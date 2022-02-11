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
F_7 ( V_15 , V_13 -> V_16 ) ;
struct V_17 V_18 ;
struct V_19 * V_20 ;
int V_21 ;
F_8 ( & V_18 , V_3 -> V_22 , V_3 -> V_23 ) ;
F_9 ( V_15 , V_13 -> V_16 ) ;
F_10 ( V_15 , V_24 , NULL , NULL ) ;
F_11 ( V_15 , & V_18 , V_13 -> V_25 , V_3 -> V_23 ) ;
V_21 = F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
if ( V_21 )
return V_21 ;
V_20 = V_3 -> V_26 ;
V_21 = F_14 ( V_20 , V_13 -> V_25 ,
F_15 ( V_13 -> V_16 ) ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = & V_3 -> V_14 . V_13 ;
unsigned V_27 = F_15 ( V_13 -> V_16 ) ;
struct V_19 * V_20 ;
int V_28 , V_21 = 0 ;
memset ( V_13 -> V_25 , 0 , V_27 ) ;
V_20 = V_3 -> V_26 ;
V_28 = F_14 ( V_20 , V_13 -> V_25 , V_27 ) ;
if ( V_28 )
V_21 = V_28 ;
return V_21 ;
}
static struct V_19 * F_17 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
T_1 * V_25 , unsigned V_31 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_18 ( V_3 -> V_32 , 0 , V_33 ) ;
if ( F_19 ( V_20 ) ) {
V_30 -> error = L_1 ;
return V_20 ;
}
if ( F_20 ( V_20 ) !=
F_21 ( F_1 ( V_3 ) ) ) {
V_30 -> error = L_2
L_3 ;
F_22 ( V_20 ) ;
return F_23 ( - V_34 ) ;
}
V_21 = F_14 ( V_20 , V_25 , V_31 ) ;
if ( V_21 ) {
V_30 -> error = L_4 ;
F_22 ( V_20 ) ;
return F_23 ( V_21 ) ;
}
return V_20 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
struct V_12 * V_13 = & V_3 -> V_14 . V_13 ;
F_25 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
F_26 ( V_13 -> V_25 ) ;
V_13 -> V_25 = NULL ;
V_20 = V_3 -> V_26 ;
if ( V_20 )
F_22 ( V_20 ) ;
V_3 -> V_26 = NULL ;
}
static int F_27 ( struct V_2 * V_3 , struct V_29 * V_30 ,
const char * V_35 )
{
struct V_19 * V_20 = NULL ;
struct V_36 * V_16 = NULL ;
T_1 * V_25 = NULL ;
int V_21 ;
if ( ! V_35 ) {
V_30 -> error = L_5 ;
return - V_34 ;
}
V_16 = F_28 ( V_35 , 0 , V_33 ) ;
if ( F_19 ( V_16 ) ) {
V_30 -> error = L_6 ;
V_21 = F_29 ( V_16 ) ;
goto V_37;
}
V_25 = F_30 ( F_15 ( V_16 ) , V_38 ) ;
if ( ! V_25 ) {
V_30 -> error = L_7 ;
V_21 = - V_39 ;
goto V_37;
}
V_3 -> V_14 . V_13 . V_25 = V_25 ;
V_3 -> V_14 . V_13 . V_16 = V_16 ;
V_20 = F_17 ( V_3 , V_30 , V_25 ,
F_15 ( V_16 ) ) ;
if ( F_19 ( V_20 ) ) {
F_24 ( V_3 ) ;
return F_29 ( V_20 ) ;
}
V_3 -> V_26 = V_20 ;
return 0 ;
V_37:
if ( V_16 && ! F_19 ( V_16 ) )
F_25 ( V_16 ) ;
F_31 ( V_25 ) ;
return V_21 ;
}
static int F_32 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_19 * V_20 = V_3 -> V_26 ;
memset ( V_5 , 0 , V_3 -> V_8 ) ;
* ( V_11 * ) V_5 = F_5 ( V_7 -> V_10 ) ;
F_33 ( V_20 , V_5 , V_5 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_29 * V_30 ,
const char * V_35 )
{
unsigned V_40 = F_35 ( F_1 ( V_3 ) ) ;
int log = F_36 ( V_40 ) ;
if ( 1 << log != V_40 ) {
V_30 -> error = L_8 ;
return - V_34 ;
}
if ( log > 9 ) {
V_30 -> error = L_9 ;
return - V_34 ;
}
V_3 -> V_14 . V_41 . V_42 = 9 - log ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
}
static int F_38 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_2 V_43 ;
memset ( V_5 , 0 , V_3 -> V_8 - sizeof( V_44 ) ) ;
V_43 = F_39 ( ( ( V_44 ) V_7 -> V_10 << V_3 -> V_14 . V_41 . V_42 ) + 1 ) ;
F_40 ( V_43 , ( T_2 * ) ( V_5 + V_3 -> V_8 - sizeof( V_44 ) ) ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
memset ( V_5 , 0 , V_3 -> V_8 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_45 * V_46 = & V_3 -> V_14 . V_46 ;
if ( V_46 -> V_16 && ! F_19 ( V_46 -> V_16 ) )
F_43 ( V_46 -> V_16 ) ;
V_46 -> V_16 = NULL ;
F_26 ( V_46 -> V_47 ) ;
V_46 -> V_47 = NULL ;
}
static int F_44 ( struct V_2 * V_3 , struct V_29 * V_30 ,
const char * V_35 )
{
struct V_45 * V_46 = & V_3 -> V_14 . V_46 ;
V_46 -> V_16 = F_45 ( L_10 , 0 , 0 ) ;
if ( F_19 ( V_46 -> V_16 ) ) {
V_30 -> error = L_11 ;
return F_29 ( V_46 -> V_16 ) ;
}
if ( V_3 -> V_48 == V_3 -> V_49 ) {
V_46 -> V_47 = NULL ;
return 0 ;
}
V_46 -> V_47 = F_30 ( V_50 , V_38 ) ;
if ( ! V_46 -> V_47 ) {
F_42 ( V_3 ) ;
V_30 -> error = L_12 ;
return - V_39 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_45 * V_46 = & V_3 -> V_14 . V_46 ;
int V_51 = V_3 -> V_23 / V_3 -> V_48 ;
if ( V_46 -> V_47 )
memcpy ( V_46 -> V_47 , V_3 -> V_22 + ( V_3 -> V_49 * V_51 ) ,
F_47 ( V_46 -> V_16 ) ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_45 * V_46 = & V_3 -> V_14 . V_46 ;
if ( V_46 -> V_47 )
memset ( V_46 -> V_47 , 0 , V_50 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 ,
T_1 * V_52 )
{
struct V_45 * V_46 = & V_3 -> V_14 . V_46 ;
F_50 ( V_53 , V_46 -> V_16 ) ;
struct V_54 V_55 ;
V_9 V_56 [ 4 ] ;
int V_57 , V_28 ;
V_53 -> V_58 = V_46 -> V_16 ;
V_53 -> V_59 = V_24 ;
V_28 = F_51 ( V_53 ) ;
if ( V_28 )
return V_28 ;
if ( V_46 -> V_47 ) {
V_28 = F_52 ( V_53 , V_46 -> V_47 , V_50 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_52 ( V_53 , V_52 + 16 , 16 * 31 ) ;
if ( V_28 )
return V_28 ;
V_56 [ 0 ] = F_3 ( V_7 -> V_10 & 0xFFFFFFFF ) ;
V_56 [ 1 ] = F_3 ( ( ( ( V_44 ) V_7 -> V_10 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_56 [ 2 ] = F_3 ( 4024 ) ;
V_56 [ 3 ] = 0 ;
V_28 = F_52 ( V_53 , ( T_1 * ) V_56 , sizeof( V_56 ) ) ;
if ( V_28 )
return V_28 ;
V_28 = F_53 ( V_53 , & V_55 ) ;
if ( V_28 )
return V_28 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
F_54 ( & V_55 . V_61 [ V_57 ] ) ;
memcpy ( V_5 , & V_55 . V_61 , V_3 -> V_8 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_62 ;
int V_28 = 0 ;
if ( F_56 ( V_7 -> V_63 -> V_64 ) == V_65 ) {
V_62 = F_57 ( F_58 ( & V_7 -> V_66 ) ) ;
V_28 = F_49 ( V_3 , V_5 , V_7 , V_62 + V_7 -> V_66 . V_67 ) ;
F_59 ( V_62 ) ;
} else
memset ( V_5 , 0 , V_3 -> V_8 ) ;
return V_28 ;
}
static int F_60 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_68 ;
int V_28 ;
if ( F_56 ( V_7 -> V_63 -> V_64 ) == V_65 )
return 0 ;
V_68 = F_57 ( F_58 ( & V_7 -> V_69 ) ) ;
V_28 = F_49 ( V_3 , V_5 , V_7 , V_68 + V_7 -> V_69 . V_67 ) ;
if ( ! V_28 )
F_61 ( V_68 + V_7 -> V_69 . V_67 , V_5 , V_3 -> V_8 ) ;
F_59 ( V_68 ) ;
return V_28 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
F_26 ( V_71 -> V_72 ) ;
V_71 -> V_72 = NULL ;
F_26 ( V_71 -> V_73 ) ;
V_71 -> V_73 = NULL ;
if ( V_71 -> V_74 && ! F_19 ( V_71 -> V_74 ) )
F_43 ( V_71 -> V_74 ) ;
V_71 -> V_74 = NULL ;
}
static int F_63 ( struct V_2 * V_3 , struct V_29 * V_30 ,
const char * V_35 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
if ( V_3 -> V_23 <= ( V_3 -> V_8 + V_75 ) ) {
V_30 -> error = L_13 ;
return - V_34 ;
}
V_71 -> V_74 = F_45 ( L_14 , 0 , 0 ) ;
if ( F_19 ( V_71 -> V_74 ) ) {
V_30 -> error = L_15 ;
return F_29 ( V_71 -> V_74 ) ;
}
V_71 -> V_72 = F_30 ( V_3 -> V_8 , V_38 ) ;
V_71 -> V_73 = F_30 ( V_75 , V_38 ) ;
if ( ! V_71 -> V_72 || ! V_71 -> V_73 ) {
F_62 ( V_3 ) ;
V_30 -> error = L_16 ;
return - V_39 ;
}
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
int V_76 = V_3 -> V_23 - V_3 -> V_8 - V_75 ;
memcpy ( V_71 -> V_72 , & V_3 -> V_22 [ V_76 ] , V_3 -> V_8 ) ;
memcpy ( V_71 -> V_73 , & V_3 -> V_22 [ V_76 + V_3 -> V_8 ] ,
V_75 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
memset ( V_71 -> V_72 , 0 , V_3 -> V_8 ) ;
memset ( V_71 -> V_73 , 0 , V_75 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
T_1 * V_52 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
V_44 V_77 = F_5 ( ( V_44 ) V_7 -> V_10 ) ;
T_1 V_56 [ V_75 ] ;
F_50 ( V_53 , V_71 -> V_74 ) ;
int V_57 , V_28 ;
memcpy ( V_56 , V_71 -> V_73 , V_75 ) ;
F_61 ( V_56 , ( T_1 * ) & V_77 , 8 ) ;
F_61 ( & V_56 [ 8 ] , ( T_1 * ) & V_77 , 8 ) ;
V_53 -> V_58 = V_71 -> V_74 ;
V_53 -> V_59 = V_24 ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
V_28 = F_51 ( V_53 ) ;
if ( V_28 )
goto V_78;
V_28 = F_52 ( V_53 , & V_56 [ V_57 * 4 ] , 4 ) ;
if ( V_28 )
goto V_78;
V_28 = F_67 ( V_53 , & V_56 [ V_57 * 4 ] ) ;
if ( V_28 )
goto V_78;
}
F_61 ( & V_56 [ 0 ] , & V_56 [ 12 ] , 4 ) ;
F_61 ( & V_56 [ 4 ] , & V_56 [ 8 ] , 4 ) ;
for ( V_57 = 0 ; V_57 < ( ( 1 << V_79 ) / 8 ) ; V_57 ++ )
F_61 ( V_52 + V_57 * 8 , V_56 , 8 ) ;
V_78:
F_68 ( V_56 , sizeof( V_56 ) ) ;
return V_28 ;
}
static int F_69 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_70 * V_71 = & V_3 -> V_14 . V_71 ;
V_44 V_77 = F_5 ( ( V_44 ) V_7 -> V_10 ) ;
T_1 * V_62 ;
int V_28 = 0 ;
if ( F_56 ( V_7 -> V_63 -> V_64 ) != V_65 ) {
V_62 = F_57 ( F_58 ( & V_7 -> V_66 ) ) ;
V_28 = F_66 ( V_3 , V_7 , V_62 + V_7 -> V_66 . V_67 ) ;
F_59 ( V_62 ) ;
}
memcpy ( V_5 , V_71 -> V_72 , V_3 -> V_8 ) ;
F_61 ( V_5 , ( T_1 * ) & V_77 , 8 ) ;
if ( V_3 -> V_8 > 8 )
F_61 ( & V_5 [ 8 ] , ( T_1 * ) & V_77 , V_3 -> V_8 - 8 ) ;
return V_28 ;
}
static int F_70 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_68 ;
int V_28 ;
if ( F_56 ( V_7 -> V_63 -> V_64 ) != V_65 )
return 0 ;
V_68 = F_57 ( F_58 ( & V_7 -> V_69 ) ) ;
V_28 = F_66 ( V_3 , V_7 , V_68 + V_7 -> V_69 . V_67 ) ;
F_59 ( V_68 ) ;
return V_28 ;
}
static void F_71 ( struct V_2 * V_3 ,
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
F_72 ( & V_63 -> V_88 ) ;
}
static struct V_6 * F_73 ( struct V_2 * V_3 ,
struct V_89 * V_15 )
{
return (struct V_6 * ) ( ( char * ) V_15 + V_3 -> V_90 ) ;
}
static struct V_89 * F_74 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
return (struct V_89 * ) ( ( char * ) V_7 - V_3 -> V_90 ) ;
}
static T_1 * F_75 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
return ( T_1 * ) F_76 ( ( unsigned long ) ( V_7 + 1 ) ,
F_77 ( F_1 ( V_3 ) ) + 1 ) ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_80 * V_63 ,
struct V_89 * V_15 )
{
struct V_91 V_92 = F_79 ( V_63 -> V_64 , V_63 -> V_83 ) ;
struct V_91 V_93 = F_79 ( V_63 -> V_82 , V_63 -> V_85 ) ;
struct V_6 * V_7 ;
T_1 * V_5 ;
int V_28 ;
V_7 = F_73 ( V_3 , V_15 ) ;
V_5 = F_75 ( V_3 , V_7 ) ;
V_7 -> V_10 = V_63 -> V_86 ;
V_7 -> V_63 = V_63 ;
F_80 ( & V_7 -> V_66 , 1 ) ;
F_81 ( & V_7 -> V_66 , V_92 . V_94 , 1 << V_79 ,
V_92 . V_95 ) ;
F_80 ( & V_7 -> V_69 , 1 ) ;
F_81 ( & V_7 -> V_69 , V_93 . V_94 , 1 << V_79 ,
V_93 . V_95 ) ;
F_82 ( V_63 -> V_64 , & V_63 -> V_83 , 1 << V_79 ) ;
F_82 ( V_63 -> V_82 , & V_63 -> V_85 , 1 << V_79 ) ;
if ( V_3 -> V_96 ) {
V_28 = V_3 -> V_96 -> V_97 ( V_3 , V_5 , V_7 ) ;
if ( V_28 < 0 )
return V_28 ;
}
F_83 ( V_15 , & V_7 -> V_66 , & V_7 -> V_69 ,
1 << V_79 , V_5 ) ;
if ( F_56 ( V_63 -> V_64 ) == V_65 )
V_28 = F_84 ( V_15 ) ;
else
V_28 = F_85 ( V_15 ) ;
if ( ! V_28 && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
V_28 = V_3 -> V_96 -> V_98 ( V_3 , V_5 , V_7 ) ;
return V_28 ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_80 * V_63 )
{
unsigned V_99 = V_63 -> V_86 & ( V_3 -> V_49 - 1 ) ;
if ( ! V_63 -> V_15 )
V_63 -> V_15 = F_87 ( V_3 -> V_100 , V_101 ) ;
F_88 ( V_63 -> V_15 , V_3 -> V_4 [ V_99 ] ) ;
F_89 ( V_63 -> V_15 ,
V_102 | V_24 ,
V_103 , F_73 ( V_3 , V_63 -> V_15 ) ) ;
}
static void F_90 ( struct V_2 * V_3 ,
struct V_89 * V_15 , struct V_81 * V_104 )
{
struct V_105 * V_106 = F_91 ( V_104 , V_3 -> V_107 ) ;
if ( (struct V_89 * ) ( V_106 + 1 ) != V_15 )
F_92 ( V_15 , V_3 -> V_100 ) ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_80 * V_63 )
{
int V_28 ;
F_94 ( & V_63 -> V_108 , 1 ) ;
while ( V_63 -> V_83 . V_109 && V_63 -> V_85 . V_109 ) {
F_86 ( V_3 , V_63 ) ;
F_95 ( & V_63 -> V_108 ) ;
V_28 = F_78 ( V_3 , V_63 , V_63 -> V_15 ) ;
switch ( V_28 ) {
case - V_110 :
F_96 ( & V_63 -> V_88 ) ;
F_97 ( & V_63 -> V_88 ) ;
case - V_111 :
V_63 -> V_15 = NULL ;
V_63 -> V_86 ++ ;
continue;
case 0 :
F_98 ( & V_63 -> V_108 ) ;
V_63 -> V_86 ++ ;
F_99 () ;
continue;
default:
F_98 ( & V_63 -> V_108 ) ;
return V_28 ;
}
}
return 0 ;
}
static struct V_81 * F_100 ( struct V_105 * V_106 , unsigned V_112 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_113 ;
unsigned int V_114 = ( V_112 + V_115 - 1 ) >> V_116 ;
T_4 V_117 = V_118 | V_119 ;
unsigned V_57 , V_120 , V_121 ;
struct V_122 * V_122 ;
struct V_91 * V_123 ;
V_124:
if ( F_101 ( V_117 & V_125 ) )
F_102 ( & V_3 -> V_126 ) ;
V_113 = F_103 ( V_101 , V_114 , V_3 -> V_40 ) ;
if ( ! V_113 )
goto V_127;
F_104 ( V_106 , V_113 ) ;
V_121 = V_112 ;
for ( V_57 = 0 ; V_57 < V_114 ; V_57 ++ ) {
V_122 = F_87 ( V_3 -> V_128 , V_117 ) ;
if ( ! V_122 ) {
F_105 ( V_3 , V_113 ) ;
F_106 ( V_113 ) ;
V_117 |= V_125 ;
goto V_124;
}
V_120 = ( V_121 > V_115 ) ? V_115 : V_121 ;
V_123 = & V_113 -> V_129 [ V_113 -> V_130 ++ ] ;
V_123 -> V_94 = V_122 ;
V_123 -> V_131 = V_120 ;
V_123 -> V_95 = 0 ;
V_113 -> V_84 . V_109 += V_120 ;
V_121 -= V_120 ;
}
V_127:
if ( F_101 ( V_117 & V_125 ) )
F_107 ( & V_3 -> V_126 ) ;
return V_113 ;
}
static void F_105 ( struct V_2 * V_3 , struct V_81 * V_113 )
{
unsigned int V_57 ;
struct V_91 * V_132 ;
F_108 (bv, clone, i) {
F_109 ( ! V_132 -> V_94 ) ;
F_92 ( V_132 -> V_94 , V_3 -> V_128 ) ;
V_132 -> V_94 = NULL ;
}
}
static void F_110 ( struct V_105 * V_106 , struct V_2 * V_3 ,
struct V_81 * V_81 , T_3 V_77 )
{
V_106 -> V_3 = V_3 ;
V_106 -> V_104 = V_81 ;
V_106 -> V_77 = V_77 ;
V_106 -> error = 0 ;
V_106 -> V_63 . V_15 = NULL ;
F_94 ( & V_106 -> V_133 , 0 ) ;
}
static void F_111 ( struct V_105 * V_106 )
{
F_95 ( & V_106 -> V_133 ) ;
}
static void F_112 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_104 = V_106 -> V_104 ;
int error = V_106 -> error ;
if ( ! F_113 ( & V_106 -> V_133 ) )
return;
if ( V_106 -> V_63 . V_15 )
F_90 ( V_3 , V_106 -> V_63 . V_15 , V_104 ) ;
V_104 -> V_134 = error ;
F_114 ( V_104 ) ;
}
static void F_115 ( struct V_81 * V_113 )
{
struct V_105 * V_106 = V_113 -> V_135 ;
struct V_2 * V_3 = V_106 -> V_3 ;
unsigned V_136 = F_56 ( V_113 ) ;
int error ;
if ( V_136 == V_65 )
F_105 ( V_3 , V_113 ) ;
error = V_113 -> V_134 ;
F_106 ( V_113 ) ;
if ( V_136 == V_137 && ! error ) {
F_116 ( V_106 ) ;
return;
}
if ( F_101 ( error ) )
V_106 -> error = error ;
F_112 ( V_106 ) ;
}
static void F_104 ( struct V_105 * V_106 , struct V_81 * V_113 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
V_113 -> V_135 = V_106 ;
V_113 -> V_138 = F_115 ;
V_113 -> V_139 = V_3 -> V_140 -> V_141 ;
V_113 -> V_142 = V_106 -> V_104 -> V_142 ;
}
static int F_117 ( struct V_105 * V_106 , T_4 V_143 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_113 ;
V_113 = F_118 ( V_106 -> V_104 , V_143 , V_3 -> V_40 ) ;
if ( ! V_113 )
return 1 ;
F_111 ( V_106 ) ;
F_104 ( V_106 , V_113 ) ;
V_113 -> V_84 . V_144 = V_3 -> V_145 + V_106 -> V_77 ;
F_119 ( V_113 ) ;
return 0 ;
}
static void F_120 ( struct V_146 * V_147 )
{
struct V_105 * V_106 = F_121 ( V_147 , struct V_105 , V_147 ) ;
F_111 ( V_106 ) ;
if ( F_117 ( V_106 , V_101 ) )
V_106 -> error = - V_39 ;
F_112 ( V_106 ) ;
}
static void F_122 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
F_123 ( & V_106 -> V_147 , F_120 ) ;
F_124 ( V_3 -> V_148 , & V_106 -> V_147 ) ;
}
static void F_125 ( struct V_105 * V_106 )
{
struct V_81 * V_113 = V_106 -> V_63 . V_82 ;
F_119 ( V_113 ) ;
}
static int F_126 ( void * V_52 )
{
struct V_2 * V_3 = V_52 ;
struct V_105 * V_106 ;
while ( 1 ) {
struct V_149 V_150 ;
struct V_151 V_152 ;
F_127 ( V_153 , V_154 ) ;
F_128 ( & V_3 -> V_155 . V_156 ) ;
V_157:
if ( ! F_129 ( & V_3 -> V_150 ) )
goto V_158;
if ( F_101 ( F_130 ( V_159 , & V_3 -> V_59 ) ) ) {
F_131 ( & V_3 -> V_155 . V_156 ) ;
break;
}
F_132 ( V_160 ) ;
F_133 ( & V_3 -> V_155 , & V_153 ) ;
F_131 ( & V_3 -> V_155 . V_156 ) ;
F_134 () ;
F_128 ( & V_3 -> V_155 . V_156 ) ;
F_135 ( & V_3 -> V_155 , & V_153 ) ;
goto V_157;
V_158:
V_150 = V_3 -> V_150 ;
V_3 -> V_150 = V_161 ;
F_131 ( & V_3 -> V_155 . V_156 ) ;
F_109 ( F_136 ( V_150 . V_162 ) ) ;
F_137 ( & V_152 ) ;
do {
V_106 = F_138 ( F_139 ( & V_150 ) ) ;
F_140 ( & V_106 -> V_162 , & V_150 ) ;
F_125 ( V_106 ) ;
} while ( ! F_129 ( & V_150 ) );
F_141 ( & V_152 ) ;
}
return 0 ;
}
static void F_142 ( struct V_105 * V_106 , int V_163 )
{
struct V_81 * V_113 = V_106 -> V_63 . V_82 ;
struct V_2 * V_3 = V_106 -> V_3 ;
unsigned long V_59 ;
T_3 V_77 ;
struct V_162 * * V_164 , * V_165 ;
if ( F_101 ( V_106 -> error < 0 ) ) {
F_105 ( V_3 , V_113 ) ;
F_106 ( V_113 ) ;
F_112 ( V_106 ) ;
return;
}
F_109 ( V_106 -> V_63 . V_85 . V_109 ) ;
V_113 -> V_84 . V_144 = V_3 -> V_145 + V_106 -> V_77 ;
if ( F_143 ( ! V_163 ) && F_130 ( V_166 , & V_3 -> V_59 ) ) {
F_119 ( V_113 ) ;
return;
}
F_144 ( & V_3 -> V_155 . V_156 , V_59 ) ;
V_164 = & V_3 -> V_150 . V_162 ;
V_165 = NULL ;
V_77 = V_106 -> V_77 ;
while ( * V_164 ) {
V_165 = * V_164 ;
if ( V_77 < F_138 ( V_165 ) -> V_77 )
V_164 = & ( * V_164 ) -> V_167 ;
else
V_164 = & ( * V_164 ) -> V_168 ;
}
F_145 ( & V_106 -> V_162 , V_165 , V_164 ) ;
F_146 ( & V_106 -> V_162 , & V_3 -> V_150 ) ;
F_147 ( & V_3 -> V_155 ) ;
F_148 ( & V_3 -> V_155 . V_156 , V_59 ) ;
}
static void F_149 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_113 ;
int V_169 ;
T_3 V_77 = V_106 -> V_77 ;
int V_28 ;
F_111 ( V_106 ) ;
F_71 ( V_3 , & V_106 -> V_63 , NULL , V_106 -> V_104 , V_77 ) ;
V_113 = F_100 ( V_106 , V_106 -> V_104 -> V_84 . V_109 ) ;
if ( F_101 ( ! V_113 ) ) {
V_106 -> error = - V_170 ;
goto V_171;
}
V_106 -> V_63 . V_82 = V_113 ;
V_106 -> V_63 . V_85 = V_113 -> V_84 ;
V_77 += F_150 ( V_113 ) ;
F_111 ( V_106 ) ;
V_28 = F_93 ( V_3 , & V_106 -> V_63 ) ;
if ( V_28 )
V_106 -> error = - V_170 ;
V_169 = F_113 ( & V_106 -> V_63 . V_108 ) ;
if ( V_169 ) {
F_142 ( V_106 , 0 ) ;
V_106 -> V_77 = V_77 ;
}
V_171:
F_112 ( V_106 ) ;
}
static void F_151 ( struct V_105 * V_106 )
{
F_112 ( V_106 ) ;
}
static void F_152 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
int V_28 = 0 ;
F_111 ( V_106 ) ;
F_71 ( V_3 , & V_106 -> V_63 , V_106 -> V_104 , V_106 -> V_104 ,
V_106 -> V_77 ) ;
V_28 = F_93 ( V_3 , & V_106 -> V_63 ) ;
if ( V_28 < 0 )
V_106 -> error = - V_170 ;
if ( F_113 ( & V_106 -> V_63 . V_108 ) )
F_151 ( V_106 ) ;
F_112 ( V_106 ) ;
}
static void V_103 ( struct V_172 * V_173 ,
int error )
{
struct V_6 * V_7 = V_173 -> V_52 ;
struct V_80 * V_63 = V_7 -> V_63 ;
struct V_105 * V_106 = F_121 ( V_63 , struct V_105 , V_63 ) ;
struct V_2 * V_3 = V_106 -> V_3 ;
if ( error == - V_111 ) {
F_153 ( & V_63 -> V_88 ) ;
return;
}
if ( ! error && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
error = V_3 -> V_96 -> V_98 ( V_3 , F_75 ( V_3 , V_7 ) , V_7 ) ;
if ( error < 0 )
V_106 -> error = - V_170 ;
F_90 ( V_3 , F_74 ( V_3 , V_7 ) , V_106 -> V_104 ) ;
if ( ! F_113 ( & V_63 -> V_108 ) )
return;
if ( F_56 ( V_106 -> V_104 ) == V_137 )
F_151 ( V_106 ) ;
else
F_142 ( V_106 , 1 ) ;
}
static void F_154 ( struct V_146 * V_147 )
{
struct V_105 * V_106 = F_121 ( V_147 , struct V_105 , V_147 ) ;
if ( F_56 ( V_106 -> V_104 ) == V_137 )
F_152 ( V_106 ) ;
else
F_149 ( V_106 ) ;
}
static void F_116 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
F_123 ( & V_106 -> V_147 , F_154 ) ;
F_124 ( V_3 -> V_174 , & V_106 -> V_147 ) ;
}
static int F_155 ( T_1 * V_22 , char * V_175 , unsigned int V_112 )
{
char V_176 [ 3 ] ;
unsigned int V_57 ;
V_176 [ 2 ] = '\0' ;
for ( V_57 = 0 ; V_57 < V_112 ; V_57 ++ ) {
V_176 [ 0 ] = * V_175 ++ ;
V_176 [ 1 ] = * V_175 ++ ;
if ( F_156 ( V_176 , 16 , & V_22 [ V_57 ] ) )
return - V_34 ;
}
if ( * V_175 != '\0' )
return - V_34 ;
return 0 ;
}
static void F_157 ( struct V_2 * V_3 )
{
unsigned V_57 ;
if ( ! V_3 -> V_4 )
return;
for ( V_57 = 0 ; V_57 < V_3 -> V_49 ; V_57 ++ )
if ( V_3 -> V_4 [ V_57 ] && ! F_19 ( V_3 -> V_4 [ V_57 ] ) ) {
F_158 ( V_3 -> V_4 [ V_57 ] ) ;
V_3 -> V_4 [ V_57 ] = NULL ;
}
F_31 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
}
static int F_159 ( struct V_2 * V_3 , char * V_177 )
{
unsigned V_57 ;
int V_21 ;
V_3 -> V_4 = F_160 ( V_3 -> V_49 * sizeof( struct V_1 * ) ,
V_38 ) ;
if ( ! V_3 -> V_4 )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_3 -> V_49 ; V_57 ++ ) {
V_3 -> V_4 [ V_57 ] = F_161 ( V_177 , 0 , 0 ) ;
if ( F_19 ( V_3 -> V_4 [ V_57 ] ) ) {
V_21 = F_29 ( V_3 -> V_4 [ V_57 ] ) ;
F_157 ( V_3 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
unsigned V_51 ;
int V_21 = 0 , V_57 , V_28 ;
V_51 = ( V_3 -> V_23 - V_3 -> V_178 ) >> F_36 ( V_3 -> V_49 ) ;
for ( V_57 = 0 ; V_57 < V_3 -> V_49 ; V_57 ++ ) {
V_28 = F_163 ( V_3 -> V_4 [ V_57 ] ,
V_3 -> V_22 + ( V_57 * V_51 ) ,
V_51 ) ;
if ( V_28 )
V_21 = V_28 ;
}
return V_21 ;
}
static int F_164 ( struct V_2 * V_3 , char * V_22 )
{
int V_28 = - V_34 ;
int V_179 = strlen ( V_22 ) ;
if ( V_3 -> V_23 != ( V_179 >> 1 ) )
goto V_78;
if ( ! V_3 -> V_23 && strcmp ( V_22 , L_17 ) )
goto V_78;
if ( V_3 -> V_23 && F_155 ( V_3 -> V_22 , V_22 , V_3 -> V_23 ) < 0 )
goto V_78;
F_165 ( V_180 , & V_3 -> V_59 ) ;
V_28 = F_162 ( V_3 ) ;
V_78:
memset ( V_22 , '0' , V_179 ) ;
return V_28 ;
}
static int F_166 ( struct V_2 * V_3 )
{
F_167 ( V_180 , & V_3 -> V_59 ) ;
memset ( & V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
return F_162 ( V_3 ) ;
}
static void F_168 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
V_30 -> V_181 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_182 ) {
F_128 ( & V_3 -> V_155 . V_156 ) ;
F_165 ( V_159 , & V_3 -> V_59 ) ;
F_147 ( & V_3 -> V_155 ) ;
F_131 ( & V_3 -> V_155 . V_156 ) ;
F_169 ( V_3 -> V_182 ) ;
}
if ( V_3 -> V_148 )
F_170 ( V_3 -> V_148 ) ;
if ( V_3 -> V_174 )
F_170 ( V_3 -> V_174 ) ;
F_157 ( V_3 ) ;
if ( V_3 -> V_40 )
F_171 ( V_3 -> V_40 ) ;
F_172 ( V_3 -> V_128 ) ;
F_172 ( V_3 -> V_100 ) ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_183 )
V_3 -> V_96 -> V_183 ( V_3 ) ;
if ( V_3 -> V_140 )
F_173 ( V_30 , V_3 -> V_140 ) ;
F_26 ( V_3 -> V_32 ) ;
F_26 ( V_3 -> V_184 ) ;
F_26 ( V_3 ) ;
}
static int F_174 ( struct V_29 * V_30 ,
char * V_185 , char * V_22 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
char * V_186 , * V_32 , * V_187 , * V_188 , * V_189 , * V_190 ;
char * V_191 = NULL ;
int V_192 = - V_34 ;
char V_193 ;
if ( strchr ( V_185 , '(' ) ) {
V_30 -> error = L_18 ;
return - V_34 ;
}
V_3 -> V_184 = F_175 ( V_185 , V_38 ) ;
if ( ! V_3 -> V_184 )
goto V_194;
V_186 = V_185 ;
V_190 = F_176 ( & V_186 , L_17 ) ;
V_32 = F_176 ( & V_190 , L_19 ) ;
if ( ! V_190 )
V_3 -> V_49 = 1 ;
else if ( sscanf ( V_190 , L_20 , & V_3 -> V_49 , & V_193 ) != 1 ||
! F_177 ( V_3 -> V_49 ) ) {
V_30 -> error = L_21 ;
return - V_34 ;
}
V_3 -> V_48 = V_3 -> V_49 ;
V_3 -> V_178 = 0 ;
V_3 -> V_32 = F_175 ( V_32 , V_38 ) ;
if ( ! V_3 -> V_32 )
goto V_194;
V_187 = F_176 ( & V_186 , L_17 ) ;
V_189 = F_176 ( & V_186 , L_17 ) ;
V_188 = F_176 ( & V_189 , L_19 ) ;
if ( V_186 )
F_178 ( L_22 ) ;
if ( ! V_187 || ( ! strcmp ( V_187 , L_23 ) && ! V_188 ) ) {
V_187 = L_24 ;
V_188 = L_23 ;
}
if ( strcmp ( V_187 , L_25 ) && ! V_188 ) {
V_30 -> error = L_26 ;
return - V_34 ;
}
V_191 = F_160 ( V_195 , V_38 ) ;
if ( ! V_191 )
goto V_194;
V_192 = snprintf ( V_191 , V_195 ,
L_27 , V_187 , V_32 ) ;
if ( V_192 < 0 ) {
F_31 ( V_191 ) ;
goto V_194;
}
V_192 = F_159 ( V_3 , V_191 ) ;
if ( V_192 < 0 ) {
V_30 -> error = L_28 ;
goto V_37;
}
V_3 -> V_8 = F_21 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_8 )
V_3 -> V_8 = F_179 ( V_3 -> V_8 ,
( unsigned int ) ( sizeof( V_44 ) / sizeof( T_1 ) ) ) ;
else if ( V_188 ) {
F_178 ( L_29 ) ;
V_188 = NULL ;
}
if ( V_188 == NULL )
V_3 -> V_96 = NULL ;
else if ( strcmp ( V_188 , L_23 ) == 0 )
V_3 -> V_96 = & V_196 ;
else if ( strcmp ( V_188 , L_30 ) == 0 )
V_3 -> V_96 = & V_197 ;
else if ( strcmp ( V_188 , L_31 ) == 0 )
V_3 -> V_96 = & V_198 ;
else if ( strcmp ( V_188 , L_32 ) == 0 )
V_3 -> V_96 = & V_199 ;
else if ( strcmp ( V_188 , L_33 ) == 0 )
V_3 -> V_96 = & V_200 ;
else if ( strcmp ( V_188 , L_34 ) == 0 ) {
V_3 -> V_96 = & V_201 ;
if ( V_3 -> V_23 % V_3 -> V_48 ) {
V_3 -> V_48 ++ ;
V_3 -> V_178 = V_3 -> V_23 / V_3 -> V_48 ;
}
} else if ( strcmp ( V_188 , L_35 ) == 0 ) {
V_3 -> V_96 = & V_202 ;
V_3 -> V_48 += 2 ;
V_3 -> V_178 = V_3 -> V_8 + V_75 ;
} else {
V_192 = - V_34 ;
V_30 -> error = L_36 ;
goto V_37;
}
V_192 = F_164 ( V_3 , V_22 ) ;
if ( V_192 < 0 ) {
V_30 -> error = L_37 ;
goto V_37;
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_203 ) {
V_192 = V_3 -> V_96 -> V_203 ( V_3 , V_30 , V_189 ) ;
if ( V_192 < 0 ) {
V_30 -> error = L_38 ;
goto V_37;
}
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_204 ) {
V_192 = V_3 -> V_96 -> V_204 ( V_3 ) ;
if ( V_192 < 0 ) {
V_30 -> error = L_39 ;
goto V_37;
}
}
V_192 = 0 ;
V_37:
F_31 ( V_191 ) ;
return V_192 ;
V_194:
V_30 -> error = L_40 ;
return - V_39 ;
}
static int F_180 ( struct V_29 * V_30 , unsigned int V_205 , char * * V_206 )
{
struct V_2 * V_3 ;
unsigned int V_23 , V_207 ;
unsigned long long V_208 ;
int V_192 ;
T_5 V_209 ;
struct V_210 V_211 ;
const char * V_212 ;
char V_193 ;
static struct V_213 V_214 [] = {
{ 0 , 3 , L_41 } ,
} ;
if ( V_205 < 5 ) {
V_30 -> error = L_42 ;
return - V_34 ;
}
V_23 = strlen ( V_206 [ 1 ] ) >> 1 ;
V_3 = F_30 ( sizeof( * V_3 ) + V_23 * sizeof( T_1 ) , V_38 ) ;
if ( ! V_3 ) {
V_30 -> error = L_43 ;
return - V_39 ;
}
V_3 -> V_23 = V_23 ;
V_30 -> V_181 = V_3 ;
V_192 = F_174 ( V_30 , V_206 [ 0 ] , V_206 [ 1 ] ) ;
if ( V_192 < 0 )
goto V_37;
V_3 -> V_90 = sizeof( struct V_89 ) ;
V_3 -> V_90 += F_181 ( F_1 ( V_3 ) ) ;
V_3 -> V_90 = F_76 ( V_3 -> V_90 , F_182 ( struct V_6 ) ) ;
if ( F_77 ( F_1 ( V_3 ) ) < V_215 ) {
V_209 = - ( V_3 -> V_90 + sizeof( struct V_6 ) )
& F_77 ( F_1 ( V_3 ) ) ;
} else {
V_209 = F_77 ( F_1 ( V_3 ) ) ;
}
V_192 = - V_39 ;
V_3 -> V_100 = F_183 ( V_216 , V_3 -> V_90 +
sizeof( struct V_6 ) + V_209 + V_3 -> V_8 ) ;
if ( ! V_3 -> V_100 ) {
V_30 -> error = L_44 ;
goto V_37;
}
V_3 -> V_107 = V_30 -> V_217 =
F_76 ( sizeof( struct V_105 ) + V_3 -> V_90 +
sizeof( struct V_6 ) + V_209 + V_3 -> V_8 ,
V_218 ) ;
V_3 -> V_128 = F_184 ( V_219 , 0 ) ;
if ( ! V_3 -> V_128 ) {
V_30 -> error = L_45 ;
goto V_37;
}
V_3 -> V_40 = F_185 ( V_216 , 0 ) ;
if ( ! V_3 -> V_40 ) {
V_30 -> error = L_46 ;
goto V_37;
}
F_186 ( & V_3 -> V_126 ) ;
V_192 = - V_34 ;
if ( sscanf ( V_206 [ 2 ] , L_47 , & V_208 , & V_193 ) != 1 ) {
V_30 -> error = L_48 ;
goto V_37;
}
V_3 -> V_87 = V_208 ;
V_192 = F_187 ( V_30 , V_206 [ 3 ] , F_188 ( V_30 -> V_220 ) , & V_3 -> V_140 ) ;
if ( V_192 ) {
V_30 -> error = L_49 ;
goto V_37;
}
V_192 = - V_34 ;
if ( sscanf ( V_206 [ 4 ] , L_47 , & V_208 , & V_193 ) != 1 ) {
V_30 -> error = L_50 ;
goto V_37;
}
V_3 -> V_145 = V_208 ;
V_206 += 5 ;
V_205 -= 5 ;
if ( V_205 ) {
V_211 . V_205 = V_205 ;
V_211 . V_206 = V_206 ;
V_192 = F_189 ( V_214 , & V_211 , & V_207 , & V_30 -> error ) ;
if ( V_192 )
goto V_37;
V_192 = - V_34 ;
while ( V_207 -- ) {
V_212 = F_190 ( & V_211 ) ;
if ( ! V_212 ) {
V_30 -> error = L_51 ;
goto V_37;
}
if ( ! strcasecmp ( V_212 , L_52 ) )
V_30 -> V_221 = 1 ;
else if ( ! strcasecmp ( V_212 , L_53 ) )
F_165 ( V_222 , & V_3 -> V_59 ) ;
else if ( ! strcasecmp ( V_212 , L_54 ) )
F_165 ( V_166 , & V_3 -> V_59 ) ;
else {
V_30 -> error = L_55 ;
goto V_37;
}
}
}
V_192 = - V_39 ;
V_3 -> V_148 = F_191 ( L_56 , V_223 , 1 ) ;
if ( ! V_3 -> V_148 ) {
V_30 -> error = L_57 ;
goto V_37;
}
if ( F_130 ( V_222 , & V_3 -> V_59 ) )
V_3 -> V_174 = F_191 ( L_58 , V_224 | V_223 , 1 ) ;
else
V_3 -> V_174 = F_191 ( L_58 , V_224 | V_223 | V_225 ,
F_192 () ) ;
if ( ! V_3 -> V_174 ) {
V_30 -> error = L_59 ;
goto V_37;
}
F_193 ( & V_3 -> V_155 ) ;
V_3 -> V_150 = V_161 ;
V_3 -> V_182 = F_194 ( F_126 , V_3 , L_60 ) ;
if ( F_19 ( V_3 -> V_182 ) ) {
V_192 = F_29 ( V_3 -> V_182 ) ;
V_3 -> V_182 = NULL ;
V_30 -> error = L_61 ;
goto V_37;
}
F_195 ( V_3 -> V_182 ) ;
V_30 -> V_226 = 1 ;
V_30 -> V_227 = true ;
return 0 ;
V_37:
F_168 ( V_30 ) ;
return V_192 ;
}
static int F_196 ( struct V_29 * V_30 , struct V_81 * V_81 )
{
struct V_105 * V_106 ;
struct V_2 * V_3 = V_30 -> V_181 ;
if ( F_101 ( V_81 -> V_142 & ( V_228 | V_229 ) ) ) {
V_81 -> V_139 = V_3 -> V_140 -> V_141 ;
if ( F_150 ( V_81 ) )
V_81 -> V_84 . V_144 = V_3 -> V_145 +
F_197 ( V_30 , V_81 -> V_84 . V_144 ) ;
return V_230 ;
}
V_106 = F_91 ( V_81 , V_3 -> V_107 ) ;
F_110 ( V_106 , V_3 , V_81 , F_197 ( V_30 , V_81 -> V_84 . V_144 ) ) ;
V_106 -> V_63 . V_15 = (struct V_89 * ) ( V_106 + 1 ) ;
if ( F_56 ( V_106 -> V_104 ) == V_137 ) {
if ( F_117 ( V_106 , V_118 ) )
F_122 ( V_106 ) ;
} else
F_116 ( V_106 ) ;
return V_231 ;
}
static void F_198 ( struct V_29 * V_30 , T_6 type ,
unsigned V_232 , char * V_233 , unsigned V_234 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
unsigned V_57 , V_235 = 0 ;
int V_236 = 0 ;
switch ( type ) {
case V_237 :
V_233 [ 0 ] = '\0' ;
break;
case V_238 :
F_199 ( L_62 , V_3 -> V_184 ) ;
if ( V_3 -> V_23 > 0 )
for ( V_57 = 0 ; V_57 < V_3 -> V_23 ; V_57 ++ )
F_199 ( L_63 , V_3 -> V_22 [ V_57 ] ) ;
else
F_199 ( L_17 ) ;
F_199 ( L_64 , ( unsigned long long ) V_3 -> V_87 ,
V_3 -> V_140 -> V_239 , ( unsigned long long ) V_3 -> V_145 ) ;
V_236 += ! ! V_30 -> V_221 ;
V_236 += F_130 ( V_222 , & V_3 -> V_59 ) ;
V_236 += F_130 ( V_166 , & V_3 -> V_59 ) ;
if ( V_236 ) {
F_199 ( L_65 , V_236 ) ;
if ( V_30 -> V_221 )
F_199 ( L_66 ) ;
if ( F_130 ( V_222 , & V_3 -> V_59 ) )
F_199 ( L_67 ) ;
if ( F_130 ( V_166 , & V_3 -> V_59 ) )
F_199 ( L_68 ) ;
}
break;
}
}
static void F_200 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
F_165 ( V_240 , & V_3 -> V_59 ) ;
}
static int F_201 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
if ( ! F_130 ( V_180 , & V_3 -> V_59 ) ) {
F_202 ( L_69 ) ;
return - V_241 ;
}
return 0 ;
}
static void F_203 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
F_167 ( V_240 , & V_3 -> V_59 ) ;
}
static int F_204 ( struct V_29 * V_30 , unsigned V_205 , char * * V_206 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
int V_192 = - V_34 ;
if ( V_205 < 2 )
goto error;
if ( ! strcasecmp ( V_206 [ 0 ] , L_70 ) ) {
if ( ! F_130 ( V_240 , & V_3 -> V_59 ) ) {
F_178 ( L_71 ) ;
return - V_34 ;
}
if ( V_205 == 3 && ! strcasecmp ( V_206 [ 1 ] , L_72 ) ) {
V_192 = F_164 ( V_3 , V_206 [ 2 ] ) ;
if ( V_192 )
return V_192 ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_204 )
V_192 = V_3 -> V_96 -> V_204 ( V_3 ) ;
return V_192 ;
}
if ( V_205 == 2 && ! strcasecmp ( V_206 [ 1 ] , L_73 ) ) {
if ( V_3 -> V_96 && V_3 -> V_96 -> V_242 ) {
V_192 = V_3 -> V_96 -> V_242 ( V_3 ) ;
if ( V_192 )
return V_192 ;
}
return F_166 ( V_3 ) ;
}
}
error:
F_178 ( L_74 ) ;
return - V_34 ;
}
static int F_205 ( struct V_29 * V_30 ,
T_7 V_243 , void * V_52 )
{
struct V_2 * V_3 = V_30 -> V_181 ;
return V_243 ( V_30 , V_3 -> V_140 , V_3 -> V_145 , V_30 -> V_120 , V_52 ) ;
}
static void F_206 ( struct V_29 * V_30 , struct V_244 * V_245 )
{
V_245 -> V_246 = V_115 ;
}
static int T_8 F_207 ( void )
{
int V_28 ;
V_28 = F_208 ( & V_247 ) ;
if ( V_28 < 0 )
F_202 ( L_75 , V_28 ) ;
return V_28 ;
}
static void T_9 F_209 ( void )
{
F_210 ( & V_247 ) ;
}
