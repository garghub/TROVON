static void F_1 ( void )
{
int V_1 ;
V_1 = 0 ;
while ( 1 ) {
if ( ! ( F_2 ( V_2 ) & 0x11 ) )
break;
V_1 ++ ;
if ( V_1 > 0x10000 ) {
F_3
( L_1 ) ;
break;
}
}
}
static void F_4 ( T_1 V_3 , T_1 V_4 , int V_5 )
{
int V_6 ;
unsigned long V_7 ;
if ( F_5 ( V_5 % 4 ) )
return;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
if ( ! ( V_6 % 8 ) )
F_1 () ;
F_6 ( V_7 ) ;
F_7 ( V_4 , V_3 + V_8 ) ;
F_8 ( V_7 ) ;
V_3 ++ ;
}
}
static void F_9 ( T_1 V_3 , void * V_9 , int V_5 )
{
unsigned long V_7 ;
T_1 * V_10 = V_9 ;
T_1 T_2 * V_11 = ( T_1 T_2 * ) ( V_8 + V_3 ) ;
int V_6 ;
T_1 V_12 ;
V_5 = F_10 ( V_5 , 4 ) ;
F_1 () ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
if ( ! ( V_6 % 8 ) )
F_1 () ;
V_12 = * V_10 ;
F_6 ( V_7 ) ;
F_7 ( V_12 , V_11 ) ;
F_8 ( V_7 ) ;
V_10 ++ ;
V_11 ++ ;
}
}
static void F_11 ( void )
{
int V_6 ;
unsigned long V_7 ;
T_1 V_13 ;
F_1 () ;
V_13 = F_2 ( V_14 ) ;
V_13 |= 1 ;
F_1 () ;
F_6 ( V_7 ) ;
F_7 ( V_13 , V_14 ) ;
F_8 ( V_7 ) ;
for ( V_6 = 0 ; V_6 < 64 ; V_6 ++ ) {
F_1 () ;
V_13 = F_2 ( V_15 + ( V_6 * 0x80 ) ) ;
V_13 = ( V_13 & ~ 0x4000 ) | 0x8000 ;
F_1 () ;
F_6 ( V_7 ) ;
F_7 ( V_13 , V_15 + ( V_6 * 0x80 ) ) ;
F_8 ( V_7 ) ;
}
}
static void F_12 ( void )
{
unsigned long V_7 ;
T_1 V_13 = F_2 ( V_14 ) ;
V_13 &= ~ 1 ;
F_1 () ;
F_6 ( V_7 ) ;
F_7 ( V_13 , V_14 ) ;
F_8 ( V_7 ) ;
}
static void F_13 ( void )
{
unsigned long V_7 ;
F_11 () ;
F_4 ( 0 , 0 , 0x200000 / 4 ) ;
F_6 ( V_7 ) ;
F_14 ( 0xea000002 , V_8 ) ;
F_8 ( V_7 ) ;
F_12 () ;
}
static void F_15 ( void )
{
unsigned long V_7 ;
F_1 () ;
F_6 ( V_7 ) ;
F_7 ( V_16 | V_17 , ( T_1 * ) V_18 ) ;
F_8 ( V_7 ) ;
}
static void F_16 ( void )
{
unsigned long V_7 ;
F_1 () ;
F_6 ( V_7 ) ;
F_7 ( V_16 | V_19 , ( T_1 * ) V_18 ) ;
F_8 ( V_7 ) ;
}
static int F_17 ( int V_20 , int V_21 ,
struct V_22 * V_23 )
{
int V_24 , V_25 , V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
unsigned long V_7 ;
V_25 = 0 ;
V_28 = V_23 -> V_31 -> V_32 ;
V_26 = V_28 -> V_33 ;
V_26 %= ( V_34 / V_20 ) ;
V_30 = V_23 -> V_30 ;
for ( V_24 = 0 ; V_24 < V_20 ; V_24 ++ ) {
F_6 ( V_7 ) ;
V_25 = F_18 ( V_35 ,
( unsigned long ) ( V_30 -> V_36 +
( V_37 * V_24 ) /
V_20 +
V_38 *
V_26 ) ,
V_39 + V_24 * V_40 +
V_38 * V_26 ,
V_21 / V_20 , V_41 ) ;
if ( F_19 ( V_25 < 0 ) ) {
F_8 ( V_7 ) ;
break;
}
F_20 ( V_35 ) ;
F_8 ( V_7 ) ;
}
return V_25 ;
}
static void F_21 ( struct V_27 * V_28 )
{
F_9 ( V_42 ,
V_28 -> V_43 , sizeof( struct V_44 ) ) ;
F_15 () ;
}
static void F_22 ( struct V_45 * V_46 )
{
int V_21 ;
struct V_29 * V_30 ;
struct V_27 * V_28 ;
V_28 =
F_23 ( V_46 , struct V_27 , V_47 ) ;
V_30 = V_28 -> V_23 -> V_30 ;
if ( F_19 ( V_28 -> V_48 == 0 ) ) {
V_21 =
F_24 ( V_30 , V_30 -> V_21 ) ;
if ( V_30 -> V_20 > 1 )
V_28 -> V_43 -> V_7 |= 0x01 ;
F_17 ( V_30 -> V_20 , V_21 ,
V_28 -> V_23 ) ;
F_21 ( V_28 ) ;
V_28 -> V_33 =
V_21 / ( V_38 * V_30 -> V_20 ) ;
return;
} else {
F_17 ( V_30 -> V_20 ,
V_38 * V_30 -> V_20 ,
V_28 -> V_23 ) ;
F_25 ( V_28 -> V_23 ) ;
V_28 -> V_33 ++ ;
if ( F_19 ( V_28 -> V_33 >= V_34 ) )
V_28 -> V_33 %= V_34 ;
F_26 ( & V_28 -> V_49 , V_50 + 1 ) ;
}
}
static void F_27 ( unsigned long V_51 )
{
int V_52 ;
struct V_29 * V_30 ;
struct V_22 * V_23 ;
struct V_27 * V_28 ;
V_23 = (struct V_22 * ) V_51 ;
V_30 = V_23 -> V_30 ;
V_28 = V_23 -> V_31 -> V_32 ;
V_52 =
F_24 ( V_30 ,
F_2
( V_53 ) ) /
V_38 ;
if ( V_52 == V_28 -> V_54 ) {
F_26 ( & ( V_28 -> V_49 ) , V_50 + 1 ) ;
return;
}
if ( V_30 -> V_20 > 1 )
V_28 -> V_54 = V_52 ;
if ( F_19 ( V_28 -> V_48 == 0 ) )
V_28 -> V_48 = 1 ;
F_28 ( V_55 , & ( V_28 -> V_47 ) ) ;
}
static void F_29 ( struct V_22 * V_23 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_30 = V_23 -> V_30 ;
V_28 = V_23 -> V_31 -> V_32 ;
F_28 ( V_55 , & ( V_28 -> V_47 ) ) ;
if ( F_19 ( V_28 -> V_49 . V_56 ) ) {
F_26 ( & V_28 -> V_49 , V_50 + 4 ) ;
return;
}
F_30 ( & ( V_28 -> V_49 ) ) ;
V_28 -> V_49 . V_56 = ( unsigned long ) V_23 ;
V_28 -> V_49 . V_57 = F_27 ;
V_28 -> V_49 . V_58 = V_50 + 4 ;
F_31 ( & ( V_28 -> V_49 ) ) ;
}
static int F_32 ( struct V_22
* V_23 )
{
struct V_29 * V_30 ;
struct V_44 * V_43 ;
struct V_27 * V_28 ;
if ( ! V_59 )
return - V_60 ;
V_28 = V_23 -> V_31 -> V_32 ;
V_43 = F_33 ( sizeof( struct V_44 ) , V_61 ) ;
if ( ! V_43 )
return - V_62 ;
V_43 -> V_63 = V_64 ;
V_43 -> V_65 = V_17 ;
V_43 -> V_66 = V_28 -> V_67 ;
V_43 -> V_68 = 0x80 ;
V_43 -> V_69 = 0 ;
V_43 -> V_7 = 0 ;
V_28 -> V_43 = V_43 ;
V_30 = V_23 -> V_30 ;
V_30 -> V_70 = V_71 ;
F_12 () ;
V_28 -> V_33 = 0 ;
V_28 -> V_54 = 0 ;
V_28 -> V_48 = 0 ;
return 0 ;
}
static int F_34 ( struct V_22
* V_23 )
{
struct V_27 * V_28 = V_23 -> V_31 -> V_32 ;
F_35 ( V_55 ) ;
if ( V_28 -> V_49 . V_56 )
F_36 ( & V_28 -> V_49 ) ;
F_37 ( V_28 -> V_43 ) ;
F_11 () ;
return 0 ;
}
static int F_38 ( struct V_22
* V_23 )
{
return F_39 ( V_23 ) ;
}
static int F_40 ( struct V_22
* V_23 , struct V_72
* V_73 )
{
return
F_41 ( V_23 ,
F_42 ( V_73 ) ) ;
}
static int F_43 ( struct V_22
* V_23 )
{
struct V_27 * V_28 = V_23 -> V_31 -> V_32 ;
if ( ( V_23 -> V_30 ) -> V_74 == V_75 )
V_28 -> V_43 -> V_63 = V_76 ;
V_28 -> V_43 -> V_77 = V_23 -> V_30 -> V_78 ;
V_28 -> V_23 = V_23 ;
return 0 ;
}
static int F_44 ( struct V_22
* V_23 , int V_65 )
{
switch ( V_65 ) {
case V_79 :
F_29 ( V_23 ) ;
break;
case V_80 :
F_16 () ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static unsigned long F_45 ( struct V_22
* V_23 )
{
return F_2 ( V_53 ) ;
}
static int T_3 F_46 ( struct V_27
* V_28 , int V_82 )
{
struct V_83 * V_31 ;
int V_25 ;
V_25 =
F_47 ( V_28 -> V_84 , L_2 , V_82 , 1 , 0 ,
& V_31 ) ;
if ( F_19 ( V_25 < 0 ) )
return V_25 ;
V_31 -> V_32 = V_28 ;
strcpy ( V_31 -> V_85 , L_2 ) ;
F_48 ( V_31 , V_86 ,
& V_87 ) ;
V_25 =
F_49 ( V_31 ,
V_88 ,
F_50
( V_61 ) ,
V_37 ,
V_37 ) ;
return V_25 ;
}
static int F_51 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
V_92 -> V_93 . integer . V_93 [ 0 ] = 1 ;
return 0 ;
}
static int F_52 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
if ( V_92 -> V_93 . integer . V_93 [ 0 ] == 1 )
return 0 ;
else
F_16 () ;
return 0 ;
}
static int F_53 ( struct V_89 * V_90 ,
struct V_94 * V_95 )
{
V_95 -> type = V_96 ;
V_95 -> V_97 = 1 ;
V_95 -> V_93 . integer . V_98 = 0 ;
V_95 -> V_93 . integer . V_99 = 0xFF ;
return 0 ;
}
static int F_54 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_27 * V_28 ;
V_28 = V_90 -> V_32 ;
if ( F_19 ( ! V_28 -> V_43 ) )
return - V_100 ;
V_92 -> V_93 . integer . V_93 [ 0 ] = V_28 -> V_43 -> V_66 ;
return 0 ;
}
static int F_55 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_27 * V_28 ;
unsigned int V_66 ;
V_28 = V_90 -> V_32 ;
if ( F_19 ( ! V_28 -> V_43 ) )
return - V_100 ;
V_66 = V_92 -> V_93 . integer . V_93 [ 0 ] ;
if ( V_66 > 0xff )
return - V_81 ;
if ( F_19 ( V_28 -> V_43 -> V_66 == V_66 ) )
return 0 ;
V_28 -> V_43 -> V_66 = V_92 -> V_93 . integer . V_93 [ 0 ] ;
V_28 -> V_67 = V_92 -> V_93 . integer . V_93 [ 0 ] ;
F_9 ( V_42 ,
V_28 -> V_43 , sizeof( struct V_44 ) ) ;
return 1 ;
}
static int F_56 ( void )
{
int V_25 ;
const struct V_101 * V_102 ;
F_13 () ;
V_25 = F_57 ( & V_102 , L_3 , & V_103 -> V_104 ) ;
if ( F_19 ( V_25 ) )
return V_25 ;
F_11 () ;
F_9 ( 0 , V_102 -> V_56 , V_102 -> V_105 ) ;
F_12 () ;
F_58 ( V_102 ) ;
return V_25 ;
}
static int F_59 ( struct V_27 * V_28 )
{
int V_25 ;
V_25 = F_60
( V_28 -> V_84 ,
F_61 ( & V_106 , V_28 ) ) ;
if ( F_19 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_60
( V_28 -> V_84 ,
F_61 ( & V_107 , V_28 ) ) ;
if ( F_19 ( V_25 < 0 ) )
return V_25 ;
return 0 ;
}
static int F_62 ( struct V_108 * V_109 )
{
struct V_27 * V_28 ;
V_28 = F_63 ( V_109 ) ;
if ( F_19 ( ! V_28 ) )
return - V_110 ;
F_64 ( V_28 -> V_84 ) ;
F_37 ( V_28 ) ;
return 0 ;
}
static int F_65 ( struct V_108 * V_109 )
{
int V_25 ;
struct V_27 * V_28 ;
V_28 = F_33 ( sizeof( struct V_27 ) , V_61 ) ;
if ( F_19 ( ! V_28 ) )
return - V_62 ;
V_25 = F_66 ( & V_109 -> V_104 , V_111 , V_112 ,
V_113 , 0 , & V_28 -> V_84 ) ;
if ( F_19 ( V_25 < 0 ) ) {
F_37 ( V_28 ) ;
return V_25 ;
}
strcpy ( V_28 -> V_84 -> V_114 , L_4 ) ;
strcpy ( V_28 -> V_84 -> V_115 , V_112 ) ;
strcpy ( V_28 -> V_84 -> V_116 ,
L_5 ) ;
F_67 ( & ( V_28 -> V_47 ) , F_22 ) ;
V_25 = F_46 ( V_28 , 0 ) ;
if ( F_19 ( V_25 < 0 ) )
goto V_117;
V_28 -> V_49 . V_56 = 0 ;
V_28 -> V_43 = NULL ;
V_25 = F_59 ( V_28 ) ;
if ( F_19 ( V_25 < 0 ) )
goto V_117;
V_25 = F_68 ( V_28 -> V_84 ) ;
if ( F_19 ( V_25 < 0 ) )
goto V_117;
F_69 ( V_109 , V_28 ) ;
V_55 = F_70 ( V_118 ) ;
if ( F_19 ( ! V_55 ) )
goto V_117;
F_3
( L_6 ) ;
return 0 ;
V_117:
F_64 ( V_28 -> V_84 ) ;
F_37 ( V_28 ) ;
return V_25 ;
}
static int T_3 F_71 ( void )
{
int V_25 ;
V_25 = F_72 ( & V_119 ) ;
if ( F_19 ( V_25 < 0 ) )
return V_25 ;
V_103 = F_73 ( V_112 , - 1 ,
V_120 , 2 ) ;
if ( F_74 ( V_103 ) ) {
F_75 ( & V_119 ) ;
return F_76 ( V_103 ) ;
}
return F_56 () ;
}
static void T_4 F_77 ( void )
{
if ( F_78 ( V_55 ) )
F_79 ( V_55 ) ;
F_80 ( V_103 ) ;
F_75 ( & V_119 ) ;
F_13 () ;
}
