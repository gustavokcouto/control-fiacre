/* Created Sun May 12 20:32:05 2019 by frac version 2.5.0 */

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/* tts API version */
int ttsapiversion () {return 2;}

/* provider */
char *source_info[3] = {"frac","2.5.0","Sun May 12 20:32:05 2019"};
char **sourceinfo () {return source_info;}

/* fiacre and private headers */
#include "foo.h"

/* storage headers */
#include "pack.h"
#include "store.h"

static storage_t values_storage;
#ifdef SHARE
static storage_t a0_storage;
static storage_t a1_storage;
#endif
#define lookup(s)   lookup_data(&values_storage,s)
#define store(v)    store_data(&values_storage,v)

static int avail;    /* for sprint_* */
static char tmpbuff[16]; /* for sprint_* */

/* utilities for structure a0 */

static int compare_a0 (struct a0 e1, struct a0 e2) {
  size_t i = 0;
  for (i=0; i<10; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a0 (char *buff, struct a0 *e, const struct pmap *pmap) {
  int j0;
  PUTS(pmap->a.l);
  for (j0=0; j0<10; j0++) {
    if (j0) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j0]);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a0 (struct a0* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 10; ++i) {
    data += pack_int(a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a0 (struct a0* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 10; ++i) {
    data += unpack_int(&(a->at[i]), data);
  }
  return data - orig;
}

#ifdef SHARE
void pack_with_size_a0 (struct a0* x, char* data) {
  unsigned char size = sizeof(unsigned char);
  size += pack_a0(x,data + size);
  *(unsigned char *)data = size;
}

void unpack_with_size_a0 (struct a0* x, char* data) {
  unpack_a0(x,data + sizeof(unsigned char));
}

size_t size_a0 (char* data) {
  return *(unsigned char *)data;
}

#define pack_shared_a0(x,data)   pack_key(&a0_storage,x,data)
#define unpack_shared_a0(x,data) unpack_key(&a0_storage,x,data)

#else
#define pack_shared_a0(x,data)   pack_a0(x,data)
#define unpack_shared_a0(x,data) unpack_a0(x,data)
#endif

/* utilities for structure a1 */

static int compare_a1 (struct a1 e1, struct a1 e2) {
  size_t i = 0;
  for (i=0; i<6; i++) {
    {int r = compare_a0(e1.at[i],e2.at[i]); if (r) return r;}
  }
  return 0;
}

static char *sprint_a1 (char *buff, struct a1 *e, const struct pmap *pmap) {
  int j1;
  PUTS(pmap->a.l);
  for (j1=0; j1<6; j1++) {
    if (j1) {PUTS(pmap->a.s);}
    buff = sprint_a0 (buff,&e->at[j1],pmap);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a1 (struct a1* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 6; ++i) {
    data += pack_shared_a0(&a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a1 (struct a1* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 6; ++i) {
    data += unpack_shared_a0(&(a->at[i]), data);
  }
  return data - orig;
}

#ifdef SHARE
void pack_with_size_a1 (struct a1* x, char* data) {
  unsigned char size = sizeof(unsigned char);
  size += pack_a1(x,data + size);
  *(unsigned char *)data = size;
}

void unpack_with_size_a1 (struct a1* x, char* data) {
  unpack_a1(x,data + sizeof(unsigned char));
}

size_t size_a1 (char* data) {
  return *(unsigned char *)data;
}

#define pack_shared_a1(x,data)   pack_key(&a1_storage,x,data)
#define unpack_shared_a1(x,data) unpack_key(&a1_storage,x,data)

#else
#define pack_shared_a1(x,data)   pack_a1(x,data)
#define unpack_shared_a1(x,data) unpack_a1(x,data)
#endif

/* Process play_1 */

/* state type */

struct value {
  char play_1_vx;
  char play_1_vy;
  struct a1 play_1_va;
};

/* utilities for structure value */

int compare_value (struct value *e1, struct value *e2) {
  if ((e1->play_1_vx) < (e2->play_1_vx)) return -1;
  if ((e1->play_1_vx) > (e2->play_1_vx)) return 1;
  if ((e1->play_1_vy) < (e2->play_1_vy)) return -1;
  if ((e1->play_1_vy) > (e2->play_1_vy)) return 1;
  {int r = compare_a1(e1->play_1_va,e2->play_1_va); if (r) return r;}
  return 0;
}

static int sprint_value (int sz, char *buff, key s, const struct pmap *pmap) {
  struct value *v = lookup(s);
  avail = sz - 1;
  /* prints state into buff: */
  PUTS(pmap->r.l);
  PUTN(9,pmap->n,"play_1_vx"); PUTS(pmap->r.b); PUTV("%hhd",v->play_1_vx);
  PUTS(pmap->r.s);
  PUTN(9,pmap->n,"play_1_vy"); PUTS(pmap->r.b); PUTV("%hhd",v->play_1_vy);
  PUTS(pmap->r.s);
  PUTN(9,pmap->n,"play_1_va"); PUTS(pmap->r.b); buff = sprint_a1 (buff,&v->play_1_va,pmap);
  PUTS(pmap->r.r);
  return (avail<0) ? -1 : (sz - avail - 1);
}

int sprint_state (int sz, char *buff, key s) {
  return sprint_value (sz, buff, s, &fcrPmap);
}

int sprint_json_state (int sz, char *buff, key s) {
  return sprint_value (sz, buff, s, &jsonPmap);
}

size_t pack_value (struct value* v, char* data) {
  const char* orig = data;
  data += pack_char(v->play_1_vx, data);
  data += pack_char(v->play_1_vy, data);
  data += pack_shared_a1(&v->play_1_va, data);
  return data - orig;
}

size_t unpack_value (struct value* v, char* data) {
  const char* orig = data;
  data += unpack_char(&(v->play_1_vx), data);
  data += unpack_char(&(v->play_1_vy), data);
  data += unpack_shared_a1(&(v->play_1_va), data);
  return data - orig;
}


void pack_with_size_value (struct value* v, char* data) {
#ifdef SHARE
  unsigned char size = sizeof(unsigned char);
#else
  unsigned short size = sizeof(int) + sizeof(unsigned short);
#endif
  size += pack_value(v,data + size);
#ifdef SHARE
  *(unsigned char *)data = size;
#else
  *(unsigned short *)(data + sizeof(int)) = size;
  MurmurHash3_x86_32(data + sizeof(int), size - sizeof(int), 42, (void*)data);
#endif
}

void unpack_with_size_value (struct value* v, char* data) {
#ifdef SHARE
  unpack_value(v,data + sizeof(unsigned char));
#else
  unpack_value(v,data + sizeof(int) + sizeof(unsigned short));
#endif
}

size_t size_value(char* data) {
#ifdef SHARE
  return *(unsigned char *)(data);
#else
  return *(unsigned short *)(data + sizeof(int));
#endif
}

/* initializes temporaries and creates initial state */
key initial() {
  struct value start;
  /* state variables: */
  start.play_1_vx=1;
  start.play_1_vy=1;
  start.play_1_va.at[0].at[0]=1;
  start.play_1_va.at[0].at[1]=1;
  start.play_1_va.at[0].at[2]=1;
  start.play_1_va.at[0].at[3]=1;
  start.play_1_va.at[0].at[4]=1;
  start.play_1_va.at[0].at[5]=1;
  start.play_1_va.at[0].at[6]=1;
  start.play_1_va.at[0].at[7]=1;
  start.play_1_va.at[0].at[8]=1;
  start.play_1_va.at[0].at[9]=1;
  start.play_1_va.at[1].at[0]=1;
  start.play_1_va.at[1].at[1]=0;
  start.play_1_va.at[1].at[2]=0;
  start.play_1_va.at[1].at[3]=0;
  start.play_1_va.at[1].at[4]=1;
  start.play_1_va.at[1].at[5]=0;
  start.play_1_va.at[1].at[6]=0;
  start.play_1_va.at[1].at[7]=0;
  start.play_1_va.at[1].at[8]=0;
  start.play_1_va.at[1].at[9]=1;
  start.play_1_va.at[2].at[0]=1;
  start.play_1_va.at[2].at[1]=0;
  start.play_1_va.at[2].at[2]=2;
  start.play_1_va.at[2].at[3]=0;
  start.play_1_va.at[2].at[4]=2;
  start.play_1_va.at[2].at[5]=0;
  start.play_1_va.at[2].at[6]=0;
  start.play_1_va.at[2].at[7]=0;
  start.play_1_va.at[2].at[8]=0;
  start.play_1_va.at[2].at[9]=1;
  start.play_1_va.at[3].at[0]=1;
  start.play_1_va.at[3].at[1]=0;
  start.play_1_va.at[3].at[2]=2;
  start.play_1_va.at[3].at[3]=2;
  start.play_1_va.at[3].at[4]=2;
  start.play_1_va.at[3].at[5]=1;
  start.play_1_va.at[3].at[6]=1;
  start.play_1_va.at[3].at[7]=0;
  start.play_1_va.at[3].at[8]=0;
  start.play_1_va.at[3].at[9]=1;
  start.play_1_va.at[4].at[0]=1;
  start.play_1_va.at[4].at[1]=0;
  start.play_1_va.at[4].at[2]=0;
  start.play_1_va.at[4].at[3]=0;
  start.play_1_va.at[4].at[4]=0;
  start.play_1_va.at[4].at[5]=1;
  start.play_1_va.at[4].at[6]=1;
  start.play_1_va.at[4].at[7]=1;
  start.play_1_va.at[4].at[8]=1;
  start.play_1_va.at[4].at[9]=1;
  start.play_1_va.at[5].at[0]=1;
  start.play_1_va.at[5].at[1]=1;
  start.play_1_va.at[5].at[2]=1;
  start.play_1_va.at[5].at[3]=1;
  start.play_1_va.at[5].at[4]=1;
  start.play_1_va.at[5].at[5]=1;
  start.play_1_va.at[5].at[6]=1;
  start.play_1_va.at[5].at[7]=1;
  start.play_1_va.at[5].at[8]=1;
  start.play_1_va.at[5].at[9]=1;
  /* storage initializations: */
  open_storage();
  values_storage = init_storage(sizeof(struct value), compare_value, pack_with_size_value, unpack_with_size_value, size_value);
#ifdef SHARE
  a0_storage = init_storage(sizeof(struct a0), compare_a0, pack_with_size_a0, unpack_with_size_a0, size_a0);
  a1_storage = init_storage(sizeof(struct a1), compare_a1, pack_with_size_a1, unpack_with_size_a1, size_a1);
#endif
  return store(&start);
  error: return 0;
}

int final(int debug) {
  finalize_storage("top", debug, &values_storage);
#ifdef SHARE
  finalize_storage("a0 ", debug, &a0_storage);
  finalize_storage("a1 ", debug, &a1_storage);
#endif
  return close_storage(debug);
}

/* -- predicates and actions */
/* by default, pre_t* returns true and act_t* is the identity function */

/* translation table for transition names */
char *transtable[9] = {"play_1_t0","play_1_t1","play_1_t2","play_1_t3","play_1_t4","play_1_t5","play_1_t6","play_1_t7","play_1_t8"};

char **transitions (int *sz) {
*sz =9;
return transtable;
}

bool pre_0 (key s) {
  /* play_1_t0 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[1].at[8] == 2))) return 0;
  if (!((v->play_1_va.at[2].at[7] == 2))) return 0;
  if (!((v->play_1_va.at[2].at[8] == 2))) return 0;
  if (!((v->play_1_va.at[3].at[7] == 2))) return 0;
  if (!((v->play_1_va.at[3].at[8] == 2))) return 0;
  return 1;
 error: return 0;
}

bool pre_1 (key s) {
  /* play_1_t1 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[v->play_1_vy].at[ISUB(v->play_1_vx,1,0,9)] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_2 (key s) {
  /* play_1_t2 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[v->play_1_vy].at[IADD(v->play_1_vx,1,0,9)] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_3 (key s) {
  /* play_1_t3 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[ISUB(v->play_1_vy,1,0,5)].at[v->play_1_vx] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_4 (key s) {
  /* play_1_t4 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[IADD(v->play_1_vy,1,0,5)].at[v->play_1_vx] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_5 (key s) {
  /* play_1_t5 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[v->play_1_vy].at[ISUB(v->play_1_vx,1,0,9)] == 2))) return 0;
  if (!((v->play_1_va.at[v->play_1_vy].at[ISUB(v->play_1_vx,2,0,9)] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_6 (key s) {
  /* play_1_t6 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[v->play_1_vy].at[IADD(v->play_1_vx,1,0,9)] == 2))) return 0;
  if (!((v->play_1_va.at[v->play_1_vy].at[IADD(v->play_1_vx,2,0,9)] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_7 (key s) {
  /* play_1_t7 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[ISUB(v->play_1_vy,1,0,5)].at[v->play_1_vx] == 2))) return 0;
  if (!((v->play_1_va.at[ISUB(v->play_1_vy,2,0,5)].at[v->play_1_vx] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_8 (key s) {
  /* play_1_t8 */
  struct value *v = lookup(s);
  if (!((v->play_1_va.at[IADD(v->play_1_vy,1,0,5)].at[v->play_1_vx] == 2))) return 0;
  if (!((v->play_1_va.at[IADD(v->play_1_vy,2,0,5)].at[v->play_1_vx] == 0))) return 0;
  return 1;
 error: return 0;
}

key act_1 (key s) {
  /* play_1_t1 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vx=ISUB(new.play_1_vx,1,0,9); 
  return store(&new);
 error: return s;
}

key act_2 (key s) {
  /* play_1_t2 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vx=IADD(new.play_1_vx,1,0,9); 
  return store(&new);
 error: return s;
}

key act_3 (key s) {
  /* play_1_t3 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vy=ISUB(new.play_1_vy,1,0,5); 
  return store(&new);
 error: return s;
}

key act_4 (key s) {
  /* play_1_t4 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vy=IADD(new.play_1_vy,1,0,5); 
  return store(&new);
 error: return s;
}

key act_5 (key s) {
  /* play_1_t5 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_va.at[new.play_1_vy].at[ISUB(new.play_1_vx,2,0,9)]=2; 
  new.play_1_va.at[new.play_1_vy].at[ISUB(new.play_1_vx,1,0,9)]=0; 
  new.play_1_vx=ISUB(new.play_1_vx,1,0,9); 
  return store(&new);
 error: return s;
}

key act_6 (key s) {
  /* play_1_t6 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_va.at[new.play_1_vy].at[IADD(new.play_1_vx,2,0,9)]=2; 
  new.play_1_va.at[new.play_1_vy].at[IADD(new.play_1_vx,1,0,9)]=0; 
  new.play_1_vx=IADD(new.play_1_vx,1,0,9); 
  return store(&new);
 error: return s;
}

key act_7 (key s) {
  /* play_1_t7 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_va.at[ISUB(new.play_1_vy,2,0,5)].at[new.play_1_vx]=2; 
  new.play_1_va.at[ISUB(new.play_1_vy,1,0,5)].at[new.play_1_vx]=0; 
  new.play_1_vy=ISUB(new.play_1_vy,1,0,5); 
  return store(&new);
 error: return s;
}

key act_8 (key s) {
  /* play_1_t8 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_va.at[IADD(new.play_1_vy,2,0,5)].at[new.play_1_vx]=2; 
  new.play_1_va.at[IADD(new.play_1_vy,1,0,5)].at[new.play_1_vx]=0; 
  new.play_1_vy=IADD(new.play_1_vy,1,0,5); 
  return store(&new);
 error: return s;
}

/* -- independance relation for transitions, for partial order modes and reset in timed modes -- */
/* indices refer to transtable; specifies independance for ALL transitions */
bool independant (int t1, int t2) {
    /* always true */
    return 1;
}

/* -- state observers for kts output -- */
char *obsnames[62] = {"play_1_vx","play_1_vy","{play_1_va.at[0].at[0]}","{play_1_va.at[0].at[1]}","{play_1_va.at[0].at[2]}","{play_1_va.at[0].at[3]}","{play_1_va.at[0].at[4]}","{play_1_va.at[0].at[5]}","{play_1_va.at[0].at[6]}","{play_1_va.at[0].at[7]}","{play_1_va.at[0].at[8]}","{play_1_va.at[0].at[9]}","{play_1_va.at[1].at[0]}","{play_1_va.at[1].at[1]}","{play_1_va.at[1].at[2]}","{play_1_va.at[1].at[3]}","{play_1_va.at[1].at[4]}","{play_1_va.at[1].at[5]}","{play_1_va.at[1].at[6]}","{play_1_va.at[1].at[7]}","{play_1_va.at[1].at[8]}","{play_1_va.at[1].at[9]}","{play_1_va.at[2].at[0]}","{play_1_va.at[2].at[1]}","{play_1_va.at[2].at[2]}","{play_1_va.at[2].at[3]}","{play_1_va.at[2].at[4]}","{play_1_va.at[2].at[5]}","{play_1_va.at[2].at[6]}","{play_1_va.at[2].at[7]}","{play_1_va.at[2].at[8]}","{play_1_va.at[2].at[9]}","{play_1_va.at[3].at[0]}","{play_1_va.at[3].at[1]}","{play_1_va.at[3].at[2]}","{play_1_va.at[3].at[3]}","{play_1_va.at[3].at[4]}","{play_1_va.at[3].at[5]}","{play_1_va.at[3].at[6]}","{play_1_va.at[3].at[7]}","{play_1_va.at[3].at[8]}","{play_1_va.at[3].at[9]}","{play_1_va.at[4].at[0]}","{play_1_va.at[4].at[1]}","{play_1_va.at[4].at[2]}","{play_1_va.at[4].at[3]}","{play_1_va.at[4].at[4]}","{play_1_va.at[4].at[5]}","{play_1_va.at[4].at[6]}","{play_1_va.at[4].at[7]}","{play_1_va.at[4].at[8]}","{play_1_va.at[4].at[9]}","{play_1_va.at[5].at[0]}","{play_1_va.at[5].at[1]}","{play_1_va.at[5].at[2]}","{play_1_va.at[5].at[3]}","{play_1_va.at[5].at[4]}","{play_1_va.at[5].at[5]}","{play_1_va.at[5].at[6]}","{play_1_va.at[5].at[7]}","{play_1_va.at[5].at[8]}","{play_1_va.at[5].at[9]}"};

char **obs_names (int *count) {*count = 62; return obsnames;}

/* returns values of observables for state s (abstractions for noninteger fields) */
int ovalues[62];

int *obs_values (key s) {
struct value *v = lookup(s);
ovalues[0]=(int)(v->play_1_vx);
ovalues[1]=(int)(v->play_1_vy);
ovalues[2]=(int)(v->play_1_va.at[0].at[0]);
ovalues[3]=(int)(v->play_1_va.at[0].at[1]);
ovalues[4]=(int)(v->play_1_va.at[0].at[2]);
ovalues[5]=(int)(v->play_1_va.at[0].at[3]);
ovalues[6]=(int)(v->play_1_va.at[0].at[4]);
ovalues[7]=(int)(v->play_1_va.at[0].at[5]);
ovalues[8]=(int)(v->play_1_va.at[0].at[6]);
ovalues[9]=(int)(v->play_1_va.at[0].at[7]);
ovalues[10]=(int)(v->play_1_va.at[0].at[8]);
ovalues[11]=(int)(v->play_1_va.at[0].at[9]);
ovalues[12]=(int)(v->play_1_va.at[1].at[0]);
ovalues[13]=(int)(v->play_1_va.at[1].at[1]);
ovalues[14]=(int)(v->play_1_va.at[1].at[2]);
ovalues[15]=(int)(v->play_1_va.at[1].at[3]);
ovalues[16]=(int)(v->play_1_va.at[1].at[4]);
ovalues[17]=(int)(v->play_1_va.at[1].at[5]);
ovalues[18]=(int)(v->play_1_va.at[1].at[6]);
ovalues[19]=(int)(v->play_1_va.at[1].at[7]);
ovalues[20]=(int)(v->play_1_va.at[1].at[8]);
ovalues[21]=(int)(v->play_1_va.at[1].at[9]);
ovalues[22]=(int)(v->play_1_va.at[2].at[0]);
ovalues[23]=(int)(v->play_1_va.at[2].at[1]);
ovalues[24]=(int)(v->play_1_va.at[2].at[2]);
ovalues[25]=(int)(v->play_1_va.at[2].at[3]);
ovalues[26]=(int)(v->play_1_va.at[2].at[4]);
ovalues[27]=(int)(v->play_1_va.at[2].at[5]);
ovalues[28]=(int)(v->play_1_va.at[2].at[6]);
ovalues[29]=(int)(v->play_1_va.at[2].at[7]);
ovalues[30]=(int)(v->play_1_va.at[2].at[8]);
ovalues[31]=(int)(v->play_1_va.at[2].at[9]);
ovalues[32]=(int)(v->play_1_va.at[3].at[0]);
ovalues[33]=(int)(v->play_1_va.at[3].at[1]);
ovalues[34]=(int)(v->play_1_va.at[3].at[2]);
ovalues[35]=(int)(v->play_1_va.at[3].at[3]);
ovalues[36]=(int)(v->play_1_va.at[3].at[4]);
ovalues[37]=(int)(v->play_1_va.at[3].at[5]);
ovalues[38]=(int)(v->play_1_va.at[3].at[6]);
ovalues[39]=(int)(v->play_1_va.at[3].at[7]);
ovalues[40]=(int)(v->play_1_va.at[3].at[8]);
ovalues[41]=(int)(v->play_1_va.at[3].at[9]);
ovalues[42]=(int)(v->play_1_va.at[4].at[0]);
ovalues[43]=(int)(v->play_1_va.at[4].at[1]);
ovalues[44]=(int)(v->play_1_va.at[4].at[2]);
ovalues[45]=(int)(v->play_1_va.at[4].at[3]);
ovalues[46]=(int)(v->play_1_va.at[4].at[4]);
ovalues[47]=(int)(v->play_1_va.at[4].at[5]);
ovalues[48]=(int)(v->play_1_va.at[4].at[6]);
ovalues[49]=(int)(v->play_1_va.at[4].at[7]);
ovalues[50]=(int)(v->play_1_va.at[4].at[8]);
ovalues[51]=(int)(v->play_1_va.at[4].at[9]);
ovalues[52]=(int)(v->play_1_va.at[5].at[0]);
ovalues[53]=(int)(v->play_1_va.at[5].at[1]);
ovalues[54]=(int)(v->play_1_va.at[5].at[2]);
ovalues[55]=(int)(v->play_1_va.at[5].at[3]);
ovalues[56]=(int)(v->play_1_va.at[5].at[4]);
ovalues[57]=(int)(v->play_1_va.at[5].at[5]);
ovalues[58]=(int)(v->play_1_va.at[5].at[6]);
ovalues[59]=(int)(v->play_1_va.at[5].at[7]);
ovalues[60]=(int)(v->play_1_va.at[5].at[8]);
ovalues[61]=(int)(v->play_1_va.at[5].at[9]);
return ovalues;
}

