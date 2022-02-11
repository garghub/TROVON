static inline void F_1 ( unsigned int V_1 ,
unsigned int * V_2 ,
unsigned int * V_3 ,
struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 -> V_8 ; V_6 ++ ) {
if ( ( V_1 >= V_5 -> V_7 -> V_9 [ V_6 ] ) &&
( V_1 <= V_5 -> V_7 -> V_10 [ V_6 ] ) ) {
* V_2 = V_6 ;
* V_3 = V_1 -
V_5 -> V_7 -> V_9 [ V_6 ] ;
return;
}
}
F_2 ( true , L_1 , V_1 ) ;
* V_2 = 0 ;
* V_3 = 0 ;
}
static int F_3 ( struct V_11 * V_12 , unsigned int V_13 )
{
T_1 V_14 ;
unsigned int V_2 , V_3 ;
struct V_4 * V_5 = F_4 ( V_12 ) ;
F_1 ( V_13 , & V_2 , & V_3 , V_5 ) ;
V_14 = F_5 ( V_5 -> V_15 +
F_6 ( V_2 ) ) ;
return ( V_14 >> V_3 ) & 1 ;
}
static void F_7 ( struct V_11 * V_12 , unsigned int V_13 ,
int V_16 )
{
unsigned int V_17 , V_2 , V_3 ;
struct V_4 * V_5 = F_4 ( V_12 ) ;
F_1 ( V_13 , & V_2 , & V_3 , V_5 ) ;
if ( V_3 >= V_18 ) {
V_3 -= V_18 ;
V_17 = F_8 ( V_2 ) ;
} else {
V_17 = F_9 ( V_2 ) ;
}
V_16 = ! ! V_16 ;
V_16 = ~ ( 1 << ( V_3 + V_18 ) ) &
( ( V_16 << V_3 ) | V_19 ) ;
F_10 ( V_16 , V_5 -> V_15 + V_17 ) ;
}
static int F_11 ( struct V_11 * V_12 , unsigned int V_13 )
{
T_1 V_20 ;
bool V_21 ;
unsigned int V_2 , V_3 ;
struct V_4 * V_5 = F_4 ( V_12 ) ;
V_21 = V_5 -> V_7 -> V_22 & V_23 ;
F_1 ( V_13 , & V_2 , & V_3 , V_5 ) ;
if ( V_21 && V_2 == 0 &&
( V_3 == 7 || V_3 == 8 ) )
return - V_24 ;
V_20 = F_5 ( V_5 -> V_15 + F_12 ( V_2 ) ) ;
V_20 &= ~ F_13 ( V_3 ) ;
F_10 ( V_20 , V_5 -> V_15 + F_12 ( V_2 ) ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , unsigned int V_13 ,
int V_16 )
{
T_1 V_20 ;
unsigned int V_2 , V_3 ;
struct V_4 * V_5 = F_4 ( V_12 ) ;
F_1 ( V_13 , & V_2 , & V_3 , V_5 ) ;
V_20 = F_5 ( V_5 -> V_15 + F_12 ( V_2 ) ) ;
V_20 |= F_13 ( V_3 ) ;
F_10 ( V_20 , V_5 -> V_15 + F_12 ( V_2 ) ) ;
V_20 = F_5 ( V_5 -> V_15 + F_15 ( V_2 ) ) ;
V_20 |= F_13 ( V_3 ) ;
F_10 ( V_20 , V_5 -> V_15 + F_15 ( V_2 ) ) ;
F_7 ( V_12 , V_13 , V_16 ) ;
return 0 ;
}
static void F_16 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 , V_5 ) ;
F_10 ( F_13 ( V_3 ) ,
V_5 -> V_15 + F_18 ( V_2 ) ) ;
}
static void F_19 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 , V_5 ) ;
F_10 ( F_13 ( V_3 ) ,
V_5 -> V_15 + F_20 ( V_2 ) ) ;
}
static void F_21 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 , V_5 ) ;
F_10 ( F_13 ( V_3 ) ,
V_5 -> V_15 + F_22 ( V_2 ) ) ;
}
static void F_23 ( struct V_25 * V_25 )
{
F_21 ( V_25 ) ;
F_19 ( V_25 ) ;
}
static int F_24 ( struct V_25 * V_25 , unsigned int type )
{
T_1 V_28 , V_29 , V_30 ;
unsigned int V_26 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_25 ) ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 , V_5 ) ;
V_28 = F_5 ( V_5 -> V_15 +
F_25 ( V_2 ) ) ;
V_29 = F_5 ( V_5 -> V_15 +
F_26 ( V_2 ) ) ;
V_30 = F_5 ( V_5 -> V_15 +
F_27 ( V_2 ) ) ;
switch ( type ) {
case V_31 :
V_28 |= F_13 ( V_3 ) ;
V_29 |= F_13 ( V_3 ) ;
V_30 &= ~ F_13 ( V_3 ) ;
break;
case V_32 :
V_28 |= F_13 ( V_3 ) ;
V_29 &= ~ F_13 ( V_3 ) ;
V_30 &= ~ F_13 ( V_3 ) ;
break;
case V_33 :
V_28 |= F_13 ( V_3 ) ;
V_30 |= F_13 ( V_3 ) ;
break;
case V_34 :
V_28 &= ~ F_13 ( V_3 ) ;
V_29 |= F_13 ( V_3 ) ;
break;
case V_35 :
V_28 &= ~ F_13 ( V_3 ) ;
V_29 &= ~ F_13 ( V_3 ) ;
break;
default:
return - V_24 ;
}
F_10 ( V_28 ,
V_5 -> V_15 + F_25 ( V_2 ) ) ;
F_10 ( V_29 ,
V_5 -> V_15 + F_26 ( V_2 ) ) ;
F_10 ( V_30 ,
V_5 -> V_15 + F_27 ( V_2 ) ) ;
if ( type & V_36 ) {
F_28 ( V_25 ,
& V_37 , V_38 , NULL ) ;
} else {
F_28 ( V_25 ,
& V_39 , V_40 , NULL ) ;
}
return 0 ;
}
static int F_29 ( struct V_25 * V_14 , unsigned int V_41 )
{
struct V_4 * V_5 =
F_4 ( F_17 ( V_14 ) ) ;
F_30 ( V_5 -> V_42 , V_41 ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_5 ,
unsigned int V_2 ,
unsigned long V_43 )
{
unsigned int V_44 = V_5 -> V_7 -> V_9 [ V_2 ] ;
struct V_45 * V_46 = V_5 -> V_12 . V_46 ;
int V_47 ;
if ( ! V_43 )
return;
F_32 (offset, &pending, 32 ) {
unsigned int V_48 ;
V_48 = F_33 ( V_46 , V_47 + V_44 ) ;
F_34 ( V_48 ) ;
}
}
static void F_35 ( struct V_49 * V_50 )
{
T_1 V_51 , V_52 ;
unsigned int V_2 ;
struct V_4 * V_5 =
F_4 ( F_36 ( V_50 ) ) ;
struct V_53 * V_54 = F_37 ( V_50 ) ;
F_38 ( V_54 , V_50 ) ;
for ( V_2 = 0 ; V_2 < V_5 -> V_7 -> V_8 ; V_2 ++ ) {
V_51 = F_5 ( V_5 -> V_15 +
F_22 ( V_2 ) ) ;
V_52 = F_5 ( V_5 -> V_15 +
F_39 ( V_2 ) ) ;
F_31 ( V_5 , V_2 , V_51 & ~ V_52 ) ;
}
F_40 ( V_54 , V_50 ) ;
}
static int T_2 F_41 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_42 ( V_56 ) ;
int V_42 = F_43 ( V_58 , 0 ) ;
struct V_25 * V_14 = F_44 ( V_42 ) ;
if ( ! F_45 ( V_14 ) )
return F_46 ( V_56 ) ;
return 0 ;
}
static int T_2 F_47 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_42 ( V_56 ) ;
int V_42 = F_43 ( V_58 , 0 ) ;
struct V_25 * V_14 = F_44 ( V_42 ) ;
if ( ! F_45 ( V_14 ) )
return F_48 ( V_56 ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_42 ( V_56 ) ;
struct V_4 * V_5 = F_50 ( V_58 ) ;
F_51 ( V_5 -> V_59 ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_42 ( V_56 ) ;
struct V_4 * V_5 = F_50 ( V_58 ) ;
return F_53 ( V_5 -> V_59 ) ;
}
static int F_54 ( struct V_11 * V_12 , unsigned V_47 )
{
int V_60 ;
V_60 = F_55 ( V_12 -> V_61 ) ;
return V_60 < 0 ? V_60 : 0 ;
}
static void F_56 ( struct V_11 * V_12 , unsigned V_47 )
{
F_57 ( V_12 -> V_61 ) ;
}
static int F_58 ( struct V_57 * V_58 )
{
int V_60 , V_2 ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
struct V_62 * V_63 ;
const struct V_64 * V_65 ;
V_5 = F_59 ( & V_58 -> V_56 , sizeof( * V_5 ) , V_66 ) ;
if ( ! V_5 )
return - V_67 ;
V_65 = F_60 ( V_68 , V_58 -> V_56 . V_69 ) ;
if ( ! V_65 ) {
F_61 ( & V_58 -> V_56 , L_2 ) ;
return - V_24 ;
}
V_5 -> V_7 = V_65 -> V_14 ;
F_62 ( V_58 , V_5 ) ;
V_63 = F_63 ( V_58 , V_70 , 0 ) ;
V_5 -> V_15 = F_64 ( & V_58 -> V_56 , V_63 ) ;
if ( F_65 ( V_5 -> V_15 ) )
return F_66 ( V_5 -> V_15 ) ;
V_5 -> V_42 = F_43 ( V_58 , 0 ) ;
if ( V_5 -> V_42 < 0 ) {
F_61 ( & V_58 -> V_56 , L_3 ) ;
return V_5 -> V_42 ;
}
V_12 = & V_5 -> V_12 ;
V_12 -> V_71 = V_5 -> V_7 -> V_71 ;
V_12 -> V_72 = V_73 ;
V_12 -> V_61 = & V_58 -> V_56 ;
V_12 -> V_74 = F_3 ;
V_12 -> V_75 = F_7 ;
V_12 -> V_76 = F_54 ;
V_12 -> free = F_56 ;
V_12 -> V_77 = F_11 ;
V_12 -> V_78 = F_14 ;
V_12 -> V_79 = - 1 ;
V_12 -> V_80 = V_5 -> V_7 -> V_80 ;
V_5 -> V_59 = F_67 ( & V_58 -> V_56 , NULL ) ;
if ( F_65 ( V_5 -> V_59 ) ) {
F_61 ( & V_58 -> V_56 , L_4 ) ;
return F_66 ( V_5 -> V_59 ) ;
}
V_60 = F_53 ( V_5 -> V_59 ) ;
if ( V_60 ) {
F_61 ( & V_58 -> V_56 , L_5 ) ;
return V_60 ;
}
F_68 ( & V_58 -> V_56 ) ;
F_69 ( & V_58 -> V_56 ) ;
V_60 = F_55 ( & V_58 -> V_56 ) ;
if ( V_60 < 0 )
goto V_81;
V_60 = F_70 ( V_12 , V_5 ) ;
if ( V_60 ) {
F_61 ( & V_58 -> V_56 , L_6 ) ;
goto V_82;
}
for ( V_2 = 0 ; V_2 < V_5 -> V_7 -> V_8 ; V_2 ++ )
F_10 ( V_83 , V_5 -> V_15 +
F_18 ( V_2 ) ) ;
V_60 = F_71 ( V_12 , & V_39 , 0 ,
V_40 , V_84 ) ;
if ( V_60 ) {
F_61 ( & V_58 -> V_56 , L_7 ) ;
goto V_85;
}
F_72 ( V_12 , & V_39 , V_5 -> V_42 ,
F_35 ) ;
F_57 ( & V_58 -> V_56 ) ;
return 0 ;
V_85:
F_73 ( V_12 ) ;
V_82:
F_57 ( & V_58 -> V_56 ) ;
V_81:
F_74 ( & V_58 -> V_56 ) ;
F_51 ( V_5 -> V_59 ) ;
return V_60 ;
}
static int F_75 ( struct V_57 * V_58 )
{
struct V_4 * V_5 = F_50 ( V_58 ) ;
F_55 ( & V_58 -> V_56 ) ;
F_73 ( & V_5 -> V_12 ) ;
F_51 ( V_5 -> V_59 ) ;
F_76 ( & V_58 -> V_56 , 0 ) ;
F_74 ( & V_58 -> V_56 ) ;
return 0 ;
}
static int T_3 F_77 ( void )
{
return F_78 ( & V_86 ) ;
}
static void T_4 F_79 ( void )
{
F_80 ( & V_86 ) ;
}
