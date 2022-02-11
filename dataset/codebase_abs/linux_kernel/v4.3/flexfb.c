static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 , L_1 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ;
switch ( V_2 -> V_9 -> V_10 . V_11 ) {
case 0 :
F_3 ( V_2 , 0x0020 , V_3 ) ;
F_3 ( V_2 , 0x0021 , V_4 ) ;
break;
case 180 :
F_3 ( V_2 , 0x0020 , V_12 - 1 - V_3 ) ;
F_3 ( V_2 , 0x0021 , V_13 - 1 - V_4 ) ;
break;
case 270 :
F_3 ( V_2 , 0x0020 , V_12 - 1 - V_4 ) ;
F_3 ( V_2 , 0x0021 , V_3 ) ;
break;
case 90 :
F_3 ( V_2 , 0x0020 , V_4 ) ;
F_3 ( V_2 , 0x0021 , V_13 - 1 - V_3 ) ;
break;
}
F_3 ( V_2 , 0x0022 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ;
switch ( V_2 -> V_9 -> V_10 . V_11 ) {
case 0 :
F_3 ( V_2 , 0x4e , V_3 ) ;
F_3 ( V_2 , 0x4f , V_4 ) ;
break;
case 180 :
F_3 ( V_2 , 0x4e , V_2 -> V_9 -> V_10 . V_14 - 1 - V_3 ) ;
F_3 ( V_2 , 0x4f , V_2 -> V_9 -> V_10 . V_15 - 1 - V_4 ) ;
break;
case 270 :
F_3 ( V_2 , 0x4e , V_2 -> V_9 -> V_10 . V_15 - 1 - V_4 ) ;
F_3 ( V_2 , 0x4f , V_3 ) ;
break;
case 90 :
F_3 ( V_2 , 0x4e , V_4 ) ;
F_3 ( V_2 , 0x4f , V_2 -> V_9 -> V_10 . V_14 - 1 - V_3 ) ;
break;
}
F_3 ( V_2 , 0x22 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 , V_8 ,
V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( V_2 , 0x15 , V_3 , V_5 ) ;
F_3 ( V_2 , 0x75 , V_4 , V_6 ) ;
F_3 ( V_2 , 0x5C ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_16 , V_2 , L_2 , V_8 ) ;
if ( V_2 -> V_17 . V_18 < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 ,
L_3 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_21 ;
int V_22 = V_23 ;
F_2 ( V_16 , V_2 , L_2 , V_8 ) ;
if ( V_2 -> V_17 . V_18 < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 , L_3 ) ;
return - V_20 ;
}
if ( V_2 -> V_17 . V_24 < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 , L_4 ) ;
return - V_20 ;
}
if ( V_25 && ( V_2 -> V_17 . V_26 < 0 ) ) {
F_7 ( V_2 -> V_9 -> V_19 , L_5 ) ;
return - V_20 ;
}
if ( V_25 )
V_22 = V_23 / 2 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_2 -> V_17 . V_27 [ V_21 ] < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 ,
L_6 ,
V_21 ) ;
return - V_20 ;
}
}
return 0 ;
}
static void F_9 ( const struct V_28 * V_29 )
{
if ( ! V_12 )
V_12 = V_29 -> V_12 ;
if ( ! V_13 )
V_13 = V_29 -> V_13 ;
V_30 = V_29 -> V_30 ;
if ( V_29 -> V_31 )
V_31 = V_29 -> V_31 ;
if ( ! V_32 ) {
V_33 = V_29 -> V_34 ;
V_35 = V_29 -> V_36 ;
}
}
static int F_10 ( const struct V_19 * V_37 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_11 ( V_38 ) ; V_21 ++ )
if ( ! strcmp ( V_29 , V_38 [ V_21 ] . V_39 ) ) {
F_9 ( & V_38 [ V_21 ] ) ;
return 0 ;
}
F_7 ( V_37 , L_7 , V_29 ) ;
return - V_20 ;
}
static int F_12 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_19 * V_37 ;
struct V_44 * V_9 ;
struct V_1 * V_2 ;
int V_45 ;
V_33 = V_46 ;
V_35 = V_32 ;
if ( V_41 )
V_37 = & V_41 -> V_37 ;
else
V_37 = & V_43 -> V_37 ;
F_13 ( V_37 , L_8 , V_8 ,
V_41 ? L_9 : L_10 ) ;
if ( V_29 ) {
V_45 = F_10 ( V_37 ) ;
if ( V_45 )
return V_45 ;
}
if ( V_12 == 0 || V_13 == 0 ) {
F_7 ( V_37 , L_11 ) ;
return - V_20 ;
}
V_47 . V_12 = V_12 ;
V_47 . V_13 = V_13 ;
F_13 ( V_37 , L_12 , V_12 , V_13 ) ;
F_13 ( V_37 , L_13 , V_29 ? V_29 : L_14 ) ;
F_13 ( V_37 , L_15 , V_30 ) ;
F_13 ( V_37 , L_16 , V_31 ) ;
F_13 ( V_37 , L_17 , V_23 ) ;
V_9 = F_14 ( & V_47 , V_37 , V_37 -> V_48 ) ;
if ( ! V_9 )
return - V_49 ;
V_2 = V_9 -> V_2 ;
if ( V_41 )
V_2 -> V_50 = V_41 ;
else
V_2 -> V_43 = V_43 ;
if ( ! V_2 -> V_51 )
V_2 -> V_51 = V_33 ;
V_2 -> V_52 . V_53 = V_54 ;
switch ( V_31 ) {
case 8 :
V_2 -> V_52 . V_55 = V_56 ;
break;
case 16 :
V_2 -> V_52 . V_55 = V_57 ;
break;
default:
F_7 ( V_37 ,
L_18 ,
V_31 ) ;
return - V_20 ;
}
if ( V_41 ) {
V_2 -> V_52 . V_58 = V_59 ;
switch ( V_23 ) {
case 8 :
V_2 -> V_52 . V_60 = V_61 ;
if ( ! V_2 -> V_62 )
V_2 -> V_52 . V_63 = F_6 ;
break;
case 9 :
if ( V_31 == 16 ) {
F_7 ( V_37 , L_19 , V_31 , V_23 ) ;
return - V_20 ;
}
V_2 -> V_52 . V_55 = V_64 ;
V_2 -> V_52 . V_60 = V_65 ;
if ( V_2 -> V_50 -> V_66 -> V_67
& F_15 ( 9 ) ) {
V_2 -> V_50 -> V_68 = 9 ;
} else {
F_16 ( V_37 ,
L_20 ) ;
V_2 -> V_69 = F_17 ( V_2 -> V_9 -> V_19 ,
V_2 -> V_70 . V_71 + ( V_2 -> V_70 . V_71 / 8 ) + 8 ,
V_72 ) ;
if ( ! V_2 -> V_69 ) {
V_45 = - V_49 ;
goto V_73;
}
V_2 -> V_52 . V_58 = V_74 ;
}
break;
default:
F_7 ( V_37 , L_21 , V_23 ) ;
return - V_20 ;
}
} else {
V_2 -> V_52 . V_63 = F_8 ;
switch ( V_23 ) {
case 8 :
V_2 -> V_52 . V_58 = V_75 ;
V_2 -> V_52 . V_60 = V_61 ;
break;
case 16 :
V_2 -> V_52 . V_55 = V_76 ;
if ( V_25 )
V_2 -> V_52 . V_58 = V_77 ;
else
V_2 -> V_52 . V_58 = V_78 ;
V_2 -> V_52 . V_60 = V_79 ;
break;
default:
F_7 ( V_37 , L_22 , V_23 ) ;
return - V_20 ;
}
}
switch ( V_30 ) {
case 0 :
break;
case 1 :
V_2 -> V_52 . V_80 = F_1 ;
break;
case 2 :
V_2 -> V_52 . V_80 = F_4 ;
break;
case 3 :
V_2 -> V_52 . V_80 = F_5 ;
break;
default:
F_7 ( V_37 , L_23 ,
V_30 ) ;
return - V_20 ;
}
if ( ! V_81 )
V_2 -> V_52 . V_82 = V_83 ;
V_45 = F_18 ( V_9 ) ;
if ( V_45 < 0 )
goto V_73;
return 0 ;
V_73:
F_19 ( V_9 ) ;
return V_45 ;
}
static int F_20 ( struct V_19 * V_37 , struct V_44 * V_9 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_20 ;
V_2 = V_9 -> V_2 ;
if ( V_2 )
F_2 ( V_84 , V_2 , L_2 ,
V_8 ) ;
F_21 ( V_9 ) ;
F_19 ( V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_40 * V_50 )
{
return F_12 ( V_50 , NULL ) ;
}
static int F_23 ( struct V_40 * V_50 )
{
struct V_44 * V_9 = F_24 ( V_50 ) ;
return F_20 ( & V_50 -> V_37 , V_9 ) ;
}
static int F_25 ( struct V_42 * V_43 )
{
return F_12 ( NULL , V_43 ) ;
}
static int F_26 ( struct V_42 * V_43 )
{
struct V_44 * V_9 = F_27 ( V_43 ) ;
return F_20 ( & V_43 -> V_37 , V_9 ) ;
}
static int T_1 F_28 ( void )
{
int V_45 , V_85 ;
V_45 = F_29 ( & V_86 ) ;
V_85 = F_30 ( & V_87 ) ;
if ( V_45 < 0 )
return V_45 ;
return V_85 ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_86 ) ;
F_33 ( & V_87 ) ;
}
