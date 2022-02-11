static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = V_2 -> V_4 ;
return 1 ;
}
static int F_2 ( void * V_5 , bool V_6 )
{
struct V_7 * V_8 ;
int V_9 = V_6 ? 1 : 0 ;
unsigned long V_10 = ( unsigned long ) V_5 ;
int V_11 = ( unsigned long ) V_5 - 1 ;
int V_12 ;
int V_13 ;
int V_14 ;
V_8 = F_3 () ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_13 = V_8 -> V_15 [ 1 ] ;
if ( V_14 != 0 )
goto V_16;
F_5 () ;
V_8 -> V_17 [ 0 ] = 0x2 ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_12 = V_8 -> V_15 [ 1 ] ;
if ( V_14 == 0 && ( V_12 & F_6 ( V_11 ) ) &&
( V_13 & F_6 ( 0 ) ) && ! ( V_13 & F_6 ( 16 ) ) )
V_9 = 1 ;
F_5 () ;
V_8 -> V_17 [ 0 ] = ( 1 | ( V_10 << 8 ) | ( V_9 << 16 ) ) ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_16:
F_7 () ;
return F_8 ( V_14 ) ;
}
static void F_9 ( struct V_18 * V_18 , int V_10 ,
int V_13 ,
struct V_7 * V_8 )
{
if ( V_13 & F_6 ( 0 ) ) {
int V_19 = F_10 ( V_18 ) ;
F_5 () ;
V_8 -> V_17 [ 0 ] = ( 1 | ( V_10 << 8 ) | ( V_19 << 16 ) ) ;
F_4 ( 17 , 11 ) ;
} else {
F_11 ( V_18 , ! ! ( V_13 & F_6 ( V_10 + 16 ) ) ) ;
}
}
static void F_12 ( struct V_18 * V_18 , int V_10 ,
int V_13 , int V_12 )
{
if ( V_12 & ( F_6 ( V_10 - 1 ) ) )
F_13 ( V_18 , ! ( V_13 & F_6 ( 16 ) ) ) ;
}
static void F_14 ( struct V_18 * V_18 , void * V_5 )
{
struct V_7 * V_8 ;
int V_10 = ( ( unsigned long ) V_5 & 0xF ) ;
int V_12 ;
int V_13 ;
int V_14 ;
V_8 = F_3 () ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_13 = V_8 -> V_15 [ 1 ] ;
if ( V_14 != 0 || ! ( V_13 & F_6 ( 0 ) ) ) {
F_7 () ;
return;
}
F_5 () ;
V_8 -> V_17 [ 0 ] = 0x2 ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_12 = V_8 -> V_15 [ 1 ] ;
F_7 () ;
if ( V_14 != 0 )
return;
F_12 ( V_18 , V_10 , V_13 , V_12 ) ;
}
static int F_15 ( struct V_20 * V_21 , void * V_5 )
{
struct V_7 * V_8 ;
int V_22 ;
int V_23 ;
int V_13 ;
int V_14 ;
V_8 = F_3 () ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_13 = V_8 -> V_15 [ 1 ] ;
F_5 () ;
V_8 -> V_17 [ 0 ] = 0x2 ;
F_4 ( 17 , 11 ) ;
V_23 = V_8 -> V_15 [ 0 ] ;
V_22 = V_8 -> V_15 [ 1 ] ;
F_7 () ;
F_16 ( V_21 , L_1 , V_14 ) ;
F_16 ( V_21 , L_2 , V_13 ) ;
F_16 ( V_21 , L_3 ,
V_13 & F_6 ( 0 ) ) ;
F_16 ( V_21 , L_4 ,
( V_13 & F_6 ( 1 ) ) >> 1 ) ;
F_16 ( V_21 , L_5 ,
( V_13 & F_6 ( 2 ) ) >> 2 ) ;
F_16 ( V_21 , L_6 ,
( V_13 & F_6 ( 3 ) ) >> 3 ) ;
F_16 ( V_21 , L_7 ,
( V_13 & F_6 ( 4 ) ) >> 4 ) ;
F_16 ( V_21 , L_8 ,
( V_13 & F_6 ( 5 ) ) >> 5 ) ;
F_16 ( V_21 , L_9 ,
( V_13 & F_6 ( 6 ) ) >> 6 ) ;
F_16 ( V_21 , L_10 ,
( V_13 & F_6 ( 7 ) ) >> 7 ) ;
F_16 ( V_21 , L_11 ,
( V_13 & F_6 ( 8 ) ) >> 8 ) ;
F_16 ( V_21 , L_12 ,
( V_13 & F_6 ( 9 ) ) >> 9 ) ;
F_16 ( V_21 , L_13 ,
( V_13 & F_6 ( 10 ) ) >> 10 ) ;
F_16 ( V_21 , L_14 ,
( V_13 & F_6 ( 11 ) ) >> 11 ) ;
F_16 ( V_21 , L_15 ,
( V_13 & F_6 ( 12 ) ) >> 12 ) ;
F_16 ( V_21 , L_16 ,
( V_13 & F_6 ( 16 ) ) >> 16 ) ;
F_16 ( V_21 , L_17 ,
( V_13 & F_6 ( 17 ) ) >> 17 ) ;
F_16 ( V_21 , L_18 ,
( V_13 & F_6 ( 18 ) ) >> 18 ) ;
F_16 ( V_21 , L_19 ,
( V_13 & F_6 ( 19 ) ) >> 19 ) ;
F_16 ( V_21 , L_20 ,
( V_13 & F_6 ( 20 ) ) >> 20 ) ;
F_16 ( V_21 , L_21 ,
( V_13 & F_6 ( 21 ) ) >> 21 ) ;
F_16 ( V_21 , L_22 , V_23 ) ;
F_16 ( V_21 , L_23 , V_22 ) ;
F_16 ( V_21 , L_24 ,
V_22 & F_6 ( 0 ) ) ;
F_16 ( V_21 , L_25 ,
( V_22 & F_6 ( 1 ) ) >> 1 ) ;
F_16 ( V_21 , L_26 ,
( V_22 & F_6 ( 2 ) ) >> 2 ) ;
F_16 ( V_21 , L_27 ,
( V_22 & F_6 ( 3 ) ) >> 3 ) ;
F_16 ( V_21 , L_28 ,
( V_22 & F_6 ( 4 ) ) >> 4 ) ;
F_16 ( V_21 , L_29 ,
( V_22 & F_6 ( 7 ) ) >> 7 ) ;
F_16 ( V_21 , L_30 ,
( V_22 & F_6 ( 8 ) ) >> 8 ) ;
F_16 ( V_21 , L_31 ,
( V_22 & F_6 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_17 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
return F_18 ( V_25 , F_15 , V_24 -> V_26 ) ;
}
static void F_19 ( struct V_27 * V_28 )
{
struct V_7 * V_8 ;
int V_12 = 0 ;
int V_13 ;
int V_14 ;
V_8 = F_3 () ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_13 = V_8 -> V_15 [ 1 ] ;
if ( V_14 != 0 )
goto V_16;
F_5 () ;
V_8 -> V_17 [ 0 ] = 0x2 ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
if ( V_14 == 0 && ( V_13 & F_6 ( 0 ) ) )
V_12 = V_8 -> V_15 [ 1 ] ;
if ( V_29 ) {
F_12 ( V_29 , 1 , V_13 , V_12 ) ;
F_9 ( V_29 , 1 , V_13 , V_8 ) ;
}
if ( V_30 ) {
F_12 ( V_30 , 2 , V_13 ,
V_12 ) ;
F_9 ( V_30 , 2 , V_13 ,
V_8 ) ;
}
if ( V_31 ) {
F_12 ( V_31 , 3 , V_13 , V_12 ) ;
F_9 ( V_31 , 3 , V_13 , V_8 ) ;
}
V_16:
F_7 () ;
}
static bool F_20 ( unsigned char V_5 , unsigned char V_32 ,
struct V_33 * V_34 )
{
static bool V_35 ;
if ( V_32 & V_36 )
return false ;
if ( F_21 ( V_5 == 0xe0 ) ) {
V_35 = true ;
return false ;
} else if ( F_21 ( V_35 ) ) {
switch ( V_5 ) {
case 0x8 :
F_22 ( & V_37 ,
F_23 ( V_38 / 4 ) ) ;
break;
}
V_35 = false ;
}
return false ;
}
static int F_24 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_5 )
{
F_22 ( & V_37 , 0 ) ;
return V_42 ;
}
static int T_1 F_25 ( void )
{
struct V_7 * V_8 ;
int V_13 , V_14 , V_43 ;
const char * V_44 ;
V_43 = 0 ;
V_44 = F_26 ( V_45 ) ;
if ( V_44 && ( strncmp ( V_44 , L_32 , 8 ) == 0 ||
strncmp ( V_44 , L_33 , 9 ) == 0 ) )
V_43 = 1 ;
if ( ! V_46 && ! V_43 )
return 0 ;
V_8 = F_3 () ;
F_4 ( 17 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_13 = V_8 -> V_15 [ 1 ] ;
F_7 () ;
if ( V_14 != 0 )
return 0 ;
if ( ! ( V_13 & F_6 ( 0 ) ) && ! V_46 )
return 0 ;
if ( ( V_13 & ( 1 << 2 | 1 << 8 ) ) == ( 1 << 2 | 1 << 8 ) ) {
V_29 = F_27 ( L_34 , & V_47 -> V_48 ,
V_49 ,
& V_50 , ( void * ) 1 ) ;
if ( ! V_29 ) {
V_14 = - V_51 ;
goto V_52;
}
V_14 = F_28 ( V_29 ) ;
if ( V_14 )
goto V_52;
}
if ( ( V_13 & ( 1 << 3 | 1 << 9 ) ) == ( 1 << 3 | 1 << 9 ) ) {
V_30 = F_27 ( L_35 ,
& V_47 -> V_48 ,
V_53 ,
& V_50 , ( void * ) 2 ) ;
if ( ! V_30 ) {
V_14 = - V_51 ;
goto V_54;
}
V_14 = F_28 ( V_30 ) ;
if ( V_14 )
goto V_54;
}
if ( ( V_13 & ( 1 << 4 | 1 << 10 ) ) == ( 1 << 4 | 1 << 10 ) ) {
V_31 = F_27 ( L_36 ,
& V_47 -> V_48 ,
V_55 ,
& V_50 , ( void * ) 3 ) ;
if ( ! V_31 ) {
V_14 = - V_51 ;
goto V_56;
}
V_14 = F_28 ( V_31 ) ;
if ( V_14 )
goto V_56;
}
V_57 =
F_29 ( V_58 ) ;
if ( V_57 ) {
V_59 =
F_29 ( V_60 ) ;
if ( ! V_59 ) {
F_30 ( V_58 ) ;
V_57 = NULL ;
}
}
if ( V_57 ) {
V_14 = V_57 (
& V_61 ) ;
F_30 ( V_58 ) ;
V_57 = NULL ;
if ( V_14 != 0 ) {
F_30 ( V_60 ) ;
V_59 = NULL ;
}
} else {
F_31 ( L_37 ) ;
V_14 = - V_62 ;
}
if ( V_14 == 0 ) {
F_31 ( L_38 ) ;
} else if ( V_14 != - V_62 ) {
F_32 ( L_39 ) ;
goto V_63;
} else {
V_14 = F_33 ( F_20 ) ;
if ( V_14 ) {
F_32 ( L_40 ) ;
goto V_63;
}
F_31 ( L_41 ) ;
}
return 0 ;
V_63:
if ( V_31 )
F_34 ( V_31 ) ;
V_56:
F_35 ( V_31 ) ;
if ( V_30 )
F_34 ( V_30 ) ;
V_54:
F_35 ( V_30 ) ;
if ( V_29 )
F_34 ( V_29 ) ;
V_52:
F_35 ( V_29 ) ;
return V_14 ;
}
static void F_36 ( void )
{
if ( V_59 ) {
V_59 ( & V_61 ) ;
F_30 ( V_60 ) ;
V_59 = NULL ;
} else {
F_37 ( F_20 ) ;
}
F_38 ( & V_37 ) ;
if ( V_29 ) {
F_34 ( V_29 ) ;
F_35 ( V_29 ) ;
}
if ( V_30 ) {
F_34 ( V_30 ) ;
F_35 ( V_30 ) ;
}
if ( V_31 ) {
F_34 ( V_31 ) ;
F_35 ( V_31 ) ;
}
}
static int F_39 ( struct V_64 * V_65 )
{
struct V_7 * V_8 ;
struct V_66 * V_67 ;
int V_14 ;
V_67 = F_40 ( V_68 ) ;
if ( ! V_67 )
return - V_62 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = V_67 -> V_69 ;
V_8 -> V_17 [ 1 ] = V_65 -> V_70 . V_71 ;
if ( F_41 () > 0 )
F_4 ( 1 , 2 ) ;
else
F_4 ( 1 , 1 ) ;
V_14 = F_8 ( V_8 -> V_15 [ 0 ] ) ;
F_7 () ;
return V_14 ;
}
static int F_42 ( struct V_64 * V_65 )
{
struct V_7 * V_8 ;
struct V_66 * V_67 ;
int V_14 ;
V_67 = F_40 ( V_68 ) ;
if ( ! V_67 )
return - V_62 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = V_67 -> V_69 ;
if ( F_41 () > 0 )
F_4 ( 0 , 2 ) ;
else
F_4 ( 0 , 1 ) ;
if ( V_8 -> V_15 [ 0 ] )
V_14 = F_8 ( V_8 -> V_15 [ 0 ] ) ;
else
V_14 = V_8 -> V_15 [ 1 ] ;
F_7 () ;
return V_14 ;
}
static void F_43 ( void )
{
int V_72 = 0x97 ;
char V_5 = 1 ;
F_44 ( & V_5 , V_72 | 1 << 12 ) ;
}
static void F_45 ( void )
{
int V_72 = 0x97 ;
char V_5 = 2 ;
F_44 ( & V_5 , V_72 | 1 << 12 ) ;
}
static void F_46 ( struct V_73 * V_74 ,
enum V_75 V_76 )
{
if ( V_76 > 0 )
F_43 () ;
else
F_45 () ;
}
static int T_1 F_47 ( struct V_77 * V_48 )
{
return F_48 ( V_48 , & V_78 ) ;
}
static void F_49 ( void )
{
F_50 ( & V_78 ) ;
}
static int F_51 ( struct V_79 * V_80 )
{
struct V_7 * V_8 ;
T_2 V_81 ;
int V_14 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = 0x0 ;
F_4 ( 4 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
if ( V_14 ) {
V_14 = F_8 ( V_14 ) ;
goto V_16;
}
V_80 -> V_82 = V_8 -> V_15 [ 1 ] & 0xFFFF ;
V_80 -> type = ( V_8 -> V_15 [ 1 ] >> 24 ) & 0xFF ;
V_80 -> V_83 = V_8 -> V_15 [ 2 ] & 0xFF ;
V_81 = ( V_8 -> V_15 [ 2 ] >> 8 ) & 0xFF ;
V_80 -> V_84 = ( V_8 -> V_15 [ 2 ] >> 16 ) & 0xFF ;
if ( V_81 & F_6 ( 0 ) )
V_80 -> V_85 = ( V_8 -> V_15 [ 3 ] >> 0 ) & 0xFF ;
if ( V_81 & F_6 ( 1 ) )
V_80 -> V_86 = ( V_8 -> V_15 [ 3 ] >> 8 ) & 0xFF ;
if ( V_81 & F_6 ( 2 ) )
V_80 -> V_87 = ( V_8 -> V_15 [ 3 ] >> 16 ) & 0xFF ;
if ( V_81 & F_6 ( 3 ) )
V_80 -> V_88 = ( V_8 -> V_15 [ 3 ] >> 24 ) & 0xFF ;
V_16:
F_7 () ;
return V_14 ;
}
static unsigned int F_52 ( void )
{
if ( V_79 . V_84 != 0 )
return V_79 . V_84 ;
if ( V_89 > 0 )
return V_89 - 1 ;
return 0 ;
}
static int F_53 ( struct V_90 * V_91 )
{
int V_92 ;
if ( V_79 . V_84 != 0 )
return V_91 -> V_93 ;
if ( V_89 > 0 ) {
for ( V_92 = 0 ; V_92 < V_89 ; ++ V_92 )
if ( V_94 [ V_92 ] == V_91 -> V_95 )
return V_92 ;
return 0 ;
}
return - V_96 ;
}
static int F_54 ( struct V_90 * V_91 , T_2 V_93 )
{
if ( V_79 . V_84 != 0 ) {
if ( V_93 != 0 )
V_97 = V_93 ;
if ( V_91 -> V_93 == V_93 )
return 0 ;
V_91 -> V_93 = V_93 ;
if ( V_93 != 0 && V_91 -> V_95 == V_98 )
V_91 -> V_95 = V_99 ;
else if ( V_93 == 0 && V_91 -> V_95 != V_98 ) {
V_99 = V_91 -> V_95 ;
V_91 -> V_95 = V_98 ;
}
return 0 ;
}
if ( V_89 > 0 && V_93 < V_89 ) {
if ( V_93 != 0 )
V_97 = V_93 ;
V_91 -> V_95 = V_94 [ V_93 ] ;
return 0 ;
}
return - V_96 ;
}
static int F_55 ( struct V_90 * V_91 )
{
struct V_7 * V_8 ;
int V_14 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = 0x1 ;
F_4 ( 4 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
if ( V_14 ) {
V_14 = F_8 ( V_14 ) ;
goto V_16;
}
V_91 -> V_95 = F_56 ( V_8 -> V_15 [ 1 ] & 0xFFFF ) ;
if ( V_91 -> V_95 != 0 )
V_91 -> V_95 -- ;
V_91 -> V_83 = ( V_8 -> V_15 [ 1 ] >> 16 ) & 0xFF ;
V_91 -> V_100 = ( V_8 -> V_15 [ 1 ] >> 24 ) & 0x3F ;
V_91 -> V_101 = ( V_8 -> V_15 [ 1 ] >> 30 ) & 0x3 ;
V_91 -> V_102 = V_8 -> V_15 [ 2 ] & 0xFF ;
V_91 -> V_103 = ( V_8 -> V_15 [ 2 ] >> 8 ) & 0xFF ;
V_91 -> V_93 = ( V_8 -> V_15 [ 2 ] >> 16 ) & 0xFF ;
V_16:
F_7 () ;
return V_14 ;
}
static int F_57 ( struct V_90 * V_91 )
{
struct V_7 * V_8 ;
int V_14 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = 0x2 ;
V_8 -> V_17 [ 1 ] = F_6 ( V_91 -> V_95 ) & 0xFFFF ;
V_8 -> V_17 [ 1 ] |= ( V_91 -> V_83 & 0xFF ) << 16 ;
V_8 -> V_17 [ 1 ] |= ( V_91 -> V_100 & 0x3F ) << 24 ;
V_8 -> V_17 [ 1 ] |= ( V_91 -> V_101 & 0x3 ) << 30 ;
V_8 -> V_17 [ 2 ] = V_91 -> V_102 & 0xFF ;
V_8 -> V_17 [ 2 ] |= ( V_91 -> V_93 & 0xFF ) << 16 ;
F_4 ( 4 , 11 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
F_7 () ;
return F_8 ( V_14 ) ;
}
static int F_58 ( struct V_90 * V_91 , struct V_90 * V_104 )
{
int V_14 ;
V_14 = F_57 ( V_91 ) ;
if ( V_14 == 0 )
return 0 ;
if ( F_57 ( V_104 ) )
F_59 ( L_42 ) ;
return V_14 ;
}
static int F_60 ( T_2 V_105 )
{
struct V_7 * V_8 ;
struct V_66 * V_67 ;
int V_14 ;
if ( V_105 >= F_61 ( V_106 ) )
return - V_96 ;
V_67 = F_40 ( V_106 [ V_105 ] ) ;
if ( ! V_67 )
return - V_96 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = V_67 -> V_69 ;
V_8 -> V_17 [ 1 ] = V_67 -> V_76 ;
F_4 ( 1 , 0 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
F_7 () ;
return F_8 ( V_14 ) ;
}
static int F_62 ( T_2 V_105 )
{
struct V_7 * V_8 ;
struct V_66 * V_67 ;
int V_14 ;
int V_107 ;
if ( V_105 >= F_61 ( V_106 ) )
return - V_96 ;
V_67 = F_40 ( V_106 [ V_105 ] ) ;
if ( ! V_67 )
return - V_96 ;
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = V_67 -> V_69 ;
F_4 ( 0 , 0 ) ;
V_14 = V_8 -> V_15 [ 0 ] ;
V_107 = V_8 -> V_15 [ 1 ] ;
F_7 () ;
if ( V_14 )
return F_8 ( V_14 ) ;
return ( V_107 == V_67 -> V_76 ) ;
}
static int F_63 ( void )
{
int V_92 ;
int V_14 ;
for ( V_92 = 0 ; V_92 < F_61 ( V_106 ) ; ++ V_92 ) {
V_14 = F_62 ( V_92 ) ;
if ( V_14 == 1 )
return V_92 ;
}
return V_14 ;
}
static int F_64 ( void )
{
return F_65 ( V_108 ) ;
}
static inline int F_66 ( void )
{
struct V_90 V_91 ;
int V_14 ;
int V_92 ;
V_14 = F_51 ( & V_79 ) ;
if ( V_14 )
return V_14 ;
F_55 ( & V_91 ) ;
if ( V_79 . V_85 > 63 )
V_79 . V_85 = 63 ;
if ( V_79 . V_86 > 63 )
V_79 . V_86 = 63 ;
if ( V_79 . V_87 > 63 )
V_79 . V_87 = 63 ;
if ( V_79 . V_88 > 63 )
V_79 . V_88 = 63 ;
V_79 . V_82 &= ~ F_6 ( V_109 ) ;
V_97 = F_53 ( & V_91 ) ;
V_99 = V_91 . V_95 ;
if ( V_97 == 0 && F_52 () != 0 )
V_97 = 1 ;
if ( V_99 == V_98 ) {
V_99 =
F_56 ( V_79 . V_82 & ~ F_6 ( V_98 ) ) ;
if ( V_99 != 0 )
V_99 -- ;
}
if ( V_79 . V_82 & ( F_6 ( V_110 ) |
F_6 ( V_111 ) ) )
V_112 = true ;
if ( V_79 . V_82 & (
F_6 ( V_111 ) | F_6 ( V_113 ) |
F_6 ( V_114 ) | F_6 ( V_115 ) |
F_6 ( V_116 ) | F_6 ( V_117 )
) )
V_118 = true ;
for ( V_92 = 0 ; V_92 < 16 ; ++ V_92 )
if ( F_67 ( V_92 ) && ( F_6 ( V_92 ) & V_79 . V_82 ) )
V_94 [ 1 + V_89 ++ ] = V_92 ;
if ( V_89 > 0 ) {
for ( V_92 = 0 ; V_92 < 16 ; ++ V_92 ) {
if ( F_6 ( V_92 ) & V_79 . V_82 ) {
V_94 [ 0 ] = V_92 ;
break;
}
}
V_89 ++ ;
}
return 0 ;
}
static inline void F_68 ( void )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < F_61 ( V_106 ) ; ++ V_92 )
if ( F_40 ( V_106 [ V_92 ] ) )
V_108 |= F_6 ( V_92 ) ;
}
static void F_69 ( void )
{
int V_14 ;
V_14 = F_66 () ;
F_68 () ;
if ( V_108 != 0 || V_14 == 0 )
V_119 = true ;
}
static T_3 F_70 ( struct V_77 * V_48 ,
struct V_120 * V_121 ,
const char * V_122 , T_4 V_123 )
{
struct V_90 V_124 ;
struct V_90 V_91 ;
bool V_125 ;
int V_76 ;
int V_14 ;
char V_126 ;
T_2 V_127 ;
int V_92 ;
V_14 = sscanf ( V_122 , L_43 , & V_76 , & V_126 ) ;
if ( V_14 < 1 )
return - V_96 ;
else if ( V_14 == 1 )
V_126 = 's' ;
if ( V_76 < 0 )
return - V_96 ;
V_125 = false ;
switch ( V_126 ) {
case 's' :
if ( V_76 > V_79 . V_85 )
V_125 = true ;
V_127 = V_128 ;
break;
case 'm' :
if ( V_76 > V_79 . V_86 )
V_125 = true ;
V_127 = V_129 ;
break;
case 'h' :
if ( V_76 > V_79 . V_87 )
V_125 = true ;
V_127 = V_130 ;
break;
case 'd' :
if ( V_76 > V_79 . V_88 )
V_125 = true ;
V_127 = V_131 ;
break;
default:
return - V_96 ;
}
if ( V_3 && V_3 -> V_132 )
V_125 = true ;
if ( V_125 ) {
switch ( V_127 ) {
case V_131 :
V_76 *= 24 ;
case V_130 :
V_76 *= 60 ;
case V_129 :
V_76 *= 60 ;
V_127 = V_128 ;
}
if ( V_3 && V_3 -> V_132 ) {
for ( V_92 = 0 ; V_3 -> V_133 [ V_92 ] != - 1 ; V_92 ++ ) {
if ( V_76 <= V_3 -> V_133 [ V_92 ] ) {
V_76 = V_3 -> V_133 [ V_92 ] ;
break;
}
}
}
if ( V_76 <= V_79 . V_85 && V_79 . V_85 ) {
V_127 = V_128 ;
} else if ( V_76 / 60 <= V_79 . V_86 && V_79 . V_86 ) {
V_76 /= 60 ;
V_127 = V_129 ;
} else if ( V_76 / ( 60 * 60 ) <= V_79 . V_87 && V_79 . V_87 ) {
V_76 /= ( 60 * 60 ) ;
V_127 = V_130 ;
} else if ( V_76 / ( 60 * 60 * 24 ) <= V_79 . V_88 && V_79 . V_88 ) {
V_76 /= ( 60 * 60 * 24 ) ;
V_127 = V_131 ;
} else {
return - V_96 ;
}
}
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
V_124 = V_91 ;
V_124 . V_100 = V_76 ;
V_124 . V_101 = V_127 ;
V_14 = F_58 ( & V_124 , & V_91 ) ;
if ( V_14 )
return V_14 ;
return V_123 ;
}
static T_3 F_71 ( struct V_77 * V_48 ,
struct V_120 * V_121 , char * V_122 )
{
struct V_90 V_91 ;
int V_14 ;
int V_134 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
V_134 = sprintf ( V_122 , L_44 , V_91 . V_100 ) ;
switch ( V_91 . V_101 ) {
case V_128 :
return V_134 + sprintf ( V_122 + V_134 , L_45 ) ;
case V_129 :
return V_134 + sprintf ( V_122 + V_134 , L_46 ) ;
case V_130 :
return V_134 + sprintf ( V_122 + V_134 , L_47 ) ;
case V_131 :
return V_134 + sprintf ( V_122 + V_134 , L_48 ) ;
default:
return - V_96 ;
}
return V_134 ;
}
static T_3 F_72 ( struct V_77 * V_48 ,
struct V_120 * V_121 ,
const char * V_122 , T_4 V_123 )
{
struct V_90 V_124 ;
struct V_90 V_91 ;
bool V_135 = false ;
int V_136 = - 1 ;
char V_137 [ 21 ] ;
int V_92 , V_14 ;
V_14 = sscanf ( V_122 , L_49 , V_137 ) ;
if ( V_14 != 1 )
return - V_96 ;
if ( V_137 [ 0 ] != '+' && V_137 [ 0 ] != '-' )
return - V_96 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
if ( V_118 )
V_135 = F_73 ( V_91 . V_95 ) ;
if ( V_118 ) {
for ( V_92 = 0 ; V_92 < F_61 ( V_138 ) ; ++ V_92 ) {
if ( ! ( V_79 . V_83 & F_6 ( V_92 ) ) )
continue;
if ( ! V_138 [ V_92 ] )
continue;
if ( strcmp ( V_137 + 1 , V_138 [ V_92 ] ) != 0 )
continue;
if ( V_137 [ 0 ] == '+' &&
V_135 && ( V_91 . V_83 & F_6 ( V_92 ) ) )
return V_123 ;
if ( V_137 [ 0 ] == '-' &&
( ! V_135 || ! ( V_91 . V_83 & F_6 ( V_92 ) ) ) )
return V_123 ;
V_136 = V_92 ;
break;
}
}
if ( V_136 != - 1 ) {
V_124 = V_91 ;
if ( V_137 [ 0 ] == '+' )
V_124 . V_83 |= F_6 ( V_136 ) ;
else {
V_124 . V_83 &= ~ F_6 ( V_136 ) ;
if ( V_136 == 1 )
V_124 . V_83 &= ~ F_6 ( 2 ) ;
}
if ( ( V_79 . V_83 & V_124 . V_83 ) !=
V_124 . V_83 )
return - V_96 ;
if ( V_124 . V_83 && ! V_135 ) {
V_124 . V_95 = V_113 ;
F_54 ( & V_124 , V_97 ) ;
} else if ( V_124 . V_83 == 0 ) {
F_54 ( & V_124 , 0 ) ;
}
if ( ! ( V_79 . V_82 & F_6 ( V_124 . V_95 ) ) )
return - V_96 ;
V_14 = F_58 ( & V_124 , & V_91 ) ;
if ( V_14 )
return V_14 ;
if ( V_124 . V_95 != V_98 )
V_99 = V_124 . V_95 ;
return V_123 ;
}
return - V_96 ;
}
static T_3 F_74 ( struct V_77 * V_48 ,
struct V_120 * V_121 , char * V_122 )
{
struct V_90 V_91 ;
bool V_135 ;
int V_93 , V_92 , V_14 ;
int V_134 = 0 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
V_134 = 0 ;
if ( V_118 ) {
V_135 = F_73 ( V_91 . V_95 ) ;
V_93 = F_53 ( & V_91 ) ;
for ( V_92 = 0 ; V_92 < F_61 ( V_138 ) ; ++ V_92 ) {
if ( ! ( V_79 . V_83 & F_6 ( V_92 ) ) )
continue;
if ( ! V_138 [ V_92 ] )
continue;
if ( ( V_135 || V_93 <= 0 ) &&
( V_91 . V_83 & F_6 ( V_92 ) ) )
V_122 [ V_134 ++ ] = '+' ;
else
V_122 [ V_134 ++ ] = '-' ;
V_134 += sprintf ( V_122 + V_134 , L_50 , V_138 [ V_92 ] ) ;
}
}
if ( V_134 )
V_122 [ V_134 - 1 ] = '\n' ;
return V_134 ;
}
static T_3 F_75 ( struct V_77 * V_48 ,
struct V_120 * V_121 ,
const char * V_122 , T_4 V_123 )
{
struct V_90 V_124 ;
struct V_90 V_91 ;
bool V_135 = false ;
int V_139 ;
int V_14 ;
V_14 = F_76 ( V_122 , 0 , & V_139 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
if ( V_139 == F_77 ( V_91 . V_95 ) )
return V_123 ;
V_124 = V_91 ;
if ( V_118 )
V_135 = F_73 ( V_91 . V_95 ) ;
if ( V_139 ) {
if ( V_135 )
V_124 . V_95 = V_111 ;
else
V_124 . V_95 = V_110 ;
} else {
if ( V_135 ) {
V_124 . V_95 = V_113 ;
F_54 ( & V_124 , V_97 ) ;
} else {
V_124 . V_95 = V_109 ;
}
}
if ( ! ( V_79 . V_82 & F_6 ( V_124 . V_95 ) ) )
return - V_96 ;
V_14 = F_58 ( & V_124 , & V_91 ) ;
if ( V_14 )
return V_14 ;
V_99 = V_124 . V_95 ;
return V_123 ;
}
static T_3 F_78 ( struct V_77 * V_48 ,
struct V_120 * V_121 ,
char * V_122 )
{
struct V_90 V_91 ;
bool V_140 = false ;
int V_14 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
V_140 = F_77 ( V_91 . V_95 ) ;
return sprintf ( V_122 , L_51 , V_140 ? 1 : 0 ) ;
}
static T_3 F_79 ( struct V_77 * V_48 ,
struct V_120 * V_121 ,
const char * V_122 , T_4 V_123 )
{
struct V_90 V_91 ;
struct V_90 V_124 ;
T_2 V_141 ;
int V_14 ;
V_14 = F_80 ( V_122 , 10 , & V_141 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
V_124 = V_91 ;
V_124 . V_102 = V_141 ;
V_14 = F_58 ( & V_124 , & V_91 ) ;
if ( V_14 )
return V_14 ;
return V_123 ;
}
static T_3 F_81 ( struct V_77 * V_48 ,
struct V_120 * V_121 ,
char * V_122 )
{
struct V_90 V_91 ;
int V_14 ;
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return V_14 ;
return sprintf ( V_122 , L_51 , V_91 . V_102 ) ;
}
static enum V_75 F_82 ( struct V_73 * V_74 )
{
int V_14 ;
T_5 V_142 ;
struct V_90 V_91 ;
if ( F_52 () ) {
V_14 = F_55 ( & V_91 ) ;
if ( V_14 )
return 0 ;
V_14 = F_53 ( & V_91 ) ;
if ( V_14 < 0 )
return 0 ;
return V_14 ;
}
if ( F_64 () ) {
V_14 = F_63 () ;
if ( V_14 < 0 )
return 0 ;
for ( V_142 = V_108 ; V_142 != 0 && V_14 > 0 ; -- V_14 )
V_142 &= V_142 - 1 ;
if ( V_142 == 0 )
return 0 ;
return F_56 ( V_142 ) - 1 ;
}
F_32 ( L_52 ) ;
return 0 ;
}
static void F_83 ( struct V_73 * V_74 ,
enum V_75 V_76 )
{
struct V_90 V_91 ;
struct V_90 V_124 ;
T_5 V_142 ;
if ( F_52 () ) {
if ( F_55 ( & V_91 ) )
return;
V_124 = V_91 ;
if ( F_54 ( & V_124 , V_76 ) )
return;
F_58 ( & V_124 , & V_91 ) ;
return;
}
if ( F_64 () ) {
for ( V_142 = V_108 ; V_142 != 0 && V_76 > 0 ; -- V_76 )
V_142 &= V_142 - 1 ;
if ( V_142 == 0 )
return;
F_60 ( F_56 ( V_142 ) - 1 ) ;
return;
}
F_32 ( L_52 ) ;
}
static int T_1 F_84 ( struct V_77 * V_48 )
{
F_69 () ;
if ( ! V_119 )
return - V_62 ;
if ( ! V_112 )
V_143 [ 1 ] = NULL ;
V_144 . V_145 = F_52 () ;
if ( ! V_144 . V_145 ) {
V_144 . V_145 = F_64 () ;
if ( V_144 . V_145 )
V_144 . V_145 -- ;
}
return F_48 ( V_48 , & V_144 ) ;
}
static void F_85 ( struct V_73 * V_74 ,
enum V_75 V_76 )
{
}
static void F_86 ( void )
{
if ( ! V_119 )
return;
V_144 . V_146 = F_85 ;
F_50 ( & V_144 ) ;
}
static int T_1 F_87 ( void )
{
struct V_7 * V_8 ;
struct V_66 * V_67 ;
int V_147 = 0 ;
int V_14 ;
if ( ! F_88 ( V_148 ) )
return - V_62 ;
V_3 = NULL ;
F_88 ( V_149 ) ;
V_14 = F_89 ( & V_150 ) ;
if ( V_14 )
goto V_151;
V_47 = F_90 ( L_53 , - 1 ) ;
if ( ! V_47 ) {
V_14 = - V_51 ;
goto V_152;
}
V_14 = F_91 ( V_47 ) ;
if ( V_14 )
goto V_153;
V_14 = F_25 () ;
if ( V_14 ) {
F_32 ( L_54 ) ;
goto V_154;
}
if ( V_3 && V_3 -> V_78 )
F_47 ( & V_47 -> V_48 ) ;
F_84 ( & V_47 -> V_48 ) ;
V_155 = F_92 ( L_55 , NULL ) ;
if ( V_155 != NULL )
F_93 ( L_56 , 0444 , V_155 , NULL ,
& V_156 ) ;
if ( F_94 () != V_157 )
return 0 ;
V_67 = F_40 ( V_68 ) ;
if ( V_67 ) {
V_8 = F_3 () ;
V_8 -> V_17 [ 0 ] = V_67 -> V_69 ;
F_4 ( 0 , 2 ) ;
if ( V_8 -> V_15 [ 0 ] == 0 )
V_147 = V_8 -> V_15 [ 3 ] ;
F_7 () ;
}
if ( V_147 ) {
struct V_158 V_70 ;
memset ( & V_70 , 0 , sizeof( struct V_158 ) ) ;
V_70 . type = V_159 ;
V_70 . V_145 = V_147 ;
V_160 = F_95 ( L_57 ,
& V_47 -> V_48 ,
NULL ,
& V_161 ,
& V_70 ) ;
if ( F_96 ( V_160 ) ) {
V_14 = F_97 ( V_160 ) ;
V_160 = NULL ;
goto V_162;
}
V_160 -> V_70 . V_71 =
F_42 ( V_160 ) ;
F_98 ( V_160 ) ;
}
return 0 ;
V_162:
F_36 () ;
V_154:
F_99 ( V_47 ) ;
V_153:
F_100 ( V_47 ) ;
V_152:
F_101 ( & V_150 ) ;
V_151:
return V_14 ;
}
static void T_6 F_102 ( void )
{
F_103 ( V_155 ) ;
if ( V_3 && V_3 -> V_78 )
F_49 () ;
F_86 () ;
F_104 ( V_160 ) ;
F_36 () ;
if ( V_47 ) {
F_105 ( V_47 ) ;
F_101 ( & V_150 ) ;
}
}
