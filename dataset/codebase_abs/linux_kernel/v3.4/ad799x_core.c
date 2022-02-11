static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = F_4 ( ( T_2 ) V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_6 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = ( T_1 ) V_7 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_8 ( V_6 , V_3 , F_4 ( V_4 ) ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_10 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
int F_11 ( struct V_1 * V_2 , unsigned V_9 )
{
return F_7 ( V_2 , V_10 ,
V_2 -> V_11 | ( V_9 << V_12 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_13 )
{
T_2 V_14 ;
T_1 V_15 ;
int V_7 ;
switch ( V_2 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
V_15 = V_2 -> V_11 | ( ( 1 << V_13 ) << V_12 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
V_15 = ( 1 << V_13 ) << V_12 ;
break;
case V_23 :
case V_24 :
V_15 = ( V_13 << V_12 ) | V_25 ;
break;
default:
return - V_26 ;
}
V_7 = F_1 ( V_2 , V_15 , & V_14 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_14 ;
}
static int F_13 ( struct V_27 * V_28 ,
struct V_29 const * V_30 ,
int * V_31 ,
int * V_32 ,
long V_33 )
{
int V_7 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned int V_34 ;
switch ( V_33 ) {
case 0 :
F_15 ( & V_28 -> V_35 ) ;
if ( F_16 ( V_28 ) )
V_7 = - V_36 ;
else
V_7 = F_12 ( V_2 , V_30 -> V_37 ) ;
F_17 ( & V_28 -> V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_31 = ( V_7 >> V_30 -> V_38 . V_39 ) &
F_18 ( V_30 -> V_38 . V_40 ) ;
return V_41 ;
case V_42 :
V_34 = ( V_2 -> V_43 * 1000 ) >> V_30 -> V_38 . V_40 ;
* V_31 = V_34 / 1000 ;
* V_32 = ( V_34 % 1000 ) * 1000 ;
return V_44 ;
}
return - V_26 ;
}
static T_3 F_19 ( struct V_45 * V_8 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_7 ;
T_1 V_31 ;
V_7 = F_5 ( V_2 , V_49 , & V_31 ) ;
if ( V_7 )
return V_7 ;
V_31 &= V_50 ;
return sprintf ( V_48 , L_3 , V_51 [ V_31 ] ) ;
}
static T_3 F_21 ( struct V_45 * V_8 ,
struct V_46 * V_47 ,
const char * V_48 ,
T_4 V_52 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
long V_31 ;
int V_7 , V_53 ;
T_1 V_54 ;
V_7 = F_22 ( V_48 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_5 ( V_2 , V_49 , & V_54 ) ;
if ( V_7 )
goto V_55;
V_54 &= ~ V_50 ;
for ( V_53 = 0 ; V_53 < F_23 ( V_51 ) ; V_53 ++ )
if ( V_31 == V_51 [ V_53 ] )
break;
if ( V_53 == F_23 ( V_51 ) ) {
V_7 = - V_26 ;
goto V_55;
}
V_54 |= V_53 ;
V_7 = F_9 ( V_2 , V_49 , V_54 ) ;
V_55:
F_17 ( & V_28 -> V_35 ) ;
return V_7 ? V_7 : V_52 ;
}
static int F_24 ( struct V_27 * V_28 ,
T_5 V_56 )
{
return 1 ;
}
static int F_25 ( struct V_27 * V_28 ,
T_5 V_56 ,
int V_31 )
{
int V_7 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_57 = ! ! ( F_26 ( V_56 ) ==
V_58 ) ;
int V_59 = F_27 ( V_56 ) ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_7 ( V_2 ,
V_60 [ V_59 ] [ V_57 ] ,
V_31 ) ;
F_17 ( & V_28 -> V_35 ) ;
return V_7 ;
}
static int F_28 ( struct V_27 * V_28 ,
T_5 V_56 ,
int * V_31 )
{
int V_7 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_57 = ! ! ( F_26 ( V_56 ) ==
V_58 ) ;
int V_59 = F_27 ( V_56 ) ;
T_2 V_61 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_1 ( V_2 ,
V_60 [ V_59 ] [ V_57 ] ,
& V_61 ) ;
F_17 ( & V_28 -> V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_31 = V_61 ;
return 0 ;
}
static T_3 F_29 ( struct V_45 * V_8 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_62 * V_63 = F_30 ( V_47 ) ;
int V_7 ;
T_2 V_31 ;
V_7 = F_1 ( V_2 , V_63 -> V_64 , & V_31 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_48 , L_4 , V_31 ) ;
}
static T_3 F_31 ( struct V_45 * V_8 ,
struct V_46 * V_47 ,
const char * V_48 ,
T_4 V_52 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_62 * V_63 = F_30 ( V_47 ) ;
long V_31 ;
int V_7 ;
V_7 = F_22 ( V_48 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_7 ( V_2 , V_63 -> V_64 , V_31 ) ;
F_17 ( & V_28 -> V_35 ) ;
return V_7 ? V_7 : V_52 ;
}
static T_6 F_32 ( int V_65 , void * V_66 )
{
struct V_27 * V_28 = V_66 ;
struct V_1 * V_2 = F_14 ( V_66 ) ;
T_1 V_67 ;
int V_53 , V_7 ;
V_7 = F_5 ( V_2 , V_68 , & V_67 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_67 )
return - V_69 ;
F_9 ( V_2 , V_68 , V_70 ) ;
for ( V_53 = 0 ; V_53 < 8 ; V_53 ++ ) {
if ( V_67 & ( 1 << V_53 ) )
F_33 ( V_28 ,
V_53 & 0x1 ?
F_34 ( V_71 ,
( V_53 >> 1 ) ,
V_72 ,
V_73 ) :
F_34 ( V_71 ,
( V_53 >> 1 ) ,
V_72 ,
V_58 ) ,
F_35 () ) ;
}
return V_74 ;
}
static int T_7 F_36 ( struct V_5 * V_6 ,
const struct V_75 * V_16 )
{
int V_7 ;
struct V_76 * V_77 = V_6 -> V_8 . V_78 ;
struct V_1 * V_2 ;
struct V_27 * V_28 = F_37 ( sizeof( * V_2 ) ) ;
if ( V_28 == NULL )
return - V_79 ;
V_2 = F_14 ( V_28 ) ;
F_38 ( V_6 , V_28 ) ;
V_2 -> V_16 = V_16 -> V_80 ;
V_2 -> V_81 = & V_82 [ V_2 -> V_16 ] ;
V_2 -> V_11 = V_2 -> V_81 -> V_83 ;
if ( V_77 )
V_2 -> V_43 = V_77 -> V_84 ;
else
V_2 -> V_43 = V_2 -> V_81 -> V_43 ;
V_2 -> V_3 = F_39 ( & V_6 -> V_8 , L_5 ) ;
if ( ! F_40 ( V_2 -> V_3 ) ) {
V_7 = F_41 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_85;
}
V_2 -> V_6 = V_6 ;
V_28 -> V_8 . V_86 = & V_6 -> V_8 ;
V_28 -> V_87 = V_16 -> V_87 ;
V_28 -> V_88 = V_2 -> V_81 -> V_88 ;
V_28 -> V_89 = V_90 ;
V_28 -> V_91 = V_2 -> V_81 -> V_92 ;
V_28 -> V_93 = V_2 -> V_81 -> V_93 ;
V_7 = F_42 ( V_28 ) ;
if ( V_7 )
goto V_94;
V_7 = F_43 ( V_28 ,
V_28 -> V_91 ,
V_28 -> V_93 ) ;
if ( V_7 )
goto V_95;
if ( V_6 -> V_65 > 0 ) {
V_7 = F_44 ( V_6 -> V_65 ,
NULL ,
F_32 ,
V_96 |
V_97 ,
V_6 -> V_87 ,
V_28 ) ;
if ( V_7 )
goto V_95;
}
V_7 = F_45 ( V_28 ) ;
if ( V_7 )
goto V_98;
return 0 ;
V_98:
F_46 ( V_6 -> V_65 , V_28 ) ;
V_95:
F_47 ( V_28 ) ;
V_94:
if ( ! F_40 ( V_2 -> V_3 ) )
F_48 ( V_2 -> V_3 ) ;
V_85:
if ( ! F_40 ( V_2 -> V_3 ) )
F_49 ( V_2 -> V_3 ) ;
F_50 ( V_28 ) ;
return V_7 ;
}
static T_8 int F_51 ( struct V_5 * V_6 )
{
struct V_27 * V_28 = F_52 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_53 ( V_28 ) ;
if ( V_6 -> V_65 > 0 )
F_46 ( V_6 -> V_65 , V_28 ) ;
F_54 ( V_28 ) ;
F_47 ( V_28 ) ;
if ( ! F_40 ( V_2 -> V_3 ) ) {
F_48 ( V_2 -> V_3 ) ;
F_49 ( V_2 -> V_3 ) ;
}
F_50 ( V_28 ) ;
return 0 ;
}
