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
static int F_17 ( const struct V_1 * V_2 ,
unsigned long V_13 , unsigned long V_19 )
{
const struct V_1 * V_4 ;
int V_20 = V_21 ;
int div = F_18 ( ( V_22 ) V_13 , V_19 ) ;
for ( V_4 = V_2 ; V_4 -> div ; V_4 ++ ) {
if ( V_4 -> div == div )
return V_4 -> div ;
else if ( V_4 -> div < div )
continue;
if ( ( V_4 -> div - div ) < ( V_20 - div ) )
V_20 = V_4 -> div ;
}
return V_20 ;
}
static int F_19 ( const struct V_1 * V_2 ,
unsigned long V_13 , unsigned long V_19 )
{
if ( ! V_2 )
return F_13 ( V_13 , V_19 ) ;
return F_17 ( V_2 , V_13 , V_19 ) ;
}
static int F_20 ( struct V_11 * V_12 , unsigned long V_19 ,
unsigned long * V_23 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_24 , V_25 = 0 ;
unsigned long V_13 , V_26 = 0 , V_27 , V_3 ;
unsigned long V_28 = * V_23 ;
if ( ! V_19 )
V_19 = 1 ;
V_3 = F_2 ( V_6 ) ;
if ( ! ( F_21 ( V_12 ) & V_29 ) ) {
V_13 = * V_23 ;
V_25 = F_19 ( V_6 -> V_2 , V_13 , V_19 ) ;
V_25 = V_25 == 0 ? 1 : V_25 ;
V_25 = V_25 > V_3 ? V_3 : V_25 ;
return V_25 ;
}
V_3 = F_22 ( V_30 / V_19 , V_3 ) ;
for ( V_24 = 1 ; V_24 <= V_3 ; V_24 ++ ) {
if ( ! F_15 ( V_6 , V_24 ) )
continue;
if ( V_19 * V_24 == V_28 ) {
* V_23 = V_28 ;
return V_24 ;
}
V_13 = F_23 ( F_24 ( V_12 ) ,
F_25 ( V_19 , V_24 ) ) ;
V_27 = F_13 ( V_13 , V_24 ) ;
if ( V_27 <= V_19 && V_27 > V_26 ) {
V_25 = V_24 ;
V_26 = V_27 ;
* V_23 = V_13 ;
}
}
if ( ! V_25 ) {
V_25 = F_2 ( V_6 ) ;
* V_23 =
F_23 ( F_24 ( V_12 ) , 1 ) ;
}
return V_25 ;
}
static long F_26 ( struct V_11 * V_12 , unsigned long V_19 ,
unsigned long * V_31 )
{
int div ;
div = F_20 ( V_12 , V_19 , V_31 ) ;
return F_13 ( * V_31 , div ) ;
}
static int F_27 ( struct V_11 * V_12 , unsigned long V_19 ,
unsigned long V_13 )
{
struct V_5 * V_6 ;
unsigned int div , V_32 ;
T_2 V_10 ;
if ( ! V_12 || ! V_19 )
return - V_33 ;
V_6 = F_10 ( V_12 ) ;
div = F_13 ( V_13 , V_19 ) ;
V_32 = F_7 ( V_6 , div ) ;
if ( V_32 > F_3 ( V_6 ) )
V_32 = F_3 ( V_6 ) ;
if ( V_6 -> V_7 & V_34 ) {
V_10 = F_3 ( V_6 ) << ( V_6 -> V_17 + 16 ) ;
} else {
V_10 = V_14 -> V_15 ( V_6 -> V_16 ) ;
V_10 &= ~ ( F_3 ( V_6 ) << V_6 -> V_17 ) ;
}
V_10 |= V_32 << V_6 -> V_17 ;
V_14 -> V_35 ( V_10 , V_6 -> V_16 ) ;
return 0 ;
}
static struct V_36 * F_28 ( struct V_37 * V_38 , const char * V_39 ,
const char * V_40 ,
unsigned long V_7 , void T_3 * V_16 ,
T_1 V_17 , T_1 V_41 , T_1 V_42 ,
const struct V_1 * V_2 )
{
struct V_5 * div ;
struct V_36 * V_36 ;
struct V_43 V_44 ;
if ( V_42 & V_34 ) {
if ( V_41 + V_17 > 16 ) {
F_29 ( L_2 ) ;
return F_30 ( - V_33 ) ;
}
}
div = F_31 ( sizeof( * div ) , V_45 ) ;
if ( ! div ) {
F_32 ( L_3 , V_46 ) ;
return F_30 ( - V_47 ) ;
}
V_44 . V_39 = V_39 ;
V_44 . V_48 = & V_49 ;
V_44 . V_7 = V_7 | V_50 ;
V_44 . V_51 = ( V_40 ? & V_40 : NULL ) ;
V_44 . V_52 = ( V_40 ? 1 : 0 ) ;
div -> V_16 = V_16 ;
div -> V_17 = V_17 ;
div -> V_41 = V_41 ;
div -> V_7 = V_42 ;
div -> V_12 . V_44 = & V_44 ;
div -> V_2 = V_2 ;
V_36 = F_33 ( V_38 , & div -> V_12 ) ;
if ( F_34 ( V_36 ) )
F_35 ( div ) ;
return V_36 ;
}
static struct V_1 *
F_36 ( struct V_53 * V_54 , T_1 * V_41 )
{
int V_55 = 0 ;
struct V_1 * V_2 ;
int V_24 ;
int div ;
T_2 V_10 ;
T_1 V_7 ;
if ( ! V_54 -> V_56 ) {
V_7 = V_54 -> V_7 ;
if ( V_7 & V_57 )
V_10 = 1 ;
else
V_10 = 0 ;
div = 1 ;
while ( div < V_54 -> V_58 ) {
if ( V_7 & V_59 )
div <<= 1 ;
else
div ++ ;
V_10 ++ ;
}
* V_41 = F_37 ( V_10 ) ;
return NULL ;
}
for ( V_24 = 0 ; V_24 < V_54 -> V_56 ; V_24 ++ )
if ( V_54 -> V_60 [ V_24 ] )
V_55 ++ ;
V_2 = F_31 ( sizeof( * V_2 ) * ( V_55 + 1 ) , V_45 ) ;
if ( ! V_2 )
return F_30 ( - V_47 ) ;
V_55 = 0 ;
* V_41 = 0 ;
for ( V_24 = 0 ; V_24 < V_54 -> V_56 ; V_24 ++ )
if ( V_54 -> V_60 [ V_24 ] ) {
V_2 [ V_55 ] . div = V_54 -> V_60 [ V_24 ] ;
V_2 [ V_55 ] . V_10 = V_24 ;
V_55 ++ ;
* V_41 = V_24 ;
}
* V_41 = F_37 ( * V_41 ) ;
return V_2 ;
}
struct V_11 * F_38 ( struct V_53 * V_54 )
{
struct V_5 * div ;
struct V_61 * V_16 ;
if ( ! V_54 )
return NULL ;
div = F_31 ( sizeof( * div ) , V_45 ) ;
if ( ! div )
return F_30 ( - V_47 ) ;
V_16 = (struct V_61 * ) & div -> V_16 ;
V_16 -> V_62 = V_54 -> V_63 ;
V_16 -> V_64 = V_54 -> V_16 ;
if ( V_54 -> V_7 & V_57 )
div -> V_7 |= V_8 ;
if ( V_54 -> V_7 & V_59 )
div -> V_7 |= V_9 ;
div -> V_2 = F_36 ( V_54 , & div -> V_41 ) ;
div -> V_17 = V_54 -> V_65 ;
return & div -> V_12 ;
}
struct V_36 * F_39 ( struct V_66 * V_54 )
{
struct V_53 * div ;
struct V_61 * V_67 ;
T_2 V_16 ;
T_1 V_41 ;
T_2 V_7 = 0 ;
T_1 V_68 = 0 ;
struct V_1 * V_2 ;
struct V_36 * V_36 ;
div = V_54 -> V_69 ;
V_67 = (struct V_61 * ) & V_16 ;
V_67 -> V_62 = div -> V_63 ;
V_67 -> V_64 = div -> V_16 ;
if ( div -> V_7 & V_57 )
V_68 |= V_8 ;
if ( div -> V_7 & V_59 )
V_68 |= V_9 ;
if ( div -> V_7 & V_70 )
V_7 |= V_29 ;
V_2 = F_36 ( div , & V_41 ) ;
if ( F_34 ( V_2 ) )
return (struct V_36 * ) V_2 ;
V_36 = F_28 ( NULL , V_54 -> V_39 , div -> V_71 ,
V_7 , ( void T_3 * ) V_16 , div -> V_65 ,
V_41 , V_68 , V_2 ) ;
if ( F_34 ( V_36 ) )
F_35 ( V_2 ) ;
return V_36 ;
}
static struct V_1 *
T_4 F_40 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
const T_5 * V_74 ;
T_2 V_10 ;
T_2 V_75 ;
T_2 V_55 ;
int V_24 ;
V_74 = F_41 ( V_73 , L_4 , & V_75 ) ;
if ( ! V_74 )
return NULL ;
V_75 /= 4 ;
V_55 = 0 ;
for ( V_24 = 0 ; V_24 < V_75 ; V_24 ++ ) {
F_42 ( V_73 , L_4 , V_24 , & V_10 ) ;
if ( V_10 )
V_55 ++ ;
}
if ( ! V_55 ) {
F_32 ( L_5 , V_73 -> V_39 ) ;
return F_30 ( - V_33 ) ;
}
V_2 = F_31 ( sizeof( * V_2 ) * ( V_55 + 1 ) , V_45 ) ;
if ( ! V_2 )
return F_30 ( - V_47 ) ;
V_55 = 0 ;
for ( V_24 = 0 ; V_24 < V_75 ; V_24 ++ ) {
F_42 ( V_73 , L_4 , V_24 , & V_10 ) ;
if ( V_10 ) {
V_2 [ V_55 ] . div = V_10 ;
V_2 [ V_55 ] . V_10 = V_24 ;
V_55 ++ ;
}
}
return V_2 ;
}
static int F_43 ( struct V_72 * V_73 ,
const struct V_1 * V_2 ,
T_1 V_7 )
{
T_2 V_76 ;
T_2 V_58 ;
T_2 V_10 = 0 ;
T_2 div ;
if ( ! V_2 ) {
if ( F_44 ( V_73 , L_6 , & V_76 ) )
V_76 = 1 ;
if ( F_44 ( V_73 , L_7 , & V_58 ) ) {
F_32 ( L_8 , V_73 -> V_39 ) ;
return - V_33 ;
}
if ( V_7 & V_8 )
V_10 = 1 ;
div = V_76 ;
while ( div < V_58 ) {
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
return F_37 ( V_10 ) ;
}
static int T_4 F_45 ( struct V_72 * V_73 ,
void T_3 * * V_16 , const struct V_1 * * V_2 ,
T_2 * V_7 , T_1 * V_68 , T_1 * V_41 , T_1 * V_17 )
{
T_2 V_10 ;
* V_16 = F_46 ( V_73 , 0 ) ;
if ( F_34 ( * V_16 ) )
return F_47 ( * V_16 ) ;
if ( ! F_44 ( V_73 , L_9 , & V_10 ) )
* V_17 = V_10 ;
else
* V_17 = 0 ;
* V_7 = 0 ;
* V_68 = 0 ;
if ( F_48 ( V_73 , L_10 ) )
* V_68 |= V_8 ;
if ( F_48 ( V_73 , L_11 ) )
* V_68 |= V_9 ;
if ( F_48 ( V_73 , L_12 ) )
* V_7 |= V_29 ;
* V_2 = F_40 ( V_73 ) ;
if ( F_34 ( * V_2 ) )
return F_47 ( * V_2 ) ;
* V_41 = F_43 ( V_73 , * V_2 , * V_68 ) ;
return 0 ;
}
static void T_4 F_49 ( struct V_72 * V_73 )
{
struct V_36 * V_36 ;
const char * V_40 ;
void T_3 * V_16 ;
T_1 V_42 = 0 ;
T_1 V_41 = 0 ;
T_1 V_17 = 0 ;
const struct V_1 * V_2 = NULL ;
T_2 V_7 = 0 ;
V_40 = F_50 ( V_73 , 0 ) ;
if ( F_45 ( V_73 , & V_16 , & V_2 , & V_7 ,
& V_42 , & V_41 , & V_17 ) )
goto V_77;
V_36 = F_28 ( NULL , V_73 -> V_39 , V_40 , V_7 , V_16 ,
V_17 , V_41 , V_42 , V_2 ) ;
if ( ! F_34 ( V_36 ) ) {
F_51 ( V_73 , V_78 , V_36 ) ;
F_52 ( V_73 ) ;
return;
}
V_77:
F_35 ( V_2 ) ;
}
static void T_4 F_53 ( struct V_72 * V_73 )
{
struct V_5 * div ;
T_2 V_10 ;
div = F_31 ( sizeof( * div ) , V_45 ) ;
if ( ! div )
return;
if ( F_45 ( V_73 , & div -> V_16 , & div -> V_2 , & V_10 ,
& div -> V_7 , & div -> V_41 , & div -> V_17 ) < 0 )
goto V_77;
if ( ! F_54 ( V_73 , & div -> V_12 , V_79 ) )
return;
V_77:
F_35 ( div -> V_2 ) ;
F_35 ( div ) ;
}
