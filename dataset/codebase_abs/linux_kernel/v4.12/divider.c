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
V_10 = V_14 -> V_15 ( & V_6 -> V_16 ) >> V_6 -> V_17 ;
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
V_10 = V_14 -> V_15 ( & V_6 -> V_16 ) ;
V_10 &= ~ ( F_3 ( V_6 ) << V_6 -> V_17 ) ;
}
V_10 |= V_32 << V_6 -> V_17 ;
V_14 -> V_35 ( V_10 , & V_6 -> V_16 ) ;
return 0 ;
}
static struct V_36 * F_28 ( struct V_37 * V_38 , const char * V_39 ,
const char * V_40 ,
unsigned long V_7 ,
struct V_41 * V_16 ,
T_1 V_17 , T_1 V_42 , T_1 V_43 ,
const struct V_1 * V_2 )
{
struct V_5 * div ;
struct V_36 * V_36 ;
struct V_44 V_45 ;
if ( V_43 & V_34 ) {
if ( V_42 + V_17 > 16 ) {
F_29 ( L_2 ) ;
return F_30 ( - V_33 ) ;
}
}
div = F_31 ( sizeof( * div ) , V_46 ) ;
if ( ! div ) {
F_32 ( L_3 , V_47 ) ;
return F_30 ( - V_48 ) ;
}
V_45 . V_39 = V_39 ;
V_45 . V_49 = & V_50 ;
V_45 . V_7 = V_7 | V_51 ;
V_45 . V_52 = ( V_40 ? & V_40 : NULL ) ;
V_45 . V_53 = ( V_40 ? 1 : 0 ) ;
memcpy ( & div -> V_16 , V_16 , sizeof( * V_16 ) ) ;
div -> V_17 = V_17 ;
div -> V_42 = V_42 ;
div -> V_7 = V_43 ;
div -> V_12 . V_45 = & V_45 ;
div -> V_2 = V_2 ;
V_36 = F_33 ( V_38 , & div -> V_12 , V_39 ) ;
if ( F_34 ( V_36 ) )
F_35 ( div ) ;
return V_36 ;
}
int F_36 ( int * V_54 , int V_55 , int V_56 ,
T_1 V_7 , T_1 * V_42 ,
const struct V_1 * * V_2 )
{
int V_57 = 0 ;
T_2 V_10 ;
int div ;
int V_24 ;
struct V_1 * V_58 ;
if ( ! V_54 ) {
if ( V_7 & V_59 )
V_10 = 1 ;
else
V_10 = 0 ;
div = 1 ;
while ( div < V_56 ) {
if ( V_7 & V_60 )
div <<= 1 ;
else
div ++ ;
V_10 ++ ;
}
* V_42 = F_37 ( V_10 ) ;
* V_2 = NULL ;
return 0 ;
}
V_24 = 0 ;
while ( ! V_55 || V_24 < V_55 ) {
if ( V_54 [ V_24 ] == - 1 )
break;
if ( V_54 [ V_24 ] )
V_57 ++ ;
V_24 ++ ;
}
V_55 = V_24 ;
V_58 = F_31 ( sizeof( * V_58 ) * ( V_57 + 1 ) , V_46 ) ;
if ( ! V_58 )
return - V_48 ;
V_57 = 0 ;
* V_42 = 0 ;
for ( V_24 = 0 ; V_24 < V_55 ; V_24 ++ )
if ( V_54 [ V_24 ] > 0 ) {
V_58 [ V_57 ] . div = V_54 [ V_24 ] ;
V_58 [ V_57 ] . V_10 = V_24 ;
V_57 ++ ;
* V_42 = V_24 ;
}
* V_42 = F_37 ( * V_42 ) ;
* V_2 = V_58 ;
return 0 ;
}
static const struct V_1 *
F_38 ( struct V_61 * V_62 , T_1 * V_42 )
{
const struct V_1 * V_2 = NULL ;
F_36 ( V_62 -> V_63 , V_62 -> V_55 ,
V_62 -> V_56 , V_62 -> V_7 , V_42 ,
& V_2 ) ;
return V_2 ;
}
struct V_11 * F_39 ( struct V_61 * V_62 )
{
struct V_5 * div ;
struct V_41 * V_16 ;
if ( ! V_62 )
return NULL ;
div = F_31 ( sizeof( * div ) , V_46 ) ;
if ( ! div )
return F_30 ( - V_48 ) ;
V_16 = (struct V_41 * ) & div -> V_16 ;
V_16 -> V_64 = V_62 -> V_65 ;
V_16 -> V_66 = V_62 -> V_16 ;
if ( V_62 -> V_7 & V_59 )
div -> V_7 |= V_8 ;
if ( V_62 -> V_7 & V_60 )
div -> V_7 |= V_9 ;
div -> V_2 = F_38 ( V_62 , & div -> V_42 ) ;
div -> V_17 = V_62 -> V_67 ;
return & div -> V_12 ;
}
struct V_36 * F_40 ( struct V_68 * V_62 )
{
struct V_61 * div = V_62 -> V_69 ;
struct V_41 V_16 = {
. V_64 = div -> V_65 ,
. V_66 = div -> V_16 ,
} ;
T_1 V_42 ;
T_2 V_7 = 0 ;
T_1 V_70 = 0 ;
const struct V_1 * V_2 ;
struct V_36 * V_36 ;
if ( div -> V_7 & V_59 )
V_70 |= V_8 ;
if ( div -> V_7 & V_60 )
V_70 |= V_9 ;
if ( div -> V_7 & V_71 )
V_7 |= V_29 ;
V_2 = F_38 ( div , & V_42 ) ;
if ( F_34 ( V_2 ) )
return (struct V_36 * ) V_2 ;
V_36 = F_28 ( NULL , V_62 -> V_39 , div -> V_72 ,
V_7 , & V_16 , div -> V_67 ,
V_42 , V_70 , V_2 ) ;
if ( F_34 ( V_36 ) )
F_35 ( V_2 ) ;
return V_36 ;
}
static struct V_1 *
T_3 F_41 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
const T_4 * V_75 ;
T_2 V_10 ;
T_2 V_76 ;
T_2 V_57 ;
int V_24 ;
V_75 = F_42 ( V_74 , L_4 , & V_76 ) ;
if ( ! V_75 )
return NULL ;
V_76 /= 4 ;
V_57 = 0 ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ ) {
F_43 ( V_74 , L_4 , V_24 , & V_10 ) ;
if ( V_10 )
V_57 ++ ;
}
if ( ! V_57 ) {
F_32 ( L_5 , V_74 -> V_39 ) ;
return F_30 ( - V_33 ) ;
}
V_2 = F_31 ( sizeof( * V_2 ) * ( V_57 + 1 ) , V_46 ) ;
if ( ! V_2 )
return F_30 ( - V_48 ) ;
V_57 = 0 ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ ) {
F_43 ( V_74 , L_4 , V_24 , & V_10 ) ;
if ( V_10 ) {
V_2 [ V_57 ] . div = V_10 ;
V_2 [ V_57 ] . V_10 = V_24 ;
V_57 ++ ;
}
}
return V_2 ;
}
static int F_44 ( struct V_73 * V_74 ,
const struct V_1 * V_2 ,
T_1 V_7 )
{
T_2 V_77 ;
T_2 V_56 ;
T_2 V_10 = 0 ;
T_2 div ;
if ( ! V_2 ) {
if ( F_45 ( V_74 , L_6 , & V_77 ) )
V_77 = 1 ;
if ( F_45 ( V_74 , L_7 , & V_56 ) ) {
F_32 ( L_8 , V_74 -> V_39 ) ;
return - V_33 ;
}
if ( V_7 & V_8 )
V_10 = 1 ;
div = V_77 ;
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
return F_37 ( V_10 ) ;
}
static int T_3 F_46 ( struct V_73 * V_74 ,
struct V_41 * V_16 , const struct V_1 * * V_2 ,
T_2 * V_7 , T_1 * V_70 , T_1 * V_42 , T_1 * V_17 )
{
T_2 V_10 ;
int V_78 ;
V_78 = F_47 ( V_74 , 0 , V_16 ) ;
if ( V_78 )
return V_78 ;
if ( ! F_45 ( V_74 , L_9 , & V_10 ) )
* V_17 = V_10 ;
else
* V_17 = 0 ;
* V_7 = 0 ;
* V_70 = 0 ;
if ( F_48 ( V_74 , L_10 ) )
* V_70 |= V_8 ;
if ( F_48 ( V_74 , L_11 ) )
* V_70 |= V_9 ;
if ( F_48 ( V_74 , L_12 ) )
* V_7 |= V_29 ;
* V_2 = F_41 ( V_74 ) ;
if ( F_34 ( * V_2 ) )
return F_49 ( * V_2 ) ;
* V_42 = F_44 ( V_74 , * V_2 , * V_70 ) ;
return 0 ;
}
static void T_3 F_50 ( struct V_73 * V_74 )
{
struct V_36 * V_36 ;
const char * V_40 ;
struct V_41 V_16 ;
T_1 V_43 = 0 ;
T_1 V_42 = 0 ;
T_1 V_17 = 0 ;
const struct V_1 * V_2 = NULL ;
T_2 V_7 = 0 ;
V_40 = F_51 ( V_74 , 0 ) ;
if ( F_46 ( V_74 , & V_16 , & V_2 , & V_7 ,
& V_43 , & V_42 , & V_17 ) )
goto V_79;
V_36 = F_28 ( NULL , V_74 -> V_39 , V_40 , V_7 , & V_16 ,
V_17 , V_42 , V_43 , V_2 ) ;
if ( ! F_34 ( V_36 ) ) {
F_52 ( V_74 , V_80 , V_36 ) ;
F_53 ( V_74 ) ;
return;
}
V_79:
F_35 ( V_2 ) ;
}
static void T_3 F_54 ( struct V_73 * V_74 )
{
struct V_5 * div ;
T_2 V_10 ;
div = F_31 ( sizeof( * div ) , V_46 ) ;
if ( ! div )
return;
if ( F_46 ( V_74 , & div -> V_16 , & div -> V_2 , & V_10 ,
& div -> V_7 , & div -> V_42 , & div -> V_17 ) < 0 )
goto V_79;
if ( ! F_55 ( V_74 , & div -> V_12 , V_81 ) )
return;
V_79:
F_35 ( div -> V_2 ) ;
F_35 ( div ) ;
}
