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
asm volatile(
" .insn rrf,0xb9ab0000,%1,%1,0,0\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "+&d" (rc), "+&d" (tmp));
if ( T_3 )
V_3 = 0 ;
}
static inline void F_4 ( struct V_6 * V_6 , int V_7 )
{
int V_8 , T_3 ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 ) ; V_8 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_UNUSED));
}
void F_5 ( struct V_6 * V_6 , int V_7 )
{
if ( ! V_3 )
return;
F_4 ( V_6 , V_7 ) ;
}
static inline void F_6 ( struct V_6 * V_6 , int V_7 )
{
int V_8 , T_3 ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 ) ; V_8 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_STABLE));
}
void F_7 ( struct V_6 * V_6 , int V_7 )
{
if ( ! V_3 )
return;
F_6 ( V_6 , V_7 ) ;
}
void F_8 ( int V_9 )
{
unsigned long V_10 , V_7 , V_11 ;
struct V_12 * V_13 ;
struct V_6 * V_6 ;
struct V_14 * V_14 ;
if ( ! V_3 )
return;
if ( V_9 )
F_9 ( NULL ) ;
F_10 (zone) {
F_11 ( & V_14 -> V_15 , V_10 ) ;
F_12 (order, t) {
F_13 (l, &zone->free_area[order].free_list[t]) {
V_6 = F_14 ( V_13 , struct V_6 , V_16 ) ;
if ( V_9 )
F_6 ( V_6 , V_7 ) ;
else
F_4 ( V_6 , V_7 ) ;
}
}
F_15 ( & V_14 -> V_15 , V_10 ) ;
}
}
