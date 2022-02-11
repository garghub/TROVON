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
unsigned int V_2 , V_3 ;
struct V_4 * V_5 = F_4 ( V_12 ) ;
F_1 ( V_13 , & V_2 , & V_3 , V_5 ) ;
if ( V_2 == 0 && ( V_3 == 7 || V_3 == 8 ) )
return - V_21 ;
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
static void F_16 ( struct V_22 * V_22 )
{
unsigned int V_23 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_22 ) ) ;
V_23 = V_22 -> V_24 ;
F_1 ( V_23 , & V_2 , & V_3 , V_5 ) ;
F_10 ( F_13 ( V_3 ) ,
V_5 -> V_15 + F_18 ( V_2 ) ) ;
}
static void F_19 ( struct V_22 * V_22 )
{
unsigned int V_23 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_22 ) ) ;
V_23 = V_22 -> V_24 ;
F_1 ( V_23 , & V_2 , & V_3 , V_5 ) ;
F_10 ( F_13 ( V_3 ) ,
V_5 -> V_15 + F_20 ( V_2 ) ) ;
}
static void F_21 ( struct V_22 * V_22 )
{
unsigned int V_23 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_22 ) ) ;
V_23 = V_22 -> V_24 ;
F_1 ( V_23 , & V_2 , & V_3 , V_5 ) ;
F_10 ( F_13 ( V_3 ) ,
V_5 -> V_15 + F_22 ( V_2 ) ) ;
}
static void F_23 ( struct V_22 * V_22 )
{
F_21 ( V_22 ) ;
F_19 ( V_22 ) ;
}
static int F_24 ( struct V_22 * V_22 , unsigned int type )
{
T_1 V_25 , V_26 , V_27 ;
unsigned int V_23 , V_2 , V_3 ;
struct V_4 * V_5 =
F_4 ( F_17 ( V_22 ) ) ;
V_23 = V_22 -> V_24 ;
F_1 ( V_23 , & V_2 , & V_3 , V_5 ) ;
V_25 = F_5 ( V_5 -> V_15 +
F_25 ( V_2 ) ) ;
V_26 = F_5 ( V_5 -> V_15 +
F_26 ( V_2 ) ) ;
V_27 = F_5 ( V_5 -> V_15 +
F_27 ( V_2 ) ) ;
switch ( type ) {
case V_28 :
V_25 |= F_13 ( V_3 ) ;
V_26 |= F_13 ( V_3 ) ;
V_27 &= ~ F_13 ( V_3 ) ;
break;
case V_29 :
V_25 |= F_13 ( V_3 ) ;
V_26 &= ~ F_13 ( V_3 ) ;
V_27 &= ~ F_13 ( V_3 ) ;
break;
case V_30 :
V_25 |= F_13 ( V_3 ) ;
V_27 |= F_13 ( V_3 ) ;
break;
case V_31 :
V_25 &= ~ F_13 ( V_3 ) ;
V_26 |= F_13 ( V_3 ) ;
break;
case V_32 :
V_25 &= ~ F_13 ( V_3 ) ;
V_26 &= ~ F_13 ( V_3 ) ;
break;
default:
return - V_21 ;
}
F_10 ( V_25 ,
V_5 -> V_15 + F_25 ( V_2 ) ) ;
F_10 ( V_26 ,
V_5 -> V_15 + F_26 ( V_2 ) ) ;
F_10 ( V_27 ,
V_5 -> V_15 + F_27 ( V_2 ) ) ;
if ( type & V_33 ) {
F_28 ( V_22 ,
& V_34 , V_35 , NULL ) ;
} else {
F_28 ( V_22 ,
& V_36 , V_37 , NULL ) ;
}
return 0 ;
}
static int F_29 ( struct V_22 * V_14 , unsigned int V_38 )
{
struct V_4 * V_5 =
F_4 ( F_17 ( V_14 ) ) ;
F_30 ( V_5 -> V_39 , V_38 ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_5 ,
unsigned int V_2 ,
unsigned long V_40 )
{
unsigned int V_41 = V_5 -> V_7 -> V_9 [ V_2 ] ;
struct V_42 * V_43 = V_5 -> V_12 . V_43 ;
int V_44 ;
if ( ! V_40 )
return;
F_32 (offset, &pending, 32 ) {
unsigned int V_45 ;
V_45 = F_33 ( V_43 , V_44 + V_41 ) ;
F_34 ( V_45 ) ;
}
}
static void F_35 ( struct V_46 * V_47 )
{
T_1 V_48 , V_49 ;
unsigned int V_2 ;
struct V_4 * V_5 =
F_4 ( F_36 ( V_47 ) ) ;
struct V_50 * V_51 = F_37 ( V_47 ) ;
F_38 ( V_51 , V_47 ) ;
for ( V_2 = 0 ; V_2 < V_5 -> V_7 -> V_8 ; V_2 ++ ) {
V_48 = F_5 ( V_5 -> V_15 +
F_22 ( V_2 ) ) ;
V_49 = F_5 ( V_5 -> V_15 +
F_39 ( V_2 ) ) ;
F_31 ( V_5 , V_2 , V_48 & ~ V_49 ) ;
}
F_40 ( V_51 , V_47 ) ;
}
static int T_2 F_41 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
int V_39 = F_43 ( V_55 , 0 ) ;
struct V_22 * V_14 = F_44 ( V_39 ) ;
if ( ! F_45 ( V_14 ) )
return F_46 ( V_53 ) ;
return 0 ;
}
static int T_2 F_47 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
int V_39 = F_43 ( V_55 , 0 ) ;
struct V_22 * V_14 = F_44 ( V_39 ) ;
if ( ! F_45 ( V_14 ) )
return F_48 ( V_53 ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
struct V_4 * V_5 = F_50 ( V_55 ) ;
F_51 ( V_5 -> V_56 ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
struct V_4 * V_5 = F_50 ( V_55 ) ;
return F_53 ( V_5 -> V_56 ) ;
}
static int F_54 ( struct V_11 * V_12 , unsigned V_44 )
{
int V_57 ;
V_57 = F_55 ( V_12 -> V_58 ) ;
return V_57 < 0 ? V_57 : 0 ;
}
static void F_56 ( struct V_11 * V_12 , unsigned V_44 )
{
F_57 ( V_12 -> V_58 ) ;
}
static int F_58 ( struct V_54 * V_55 )
{
int V_57 , V_2 ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
struct V_59 * V_60 ;
const struct V_61 * V_62 ;
V_5 = F_59 ( & V_55 -> V_53 , sizeof( * V_5 ) , V_63 ) ;
if ( ! V_5 )
return - V_64 ;
V_62 = F_60 ( V_65 , V_55 -> V_53 . V_66 ) ;
if ( ! V_62 ) {
F_61 ( & V_55 -> V_53 , L_2 ) ;
return - V_21 ;
}
V_5 -> V_7 = V_62 -> V_14 ;
F_62 ( V_55 , V_5 ) ;
V_60 = F_63 ( V_55 , V_67 , 0 ) ;
V_5 -> V_15 = F_64 ( & V_55 -> V_53 , V_60 ) ;
if ( F_65 ( V_5 -> V_15 ) )
return F_66 ( V_5 -> V_15 ) ;
V_5 -> V_39 = F_43 ( V_55 , 0 ) ;
if ( V_5 -> V_39 < 0 ) {
F_61 ( & V_55 -> V_53 , L_3 ) ;
return V_5 -> V_39 ;
}
V_12 = & V_5 -> V_12 ;
V_12 -> V_68 = V_5 -> V_7 -> V_68 ;
V_12 -> V_69 = V_70 ;
V_12 -> V_58 = & V_55 -> V_53 ;
V_12 -> V_71 = F_3 ;
V_12 -> V_72 = F_7 ;
V_12 -> V_73 = F_54 ;
V_12 -> free = F_56 ;
V_12 -> V_74 = F_11 ;
V_12 -> V_75 = F_14 ;
V_12 -> V_76 = - 1 ;
V_12 -> V_77 = V_5 -> V_7 -> V_77 ;
V_5 -> V_56 = F_67 ( & V_55 -> V_53 , NULL ) ;
if ( F_65 ( V_5 -> V_56 ) ) {
F_61 ( & V_55 -> V_53 , L_4 ) ;
return F_66 ( V_5 -> V_56 ) ;
}
F_68 ( & V_55 -> V_53 ) ;
V_57 = F_55 ( & V_55 -> V_53 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_69 ( V_12 , V_5 ) ;
if ( V_57 ) {
F_61 ( & V_55 -> V_53 , L_5 ) ;
goto V_78;
}
for ( V_2 = 0 ; V_2 < V_5 -> V_7 -> V_8 ; V_2 ++ )
F_10 ( V_79 , V_5 -> V_15 +
F_18 ( V_2 ) ) ;
V_57 = F_70 ( V_12 , & V_36 , 0 ,
V_37 , V_80 ) ;
if ( V_57 ) {
F_61 ( & V_55 -> V_53 , L_6 ) ;
goto V_81;
}
F_71 ( V_12 , & V_36 , V_5 -> V_39 ,
F_35 ) ;
F_57 ( & V_55 -> V_53 ) ;
return 0 ;
V_81:
F_72 ( V_12 ) ;
V_78:
F_57 ( & V_55 -> V_53 ) ;
return V_57 ;
}
static int F_73 ( struct V_54 * V_55 )
{
struct V_4 * V_5 = F_50 ( V_55 ) ;
F_55 ( & V_55 -> V_53 ) ;
F_72 ( & V_5 -> V_12 ) ;
F_51 ( V_5 -> V_56 ) ;
F_74 ( & V_55 -> V_53 , 0 ) ;
F_75 ( & V_55 -> V_53 ) ;
return 0 ;
}
static int T_3 F_76 ( void )
{
return F_77 ( & V_82 ) ;
}
static void T_4 F_78 ( void )
{
F_79 ( & V_82 ) ;
}
