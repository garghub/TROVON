static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_6 ) {
unsigned long V_7 ;
F_4 ( V_7 ) ;
if ( V_4 -> V_8 ) {
F_5 ( V_4 -> V_6 , & V_9 [ V_5 ] -> V_10 ) ;
} else {
F_5 ( V_4 -> V_6 , & V_11 -> V_12 ) ;
}
F_6 ( V_7 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_6 ) {
unsigned long V_7 ;
F_4 ( V_7 ) ;
if ( V_4 -> V_8 ) {
F_5 ( V_4 -> V_6 , & V_9 [ V_5 ] -> V_13 ) ;
} else {
F_5 ( V_4 -> V_6 , & V_11 -> V_14 ) ;
}
F_6 ( V_7 ) ;
}
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_15 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_11 ( V_2 -> V_15 ) ;
}
static unsigned int F_12 ( struct V_16 * V_17 ,
unsigned int V_18 )
{
struct V_3 * V_4 ;
unsigned int V_15 ;
unsigned int V_19 ;
if ( V_18 >= V_20 ) {
F_13 ( L_1 , V_18 ) ;
F_14 () ;
}
V_19 = ( V_18 & 0xf ) ;
V_15 = F_15 ( V_18 , V_19 ) ;
if ( V_15 == 0 )
goto V_21;
V_4 = F_16 ( V_15 ) ;
if ( F_17 ( V_4 ) )
goto V_21;
V_4 = F_18 ( sizeof( struct V_3 ) , V_22 ) ;
if ( F_17 ( ! V_4 ) ) {
F_13 ( L_2 ) ;
F_14 () ;
}
V_4 -> V_6 = V_23 [ V_18 ] ;
V_4 -> V_8 = V_18 < V_24 ;
F_19 ( V_15 , & V_25 ,
V_26 , L_3 ) ;
F_20 ( V_15 , V_4 ) ;
V_21:
return V_15 ;
}
static void F_21 ( void )
{
F_22 ( & V_27 -> V_28 ) ;
}
void F_23 ( struct V_29 * V_30 )
{
unsigned long V_31 , V_32 , V_33 ;
F_24 ( V_34 L_4 ) ;
__asm__ __volatile__("mov 0x500, %%g1\n\t"
"lda [%%g1] 0x4, %0\n\t"
"mov 0x600, %%g1\n\t"
"lda [%%g1] 0x4, %1\n\t" :
"=r" (afsr), "=r" (afar));
F_24 ( V_34 L_5 , V_31 , V_32 ) ;
V_33 = F_22 ( & V_11 -> V_35 ) ;
F_24 ( V_34 L_6 , V_33 ) ;
if ( V_33 & V_36 )
F_24 ( V_34 L_7 ) ;
if ( V_33 & V_37 )
F_24 ( V_34 L_8 ) ;
if ( V_33 & V_38 )
F_24 ( V_34 L_9 ) ;
if ( V_33 & V_39 )
F_24 ( V_34 L_10 ) ;
F_24 ( V_34 L_11 ) ;
F_25 ( V_30 ) ;
F_14 () ;
}
void F_26 ( void )
{
unsigned long V_7 ;
F_4 ( V_7 ) ;
F_5 ( V_23 [ V_40 ] , & V_11 -> V_14 ) ;
F_6 ( V_7 ) ;
}
void F_27 ( int V_5 )
{
F_22 ( & V_41 [ V_5 ] -> V_42 ) ;
}
static void F_28 ( int V_5 , unsigned int V_43 )
{
unsigned int V_44 = V_43 ? F_29 ( V_43 ) : 0 ;
F_5 ( V_44 , & V_41 [ V_5 ] -> V_42 ) ;
}
static void T_1 F_30 ( void )
{
struct V_45 * V_46 = F_31 ( NULL , L_12 ) ;
int V_47 , V_48 , V_49 , V_50 ;
unsigned int V_15 ;
const T_2 * V_51 ;
if ( ! V_46 ) {
F_24 ( V_34 L_13 ) ;
return;
}
V_51 = F_32 ( V_46 , L_14 , & V_49 ) ;
F_33 ( V_46 ) ;
if ( ! V_51 ) {
F_24 ( V_34 L_15 ) ;
return;
}
V_50 = ( V_49 / sizeof( T_2 ) ) - 1 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_41 [ V_47 ] = ( void V_52 * )
( unsigned long ) V_51 [ V_47 ] ;
}
V_27 = ( void V_52 * )
( unsigned long ) V_51 [ V_50 ] ;
F_5 ( 0x00000000 , & V_27 -> V_53 ) ;
#ifdef F_34
V_54 . V_55 = V_56 * 2 ;
V_54 . V_57 |= V_58 ;
#else
V_54 . V_55 = V_56 / V_59 ;
V_54 . V_57 |= V_60 ;
#endif
V_54 . V_57 |= V_61 ;
F_5 ( F_29 ( V_54 . V_55 ) ,
& V_27 -> V_28 ) ;
V_62 = & V_27 -> V_63 ;
V_15 = F_12 ( NULL , V_64 ) ;
V_48 = F_35 ( V_15 , V_65 , V_66 , L_16 , NULL ) ;
if ( V_48 ) {
F_24 ( V_34 L_17 ,
V_48 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
F_5 ( 0 , & V_41 [ V_47 ] -> V_42 ) ;
if ( V_50 == 4 )
F_5 ( V_67 , & V_11 -> V_12 ) ;
#ifdef F_34
{
unsigned long V_7 ;
struct V_68 * V_69 = & V_70 [ V_71 + ( 14 - 1 ) ] ;
F_4 ( V_7 ) ;
V_69 -> V_72 = V_73 [ 0 ] ;
V_69 -> V_74 = V_73 [ 1 ] ;
V_69 -> V_75 = V_73 [ 2 ] ;
V_69 -> V_76 = V_73 [ 3 ] ;
V_77 -> V_78 () ;
F_6 ( V_7 ) ;
}
#endif
}
void T_1 F_36 ( void )
{
struct V_45 * V_46 = F_31 ( NULL , L_18 ) ;
int V_49 , V_47 , V_79 , V_80 ;
const T_2 * V_51 ;
if ( ! V_46 ) {
F_24 ( V_34 L_19 ) ;
return;
}
V_51 = F_32 ( V_46 , L_14 , & V_49 ) ;
F_33 ( V_46 ) ;
if ( ! V_51 ) {
F_24 ( V_34 L_20 ) ;
return;
}
V_80 = ( V_49 / sizeof( T_2 ) ) - 1 ;
for ( V_47 = 0 ; V_47 < V_80 ; V_47 ++ ) {
V_9 [ V_47 ] = ( void V_52 * )
( unsigned long ) V_51 [ V_47 ] ;
}
V_11 = ( void V_52 * )
( unsigned long ) V_51 [ V_80 ] ;
F_37 () ;
F_5 ( ~ V_81 , & V_11 -> V_12 ) ;
for ( V_47 = 0 ; ! F_38 ( V_47 , NULL , & V_79 ) ; V_47 ++ )
F_5 ( ~ 0x17fff , & V_9 [ V_79 ] -> V_13 ) ;
if ( V_80 == 4 )
F_5 ( 0 , & V_11 -> V_82 ) ;
V_54 . V_83 = F_30 ;
V_54 . V_84 = F_12 ;
V_54 . V_85 = V_56 ;
V_54 . V_86 = F_21 ;
V_54 . V_87 = F_28 ;
}
