static struct V_1 * F_1 ( unsigned long V_2 )
{
unsigned int V_3 ;
T_1 * V_4 = F_2 ( V_2 , & V_3 ) ;
if ( ! V_4 )
return NULL ;
V_2 &= F_3 ( V_3 ) ;
return & V_5 [ F_4 ( V_2 , V_6 ) ] ;
}
static struct V_7 * F_5 ( unsigned long V_2 )
{
struct V_7 * V_8 ;
F_6 (p, &kmmio_probes, list) {
if ( V_2 >= V_8 -> V_2 && V_2 < ( V_8 -> V_2 + V_8 -> V_9 ) )
return V_8 ;
}
return NULL ;
}
static struct V_10 * F_7 ( unsigned long V_2 )
{
struct V_1 * V_11 ;
struct V_10 * V_12 ;
unsigned int V_3 ;
T_1 * V_4 = F_2 ( V_2 , & V_3 ) ;
if ( ! V_4 )
return NULL ;
V_2 &= F_3 ( V_3 ) ;
V_11 = F_1 ( V_2 ) ;
F_6 (f, head, list) {
if ( V_12 -> V_2 == V_2 )
return V_12 ;
}
return NULL ;
}
static void F_8 ( T_2 * V_13 , bool V_14 , T_3 * V_15 )
{
T_3 V_16 = F_9 ( * V_13 ) ;
if ( V_14 ) {
* V_15 = V_16 & V_17 ;
V_16 &= ~ V_17 ;
} else
V_16 |= * V_15 ;
F_10 ( V_13 , F_11 ( V_16 ) ) ;
}
static void F_12 ( T_1 * V_4 , bool V_14 , T_4 * V_15 )
{
T_4 V_16 = F_13 ( * V_4 ) ;
if ( V_14 ) {
* V_15 = V_16 & V_17 ;
V_16 &= ~ V_17 ;
} else
V_16 |= * V_15 ;
F_14 ( V_4 , F_15 ( V_16 ) ) ;
}
static int F_16 ( struct V_10 * V_12 , bool V_14 )
{
unsigned int V_18 ;
T_1 * V_4 = F_2 ( V_12 -> V_2 , & V_18 ) ;
if ( ! V_4 ) {
F_17 ( L_1 , V_12 -> V_2 ) ;
return - 1 ;
}
switch ( V_18 ) {
case V_19 :
F_8 ( ( T_2 * ) V_4 , V_14 , & V_12 -> V_20 ) ;
break;
case V_21 :
F_12 ( V_4 , V_14 , & V_12 -> V_20 ) ;
break;
default:
F_17 ( L_2 , V_18 ) ;
return - 1 ;
}
F_18 ( V_12 -> V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_12 )
{
int V_22 ;
F_20 (f->armed, KERN_ERR pr_fmt(L_3)) ;
if ( V_12 -> V_23 ) {
F_21 ( L_4 ,
V_12 -> V_2 , V_12 -> V_24 , ! ! V_12 -> V_20 ) ;
}
V_22 = F_16 ( V_12 , true ) ;
F_20 (ret < 0 , KERN_ERR pr_fmt(L_5),
f->addr) ;
V_12 -> V_23 = true ;
return V_22 ;
}
static void F_22 ( struct V_10 * V_12 )
{
int V_22 = F_16 ( V_12 , false ) ;
F_20 ( V_22 < 0 ,
V_25 L_6 , V_12 -> V_2 ) ;
V_12 -> V_23 = false ;
}
int F_23 ( struct V_26 * V_27 , unsigned long V_2 )
{
struct V_28 * V_29 ;
struct V_10 * V_30 ;
int V_22 = 0 ;
unsigned long V_31 = V_2 ;
unsigned int V_3 ;
T_1 * V_4 = F_2 ( V_2 , & V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_31 &= F_3 ( V_3 ) ;
F_24 () ;
F_25 () ;
V_30 = F_7 ( V_31 ) ;
if ( ! V_30 ) {
goto V_33;
}
V_29 = & F_26 ( V_34 ) ;
if ( V_29 -> V_35 ) {
if ( V_31 == V_29 -> V_2 ) {
F_27 ( L_7 ,
V_2 , F_28 () ) ;
if ( ! V_30 -> V_20 )
F_29 ( L_8 ,
V_2 , F_28 () ) ;
} else {
F_30 ( L_9 ,
F_28 () , V_2 ) ;
F_30 ( L_10 , V_29 -> V_2 ) ;
F_22 ( V_30 ) ;
}
goto V_36;
}
V_29 -> V_35 ++ ;
V_29 -> V_37 = V_30 ;
V_29 -> V_38 = F_5 ( V_31 ) ;
V_29 -> V_39 = ( V_27 -> V_40 & ( V_41 | V_42 ) ) ;
V_29 -> V_2 = V_31 ;
if ( V_29 -> V_38 && V_29 -> V_38 -> V_43 )
V_29 -> V_38 -> V_43 ( V_29 -> V_38 , V_27 , V_2 ) ;
V_27 -> V_40 |= V_41 ;
V_27 -> V_40 &= ~ V_42 ;
F_22 ( V_29 -> V_37 ) ;
F_31 ( V_34 ) ;
return 1 ;
V_36:
F_31 ( V_34 ) ;
V_33:
F_32 () ;
F_33 () ;
return V_22 ;
}
static int F_34 ( unsigned long V_44 , struct V_26 * V_27 )
{
int V_22 = 0 ;
struct V_28 * V_29 = & F_26 ( V_34 ) ;
if ( ! V_29 -> V_35 ) {
F_21 ( L_11 ,
F_28 () ) ;
goto V_45;
}
if ( V_29 -> V_38 && V_29 -> V_38 -> V_46 )
V_29 -> V_38 -> V_46 ( V_29 -> V_38 , V_44 , V_27 ) ;
F_35 ( & V_47 ) ;
if ( V_29 -> V_37 -> V_24 )
F_19 ( V_29 -> V_37 ) ;
F_36 ( & V_47 ) ;
V_27 -> V_40 &= ~ V_41 ;
V_27 -> V_40 |= V_29 -> V_39 ;
V_29 -> V_35 -- ;
F_37 ( V_29 -> V_35 ) ;
F_32 () ;
F_33 () ;
if ( ! ( V_27 -> V_40 & V_41 ) )
V_22 = 1 ;
V_45:
F_31 ( V_34 ) ;
return V_22 ;
}
static int F_38 ( unsigned long V_2 )
{
struct V_10 * V_12 ;
V_12 = F_7 ( V_2 ) ;
if ( V_12 ) {
if ( ! V_12 -> V_24 )
F_19 ( V_12 ) ;
V_12 -> V_24 ++ ;
return 0 ;
}
V_12 = F_39 ( sizeof( * V_12 ) , V_48 ) ;
if ( ! V_12 )
return - 1 ;
V_12 -> V_24 = 1 ;
V_12 -> V_2 = V_2 ;
if ( F_19 ( V_12 ) ) {
F_40 ( V_12 ) ;
return - 1 ;
}
F_41 ( & V_12 -> V_49 , F_1 ( V_12 -> V_2 ) ) ;
return 0 ;
}
static void F_42 ( unsigned long V_2 ,
struct V_10 * * V_50 )
{
struct V_10 * V_12 ;
V_12 = F_7 ( V_2 ) ;
if ( ! V_12 )
return;
V_12 -> V_24 -- ;
F_37 ( V_12 -> V_24 < 0 ) ;
if ( ! V_12 -> V_24 ) {
F_22 ( V_12 ) ;
if ( ! V_12 -> V_51 ) {
V_12 -> V_52 = * V_50 ;
* V_50 = V_12 ;
V_12 -> V_51 = true ;
}
}
}
int F_43 ( struct V_7 * V_8 )
{
unsigned long V_40 ;
int V_22 = 0 ;
unsigned long V_53 = 0 ;
const unsigned long V_54 = V_8 -> V_9 + ( V_8 -> V_2 & ~ V_55 ) ;
unsigned int V_3 ;
T_1 * V_4 ;
F_44 ( & V_47 , V_40 ) ;
if ( F_5 ( V_8 -> V_2 ) ) {
V_22 = - V_56 ;
goto V_45;
}
V_4 = F_2 ( V_8 -> V_2 , & V_3 ) ;
if ( ! V_4 ) {
V_22 = - V_32 ;
goto V_45;
}
V_57 ++ ;
F_41 ( & V_8 -> V_49 , & V_58 ) ;
while ( V_53 < V_54 ) {
if ( F_38 ( V_8 -> V_2 + V_53 ) )
F_17 ( L_12 ) ;
V_53 += F_45 ( V_3 ) ;
}
V_45:
F_46 ( & V_47 , V_40 ) ;
return V_22 ;
}
static void F_47 ( struct V_59 * V_11 )
{
struct V_60 * V_61 = F_48 (
V_11 ,
struct V_60 ,
V_62 ) ;
struct V_10 * V_12 = V_61 -> V_50 ;
while ( V_12 ) {
struct V_10 * V_63 = V_12 -> V_52 ;
F_37 ( V_12 -> V_24 ) ;
F_40 ( V_12 ) ;
V_12 = V_63 ;
}
F_40 ( V_61 ) ;
}
static void F_49 ( struct V_59 * V_11 )
{
struct V_60 * V_61 =
F_48 ( V_11 , struct V_60 , V_62 ) ;
struct V_10 * V_12 = V_61 -> V_50 ;
struct V_10 * * V_64 = & V_61 -> V_50 ;
unsigned long V_40 ;
F_44 ( & V_47 , V_40 ) ;
while ( V_12 ) {
if ( ! V_12 -> V_24 ) {
F_50 ( & V_12 -> V_49 ) ;
V_64 = & V_12 -> V_52 ;
} else {
* V_64 = V_12 -> V_52 ;
V_12 -> V_52 = NULL ;
V_12 -> V_51 = false ;
}
V_12 = * V_64 ;
}
F_46 ( & V_47 , V_40 ) ;
F_51 ( & V_61 -> V_62 , F_47 ) ;
}
void F_52 ( struct V_7 * V_8 )
{
unsigned long V_40 ;
unsigned long V_53 = 0 ;
const unsigned long V_54 = V_8 -> V_9 + ( V_8 -> V_2 & ~ V_55 ) ;
struct V_10 * V_50 = NULL ;
struct V_60 * V_65 ;
unsigned int V_3 ;
T_1 * V_4 ;
V_4 = F_2 ( V_8 -> V_2 , & V_3 ) ;
if ( ! V_4 )
return;
F_44 ( & V_47 , V_40 ) ;
while ( V_53 < V_54 ) {
F_42 ( V_8 -> V_2 + V_53 , & V_50 ) ;
V_53 += F_45 ( V_3 ) ;
}
F_50 ( & V_8 -> V_49 ) ;
V_57 -- ;
F_46 ( & V_47 , V_40 ) ;
if ( ! V_50 )
return;
V_65 = F_53 ( sizeof( * V_65 ) , V_48 ) ;
if ( ! V_65 ) {
F_54 ( L_13 ) ;
return;
}
V_65 -> V_50 = V_50 ;
F_51 ( & V_65 -> V_62 , F_49 ) ;
}
static int
F_55 ( struct V_66 * V_67 , unsigned long V_68 , void * args )
{
struct V_69 * V_70 = args ;
unsigned long * V_71 = ( unsigned long * ) F_56 ( V_70 -> V_72 ) ;
if ( V_68 == V_73 && ( * V_71 & V_74 ) )
if ( F_34 ( * V_71 , V_70 -> V_27 ) == 1 ) {
* V_71 &= ~ V_74 ;
return V_75 ;
}
return V_76 ;
}
int F_57 ( void )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
F_58 ( & V_5 [ V_77 ] ) ;
return F_59 ( & V_79 ) ;
}
void F_60 ( void )
{
int V_77 ;
F_61 ( & V_79 ) ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
F_20 ( ! F_62 ( & V_5 [ V_77 ] ) ,
V_25 L_14 ) ;
}
}
