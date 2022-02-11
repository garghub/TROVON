static T_1 T_2 * F_1 ( void T_2 * V_1 , int V_2 )
{
return V_1 + V_3 +
V_4 * V_2 ;
}
static void F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 T_2 * V_9 = F_1 ( V_8 -> V_1 , V_10 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ )
F_4 ( 0xffffffff , V_9 + V_11 ) ;
}
static int F_5 ( struct V_5 * V_6 ,
unsigned int V_12 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 T_2 * V_9 = F_1 ( V_8 -> V_1 , V_10 ) ;
unsigned long V_13 ;
for ( V_13 = 20 ; V_13 ; V_13 -- ) {
if ( ! F_6 ( V_9 + 3 ) )
return 0 ;
F_7 ( 10 ) ;
}
V_13 = V_14 + F_8 ( V_12 ) ;
do {
if ( ! F_6 ( V_9 + 3 ) )
return 0 ;
F_9 ( 1 ) ;
} while ( F_10 ( V_14 , V_13 ) );
return - V_15 ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( V_16 + V_17 , V_8 -> V_18 + V_19 ) ;
F_4 ( V_16 + V_17 , V_8 -> V_18 + V_20 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
unsigned int V_12 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_13 = V_14 + F_8 ( V_12 ) ;
do {
if ( F_6 ( V_8 -> V_18 + V_19 ) == F_6 ( V_8 -> V_18 + V_20 ) )
return 0 ;
F_9 ( 1 ) ;
} while ( F_10 ( V_14 , V_13 ) );
F_13 ( & V_6 -> V_21 , L_1 ,
F_6 ( V_8 -> V_18 + V_19 ) , F_6 ( V_8 -> V_18 + V_20 ) ,
F_6 ( V_8 -> V_18 + V_22 ) ) ;
return - V_15 ;
}
static void F_14 ( struct V_7 * V_8 , T_1 V_23 )
{
* ( V_8 -> V_24 ) ++ = V_23 ;
}
static void F_15 ( struct V_7 * V_8 , T_1 V_25 , T_1 V_26 ,
T_1 V_27 )
{
F_14 ( V_8 , ( V_27 << 18 ) | ( V_25 << 13 ) | V_26 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
F_14 ( V_8 , 0x20000000 | ( V_16 + V_17 ) ) ;
F_4 ( V_16 + V_17 , V_8 -> V_18 + V_19 ) ;
V_28 = F_17 ( V_8 -> V_29 , 0 , 0 , 0 , 0 ) ;
if ( V_28 )
F_18 ( & V_6 -> V_21 , L_2 ,
V_30 , V_28 ) ;
V_8 -> V_24 = V_8 -> V_31 ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
F_20 ( & V_32 ) ;
F_4 ( V_16 + V_17 + ( V_8 -> V_24 - V_8 -> V_31 )
* sizeof( T_1 ) , V_8 -> V_18 + V_19 ) ;
V_28 = F_17 ( V_8 -> V_29 , 0 , 0 , 0 , 0 ) ;
if ( V_28 )
F_18 ( & V_6 -> V_21 , L_2 ,
V_30 , V_28 ) ;
if ( ( V_8 -> V_24 - V_8 -> V_31 ) * sizeof( T_1 ) >
V_33 - 1024 ) {
F_21 ( & V_6 -> V_21 , L_3 ) ;
F_12 ( V_6 , 200 ) ;
F_16 ( V_6 ) ;
}
F_22 ( & V_32 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_15 ( V_8 , V_34 , 0 , 1 ) ;
F_14 ( V_8 , 0x31337303 ) ;
F_15 ( V_8 , V_34 , 0x180 , 3 ) ;
F_14 ( V_8 , V_35 + V_10 ) ;
F_14 ( V_8 , 0xfeed0001 ) ;
F_14 ( V_8 , 0xfeed0000 ) ;
F_15 ( V_8 , V_36 , 0 , 1 ) ;
F_14 ( V_8 , 0x3137c0de ) ;
F_15 ( V_8 , V_36 , 0x180 , 3 ) ;
F_14 ( V_8 , V_35 + V_10 ) ;
F_14 ( V_8 , 0xfeed0000 ) ;
F_14 ( V_8 , 0xfeed0001 ) ;
F_19 ( V_6 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
unsigned int V_37 , unsigned int V_38 ,
int V_39 , int V_40 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_15 ( V_8 , V_34 ,
V_41 , 8 ) ;
F_14 ( V_8 , V_42 + V_37 ) ;
F_14 ( V_8 , V_38 ) ;
F_14 ( V_8 , V_39 ) ;
F_14 ( V_8 , V_39 ) ;
F_14 ( V_8 , V_39 ) ;
F_14 ( V_8 , V_40 ) ;
F_14 ( V_8 , ( 1 << 8 ) | 1 ) ;
F_14 ( V_8 , 0 ) ;
F_2 ( V_6 ) ;
F_15 ( V_8 , V_34 ,
V_43 , 1 ) ;
F_14 ( V_8 , 0 ) ;
F_15 ( V_8 , V_34 , 0x100 , 1 ) ;
F_14 ( V_8 , 0 ) ;
F_19 ( V_6 ) ;
if ( F_5 ( V_6 , 200 ) < 0 ) {
F_13 ( & V_6 -> V_21 , L_4 , V_30 ) ;
return - 1 ;
}
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
unsigned int V_37 , unsigned int V_38 ,
int V_39 , int V_40 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_15 ( V_8 , V_36 ,
V_41 , 8 ) ;
F_14 ( V_8 , V_37 ) ;
F_14 ( V_8 , V_42 + V_38 ) ;
F_14 ( V_8 , V_39 ) ;
F_14 ( V_8 , V_39 ) ;
F_14 ( V_8 , V_39 ) ;
F_14 ( V_8 , V_40 ) ;
F_14 ( V_8 , ( 1 << 8 ) | 1 ) ;
F_14 ( V_8 , 0 ) ;
F_2 ( V_6 ) ;
F_15 ( V_8 , V_36 ,
V_43 , 1 ) ;
F_14 ( V_8 , 0 ) ;
F_15 ( V_8 , V_36 , 0x100 , 1 ) ;
F_14 ( V_8 , 0 ) ;
F_19 ( V_6 ) ;
if ( F_5 ( V_6 , 200 ) < 0 ) {
F_13 ( & V_6 -> V_21 , L_4 , V_30 ) ;
return - 1 ;
}
return 0 ;
}
static void F_26 ( struct V_5 * V_6 , int V_44 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
if ( ! ( V_46 -> V_47 [ V_44 ] . V_48 & V_49 ) )
return;
F_21 ( & V_6 -> V_21 , L_5 , V_44 ,
V_46 -> V_47 [ V_44 ] . V_50 ) ;
if ( F_24 ( V_6 , V_51 + V_44 * V_46 -> V_52 ,
V_46 -> V_47 [ V_44 ] . V_50 , V_53 ,
V_46 -> V_52 / V_53 ) < 0 ) {
F_18 ( & V_6 -> V_21 ,
L_6 L_7 ,
V_44 * V_46 -> V_52 , V_46 -> V_47 [ V_44 ] . V_50 ,
V_46 -> V_52 ) ;
}
V_46 -> V_47 [ V_44 ] . V_48 &= ~ V_49 ;
}
static void F_27 ( struct V_5 * V_6 , int V_44 ,
unsigned int V_50 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
F_21 ( & V_6 -> V_21 , L_8 , V_44 , V_50 ) ;
if ( F_25 ( V_6 , V_50 ,
V_51 + V_44 * V_46 -> V_52 ,
V_53 ,
V_46 -> V_52 / V_53 ) < 0 ) {
F_18 ( & V_6 -> V_21 ,
L_9 ,
V_50 , V_44 * V_46 -> V_52 , V_46 -> V_52 ) ;
}
V_46 -> V_47 [ V_44 ] . V_50 = V_50 ;
V_46 -> V_47 [ V_44 ] . V_48 |= V_54 ;
}
static void F_28 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
int V_11 ;
F_21 ( & V_6 -> V_21 , L_10 ) ;
for ( V_11 = 0 ; V_11 < V_46 -> V_55 ; V_11 ++ ) {
F_26 ( V_6 , V_11 ) ;
V_46 -> V_47 [ V_11 ] . V_48 = 0 ;
}
}
static unsigned int F_29 ( struct V_5 * V_6 ,
T_3 V_50 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
unsigned int V_56 ;
unsigned int V_57 ;
int V_11 ;
static int V_58 ;
V_57 = ( unsigned int ) ( V_50 & ( V_46 -> V_52 - 1 ) ) ;
V_56 = ( unsigned int ) ( V_50 - V_57 ) ;
for ( V_11 = 0 ; V_11 < V_46 -> V_55 ; V_11 ++ ) {
if ( ( V_46 -> V_47 [ V_11 ] . V_48 & V_54 ) &&
V_46 -> V_47 [ V_11 ] . V_50 == V_56 ) {
V_46 -> V_59 ++ ;
F_21 ( & V_6 -> V_21 , L_11 , V_11 ,
V_46 -> V_47 [ V_11 ] . V_50 ) ;
return V_11 ;
}
}
V_11 = ( V_14 + ( V_58 ++ ) ) % V_46 -> V_55 ;
F_21 ( & V_6 -> V_21 , L_12 , V_11 ) ;
F_26 ( V_6 , V_11 ) ;
F_27 ( V_6 , V_11 , V_56 ) ;
V_46 -> V_60 ++ ;
return V_11 ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_46 . V_55 = V_61 ;
V_8 -> V_46 . V_52 = V_62 ;
V_8 -> V_46 . V_47 = F_31 ( sizeof( struct V_63 ) *
V_61 , V_64 ) ;
if ( V_8 -> V_46 . V_47 == NULL ) {
F_18 ( & V_6 -> V_21 , L_13 ) ;
return - V_65 ;
}
F_32 ( & V_6 -> V_21 , L_14 ,
V_61 , V_62 / 1024 ) ;
return 0 ;
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_28 ( V_6 ) ;
F_34 ( V_8 -> V_46 . V_47 ) ;
}
static int F_35 ( struct V_5 * V_6 , T_3 V_66 ,
T_4 V_39 , T_4 * V_67 , T_5 * V_68 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_69 , V_40 ;
F_21 ( & V_6 -> V_21 , L_15 , V_30 ,
( unsigned int ) V_66 , V_39 ) ;
if ( V_66 >= V_8 -> V_27 )
return - V_70 ;
if ( V_39 > V_8 -> V_27 - V_66 )
V_39 = V_8 -> V_27 - V_66 ;
V_40 = V_39 ;
while ( V_40 ) {
unsigned int V_57 , V_71 ;
unsigned int V_44 ;
V_57 = ( unsigned int ) ( V_66 & ( V_8 -> V_46 . V_52 - 1 ) ) ;
V_71 = V_8 -> V_46 . V_52 - V_57 ;
V_44 = F_29 ( V_6 , V_66 ) ;
V_69 = V_51 + V_44 * V_8 -> V_46 . V_52 + V_57 ;
F_21 ( & V_6 -> V_21 , L_16
L_17 , V_30 ,
( unsigned int ) V_66 , V_69 , V_57 , V_71 , V_40 ) ;
if ( V_71 > V_40 )
V_71 = V_40 ;
memcpy ( V_68 , V_8 -> V_72 + V_69 , V_71 ) ;
V_68 += V_71 ;
V_40 -= V_71 ;
V_66 += V_71 ;
}
* V_67 = V_39 ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 , T_3 V_73 ,
T_4 V_39 , T_4 * V_67 , const T_5 * V_68 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_69 , V_40 ;
if ( V_73 >= V_8 -> V_27 )
return - V_70 ;
if ( V_39 > V_8 -> V_27 - V_73 )
V_39 = V_8 -> V_27 - V_73 ;
V_40 = V_39 ;
while ( V_40 ) {
unsigned int V_57 , V_71 ;
unsigned int V_44 ;
V_57 = ( unsigned int ) ( V_73 & ( V_8 -> V_46 . V_52 - 1 ) ) ;
V_71 = V_8 -> V_46 . V_52 - V_57 ;
V_44 = F_29 ( V_6 , V_73 ) ;
V_69 = V_51 + V_44 * V_8 -> V_46 . V_52 + V_57 ;
F_21 ( & V_6 -> V_21 , L_18
L_17 , V_30 , ( unsigned int ) V_73 ,
V_69 , V_57 , V_71 , V_40 ) ;
if ( V_71 > V_40 )
V_71 = V_40 ;
memcpy ( V_8 -> V_72 + V_69 , V_68 , V_71 ) ;
V_8 -> V_46 . V_47 [ V_44 ] . V_48 |= V_49 ;
V_68 += V_71 ;
V_40 -= V_71 ;
V_73 += V_71 ;
}
* V_67 = V_39 ;
return 0 ;
}
static int F_37 ( struct V_74 * V_75 , void * V_76 )
{
struct V_7 * V_8 = V_75 -> V_77 ;
F_38 ( V_75 , L_19 , V_8 -> V_46 . V_59 , V_8 -> V_46 . V_60 ) ;
return 0 ;
}
static int F_39 ( struct V_78 * V_78 , struct V_79 * V_79 )
{
return F_40 ( V_79 , F_37 , F_41 ( V_78 ) ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_80 * V_81 ;
V_81 = F_43 ( V_82 , 0444 , NULL , & V_83 ,
V_8 ) ;
if ( ! V_81 )
F_13 ( & V_6 -> V_21 , L_20 ) ;
}
static struct V_84 * F_44 ( struct V_5 * V_6 ,
struct V_84 * V_84 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_85 = F_45 ( V_84 ) == V_86 ;
const char * V_87 = V_85 ? L_21 : L_22 ;
T_3 V_57 = V_84 -> V_88 . V_89 << 9 ;
int error = 0 ;
struct V_90 V_91 ;
struct V_92 V_93 ;
struct V_84 * V_94 ;
F_46 (bvec, bio, iter) {
char * V_95 = F_47 ( V_91 . V_96 ) + V_91 . V_97 ;
T_4 V_39 = V_91 . V_98 , V_67 ;
F_21 ( & V_6 -> V_21 , L_23 , V_87 ,
V_39 , V_57 ) ;
if ( V_85 )
error = F_36 ( V_6 , V_57 , V_39 , & V_67 , V_95 ) ;
else
error = F_35 ( V_6 , V_57 , V_39 , & V_67 , V_95 ) ;
if ( error ) {
F_18 ( & V_6 -> V_21 , L_24 , V_87 ) ;
goto V_99;
}
if ( V_67 != V_39 ) {
F_18 ( & V_6 -> V_21 , L_25 , V_87 ) ;
error = - V_70 ;
goto V_99;
}
V_57 += V_39 ;
}
F_21 ( & V_6 -> V_21 , L_26 , V_87 ) ;
V_99:
F_48 ( & V_8 -> V_100 ) ;
F_49 ( & V_8 -> V_101 ) ;
V_94 = F_50 ( & V_8 -> V_101 ) ;
F_51 ( & V_8 -> V_100 ) ;
V_84 -> V_102 = error ;
F_52 ( V_84 ) ;
return V_94 ;
}
static T_6 F_53 ( struct V_103 * V_104 , struct V_84 * V_84 )
{
struct V_5 * V_6 = V_104 -> V_105 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_106 ;
F_21 ( & V_6 -> V_21 , L_27 , V_30 ) ;
F_54 ( V_104 , & V_84 , V_104 -> V_107 ) ;
F_48 ( & V_8 -> V_100 ) ;
V_106 = ! F_55 ( & V_8 -> V_101 ) ;
F_56 ( & V_8 -> V_101 , V_84 ) ;
F_51 ( & V_8 -> V_100 ) ;
if ( V_106 )
return V_108 ;
do {
V_84 = F_44 ( V_6 , V_84 ) ;
} while ( V_84 );
return V_108 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int error , V_28 ;
struct V_103 * V_109 ;
struct V_110 * V_110 ;
T_7 V_111 , V_112 , V_113 , V_114 , V_115 ,
V_116 , V_117 ;
char * V_118 ;
V_8 = F_31 ( sizeof( * V_8 ) , V_64 ) ;
if ( ! V_8 ) {
error = - V_65 ;
goto V_119;
}
F_58 ( & V_8 -> V_100 ) ;
F_59 ( & V_8 -> V_101 ) ;
F_60 ( V_6 , V_8 ) ;
V_8 -> V_72 = ( void * ) F_61 ( V_64 ,
F_62 ( V_120 ) ) ;
if ( V_8 -> V_72 == NULL ) {
F_18 ( & V_6 -> V_21 , L_28 ) ;
error = - V_65 ;
goto V_121;
}
V_8 -> V_31 = ( T_1 * ) ( V_8 -> V_72 + V_17 ) ;
V_8 -> V_24 = V_8 -> V_31 ;
if ( F_63 ( V_6 ) ) {
F_18 ( & V_6 -> V_21 , L_29 ) ;
error = - V_122 ;
goto V_123;
}
V_28 = - 1 ;
V_111 = F_64 ( F_65 ( V_27 , & V_118 ) , 1024 * 1024 ) ;
if ( ! V_111 ) {
F_18 ( & V_6 -> V_21 , L_30 ) ;
error = - V_124 ;
goto V_125;
}
while ( V_111 > 0 ) {
V_28 = F_66 ( V_111 , 0 , 0 , 0 , 0 ,
& V_8 -> V_126 ,
& V_112 ) ;
if ( ! V_28 )
break;
V_111 -= 1024 * 1024 ;
}
if ( V_28 ) {
F_18 ( & V_6 -> V_21 , L_31 ,
V_28 ) ;
error = - V_65 ;
goto V_125;
}
V_28 = F_67 ( V_8 -> V_126 , 0 ,
& V_8 -> V_29 , & V_113 ,
& V_114 , & V_115 ,
& V_116 ) ;
if ( V_28 ) {
F_18 ( & V_6 -> V_21 , L_32 ,
V_28 ) ;
error = - V_65 ;
goto V_127;
}
V_117 = F_68 ( F_69 ( V_8 -> V_72 ) ) ;
V_28 = F_70 ( V_8 -> V_29 , V_42 ,
V_117 , V_120 ,
V_128 | V_129 |
V_130 ) ;
if ( V_28 ) {
F_18 ( & V_6 -> V_21 , L_33 ,
V_28 ) ;
error = - V_65 ;
goto V_131;
}
V_8 -> V_18 = F_71 ( V_113 , 64 * 1024 ) ;
if ( ! V_8 -> V_18 ) {
F_18 ( & V_6 -> V_21 , L_34 ) ;
error = - V_65 ;
goto V_132;
}
V_8 -> V_1 = F_71 ( V_115 , V_116 ) ;
if ( ! V_8 -> V_1 ) {
F_18 ( & V_6 -> V_21 , L_35 ) ;
error = - V_65 ;
goto V_133;
}
F_20 ( & V_32 ) ;
F_11 ( V_6 ) ;
F_22 ( & V_32 ) ;
V_8 -> V_27 = V_111 ;
F_23 ( V_6 ) ;
F_20 ( & V_32 ) ;
error = F_12 ( V_6 , 100 ) ;
F_22 ( & V_32 ) ;
if ( error < 0 ) {
F_18 ( & V_6 -> V_21 , L_36 ) ;
error = - V_15 ;
goto V_134;
}
F_30 ( V_6 ) ;
F_42 ( V_6 ) ;
V_109 = F_72 ( V_64 ) ;
if ( ! V_109 ) {
F_18 ( & V_6 -> V_21 , L_37 ) ;
error = - V_65 ;
goto V_135;
}
V_8 -> V_109 = V_109 ;
V_109 -> V_105 = V_6 ;
F_73 ( V_109 , F_53 ) ;
F_74 ( V_109 , V_136 ) ;
F_75 ( V_109 , V_137 ) ;
F_76 ( V_109 , V_138 ) ;
V_110 = F_77 ( 1 ) ;
if ( ! V_110 ) {
F_18 ( & V_6 -> V_21 , L_38 ) ;
error = - V_65 ;
goto V_139;
}
V_8 -> V_110 = V_110 ;
V_110 -> V_140 = V_141 ;
V_110 -> V_142 = 0 ;
V_110 -> V_143 = & V_144 ;
V_110 -> V_109 = V_109 ;
V_110 -> V_145 = V_6 ;
V_110 -> V_146 = & V_6 -> V_21 ;
F_78 ( V_110 -> V_147 , V_82 , sizeof( V_110 -> V_147 ) ) ;
F_79 ( V_110 , V_8 -> V_27 >> 9 ) ;
F_32 ( & V_6 -> V_21 , L_39 ,
V_110 -> V_147 , F_80 ( V_110 ) >> 11 ) ;
F_81 ( V_110 ) ;
return 0 ;
V_139:
F_82 ( V_109 ) ;
V_135:
F_83 ( V_82 , NULL ) ;
F_33 ( V_6 ) ;
V_134:
F_84 ( V_8 -> V_1 ) ;
V_133:
F_84 ( V_8 -> V_18 ) ;
V_132:
F_70 ( V_8 -> V_29 , V_42 , V_117 ,
V_120 , V_130 ) ;
V_131:
F_85 ( V_8 -> V_29 ) ;
V_127:
F_86 ( V_8 -> V_126 ) ;
V_125:
F_87 ( V_6 ) ;
V_123:
F_88 ( ( unsigned long ) V_8 -> V_72 , F_62 ( V_120 ) ) ;
V_121:
F_34 ( V_8 ) ;
F_60 ( V_6 , NULL ) ;
V_119:
return error ;
}
static int F_89 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_90 ( V_8 -> V_110 ) ;
F_91 ( V_8 -> V_110 ) ;
F_82 ( V_8 -> V_109 ) ;
F_83 ( V_82 , NULL ) ;
F_33 ( V_6 ) ;
F_84 ( V_8 -> V_1 ) ;
F_84 ( V_8 -> V_18 ) ;
F_70 ( V_8 -> V_29 , V_42 ,
F_68 ( F_69 ( V_8 -> V_72 ) ) ,
V_120 , V_130 ) ;
F_85 ( V_8 -> V_29 ) ;
F_86 ( V_8 -> V_126 ) ;
F_87 ( V_6 ) ;
F_88 ( ( unsigned long ) V_8 -> V_72 , F_62 ( V_120 ) ) ;
F_34 ( V_8 ) ;
F_60 ( V_6 , NULL ) ;
return 0 ;
}
static int T_8 F_92 ( void )
{
int error ;
if ( ! F_93 ( V_148 ) )
return - V_149 ;
error = F_94 ( 0 , V_82 ) ;
if ( error <= 0 ) {
F_95 ( L_40 , V_82 , error ) ;
return error ;
}
V_141 = error ;
F_96 ( L_41 , V_82 ,
V_141 ) ;
error = F_97 ( & V_150 ) ;
if ( error )
F_98 ( V_141 , V_82 ) ;
return error ;
}
static void T_9 F_99 ( void )
{
F_100 ( & V_150 ) ;
F_98 ( V_141 , V_82 ) ;
}
