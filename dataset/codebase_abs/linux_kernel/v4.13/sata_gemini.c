struct V_1 * F_1 ( void )
{
if ( V_2 )
return V_2 ;
return F_2 ( - V_3 ) ;
}
bool F_3 ( struct V_1 * V_4 , bool V_5 )
{
if ( ! V_4 -> V_6 )
return false ;
if ( ( V_4 -> V_7 == V_8 ) &&
! V_5 )
return false ;
if ( ( V_4 -> V_7 == V_9 ) &&
V_5 )
return false ;
return true ;
}
enum V_10 F_4 ( struct V_1 * V_4 )
{
return V_4 -> V_7 ;
}
static int F_5 ( struct V_1 * V_4 ,
unsigned int V_11 )
{
unsigned long V_12 = V_13 + ( V_14 * 1 ) ;
bool V_15 ;
T_1 V_16 ;
if ( V_11 == 0 ) {
V_16 = V_17 | V_18 ;
if ( V_4 -> V_7 == V_8 )
V_16 |= V_19 ;
F_6 ( V_16 , V_4 -> V_20 + V_21 ) ;
} else {
V_16 = V_17 | V_18 ;
if ( V_4 -> V_7 == V_9 )
V_16 |= V_19 ;
F_6 ( V_16 , V_4 -> V_20 + V_22 ) ;
}
F_7 ( 10 ) ;
do {
F_7 ( 100 ) ;
if ( V_11 == 0 )
V_16 = F_8 ( V_4 -> V_20 + V_23 ) ;
else
V_16 = F_8 ( V_4 -> V_20 + V_24 ) ;
if ( V_16 & V_25 )
break;
} while ( F_9 ( V_13 , V_12 ) );
V_15 = ! ! ( V_16 & V_25 ) ;
F_10 ( V_4 -> V_26 , L_1 , V_11 ,
V_15 ? L_2 : L_3 ) ;
return V_15 ? 0 : - V_27 ;
}
int F_11 ( struct V_1 * V_4 , unsigned int V_11 )
{
struct V_28 * V_29 ;
int V_30 ;
if ( V_11 == 0 )
V_29 = V_4 -> V_31 ;
else
V_29 = V_4 -> V_32 ;
F_12 ( V_29 ) ;
F_7 ( 10 ) ;
V_30 = F_5 ( V_4 , V_11 ) ;
if ( V_30 )
F_13 ( V_29 ) ;
return V_30 ;
}
void F_14 ( struct V_1 * V_4 , unsigned int V_11 )
{
if ( V_11 == 0 )
F_13 ( V_4 -> V_31 ) ;
else if ( V_11 == 1 )
F_13 ( V_4 -> V_32 ) ;
}
int F_15 ( struct V_1 * V_4 ,
unsigned int V_11 )
{
if ( V_11 == 0 )
F_16 ( V_4 -> V_33 ) ;
else
F_16 ( V_4 -> V_34 ) ;
F_7 ( 10 ) ;
return F_5 ( V_4 , V_11 ) ;
}
static int F_17 ( struct V_1 * V_4 )
{
struct V_35 * V_26 = V_4 -> V_26 ;
T_1 V_36 , V_37 ;
int V_30 ;
V_4 -> V_31 = F_18 ( V_26 , L_4 ) ;
if ( F_19 ( V_4 -> V_31 ) ) {
F_20 ( V_26 , L_5 ) ;
return - V_27 ;
}
V_4 -> V_32 = F_18 ( V_26 , L_6 ) ;
if ( F_19 ( V_4 -> V_32 ) ) {
F_20 ( V_26 , L_7 ) ;
return - V_27 ;
}
V_30 = F_21 ( V_4 -> V_31 ) ;
if ( V_30 ) {
F_22 ( L_8 ) ;
return V_30 ;
}
V_30 = F_21 ( V_4 -> V_32 ) ;
if ( V_30 ) {
F_22 ( L_9 ) ;
F_23 ( V_4 -> V_31 ) ;
return V_30 ;
}
V_4 -> V_33 = F_24 ( V_26 , L_10 ) ;
if ( F_19 ( V_4 -> V_33 ) ) {
F_20 ( V_26 , L_11 ) ;
F_23 ( V_4 -> V_32 ) ;
F_23 ( V_4 -> V_31 ) ;
return F_25 ( V_4 -> V_33 ) ;
}
V_4 -> V_34 = F_24 ( V_26 , L_12 ) ;
if ( F_19 ( V_4 -> V_34 ) ) {
F_20 ( V_26 , L_13 ) ;
F_23 ( V_4 -> V_32 ) ;
F_23 ( V_4 -> V_31 ) ;
return F_25 ( V_4 -> V_34 ) ;
}
V_36 = F_8 ( V_4 -> V_20 + V_38 ) ;
V_37 = F_8 ( V_4 -> V_20 + V_39 ) ;
V_4 -> V_6 = true ;
F_13 ( V_4 -> V_31 ) ;
F_13 ( V_4 -> V_32 ) ;
F_10 ( V_26 , L_14 , V_36 , V_37 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_35 * V_26 = & V_41 -> V_26 ;
struct V_42 * V_43 = V_26 -> V_44 ;
struct V_1 * V_4 ;
static struct V_45 * V_46 ;
struct V_47 * V_48 ;
enum V_10 V_7 ;
T_1 V_49 ;
T_1 V_50 ;
T_1 V_16 ;
int V_30 ;
V_4 = F_27 ( V_26 , sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_26 = V_26 ;
V_48 = F_28 ( V_41 , V_53 , 0 ) ;
if ( ! V_48 )
return - V_27 ;
V_4 -> V_20 = F_29 ( V_26 , V_48 ) ;
if ( F_19 ( V_4 -> V_20 ) )
return F_25 ( V_4 -> V_20 ) ;
V_46 = F_30 ( V_43 , L_15 ) ;
if ( F_19 ( V_46 ) ) {
F_20 ( V_26 , L_16 ) ;
return F_25 ( V_46 ) ;
}
if ( F_31 ( V_43 , L_17 ) ) {
V_30 = F_17 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
if ( F_31 ( V_43 , L_18 ) )
V_4 -> V_54 = true ;
if ( ! V_4 -> V_6 && ! V_4 -> V_54 ) {
F_20 ( V_26 , L_19 ) ;
V_30 = - V_55 ;
goto V_56;
}
V_30 = F_32 ( V_43 , L_20 , & V_7 ) ;
if ( V_30 ) {
F_20 ( V_26 , L_21 ) ;
goto V_56;
}
if ( V_7 > V_9 ) {
F_20 ( V_26 , L_22 , V_7 ) ;
V_30 = - V_55 ;
goto V_56;
}
V_4 -> V_7 = V_7 ;
V_50 = V_57 ;
V_49 = ( V_7 << V_58 ) ;
if ( V_4 -> V_54 )
V_49 |= V_59 | V_60 ;
else
V_50 |= V_59 ;
V_30 = F_33 ( V_46 , V_61 , V_50 , V_49 ) ;
if ( V_30 ) {
F_20 ( V_26 , L_23 ) ;
V_30 = - V_27 ;
goto V_56;
}
if ( V_4 -> V_54 ) {
V_30 = F_34 ( V_46 , V_62 , & V_16 ) ;
if ( V_30 ) {
F_20 ( V_26 , L_24 ) ;
return V_30 ;
}
F_10 ( V_26 , L_25 , V_16 ) ;
}
F_10 ( V_26 , L_26 ) ;
F_35 ( V_41 , V_4 ) ;
V_2 = V_4 ;
return 0 ;
V_56:
if ( V_4 -> V_6 ) {
F_36 ( V_4 -> V_32 ) ;
F_36 ( V_4 -> V_31 ) ;
}
return V_30 ;
}
static int F_37 ( struct V_40 * V_41 )
{
struct V_1 * V_4 = F_38 ( V_41 ) ;
if ( V_4 -> V_6 ) {
F_36 ( V_4 -> V_32 ) ;
F_36 ( V_4 -> V_31 ) ;
}
V_2 = NULL ;
return 0 ;
}
