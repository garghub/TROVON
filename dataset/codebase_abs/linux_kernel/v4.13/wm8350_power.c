static int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , V_2 , 0 , 0 )
* V_3 ;
}
static int F_3 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , V_4 , 0 , 0 )
* V_3 ;
}
static int F_4 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , V_5 , 0 , 0 )
* V_3 ;
}
static inline int F_5 ( struct V_1 * V_1 , int V_6 )
{
if ( ! V_1 -> V_7 . V_8 )
return ( ( ( V_6 - 30 ) / 15 ) & 0xf ) << 8 ;
else
return ( ( ( V_6 - 30 ) / 30 ) & 0xf ) << 8 ;
}
static int F_6 ( struct V_1 * V_1 )
{
T_1 V_9 , V_10 , V_11 , V_12 ;
int V_13 = 0 ;
V_9 = F_7 ( V_1 , V_14 ) ;
V_10 = F_7 ( V_1 , V_15 ) ;
V_11 = F_7 ( V_1 , V_16 ) ;
V_12 = F_7 ( V_1 , V_17 ) ;
V_9 = ( V_9 & V_18 ) >> V_19 ;
V_12 &= V_20 ;
if ( ( ( V_9 == V_21 ) ||
( V_9 == V_22 ) ||
( V_9 == V_23 ) )
&& ! ( V_10 & V_24 ) )
V_13 = V_25 ;
else if ( ( ( V_9 == V_21 ) ||
( V_9 == V_22 ) ||
( V_9 == V_23 ) )
&& ( V_10 & V_24 ) && ( V_12 == 0 ) )
V_13 = V_25 | V_26 ;
else if ( V_11 & V_27 )
V_13 = V_28 ;
else
V_13 = V_26 ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_1 ,
struct V_29 * V_30 )
{
T_1 V_31 , V_32 , V_33 ;
if ( ! V_30 ) {
F_9 ( V_1 -> V_34 ,
L_1 ) ;
return - V_35 ;
}
if ( V_30 -> V_36 > 500 ) {
F_10 ( V_1 -> V_34 , L_2 ) ;
return - V_35 ;
}
V_32 = F_11 ( V_30 -> V_32 ) ;
F_12 ( V_1 ) ;
V_31 = F_7 ( V_1 , V_37 )
& V_38 ;
F_13 ( V_1 , V_37 ,
V_31 | V_32 | V_30 -> V_39 |
V_40 |
V_41 |
V_42 ) ;
if ( F_6 ( V_1 ) & V_25 ) {
V_33 =
F_14 ( V_30 -> V_36 ) ;
F_13 ( V_1 , V_17 ,
V_30 -> V_43 | V_30 -> V_44 |
V_33 | F_5 ( V_1 ,
V_30 -> V_45 ) ) ;
} else {
V_33 =
F_14 ( V_30 -> V_33 ) ;
F_13 ( V_1 , V_17 ,
V_30 -> V_43 | V_30 -> V_46 |
V_33 | F_5 ( V_1 ,
V_30 -> V_45 ) ) ;
}
F_15 ( V_1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
T_1 V_47 ;
V_47 = F_7 ( V_1 , V_17 ) ;
V_47 &= V_48 ;
switch ( V_47 ) {
case V_49 :
return V_50 ;
case V_51 :
case V_52 :
return V_53 ;
default:
return V_54 ;
}
}
static T_2 F_17 ( struct V_55 * V_34 ,
struct V_56 * V_57 , char * V_58 )
{
struct V_1 * V_1 = F_18 ( V_34 ) ;
char * V_59 ;
int V_47 ;
V_47 = F_7 ( V_1 , V_17 ) &
V_48 ;
switch ( V_47 ) {
case V_49 :
V_59 = L_3 ;
break;
case V_51 :
V_59 = L_4 ;
break;
case V_52 :
V_59 = L_5 ;
break;
default:
return 0 ;
}
return sprintf ( V_58 , L_6 , V_59 ) ;
}
static T_3 F_19 ( int V_60 , void * V_61 )
{
struct V_1 * V_1 = V_61 ;
struct V_62 * V_7 = & V_1 -> V_7 ;
struct V_29 * V_30 = V_7 -> V_30 ;
switch ( V_60 - V_1 -> V_63 ) {
case V_64 :
F_10 ( V_1 -> V_34 , L_7 ) ;
break;
case V_65 :
F_10 ( V_1 -> V_34 , L_8 ) ;
F_20 ( V_7 -> V_66 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_20 ( V_7 -> V_66 ) ;
break;
case V_71 :
F_21 ( V_1 -> V_34 , L_9 ) ;
F_8 ( V_1 , V_30 ) ;
F_12 ( V_1 ) ;
F_22 ( V_1 , V_37 ,
V_72 ) ;
F_15 ( V_1 ) ;
break;
case V_73 :
F_9 ( V_1 -> V_34 , L_10 ) ;
break;
case V_74 :
F_9 ( V_1 -> V_34 , L_11 ) ;
break;
case V_75 :
F_9 ( V_1 -> V_34 , L_12 ) ;
break;
case V_76 :
case V_77 :
F_8 ( V_1 , V_30 ) ;
case V_78 :
F_20 ( V_7 -> V_66 ) ;
F_20 ( V_7 -> V_79 ) ;
F_20 ( V_7 -> V_80 ) ;
break;
default:
F_10 ( V_1 -> V_34 , L_13 , V_60 ) ;
}
return V_81 ;
}
static int F_23 ( struct V_82 * V_83 ,
enum V_84 V_85 ,
union V_86 * V_87 )
{
struct V_1 * V_1 = F_18 ( V_83 -> V_34 . V_88 ) ;
int V_89 = 0 ;
switch ( V_85 ) {
case V_90 :
V_87 -> V_91 = ! ! ( F_6 ( V_1 ) &
V_28 ) ;
break;
case V_92 :
V_87 -> V_91 = F_3 ( V_1 ) ;
break;
default:
V_89 = - V_35 ;
break;
}
return V_89 ;
}
static int F_24 ( struct V_82 * V_83 ,
enum V_84 V_85 ,
union V_86 * V_87 )
{
struct V_1 * V_1 = F_18 ( V_83 -> V_34 . V_88 ) ;
int V_89 = 0 ;
switch ( V_85 ) {
case V_90 :
V_87 -> V_91 = ! ! ( F_6 ( V_1 ) &
V_25 ) ;
break;
case V_92 :
V_87 -> V_91 = F_4 ( V_1 ) ;
break;
default:
V_89 = - V_35 ;
break;
}
return V_89 ;
}
static int F_25 ( struct V_1 * V_1 )
{
T_1 V_31 ;
if ( F_1 ( V_1 ) < 2850000 )
return V_93 ;
V_31 = F_7 ( V_1 , V_94 ) ;
if ( V_31 & V_95 )
return V_96 ;
if ( V_31 & V_97 )
return V_98 ;
return V_99 ;
}
static int F_26 ( struct V_1 * V_1 )
{
int V_47 ;
V_47 = F_7 ( V_1 , V_17 ) &
V_48 ;
switch ( V_47 ) {
case V_49 :
return V_100 ;
case V_51 :
return V_101 ;
case V_52 :
return V_102 ;
default:
return V_103 ;
}
}
static int F_27 ( struct V_82 * V_83 ,
enum V_84 V_85 ,
union V_86 * V_87 )
{
struct V_1 * V_1 = F_18 ( V_83 -> V_34 . V_88 ) ;
int V_89 = 0 ;
switch ( V_85 ) {
case V_104 :
V_87 -> V_91 = F_16 ( V_1 ) ;
break;
case V_90 :
V_87 -> V_91 = ! ! ( F_6 ( V_1 ) &
V_26 ) ;
break;
case V_92 :
V_87 -> V_91 = F_1 ( V_1 ) ;
break;
case V_105 :
V_87 -> V_91 = F_25 ( V_1 ) ;
break;
case V_106 :
V_87 -> V_91 = F_26 ( V_1 ) ;
break;
default:
V_89 = - V_35 ;
break;
}
return V_89 ;
}
static void F_28 ( struct V_1 * V_1 )
{
F_29 ( V_1 , V_67 ,
F_19 , 0 , L_14 , V_1 ) ;
F_29 ( V_1 , V_68 ,
F_19 , 0 , L_15 , V_1 ) ;
F_29 ( V_1 , V_64 ,
F_19 , 0 , L_16 , V_1 ) ;
F_29 ( V_1 , V_65 ,
F_19 , 0 ,
L_17 , V_1 ) ;
F_29 ( V_1 , V_70 ,
F_19 , 0 ,
L_18 , V_1 ) ;
F_29 ( V_1 , V_69 ,
F_19 , 0 ,
L_19 , V_1 ) ;
F_29 ( V_1 , V_71 ,
F_19 , 0 ,
L_20 , V_1 ) ;
F_29 ( V_1 , V_73 ,
F_19 , 0 ,
L_21 , V_1 ) ;
F_29 ( V_1 , V_74 ,
F_19 , 0 ,
L_22 , V_1 ) ;
F_29 ( V_1 , V_75 ,
F_19 , 0 ,
L_23 , V_1 ) ;
F_29 ( V_1 , V_76 ,
F_19 , 0 , L_24 , V_1 ) ;
F_29 ( V_1 , V_77 ,
F_19 , 0 , L_25 , V_1 ) ;
F_29 ( V_1 , V_78 ,
F_19 , 0 , L_26 , V_1 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
F_31 ( V_1 , V_67 , V_1 ) ;
F_31 ( V_1 , V_68 , V_1 ) ;
F_31 ( V_1 , V_64 , V_1 ) ;
F_31 ( V_1 , V_65 , V_1 ) ;
F_31 ( V_1 , V_70 , V_1 ) ;
F_31 ( V_1 , V_69 , V_1 ) ;
F_31 ( V_1 , V_73 , V_1 ) ;
F_31 ( V_1 , V_74 , V_1 ) ;
F_31 ( V_1 , V_75 , V_1 ) ;
F_31 ( V_1 , V_76 , V_1 ) ;
F_31 ( V_1 , V_77 , V_1 ) ;
F_31 ( V_1 , V_78 , V_1 ) ;
}
static int F_32 ( struct V_107 * V_108 )
{
struct V_1 * V_1 = F_33 ( V_108 ) ;
struct V_62 * V_7 = & V_1 -> V_7 ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_89 ;
V_7 -> V_80 = F_34 ( & V_108 -> V_34 , & V_109 , NULL ) ;
if ( F_35 ( V_7 -> V_80 ) )
return F_36 ( V_7 -> V_80 ) ;
V_7 -> V_66 = F_34 ( & V_108 -> V_34 , & V_110 ,
NULL ) ;
if ( F_35 ( V_7 -> V_66 ) ) {
V_89 = F_36 ( V_7 -> V_66 ) ;
goto V_111;
}
V_7 -> V_79 = F_34 ( & V_108 -> V_34 , & V_112 , NULL ) ;
if ( F_35 ( V_7 -> V_79 ) ) {
V_89 = F_36 ( V_7 -> V_79 ) ;
goto V_113;
}
V_89 = F_37 ( & V_108 -> V_34 , & V_114 ) ;
if ( V_89 < 0 )
F_9 ( V_1 -> V_34 , L_27 , V_89 ) ;
V_89 = 0 ;
F_28 ( V_1 ) ;
if ( F_8 ( V_1 , V_30 ) == 0 ) {
F_12 ( V_1 ) ;
F_22 ( V_1 , V_115 , V_116 ) ;
F_15 ( V_1 ) ;
}
return V_89 ;
V_113:
F_38 ( V_7 -> V_66 ) ;
V_111:
F_38 ( V_7 -> V_80 ) ;
return V_89 ;
}
static int F_39 ( struct V_107 * V_108 )
{
struct V_1 * V_1 = F_33 ( V_108 ) ;
struct V_62 * V_7 = & V_1 -> V_7 ;
F_30 ( V_1 ) ;
F_40 ( & V_108 -> V_34 , & V_114 ) ;
F_38 ( V_7 -> V_66 ) ;
F_38 ( V_7 -> V_80 ) ;
F_38 ( V_7 -> V_79 ) ;
return 0 ;
}
