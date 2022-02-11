static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
T_1 V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_11 [ 0 ] . V_12 )
V_9 -> V_11 [ 0 ] . V_12 ( V_2 , V_3 , V_4 ) ;
if ( V_4 ) {
if ( F_4 () ) {
V_6 = F_5 ( V_13 ) ;
if ( ( 1 << V_5 ) >= V_14 )
V_6 |= V_15 ;
else
V_6 &= ~ V_15 ;
F_6 ( V_6 , V_13 ) ;
}
if ( V_9 -> V_11 [ 0 ] . V_16 ) {
V_6 = F_5 ( V_17 ) ;
V_6 |= V_18 ;
F_6 ( V_6 , V_17 ) ;
}
V_6 = F_5 ( V_19 ) ;
if ( F_7 () ) {
V_7 = F_5 ( V_20 ) ;
V_7 |= V_21 ;
F_6 ( V_7 , V_20 ) ;
} else {
V_6 |= V_22 ;
}
V_6 &= ~ V_23 ;
F_6 ( V_6 , V_19 ) ;
} else {
V_6 = F_5 ( V_19 ) ;
V_6 &= ~ V_23 ;
F_6 ( V_6 , V_19 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
T_1 V_6 ;
F_9 ( 100 ) ;
if ( V_4 ) {
V_6 = F_5 ( V_19 ) ;
V_6 |= ( V_23 | V_22 ) ;
if ( ( 1 << V_5 ) <= V_24 )
V_6 &= ~ V_25 ;
else
V_6 |= V_25 ;
F_6 ( V_6 , V_19 ) ;
} else {
V_6 = F_5 ( V_19 ) ;
V_6 |= ( V_22 | V_23 |
V_25 ) ;
F_6 ( V_6 , V_19 ) ;
}
}
static void F_10 ( struct V_8 * V_9 )
{
T_1 V_6 ;
V_6 = F_5 ( V_26 ) ;
if ( V_9 -> V_11 [ 0 ] . V_16 )
V_6 |= V_27 ;
else
V_6 &= ~ V_27 ;
F_6 ( V_6 , V_26 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_11 [ 0 ] . V_12 )
V_9 -> V_11 [ 0 ] . V_12 ( V_2 , V_3 , V_4 ) ;
if ( V_4 )
F_10 ( V_9 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_4 )
F_10 ( V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 , int V_4 ,
int V_5 )
{
return 0 ;
}
static inline void F_14 ( struct V_8 * V_28 ,
int V_29 )
{
if ( F_15 ( V_28 -> V_11 [ 0 ] . V_30 ) &&
( V_28 -> V_11 [ 0 ] . V_30 < V_31 ) )
F_16 ( V_28 -> V_11 [ 0 ] . V_30 ,
V_32 ) ;
if ( F_15 ( V_28 -> V_11 [ 0 ] . V_33 ) &&
( V_28 -> V_11 [ 0 ] . V_33 < V_31 ) )
F_16 ( V_28 -> V_11 [ 0 ] . V_33 ,
V_32 ) ;
if ( F_17 () ) {
if ( V_29 == 0 ) {
F_18 ( L_1 ,
V_32 ) ;
F_18 ( L_2 ,
V_32 ) ;
F_18 ( L_3 ,
V_32 ) ;
if ( V_28 -> V_11 [ 0 ] . V_34 &
( V_35 | V_36 ) ) {
F_18 ( L_4 ,
V_32 ) ;
F_18 ( L_5 ,
V_32 ) ;
F_18 ( L_6 ,
V_32 ) ;
}
if ( V_28 -> V_11 [ 0 ] . V_34 &
V_36 ) {
F_18 ( L_7 ,
V_32 ) ;
F_18 ( L_8 ,
V_32 ) ;
F_18 ( L_9 ,
V_32 ) ;
F_18 ( L_10 ,
V_32 ) ;
}
}
if ( V_29 == 1 ) {
F_18 ( L_11 ,
V_32 ) ;
F_18 ( L_12 ,
V_32 ) ;
F_18 ( L_13 ,
V_32 ) ;
if ( V_28 -> V_11 [ 0 ] . V_34 &
( V_35 | V_36 ) ) {
F_18 ( L_14 ,
V_32 ) ;
F_18 ( L_15 ,
V_32 ) ;
F_18 ( L_16 ,
V_32 ) ;
}
if ( V_28 -> V_11 [ 0 ] . V_34 &
V_36 ) {
F_18 ( L_17 ,
V_32 ) ;
F_18 ( L_18 ,
V_32 ) ;
F_18 ( L_19 ,
V_32 ) ;
F_18 ( L_20 ,
V_32 ) ;
}
}
}
}
static int T_2 F_19 ( struct V_37 * V_38 ,
struct V_8 * V_9 )
{
char * V_39 ;
V_39 = F_20 ( sizeof( char ) * ( V_40 + 1 ) , V_41 ) ;
if ( ! V_39 ) {
F_21 ( L_21 ) ;
F_22 ( V_39 ) ;
return - V_42 ;
}
if ( V_38 -> V_43 )
strncpy ( V_39 , V_38 -> V_43 , V_40 ) ;
else
snprintf ( V_39 , ( V_40 + 1 ) , L_22 ,
V_38 -> V_9 , 1 ) ;
V_9 -> V_11 [ 0 ] . V_43 = V_39 ;
V_9 -> V_44 = 1 ;
V_9 -> V_11 [ 0 ] . V_34 = V_38 -> V_34 ;
V_9 -> V_11 [ 0 ] . V_45 = V_38 -> V_45 ;
V_9 -> V_11 [ 0 ] . V_16 = ! V_38 -> V_46 ;
V_9 -> V_47 = V_38 -> V_47 ;
V_9 -> V_48 = 0 ;
V_9 -> V_49 = F_1 ;
V_9 -> V_11 [ 0 ] . V_30 = V_38 -> V_50 ;
V_9 -> V_11 [ 0 ] . V_33 = V_38 -> V_33 ;
V_9 -> V_11 [ 0 ] . V_12 = V_38 -> V_12 ;
V_9 -> V_11 [ 0 ] . V_51 = V_38 -> V_51 ;
if ( V_38 -> V_52 )
V_9 -> V_11 [ 0 ] . V_53 = 1 ;
if ( V_38 -> V_54 )
V_9 -> V_11 [ 0 ] . V_54 = 1 ;
if ( V_38 -> V_55 )
V_9 -> V_11 [ 0 ] . V_55 = 1 ;
if ( V_38 -> V_56 )
V_9 -> V_11 [ 0 ] . V_56 = 1 ;
if ( V_38 -> V_57 )
V_9 -> V_11 [ 0 ] . V_58 = V_38 -> V_57 ;
if ( V_38 -> V_59 )
V_9 -> V_11 [ 0 ] . V_59 = 1 ;
if ( F_23 () )
V_9 -> V_11 [ 0 ] . V_60 = V_24 |
V_61 |
V_62 |
V_63 |
V_14 |
V_64 ;
else
V_9 -> V_11 [ 0 ] . V_60 = V_38 -> V_60 ;
if ( ! F_23 () )
V_9 -> V_11 [ 0 ] . V_65 |= V_66 ;
switch ( V_38 -> V_9 ) {
case 1 :
if ( V_9 -> V_11 [ 0 ] . V_65 & V_66 ) {
V_9 -> V_11 [ 0 ] . V_67 =
F_3 ;
V_9 -> V_11 [ 0 ] . V_68 =
F_8 ;
}
if ( F_23 () )
V_9 -> V_11 [ 0 ] . V_69 = F_13 ;
if ( F_7 () &&
( V_38 -> V_34 & V_36 ) ) {
V_38 -> V_34 &= ~ V_36 ;
V_38 -> V_34 |= V_35 ;
V_9 -> V_11 [ 0 ] . V_34 = V_38 -> V_34 ;
}
break;
case 2 :
if ( F_23 () )
V_9 -> V_11 [ 0 ] . V_69 = F_12 ;
if ( V_38 -> V_46 )
V_38 -> V_70 = 1 ;
if ( V_38 -> V_70 && ( V_38 -> V_34 & V_36 ) ) {
V_38 -> V_34 &= ~ V_36 ;
V_38 -> V_34 |= V_35 ;
}
if ( V_9 -> V_11 [ 0 ] . V_65 & V_66 ) {
V_9 -> V_11 [ 0 ] . V_67 = F_11 ;
V_9 -> V_11 [ 0 ] . V_68 = NULL ;
}
break;
case 3 :
case 4 :
case 5 :
V_9 -> V_11 [ 0 ] . V_67 = NULL ;
V_9 -> V_11 [ 0 ] . V_68 = NULL ;
break;
default:
F_21 ( L_23 , V_38 -> V_9 ) ;
F_22 ( V_39 ) ;
return - V_71 ;
}
return 0 ;
}
void F_24 ( struct V_37 * V_38 )
{
struct V_72 * V_73 ;
struct V_8 * V_74 ;
int V_75 ;
if ( V_76 != 1 )
return;
V_76 ++ ;
for (; V_38 -> V_9 ; V_38 ++ ) {
if ( ! V_38 -> V_77 )
continue;
V_73 = V_38 -> V_73 ;
if ( ! V_73 )
continue;
V_74 = V_73 -> V_2 . V_10 ;
if ( ! V_74 )
continue;
V_74 -> V_11 [ 0 ] . V_30 = V_38 -> V_50 ;
V_74 -> V_11 [ 0 ] . V_33 = V_38 -> V_33 ;
V_75 = F_25 ( V_73 ) ;
if ( V_75 )
F_21 ( L_24 ,
V_38 -> V_43 ) ;
}
}
static void T_2 F_26 ( struct V_37 * V_78 ,
int V_79 )
{
struct V_80 * V_81 ;
struct V_80 * V_82 [ 1 ] ;
struct V_83 * V_84 ;
struct V_72 * V_73 ;
char V_85 [ V_86 ] ;
struct V_8 * V_87 ;
struct V_88 * V_89 ;
char * V_43 ;
int V_75 ;
V_87 = F_20 ( sizeof( struct V_8 ) , V_41 ) ;
if ( ! V_87 ) {
F_21 ( L_25 ) ;
return;
}
V_75 = F_19 ( V_78 , V_87 ) ;
if ( V_75 < 0 )
goto V_90;
F_14 ( V_87 , ( V_79 - 1 ) ) ;
V_43 = L_26 ;
V_75 = snprintf ( V_85 , V_86 ,
L_27 , V_79 ) ;
F_27 ( V_75 >= V_86 ,
L_28 , V_79 ) ;
V_81 = F_28 ( V_85 ) ;
if ( ! V_81 ) {
F_21 ( L_29 , V_85 ) ;
goto V_91;
}
V_82 [ 0 ] = V_81 ;
if ( V_81 -> V_92 != NULL ) {
V_89 = V_81 -> V_92 ;
V_87 -> V_93 = V_89 -> V_94 ;
if ( V_78 -> V_70 )
V_87 -> V_93 &=
~ V_95 ;
}
V_73 = F_29 ( V_43 , V_79 - 1 ) ;
if ( ! V_73 ) {
F_21 ( L_30 , V_43 ) ;
goto V_91;
}
F_30 ( & V_73 -> V_2 , L_31 , V_73 -> V_43 , V_73 -> V_96 ) ;
V_84 = F_31 ( V_73 , V_82 , 1 ) ;
if ( F_32 ( V_84 ) ) {
F_21 ( L_32 , V_43 ) ;
goto V_97;
}
V_75 = F_33 ( V_73 , V_87 ,
sizeof( struct V_8 ) ) ;
if ( V_75 ) {
F_21 ( L_33 , V_43 ) ;
goto V_97;
}
V_78 -> V_73 = V_73 ;
if ( V_78 -> V_77 )
goto V_90;
V_75 = F_25 ( V_73 ) ;
if ( V_75 ) {
F_21 ( L_34 , V_43 ) ;
goto V_98;
}
goto V_90;
V_98:
F_34 ( V_84 ) ;
V_97:
F_35 ( V_73 ) ;
V_91:
F_22 ( V_87 -> V_11 [ 0 ] . V_43 ) ;
V_90:
F_22 ( V_87 ) ;
}
void T_2 F_36 ( struct V_37 * V_99 )
{
if ( V_76 )
return;
V_76 = 1 ;
if ( F_4 () ) {
V_19 = V_100 ;
V_26 = V_13 ;
} else {
V_19 = V_101 ;
V_26 = V_102 ;
}
for (; V_99 -> V_9 ; V_99 ++ )
F_26 ( V_99 , V_99 -> V_9 ) ;
}
