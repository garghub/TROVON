static int F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
if ( ! F_2 ( V_5 ) ) {
F_3 ( L_1 ,
V_6 ) ;
return - V_7 ;
}
F_4 ( V_8 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 )
F_4 ( V_12 ) ;
break;
}
return 0 ;
}
static int F_6 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_13 = 0 ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_15 ) {
V_13 = V_4 -> V_14 -> V_15 ( V_2 ) ;
if ( V_13 )
break;
}
}
return V_13 ;
}
static int F_7 ( struct V_16 * V_17 , void * V_18 )
{
struct V_1 * V_2 = F_8 ( V_17 -> V_19 ) ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_20 * V_21 = F_9 ( V_17 ) ;
struct V_22 * V_23 = F_10 ( V_21 ) ;
int V_13 ;
if ( ! V_21 || ! V_23 || V_23 -> V_24 )
return 0 ;
if ( ( V_17 -> V_25 >> 8 ) == V_26 )
return 0 ;
V_23 -> V_27 = V_17 -> V_25 ;
V_23 -> V_28 &= 0xFFFFFF00 ;
if ( V_17 -> V_29 == V_30 )
V_23 -> V_28 |= V_31 ;
V_23 -> V_32 = F_11 ( V_17 , V_33 ) ;
if ( F_12 ( V_17 ) ) {
V_23 -> V_34 = F_13 ( V_17 ) ;
if ( F_14 ( V_17 ) == V_35 )
V_23 -> V_28 |= V_36 ;
else if ( F_14 ( V_17 ) == V_37 )
V_23 -> V_28 |= V_38 ;
V_23 -> V_39 = F_15 ( V_17 ,
V_40 ) ;
}
V_23 -> V_41 = ( ( V_17 -> V_19 -> V_42 << 8 ) | V_17 -> V_43 ) ;
V_23 -> V_44 = V_4 -> V_45 ( V_4 , V_17 -> V_19 , V_17 -> V_43 & 0xff ) ;
V_13 = F_16 ( V_23 ) ;
if ( V_13 ) {
F_3 ( L_2 ,
V_6 , F_17 ( V_17 ) , V_13 ) ;
return V_13 ;
}
if ( ( V_17 -> V_46 == V_47 && V_17 -> V_48 == 0x1657 ) ||
( V_17 -> V_46 == V_47 && V_17 -> V_48 == 0x168e ) )
V_23 -> V_24 -> V_49 |= V_50 ;
if ( ! V_23 -> V_24 -> V_19 )
V_23 -> V_24 -> V_19 = V_17 -> V_19 ;
F_4 ( V_51 ) ;
F_18 ( V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_52 * V_24 , int V_53 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_54 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_55 )
V_13 = V_4 -> V_14 -> V_55 ( V_24 , V_53 ) ;
return V_13 ;
}
static int F_20 ( struct V_52 * V_24 )
{
return V_24 -> V_56 ;
}
static int F_21 ( struct V_52 * V_24 , int * V_57 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = V_58 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_59 ) {
V_13 = V_4 -> V_14 -> V_59 ( V_24 ) ;
if ( V_57 ) {
* V_57 = 0 ;
if ( V_13 & V_60 )
* V_57 = 1000 ;
}
}
return V_13 ;
}
static int F_22 ( struct V_52 * V_24 , int V_53 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_54 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_61 )
V_13 = V_4 -> V_14 -> V_61 ( V_24 , V_53 ) ;
return V_13 ;
}
static int F_23 ( struct V_52 * V_24 , int V_62 )
{
int V_13 ;
int V_63 ;
while ( 1 ) {
V_13 = F_21 ( V_24 , & V_63 ) ;
if ( V_13 != V_60 )
return V_13 ;
V_62 -= V_63 ;
if ( V_62 <= 0 ) {
F_3 ( L_3 ,
V_6 , V_24 -> V_56 , V_62 ) ;
return V_58 ;
}
F_24 ( V_63 ) ;
}
return V_58 ;
}
static int F_25 ( struct V_52 * V_24 , int V_64 ,
char * V_65 , unsigned long V_66 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_54 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_67 )
V_13 = V_4 -> V_14 -> V_67 ( V_24 , V_64 , V_65 , V_66 ) ;
return V_13 ;
}
static int F_26 ( struct V_52 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = 0 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_68 )
V_13 = V_4 -> V_14 -> V_68 ( V_24 ) ;
return V_13 ;
}
static int F_27 ( struct V_52 * V_24 , int type , int V_69 ,
unsigned long V_56 , unsigned long V_70 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_54 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_71 )
V_13 = V_4 -> V_14 -> V_71 ( V_24 , type , V_69 , V_56 , V_70 ) ;
return V_13 ;
}
static inline bool F_28 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_10 ( V_21 ) ;
if ( ! V_23 || ! V_23 -> V_24 )
return false ;
if ( V_23 -> V_24 -> V_49 & V_72 )
return true ;
return false ;
}
static int F_29 ( struct V_20 * V_21 ,
int V_73 , int V_74 , T_1 * V_75 )
{
if ( F_28 ( V_21 ) ) {
* V_75 = 0xFFFFFFFF ;
return V_76 ;
}
return F_30 ( V_21 , V_73 , V_74 , V_75 ) ;
}
static int F_31 ( struct V_20 * V_21 ,
int V_73 , int V_74 , T_1 V_75 )
{
if ( F_28 ( V_21 ) )
return V_76 ;
return F_32 ( V_21 , V_73 , V_74 , V_75 ) ;
}
static int F_33 ( struct V_52 * * V_24 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
break;
}
if ( V_4 && V_4 -> V_14 -> V_77 )
return V_4 -> V_14 -> V_77 ( V_24 ) ;
return - V_54 ;
}
static int F_34 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_10 ( V_21 ) ;
struct V_3 * V_4 ;
T_2 V_13 ;
if ( ! V_23 )
return - V_54 ;
V_4 = V_23 -> V_4 -> V_9 ;
V_13 = F_35 ( V_4 -> V_78 ,
V_79 , V_23 -> V_41 ) ;
if ( V_13 ) {
F_3 ( L_4 ,
V_6 , V_23 -> V_41 , V_13 ) ;
return - V_80 ;
}
return 0 ;
}
static int T_3 F_36 ( void )
{
int V_13 = - V_7 ;
F_37 ( V_81 ) ;
V_13 = F_38 ( & V_82 ) ;
if ( ! V_13 )
F_39 ( L_5 ) ;
else
F_39 ( L_6 , V_13 ) ;
return V_13 ;
}
