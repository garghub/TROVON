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
V_12 -> V_22 , V_12 -> V_23 , V_12 -> V_24 ) ;
F_13 ( V_9 ) ;
F_5 ( V_11 , L_2 ,
F_6 ( V_9 ) ,
V_12 -> V_23 ) ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_17 * V_18 ,
enum V_25 V_26 )
{
struct V_3 * V_4 = F_9 ( V_18 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
if ( V_18 -> V_27 != V_28 ) {
F_15 ( V_11 , L_3 ) ;
return - V_29 ;
}
if ( V_12 -> V_27 == V_28 ) {
V_18 -> V_27 = F_16 ( V_11 , V_18 -> V_22 , V_18 -> V_23 , V_26 ) ;
} else {
F_17 ( V_11 , V_12 -> V_27 , V_12 -> V_23 , V_26 ) ;
V_18 -> V_27 = V_12 -> V_27 ;
}
if ( F_18 ( V_11 , V_18 -> V_27 ) ) {
F_15 ( V_11 , L_4 , V_18 -> V_27 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_19 ( struct V_10 * V_11 ,
struct V_17 * V_18 ,
enum V_25 V_26 )
{
struct V_3 * V_4 = F_9 ( V_18 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
if ( V_18 -> V_27 == V_28 ) {
F_15 ( V_11 , L_5 ) ;
return - V_29 ;
}
if ( V_12 -> V_27 == V_28 )
F_20 ( V_11 , V_18 -> V_27 , V_18 -> V_23 , V_26 ) ;
else
F_21 ( V_11 , V_12 -> V_27 , V_12 -> V_23 , V_26 ) ;
V_18 -> V_27 = V_28 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 , int V_30 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
enum V_25 V_26 ;
V_26 = F_23 ( V_9 ) ? V_31 : V_32 ;
if ( V_30 )
return F_14 ( V_11 , V_18 , V_26 ) ;
else
return F_19 ( V_11 , V_18 , V_26 ) ;
}
static int F_24 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_1 * V_35 = F_26 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_35 ) ;
F_27 ( V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ! F_29 ( V_7 , V_36 ) ) {
F_30 ( V_9 ) ;
F_31 ( V_9 ) ;
F_32 ( V_9 ) ;
}
F_24 ( V_16 , V_2 , V_34 ) ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_39 = V_34 -> V_40 & V_41 ;
int V_42 = F_34 ( V_34 -> V_43 ) & V_44 ;
int V_45 ;
int (* F_35)( struct V_15 * V_16 , struct V_1 * V_2 ,
struct V_33 * V_34 );
char * V_46 ;
V_2 = F_36 ( V_7 , V_42 ) ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 ) {
F_15 ( V_11 , L_6 ) ;
V_45 = - V_47 ;
goto V_48;
}
switch ( V_39 ) {
case V_49 :
V_46 = L_7 ;
F_35 = V_38 -> V_10 ;
break;
case V_50 :
V_46 = L_8 ;
F_35 = V_38 -> V_51 ;
break;
case V_52 :
V_46 = L_9 ;
F_35 = V_38 -> V_53 ;
break;
default:
F_37 ( V_11 , L_10 , V_39 ) ;
F_35 = NULL ;
V_45 = - V_47 ;
}
if ( F_35 ) {
unsigned long V_54 ;
F_5 ( V_11 , L_11 , V_38 -> V_55 , V_42 , V_46 ) ;
F_38 ( V_16 , V_54 ) ;
V_45 = F_35 ( V_16 , V_2 , V_34 ) ;
F_39 ( V_16 , V_54 ) ;
}
V_48:
F_13 ( V_9 ) ;
return V_45 ;
}
static int F_40 ( struct V_15 * V_16 ,
struct V_56 * V_57 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
V_7 -> V_58 . V_59 = F_41 ( V_16 ) ;
F_5 ( V_11 , L_12 ,
F_42 ( V_57 ) ,
V_7 -> V_58 . V_59 ) ;
return 0 ;
}
static int F_43 ( struct V_15 * V_16 ,
struct V_56 * V_57 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_1 * V_35 = F_26 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_35 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_33 V_34 ;
struct V_37 * V_60 = NULL ;
int V_61 = F_44 ( V_57 ) ;
int V_45 = 0 ;
F_5 ( V_11 , L_13 , V_61 ) ;
switch ( V_61 ) {
case V_62 :
V_9 -> V_38 = & V_63 ;
break;
case V_64 :
V_9 -> V_38 = & V_65 ;
break;
case V_66 :
V_9 -> V_38 = & V_67 ;
break;
default:
return V_45 ;
}
F_45 ( V_16 , & V_34 ) ;
switch ( V_34 . V_40 & V_68 ) {
case V_69 :
switch ( V_34 . V_70 ) {
case V_71 :
V_60 = & V_72 ;
break;
}
}
if ( V_60 )
V_45 = F_33 ( V_16 , V_60 , & V_34 ) ;
else
V_45 = V_7 -> V_73 -> V_74 ( & V_7 -> V_58 , & V_34 ) ;
if ( V_45 < 0 )
F_46 ( V_9 ) ;
return V_45 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_17 * V_18 ;
F_30 ( V_9 ) ;
while ( 1 ) {
V_18 = F_48 ( V_9 , NULL ) ;
if ( ! V_18 )
break;
}
return 0 ;
}
static void F_49 ( struct V_6 * V_7 )
{
int V_75 ;
struct V_1 * V_2 ;
F_50 (uep, gpriv, i)
V_2 -> V_9 = NULL ;
}
static int F_51 ( struct V_76 * V_14 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_53 ( V_7 ) ;
struct V_8 * V_9 ;
int V_45 = - V_29 ;
if ( V_2 -> V_9 ) {
F_54 ( V_2 -> V_9 ) ;
F_31 ( V_2 -> V_9 ) ;
return 0 ;
}
V_9 = F_55 ( V_16 ,
F_56 ( V_78 ) ,
F_57 ( V_78 ) ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_9 -> V_79 = V_2 ;
F_58 ( V_9 , 0 ,
F_59 ( V_78 ) ,
F_60 ( V_78 ) ) ;
if ( F_57 ( V_78 ) )
V_9 -> V_38 = & V_80 ;
else
V_9 -> V_38 = & V_81 ;
V_45 = 0 ;
}
return V_45 ;
}
static int F_61 ( struct V_76 * V_14 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
return F_47 ( V_2 ) ;
}
static struct V_20 * F_62 ( struct V_76 * V_14 ,
T_1 V_82 )
{
struct V_3 * V_4 ;
V_4 = F_63 ( sizeof *V_4 , V_82 ) ;
if ( ! V_4 )
return NULL ;
F_64 ( F_11 ( V_4 ) ) ;
V_4 -> V_12 . V_27 = V_28 ;
return & V_4 -> V_12 ;
}
static void F_65 ( struct V_76 * V_14 ,
struct V_20 * V_12 )
{
struct V_3 * V_4 = F_66 ( V_12 ) ;
F_67 ( ! F_68 ( & V_4 -> V_18 . V_83 ) ) ;
F_69 ( V_4 ) ;
}
static int F_70 ( struct V_76 * V_14 , struct V_20 * V_12 ,
T_1 V_82 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_66 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( F_71 ( V_7 ) ||
F_72 ( ! V_7 -> V_73 ) ||
F_72 ( ! V_9 ) )
return - V_84 ;
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_73 ( struct V_76 * V_14 , struct V_20 * V_12 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
struct V_3 * V_4 = F_66 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_48 ( V_9 , F_11 ( V_4 ) ) ;
F_1 ( V_2 , V_4 , - V_85 ) ;
return 0 ;
}
static int F_74 ( struct V_76 * V_14 , int V_86 , int V_87 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_53 ( V_7 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_54 ;
F_47 ( V_2 ) ;
F_5 ( V_11 , L_14 ,
V_86 , F_6 ( V_9 ) ) ;
F_38 ( V_16 , V_54 ) ;
if ( V_86 )
F_46 ( V_9 ) ;
else
F_30 ( V_9 ) ;
if ( V_86 && V_87 )
F_75 ( V_7 , V_36 ) ;
else
F_76 ( V_7 , V_36 ) ;
F_39 ( V_16 , V_54 ) ;
return 0 ;
}
static int F_77 ( struct V_76 * V_14 , int V_88 )
{
return F_74 ( V_14 , V_88 , 0 ) ;
}
static int F_78 ( struct V_76 * V_14 )
{
return F_74 ( V_14 , 1 , 1 ) ;
}
static int F_79 ( struct V_15 * V_16 , T_2 V_5 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_1 * V_35 = F_26 ( V_7 ) ;
struct V_89 * V_90 = F_80 ( V_16 ) ;
struct V_10 * V_11 = F_81 ( V_16 ) ;
unsigned long V_54 ;
int V_45 = 0 ;
F_38 ( V_16 , V_54 ) ;
F_75 ( V_7 , V_5 ) ;
if ( ! ( F_29 ( V_7 , V_91 ) &&
F_29 ( V_7 , V_92 ) ) )
V_45 = - 1 ;
F_39 ( V_16 , V_54 ) ;
if ( V_45 < 0 )
return 0 ;
F_5 ( V_11 , L_15 ) ;
F_82 ( V_16 ,
F_22 ) ;
F_83 ( V_16 ) ;
F_49 ( V_7 ) ;
V_35 -> V_9 = F_84 ( V_16 ) ;
V_35 -> V_9 -> V_79 = V_35 ;
F_58 ( V_35 -> V_9 , 0 , 0 , 64 ) ;
F_85 ( V_16 , 1 ) ;
F_86 ( V_16 , 1 ) ;
F_87 ( V_16 , 1 ) ;
V_90 -> V_93 = F_40 ;
V_90 -> V_94 = F_43 ;
F_88 ( V_16 , V_90 ) ;
return 0 ;
}
static int F_89 ( struct V_15 * V_16 , T_2 V_5 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_89 * V_90 = F_80 ( V_16 ) ;
struct V_1 * V_35 = F_26 ( V_7 ) ;
struct V_10 * V_11 = F_81 ( V_16 ) ;
unsigned long V_54 ;
int V_45 = 0 ;
F_38 ( V_16 , V_54 ) ;
F_76 ( V_7 , V_5 ) ;
if ( ! F_29 ( V_7 , V_91 ) &&
! F_29 ( V_7 , V_92 ) )
V_45 = - 1 ;
F_39 ( V_16 , V_54 ) ;
if ( V_45 < 0 )
return 0 ;
F_90 ( V_16 ) ;
V_90 -> V_93 = NULL ;
V_90 -> V_94 = NULL ;
F_88 ( V_16 , V_90 ) ;
V_7 -> V_58 . V_59 = V_95 ;
F_85 ( V_16 , 0 ) ;
F_86 ( V_16 , 0 ) ;
F_87 ( V_16 , 0 ) ;
F_47 ( V_35 ) ;
F_5 ( V_11 , L_16 ) ;
return 0 ;
}
static int F_91 ( struct V_96 * V_58 ,
struct V_97 * V_73 )
{
struct V_6 * V_7 = F_92 ( V_58 ) ;
struct V_15 * V_16 = F_53 ( V_7 ) ;
if ( ! V_73 ||
! V_73 -> V_74 ||
V_73 -> V_59 < V_98 )
return - V_47 ;
V_7 -> V_73 = V_73 ;
V_7 -> V_58 . V_11 . V_73 = & V_73 -> V_73 ;
return F_79 ( V_16 , V_92 ) ;
}
static int F_93 ( struct V_96 * V_58 ,
struct V_97 * V_73 )
{
struct V_6 * V_7 = F_92 ( V_58 ) ;
struct V_15 * V_16 = F_53 ( V_7 ) ;
if ( ! V_73 ||
! V_73 -> V_99 )
return - V_47 ;
F_89 ( V_16 , V_92 ) ;
V_7 -> V_58 . V_11 . V_73 = NULL ;
V_7 -> V_73 = NULL ;
return 0 ;
}
static int F_94 ( struct V_96 * V_58 )
{
struct V_6 * V_7 = F_92 ( V_58 ) ;
struct V_15 * V_16 = F_53 ( V_7 ) ;
return F_95 ( V_16 ) ;
}
static int F_96 ( struct V_15 * V_16 )
{
return F_79 ( V_16 , V_91 ) ;
}
static int F_97 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
if ( V_7 -> V_73 &&
V_7 -> V_73 -> V_100 )
V_7 -> V_73 -> V_100 ( & V_7 -> V_58 ) ;
return F_89 ( V_16 , V_91 ) ;
}
int F_98 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = F_81 ( V_16 ) ;
int V_101 = F_99 ( V_16 , V_101 ) ;
int V_75 ;
int V_45 ;
V_7 = F_63 ( sizeof( struct V_6 ) , V_102 ) ;
if ( ! V_7 ) {
F_15 ( V_11 , L_17 ) ;
return - V_103 ;
}
V_2 = F_63 ( sizeof( struct V_1 ) * V_101 , V_102 ) ;
if ( ! V_2 ) {
F_15 ( V_11 , L_18 ) ;
V_45 = - V_103 ;
goto V_104;
}
F_100 ( V_16 , & V_7 -> V_90 , V_105 ) ;
V_7 -> V_90 . V_55 = L_19 ;
V_7 -> V_90 . V_106 = F_96 ;
V_7 -> V_90 . V_107 = F_97 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_108 = V_101 ;
F_101 ( V_7 ) ;
F_102 ( & V_7 -> V_58 . V_11 , L_19 ) ;
V_7 -> V_58 . V_11 . V_109 = V_11 ;
V_7 -> V_58 . V_55 = L_20 ;
V_7 -> V_58 . V_110 = & V_111 ;
V_7 -> V_58 . V_112 = 1 ;
V_45 = F_103 ( & V_7 -> V_58 . V_11 ) ;
if ( V_45 < 0 )
goto V_113;
F_104 ( & V_7 -> V_58 . V_114 ) ;
F_50 (uep, gpriv, i) {
V_2 -> V_7 = V_7 ;
snprintf ( V_2 -> V_115 , V_116 , L_21 , V_75 ) ;
V_2 -> V_14 . V_55 = V_2 -> V_115 ;
V_2 -> V_14 . V_110 = & V_117 ;
F_104 ( & V_2 -> V_14 . V_114 ) ;
if ( F_105 ( V_2 ) ) {
V_7 -> V_58 . V_118 = & V_2 -> V_14 ;
V_2 -> V_14 . V_119 = 64 ;
}
else {
V_2 -> V_14 . V_119 = 512 ;
F_106 ( & V_2 -> V_14 . V_114 , & V_7 -> V_58 . V_114 ) ;
}
}
F_107 ( V_7 ) ;
V_45 = F_108 ( V_11 , & V_7 -> V_58 ) ;
if ( V_45 )
goto V_120;
F_109 ( V_11 , L_22 ) ;
return 0 ;
V_120:
F_110 ( & V_7 -> V_58 . V_11 ) ;
V_113:
F_69 ( V_7 -> V_2 ) ;
V_104:
F_69 ( V_7 ) ;
return V_45 ;
}
void F_111 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
F_112 ( & V_7 -> V_58 ) ;
F_110 ( & V_7 -> V_58 . V_11 ) ;
F_113 ( V_7 ) ;
F_69 ( V_7 -> V_2 ) ;
F_69 ( V_7 ) ;
}
