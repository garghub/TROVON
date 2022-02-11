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
V_7 = F_17 ( V_28 ,
V_30 -> V_36 ) ;
else
V_7 = F_12 ( V_2 , V_30 -> V_36 ) ;
F_18 ( & V_28 -> V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_31 = ( V_7 >> V_30 -> V_37 . V_38 ) &
F_19 ( V_30 -> V_37 . V_39 ) ;
return V_40 ;
case ( 1 << V_41 ) :
V_34 = ( V_2 -> V_42 * 1000 ) >> V_30 -> V_37 . V_39 ;
* V_31 = V_34 / 1000 ;
* V_32 = ( V_34 % 1000 ) * 1000 ;
return V_43 ;
}
return - V_26 ;
}
static T_3 F_20 ( struct V_44 * V_8 ,
struct V_45 * V_46 ,
char * V_47 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_7 ;
T_1 V_31 ;
V_7 = F_5 ( V_2 , V_48 , & V_31 ) ;
if ( V_7 )
return V_7 ;
V_31 &= V_49 ;
return sprintf ( V_47 , L_3 , V_50 [ V_31 ] ) ;
}
static T_3 F_22 ( struct V_44 * V_8 ,
struct V_45 * V_46 ,
const char * V_47 ,
T_4 V_51 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
long V_31 ;
int V_7 , V_52 ;
T_1 V_53 ;
V_7 = F_23 ( V_47 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_5 ( V_2 , V_48 , & V_53 ) ;
if ( V_7 )
goto V_54;
V_53 &= ~ V_49 ;
for ( V_52 = 0 ; V_52 < F_24 ( V_50 ) ; V_52 ++ )
if ( V_31 == V_50 [ V_52 ] )
break;
if ( V_52 == F_24 ( V_50 ) ) {
V_7 = - V_26 ;
goto V_54;
}
V_53 |= V_52 ;
V_7 = F_9 ( V_2 , V_48 , V_53 ) ;
V_54:
F_18 ( & V_28 -> V_35 ) ;
return V_7 ? V_7 : V_51 ;
}
static int F_25 ( struct V_27 * V_28 ,
T_5 V_55 )
{
return 1 ;
}
static int F_26 ( struct V_27 * V_28 ,
T_5 V_55 ,
int V_31 )
{
int V_7 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_56 = ! ! ( F_27 ( V_55 ) ==
V_57 ) ;
int V_58 = F_28 ( V_55 ) ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_7 ( V_2 ,
V_59 [ V_58 ] [ V_56 ] ,
V_31 ) ;
F_18 ( & V_28 -> V_35 ) ;
return V_7 ;
}
static int F_29 ( struct V_27 * V_28 ,
T_5 V_55 ,
int * V_31 )
{
int V_7 ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_56 = ! ! ( F_27 ( V_55 ) ==
V_57 ) ;
int V_58 = F_28 ( V_55 ) ;
T_2 V_60 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_1 ( V_2 ,
V_59 [ V_58 ] [ V_56 ] ,
& V_60 ) ;
F_18 ( & V_28 -> V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_31 = V_60 ;
return 0 ;
}
static T_3 F_30 ( struct V_44 * V_8 ,
struct V_45 * V_46 ,
char * V_47 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_61 * V_62 = F_31 ( V_46 ) ;
int V_7 ;
T_2 V_31 ;
V_7 = F_1 ( V_2 , V_62 -> V_63 , & V_31 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_47 , L_4 , V_31 ) ;
}
static T_3 F_32 ( struct V_44 * V_8 ,
struct V_45 * V_46 ,
const char * V_47 ,
T_4 V_51 )
{
struct V_27 * V_28 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_61 * V_62 = F_31 ( V_46 ) ;
long V_31 ;
int V_7 ;
V_7 = F_23 ( V_47 , 10 , & V_31 ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_28 -> V_35 ) ;
V_7 = F_7 ( V_2 , V_62 -> V_63 , V_31 ) ;
F_18 ( & V_28 -> V_35 ) ;
return V_7 ? V_7 : V_51 ;
}
static T_6 F_33 ( int V_64 , void * V_65 )
{
struct V_27 * V_28 = V_65 ;
struct V_1 * V_2 = F_14 ( V_65 ) ;
T_1 V_66 ;
int V_52 , V_7 ;
V_7 = F_5 ( V_2 , V_67 , & V_66 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_66 )
return - V_68 ;
F_9 ( V_2 , V_67 , V_69 ) ;
for ( V_52 = 0 ; V_52 < 8 ; V_52 ++ ) {
if ( V_66 & ( 1 << V_52 ) )
F_34 ( V_28 ,
V_52 & 0x1 ?
F_35 ( V_70 ,
( V_52 >> 1 ) ,
V_71 ,
V_72 ) :
F_35 ( V_70 ,
( V_52 >> 1 ) ,
V_71 ,
V_57 ) ,
F_36 () ) ;
}
return V_73 ;
}
static int T_7 F_37 ( struct V_5 * V_6 ,
const struct V_74 * V_16 )
{
int V_7 ;
struct V_75 * V_76 = V_6 -> V_8 . V_77 ;
struct V_1 * V_2 ;
struct V_27 * V_28 = F_38 ( sizeof( * V_2 ) ) ;
if ( V_28 == NULL )
return - V_78 ;
V_2 = F_14 ( V_28 ) ;
F_39 ( V_6 , V_28 ) ;
V_2 -> V_16 = V_16 -> V_79 ;
V_2 -> V_80 = & V_81 [ V_2 -> V_16 ] ;
V_2 -> V_11 = V_2 -> V_80 -> V_82 ;
if ( V_76 )
V_2 -> V_42 = V_76 -> V_83 ;
else
V_2 -> V_42 = V_2 -> V_80 -> V_42 ;
V_2 -> V_3 = F_40 ( & V_6 -> V_8 , L_5 ) ;
if ( ! F_41 ( V_2 -> V_3 ) ) {
V_7 = F_42 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_84;
}
V_2 -> V_6 = V_6 ;
V_28 -> V_8 . V_85 = & V_6 -> V_8 ;
V_28 -> V_86 = V_16 -> V_86 ;
V_28 -> V_87 = V_2 -> V_80 -> V_87 ;
V_28 -> V_88 = V_89 ;
V_28 -> V_90 = V_2 -> V_80 -> V_91 ;
V_28 -> V_92 = V_2 -> V_80 -> V_92 ;
V_7 = F_43 ( V_28 ) ;
if ( V_7 )
goto V_93;
V_7 = F_44 ( V_28 ,
V_28 -> V_90 ,
V_28 -> V_92 ) ;
if ( V_7 )
goto V_94;
if ( V_6 -> V_64 > 0 ) {
V_7 = F_45 ( V_6 -> V_64 ,
NULL ,
F_33 ,
V_95 |
V_96 ,
V_6 -> V_86 ,
V_28 ) ;
if ( V_7 )
goto V_94;
}
V_7 = F_46 ( V_28 ) ;
if ( V_7 )
goto V_97;
return 0 ;
V_97:
F_47 ( V_6 -> V_64 , V_28 ) ;
V_94:
F_48 ( V_28 ) ;
V_93:
if ( ! F_41 ( V_2 -> V_3 ) )
F_49 ( V_2 -> V_3 ) ;
V_84:
if ( ! F_41 ( V_2 -> V_3 ) )
F_50 ( V_2 -> V_3 ) ;
F_51 ( V_28 ) ;
return V_7 ;
}
static T_8 int F_52 ( struct V_5 * V_6 )
{
struct V_27 * V_28 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
F_54 ( V_28 ) ;
if ( V_6 -> V_64 > 0 )
F_47 ( V_6 -> V_64 , V_28 ) ;
F_55 ( V_28 ) ;
F_48 ( V_28 ) ;
if ( ! F_41 ( V_2 -> V_3 ) ) {
F_49 ( V_2 -> V_3 ) ;
F_50 ( V_2 -> V_3 ) ;
}
F_51 ( V_28 ) ;
return 0 ;
}
static T_9 int F_56 ( void )
{
return F_57 ( & V_98 ) ;
}
static T_10 void F_58 ( void )
{
F_59 ( & V_98 ) ;
}
