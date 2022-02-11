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
if ( V_4 -> V_13 . V_14 != 0 )
F_4 ( V_15 ) ;
break;
}
return 0 ;
}
static int F_6 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_16 = 0 ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_18 ) {
V_16 = V_4 -> V_17 -> V_18 ( V_2 ) ;
if ( V_16 )
break;
}
}
return V_16 ;
}
static int F_7 ( struct V_19 * V_20 , void * V_21 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_22 ) ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_23 * V_24 = F_9 ( V_20 ) ;
struct V_25 * V_26 = F_10 ( V_24 ) ;
int V_16 ;
if ( ! V_24 || ! V_26 || V_26 -> V_27 )
return 0 ;
if ( ( V_20 -> V_28 >> 8 ) == V_29 )
return 0 ;
V_26 -> V_30 = V_20 -> V_28 ;
V_26 -> V_31 &= 0xFFFFFF00 ;
if ( V_20 -> V_32 == V_33 )
V_26 -> V_31 |= V_34 ;
V_26 -> V_35 = F_11 ( V_20 , V_36 ) ;
if ( F_12 ( V_20 ) ) {
V_26 -> V_37 = F_13 ( V_20 ) ;
if ( F_14 ( V_20 ) == V_38 )
V_26 -> V_31 |= V_39 ;
else if ( F_14 ( V_20 ) == V_40 )
V_26 -> V_31 |= V_41 ;
V_26 -> V_42 = F_15 ( V_20 ,
V_43 ) ;
}
V_26 -> V_44 = ( ( V_20 -> V_22 -> V_45 << 8 ) | V_20 -> V_46 ) ;
V_26 -> V_47 = V_4 -> V_48 ( V_4 , V_20 -> V_22 , V_20 -> V_46 & 0xff ) ;
V_16 = F_16 ( V_26 ) ;
if ( V_16 ) {
F_3 ( L_2 ,
V_6 , F_17 ( V_20 ) , V_16 ) ;
return V_16 ;
}
if ( ( V_20 -> V_49 == V_50 && V_20 -> V_51 == 0x1657 ) ||
( V_20 -> V_49 == V_50 && V_20 -> V_51 == 0x168e ) )
V_26 -> V_27 -> V_52 |= V_53 ;
if ( ! V_26 -> V_27 -> V_22 )
V_26 -> V_27 -> V_22 = V_20 -> V_22 ;
F_4 ( V_54 ) ;
F_18 ( V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_55 * V_27 , int V_56 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_16 = - V_57 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_58 )
V_16 = V_4 -> V_17 -> V_58 ( V_27 , V_56 ) ;
return V_16 ;
}
static int F_20 ( struct V_55 * V_27 )
{
return V_27 -> V_59 ;
}
static int F_21 ( struct V_55 * V_27 , int * V_60 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_16 = V_61 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_62 ) {
V_16 = V_4 -> V_17 -> V_62 ( V_27 ) ;
if ( V_60 ) {
* V_60 = 0 ;
if ( V_16 & V_63 )
* V_60 = 1000 ;
}
}
return V_16 ;
}
static int F_22 ( struct V_55 * V_27 , int V_56 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_16 = - V_57 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_64 )
V_16 = V_4 -> V_17 -> V_64 ( V_27 , V_56 ) ;
return V_16 ;
}
static int F_23 ( struct V_55 * V_27 , int V_65 )
{
int V_16 ;
int V_66 ;
while ( 1 ) {
V_16 = F_21 ( V_27 , & V_66 ) ;
if ( V_16 != V_63 )
return V_16 ;
V_65 -= V_66 ;
if ( V_65 <= 0 ) {
F_3 ( L_3 ,
V_6 , V_27 -> V_59 , V_65 ) ;
return V_61 ;
}
F_24 ( V_66 ) ;
}
return V_61 ;
}
static int F_25 ( struct V_55 * V_27 , int V_67 ,
char * V_68 , unsigned long V_69 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_16 = - V_57 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_70 )
V_16 = V_4 -> V_17 -> V_70 ( V_27 , V_67 , V_68 , V_69 ) ;
return V_16 ;
}
static int F_26 ( struct V_55 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_16 = 0 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_71 )
V_16 = V_4 -> V_17 -> V_71 ( V_27 ) ;
return V_16 ;
}
static int F_27 ( struct V_55 * V_27 , int type , int V_72 ,
unsigned long V_59 , unsigned long V_73 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_16 = - V_57 ;
if ( V_4 -> V_17 && V_4 -> V_17 -> V_74 )
V_16 = V_4 -> V_17 -> V_74 ( V_27 , type , V_72 , V_59 , V_73 ) ;
return V_16 ;
}
static inline bool F_28 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_10 ( V_24 ) ;
if ( ! V_26 || ! V_26 -> V_27 )
return false ;
if ( V_26 -> V_27 -> V_52 & V_75 )
return true ;
return false ;
}
static int F_29 ( struct V_23 * V_24 ,
int V_76 , int V_77 , T_1 * V_78 )
{
if ( F_28 ( V_24 ) ) {
* V_78 = 0xFFFFFFFF ;
return V_79 ;
}
return F_30 ( V_24 , V_76 , V_77 , V_78 ) ;
}
static int F_31 ( struct V_23 * V_24 ,
int V_76 , int V_77 , T_1 V_78 )
{
if ( F_28 ( V_24 ) )
return V_79 ;
return F_32 ( V_24 , V_76 , V_77 , V_78 ) ;
}
static int F_33 ( struct V_55 * * V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
break;
}
if ( V_4 && V_4 -> V_17 -> V_80 )
return V_4 -> V_17 -> V_80 ( V_27 ) ;
return - V_57 ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_10 ( V_24 ) ;
struct V_3 * V_4 ;
T_2 V_16 ;
if ( ! V_26 )
return - V_57 ;
V_4 = V_26 -> V_4 -> V_9 ;
V_16 = F_35 ( V_4 -> V_81 ,
V_82 , V_26 -> V_44 ) ;
if ( V_16 ) {
F_3 ( L_4 ,
V_6 , V_26 -> V_44 , V_16 ) ;
return - V_83 ;
}
return 0 ;
}
static int T_3 F_36 ( void )
{
int V_16 = - V_7 ;
F_37 ( V_84 ) ;
V_16 = F_38 ( & V_85 ) ;
if ( ! V_16 )
F_39 ( L_5 ) ;
else
F_39 ( L_6 , V_16 ) ;
return V_16 ;
}
