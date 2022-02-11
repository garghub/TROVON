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
V_11 V_77 = F_5 ( V_7 -> V_10 ) ;
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
V_11 V_77 = F_5 ( V_7 -> V_10 ) ;
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
V_123:
if ( F_101 ( V_117 & V_124 ) )
F_102 ( & V_3 -> V_125 ) ;
V_113 = F_103 ( V_101 , V_114 , V_3 -> V_40 ) ;
if ( ! V_113 )
goto V_126;
F_104 ( V_106 , V_113 ) ;
V_121 = V_112 ;
for ( V_57 = 0 ; V_57 < V_114 ; V_57 ++ ) {
V_122 = F_87 ( V_3 -> V_127 , V_117 ) ;
if ( ! V_122 ) {
F_105 ( V_3 , V_113 ) ;
F_106 ( V_113 ) ;
V_117 |= V_124 ;
goto V_123;
}
V_120 = ( V_121 > V_115 ) ? V_115 : V_121 ;
F_107 ( V_113 , V_122 , V_120 , 0 ) ;
V_121 -= V_120 ;
}
V_126:
if ( F_101 ( V_117 & V_124 ) )
F_108 ( & V_3 -> V_125 ) ;
return V_113 ;
}
static void F_105 ( struct V_2 * V_3 , struct V_81 * V_113 )
{
unsigned int V_57 ;
struct V_91 * V_128 ;
F_109 (bv, clone, i) {
F_110 ( ! V_128 -> V_94 ) ;
F_92 ( V_128 -> V_94 , V_3 -> V_127 ) ;
V_128 -> V_94 = NULL ;
}
}
static void F_111 ( struct V_105 * V_106 , struct V_2 * V_3 ,
struct V_81 * V_81 , T_3 V_77 )
{
V_106 -> V_3 = V_3 ;
V_106 -> V_104 = V_81 ;
V_106 -> V_77 = V_77 ;
V_106 -> error = 0 ;
V_106 -> V_63 . V_15 = NULL ;
F_94 ( & V_106 -> V_129 , 0 ) ;
}
static void F_112 ( struct V_105 * V_106 )
{
F_95 ( & V_106 -> V_129 ) ;
}
static void F_113 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_104 = V_106 -> V_104 ;
int error = V_106 -> error ;
if ( ! F_114 ( & V_106 -> V_129 ) )
return;
if ( V_106 -> V_63 . V_15 )
F_90 ( V_3 , V_106 -> V_63 . V_15 , V_104 ) ;
V_104 -> V_130 = error ;
F_115 ( V_104 ) ;
}
static void F_116 ( struct V_81 * V_113 )
{
struct V_105 * V_106 = V_113 -> V_131 ;
struct V_2 * V_3 = V_106 -> V_3 ;
unsigned V_132 = F_56 ( V_113 ) ;
int error ;
if ( V_132 == V_65 )
F_105 ( V_3 , V_113 ) ;
error = V_113 -> V_130 ;
F_106 ( V_113 ) ;
if ( V_132 == V_133 && ! error ) {
F_117 ( V_106 ) ;
return;
}
if ( F_101 ( error ) )
V_106 -> error = error ;
F_113 ( V_106 ) ;
}
static void F_104 ( struct V_105 * V_106 , struct V_81 * V_113 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
V_113 -> V_131 = V_106 ;
V_113 -> V_134 = F_116 ;
V_113 -> V_135 = V_3 -> V_136 -> V_137 ;
V_113 -> V_138 = V_106 -> V_104 -> V_138 ;
}
static int F_118 ( struct V_105 * V_106 , T_4 V_139 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_113 ;
V_113 = F_119 ( V_106 -> V_104 , V_139 , V_3 -> V_40 ) ;
if ( ! V_113 )
return 1 ;
F_112 ( V_106 ) ;
F_104 ( V_106 , V_113 ) ;
V_113 -> V_84 . V_140 = V_3 -> V_141 + V_106 -> V_77 ;
F_120 ( V_113 ) ;
return 0 ;
}
static void F_121 ( struct V_142 * V_143 )
{
struct V_105 * V_106 = F_122 ( V_143 , struct V_105 , V_143 ) ;
F_112 ( V_106 ) ;
if ( F_118 ( V_106 , V_101 ) )
V_106 -> error = - V_39 ;
F_113 ( V_106 ) ;
}
static void F_123 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
F_124 ( & V_106 -> V_143 , F_121 ) ;
F_125 ( V_3 -> V_144 , & V_106 -> V_143 ) ;
}
static void F_126 ( struct V_105 * V_106 )
{
struct V_81 * V_113 = V_106 -> V_63 . V_82 ;
F_120 ( V_113 ) ;
}
static int F_127 ( void * V_52 )
{
struct V_2 * V_3 = V_52 ;
struct V_105 * V_106 ;
while ( 1 ) {
struct V_145 V_146 ;
struct V_147 V_148 ;
F_128 ( V_149 , V_150 ) ;
F_129 ( & V_3 -> V_151 . V_152 ) ;
V_153:
if ( ! F_130 ( & V_3 -> V_146 ) )
goto V_154;
F_131 ( V_155 ) ;
F_132 ( & V_3 -> V_151 , & V_149 ) ;
F_133 ( & V_3 -> V_151 . V_152 ) ;
if ( F_101 ( F_134 () ) ) {
F_135 ( V_150 , V_156 ) ;
F_136 ( & V_3 -> V_151 , & V_149 ) ;
break;
}
F_137 () ;
F_135 ( V_150 , V_156 ) ;
F_129 ( & V_3 -> V_151 . V_152 ) ;
F_138 ( & V_3 -> V_151 , & V_149 ) ;
goto V_153;
V_154:
V_146 = V_3 -> V_146 ;
V_3 -> V_146 = V_157 ;
F_133 ( & V_3 -> V_151 . V_152 ) ;
F_110 ( F_139 ( V_146 . V_158 ) ) ;
F_140 ( & V_148 ) ;
do {
V_106 = F_141 ( F_142 ( & V_146 ) ) ;
F_143 ( & V_106 -> V_158 , & V_146 ) ;
F_126 ( V_106 ) ;
} while ( ! F_130 ( & V_146 ) );
F_144 ( & V_148 ) ;
}
return 0 ;
}
static void F_145 ( struct V_105 * V_106 , int V_159 )
{
struct V_81 * V_113 = V_106 -> V_63 . V_82 ;
struct V_2 * V_3 = V_106 -> V_3 ;
unsigned long V_59 ;
T_3 V_77 ;
struct V_158 * * V_160 , * V_161 ;
if ( F_101 ( V_106 -> error < 0 ) ) {
F_105 ( V_3 , V_113 ) ;
F_106 ( V_113 ) ;
F_113 ( V_106 ) ;
return;
}
F_110 ( V_106 -> V_63 . V_85 . V_109 ) ;
V_113 -> V_84 . V_140 = V_3 -> V_141 + V_106 -> V_77 ;
if ( F_146 ( ! V_159 ) && F_147 ( V_162 , & V_3 -> V_59 ) ) {
F_120 ( V_113 ) ;
return;
}
F_148 ( & V_3 -> V_151 . V_152 , V_59 ) ;
V_160 = & V_3 -> V_146 . V_158 ;
V_161 = NULL ;
V_77 = V_106 -> V_77 ;
while ( * V_160 ) {
V_161 = * V_160 ;
if ( V_77 < F_141 ( V_161 ) -> V_77 )
V_160 = & ( * V_160 ) -> V_163 ;
else
V_160 = & ( * V_160 ) -> V_164 ;
}
F_149 ( & V_106 -> V_158 , V_161 , V_160 ) ;
F_150 ( & V_106 -> V_158 , & V_3 -> V_146 ) ;
F_151 ( & V_3 -> V_151 ) ;
F_152 ( & V_3 -> V_151 . V_152 , V_59 ) ;
}
static void F_153 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
struct V_81 * V_113 ;
int V_165 ;
T_3 V_77 = V_106 -> V_77 ;
int V_28 ;
F_112 ( V_106 ) ;
F_71 ( V_3 , & V_106 -> V_63 , NULL , V_106 -> V_104 , V_77 ) ;
V_113 = F_100 ( V_106 , V_106 -> V_104 -> V_84 . V_109 ) ;
if ( F_101 ( ! V_113 ) ) {
V_106 -> error = - V_166 ;
goto V_167;
}
V_106 -> V_63 . V_82 = V_113 ;
V_106 -> V_63 . V_85 = V_113 -> V_84 ;
V_77 += F_154 ( V_113 ) ;
F_112 ( V_106 ) ;
V_28 = F_93 ( V_3 , & V_106 -> V_63 ) ;
if ( V_28 )
V_106 -> error = - V_166 ;
V_165 = F_114 ( & V_106 -> V_63 . V_108 ) ;
if ( V_165 ) {
F_145 ( V_106 , 0 ) ;
V_106 -> V_77 = V_77 ;
}
V_167:
F_113 ( V_106 ) ;
}
static void F_155 ( struct V_105 * V_106 )
{
F_113 ( V_106 ) ;
}
static void F_156 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
int V_28 = 0 ;
F_112 ( V_106 ) ;
F_71 ( V_3 , & V_106 -> V_63 , V_106 -> V_104 , V_106 -> V_104 ,
V_106 -> V_77 ) ;
V_28 = F_93 ( V_3 , & V_106 -> V_63 ) ;
if ( V_28 < 0 )
V_106 -> error = - V_166 ;
if ( F_114 ( & V_106 -> V_63 . V_108 ) )
F_155 ( V_106 ) ;
F_113 ( V_106 ) ;
}
static void V_103 ( struct V_168 * V_169 ,
int error )
{
struct V_6 * V_7 = V_169 -> V_52 ;
struct V_80 * V_63 = V_7 -> V_63 ;
struct V_105 * V_106 = F_122 ( V_63 , struct V_105 , V_63 ) ;
struct V_2 * V_3 = V_106 -> V_3 ;
if ( error == - V_111 ) {
F_157 ( & V_63 -> V_88 ) ;
return;
}
if ( ! error && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
error = V_3 -> V_96 -> V_98 ( V_3 , F_75 ( V_3 , V_7 ) , V_7 ) ;
if ( error < 0 )
V_106 -> error = - V_166 ;
F_90 ( V_3 , F_74 ( V_3 , V_7 ) , V_106 -> V_104 ) ;
if ( ! F_114 ( & V_63 -> V_108 ) )
return;
if ( F_56 ( V_106 -> V_104 ) == V_133 )
F_155 ( V_106 ) ;
else
F_145 ( V_106 , 1 ) ;
}
static void F_158 ( struct V_142 * V_143 )
{
struct V_105 * V_106 = F_122 ( V_143 , struct V_105 , V_143 ) ;
if ( F_56 ( V_106 -> V_104 ) == V_133 )
F_156 ( V_106 ) ;
else
F_153 ( V_106 ) ;
}
static void F_117 ( struct V_105 * V_106 )
{
struct V_2 * V_3 = V_106 -> V_3 ;
F_124 ( & V_106 -> V_143 , F_158 ) ;
F_125 ( V_3 -> V_170 , & V_106 -> V_143 ) ;
}
static int F_159 ( T_1 * V_22 , char * V_171 , unsigned int V_112 )
{
char V_172 [ 3 ] ;
unsigned int V_57 ;
V_172 [ 2 ] = '\0' ;
for ( V_57 = 0 ; V_57 < V_112 ; V_57 ++ ) {
V_172 [ 0 ] = * V_171 ++ ;
V_172 [ 1 ] = * V_171 ++ ;
if ( F_160 ( V_172 , 16 , & V_22 [ V_57 ] ) )
return - V_34 ;
}
if ( * V_171 != '\0' )
return - V_34 ;
return 0 ;
}
static void F_161 ( struct V_2 * V_3 )
{
unsigned V_57 ;
if ( ! V_3 -> V_4 )
return;
for ( V_57 = 0 ; V_57 < V_3 -> V_49 ; V_57 ++ )
if ( V_3 -> V_4 [ V_57 ] && ! F_19 ( V_3 -> V_4 [ V_57 ] ) ) {
F_162 ( V_3 -> V_4 [ V_57 ] ) ;
V_3 -> V_4 [ V_57 ] = NULL ;
}
F_31 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
}
static int F_163 ( struct V_2 * V_3 , char * V_173 )
{
unsigned V_57 ;
int V_21 ;
V_3 -> V_4 = F_30 ( V_3 -> V_49 * sizeof( struct V_1 * ) ,
V_38 ) ;
if ( ! V_3 -> V_4 )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_3 -> V_49 ; V_57 ++ ) {
V_3 -> V_4 [ V_57 ] = F_164 ( V_173 , 0 , 0 ) ;
if ( F_19 ( V_3 -> V_4 [ V_57 ] ) ) {
V_21 = F_29 ( V_3 -> V_4 [ V_57 ] ) ;
F_161 ( V_3 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_165 ( struct V_2 * V_3 )
{
unsigned V_51 ;
int V_21 = 0 , V_57 , V_28 ;
V_51 = ( V_3 -> V_23 - V_3 -> V_174 ) >> F_36 ( V_3 -> V_49 ) ;
for ( V_57 = 0 ; V_57 < V_3 -> V_49 ; V_57 ++ ) {
V_28 = F_166 ( V_3 -> V_4 [ V_57 ] ,
V_3 -> V_22 + ( V_57 * V_51 ) ,
V_51 ) ;
if ( V_28 )
V_21 = V_28 ;
}
return V_21 ;
}
static bool F_167 ( const char * V_175 )
{
while ( * V_175 )
if ( isspace ( * V_175 ++ ) )
return true ;
return false ;
}
static int F_168 ( struct V_2 * V_3 , const char * V_176 )
{
char * V_177 , * V_178 ;
int V_179 ;
struct V_22 * V_22 ;
const struct V_180 * V_181 ;
if ( F_167 ( V_176 ) ) {
F_169 ( L_17 ) ;
return - V_34 ;
}
V_178 = strpbrk ( V_176 , L_18 ) ;
if ( ! V_178 || V_178 == V_176 || ! strlen ( V_178 + 1 ) )
return - V_34 ;
if ( strncmp ( V_176 , L_19 , V_178 - V_176 + 1 ) &&
strncmp ( V_176 , L_20 , V_178 - V_176 + 1 ) )
return - V_34 ;
V_177 = F_170 ( V_176 , V_38 ) ;
if ( ! V_177 )
return - V_39 ;
V_22 = F_171 ( V_176 [ 0 ] == 'l' ? & V_182 : & V_183 ,
V_178 + 1 , NULL ) ;
if ( F_19 ( V_22 ) ) {
F_26 ( V_177 ) ;
return F_29 ( V_22 ) ;
}
F_172 ( & V_22 -> V_184 ) ;
V_181 = V_180 ( V_22 ) ;
if ( ! V_181 ) {
F_173 ( & V_22 -> V_184 ) ;
F_174 ( V_22 ) ;
F_26 ( V_177 ) ;
return - V_185 ;
}
if ( V_3 -> V_23 != V_181 -> V_186 ) {
F_173 ( & V_22 -> V_184 ) ;
F_174 ( V_22 ) ;
F_26 ( V_177 ) ;
return - V_34 ;
}
memcpy ( V_3 -> V_22 , V_181 -> V_52 , V_3 -> V_23 ) ;
F_173 ( & V_22 -> V_184 ) ;
F_174 ( V_22 ) ;
F_175 ( V_187 , & V_3 -> V_59 ) ;
V_179 = F_165 ( V_3 ) ;
memset ( V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
if ( ! V_179 ) {
F_176 ( V_187 , & V_3 -> V_59 ) ;
F_26 ( V_3 -> V_176 ) ;
V_3 -> V_176 = V_177 ;
} else
F_26 ( V_177 ) ;
return V_179 ;
}
static int F_177 ( char * * V_176 )
{
char * V_188 , V_189 ;
int V_179 ;
if ( * V_176 [ 0 ] != ':' )
return strlen ( * V_176 ) >> 1 ;
V_188 = strpbrk ( * V_176 + 1 , L_18 ) ;
if ( ! V_188 )
return - V_34 ;
if ( sscanf ( * V_176 + 1 , L_21 , & V_179 , & V_189 ) != 2 || V_189 != ':' )
return - V_34 ;
* V_176 = V_188 ;
return V_179 ;
}
static int F_168 ( struct V_2 * V_3 , const char * V_176 )
{
return - V_34 ;
}
static int F_177 ( char * * V_176 )
{
return ( * V_176 [ 0 ] == ':' ) ? - V_34 : strlen ( * V_176 ) >> 1 ;
}
static int F_178 ( struct V_2 * V_3 , char * V_22 )
{
int V_28 = - V_34 ;
int V_190 = strlen ( V_22 ) ;
if ( ! V_3 -> V_23 && strcmp ( V_22 , L_22 ) )
goto V_78;
if ( V_22 [ 0 ] == ':' ) {
V_28 = F_168 ( V_3 , V_22 + 1 ) ;
goto V_78;
}
F_175 ( V_187 , & V_3 -> V_59 ) ;
F_26 ( V_3 -> V_176 ) ;
V_3 -> V_176 = NULL ;
if ( V_3 -> V_23 && F_159 ( V_3 -> V_22 , V_22 , V_3 -> V_23 ) < 0 )
goto V_78;
V_28 = F_165 ( V_3 ) ;
if ( ! V_28 )
F_176 ( V_187 , & V_3 -> V_59 ) ;
V_78:
memset ( V_22 , '0' , V_190 ) ;
return V_28 ;
}
static int F_179 ( struct V_2 * V_3 )
{
F_175 ( V_187 , & V_3 -> V_59 ) ;
memset ( & V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
F_26 ( V_3 -> V_176 ) ;
V_3 -> V_176 = NULL ;
return F_165 ( V_3 ) ;
}
static void F_180 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
V_30 -> V_191 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_192 )
F_181 ( V_3 -> V_192 ) ;
if ( V_3 -> V_144 )
F_182 ( V_3 -> V_144 ) ;
if ( V_3 -> V_170 )
F_182 ( V_3 -> V_170 ) ;
F_161 ( V_3 ) ;
if ( V_3 -> V_40 )
F_183 ( V_3 -> V_40 ) ;
F_184 ( V_3 -> V_127 ) ;
F_184 ( V_3 -> V_100 ) ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_193 )
V_3 -> V_96 -> V_193 ( V_3 ) ;
if ( V_3 -> V_136 )
F_185 ( V_30 , V_3 -> V_136 ) ;
F_26 ( V_3 -> V_32 ) ;
F_26 ( V_3 -> V_194 ) ;
F_26 ( V_3 -> V_176 ) ;
F_26 ( V_3 ) ;
}
static int F_186 ( struct V_29 * V_30 ,
char * V_195 , char * V_22 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
char * V_196 , * V_32 , * V_197 , * V_198 , * V_199 , * V_200 ;
char * V_201 = NULL ;
int V_179 = - V_34 ;
char V_189 ;
if ( strchr ( V_195 , '(' ) ) {
V_30 -> error = L_23 ;
return - V_34 ;
}
V_3 -> V_194 = F_170 ( V_195 , V_38 ) ;
if ( ! V_3 -> V_194 )
goto V_202;
V_196 = V_195 ;
V_200 = F_187 ( & V_196 , L_22 ) ;
V_32 = F_187 ( & V_200 , L_18 ) ;
if ( ! V_200 )
V_3 -> V_49 = 1 ;
else if ( sscanf ( V_200 , L_21 , & V_3 -> V_49 , & V_189 ) != 1 ||
! F_188 ( V_3 -> V_49 ) ) {
V_30 -> error = L_24 ;
return - V_34 ;
}
V_3 -> V_48 = V_3 -> V_49 ;
V_3 -> V_174 = 0 ;
V_3 -> V_32 = F_170 ( V_32 , V_38 ) ;
if ( ! V_3 -> V_32 )
goto V_202;
V_197 = F_187 ( & V_196 , L_22 ) ;
V_199 = F_187 ( & V_196 , L_22 ) ;
V_198 = F_187 ( & V_199 , L_18 ) ;
if ( V_196 )
F_189 ( L_25 ) ;
if ( ! V_197 || ( ! strcmp ( V_197 , L_26 ) && ! V_198 ) ) {
V_197 = L_27 ;
V_198 = L_26 ;
}
if ( strcmp ( V_197 , L_28 ) && ! V_198 ) {
V_30 -> error = L_29 ;
return - V_34 ;
}
V_201 = F_190 ( V_203 , V_38 ) ;
if ( ! V_201 )
goto V_202;
V_179 = snprintf ( V_201 , V_203 ,
L_30 , V_197 , V_32 ) ;
if ( V_179 < 0 ) {
F_31 ( V_201 ) ;
goto V_202;
}
V_179 = F_163 ( V_3 , V_201 ) ;
if ( V_179 < 0 ) {
V_30 -> error = L_31 ;
goto V_37;
}
V_3 -> V_8 = F_21 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_8 )
V_3 -> V_8 = F_191 ( V_3 -> V_8 ,
( unsigned int ) ( sizeof( V_44 ) / sizeof( T_1 ) ) ) ;
else if ( V_198 ) {
F_189 ( L_32 ) ;
V_198 = NULL ;
}
if ( V_198 == NULL )
V_3 -> V_96 = NULL ;
else if ( strcmp ( V_198 , L_26 ) == 0 )
V_3 -> V_96 = & V_204 ;
else if ( strcmp ( V_198 , L_33 ) == 0 )
V_3 -> V_96 = & V_205 ;
else if ( strcmp ( V_198 , L_34 ) == 0 )
V_3 -> V_96 = & V_206 ;
else if ( strcmp ( V_198 , L_35 ) == 0 )
V_3 -> V_96 = & V_207 ;
else if ( strcmp ( V_198 , L_36 ) == 0 )
V_3 -> V_96 = & V_208 ;
else if ( strcmp ( V_198 , L_37 ) == 0 ) {
V_3 -> V_96 = & V_209 ;
if ( V_3 -> V_23 % V_3 -> V_48 ) {
V_3 -> V_48 ++ ;
V_3 -> V_174 = V_3 -> V_23 / V_3 -> V_48 ;
}
} else if ( strcmp ( V_198 , L_38 ) == 0 ) {
V_3 -> V_96 = & V_210 ;
V_3 -> V_48 += 2 ;
V_3 -> V_174 = V_3 -> V_8 + V_75 ;
} else {
V_179 = - V_34 ;
V_30 -> error = L_39 ;
goto V_37;
}
V_179 = F_178 ( V_3 , V_22 ) ;
if ( V_179 < 0 ) {
V_30 -> error = L_40 ;
goto V_37;
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_211 ) {
V_179 = V_3 -> V_96 -> V_211 ( V_3 , V_30 , V_199 ) ;
if ( V_179 < 0 ) {
V_30 -> error = L_41 ;
goto V_37;
}
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_212 ) {
V_179 = V_3 -> V_96 -> V_212 ( V_3 ) ;
if ( V_179 < 0 ) {
V_30 -> error = L_42 ;
goto V_37;
}
}
V_179 = 0 ;
V_37:
F_31 ( V_201 ) ;
return V_179 ;
V_202:
V_30 -> error = L_43 ;
return - V_39 ;
}
static int F_192 ( struct V_29 * V_30 , unsigned int V_213 , char * * V_214 )
{
struct V_2 * V_3 ;
int V_23 ;
unsigned int V_215 ;
unsigned long long V_216 ;
int V_179 ;
T_5 V_217 ;
struct V_218 V_219 ;
const char * V_220 ;
char V_189 ;
static struct V_221 V_222 [] = {
{ 0 , 3 , L_44 } ,
} ;
if ( V_213 < 5 ) {
V_30 -> error = L_45 ;
return - V_34 ;
}
V_23 = F_177 ( & V_214 [ 1 ] ) ;
if ( V_23 < 0 ) {
V_30 -> error = L_46 ;
return - V_34 ;
}
V_3 = F_30 ( sizeof( * V_3 ) + V_23 * sizeof( T_1 ) , V_38 ) ;
if ( ! V_3 ) {
V_30 -> error = L_47 ;
return - V_39 ;
}
V_3 -> V_23 = V_23 ;
V_30 -> V_191 = V_3 ;
V_179 = F_186 ( V_30 , V_214 [ 0 ] , V_214 [ 1 ] ) ;
if ( V_179 < 0 )
goto V_37;
V_3 -> V_90 = sizeof( struct V_89 ) ;
V_3 -> V_90 += F_193 ( F_1 ( V_3 ) ) ;
V_3 -> V_90 = F_76 ( V_3 -> V_90 , F_194 ( struct V_6 ) ) ;
if ( F_77 ( F_1 ( V_3 ) ) < V_223 ) {
V_217 = - ( V_3 -> V_90 + sizeof( struct V_6 ) )
& F_77 ( F_1 ( V_3 ) ) ;
} else {
V_217 = F_77 ( F_1 ( V_3 ) ) ;
}
V_179 = - V_39 ;
V_3 -> V_100 = F_195 ( V_224 , V_3 -> V_90 +
sizeof( struct V_6 ) + V_217 + V_3 -> V_8 ) ;
if ( ! V_3 -> V_100 ) {
V_30 -> error = L_48 ;
goto V_37;
}
V_3 -> V_107 = V_30 -> V_225 =
F_76 ( sizeof( struct V_105 ) + V_3 -> V_90 +
sizeof( struct V_6 ) + V_217 + V_3 -> V_8 ,
V_226 ) ;
V_3 -> V_127 = F_196 ( V_227 , 0 ) ;
if ( ! V_3 -> V_127 ) {
V_30 -> error = L_49 ;
goto V_37;
}
V_3 -> V_40 = F_197 ( V_224 , 0 ) ;
if ( ! V_3 -> V_40 ) {
V_30 -> error = L_50 ;
goto V_37;
}
F_198 ( & V_3 -> V_125 ) ;
V_179 = - V_34 ;
if ( sscanf ( V_214 [ 2 ] , L_51 , & V_216 , & V_189 ) != 1 ) {
V_30 -> error = L_52 ;
goto V_37;
}
V_3 -> V_87 = V_216 ;
V_179 = F_199 ( V_30 , V_214 [ 3 ] , F_200 ( V_30 -> V_228 ) , & V_3 -> V_136 ) ;
if ( V_179 ) {
V_30 -> error = L_53 ;
goto V_37;
}
V_179 = - V_34 ;
if ( sscanf ( V_214 [ 4 ] , L_51 , & V_216 , & V_189 ) != 1 ) {
V_30 -> error = L_54 ;
goto V_37;
}
V_3 -> V_141 = V_216 ;
V_214 += 5 ;
V_213 -= 5 ;
if ( V_213 ) {
V_219 . V_213 = V_213 ;
V_219 . V_214 = V_214 ;
V_179 = F_201 ( V_222 , & V_219 , & V_215 , & V_30 -> error ) ;
if ( V_179 )
goto V_37;
V_179 = - V_34 ;
while ( V_215 -- ) {
V_220 = F_202 ( & V_219 ) ;
if ( ! V_220 ) {
V_30 -> error = L_55 ;
goto V_37;
}
if ( ! strcasecmp ( V_220 , L_56 ) )
V_30 -> V_229 = 1 ;
else if ( ! strcasecmp ( V_220 , L_57 ) )
F_176 ( V_230 , & V_3 -> V_59 ) ;
else if ( ! strcasecmp ( V_220 , L_58 ) )
F_176 ( V_162 , & V_3 -> V_59 ) ;
else {
V_30 -> error = L_59 ;
goto V_37;
}
}
}
V_179 = - V_39 ;
V_3 -> V_144 = F_203 ( L_60 , V_231 , 1 ) ;
if ( ! V_3 -> V_144 ) {
V_30 -> error = L_61 ;
goto V_37;
}
if ( F_147 ( V_230 , & V_3 -> V_59 ) )
V_3 -> V_170 = F_203 ( L_62 , V_232 | V_231 , 1 ) ;
else
V_3 -> V_170 = F_203 ( L_62 , V_232 | V_231 | V_233 ,
F_204 () ) ;
if ( ! V_3 -> V_170 ) {
V_30 -> error = L_63 ;
goto V_37;
}
F_205 ( & V_3 -> V_151 ) ;
V_3 -> V_146 = V_157 ;
V_3 -> V_192 = F_206 ( F_127 , V_3 , L_64 ) ;
if ( F_19 ( V_3 -> V_192 ) ) {
V_179 = F_29 ( V_3 -> V_192 ) ;
V_3 -> V_192 = NULL ;
V_30 -> error = L_65 ;
goto V_37;
}
F_207 ( V_3 -> V_192 ) ;
V_30 -> V_234 = 1 ;
V_30 -> V_235 = true ;
return 0 ;
V_37:
F_180 ( V_30 ) ;
return V_179 ;
}
static int F_208 ( struct V_29 * V_30 , struct V_81 * V_81 )
{
struct V_105 * V_106 ;
struct V_2 * V_3 = V_30 -> V_191 ;
if ( F_101 ( V_81 -> V_138 & V_236 ||
F_209 ( V_81 ) == V_237 ) ) {
V_81 -> V_135 = V_3 -> V_136 -> V_137 ;
if ( F_154 ( V_81 ) )
V_81 -> V_84 . V_140 = V_3 -> V_141 +
F_210 ( V_30 , V_81 -> V_84 . V_140 ) ;
return V_238 ;
}
if ( F_101 ( V_81 -> V_84 . V_109 > ( V_227 << V_116 ) ) &&
F_56 ( V_81 ) == V_65 )
F_211 ( V_81 , ( ( V_227 << V_116 ) >> V_79 ) ) ;
V_106 = F_91 ( V_81 , V_3 -> V_107 ) ;
F_111 ( V_106 , V_3 , V_81 , F_210 ( V_30 , V_81 -> V_84 . V_140 ) ) ;
V_106 -> V_63 . V_15 = (struct V_89 * ) ( V_106 + 1 ) ;
if ( F_56 ( V_106 -> V_104 ) == V_133 ) {
if ( F_118 ( V_106 , V_118 ) )
F_123 ( V_106 ) ;
} else
F_117 ( V_106 ) ;
return V_239 ;
}
static void F_212 ( struct V_29 * V_30 , T_6 type ,
unsigned V_240 , char * V_241 , unsigned V_242 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
unsigned V_57 , V_243 = 0 ;
int V_244 = 0 ;
switch ( type ) {
case V_245 :
V_241 [ 0 ] = '\0' ;
break;
case V_246 :
F_213 ( L_66 , V_3 -> V_194 ) ;
if ( V_3 -> V_23 > 0 ) {
if ( V_3 -> V_176 )
F_213 ( L_67 , V_3 -> V_23 , V_3 -> V_176 ) ;
else
for ( V_57 = 0 ; V_57 < V_3 -> V_23 ; V_57 ++ )
F_213 ( L_68 , V_3 -> V_22 [ V_57 ] ) ;
} else
F_213 ( L_22 ) ;
F_213 ( L_69 , ( unsigned long long ) V_3 -> V_87 ,
V_3 -> V_136 -> V_247 , ( unsigned long long ) V_3 -> V_141 ) ;
V_244 += ! ! V_30 -> V_229 ;
V_244 += F_147 ( V_230 , & V_3 -> V_59 ) ;
V_244 += F_147 ( V_162 , & V_3 -> V_59 ) ;
if ( V_244 ) {
F_213 ( L_70 , V_244 ) ;
if ( V_30 -> V_229 )
F_213 ( L_71 ) ;
if ( F_147 ( V_230 , & V_3 -> V_59 ) )
F_213 ( L_72 ) ;
if ( F_147 ( V_162 , & V_3 -> V_59 ) )
F_213 ( L_73 ) ;
}
break;
}
}
static void F_214 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
F_176 ( V_248 , & V_3 -> V_59 ) ;
}
static int F_215 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
if ( ! F_147 ( V_187 , & V_3 -> V_59 ) ) {
F_169 ( L_74 ) ;
return - V_249 ;
}
return 0 ;
}
static void F_216 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
F_175 ( V_248 , & V_3 -> V_59 ) ;
}
static int F_217 ( struct V_29 * V_30 , unsigned V_213 , char * * V_214 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
int V_23 , V_179 = - V_34 ;
if ( V_213 < 2 )
goto error;
if ( ! strcasecmp ( V_214 [ 0 ] , L_75 ) ) {
if ( ! F_147 ( V_248 , & V_3 -> V_59 ) ) {
F_189 ( L_76 ) ;
return - V_34 ;
}
if ( V_213 == 3 && ! strcasecmp ( V_214 [ 1 ] , L_77 ) ) {
V_23 = F_177 ( & V_214 [ 2 ] ) ;
if ( V_23 < 0 || V_3 -> V_23 != V_23 ) {
memset ( V_214 [ 2 ] , '0' , strlen ( V_214 [ 2 ] ) ) ;
return - V_34 ;
}
V_179 = F_178 ( V_3 , V_214 [ 2 ] ) ;
if ( V_179 )
return V_179 ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_212 )
V_179 = V_3 -> V_96 -> V_212 ( V_3 ) ;
return V_179 ;
}
if ( V_213 == 2 && ! strcasecmp ( V_214 [ 1 ] , L_78 ) ) {
if ( V_3 -> V_96 && V_3 -> V_96 -> V_250 ) {
V_179 = V_3 -> V_96 -> V_250 ( V_3 ) ;
if ( V_179 )
return V_179 ;
}
return F_179 ( V_3 ) ;
}
}
error:
F_189 ( L_79 ) ;
return - V_34 ;
}
static int F_218 ( struct V_29 * V_30 ,
T_7 V_251 , void * V_52 )
{
struct V_2 * V_3 = V_30 -> V_191 ;
return V_251 ( V_30 , V_3 -> V_136 , V_3 -> V_141 , V_30 -> V_120 , V_52 ) ;
}
static void F_219 ( struct V_29 * V_30 , struct V_252 * V_253 )
{
V_253 -> V_254 = V_115 ;
}
static int T_8 F_220 ( void )
{
int V_28 ;
V_28 = F_221 ( & V_255 ) ;
if ( V_28 < 0 )
F_169 ( L_80 , V_28 ) ;
return V_28 ;
}
static void T_9 F_222 ( void )
{
F_223 ( & V_255 ) ;
}
