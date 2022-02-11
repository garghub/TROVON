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
F_12 ( V_12 ) ) ;
return V_13 ;
}
return F_13 ( V_13 , div ) ;
}
static bool F_14 ( const struct V_1 * V_2 ,
unsigned int div )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ )
if ( V_4 -> div == div )
return true ;
return false ;
}
static bool F_15 ( struct V_5 * V_6 , unsigned int div )
{
if ( V_6 -> V_7 & V_9 )
return F_16 ( div ) ;
if ( V_6 -> V_2 )
return F_14 ( V_6 -> V_2 , div ) ;
return true ;
}
static int F_17 ( struct V_11 * V_12 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_21 , V_22 = 0 ;
unsigned long V_13 , V_23 = 0 , V_24 , V_3 ;
unsigned long V_25 = * V_20 ;
if ( ! V_19 )
V_19 = 1 ;
V_3 = F_2 ( V_6 ) ;
if ( ! ( F_18 ( V_12 ) & V_26 ) ) {
V_13 = * V_20 ;
V_22 = F_13 ( V_13 , V_19 ) ;
V_22 = V_22 == 0 ? 1 : V_22 ;
V_22 = V_22 > V_3 ? V_3 : V_22 ;
return V_22 ;
}
V_3 = F_19 ( V_27 / V_19 , V_3 ) ;
for ( V_21 = 1 ; V_21 <= V_3 ; V_21 ++ ) {
if ( ! F_15 ( V_6 , V_21 ) )
continue;
if ( V_19 * V_21 == V_25 ) {
* V_20 = V_25 ;
return V_21 ;
}
V_13 = F_20 ( F_21 ( V_12 ) ,
F_22 ( V_19 , V_21 ) ) ;
V_24 = F_13 ( V_13 , V_21 ) ;
if ( V_24 <= V_19 && V_24 > V_23 ) {
V_22 = V_21 ;
V_23 = V_24 ;
* V_20 = V_13 ;
}
}
if ( ! V_22 ) {
V_22 = F_2 ( V_6 ) ;
* V_20 =
F_20 ( F_21 ( V_12 ) , 1 ) ;
}
return V_22 ;
}
static long F_23 ( struct V_11 * V_12 , unsigned long V_19 ,
unsigned long * V_28 )
{
int div ;
div = F_17 ( V_12 , V_19 , V_28 ) ;
return F_13 ( * V_28 , div ) ;
}
static int F_24 ( struct V_11 * V_12 , unsigned long V_19 ,
unsigned long V_13 )
{
struct V_5 * V_6 ;
unsigned int div , V_29 ;
unsigned long V_7 = 0 ;
T_2 V_10 ;
if ( ! V_12 || ! V_19 )
return - V_30 ;
V_6 = F_10 ( V_12 ) ;
div = F_13 ( V_13 , V_19 ) ;
V_29 = F_7 ( V_6 , div ) ;
if ( V_29 > F_3 ( V_6 ) )
V_29 = F_3 ( V_6 ) ;
if ( V_6 -> V_31 )
F_25 ( V_6 -> V_31 , V_7 ) ;
if ( V_6 -> V_7 & V_32 ) {
V_10 = F_3 ( V_6 ) << ( V_6 -> V_17 + 16 ) ;
} else {
V_10 = V_14 -> V_15 ( V_6 -> V_16 ) ;
V_10 &= ~ ( F_3 ( V_6 ) << V_6 -> V_17 ) ;
}
V_10 |= V_29 << V_6 -> V_17 ;
V_14 -> V_33 ( V_10 , V_6 -> V_16 ) ;
if ( V_6 -> V_31 )
F_26 ( V_6 -> V_31 , V_7 ) ;
return 0 ;
}
static struct V_34 * F_27 ( struct V_35 * V_36 , const char * V_37 ,
const char * V_38 ,
unsigned long V_7 , void T_3 * V_16 ,
T_1 V_17 , T_1 V_39 , T_1 V_40 ,
const struct V_1 * V_2 ,
T_4 * V_31 )
{
struct V_5 * div ;
struct V_34 * V_34 ;
struct V_41 V_42 ;
if ( V_40 & V_32 ) {
if ( V_39 + V_17 > 16 ) {
F_28 ( L_2 ) ;
return F_29 ( - V_30 ) ;
}
}
div = F_30 ( sizeof( * div ) , V_43 ) ;
if ( ! div ) {
F_31 ( L_3 , V_44 ) ;
return F_29 ( - V_45 ) ;
}
V_42 . V_37 = V_37 ;
V_42 . V_46 = & V_47 ;
V_42 . V_7 = V_7 | V_48 ;
V_42 . V_49 = ( V_38 ? & V_38 : NULL ) ;
V_42 . V_50 = ( V_38 ? 1 : 0 ) ;
div -> V_16 = V_16 ;
div -> V_17 = V_17 ;
div -> V_39 = V_39 ;
div -> V_7 = V_40 ;
div -> V_31 = V_31 ;
div -> V_12 . V_42 = & V_42 ;
div -> V_2 = V_2 ;
V_34 = F_32 ( V_36 , & div -> V_12 ) ;
if ( F_33 ( V_34 ) )
F_34 ( div ) ;
return V_34 ;
}
static struct V_1 *
F_35 ( struct V_51 * V_52 , T_1 * V_39 )
{
int V_53 = 0 ;
struct V_1 * V_2 ;
int V_21 ;
int div ;
T_2 V_10 ;
T_1 V_7 ;
if ( ! V_52 -> V_54 ) {
V_7 = V_52 -> V_7 ;
if ( V_7 & V_55 )
V_10 = 1 ;
else
V_10 = 0 ;
div = 1 ;
while ( div < V_52 -> V_56 ) {
if ( V_7 & V_57 )
div <<= 1 ;
else
div ++ ;
V_10 ++ ;
}
* V_39 = F_36 ( V_10 ) ;
return NULL ;
}
for ( V_21 = 0 ; V_21 < V_52 -> V_54 ; V_21 ++ )
if ( V_52 -> V_58 [ V_21 ] )
V_53 ++ ;
V_2 = F_30 ( sizeof( * V_2 ) * ( V_53 + 1 ) , V_43 ) ;
if ( ! V_2 )
return F_29 ( - V_45 ) ;
V_53 = 0 ;
* V_39 = 0 ;
for ( V_21 = 0 ; V_21 < V_52 -> V_54 ; V_21 ++ )
if ( V_52 -> V_58 [ V_21 ] ) {
V_2 [ V_53 ] . div = V_52 -> V_58 [ V_21 ] ;
V_2 [ V_53 ] . V_10 = V_21 ;
V_53 ++ ;
* V_39 = V_21 ;
}
* V_39 = F_36 ( * V_39 ) ;
return V_2 ;
}
struct V_11 * F_37 ( struct V_51 * V_52 )
{
struct V_5 * div ;
struct V_59 * V_16 ;
if ( ! V_52 )
return NULL ;
div = F_30 ( sizeof( * div ) , V_43 ) ;
if ( ! div )
return F_29 ( - V_45 ) ;
V_16 = (struct V_59 * ) & div -> V_16 ;
V_16 -> V_60 = V_52 -> V_61 ;
V_16 -> V_62 = V_52 -> V_16 ;
if ( V_52 -> V_7 & V_55 )
div -> V_7 |= V_8 ;
if ( V_52 -> V_7 & V_57 )
div -> V_7 |= V_9 ;
div -> V_2 = F_35 ( V_52 , & div -> V_39 ) ;
div -> V_17 = V_52 -> V_63 ;
return & div -> V_12 ;
}
struct V_34 * F_38 ( struct V_64 * V_52 )
{
struct V_51 * div ;
struct V_59 * V_65 ;
T_2 V_16 ;
T_1 V_39 ;
T_2 V_7 = 0 ;
T_1 V_66 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_34 ;
div = V_52 -> V_67 ;
V_65 = (struct V_59 * ) & V_16 ;
V_65 -> V_60 = div -> V_61 ;
V_65 -> V_62 = div -> V_16 ;
if ( div -> V_7 & V_55 )
V_66 |= V_8 ;
if ( div -> V_7 & V_57 )
V_66 |= V_9 ;
if ( div -> V_7 & V_68 )
V_7 |= V_26 ;
V_2 = F_35 ( div , & V_39 ) ;
if ( F_33 ( V_2 ) )
return (struct V_34 * ) V_2 ;
V_34 = F_27 ( NULL , V_52 -> V_37 , div -> V_69 ,
V_7 , ( void T_3 * ) V_16 , div -> V_63 ,
V_39 , V_66 , V_2 , NULL ) ;
if ( F_33 ( V_34 ) )
F_34 ( V_2 ) ;
return V_34 ;
}
static struct V_1 *
T_5 F_39 ( struct V_70 * V_71 )
{
struct V_1 * V_2 ;
const T_6 * V_72 ;
T_2 V_10 ;
T_2 V_73 ;
T_2 V_53 ;
int V_21 ;
V_72 = F_40 ( V_71 , L_4 , & V_73 ) ;
if ( ! V_72 )
return NULL ;
V_73 /= 4 ;
V_53 = 0 ;
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ ) {
F_41 ( V_71 , L_4 , V_21 , & V_10 ) ;
if ( V_10 )
V_53 ++ ;
}
if ( ! V_53 ) {
F_31 ( L_5 , V_71 -> V_37 ) ;
return F_29 ( - V_30 ) ;
}
V_2 = F_30 ( sizeof( * V_2 ) * ( V_53 + 1 ) , V_43 ) ;
if ( ! V_2 )
return F_29 ( - V_45 ) ;
V_53 = 0 ;
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ ) {
F_41 ( V_71 , L_4 , V_21 , & V_10 ) ;
if ( V_10 ) {
V_2 [ V_53 ] . div = V_10 ;
V_2 [ V_53 ] . V_10 = V_21 ;
V_53 ++ ;
}
}
return V_2 ;
}
static int F_42 ( struct V_70 * V_71 ,
const struct V_1 * V_2 ,
T_1 V_7 )
{
T_2 V_74 ;
T_2 V_56 ;
T_2 V_10 = 0 ;
T_2 div ;
if ( ! V_2 ) {
if ( F_43 ( V_71 , L_6 , & V_74 ) )
V_74 = 1 ;
if ( F_43 ( V_71 , L_7 , & V_56 ) ) {
F_31 ( L_8 , V_71 -> V_37 ) ;
return - V_30 ;
}
if ( V_7 & V_8 )
V_10 = 1 ;
div = V_74 ;
while ( div < V_56 ) {
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
return F_36 ( V_10 ) ;
}
static int T_5 F_44 ( struct V_70 * V_71 ,
void T_3 * * V_16 , const struct V_1 * * V_2 ,
T_2 * V_7 , T_1 * V_66 , T_1 * V_39 , T_1 * V_17 )
{
T_2 V_10 ;
* V_16 = F_45 ( V_71 , 0 ) ;
if ( F_33 ( * V_16 ) )
return F_46 ( * V_16 ) ;
if ( ! F_43 ( V_71 , L_9 , & V_10 ) )
* V_17 = V_10 ;
else
* V_17 = 0 ;
* V_7 = 0 ;
* V_66 = 0 ;
if ( F_47 ( V_71 , L_10 ) )
* V_66 |= V_8 ;
if ( F_47 ( V_71 , L_11 ) )
* V_66 |= V_9 ;
if ( F_47 ( V_71 , L_12 ) )
* V_7 |= V_26 ;
* V_2 = F_39 ( V_71 ) ;
if ( F_33 ( * V_2 ) )
return F_46 ( * V_2 ) ;
* V_39 = F_42 ( V_71 , * V_2 , * V_66 ) ;
return 0 ;
}
static void T_5 F_48 ( struct V_70 * V_71 )
{
struct V_34 * V_34 ;
const char * V_38 ;
void T_3 * V_16 ;
T_1 V_40 = 0 ;
T_1 V_39 = 0 ;
T_1 V_17 = 0 ;
const struct V_1 * V_2 = NULL ;
T_2 V_7 = 0 ;
V_38 = F_49 ( V_71 , 0 ) ;
if ( F_44 ( V_71 , & V_16 , & V_2 , & V_7 ,
& V_40 , & V_39 , & V_17 ) )
goto V_75;
V_34 = F_27 ( NULL , V_71 -> V_37 , V_38 , V_7 , V_16 ,
V_17 , V_39 , V_40 , V_2 ,
NULL ) ;
if ( ! F_33 ( V_34 ) ) {
F_50 ( V_71 , V_76 , V_34 ) ;
F_51 ( V_71 ) ;
return;
}
V_75:
F_34 ( V_2 ) ;
}
static void T_5 F_52 ( struct V_70 * V_71 )
{
struct V_5 * div ;
T_2 V_10 ;
div = F_30 ( sizeof( * div ) , V_43 ) ;
if ( ! div )
return;
if ( F_44 ( V_71 , & div -> V_16 , & div -> V_2 , & V_10 ,
& div -> V_7 , & div -> V_39 , & div -> V_17 ) < 0 )
goto V_75;
if ( ! F_53 ( V_71 , & div -> V_12 , V_77 ) )
return;
V_75:
F_34 ( div -> V_2 ) ;
F_34 ( div ) ;
}
