static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 [ 0 ] ;
}
static struct V_6 * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_7 [ 0 ] ;
}
static int F_3 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
memset ( V_8 , 0 , V_3 -> V_11 ) ;
* ( V_12 * ) V_8 = F_4 ( V_10 -> V_13 & 0xffffffff ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
memset ( V_8 , 0 , V_3 -> V_11 ) ;
* ( V_14 * ) V_8 = F_6 ( V_10 -> V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = & V_3 -> V_17 . V_16 ;
F_8 ( V_18 , V_16 -> V_19 ) ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
int V_24 ;
F_9 ( & V_21 , V_3 -> V_25 , V_3 -> V_26 ) ;
F_10 ( V_18 , V_16 -> V_19 ) ;
F_11 ( V_18 , V_27 , NULL , NULL ) ;
F_12 ( V_18 , & V_21 , V_16 -> V_28 , V_3 -> V_26 ) ;
V_24 = F_13 ( V_18 ) ;
F_14 ( V_18 ) ;
if ( V_24 )
return V_24 ;
V_23 = V_3 -> V_29 ;
V_24 = F_15 ( V_23 , V_16 -> V_28 ,
F_16 ( V_16 -> V_19 ) ) ;
if ( V_24 )
return V_24 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = & V_3 -> V_17 . V_16 ;
unsigned V_30 = F_16 ( V_16 -> V_19 ) ;
struct V_22 * V_23 ;
int V_31 , V_24 = 0 ;
memset ( V_16 -> V_28 , 0 , V_30 ) ;
V_23 = V_3 -> V_29 ;
V_31 = F_15 ( V_23 , V_16 -> V_28 , V_30 ) ;
if ( V_31 )
V_24 = V_31 ;
return V_24 ;
}
static struct V_22 * F_18 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
const T_1 * V_28 ,
unsigned int V_34 )
{
struct V_22 * V_23 ;
int V_24 ;
V_23 = F_19 ( V_3 -> V_35 , 0 , V_36 ) ;
if ( F_20 ( V_23 ) ) {
V_33 -> error = L_1 ;
return V_23 ;
}
if ( F_21 ( V_23 ) != V_3 -> V_11 ) {
V_33 -> error = L_2
L_3 ;
F_22 ( V_23 ) ;
return F_23 ( - V_37 ) ;
}
V_24 = F_15 ( V_23 , V_28 , V_34 ) ;
if ( V_24 ) {
V_33 -> error = L_4 ;
F_22 ( V_23 ) ;
return F_23 ( V_24 ) ;
}
return V_23 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_22 * V_23 ;
struct V_15 * V_16 = & V_3 -> V_17 . V_16 ;
F_25 ( V_16 -> V_19 ) ;
V_16 -> V_19 = NULL ;
F_26 ( V_16 -> V_28 ) ;
V_16 -> V_28 = NULL ;
V_23 = V_3 -> V_29 ;
if ( V_23 )
F_22 ( V_23 ) ;
V_3 -> V_29 = NULL ;
}
static int F_27 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_22 * V_23 = NULL ;
struct V_39 * V_19 = NULL ;
T_1 * V_28 = NULL ;
int V_24 ;
if ( ! V_38 ) {
V_33 -> error = L_5 ;
return - V_37 ;
}
V_19 = F_28 ( V_38 , 0 , V_36 ) ;
if ( F_20 ( V_19 ) ) {
V_33 -> error = L_6 ;
V_24 = F_29 ( V_19 ) ;
goto V_40;
}
V_28 = F_30 ( F_16 ( V_19 ) , V_41 ) ;
if ( ! V_28 ) {
V_33 -> error = L_7 ;
V_24 = - V_42 ;
goto V_40;
}
V_3 -> V_17 . V_16 . V_28 = V_28 ;
V_3 -> V_17 . V_16 . V_19 = V_19 ;
V_23 = F_18 ( V_3 , V_33 , V_28 ,
F_16 ( V_19 ) ) ;
if ( F_20 ( V_23 ) ) {
F_24 ( V_3 ) ;
return F_29 ( V_23 ) ;
}
V_3 -> V_29 = V_23 ;
return 0 ;
V_40:
if ( V_19 && ! F_20 ( V_19 ) )
F_25 ( V_19 ) ;
F_31 ( V_28 ) ;
return V_24 ;
}
static int F_32 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_22 * V_23 = V_3 -> V_29 ;
memset ( V_8 , 0 , V_3 -> V_11 ) ;
* ( V_14 * ) V_8 = F_6 ( V_10 -> V_13 ) ;
F_33 ( V_23 , V_8 , V_8 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
unsigned V_43 = F_35 ( F_1 ( V_3 ) ) ;
int log = F_36 ( V_43 ) ;
if ( 1 << log != V_43 ) {
V_33 -> error = L_8 ;
return - V_37 ;
}
if ( log > 9 ) {
V_33 -> error = L_9 ;
return - V_37 ;
}
V_3 -> V_17 . V_44 . V_45 = 9 - log ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
}
static int F_38 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_46 ;
memset ( V_8 , 0 , V_3 -> V_11 - sizeof( V_47 ) ) ;
V_46 = F_39 ( ( ( V_47 ) V_10 -> V_13 << V_3 -> V_17 . V_44 . V_45 ) + 1 ) ;
F_40 ( V_46 , ( T_2 * ) ( V_8 + V_3 -> V_11 - sizeof( V_47 ) ) ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
memset ( V_8 , 0 , V_3 -> V_11 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_17 . V_49 ;
if ( V_49 -> V_19 && ! F_20 ( V_49 -> V_19 ) )
F_43 ( V_49 -> V_19 ) ;
V_49 -> V_19 = NULL ;
F_26 ( V_49 -> V_50 ) ;
V_49 -> V_50 = NULL ;
}
static int F_44 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_48 * V_49 = & V_3 -> V_17 . V_49 ;
if ( V_3 -> V_51 != ( 1 << V_52 ) ) {
V_33 -> error = L_10 ;
return - V_37 ;
}
V_49 -> V_19 = F_45 ( L_11 , 0 , 0 ) ;
if ( F_20 ( V_49 -> V_19 ) ) {
V_33 -> error = L_12 ;
return F_29 ( V_49 -> V_19 ) ;
}
if ( V_3 -> V_53 == V_3 -> V_54 ) {
V_49 -> V_50 = NULL ;
return 0 ;
}
V_49 -> V_50 = F_30 ( V_55 , V_41 ) ;
if ( ! V_49 -> V_50 ) {
F_42 ( V_3 ) ;
V_33 -> error = L_13 ;
return - V_42 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_17 . V_49 ;
int V_56 = V_3 -> V_26 / V_3 -> V_53 ;
if ( V_49 -> V_50 )
memcpy ( V_49 -> V_50 , V_3 -> V_25 + ( V_3 -> V_54 * V_56 ) ,
F_47 ( V_49 -> V_19 ) ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_17 . V_49 ;
if ( V_49 -> V_50 )
memset ( V_49 -> V_50 , 0 , V_55 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 ,
T_1 * V_57 )
{
struct V_48 * V_49 = & V_3 -> V_17 . V_49 ;
F_50 ( V_58 , V_49 -> V_19 ) ;
struct V_59 V_60 ;
V_12 V_61 [ 4 ] ;
int V_62 , V_31 ;
V_58 -> V_63 = V_49 -> V_19 ;
V_58 -> V_64 = V_27 ;
V_31 = F_51 ( V_58 ) ;
if ( V_31 )
return V_31 ;
if ( V_49 -> V_50 ) {
V_31 = F_52 ( V_58 , V_49 -> V_50 , V_55 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_52 ( V_58 , V_57 + 16 , 16 * 31 ) ;
if ( V_31 )
return V_31 ;
V_61 [ 0 ] = F_4 ( V_10 -> V_13 & 0xFFFFFFFF ) ;
V_61 [ 1 ] = F_4 ( ( ( ( V_47 ) V_10 -> V_13 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_61 [ 2 ] = F_4 ( 4024 ) ;
V_61 [ 3 ] = 0 ;
V_31 = F_52 ( V_58 , ( T_1 * ) V_61 , sizeof( V_61 ) ) ;
if ( V_31 )
return V_31 ;
V_31 = F_53 ( V_58 , & V_60 ) ;
if ( V_31 )
return V_31 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ )
F_54 ( & V_60 . V_66 [ V_62 ] ) ;
memcpy ( V_8 , & V_60 . V_66 , V_3 -> V_11 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 ;
T_1 * V_67 ;
int V_31 = 0 ;
if ( F_56 ( V_10 -> V_68 -> V_69 ) == V_70 ) {
V_21 = F_57 ( V_3 , V_10 -> V_71 ) ;
V_67 = F_58 ( F_59 ( V_21 ) ) ;
V_31 = F_49 ( V_3 , V_8 , V_10 , V_67 + V_21 -> V_72 ) ;
F_60 ( V_67 ) ;
} else
memset ( V_8 , 0 , V_3 -> V_11 ) ;
return V_31 ;
}
static int F_61 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 ;
T_1 * V_73 ;
int V_31 ;
if ( F_56 ( V_10 -> V_68 -> V_69 ) == V_70 )
return 0 ;
V_21 = F_57 ( V_3 , V_10 -> V_74 ) ;
V_73 = F_58 ( F_59 ( V_21 ) ) ;
V_31 = F_49 ( V_3 , V_8 , V_10 , V_73 + V_21 -> V_72 ) ;
if ( ! V_31 )
F_62 ( V_73 + V_21 -> V_72 , V_8 , V_3 -> V_11 ) ;
F_60 ( V_73 ) ;
return V_31 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_75 * V_76 = & V_3 -> V_17 . V_76 ;
F_26 ( V_76 -> V_77 ) ;
V_76 -> V_77 = NULL ;
F_26 ( V_76 -> V_78 ) ;
V_76 -> V_78 = NULL ;
if ( V_76 -> V_79 && ! F_20 ( V_76 -> V_79 ) )
F_43 ( V_76 -> V_79 ) ;
V_76 -> V_79 = NULL ;
}
static int F_64 ( struct V_2 * V_3 , struct V_32 * V_33 ,
const char * V_38 )
{
struct V_75 * V_76 = & V_3 -> V_17 . V_76 ;
if ( V_3 -> V_51 != ( 1 << V_52 ) ) {
V_33 -> error = L_14 ;
return - V_37 ;
}
if ( V_3 -> V_26 <= ( V_3 -> V_11 + V_80 ) ) {
V_33 -> error = L_15 ;
return - V_37 ;
}
V_76 -> V_79 = F_45 ( L_16 , 0 , 0 ) ;
if ( F_20 ( V_76 -> V_79 ) ) {
V_33 -> error = L_17 ;
return F_29 ( V_76 -> V_79 ) ;
}
V_76 -> V_77 = F_30 ( V_3 -> V_11 , V_41 ) ;
V_76 -> V_78 = F_30 ( V_80 , V_41 ) ;
if ( ! V_76 -> V_77 || ! V_76 -> V_78 ) {
F_63 ( V_3 ) ;
V_33 -> error = L_18 ;
return - V_42 ;
}
return 0 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_75 * V_76 = & V_3 -> V_17 . V_76 ;
int V_81 = V_3 -> V_26 - V_3 -> V_11 - V_80 ;
memcpy ( V_76 -> V_77 , & V_3 -> V_25 [ V_81 ] , V_3 -> V_11 ) ;
memcpy ( V_76 -> V_78 , & V_3 -> V_25 [ V_81 + V_3 -> V_11 ] ,
V_80 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_75 * V_76 = & V_3 -> V_17 . V_76 ;
memset ( V_76 -> V_77 , 0 , V_3 -> V_11 ) ;
memset ( V_76 -> V_78 , 0 , V_80 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
T_1 * V_57 )
{
struct V_75 * V_76 = & V_3 -> V_17 . V_76 ;
V_14 V_82 = F_6 ( V_10 -> V_13 ) ;
T_1 V_61 [ V_80 ] ;
F_50 ( V_58 , V_76 -> V_79 ) ;
int V_62 , V_31 ;
memcpy ( V_61 , V_76 -> V_78 , V_80 ) ;
F_62 ( V_61 , ( T_1 * ) & V_82 , 8 ) ;
F_62 ( & V_61 [ 8 ] , ( T_1 * ) & V_82 , 8 ) ;
V_58 -> V_63 = V_76 -> V_79 ;
V_58 -> V_64 = V_27 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
V_31 = F_51 ( V_58 ) ;
if ( V_31 )
goto V_83;
V_31 = F_52 ( V_58 , & V_61 [ V_62 * 4 ] , 4 ) ;
if ( V_31 )
goto V_83;
V_31 = F_68 ( V_58 , & V_61 [ V_62 * 4 ] ) ;
if ( V_31 )
goto V_83;
}
F_62 ( & V_61 [ 0 ] , & V_61 [ 12 ] , 4 ) ;
F_62 ( & V_61 [ 4 ] , & V_61 [ 8 ] , 4 ) ;
for ( V_62 = 0 ; V_62 < ( ( 1 << V_52 ) / 8 ) ; V_62 ++ )
F_62 ( V_57 + V_62 * 8 , V_61 , 8 ) ;
V_83:
F_69 ( V_61 , sizeof( V_61 ) ) ;
return V_31 ;
}
static int F_70 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 ;
struct V_75 * V_76 = & V_3 -> V_17 . V_76 ;
V_14 V_82 = F_6 ( V_10 -> V_13 ) ;
T_1 * V_67 ;
int V_31 = 0 ;
if ( F_56 ( V_10 -> V_68 -> V_69 ) != V_70 ) {
V_21 = F_57 ( V_3 , V_10 -> V_71 ) ;
V_67 = F_58 ( F_59 ( V_21 ) ) ;
V_31 = F_67 ( V_3 , V_10 , V_67 + V_21 -> V_72 ) ;
F_60 ( V_67 ) ;
}
memcpy ( V_8 , V_76 -> V_77 , V_3 -> V_11 ) ;
F_62 ( V_8 , ( T_1 * ) & V_82 , 8 ) ;
if ( V_3 -> V_11 > 8 )
F_62 ( & V_8 [ 8 ] , ( T_1 * ) & V_82 , V_3 -> V_11 - 8 ) ;
return V_31 ;
}
static int F_71 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 ;
T_1 * V_73 ;
int V_31 ;
if ( F_56 ( V_10 -> V_68 -> V_69 ) != V_70 )
return 0 ;
V_21 = F_57 ( V_3 , V_10 -> V_74 ) ;
V_73 = F_58 ( F_59 ( V_21 ) ) ;
V_31 = F_67 ( V_3 , V_10 , V_73 + V_21 -> V_72 ) ;
F_60 ( V_73 ) ;
return V_31 ;
}
static int F_72 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
F_73 ( V_8 , V_3 -> V_11 ) ;
return 0 ;
}
static bool F_74 ( struct V_2 * V_3 )
{
return F_75 ( V_84 , & V_3 -> V_85 ) ;
}
static bool F_76 ( struct V_2 * V_3 )
{
return F_74 ( V_3 ) && V_3 -> V_86 ;
}
static struct V_20 * F_57 ( struct V_2 * V_3 ,
struct V_20 * V_21 )
{
if ( F_77 ( F_74 ( V_3 ) ) )
return & V_21 [ 2 ] ;
return V_21 ;
}
static int F_78 ( struct V_87 * V_88 , struct V_89 * V_89 )
{
struct V_90 * V_91 ;
unsigned int V_92 ;
int V_93 ;
if ( ! F_79 ( V_89 ) || ! V_88 -> V_3 -> V_94 )
return 0 ;
V_91 = F_80 ( V_89 , V_95 , 1 ) ;
if ( F_20 ( V_91 ) )
return F_29 ( V_91 ) ;
V_92 = V_88 -> V_3 -> V_94 * F_79 ( V_89 ) ;
V_91 -> V_96 . V_97 = V_92 ;
V_91 -> V_96 . V_98 = V_88 -> V_3 -> V_99 + V_88 -> V_82 ;
V_91 -> V_100 &= ~ V_101 ;
V_93 = F_81 ( V_89 , F_82 ( V_88 -> V_102 ) ,
V_92 , F_83 ( V_88 -> V_102 ) ) ;
if ( F_77 ( V_93 != V_92 ) )
return - V_42 ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
#ifdef F_85
struct V_103 * V_104 = F_86 ( V_3 -> V_105 -> V_106 -> V_107 ) ;
if ( ! V_104 || strcasecmp ( V_104 -> V_108 -> V_109 , L_19 ) ) {
V_33 -> error = L_20 ;
return - V_37 ;
}
if ( V_104 -> V_110 != V_3 -> V_94 ||
V_104 -> V_111 != V_3 -> V_94 ) {
V_33 -> error = L_21 ;
return - V_37 ;
}
if ( 1 << V_104 -> V_112 != V_3 -> V_51 ) {
V_33 -> error = L_22 ;
return - V_37 ;
}
if ( F_74 ( V_3 ) ) {
V_3 -> V_113 = V_3 -> V_94 - V_3 -> V_114 ;
F_87 ( L_23 ,
V_3 -> V_113 , V_3 -> V_114 ) ;
if ( F_88 ( F_2 ( V_3 ) , V_3 -> V_113 ) ) {
V_33 -> error = L_24 ;
return - V_37 ;
}
} else if ( V_3 -> V_114 )
F_87 ( L_25 ,
V_3 -> V_114 ) ;
if ( ( V_3 -> V_113 + V_3 -> V_114 ) != V_104 -> V_110 ) {
V_33 -> error = L_26 ;
return - V_37 ;
}
return 0 ;
#else
V_33 -> error = L_20 ;
return - V_37 ;
#endif
}
static void F_89 ( struct V_2 * V_3 ,
struct V_115 * V_68 ,
struct V_89 * V_116 , struct V_89 * V_69 ,
T_3 V_82 )
{
V_68 -> V_69 = V_69 ;
V_68 -> V_116 = V_116 ;
if ( V_69 )
V_68 -> V_117 = V_69 -> V_118 ;
if ( V_116 )
V_68 -> V_119 = V_116 -> V_118 ;
V_68 -> V_120 = V_82 + V_3 -> V_121 ;
F_90 ( & V_68 -> V_122 ) ;
}
static struct V_9 * F_91 ( struct V_2 * V_3 ,
void * V_18 )
{
return (struct V_9 * ) ( ( char * ) V_18 + V_3 -> V_123 ) ;
}
static void * F_92 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
return ( void * ) ( ( char * ) V_10 - V_3 -> V_123 ) ;
}
static T_1 * F_93 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( F_74 ( V_3 ) )
return ( T_1 * ) F_94 ( ( unsigned long ) ( V_10 + 1 ) ,
F_95 ( F_2 ( V_3 ) ) + 1 ) ;
else
return ( T_1 * ) F_94 ( ( unsigned long ) ( V_10 + 1 ) ,
F_96 ( F_1 ( V_3 ) ) + 1 ) ;
}
static T_1 * F_97 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
return F_93 ( V_3 , V_10 ) + V_3 -> V_11 ;
}
static T_4 * F_98 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
T_1 * V_124 = F_93 ( V_3 , V_10 ) + V_3 -> V_11 + V_3 -> V_11 ;
return ( T_4 * ) V_124 ;
}
static unsigned int * F_99 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
T_1 * V_124 = F_93 ( V_3 , V_10 ) + V_3 -> V_11 +
V_3 -> V_11 + sizeof( T_4 ) ;
return ( unsigned int * ) V_124 ;
}
static void * F_100 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_115 * V_68 = V_10 -> V_68 ;
struct V_87 * V_88 = F_101 ( V_68 , struct V_87 , V_68 ) ;
return & V_88 -> V_102 [ * F_99 ( V_3 , V_10 ) *
V_3 -> V_94 ] ;
}
static void * F_102 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
return F_100 ( V_3 , V_10 ) + V_3 -> V_113 ;
}
static int F_103 ( struct V_2 * V_3 ,
struct V_115 * V_68 ,
struct V_125 * V_18 ,
unsigned int V_126 )
{
struct V_127 V_128 = F_104 ( V_68 -> V_69 , V_68 -> V_117 ) ;
struct V_127 V_129 = F_104 ( V_68 -> V_116 , V_68 -> V_119 ) ;
struct V_9 * V_10 ;
T_1 * V_8 , * V_130 , * V_131 , * V_132 ;
T_4 * V_82 ;
int V_31 = 0 ;
F_105 ( V_3 -> V_114 && V_3 -> V_114 != V_3 -> V_11 ) ;
if ( F_77 ( V_128 . V_133 & ( V_3 -> V_51 - 1 ) ) )
return - V_134 ;
V_10 = F_91 ( V_3 , V_18 ) ;
V_10 -> V_13 = V_68 -> V_120 ;
if ( F_75 ( V_135 , & V_3 -> V_85 ) )
V_10 -> V_13 >>= V_3 -> V_136 ;
V_10 -> V_68 = V_68 ;
* F_99 ( V_3 , V_10 ) = V_126 ;
V_82 = F_98 ( V_3 , V_10 ) ;
* V_82 = F_6 ( V_68 -> V_120 - V_3 -> V_121 ) ;
V_8 = F_93 ( V_3 , V_10 ) ;
V_130 = F_97 ( V_3 , V_10 ) ;
V_132 = F_100 ( V_3 , V_10 ) ;
V_131 = F_102 ( V_3 , V_10 ) ;
F_106 ( V_10 -> V_71 , 4 ) ;
F_107 ( & V_10 -> V_71 [ 0 ] , V_82 , sizeof( T_4 ) ) ;
F_107 ( & V_10 -> V_71 [ 1 ] , V_130 , V_3 -> V_11 ) ;
F_108 ( & V_10 -> V_71 [ 2 ] , V_128 . V_137 , V_3 -> V_51 , V_128 . V_133 ) ;
F_107 ( & V_10 -> V_71 [ 3 ] , V_132 , V_3 -> V_113 ) ;
F_106 ( V_10 -> V_74 , 4 ) ;
F_107 ( & V_10 -> V_74 [ 0 ] , V_82 , sizeof( T_4 ) ) ;
F_107 ( & V_10 -> V_74 [ 1 ] , V_130 , V_3 -> V_11 ) ;
F_108 ( & V_10 -> V_74 [ 2 ] , V_129 . V_137 , V_3 -> V_51 , V_129 . V_133 ) ;
F_107 ( & V_10 -> V_74 [ 3 ] , V_132 , V_3 -> V_113 ) ;
if ( V_3 -> V_138 ) {
if ( V_3 -> V_114 && F_56 ( V_68 -> V_69 ) != V_70 ) {
memcpy ( V_130 , V_131 , V_3 -> V_11 ) ;
} else {
V_31 = V_3 -> V_138 -> V_139 ( V_3 , V_130 , V_10 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_3 -> V_114 )
memcpy ( V_131 , V_130 , V_3 -> V_11 ) ;
}
memcpy ( V_8 , V_130 , V_3 -> V_11 ) ;
}
F_109 ( V_18 , sizeof( T_4 ) + V_3 -> V_11 ) ;
if ( F_56 ( V_68 -> V_69 ) == V_70 ) {
F_110 ( V_18 , V_10 -> V_71 , V_10 -> V_74 ,
V_3 -> V_51 , V_8 ) ;
V_31 = F_111 ( V_18 ) ;
if ( V_3 -> V_113 + V_3 -> V_114 != V_3 -> V_94 )
memset ( V_132 + V_3 -> V_113 + V_3 -> V_114 , 0 ,
V_3 -> V_94 - ( V_3 -> V_113 + V_3 -> V_114 ) ) ;
} else {
F_110 ( V_18 , V_10 -> V_71 , V_10 -> V_74 ,
V_3 -> V_51 + V_3 -> V_113 , V_8 ) ;
V_31 = F_112 ( V_18 ) ;
}
if ( V_31 == - V_140 )
F_113 ( L_27 ,
( unsigned long long ) F_114 ( * V_82 ) ) ;
if ( ! V_31 && V_3 -> V_138 && V_3 -> V_138 -> V_141 )
V_31 = V_3 -> V_138 -> V_141 ( V_3 , V_130 , V_10 ) ;
F_115 ( V_68 -> V_69 , & V_68 -> V_117 , V_3 -> V_51 ) ;
F_115 ( V_68 -> V_116 , & V_68 -> V_119 , V_3 -> V_51 ) ;
return V_31 ;
}
static int F_116 ( struct V_2 * V_3 ,
struct V_115 * V_68 ,
struct V_142 * V_18 ,
unsigned int V_126 )
{
struct V_127 V_128 = F_104 ( V_68 -> V_69 , V_68 -> V_117 ) ;
struct V_127 V_129 = F_104 ( V_68 -> V_116 , V_68 -> V_119 ) ;
struct V_20 * V_71 , * V_74 ;
struct V_9 * V_10 ;
T_1 * V_8 , * V_130 , * V_131 ;
T_4 * V_82 ;
int V_31 = 0 ;
if ( F_77 ( V_128 . V_133 & ( V_3 -> V_51 - 1 ) ) )
return - V_134 ;
V_10 = F_91 ( V_3 , V_18 ) ;
V_10 -> V_13 = V_68 -> V_120 ;
if ( F_75 ( V_135 , & V_3 -> V_85 ) )
V_10 -> V_13 >>= V_3 -> V_136 ;
V_10 -> V_68 = V_68 ;
* F_99 ( V_3 , V_10 ) = V_126 ;
V_8 = F_93 ( V_3 , V_10 ) ;
V_130 = F_97 ( V_3 , V_10 ) ;
V_131 = F_102 ( V_3 , V_10 ) ;
V_82 = F_98 ( V_3 , V_10 ) ;
* V_82 = F_6 ( V_68 -> V_120 - V_3 -> V_121 ) ;
V_71 = & V_10 -> V_71 [ 0 ] ;
V_74 = & V_10 -> V_74 [ 0 ] ;
F_106 ( V_71 , 1 ) ;
F_108 ( V_71 , V_128 . V_137 , V_3 -> V_51 , V_128 . V_133 ) ;
F_106 ( V_74 , 1 ) ;
F_108 ( V_74 , V_129 . V_137 , V_3 -> V_51 , V_129 . V_133 ) ;
if ( V_3 -> V_138 ) {
if ( V_3 -> V_114 && F_56 ( V_68 -> V_69 ) != V_70 ) {
memcpy ( V_130 , V_131 , V_3 -> V_114 ) ;
} else {
V_31 = V_3 -> V_138 -> V_139 ( V_3 , V_130 , V_10 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_3 -> V_114 )
memcpy ( V_131 , V_130 , V_3 -> V_114 ) ;
}
memcpy ( V_8 , V_130 , V_3 -> V_11 ) ;
}
F_117 ( V_18 , V_71 , V_74 , V_3 -> V_51 , V_8 ) ;
if ( F_56 ( V_68 -> V_69 ) == V_70 )
V_31 = F_118 ( V_18 ) ;
else
V_31 = F_119 ( V_18 ) ;
if ( ! V_31 && V_3 -> V_138 && V_3 -> V_138 -> V_141 )
V_31 = V_3 -> V_138 -> V_141 ( V_3 , V_130 , V_10 ) ;
F_115 ( V_68 -> V_69 , & V_68 -> V_117 , V_3 -> V_51 ) ;
F_115 ( V_68 -> V_116 , & V_68 -> V_119 , V_3 -> V_51 ) ;
return V_31 ;
}
static void F_120 ( struct V_2 * V_3 ,
struct V_115 * V_68 )
{
unsigned V_143 = V_68 -> V_120 & ( V_3 -> V_54 - 1 ) ;
if ( ! V_68 -> V_31 . V_18 )
V_68 -> V_31 . V_18 = F_121 ( V_3 -> V_144 , V_95 ) ;
F_122 ( V_68 -> V_31 . V_18 , V_3 -> V_4 . V_5 [ V_143 ] ) ;
F_123 ( V_68 -> V_31 . V_18 ,
V_145 | V_27 ,
V_146 , F_91 ( V_3 , V_68 -> V_31 . V_18 ) ) ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_115 * V_68 )
{
if ( ! V_68 -> V_31 . V_147 )
V_68 -> V_31 . V_147 = F_121 ( V_3 -> V_144 , V_95 ) ;
F_125 ( V_68 -> V_31 . V_147 , V_3 -> V_4 . V_7 [ 0 ] ) ;
F_126 ( V_68 -> V_31 . V_147 ,
V_145 | V_27 ,
V_146 , F_91 ( V_3 , V_68 -> V_31 . V_147 ) ) ;
}
static void F_127 ( struct V_2 * V_3 ,
struct V_115 * V_68 )
{
if ( F_74 ( V_3 ) )
F_124 ( V_3 , V_68 ) ;
else
F_120 ( V_3 , V_68 ) ;
}
static void F_128 ( struct V_2 * V_3 ,
struct V_142 * V_18 , struct V_89 * V_148 )
{
struct V_87 * V_88 = F_129 ( V_148 , V_3 -> V_149 ) ;
if ( (struct V_142 * ) ( V_88 + 1 ) != V_18 )
F_130 ( V_18 , V_3 -> V_144 ) ;
}
static void F_131 ( struct V_2 * V_3 ,
struct V_125 * V_18 , struct V_89 * V_148 )
{
struct V_87 * V_88 = F_129 ( V_148 , V_3 -> V_149 ) ;
if ( (struct V_125 * ) ( V_88 + 1 ) != V_18 )
F_130 ( V_18 , V_3 -> V_144 ) ;
}
static void F_132 ( struct V_2 * V_3 , void * V_18 , struct V_89 * V_148 )
{
if ( F_74 ( V_3 ) )
F_131 ( V_3 , V_18 , V_148 ) ;
else
F_128 ( V_3 , V_18 , V_148 ) ;
}
static int F_133 ( struct V_2 * V_3 ,
struct V_115 * V_68 )
{
unsigned int V_126 = 0 ;
unsigned int V_150 = V_3 -> V_51 >> V_52 ;
int V_31 ;
F_134 ( & V_68 -> V_151 , 1 ) ;
while ( V_68 -> V_117 . V_97 && V_68 -> V_119 . V_97 ) {
F_127 ( V_3 , V_68 ) ;
F_135 ( & V_68 -> V_151 ) ;
if ( F_74 ( V_3 ) )
V_31 = F_103 ( V_3 , V_68 , V_68 -> V_31 . V_147 , V_126 ) ;
else
V_31 = F_116 ( V_3 , V_68 , V_68 -> V_31 . V_18 , V_126 ) ;
switch ( V_31 ) {
case - V_152 :
F_136 ( & V_68 -> V_122 ) ;
F_137 ( & V_68 -> V_122 ) ;
case - V_153 :
V_68 -> V_31 . V_18 = NULL ;
V_68 -> V_120 += V_150 ;
V_126 ++ ;
continue;
case 0 :
F_138 ( & V_68 -> V_151 ) ;
V_68 -> V_120 += V_150 ;
V_126 ++ ;
F_139 () ;
continue;
case - V_140 :
F_138 ( & V_68 -> V_151 ) ;
return - V_154 ;
default:
F_138 ( & V_68 -> V_151 ) ;
return - V_134 ;
}
}
return 0 ;
}
static struct V_89 * F_140 ( struct V_87 * V_88 , unsigned V_155 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
struct V_89 * V_156 ;
unsigned int V_157 = ( V_155 + V_158 - 1 ) >> V_159 ;
T_5 V_160 = V_161 | V_162 ;
unsigned V_62 , V_163 , V_164 ;
struct V_165 * V_165 ;
V_166:
if ( F_77 ( V_160 & V_167 ) )
F_141 ( & V_3 -> V_168 ) ;
V_156 = F_142 ( V_95 , V_157 , V_3 -> V_43 ) ;
if ( ! V_156 )
goto V_83;
F_143 ( V_88 , V_156 ) ;
V_164 = V_155 ;
for ( V_62 = 0 ; V_62 < V_157 ; V_62 ++ ) {
V_165 = F_121 ( V_3 -> V_169 , V_160 ) ;
if ( ! V_165 ) {
F_144 ( V_3 , V_156 ) ;
F_145 ( V_156 ) ;
V_160 |= V_167 ;
goto V_166;
}
V_163 = ( V_164 > V_158 ) ? V_158 : V_164 ;
F_146 ( V_156 , V_165 , V_163 , 0 ) ;
V_164 -= V_163 ;
}
if ( F_78 ( V_88 , V_156 ) ) {
F_144 ( V_3 , V_156 ) ;
F_145 ( V_156 ) ;
V_156 = NULL ;
}
V_83:
if ( F_77 ( V_160 & V_167 ) )
F_147 ( & V_3 -> V_168 ) ;
return V_156 ;
}
static void F_144 ( struct V_2 * V_3 , struct V_89 * V_156 )
{
unsigned int V_62 ;
struct V_127 * V_170 ;
F_148 (bv, clone, i) {
F_105 ( ! V_170 -> V_137 ) ;
F_130 ( V_170 -> V_137 , V_3 -> V_169 ) ;
V_170 -> V_137 = NULL ;
}
}
static void F_149 ( struct V_87 * V_88 , struct V_2 * V_3 ,
struct V_89 * V_89 , T_3 V_82 )
{
V_88 -> V_3 = V_3 ;
V_88 -> V_148 = V_89 ;
V_88 -> V_82 = V_82 ;
V_88 -> error = 0 ;
V_88 -> V_68 . V_31 . V_18 = NULL ;
V_88 -> V_102 = NULL ;
V_88 -> V_171 = false ;
F_134 ( & V_88 -> V_172 , 0 ) ;
}
static void F_150 ( struct V_87 * V_88 )
{
F_135 ( & V_88 -> V_172 ) ;
}
static void F_151 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
struct V_89 * V_148 = V_88 -> V_148 ;
int error = V_88 -> error ;
if ( ! F_152 ( & V_88 -> V_172 ) )
return;
if ( V_88 -> V_68 . V_31 . V_18 )
F_132 ( V_3 , V_88 -> V_68 . V_31 . V_18 , V_148 ) ;
if ( F_77 ( V_88 -> V_171 ) )
F_130 ( V_88 -> V_102 , V_88 -> V_3 -> V_173 ) ;
else
F_31 ( V_88 -> V_102 ) ;
V_148 -> V_174 = error ;
F_153 ( V_148 ) ;
}
static void F_154 ( struct V_89 * V_156 )
{
struct V_87 * V_88 = V_156 -> V_175 ;
struct V_2 * V_3 = V_88 -> V_3 ;
unsigned V_176 = F_56 ( V_156 ) ;
int error ;
if ( V_176 == V_70 )
F_144 ( V_3 , V_156 ) ;
error = V_156 -> V_174 ;
F_145 ( V_156 ) ;
if ( V_176 == V_177 && ! error ) {
F_155 ( V_88 ) ;
return;
}
if ( F_77 ( error ) )
V_88 -> error = error ;
F_151 ( V_88 ) ;
}
static void F_143 ( struct V_87 * V_88 , struct V_89 * V_156 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
V_156 -> V_175 = V_88 ;
V_156 -> V_178 = F_154 ;
V_156 -> V_179 = V_3 -> V_105 -> V_106 ;
V_156 -> V_180 = V_88 -> V_148 -> V_180 ;
}
static int F_156 ( struct V_87 * V_88 , T_5 V_181 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
struct V_89 * V_156 ;
V_156 = F_157 ( V_88 -> V_148 , V_181 , V_3 -> V_43 ) ;
if ( ! V_156 )
return 1 ;
F_150 ( V_88 ) ;
F_143 ( V_88 , V_156 ) ;
V_156 -> V_118 . V_98 = V_3 -> V_99 + V_88 -> V_82 ;
if ( F_78 ( V_88 , V_156 ) ) {
F_151 ( V_88 ) ;
F_145 ( V_156 ) ;
return 1 ;
}
F_158 ( V_156 ) ;
return 0 ;
}
static void F_159 ( struct V_182 * V_183 )
{
struct V_87 * V_88 = F_101 ( V_183 , struct V_87 , V_183 ) ;
F_150 ( V_88 ) ;
if ( F_156 ( V_88 , V_95 ) )
V_88 -> error = - V_42 ;
F_151 ( V_88 ) ;
}
static void F_160 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
F_161 ( & V_88 -> V_183 , F_159 ) ;
F_162 ( V_3 -> V_184 , & V_88 -> V_183 ) ;
}
static void F_163 ( struct V_87 * V_88 )
{
struct V_89 * V_156 = V_88 -> V_68 . V_116 ;
F_158 ( V_156 ) ;
}
static int F_164 ( void * V_57 )
{
struct V_2 * V_3 = V_57 ;
struct V_87 * V_88 ;
while ( 1 ) {
struct V_185 V_186 ;
struct V_187 V_188 ;
F_165 ( V_189 , V_190 ) ;
F_166 ( & V_3 -> V_191 . V_192 ) ;
V_193:
if ( ! F_167 ( & V_3 -> V_186 ) )
goto V_194;
F_168 ( V_195 ) ;
F_169 ( & V_3 -> V_191 , & V_189 ) ;
F_170 ( & V_3 -> V_191 . V_192 ) ;
if ( F_77 ( F_171 () ) ) {
F_168 ( V_196 ) ;
F_172 ( & V_3 -> V_191 , & V_189 ) ;
break;
}
F_173 () ;
F_168 ( V_196 ) ;
F_166 ( & V_3 -> V_191 . V_192 ) ;
F_174 ( & V_3 -> V_191 , & V_189 ) ;
goto V_193;
V_194:
V_186 = V_3 -> V_186 ;
V_3 -> V_186 = V_197 ;
F_170 ( & V_3 -> V_191 . V_192 ) ;
F_105 ( F_175 ( V_186 . V_198 ) ) ;
F_176 ( & V_188 ) ;
do {
V_88 = F_177 ( F_178 ( & V_186 ) ) ;
F_179 ( & V_88 -> V_198 , & V_186 ) ;
F_163 ( V_88 ) ;
} while ( ! F_167 ( & V_186 ) );
F_180 ( & V_188 ) ;
}
return 0 ;
}
static void F_181 ( struct V_87 * V_88 , int V_199 )
{
struct V_89 * V_156 = V_88 -> V_68 . V_116 ;
struct V_2 * V_3 = V_88 -> V_3 ;
unsigned long V_64 ;
T_3 V_82 ;
struct V_198 * * V_200 , * V_201 ;
if ( F_77 ( V_88 -> error < 0 ) ) {
F_144 ( V_3 , V_156 ) ;
F_145 ( V_156 ) ;
F_151 ( V_88 ) ;
return;
}
F_105 ( V_88 -> V_68 . V_119 . V_97 ) ;
V_156 -> V_118 . V_98 = V_3 -> V_99 + V_88 -> V_82 ;
if ( F_182 ( ! V_199 ) && F_75 ( V_202 , & V_3 -> V_64 ) ) {
F_158 ( V_156 ) ;
return;
}
F_183 ( & V_3 -> V_191 . V_192 , V_64 ) ;
V_200 = & V_3 -> V_186 . V_198 ;
V_201 = NULL ;
V_82 = V_88 -> V_82 ;
while ( * V_200 ) {
V_201 = * V_200 ;
if ( V_82 < F_177 ( V_201 ) -> V_82 )
V_200 = & ( * V_200 ) -> V_203 ;
else
V_200 = & ( * V_200 ) -> V_204 ;
}
F_184 ( & V_88 -> V_198 , V_201 , V_200 ) ;
F_185 ( & V_88 -> V_198 , & V_3 -> V_186 ) ;
F_186 ( & V_3 -> V_191 ) ;
F_187 ( & V_3 -> V_191 . V_192 , V_64 ) ;
}
static void F_188 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
struct V_89 * V_156 ;
int V_205 ;
T_3 V_82 = V_88 -> V_82 ;
int V_31 ;
F_150 ( V_88 ) ;
F_89 ( V_3 , & V_88 -> V_68 , NULL , V_88 -> V_148 , V_82 ) ;
V_156 = F_140 ( V_88 , V_88 -> V_148 -> V_118 . V_97 ) ;
if ( F_77 ( ! V_156 ) ) {
V_88 -> error = - V_134 ;
goto V_206;
}
V_88 -> V_68 . V_116 = V_156 ;
V_88 -> V_68 . V_119 = V_156 -> V_118 ;
V_82 += F_79 ( V_156 ) ;
F_150 ( V_88 ) ;
V_31 = F_133 ( V_3 , & V_88 -> V_68 ) ;
if ( V_31 < 0 )
V_88 -> error = V_31 ;
V_205 = F_152 ( & V_88 -> V_68 . V_151 ) ;
if ( V_205 ) {
F_181 ( V_88 , 0 ) ;
V_88 -> V_82 = V_82 ;
}
V_206:
F_151 ( V_88 ) ;
}
static void F_189 ( struct V_87 * V_88 )
{
F_151 ( V_88 ) ;
}
static void F_190 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
int V_31 = 0 ;
F_150 ( V_88 ) ;
F_89 ( V_3 , & V_88 -> V_68 , V_88 -> V_148 , V_88 -> V_148 ,
V_88 -> V_82 ) ;
V_31 = F_133 ( V_3 , & V_88 -> V_68 ) ;
if ( V_31 < 0 )
V_88 -> error = V_31 ;
if ( F_152 ( & V_88 -> V_68 . V_151 ) )
F_189 ( V_88 ) ;
F_151 ( V_88 ) ;
}
static void V_146 ( struct V_207 * V_208 ,
int error )
{
struct V_9 * V_10 = V_208 -> V_57 ;
struct V_115 * V_68 = V_10 -> V_68 ;
struct V_87 * V_88 = F_101 ( V_68 , struct V_87 , V_68 ) ;
struct V_2 * V_3 = V_88 -> V_3 ;
if ( error == - V_153 ) {
F_191 ( & V_68 -> V_122 ) ;
return;
}
if ( ! error && V_3 -> V_138 && V_3 -> V_138 -> V_141 )
error = V_3 -> V_138 -> V_141 ( V_3 , F_97 ( V_3 , V_10 ) , V_10 ) ;
if ( error == - V_140 ) {
F_113 ( L_27 ,
( unsigned long long ) F_114 ( * F_98 ( V_3 , V_10 ) ) ) ;
V_88 -> error = - V_154 ;
} else if ( error < 0 )
V_88 -> error = - V_134 ;
F_132 ( V_3 , F_92 ( V_3 , V_10 ) , V_88 -> V_148 ) ;
if ( ! F_152 ( & V_68 -> V_151 ) )
return;
if ( F_56 ( V_88 -> V_148 ) == V_177 )
F_189 ( V_88 ) ;
else
F_181 ( V_88 , 1 ) ;
}
static void F_192 ( struct V_182 * V_183 )
{
struct V_87 * V_88 = F_101 ( V_183 , struct V_87 , V_183 ) ;
if ( F_56 ( V_88 -> V_148 ) == V_177 )
F_190 ( V_88 ) ;
else
F_188 ( V_88 ) ;
}
static void F_155 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
F_161 ( & V_88 -> V_183 , F_192 ) ;
F_162 ( V_3 -> V_209 , & V_88 -> V_183 ) ;
}
static void F_193 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 . V_7 )
return;
if ( V_3 -> V_4 . V_7 [ 0 ] && ! F_20 ( V_3 -> V_4 . V_7 [ 0 ] ) ) {
F_194 ( V_3 -> V_4 . V_7 [ 0 ] ) ;
V_3 -> V_4 . V_7 [ 0 ] = NULL ;
}
F_31 ( V_3 -> V_4 . V_7 ) ;
V_3 -> V_4 . V_7 = NULL ;
}
static void F_195 ( struct V_2 * V_3 )
{
unsigned V_62 ;
if ( ! V_3 -> V_4 . V_5 )
return;
for ( V_62 = 0 ; V_62 < V_3 -> V_54 ; V_62 ++ )
if ( V_3 -> V_4 . V_5 [ V_62 ] && ! F_20 ( V_3 -> V_4 . V_5 [ V_62 ] ) ) {
F_196 ( V_3 -> V_4 . V_5 [ V_62 ] ) ;
V_3 -> V_4 . V_5 [ V_62 ] = NULL ;
}
F_31 ( V_3 -> V_4 . V_5 ) ;
V_3 -> V_4 . V_5 = NULL ;
}
static void F_197 ( struct V_2 * V_3 )
{
if ( F_74 ( V_3 ) )
F_193 ( V_3 ) ;
else
F_195 ( V_3 ) ;
}
static int F_198 ( struct V_2 * V_3 , char * V_210 )
{
unsigned V_62 ;
int V_24 ;
V_3 -> V_4 . V_5 = F_30 ( V_3 -> V_54 *
sizeof( struct V_1 * ) , V_41 ) ;
if ( ! V_3 -> V_4 . V_5 )
return - V_42 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_54 ; V_62 ++ ) {
V_3 -> V_4 . V_5 [ V_62 ] = F_199 ( V_210 , 0 , 0 ) ;
if ( F_20 ( V_3 -> V_4 . V_5 [ V_62 ] ) ) {
V_24 = F_29 ( V_3 -> V_4 . V_5 [ V_62 ] ) ;
F_197 ( V_3 ) ;
return V_24 ;
}
}
return 0 ;
}
static int F_200 ( struct V_2 * V_3 , char * V_210 )
{
int V_24 ;
V_3 -> V_4 . V_5 = F_201 ( sizeof( struct V_6 * ) , V_41 ) ;
if ( ! V_3 -> V_4 . V_5 )
return - V_42 ;
V_3 -> V_4 . V_7 [ 0 ] = F_202 ( V_210 , 0 , 0 ) ;
if ( F_20 ( V_3 -> V_4 . V_7 [ 0 ] ) ) {
V_24 = F_29 ( V_3 -> V_4 . V_7 [ 0 ] ) ;
F_197 ( V_3 ) ;
return V_24 ;
}
return 0 ;
}
static int F_203 ( struct V_2 * V_3 , char * V_210 )
{
if ( F_74 ( V_3 ) )
return F_200 ( V_3 , V_210 ) ;
else
return F_198 ( V_3 , V_210 ) ;
}
static unsigned F_204 ( struct V_2 * V_3 )
{
return ( V_3 -> V_26 - V_3 -> V_211 ) >> F_36 ( V_3 -> V_54 ) ;
}
static unsigned F_205 ( struct V_2 * V_3 )
{
return F_204 ( V_3 ) + F_206 ( sizeof( struct V_212 ) ) ;
}
static void F_207 ( char * V_213 , const void * V_25 ,
unsigned V_214 , unsigned V_215 )
{
struct V_212 * V_216 ;
struct V_217 * V_218 ;
V_218 = (struct V_217 * ) V_213 ;
V_216 = F_208 ( V_218 ) ;
V_216 -> V_214 = F_209 ( V_214 ) ;
V_218 -> V_219 = F_210 ( sizeof( * V_216 ) ) ;
V_218 -> V_220 = V_221 ;
V_213 += F_206 ( sizeof( * V_216 ) ) ;
memcpy ( V_213 , V_25 + V_214 , V_215 ) ;
V_213 += V_215 ;
memcpy ( V_213 , V_25 , V_214 ) ;
}
static int F_211 ( struct V_2 * V_3 )
{
unsigned V_56 ;
int V_24 = 0 , V_62 , V_31 ;
V_56 = F_204 ( V_3 ) ;
if ( F_76 ( V_3 ) )
F_207 ( V_3 -> V_222 , V_3 -> V_25 ,
V_56 - V_3 -> V_86 ,
V_3 -> V_86 ) ;
for ( V_62 = 0 ; V_62 < V_3 -> V_54 ; V_62 ++ ) {
if ( F_76 ( V_3 ) )
V_31 = F_212 ( V_3 -> V_4 . V_7 [ V_62 ] ,
V_3 -> V_222 , F_205 ( V_3 ) ) ;
else if ( F_74 ( V_3 ) )
V_31 = F_212 ( V_3 -> V_4 . V_7 [ V_62 ] ,
V_3 -> V_25 + ( V_62 * V_56 ) ,
V_56 ) ;
else
V_31 = F_213 ( V_3 -> V_4 . V_5 [ V_62 ] ,
V_3 -> V_25 + ( V_62 * V_56 ) ,
V_56 ) ;
if ( V_31 )
V_24 = V_31 ;
}
if ( F_76 ( V_3 ) )
F_69 ( V_3 -> V_222 , F_205 ( V_3 ) ) ;
return V_24 ;
}
static bool F_214 ( const char * V_223 )
{
while ( * V_223 )
if ( isspace ( * V_223 ++ ) )
return true ;
return false ;
}
static int F_215 ( struct V_2 * V_3 , const char * V_224 )
{
char * V_225 , * V_226 ;
int V_93 ;
struct V_25 * V_25 ;
const struct V_227 * V_228 ;
if ( F_214 ( V_224 ) ) {
F_216 ( L_28 ) ;
return - V_37 ;
}
V_226 = strpbrk ( V_224 , L_29 ) ;
if ( ! V_226 || V_226 == V_224 || ! strlen ( V_226 + 1 ) )
return - V_37 ;
if ( strncmp ( V_224 , L_30 , V_226 - V_224 + 1 ) &&
strncmp ( V_224 , L_31 , V_226 - V_224 + 1 ) )
return - V_37 ;
V_225 = F_217 ( V_224 , V_41 ) ;
if ( ! V_225 )
return - V_42 ;
V_25 = F_218 ( V_224 [ 0 ] == 'l' ? & V_229 : & V_230 ,
V_226 + 1 , NULL ) ;
if ( F_20 ( V_25 ) ) {
F_26 ( V_225 ) ;
return F_29 ( V_25 ) ;
}
F_219 ( & V_25 -> V_231 ) ;
V_228 = F_220 ( V_25 ) ;
if ( ! V_228 ) {
F_221 ( & V_25 -> V_231 ) ;
F_222 ( V_25 ) ;
F_26 ( V_225 ) ;
return - V_232 ;
}
if ( V_3 -> V_26 != V_228 -> V_233 ) {
F_221 ( & V_25 -> V_231 ) ;
F_222 ( V_25 ) ;
F_26 ( V_225 ) ;
return - V_37 ;
}
memcpy ( V_3 -> V_25 , V_228 -> V_57 , V_3 -> V_26 ) ;
F_221 ( & V_25 -> V_231 ) ;
F_222 ( V_25 ) ;
F_223 ( V_234 , & V_3 -> V_64 ) ;
V_93 = F_211 ( V_3 ) ;
memset ( V_3 -> V_25 , 0 , V_3 -> V_26 * sizeof( T_1 ) ) ;
if ( ! V_93 ) {
F_224 ( V_234 , & V_3 -> V_64 ) ;
F_26 ( V_3 -> V_224 ) ;
V_3 -> V_224 = V_225 ;
} else
F_26 ( V_225 ) ;
return V_93 ;
}
static int F_225 ( char * * V_224 )
{
char * V_235 , V_236 ;
int V_93 ;
if ( * V_224 [ 0 ] != ':' )
return strlen ( * V_224 ) >> 1 ;
V_235 = strpbrk ( * V_224 + 1 , L_29 ) ;
if ( ! V_235 )
return - V_37 ;
if ( sscanf ( * V_224 + 1 , L_32 , & V_93 , & V_236 ) != 2 || V_236 != ':' )
return - V_37 ;
* V_224 = V_235 ;
return V_93 ;
}
static int F_215 ( struct V_2 * V_3 , const char * V_224 )
{
return - V_37 ;
}
static int F_225 ( char * * V_224 )
{
return ( * V_224 [ 0 ] == ':' ) ? - V_37 : strlen ( * V_224 ) >> 1 ;
}
static int F_226 ( struct V_2 * V_3 , char * V_25 )
{
int V_31 = - V_37 ;
int V_237 = strlen ( V_25 ) ;
if ( ! V_3 -> V_26 && strcmp ( V_25 , L_33 ) )
goto V_83;
if ( V_25 [ 0 ] == ':' ) {
V_31 = F_215 ( V_3 , V_25 + 1 ) ;
goto V_83;
}
F_223 ( V_234 , & V_3 -> V_64 ) ;
F_26 ( V_3 -> V_224 ) ;
V_3 -> V_224 = NULL ;
if ( V_3 -> V_26 && F_227 ( V_3 -> V_25 , V_25 , V_3 -> V_26 ) < 0 )
goto V_83;
V_31 = F_211 ( V_3 ) ;
if ( ! V_31 )
F_224 ( V_234 , & V_3 -> V_64 ) ;
V_83:
memset ( V_25 , '0' , V_237 ) ;
return V_31 ;
}
static int F_228 ( struct V_2 * V_3 )
{
int V_31 ;
F_223 ( V_234 , & V_3 -> V_64 ) ;
F_73 ( & V_3 -> V_25 , V_3 -> V_26 ) ;
F_26 ( V_3 -> V_224 ) ;
V_3 -> V_224 = NULL ;
V_31 = F_211 ( V_3 ) ;
memset ( & V_3 -> V_25 , 0 , V_3 -> V_26 * sizeof( T_1 ) ) ;
return V_31 ;
}
static void F_229 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
V_33 -> V_238 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_239 )
F_230 ( V_3 -> V_239 ) ;
if ( V_3 -> V_184 )
F_231 ( V_3 -> V_184 ) ;
if ( V_3 -> V_209 )
F_231 ( V_3 -> V_209 ) ;
F_197 ( V_3 ) ;
if ( V_3 -> V_43 )
F_232 ( V_3 -> V_43 ) ;
F_233 ( V_3 -> V_169 ) ;
F_233 ( V_3 -> V_144 ) ;
F_233 ( V_3 -> V_173 ) ;
if ( V_3 -> V_138 && V_3 -> V_138 -> V_240 )
V_3 -> V_138 -> V_240 ( V_3 ) ;
if ( V_3 -> V_105 )
F_234 ( V_33 , V_3 -> V_105 ) ;
F_26 ( V_3 -> V_35 ) ;
F_26 ( V_3 -> V_241 ) ;
F_26 ( V_3 -> V_224 ) ;
F_26 ( V_3 -> V_242 ) ;
F_26 ( V_3 -> V_222 ) ;
F_26 ( V_3 ) ;
}
static int F_235 ( struct V_32 * V_33 , const char * V_243 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
if ( F_74 ( V_3 ) )
V_3 -> V_11 = F_236 ( F_2 ( V_3 ) ) ;
else
V_3 -> V_11 = F_237 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_11 )
V_3 -> V_11 = F_238 ( V_3 -> V_11 ,
( unsigned int ) ( sizeof( V_47 ) / sizeof( T_1 ) ) ) ;
else if ( V_243 ) {
F_239 ( L_34 ) ;
V_243 = NULL ;
}
if ( V_243 == NULL )
V_3 -> V_138 = NULL ;
else if ( strcmp ( V_243 , L_35 ) == 0 )
V_3 -> V_138 = & V_244 ;
else if ( strcmp ( V_243 , L_36 ) == 0 )
V_3 -> V_138 = & V_245 ;
else if ( strcmp ( V_243 , L_37 ) == 0 )
V_3 -> V_138 = & V_246 ;
else if ( strcmp ( V_243 , L_38 ) == 0 )
V_3 -> V_138 = & V_247 ;
else if ( strcmp ( V_243 , L_39 ) == 0 )
V_3 -> V_138 = & V_248 ;
else if ( strcmp ( V_243 , L_40 ) == 0 ) {
V_3 -> V_138 = & V_249 ;
if ( V_3 -> V_26 % V_3 -> V_53 ) {
V_3 -> V_53 ++ ;
V_3 -> V_211 = V_3 -> V_26 / V_3 -> V_53 ;
}
} else if ( strcmp ( V_243 , L_41 ) == 0 ) {
V_3 -> V_138 = & V_250 ;
V_3 -> V_53 += 2 ;
V_3 -> V_211 = V_3 -> V_11 + V_80 ;
} else if ( strcmp ( V_243 , L_42 ) == 0 ) {
V_3 -> V_138 = & V_251 ;
V_3 -> V_114 = V_3 -> V_11 ;
} else {
V_33 -> error = L_43 ;
return - V_37 ;
}
return 0 ;
}
static int F_240 ( struct V_2 * V_3 )
{
const char * V_252 = NULL ;
char * V_99 , * V_253 ;
if ( F_74 ( V_3 ) ) {
V_252 = F_241 ( F_242 ( F_2 ( V_3 ) ) ) ;
if ( ! V_252 )
return - V_37 ;
if ( F_76 ( V_3 ) ) {
V_252 = strchr ( V_252 , ',' ) ;
if ( ! V_252 )
return - V_37 ;
}
V_252 ++ ;
} else {
V_252 = F_241 ( F_243 ( F_1 ( V_3 ) ) ) ;
if ( ! V_252 )
return - V_37 ;
}
V_99 = strchr ( V_252 , '(' ) ;
V_253 = strchr ( V_252 , ')' ) ;
if ( ! V_99 && ! V_253 ) {
V_3 -> V_35 = F_217 ( V_252 , V_41 ) ;
return V_3 -> V_35 ? 0 : - V_42 ;
}
if ( ! V_99 || ! V_253 || ++ V_99 >= V_253 )
return - V_37 ;
V_3 -> V_35 = F_30 ( V_253 - V_99 + 1 , V_41 ) ;
if ( ! V_3 -> V_35 )
return - V_42 ;
strncpy ( V_3 -> V_35 , V_99 , V_253 - V_99 ) ;
return 0 ;
}
static int F_244 ( struct V_2 * V_3 , char * V_254 )
{
char * V_99 , * V_253 , * V_255 = NULL ;
struct V_39 * V_256 ;
if ( ! F_245 ( V_254 , L_44 ) )
return 0 ;
V_99 = strchr ( V_254 , '(' ) ;
V_253 = strchr ( V_254 , ',' ) ;
if ( ! V_99 || ! V_253 || ++ V_99 > V_253 )
return - V_37 ;
V_255 = F_30 ( V_253 - V_99 + 1 , V_41 ) ;
if ( ! V_255 )
return - V_42 ;
strncpy ( V_255 , V_99 , V_253 - V_99 ) ;
V_256 = F_28 ( V_255 , 0 , 0 ) ;
F_31 ( V_255 ) ;
if ( F_20 ( V_256 ) )
return F_29 ( V_256 ) ;
V_3 -> V_86 = F_16 ( V_256 ) ;
F_25 ( V_256 ) ;
V_3 -> V_222 = F_201 ( F_205 ( V_3 ) , V_41 ) ;
if ( ! V_3 -> V_222 )
return - V_42 ;
return 0 ;
}
static int F_246 ( struct V_32 * V_33 , char * V_257 , char * V_25 ,
char * * V_243 , char * * V_258 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
char * V_259 , * V_254 ;
int V_93 = - V_37 ;
V_3 -> V_54 = 1 ;
V_259 = & V_257 [ strlen ( L_45 ) ] ;
V_254 = F_247 ( & V_259 , L_33 ) ;
* V_243 = F_247 ( & V_259 , L_29 ) ;
* V_258 = V_259 ;
if ( * V_243 && ! strcmp ( * V_243 , L_40 ) )
V_3 -> V_54 = 64 ;
V_3 -> V_53 = V_3 -> V_54 ;
V_93 = F_203 ( V_3 , V_254 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_46 ;
return V_93 ;
}
if ( F_74 ( V_3 ) ) {
V_93 = F_244 ( V_3 , V_254 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_47 ;
return - V_42 ;
}
V_3 -> V_11 = F_236 ( F_2 ( V_3 ) ) ;
} else
V_3 -> V_11 = F_237 ( F_1 ( V_3 ) ) ;
V_93 = F_240 ( V_3 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_48 ;
return - V_42 ;
}
return 0 ;
}
static int F_248 ( struct V_32 * V_33 , char * V_257 , char * V_25 ,
char * * V_243 , char * * V_258 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
char * V_259 , * V_35 , * V_260 , * V_261 ;
char * V_254 = NULL ;
int V_93 = - V_37 ;
char V_236 ;
if ( strchr ( V_257 , '(' ) || F_74 ( V_3 ) ) {
V_33 -> error = L_49 ;
return - V_37 ;
}
V_259 = V_257 ;
V_261 = F_247 ( & V_259 , L_33 ) ;
V_35 = F_247 ( & V_261 , L_29 ) ;
if ( ! V_261 )
V_3 -> V_54 = 1 ;
else if ( sscanf ( V_261 , L_32 , & V_3 -> V_54 , & V_236 ) != 1 ||
! F_249 ( V_3 -> V_54 ) ) {
V_33 -> error = L_50 ;
return - V_37 ;
}
V_3 -> V_53 = V_3 -> V_54 ;
V_3 -> V_35 = F_217 ( V_35 , V_41 ) ;
if ( ! V_3 -> V_35 )
goto V_262;
V_260 = F_247 ( & V_259 , L_33 ) ;
* V_258 = F_247 ( & V_259 , L_33 ) ;
* V_243 = F_247 ( & * V_258 , L_29 ) ;
if ( V_259 )
F_239 ( L_51 ) ;
if ( ! V_260 || ( ! strcmp ( V_260 , L_35 ) && ! * V_243 ) ) {
V_260 = L_52 ;
* V_243 = L_35 ;
}
if ( strcmp ( V_260 , L_53 ) && ! * V_243 ) {
V_33 -> error = L_54 ;
return - V_37 ;
}
V_254 = F_201 ( V_263 , V_41 ) ;
if ( ! V_254 )
goto V_262;
V_93 = snprintf ( V_254 , V_263 ,
L_55 , V_260 , V_35 ) ;
if ( V_93 < 0 ) {
F_31 ( V_254 ) ;
goto V_262;
}
V_93 = F_203 ( V_3 , V_254 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_46 ;
F_31 ( V_254 ) ;
return V_93 ;
}
return 0 ;
V_262:
V_33 -> error = L_56 ;
return - V_42 ;
}
static int F_250 ( struct V_32 * V_33 , char * V_257 , char * V_25 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
char * V_243 = NULL , * V_258 = NULL ;
int V_93 ;
V_3 -> V_241 = F_217 ( V_257 , V_41 ) ;
if ( ! V_3 -> V_241 ) {
V_33 -> error = L_56 ;
return - V_42 ;
}
if ( F_245 ( V_257 , L_45 ) )
V_93 = F_246 ( V_33 , V_257 , V_25 , & V_243 , & V_258 ) ;
else
V_93 = F_248 ( V_33 , V_257 , V_25 , & V_243 , & V_258 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_235 ( V_33 , V_243 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_226 ( V_3 , V_25 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_57 ;
return V_93 ;
}
if ( V_3 -> V_138 && V_3 -> V_138 -> V_264 ) {
V_93 = V_3 -> V_138 -> V_264 ( V_3 , V_33 , V_258 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_58 ;
return V_93 ;
}
}
if ( V_3 -> V_138 && V_3 -> V_138 -> V_265 ) {
V_93 = V_3 -> V_138 -> V_265 ( V_3 ) ;
if ( V_93 < 0 ) {
V_33 -> error = L_59 ;
return V_93 ;
}
}
return V_93 ;
}
static int F_251 ( struct V_32 * V_33 , unsigned int V_266 , char * * V_267 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
struct V_268 V_269 ;
static struct V_270 V_271 [] = {
{ 0 , 6 , L_60 } ,
} ;
unsigned int V_272 , V_46 ;
const char * V_273 , * V_274 ;
char V_236 ;
int V_93 ;
V_269 . V_266 = V_266 ;
V_269 . V_267 = V_267 ;
V_93 = F_252 ( V_271 , & V_269 , & V_272 , & V_33 -> error ) ;
if ( V_93 )
return V_93 ;
while ( V_272 -- ) {
V_273 = F_253 ( & V_269 ) ;
if ( ! V_273 ) {
V_33 -> error = L_61 ;
return - V_37 ;
}
if ( ! strcasecmp ( V_273 , L_62 ) )
V_33 -> V_275 = 1 ;
else if ( ! strcasecmp ( V_273 , L_63 ) )
F_224 ( V_276 , & V_3 -> V_64 ) ;
else if ( ! strcasecmp ( V_273 , L_64 ) )
F_224 ( V_202 , & V_3 -> V_64 ) ;
else if ( sscanf ( V_273 , L_65 , & V_46 ) == 1 ) {
if ( V_46 == 0 || V_46 > V_277 ) {
V_33 -> error = L_66 ;
return - V_37 ;
}
V_3 -> V_94 = V_46 ;
V_274 = strchr ( V_273 + strlen ( L_67 ) , ':' ) + 1 ;
if ( ! strcasecmp ( V_274 , L_68 ) ) {
F_224 ( V_84 , & V_3 -> V_85 ) ;
} else if ( strcasecmp ( V_274 , L_69 ) ) {
V_33 -> error = L_70 ;
return - V_37 ;
}
V_3 -> V_242 = F_217 ( V_274 , V_41 ) ;
if ( ! V_3 -> V_242 )
return - V_42 ;
} else if ( sscanf ( V_273 , L_71 , & V_3 -> V_51 , & V_236 ) == 1 ) {
if ( V_3 -> V_51 < ( 1 << V_52 ) ||
V_3 -> V_51 > 4096 ||
( V_3 -> V_51 & ( V_3 -> V_51 - 1 ) ) ) {
V_33 -> error = L_72 ;
return - V_37 ;
}
V_3 -> V_136 = F_254 ( V_3 -> V_51 ) - V_52 ;
} else if ( ! strcasecmp ( V_273 , L_73 ) )
F_224 ( V_135 , & V_3 -> V_85 ) ;
else {
V_33 -> error = L_74 ;
return - V_37 ;
}
}
return 0 ;
}
static int F_255 ( struct V_32 * V_33 , unsigned int V_266 , char * * V_267 )
{
struct V_2 * V_3 ;
int V_26 ;
unsigned int V_278 ;
unsigned long long V_279 ;
int V_93 ;
T_6 V_280 , V_281 ;
char V_236 ;
if ( V_266 < 5 ) {
V_33 -> error = L_75 ;
return - V_37 ;
}
V_26 = F_225 ( & V_267 [ 1 ] ) ;
if ( V_26 < 0 ) {
V_33 -> error = L_76 ;
return - V_37 ;
}
V_3 = F_30 ( sizeof( * V_3 ) + V_26 * sizeof( T_1 ) , V_41 ) ;
if ( ! V_3 ) {
V_33 -> error = L_77 ;
return - V_42 ;
}
V_3 -> V_26 = V_26 ;
V_3 -> V_51 = ( 1 << V_52 ) ;
V_3 -> V_136 = 0 ;
V_33 -> V_238 = V_3 ;
if ( V_266 > 5 ) {
V_93 = F_251 ( V_33 , V_266 - 5 , & V_267 [ 5 ] ) ;
if ( V_93 )
goto V_40;
}
V_93 = F_250 ( V_33 , V_267 [ 0 ] , V_267 [ 1 ] ) ;
if ( V_93 < 0 )
goto V_40;
if ( F_74 ( V_3 ) ) {
V_3 -> V_123 = sizeof( struct V_125 ) ;
V_3 -> V_123 += F_256 ( F_2 ( V_3 ) ) ;
V_278 = F_95 ( F_2 ( V_3 ) ) ;
} else {
V_3 -> V_123 = sizeof( struct V_142 ) ;
V_3 -> V_123 += F_257 ( F_1 ( V_3 ) ) ;
V_278 = F_96 ( F_1 ( V_3 ) ) ;
}
V_3 -> V_123 = F_94 ( V_3 -> V_123 , F_258 ( struct V_9 ) ) ;
if ( V_278 < V_282 ) {
V_280 = - ( V_3 -> V_123 + sizeof( struct V_9 ) )
& V_278 ;
} else {
V_280 = V_278 ;
}
V_93 = - V_42 ;
V_281 = sizeof( struct V_9 ) +
V_280 + V_3 -> V_11 +
V_3 -> V_11 +
sizeof( T_4 ) +
sizeof( unsigned int ) ;
V_3 -> V_144 = F_259 ( V_283 , V_3 -> V_123 + V_281 ) ;
if ( ! V_3 -> V_144 ) {
V_33 -> error = L_78 ;
goto V_40;
}
V_3 -> V_149 = V_33 -> V_284 =
F_94 ( sizeof( struct V_87 ) + V_3 -> V_123 + V_281 ,
V_285 ) ;
V_3 -> V_169 = F_260 ( V_286 , 0 ) ;
if ( ! V_3 -> V_169 ) {
V_33 -> error = L_79 ;
goto V_40;
}
V_3 -> V_43 = F_261 ( V_283 , 0 ) ;
if ( ! V_3 -> V_43 ) {
V_33 -> error = L_80 ;
goto V_40;
}
F_262 ( & V_3 -> V_168 ) ;
V_93 = - V_37 ;
if ( ( sscanf ( V_267 [ 2 ] , L_81 , & V_279 , & V_236 ) != 1 ) ||
( V_279 & ( ( V_3 -> V_51 >> V_52 ) - 1 ) ) ) {
V_33 -> error = L_82 ;
goto V_40;
}
V_3 -> V_121 = V_279 ;
V_93 = F_263 ( V_33 , V_267 [ 3 ] , F_264 ( V_33 -> V_287 ) , & V_3 -> V_105 ) ;
if ( V_93 ) {
V_33 -> error = L_83 ;
goto V_40;
}
V_93 = - V_37 ;
if ( sscanf ( V_267 [ 4 ] , L_81 , & V_279 , & V_236 ) != 1 ) {
V_33 -> error = L_84 ;
goto V_40;
}
V_3 -> V_99 = V_279 ;
if ( F_74 ( V_3 ) || V_3 -> V_114 ) {
V_93 = F_84 ( V_3 , V_33 ) ;
if ( V_93 )
goto V_40;
V_3 -> V_288 = V_289 / V_3 -> V_94 ;
if ( ! V_3 -> V_288 )
V_3 -> V_288 = 1 ;
V_3 -> V_173 = F_259 ( V_283 ,
V_3 -> V_288 * V_3 -> V_94 ) ;
if ( ! V_3 -> V_173 ) {
V_33 -> error = L_85 ;
goto V_40;
}
V_3 -> V_288 <<= V_3 -> V_136 ;
}
V_93 = - V_42 ;
V_3 -> V_184 = F_265 ( L_86 , V_290 | V_291 | V_292 , 1 ) ;
if ( ! V_3 -> V_184 ) {
V_33 -> error = L_87 ;
goto V_40;
}
if ( F_75 ( V_276 , & V_3 -> V_64 ) )
V_3 -> V_209 = F_265 ( L_88 , V_290 | V_291 | V_292 , 1 ) ;
else
V_3 -> V_209 = F_265 ( L_88 ,
V_290 | V_291 | V_292 | V_293 ,
F_266 () ) ;
if ( ! V_3 -> V_209 ) {
V_33 -> error = L_89 ;
goto V_40;
}
F_267 ( & V_3 -> V_191 ) ;
V_3 -> V_186 = V_197 ;
V_3 -> V_239 = F_268 ( F_164 , V_3 , L_90 ) ;
if ( F_20 ( V_3 -> V_239 ) ) {
V_93 = F_29 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
V_33 -> error = L_91 ;
goto V_40;
}
F_269 ( V_3 -> V_239 ) ;
V_33 -> V_294 = 1 ;
return 0 ;
V_40:
F_229 ( V_33 ) ;
return V_93 ;
}
static int F_270 ( struct V_32 * V_33 , struct V_89 * V_89 )
{
struct V_87 * V_88 ;
struct V_2 * V_3 = V_33 -> V_238 ;
if ( F_77 ( V_89 -> V_180 & V_295 ||
F_271 ( V_89 ) == V_296 ) ) {
V_89 -> V_179 = V_3 -> V_105 -> V_106 ;
if ( F_79 ( V_89 ) )
V_89 -> V_118 . V_98 = V_3 -> V_99 +
F_272 ( V_33 , V_89 -> V_118 . V_98 ) ;
return V_297 ;
}
if ( F_77 ( V_89 -> V_118 . V_97 > ( V_286 << V_159 ) ) &&
( F_56 ( V_89 ) == V_70 || V_3 -> V_94 ) )
F_273 ( V_89 , ( ( V_286 << V_159 ) >> V_52 ) ) ;
if ( F_77 ( ( V_89 -> V_118 . V_98 & ( ( V_3 -> V_51 >> V_52 ) - 1 ) ) != 0 ) )
return - V_134 ;
if ( F_77 ( V_89 -> V_118 . V_97 & ( V_3 -> V_51 - 1 ) ) )
return - V_134 ;
V_88 = F_129 ( V_89 , V_3 -> V_149 ) ;
F_149 ( V_88 , V_3 , V_89 , F_272 ( V_33 , V_89 -> V_118 . V_98 ) ) ;
if ( V_3 -> V_94 ) {
unsigned V_92 = V_3 -> V_94 * ( F_79 ( V_89 ) >> V_3 -> V_136 ) ;
if ( F_77 ( V_92 > V_298 ) ||
F_77 ( ! ( V_88 -> V_102 = F_201 ( V_92 ,
V_95 | V_299 | V_300 | V_301 ) ) ) ) {
if ( F_79 ( V_89 ) > V_3 -> V_288 )
F_273 ( V_89 , V_3 -> V_288 ) ;
V_88 -> V_102 = F_121 ( V_3 -> V_173 , V_95 ) ;
V_88 -> V_171 = true ;
}
}
if ( F_74 ( V_3 ) )
V_88 -> V_68 . V_31 . V_147 = (struct V_125 * ) ( V_88 + 1 ) ;
else
V_88 -> V_68 . V_31 . V_18 = (struct V_142 * ) ( V_88 + 1 ) ;
if ( F_56 ( V_88 -> V_148 ) == V_177 ) {
if ( F_156 ( V_88 , V_161 ) )
F_160 ( V_88 ) ;
} else
F_155 ( V_88 ) ;
return V_302 ;
}
static void F_274 ( struct V_32 * V_33 , T_7 type ,
unsigned V_303 , char * V_304 , unsigned V_305 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
unsigned V_62 , V_306 = 0 ;
int V_307 = 0 ;
switch ( type ) {
case V_308 :
V_304 [ 0 ] = '\0' ;
break;
case V_309 :
F_275 ( L_92 , V_3 -> V_241 ) ;
if ( V_3 -> V_26 > 0 ) {
if ( V_3 -> V_224 )
F_275 ( L_93 , V_3 -> V_26 , V_3 -> V_224 ) ;
else
for ( V_62 = 0 ; V_62 < V_3 -> V_26 ; V_62 ++ )
F_275 ( L_94 , V_3 -> V_25 [ V_62 ] ) ;
} else
F_275 ( L_33 ) ;
F_275 ( L_95 , ( unsigned long long ) V_3 -> V_121 ,
V_3 -> V_105 -> V_109 , ( unsigned long long ) V_3 -> V_99 ) ;
V_307 += ! ! V_33 -> V_275 ;
V_307 += F_75 ( V_276 , & V_3 -> V_64 ) ;
V_307 += F_75 ( V_202 , & V_3 -> V_64 ) ;
V_307 += V_3 -> V_51 != ( 1 << V_52 ) ;
V_307 += F_75 ( V_135 , & V_3 -> V_85 ) ;
if ( V_3 -> V_94 )
V_307 ++ ;
if ( V_307 ) {
F_275 ( L_96 , V_307 ) ;
if ( V_33 -> V_275 )
F_275 ( L_97 ) ;
if ( F_75 ( V_276 , & V_3 -> V_64 ) )
F_275 ( L_98 ) ;
if ( F_75 ( V_202 , & V_3 -> V_64 ) )
F_275 ( L_99 ) ;
if ( V_3 -> V_94 )
F_275 ( L_100 , V_3 -> V_94 , V_3 -> V_242 ) ;
if ( V_3 -> V_51 != ( 1 << V_52 ) )
F_275 ( L_101 , V_3 -> V_51 ) ;
if ( F_75 ( V_135 , & V_3 -> V_85 ) )
F_275 ( L_102 ) ;
}
break;
}
}
static void F_276 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
F_224 ( V_310 , & V_3 -> V_64 ) ;
}
static int F_277 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
if ( ! F_75 ( V_234 , & V_3 -> V_64 ) ) {
F_216 ( L_103 ) ;
return - V_311 ;
}
return 0 ;
}
static void F_278 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
F_223 ( V_310 , & V_3 -> V_64 ) ;
}
static int F_279 ( struct V_32 * V_33 , unsigned V_266 , char * * V_267 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
int V_26 , V_93 = - V_37 ;
if ( V_266 < 2 )
goto error;
if ( ! strcasecmp ( V_267 [ 0 ] , L_104 ) ) {
if ( ! F_75 ( V_310 , & V_3 -> V_64 ) ) {
F_239 ( L_105 ) ;
return - V_37 ;
}
if ( V_266 == 3 && ! strcasecmp ( V_267 [ 1 ] , L_106 ) ) {
V_26 = F_225 ( & V_267 [ 2 ] ) ;
if ( V_26 < 0 || V_3 -> V_26 != V_26 ) {
memset ( V_267 [ 2 ] , '0' , strlen ( V_267 [ 2 ] ) ) ;
return - V_37 ;
}
V_93 = F_226 ( V_3 , V_267 [ 2 ] ) ;
if ( V_93 )
return V_93 ;
if ( V_3 -> V_138 && V_3 -> V_138 -> V_265 )
V_93 = V_3 -> V_138 -> V_265 ( V_3 ) ;
return V_93 ;
}
if ( V_266 == 2 && ! strcasecmp ( V_267 [ 1 ] , L_107 ) ) {
if ( V_3 -> V_138 && V_3 -> V_138 -> V_312 ) {
V_93 = V_3 -> V_138 -> V_312 ( V_3 ) ;
if ( V_93 )
return V_93 ;
}
return F_228 ( V_3 ) ;
}
}
error:
F_239 ( L_108 ) ;
return - V_37 ;
}
static int F_280 ( struct V_32 * V_33 ,
T_8 V_313 , void * V_57 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
return V_313 ( V_33 , V_3 -> V_105 , V_3 -> V_99 , V_33 -> V_163 , V_57 ) ;
}
static void F_281 ( struct V_32 * V_33 , struct V_314 * V_315 )
{
struct V_2 * V_3 = V_33 -> V_238 ;
V_315 -> V_316 = V_158 ;
if ( V_3 -> V_51 != ( 1 << V_52 ) ) {
V_315 -> V_317 = V_3 -> V_51 ;
V_315 -> V_318 = V_3 -> V_51 ;
F_282 ( V_315 , V_3 -> V_51 ) ;
}
}
static int T_9 F_283 ( void )
{
int V_31 ;
V_31 = F_284 ( & V_319 ) ;
if ( V_31 < 0 )
F_216 ( L_109 , V_31 ) ;
return V_31 ;
}
static void T_10 F_285 ( void )
{
F_286 ( & V_319 ) ;
}
