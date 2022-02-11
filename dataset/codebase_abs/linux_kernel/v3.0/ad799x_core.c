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
struct V_1 * V_2 = V_28 -> V_34 ;
unsigned int V_35 ;
switch ( V_33 ) {
case 0 :
F_14 ( & V_28 -> V_36 ) ;
if ( F_15 ( V_28 ) )
V_7 = F_16 ( V_2 ,
1 << V_30 -> V_37 ) ;
else
V_7 = F_12 ( V_2 , V_30 -> V_37 ) ;
F_17 ( & V_28 -> V_36 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_31 = ( V_7 >> V_2 -> V_38 -> V_39 [ 0 ] . V_40 . V_41 ) &
F_18 ( V_2 -> V_38 -> V_39 [ 0 ] . V_40 . V_42 ) ;
return V_43 ;
case ( 1 << V_44 ) :
V_35 = ( V_2 -> V_45 * 1000 )
>> V_2 -> V_38 -> V_39 [ 0 ] . V_40 . V_42 ;
* V_31 = V_35 / 1000 ;
* V_32 = ( V_35 % 1000 ) * 1000 ;
return V_46 ;
}
return - V_26 ;
}
static T_3 F_19 ( struct V_47 * V_8 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_21 ( V_28 ) ;
int V_7 , V_51 = 0 ;
T_1 V_31 ;
V_7 = F_5 ( V_2 , V_52 , & V_31 ) ;
if ( V_7 )
return V_7 ;
V_31 &= V_53 ;
switch ( V_31 ) {
case V_54 :
V_51 = sprintf ( V_50 , L_3 ) ;
break;
case V_55 :
V_51 = sprintf ( V_50 , L_4 ) ;
break;
case V_56 :
V_51 = sprintf ( V_50 , L_5 ) ;
break;
case V_57 :
V_51 = sprintf ( V_50 , L_6 ) ;
break;
case V_58 :
V_51 = sprintf ( V_50 , L_7 ) ;
break;
case V_59 :
V_51 = sprintf ( V_50 , L_8 ) ;
break;
case V_60 :
V_51 = sprintf ( V_50 , L_9 ) ;
break;
case V_61 :
V_51 = sprintf ( V_50 , L_10 ) ;
break;
}
return V_51 ;
}
static T_3 F_22 ( struct V_47 * V_8 ,
struct V_48 * V_49 ,
const char * V_50 ,
T_4 V_51 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_21 ( V_28 ) ;
long V_31 ;
int V_7 ;
T_1 V_62 ;
V_7 = F_23 ( V_50 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_14 ( & V_28 -> V_36 ) ;
V_7 = F_5 ( V_2 , V_52 , & V_62 ) ;
if ( V_7 )
goto V_63;
V_62 &= ~ V_53 ;
switch ( V_31 ) {
case 15625 :
V_62 |= V_55 ;
break;
case 7812 :
V_62 |= V_56 ;
break;
case 3906 :
V_62 |= V_57 ;
break;
case 1953 :
V_62 |= V_58 ;
break;
case 976 :
V_62 |= V_59 ;
break;
case 488 :
V_62 |= V_60 ;
break;
case 244 :
V_62 |= V_61 ;
break;
case 0 :
V_62 |= V_54 ;
break;
default:
V_7 = - V_26 ;
goto V_63;
}
V_7 = F_9 ( V_2 , V_52 , V_62 ) ;
V_63:
F_17 ( & V_28 -> V_36 ) ;
return V_7 ? V_7 : V_51 ;
}
static T_3 F_24 ( struct V_47 * V_8 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_21 ( V_28 ) ;
struct V_64 * V_65 = F_25 ( V_49 ) ;
int V_7 ;
T_2 V_31 ;
V_7 = F_1 ( V_2 , V_65 -> V_37 , & V_31 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_50 , L_11 , V_31 ) ;
}
static T_3 F_26 ( struct V_47 * V_8 ,
struct V_48 * V_49 ,
const char * V_50 ,
T_4 V_51 )
{
struct V_27 * V_28 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_21 ( V_28 ) ;
struct V_64 * V_65 = F_25 ( V_49 ) ;
long V_31 ;
int V_7 ;
V_7 = F_23 ( V_50 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_14 ( & V_28 -> V_36 ) ;
V_7 = F_7 ( V_2 , V_65 -> V_37 , V_31 ) ;
F_17 ( & V_28 -> V_36 ) ;
return V_7 ? V_7 : V_51 ;
}
static T_5 F_27 ( int V_66 , void * V_67 )
{
struct V_27 * V_68 = V_67 ;
struct V_1 * V_2 = F_21 ( V_67 ) ;
T_1 V_69 ;
int V_70 , V_7 ;
V_7 = F_5 ( V_2 , V_71 , & V_69 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_69 )
return - V_72 ;
F_9 ( V_2 , V_71 , V_73 ) ;
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ ) {
if ( V_69 & ( 1 << V_70 ) )
F_28 ( V_68 , 0 ,
V_70 & 0x1 ?
F_29 ( V_70 >> 1 ) :
F_30 ( V_70 >> 1 ) ,
F_31 () ) ;
}
return V_74 ;
}
static int T_6 F_32 ( struct V_5 * V_6 ,
const struct V_75 * V_16 )
{
int V_7 , V_76 = 0 ;
struct V_77 * V_78 = V_6 -> V_8 . V_79 ;
struct V_1 * V_2 ;
struct V_27 * V_68 = F_33 ( sizeof( * V_2 ) ) ;
if ( V_68 == NULL )
return - V_80 ;
V_2 = F_34 ( V_68 ) ;
F_35 ( V_6 , V_68 ) ;
V_2 -> V_16 = V_16 -> V_81 ;
V_2 -> V_38 = & V_82 [ V_2 -> V_16 ] ;
V_2 -> V_11 = V_2 -> V_38 -> V_83 ;
if ( V_78 )
V_2 -> V_45 = V_78 -> V_84 ;
else
V_2 -> V_45 = V_2 -> V_38 -> V_45 ;
V_2 -> V_3 = F_36 ( & V_6 -> V_8 , L_12 ) ;
if ( ! F_37 ( V_2 -> V_3 ) ) {
V_7 = F_38 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_85;
}
V_2 -> V_6 = V_6 ;
V_68 -> V_8 . V_86 = & V_6 -> V_8 ;
V_68 -> V_87 = V_16 -> V_87 ;
V_68 -> V_88 = V_2 -> V_38 -> V_88 ;
V_68 -> V_87 = V_16 -> V_87 ;
V_68 -> V_34 = ( void * ) ( V_2 ) ;
V_68 -> V_89 = V_90 ;
V_68 -> V_91 = V_2 -> V_38 -> V_39 ;
V_68 -> V_92 = V_2 -> V_38 -> V_92 ;
V_7 = F_39 ( V_68 ) ;
if ( V_7 )
goto V_93;
V_7 = F_40 ( V_68 ) ;
if ( V_7 )
goto V_94;
V_76 = 1 ;
V_7 = F_41 ( V_68 -> V_95 , 0 ,
V_68 -> V_91 ,
V_68 -> V_92 ) ;
if ( V_7 )
goto V_94;
if ( V_6 -> V_66 > 0 ) {
V_7 = F_42 ( V_6 -> V_66 ,
NULL ,
F_27 ,
V_96 |
V_97 ,
V_6 -> V_87 ,
V_68 ) ;
if ( V_7 )
goto V_94;
}
return 0 ;
V_94:
F_43 ( V_68 ) ;
V_93:
if ( ! F_37 ( V_2 -> V_3 ) )
F_44 ( V_2 -> V_3 ) ;
V_85:
if ( ! F_37 ( V_2 -> V_3 ) )
F_45 ( V_2 -> V_3 ) ;
if ( V_76 )
F_46 ( V_68 ) ;
else
F_47 ( V_68 ) ;
return V_7 ;
}
static T_7 int F_48 ( struct V_5 * V_6 )
{
struct V_27 * V_68 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_68 ) ;
if ( V_6 -> V_66 > 0 )
F_50 ( V_6 -> V_66 , V_68 ) ;
F_51 ( V_68 -> V_95 ) ;
F_43 ( V_68 ) ;
if ( ! F_37 ( V_2 -> V_3 ) ) {
F_44 ( V_2 -> V_3 ) ;
F_45 ( V_2 -> V_3 ) ;
}
F_46 ( V_68 ) ;
return 0 ;
}
static T_8 int F_52 ( void )
{
return F_53 ( & V_98 ) ;
}
static T_9 void F_54 ( void )
{
F_55 ( & V_98 ) ;
}
