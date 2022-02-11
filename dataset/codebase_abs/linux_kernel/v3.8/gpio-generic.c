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
static unsigned long F_17 ( struct V_3 * V_4 , unsigned int V_5 )
{
return 1 << V_5 ;
}
static unsigned long F_18 ( struct V_3 * V_4 ,
unsigned int V_5 )
{
return 1 << ( V_4 -> V_6 - 1 - V_5 ) ;
}
static int F_19 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
return V_4 -> V_10 ( V_4 -> V_11 ) & V_4 -> V_12 ( V_4 , V_9 ) ;
}
static void F_21 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_14 = V_4 -> V_12 ( V_4 , V_9 ) ;
unsigned long V_15 ;
F_22 ( & V_4 -> V_16 , V_15 ) ;
if ( V_13 )
V_4 -> V_2 |= V_14 ;
else
V_4 -> V_2 &= ~ V_14 ;
V_4 -> V_17 ( V_4 -> V_11 , V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_16 , V_15 ) ;
}
static void F_24 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_13 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_14 = V_4 -> V_12 ( V_4 , V_9 ) ;
if ( V_13 )
V_4 -> V_17 ( V_4 -> V_18 , V_14 ) ;
else
V_4 -> V_17 ( V_4 -> V_19 , V_14 ) ;
}
static void F_25 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_14 = V_4 -> V_12 ( V_4 , V_9 ) ;
unsigned long V_15 ;
F_22 ( & V_4 -> V_16 , V_15 ) ;
if ( V_13 )
V_4 -> V_2 |= V_14 ;
else
V_4 -> V_2 &= ~ V_14 ;
V_4 -> V_17 ( V_4 -> V_18 , V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_16 , V_15 ) ;
}
static int F_26 ( struct V_7 * V_8 , unsigned int V_9 )
{
return 0 ;
}
static int F_27 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_13 )
{
V_8 -> V_20 ( V_8 , V_9 , V_13 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_15 ;
F_22 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 &= ~ V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_23 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_15 ;
V_8 -> V_20 ( V_8 , V_9 , V_13 ) ;
F_22 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 |= V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_23 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_15 ;
F_22 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 |= V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_23 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_20 ( V_8 ) ;
unsigned long V_15 ;
V_8 -> V_20 ( V_8 , V_9 , V_13 ) ;
F_22 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_21 &= ~ V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_22 , V_4 -> V_21 ) ;
F_23 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_32 ( struct V_23 * V_24 ,
struct V_3 * V_4 ,
bool V_25 )
{
switch ( V_4 -> V_6 ) {
case 8 :
V_4 -> V_10 = F_3 ;
V_4 -> V_17 = F_1 ;
break;
case 16 :
V_4 -> V_10 = F_7 ;
V_4 -> V_17 = F_5 ;
break;
case 32 :
V_4 -> V_10 = F_11 ;
V_4 -> V_17 = F_9 ;
break;
#if V_26 >= 64
case 64 :
V_4 -> V_10 = F_15 ;
V_4 -> V_17 = F_13 ;
break;
#endif
default:
F_33 ( V_24 , L_1 , V_4 -> V_6 ) ;
return - V_27 ;
}
V_4 -> V_12 = V_25 ? F_18 : F_17 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 ,
void T_1 * V_28 ,
void T_1 * V_20 ,
void T_1 * V_29 )
{
V_4 -> V_11 = V_28 ;
if ( ! V_4 -> V_11 )
return - V_27 ;
if ( V_20 && V_29 ) {
V_4 -> V_18 = V_20 ;
V_4 -> V_19 = V_29 ;
V_4 -> V_8 . V_20 = F_24 ;
} else if ( V_20 && ! V_29 ) {
V_4 -> V_18 = V_20 ;
V_4 -> V_8 . V_20 = F_25 ;
} else {
V_4 -> V_8 . V_20 = F_21 ;
}
V_4 -> V_8 . V_30 = F_19 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 ,
void T_1 * V_31 ,
void T_1 * V_32 )
{
if ( V_31 && V_32 ) {
return - V_27 ;
} else if ( V_31 ) {
V_4 -> V_22 = V_31 ;
V_4 -> V_8 . V_33 = F_29 ;
V_4 -> V_8 . V_34 = F_28 ;
} else if ( V_32 ) {
V_4 -> V_22 = V_32 ;
V_4 -> V_8 . V_33 = F_31 ;
V_4 -> V_8 . V_34 = F_30 ;
} else {
V_4 -> V_8 . V_33 = F_27 ;
V_4 -> V_8 . V_34 = F_26 ;
}
return 0 ;
}
int F_36 ( struct V_3 * V_4 )
{
int V_35 = F_37 ( & V_4 -> V_8 ) ;
F_38 ( V_4 ) ;
return V_35 ;
}
int F_39 ( struct V_3 * V_4 , struct V_23 * V_24 ,
unsigned long V_36 , void T_1 * V_28 , void T_1 * V_20 ,
void T_1 * V_29 , void T_1 * V_31 , void T_1 * V_32 ,
unsigned long V_15 )
{
int V_37 ;
if ( ! F_40 ( V_36 ) )
return - V_27 ;
V_4 -> V_6 = V_36 * 8 ;
if ( V_4 -> V_6 > V_26 )
return - V_27 ;
F_41 ( & V_4 -> V_16 ) ;
V_4 -> V_8 . V_24 = V_24 ;
V_4 -> V_8 . V_38 = F_42 ( V_24 ) ;
V_4 -> V_8 . V_39 = - 1 ;
V_4 -> V_8 . V_40 = V_4 -> V_6 ;
V_37 = F_34 ( V_4 , V_28 , V_20 , V_29 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_32 ( V_24 , V_4 , V_15 & V_41 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_35 ( V_4 , V_31 , V_32 ) ;
if ( V_37 )
return V_37 ;
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_11 ) ;
if ( V_4 -> V_8 . V_20 == F_25 &&
! ( V_15 & V_42 ) )
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_18 ) ;
if ( V_4 -> V_22 && ! ( V_15 & V_43 ) )
V_4 -> V_21 = V_4 -> V_10 ( V_4 -> V_22 ) ;
return V_37 ;
}
static void T_1 * F_43 ( struct V_44 * V_45 ,
const char * V_46 ,
T_2 V_47 ,
int * V_35 )
{
struct V_23 * V_24 = & V_45 -> V_24 ;
struct V_48 * V_49 ;
T_2 V_50 ;
T_2 V_36 ;
void T_1 * V_37 ;
* V_35 = 0 ;
V_49 = F_44 ( V_45 , V_51 , V_46 ) ;
if ( ! V_49 )
return NULL ;
V_36 = F_45 ( V_49 ) ;
if ( V_36 != V_47 ) {
* V_35 = - V_27 ;
return NULL ;
}
V_50 = V_49 -> V_50 ;
if ( ! F_46 ( V_24 , V_50 , V_36 , V_49 -> V_46 ) ) {
* V_35 = - V_52 ;
return NULL ;
}
V_37 = F_47 ( V_24 , V_50 , V_36 ) ;
if ( ! V_37 ) {
* V_35 = - V_53 ;
return NULL ;
}
return V_37 ;
}
static int F_48 ( struct V_44 * V_45 )
{
struct V_23 * V_24 = & V_45 -> V_24 ;
struct V_48 * V_49 ;
void T_1 * V_28 ;
void T_1 * V_20 ;
void T_1 * V_29 ;
void T_1 * V_31 ;
void T_1 * V_32 ;
unsigned long V_36 ;
unsigned long V_15 = 0 ;
int V_35 ;
struct V_3 * V_4 ;
struct V_54 * V_55 = F_49 ( V_24 ) ;
V_49 = F_44 ( V_45 , V_51 , L_2 ) ;
if ( ! V_49 )
return - V_27 ;
V_36 = F_45 ( V_49 ) ;
V_28 = F_43 ( V_45 , L_2 , V_36 , & V_35 ) ;
if ( ! V_28 )
return V_35 ? V_35 : - V_27 ;
V_20 = F_43 ( V_45 , L_3 , V_36 , & V_35 ) ;
if ( V_35 )
return V_35 ;
V_29 = F_43 ( V_45 , L_4 , V_36 , & V_35 ) ;
if ( V_35 )
return V_35 ;
V_31 = F_43 ( V_45 , L_5 , V_36 , & V_35 ) ;
if ( V_35 )
return V_35 ;
V_32 = F_43 ( V_45 , L_6 , V_36 , & V_35 ) ;
if ( V_35 )
return V_35 ;
if ( ! strcmp ( F_50 ( V_45 ) -> V_46 , L_7 ) )
V_15 |= V_41 ;
V_4 = F_51 ( & V_45 -> V_24 , sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 )
return - V_53 ;
V_35 = F_39 ( V_4 , V_24 , V_36 , V_28 , V_20 , V_29 , V_31 , V_32 , V_15 ) ;
if ( V_35 )
return V_35 ;
if ( V_55 ) {
V_4 -> V_8 . V_39 = V_55 -> V_39 ;
if ( V_55 -> V_40 > 0 )
V_4 -> V_8 . V_40 = V_55 -> V_40 ;
}
F_52 ( V_45 , V_4 ) ;
return F_53 ( & V_4 -> V_8 ) ;
}
static int F_54 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_55 ( V_45 ) ;
return F_36 ( V_4 ) ;
}
