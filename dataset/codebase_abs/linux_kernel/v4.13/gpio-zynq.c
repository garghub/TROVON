static int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 -> V_4 & V_5 ) ;
}
static inline void F_2 ( unsigned int V_6 ,
unsigned int * V_7 ,
unsigned int * V_8 ,
struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_3 -> V_10 ; V_9 ++ ) {
if ( ( V_6 >= V_2 -> V_3 -> V_11 [ V_9 ] ) &&
( V_6 <= V_2 -> V_3 -> V_12 [ V_9 ] ) ) {
* V_7 = V_9 ;
* V_8 = V_6 -
V_2 -> V_3 -> V_11 [ V_9 ] ;
return;
}
}
F_3 ( true , L_1 , V_6 ) ;
* V_7 = 0 ;
* V_8 = 0 ;
}
static int F_4 ( struct V_13 * V_14 , unsigned int V_15 )
{
T_1 V_16 ;
unsigned int V_7 , V_8 ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
F_2 ( V_15 , & V_7 , & V_8 , V_2 ) ;
V_16 = F_6 ( V_2 -> V_17 +
F_7 ( V_7 ) ) ;
return ( V_16 >> V_8 ) & 1 ;
}
static void F_8 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_18 )
{
unsigned int V_19 , V_7 , V_8 ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
F_2 ( V_15 , & V_7 , & V_8 , V_2 ) ;
if ( V_8 >= V_20 ) {
V_8 -= V_20 ;
V_19 = F_9 ( V_7 ) ;
} else {
V_19 = F_10 ( V_7 ) ;
}
V_18 = ! ! V_18 ;
V_18 = ~ ( 1 << ( V_8 + V_20 ) ) &
( ( V_18 << V_8 ) | V_21 ) ;
F_11 ( V_18 , V_2 -> V_17 + V_19 ) ;
}
static int F_12 ( struct V_13 * V_14 , unsigned int V_15 )
{
T_1 V_22 ;
unsigned int V_7 , V_8 ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
F_2 ( V_15 , & V_7 , & V_8 , V_2 ) ;
if ( F_1 ( V_2 ) && V_7 == 0 &&
( V_8 == 7 || V_8 == 8 ) )
return - V_23 ;
V_22 = F_6 ( V_2 -> V_17 + F_13 ( V_7 ) ) ;
V_22 &= ~ F_14 ( V_8 ) ;
F_11 ( V_22 , V_2 -> V_17 + F_13 ( V_7 ) ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_18 )
{
T_1 V_22 ;
unsigned int V_7 , V_8 ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
F_2 ( V_15 , & V_7 , & V_8 , V_2 ) ;
V_22 = F_6 ( V_2 -> V_17 + F_13 ( V_7 ) ) ;
V_22 |= F_14 ( V_8 ) ;
F_11 ( V_22 , V_2 -> V_17 + F_13 ( V_7 ) ) ;
V_22 = F_6 ( V_2 -> V_17 + F_16 ( V_7 ) ) ;
V_22 |= F_14 ( V_8 ) ;
F_11 ( V_22 , V_2 -> V_17 + F_16 ( V_7 ) ) ;
F_8 ( V_14 , V_15 , V_18 ) ;
return 0 ;
}
static void F_17 ( struct V_24 * V_24 )
{
unsigned int V_25 , V_7 , V_8 ;
struct V_1 * V_2 =
F_5 ( F_18 ( V_24 ) ) ;
V_25 = V_24 -> V_26 ;
F_2 ( V_25 , & V_7 , & V_8 , V_2 ) ;
F_11 ( F_14 ( V_8 ) ,
V_2 -> V_17 + F_19 ( V_7 ) ) ;
}
static void F_20 ( struct V_24 * V_24 )
{
unsigned int V_25 , V_7 , V_8 ;
struct V_1 * V_2 =
F_5 ( F_18 ( V_24 ) ) ;
V_25 = V_24 -> V_26 ;
F_2 ( V_25 , & V_7 , & V_8 , V_2 ) ;
F_11 ( F_14 ( V_8 ) ,
V_2 -> V_17 + F_21 ( V_7 ) ) ;
}
static void F_22 ( struct V_24 * V_24 )
{
unsigned int V_25 , V_7 , V_8 ;
struct V_1 * V_2 =
F_5 ( F_18 ( V_24 ) ) ;
V_25 = V_24 -> V_26 ;
F_2 ( V_25 , & V_7 , & V_8 , V_2 ) ;
F_11 ( F_14 ( V_8 ) ,
V_2 -> V_17 + F_23 ( V_7 ) ) ;
}
static void F_24 ( struct V_24 * V_24 )
{
F_22 ( V_24 ) ;
F_20 ( V_24 ) ;
}
static int F_25 ( struct V_24 * V_24 , unsigned int type )
{
T_1 V_27 , V_28 , V_29 ;
unsigned int V_25 , V_7 , V_8 ;
struct V_1 * V_2 =
F_5 ( F_18 ( V_24 ) ) ;
V_25 = V_24 -> V_26 ;
F_2 ( V_25 , & V_7 , & V_8 , V_2 ) ;
V_27 = F_6 ( V_2 -> V_17 +
F_26 ( V_7 ) ) ;
V_28 = F_6 ( V_2 -> V_17 +
F_27 ( V_7 ) ) ;
V_29 = F_6 ( V_2 -> V_17 +
F_28 ( V_7 ) ) ;
switch ( type ) {
case V_30 :
V_27 |= F_14 ( V_8 ) ;
V_28 |= F_14 ( V_8 ) ;
V_29 &= ~ F_14 ( V_8 ) ;
break;
case V_31 :
V_27 |= F_14 ( V_8 ) ;
V_28 &= ~ F_14 ( V_8 ) ;
V_29 &= ~ F_14 ( V_8 ) ;
break;
case V_32 :
V_27 |= F_14 ( V_8 ) ;
V_29 |= F_14 ( V_8 ) ;
break;
case V_33 :
V_27 &= ~ F_14 ( V_8 ) ;
V_28 |= F_14 ( V_8 ) ;
break;
case V_34 :
V_27 &= ~ F_14 ( V_8 ) ;
V_28 &= ~ F_14 ( V_8 ) ;
break;
default:
return - V_23 ;
}
F_11 ( V_27 ,
V_2 -> V_17 + F_26 ( V_7 ) ) ;
F_11 ( V_28 ,
V_2 -> V_17 + F_27 ( V_7 ) ) ;
F_11 ( V_29 ,
V_2 -> V_17 + F_28 ( V_7 ) ) ;
if ( type & V_35 ) {
F_29 ( V_24 ,
& V_36 , V_37 , NULL ) ;
} else {
F_29 ( V_24 ,
& V_38 , V_39 , NULL ) ;
}
return 0 ;
}
static int F_30 ( struct V_24 * V_16 , unsigned int V_40 )
{
struct V_1 * V_2 =
F_5 ( F_18 ( V_16 ) ) ;
F_31 ( V_2 -> V_41 , V_40 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned long V_42 )
{
unsigned int V_43 = V_2 -> V_3 -> V_11 [ V_7 ] ;
struct V_44 * V_45 = V_2 -> V_14 . V_45 ;
int V_46 ;
if ( ! V_42 )
return;
F_33 (offset, &pending, 32 ) {
unsigned int V_47 ;
V_47 = F_34 ( V_45 , V_46 + V_43 ) ;
F_35 ( V_47 ) ;
}
}
static void F_36 ( struct V_48 * V_49 )
{
T_1 V_50 , V_51 ;
unsigned int V_7 ;
struct V_1 * V_2 =
F_5 ( F_37 ( V_49 ) ) ;
struct V_52 * V_53 = F_38 ( V_49 ) ;
F_39 ( V_53 , V_49 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_3 -> V_10 ; V_7 ++ ) {
V_50 = F_6 ( V_2 -> V_17 +
F_23 ( V_7 ) ) ;
V_51 = F_6 ( V_2 -> V_17 +
F_40 ( V_7 ) ) ;
F_32 ( V_2 , V_7 , V_50 & ~ V_51 ) ;
}
F_41 ( V_53 , V_49 ) ;
}
static int T_2 F_42 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_43 ( V_55 ) ;
int V_41 = F_44 ( V_57 , 0 ) ;
struct V_24 * V_16 = F_45 ( V_41 ) ;
if ( ! F_46 ( V_16 ) )
return F_47 ( V_55 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_43 ( V_55 ) ;
int V_41 = F_44 ( V_57 , 0 ) ;
struct V_24 * V_16 = F_45 ( V_41 ) ;
if ( ! F_46 ( V_16 ) )
return F_49 ( V_55 ) ;
return 0 ;
}
static int T_2 F_50 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_43 ( V_55 ) ;
struct V_1 * V_2 = F_51 ( V_57 ) ;
F_52 ( V_2 -> V_58 ) ;
return 0 ;
}
static int T_2 F_53 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_43 ( V_55 ) ;
struct V_1 * V_2 = F_51 ( V_57 ) ;
return F_54 ( V_2 -> V_58 ) ;
}
static int F_55 ( struct V_13 * V_14 , unsigned V_46 )
{
int V_59 ;
V_59 = F_56 ( V_14 -> V_60 ) ;
return V_59 < 0 ? V_59 : 0 ;
}
static void F_57 ( struct V_13 * V_14 , unsigned V_46 )
{
F_58 ( V_14 -> V_60 ) ;
}
static int F_59 ( struct V_56 * V_57 )
{
int V_59 , V_7 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_61 * V_62 ;
const struct V_63 * V_64 ;
V_2 = F_60 ( & V_57 -> V_55 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_66 ;
V_64 = F_61 ( V_67 , V_57 -> V_55 . V_68 ) ;
if ( ! V_64 ) {
F_62 ( & V_57 -> V_55 , L_2 ) ;
return - V_23 ;
}
V_2 -> V_3 = V_64 -> V_16 ;
F_63 ( V_57 , V_2 ) ;
V_62 = F_64 ( V_57 , V_69 , 0 ) ;
V_2 -> V_17 = F_65 ( & V_57 -> V_55 , V_62 ) ;
if ( F_66 ( V_2 -> V_17 ) )
return F_67 ( V_2 -> V_17 ) ;
V_2 -> V_41 = F_44 ( V_57 , 0 ) ;
if ( V_2 -> V_41 < 0 ) {
F_62 ( & V_57 -> V_55 , L_3 ) ;
return V_2 -> V_41 ;
}
V_14 = & V_2 -> V_14 ;
V_14 -> V_70 = V_2 -> V_3 -> V_70 ;
V_14 -> V_71 = V_72 ;
V_14 -> V_60 = & V_57 -> V_55 ;
V_14 -> V_73 = F_4 ;
V_14 -> V_74 = F_8 ;
V_14 -> V_75 = F_55 ;
V_14 -> free = F_57 ;
V_14 -> V_76 = F_12 ;
V_14 -> V_77 = F_15 ;
V_14 -> V_78 = - 1 ;
V_14 -> V_79 = V_2 -> V_3 -> V_79 ;
V_2 -> V_58 = F_68 ( & V_57 -> V_55 , NULL ) ;
if ( F_66 ( V_2 -> V_58 ) ) {
F_62 ( & V_57 -> V_55 , L_4 ) ;
return F_67 ( V_2 -> V_58 ) ;
}
V_59 = F_54 ( V_2 -> V_58 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_5 ) ;
return V_59 ;
}
F_69 ( & V_57 -> V_55 ) ;
F_70 ( & V_57 -> V_55 ) ;
V_59 = F_56 ( & V_57 -> V_55 ) ;
if ( V_59 < 0 )
goto V_80;
V_59 = F_71 ( V_14 , V_2 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_6 ) ;
goto V_81;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_3 -> V_10 ; V_7 ++ )
F_11 ( V_82 , V_2 -> V_17 +
F_19 ( V_7 ) ) ;
V_59 = F_72 ( V_14 , & V_38 , 0 ,
V_39 , V_83 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_7 ) ;
goto V_84;
}
F_73 ( V_14 , & V_38 , V_2 -> V_41 ,
F_36 ) ;
F_58 ( & V_57 -> V_55 ) ;
return 0 ;
V_84:
F_74 ( V_14 ) ;
V_81:
F_58 ( & V_57 -> V_55 ) ;
V_80:
F_75 ( & V_57 -> V_55 ) ;
F_52 ( V_2 -> V_58 ) ;
return V_59 ;
}
static int F_76 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_51 ( V_57 ) ;
F_56 ( & V_57 -> V_55 ) ;
F_74 ( & V_2 -> V_14 ) ;
F_52 ( V_2 -> V_58 ) ;
F_77 ( & V_57 -> V_55 , 0 ) ;
F_75 ( & V_57 -> V_55 ) ;
return 0 ;
}
static int T_3 F_78 ( void )
{
return F_79 ( & V_85 ) ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_85 ) ;
}
