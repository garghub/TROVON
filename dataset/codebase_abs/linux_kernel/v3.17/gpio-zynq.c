static inline void F_1 ( unsigned int V_1 ,
unsigned int * V_2 ,
unsigned int * V_3 )
{
switch ( V_1 ) {
case V_4 ... V_5 :
* V_2 = 0 ;
* V_3 = V_1 ;
break;
case V_6 ... V_7 :
* V_2 = 1 ;
* V_3 = V_1 - V_6 ;
break;
case V_8 ... V_9 :
* V_2 = 2 ;
* V_3 = V_1 - V_8 ;
break;
case V_10 ... V_11 :
* V_2 = 3 ;
* V_3 = V_1 - V_10 ;
break;
default:
F_2 ( true , L_1 , V_1 ) ;
* V_2 = 0 ;
* V_3 = 0 ;
break;
}
}
static int F_3 ( struct V_12 * V_13 , unsigned int V_14 )
{
T_1 V_15 ;
unsigned int V_2 , V_3 ;
struct V_16 * V_17 = F_4 ( V_13 , struct V_16 , V_13 ) ;
F_1 ( V_14 , & V_2 , & V_3 ) ;
V_15 = F_5 ( V_17 -> V_18 +
F_6 ( V_2 ) ) ;
return ( V_15 >> V_3 ) & 1 ;
}
static void F_7 ( struct V_12 * V_13 , unsigned int V_14 ,
int V_19 )
{
unsigned int V_20 , V_2 , V_3 ;
struct V_16 * V_17 = F_4 ( V_13 , struct V_16 , V_13 ) ;
F_1 ( V_14 , & V_2 , & V_3 ) ;
if ( V_3 >= V_21 ) {
V_3 -= V_21 ;
V_20 = F_8 ( V_2 ) ;
} else {
V_20 = F_9 ( V_2 ) ;
}
V_19 = ! ! V_19 ;
V_19 = ~ ( 1 << ( V_3 + V_21 ) ) &
( ( V_19 << V_3 ) | V_22 ) ;
F_10 ( V_19 , V_17 -> V_18 + V_20 ) ;
}
static int F_11 ( struct V_12 * V_13 , unsigned int V_14 )
{
T_1 V_23 ;
unsigned int V_2 , V_3 ;
struct V_16 * V_17 = F_4 ( V_13 , struct V_16 , V_13 ) ;
F_1 ( V_14 , & V_2 , & V_3 ) ;
if ( V_2 == 0 && ( V_3 == 7 || V_3 == 8 ) )
return - V_24 ;
V_23 = F_5 ( V_17 -> V_18 + F_12 ( V_2 ) ) ;
V_23 &= ~ F_13 ( V_3 ) ;
F_10 ( V_23 , V_17 -> V_18 + F_12 ( V_2 ) ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 , unsigned int V_14 ,
int V_19 )
{
T_1 V_23 ;
unsigned int V_2 , V_3 ;
struct V_16 * V_17 = F_4 ( V_13 , struct V_16 , V_13 ) ;
F_1 ( V_14 , & V_2 , & V_3 ) ;
V_23 = F_5 ( V_17 -> V_18 + F_12 ( V_2 ) ) ;
V_23 |= F_13 ( V_3 ) ;
F_10 ( V_23 , V_17 -> V_18 + F_12 ( V_2 ) ) ;
V_23 = F_5 ( V_17 -> V_18 + F_15 ( V_2 ) ) ;
V_23 |= F_13 ( V_3 ) ;
F_10 ( V_23 , V_17 -> V_18 + F_15 ( V_2 ) ) ;
F_7 ( V_13 , V_14 , V_19 ) ;
return 0 ;
}
static void F_16 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_2 , V_3 ;
struct V_16 * V_17 = F_17 ( V_25 ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 ) ;
F_10 ( F_13 ( V_3 ) ,
V_17 -> V_18 + F_18 ( V_2 ) ) ;
}
static void F_19 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_2 , V_3 ;
struct V_16 * V_17 = F_17 ( V_25 ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 ) ;
F_10 ( F_13 ( V_3 ) ,
V_17 -> V_18 + F_20 ( V_2 ) ) ;
}
static void F_21 ( struct V_25 * V_25 )
{
unsigned int V_26 , V_2 , V_3 ;
struct V_16 * V_17 = F_17 ( V_25 ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 ) ;
F_10 ( F_13 ( V_3 ) ,
V_17 -> V_18 + F_22 ( V_2 ) ) ;
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
struct V_16 * V_17 = F_17 ( V_25 ) ;
V_26 = V_25 -> V_27 ;
F_1 ( V_26 , & V_2 , & V_3 ) ;
V_28 = F_5 ( V_17 -> V_18 +
F_25 ( V_2 ) ) ;
V_29 = F_5 ( V_17 -> V_18 +
F_26 ( V_2 ) ) ;
V_30 = F_5 ( V_17 -> V_18 +
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
V_17 -> V_18 + F_25 ( V_2 ) ) ;
F_10 ( V_29 ,
V_17 -> V_18 + F_26 ( V_2 ) ) ;
F_10 ( V_30 ,
V_17 -> V_18 + F_27 ( V_2 ) ) ;
if ( type & V_36 ) {
F_28 ( V_25 -> V_37 ,
& V_38 , V_39 , NULL ) ;
} else {
F_28 ( V_25 -> V_37 ,
& V_40 , V_41 , NULL ) ;
}
return 0 ;
}
static int F_29 ( struct V_25 * V_15 , unsigned int V_42 )
{
if ( V_42 )
F_19 ( V_15 ) ;
else
F_16 ( V_15 ) ;
return 0 ;
}
static void F_30 ( unsigned int V_37 , struct V_43 * V_44 )
{
T_1 V_45 , V_46 ;
unsigned int V_2 ;
struct V_16 * V_17 = F_31 ( V_37 ) ;
struct V_47 * V_48 = F_32 ( V_44 ) ;
F_33 ( V_48 , V_44 ) ;
for ( V_2 = 0 ; V_2 < V_49 ; V_2 ++ ) {
V_45 = F_5 ( V_17 -> V_18 +
F_22 ( V_2 ) ) ;
V_46 = F_5 ( V_17 -> V_18 +
F_34 ( V_2 ) ) ;
V_45 &= ~ V_46 ;
if ( V_45 ) {
int V_50 ;
unsigned long V_51 = V_45 ;
F_35 (offset, &pending, 32 ) {
unsigned int V_52 =
F_36 ( V_17 -> V_13 . V_53 ,
V_50 ) ;
F_37 ( V_52 ) ;
}
}
}
F_38 ( V_48 , V_44 ) ;
}
static int T_2 F_39 ( struct V_54 * V_55 )
{
if ( ! F_40 ( V_55 ) )
return F_41 ( V_55 ) ;
return 0 ;
}
static int T_2 F_42 ( struct V_54 * V_55 )
{
if ( ! F_40 ( V_55 ) )
return F_43 ( V_55 ) ;
return 0 ;
}
static int T_2 F_44 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_45 ( V_55 ) ;
struct V_16 * V_17 = F_46 ( V_57 ) ;
F_47 ( V_17 -> V_58 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_45 ( V_55 ) ;
struct V_16 * V_17 = F_46 ( V_57 ) ;
return F_49 ( V_17 -> V_58 ) ;
}
static int F_50 ( struct V_12 * V_13 , unsigned V_50 )
{
int V_59 ;
V_59 = F_51 ( V_13 -> V_55 ) ;
return V_59 < 0 ? V_59 : 0 ;
}
static void F_52 ( struct V_12 * V_13 , unsigned V_50 )
{
F_53 ( V_13 -> V_55 ) ;
}
static int F_54 ( struct V_56 * V_57 )
{
int V_59 , V_2 , V_37 ;
struct V_16 * V_17 ;
struct V_12 * V_13 ;
struct V_60 * V_61 ;
V_17 = F_55 ( & V_57 -> V_55 , sizeof( * V_17 ) , V_62 ) ;
if ( ! V_17 )
return - V_63 ;
F_56 ( V_57 , V_17 ) ;
V_61 = F_57 ( V_57 , V_64 , 0 ) ;
V_17 -> V_18 = F_58 ( & V_57 -> V_55 , V_61 ) ;
if ( F_59 ( V_17 -> V_18 ) )
return F_60 ( V_17 -> V_18 ) ;
V_37 = F_61 ( V_57 , 0 ) ;
if ( V_37 < 0 ) {
F_62 ( & V_57 -> V_55 , L_2 ) ;
return V_37 ;
}
V_13 = & V_17 -> V_13 ;
V_13 -> V_65 = L_3 ;
V_13 -> V_66 = V_67 ;
V_13 -> V_55 = & V_57 -> V_55 ;
V_13 -> V_68 = F_3 ;
V_13 -> V_69 = F_7 ;
V_13 -> V_70 = F_50 ;
V_13 -> free = F_52 ;
V_13 -> V_71 = F_11 ;
V_13 -> V_72 = F_14 ;
V_13 -> V_73 = - 1 ;
V_13 -> V_74 = V_75 ;
V_17 -> V_58 = F_63 ( & V_57 -> V_55 , NULL ) ;
if ( F_59 ( V_17 -> V_58 ) ) {
F_62 ( & V_57 -> V_55 , L_4 ) ;
return F_60 ( V_17 -> V_58 ) ;
}
V_59 = F_49 ( V_17 -> V_58 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_5 ) ;
return V_59 ;
}
V_59 = F_64 ( V_13 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_6 ) ;
goto V_76;
}
for ( V_2 = 0 ; V_2 < V_49 ; V_2 ++ )
F_10 ( V_77 , V_17 -> V_18 +
F_18 ( V_2 ) ) ;
V_59 = F_65 ( V_13 , & V_40 , 0 ,
V_41 , V_78 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_7 ) ;
goto V_79;
}
F_66 ( V_13 , & V_40 , V_37 ,
F_30 ) ;
F_67 ( & V_57 -> V_55 ) ;
F_68 ( & V_57 -> V_55 ) ;
F_69 ( & V_57 -> V_55 , 1 ) ;
return 0 ;
V_79:
if ( F_70 ( V_13 ) )
F_62 ( & V_57 -> V_55 , L_8 ) ;
V_76:
F_47 ( V_17 -> V_58 ) ;
return V_59 ;
}
static int F_71 ( struct V_56 * V_57 )
{
int V_59 ;
struct V_16 * V_17 = F_46 ( V_57 ) ;
F_51 ( & V_57 -> V_55 ) ;
V_59 = F_70 ( & V_17 -> V_13 ) ;
if ( V_59 ) {
F_62 ( & V_57 -> V_55 , L_8 ) ;
return V_59 ;
}
F_47 ( V_17 -> V_58 ) ;
F_69 ( & V_57 -> V_55 , 0 ) ;
return 0 ;
}
static int T_3 F_72 ( void )
{
return F_73 ( & V_80 ) ;
}
