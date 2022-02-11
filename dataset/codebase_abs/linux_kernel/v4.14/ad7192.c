static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_6 &= ~ V_7 ;
V_5 -> V_6 |= F_4 ( V_4 ) ;
return F_5 ( & V_5 -> V_3 , V_8 , 3 , V_5 -> V_6 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
enum V_9 V_10 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_10 &= ~ V_11 ;
V_5 -> V_10 |= F_7 ( V_10 ) ;
return F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
}
static int F_8 ( struct V_1 * V_5 )
{
return F_9 ( & V_5 -> V_3 , V_13 ,
F_10 ( V_13 ) ) ;
}
static int F_11 ( struct V_1 * V_5 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = F_12 ( V_5 -> V_3 . V_18 ) ;
unsigned long long V_19 ;
int V_20 , V_21 , V_22 ;
V_21 = F_13 ( & V_5 -> V_3 , 48 ) ;
if ( V_21 < 0 )
goto V_23;
F_14 ( 500 , 1000 ) ;
V_21 = F_15 ( & V_5 -> V_3 , V_24 , 1 , & V_22 ) ;
if ( V_21 )
goto V_23;
V_22 &= V_25 ;
if ( V_22 != V_5 -> V_26 )
F_16 ( & V_5 -> V_3 . V_18 -> V_27 , L_1 ,
V_22 ) ;
switch ( V_15 -> V_28 ) {
case V_29 :
case V_30 :
V_5 -> V_31 = V_32 ;
break;
case V_33 :
case V_34 :
if ( V_15 -> V_35 )
V_5 -> V_31 = V_15 -> V_35 ;
else
V_5 -> V_31 = V_32 ;
break;
default:
V_21 = - V_36 ;
goto V_23;
}
V_5 -> V_10 = F_7 ( V_37 ) |
F_17 ( V_15 -> V_28 ) |
F_18 ( 480 ) ;
V_5 -> V_6 = F_19 ( 0 ) ;
if ( V_15 -> V_38 )
V_5 -> V_10 |= V_39 ;
if ( V_15 -> V_40 )
V_5 -> V_10 |= V_41 ;
if ( V_15 -> V_42 && ( V_5 -> V_26 != V_43 ) )
V_5 -> V_6 |= V_44 ;
if ( V_15 -> V_45 ) {
V_5 -> V_6 |= V_46 ;
if ( V_15 -> V_40 )
V_5 -> V_47 = 3 ;
else
V_5 -> V_47 = 4 ;
} else {
V_5 -> V_47 = 1 ;
}
if ( V_15 -> V_48 )
V_5 -> V_6 |= V_49 ;
if ( V_15 -> V_50 )
V_5 -> V_6 |= V_51 ;
if ( V_15 -> V_52 )
V_5 -> V_6 |= V_53 ;
V_21 = F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
if ( V_21 )
goto V_23;
V_21 = F_5 ( & V_5 -> V_3 , V_8 , 3 , V_5 -> V_6 ) ;
if ( V_21 )
goto V_23;
V_21 = F_8 ( V_5 ) ;
if ( V_21 )
goto V_23;
for ( V_20 = 0 ; V_20 < F_10 ( V_5 -> V_54 ) ; V_20 ++ ) {
V_19 = ( ( V_55 ) V_5 -> V_56 * 100000000 )
>> ( V_17 -> V_57 [ 0 ] . V_58 . V_59 -
( ( V_5 -> V_6 & V_51 ) ? 0 : 1 ) ) ;
V_19 >>= V_20 ;
V_5 -> V_54 [ V_20 ] [ 1 ] = F_20 ( V_19 , 100000000 ) * 10 ;
V_5 -> V_54 [ V_20 ] [ 0 ] = V_19 ;
}
return 0 ;
V_23:
F_21 ( & V_5 -> V_3 . V_18 -> V_27 , L_2 ) ;
return V_21 ;
}
static T_1
F_22 ( struct V_60 * V_27 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_16 * V_17 = F_23 ( V_27 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
int V_20 , V_64 = 0 ;
for ( V_20 = 0 ; V_20 < F_10 ( V_5 -> V_54 ) ; V_20 ++ )
V_64 += sprintf ( V_63 + V_64 , L_3 , V_5 -> V_54 [ V_20 ] [ 0 ] ,
V_5 -> V_54 [ V_20 ] [ 1 ] ) ;
V_64 += sprintf ( V_63 + V_64 , L_4 ) ;
return V_64 ;
}
static T_1 F_25 ( struct V_60 * V_27 ,
struct V_61 * V_62 ,
char * V_63 )
{
struct V_16 * V_17 = F_23 ( V_27 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
return sprintf ( V_63 , L_5 , ! ! ( V_5 -> V_10 & V_65 ) ) ;
}
static T_1 F_26 ( struct V_60 * V_27 ,
struct V_61 * V_62 ,
char * V_63 )
{
struct V_16 * V_17 = F_23 ( V_27 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
return sprintf ( V_63 , L_5 , ! ! ( V_5 -> V_66 & V_67 ) ) ;
}
static T_1 F_27 ( struct V_60 * V_27 ,
struct V_61 * V_62 ,
const char * V_63 ,
T_2 V_64 )
{
struct V_16 * V_17 = F_23 ( V_27 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
struct V_68 * V_69 = F_28 ( V_62 ) ;
int V_21 ;
bool V_70 ;
V_21 = F_29 ( V_63 , & V_70 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_30 ( V_17 ) ;
if ( V_21 )
return V_21 ;
switch ( ( V_71 ) V_69 -> V_72 ) {
case V_73 :
if ( V_70 )
V_5 -> V_66 |= V_67 ;
else
V_5 -> V_66 &= ~ V_67 ;
F_5 ( & V_5 -> V_3 , V_73 , 1 , V_5 -> V_66 ) ;
break;
case V_12 :
if ( V_70 )
V_5 -> V_10 |= V_65 ;
else
V_5 -> V_10 &= ~ V_65 ;
F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
break;
default:
V_21 = - V_36 ;
}
F_31 ( V_17 ) ;
return V_21 ? V_21 : V_64 ;
}
static unsigned int F_32 ( bool V_74 )
{
return V_74 ? 2815 * 2 : 2815 ;
}
static int F_33 ( struct V_16 * V_17 ,
struct V_75 const * V_76 ,
int * V_70 ,
int * V_77 ,
long V_78 )
{
struct V_1 * V_5 = F_24 ( V_17 ) ;
bool V_74 = ! ! ( V_5 -> V_6 & V_51 ) ;
switch ( V_78 ) {
case V_79 :
return F_34 ( V_17 , V_76 , V_70 ) ;
case V_80 :
switch ( V_76 -> type ) {
case V_81 :
F_35 ( & V_17 -> V_82 ) ;
* V_70 = V_5 -> V_54 [ F_19 ( V_5 -> V_6 ) ] [ 0 ] ;
* V_77 = V_5 -> V_54 [ F_19 ( V_5 -> V_6 ) ] [ 1 ] ;
F_36 ( & V_17 -> V_82 ) ;
return V_83 ;
case V_84 :
* V_70 = 0 ;
* V_77 = 1000000000 / F_32 ( V_74 ) ;
return V_83 ;
default:
return - V_36 ;
}
case V_85 :
if ( ! V_74 )
* V_70 = - ( 1 << ( V_76 -> V_58 . V_59 - 1 ) ) ;
else
* V_70 = 0 ;
if ( V_76 -> type == V_84 )
* V_70 -= 273 * F_32 ( V_74 ) ;
return V_86 ;
case V_87 :
* V_70 = V_5 -> V_31 /
( V_5 -> V_47 * 1024 * F_18 ( V_5 -> V_10 ) ) ;
return V_86 ;
}
return - V_36 ;
}
static int F_37 ( struct V_16 * V_17 ,
struct V_75 const * V_76 ,
int V_70 ,
int V_77 ,
long V_88 )
{
struct V_1 * V_5 = F_24 ( V_17 ) ;
int V_21 , V_20 , div ;
unsigned int V_89 ;
V_21 = F_30 ( V_17 ) ;
if ( V_21 )
return V_21 ;
switch ( V_88 ) {
case V_80 :
V_21 = - V_36 ;
for ( V_20 = 0 ; V_20 < F_10 ( V_5 -> V_54 ) ; V_20 ++ )
if ( V_77 == V_5 -> V_54 [ V_20 ] [ 1 ] ) {
V_21 = 0 ;
V_89 = V_5 -> V_6 ;
V_5 -> V_6 &= ~ F_19 ( - 1 ) ;
V_5 -> V_6 |= F_19 ( V_20 ) ;
if ( V_89 == V_5 -> V_6 )
break;
F_5 ( & V_5 -> V_3 , V_8 ,
3 , V_5 -> V_6 ) ;
F_8 ( V_5 ) ;
break;
}
break;
case V_87 :
if ( ! V_70 ) {
V_21 = - V_36 ;
break;
}
div = V_5 -> V_31 / ( V_70 * V_5 -> V_47 * 1024 ) ;
if ( div < 1 || div > 1023 ) {
V_21 = - V_36 ;
break;
}
V_5 -> V_10 &= ~ F_18 ( - 1 ) ;
V_5 -> V_10 |= F_18 ( div ) ;
F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
break;
default:
V_21 = - V_36 ;
}
F_31 ( V_17 ) ;
return V_21 ;
}
static int F_38 ( struct V_16 * V_17 ,
struct V_75 const * V_76 ,
long V_88 )
{
switch ( V_88 ) {
case V_80 :
return V_83 ;
case V_87 :
return V_86 ;
default:
return - V_36 ;
}
}
static int F_39 ( struct V_90 * V_18 )
{
const struct V_14 * V_15 = F_40 ( & V_18 -> V_27 ) ;
struct V_1 * V_5 ;
struct V_16 * V_17 ;
int V_21 , V_91 = 0 ;
if ( ! V_15 ) {
F_21 ( & V_18 -> V_27 , L_6 ) ;
return - V_92 ;
}
if ( ! V_18 -> V_93 ) {
F_21 ( & V_18 -> V_27 , L_7 ) ;
return - V_92 ;
}
V_17 = F_41 ( & V_18 -> V_27 , sizeof( * V_5 ) ) ;
if ( ! V_17 )
return - V_94 ;
V_5 = F_24 ( V_17 ) ;
V_5 -> V_95 = F_42 ( & V_18 -> V_27 , L_8 ) ;
if ( F_43 ( V_5 -> V_95 ) )
return F_44 ( V_5 -> V_95 ) ;
V_21 = F_45 ( V_5 -> V_95 ) ;
if ( V_21 ) {
F_21 ( & V_18 -> V_27 , L_9 ) ;
return V_21 ;
}
V_5 -> V_96 = F_42 ( & V_18 -> V_27 , L_10 ) ;
if ( F_43 ( V_5 -> V_96 ) ) {
V_21 = F_44 ( V_5 -> V_96 ) ;
goto V_97;
}
V_21 = F_45 ( V_5 -> V_96 ) ;
if ( V_21 ) {
F_21 ( & V_18 -> V_27 , L_11 ) ;
goto V_97;
}
V_91 = F_46 ( V_5 -> V_95 ) ;
if ( V_15 -> V_98 )
V_5 -> V_56 = V_15 -> V_98 ;
else if ( V_91 )
V_5 -> V_56 = V_91 / 1000 ;
else
F_16 ( & V_18 -> V_27 , L_12 ) ;
F_47 ( V_18 , V_17 ) ;
V_5 -> V_26 = F_48 ( V_18 ) -> V_99 ;
V_17 -> V_27 . V_100 = & V_18 -> V_27 ;
V_17 -> V_101 = F_48 ( V_18 ) -> V_101 ;
V_17 -> V_102 = V_103 ;
switch ( V_5 -> V_26 ) {
case V_104 :
V_17 -> V_57 = V_105 ;
V_17 -> V_106 = F_10 ( V_105 ) ;
break;
default:
V_17 -> V_57 = V_107 ;
V_17 -> V_106 = F_10 ( V_107 ) ;
break;
}
if ( V_5 -> V_26 == V_43 )
V_17 -> V_108 = & V_109 ;
else
V_17 -> V_108 = & V_110 ;
F_49 ( & V_5 -> V_3 , V_17 , V_18 , & V_111 ) ;
V_21 = F_50 ( V_17 ) ;
if ( V_21 )
goto V_112;
V_21 = F_11 ( V_5 , V_15 ) ;
if ( V_21 )
goto V_113;
V_21 = F_51 ( V_17 ) ;
if ( V_21 < 0 )
goto V_113;
return 0 ;
V_113:
F_52 ( V_17 ) ;
V_112:
F_53 ( V_5 -> V_96 ) ;
V_97:
F_53 ( V_5 -> V_95 ) ;
return V_21 ;
}
static int F_54 ( struct V_90 * V_18 )
{
struct V_16 * V_17 = F_12 ( V_18 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
F_55 ( V_17 ) ;
F_52 ( V_17 ) ;
F_53 ( V_5 -> V_96 ) ;
F_53 ( V_5 -> V_95 ) ;
return 0 ;
}
