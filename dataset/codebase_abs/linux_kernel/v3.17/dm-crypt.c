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
struct {
struct V_56 V_16 ;
char V_57 [ F_45 ( V_49 -> V_25 ) ] ;
} V_58 ;
struct V_59 V_60 ;
V_9 V_61 [ 4 ] ;
int V_62 , V_31 ;
V_58 . V_16 . V_24 = V_49 -> V_25 ;
V_58 . V_16 . V_26 = V_27 ;
V_31 = F_46 ( & V_58 . V_16 ) ;
if ( V_31 )
return V_31 ;
if ( V_49 -> V_50 ) {
V_31 = F_47 ( & V_58 . V_16 , V_49 -> V_50 , V_53 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_47 ( & V_58 . V_16 , V_55 + 16 , 16 * 31 ) ;
if ( V_31 )
return V_31 ;
V_61 [ 0 ] = F_3 ( V_7 -> V_10 & 0xFFFFFFFF ) ;
V_61 [ 1 ] = F_3 ( ( ( ( V_47 ) V_7 -> V_10 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_61 [ 2 ] = F_3 ( 4024 ) ;
V_61 [ 3 ] = 0 ;
V_31 = F_47 ( & V_58 . V_16 , ( T_1 * ) V_61 , sizeof( V_61 ) ) ;
if ( V_31 )
return V_31 ;
V_31 = F_48 ( & V_58 . V_16 , & V_60 ) ;
if ( V_31 )
return V_31 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ )
F_49 ( & V_60 . V_64 [ V_62 ] ) ;
memcpy ( V_5 , & V_60 . V_64 , V_3 -> V_8 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_65 ;
int V_31 = 0 ;
if ( F_51 ( V_7 -> V_57 -> V_66 ) == V_67 ) {
V_65 = F_52 ( F_53 ( & V_7 -> V_68 ) ) ;
V_31 = F_44 ( V_3 , V_5 , V_7 , V_65 + V_7 -> V_68 . V_69 ) ;
F_54 ( V_65 ) ;
} else
memset ( V_5 , 0 , V_3 -> V_8 ) ;
return V_31 ;
}
static int F_55 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_70 ;
int V_31 ;
if ( F_51 ( V_7 -> V_57 -> V_66 ) == V_67 )
return 0 ;
V_70 = F_52 ( F_53 ( & V_7 -> V_71 ) ) ;
V_31 = F_44 ( V_3 , V_5 , V_7 , V_70 + V_7 -> V_71 . V_69 ) ;
if ( ! V_31 )
F_56 ( V_70 + V_7 -> V_71 . V_69 , V_5 , V_3 -> V_8 ) ;
F_54 ( V_70 ) ;
return V_31 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = & V_3 -> V_14 . V_73 ;
F_21 ( V_73 -> V_74 ) ;
V_73 -> V_74 = NULL ;
F_21 ( V_73 -> V_75 ) ;
V_73 -> V_75 = NULL ;
if ( V_73 -> V_76 && ! F_14 ( V_73 -> V_76 ) )
F_38 ( V_73 -> V_76 ) ;
V_73 -> V_76 = NULL ;
}
static int F_58 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_72 * V_73 = & V_3 -> V_14 . V_73 ;
if ( V_3 -> V_23 <= ( V_3 -> V_8 + V_77 ) ) {
V_33 -> error = L_13 ;
return - V_37 ;
}
V_73 -> V_76 = F_40 ( L_14 , 0 , 0 ) ;
if ( F_14 ( V_73 -> V_76 ) ) {
V_33 -> error = L_15 ;
return F_24 ( V_73 -> V_76 ) ;
}
V_73 -> V_74 = F_25 ( V_3 -> V_8 , V_41 ) ;
V_73 -> V_75 = F_25 ( V_77 , V_41 ) ;
if ( ! V_73 -> V_74 || ! V_73 -> V_75 ) {
F_57 ( V_3 ) ;
V_33 -> error = L_16 ;
return - V_42 ;
}
return 0 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = & V_3 -> V_14 . V_73 ;
int V_78 = V_3 -> V_23 - V_3 -> V_8 - V_77 ;
memcpy ( V_73 -> V_74 , & V_3 -> V_22 [ V_78 ] , V_3 -> V_8 ) ;
memcpy ( V_73 -> V_75 , & V_3 -> V_22 [ V_78 + V_3 -> V_8 ] ,
V_77 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = & V_3 -> V_14 . V_73 ;
memset ( V_73 -> V_74 , 0 , V_3 -> V_8 ) ;
memset ( V_73 -> V_75 , 0 , V_77 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
T_1 * V_55 )
{
struct V_72 * V_73 = & V_3 -> V_14 . V_73 ;
V_47 V_79 = F_5 ( ( V_47 ) V_7 -> V_10 ) ;
T_1 V_61 [ V_77 ] ;
struct {
struct V_56 V_16 ;
char V_57 [ F_45 ( V_73 -> V_76 ) ] ;
} V_58 ;
int V_62 , V_31 ;
memcpy ( V_61 , V_73 -> V_75 , V_77 ) ;
F_56 ( V_61 , ( T_1 * ) & V_79 , 8 ) ;
F_56 ( & V_61 [ 8 ] , ( T_1 * ) & V_79 , 8 ) ;
V_58 . V_16 . V_24 = V_73 -> V_76 ;
V_58 . V_16 . V_26 = V_27 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
V_31 = F_46 ( & V_58 . V_16 ) ;
if ( V_31 )
goto V_80;
V_31 = F_47 ( & V_58 . V_16 , & V_61 [ V_62 * 4 ] , 4 ) ;
if ( V_31 )
goto V_80;
V_31 = F_62 ( & V_58 . V_16 , & V_61 [ V_62 * 4 ] ) ;
if ( V_31 )
goto V_80;
}
F_56 ( & V_61 [ 0 ] , & V_61 [ 12 ] , 4 ) ;
F_56 ( & V_61 [ 4 ] , & V_61 [ 8 ] , 4 ) ;
for ( V_62 = 0 ; V_62 < ( ( 1 << V_81 ) / 8 ) ; V_62 ++ )
F_56 ( V_55 + V_62 * 8 , V_61 , 8 ) ;
V_80:
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
return V_31 ;
}
static int F_63 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_72 * V_73 = & V_3 -> V_14 . V_73 ;
V_47 V_79 = F_5 ( ( V_47 ) V_7 -> V_10 ) ;
T_1 * V_65 ;
int V_31 = 0 ;
if ( F_51 ( V_7 -> V_57 -> V_66 ) != V_67 ) {
V_65 = F_52 ( F_53 ( & V_7 -> V_68 ) ) ;
V_31 = F_61 ( V_3 , V_7 , V_65 + V_7 -> V_68 . V_69 ) ;
F_54 ( V_65 ) ;
}
memcpy ( V_5 , V_73 -> V_74 , V_3 -> V_8 ) ;
F_56 ( V_5 , ( T_1 * ) & V_79 , 8 ) ;
if ( V_3 -> V_8 > 8 )
F_56 ( & V_5 [ 8 ] , ( T_1 * ) & V_79 , V_3 -> V_8 - 8 ) ;
return V_31 ;
}
static int F_64 ( struct V_2 * V_3 , T_1 * V_5 ,
struct V_6 * V_7 )
{
T_1 * V_70 ;
int V_31 ;
if ( F_51 ( V_7 -> V_57 -> V_66 ) != V_67 )
return 0 ;
V_70 = F_52 ( F_53 ( & V_7 -> V_71 ) ) ;
V_31 = F_61 ( V_3 , V_7 , V_70 + V_7 -> V_71 . V_69 ) ;
F_54 ( V_70 ) ;
return V_31 ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_82 * V_57 ,
struct V_83 * V_84 , struct V_83 * V_66 ,
T_3 V_79 )
{
V_57 -> V_66 = V_66 ;
V_57 -> V_84 = V_84 ;
if ( V_66 )
V_57 -> V_85 = V_66 -> V_86 ;
if ( V_84 )
V_57 -> V_87 = V_84 -> V_86 ;
V_57 -> V_88 = V_79 + V_3 -> V_89 ;
F_66 ( & V_57 -> V_90 ) ;
}
static struct V_6 * F_67 ( struct V_2 * V_3 ,
struct V_91 * V_92 )
{
return (struct V_6 * ) ( ( char * ) V_92 + V_3 -> V_93 ) ;
}
static struct V_91 * F_68 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
return (struct V_91 * ) ( ( char * ) V_7 - V_3 -> V_93 ) ;
}
static T_1 * F_69 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
return ( T_1 * ) F_70 ( ( unsigned long ) ( V_7 + 1 ) ,
F_71 ( F_1 ( V_3 ) ) + 1 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_82 * V_57 ,
struct V_91 * V_92 )
{
struct V_94 V_95 = F_73 ( V_57 -> V_66 , V_57 -> V_85 ) ;
struct V_94 V_96 = F_73 ( V_57 -> V_84 , V_57 -> V_87 ) ;
struct V_6 * V_7 ;
T_1 * V_5 ;
int V_31 ;
V_7 = F_67 ( V_3 , V_92 ) ;
V_5 = F_69 ( V_3 , V_7 ) ;
V_7 -> V_10 = V_57 -> V_88 ;
V_7 -> V_57 = V_57 ;
F_74 ( & V_7 -> V_68 , 1 ) ;
F_75 ( & V_7 -> V_68 , V_95 . V_97 , 1 << V_81 ,
V_95 . V_98 ) ;
F_74 ( & V_7 -> V_71 , 1 ) ;
F_75 ( & V_7 -> V_71 , V_96 . V_97 , 1 << V_81 ,
V_96 . V_98 ) ;
F_76 ( V_57 -> V_66 , & V_57 -> V_85 , 1 << V_81 ) ;
F_76 ( V_57 -> V_84 , & V_57 -> V_87 , 1 << V_81 ) ;
if ( V_3 -> V_99 ) {
V_31 = V_3 -> V_99 -> V_100 ( V_3 , V_5 , V_7 ) ;
if ( V_31 < 0 )
return V_31 ;
}
F_77 ( V_92 , & V_7 -> V_68 , & V_7 -> V_71 ,
1 << V_81 , V_5 ) ;
if ( F_51 ( V_57 -> V_66 ) == V_67 )
V_31 = F_78 ( V_92 ) ;
else
V_31 = F_79 ( V_92 ) ;
if ( ! V_31 && V_3 -> V_99 && V_3 -> V_99 -> V_101 )
V_31 = V_3 -> V_99 -> V_101 ( V_3 , V_5 , V_7 ) ;
return V_31 ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_82 * V_57 )
{
unsigned V_102 = V_57 -> V_88 & ( V_3 -> V_52 - 1 ) ;
if ( ! V_57 -> V_92 )
V_57 -> V_92 = F_81 ( V_3 -> V_103 , V_104 ) ;
F_82 ( V_57 -> V_92 , V_3 -> V_4 [ V_102 ] ) ;
F_83 ( V_57 -> V_92 ,
V_105 | V_27 ,
V_106 , F_67 ( V_3 , V_57 -> V_92 ) ) ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_91 * V_92 , struct V_83 * V_107 )
{
struct V_108 * V_109 = F_85 ( V_107 , V_3 -> V_110 ) ;
if ( (struct V_91 * ) ( V_109 + 1 ) != V_92 )
F_86 ( V_92 , V_3 -> V_103 ) ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_82 * V_57 )
{
int V_31 ;
F_88 ( & V_57 -> V_111 , 1 ) ;
while ( V_57 -> V_85 . V_112 && V_57 -> V_87 . V_112 ) {
F_80 ( V_3 , V_57 ) ;
F_89 ( & V_57 -> V_111 ) ;
V_31 = F_72 ( V_3 , V_57 , V_57 -> V_92 ) ;
switch ( V_31 ) {
case - V_113 :
F_90 ( & V_57 -> V_90 ) ;
F_91 ( & V_57 -> V_90 ) ;
case - V_114 :
V_57 -> V_92 = NULL ;
V_57 -> V_88 ++ ;
continue;
case 0 :
F_92 ( & V_57 -> V_111 ) ;
V_57 -> V_88 ++ ;
F_93 () ;
continue;
default:
F_92 ( & V_57 -> V_111 ) ;
return V_31 ;
}
}
return 0 ;
}
static struct V_83 * F_94 ( struct V_108 * V_109 , unsigned V_115 ,
unsigned * V_116 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
struct V_83 * V_117 ;
unsigned int V_118 = ( V_115 + V_119 - 1 ) >> V_120 ;
T_4 V_121 = V_104 | V_122 ;
unsigned V_62 , V_123 ;
struct V_124 * V_124 ;
V_117 = F_95 ( V_104 , V_118 , V_3 -> V_43 ) ;
if ( ! V_117 )
return NULL ;
F_96 ( V_109 , V_117 ) ;
* V_116 = 0 ;
for ( V_62 = 0 ; V_62 < V_118 ; V_62 ++ ) {
V_124 = F_81 ( V_3 -> V_125 , V_121 ) ;
if ( ! V_124 ) {
* V_116 = 1 ;
break;
}
V_121 = ( V_121 | V_126 ) & ~ V_127 ;
V_123 = ( V_115 > V_119 ) ? V_119 : V_115 ;
if ( ! F_97 ( V_117 , V_124 , V_123 , 0 ) ) {
F_86 ( V_124 , V_3 -> V_125 ) ;
break;
}
V_115 -= V_123 ;
}
if ( ! V_117 -> V_86 . V_112 ) {
F_98 ( V_117 ) ;
return NULL ;
}
return V_117 ;
}
static void F_99 ( struct V_2 * V_3 , struct V_83 * V_117 )
{
unsigned int V_62 ;
struct V_94 * V_128 ;
F_100 (bv, clone, i) {
F_101 ( ! V_128 -> V_97 ) ;
F_86 ( V_128 -> V_97 , V_3 -> V_125 ) ;
V_128 -> V_97 = NULL ;
}
}
static void F_102 ( struct V_108 * V_109 , struct V_2 * V_3 ,
struct V_83 * V_83 , T_3 V_79 )
{
V_109 -> V_3 = V_3 ;
V_109 -> V_107 = V_83 ;
V_109 -> V_79 = V_79 ;
V_109 -> error = 0 ;
V_109 -> V_129 = NULL ;
V_109 -> V_57 . V_92 = NULL ;
F_88 ( & V_109 -> V_130 , 0 ) ;
}
static void F_103 ( struct V_108 * V_109 )
{
F_89 ( & V_109 -> V_130 ) ;
}
static void F_104 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
struct V_83 * V_107 = V_109 -> V_107 ;
struct V_108 * V_129 = V_109 -> V_129 ;
int error = V_109 -> error ;
if ( ! F_105 ( & V_109 -> V_130 ) )
return;
if ( V_109 -> V_57 . V_92 )
F_84 ( V_3 , V_109 -> V_57 . V_92 , V_107 ) ;
if ( V_109 != F_85 ( V_107 , V_3 -> V_110 ) )
F_86 ( V_109 , V_3 -> V_131 ) ;
if ( F_106 ( ! V_129 ) )
F_107 ( V_107 , error ) ;
else {
if ( error && ! V_129 -> error )
V_129 -> error = error ;
F_104 ( V_129 ) ;
}
}
static void F_108 ( struct V_83 * V_117 , int error )
{
struct V_108 * V_109 = V_117 -> V_132 ;
struct V_2 * V_3 = V_109 -> V_3 ;
unsigned V_133 = F_51 ( V_117 ) ;
if ( F_109 ( ! F_110 ( V_117 , V_134 ) && ! error ) )
error = - V_135 ;
if ( V_133 == V_67 )
F_99 ( V_3 , V_117 ) ;
F_98 ( V_117 ) ;
if ( V_133 == V_136 && ! error ) {
F_111 ( V_109 ) ;
return;
}
if ( F_109 ( error ) )
V_109 -> error = error ;
F_104 ( V_109 ) ;
}
static void F_96 ( struct V_108 * V_109 , struct V_83 * V_117 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
V_117 -> V_132 = V_109 ;
V_117 -> V_137 = F_108 ;
V_117 -> V_138 = V_3 -> V_139 -> V_140 ;
V_117 -> V_141 = V_109 -> V_107 -> V_141 ;
}
static int F_112 ( struct V_108 * V_109 , T_4 V_142 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
struct V_83 * V_107 = V_109 -> V_107 ;
struct V_83 * V_117 ;
V_117 = F_113 ( V_107 , V_142 , V_3 -> V_43 ) ;
if ( ! V_117 )
return 1 ;
F_103 ( V_109 ) ;
F_96 ( V_109 , V_117 ) ;
V_117 -> V_86 . V_143 = V_3 -> V_144 + V_109 -> V_79 ;
F_114 ( V_117 ) ;
return 0 ;
}
static void F_115 ( struct V_108 * V_109 )
{
struct V_83 * V_117 = V_109 -> V_57 . V_84 ;
F_114 ( V_117 ) ;
}
static void F_116 ( struct V_145 * V_146 )
{
struct V_108 * V_109 = F_117 ( V_146 , struct V_108 , V_146 ) ;
if ( F_51 ( V_109 -> V_107 ) == V_136 ) {
F_103 ( V_109 ) ;
if ( F_112 ( V_109 , V_104 ) )
V_109 -> error = - V_42 ;
F_104 ( V_109 ) ;
} else
F_115 ( V_109 ) ;
}
static void F_118 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
F_119 ( & V_109 -> V_146 , F_116 ) ;
F_120 ( V_3 -> V_147 , & V_109 -> V_146 ) ;
}
static void F_121 ( struct V_108 * V_109 , int V_148 )
{
struct V_83 * V_117 = V_109 -> V_57 . V_84 ;
struct V_2 * V_3 = V_109 -> V_3 ;
if ( F_109 ( V_109 -> error < 0 ) ) {
F_99 ( V_3 , V_117 ) ;
F_98 ( V_117 ) ;
F_104 ( V_109 ) ;
return;
}
F_101 ( V_109 -> V_57 . V_87 . V_112 ) ;
V_117 -> V_86 . V_143 = V_3 -> V_144 + V_109 -> V_79 ;
if ( V_148 )
F_118 ( V_109 ) ;
else
F_114 ( V_117 ) ;
}
static void F_122 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
struct V_83 * V_117 ;
struct V_108 * V_149 ;
int V_150 ;
unsigned V_116 = 0 ;
unsigned V_151 = V_109 -> V_107 -> V_86 . V_112 ;
T_3 V_79 = V_109 -> V_79 ;
int V_31 ;
F_103 ( V_109 ) ;
F_65 ( V_3 , & V_109 -> V_57 , NULL , V_109 -> V_107 , V_79 ) ;
while ( V_151 ) {
V_117 = F_94 ( V_109 , V_151 , & V_116 ) ;
if ( F_109 ( ! V_117 ) ) {
V_109 -> error = - V_42 ;
break;
}
V_109 -> V_57 . V_84 = V_117 ;
V_109 -> V_57 . V_87 = V_117 -> V_86 ;
V_151 -= V_117 -> V_86 . V_112 ;
V_79 += F_123 ( V_117 ) ;
F_103 ( V_109 ) ;
V_31 = F_87 ( V_3 , & V_109 -> V_57 ) ;
if ( V_31 < 0 )
V_109 -> error = - V_135 ;
V_150 = F_105 ( & V_109 -> V_57 . V_111 ) ;
if ( V_150 ) {
F_121 ( V_109 , 0 ) ;
if ( F_109 ( V_31 < 0 ) )
break;
V_109 -> V_79 = V_79 ;
}
if ( F_109 ( V_116 ) )
F_124 ( V_152 , V_153 / 100 ) ;
if ( F_109 ( ! V_150 && V_151 ) ) {
V_149 = F_81 ( V_3 -> V_131 , V_104 ) ;
F_102 ( V_149 , V_109 -> V_3 , V_109 -> V_107 , V_79 ) ;
F_103 ( V_149 ) ;
F_65 ( V_3 , & V_149 -> V_57 , NULL ,
V_109 -> V_107 , V_79 ) ;
V_149 -> V_57 . V_85 = V_109 -> V_57 . V_85 ;
if ( ! V_109 -> V_129 )
V_149 -> V_129 = V_109 ;
else {
V_149 -> V_129 = V_109 -> V_129 ;
F_103 ( V_109 -> V_129 ) ;
F_104 ( V_109 ) ;
}
V_109 = V_149 ;
}
}
F_104 ( V_109 ) ;
}
static void F_125 ( struct V_108 * V_109 )
{
F_104 ( V_109 ) ;
}
static void F_126 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
int V_31 = 0 ;
F_103 ( V_109 ) ;
F_65 ( V_3 , & V_109 -> V_57 , V_109 -> V_107 , V_109 -> V_107 ,
V_109 -> V_79 ) ;
V_31 = F_87 ( V_3 , & V_109 -> V_57 ) ;
if ( V_31 < 0 )
V_109 -> error = - V_135 ;
if ( F_105 ( & V_109 -> V_57 . V_111 ) )
F_125 ( V_109 ) ;
F_104 ( V_109 ) ;
}
static void V_106 ( struct V_154 * V_155 ,
int error )
{
struct V_6 * V_7 = V_155 -> V_55 ;
struct V_82 * V_57 = V_7 -> V_57 ;
struct V_108 * V_109 = F_117 ( V_57 , struct V_108 , V_57 ) ;
struct V_2 * V_3 = V_109 -> V_3 ;
if ( error == - V_114 ) {
F_127 ( & V_57 -> V_90 ) ;
return;
}
if ( ! error && V_3 -> V_99 && V_3 -> V_99 -> V_101 )
error = V_3 -> V_99 -> V_101 ( V_3 , F_69 ( V_3 , V_7 ) , V_7 ) ;
if ( error < 0 )
V_109 -> error = - V_135 ;
F_84 ( V_3 , F_68 ( V_3 , V_7 ) , V_109 -> V_107 ) ;
if ( ! F_105 ( & V_57 -> V_111 ) )
return;
if ( F_51 ( V_109 -> V_107 ) == V_136 )
F_125 ( V_109 ) ;
else
F_121 ( V_109 , 1 ) ;
}
static void F_128 ( struct V_145 * V_146 )
{
struct V_108 * V_109 = F_117 ( V_146 , struct V_108 , V_146 ) ;
if ( F_51 ( V_109 -> V_107 ) == V_136 )
F_126 ( V_109 ) ;
else
F_122 ( V_109 ) ;
}
static void F_111 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
F_119 ( & V_109 -> V_146 , F_128 ) ;
F_120 ( V_3 -> V_156 , & V_109 -> V_146 ) ;
}
static int F_129 ( T_1 * V_22 , char * V_157 , unsigned int V_115 )
{
char V_158 [ 3 ] ;
unsigned int V_62 ;
V_158 [ 2 ] = '\0' ;
for ( V_62 = 0 ; V_62 < V_115 ; V_62 ++ ) {
V_158 [ 0 ] = * V_157 ++ ;
V_158 [ 1 ] = * V_157 ++ ;
if ( F_130 ( V_158 , 16 , & V_22 [ V_62 ] ) )
return - V_37 ;
}
if ( * V_157 != '\0' )
return - V_37 ;
return 0 ;
}
static void F_131 ( struct V_2 * V_3 )
{
unsigned V_62 ;
if ( ! V_3 -> V_4 )
return;
for ( V_62 = 0 ; V_62 < V_3 -> V_52 ; V_62 ++ )
if ( V_3 -> V_4 [ V_62 ] && ! F_14 ( V_3 -> V_4 [ V_62 ] ) ) {
F_132 ( V_3 -> V_4 [ V_62 ] ) ;
V_3 -> V_4 [ V_62 ] = NULL ;
}
F_26 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
}
static int F_133 ( struct V_2 * V_3 , char * V_159 )
{
unsigned V_62 ;
int V_21 ;
V_3 -> V_4 = F_134 ( V_3 -> V_52 * sizeof( struct V_1 * ) ,
V_41 ) ;
if ( ! V_3 -> V_4 )
return - V_42 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_52 ; V_62 ++ ) {
V_3 -> V_4 [ V_62 ] = F_135 ( V_159 , 0 , 0 ) ;
if ( F_14 ( V_3 -> V_4 [ V_62 ] ) ) {
V_21 = F_24 ( V_3 -> V_4 [ V_62 ] ) ;
F_131 ( V_3 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_136 ( struct V_2 * V_3 )
{
unsigned V_54 ;
int V_21 = 0 , V_62 , V_31 ;
V_54 = ( V_3 -> V_23 - V_3 -> V_160 ) >> F_31 ( V_3 -> V_52 ) ;
for ( V_62 = 0 ; V_62 < V_3 -> V_52 ; V_62 ++ ) {
V_31 = F_137 ( V_3 -> V_4 [ V_62 ] ,
V_3 -> V_22 + ( V_62 * V_54 ) ,
V_54 ) ;
if ( V_31 )
V_21 = V_31 ;
}
return V_21 ;
}
static int F_138 ( struct V_2 * V_3 , char * V_22 )
{
int V_31 = - V_37 ;
int V_161 = strlen ( V_22 ) ;
if ( V_3 -> V_23 != ( V_161 >> 1 ) )
goto V_80;
if ( ! V_3 -> V_23 && strcmp ( V_22 , L_17 ) )
goto V_80;
if ( V_3 -> V_23 && F_129 ( V_3 -> V_22 , V_22 , V_3 -> V_23 ) < 0 )
goto V_80;
F_139 ( V_162 , & V_3 -> V_26 ) ;
V_31 = F_136 ( V_3 ) ;
V_80:
memset ( V_22 , '0' , V_161 ) ;
return V_31 ;
}
static int F_140 ( struct V_2 * V_3 )
{
F_141 ( V_162 , & V_3 -> V_26 ) ;
memset ( & V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
return F_136 ( V_3 ) ;
}
static void F_142 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
V_33 -> V_163 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_147 )
F_143 ( V_3 -> V_147 ) ;
if ( V_3 -> V_156 )
F_143 ( V_3 -> V_156 ) ;
F_131 ( V_3 ) ;
if ( V_3 -> V_43 )
F_144 ( V_3 -> V_43 ) ;
if ( V_3 -> V_125 )
F_145 ( V_3 -> V_125 ) ;
if ( V_3 -> V_103 )
F_145 ( V_3 -> V_103 ) ;
if ( V_3 -> V_131 )
F_145 ( V_3 -> V_131 ) ;
if ( V_3 -> V_99 && V_3 -> V_99 -> V_164 )
V_3 -> V_99 -> V_164 ( V_3 ) ;
if ( V_3 -> V_139 )
F_146 ( V_33 , V_3 -> V_139 ) ;
F_21 ( V_3 -> V_35 ) ;
F_21 ( V_3 -> V_165 ) ;
F_21 ( V_3 ) ;
}
static int F_147 ( struct V_32 * V_33 ,
char * V_166 , char * V_22 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
char * V_167 , * V_35 , * V_168 , * V_169 , * V_170 , * V_171 ;
char * V_172 = NULL ;
int V_173 = - V_37 ;
char V_174 ;
if ( strchr ( V_166 , '(' ) ) {
V_33 -> error = L_18 ;
return - V_37 ;
}
V_3 -> V_165 = F_148 ( V_166 , V_41 ) ;
if ( ! V_3 -> V_165 )
goto V_175;
V_167 = V_166 ;
V_171 = F_149 ( & V_167 , L_17 ) ;
V_35 = F_149 ( & V_171 , L_19 ) ;
if ( ! V_171 )
V_3 -> V_52 = 1 ;
else if ( sscanf ( V_171 , L_20 , & V_3 -> V_52 , & V_174 ) != 1 ||
! F_150 ( V_3 -> V_52 ) ) {
V_33 -> error = L_21 ;
return - V_37 ;
}
V_3 -> V_51 = V_3 -> V_52 ;
V_3 -> V_160 = 0 ;
V_3 -> V_35 = F_148 ( V_35 , V_41 ) ;
if ( ! V_3 -> V_35 )
goto V_175;
V_168 = F_149 ( & V_167 , L_17 ) ;
V_170 = F_149 ( & V_167 , L_17 ) ;
V_169 = F_149 ( & V_170 , L_19 ) ;
if ( V_167 )
F_151 ( L_22 ) ;
if ( ! V_168 || ( ! strcmp ( V_168 , L_23 ) && ! V_169 ) ) {
V_168 = L_24 ;
V_169 = L_23 ;
}
if ( strcmp ( V_168 , L_25 ) && ! V_169 ) {
V_33 -> error = L_26 ;
return - V_37 ;
}
V_172 = F_134 ( V_176 , V_41 ) ;
if ( ! V_172 )
goto V_175;
V_173 = snprintf ( V_172 , V_176 ,
L_27 , V_168 , V_35 ) ;
if ( V_173 < 0 ) {
F_26 ( V_172 ) ;
goto V_175;
}
V_173 = F_133 ( V_3 , V_172 ) ;
if ( V_173 < 0 ) {
V_33 -> error = L_28 ;
goto V_40;
}
V_3 -> V_8 = F_16 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_8 )
V_3 -> V_8 = F_152 ( V_3 -> V_8 ,
( unsigned int ) ( sizeof( V_47 ) / sizeof( T_1 ) ) ) ;
else if ( V_169 ) {
F_151 ( L_29 ) ;
V_169 = NULL ;
}
if ( V_169 == NULL )
V_3 -> V_99 = NULL ;
else if ( strcmp ( V_169 , L_23 ) == 0 )
V_3 -> V_99 = & V_177 ;
else if ( strcmp ( V_169 , L_30 ) == 0 )
V_3 -> V_99 = & V_178 ;
else if ( strcmp ( V_169 , L_31 ) == 0 )
V_3 -> V_99 = & V_179 ;
else if ( strcmp ( V_169 , L_32 ) == 0 )
V_3 -> V_99 = & V_180 ;
else if ( strcmp ( V_169 , L_33 ) == 0 )
V_3 -> V_99 = & V_181 ;
else if ( strcmp ( V_169 , L_34 ) == 0 ) {
V_3 -> V_99 = & V_182 ;
if ( V_3 -> V_23 % V_3 -> V_51 ) {
V_3 -> V_51 ++ ;
V_3 -> V_160 = V_3 -> V_23 / V_3 -> V_51 ;
}
} else if ( strcmp ( V_169 , L_35 ) == 0 ) {
V_3 -> V_99 = & V_183 ;
V_3 -> V_51 += 2 ;
V_3 -> V_160 = V_3 -> V_8 + V_77 ;
} else {
V_173 = - V_37 ;
V_33 -> error = L_36 ;
goto V_40;
}
V_173 = F_138 ( V_3 , V_22 ) ;
if ( V_173 < 0 ) {
V_33 -> error = L_37 ;
goto V_40;
}
if ( V_3 -> V_99 && V_3 -> V_99 -> V_184 ) {
V_173 = V_3 -> V_99 -> V_184 ( V_3 , V_33 , V_170 ) ;
if ( V_173 < 0 ) {
V_33 -> error = L_38 ;
goto V_40;
}
}
if ( V_3 -> V_99 && V_3 -> V_99 -> V_185 ) {
V_173 = V_3 -> V_99 -> V_185 ( V_3 ) ;
if ( V_173 < 0 ) {
V_33 -> error = L_39 ;
goto V_40;
}
}
V_173 = 0 ;
V_40:
F_26 ( V_172 ) ;
return V_173 ;
V_175:
V_33 -> error = L_40 ;
return - V_42 ;
}
static int F_153 ( struct V_32 * V_33 , unsigned int V_186 , char * * V_187 )
{
struct V_2 * V_3 ;
unsigned int V_23 , V_188 ;
unsigned long long V_189 ;
int V_173 ;
T_5 V_190 ;
struct V_191 V_192 ;
const char * V_193 ;
char V_174 ;
static struct V_194 V_195 [] = {
{ 0 , 1 , L_41 } ,
} ;
if ( V_186 < 5 ) {
V_33 -> error = L_42 ;
return - V_37 ;
}
V_23 = strlen ( V_187 [ 1 ] ) >> 1 ;
V_3 = F_25 ( sizeof( * V_3 ) + V_23 * sizeof( T_1 ) , V_41 ) ;
if ( ! V_3 ) {
V_33 -> error = L_43 ;
return - V_42 ;
}
V_3 -> V_23 = V_23 ;
V_33 -> V_163 = V_3 ;
V_173 = F_147 ( V_33 , V_187 [ 0 ] , V_187 [ 1 ] ) ;
if ( V_173 < 0 )
goto V_40;
V_173 = - V_42 ;
V_3 -> V_131 = F_154 ( V_196 , V_197 ) ;
if ( ! V_3 -> V_131 ) {
V_33 -> error = L_44 ;
goto V_40;
}
V_3 -> V_93 = sizeof( struct V_91 ) ;
V_3 -> V_93 += F_155 ( F_1 ( V_3 ) ) ;
V_3 -> V_93 = F_70 ( V_3 -> V_93 , F_156 ( struct V_6 ) ) ;
if ( F_71 ( F_1 ( V_3 ) ) < V_198 ) {
V_190 = - ( V_3 -> V_93 + sizeof( struct V_6 ) )
& F_71 ( F_1 ( V_3 ) ) ;
} else {
V_190 = F_71 ( F_1 ( V_3 ) ) ;
}
V_3 -> V_103 = F_157 ( V_196 , V_3 -> V_93 +
sizeof( struct V_6 ) + V_190 + V_3 -> V_8 ) ;
if ( ! V_3 -> V_103 ) {
V_33 -> error = L_45 ;
goto V_40;
}
V_3 -> V_110 = V_33 -> V_110 =
F_70 ( sizeof( struct V_108 ) + V_3 -> V_93 +
sizeof( struct V_6 ) + V_190 + V_3 -> V_8 ,
V_199 ) ;
V_3 -> V_125 = F_158 ( V_200 , 0 ) ;
if ( ! V_3 -> V_125 ) {
V_33 -> error = L_46 ;
goto V_40;
}
V_3 -> V_43 = F_159 ( V_196 , 0 ) ;
if ( ! V_3 -> V_43 ) {
V_33 -> error = L_47 ;
goto V_40;
}
V_173 = - V_37 ;
if ( sscanf ( V_187 [ 2 ] , L_48 , & V_189 , & V_174 ) != 1 ) {
V_33 -> error = L_49 ;
goto V_40;
}
V_3 -> V_89 = V_189 ;
if ( F_160 ( V_33 , V_187 [ 3 ] , F_161 ( V_33 -> V_201 ) , & V_3 -> V_139 ) ) {
V_33 -> error = L_50 ;
goto V_40;
}
if ( sscanf ( V_187 [ 4 ] , L_48 , & V_189 , & V_174 ) != 1 ) {
V_33 -> error = L_51 ;
goto V_40;
}
V_3 -> V_144 = V_189 ;
V_187 += 5 ;
V_186 -= 5 ;
if ( V_186 ) {
V_192 . V_186 = V_186 ;
V_192 . V_187 = V_187 ;
V_173 = F_162 ( V_195 , & V_192 , & V_188 , & V_33 -> error ) ;
if ( V_173 )
goto V_40;
V_193 = F_163 ( & V_192 ) ;
if ( V_188 == 1 && V_193 &&
! strcasecmp ( V_193 , L_52 ) )
V_33 -> V_202 = 1 ;
else if ( V_188 ) {
V_173 = - V_37 ;
V_33 -> error = L_53 ;
goto V_40;
}
}
V_173 = - V_42 ;
V_3 -> V_147 = F_164 ( L_54 , V_203 , 1 ) ;
if ( ! V_3 -> V_147 ) {
V_33 -> error = L_55 ;
goto V_40;
}
V_3 -> V_156 = F_164 ( L_56 ,
V_204 | V_203 , 1 ) ;
if ( ! V_3 -> V_156 ) {
V_33 -> error = L_57 ;
goto V_40;
}
V_33 -> V_205 = 1 ;
V_33 -> V_206 = true ;
return 0 ;
V_40:
F_142 ( V_33 ) ;
return V_173 ;
}
static int F_165 ( struct V_32 * V_33 , struct V_83 * V_83 )
{
struct V_108 * V_109 ;
struct V_2 * V_3 = V_33 -> V_163 ;
if ( F_109 ( V_83 -> V_141 & ( V_207 | V_208 ) ) ) {
V_83 -> V_138 = V_3 -> V_139 -> V_140 ;
if ( F_123 ( V_83 ) )
V_83 -> V_86 . V_143 = V_3 -> V_144 +
F_166 ( V_33 , V_83 -> V_86 . V_143 ) ;
return V_209 ;
}
V_109 = F_85 ( V_83 , V_3 -> V_110 ) ;
F_102 ( V_109 , V_3 , V_83 , F_166 ( V_33 , V_83 -> V_86 . V_143 ) ) ;
V_109 -> V_57 . V_92 = (struct V_91 * ) ( V_109 + 1 ) ;
if ( F_51 ( V_109 -> V_107 ) == V_136 ) {
if ( F_112 ( V_109 , V_210 ) )
F_118 ( V_109 ) ;
} else
F_111 ( V_109 ) ;
return V_211 ;
}
static void F_167 ( struct V_32 * V_33 , T_6 type ,
unsigned V_212 , char * V_213 , unsigned V_214 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
unsigned V_62 , V_215 = 0 ;
switch ( type ) {
case V_216 :
V_213 [ 0 ] = '\0' ;
break;
case V_217 :
F_168 ( L_58 , V_3 -> V_165 ) ;
if ( V_3 -> V_23 > 0 )
for ( V_62 = 0 ; V_62 < V_3 -> V_23 ; V_62 ++ )
F_168 ( L_59 , V_3 -> V_22 [ V_62 ] ) ;
else
F_168 ( L_17 ) ;
F_168 ( L_60 , ( unsigned long long ) V_3 -> V_89 ,
V_3 -> V_139 -> V_218 , ( unsigned long long ) V_3 -> V_144 ) ;
if ( V_33 -> V_202 )
F_168 ( L_61 ) ;
break;
}
}
static void F_169 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
F_139 ( V_219 , & V_3 -> V_26 ) ;
}
static int F_170 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
if ( ! F_171 ( V_162 , & V_3 -> V_26 ) ) {
F_172 ( L_62 ) ;
return - V_220 ;
}
return 0 ;
}
static void F_173 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
F_141 ( V_219 , & V_3 -> V_26 ) ;
}
static int F_174 ( struct V_32 * V_33 , unsigned V_186 , char * * V_187 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
int V_173 = - V_37 ;
if ( V_186 < 2 )
goto error;
if ( ! strcasecmp ( V_187 [ 0 ] , L_63 ) ) {
if ( ! F_171 ( V_219 , & V_3 -> V_26 ) ) {
F_151 ( L_64 ) ;
return - V_37 ;
}
if ( V_186 == 3 && ! strcasecmp ( V_187 [ 1 ] , L_65 ) ) {
V_173 = F_138 ( V_3 , V_187 [ 2 ] ) ;
if ( V_173 )
return V_173 ;
if ( V_3 -> V_99 && V_3 -> V_99 -> V_185 )
V_173 = V_3 -> V_99 -> V_185 ( V_3 ) ;
return V_173 ;
}
if ( V_186 == 2 && ! strcasecmp ( V_187 [ 1 ] , L_66 ) ) {
if ( V_3 -> V_99 && V_3 -> V_99 -> V_221 ) {
V_173 = V_3 -> V_99 -> V_221 ( V_3 ) ;
if ( V_173 )
return V_173 ;
}
return F_140 ( V_3 ) ;
}
}
error:
F_151 ( L_67 ) ;
return - V_37 ;
}
static int F_175 ( struct V_32 * V_33 , struct V_222 * V_223 ,
struct V_94 * V_224 , int V_225 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
struct V_226 * V_227 = F_176 ( V_3 -> V_139 -> V_140 ) ;
if ( ! V_227 -> V_228 )
return V_225 ;
V_223 -> V_138 = V_3 -> V_139 -> V_140 ;
V_223 -> V_143 = V_3 -> V_144 + F_166 ( V_33 , V_223 -> V_143 ) ;
return F_177 ( V_225 , V_227 -> V_228 ( V_227 , V_223 , V_224 ) ) ;
}
static int F_178 ( struct V_32 * V_33 ,
T_7 V_229 , void * V_55 )
{
struct V_2 * V_3 = V_33 -> V_163 ;
return V_229 ( V_33 , V_3 -> V_139 , V_3 -> V_144 , V_33 -> V_123 , V_55 ) ;
}
static int T_8 F_179 ( void )
{
int V_31 ;
V_197 = F_180 ( V_108 , 0 ) ;
if ( ! V_197 )
return - V_42 ;
V_31 = F_181 ( & V_230 ) ;
if ( V_31 < 0 ) {
F_172 ( L_68 , V_31 ) ;
F_182 ( V_197 ) ;
}
return V_31 ;
}
static void T_9 F_183 ( void )
{
F_184 ( & V_230 ) ;
F_182 ( V_197 ) ;
}
