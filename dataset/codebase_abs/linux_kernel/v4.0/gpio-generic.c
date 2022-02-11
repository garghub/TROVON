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
static void F_34 ( struct V_3 * V_4 ,
unsigned long * V_14 , unsigned long * V_6 ,
unsigned long * V_20 ,
unsigned long * V_21 )
{
int V_22 ;
* V_20 = 0 ;
* V_21 = 0 ;
for ( V_22 = 0 ; V_22 < V_4 -> V_6 ; V_22 ++ ) {
if ( * V_14 == 0 )
break;
if ( F_35 ( V_22 , V_14 ) ) {
if ( F_36 ( V_22 , V_6 ) )
* V_20 |= V_4 -> V_12 ( V_4 , V_22 ) ;
else
* V_21 |= V_4 -> V_12 ( V_4 , V_22 ) ;
}
}
}
static void F_37 ( struct V_3 * V_4 ,
unsigned long * V_14 ,
unsigned long * V_6 ,
void T_1 * V_1 )
{
unsigned long V_15 ;
unsigned long V_20 , V_21 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
F_34 ( V_4 , V_14 , V_6 , & V_20 , & V_21 ) ;
V_4 -> V_2 |= V_20 ;
V_4 -> V_2 &= ~ V_21 ;
V_4 -> V_17 ( V_1 , V_4 -> V_2 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
}
static void F_38 ( struct V_7 * V_8 , unsigned long * V_14 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
F_37 ( V_4 , V_14 , V_6 , V_4 -> V_11 ) ;
}
static void F_39 ( struct V_7 * V_8 , unsigned long * V_14 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
F_37 ( V_4 , V_14 , V_6 , V_4 -> V_18 ) ;
}
static void F_40 ( struct V_7 * V_8 ,
unsigned long * V_14 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_20 , V_21 ;
F_34 ( V_4 , V_14 , V_6 , & V_20 , & V_21 ) ;
if ( V_20 )
V_4 -> V_17 ( V_4 -> V_18 , V_20 ) ;
if ( V_21 )
V_4 -> V_17 ( V_4 -> V_19 , V_21 ) ;
}
static int F_41 ( struct V_7 * V_8 , unsigned int V_9 )
{
return 0 ;
}
static int F_42 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_13 )
{
V_8 -> V_23 ( V_8 , V_9 , V_13 ) ;
return 0 ;
}
static int F_43 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_24 &= ~ V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_25 , V_4 -> V_24 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
V_8 -> V_23 ( V_8 , V_9 , V_13 ) ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_24 |= V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_25 , V_4 -> V_24 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_24 |= V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_25 , V_4 -> V_24 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_46 ( struct V_7 * V_8 , unsigned int V_9 , int V_13 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_15 ;
V_8 -> V_23 ( V_8 , V_9 , V_13 ) ;
F_30 ( & V_4 -> V_16 , V_15 ) ;
V_4 -> V_24 &= ~ V_4 -> V_12 ( V_4 , V_9 ) ;
V_4 -> V_17 ( V_4 -> V_25 , V_4 -> V_24 ) ;
F_31 ( & V_4 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_47 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
bool V_28 ,
bool V_29 )
{
switch ( V_4 -> V_6 ) {
case 8 :
V_4 -> V_10 = F_3 ;
V_4 -> V_17 = F_1 ;
break;
case 16 :
if ( V_29 ) {
V_4 -> V_10 = F_19 ;
V_4 -> V_17 = F_17 ;
} else {
V_4 -> V_10 = F_7 ;
V_4 -> V_17 = F_5 ;
}
break;
case 32 :
if ( V_29 ) {
V_4 -> V_10 = F_23 ;
V_4 -> V_17 = F_21 ;
} else {
V_4 -> V_10 = F_11 ;
V_4 -> V_17 = F_9 ;
}
break;
#if V_30 >= 64
case 64 :
if ( V_29 ) {
F_48 ( V_27 ,
L_1 ) ;
return - V_31 ;
} else {
V_4 -> V_10 = F_15 ;
V_4 -> V_17 = F_13 ;
}
break;
#endif
default:
F_48 ( V_27 , L_2 , V_4 -> V_6 ) ;
return - V_31 ;
}
V_4 -> V_12 = V_28 ? F_26 : F_25 ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 ,
void T_1 * V_32 ,
void T_1 * V_23 ,
void T_1 * V_33 )
{
V_4 -> V_11 = V_32 ;
if ( ! V_4 -> V_11 )
return - V_31 ;
if ( V_23 && V_33 ) {
V_4 -> V_18 = V_23 ;
V_4 -> V_19 = V_33 ;
V_4 -> V_8 . V_23 = F_32 ;
V_4 -> V_8 . V_34 = F_40 ;
} else if ( V_23 && ! V_33 ) {
V_4 -> V_18 = V_23 ;
V_4 -> V_8 . V_23 = F_33 ;
V_4 -> V_8 . V_34 = F_39 ;
} else {
V_4 -> V_8 . V_23 = F_29 ;
V_4 -> V_8 . V_34 = F_38 ;
}
V_4 -> V_8 . V_35 = F_27 ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
void T_1 * V_36 ,
void T_1 * V_37 )
{
if ( V_36 && V_37 ) {
return - V_31 ;
} else if ( V_36 ) {
V_4 -> V_25 = V_36 ;
V_4 -> V_8 . V_38 = F_44 ;
V_4 -> V_8 . V_39 = F_43 ;
} else if ( V_37 ) {
V_4 -> V_25 = V_37 ;
V_4 -> V_8 . V_38 = F_46 ;
V_4 -> V_8 . V_39 = F_45 ;
} else {
V_4 -> V_8 . V_38 = F_42 ;
V_4 -> V_8 . V_39 = F_41 ;
}
return 0 ;
}
static int F_51 ( struct V_7 * V_40 , unsigned V_41 )
{
if ( V_41 < V_40 -> V_42 )
return 0 ;
return - V_31 ;
}
int F_52 ( struct V_3 * V_4 )
{
F_53 ( & V_4 -> V_8 ) ;
return 0 ;
}
int F_54 ( struct V_3 * V_4 , struct V_26 * V_27 ,
unsigned long V_43 , void T_1 * V_32 , void T_1 * V_23 ,
void T_1 * V_33 , void T_1 * V_36 , void T_1 * V_37 ,
unsigned long V_15 )
{
int V_44 ;
if ( ! F_55 ( V_43 ) )
return - V_31 ;
V_4 -> V_6 = V_43 * 8 ;
if ( V_4 -> V_6 > V_30 )
return - V_31 ;
F_56 ( & V_4 -> V_16 ) ;
V_4 -> V_8 . V_27 = V_27 ;
V_4 -> V_8 . V_45 = F_57 ( V_27 ) ;
V_4 -> V_8 . V_46 = - 1 ;
V_4 -> V_8 . V_42 = V_4 -> V_6 ;
V_4 -> V_8 . V_47 = F_51 ;
V_44 = F_49 ( V_4 , V_32 , V_23 , V_33 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_47 ( V_27 , V_4 , V_15 & V_48 ,
V_15 & V_49 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_4 , V_36 , V_37 ) ;
if ( V_44 )
return V_44 ;
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_11 ) ;
if ( V_4 -> V_8 . V_23 == F_33 &&
! ( V_15 & V_50 ) )
V_4 -> V_2 = V_4 -> V_10 ( V_4 -> V_18 ) ;
if ( V_4 -> V_25 && ! ( V_15 & V_51 ) )
V_4 -> V_24 = V_4 -> V_10 ( V_4 -> V_25 ) ;
return V_44 ;
}
static void T_1 * F_58 ( struct V_52 * V_53 ,
const char * V_54 ,
T_2 V_55 ,
int * V_56 )
{
struct V_26 * V_27 = & V_53 -> V_27 ;
struct V_57 * V_58 ;
T_2 V_59 ;
T_2 V_43 ;
void T_1 * V_44 ;
* V_56 = 0 ;
V_58 = F_59 ( V_53 , V_60 , V_54 ) ;
if ( ! V_58 )
return NULL ;
V_43 = F_60 ( V_58 ) ;
if ( V_43 != V_55 ) {
* V_56 = - V_31 ;
return NULL ;
}
V_59 = V_58 -> V_59 ;
if ( ! F_61 ( V_27 , V_59 , V_43 , V_58 -> V_54 ) ) {
* V_56 = - V_61 ;
return NULL ;
}
V_44 = F_62 ( V_27 , V_59 , V_43 ) ;
if ( ! V_44 ) {
* V_56 = - V_62 ;
return NULL ;
}
return V_44 ;
}
static int F_63 ( struct V_52 * V_53 )
{
struct V_26 * V_27 = & V_53 -> V_27 ;
struct V_57 * V_58 ;
void T_1 * V_32 ;
void T_1 * V_23 ;
void T_1 * V_33 ;
void T_1 * V_36 ;
void T_1 * V_37 ;
unsigned long V_43 ;
unsigned long V_15 = V_53 -> V_63 -> V_64 ;
int V_56 ;
struct V_3 * V_4 ;
struct V_65 * V_66 = F_64 ( V_27 ) ;
V_58 = F_59 ( V_53 , V_60 , L_3 ) ;
if ( ! V_58 )
return - V_31 ;
V_43 = F_60 ( V_58 ) ;
V_32 = F_58 ( V_53 , L_3 , V_43 , & V_56 ) ;
if ( ! V_32 )
return V_56 ? V_56 : - V_31 ;
V_23 = F_58 ( V_53 , L_4 , V_43 , & V_56 ) ;
if ( V_56 )
return V_56 ;
V_33 = F_58 ( V_53 , L_5 , V_43 , & V_56 ) ;
if ( V_56 )
return V_56 ;
V_36 = F_58 ( V_53 , L_6 , V_43 , & V_56 ) ;
if ( V_56 )
return V_56 ;
V_37 = F_58 ( V_53 , L_7 , V_43 , & V_56 ) ;
if ( V_56 )
return V_56 ;
V_4 = F_65 ( & V_53 -> V_27 , sizeof( * V_4 ) , V_67 ) ;
if ( ! V_4 )
return - V_62 ;
V_56 = F_54 ( V_4 , V_27 , V_43 , V_32 , V_23 , V_33 , V_36 , V_37 , V_15 ) ;
if ( V_56 )
return V_56 ;
if ( V_66 ) {
if ( V_66 -> V_45 )
V_4 -> V_8 . V_45 = V_66 -> V_45 ;
V_4 -> V_8 . V_46 = V_66 -> V_46 ;
if ( V_66 -> V_42 > 0 )
V_4 -> V_8 . V_42 = V_66 -> V_42 ;
}
F_66 ( V_53 , V_4 ) ;
return F_67 ( & V_4 -> V_8 ) ;
}
static int F_68 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = F_69 ( V_53 ) ;
return F_52 ( V_4 ) ;
}
