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
V_59 -> V_87 = 0 ;
V_59 -> V_88 = 0 ;
V_59 -> V_89 = V_68 ? V_68 -> V_90 : 0 ;
V_59 -> V_91 = V_86 ? V_86 -> V_90 : 0 ;
V_59 -> V_92 = V_81 + V_3 -> V_93 ;
F_68 ( & V_59 -> V_94 ) ;
}
static struct V_8 * F_69 ( struct V_2 * V_3 ,
struct V_95 * V_96 )
{
return (struct V_8 * ) ( ( char * ) V_96 + V_3 -> V_97 ) ;
}
static struct V_95 * F_70 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return (struct V_95 * ) ( ( char * ) V_9 - V_3 -> V_97 ) ;
}
static T_1 * F_71 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return ( T_1 * ) F_72 ( ( unsigned long ) ( V_9 + 1 ) ,
F_73 ( F_3 ( V_3 ) ) + 1 ) ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_84 * V_59 ,
struct V_95 * V_96 )
{
struct V_98 * V_99 = F_75 ( V_59 -> V_68 , V_59 -> V_89 ) ;
struct V_98 * V_100 = F_75 ( V_59 -> V_86 , V_59 -> V_91 ) ;
struct V_8 * V_9 ;
T_1 * V_7 ;
int V_33 ;
V_9 = F_69 ( V_3 , V_96 ) ;
V_7 = F_71 ( V_3 , V_9 ) ;
V_9 -> V_12 = V_59 -> V_92 ;
V_9 -> V_59 = V_59 ;
F_76 ( & V_9 -> V_70 , 1 ) ;
F_77 ( & V_9 -> V_70 , V_99 -> V_101 , 1 << V_83 ,
V_99 -> V_102 + V_59 -> V_87 ) ;
F_76 ( & V_9 -> V_73 , 1 ) ;
F_77 ( & V_9 -> V_73 , V_100 -> V_101 , 1 << V_83 ,
V_100 -> V_102 + V_59 -> V_88 ) ;
V_59 -> V_87 += 1 << V_83 ;
if ( V_59 -> V_87 >= V_99 -> V_103 ) {
V_59 -> V_87 = 0 ;
V_59 -> V_89 ++ ;
}
V_59 -> V_88 += 1 << V_83 ;
if ( V_59 -> V_88 >= V_100 -> V_103 ) {
V_59 -> V_88 = 0 ;
V_59 -> V_91 ++ ;
}
if ( V_3 -> V_104 ) {
V_33 = V_3 -> V_104 -> V_105 ( V_3 , V_7 , V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
}
F_78 ( V_96 , & V_9 -> V_70 , & V_9 -> V_73 ,
1 << V_83 , V_7 ) ;
if ( F_53 ( V_59 -> V_68 ) == V_69 )
V_33 = F_79 ( V_96 ) ;
else
V_33 = F_80 ( V_96 ) ;
if ( ! V_33 && V_3 -> V_104 && V_3 -> V_104 -> V_106 )
V_33 = V_3 -> V_104 -> V_106 ( V_3 , V_7 , V_9 ) ;
return V_33 ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_84 * V_59 )
{
struct V_1 * V_107 = F_1 ( V_3 ) ;
unsigned V_108 = V_59 -> V_92 & ( V_3 -> V_54 - 1 ) ;
if ( ! V_107 -> V_96 )
V_107 -> V_96 = F_82 ( V_3 -> V_109 , V_110 ) ;
F_83 ( V_107 -> V_96 , V_3 -> V_6 [ V_108 ] ) ;
F_84 ( V_107 -> V_96 ,
V_111 | V_29 ,
V_112 , F_69 ( V_3 , V_107 -> V_96 ) ) ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_84 * V_59 )
{
struct V_1 * V_107 = F_1 ( V_3 ) ;
int V_33 ;
F_86 ( & V_59 -> V_113 , 1 ) ;
while( V_59 -> V_89 < V_59 -> V_68 -> V_114 &&
V_59 -> V_91 < V_59 -> V_86 -> V_114 ) {
F_81 ( V_3 , V_59 ) ;
F_87 ( & V_59 -> V_113 ) ;
V_33 = F_74 ( V_3 , V_59 , V_107 -> V_96 ) ;
switch ( V_33 ) {
case - V_115 :
F_88 ( & V_59 -> V_94 ) ;
F_89 ( & V_59 -> V_94 ) ;
case - V_116 :
V_107 -> V_96 = NULL ;
V_59 -> V_92 ++ ;
continue;
case 0 :
F_90 ( & V_59 -> V_113 ) ;
V_59 -> V_92 ++ ;
F_91 () ;
continue;
default:
F_90 ( & V_59 -> V_113 ) ;
return V_33 ;
}
}
return 0 ;
}
static struct V_85 * F_92 ( struct V_117 * V_118 , unsigned V_119 ,
unsigned * V_120 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
struct V_85 * V_121 ;
unsigned int V_122 = ( V_119 + V_123 - 1 ) >> V_124 ;
T_4 V_125 = V_110 | V_126 ;
unsigned V_64 , V_127 ;
struct V_128 * V_128 ;
V_121 = F_93 ( V_110 , V_122 , V_3 -> V_45 ) ;
if ( ! V_121 )
return NULL ;
F_94 ( V_118 , V_121 ) ;
* V_120 = 0 ;
for ( V_64 = 0 ; V_64 < V_122 ; V_64 ++ ) {
V_128 = F_82 ( V_3 -> V_129 , V_125 ) ;
if ( ! V_128 ) {
* V_120 = 1 ;
break;
}
V_125 = ( V_125 | V_130 ) & ~ V_131 ;
V_127 = ( V_119 > V_123 ) ? V_123 : V_119 ;
if ( ! F_95 ( V_121 , V_128 , V_127 , 0 ) ) {
F_96 ( V_128 , V_3 -> V_129 ) ;
break;
}
V_119 -= V_127 ;
}
if ( ! V_121 -> V_132 ) {
F_97 ( V_121 ) ;
return NULL ;
}
return V_121 ;
}
static void F_98 ( struct V_2 * V_3 , struct V_85 * V_121 )
{
unsigned int V_64 ;
struct V_98 * V_133 ;
F_99 (bv, clone, i) {
F_100 ( ! V_133 -> V_101 ) ;
F_96 ( V_133 -> V_101 , V_3 -> V_129 ) ;
V_133 -> V_101 = NULL ;
}
}
static struct V_117 * F_101 ( struct V_2 * V_3 ,
struct V_85 * V_85 , T_3 V_81 )
{
struct V_117 * V_118 ;
V_118 = F_82 ( V_3 -> V_134 , V_110 ) ;
V_118 -> V_3 = V_3 ;
V_118 -> V_135 = V_85 ;
V_118 -> V_81 = V_81 ;
V_118 -> error = 0 ;
V_118 -> V_136 = NULL ;
F_86 ( & V_118 -> V_137 , 0 ) ;
return V_118 ;
}
static void F_102 ( struct V_117 * V_118 )
{
F_87 ( & V_118 -> V_137 ) ;
}
static void F_103 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
struct V_85 * V_135 = V_118 -> V_135 ;
struct V_117 * V_136 = V_118 -> V_136 ;
int error = V_118 -> error ;
if ( ! F_104 ( & V_118 -> V_137 ) )
return;
F_96 ( V_118 , V_3 -> V_134 ) ;
if ( F_105 ( ! V_136 ) )
F_106 ( V_135 , error ) ;
else {
if ( error && ! V_136 -> error )
V_136 -> error = error ;
F_103 ( V_136 ) ;
}
}
static void F_107 ( struct V_85 * V_121 , int error )
{
struct V_117 * V_118 = V_121 -> V_138 ;
struct V_2 * V_3 = V_118 -> V_3 ;
unsigned V_139 = F_53 ( V_121 ) ;
if ( F_108 ( ! F_109 ( V_121 , V_140 ) && ! error ) )
error = - V_141 ;
if ( V_139 == V_69 )
F_98 ( V_3 , V_121 ) ;
F_97 ( V_121 ) ;
if ( V_139 == V_142 && ! error ) {
F_110 ( V_118 ) ;
return;
}
if ( F_108 ( error ) )
V_118 -> error = error ;
F_103 ( V_118 ) ;
}
static void F_94 ( struct V_117 * V_118 , struct V_85 * V_121 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
V_121 -> V_138 = V_118 ;
V_121 -> V_143 = F_107 ;
V_121 -> V_144 = V_3 -> V_145 -> V_146 ;
V_121 -> V_147 = V_118 -> V_135 -> V_147 ;
}
static int F_111 ( struct V_117 * V_118 , T_4 V_148 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
struct V_85 * V_135 = V_118 -> V_135 ;
struct V_85 * V_121 ;
V_121 = F_112 ( V_135 , V_148 , V_3 -> V_45 ) ;
if ( ! V_121 )
return 1 ;
F_102 ( V_118 ) ;
F_94 ( V_118 , V_121 ) ;
V_121 -> V_149 = V_3 -> V_150 + V_118 -> V_81 ;
F_113 ( V_121 ) ;
return 0 ;
}
static void F_114 ( struct V_117 * V_118 )
{
struct V_85 * V_121 = V_118 -> V_59 . V_86 ;
F_113 ( V_121 ) ;
}
static void F_115 ( struct V_151 * V_152 )
{
struct V_117 * V_118 = F_116 ( V_152 , struct V_117 , V_152 ) ;
if ( F_53 ( V_118 -> V_135 ) == V_142 ) {
F_102 ( V_118 ) ;
if ( F_111 ( V_118 , V_110 ) )
V_118 -> error = - V_44 ;
F_103 ( V_118 ) ;
} else
F_114 ( V_118 ) ;
}
static void F_117 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
F_118 ( & V_118 -> V_152 , F_115 ) ;
F_119 ( V_3 -> V_153 , & V_118 -> V_152 ) ;
}
static void F_120 ( struct V_117 * V_118 , int V_154 )
{
struct V_85 * V_121 = V_118 -> V_59 . V_86 ;
struct V_2 * V_3 = V_118 -> V_3 ;
if ( F_108 ( V_118 -> error < 0 ) ) {
F_98 ( V_3 , V_121 ) ;
F_97 ( V_121 ) ;
F_103 ( V_118 ) ;
return;
}
F_100 ( V_118 -> V_59 . V_91 < V_121 -> V_114 ) ;
V_121 -> V_149 = V_3 -> V_150 + V_118 -> V_81 ;
if ( V_154 )
F_117 ( V_118 ) ;
else
F_113 ( V_121 ) ;
}
static void F_121 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
struct V_85 * V_121 ;
struct V_117 * V_155 ;
int V_156 ;
unsigned V_120 = 0 ;
unsigned V_157 = V_118 -> V_135 -> V_132 ;
T_3 V_81 = V_118 -> V_81 ;
int V_33 ;
F_102 ( V_118 ) ;
F_67 ( V_3 , & V_118 -> V_59 , NULL , V_118 -> V_135 , V_81 ) ;
while ( V_157 ) {
V_121 = F_92 ( V_118 , V_157 , & V_120 ) ;
if ( F_108 ( ! V_121 ) ) {
V_118 -> error = - V_44 ;
break;
}
V_118 -> V_59 . V_86 = V_121 ;
V_118 -> V_59 . V_91 = 0 ;
V_157 -= V_121 -> V_132 ;
V_81 += F_122 ( V_121 ) ;
F_102 ( V_118 ) ;
V_33 = F_85 ( V_3 , & V_118 -> V_59 ) ;
if ( V_33 < 0 )
V_118 -> error = - V_141 ;
V_156 = F_104 ( & V_118 -> V_59 . V_113 ) ;
if ( V_156 ) {
F_120 ( V_118 , 0 ) ;
if ( F_108 ( V_33 < 0 ) )
break;
V_118 -> V_81 = V_81 ;
}
if ( F_108 ( V_120 ) )
F_123 ( V_158 , V_159 / 100 ) ;
if ( F_108 ( ! V_156 && V_157 ) ) {
V_155 = F_101 ( V_118 -> V_3 , V_118 -> V_135 ,
V_81 ) ;
F_102 ( V_155 ) ;
F_67 ( V_3 , & V_155 -> V_59 , NULL ,
V_118 -> V_135 , V_81 ) ;
V_155 -> V_59 . V_89 = V_118 -> V_59 . V_89 ;
V_155 -> V_59 . V_87 = V_118 -> V_59 . V_87 ;
if ( ! V_118 -> V_136 )
V_155 -> V_136 = V_118 ;
else {
V_155 -> V_136 = V_118 -> V_136 ;
F_102 ( V_118 -> V_136 ) ;
F_103 ( V_118 ) ;
}
V_118 = V_155 ;
}
}
F_103 ( V_118 ) ;
}
static void F_124 ( struct V_117 * V_118 )
{
F_103 ( V_118 ) ;
}
static void F_125 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
int V_33 = 0 ;
F_102 ( V_118 ) ;
F_67 ( V_3 , & V_118 -> V_59 , V_118 -> V_135 , V_118 -> V_135 ,
V_118 -> V_81 ) ;
V_33 = F_85 ( V_3 , & V_118 -> V_59 ) ;
if ( V_33 < 0 )
V_118 -> error = - V_141 ;
if ( F_104 ( & V_118 -> V_59 . V_113 ) )
F_124 ( V_118 ) ;
F_103 ( V_118 ) ;
}
static void V_112 ( struct V_160 * V_161 ,
int error )
{
struct V_8 * V_9 = V_161 -> V_57 ;
struct V_84 * V_59 = V_9 -> V_59 ;
struct V_117 * V_118 = F_116 ( V_59 , struct V_117 , V_59 ) ;
struct V_2 * V_3 = V_118 -> V_3 ;
if ( error == - V_116 ) {
F_126 ( & V_59 -> V_94 ) ;
return;
}
if ( ! error && V_3 -> V_104 && V_3 -> V_104 -> V_106 )
error = V_3 -> V_104 -> V_106 ( V_3 , F_71 ( V_3 , V_9 ) , V_9 ) ;
if ( error < 0 )
V_118 -> error = - V_141 ;
F_96 ( F_70 ( V_3 , V_9 ) , V_3 -> V_109 ) ;
if ( ! F_104 ( & V_59 -> V_113 ) )
return;
if ( F_53 ( V_118 -> V_135 ) == V_142 )
F_124 ( V_118 ) ;
else
F_120 ( V_118 , 1 ) ;
}
static void F_127 ( struct V_151 * V_152 )
{
struct V_117 * V_118 = F_116 ( V_152 , struct V_117 , V_152 ) ;
if ( F_53 ( V_118 -> V_135 ) == V_142 )
F_125 ( V_118 ) ;
else
F_121 ( V_118 ) ;
}
static void F_110 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = V_118 -> V_3 ;
F_118 ( & V_118 -> V_152 , F_127 ) ;
F_119 ( V_3 -> V_162 , & V_118 -> V_152 ) ;
}
static int F_128 ( T_1 * V_24 , char * V_163 , unsigned int V_119 )
{
char V_164 [ 3 ] ;
unsigned int V_64 ;
V_164 [ 2 ] = '\0' ;
for ( V_64 = 0 ; V_64 < V_119 ; V_64 ++ ) {
V_164 [ 0 ] = * V_163 ++ ;
V_164 [ 1 ] = * V_163 ++ ;
if ( F_129 ( V_164 , 16 , & V_24 [ V_64 ] ) )
return - V_39 ;
}
if ( * V_163 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_130 ( struct V_2 * V_3 )
{
unsigned V_64 ;
if ( ! V_3 -> V_6 )
return;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ )
if ( V_3 -> V_6 [ V_64 ] && ! F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
F_131 ( V_3 -> V_6 [ V_64 ] ) ;
V_3 -> V_6 [ V_64 ] = NULL ;
}
F_28 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
static int F_132 ( struct V_2 * V_3 , char * V_165 )
{
unsigned V_64 ;
int V_23 ;
V_3 -> V_6 = F_133 ( V_3 -> V_54 * sizeof( struct V_5 * ) ,
V_43 ) ;
if ( ! V_3 -> V_6 )
return - V_44 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_3 -> V_6 [ V_64 ] = F_134 ( V_165 , 0 , 0 ) ;
if ( F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
V_23 = F_26 ( V_3 -> V_6 [ V_64 ] ) ;
F_130 ( V_3 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_135 ( struct V_2 * V_3 )
{
unsigned V_56 ;
int V_23 = 0 , V_64 , V_33 ;
V_56 = ( V_3 -> V_25 - V_3 -> V_166 ) >> F_33 ( V_3 -> V_54 ) ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_33 = F_136 ( V_3 -> V_6 [ V_64 ] ,
V_3 -> V_24 + ( V_64 * V_56 ) ,
V_56 ) ;
if ( V_33 )
V_23 = V_33 ;
}
return V_23 ;
}
static int F_137 ( struct V_2 * V_3 , char * V_24 )
{
int V_33 = - V_39 ;
int V_167 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_167 >> 1 ) )
goto V_82;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_17 ) )
goto V_82;
if ( V_3 -> V_25 && F_128 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_82;
F_138 ( V_168 , & V_3 -> V_28 ) ;
V_33 = F_135 ( V_3 ) ;
V_82:
memset ( V_24 , '0' , V_167 ) ;
return V_33 ;
}
static int F_139 ( struct V_2 * V_3 )
{
F_140 ( V_168 , & V_3 -> V_28 ) ;
memset ( & V_3 -> V_24 , 0 , V_3 -> V_25 * sizeof( T_1 ) ) ;
return F_135 ( V_3 ) ;
}
static void F_141 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
struct V_1 * V_170 ;
int V_4 ;
V_35 -> V_169 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_153 )
F_142 ( V_3 -> V_153 ) ;
if ( V_3 -> V_162 )
F_142 ( V_3 -> V_162 ) ;
if ( V_3 -> V_4 )
F_143 (cpu) {
V_170 = F_144 ( V_3 -> V_4 , V_4 ) ;
if ( V_170 -> V_96 )
F_96 ( V_170 -> V_96 , V_3 -> V_109 ) ;
}
F_130 ( V_3 ) ;
if ( V_3 -> V_45 )
F_145 ( V_3 -> V_45 ) ;
if ( V_3 -> V_129 )
F_146 ( V_3 -> V_129 ) ;
if ( V_3 -> V_109 )
F_146 ( V_3 -> V_109 ) ;
if ( V_3 -> V_134 )
F_146 ( V_3 -> V_134 ) ;
if ( V_3 -> V_104 && V_3 -> V_104 -> V_171 )
V_3 -> V_104 -> V_171 ( V_3 ) ;
if ( V_3 -> V_145 )
F_147 ( V_35 , V_3 -> V_145 ) ;
if ( V_3 -> V_4 )
F_148 ( V_3 -> V_4 ) ;
F_23 ( V_3 -> V_37 ) ;
F_23 ( V_3 -> V_172 ) ;
F_23 ( V_3 ) ;
}
static int F_149 ( struct V_34 * V_35 ,
char * V_173 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
char * V_174 , * V_37 , * V_175 , * V_176 , * V_177 , * V_178 ;
char * V_179 = NULL ;
int V_180 = - V_39 ;
char V_181 ;
if ( strchr ( V_173 , '(' ) ) {
V_35 -> error = L_18 ;
return - V_39 ;
}
V_3 -> V_172 = F_150 ( V_173 , V_43 ) ;
if ( ! V_3 -> V_172 )
goto V_182;
V_174 = V_173 ;
V_178 = F_151 ( & V_174 , L_17 ) ;
V_37 = F_151 ( & V_178 , L_19 ) ;
if ( ! V_178 )
V_3 -> V_54 = 1 ;
else if ( sscanf ( V_178 , L_20 , & V_3 -> V_54 , & V_181 ) != 1 ||
! F_152 ( V_3 -> V_54 ) ) {
V_35 -> error = L_21 ;
return - V_39 ;
}
V_3 -> V_53 = V_3 -> V_54 ;
V_3 -> V_166 = 0 ;
V_3 -> V_37 = F_150 ( V_37 , V_43 ) ;
if ( ! V_3 -> V_37 )
goto V_182;
V_175 = F_151 ( & V_174 , L_17 ) ;
V_177 = F_151 ( & V_174 , L_17 ) ;
V_176 = F_151 ( & V_177 , L_19 ) ;
if ( V_174 )
F_153 ( L_22 ) ;
V_3 -> V_4 = F_154 ( sizeof( * ( V_3 -> V_4 ) ) ,
F_155 ( struct V_1 ) ) ;
if ( ! V_3 -> V_4 ) {
V_35 -> error = L_23 ;
goto V_182;
}
if ( ! V_175 || ( ! strcmp ( V_175 , L_24 ) && ! V_176 ) ) {
V_175 = L_25 ;
V_176 = L_24 ;
}
if ( strcmp ( V_175 , L_26 ) && ! V_176 ) {
V_35 -> error = L_27 ;
return - V_39 ;
}
V_179 = F_133 ( V_183 , V_43 ) ;
if ( ! V_179 )
goto V_182;
V_180 = snprintf ( V_179 , V_183 ,
L_28 , V_175 , V_37 ) ;
if ( V_180 < 0 ) {
F_28 ( V_179 ) ;
goto V_182;
}
V_180 = F_132 ( V_3 , V_179 ) ;
if ( V_180 < 0 ) {
V_35 -> error = L_29 ;
goto V_42;
}
V_3 -> V_10 = F_18 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_156 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_49 ) / sizeof( T_1 ) ) ) ;
else if ( V_176 ) {
F_153 ( L_30 ) ;
V_176 = NULL ;
}
if ( V_176 == NULL )
V_3 -> V_104 = NULL ;
else if ( strcmp ( V_176 , L_24 ) == 0 )
V_3 -> V_104 = & V_184 ;
else if ( strcmp ( V_176 , L_31 ) == 0 )
V_3 -> V_104 = & V_185 ;
else if ( strcmp ( V_176 , L_32 ) == 0 )
V_3 -> V_104 = & V_186 ;
else if ( strcmp ( V_176 , L_33 ) == 0 )
V_3 -> V_104 = & V_187 ;
else if ( strcmp ( V_176 , L_34 ) == 0 )
V_3 -> V_104 = & V_188 ;
else if ( strcmp ( V_176 , L_35 ) == 0 ) {
V_3 -> V_104 = & V_189 ;
if ( V_3 -> V_25 % V_3 -> V_53 ) {
V_3 -> V_53 ++ ;
V_3 -> V_166 = V_3 -> V_25 / V_3 -> V_53 ;
}
} else if ( strcmp ( V_176 , L_36 ) == 0 ) {
V_3 -> V_104 = & V_190 ;
V_3 -> V_53 += 2 ;
V_3 -> V_166 = V_3 -> V_10 + V_79 ;
} else {
V_180 = - V_39 ;
V_35 -> error = L_37 ;
goto V_42;
}
V_180 = F_137 ( V_3 , V_24 ) ;
if ( V_180 < 0 ) {
V_35 -> error = L_38 ;
goto V_42;
}
if ( V_3 -> V_104 && V_3 -> V_104 -> V_191 ) {
V_180 = V_3 -> V_104 -> V_191 ( V_3 , V_35 , V_177 ) ;
if ( V_180 < 0 ) {
V_35 -> error = L_39 ;
goto V_42;
}
}
if ( V_3 -> V_104 && V_3 -> V_104 -> V_192 ) {
V_180 = V_3 -> V_104 -> V_192 ( V_3 ) ;
if ( V_180 < 0 ) {
V_35 -> error = L_40 ;
goto V_42;
}
}
V_180 = 0 ;
V_42:
F_28 ( V_179 ) ;
return V_180 ;
V_182:
V_35 -> error = L_41 ;
return - V_44 ;
}
static int F_157 ( struct V_34 * V_35 , unsigned int V_193 , char * * V_194 )
{
struct V_2 * V_3 ;
unsigned int V_25 , V_195 ;
unsigned long long V_196 ;
int V_180 ;
struct V_197 V_198 ;
const char * V_199 ;
char V_181 ;
static struct V_200 V_201 [] = {
{ 0 , 1 , L_42 } ,
} ;
if ( V_193 < 5 ) {
V_35 -> error = L_43 ;
return - V_39 ;
}
V_25 = strlen ( V_194 [ 1 ] ) >> 1 ;
V_3 = F_27 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_43 ) ;
if ( ! V_3 ) {
V_35 -> error = L_44 ;
return - V_44 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_169 = V_3 ;
V_180 = F_149 ( V_35 , V_194 [ 0 ] , V_194 [ 1 ] ) ;
if ( V_180 < 0 )
goto V_42;
V_180 = - V_44 ;
V_3 -> V_134 = F_158 ( V_202 , V_203 ) ;
if ( ! V_3 -> V_134 ) {
V_35 -> error = L_45 ;
goto V_42;
}
V_3 -> V_97 = sizeof( struct V_95 ) ;
V_3 -> V_97 += F_159 ( F_3 ( V_3 ) ) ;
V_3 -> V_97 = F_72 ( V_3 -> V_97 , F_160 () ) ;
V_3 -> V_97 += F_73 ( F_3 ( V_3 ) ) &
~ ( F_160 () - 1 ) ;
V_3 -> V_109 = F_161 ( V_202 , V_3 -> V_97 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_109 ) {
V_35 -> error = L_46 ;
goto V_42;
}
V_3 -> V_129 = F_162 ( V_204 , 0 ) ;
if ( ! V_3 -> V_129 ) {
V_35 -> error = L_47 ;
goto V_42;
}
V_3 -> V_45 = F_163 ( V_202 , 0 ) ;
if ( ! V_3 -> V_45 ) {
V_35 -> error = L_48 ;
goto V_42;
}
V_180 = - V_39 ;
if ( sscanf ( V_194 [ 2 ] , L_49 , & V_196 , & V_181 ) != 1 ) {
V_35 -> error = L_50 ;
goto V_42;
}
V_3 -> V_93 = V_196 ;
if ( F_164 ( V_35 , V_194 [ 3 ] , F_165 ( V_35 -> V_205 ) , & V_3 -> V_145 ) ) {
V_35 -> error = L_51 ;
goto V_42;
}
if ( sscanf ( V_194 [ 4 ] , L_49 , & V_196 , & V_181 ) != 1 ) {
V_35 -> error = L_52 ;
goto V_42;
}
V_3 -> V_150 = V_196 ;
V_194 += 5 ;
V_193 -= 5 ;
if ( V_193 ) {
V_198 . V_193 = V_193 ;
V_198 . V_194 = V_194 ;
V_180 = F_166 ( V_201 , & V_198 , & V_195 , & V_35 -> error ) ;
if ( V_180 )
goto V_42;
V_199 = F_167 ( & V_198 ) ;
if ( V_195 == 1 && V_199 &&
! strcasecmp ( V_199 , L_53 ) )
V_35 -> V_206 = 1 ;
else if ( V_195 ) {
V_180 = - V_39 ;
V_35 -> error = L_54 ;
goto V_42;
}
}
V_180 = - V_44 ;
V_3 -> V_153 = F_168 ( L_55 , V_207 , 1 ) ;
if ( ! V_3 -> V_153 ) {
V_35 -> error = L_56 ;
goto V_42;
}
V_3 -> V_162 = F_168 ( L_57 ,
V_208 | V_207 , 1 ) ;
if ( ! V_3 -> V_162 ) {
V_35 -> error = L_58 ;
goto V_42;
}
V_35 -> V_209 = 1 ;
V_35 -> V_210 = true ;
return 0 ;
V_42:
F_141 ( V_35 ) ;
return V_180 ;
}
static int F_169 ( struct V_34 * V_35 , struct V_85 * V_85 )
{
struct V_117 * V_118 ;
struct V_2 * V_3 = V_35 -> V_169 ;
if ( F_108 ( V_85 -> V_147 & ( V_211 | V_212 ) ) ) {
V_85 -> V_144 = V_3 -> V_145 -> V_146 ;
if ( F_122 ( V_85 ) )
V_85 -> V_149 = V_3 -> V_150 + F_170 ( V_35 , V_85 -> V_149 ) ;
return V_213 ;
}
V_118 = F_101 ( V_3 , V_85 , F_170 ( V_35 , V_85 -> V_149 ) ) ;
if ( F_53 ( V_118 -> V_135 ) == V_142 ) {
if ( F_111 ( V_118 , V_214 ) )
F_117 ( V_118 ) ;
} else
F_110 ( V_118 ) ;
return V_215 ;
}
static void F_171 ( struct V_34 * V_35 , T_5 type ,
unsigned V_216 , char * V_217 , unsigned V_218 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
unsigned V_64 , V_219 = 0 ;
switch ( type ) {
case V_220 :
V_217 [ 0 ] = '\0' ;
break;
case V_221 :
F_172 ( L_59 , V_3 -> V_172 ) ;
if ( V_3 -> V_25 > 0 )
for ( V_64 = 0 ; V_64 < V_3 -> V_25 ; V_64 ++ )
F_172 ( L_60 , V_3 -> V_24 [ V_64 ] ) ;
else
F_172 ( L_17 ) ;
F_172 ( L_61 , ( unsigned long long ) V_3 -> V_93 ,
V_3 -> V_145 -> V_222 , ( unsigned long long ) V_3 -> V_150 ) ;
if ( V_35 -> V_206 )
F_172 ( L_62 ) ;
break;
}
}
static void F_173 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
F_138 ( V_223 , & V_3 -> V_28 ) ;
}
static int F_174 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
if ( ! F_175 ( V_168 , & V_3 -> V_28 ) ) {
F_176 ( L_63 ) ;
return - V_224 ;
}
return 0 ;
}
static void F_177 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
F_140 ( V_223 , & V_3 -> V_28 ) ;
}
static int F_178 ( struct V_34 * V_35 , unsigned V_193 , char * * V_194 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
int V_180 = - V_39 ;
if ( V_193 < 2 )
goto error;
if ( ! strcasecmp ( V_194 [ 0 ] , L_64 ) ) {
if ( ! F_175 ( V_223 , & V_3 -> V_28 ) ) {
F_153 ( L_65 ) ;
return - V_39 ;
}
if ( V_193 == 3 && ! strcasecmp ( V_194 [ 1 ] , L_66 ) ) {
V_180 = F_137 ( V_3 , V_194 [ 2 ] ) ;
if ( V_180 )
return V_180 ;
if ( V_3 -> V_104 && V_3 -> V_104 -> V_192 )
V_180 = V_3 -> V_104 -> V_192 ( V_3 ) ;
return V_180 ;
}
if ( V_193 == 2 && ! strcasecmp ( V_194 [ 1 ] , L_67 ) ) {
if ( V_3 -> V_104 && V_3 -> V_104 -> V_225 ) {
V_180 = V_3 -> V_104 -> V_225 ( V_3 ) ;
if ( V_180 )
return V_180 ;
}
return F_139 ( V_3 ) ;
}
}
error:
F_153 ( L_68 ) ;
return - V_39 ;
}
static int F_179 ( struct V_34 * V_35 , struct V_226 * V_227 ,
struct V_98 * V_228 , int V_229 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
struct V_230 * V_231 = F_180 ( V_3 -> V_145 -> V_146 ) ;
if ( ! V_231 -> V_232 )
return V_229 ;
V_227 -> V_144 = V_3 -> V_145 -> V_146 ;
V_227 -> V_149 = V_3 -> V_150 + F_170 ( V_35 , V_227 -> V_149 ) ;
return F_181 ( V_229 , V_231 -> V_232 ( V_231 , V_227 , V_228 ) ) ;
}
static int F_182 ( struct V_34 * V_35 ,
T_6 V_233 , void * V_57 )
{
struct V_2 * V_3 = V_35 -> V_169 ;
return V_233 ( V_35 , V_3 -> V_145 , V_3 -> V_150 , V_35 -> V_127 , V_57 ) ;
}
static int T_7 F_183 ( void )
{
int V_33 ;
V_203 = F_184 ( V_117 , 0 ) ;
if ( ! V_203 )
return - V_44 ;
V_33 = F_185 ( & V_234 ) ;
if ( V_33 < 0 ) {
F_176 ( L_69 , V_33 ) ;
F_186 ( V_203 ) ;
}
return V_33 ;
}
static void T_8 F_187 ( void )
{
F_188 ( & V_234 ) ;
F_186 ( V_203 ) ;
}
