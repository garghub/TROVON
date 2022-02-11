static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = ( T_2 ) V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_5 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = ( T_1 ) V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_7 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_9 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_10 ( struct V_9 * V_10 ,
const unsigned long * V_11 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_12 ( V_2 -> V_12 ) ;
V_2 -> V_12 = F_13 ( V_10 -> V_13 , V_14 ) ;
if ( ! V_2 -> V_12 )
return - V_15 ;
V_2 -> V_16 = F_14 ( V_11 , V_10 -> V_17 ) * 2 ;
switch ( V_2 -> V_18 ) {
case V_19 :
case V_20 :
return F_6 ( V_2 , V_21 ,
V_2 -> V_22 | ( * V_11 << V_23 ) ) ;
default:
break;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_24 )
{
T_2 V_25 ;
T_1 V_26 ;
int V_7 ;
switch ( V_2 -> V_18 ) {
case V_27 :
case V_28 :
case V_29 :
V_26 = V_2 -> V_22 | ( ( 1 << V_24 ) << V_23 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
V_26 = ( 1 << V_24 ) << V_23 ;
break;
case V_19 :
case V_20 :
V_26 = ( V_24 << V_23 ) | V_33 ;
break;
default:
return - V_34 ;
}
V_7 = F_1 ( V_2 , V_26 , & V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_25 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_35 const * V_36 ,
int * V_37 ,
int * V_38 ,
long V_39 )
{
int V_7 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
unsigned int V_40 ;
switch ( V_39 ) {
case V_41 :
F_17 ( & V_10 -> V_42 ) ;
if ( F_18 ( V_10 ) )
V_7 = - V_43 ;
else
V_7 = F_15 ( V_2 , V_36 -> V_44 ) ;
F_19 ( & V_10 -> V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_37 = ( V_7 >> V_36 -> V_45 . V_46 ) &
F_20 ( V_36 -> V_45 . V_47 ) ;
return V_48 ;
case V_49 :
V_40 = ( V_2 -> V_50 * 1000 ) >> V_36 -> V_45 . V_47 ;
* V_37 = V_40 / 1000 ;
* V_38 = ( V_40 % 1000 ) * 1000 ;
return V_51 ;
}
return - V_34 ;
}
static T_3 F_21 ( struct V_52 * V_8 ,
struct V_53 * V_54 ,
char * V_55 )
{
struct V_9 * V_10 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
int V_7 ;
T_1 V_37 ;
V_7 = F_4 ( V_2 , V_56 , & V_37 ) ;
if ( V_7 )
return V_7 ;
V_37 &= V_57 ;
return sprintf ( V_55 , L_3 , V_58 [ V_37 ] ) ;
}
static T_3 F_23 ( struct V_52 * V_8 ,
struct V_53 * V_54 ,
const char * V_55 ,
T_4 V_59 )
{
struct V_9 * V_10 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
long V_37 ;
int V_7 , V_60 ;
T_1 V_61 ;
V_7 = F_24 ( V_55 , 10 , & V_37 ) ;
if ( V_7 )
return V_7 ;
F_17 ( & V_10 -> V_42 ) ;
V_7 = F_4 ( V_2 , V_56 , & V_61 ) ;
if ( V_7 )
goto V_62;
V_61 &= ~ V_57 ;
for ( V_60 = 0 ; V_60 < F_25 ( V_58 ) ; V_60 ++ )
if ( V_37 == V_58 [ V_60 ] )
break;
if ( V_60 == F_25 ( V_58 ) ) {
V_7 = - V_34 ;
goto V_62;
}
V_61 |= V_60 ;
V_7 = F_8 ( V_2 , V_56 , V_61 ) ;
V_62:
F_19 ( & V_10 -> V_42 ) ;
return V_7 ? V_7 : V_59 ;
}
static int F_26 ( struct V_9 * V_10 ,
T_5 V_63 )
{
return 1 ;
}
static int F_27 ( struct V_9 * V_10 ,
T_5 V_63 ,
int V_37 )
{
int V_7 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
int V_64 = ! ! ( F_28 ( V_63 ) ==
V_65 ) ;
int V_66 = F_29 ( V_63 ) ;
F_17 ( & V_10 -> V_42 ) ;
V_7 = F_6 ( V_2 ,
V_67 [ V_66 ] [ V_64 ] ,
V_37 ) ;
F_19 ( & V_10 -> V_42 ) ;
return V_7 ;
}
static int F_30 ( struct V_9 * V_10 ,
T_5 V_63 ,
int * V_37 )
{
int V_7 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
int V_64 = ! ! ( F_28 ( V_63 ) ==
V_65 ) ;
int V_66 = F_29 ( V_63 ) ;
T_2 V_68 ;
F_17 ( & V_10 -> V_42 ) ;
V_7 = F_1 ( V_2 ,
V_67 [ V_66 ] [ V_64 ] ,
& V_68 ) ;
F_19 ( & V_10 -> V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_37 = V_68 ;
return 0 ;
}
static T_3 F_31 ( struct V_52 * V_8 ,
struct V_53 * V_54 ,
char * V_55 )
{
struct V_9 * V_10 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_69 * V_70 = F_32 ( V_54 ) ;
int V_7 ;
T_2 V_37 ;
V_7 = F_1 ( V_2 , V_70 -> V_71 , & V_37 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_55 , L_4 , V_37 ) ;
}
static T_3 F_33 ( struct V_52 * V_8 ,
struct V_53 * V_54 ,
const char * V_55 ,
T_4 V_59 )
{
struct V_9 * V_10 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_69 * V_70 = F_32 ( V_54 ) ;
long V_37 ;
int V_7 ;
V_7 = F_24 ( V_55 , 10 , & V_37 ) ;
if ( V_7 )
return V_7 ;
F_17 ( & V_10 -> V_42 ) ;
V_7 = F_6 ( V_2 , V_70 -> V_71 , V_37 ) ;
F_19 ( & V_10 -> V_42 ) ;
return V_7 ? V_7 : V_59 ;
}
static T_6 F_34 ( int V_72 , void * V_73 )
{
struct V_9 * V_10 = V_73 ;
struct V_1 * V_2 = F_11 ( V_73 ) ;
T_1 V_74 ;
int V_60 , V_7 ;
V_7 = F_4 ( V_2 , V_75 , & V_74 ) ;
if ( V_7 )
goto V_76;
if ( ! V_74 )
goto V_76;
F_8 ( V_2 , V_75 , V_77 ) ;
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ ) {
if ( V_74 & ( 1 << V_60 ) )
F_35 ( V_10 ,
V_60 & 0x1 ?
F_36 ( V_78 ,
( V_60 >> 1 ) ,
V_79 ,
V_80 ) :
F_36 ( V_78 ,
( V_60 >> 1 ) ,
V_79 ,
V_65 ) ,
F_37 () ) ;
}
V_76:
return V_81 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_82 * V_18 )
{
int V_7 ;
struct V_83 * V_84 = V_6 -> V_8 . V_85 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = F_39 ( sizeof( * V_2 ) ) ;
if ( V_10 == NULL )
return - V_15 ;
V_2 = F_11 ( V_10 ) ;
F_40 ( V_6 , V_10 ) ;
V_2 -> V_18 = V_18 -> V_86 ;
V_2 -> V_87 = & V_88 [ V_2 -> V_18 ] ;
V_2 -> V_22 = V_2 -> V_87 -> V_89 ;
if ( ! V_84 )
return - V_34 ;
V_2 -> V_50 = V_84 -> V_90 ;
V_2 -> V_3 = F_41 ( & V_6 -> V_8 , L_5 ) ;
if ( ! F_42 ( V_2 -> V_3 ) ) {
V_7 = F_43 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_91;
}
V_2 -> V_6 = V_6 ;
V_10 -> V_8 . V_92 = & V_6 -> V_8 ;
V_10 -> V_93 = V_18 -> V_93 ;
V_10 -> V_94 = V_2 -> V_87 -> V_94 ;
V_10 -> V_95 = V_96 ;
V_10 -> V_97 = V_2 -> V_87 -> V_98 ;
V_10 -> V_99 = V_2 -> V_87 -> V_99 ;
V_7 = F_44 ( V_10 ) ;
if ( V_7 )
goto V_100;
if ( V_6 -> V_72 > 0 ) {
V_7 = F_45 ( V_6 -> V_72 ,
NULL ,
F_34 ,
V_101 |
V_102 ,
V_6 -> V_93 ,
V_10 ) ;
if ( V_7 )
goto V_103;
}
V_7 = F_46 ( V_10 ) ;
if ( V_7 )
goto V_104;
return 0 ;
V_104:
F_47 ( V_6 -> V_72 , V_10 ) ;
V_103:
F_48 ( V_10 ) ;
V_100:
if ( ! F_42 ( V_2 -> V_3 ) )
F_49 ( V_2 -> V_3 ) ;
V_91:
if ( ! F_42 ( V_2 -> V_3 ) )
F_50 ( V_2 -> V_3 ) ;
F_51 ( V_10 ) ;
return V_7 ;
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_54 ( V_10 ) ;
if ( V_6 -> V_72 > 0 )
F_47 ( V_6 -> V_72 , V_10 ) ;
F_48 ( V_10 ) ;
if ( ! F_42 ( V_2 -> V_3 ) ) {
F_49 ( V_2 -> V_3 ) ;
F_50 ( V_2 -> V_3 ) ;
}
F_12 ( V_2 -> V_12 ) ;
F_51 ( V_10 ) ;
return 0 ;
}
