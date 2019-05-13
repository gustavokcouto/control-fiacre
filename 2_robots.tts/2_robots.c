/* Created Sun May 12 22:08:33 2019 by frac version 2.5.0 */

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/* tts API version */
int ttsapiversion () {return 2;}

/* provider */
char *source_info[3] = {"frac","2.5.0","Sun May 12 22:08:33 2019"};
char **sourceinfo () {return source_info;}

/* fiacre and private headers */
#include "2_robots.h"

/* storage headers */
#include "pack.h"
#include "store.h"

static storage_t values_storage;
#ifdef SHARE
static storage_t a1_storage;
#endif
#define lookup(s)   lookup_data(&values_storage,s)
#define store(v)    store_data(&values_storage,v)

static int avail;    /* for sprint_* */
static char tmpbuff[16]; /* for sprint_* */

/* utilities for structure a0 */

static int compare_a0 (struct a0 e1, struct a0 e2) {
  size_t i = 0;
  for (i=0; i<4; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a0 (char *buff, struct a0 *e, const struct pmap *pmap) {
  int j0;
  PUTS(pmap->a.l);
  for (j0=0; j0<4; j0++) {
    if (j0) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j0]);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a0 (struct a0* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 4; ++i) {
    data += pack_int(a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a0 (struct a0* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 4; ++i) {
    data += unpack_int(&(a->at[i]), data);
  }
  return data - orig;
}

/* utilities for structure a1 */

static int compare_a1 (struct a1 e1, struct a1 e2) {
  size_t i = 0;
  for (i=0; i<4; i++) {
    {int r = compare_a0(e1.at[i],e2.at[i]); if (r) return r;}
  }
  return 0;
}

static char *sprint_a1 (char *buff, struct a1 *e, const struct pmap *pmap) {
  int j1;
  PUTS(pmap->a.l);
  for (j1=0; j1<4; j1++) {
    if (j1) {PUTS(pmap->a.s);}
    buff = sprint_a0 (buff,&e->at[j1],pmap);
  }
  PUTS(pmap->a.r);
  return buff;
}

static size_t pack_a1 (struct a1* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 4; ++i) {
    data += pack_a0(&a->at[i], data);
  }
  return data - orig;
}

static size_t unpack_a1 (struct a1* a, char* data) {
  const char* orig = data;
  size_t i = 0;
  for (i = 0; i < 4; ++i) {
    data += unpack_a0(&(a->at[i]), data);
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

/* read-only temporary variables */
struct a1 play_1_va;

/* state type */

struct value {
  char play_1_vx;
  char play_1_vy;
};

/* utilities for structure value */

int compare_value (struct value *e1, struct value *e2) {
  if ((e1->play_1_vx) < (e2->play_1_vx)) return -1;
  if ((e1->play_1_vx) > (e2->play_1_vx)) return 1;
  if ((e1->play_1_vy) < (e2->play_1_vy)) return -1;
  if ((e1->play_1_vy) > (e2->play_1_vy)) return 1;
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
  return data - orig;
}

size_t unpack_value (struct value* v, char* data) {
  const char* orig = data;
  data += unpack_char(&(v->play_1_vx), data);
  data += unpack_char(&(v->play_1_vy), data);
  return data - orig;
}


void pack_with_size_value (struct value* v, char* data) {
  unsigned char size = sizeof(unsigned char);
  size += pack_value(v,data + size);
  *(unsigned char *)data = size;
}

void unpack_with_size_value (struct value* v, char* data) {
  unpack_value(v,data + sizeof(unsigned char));
}

size_t size_value(char* data) {
  return *(unsigned char *)(data);
}

/* initializes temporaries and creates initial state */
key initial() {
  struct value start;
  /* read-only temporaries: */
  play_1_va.at[0].at[0]=1;
  play_1_va.at[0].at[1]=1;
  play_1_va.at[0].at[2]=1;
  play_1_va.at[0].at[3]=1;
  play_1_va.at[1].at[0]=1;
  play_1_va.at[1].at[1]=0;
  play_1_va.at[1].at[2]=0;
  play_1_va.at[1].at[3]=1;
  play_1_va.at[2].at[0]=1;
  play_1_va.at[2].at[1]=0;
  play_1_va.at[2].at[2]=0;
  play_1_va.at[2].at[3]=1;
  play_1_va.at[3].at[0]=1;
  play_1_va.at[3].at[1]=1;
  play_1_va.at[3].at[2]=1;
  play_1_va.at[3].at[3]=1;
  /* state variables: */
  start.play_1_vx=1;
  start.play_1_vy=1;
  /* storage initializations: */
  open_storage();
  values_storage = init_storage(sizeof(struct value), compare_value, pack_with_size_value, unpack_with_size_value, size_value);
#ifdef SHARE
  a1_storage = init_storage(sizeof(struct a1), compare_a1, pack_with_size_a1, unpack_with_size_a1, size_a1);
#endif
  return store(&start);
  error: return 0;
}

int final(int debug) {
  finalize_storage("top", debug, &values_storage);
#ifdef SHARE
  finalize_storage("a1 ", debug, &a1_storage);
#endif
  return close_storage(debug);
}

/* -- predicates and actions */
/* by default, pre_t* returns true and act_t* is the identity function */

/* translation table for transition names */
char *transtable[4] = {"play_1_t0","play_1_t1","play_1_t2","play_1_t3"};

char **transitions (int *sz) {
*sz =4;
return transtable;
}

bool pre_0 (key s) {
  /* play_1_t0 */
  struct value *v = lookup(s);
  if (!((play_1_va.at[v->play_1_vy].at[ISUB(v->play_1_vx,1,0,3)] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_1 (key s) {
  /* play_1_t1 */
  struct value *v = lookup(s);
  if (!((play_1_va.at[v->play_1_vy].at[IADD(v->play_1_vx,1,0,3)] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_2 (key s) {
  /* play_1_t2 */
  struct value *v = lookup(s);
  if (!((play_1_va.at[ISUB(v->play_1_vy,1,0,3)].at[v->play_1_vx] == 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_3 (key s) {
  /* play_1_t3 */
  struct value *v = lookup(s);
  if (!((play_1_va.at[IADD(v->play_1_vy,1,0,3)].at[v->play_1_vx] == 0))) return 0;
  return 1;
 error: return 0;
}

key act_0 (key s) {
  /* play_1_t0 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vx=ISUB(new.play_1_vx,1,0,3); 
  return store(&new);
 error: return s;
}

key act_1 (key s) {
  /* play_1_t1 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vx=IADD(new.play_1_vx,1,0,3); 
  return store(&new);
 error: return s;
}

key act_2 (key s) {
  /* play_1_t2 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vy=ISUB(new.play_1_vy,1,0,3); 
  return store(&new);
 error: return s;
}

key act_3 (key s) {
  /* play_1_t3 */
  struct value new = *(struct value*)lookup(s);
  new.play_1_vy=IADD(new.play_1_vy,1,0,3); 
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
char *obsnames[2] = {"play_1_vx","play_1_vy"};

char **obs_names (int *count) {*count = 2; return obsnames;}

/* returns values of observables for state s (abstractions for noninteger fields) */
int ovalues[2];

int *obs_values (key s) {
struct value *v = lookup(s);
ovalues[0]=(int)(v->play_1_vx);
ovalues[1]=(int)(v->play_1_vy);
return ovalues;
}

