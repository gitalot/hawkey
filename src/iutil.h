#ifndef IUTIL_H
#define IUTIL_H

// libsolv
#include "solv/queue.h"
#include "solv/repo.h"
#include "solv/rules.h"
#include "solv/transaction.h"

// hawkey
#include "packagelist.h"
#include "sack.h"

#define CHKSUM_BYTES 32

/* crypto utils */
int checksum_cmp(unsigned char *cs1, unsigned char *cs2);
int checksum_fp(FILE *fp, unsigned char *out);
int checksum_stat(FILE *fp, unsigned char *out);
void checksum_dump(unsigned char *cs);

/* filesystem utils */
int is_readable_rpm(const char *fn);
int mkcachedir(const char *path);
char *this_username(void);

/* libsolv utils */
void repo_internalize_trigger(Repo *r);
Transaction *job2transaction(HySack sack, Queue *job, Queue *errors);
void queue2plist(HySack sack, Queue *q, HyPackageList plist);
char *problemruleinfo2str(Pool *pool, SolverRuleinfo type, Id source, Id target, Id dep);
Id what_updates(Pool *pool, Id p);

#endif
