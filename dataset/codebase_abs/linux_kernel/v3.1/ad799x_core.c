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
V_7 = F_17 ( V_2 ,
1 << V_30 -> V_36 ) ;
else
V_7 = F_12 ( V_2 , V_30 -> V_36 ) ;
F_18 ( & V_28 -> V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_31 = ( V_7 >> V_2 -> V_37 -> V_38 [ 0 ] . V_39 . V_40 ) &
F_19 ( V_2 -> V_37 -> V_38 [ 0 ] . V_39 . V_41 ) ;
return V_42 ;
case ( 1 << V_43 ) :
V_34 = ( V_2 -> V_44 * 1000 )
>> V_2 -> V_37 -> V_38 [ 0 ] . V_39 . V_41 ;
* V_31 = V_34 / 1000 ;
* V_32 = ( V_34 % 1000 ) * 1000 ;
return V_45 ;
}
return - V_26 ;
}
static T_3 F_20 ( struct V_46 * V_8 ,
struct V_47 * V_48 ,
char * V_49 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_7 , V_50 = 0 ;
T_1 V_31 ;
V_7 = F_5 ( V_2 , V_51 , & V_31 ) ;
if ( V_7 )
return V_7 ;
V_31 &= V_52 ;
switch ( V_31 ) {
case V_53 :
V_50 = sprintf ( V_49 , L_3 ) ;
break;
case V_54 :
V_50 = sprintf ( V_49 , L_4 ) ;
break;
case V_55 :
V_50 = sprintf ( V_49 , L_5 ) ;
break;
case V_56 :
V_50 = sprintf ( V_49 , L_6 ) ;
break;
case V_57 :
V_50 = sprintf ( V_49 , L_7 ) ;
break;
case V_58 :
V_50 = sprintf ( V_49 , L_8 ) ;
break;
case V_59 :
V_50 = sprintf ( V_49 , L_9 ) ;
break;
case V_60 :
V_50 = sprintf ( V_49 , L_10 ) ;
break;
}
return V_50 ;
}
static T_3 F_22 ( struct V_46 * V_8 ,
struct V_47 * V_48 ,
const char * V_49 ,
T_4 V_50 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
long V_31 ;
int V_7 ;
T_1 V_61 ;
V_7 = F_23 ( V_49 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_5 ( V_2 , V_51 , & V_61 ) ;
if ( V_7 )
goto V_62;
V_61 &= ~ V_52 ;
switch ( V_31 ) {
case 15625 :
V_61 |= V_54 ;
break;
case 7812 :
V_61 |= V_55 ;
break;
case 3906 :
V_61 |= V_56 ;
break;
case 1953 :
V_61 |= V_57 ;
break;
case 976 :
V_61 |= V_58 ;
break;
case 488 :
V_61 |= V_59 ;
break;
case 244 :
V_61 |= V_60 ;
break;
case 0 :
V_61 |= V_53 ;
break;
default:
V_7 = - V_26 ;
goto V_62;
}
V_7 = F_9 ( V_2 , V_51 , V_61 ) ;
V_62:
F_18 ( & V_28 -> V_35 ) ;
return V_7 ? V_7 : V_50 ;
}
static T_3 F_24 ( struct V_46 * V_8 ,
struct V_47 * V_48 ,
char * V_49 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_63 * V_64 = F_25 ( V_48 ) ;
int V_7 ;
T_2 V_31 ;
V_7 = F_1 ( V_2 , V_64 -> V_36 , & V_31 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_49 , L_11 , V_31 ) ;
}
static T_3 F_26 ( struct V_46 * V_8 ,
struct V_47 * V_48 ,
const char * V_49 ,
T_4 V_50 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_63 * V_64 = F_25 ( V_48 ) ;
long V_31 ;
int V_7 ;
V_7 = F_23 ( V_49 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_7 ( V_2 , V_64 -> V_36 , V_31 ) ;
F_18 ( & V_28 -> V_35 ) ;
return V_7 ? V_7 : V_50 ;
}
static T_5 F_27 ( int V_65 , void * V_66 )
{
struct V_27 * V_67 = V_66 ;
struct V_1 * V_2 = F_14 ( V_66 ) ;
T_1 V_68 ;
int V_69 , V_7 ;
V_7 = F_5 ( V_2 , V_70 , & V_68 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_68 )
return - V_71 ;
F_9 ( V_2 , V_70 , V_72 ) ;
for ( V_69 = 0 ; V_69 < 8 ; V_69 ++ ) {
if ( V_68 & ( 1 << V_69 ) )
F_28 ( V_67 , 0 ,
V_69 & 0x1 ?
F_29 ( V_69 >> 1 ) :
F_30 ( V_69 >> 1 ) ,
F_31 () ) ;
}
return V_73 ;
}
static int T_6 F_32 ( struct V_5 * V_6 ,
const struct V_74 * V_16 )
{
int V_7 , V_75 = 0 ;
struct V_76 * V_77 = V_6 -> V_8 . V_78 ;
struct V_1 * V_2 ;
struct V_27 * V_67 = F_33 ( sizeof( * V_2 ) ) ;
if ( V_67 == NULL )
return - V_79 ;
V_2 = F_14 ( V_67 ) ;
F_34 ( V_6 , V_67 ) ;
V_2 -> V_16 = V_16 -> V_80 ;
V_2 -> V_37 = & V_81 [ V_2 -> V_16 ] ;
V_2 -> V_11 = V_2 -> V_37 -> V_82 ;
if ( V_77 )
V_2 -> V_44 = V_77 -> V_83 ;
else
V_2 -> V_44 = V_2 -> V_37 -> V_44 ;
V_2 -> V_3 = F_35 ( & V_6 -> V_8 , L_12 ) ;
if ( ! F_36 ( V_2 -> V_3 ) ) {
V_7 = F_37 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_84;
}
V_2 -> V_6 = V_6 ;
V_67 -> V_8 . V_85 = & V_6 -> V_8 ;
V_67 -> V_86 = V_16 -> V_86 ;
V_67 -> V_87 = V_2 -> V_37 -> V_87 ;
V_67 -> V_86 = V_16 -> V_86 ;
V_67 -> V_88 = V_89 ;
V_67 -> V_90 = V_2 -> V_37 -> V_38 ;
V_67 -> V_91 = V_2 -> V_37 -> V_91 ;
V_7 = F_38 ( V_67 ) ;
if ( V_7 )
goto V_92;
V_7 = F_39 ( V_67 ) ;
if ( V_7 )
goto V_93;
V_75 = 1 ;
V_7 = F_40 ( V_67 -> V_94 , 0 ,
V_67 -> V_90 ,
V_67 -> V_91 ) ;
if ( V_7 )
goto V_93;
if ( V_6 -> V_65 > 0 ) {
V_7 = F_41 ( V_6 -> V_65 ,
NULL ,
F_27 ,
V_95 |
V_96 ,
V_6 -> V_86 ,
V_67 ) ;
if ( V_7 )
goto V_93;
}
return 0 ;
V_93:
F_42 ( V_67 ) ;
V_92:
if ( ! F_36 ( V_2 -> V_3 ) )
F_43 ( V_2 -> V_3 ) ;
V_84:
if ( ! F_36 ( V_2 -> V_3 ) )
F_44 ( V_2 -> V_3 ) ;
if ( V_75 )
F_45 ( V_67 ) ;
else
F_46 ( V_67 ) ;
return V_7 ;
}
static T_7 int F_47 ( struct V_5 * V_6 )
{
struct V_27 * V_67 = F_48 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_67 ) ;
if ( V_6 -> V_65 > 0 )
F_49 ( V_6 -> V_65 , V_67 ) ;
F_50 ( V_67 -> V_94 ) ;
F_42 ( V_67 ) ;
if ( ! F_36 ( V_2 -> V_3 ) ) {
F_43 ( V_2 -> V_3 ) ;
F_44 ( V_2 -> V_3 ) ;
}
F_45 ( V_67 ) ;
return 0 ;
}
static T_8 int F_51 ( void )
{
return F_52 ( & V_97 ) ;
}
static T_9 void F_53 ( void )
{
F_54 ( & V_97 ) ;
}
