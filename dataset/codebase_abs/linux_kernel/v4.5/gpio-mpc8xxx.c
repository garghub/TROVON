static inline T_1 F_1 ( unsigned int V_1 )
{
return 1u << ( V_2 - 1 - V_1 ) ;
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_3 ( V_4 , struct V_5 , V_7 ) ;
V_6 -> V_8 = F_4 ( V_4 -> V_9 + V_10 ) ;
}
static int F_5 ( struct V_11 * V_12 , unsigned int V_1 )
{
T_1 V_13 ;
struct V_3 * V_4 = F_6 ( V_12 ) ;
struct V_5 * V_6 = F_7 ( V_12 ) ;
T_1 V_14 , V_15 ;
V_14 = F_4 ( V_4 -> V_9 + V_16 ) ;
V_13 = F_4 ( V_4 -> V_9 + V_10 ) & ~ V_14 ;
V_15 = V_6 -> V_8 & V_14 ;
return ! ! ( ( V_13 | V_15 ) & F_1 ( V_1 ) ) ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_1 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
return F_4 ( V_4 -> V_9 + V_10 ) & F_1 ( V_1 ) ;
}
static void F_9 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
struct V_5 * V_6 = F_7 ( V_12 ) ;
unsigned long V_17 ;
F_10 ( & V_6 -> V_18 , V_17 ) ;
if ( V_13 )
V_6 -> V_8 |= F_1 ( V_1 ) ;
else
V_6 -> V_8 &= ~ F_1 ( V_1 ) ;
F_11 ( V_4 -> V_9 + V_10 , V_6 -> V_8 ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
}
static void F_13 ( struct V_11 * V_12 ,
unsigned long * V_19 , unsigned long * V_20 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
struct V_5 * V_6 = F_7 ( V_12 ) ;
unsigned long V_17 ;
int V_21 ;
F_10 ( & V_6 -> V_18 , V_17 ) ;
for ( V_21 = 0 ; V_21 < V_12 -> V_22 ; V_21 ++ ) {
if ( * V_19 == 0 )
break;
if ( F_14 ( V_21 , V_19 ) ) {
if ( F_15 ( V_21 , V_20 ) )
V_6 -> V_8 |= F_1 ( V_21 ) ;
else
V_6 -> V_8 &= ~ F_1 ( V_21 ) ;
}
}
F_11 ( V_4 -> V_9 + V_10 , V_6 -> V_8 ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
}
static int F_16 ( struct V_11 * V_12 , unsigned int V_1 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
struct V_5 * V_6 = F_7 ( V_12 ) ;
unsigned long V_17 ;
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_17 ( V_4 -> V_9 + V_16 , F_1 ( V_1 ) ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
struct V_5 * V_6 = F_7 ( V_12 ) ;
unsigned long V_17 ;
F_9 ( V_12 , V_1 , V_13 ) ;
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_19 ( V_4 -> V_9 + V_16 , F_1 ( V_1 ) ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
if ( V_1 >= 28 )
return - V_23 ;
return F_18 ( V_12 , V_1 , V_13 ) ;
}
static int F_21 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
if ( V_1 <= 3 )
return - V_23 ;
return F_18 ( V_12 , V_1 , V_13 ) ;
}
static int F_22 ( struct V_11 * V_12 , unsigned V_24 )
{
struct V_5 * V_6 = F_7 ( V_12 ) ;
if ( V_6 -> V_25 && V_24 < V_2 )
return F_23 ( V_6 -> V_25 , V_24 ) ;
else
return - V_26 ;
}
static void F_24 ( struct V_27 * V_28 )
{
struct V_5 * V_6 = F_25 ( V_28 ) ;
struct V_29 * V_30 = F_26 ( V_28 ) ;
struct V_3 * V_4 = & V_6 -> V_7 ;
unsigned int V_19 ;
V_19 = F_4 ( V_4 -> V_9 + V_31 ) & F_4 ( V_4 -> V_9 + V_32 ) ;
if ( V_19 )
F_27 ( F_28 ( V_6 -> V_25 ,
32 - F_29 ( V_19 ) ) ) ;
if ( V_30 -> V_33 )
V_30 -> V_33 ( & V_28 -> V_34 ) ;
}
static void F_30 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = F_31 ( V_35 ) ;
struct V_3 * V_4 = & V_6 -> V_7 ;
unsigned long V_17 ;
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_19 ( V_4 -> V_9 + V_32 , F_1 ( F_32 ( V_35 ) ) ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
}
static void F_33 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = F_31 ( V_35 ) ;
struct V_3 * V_4 = & V_6 -> V_7 ;
unsigned long V_17 ;
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_17 ( V_4 -> V_9 + V_32 , F_1 ( F_32 ( V_35 ) ) ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
}
static void F_34 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = F_31 ( V_35 ) ;
struct V_3 * V_4 = & V_6 -> V_7 ;
F_11 ( V_4 -> V_9 + V_31 , F_1 ( F_32 ( V_35 ) ) ) ;
}
static int F_35 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_5 * V_6 = F_31 ( V_35 ) ;
struct V_3 * V_4 = & V_6 -> V_7 ;
unsigned long V_17 ;
switch ( V_36 ) {
case V_37 :
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_19 ( V_4 -> V_9 + V_38 ,
F_1 ( F_32 ( V_35 ) ) ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
break;
case V_39 :
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_17 ( V_4 -> V_9 + V_38 ,
F_1 ( F_32 ( V_35 ) ) ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_36 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_5 * V_6 = F_31 ( V_35 ) ;
struct V_3 * V_4 = & V_6 -> V_7 ;
unsigned long V_1 = F_32 ( V_35 ) ;
void T_2 * V_40 ;
unsigned int V_41 ;
unsigned long V_17 ;
if ( V_1 < 16 ) {
V_40 = V_4 -> V_9 + V_38 ;
V_41 = ( 15 - V_1 ) * 2 ;
} else {
V_40 = V_4 -> V_9 + V_42 ;
V_41 = ( 15 - ( V_1 % 16 ) ) * 2 ;
}
switch ( V_36 ) {
case V_37 :
case V_43 :
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_37 ( V_40 , 3 << V_41 , 2 << V_41 ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
break;
case V_44 :
case V_45 :
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_37 ( V_40 , 3 << V_41 , 1 << V_41 ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
break;
case V_39 :
F_10 ( & V_6 -> V_18 , V_17 ) ;
F_17 ( V_40 , 3 << V_41 ) ;
F_12 ( & V_6 -> V_18 , V_17 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_38 ( struct V_46 * V_47 , unsigned int V_25 ,
T_3 V_48 )
{
F_39 ( V_25 , V_47 -> V_49 ) ;
F_40 ( V_25 , & V_50 , V_51 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_56 . V_57 ;
struct V_5 * V_6 ;
struct V_3 * V_7 ;
struct V_11 * V_12 ;
const struct V_58 * V_59 ;
const struct V_60 * V_61 =
F_42 ( & V_53 -> V_56 ) ;
int V_62 ;
V_6 = F_43 ( & V_53 -> V_56 , sizeof( * V_6 ) , V_63 ) ;
if ( ! V_6 )
return - V_64 ;
F_44 ( V_53 , V_6 ) ;
F_45 ( & V_6 -> V_18 ) ;
V_7 = & V_6 -> V_7 ;
V_12 = & V_7 -> V_12 ;
V_7 -> V_65 = F_2 ;
V_12 -> V_22 = V_2 ;
V_12 -> V_66 = F_16 ;
if ( ! V_61 )
V_61 = & V_67 ;
V_50 . V_68 = V_61 -> V_68 ;
V_12 -> V_69 = V_61 -> V_70 ? : F_18 ;
V_12 -> V_71 = V_61 -> V_72 ? : F_8 ;
V_12 -> V_73 = F_9 ;
V_12 -> V_74 = F_13 ;
V_12 -> V_75 = F_22 ;
V_62 = F_46 ( V_55 , V_7 , V_6 ) ;
if ( V_62 )
return V_62 ;
V_6 -> V_76 = F_47 ( V_55 , 0 ) ;
if ( V_6 -> V_76 == V_77 )
return 0 ;
V_6 -> V_25 = F_48 ( V_55 , V_2 ,
& V_78 , V_6 ) ;
if ( ! V_6 -> V_25 )
return 0 ;
V_59 = F_49 ( V_79 , V_55 ) ;
if ( V_59 )
V_6 -> V_80 = V_59 -> V_8 ;
F_11 ( V_7 -> V_9 + V_31 , 0xffffffff ) ;
F_11 ( V_7 -> V_9 + V_32 , 0 ) ;
F_50 ( V_6 -> V_76 ,
F_24 , V_6 ) ;
return 0 ;
}
static int F_51 ( struct V_52 * V_53 )
{
struct V_5 * V_6 = F_52 ( V_53 ) ;
if ( V_6 -> V_25 ) {
F_50 ( V_6 -> V_76 , NULL , NULL ) ;
F_53 ( V_6 -> V_25 ) ;
}
F_54 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
return F_56 ( & V_81 ) ;
}
