static void F_1 ( struct V_1 * V_2 , int V_3 ,
const T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 V_9 ;
struct V_10 * V_11 , V_12 [ 5 ] ;
int V_13 ;
F_2 ( V_2 -> V_14 == NULL ) ;
F_3 ( & V_9 ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_11 = & V_12 [ 0 ] ;
V_3 &= 0xff ;
V_11 -> V_15 = & V_3 ;
V_11 -> V_16 = 9 ;
V_11 -> V_17 = 2 ;
if ( V_7 > 1 && V_5 == 0 ) {
V_11 -> V_16 = 10 ;
V_3 <<= 1 ;
}
F_4 ( V_11 , & V_9 ) ;
if ( V_5 ) {
V_11 ++ ;
V_11 -> V_15 = V_4 ;
V_11 -> V_17 = V_5 ;
V_11 -> V_16 = 9 ;
F_4 ( V_11 , & V_9 ) ;
}
if ( V_7 ) {
V_11 ++ ;
V_11 -> V_18 = V_6 ;
V_11 -> V_17 = V_7 ;
F_4 ( V_11 , & V_9 ) ;
}
V_13 = F_5 ( V_2 -> V_14 , & V_9 ) ;
if ( V_13 < 0 )
F_6 ( & V_2 -> V_14 -> V_19 , L_1 , V_13 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , NULL , 0 , NULL , 0 ) ;
}
static inline void F_8 ( struct V_1 * V_2 ,
int V_20 , const T_1 * V_21 , int V_17 )
{
F_1 ( V_2 , V_20 , V_21 , V_17 , NULL , 0 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
int V_20 , T_1 * V_21 , int V_17 )
{
F_1 ( V_2 , V_20 , NULL , 0 , V_21 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_22 )
{
V_2 -> V_23 = F_11 ( V_22 ) ;
V_2 -> V_24 = V_25 + V_2 -> V_23 ;
}
static void V_23 ( struct V_1 * V_2 )
{
unsigned long V_26 = V_2 -> V_24 - V_25 ;
if ( ( long ) V_26 > 0 && V_26 <= V_2 -> V_23 ) {
F_12 ( V_27 ) ;
F_13 ( V_26 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_28 )
{
int V_3 ;
if ( V_28 )
V_3 = V_29 ;
else
V_3 = V_30 ;
V_23 ( V_2 ) ;
F_7 ( V_2 , V_3 ) ;
F_10 ( V_2 , 120 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_31 )
{
int V_3 = V_31 ? V_32 : V_33 ;
F_7 ( V_2 , V_3 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_34 ;
int V_31 ;
F_9 ( V_2 , V_35 ,
( T_1 * ) & V_34 , 4 ) ;
V_34 = F_17 ( V_34 ) ;
V_31 = ( V_34 & ( 1 << 17 ) ) && ( V_34 & ( 1 << 10 ) ) ;
F_6 ( & V_2 -> V_14 -> V_19 ,
L_2 ,
V_31 ? L_3 : L_4 , V_34 ) ;
return V_31 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_36 , V_2 -> V_37 , 3 ) ;
F_6 ( & V_2 -> V_14 -> V_19 , L_5 ,
V_2 -> V_37 [ 0 ] ,
V_2 -> V_37 [ 1 ] ,
V_2 -> V_37 [ 2 ] ) ;
switch ( V_2 -> V_37 [ 0 ] ) {
case 0x10 :
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = L_6 ;
V_2 -> V_41 = 1 ;
V_2 -> V_42 = 1 ;
break;
case 0x29 :
V_2 -> V_38 = V_43 ;
V_2 -> V_40 = L_7 ;
break;
case 0x45 :
V_2 -> V_38 = V_44 ;
V_2 -> V_40 = L_8 ;
break;
case 0x83 :
V_2 -> V_38 = V_45 ;
V_2 -> V_40 = L_9 ;
break;
default:
V_2 -> V_40 = L_10 ;
F_19 ( & V_2 -> V_14 -> V_19 , L_11 ) ;
return - V_46 ;
}
V_2 -> V_47 = V_2 -> V_37 [ 1 ] ;
F_20 ( & V_2 -> V_14 -> V_19 , L_12 ,
V_2 -> V_40 , V_2 -> V_47 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_48 )
{
T_3 V_49 ;
F_9 ( V_2 , V_50 , ( T_1 * ) & V_49 , 1 ) ;
if ( V_48 ) {
V_49 |= V_51 |
V_52 ;
} else {
V_49 &= ~ ( V_51 |
V_52 ) ;
}
V_49 |= 1 << 8 ;
F_8 ( V_2 , V_53 , ( T_1 * ) & V_49 , 2 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned V_54 )
{
T_3 V_55 ;
V_2 -> V_56 = V_54 ;
if ( ! V_2 -> V_31 )
return;
V_55 = 0 ;
F_9 ( V_2 , V_57 , ( T_1 * ) & V_55 , 1 ) ;
V_55 &= ~ 3 ;
V_55 |= ( 1 << 8 ) | ( V_54 & 3 ) ;
F_8 ( V_2 , V_58 , ( T_1 * ) & V_55 , 2 ) ;
}
static unsigned F_23 ( struct V_1 * V_2 )
{
return V_2 -> V_56 ;
}
static unsigned F_24 ( struct V_1 * V_2 )
{
T_1 V_55 ;
F_9 ( V_2 , V_57 , & V_55 , 1 ) ;
return V_55 & 3 ;
}
static void F_25 ( struct V_1 * V_2 , int V_59 )
{
int V_60 ;
V_60 = V_59 | ( 1 << 8 ) ;
F_8 ( V_2 , V_61 , ( T_1 * ) & V_60 , 2 ) ;
if ( V_59 )
F_21 ( V_2 , 1 ) ;
else
F_21 ( V_2 , 0 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_60 ;
F_9 ( V_2 , V_62 , & V_60 , 1 ) ;
return V_60 ;
}
static int F_27 ( struct V_63 * V_19 )
{
struct V_1 * V_2 = F_28 ( & V_19 -> V_19 ) ;
int V_59 ;
F_6 ( & V_2 -> V_14 -> V_19 , L_13 , V_64 ) ;
if ( V_19 -> V_65 . V_66 == V_67 &&
V_19 -> V_65 . V_68 == V_67 )
V_59 = V_19 -> V_65 . V_69 ;
else
V_59 = 0 ;
if ( V_2 -> V_41 )
F_25 ( V_2 , V_59 ) ;
else
return - V_46 ;
return 0 ;
}
static int F_29 ( struct V_63 * V_19 )
{
struct V_1 * V_2 = F_28 ( & V_19 -> V_19 ) ;
F_6 ( & V_19 -> V_19 , L_13 , V_64 ) ;
if ( ! V_2 -> V_41 )
return - V_46 ;
if ( V_19 -> V_65 . V_66 == V_67 &&
V_19 -> V_65 . V_68 == V_67 ) {
if ( V_2 -> V_41 )
return F_26 ( V_2 ) ;
else
return V_19 -> V_65 . V_69 ;
}
return 0 ;
}
static int F_30 ( struct V_63 * V_19 )
{
struct V_1 * V_2 = F_28 ( & V_19 -> V_19 ) ;
int V_13 ;
F_31 ( & V_2 -> V_70 ) ;
V_13 = F_27 ( V_19 ) ;
F_32 ( & V_2 -> V_70 ) ;
return V_13 ;
}
static int F_33 ( struct V_63 * V_19 )
{
struct V_1 * V_2 = F_28 ( & V_19 -> V_19 ) ;
int V_13 ;
F_31 ( & V_2 -> V_70 ) ;
V_13 = F_29 ( V_19 ) ;
F_32 ( & V_2 -> V_70 ) ;
return V_13 ;
}
static T_4 F_34 ( struct V_71 * V_19 ,
struct V_72 * V_73 ,
char * V_21 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
const char * V_74 ;
int V_54 ;
int V_17 ;
if ( ! V_2 -> V_42 )
V_54 = 0 ;
else
V_54 = F_23 ( V_2 ) ;
V_74 = L_10 ;
if ( V_54 >= 0 && V_54 < F_35 ( V_75 ) )
V_74 = V_75 [ V_54 ] ;
V_17 = snprintf ( V_21 , V_76 , L_13 , V_74 ) ;
return V_17 < V_76 - 1 ? V_17 : V_76 - 1 ;
}
static T_4 F_36 ( struct V_71 * V_19 ,
struct V_72 * V_73 ,
const char * V_21 , T_5 V_77 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
int V_78 ;
for ( V_78 = 0 ; V_78 < F_35 ( V_75 ) ; V_78 ++ ) {
const char * V_74 = V_75 [ V_78 ] ;
int V_79 = strlen ( V_74 ) ;
if ( V_77 > 0 && V_21 [ V_77 - 1 ] == '\n' )
V_77 -- ;
if ( V_77 != V_79 )
continue;
if ( strncmp ( V_21 , V_74 , V_79 ) == 0 )
break;
}
if ( V_78 == F_35 ( V_75 ) )
return - V_80 ;
if ( ! V_2 -> V_42 && V_78 != 0 )
return - V_80 ;
F_31 ( & V_2 -> V_70 ) ;
F_22 ( V_2 , V_78 ) ;
F_32 ( & V_2 -> V_70 ) ;
return V_77 ;
}
static T_4 F_37 ( struct V_71 * V_19 ,
struct V_72 * V_73 ,
char * V_21 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
int V_17 ;
int V_78 ;
if ( ! V_2 -> V_42 )
return snprintf ( V_21 , V_76 , L_13 , V_75 [ 0 ] ) ;
for ( V_78 = 0 , V_17 = 0 ;
V_17 < V_76 && V_78 < F_35 ( V_75 ) ; V_78 ++ )
V_17 += snprintf ( & V_21 [ V_17 ] , V_76 - V_17 , L_14 ,
V_78 ? L_15 : L_3 , V_75 [ V_78 ] ,
V_78 == F_35 ( V_75 ) - 1 ? L_16 : L_3 ) ;
return V_17 < V_76 ? V_17 : V_76 - 1 ;
}
static int F_38 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
struct V_81 * V_83 = V_2 -> V_83 ;
int V_13 ;
if ( F_40 ( V_82 ) )
return 0 ;
V_13 = V_83 -> V_84 . V_85 -> V_86 ( V_83 , V_82 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static void F_41 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
struct V_81 * V_83 = V_2 -> V_83 ;
if ( ! F_40 ( V_82 ) )
return;
V_83 -> V_84 . V_85 -> V_87 ( V_83 , V_82 ) ;
}
static int F_42 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
struct V_81 * V_83 = V_2 -> V_83 ;
int V_13 ;
F_6 ( & V_2 -> V_14 -> V_19 , L_13 , V_64 ) ;
V_83 -> V_84 . V_85 -> V_88 ( V_83 , & V_2 -> V_89 ) ;
if ( V_2 -> V_90 > 0 )
V_83 -> V_84 . V_85 -> V_91 ( V_83 , V_2 -> V_90 ) ;
V_13 = V_83 -> V_84 . V_85 -> V_48 ( V_83 ) ;
if ( V_13 ) {
F_43 ( L_17 , V_64 ) ;
return V_13 ;
}
F_44 ( 50 ) ;
if ( F_45 ( V_2 -> V_92 ) )
F_46 ( V_2 -> V_92 , 1 ) ;
if ( V_2 -> V_31 ) {
F_6 ( & V_2 -> V_14 -> V_19 , L_18 ) ;
return 0 ;
}
F_44 ( 120 ) ;
F_14 ( V_2 , 0 ) ;
V_2 -> V_31 = 1 ;
F_47 ( 5000 , 10000 ) ;
F_15 ( V_2 , 1 ) ;
F_22 ( V_2 , V_2 -> V_56 ) ;
return F_27 ( V_2 -> V_93 ) ;
}
static void F_48 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
struct V_81 * V_83 = V_2 -> V_83 ;
F_6 ( V_82 -> V_19 , L_13 , V_64 ) ;
if ( ! V_2 -> V_31 )
return;
F_15 ( V_2 , 0 ) ;
F_14 ( V_2 , 1 ) ;
V_2 -> V_31 = 0 ;
F_44 ( 50 ) ;
if ( F_45 ( V_2 -> V_92 ) )
F_46 ( V_2 -> V_92 , 0 ) ;
F_44 ( 100 ) ;
V_83 -> V_84 . V_85 -> V_94 ( V_83 ) ;
}
static int F_49 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
int V_13 ;
F_6 ( V_82 -> V_19 , L_13 , V_64 ) ;
if ( ! F_40 ( V_82 ) )
return - V_46 ;
if ( F_50 ( V_82 ) )
return 0 ;
F_31 ( & V_2 -> V_70 ) ;
V_13 = F_42 ( V_82 ) ;
F_32 ( & V_2 -> V_70 ) ;
if ( V_13 )
return V_13 ;
V_82 -> V_95 = V_96 ;
return 0 ;
}
static void F_51 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
F_6 ( V_82 -> V_19 , L_13 , V_64 ) ;
if ( ! F_50 ( V_82 ) )
return;
F_31 ( & V_2 -> V_70 ) ;
F_48 ( V_82 ) ;
F_32 ( & V_2 -> V_70 ) ;
V_82 -> V_95 = V_97 ;
}
static void F_52 ( struct V_81 * V_82 ,
struct V_98 * V_89 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
struct V_81 * V_83 = V_2 -> V_83 ;
V_2 -> V_89 = * V_89 ;
V_82 -> V_99 . V_89 = * V_89 ;
V_83 -> V_84 . V_85 -> V_88 ( V_83 , V_89 ) ;
}
static void F_53 ( struct V_81 * V_82 ,
struct V_98 * V_89 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
* V_89 = V_2 -> V_89 ;
}
static int F_54 ( struct V_81 * V_82 ,
struct V_98 * V_89 )
{
struct V_1 * V_2 = F_39 ( V_82 ) ;
struct V_81 * V_83 = V_2 -> V_83 ;
return V_83 -> V_84 . V_85 -> V_100 ( V_83 , V_89 ) ;
}
static int F_55 ( struct V_101 * V_14 )
{
const struct V_102 * V_103 ;
struct V_1 * V_2 = F_28 ( & V_14 -> V_19 ) ;
struct V_81 * V_82 , * V_83 ;
V_103 = F_56 ( & V_14 -> V_19 ) ;
V_2 -> V_92 = V_103 -> V_92 ;
V_83 = F_57 ( V_103 -> V_104 ) ;
if ( V_83 == NULL ) {
F_19 ( & V_14 -> V_19 , L_19 ,
V_103 -> V_104 ) ;
return - V_105 ;
}
V_2 -> V_83 = V_83 ;
V_2 -> V_90 = V_103 -> V_90 ;
V_82 = & V_2 -> V_82 ;
V_82 -> V_40 = V_103 -> V_40 ;
return 0 ;
}
static int F_58 ( struct V_101 * V_14 )
{
struct V_1 * V_2 = F_28 ( & V_14 -> V_19 ) ;
struct V_106 * V_107 = V_14 -> V_19 . V_108 ;
V_2 -> V_92 = F_59 ( V_107 , L_20 , 0 ) ;
V_2 -> V_83 = F_60 ( V_107 ) ;
if ( F_61 ( V_2 -> V_83 ) ) {
F_19 ( & V_14 -> V_19 , L_21 ) ;
return F_62 ( V_2 -> V_83 ) ;
}
return 0 ;
}
static int F_63 ( struct V_101 * V_14 )
{
struct V_1 * V_2 ;
struct V_81 * V_82 ;
struct V_63 * V_109 ;
int V_110 , V_69 ;
struct V_111 V_65 ;
int V_13 ;
F_6 ( & V_14 -> V_19 , L_13 , V_64 ) ;
V_14 -> V_54 = V_112 ;
V_2 = F_64 ( & V_14 -> V_19 , sizeof( * V_2 ) , V_113 ) ;
if ( V_2 == NULL )
return - V_114 ;
F_65 ( & V_14 -> V_19 , V_2 ) ;
V_2 -> V_14 = V_14 ;
F_66 ( & V_2 -> V_70 ) ;
if ( F_56 ( & V_14 -> V_19 ) ) {
V_13 = F_55 ( V_14 ) ;
if ( V_13 )
return V_13 ;
} else if ( V_14 -> V_19 . V_108 ) {
V_13 = F_58 ( V_14 ) ;
if ( V_13 )
return V_13 ;
} else {
F_19 ( & V_14 -> V_19 , L_22 ) ;
return - V_46 ;
}
if ( F_45 ( V_2 -> V_92 ) ) {
V_13 = F_67 ( & V_14 -> V_19 , V_2 -> V_92 ,
V_115 , L_23 ) ;
if ( V_13 )
goto V_116;
}
if ( F_45 ( V_2 -> V_92 ) )
F_46 ( V_2 -> V_92 , 1 ) ;
F_47 ( 5000 , 10000 ) ;
V_2 -> V_31 = F_16 ( V_2 ) ;
V_13 = F_18 ( V_2 ) ;
if ( ! V_2 -> V_31 && F_45 ( V_2 -> V_92 ) )
F_46 ( V_2 -> V_92 , 0 ) ;
if ( V_13 ) {
F_19 ( & V_14 -> V_19 , L_24 , V_64 ) ;
goto V_117;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_67 ;
V_65 . type = V_118 ;
V_109 = F_68 ( L_6 , & V_2 -> V_14 -> V_19 ,
V_2 , & V_119 , & V_65 ) ;
if ( F_61 ( V_109 ) ) {
V_13 = F_62 ( V_109 ) ;
goto V_120;
}
V_2 -> V_93 = V_109 ;
if ( V_2 -> V_42 ) {
V_13 = F_69 ( & V_109 -> V_19 . V_121 , & V_122 ) ;
if ( V_13 ) {
F_19 ( & V_109 -> V_19 ,
L_25 , V_64 ) ;
goto V_123;
}
V_2 -> V_56 = F_24 ( V_2 ) ;
}
V_110 = 255 ;
if ( V_2 -> V_41 )
V_69 = F_26 ( V_2 ) ;
else
V_69 = 0 ;
V_109 -> V_65 . V_110 = V_110 ;
V_109 -> V_65 . V_69 = V_69 ;
F_27 ( V_109 ) ;
V_2 -> V_89 = V_124 ;
V_82 = & V_2 -> V_82 ;
V_82 -> V_19 = & V_14 -> V_19 ;
V_82 -> V_125 = & V_126 ;
V_82 -> type = V_127 ;
V_82 -> V_128 = V_129 ;
V_82 -> V_99 . V_89 = V_2 -> V_89 ;
V_13 = F_70 ( V_82 ) ;
if ( V_13 ) {
F_19 ( & V_14 -> V_19 , L_26 ) ;
goto V_130;
}
return 0 ;
V_130:
F_71 ( & V_109 -> V_19 . V_121 , & V_122 ) ;
V_123:
F_72 ( V_109 ) ;
V_120:
V_117:
V_116:
F_73 ( V_2 -> V_83 ) ;
return V_13 ;
}
static int F_74 ( struct V_101 * V_14 )
{
struct V_1 * V_2 = F_28 ( & V_14 -> V_19 ) ;
struct V_81 * V_82 = & V_2 -> V_82 ;
struct V_81 * V_83 = V_2 -> V_83 ;
F_6 ( & V_2 -> V_14 -> V_19 , L_13 , V_64 ) ;
F_71 ( & V_2 -> V_93 -> V_19 . V_121 , & V_122 ) ;
F_72 ( V_2 -> V_93 ) ;
F_75 ( V_82 ) ;
F_51 ( V_82 ) ;
F_41 ( V_82 ) ;
F_73 ( V_83 ) ;
return 0 ;
}
