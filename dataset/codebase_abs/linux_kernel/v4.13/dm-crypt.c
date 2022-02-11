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
static int F_7 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
memset ( V_8 , 0 , V_3 -> V_11 ) ;
* ( V_15 * ) & V_8 [ V_3 -> V_11 - sizeof( V_16 ) ] = F_8 ( V_10 -> V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_19 . V_18 ;
F_10 ( V_20 , V_18 -> V_21 ) ;
struct V_22 V_23 ;
struct V_24 * V_25 ;
int V_26 ;
F_11 ( & V_23 , V_3 -> V_27 , V_3 -> V_28 ) ;
F_12 ( V_20 , V_18 -> V_21 ) ;
F_13 ( V_20 , V_29 , NULL , NULL ) ;
F_14 ( V_20 , & V_23 , V_18 -> V_30 , V_3 -> V_28 ) ;
V_26 = F_15 ( V_20 ) ;
F_16 ( V_20 ) ;
if ( V_26 )
return V_26 ;
V_25 = V_3 -> V_31 ;
V_26 = F_17 ( V_25 , V_18 -> V_30 ,
F_18 ( V_18 -> V_21 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_19 . V_18 ;
unsigned V_32 = F_18 ( V_18 -> V_21 ) ;
struct V_24 * V_25 ;
int V_33 , V_26 = 0 ;
memset ( V_18 -> V_30 , 0 , V_32 ) ;
V_25 = V_3 -> V_31 ;
V_33 = F_17 ( V_25 , V_18 -> V_30 , V_32 ) ;
if ( V_33 )
V_26 = V_33 ;
return V_26 ;
}
static struct V_24 * F_20 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
const T_1 * V_30 ,
unsigned int V_36 )
{
struct V_24 * V_25 ;
int V_26 ;
V_25 = F_21 ( V_3 -> V_37 , 0 , V_38 ) ;
if ( F_22 ( V_25 ) ) {
V_35 -> error = L_1 ;
return V_25 ;
}
if ( F_23 ( V_25 ) != V_3 -> V_11 ) {
V_35 -> error = L_2
L_3 ;
F_24 ( V_25 ) ;
return F_25 ( - V_39 ) ;
}
V_26 = F_17 ( V_25 , V_30 , V_36 ) ;
if ( V_26 ) {
V_35 -> error = L_4 ;
F_24 ( V_25 ) ;
return F_25 ( V_26 ) ;
}
return V_25 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
struct V_17 * V_18 = & V_3 -> V_19 . V_18 ;
F_27 ( V_18 -> V_21 ) ;
V_18 -> V_21 = NULL ;
F_28 ( V_18 -> V_30 ) ;
V_18 -> V_30 = NULL ;
V_25 = V_3 -> V_31 ;
if ( V_25 )
F_24 ( V_25 ) ;
V_3 -> V_31 = NULL ;
}
static int F_29 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_24 * V_25 = NULL ;
struct V_41 * V_21 = NULL ;
T_1 * V_30 = NULL ;
int V_26 ;
if ( ! V_40 ) {
V_35 -> error = L_5 ;
return - V_39 ;
}
V_21 = F_30 ( V_40 , 0 , V_38 ) ;
if ( F_22 ( V_21 ) ) {
V_35 -> error = L_6 ;
V_26 = F_31 ( V_21 ) ;
goto V_42;
}
V_30 = F_32 ( F_18 ( V_21 ) , V_43 ) ;
if ( ! V_30 ) {
V_35 -> error = L_7 ;
V_26 = - V_44 ;
goto V_42;
}
V_3 -> V_19 . V_18 . V_30 = V_30 ;
V_3 -> V_19 . V_18 . V_21 = V_21 ;
V_25 = F_20 ( V_3 , V_35 , V_30 ,
F_18 ( V_21 ) ) ;
if ( F_22 ( V_25 ) ) {
F_26 ( V_3 ) ;
return F_31 ( V_25 ) ;
}
V_3 -> V_31 = V_25 ;
return 0 ;
V_42:
if ( V_21 && ! F_22 ( V_21 ) )
F_27 ( V_21 ) ;
F_33 ( V_30 ) ;
return V_26 ;
}
static int F_34 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_24 * V_25 = V_3 -> V_31 ;
memset ( V_8 , 0 , V_3 -> V_11 ) ;
* ( V_14 * ) V_8 = F_6 ( V_10 -> V_13 ) ;
F_35 ( V_25 , V_8 , V_8 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
unsigned V_45 = F_37 ( F_1 ( V_3 ) ) ;
int log = F_38 ( V_45 ) ;
if ( 1 << log != V_45 ) {
V_35 -> error = L_8 ;
return - V_39 ;
}
if ( log > 9 ) {
V_35 -> error = L_9 ;
return - V_39 ;
}
V_3 -> V_19 . V_46 . V_47 = 9 - log ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 )
{
}
static int F_40 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
V_15 V_48 ;
memset ( V_8 , 0 , V_3 -> V_11 - sizeof( V_16 ) ) ;
V_48 = F_8 ( ( ( V_16 ) V_10 -> V_13 << V_3 -> V_19 . V_46 . V_47 ) + 1 ) ;
F_41 ( V_48 , ( V_15 * ) ( V_8 + V_3 -> V_11 - sizeof( V_16 ) ) ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
memset ( V_8 , 0 , V_3 -> V_11 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_49 * V_50 = & V_3 -> V_19 . V_50 ;
if ( V_50 -> V_21 && ! F_22 ( V_50 -> V_21 ) )
F_44 ( V_50 -> V_21 ) ;
V_50 -> V_21 = NULL ;
F_28 ( V_50 -> V_51 ) ;
V_50 -> V_51 = NULL ;
}
static int F_45 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_49 * V_50 = & V_3 -> V_19 . V_50 ;
if ( V_3 -> V_52 != ( 1 << V_53 ) ) {
V_35 -> error = L_10 ;
return - V_39 ;
}
V_50 -> V_21 = F_46 ( L_11 , 0 , 0 ) ;
if ( F_22 ( V_50 -> V_21 ) ) {
V_35 -> error = L_12 ;
return F_31 ( V_50 -> V_21 ) ;
}
if ( V_3 -> V_54 == V_3 -> V_55 ) {
V_50 -> V_51 = NULL ;
return 0 ;
}
V_50 -> V_51 = F_32 ( V_56 , V_43 ) ;
if ( ! V_50 -> V_51 ) {
F_43 ( V_3 ) ;
V_35 -> error = L_13 ;
return - V_44 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_49 * V_50 = & V_3 -> V_19 . V_50 ;
int V_57 = V_3 -> V_28 / V_3 -> V_54 ;
if ( V_50 -> V_51 )
memcpy ( V_50 -> V_51 , V_3 -> V_27 + ( V_3 -> V_55 * V_57 ) ,
F_48 ( V_50 -> V_21 ) ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_49 * V_50 = & V_3 -> V_19 . V_50 ;
if ( V_50 -> V_51 )
memset ( V_50 -> V_51 , 0 , V_56 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 ,
T_1 * V_58 )
{
struct V_49 * V_50 = & V_3 -> V_19 . V_50 ;
F_51 ( V_59 , V_50 -> V_21 ) ;
struct V_60 V_61 ;
V_12 V_62 [ 4 ] ;
int V_63 , V_33 ;
V_59 -> V_64 = V_50 -> V_21 ;
V_59 -> V_65 = V_29 ;
V_33 = F_52 ( V_59 ) ;
if ( V_33 )
return V_33 ;
if ( V_50 -> V_51 ) {
V_33 = F_53 ( V_59 , V_50 -> V_51 , V_56 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_53 ( V_59 , V_58 + 16 , 16 * 31 ) ;
if ( V_33 )
return V_33 ;
V_62 [ 0 ] = F_4 ( V_10 -> V_13 & 0xFFFFFFFF ) ;
V_62 [ 1 ] = F_4 ( ( ( ( V_16 ) V_10 -> V_13 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_62 [ 2 ] = F_4 ( 4024 ) ;
V_62 [ 3 ] = 0 ;
V_33 = F_53 ( V_59 , ( T_1 * ) V_62 , sizeof( V_62 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_54 ( V_59 , & V_61 ) ;
if ( V_33 )
return V_33 ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ )
F_55 ( & V_61 . V_67 [ V_63 ] ) ;
memcpy ( V_8 , & V_61 . V_67 , V_3 -> V_11 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_22 * V_23 ;
T_1 * V_68 ;
int V_33 = 0 ;
if ( F_57 ( V_10 -> V_69 -> V_70 ) == V_71 ) {
V_23 = F_58 ( V_3 , V_10 -> V_72 ) ;
V_68 = F_59 ( F_60 ( V_23 ) ) ;
V_33 = F_50 ( V_3 , V_8 , V_10 , V_68 + V_23 -> V_73 ) ;
F_61 ( V_68 ) ;
} else
memset ( V_8 , 0 , V_3 -> V_11 ) ;
return V_33 ;
}
static int F_62 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_22 * V_23 ;
T_1 * V_74 ;
int V_33 ;
if ( F_57 ( V_10 -> V_69 -> V_70 ) == V_71 )
return 0 ;
V_23 = F_58 ( V_3 , V_10 -> V_75 ) ;
V_74 = F_59 ( F_60 ( V_23 ) ) ;
V_33 = F_50 ( V_3 , V_8 , V_10 , V_74 + V_23 -> V_73 ) ;
if ( ! V_33 )
F_63 ( V_74 + V_23 -> V_73 , V_8 , V_3 -> V_11 ) ;
F_61 ( V_74 ) ;
return V_33 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_76 * V_77 = & V_3 -> V_19 . V_77 ;
F_28 ( V_77 -> V_78 ) ;
V_77 -> V_78 = NULL ;
F_28 ( V_77 -> V_79 ) ;
V_77 -> V_79 = NULL ;
if ( V_77 -> V_80 && ! F_22 ( V_77 -> V_80 ) )
F_44 ( V_77 -> V_80 ) ;
V_77 -> V_80 = NULL ;
}
static int F_65 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_76 * V_77 = & V_3 -> V_19 . V_77 ;
if ( V_3 -> V_52 != ( 1 << V_53 ) ) {
V_35 -> error = L_14 ;
return - V_39 ;
}
if ( V_3 -> V_28 <= ( V_3 -> V_11 + V_81 ) ) {
V_35 -> error = L_15 ;
return - V_39 ;
}
V_77 -> V_80 = F_46 ( L_16 , 0 , 0 ) ;
if ( F_22 ( V_77 -> V_80 ) ) {
V_35 -> error = L_17 ;
return F_31 ( V_77 -> V_80 ) ;
}
V_77 -> V_78 = F_32 ( V_3 -> V_11 , V_43 ) ;
V_77 -> V_79 = F_32 ( V_81 , V_43 ) ;
if ( ! V_77 -> V_78 || ! V_77 -> V_79 ) {
F_64 ( V_3 ) ;
V_35 -> error = L_18 ;
return - V_44 ;
}
return 0 ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_76 * V_77 = & V_3 -> V_19 . V_77 ;
int V_82 = V_3 -> V_28 - V_3 -> V_11 - V_81 ;
memcpy ( V_77 -> V_78 , & V_3 -> V_27 [ V_82 ] , V_3 -> V_11 ) ;
memcpy ( V_77 -> V_79 , & V_3 -> V_27 [ V_82 + V_3 -> V_11 ] ,
V_81 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_76 * V_77 = & V_3 -> V_19 . V_77 ;
memset ( V_77 -> V_78 , 0 , V_3 -> V_11 ) ;
memset ( V_77 -> V_79 , 0 , V_81 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
T_1 * V_58 )
{
struct V_76 * V_77 = & V_3 -> V_19 . V_77 ;
V_14 V_83 = F_6 ( V_10 -> V_13 ) ;
T_1 V_62 [ V_81 ] ;
F_51 ( V_59 , V_77 -> V_80 ) ;
int V_63 , V_33 ;
memcpy ( V_62 , V_77 -> V_79 , V_81 ) ;
F_63 ( V_62 , ( T_1 * ) & V_83 , 8 ) ;
F_63 ( & V_62 [ 8 ] , ( T_1 * ) & V_83 , 8 ) ;
V_59 -> V_64 = V_77 -> V_80 ;
V_59 -> V_65 = V_29 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
V_33 = F_52 ( V_59 ) ;
if ( V_33 )
goto V_84;
V_33 = F_53 ( V_59 , & V_62 [ V_63 * 4 ] , 4 ) ;
if ( V_33 )
goto V_84;
V_33 = F_69 ( V_59 , & V_62 [ V_63 * 4 ] ) ;
if ( V_33 )
goto V_84;
}
F_63 ( & V_62 [ 0 ] , & V_62 [ 12 ] , 4 ) ;
F_63 ( & V_62 [ 4 ] , & V_62 [ 8 ] , 4 ) ;
for ( V_63 = 0 ; V_63 < ( ( 1 << V_53 ) / 8 ) ; V_63 ++ )
F_63 ( V_58 + V_63 * 8 , V_62 , 8 ) ;
V_84:
F_70 ( V_62 , sizeof( V_62 ) ) ;
return V_33 ;
}
static int F_71 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_22 * V_23 ;
struct V_76 * V_77 = & V_3 -> V_19 . V_77 ;
V_14 V_83 = F_6 ( V_10 -> V_13 ) ;
T_1 * V_68 ;
int V_33 = 0 ;
if ( F_57 ( V_10 -> V_69 -> V_70 ) != V_71 ) {
V_23 = F_58 ( V_3 , V_10 -> V_72 ) ;
V_68 = F_59 ( F_60 ( V_23 ) ) ;
V_33 = F_68 ( V_3 , V_10 , V_68 + V_23 -> V_73 ) ;
F_61 ( V_68 ) ;
}
memcpy ( V_8 , V_77 -> V_78 , V_3 -> V_11 ) ;
F_63 ( V_8 , ( T_1 * ) & V_83 , 8 ) ;
if ( V_3 -> V_11 > 8 )
F_63 ( & V_8 [ 8 ] , ( T_1 * ) & V_83 , V_3 -> V_11 - 8 ) ;
return V_33 ;
}
static int F_72 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_22 * V_23 ;
T_1 * V_74 ;
int V_33 ;
if ( F_57 ( V_10 -> V_69 -> V_70 ) != V_71 )
return 0 ;
V_23 = F_58 ( V_3 , V_10 -> V_75 ) ;
V_74 = F_59 ( F_60 ( V_23 ) ) ;
V_33 = F_68 ( V_3 , V_10 , V_74 + V_23 -> V_73 ) ;
F_61 ( V_74 ) ;
return V_33 ;
}
static int F_73 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
F_74 ( V_8 , V_3 -> V_11 ) ;
return 0 ;
}
static bool F_75 ( struct V_2 * V_3 )
{
return F_76 ( V_85 , & V_3 -> V_86 ) ;
}
static bool F_77 ( struct V_2 * V_3 )
{
return F_75 ( V_3 ) && V_3 -> V_87 ;
}
static struct V_22 * F_58 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
if ( F_78 ( F_75 ( V_3 ) ) )
return & V_23 [ 2 ] ;
return V_23 ;
}
static int F_79 ( struct V_88 * V_89 , struct V_90 * V_90 )
{
struct V_91 * V_92 ;
unsigned int V_93 ;
int V_94 ;
if ( ! F_80 ( V_90 ) || ! V_89 -> V_3 -> V_95 )
return 0 ;
V_92 = F_81 ( V_90 , V_96 , 1 ) ;
if ( F_22 ( V_92 ) )
return F_31 ( V_92 ) ;
V_93 = V_89 -> V_3 -> V_95 * F_80 ( V_90 ) ;
V_92 -> V_97 . V_98 = V_93 ;
V_92 -> V_97 . V_99 = V_89 -> V_3 -> V_100 + V_89 -> V_83 ;
V_92 -> V_101 &= ~ V_102 ;
V_94 = F_82 ( V_90 , F_83 ( V_89 -> V_103 ) ,
V_93 , F_84 ( V_89 -> V_103 ) ) ;
if ( F_78 ( V_94 != V_93 ) )
return - V_44 ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , struct V_34 * V_35 )
{
#ifdef F_86
struct V_104 * V_105 = F_87 ( V_3 -> V_106 -> V_107 -> V_108 ) ;
if ( ! V_105 || strcasecmp ( V_105 -> V_109 -> V_110 , L_19 ) ) {
V_35 -> error = L_20 ;
return - V_39 ;
}
if ( V_105 -> V_111 != V_3 -> V_95 ||
V_105 -> V_112 != V_3 -> V_95 ) {
V_35 -> error = L_21 ;
return - V_39 ;
}
if ( 1 << V_105 -> V_113 != V_3 -> V_52 ) {
V_35 -> error = L_22 ;
return - V_39 ;
}
if ( F_75 ( V_3 ) ) {
V_3 -> V_114 = V_3 -> V_95 - V_3 -> V_115 ;
F_88 ( L_23 ,
V_3 -> V_114 , V_3 -> V_115 ) ;
if ( F_89 ( F_2 ( V_3 ) , V_3 -> V_114 ) ) {
V_35 -> error = L_24 ;
return - V_39 ;
}
} else if ( V_3 -> V_115 )
F_88 ( L_25 ,
V_3 -> V_115 ) ;
if ( ( V_3 -> V_114 + V_3 -> V_115 ) != V_105 -> V_111 ) {
V_35 -> error = L_26 ;
return - V_39 ;
}
return 0 ;
#else
V_35 -> error = L_20 ;
return - V_39 ;
#endif
}
static void F_90 ( struct V_2 * V_3 ,
struct V_116 * V_69 ,
struct V_90 * V_117 , struct V_90 * V_70 ,
T_2 V_83 )
{
V_69 -> V_70 = V_70 ;
V_69 -> V_117 = V_117 ;
if ( V_70 )
V_69 -> V_118 = V_70 -> V_119 ;
if ( V_117 )
V_69 -> V_120 = V_117 -> V_119 ;
V_69 -> V_121 = V_83 + V_3 -> V_122 ;
F_91 ( & V_69 -> V_123 ) ;
}
static struct V_9 * F_92 ( struct V_2 * V_3 ,
void * V_20 )
{
return (struct V_9 * ) ( ( char * ) V_20 + V_3 -> V_124 ) ;
}
static void * F_93 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
return ( void * ) ( ( char * ) V_10 - V_3 -> V_124 ) ;
}
static T_1 * F_94 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( F_75 ( V_3 ) )
return ( T_1 * ) F_95 ( ( unsigned long ) ( V_10 + 1 ) ,
F_96 ( F_2 ( V_3 ) ) + 1 ) ;
else
return ( T_1 * ) F_95 ( ( unsigned long ) ( V_10 + 1 ) ,
F_97 ( F_1 ( V_3 ) ) + 1 ) ;
}
static T_1 * F_98 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
return F_94 ( V_3 , V_10 ) + V_3 -> V_11 ;
}
static T_3 * F_99 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
T_1 * V_125 = F_94 ( V_3 , V_10 ) + V_3 -> V_11 + V_3 -> V_11 ;
return ( T_3 * ) V_125 ;
}
static unsigned int * F_100 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
T_1 * V_125 = F_94 ( V_3 , V_10 ) + V_3 -> V_11 +
V_3 -> V_11 + sizeof( T_3 ) ;
return ( unsigned int * ) V_125 ;
}
static void * F_101 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_116 * V_69 = V_10 -> V_69 ;
struct V_88 * V_89 = F_102 ( V_69 , struct V_88 , V_69 ) ;
return & V_89 -> V_103 [ * F_100 ( V_3 , V_10 ) *
V_3 -> V_95 ] ;
}
static void * F_103 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
return F_101 ( V_3 , V_10 ) + V_3 -> V_114 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_116 * V_69 ,
struct V_126 * V_20 ,
unsigned int V_127 )
{
struct V_128 V_129 = F_105 ( V_69 -> V_70 , V_69 -> V_118 ) ;
struct V_128 V_130 = F_105 ( V_69 -> V_117 , V_69 -> V_120 ) ;
struct V_9 * V_10 ;
T_1 * V_8 , * V_131 , * V_132 , * V_133 ;
T_3 * V_83 ;
int V_33 = 0 ;
F_106 ( V_3 -> V_115 && V_3 -> V_115 != V_3 -> V_11 ) ;
if ( F_78 ( V_129 . V_134 & ( V_3 -> V_52 - 1 ) ) )
return - V_135 ;
V_10 = F_92 ( V_3 , V_20 ) ;
V_10 -> V_13 = V_69 -> V_121 ;
if ( F_76 ( V_136 , & V_3 -> V_86 ) )
V_10 -> V_13 >>= V_3 -> V_137 ;
V_10 -> V_69 = V_69 ;
* F_100 ( V_3 , V_10 ) = V_127 ;
V_83 = F_99 ( V_3 , V_10 ) ;
* V_83 = F_6 ( V_69 -> V_121 - V_3 -> V_122 ) ;
V_8 = F_94 ( V_3 , V_10 ) ;
V_131 = F_98 ( V_3 , V_10 ) ;
V_133 = F_101 ( V_3 , V_10 ) ;
V_132 = F_103 ( V_3 , V_10 ) ;
F_107 ( V_10 -> V_72 , 4 ) ;
F_108 ( & V_10 -> V_72 [ 0 ] , V_83 , sizeof( T_3 ) ) ;
F_108 ( & V_10 -> V_72 [ 1 ] , V_131 , V_3 -> V_11 ) ;
F_109 ( & V_10 -> V_72 [ 2 ] , V_129 . V_138 , V_3 -> V_52 , V_129 . V_134 ) ;
F_108 ( & V_10 -> V_72 [ 3 ] , V_133 , V_3 -> V_114 ) ;
F_107 ( V_10 -> V_75 , 4 ) ;
F_108 ( & V_10 -> V_75 [ 0 ] , V_83 , sizeof( T_3 ) ) ;
F_108 ( & V_10 -> V_75 [ 1 ] , V_131 , V_3 -> V_11 ) ;
F_109 ( & V_10 -> V_75 [ 2 ] , V_130 . V_138 , V_3 -> V_52 , V_130 . V_134 ) ;
F_108 ( & V_10 -> V_75 [ 3 ] , V_133 , V_3 -> V_114 ) ;
if ( V_3 -> V_139 ) {
if ( V_3 -> V_115 && F_57 ( V_69 -> V_70 ) != V_71 ) {
memcpy ( V_131 , V_132 , V_3 -> V_11 ) ;
} else {
V_33 = V_3 -> V_139 -> V_140 ( V_3 , V_131 , V_10 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_3 -> V_115 )
memcpy ( V_132 , V_131 , V_3 -> V_11 ) ;
}
memcpy ( V_8 , V_131 , V_3 -> V_11 ) ;
}
F_110 ( V_20 , sizeof( T_3 ) + V_3 -> V_11 ) ;
if ( F_57 ( V_69 -> V_70 ) == V_71 ) {
F_111 ( V_20 , V_10 -> V_72 , V_10 -> V_75 ,
V_3 -> V_52 , V_8 ) ;
V_33 = F_112 ( V_20 ) ;
if ( V_3 -> V_114 + V_3 -> V_115 != V_3 -> V_95 )
memset ( V_133 + V_3 -> V_114 + V_3 -> V_115 , 0 ,
V_3 -> V_95 - ( V_3 -> V_114 + V_3 -> V_115 ) ) ;
} else {
F_111 ( V_20 , V_10 -> V_72 , V_10 -> V_75 ,
V_3 -> V_52 + V_3 -> V_114 , V_8 ) ;
V_33 = F_113 ( V_20 ) ;
}
if ( V_33 == - V_141 )
F_114 ( L_27 ,
( unsigned long long ) F_115 ( * V_83 ) ) ;
if ( ! V_33 && V_3 -> V_139 && V_3 -> V_139 -> V_142 )
V_33 = V_3 -> V_139 -> V_142 ( V_3 , V_131 , V_10 ) ;
F_116 ( V_69 -> V_70 , & V_69 -> V_118 , V_3 -> V_52 ) ;
F_116 ( V_69 -> V_117 , & V_69 -> V_120 , V_3 -> V_52 ) ;
return V_33 ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_116 * V_69 ,
struct V_143 * V_20 ,
unsigned int V_127 )
{
struct V_128 V_129 = F_105 ( V_69 -> V_70 , V_69 -> V_118 ) ;
struct V_128 V_130 = F_105 ( V_69 -> V_117 , V_69 -> V_120 ) ;
struct V_22 * V_72 , * V_75 ;
struct V_9 * V_10 ;
T_1 * V_8 , * V_131 , * V_132 ;
T_3 * V_83 ;
int V_33 = 0 ;
if ( F_78 ( V_129 . V_134 & ( V_3 -> V_52 - 1 ) ) )
return - V_135 ;
V_10 = F_92 ( V_3 , V_20 ) ;
V_10 -> V_13 = V_69 -> V_121 ;
if ( F_76 ( V_136 , & V_3 -> V_86 ) )
V_10 -> V_13 >>= V_3 -> V_137 ;
V_10 -> V_69 = V_69 ;
* F_100 ( V_3 , V_10 ) = V_127 ;
V_8 = F_94 ( V_3 , V_10 ) ;
V_131 = F_98 ( V_3 , V_10 ) ;
V_132 = F_103 ( V_3 , V_10 ) ;
V_83 = F_99 ( V_3 , V_10 ) ;
* V_83 = F_6 ( V_69 -> V_121 - V_3 -> V_122 ) ;
V_72 = & V_10 -> V_72 [ 0 ] ;
V_75 = & V_10 -> V_75 [ 0 ] ;
F_107 ( V_72 , 1 ) ;
F_109 ( V_72 , V_129 . V_138 , V_3 -> V_52 , V_129 . V_134 ) ;
F_107 ( V_75 , 1 ) ;
F_109 ( V_75 , V_130 . V_138 , V_3 -> V_52 , V_130 . V_134 ) ;
if ( V_3 -> V_139 ) {
if ( V_3 -> V_115 && F_57 ( V_69 -> V_70 ) != V_71 ) {
memcpy ( V_131 , V_132 , V_3 -> V_115 ) ;
} else {
V_33 = V_3 -> V_139 -> V_140 ( V_3 , V_131 , V_10 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_3 -> V_115 )
memcpy ( V_132 , V_131 , V_3 -> V_115 ) ;
}
memcpy ( V_8 , V_131 , V_3 -> V_11 ) ;
}
F_118 ( V_20 , V_72 , V_75 , V_3 -> V_52 , V_8 ) ;
if ( F_57 ( V_69 -> V_70 ) == V_71 )
V_33 = F_119 ( V_20 ) ;
else
V_33 = F_120 ( V_20 ) ;
if ( ! V_33 && V_3 -> V_139 && V_3 -> V_139 -> V_142 )
V_33 = V_3 -> V_139 -> V_142 ( V_3 , V_131 , V_10 ) ;
F_116 ( V_69 -> V_70 , & V_69 -> V_118 , V_3 -> V_52 ) ;
F_116 ( V_69 -> V_117 , & V_69 -> V_120 , V_3 -> V_52 ) ;
return V_33 ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_116 * V_69 )
{
unsigned V_144 = V_69 -> V_121 & ( V_3 -> V_55 - 1 ) ;
if ( ! V_69 -> V_33 . V_20 )
V_69 -> V_33 . V_20 = F_122 ( V_3 -> V_145 , V_96 ) ;
F_123 ( V_69 -> V_33 . V_20 , V_3 -> V_4 . V_5 [ V_144 ] ) ;
F_124 ( V_69 -> V_33 . V_20 ,
V_146 | V_29 ,
V_147 , F_92 ( V_3 , V_69 -> V_33 . V_20 ) ) ;
}
static void F_125 ( struct V_2 * V_3 ,
struct V_116 * V_69 )
{
if ( ! V_69 -> V_33 . V_148 )
V_69 -> V_33 . V_148 = F_122 ( V_3 -> V_145 , V_96 ) ;
F_126 ( V_69 -> V_33 . V_148 , V_3 -> V_4 . V_7 [ 0 ] ) ;
F_127 ( V_69 -> V_33 . V_148 ,
V_146 | V_29 ,
V_147 , F_92 ( V_3 , V_69 -> V_33 . V_148 ) ) ;
}
static void F_128 ( struct V_2 * V_3 ,
struct V_116 * V_69 )
{
if ( F_75 ( V_3 ) )
F_125 ( V_3 , V_69 ) ;
else
F_121 ( V_3 , V_69 ) ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_143 * V_20 , struct V_90 * V_149 )
{
struct V_88 * V_89 = F_130 ( V_149 , V_3 -> V_150 ) ;
if ( (struct V_143 * ) ( V_89 + 1 ) != V_20 )
F_131 ( V_20 , V_3 -> V_145 ) ;
}
static void F_132 ( struct V_2 * V_3 ,
struct V_126 * V_20 , struct V_90 * V_149 )
{
struct V_88 * V_89 = F_130 ( V_149 , V_3 -> V_150 ) ;
if ( (struct V_126 * ) ( V_89 + 1 ) != V_20 )
F_131 ( V_20 , V_3 -> V_145 ) ;
}
static void F_133 ( struct V_2 * V_3 , void * V_20 , struct V_90 * V_149 )
{
if ( F_75 ( V_3 ) )
F_132 ( V_3 , V_20 , V_149 ) ;
else
F_129 ( V_3 , V_20 , V_149 ) ;
}
static T_4 F_134 ( struct V_2 * V_3 ,
struct V_116 * V_69 )
{
unsigned int V_127 = 0 ;
unsigned int V_151 = V_3 -> V_52 >> V_53 ;
int V_33 ;
F_135 ( & V_69 -> V_152 , 1 ) ;
while ( V_69 -> V_118 . V_98 && V_69 -> V_120 . V_98 ) {
F_128 ( V_3 , V_69 ) ;
F_136 ( & V_69 -> V_152 ) ;
if ( F_75 ( V_3 ) )
V_33 = F_104 ( V_3 , V_69 , V_69 -> V_33 . V_148 , V_127 ) ;
else
V_33 = F_117 ( V_3 , V_69 , V_69 -> V_33 . V_20 , V_127 ) ;
switch ( V_33 ) {
case - V_153 :
F_137 ( & V_69 -> V_123 ) ;
F_138 ( & V_69 -> V_123 ) ;
case - V_154 :
V_69 -> V_33 . V_20 = NULL ;
V_69 -> V_121 += V_151 ;
V_127 ++ ;
continue;
case 0 :
F_139 ( & V_69 -> V_152 ) ;
V_69 -> V_121 += V_151 ;
V_127 ++ ;
F_140 () ;
continue;
case - V_141 :
F_139 ( & V_69 -> V_152 ) ;
return V_155 ;
default:
F_139 ( & V_69 -> V_152 ) ;
return V_156 ;
}
}
return 0 ;
}
static struct V_90 * F_141 ( struct V_88 * V_89 , unsigned V_157 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_158 ;
unsigned int V_159 = ( V_157 + V_160 - 1 ) >> V_161 ;
T_5 V_162 = V_163 | V_164 ;
unsigned V_63 , V_165 , V_166 ;
struct V_167 * V_167 ;
V_168:
if ( F_78 ( V_162 & V_169 ) )
F_142 ( & V_3 -> V_170 ) ;
V_158 = F_143 ( V_96 , V_159 , V_3 -> V_45 ) ;
if ( ! V_158 )
goto V_84;
F_144 ( V_89 , V_158 ) ;
V_166 = V_157 ;
for ( V_63 = 0 ; V_63 < V_159 ; V_63 ++ ) {
V_167 = F_122 ( V_3 -> V_171 , V_162 ) ;
if ( ! V_167 ) {
F_145 ( V_3 , V_158 ) ;
F_146 ( V_158 ) ;
V_162 |= V_169 ;
goto V_168;
}
V_165 = ( V_166 > V_160 ) ? V_160 : V_166 ;
F_147 ( V_158 , V_167 , V_165 , 0 ) ;
V_166 -= V_165 ;
}
if ( F_79 ( V_89 , V_158 ) ) {
F_145 ( V_3 , V_158 ) ;
F_146 ( V_158 ) ;
V_158 = NULL ;
}
V_84:
if ( F_78 ( V_162 & V_169 ) )
F_148 ( & V_3 -> V_170 ) ;
return V_158 ;
}
static void F_145 ( struct V_2 * V_3 , struct V_90 * V_158 )
{
unsigned int V_63 ;
struct V_128 * V_172 ;
F_149 (bv, clone, i) {
F_106 ( ! V_172 -> V_138 ) ;
F_131 ( V_172 -> V_138 , V_3 -> V_171 ) ;
V_172 -> V_138 = NULL ;
}
}
static void F_150 ( struct V_88 * V_89 , struct V_2 * V_3 ,
struct V_90 * V_90 , T_2 V_83 )
{
V_89 -> V_3 = V_3 ;
V_89 -> V_149 = V_90 ;
V_89 -> V_83 = V_83 ;
V_89 -> error = 0 ;
V_89 -> V_69 . V_33 . V_20 = NULL ;
V_89 -> V_103 = NULL ;
V_89 -> V_173 = false ;
F_135 ( & V_89 -> V_174 , 0 ) ;
}
static void F_151 ( struct V_88 * V_89 )
{
F_136 ( & V_89 -> V_174 ) ;
}
static void F_152 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_149 = V_89 -> V_149 ;
T_4 error = V_89 -> error ;
if ( ! F_153 ( & V_89 -> V_174 ) )
return;
if ( V_89 -> V_69 . V_33 . V_20 )
F_133 ( V_3 , V_89 -> V_69 . V_33 . V_20 , V_149 ) ;
if ( F_78 ( V_89 -> V_173 ) )
F_131 ( V_89 -> V_103 , V_89 -> V_3 -> V_175 ) ;
else
F_33 ( V_89 -> V_103 ) ;
V_149 -> V_176 = error ;
F_154 ( V_149 ) ;
}
static void F_155 ( struct V_90 * V_158 )
{
struct V_88 * V_89 = V_158 -> V_177 ;
struct V_2 * V_3 = V_89 -> V_3 ;
unsigned V_178 = F_57 ( V_158 ) ;
T_4 error ;
if ( V_178 == V_71 )
F_145 ( V_3 , V_158 ) ;
error = V_158 -> V_176 ;
F_146 ( V_158 ) ;
if ( V_178 == V_179 && ! error ) {
F_156 ( V_89 ) ;
return;
}
if ( F_78 ( error ) )
V_89 -> error = error ;
F_152 ( V_89 ) ;
}
static void F_144 ( struct V_88 * V_89 , struct V_90 * V_158 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
V_158 -> V_177 = V_89 ;
V_158 -> V_180 = F_155 ;
V_158 -> V_181 = V_3 -> V_106 -> V_107 ;
V_158 -> V_182 = V_89 -> V_149 -> V_182 ;
}
static int F_157 ( struct V_88 * V_89 , T_5 V_183 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_158 ;
V_158 = F_158 ( V_89 -> V_149 , V_183 , V_3 -> V_45 ) ;
if ( ! V_158 )
return 1 ;
F_151 ( V_89 ) ;
F_144 ( V_89 , V_158 ) ;
V_158 -> V_119 . V_99 = V_3 -> V_100 + V_89 -> V_83 ;
if ( F_79 ( V_89 , V_158 ) ) {
F_152 ( V_89 ) ;
F_146 ( V_158 ) ;
return 1 ;
}
F_159 ( V_158 ) ;
return 0 ;
}
static void F_160 ( struct V_184 * V_185 )
{
struct V_88 * V_89 = F_102 ( V_185 , struct V_88 , V_185 ) ;
F_151 ( V_89 ) ;
if ( F_157 ( V_89 , V_96 ) )
V_89 -> error = V_186 ;
F_152 ( V_89 ) ;
}
static void F_161 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
F_162 ( & V_89 -> V_185 , F_160 ) ;
F_163 ( V_3 -> V_187 , & V_89 -> V_185 ) ;
}
static void F_164 ( struct V_88 * V_89 )
{
struct V_90 * V_158 = V_89 -> V_69 . V_117 ;
F_159 ( V_158 ) ;
}
static int F_165 ( void * V_58 )
{
struct V_2 * V_3 = V_58 ;
struct V_88 * V_89 ;
while ( 1 ) {
struct V_188 V_189 ;
struct V_190 V_191 ;
F_166 ( V_192 , V_193 ) ;
F_167 ( & V_3 -> V_194 . V_195 ) ;
V_196:
if ( ! F_168 ( & V_3 -> V_189 ) )
goto V_197;
F_169 ( V_198 ) ;
F_170 ( & V_3 -> V_194 , & V_192 ) ;
F_171 ( & V_3 -> V_194 . V_195 ) ;
if ( F_78 ( F_172 () ) ) {
F_169 ( V_199 ) ;
F_173 ( & V_3 -> V_194 , & V_192 ) ;
break;
}
F_174 () ;
F_169 ( V_199 ) ;
F_167 ( & V_3 -> V_194 . V_195 ) ;
F_175 ( & V_3 -> V_194 , & V_192 ) ;
goto V_196;
V_197:
V_189 = V_3 -> V_189 ;
V_3 -> V_189 = V_200 ;
F_171 ( & V_3 -> V_194 . V_195 ) ;
F_106 ( F_176 ( V_189 . V_201 ) ) ;
F_177 ( & V_191 ) ;
do {
V_89 = F_178 ( F_179 ( & V_189 ) ) ;
F_180 ( & V_89 -> V_201 , & V_189 ) ;
F_164 ( V_89 ) ;
} while ( ! F_168 ( & V_189 ) );
F_181 ( & V_191 ) ;
}
return 0 ;
}
static void F_182 ( struct V_88 * V_89 , int V_202 )
{
struct V_90 * V_158 = V_89 -> V_69 . V_117 ;
struct V_2 * V_3 = V_89 -> V_3 ;
unsigned long V_65 ;
T_2 V_83 ;
struct V_201 * * V_203 , * V_204 ;
if ( F_78 ( V_89 -> error ) ) {
F_145 ( V_3 , V_158 ) ;
F_146 ( V_158 ) ;
F_152 ( V_89 ) ;
return;
}
F_106 ( V_89 -> V_69 . V_120 . V_98 ) ;
V_158 -> V_119 . V_99 = V_3 -> V_100 + V_89 -> V_83 ;
if ( F_183 ( ! V_202 ) && F_76 ( V_205 , & V_3 -> V_65 ) ) {
F_159 ( V_158 ) ;
return;
}
F_184 ( & V_3 -> V_194 . V_195 , V_65 ) ;
V_203 = & V_3 -> V_189 . V_201 ;
V_204 = NULL ;
V_83 = V_89 -> V_83 ;
while ( * V_203 ) {
V_204 = * V_203 ;
if ( V_83 < F_178 ( V_204 ) -> V_83 )
V_203 = & ( * V_203 ) -> V_206 ;
else
V_203 = & ( * V_203 ) -> V_207 ;
}
F_185 ( & V_89 -> V_201 , V_204 , V_203 ) ;
F_186 ( & V_89 -> V_201 , & V_3 -> V_189 ) ;
F_187 ( & V_3 -> V_194 ) ;
F_188 ( & V_3 -> V_194 . V_195 , V_65 ) ;
}
static void F_189 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_158 ;
int V_208 ;
T_2 V_83 = V_89 -> V_83 ;
T_4 V_33 ;
F_151 ( V_89 ) ;
F_90 ( V_3 , & V_89 -> V_69 , NULL , V_89 -> V_149 , V_83 ) ;
V_158 = F_141 ( V_89 , V_89 -> V_149 -> V_119 . V_98 ) ;
if ( F_78 ( ! V_158 ) ) {
V_89 -> error = V_156 ;
goto V_209;
}
V_89 -> V_69 . V_117 = V_158 ;
V_89 -> V_69 . V_120 = V_158 -> V_119 ;
V_83 += F_80 ( V_158 ) ;
F_151 ( V_89 ) ;
V_33 = F_134 ( V_3 , & V_89 -> V_69 ) ;
if ( V_33 )
V_89 -> error = V_33 ;
V_208 = F_153 ( & V_89 -> V_69 . V_152 ) ;
if ( V_208 ) {
F_182 ( V_89 , 0 ) ;
V_89 -> V_83 = V_83 ;
}
V_209:
F_152 ( V_89 ) ;
}
static void F_190 ( struct V_88 * V_89 )
{
F_152 ( V_89 ) ;
}
static void F_191 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
T_4 V_33 ;
F_151 ( V_89 ) ;
F_90 ( V_3 , & V_89 -> V_69 , V_89 -> V_149 , V_89 -> V_149 ,
V_89 -> V_83 ) ;
V_33 = F_134 ( V_3 , & V_89 -> V_69 ) ;
if ( V_33 )
V_89 -> error = V_33 ;
if ( F_153 ( & V_89 -> V_69 . V_152 ) )
F_190 ( V_89 ) ;
F_152 ( V_89 ) ;
}
static void V_147 ( struct V_210 * V_211 ,
int error )
{
struct V_9 * V_10 = V_211 -> V_58 ;
struct V_116 * V_69 = V_10 -> V_69 ;
struct V_88 * V_89 = F_102 ( V_69 , struct V_88 , V_69 ) ;
struct V_2 * V_3 = V_89 -> V_3 ;
if ( error == - V_154 ) {
F_192 ( & V_69 -> V_123 ) ;
return;
}
if ( ! error && V_3 -> V_139 && V_3 -> V_139 -> V_142 )
error = V_3 -> V_139 -> V_142 ( V_3 , F_98 ( V_3 , V_10 ) , V_10 ) ;
if ( error == - V_141 ) {
F_114 ( L_27 ,
( unsigned long long ) F_115 ( * F_99 ( V_3 , V_10 ) ) ) ;
V_89 -> error = V_155 ;
} else if ( error < 0 )
V_89 -> error = V_156 ;
F_133 ( V_3 , F_93 ( V_3 , V_10 ) , V_89 -> V_149 ) ;
if ( ! F_153 ( & V_69 -> V_152 ) )
return;
if ( F_57 ( V_89 -> V_149 ) == V_179 )
F_190 ( V_89 ) ;
else
F_182 ( V_89 , 1 ) ;
}
static void F_193 ( struct V_184 * V_185 )
{
struct V_88 * V_89 = F_102 ( V_185 , struct V_88 , V_185 ) ;
if ( F_57 ( V_89 -> V_149 ) == V_179 )
F_191 ( V_89 ) ;
else
F_189 ( V_89 ) ;
}
static void F_156 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
F_162 ( & V_89 -> V_185 , F_193 ) ;
F_163 ( V_3 -> V_212 , & V_89 -> V_185 ) ;
}
static void F_194 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 . V_7 )
return;
if ( V_3 -> V_4 . V_7 [ 0 ] && ! F_22 ( V_3 -> V_4 . V_7 [ 0 ] ) ) {
F_195 ( V_3 -> V_4 . V_7 [ 0 ] ) ;
V_3 -> V_4 . V_7 [ 0 ] = NULL ;
}
F_33 ( V_3 -> V_4 . V_7 ) ;
V_3 -> V_4 . V_7 = NULL ;
}
static void F_196 ( struct V_2 * V_3 )
{
unsigned V_63 ;
if ( ! V_3 -> V_4 . V_5 )
return;
for ( V_63 = 0 ; V_63 < V_3 -> V_55 ; V_63 ++ )
if ( V_3 -> V_4 . V_5 [ V_63 ] && ! F_22 ( V_3 -> V_4 . V_5 [ V_63 ] ) ) {
F_197 ( V_3 -> V_4 . V_5 [ V_63 ] ) ;
V_3 -> V_4 . V_5 [ V_63 ] = NULL ;
}
F_33 ( V_3 -> V_4 . V_5 ) ;
V_3 -> V_4 . V_5 = NULL ;
}
static void F_198 ( struct V_2 * V_3 )
{
if ( F_75 ( V_3 ) )
F_194 ( V_3 ) ;
else
F_196 ( V_3 ) ;
}
static int F_199 ( struct V_2 * V_3 , char * V_213 )
{
unsigned V_63 ;
int V_26 ;
V_3 -> V_4 . V_5 = F_32 ( V_3 -> V_55 *
sizeof( struct V_1 * ) , V_43 ) ;
if ( ! V_3 -> V_4 . V_5 )
return - V_44 ;
for ( V_63 = 0 ; V_63 < V_3 -> V_55 ; V_63 ++ ) {
V_3 -> V_4 . V_5 [ V_63 ] = F_200 ( V_213 , 0 , 0 ) ;
if ( F_22 ( V_3 -> V_4 . V_5 [ V_63 ] ) ) {
V_26 = F_31 ( V_3 -> V_4 . V_5 [ V_63 ] ) ;
F_198 ( V_3 ) ;
return V_26 ;
}
}
return 0 ;
}
static int F_201 ( struct V_2 * V_3 , char * V_213 )
{
int V_26 ;
V_3 -> V_4 . V_5 = F_202 ( sizeof( struct V_6 * ) , V_43 ) ;
if ( ! V_3 -> V_4 . V_5 )
return - V_44 ;
V_3 -> V_4 . V_7 [ 0 ] = F_203 ( V_213 , 0 , 0 ) ;
if ( F_22 ( V_3 -> V_4 . V_7 [ 0 ] ) ) {
V_26 = F_31 ( V_3 -> V_4 . V_7 [ 0 ] ) ;
F_198 ( V_3 ) ;
return V_26 ;
}
return 0 ;
}
static int F_204 ( struct V_2 * V_3 , char * V_213 )
{
if ( F_75 ( V_3 ) )
return F_201 ( V_3 , V_213 ) ;
else
return F_199 ( V_3 , V_213 ) ;
}
static unsigned F_205 ( struct V_2 * V_3 )
{
return ( V_3 -> V_28 - V_3 -> V_214 ) >> F_38 ( V_3 -> V_55 ) ;
}
static unsigned F_206 ( struct V_2 * V_3 )
{
return F_205 ( V_3 ) + F_207 ( sizeof( struct V_215 ) ) ;
}
static void F_208 ( char * V_216 , const void * V_27 ,
unsigned V_217 , unsigned V_218 )
{
struct V_215 * V_219 ;
struct V_220 * V_221 ;
V_221 = (struct V_220 * ) V_216 ;
V_219 = F_209 ( V_221 ) ;
V_219 -> V_217 = F_210 ( V_217 ) ;
V_221 -> V_222 = F_211 ( sizeof( * V_219 ) ) ;
V_221 -> V_223 = V_224 ;
V_216 += F_207 ( sizeof( * V_219 ) ) ;
memcpy ( V_216 , V_27 + V_217 , V_218 ) ;
V_216 += V_218 ;
memcpy ( V_216 , V_27 , V_217 ) ;
}
static int F_212 ( struct V_2 * V_3 )
{
unsigned V_57 ;
int V_26 = 0 , V_63 , V_33 ;
V_57 = F_205 ( V_3 ) ;
if ( F_77 ( V_3 ) )
F_208 ( V_3 -> V_225 , V_3 -> V_27 ,
V_57 - V_3 -> V_87 ,
V_3 -> V_87 ) ;
for ( V_63 = 0 ; V_63 < V_3 -> V_55 ; V_63 ++ ) {
if ( F_77 ( V_3 ) )
V_33 = F_213 ( V_3 -> V_4 . V_7 [ V_63 ] ,
V_3 -> V_225 , F_206 ( V_3 ) ) ;
else if ( F_75 ( V_3 ) )
V_33 = F_213 ( V_3 -> V_4 . V_7 [ V_63 ] ,
V_3 -> V_27 + ( V_63 * V_57 ) ,
V_57 ) ;
else
V_33 = F_214 ( V_3 -> V_4 . V_5 [ V_63 ] ,
V_3 -> V_27 + ( V_63 * V_57 ) ,
V_57 ) ;
if ( V_33 )
V_26 = V_33 ;
}
if ( F_77 ( V_3 ) )
F_70 ( V_3 -> V_225 , F_206 ( V_3 ) ) ;
return V_26 ;
}
static bool F_215 ( const char * V_226 )
{
while ( * V_226 )
if ( isspace ( * V_226 ++ ) )
return true ;
return false ;
}
static int F_216 ( struct V_2 * V_3 , const char * V_227 )
{
char * V_228 , * V_229 ;
int V_94 ;
struct V_27 * V_27 ;
const struct V_230 * V_231 ;
if ( F_215 ( V_227 ) ) {
F_217 ( L_28 ) ;
return - V_39 ;
}
V_229 = strpbrk ( V_227 , L_29 ) ;
if ( ! V_229 || V_229 == V_227 || ! strlen ( V_229 + 1 ) )
return - V_39 ;
if ( strncmp ( V_227 , L_30 , V_229 - V_227 + 1 ) &&
strncmp ( V_227 , L_31 , V_229 - V_227 + 1 ) )
return - V_39 ;
V_228 = F_218 ( V_227 , V_43 ) ;
if ( ! V_228 )
return - V_44 ;
V_27 = F_219 ( V_227 [ 0 ] == 'l' ? & V_232 : & V_233 ,
V_229 + 1 , NULL ) ;
if ( F_22 ( V_27 ) ) {
F_28 ( V_228 ) ;
return F_31 ( V_27 ) ;
}
F_220 ( & V_27 -> V_234 ) ;
V_231 = F_221 ( V_27 ) ;
if ( ! V_231 ) {
F_222 ( & V_27 -> V_234 ) ;
F_223 ( V_27 ) ;
F_28 ( V_228 ) ;
return - V_235 ;
}
if ( V_3 -> V_28 != V_231 -> V_236 ) {
F_222 ( & V_27 -> V_234 ) ;
F_223 ( V_27 ) ;
F_28 ( V_228 ) ;
return - V_39 ;
}
memcpy ( V_3 -> V_27 , V_231 -> V_58 , V_3 -> V_28 ) ;
F_222 ( & V_27 -> V_234 ) ;
F_223 ( V_27 ) ;
F_224 ( V_237 , & V_3 -> V_65 ) ;
V_94 = F_212 ( V_3 ) ;
memset ( V_3 -> V_27 , 0 , V_3 -> V_28 * sizeof( T_1 ) ) ;
if ( ! V_94 ) {
F_225 ( V_237 , & V_3 -> V_65 ) ;
F_28 ( V_3 -> V_227 ) ;
V_3 -> V_227 = V_228 ;
} else
F_28 ( V_228 ) ;
return V_94 ;
}
static int F_226 ( char * * V_227 )
{
char * V_238 , V_239 ;
int V_94 ;
if ( * V_227 [ 0 ] != ':' )
return strlen ( * V_227 ) >> 1 ;
V_238 = strpbrk ( * V_227 + 1 , L_29 ) ;
if ( ! V_238 )
return - V_39 ;
if ( sscanf ( * V_227 + 1 , L_32 , & V_94 , & V_239 ) != 2 || V_239 != ':' )
return - V_39 ;
* V_227 = V_238 ;
return V_94 ;
}
static int F_216 ( struct V_2 * V_3 , const char * V_227 )
{
return - V_39 ;
}
static int F_226 ( char * * V_227 )
{
return ( * V_227 [ 0 ] == ':' ) ? - V_39 : strlen ( * V_227 ) >> 1 ;
}
static int F_227 ( struct V_2 * V_3 , char * V_27 )
{
int V_33 = - V_39 ;
int V_240 = strlen ( V_27 ) ;
if ( ! V_3 -> V_28 && strcmp ( V_27 , L_33 ) )
goto V_84;
if ( V_27 [ 0 ] == ':' ) {
V_33 = F_216 ( V_3 , V_27 + 1 ) ;
goto V_84;
}
F_224 ( V_237 , & V_3 -> V_65 ) ;
F_28 ( V_3 -> V_227 ) ;
V_3 -> V_227 = NULL ;
if ( V_3 -> V_28 && F_228 ( V_3 -> V_27 , V_27 , V_3 -> V_28 ) < 0 )
goto V_84;
V_33 = F_212 ( V_3 ) ;
if ( ! V_33 )
F_225 ( V_237 , & V_3 -> V_65 ) ;
V_84:
memset ( V_27 , '0' , V_240 ) ;
return V_33 ;
}
static int F_229 ( struct V_2 * V_3 )
{
int V_33 ;
F_224 ( V_237 , & V_3 -> V_65 ) ;
F_74 ( & V_3 -> V_27 , V_3 -> V_28 ) ;
F_28 ( V_3 -> V_227 ) ;
V_3 -> V_227 = NULL ;
V_33 = F_212 ( V_3 ) ;
memset ( & V_3 -> V_27 , 0 , V_3 -> V_28 * sizeof( T_1 ) ) ;
return V_33 ;
}
static void F_230 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
V_35 -> V_241 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_242 )
F_231 ( V_3 -> V_242 ) ;
if ( V_3 -> V_187 )
F_232 ( V_3 -> V_187 ) ;
if ( V_3 -> V_212 )
F_232 ( V_3 -> V_212 ) ;
F_198 ( V_3 ) ;
if ( V_3 -> V_45 )
F_233 ( V_3 -> V_45 ) ;
F_234 ( V_3 -> V_171 ) ;
F_234 ( V_3 -> V_145 ) ;
F_234 ( V_3 -> V_175 ) ;
if ( V_3 -> V_139 && V_3 -> V_139 -> V_243 )
V_3 -> V_139 -> V_243 ( V_3 ) ;
if ( V_3 -> V_106 )
F_235 ( V_35 , V_3 -> V_106 ) ;
F_28 ( V_3 -> V_37 ) ;
F_28 ( V_3 -> V_244 ) ;
F_28 ( V_3 -> V_227 ) ;
F_28 ( V_3 -> V_245 ) ;
F_28 ( V_3 -> V_225 ) ;
F_28 ( V_3 ) ;
}
static int F_236 ( struct V_34 * V_35 , const char * V_246 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
if ( F_75 ( V_3 ) )
V_3 -> V_11 = F_237 ( F_2 ( V_3 ) ) ;
else
V_3 -> V_11 = F_238 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_11 )
V_3 -> V_11 = F_239 ( V_3 -> V_11 ,
( unsigned int ) ( sizeof( V_16 ) / sizeof( T_1 ) ) ) ;
else if ( V_246 ) {
F_240 ( L_34 ) ;
V_246 = NULL ;
}
if ( V_246 == NULL )
V_3 -> V_139 = NULL ;
else if ( strcmp ( V_246 , L_35 ) == 0 )
V_3 -> V_139 = & V_247 ;
else if ( strcmp ( V_246 , L_36 ) == 0 )
V_3 -> V_139 = & V_248 ;
else if ( strcmp ( V_246 , L_37 ) == 0 )
V_3 -> V_139 = & V_249 ;
else if ( strcmp ( V_246 , L_38 ) == 0 )
V_3 -> V_139 = & V_250 ;
else if ( strcmp ( V_246 , L_39 ) == 0 )
V_3 -> V_139 = & V_251 ;
else if ( strcmp ( V_246 , L_40 ) == 0 )
V_3 -> V_139 = & V_252 ;
else if ( strcmp ( V_246 , L_41 ) == 0 ) {
V_3 -> V_139 = & V_253 ;
if ( V_3 -> V_28 % V_3 -> V_54 ) {
V_3 -> V_54 ++ ;
V_3 -> V_214 = V_3 -> V_28 / V_3 -> V_54 ;
}
} else if ( strcmp ( V_246 , L_42 ) == 0 ) {
V_3 -> V_139 = & V_254 ;
V_3 -> V_54 += 2 ;
V_3 -> V_214 = V_3 -> V_11 + V_81 ;
} else if ( strcmp ( V_246 , L_43 ) == 0 ) {
V_3 -> V_139 = & V_255 ;
V_3 -> V_115 = V_3 -> V_11 ;
} else {
V_35 -> error = L_44 ;
return - V_39 ;
}
return 0 ;
}
static int F_241 ( struct V_2 * V_3 )
{
const char * V_256 = NULL ;
char * V_100 , * V_257 ;
if ( F_75 ( V_3 ) ) {
V_256 = F_242 ( F_243 ( F_2 ( V_3 ) ) ) ;
if ( ! V_256 )
return - V_39 ;
if ( F_77 ( V_3 ) ) {
V_256 = strchr ( V_256 , ',' ) ;
if ( ! V_256 )
return - V_39 ;
}
V_256 ++ ;
} else {
V_256 = F_242 ( F_244 ( F_1 ( V_3 ) ) ) ;
if ( ! V_256 )
return - V_39 ;
}
V_100 = strchr ( V_256 , '(' ) ;
V_257 = strchr ( V_256 , ')' ) ;
if ( ! V_100 && ! V_257 ) {
V_3 -> V_37 = F_218 ( V_256 , V_43 ) ;
return V_3 -> V_37 ? 0 : - V_44 ;
}
if ( ! V_100 || ! V_257 || ++ V_100 >= V_257 )
return - V_39 ;
V_3 -> V_37 = F_32 ( V_257 - V_100 + 1 , V_43 ) ;
if ( ! V_3 -> V_37 )
return - V_44 ;
strncpy ( V_3 -> V_37 , V_100 , V_257 - V_100 ) ;
return 0 ;
}
static int F_245 ( struct V_2 * V_3 , char * V_258 )
{
char * V_100 , * V_257 , * V_259 = NULL ;
struct V_41 * V_260 ;
if ( ! F_246 ( V_258 , L_45 ) )
return 0 ;
V_100 = strchr ( V_258 , '(' ) ;
V_257 = strchr ( V_258 , ',' ) ;
if ( ! V_100 || ! V_257 || ++ V_100 > V_257 )
return - V_39 ;
V_259 = F_32 ( V_257 - V_100 + 1 , V_43 ) ;
if ( ! V_259 )
return - V_44 ;
strncpy ( V_259 , V_100 , V_257 - V_100 ) ;
V_260 = F_30 ( V_259 , 0 , 0 ) ;
F_33 ( V_259 ) ;
if ( F_22 ( V_260 ) )
return F_31 ( V_260 ) ;
V_3 -> V_87 = F_18 ( V_260 ) ;
F_27 ( V_260 ) ;
V_3 -> V_225 = F_202 ( F_206 ( V_3 ) , V_43 ) ;
if ( ! V_3 -> V_225 )
return - V_44 ;
return 0 ;
}
static int F_247 ( struct V_34 * V_35 , char * V_261 , char * V_27 ,
char * * V_246 , char * * V_262 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
char * V_263 , * V_258 ;
int V_94 = - V_39 ;
V_3 -> V_55 = 1 ;
V_263 = & V_261 [ strlen ( L_46 ) ] ;
V_258 = F_248 ( & V_263 , L_33 ) ;
* V_246 = F_248 ( & V_263 , L_29 ) ;
* V_262 = V_263 ;
if ( * V_246 && ! strcmp ( * V_246 , L_41 ) )
V_3 -> V_55 = 64 ;
V_3 -> V_54 = V_3 -> V_55 ;
V_94 = F_204 ( V_3 , V_258 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_47 ;
return V_94 ;
}
if ( F_75 ( V_3 ) ) {
V_94 = F_245 ( V_3 , V_258 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_48 ;
return - V_44 ;
}
V_3 -> V_11 = F_237 ( F_2 ( V_3 ) ) ;
} else
V_3 -> V_11 = F_238 ( F_1 ( V_3 ) ) ;
V_94 = F_241 ( V_3 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_49 ;
return - V_44 ;
}
return 0 ;
}
static int F_249 ( struct V_34 * V_35 , char * V_261 , char * V_27 ,
char * * V_246 , char * * V_262 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
char * V_263 , * V_37 , * V_264 , * V_265 ;
char * V_258 = NULL ;
int V_94 = - V_39 ;
char V_239 ;
if ( strchr ( V_261 , '(' ) || F_75 ( V_3 ) ) {
V_35 -> error = L_50 ;
return - V_39 ;
}
V_263 = V_261 ;
V_265 = F_248 ( & V_263 , L_33 ) ;
V_37 = F_248 ( & V_265 , L_29 ) ;
if ( ! V_265 )
V_3 -> V_55 = 1 ;
else if ( sscanf ( V_265 , L_32 , & V_3 -> V_55 , & V_239 ) != 1 ||
! F_250 ( V_3 -> V_55 ) ) {
V_35 -> error = L_51 ;
return - V_39 ;
}
V_3 -> V_54 = V_3 -> V_55 ;
V_3 -> V_37 = F_218 ( V_37 , V_43 ) ;
if ( ! V_3 -> V_37 )
goto V_266;
V_264 = F_248 ( & V_263 , L_33 ) ;
* V_262 = F_248 ( & V_263 , L_33 ) ;
* V_246 = F_248 ( & * V_262 , L_29 ) ;
if ( V_263 )
F_240 ( L_52 ) ;
if ( ! V_264 || ( ! strcmp ( V_264 , L_35 ) && ! * V_246 ) ) {
V_264 = L_53 ;
* V_246 = L_35 ;
}
if ( strcmp ( V_264 , L_54 ) && ! * V_246 ) {
V_35 -> error = L_55 ;
return - V_39 ;
}
V_258 = F_202 ( V_267 , V_43 ) ;
if ( ! V_258 )
goto V_266;
V_94 = snprintf ( V_258 , V_267 ,
L_56 , V_264 , V_37 ) ;
if ( V_94 < 0 ) {
F_33 ( V_258 ) ;
goto V_266;
}
V_94 = F_204 ( V_3 , V_258 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_47 ;
F_33 ( V_258 ) ;
return V_94 ;
}
return 0 ;
V_266:
V_35 -> error = L_57 ;
return - V_44 ;
}
static int F_251 ( struct V_34 * V_35 , char * V_261 , char * V_27 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
char * V_246 = NULL , * V_262 = NULL ;
int V_94 ;
V_3 -> V_244 = F_218 ( V_261 , V_43 ) ;
if ( ! V_3 -> V_244 ) {
V_35 -> error = L_57 ;
return - V_44 ;
}
if ( F_246 ( V_261 , L_46 ) )
V_94 = F_247 ( V_35 , V_261 , V_27 , & V_246 , & V_262 ) ;
else
V_94 = F_249 ( V_35 , V_261 , V_27 , & V_246 , & V_262 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_236 ( V_35 , V_246 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_227 ( V_3 , V_27 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_58 ;
return V_94 ;
}
if ( V_3 -> V_139 && V_3 -> V_139 -> V_268 ) {
V_94 = V_3 -> V_139 -> V_268 ( V_3 , V_35 , V_262 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_59 ;
return V_94 ;
}
}
if ( V_3 -> V_139 && V_3 -> V_139 -> V_269 ) {
V_94 = V_3 -> V_139 -> V_269 ( V_3 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_60 ;
return V_94 ;
}
}
return V_94 ;
}
static int F_252 ( struct V_34 * V_35 , unsigned int V_270 , char * * V_271 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
struct V_272 V_273 ;
static struct V_274 V_275 [] = {
{ 0 , 6 , L_61 } ,
} ;
unsigned int V_276 , V_48 ;
const char * V_277 , * V_278 ;
char V_239 ;
int V_94 ;
V_273 . V_270 = V_270 ;
V_273 . V_271 = V_271 ;
V_94 = F_253 ( V_275 , & V_273 , & V_276 , & V_35 -> error ) ;
if ( V_94 )
return V_94 ;
while ( V_276 -- ) {
V_277 = F_254 ( & V_273 ) ;
if ( ! V_277 ) {
V_35 -> error = L_62 ;
return - V_39 ;
}
if ( ! strcasecmp ( V_277 , L_63 ) )
V_35 -> V_279 = 1 ;
else if ( ! strcasecmp ( V_277 , L_64 ) )
F_225 ( V_280 , & V_3 -> V_65 ) ;
else if ( ! strcasecmp ( V_277 , L_65 ) )
F_225 ( V_205 , & V_3 -> V_65 ) ;
else if ( sscanf ( V_277 , L_66 , & V_48 ) == 1 ) {
if ( V_48 == 0 || V_48 > V_281 ) {
V_35 -> error = L_67 ;
return - V_39 ;
}
V_3 -> V_95 = V_48 ;
V_278 = strchr ( V_277 + strlen ( L_68 ) , ':' ) + 1 ;
if ( ! strcasecmp ( V_278 , L_69 ) ) {
F_225 ( V_85 , & V_3 -> V_86 ) ;
} else if ( strcasecmp ( V_278 , L_70 ) ) {
V_35 -> error = L_71 ;
return - V_39 ;
}
V_3 -> V_245 = F_218 ( V_278 , V_43 ) ;
if ( ! V_3 -> V_245 )
return - V_44 ;
} else if ( sscanf ( V_277 , L_72 , & V_3 -> V_52 , & V_239 ) == 1 ) {
if ( V_3 -> V_52 < ( 1 << V_53 ) ||
V_3 -> V_52 > 4096 ||
( V_3 -> V_52 & ( V_3 -> V_52 - 1 ) ) ) {
V_35 -> error = L_73 ;
return - V_39 ;
}
V_3 -> V_137 = F_255 ( V_3 -> V_52 ) - V_53 ;
} else if ( ! strcasecmp ( V_277 , L_74 ) )
F_225 ( V_136 , & V_3 -> V_86 ) ;
else {
V_35 -> error = L_75 ;
return - V_39 ;
}
}
return 0 ;
}
static int F_256 ( struct V_34 * V_35 , unsigned int V_270 , char * * V_271 )
{
struct V_2 * V_3 ;
int V_28 ;
unsigned int V_282 ;
unsigned long long V_283 ;
int V_94 ;
T_6 V_284 , V_285 ;
char V_239 ;
if ( V_270 < 5 ) {
V_35 -> error = L_76 ;
return - V_39 ;
}
V_28 = F_226 ( & V_271 [ 1 ] ) ;
if ( V_28 < 0 ) {
V_35 -> error = L_77 ;
return - V_39 ;
}
V_3 = F_32 ( sizeof( * V_3 ) + V_28 * sizeof( T_1 ) , V_43 ) ;
if ( ! V_3 ) {
V_35 -> error = L_78 ;
return - V_44 ;
}
V_3 -> V_28 = V_28 ;
V_3 -> V_52 = ( 1 << V_53 ) ;
V_3 -> V_137 = 0 ;
V_35 -> V_241 = V_3 ;
if ( V_270 > 5 ) {
V_94 = F_252 ( V_35 , V_270 - 5 , & V_271 [ 5 ] ) ;
if ( V_94 )
goto V_42;
}
V_94 = F_251 ( V_35 , V_271 [ 0 ] , V_271 [ 1 ] ) ;
if ( V_94 < 0 )
goto V_42;
if ( F_75 ( V_3 ) ) {
V_3 -> V_124 = sizeof( struct V_126 ) ;
V_3 -> V_124 += F_257 ( F_2 ( V_3 ) ) ;
V_282 = F_96 ( F_2 ( V_3 ) ) ;
} else {
V_3 -> V_124 = sizeof( struct V_143 ) ;
V_3 -> V_124 += F_258 ( F_1 ( V_3 ) ) ;
V_282 = F_97 ( F_1 ( V_3 ) ) ;
}
V_3 -> V_124 = F_95 ( V_3 -> V_124 , F_259 ( struct V_9 ) ) ;
if ( V_282 < V_286 ) {
V_284 = - ( V_3 -> V_124 + sizeof( struct V_9 ) )
& V_282 ;
} else {
V_284 = V_282 ;
}
V_94 = - V_44 ;
V_285 = sizeof( struct V_9 ) +
V_284 + V_3 -> V_11 +
V_3 -> V_11 +
sizeof( T_3 ) +
sizeof( unsigned int ) ;
V_3 -> V_145 = F_260 ( V_287 , V_3 -> V_124 + V_285 ) ;
if ( ! V_3 -> V_145 ) {
V_35 -> error = L_79 ;
goto V_42;
}
V_3 -> V_150 = V_35 -> V_288 =
F_95 ( sizeof( struct V_88 ) + V_3 -> V_124 + V_285 ,
V_289 ) ;
V_3 -> V_171 = F_261 ( V_290 , 0 ) ;
if ( ! V_3 -> V_171 ) {
V_35 -> error = L_80 ;
goto V_42;
}
V_3 -> V_45 = F_262 ( V_287 , 0 , ( V_291 |
V_292 ) ) ;
if ( ! V_3 -> V_45 ) {
V_35 -> error = L_81 ;
goto V_42;
}
F_263 ( & V_3 -> V_170 ) ;
V_94 = - V_39 ;
if ( ( sscanf ( V_271 [ 2 ] , L_82 , & V_283 , & V_239 ) != 1 ) ||
( V_283 & ( ( V_3 -> V_52 >> V_53 ) - 1 ) ) ) {
V_35 -> error = L_83 ;
goto V_42;
}
V_3 -> V_122 = V_283 ;
V_94 = F_264 ( V_35 , V_271 [ 3 ] , F_265 ( V_35 -> V_293 ) , & V_3 -> V_106 ) ;
if ( V_94 ) {
V_35 -> error = L_84 ;
goto V_42;
}
V_94 = - V_39 ;
if ( sscanf ( V_271 [ 4 ] , L_82 , & V_283 , & V_239 ) != 1 ) {
V_35 -> error = L_85 ;
goto V_42;
}
V_3 -> V_100 = V_283 ;
if ( F_75 ( V_3 ) || V_3 -> V_115 ) {
V_94 = F_85 ( V_3 , V_35 ) ;
if ( V_94 )
goto V_42;
V_3 -> V_294 = V_295 / V_3 -> V_95 ;
if ( ! V_3 -> V_294 )
V_3 -> V_294 = 1 ;
V_3 -> V_175 = F_260 ( V_287 ,
V_3 -> V_294 * V_3 -> V_95 ) ;
if ( ! V_3 -> V_175 ) {
V_35 -> error = L_86 ;
goto V_42;
}
V_3 -> V_294 <<= V_3 -> V_137 ;
}
V_94 = - V_44 ;
V_3 -> V_187 = F_266 ( L_87 , V_296 | V_297 | V_298 , 1 ) ;
if ( ! V_3 -> V_187 ) {
V_35 -> error = L_88 ;
goto V_42;
}
if ( F_76 ( V_280 , & V_3 -> V_65 ) )
V_3 -> V_212 = F_266 ( L_89 , V_296 | V_297 | V_298 , 1 ) ;
else
V_3 -> V_212 = F_266 ( L_89 ,
V_296 | V_297 | V_298 | V_299 ,
F_267 () ) ;
if ( ! V_3 -> V_212 ) {
V_35 -> error = L_90 ;
goto V_42;
}
F_268 ( & V_3 -> V_194 ) ;
V_3 -> V_189 = V_200 ;
V_3 -> V_242 = F_269 ( F_165 , V_3 , L_91 ) ;
if ( F_22 ( V_3 -> V_242 ) ) {
V_94 = F_31 ( V_3 -> V_242 ) ;
V_3 -> V_242 = NULL ;
V_35 -> error = L_92 ;
goto V_42;
}
F_270 ( V_3 -> V_242 ) ;
V_35 -> V_300 = 1 ;
return 0 ;
V_42:
F_230 ( V_35 ) ;
return V_94 ;
}
static int F_271 ( struct V_34 * V_35 , struct V_90 * V_90 )
{
struct V_88 * V_89 ;
struct V_2 * V_3 = V_35 -> V_241 ;
if ( F_78 ( V_90 -> V_182 & V_301 ||
F_272 ( V_90 ) == V_302 ) ) {
V_90 -> V_181 = V_3 -> V_106 -> V_107 ;
if ( F_80 ( V_90 ) )
V_90 -> V_119 . V_99 = V_3 -> V_100 +
F_273 ( V_35 , V_90 -> V_119 . V_99 ) ;
return V_303 ;
}
if ( F_78 ( V_90 -> V_119 . V_98 > ( V_290 << V_161 ) ) &&
( F_57 ( V_90 ) == V_71 || V_3 -> V_95 ) )
F_274 ( V_90 , ( ( V_290 << V_161 ) >> V_53 ) ) ;
if ( F_78 ( ( V_90 -> V_119 . V_99 & ( ( V_3 -> V_52 >> V_53 ) - 1 ) ) != 0 ) )
return V_304 ;
if ( F_78 ( V_90 -> V_119 . V_98 & ( V_3 -> V_52 - 1 ) ) )
return V_304 ;
V_89 = F_130 ( V_90 , V_3 -> V_150 ) ;
F_150 ( V_89 , V_3 , V_90 , F_273 ( V_35 , V_90 -> V_119 . V_99 ) ) ;
if ( V_3 -> V_95 ) {
unsigned V_93 = V_3 -> V_95 * ( F_80 ( V_90 ) >> V_3 -> V_137 ) ;
if ( F_78 ( V_93 > V_305 ) ||
F_78 ( ! ( V_89 -> V_103 = F_202 ( V_93 ,
V_96 | V_306 | V_307 | V_308 ) ) ) ) {
if ( F_80 ( V_90 ) > V_3 -> V_294 )
F_274 ( V_90 , V_3 -> V_294 ) ;
V_89 -> V_103 = F_122 ( V_3 -> V_175 , V_96 ) ;
V_89 -> V_173 = true ;
}
}
if ( F_75 ( V_3 ) )
V_89 -> V_69 . V_33 . V_148 = (struct V_126 * ) ( V_89 + 1 ) ;
else
V_89 -> V_69 . V_33 . V_20 = (struct V_143 * ) ( V_89 + 1 ) ;
if ( F_57 ( V_89 -> V_149 ) == V_179 ) {
if ( F_157 ( V_89 , V_163 ) )
F_161 ( V_89 ) ;
} else
F_156 ( V_89 ) ;
return V_309 ;
}
static void F_275 ( struct V_34 * V_35 , T_7 type ,
unsigned V_310 , char * V_311 , unsigned V_312 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
unsigned V_63 , V_313 = 0 ;
int V_314 = 0 ;
switch ( type ) {
case V_315 :
V_311 [ 0 ] = '\0' ;
break;
case V_316 :
F_276 ( L_93 , V_3 -> V_244 ) ;
if ( V_3 -> V_28 > 0 ) {
if ( V_3 -> V_227 )
F_276 ( L_94 , V_3 -> V_28 , V_3 -> V_227 ) ;
else
for ( V_63 = 0 ; V_63 < V_3 -> V_28 ; V_63 ++ )
F_276 ( L_95 , V_3 -> V_27 [ V_63 ] ) ;
} else
F_276 ( L_33 ) ;
F_276 ( L_96 , ( unsigned long long ) V_3 -> V_122 ,
V_3 -> V_106 -> V_110 , ( unsigned long long ) V_3 -> V_100 ) ;
V_314 += ! ! V_35 -> V_279 ;
V_314 += F_76 ( V_280 , & V_3 -> V_65 ) ;
V_314 += F_76 ( V_205 , & V_3 -> V_65 ) ;
V_314 += V_3 -> V_52 != ( 1 << V_53 ) ;
V_314 += F_76 ( V_136 , & V_3 -> V_86 ) ;
if ( V_3 -> V_95 )
V_314 ++ ;
if ( V_314 ) {
F_276 ( L_97 , V_314 ) ;
if ( V_35 -> V_279 )
F_276 ( L_98 ) ;
if ( F_76 ( V_280 , & V_3 -> V_65 ) )
F_276 ( L_99 ) ;
if ( F_76 ( V_205 , & V_3 -> V_65 ) )
F_276 ( L_100 ) ;
if ( V_3 -> V_95 )
F_276 ( L_101 , V_3 -> V_95 , V_3 -> V_245 ) ;
if ( V_3 -> V_52 != ( 1 << V_53 ) )
F_276 ( L_102 , V_3 -> V_52 ) ;
if ( F_76 ( V_136 , & V_3 -> V_86 ) )
F_276 ( L_103 ) ;
}
break;
}
}
static void F_277 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
F_225 ( V_317 , & V_3 -> V_65 ) ;
}
static int F_278 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
if ( ! F_76 ( V_237 , & V_3 -> V_65 ) ) {
F_217 ( L_104 ) ;
return - V_318 ;
}
return 0 ;
}
static void F_279 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
F_224 ( V_317 , & V_3 -> V_65 ) ;
}
static int F_280 ( struct V_34 * V_35 , unsigned V_270 , char * * V_271 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
int V_28 , V_94 = - V_39 ;
if ( V_270 < 2 )
goto error;
if ( ! strcasecmp ( V_271 [ 0 ] , L_105 ) ) {
if ( ! F_76 ( V_317 , & V_3 -> V_65 ) ) {
F_240 ( L_106 ) ;
return - V_39 ;
}
if ( V_270 == 3 && ! strcasecmp ( V_271 [ 1 ] , L_107 ) ) {
V_28 = F_226 ( & V_271 [ 2 ] ) ;
if ( V_28 < 0 || V_3 -> V_28 != V_28 ) {
memset ( V_271 [ 2 ] , '0' , strlen ( V_271 [ 2 ] ) ) ;
return - V_39 ;
}
V_94 = F_227 ( V_3 , V_271 [ 2 ] ) ;
if ( V_94 )
return V_94 ;
if ( V_3 -> V_139 && V_3 -> V_139 -> V_269 )
V_94 = V_3 -> V_139 -> V_269 ( V_3 ) ;
return V_94 ;
}
if ( V_270 == 2 && ! strcasecmp ( V_271 [ 1 ] , L_108 ) ) {
if ( V_3 -> V_139 && V_3 -> V_139 -> V_319 ) {
V_94 = V_3 -> V_139 -> V_319 ( V_3 ) ;
if ( V_94 )
return V_94 ;
}
return F_229 ( V_3 ) ;
}
}
error:
F_240 ( L_109 ) ;
return - V_39 ;
}
static int F_281 ( struct V_34 * V_35 ,
T_8 V_320 , void * V_58 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
return V_320 ( V_35 , V_3 -> V_106 , V_3 -> V_100 , V_35 -> V_165 , V_58 ) ;
}
static void F_282 ( struct V_34 * V_35 , struct V_321 * V_322 )
{
struct V_2 * V_3 = V_35 -> V_241 ;
V_322 -> V_323 = V_160 ;
if ( V_3 -> V_52 != ( 1 << V_53 ) ) {
V_322 -> V_324 = V_3 -> V_52 ;
V_322 -> V_325 = V_3 -> V_52 ;
F_283 ( V_322 , V_3 -> V_52 ) ;
}
}
static int T_9 F_284 ( void )
{
int V_33 ;
V_33 = F_285 ( & V_326 ) ;
if ( V_33 < 0 )
F_217 ( L_110 , V_33 ) ;
return V_33 ;
}
static void T_10 F_286 ( void )
{
F_287 ( & V_326 ) ;
}
