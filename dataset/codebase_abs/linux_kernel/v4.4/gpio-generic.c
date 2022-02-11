static void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
F_2 ( V_2 , V_1 ) ;
}
static unsigned long F_3 ( void T_1 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( void T_1 * V_1 , unsigned long V_2 )
{
F_6 ( V_2 , V_1 ) ;
}
static unsigned long F_7 ( void T_1 * V_1 )
{
return F_8 ( V_1 ) ;
}
static void F_9 ( void T_1 * V_1 , unsigned long V_2 )
{
F_10 ( V_2 , V_1 ) ;
}
static unsigned long F_11 ( void T_1 * V_1 )
{
return F_12 ( V_1 ) ;
}
static void F_13 ( void T_1 * V_1 , unsigned long V_2 )
{
F_14 ( V_2 , V_1 ) ;
}
static unsigned long F_15 ( void T_1 * V_1 )
{
return F_16 ( V_1 ) ;
}
static void F_17 ( void T_1 * V_1 , unsigned long V_2 )
{
F_18 ( V_2 , V_1 ) ;
}
static unsigned long F_19 ( void T_1 * V_1 )
{
return F_20 ( V_1 ) ;
}
static void F_21 ( void T_1 * V_1 , unsigned long V_2 )
{
F_22 ( V_2 , V_1 ) ;
}
static unsigned long F_23 ( void T_1 * V_1 )
{
return F_24 ( V_1 ) ;
}
static unsigned long F_25 ( struct V_3 * V_4 , unsigned int V_5 )
{
return 1 << V_5 ;
}
static unsigned long F_26 ( struct V_3 * V_4 ,
unsigned int V_5 )
{
return 1 << ( V_4 -> V_6 - 1 - V_5 ) ;
}
static int F_27 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_10 = V_4 -> V_11 ( V_4 , V_9 ) ;
if ( V_4 -> V_12 & V_10 )
return ! ! ( V_4 -> V_13 ( V_4 -> V_14 ) & V_10 ) ;
else
return ! ! ( V_4 -> V_13 ( V_4 -> V_15 ) & V_10 ) ;
}
static int F_29 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
return ! ! ( V_4 -> V_13 ( V_4 -> V_15 ) & V_4 -> V_11 ( V_4 , V_9 ) ) ;
}
static void F_30 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
}
static void F_31 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_17 = V_4 -> V_11 ( V_4 , V_9 ) ;
unsigned long V_18 ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
if ( V_16 )
V_4 -> V_2 |= V_17 ;
else
V_4 -> V_2 &= ~ V_17 ;
V_4 -> V_20 ( V_4 -> V_15 , V_4 -> V_2 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_34 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_17 = V_4 -> V_11 ( V_4 , V_9 ) ;
if ( V_16 )
V_4 -> V_20 ( V_4 -> V_14 , V_17 ) ;
else
V_4 -> V_20 ( V_4 -> V_21 , V_17 ) ;
}
static void F_35 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_17 = V_4 -> V_11 ( V_4 , V_9 ) ;
unsigned long V_18 ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
if ( V_16 )
V_4 -> V_2 |= V_17 ;
else
V_4 -> V_2 &= ~ V_17 ;
V_4 -> V_20 ( V_4 -> V_14 , V_4 -> V_2 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_36 ( struct V_3 * V_4 ,
unsigned long * V_17 , unsigned long * V_6 ,
unsigned long * V_22 ,
unsigned long * V_23 )
{
int V_24 ;
* V_22 = 0 ;
* V_23 = 0 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_6 ; V_24 ++ ) {
if ( * V_17 == 0 )
break;
if ( F_37 ( V_24 , V_17 ) ) {
if ( F_38 ( V_24 , V_6 ) )
* V_22 |= V_4 -> V_11 ( V_4 , V_24 ) ;
else
* V_23 |= V_4 -> V_11 ( V_4 , V_24 ) ;
}
}
}
static void F_39 ( struct V_3 * V_4 ,
unsigned long * V_17 ,
unsigned long * V_6 ,
void T_1 * V_1 )
{
unsigned long V_18 ;
unsigned long V_22 , V_23 ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
F_36 ( V_4 , V_17 , V_6 , & V_22 , & V_23 ) ;
V_4 -> V_2 |= V_22 ;
V_4 -> V_2 &= ~ V_23 ;
V_4 -> V_20 ( V_1 , V_4 -> V_2 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_40 ( struct V_7 * V_8 , unsigned long * V_17 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
F_39 ( V_4 , V_17 , V_6 , V_4 -> V_15 ) ;
}
static void F_41 ( struct V_7 * V_8 , unsigned long * V_17 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
F_39 ( V_4 , V_17 , V_6 , V_4 -> V_14 ) ;
}
static void F_42 ( struct V_7 * V_8 ,
unsigned long * V_17 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_22 , V_23 ;
F_36 ( V_4 , V_17 , V_6 , & V_22 , & V_23 ) ;
if ( V_22 )
V_4 -> V_20 ( V_4 -> V_14 , V_22 ) ;
if ( V_23 )
V_4 -> V_20 ( V_4 -> V_21 , V_23 ) ;
}
static int F_43 ( struct V_7 * V_8 , unsigned int V_9 )
{
return 0 ;
}
static int F_44 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_16 )
{
return - V_25 ;
}
static int F_45 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_16 )
{
V_8 -> V_26 ( V_8 , V_9 , V_16 ) ;
return 0 ;
}
static int F_46 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 &= ~ V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_27 , V_4 -> V_12 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_47 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
return ( V_4 -> V_13 ( V_4 -> V_27 ) & V_4 -> V_11 ( V_4 , V_9 ) ) ?
V_28 : V_29 ;
}
static int F_48 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
V_8 -> V_26 ( V_8 , V_9 , V_16 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 |= V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_27 , V_4 -> V_12 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 |= V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_27 , V_4 -> V_12 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_50 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
V_8 -> V_26 ( V_8 , V_9 , V_16 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 &= ~ V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_27 , V_4 -> V_12 ) ;
F_33 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
return ( V_4 -> V_13 ( V_4 -> V_27 ) & V_4 -> V_11 ( V_4 , V_9 ) ) ?
V_29 : V_28 ;
}
static int F_52 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
bool V_32 ,
bool V_33 )
{
switch ( V_4 -> V_6 ) {
case 8 :
V_4 -> V_13 = F_3 ;
V_4 -> V_20 = F_1 ;
break;
case 16 :
if ( V_33 ) {
V_4 -> V_13 = F_19 ;
V_4 -> V_20 = F_17 ;
} else {
V_4 -> V_13 = F_7 ;
V_4 -> V_20 = F_5 ;
}
break;
case 32 :
if ( V_33 ) {
V_4 -> V_13 = F_23 ;
V_4 -> V_20 = F_21 ;
} else {
V_4 -> V_13 = F_11 ;
V_4 -> V_20 = F_9 ;
}
break;
#if V_34 >= 64
case 64 :
if ( V_33 ) {
F_53 ( V_31 ,
L_1 ) ;
return - V_25 ;
} else {
V_4 -> V_13 = F_15 ;
V_4 -> V_20 = F_13 ;
}
break;
#endif
default:
F_53 ( V_31 , L_2 , V_4 -> V_6 ) ;
return - V_25 ;
}
V_4 -> V_11 = V_32 ? F_26 : F_25 ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
void T_1 * V_35 ,
void T_1 * V_26 ,
void T_1 * V_36 ,
unsigned long V_18 )
{
V_4 -> V_15 = V_35 ;
if ( ! V_4 -> V_15 )
return - V_25 ;
if ( V_26 && V_36 ) {
V_4 -> V_14 = V_26 ;
V_4 -> V_21 = V_36 ;
V_4 -> V_8 . V_26 = F_34 ;
V_4 -> V_8 . V_37 = F_42 ;
} else if ( V_26 && ! V_36 ) {
V_4 -> V_14 = V_26 ;
V_4 -> V_8 . V_26 = F_35 ;
V_4 -> V_8 . V_37 = F_41 ;
} else if ( V_18 & V_38 ) {
V_4 -> V_8 . V_26 = F_30 ;
V_4 -> V_8 . V_37 = NULL ;
} else {
V_4 -> V_8 . V_26 = F_31 ;
V_4 -> V_8 . V_37 = F_40 ;
}
if ( ! ( V_18 & V_39 ) &&
( V_18 & V_40 ) )
V_4 -> V_8 . V_41 = F_27 ;
else
V_4 -> V_8 . V_41 = F_29 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
void T_1 * V_42 ,
void T_1 * V_43 ,
unsigned long V_18 )
{
if ( V_42 && V_43 ) {
return - V_25 ;
} else if ( V_42 ) {
V_4 -> V_27 = V_42 ;
V_4 -> V_8 . V_44 = F_48 ;
V_4 -> V_8 . V_45 = F_46 ;
V_4 -> V_8 . V_46 = F_47 ;
} else if ( V_43 ) {
V_4 -> V_27 = V_43 ;
V_4 -> V_8 . V_44 = F_50 ;
V_4 -> V_8 . V_45 = F_49 ;
V_4 -> V_8 . V_46 = F_51 ;
} else {
if ( V_18 & V_38 )
V_4 -> V_8 . V_44 = F_44 ;
else
V_4 -> V_8 . V_44 = F_45 ;
V_4 -> V_8 . V_45 = F_43 ;
}
return 0 ;
}
static int F_56 ( struct V_7 * V_47 , unsigned V_48 )
{
if ( V_48 < V_47 -> V_49 )
return 0 ;
return - V_25 ;
}
int F_57 ( struct V_3 * V_4 )
{
F_58 ( & V_4 -> V_8 ) ;
return 0 ;
}
int F_59 ( struct V_3 * V_4 , struct V_30 * V_31 ,
unsigned long V_50 , void T_1 * V_35 , void T_1 * V_26 ,
void T_1 * V_36 , void T_1 * V_42 , void T_1 * V_43 ,
unsigned long V_18 )
{
int V_51 ;
if ( ! F_60 ( V_50 ) )
return - V_25 ;
V_4 -> V_6 = V_50 * 8 ;
if ( V_4 -> V_6 > V_34 )
return - V_25 ;
F_61 ( & V_4 -> V_19 ) ;
V_4 -> V_8 . V_31 = V_31 ;
V_4 -> V_8 . V_52 = F_62 ( V_31 ) ;
V_4 -> V_8 . V_53 = - 1 ;
V_4 -> V_8 . V_49 = V_4 -> V_6 ;
V_4 -> V_8 . V_54 = F_56 ;
V_51 = F_54 ( V_4 , V_35 , V_26 , V_36 , V_18 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_52 ( V_31 , V_4 , V_18 & V_55 ,
V_18 & V_56 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_55 ( V_4 , V_42 , V_43 , V_18 ) ;
if ( V_51 )
return V_51 ;
V_4 -> V_2 = V_4 -> V_13 ( V_4 -> V_15 ) ;
if ( V_4 -> V_8 . V_26 == F_35 &&
! ( V_18 & V_39 ) )
V_4 -> V_2 = V_4 -> V_13 ( V_4 -> V_14 ) ;
if ( V_4 -> V_27 && ! ( V_18 & V_57 ) )
V_4 -> V_12 = V_4 -> V_13 ( V_4 -> V_27 ) ;
return V_51 ;
}
static void T_1 * F_63 ( struct V_58 * V_59 ,
const char * V_60 ,
T_2 V_61 )
{
struct V_62 * V_63 ;
T_2 V_50 ;
V_63 = F_64 ( V_59 , V_64 , V_60 ) ;
if ( ! V_63 )
return NULL ;
V_50 = F_65 ( V_63 ) ;
if ( V_50 != V_61 )
return F_66 ( - V_25 ) ;
return F_67 ( & V_59 -> V_31 , V_63 ) ;
}
static int F_68 ( struct V_58 * V_59 )
{
struct V_30 * V_31 = & V_59 -> V_31 ;
struct V_62 * V_63 ;
void T_1 * V_35 ;
void T_1 * V_26 ;
void T_1 * V_36 ;
void T_1 * V_42 ;
void T_1 * V_43 ;
unsigned long V_50 ;
unsigned long V_18 = V_59 -> V_65 -> V_66 ;
int V_67 ;
struct V_3 * V_4 ;
struct V_68 * V_69 = F_69 ( V_31 ) ;
V_63 = F_64 ( V_59 , V_64 , L_3 ) ;
if ( ! V_63 )
return - V_25 ;
V_50 = F_65 ( V_63 ) ;
V_35 = F_63 ( V_59 , L_3 , V_50 ) ;
if ( F_70 ( V_35 ) )
return F_71 ( V_35 ) ;
V_26 = F_63 ( V_59 , L_4 , V_50 ) ;
if ( F_70 ( V_26 ) )
return F_71 ( V_26 ) ;
V_36 = F_63 ( V_59 , L_5 , V_50 ) ;
if ( F_70 ( V_36 ) )
return F_71 ( V_36 ) ;
V_42 = F_63 ( V_59 , L_6 , V_50 ) ;
if ( F_70 ( V_42 ) )
return F_71 ( V_42 ) ;
V_43 = F_63 ( V_59 , L_7 , V_50 ) ;
if ( F_70 ( V_43 ) )
return F_71 ( V_43 ) ;
V_4 = F_72 ( & V_59 -> V_31 , sizeof( * V_4 ) , V_70 ) ;
if ( ! V_4 )
return - V_71 ;
V_67 = F_59 ( V_4 , V_31 , V_50 , V_35 , V_26 , V_36 , V_42 , V_43 , V_18 ) ;
if ( V_67 )
return V_67 ;
if ( V_69 ) {
if ( V_69 -> V_52 )
V_4 -> V_8 . V_52 = V_69 -> V_52 ;
V_4 -> V_8 . V_53 = V_69 -> V_53 ;
if ( V_69 -> V_49 > 0 )
V_4 -> V_8 . V_49 = V_69 -> V_49 ;
}
F_73 ( V_59 , V_4 ) ;
return F_74 ( & V_4 -> V_8 ) ;
}
static int F_75 ( struct V_58 * V_59 )
{
struct V_3 * V_4 = F_76 ( V_59 ) ;
return F_57 ( V_4 ) ;
}
