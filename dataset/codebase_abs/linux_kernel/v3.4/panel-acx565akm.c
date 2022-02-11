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
F_9 ( V_2 , V_35 , ( T_1 * ) & V_34 , 4 ) ;
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
V_2 -> V_37 [ 0 ] , V_2 -> V_37 [ 1 ] , V_2 -> V_37 [ 2 ] ) ;
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
int V_13 ;
int V_59 ;
F_6 ( & V_2 -> V_14 -> V_19 , L_13 , V_64 ) ;
F_29 ( & V_2 -> V_65 ) ;
if ( V_19 -> V_66 . V_67 == V_68 &&
V_19 -> V_66 . V_69 == V_68 )
V_59 = V_19 -> V_66 . V_70 ;
else
V_59 = 0 ;
V_13 = 0 ;
if ( V_2 -> V_41 )
F_25 ( V_2 , V_59 ) ;
else if ( V_2 -> V_71 -> V_72 )
V_13 = V_2 -> V_71 -> V_72 ( V_2 -> V_71 , V_59 ) ;
else
V_13 = - V_46 ;
F_30 ( & V_2 -> V_65 ) ;
return V_13 ;
}
static int F_31 ( struct V_63 * V_19 )
{
struct V_1 * V_2 = F_28 ( & V_19 -> V_19 ) ;
F_6 ( & V_19 -> V_19 , L_13 , V_64 ) ;
if ( ! V_2 -> V_41 && V_2 -> V_71 -> V_72 == NULL )
return - V_46 ;
if ( V_19 -> V_66 . V_67 == V_68 &&
V_19 -> V_66 . V_69 == V_68 ) {
if ( V_2 -> V_41 )
return F_26 ( V_2 ) ;
else
return V_19 -> V_66 . V_70 ;
}
return 0 ;
}
static T_4 F_32 ( struct V_73 * V_19 ,
struct V_74 * V_75 ,
char * V_21 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
const char * V_76 ;
int V_54 ;
int V_17 ;
if ( ! V_2 -> V_42 )
V_54 = 0 ;
else
V_54 = F_23 ( V_2 ) ;
V_76 = L_10 ;
if ( V_54 >= 0 && V_54 < F_33 ( V_77 ) )
V_76 = V_77 [ V_54 ] ;
V_17 = snprintf ( V_21 , V_78 , L_13 , V_76 ) ;
return V_17 < V_78 - 1 ? V_17 : V_78 - 1 ;
}
static T_4 F_34 ( struct V_73 * V_19 ,
struct V_74 * V_75 ,
const char * V_21 , T_5 V_79 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < F_33 ( V_77 ) ; V_80 ++ ) {
const char * V_76 = V_77 [ V_80 ] ;
int V_81 = strlen ( V_76 ) ;
if ( V_79 > 0 && V_21 [ V_79 - 1 ] == '\n' )
V_79 -- ;
if ( V_79 != V_81 )
continue;
if ( strncmp ( V_21 , V_76 , V_81 ) == 0 )
break;
}
if ( V_80 == F_33 ( V_77 ) )
return - V_82 ;
if ( ! V_2 -> V_42 && V_80 != 0 )
return - V_82 ;
F_29 ( & V_2 -> V_65 ) ;
F_22 ( V_2 , V_80 ) ;
F_30 ( & V_2 -> V_65 ) ;
return V_79 ;
}
static T_4 F_35 ( struct V_73 * V_19 ,
struct V_74 * V_75 ,
char * V_21 )
{
struct V_1 * V_2 = F_28 ( V_19 ) ;
int V_17 ;
int V_80 ;
if ( ! V_2 -> V_42 )
return snprintf ( V_21 , V_78 , L_13 , V_77 [ 0 ] ) ;
for ( V_80 = 0 , V_17 = 0 ;
V_17 < V_78 && V_80 < F_33 ( V_77 ) ; V_80 ++ )
V_17 += snprintf ( & V_21 [ V_17 ] , V_78 - V_17 , L_14 ,
V_80 ? L_15 : L_3 , V_77 [ V_80 ] ,
V_80 == F_33 ( V_77 ) - 1 ? L_16 : L_3 ) ;
return V_17 < V_78 ? V_17 : V_78 - 1 ;
}
static int F_36 ( struct V_83 * V_71 )
{
return 16 ;
}
static int F_37 ( struct V_83 * V_71 )
{
int V_13 ;
struct V_1 * V_2 = & V_84 ;
struct V_63 * V_85 ;
int V_86 , V_70 ;
struct V_87 V_66 ;
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
V_71 -> V_88 . V_89 = V_90 | V_91 |
V_92 ;
V_71 -> V_88 . V_93 = V_94 ;
if ( V_71 -> V_95 )
V_71 -> V_95 ( V_71 ) ;
F_38 ( 5 ) ;
V_2 -> V_31 = F_16 ( V_2 ) ;
V_13 = F_18 ( V_2 ) ;
if ( V_13 ) {
F_19 ( & V_71 -> V_19 , L_17 , V_64 ) ;
if ( ! V_2 -> V_31 && V_71 -> V_96 )
V_71 -> V_96 ( V_71 ) ;
return V_13 ;
}
F_29 ( & V_84 . V_65 ) ;
V_84 . V_71 = V_71 ;
F_30 ( & V_84 . V_65 ) ;
if ( ! V_2 -> V_31 ) {
if ( V_71 -> V_96 )
V_71 -> V_96 ( V_71 ) ;
}
V_66 . V_67 = V_68 ;
V_66 . V_69 = V_68 ;
V_66 . type = V_97 ;
V_85 = F_39 ( L_6 , & V_2 -> V_14 -> V_19 ,
V_2 , & V_98 , & V_66 ) ;
V_2 -> V_99 = V_85 ;
if ( V_2 -> V_42 ) {
V_13 = F_40 ( & V_85 -> V_19 . V_100 , & V_101 ) ;
if ( V_13 ) {
F_19 ( & V_85 -> V_19 ,
L_18 , V_64 ) ;
F_41 ( V_85 ) ;
return V_13 ;
}
V_2 -> V_56 = F_24 ( V_2 ) ;
}
if ( V_2 -> V_41 )
V_86 = 255 ;
else
V_86 = V_71 -> V_102 ;
if ( V_2 -> V_41 )
V_70 = F_26 ( V_2 ) ;
else if ( V_71 -> V_103 )
V_70 = V_71 -> V_103 ( V_71 ) ;
else
V_70 = 0 ;
V_85 -> V_66 . V_86 = V_86 ;
V_85 -> V_66 . V_70 = V_70 ;
F_27 ( V_85 ) ;
return 0 ;
}
static void F_42 ( struct V_83 * V_71 )
{
struct V_1 * V_2 = & V_84 ;
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
F_43 ( & V_2 -> V_99 -> V_19 . V_100 , & V_101 ) ;
F_41 ( V_2 -> V_99 ) ;
F_29 ( & V_84 . V_65 ) ;
V_84 . V_71 = NULL ;
F_30 ( & V_84 . V_65 ) ;
}
static int F_44 ( struct V_83 * V_71 )
{
struct V_1 * V_2 = & V_84 ;
int V_13 ;
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
if ( V_71 -> V_104 == V_105 )
return 0 ;
F_29 ( & V_2 -> V_65 ) ;
V_13 = F_45 ( V_71 ) ;
if ( V_13 ) {
F_46 ( L_19 , V_64 ) ;
goto V_106;
}
F_38 ( 50 ) ;
if ( V_71 -> V_95 ) {
V_13 = V_71 -> V_95 ( V_71 ) ;
if ( V_13 )
goto V_107;
}
if ( V_2 -> V_31 ) {
F_6 ( & V_2 -> V_14 -> V_19 , L_20 ) ;
F_30 ( & V_2 -> V_65 ) ;
return 0 ;
}
F_38 ( 120 ) ;
F_14 ( V_2 , 0 ) ;
V_2 -> V_31 = 1 ;
F_38 ( 5 ) ;
F_15 ( V_2 , 1 ) ;
F_22 ( V_2 , V_2 -> V_56 ) ;
F_30 ( & V_2 -> V_65 ) ;
return F_27 ( V_2 -> V_99 ) ;
V_107:
F_47 ( V_71 ) ;
V_106:
F_30 ( & V_2 -> V_65 ) ;
return V_13 ;
}
static void F_48 ( struct V_83 * V_71 )
{
struct V_1 * V_2 = & V_84 ;
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
if ( V_71 -> V_104 != V_105 )
return;
F_29 ( & V_2 -> V_65 ) ;
if ( ! V_2 -> V_31 ) {
F_30 ( & V_2 -> V_65 ) ;
return;
}
F_15 ( V_2 , 0 ) ;
F_14 ( V_2 , 1 ) ;
V_2 -> V_31 = 0 ;
F_38 ( 50 ) ;
if ( V_71 -> V_96 )
V_71 -> V_96 ( V_71 ) ;
F_38 ( 100 ) ;
F_47 ( V_71 ) ;
F_30 ( & V_2 -> V_65 ) ;
}
static int F_49 ( struct V_83 * V_71 )
{
int V_13 ;
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
V_13 = F_44 ( V_71 ) ;
if ( V_13 )
return V_13 ;
V_71 -> V_104 = V_105 ;
return 0 ;
}
static void F_50 ( struct V_83 * V_71 )
{
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
F_48 ( V_71 ) ;
V_71 -> V_104 = V_108 ;
}
static int F_51 ( struct V_83 * V_71 )
{
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
F_48 ( V_71 ) ;
V_71 -> V_104 = V_109 ;
return 0 ;
}
static int F_52 ( struct V_83 * V_71 )
{
int V_13 ;
F_6 ( & V_71 -> V_19 , L_13 , V_64 ) ;
V_13 = F_44 ( V_71 ) ;
if ( V_13 )
return V_13 ;
V_71 -> V_104 = V_105 ;
return 0 ;
}
static void F_53 ( struct V_83 * V_71 ,
struct V_110 * V_93 )
{
int V_13 ;
if ( V_71 -> V_104 == V_105 )
F_47 ( V_71 ) ;
V_71 -> V_88 . V_93 = * V_93 ;
if ( V_71 -> V_104 == V_105 ) {
V_13 = F_45 ( V_71 ) ;
if ( V_13 )
F_19 ( & V_71 -> V_19 , L_21 , V_64 ) ;
}
}
static void F_54 ( struct V_83 * V_71 ,
struct V_110 * V_93 )
{
* V_93 = V_71 -> V_88 . V_93 ;
}
static int F_55 ( struct V_83 * V_71 ,
struct V_110 * V_93 )
{
return 0 ;
}
static int F_56 ( struct V_111 * V_14 )
{
struct V_1 * V_2 = & V_84 ;
F_6 ( & V_14 -> V_19 , L_13 , V_64 ) ;
V_14 -> V_54 = V_112 ;
V_2 -> V_14 = V_14 ;
F_57 ( & V_2 -> V_65 ) ;
F_58 ( & V_14 -> V_19 , V_2 ) ;
F_59 ( & V_113 ) ;
return 0 ;
}
static int F_60 ( struct V_111 * V_14 )
{
struct V_1 * V_2 = F_28 ( & V_14 -> V_19 ) ;
F_6 ( & V_2 -> V_14 -> V_19 , L_13 , V_64 ) ;
F_61 ( & V_113 ) ;
return 0 ;
}
