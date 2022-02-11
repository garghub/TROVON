static unsigned int F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div > V_3 )
V_3 = V_4 -> div ;
return V_3 ;
}
static unsigned int F_2 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 & V_8 )
return F_3 ( V_6 ) ;
if ( V_6 -> V_7 & V_9 )
return 1 << F_3 ( V_6 ) ;
if ( V_6 -> V_2 )
return F_1 ( V_6 -> V_2 ) ;
return F_3 ( V_6 ) + 1 ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
unsigned int V_10 )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> V_10 == V_10 )
return V_4 -> div ;
return 0 ;
}
static unsigned int F_5 ( struct V_5 * V_6 , unsigned int V_10 )
{
if ( V_6 -> V_7 & V_8 )
return V_10 ;
if ( V_6 -> V_7 & V_9 )
return 1 << V_10 ;
if ( V_6 -> V_2 )
return F_4 ( V_6 -> V_2 , V_10 ) ;
return V_10 + 1 ;
}
static unsigned int F_6 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div == div )
return V_4 -> V_10 ;
return 0 ;
}
static unsigned int F_7 ( struct V_5 * V_6 , T_1 div )
{
if ( V_6 -> V_7 & V_8 )
return div ;
if ( V_6 -> V_7 & V_9 )
return F_8 ( div ) ;
if ( V_6 -> V_2 )
return F_6 ( V_6 -> V_2 , div ) ;
return div - 1 ;
}
static unsigned long F_9 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned int div , V_10 ;
V_10 = V_14 -> V_15 ( V_6 -> V_16 ) >> V_6 -> V_17 ;
V_10 &= F_3 ( V_6 ) ;
div = F_5 ( V_6 , V_10 ) ;
if ( ! div ) {
F_11 ( ! ( V_6 -> V_7 & V_18 ) ,
L_1 ,
F_12 ( V_12 -> V_19 ) ) ;
return V_13 ;
}
return V_13 / div ;
}
static bool F_13 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div == div )
return true ;
return false ;
}
static bool F_14 ( struct V_5 * V_6 , unsigned int div )
{
if ( V_6 -> V_7 & V_9 )
return F_15 ( div ) ;
if ( V_6 -> V_2 )
return F_13 ( V_6 -> V_2 , div ) ;
return true ;
}
static int F_16 ( struct V_11 * V_12 , unsigned long V_20 ,
unsigned long * V_21 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_22 , V_23 = 0 ;
unsigned long V_13 , V_24 = 0 , V_25 , V_3 ;
unsigned long V_26 = * V_21 ;
if ( ! V_20 )
V_20 = 1 ;
V_3 = F_2 ( V_6 ) ;
if ( ! ( F_17 ( V_12 -> V_19 ) & V_27 ) ) {
V_13 = * V_21 ;
V_23 = F_18 ( V_13 , V_20 ) ;
V_23 = V_23 == 0 ? 1 : V_23 ;
V_23 = V_23 > V_3 ? V_3 : V_23 ;
return V_23 ;
}
V_3 = F_19 ( V_28 / V_20 , V_3 ) ;
for ( V_22 = 1 ; V_22 <= V_3 ; V_22 ++ ) {
if ( ! F_14 ( V_6 , V_22 ) )
continue;
if ( V_20 * V_22 == V_26 ) {
* V_21 = V_26 ;
return V_22 ;
}
V_13 = F_20 ( F_21 ( V_12 -> V_19 ) ,
F_22 ( V_20 , V_22 ) ) ;
V_25 = V_13 / V_22 ;
if ( V_25 <= V_20 && V_25 > V_24 ) {
V_23 = V_22 ;
V_24 = V_25 ;
* V_21 = V_13 ;
}
}
if ( ! V_23 ) {
V_23 = F_2 ( V_6 ) ;
* V_21 =
F_20 ( F_21 ( V_12 -> V_19 ) , 1 ) ;
}
return V_23 ;
}
static long F_23 ( struct V_11 * V_12 , unsigned long V_20 ,
unsigned long * V_29 )
{
int div ;
div = F_16 ( V_12 , V_20 , V_29 ) ;
return * V_29 / div ;
}
static int F_24 ( struct V_11 * V_12 , unsigned long V_20 ,
unsigned long V_13 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned int div , V_30 ;
unsigned long V_7 = 0 ;
T_2 V_10 ;
div = V_13 / V_20 ;
V_30 = F_7 ( V_6 , div ) ;
if ( V_30 > F_3 ( V_6 ) )
V_30 = F_3 ( V_6 ) ;
if ( V_6 -> V_31 )
F_25 ( V_6 -> V_31 , V_7 ) ;
if ( V_6 -> V_7 & V_32 ) {
V_10 = F_3 ( V_6 ) << ( V_6 -> V_17 + 16 ) ;
} else {
V_10 = V_14 -> V_15 ( V_6 -> V_16 ) ;
V_10 &= ~ ( F_3 ( V_6 ) << V_6 -> V_17 ) ;
}
V_10 |= V_30 << V_6 -> V_17 ;
V_14 -> V_33 ( V_10 , V_6 -> V_16 ) ;
if ( V_6 -> V_31 )
F_26 ( V_6 -> V_31 , V_7 ) ;
return 0 ;
}
static struct V_19 * F_27 ( struct V_34 * V_35 , const char * V_36 ,
const char * V_37 ,
unsigned long V_7 , void T_3 * V_16 ,
T_1 V_17 , T_1 V_38 , T_1 V_39 ,
const struct V_1 * V_2 ,
T_4 * V_31 )
{
struct V_5 * div ;
struct V_19 * V_19 ;
struct V_40 V_41 ;
if ( V_39 & V_32 ) {
if ( V_38 + V_17 > 16 ) {
F_28 ( L_2 ) ;
return F_29 ( - V_42 ) ;
}
}
div = F_30 ( sizeof( * div ) , V_43 ) ;
if ( ! div ) {
F_31 ( L_3 , V_44 ) ;
return F_29 ( - V_45 ) ;
}
V_41 . V_36 = V_36 ;
V_41 . V_46 = & V_47 ;
V_41 . V_7 = V_7 | V_48 ;
V_41 . V_49 = ( V_37 ? & V_37 : NULL ) ;
V_41 . V_50 = ( V_37 ? 1 : 0 ) ;
div -> V_16 = V_16 ;
div -> V_17 = V_17 ;
div -> V_38 = V_38 ;
div -> V_7 = V_39 ;
div -> V_31 = V_31 ;
div -> V_12 . V_41 = & V_41 ;
div -> V_2 = V_2 ;
V_19 = F_32 ( V_35 , & div -> V_12 ) ;
if ( F_33 ( V_19 ) )
F_34 ( div ) ;
return V_19 ;
}
static struct V_1
T_5 * F_35 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
const T_6 * V_53 ;
T_2 V_10 ;
T_2 V_54 ;
T_2 V_55 ;
int V_22 ;
V_53 = F_36 ( V_52 , L_4 , & V_54 ) ;
if ( ! V_53 )
return NULL ;
V_54 /= 4 ;
V_55 = 0 ;
for ( V_22 = 0 ; V_22 < V_54 ; V_22 ++ ) {
F_37 ( V_52 , L_4 , V_22 , & V_10 ) ;
if ( V_10 )
V_55 ++ ;
}
if ( ! V_55 ) {
F_31 ( L_5 , V_52 -> V_36 ) ;
return F_29 ( - V_42 ) ;
}
V_2 = F_30 ( sizeof( * V_2 ) * ( V_55 + 1 ) , V_43 ) ;
if ( ! V_2 )
return F_29 ( - V_45 ) ;
V_55 = 0 ;
for ( V_22 = 0 ; V_22 < V_54 ; V_22 ++ ) {
F_37 ( V_52 , L_4 , V_22 , & V_10 ) ;
if ( V_10 ) {
V_2 [ V_55 ] . div = V_10 ;
V_2 [ V_55 ] . V_10 = V_22 ;
V_55 ++ ;
}
}
return V_2 ;
}
static int F_38 ( struct V_51 * V_52 ,
const struct V_1 * V_2 ,
T_1 V_7 )
{
T_2 V_56 ;
T_2 V_57 ;
T_2 V_10 = 0 ;
T_2 div ;
if ( ! V_2 ) {
if ( F_39 ( V_52 , L_6 , & V_56 ) )
V_56 = 1 ;
if ( F_39 ( V_52 , L_7 , & V_57 ) ) {
F_31 ( L_8 , V_52 -> V_36 ) ;
return - V_42 ;
}
if ( V_7 & V_8 )
V_10 = 1 ;
div = V_56 ;
while ( div < V_57 ) {
if ( V_7 & V_9 )
div <<= 1 ;
else
div ++ ;
V_10 ++ ;
}
} else {
div = 0 ;
while ( V_2 [ div ] . div ) {
V_10 = V_2 [ div ] . V_10 ;
div ++ ;
}
}
return F_40 ( V_10 ) ;
}
static int T_5 F_41 ( struct V_51 * V_52 ,
void T_3 * * V_16 , const struct V_1 * * V_2 ,
T_2 * V_7 , T_1 * V_58 , T_1 * V_38 , T_1 * V_17 )
{
T_2 V_10 ;
* V_16 = F_42 ( V_52 , 0 ) ;
if ( ! * V_16 )
return - V_42 ;
if ( ! F_39 ( V_52 , L_9 , & V_10 ) )
* V_17 = V_10 ;
else
* V_17 = 0 ;
* V_7 = 0 ;
* V_58 = 0 ;
if ( F_43 ( V_52 , L_10 ) )
* V_58 |= V_8 ;
if ( F_43 ( V_52 , L_11 ) )
* V_58 |= V_9 ;
if ( F_43 ( V_52 , L_12 ) )
* V_7 |= V_27 ;
* V_2 = F_35 ( V_52 ) ;
if ( F_33 ( * V_2 ) )
return F_44 ( * V_2 ) ;
* V_38 = F_38 ( V_52 , * V_2 , * V_58 ) ;
return 0 ;
}
static void T_5 F_45 ( struct V_51 * V_52 )
{
struct V_19 * V_19 ;
const char * V_37 ;
void T_3 * V_16 ;
T_1 V_39 = 0 ;
T_1 V_38 = 0 ;
T_1 V_17 = 0 ;
const struct V_1 * V_2 = NULL ;
T_2 V_7 = 0 ;
V_37 = F_46 ( V_52 , 0 ) ;
if ( F_41 ( V_52 , & V_16 , & V_2 , & V_7 ,
& V_39 , & V_38 , & V_17 ) )
goto V_59;
V_19 = F_27 ( NULL , V_52 -> V_36 , V_37 , V_7 , V_16 ,
V_17 , V_38 , V_39 , V_2 , NULL ) ;
if ( ! F_33 ( V_19 ) ) {
F_47 ( V_52 , V_60 , V_19 ) ;
F_48 ( V_52 ) ;
return;
}
V_59:
F_34 ( V_2 ) ;
}
static void T_5 F_49 ( struct V_51 * V_52 )
{
struct V_5 * div ;
T_2 V_10 ;
div = F_30 ( sizeof( * div ) , V_43 ) ;
if ( ! div )
return;
if ( F_41 ( V_52 , & div -> V_16 , & div -> V_2 , & V_10 ,
& div -> V_7 , & div -> V_38 , & div -> V_17 ) < 0 )
goto V_59;
if ( ! F_50 ( V_52 , & div -> V_12 , V_61 ) )
return;
V_59:
F_34 ( div -> V_2 ) ;
F_34 ( div ) ;
}
