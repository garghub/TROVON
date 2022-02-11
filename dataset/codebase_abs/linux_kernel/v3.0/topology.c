static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
F_2 ( & V_4 ) ;
if ( ! V_5 || ! V_6 ) {
F_3 ( & V_4 , F_4 ( V_3 ) ) ;
return V_4 ;
}
while ( V_2 ) {
if ( F_5 ( V_3 , & V_2 -> V_4 ) ) {
V_4 = V_2 -> V_4 ;
break;
}
V_2 = V_2 -> V_7 ;
}
if ( F_6 ( & V_4 ) )
F_3 ( & V_4 , F_4 ( V_3 ) ) ;
return V_4 ;
}
static void F_7 ( struct V_8 * V_9 ,
struct V_1 * V_10 , struct V_1 * V_11 )
{
unsigned int V_3 ;
for ( V_3 = F_8 ( & V_9 -> V_4 [ 0 ] , V_12 ) ;
V_3 < V_12 ;
V_3 = F_9 ( & V_9 -> V_4 [ 0 ] , V_12 , V_3 + 1 ) )
{
unsigned int V_13 , V_14 ;
V_13 = V_12 - 1 - V_3 + V_9 -> V_15 ;
F_10 (lcpu) {
if ( F_11 ( V_14 ) != V_13 )
continue;
#ifdef F_12
F_13 ( V_14 , & V_10 -> V_4 ) ;
V_16 [ V_14 ] = V_10 -> V_17 ;
#endif
F_13 ( V_14 , & V_11 -> V_4 ) ;
V_18 [ V_14 ] = V_11 -> V_17 ;
V_19 [ V_14 ] = V_9 -> V_20 ;
}
}
}
static void F_14 ( void )
{
struct V_1 * V_2 ;
V_2 = & V_21 ;
while ( V_2 ) {
F_2 ( & V_2 -> V_4 ) ;
V_2 = V_2 -> V_7 ;
}
#ifdef F_12
V_2 = & V_22 ;
while ( V_2 ) {
F_2 ( & V_2 -> V_4 ) ;
V_2 = V_2 -> V_7 ;
}
#endif
}
static union V_23 * F_15 ( union V_23 * V_24 )
{
if ( ! V_24 -> V_25 )
return (union V_23 * ) ( (struct V_8 * ) V_24 + 1 ) ;
return (union V_23 * ) ( (struct V_26 * ) V_24 + 1 ) ;
}
static void F_16 ( struct V_27 * V_2 )
{
#ifdef F_12
struct V_1 * V_10 = & V_22 ;
#else
struct V_1 * V_10 = NULL ;
#endif
struct V_1 * V_11 = & V_21 ;
union V_23 * V_24 , * V_28 ;
F_17 ( & V_29 ) ;
F_14 () ;
V_24 = V_2 -> V_24 ;
V_28 = (union V_23 * ) ( ( unsigned long ) V_2 + V_2 -> V_30 ) ;
while ( V_24 < V_28 ) {
switch ( V_24 -> V_25 ) {
#ifdef F_12
case 2 :
V_10 = V_10 -> V_7 ;
V_10 -> V_17 = V_24 -> V_31 . V_17 ;
break;
#endif
case 1 :
V_11 = V_11 -> V_7 ;
V_11 -> V_17 = V_24 -> V_31 . V_17 ;
break;
case 0 :
F_7 ( & V_24 -> V_3 , V_10 , V_11 ) ;
break;
default:
F_14 () ;
goto V_32;
}
V_24 = F_15 ( V_24 ) ;
}
V_32:
F_18 ( & V_29 ) ;
}
static void F_19 ( void )
{
int V_3 ;
F_20 ( & V_33 ) ;
F_21 (cpu)
V_19 [ V_3 ] = V_34 ;
F_22 ( & V_33 ) ;
}
static int F_23 ( unsigned long V_35 )
{
int V_36 ;
asm volatile(
" .insn rre,0xb9a20000,%1,%1\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (rc)
: "d" (fc) : "cc");
return V_36 ;
}
int F_24 ( int V_35 )
{
int V_3 ;
int V_36 ;
if ( ! V_6 )
return - V_37 ;
if ( V_35 )
V_36 = F_23 ( V_38 ) ;
else
V_36 = F_23 ( V_39 ) ;
if ( V_36 )
return - V_40 ;
F_21 (cpu)
V_19 [ V_3 ] = V_41 ;
return V_36 ;
}
static void F_25 ( void )
{
unsigned long V_42 ;
int V_3 ;
F_26 ( & V_29 , V_42 ) ;
F_21 (cpu) {
V_43 [ V_3 ] = F_1 ( & V_21 , V_3 ) ;
#ifdef F_12
V_44 [ V_3 ] = F_1 ( & V_22 , V_3 ) ;
#endif
}
F_27 ( & V_29 , V_42 ) ;
}
void F_28 ( struct V_27 * V_2 )
{
#ifdef F_12
int V_36 ;
V_36 = F_29 ( V_2 , 15 , 1 , 3 ) ;
if ( V_36 != - V_45 )
return;
#endif
F_29 ( V_2 , 15 , 1 , 2 ) ;
}
int F_30 ( void )
{
struct V_27 * V_2 = V_46 ;
struct V_47 * V_48 ;
int V_3 ;
if ( ! V_6 ) {
F_25 () ;
F_19 () ;
return 0 ;
}
F_28 ( V_2 ) ;
F_16 ( V_2 ) ;
F_25 () ;
F_31 (cpu) {
V_48 = F_32 ( V_3 ) ;
F_33 ( & V_48 -> V_49 , V_50 ) ;
}
return 1 ;
}
static void F_34 ( struct V_51 * V_52 )
{
F_35 () ;
}
void F_36 ( void )
{
F_37 ( & V_53 ) ;
}
static void F_38 ( unsigned long V_54 )
{
if ( F_23 ( V_55 ) )
F_36 () ;
F_39 () ;
}
static void F_39 ( void )
{
V_56 . V_57 = F_38 ;
V_56 . V_58 = 0 ;
V_56 . V_59 = V_60 + 60 * V_61 ;
F_40 ( & V_56 ) ;
}
static int T_2 F_41 ( char * V_62 )
{
if ( strncmp ( V_62 , L_1 , 3 ) )
return 0 ;
V_5 = 0 ;
return 0 ;
}
static int T_2 F_42 ( void )
{
int V_36 ;
V_36 = 0 ;
if ( ! V_6 ) {
F_19 () ;
goto V_32;
}
F_43 ( & V_56 ) ;
F_39 () ;
V_32:
F_25 () ;
return V_36 ;
}
static void F_44 ( struct V_27 * V_2 , struct V_1 * V_4 ,
int V_63 )
{
int V_64 , V_65 ;
V_65 = V_2 -> V_66 [ V_67 - V_63 ] ;
for ( V_64 = 0 ; V_64 < V_2 -> V_68 - V_63 ; V_64 ++ )
V_65 *= V_2 -> V_66 [ V_67 - V_63 - 1 - V_64 ] ;
V_65 = F_45 ( V_65 , 1 ) ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_4 -> V_7 = F_46 ( sizeof( struct V_1 ) ) ;
V_4 = V_4 -> V_7 ;
}
}
void T_2 F_47 ( void )
{
struct V_27 * V_2 ;
int V_64 ;
if ( ! V_6 )
return;
V_46 = F_48 ( V_69 ) ;
V_2 = V_46 ;
F_28 ( V_2 ) ;
F_49 ( L_2 ) ;
for ( V_64 = 0 ; V_64 < V_67 ; V_64 ++ )
F_50 ( L_3 , V_2 -> V_66 [ V_64 ] ) ;
F_50 ( L_4 , V_2 -> V_68 ) ;
F_44 ( V_2 , & V_21 , 2 ) ;
#ifdef F_12
F_44 ( V_2 , & V_22 , 3 ) ;
#endif
}
