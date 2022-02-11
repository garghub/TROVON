static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
int V_9 ;
F_3 ( V_8 ) ;
if ( V_8 -> V_10 == V_11 ) {
F_4 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_14 ( V_8 -> V_15 , V_3 ) ;
F_5 ( & V_5 -> V_12 ) ;
} else {
F_6 ( V_8 , L_1 ) ;
V_9 = - V_16 ;
}
F_7 ( V_8 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
F_9 ( V_8 , V_18 , L_2 ,
V_17 ) ;
F_4 ( & V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_19 , V_17 ) ;
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_22 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
F_4 ( & V_5 -> V_12 ) ;
V_22 = F_12 ( & V_5 -> V_19 ) ;
F_5 ( & V_5 -> V_12 ) ;
F_9 ( V_8 , V_18 , L_3 , V_22 ) ;
* V_21 = F_13 ( V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_22 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
V_22 = F_15 ( V_21 ) ;
F_9 ( V_8 , V_18 , L_4 , V_22 ) ;
F_4 ( & V_5 -> V_12 ) ;
F_16 ( & V_5 -> V_19 , & V_5 -> V_23 , V_22 ) ;
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
int V_26 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
F_6 ( V_8 , L_5 ) ;
return - V_27 ;
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_30 V_31 ;
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_32 , V_22 ;
int V_9 ;
V_5 = F_2 ( V_29 , struct V_4 , V_29 ) ;
V_8 = V_5 -> V_8 ;
F_4 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_33 ( V_8 -> V_15 , & V_32 ) ;
F_5 ( & V_5 -> V_12 ) ;
if ( V_9 ) {
F_19 ( & V_5 -> V_29 ) ;
return;
}
V_22 = F_20 ( & V_5 -> V_19 , V_32 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = F_21 ( V_22 ) ;
F_22 ( V_5 -> V_35 , & V_31 ) ;
F_23 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
F_24 ( V_36 , & V_8 -> V_37 ) ;
F_9 ( V_8 , V_18 ,
L_6 ,
V_32 , V_22 ) ;
}
static T_3 F_25 ( const struct V_38 * V_23 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_39 ;
int V_9 ;
V_5 = F_2 ( V_23 , struct V_4 , V_23 ) ;
V_8 = V_5 -> V_8 ;
V_9 = V_5 -> V_13 -> V_40 ( V_8 -> V_15 , & V_39 ) ;
if ( V_9 )
F_26 ( 1 , L_7 , V_9 ) ;
F_9 ( V_8 , V_18 , L_8 , V_39 ) ;
return V_39 ;
}
static int F_27 ( struct V_7 * V_8 )
{
enum V_41 V_42 = V_43 ;
enum V_44 V_45 = V_46 ;
struct V_4 * V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_47 ;
if ( ! V_5 -> V_48 ) {
F_28 ( V_8 , L_9 ) ;
return 0 ;
}
switch ( V_5 -> V_42 ) {
case V_49 :
V_8 -> V_37 |= V_50 ;
V_42 = V_43 ;
break;
case V_51 :
V_8 -> V_37 &= ~ V_50 ;
V_42 = V_52 ;
break;
case V_53 :
F_6 ( V_8 , L_10 ) ;
return - V_54 ;
}
F_4 ( & V_5 -> V_12 ) ;
switch ( V_5 -> V_45 ) {
case V_55 :
V_45 = V_46 ;
break;
case V_56 :
case V_57 :
V_5 -> V_45 = V_55 ;
V_45 = V_58 ;
break;
case V_59 :
V_5 -> V_45 = V_59 ;
V_45 = V_60 ;
break;
case V_61 :
case V_62 :
V_5 -> V_45 = V_59 ;
V_45 = V_63 ;
break;
case V_64 :
V_5 -> V_45 = V_64 ;
V_45 = V_65 ;
break;
case V_66 :
case V_67 :
V_5 -> V_45 = V_64 ;
V_45 = V_68 ;
break;
case V_69 :
V_5 -> V_45 = V_69 ;
V_45 = V_70 ;
break;
case V_71 :
case V_72 :
V_5 -> V_45 = V_69 ;
V_45 = V_73 ;
break;
case V_74 :
V_5 -> V_45 = V_74 ;
V_45 = V_75 ;
break;
case V_76 :
case V_77 :
V_5 -> V_45 = V_74 ;
V_45 = V_78 ;
break;
}
V_5 -> V_13 -> V_79 ( V_8 -> V_15 , V_45 , V_42 ) ;
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
int F_29 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
struct V_82 V_83 ;
struct V_4 * V_5 ;
int V_9 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_47 ;
if ( F_30 ( & V_83 , V_81 -> V_84 , sizeof( V_83 ) ) )
return - V_16 ;
F_9 ( V_8 , V_18 ,
L_11 ,
V_83 . V_42 , V_83 . V_45 ) ;
if ( V_83 . V_37 ) {
F_6 ( V_8 , L_12 ) ;
return - V_85 ;
}
V_5 -> V_48 = 1 ;
V_5 -> V_42 = V_83 . V_42 ;
V_5 -> V_45 = V_83 . V_45 ;
V_9 = F_27 ( V_8 ) ;
if ( V_9 )
return V_9 ;
V_83 . V_45 = V_5 -> V_45 ;
return F_31 ( V_81 -> V_84 , & V_83 ,
sizeof( V_83 ) ) ? - V_16 : 0 ;
}
int F_32 ( struct V_7 * V_8 , struct V_86 * V_2 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_47 ;
V_2 -> V_87 = V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 ;
if ( V_5 -> clock )
V_2 -> V_94 = F_33 ( V_5 -> clock ) ;
else
V_2 -> V_94 = - 1 ;
V_2 -> V_95 = F_34 ( V_55 ) |
F_34 ( V_59 ) |
F_34 ( V_61 ) |
F_34 ( V_62 ) |
F_34 ( V_64 ) |
F_34 ( V_66 ) |
F_34 ( V_67 ) |
F_34 ( V_69 ) |
F_34 ( V_71 ) |
F_34 ( V_72 ) |
F_34 ( V_74 ) |
F_34 ( V_76 ) |
F_34 ( V_77 ) ;
V_2 -> V_96 = F_34 ( V_51 ) | F_34 ( V_49 ) ;
return 0 ;
}
void F_35 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
if ( V_5 -> clock ) {
F_36 ( V_5 -> clock ) ;
V_5 -> clock = NULL ;
}
F_37 ( & V_5 -> V_29 ) ;
if ( V_5 -> V_35 ) {
F_23 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
}
F_4 ( & V_5 -> V_12 ) ;
V_5 -> V_13 -> V_97 ( V_8 -> V_15 ) ;
F_5 ( & V_5 -> V_12 ) ;
F_38 ( V_5 ) ;
V_8 -> V_5 = NULL ;
}
static int F_39 ( struct V_7 * V_8 , bool V_98 )
{
struct V_4 * V_5 ;
int V_9 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_85 ;
F_40 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_99 ( V_8 -> V_15 ) ;
if ( V_9 ) {
F_28 ( V_8 , L_13 ) ;
return V_9 ;
}
F_41 ( & V_5 -> V_29 , F_18 ) ;
if ( V_98 ) {
memset ( & V_5 -> V_23 , 0 , sizeof( V_5 -> V_23 ) ) ;
V_5 -> V_23 . V_100 = F_25 ;
V_5 -> V_23 . V_101 = F_42 ( 64 ) ;
V_5 -> V_23 . V_102 = 0 ;
V_5 -> V_23 . V_103 = 1 ;
F_16 ( & V_5 -> V_19 , & V_5 -> V_23 ,
F_43 ( F_44 () ) ) ;
}
return V_9 ;
}
int F_45 ( struct V_7 * V_8 , bool V_98 )
{
struct V_4 * V_5 ;
int V_9 ;
V_5 = F_46 ( sizeof( * V_5 ) , V_104 ) ;
if ( ! V_5 ) {
F_28 ( V_8 , L_14 ) ;
return - V_105 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_13 = V_8 -> V_13 -> V_5 ;
if ( ! V_5 -> V_13 ) {
F_28 ( V_8 , L_15 ) ;
V_9 = - V_47 ;
goto V_106;
}
V_8 -> V_5 = V_5 ;
V_9 = F_39 ( V_8 , V_98 ) ;
if ( V_9 )
goto V_106;
F_27 ( V_8 ) ;
V_5 -> V_6 . V_107 = V_108 ;
snprintf ( V_5 -> V_6 . V_109 , 16 , L_16 , V_8 -> V_110 -> V_109 ) ;
V_5 -> V_6 . V_111 = V_112 ;
V_5 -> V_6 . V_113 = 0 ;
V_5 -> V_6 . V_114 = 0 ;
V_5 -> V_6 . V_115 = 0 ;
V_5 -> V_6 . V_116 = 0 ;
V_5 -> V_6 . V_14 = F_1 ;
V_5 -> V_6 . V_117 = F_8 ;
V_5 -> V_6 . V_118 = F_11 ;
V_5 -> V_6 . V_119 = F_14 ;
V_5 -> V_6 . V_99 = F_17 ;
V_5 -> clock = F_47 ( & V_5 -> V_6 , & V_8 -> V_120 -> V_121 ) ;
if ( F_48 ( V_5 -> clock ) ) {
V_9 = - V_85 ;
F_6 ( V_8 , L_17 ) ;
goto V_122;
}
return 0 ;
V_122:
F_35 ( V_8 ) ;
V_5 -> clock = NULL ;
V_106:
F_38 ( V_5 ) ;
V_8 -> V_5 = NULL ;
return V_9 ;
}
void F_49 ( struct V_7 * V_8 , struct V_123 * V_124 )
{
struct V_4 * V_5 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
if ( F_50 ( V_36 , & V_8 -> V_37 ) )
return;
if ( F_51 ( ! ( V_8 -> V_37 & V_50 ) ) ) {
F_52 ( V_8 ,
L_18 ) ;
} else if ( F_51 ( V_5 -> V_35 ) ) {
F_52 ( V_8 ,
L_19 ) ;
} else {
F_53 ( V_124 ) -> V_125 |= V_126 ;
V_5 -> V_35 = F_54 ( V_124 ) ;
F_19 ( & V_5 -> V_29 ) ;
}
}
void F_55 ( struct V_7 * V_8 , struct V_123 * V_124 )
{
struct V_4 * V_5 ;
T_3 V_32 , V_22 ;
int V_9 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
F_4 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_127 ( V_8 -> V_15 , & V_32 ) ;
if ( V_9 ) {
F_5 ( & V_5 -> V_12 ) ;
F_28 ( V_8 , L_20 ) ;
return;
}
V_22 = F_20 ( & V_5 -> V_19 , V_32 ) ;
F_5 ( & V_5 -> V_12 ) ;
F_56 ( V_124 ) -> V_34 = F_21 ( V_22 ) ;
F_9 ( V_8 , V_18 ,
L_21 ,
V_32 , V_22 ) ;
}
