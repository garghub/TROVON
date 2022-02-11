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
return F_26 ( V_5 ) ;
}
static unsigned long F_27 ( struct V_3 * V_4 ,
unsigned int V_5 )
{
return F_26 ( V_4 -> V_6 - 1 - V_5 ) ;
}
static int F_28 ( struct V_3 * V_4 , unsigned int V_7 )
{
unsigned long V_8 = V_4 -> V_9 ( V_4 , V_7 ) ;
if ( V_4 -> V_10 & V_8 )
return ! ! ( V_4 -> V_11 ( V_4 -> V_12 ) & V_8 ) ;
else
return ! ! ( V_4 -> V_11 ( V_4 -> V_13 ) & V_8 ) ;
}
static int F_29 ( struct V_3 * V_4 , unsigned int V_7 )
{
return ! ! ( V_4 -> V_11 ( V_4 -> V_13 ) & V_4 -> V_9 ( V_4 , V_7 ) ) ;
}
static void F_30 ( struct V_3 * V_4 , unsigned int V_7 , int V_14 )
{
}
static void F_31 ( struct V_3 * V_4 , unsigned int V_7 , int V_14 )
{
unsigned long V_15 = V_4 -> V_9 ( V_4 , V_7 ) ;
unsigned long V_16 ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
if ( V_14 )
V_4 -> V_18 |= V_15 ;
else
V_4 -> V_18 &= ~ V_15 ;
V_4 -> V_19 ( V_4 -> V_13 , V_4 -> V_18 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
}
static void F_34 ( struct V_3 * V_4 , unsigned int V_7 ,
int V_14 )
{
unsigned long V_15 = V_4 -> V_9 ( V_4 , V_7 ) ;
if ( V_14 )
V_4 -> V_19 ( V_4 -> V_12 , V_15 ) ;
else
V_4 -> V_19 ( V_4 -> V_20 , V_15 ) ;
}
static void F_35 ( struct V_3 * V_4 , unsigned int V_7 , int V_14 )
{
unsigned long V_15 = V_4 -> V_9 ( V_4 , V_7 ) ;
unsigned long V_16 ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
if ( V_14 )
V_4 -> V_18 |= V_15 ;
else
V_4 -> V_18 &= ~ V_15 ;
V_4 -> V_19 ( V_4 -> V_12 , V_4 -> V_18 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
}
static void F_36 ( struct V_3 * V_4 ,
unsigned long * V_15 , unsigned long * V_21 ,
unsigned long * V_22 ,
unsigned long * V_23 )
{
int V_24 ;
* V_22 = 0 ;
* V_23 = 0 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_6 ; V_24 ++ ) {
if ( * V_15 == 0 )
break;
if ( F_37 ( V_24 , V_15 ) ) {
if ( F_38 ( V_24 , V_21 ) )
* V_22 |= V_4 -> V_9 ( V_4 , V_24 ) ;
else
* V_23 |= V_4 -> V_9 ( V_4 , V_24 ) ;
}
}
}
static void F_39 ( struct V_3 * V_4 ,
unsigned long * V_15 ,
unsigned long * V_21 ,
void T_1 * V_1 )
{
unsigned long V_16 ;
unsigned long V_22 , V_23 ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
F_36 ( V_4 , V_15 , V_21 , & V_22 , & V_23 ) ;
V_4 -> V_18 |= V_22 ;
V_4 -> V_18 &= ~ V_23 ;
V_4 -> V_19 ( V_1 , V_4 -> V_18 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
}
static void F_40 ( struct V_3 * V_4 , unsigned long * V_15 ,
unsigned long * V_21 )
{
F_39 ( V_4 , V_15 , V_21 , V_4 -> V_13 ) ;
}
static void F_41 ( struct V_3 * V_4 , unsigned long * V_15 ,
unsigned long * V_21 )
{
F_39 ( V_4 , V_15 , V_21 , V_4 -> V_12 ) ;
}
static void F_42 ( struct V_3 * V_4 ,
unsigned long * V_15 ,
unsigned long * V_21 )
{
unsigned long V_22 , V_23 ;
F_36 ( V_4 , V_15 , V_21 , & V_22 , & V_23 ) ;
if ( V_22 )
V_4 -> V_19 ( V_4 -> V_12 , V_22 ) ;
if ( V_23 )
V_4 -> V_19 ( V_4 -> V_20 , V_23 ) ;
}
static int F_43 ( struct V_3 * V_4 , unsigned int V_7 )
{
return 0 ;
}
static int F_44 ( struct V_3 * V_4 , unsigned int V_7 ,
int V_14 )
{
return - V_25 ;
}
static int F_45 ( struct V_3 * V_4 , unsigned int V_7 ,
int V_14 )
{
V_4 -> V_26 ( V_4 , V_7 , V_14 ) ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 , unsigned int V_7 )
{
unsigned long V_16 ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
V_4 -> V_10 &= ~ V_4 -> V_9 ( V_4 , V_7 ) ;
V_4 -> V_19 ( V_4 -> V_27 , V_4 -> V_10 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , unsigned int V_7 )
{
return ! ( V_4 -> V_11 ( V_4 -> V_27 ) & V_4 -> V_9 ( V_4 , V_7 ) ) ;
}
static int F_48 ( struct V_3 * V_4 , unsigned int V_7 , int V_14 )
{
unsigned long V_16 ;
V_4 -> V_26 ( V_4 , V_7 , V_14 ) ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
V_4 -> V_10 |= V_4 -> V_9 ( V_4 , V_7 ) ;
V_4 -> V_19 ( V_4 -> V_27 , V_4 -> V_10 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , unsigned int V_7 )
{
unsigned long V_16 ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
V_4 -> V_10 |= V_4 -> V_9 ( V_4 , V_7 ) ;
V_4 -> V_19 ( V_4 -> V_27 , V_4 -> V_10 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 , unsigned int V_7 , int V_14 )
{
unsigned long V_16 ;
V_4 -> V_26 ( V_4 , V_7 , V_14 ) ;
F_32 ( & V_4 -> V_17 , V_16 ) ;
V_4 -> V_10 &= ~ V_4 -> V_9 ( V_4 , V_7 ) ;
V_4 -> V_19 ( V_4 -> V_27 , V_4 -> V_10 ) ;
F_33 ( & V_4 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , unsigned int V_7 )
{
return ! ! ( V_4 -> V_11 ( V_4 -> V_27 ) & V_4 -> V_9 ( V_4 , V_7 ) ) ;
}
static int F_52 ( struct V_28 * V_29 ,
struct V_3 * V_4 ,
bool V_30 ,
bool V_31 )
{
switch ( V_4 -> V_6 ) {
case 8 :
V_4 -> V_11 = F_3 ;
V_4 -> V_19 = F_1 ;
break;
case 16 :
if ( V_31 ) {
V_4 -> V_11 = F_19 ;
V_4 -> V_19 = F_17 ;
} else {
V_4 -> V_11 = F_7 ;
V_4 -> V_19 = F_5 ;
}
break;
case 32 :
if ( V_31 ) {
V_4 -> V_11 = F_23 ;
V_4 -> V_19 = F_21 ;
} else {
V_4 -> V_11 = F_11 ;
V_4 -> V_19 = F_9 ;
}
break;
#if V_32 >= 64
case 64 :
if ( V_31 ) {
F_53 ( V_29 ,
L_1 ) ;
return - V_25 ;
} else {
V_4 -> V_11 = F_15 ;
V_4 -> V_19 = F_13 ;
}
break;
#endif
default:
F_53 ( V_29 , L_2 , V_4 -> V_6 ) ;
return - V_25 ;
}
V_4 -> V_9 = V_30 ? F_27 : F_25 ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
void T_1 * V_33 ,
void T_1 * V_26 ,
void T_1 * V_34 ,
unsigned long V_16 )
{
V_4 -> V_13 = V_33 ;
if ( ! V_4 -> V_13 )
return - V_25 ;
if ( V_26 && V_34 ) {
V_4 -> V_12 = V_26 ;
V_4 -> V_20 = V_34 ;
V_4 -> V_26 = F_34 ;
V_4 -> V_35 = F_42 ;
} else if ( V_26 && ! V_34 ) {
V_4 -> V_12 = V_26 ;
V_4 -> V_26 = F_35 ;
V_4 -> V_35 = F_41 ;
} else if ( V_16 & V_36 ) {
V_4 -> V_26 = F_30 ;
V_4 -> V_35 = NULL ;
} else {
V_4 -> V_26 = F_31 ;
V_4 -> V_35 = F_40 ;
}
if ( ! ( V_16 & V_37 ) &&
( V_16 & V_38 ) )
V_4 -> V_39 = F_28 ;
else
V_4 -> V_39 = F_29 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
void T_1 * V_40 ,
void T_1 * V_41 ,
unsigned long V_16 )
{
if ( V_40 && V_41 ) {
return - V_25 ;
} else if ( V_40 ) {
V_4 -> V_27 = V_40 ;
V_4 -> V_42 = F_48 ;
V_4 -> V_43 = F_46 ;
V_4 -> V_44 = F_47 ;
} else if ( V_41 ) {
V_4 -> V_27 = V_41 ;
V_4 -> V_42 = F_50 ;
V_4 -> V_43 = F_49 ;
V_4 -> V_44 = F_51 ;
} else {
if ( V_16 & V_36 )
V_4 -> V_42 = F_44 ;
else
V_4 -> V_42 = F_45 ;
V_4 -> V_43 = F_43 ;
}
return 0 ;
}
static int F_56 ( struct V_3 * V_45 , unsigned V_46 )
{
if ( V_46 < V_45 -> V_47 )
return 0 ;
return - V_25 ;
}
int F_57 ( struct V_3 * V_4 , struct V_28 * V_29 ,
unsigned long V_48 , void T_1 * V_33 , void T_1 * V_26 ,
void T_1 * V_34 , void T_1 * V_40 , void T_1 * V_41 ,
unsigned long V_16 )
{
int V_49 ;
if ( ! F_58 ( V_48 ) )
return - V_25 ;
V_4 -> V_6 = V_48 * 8 ;
if ( V_4 -> V_6 > V_32 )
return - V_25 ;
F_59 ( & V_4 -> V_17 ) ;
V_4 -> V_50 = V_29 ;
V_4 -> V_51 = F_60 ( V_29 ) ;
V_4 -> V_52 = - 1 ;
V_4 -> V_47 = V_4 -> V_6 ;
V_4 -> V_53 = F_56 ;
V_49 = F_54 ( V_4 , V_33 , V_26 , V_34 , V_16 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_52 ( V_29 , V_4 , V_16 & V_54 ,
V_16 & V_55 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_55 ( V_4 , V_40 , V_41 , V_16 ) ;
if ( V_49 )
return V_49 ;
V_4 -> V_18 = V_4 -> V_11 ( V_4 -> V_13 ) ;
if ( V_4 -> V_26 == F_35 &&
! ( V_16 & V_37 ) )
V_4 -> V_18 = V_4 -> V_11 ( V_4 -> V_12 ) ;
if ( V_4 -> V_27 && ! ( V_16 & V_56 ) )
V_4 -> V_10 = V_4 -> V_11 ( V_4 -> V_27 ) ;
return V_49 ;
}
static void T_1 * F_61 ( struct V_57 * V_58 ,
const char * V_59 ,
T_2 V_60 )
{
struct V_61 * V_62 ;
T_2 V_48 ;
V_62 = F_62 ( V_58 , V_63 , V_59 ) ;
if ( ! V_62 )
return NULL ;
V_48 = F_63 ( V_62 ) ;
if ( V_48 != V_60 )
return F_64 ( - V_25 ) ;
return F_65 ( & V_58 -> V_29 , V_62 ) ;
}
static int F_66 ( struct V_57 * V_58 )
{
struct V_28 * V_29 = & V_58 -> V_29 ;
struct V_61 * V_62 ;
void T_1 * V_33 ;
void T_1 * V_26 ;
void T_1 * V_34 ;
void T_1 * V_40 ;
void T_1 * V_41 ;
unsigned long V_48 ;
unsigned long V_16 = V_58 -> V_64 -> V_65 ;
int V_66 ;
struct V_3 * V_4 ;
struct V_67 * V_68 = F_67 ( V_29 ) ;
V_62 = F_62 ( V_58 , V_63 , L_3 ) ;
if ( ! V_62 )
return - V_25 ;
V_48 = F_63 ( V_62 ) ;
V_33 = F_61 ( V_58 , L_3 , V_48 ) ;
if ( F_68 ( V_33 ) )
return F_69 ( V_33 ) ;
V_26 = F_61 ( V_58 , L_4 , V_48 ) ;
if ( F_68 ( V_26 ) )
return F_69 ( V_26 ) ;
V_34 = F_61 ( V_58 , L_5 , V_48 ) ;
if ( F_68 ( V_34 ) )
return F_69 ( V_34 ) ;
V_40 = F_61 ( V_58 , L_6 , V_48 ) ;
if ( F_68 ( V_40 ) )
return F_69 ( V_40 ) ;
V_41 = F_61 ( V_58 , L_7 , V_48 ) ;
if ( F_68 ( V_41 ) )
return F_69 ( V_41 ) ;
V_4 = F_70 ( & V_58 -> V_29 , sizeof( * V_4 ) , V_69 ) ;
if ( ! V_4 )
return - V_70 ;
V_66 = F_57 ( V_4 , V_29 , V_48 , V_33 , V_26 , V_34 , V_40 , V_41 , V_16 ) ;
if ( V_66 )
return V_66 ;
if ( V_68 ) {
if ( V_68 -> V_51 )
V_4 -> V_51 = V_68 -> V_51 ;
V_4 -> V_52 = V_68 -> V_52 ;
if ( V_68 -> V_47 > 0 )
V_4 -> V_47 = V_68 -> V_47 ;
}
F_71 ( V_58 , V_4 ) ;
return F_72 ( V_4 , NULL ) ;
}
static int F_73 ( struct V_57 * V_58 )
{
struct V_3 * V_4 = F_74 ( V_58 ) ;
F_75 ( V_4 ) ;
return 0 ;
}
