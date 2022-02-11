static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( unsigned int V_5 ,
unsigned int * V_6 ,
unsigned int * V_7 ,
struct V_1 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 -> V_11 ; V_9 ++ ) {
if ( ( V_5 >= V_8 -> V_10 -> V_12 [ V_9 ] ) &&
( V_5 <= V_8 -> V_10 -> V_13 [ V_9 ] ) ) {
* V_6 = V_9 ;
* V_7 = V_5 -
V_8 -> V_10 -> V_12 [ V_9 ] ;
return;
}
}
F_4 ( true , L_1 , V_5 ) ;
* V_6 = 0 ;
* V_7 = 0 ;
}
static int F_5 ( struct V_2 * V_4 , unsigned int V_14 )
{
T_1 V_15 ;
unsigned int V_6 , V_7 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_3 ( V_14 , & V_6 , & V_7 , V_8 ) ;
V_15 = F_6 ( V_8 -> V_16 +
F_7 ( V_6 ) ) ;
return ( V_15 >> V_7 ) & 1 ;
}
static void F_8 ( struct V_2 * V_4 , unsigned int V_14 ,
int V_17 )
{
unsigned int V_18 , V_6 , V_7 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_3 ( V_14 , & V_6 , & V_7 , V_8 ) ;
if ( V_7 >= V_19 ) {
V_7 -= V_19 ;
V_18 = F_9 ( V_6 ) ;
} else {
V_18 = F_10 ( V_6 ) ;
}
V_17 = ! ! V_17 ;
V_17 = ~ ( 1 << ( V_7 + V_19 ) ) &
( ( V_17 << V_7 ) | V_20 ) ;
F_11 ( V_17 , V_8 -> V_16 + V_18 ) ;
}
static int F_12 ( struct V_2 * V_4 , unsigned int V_14 )
{
T_1 V_21 ;
unsigned int V_6 , V_7 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_3 ( V_14 , & V_6 , & V_7 , V_8 ) ;
if ( V_6 == 0 && ( V_7 == 7 || V_7 == 8 ) )
return - V_22 ;
V_21 = F_6 ( V_8 -> V_16 + F_13 ( V_6 ) ) ;
V_21 &= ~ F_14 ( V_7 ) ;
F_11 ( V_21 , V_8 -> V_16 + F_13 ( V_6 ) ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_4 , unsigned int V_14 ,
int V_17 )
{
T_1 V_21 ;
unsigned int V_6 , V_7 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_3 ( V_14 , & V_6 , & V_7 , V_8 ) ;
V_21 = F_6 ( V_8 -> V_16 + F_13 ( V_6 ) ) ;
V_21 |= F_14 ( V_7 ) ;
F_11 ( V_21 , V_8 -> V_16 + F_13 ( V_6 ) ) ;
V_21 = F_6 ( V_8 -> V_16 + F_16 ( V_6 ) ) ;
V_21 |= F_14 ( V_7 ) ;
F_11 ( V_21 , V_8 -> V_16 + F_16 ( V_6 ) ) ;
F_8 ( V_4 , V_14 , V_17 ) ;
return 0 ;
}
static void F_17 ( struct V_23 * V_23 )
{
unsigned int V_24 , V_6 , V_7 ;
struct V_1 * V_8 =
F_1 ( F_18 ( V_23 ) ) ;
V_24 = V_23 -> V_25 ;
F_3 ( V_24 , & V_6 , & V_7 , V_8 ) ;
F_11 ( F_14 ( V_7 ) ,
V_8 -> V_16 + F_19 ( V_6 ) ) ;
}
static void F_20 ( struct V_23 * V_23 )
{
unsigned int V_24 , V_6 , V_7 ;
struct V_1 * V_8 =
F_1 ( F_18 ( V_23 ) ) ;
V_24 = V_23 -> V_25 ;
F_3 ( V_24 , & V_6 , & V_7 , V_8 ) ;
F_11 ( F_14 ( V_7 ) ,
V_8 -> V_16 + F_21 ( V_6 ) ) ;
}
static void F_22 ( struct V_23 * V_23 )
{
unsigned int V_24 , V_6 , V_7 ;
struct V_1 * V_8 =
F_1 ( F_18 ( V_23 ) ) ;
V_24 = V_23 -> V_25 ;
F_3 ( V_24 , & V_6 , & V_7 , V_8 ) ;
F_11 ( F_14 ( V_7 ) ,
V_8 -> V_16 + F_23 ( V_6 ) ) ;
}
static void F_24 ( struct V_23 * V_23 )
{
F_22 ( V_23 ) ;
F_20 ( V_23 ) ;
}
static int F_25 ( struct V_23 * V_23 , unsigned int type )
{
T_1 V_26 , V_27 , V_28 ;
unsigned int V_24 , V_6 , V_7 ;
struct V_1 * V_8 =
F_1 ( F_18 ( V_23 ) ) ;
V_24 = V_23 -> V_25 ;
F_3 ( V_24 , & V_6 , & V_7 , V_8 ) ;
V_26 = F_6 ( V_8 -> V_16 +
F_26 ( V_6 ) ) ;
V_27 = F_6 ( V_8 -> V_16 +
F_27 ( V_6 ) ) ;
V_28 = F_6 ( V_8 -> V_16 +
F_28 ( V_6 ) ) ;
switch ( type ) {
case V_29 :
V_26 |= F_14 ( V_7 ) ;
V_27 |= F_14 ( V_7 ) ;
V_28 &= ~ F_14 ( V_7 ) ;
break;
case V_30 :
V_26 |= F_14 ( V_7 ) ;
V_27 &= ~ F_14 ( V_7 ) ;
V_28 &= ~ F_14 ( V_7 ) ;
break;
case V_31 :
V_26 |= F_14 ( V_7 ) ;
V_28 |= F_14 ( V_7 ) ;
break;
case V_32 :
V_26 &= ~ F_14 ( V_7 ) ;
V_27 |= F_14 ( V_7 ) ;
break;
case V_33 :
V_26 &= ~ F_14 ( V_7 ) ;
V_27 &= ~ F_14 ( V_7 ) ;
break;
default:
return - V_22 ;
}
F_11 ( V_26 ,
V_8 -> V_16 + F_26 ( V_6 ) ) ;
F_11 ( V_27 ,
V_8 -> V_16 + F_27 ( V_6 ) ) ;
F_11 ( V_28 ,
V_8 -> V_16 + F_28 ( V_6 ) ) ;
if ( type & V_34 ) {
F_29 ( V_23 ,
& V_35 , V_36 , NULL ) ;
} else {
F_29 ( V_23 ,
& V_37 , V_38 , NULL ) ;
}
return 0 ;
}
static int F_30 ( struct V_23 * V_15 , unsigned int V_39 )
{
struct V_1 * V_8 =
F_1 ( F_18 ( V_15 ) ) ;
F_31 ( V_8 -> V_40 , V_39 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_8 ,
unsigned int V_6 ,
unsigned long V_41 )
{
unsigned int V_42 = V_8 -> V_10 -> V_12 [ V_6 ] ;
struct V_43 * V_44 = V_8 -> V_4 . V_44 ;
int V_45 ;
if ( ! V_41 )
return;
F_33 (offset, &pending, 32 ) {
unsigned int V_46 ;
V_46 = F_34 ( V_44 , V_45 + V_42 ) ;
F_35 ( V_46 ) ;
}
}
static void F_36 ( struct V_47 * V_48 )
{
T_1 V_49 , V_50 ;
unsigned int V_6 ;
struct V_1 * V_8 =
F_1 ( F_37 ( V_48 ) ) ;
struct V_51 * V_52 = F_38 ( V_48 ) ;
F_39 ( V_52 , V_48 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_10 -> V_11 ; V_6 ++ ) {
V_49 = F_6 ( V_8 -> V_16 +
F_23 ( V_6 ) ) ;
V_50 = F_6 ( V_8 -> V_16 +
F_40 ( V_6 ) ) ;
F_32 ( V_8 , V_6 , V_49 & ~ V_50 ) ;
}
F_41 ( V_52 , V_48 ) ;
}
static int T_2 F_42 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_43 ( V_54 ) ;
int V_40 = F_44 ( V_56 , 0 ) ;
struct V_23 * V_15 = F_45 ( V_40 ) ;
if ( ! F_46 ( V_15 ) )
return F_47 ( V_54 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_43 ( V_54 ) ;
int V_40 = F_44 ( V_56 , 0 ) ;
struct V_23 * V_15 = F_45 ( V_40 ) ;
if ( ! F_46 ( V_15 ) )
return F_49 ( V_54 ) ;
return 0 ;
}
static int T_2 F_50 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_43 ( V_54 ) ;
struct V_1 * V_8 = F_51 ( V_56 ) ;
F_52 ( V_8 -> V_57 ) ;
return 0 ;
}
static int T_2 F_53 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_43 ( V_54 ) ;
struct V_1 * V_8 = F_51 ( V_56 ) ;
return F_54 ( V_8 -> V_57 ) ;
}
static int F_55 ( struct V_2 * V_4 , unsigned V_45 )
{
int V_58 ;
V_58 = F_56 ( V_4 -> V_54 ) ;
return V_58 < 0 ? V_58 : 0 ;
}
static void F_57 ( struct V_2 * V_4 , unsigned V_45 )
{
F_58 ( V_4 -> V_54 ) ;
}
static int F_59 ( struct V_55 * V_56 )
{
int V_58 , V_6 ;
struct V_1 * V_8 ;
struct V_2 * V_4 ;
struct V_59 * V_60 ;
const struct V_61 * V_62 ;
V_8 = F_60 ( & V_56 -> V_54 , sizeof( * V_8 ) , V_63 ) ;
if ( ! V_8 )
return - V_64 ;
V_62 = F_61 ( V_65 , V_56 -> V_54 . V_66 ) ;
if ( ! V_62 ) {
F_62 ( & V_56 -> V_54 , L_2 ) ;
return - V_22 ;
}
V_8 -> V_10 = V_62 -> V_15 ;
F_63 ( V_56 , V_8 ) ;
V_60 = F_64 ( V_56 , V_67 , 0 ) ;
V_8 -> V_16 = F_65 ( & V_56 -> V_54 , V_60 ) ;
if ( F_66 ( V_8 -> V_16 ) )
return F_67 ( V_8 -> V_16 ) ;
V_8 -> V_40 = F_44 ( V_56 , 0 ) ;
if ( V_8 -> V_40 < 0 ) {
F_62 ( & V_56 -> V_54 , L_3 ) ;
return V_8 -> V_40 ;
}
V_4 = & V_8 -> V_4 ;
V_4 -> V_68 = V_8 -> V_10 -> V_68 ;
V_4 -> V_69 = V_70 ;
V_4 -> V_54 = & V_56 -> V_54 ;
V_4 -> V_71 = F_5 ;
V_4 -> V_72 = F_8 ;
V_4 -> V_73 = F_55 ;
V_4 -> free = F_57 ;
V_4 -> V_74 = F_12 ;
V_4 -> V_75 = F_15 ;
V_4 -> V_76 = - 1 ;
V_4 -> V_77 = V_8 -> V_10 -> V_77 ;
V_8 -> V_57 = F_68 ( & V_56 -> V_54 , NULL ) ;
if ( F_66 ( V_8 -> V_57 ) ) {
F_62 ( & V_56 -> V_54 , L_4 ) ;
return F_67 ( V_8 -> V_57 ) ;
}
V_58 = F_54 ( V_8 -> V_57 ) ;
if ( V_58 ) {
F_62 ( & V_56 -> V_54 , L_5 ) ;
return V_58 ;
}
V_58 = F_69 ( V_4 ) ;
if ( V_58 ) {
F_62 ( & V_56 -> V_54 , L_6 ) ;
goto V_78;
}
for ( V_6 = 0 ; V_6 < V_8 -> V_10 -> V_11 ; V_6 ++ )
F_11 ( V_79 , V_8 -> V_16 +
F_19 ( V_6 ) ) ;
V_58 = F_70 ( V_4 , & V_37 , 0 ,
V_38 , V_80 ) ;
if ( V_58 ) {
F_62 ( & V_56 -> V_54 , L_7 ) ;
goto V_81;
}
F_71 ( V_4 , & V_37 , V_8 -> V_40 ,
F_36 ) ;
F_72 ( & V_56 -> V_54 ) ;
F_73 ( & V_56 -> V_54 ) ;
return 0 ;
V_81:
F_74 ( V_4 ) ;
V_78:
F_52 ( V_8 -> V_57 ) ;
return V_58 ;
}
static int F_75 ( struct V_55 * V_56 )
{
struct V_1 * V_8 = F_51 ( V_56 ) ;
F_56 ( & V_56 -> V_54 ) ;
F_74 ( & V_8 -> V_4 ) ;
F_52 ( V_8 -> V_57 ) ;
F_76 ( & V_56 -> V_54 , 0 ) ;
F_77 ( & V_56 -> V_54 ) ;
return 0 ;
}
static int T_3 F_78 ( void )
{
return F_79 ( & V_82 ) ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_82 ) ;
}
