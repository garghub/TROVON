static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 [ 0 ] ;
}
static int F_2 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
memset ( V_5 , 0 , V_3 -> V_8 ) ;
* ( V_9 * ) V_5 = F_3 ( V_7 -> V_10 & 0xffffffff ) ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
memset ( V_5 , 0 , V_3 -> V_8 ) ;
* ( V_11 * ) V_5 = F_5 ( V_7 -> V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = & V_3 -> V_14 . V_13 ;
struct V_15 V_16 ;
struct V_17 V_18 ;
struct V_19 * V_20 ;
int V_21 ;
F_7 ( & V_18 , V_3 -> V_22 , V_3 -> V_23 ) ;
V_16 . V_24 = V_13 -> V_25 ;
V_16 . V_26 = V_27 ;
V_21 = F_8 ( & V_16 , & V_18 , V_3 -> V_23 , V_13 -> V_28 ) ;
if ( V_21 )
return V_21 ;
V_20 = V_3 -> V_29 ;
V_21 = F_9 ( V_20 , V_13 -> V_28 ,
F_10 ( V_13 -> V_25 ) ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = & V_3 -> V_14 . V_13 ;
unsigned V_30 = F_10 ( V_13 -> V_25 ) ;
struct V_19 * V_20 ;
int V_31 , V_21 = 0 ;
memset ( V_13 -> V_28 , 0 , V_30 ) ;
V_20 = V_3 -> V_29 ;
V_31 = F_9 ( V_20 , V_13 -> V_28 , V_30 ) ;
if ( V_31 )
V_21 = V_31 ;
return V_21 ;
}
static struct V_19 * F_12 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
T_1 * V_28 , unsigned V_34 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_13 ( V_3 -> V_35 , 0 , V_36 ) ;
if ( F_14 ( V_20 ) ) {
V_33 -> error = L_1 ;
return V_20 ;
}
if ( F_15 ( V_20 ) !=
F_16 ( F_1 ( V_3 ) ) ) {
V_33 -> error = L_2
L_3 ;
F_17 ( V_20 ) ;
return F_18 ( - V_37 ) ;
}
V_21 = F_9 ( V_20 , V_28 , V_34 ) ;
if ( V_21 ) {
V_33 -> error = L_4 ;
F_17 ( V_20 ) ;
return F_18 ( V_21 ) ;
}
return V_20 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
struct V_12 * V_13 = & V_3 -> V_14 . V_13 ;
F_20 ( V_13 -> V_25 ) ;
V_13 -> V_25 = NULL ;
F_21 ( V_13 -> V_28 ) ;
V_13 -> V_28 = NULL ;
V_20 = V_3 -> V_29 ;
if ( V_20 )
F_17 ( V_20 ) ;
V_3 -> V_29 = NULL ;
}
static int F_22 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_19 * V_20 = NULL ;
struct V_39 * V_25 = NULL ;
T_1 * V_28 = NULL ;
int V_21 ;
if ( ! V_38 ) {
V_33 -> error = L_5 ;
return - V_37 ;
}
V_25 = F_23 ( V_38 , 0 , V_36 ) ;
if ( F_14 ( V_25 ) ) {
V_33 -> error = L_6 ;
V_21 = F_24 ( V_25 ) ;
goto V_40;
}
V_28 = F_25 ( F_10 ( V_25 ) , V_41 ) ;
if ( ! V_28 ) {
V_33 -> error = L_7 ;
V_21 = - V_42 ;
goto V_40;
}
V_3 -> V_14 . V_13 . V_28 = V_28 ;
V_3 -> V_14 . V_13 . V_25 = V_25 ;
V_20 = F_12 ( V_3 , V_33 , V_28 ,
F_10 ( V_25 ) ) ;
if ( F_14 ( V_20 ) ) {
F_19 ( V_3 ) ;
return F_24 ( V_20 ) ;
}
V_3 -> V_29 = V_20 ;
return 0 ;
V_40:
if ( V_25 && ! F_14 ( V_25 ) )
F_20 ( V_25 ) ;
F_26 ( V_28 ) ;
return V_21 ;
}
static int F_27 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_19 * V_20 = V_3 -> V_29 ;
memset ( V_5 , 0 , V_3 -> V_8 ) ;
* ( V_11 * ) V_5 = F_5 ( V_7 -> V_10 ) ;
F_28 ( V_20 , V_5 , V_5 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
unsigned V_43 = F_30 ( F_1 ( V_3 ) ) ;
int log = F_31 ( V_43 ) ;
if ( 1 << log != V_43 ) {
V_33 -> error = L_8 ;
return - V_37 ;
}
if ( log > 9 ) {
V_33 -> error = L_9 ;
return - V_37 ;
}
V_3 -> V_14 . V_44 . V_45 = 9 - log ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 )
{
}
static int F_33 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_2 V_46 ;
memset ( V_5 , 0 , V_3 -> V_8 - sizeof( V_47 ) ) ;
V_46 = F_34 ( ( ( V_47 ) V_7 -> V_10 << V_3 -> V_14 . V_44 . V_45 ) + 1 ) ;
F_35 ( V_46 , ( T_2 * ) ( V_5 + V_3 -> V_8 - sizeof( V_47 ) ) ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
memset ( V_5 , 0 , V_3 -> V_8 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_14 . V_49 ;
if ( V_49 -> V_25 && ! F_14 ( V_49 -> V_25 ) )
F_38 ( V_49 -> V_25 ) ;
V_49 -> V_25 = NULL ;
F_21 ( V_49 -> V_50 ) ;
V_49 -> V_50 = NULL ;
}
static int F_39 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_48 * V_49 = & V_3 -> V_14 . V_49 ;
V_49 -> V_25 = F_40 ( L_10 , 0 , 0 ) ;
if ( F_14 ( V_49 -> V_25 ) ) {
V_33 -> error = L_11 ;
return F_24 ( V_49 -> V_25 ) ;
}
if ( V_3 -> V_51 == V_3 -> V_52 ) {
V_49 -> V_50 = NULL ;
return 0 ;
}
V_49 -> V_50 = F_25 ( V_53 , V_41 ) ;
if ( ! V_49 -> V_50 ) {
F_37 ( V_3 ) ;
V_33 -> error = L_12 ;
return - V_42 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_14 . V_49 ;
int V_54 = V_3 -> V_23 / V_3 -> V_51 ;
if ( V_49 -> V_50 )
memcpy ( V_49 -> V_50 , V_3 -> V_22 + ( V_3 -> V_52 * V_54 ) ,
F_42 ( V_49 -> V_25 ) ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_14 . V_49 ;
if ( V_49 -> V_50 )
memset ( V_49 -> V_50 , 0 , V_53 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 ,
T_1 * V_55 )
{
struct V_48 * V_49 = & V_3 -> V_14 . V_49 ;
F_45 ( V_16 , V_49 -> V_25 ) ;
struct V_56 V_57 ;
V_9 V_58 [ 4 ] ;
int V_59 , V_31 ;
V_16 -> V_24 = V_49 -> V_25 ;
V_16 -> V_26 = V_27 ;
V_31 = F_46 ( V_16 ) ;
if ( V_31 )
return V_31 ;
if ( V_49 -> V_50 ) {
V_31 = F_47 ( V_16 , V_49 -> V_50 , V_53 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_47 ( V_16 , V_55 + 16 , 16 * 31 ) ;
if ( V_31 )
return V_31 ;
V_58 [ 0 ] = F_3 ( V_7 -> V_10 & 0xFFFFFFFF ) ;
V_58 [ 1 ] = F_3 ( ( ( ( V_47 ) V_7 -> V_10 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_58 [ 2 ] = F_3 ( 4024 ) ;
V_58 [ 3 ] = 0 ;
V_31 = F_47 ( V_16 , ( T_1 * ) V_58 , sizeof( V_58 ) ) ;
if ( V_31 )
return V_31 ;
V_31 = F_48 ( V_16 , & V_57 ) ;
if ( V_31 )
return V_31 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ )
F_49 ( & V_57 . V_61 [ V_59 ] ) ;
memcpy ( V_5 , & V_57 . V_61 , V_3 -> V_8 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_62 ;
int V_31 = 0 ;
if ( F_51 ( V_7 -> V_63 -> V_64 ) == V_65 ) {
V_62 = F_52 ( F_53 ( & V_7 -> V_66 ) ) ;
V_31 = F_44 ( V_3 , V_5 , V_7 , V_62 + V_7 -> V_66 . V_67 ) ;
F_54 ( V_62 ) ;
} else
memset ( V_5 , 0 , V_3 -> V_8 ) ;
return V_31 ;
}
static int F_55 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_68 ;
int V_31 ;
if ( F_51 ( V_7 -> V_63 -> V_64 ) == V_65 )
return 0 ;
V_68 = F_52 ( F_53 ( & V_7 -> V_69 ) ) ;
V_31 = F_44 ( V_3 , V_5 , V_7 , V_68 + V_7 -> V_69 . V_67 ) ;
if ( ! V_31 )
F_56 ( V_68 + V_7 -> V_69 . V_67 , V_5 , V_3 -> V_8 ) ;
F_54 ( V_68 ) ;
return V_31 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
F_21 ( V_71 -> V_72 ) ;
V_71 -> V_72 = NULL ;
F_21 ( V_71 -> V_73 ) ;
V_71 -> V_73 = NULL ;
if ( V_71 -> V_74 && ! F_14 ( V_71 -> V_74 ) )
F_38 ( V_71 -> V_74 ) ;
V_71 -> V_74 = NULL ;
}
static int F_58 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
if ( V_3 -> V_23 <= ( V_3 -> V_8 + V_75 ) ) {
V_33 -> error = L_13 ;
return - V_37 ;
}
V_71 -> V_74 = F_40 ( L_14 , 0 , 0 ) ;
if ( F_14 ( V_71 -> V_74 ) ) {
V_33 -> error = L_15 ;
return F_24 ( V_71 -> V_74 ) ;
}
V_71 -> V_72 = F_25 ( V_3 -> V_8 , V_41 ) ;
V_71 -> V_73 = F_25 ( V_75 , V_41 ) ;
if ( ! V_71 -> V_72 || ! V_71 -> V_73 ) {
F_57 ( V_3 ) ;
V_33 -> error = L_16 ;
return - V_42 ;
}
return 0 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
int V_76 = V_3 -> V_23 - V_3 -> V_8 - V_75 ;
memcpy ( V_71 -> V_72 , & V_3 -> V_22 [ V_76 ] , V_3 -> V_8 ) ;
memcpy ( V_71 -> V_73 , & V_3 -> V_22 [ V_76 + V_3 -> V_8 ] ,
V_75 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
memset ( V_71 -> V_72 , 0 , V_3 -> V_8 ) ;
memset ( V_71 -> V_73 , 0 , V_75 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
T_1 * V_55 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
V_47 V_77 = F_5 ( ( V_47 ) V_7 -> V_10 ) ;
T_1 V_58 [ V_75 ] ;
F_45 ( V_16 , V_71 -> V_74 ) ;
int V_59 , V_31 ;
memcpy ( V_58 , V_71 -> V_73 , V_75 ) ;
F_56 ( V_58 , ( T_1 * ) & V_77 , 8 ) ;
F_56 ( & V_58 [ 8 ] , ( T_1 * ) & V_77 , 8 ) ;
V_16 -> V_24 = V_71 -> V_74 ;
V_16 -> V_26 = V_27 ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
V_31 = F_46 ( V_16 ) ;
if ( V_31 )
goto V_78;
V_31 = F_47 ( V_16 , & V_58 [ V_59 * 4 ] , 4 ) ;
if ( V_31 )
goto V_78;
V_31 = F_62 ( V_16 , & V_58 [ V_59 * 4 ] ) ;
if ( V_31 )
goto V_78;
}
F_56 ( & V_58 [ 0 ] , & V_58 [ 12 ] , 4 ) ;
F_56 ( & V_58 [ 4 ] , & V_58 [ 8 ] , 4 ) ;
for ( V_59 = 0 ; V_59 < ( ( 1 << V_79 ) / 8 ) ; V_59 ++ )
F_56 ( V_55 + V_59 * 8 , V_58 , 8 ) ;
V_78:
F_63 ( V_58 , sizeof( V_58 ) ) ;
return V_31 ;
}
static int F_64 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
V_47 V_77 = F_5 ( ( V_47 ) V_7 -> V_10 ) ;
T_1 * V_62 ;
int V_31 = 0 ;
if ( F_51 ( V_7 -> V_63 -> V_64 ) != V_65 ) {
V_62 = F_52 ( F_53 ( & V_7 -> V_66 ) ) ;
V_31 = F_61 ( V_3 , V_7 , V_62 + V_7 -> V_66 . V_67 ) ;
F_54 ( V_62 ) ;
}
memcpy ( V_5 , V_71 -> V_72 , V_3 -> V_8 ) ;
F_56 ( V_5 , ( T_1 * ) & V_77 , 8 ) ;
if ( V_3 -> V_8 > 8 )
F_56 ( & V_5 [ 8 ] , ( T_1 * ) & V_77 , V_3 -> V_8 - 8 ) ;
return V_31 ;
}
static int F_65 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_68 ;
int V_31 ;
if ( F_51 ( V_7 -> V_63 -> V_64 ) != V_65 )
return 0 ;
V_68 = F_52 ( F_53 ( & V_7 -> V_69 ) ) ;
V_31 = F_61 ( V_3 , V_7 , V_68 + V_7 -> V_69 . V_67 ) ;
F_54 ( V_68 ) ;
return V_31 ;
}
static void F_66 ( struct V_2 * V_3 ,
struct V_80 * V_63 ,
struct V_81 * V_82 , struct V_81 * V_64 ,
T_3 V_77 )
{
V_63 -> V_64 = V_64 ;
V_63 -> V_82 = V_82 ;
if ( V_64 )
V_63 -> V_83 = V_64 -> V_84 ;
if ( V_82 )
V_63 -> V_85 = V_82 -> V_84 ;
V_63 -> V_86 = V_77 + V_3 -> V_87 ;
F_67 ( & V_63 -> V_88 ) ;
}
static struct V_6 * F_68 ( struct V_2 * V_3 ,
struct V_89 * V_90 )
{
return (struct V_6 * ) ( ( char * ) V_90 + V_3 -> V_91 ) ;
}
static struct V_89 * F_69 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
return (struct V_89 * ) ( ( char * ) V_7 - V_3 -> V_91 ) ;
}
static T_1 * F_70 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
return ( T_1 * ) F_71 ( ( unsigned long ) ( V_7 + 1 ) ,
F_72 ( F_1 ( V_3 ) ) + 1 ) ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_80 * V_63 ,
struct V_89 * V_90 )
{
struct V_92 V_93 = F_74 ( V_63 -> V_64 , V_63 -> V_83 ) ;
struct V_92 V_94 = F_74 ( V_63 -> V_82 , V_63 -> V_85 ) ;
struct V_6 * V_7 ;
T_1 * V_5 ;
int V_31 ;
V_7 = F_68 ( V_3 , V_90 ) ;
V_5 = F_70 ( V_3 , V_7 ) ;
V_7 -> V_10 = V_63 -> V_86 ;
V_7 -> V_63 = V_63 ;
F_75 ( & V_7 -> V_66 , 1 ) ;
F_76 ( & V_7 -> V_66 , V_93 . V_95 , 1 << V_79 ,
V_93 . V_96 ) ;
F_75 ( & V_7 -> V_69 , 1 ) ;
F_76 ( & V_7 -> V_69 , V_94 . V_95 , 1 << V_79 ,
V_94 . V_96 ) ;
F_77 ( V_63 -> V_64 , & V_63 -> V_83 , 1 << V_79 ) ;
F_77 ( V_63 -> V_82 , & V_63 -> V_85 , 1 << V_79 ) ;
if ( V_3 -> V_97 ) {
V_31 = V_3 -> V_97 -> V_98 ( V_3 , V_5 , V_7 ) ;
if ( V_31 < 0 )
return V_31 ;
}
F_78 ( V_90 , & V_7 -> V_66 , & V_7 -> V_69 ,
1 << V_79 , V_5 ) ;
if ( F_51 ( V_63 -> V_64 ) == V_65 )
V_31 = F_79 ( V_90 ) ;
else
V_31 = F_80 ( V_90 ) ;
if ( ! V_31 && V_3 -> V_97 && V_3 -> V_97 -> V_99 )
V_31 = V_3 -> V_97 -> V_99 ( V_3 , V_5 , V_7 ) ;
return V_31 ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_80 * V_63 )
{
unsigned V_100 = V_63 -> V_86 & ( V_3 -> V_52 - 1 ) ;
if ( ! V_63 -> V_90 )
V_63 -> V_90 = F_82 ( V_3 -> V_101 , V_102 ) ;
F_83 ( V_63 -> V_90 , V_3 -> V_4 [ V_100 ] ) ;
F_84 ( V_63 -> V_90 ,
V_103 | V_27 ,
V_104 , F_68 ( V_3 , V_63 -> V_90 ) ) ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_89 * V_90 , struct V_81 * V_105 )
{
struct V_106 * V_107 = F_86 ( V_105 , V_3 -> V_108 ) ;
if ( (struct V_89 * ) ( V_107 + 1 ) != V_90 )
F_87 ( V_90 , V_3 -> V_101 ) ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_80 * V_63 )
{
int V_31 ;
F_89 ( & V_63 -> V_109 , 1 ) ;
while ( V_63 -> V_83 . V_110 && V_63 -> V_85 . V_110 ) {
F_81 ( V_3 , V_63 ) ;
F_90 ( & V_63 -> V_109 ) ;
V_31 = F_73 ( V_3 , V_63 , V_63 -> V_90 ) ;
switch ( V_31 ) {
case - V_111 :
F_91 ( & V_63 -> V_88 ) ;
F_92 ( & V_63 -> V_88 ) ;
case - V_112 :
V_63 -> V_90 = NULL ;
V_63 -> V_86 ++ ;
continue;
case 0 :
F_93 ( & V_63 -> V_109 ) ;
V_63 -> V_86 ++ ;
F_94 () ;
continue;
default:
F_93 ( & V_63 -> V_109 ) ;
return V_31 ;
}
}
return 0 ;
}
static struct V_81 * F_95 ( struct V_106 * V_107 , unsigned V_113 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_114 ;
unsigned int V_115 = ( V_113 + V_116 - 1 ) >> V_117 ;
T_4 V_118 = V_119 | V_120 ;
unsigned V_59 , V_121 , V_122 ;
struct V_123 * V_123 ;
struct V_92 * V_124 ;
V_125:
if ( F_96 ( V_118 & V_126 ) )
F_97 ( & V_3 -> V_127 ) ;
V_114 = F_98 ( V_102 , V_115 , V_3 -> V_43 ) ;
if ( ! V_114 )
goto V_128;
F_99 ( V_107 , V_114 ) ;
V_122 = V_113 ;
for ( V_59 = 0 ; V_59 < V_115 ; V_59 ++ ) {
V_123 = F_82 ( V_3 -> V_129 , V_118 ) ;
if ( ! V_123 ) {
F_100 ( V_3 , V_114 ) ;
F_101 ( V_114 ) ;
V_118 |= V_126 ;
goto V_125;
}
V_121 = ( V_122 > V_116 ) ? V_116 : V_122 ;
V_124 = & V_114 -> V_130 [ V_114 -> V_131 ++ ] ;
V_124 -> V_95 = V_123 ;
V_124 -> V_132 = V_121 ;
V_124 -> V_96 = 0 ;
V_114 -> V_84 . V_110 += V_121 ;
V_122 -= V_121 ;
}
V_128:
if ( F_96 ( V_118 & V_126 ) )
F_102 ( & V_3 -> V_127 ) ;
return V_114 ;
}
static void F_100 ( struct V_2 * V_3 , struct V_81 * V_114 )
{
unsigned int V_59 ;
struct V_92 * V_133 ;
F_103 (bv, clone, i) {
F_104 ( ! V_133 -> V_95 ) ;
F_87 ( V_133 -> V_95 , V_3 -> V_129 ) ;
V_133 -> V_95 = NULL ;
}
}
static void F_105 ( struct V_106 * V_107 , struct V_2 * V_3 ,
struct V_81 * V_81 , T_3 V_77 )
{
V_107 -> V_3 = V_3 ;
V_107 -> V_105 = V_81 ;
V_107 -> V_77 = V_77 ;
V_107 -> error = 0 ;
V_107 -> V_63 . V_90 = NULL ;
F_89 ( & V_107 -> V_134 , 0 ) ;
}
static void F_106 ( struct V_106 * V_107 )
{
F_90 ( & V_107 -> V_134 ) ;
}
static void F_107 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_105 = V_107 -> V_105 ;
int error = V_107 -> error ;
if ( ! F_108 ( & V_107 -> V_134 ) )
return;
if ( V_107 -> V_63 . V_90 )
F_85 ( V_3 , V_107 -> V_63 . V_90 , V_105 ) ;
F_109 ( V_105 , error ) ;
}
static void F_110 ( struct V_81 * V_114 , int error )
{
struct V_106 * V_107 = V_114 -> V_135 ;
struct V_2 * V_3 = V_107 -> V_3 ;
unsigned V_136 = F_51 ( V_114 ) ;
if ( F_96 ( ! F_111 ( V_114 , V_137 ) && ! error ) )
error = - V_138 ;
if ( V_136 == V_65 )
F_100 ( V_3 , V_114 ) ;
F_101 ( V_114 ) ;
if ( V_136 == V_139 && ! error ) {
F_112 ( V_107 ) ;
return;
}
if ( F_96 ( error ) )
V_107 -> error = error ;
F_107 ( V_107 ) ;
}
static void F_99 ( struct V_106 * V_107 , struct V_81 * V_114 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
V_114 -> V_135 = V_107 ;
V_114 -> V_140 = F_110 ;
V_114 -> V_141 = V_3 -> V_142 -> V_143 ;
V_114 -> V_144 = V_107 -> V_105 -> V_144 ;
}
static int F_113 ( struct V_106 * V_107 , T_4 V_145 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_114 ;
V_114 = F_114 ( V_107 -> V_105 , V_145 , V_3 -> V_43 ) ;
if ( ! V_114 )
return 1 ;
F_106 ( V_107 ) ;
F_99 ( V_107 , V_114 ) ;
V_114 -> V_84 . V_146 = V_3 -> V_147 + V_107 -> V_77 ;
F_115 ( V_114 ) ;
return 0 ;
}
static void F_116 ( struct V_148 * V_149 )
{
struct V_106 * V_107 = F_117 ( V_149 , struct V_106 , V_149 ) ;
F_106 ( V_107 ) ;
if ( F_113 ( V_107 , V_102 ) )
V_107 -> error = - V_42 ;
F_107 ( V_107 ) ;
}
static void F_118 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
F_119 ( & V_107 -> V_149 , F_116 ) ;
F_120 ( V_3 -> V_150 , & V_107 -> V_149 ) ;
}
static void F_121 ( struct V_106 * V_107 )
{
struct V_81 * V_114 = V_107 -> V_63 . V_82 ;
F_115 ( V_114 ) ;
}
static int F_122 ( void * V_55 )
{
struct V_2 * V_3 = V_55 ;
struct V_106 * V_107 ;
while ( 1 ) {
struct V_151 V_152 ;
struct V_153 V_154 ;
F_123 ( V_155 , V_156 ) ;
F_124 ( & V_3 -> V_157 . V_158 ) ;
V_159:
if ( ! F_125 ( & V_3 -> V_152 ) )
goto V_160;
F_126 ( V_161 ) ;
F_127 ( & V_3 -> V_157 , & V_155 ) ;
F_128 ( & V_3 -> V_157 . V_158 ) ;
if ( F_96 ( F_129 () ) ) {
F_130 ( V_156 , V_162 ) ;
F_131 ( & V_3 -> V_157 , & V_155 ) ;
break;
}
F_132 () ;
F_130 ( V_156 , V_162 ) ;
F_124 ( & V_3 -> V_157 . V_158 ) ;
F_133 ( & V_3 -> V_157 , & V_155 ) ;
goto V_159;
V_160:
V_152 = V_3 -> V_152 ;
V_3 -> V_152 = V_163 ;
F_128 ( & V_3 -> V_157 . V_158 ) ;
F_104 ( F_134 ( V_152 . V_164 ) ) ;
F_135 ( & V_154 ) ;
do {
V_107 = F_136 ( F_137 ( & V_152 ) ) ;
F_138 ( & V_107 -> V_164 , & V_152 ) ;
F_121 ( V_107 ) ;
} while ( ! F_125 ( & V_152 ) );
F_139 ( & V_154 ) ;
}
return 0 ;
}
static void F_140 ( struct V_106 * V_107 , int V_165 )
{
struct V_81 * V_114 = V_107 -> V_63 . V_82 ;
struct V_2 * V_3 = V_107 -> V_3 ;
unsigned long V_26 ;
T_3 V_77 ;
struct V_164 * * V_166 , * V_167 ;
if ( F_96 ( V_107 -> error < 0 ) ) {
F_100 ( V_3 , V_114 ) ;
F_101 ( V_114 ) ;
F_107 ( V_107 ) ;
return;
}
F_104 ( V_107 -> V_63 . V_85 . V_110 ) ;
V_114 -> V_84 . V_146 = V_3 -> V_147 + V_107 -> V_77 ;
if ( F_141 ( ! V_165 ) && F_142 ( V_168 , & V_3 -> V_26 ) ) {
F_115 ( V_114 ) ;
return;
}
F_143 ( & V_3 -> V_157 . V_158 , V_26 ) ;
V_166 = & V_3 -> V_152 . V_164 ;
V_167 = NULL ;
V_77 = V_107 -> V_77 ;
while ( * V_166 ) {
V_167 = * V_166 ;
if ( V_77 < F_136 ( V_167 ) -> V_77 )
V_166 = & ( * V_166 ) -> V_169 ;
else
V_166 = & ( * V_166 ) -> V_170 ;
}
F_144 ( & V_107 -> V_164 , V_167 , V_166 ) ;
F_145 ( & V_107 -> V_164 , & V_3 -> V_152 ) ;
F_146 ( & V_3 -> V_157 ) ;
F_147 ( & V_3 -> V_157 . V_158 , V_26 ) ;
}
static void F_148 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_114 ;
int V_171 ;
T_3 V_77 = V_107 -> V_77 ;
int V_31 ;
F_106 ( V_107 ) ;
F_66 ( V_3 , & V_107 -> V_63 , NULL , V_107 -> V_105 , V_77 ) ;
V_114 = F_95 ( V_107 , V_107 -> V_105 -> V_84 . V_110 ) ;
if ( F_96 ( ! V_114 ) ) {
V_107 -> error = - V_138 ;
goto V_172;
}
V_107 -> V_63 . V_82 = V_114 ;
V_107 -> V_63 . V_85 = V_114 -> V_84 ;
V_77 += F_149 ( V_114 ) ;
F_106 ( V_107 ) ;
V_31 = F_88 ( V_3 , & V_107 -> V_63 ) ;
if ( V_31 )
V_107 -> error = - V_138 ;
V_171 = F_108 ( & V_107 -> V_63 . V_109 ) ;
if ( V_171 ) {
F_140 ( V_107 , 0 ) ;
V_107 -> V_77 = V_77 ;
}
V_172:
F_107 ( V_107 ) ;
}
static void F_150 ( struct V_106 * V_107 )
{
F_107 ( V_107 ) ;
}
static void F_151 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
int V_31 = 0 ;
F_106 ( V_107 ) ;
F_66 ( V_3 , & V_107 -> V_63 , V_107 -> V_105 , V_107 -> V_105 ,
V_107 -> V_77 ) ;
V_31 = F_88 ( V_3 , & V_107 -> V_63 ) ;
if ( V_31 < 0 )
V_107 -> error = - V_138 ;
if ( F_108 ( & V_107 -> V_63 . V_109 ) )
F_150 ( V_107 ) ;
F_107 ( V_107 ) ;
}
static void V_104 ( struct V_173 * V_174 ,
int error )
{
struct V_6 * V_7 = V_174 -> V_55 ;
struct V_80 * V_63 = V_7 -> V_63 ;
struct V_106 * V_107 = F_117 ( V_63 , struct V_106 , V_63 ) ;
struct V_2 * V_3 = V_107 -> V_3 ;
if ( error == - V_112 ) {
F_152 ( & V_63 -> V_88 ) ;
return;
}
if ( ! error && V_3 -> V_97 && V_3 -> V_97 -> V_99 )
error = V_3 -> V_97 -> V_99 ( V_3 , F_70 ( V_3 , V_7 ) , V_7 ) ;
if ( error < 0 )
V_107 -> error = - V_138 ;
F_85 ( V_3 , F_69 ( V_3 , V_7 ) , V_107 -> V_105 ) ;
if ( ! F_108 ( & V_63 -> V_109 ) )
return;
if ( F_51 ( V_107 -> V_105 ) == V_139 )
F_150 ( V_107 ) ;
else
F_140 ( V_107 , 1 ) ;
}
static void F_153 ( struct V_148 * V_149 )
{
struct V_106 * V_107 = F_117 ( V_149 , struct V_106 , V_149 ) ;
if ( F_51 ( V_107 -> V_105 ) == V_139 )
F_151 ( V_107 ) ;
else
F_148 ( V_107 ) ;
}
static void F_112 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
F_119 ( & V_107 -> V_149 , F_153 ) ;
F_120 ( V_3 -> V_175 , & V_107 -> V_149 ) ;
}
static int F_154 ( T_1 * V_22 , char * V_176 , unsigned int V_113 )
{
char V_177 [ 3 ] ;
unsigned int V_59 ;
V_177 [ 2 ] = '\0' ;
for ( V_59 = 0 ; V_59 < V_113 ; V_59 ++ ) {
V_177 [ 0 ] = * V_176 ++ ;
V_177 [ 1 ] = * V_176 ++ ;
if ( F_155 ( V_177 , 16 , & V_22 [ V_59 ] ) )
return - V_37 ;
}
if ( * V_176 != '\0' )
return - V_37 ;
return 0 ;
}
static void F_156 ( struct V_2 * V_3 )
{
unsigned V_59 ;
if ( ! V_3 -> V_4 )
return;
for ( V_59 = 0 ; V_59 < V_3 -> V_52 ; V_59 ++ )
if ( V_3 -> V_4 [ V_59 ] && ! F_14 ( V_3 -> V_4 [ V_59 ] ) ) {
F_157 ( V_3 -> V_4 [ V_59 ] ) ;
V_3 -> V_4 [ V_59 ] = NULL ;
}
F_26 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
}
static int F_158 ( struct V_2 * V_3 , char * V_178 )
{
unsigned V_59 ;
int V_21 ;
V_3 -> V_4 = F_159 ( V_3 -> V_52 * sizeof( struct V_1 * ) ,
V_41 ) ;
if ( ! V_3 -> V_4 )
return - V_42 ;
for ( V_59 = 0 ; V_59 < V_3 -> V_52 ; V_59 ++ ) {
V_3 -> V_4 [ V_59 ] = F_160 ( V_178 , 0 , 0 ) ;
if ( F_14 ( V_3 -> V_4 [ V_59 ] ) ) {
V_21 = F_24 ( V_3 -> V_4 [ V_59 ] ) ;
F_156 ( V_3 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_161 ( struct V_2 * V_3 )
{
unsigned V_54 ;
int V_21 = 0 , V_59 , V_31 ;
V_54 = ( V_3 -> V_23 - V_3 -> V_179 ) >> F_31 ( V_3 -> V_52 ) ;
for ( V_59 = 0 ; V_59 < V_3 -> V_52 ; V_59 ++ ) {
V_31 = F_162 ( V_3 -> V_4 [ V_59 ] ,
V_3 -> V_22 + ( V_59 * V_54 ) ,
V_54 ) ;
if ( V_31 )
V_21 = V_31 ;
}
return V_21 ;
}
static int F_163 ( struct V_2 * V_3 , char * V_22 )
{
int V_31 = - V_37 ;
int V_180 = strlen ( V_22 ) ;
if ( V_3 -> V_23 != ( V_180 >> 1 ) )
goto V_78;
if ( ! V_3 -> V_23 && strcmp ( V_22 , L_17 ) )
goto V_78;
if ( V_3 -> V_23 && F_154 ( V_3 -> V_22 , V_22 , V_3 -> V_23 ) < 0 )
goto V_78;
F_164 ( V_181 , & V_3 -> V_26 ) ;
V_31 = F_161 ( V_3 ) ;
V_78:
memset ( V_22 , '0' , V_180 ) ;
return V_31 ;
}
static int F_165 ( struct V_2 * V_3 )
{
F_166 ( V_181 , & V_3 -> V_26 ) ;
memset ( & V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
return F_161 ( V_3 ) ;
}
static void F_167 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
V_33 -> V_182 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_183 )
F_168 ( V_3 -> V_183 ) ;
if ( V_3 -> V_150 )
F_169 ( V_3 -> V_150 ) ;
if ( V_3 -> V_175 )
F_169 ( V_3 -> V_175 ) ;
F_156 ( V_3 ) ;
if ( V_3 -> V_43 )
F_170 ( V_3 -> V_43 ) ;
if ( V_3 -> V_129 )
F_171 ( V_3 -> V_129 ) ;
if ( V_3 -> V_101 )
F_171 ( V_3 -> V_101 ) ;
if ( V_3 -> V_97 && V_3 -> V_97 -> V_184 )
V_3 -> V_97 -> V_184 ( V_3 ) ;
if ( V_3 -> V_142 )
F_172 ( V_33 , V_3 -> V_142 ) ;
F_21 ( V_3 -> V_35 ) ;
F_21 ( V_3 -> V_185 ) ;
F_21 ( V_3 ) ;
}
static int F_173 ( struct V_32 * V_33 ,
char * V_186 , char * V_22 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
char * V_187 , * V_35 , * V_188 , * V_189 , * V_190 , * V_191 ;
char * V_192 = NULL ;
int V_193 = - V_37 ;
char V_194 ;
if ( strchr ( V_186 , '(' ) ) {
V_33 -> error = L_18 ;
return - V_37 ;
}
V_3 -> V_185 = F_174 ( V_186 , V_41 ) ;
if ( ! V_3 -> V_185 )
goto V_195;
V_187 = V_186 ;
V_191 = F_175 ( & V_187 , L_17 ) ;
V_35 = F_175 ( & V_191 , L_19 ) ;
if ( ! V_191 )
V_3 -> V_52 = 1 ;
else if ( sscanf ( V_191 , L_20 , & V_3 -> V_52 , & V_194 ) != 1 ||
! F_176 ( V_3 -> V_52 ) ) {
V_33 -> error = L_21 ;
return - V_37 ;
}
V_3 -> V_51 = V_3 -> V_52 ;
V_3 -> V_179 = 0 ;
V_3 -> V_35 = F_174 ( V_35 , V_41 ) ;
if ( ! V_3 -> V_35 )
goto V_195;
V_188 = F_175 ( & V_187 , L_17 ) ;
V_190 = F_175 ( & V_187 , L_17 ) ;
V_189 = F_175 ( & V_190 , L_19 ) ;
if ( V_187 )
F_177 ( L_22 ) ;
if ( ! V_188 || ( ! strcmp ( V_188 , L_23 ) && ! V_189 ) ) {
V_188 = L_24 ;
V_189 = L_23 ;
}
if ( strcmp ( V_188 , L_25 ) && ! V_189 ) {
V_33 -> error = L_26 ;
return - V_37 ;
}
V_192 = F_159 ( V_196 , V_41 ) ;
if ( ! V_192 )
goto V_195;
V_193 = snprintf ( V_192 , V_196 ,
L_27 , V_188 , V_35 ) ;
if ( V_193 < 0 ) {
F_26 ( V_192 ) ;
goto V_195;
}
V_193 = F_158 ( V_3 , V_192 ) ;
if ( V_193 < 0 ) {
V_33 -> error = L_28 ;
goto V_40;
}
V_3 -> V_8 = F_16 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_8 )
V_3 -> V_8 = F_178 ( V_3 -> V_8 ,
( unsigned int ) ( sizeof( V_47 ) / sizeof( T_1 ) ) ) ;
else if ( V_189 ) {
F_177 ( L_29 ) ;
V_189 = NULL ;
}
if ( V_189 == NULL )
V_3 -> V_97 = NULL ;
else if ( strcmp ( V_189 , L_23 ) == 0 )
V_3 -> V_97 = & V_197 ;
else if ( strcmp ( V_189 , L_30 ) == 0 )
V_3 -> V_97 = & V_198 ;
else if ( strcmp ( V_189 , L_31 ) == 0 )
V_3 -> V_97 = & V_199 ;
else if ( strcmp ( V_189 , L_32 ) == 0 )
V_3 -> V_97 = & V_200 ;
else if ( strcmp ( V_189 , L_33 ) == 0 )
V_3 -> V_97 = & V_201 ;
else if ( strcmp ( V_189 , L_34 ) == 0 ) {
V_3 -> V_97 = & V_202 ;
if ( V_3 -> V_23 % V_3 -> V_51 ) {
V_3 -> V_51 ++ ;
V_3 -> V_179 = V_3 -> V_23 / V_3 -> V_51 ;
}
} else if ( strcmp ( V_189 , L_35 ) == 0 ) {
V_3 -> V_97 = & V_203 ;
V_3 -> V_51 += 2 ;
V_3 -> V_179 = V_3 -> V_8 + V_75 ;
} else {
V_193 = - V_37 ;
V_33 -> error = L_36 ;
goto V_40;
}
V_193 = F_163 ( V_3 , V_22 ) ;
if ( V_193 < 0 ) {
V_33 -> error = L_37 ;
goto V_40;
}
if ( V_3 -> V_97 && V_3 -> V_97 -> V_204 ) {
V_193 = V_3 -> V_97 -> V_204 ( V_3 , V_33 , V_190 ) ;
if ( V_193 < 0 ) {
V_33 -> error = L_38 ;
goto V_40;
}
}
if ( V_3 -> V_97 && V_3 -> V_97 -> V_205 ) {
V_193 = V_3 -> V_97 -> V_205 ( V_3 ) ;
if ( V_193 < 0 ) {
V_33 -> error = L_39 ;
goto V_40;
}
}
V_193 = 0 ;
V_40:
F_26 ( V_192 ) ;
return V_193 ;
V_195:
V_33 -> error = L_40 ;
return - V_42 ;
}
static int F_179 ( struct V_32 * V_33 , unsigned int V_206 , char * * V_207 )
{
struct V_2 * V_3 ;
unsigned int V_23 , V_208 ;
unsigned long long V_209 ;
int V_193 ;
T_5 V_210 ;
struct V_211 V_212 ;
const char * V_213 ;
char V_194 ;
static struct V_214 V_215 [] = {
{ 0 , 3 , L_41 } ,
} ;
if ( V_206 < 5 ) {
V_33 -> error = L_42 ;
return - V_37 ;
}
V_23 = strlen ( V_207 [ 1 ] ) >> 1 ;
V_3 = F_25 ( sizeof( * V_3 ) + V_23 * sizeof( T_1 ) , V_41 ) ;
if ( ! V_3 ) {
V_33 -> error = L_43 ;
return - V_42 ;
}
V_3 -> V_23 = V_23 ;
V_33 -> V_182 = V_3 ;
V_193 = F_173 ( V_33 , V_207 [ 0 ] , V_207 [ 1 ] ) ;
if ( V_193 < 0 )
goto V_40;
V_3 -> V_91 = sizeof( struct V_89 ) ;
V_3 -> V_91 += F_180 ( F_1 ( V_3 ) ) ;
V_3 -> V_91 = F_71 ( V_3 -> V_91 , F_181 ( struct V_6 ) ) ;
if ( F_72 ( F_1 ( V_3 ) ) < V_216 ) {
V_210 = - ( V_3 -> V_91 + sizeof( struct V_6 ) )
& F_72 ( F_1 ( V_3 ) ) ;
} else {
V_210 = F_72 ( F_1 ( V_3 ) ) ;
}
V_193 = - V_42 ;
V_3 -> V_101 = F_182 ( V_217 , V_3 -> V_91 +
sizeof( struct V_6 ) + V_210 + V_3 -> V_8 ) ;
if ( ! V_3 -> V_101 ) {
V_33 -> error = L_44 ;
goto V_40;
}
V_3 -> V_108 = V_33 -> V_108 =
F_71 ( sizeof( struct V_106 ) + V_3 -> V_91 +
sizeof( struct V_6 ) + V_210 + V_3 -> V_8 ,
V_218 ) ;
V_3 -> V_129 = F_183 ( V_219 , 0 ) ;
if ( ! V_3 -> V_129 ) {
V_33 -> error = L_45 ;
goto V_40;
}
V_3 -> V_43 = F_184 ( V_217 , 0 ) ;
if ( ! V_3 -> V_43 ) {
V_33 -> error = L_46 ;
goto V_40;
}
F_185 ( & V_3 -> V_127 ) ;
V_193 = - V_37 ;
if ( sscanf ( V_207 [ 2 ] , L_47 , & V_209 , & V_194 ) != 1 ) {
V_33 -> error = L_48 ;
goto V_40;
}
V_3 -> V_87 = V_209 ;
if ( F_186 ( V_33 , V_207 [ 3 ] , F_187 ( V_33 -> V_220 ) , & V_3 -> V_142 ) ) {
V_33 -> error = L_49 ;
goto V_40;
}
if ( sscanf ( V_207 [ 4 ] , L_47 , & V_209 , & V_194 ) != 1 ) {
V_33 -> error = L_50 ;
goto V_40;
}
V_3 -> V_147 = V_209 ;
V_207 += 5 ;
V_206 -= 5 ;
if ( V_206 ) {
V_212 . V_206 = V_206 ;
V_212 . V_207 = V_207 ;
V_193 = F_188 ( V_215 , & V_212 , & V_208 , & V_33 -> error ) ;
if ( V_193 )
goto V_40;
V_193 = - V_37 ;
while ( V_208 -- ) {
V_213 = F_189 ( & V_212 ) ;
if ( ! V_213 ) {
V_33 -> error = L_51 ;
goto V_40;
}
if ( ! strcasecmp ( V_213 , L_52 ) )
V_33 -> V_221 = 1 ;
else if ( ! strcasecmp ( V_213 , L_53 ) )
F_164 ( V_222 , & V_3 -> V_26 ) ;
else if ( ! strcasecmp ( V_213 , L_54 ) )
F_164 ( V_168 , & V_3 -> V_26 ) ;
else {
V_33 -> error = L_55 ;
goto V_40;
}
}
}
V_193 = - V_42 ;
V_3 -> V_150 = F_190 ( L_56 , V_223 , 1 ) ;
if ( ! V_3 -> V_150 ) {
V_33 -> error = L_57 ;
goto V_40;
}
if ( F_142 ( V_222 , & V_3 -> V_26 ) )
V_3 -> V_175 = F_190 ( L_58 , V_224 | V_223 , 1 ) ;
else
V_3 -> V_175 = F_190 ( L_58 , V_224 | V_223 | V_225 ,
F_191 () ) ;
if ( ! V_3 -> V_175 ) {
V_33 -> error = L_59 ;
goto V_40;
}
F_192 ( & V_3 -> V_157 ) ;
V_3 -> V_152 = V_163 ;
V_3 -> V_183 = F_193 ( F_122 , V_3 , L_60 ) ;
if ( F_14 ( V_3 -> V_183 ) ) {
V_193 = F_24 ( V_3 -> V_183 ) ;
V_3 -> V_183 = NULL ;
V_33 -> error = L_61 ;
goto V_40;
}
F_194 ( V_3 -> V_183 ) ;
V_33 -> V_226 = 1 ;
V_33 -> V_227 = true ;
return 0 ;
V_40:
F_167 ( V_33 ) ;
return V_193 ;
}
static int F_195 ( struct V_32 * V_33 , struct V_81 * V_81 )
{
struct V_106 * V_107 ;
struct V_2 * V_3 = V_33 -> V_182 ;
if ( F_96 ( V_81 -> V_144 & ( V_228 | V_229 ) ) ) {
V_81 -> V_141 = V_3 -> V_142 -> V_143 ;
if ( F_149 ( V_81 ) )
V_81 -> V_84 . V_146 = V_3 -> V_147 +
F_196 ( V_33 , V_81 -> V_84 . V_146 ) ;
return V_230 ;
}
V_107 = F_86 ( V_81 , V_3 -> V_108 ) ;
F_105 ( V_107 , V_3 , V_81 , F_196 ( V_33 , V_81 -> V_84 . V_146 ) ) ;
V_107 -> V_63 . V_90 = (struct V_89 * ) ( V_107 + 1 ) ;
if ( F_51 ( V_107 -> V_105 ) == V_139 ) {
if ( F_113 ( V_107 , V_119 ) )
F_118 ( V_107 ) ;
} else
F_112 ( V_107 ) ;
return V_231 ;
}
static void F_197 ( struct V_32 * V_33 , T_6 type ,
unsigned V_232 , char * V_233 , unsigned V_234 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
unsigned V_59 , V_235 = 0 ;
int V_236 = 0 ;
switch ( type ) {
case V_237 :
V_233 [ 0 ] = '\0' ;
break;
case V_238 :
F_198 ( L_62 , V_3 -> V_185 ) ;
if ( V_3 -> V_23 > 0 )
for ( V_59 = 0 ; V_59 < V_3 -> V_23 ; V_59 ++ )
F_198 ( L_63 , V_3 -> V_22 [ V_59 ] ) ;
else
F_198 ( L_17 ) ;
F_198 ( L_64 , ( unsigned long long ) V_3 -> V_87 ,
V_3 -> V_142 -> V_239 , ( unsigned long long ) V_3 -> V_147 ) ;
V_236 += ! ! V_33 -> V_221 ;
V_236 += F_142 ( V_222 , & V_3 -> V_26 ) ;
V_236 += F_142 ( V_168 , & V_3 -> V_26 ) ;
if ( V_236 ) {
F_198 ( L_65 , V_236 ) ;
if ( V_33 -> V_221 )
F_198 ( L_66 ) ;
if ( F_142 ( V_222 , & V_3 -> V_26 ) )
F_198 ( L_67 ) ;
if ( F_142 ( V_168 , & V_3 -> V_26 ) )
F_198 ( L_68 ) ;
}
break;
}
}
static void F_199 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
F_164 ( V_240 , & V_3 -> V_26 ) ;
}
static int F_200 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
if ( ! F_142 ( V_181 , & V_3 -> V_26 ) ) {
F_201 ( L_69 ) ;
return - V_241 ;
}
return 0 ;
}
static void F_202 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
F_166 ( V_240 , & V_3 -> V_26 ) ;
}
static int F_203 ( struct V_32 * V_33 , unsigned V_206 , char * * V_207 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
int V_193 = - V_37 ;
if ( V_206 < 2 )
goto error;
if ( ! strcasecmp ( V_207 [ 0 ] , L_70 ) ) {
if ( ! F_142 ( V_240 , & V_3 -> V_26 ) ) {
F_177 ( L_71 ) ;
return - V_37 ;
}
if ( V_206 == 3 && ! strcasecmp ( V_207 [ 1 ] , L_72 ) ) {
V_193 = F_163 ( V_3 , V_207 [ 2 ] ) ;
if ( V_193 )
return V_193 ;
if ( V_3 -> V_97 && V_3 -> V_97 -> V_205 )
V_193 = V_3 -> V_97 -> V_205 ( V_3 ) ;
return V_193 ;
}
if ( V_206 == 2 && ! strcasecmp ( V_207 [ 1 ] , L_73 ) ) {
if ( V_3 -> V_97 && V_3 -> V_97 -> V_242 ) {
V_193 = V_3 -> V_97 -> V_242 ( V_3 ) ;
if ( V_193 )
return V_193 ;
}
return F_165 ( V_3 ) ;
}
}
error:
F_177 ( L_74 ) ;
return - V_37 ;
}
static int F_204 ( struct V_32 * V_33 , struct V_243 * V_244 ,
struct V_92 * V_245 , int V_246 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
struct V_247 * V_248 = F_205 ( V_3 -> V_142 -> V_143 ) ;
if ( ! V_248 -> V_249 )
return V_246 ;
V_244 -> V_141 = V_3 -> V_142 -> V_143 ;
V_244 -> V_146 = V_3 -> V_147 + F_196 ( V_33 , V_244 -> V_146 ) ;
return F_206 ( V_246 , V_248 -> V_249 ( V_248 , V_244 , V_245 ) ) ;
}
static int F_207 ( struct V_32 * V_33 ,
T_7 V_250 , void * V_55 )
{
struct V_2 * V_3 = V_33 -> V_182 ;
return V_250 ( V_33 , V_3 -> V_142 , V_3 -> V_147 , V_33 -> V_121 , V_55 ) ;
}
static int T_8 F_208 ( void )
{
int V_31 ;
V_31 = F_209 ( & V_251 ) ;
if ( V_31 < 0 )
F_201 ( L_75 , V_31 ) ;
return V_31 ;
}
static void T_9 F_210 ( void )
{
F_211 ( & V_251 ) ;
}
