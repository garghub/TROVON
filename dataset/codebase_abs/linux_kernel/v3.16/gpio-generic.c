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
return ! ! ( V_4 -> V_10 ( V_4 -> V_11 ) & V_4 -> V_12 ( V_4 , V_9 ) ) ;
}
static void F_29 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_14 = V_4 -> V_12 ( V_4 , V_9 ) ;
unsigned long V_15 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
if ( V_13 )
V_4 -> V_2 |= V_14 ;
else
V_4 -> V_2 &= ~ V_14 ;
V_4 -> V_17 ( V_4 -> V_11 , V_4 -> V_2 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
}
static void F_32 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_14 = V_4 -> V_12 ( V_4 , V_9 ) ;
if ( V_13 )
V_4 -> V_17 ( V_4 -> V_18 , V_14 ) ;
else
V_4 -> V_17 ( V_4 -> V_19 , V_14 ) ;
}
static void F_33 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_14 = V_4 -> V_12 ( V_4 , V_9 ) ;
unsigned long V_15 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
if ( V_13 )
V_4 -> V_2 |= V_14 ;
else
V_4 -> V_2 &= ~ V_14 ;
V_4 -> V_17 ( V_4 -> V_18 , V_4 -> V_2 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
}
static int F_34 ( struct V_7 * V_8 , unsigned int V_9 )
{
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_13 )
{
V_8 -> V_20 ( V_8 , V_9 , V_13 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 &= ~ V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
V_8 -> V_20 ( V_8 , V_9 , V_13 ) ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 |= V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 |= V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
V_8 -> V_20 ( V_8 , V_9 , V_13 ) ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 &= ~ V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
struct V_3 * V_4 ,
bool V_25 ,
bool V_26 )
{
switch ( V_4 -> V_6 ) {
case 8 :
V_4 -> V_10 = F_3 ;
V_4 -> V_17 = F_1 ;
break;
case 16 :
if ( V_26 ) {
V_4 -> V_10 = F_19 ;
V_4 -> V_17 = F_17 ;
} else {
V_4 -> V_10 = F_7 ;
V_4 -> V_17 = F_5 ;
}
break;
case 32 :
if ( V_26 ) {
V_4 -> V_10 = F_23 ;
V_4 -> V_17 = F_21 ;
} else {
V_4 -> V_10 = F_11 ;
V_4 -> V_17 = F_9 ;
}
break;
#if V_27 >= 64
case 64 :
if ( V_26 ) {
F_41 ( V_24 ,
L_1 ) ;
return - V_28 ;
} else {
V_4 -> V_10 = F_15 ;
V_4 -> V_17 = F_13 ;
}
break;
#endif
default:
F_41 ( V_24 , L_2 , V_4 -> V_6 ) ;
return - V_28 ;
}
V_4 -> V_12 = V_25 ? F_26 : F_25 ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 ,
void T_1 * V_29 ,
void T_1 * V_20 ,
void T_1 * V_30 )
{
V_4 -> V_11 = V_29 ;
if ( ! V_4 -> V_11 )
return - V_28 ;
if ( V_20 && V_30 ) {
V_4 -> V_18 = V_20 ;
V_4 -> V_19 = V_30 ;
V_4 -> V_8 . V_20 = F_32 ;
} else if ( V_20 && ! V_30 ) {
V_4 -> V_18 = V_20 ;
V_4 -> V_8 . V_20 = F_33 ;
} else {
V_4 -> V_8 . V_20 = F_29 ;
}
V_4 -> V_8 . V_31 = F_27 ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 ,
void T_1 * V_32 ,
void T_1 * V_33 )
{
if ( V_32 && V_33 ) {
return - V_28 ;
} else if ( V_32 ) {
V_4 -> V_22 = V_32 ;
V_4 -> V_8 . V_34 = F_37 ;
V_4 -> V_8 . V_35 = F_36 ;
} else if ( V_33 ) {
V_4 -> V_22 = V_33 ;
V_4 -> V_8 . V_34 = F_39 ;
V_4 -> V_8 . V_35 = F_38 ;
} else {
V_4 -> V_8 . V_34 = F_35 ;
V_4 -> V_8 . V_35 = F_34 ;
}
return 0 ;
}
static int F_44 ( struct V_7 * V_36 , unsigned V_37 )
{
if ( V_37 < V_36 -> V_38 )
return 0 ;
return - V_28 ;
}
int F_45 ( struct V_3 * V_4 )
{
return F_46 ( & V_4 -> V_8 ) ;
}
int F_47 ( struct V_3 * V_4 , struct V_23 * V_24 ,
unsigned long V_39 , void T_1 * V_29 , void T_1 * V_20 ,
void T_1 * V_30 , void T_1 * V_32 , void T_1 * V_33 ,
unsigned long V_15 )
{
int V_40 ;
if ( ! F_48 ( V_39 ) )
return - V_28 ;
V_4 -> V_6 = V_39 * 8 ;
if ( V_4 -> V_6 > V_27 )
return - V_28 ;
F_49 ( & V_4 -> V_16 ) ;
V_4 -> V_8 . V_24 = V_24 ;
V_4 -> V_8 . V_41 = F_50 ( V_24 ) ;
V_4 -> V_8 . V_42 = - 1 ;
V_4 -> V_8 . V_38 = V_4 -> V_6 ;
V_4 -> V_8 . V_43 = F_44 ;
V_40 = F_42 ( V_4 , V_29 , V_20 , V_30 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_40 ( V_24 , V_4 , V_15 & V_44 ,
V_15 & V_45 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_43 ( V_4 , V_32 , V_33 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_11 ) ;
if ( V_4 -> V_8 . V_20 == F_33 &&
! ( V_15 & V_46 ) )
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_18 ) ;
if ( V_4 -> V_22 && ! ( V_15 & V_47 ) )
V_4 -> V_21 = V_4 -> V_10 ( V_4 -> V_22 ) ;
return V_40 ;
}
static void T_1 * F_51 ( struct V_48 * V_49 ,
const char * V_50 ,
T_2 V_51 ,
int * V_52 )
{
struct V_23 * V_24 = & V_49 -> V_24 ;
struct V_53 * V_54 ;
T_2 V_55 ;
T_2 V_39 ;
void T_1 * V_40 ;
* V_52 = 0 ;
V_54 = F_52 ( V_49 , V_56 , V_50 ) ;
if ( ! V_54 )
return NULL ;
V_39 = F_53 ( V_54 ) ;
if ( V_39 != V_51 ) {
* V_52 = - V_28 ;
return NULL ;
}
V_55 = V_54 -> V_55 ;
if ( ! F_54 ( V_24 , V_55 , V_39 , V_54 -> V_50 ) ) {
* V_52 = - V_57 ;
return NULL ;
}
V_40 = F_55 ( V_24 , V_55 , V_39 ) ;
if ( ! V_40 ) {
* V_52 = - V_58 ;
return NULL ;
}
return V_40 ;
}
static int F_56 ( struct V_48 * V_49 )
{
struct V_23 * V_24 = & V_49 -> V_24 ;
struct V_53 * V_54 ;
void T_1 * V_29 ;
void T_1 * V_20 ;
void T_1 * V_30 ;
void T_1 * V_32 ;
void T_1 * V_33 ;
unsigned long V_39 ;
unsigned long V_15 = V_49 -> V_59 -> V_60 ;
int V_52 ;
struct V_3 * V_4 ;
struct V_61 * V_62 = F_57 ( V_24 ) ;
V_54 = F_52 ( V_49 , V_56 , L_3 ) ;
if ( ! V_54 )
return - V_28 ;
V_39 = F_53 ( V_54 ) ;
V_29 = F_51 ( V_49 , L_3 , V_39 , & V_52 ) ;
if ( ! V_29 )
return V_52 ? V_52 : - V_28 ;
V_20 = F_51 ( V_49 , L_4 , V_39 , & V_52 ) ;
if ( V_52 )
return V_52 ;
V_30 = F_51 ( V_49 , L_5 , V_39 , & V_52 ) ;
if ( V_52 )
return V_52 ;
V_32 = F_51 ( V_49 , L_6 , V_39 , & V_52 ) ;
if ( V_52 )
return V_52 ;
V_33 = F_51 ( V_49 , L_7 , V_39 , & V_52 ) ;
if ( V_52 )
return V_52 ;
V_4 = F_58 ( & V_49 -> V_24 , sizeof( * V_4 ) , V_63 ) ;
if ( ! V_4 )
return - V_58 ;
V_52 = F_47 ( V_4 , V_24 , V_39 , V_29 , V_20 , V_30 , V_32 , V_33 , V_15 ) ;
if ( V_52 )
return V_52 ;
if ( V_62 ) {
if ( V_62 -> V_41 )
V_4 -> V_8 . V_41 = V_62 -> V_41 ;
V_4 -> V_8 . V_42 = V_62 -> V_42 ;
if ( V_62 -> V_38 > 0 )
V_4 -> V_8 . V_38 = V_62 -> V_38 ;
}
F_59 ( V_49 , V_4 ) ;
return F_60 ( & V_4 -> V_8 ) ;
}
static int F_61 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_62 ( V_49 ) ;
return F_45 ( V_4 ) ;
}
