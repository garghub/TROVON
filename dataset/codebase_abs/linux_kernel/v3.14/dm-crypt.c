static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_5 * F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_6 [ 0 ] ;
}
static int F_4 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_11 * ) V_7 = F_5 ( V_9 -> V_12 & 0xffffffff ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_13 * ) V_7 = F_7 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 * V_22 ;
int V_23 ;
F_9 ( & V_20 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_18 . V_26 = V_15 -> V_27 ;
V_18 . V_28 = V_29 ;
V_23 = F_10 ( & V_18 , & V_20 , V_3 -> V_25 , V_15 -> V_30 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_3 -> V_31 ;
V_23 = F_11 ( V_22 , V_15 -> V_30 ,
F_12 ( V_15 -> V_27 ) ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
unsigned V_32 = F_12 ( V_15 -> V_27 ) ;
struct V_21 * V_22 ;
int V_33 , V_23 = 0 ;
memset ( V_15 -> V_30 , 0 , V_32 ) ;
V_22 = V_3 -> V_31 ;
V_33 = F_11 ( V_22 , V_15 -> V_30 , V_32 ) ;
if ( V_33 )
V_23 = V_33 ;
return V_23 ;
}
static struct V_21 * F_14 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
T_1 * V_30 , unsigned V_36 )
{
struct V_21 * V_22 ;
int V_23 ;
V_22 = F_15 ( V_3 -> V_37 , 0 , V_38 ) ;
if ( F_16 ( V_22 ) ) {
V_35 -> error = L_1 ;
return V_22 ;
}
if ( F_17 ( V_22 ) !=
F_18 ( F_3 ( V_3 ) ) ) {
V_35 -> error = L_2
L_3 ;
F_19 ( V_22 ) ;
return F_20 ( - V_39 ) ;
}
V_23 = F_11 ( V_22 , V_30 , V_36 ) ;
if ( V_23 ) {
V_35 -> error = L_4 ;
F_19 ( V_22 ) ;
return F_20 ( V_23 ) ;
}
return V_22 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
F_22 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
F_23 ( V_15 -> V_30 ) ;
V_15 -> V_30 = NULL ;
V_22 = V_3 -> V_31 ;
if ( V_22 )
F_19 ( V_22 ) ;
V_3 -> V_31 = NULL ;
}
static int F_24 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_21 * V_22 = NULL ;
struct V_41 * V_27 = NULL ;
T_1 * V_30 = NULL ;
int V_23 ;
if ( ! V_40 ) {
V_35 -> error = L_5 ;
return - V_39 ;
}
V_27 = F_25 ( V_40 , 0 , V_38 ) ;
if ( F_16 ( V_27 ) ) {
V_35 -> error = L_6 ;
V_23 = F_26 ( V_27 ) ;
goto V_42;
}
V_30 = F_27 ( F_12 ( V_27 ) , V_43 ) ;
if ( ! V_30 ) {
V_35 -> error = L_7 ;
V_23 = - V_44 ;
goto V_42;
}
V_3 -> V_16 . V_15 . V_30 = V_30 ;
V_3 -> V_16 . V_15 . V_27 = V_27 ;
V_22 = F_14 ( V_3 , V_35 , V_30 ,
F_12 ( V_27 ) ) ;
if ( F_16 ( V_22 ) ) {
F_21 ( V_3 ) ;
return F_26 ( V_22 ) ;
}
V_3 -> V_31 = V_22 ;
return 0 ;
V_42:
if ( V_27 && ! F_16 ( V_27 ) )
F_22 ( V_27 ) ;
F_28 ( V_30 ) ;
return V_23 ;
}
static int F_29 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_21 * V_22 = V_3 -> V_31 ;
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_13 * ) V_7 = F_7 ( V_9 -> V_12 ) ;
F_30 ( V_22 , V_7 , V_7 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
unsigned V_45 = F_32 ( F_3 ( V_3 ) ) ;
int log = F_33 ( V_45 ) ;
if ( 1 << log != V_45 ) {
V_35 -> error = L_8 ;
return - V_39 ;
}
if ( log > 9 ) {
V_35 -> error = L_9 ;
return - V_39 ;
}
V_3 -> V_16 . V_46 . V_47 = 9 - log ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 )
{
}
static int F_35 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_2 V_48 ;
memset ( V_7 , 0 , V_3 -> V_10 - sizeof( V_49 ) ) ;
V_48 = F_36 ( ( ( V_49 ) V_9 -> V_12 << V_3 -> V_16 . V_46 . V_47 ) + 1 ) ;
F_37 ( V_48 , ( T_2 * ) ( V_7 + V_3 -> V_10 - sizeof( V_49 ) ) ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
if ( V_51 -> V_27 && ! F_16 ( V_51 -> V_27 ) )
F_40 ( V_51 -> V_27 ) ;
V_51 -> V_27 = NULL ;
F_23 ( V_51 -> V_52 ) ;
V_51 -> V_52 = NULL ;
}
static int F_41 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
V_51 -> V_27 = F_42 ( L_10 , 0 , 0 ) ;
if ( F_16 ( V_51 -> V_27 ) ) {
V_35 -> error = L_11 ;
return F_26 ( V_51 -> V_27 ) ;
}
if ( V_3 -> V_53 == V_3 -> V_54 ) {
V_51 -> V_52 = NULL ;
return 0 ;
}
V_51 -> V_52 = F_27 ( V_55 , V_43 ) ;
if ( ! V_51 -> V_52 ) {
F_39 ( V_3 ) ;
V_35 -> error = L_12 ;
return - V_44 ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
int V_56 = V_3 -> V_25 / V_3 -> V_53 ;
if ( V_51 -> V_52 )
memcpy ( V_51 -> V_52 , V_3 -> V_24 + ( V_3 -> V_54 * V_56 ) ,
F_44 ( V_51 -> V_27 ) ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
if ( V_51 -> V_52 )
memset ( V_51 -> V_52 , 0 , V_55 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_57 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
struct {
struct V_58 V_18 ;
char V_59 [ F_47 ( V_51 -> V_27 ) ] ;
} V_60 ;
struct V_61 V_62 ;
V_11 V_63 [ 4 ] ;
int V_64 , V_33 ;
V_60 . V_18 . V_26 = V_51 -> V_27 ;
V_60 . V_18 . V_28 = V_29 ;
V_33 = F_48 ( & V_60 . V_18 ) ;
if ( V_33 )
return V_33 ;
if ( V_51 -> V_52 ) {
V_33 = F_49 ( & V_60 . V_18 , V_51 -> V_52 , V_55 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_49 ( & V_60 . V_18 , V_57 + 16 , 16 * 31 ) ;
if ( V_33 )
return V_33 ;
V_63 [ 0 ] = F_5 ( V_9 -> V_12 & 0xFFFFFFFF ) ;
V_63 [ 1 ] = F_5 ( ( ( ( V_49 ) V_9 -> V_12 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_63 [ 2 ] = F_5 ( 4024 ) ;
V_63 [ 3 ] = 0 ;
V_33 = F_49 ( & V_60 . V_18 , ( T_1 * ) V_63 , sizeof( V_63 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_50 ( & V_60 . V_18 , & V_62 ) ;
if ( V_33 )
return V_33 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
F_51 ( & V_62 . V_66 [ V_64 ] ) ;
memcpy ( V_7 , & V_62 . V_66 , V_3 -> V_10 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_67 ;
int V_33 = 0 ;
if ( F_53 ( V_9 -> V_59 -> V_68 ) == V_69 ) {
V_67 = F_54 ( F_55 ( & V_9 -> V_70 ) ) ;
V_33 = F_46 ( V_3 , V_7 , V_9 , V_67 + V_9 -> V_70 . V_71 ) ;
F_56 ( V_67 ) ;
} else
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return V_33 ;
}
static int F_57 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_72 ;
int V_33 ;
if ( F_53 ( V_9 -> V_59 -> V_68 ) == V_69 )
return 0 ;
V_72 = F_54 ( F_55 ( & V_9 -> V_73 ) ) ;
V_33 = F_46 ( V_3 , V_7 , V_9 , V_72 + V_9 -> V_73 . V_71 ) ;
if ( ! V_33 )
F_58 ( V_72 + V_9 -> V_73 . V_71 , V_7 , V_3 -> V_10 ) ;
F_56 ( V_72 ) ;
return V_33 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = & V_3 -> V_16 . V_75 ;
F_23 ( V_75 -> V_76 ) ;
V_75 -> V_76 = NULL ;
F_23 ( V_75 -> V_77 ) ;
V_75 -> V_77 = NULL ;
if ( V_75 -> V_78 && ! F_16 ( V_75 -> V_78 ) )
F_40 ( V_75 -> V_78 ) ;
V_75 -> V_78 = NULL ;
}
static int F_60 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_74 * V_75 = & V_3 -> V_16 . V_75 ;
if ( V_3 -> V_25 <= ( V_3 -> V_10 + V_79 ) ) {
V_35 -> error = L_13 ;
return - V_39 ;
}
V_75 -> V_78 = F_42 ( L_14 , 0 , 0 ) ;
if ( F_16 ( V_75 -> V_78 ) ) {
V_35 -> error = L_15 ;
return F_26 ( V_75 -> V_78 ) ;
}
V_75 -> V_76 = F_27 ( V_3 -> V_10 , V_43 ) ;
V_75 -> V_77 = F_27 ( V_79 , V_43 ) ;
if ( ! V_75 -> V_76 || ! V_75 -> V_77 ) {
F_59 ( V_3 ) ;
V_35 -> error = L_16 ;
return - V_44 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = & V_3 -> V_16 . V_75 ;
int V_80 = V_3 -> V_25 - V_3 -> V_10 - V_79 ;
memcpy ( V_75 -> V_76 , & V_3 -> V_24 [ V_80 ] , V_3 -> V_10 ) ;
memcpy ( V_75 -> V_77 , & V_3 -> V_24 [ V_80 + V_3 -> V_10 ] ,
V_79 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = & V_3 -> V_16 . V_75 ;
memset ( V_75 -> V_76 , 0 , V_3 -> V_10 ) ;
memset ( V_75 -> V_77 , 0 , V_79 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
T_1 * V_57 )
{
struct V_74 * V_75 = & V_3 -> V_16 . V_75 ;
V_49 V_81 = F_7 ( ( V_49 ) V_9 -> V_12 ) ;
T_1 V_63 [ V_79 ] ;
struct {
struct V_58 V_18 ;
char V_59 [ F_47 ( V_75 -> V_78 ) ] ;
} V_60 ;
int V_64 , V_33 ;
memcpy ( V_63 , V_75 -> V_77 , V_79 ) ;
F_58 ( V_63 , ( T_1 * ) & V_81 , 8 ) ;
F_58 ( & V_63 [ 8 ] , ( T_1 * ) & V_81 , 8 ) ;
V_60 . V_18 . V_26 = V_75 -> V_78 ;
V_60 . V_18 . V_28 = V_29 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
V_33 = F_48 ( & V_60 . V_18 ) ;
if ( V_33 )
goto V_82;
V_33 = F_49 ( & V_60 . V_18 , & V_63 [ V_64 * 4 ] , 4 ) ;
if ( V_33 )
goto V_82;
V_33 = F_64 ( & V_60 . V_18 , & V_63 [ V_64 * 4 ] ) ;
if ( V_33 )
goto V_82;
}
F_58 ( & V_63 [ 0 ] , & V_63 [ 12 ] , 4 ) ;
F_58 ( & V_63 [ 4 ] , & V_63 [ 8 ] , 4 ) ;
for ( V_64 = 0 ; V_64 < ( ( 1 << V_83 ) / 8 ) ; V_64 ++ )
F_58 ( V_57 + V_64 * 8 , V_63 , 8 ) ;
V_82:
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
return V_33 ;
}
static int F_65 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_74 * V_75 = & V_3 -> V_16 . V_75 ;
V_49 V_81 = F_7 ( ( V_49 ) V_9 -> V_12 ) ;
T_1 * V_67 ;
int V_33 = 0 ;
if ( F_53 ( V_9 -> V_59 -> V_68 ) != V_69 ) {
V_67 = F_54 ( F_55 ( & V_9 -> V_70 ) ) ;
V_33 = F_63 ( V_3 , V_9 , V_67 + V_9 -> V_70 . V_71 ) ;
F_56 ( V_67 ) ;
}
memcpy ( V_7 , V_75 -> V_76 , V_3 -> V_10 ) ;
F_58 ( V_7 , ( T_1 * ) & V_81 , 8 ) ;
if ( V_3 -> V_10 > 8 )
F_58 ( & V_7 [ 8 ] , ( T_1 * ) & V_81 , V_3 -> V_10 - 8 ) ;
return V_33 ;
}
static int F_66 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_72 ;
int V_33 ;
if ( F_53 ( V_9 -> V_59 -> V_68 ) != V_69 )
return 0 ;
V_72 = F_54 ( F_55 ( & V_9 -> V_73 ) ) ;
V_33 = F_63 ( V_3 , V_9 , V_72 + V_9 -> V_73 . V_71 ) ;
F_56 ( V_72 ) ;
return V_33 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_84 * V_59 ,
struct V_85 * V_86 , struct V_85 * V_68 ,
T_3 V_81 )
{
V_59 -> V_68 = V_68 ;
V_59 -> V_86 = V_86 ;
if ( V_68 )
V_59 -> V_87 = V_68 -> V_88 ;
if ( V_86 )
V_59 -> V_89 = V_86 -> V_88 ;
V_59 -> V_90 = V_81 + V_3 -> V_91 ;
F_68 ( & V_59 -> V_92 ) ;
}
static struct V_8 * F_69 ( struct V_2 * V_3 ,
struct V_93 * V_94 )
{
return (struct V_8 * ) ( ( char * ) V_94 + V_3 -> V_95 ) ;
}
static struct V_93 * F_70 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return (struct V_93 * ) ( ( char * ) V_9 - V_3 -> V_95 ) ;
}
static T_1 * F_71 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return ( T_1 * ) F_72 ( ( unsigned long ) ( V_9 + 1 ) ,
F_73 ( F_3 ( V_3 ) ) + 1 ) ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_84 * V_59 ,
struct V_93 * V_94 )
{
struct V_96 V_97 = F_75 ( V_59 -> V_68 , V_59 -> V_87 ) ;
struct V_96 V_98 = F_75 ( V_59 -> V_86 , V_59 -> V_89 ) ;
struct V_8 * V_9 ;
T_1 * V_7 ;
int V_33 ;
V_9 = F_69 ( V_3 , V_94 ) ;
V_7 = F_71 ( V_3 , V_9 ) ;
V_9 -> V_12 = V_59 -> V_90 ;
V_9 -> V_59 = V_59 ;
F_76 ( & V_9 -> V_70 , 1 ) ;
F_77 ( & V_9 -> V_70 , V_97 . V_99 , 1 << V_83 ,
V_97 . V_100 ) ;
F_76 ( & V_9 -> V_73 , 1 ) ;
F_77 ( & V_9 -> V_73 , V_98 . V_99 , 1 << V_83 ,
V_98 . V_100 ) ;
F_78 ( V_59 -> V_68 , & V_59 -> V_87 , 1 << V_83 ) ;
F_78 ( V_59 -> V_86 , & V_59 -> V_89 , 1 << V_83 ) ;
if ( V_3 -> V_101 ) {
V_33 = V_3 -> V_101 -> V_102 ( V_3 , V_7 , V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
}
F_79 ( V_94 , & V_9 -> V_70 , & V_9 -> V_73 ,
1 << V_83 , V_7 ) ;
if ( F_53 ( V_59 -> V_68 ) == V_69 )
V_33 = F_80 ( V_94 ) ;
else
V_33 = F_81 ( V_94 ) ;
if ( ! V_33 && V_3 -> V_101 && V_3 -> V_101 -> V_103 )
V_33 = V_3 -> V_101 -> V_103 ( V_3 , V_7 , V_9 ) ;
return V_33 ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_84 * V_59 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
unsigned V_105 = V_59 -> V_90 & ( V_3 -> V_54 - 1 ) ;
if ( ! V_104 -> V_94 )
V_104 -> V_94 = F_83 ( V_3 -> V_106 , V_107 ) ;
F_84 ( V_104 -> V_94 , V_3 -> V_6 [ V_105 ] ) ;
F_85 ( V_104 -> V_94 ,
V_108 | V_29 ,
V_109 , F_69 ( V_3 , V_104 -> V_94 ) ) ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_84 * V_59 )
{
struct V_1 * V_104 = F_1 ( V_3 ) ;
int V_33 ;
F_87 ( & V_59 -> V_110 , 1 ) ;
while ( V_59 -> V_87 . V_111 && V_59 -> V_89 . V_111 ) {
F_82 ( V_3 , V_59 ) ;
F_88 ( & V_59 -> V_110 ) ;
V_33 = F_74 ( V_3 , V_59 , V_104 -> V_94 ) ;
switch ( V_33 ) {
case - V_112 :
F_89 ( & V_59 -> V_92 ) ;
F_90 ( & V_59 -> V_92 ) ;
case - V_113 :
V_104 -> V_94 = NULL ;
V_59 -> V_90 ++ ;
continue;
case 0 :
F_91 ( & V_59 -> V_110 ) ;
V_59 -> V_90 ++ ;
F_92 () ;
continue;
default:
F_91 ( & V_59 -> V_110 ) ;
return V_33 ;
}
}
return 0 ;
}
static struct V_85 * F_93 ( struct V_114 * V_115 , unsigned V_116 ,
unsigned * V_117 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
struct V_85 * V_118 ;
unsigned int V_119 = ( V_116 + V_120 - 1 ) >> V_121 ;
T_4 V_122 = V_107 | V_123 ;
unsigned V_64 , V_124 ;
struct V_125 * V_125 ;
V_118 = F_94 ( V_107 , V_119 , V_3 -> V_45 ) ;
if ( ! V_118 )
return NULL ;
F_95 ( V_115 , V_118 ) ;
* V_117 = 0 ;
for ( V_64 = 0 ; V_64 < V_119 ; V_64 ++ ) {
V_125 = F_83 ( V_3 -> V_126 , V_122 ) ;
if ( ! V_125 ) {
* V_117 = 1 ;
break;
}
V_122 = ( V_122 | V_127 ) & ~ V_128 ;
V_124 = ( V_116 > V_120 ) ? V_120 : V_116 ;
if ( ! F_96 ( V_118 , V_125 , V_124 , 0 ) ) {
F_97 ( V_125 , V_3 -> V_126 ) ;
break;
}
V_116 -= V_124 ;
}
if ( ! V_118 -> V_88 . V_111 ) {
F_98 ( V_118 ) ;
return NULL ;
}
return V_118 ;
}
static void F_99 ( struct V_2 * V_3 , struct V_85 * V_118 )
{
unsigned int V_64 ;
struct V_96 * V_129 ;
F_100 (bv, clone, i) {
F_101 ( ! V_129 -> V_99 ) ;
F_97 ( V_129 -> V_99 , V_3 -> V_126 ) ;
V_129 -> V_99 = NULL ;
}
}
static struct V_114 * F_102 ( struct V_2 * V_3 ,
struct V_85 * V_85 , T_3 V_81 )
{
struct V_114 * V_115 ;
V_115 = F_83 ( V_3 -> V_130 , V_107 ) ;
V_115 -> V_3 = V_3 ;
V_115 -> V_131 = V_85 ;
V_115 -> V_81 = V_81 ;
V_115 -> error = 0 ;
V_115 -> V_132 = NULL ;
F_87 ( & V_115 -> V_133 , 0 ) ;
return V_115 ;
}
static void F_103 ( struct V_114 * V_115 )
{
F_88 ( & V_115 -> V_133 ) ;
}
static void F_104 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
struct V_85 * V_131 = V_115 -> V_131 ;
struct V_114 * V_132 = V_115 -> V_132 ;
int error = V_115 -> error ;
if ( ! F_105 ( & V_115 -> V_133 ) )
return;
F_97 ( V_115 , V_3 -> V_130 ) ;
if ( F_106 ( ! V_132 ) )
F_107 ( V_131 , error ) ;
else {
if ( error && ! V_132 -> error )
V_132 -> error = error ;
F_104 ( V_132 ) ;
}
}
static void F_108 ( struct V_85 * V_118 , int error )
{
struct V_114 * V_115 = V_118 -> V_134 ;
struct V_2 * V_3 = V_115 -> V_3 ;
unsigned V_135 = F_53 ( V_118 ) ;
if ( F_109 ( ! F_110 ( V_118 , V_136 ) && ! error ) )
error = - V_137 ;
if ( V_135 == V_69 )
F_99 ( V_3 , V_118 ) ;
F_98 ( V_118 ) ;
if ( V_135 == V_138 && ! error ) {
F_111 ( V_115 ) ;
return;
}
if ( F_109 ( error ) )
V_115 -> error = error ;
F_104 ( V_115 ) ;
}
static void F_95 ( struct V_114 * V_115 , struct V_85 * V_118 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
V_118 -> V_134 = V_115 ;
V_118 -> V_139 = F_108 ;
V_118 -> V_140 = V_3 -> V_141 -> V_142 ;
V_118 -> V_143 = V_115 -> V_131 -> V_143 ;
}
static int F_112 ( struct V_114 * V_115 , T_4 V_144 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
struct V_85 * V_131 = V_115 -> V_131 ;
struct V_85 * V_118 ;
V_118 = F_113 ( V_131 , V_144 , V_3 -> V_45 ) ;
if ( ! V_118 )
return 1 ;
F_103 ( V_115 ) ;
F_95 ( V_115 , V_118 ) ;
V_118 -> V_88 . V_145 = V_3 -> V_146 + V_115 -> V_81 ;
F_114 ( V_118 ) ;
return 0 ;
}
static void F_115 ( struct V_114 * V_115 )
{
struct V_85 * V_118 = V_115 -> V_59 . V_86 ;
F_114 ( V_118 ) ;
}
static void F_116 ( struct V_147 * V_148 )
{
struct V_114 * V_115 = F_117 ( V_148 , struct V_114 , V_148 ) ;
if ( F_53 ( V_115 -> V_131 ) == V_138 ) {
F_103 ( V_115 ) ;
if ( F_112 ( V_115 , V_107 ) )
V_115 -> error = - V_44 ;
F_104 ( V_115 ) ;
} else
F_115 ( V_115 ) ;
}
static void F_118 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
F_119 ( & V_115 -> V_148 , F_116 ) ;
F_120 ( V_3 -> V_149 , & V_115 -> V_148 ) ;
}
static void F_121 ( struct V_114 * V_115 , int V_150 )
{
struct V_85 * V_118 = V_115 -> V_59 . V_86 ;
struct V_2 * V_3 = V_115 -> V_3 ;
if ( F_109 ( V_115 -> error < 0 ) ) {
F_99 ( V_3 , V_118 ) ;
F_98 ( V_118 ) ;
F_104 ( V_115 ) ;
return;
}
F_101 ( V_115 -> V_59 . V_89 . V_111 ) ;
V_118 -> V_88 . V_145 = V_3 -> V_146 + V_115 -> V_81 ;
if ( V_150 )
F_118 ( V_115 ) ;
else
F_114 ( V_118 ) ;
}
static void F_122 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
struct V_85 * V_118 ;
struct V_114 * V_151 ;
int V_152 ;
unsigned V_117 = 0 ;
unsigned V_153 = V_115 -> V_131 -> V_88 . V_111 ;
T_3 V_81 = V_115 -> V_81 ;
int V_33 ;
F_103 ( V_115 ) ;
F_67 ( V_3 , & V_115 -> V_59 , NULL , V_115 -> V_131 , V_81 ) ;
while ( V_153 ) {
V_118 = F_93 ( V_115 , V_153 , & V_117 ) ;
if ( F_109 ( ! V_118 ) ) {
V_115 -> error = - V_44 ;
break;
}
V_115 -> V_59 . V_86 = V_118 ;
V_115 -> V_59 . V_89 = V_118 -> V_88 ;
V_153 -= V_118 -> V_88 . V_111 ;
V_81 += F_123 ( V_118 ) ;
F_103 ( V_115 ) ;
V_33 = F_86 ( V_3 , & V_115 -> V_59 ) ;
if ( V_33 < 0 )
V_115 -> error = - V_137 ;
V_152 = F_105 ( & V_115 -> V_59 . V_110 ) ;
if ( V_152 ) {
F_121 ( V_115 , 0 ) ;
if ( F_109 ( V_33 < 0 ) )
break;
V_115 -> V_81 = V_81 ;
}
if ( F_109 ( V_117 ) )
F_124 ( V_154 , V_155 / 100 ) ;
if ( F_109 ( ! V_152 && V_153 ) ) {
V_151 = F_102 ( V_115 -> V_3 , V_115 -> V_131 ,
V_81 ) ;
F_103 ( V_151 ) ;
F_67 ( V_3 , & V_151 -> V_59 , NULL ,
V_115 -> V_131 , V_81 ) ;
V_151 -> V_59 . V_87 = V_115 -> V_59 . V_87 ;
if ( ! V_115 -> V_132 )
V_151 -> V_132 = V_115 ;
else {
V_151 -> V_132 = V_115 -> V_132 ;
F_103 ( V_115 -> V_132 ) ;
F_104 ( V_115 ) ;
}
V_115 = V_151 ;
}
}
F_104 ( V_115 ) ;
}
static void F_125 ( struct V_114 * V_115 )
{
F_104 ( V_115 ) ;
}
static void F_126 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
int V_33 = 0 ;
F_103 ( V_115 ) ;
F_67 ( V_3 , & V_115 -> V_59 , V_115 -> V_131 , V_115 -> V_131 ,
V_115 -> V_81 ) ;
V_33 = F_86 ( V_3 , & V_115 -> V_59 ) ;
if ( V_33 < 0 )
V_115 -> error = - V_137 ;
if ( F_105 ( & V_115 -> V_59 . V_110 ) )
F_125 ( V_115 ) ;
F_104 ( V_115 ) ;
}
static void V_109 ( struct V_156 * V_157 ,
int error )
{
struct V_8 * V_9 = V_157 -> V_57 ;
struct V_84 * V_59 = V_9 -> V_59 ;
struct V_114 * V_115 = F_117 ( V_59 , struct V_114 , V_59 ) ;
struct V_2 * V_3 = V_115 -> V_3 ;
if ( error == - V_113 ) {
F_127 ( & V_59 -> V_92 ) ;
return;
}
if ( ! error && V_3 -> V_101 && V_3 -> V_101 -> V_103 )
error = V_3 -> V_101 -> V_103 ( V_3 , F_71 ( V_3 , V_9 ) , V_9 ) ;
if ( error < 0 )
V_115 -> error = - V_137 ;
F_97 ( F_70 ( V_3 , V_9 ) , V_3 -> V_106 ) ;
if ( ! F_105 ( & V_59 -> V_110 ) )
return;
if ( F_53 ( V_115 -> V_131 ) == V_138 )
F_125 ( V_115 ) ;
else
F_121 ( V_115 , 1 ) ;
}
static void F_128 ( struct V_147 * V_148 )
{
struct V_114 * V_115 = F_117 ( V_148 , struct V_114 , V_148 ) ;
if ( F_53 ( V_115 -> V_131 ) == V_138 )
F_126 ( V_115 ) ;
else
F_122 ( V_115 ) ;
}
static void F_111 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = V_115 -> V_3 ;
F_119 ( & V_115 -> V_148 , F_128 ) ;
F_120 ( V_3 -> V_158 , & V_115 -> V_148 ) ;
}
static int F_129 ( T_1 * V_24 , char * V_159 , unsigned int V_116 )
{
char V_160 [ 3 ] ;
unsigned int V_64 ;
V_160 [ 2 ] = '\0' ;
for ( V_64 = 0 ; V_64 < V_116 ; V_64 ++ ) {
V_160 [ 0 ] = * V_159 ++ ;
V_160 [ 1 ] = * V_159 ++ ;
if ( F_130 ( V_160 , 16 , & V_24 [ V_64 ] ) )
return - V_39 ;
}
if ( * V_159 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_131 ( struct V_2 * V_3 )
{
unsigned V_64 ;
if ( ! V_3 -> V_6 )
return;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ )
if ( V_3 -> V_6 [ V_64 ] && ! F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
F_132 ( V_3 -> V_6 [ V_64 ] ) ;
V_3 -> V_6 [ V_64 ] = NULL ;
}
F_28 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
static int F_133 ( struct V_2 * V_3 , char * V_161 )
{
unsigned V_64 ;
int V_23 ;
V_3 -> V_6 = F_134 ( V_3 -> V_54 * sizeof( struct V_5 * ) ,
V_43 ) ;
if ( ! V_3 -> V_6 )
return - V_44 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_3 -> V_6 [ V_64 ] = F_135 ( V_161 , 0 , 0 ) ;
if ( F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
V_23 = F_26 ( V_3 -> V_6 [ V_64 ] ) ;
F_131 ( V_3 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_136 ( struct V_2 * V_3 )
{
unsigned V_56 ;
int V_23 = 0 , V_64 , V_33 ;
V_56 = ( V_3 -> V_25 - V_3 -> V_162 ) >> F_33 ( V_3 -> V_54 ) ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_33 = F_137 ( V_3 -> V_6 [ V_64 ] ,
V_3 -> V_24 + ( V_64 * V_56 ) ,
V_56 ) ;
if ( V_33 )
V_23 = V_33 ;
}
return V_23 ;
}
static int F_138 ( struct V_2 * V_3 , char * V_24 )
{
int V_33 = - V_39 ;
int V_163 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_163 >> 1 ) )
goto V_82;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_17 ) )
goto V_82;
if ( V_3 -> V_25 && F_129 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_82;
F_139 ( V_164 , & V_3 -> V_28 ) ;
V_33 = F_136 ( V_3 ) ;
V_82:
memset ( V_24 , '0' , V_163 ) ;
return V_33 ;
}
static int F_140 ( struct V_2 * V_3 )
{
F_141 ( V_164 , & V_3 -> V_28 ) ;
memset ( & V_3 -> V_24 , 0 , V_3 -> V_25 * sizeof( T_1 ) ) ;
return F_136 ( V_3 ) ;
}
static void F_142 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
struct V_1 * V_166 ;
int V_4 ;
V_35 -> V_165 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_149 )
F_143 ( V_3 -> V_149 ) ;
if ( V_3 -> V_158 )
F_143 ( V_3 -> V_158 ) ;
if ( V_3 -> V_4 )
F_144 (cpu) {
V_166 = F_145 ( V_3 -> V_4 , V_4 ) ;
if ( V_166 -> V_94 )
F_97 ( V_166 -> V_94 , V_3 -> V_106 ) ;
}
F_131 ( V_3 ) ;
if ( V_3 -> V_45 )
F_146 ( V_3 -> V_45 ) ;
if ( V_3 -> V_126 )
F_147 ( V_3 -> V_126 ) ;
if ( V_3 -> V_106 )
F_147 ( V_3 -> V_106 ) ;
if ( V_3 -> V_130 )
F_147 ( V_3 -> V_130 ) ;
if ( V_3 -> V_101 && V_3 -> V_101 -> V_167 )
V_3 -> V_101 -> V_167 ( V_3 ) ;
if ( V_3 -> V_141 )
F_148 ( V_35 , V_3 -> V_141 ) ;
if ( V_3 -> V_4 )
F_149 ( V_3 -> V_4 ) ;
F_23 ( V_3 -> V_37 ) ;
F_23 ( V_3 -> V_168 ) ;
F_23 ( V_3 ) ;
}
static int F_150 ( struct V_34 * V_35 ,
char * V_169 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
char * V_170 , * V_37 , * V_171 , * V_172 , * V_173 , * V_174 ;
char * V_175 = NULL ;
int V_176 = - V_39 ;
char V_177 ;
if ( strchr ( V_169 , '(' ) ) {
V_35 -> error = L_18 ;
return - V_39 ;
}
V_3 -> V_168 = F_151 ( V_169 , V_43 ) ;
if ( ! V_3 -> V_168 )
goto V_178;
V_170 = V_169 ;
V_174 = F_152 ( & V_170 , L_17 ) ;
V_37 = F_152 ( & V_174 , L_19 ) ;
if ( ! V_174 )
V_3 -> V_54 = 1 ;
else if ( sscanf ( V_174 , L_20 , & V_3 -> V_54 , & V_177 ) != 1 ||
! F_153 ( V_3 -> V_54 ) ) {
V_35 -> error = L_21 ;
return - V_39 ;
}
V_3 -> V_53 = V_3 -> V_54 ;
V_3 -> V_162 = 0 ;
V_3 -> V_37 = F_151 ( V_37 , V_43 ) ;
if ( ! V_3 -> V_37 )
goto V_178;
V_171 = F_152 ( & V_170 , L_17 ) ;
V_173 = F_152 ( & V_170 , L_17 ) ;
V_172 = F_152 ( & V_173 , L_19 ) ;
if ( V_170 )
F_154 ( L_22 ) ;
V_3 -> V_4 = F_155 ( sizeof( * ( V_3 -> V_4 ) ) ,
F_156 ( struct V_1 ) ) ;
if ( ! V_3 -> V_4 ) {
V_35 -> error = L_23 ;
goto V_178;
}
if ( ! V_171 || ( ! strcmp ( V_171 , L_24 ) && ! V_172 ) ) {
V_171 = L_25 ;
V_172 = L_24 ;
}
if ( strcmp ( V_171 , L_26 ) && ! V_172 ) {
V_35 -> error = L_27 ;
return - V_39 ;
}
V_175 = F_134 ( V_179 , V_43 ) ;
if ( ! V_175 )
goto V_178;
V_176 = snprintf ( V_175 , V_179 ,
L_28 , V_171 , V_37 ) ;
if ( V_176 < 0 ) {
F_28 ( V_175 ) ;
goto V_178;
}
V_176 = F_133 ( V_3 , V_175 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_29 ;
goto V_42;
}
V_3 -> V_10 = F_18 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_157 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_49 ) / sizeof( T_1 ) ) ) ;
else if ( V_172 ) {
F_154 ( L_30 ) ;
V_172 = NULL ;
}
if ( V_172 == NULL )
V_3 -> V_101 = NULL ;
else if ( strcmp ( V_172 , L_24 ) == 0 )
V_3 -> V_101 = & V_180 ;
else if ( strcmp ( V_172 , L_31 ) == 0 )
V_3 -> V_101 = & V_181 ;
else if ( strcmp ( V_172 , L_32 ) == 0 )
V_3 -> V_101 = & V_182 ;
else if ( strcmp ( V_172 , L_33 ) == 0 )
V_3 -> V_101 = & V_183 ;
else if ( strcmp ( V_172 , L_34 ) == 0 )
V_3 -> V_101 = & V_184 ;
else if ( strcmp ( V_172 , L_35 ) == 0 ) {
V_3 -> V_101 = & V_185 ;
if ( V_3 -> V_25 % V_3 -> V_53 ) {
V_3 -> V_53 ++ ;
V_3 -> V_162 = V_3 -> V_25 / V_3 -> V_53 ;
}
} else if ( strcmp ( V_172 , L_36 ) == 0 ) {
V_3 -> V_101 = & V_186 ;
V_3 -> V_53 += 2 ;
V_3 -> V_162 = V_3 -> V_10 + V_79 ;
} else {
V_176 = - V_39 ;
V_35 -> error = L_37 ;
goto V_42;
}
V_176 = F_138 ( V_3 , V_24 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_38 ;
goto V_42;
}
if ( V_3 -> V_101 && V_3 -> V_101 -> V_187 ) {
V_176 = V_3 -> V_101 -> V_187 ( V_3 , V_35 , V_173 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_39 ;
goto V_42;
}
}
if ( V_3 -> V_101 && V_3 -> V_101 -> V_188 ) {
V_176 = V_3 -> V_101 -> V_188 ( V_3 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_40 ;
goto V_42;
}
}
V_176 = 0 ;
V_42:
F_28 ( V_175 ) ;
return V_176 ;
V_178:
V_35 -> error = L_41 ;
return - V_44 ;
}
static int F_158 ( struct V_34 * V_35 , unsigned int V_189 , char * * V_190 )
{
struct V_2 * V_3 ;
unsigned int V_25 , V_191 ;
unsigned long long V_192 ;
int V_176 ;
struct V_193 V_194 ;
const char * V_195 ;
char V_177 ;
static struct V_196 V_197 [] = {
{ 0 , 1 , L_42 } ,
} ;
if ( V_189 < 5 ) {
V_35 -> error = L_43 ;
return - V_39 ;
}
V_25 = strlen ( V_190 [ 1 ] ) >> 1 ;
V_3 = F_27 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_43 ) ;
if ( ! V_3 ) {
V_35 -> error = L_44 ;
return - V_44 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_165 = V_3 ;
V_176 = F_150 ( V_35 , V_190 [ 0 ] , V_190 [ 1 ] ) ;
if ( V_176 < 0 )
goto V_42;
V_176 = - V_44 ;
V_3 -> V_130 = F_159 ( V_198 , V_199 ) ;
if ( ! V_3 -> V_130 ) {
V_35 -> error = L_45 ;
goto V_42;
}
V_3 -> V_95 = sizeof( struct V_93 ) ;
V_3 -> V_95 += F_160 ( F_3 ( V_3 ) ) ;
V_3 -> V_95 = F_72 ( V_3 -> V_95 , F_161 () ) ;
V_3 -> V_95 += F_73 ( F_3 ( V_3 ) ) &
~ ( F_161 () - 1 ) ;
V_3 -> V_106 = F_162 ( V_198 , V_3 -> V_95 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_106 ) {
V_35 -> error = L_46 ;
goto V_42;
}
V_3 -> V_126 = F_163 ( V_200 , 0 ) ;
if ( ! V_3 -> V_126 ) {
V_35 -> error = L_47 ;
goto V_42;
}
V_3 -> V_45 = F_164 ( V_198 , 0 ) ;
if ( ! V_3 -> V_45 ) {
V_35 -> error = L_48 ;
goto V_42;
}
V_176 = - V_39 ;
if ( sscanf ( V_190 [ 2 ] , L_49 , & V_192 , & V_177 ) != 1 ) {
V_35 -> error = L_50 ;
goto V_42;
}
V_3 -> V_91 = V_192 ;
if ( F_165 ( V_35 , V_190 [ 3 ] , F_166 ( V_35 -> V_201 ) , & V_3 -> V_141 ) ) {
V_35 -> error = L_51 ;
goto V_42;
}
if ( sscanf ( V_190 [ 4 ] , L_49 , & V_192 , & V_177 ) != 1 ) {
V_35 -> error = L_52 ;
goto V_42;
}
V_3 -> V_146 = V_192 ;
V_190 += 5 ;
V_189 -= 5 ;
if ( V_189 ) {
V_194 . V_189 = V_189 ;
V_194 . V_190 = V_190 ;
V_176 = F_167 ( V_197 , & V_194 , & V_191 , & V_35 -> error ) ;
if ( V_176 )
goto V_42;
V_195 = F_168 ( & V_194 ) ;
if ( V_191 == 1 && V_195 &&
! strcasecmp ( V_195 , L_53 ) )
V_35 -> V_202 = 1 ;
else if ( V_191 ) {
V_176 = - V_39 ;
V_35 -> error = L_54 ;
goto V_42;
}
}
V_176 = - V_44 ;
V_3 -> V_149 = F_169 ( L_55 , V_203 , 1 ) ;
if ( ! V_3 -> V_149 ) {
V_35 -> error = L_56 ;
goto V_42;
}
V_3 -> V_158 = F_169 ( L_57 ,
V_204 | V_203 , 1 ) ;
if ( ! V_3 -> V_158 ) {
V_35 -> error = L_58 ;
goto V_42;
}
V_35 -> V_205 = 1 ;
V_35 -> V_206 = true ;
return 0 ;
V_42:
F_142 ( V_35 ) ;
return V_176 ;
}
static int F_170 ( struct V_34 * V_35 , struct V_85 * V_85 )
{
struct V_114 * V_115 ;
struct V_2 * V_3 = V_35 -> V_165 ;
if ( F_109 ( V_85 -> V_143 & ( V_207 | V_208 ) ) ) {
V_85 -> V_140 = V_3 -> V_141 -> V_142 ;
if ( F_123 ( V_85 ) )
V_85 -> V_88 . V_145 = V_3 -> V_146 +
F_171 ( V_35 , V_85 -> V_88 . V_145 ) ;
return V_209 ;
}
V_115 = F_102 ( V_3 , V_85 , F_171 ( V_35 , V_85 -> V_88 . V_145 ) ) ;
if ( F_53 ( V_115 -> V_131 ) == V_138 ) {
if ( F_112 ( V_115 , V_210 ) )
F_118 ( V_115 ) ;
} else
F_111 ( V_115 ) ;
return V_211 ;
}
static void F_172 ( struct V_34 * V_35 , T_5 type ,
unsigned V_212 , char * V_213 , unsigned V_214 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
unsigned V_64 , V_215 = 0 ;
switch ( type ) {
case V_216 :
V_213 [ 0 ] = '\0' ;
break;
case V_217 :
F_173 ( L_59 , V_3 -> V_168 ) ;
if ( V_3 -> V_25 > 0 )
for ( V_64 = 0 ; V_64 < V_3 -> V_25 ; V_64 ++ )
F_173 ( L_60 , V_3 -> V_24 [ V_64 ] ) ;
else
F_173 ( L_17 ) ;
F_173 ( L_61 , ( unsigned long long ) V_3 -> V_91 ,
V_3 -> V_141 -> V_218 , ( unsigned long long ) V_3 -> V_146 ) ;
if ( V_35 -> V_202 )
F_173 ( L_62 ) ;
break;
}
}
static void F_174 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
F_139 ( V_219 , & V_3 -> V_28 ) ;
}
static int F_175 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
if ( ! F_176 ( V_164 , & V_3 -> V_28 ) ) {
F_177 ( L_63 ) ;
return - V_220 ;
}
return 0 ;
}
static void F_178 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
F_141 ( V_219 , & V_3 -> V_28 ) ;
}
static int F_179 ( struct V_34 * V_35 , unsigned V_189 , char * * V_190 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
int V_176 = - V_39 ;
if ( V_189 < 2 )
goto error;
if ( ! strcasecmp ( V_190 [ 0 ] , L_64 ) ) {
if ( ! F_176 ( V_219 , & V_3 -> V_28 ) ) {
F_154 ( L_65 ) ;
return - V_39 ;
}
if ( V_189 == 3 && ! strcasecmp ( V_190 [ 1 ] , L_66 ) ) {
V_176 = F_138 ( V_3 , V_190 [ 2 ] ) ;
if ( V_176 )
return V_176 ;
if ( V_3 -> V_101 && V_3 -> V_101 -> V_188 )
V_176 = V_3 -> V_101 -> V_188 ( V_3 ) ;
return V_176 ;
}
if ( V_189 == 2 && ! strcasecmp ( V_190 [ 1 ] , L_67 ) ) {
if ( V_3 -> V_101 && V_3 -> V_101 -> V_221 ) {
V_176 = V_3 -> V_101 -> V_221 ( V_3 ) ;
if ( V_176 )
return V_176 ;
}
return F_140 ( V_3 ) ;
}
}
error:
F_154 ( L_68 ) ;
return - V_39 ;
}
static int F_180 ( struct V_34 * V_35 , struct V_222 * V_223 ,
struct V_96 * V_224 , int V_225 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
struct V_226 * V_227 = F_181 ( V_3 -> V_141 -> V_142 ) ;
if ( ! V_227 -> V_228 )
return V_225 ;
V_223 -> V_140 = V_3 -> V_141 -> V_142 ;
V_223 -> V_145 = V_3 -> V_146 + F_171 ( V_35 , V_223 -> V_145 ) ;
return F_182 ( V_225 , V_227 -> V_228 ( V_227 , V_223 , V_224 ) ) ;
}
static int F_183 ( struct V_34 * V_35 ,
T_6 V_229 , void * V_57 )
{
struct V_2 * V_3 = V_35 -> V_165 ;
return V_229 ( V_35 , V_3 -> V_141 , V_3 -> V_146 , V_35 -> V_124 , V_57 ) ;
}
static int T_7 F_184 ( void )
{
int V_33 ;
V_199 = F_185 ( V_114 , 0 ) ;
if ( ! V_199 )
return - V_44 ;
V_33 = F_186 ( & V_230 ) ;
if ( V_33 < 0 ) {
F_177 ( L_69 , V_33 ) ;
F_187 ( V_199 ) ;
}
return V_33 ;
}
static void T_8 F_188 ( void )
{
F_189 ( & V_230 ) ;
F_187 ( V_199 ) ;
}
