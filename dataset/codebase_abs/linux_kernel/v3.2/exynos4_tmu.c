static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( V_3 < 25 || V_3 > 125 ) {
V_6 = - V_7 ;
goto V_8;
}
switch ( V_5 -> V_9 ) {
case V_10 :
V_6 = ( V_3 - 25 ) *
( V_2 -> V_11 - V_2 -> V_12 ) /
( 85 - 25 ) + V_2 -> V_12 ;
break;
case V_13 :
V_6 = V_3 + V_2 -> V_12 - 25 ;
break;
default:
V_6 = V_3 + V_14 ;
break;
}
V_8:
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 ;
if ( V_6 < 75 || V_6 > 175 ) {
V_3 = - V_15 ;
goto V_8;
}
switch ( V_5 -> V_9 ) {
case V_10 :
V_3 = ( V_6 - V_2 -> V_12 ) * ( 85 - 25 ) /
( V_2 -> V_11 - V_2 -> V_12 ) + 25 ;
break;
case V_13 :
V_3 = V_6 - V_2 -> V_12 + 25 ;
break;
default:
V_3 = V_6 - V_14 ;
break;
}
V_8:
return V_3 ;
}
static int F_3 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_18 , V_19 ;
int V_20 = 0 , V_21 ;
F_5 ( & V_2 -> V_22 ) ;
F_6 ( V_2 -> V_23 ) ;
V_18 = F_7 ( V_2 -> V_24 + V_25 ) ;
if ( ! V_18 ) {
V_20 = - V_26 ;
goto V_8;
}
V_19 = F_8 ( V_2 -> V_24 + V_27 ) ;
V_2 -> V_12 = V_19 & V_28 ;
V_2 -> V_11 = ( ( V_19 >> 8 ) & V_28 ) ;
V_21 = F_1 ( V_2 , V_5 -> V_29 ) ;
if ( V_21 < 0 ) {
V_20 = V_21 ;
goto V_8;
}
F_9 ( V_21 ,
V_2 -> V_24 + V_30 ) ;
F_9 ( V_5 -> V_31 [ 0 ] ,
V_2 -> V_24 + V_32 ) ;
F_9 ( V_5 -> V_31 [ 1 ] ,
V_2 -> V_24 + V_33 ) ;
F_9 ( V_5 -> V_31 [ 2 ] ,
V_2 -> V_24 + V_34 ) ;
F_9 ( V_5 -> V_31 [ 3 ] ,
V_2 -> V_24 + V_35 ) ;
F_10 ( V_36 ,
V_2 -> V_24 + V_37 ) ;
V_8:
F_11 ( V_2 -> V_23 ) ;
F_12 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static void F_13 ( struct V_16 * V_17 , bool V_38 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_39 , V_40 ;
F_5 ( & V_2 -> V_22 ) ;
F_6 ( V_2 -> V_23 ) ;
V_39 = V_5 -> V_41 << V_42 |
V_5 -> V_43 << V_44 ;
if ( V_38 ) {
V_39 |= V_45 ;
V_40 = V_5 -> V_46 << 12 |
V_5 -> V_47 << 8 |
V_5 -> V_48 << 4 |
V_5 -> V_49 ;
} else {
V_39 |= V_50 ;
V_40 = 0 ;
}
F_10 ( V_40 , V_2 -> V_24 + V_51 ) ;
F_10 ( V_39 , V_2 -> V_24 + V_52 ) ;
F_11 ( V_2 -> V_23 ) ;
F_12 ( & V_2 -> V_22 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_3 ;
F_5 ( & V_2 -> V_22 ) ;
F_6 ( V_2 -> V_23 ) ;
V_6 = F_7 ( V_2 -> V_24 + V_53 ) ;
V_3 = F_2 ( V_2 , V_6 ) ;
F_11 ( V_2 -> V_23 ) ;
F_12 ( & V_2 -> V_22 ) ;
return V_3 ;
}
static void F_15 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_16 ( V_55 ,
struct V_1 , V_56 ) ;
F_5 ( & V_2 -> V_22 ) ;
F_6 ( V_2 -> V_23 ) ;
F_10 ( V_36 , V_2 -> V_24 + V_37 ) ;
F_17 ( & V_2 -> V_57 -> V_58 , V_59 ) ;
F_18 ( V_2 -> V_60 ) ;
F_11 ( V_2 -> V_23 ) ;
F_12 ( & V_2 -> V_22 ) ;
}
static T_2 F_19 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
F_20 ( V_60 ) ;
F_21 ( & V_2 -> V_56 ) ;
return V_62 ;
}
static T_3 F_22 ( struct V_63 * V_64 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_1 ) ;
}
static T_3 F_23 ( struct V_63 * V_64 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_1 * V_2 = F_24 ( V_64 ) ;
int V_20 ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
return sprintf ( V_67 , L_2 , V_20 * 1000 ) ;
}
static T_3 F_25 ( struct V_63 * V_64 ,
struct V_65 * V_68 , char * V_67 )
{
struct V_69 * V_66 = F_26 ( V_68 ) ;
struct V_1 * V_2 = F_24 ( V_64 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 ;
unsigned int V_70 ;
V_3 = F_14 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_70 = V_5 -> V_29 + V_5 -> V_31 [ V_66 -> V_71 ] ;
return sprintf ( V_67 , L_2 , ! ! ( V_3 > V_70 ) ) ;
}
static T_3 F_27 ( struct V_63 * V_64 ,
struct V_65 * V_68 , char * V_67 )
{
struct V_69 * V_66 = F_26 ( V_68 ) ;
struct V_1 * V_2 = F_24 ( V_64 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_3 = V_5 -> V_29 +
V_5 -> V_31 [ V_66 -> V_71 ] ;
return sprintf ( V_67 , L_3 , V_3 * 1000 ) ;
}
static int T_4 F_28 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = V_17 -> V_64 . V_72 ;
int V_20 ;
if ( ! V_5 ) {
F_29 ( & V_17 -> V_64 , L_4 ) ;
return - V_73 ;
}
V_2 = F_30 ( sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_2 ) {
F_29 ( & V_17 -> V_64 , L_5 ) ;
return - V_75 ;
}
V_2 -> V_60 = F_31 ( V_17 , 0 ) ;
if ( V_2 -> V_60 < 0 ) {
V_20 = V_2 -> V_60 ;
F_29 ( & V_17 -> V_64 , L_6 ) ;
goto V_76;
}
F_32 ( & V_2 -> V_56 , F_15 ) ;
V_2 -> V_77 = F_33 ( V_17 , V_78 , 0 ) ;
if ( ! V_2 -> V_77 ) {
V_20 = - V_79 ;
F_29 ( & V_17 -> V_64 , L_7 ) ;
goto V_76;
}
V_2 -> V_77 = F_34 ( V_2 -> V_77 -> V_80 ,
F_35 ( V_2 -> V_77 ) , V_17 -> V_81 ) ;
if ( ! V_2 -> V_77 ) {
V_20 = - V_73 ;
F_29 ( & V_17 -> V_64 , L_8 ) ;
goto V_76;
}
V_2 -> V_24 = F_36 ( V_2 -> V_77 -> V_80 , F_35 ( V_2 -> V_77 ) ) ;
if ( ! V_2 -> V_24 ) {
V_20 = - V_73 ;
F_29 ( & V_17 -> V_64 , L_9 ) ;
goto V_82;
}
V_20 = F_37 ( V_2 -> V_60 , F_19 ,
V_83 ,
L_10 , V_2 ) ;
if ( V_20 ) {
F_29 ( & V_17 -> V_64 , L_11 , V_2 -> V_60 ) ;
goto V_84;
}
V_2 -> V_23 = F_38 ( NULL , L_12 ) ;
if ( F_39 ( V_2 -> V_23 ) ) {
V_20 = F_40 ( V_2 -> V_23 ) ;
F_29 ( & V_17 -> V_64 , L_13 ) ;
goto V_85;
}
V_2 -> V_5 = V_5 ;
F_41 ( V_17 , V_2 ) ;
F_42 ( & V_2 -> V_22 ) ;
V_20 = F_3 ( V_17 ) ;
if ( V_20 ) {
F_29 ( & V_17 -> V_64 , L_14 ) ;
goto V_86;
}
V_20 = F_43 ( & V_17 -> V_64 . V_58 , & V_87 ) ;
if ( V_20 ) {
F_29 ( & V_17 -> V_64 , L_15 ) ;
goto V_86;
}
V_2 -> V_57 = F_44 ( & V_17 -> V_64 ) ;
if ( F_39 ( V_2 -> V_57 ) ) {
V_20 = F_40 ( V_2 -> V_57 ) ;
F_29 ( & V_17 -> V_64 , L_16 ) ;
goto V_88;
}
F_13 ( V_17 , true ) ;
return 0 ;
V_88:
F_45 ( & V_17 -> V_64 . V_58 , & V_87 ) ;
V_86:
F_41 ( V_17 , NULL ) ;
F_46 ( V_2 -> V_23 ) ;
V_85:
F_47 ( V_2 -> V_60 , V_2 ) ;
V_84:
F_48 ( V_2 -> V_24 ) ;
V_82:
F_49 ( V_2 -> V_77 -> V_80 , F_35 ( V_2 -> V_77 ) ) ;
V_76:
F_50 ( V_2 ) ;
return V_20 ;
}
static int T_5 F_51 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
F_13 ( V_17 , false ) ;
F_52 ( V_2 -> V_57 ) ;
F_45 ( & V_17 -> V_64 . V_58 , & V_87 ) ;
F_46 ( V_2 -> V_23 ) ;
F_47 ( V_2 -> V_60 , V_2 ) ;
F_48 ( V_2 -> V_24 ) ;
F_49 ( V_2 -> V_77 -> V_80 , F_35 ( V_2 -> V_77 ) ) ;
F_41 ( V_17 , NULL ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , T_6 V_89 )
{
F_13 ( V_17 , false ) ;
return 0 ;
}
static int F_54 ( struct V_16 * V_17 )
{
F_3 ( V_17 ) ;
F_13 ( V_17 , true ) ;
return 0 ;
}
