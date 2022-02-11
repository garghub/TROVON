static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
V_8 = F_3 ( V_6 , V_3 , V_4 ) ;
F_4 ( & V_6 -> V_9 , L_1 , V_3 , V_4 ,
V_8 < 0 ? L_2 : L_3 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
V_8 = F_6 ( V_6 , V_3 ) ;
F_4 ( & V_6 -> V_9 , L_4 , V_3 , V_8 ,
V_8 < 0 ? L_2 : L_3 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_10 )
{
T_1 V_4 ;
int V_8 ;
V_4 = ( V_10 << V_11 ) |
( V_2 -> V_12 << V_13 ) ;
V_8 = F_1 ( V_2 , V_14 , V_4 ) ;
if ( V_8 == 0 )
V_2 -> V_10 = V_10 ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_10 << V_15 ) |
( V_2 -> V_16 << V_17 ) |
( V_2 -> V_18 << V_19 ) ;
return F_1 ( V_2 , V_20 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_10 << V_11 ) |
( V_2 -> V_12 << V_13 ) ;
return F_1 ( V_2 , V_14 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_21 << V_22 ) |
( V_2 -> V_23 -> V_24 << V_25 ) ;
return F_1 ( V_2 , V_26 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_23 -> V_27 << V_28 ) |
( V_2 -> V_23 -> V_29 << V_30 ) ;
return F_1 ( V_2 , V_31 , V_4 ) ;
}
static void F_12 ( long unsigned int V_32 )
{
struct V_33 * V_7 = F_13 ( (struct V_5 * ) V_32 ) ;
struct V_1 * V_2 = F_14 ( V_7 ) ;
struct V_34 * V_23 = V_2 -> V_23 ;
F_15 ( V_23 -> V_35 , 0 ) ;
}
static int F_16 ( struct V_5 * V_6 , bool V_36 )
{
int V_8 , V_37 ;
struct V_33 * V_7 = F_13 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_7 ) ;
struct V_34 * V_23 = V_2 -> V_23 ;
V_37 = F_17 ( & V_2 -> V_38 ) ;
if ( ! V_36 ) {
V_8 = F_1 ( V_2 , V_14 , 0 ) ;
if ( V_8 < 0 )
goto V_39;
F_18 ( & V_2 -> V_38 ,
V_40 + F_19 ( V_41 ) ) ;
return 0 ;
}
if ( V_37 )
F_15 ( V_23 -> V_35 , 0 ) ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 < 0 )
goto V_39;
F_15 ( V_23 -> V_35 , 1 ) ;
return 0 ;
V_39:
F_20 ( & V_6 -> V_9 , L_5 ,
V_36 ? L_6 : L_7 , V_8 ) ;
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
V_8 = F_5 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 &= ~ V_43 ;
V_8 &= ~ ( V_44 | V_45 ) ;
if ( V_8 > 0 )
F_4 ( & V_6 -> V_9 , L_8 , V_8 ) ;
return V_8 ;
}
static int F_22 ( struct V_33 * V_7 , T_2 V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
V_4 = F_23 ( V_4 , V_46 , V_47 ) ;
V_4 = V_4 / V_48 - 1 ;
V_2 -> V_21 = V_4 ;
return F_10 ( V_2 ) ;
}
static int F_24 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
* V_4 = ( T_2 ) ( V_2 -> V_21 + 1 ) * V_48 ;
return 0 ;
}
static int F_25 ( struct V_33 * V_7 , T_2 V_49 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
V_49 = F_26 ( V_49 ) ;
V_49 = F_27 ( V_49 , V_50 ) ;
V_2 -> V_12 = V_49 ;
return F_9 ( V_2 ) ;
}
static int F_28 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
* V_4 = F_29 ( ( T_2 ) V_2 -> V_12 ,
V_50 ) ;
return 0 ;
}
static int F_30 ( struct V_33 * V_7 , T_2 V_49 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
V_49 = F_26 ( V_49 ) ;
V_49 = F_27 ( V_49 , V_51 ) ;
V_2 -> V_16 = V_49 ;
return F_8 ( V_2 ) ;
}
static int F_31 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
* V_4 = F_29 ( ( T_2 ) V_2 -> V_16 ,
V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_33 * V_7 , T_2 V_49 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
V_49 = F_26 ( V_49 ) ;
V_49 = F_27 ( V_49 , V_52 ) ;
V_2 -> V_18 = V_49 ;
return F_8 ( V_2 ) ;
}
static int F_33 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
* V_4 = F_29 ( ( T_2 ) V_2 -> V_18 ,
V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_7 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
return F_16 ( V_6 , V_4 ) ;
}
static int F_35 ( struct V_33 * V_7 , T_2 V_53 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
unsigned int V_10 ;
switch ( V_53 ) {
case V_54 :
V_10 = V_55 ;
break;
case V_56 :
V_10 = V_57 ;
break;
case V_58 :
V_10 = V_59 ;
break;
case V_60 :
V_10 = V_61 ;
break;
default:
return - V_62 ;
}
return F_7 ( V_2 , V_10 ) ;
}
static int F_36 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
* V_4 = V_2 -> V_10 ;
return 0 ;
}
static int F_37 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
int V_63 ;
V_63 = F_21 ( V_2 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_63 & V_64 )
* V_4 = V_65 ;
else if ( V_63 > 0 )
* V_4 = V_66 ;
else
* V_4 = V_67 ;
return 0 ;
}
static int F_38 ( struct V_33 * V_7 , T_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
int V_8 ;
V_8 = F_5 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_4 = V_8 ;
return 0 ;
}
static int F_39 ( struct V_68 * V_69 )
{
struct V_1 * V_9 =
F_40 ( V_69 -> V_70 , struct V_1 , V_71 ) ;
int V_8 = 0 ;
switch ( V_69 -> V_72 ) {
case V_73 :
V_8 = F_22 ( & V_9 -> V_7 , V_69 -> V_4 ) ;
break;
case V_74 :
V_8 = F_25 ( & V_9 -> V_7 , V_69 -> V_4 ) ;
break;
case V_75 :
V_8 = F_30 ( & V_9 -> V_7 , V_69 -> V_4 ) ;
break;
case V_76 :
V_8 = F_32 ( & V_9 -> V_7 , V_69 -> V_4 ) ;
break;
case V_77 :
V_8 = F_34 ( & V_9 -> V_7 , V_69 -> V_4 ) ;
break;
case V_78 :
V_8 = F_35 ( & V_9 -> V_7 , V_69 -> V_4 ) ;
break;
default:
V_8 = - V_62 ;
}
return V_8 ;
}
static int F_41 ( struct V_68 * V_69 )
{
struct V_1 * V_9 =
F_40 ( V_69 -> V_70 , struct V_1 , V_71 ) ;
int V_8 = 0 ;
switch ( V_69 -> V_72 ) {
case V_73 :
V_8 = F_24 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
case V_74 :
V_8 = F_28 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
case V_75 :
V_8 = F_31 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
case V_76 :
V_8 = F_33 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
case V_78 :
V_8 = F_36 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
case V_79 :
V_8 = F_37 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
#ifndef F_42
case V_80 :
V_8 = F_38 ( & V_9 -> V_7 , & V_69 -> V_4 ) ;
break;
#endif
default:
V_8 = - V_62 ;
}
return V_8 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
V_8 = F_5 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
F_4 ( & V_6 -> V_9 , L_9 , V_8 ) ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_21 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_8 ? - V_81 : 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_82 )
{
struct V_34 * V_23 = V_2 -> V_23 ;
int V_8 ;
F_15 ( V_23 -> V_83 , V_82 ) ;
F_45 ( 100 , 100 + 1 ) ;
if ( V_82 ) {
V_8 = F_43 ( V_2 ) ;
if ( V_8 < 0 ) {
F_44 ( V_2 , 0 ) ;
return V_8 ;
}
}
return 0 ;
}
static int F_46 ( struct V_33 * V_7 , int V_82 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
int V_8 = 0 ;
F_47 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_85 == ! V_82 ) {
V_8 = F_44 ( V_2 , ! ! V_82 ) ;
if ( V_8 < 0 )
goto V_86;
}
V_2 -> V_85 += V_82 ? 1 : - 1 ;
F_48 ( V_2 -> V_85 < 0 ) ;
V_86:
F_49 ( & V_2 -> V_84 ) ;
return V_8 ;
}
static int F_50 ( struct V_33 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
struct V_87 * V_88 = V_6 -> V_88 ;
struct V_1 * V_2 = F_14 ( V_7 ) ;
int V_8 ;
if ( ! F_51 ( V_88 , V_89 ) ) {
F_20 ( & V_6 -> V_9 , L_10 ) ;
return - V_90 ;
}
V_8 = F_46 ( & V_2 -> V_7 , 1 ) ;
if ( V_8 < 0 ) {
F_20 ( & V_6 -> V_9 , L_11 ) ;
} else {
F_4 ( & V_6 -> V_9 , L_12 ) ;
F_46 ( & V_2 -> V_7 , 0 ) ;
}
return V_8 ;
}
static int F_52 ( struct V_33 * V_7 , struct V_91 * V_92 )
{
return F_46 ( V_7 , 1 ) ;
}
static int F_53 ( struct V_33 * V_7 , struct V_91 * V_92 )
{
return F_46 ( V_7 , 0 ) ;
}
static int F_54 ( struct V_93 * V_9 )
{
struct V_5 * V_6 = F_55 ( V_9 ) ;
struct V_33 * V_94 = F_13 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_94 ) ;
int V_95 ;
if ( V_2 -> V_85 == 0 )
return 0 ;
V_95 = F_44 ( V_2 , 0 ) ;
F_4 ( & V_6 -> V_9 , L_13 , V_95 < 0 ? L_14 : L_3 ) ;
return V_95 ;
}
static int F_56 ( struct V_93 * V_9 )
{
struct V_5 * V_6 = F_55 ( V_9 ) ;
struct V_33 * V_94 = F_13 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_94 ) ;
int V_95 ;
if ( V_2 -> V_85 == 0 )
return 0 ;
V_95 = F_44 ( V_2 , 1 ) ;
F_4 ( & V_6 -> V_9 , L_15 , V_95 < 0 ? L_2 : L_3 ) ;
return V_95 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_33 * V_7 = F_13 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_7 ) ;
struct V_34 * V_23 = V_2 -> V_23 ;
int V_8 ;
if ( ! F_58 ( V_23 -> V_83 ) )
return - V_62 ;
V_8 = F_59 ( V_23 -> V_83 , 0 ) ;
if ( V_8 < 0 )
goto V_96;
F_60 ( & V_6 -> V_9 , L_16 ) ;
if ( ! F_58 ( V_23 -> V_35 ) ) {
V_8 = - V_62 ;
goto V_97;
}
V_8 = F_59 ( V_23 -> V_35 , 0 ) ;
if ( V_8 < 0 )
goto V_98;
return 0 ;
V_98:
F_61 ( V_23 -> V_35 ) ;
V_97:
F_59 ( V_23 -> V_83 , 0 ) ;
V_96:
F_61 ( V_23 -> V_83 ) ;
return V_8 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_33 * V_7 = F_13 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_7 ) ;
struct V_34 * V_23 = V_2 -> V_23 ;
int V_8 ;
V_8 = F_59 ( V_23 -> V_35 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_59 ( V_23 -> V_83 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
F_61 ( V_23 -> V_35 ) ;
F_61 ( V_23 -> V_83 ) ;
return 0 ;
}
static void * F_63 ( struct V_5 * V_6 )
{
static struct V_34 V_99 ;
if ( F_64 ( & V_6 -> V_9 ) ) {
V_99 . V_83 =
F_65 ( F_66 ( & ( V_6 -> V_9 ) ,
NULL , 2 , V_100 ) ) ;
V_99 . V_35 =
F_65 ( F_66 ( & ( V_6 -> V_9 ) ,
NULL , 0 , V_100 ) ) ;
V_99 . V_101 =
F_65 ( F_66 ( & ( V_6 -> V_9 ) ,
NULL , 1 , V_100 ) ) ;
} else {
V_99 . V_83 = - 1 ;
V_99 . V_35 = - 1 ;
V_99 . V_101 = - 1 ;
}
F_60 ( & V_6 -> V_9 , L_17 ,
V_99 . V_83 , V_99 . V_35 ,
V_99 . V_101 ) ;
V_99 . V_27 = 1 ;
V_99 . V_29 = 0 ;
V_99 . V_24 = 0 ;
return & V_99 ;
}
static int F_67 ( struct V_5 * V_6 ,
const struct V_102 * V_72 )
{
int V_39 = 0 ;
struct V_1 * V_2 ;
unsigned int V_103 ;
int V_8 ;
V_2 = F_68 ( sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 ) {
F_20 ( & V_6 -> V_9 , L_18 ) ;
return - V_105 ;
}
V_2 -> V_23 = V_6 -> V_9 . V_99 ;
if ( ! V_2 -> V_23 || F_64 ( & V_6 -> V_9 ) )
V_2 -> V_23 = F_63 ( V_6 ) ;
F_69 ( & V_2 -> V_7 , V_6 , & V_106 ) ;
V_2 -> V_7 . V_107 = & V_108 ;
V_2 -> V_7 . V_109 |= V_110 ;
V_2 -> V_10 = V_54 ;
V_2 -> V_21 = V_47 / V_48 - 1 ;
V_8 =
F_70 ( & V_2 -> V_71 ,
F_71 ( V_111 ) ) ;
if ( V_8 ) {
F_20 ( & V_6 -> V_9 , L_19 ) ;
goto V_112;
}
for ( V_103 = 0 ; V_103 < F_71 ( V_111 ) ; V_103 ++ )
F_72 ( & V_2 -> V_71 , & V_111 [ V_103 ] ,
NULL ) ;
if ( V_2 -> V_71 . error ) {
F_20 ( & V_6 -> V_9 , L_20 ) ;
goto V_112;
}
V_2 -> V_7 . V_71 = & V_2 -> V_71 ;
V_39 = F_73 ( & V_2 -> V_7 . V_113 , 0 , NULL ) ;
if ( V_39 ) {
F_20 ( & V_6 -> V_9 , L_21 ) ;
goto V_114;
}
V_2 -> V_7 . V_113 . V_115 = V_116 ;
F_74 ( & V_2 -> V_84 ) ;
F_75 ( & V_2 -> V_38 , F_12 ,
( unsigned long ) V_6 ) ;
V_39 = F_57 ( V_6 ) ;
if ( V_39 ) {
F_20 ( & V_6 -> V_9 , L_22 ) ;
goto V_112;
}
if ( F_76 ( & V_6 -> V_9 ) )
V_39 = F_77 ( & V_2 -> V_7 , NULL , V_117 ) ;
return 0 ;
V_112:
F_78 ( & V_2 -> V_7 . V_113 ) ;
F_79 ( & V_2 -> V_71 ) ;
V_114:
F_80 ( & V_2 -> V_7 ) ;
F_81 ( V_2 ) ;
return V_39 ;
}
static int F_82 ( struct V_5 * V_6 )
{
struct V_33 * V_7 = F_13 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_7 ) ;
int V_8 ;
F_78 ( & V_2 -> V_7 . V_113 ) ;
F_79 ( & V_2 -> V_71 ) ;
F_80 ( V_7 ) ;
F_83 ( V_7 ) ;
F_17 ( & V_2 -> V_38 ) ;
V_8 = F_62 ( V_6 ) ;
if ( V_8 < 0 )
goto V_118;
F_81 ( V_2 ) ;
return 0 ;
V_118:
F_20 ( & V_6 -> V_9 , L_22 ) ;
return V_8 ;
}
static T_4 int F_84 ( void )
{
return F_85 ( & V_119 ) ;
}
static T_5 void F_86 ( void )
{
F_87 ( & V_119 ) ;
}
