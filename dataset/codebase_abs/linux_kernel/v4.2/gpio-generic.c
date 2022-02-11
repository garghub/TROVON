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
return V_4 -> V_13 ( V_4 -> V_14 ) & V_10 ;
else
return V_4 -> V_13 ( V_4 -> V_15 ) & V_10 ;
}
static int F_29 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
return ! ! ( V_4 -> V_13 ( V_4 -> V_15 ) & V_4 -> V_11 ( V_4 , V_9 ) ) ;
}
static void F_30 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_17 = V_4 -> V_11 ( V_4 , V_9 ) ;
unsigned long V_18 ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
if ( V_16 )
V_4 -> V_2 |= V_17 ;
else
V_4 -> V_2 &= ~ V_17 ;
V_4 -> V_20 ( V_4 -> V_15 , V_4 -> V_2 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_33 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_17 = V_4 -> V_11 ( V_4 , V_9 ) ;
if ( V_16 )
V_4 -> V_20 ( V_4 -> V_14 , V_17 ) ;
else
V_4 -> V_20 ( V_4 -> V_21 , V_17 ) ;
}
static void F_34 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_17 = V_4 -> V_11 ( V_4 , V_9 ) ;
unsigned long V_18 ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
if ( V_16 )
V_4 -> V_2 |= V_17 ;
else
V_4 -> V_2 &= ~ V_17 ;
V_4 -> V_20 ( V_4 -> V_14 , V_4 -> V_2 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_35 ( struct V_3 * V_4 ,
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
if ( F_36 ( V_24 , V_17 ) ) {
if ( F_37 ( V_24 , V_6 ) )
* V_22 |= V_4 -> V_11 ( V_4 , V_24 ) ;
else
* V_23 |= V_4 -> V_11 ( V_4 , V_24 ) ;
}
}
}
static void F_38 ( struct V_3 * V_4 ,
unsigned long * V_17 ,
unsigned long * V_6 ,
void T_1 * V_1 )
{
unsigned long V_18 ;
unsigned long V_22 , V_23 ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
F_35 ( V_4 , V_17 , V_6 , & V_22 , & V_23 ) ;
V_4 -> V_2 |= V_22 ;
V_4 -> V_2 &= ~ V_23 ;
V_4 -> V_20 ( V_1 , V_4 -> V_2 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_39 ( struct V_7 * V_8 , unsigned long * V_17 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
F_38 ( V_4 , V_17 , V_6 , V_4 -> V_15 ) ;
}
static void F_40 ( struct V_7 * V_8 , unsigned long * V_17 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
F_38 ( V_4 , V_17 , V_6 , V_4 -> V_14 ) ;
}
static void F_41 ( struct V_7 * V_8 ,
unsigned long * V_17 ,
unsigned long * V_6 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_22 , V_23 ;
F_35 ( V_4 , V_17 , V_6 , & V_22 , & V_23 ) ;
if ( V_22 )
V_4 -> V_20 ( V_4 -> V_14 , V_22 ) ;
if ( V_23 )
V_4 -> V_20 ( V_4 -> V_21 , V_23 ) ;
}
static int F_42 ( struct V_7 * V_8 , unsigned int V_9 )
{
return 0 ;
}
static int F_43 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_16 )
{
V_8 -> V_25 ( V_8 , V_9 , V_16 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 &= ~ V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_26 , V_4 -> V_12 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
V_8 -> V_25 ( V_8 , V_9 , V_16 ) ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 |= V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_26 , V_4 -> V_12 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_46 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 |= V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_26 , V_4 -> V_12 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_47 ( struct V_7 * V_8 , unsigned int V_9 , int V_16 )
{
struct V_3 * V_4 = F_28 ( V_8 ) ;
unsigned long V_18 ;
V_8 -> V_25 ( V_8 , V_9 , V_16 ) ;
F_31 ( & V_4 -> V_19 , V_18 ) ;
V_4 -> V_12 &= ~ V_4 -> V_11 ( V_4 , V_9 ) ;
V_4 -> V_20 ( V_4 -> V_26 , V_4 -> V_12 ) ;
F_32 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_48 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
bool V_29 ,
bool V_30 )
{
switch ( V_4 -> V_6 ) {
case 8 :
V_4 -> V_13 = F_3 ;
V_4 -> V_20 = F_1 ;
break;
case 16 :
if ( V_30 ) {
V_4 -> V_13 = F_19 ;
V_4 -> V_20 = F_17 ;
} else {
V_4 -> V_13 = F_7 ;
V_4 -> V_20 = F_5 ;
}
break;
case 32 :
if ( V_30 ) {
V_4 -> V_13 = F_23 ;
V_4 -> V_20 = F_21 ;
} else {
V_4 -> V_13 = F_11 ;
V_4 -> V_20 = F_9 ;
}
break;
#if V_31 >= 64
case 64 :
if ( V_30 ) {
F_49 ( V_28 ,
L_1 ) ;
return - V_32 ;
} else {
V_4 -> V_13 = F_15 ;
V_4 -> V_20 = F_13 ;
}
break;
#endif
default:
F_49 ( V_28 , L_2 , V_4 -> V_6 ) ;
return - V_32 ;
}
V_4 -> V_11 = V_29 ? F_26 : F_25 ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
void T_1 * V_33 ,
void T_1 * V_25 ,
void T_1 * V_34 ,
unsigned long V_18 )
{
V_4 -> V_15 = V_33 ;
if ( ! V_4 -> V_15 )
return - V_32 ;
if ( V_25 && V_34 ) {
V_4 -> V_14 = V_25 ;
V_4 -> V_21 = V_34 ;
V_4 -> V_8 . V_25 = F_33 ;
V_4 -> V_8 . V_35 = F_41 ;
} else if ( V_25 && ! V_34 ) {
V_4 -> V_14 = V_25 ;
V_4 -> V_8 . V_25 = F_34 ;
V_4 -> V_8 . V_35 = F_40 ;
} else {
V_4 -> V_8 . V_25 = F_30 ;
V_4 -> V_8 . V_35 = F_39 ;
}
if ( ! ( V_18 & V_36 ) &&
( V_18 & V_37 ) )
V_4 -> V_8 . V_38 = F_27 ;
else
V_4 -> V_8 . V_38 = F_29 ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
void T_1 * V_39 ,
void T_1 * V_40 )
{
if ( V_39 && V_40 ) {
return - V_32 ;
} else if ( V_39 ) {
V_4 -> V_26 = V_39 ;
V_4 -> V_8 . V_41 = F_45 ;
V_4 -> V_8 . V_42 = F_44 ;
} else if ( V_40 ) {
V_4 -> V_26 = V_40 ;
V_4 -> V_8 . V_41 = F_47 ;
V_4 -> V_8 . V_42 = F_46 ;
} else {
V_4 -> V_8 . V_41 = F_43 ;
V_4 -> V_8 . V_42 = F_42 ;
}
return 0 ;
}
static int F_52 ( struct V_7 * V_43 , unsigned V_44 )
{
if ( V_44 < V_43 -> V_45 )
return 0 ;
return - V_32 ;
}
int F_53 ( struct V_3 * V_4 )
{
F_54 ( & V_4 -> V_8 ) ;
return 0 ;
}
int F_55 ( struct V_3 * V_4 , struct V_27 * V_28 ,
unsigned long V_46 , void T_1 * V_33 , void T_1 * V_25 ,
void T_1 * V_34 , void T_1 * V_39 , void T_1 * V_40 ,
unsigned long V_18 )
{
int V_47 ;
if ( ! F_56 ( V_46 ) )
return - V_32 ;
V_4 -> V_6 = V_46 * 8 ;
if ( V_4 -> V_6 > V_31 )
return - V_32 ;
F_57 ( & V_4 -> V_19 ) ;
V_4 -> V_8 . V_28 = V_28 ;
V_4 -> V_8 . V_48 = F_58 ( V_28 ) ;
V_4 -> V_8 . V_49 = - 1 ;
V_4 -> V_8 . V_45 = V_4 -> V_6 ;
V_4 -> V_8 . V_50 = F_52 ;
V_47 = F_50 ( V_4 , V_33 , V_25 , V_34 , V_18 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_28 , V_4 , V_18 & V_51 ,
V_18 & V_52 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_51 ( V_4 , V_39 , V_40 ) ;
if ( V_47 )
return V_47 ;
V_4 -> V_2 = V_4 -> V_13 ( V_4 -> V_15 ) ;
if ( V_4 -> V_8 . V_25 == F_34 &&
! ( V_18 & V_36 ) )
V_4 -> V_2 = V_4 -> V_13 ( V_4 -> V_14 ) ;
if ( V_4 -> V_26 && ! ( V_18 & V_53 ) )
V_4 -> V_12 = V_4 -> V_13 ( V_4 -> V_26 ) ;
return V_47 ;
}
static void T_1 * F_59 ( struct V_54 * V_55 ,
const char * V_56 ,
T_2 V_57 ,
int * V_58 )
{
struct V_27 * V_28 = & V_55 -> V_28 ;
struct V_59 * V_60 ;
T_2 V_61 ;
T_2 V_46 ;
void T_1 * V_47 ;
* V_58 = 0 ;
V_60 = F_60 ( V_55 , V_62 , V_56 ) ;
if ( ! V_60 )
return NULL ;
V_46 = F_61 ( V_60 ) ;
if ( V_46 != V_57 ) {
* V_58 = - V_32 ;
return NULL ;
}
V_61 = V_60 -> V_61 ;
if ( ! F_62 ( V_28 , V_61 , V_46 , V_60 -> V_56 ) ) {
* V_58 = - V_63 ;
return NULL ;
}
V_47 = F_63 ( V_28 , V_61 , V_46 ) ;
if ( ! V_47 ) {
* V_58 = - V_64 ;
return NULL ;
}
return V_47 ;
}
static int F_64 ( struct V_54 * V_55 )
{
struct V_27 * V_28 = & V_55 -> V_28 ;
struct V_59 * V_60 ;
void T_1 * V_33 ;
void T_1 * V_25 ;
void T_1 * V_34 ;
void T_1 * V_39 ;
void T_1 * V_40 ;
unsigned long V_46 ;
unsigned long V_18 = V_55 -> V_65 -> V_66 ;
int V_58 ;
struct V_3 * V_4 ;
struct V_67 * V_68 = F_65 ( V_28 ) ;
V_60 = F_60 ( V_55 , V_62 , L_3 ) ;
if ( ! V_60 )
return - V_32 ;
V_46 = F_61 ( V_60 ) ;
V_33 = F_59 ( V_55 , L_3 , V_46 , & V_58 ) ;
if ( ! V_33 )
return V_58 ? V_58 : - V_32 ;
V_25 = F_59 ( V_55 , L_4 , V_46 , & V_58 ) ;
if ( V_58 )
return V_58 ;
V_34 = F_59 ( V_55 , L_5 , V_46 , & V_58 ) ;
if ( V_58 )
return V_58 ;
V_39 = F_59 ( V_55 , L_6 , V_46 , & V_58 ) ;
if ( V_58 )
return V_58 ;
V_40 = F_59 ( V_55 , L_7 , V_46 , & V_58 ) ;
if ( V_58 )
return V_58 ;
V_4 = F_66 ( & V_55 -> V_28 , sizeof( * V_4 ) , V_69 ) ;
if ( ! V_4 )
return - V_64 ;
V_58 = F_55 ( V_4 , V_28 , V_46 , V_33 , V_25 , V_34 , V_39 , V_40 , V_18 ) ;
if ( V_58 )
return V_58 ;
if ( V_68 ) {
if ( V_68 -> V_48 )
V_4 -> V_8 . V_48 = V_68 -> V_48 ;
V_4 -> V_8 . V_49 = V_68 -> V_49 ;
if ( V_68 -> V_45 > 0 )
V_4 -> V_8 . V_45 = V_68 -> V_45 ;
}
F_67 ( V_55 , V_4 ) ;
return F_68 ( & V_4 -> V_8 ) ;
}
static int F_69 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = F_70 ( V_55 ) ;
return F_53 ( V_4 ) ;
}
