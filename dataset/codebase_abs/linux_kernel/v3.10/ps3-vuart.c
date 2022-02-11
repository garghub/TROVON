static struct V_1 * F_1 (
struct V_2 * V_3 )
{
F_2 ( ! V_3 ) ;
F_2 ( ! V_3 -> V_4 ) ;
return (struct V_1 * ) V_3 -> V_4 ;
}
static void T_1 F_3 (
const struct V_5 * V_6 , const char * V_7 , int line )
{
F_4 ( L_1 , V_7 , line , V_6 -> V_8 ) ;
}
static void T_1 F_5 ( unsigned int V_9 ,
const char * V_7 , int line )
{
#if F_6 ( V_10 )
static const char * V_11 [] = {
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
} ;
int V_12 ;
unsigned int V_13 ;
T_2 V_14 ;
for ( V_13 = 0 ; V_13 < F_7 ( V_11 ) ; V_13 ++ ) {
V_12 = F_8 ( V_9 , V_13 , & V_14 ) ;
if ( V_12 ) {
F_4 ( L_10 , V_7 , line ,
V_9 , V_11 [ V_13 ] , F_9 ( V_12 ) ) ;
continue;
}
F_4 ( L_11 ,
V_7 , line , V_9 , V_11 [ V_13 ] , V_14 ) ;
}
#endif
}
int F_10 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
int V_12 ;
T_2 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
V_12 = F_8 ( V_3 -> V_9 ,
V_20 , & V_19 ) ;
V_16 -> V_19 = V_19 ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_12 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_12 = F_8 ( V_3 -> V_9 ,
V_23 , & V_17 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_13 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_12 = F_8 ( V_3 -> V_9 ,
V_24 , & V_18 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_14 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_16 -> V_25 = V_17 - V_18 ;
F_11 ( & V_3 -> V_21 , L_15 , V_22 , __LINE__ ,
V_16 -> V_19 , V_16 -> V_25 ) ;
return V_12 ;
}
int F_12 ( struct V_2 * V_3 , unsigned int V_19 ,
unsigned int V_25 )
{
int V_12 ;
T_2 V_17 ;
V_12 = F_13 ( V_3 -> V_9 ,
V_20 , V_19 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_12 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_12 = F_8 ( V_3 -> V_9 ,
V_23 , & V_17 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_13 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_12 = F_13 ( V_3 -> V_9 ,
V_24 , V_17 - V_25 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_14 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
F_11 ( & V_3 -> V_21 , L_16 , V_22 , __LINE__ ,
V_19 , V_25 ) ;
return V_12 ;
}
static int F_14 ( struct V_2 * V_3 ,
T_2 * V_26 )
{
int V_12 ;
V_12 = F_8 ( V_3 -> V_9 ,
V_27 , V_26 ) ;
if ( V_12 )
F_11 ( & V_3 -> V_21 , L_17 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
F_11 ( & V_3 -> V_21 , L_18 , V_22 , __LINE__ ,
* V_26 ) ;
return V_12 ;
}
static int F_15 ( struct V_2 * V_3 ,
unsigned long V_28 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
F_11 ( & V_3 -> V_21 , L_19 , V_22 , __LINE__ , V_28 ) ;
V_29 -> V_30 = V_28 ;
V_12 = F_13 ( V_3 -> V_9 ,
V_31 , V_29 -> V_30 ) ;
if ( V_12 )
F_11 ( & V_3 -> V_21 , L_20 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
static int F_16 ( struct V_2 * V_3 ,
unsigned long * V_8 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
T_2 V_32 ;
V_12 = F_8 ( V_3 -> V_9 ,
V_33 , & V_32 ) ;
if ( V_12 )
F_11 ( & V_3 -> V_21 , L_21 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
* V_8 = V_32 & V_29 -> V_30 ;
F_11 ( & V_3 -> V_21 , L_22 ,
V_22 , __LINE__ , V_29 -> V_30 , V_32 , * V_8 ) ;
return V_12 ;
}
int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_30 & V_34 ) ? 0
: F_15 ( V_3 , V_29 -> V_30
| V_34 ) ;
}
int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_30 & V_35 ) ? 0
: F_15 ( V_3 , V_29 -> V_30
| V_35 ) ;
}
int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_30 & V_36 ) ? 0
: F_15 ( V_3 , V_29 -> V_30
| V_36 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_30 & V_34 )
? F_15 ( V_3 , V_29 -> V_30
& ~ V_34 ) : 0 ;
}
int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_30 & V_35 )
? F_15 ( V_3 , V_29 -> V_30
& ~ V_35 ) : 0 ;
}
int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_30 & V_36 )
? F_15 ( V_3 , V_29 -> V_30
& ~ V_36 ) : 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
const void * V_37 , unsigned int V_38 , T_2 * V_39 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
V_12 = F_24 ( V_3 -> V_9 ,
F_25 ( F_26 ( V_37 ) ) , V_38 , V_39 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_23
L_24 , V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_29 -> V_40 . V_39 += * V_39 ;
F_11 ( & V_3 -> V_21 , L_25 , V_22 , __LINE__ ,
* V_39 , V_38 , V_29 -> V_40 . V_39 ) ;
return V_12 ;
}
static int F_27 ( struct V_2 * V_3 , void * V_37 ,
unsigned int V_38 , T_2 * V_41 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
F_11 ( & V_3 -> V_21 , L_26 , V_22 , __LINE__ , V_38 ) ;
V_12 = F_28 ( V_3 -> V_9 ,
F_25 ( F_26 ( V_37 ) ) , V_38 , V_41 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_27 ,
V_22 , __LINE__ , F_9 ( V_12 ) ) ;
return V_12 ;
}
V_29 -> V_40 . V_41 += * V_41 ;
F_11 ( & V_3 -> V_21 , L_28 , V_22 , __LINE__ ,
* V_41 , V_38 , V_29 -> V_40 . V_41 ) ;
return V_12 ;
}
void F_29 ( struct V_2 * V_3 ,
unsigned int V_38 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
T_2 V_26 ;
void * V_32 ;
V_12 = F_14 ( V_3 , & V_26 ) ;
F_2 ( V_12 ) ;
V_38 = V_38 ? F_30 ( V_38 , ( unsigned int ) V_26 ) : V_26 ;
F_11 ( & V_3 -> V_21 , L_29 , V_22 , __LINE__ , V_38 ) ;
if ( ! V_38 )
return;
V_38 += 128 ;
V_32 = F_31 ( V_38 , V_42 ) ;
if ( ! V_32 )
return;
F_27 ( V_3 , V_32 , V_38 , & V_26 ) ;
F_32 ( V_32 ) ;
V_29 -> V_40 . V_41 -= V_26 ;
}
int F_33 ( struct V_2 * V_3 , const void * V_37 ,
unsigned int V_38 )
{
static unsigned long V_43 ;
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
unsigned long V_44 ;
struct V_45 * V_46 ;
F_11 ( & V_3 -> V_21 , L_30 , V_22 , __LINE__ ,
V_38 , V_38 ) ;
F_34 ( & V_29 -> V_47 . V_48 , V_44 ) ;
if ( F_35 ( & V_29 -> V_47 . V_49 ) ) {
T_2 V_39 ;
V_12 = F_23 ( V_3 , V_37 , V_38 , & V_39 ) ;
F_36 ( & V_29 -> V_47 . V_48 , V_44 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 ,
L_31 ,
V_22 , __LINE__ ) ;
return V_12 ;
}
if ( V_39 == V_38 ) {
F_11 ( & V_3 -> V_21 , L_32 ,
V_22 , __LINE__ , V_38 ) ;
return 0 ;
}
V_38 -= V_39 ;
V_37 += V_39 ;
} else
F_36 ( & V_29 -> V_47 . V_48 , V_44 ) ;
V_46 = F_31 ( sizeof( struct V_45 ) + V_38 , V_42 ) ;
if ( ! V_46 )
return - V_50 ;
memcpy ( V_46 -> V_51 , V_37 , V_38 ) ;
V_46 -> V_49 = V_46 -> V_51 ;
V_46 -> V_52 = V_46 -> V_51 + V_38 ;
V_46 -> V_43 = ++ V_43 ;
F_34 ( & V_29 -> V_47 . V_48 , V_44 ) ;
F_37 ( & V_46 -> V_53 , & V_29 -> V_47 . V_49 ) ;
F_17 ( V_3 ) ;
F_36 ( & V_29 -> V_47 . V_48 , V_44 ) ;
F_11 ( & V_3 -> V_21 , L_33 ,
V_22 , __LINE__ , V_46 -> V_43 , V_38 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
T_2 * V_54 )
{
static unsigned long V_43 ;
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
struct V_45 * V_46 ;
T_2 V_38 ;
* V_54 = 0 ;
V_12 = F_14 ( V_3 , & V_38 ) ;
F_2 ( V_12 ) ;
if ( V_12 )
return - V_55 ;
if ( ! V_38 )
return 0 ;
V_38 += 128 ;
V_46 = F_31 ( sizeof( struct V_45 ) + V_38 , V_56 ) ;
if ( ! V_46 )
return - V_50 ;
F_27 ( V_3 , V_46 -> V_51 , V_38 , & V_38 ) ;
V_46 -> V_49 = V_46 -> V_51 ;
V_46 -> V_52 = V_46 -> V_51 + V_38 ;
V_46 -> V_43 = ++ V_43 ;
F_37 ( & V_46 -> V_53 , & V_29 -> V_57 . V_49 ) ;
V_29 -> V_57 . V_58 += V_38 ;
F_11 ( & V_3 -> V_21 , L_34 ,
V_22 , __LINE__ , V_46 -> V_43 , V_38 ) ;
* V_54 = V_38 ;
return 0 ;
}
int F_39 ( struct V_2 * V_3 , void * V_37 ,
unsigned int V_38 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
unsigned long V_44 ;
struct V_45 * V_46 , * V_59 ;
unsigned long V_41 ;
F_11 ( & V_3 -> V_21 , L_30 , V_22 , __LINE__ ,
V_38 , V_38 ) ;
F_34 ( & V_29 -> V_57 . V_48 , V_44 ) ;
while ( V_29 -> V_57 . V_58 < V_38 ) {
T_2 V_32 ;
V_12 = F_38 ( V_3 , & V_32 ) ;
if ( V_12 || ! V_32 ) {
F_11 ( & V_3 -> V_21 , L_35 ,
V_22 , __LINE__ ,
V_38 - V_29 -> V_57 . V_58 ) ;
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
return - V_60 ;
}
}
F_40 (lb, n, &priv->rx_list.head, link) {
V_41 = F_30 ( ( unsigned int ) ( V_46 -> V_52 - V_46 -> V_49 ) , V_38 ) ;
memcpy ( V_37 , V_46 -> V_49 , V_41 ) ;
V_37 += V_41 ;
V_38 -= V_41 ;
V_29 -> V_57 . V_58 -= V_41 ;
if ( V_41 < V_46 -> V_52 - V_46 -> V_49 ) {
V_46 -> V_49 += V_41 ;
F_11 ( & V_3 -> V_21 , L_36
L_37 , V_22 , __LINE__ , V_46 -> V_43 ,
V_41 ) ;
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
return 0 ;
}
F_11 ( & V_3 -> V_21 , L_38
L_37 , V_22 , __LINE__ , V_46 -> V_43 ,
V_41 ) ;
F_41 ( & V_46 -> V_53 ) ;
F_32 ( V_46 ) ;
}
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
return 0 ;
}
static void F_42 ( struct V_61 * V_62 )
{
struct V_2 * V_3 =
F_43 ( V_62 ) ;
struct V_63 * V_64 =
F_44 ( V_3 ) ;
F_2 ( ! V_64 ) ;
V_64 -> V_62 ( V_3 ) ;
}
int F_45 ( struct V_2 * V_3 , unsigned int V_38 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
unsigned long V_44 ;
if ( V_29 -> V_57 . V_62 . V_65 ) {
F_11 ( & V_3 -> V_21 , L_39 ,
V_22 , __LINE__ ) ;
return - V_60 ;
}
F_2 ( ! V_38 ) ;
F_46 ( & V_29 -> V_57 . V_62 . V_62 , F_42 ) ;
F_34 ( & V_29 -> V_57 . V_48 , V_44 ) ;
if ( V_29 -> V_57 . V_58 >= V_38 ) {
F_11 ( & V_3 -> V_21 , L_40 ,
V_22 , __LINE__ , V_38 ) ;
F_47 ( & V_29 -> V_57 . V_62 . V_62 ) ;
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
return 0 ;
}
V_29 -> V_57 . V_62 . V_65 = V_38 ;
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
F_11 ( & V_3 -> V_21 , L_41 , V_22 ,
__LINE__ , V_38 , V_38 ) ;
return 0 ;
}
void F_48 ( struct V_2 * V_3 )
{
F_1 ( V_3 ) -> V_57 . V_62 . V_65 = 0 ;
}
static int F_49 ( struct V_2 * V_3 )
{
int V_12 = 0 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
unsigned long V_44 ;
struct V_45 * V_46 , * V_59 ;
unsigned long V_66 = 0 ;
F_11 ( & V_3 -> V_21 , L_42 , V_22 , __LINE__ ) ;
F_34 ( & V_29 -> V_47 . V_48 , V_44 ) ;
F_40 (lb, n, &priv->tx_list.head, link) {
T_2 V_39 ;
V_12 = F_23 ( V_3 , V_46 -> V_49 , V_46 -> V_52 - V_46 -> V_49 ,
& V_39 ) ;
if ( V_12 ) {
F_11 ( & V_3 -> V_21 ,
L_31 ,
V_22 , __LINE__ ) ;
break;
}
V_66 += V_39 ;
if ( V_39 < V_46 -> V_52 - V_46 -> V_49 ) {
V_46 -> V_49 += V_39 ;
F_11 ( & V_3 -> V_21 ,
L_43 ,
V_22 , __LINE__ , V_46 -> V_43 ,
V_39 ) ;
goto V_67;
}
F_11 ( & V_3 -> V_21 , L_44 , V_22 , __LINE__ ,
V_46 -> V_43 ) ;
F_41 ( & V_46 -> V_53 ) ;
F_32 ( V_46 ) ;
}
F_20 ( V_3 ) ;
V_67:
F_36 ( & V_29 -> V_47 . V_48 , V_44 ) ;
F_11 ( & V_3 -> V_21 , L_45 ,
V_22 , __LINE__ , V_66 ) ;
return V_12 ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
unsigned long V_44 ;
T_2 V_38 ;
F_11 ( & V_3 -> V_21 , L_42 , V_22 , __LINE__ ) ;
F_34 ( & V_29 -> V_57 . V_48 , V_44 ) ;
V_12 = F_38 ( V_3 , & V_38 ) ;
if ( V_12 ) {
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
return V_12 ;
}
if ( V_29 -> V_57 . V_62 . V_65 && V_29 -> V_57 . V_58
>= V_29 -> V_57 . V_62 . V_65 ) {
F_11 ( & V_3 -> V_21 , L_46 ,
V_22 , __LINE__ , V_29 -> V_57 . V_62 . V_65 ) ;
V_29 -> V_57 . V_62 . V_65 = 0 ;
F_47 ( & V_29 -> V_57 . V_62 . V_62 ) ;
}
F_36 ( & V_29 -> V_57 . V_48 , V_44 ) ;
return V_12 ;
}
static int F_51 (
struct V_2 * V_3 )
{
F_11 ( & V_3 -> V_21 , L_42 , V_22 , __LINE__ ) ;
F_2 ( L_47 ) ;
return - 1 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_12 ;
struct V_1 * V_29 = F_1 ( V_3 ) ;
unsigned long V_8 ;
V_12 = F_16 ( V_3 , & V_8 ) ;
if ( V_12 )
return V_12 ;
F_11 ( & V_3 -> V_21 , L_48 , V_22 , __LINE__ ,
V_8 ) ;
if ( V_8 & V_36 ) {
V_29 -> V_40 . V_68 ++ ;
V_12 = F_51 ( V_3 ) ;
if ( V_12 )
F_22 ( V_3 ) ;
}
if ( V_8 & V_34 ) {
V_29 -> V_40 . V_69 ++ ;
V_12 = F_49 ( V_3 ) ;
if ( V_12 )
F_20 ( V_3 ) ;
}
if ( V_8 & V_35 ) {
V_29 -> V_40 . V_70 ++ ;
V_12 = F_50 ( V_3 ) ;
if ( V_12 )
F_21 ( V_3 ) ;
}
return 0 ;
}
static T_3 F_53 ( int V_71 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
F_2 ( ! V_74 ) ;
while ( 1 ) {
unsigned int V_75 ;
F_54 ( V_74 -> V_6 ) ;
V_75 = ( V_76 - 1 ) - F_55 ( V_74 -> V_6 -> V_8 ) ;
if ( V_75 == V_76 )
break;
F_2 ( V_75 >= V_77 ) ;
F_2 ( ! V_74 -> V_78 [ V_75 ] ) ;
F_52 ( V_74 -> V_78 [ V_75 ] ) ;
}
return V_79 ;
}
static int F_56 ( void )
{
int V_12 ;
F_4 ( L_49 , V_22 , __LINE__ ) ;
V_73 . V_80 ++ ;
F_2 ( V_73 . V_80 > 2 ) ;
if ( V_73 . V_80 != 1 )
return 0 ;
F_2 ( V_73 . V_6 ) ;
V_73 . V_6 = F_57 ( sizeof( struct V_5 ) , V_42 ) ;
if ( ! V_73 . V_6 ) {
F_4 ( L_50 , V_22 , __LINE__ ) ;
V_12 = - V_50 ;
goto V_81;
}
V_12 = F_58 ( V_82 , V_73 . V_6 ,
& V_73 . V_83 ) ;
if ( V_12 ) {
F_4 ( L_51 ,
V_22 , __LINE__ , V_12 ) ;
V_12 = - V_84 ;
goto V_85;
}
V_12 = F_59 ( V_73 . V_83 , F_53 ,
0 , L_52 , & V_73 ) ;
if ( V_12 ) {
F_4 ( L_53 ,
V_22 , __LINE__ , V_12 ) ;
goto V_86;
}
F_4 ( L_54 , V_22 , __LINE__ ) ;
return V_12 ;
V_86:
F_60 ( V_73 . V_83 ) ;
V_73 . V_83 = V_87 ;
V_85:
F_32 ( V_73 . V_6 ) ;
V_73 . V_6 = NULL ;
V_81:
V_73 . V_80 -- ;
F_4 ( L_55 , V_22 , __LINE__ ) ;
return V_12 ;
}
static int F_61 ( void )
{
F_4 ( L_49 , V_22 , __LINE__ ) ;
V_73 . V_80 -- ;
F_2 ( V_73 . V_80 < 0 ) ;
if ( V_73 . V_80 != 0 )
return 0 ;
F_62 ( V_73 . V_83 , & V_73 ) ;
F_60 ( V_73 . V_83 ) ;
V_73 . V_83 = V_87 ;
F_32 ( V_73 . V_6 ) ;
V_73 . V_6 = NULL ;
F_4 ( L_56 , V_22 , __LINE__ ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 )
{
int V_12 ;
struct V_63 * V_64 ;
struct V_1 * V_29 = NULL ;
F_11 ( & V_3 -> V_21 , L_42 , V_22 , __LINE__ ) ;
V_64 = F_44 ( V_3 ) ;
F_11 ( & V_3 -> V_21 , L_57 , V_22 , __LINE__ ,
V_64 -> V_21 . V_21 . V_88 ) ;
F_2 ( ! V_64 ) ;
if ( V_3 -> V_9 >= V_77 ) {
F_64 () ;
return - V_89 ;
}
F_65 ( & V_73 . V_90 ) ;
V_12 = F_56 () ;
if ( V_12 )
goto V_91;
if ( V_73 . V_78 [ V_3 -> V_9 ] ) {
F_11 ( & V_3 -> V_21 , L_58 , V_22 ,
__LINE__ , V_3 -> V_9 ) ;
V_12 = - V_92 ;
goto V_93;
}
V_73 . V_78 [ V_3 -> V_9 ] = V_3 ;
V_3 -> V_4 = F_57 ( sizeof( struct V_1 ) ,
V_42 ) ;
if ( ! V_3 -> V_4 ) {
V_12 = - V_50 ;
goto V_94;
}
V_29 = F_1 ( V_3 ) ;
F_66 ( & V_29 -> V_47 . V_49 ) ;
F_67 ( & V_29 -> V_47 . V_48 ) ;
F_66 ( & V_29 -> V_57 . V_49 ) ;
F_67 ( & V_29 -> V_57 . V_48 ) ;
F_68 ( & V_29 -> V_57 . V_62 . V_62 , NULL ) ;
V_29 -> V_57 . V_62 . V_65 = 0 ;
V_29 -> V_57 . V_62 . V_3 = V_3 ;
F_29 ( V_3 , 0 ) ;
F_15 ( V_3 , V_35 ) ;
F_12 ( V_3 , 1 , 1 ) ;
if ( V_64 -> V_95 )
V_12 = V_64 -> V_95 ( V_3 ) ;
else {
V_12 = 0 ;
F_69 ( & V_3 -> V_21 , L_59 , V_22 ,
__LINE__ ) ;
}
if ( V_12 ) {
F_11 ( & V_3 -> V_21 , L_60 ,
V_22 , __LINE__ ) ;
goto V_96;
}
F_70 ( & V_73 . V_90 ) ;
return V_12 ;
V_96:
F_15 ( V_3 , 0 ) ;
F_32 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
V_94:
V_73 . V_78 [ V_3 -> V_9 ] = NULL ;
V_93:
F_61 () ;
V_91:
F_70 ( & V_73 . V_90 ) ;
F_11 ( & V_3 -> V_21 , L_61 , V_22 , __LINE__ ) ;
return V_12 ;
}
static int F_71 ( struct V_2 * V_3 )
{
F_11 ( & V_3 -> V_21 , L_42 , V_22 , __LINE__ ) ;
F_48 ( V_3 ) ;
F_15 ( V_3 , 0 ) ;
F_61 () ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
struct V_63 * V_64 ;
F_2 ( ! V_3 ) ;
F_65 ( & V_73 . V_90 ) ;
F_11 ( & V_3 -> V_21 , L_62 , V_22 , __LINE__ ,
V_3 -> V_97 ) ;
if ( ! V_3 -> V_21 . V_98 ) {
F_11 ( & V_3 -> V_21 , L_63 , V_22 ,
__LINE__ ) ;
F_70 ( & V_73 . V_90 ) ;
return 0 ;
}
V_64 = F_44 ( V_3 ) ;
F_2 ( ! V_64 ) ;
if ( V_64 -> remove ) {
V_64 -> remove ( V_3 ) ;
} else {
F_11 ( & V_3 -> V_21 , L_64 , V_22 ,
__LINE__ ) ;
F_64 () ;
}
F_71 ( V_3 ) ;
V_73 . V_78 [ V_3 -> V_9 ] = NULL ;
F_32 ( V_29 ) ;
V_29 = NULL ;
F_11 ( & V_3 -> V_21 , L_56 , V_22 , __LINE__ ) ;
F_70 ( & V_73 . V_90 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_63 * V_64 ;
F_2 ( ! V_3 ) ;
F_65 ( & V_73 . V_90 ) ;
F_11 ( & V_3 -> V_21 , L_62 , V_22 , __LINE__ ,
V_3 -> V_97 ) ;
if ( ! V_3 -> V_21 . V_98 ) {
F_11 ( & V_3 -> V_21 , L_63 , V_22 ,
__LINE__ ) ;
F_70 ( & V_73 . V_90 ) ;
return 0 ;
}
V_64 = F_44 ( V_3 ) ;
F_2 ( ! V_64 ) ;
if ( V_64 -> V_99 )
V_64 -> V_99 ( V_3 ) ;
else if ( V_64 -> remove ) {
F_11 ( & V_3 -> V_21 , L_65 ,
V_22 , __LINE__ ) ;
V_64 -> remove ( V_3 ) ;
} else {
F_11 ( & V_3 -> V_21 , L_66 , V_22 ,
__LINE__ ) ;
F_64 () ;
}
F_71 ( V_3 ) ;
F_11 ( & V_3 -> V_21 , L_56 , V_22 , __LINE__ ) ;
F_70 ( & V_73 . V_90 ) ;
return 0 ;
}
static int T_4 F_74 ( void )
{
F_4 ( L_67 , V_22 , __LINE__ ) ;
if ( ! F_75 ( V_100 ) )
return - V_101 ;
F_76 ( & V_73 . V_90 ) ;
return 0 ;
}
static void T_5 F_77 ( void )
{
F_4 ( L_67 , V_22 , __LINE__ ) ;
}
int F_78 ( struct V_63 * V_64 )
{
int V_12 ;
F_4 ( L_57 , V_22 , __LINE__ , V_64 -> V_21 . V_21 . V_88 ) ;
F_2 ( ! V_64 -> V_21 . V_97 ) ;
F_2 ( ! V_64 -> V_21 . V_21 . V_88 ) ;
V_64 -> V_21 . V_95 = F_63 ;
V_64 -> V_21 . remove = F_72 ;
V_64 -> V_21 . V_99 = F_73 ;
V_12 = F_79 ( & V_64 -> V_21 ) ;
return V_12 ;
}
void F_80 ( struct V_63 * V_64 )
{
F_4 ( L_57 , V_22 , __LINE__ , V_64 -> V_21 . V_21 . V_88 ) ;
F_81 ( & V_64 -> V_21 ) ;
}
