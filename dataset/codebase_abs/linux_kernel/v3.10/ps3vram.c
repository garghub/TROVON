static T_1 * F_1 ( void * V_1 , int V_2 )
{
return V_1 + V_3 +
V_4 * V_2 ;
}
static void F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 * V_9 = F_1 ( V_8 -> V_1 , V_10 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ )
V_9 [ V_11 ] = 0xffffffff ;
}
static int F_4 ( struct V_5 * V_6 ,
unsigned int V_12 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 * V_9 = F_1 ( V_8 -> V_1 , V_10 ) ;
unsigned long V_13 ;
for ( V_13 = 20 ; V_13 ; V_13 -- ) {
if ( ! V_9 [ 3 ] )
return 0 ;
F_5 ( 10 ) ;
}
V_13 = V_14 + F_6 ( V_12 ) ;
do {
if ( ! V_9 [ 3 ] )
return 0 ;
F_7 ( 1 ) ;
} while ( F_8 ( V_14 , V_13 ) );
return - V_15 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_16 [ V_17 ] = V_18 + V_19 ;
V_8 -> V_16 [ V_20 ] = V_18 + V_19 ;
}
static int F_10 ( struct V_5 * V_6 ,
unsigned int V_12 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_13 = V_14 + F_6 ( V_12 ) ;
do {
if ( V_8 -> V_16 [ V_17 ] == V_8 -> V_16 [ V_20 ] )
return 0 ;
F_7 ( 1 ) ;
} while ( F_8 ( V_14 , V_13 ) );
F_11 ( & V_6 -> V_21 , L_1 ,
V_8 -> V_16 [ V_17 ] , V_8 -> V_16 [ V_20 ] ,
V_8 -> V_16 [ V_22 ] ) ;
return - V_15 ;
}
static void F_12 ( struct V_7 * V_8 , T_1 V_23 )
{
* ( V_8 -> V_24 ) ++ = V_23 ;
}
static void F_13 ( struct V_7 * V_8 , T_1 V_25 , T_1 V_26 ,
T_1 V_27 )
{
F_12 ( V_8 , ( V_27 << 18 ) | ( V_25 << 13 ) | V_26 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
F_12 ( V_8 , 0x20000000 | ( V_18 + V_19 ) ) ;
V_8 -> V_16 [ V_17 ] = V_18 + V_19 ;
V_28 = F_15 ( V_8 -> V_29 , 0 , 0 , 0 , 0 ) ;
if ( V_28 )
F_16 ( & V_6 -> V_21 , L_2 ,
V_30 , V_28 ) ;
V_8 -> V_24 = V_8 -> V_31 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
F_18 ( & V_32 ) ;
V_8 -> V_16 [ V_17 ] = V_18 + V_19 +
( V_8 -> V_24 - V_8 -> V_31 ) * sizeof( T_1 ) ;
V_28 = F_15 ( V_8 -> V_29 , 0 , 0 , 0 , 0 ) ;
if ( V_28 )
F_16 ( & V_6 -> V_21 , L_2 ,
V_30 , V_28 ) ;
if ( ( V_8 -> V_24 - V_8 -> V_31 ) * sizeof( T_1 ) >
V_33 - 1024 ) {
F_19 ( & V_6 -> V_21 , L_3 ) ;
F_10 ( V_6 , 200 ) ;
F_14 ( V_6 ) ;
}
F_20 ( & V_32 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_13 ( V_8 , V_34 , 0 , 1 ) ;
F_12 ( V_8 , 0x31337303 ) ;
F_13 ( V_8 , V_34 , 0x180 , 3 ) ;
F_12 ( V_8 , V_35 + V_10 ) ;
F_12 ( V_8 , 0xfeed0001 ) ;
F_12 ( V_8 , 0xfeed0000 ) ;
F_13 ( V_8 , V_36 , 0 , 1 ) ;
F_12 ( V_8 , 0x3137c0de ) ;
F_13 ( V_8 , V_36 , 0x180 , 3 ) ;
F_12 ( V_8 , V_35 + V_10 ) ;
F_12 ( V_8 , 0xfeed0000 ) ;
F_12 ( V_8 , 0xfeed0001 ) ;
F_17 ( V_6 ) ;
}
static int F_22 ( struct V_5 * V_6 ,
unsigned int V_37 , unsigned int V_38 ,
int V_39 , int V_40 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_13 ( V_8 , V_34 ,
V_41 , 8 ) ;
F_12 ( V_8 , V_42 + V_37 ) ;
F_12 ( V_8 , V_38 ) ;
F_12 ( V_8 , V_39 ) ;
F_12 ( V_8 , V_39 ) ;
F_12 ( V_8 , V_39 ) ;
F_12 ( V_8 , V_40 ) ;
F_12 ( V_8 , ( 1 << 8 ) | 1 ) ;
F_12 ( V_8 , 0 ) ;
F_2 ( V_6 ) ;
F_13 ( V_8 , V_34 ,
V_43 , 1 ) ;
F_12 ( V_8 , 0 ) ;
F_13 ( V_8 , V_34 , 0x100 , 1 ) ;
F_12 ( V_8 , 0 ) ;
F_17 ( V_6 ) ;
if ( F_4 ( V_6 , 200 ) < 0 ) {
F_11 ( & V_6 -> V_21 , L_4 , V_30 ) ;
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
unsigned int V_37 , unsigned int V_38 ,
int V_39 , int V_40 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_13 ( V_8 , V_36 ,
V_41 , 8 ) ;
F_12 ( V_8 , V_37 ) ;
F_12 ( V_8 , V_42 + V_38 ) ;
F_12 ( V_8 , V_39 ) ;
F_12 ( V_8 , V_39 ) ;
F_12 ( V_8 , V_39 ) ;
F_12 ( V_8 , V_40 ) ;
F_12 ( V_8 , ( 1 << 8 ) | 1 ) ;
F_12 ( V_8 , 0 ) ;
F_2 ( V_6 ) ;
F_13 ( V_8 , V_36 ,
V_43 , 1 ) ;
F_12 ( V_8 , 0 ) ;
F_13 ( V_8 , V_36 , 0x100 , 1 ) ;
F_12 ( V_8 , 0 ) ;
F_17 ( V_6 ) ;
if ( F_4 ( V_6 , 200 ) < 0 ) {
F_11 ( & V_6 -> V_21 , L_4 , V_30 ) ;
return - 1 ;
}
return 0 ;
}
static void F_24 ( struct V_5 * V_6 , int V_44 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
if ( ! ( V_46 -> V_47 [ V_44 ] . V_48 & V_49 ) )
return;
F_19 ( & V_6 -> V_21 , L_5 , V_44 ,
V_46 -> V_47 [ V_44 ] . V_50 ) ;
if ( F_22 ( V_6 , V_51 + V_44 * V_46 -> V_52 ,
V_46 -> V_47 [ V_44 ] . V_50 , V_53 ,
V_46 -> V_52 / V_53 ) < 0 ) {
F_16 ( & V_6 -> V_21 ,
L_6 L_7 ,
V_44 * V_46 -> V_52 , V_46 -> V_47 [ V_44 ] . V_50 ,
V_46 -> V_52 ) ;
}
V_46 -> V_47 [ V_44 ] . V_48 &= ~ V_49 ;
}
static void F_25 ( struct V_5 * V_6 , int V_44 ,
unsigned int V_50 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
F_19 ( & V_6 -> V_21 , L_8 , V_44 , V_50 ) ;
if ( F_23 ( V_6 , V_50 ,
V_51 + V_44 * V_46 -> V_52 ,
V_53 ,
V_46 -> V_52 / V_53 ) < 0 ) {
F_16 ( & V_6 -> V_21 ,
L_9 ,
V_50 , V_44 * V_46 -> V_52 , V_46 -> V_52 ) ;
}
V_46 -> V_47 [ V_44 ] . V_50 = V_50 ;
V_46 -> V_47 [ V_44 ] . V_48 |= V_54 ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_45 * V_46 = & V_8 -> V_46 ;
int V_11 ;
F_19 ( & V_6 -> V_21 , L_10 ) ;
for ( V_11 = 0 ; V_11 < V_46 -> V_55 ; V_11 ++ ) {
F_24 ( V_6 , V_11 ) ;
V_46 -> V_47 [ V_11 ] . V_48 = 0 ;
}
}
static unsigned int F_27 ( struct V_5 * V_6 ,
T_2 V_50 )
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
F_19 ( & V_6 -> V_21 , L_11 , V_11 ,
V_46 -> V_47 [ V_11 ] . V_50 ) ;
return V_11 ;
}
}
V_11 = ( V_14 + ( V_58 ++ ) ) % V_46 -> V_55 ;
F_19 ( & V_6 -> V_21 , L_12 , V_11 ) ;
F_24 ( V_6 , V_11 ) ;
F_25 ( V_6 , V_11 , V_56 ) ;
V_46 -> V_60 ++ ;
return V_11 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_46 . V_55 = V_61 ;
V_8 -> V_46 . V_52 = V_62 ;
V_8 -> V_46 . V_47 = F_29 ( sizeof( struct V_63 ) *
V_61 , V_64 ) ;
if ( V_8 -> V_46 . V_47 == NULL ) {
F_16 ( & V_6 -> V_21 , L_13 ) ;
return - V_65 ;
}
F_30 ( & V_6 -> V_21 , L_14 ,
V_61 , V_62 / 1024 ) ;
return 0 ;
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_26 ( V_6 ) ;
F_32 ( V_8 -> V_46 . V_47 ) ;
}
static int F_33 ( struct V_5 * V_6 , T_2 V_66 ,
T_3 V_39 , T_3 * V_67 , T_4 * V_68 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_69 , V_40 ;
F_19 ( & V_6 -> V_21 , L_15 , V_30 ,
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
V_44 = F_27 ( V_6 , V_66 ) ;
V_69 = V_51 + V_44 * V_8 -> V_46 . V_52 + V_57 ;
F_19 ( & V_6 -> V_21 , L_16
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
static int F_34 ( struct V_5 * V_6 , T_2 V_73 ,
T_3 V_39 , T_3 * V_67 , const T_4 * V_68 )
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
V_44 = F_27 ( V_6 , V_73 ) ;
V_69 = V_51 + V_44 * V_8 -> V_46 . V_52 + V_57 ;
F_19 ( & V_6 -> V_21 , L_18
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
static int F_35 ( struct V_74 * V_75 , void * V_76 )
{
struct V_7 * V_8 = V_75 -> V_77 ;
F_36 ( V_75 , L_19 , V_8 -> V_46 . V_59 , V_8 -> V_46 . V_60 ) ;
return 0 ;
}
static int F_37 ( struct V_78 * V_78 , struct V_79 * V_79 )
{
return F_38 ( V_79 , F_35 , F_39 ( V_78 ) ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_80 * V_81 ;
V_81 = F_41 ( V_82 , 0444 , NULL , & V_83 ,
V_8 ) ;
if ( ! V_81 )
F_11 ( & V_6 -> V_21 , L_20 ) ;
}
static struct V_84 * F_42 ( struct V_5 * V_6 ,
struct V_84 * V_84 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_85 = F_43 ( V_84 ) == V_86 ;
const char * V_87 = V_85 ? L_21 : L_22 ;
T_2 V_57 = V_84 -> V_88 << 9 ;
int error = 0 ;
struct V_89 * V_90 ;
unsigned int V_11 ;
struct V_84 * V_91 ;
F_44 (bvec, bio, i) {
char * V_92 = F_45 ( V_90 -> V_93 ) + V_90 -> V_94 ;
T_3 V_39 = V_90 -> V_95 , V_67 ;
F_19 ( & V_6 -> V_21 , L_23 , V_87 ,
V_39 , V_57 ) ;
if ( V_85 )
error = F_34 ( V_6 , V_57 , V_39 , & V_67 , V_92 ) ;
else
error = F_33 ( V_6 , V_57 , V_39 , & V_67 , V_92 ) ;
if ( error ) {
F_16 ( & V_6 -> V_21 , L_24 , V_87 ) ;
goto V_96;
}
if ( V_67 != V_39 ) {
F_16 ( & V_6 -> V_21 , L_25 , V_87 ) ;
error = - V_70 ;
goto V_96;
}
V_57 += V_39 ;
}
F_19 ( & V_6 -> V_21 , L_26 , V_87 ) ;
V_96:
F_46 ( & V_8 -> V_97 ) ;
F_47 ( & V_8 -> V_98 ) ;
V_91 = F_48 ( & V_8 -> V_98 ) ;
F_49 ( & V_8 -> V_97 ) ;
F_50 ( V_84 , error ) ;
return V_91 ;
}
static void F_51 ( struct V_99 * V_100 , struct V_84 * V_84 )
{
struct V_5 * V_6 = V_100 -> V_101 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_102 ;
F_19 ( & V_6 -> V_21 , L_27 , V_30 ) ;
F_46 ( & V_8 -> V_97 ) ;
V_102 = ! F_52 ( & V_8 -> V_98 ) ;
F_53 ( & V_8 -> V_98 , V_84 ) ;
F_49 ( & V_8 -> V_97 ) ;
if ( V_102 )
return;
do {
V_84 = F_42 ( V_6 , V_84 ) ;
} while ( V_84 );
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int error , V_28 ;
struct V_99 * V_103 ;
struct V_104 * V_104 ;
T_5 V_105 , V_106 , V_107 , V_108 , V_109 ,
V_110 , V_111 ;
char * V_112 ;
V_8 = F_29 ( sizeof( * V_8 ) , V_64 ) ;
if ( ! V_8 ) {
error = - V_65 ;
goto V_113;
}
F_55 ( & V_8 -> V_97 ) ;
F_56 ( & V_8 -> V_98 ) ;
F_57 ( V_6 , V_8 ) ;
V_8 -> V_72 = ( void * ) F_58 ( V_64 ,
F_59 ( V_114 ) ) ;
if ( V_8 -> V_72 == NULL ) {
F_16 ( & V_6 -> V_21 , L_28 ) ;
error = - V_65 ;
goto V_115;
}
V_8 -> V_31 = ( T_1 * ) ( V_8 -> V_72 + V_19 ) ;
V_8 -> V_24 = V_8 -> V_31 ;
if ( F_60 ( V_6 ) ) {
F_16 ( & V_6 -> V_21 , L_29 ) ;
error = - V_116 ;
goto V_117;
}
V_28 = - 1 ;
V_105 = F_61 ( F_62 ( V_27 , & V_112 ) , 1024 * 1024 ) ;
if ( ! V_105 ) {
F_16 ( & V_6 -> V_21 , L_30 ) ;
error = - V_118 ;
goto V_119;
}
while ( V_105 > 0 ) {
V_28 = F_63 ( V_105 , 0 , 0 , 0 , 0 ,
& V_8 -> V_120 ,
& V_106 ) ;
if ( ! V_28 )
break;
V_105 -= 1024 * 1024 ;
}
if ( V_28 ) {
F_16 ( & V_6 -> V_21 , L_31 ,
V_28 ) ;
error = - V_65 ;
goto V_119;
}
V_28 = F_64 ( V_8 -> V_120 , 0 ,
& V_8 -> V_29 , & V_107 ,
& V_108 , & V_109 ,
& V_110 ) ;
if ( V_28 ) {
F_16 ( & V_6 -> V_21 , L_32 ,
V_28 ) ;
error = - V_65 ;
goto V_121;
}
V_111 = F_65 ( F_66 ( V_8 -> V_72 ) ) ;
V_28 = F_67 ( V_8 -> V_29 , V_42 ,
V_111 , V_114 ,
V_122 | V_123 |
V_124 ) ;
if ( V_28 ) {
F_16 ( & V_6 -> V_21 , L_33 ,
V_28 ) ;
error = - V_65 ;
goto V_125;
}
V_8 -> V_16 = F_68 ( V_107 , 64 * 1024 ) ;
if ( ! V_8 -> V_16 ) {
F_16 ( & V_6 -> V_21 , L_34 ) ;
error = - V_65 ;
goto V_126;
}
V_8 -> V_1 = F_68 ( V_109 , V_110 ) ;
if ( ! V_8 -> V_1 ) {
F_16 ( & V_6 -> V_21 , L_35 ) ;
error = - V_65 ;
goto V_127;
}
F_18 ( & V_32 ) ;
F_9 ( V_6 ) ;
F_20 ( & V_32 ) ;
V_8 -> V_27 = V_105 ;
F_21 ( V_6 ) ;
F_18 ( & V_32 ) ;
error = F_10 ( V_6 , 100 ) ;
F_20 ( & V_32 ) ;
if ( error < 0 ) {
F_16 ( & V_6 -> V_21 , L_36 ) ;
error = - V_15 ;
goto V_128;
}
F_28 ( V_6 ) ;
F_40 ( V_6 ) ;
V_103 = F_69 ( V_64 ) ;
if ( ! V_103 ) {
F_16 ( & V_6 -> V_21 , L_37 ) ;
error = - V_65 ;
goto V_129;
}
V_8 -> V_103 = V_103 ;
V_103 -> V_101 = V_6 ;
F_70 ( V_103 , F_51 ) ;
F_71 ( V_103 , V_130 ) ;
F_72 ( V_103 , V_131 ) ;
F_73 ( V_103 , V_132 ) ;
V_104 = F_74 ( 1 ) ;
if ( ! V_104 ) {
F_16 ( & V_6 -> V_21 , L_38 ) ;
error = - V_65 ;
goto V_133;
}
V_8 -> V_104 = V_104 ;
V_104 -> V_134 = V_135 ;
V_104 -> V_136 = 0 ;
V_104 -> V_137 = & V_138 ;
V_104 -> V_103 = V_103 ;
V_104 -> V_139 = V_6 ;
V_104 -> V_140 = & V_6 -> V_21 ;
F_75 ( V_104 -> V_141 , V_82 , sizeof( V_104 -> V_141 ) ) ;
F_76 ( V_104 , V_8 -> V_27 >> 9 ) ;
F_30 ( & V_6 -> V_21 , L_39 ,
V_104 -> V_141 , F_77 ( V_104 ) >> 11 ) ;
F_78 ( V_104 ) ;
return 0 ;
V_133:
F_79 ( V_103 ) ;
V_129:
F_80 ( V_82 , NULL ) ;
F_31 ( V_6 ) ;
V_128:
F_81 ( V_8 -> V_1 ) ;
V_127:
F_81 ( V_8 -> V_16 ) ;
V_126:
F_67 ( V_8 -> V_29 , V_42 , V_111 ,
V_114 , V_124 ) ;
V_125:
F_82 ( V_8 -> V_29 ) ;
V_121:
F_83 ( V_8 -> V_120 ) ;
V_119:
F_84 ( V_6 ) ;
V_117:
F_85 ( ( unsigned long ) V_8 -> V_72 , F_59 ( V_114 ) ) ;
V_115:
F_32 ( V_8 ) ;
F_57 ( V_6 , NULL ) ;
V_113:
return error ;
}
static int F_86 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_87 ( V_8 -> V_104 ) ;
F_88 ( V_8 -> V_104 ) ;
F_79 ( V_8 -> V_103 ) ;
F_80 ( V_82 , NULL ) ;
F_31 ( V_6 ) ;
F_81 ( V_8 -> V_1 ) ;
F_81 ( V_8 -> V_16 ) ;
F_67 ( V_8 -> V_29 , V_42 ,
F_65 ( F_66 ( V_8 -> V_72 ) ) ,
V_114 , V_124 ) ;
F_82 ( V_8 -> V_29 ) ;
F_83 ( V_8 -> V_120 ) ;
F_84 ( V_6 ) ;
F_85 ( ( unsigned long ) V_8 -> V_72 , F_59 ( V_114 ) ) ;
F_32 ( V_8 ) ;
F_57 ( V_6 , NULL ) ;
return 0 ;
}
static int T_6 F_89 ( void )
{
int error ;
if ( ! F_90 ( V_142 ) )
return - V_143 ;
error = F_91 ( 0 , V_82 ) ;
if ( error <= 0 ) {
F_92 ( L_40 , V_82 , error ) ;
return error ;
}
V_135 = error ;
F_93 ( L_41 , V_82 ,
V_135 ) ;
error = F_94 ( & V_144 ) ;
if ( error )
F_95 ( V_135 , V_82 ) ;
return error ;
}
static void T_7 F_96 ( void )
{
F_97 ( & V_144 ) ;
F_95 ( V_135 , V_82 ) ;
}
