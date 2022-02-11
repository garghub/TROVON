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
struct V_16 * V_17 = F_17 ( V_15 ) ;
F_30 ( V_17 -> V_37 , V_42 ) ;
return 0 ;
}
static void F_31 ( struct V_16 * V_17 ,
unsigned int V_2 ,
unsigned long V_43 )
{
unsigned int V_44 = V_45 [ V_2 ] ;
struct V_46 * V_47 = V_17 -> V_13 . V_47 ;
int V_48 ;
if ( ! V_43 )
return;
F_32 (offset, &pending, 32 ) {
unsigned int V_49 ;
V_49 = F_33 ( V_47 , V_48 + V_44 ) ;
F_34 ( V_49 ) ;
}
}
static void F_35 ( unsigned int V_37 , struct V_50 * V_51 )
{
T_1 V_52 , V_53 ;
unsigned int V_2 ;
struct V_16 * V_17 = F_36 ( V_37 ) ;
struct V_54 * V_55 = F_37 ( V_51 ) ;
F_38 ( V_55 , V_51 ) ;
for ( V_2 = 0 ; V_2 < V_56 ; V_2 ++ ) {
V_52 = F_5 ( V_17 -> V_18 +
F_22 ( V_2 ) ) ;
V_53 = F_5 ( V_17 -> V_18 +
F_39 ( V_2 ) ) ;
F_31 ( V_17 , V_2 , V_52 & ~ V_53 ) ;
}
F_40 ( V_55 , V_51 ) ;
}
static int T_2 F_41 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_42 ( V_58 ) ;
int V_37 = F_43 ( V_60 , 0 ) ;
struct V_25 * V_15 = F_44 ( V_37 ) ;
if ( ! F_45 ( V_15 ) )
return F_46 ( V_58 ) ;
return 0 ;
}
static int T_2 F_47 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_42 ( V_58 ) ;
int V_37 = F_43 ( V_60 , 0 ) ;
struct V_25 * V_15 = F_44 ( V_37 ) ;
if ( ! F_45 ( V_15 ) )
return F_48 ( V_58 ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_42 ( V_58 ) ;
struct V_16 * V_17 = F_50 ( V_60 ) ;
F_51 ( V_17 -> V_61 ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_42 ( V_58 ) ;
struct V_16 * V_17 = F_50 ( V_60 ) ;
return F_53 ( V_17 -> V_61 ) ;
}
static int F_54 ( struct V_12 * V_13 , unsigned V_48 )
{
int V_62 ;
V_62 = F_55 ( V_13 -> V_58 ) ;
return V_62 < 0 ? V_62 : 0 ;
}
static void F_56 ( struct V_12 * V_13 , unsigned V_48 )
{
F_57 ( V_13 -> V_58 ) ;
}
static int F_58 ( struct V_59 * V_60 )
{
int V_62 , V_2 ;
struct V_16 * V_17 ;
struct V_12 * V_13 ;
struct V_63 * V_64 ;
V_17 = F_59 ( & V_60 -> V_58 , sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return - V_66 ;
F_60 ( V_60 , V_17 ) ;
V_64 = F_61 ( V_60 , V_67 , 0 ) ;
V_17 -> V_18 = F_62 ( & V_60 -> V_58 , V_64 ) ;
if ( F_63 ( V_17 -> V_18 ) )
return F_64 ( V_17 -> V_18 ) ;
V_17 -> V_37 = F_43 ( V_60 , 0 ) ;
if ( V_17 -> V_37 < 0 ) {
F_65 ( & V_60 -> V_58 , L_2 ) ;
return V_17 -> V_37 ;
}
V_13 = & V_17 -> V_13 ;
V_13 -> V_68 = L_3 ;
V_13 -> V_69 = V_70 ;
V_13 -> V_58 = & V_60 -> V_58 ;
V_13 -> V_71 = F_3 ;
V_13 -> V_72 = F_7 ;
V_13 -> V_73 = F_54 ;
V_13 -> free = F_56 ;
V_13 -> V_74 = F_11 ;
V_13 -> V_75 = F_14 ;
V_13 -> V_76 = - 1 ;
V_13 -> V_77 = V_78 ;
V_17 -> V_61 = F_66 ( & V_60 -> V_58 , NULL ) ;
if ( F_63 ( V_17 -> V_61 ) ) {
F_65 ( & V_60 -> V_58 , L_4 ) ;
return F_64 ( V_17 -> V_61 ) ;
}
V_62 = F_53 ( V_17 -> V_61 ) ;
if ( V_62 ) {
F_65 ( & V_60 -> V_58 , L_5 ) ;
return V_62 ;
}
V_62 = F_67 ( V_13 ) ;
if ( V_62 ) {
F_65 ( & V_60 -> V_58 , L_6 ) ;
goto V_79;
}
for ( V_2 = 0 ; V_2 < V_56 ; V_2 ++ )
F_10 ( V_80 , V_17 -> V_18 +
F_18 ( V_2 ) ) ;
V_62 = F_68 ( V_13 , & V_40 , 0 ,
V_41 , V_81 ) ;
if ( V_62 ) {
F_65 ( & V_60 -> V_58 , L_7 ) ;
goto V_82;
}
F_69 ( V_13 , & V_40 , V_17 -> V_37 ,
F_35 ) ;
F_70 ( & V_60 -> V_58 ) ;
F_71 ( & V_60 -> V_58 ) ;
return 0 ;
V_82:
F_72 ( V_13 ) ;
V_79:
F_51 ( V_17 -> V_61 ) ;
return V_62 ;
}
static int F_73 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_50 ( V_60 ) ;
F_55 ( & V_60 -> V_58 ) ;
F_72 ( & V_17 -> V_13 ) ;
F_51 ( V_17 -> V_61 ) ;
F_74 ( & V_60 -> V_58 , 0 ) ;
return 0 ;
}
static int T_3 F_75 ( void )
{
return F_76 ( & V_83 ) ;
}
