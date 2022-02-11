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
static inline int F_3 ( void )
{
register unsigned long T_2 V_4 ( L_5 ) = 0 ;
register int T_3 V_4 ( L_6 ) ;
asm volatile(
" .insn rrf,0xb9ab0000,%1,%1,%2,0\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=&d" (rc), "+&d" (tmp)
: "i" (ESSA_GET_STATE), "0" (-EOPNOTSUPP));
return T_3 ;
}
void T_1 F_4 ( void )
{
if ( ! V_3 )
return;
if ( F_3 () ) {
V_3 = 0 ;
return;
}
if ( F_5 ( 147 ) )
V_3 = 2 ;
}
static inline unsigned char F_6 ( struct V_5 * V_5 )
{
unsigned char V_6 ;
asm volatile(" .insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (state)
: "a" (page_to_phys(page)),
"i" (ESSA_GET_STATE));
return V_6 & 0x3f ;
}
static inline void F_7 ( struct V_5 * V_5 , int V_7 )
{
int V_8 , T_3 ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 ) ; V_8 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_UNUSED));
}
static inline void F_8 ( struct V_5 * V_5 , int V_7 )
{
int V_8 , T_3 ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 ) ; V_8 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_STABLE));
}
static inline void F_9 ( struct V_5 * V_5 , int V_7 )
{
int V_8 , T_3 ;
for ( V_8 = 0 ; V_8 < ( 1 << V_7 ) ; V_8 ++ )
asm volatile(".insn rrf,0xb9ab0000,%0,%1,%2,0"
: "=&d" (rc)
: "a" (page_to_phys(page + i)),
"i" (ESSA_SET_STABLE_NODAT));
}
static void F_10 ( T_4 * V_9 , unsigned long V_10 , unsigned long V_11 )
{
unsigned long V_12 ;
struct V_5 * V_5 ;
T_5 * V_13 ;
V_13 = F_11 ( V_9 , V_10 ) ;
do {
V_12 = F_12 ( V_10 , V_11 ) ;
if ( F_13 ( * V_13 ) || F_14 ( * V_13 ) )
continue;
V_5 = F_15 ( F_16 ( * V_13 ) ) ;
F_17 ( V_14 , & V_5 -> V_15 ) ;
} while ( V_13 ++ , V_10 = V_12 , V_10 != V_11 );
}
static void F_18 ( T_6 * V_16 , unsigned long V_10 , unsigned long V_11 )
{
unsigned long V_12 ;
struct V_5 * V_5 ;
T_4 * V_9 ;
int V_8 ;
V_9 = F_19 ( V_16 , V_10 ) ;
do {
V_12 = F_20 ( V_10 , V_11 ) ;
if ( F_21 ( * V_9 ) || F_22 ( * V_9 ) )
continue;
if ( ! F_23 ( * V_9 ) ) {
V_5 = F_15 ( F_24 ( * V_9 ) ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_17 ( V_14 , & V_5 [ V_8 ] . V_15 ) ;
}
F_10 ( V_9 , V_10 , V_12 ) ;
} while ( V_9 ++ , V_10 = V_12 , V_10 != V_11 );
}
static void F_25 ( T_7 * V_17 , unsigned long V_10 , unsigned long V_11 )
{
unsigned long V_12 ;
struct V_5 * V_5 ;
T_6 * V_16 ;
int V_8 ;
V_16 = F_26 ( V_17 , V_10 ) ;
do {
V_12 = F_27 ( V_10 , V_11 ) ;
if ( F_28 ( * V_16 ) )
continue;
if ( ! F_29 ( * V_16 ) ) {
V_5 = F_15 ( F_30 ( * V_16 ) ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_17 ( V_14 , & V_5 [ V_8 ] . V_15 ) ;
}
F_18 ( V_16 , V_10 , V_12 ) ;
} while ( V_16 ++ , V_10 = V_12 , V_10 != V_11 );
}
static void F_31 ( void )
{
unsigned long V_10 , V_12 ;
struct V_5 * V_5 ;
T_7 * V_17 ;
int V_8 ;
V_10 = 0 ;
V_17 = F_32 ( V_10 ) ;
do {
V_12 = F_33 ( V_10 , V_18 ) ;
if ( F_34 ( * V_17 ) )
continue;
if ( ! F_35 ( * V_17 ) ) {
V_5 = F_15 ( F_36 ( * V_17 ) ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_17 ( V_14 , & V_5 [ V_8 ] . V_15 ) ;
}
F_25 ( V_17 , V_10 , V_12 ) ;
} while ( V_17 ++ , V_10 = V_12 , V_10 != V_18 );
}
void T_1 F_37 ( void )
{
struct V_19 * V_20 ;
struct V_5 * V_5 ;
unsigned long V_21 , V_11 , V_22 ;
if ( V_3 < 2 )
return;
F_31 () ;
F_38 (memory, reg) {
V_21 = F_39 ( V_20 ) ;
V_11 = F_40 ( V_20 ) ;
V_5 = F_41 ( V_21 ) ;
for ( V_22 = V_21 ; V_22 < V_11 ; V_22 ++ , V_5 ++ ) {
if ( F_42 ( V_14 , & V_5 -> V_15 ) )
continue;
if ( ! F_43 ( & V_5 -> V_23 ) )
continue;
F_9 ( V_5 , 0 ) ;
}
}
}
void F_44 ( struct V_5 * V_5 , int V_7 )
{
if ( ! V_3 )
return;
F_7 ( V_5 , V_7 ) ;
}
void F_45 ( struct V_5 * V_5 , int V_7 )
{
if ( ! V_3 )
return;
if ( V_3 < 2 )
F_8 ( V_5 , V_7 ) ;
else
F_9 ( V_5 , V_7 ) ;
}
void F_46 ( struct V_5 * V_5 , int V_7 )
{
if ( ! V_3 )
return;
F_8 ( V_5 , V_7 ) ;
}
void F_47 ( struct V_5 * V_5 , int V_7 )
{
if ( V_3 < 2 )
return;
F_9 ( V_5 , V_7 ) ;
}
int F_48 ( struct V_5 * V_5 )
{
unsigned char V_6 ;
if ( V_3 < 2 )
return 0 ;
V_6 = F_6 ( V_5 ) ;
return ! ! ( V_6 & 0x20 ) ;
}
void F_49 ( int V_24 )
{
unsigned long V_15 , V_7 , V_25 ;
struct V_26 * V_27 ;
struct V_5 * V_5 ;
struct V_28 * V_28 ;
if ( ! V_3 )
return;
if ( V_24 )
F_50 ( NULL ) ;
F_51 (zone) {
F_52 ( & V_28 -> V_29 , V_15 ) ;
F_53 (order, t) {
F_54 (l, &zone->free_area[order].free_list[t]) {
V_5 = F_55 ( V_27 , struct V_5 , V_23 ) ;
if ( V_24 )
F_8 ( V_5 , 0 ) ;
else
F_7 ( V_5 , V_7 ) ;
}
}
F_56 ( & V_28 -> V_29 , V_15 ) ;
}
}
