static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
switch ( V_2 -> V_7 -> V_8 . V_9 ) {
case 0 :
F_2 ( V_2 , 0x0020 , V_3 ) ;
F_2 ( V_2 , 0x0021 , V_4 ) ;
break;
case 180 :
F_2 ( V_2 , 0x0020 , V_10 - 1 - V_3 ) ;
F_2 ( V_2 , 0x0021 , V_11 - 1 - V_4 ) ;
break;
case 270 :
F_2 ( V_2 , 0x0020 , V_10 - 1 - V_4 ) ;
F_2 ( V_2 , 0x0021 , V_3 ) ;
break;
case 90 :
F_2 ( V_2 , 0x0020 , V_4 ) ;
F_2 ( V_2 , 0x0021 , V_11 - 1 - V_3 ) ;
break;
}
F_2 ( V_2 , 0x0022 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
switch ( V_2 -> V_7 -> V_8 . V_9 ) {
case 0 :
F_2 ( V_2 , 0x4e , V_3 ) ;
F_2 ( V_2 , 0x4f , V_4 ) ;
break;
case 180 :
F_2 ( V_2 , 0x4e , V_2 -> V_7 -> V_8 . V_12 - 1 - V_3 ) ;
F_2 ( V_2 , 0x4f , V_2 -> V_7 -> V_8 . V_13 - 1 - V_4 ) ;
break;
case 270 :
F_2 ( V_2 , 0x4e , V_2 -> V_7 -> V_8 . V_13 - 1 - V_4 ) ;
F_2 ( V_2 , 0x4f , V_3 ) ;
break;
case 90 :
F_2 ( V_2 , 0x4e , V_4 ) ;
F_2 ( V_2 , 0x4f , V_2 -> V_7 -> V_8 . V_12 - 1 - V_3 ) ;
break;
}
F_2 ( V_2 , 0x22 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_2 , 0x15 , V_3 , V_5 ) ;
F_2 ( V_2 , 0x75 , V_4 , V_6 ) ;
F_2 ( V_2 , 0x5C ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( V_14 , V_2 , L_1 , V_15 ) ;
if ( V_2 -> V_16 . V_17 < 0 ) {
F_7 ( V_2 -> V_7 -> V_18 ,
L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_20 ;
int V_21 = V_22 ;
F_6 ( V_14 , V_2 , L_1 , V_15 ) ;
if ( V_2 -> V_16 . V_17 < 0 ) {
F_7 ( V_2 -> V_7 -> V_18 , L_2 ) ;
return - V_19 ;
}
if ( V_2 -> V_16 . V_23 < 0 ) {
F_7 ( V_2 -> V_7 -> V_18 , L_3 ) ;
return - V_19 ;
}
if ( V_24 && ( V_2 -> V_16 . V_25 < 0 ) ) {
F_7 ( V_2 -> V_7 -> V_18 , L_4 ) ;
return - V_19 ;
}
if ( V_24 )
V_21 = V_22 / 2 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_2 -> V_16 . V_26 [ V_20 ] < 0 ) {
F_7 ( V_2 -> V_7 -> V_18 ,
L_5 ,
V_20 ) ;
return - V_19 ;
}
}
return 0 ;
}
static void F_9 ( const struct V_27 * V_28 )
{
if ( ! V_10 )
V_10 = V_28 -> V_10 ;
if ( ! V_11 )
V_11 = V_28 -> V_11 ;
V_29 = V_28 -> V_29 ;
if ( V_28 -> V_30 )
V_30 = V_28 -> V_30 ;
if ( ! V_31 ) {
V_32 = V_28 -> V_33 ;
V_34 = V_28 -> V_35 ;
}
}
static int F_10 ( const struct V_18 * V_36 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_11 ( V_37 ) ; V_20 ++ )
if ( ! strcmp ( V_28 , V_37 [ V_20 ] . V_38 ) ) {
F_9 ( & V_37 [ V_20 ] ) ;
return 0 ;
}
F_7 ( V_36 , L_6 , V_28 ) ;
return - V_19 ;
}
static int F_12 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_18 * V_36 ;
struct V_43 * V_7 ;
struct V_1 * V_2 ;
int V_44 ;
V_32 = V_45 ;
V_34 = V_31 ;
if ( V_40 )
V_36 = & V_40 -> V_36 ;
else
V_36 = & V_42 -> V_36 ;
F_13 ( V_36 , L_7 , V_15 ,
V_40 ? L_8 : L_9 ) ;
if ( V_28 ) {
V_44 = F_10 ( V_36 ) ;
if ( V_44 )
return V_44 ;
}
if ( V_10 == 0 || V_11 == 0 ) {
F_7 ( V_36 , L_10 ) ;
return - V_19 ;
}
V_46 . V_10 = V_10 ;
V_46 . V_11 = V_11 ;
F_13 ( V_36 , L_11 , V_10 , V_11 ) ;
F_13 ( V_36 , L_12 , V_28 ? V_28 : L_13 ) ;
F_13 ( V_36 , L_14 , V_29 ) ;
F_13 ( V_36 , L_15 , V_30 ) ;
F_13 ( V_36 , L_16 , V_22 ) ;
V_7 = F_14 ( & V_46 , V_36 , V_36 -> V_47 ) ;
if ( ! V_7 )
return - V_48 ;
V_2 = V_7 -> V_2 ;
if ( V_40 )
V_2 -> V_49 = V_40 ;
else
V_2 -> V_42 = V_42 ;
if ( ! V_2 -> V_50 )
V_2 -> V_50 = V_32 ;
V_2 -> V_51 . V_52 = V_53 ;
switch ( V_30 ) {
case 8 :
V_2 -> V_51 . V_54 = V_55 ;
break;
case 16 :
V_2 -> V_51 . V_54 = V_56 ;
break;
default:
F_7 ( V_36 ,
L_17 ,
V_30 ) ;
return - V_19 ;
}
if ( V_40 ) {
V_2 -> V_51 . V_57 = V_58 ;
switch ( V_22 ) {
case 8 :
V_2 -> V_51 . V_59 = V_60 ;
if ( ! V_2 -> V_61 )
V_2 -> V_51 . V_62 = F_5 ;
break;
case 9 :
if ( V_30 == 16 ) {
F_7 ( V_36 , L_18 , V_30 , V_22 ) ;
return - V_19 ;
}
V_2 -> V_51 . V_54 = V_63 ;
V_2 -> V_51 . V_59 = V_64 ;
if ( V_2 -> V_49 -> V_65 -> V_66
& F_15 ( 9 ) ) {
V_2 -> V_49 -> V_67 = 9 ;
} else {
F_16 ( V_36 ,
L_19 ) ;
V_2 -> V_68 = F_17 ( V_2 -> V_7 -> V_18 ,
V_2 -> V_69 . V_70 + ( V_2 -> V_69 . V_70 / 8 ) + 8 ,
V_71 ) ;
if ( ! V_2 -> V_68 ) {
V_44 = - V_48 ;
goto V_72;
}
V_2 -> V_51 . V_57 = V_73 ;
}
break;
default:
F_7 ( V_36 , L_20 , V_22 ) ;
return - V_19 ;
}
} else {
V_2 -> V_51 . V_62 = F_8 ;
switch ( V_22 ) {
case 8 :
V_2 -> V_51 . V_57 = V_74 ;
V_2 -> V_51 . V_59 = V_60 ;
break;
case 16 :
V_2 -> V_51 . V_54 = V_75 ;
if ( V_24 )
V_2 -> V_51 . V_57 = V_76 ;
else
V_2 -> V_51 . V_57 = V_77 ;
V_2 -> V_51 . V_59 = V_78 ;
break;
default:
F_7 ( V_36 , L_21 , V_22 ) ;
return - V_19 ;
}
}
switch ( V_29 ) {
case 0 :
break;
case 1 :
V_2 -> V_51 . V_79 = F_1 ;
break;
case 2 :
V_2 -> V_51 . V_79 = F_3 ;
break;
case 3 :
V_2 -> V_51 . V_79 = F_4 ;
break;
default:
F_7 ( V_36 , L_22 ,
V_29 ) ;
return - V_19 ;
}
if ( ! V_80 )
V_2 -> V_51 . V_81 = V_82 ;
V_44 = F_18 ( V_7 ) ;
if ( V_44 < 0 )
goto V_72;
return 0 ;
V_72:
F_19 ( V_7 ) ;
return V_44 ;
}
static int F_20 ( struct V_18 * V_36 , struct V_43 * V_7 )
{
struct V_1 * V_2 ;
if ( ! V_7 )
return - V_19 ;
V_2 = V_7 -> V_2 ;
if ( V_2 )
F_6 ( V_83 , V_2 , L_1 ,
V_15 ) ;
F_21 ( V_7 ) ;
F_19 ( V_7 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_49 )
{
return F_12 ( V_49 , NULL ) ;
}
static int F_23 ( struct V_39 * V_49 )
{
struct V_43 * V_7 = F_24 ( V_49 ) ;
return F_20 ( & V_49 -> V_36 , V_7 ) ;
}
static int F_25 ( struct V_41 * V_42 )
{
return F_12 ( NULL , V_42 ) ;
}
static int F_26 ( struct V_41 * V_42 )
{
struct V_43 * V_7 = F_27 ( V_42 ) ;
return F_20 ( & V_42 -> V_36 , V_7 ) ;
}
static int T_1 F_28 ( void )
{
int V_44 , V_84 ;
V_44 = F_29 ( & V_85 ) ;
V_84 = F_30 ( & V_86 ) ;
if ( V_44 < 0 )
return V_44 ;
return V_84 ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_85 ) ;
F_33 ( & V_86 ) ;
}
