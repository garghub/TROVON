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
static inline void F_12 ( struct V_7
* V_26 , int V_27 )
{
if ( F_13 ( V_26 -> V_28 ) &&
( V_26 -> V_28 < V_29 ) )
F_14 ( V_26 -> V_28 ,
V_30 ) ;
if ( F_13 ( V_26 -> V_31 ) &&
( V_26 -> V_31 < V_29 ) )
F_14 ( V_26 -> V_31 ,
V_30 ) ;
if ( F_15 () ) {
if ( V_27 == 0 ) {
F_16 ( L_1 ,
V_30 ) ;
F_16 ( L_2 ,
V_30 ) ;
F_16 ( L_3 ,
V_30 ) ;
if ( V_26 -> V_32 &
( V_33 | V_34 ) ) {
F_16 ( L_4 ,
V_30 ) ;
F_16 ( L_5 ,
V_30 ) ;
F_16 ( L_6 ,
V_30 ) ;
}
if ( V_26 -> V_32 &
V_34 ) {
F_16 ( L_7 ,
V_30 ) ;
F_16 ( L_8 ,
V_30 ) ;
F_16 ( L_9 ,
V_30 ) ;
F_16 ( L_10 ,
V_30 ) ;
}
}
if ( V_27 == 1 ) {
F_16 ( L_11 ,
V_30 ) ;
F_16 ( L_12 ,
V_30 ) ;
F_16 ( L_13 ,
V_30 ) ;
if ( V_26 -> V_32 &
( V_33 | V_34 ) ) {
F_16 ( L_14 ,
V_30 ) ;
F_16 ( L_15 ,
V_30 ) ;
F_16 ( L_16 ,
V_30 ) ;
}
if ( V_26 -> V_32 &
V_34 ) {
F_16 ( L_17 ,
V_30 ) ;
F_16 ( L_18 ,
V_30 ) ;
F_16 ( L_19 ,
V_30 ) ;
F_16 ( L_20 ,
V_30 ) ;
}
}
}
}
static int T_2 F_17 ( struct V_35 * V_36 ,
struct V_7 * V_8 )
{
char * V_37 ;
V_37 = F_18 ( sizeof( char ) * ( V_38 + 1 ) , V_39 ) ;
if ( ! V_37 ) {
F_19 ( L_21 ) ;
F_20 ( V_37 ) ;
return - V_40 ;
}
if ( V_36 -> V_41 )
strncpy ( V_37 , V_36 -> V_41 , V_38 ) ;
else
snprintf ( V_37 , ( V_38 + 1 ) , L_22 ,
V_36 -> V_8 , 1 ) ;
V_8 -> V_41 = V_37 ;
V_8 -> V_32 = V_36 -> V_32 ;
V_8 -> V_14 = ! V_36 -> V_42 ;
V_8 -> V_43 = 0 ;
V_8 -> V_28 = V_36 -> V_44 ;
V_8 -> V_31 = V_36 -> V_31 ;
V_8 -> V_10 = V_36 -> V_10 ;
V_8 -> V_45 = V_36 -> V_45 ;
if ( V_36 -> V_46 )
V_8 -> V_47 = 1 ;
if ( V_36 -> V_48 )
V_8 -> V_48 = 1 ;
if ( F_21 () )
V_8 -> V_49 = V_22 |
V_50 |
V_51 |
V_52 |
V_12 |
V_53 ;
else
V_8 -> V_49 = V_36 -> V_49 ;
if ( ! F_21 () )
V_8 -> V_54 |= V_55 ;
switch ( V_36 -> V_8 ) {
case 1 :
if ( V_8 -> V_54 & V_55 ) {
V_8 -> V_56 =
F_1 ;
V_8 -> V_57 =
F_6 ;
}
if ( F_21 () )
V_8 -> V_58 = F_11 ;
if ( F_5 () &&
( V_36 -> V_32 & V_34 ) ) {
V_36 -> V_32 &= ~ V_34 ;
V_36 -> V_32 |= V_33 ;
V_8 -> V_32 = V_36 -> V_32 ;
}
break;
case 2 :
if ( F_21 () )
V_8 -> V_58 = F_10 ;
if ( V_36 -> V_42 )
V_36 -> V_59 = 1 ;
if ( V_36 -> V_59 && ( V_36 -> V_32 & V_34 ) ) {
V_36 -> V_32 &= ~ V_34 ;
V_36 -> V_32 |= V_33 ;
}
if ( V_8 -> V_54 & V_55 ) {
V_8 -> V_56 = F_9 ;
V_8 -> V_57 = NULL ;
}
break;
case 3 :
case 4 :
case 5 :
V_8 -> V_56 = NULL ;
V_8 -> V_57 = NULL ;
break;
default:
F_19 ( L_23 , V_36 -> V_8 ) ;
F_20 ( V_37 ) ;
return - V_60 ;
}
return 0 ;
}
void F_22 ( struct V_35 * V_36 )
{
struct V_61 * V_62 ;
struct V_7 * V_63 ;
int V_64 ;
if ( V_65 != 1 )
return;
V_65 ++ ;
for (; V_36 -> V_8 ; V_36 ++ ) {
if ( ! V_36 -> V_66 )
continue;
V_62 = V_36 -> V_62 ;
if ( ! V_62 )
continue;
V_63 = V_62 -> V_2 . V_9 ;
if ( ! V_63 )
continue;
V_63 -> V_28 = V_36 -> V_44 ;
V_63 -> V_31 = V_36 -> V_31 ;
V_64 = F_23 ( V_62 ) ;
if ( V_64 )
F_19 ( L_24 ,
V_36 -> V_41 ) ;
}
}
static void T_2 F_24 ( struct V_35 * V_67 ,
int V_68 )
{
struct V_69 * V_70 ;
struct V_69 * V_71 [ 1 ] ;
struct V_72 * V_73 ;
struct V_61 * V_62 ;
char V_74 [ V_75 ] ;
struct V_7 * V_76 ;
struct V_77 * V_78 ;
char * V_41 ;
int V_64 ;
V_76 = F_18 ( sizeof( * V_76 ) , V_39 ) ;
if ( ! V_76 ) {
F_19 ( L_25 ) ;
return;
}
V_64 = F_17 ( V_67 , V_76 ) ;
if ( V_64 < 0 )
goto V_79;
F_12 ( V_76 , ( V_68 - 1 ) ) ;
V_41 = L_26 ;
V_64 = snprintf ( V_74 , V_75 ,
L_27 , V_68 ) ;
F_25 ( V_64 >= V_75 ,
L_28 , V_68 ) ;
V_70 = F_26 ( V_74 ) ;
if ( ! V_70 ) {
F_19 ( L_29 , V_74 ) ;
goto V_80;
}
V_71 [ 0 ] = V_70 ;
if ( V_70 -> V_81 != NULL ) {
V_78 = V_70 -> V_81 ;
V_76 -> V_82 = V_78 -> V_83 ;
if ( V_67 -> V_59 )
V_76 -> V_82 &=
~ V_84 ;
}
V_62 = F_27 ( V_41 , V_68 - 1 ) ;
if ( ! V_62 ) {
F_19 ( L_30 , V_41 ) ;
goto V_80;
}
F_28 ( & V_62 -> V_2 , L_31 , V_62 -> V_41 , V_62 -> V_85 ) ;
V_73 = F_29 ( V_62 , V_71 , 1 ) ;
if ( F_30 ( V_73 ) ) {
F_19 ( L_32 , V_41 ) ;
goto V_86;
}
V_64 = F_31 ( V_62 , V_76 ,
sizeof( struct V_7 ) ) ;
if ( V_64 ) {
F_19 ( L_33 , V_41 ) ;
goto V_86;
}
V_67 -> V_62 = V_62 ;
if ( V_67 -> V_66 )
goto V_79;
V_64 = F_23 ( V_62 ) ;
if ( V_64 ) {
F_19 ( L_34 , V_41 ) ;
goto V_87;
}
goto V_79;
V_87:
F_32 ( V_73 ) ;
V_86:
F_33 ( V_62 ) ;
V_80:
F_20 ( V_76 -> V_41 ) ;
V_79:
F_20 ( V_76 ) ;
}
void T_2 F_34 ( struct V_35 * V_88 )
{
if ( V_65 )
return;
V_65 = 1 ;
if ( F_2 () ) {
V_17 = V_89 ;
V_24 = V_11 ;
} else {
V_17 = V_90 ;
V_24 = V_91 ;
}
for (; V_88 -> V_8 ; V_88 ++ )
F_24 ( V_88 , V_88 -> V_8 ) ;
}
