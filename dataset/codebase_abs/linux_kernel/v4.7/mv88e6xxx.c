static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( ! F_3 ( & V_2 -> V_3 ) ) ) {
F_4 ( V_2 -> V_4 , L_1 ) ;
F_5 () ;
}
}
static int F_6 ( struct V_5 * V_6 , int V_7 )
{
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
V_8 = F_7 ( V_6 , V_7 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
}
return - V_12 ;
}
static int F_8 ( struct V_5 * V_6 , int V_7 , int V_13 ,
int V_14 )
{
int V_8 ;
if ( V_7 == 0 )
return F_7 ( V_6 , V_13 , V_14 ) ;
V_8 = F_6 ( V_6 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_9 ( V_6 , V_7 , V_10 ,
V_15 | ( V_13 << 5 ) | V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_6 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_7 ( V_6 , V_7 , V_16 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_8 & 0xffff ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_13 , int V_14 )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_8 ( V_2 -> V_6 , V_2 -> V_7 , V_13 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
F_11 ( V_2 -> V_4 , L_2 ,
V_13 , V_14 , V_8 ) ;
return V_8 ;
}
int F_12 ( struct V_1 * V_2 , int V_13 , int V_14 )
{
int V_8 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_10 ( V_2 , V_13 , V_14 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_15 ( struct V_5 * V_6 , int V_7 , int V_13 ,
int V_14 , T_1 V_17 )
{
int V_8 ;
if ( V_7 == 0 )
return F_9 ( V_6 , V_13 , V_14 , V_17 ) ;
V_8 = F_6 ( V_6 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_9 ( V_6 , V_7 , V_16 , V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_9 ( V_6 , V_7 , V_10 ,
V_18 | ( V_13 << 5 ) | V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_6 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_13 ,
int V_14 , T_1 V_17 )
{
F_1 ( V_2 ) ;
F_11 ( V_2 -> V_4 , L_3 ,
V_13 , V_14 , V_17 ) ;
return F_15 ( V_2 -> V_6 , V_2 -> V_7 , V_13 , V_14 , V_17 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_13 ,
int V_14 , T_1 V_17 )
{
int V_8 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_16 ( V_2 , V_13 , V_14 , V_17 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_18 ( struct V_19 * V_20 , T_2 * V_13 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_21 ;
V_21 = F_17 ( V_2 , V_22 , V_23 ,
( V_13 [ 0 ] << 8 ) | V_13 [ 1 ] ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 ( V_2 , V_22 , V_24 ,
( V_13 [ 2 ] << 8 ) | V_13 [ 3 ] ) ;
if ( V_21 )
return V_21 ;
return F_17 ( V_2 , V_22 , V_25 ,
( V_13 [ 4 ] << 8 ) | V_13 [ 5 ] ) ;
}
static int F_20 ( struct V_19 * V_20 , T_2 * V_13 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
int V_26 ;
V_8 = F_17 ( V_2 , V_27 , V_28 ,
V_29 |
( V_9 << 8 ) | V_13 [ V_9 ] ) ;
if ( V_8 )
return V_8 ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ ) {
V_8 = F_12 ( V_2 , V_27 ,
V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 & V_29 ) == 0 )
break;
}
if ( V_26 == 16 )
return - V_12 ;
}
return 0 ;
}
int F_21 ( struct V_19 * V_20 , T_2 * V_13 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
if ( F_22 ( V_2 , V_30 ) )
return F_20 ( V_20 , V_13 ) ;
else
return F_18 ( V_20 , V_13 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_13 ,
int V_31 )
{
if ( V_13 >= 0 )
return F_10 ( V_2 , V_13 , V_31 ) ;
return 0xffff ;
}
static int F_24 ( struct V_1 * V_2 , int V_13 ,
int V_31 , T_1 V_17 )
{
if ( V_13 >= 0 )
return F_16 ( V_2 , V_13 , V_31 , V_17 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_8 ;
unsigned long V_32 ;
V_8 = F_10 ( V_2 , V_22 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_16 ( V_2 , V_22 , V_33 ,
V_8 & ~ V_34 ) ;
if ( V_8 )
return V_8 ;
V_32 = V_35 + 1 * V_36 ;
while ( F_26 ( V_35 , V_32 ) ) {
V_8 = F_10 ( V_2 , V_22 , V_37 ) ;
if ( V_8 < 0 )
return V_8 ;
F_27 ( 1000 , 2000 ) ;
if ( ( V_8 & V_38 ) !=
V_39 )
return 0 ;
}
return - V_12 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_8 , V_21 ;
unsigned long V_32 ;
V_8 = F_12 ( V_2 , V_22 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_21 = F_17 ( V_2 , V_22 , V_33 ,
V_8 | V_34 ) ;
if ( V_21 )
return V_21 ;
V_32 = V_35 + 1 * V_36 ;
while ( F_26 ( V_35 , V_32 ) ) {
V_8 = F_12 ( V_2 , V_22 , V_37 ) ;
if ( V_8 < 0 )
return V_8 ;
F_27 ( 1000 , 2000 ) ;
if ( ( V_8 & V_38 ) ==
V_39 )
return 0 ;
}
return - V_12 ;
}
static void F_29 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( V_41 , struct V_1 , V_42 ) ;
if ( F_31 ( & V_2 -> V_43 ) ) {
if ( F_28 ( V_2 ) == 0 )
V_2 -> V_44 = 0 ;
F_14 ( & V_2 -> V_43 ) ;
}
}
static void F_32 ( unsigned long V_45 )
{
struct V_1 * V_2 = ( void * ) V_45 ;
F_33 ( & V_2 -> V_42 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_8 ;
F_13 ( & V_2 -> V_43 ) ;
if ( ! V_2 -> V_44 ) {
V_8 = F_25 ( V_2 ) ;
if ( V_8 < 0 ) {
F_14 ( & V_2 -> V_43 ) ;
return V_8 ;
}
V_2 -> V_44 = 1 ;
} else {
F_35 ( & V_2 -> V_46 ) ;
V_8 = 0 ;
}
return V_8 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_46 , V_35 + F_38 ( 10 ) ) ;
F_14 ( & V_2 -> V_43 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_43 ) ;
F_41 ( & V_2 -> V_42 , F_29 ) ;
F_42 ( & V_2 -> V_46 ) ;
V_2 -> V_46 . V_47 = ( unsigned long ) V_2 ;
V_2 -> V_46 . V_48 = F_32 ;
}
static int F_43 ( struct V_1 * V_2 , int V_13 ,
int V_31 )
{
int V_8 ;
V_8 = F_34 ( V_2 ) ;
if ( V_8 >= 0 ) {
V_8 = F_10 ( V_2 , V_13 , V_31 ) ;
F_36 ( V_2 ) ;
}
return V_8 ;
}
static int F_44 ( struct V_1 * V_2 , int V_13 ,
int V_31 , T_1 V_17 )
{
int V_8 ;
V_8 = F_34 ( V_2 ) ;
if ( V_8 >= 0 ) {
V_8 = F_16 ( V_2 , V_13 , V_31 , V_17 ) ;
F_36 ( V_2 ) ;
}
return V_8 ;
}
static bool F_45 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_51 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_52 ;
}
static bool F_47 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_53 ;
}
static bool F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_54 ;
}
static bool F_49 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_55 ;
}
static bool F_50 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_56 ;
}
static bool F_51 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_57 ;
}
static bool F_52 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_50 == V_58 ;
}
static unsigned int F_53 ( struct V_1 * V_2 )
{
return V_2 -> V_49 -> V_59 ;
}
static bool F_54 ( struct V_1 * V_2 )
{
if ( F_47 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) || F_52 ( V_2 ) )
return true ;
return false ;
}
static void F_55 ( struct V_19 * V_20 , int V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
T_3 V_14 ;
int V_8 ;
if ( ! F_56 ( V_62 ) )
return;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_63 ) ;
if ( V_8 < 0 )
goto V_64;
V_14 = V_8 & ~ ( V_65 |
V_66 |
V_67 |
V_68 |
V_69 ) ;
V_14 |= V_66 ;
if ( V_62 -> V_70 )
V_14 |= V_65 ;
if ( F_45 ( V_2 ) && V_62 -> V_71 > V_72 )
goto V_64;
switch ( V_62 -> V_71 ) {
case V_73 :
V_14 |= V_74 ;
break;
case V_72 :
V_14 |= V_75 ;
break;
case V_76 :
V_14 |= V_77 ;
break;
default:
F_58 ( L_4 ) ;
goto V_64;
}
V_14 |= V_68 ;
if ( V_62 -> V_78 == V_79 )
V_14 |= V_67 ;
if ( ( F_52 ( V_2 ) || F_51 ( V_2 ) ) &&
( V_60 >= V_2 -> V_49 -> V_80 - 2 ) ) {
if ( V_62 -> V_81 == V_82 )
V_14 |= V_83 ;
if ( V_62 -> V_81 == V_84 )
V_14 |= V_85 ;
if ( V_62 -> V_81 == V_86 )
V_14 |= ( V_83 |
V_85 ) ;
}
F_16 ( V_2 , F_57 ( V_60 ) , V_63 , V_14 ) ;
V_64:
F_14 ( & V_2 -> V_3 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 10 ; V_9 ++ ) {
V_8 = F_10 ( V_2 , V_22 , V_87 ) ;
if ( ( V_8 & V_88 ) == 0 )
return 0 ;
}
return - V_12 ;
}
static int F_60 ( struct V_1 * V_2 ,
int V_60 )
{
int V_8 ;
if ( F_50 ( V_2 ) || F_52 ( V_2 ) )
V_60 = ( V_60 + 1 ) << 5 ;
V_8 = F_16 ( V_2 , V_22 , V_87 ,
V_89 |
V_90 | V_60 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_59 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 ,
int V_91 , T_3 * V_17 )
{
T_3 V_92 ;
int V_8 ;
* V_17 = 0 ;
V_8 = F_16 ( V_2 , V_22 , V_87 ,
V_93 |
V_90 | V_91 ) ;
if ( V_8 < 0 )
return;
V_8 = F_59 ( V_2 ) ;
if ( V_8 < 0 )
return;
V_8 = F_10 ( V_2 , V_22 , V_94 ) ;
if ( V_8 < 0 )
return;
V_92 = V_8 << 16 ;
V_8 = F_10 ( V_2 , V_22 , V_95 ) ;
if ( V_8 < 0 )
return;
* V_17 = V_92 | V_8 ;
}
static bool F_62 ( struct V_1 * V_2 ,
struct V_96 * V_91 )
{
switch ( V_91 -> type ) {
case V_97 :
return true ;
case V_98 :
return F_50 ( V_2 ) ;
case V_99 :
return F_46 ( V_2 ) ||
F_49 ( V_2 ) ||
F_47 ( V_2 ) ||
F_48 ( V_2 ) ||
F_51 ( V_2 ) ||
F_52 ( V_2 ) ;
}
return false ;
}
static T_4 F_63 ( struct V_1 * V_2 ,
struct V_96 * V_100 ,
int V_60 )
{
T_3 V_101 ;
T_3 V_102 = 0 ;
int V_8 ;
T_5 V_103 ;
switch ( V_100 -> type ) {
case V_99 :
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_100 -> V_14 ) ;
if ( V_8 < 0 )
return V_104 ;
V_101 = V_8 ;
if ( V_100 -> V_105 == 4 ) {
V_8 = F_10 ( V_2 , F_57 ( V_60 ) ,
V_100 -> V_14 + 1 ) ;
if ( V_8 < 0 )
return V_104 ;
V_102 = V_8 ;
}
break;
case V_97 :
case V_98 :
F_61 ( V_2 , V_100 -> V_14 , & V_101 ) ;
if ( V_100 -> V_105 == 8 )
F_61 ( V_2 , V_100 -> V_14 + 1 , & V_102 ) ;
}
V_103 = ( ( ( T_5 ) V_102 ) << 16 ) | V_101 ;
return V_103 ;
}
static void F_64 ( struct V_19 * V_20 , int V_60 ,
T_6 * V_47 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_96 * V_91 ;
int V_9 , V_26 ;
for ( V_9 = 0 , V_26 = 0 ; V_9 < F_65 ( V_106 ) ; V_9 ++ ) {
V_91 = & V_106 [ V_9 ] ;
if ( F_62 ( V_2 , V_91 ) ) {
memcpy ( V_47 + V_26 * V_107 , V_91 -> string ,
V_107 ) ;
V_26 ++ ;
}
}
}
static int F_66 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_96 * V_91 ;
int V_9 , V_26 ;
for ( V_9 = 0 , V_26 = 0 ; V_9 < F_65 ( V_106 ) ; V_9 ++ ) {
V_91 = & V_106 [ V_9 ] ;
if ( F_62 ( V_2 , V_91 ) )
V_26 ++ ;
}
return V_26 ;
}
static void F_67 ( struct V_19 * V_20 , int V_60 ,
T_4 * V_47 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_96 * V_91 ;
int V_8 ;
int V_9 , V_26 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_60 ( V_2 , V_60 ) ;
if ( V_8 < 0 ) {
F_14 ( & V_2 -> V_3 ) ;
return;
}
for ( V_9 = 0 , V_26 = 0 ; V_9 < F_65 ( V_106 ) ; V_9 ++ ) {
V_91 = & V_106 [ V_9 ] ;
if ( F_62 ( V_2 , V_91 ) ) {
V_47 [ V_26 ] = F_63 ( V_2 , V_91 , V_60 ) ;
V_26 ++ ;
}
}
F_14 ( & V_2 -> V_3 ) ;
}
static int F_68 ( struct V_19 * V_20 , int V_60 )
{
return 32 * sizeof( T_1 ) ;
}
static void F_69 ( struct V_19 * V_20 , int V_60 ,
struct V_108 * V_109 , void * V_110 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
T_1 * V_111 = V_110 ;
int V_9 ;
V_109 -> V_112 = 0 ;
memset ( V_111 , 0xff , 32 * sizeof( T_1 ) ) ;
F_13 ( & V_2 -> V_3 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
int V_8 ;
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_9 ) ;
if ( V_8 >= 0 )
V_111 [ V_9 ] = V_8 ;
}
F_14 ( & V_2 -> V_3 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_14 , int V_113 ,
T_1 V_114 )
{
unsigned long V_32 = V_35 + V_36 / 10 ;
while ( F_26 ( V_35 , V_32 ) ) {
int V_8 ;
V_8 = F_10 ( V_2 , V_14 , V_113 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! ( V_8 & V_114 ) )
return 0 ;
F_27 ( 1000 , 2000 ) ;
}
return - V_12 ;
}
static int F_71 ( struct V_1 * V_2 , int V_14 ,
int V_113 , T_1 V_114 )
{
int V_8 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_70 ( V_2 , V_14 , V_113 , V_114 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_72 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , V_27 , V_115 ,
V_116 ) ;
}
static int F_73 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
return F_71 ( V_2 , V_27 , V_117 ,
V_118 ) ;
}
static int F_74 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
return F_71 ( V_2 , V_27 , V_117 ,
V_119 ) ;
}
static int F_75 ( struct V_19 * V_20 , int V_13 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
F_13 ( & V_2 -> V_120 ) ;
V_8 = F_17 ( V_2 , V_27 , V_117 ,
V_121 |
( V_13 & V_122 ) ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_74 ( V_20 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_12 ( V_2 , V_27 , V_123 ) ;
error:
F_14 ( & V_2 -> V_120 ) ;
return V_8 ;
}
static int F_76 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
if ( F_22 ( V_2 , V_124 ) )
return V_2 -> V_125 ;
return 0 ;
}
static int F_77 ( struct V_19 * V_20 ,
struct V_126 * V_127 , T_2 * V_47 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_113 ;
int V_128 ;
int V_8 ;
if ( ! F_22 ( V_2 , V_124 ) )
return - V_129 ;
V_113 = V_127 -> V_113 ;
V_128 = V_127 -> V_128 ;
V_127 -> V_128 = 0 ;
V_127 -> V_130 = 0xc3ec4951 ;
V_8 = F_73 ( V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_113 & 1 ) {
int V_131 ;
V_131 = F_75 ( V_20 , V_113 >> 1 ) ;
if ( V_131 < 0 )
return V_131 ;
* V_47 ++ = ( V_131 >> 8 ) & 0xff ;
V_113 ++ ;
V_128 -- ;
V_127 -> V_128 ++ ;
}
while ( V_128 >= 2 ) {
int V_131 ;
V_131 = F_75 ( V_20 , V_113 >> 1 ) ;
if ( V_131 < 0 )
return V_131 ;
* V_47 ++ = V_131 & 0xff ;
* V_47 ++ = ( V_131 >> 8 ) & 0xff ;
V_113 += 2 ;
V_128 -= 2 ;
V_127 -> V_128 += 2 ;
}
if ( V_128 ) {
int V_131 ;
V_131 = F_75 ( V_20 , V_113 >> 1 ) ;
if ( V_131 < 0 )
return V_131 ;
* V_47 ++ = V_131 & 0xff ;
V_113 ++ ;
V_128 -- ;
V_127 -> V_128 ++ ;
}
return 0 ;
}
static int F_78 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
V_8 = F_12 ( V_2 , V_27 , V_117 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! ( V_8 & V_132 ) )
return - V_133 ;
return 0 ;
}
static int F_79 ( struct V_19 * V_20 , int V_13 ,
T_1 V_47 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
F_13 ( & V_2 -> V_120 ) ;
V_8 = F_17 ( V_2 , V_27 , V_123 , V_47 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_17 ( V_2 , V_27 , V_117 ,
V_134 |
( V_13 & V_122 ) ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_74 ( V_20 ) ;
error:
F_14 ( & V_2 -> V_120 ) ;
return V_8 ;
}
static int F_80 ( struct V_19 * V_20 ,
struct V_126 * V_127 , T_2 * V_47 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_113 ;
int V_8 ;
int V_128 ;
if ( ! F_22 ( V_2 , V_124 ) )
return - V_129 ;
if ( V_127 -> V_130 != 0xc3ec4951 )
return - V_135 ;
V_8 = F_78 ( V_20 ) ;
if ( V_8 )
return V_8 ;
V_113 = V_127 -> V_113 ;
V_128 = V_127 -> V_128 ;
V_127 -> V_128 = 0 ;
V_8 = F_73 ( V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_113 & 1 ) {
int V_131 ;
V_131 = F_75 ( V_20 , V_113 >> 1 ) ;
if ( V_131 < 0 )
return V_131 ;
V_131 = ( * V_47 ++ << 8 ) | ( V_131 & 0xff ) ;
V_8 = F_79 ( V_20 , V_113 >> 1 , V_131 ) ;
if ( V_8 < 0 )
return V_8 ;
V_113 ++ ;
V_128 -- ;
V_127 -> V_128 ++ ;
}
while ( V_128 >= 2 ) {
int V_131 ;
V_131 = * V_47 ++ ;
V_131 |= * V_47 ++ << 8 ;
V_8 = F_79 ( V_20 , V_113 >> 1 , V_131 ) ;
if ( V_8 < 0 )
return V_8 ;
V_113 += 2 ;
V_128 -= 2 ;
V_127 -> V_128 += 2 ;
}
if ( V_128 ) {
int V_131 ;
V_131 = F_75 ( V_20 , V_113 >> 1 ) ;
if ( V_131 < 0 )
return V_131 ;
V_131 = ( V_131 & 0xff00 ) | * V_47 ++ ;
V_8 = F_79 ( V_20 , V_113 >> 1 , V_131 ) ;
if ( V_8 < 0 )
return V_8 ;
V_113 ++ ;
V_128 -- ;
V_127 -> V_128 ++ ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , V_22 , V_136 ,
V_137 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
int V_13 , int V_31 )
{
int V_8 ;
V_8 = F_16 ( V_2 , V_27 , V_115 ,
V_138 | ( V_13 << 5 ) |
V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_72 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_2 , V_27 , V_139 ) ;
return V_8 ;
}
static int F_83 ( struct V_1 * V_2 ,
int V_13 , int V_31 , T_1 V_17 )
{
int V_8 ;
V_8 = F_16 ( V_2 , V_27 , V_139 , V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_16 ( V_2 , V_27 , V_115 ,
V_140 | ( V_13 << 5 ) |
V_31 ) ;
return F_72 ( V_2 ) ;
}
static int F_84 ( struct V_19 * V_20 , int V_60 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_14 ;
if ( ! F_22 ( V_2 , V_143 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_14 = F_82 ( V_2 , V_60 , 16 ) ;
if ( V_14 < 0 )
goto V_64;
V_142 -> V_144 = ! ! ( V_14 & 0x0200 ) ;
V_142 -> V_145 = ! ! ( V_14 & 0x0100 ) ;
V_14 = F_10 ( V_2 , F_57 ( V_60 ) , V_146 ) ;
if ( V_14 < 0 )
goto V_64;
V_142 -> V_147 = ! ! ( V_14 & V_148 ) ;
V_14 = 0 ;
V_64:
F_14 ( & V_2 -> V_3 ) ;
return V_14 ;
}
static int F_85 ( struct V_19 * V_20 , int V_60 ,
struct V_61 * V_62 , struct V_141 * V_142 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_14 ;
int V_8 ;
if ( ! F_22 ( V_2 , V_143 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_82 ( V_2 , V_60 , 16 ) ;
if ( V_8 < 0 )
goto V_64;
V_14 = V_8 & ~ 0x0300 ;
if ( V_142 -> V_144 )
V_14 |= 0x0200 ;
if ( V_142 -> V_145 )
V_14 |= 0x0100 ;
V_8 = F_83 ( V_2 , V_60 , 16 , V_14 ) ;
V_64:
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_149 , T_1 V_150 )
{
int V_8 ;
if ( F_54 ( V_2 ) ) {
V_8 = F_16 ( V_2 , V_22 , V_151 , V_149 ) ;
if ( V_8 < 0 )
return V_8 ;
} else if ( F_53 ( V_2 ) == 256 ) {
V_8 = F_10 ( V_2 , V_22 , V_152 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_16 ( V_2 , V_22 , V_152 ,
( V_8 & 0xfff ) |
( ( V_149 << 8 ) & 0xf000 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_150 |= V_149 & 0xf ;
}
V_8 = F_16 ( V_2 , V_22 , V_136 , V_150 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_81 ( V_2 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
T_1 V_47 = V_154 -> V_155 & V_156 ;
if ( V_154 -> V_155 != V_157 ) {
unsigned int V_114 , V_158 ;
if ( V_154 -> V_159 ) {
V_47 |= V_160 ;
V_114 = V_161 ;
V_158 = V_162 ;
} else {
V_114 = V_163 ;
V_158 = V_164 ;
}
V_47 |= ( V_154 -> V_165 << V_158 ) & V_114 ;
}
return F_16 ( V_2 , V_22 , V_166 , V_47 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
bool V_167 )
{
int V_168 ;
int V_21 ;
V_21 = F_81 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_87 ( V_2 , V_154 ) ;
if ( V_21 )
return V_21 ;
if ( V_154 -> V_149 ) {
V_168 = V_167 ? V_169 :
V_170 ;
} else {
V_168 = V_167 ? V_171 :
V_172 ;
}
return F_86 ( V_2 , V_154 -> V_149 , V_168 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
T_1 V_149 , bool V_167 )
{
struct V_153 V_154 = {
. V_149 = V_149 ,
. V_155 = 0 ,
} ;
return F_88 ( V_2 , & V_154 , V_167 ) ;
}
static int F_90 ( struct V_1 * V_2 , T_1 V_149 ,
int V_173 , int V_174 , bool V_167 )
{
struct V_153 V_154 = {
. V_159 = false ,
. V_149 = V_149 ,
} ;
V_154 . V_155 = V_156 ;
V_154 . V_165 = ( V_174 & 0x0f ) << 4 ;
V_154 . V_165 |= V_173 & 0x0f ;
return F_88 ( V_2 , & V_154 , V_167 ) ;
}
static int F_91 ( struct V_1 * V_2 , T_1 V_149 ,
int V_60 , bool V_167 )
{
return F_90 ( V_2 , V_149 , V_60 , 0x0f , V_167 ) ;
}
static int F_92 ( struct V_1 * V_2 , int V_60 ,
T_2 V_155 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
int V_14 , V_8 = 0 ;
T_2 V_175 ;
V_14 = F_10 ( V_2 , F_57 ( V_60 ) , V_176 ) ;
if ( V_14 < 0 )
return V_14 ;
V_175 = V_14 & V_177 ;
if ( V_175 != V_155 ) {
if ( ( V_175 == V_178 ||
V_175 == V_179 )
&& ( V_155 == V_180 ||
V_155 == V_181 ) ) {
V_8 = F_91 ( V_2 , 0 , V_60 , false ) ;
if ( V_8 )
return V_8 ;
}
V_14 = ( V_14 & ~ V_177 ) | V_155 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_176 ,
V_14 ) ;
if ( V_8 )
return V_8 ;
F_93 ( V_20 -> V_182 [ V_60 ] , L_5 ,
V_183 [ V_155 ] ,
V_183 [ V_175 ] ) ;
}
return V_8 ;
}
static int F_94 ( struct V_1 * V_2 ,
int V_60 )
{
struct V_184 * V_185 = V_2 -> V_182 [ V_60 ] . V_186 ;
const T_1 V_114 = ( 1 << V_2 -> V_49 -> V_80 ) - 1 ;
struct V_19 * V_20 = V_2 -> V_20 ;
T_1 V_187 = 0 ;
int V_14 ;
int V_9 ;
if ( F_95 ( V_20 , V_60 ) || F_96 ( V_20 , V_60 ) ) {
V_187 = V_114 ;
} else {
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
if ( V_185 && V_2 -> V_182 [ V_9 ] . V_186 == V_185 )
V_187 |= F_97 ( V_9 ) ;
if ( F_95 ( V_20 , V_9 ) || F_96 ( V_20 , V_9 ) )
V_187 |= F_97 ( V_9 ) ;
}
}
V_187 &= ~ F_97 ( V_60 ) ;
V_14 = F_10 ( V_2 , F_57 ( V_60 ) , V_188 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_114 ;
V_14 |= V_187 & V_114 ;
return F_16 ( V_2 , F_57 ( V_60 ) , V_188 , V_14 ) ;
}
static void F_98 ( struct V_19 * V_20 , int V_60 ,
T_2 V_155 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_189 ;
int V_21 ;
if ( ! F_22 ( V_2 , V_190 ) )
return;
switch ( V_155 ) {
case V_191 :
V_189 = V_180 ;
break;
case V_192 :
case V_193 :
V_189 = V_181 ;
break;
case V_194 :
V_189 = V_178 ;
break;
case V_195 :
default:
V_189 = V_179 ;
break;
}
F_13 ( & V_2 -> V_3 ) ;
V_21 = F_92 ( V_2 , V_60 , V_189 ) ;
F_14 ( & V_2 -> V_3 ) ;
if ( V_21 )
F_99 ( V_20 -> V_182 [ V_60 ] , L_6 ,
V_183 [ V_189 ] ) ;
}
static int F_100 ( struct V_1 * V_2 , int V_60 ,
T_1 * V_196 , T_1 * V_197 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_1 V_198 ;
int V_8 ;
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_199 ) ;
if ( V_8 < 0 )
return V_8 ;
V_198 = V_8 & V_200 ;
if ( V_196 ) {
V_8 &= ~ V_200 ;
V_8 |= * V_196 & V_200 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_199 , V_8 ) ;
if ( V_8 < 0 )
return V_8 ;
F_93 ( V_20 -> V_182 [ V_60 ] , L_7 , * V_196 ,
V_198 ) ;
}
if ( V_197 )
* V_197 = V_198 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
int V_60 , T_1 * V_198 )
{
return F_100 ( V_2 , V_60 , NULL , V_198 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
int V_60 , T_1 V_198 )
{
return F_100 ( V_2 , V_60 , & V_198 , NULL ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , V_22 , V_201 ,
V_202 ) ;
}
static int F_104 ( struct V_1 * V_2 , T_1 V_168 )
{
int V_8 ;
V_8 = F_16 ( V_2 , V_22 , V_201 , V_168 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_103 ( V_2 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_103 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_104 ( V_2 , V_203 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_204 * V_154 ,
unsigned int V_205 )
{
T_1 V_109 [ 3 ] ;
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < 3 ; ++ V_9 ) {
V_8 = F_10 ( V_2 , V_22 ,
V_206 + V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
V_109 [ V_9 ] = V_8 ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
unsigned int V_158 = ( V_9 % 4 ) * 4 + V_205 ;
T_1 V_14 = V_109 [ V_9 / 4 ] ;
V_154 -> V_47 [ V_9 ] = ( V_14 >> V_158 ) & V_207 ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
return F_106 ( V_2 , V_154 , 0 ) ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
return F_106 ( V_2 , V_154 , 2 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_204 * V_154 ,
unsigned int V_205 )
{
T_1 V_109 [ 3 ] = { 0 } ;
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
unsigned int V_158 = ( V_9 % 4 ) * 4 + V_205 ;
T_2 V_47 = V_154 -> V_47 [ V_9 ] ;
V_109 [ V_9 / 4 ] |= ( V_47 & V_207 ) << V_158 ;
}
for ( V_9 = 0 ; V_9 < 3 ; ++ V_9 ) {
V_8 = F_16 ( V_2 , V_22 ,
V_206 + V_9 , V_109 [ V_9 ] ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
return F_109 ( V_2 , V_154 , 0 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
return F_109 ( V_2 , V_154 , 2 ) ;
}
static int F_112 ( struct V_1 * V_2 , T_1 V_208 )
{
return F_16 ( V_2 , V_22 , V_209 ,
V_208 & V_210 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
struct V_204 V_211 = { 0 } ;
int V_8 ;
V_8 = F_103 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_104 ( V_2 , V_212 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_2 , V_22 , V_209 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_208 = V_8 & V_210 ;
V_211 . V_213 = ! ! ( V_8 & V_214 ) ;
if ( V_211 . V_213 ) {
V_8 = F_107 ( V_2 , & V_211 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_54 ( V_2 ) ) {
V_8 = F_10 ( V_2 , V_22 ,
V_215 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_149 = V_8 & V_216 ;
} else if ( F_53 ( V_2 ) == 256 ) {
V_8 = F_10 ( V_2 , V_22 ,
V_201 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_149 = ( V_8 & 0xf00 ) >> 4 ;
V_211 . V_149 |= V_8 & 0xf ;
}
if ( F_22 ( V_2 , V_217 ) ) {
V_8 = F_10 ( V_2 , V_22 ,
V_218 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_219 = V_8 & V_220 ;
}
}
* V_154 = V_211 ;
return 0 ;
}
static int F_114 ( struct V_19 * V_20 , int V_60 ,
struct V_221 * V_222 ,
int (* F_115)( struct V_223 * V_224 ) )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_204 V_211 ;
T_1 V_198 ;
int V_21 ;
if ( ! F_22 ( V_2 , V_225 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_21 = F_101 ( V_2 , V_60 , & V_198 ) ;
if ( V_21 )
goto V_226;
V_21 = F_112 ( V_2 , V_210 ) ;
if ( V_21 )
goto V_226;
do {
V_21 = F_113 ( V_2 , & V_211 ) ;
if ( V_21 )
break;
if ( ! V_211 . V_213 )
break;
if ( V_211 . V_47 [ V_60 ] == V_227 )
continue;
V_222 -> V_228 = V_222 -> V_229 = V_211 . V_208 ;
V_222 -> V_230 = 0 ;
if ( V_211 . V_47 [ V_60 ] == V_231 )
V_222 -> V_230 |= V_232 ;
if ( V_211 . V_208 == V_198 )
V_222 -> V_230 |= V_233 ;
V_21 = F_115 ( & V_222 -> V_224 ) ;
if ( V_21 )
break;
} while ( V_211 . V_208 < V_210 );
V_226:
F_14 ( & V_2 -> V_3 ) ;
return V_21 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
T_1 V_168 = V_234 ;
T_1 V_14 = 0 ;
int V_8 ;
V_8 = F_103 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! V_154 -> V_213 )
goto V_235;
V_8 = F_110 ( V_2 , V_154 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_22 ( V_2 , V_217 ) ) {
V_14 = V_154 -> V_219 & V_220 ;
V_8 = F_16 ( V_2 , V_22 , V_218 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( F_54 ( V_2 ) ) {
V_14 = V_154 -> V_149 & V_216 ;
V_8 = F_16 ( V_2 , V_22 , V_215 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
} else if ( F_53 ( V_2 ) == 256 ) {
V_168 |= ( V_154 -> V_149 & 0xf0 ) << 8 ;
V_168 |= V_154 -> V_149 & 0xf ;
}
V_14 = V_214 ;
V_235:
V_14 |= V_154 -> V_208 & V_210 ;
V_8 = F_16 ( V_2 , V_22 , V_209 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_104 ( V_2 , V_168 ) ;
}
static int F_117 ( struct V_1 * V_2 , T_2 V_219 ,
struct V_204 * V_154 )
{
struct V_204 V_211 = { 0 } ;
int V_8 ;
V_8 = F_103 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_16 ( V_2 , V_22 , V_218 ,
V_219 & V_220 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_104 ( V_2 , V_236 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_2 , V_22 , V_218 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_219 = V_8 & V_220 ;
V_8 = F_10 ( V_2 , V_22 , V_209 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_213 = ! ! ( V_8 & V_214 ) ;
if ( V_211 . V_213 ) {
V_8 = F_108 ( V_2 , & V_211 ) ;
if ( V_8 < 0 )
return V_8 ;
}
* V_154 = V_211 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_204 * V_154 )
{
T_1 V_14 = 0 ;
int V_8 ;
V_8 = F_103 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! V_154 -> V_213 )
goto V_235;
V_8 = F_111 ( V_2 , V_154 ) ;
if ( V_8 < 0 )
return V_8 ;
V_14 = V_214 ;
V_235:
V_8 = F_16 ( V_2 , V_22 , V_209 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
V_14 = V_154 -> V_219 & V_220 ;
V_8 = F_16 ( V_2 , V_22 , V_218 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_104 ( V_2 , V_237 ) ;
}
static int F_119 ( struct V_1 * V_2 , int V_60 ,
T_1 * V_196 , T_1 * V_197 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_1 V_238 ;
T_1 V_149 ;
int V_8 ;
if ( F_53 ( V_2 ) == 4096 )
V_238 = 0xff ;
else if ( F_53 ( V_2 ) == 256 )
V_238 = 0xf ;
else
return - V_129 ;
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_188 ) ;
if ( V_8 < 0 )
return V_8 ;
V_149 = ( V_8 & V_239 ) >> 12 ;
if ( V_196 ) {
V_8 &= ~ V_239 ;
V_8 |= ( * V_196 << 12 ) & V_239 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_188 ,
V_8 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_240 ) ;
if ( V_8 < 0 )
return V_8 ;
V_149 |= ( V_8 & V_238 ) << 4 ;
if ( V_196 ) {
V_8 &= ~ V_238 ;
V_8 |= ( * V_196 >> 4 ) & V_238 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_240 ,
V_8 ) ;
if ( V_8 < 0 )
return V_8 ;
F_93 ( V_20 -> V_182 [ V_60 ] , L_8 , * V_196 , V_149 ) ;
}
if ( V_197 )
* V_197 = V_149 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
int V_60 , T_1 * V_149 )
{
return F_119 ( V_2 , V_60 , NULL , V_149 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
int V_60 , T_1 V_149 )
{
return F_119 ( V_2 , V_60 , & V_149 , NULL ) ;
}
static int F_122 ( struct V_1 * V_2 , T_1 * V_149 )
{
F_123 ( V_241 , V_242 ) ;
struct V_204 V_222 ;
int V_9 , V_21 ;
F_124 ( V_241 , V_242 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
V_21 = F_120 ( V_2 , V_9 , V_149 ) ;
if ( V_21 )
return V_21 ;
F_125 ( * V_149 , V_241 ) ;
}
V_21 = F_112 ( V_2 , V_210 ) ;
if ( V_21 )
return V_21 ;
do {
V_21 = F_113 ( V_2 , & V_222 ) ;
if ( V_21 )
return V_21 ;
if ( ! V_222 . V_213 )
break;
F_125 ( V_222 . V_149 , V_241 ) ;
} while ( V_222 . V_208 < V_210 );
* V_149 = F_126 ( V_241 , V_242 , 1 ) ;
if ( F_2 ( * V_149 >= F_53 ( V_2 ) ) )
return - V_243 ;
return F_89 ( V_2 , * V_149 , true ) ;
}
static int F_127 ( struct V_1 * V_2 , T_1 V_208 ,
struct V_204 * V_154 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_204 V_222 = {
. V_213 = true ,
. V_208 = V_208 ,
} ;
int V_9 , V_21 ;
V_21 = F_122 ( V_2 , & V_222 . V_149 ) ;
if ( V_21 )
return V_21 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 )
V_222 . V_47 [ V_9 ] = F_95 ( V_20 , V_9 ) || F_96 ( V_20 , V_9 )
? V_244
: V_227 ;
if ( F_47 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) || F_52 ( V_2 ) ) {
struct V_204 V_245 ;
V_222 . V_219 = 0 ;
V_21 = F_117 ( V_2 , V_220 , & V_245 ) ;
if ( V_21 )
return V_21 ;
if ( V_245 . V_219 != V_222 . V_219 || ! V_245 . V_213 ) {
memset ( & V_245 , 0 , sizeof( V_245 ) ) ;
V_245 . V_213 = true ;
V_245 . V_219 = V_222 . V_219 ;
V_21 = F_118 ( V_2 , & V_245 ) ;
if ( V_21 )
return V_21 ;
}
}
* V_154 = V_222 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , T_1 V_208 ,
struct V_204 * V_154 , bool V_246 )
{
int V_21 ;
if ( ! V_208 )
return - V_135 ;
V_21 = F_112 ( V_2 , V_208 - 1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_113 ( V_2 , V_154 ) ;
if ( V_21 )
return V_21 ;
if ( V_154 -> V_208 != V_208 || ! V_154 -> V_213 ) {
if ( ! V_246 )
return - V_129 ;
V_21 = F_127 ( V_2 , V_208 , V_154 ) ;
}
return V_21 ;
}
static int F_129 ( struct V_19 * V_20 , int V_60 ,
T_1 V_228 , T_1 V_229 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_204 V_222 ;
int V_9 , V_21 ;
if ( ! V_228 )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_21 = F_112 ( V_2 , V_228 - 1 ) ;
if ( V_21 )
goto V_226;
do {
V_21 = F_113 ( V_2 , & V_222 ) ;
if ( V_21 )
goto V_226;
if ( ! V_222 . V_213 )
break;
if ( V_222 . V_208 > V_229 )
break;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
if ( F_96 ( V_20 , V_9 ) || F_95 ( V_20 , V_9 ) )
continue;
if ( V_222 . V_47 [ V_9 ] ==
V_227 )
continue;
if ( V_2 -> V_182 [ V_9 ] . V_186 ==
V_2 -> V_182 [ V_60 ] . V_186 )
break;
F_130 ( V_20 -> V_182 [ V_60 ] ,
L_9 ,
V_222 . V_208 ,
F_131 ( V_2 -> V_182 [ V_9 ] . V_186 ) ) ;
V_21 = - V_129 ;
goto V_226;
}
} while ( V_222 . V_208 < V_229 );
V_226:
F_14 ( & V_2 -> V_3 ) ;
return V_21 ;
}
static int F_132 ( struct V_19 * V_20 , int V_60 ,
bool V_247 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
T_1 V_197 , V_196 = V_247 ? V_248 :
V_249 ;
int V_8 ;
if ( ! F_22 ( V_2 , V_225 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_250 ) ;
if ( V_8 < 0 )
goto V_226;
V_197 = V_8 & V_251 ;
if ( V_196 != V_197 ) {
V_8 &= ~ V_251 ;
V_8 |= V_196 & V_251 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_250 ,
V_8 ) ;
if ( V_8 < 0 )
goto V_226;
F_93 ( V_20 -> V_182 [ V_60 ] , L_10 ,
V_252 [ V_196 ] ,
V_252 [ V_197 ] ) ;
}
V_8 = 0 ;
V_226:
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_133 ( struct V_19 * V_20 , int V_60 ,
const struct V_221 * V_222 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_21 ;
if ( ! F_22 ( V_2 , V_225 ) )
return - V_129 ;
V_21 = F_129 ( V_20 , V_60 , V_222 -> V_228 ,
V_222 -> V_229 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , int V_60 ,
T_1 V_208 , bool V_255 )
{
struct V_204 V_222 ;
int V_21 ;
V_21 = F_128 ( V_2 , V_208 , & V_222 , true ) ;
if ( V_21 )
return V_21 ;
V_222 . V_47 [ V_60 ] = V_255 ?
V_231 :
V_256 ;
return F_116 ( V_2 , & V_222 ) ;
}
static void F_135 ( struct V_19 * V_20 , int V_60 ,
const struct V_221 * V_222 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
bool V_255 = V_222 -> V_230 & V_232 ;
bool V_198 = V_222 -> V_230 & V_233 ;
T_1 V_208 ;
if ( ! F_22 ( V_2 , V_225 ) )
return;
F_13 ( & V_2 -> V_3 ) ;
for ( V_208 = V_222 -> V_228 ; V_208 <= V_222 -> V_229 ; ++ V_208 )
if ( F_134 ( V_2 , V_60 , V_208 , V_255 ) )
F_99 ( V_20 -> V_182 [ V_60 ] , L_11 ,
V_208 , V_255 ? 'u' : 't' ) ;
if ( V_198 && F_102 ( V_2 , V_60 , V_222 -> V_229 ) )
F_99 ( V_20 -> V_182 [ V_60 ] , L_12 ,
V_222 -> V_229 ) ;
F_14 ( & V_2 -> V_3 ) ;
}
static int F_136 ( struct V_1 * V_2 ,
int V_60 , T_1 V_208 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_204 V_222 ;
int V_9 , V_21 ;
V_21 = F_128 ( V_2 , V_208 , & V_222 , false ) ;
if ( V_21 )
return V_21 ;
if ( V_222 . V_47 [ V_60 ] == V_227 )
return - V_129 ;
V_222 . V_47 [ V_60 ] = V_227 ;
V_222 . V_213 = false ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
if ( F_95 ( V_20 , V_9 ) || F_96 ( V_20 , V_9 ) )
continue;
if ( V_222 . V_47 [ V_9 ] != V_227 ) {
V_222 . V_213 = true ;
break;
}
}
V_21 = F_116 ( V_2 , & V_222 ) ;
if ( V_21 )
return V_21 ;
return F_91 ( V_2 , V_222 . V_149 , V_60 , false ) ;
}
static int F_137 ( struct V_19 * V_20 , int V_60 ,
const struct V_221 * V_222 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
T_1 V_198 , V_208 ;
int V_21 = 0 ;
if ( ! F_22 ( V_2 , V_225 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_21 = F_101 ( V_2 , V_60 , & V_198 ) ;
if ( V_21 )
goto V_226;
for ( V_208 = V_222 -> V_228 ; V_208 <= V_222 -> V_229 ; ++ V_208 ) {
V_21 = F_136 ( V_2 , V_60 , V_208 ) ;
if ( V_21 )
goto V_226;
if ( V_208 == V_198 ) {
V_21 = F_102 ( V_2 , V_60 , 0 ) ;
if ( V_21 )
goto V_226;
}
}
V_226:
F_14 ( & V_2 -> V_3 ) ;
return V_21 ;
}
static int F_138 ( struct V_1 * V_2 ,
const unsigned char * V_13 )
{
int V_9 , V_8 ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ ) {
V_8 = F_16 (
V_2 , V_22 , V_257 + V_9 ,
( V_13 [ V_9 * 2 ] << 8 ) | V_13 [ V_9 * 2 + 1 ] ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 ,
unsigned char * V_13 )
{
int V_9 , V_8 ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ ) {
V_8 = F_10 ( V_2 , V_22 ,
V_257 + V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
V_13 [ V_9 * 2 ] = V_8 >> 8 ;
V_13 [ V_9 * 2 + 1 ] = V_8 & 0xff ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
int V_8 ;
V_8 = F_81 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_138 ( V_2 , V_154 -> V_258 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_87 ( V_2 , V_154 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_86 ( V_2 , V_154 -> V_149 , V_259 ) ;
}
static int F_141 ( struct V_1 * V_2 , int V_60 ,
const unsigned char * V_13 , T_1 V_208 ,
T_2 V_155 )
{
struct V_153 V_154 = { 0 } ;
struct V_204 V_222 ;
int V_21 ;
if ( V_208 == 0 )
V_21 = F_120 ( V_2 , V_60 , & V_222 . V_149 ) ;
else
V_21 = F_128 ( V_2 , V_208 , & V_222 , false ) ;
if ( V_21 )
return V_21 ;
V_154 . V_149 = V_222 . V_149 ;
V_154 . V_155 = V_155 ;
F_142 ( V_154 . V_258 , V_13 ) ;
if ( V_155 != V_157 ) {
V_154 . V_159 = false ;
V_154 . V_165 = F_97 ( V_60 ) ;
}
return F_140 ( V_2 , & V_154 ) ;
}
static int F_143 ( struct V_19 * V_20 , int V_60 ,
const struct V_260 * V_261 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
if ( ! F_22 ( V_2 , V_262 ) )
return - V_129 ;
return 0 ;
}
static void F_144 ( struct V_19 * V_20 , int V_60 ,
const struct V_260 * V_261 ,
struct V_253 * V_254 )
{
int V_155 = F_145 ( V_261 -> V_13 ) ?
V_263 :
V_264 ;
struct V_1 * V_2 = F_19 ( V_20 ) ;
if ( ! F_22 ( V_2 , V_262 ) )
return;
F_13 ( & V_2 -> V_3 ) ;
if ( F_141 ( V_2 , V_60 , V_261 -> V_13 , V_261 -> V_208 , V_155 ) )
F_99 ( V_20 -> V_182 [ V_60 ] , L_13 ) ;
F_14 ( & V_2 -> V_3 ) ;
}
static int F_146 ( struct V_19 * V_20 , int V_60 ,
const struct V_260 * V_261 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
if ( ! F_22 ( V_2 , V_262 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_141 ( V_2 , V_60 , V_261 -> V_13 , V_261 -> V_208 ,
V_157 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_147 ( struct V_1 * V_2 , T_1 V_149 ,
struct V_153 * V_154 )
{
struct V_153 V_211 = { 0 } ;
int V_8 ;
V_211 . V_149 = V_149 ;
V_8 = F_81 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_86 ( V_2 , V_149 , V_265 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_139 ( V_2 , V_211 . V_258 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_2 , V_22 , V_166 ) ;
if ( V_8 < 0 )
return V_8 ;
V_211 . V_155 = V_8 & V_156 ;
if ( V_211 . V_155 != V_157 ) {
unsigned int V_114 , V_158 ;
if ( V_8 & V_160 ) {
V_211 . V_159 = true ;
V_114 = V_161 ;
V_158 = V_162 ;
} else {
V_211 . V_159 = false ;
V_114 = V_163 ;
V_158 = V_164 ;
}
V_211 . V_165 = ( V_8 & V_114 ) >> V_158 ;
}
* V_154 = V_211 ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 ,
T_1 V_149 , T_1 V_208 , int V_60 ,
struct V_260 * V_261 ,
int (* F_115)( struct V_223 * V_224 ) )
{
struct V_153 V_13 = {
. V_258 = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ,
} ;
int V_21 ;
V_21 = F_138 ( V_2 , V_13 . V_258 ) ;
if ( V_21 )
return V_21 ;
do {
V_21 = F_147 ( V_2 , V_149 , & V_13 ) ;
if ( V_21 )
break;
if ( V_13 . V_155 == V_157 )
break;
if ( ! V_13 . V_159 && V_13 . V_165 & F_97 ( V_60 ) ) {
bool V_266 = V_13 . V_155 ==
( F_145 ( V_13 . V_258 ) ?
V_263 :
V_264 ) ;
V_261 -> V_208 = V_208 ;
F_142 ( V_261 -> V_13 , V_13 . V_258 ) ;
V_261 -> V_267 = V_266 ? V_268 : V_269 ;
V_21 = F_115 ( & V_261 -> V_224 ) ;
if ( V_21 )
break;
}
} while ( ! F_149 ( V_13 . V_258 ) );
return V_21 ;
}
static int F_150 ( struct V_19 * V_20 , int V_60 ,
struct V_260 * V_261 ,
int (* F_115)( struct V_223 * V_224 ) )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_204 V_222 = {
. V_208 = V_210 ,
} ;
T_1 V_149 ;
int V_21 ;
if ( ! F_22 ( V_2 , V_262 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_21 = F_120 ( V_2 , V_60 , & V_149 ) ;
if ( V_21 )
goto V_226;
V_21 = F_148 ( V_2 , V_149 , 0 , V_60 , V_261 , F_115 ) ;
if ( V_21 )
goto V_226;
V_21 = F_112 ( V_2 , V_222 . V_208 ) ;
if ( V_21 )
goto V_226;
do {
V_21 = F_113 ( V_2 , & V_222 ) ;
if ( V_21 )
break;
if ( ! V_222 . V_213 )
break;
V_21 = F_148 ( V_2 , V_222 . V_149 , V_222 . V_208 , V_60 ,
V_261 , F_115 ) ;
if ( V_21 )
break;
} while ( V_222 . V_208 < V_210 );
V_226:
F_14 ( & V_2 -> V_3 ) ;
return V_21 ;
}
static int F_151 ( struct V_19 * V_20 , int V_60 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_9 , V_21 = 0 ;
if ( ! F_22 ( V_2 , V_270 ) )
return - V_129 ;
F_13 ( & V_2 -> V_3 ) ;
V_2 -> V_182 [ V_60 ] . V_186 = V_185 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 ) {
if ( V_2 -> V_182 [ V_9 ] . V_186 == V_185 ) {
V_21 = F_94 ( V_2 , V_9 ) ;
if ( V_21 )
break;
}
}
F_14 ( & V_2 -> V_3 ) ;
return V_21 ;
}
static void F_152 ( struct V_19 * V_20 , int V_60 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_184 * V_185 = V_2 -> V_182 [ V_60 ] . V_186 ;
int V_9 ;
if ( ! F_22 ( V_2 , V_270 ) )
return;
F_13 ( & V_2 -> V_3 ) ;
V_2 -> V_182 [ V_60 ] . V_186 = NULL ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; ++ V_9 )
if ( V_9 == V_60 || V_2 -> V_182 [ V_9 ] . V_186 == V_185 )
if ( F_94 ( V_2 , V_9 ) )
F_130 ( V_20 -> V_182 [ V_9 ] , L_14 ) ;
F_14 ( & V_2 -> V_3 ) ;
}
static int F_153 ( struct V_1 * V_2 ,
int V_60 , int V_271 , int V_14 , int V_17 )
{
int V_8 ;
V_8 = F_83 ( V_2 , V_60 , 0x16 , V_271 ) ;
if ( V_8 < 0 )
goto V_272;
V_8 = F_83 ( V_2 , V_60 , V_14 , V_17 ) ;
V_272:
F_83 ( V_2 , V_60 , 0x16 , 0x0 ) ;
return V_8 ;
}
static int F_154 ( struct V_1 * V_2 ,
int V_60 , int V_271 , int V_14 )
{
int V_8 ;
V_8 = F_83 ( V_2 , V_60 , 0x16 , V_271 ) ;
if ( V_8 < 0 )
goto V_272;
V_8 = F_82 ( V_2 , V_60 , V_14 ) ;
V_272:
F_83 ( V_2 , V_60 , 0x16 , 0x0 ) ;
return V_8 ;
}
static int F_155 ( struct V_1 * V_2 )
{
bool V_273 = F_22 ( V_2 , V_274 ) ;
T_1 V_275 = ( V_273 ? 0x8800 : 0xc800 ) ;
struct V_276 * V_277 = V_2 -> V_278 ;
unsigned long V_32 ;
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; V_9 ++ ) {
V_8 = F_10 ( V_2 , F_57 ( V_9 ) , V_176 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_9 ) , V_176 ,
V_8 & 0xfffc ) ;
if ( V_8 )
return V_8 ;
}
F_27 ( 2000 , 4000 ) ;
if ( V_277 ) {
F_156 ( V_277 , 1 ) ;
F_27 ( 10000 , 20000 ) ;
F_156 ( V_277 , 0 ) ;
F_27 ( 10000 , 20000 ) ;
}
if ( V_273 )
V_8 = F_16 ( V_2 , V_22 , 0x04 , 0xc000 ) ;
else
V_8 = F_16 ( V_2 , V_22 , 0x04 , 0xc400 ) ;
if ( V_8 )
return V_8 ;
V_32 = V_35 + 1 * V_36 ;
while ( F_26 ( V_35 , V_32 ) ) {
V_8 = F_10 ( V_2 , V_22 , 0x00 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 & V_275 ) == V_275 )
break;
F_27 ( 1000 , 2000 ) ;
}
if ( F_157 ( V_35 , V_32 ) )
V_8 = - V_12 ;
else
V_8 = 0 ;
return V_8 ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_154 ( V_2 , V_279 , V_280 ,
V_281 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_282 ) {
V_8 &= ~ V_282 ;
V_8 = F_153 ( V_2 , V_279 ,
V_280 , V_281 ,
V_8 ) ;
}
return V_8 ;
}
static int F_159 ( struct V_1 * V_2 , int V_60 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
int V_8 ;
T_1 V_14 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_49 ( V_2 ) || F_46 ( V_2 ) ||
F_45 ( V_2 ) || F_50 ( V_2 ) ) {
V_14 = F_10 ( V_2 , F_57 ( V_60 ) , V_63 ) ;
if ( F_95 ( V_20 , V_60 ) || F_96 ( V_20 , V_60 ) ) {
V_14 &= ~ V_69 ;
V_14 |= V_66 |
V_65 |
V_67 |
V_68 ;
if ( F_45 ( V_2 ) )
V_14 |= V_75 ;
else
V_14 |= V_74 ;
} else {
V_14 |= V_69 ;
}
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_63 , V_14 ) ;
if ( V_8 )
return V_8 ;
}
V_14 = 0 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_46 ( V_2 ) || F_45 ( V_2 ) ||
F_49 ( V_2 ) || F_50 ( V_2 ) )
V_14 = V_283 |
V_284 | V_285 |
V_179 ;
if ( F_95 ( V_20 , V_60 ) ) {
if ( F_46 ( V_2 ) || F_49 ( V_2 ) )
V_14 |= V_286 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_50 ( V_2 ) ) {
if ( V_20 -> V_287 -> V_288 == V_289 )
V_14 |= V_290 ;
else
V_14 |= V_291 ;
V_14 |= V_292 |
V_293 ;
}
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_46 ( V_2 ) || F_45 ( V_2 ) ||
F_49 ( V_2 ) || F_50 ( V_2 ) ) {
if ( V_20 -> V_287 -> V_288 == V_289 )
V_14 |= V_294 ;
}
}
if ( F_96 ( V_20 , V_60 ) ) {
if ( F_46 ( V_2 ) || F_49 ( V_2 ) )
V_14 |= V_286 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_50 ( V_2 ) ) {
V_14 |= V_291 ;
}
if ( V_60 == F_160 ( V_20 ) )
V_14 |= V_292 |
V_293 ;
}
if ( V_14 ) {
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_176 , V_14 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_52 ( V_2 ) ) {
V_8 = F_10 ( V_2 , F_57 ( V_60 ) , V_146 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 &= V_295 ;
if ( ( V_8 == V_296 ) ||
( V_8 == V_297 ) ||
( V_8 == V_298 ) ) {
V_8 = F_158 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
}
}
V_14 = 0 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_46 ( V_2 ) || F_50 ( V_2 ) ||
F_49 ( V_2 ) )
V_14 = V_299 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_50 ( V_2 ) )
V_14 |= V_300 ;
if ( F_46 ( V_2 ) || F_49 ( V_2 ) ) {
V_14 |= F_160 ( V_20 ) ;
if ( V_60 == F_160 ( V_20 ) )
V_14 |= V_301 ;
}
V_14 |= V_249 ;
if ( V_14 ) {
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_250 , V_14 ) ;
if ( V_8 )
return V_8 ;
}
V_14 = 1 << V_60 ;
if ( F_95 ( V_20 , V_60 ) )
V_14 = 0 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_302 , V_14 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_303 ,
0x0000 ) ;
if ( V_8 )
return V_8 ;
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_50 ( V_2 ) ) {
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_304 , 0x0000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_305 , 0x0000 ) ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_306 , 0x0000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_307 , V_308 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_309 , 0x3210 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_310 , 0x7654 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_49 ( V_2 ) || F_46 ( V_2 ) ||
F_50 ( V_2 ) ) {
V_8 = F_16 ( V_2 , F_57 ( V_60 ) ,
V_311 , 0x0001 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_240 , 0x0000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_121 ( V_2 , V_60 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_94 ( V_2 , V_60 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 , F_57 ( V_60 ) , V_199 ,
0x0000 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_3 V_312 = F_160 ( V_20 ) ;
T_1 V_14 ;
int V_21 ;
int V_9 ;
V_14 = 0 ;
if ( F_22 ( V_2 , V_313 ) ||
F_22 ( V_2 , V_274 ) )
V_14 |= V_34 ;
V_21 = F_16 ( V_2 , V_22 , V_33 , V_14 ) ;
if ( V_21 )
return V_21 ;
V_14 = V_312 << V_314 |
V_312 << V_315 |
V_312 << V_316 ;
V_21 = F_16 ( V_2 , V_22 , V_317 , V_14 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_318 ,
V_319 |
( V_20 -> V_320 & 0x1f ) ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_152 ,
0x0140 | V_321 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_322 , 0x0000 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_323 , 0x0000 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_324 , 0x5555 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_325 , 0x5555 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_326 , 0xaaaa ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_327 , 0xaaaa ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_328 , 0xffff ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_329 , 0xffff ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_22 , V_330 , 0xfa41 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_27 , V_331 , 0xffff ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_27 , V_332 ,
0x7 | V_333 | 0x70 |
V_334 ) ;
if ( V_21 )
return V_21 ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
int V_335 = 0x1f ;
if ( V_2 -> V_20 -> V_336 -> V_337 &&
V_9 != V_2 -> V_20 -> V_320 && V_9 < V_2 -> V_20 -> V_287 -> V_338 -> V_339 )
V_335 = V_2 -> V_20 -> V_336 -> V_337 [ V_9 ] & 0x1f ;
V_21 = F_16 (
V_2 , V_27 ,
V_340 ,
V_341 |
( V_9 << V_342 ) | V_335 ) ;
if ( V_21 )
return V_21 ;
}
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_21 = F_16 ( V_2 , V_27 , V_343 ,
0x8000 |
( V_9 << V_344 ) |
( ( 1 << V_2 -> V_49 -> V_80 ) - 1 ) ) ;
if ( V_21 )
return V_21 ;
}
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
V_21 = F_16 (
V_2 , V_27 ,
V_345 ,
V_346 |
( V_9 << V_347 ) ) ;
if ( V_21 )
return V_21 ;
}
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_50 ( V_2 ) ) {
V_21 = F_16 ( V_2 , V_27 ,
V_348 , 0xffff ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_27 ,
V_349 , 0x9000 ) ;
if ( V_21 )
return V_21 ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
V_21 = F_16 ( V_2 , V_27 ,
V_350 ,
0x8000 | ( V_9 << 8 ) ) ;
if ( V_21 )
return V_21 ;
}
}
if ( F_52 ( V_2 ) || F_51 ( V_2 ) ||
F_48 ( V_2 ) || F_47 ( V_2 ) ||
F_49 ( V_2 ) || F_46 ( V_2 ) ||
F_50 ( V_2 ) ) {
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; V_9 ++ ) {
V_21 = F_16 ( V_2 , V_27 ,
V_351 ,
0x9000 | ( V_9 << 8 ) ) ;
if ( V_21 )
return V_21 ;
}
}
V_21 = F_16 ( V_2 , V_22 , V_87 ,
V_352 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_59 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_89 ( V_2 , 0 , true ) ;
if ( V_21 )
return V_21 ;
V_21 = F_105 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_21 ;
}
static int F_162 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_21 ;
int V_9 ;
V_2 -> V_20 = V_20 ;
if ( F_22 ( V_2 , V_124 ) )
F_40 ( & V_2 -> V_120 ) ;
if ( F_22 ( V_2 , V_313 ) )
F_39 ( V_2 ) ;
F_13 ( & V_2 -> V_3 ) ;
V_21 = F_155 ( V_2 ) ;
if ( V_21 )
goto V_226;
V_21 = F_161 ( V_2 ) ;
if ( V_21 )
goto V_226;
for ( V_9 = 0 ; V_9 < V_2 -> V_49 -> V_80 ; V_9 ++ ) {
V_21 = F_159 ( V_2 , V_9 ) ;
if ( V_21 )
goto V_226;
}
V_226:
F_14 ( & V_2 -> V_3 ) ;
return V_21 ;
}
int F_163 ( struct V_19 * V_20 , int V_60 , int V_271 , int V_14 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_154 ( V_2 , V_60 , V_271 , V_14 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
int F_164 ( struct V_19 * V_20 , int V_60 , int V_271 ,
int V_14 , int V_17 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_153 ( V_2 , V_60 , V_271 , V_14 , V_17 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_165 ( struct V_1 * V_2 ,
int V_60 )
{
if ( V_60 >= 0 && V_60 < V_2 -> V_49 -> V_80 )
return V_60 ;
return - V_135 ;
}
static int F_166 ( struct V_19 * V_20 , int V_60 , int V_31 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_13 = F_165 ( V_2 , V_60 ) ;
int V_8 ;
if ( V_13 < 0 )
return 0xffff ;
F_13 ( & V_2 -> V_3 ) ;
if ( F_22 ( V_2 , V_313 ) )
V_8 = F_43 ( V_2 , V_13 , V_31 ) ;
else if ( F_22 ( V_2 , V_353 ) )
V_8 = F_82 ( V_2 , V_13 , V_31 ) ;
else
V_8 = F_23 ( V_2 , V_13 , V_31 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_167 ( struct V_19 * V_20 , int V_60 , int V_31 ,
T_1 V_17 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_13 = F_165 ( V_2 , V_60 ) ;
int V_8 ;
if ( V_13 < 0 )
return 0xffff ;
F_13 ( & V_2 -> V_3 ) ;
if ( F_22 ( V_2 , V_313 ) )
V_8 = F_44 ( V_2 , V_13 , V_31 , V_17 ) ;
else if ( F_22 ( V_2 , V_353 ) )
V_8 = F_83 ( V_2 , V_13 , V_31 , V_17 ) ;
else
V_8 = F_24 ( V_2 , V_13 , V_31 , V_17 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_168 ( struct V_19 * V_20 , int * V_354 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_8 ;
int V_17 ;
* V_354 = 0 ;
F_13 ( & V_2 -> V_3 ) ;
V_8 = F_24 ( V_2 , 0x0 , 0x16 , 0x6 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_23 ( V_2 , 0x0 , 0x1a ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_24 ( V_2 , 0x0 , 0x1a , V_8 | ( 1 << 5 ) ) ;
if ( V_8 < 0 )
goto error;
F_27 ( 10000 , 12000 ) ;
V_17 = F_23 ( V_2 , 0x0 , 0x1a ) ;
if ( V_17 < 0 ) {
V_8 = V_17 ;
goto error;
}
V_8 = F_24 ( V_2 , 0x0 , 0x1a , V_8 & ~ ( 1 << 5 ) ) ;
if ( V_8 < 0 )
goto error;
* V_354 = ( ( V_17 & 0x1f ) - 5 ) * 5 ;
error:
F_24 ( V_2 , 0x0 , 0x16 , 0x0 ) ;
F_14 ( & V_2 -> V_3 ) ;
return V_8 ;
}
static int F_169 ( struct V_19 * V_20 , int * V_354 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_355 = F_50 ( V_2 ) ? 3 : 0 ;
int V_8 ;
* V_354 = 0 ;
V_8 = F_163 ( V_20 , V_355 , 6 , 27 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_354 = ( V_8 & 0xff ) - 25 ;
return 0 ;
}
static int F_170 ( struct V_19 * V_20 , int * V_354 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
if ( ! F_22 ( V_2 , V_356 ) )
return - V_129 ;
if ( F_50 ( V_2 ) || F_52 ( V_2 ) )
return F_169 ( V_20 , V_354 ) ;
return F_168 ( V_20 , V_354 ) ;
}
static int F_171 ( struct V_19 * V_20 , int * V_354 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_355 = F_50 ( V_2 ) ? 3 : 0 ;
int V_8 ;
if ( ! F_22 ( V_2 , V_357 ) )
return - V_129 ;
* V_354 = 0 ;
V_8 = F_163 ( V_20 , V_355 , 6 , 26 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_354 = ( ( ( V_8 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
static int F_172 ( struct V_19 * V_20 , int V_354 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_355 = F_50 ( V_2 ) ? 3 : 0 ;
int V_8 ;
if ( ! F_22 ( V_2 , V_357 ) )
return - V_129 ;
V_8 = F_163 ( V_20 , V_355 , 6 , 26 ) ;
if ( V_8 < 0 )
return V_8 ;
V_354 = F_173 ( F_174 ( V_354 , 5 ) + 5 , 0 , 0x1f ) ;
return F_164 ( V_20 , V_355 , 6 , 26 ,
( V_8 & 0xe0ff ) | ( V_354 << 8 ) ) ;
}
static int F_175 ( struct V_19 * V_20 , bool * V_358 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
int V_355 = F_50 ( V_2 ) ? 3 : 0 ;
int V_8 ;
if ( ! F_22 ( V_2 , V_357 ) )
return - V_129 ;
* V_358 = false ;
V_8 = F_163 ( V_20 , V_355 , 6 , 26 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_358 = ! ! ( V_8 & 0x40 ) ;
return 0 ;
}
static const struct V_359 *
F_176 ( unsigned int V_360 , const struct V_359 * V_361 ,
unsigned int V_362 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_362 ; ++ V_9 )
if ( V_361 [ V_9 ] . V_360 == V_360 )
return & V_361 [ V_9 ] ;
return NULL ;
}
static const char * F_177 ( struct V_363 * V_364 ,
struct V_363 * V_365 , int V_7 ,
void * * V_366 )
{
const struct V_359 * V_49 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
const char * V_367 ;
int V_368 , V_360 , V_369 ;
V_6 = F_178 ( V_365 ) ;
if ( ! V_6 )
return NULL ;
V_368 = F_8 ( V_6 , V_7 , F_57 ( 0 ) , V_370 ) ;
if ( V_368 < 0 )
return NULL ;
V_360 = ( V_368 & 0xfff0 ) >> 4 ;
V_369 = V_368 & 0x000f ;
V_49 = F_176 ( V_360 , V_371 ,
F_65 ( V_371 ) ) ;
if ( ! V_49 )
return NULL ;
V_367 = V_49 -> V_367 ;
V_2 = F_179 ( V_364 , sizeof( * V_2 ) , V_372 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_49 = V_49 ;
F_40 ( & V_2 -> V_3 ) ;
* V_366 = V_2 ;
F_180 ( & V_2 -> V_6 -> V_4 , L_15 ,
V_360 , V_367 , V_369 ) ;
return V_367 ;
}
int F_181 ( struct V_373 * V_374 )
{
struct V_363 * V_4 = & V_374 -> V_4 ;
struct V_375 * V_376 = V_4 -> V_377 ;
struct V_1 * V_2 ;
int V_368 , V_360 , V_369 ;
struct V_19 * V_20 ;
T_3 V_125 ;
int V_21 ;
V_20 = F_179 ( V_4 , sizeof( * V_20 ) + sizeof( * V_2 ) , V_372 ) ;
if ( ! V_20 )
return - V_378 ;
V_2 = (struct V_1 * ) ( V_20 + 1 ) ;
V_20 -> V_366 = V_2 ;
V_20 -> V_4 = V_4 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_6 = V_374 -> V_6 ;
V_2 -> V_7 = V_374 -> V_13 ;
F_40 ( & V_2 -> V_3 ) ;
F_182 ( & V_2 -> V_6 -> V_4 ) ;
V_20 -> V_379 = & V_380 ;
V_368 = F_12 ( V_2 , F_57 ( 0 ) , V_370 ) ;
if ( V_368 < 0 )
return V_368 ;
V_360 = ( V_368 & 0xfff0 ) >> 4 ;
V_369 = V_368 & 0x000f ;
V_2 -> V_49 = F_176 ( V_360 , V_371 ,
F_65 ( V_371 ) ) ;
if ( ! V_2 -> V_49 )
return - V_381 ;
V_2 -> V_278 = F_183 ( & V_374 -> V_4 , L_16 , V_382 ) ;
if ( F_184 ( V_2 -> V_278 ) ) {
V_21 = F_185 ( V_2 -> V_278 ) ;
if ( V_21 == - V_383 ) {
V_2 -> V_278 = NULL ;
} else {
return V_21 ;
}
}
if ( F_22 ( V_2 , V_124 ) &&
! F_186 ( V_376 , L_17 , & V_125 ) )
V_2 -> V_125 = V_125 ;
F_187 ( V_4 , V_20 ) ;
F_180 ( V_4 , L_15 ,
V_360 , V_2 -> V_49 -> V_367 , V_369 ) ;
return 0 ;
}
static void F_188 ( struct V_373 * V_374 )
{
struct V_19 * V_20 = F_189 ( & V_374 -> V_4 ) ;
struct V_1 * V_2 = F_19 ( V_20 ) ;
F_190 ( & V_2 -> V_6 -> V_4 ) ;
}
static int T_7 F_191 ( void )
{
F_192 ( & V_380 ) ;
return F_193 ( & V_384 ) ;
}
static void T_8 F_194 ( void )
{
F_195 ( & V_384 ) ;
F_196 ( & V_380 ) ;
}
