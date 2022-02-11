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
T_1 V_23 [ 6 ] ;
memset ( & V_23 , 0xFF , 6 ) ;
V_21 = F_13 ( V_5 -> V_3 . V_18 , & V_23 , 6 ) ;
if ( V_21 < 0 )
goto V_24;
F_14 ( 500 , 1000 ) ;
V_21 = F_15 ( & V_5 -> V_3 , V_25 , 1 , & V_22 ) ;
if ( V_21 )
goto V_24;
V_22 &= V_26 ;
if ( V_22 != V_5 -> V_27 )
F_16 ( & V_5 -> V_3 . V_18 -> V_28 , L_1 ,
V_22 ) ;
switch ( V_15 -> V_29 ) {
case V_30 :
case V_31 :
V_5 -> V_32 = V_33 ;
break;
case V_34 :
case V_35 :
if ( V_15 -> V_36 )
V_5 -> V_32 = V_15 -> V_36 ;
else
V_5 -> V_32 = V_33 ;
break;
default:
V_21 = - V_37 ;
goto V_24;
}
V_5 -> V_10 = F_7 ( V_38 ) |
F_17 ( V_15 -> V_29 ) |
F_18 ( 480 ) ;
V_5 -> V_6 = F_19 ( 0 ) ;
if ( V_15 -> V_39 )
V_5 -> V_10 |= V_40 ;
if ( V_15 -> V_41 )
V_5 -> V_10 |= V_42 ;
if ( V_15 -> V_43 && ( V_5 -> V_27 != V_44 ) )
V_5 -> V_6 |= V_45 ;
if ( V_15 -> V_46 ) {
V_5 -> V_6 |= V_47 ;
if ( V_15 -> V_41 )
V_5 -> V_48 = 3 ;
else
V_5 -> V_48 = 4 ;
} else {
V_5 -> V_48 = 1 ;
}
if ( V_15 -> V_49 )
V_5 -> V_6 |= V_50 ;
if ( V_15 -> V_51 )
V_5 -> V_6 |= V_52 ;
if ( V_15 -> V_53 )
V_5 -> V_6 |= V_54 ;
V_21 = F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
if ( V_21 )
goto V_24;
V_21 = F_5 ( & V_5 -> V_3 , V_8 , 3 , V_5 -> V_6 ) ;
if ( V_21 )
goto V_24;
V_21 = F_8 ( V_5 ) ;
if ( V_21 )
goto V_24;
for ( V_20 = 0 ; V_20 < F_10 ( V_5 -> V_55 ) ; V_20 ++ ) {
V_19 = ( ( V_56 ) V_5 -> V_57 * 100000000 )
>> ( V_17 -> V_58 [ 0 ] . V_59 . V_60 -
( ( V_5 -> V_6 & V_52 ) ? 0 : 1 ) ) ;
V_19 >>= V_20 ;
V_5 -> V_55 [ V_20 ] [ 1 ] = F_20 ( V_19 , 100000000 ) * 10 ;
V_5 -> V_55 [ V_20 ] [ 0 ] = V_19 ;
}
return 0 ;
V_24:
F_21 ( & V_5 -> V_3 . V_18 -> V_28 , L_2 ) ;
return V_21 ;
}
static T_2
F_22 ( struct V_61 * V_28 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_16 * V_17 = F_23 ( V_28 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
int V_20 , V_65 = 0 ;
for ( V_20 = 0 ; V_20 < F_10 ( V_5 -> V_55 ) ; V_20 ++ )
V_65 += sprintf ( V_64 + V_65 , L_3 , V_5 -> V_55 [ V_20 ] [ 0 ] ,
V_5 -> V_55 [ V_20 ] [ 1 ] ) ;
V_65 += sprintf ( V_64 + V_65 , L_4 ) ;
return V_65 ;
}
static T_2 F_25 ( struct V_61 * V_28 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_16 * V_17 = F_23 ( V_28 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
return sprintf ( V_64 , L_5 , ! ! ( V_5 -> V_10 & V_66 ) ) ;
}
static T_2 F_26 ( struct V_61 * V_28 ,
struct V_62 * V_63 ,
char * V_64 )
{
struct V_16 * V_17 = F_23 ( V_28 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
return sprintf ( V_64 , L_5 , ! ! ( V_5 -> V_67 & V_68 ) ) ;
}
static T_2 F_27 ( struct V_61 * V_28 ,
struct V_62 * V_63 ,
const char * V_64 ,
T_3 V_65 )
{
struct V_16 * V_17 = F_23 ( V_28 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
struct V_69 * V_70 = F_28 ( V_63 ) ;
int V_21 ;
bool V_71 ;
V_21 = F_29 ( V_64 , & V_71 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_30 ( V_17 ) ;
if ( V_21 )
return V_21 ;
switch ( ( V_72 ) V_70 -> V_73 ) {
case V_74 :
if ( V_71 )
V_5 -> V_67 |= V_68 ;
else
V_5 -> V_67 &= ~ V_68 ;
F_5 ( & V_5 -> V_3 , V_74 , 1 , V_5 -> V_67 ) ;
break;
case V_12 :
if ( V_71 )
V_5 -> V_10 |= V_66 ;
else
V_5 -> V_10 &= ~ V_66 ;
F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
break;
default:
V_21 = - V_37 ;
}
F_31 ( V_17 ) ;
return V_21 ? V_21 : V_65 ;
}
static unsigned int F_32 ( bool V_75 )
{
return V_75 ? 2815 * 2 : 2815 ;
}
static int F_33 ( struct V_16 * V_17 ,
struct V_76 const * V_77 ,
int * V_71 ,
int * V_78 ,
long V_79 )
{
struct V_1 * V_5 = F_24 ( V_17 ) ;
bool V_75 = ! ! ( V_5 -> V_6 & V_52 ) ;
switch ( V_79 ) {
case V_80 :
return F_34 ( V_17 , V_77 , V_71 ) ;
case V_81 :
switch ( V_77 -> type ) {
case V_82 :
F_35 ( & V_17 -> V_83 ) ;
* V_71 = V_5 -> V_55 [ F_19 ( V_5 -> V_6 ) ] [ 0 ] ;
* V_78 = V_5 -> V_55 [ F_19 ( V_5 -> V_6 ) ] [ 1 ] ;
F_36 ( & V_17 -> V_83 ) ;
return V_84 ;
case V_85 :
* V_71 = 0 ;
* V_78 = 1000000000 / F_32 ( V_75 ) ;
return V_84 ;
default:
return - V_37 ;
}
case V_86 :
if ( ! V_75 )
* V_71 = - ( 1 << ( V_77 -> V_59 . V_60 - 1 ) ) ;
else
* V_71 = 0 ;
if ( V_77 -> type == V_85 )
* V_71 -= 273 * F_32 ( V_75 ) ;
return V_87 ;
case V_88 :
* V_71 = V_5 -> V_32 /
( V_5 -> V_48 * 1024 * F_18 ( V_5 -> V_10 ) ) ;
return V_87 ;
}
return - V_37 ;
}
static int F_37 ( struct V_16 * V_17 ,
struct V_76 const * V_77 ,
int V_71 ,
int V_78 ,
long V_89 )
{
struct V_1 * V_5 = F_24 ( V_17 ) ;
int V_21 , V_20 , div ;
unsigned int V_90 ;
V_21 = F_30 ( V_17 ) ;
if ( V_21 )
return V_21 ;
switch ( V_89 ) {
case V_81 :
V_21 = - V_37 ;
for ( V_20 = 0 ; V_20 < F_10 ( V_5 -> V_55 ) ; V_20 ++ )
if ( V_78 == V_5 -> V_55 [ V_20 ] [ 1 ] ) {
V_21 = 0 ;
V_90 = V_5 -> V_6 ;
V_5 -> V_6 &= ~ F_19 ( - 1 ) ;
V_5 -> V_6 |= F_19 ( V_20 ) ;
if ( V_90 == V_5 -> V_6 )
break;
F_5 ( & V_5 -> V_3 , V_8 ,
3 , V_5 -> V_6 ) ;
F_8 ( V_5 ) ;
break;
}
break;
case V_88 :
if ( ! V_71 ) {
V_21 = - V_37 ;
break;
}
div = V_5 -> V_32 / ( V_71 * V_5 -> V_48 * 1024 ) ;
if ( div < 1 || div > 1023 ) {
V_21 = - V_37 ;
break;
}
V_5 -> V_10 &= ~ F_18 ( - 1 ) ;
V_5 -> V_10 |= F_18 ( div ) ;
F_5 ( & V_5 -> V_3 , V_12 , 3 , V_5 -> V_10 ) ;
break;
default:
V_21 = - V_37 ;
}
F_31 ( V_17 ) ;
return V_21 ;
}
static int F_38 ( struct V_16 * V_17 ,
struct V_76 const * V_77 ,
long V_89 )
{
switch ( V_89 ) {
case V_81 :
return V_84 ;
case V_88 :
return V_87 ;
default:
return - V_37 ;
}
}
static int F_39 ( struct V_91 * V_18 )
{
const struct V_14 * V_15 = F_40 ( & V_18 -> V_28 ) ;
struct V_1 * V_5 ;
struct V_16 * V_17 ;
int V_21 , V_92 = 0 ;
if ( ! V_15 ) {
F_21 ( & V_18 -> V_28 , L_6 ) ;
return - V_93 ;
}
if ( ! V_18 -> V_94 ) {
F_21 ( & V_18 -> V_28 , L_7 ) ;
return - V_93 ;
}
V_17 = F_41 ( & V_18 -> V_28 , sizeof( * V_5 ) ) ;
if ( ! V_17 )
return - V_95 ;
V_5 = F_24 ( V_17 ) ;
V_5 -> V_96 = F_42 ( & V_18 -> V_28 , L_8 ) ;
if ( F_43 ( V_5 -> V_96 ) )
return F_44 ( V_5 -> V_96 ) ;
V_21 = F_45 ( V_5 -> V_96 ) ;
if ( V_21 ) {
F_21 ( & V_18 -> V_28 , L_9 ) ;
return V_21 ;
}
V_5 -> V_97 = F_42 ( & V_18 -> V_28 , L_10 ) ;
if ( F_43 ( V_5 -> V_97 ) ) {
V_21 = F_44 ( V_5 -> V_97 ) ;
goto V_98;
}
V_21 = F_45 ( V_5 -> V_97 ) ;
if ( V_21 ) {
F_21 ( & V_18 -> V_28 , L_11 ) ;
goto V_98;
}
V_92 = F_46 ( V_5 -> V_96 ) ;
if ( V_15 -> V_99 )
V_5 -> V_57 = V_15 -> V_99 ;
else if ( V_92 )
V_5 -> V_57 = V_92 / 1000 ;
else
F_16 ( & V_18 -> V_28 , L_12 ) ;
F_47 ( V_18 , V_17 ) ;
V_5 -> V_27 = F_48 ( V_18 ) -> V_100 ;
V_17 -> V_28 . V_101 = & V_18 -> V_28 ;
V_17 -> V_102 = F_48 ( V_18 ) -> V_102 ;
V_17 -> V_103 = V_104 ;
switch ( V_5 -> V_27 ) {
case V_105 :
V_17 -> V_58 = V_106 ;
V_17 -> V_107 = F_10 ( V_106 ) ;
break;
default:
V_17 -> V_58 = V_108 ;
V_17 -> V_107 = F_10 ( V_108 ) ;
break;
}
if ( V_5 -> V_27 == V_44 )
V_17 -> V_109 = & V_110 ;
else
V_17 -> V_109 = & V_111 ;
F_49 ( & V_5 -> V_3 , V_17 , V_18 , & V_112 ) ;
V_21 = F_50 ( V_17 ) ;
if ( V_21 )
goto V_113;
V_21 = F_11 ( V_5 , V_15 ) ;
if ( V_21 )
goto V_114;
V_21 = F_51 ( V_17 ) ;
if ( V_21 < 0 )
goto V_114;
return 0 ;
V_114:
F_52 ( V_17 ) ;
V_113:
F_53 ( V_5 -> V_97 ) ;
V_98:
F_53 ( V_5 -> V_96 ) ;
return V_21 ;
}
static int F_54 ( struct V_91 * V_18 )
{
struct V_16 * V_17 = F_12 ( V_18 ) ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
F_55 ( V_17 ) ;
F_52 ( V_17 ) ;
F_53 ( V_5 -> V_97 ) ;
F_53 ( V_5 -> V_96 ) ;
return 0 ;
}
