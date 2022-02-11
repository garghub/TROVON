static void T_1 F_1 ( void )
{
int V_1 ;
int V_2 ;
T_2 * V_3 = V_4 ;
#ifdef F_2
struct V_5 * V_6 = V_7 ;
struct V_8 * V_9 = V_10 ;
#endif
F_3 ( & V_3 , V_11 , V_12 ) ;
F_4 ( & V_3 , V_11 , V_13 ) ;
#ifdef F_2
F_5 ( & V_3 , & V_9 , V_11 , F_6 ( V_14 ) , V_15 ) ;
#endif
F_7 ( & V_3 , V_11 , V_11 , V_16 | V_17 | V_18 ) ;
F_8 ( & V_3 , V_11 , V_13 ) ;
#ifdef F_2
F_4 ( & V_3 , V_11 , V_19 ) ;
F_9 ( & V_3 , V_11 , V_11 , 0xf ) ;
F_10 ( & V_3 , V_11 , V_11 , 3 + 16 ) ;
F_7 ( & V_3 , V_11 , V_11 , 0x8001 ) ;
F_10 ( & V_3 , V_11 , V_11 , 16 ) ;
F_7 ( & V_3 , V_11 , V_11 , 0x0700 ) ;
F_11 ( & V_3 , V_11 , V_11 , 32 ) ;
F_12 ( & V_3 , V_11 , 0x500 , V_11 ) ;
F_5 ( & V_3 , & V_9 , V_11 , 1 , V_15 ) ;
F_13 ( & V_3 ) ;
#endif
F_14 ( & V_3 , 1 , 0 , 0 ) ;
F_15 ( & V_3 , V_11 , V_20 ) ;
F_16 ( & V_3 , V_11 , 0 , 0 , 6 ) ;
F_7 ( & V_3 , V_11 , V_11 , 0x1c0 | 54 ) ;
F_3 ( & V_3 , V_11 , V_20 ) ;
F_17 ( & V_3 , V_11 , ( long ) V_21 ) ;
F_18 ( & V_3 , V_11 ) ;
F_15 ( & V_3 , V_11 , V_12 ) ;
#ifdef F_2
F_19 ( & V_6 , V_3 , V_15 ) ;
F_17 ( & V_3 , V_11 , ( long ) V_22 ) ;
F_18 ( & V_3 , V_11 ) ;
F_15 ( & V_3 , V_11 , V_12 ) ;
#endif
F_20 ( V_10 , V_7 ) ;
V_2 = ( int ) ( V_3 - V_4 ) ;
F_21 ( L_1 , V_2 ) ;
F_21 ( L_2 ) ;
F_21 ( L_3 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_21 ( L_4 , V_4 [ V_1 ] ) ;
F_21 ( L_5 ) ;
if ( V_2 > 32 )
F_22 ( L_6 , V_2 ) ;
}
static int F_23 ( int V_23 )
{
#ifdef F_24
return F_25 ( V_23 ) ;
#else
return F_26 () ;
#endif
}
static int F_27 ( int V_24 )
{
#ifdef F_24
return F_28 ( V_24 ) ;
#else
return 0 ;
#endif
}
static T_3 F_29 ( int V_25 , void * V_26 )
{
unsigned int V_27 = F_26 () ;
int V_23 = F_27 ( V_27 ) ;
if ( V_28 ) {
if ( V_29 [ V_23 ] > 0 ) {
F_30 ( F_31 ( V_27 ) , 1 ) ;
V_29 [ V_23 ] -- ;
} else {
F_32 ( V_25 ) ;
F_33 ( V_23 , & V_30 ) ;
}
} else {
F_30 ( F_31 ( V_27 ) , 1 ) ;
}
return V_31 ;
}
static void F_34 ( const char * V_32 )
{
while ( * V_32 )
F_35 ( * V_32 ++ ) ;
}
static void F_36 ( T_4 V_33 , int V_34 )
{
int V_35 ;
int V_36 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
V_36 = ( V_33 >> ( ( V_34 - V_35 - 1 ) * 4 ) ) & 0xf ;
if ( V_36 >= 10 )
F_35 ( 'a' + V_36 - 10 ) ;
else
F_35 ( '0' + V_36 ) ;
}
}
void F_37 ( T_4 V_37 [ 32 ] )
{
T_4 V_1 ;
unsigned int V_24 = F_26 () ;
T_4 V_38 = F_38 () ;
T_4 V_39 = F_39 () ;
T_4 V_40 = F_40 () ;
T_4 V_41 = F_41 () ;
F_42 ( 100000000ull * V_24 ) ;
F_34 ( L_7 ) ;
F_36 ( V_24 , 1 ) ;
F_34 ( L_8 ) ;
for ( V_1 = 0 ; V_1 < 32 ; V_1 ++ ) {
F_34 ( L_9 ) ;
F_34 ( V_42 [ V_1 ] ) ;
F_34 ( L_10 ) ;
F_36 ( V_37 [ V_1 ] , 16 ) ;
if ( V_1 & 1 )
F_34 ( L_11 ) ;
}
F_34 ( L_12 ) ;
F_36 ( V_40 , 16 ) ;
F_34 ( L_13 ) ;
F_36 ( V_41 , 16 ) ;
F_34 ( L_11 ) ;
F_34 ( L_14 ) ;
F_36 ( V_39 , 16 ) ;
F_34 ( L_15 ) ;
F_36 ( V_38 , 16 ) ;
F_34 ( L_11 ) ;
F_34 ( L_16 ) ;
F_36 ( F_43 ( F_44 ( V_24 * 2 ) ) , 16 ) ;
F_34 ( L_17 ) ;
F_36 ( F_43 ( F_45 ( V_24 * 2 ) ) , 16 ) ;
F_34 ( L_11 ) ;
F_34 ( L_18 ) ;
}
static void F_46 ( int V_23 )
{
unsigned int V_27 ;
unsigned int V_43 ;
union V_44 V_45 ;
V_27 = F_23 ( V_23 ) ;
V_43 = V_46 + V_27 ;
F_30 ( F_31 ( V_27 ) , 1 ) ;
V_45 . T_4 = 0 ;
F_30 ( F_47 ( V_27 ) , V_45 . T_4 ) ;
F_48 ( V_43 , F_29 ) ;
}
static void F_49 ( int V_23 )
{
unsigned int V_27 ;
unsigned int V_43 ;
union V_44 V_45 ;
V_27 = F_23 ( V_23 ) ;
V_45 . T_4 = 0 ;
F_30 ( F_47 ( V_27 ) , V_45 . T_4 ) ;
V_29 [ V_23 ] = V_47 ;
V_43 = V_46 + V_27 ;
if ( F_50 ( V_43 , F_29 ,
V_48 , L_19 , F_29 ) )
F_22 ( L_20 , V_43 ) ;
F_51 ( V_23 , & V_30 ) ;
F_30 ( F_31 ( V_27 ) , 1 ) ;
V_45 . T_4 = 0 ;
V_45 . V_49 . V_2 = V_50 ;
V_45 . V_49 . V_51 = 3 ;
F_30 ( F_47 ( V_27 ) , V_45 . T_4 ) ;
}
static int F_52 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
unsigned int V_23 = ( unsigned long ) V_55 ;
switch ( V_54 ) {
case V_56 :
F_46 ( V_23 ) ;
break;
case V_57 :
case V_58 :
F_49 ( V_23 ) ;
break;
default:
break;
}
return V_59 ;
}
static void F_53 ( void )
{
int V_23 ;
int V_24 ;
F_54 (cpu) {
V_24 = F_23 ( V_23 ) ;
F_30 ( F_31 ( V_24 ) , 1 ) ;
V_29 [ V_23 ] = V_47 ;
if ( ( V_47 || ! V_28 ) &&
! F_55 ( V_23 , & V_30 ) ) {
int V_43 = V_46 + V_24 ;
F_56 ( V_43 ) ;
F_51 ( V_23 , & V_30 ) ;
}
}
}
static void F_57 ( int V_60 )
{
unsigned int V_61 ;
V_62 = V_63 ;
while ( ( V_60 % V_62 ) != 0 )
V_62 -- ;
V_61 = V_60 / V_62 ;
V_47 = V_61 > 2 ? V_61 - 2 : 0 ;
V_64 = V_60 ;
V_50 = ( ( F_58 () >> 8 ) * V_62 ) >> 8 ;
}
static int F_59 ( int V_60 )
{
int V_23 ;
int V_24 ;
union V_44 V_45 ;
if ( V_60 <= 0 )
return - 1 ;
F_57 ( V_60 ) ;
F_54 (cpu) {
V_24 = F_23 ( V_23 ) ;
F_30 ( F_31 ( V_24 ) , 1 ) ;
V_45 . T_4 = 0 ;
V_45 . V_49 . V_2 = V_50 ;
V_45 . V_49 . V_51 = 3 ;
F_30 ( F_47 ( V_24 ) , V_45 . T_4 ) ;
F_30 ( F_31 ( V_24 ) , 1 ) ;
}
F_53 () ;
return 0 ;
}
static T_5 F_60 ( struct V_65 * V_65 , const char T_6 * V_66 ,
T_7 V_67 , T_8 * V_68 )
{
if ( V_67 ) {
if ( ! V_69 ) {
T_7 V_1 ;
V_70 = 0 ;
for ( V_1 = 0 ; V_1 != V_67 ; V_1 ++ ) {
char V_71 ;
if ( F_61 ( V_71 , V_66 + V_1 ) )
return - V_72 ;
if ( V_71 == 'V' )
V_70 = 1 ;
}
}
F_53 () ;
}
return V_67 ;
}
static long F_62 ( struct V_65 * V_65 , unsigned int V_73 ,
unsigned long V_74 )
{
void T_6 * V_75 = ( void T_6 * ) V_74 ;
int T_6 * V_3 = V_75 ;
int V_76 ;
static struct V_77 V_78 = {
. V_79 = V_80 |
V_81 |
V_82 ,
. V_83 = 1 ,
. V_84 = L_21 ,
} ;
switch ( V_73 ) {
case V_85 :
return F_63 ( V_75 , & V_78 , sizeof( V_78 ) ) ? - V_72 : 0 ;
case V_86 :
case V_87 :
return F_64 ( 0 , V_3 ) ;
case V_88 :
F_53 () ;
return 0 ;
case V_89 :
if ( F_61 ( V_76 , V_3 ) )
return - V_72 ;
if ( F_59 ( V_76 ) )
return - V_90 ;
case V_91 :
return F_64 ( V_64 , V_3 ) ;
default:
return - V_92 ;
}
}
static int F_65 ( struct V_93 * V_93 , struct V_65 * V_65 )
{
if ( F_66 ( 0 , & V_94 ) )
return - V_95 ;
F_53 () ;
V_28 = 1 ;
return F_67 ( V_93 , V_65 ) ;
}
static int F_68 ( struct V_93 * V_93 , struct V_65 * V_65 )
{
if ( V_70 ) {
V_28 = 0 ;
F_53 () ;
} else {
F_69 ( L_22 ) ;
}
F_70 ( 0 , & V_94 ) ;
V_70 = 0 ;
return 0 ;
}
static int T_1 F_71 ( void )
{
int V_1 ;
int V_96 ;
int V_23 ;
T_4 * V_97 ;
V_63 = 6 ;
do {
V_63 -- ;
V_50 = ( ( F_58 () >> 8 ) * V_63 ) >> 8 ;
} while ( V_50 > 65535 );
F_72 ( V_50 == 0 ) ;
F_57 ( V_64 ) ;
F_73 ( L_23 , V_62 ) ;
V_96 = F_74 ( & V_98 ) ;
if ( V_96 ) {
F_75 ( L_24 ,
V_99 , V_96 ) ;
goto V_100;
}
F_1 () ;
V_97 = ( T_4 * ) V_4 ;
for ( V_1 = 0 ; V_1 < 16 ; V_1 ++ ) {
F_30 ( V_101 , V_1 * 8 ) ;
F_30 ( V_102 , V_97 [ V_1 ] ) ;
}
F_30 ( F_76 ( 0 ) , 0x81fc0000 ) ;
F_77 ( & V_30 ) ;
F_54 (cpu)
F_49 ( V_23 ) ;
F_78 ( & V_103 ) ;
V_100:
return V_96 ;
}
static void T_9 F_79 ( void )
{
int V_23 ;
F_80 ( & V_98 ) ;
F_81 ( & V_103 ) ;
F_54 (cpu) {
int V_27 = F_23 ( V_23 ) ;
F_30 ( F_47 ( V_27 ) , 0 ) ;
F_48 ( V_46 + V_27 , F_29 ) ;
}
F_30 ( F_76 ( 0 ) , 0 ) ;
}
