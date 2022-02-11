static unsigned int F_1 ( int V_1 , int V_2 , int V_3 )
{
return ( V_1 + 1 ) << 5 | ( V_2 << 2 ) | V_3 ;
}
static void F_2 ( int V_4 )
{
unsigned int V_5 ;
unsigned int V_6 , V_3 ;
unsigned int V_7 ;
V_5 = F_3 ( V_4 ) & 0x3ffff ;
F_4 ( V_4 , V_5 ) ;
V_7 = ( V_4 << 2 ) ;
for ( V_6 = 0 ; V_5 ; V_6 ++ , V_5 >>= 1 ) {
unsigned int V_8 , V_9 ;
if ( ! ( V_5 & 1 ) )
continue;
V_9 = F_5 ( F_6 ( V_6 ) , 0xf << V_7 ) ;
V_9 &= ( 0xf << V_7 ) ;
V_3 = ( 1 << V_7 ) ;
for ( V_8 = 0 ; V_9 != 0 ; V_8 ++ , V_3 <<= 1 ) {
unsigned int V_10 ;
struct V_11 * V_12 ;
if ( ! ( V_9 & V_3 ) )
continue;
V_9 &= ~ V_3 ;
V_10 = F_1 ( V_6 , V_4 , V_8 ) ;
V_12 = V_13 [ V_10 ] ;
while ( V_12 ) {
struct V_11 * V_14 ;
V_14 = V_12 -> V_14 ;
F_7 ( V_12 -> V_15 ) ;
V_12 = V_14 ;
}
F_8 ( F_6 ( V_6 ) , V_3 ) ;
}
}
}
void F_9 ( int V_10 , struct V_16 * V_17 )
{
struct V_16 * V_18 ;
int V_4 = V_19 [ V_10 ] ;
F_10 () ;
F_11 ( 1 << V_10 ) ;
#ifdef F_12
if ( V_10 == V_20 )
F_13 () ;
#endif
V_18 = F_14 ( V_17 ) ;
F_15 () ;
if ( V_4 == 0 ) {
struct V_11 * V_12 ;
V_12 = V_13 [ V_10 ] ;
while ( V_12 ) {
struct V_11 * V_14 ;
V_14 = V_12 -> V_14 ;
F_7 ( V_12 -> V_15 ) ;
V_12 = V_14 ;
}
} else {
F_2 ( V_4 ) ;
}
F_16 () ;
F_14 ( V_18 ) ;
}
static void F_17 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
unsigned int V_25 ;
#ifdef F_12
int V_26 = V_24 -> V_26 ;
unsigned long V_27 ;
#endif
V_25 = V_24 -> V_25 ;
#ifdef F_12
F_18 ( & V_28 , V_27 ) ;
F_19 ( V_26 , F_20 ( V_26 ) | ( 1 << V_25 ) ) ;
F_21 ( & V_28 , V_27 ) ;
#else
F_22 ( F_23 () | ( 1 << V_25 ) ) ;
#endif
}
static void F_24 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
unsigned int V_25 ;
#ifdef F_12
int V_26 = V_24 -> V_26 ;
unsigned long V_27 ;
#endif
V_25 = V_24 -> V_25 ;
#ifdef F_12
F_18 ( & V_28 , V_27 ) ;
F_19 ( V_26 , F_20 ( V_26 ) & ~ ( 1 << V_25 ) ) ;
F_21 ( & V_28 , V_27 ) ;
#else
F_22 ( F_23 () & ~ ( 1 << V_25 ) ) ;
#endif
}
static unsigned int F_25 ( struct V_21 * V_22 )
{
F_26 ( V_22 -> V_15 ) ;
F_24 ( V_22 ) ;
return 0 ;
}
static void F_27 ( struct V_21 * V_22 )
{
F_17 ( V_22 ) ;
F_28 ( V_22 -> V_15 ) ;
}
void T_1 F_29 ( void )
{
struct V_29 * V_30 ;
int V_26 = F_30 ( 1 ) ;
if ( V_26 == - 1 )
V_26 = F_30 ( 0 ) ;
F_31 (dp, L_1 ) {
int V_31 = F_32 ( V_30 , L_2 , 0 ) ;
int V_1 = F_32 ( V_30 , L_3 , 0 ) ;
V_32 [ V_1 ] = V_26 ;
F_33 ( V_31 , V_26 << 3 ) ;
}
F_34 ( V_33 L_4 , V_26 ) ;
}
static void F_35 ( void )
{
F_36 ( & V_34 -> V_35 ) ;
}
static void F_37 ( int V_36 , unsigned int V_37 )
{
unsigned int V_38 = V_37 ? F_38 ( V_37 ) : 0 ;
F_39 ( V_36 , V_38 ) ;
}
static void T_1 F_40 ( void )
{
int V_36 = 0 , V_39 ;
while ( ! F_41 ( V_36 , NULL , & V_39 ) ) {
F_37 ( V_39 >> 3 , 0 ) ;
V_36 ++ ;
}
}
unsigned int F_42 ( unsigned int V_25 ,
unsigned int V_10 ,
unsigned int V_1 )
{
struct V_23 * V_24 ;
unsigned int V_15 ;
V_15 = F_43 ( V_25 , V_10 ) ;
if ( V_15 == 0 ) {
F_44 ( L_5 ,
V_25 , V_10 , V_1 ) ;
goto V_40;
}
V_24 = F_45 ( V_15 ) ;
if ( F_46 ( V_24 ) )
goto V_40;
V_24 = F_47 ( sizeof( struct V_23 ) , V_41 ) ;
if ( F_46 ( ! V_24 ) ) {
F_44 ( L_6 ) ;
F_48 () ;
}
V_24 -> V_26 = V_32 [ V_1 ] ;
V_24 -> V_25 = V_25 ;
F_49 ( V_15 , & V_42 ,
V_43 , L_7 ) ;
F_50 ( V_15 , V_24 ) ;
V_40:
return V_15 ;
}
unsigned int F_51 ( struct V_44 * V_45 ,
unsigned int V_25 )
{
struct V_29 * V_30 = V_45 -> V_46 . V_47 ;
struct V_29 * V_48 , * V_49 = V_30 -> V_50 ;
char * V_51 ;
const struct V_52 * V_17 ;
unsigned int V_10 ;
unsigned int V_15 ;
int V_1 , V_3 ;
int V_4 ;
V_15 = V_25 ;
while ( V_49 ) {
if ( ! strcmp ( V_49 -> V_53 , L_1 ) ) {
V_51 = L_8 ;
break;
}
if ( ! strcmp ( V_49 -> V_53 , L_9 ) ) {
V_51 = L_10 ;
break;
}
V_49 = V_49 -> V_50 ;
}
if ( ! V_49 )
goto V_40;
V_17 = F_52 ( V_30 , L_11 , NULL ) ;
if ( ! V_17 )
goto V_40;
V_3 = V_17 -> V_54 ;
if ( ! V_49 -> V_50 || strcmp ( V_49 -> V_50 -> V_53 , V_51 ) ) {
F_34 ( V_33 L_12 ,
V_49 -> V_55 , V_51 ) ;
goto V_40;
}
V_48 = V_49 -> V_50 ;
V_1 = F_32 ( V_48 , L_3 , - 1 ) ;
if ( V_1 == - 1 ) {
F_34 ( V_33 L_13 ,
V_48 -> V_55 ) ;
goto V_40;
}
V_4 = V_19 [ V_25 ] ;
if ( V_4 )
V_10 = F_1 ( V_1 , V_4 , V_3 ) ;
else
V_10 = V_25 ;
V_15 = F_42 ( V_25 , V_10 , V_1 ) ;
V_40:
return V_15 ;
}
unsigned int F_53 ( unsigned int V_1 , unsigned int V_25 )
{
return F_42 ( V_25 , V_25 , V_1 ) ;
}
static void T_1 F_54 ( void )
{
#ifdef F_12
unsigned long V_27 ;
struct V_56 * V_57 = & V_58 [ V_59 + ( 14 - 1 ) ] ;
V_60 [ 2 ] += V_61 - V_62 ;
F_55 ( V_27 ) ;
V_63 [ 0 ] = 0x01000000 ;
V_57 -> V_64 = V_60 [ 0 ] ;
V_57 -> V_65 = V_60 [ 1 ] ;
V_57 -> V_66 = V_60 [ 2 ] ;
V_57 -> V_67 = V_60 [ 3 ] ;
V_68 -> V_69 () ;
F_56 ( V_27 ) ;
#endif
}
static void T_1 F_57 ( void )
{
struct V_29 * V_30 ;
struct V_70 V_71 ;
unsigned int V_15 ;
const T_2 * V_72 ;
int V_73 ;
int V_1 ;
V_30 = F_58 ( NULL , L_10 ) ;
if ( ! V_30 ) {
F_44 ( L_14 ) ;
F_48 () ;
}
V_72 = F_52 ( V_30 , L_11 , NULL ) ;
if ( ! V_72 ) {
F_44 ( L_15 ) ;
F_48 () ;
}
V_1 = F_32 ( V_30 , L_3 , - 1 ) ;
if ( V_1 == - 1 ) {
F_44 ( L_16 ) ;
F_48 () ;
}
F_59 ( V_30 ) ;
V_71 . V_74 = V_72 [ 1 ] ;
V_71 . V_75 = V_72 [ 2 ] - 1 ;
V_71 . V_27 = V_72 [ 0 ] & 0xff ;
V_34 = F_60 ( & V_71 , V_76 ,
sizeof( struct V_77 ) , L_17 ) ;
if ( ! V_34 ) {
F_44 ( L_18 ) ;
F_48 () ;
}
#ifdef F_12
V_78 . V_79 = V_80 * 2 ;
#else
V_78 . V_79 = V_80 / V_81 ;
V_78 . V_82 |= V_83 ;
#endif
V_78 . V_82 |= V_84 ;
F_61 ( F_38 ( V_78 . V_79 ) ,
& V_34 -> V_35 ) ;
V_85 = & V_34 -> V_86 ;
V_15 = F_53 ( V_1 , V_87 ) ;
V_73 = F_62 ( V_15 , V_88 , V_89 , L_19 , NULL ) ;
if ( V_73 ) {
F_44 ( L_20 ,
V_73 ) ;
F_48 () ;
}
F_40 () ;
F_54 () ;
}
void T_1 F_63 ( void )
{
struct V_29 * V_30 ;
int V_90 ;
V_90 = V_91 ;
F_31 (dp, L_1 ) {
int V_31 = F_32 ( V_30 , L_2 , 0 ) ;
int V_1 = F_32 ( V_30 , L_3 , 0 ) ;
unsigned int V_9 ;
F_33 ( V_31 , V_90 << 3 ) ;
V_32 [ V_1 ] = V_90 ;
V_9 = F_5 ( V_31 , 0xffffffff ) ;
if ( V_9 ) {
F_34 ( V_33 L_21 ,
V_9 , V_1 ) ;
F_8 ( V_31 , V_9 ) ;
}
}
}
void T_1 F_64 ( void )
{
F_65 () ;
V_78 . V_92 = F_57 ;
V_78 . V_93 = F_51 ;
V_78 . V_94 = V_80 ;
V_78 . V_95 = F_35 ;
V_78 . V_96 = F_37 ;
}
