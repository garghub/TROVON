static inline int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
return F_2 ( V_2 -> V_4 + V_5 , V_3 ,
( V_3 & V_6 ) , 0 , V_7 ) ;
}
static int F_3 ( enum V_8 V_9 )
{
enum V_10 V_11 ;
switch ( V_9 ) {
case V_12 :
V_11 = V_13 ;
break;
case V_14 :
V_11 = V_15 ;
break;
case V_16 :
V_11 = V_17 ;
break;
case V_18 :
V_11 = V_19 ;
break;
case V_20 :
default:
V_11 = V_21 ;
break;
}
return V_11 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_5 ( V_22 )
| F_6 ( V_23 )
| F_7 ( V_24 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_25 ) ;
}
static int F_9 ( struct V_26 * V_27 , enum V_28 V_29 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_32 ;
F_10 ( & V_2 -> V_33 ) ;
V_32 = F_11 ( V_2 -> V_34 , V_31 -> V_35 ) ;
if ( V_32 )
goto V_36;
V_32 = F_12 ( V_2 -> V_34 ) ;
if ( V_32 )
goto V_36;
return 0 ;
V_36:
F_13 ( & V_2 -> V_33 ) ;
return V_32 ;
}
static void F_14 ( struct V_26 * V_27 , enum V_28 V_29 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
F_15 ( V_2 -> V_34 ) ;
F_13 ( & V_2 -> V_33 ) ;
}
static int F_16 ( struct V_26 * V_27 ,
T_2 V_37 , int V_38 , T_2 V_39 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_1 V_3 ;
V_3 = F_17 ( V_37 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_40 ) ;
V_3 = F_18 ( V_38 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_41 ) ;
V_3 = F_19 ( V_31 -> V_42 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_43 ) ;
F_8 ( 0xff , V_2 -> V_4 + V_44 ) ;
V_3 = V_45 | V_46 | V_39 ;
F_8 ( V_3 , V_2 -> V_4 + V_47 ) ;
return F_1 ( V_2 ) ;
}
static int F_20 ( struct V_26 * V_27 , T_2 V_37 , T_2 * V_48 ,
int V_38 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_32 ;
V_32 = F_16 ( V_27 , V_37 , V_38 , V_49 ) ;
if ( V_32 )
return V_32 ;
F_21 ( V_48 , V_2 -> V_50 , V_38 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 , T_2 V_37 ,
T_2 * V_48 , int V_38 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
if ( V_38 )
F_23 ( V_2 -> V_50 , V_48 , V_38 ) ;
return F_16 ( V_27 , V_37 , V_38 , V_51 ) ;
}
static int F_24 ( struct V_26 * V_27 , T_3 V_52 ,
T_4 V_53 , T_5 V_38 , T_2 V_54 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_2 V_11 = 0 ;
T_1 V_3 ;
V_3 = F_25 ( V_2 -> V_4 + V_55 ) ;
V_3 &= ~ ( V_56 | V_57 ) ;
V_3 |= V_58 ;
V_3 |= ( V_27 -> V_59 == 4 ) ? V_60
: V_61 ;
F_8 ( V_3 , V_2 -> V_4 + V_55 ) ;
F_8 ( V_52 , V_2 -> V_4 + V_62 ) ;
F_8 ( V_53 , V_2 -> V_4 + V_63 ) ;
F_8 ( F_26 ( V_38 ) , V_2 -> V_4 + V_64 ) ;
V_3 = F_19 ( V_31 -> V_42 ) ;
if ( V_54 == V_65 )
V_11 = F_3 ( V_27 -> V_66 ) ;
else
V_11 = F_3 ( V_27 -> V_67 ) ;
V_3 |= F_27 ( V_11 ) ;
if ( V_54 == V_65 )
V_3 |= F_28 ( V_27 -> V_68 >> 3 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_43 ) ;
F_8 ( 0xff , V_2 -> V_4 + V_44 ) ;
V_3 = F_29 ( V_54 ) | V_69 ;
V_3 |= ( V_54 == V_65 )
? F_30 ( V_27 -> V_70 )
: F_31 ( V_27 -> V_71 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_72 ) ;
return F_1 ( V_2 ) ;
}
static T_6 F_32 ( struct V_26 * V_27 , T_3 V_73 , T_5 V_38 ,
T_7 * V_74 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_5 V_75 ;
int V_32 ;
for ( V_75 = 0 ; V_75 < V_38 ; V_75 += V_76 ) {
T_5 V_77 = F_33 ( T_5 , V_76 , V_38 - V_75 ) ;
V_32 = F_24 ( V_27 ,
V_73 + V_75 , V_2 -> V_78 , V_77 , V_65 ) ;
if ( V_32 ) {
F_34 ( V_27 -> V_79 , L_1 ) ;
return V_32 ;
}
memcpy ( V_74 + V_75 , V_2 -> V_80 , V_77 ) ;
}
return V_38 ;
}
static T_6 F_35 ( struct V_26 * V_27 , T_3 V_81 ,
T_5 V_38 , const T_7 * V_82 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_5 V_75 ;
int V_32 ;
for ( V_75 = 0 ; V_75 < V_38 ; V_75 += V_76 ) {
T_5 V_77 = F_33 ( T_5 , V_76 , V_38 - V_75 ) ;
memcpy ( V_2 -> V_80 , V_82 + V_75 , V_77 ) ;
V_32 = F_24 ( V_27 ,
V_81 + V_75 , V_2 -> V_78 , V_77 , V_83 ) ;
if ( V_32 ) {
F_34 ( V_27 -> V_79 , L_2 ) ;
return V_32 ;
}
}
return V_38 ;
}
static int F_36 ( struct V_84 * V_85 ,
struct V_1 * V_2 )
{
const struct V_86 V_87 = {
. V_88 = V_89 |
V_90 |
V_91 |
V_92 |
V_93 ,
} ;
struct V_94 * V_79 = V_2 -> V_79 ;
struct V_26 * V_27 ;
struct V_30 * V_31 ;
struct V_95 * V_96 ;
int V_32 ;
V_27 = F_37 ( V_79 , sizeof( * V_27 ) , V_97 ) ;
if ( ! V_27 )
return - V_98 ;
V_27 -> V_79 = V_79 ;
F_38 ( V_27 , V_85 ) ;
V_31 = F_37 ( V_79 , sizeof( * V_31 ) , V_97 ) ;
if ( ! V_31 )
return - V_98 ;
V_32 = F_39 ( V_85 , L_3 , & V_31 -> V_42 ) ;
if ( V_32 ) {
F_40 ( V_79 , L_4 ,
V_85 ) ;
return V_32 ;
}
V_32 = F_39 ( V_85 , L_5 ,
& V_31 -> V_35 ) ;
if ( V_32 ) {
F_40 ( V_79 , L_6 ,
V_85 ) ;
return V_32 ;
}
V_31 -> V_2 = V_2 ;
V_27 -> V_31 = V_31 ;
V_27 -> V_99 = F_9 ;
V_27 -> V_100 = F_14 ;
V_27 -> V_101 = F_20 ;
V_27 -> V_102 = F_22 ;
V_27 -> V_103 = F_32 ;
V_27 -> V_104 = F_35 ;
V_27 -> V_105 = NULL ;
V_32 = F_41 ( V_27 , NULL , & V_87 ) ;
if ( V_32 )
return V_32 ;
V_96 = & V_27 -> V_96 ;
V_96 -> V_106 = V_85 -> V_106 ;
V_32 = F_42 ( V_96 , NULL , 0 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_27 [ V_2 -> V_107 ] = V_27 ;
V_2 -> V_107 ++ ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_2 -> V_107 ; V_108 ++ )
F_44 ( & V_2 -> V_27 [ V_108 ] -> V_96 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_94 * V_79 = V_2 -> V_79 ;
struct V_84 * V_85 ;
int V_32 ;
F_46 (dev->of_node, np) {
V_32 = F_36 ( V_85 , V_2 ) ;
if ( V_32 )
goto V_109;
if ( V_2 -> V_107 == V_110 ) {
F_34 ( V_79 , L_7 ) ;
break;
}
}
return 0 ;
V_109:
F_43 ( V_2 ) ;
return V_32 ;
}
static int F_47 ( struct V_111 * V_112 )
{
struct V_94 * V_79 = & V_112 -> V_79 ;
struct V_113 * V_114 ;
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_37 ( V_79 , sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
F_48 ( V_112 , V_2 ) ;
V_2 -> V_79 = V_79 ;
V_114 = F_49 ( V_112 , V_115 , L_8 ) ;
V_2 -> V_4 = F_50 ( V_79 , V_114 ) ;
if ( F_51 ( V_2 -> V_4 ) )
return F_52 ( V_2 -> V_4 ) ;
V_114 = F_49 ( V_112 , V_115 , L_9 ) ;
V_2 -> V_50 = F_50 ( V_79 , V_114 ) ;
if ( F_51 ( V_2 -> V_50 ) )
return F_52 ( V_2 -> V_50 ) ;
V_2 -> V_34 = F_53 ( V_79 , NULL ) ;
if ( F_51 ( V_2 -> V_34 ) )
return F_52 ( V_2 -> V_34 ) ;
V_32 = F_54 ( V_79 , F_55 ( 32 ) ) ;
if ( V_32 ) {
F_34 ( V_79 , L_10 ) ;
return V_32 ;
}
V_2 -> V_80 = F_56 ( V_79 , V_76 ,
& V_2 -> V_78 , V_97 ) ;
if ( ! V_2 -> V_80 )
return - V_98 ;
V_32 = F_12 ( V_2 -> V_34 ) ;
if ( V_32 )
return V_32 ;
F_57 ( & V_2 -> V_33 ) ;
F_4 ( V_2 ) ;
V_32 = F_45 ( V_2 ) ;
if ( V_32 )
F_58 ( & V_2 -> V_33 ) ;
F_15 ( V_2 -> V_34 ) ;
return V_32 ;
}
static int F_59 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_60 ( V_112 ) ;
F_43 ( V_2 ) ;
F_58 ( & V_2 -> V_33 ) ;
F_15 ( V_2 -> V_34 ) ;
return 0 ;
}
