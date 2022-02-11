static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 () ;
if ( V_4 -> V_6 ) {
unsigned long V_7 ;
F_3 ( V_7 ) ;
if ( V_4 -> V_8 ) {
F_4 ( V_4 -> V_6 , & V_9 [ V_5 ] -> V_10 ) ;
} else {
F_4 ( V_4 -> V_6 , & V_11 -> V_12 ) ;
}
F_5 ( V_7 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 () ;
if ( V_4 -> V_6 ) {
unsigned long V_7 ;
F_3 ( V_7 ) ;
if ( V_4 -> V_8 ) {
F_4 ( V_4 -> V_6 , & V_9 [ V_5 ] -> V_13 ) ;
} else {
F_4 ( V_4 -> V_6 , & V_11 -> V_14 ) ;
}
F_5 ( V_7 ) ;
}
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_15 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_10 ( V_2 -> V_15 ) ;
}
static unsigned int F_11 ( struct V_16 * V_17 ,
unsigned int V_18 )
{
struct V_3 * V_4 ;
unsigned int V_15 ;
unsigned int V_19 ;
if ( V_18 >= V_20 ) {
F_12 ( L_1 , V_18 ) ;
F_13 () ;
}
V_19 = ( V_18 & 0xf ) ;
V_15 = F_14 ( V_18 , V_19 ) ;
if ( V_15 == 0 )
goto V_21;
V_4 = F_15 ( V_15 ) ;
if ( F_16 ( V_4 ) )
goto V_21;
V_4 = F_17 ( sizeof( struct V_3 ) , V_22 ) ;
if ( F_16 ( ! V_4 ) ) {
F_12 ( L_2 ) ;
F_13 () ;
}
V_4 -> V_6 = V_23 [ V_18 ] ;
V_4 -> V_8 = V_18 < V_24 ;
F_18 ( V_15 , & V_25 ,
V_26 , L_3 ) ;
F_19 ( V_15 , V_4 ) ;
V_21:
return V_15 ;
}
static void F_20 ( int V_5 , int V_27 )
{
F_4 ( F_21 ( V_27 ) , & V_9 [ V_5 ] -> V_10 ) ;
}
static void F_22 ( int V_5 , int V_27 )
{
F_4 ( F_21 ( V_27 ) , & V_9 [ V_5 ] -> V_13 ) ;
}
static void F_23 ( int V_5 )
{
F_4 ( V_5 , & V_11 -> V_28 ) ;
}
static void F_24 ( void )
{
F_25 ( & V_29 -> V_30 ) ;
}
void F_26 ( struct V_31 * V_32 )
{
unsigned long V_33 , V_34 , V_35 ;
F_27 ( V_36 L_4 ) ;
__asm__ __volatile__("mov 0x500, %%g1\n\t"
"lda [%%g1] 0x4, %0\n\t"
"mov 0x600, %%g1\n\t"
"lda [%%g1] 0x4, %1\n\t" :
"=r" (afsr), "=r" (afar));
F_27 ( V_36 L_5 , V_33 , V_34 ) ;
V_35 = F_25 ( & V_11 -> V_37 ) ;
F_27 ( V_36 L_6 , V_35 ) ;
if ( V_35 & V_38 )
F_27 ( V_36 L_7 ) ;
if ( V_35 & V_39 )
F_27 ( V_36 L_8 ) ;
if ( V_35 & V_40 )
F_27 ( V_36 L_9 ) ;
if ( V_35 & V_41 )
F_27 ( V_36 L_10 ) ;
F_27 ( V_36 L_11 ) ;
F_28 ( V_32 ) ;
F_13 () ;
}
void F_29 ( void )
{
unsigned long V_7 ;
F_3 ( V_7 ) ;
F_4 ( V_23 [ V_42 ] , & V_11 -> V_14 ) ;
F_5 ( V_7 ) ;
}
void F_30 ( int V_5 )
{
F_25 ( & V_43 [ V_5 ] -> V_44 ) ;
}
static void F_31 ( int V_5 , unsigned int V_45 )
{
F_4 ( V_45 , & V_43 [ V_5 ] -> V_44 ) ;
}
static void T_1 F_32 ( T_2 V_46 )
{
struct V_47 * V_48 = F_33 ( NULL , L_12 ) ;
int V_49 , V_50 , V_51 , V_52 ;
unsigned int V_15 ;
const T_3 * V_53 ;
if ( ! V_48 ) {
F_27 ( V_36 L_13 ) ;
return;
}
V_53 = F_34 ( V_48 , L_14 , & V_51 ) ;
F_35 ( V_48 ) ;
if ( ! V_53 ) {
F_27 ( V_36 L_15 ) ;
return;
}
V_52 = ( V_51 / sizeof( T_3 ) ) - 1 ;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_43 [ V_49 ] = ( void V_54 * )
( unsigned long ) V_53 [ V_49 ] ;
}
V_29 = ( void V_54 * )
( unsigned long ) V_53 [ V_52 ] ;
F_4 ( 0x00000000 , & V_29 -> V_55 ) ;
F_4 ( ( ( ( 1000000 / V_56 ) + 1 ) << 10 ) , & V_29 -> V_30 ) ;
V_57 = & V_29 -> V_58 ;
V_15 = F_11 ( NULL , V_59 ) ;
V_50 = F_36 ( V_15 , V_46 , V_60 , L_16 , NULL ) ;
if ( V_50 ) {
F_27 ( V_36 L_17 ,
V_50 ) ;
return;
}
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ )
F_4 ( 0 , & V_43 [ V_49 ] -> V_44 ) ;
if ( V_52 == 4 )
F_4 ( V_61 , & V_11 -> V_12 ) ;
#ifdef F_37
{
unsigned long V_7 ;
struct V_62 * V_63 = & V_64 [ V_65 + ( 14 - 1 ) ] ;
F_3 ( V_7 ) ;
V_63 -> V_66 = V_67 [ 0 ] ;
V_63 -> V_68 = V_67 [ 1 ] ;
V_63 -> V_69 = V_67 [ 2 ] ;
V_63 -> V_70 = V_67 [ 3 ] ;
F_38 () ;
F_5 ( V_7 ) ;
}
#endif
}
void T_1 F_39 ( void )
{
struct V_47 * V_48 = F_33 ( NULL , L_18 ) ;
int V_51 , V_49 , V_71 , V_72 ;
const T_3 * V_53 ;
if ( ! V_48 ) {
F_27 ( V_36 L_19 ) ;
return;
}
V_53 = F_34 ( V_48 , L_14 , & V_51 ) ;
F_35 ( V_48 ) ;
if ( ! V_53 ) {
F_27 ( V_36 L_20 ) ;
return;
}
V_72 = ( V_51 / sizeof( T_3 ) ) - 1 ;
for ( V_49 = 0 ; V_49 < V_72 ; V_49 ++ ) {
V_9 [ V_49 ] = ( void V_54 * )
( unsigned long ) V_53 [ V_49 ] ;
}
V_11 = ( void V_54 * )
( unsigned long ) V_53 [ V_72 ] ;
F_40 () ;
F_4 ( ~ V_73 , & V_11 -> V_12 ) ;
for ( V_49 = 0 ; ! F_41 ( V_49 , NULL , & V_71 ) ; V_49 ++ )
F_4 ( ~ 0x17fff , & V_9 [ V_71 ] -> V_13 ) ;
if ( V_72 == 4 )
F_4 ( 0 , & V_11 -> V_28 ) ;
F_42 ( V_74 , F_24 , V_75 ) ;
F_42 ( V_76 , F_31 , V_75 ) ;
V_77 . V_78 = F_32 ;
V_77 . V_79 = F_11 ;
#ifdef F_37
F_42 ( V_80 , F_20 , V_75 ) ;
F_42 ( V_81 , F_22 , V_75 ) ;
F_42 ( V_82 , F_23 , V_75 ) ;
#endif
}
