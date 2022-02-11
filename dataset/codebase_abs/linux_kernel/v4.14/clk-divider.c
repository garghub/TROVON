static unsigned int F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned int V_4 = 0 , V_5 = F_2 ( V_3 ) ;
const struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ )
if ( V_6 -> div > V_4 && V_6 -> V_7 <= V_5 )
V_4 = V_6 -> div ;
return V_4 ;
}
static unsigned int F_3 ( const struct V_1 * V_2 )
{
unsigned int V_8 = V_9 ;
const struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ )
if ( V_6 -> div < V_8 )
V_8 = V_6 -> div ;
return V_8 ;
}
static unsigned int F_4 ( const struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_10 )
{
if ( V_10 & V_11 )
return F_2 ( V_3 ) ;
if ( V_10 & V_12 )
return 1 << F_2 ( V_3 ) ;
if ( V_2 )
return F_1 ( V_2 , V_3 ) ;
return F_2 ( V_3 ) + 1 ;
}
static unsigned int F_5 ( const struct V_1 * V_2 ,
unsigned int V_7 )
{
const struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ )
if ( V_6 -> V_7 == V_7 )
return V_6 -> div ;
return 0 ;
}
static unsigned int F_6 ( const struct V_1 * V_2 ,
unsigned int V_7 , unsigned long V_10 , T_1 V_3 )
{
if ( V_10 & V_11 )
return V_7 ;
if ( V_10 & V_12 )
return 1 << V_7 ;
if ( V_10 & V_13 )
return V_7 ? V_7 : F_2 ( V_3 ) + 1 ;
if ( V_2 )
return F_5 ( V_2 , V_7 ) ;
return V_7 + 1 ;
}
static unsigned int F_7 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ )
if ( V_6 -> div == div )
return V_6 -> V_7 ;
return 0 ;
}
static unsigned int F_8 ( const struct V_1 * V_2 ,
unsigned int div , unsigned long V_10 , T_1 V_3 )
{
if ( V_10 & V_11 )
return div ;
if ( V_10 & V_12 )
return F_9 ( div ) ;
if ( V_10 & V_13 )
return ( div == F_2 ( V_3 ) + 1 ) ? 0 : div ;
if ( V_2 )
return F_7 ( V_2 , div ) ;
return div - 1 ;
}
unsigned long F_10 ( struct V_14 * V_15 , unsigned long V_16 ,
unsigned int V_7 ,
const struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_17 * V_18 = F_11 ( V_15 ) ;
unsigned int div ;
div = F_6 ( V_2 , V_7 , V_10 , V_18 -> V_3 ) ;
if ( ! div ) {
F_12 ( ! ( V_10 & V_19 ) ,
L_1 ,
F_13 ( V_15 ) ) ;
return V_16 ;
}
return F_14 ( ( V_20 ) V_16 , div ) ;
}
static unsigned long F_15 ( struct V_14 * V_15 ,
unsigned long V_16 )
{
struct V_17 * V_18 = F_11 ( V_15 ) ;
unsigned int V_7 ;
V_7 = F_16 ( V_18 -> V_21 ) >> V_18 -> V_22 ;
V_7 &= F_2 ( V_18 -> V_3 ) ;
return F_10 ( V_15 , V_16 , V_7 , V_18 -> V_2 ,
V_18 -> V_10 ) ;
}
static bool F_17 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ )
if ( V_6 -> div == div )
return true ;
return false ;
}
static bool F_18 ( const struct V_1 * V_2 , unsigned int div ,
unsigned long V_10 )
{
if ( V_10 & V_12 )
return F_19 ( div ) ;
if ( V_2 )
return F_17 ( V_2 , div ) ;
return true ;
}
static int F_20 ( const struct V_1 * V_2 , int div )
{
const struct V_1 * V_6 ;
int V_23 = V_24 ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ ) {
if ( V_6 -> div == div )
return V_6 -> div ;
else if ( V_6 -> div < div )
continue;
if ( ( V_6 -> div - div ) < ( V_23 - div ) )
V_23 = V_6 -> div ;
}
return V_23 ;
}
static int F_21 ( const struct V_1 * V_2 , int div )
{
const struct V_1 * V_6 ;
int V_25 = F_3 ( V_2 ) ;
for ( V_6 = V_2 ; V_6 -> div ; V_6 ++ ) {
if ( V_6 -> div == div )
return V_6 -> div ;
else if ( V_6 -> div > div )
continue;
if ( ( div - V_6 -> div ) < ( div - V_25 ) )
V_25 = V_6 -> div ;
}
return V_25 ;
}
static int F_22 ( const struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_26 ,
unsigned long V_10 )
{
int div = F_14 ( ( V_20 ) V_16 , V_26 ) ;
if ( V_10 & V_12 )
div = F_23 ( div ) ;
if ( V_2 )
div = F_20 ( V_2 , div ) ;
return div ;
}
static int F_24 ( const struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_26 ,
unsigned long V_10 )
{
int V_23 , V_25 ;
unsigned long V_27 , V_28 ;
V_23 = F_14 ( ( V_20 ) V_16 , V_26 ) ;
V_25 = V_16 / V_26 ;
if ( V_10 & V_12 ) {
V_23 = F_23 ( V_23 ) ;
V_25 = F_25 ( V_25 ) ;
} else if ( V_2 ) {
V_23 = F_20 ( V_2 , V_23 ) ;
V_25 = F_21 ( V_2 , V_25 ) ;
}
V_27 = F_14 ( ( V_20 ) V_16 , V_23 ) ;
V_28 = F_14 ( ( V_20 ) V_16 , V_25 ) ;
return ( V_26 - V_27 ) <= ( V_28 - V_26 ) ? V_23 : V_25 ;
}
static int F_26 ( const struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_26 ,
unsigned long V_10 )
{
if ( V_10 & V_29 )
return F_24 ( V_2 , V_16 , V_26 , V_10 ) ;
return F_22 ( V_2 , V_16 , V_26 , V_10 ) ;
}
static bool F_27 ( unsigned long V_26 , unsigned long V_30 ,
unsigned long V_31 , unsigned long V_10 )
{
if ( V_10 & V_29 )
return abs ( V_26 - V_30 ) < abs ( V_26 - V_31 ) ;
return V_30 <= V_26 && V_30 > V_31 ;
}
static int F_28 ( const struct V_1 * V_2 , int div ,
unsigned long V_10 )
{
div ++ ;
if ( V_10 & V_12 )
return F_23 ( div ) ;
if ( V_2 )
return F_20 ( V_2 , div ) ;
return div ;
}
static int F_29 ( struct V_14 * V_15 , struct V_14 * V_32 ,
unsigned long V_26 ,
unsigned long * V_33 ,
const struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_10 )
{
int V_34 , V_35 = 0 ;
unsigned long V_16 , V_31 = 0 , V_30 , V_4 ;
unsigned long V_36 = * V_33 ;
if ( ! V_26 )
V_26 = 1 ;
V_4 = F_4 ( V_2 , V_3 , V_10 ) ;
if ( ! ( F_30 ( V_15 ) & V_37 ) ) {
V_16 = * V_33 ;
V_35 = F_26 ( V_2 , V_16 , V_26 , V_10 ) ;
V_35 = V_35 == 0 ? 1 : V_35 ;
V_35 = V_35 > V_4 ? V_4 : V_35 ;
return V_35 ;
}
V_4 = F_31 ( V_38 / V_26 , V_4 ) ;
for ( V_34 = F_28 ( V_2 , 0 , V_10 ) ; V_34 <= V_4 ;
V_34 = F_28 ( V_2 , V_34 , V_10 ) ) {
if ( V_26 * V_34 == V_36 ) {
* V_33 = V_36 ;
return V_34 ;
}
V_16 = F_32 ( V_32 , V_26 * V_34 ) ;
V_30 = F_14 ( ( V_20 ) V_16 , V_34 ) ;
if ( F_27 ( V_26 , V_30 , V_31 , V_10 ) ) {
V_35 = V_34 ;
V_31 = V_30 ;
* V_33 = V_16 ;
}
}
if ( ! V_35 ) {
V_35 = F_4 ( V_2 , V_3 , V_10 ) ;
* V_33 = F_32 ( V_32 , 1 ) ;
}
return V_35 ;
}
long F_33 ( struct V_14 * V_15 , struct V_14 * V_32 ,
unsigned long V_26 , unsigned long * V_39 ,
const struct V_1 * V_2 ,
T_1 V_3 , unsigned long V_10 )
{
int div ;
div = F_29 ( V_15 , V_32 , V_26 , V_39 , V_2 , V_3 , V_10 ) ;
return F_14 ( ( V_20 ) * V_39 , div ) ;
}
static long F_34 ( struct V_14 * V_15 , unsigned long V_26 ,
unsigned long * V_39 )
{
struct V_17 * V_18 = F_11 ( V_15 ) ;
int V_35 ;
if ( V_18 -> V_10 & V_40 ) {
V_35 = F_16 ( V_18 -> V_21 ) >> V_18 -> V_22 ;
V_35 &= F_2 ( V_18 -> V_3 ) ;
V_35 = F_6 ( V_18 -> V_2 , V_35 , V_18 -> V_10 ,
V_18 -> V_3 ) ;
return F_14 ( ( V_20 ) * V_39 , V_35 ) ;
}
return F_35 ( V_15 , V_26 , V_39 , V_18 -> V_2 ,
V_18 -> V_3 , V_18 -> V_10 ) ;
}
int F_36 ( unsigned long V_26 , unsigned long V_16 ,
const struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_10 )
{
unsigned int div , V_41 ;
div = F_14 ( ( V_20 ) V_16 , V_26 ) ;
if ( ! F_18 ( V_2 , div , V_10 ) )
return - V_42 ;
V_41 = F_8 ( V_2 , div , V_10 , V_3 ) ;
return F_37 (unsigned int, value, div_mask(width)) ;
}
static int F_38 ( struct V_14 * V_15 , unsigned long V_26 ,
unsigned long V_16 )
{
struct V_17 * V_18 = F_11 ( V_15 ) ;
int V_41 ;
unsigned long V_10 = 0 ;
T_2 V_7 ;
V_41 = F_36 ( V_26 , V_16 , V_18 -> V_2 ,
V_18 -> V_3 , V_18 -> V_10 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_18 -> V_43 )
F_39 ( V_18 -> V_43 , V_10 ) ;
else
F_40 ( V_18 -> V_43 ) ;
if ( V_18 -> V_10 & V_44 ) {
V_7 = F_2 ( V_18 -> V_3 ) << ( V_18 -> V_22 + 16 ) ;
} else {
V_7 = F_16 ( V_18 -> V_21 ) ;
V_7 &= ~ ( F_2 ( V_18 -> V_3 ) << V_18 -> V_22 ) ;
}
V_7 |= ( T_2 ) V_41 << V_18 -> V_22 ;
F_41 ( V_7 , V_18 -> V_21 ) ;
if ( V_18 -> V_43 )
F_42 ( V_18 -> V_43 , V_10 ) ;
else
F_43 ( V_18 -> V_43 ) ;
return 0 ;
}
static struct V_14 * F_44 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , unsigned long V_10 ,
void T_3 * V_21 , T_1 V_22 , T_1 V_3 ,
T_1 V_49 , const struct V_1 * V_2 ,
T_4 * V_43 )
{
struct V_17 * div ;
struct V_14 * V_15 ;
struct V_50 V_51 ;
int V_52 ;
if ( V_49 & V_44 ) {
if ( V_3 + V_22 > 16 ) {
F_45 ( L_2 ) ;
return F_46 ( - V_42 ) ;
}
}
div = F_47 ( sizeof( * div ) , V_53 ) ;
if ( ! div )
return F_46 ( - V_54 ) ;
V_51 . V_47 = V_47 ;
if ( V_49 & V_40 )
V_51 . V_55 = & V_56 ;
else
V_51 . V_55 = & V_57 ;
V_51 . V_10 = V_10 | V_58 ;
V_51 . V_59 = ( V_48 ? & V_48 : NULL ) ;
V_51 . V_60 = ( V_48 ? 1 : 0 ) ;
div -> V_21 = V_21 ;
div -> V_22 = V_22 ;
div -> V_3 = V_3 ;
div -> V_10 = V_49 ;
div -> V_43 = V_43 ;
div -> V_15 . V_51 = & V_51 ;
div -> V_2 = V_2 ;
V_15 = & div -> V_15 ;
V_52 = F_48 ( V_46 , V_15 ) ;
if ( V_52 ) {
F_49 ( div ) ;
V_15 = F_46 ( V_52 ) ;
}
return V_15 ;
}
struct V_61 * F_50 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , unsigned long V_10 ,
void T_3 * V_21 , T_1 V_22 , T_1 V_3 ,
T_1 V_49 , T_4 * V_43 )
{
struct V_14 * V_15 ;
V_15 = F_44 ( V_46 , V_47 , V_48 , V_10 , V_21 , V_22 ,
V_3 , V_49 , NULL , V_43 ) ;
if ( F_51 ( V_15 ) )
return F_52 ( V_15 ) ;
return V_15 -> V_61 ;
}
struct V_14 * F_53 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , unsigned long V_10 ,
void T_3 * V_21 , T_1 V_22 , T_1 V_3 ,
T_1 V_49 , T_4 * V_43 )
{
return F_44 ( V_46 , V_47 , V_48 , V_10 , V_21 , V_22 ,
V_3 , V_49 , NULL , V_43 ) ;
}
struct V_61 * F_54 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , unsigned long V_10 ,
void T_3 * V_21 , T_1 V_22 , T_1 V_3 ,
T_1 V_49 , const struct V_1 * V_2 ,
T_4 * V_43 )
{
struct V_14 * V_15 ;
V_15 = F_44 ( V_46 , V_47 , V_48 , V_10 , V_21 , V_22 ,
V_3 , V_49 , V_2 , V_43 ) ;
if ( F_51 ( V_15 ) )
return F_52 ( V_15 ) ;
return V_15 -> V_61 ;
}
struct V_14 * F_55 ( struct V_45 * V_46 ,
const char * V_47 , const char * V_48 , unsigned long V_10 ,
void T_3 * V_21 , T_1 V_22 , T_1 V_3 ,
T_1 V_49 , const struct V_1 * V_2 ,
T_4 * V_43 )
{
return F_44 ( V_46 , V_47 , V_48 , V_10 , V_21 , V_22 ,
V_3 , V_49 , V_2 , V_43 ) ;
}
void F_56 ( struct V_61 * V_61 )
{
struct V_17 * div ;
struct V_14 * V_15 ;
V_15 = F_57 ( V_61 ) ;
if ( ! V_15 )
return;
div = F_11 ( V_15 ) ;
F_58 ( V_61 ) ;
F_49 ( div ) ;
}
void F_59 ( struct V_14 * V_15 )
{
struct V_17 * div ;
div = F_11 ( V_15 ) ;
F_60 ( V_15 ) ;
F_49 ( div ) ;
}
