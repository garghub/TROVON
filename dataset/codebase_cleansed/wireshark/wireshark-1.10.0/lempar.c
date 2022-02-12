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
void *ParseAlloc(void *(*mallocProc)(gulong)){
yyParser *pParser;
pParser = (yyParser*)(*mallocProc)( (gulong)sizeof(yyParser) );
#endif
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
static void yy_destructor(yyParser *yypParser, YYCODETYPE yymajor, YYMINORTYPE *yypminor){
ParseARG_FETCH;
switch( yymajor ){
%%
default: break;
}
}
static int yy_pop_parser_stack(yyParser *pParser){
YYCODETYPE yymajor;
yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];
if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
if( yyTraceFILE && pParser->yyidx>=0 ){
fprintf(yyTraceFILE,"%sPopping %s\n",
yyTracePrompt,
yyTokenName[yytos->major]);
}
#endif
yymajor = yytos->major;
yy_destructor(pParser, yymajor, &yytos->minor);
pParser->yyidx--;
return yymajor;
}
void ParseFree(
void *p,
void (*freeProc)(void*)
){
yyParser *pParser = (yyParser*)p;
if( pParser==0 ) return;
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
if( stateno>YY_SHIFT_MAX
|| (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
return yy_default[stateno];
}
assert( iLookAhead!=YYNOCODE );
i += iLookAhead;
if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
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
return yy_find_shift_action(pParser, iFallback);
}
#endif
#ifdef YYWILDCARD
{
int j = i - iLookAhead + YYWILDCARD;
if( j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD ){
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
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
}
static int yy_find_reduce_action(
int stateno,
YYCODETYPE iLookAhead
){
int i;
#ifdef YYERRORSYMBOL
if( stateno>YY_REDUCE_MAX ){
return yy_default[stateno];
}
#else
assert( stateno<=YY_REDUCE_MAX );
#endif
i = yy_reduce_ofst[stateno];
assert( i!=YY_REDUCE_USE_DFLT );
assert( iLookAhead!=YYNOCODE );
i += iLookAhead;
#ifdef YYERRORSYMBOL
if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
return yy_default[stateno];
}
#else
assert( i>=0 && i<YY_SZ_ACTTAB );
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
#ifndef NDEBUG
if( yyTraceFILE && yypParser->yyidx>0 ){
int i;
fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
for(i=1; i<=yypParser->yyidx; i++)
fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
fprintf(yyTraceFILE,"\n");
}
#endif
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
fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
yyRuleName[yyruleno]);
}
#endif
yygotominor = yyzerominor;
switch( yyruleno ){
%%
};
yygoto = yyRuleInfo[yyruleno].lhs;
yysize = yyRuleInfo[yyruleno].nrhs;
yypParser->yyidx -= yysize;
yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
if( yyact < YYNSTATE ){
#ifdef NDEBUG
if( yysize ){
yypParser->yyidx++;
yymsp -= yysize-1;
yymsp->stateno = (YYACTIONTYPE)yyact;
yymsp->major = (YYCODETYPE)yygoto;
yymsp->minor = yygotominor;
}else
#endif
{
yy_shift(yypParser,yyact,yygoto,&yygotominor);
}
}else{
assert( yyact == YYNSTATE + YYNRULE + 1 );
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
yyParser *yypParser _U_,
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
int yyendofinput;
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
}
yyminorunion.yy0 = yyminor;
yyendofinput = (yymajor==0);
ParseARG_STORE;
#ifndef NDEBUG
if( yyTraceFILE ){
fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
}
#endif
do{
yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
if( yyact<YYNSTATE ){
assert( !yyendofinput );
yy_shift(yypParser,yyact,yymajor,&yyminorunion);
yypParser->yyerrcnt--;
yymajor = YYNOCODE;
}else if( yyact < YYNSTATE + YYNRULE ){
yy_reduce(yypParser,yyact-YYNSTATE);
}else{
#ifdef YYERRORSYMBOL
int yymx;
#endif
assert( yyact == YY_ERROR_ACTION );
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
yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
yymajor = YYNOCODE;
}else{
while(
yypParser->yyidx >= 0 &&
yymx != YYERRORSYMBOL &&
(yyact = yy_find_reduce_action(
yypParser->yystack[yypParser->yyidx].stateno,
YYERRORSYMBOL)) >= YYNSTATE
){
yy_pop_parser_stack(yypParser);
}
if( yypParser->yyidx < 0 || yymajor==0 ){
yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
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
#else
if( yypParser->yyerrcnt<=0 ){
yy_syntax_error(yypParser,yymajor,yyminorunion);
}
yypParser->yyerrcnt = 3;
yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
if( yyendofinput ){
yy_parse_failed(yypParser);
}
yymajor = YYNOCODE;
#endif
}
}while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
return;
}
