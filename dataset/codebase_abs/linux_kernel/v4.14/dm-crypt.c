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
F_69 ( V_62 , V_77 -> V_79 , ( T_1 * ) & V_83 , 8 ) ;
F_69 ( & V_62 [ 8 ] , V_77 -> V_79 + 8 , ( T_1 * ) & V_83 , 8 ) ;
V_59 -> V_64 = V_77 -> V_80 ;
V_59 -> V_65 = V_29 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
V_33 = F_52 ( V_59 ) ;
if ( V_33 )
goto V_84;
V_33 = F_53 ( V_59 , & V_62 [ V_63 * 4 ] , 4 ) ;
if ( V_33 )
goto V_84;
V_33 = F_70 ( V_59 , & V_62 [ V_63 * 4 ] ) ;
if ( V_33 )
goto V_84;
}
F_63 ( & V_62 [ 0 ] , & V_62 [ 12 ] , 4 ) ;
F_63 ( & V_62 [ 4 ] , & V_62 [ 8 ] , 4 ) ;
for ( V_63 = 0 ; V_63 < ( ( 1 << V_53 ) / 8 ) ; V_63 ++ )
F_63 ( V_58 + V_63 * 8 , V_62 , 8 ) ;
V_84:
F_71 ( V_62 , sizeof( V_62 ) ) ;
return V_33 ;
}
static int F_72 ( struct V_2 * V_3 , T_1 * V_8 ,
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
F_69 ( V_8 , V_77 -> V_78 , ( T_1 * ) & V_83 , 8 ) ;
if ( V_3 -> V_11 > 8 )
F_69 ( & V_8 [ 8 ] , V_77 -> V_78 + 8 , ( T_1 * ) & V_83 ,
V_3 -> V_11 - 8 ) ;
return V_33 ;
}
static int F_73 ( struct V_2 * V_3 , T_1 * V_8 ,
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
static int F_74 ( struct V_2 * V_3 , T_1 * V_8 ,
struct V_9 * V_10 )
{
F_75 ( V_8 , V_3 -> V_11 ) ;
return 0 ;
}
static bool F_76 ( struct V_2 * V_3 )
{
return F_77 ( V_85 , & V_3 -> V_86 ) ;
}
static bool F_78 ( struct V_2 * V_3 )
{
return F_76 ( V_3 ) && V_3 -> V_87 ;
}
static struct V_22 * F_58 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
if ( F_79 ( F_76 ( V_3 ) ) )
return & V_23 [ 2 ] ;
return V_23 ;
}
static int F_80 ( struct V_88 * V_89 , struct V_90 * V_90 )
{
struct V_91 * V_92 ;
unsigned int V_93 ;
int V_94 ;
if ( ! F_81 ( V_90 ) || ! V_89 -> V_3 -> V_95 )
return 0 ;
V_92 = F_82 ( V_90 , V_96 , 1 ) ;
if ( F_22 ( V_92 ) )
return F_31 ( V_92 ) ;
V_93 = V_89 -> V_3 -> V_95 * F_81 ( V_90 ) ;
V_92 -> V_97 . V_98 = V_93 ;
V_92 -> V_97 . V_99 = V_89 -> V_3 -> V_100 + V_89 -> V_83 ;
V_94 = F_83 ( V_90 , F_84 ( V_89 -> V_101 ) ,
V_93 , F_85 ( V_89 -> V_101 ) ) ;
if ( F_79 ( V_94 != V_93 ) )
return - V_44 ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 , struct V_34 * V_35 )
{
#ifdef F_87
struct V_102 * V_103 = F_88 ( V_3 -> V_104 -> V_105 -> V_106 ) ;
if ( ! V_103 || strcasecmp ( V_103 -> V_107 -> V_108 , L_19 ) ) {
V_35 -> error = L_20 ;
return - V_39 ;
}
if ( V_103 -> V_109 != V_3 -> V_95 ||
V_103 -> V_110 != V_3 -> V_95 ) {
V_35 -> error = L_21 ;
return - V_39 ;
}
if ( 1 << V_103 -> V_111 != V_3 -> V_52 ) {
V_35 -> error = L_22 ;
return - V_39 ;
}
if ( F_76 ( V_3 ) ) {
V_3 -> V_112 = V_3 -> V_95 - V_3 -> V_113 ;
F_89 ( L_23 ,
V_3 -> V_112 , V_3 -> V_113 ) ;
if ( F_90 ( F_2 ( V_3 ) , V_3 -> V_112 ) ) {
V_35 -> error = L_24 ;
return - V_39 ;
}
} else if ( V_3 -> V_113 )
F_89 ( L_25 ,
V_3 -> V_113 ) ;
if ( ( V_3 -> V_112 + V_3 -> V_113 ) != V_103 -> V_109 ) {
V_35 -> error = L_26 ;
return - V_39 ;
}
return 0 ;
#else
V_35 -> error = L_20 ;
return - V_39 ;
#endif
}
static void F_91 ( struct V_2 * V_3 ,
struct V_114 * V_69 ,
struct V_90 * V_115 , struct V_90 * V_70 ,
T_2 V_83 )
{
V_69 -> V_70 = V_70 ;
V_69 -> V_115 = V_115 ;
if ( V_70 )
V_69 -> V_116 = V_70 -> V_117 ;
if ( V_115 )
V_69 -> V_118 = V_115 -> V_117 ;
V_69 -> V_119 = V_83 + V_3 -> V_120 ;
F_92 ( & V_69 -> V_121 ) ;
}
static struct V_9 * F_93 ( struct V_2 * V_3 ,
void * V_20 )
{
return (struct V_9 * ) ( ( char * ) V_20 + V_3 -> V_122 ) ;
}
static void * F_94 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
return ( void * ) ( ( char * ) V_10 - V_3 -> V_122 ) ;
}
static T_1 * F_95 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( F_76 ( V_3 ) )
return ( T_1 * ) F_96 ( ( unsigned long ) ( V_10 + 1 ) ,
F_97 ( F_2 ( V_3 ) ) + 1 ) ;
else
return ( T_1 * ) F_96 ( ( unsigned long ) ( V_10 + 1 ) ,
F_98 ( F_1 ( V_3 ) ) + 1 ) ;
}
static T_1 * F_99 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
return F_95 ( V_3 , V_10 ) + V_3 -> V_11 ;
}
static T_3 * F_100 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
T_1 * V_123 = F_95 ( V_3 , V_10 ) + V_3 -> V_11 + V_3 -> V_11 ;
return ( T_3 * ) V_123 ;
}
static unsigned int * F_101 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
T_1 * V_123 = F_95 ( V_3 , V_10 ) + V_3 -> V_11 +
V_3 -> V_11 + sizeof( T_3 ) ;
return ( unsigned int * ) V_123 ;
}
static void * F_102 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_114 * V_69 = V_10 -> V_69 ;
struct V_88 * V_89 = F_103 ( V_69 , struct V_88 , V_69 ) ;
return & V_89 -> V_101 [ * F_101 ( V_3 , V_10 ) *
V_3 -> V_95 ] ;
}
static void * F_104 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
return F_102 ( V_3 , V_10 ) + V_3 -> V_112 ;
}
static int F_105 ( struct V_2 * V_3 ,
struct V_114 * V_69 ,
struct V_124 * V_20 ,
unsigned int V_125 )
{
struct V_126 V_127 = F_106 ( V_69 -> V_70 , V_69 -> V_116 ) ;
struct V_126 V_128 = F_106 ( V_69 -> V_115 , V_69 -> V_118 ) ;
struct V_9 * V_10 ;
T_1 * V_8 , * V_129 , * V_130 , * V_131 ;
T_3 * V_83 ;
int V_33 = 0 ;
F_107 ( V_3 -> V_113 && V_3 -> V_113 != V_3 -> V_11 ) ;
if ( F_79 ( V_127 . V_132 & ( V_3 -> V_52 - 1 ) ) )
return - V_133 ;
V_10 = F_93 ( V_3 , V_20 ) ;
V_10 -> V_13 = V_69 -> V_119 ;
if ( F_77 ( V_134 , & V_3 -> V_86 ) )
V_10 -> V_13 >>= V_3 -> V_135 ;
V_10 -> V_69 = V_69 ;
* F_101 ( V_3 , V_10 ) = V_125 ;
V_83 = F_100 ( V_3 , V_10 ) ;
* V_83 = F_6 ( V_69 -> V_119 - V_3 -> V_120 ) ;
V_8 = F_95 ( V_3 , V_10 ) ;
V_129 = F_99 ( V_3 , V_10 ) ;
V_131 = F_102 ( V_3 , V_10 ) ;
V_130 = F_104 ( V_3 , V_10 ) ;
F_108 ( V_10 -> V_72 , 4 ) ;
F_109 ( & V_10 -> V_72 [ 0 ] , V_83 , sizeof( T_3 ) ) ;
F_109 ( & V_10 -> V_72 [ 1 ] , V_129 , V_3 -> V_11 ) ;
F_110 ( & V_10 -> V_72 [ 2 ] , V_127 . V_136 , V_3 -> V_52 , V_127 . V_132 ) ;
F_109 ( & V_10 -> V_72 [ 3 ] , V_131 , V_3 -> V_112 ) ;
F_108 ( V_10 -> V_75 , 4 ) ;
F_109 ( & V_10 -> V_75 [ 0 ] , V_83 , sizeof( T_3 ) ) ;
F_109 ( & V_10 -> V_75 [ 1 ] , V_129 , V_3 -> V_11 ) ;
F_110 ( & V_10 -> V_75 [ 2 ] , V_128 . V_136 , V_3 -> V_52 , V_128 . V_132 ) ;
F_109 ( & V_10 -> V_75 [ 3 ] , V_131 , V_3 -> V_112 ) ;
if ( V_3 -> V_137 ) {
if ( V_3 -> V_113 && F_57 ( V_69 -> V_70 ) != V_71 ) {
memcpy ( V_129 , V_130 , V_3 -> V_11 ) ;
} else {
V_33 = V_3 -> V_137 -> V_138 ( V_3 , V_129 , V_10 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_3 -> V_113 )
memcpy ( V_130 , V_129 , V_3 -> V_11 ) ;
}
memcpy ( V_8 , V_129 , V_3 -> V_11 ) ;
}
F_111 ( V_20 , sizeof( T_3 ) + V_3 -> V_11 ) ;
if ( F_57 ( V_69 -> V_70 ) == V_71 ) {
F_112 ( V_20 , V_10 -> V_72 , V_10 -> V_75 ,
V_3 -> V_52 , V_8 ) ;
V_33 = F_113 ( V_20 ) ;
if ( V_3 -> V_112 + V_3 -> V_113 != V_3 -> V_95 )
memset ( V_131 + V_3 -> V_112 + V_3 -> V_113 , 0 ,
V_3 -> V_95 - ( V_3 -> V_112 + V_3 -> V_113 ) ) ;
} else {
F_112 ( V_20 , V_10 -> V_72 , V_10 -> V_75 ,
V_3 -> V_52 + V_3 -> V_112 , V_8 ) ;
V_33 = F_114 ( V_20 ) ;
}
if ( V_33 == - V_139 )
F_115 ( L_27 ,
( unsigned long long ) F_116 ( * V_83 ) ) ;
if ( ! V_33 && V_3 -> V_137 && V_3 -> V_137 -> V_140 )
V_33 = V_3 -> V_137 -> V_140 ( V_3 , V_129 , V_10 ) ;
F_117 ( V_69 -> V_70 , & V_69 -> V_116 , V_3 -> V_52 ) ;
F_117 ( V_69 -> V_115 , & V_69 -> V_118 , V_3 -> V_52 ) ;
return V_33 ;
}
static int F_118 ( struct V_2 * V_3 ,
struct V_114 * V_69 ,
struct V_141 * V_20 ,
unsigned int V_125 )
{
struct V_126 V_127 = F_106 ( V_69 -> V_70 , V_69 -> V_116 ) ;
struct V_126 V_128 = F_106 ( V_69 -> V_115 , V_69 -> V_118 ) ;
struct V_22 * V_72 , * V_75 ;
struct V_9 * V_10 ;
T_1 * V_8 , * V_129 , * V_130 ;
T_3 * V_83 ;
int V_33 = 0 ;
if ( F_79 ( V_127 . V_132 & ( V_3 -> V_52 - 1 ) ) )
return - V_133 ;
V_10 = F_93 ( V_3 , V_20 ) ;
V_10 -> V_13 = V_69 -> V_119 ;
if ( F_77 ( V_134 , & V_3 -> V_86 ) )
V_10 -> V_13 >>= V_3 -> V_135 ;
V_10 -> V_69 = V_69 ;
* F_101 ( V_3 , V_10 ) = V_125 ;
V_8 = F_95 ( V_3 , V_10 ) ;
V_129 = F_99 ( V_3 , V_10 ) ;
V_130 = F_104 ( V_3 , V_10 ) ;
V_83 = F_100 ( V_3 , V_10 ) ;
* V_83 = F_6 ( V_69 -> V_119 - V_3 -> V_120 ) ;
V_72 = & V_10 -> V_72 [ 0 ] ;
V_75 = & V_10 -> V_75 [ 0 ] ;
F_108 ( V_72 , 1 ) ;
F_110 ( V_72 , V_127 . V_136 , V_3 -> V_52 , V_127 . V_132 ) ;
F_108 ( V_75 , 1 ) ;
F_110 ( V_75 , V_128 . V_136 , V_3 -> V_52 , V_128 . V_132 ) ;
if ( V_3 -> V_137 ) {
if ( V_3 -> V_113 && F_57 ( V_69 -> V_70 ) != V_71 ) {
memcpy ( V_129 , V_130 , V_3 -> V_113 ) ;
} else {
V_33 = V_3 -> V_137 -> V_138 ( V_3 , V_129 , V_10 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_3 -> V_113 )
memcpy ( V_130 , V_129 , V_3 -> V_113 ) ;
}
memcpy ( V_8 , V_129 , V_3 -> V_11 ) ;
}
F_119 ( V_20 , V_72 , V_75 , V_3 -> V_52 , V_8 ) ;
if ( F_57 ( V_69 -> V_70 ) == V_71 )
V_33 = F_120 ( V_20 ) ;
else
V_33 = F_121 ( V_20 ) ;
if ( ! V_33 && V_3 -> V_137 && V_3 -> V_137 -> V_140 )
V_33 = V_3 -> V_137 -> V_140 ( V_3 , V_129 , V_10 ) ;
F_117 ( V_69 -> V_70 , & V_69 -> V_116 , V_3 -> V_52 ) ;
F_117 ( V_69 -> V_115 , & V_69 -> V_118 , V_3 -> V_52 ) ;
return V_33 ;
}
static void F_122 ( struct V_2 * V_3 ,
struct V_114 * V_69 )
{
unsigned V_142 = V_69 -> V_119 & ( V_3 -> V_55 - 1 ) ;
if ( ! V_69 -> V_33 . V_20 )
V_69 -> V_33 . V_20 = F_123 ( V_3 -> V_143 , V_96 ) ;
F_124 ( V_69 -> V_33 . V_20 , V_3 -> V_4 . V_5 [ V_142 ] ) ;
F_125 ( V_69 -> V_33 . V_20 ,
V_144 | V_29 ,
V_145 , F_93 ( V_3 , V_69 -> V_33 . V_20 ) ) ;
}
static void F_126 ( struct V_2 * V_3 ,
struct V_114 * V_69 )
{
if ( ! V_69 -> V_33 . V_146 )
V_69 -> V_33 . V_146 = F_123 ( V_3 -> V_143 , V_96 ) ;
F_127 ( V_69 -> V_33 . V_146 , V_3 -> V_4 . V_7 [ 0 ] ) ;
F_128 ( V_69 -> V_33 . V_146 ,
V_144 | V_29 ,
V_145 , F_93 ( V_3 , V_69 -> V_33 . V_146 ) ) ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_114 * V_69 )
{
if ( F_76 ( V_3 ) )
F_126 ( V_3 , V_69 ) ;
else
F_122 ( V_3 , V_69 ) ;
}
static void F_130 ( struct V_2 * V_3 ,
struct V_141 * V_20 , struct V_90 * V_147 )
{
struct V_88 * V_89 = F_131 ( V_147 , V_3 -> V_148 ) ;
if ( (struct V_141 * ) ( V_89 + 1 ) != V_20 )
F_132 ( V_20 , V_3 -> V_143 ) ;
}
static void F_133 ( struct V_2 * V_3 ,
struct V_124 * V_20 , struct V_90 * V_147 )
{
struct V_88 * V_89 = F_131 ( V_147 , V_3 -> V_148 ) ;
if ( (struct V_124 * ) ( V_89 + 1 ) != V_20 )
F_132 ( V_20 , V_3 -> V_143 ) ;
}
static void F_134 ( struct V_2 * V_3 , void * V_20 , struct V_90 * V_147 )
{
if ( F_76 ( V_3 ) )
F_133 ( V_3 , V_20 , V_147 ) ;
else
F_130 ( V_3 , V_20 , V_147 ) ;
}
static T_4 F_135 ( struct V_2 * V_3 ,
struct V_114 * V_69 )
{
unsigned int V_125 = 0 ;
unsigned int V_149 = V_3 -> V_52 >> V_53 ;
int V_33 ;
F_136 ( & V_69 -> V_150 , 1 ) ;
while ( V_69 -> V_116 . V_98 && V_69 -> V_118 . V_98 ) {
F_129 ( V_3 , V_69 ) ;
F_137 ( & V_69 -> V_150 ) ;
if ( F_76 ( V_3 ) )
V_33 = F_105 ( V_3 , V_69 , V_69 -> V_33 . V_146 , V_125 ) ;
else
V_33 = F_118 ( V_3 , V_69 , V_69 -> V_33 . V_20 , V_125 ) ;
switch ( V_33 ) {
case - V_151 :
F_138 ( & V_69 -> V_121 ) ;
F_139 ( & V_69 -> V_121 ) ;
case - V_152 :
V_69 -> V_33 . V_20 = NULL ;
V_69 -> V_119 += V_149 ;
V_125 ++ ;
continue;
case 0 :
F_140 ( & V_69 -> V_150 ) ;
V_69 -> V_119 += V_149 ;
V_125 ++ ;
F_141 () ;
continue;
case - V_139 :
F_140 ( & V_69 -> V_150 ) ;
return V_153 ;
default:
F_140 ( & V_69 -> V_150 ) ;
return V_154 ;
}
}
return 0 ;
}
static struct V_90 * F_142 ( struct V_88 * V_89 , unsigned V_155 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_156 ;
unsigned int V_157 = ( V_155 + V_158 - 1 ) >> V_159 ;
T_5 V_160 = V_161 | V_162 ;
unsigned V_63 , V_163 , V_164 ;
struct V_165 * V_165 ;
V_166:
if ( F_79 ( V_160 & V_167 ) )
F_143 ( & V_3 -> V_168 ) ;
V_156 = F_144 ( V_96 , V_157 , V_3 -> V_45 ) ;
if ( ! V_156 )
goto V_84;
F_145 ( V_89 , V_156 ) ;
V_164 = V_155 ;
for ( V_63 = 0 ; V_63 < V_157 ; V_63 ++ ) {
V_165 = F_123 ( V_3 -> V_169 , V_160 ) ;
if ( ! V_165 ) {
F_146 ( V_3 , V_156 ) ;
F_147 ( V_156 ) ;
V_160 |= V_167 ;
goto V_166;
}
V_163 = ( V_164 > V_158 ) ? V_158 : V_164 ;
F_148 ( V_156 , V_165 , V_163 , 0 ) ;
V_164 -= V_163 ;
}
if ( F_80 ( V_89 , V_156 ) ) {
F_146 ( V_3 , V_156 ) ;
F_147 ( V_156 ) ;
V_156 = NULL ;
}
V_84:
if ( F_79 ( V_160 & V_167 ) )
F_149 ( & V_3 -> V_168 ) ;
return V_156 ;
}
static void F_146 ( struct V_2 * V_3 , struct V_90 * V_156 )
{
unsigned int V_63 ;
struct V_126 * V_170 ;
F_150 (bv, clone, i) {
F_107 ( ! V_170 -> V_136 ) ;
F_132 ( V_170 -> V_136 , V_3 -> V_169 ) ;
V_170 -> V_136 = NULL ;
}
}
static void F_151 ( struct V_88 * V_89 , struct V_2 * V_3 ,
struct V_90 * V_90 , T_2 V_83 )
{
V_89 -> V_3 = V_3 ;
V_89 -> V_147 = V_90 ;
V_89 -> V_83 = V_83 ;
V_89 -> error = 0 ;
V_89 -> V_69 . V_33 . V_20 = NULL ;
V_89 -> V_101 = NULL ;
V_89 -> V_171 = false ;
F_136 ( & V_89 -> V_172 , 0 ) ;
}
static void F_152 ( struct V_88 * V_89 )
{
F_137 ( & V_89 -> V_172 ) ;
}
static void F_153 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_147 = V_89 -> V_147 ;
T_4 error = V_89 -> error ;
if ( ! F_154 ( & V_89 -> V_172 ) )
return;
if ( V_89 -> V_69 . V_33 . V_20 )
F_134 ( V_3 , V_89 -> V_69 . V_33 . V_20 , V_147 ) ;
if ( F_79 ( V_89 -> V_171 ) )
F_132 ( V_89 -> V_101 , V_89 -> V_3 -> V_173 ) ;
else
F_33 ( V_89 -> V_101 ) ;
V_147 -> V_174 = error ;
F_155 ( V_147 ) ;
}
static void F_156 ( struct V_90 * V_156 )
{
struct V_88 * V_89 = V_156 -> V_175 ;
struct V_2 * V_3 = V_89 -> V_3 ;
unsigned V_176 = F_57 ( V_156 ) ;
T_4 error ;
if ( V_176 == V_71 )
F_146 ( V_3 , V_156 ) ;
error = V_156 -> V_174 ;
F_147 ( V_156 ) ;
if ( V_176 == V_177 && ! error ) {
F_157 ( V_89 ) ;
return;
}
if ( F_79 ( error ) )
V_89 -> error = error ;
F_153 ( V_89 ) ;
}
static void F_145 ( struct V_88 * V_89 , struct V_90 * V_156 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
V_156 -> V_175 = V_89 ;
V_156 -> V_178 = F_156 ;
F_158 ( V_156 , V_3 -> V_104 -> V_105 ) ;
V_156 -> V_179 = V_89 -> V_147 -> V_179 ;
}
static int F_159 ( struct V_88 * V_89 , T_5 V_180 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_156 ;
V_156 = F_160 ( V_89 -> V_147 , V_180 , V_3 -> V_45 ) ;
if ( ! V_156 )
return 1 ;
F_152 ( V_89 ) ;
F_145 ( V_89 , V_156 ) ;
V_156 -> V_117 . V_99 = V_3 -> V_100 + V_89 -> V_83 ;
if ( F_80 ( V_89 , V_156 ) ) {
F_153 ( V_89 ) ;
F_147 ( V_156 ) ;
return 1 ;
}
F_161 ( V_156 ) ;
return 0 ;
}
static void F_162 ( struct V_181 * V_182 )
{
struct V_88 * V_89 = F_103 ( V_182 , struct V_88 , V_182 ) ;
F_152 ( V_89 ) ;
if ( F_159 ( V_89 , V_96 ) )
V_89 -> error = V_183 ;
F_153 ( V_89 ) ;
}
static void F_163 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
F_164 ( & V_89 -> V_182 , F_162 ) ;
F_165 ( V_3 -> V_184 , & V_89 -> V_182 ) ;
}
static void F_166 ( struct V_88 * V_89 )
{
struct V_90 * V_156 = V_89 -> V_69 . V_115 ;
F_161 ( V_156 ) ;
}
static int F_167 ( void * V_58 )
{
struct V_2 * V_3 = V_58 ;
struct V_88 * V_89 ;
while ( 1 ) {
struct V_185 V_186 ;
struct V_187 V_188 ;
F_168 ( V_189 , V_190 ) ;
F_169 ( & V_3 -> V_191 . V_192 ) ;
V_193:
if ( ! F_170 ( & V_3 -> V_186 ) )
goto V_194;
F_171 ( V_195 ) ;
F_172 ( & V_3 -> V_191 , & V_189 ) ;
F_173 ( & V_3 -> V_191 . V_192 ) ;
if ( F_79 ( F_174 () ) ) {
F_171 ( V_196 ) ;
F_175 ( & V_3 -> V_191 , & V_189 ) ;
break;
}
F_176 () ;
F_171 ( V_196 ) ;
F_169 ( & V_3 -> V_191 . V_192 ) ;
F_177 ( & V_3 -> V_191 , & V_189 ) ;
goto V_193;
V_194:
V_186 = V_3 -> V_186 ;
V_3 -> V_186 = V_197 ;
F_173 ( & V_3 -> V_191 . V_192 ) ;
F_107 ( F_178 ( V_186 . V_198 ) ) ;
F_179 ( & V_188 ) ;
do {
V_89 = F_180 ( F_181 ( & V_186 ) ) ;
F_182 ( & V_89 -> V_198 , & V_186 ) ;
F_166 ( V_89 ) ;
} while ( ! F_170 ( & V_186 ) );
F_183 ( & V_188 ) ;
}
return 0 ;
}
static void F_184 ( struct V_88 * V_89 , int V_199 )
{
struct V_90 * V_156 = V_89 -> V_69 . V_115 ;
struct V_2 * V_3 = V_89 -> V_3 ;
unsigned long V_65 ;
T_2 V_83 ;
struct V_198 * * V_200 , * V_201 ;
if ( F_79 ( V_89 -> error ) ) {
F_146 ( V_3 , V_156 ) ;
F_147 ( V_156 ) ;
F_153 ( V_89 ) ;
return;
}
F_107 ( V_89 -> V_69 . V_118 . V_98 ) ;
V_156 -> V_117 . V_99 = V_3 -> V_100 + V_89 -> V_83 ;
if ( F_185 ( ! V_199 ) && F_77 ( V_202 , & V_3 -> V_65 ) ) {
F_161 ( V_156 ) ;
return;
}
F_186 ( & V_3 -> V_191 . V_192 , V_65 ) ;
V_200 = & V_3 -> V_186 . V_198 ;
V_201 = NULL ;
V_83 = V_89 -> V_83 ;
while ( * V_200 ) {
V_201 = * V_200 ;
if ( V_83 < F_180 ( V_201 ) -> V_83 )
V_200 = & ( * V_200 ) -> V_203 ;
else
V_200 = & ( * V_200 ) -> V_204 ;
}
F_187 ( & V_89 -> V_198 , V_201 , V_200 ) ;
F_188 ( & V_89 -> V_198 , & V_3 -> V_186 ) ;
F_189 ( & V_3 -> V_191 ) ;
F_190 ( & V_3 -> V_191 . V_192 , V_65 ) ;
}
static void F_191 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
struct V_90 * V_156 ;
int V_205 ;
T_2 V_83 = V_89 -> V_83 ;
T_4 V_33 ;
F_152 ( V_89 ) ;
F_91 ( V_3 , & V_89 -> V_69 , NULL , V_89 -> V_147 , V_83 ) ;
V_156 = F_142 ( V_89 , V_89 -> V_147 -> V_117 . V_98 ) ;
if ( F_79 ( ! V_156 ) ) {
V_89 -> error = V_154 ;
goto V_206;
}
V_89 -> V_69 . V_115 = V_156 ;
V_89 -> V_69 . V_118 = V_156 -> V_117 ;
V_83 += F_81 ( V_156 ) ;
F_152 ( V_89 ) ;
V_33 = F_135 ( V_3 , & V_89 -> V_69 ) ;
if ( V_33 )
V_89 -> error = V_33 ;
V_205 = F_154 ( & V_89 -> V_69 . V_150 ) ;
if ( V_205 ) {
F_184 ( V_89 , 0 ) ;
V_89 -> V_83 = V_83 ;
}
V_206:
F_153 ( V_89 ) ;
}
static void F_192 ( struct V_88 * V_89 )
{
F_153 ( V_89 ) ;
}
static void F_193 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
T_4 V_33 ;
F_152 ( V_89 ) ;
F_91 ( V_3 , & V_89 -> V_69 , V_89 -> V_147 , V_89 -> V_147 ,
V_89 -> V_83 ) ;
V_33 = F_135 ( V_3 , & V_89 -> V_69 ) ;
if ( V_33 )
V_89 -> error = V_33 ;
if ( F_154 ( & V_89 -> V_69 . V_150 ) )
F_192 ( V_89 ) ;
F_153 ( V_89 ) ;
}
static void V_145 ( struct V_207 * V_208 ,
int error )
{
struct V_9 * V_10 = V_208 -> V_58 ;
struct V_114 * V_69 = V_10 -> V_69 ;
struct V_88 * V_89 = F_103 ( V_69 , struct V_88 , V_69 ) ;
struct V_2 * V_3 = V_89 -> V_3 ;
if ( error == - V_152 ) {
F_194 ( & V_69 -> V_121 ) ;
return;
}
if ( ! error && V_3 -> V_137 && V_3 -> V_137 -> V_140 )
error = V_3 -> V_137 -> V_140 ( V_3 , F_99 ( V_3 , V_10 ) , V_10 ) ;
if ( error == - V_139 ) {
F_115 ( L_27 ,
( unsigned long long ) F_116 ( * F_100 ( V_3 , V_10 ) ) ) ;
V_89 -> error = V_153 ;
} else if ( error < 0 )
V_89 -> error = V_154 ;
F_134 ( V_3 , F_94 ( V_3 , V_10 ) , V_89 -> V_147 ) ;
if ( ! F_154 ( & V_69 -> V_150 ) )
return;
if ( F_57 ( V_89 -> V_147 ) == V_177 )
F_192 ( V_89 ) ;
else
F_184 ( V_89 , 1 ) ;
}
static void F_195 ( struct V_181 * V_182 )
{
struct V_88 * V_89 = F_103 ( V_182 , struct V_88 , V_182 ) ;
if ( F_57 ( V_89 -> V_147 ) == V_177 )
F_193 ( V_89 ) ;
else
F_191 ( V_89 ) ;
}
static void F_157 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = V_89 -> V_3 ;
F_164 ( & V_89 -> V_182 , F_195 ) ;
F_165 ( V_3 -> V_209 , & V_89 -> V_182 ) ;
}
static void F_196 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 . V_7 )
return;
if ( V_3 -> V_4 . V_7 [ 0 ] && ! F_22 ( V_3 -> V_4 . V_7 [ 0 ] ) ) {
F_197 ( V_3 -> V_4 . V_7 [ 0 ] ) ;
V_3 -> V_4 . V_7 [ 0 ] = NULL ;
}
F_33 ( V_3 -> V_4 . V_7 ) ;
V_3 -> V_4 . V_7 = NULL ;
}
static void F_198 ( struct V_2 * V_3 )
{
unsigned V_63 ;
if ( ! V_3 -> V_4 . V_5 )
return;
for ( V_63 = 0 ; V_63 < V_3 -> V_55 ; V_63 ++ )
if ( V_3 -> V_4 . V_5 [ V_63 ] && ! F_22 ( V_3 -> V_4 . V_5 [ V_63 ] ) ) {
F_199 ( V_3 -> V_4 . V_5 [ V_63 ] ) ;
V_3 -> V_4 . V_5 [ V_63 ] = NULL ;
}
F_33 ( V_3 -> V_4 . V_5 ) ;
V_3 -> V_4 . V_5 = NULL ;
}
static void F_200 ( struct V_2 * V_3 )
{
if ( F_76 ( V_3 ) )
F_196 ( V_3 ) ;
else
F_198 ( V_3 ) ;
}
static int F_201 ( struct V_2 * V_3 , char * V_210 )
{
unsigned V_63 ;
int V_26 ;
V_3 -> V_4 . V_5 = F_32 ( V_3 -> V_55 *
sizeof( struct V_1 * ) , V_43 ) ;
if ( ! V_3 -> V_4 . V_5 )
return - V_44 ;
for ( V_63 = 0 ; V_63 < V_3 -> V_55 ; V_63 ++ ) {
V_3 -> V_4 . V_5 [ V_63 ] = F_202 ( V_210 , 0 , 0 ) ;
if ( F_22 ( V_3 -> V_4 . V_5 [ V_63 ] ) ) {
V_26 = F_31 ( V_3 -> V_4 . V_5 [ V_63 ] ) ;
F_200 ( V_3 ) ;
return V_26 ;
}
}
return 0 ;
}
static int F_203 ( struct V_2 * V_3 , char * V_210 )
{
int V_26 ;
V_3 -> V_4 . V_5 = F_204 ( sizeof( struct V_6 * ) , V_43 ) ;
if ( ! V_3 -> V_4 . V_5 )
return - V_44 ;
V_3 -> V_4 . V_7 [ 0 ] = F_205 ( V_210 , 0 , 0 ) ;
if ( F_22 ( V_3 -> V_4 . V_7 [ 0 ] ) ) {
V_26 = F_31 ( V_3 -> V_4 . V_7 [ 0 ] ) ;
F_200 ( V_3 ) ;
return V_26 ;
}
return 0 ;
}
static int F_206 ( struct V_2 * V_3 , char * V_210 )
{
if ( F_76 ( V_3 ) )
return F_203 ( V_3 , V_210 ) ;
else
return F_201 ( V_3 , V_210 ) ;
}
static unsigned F_207 ( struct V_2 * V_3 )
{
return ( V_3 -> V_28 - V_3 -> V_211 ) >> F_38 ( V_3 -> V_55 ) ;
}
static unsigned F_208 ( struct V_2 * V_3 )
{
return F_207 ( V_3 ) + F_209 ( sizeof( struct V_212 ) ) ;
}
static void F_210 ( char * V_213 , const void * V_27 ,
unsigned V_214 , unsigned V_215 )
{
struct V_212 * V_216 ;
struct V_217 * V_218 ;
V_218 = (struct V_217 * ) V_213 ;
V_216 = F_211 ( V_218 ) ;
V_216 -> V_214 = F_212 ( V_214 ) ;
V_218 -> V_219 = F_213 ( sizeof( * V_216 ) ) ;
V_218 -> V_220 = V_221 ;
V_213 += F_209 ( sizeof( * V_216 ) ) ;
memcpy ( V_213 , V_27 + V_214 , V_215 ) ;
V_213 += V_215 ;
memcpy ( V_213 , V_27 , V_214 ) ;
}
static int F_214 ( struct V_2 * V_3 )
{
unsigned V_57 ;
int V_26 = 0 , V_63 , V_33 ;
V_57 = F_207 ( V_3 ) ;
if ( F_78 ( V_3 ) )
F_210 ( V_3 -> V_222 , V_3 -> V_27 ,
V_57 - V_3 -> V_87 ,
V_3 -> V_87 ) ;
for ( V_63 = 0 ; V_63 < V_3 -> V_55 ; V_63 ++ ) {
if ( F_78 ( V_3 ) )
V_33 = F_215 ( V_3 -> V_4 . V_7 [ V_63 ] ,
V_3 -> V_222 , F_208 ( V_3 ) ) ;
else if ( F_76 ( V_3 ) )
V_33 = F_215 ( V_3 -> V_4 . V_7 [ V_63 ] ,
V_3 -> V_27 + ( V_63 * V_57 ) ,
V_57 ) ;
else
V_33 = F_216 ( V_3 -> V_4 . V_5 [ V_63 ] ,
V_3 -> V_27 + ( V_63 * V_57 ) ,
V_57 ) ;
if ( V_33 )
V_26 = V_33 ;
}
if ( F_78 ( V_3 ) )
F_71 ( V_3 -> V_222 , F_208 ( V_3 ) ) ;
return V_26 ;
}
static bool F_217 ( const char * V_223 )
{
while ( * V_223 )
if ( isspace ( * V_223 ++ ) )
return true ;
return false ;
}
static int F_218 ( struct V_2 * V_3 , const char * V_224 )
{
char * V_225 , * V_226 ;
int V_94 ;
struct V_27 * V_27 ;
const struct V_227 * V_228 ;
if ( F_217 ( V_224 ) ) {
F_219 ( L_28 ) ;
return - V_39 ;
}
V_226 = strpbrk ( V_224 , L_29 ) ;
if ( ! V_226 || V_226 == V_224 || ! strlen ( V_226 + 1 ) )
return - V_39 ;
if ( strncmp ( V_224 , L_30 , V_226 - V_224 + 1 ) &&
strncmp ( V_224 , L_31 , V_226 - V_224 + 1 ) )
return - V_39 ;
V_225 = F_220 ( V_224 , V_43 ) ;
if ( ! V_225 )
return - V_44 ;
V_27 = F_221 ( V_224 [ 0 ] == 'l' ? & V_229 : & V_230 ,
V_226 + 1 , NULL ) ;
if ( F_22 ( V_27 ) ) {
F_28 ( V_225 ) ;
return F_31 ( V_27 ) ;
}
F_222 ( & V_27 -> V_231 ) ;
V_228 = F_223 ( V_27 ) ;
if ( ! V_228 ) {
F_224 ( & V_27 -> V_231 ) ;
F_225 ( V_27 ) ;
F_28 ( V_225 ) ;
return - V_232 ;
}
if ( V_3 -> V_28 != V_228 -> V_233 ) {
F_224 ( & V_27 -> V_231 ) ;
F_225 ( V_27 ) ;
F_28 ( V_225 ) ;
return - V_39 ;
}
memcpy ( V_3 -> V_27 , V_228 -> V_58 , V_3 -> V_28 ) ;
F_224 ( & V_27 -> V_231 ) ;
F_225 ( V_27 ) ;
F_226 ( V_234 , & V_3 -> V_65 ) ;
V_94 = F_214 ( V_3 ) ;
memset ( V_3 -> V_27 , 0 , V_3 -> V_28 * sizeof( T_1 ) ) ;
if ( ! V_94 ) {
F_227 ( V_234 , & V_3 -> V_65 ) ;
F_28 ( V_3 -> V_224 ) ;
V_3 -> V_224 = V_225 ;
} else
F_28 ( V_225 ) ;
return V_94 ;
}
static int F_228 ( char * * V_224 )
{
char * V_235 , V_236 ;
int V_94 ;
if ( * V_224 [ 0 ] != ':' )
return strlen ( * V_224 ) >> 1 ;
V_235 = strpbrk ( * V_224 + 1 , L_29 ) ;
if ( ! V_235 )
return - V_39 ;
if ( sscanf ( * V_224 + 1 , L_32 , & V_94 , & V_236 ) != 2 || V_236 != ':' )
return - V_39 ;
* V_224 = V_235 ;
return V_94 ;
}
static int F_218 ( struct V_2 * V_3 , const char * V_224 )
{
return - V_39 ;
}
static int F_228 ( char * * V_224 )
{
return ( * V_224 [ 0 ] == ':' ) ? - V_39 : strlen ( * V_224 ) >> 1 ;
}
static int F_229 ( struct V_2 * V_3 , char * V_27 )
{
int V_33 = - V_39 ;
int V_237 = strlen ( V_27 ) ;
if ( ! V_3 -> V_28 && strcmp ( V_27 , L_33 ) )
goto V_84;
if ( V_27 [ 0 ] == ':' ) {
V_33 = F_218 ( V_3 , V_27 + 1 ) ;
goto V_84;
}
F_226 ( V_234 , & V_3 -> V_65 ) ;
F_28 ( V_3 -> V_224 ) ;
V_3 -> V_224 = NULL ;
if ( V_3 -> V_28 && F_230 ( V_3 -> V_27 , V_27 , V_3 -> V_28 ) < 0 )
goto V_84;
V_33 = F_214 ( V_3 ) ;
if ( ! V_33 )
F_227 ( V_234 , & V_3 -> V_65 ) ;
V_84:
memset ( V_27 , '0' , V_237 ) ;
return V_33 ;
}
static int F_231 ( struct V_2 * V_3 )
{
int V_33 ;
F_226 ( V_234 , & V_3 -> V_65 ) ;
F_75 ( & V_3 -> V_27 , V_3 -> V_28 ) ;
F_28 ( V_3 -> V_224 ) ;
V_3 -> V_224 = NULL ;
V_33 = F_214 ( V_3 ) ;
memset ( & V_3 -> V_27 , 0 , V_3 -> V_28 * sizeof( T_1 ) ) ;
return V_33 ;
}
static void F_232 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
V_35 -> V_238 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_239 )
F_233 ( V_3 -> V_239 ) ;
if ( V_3 -> V_184 )
F_234 ( V_3 -> V_184 ) ;
if ( V_3 -> V_209 )
F_234 ( V_3 -> V_209 ) ;
F_200 ( V_3 ) ;
if ( V_3 -> V_45 )
F_235 ( V_3 -> V_45 ) ;
F_236 ( V_3 -> V_169 ) ;
F_236 ( V_3 -> V_143 ) ;
F_236 ( V_3 -> V_173 ) ;
if ( V_3 -> V_137 && V_3 -> V_137 -> V_240 )
V_3 -> V_137 -> V_240 ( V_3 ) ;
if ( V_3 -> V_104 )
F_237 ( V_35 , V_3 -> V_104 ) ;
F_28 ( V_3 -> V_37 ) ;
F_28 ( V_3 -> V_241 ) ;
F_28 ( V_3 -> V_224 ) ;
F_28 ( V_3 -> V_242 ) ;
F_28 ( V_3 -> V_222 ) ;
F_28 ( V_3 ) ;
}
static int F_238 ( struct V_34 * V_35 , const char * V_243 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
if ( F_76 ( V_3 ) )
V_3 -> V_11 = F_239 ( F_2 ( V_3 ) ) ;
else
V_3 -> V_11 = F_240 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_11 )
V_3 -> V_11 = F_241 ( V_3 -> V_11 ,
( unsigned int ) ( sizeof( V_16 ) / sizeof( T_1 ) ) ) ;
else if ( V_243 ) {
F_242 ( L_34 ) ;
V_243 = NULL ;
}
if ( V_243 == NULL )
V_3 -> V_137 = NULL ;
else if ( strcmp ( V_243 , L_35 ) == 0 )
V_3 -> V_137 = & V_244 ;
else if ( strcmp ( V_243 , L_36 ) == 0 )
V_3 -> V_137 = & V_245 ;
else if ( strcmp ( V_243 , L_37 ) == 0 )
V_3 -> V_137 = & V_246 ;
else if ( strcmp ( V_243 , L_38 ) == 0 )
V_3 -> V_137 = & V_247 ;
else if ( strcmp ( V_243 , L_39 ) == 0 )
V_3 -> V_137 = & V_248 ;
else if ( strcmp ( V_243 , L_40 ) == 0 )
V_3 -> V_137 = & V_249 ;
else if ( strcmp ( V_243 , L_41 ) == 0 ) {
V_3 -> V_137 = & V_250 ;
if ( V_3 -> V_28 % V_3 -> V_54 ) {
V_3 -> V_54 ++ ;
V_3 -> V_211 = V_3 -> V_28 / V_3 -> V_54 ;
}
} else if ( strcmp ( V_243 , L_42 ) == 0 ) {
V_3 -> V_137 = & V_251 ;
V_3 -> V_54 += 2 ;
V_3 -> V_211 = V_3 -> V_11 + V_81 ;
} else if ( strcmp ( V_243 , L_43 ) == 0 ) {
V_3 -> V_137 = & V_252 ;
V_3 -> V_113 = V_3 -> V_11 ;
} else {
V_35 -> error = L_44 ;
return - V_39 ;
}
return 0 ;
}
static int F_243 ( struct V_2 * V_3 )
{
const char * V_253 = NULL ;
char * V_100 , * V_254 ;
if ( F_76 ( V_3 ) ) {
V_253 = F_244 ( F_245 ( F_2 ( V_3 ) ) ) ;
if ( ! V_253 )
return - V_39 ;
if ( F_78 ( V_3 ) ) {
V_253 = strchr ( V_253 , ',' ) ;
if ( ! V_253 )
return - V_39 ;
}
V_253 ++ ;
} else {
V_253 = F_244 ( F_246 ( F_1 ( V_3 ) ) ) ;
if ( ! V_253 )
return - V_39 ;
}
V_100 = strchr ( V_253 , '(' ) ;
V_254 = strchr ( V_253 , ')' ) ;
if ( ! V_100 && ! V_254 ) {
V_3 -> V_37 = F_220 ( V_253 , V_43 ) ;
return V_3 -> V_37 ? 0 : - V_44 ;
}
if ( ! V_100 || ! V_254 || ++ V_100 >= V_254 )
return - V_39 ;
V_3 -> V_37 = F_32 ( V_254 - V_100 + 1 , V_43 ) ;
if ( ! V_3 -> V_37 )
return - V_44 ;
strncpy ( V_3 -> V_37 , V_100 , V_254 - V_100 ) ;
return 0 ;
}
static int F_247 ( struct V_2 * V_3 , char * V_255 )
{
char * V_100 , * V_254 , * V_256 = NULL ;
struct V_41 * V_257 ;
if ( ! F_248 ( V_255 , L_45 ) )
return 0 ;
V_100 = strchr ( V_255 , '(' ) ;
V_254 = strchr ( V_255 , ',' ) ;
if ( ! V_100 || ! V_254 || ++ V_100 > V_254 )
return - V_39 ;
V_256 = F_32 ( V_254 - V_100 + 1 , V_43 ) ;
if ( ! V_256 )
return - V_44 ;
strncpy ( V_256 , V_100 , V_254 - V_100 ) ;
V_257 = F_30 ( V_256 , 0 , 0 ) ;
F_33 ( V_256 ) ;
if ( F_22 ( V_257 ) )
return F_31 ( V_257 ) ;
V_3 -> V_87 = F_18 ( V_257 ) ;
F_27 ( V_257 ) ;
V_3 -> V_222 = F_204 ( F_208 ( V_3 ) , V_43 ) ;
if ( ! V_3 -> V_222 )
return - V_44 ;
return 0 ;
}
static int F_249 ( struct V_34 * V_35 , char * V_258 , char * V_27 ,
char * * V_243 , char * * V_259 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
char * V_260 , * V_255 ;
int V_94 = - V_39 ;
V_3 -> V_55 = 1 ;
V_260 = & V_258 [ strlen ( L_46 ) ] ;
V_255 = F_250 ( & V_260 , L_33 ) ;
* V_243 = F_250 ( & V_260 , L_29 ) ;
* V_259 = V_260 ;
if ( * V_243 && ! strcmp ( * V_243 , L_41 ) )
V_3 -> V_55 = 64 ;
V_3 -> V_54 = V_3 -> V_55 ;
V_94 = F_206 ( V_3 , V_255 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_47 ;
return V_94 ;
}
if ( F_76 ( V_3 ) ) {
V_94 = F_247 ( V_3 , V_255 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_48 ;
return - V_44 ;
}
V_3 -> V_11 = F_239 ( F_2 ( V_3 ) ) ;
} else
V_3 -> V_11 = F_240 ( F_1 ( V_3 ) ) ;
V_94 = F_243 ( V_3 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_49 ;
return - V_44 ;
}
return 0 ;
}
static int F_251 ( struct V_34 * V_35 , char * V_258 , char * V_27 ,
char * * V_243 , char * * V_259 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
char * V_260 , * V_37 , * V_261 , * V_262 ;
char * V_255 = NULL ;
int V_94 = - V_39 ;
char V_236 ;
if ( strchr ( V_258 , '(' ) || F_76 ( V_3 ) ) {
V_35 -> error = L_50 ;
return - V_39 ;
}
V_260 = V_258 ;
V_262 = F_250 ( & V_260 , L_33 ) ;
V_37 = F_250 ( & V_262 , L_29 ) ;
if ( ! V_262 )
V_3 -> V_55 = 1 ;
else if ( sscanf ( V_262 , L_32 , & V_3 -> V_55 , & V_236 ) != 1 ||
! F_252 ( V_3 -> V_55 ) ) {
V_35 -> error = L_51 ;
return - V_39 ;
}
V_3 -> V_54 = V_3 -> V_55 ;
V_3 -> V_37 = F_220 ( V_37 , V_43 ) ;
if ( ! V_3 -> V_37 )
goto V_263;
V_261 = F_250 ( & V_260 , L_33 ) ;
* V_259 = F_250 ( & V_260 , L_33 ) ;
* V_243 = F_250 ( & * V_259 , L_29 ) ;
if ( V_260 )
F_242 ( L_52 ) ;
if ( ! V_261 || ( ! strcmp ( V_261 , L_35 ) && ! * V_243 ) ) {
V_261 = L_53 ;
* V_243 = L_35 ;
}
if ( strcmp ( V_261 , L_54 ) && ! * V_243 ) {
V_35 -> error = L_55 ;
return - V_39 ;
}
V_255 = F_204 ( V_264 , V_43 ) ;
if ( ! V_255 )
goto V_263;
V_94 = snprintf ( V_255 , V_264 ,
L_56 , V_261 , V_37 ) ;
if ( V_94 < 0 ) {
F_33 ( V_255 ) ;
goto V_263;
}
V_94 = F_206 ( V_3 , V_255 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_47 ;
F_33 ( V_255 ) ;
return V_94 ;
}
F_33 ( V_255 ) ;
return 0 ;
V_263:
V_35 -> error = L_57 ;
return - V_44 ;
}
static int F_253 ( struct V_34 * V_35 , char * V_258 , char * V_27 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
char * V_243 = NULL , * V_259 = NULL ;
int V_94 ;
V_3 -> V_241 = F_220 ( V_258 , V_43 ) ;
if ( ! V_3 -> V_241 ) {
V_35 -> error = L_57 ;
return - V_44 ;
}
if ( F_248 ( V_258 , L_46 ) )
V_94 = F_249 ( V_35 , V_258 , V_27 , & V_243 , & V_259 ) ;
else
V_94 = F_251 ( V_35 , V_258 , V_27 , & V_243 , & V_259 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_238 ( V_35 , V_243 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_229 ( V_3 , V_27 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_58 ;
return V_94 ;
}
if ( V_3 -> V_137 && V_3 -> V_137 -> V_265 ) {
V_94 = V_3 -> V_137 -> V_265 ( V_3 , V_35 , V_259 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_59 ;
return V_94 ;
}
}
if ( V_3 -> V_137 && V_3 -> V_137 -> V_266 ) {
V_94 = V_3 -> V_137 -> V_266 ( V_3 ) ;
if ( V_94 < 0 ) {
V_35 -> error = L_60 ;
return V_94 ;
}
}
return V_94 ;
}
static int F_254 ( struct V_34 * V_35 , unsigned int V_267 , char * * V_268 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
struct V_269 V_270 ;
static const struct V_271 V_272 [] = {
{ 0 , 6 , L_61 } ,
} ;
unsigned int V_273 , V_48 ;
const char * V_274 , * V_275 ;
char V_236 ;
int V_94 ;
V_270 . V_267 = V_267 ;
V_270 . V_268 = V_268 ;
V_94 = F_255 ( V_272 , & V_270 , & V_273 , & V_35 -> error ) ;
if ( V_94 )
return V_94 ;
while ( V_273 -- ) {
V_274 = F_256 ( & V_270 ) ;
if ( ! V_274 ) {
V_35 -> error = L_62 ;
return - V_39 ;
}
if ( ! strcasecmp ( V_274 , L_63 ) )
V_35 -> V_276 = 1 ;
else if ( ! strcasecmp ( V_274 , L_64 ) )
F_227 ( V_277 , & V_3 -> V_65 ) ;
else if ( ! strcasecmp ( V_274 , L_65 ) )
F_227 ( V_202 , & V_3 -> V_65 ) ;
else if ( sscanf ( V_274 , L_66 , & V_48 ) == 1 ) {
if ( V_48 == 0 || V_48 > V_278 ) {
V_35 -> error = L_67 ;
return - V_39 ;
}
V_3 -> V_95 = V_48 ;
V_275 = strchr ( V_274 + strlen ( L_68 ) , ':' ) + 1 ;
if ( ! strcasecmp ( V_275 , L_69 ) ) {
F_227 ( V_85 , & V_3 -> V_86 ) ;
} else if ( strcasecmp ( V_275 , L_70 ) ) {
V_35 -> error = L_71 ;
return - V_39 ;
}
V_3 -> V_242 = F_220 ( V_275 , V_43 ) ;
if ( ! V_3 -> V_242 )
return - V_44 ;
} else if ( sscanf ( V_274 , L_72 , & V_3 -> V_52 , & V_236 ) == 1 ) {
if ( V_3 -> V_52 < ( 1 << V_53 ) ||
V_3 -> V_52 > 4096 ||
( V_3 -> V_52 & ( V_3 -> V_52 - 1 ) ) ) {
V_35 -> error = L_73 ;
return - V_39 ;
}
if ( V_35 -> V_163 & ( ( V_3 -> V_52 >> V_53 ) - 1 ) ) {
V_35 -> error = L_74 ;
return - V_39 ;
}
V_3 -> V_135 = F_257 ( V_3 -> V_52 ) - V_53 ;
} else if ( ! strcasecmp ( V_274 , L_75 ) )
F_227 ( V_134 , & V_3 -> V_86 ) ;
else {
V_35 -> error = L_76 ;
return - V_39 ;
}
}
return 0 ;
}
static int F_258 ( struct V_34 * V_35 , unsigned int V_267 , char * * V_268 )
{
struct V_2 * V_3 ;
int V_28 ;
unsigned int V_279 ;
unsigned long long V_280 ;
int V_94 ;
T_6 V_281 , V_282 ;
char V_236 ;
if ( V_267 < 5 ) {
V_35 -> error = L_77 ;
return - V_39 ;
}
V_28 = F_228 ( & V_268 [ 1 ] ) ;
if ( V_28 < 0 ) {
V_35 -> error = L_78 ;
return - V_39 ;
}
V_3 = F_32 ( sizeof( * V_3 ) + V_28 * sizeof( T_1 ) , V_43 ) ;
if ( ! V_3 ) {
V_35 -> error = L_79 ;
return - V_44 ;
}
V_3 -> V_28 = V_28 ;
V_3 -> V_52 = ( 1 << V_53 ) ;
V_3 -> V_135 = 0 ;
V_35 -> V_238 = V_3 ;
if ( V_267 > 5 ) {
V_94 = F_254 ( V_35 , V_267 - 5 , & V_268 [ 5 ] ) ;
if ( V_94 )
goto V_42;
}
V_94 = F_253 ( V_35 , V_268 [ 0 ] , V_268 [ 1 ] ) ;
if ( V_94 < 0 )
goto V_42;
if ( F_76 ( V_3 ) ) {
V_3 -> V_122 = sizeof( struct V_124 ) ;
V_3 -> V_122 += F_259 ( F_2 ( V_3 ) ) ;
V_279 = F_97 ( F_2 ( V_3 ) ) ;
} else {
V_3 -> V_122 = sizeof( struct V_141 ) ;
V_3 -> V_122 += F_260 ( F_1 ( V_3 ) ) ;
V_279 = F_98 ( F_1 ( V_3 ) ) ;
}
V_3 -> V_122 = F_96 ( V_3 -> V_122 , F_261 ( struct V_9 ) ) ;
if ( V_279 < V_283 ) {
V_281 = - ( V_3 -> V_122 + sizeof( struct V_9 ) )
& V_279 ;
} else {
V_281 = V_279 ;
}
V_94 = - V_44 ;
V_282 = sizeof( struct V_9 ) +
V_281 + V_3 -> V_11 +
V_3 -> V_11 +
sizeof( T_3 ) +
sizeof( unsigned int ) ;
V_3 -> V_143 = F_262 ( V_284 , V_3 -> V_122 + V_282 ) ;
if ( ! V_3 -> V_143 ) {
V_35 -> error = L_80 ;
goto V_42;
}
V_3 -> V_148 = V_35 -> V_285 =
F_96 ( sizeof( struct V_88 ) + V_3 -> V_122 + V_282 ,
V_286 ) ;
V_3 -> V_169 = F_263 ( V_287 , 0 ) ;
if ( ! V_3 -> V_169 ) {
V_35 -> error = L_81 ;
goto V_42;
}
V_3 -> V_45 = F_264 ( V_284 , 0 , ( V_288 |
V_289 ) ) ;
if ( ! V_3 -> V_45 ) {
V_35 -> error = L_82 ;
goto V_42;
}
F_265 ( & V_3 -> V_168 ) ;
V_94 = - V_39 ;
if ( ( sscanf ( V_268 [ 2 ] , L_83 , & V_280 , & V_236 ) != 1 ) ||
( V_280 & ( ( V_3 -> V_52 >> V_53 ) - 1 ) ) ) {
V_35 -> error = L_84 ;
goto V_42;
}
V_3 -> V_120 = V_280 ;
V_94 = F_266 ( V_35 , V_268 [ 3 ] , F_267 ( V_35 -> V_290 ) , & V_3 -> V_104 ) ;
if ( V_94 ) {
V_35 -> error = L_85 ;
goto V_42;
}
V_94 = - V_39 ;
if ( sscanf ( V_268 [ 4 ] , L_83 , & V_280 , & V_236 ) != 1 ) {
V_35 -> error = L_86 ;
goto V_42;
}
V_3 -> V_100 = V_280 ;
if ( F_76 ( V_3 ) || V_3 -> V_113 ) {
V_94 = F_86 ( V_3 , V_35 ) ;
if ( V_94 )
goto V_42;
V_3 -> V_291 = V_292 / V_3 -> V_95 ;
if ( ! V_3 -> V_291 )
V_3 -> V_291 = 1 ;
V_3 -> V_173 = F_262 ( V_284 ,
V_3 -> V_291 * V_3 -> V_95 ) ;
if ( ! V_3 -> V_173 ) {
V_35 -> error = L_87 ;
goto V_42;
}
V_3 -> V_291 <<= V_3 -> V_135 ;
}
V_94 = - V_44 ;
V_3 -> V_184 = F_268 ( L_88 , V_293 | V_294 | V_295 , 1 ) ;
if ( ! V_3 -> V_184 ) {
V_35 -> error = L_89 ;
goto V_42;
}
if ( F_77 ( V_277 , & V_3 -> V_65 ) )
V_3 -> V_209 = F_268 ( L_90 , V_293 | V_294 | V_295 , 1 ) ;
else
V_3 -> V_209 = F_268 ( L_90 ,
V_293 | V_294 | V_295 | V_296 ,
F_269 () ) ;
if ( ! V_3 -> V_209 ) {
V_35 -> error = L_91 ;
goto V_42;
}
F_270 ( & V_3 -> V_191 ) ;
V_3 -> V_186 = V_197 ;
V_3 -> V_239 = F_271 ( F_167 , V_3 , L_92 ) ;
if ( F_22 ( V_3 -> V_239 ) ) {
V_94 = F_31 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
V_35 -> error = L_93 ;
goto V_42;
}
F_272 ( V_3 -> V_239 ) ;
V_35 -> V_297 = 1 ;
return 0 ;
V_42:
F_232 ( V_35 ) ;
return V_94 ;
}
static int F_273 ( struct V_34 * V_35 , struct V_90 * V_90 )
{
struct V_88 * V_89 ;
struct V_2 * V_3 = V_35 -> V_238 ;
if ( F_79 ( V_90 -> V_179 & V_298 ||
F_274 ( V_90 ) == V_299 ) ) {
F_158 ( V_90 , V_3 -> V_104 -> V_105 ) ;
if ( F_81 ( V_90 ) )
V_90 -> V_117 . V_99 = V_3 -> V_100 +
F_275 ( V_35 , V_90 -> V_117 . V_99 ) ;
return V_300 ;
}
if ( F_79 ( V_90 -> V_117 . V_98 > ( V_287 << V_159 ) ) &&
( F_57 ( V_90 ) == V_71 || V_3 -> V_95 ) )
F_276 ( V_90 , ( ( V_287 << V_159 ) >> V_53 ) ) ;
if ( F_79 ( ( V_90 -> V_117 . V_99 & ( ( V_3 -> V_52 >> V_53 ) - 1 ) ) != 0 ) )
return V_301 ;
if ( F_79 ( V_90 -> V_117 . V_98 & ( V_3 -> V_52 - 1 ) ) )
return V_301 ;
V_89 = F_131 ( V_90 , V_3 -> V_148 ) ;
F_151 ( V_89 , V_3 , V_90 , F_275 ( V_35 , V_90 -> V_117 . V_99 ) ) ;
if ( V_3 -> V_95 ) {
unsigned V_93 = V_3 -> V_95 * ( F_81 ( V_90 ) >> V_3 -> V_135 ) ;
if ( F_79 ( V_93 > V_302 ) ||
F_79 ( ! ( V_89 -> V_101 = F_204 ( V_93 ,
V_96 | V_303 | V_304 | V_305 ) ) ) ) {
if ( F_81 ( V_90 ) > V_3 -> V_291 )
F_276 ( V_90 , V_3 -> V_291 ) ;
V_89 -> V_101 = F_123 ( V_3 -> V_173 , V_96 ) ;
V_89 -> V_171 = true ;
}
}
if ( F_76 ( V_3 ) )
V_89 -> V_69 . V_33 . V_146 = (struct V_124 * ) ( V_89 + 1 ) ;
else
V_89 -> V_69 . V_33 . V_20 = (struct V_141 * ) ( V_89 + 1 ) ;
if ( F_57 ( V_89 -> V_147 ) == V_177 ) {
if ( F_159 ( V_89 , V_161 ) )
F_163 ( V_89 ) ;
} else
F_157 ( V_89 ) ;
return V_306 ;
}
static void F_277 ( struct V_34 * V_35 , T_7 type ,
unsigned V_307 , char * V_308 , unsigned V_309 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
unsigned V_63 , V_310 = 0 ;
int V_311 = 0 ;
switch ( type ) {
case V_312 :
V_308 [ 0 ] = '\0' ;
break;
case V_313 :
F_278 ( L_94 , V_3 -> V_241 ) ;
if ( V_3 -> V_28 > 0 ) {
if ( V_3 -> V_224 )
F_278 ( L_95 , V_3 -> V_28 , V_3 -> V_224 ) ;
else
for ( V_63 = 0 ; V_63 < V_3 -> V_28 ; V_63 ++ )
F_278 ( L_96 , V_3 -> V_27 [ V_63 ] ) ;
} else
F_278 ( L_33 ) ;
F_278 ( L_97 , ( unsigned long long ) V_3 -> V_120 ,
V_3 -> V_104 -> V_108 , ( unsigned long long ) V_3 -> V_100 ) ;
V_311 += ! ! V_35 -> V_276 ;
V_311 += F_77 ( V_277 , & V_3 -> V_65 ) ;
V_311 += F_77 ( V_202 , & V_3 -> V_65 ) ;
V_311 += V_3 -> V_52 != ( 1 << V_53 ) ;
V_311 += F_77 ( V_134 , & V_3 -> V_86 ) ;
if ( V_3 -> V_95 )
V_311 ++ ;
if ( V_311 ) {
F_278 ( L_98 , V_311 ) ;
if ( V_35 -> V_276 )
F_278 ( L_99 ) ;
if ( F_77 ( V_277 , & V_3 -> V_65 ) )
F_278 ( L_100 ) ;
if ( F_77 ( V_202 , & V_3 -> V_65 ) )
F_278 ( L_101 ) ;
if ( V_3 -> V_95 )
F_278 ( L_102 , V_3 -> V_95 , V_3 -> V_242 ) ;
if ( V_3 -> V_52 != ( 1 << V_53 ) )
F_278 ( L_103 , V_3 -> V_52 ) ;
if ( F_77 ( V_134 , & V_3 -> V_86 ) )
F_278 ( L_104 ) ;
}
break;
}
}
static void F_279 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
F_227 ( V_314 , & V_3 -> V_65 ) ;
}
static int F_280 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
if ( ! F_77 ( V_234 , & V_3 -> V_65 ) ) {
F_219 ( L_105 ) ;
return - V_315 ;
}
return 0 ;
}
static void F_281 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
F_226 ( V_314 , & V_3 -> V_65 ) ;
}
static int F_282 ( struct V_34 * V_35 , unsigned V_267 , char * * V_268 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
int V_28 , V_94 = - V_39 ;
if ( V_267 < 2 )
goto error;
if ( ! strcasecmp ( V_268 [ 0 ] , L_106 ) ) {
if ( ! F_77 ( V_314 , & V_3 -> V_65 ) ) {
F_242 ( L_107 ) ;
return - V_39 ;
}
if ( V_267 == 3 && ! strcasecmp ( V_268 [ 1 ] , L_108 ) ) {
V_28 = F_228 ( & V_268 [ 2 ] ) ;
if ( V_28 < 0 || V_3 -> V_28 != V_28 ) {
memset ( V_268 [ 2 ] , '0' , strlen ( V_268 [ 2 ] ) ) ;
return - V_39 ;
}
V_94 = F_229 ( V_3 , V_268 [ 2 ] ) ;
if ( V_94 )
return V_94 ;
if ( V_3 -> V_137 && V_3 -> V_137 -> V_266 )
V_94 = V_3 -> V_137 -> V_266 ( V_3 ) ;
return V_94 ;
}
if ( V_267 == 2 && ! strcasecmp ( V_268 [ 1 ] , L_109 ) ) {
if ( V_3 -> V_137 && V_3 -> V_137 -> V_316 ) {
V_94 = V_3 -> V_137 -> V_316 ( V_3 ) ;
if ( V_94 )
return V_94 ;
}
return F_231 ( V_3 ) ;
}
}
error:
F_242 ( L_110 ) ;
return - V_39 ;
}
static int F_283 ( struct V_34 * V_35 ,
T_8 V_317 , void * V_58 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
return V_317 ( V_35 , V_3 -> V_104 , V_3 -> V_100 , V_35 -> V_163 , V_58 ) ;
}
static void F_284 ( struct V_34 * V_35 , struct V_318 * V_319 )
{
struct V_2 * V_3 = V_35 -> V_238 ;
V_319 -> V_320 = V_158 ;
if ( V_3 -> V_52 != ( 1 << V_53 ) ) {
V_319 -> V_321 = V_3 -> V_52 ;
V_319 -> V_322 = V_3 -> V_52 ;
F_285 ( V_319 , V_3 -> V_52 ) ;
}
}
static int T_9 F_286 ( void )
{
int V_33 ;
V_33 = F_287 ( & V_323 ) ;
if ( V_33 < 0 )
F_219 ( L_111 , V_33 ) ;
return V_33 ;
}
static void T_10 F_288 ( void )
{
F_289 ( & V_323 ) ;
}
