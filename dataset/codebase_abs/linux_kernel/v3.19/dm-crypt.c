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
static struct V_81 * F_95 ( struct V_106 * V_107 , unsigned V_113 ,
unsigned * V_114 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_115 ;
unsigned int V_116 = ( V_113 + V_117 - 1 ) >> V_118 ;
T_4 V_119 = V_102 | V_120 ;
unsigned V_59 , V_121 ;
struct V_122 * V_122 ;
V_115 = F_96 ( V_102 , V_116 , V_3 -> V_43 ) ;
if ( ! V_115 )
return NULL ;
F_97 ( V_107 , V_115 ) ;
* V_114 = 0 ;
for ( V_59 = 0 ; V_59 < V_116 ; V_59 ++ ) {
V_122 = F_82 ( V_3 -> V_123 , V_119 ) ;
if ( ! V_122 ) {
* V_114 = 1 ;
break;
}
V_119 = ( V_119 | V_124 ) & ~ V_125 ;
V_121 = ( V_113 > V_117 ) ? V_117 : V_113 ;
if ( ! F_98 ( V_115 , V_122 , V_121 , 0 ) ) {
F_87 ( V_122 , V_3 -> V_123 ) ;
break;
}
V_113 -= V_121 ;
}
if ( ! V_115 -> V_84 . V_110 ) {
F_99 ( V_115 ) ;
return NULL ;
}
return V_115 ;
}
static void F_100 ( struct V_2 * V_3 , struct V_81 * V_115 )
{
unsigned int V_59 ;
struct V_92 * V_126 ;
F_101 (bv, clone, i) {
F_102 ( ! V_126 -> V_95 ) ;
F_87 ( V_126 -> V_95 , V_3 -> V_123 ) ;
V_126 -> V_95 = NULL ;
}
}
static void F_103 ( struct V_106 * V_107 , struct V_2 * V_3 ,
struct V_81 * V_81 , T_3 V_77 )
{
V_107 -> V_3 = V_3 ;
V_107 -> V_105 = V_81 ;
V_107 -> V_77 = V_77 ;
V_107 -> error = 0 ;
V_107 -> V_127 = NULL ;
V_107 -> V_63 . V_90 = NULL ;
F_89 ( & V_107 -> V_128 , 0 ) ;
}
static void F_104 ( struct V_106 * V_107 )
{
F_90 ( & V_107 -> V_128 ) ;
}
static void F_105 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_105 = V_107 -> V_105 ;
struct V_106 * V_127 = V_107 -> V_127 ;
int error = V_107 -> error ;
if ( ! F_106 ( & V_107 -> V_128 ) )
return;
if ( V_107 -> V_63 . V_90 )
F_85 ( V_3 , V_107 -> V_63 . V_90 , V_105 ) ;
if ( V_107 != F_86 ( V_105 , V_3 -> V_108 ) )
F_87 ( V_107 , V_3 -> V_129 ) ;
if ( F_107 ( ! V_127 ) )
F_108 ( V_105 , error ) ;
else {
if ( error && ! V_127 -> error )
V_127 -> error = error ;
F_105 ( V_127 ) ;
}
}
static void F_109 ( struct V_81 * V_115 , int error )
{
struct V_106 * V_107 = V_115 -> V_130 ;
struct V_2 * V_3 = V_107 -> V_3 ;
unsigned V_131 = F_51 ( V_115 ) ;
if ( F_110 ( ! F_111 ( V_115 , V_132 ) && ! error ) )
error = - V_133 ;
if ( V_131 == V_65 )
F_100 ( V_3 , V_115 ) ;
F_99 ( V_115 ) ;
if ( V_131 == V_134 && ! error ) {
F_112 ( V_107 ) ;
return;
}
if ( F_110 ( error ) )
V_107 -> error = error ;
F_105 ( V_107 ) ;
}
static void F_97 ( struct V_106 * V_107 , struct V_81 * V_115 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
V_115 -> V_130 = V_107 ;
V_115 -> V_135 = F_109 ;
V_115 -> V_136 = V_3 -> V_137 -> V_138 ;
V_115 -> V_139 = V_107 -> V_105 -> V_139 ;
}
static int F_113 ( struct V_106 * V_107 , T_4 V_140 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_105 = V_107 -> V_105 ;
struct V_81 * V_115 ;
V_115 = F_114 ( V_105 , V_140 , V_3 -> V_43 ) ;
if ( ! V_115 )
return 1 ;
F_104 ( V_107 ) ;
F_97 ( V_107 , V_115 ) ;
V_115 -> V_84 . V_141 = V_3 -> V_142 + V_107 -> V_77 ;
F_115 ( V_115 ) ;
return 0 ;
}
static void F_116 ( struct V_106 * V_107 )
{
struct V_81 * V_115 = V_107 -> V_63 . V_82 ;
F_115 ( V_115 ) ;
}
static void F_117 ( struct V_143 * V_144 )
{
struct V_106 * V_107 = F_118 ( V_144 , struct V_106 , V_144 ) ;
if ( F_51 ( V_107 -> V_105 ) == V_134 ) {
F_104 ( V_107 ) ;
if ( F_113 ( V_107 , V_102 ) )
V_107 -> error = - V_42 ;
F_105 ( V_107 ) ;
} else
F_116 ( V_107 ) ;
}
static void F_119 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
F_120 ( & V_107 -> V_144 , F_117 ) ;
F_121 ( V_3 -> V_145 , & V_107 -> V_144 ) ;
}
static void F_122 ( struct V_106 * V_107 , int V_146 )
{
struct V_81 * V_115 = V_107 -> V_63 . V_82 ;
struct V_2 * V_3 = V_107 -> V_3 ;
if ( F_110 ( V_107 -> error < 0 ) ) {
F_100 ( V_3 , V_115 ) ;
F_99 ( V_115 ) ;
F_105 ( V_107 ) ;
return;
}
F_102 ( V_107 -> V_63 . V_85 . V_110 ) ;
V_115 -> V_84 . V_141 = V_3 -> V_142 + V_107 -> V_77 ;
if ( V_146 )
F_119 ( V_107 ) ;
else
F_115 ( V_115 ) ;
}
static void F_123 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
struct V_81 * V_115 ;
struct V_106 * V_147 ;
int V_148 ;
unsigned V_114 = 0 ;
unsigned V_149 = V_107 -> V_105 -> V_84 . V_110 ;
T_3 V_77 = V_107 -> V_77 ;
int V_31 ;
F_104 ( V_107 ) ;
F_66 ( V_3 , & V_107 -> V_63 , NULL , V_107 -> V_105 , V_77 ) ;
while ( V_149 ) {
V_115 = F_95 ( V_107 , V_149 , & V_114 ) ;
if ( F_110 ( ! V_115 ) ) {
V_107 -> error = - V_42 ;
break;
}
V_107 -> V_63 . V_82 = V_115 ;
V_107 -> V_63 . V_85 = V_115 -> V_84 ;
V_149 -= V_115 -> V_84 . V_110 ;
V_77 += F_124 ( V_115 ) ;
F_104 ( V_107 ) ;
V_31 = F_88 ( V_3 , & V_107 -> V_63 ) ;
if ( V_31 < 0 )
V_107 -> error = - V_133 ;
V_148 = F_106 ( & V_107 -> V_63 . V_109 ) ;
if ( V_148 ) {
F_122 ( V_107 , 0 ) ;
if ( F_110 ( V_31 < 0 ) )
break;
V_107 -> V_77 = V_77 ;
}
if ( F_110 ( V_114 ) )
F_125 ( V_150 , V_151 / 100 ) ;
if ( F_110 ( ! V_148 && V_149 ) ) {
V_147 = F_82 ( V_3 -> V_129 , V_102 ) ;
F_103 ( V_147 , V_107 -> V_3 , V_107 -> V_105 , V_77 ) ;
F_104 ( V_147 ) ;
F_66 ( V_3 , & V_147 -> V_63 , NULL ,
V_107 -> V_105 , V_77 ) ;
V_147 -> V_63 . V_83 = V_107 -> V_63 . V_83 ;
if ( ! V_107 -> V_127 )
V_147 -> V_127 = V_107 ;
else {
V_147 -> V_127 = V_107 -> V_127 ;
F_104 ( V_107 -> V_127 ) ;
F_105 ( V_107 ) ;
}
V_107 = V_147 ;
}
}
F_105 ( V_107 ) ;
}
static void F_126 ( struct V_106 * V_107 )
{
F_105 ( V_107 ) ;
}
static void F_127 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
int V_31 = 0 ;
F_104 ( V_107 ) ;
F_66 ( V_3 , & V_107 -> V_63 , V_107 -> V_105 , V_107 -> V_105 ,
V_107 -> V_77 ) ;
V_31 = F_88 ( V_3 , & V_107 -> V_63 ) ;
if ( V_31 < 0 )
V_107 -> error = - V_133 ;
if ( F_106 ( & V_107 -> V_63 . V_109 ) )
F_126 ( V_107 ) ;
F_105 ( V_107 ) ;
}
static void V_104 ( struct V_152 * V_153 ,
int error )
{
struct V_6 * V_7 = V_153 -> V_55 ;
struct V_80 * V_63 = V_7 -> V_63 ;
struct V_106 * V_107 = F_118 ( V_63 , struct V_106 , V_63 ) ;
struct V_2 * V_3 = V_107 -> V_3 ;
if ( error == - V_112 ) {
F_128 ( & V_63 -> V_88 ) ;
return;
}
if ( ! error && V_3 -> V_97 && V_3 -> V_97 -> V_99 )
error = V_3 -> V_97 -> V_99 ( V_3 , F_70 ( V_3 , V_7 ) , V_7 ) ;
if ( error < 0 )
V_107 -> error = - V_133 ;
F_85 ( V_3 , F_69 ( V_3 , V_7 ) , V_107 -> V_105 ) ;
if ( ! F_106 ( & V_63 -> V_109 ) )
return;
if ( F_51 ( V_107 -> V_105 ) == V_134 )
F_126 ( V_107 ) ;
else
F_122 ( V_107 , 1 ) ;
}
static void F_129 ( struct V_143 * V_144 )
{
struct V_106 * V_107 = F_118 ( V_144 , struct V_106 , V_144 ) ;
if ( F_51 ( V_107 -> V_105 ) == V_134 )
F_127 ( V_107 ) ;
else
F_123 ( V_107 ) ;
}
static void F_112 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_3 ;
F_120 ( & V_107 -> V_144 , F_129 ) ;
F_121 ( V_3 -> V_154 , & V_107 -> V_144 ) ;
}
static int F_130 ( T_1 * V_22 , char * V_155 , unsigned int V_113 )
{
char V_156 [ 3 ] ;
unsigned int V_59 ;
V_156 [ 2 ] = '\0' ;
for ( V_59 = 0 ; V_59 < V_113 ; V_59 ++ ) {
V_156 [ 0 ] = * V_155 ++ ;
V_156 [ 1 ] = * V_155 ++ ;
if ( F_131 ( V_156 , 16 , & V_22 [ V_59 ] ) )
return - V_37 ;
}
if ( * V_155 != '\0' )
return - V_37 ;
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
unsigned V_59 ;
if ( ! V_3 -> V_4 )
return;
for ( V_59 = 0 ; V_59 < V_3 -> V_52 ; V_59 ++ )
if ( V_3 -> V_4 [ V_59 ] && ! F_14 ( V_3 -> V_4 [ V_59 ] ) ) {
F_133 ( V_3 -> V_4 [ V_59 ] ) ;
V_3 -> V_4 [ V_59 ] = NULL ;
}
F_26 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
}
static int F_134 ( struct V_2 * V_3 , char * V_157 )
{
unsigned V_59 ;
int V_21 ;
V_3 -> V_4 = F_135 ( V_3 -> V_52 * sizeof( struct V_1 * ) ,
V_41 ) ;
if ( ! V_3 -> V_4 )
return - V_42 ;
for ( V_59 = 0 ; V_59 < V_3 -> V_52 ; V_59 ++ ) {
V_3 -> V_4 [ V_59 ] = F_136 ( V_157 , 0 , 0 ) ;
if ( F_14 ( V_3 -> V_4 [ V_59 ] ) ) {
V_21 = F_24 ( V_3 -> V_4 [ V_59 ] ) ;
F_132 ( V_3 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_137 ( struct V_2 * V_3 )
{
unsigned V_54 ;
int V_21 = 0 , V_59 , V_31 ;
V_54 = ( V_3 -> V_23 - V_3 -> V_158 ) >> F_31 ( V_3 -> V_52 ) ;
for ( V_59 = 0 ; V_59 < V_3 -> V_52 ; V_59 ++ ) {
V_31 = F_138 ( V_3 -> V_4 [ V_59 ] ,
V_3 -> V_22 + ( V_59 * V_54 ) ,
V_54 ) ;
if ( V_31 )
V_21 = V_31 ;
}
return V_21 ;
}
static int F_139 ( struct V_2 * V_3 , char * V_22 )
{
int V_31 = - V_37 ;
int V_159 = strlen ( V_22 ) ;
if ( V_3 -> V_23 != ( V_159 >> 1 ) )
goto V_78;
if ( ! V_3 -> V_23 && strcmp ( V_22 , L_17 ) )
goto V_78;
if ( V_3 -> V_23 && F_130 ( V_3 -> V_22 , V_22 , V_3 -> V_23 ) < 0 )
goto V_78;
F_140 ( V_160 , & V_3 -> V_26 ) ;
V_31 = F_137 ( V_3 ) ;
V_78:
memset ( V_22 , '0' , V_159 ) ;
return V_31 ;
}
static int F_141 ( struct V_2 * V_3 )
{
F_142 ( V_160 , & V_3 -> V_26 ) ;
memset ( & V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
return F_137 ( V_3 ) ;
}
static void F_143 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
V_33 -> V_161 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_145 )
F_144 ( V_3 -> V_145 ) ;
if ( V_3 -> V_154 )
F_144 ( V_3 -> V_154 ) ;
F_132 ( V_3 ) ;
if ( V_3 -> V_43 )
F_145 ( V_3 -> V_43 ) ;
if ( V_3 -> V_123 )
F_146 ( V_3 -> V_123 ) ;
if ( V_3 -> V_101 )
F_146 ( V_3 -> V_101 ) ;
if ( V_3 -> V_129 )
F_146 ( V_3 -> V_129 ) ;
if ( V_3 -> V_97 && V_3 -> V_97 -> V_162 )
V_3 -> V_97 -> V_162 ( V_3 ) ;
if ( V_3 -> V_137 )
F_147 ( V_33 , V_3 -> V_137 ) ;
F_21 ( V_3 -> V_35 ) ;
F_21 ( V_3 -> V_163 ) ;
F_21 ( V_3 ) ;
}
static int F_148 ( struct V_32 * V_33 ,
char * V_164 , char * V_22 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
char * V_165 , * V_35 , * V_166 , * V_167 , * V_168 , * V_169 ;
char * V_170 = NULL ;
int V_171 = - V_37 ;
char V_172 ;
if ( strchr ( V_164 , '(' ) ) {
V_33 -> error = L_18 ;
return - V_37 ;
}
V_3 -> V_163 = F_149 ( V_164 , V_41 ) ;
if ( ! V_3 -> V_163 )
goto V_173;
V_165 = V_164 ;
V_169 = F_150 ( & V_165 , L_17 ) ;
V_35 = F_150 ( & V_169 , L_19 ) ;
if ( ! V_169 )
V_3 -> V_52 = 1 ;
else if ( sscanf ( V_169 , L_20 , & V_3 -> V_52 , & V_172 ) != 1 ||
! F_151 ( V_3 -> V_52 ) ) {
V_33 -> error = L_21 ;
return - V_37 ;
}
V_3 -> V_51 = V_3 -> V_52 ;
V_3 -> V_158 = 0 ;
V_3 -> V_35 = F_149 ( V_35 , V_41 ) ;
if ( ! V_3 -> V_35 )
goto V_173;
V_166 = F_150 ( & V_165 , L_17 ) ;
V_168 = F_150 ( & V_165 , L_17 ) ;
V_167 = F_150 ( & V_168 , L_19 ) ;
if ( V_165 )
F_152 ( L_22 ) ;
if ( ! V_166 || ( ! strcmp ( V_166 , L_23 ) && ! V_167 ) ) {
V_166 = L_24 ;
V_167 = L_23 ;
}
if ( strcmp ( V_166 , L_25 ) && ! V_167 ) {
V_33 -> error = L_26 ;
return - V_37 ;
}
V_170 = F_135 ( V_174 , V_41 ) ;
if ( ! V_170 )
goto V_173;
V_171 = snprintf ( V_170 , V_174 ,
L_27 , V_166 , V_35 ) ;
if ( V_171 < 0 ) {
F_26 ( V_170 ) ;
goto V_173;
}
V_171 = F_134 ( V_3 , V_170 ) ;
if ( V_171 < 0 ) {
V_33 -> error = L_28 ;
goto V_40;
}
V_3 -> V_8 = F_16 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_8 )
V_3 -> V_8 = F_153 ( V_3 -> V_8 ,
( unsigned int ) ( sizeof( V_47 ) / sizeof( T_1 ) ) ) ;
else if ( V_167 ) {
F_152 ( L_29 ) ;
V_167 = NULL ;
}
if ( V_167 == NULL )
V_3 -> V_97 = NULL ;
else if ( strcmp ( V_167 , L_23 ) == 0 )
V_3 -> V_97 = & V_175 ;
else if ( strcmp ( V_167 , L_30 ) == 0 )
V_3 -> V_97 = & V_176 ;
else if ( strcmp ( V_167 , L_31 ) == 0 )
V_3 -> V_97 = & V_177 ;
else if ( strcmp ( V_167 , L_32 ) == 0 )
V_3 -> V_97 = & V_178 ;
else if ( strcmp ( V_167 , L_33 ) == 0 )
V_3 -> V_97 = & V_179 ;
else if ( strcmp ( V_167 , L_34 ) == 0 ) {
V_3 -> V_97 = & V_180 ;
if ( V_3 -> V_23 % V_3 -> V_51 ) {
V_3 -> V_51 ++ ;
V_3 -> V_158 = V_3 -> V_23 / V_3 -> V_51 ;
}
} else if ( strcmp ( V_167 , L_35 ) == 0 ) {
V_3 -> V_97 = & V_181 ;
V_3 -> V_51 += 2 ;
V_3 -> V_158 = V_3 -> V_8 + V_75 ;
} else {
V_171 = - V_37 ;
V_33 -> error = L_36 ;
goto V_40;
}
V_171 = F_139 ( V_3 , V_22 ) ;
if ( V_171 < 0 ) {
V_33 -> error = L_37 ;
goto V_40;
}
if ( V_3 -> V_97 && V_3 -> V_97 -> V_182 ) {
V_171 = V_3 -> V_97 -> V_182 ( V_3 , V_33 , V_168 ) ;
if ( V_171 < 0 ) {
V_33 -> error = L_38 ;
goto V_40;
}
}
if ( V_3 -> V_97 && V_3 -> V_97 -> V_183 ) {
V_171 = V_3 -> V_97 -> V_183 ( V_3 ) ;
if ( V_171 < 0 ) {
V_33 -> error = L_39 ;
goto V_40;
}
}
V_171 = 0 ;
V_40:
F_26 ( V_170 ) ;
return V_171 ;
V_173:
V_33 -> error = L_40 ;
return - V_42 ;
}
static int F_154 ( struct V_32 * V_33 , unsigned int V_184 , char * * V_185 )
{
struct V_2 * V_3 ;
unsigned int V_23 , V_186 ;
unsigned long long V_187 ;
int V_171 ;
T_5 V_188 ;
struct V_189 V_190 ;
const char * V_191 ;
char V_172 ;
static struct V_192 V_193 [] = {
{ 0 , 1 , L_41 } ,
} ;
if ( V_184 < 5 ) {
V_33 -> error = L_42 ;
return - V_37 ;
}
V_23 = strlen ( V_185 [ 1 ] ) >> 1 ;
V_3 = F_25 ( sizeof( * V_3 ) + V_23 * sizeof( T_1 ) , V_41 ) ;
if ( ! V_3 ) {
V_33 -> error = L_43 ;
return - V_42 ;
}
V_3 -> V_23 = V_23 ;
V_33 -> V_161 = V_3 ;
V_171 = F_148 ( V_33 , V_185 [ 0 ] , V_185 [ 1 ] ) ;
if ( V_171 < 0 )
goto V_40;
V_171 = - V_42 ;
V_3 -> V_129 = F_155 ( V_194 , V_195 ) ;
if ( ! V_3 -> V_129 ) {
V_33 -> error = L_44 ;
goto V_40;
}
V_3 -> V_91 = sizeof( struct V_89 ) ;
V_3 -> V_91 += F_156 ( F_1 ( V_3 ) ) ;
V_3 -> V_91 = F_71 ( V_3 -> V_91 , F_157 ( struct V_6 ) ) ;
if ( F_72 ( F_1 ( V_3 ) ) < V_196 ) {
V_188 = - ( V_3 -> V_91 + sizeof( struct V_6 ) )
& F_72 ( F_1 ( V_3 ) ) ;
} else {
V_188 = F_72 ( F_1 ( V_3 ) ) ;
}
V_3 -> V_101 = F_158 ( V_194 , V_3 -> V_91 +
sizeof( struct V_6 ) + V_188 + V_3 -> V_8 ) ;
if ( ! V_3 -> V_101 ) {
V_33 -> error = L_45 ;
goto V_40;
}
V_3 -> V_108 = V_33 -> V_108 =
F_71 ( sizeof( struct V_106 ) + V_3 -> V_91 +
sizeof( struct V_6 ) + V_188 + V_3 -> V_8 ,
V_197 ) ;
V_3 -> V_123 = F_159 ( V_198 , 0 ) ;
if ( ! V_3 -> V_123 ) {
V_33 -> error = L_46 ;
goto V_40;
}
V_3 -> V_43 = F_160 ( V_194 , 0 ) ;
if ( ! V_3 -> V_43 ) {
V_33 -> error = L_47 ;
goto V_40;
}
V_171 = - V_37 ;
if ( sscanf ( V_185 [ 2 ] , L_48 , & V_187 , & V_172 ) != 1 ) {
V_33 -> error = L_49 ;
goto V_40;
}
V_3 -> V_87 = V_187 ;
if ( F_161 ( V_33 , V_185 [ 3 ] , F_162 ( V_33 -> V_199 ) , & V_3 -> V_137 ) ) {
V_33 -> error = L_50 ;
goto V_40;
}
if ( sscanf ( V_185 [ 4 ] , L_48 , & V_187 , & V_172 ) != 1 ) {
V_33 -> error = L_51 ;
goto V_40;
}
V_3 -> V_142 = V_187 ;
V_185 += 5 ;
V_184 -= 5 ;
if ( V_184 ) {
V_190 . V_184 = V_184 ;
V_190 . V_185 = V_185 ;
V_171 = F_163 ( V_193 , & V_190 , & V_186 , & V_33 -> error ) ;
if ( V_171 )
goto V_40;
V_191 = F_164 ( & V_190 ) ;
if ( V_186 == 1 && V_191 &&
! strcasecmp ( V_191 , L_52 ) )
V_33 -> V_200 = 1 ;
else if ( V_186 ) {
V_171 = - V_37 ;
V_33 -> error = L_53 ;
goto V_40;
}
}
V_171 = - V_42 ;
V_3 -> V_145 = F_165 ( L_54 , V_201 , 1 ) ;
if ( ! V_3 -> V_145 ) {
V_33 -> error = L_55 ;
goto V_40;
}
V_3 -> V_154 = F_165 ( L_56 ,
V_202 | V_201 , 1 ) ;
if ( ! V_3 -> V_154 ) {
V_33 -> error = L_57 ;
goto V_40;
}
V_33 -> V_203 = 1 ;
V_33 -> V_204 = true ;
return 0 ;
V_40:
F_143 ( V_33 ) ;
return V_171 ;
}
static int F_166 ( struct V_32 * V_33 , struct V_81 * V_81 )
{
struct V_106 * V_107 ;
struct V_2 * V_3 = V_33 -> V_161 ;
if ( F_110 ( V_81 -> V_139 & ( V_205 | V_206 ) ) ) {
V_81 -> V_136 = V_3 -> V_137 -> V_138 ;
if ( F_124 ( V_81 ) )
V_81 -> V_84 . V_141 = V_3 -> V_142 +
F_167 ( V_33 , V_81 -> V_84 . V_141 ) ;
return V_207 ;
}
V_107 = F_86 ( V_81 , V_3 -> V_108 ) ;
F_103 ( V_107 , V_3 , V_81 , F_167 ( V_33 , V_81 -> V_84 . V_141 ) ) ;
V_107 -> V_63 . V_90 = (struct V_89 * ) ( V_107 + 1 ) ;
if ( F_51 ( V_107 -> V_105 ) == V_134 ) {
if ( F_113 ( V_107 , V_208 ) )
F_119 ( V_107 ) ;
} else
F_112 ( V_107 ) ;
return V_209 ;
}
static void F_168 ( struct V_32 * V_33 , T_6 type ,
unsigned V_210 , char * V_211 , unsigned V_212 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
unsigned V_59 , V_213 = 0 ;
switch ( type ) {
case V_214 :
V_211 [ 0 ] = '\0' ;
break;
case V_215 :
F_169 ( L_58 , V_3 -> V_163 ) ;
if ( V_3 -> V_23 > 0 )
for ( V_59 = 0 ; V_59 < V_3 -> V_23 ; V_59 ++ )
F_169 ( L_59 , V_3 -> V_22 [ V_59 ] ) ;
else
F_169 ( L_17 ) ;
F_169 ( L_60 , ( unsigned long long ) V_3 -> V_87 ,
V_3 -> V_137 -> V_216 , ( unsigned long long ) V_3 -> V_142 ) ;
if ( V_33 -> V_200 )
F_169 ( L_61 ) ;
break;
}
}
static void F_170 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
F_140 ( V_217 , & V_3 -> V_26 ) ;
}
static int F_171 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
if ( ! F_172 ( V_160 , & V_3 -> V_26 ) ) {
F_173 ( L_62 ) ;
return - V_218 ;
}
return 0 ;
}
static void F_174 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
F_142 ( V_217 , & V_3 -> V_26 ) ;
}
static int F_175 ( struct V_32 * V_33 , unsigned V_184 , char * * V_185 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
int V_171 = - V_37 ;
if ( V_184 < 2 )
goto error;
if ( ! strcasecmp ( V_185 [ 0 ] , L_63 ) ) {
if ( ! F_172 ( V_217 , & V_3 -> V_26 ) ) {
F_152 ( L_64 ) ;
return - V_37 ;
}
if ( V_184 == 3 && ! strcasecmp ( V_185 [ 1 ] , L_65 ) ) {
V_171 = F_139 ( V_3 , V_185 [ 2 ] ) ;
if ( V_171 )
return V_171 ;
if ( V_3 -> V_97 && V_3 -> V_97 -> V_183 )
V_171 = V_3 -> V_97 -> V_183 ( V_3 ) ;
return V_171 ;
}
if ( V_184 == 2 && ! strcasecmp ( V_185 [ 1 ] , L_66 ) ) {
if ( V_3 -> V_97 && V_3 -> V_97 -> V_219 ) {
V_171 = V_3 -> V_97 -> V_219 ( V_3 ) ;
if ( V_171 )
return V_171 ;
}
return F_141 ( V_3 ) ;
}
}
error:
F_152 ( L_67 ) ;
return - V_37 ;
}
static int F_176 ( struct V_32 * V_33 , struct V_220 * V_221 ,
struct V_92 * V_222 , int V_223 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
struct V_224 * V_225 = F_177 ( V_3 -> V_137 -> V_138 ) ;
if ( ! V_225 -> V_226 )
return V_223 ;
V_221 -> V_136 = V_3 -> V_137 -> V_138 ;
V_221 -> V_141 = V_3 -> V_142 + F_167 ( V_33 , V_221 -> V_141 ) ;
return F_178 ( V_223 , V_225 -> V_226 ( V_225 , V_221 , V_222 ) ) ;
}
static int F_179 ( struct V_32 * V_33 ,
T_7 V_227 , void * V_55 )
{
struct V_2 * V_3 = V_33 -> V_161 ;
return V_227 ( V_33 , V_3 -> V_137 , V_3 -> V_142 , V_33 -> V_121 , V_55 ) ;
}
static int T_8 F_180 ( void )
{
int V_31 ;
V_195 = F_181 ( V_106 , 0 ) ;
if ( ! V_195 )
return - V_42 ;
V_31 = F_182 ( & V_228 ) ;
if ( V_31 < 0 ) {
F_173 ( L_68 , V_31 ) ;
F_183 ( V_195 ) ;
}
return V_31 ;
}
static void T_9 F_184 ( void )
{
F_185 ( & V_228 ) ;
F_183 ( V_195 ) ;
}
