static int T_1 F_1 ( char * V_1 )
{
char * V_2 ;
V_2 = F_2 ( V_1 ) ;
if ( strcmp ( V_2 , L_1 ) == 0 || strcmp ( V_2 , L_2 ) == 0 ) {
V_3 = 1 ;
return 1 ;
}
V_3 = 0 ;
if ( strcmp ( V_2 , L_3 ) == 0 || strcmp ( V_2 , L_4 ) == 0 )
return 1 ;
return 0 ;
}
void T_1 F_3 ( void )
{
register unsigned long T_2 V_4 ( L_5 ) = 0 ;
register int T_3 V_4 ( L_6 ) = - V_5 ;
if ( ! V_3 )
return;
if ( V_6 || V_7 . type == V_8 ) {
V_3 = 0 ;
return;
}
asm volatile(
" .insn rrf,0xb9ab0000,%1,%1,0,0\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "+&d" (rc), "+&d" (tmp));
if ( T_3 )
V_3 = 0 ;
}
static inline void F_4 ( struct V_9 * V_9 , int V_10 )
{
int V_11 , T_3 ;
for ( V_11 = 0 ; V_11 < ( 1 << V_10 ) ; V_11 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_UNUSED));
}
void F_5 ( struct V_9 * V_9 , int V_10 )
{
if ( ! V_3 )
return;
F_4 ( V_9 , V_10 ) ;
}
static inline void F_6 ( struct V_9 * V_9 , int V_10 )
{
int V_11 , T_3 ;
for ( V_11 = 0 ; V_11 < ( 1 << V_10 ) ; V_11 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_STABLE));
}
void F_7 ( struct V_9 * V_9 , int V_10 )
{
if ( ! V_3 )
return;
F_6 ( V_9 , V_10 ) ;
}
void F_8 ( int V_12 )
{
unsigned long V_13 , V_10 , V_14 ;
struct V_15 * V_16 ;
struct V_9 * V_9 ;
struct V_17 * V_17 ;
if ( ! V_3 )
return;
if ( V_12 )
F_9 ( NULL ) ;
F_10 (zone) {
F_11 ( & V_17 -> V_18 , V_13 ) ;
F_12 (order, t) {
F_13 (l, &zone->free_area[order].free_list[t]) {
V_9 = F_14 ( V_16 , struct V_9 , V_19 ) ;
if ( V_12 )
F_6 ( V_9 , V_10 ) ;
else
F_4 ( V_9 , V_10 ) ;
}
}
F_15 ( & V_17 -> V_18 , V_13 ) ;
}
}
