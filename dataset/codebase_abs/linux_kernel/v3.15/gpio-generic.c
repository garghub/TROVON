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
int F_44 ( struct V_3 * V_4 )
{
return F_45 ( & V_4 -> V_8 ) ;
}
int F_46 ( struct V_3 * V_4 , struct V_23 * V_24 ,
unsigned long V_36 , void T_1 * V_29 , void T_1 * V_20 ,
void T_1 * V_30 , void T_1 * V_32 , void T_1 * V_33 ,
unsigned long V_15 )
{
int V_37 ;
if ( ! F_47 ( V_36 ) )
return - V_28 ;
V_4 -> V_6 = V_36 * 8 ;
if ( V_4 -> V_6 > V_27 )
return - V_28 ;
F_48 ( & V_4 -> V_16 ) ;
V_4 -> V_8 . V_24 = V_24 ;
V_4 -> V_8 . V_38 = F_49 ( V_24 ) ;
V_4 -> V_8 . V_39 = - 1 ;
V_4 -> V_8 . V_40 = V_4 -> V_6 ;
V_37 = F_42 ( V_4 , V_29 , V_20 , V_30 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_40 ( V_24 , V_4 , V_15 & V_41 ,
V_15 & V_42 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_43 ( V_4 , V_32 , V_33 ) ;
if ( V_37 )
return V_37 ;
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_11 ) ;
if ( V_4 -> V_8 . V_20 == F_33 &&
! ( V_15 & V_43 ) )
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_18 ) ;
if ( V_4 -> V_22 && ! ( V_15 & V_44 ) )
V_4 -> V_21 = V_4 -> V_10 ( V_4 -> V_22 ) ;
return V_37 ;
}
static void T_1 * F_50 ( struct V_45 * V_46 ,
const char * V_47 ,
T_2 V_48 ,
int * V_49 )
{
struct V_23 * V_24 = & V_46 -> V_24 ;
struct V_50 * V_51 ;
T_2 V_52 ;
T_2 V_36 ;
void T_1 * V_37 ;
* V_49 = 0 ;
V_51 = F_51 ( V_46 , V_53 , V_47 ) ;
if ( ! V_51 )
return NULL ;
V_36 = F_52 ( V_51 ) ;
if ( V_36 != V_48 ) {
* V_49 = - V_28 ;
return NULL ;
}
V_52 = V_51 -> V_52 ;
if ( ! F_53 ( V_24 , V_52 , V_36 , V_51 -> V_47 ) ) {
* V_49 = - V_54 ;
return NULL ;
}
V_37 = F_54 ( V_24 , V_52 , V_36 ) ;
if ( ! V_37 ) {
* V_49 = - V_55 ;
return NULL ;
}
return V_37 ;
}
static int F_55 ( struct V_45 * V_46 )
{
struct V_23 * V_24 = & V_46 -> V_24 ;
struct V_50 * V_51 ;
void T_1 * V_29 ;
void T_1 * V_20 ;
void T_1 * V_30 ;
void T_1 * V_32 ;
void T_1 * V_33 ;
unsigned long V_36 ;
unsigned long V_15 = V_46 -> V_56 -> V_57 ;
int V_49 ;
struct V_3 * V_4 ;
struct V_58 * V_59 = F_56 ( V_24 ) ;
V_51 = F_51 ( V_46 , V_53 , L_3 ) ;
if ( ! V_51 )
return - V_28 ;
V_36 = F_52 ( V_51 ) ;
V_29 = F_50 ( V_46 , L_3 , V_36 , & V_49 ) ;
if ( ! V_29 )
return V_49 ? V_49 : - V_28 ;
V_20 = F_50 ( V_46 , L_4 , V_36 , & V_49 ) ;
if ( V_49 )
return V_49 ;
V_30 = F_50 ( V_46 , L_5 , V_36 , & V_49 ) ;
if ( V_49 )
return V_49 ;
V_32 = F_50 ( V_46 , L_6 , V_36 , & V_49 ) ;
if ( V_49 )
return V_49 ;
V_33 = F_50 ( V_46 , L_7 , V_36 , & V_49 ) ;
if ( V_49 )
return V_49 ;
V_4 = F_57 ( & V_46 -> V_24 , sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 )
return - V_55 ;
V_49 = F_46 ( V_4 , V_24 , V_36 , V_29 , V_20 , V_30 , V_32 , V_33 , V_15 ) ;
if ( V_49 )
return V_49 ;
if ( V_59 ) {
if ( V_59 -> V_38 )
V_4 -> V_8 . V_38 = V_59 -> V_38 ;
V_4 -> V_8 . V_39 = V_59 -> V_39 ;
if ( V_59 -> V_40 > 0 )
V_4 -> V_8 . V_40 = V_59 -> V_40 ;
}
F_58 ( V_46 , V_4 ) ;
return F_59 ( & V_4 -> V_8 ) ;
}
static int F_60 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = F_61 ( V_46 ) ;
return F_44 ( V_4 ) ;
}
