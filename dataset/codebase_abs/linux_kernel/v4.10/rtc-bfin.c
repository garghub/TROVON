static inline T_1 F_1 ( unsigned long V_1 )
{
T_1 V_2 = ( V_1 % 60 ) ;
T_1 V_3 = ( V_1 % ( 60 * 60 ) ) / 60 ;
T_1 V_4 = ( V_1 % ( 60 * 60 * 24 ) ) / ( 60 * 60 ) ;
T_1 V_5 = ( V_1 / ( 60 * 60 * 24 ) ) ;
return ( V_2 << V_6 ) +
( V_3 << V_7 ) +
( V_4 << V_8 ) +
( V_5 << V_9 ) ;
}
static inline unsigned long F_2 ( T_1 V_10 )
{
return ( ( ( V_10 >> V_6 ) & 0x003F ) ) +
( ( ( V_10 >> V_7 ) & 0x003F ) * 60 ) +
( ( ( V_10 >> V_8 ) & 0x001F ) * 60 * 60 ) +
( ( ( V_10 >> V_9 ) & 0x7FFF ) * 60 * 60 * 24 ) ;
}
static inline void F_3 ( T_1 V_10 , struct V_11 * V_12 )
{
F_4 ( F_2 ( V_10 ) , V_12 ) ;
}
static void F_5 ( struct V_13 * V_14 )
{
F_6 ( V_14 ) ;
while ( F_7 () & V_15 )
F_8 ( & V_16 , V_17 * 5 ) ;
F_6 ( V_14 ) ;
}
static void F_9 ( struct V_13 * V_14 , T_2 V_18 )
{
struct V_19 * V_20 = F_10 ( V_14 ) ;
F_6 ( V_14 ) ;
F_5 ( V_14 ) ;
F_11 ( 0x1 ) ;
F_12 ( V_18 ) ;
F_13 ( 0 ) ;
F_14 ( 0xFFFF ) ;
V_20 -> V_21 = 0 ;
}
static T_3 F_15 ( int V_22 , void * V_23 )
{
struct V_13 * V_14 = V_23 ;
struct V_19 * V_20 = F_10 ( V_14 ) ;
unsigned long V_24 = 0 ;
bool V_25 = false ;
T_2 V_26 , V_27 , V_18 , V_28 ;
F_6 ( V_14 ) ;
V_26 = F_7 () ;
V_18 = F_16 () ;
V_27 = 0 ;
V_28 = V_29 ;
if ( V_26 & V_28 ) {
V_27 |= V_28 ;
V_25 = true ;
F_17 ( & V_16 ) ;
}
V_28 = ( V_30 | V_31 ) ;
if ( V_18 & V_28 ) {
if ( V_26 & V_28 ) {
V_27 |= V_28 ;
V_24 |= V_32 | V_33 ;
}
}
V_28 = V_34 ;
if ( V_18 & V_28 ) {
if ( V_26 & V_28 ) {
V_27 |= V_28 ;
V_24 |= V_35 | V_33 ;
}
}
if ( V_24 )
F_18 ( V_20 -> V_36 , 1 , V_24 ) ;
if ( V_25 || V_24 ) {
F_14 ( V_27 ) ;
return V_37 ;
} else
return V_38 ;
}
static void F_19 ( T_2 V_39 )
{
F_14 ( V_39 ) ;
F_12 ( F_16 () | V_39 ) ;
}
static void F_20 ( T_2 V_39 )
{
F_12 ( F_16 () & V_39 ) ;
}
static void F_21 ( struct V_19 * V_20 )
{
F_19 ( V_20 -> V_40 . V_41 == - 1 ? V_30 : V_31 ) ;
}
static int F_22 ( struct V_13 * V_14 , unsigned int V_42 )
{
struct V_19 * V_20 = F_10 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_42 )
F_21 ( V_20 ) ;
else
F_20 ( ~ ( V_30 | V_31 ) ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 , struct V_11 * V_12 )
{
struct V_19 * V_20 = F_10 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_20 -> V_21 & 0x1 )
F_5 ( V_14 ) ;
F_3 ( F_24 () , V_12 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , struct V_11 * V_12 )
{
struct V_19 * V_20 = F_10 ( V_14 ) ;
int V_43 ;
unsigned long V_1 ;
F_6 ( V_14 ) ;
V_43 = F_26 ( V_12 , & V_1 ) ;
if ( V_43 == 0 ) {
if ( V_20 -> V_21 & 0x1 )
F_5 ( V_14 ) ;
F_27 ( F_1 ( V_1 ) ) ;
V_20 -> V_21 = 0x1 ;
}
return V_43 ;
}
static int F_28 ( struct V_13 * V_14 , struct V_44 * V_45 )
{
struct V_19 * V_20 = F_10 ( V_14 ) ;
F_6 ( V_14 ) ;
V_45 -> time = V_20 -> V_40 ;
F_5 ( V_14 ) ;
V_45 -> V_42 = ! ! ( F_16 () & ( V_30 | V_31 ) ) ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 , struct V_44 * V_45 )
{
struct V_19 * V_20 = F_10 ( V_14 ) ;
unsigned long V_40 ;
F_6 ( V_14 ) ;
if ( F_26 ( & V_45 -> time , & V_40 ) )
return - V_46 ;
V_20 -> V_40 = V_45 -> time ;
F_5 ( V_14 ) ;
F_13 ( F_1 ( V_40 ) ) ;
if ( V_45 -> V_42 )
F_21 ( V_20 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 , struct V_47 * V_48 )
{
#define F_31 ( T_4 ) ((x) ? "yes" : "no")
T_2 V_49 = F_16 () ;
F_6 ( V_14 ) ;
F_32 ( V_48 ,
L_1
L_2
L_3 ,
F_31 ( V_49 & V_30 ) ,
F_31 ( V_49 & V_31 ) ,
F_31 ( V_49 & V_34 ) ) ;
return 0 ;
#undef F_31
}
static int F_33 ( struct V_50 * V_51 )
{
struct V_19 * V_20 ;
struct V_13 * V_14 = & V_51 -> V_14 ;
int V_43 ;
unsigned long V_52 = V_53 + V_17 ;
F_6 ( V_14 ) ;
V_20 = F_34 ( V_14 , sizeof( * V_20 ) , V_54 ) ;
if ( F_35 ( ! V_20 ) )
return - V_55 ;
F_36 ( V_51 , V_20 ) ;
F_37 ( V_14 , 1 ) ;
V_20 -> V_36 = F_38 ( V_14 , V_51 -> V_56 , & V_57 ,
V_58 ) ;
if ( F_39 ( V_20 -> V_36 ) )
return F_40 ( V_20 -> V_36 ) ;
V_43 = F_41 ( V_14 , V_59 , F_15 , 0 ,
V_51 -> V_56 , V_14 ) ;
if ( F_35 ( V_43 ) )
F_42 ( & V_51 -> V_14 ,
L_4
L_5 ) ;
while ( F_7 () & V_15 )
if ( F_43 ( V_53 , V_52 ) )
break;
F_9 ( V_14 , V_29 ) ;
F_44 ( 0 ) ;
return 0 ;
}
static int F_45 ( struct V_50 * V_51 )
{
struct V_13 * V_14 = & V_51 -> V_14 ;
F_9 ( V_14 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_13 * V_14 )
{
F_6 ( V_14 ) ;
if ( F_47 ( V_14 ) ) {
F_48 ( V_59 ) ;
F_5 ( V_14 ) ;
} else
F_20 ( 0 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_14 )
{
F_6 ( V_14 ) ;
if ( F_47 ( V_14 ) )
F_50 ( V_59 ) ;
while ( ! ( F_7 () & V_34 ) )
continue;
F_19 ( V_29 ) ;
return 0 ;
}
