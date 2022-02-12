void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
yyTraceFILE = TraceFILE;
yyTracePrompt = zTracePrompt;
if( yyTraceFILE==0 ) yyTracePrompt = 0;
else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
static void yyGrowStack(yyParser *p){
int newSize;
yyStackEntry *pNew;
newSize = p->yystksz*2 + 100;
pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
if( pNew ){
p->yystack = pNew;
p->yystksz = newSize;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
yyTracePrompt, p->yystksz);
}
#endif
}
}
void *ParseAlloc(void *(*mallocProc)(YYMALLOCARGTYPE)){
yyParser *pParser;
pParser = (yyParser*)(*mallocProc)( (YYMALLOCARGTYPE)sizeof(yyParser) );
if( pParser ){
pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
pParser->yystack = NULL;
pParser->yystksz = 0;
yyGrowStack(pParser);
#endif
}
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
assert( pParser->yyidx>=0 );
yytos = &pParser->yystack[pParser->yyidx--];
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sPopping %s\n",
yyTracePrompt,
yyTokenName[yytos->major]);
}
#endif
yy_destructor(pParser, yytos->major, &yytos->minor);
}
void ParseFree(
void *p,
void (*freeProc)(void*)
){
yyParser *pParser = (yyParser*)p;
#ifndef YYPARSEFREENEVERNULL
if( pParser==0 ) return;
#endif
while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
free(pParser->yystack);
#endif
(*freeProc)((void*)pParser);
}
int ParseStackPeak(void *p){
yyParser *pParser = (yyParser*)p;
return pParser->yyidxMax;
}
static int yy_find_shift_action(
yyParser *pParser,
YYCODETYPE iLookAhead
){
int i;
int stateno = pParser->yystack[pParser->yyidx].stateno;
if( stateno>=YY_MIN_REDUCE ) return stateno;
assert( stateno <= YY_SHIFT_COUNT );
do{
i = yy_shift_ofst[stateno];
if( i==YY_SHIFT_USE_DFLT ) return yy_default[stateno];
assert( iLookAhead!=YYNOCODE );
i += iLookAhead;
if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
if( iLookAhead>0 ){
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
yy_lookahead[j]==YYWILDCARD
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
}
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
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor _U_){
ParseARG_FETCH;
yypParser->yyidx--;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
}
#endif
while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
%%
ParseARG_STORE;
}
static void yyTraceShift(yyParser *yypParser, int yyNewState){
if( yyTraceFILE ){
if( yyNewState<YYNSTATE ){
fprintf(yyTraceFILE,"%sShift '%s', go to state %d\n",
yyTracePrompt,yyTokenName[yypParser->yystack[yypParser->yyidx].major],
yyNewState);
}else{
fprintf(yyTraceFILE,"%sShift '%s'\n",
yyTracePrompt,yyTokenName[yypParser->yystack[yypParser->yyidx].major]);
}
}
}
static void yy_shift(
yyParser *yypParser,
int yyNewState,
int yyMajor,
YYMINORTYPE *yypMinor
){
yyStackEntry *yytos;
yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
if( yypParser->yyidx>yypParser->yyidxMax ){
yypParser->yyidxMax = yypParser->yyidx;
}
#endif
#if YYSTACKDEPTH>0
if( yypParser->yyidx>=YYSTACKDEPTH ){
yyStackOverflow(yypParser, yypMinor);
return;
}
#else
if( yypParser->yyidx>=yypParser->yystksz ){
yyGrowStack(yypParser);
if( yypParser->yyidx>=yypParser->yystksz ){
yyStackOverflow(yypParser, yypMinor);
return;
}
}
#endif
yytos = &yypParser->yystack[yypParser->yyidx];
yytos->stateno = (YYACTIONTYPE)yyNewState;
yytos->major = (YYCODETYPE)yyMajor;
yytos->minor = *yypMinor;
yyTraceShift(yypParser, yyNewState);
}
static void yy_reduce(
yyParser *yypParser,
int yyruleno
){
int yygoto;
int yyact;
YYMINORTYPE yygotominor;
yyStackEntry *yymsp;
int yysize;
ParseARG_FETCH;
yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
if( yyTraceFILE && yyruleno>=0
&& yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
yysize = yyRuleInfo[yyruleno].nrhs;
fprintf(yyTraceFILE, "%sReduce [%s], go to state %d.\n", yyTracePrompt,
yyRuleName[yyruleno], yymsp[-yysize].stateno);
}
#endif
yygotominor = yyzerominor;
switch( yyruleno ){
%%
};
assert( yyruleno>=0 && yyruleno<(int)(sizeof(yyRuleInfo)/sizeof(yyRuleInfo[0])) );
yygoto = yyRuleInfo[yyruleno].lhs;
yysize = yyRuleInfo[yyruleno].nrhs;
yypParser->yyidx -= yysize;
yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
if( yyact <= YY_MAX_SHIFTREDUCE ){
if( yyact>YY_MAX_SHIFT ) yyact += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
if( yysize ){
yypParser->yyidx++;
yymsp -= yysize-1;
yymsp->stateno = (YYACTIONTYPE)yyact;
yymsp->major = (YYCODETYPE)yygoto;
yymsp->minor = yygotominor;
yyTraceShift(yypParser, yyact);
}else{
yy_shift(yypParser,yyact,yygoto,&yygotominor);
}
}else{
assert( yyact == YY_ACCEPT_ACTION );
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
while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
%%
ParseARG_STORE;
}
static void yy_syntax_error(
yyParser *yypParser,
int yymajor _U_,
YYMINORTYPE yyminor
){
ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
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
while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
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
int yyact;
#if !defined(YYERRORSYMBOL) && !defined(YYNOERRORRECOVERY)
int yyendofinput;
#endif
#ifdef YYERRORSYMBOL
int yyerrorhit = 0;
#endif
yyParser *yypParser;
yypParser = (yyParser*)yyp;
if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
if( yypParser->yystksz <=0 ){
yyminorunion = yyzerominor;
yyStackOverflow(yypParser, &yyminorunion);
return;
}
#endif
yypParser->yyidx = 0;
yypParser->yyerrcnt = -1;
yypParser->yystack[0].stateno = 0;
yypParser->yystack[0].major = 0;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sInitialize. Empty stack. State 0\n",
yyTracePrompt);
}
#endif
}
yyminorunion.yy0 = yyminor;
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
if( yyact > YY_MAX_SHIFT ) yyact += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
yy_shift(yypParser,yyact,yymajor,&yyminorunion);
yypParser->yyerrcnt--;
yymajor = YYNOCODE;
}else if( yyact <= YY_MAX_REDUCE ){
yy_reduce(yypParser,yyact-YY_MIN_REDUCE);
}else{
assert( yyact == YY_ERROR_ACTION );
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
yy_syntax_error(yypParser,yymajor,yyminorunion);
}
yymx = yypParser->yystack[yypParser->yyidx].major;
if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sDiscard input token %s\n",
yyTracePrompt,yyTokenName[yymajor]);
}
#endif
yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
yymajor = YYNOCODE;
}else{
while(
yypParser->yyidx >= 0 &&
yymx != YYERRORSYMBOL &&
(yyact = yy_find_reduce_action(
yypParser->yystack[yypParser->yyidx].stateno,
YYERRORSYMBOL)) >= YY_MIN_REDUCE
){
yy_pop_parser_stack(yypParser);
}
if( yypParser->yyidx < 0 || yymajor==0 ){
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
yy_parse_failed(yypParser);
yymajor = YYNOCODE;
}else if( yymx!=YYERRORSYMBOL ){
YYMINORTYPE u2;
u2.YYERRSYMDT = 0;
yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
}
}
yypParser->yyerrcnt = 3;
yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
yy_syntax_error(yypParser,yymajor,yyminorunion);
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
yymajor = YYNOCODE;
#else
if( yypParser->yyerrcnt<=0 ){
yy_syntax_error(yypParser,yymajor,yyminorunion);
}
yypParser->yyerrcnt = 3;
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
if( yyendofinput ){
yy_parse_failed(yypParser);
}
yymajor = YYNOCODE;
#endif
}
}while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
#ifndef NDEBUG
if( yyTraceFILE ){
int i;
fprintf(yyTraceFILE,"%sReturn. Stack=",yyTracePrompt);
for(i=1; i<=yypParser->yyidx; i++)
fprintf(yyTraceFILE,"%c%s", i==1 ? '[' : ' ',
yyTokenName[yypParser->yystack[i].major]);
fprintf(yyTraceFILE,"]\n");
}
#endif
return;
}
