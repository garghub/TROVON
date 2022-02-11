static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
T_1 V_5 , V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_10 )
V_8 -> V_10 ( V_2 , V_3 ) ;
if ( V_3 ) {
if ( F_2 () ) {
V_5 = F_3 ( V_11 ) ;
if ( ( 1 << V_4 ) >= V_12 )
V_5 |= V_13 ;
else
V_5 &= ~ V_13 ;
F_4 ( V_5 , V_11 ) ;
}
if ( V_8 -> V_14 ) {
V_5 = F_3 ( V_15 ) ;
V_5 |= V_16 ;
F_4 ( V_5 , V_15 ) ;
}
V_5 = F_3 ( V_17 ) ;
if ( F_5 () ) {
V_6 = F_3 ( V_18 ) ;
V_6 |= V_19 ;
F_4 ( V_6 , V_18 ) ;
} else {
V_5 |= V_20 ;
}
V_5 &= ~ V_21 ;
F_4 ( V_5 , V_17 ) ;
} else {
V_5 = F_3 ( V_17 ) ;
V_5 &= ~ V_21 ;
F_4 ( V_5 , V_17 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 ;
F_7 ( 100 ) ;
if ( V_3 ) {
V_5 = F_3 ( V_17 ) ;
V_5 |= ( V_21 | V_20 ) ;
if ( ( 1 << V_4 ) <= V_22 )
V_5 &= ~ V_23 ;
else
V_5 |= V_23 ;
F_4 ( V_5 , V_17 ) ;
} else {
V_5 = F_3 ( V_17 ) ;
V_5 |= ( V_20 | V_21 |
V_23 ) ;
F_4 ( V_5 , V_17 ) ;
}
}
static void F_8 ( struct V_7 * V_8 )
{
T_1 V_5 ;
V_5 = F_3 ( V_24 ) ;
if ( V_8 -> V_14 )
V_5 |= V_25 ;
else
V_5 &= ~ V_25 ;
F_4 ( V_5 , V_24 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_10 )
V_8 -> V_10 ( V_2 , V_3 ) ;
if ( V_3 )
F_8 ( V_8 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_3 )
F_8 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return 0 ;
}
static int T_2 F_12 ( struct V_26 * V_27 ,
struct V_7 * V_8 )
{
char * V_28 ;
V_28 = F_13 ( sizeof( char ) * ( V_29 + 1 ) , V_30 ) ;
if ( ! V_28 ) {
F_14 ( L_1 ) ;
F_15 ( V_28 ) ;
return - V_31 ;
}
if ( V_27 -> V_32 )
strncpy ( V_28 , V_27 -> V_32 , V_29 ) ;
else
snprintf ( V_28 , ( V_29 + 1 ) , L_2 ,
V_27 -> V_8 , 1 ) ;
V_8 -> V_32 = V_28 ;
V_8 -> V_33 = V_27 -> V_33 ;
V_8 -> V_14 = ! V_27 -> V_34 ;
V_8 -> V_35 = 0 ;
if ( V_27 -> V_36 ) {
V_8 -> V_37 = - V_38 ;
V_8 -> V_39 = V_27 -> V_37 ;
} else {
V_8 -> V_37 = V_27 -> V_37 ;
V_8 -> V_39 = - V_38 ;
}
V_8 -> V_40 = V_27 -> V_40 ;
V_8 -> V_10 = V_27 -> V_10 ;
V_8 -> V_41 = V_27 -> V_41 ;
if ( V_27 -> V_42 )
V_8 -> V_42 = 1 ;
if ( F_16 () )
V_8 -> V_43 = V_22 |
V_44 |
V_45 |
V_46 |
V_12 |
V_47 ;
else
V_8 -> V_43 = V_27 -> V_43 ;
if ( ! F_16 () )
V_8 -> V_48 |= V_49 ;
switch ( V_27 -> V_8 ) {
case 1 :
if ( V_8 -> V_48 & V_49 ) {
V_8 -> V_50 =
F_1 ;
V_8 -> V_51 =
F_6 ;
}
if ( F_16 () )
V_8 -> V_52 = F_11 ;
if ( F_5 () &&
( V_27 -> V_33 & V_53 ) ) {
V_27 -> V_33 &= ~ V_53 ;
V_27 -> V_33 |= V_54 ;
V_8 -> V_33 = V_27 -> V_33 ;
}
break;
case 2 :
if ( F_16 () )
V_8 -> V_52 = F_10 ;
if ( V_27 -> V_34 )
V_27 -> V_55 = 1 ;
if ( V_27 -> V_55 && ( V_27 -> V_33 & V_53 ) ) {
V_27 -> V_33 &= ~ V_53 ;
V_27 -> V_33 |= V_54 ;
}
if ( V_8 -> V_48 & V_49 ) {
V_8 -> V_50 = F_9 ;
V_8 -> V_51 = NULL ;
}
break;
case 3 :
case 4 :
case 5 :
V_8 -> V_50 = NULL ;
V_8 -> V_51 = NULL ;
break;
default:
F_14 ( L_3 , V_27 -> V_8 ) ;
F_15 ( V_28 ) ;
return - V_56 ;
}
return 0 ;
}
void F_17 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
struct V_7 * V_59 ;
int V_60 ;
if ( V_61 != 1 )
return;
V_61 ++ ;
for (; V_27 -> V_8 ; V_27 ++ ) {
if ( ! V_27 -> V_62 )
continue;
V_58 = V_27 -> V_58 ;
if ( ! V_58 )
continue;
V_59 = V_58 -> V_2 . V_9 ;
if ( ! V_59 )
continue;
if ( V_27 -> V_36 ) {
V_59 -> V_37 = - V_38 ;
V_59 -> V_39 = V_27 -> V_37 ;
} else {
V_59 -> V_37 = V_27 -> V_37 ;
V_59 -> V_39 = - V_38 ;
}
V_59 -> V_40 = V_27 -> V_40 ;
V_60 = F_18 ( V_58 ) ;
if ( V_60 )
F_14 ( L_4 ,
V_27 -> V_32 ) ;
}
}
static void T_2 F_19 ( struct V_26 * V_63 ,
int V_64 )
{
struct V_65 * V_66 ;
struct V_65 * V_67 [ 1 ] ;
struct V_68 * V_69 ;
struct V_57 * V_58 ;
char V_70 [ V_71 ] ;
struct V_7 * V_72 ;
struct V_73 * V_74 ;
char * V_32 ;
int V_60 ;
V_72 = F_13 ( sizeof( * V_72 ) , V_30 ) ;
if ( ! V_72 ) {
F_14 ( L_5 ) ;
return;
}
V_60 = F_12 ( V_63 , V_72 ) ;
if ( V_60 < 0 )
goto V_75;
V_32 = L_6 ;
V_60 = snprintf ( V_70 , V_71 ,
L_7 , V_64 ) ;
F_20 ( V_60 >= V_71 ,
L_8 , V_64 ) ;
V_66 = F_21 ( V_70 ) ;
if ( ! V_66 ) {
F_14 ( L_9 , V_70 ) ;
goto V_76;
}
V_67 [ 0 ] = V_66 ;
if ( V_66 -> V_77 != NULL ) {
V_74 = V_66 -> V_77 ;
V_72 -> V_78 = V_74 -> V_79 ;
if ( V_63 -> V_55 )
V_72 -> V_78 &=
~ V_80 ;
}
V_58 = F_22 ( V_32 , V_64 - 1 ) ;
if ( ! V_58 ) {
F_14 ( L_10 , V_32 ) ;
goto V_76;
}
F_23 ( & V_58 -> V_2 , L_11 , V_58 -> V_32 , V_58 -> V_81 ) ;
V_69 = F_24 ( V_58 , V_67 , 1 ) ;
if ( F_25 ( V_69 ) ) {
F_14 ( L_12 , V_32 ) ;
goto V_82;
}
V_60 = F_26 ( V_58 , V_72 ,
sizeof( struct V_7 ) ) ;
if ( V_60 ) {
F_14 ( L_13 , V_32 ) ;
goto V_82;
}
V_63 -> V_58 = V_58 ;
if ( V_63 -> V_62 )
goto V_75;
V_60 = F_18 ( V_58 ) ;
if ( V_60 ) {
F_14 ( L_14 , V_32 ) ;
goto V_83;
}
goto V_75;
V_83:
F_27 ( V_69 ) ;
V_82:
F_28 ( V_58 ) ;
V_76:
F_15 ( V_72 -> V_32 ) ;
V_75:
F_15 ( V_72 ) ;
}
void T_2 F_29 ( struct V_26 * V_84 )
{
if ( V_61 )
return;
V_61 = 1 ;
if ( F_2 () ) {
V_17 = V_85 ;
V_24 = V_11 ;
} else {
V_17 = V_86 ;
V_24 = V_87 ;
}
for (; V_84 -> V_8 ; V_84 ++ )
F_19 ( V_84 , V_84 -> V_8 ) ;
}
