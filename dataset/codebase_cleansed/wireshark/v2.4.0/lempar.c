void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
yyTraceFILE = TraceFILE;
yyTracePrompt = zTracePrompt;
if( yyTraceFILE==0 ) yyTracePrompt = 0;
else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
static int yyGrowStack(yyParser *p){
int newSize;
int idx;
yyStackEntry *pNew;
newSize = p->yystksz*2 + 100;
idx = p->yytos ? (int)(p->yytos - p->yystack) : 0;
if( p->yystack==&p->yystk0 ){
pNew = malloc(newSize*sizeof(pNew[0]));
if( pNew ) pNew[0] = p->yystk0;
}else{
pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
}
if( pNew ){
p->yystack = pNew;
p->yytos = &p->yystack[idx];
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sStack grows from %d to %d entries.\n",
yyTracePrompt, p->yystksz, newSize);
}
#endif
p->yystksz = newSize;
}
return pNew==0;
}
static void ParseInit(void *yypParser){
yyParser *pParser = (yyParser*)yypParser;
#ifdef YYTRACKMAXSTACKDEPTH
pParser->yyhwm = 0;
#endif
#if YYSTACKDEPTH<=0
pParser->yytos = NULL;
pParser->yystack = NULL;
pParser->yystksz = 0;
if( yyGrowStack(pParser) ){
pParser->yystack = &pParser->yystk0;
pParser->yystksz = 1;
}
#endif
#ifndef YYNOERRORRECOVERY
pParser->yyerrcnt = -1;
#endif
pParser->yytos = pParser->yystack;
pParser->yystack[0].stateno = 0;
pParser->yystack[0].major = 0;
}
void *ParseAlloc(void *(*mallocProc)(YYMALLOCARGTYPE)){
yyParser *pParser;
pParser = (yyParser*)(*mallocProc)( (YYMALLOCARGTYPE)sizeof(yyParser) );
if( pParser ) ParseInit(pParser);
return pParser;
}
static void yy_destructor(
yyParser *yypParser,
YYCODETYPE yymajor,
YYMINORTYPE *yypminor
){
ParseARG_FETCH;
switch( yymajor ){
%%
default: break;
}
}
static void yy_pop_parser_stack(yyParser *pParser){
yyStackEntry *yytos;
assert( pParser->yytos!=0 );
assert( pParser->yytos > pParser->yystack );
yytos = pParser->yytos--;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sPopping %s\n",
yyTracePrompt,
yyTokenName[yytos->major]);
}
#endif
yy_destructor(pParser, yytos->major, &yytos->minor);
}
static void ParseFinalize(void *p){
yyParser *pParser = (yyParser*)p;
while( pParser->yytos>pParser->yystack ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
if( pParser->yystack!=&pParser->yystk0 ) free(pParser->yystack);
#endif
}
void ParseFree(
void *p,
void (*freeProc)(void*)
){
#ifndef YYPARSEFREENEVERNULL
if( p==0 ) return;
#endif
ParseFinalize(p);
(*freeProc)(p);
}
int ParseStackPeak(void *p){
yyParser *pParser = (yyParser*)p;
return pParser->yyhwm;
}
static unsigned int yy_find_shift_action(
yyParser *pParser,
YYCODETYPE iLookAhead
){
int i;
int stateno = pParser->yytos->stateno;
if( stateno>=YY_MIN_REDUCE ) return stateno;
assert( stateno <= YY_SHIFT_COUNT );
do{
i = yy_shift_ofst[stateno];
assert( iLookAhead!=YYNOCODE );
i += iLookAhead;
if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
#ifdef YYFALLBACK
YYCODETYPE iFallback;
if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
&& (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
}
#endif
assert( yyFallback[iFallback]==0 );
iLookAhead = iFallback;
continue;
}
#endif
#ifdef YYWILDCARD
{
int j = i - iLookAhead + YYWILDCARD;
if(
#if YY_SHIFT_MIN+YYWILDCARD<0
j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
j<YY_ACTTAB_COUNT &&
#endif
yy_lookahead[j]==YYWILDCARD && iLookAhead>0
){
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
yyTracePrompt, yyTokenName[iLookAhead],
yyTokenName[YYWILDCARD]);
}
#endif
return yy_action[j];
}
}
#endif
return yy_default[stateno];
}else{
return yy_action[i];
}
}while(1);
}
static int yy_find_reduce_action(
int stateno,
YYCODETYPE iLookAhead
){
int i;
#ifdef YYERRORSYMBOL
if( stateno>YY_REDUCE_COUNT ){
return yy_default[stateno];
}
#else
assert( stateno<=YY_REDUCE_COUNT );
#endif
i = yy_reduce_ofst[stateno];
assert( i!=YY_REDUCE_USE_DFLT );
assert( iLookAhead!=YYNOCODE );
i += iLookAhead;
#ifdef YYERRORSYMBOL
if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
return yy_default[stateno];
}
#else
assert( i>=0 && i<YY_ACTTAB_COUNT );
assert( yy_lookahead[i]==iLookAhead );
#endif
return yy_action[i];
}
static void yyStackOverflow(yyParser *yypParser){
ParseARG_FETCH;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
}
#endif
while( yypParser->yytos>yypParser->yystack ) yy_pop_parser_stack(yypParser);
%%
ParseARG_STORE;
}
static void yyTraceShift(yyParser *yypParser, int yyNewState){
if( yyTraceFILE ){
if( yyNewState<YYNSTATE ){
fprintf(yyTraceFILE,"%sShift '%s', go to state %d\n",
yyTracePrompt,yyTokenName[yypParser->yytos->major],
yyNewState);
}else{
fprintf(yyTraceFILE,"%sShift '%s'\n",
yyTracePrompt,yyTokenName[yypParser->yytos->major]);
}
}
}
static void yy_shift(
yyParser *yypParser,
int yyNewState,
int yyMajor,
ParseTOKENTYPE yyMinor
){
yyStackEntry *yytos;
yypParser->yytos++;
#ifdef YYTRACKMAXSTACKDEPTH
if( (int)(yypParser->yytos - yypParser->yystack)>yypParser->yyhwm ){
yypParser->yyhwm++;
assert( yypParser->yyhwm == (int)(yypParser->yytos - yypParser->yystack) );
}
#endif
#if YYSTACKDEPTH>0
if( yypParser->yytos>=&yypParser->yystack[YYSTACKDEPTH] ){
yypParser->yytos--;
yyStackOverflow(yypParser);
return;
}
#else
if( yypParser->yytos>=&yypParser->yystack[yypParser->yystksz] ){
if( yyGrowStack(yypParser) ){
yypParser->yytos--;
yyStackOverflow(yypParser);
return;
}
}
#endif
if( yyNewState > YY_MAX_SHIFT ){
yyNewState += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
}
yytos = yypParser->yytos;
yytos->stateno = (YYACTIONTYPE)yyNewState;
yytos->major = (YYCODETYPE)yyMajor;
yytos->minor.yy0 = yyMinor;
yyTraceShift(yypParser, yyNewState);
}
static void yy_reduce(
yyParser *yypParser,
unsigned int yyruleno
){
int yygoto;
int yyact;
yyStackEntry *yymsp;
int yysize;
ParseARG_FETCH;
yymsp = yypParser->yytos;
#ifndef NDEBUG
if( yyTraceFILE && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
yysize = yyRuleInfo[yyruleno].nrhs;
fprintf(yyTraceFILE, "%sReduce [%s], go to state %d.\n", yyTracePrompt,
yyRuleName[yyruleno], yymsp[-yysize].stateno);
}
#endif
if( yyRuleInfo[yyruleno].nrhs==0 ){
#ifdef YYTRACKMAXSTACKDEPTH
if( (int)(yypParser->yytos - yypParser->yystack)>yypParser->yyhwm ){
yypParser->yyhwm++;
assert( yypParser->yyhwm == (int)(yypParser->yytos - yypParser->yystack));
}
#endif
#if YYSTACKDEPTH>0
if( yypParser->yytos>=&yypParser->yystack[YYSTACKDEPTH-1] ){
yyStackOverflow(yypParser);
return;
}
#else
if( yypParser->yytos>=&yypParser->yystack[yypParser->yystksz-1] ){
if( yyGrowStack(yypParser) ){
yyStackOverflow(yypParser);
return;
}
yymsp = yypParser->yytos;
}
#endif
}
switch( yyruleno ){
%%
};
assert( yyruleno<sizeof(yyRuleInfo)/sizeof(yyRuleInfo[0]) );
yygoto = yyRuleInfo[yyruleno].lhs;
yysize = yyRuleInfo[yyruleno].nrhs;
yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
if( yyact <= YY_MAX_SHIFTREDUCE ){
if( yyact>YY_MAX_SHIFT ){
yyact += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
}
yymsp -= yysize-1;
yypParser->yytos = yymsp;
yymsp->stateno = (YYACTIONTYPE)yyact;
yymsp->major = (YYCODETYPE)yygoto;
yyTraceShift(yypParser, yyact);
}else{
assert( yyact == YY_ACCEPT_ACTION );
yypParser->yytos -= yysize;
yy_accept(yypParser);
}
}
static void yy_parse_failed(
yyParser *yypParser
){
ParseARG_FETCH;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
}
#endif
while( yypParser->yytos>yypParser->yystack ) yy_pop_parser_stack(yypParser);
%%
ParseARG_STORE;
}
static void yy_syntax_error(
yyParser *yypParser,
int yymajor _U_,
ParseTOKENTYPE yyminor
){
ParseARG_FETCH;
#define TOKEN yyminor
%%
ParseARG_STORE;
}
static void yy_accept(
yyParser *yypParser
){
ParseARG_FETCH;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
}
#endif
#ifndef YYNOERRORRECOVERY
yypParser->yyerrcnt = -1;
#endif
assert( yypParser->yytos==yypParser->yystack );
%%
ParseARG_STORE;
}
void Parse(
void *yyp,
int yymajor,
ParseTOKENTYPE yyminor
ParseARG_PDECL
){
YYMINORTYPE yyminorunion;
unsigned int yyact;
#if !defined(YYERRORSYMBOL) && !defined(YYNOERRORRECOVERY)
int yyendofinput;
#endif
#ifdef YYERRORSYMBOL
int yyerrorhit = 0;
#endif
yyParser *yypParser;
yypParser = (yyParser*)yyp;
assert( yypParser->yytos!=0 );
#if !defined(YYERRORSYMBOL) && !defined(YYNOERRORRECOVERY)
yyendofinput = (yymajor==0);
#endif
ParseARG_STORE;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sInput '%s'\n",yyTracePrompt,yyTokenName[yymajor]);
}
#endif
do{
yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
if( yyact <= YY_MAX_SHIFTREDUCE ){
yy_shift(yypParser,yyact,yymajor,yyminor);
#ifndef YYNOERRORRECOVERY
yypParser->yyerrcnt--;
#endif
yymajor = YYNOCODE;
}else if( yyact <= YY_MAX_REDUCE ){
yy_reduce(yypParser,yyact-YY_MIN_REDUCE);
}else{
assert( yyact == YY_ERROR_ACTION );
yyminorunion.yy0 = yyminor;
#ifdef YYERRORSYMBOL
int yymx;
#endif
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
}
#endif
#ifdef YYERRORSYMBOL
if( yypParser->yyerrcnt<0 ){
yy_syntax_error(yypParser,yymajor,yyminor);
}
yymx = yypParser->yytos->major;
if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sDiscard input token %s\n",
yyTracePrompt,yyTokenName[yymajor]);
}
#endif
yy_destructor(yypParser, (YYCODETYPE)yymajor, &yyminorunion);
yymajor = YYNOCODE;
}else{
while( yypParser->yytos >= yypParser->yystack
&& yymx != YYERRORSYMBOL
&& (yyact = yy_find_reduce_action(
yypParser->yytos->stateno,
YYERRORSYMBOL)) >= YY_MIN_REDUCE
){
yy_pop_parser_stack(yypParser);
}
if( yypParser->yytos < yypParser->yystack || yymajor==0 ){
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
yy_parse_failed(yypParser);
#ifndef YYNOERRORRECOVERY
yypParser->yyerrcnt = -1;
#endif
yymajor = YYNOCODE;
}else if( yymx!=YYERRORSYMBOL ){
yy_shift(yypParser,yyact,YYERRORSYMBOL,yyminor);
}
}
yypParser->yyerrcnt = 3;
yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
yy_syntax_error(yypParser,yymajor, yyminor);
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
yymajor = YYNOCODE;
#else
if( yypParser->yyerrcnt<=0 ){
yy_syntax_error(yypParser,yymajor, yyminor);
}
yypParser->yyerrcnt = 3;
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
if( yyendofinput ){
yy_parse_failed(yypParser);
#ifndef YYNOERRORRECOVERY
yypParser->yyerrcnt = -1;
#endif
}
yymajor = YYNOCODE;
#endif
}
}while( yymajor!=YYNOCODE && yypParser->yytos>yypParser->yystack );
#ifndef NDEBUG
if( yyTraceFILE ){
yyStackEntry *i;
char cDiv = '[';
fprintf(yyTraceFILE,"%sReturn. Stack=",yyTracePrompt);
for(i=&yypParser->yystack[1]; i<=yypParser->yytos; i++){
fprintf(yyTraceFILE,"%c%s", cDiv, yyTokenName[i->major]);
cDiv = ' ';
}
fprintf(yyTraceFILE,"]\n");
}
#endif
return;
}
