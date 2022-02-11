static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_6 = 0 ;
V_6 |= ( V_3 & V_7 ) ? V_8 : 0 ;
V_6 |= ( V_3 & V_9 ) ? V_10 : 0 ;
V_6 |= ( V_3 & V_11 ) ? 0 : V_12 | V_8 ;
F_2 ( V_6 , V_4 -> V_13 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_6 = F_4 ( V_4 -> V_13 ) ;
return ( V_6 & V_8 ) ? V_7 : 0 |
( V_6 & V_14 ) ? V_15 : 0 ;
}
static void F_5 ( struct V_1 * V_2 , bool V_16 )
{
}
static void F_6 ( struct V_4 * V_4 , T_1 V_3 )
{
if ( ! V_4 -> V_2 . V_17 )
V_3 |= V_12 ;
F_2 ( V_3 , V_4 -> V_13 ) ;
}
static void F_7 ( struct V_4 * V_4 , int V_18 , T_2 V_19 )
{
int V_20 ;
T_2 V_21 ;
T_1 V_22 ;
V_21 = F_8 ( V_18 / 10 ) | F_9 ( ( V_18 % 10 ) / 2 ) ;
V_21 |= V_19 ;
for ( V_20 = 0 ; V_20 < 18 ; V_20 ++ ) {
V_22 = V_21 & ( 1 << V_20 ) ? V_23 : 0 ;
F_6 ( V_4 , V_22 ) ;
F_10 ( 5 ) ;
F_6 ( V_4 , V_22 | V_24 ) ;
F_10 ( 5 ) ;
F_6 ( V_4 , V_22 ) ;
}
F_10 ( 5 ) ;
F_6 ( V_4 , V_25 ) ;
F_10 ( 5 ) ;
F_6 ( V_4 , 0 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 -> V_28 , struct V_1 , V_29 ) ;
struct V_4 * V_4 = V_2 -> V_5 ;
int V_30 , V_31 , V_32 , V_33 ;
switch ( V_27 -> V_34 ) {
case V_35 :
V_30 = V_27 -> V_36 ;
V_31 = V_4 -> V_31 -> V_37 . V_36 ;
break;
case V_38 :
V_31 = V_27 -> V_36 ;
V_30 = V_4 -> V_30 -> V_37 . V_36 ;
break;
default:
return - V_39 ;
}
V_32 = V_33 = V_30 ;
if ( V_31 < 0 )
V_33 = F_13 ( 0 , V_33 + V_31 ) ;
if ( V_31 > 0 )
V_32 = F_13 ( 0 , V_32 - V_31 ) ;
F_7 ( V_4 , abs ( V_32 - 68 ) , V_40 ) ;
F_7 ( V_4 , abs ( V_33 - 68 ) , V_41 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_42 && F_4 ( V_4 -> V_13 ) & V_43 ) {
V_4 -> V_30 = F_15 ( & V_2 -> V_29 , & V_44 , V_35 , 0 , 68 , 2 , 56 ) ;
V_4 -> V_31 = F_15 ( & V_2 -> V_29 , & V_44 , V_38 , - 68 , 68 , 2 , 0 ) ;
if ( V_2 -> V_29 . error ) {
F_16 ( V_45 L_1 ) ;
return V_2 -> V_29 . error ;
}
}
return 0 ;
}
static int T_3 F_17 ( struct V_4 * V_4 , struct V_46 * V_47 , int V_13 )
{
int V_48 , V_20 ;
char * V_49 = V_4 -> V_42 ? L_2 : L_3 ;
for ( V_20 = 0 ; V_20 < V_50 ; V_20 ++ )
if ( V_13 == V_51 [ V_20 ] -> V_13 )
return - V_52 ;
F_18 ( V_4 -> V_53 . V_54 , L_4 ,
sizeof( V_4 -> V_53 . V_54 ) ) ,
V_4 -> V_13 = V_13 ;
if ( ! F_19 ( V_4 -> V_13 , 2 , V_4 -> V_53 . V_54 ) ) {
F_16 ( V_45 L_5 , V_4 -> V_13 ) ;
return - V_52 ;
}
F_20 ( V_47 , V_4 ) ;
V_48 = F_21 ( V_47 , & V_4 -> V_53 ) ;
if ( V_48 < 0 ) {
F_22 ( & V_4 -> V_53 , L_6 ) ;
F_23 ( V_4 -> V_13 , 2 ) ;
return V_48 ;
}
V_4 -> V_2 . V_53 = & V_4 -> V_53 ;
V_4 -> V_2 . V_5 = V_4 ;
V_4 -> V_2 . V_55 = V_55 [ V_50 ] ;
V_4 -> V_2 . V_56 = & V_57 ;
V_4 -> V_2 . V_58 = F_14 ;
F_18 ( V_4 -> V_2 . V_59 , V_49 , sizeof( V_4 -> V_2 . V_59 ) ) ;
snprintf ( V_4 -> V_2 . V_60 , sizeof( V_4 -> V_2 . V_60 ) , L_7 ,
V_4 -> V_42 ? L_8 : L_9 , F_24 ( V_47 ) ) ;
if ( F_25 ( & V_4 -> V_2 , V_61 ) ) {
F_16 ( V_45 L_10 ) ;
F_23 ( V_4 -> V_13 , 2 ) ;
return - V_62 ;
}
F_16 ( V_63 L_11 ,
V_49 , V_4 -> V_13 ) ;
return 0 ;
}
static int T_3 F_26 ( struct V_46 * V_47 , unsigned int V_64 )
{
struct V_4 * V_4 = F_27 ( sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return 0 ;
if ( F_17 ( V_4 , V_47 , V_66 ) ) {
F_28 ( V_4 ) ;
return 0 ;
}
F_20 ( V_47 , V_4 ) ;
V_51 [ V_50 ++ ] = V_4 ;
return 1 ;
}
static int T_3 F_29 ( struct V_67 * V_47 ,
const struct V_68 * V_34 )
{
int V_69 ;
struct V_4 * V_4 = F_27 ( sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return - V_70 ;
V_4 -> V_42 = true ;
V_69 = F_17 ( V_4 , & V_47 -> V_71 , F_30 ( V_47 , 0 ) ) ;
if ( V_69 ) {
F_28 ( V_4 ) ;
return V_69 ;
}
F_31 ( V_47 , V_4 ) ;
V_51 [ V_50 ++ ] = V_4 ;
return 0 ;
}
static void T_4 F_32 ( struct V_4 * V_4 )
{
F_33 ( & V_4 -> V_2 ) ;
F_23 ( V_4 -> V_13 , 2 ) ;
F_34 ( & V_4 -> V_53 ) ;
F_28 ( V_4 ) ;
}
static int T_4 F_35 ( struct V_46 * V_47 , unsigned int V_64 )
{
F_32 ( F_36 ( V_47 ) ) ;
F_20 ( V_47 , NULL ) ;
return 0 ;
}
static void T_4 F_37 ( struct V_67 * V_47 )
{
F_32 ( F_38 ( V_47 ) ) ;
F_31 ( V_47 , NULL ) ;
}
static int T_5 F_39 ( void )
{
int V_69 ;
V_69 = F_40 ( & V_72 ) ;
if ( ! V_69 )
V_73 = true ;
V_69 = F_41 ( & V_74 , 1 ) ;
if ( ! V_69 )
V_75 = true ;
return ( V_73 || V_75 ) ? 0 : V_69 ;
}
static void T_6 F_42 ( void )
{
if ( V_73 )
F_43 ( & V_72 ) ;
if ( V_75 )
F_44 ( & V_74 ) ;
}
