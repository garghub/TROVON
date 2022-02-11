static T_1 * F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
T_1 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( V_4 ) )
return NULL ;
F_4 ( V_4 , * V_3 ) ;
return V_4 ;
}
static void F_5 ( T_1 * V_4 , unsigned long * V_3 )
{
if ( ! V_4 )
return;
F_6 ( V_4 , * V_3 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
F_11 ( & V_8 -> V_13 ) ;
F_12 ( & V_8 -> V_13 , & V_6 -> V_14 ) ;
V_8 -> V_15 . V_16 = 0 ;
V_8 -> V_15 . V_17 = - V_18 ;
F_13 ( V_10 , L_1 ,
F_14 ( V_12 ) ,
V_8 -> V_15 . V_19 ) ;
}
static struct V_7 * F_15 ( struct V_5 * V_6 )
{
if ( F_16 ( & V_6 -> V_14 ) )
return NULL ;
return F_17 ( V_6 -> V_14 . V_20 , struct V_7 , V_13 ) ;
}
static int F_18 ( struct V_5 * V_6 , int V_21 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 * V_4 ;
unsigned long V_3 ;
int V_22 = 0 ;
if ( ! V_6 -> V_23 ) {
F_19 ( V_10 , L_2 ) ;
return - V_24 ;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
V_8 = F_15 ( V_6 ) ;
if ( V_8 ) {
if ( V_21 )
V_22 = V_6 -> V_23 -> V_21 ( V_6 , V_8 ) ;
else
V_22 = V_6 -> V_23 -> V_25 ( V_6 , V_8 ) ;
}
F_5 ( V_4 , & V_3 ) ;
return V_22 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_17 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
F_13 ( V_10 , L_3 , F_14 ( V_12 ) ) ;
F_11 ( & V_8 -> V_13 ) ;
V_8 -> V_15 . V_17 = V_17 ;
V_8 -> V_15 . V_26 ( & V_6 -> V_27 , & V_8 -> V_15 ) ;
if ( 0 == V_17 )
F_21 ( V_6 ) ;
}
static void F_22 ( struct V_5 * V_6 , int V_28 )
{
F_23 ( V_6 , V_29 , V_28 ) ;
}
static void F_24 ( struct V_5 * V_6 , int V_28 )
{
F_23 ( V_6 , V_30 , V_28 ) ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = F_10 ( V_6 ) ;
F_26 ( V_12 ) ;
F_20 ( V_6 , V_8 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_31 * V_15 = & V_8 -> V_15 ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
void * V_32 ;
int V_33 , V_34 ;
int V_35 = 0 ;
int V_28 ;
int V_36 ;
V_36 = F_28 ( V_12 ) ;
V_32 = V_15 -> V_32 + V_15 -> V_16 ;
V_33 = V_15 -> V_19 - V_15 -> V_16 ;
V_34 = F_29 ( V_12 , V_32 , V_33 ) ;
if ( V_34 > 0 )
V_15 -> V_16 += V_34 ;
if ( V_34 < V_33 )
V_35 = 0 ;
else if ( V_34 < V_36 )
V_35 = 1 ;
else
V_35 = ! V_15 -> V_37 ;
F_13 ( V_10 , L_4 ,
F_14 ( V_12 ) ,
V_33 , V_34 , V_35 , V_15 -> V_37 ) ;
V_28 = ! V_35 ;
V_6 -> V_23 -> V_38 ( V_6 , V_28 ) ;
F_30 ( V_12 ) ;
if ( V_35 ) {
if ( F_31 ( V_6 ) )
F_26 ( V_12 ) ;
F_20 ( V_6 , V_8 , 0 ) ;
}
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = F_10 ( V_6 ) ;
F_33 ( V_12 ) ;
F_27 ( V_6 , V_8 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_31 * V_15 = & V_8 -> V_15 ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
void * V_32 ;
int V_36 ;
int V_33 , V_39 ;
int V_35 = 0 ;
V_36 = F_28 ( V_12 ) ;
V_32 = V_15 -> V_32 + V_15 -> V_16 ;
V_33 = V_15 -> V_19 - V_15 -> V_16 ;
V_39 = F_35 ( V_12 , V_32 , V_33 ) ;
if ( V_39 < 0 )
return - V_40 ;
V_15 -> V_16 += V_39 ;
if ( ( V_39 == V_33 ) ||
( V_39 < V_36 ) )
V_35 = 1 ;
F_13 ( V_10 , L_5 ,
F_14 ( V_12 ) ,
V_33 , V_39 , V_35 , V_15 -> V_37 ) ;
if ( V_35 ) {
int V_41 = 0 ;
V_6 -> V_23 -> V_38 ( V_6 , V_41 ) ;
F_36 ( V_12 ) ;
F_20 ( V_6 , V_8 , 0 ) ;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = F_10 ( V_6 ) ;
int V_28 = 1 ;
int V_22 ;
V_22 = F_38 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
V_6 -> V_23 -> V_38 ( V_6 , V_28 ) ;
return V_22 ;
}
static int F_39 ( struct V_42 * V_43 ,
struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_5 * V_46 = F_41 ( V_2 ) ;
struct V_11 * V_12 = F_10 ( V_46 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_42 * V_43 ,
struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
if ( ! F_43 ( V_2 , V_47 ) ) {
F_36 ( V_12 ) ;
F_44 ( V_12 ) ;
F_30 ( V_12 ) ;
}
F_39 ( V_43 , V_6 , V_45 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
static int F_45 ( struct V_42 * V_43 ,
struct V_48 * V_23 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
struct V_5 * V_6 ;
int V_49 = V_45 -> V_50 & V_51 ;
int V_52 = F_46 ( V_45 -> V_53 ) & V_54 ;
int V_22 ;
int (* F_47)( struct V_42 * V_43 , struct V_5 * V_6 ,
struct V_44 * V_45 );
char * V_55 ;
V_6 = F_48 ( V_2 , V_52 ) ;
if ( ! F_10 ( V_6 ) ) {
F_19 ( V_10 , L_6 ) ;
return - V_56 ;
}
switch ( V_49 ) {
case V_57 :
V_55 = L_7 ;
F_47 = V_23 -> V_9 ;
break;
case V_58 :
V_55 = L_8 ;
F_47 = V_23 -> V_59 ;
break;
case V_60 :
V_55 = L_9 ;
F_47 = V_23 -> V_61 ;
break;
default:
F_49 ( V_10 , L_10 , V_49 ) ;
F_47 = NULL ;
V_22 = - V_56 ;
}
if ( F_47 ) {
F_13 ( V_10 , L_11 , V_23 -> V_62 , V_52 , V_55 ) ;
V_22 = F_47 ( V_43 , V_6 , V_45 ) ;
}
return V_22 ;
}
static int F_50 ( struct V_42 * V_43 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
V_2 -> V_65 . V_66 = F_51 ( V_64 ) ;
F_13 ( V_10 , L_12 ,
F_52 ( V_64 ) ,
V_2 -> V_65 . V_66 ) ;
return 0 ;
}
static int F_53 ( struct V_42 * V_43 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_5 * V_46 = F_41 ( V_2 ) ;
struct V_11 * V_12 = F_10 ( V_46 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
struct V_44 V_45 ;
struct V_48 * V_67 = NULL ;
int V_68 = F_54 ( V_64 ) ;
int V_22 = 0 ;
F_13 ( V_10 , L_13 , V_68 ) ;
switch ( V_68 ) {
case V_69 :
V_46 -> V_23 = & V_70 ;
break;
case V_71 :
V_46 -> V_23 = & V_72 ;
break;
case V_73 :
V_46 -> V_23 = & V_74 ;
break;
default:
return V_22 ;
}
F_55 ( V_43 , & V_45 ) ;
switch ( V_45 . V_50 & V_75 ) {
case V_76 :
switch ( V_45 . V_77 ) {
case V_78 :
V_67 = & V_79 ;
break;
}
}
if ( V_67 )
V_22 = F_45 ( V_43 , V_67 , & V_45 ) ;
else
V_22 = V_2 -> V_80 -> V_81 ( & V_2 -> V_65 , & V_45 ) ;
if ( V_22 < 0 )
F_56 ( V_12 ) ;
return V_22 ;
}
static int F_57 ( struct V_42 * V_43 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_5 * V_6 ;
struct V_11 * V_12 ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
int V_82 , V_22 ;
if ( ! V_64 -> V_29 ) {
F_19 ( V_10 , L_14 , V_83 ) ;
return - V_24 ;
}
F_13 ( V_10 , L_15 , V_64 -> V_29 ) ;
F_58 (pipe, priv, i) {
if ( ! ( V_64 -> V_29 & ( 1 << V_82 ) ) )
continue;
V_6 = F_59 ( V_12 ) ;
V_22 = F_60 ( V_6 ) ;
if ( V_22 < 0 )
F_19 ( V_10 , L_16 , V_82 , V_22 ) ;
}
return 0 ;
}
static int F_61 ( struct V_42 * V_43 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_5 * V_6 ;
struct V_11 * V_12 ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
int V_82 , V_22 ;
if ( ! V_64 -> V_30 ) {
F_19 ( V_10 , L_14 , V_83 ) ;
return - V_24 ;
}
F_13 ( V_10 , L_17 , V_64 -> V_30 ) ;
F_58 (pipe, priv, i) {
if ( ! ( V_64 -> V_30 & ( 1 << V_82 ) ) )
continue;
V_6 = F_59 ( V_12 ) ;
V_22 = F_60 ( V_6 ) ;
if ( V_22 < 0 )
F_19 ( V_10 , L_18 , V_82 , V_22 ) ;
}
return 0 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_42 * V_43 = F_63 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_64 ( V_43 ) ;
if ( ! V_12 )
return - V_24 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_12 -> V_84 = V_6 ;
F_65 ( & V_6 -> V_14 ) ;
return 0 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_7 * V_8 ;
int V_41 = 0 ;
F_36 ( V_12 ) ;
F_22 ( V_6 , V_41 ) ;
F_24 ( V_6 , V_41 ) ;
while ( 1 ) {
V_8 = F_15 ( V_6 ) ;
if ( ! V_8 )
break;
F_20 ( V_6 , V_8 , - V_85 ) ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
int V_82 ;
struct V_5 * V_6 ;
F_68 (uep, gpriv, i)
V_6 -> V_12 = NULL ;
}
static int F_69 ( struct V_86 * V_27 ,
const struct V_87 * V_88 )
{
struct V_5 * V_6 = F_70 ( V_27 ) ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_42 * V_43 = F_63 ( V_2 ) ;
struct V_11 * V_12 ;
T_1 * V_4 ;
unsigned long V_3 ;
int V_22 = - V_24 ;
if ( V_6 -> V_12 )
return 0 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
V_12 = F_71 ( V_43 , V_88 ) ;
if ( V_12 ) {
V_6 -> V_12 = V_12 ;
V_12 -> V_84 = V_6 ;
F_65 ( & V_6 -> V_14 ) ;
if ( F_72 ( V_88 ) )
V_6 -> V_23 = & V_89 ;
else
V_6 -> V_23 = & V_90 ;
V_22 = 0 ;
}
F_5 ( V_4 , & V_3 ) ;
return V_22 ;
}
static int F_73 ( struct V_86 * V_27 )
{
struct V_5 * V_6 = F_70 ( V_27 ) ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
T_1 * V_4 ;
unsigned long V_3 ;
int V_22 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
V_22 = F_66 ( V_6 ) ;
F_5 ( V_4 , & V_3 ) ;
return V_22 ;
}
static struct V_31 * F_74 ( struct V_86 * V_27 ,
T_2 V_91 )
{
struct V_7 * V_8 ;
V_8 = F_75 ( sizeof *V_8 , V_91 ) ;
if ( ! V_8 )
return NULL ;
F_65 ( & V_8 -> V_13 ) ;
return & V_8 -> V_15 ;
}
static void F_76 ( struct V_86 * V_27 ,
struct V_31 * V_15 )
{
struct V_7 * V_8 = F_77 ( V_15 ) ;
F_78 ( ! F_16 ( & V_8 -> V_13 ) ) ;
F_79 ( V_8 ) ;
}
static int F_80 ( struct V_86 * V_27 , struct V_31 * V_15 ,
T_2 V_91 )
{
struct V_5 * V_6 = F_70 ( V_27 ) ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_7 * V_8 = F_77 ( V_15 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
T_1 * V_4 ;
unsigned long V_3 ;
int V_22 = 0 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_81 ( V_2 ) ||
F_82 ( ! V_2 -> V_80 ) ||
F_82 ( ! V_12 ) )
V_22 = - V_92 ;
else
F_7 ( V_6 , V_8 ) ;
F_5 ( V_4 , & V_3 ) ;
F_21 ( V_6 ) ;
return V_22 ;
}
static int F_83 ( struct V_86 * V_27 , struct V_31 * V_15 )
{
struct V_5 * V_6 = F_70 ( V_27 ) ;
struct V_7 * V_8 = F_77 ( V_15 ) ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
T_1 * V_4 ;
unsigned long V_3 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
F_20 ( V_6 , V_8 , - V_85 ) ;
F_5 ( V_4 , & V_3 ) ;
return 0 ;
}
static int F_84 ( struct V_86 * V_27 , int V_93 , int V_94 )
{
struct V_5 * V_6 = F_70 ( V_27 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
T_1 * V_4 ;
unsigned long V_3 ;
int V_22 = - V_95 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( ! F_15 ( V_6 ) ) {
F_13 ( V_10 , L_19 ,
V_93 , F_14 ( V_12 ) ) ;
if ( V_93 )
F_56 ( V_12 ) ;
else
F_36 ( V_12 ) ;
if ( V_93 && V_94 )
F_85 ( V_2 , V_47 ) ;
else
F_86 ( V_2 , V_47 ) ;
V_22 = 0 ;
}
F_5 ( V_4 , & V_3 ) ;
return V_22 ;
}
static int F_87 ( struct V_86 * V_27 , int V_96 )
{
return F_84 ( V_27 , V_96 , 0 ) ;
}
static int F_88 ( struct V_86 * V_27 )
{
return F_84 ( V_27 , 1 , 1 ) ;
}
static int F_89 ( struct V_42 * V_43 , T_3 V_17 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_5 * V_46 = F_41 ( V_2 ) ;
struct V_97 * V_98 = F_90 ( V_43 ) ;
struct V_9 * V_10 = F_91 ( V_43 ) ;
T_1 * V_4 ;
unsigned long V_3 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
F_85 ( V_2 , V_17 ) ;
if ( ! ( F_43 ( V_2 , V_99 ) &&
F_43 ( V_2 , V_100 ) ) )
goto V_101;
F_13 ( V_10 , L_20 ) ;
F_92 ( V_43 ) ;
F_67 ( V_2 ) ;
F_62 ( V_46 ) ;
F_93 ( V_43 , 1 ) ;
F_94 ( V_43 , 1 ) ;
F_95 ( V_43 , 1 ) ;
V_98 -> V_102 = F_50 ;
V_98 -> V_103 = F_53 ;
V_98 -> V_104 = F_57 ;
V_98 -> V_105 = F_61 ;
V_98 -> V_106 = 0 ;
V_98 -> V_107 = 0 ;
F_96 ( V_43 , V_98 ) ;
V_101:
F_5 ( V_4 , & V_3 ) ;
return 0 ;
}
static int F_97 ( struct V_42 * V_43 , T_3 V_17 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
struct V_97 * V_98 = F_90 ( V_43 ) ;
struct V_5 * V_46 = F_41 ( V_2 ) ;
struct V_9 * V_10 = F_91 ( V_43 ) ;
T_1 * V_4 ;
unsigned long V_3 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
F_86 ( V_2 , V_17 ) ;
if ( ! F_43 ( V_2 , V_99 ) &&
! F_43 ( V_2 , V_100 ) )
goto V_108;
V_98 -> V_102 = NULL ;
V_98 -> V_103 = NULL ;
V_98 -> V_104 = NULL ;
V_98 -> V_105 = NULL ;
V_98 -> V_106 = 0 ;
V_98 -> V_107 = 0 ;
F_96 ( V_43 , V_98 ) ;
F_98 ( V_46 ) ;
V_2 -> V_65 . V_66 = V_109 ;
F_93 ( V_43 , 0 ) ;
F_94 ( V_43 , 0 ) ;
F_95 ( V_43 , 0 ) ;
F_5 ( V_4 , & V_3 ) ;
if ( V_2 -> V_80 &&
V_2 -> V_80 -> V_110 )
V_2 -> V_80 -> V_110 ( & V_2 -> V_65 ) ;
F_13 ( V_10 , L_21 ) ;
return 0 ;
V_108:
F_5 ( V_4 , & V_3 ) ;
return 0 ;
}
int F_99 ( struct V_111 * V_80 ,
int (* F_100)( struct V_112 * ) )
{
struct V_1 * V_2 = V_113 ;
struct V_42 * V_43 ;
struct V_9 * V_10 ;
int V_22 ;
if ( ! F_100 ||
! V_80 ||
! V_80 -> V_81 ||
V_80 -> V_66 != V_114 )
return - V_56 ;
if ( ! V_2 )
return - V_115 ;
if ( V_2 -> V_80 )
return - V_40 ;
V_10 = F_9 ( V_2 ) ;
V_43 = F_63 ( V_2 ) ;
V_2 -> V_80 = V_80 ;
V_2 -> V_65 . V_10 . V_80 = & V_80 -> V_80 ;
V_22 = F_101 ( & V_2 -> V_65 . V_10 ) ;
if ( V_22 ) {
F_19 ( V_10 , L_22 , V_22 ) ;
goto V_116;
}
V_22 = F_100 ( & V_2 -> V_65 ) ;
if ( V_22 ) {
F_19 ( V_10 , L_23 ,
V_80 -> V_80 . V_62 , V_22 ) ;
goto V_117;
}
F_13 ( V_10 , L_24 , V_80 -> V_80 . V_62 ) ;
return F_89 ( V_43 , V_100 ) ;
V_117:
F_102 ( & V_2 -> V_65 . V_10 ) ;
V_116:
V_2 -> V_80 = NULL ;
V_2 -> V_65 . V_10 . V_80 = NULL ;
return V_22 ;
}
int F_103 ( struct V_111 * V_80 )
{
struct V_1 * V_2 = V_113 ;
struct V_42 * V_43 ;
struct V_9 * V_10 = F_9 ( V_2 ) ;
if ( ! V_2 )
return - V_115 ;
if ( ! V_80 ||
! V_80 -> V_118 ||
V_80 != V_2 -> V_80 )
return - V_56 ;
V_10 = F_9 ( V_2 ) ;
V_43 = F_63 ( V_2 ) ;
F_97 ( V_43 , V_100 ) ;
F_102 ( & V_2 -> V_65 . V_10 ) ;
V_2 -> V_80 = NULL ;
if ( V_80 -> V_110 )
V_80 -> V_110 ( & V_2 -> V_65 ) ;
V_80 -> V_118 ( & V_2 -> V_65 ) ;
F_13 ( V_10 , L_25 , V_80 -> V_80 . V_62 ) ;
return 0 ;
}
static int F_104 ( struct V_112 * V_65 )
{
struct V_1 * V_2 = F_105 ( V_65 ) ;
struct V_42 * V_43 = F_63 ( V_2 ) ;
return F_106 ( V_43 ) ;
}
static int F_107 ( struct V_42 * V_43 )
{
return F_89 ( V_43 , V_99 ) ;
}
static int F_108 ( struct V_42 * V_43 )
{
return F_97 ( V_43 , V_99 ) ;
}
int T_4 F_109 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = F_91 ( V_43 ) ;
int V_119 = F_110 ( V_43 , V_119 ) ;
int V_82 ;
V_2 = F_75 ( sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_2 ) {
F_19 ( V_10 , L_26 ) ;
return - V_121 ;
}
V_6 = F_75 ( sizeof( struct V_5 ) * V_119 , V_120 ) ;
if ( ! V_6 ) {
F_19 ( V_10 , L_27 ) ;
goto V_122;
}
F_111 ( V_43 , & V_2 -> V_98 , V_123 ) ;
V_2 -> V_98 . V_62 = L_28 ;
V_2 -> V_98 . V_124 = F_107 ;
V_2 -> V_98 . V_125 = F_108 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_126 = V_119 ;
F_112 ( V_2 ) ;
F_113 ( & V_2 -> V_65 . V_10 ) ;
F_114 ( & V_2 -> V_65 . V_10 , L_28 ) ;
V_2 -> V_65 . V_10 . V_127 = V_10 ;
V_2 -> V_65 . V_62 = L_29 ;
V_2 -> V_65 . V_128 = & V_129 ;
V_2 -> V_65 . V_130 = 1 ;
F_65 ( & V_2 -> V_65 . V_131 ) ;
F_68 (uep, gpriv, i) {
V_6 -> V_2 = V_2 ;
snprintf ( V_6 -> V_132 , V_133 , L_30 , V_82 ) ;
V_6 -> V_27 . V_62 = V_6 -> V_132 ;
V_6 -> V_27 . V_128 = & V_134 ;
F_65 ( & V_6 -> V_27 . V_131 ) ;
F_65 ( & V_6 -> V_14 ) ;
if ( F_31 ( V_6 ) ) {
V_2 -> V_65 . V_135 = & V_6 -> V_27 ;
V_6 -> V_27 . V_136 = 64 ;
}
else {
V_6 -> V_27 . V_136 = 512 ;
F_12 ( & V_6 -> V_27 . V_131 , & V_2 -> V_65 . V_131 ) ;
}
}
V_113 = V_2 ;
F_115 ( V_10 , L_31 ) ;
return 0 ;
V_122:
F_79 ( V_2 ) ;
return - V_121 ;
}
void T_5 F_116 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_40 ( V_43 ) ;
F_79 ( V_2 -> V_6 ) ;
F_79 ( V_2 ) ;
}
