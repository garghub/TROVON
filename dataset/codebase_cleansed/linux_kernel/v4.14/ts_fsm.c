static inline int match_token(struct ts_fsm_token *t, u8 d)
{
if (t->type)
return (token_lookup_tbl[d] & t->type) != 0;
else
return t->value == d;
}
static unsigned int fsm_find(struct ts_config *conf, struct ts_state *state)
{
struct ts_fsm *fsm = ts_config_priv(conf);
struct ts_fsm_token *cur = NULL, *next;
unsigned int match_start, block_idx = 0, tok_idx;
unsigned block_len = 0, strict, consumed = state->offset;
const u8 *data;
#define GET_NEXT_BLOCK() \
({ consumed += block_idx; \
block_idx = 0; \
block_len = conf->get_next_block(consumed, &data, conf, state); })
#define TOKEN_MISMATCH() \
do { \
if (strict) \
goto no_match; \
block_idx++; \
goto startover; \
} while(0)
#define end_of_data() unlikely(block_idx >= block_len && !GET_NEXT_BLOCK())
if (end_of_data())
goto no_match;
strict = fsm->tokens[0].recur != TS_FSM_HEAD_IGNORE;
startover:
match_start = consumed + block_idx;
for (tok_idx = 0; tok_idx < fsm->ntokens; tok_idx++) {
cur = &fsm->tokens[tok_idx];
if (likely(tok_idx < (fsm->ntokens - 1)))
next = &fsm->tokens[tok_idx + 1];
else
next = NULL;
switch (cur->recur) {
case TS_FSM_SINGLE:
if (end_of_data())
goto no_match;
if (!match_token(cur, data[block_idx]))
TOKEN_MISMATCH();
break;
case TS_FSM_PERHAPS:
if (end_of_data() ||
!match_token(cur, data[block_idx]))
continue;
break;
case TS_FSM_MULTI:
if (end_of_data())
goto no_match;
if (!match_token(cur, data[block_idx]))
TOKEN_MISMATCH();
block_idx++;
case TS_FSM_ANY:
if (next == NULL)
goto found_match;
if (end_of_data())
continue;
while (!match_token(next, data[block_idx])) {
if (!match_token(cur, data[block_idx]))
TOKEN_MISMATCH();
block_idx++;
if (end_of_data())
goto no_match;
}
continue;
case TS_FSM_HEAD_IGNORE:
if (end_of_data())
continue;
while (!match_token(next, data[block_idx])) {
if (!match_token(cur, data[block_idx]))
goto no_match;
block_idx++;
if (end_of_data())
goto no_match;
}
match_start = consumed + block_idx;
continue;
}
block_idx++;
}
if (end_of_data())
goto found_match;
no_match:
return UINT_MAX;
found_match:
state->offset = consumed + block_idx;
return match_start;
}
static struct ts_config *fsm_init(const void *pattern, unsigned int len,
gfp_t gfp_mask, int flags)
{
int i, err = -EINVAL;
struct ts_config *conf;
struct ts_fsm *fsm;
struct ts_fsm_token *tokens = (struct ts_fsm_token *) pattern;
unsigned int ntokens = len / sizeof(*tokens);
size_t priv_size = sizeof(*fsm) + len;
if (len % sizeof(struct ts_fsm_token) || ntokens < 1)
goto errout;
if (flags & TS_IGNORECASE)
goto errout;
for (i = 0; i < ntokens; i++) {
struct ts_fsm_token *t = &tokens[i];
if (t->type > TS_FSM_TYPE_MAX || t->recur > TS_FSM_RECUR_MAX)
goto errout;
if (t->recur == TS_FSM_HEAD_IGNORE &&
(i != 0 || i == (ntokens - 1)))
goto errout;
}
conf = alloc_ts_config(priv_size, gfp_mask);
if (IS_ERR(conf))
return conf;
conf->flags = flags;
fsm = ts_config_priv(conf);
fsm->ntokens = ntokens;
memcpy(fsm->tokens, pattern, len);
for (i = 0; i < fsm->ntokens; i++) {
struct ts_fsm_token *t = &fsm->tokens[i];
t->type = token_map[t->type];
}
return conf;
errout:
return ERR_PTR(err);
}
static void *fsm_get_pattern(struct ts_config *conf)
{
struct ts_fsm *fsm = ts_config_priv(conf);
return fsm->tokens;
}
static unsigned int fsm_get_pattern_len(struct ts_config *conf)
{
struct ts_fsm *fsm = ts_config_priv(conf);
return fsm->ntokens * sizeof(struct ts_fsm_token);
}
static int __init init_fsm(void)
{
return textsearch_register(&fsm_ops);
}
static void __exit exit_fsm(void)
{
textsearch_unregister(&fsm_ops);
}
