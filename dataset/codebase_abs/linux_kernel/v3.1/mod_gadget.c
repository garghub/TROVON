static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_4 ) ;
struct V_13 * V_14 = & V_4 -> V_14 ;
V_14 -> V_15 = 0 ;
V_14 -> V_16 = - V_17 ;
F_6 ( V_10 , V_12 , V_2 -> V_18 ,
V_14 -> V_19 , V_14 -> V_20 , V_14 -> V_21 ) ;
F_7 ( V_8 , L_1 ,
F_8 ( V_10 ) ,
V_14 -> V_20 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_7 ( V_8 , L_2 , F_8 ( V_10 ) ) ;
V_4 -> V_14 . V_16 = V_16 ;
V_4 -> V_14 . V_22 ( & V_2 -> V_23 , & V_4 -> V_14 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_3 * V_4 = F_12 ( V_12 ) ;
V_4 -> V_14 . V_15 = V_12 -> V_15 ;
F_9 ( V_2 , V_4 , 0 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_11 * V_12 ,
enum V_24 V_25 )
{
struct V_3 * V_4 = F_12 ( V_12 ) ;
struct V_13 * V_14 = & V_4 -> V_14 ;
if ( V_12 -> V_26 != V_27 ) {
F_14 ( V_8 , L_3 ) ;
return - V_28 ;
}
if ( V_14 -> V_26 == V_27 ) {
V_12 -> V_26 = F_15 ( V_8 , V_12 -> V_19 , V_12 -> V_20 , V_25 ) ;
} else {
F_16 ( V_8 , V_14 -> V_26 , V_14 -> V_20 , V_25 ) ;
V_12 -> V_26 = V_14 -> V_26 ;
}
if ( F_17 ( V_8 , V_12 -> V_26 ) ) {
F_14 ( V_8 , L_4 , V_12 -> V_26 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_18 ( struct V_7 * V_8 ,
struct V_11 * V_12 ,
enum V_24 V_25 )
{
struct V_3 * V_4 = F_12 ( V_12 ) ;
struct V_13 * V_14 = & V_4 -> V_14 ;
if ( V_12 -> V_26 == V_27 ) {
F_14 ( V_8 , L_5 ) ;
return - V_28 ;
}
if ( V_14 -> V_26 == V_27 )
F_19 ( V_8 , V_12 -> V_26 , V_12 -> V_20 , V_25 ) ;
else
F_20 ( V_8 , V_14 -> V_26 , V_14 -> V_20 , V_25 ) ;
V_12 -> V_26 = V_27 ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 , int V_29 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
enum V_24 V_25 ;
V_25 = F_22 ( V_10 ) ? V_30 : V_31 ;
if ( V_29 )
return F_13 ( V_8 , V_12 , V_25 ) ;
else
return F_18 ( V_8 , V_12 , V_25 ) ;
}
static int F_23 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
struct V_1 * V_36 = F_25 ( V_6 ) ;
struct V_9 * V_10 = F_4 ( V_36 ) ;
F_26 ( V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( ! F_28 ( V_6 , V_37 ) ) {
F_29 ( V_10 ) ;
F_30 ( V_10 ) ;
F_31 ( V_10 ) ;
}
F_23 ( V_33 , V_2 , V_35 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 ,
struct V_38 * V_18 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_39 = V_35 -> V_40 & V_41 ;
int V_42 = F_33 ( V_35 -> V_43 ) & V_44 ;
int V_45 ;
int (* F_34)( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_34 * V_35 );
char * V_46 ;
V_2 = F_35 ( V_6 , V_42 ) ;
V_10 = F_4 ( V_2 ) ;
if ( ! V_10 ) {
F_14 ( V_8 , L_6 ) ;
V_45 = - V_47 ;
goto V_48;
}
switch ( V_39 ) {
case V_49 :
V_46 = L_7 ;
F_34 = V_18 -> V_7 ;
break;
case V_50 :
V_46 = L_8 ;
F_34 = V_18 -> V_51 ;
break;
case V_52 :
V_46 = L_9 ;
F_34 = V_18 -> V_53 ;
break;
default:
F_36 ( V_8 , L_10 , V_39 ) ;
F_34 = NULL ;
V_45 = - V_47 ;
}
if ( F_34 ) {
unsigned long V_54 ;
F_7 ( V_8 , L_11 , V_18 -> V_55 , V_42 , V_46 ) ;
F_37 ( V_33 , V_54 ) ;
V_45 = F_34 ( V_33 , V_2 , V_35 ) ;
F_38 ( V_33 , V_54 ) ;
}
V_48:
F_39 ( V_10 ) ;
return V_45 ;
}
static int F_40 ( struct V_32 * V_33 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_6 -> V_58 . V_59 = F_41 ( V_57 ) ;
F_7 ( V_8 , L_12 ,
F_42 ( V_57 ) ,
V_6 -> V_58 . V_59 ) ;
return 0 ;
}
static int F_43 ( struct V_32 * V_33 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
struct V_1 * V_36 = F_25 ( V_6 ) ;
struct V_9 * V_10 = F_4 ( V_36 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_34 V_35 ;
struct V_38 * V_60 = NULL ;
int V_61 = F_44 ( V_57 ) ;
int V_45 = 0 ;
F_7 ( V_8 , L_13 , V_61 ) ;
switch ( V_61 ) {
case V_62 :
V_36 -> V_18 = & V_63 ;
break;
case V_64 :
V_36 -> V_18 = & V_65 ;
break;
case V_66 :
V_36 -> V_18 = & V_67 ;
break;
default:
return V_45 ;
}
F_45 ( V_33 , & V_35 ) ;
switch ( V_35 . V_40 & V_68 ) {
case V_69 :
switch ( V_35 . V_70 ) {
case V_71 :
V_60 = & V_72 ;
break;
}
}
if ( V_60 )
V_45 = F_32 ( V_33 , V_60 , & V_35 ) ;
else
V_45 = V_6 -> V_73 -> V_74 ( & V_6 -> V_58 , & V_35 ) ;
if ( V_45 < 0 )
F_46 ( V_10 ) ;
return V_45 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 ;
F_29 ( V_10 ) ;
while ( 1 ) {
V_12 = F_48 ( V_10 , NULL ) ;
if ( ! V_12 )
break;
}
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
int V_75 ;
struct V_1 * V_2 ;
F_50 (uep, gpriv, i)
V_2 -> V_10 = NULL ;
}
static int F_51 ( struct V_76 * V_23 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_53 ( V_6 ) ;
struct V_9 * V_10 ;
int V_45 = - V_28 ;
if ( V_2 -> V_10 ) {
F_54 ( V_2 -> V_10 ) ;
F_30 ( V_2 -> V_10 ) ;
return 0 ;
}
V_10 = F_55 ( V_33 , V_78 ) ;
if ( V_10 ) {
V_2 -> V_10 = V_10 ;
V_10 -> V_79 = V_2 ;
if ( F_56 ( V_78 ) )
V_2 -> V_18 = & V_80 ;
else
V_2 -> V_18 = & V_81 ;
V_45 = 0 ;
}
return V_45 ;
}
static int F_57 ( struct V_76 * V_23 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
return F_47 ( V_2 ) ;
}
static struct V_13 * F_58 ( struct V_76 * V_23 ,
T_1 V_82 )
{
struct V_3 * V_4 ;
V_4 = F_59 ( sizeof *V_4 , V_82 ) ;
if ( ! V_4 )
return NULL ;
F_60 ( F_5 ( V_4 ) ) ;
V_4 -> V_14 . V_26 = V_27 ;
return & V_4 -> V_14 ;
}
static void F_61 ( struct V_76 * V_23 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = F_62 ( V_14 ) ;
F_63 ( ! F_64 ( & V_4 -> V_12 . V_83 ) ) ;
F_65 ( V_4 ) ;
}
static int F_66 ( struct V_76 * V_23 , struct V_13 * V_14 ,
T_1 V_82 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_62 ( V_14 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( F_67 ( V_6 ) ||
F_68 ( ! V_6 -> V_73 ) ||
F_68 ( ! V_10 ) )
return - V_84 ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_69 ( struct V_76 * V_23 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
struct V_3 * V_4 = F_62 ( V_14 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
F_48 ( V_10 , F_5 ( V_4 ) ) ;
F_9 ( V_2 , V_4 , - V_85 ) ;
return 0 ;
}
static int F_70 ( struct V_76 * V_23 , int V_86 , int V_87 )
{
struct V_1 * V_2 = F_52 ( V_23 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_53 ( V_6 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned long V_54 ;
F_47 ( V_2 ) ;
F_7 ( V_8 , L_14 ,
V_86 , F_8 ( V_10 ) ) ;
F_37 ( V_33 , V_54 ) ;
if ( V_86 )
F_46 ( V_10 ) ;
else
F_29 ( V_10 ) ;
if ( V_86 && V_87 )
F_71 ( V_6 , V_37 ) ;
else
F_72 ( V_6 , V_37 ) ;
F_38 ( V_33 , V_54 ) ;
return 0 ;
}
static int F_73 ( struct V_76 * V_23 , int V_88 )
{
return F_70 ( V_23 , V_88 , 0 ) ;
}
static int F_74 ( struct V_76 * V_23 )
{
return F_70 ( V_23 , 1 , 1 ) ;
}
static int F_75 ( struct V_32 * V_33 , T_2 V_16 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
struct V_1 * V_36 = F_25 ( V_6 ) ;
struct V_89 * V_90 = F_76 ( V_33 ) ;
struct V_7 * V_8 = F_77 ( V_33 ) ;
unsigned long V_54 ;
int V_45 = 0 ;
F_37 ( V_33 , V_54 ) ;
F_71 ( V_6 , V_16 ) ;
if ( ! ( F_28 ( V_6 , V_91 ) &&
F_28 ( V_6 , V_92 ) ) )
V_45 = - 1 ;
F_38 ( V_33 , V_54 ) ;
if ( V_45 < 0 )
return 0 ;
F_7 ( V_8 , L_15 ) ;
F_78 ( V_33 ,
F_10 ,
F_21 ) ;
F_79 ( V_33 ) ;
F_49 ( V_6 ) ;
V_36 -> V_10 = F_80 ( V_33 ) ;
V_36 -> V_10 -> V_79 = V_36 ;
F_81 ( V_33 , 1 ) ;
F_82 ( V_33 , 1 ) ;
F_83 ( V_33 , 1 ) ;
V_90 -> V_93 = F_40 ;
V_90 -> V_94 = F_43 ;
F_84 ( V_33 , V_90 ) ;
return 0 ;
}
static int F_85 ( struct V_32 * V_33 , T_2 V_16 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
struct V_89 * V_90 = F_76 ( V_33 ) ;
struct V_1 * V_36 = F_25 ( V_6 ) ;
struct V_7 * V_8 = F_77 ( V_33 ) ;
unsigned long V_54 ;
int V_45 = 0 ;
F_37 ( V_33 , V_54 ) ;
F_72 ( V_6 , V_16 ) ;
if ( ! F_28 ( V_6 , V_91 ) &&
! F_28 ( V_6 , V_92 ) )
V_45 = - 1 ;
F_38 ( V_33 , V_54 ) ;
if ( V_45 < 0 )
return 0 ;
F_86 ( V_33 ) ;
V_90 -> V_93 = NULL ;
V_90 -> V_94 = NULL ;
F_84 ( V_33 , V_90 ) ;
V_6 -> V_58 . V_59 = V_95 ;
F_81 ( V_33 , 0 ) ;
F_82 ( V_33 , 0 ) ;
F_83 ( V_33 , 0 ) ;
F_47 ( V_36 ) ;
if ( V_6 -> V_73 &&
V_6 -> V_73 -> V_96 )
V_6 -> V_73 -> V_96 ( & V_6 -> V_58 ) ;
F_7 ( V_8 , L_16 ) ;
return 0 ;
}
static int F_87 ( struct V_97 * V_73 ,
int (* F_88)( struct V_98 * ) )
{
struct V_5 * V_6 ;
struct V_32 * V_33 ;
struct V_7 * V_8 ;
int V_45 ;
if ( ! F_88 ||
! V_73 ||
! V_73 -> V_74 ||
V_73 -> V_59 != V_99 )
return - V_47 ;
F_89 (gpriv) {
if ( ! V_6 -> V_73 )
goto V_100;
}
return - V_101 ;
V_100:
V_8 = F_3 ( V_6 ) ;
V_33 = F_53 ( V_6 ) ;
V_6 -> V_73 = V_73 ;
V_6 -> V_58 . V_8 . V_73 = & V_73 -> V_73 ;
V_45 = F_90 ( & V_6 -> V_58 . V_8 ) ;
if ( V_45 ) {
F_14 ( V_8 , L_17 , V_45 ) ;
goto V_102;
}
V_45 = F_88 ( & V_6 -> V_58 ) ;
if ( V_45 ) {
F_14 ( V_8 , L_18 ,
V_73 -> V_73 . V_55 , V_45 ) ;
goto V_103;
}
F_7 ( V_8 , L_19 , V_73 -> V_73 . V_55 ) ;
return F_75 ( V_33 , V_92 ) ;
V_103:
F_91 ( & V_6 -> V_58 . V_8 ) ;
V_102:
V_6 -> V_73 = NULL ;
V_6 -> V_58 . V_8 . V_73 = NULL ;
return V_45 ;
}
static int F_92 ( struct V_97 * V_73 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 ;
struct V_7 * V_8 ;
if ( ! V_73 ||
! V_73 -> V_104 )
return - V_47 ;
F_89 (gpriv) {
if ( V_6 -> V_73 == V_73 )
goto V_105;
}
return - V_101 ;
V_105:
V_8 = F_3 ( V_6 ) ;
V_33 = F_53 ( V_6 ) ;
F_85 ( V_33 , V_92 ) ;
F_91 ( & V_6 -> V_58 . V_8 ) ;
V_6 -> V_73 = NULL ;
if ( V_73 -> V_96 )
V_73 -> V_96 ( & V_6 -> V_58 ) ;
V_73 -> V_104 ( & V_6 -> V_58 ) ;
F_7 ( V_8 , L_20 , V_73 -> V_73 . V_55 ) ;
return 0 ;
}
static int F_93 ( struct V_98 * V_58 )
{
struct V_5 * V_6 = F_94 ( V_58 ) ;
struct V_32 * V_33 = F_53 ( V_6 ) ;
return F_95 ( V_33 ) ;
}
static int F_96 ( struct V_32 * V_33 )
{
return F_75 ( V_33 , V_91 ) ;
}
static int F_97 ( struct V_32 * V_33 )
{
return F_85 ( V_33 , V_91 ) ;
}
int T_3 F_98 ( struct V_32 * V_33 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_7 * V_8 = F_77 ( V_33 ) ;
int V_106 = F_99 ( V_33 , V_106 ) ;
int V_75 ;
int V_45 ;
V_6 = F_59 ( sizeof( struct V_5 ) , V_107 ) ;
if ( ! V_6 ) {
F_14 ( V_8 , L_21 ) ;
return - V_108 ;
}
V_2 = F_59 ( sizeof( struct V_1 ) * V_106 , V_107 ) ;
if ( ! V_2 ) {
F_14 ( V_8 , L_22 ) ;
V_45 = - V_108 ;
goto V_109;
}
F_100 ( V_33 , & V_6 -> V_90 , V_110 ) ;
V_6 -> V_90 . V_55 = L_23 ;
V_6 -> V_90 . V_111 = F_96 ;
V_6 -> V_90 . V_112 = F_97 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_113 = V_106 ;
F_101 ( V_6 ) ;
F_102 ( & V_6 -> V_58 . V_8 ) ;
F_103 ( & V_6 -> V_58 . V_8 , L_23 ) ;
V_6 -> V_58 . V_8 . V_114 = V_8 ;
V_6 -> V_58 . V_55 = L_24 ;
V_6 -> V_58 . V_115 = & V_116 ;
V_6 -> V_58 . V_117 = 1 ;
F_104 ( & V_6 -> V_58 . V_118 ) ;
F_50 (uep, gpriv, i) {
V_2 -> V_6 = V_6 ;
snprintf ( V_2 -> V_119 , V_120 , L_25 , V_75 ) ;
V_2 -> V_23 . V_55 = V_2 -> V_119 ;
V_2 -> V_23 . V_115 = & V_121 ;
F_104 ( & V_2 -> V_23 . V_118 ) ;
if ( F_105 ( V_2 ) ) {
V_6 -> V_58 . V_122 = & V_2 -> V_23 ;
V_2 -> V_23 . V_123 = 64 ;
}
else {
V_2 -> V_23 . V_123 = 512 ;
F_106 ( & V_2 -> V_23 . V_118 , & V_6 -> V_58 . V_118 ) ;
}
}
F_107 ( V_6 ) ;
V_45 = F_108 ( V_8 , & V_6 -> V_58 ) ;
if ( V_45 )
goto V_124;
F_109 ( V_8 , L_26 ) ;
return 0 ;
V_124:
F_65 ( V_6 -> V_2 ) ;
V_109:
F_65 ( V_6 ) ;
return V_45 ;
}
void T_4 F_110 ( struct V_32 * V_33 )
{
struct V_5 * V_6 = F_24 ( V_33 ) ;
F_111 ( & V_6 -> V_58 ) ;
F_112 ( V_6 ) ;
F_65 ( V_6 -> V_2 ) ;
F_65 ( V_6 ) ;
}
