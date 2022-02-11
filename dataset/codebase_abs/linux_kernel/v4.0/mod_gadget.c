static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
F_5 ( V_11 , L_1 , F_6 ( V_9 ) ) ;
V_4 -> V_12 . V_5 = V_5 ;
F_7 ( & V_2 -> V_13 , & V_4 -> V_12 ) ;
}
static void F_8 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_8 * V_9 = V_17 -> V_9 ;
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_3 * V_4 = F_10 ( V_17 ) ;
V_4 -> V_12 . V_18 = V_17 -> V_18 ;
F_1 ( V_2 , V_4 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_16 * V_17 = F_12 ( V_4 ) ;
struct V_19 * V_12 = & V_4 -> V_12 ;
V_12 -> V_18 = 0 ;
V_12 -> V_5 = - V_20 ;
F_13 ( V_9 , V_17 , F_8 ,
V_12 -> V_21 , V_12 -> V_22 , V_12 -> V_23 , - 1 ) ;
F_14 ( V_9 ) ;
F_5 ( V_11 , L_2 ,
F_6 ( V_9 ) ,
V_12 -> V_22 ) ;
}
static int F_15 ( struct V_16 * V_17 , int V_24 )
{
struct V_3 * V_4 = F_10 ( V_17 ) ;
struct V_19 * V_12 = & V_4 -> V_12 ;
struct V_8 * V_9 = V_17 -> V_9 ;
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_25 V_26 ;
int V_27 = 0 ;
V_26 = F_16 ( V_9 ) ;
if ( V_24 ) {
F_17 ( V_12 -> V_28 ) ;
V_27 = F_18 ( & V_7 -> V_29 , V_12 , V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
V_17 -> V_30 = V_12 -> V_30 ;
} else {
F_19 ( & V_7 -> V_29 , V_12 , V_26 ) ;
}
return V_27 ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
struct V_1 * V_33 = F_22 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_33 ) ;
F_23 ( V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ! F_25 ( V_7 , V_34 ) ) {
F_26 ( V_9 ) ;
F_27 ( V_9 ) ;
F_28 ( V_9 ) ;
}
F_20 ( V_15 , V_2 , V_32 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
switch ( F_30 ( V_32 -> V_35 ) ) {
case V_36 :
F_20 ( V_15 , V_2 , V_32 ) ;
F_31 ( 100 ) ;
F_32 ( V_15 , F_30 ( V_32 -> V_37 >> 8 ) ) ;
break;
default:
F_20 ( V_15 , V_2 , V_32 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_34 ( V_9 ) ;
F_20 ( V_15 , V_2 , V_32 ) ;
return 0 ;
}
static void F_35 ( struct V_38 * V_13 ,
struct V_19 * V_12 )
{
struct V_3 * V_4 = F_36 ( V_12 ) ;
F_37 ( V_4 -> V_17 . V_21 ) ;
F_38 ( V_13 , V_12 ) ;
}
static void F_39 ( struct V_6 * V_7 ,
unsigned short V_5 )
{
struct V_1 * V_33 = F_22 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_33 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_19 * V_12 ;
unsigned short * V_21 ;
V_12 = F_40 ( & V_33 -> V_13 , V_39 ) ;
if ( ! V_12 ) {
F_41 ( V_11 , L_3 ) ;
return;
}
V_21 = F_42 ( sizeof( * V_21 ) , V_39 ) ;
if ( ! V_21 ) {
F_38 ( & V_33 -> V_13 , V_12 ) ;
F_41 ( V_11 , L_4 ) ;
return;
}
* V_21 = F_43 ( V_5 ) ;
V_12 -> V_40 = F_35 ;
V_12 -> V_21 = V_21 ;
V_12 -> V_22 = sizeof( * V_21 ) ;
V_12 -> V_23 = 0 ;
V_9 -> V_41 = & V_42 ;
F_11 ( V_33 , F_36 ( V_12 ) ) ;
}
static int F_44 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned short V_5 = 0 ;
if ( F_25 ( V_7 , V_43 ) )
V_5 = 1 << V_44 ;
F_39 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_45 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned short V_5 = 0 ;
F_39 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_46 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned short V_5 = 0 ;
if ( F_47 ( V_9 ) )
V_5 = 1 << V_45 ;
F_39 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_48 ( struct V_14 * V_15 ,
struct V_46 * V_41 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_47 = V_32 -> V_48 & V_49 ;
int V_50 = F_30 ( V_32 -> V_37 ) & V_51 ;
int V_27 = 0 ;
int (* F_49)( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_31 * V_32 );
char * V_52 ;
V_2 = F_50 ( V_7 , V_50 ) ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 ) {
F_41 ( V_11 , L_5 ) ;
return - V_53 ;
}
switch ( V_47 ) {
case V_54 :
V_52 = L_6 ;
F_49 = V_41 -> V_10 ;
break;
case V_55 :
V_52 = L_7 ;
F_49 = V_41 -> V_56 ;
break;
case V_57 :
V_52 = L_8 ;
F_49 = V_41 -> V_58 ;
break;
default:
F_51 ( V_11 , L_9 , V_47 ) ;
F_49 = NULL ;
V_27 = - V_53 ;
}
if ( F_49 ) {
F_5 ( V_11 , L_10 , V_41 -> V_59 , V_50 , V_52 ) ;
V_27 = F_49 ( V_15 , V_2 , V_32 ) ;
}
return V_27 ;
}
static int F_52 ( struct V_14 * V_15 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
V_7 -> V_29 . V_62 = F_53 ( V_15 ) ;
F_5 ( V_11 , L_11 ,
F_54 ( V_61 ) ,
V_7 -> V_29 . V_62 ) ;
return 0 ;
}
static int F_55 ( struct V_14 * V_15 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
struct V_1 * V_33 = F_22 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_33 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_31 V_32 ;
struct V_46 * V_63 = NULL ;
int V_64 = F_56 ( V_61 ) ;
int V_27 = 0 ;
F_5 ( V_11 , L_12 , V_64 ) ;
switch ( V_64 ) {
case V_65 :
V_9 -> V_41 = & V_42 ;
break;
case V_66 :
V_9 -> V_41 = & V_67 ;
break;
case V_68 :
V_9 -> V_41 = & V_69 ;
break;
case V_70 :
case V_71 :
F_23 ( V_9 ) ;
default:
return V_27 ;
}
F_57 ( V_15 , & V_32 ) ;
switch ( V_32 . V_48 & V_72 ) {
case V_73 :
switch ( V_32 . V_74 ) {
case V_75 :
V_63 = & V_76 ;
break;
case V_77 :
V_63 = & V_78 ;
break;
case V_79 :
V_63 = & V_80 ;
break;
}
}
if ( V_63 )
V_27 = F_48 ( V_15 , V_63 , & V_32 ) ;
else
V_27 = V_7 -> V_81 -> V_82 ( & V_7 -> V_29 , & V_32 ) ;
if ( V_27 < 0 )
F_34 ( V_9 ) ;
return V_27 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_16 * V_17 ;
while ( 1 ) {
V_17 = F_59 ( V_9 , NULL ) ;
if ( ! V_17 )
break;
F_1 ( V_2 , F_10 ( V_17 ) , - V_83 ) ;
}
F_26 ( V_9 ) ;
return 0 ;
}
static int F_60 ( struct V_38 * V_13 ,
const struct V_84 * V_85 )
{
struct V_1 * V_2 = F_61 ( V_13 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_62 ( V_7 ) ;
struct V_8 * V_9 ;
int V_27 = - V_86 ;
if ( V_2 -> V_9 ) {
F_63 ( V_2 -> V_9 ) ;
F_27 ( V_2 -> V_9 ) ;
return 0 ;
}
V_9 = F_64 ( V_15 ,
F_65 ( V_85 ) ,
F_66 ( V_85 ) ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_9 -> V_87 = V_2 ;
F_67 ( V_9 , 0 ,
F_68 ( V_85 ) ,
F_69 ( V_85 ) ) ;
if ( F_66 ( V_85 ) )
V_9 -> V_41 = & V_88 ;
else
V_9 -> V_41 = & V_89 ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_70 ( struct V_38 * V_13 )
{
struct V_1 * V_2 = F_61 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return - V_53 ;
F_58 ( V_2 ) ;
F_71 ( V_9 ) ;
V_2 -> V_9 -> V_87 = NULL ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static struct V_19 * F_72 ( struct V_38 * V_13 ,
T_1 V_90 )
{
struct V_3 * V_4 ;
V_4 = F_73 ( sizeof *V_4 , V_90 ) ;
if ( ! V_4 )
return NULL ;
F_74 ( F_12 ( V_4 ) ) ;
return & V_4 -> V_12 ;
}
static void F_75 ( struct V_38 * V_13 ,
struct V_19 * V_12 )
{
struct V_3 * V_4 = F_36 ( V_12 ) ;
F_17 ( ! F_76 ( & V_4 -> V_17 . V_91 ) ) ;
F_37 ( V_4 ) ;
}
static int F_77 ( struct V_38 * V_13 , struct V_19 * V_12 ,
T_1 V_90 )
{
struct V_1 * V_2 = F_61 ( V_13 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_36 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( F_78 ( V_7 ) ||
F_79 ( ! V_7 -> V_81 ) ||
F_79 ( ! V_9 ) )
return - V_92 ;
F_11 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_38 * V_13 , struct V_19 * V_12 )
{
struct V_1 * V_2 = F_61 ( V_13 ) ;
struct V_3 * V_4 = F_36 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_59 ( V_9 , F_12 ( V_4 ) ) ;
F_1 ( V_2 , V_4 , - V_83 ) ;
return 0 ;
}
static int F_81 ( struct V_38 * V_13 , int V_93 , int V_94 )
{
struct V_1 * V_2 = F_61 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_62 ( V_7 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_95 ;
F_58 ( V_2 ) ;
F_5 ( V_11 , L_13 ,
V_93 , F_6 ( V_9 ) ) ;
F_82 ( V_15 , V_95 ) ;
if ( V_93 )
F_34 ( V_9 ) ;
else
F_26 ( V_9 ) ;
if ( V_93 && V_94 )
F_83 ( V_7 , V_34 ) ;
else
F_84 ( V_7 , V_34 ) ;
F_85 ( V_15 , V_95 ) ;
return 0 ;
}
static int F_86 ( struct V_38 * V_13 , int V_96 )
{
return F_81 ( V_13 , V_96 , 0 ) ;
}
static int F_87 ( struct V_38 * V_13 )
{
return F_81 ( V_13 , 1 , 1 ) ;
}
static int F_88 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
return V_7 -> V_81 &&
F_25 ( V_7 , V_97 ) ;
}
static void F_89 ( struct V_14 * V_15 )
{
if ( F_88 ( V_15 ) )
F_90 ( V_15 , 1 ) ;
else
F_90 ( V_15 , 0 ) ;
}
static int F_91 ( struct V_14 * V_15 , T_2 V_5 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
struct V_1 * V_33 = F_22 ( V_7 ) ;
struct V_98 * V_99 = F_92 ( V_15 ) ;
struct V_10 * V_11 = F_93 ( V_15 ) ;
unsigned long V_95 ;
int V_27 = 0 ;
F_82 ( V_15 , V_95 ) ;
F_83 ( V_7 , V_5 ) ;
if ( ! ( F_25 ( V_7 , V_100 ) &&
F_25 ( V_7 , V_101 ) ) )
V_27 = - 1 ;
F_85 ( V_15 , V_95 ) ;
if ( V_27 < 0 )
return 0 ;
F_5 ( V_11 , L_14 ) ;
F_94 ( V_15 ) ;
F_95 ( V_15 ,
F_15 ) ;
V_33 -> V_9 = F_96 ( V_15 ) ;
V_33 -> V_9 -> V_87 = V_33 ;
F_67 ( V_33 -> V_9 , 0 , 0 , 64 ) ;
F_97 ( V_15 , 1 ) ;
F_89 ( V_15 ) ;
V_99 -> V_102 = F_52 ;
V_99 -> V_103 = F_55 ;
F_98 ( V_15 , V_99 ) ;
return 0 ;
}
static int F_99 ( struct V_14 * V_15 , T_2 V_5 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
struct V_98 * V_99 = F_92 ( V_15 ) ;
struct V_1 * V_33 = F_22 ( V_7 ) ;
struct V_10 * V_11 = F_93 ( V_15 ) ;
unsigned long V_95 ;
int V_27 = 0 ;
F_82 ( V_15 , V_95 ) ;
F_84 ( V_7 , V_5 ) ;
if ( ! F_25 ( V_7 , V_100 ) &&
! F_25 ( V_7 , V_101 ) )
V_27 = - 1 ;
F_85 ( V_15 , V_95 ) ;
if ( V_27 < 0 )
return 0 ;
F_100 ( V_15 ) ;
V_99 -> V_102 = NULL ;
V_99 -> V_103 = NULL ;
F_98 ( V_15 , V_99 ) ;
V_7 -> V_29 . V_62 = V_104 ;
F_32 ( V_15 , 0 ) ;
F_97 ( V_15 , 0 ) ;
F_70 ( & V_33 -> V_13 ) ;
F_5 ( V_11 , L_15 ) ;
return 0 ;
}
static int F_101 ( struct V_105 * V_29 ,
struct V_106 * V_81 )
{
struct V_6 * V_7 = F_102 ( V_29 ) ;
struct V_14 * V_15 = F_62 ( V_7 ) ;
if ( ! V_81 ||
! V_81 -> V_82 ||
V_81 -> V_107 < V_108 )
return - V_53 ;
V_7 -> V_81 = V_81 ;
return F_91 ( V_15 , V_101 ) ;
}
static int F_103 ( struct V_105 * V_29 )
{
struct V_6 * V_7 = F_102 ( V_29 ) ;
struct V_14 * V_15 = F_62 ( V_7 ) ;
F_99 ( V_15 , V_101 ) ;
V_7 -> V_81 = NULL ;
return 0 ;
}
static int F_104 ( struct V_105 * V_29 )
{
struct V_6 * V_7 = F_102 ( V_29 ) ;
struct V_14 * V_15 = F_62 ( V_7 ) ;
return F_105 ( V_15 ) ;
}
static int F_106 ( struct V_105 * V_29 , int V_109 )
{
struct V_6 * V_7 = F_102 ( V_29 ) ;
struct V_14 * V_15 = F_62 ( V_7 ) ;
unsigned long V_95 ;
F_82 ( V_15 , V_95 ) ;
if ( V_109 )
F_83 ( V_7 , V_97 ) ;
else
F_84 ( V_7 , V_97 ) ;
F_89 ( V_15 ) ;
F_85 ( V_15 , V_95 ) ;
return 0 ;
}
static int F_107 ( struct V_105 * V_29 , int V_110 )
{
struct V_6 * V_7 = F_102 ( V_29 ) ;
if ( V_110 )
F_83 ( V_7 , V_43 ) ;
else
F_84 ( V_7 , V_43 ) ;
V_29 -> V_111 = ( V_110 != 0 ) ;
return 0 ;
}
static int F_108 ( struct V_14 * V_15 )
{
return F_91 ( V_15 , V_100 ) ;
}
static int F_109 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
if ( V_7 -> V_81 &&
V_7 -> V_81 -> V_112 )
V_7 -> V_81 -> V_112 ( & V_7 -> V_29 ) ;
return F_99 ( V_15 , V_100 ) ;
}
int F_110 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = F_93 ( V_15 ) ;
int V_113 = F_111 ( V_15 , V_113 ) ;
int V_114 ;
int V_27 ;
V_7 = F_73 ( sizeof( struct V_6 ) , V_115 ) ;
if ( ! V_7 ) {
F_41 ( V_11 , L_16 ) ;
return - V_116 ;
}
V_2 = F_73 ( sizeof( struct V_1 ) * V_113 , V_115 ) ;
if ( ! V_2 ) {
F_41 ( V_11 , L_17 ) ;
V_27 = - V_116 ;
goto V_117;
}
F_112 ( V_15 , & V_7 -> V_99 , V_118 ) ;
V_7 -> V_99 . V_59 = L_18 ;
V_7 -> V_99 . V_119 = F_108 ;
V_7 -> V_99 . V_120 = F_109 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_121 = V_113 ;
F_113 ( V_7 ) ;
V_7 -> V_29 . V_11 . V_122 = V_11 ;
V_7 -> V_29 . V_59 = L_19 ;
V_7 -> V_29 . V_123 = & V_124 ;
V_7 -> V_29 . V_107 = V_125 ;
F_114 ( & V_7 -> V_29 . V_126 ) ;
F_115 (uep, gpriv, i) {
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = NULL ;
snprintf ( V_2 -> V_127 , V_128 , L_20 , V_114 ) ;
V_2 -> V_13 . V_59 = V_2 -> V_127 ;
V_2 -> V_13 . V_123 = & V_129 ;
F_114 ( & V_2 -> V_13 . V_126 ) ;
if ( F_116 ( V_2 ) ) {
V_7 -> V_29 . V_130 = & V_2 -> V_13 ;
F_117 ( & V_2 -> V_13 , 64 ) ;
}
else {
F_117 ( & V_2 -> V_13 , 512 ) ;
F_118 ( & V_2 -> V_13 . V_126 , & V_7 -> V_29 . V_126 ) ;
}
}
V_27 = F_119 ( V_11 , & V_7 -> V_29 ) ;
if ( V_27 )
goto V_131;
F_120 ( V_11 , L_21 ) ;
return 0 ;
V_131:
F_37 ( V_7 -> V_2 ) ;
V_117:
F_37 ( V_7 ) ;
return V_27 ;
}
void F_121 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_21 ( V_15 ) ;
F_122 ( & V_7 -> V_29 ) ;
F_37 ( V_7 -> V_2 ) ;
F_37 ( V_7 ) ;
}
