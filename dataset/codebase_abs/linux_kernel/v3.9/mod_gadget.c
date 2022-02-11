static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
F_5 ( V_11 , L_1 , F_6 ( V_9 ) ) ;
V_4 -> V_12 . V_5 = V_5 ;
V_4 -> V_12 . V_13 ( & V_2 -> V_14 , & V_4 -> V_12 ) ;
}
static void F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_3 * V_4 = F_9 ( V_18 ) ;
V_4 -> V_12 . V_19 = V_18 -> V_19 ;
F_1 ( V_2 , V_4 , 0 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_17 * V_18 = F_11 ( V_4 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
V_12 -> V_19 = 0 ;
V_12 -> V_5 = - V_21 ;
F_12 ( V_9 , V_18 , F_7 ,
V_12 -> V_22 , V_12 -> V_23 , V_12 -> V_24 , - 1 ) ;
F_13 ( V_9 ) ;
F_5 ( V_11 , L_2 ,
F_6 ( V_9 ) ,
V_12 -> V_23 ) ;
}
static int F_14 ( struct V_17 * V_18 , int V_25 )
{
struct V_3 * V_4 = F_9 ( V_18 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_26 V_27 ;
int V_28 = 0 ;
V_27 = F_15 ( V_9 ) ;
if ( V_25 ) {
F_16 ( V_12 -> V_29 ) ;
V_28 = F_17 ( & V_7 -> V_30 , V_12 , V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
V_18 -> V_31 = V_12 -> V_31 ;
} else {
F_18 ( & V_7 -> V_30 , V_12 , V_27 ) ;
}
return V_28 ;
}
static int F_19 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
struct V_1 * V_34 = F_21 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_34 ) ;
F_22 ( V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ! F_24 ( V_7 , V_35 ) ) {
F_25 ( V_9 ) ;
F_26 ( V_9 ) ;
F_27 ( V_9 ) ;
}
F_19 ( V_16 , V_2 , V_33 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
switch ( F_29 ( V_33 -> V_36 ) ) {
case V_37 :
F_19 ( V_16 , V_2 , V_33 ) ;
F_30 ( 100 ) ;
F_31 ( V_16 , F_29 ( V_33 -> V_38 >> 8 ) ) ;
break;
default:
F_19 ( V_16 , V_2 , V_33 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_33 ( V_9 ) ;
F_19 ( V_16 , V_2 , V_33 ) ;
return 0 ;
}
static void F_34 ( struct V_39 * V_14 ,
struct V_20 * V_12 )
{
struct V_3 * V_4 = F_35 ( V_12 ) ;
F_36 ( V_4 -> V_18 . V_22 ) ;
F_37 ( V_14 , V_12 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
unsigned short V_5 )
{
struct V_1 * V_34 = F_21 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_34 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_20 * V_12 ;
unsigned short * V_22 ;
V_12 = F_39 ( & V_34 -> V_14 , V_40 ) ;
if ( ! V_12 ) {
F_40 ( V_11 , L_3 ) ;
return;
}
V_22 = F_41 ( sizeof( * V_22 ) , V_40 ) ;
if ( ! V_22 ) {
F_37 ( & V_34 -> V_14 , V_12 ) ;
F_40 ( V_11 , L_4 ) ;
return;
}
* V_22 = F_42 ( V_5 ) ;
V_12 -> V_13 = F_34 ;
V_12 -> V_22 = V_22 ;
V_12 -> V_23 = sizeof( * V_22 ) ;
V_12 -> V_24 = 0 ;
V_9 -> V_41 = & V_42 ;
F_10 ( V_34 , F_35 ( V_12 ) ) ;
}
static int F_43 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned short V_5 = 0 ;
if ( F_24 ( V_7 , V_43 ) )
V_5 = 1 << V_44 ;
F_38 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_44 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned short V_5 = 0 ;
F_38 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned short V_5 = 0 ;
if ( F_46 ( V_9 ) )
V_5 = 1 << V_45 ;
F_38 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_47 ( struct V_15 * V_16 ,
struct V_46 * V_41 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_47 = V_33 -> V_48 & V_49 ;
int V_50 = F_29 ( V_33 -> V_38 ) & V_51 ;
int V_28 = 0 ;
int (* F_48)( struct V_15 * V_16 , struct V_1 * V_2 ,
struct V_32 * V_33 );
char * V_52 ;
V_2 = F_49 ( V_7 , V_50 ) ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 ) {
F_40 ( V_11 , L_5 ) ;
return - V_53 ;
}
switch ( V_47 ) {
case V_54 :
V_52 = L_6 ;
F_48 = V_41 -> V_10 ;
break;
case V_55 :
V_52 = L_7 ;
F_48 = V_41 -> V_56 ;
break;
case V_57 :
V_52 = L_8 ;
F_48 = V_41 -> V_58 ;
break;
default:
F_50 ( V_11 , L_9 , V_47 ) ;
F_48 = NULL ;
V_28 = - V_53 ;
}
if ( F_48 ) {
F_5 ( V_11 , L_10 , V_41 -> V_59 , V_50 , V_52 ) ;
V_28 = F_48 ( V_16 , V_2 , V_33 ) ;
}
return V_28 ;
}
static int F_51 ( struct V_15 * V_16 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
V_7 -> V_30 . V_62 = F_52 ( V_16 ) ;
F_5 ( V_11 , L_11 ,
F_53 ( V_61 ) ,
V_7 -> V_30 . V_62 ) ;
return 0 ;
}
static int F_54 ( struct V_15 * V_16 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
struct V_1 * V_34 = F_21 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_34 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_32 V_33 ;
struct V_46 * V_63 = NULL ;
int V_64 = F_55 ( V_61 ) ;
int V_28 = 0 ;
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
default:
return V_28 ;
}
F_56 ( V_16 , & V_33 ) ;
switch ( V_33 . V_48 & V_70 ) {
case V_71 :
switch ( V_33 . V_72 ) {
case V_73 :
V_63 = & V_74 ;
break;
case V_75 :
V_63 = & V_76 ;
break;
case V_77 :
V_63 = & V_78 ;
break;
}
}
if ( V_63 )
V_28 = F_47 ( V_16 , V_63 , & V_33 ) ;
else
V_28 = V_7 -> V_79 -> V_80 ( & V_7 -> V_30 , & V_33 ) ;
if ( V_28 < 0 )
F_33 ( V_9 ) ;
return V_28 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_17 * V_18 ;
while ( 1 ) {
V_18 = F_58 ( V_9 , NULL ) ;
if ( ! V_18 )
break;
F_1 ( V_2 , F_9 ( V_18 ) , - V_81 ) ;
}
F_25 ( V_9 ) ;
return 0 ;
}
static int F_59 ( struct V_39 * V_14 ,
const struct V_82 * V_83 )
{
struct V_1 * V_2 = F_60 ( V_14 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_61 ( V_7 ) ;
struct V_8 * V_9 ;
int V_28 = - V_84 ;
if ( V_2 -> V_9 ) {
F_62 ( V_2 -> V_9 ) ;
F_26 ( V_2 -> V_9 ) ;
return 0 ;
}
V_9 = F_63 ( V_16 ,
F_64 ( V_83 ) ,
F_65 ( V_83 ) ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_9 -> V_85 = V_2 ;
F_66 ( V_9 , 0 ,
F_67 ( V_83 ) ,
F_68 ( V_83 ) ) ;
if ( F_65 ( V_83 ) )
V_9 -> V_41 = & V_86 ;
else
V_9 -> V_41 = & V_87 ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_69 ( struct V_39 * V_14 )
{
struct V_1 * V_2 = F_60 ( V_14 ) ;
F_57 ( V_2 ) ;
V_2 -> V_9 -> V_85 = NULL ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static struct V_20 * F_70 ( struct V_39 * V_14 ,
T_1 V_88 )
{
struct V_3 * V_4 ;
V_4 = F_71 ( sizeof *V_4 , V_88 ) ;
if ( ! V_4 )
return NULL ;
F_72 ( F_11 ( V_4 ) ) ;
return & V_4 -> V_12 ;
}
static void F_73 ( struct V_39 * V_14 ,
struct V_20 * V_12 )
{
struct V_3 * V_4 = F_35 ( V_12 ) ;
F_16 ( ! F_74 ( & V_4 -> V_18 . V_89 ) ) ;
F_36 ( V_4 ) ;
}
static int F_75 ( struct V_39 * V_14 , struct V_20 * V_12 ,
T_1 V_88 )
{
struct V_1 * V_2 = F_60 ( V_14 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_35 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( F_76 ( V_7 ) ||
F_77 ( ! V_7 -> V_79 ) ||
F_77 ( ! V_9 ) )
return - V_90 ;
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_78 ( struct V_39 * V_14 , struct V_20 * V_12 )
{
struct V_1 * V_2 = F_60 ( V_14 ) ;
struct V_3 * V_4 = F_35 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_58 ( V_9 , F_11 ( V_4 ) ) ;
F_1 ( V_2 , V_4 , - V_81 ) ;
return 0 ;
}
static int F_79 ( struct V_39 * V_14 , int V_91 , int V_92 )
{
struct V_1 * V_2 = F_60 ( V_14 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_61 ( V_7 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_93 ;
F_57 ( V_2 ) ;
F_5 ( V_11 , L_13 ,
V_91 , F_6 ( V_9 ) ) ;
F_80 ( V_16 , V_93 ) ;
if ( V_91 )
F_33 ( V_9 ) ;
else
F_25 ( V_9 ) ;
if ( V_91 && V_92 )
F_81 ( V_7 , V_35 ) ;
else
F_82 ( V_7 , V_35 ) ;
F_83 ( V_16 , V_93 ) ;
return 0 ;
}
static int F_84 ( struct V_39 * V_14 , int V_94 )
{
return F_79 ( V_14 , V_94 , 0 ) ;
}
static int F_85 ( struct V_39 * V_14 )
{
return F_79 ( V_14 , 1 , 1 ) ;
}
static int F_86 ( struct V_15 * V_16 , T_2 V_5 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
struct V_1 * V_34 = F_21 ( V_7 ) ;
struct V_95 * V_96 = F_87 ( V_16 ) ;
struct V_10 * V_11 = F_88 ( V_16 ) ;
unsigned long V_93 ;
int V_28 = 0 ;
F_80 ( V_16 , V_93 ) ;
F_81 ( V_7 , V_5 ) ;
if ( ! ( F_24 ( V_7 , V_97 ) &&
F_24 ( V_7 , V_98 ) ) )
V_28 = - 1 ;
F_83 ( V_16 , V_93 ) ;
if ( V_28 < 0 )
return 0 ;
F_5 ( V_11 , L_14 ) ;
F_89 ( V_16 ,
F_14 ) ;
F_90 ( V_16 ) ;
V_34 -> V_9 = F_91 ( V_16 ) ;
V_34 -> V_9 -> V_85 = V_34 ;
F_66 ( V_34 -> V_9 , 0 , 0 , 64 ) ;
F_92 ( V_16 , 1 ) ;
V_96 -> V_99 = F_51 ;
V_96 -> V_100 = F_54 ;
F_93 ( V_16 , V_96 ) ;
return 0 ;
}
static int F_94 ( struct V_15 * V_16 , T_2 V_5 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
struct V_95 * V_96 = F_87 ( V_16 ) ;
struct V_1 * V_34 = F_21 ( V_7 ) ;
struct V_10 * V_11 = F_88 ( V_16 ) ;
unsigned long V_93 ;
int V_28 = 0 ;
F_80 ( V_16 , V_93 ) ;
F_82 ( V_7 , V_5 ) ;
if ( ! F_24 ( V_7 , V_97 ) &&
! F_24 ( V_7 , V_98 ) )
V_28 = - 1 ;
F_83 ( V_16 , V_93 ) ;
if ( V_28 < 0 )
return 0 ;
F_95 ( V_16 ) ;
V_96 -> V_99 = NULL ;
V_96 -> V_100 = NULL ;
F_93 ( V_16 , V_96 ) ;
V_7 -> V_30 . V_62 = V_101 ;
F_31 ( V_16 , 0 ) ;
F_92 ( V_16 , 0 ) ;
F_69 ( & V_34 -> V_14 ) ;
F_5 ( V_11 , L_15 ) ;
return 0 ;
}
static int F_96 ( struct V_102 * V_30 ,
struct V_103 * V_79 )
{
struct V_6 * V_7 = F_97 ( V_30 ) ;
struct V_15 * V_16 = F_61 ( V_7 ) ;
if ( ! V_79 ||
! V_79 -> V_80 ||
V_79 -> V_104 < V_105 )
return - V_53 ;
V_7 -> V_79 = V_79 ;
V_7 -> V_30 . V_11 . V_79 = & V_79 -> V_79 ;
return F_86 ( V_16 , V_98 ) ;
}
static int F_98 ( struct V_102 * V_30 ,
struct V_103 * V_79 )
{
struct V_6 * V_7 = F_97 ( V_30 ) ;
struct V_15 * V_16 = F_61 ( V_7 ) ;
if ( ! V_79 ||
! V_79 -> V_106 )
return - V_53 ;
F_94 ( V_16 , V_98 ) ;
V_7 -> V_30 . V_11 . V_79 = NULL ;
V_7 -> V_79 = NULL ;
return 0 ;
}
static int F_99 ( struct V_102 * V_30 )
{
struct V_6 * V_7 = F_97 ( V_30 ) ;
struct V_15 * V_16 = F_61 ( V_7 ) ;
return F_100 ( V_16 ) ;
}
static int F_101 ( struct V_102 * V_30 , int V_107 )
{
struct V_6 * V_7 = F_97 ( V_30 ) ;
struct V_15 * V_16 = F_61 ( V_7 ) ;
F_102 ( V_16 , V_107 ) ;
return 0 ;
}
static int F_103 ( struct V_102 * V_30 , int V_108 )
{
struct V_6 * V_7 = F_97 ( V_30 ) ;
if ( V_108 )
F_81 ( V_7 , V_43 ) ;
else
F_82 ( V_7 , V_43 ) ;
return 0 ;
}
static int F_104 ( struct V_15 * V_16 )
{
return F_86 ( V_16 , V_97 ) ;
}
static int F_105 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
if ( V_7 -> V_79 &&
V_7 -> V_79 -> V_109 )
V_7 -> V_79 -> V_109 ( & V_7 -> V_30 ) ;
return F_94 ( V_16 , V_97 ) ;
}
static void F_106 ( struct V_10 * V_110 )
{
}
int F_107 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = F_88 ( V_16 ) ;
int V_111 = F_108 ( V_16 , V_111 ) ;
int V_112 ;
int V_28 ;
V_7 = F_71 ( sizeof( struct V_6 ) , V_113 ) ;
if ( ! V_7 ) {
F_40 ( V_11 , L_16 ) ;
return - V_114 ;
}
V_2 = F_71 ( sizeof( struct V_1 ) * V_111 , V_113 ) ;
if ( ! V_2 ) {
F_40 ( V_11 , L_17 ) ;
V_28 = - V_114 ;
goto V_115;
}
F_109 ( V_16 , & V_7 -> V_96 , V_116 ) ;
V_7 -> V_96 . V_59 = L_18 ;
V_7 -> V_96 . V_117 = F_104 ;
V_7 -> V_96 . V_118 = F_105 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_119 = V_111 ;
F_110 ( V_7 ) ;
F_111 ( & V_7 -> V_30 . V_11 , L_18 ) ;
V_7 -> V_30 . V_11 . V_120 = V_11 ;
V_7 -> V_30 . V_11 . V_121 = F_106 ;
V_7 -> V_30 . V_59 = L_19 ;
V_7 -> V_30 . V_122 = & V_123 ;
V_7 -> V_30 . V_104 = V_124 ;
V_28 = F_112 ( & V_7 -> V_30 . V_11 ) ;
if ( V_28 < 0 )
goto V_125;
F_113 ( & V_7 -> V_30 . V_126 ) ;
F_114 (uep, gpriv, i) {
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = NULL ;
snprintf ( V_2 -> V_127 , V_128 , L_20 , V_112 ) ;
V_2 -> V_14 . V_59 = V_2 -> V_127 ;
V_2 -> V_14 . V_122 = & V_129 ;
F_113 ( & V_2 -> V_14 . V_126 ) ;
if ( F_115 ( V_2 ) ) {
V_7 -> V_30 . V_130 = & V_2 -> V_14 ;
V_2 -> V_14 . V_131 = 64 ;
}
else {
V_2 -> V_14 . V_131 = 512 ;
F_116 ( & V_2 -> V_14 . V_126 , & V_7 -> V_30 . V_126 ) ;
}
}
V_28 = F_117 ( V_11 , & V_7 -> V_30 ) ;
if ( V_28 )
goto V_132;
F_118 ( V_11 , L_21 ) ;
return 0 ;
V_132:
F_119 ( & V_7 -> V_30 . V_11 ) ;
V_125:
F_36 ( V_7 -> V_2 ) ;
V_115:
F_36 ( V_7 ) ;
return V_28 ;
}
void F_120 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_20 ( V_16 ) ;
F_121 ( & V_7 -> V_30 ) ;
F_119 ( & V_7 -> V_30 . V_11 ) ;
F_36 ( V_7 -> V_2 ) ;
F_36 ( V_7 ) ;
}
