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
static int F_84 ( struct V_2 * V_3 ,
struct V_82 * V_57 )
{
int V_31 ;
F_85 ( & V_57 -> V_107 , 1 ) ;
while ( V_57 -> V_85 . V_108 && V_57 -> V_87 . V_108 ) {
F_80 ( V_3 , V_57 ) ;
F_86 ( & V_57 -> V_107 ) ;
V_31 = F_72 ( V_3 , V_57 , V_57 -> V_92 ) ;
switch ( V_31 ) {
case - V_109 :
F_87 ( & V_57 -> V_90 ) ;
F_88 ( & V_57 -> V_90 ) ;
case - V_110 :
V_57 -> V_92 = NULL ;
V_57 -> V_88 ++ ;
continue;
case 0 :
F_89 ( & V_57 -> V_107 ) ;
V_57 -> V_88 ++ ;
F_90 () ;
continue;
default:
F_89 ( & V_57 -> V_107 ) ;
return V_31 ;
}
}
return 0 ;
}
static struct V_83 * F_91 ( struct V_111 * V_112 , unsigned V_113 ,
unsigned * V_114 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
struct V_83 * V_115 ;
unsigned int V_116 = ( V_113 + V_117 - 1 ) >> V_118 ;
T_4 V_119 = V_104 | V_120 ;
unsigned V_62 , V_121 ;
struct V_122 * V_122 ;
V_115 = F_92 ( V_104 , V_116 , V_3 -> V_43 ) ;
if ( ! V_115 )
return NULL ;
F_93 ( V_112 , V_115 ) ;
* V_114 = 0 ;
for ( V_62 = 0 ; V_62 < V_116 ; V_62 ++ ) {
V_122 = F_81 ( V_3 -> V_123 , V_119 ) ;
if ( ! V_122 ) {
* V_114 = 1 ;
break;
}
V_119 = ( V_119 | V_124 ) & ~ V_125 ;
V_121 = ( V_113 > V_117 ) ? V_117 : V_113 ;
if ( ! F_94 ( V_115 , V_122 , V_121 , 0 ) ) {
F_95 ( V_122 , V_3 -> V_123 ) ;
break;
}
V_113 -= V_121 ;
}
if ( ! V_115 -> V_86 . V_108 ) {
F_96 ( V_115 ) ;
return NULL ;
}
return V_115 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_83 * V_115 )
{
unsigned int V_62 ;
struct V_94 * V_126 ;
F_98 (bv, clone, i) {
F_99 ( ! V_126 -> V_97 ) ;
F_95 ( V_126 -> V_97 , V_3 -> V_123 ) ;
V_126 -> V_97 = NULL ;
}
}
static struct V_111 * F_100 ( struct V_2 * V_3 ,
struct V_83 * V_83 , T_3 V_79 )
{
struct V_111 * V_112 ;
V_112 = F_81 ( V_3 -> V_127 , V_104 ) ;
V_112 -> V_3 = V_3 ;
V_112 -> V_128 = V_83 ;
V_112 -> V_79 = V_79 ;
V_112 -> error = 0 ;
V_112 -> V_129 = NULL ;
V_112 -> V_57 . V_92 = NULL ;
F_85 ( & V_112 -> V_130 , 0 ) ;
return V_112 ;
}
static void F_101 ( struct V_111 * V_112 )
{
F_86 ( & V_112 -> V_130 ) ;
}
static void F_102 ( struct V_111 * V_112 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
struct V_83 * V_128 = V_112 -> V_128 ;
struct V_111 * V_129 = V_112 -> V_129 ;
int error = V_112 -> error ;
if ( ! F_103 ( & V_112 -> V_130 ) )
return;
if ( V_112 -> V_57 . V_92 )
F_95 ( V_112 -> V_57 . V_92 , V_3 -> V_103 ) ;
F_95 ( V_112 , V_3 -> V_127 ) ;
if ( F_104 ( ! V_129 ) )
F_105 ( V_128 , error ) ;
else {
if ( error && ! V_129 -> error )
V_129 -> error = error ;
F_102 ( V_129 ) ;
}
}
static void F_106 ( struct V_83 * V_115 , int error )
{
struct V_111 * V_112 = V_115 -> V_131 ;
struct V_2 * V_3 = V_112 -> V_3 ;
unsigned V_132 = F_51 ( V_115 ) ;
if ( F_107 ( ! F_108 ( V_115 , V_133 ) && ! error ) )
error = - V_134 ;
if ( V_132 == V_67 )
F_97 ( V_3 , V_115 ) ;
F_96 ( V_115 ) ;
if ( V_132 == V_135 && ! error ) {
F_109 ( V_112 ) ;
return;
}
if ( F_107 ( error ) )
V_112 -> error = error ;
F_102 ( V_112 ) ;
}
static void F_93 ( struct V_111 * V_112 , struct V_83 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
V_115 -> V_131 = V_112 ;
V_115 -> V_136 = F_106 ;
V_115 -> V_137 = V_3 -> V_138 -> V_139 ;
V_115 -> V_140 = V_112 -> V_128 -> V_140 ;
}
static int F_110 ( struct V_111 * V_112 , T_4 V_141 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
struct V_83 * V_128 = V_112 -> V_128 ;
struct V_83 * V_115 ;
V_115 = F_111 ( V_128 , V_141 , V_3 -> V_43 ) ;
if ( ! V_115 )
return 1 ;
F_101 ( V_112 ) ;
F_93 ( V_112 , V_115 ) ;
V_115 -> V_86 . V_142 = V_3 -> V_143 + V_112 -> V_79 ;
F_112 ( V_115 ) ;
return 0 ;
}
static void F_113 ( struct V_111 * V_112 )
{
struct V_83 * V_115 = V_112 -> V_57 . V_84 ;
F_112 ( V_115 ) ;
}
static void F_114 ( struct V_144 * V_145 )
{
struct V_111 * V_112 = F_115 ( V_145 , struct V_111 , V_145 ) ;
if ( F_51 ( V_112 -> V_128 ) == V_135 ) {
F_101 ( V_112 ) ;
if ( F_110 ( V_112 , V_104 ) )
V_112 -> error = - V_42 ;
F_102 ( V_112 ) ;
} else
F_113 ( V_112 ) ;
}
static void F_116 ( struct V_111 * V_112 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
F_117 ( & V_112 -> V_145 , F_114 ) ;
F_118 ( V_3 -> V_146 , & V_112 -> V_145 ) ;
}
static void F_119 ( struct V_111 * V_112 , int V_147 )
{
struct V_83 * V_115 = V_112 -> V_57 . V_84 ;
struct V_2 * V_3 = V_112 -> V_3 ;
if ( F_107 ( V_112 -> error < 0 ) ) {
F_97 ( V_3 , V_115 ) ;
F_96 ( V_115 ) ;
F_102 ( V_112 ) ;
return;
}
F_99 ( V_112 -> V_57 . V_87 . V_108 ) ;
V_115 -> V_86 . V_142 = V_3 -> V_143 + V_112 -> V_79 ;
if ( V_147 )
F_116 ( V_112 ) ;
else
F_112 ( V_115 ) ;
}
static void F_120 ( struct V_111 * V_112 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
struct V_83 * V_115 ;
struct V_111 * V_148 ;
int V_149 ;
unsigned V_114 = 0 ;
unsigned V_150 = V_112 -> V_128 -> V_86 . V_108 ;
T_3 V_79 = V_112 -> V_79 ;
int V_31 ;
F_101 ( V_112 ) ;
F_65 ( V_3 , & V_112 -> V_57 , NULL , V_112 -> V_128 , V_79 ) ;
while ( V_150 ) {
V_115 = F_91 ( V_112 , V_150 , & V_114 ) ;
if ( F_107 ( ! V_115 ) ) {
V_112 -> error = - V_42 ;
break;
}
V_112 -> V_57 . V_84 = V_115 ;
V_112 -> V_57 . V_87 = V_115 -> V_86 ;
V_150 -= V_115 -> V_86 . V_108 ;
V_79 += F_121 ( V_115 ) ;
F_101 ( V_112 ) ;
V_31 = F_84 ( V_3 , & V_112 -> V_57 ) ;
if ( V_31 < 0 )
V_112 -> error = - V_134 ;
V_149 = F_103 ( & V_112 -> V_57 . V_107 ) ;
if ( V_149 ) {
F_119 ( V_112 , 0 ) ;
if ( F_107 ( V_31 < 0 ) )
break;
V_112 -> V_79 = V_79 ;
}
if ( F_107 ( V_114 ) )
F_122 ( V_151 , V_152 / 100 ) ;
if ( F_107 ( ! V_149 && V_150 ) ) {
V_148 = F_100 ( V_112 -> V_3 , V_112 -> V_128 ,
V_79 ) ;
F_101 ( V_148 ) ;
F_65 ( V_3 , & V_148 -> V_57 , NULL ,
V_112 -> V_128 , V_79 ) ;
V_148 -> V_57 . V_85 = V_112 -> V_57 . V_85 ;
if ( ! V_112 -> V_129 )
V_148 -> V_129 = V_112 ;
else {
V_148 -> V_129 = V_112 -> V_129 ;
F_101 ( V_112 -> V_129 ) ;
F_102 ( V_112 ) ;
}
V_112 = V_148 ;
}
}
F_102 ( V_112 ) ;
}
static void F_123 ( struct V_111 * V_112 )
{
F_102 ( V_112 ) ;
}
static void F_124 ( struct V_111 * V_112 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
int V_31 = 0 ;
F_101 ( V_112 ) ;
F_65 ( V_3 , & V_112 -> V_57 , V_112 -> V_128 , V_112 -> V_128 ,
V_112 -> V_79 ) ;
V_31 = F_84 ( V_3 , & V_112 -> V_57 ) ;
if ( V_31 < 0 )
V_112 -> error = - V_134 ;
if ( F_103 ( & V_112 -> V_57 . V_107 ) )
F_123 ( V_112 ) ;
F_102 ( V_112 ) ;
}
static void V_106 ( struct V_153 * V_154 ,
int error )
{
struct V_6 * V_7 = V_154 -> V_55 ;
struct V_82 * V_57 = V_7 -> V_57 ;
struct V_111 * V_112 = F_115 ( V_57 , struct V_111 , V_57 ) ;
struct V_2 * V_3 = V_112 -> V_3 ;
if ( error == - V_110 ) {
F_125 ( & V_57 -> V_90 ) ;
return;
}
if ( ! error && V_3 -> V_99 && V_3 -> V_99 -> V_101 )
error = V_3 -> V_99 -> V_101 ( V_3 , F_69 ( V_3 , V_7 ) , V_7 ) ;
if ( error < 0 )
V_112 -> error = - V_134 ;
F_95 ( F_68 ( V_3 , V_7 ) , V_3 -> V_103 ) ;
if ( ! F_103 ( & V_57 -> V_107 ) )
return;
if ( F_51 ( V_112 -> V_128 ) == V_135 )
F_123 ( V_112 ) ;
else
F_119 ( V_112 , 1 ) ;
}
static void F_126 ( struct V_144 * V_145 )
{
struct V_111 * V_112 = F_115 ( V_145 , struct V_111 , V_145 ) ;
if ( F_51 ( V_112 -> V_128 ) == V_135 )
F_124 ( V_112 ) ;
else
F_120 ( V_112 ) ;
}
static void F_109 ( struct V_111 * V_112 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
F_117 ( & V_112 -> V_145 , F_126 ) ;
F_118 ( V_3 -> V_155 , & V_112 -> V_145 ) ;
}
static int F_127 ( T_1 * V_22 , char * V_156 , unsigned int V_113 )
{
char V_157 [ 3 ] ;
unsigned int V_62 ;
V_157 [ 2 ] = '\0' ;
for ( V_62 = 0 ; V_62 < V_113 ; V_62 ++ ) {
V_157 [ 0 ] = * V_156 ++ ;
V_157 [ 1 ] = * V_156 ++ ;
if ( F_128 ( V_157 , 16 , & V_22 [ V_62 ] ) )
return - V_37 ;
}
if ( * V_156 != '\0' )
return - V_37 ;
return 0 ;
}
static void F_129 ( struct V_2 * V_3 )
{
unsigned V_62 ;
if ( ! V_3 -> V_4 )
return;
for ( V_62 = 0 ; V_62 < V_3 -> V_52 ; V_62 ++ )
if ( V_3 -> V_4 [ V_62 ] && ! F_14 ( V_3 -> V_4 [ V_62 ] ) ) {
F_130 ( V_3 -> V_4 [ V_62 ] ) ;
V_3 -> V_4 [ V_62 ] = NULL ;
}
F_26 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
}
static int F_131 ( struct V_2 * V_3 , char * V_158 )
{
unsigned V_62 ;
int V_21 ;
V_3 -> V_4 = F_132 ( V_3 -> V_52 * sizeof( struct V_1 * ) ,
V_41 ) ;
if ( ! V_3 -> V_4 )
return - V_42 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_52 ; V_62 ++ ) {
V_3 -> V_4 [ V_62 ] = F_133 ( V_158 , 0 , 0 ) ;
if ( F_14 ( V_3 -> V_4 [ V_62 ] ) ) {
V_21 = F_24 ( V_3 -> V_4 [ V_62 ] ) ;
F_129 ( V_3 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_134 ( struct V_2 * V_3 )
{
unsigned V_54 ;
int V_21 = 0 , V_62 , V_31 ;
V_54 = ( V_3 -> V_23 - V_3 -> V_159 ) >> F_31 ( V_3 -> V_52 ) ;
for ( V_62 = 0 ; V_62 < V_3 -> V_52 ; V_62 ++ ) {
V_31 = F_135 ( V_3 -> V_4 [ V_62 ] ,
V_3 -> V_22 + ( V_62 * V_54 ) ,
V_54 ) ;
if ( V_31 )
V_21 = V_31 ;
}
return V_21 ;
}
static int F_136 ( struct V_2 * V_3 , char * V_22 )
{
int V_31 = - V_37 ;
int V_160 = strlen ( V_22 ) ;
if ( V_3 -> V_23 != ( V_160 >> 1 ) )
goto V_80;
if ( ! V_3 -> V_23 && strcmp ( V_22 , L_17 ) )
goto V_80;
if ( V_3 -> V_23 && F_127 ( V_3 -> V_22 , V_22 , V_3 -> V_23 ) < 0 )
goto V_80;
F_137 ( V_161 , & V_3 -> V_26 ) ;
V_31 = F_134 ( V_3 ) ;
V_80:
memset ( V_22 , '0' , V_160 ) ;
return V_31 ;
}
static int F_138 ( struct V_2 * V_3 )
{
F_139 ( V_161 , & V_3 -> V_26 ) ;
memset ( & V_3 -> V_22 , 0 , V_3 -> V_23 * sizeof( T_1 ) ) ;
return F_134 ( V_3 ) ;
}
static void F_140 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
V_33 -> V_162 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_146 )
F_141 ( V_3 -> V_146 ) ;
if ( V_3 -> V_155 )
F_141 ( V_3 -> V_155 ) ;
F_129 ( V_3 ) ;
if ( V_3 -> V_43 )
F_142 ( V_3 -> V_43 ) ;
if ( V_3 -> V_123 )
F_143 ( V_3 -> V_123 ) ;
if ( V_3 -> V_103 )
F_143 ( V_3 -> V_103 ) ;
if ( V_3 -> V_127 )
F_143 ( V_3 -> V_127 ) ;
if ( V_3 -> V_99 && V_3 -> V_99 -> V_163 )
V_3 -> V_99 -> V_163 ( V_3 ) ;
if ( V_3 -> V_138 )
F_144 ( V_33 , V_3 -> V_138 ) ;
F_21 ( V_3 -> V_35 ) ;
F_21 ( V_3 -> V_164 ) ;
F_21 ( V_3 ) ;
}
static int F_145 ( struct V_32 * V_33 ,
char * V_165 , char * V_22 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
char * V_166 , * V_35 , * V_167 , * V_168 , * V_169 , * V_170 ;
char * V_171 = NULL ;
int V_172 = - V_37 ;
char V_173 ;
if ( strchr ( V_165 , '(' ) ) {
V_33 -> error = L_18 ;
return - V_37 ;
}
V_3 -> V_164 = F_146 ( V_165 , V_41 ) ;
if ( ! V_3 -> V_164 )
goto V_174;
V_166 = V_165 ;
V_170 = F_147 ( & V_166 , L_17 ) ;
V_35 = F_147 ( & V_170 , L_19 ) ;
if ( ! V_170 )
V_3 -> V_52 = 1 ;
else if ( sscanf ( V_170 , L_20 , & V_3 -> V_52 , & V_173 ) != 1 ||
! F_148 ( V_3 -> V_52 ) ) {
V_33 -> error = L_21 ;
return - V_37 ;
}
V_3 -> V_51 = V_3 -> V_52 ;
V_3 -> V_159 = 0 ;
V_3 -> V_35 = F_146 ( V_35 , V_41 ) ;
if ( ! V_3 -> V_35 )
goto V_174;
V_167 = F_147 ( & V_166 , L_17 ) ;
V_169 = F_147 ( & V_166 , L_17 ) ;
V_168 = F_147 ( & V_169 , L_19 ) ;
if ( V_166 )
F_149 ( L_22 ) ;
if ( ! V_167 || ( ! strcmp ( V_167 , L_23 ) && ! V_168 ) ) {
V_167 = L_24 ;
V_168 = L_23 ;
}
if ( strcmp ( V_167 , L_25 ) && ! V_168 ) {
V_33 -> error = L_26 ;
return - V_37 ;
}
V_171 = F_132 ( V_175 , V_41 ) ;
if ( ! V_171 )
goto V_174;
V_172 = snprintf ( V_171 , V_175 ,
L_27 , V_167 , V_35 ) ;
if ( V_172 < 0 ) {
F_26 ( V_171 ) ;
goto V_174;
}
V_172 = F_131 ( V_3 , V_171 ) ;
if ( V_172 < 0 ) {
V_33 -> error = L_28 ;
goto V_40;
}
V_3 -> V_8 = F_16 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_8 )
V_3 -> V_8 = F_150 ( V_3 -> V_8 ,
( unsigned int ) ( sizeof( V_47 ) / sizeof( T_1 ) ) ) ;
else if ( V_168 ) {
F_149 ( L_29 ) ;
V_168 = NULL ;
}
if ( V_168 == NULL )
V_3 -> V_99 = NULL ;
else if ( strcmp ( V_168 , L_23 ) == 0 )
V_3 -> V_99 = & V_176 ;
else if ( strcmp ( V_168 , L_30 ) == 0 )
V_3 -> V_99 = & V_177 ;
else if ( strcmp ( V_168 , L_31 ) == 0 )
V_3 -> V_99 = & V_178 ;
else if ( strcmp ( V_168 , L_32 ) == 0 )
V_3 -> V_99 = & V_179 ;
else if ( strcmp ( V_168 , L_33 ) == 0 )
V_3 -> V_99 = & V_180 ;
else if ( strcmp ( V_168 , L_34 ) == 0 ) {
V_3 -> V_99 = & V_181 ;
if ( V_3 -> V_23 % V_3 -> V_51 ) {
V_3 -> V_51 ++ ;
V_3 -> V_159 = V_3 -> V_23 / V_3 -> V_51 ;
}
} else if ( strcmp ( V_168 , L_35 ) == 0 ) {
V_3 -> V_99 = & V_182 ;
V_3 -> V_51 += 2 ;
V_3 -> V_159 = V_3 -> V_8 + V_77 ;
} else {
V_172 = - V_37 ;
V_33 -> error = L_36 ;
goto V_40;
}
V_172 = F_136 ( V_3 , V_22 ) ;
if ( V_172 < 0 ) {
V_33 -> error = L_37 ;
goto V_40;
}
if ( V_3 -> V_99 && V_3 -> V_99 -> V_183 ) {
V_172 = V_3 -> V_99 -> V_183 ( V_3 , V_33 , V_169 ) ;
if ( V_172 < 0 ) {
V_33 -> error = L_38 ;
goto V_40;
}
}
if ( V_3 -> V_99 && V_3 -> V_99 -> V_184 ) {
V_172 = V_3 -> V_99 -> V_184 ( V_3 ) ;
if ( V_172 < 0 ) {
V_33 -> error = L_39 ;
goto V_40;
}
}
V_172 = 0 ;
V_40:
F_26 ( V_171 ) ;
return V_172 ;
V_174:
V_33 -> error = L_40 ;
return - V_42 ;
}
static int F_151 ( struct V_32 * V_33 , unsigned int V_185 , char * * V_186 )
{
struct V_2 * V_3 ;
unsigned int V_23 , V_187 ;
unsigned long long V_188 ;
int V_172 ;
struct V_189 V_190 ;
const char * V_191 ;
char V_173 ;
static struct V_192 V_193 [] = {
{ 0 , 1 , L_41 } ,
} ;
if ( V_185 < 5 ) {
V_33 -> error = L_42 ;
return - V_37 ;
}
V_23 = strlen ( V_186 [ 1 ] ) >> 1 ;
V_3 = F_25 ( sizeof( * V_3 ) + V_23 * sizeof( T_1 ) , V_41 ) ;
if ( ! V_3 ) {
V_33 -> error = L_43 ;
return - V_42 ;
}
V_3 -> V_23 = V_23 ;
V_33 -> V_162 = V_3 ;
V_172 = F_145 ( V_33 , V_186 [ 0 ] , V_186 [ 1 ] ) ;
if ( V_172 < 0 )
goto V_40;
V_172 = - V_42 ;
V_3 -> V_127 = F_152 ( V_194 , V_195 ) ;
if ( ! V_3 -> V_127 ) {
V_33 -> error = L_44 ;
goto V_40;
}
V_3 -> V_93 = sizeof( struct V_91 ) ;
V_3 -> V_93 += F_153 ( F_1 ( V_3 ) ) ;
V_3 -> V_93 = F_70 ( V_3 -> V_93 , F_154 () ) ;
V_3 -> V_93 += F_71 ( F_1 ( V_3 ) ) &
~ ( F_154 () - 1 ) ;
V_3 -> V_103 = F_155 ( V_194 , V_3 -> V_93 +
sizeof( struct V_6 ) + V_3 -> V_8 ) ;
if ( ! V_3 -> V_103 ) {
V_33 -> error = L_45 ;
goto V_40;
}
V_3 -> V_123 = F_156 ( V_196 , 0 ) ;
if ( ! V_3 -> V_123 ) {
V_33 -> error = L_46 ;
goto V_40;
}
V_3 -> V_43 = F_157 ( V_194 , 0 ) ;
if ( ! V_3 -> V_43 ) {
V_33 -> error = L_47 ;
goto V_40;
}
V_172 = - V_37 ;
if ( sscanf ( V_186 [ 2 ] , L_48 , & V_188 , & V_173 ) != 1 ) {
V_33 -> error = L_49 ;
goto V_40;
}
V_3 -> V_89 = V_188 ;
if ( F_158 ( V_33 , V_186 [ 3 ] , F_159 ( V_33 -> V_197 ) , & V_3 -> V_138 ) ) {
V_33 -> error = L_50 ;
goto V_40;
}
if ( sscanf ( V_186 [ 4 ] , L_48 , & V_188 , & V_173 ) != 1 ) {
V_33 -> error = L_51 ;
goto V_40;
}
V_3 -> V_143 = V_188 ;
V_186 += 5 ;
V_185 -= 5 ;
if ( V_185 ) {
V_190 . V_185 = V_185 ;
V_190 . V_186 = V_186 ;
V_172 = F_160 ( V_193 , & V_190 , & V_187 , & V_33 -> error ) ;
if ( V_172 )
goto V_40;
V_191 = F_161 ( & V_190 ) ;
if ( V_187 == 1 && V_191 &&
! strcasecmp ( V_191 , L_52 ) )
V_33 -> V_198 = 1 ;
else if ( V_187 ) {
V_172 = - V_37 ;
V_33 -> error = L_53 ;
goto V_40;
}
}
V_172 = - V_42 ;
V_3 -> V_146 = F_162 ( L_54 , V_199 , 1 ) ;
if ( ! V_3 -> V_146 ) {
V_33 -> error = L_55 ;
goto V_40;
}
V_3 -> V_155 = F_162 ( L_56 ,
V_200 | V_199 , 1 ) ;
if ( ! V_3 -> V_155 ) {
V_33 -> error = L_57 ;
goto V_40;
}
V_33 -> V_201 = 1 ;
V_33 -> V_202 = true ;
return 0 ;
V_40:
F_140 ( V_33 ) ;
return V_172 ;
}
static int F_163 ( struct V_32 * V_33 , struct V_83 * V_83 )
{
struct V_111 * V_112 ;
struct V_2 * V_3 = V_33 -> V_162 ;
if ( F_107 ( V_83 -> V_140 & ( V_203 | V_204 ) ) ) {
V_83 -> V_137 = V_3 -> V_138 -> V_139 ;
if ( F_121 ( V_83 ) )
V_83 -> V_86 . V_142 = V_3 -> V_143 +
F_164 ( V_33 , V_83 -> V_86 . V_142 ) ;
return V_205 ;
}
V_112 = F_100 ( V_3 , V_83 , F_164 ( V_33 , V_83 -> V_86 . V_142 ) ) ;
if ( F_51 ( V_112 -> V_128 ) == V_135 ) {
if ( F_110 ( V_112 , V_206 ) )
F_116 ( V_112 ) ;
} else
F_109 ( V_112 ) ;
return V_207 ;
}
static void F_165 ( struct V_32 * V_33 , T_5 type ,
unsigned V_208 , char * V_209 , unsigned V_210 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
unsigned V_62 , V_211 = 0 ;
switch ( type ) {
case V_212 :
V_209 [ 0 ] = '\0' ;
break;
case V_213 :
F_166 ( L_58 , V_3 -> V_164 ) ;
if ( V_3 -> V_23 > 0 )
for ( V_62 = 0 ; V_62 < V_3 -> V_23 ; V_62 ++ )
F_166 ( L_59 , V_3 -> V_22 [ V_62 ] ) ;
else
F_166 ( L_17 ) ;
F_166 ( L_60 , ( unsigned long long ) V_3 -> V_89 ,
V_3 -> V_138 -> V_214 , ( unsigned long long ) V_3 -> V_143 ) ;
if ( V_33 -> V_198 )
F_166 ( L_61 ) ;
break;
}
}
static void F_167 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
F_137 ( V_215 , & V_3 -> V_26 ) ;
}
static int F_168 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
if ( ! F_169 ( V_161 , & V_3 -> V_26 ) ) {
F_170 ( L_62 ) ;
return - V_216 ;
}
return 0 ;
}
static void F_171 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
F_139 ( V_215 , & V_3 -> V_26 ) ;
}
static int F_172 ( struct V_32 * V_33 , unsigned V_185 , char * * V_186 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
int V_172 = - V_37 ;
if ( V_185 < 2 )
goto error;
if ( ! strcasecmp ( V_186 [ 0 ] , L_63 ) ) {
if ( ! F_169 ( V_215 , & V_3 -> V_26 ) ) {
F_149 ( L_64 ) ;
return - V_37 ;
}
if ( V_185 == 3 && ! strcasecmp ( V_186 [ 1 ] , L_65 ) ) {
V_172 = F_136 ( V_3 , V_186 [ 2 ] ) ;
if ( V_172 )
return V_172 ;
if ( V_3 -> V_99 && V_3 -> V_99 -> V_184 )
V_172 = V_3 -> V_99 -> V_184 ( V_3 ) ;
return V_172 ;
}
if ( V_185 == 2 && ! strcasecmp ( V_186 [ 1 ] , L_66 ) ) {
if ( V_3 -> V_99 && V_3 -> V_99 -> V_217 ) {
V_172 = V_3 -> V_99 -> V_217 ( V_3 ) ;
if ( V_172 )
return V_172 ;
}
return F_138 ( V_3 ) ;
}
}
error:
F_149 ( L_67 ) ;
return - V_37 ;
}
static int F_173 ( struct V_32 * V_33 , struct V_218 * V_219 ,
struct V_94 * V_220 , int V_221 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
struct V_222 * V_223 = F_174 ( V_3 -> V_138 -> V_139 ) ;
if ( ! V_223 -> V_224 )
return V_221 ;
V_219 -> V_137 = V_3 -> V_138 -> V_139 ;
V_219 -> V_142 = V_3 -> V_143 + F_164 ( V_33 , V_219 -> V_142 ) ;
return F_175 ( V_221 , V_223 -> V_224 ( V_223 , V_219 , V_220 ) ) ;
}
static int F_176 ( struct V_32 * V_33 ,
T_6 V_225 , void * V_55 )
{
struct V_2 * V_3 = V_33 -> V_162 ;
return V_225 ( V_33 , V_3 -> V_138 , V_3 -> V_143 , V_33 -> V_121 , V_55 ) ;
}
static int T_7 F_177 ( void )
{
int V_31 ;
V_195 = F_178 ( V_111 , 0 ) ;
if ( ! V_195 )
return - V_42 ;
V_31 = F_179 ( & V_226 ) ;
if ( V_31 < 0 ) {
F_170 ( L_68 , V_31 ) ;
F_180 ( V_195 ) ;
}
return V_31 ;
}
static void T_8 F_181 ( void )
{
F_182 ( & V_226 ) ;
F_180 ( V_195 ) ;
}
