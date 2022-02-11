static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ,
V_6 ,
NULL ) ;
return V_7 ;
}
static int F_3 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_12 , V_13 = V_4 -> V_14 + V_15 ;
V_12 = F_5 ( V_9 , V_10 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_6 ( V_11 , V_13 , V_16 , V_12 ) ;
}
static unsigned int F_7 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_17 = V_4 -> V_14 + V_18 ;
int V_19 = V_4 -> V_14 + V_20 ;
int V_21 ;
V_21 = F_8 ( V_11 , V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_21 & V_22 ) )
return V_23 ;
V_21 = F_8 ( V_11 , V_17 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 & V_24 )
return V_25 ;
else
return V_26 ;
}
static int F_9 ( struct V_8 * V_9 ,
unsigned int V_27 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_17 = V_4 -> V_14 + V_18 ;
int V_19 = V_4 -> V_14 + V_20 ;
int V_21 ;
switch ( V_27 ) {
case V_23 :
V_21 = F_6 ( V_11 , V_19 ,
V_22 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
case V_26 :
V_21 = F_6 ( V_11 , V_17 ,
V_24 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_11 , V_19 ,
V_22 ,
V_22 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
case V_25 :
V_21 = F_6 ( V_11 , V_17 ,
V_24 ,
V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_11 , V_19 ,
V_22 ,
V_22 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_29 = 1 << F_11 ( V_9 ) ;
int V_21 ;
V_21 = F_8 ( V_11 , V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_21 & V_29 ) )
return V_31 ;
V_21 = F_8 ( V_11 , V_32 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 & V_29 )
return V_33 ;
V_21 = F_7 ( V_9 ) ;
if ( V_21 < 0 )
return V_21 ;
else
return F_12 ( V_21 ) ;
}
static unsigned int F_13 ( struct V_8 * V_9 ,
int V_34 ,
int V_35 , int V_36 )
{
if ( V_36 < 20000 )
return V_25 ;
if ( V_36 < 50000 )
return V_26 ;
return V_23 ;
}
static int F_14 ( struct V_37 * V_38 )
{
struct V_11 * V_11 = F_15 ( V_38 -> V_39 . V_40 ) ;
struct V_41 * V_42 = F_16 ( V_11 -> V_39 ) ;
struct V_43 V_44 = { } ;
int V_45 ;
struct V_3 * V_4 ;
struct V_46 * V_47 ;
int V_21 , V_1 ;
if ( V_42 && V_42 -> V_48 )
V_45 = ( V_42 -> V_48 * 10 ) + 1 ;
else
V_45 = 0 ;
V_45 = V_38 -> V_45 - V_45 ;
F_17 ( & V_38 -> V_39 , L_1 , V_45 + 1 ) ;
V_4 = F_18 ( & V_38 -> V_39 , sizeof( struct V_3 ) , V_49 ) ;
if ( V_4 == NULL ) {
F_19 ( & V_38 -> V_39 , L_2 ) ;
return - V_50 ;
}
V_4 -> V_11 = V_11 ;
V_47 = F_20 ( V_38 , V_51 , 0 ) ;
if ( V_47 == NULL ) {
F_19 ( & V_38 -> V_39 , L_3 ) ;
V_21 = - V_28 ;
goto V_52;
}
V_4 -> V_14 = V_47 -> V_53 ;
snprintf ( V_4 -> V_54 , sizeof( V_4 -> V_54 ) , L_4 , V_45 + 1 ) ;
V_4 -> V_55 . V_54 = V_4 -> V_54 ;
snprintf ( V_4 -> V_56 , sizeof( V_4 -> V_56 ) ,
L_5 , V_45 + 1 ) ;
V_4 -> V_55 . V_56 = V_4 -> V_56 ;
V_4 -> V_55 . V_45 = V_45 ;
V_4 -> V_55 . type = V_57 ;
V_4 -> V_55 . V_58 = 32 ;
V_4 -> V_55 . V_59 = & V_60 ;
V_4 -> V_55 . V_61 = V_62 ;
V_4 -> V_55 . V_63 = V_4 -> V_14 + V_20 ;
V_4 -> V_55 . V_64 = V_16 ;
V_4 -> V_55 . V_65 = V_66 ;
V_4 -> V_55 . V_67 = 1 << V_45 ;
V_4 -> V_55 . V_68 = V_4 -> V_14 ;
V_4 -> V_55 . V_69 = V_70 ;
V_4 -> V_55 . V_71 = V_72 ;
V_4 -> V_55 . V_73 = F_21 ( V_72 ) ;
V_44 . V_39 = V_38 -> V_39 . V_40 ;
if ( V_42 )
V_44 . V_74 = V_42 -> V_4 [ V_45 ] ;
V_44 . V_75 = V_4 ;
V_44 . V_76 = V_11 -> V_76 ;
V_4 -> V_5 = F_22 ( & V_38 -> V_39 , & V_4 -> V_55 ,
& V_44 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
V_21 = F_24 ( V_4 -> V_5 ) ;
F_19 ( V_11 -> V_39 , L_6 ,
V_45 + 1 , V_21 ) ;
goto V_52;
}
V_1 = F_25 ( V_11 , F_26 ( V_38 , L_7 ) ) ;
V_21 = F_27 ( & V_38 -> V_39 , V_1 , NULL ,
F_1 ,
V_77 , V_4 -> V_54 ,
V_4 ) ;
if ( V_21 != 0 ) {
F_19 ( & V_38 -> V_39 , L_8 ,
V_1 , V_21 ) ;
goto V_52;
}
F_28 ( V_38 , V_4 ) ;
return 0 ;
V_52:
return V_21 ;
}
static int F_29 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_12 , V_13 = V_4 -> V_14 + V_15 ;
V_12 = F_5 ( V_9 , V_10 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_6 ( V_11 , V_13 , V_78 , V_12 ) ;
}
static unsigned int F_30 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_19 = V_4 -> V_14 + V_20 ;
int V_21 ;
V_21 = F_8 ( V_11 , V_19 ) ;
if ( V_21 < 0 )
return 0 ;
if ( V_21 & V_79 )
return V_26 ;
else
return V_23 ;
}
static int F_31 ( struct V_8 * V_9 ,
unsigned int V_27 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_19 = V_4 -> V_14 + V_20 ;
int V_21 ;
switch ( V_27 ) {
case V_23 :
V_21 = F_6 ( V_11 , V_19 , V_79 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
case V_26 :
V_21 = F_6 ( V_11 , V_19 , V_79 ,
V_79 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_29 = 1 << F_11 ( V_9 ) ;
int V_21 ;
V_21 = F_8 ( V_11 , V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_21 & V_29 ) )
return V_31 ;
V_21 = F_8 ( V_11 , V_32 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 & V_29 )
return V_33 ;
V_21 = F_30 ( V_9 ) ;
if ( V_21 < 0 )
return V_21 ;
else
return F_12 ( V_21 ) ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_11 * V_11 = F_15 ( V_38 -> V_39 . V_40 ) ;
struct V_41 * V_42 = F_16 ( V_11 -> V_39 ) ;
struct V_43 V_44 = { } ;
int V_45 ;
struct V_3 * V_4 ;
struct V_46 * V_47 ;
int V_21 , V_1 ;
if ( V_42 && V_42 -> V_48 )
V_45 = ( V_42 -> V_48 * 10 ) + 1 ;
else
V_45 = 0 ;
V_45 = V_38 -> V_45 - V_45 ;
F_17 ( & V_38 -> V_39 , L_1 , V_45 + 1 ) ;
V_4 = F_18 ( & V_38 -> V_39 , sizeof( struct V_3 ) , V_49 ) ;
if ( V_4 == NULL ) {
F_19 ( & V_38 -> V_39 , L_2 ) ;
return - V_50 ;
}
V_4 -> V_11 = V_11 ;
V_47 = F_20 ( V_38 , V_51 , 0 ) ;
if ( V_47 == NULL ) {
F_19 ( & V_38 -> V_39 , L_3 ) ;
V_21 = - V_28 ;
goto V_52;
}
V_4 -> V_14 = V_47 -> V_53 ;
snprintf ( V_4 -> V_54 , sizeof( V_4 -> V_54 ) , L_4 , V_45 + 1 ) ;
V_4 -> V_55 . V_54 = V_4 -> V_54 ;
snprintf ( V_4 -> V_56 , sizeof( V_4 -> V_56 ) ,
L_5 , V_45 + 1 ) ;
V_4 -> V_55 . V_56 = V_4 -> V_56 ;
V_4 -> V_55 . V_45 = V_45 ;
V_4 -> V_55 . type = V_57 ;
V_4 -> V_55 . V_58 = 32 ;
V_4 -> V_55 . V_71 = V_80 ;
V_4 -> V_55 . V_73 = F_21 ( V_80 ) ;
V_4 -> V_55 . V_59 = & V_81 ;
V_4 -> V_55 . V_61 = V_62 ;
V_4 -> V_55 . V_63 = V_4 -> V_14 + V_20 ;
V_4 -> V_55 . V_64 = V_78 ;
V_4 -> V_55 . V_65 = V_66 ;
V_4 -> V_55 . V_67 = 1 << V_45 ;
V_4 -> V_55 . V_68 = V_4 -> V_14 ;
V_4 -> V_55 . V_69 = V_82 ;
V_44 . V_39 = V_38 -> V_39 . V_40 ;
if ( V_42 )
V_44 . V_74 = V_42 -> V_4 [ V_45 ] ;
V_44 . V_75 = V_4 ;
V_44 . V_76 = V_11 -> V_76 ;
V_4 -> V_5 = F_22 ( & V_38 -> V_39 , & V_4 -> V_55 ,
& V_44 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
V_21 = F_24 ( V_4 -> V_5 ) ;
F_19 ( V_11 -> V_39 , L_6 ,
V_45 + 1 , V_21 ) ;
goto V_52;
}
V_1 = F_25 ( V_11 , F_26 ( V_38 , L_7 ) ) ;
V_21 = F_27 ( & V_38 -> V_39 , V_1 , NULL ,
F_1 ,
V_77 , V_4 -> V_54 , V_4 ) ;
if ( V_21 != 0 ) {
F_19 ( & V_38 -> V_39 , L_8 ,
V_1 , V_21 ) ;
goto V_52;
}
F_28 ( V_38 , V_4 ) ;
return 0 ;
V_52:
return V_21 ;
}
static int F_34 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_12 , V_13 = V_4 -> V_14 + V_83 ;
V_12 = F_35 ( V_9 , V_10 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_6 ( V_11 , V_13 , V_84 , V_12 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
struct V_11 * V_11 = V_4 -> V_11 ;
int V_29 = 1 << F_11 ( V_9 ) ;
int V_21 ;
V_21 = F_8 ( V_11 , V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 & V_29 )
return V_85 ;
else
return V_31 ;
}
static int F_37 ( struct V_37 * V_38 )
{
struct V_11 * V_11 = F_15 ( V_38 -> V_39 . V_40 ) ;
struct V_41 * V_42 = F_16 ( V_11 -> V_39 ) ;
struct V_43 V_44 = { } ;
int V_45 ;
struct V_3 * V_4 ;
struct V_46 * V_47 ;
int V_21 ;
if ( V_42 && V_42 -> V_48 )
V_45 = ( V_42 -> V_48 * 10 ) + 1 ;
else
V_45 = 0 ;
V_45 = V_38 -> V_45 - V_45 ;
F_17 ( & V_38 -> V_39 , L_1 , V_45 + 1 ) ;
V_4 = F_18 ( & V_38 -> V_39 , sizeof( struct V_3 ) , V_49 ) ;
if ( V_4 == NULL ) {
F_19 ( & V_38 -> V_39 , L_2 ) ;
return - V_50 ;
}
V_4 -> V_11 = V_11 ;
V_47 = F_20 ( V_38 , V_51 , 0 ) ;
if ( V_47 == NULL ) {
F_19 ( & V_38 -> V_39 , L_3 ) ;
V_21 = - V_28 ;
goto V_52;
}
V_4 -> V_14 = V_47 -> V_53 ;
snprintf ( V_4 -> V_54 , sizeof( V_4 -> V_54 ) , L_4 , V_45 + 1 ) ;
V_4 -> V_55 . V_54 = V_4 -> V_54 ;
snprintf ( V_4 -> V_56 , sizeof( V_4 -> V_56 ) ,
L_5 , V_45 + 1 ) ;
V_4 -> V_55 . V_56 = V_4 -> V_56 ;
V_4 -> V_55 . V_45 = V_45 ;
V_4 -> V_55 . type = V_57 ;
V_4 -> V_55 . V_58 = V_86 + 1 ;
V_4 -> V_55 . V_59 = & V_87 ;
V_4 -> V_55 . V_61 = V_62 ;
V_4 -> V_55 . V_63 = V_4 -> V_14 + V_88 ;
V_4 -> V_55 . V_64 = V_84 ;
V_4 -> V_55 . V_65 = V_66 ;
V_4 -> V_55 . V_67 = 1 << V_45 ;
V_4 -> V_55 . V_89 = 800000 ;
V_4 -> V_55 . V_90 = 50000 ;
V_4 -> V_55 . V_91 = 1000 ;
V_44 . V_39 = V_38 -> V_39 . V_40 ;
if ( V_42 )
V_44 . V_74 = V_42 -> V_4 [ V_45 ] ;
V_44 . V_75 = V_4 ;
V_44 . V_76 = V_11 -> V_76 ;
V_4 -> V_5 = F_22 ( & V_38 -> V_39 , & V_4 -> V_55 ,
& V_44 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
V_21 = F_24 ( V_4 -> V_5 ) ;
F_19 ( V_11 -> V_39 , L_6 ,
V_45 + 1 , V_21 ) ;
goto V_52;
}
F_28 ( V_38 , V_4 ) ;
return 0 ;
V_52:
return V_21 ;
}
static int T_2 F_38 ( void )
{
int V_21 ;
V_21 = F_39 ( & V_92 ) ;
if ( V_21 != 0 )
F_40 ( L_9 , V_21 ) ;
V_21 = F_39 ( & V_93 ) ;
if ( V_21 != 0 )
F_40 ( L_10 , V_21 ) ;
V_21 = F_39 ( & V_94 ) ;
if ( V_21 != 0 )
F_40 ( L_11 ,
V_21 ) ;
return 0 ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_94 ) ;
F_42 ( & V_93 ) ;
F_42 ( & V_92 ) ;
}
