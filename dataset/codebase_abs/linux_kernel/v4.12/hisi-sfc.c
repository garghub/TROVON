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
case V_17 :
default:
V_11 = V_18 ;
break;
}
return V_11 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_5 ( V_19 )
| F_6 ( V_20 )
| F_7 ( V_21 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_22 ) ;
}
static int F_9 ( struct V_23 * V_24 , enum V_25 V_26 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_29 ;
F_10 ( & V_2 -> V_30 ) ;
V_29 = F_11 ( V_2 -> V_31 , V_28 -> V_32 ) ;
if ( V_29 )
goto V_33;
V_29 = F_12 ( V_2 -> V_31 ) ;
if ( V_29 )
goto V_33;
return 0 ;
V_33:
F_13 ( & V_2 -> V_30 ) ;
return V_29 ;
}
static void F_14 ( struct V_23 * V_24 , enum V_25 V_26 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
F_15 ( V_2 -> V_31 ) ;
F_13 ( & V_2 -> V_30 ) ;
}
static int F_16 ( struct V_23 * V_24 ,
T_2 V_34 , int V_35 , T_2 V_36 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_1 V_3 ;
V_3 = F_17 ( V_34 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_37 ) ;
V_3 = F_18 ( V_35 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_38 ) ;
V_3 = F_19 ( V_28 -> V_39 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_40 ) ;
F_8 ( 0xff , V_2 -> V_4 + V_41 ) ;
V_3 = V_42 | V_43 | V_36 ;
F_8 ( V_3 , V_2 -> V_4 + V_44 ) ;
return F_1 ( V_2 ) ;
}
static int F_20 ( struct V_23 * V_24 , T_2 V_34 , T_2 * V_45 ,
int V_35 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_29 ;
V_29 = F_16 ( V_24 , V_34 , V_35 , V_46 ) ;
if ( V_29 )
return V_29 ;
F_21 ( V_45 , V_2 -> V_47 , V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 , T_2 V_34 ,
T_2 * V_45 , int V_35 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
if ( V_35 )
F_23 ( V_2 -> V_47 , V_45 , V_35 ) ;
return F_16 ( V_24 , V_34 , V_35 , V_48 ) ;
}
static int F_24 ( struct V_23 * V_24 , T_3 V_49 ,
T_4 V_50 , T_5 V_35 , T_2 V_51 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_2 V_11 = 0 ;
T_1 V_3 ;
V_3 = F_25 ( V_2 -> V_4 + V_52 ) ;
V_3 &= ~ ( V_53 | V_54 ) ;
V_3 |= V_55 ;
V_3 |= ( V_24 -> V_56 == 4 ) ? V_57
: V_58 ;
F_8 ( V_3 , V_2 -> V_4 + V_52 ) ;
F_8 ( V_49 , V_2 -> V_4 + V_59 ) ;
F_8 ( V_50 , V_2 -> V_4 + V_60 ) ;
F_8 ( F_26 ( V_35 ) , V_2 -> V_4 + V_61 ) ;
V_3 = F_19 ( V_28 -> V_39 ) ;
V_11 = F_3 ( V_24 -> V_9 ) ;
V_3 |= F_27 ( V_11 ) ;
if ( V_51 == V_62 )
V_3 |= F_28 ( V_24 -> V_63 >> 3 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_40 ) ;
F_8 ( 0xff , V_2 -> V_4 + V_41 ) ;
V_3 = F_29 ( V_51 ) | V_64 ;
V_3 |= ( V_51 == V_62 )
? F_30 ( V_24 -> V_65 )
: F_31 ( V_24 -> V_66 ) ;
F_8 ( V_3 , V_2 -> V_4 + V_67 ) ;
return F_1 ( V_2 ) ;
}
static T_6 F_32 ( struct V_23 * V_24 , T_3 V_68 , T_5 V_35 ,
T_7 * V_69 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_5 V_70 ;
int V_29 ;
for ( V_70 = 0 ; V_70 < V_35 ; V_70 += V_71 ) {
T_5 V_72 = F_33 ( T_5 , V_71 , V_35 - V_70 ) ;
V_29 = F_24 ( V_24 ,
V_68 + V_70 , V_2 -> V_73 , V_72 , V_62 ) ;
if ( V_29 ) {
F_34 ( V_24 -> V_74 , L_1 ) ;
return V_29 ;
}
memcpy ( V_69 + V_70 , V_2 -> V_75 , V_72 ) ;
}
return V_35 ;
}
static T_6 F_35 ( struct V_23 * V_24 , T_3 V_76 ,
T_5 V_35 , const T_7 * V_77 )
{
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_5 V_70 ;
int V_29 ;
for ( V_70 = 0 ; V_70 < V_35 ; V_70 += V_71 ) {
T_5 V_72 = F_33 ( T_5 , V_71 , V_35 - V_70 ) ;
memcpy ( V_2 -> V_75 , V_77 + V_70 , V_72 ) ;
V_29 = F_24 ( V_24 ,
V_76 + V_70 , V_2 -> V_73 , V_72 , V_78 ) ;
if ( V_29 ) {
F_34 ( V_24 -> V_74 , L_2 ) ;
return V_29 ;
}
}
return V_35 ;
}
static int F_36 ( struct V_79 * V_80 ,
struct V_1 * V_2 )
{
struct V_81 * V_74 = V_2 -> V_74 ;
struct V_23 * V_24 ;
struct V_27 * V_28 ;
struct V_82 * V_83 ;
int V_29 ;
V_24 = F_37 ( V_74 , sizeof( * V_24 ) , V_84 ) ;
if ( ! V_24 )
return - V_85 ;
V_24 -> V_74 = V_74 ;
F_38 ( V_24 , V_80 ) ;
V_28 = F_37 ( V_74 , sizeof( * V_28 ) , V_84 ) ;
if ( ! V_28 )
return - V_85 ;
V_29 = F_39 ( V_80 , L_3 , & V_28 -> V_39 ) ;
if ( V_29 ) {
F_40 ( V_74 , L_4 ,
V_80 -> V_86 ) ;
return V_29 ;
}
V_29 = F_39 ( V_80 , L_5 ,
& V_28 -> V_32 ) ;
if ( V_29 ) {
F_40 ( V_74 , L_6 ,
V_80 -> V_86 ) ;
return V_29 ;
}
V_28 -> V_2 = V_2 ;
V_24 -> V_28 = V_28 ;
V_24 -> V_87 = F_9 ;
V_24 -> V_88 = F_14 ;
V_24 -> V_89 = F_20 ;
V_24 -> V_90 = F_22 ;
V_24 -> V_91 = F_32 ;
V_24 -> V_92 = F_35 ;
V_24 -> V_93 = NULL ;
V_29 = F_41 ( V_24 , NULL , V_14 ) ;
if ( V_29 )
return V_29 ;
V_83 = & V_24 -> V_83 ;
V_83 -> V_94 = V_80 -> V_94 ;
V_29 = F_42 ( V_83 , NULL , 0 ) ;
if ( V_29 )
return V_29 ;
V_2 -> V_24 [ V_2 -> V_95 ] = V_24 ;
V_2 -> V_95 ++ ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_2 -> V_95 ; V_96 ++ )
F_44 ( & V_2 -> V_24 [ V_96 ] -> V_83 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_81 * V_74 = V_2 -> V_74 ;
struct V_79 * V_80 ;
int V_29 ;
F_46 (dev->of_node, np) {
V_29 = F_36 ( V_80 , V_2 ) ;
if ( V_29 )
goto V_97;
if ( V_2 -> V_95 == V_98 ) {
F_34 ( V_74 , L_7 ) ;
break;
}
}
return 0 ;
V_97:
F_43 ( V_2 ) ;
return V_29 ;
}
static int F_47 ( struct V_99 * V_100 )
{
struct V_81 * V_74 = & V_100 -> V_74 ;
struct V_101 * V_102 ;
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_37 ( V_74 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
F_48 ( V_100 , V_2 ) ;
V_2 -> V_74 = V_74 ;
V_102 = F_49 ( V_100 , V_103 , L_8 ) ;
V_2 -> V_4 = F_50 ( V_74 , V_102 ) ;
if ( F_51 ( V_2 -> V_4 ) )
return F_52 ( V_2 -> V_4 ) ;
V_102 = F_49 ( V_100 , V_103 , L_9 ) ;
V_2 -> V_47 = F_50 ( V_74 , V_102 ) ;
if ( F_51 ( V_2 -> V_47 ) )
return F_52 ( V_2 -> V_47 ) ;
V_2 -> V_31 = F_53 ( V_74 , NULL ) ;
if ( F_51 ( V_2 -> V_31 ) )
return F_52 ( V_2 -> V_31 ) ;
V_29 = F_54 ( V_74 , F_55 ( 32 ) ) ;
if ( V_29 ) {
F_34 ( V_74 , L_10 ) ;
return V_29 ;
}
V_2 -> V_75 = F_56 ( V_74 , V_71 ,
& V_2 -> V_73 , V_84 ) ;
if ( ! V_2 -> V_75 )
return - V_85 ;
V_29 = F_12 ( V_2 -> V_31 ) ;
if ( V_29 )
return V_29 ;
F_57 ( & V_2 -> V_30 ) ;
F_4 ( V_2 ) ;
V_29 = F_45 ( V_2 ) ;
if ( V_29 )
F_58 ( & V_2 -> V_30 ) ;
F_15 ( V_2 -> V_31 ) ;
return V_29 ;
}
static int F_59 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_60 ( V_100 ) ;
F_43 ( V_2 ) ;
F_58 ( & V_2 -> V_30 ) ;
F_15 ( V_2 -> V_31 ) ;
return 0 ;
}
