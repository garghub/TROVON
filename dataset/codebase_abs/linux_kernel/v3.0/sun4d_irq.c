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
static void F_29 ( int V_29 , int V_30 )
{
F_30 ( V_29 , V_30 ) ;
}
static void F_31 ( int V_29 , int V_30 )
{
}
static void F_32 ( int V_29 )
{
}
void T_1 F_33 ( void )
{
struct V_31 * V_32 ;
int V_26 = F_34 ( 1 ) ;
if ( V_26 == - 1 )
V_26 = F_34 ( 0 ) ;
F_35 (dp, L_1 ) {
int V_33 = F_36 ( V_32 , L_2 , 0 ) ;
int V_1 = F_36 ( V_32 , L_3 , 0 ) ;
V_34 [ V_1 ] = V_26 ;
F_37 ( V_33 , V_26 << 3 ) ;
}
F_38 ( V_35 L_4 , V_26 ) ;
}
static void F_39 ( void )
{
F_40 ( & V_36 -> V_37 ) ;
}
static void F_41 ( int V_29 , unsigned int V_38 )
{
F_42 ( V_29 , V_38 ) ;
}
static void T_1 F_43 ( void )
{
int V_29 = 0 , V_39 ;
while ( ! F_44 ( V_29 , NULL , & V_39 ) ) {
F_41 ( V_39 >> 3 , 0 ) ;
V_29 ++ ;
}
}
unsigned int F_45 ( unsigned int V_25 ,
unsigned int V_10 ,
unsigned int V_1 )
{
struct V_23 * V_24 ;
unsigned int V_15 ;
V_15 = F_46 ( V_25 , V_10 ) ;
if ( V_15 == 0 ) {
F_47 ( L_5 ,
V_25 , V_10 , V_1 ) ;
goto V_40;
}
V_24 = F_48 ( V_15 ) ;
if ( F_49 ( V_24 ) )
goto V_40;
V_24 = F_50 ( sizeof( struct V_23 ) , V_41 ) ;
if ( F_49 ( ! V_24 ) ) {
F_47 ( L_6 ) ;
F_51 () ;
}
V_24 -> V_26 = V_34 [ V_1 ] ;
V_24 -> V_25 = V_25 ;
F_52 ( V_15 , & V_42 ,
V_43 , L_7 ) ;
F_53 ( V_15 , V_24 ) ;
V_40:
return V_15 ;
}
unsigned int F_54 ( struct V_44 * V_45 ,
unsigned int V_25 )
{
struct V_31 * V_32 = V_45 -> V_46 . V_47 ;
struct V_31 * V_48 , * V_49 = V_32 -> V_50 ;
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
V_17 = F_55 ( V_32 , L_11 , NULL ) ;
if ( ! V_17 )
goto V_40;
V_3 = V_17 -> V_54 ;
if ( ! V_49 -> V_50 || strcmp ( V_49 -> V_50 -> V_53 , V_51 ) ) {
F_38 ( V_35 L_12 ,
V_49 -> V_55 , V_51 ) ;
goto V_40;
}
V_48 = V_49 -> V_50 ;
V_1 = F_36 ( V_48 , L_3 , - 1 ) ;
if ( V_1 == - 1 ) {
F_38 ( V_35 L_13 ,
V_48 -> V_55 ) ;
goto V_40;
}
V_4 = V_19 [ V_25 ] ;
if ( V_4 )
V_10 = F_1 ( V_1 , V_4 , V_3 ) ;
else
V_10 = V_25 ;
V_15 = F_45 ( V_25 , V_10 , V_1 ) ;
V_40:
return V_15 ;
}
unsigned int F_56 ( unsigned int V_1 , unsigned int V_25 )
{
return F_45 ( V_25 , V_25 , V_1 ) ;
}
static void T_1 F_57 ( void )
{
#ifdef F_12
unsigned long V_27 ;
struct V_56 * V_57 = & V_58 [ V_59 + ( 14 - 1 ) ] ;
V_60 [ 2 ] += V_61 - V_62 ;
F_58 ( V_27 ) ;
V_63 [ 0 ] = 0x01000000 ;
V_57 -> V_64 = V_60 [ 0 ] ;
V_57 -> V_65 = V_60 [ 1 ] ;
V_57 -> V_66 = V_60 [ 2 ] ;
V_57 -> V_67 = V_60 [ 3 ] ;
F_59 () ;
F_60 ( V_27 ) ;
#endif
}
static void T_1 F_61 ( T_2 V_68 )
{
struct V_31 * V_32 ;
struct V_69 V_70 ;
unsigned int V_15 ;
const T_3 * V_71 ;
int V_72 ;
int V_1 ;
V_32 = F_62 ( NULL , L_10 ) ;
if ( ! V_32 ) {
F_47 ( L_14 ) ;
F_51 () ;
}
V_71 = F_55 ( V_32 , L_11 , NULL ) ;
if ( ! V_71 ) {
F_47 ( L_15 ) ;
F_51 () ;
}
V_1 = F_36 ( V_32 , L_3 , - 1 ) ;
if ( V_1 == - 1 ) {
F_47 ( L_16 ) ;
F_51 () ;
}
F_63 ( V_32 ) ;
V_70 . V_73 = V_71 [ 1 ] ;
V_70 . V_74 = V_71 [ 2 ] - 1 ;
V_70 . V_27 = V_71 [ 0 ] & 0xff ;
V_36 = F_64 ( & V_70 , V_75 ,
sizeof( struct V_76 ) , L_17 ) ;
if ( ! V_36 ) {
F_47 ( L_18 ) ;
F_51 () ;
}
F_65 ( ( ( ( 1000000 / V_77 ) + 1 ) << 10 ) , & V_36 -> V_37 ) ;
V_78 = & V_36 -> V_79 ;
V_15 = F_56 ( V_1 , V_80 ) ;
V_72 = F_66 ( V_15 , V_68 , V_81 , L_19 , NULL ) ;
if ( V_72 ) {
F_47 ( L_20 ,
V_72 ) ;
F_51 () ;
}
F_43 () ;
F_57 () ;
}
void T_1 F_67 ( void )
{
struct V_31 * V_32 ;
int V_82 ;
V_82 = V_83 ;
F_35 (dp, L_1 ) {
int V_33 = F_36 ( V_32 , L_2 , 0 ) ;
int V_1 = F_36 ( V_32 , L_3 , 0 ) ;
unsigned int V_9 ;
F_37 ( V_33 , V_82 << 3 ) ;
V_34 [ V_1 ] = V_82 ;
V_9 = F_5 ( V_33 , 0xffffffff ) ;
if ( V_9 ) {
F_38 ( V_35 L_21 ,
V_9 , V_1 ) ;
F_8 ( V_33 , V_9 ) ;
}
}
}
void T_1 F_68 ( void )
{
F_69 () ;
F_70 ( V_84 , F_39 , V_85 ) ;
F_70 ( V_86 , F_41 , V_85 ) ;
V_87 . V_88 = F_61 ;
V_87 . V_89 = F_54 ;
#ifdef F_12
F_70 ( V_90 , F_29 , V_85 ) ;
F_70 ( V_91 , F_31 , V_92 ) ;
F_70 ( V_93 , F_32 , V_92 ) ;
#endif
}
