static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
if ( V_2 -> V_8 != 0 ) {
F_2 ( V_3 -> V_2 ,
L_1 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_2 -> V_8 & ( 1 << V_7 ) ) {
V_6 = & V_2 -> V_6 [ V_7 ] . V_6 ;
F_3 ( V_6 ) ;
if ( ! V_2 -> V_8 )
break;
}
}
}
}
static struct V_5 * F_4 ( struct V_10 * V_11 ,
struct V_12 * V_13 , T_1 V_14 )
{
struct V_1 * V_2 = F_5 ( V_11 ,
struct V_1 , V_2 ) ;
struct V_15 * V_16 = NULL ;
struct V_5 * V_6 = NULL ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( ! ( V_2 -> V_8 & ( 1 << V_7 ) ) ) {
V_2 -> V_8 |= ( 1 << V_7 ) ;
V_16 = & ( V_2 -> V_6 [ V_7 ] ) ;
V_16 -> V_2 = V_2 ;
V_16 -> V_17 = V_7 ;
V_16 -> V_18 = V_13 -> V_18 ;
V_16 -> V_14 = V_14 ;
V_6 = & ( V_16 -> V_6 ) ;
V_6 -> V_4 = V_16 ;
V_6 -> V_19 = V_20 ;
V_6 -> V_21 = 0x100000 ;
V_6 -> V_22 = V_14 ;
V_6 -> V_23 = 0 ;
break;
}
}
return V_6 ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_4 ;
V_6 -> V_23 = 0 ;
V_16 -> V_24 = 0 ;
V_16 -> V_25 = 0 ;
V_16 -> V_2 -> V_8 &=
~ ( 1 << V_16 -> V_17 ) ;
V_6 -> V_19 = V_26 ;
}
static void F_6 ( struct V_5 * V_6 ,
T_2 V_27 , T_1 V_28 ,
T_3 V_29 , T_4 V_25 )
{
struct V_15 * V_16 = V_6 -> V_4 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_3 = V_2 -> V_4 ;
void T_5 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_16 -> V_17 ;
T_2 V_33 = 0 ;
F_7 ( V_3 -> V_2 , L_2 ,
V_6 , V_27 , V_29 , V_25 , V_28 ) ;
if ( V_28 ) {
V_33 |= 1 << V_34 ;
F_8 ( V_25 < V_27 ) ;
}
V_33 |= V_35
<< V_36 ;
V_33 |= ( V_16 -> V_18 << V_37 )
| ( 1 << V_38 )
| ( 1 << V_39 )
| ( V_16 -> V_14
? ( 1 << V_40 )
: 0 ) ;
F_9 ( V_30 , V_32 , V_29 ) ;
F_10 ( V_30 , V_32 , V_25 ) ;
F_11 ( V_30 ,
F_12 ( V_32 , V_41 ) ,
V_33 ) ;
}
static int F_13 ( struct V_5 * V_6 ,
T_2 V_27 , T_1 V_28 ,
T_3 V_29 , T_4 V_25 )
{
struct V_15 * V_16 = V_6 -> V_4 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_3 = V_2 -> V_4 ;
F_7 ( V_3 -> V_2 , L_3 ,
V_16 -> V_18 ,
V_16 -> V_14 ? L_4 : L_5 ,
V_27 , V_29 , V_25 , V_28 ) ;
F_8 ( V_6 -> V_19 == V_26 ||
V_6 -> V_19 == V_42 ) ;
if ( V_3 -> V_43 -> V_44 ) {
int V_45 = V_3 -> V_43 -> V_44 ( V_6 ,
V_27 , & V_28 , & V_29 , & V_25 ) ;
if ( V_45 )
return V_45 ;
}
if ( ( V_3 -> V_46 >= V_47 ) && ( V_29 % 4 ) )
return false ;
V_6 -> V_23 = 0 ;
V_16 -> V_24 = V_29 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_48 = V_27 ;
V_6 -> V_19 = V_42 ;
F_6 ( V_6 , V_27 , V_28 , V_29 , V_25 ) ;
return true ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_4 ;
void T_5 * V_30 = V_16 -> V_2 -> V_31 ;
struct V_3 * V_3 = V_16 -> V_2 -> V_4 ;
T_1 V_32 = V_16 -> V_17 ;
int V_49 ;
T_2 V_33 ;
if ( V_6 -> V_19 == V_42 ) {
if ( V_16 -> V_14 ) {
V_49 = V_3 -> V_50 . V_51 ( V_16 -> V_18 ,
V_52 ) ;
V_33 = F_15 ( V_30 , V_49 ) ;
V_33 &= ~ ( V_53 | V_54 ) ;
F_11 ( V_30 , V_49 , V_33 ) ;
V_33 &= ~ V_55 ;
F_11 ( V_30 , V_49 , V_33 ) ;
} else {
V_49 = V_3 -> V_50 . V_51 ( V_16 -> V_18 ,
V_56 ) ;
V_33 = F_15 ( V_30 , V_49 ) ;
V_33 &= ~ ( V_57 |
V_58 |
V_59 ) ;
F_11 ( V_30 , V_49 , V_33 ) ;
}
F_11 ( V_30 ,
F_12 ( V_32 , V_41 ) ,
0 ) ;
F_9 ( V_30 , V_32 , 0 ) ;
F_10 ( V_30 , V_32 , 0 ) ;
V_6 -> V_19 = V_20 ;
}
return 0 ;
}
static T_6 F_16 ( int V_60 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_15 * V_16 ;
struct V_5 * V_6 ;
void T_5 * V_30 = V_2 -> V_31 ;
T_6 V_61 = V_62 ;
unsigned long V_63 ;
T_1 V_32 ;
T_1 V_64 ;
T_4 V_65 , V_66 ;
T_2 V_33 ;
F_17 ( & V_3 -> V_67 , V_63 ) ;
V_64 = F_18 ( V_30 , V_68 ) ;
#ifdef F_19
F_20 ( V_30 , V_68 , V_64 ) ;
#endif
if ( ! V_64 ) {
F_7 ( V_3 -> V_2 , L_6 ) ;
for ( V_32 = 0 ; V_32 < V_9 ; V_32 ++ ) {
V_16 = (struct V_15 * )
& ( V_2 -> V_6 [ V_32 ] ) ;
V_6 = & V_16 -> V_6 ;
if ( V_6 -> V_19 == V_42 ) {
V_66 = F_21 ( V_30 , V_32 ) ;
if ( V_66 == 0 )
V_64 |= ( 1 << V_32 ) ;
}
}
F_7 ( V_3 -> V_2 , L_7 , V_64 ) ;
if ( ! V_64 )
goto V_69;
}
for ( V_32 = 0 ; V_32 < V_9 ; V_32 ++ ) {
if ( V_64 & ( 1 << V_32 ) ) {
V_16 = (struct V_15 * )
& ( V_2 -> V_6 [ V_32 ] ) ;
V_6 = & V_16 -> V_6 ;
V_33 = F_15 ( V_30 ,
F_12 ( V_32 ,
V_41 ) ) ;
if ( V_33 & ( 1 << V_70 ) ) {
V_16 -> V_6 . V_19 =
V_71 ;
} else {
T_1 V_72 ;
V_65 = F_22 ( V_30 ,
V_32 ) ;
V_6 -> V_23 = V_65
- V_16 -> V_24 ;
F_7 ( V_3 -> V_2 , L_8 ,
V_6 , V_16 -> V_24 ,
V_65 , V_6 -> V_23 ,
V_16 -> V_25 ,
( V_6 -> V_23
< V_16 -> V_25 ) ?
L_9 : L_10 ) ;
V_72 = F_18 ( V_30 , V_73 ) ;
V_6 -> V_19 = V_20 ;
if ( ( V_72 & V_74 )
&& ( V_16 -> V_14 )
&& ( ( V_6 -> V_22 == 0 )
|| ( V_6 -> V_23 &
( V_16 -> V_48 - 1 ) ) )
) {
T_1 V_18 = V_16 -> V_18 ;
int V_49 = V_3 -> V_50 . V_51 ( V_18 ,
V_52 ) ;
T_2 V_75 ;
F_23 ( V_30 , V_18 ) ;
V_75 = F_15 ( V_30 , V_49 ) ;
V_75 &= ~ ( V_54
| V_53 ) ;
F_11 ( V_30 , V_49 , V_75 ) ;
V_75 &= ~ V_55 ;
V_75 |= V_76 ;
F_11 ( V_30 , V_49 , V_75 ) ;
}
F_24 ( V_3 , V_16 -> V_18 ,
V_16 -> V_14 ) ;
}
}
}
V_61 = V_77 ;
V_69:
F_25 ( & V_3 -> V_67 , V_63 ) ;
return V_61 ;
}
void F_26 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 ,
struct V_1 , V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_60 )
F_27 ( V_2 -> V_60 , V_11 ) ;
F_28 ( V_2 ) ;
}
struct V_10 * F_29 ( struct V_3 * V_3 , void T_5 * V_31 )
{
struct V_1 * V_2 ;
struct V_78 * V_79 = V_3 -> V_2 ;
struct V_80 * V_81 = F_30 ( V_79 ) ;
int V_60 = F_31 ( V_81 , L_11 ) ;
if ( V_60 <= 0 ) {
F_2 ( V_79 , L_12 ) ;
return NULL ;
}
V_2 = F_32 ( sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_83 = V_9 ;
V_2 -> V_4 = V_3 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_2 . V_84 = F_4 ;
V_2 -> V_2 . V_85 = F_3 ;
V_2 -> V_2 . V_86 = F_13 ;
V_2 -> V_2 . V_87 = F_14 ;
if ( F_33 ( V_60 , F_16 , 0 ,
F_34 ( V_3 -> V_2 ) , & V_2 -> V_2 ) ) {
F_2 ( V_79 , L_13 , V_60 ) ;
F_26 ( & V_2 -> V_2 ) ;
return NULL ;
}
V_2 -> V_60 = V_60 ;
return & V_2 -> V_2 ;
}
