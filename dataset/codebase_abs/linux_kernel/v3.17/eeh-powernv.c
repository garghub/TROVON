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
if ( ! V_23 -> V_24 -> V_19 )
V_23 -> V_24 -> V_19 = V_17 -> V_19 ;
F_4 ( V_46 ) ;
F_18 ( V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_47 * V_24 , int V_48 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_49 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_50 )
V_13 = V_4 -> V_14 -> V_50 ( V_24 , V_48 ) ;
return V_13 ;
}
static int F_20 ( struct V_47 * V_24 )
{
return V_24 -> V_51 ;
}
static int F_21 ( struct V_47 * V_24 , int * V_52 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = V_53 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_54 ) {
V_13 = V_4 -> V_14 -> V_54 ( V_24 ) ;
if ( V_52 ) {
* V_52 = 0 ;
if ( V_13 & V_55 )
* V_52 = 1000 ;
}
}
return V_13 ;
}
static int F_22 ( struct V_47 * V_24 , int V_48 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_49 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_56 )
V_13 = V_4 -> V_14 -> V_56 ( V_24 , V_48 ) ;
return V_13 ;
}
static int F_23 ( struct V_47 * V_24 , int V_57 )
{
int V_13 ;
int V_58 ;
while ( 1 ) {
V_13 = F_21 ( V_24 , & V_58 ) ;
if ( V_13 != V_55 )
return V_13 ;
V_57 -= V_58 ;
if ( V_57 <= 0 ) {
F_3 ( L_3 ,
V_6 , V_24 -> V_51 , V_57 ) ;
return V_53 ;
}
F_24 ( V_58 ) ;
}
return V_53 ;
}
static int F_25 ( struct V_47 * V_24 , int V_59 ,
char * V_60 , unsigned long V_61 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = - V_49 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_62 )
V_13 = V_4 -> V_14 -> V_62 ( V_24 , V_59 , V_60 , V_61 ) ;
return V_13 ;
}
static int F_26 ( struct V_47 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
int V_13 = 0 ;
if ( V_4 -> V_14 && V_4 -> V_14 -> V_63 )
V_13 = V_4 -> V_14 -> V_63 ( V_24 ) ;
return V_13 ;
}
static int F_27 ( struct V_47 * * V_24 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
break;
}
if ( V_4 && V_4 -> V_14 -> V_64 )
return V_4 -> V_14 -> V_64 ( V_24 ) ;
return - V_49 ;
}
static int F_28 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_10 ( V_21 ) ;
struct V_3 * V_4 ;
T_1 V_13 ;
if ( ! V_23 )
return - V_49 ;
V_4 = V_23 -> V_4 -> V_9 ;
V_13 = F_29 ( V_4 -> V_65 ,
V_66 , V_23 -> V_41 ) ;
if ( V_13 ) {
F_3 ( L_4 ,
V_6 , V_23 -> V_41 , V_13 ) ;
return - V_67 ;
}
return 0 ;
}
static int T_2 F_30 ( void )
{
int V_13 = - V_7 ;
F_31 ( V_68 ) ;
V_13 = F_32 ( & V_69 ) ;
if ( ! V_13 )
F_33 ( L_5 ) ;
else
F_33 ( L_6 , V_13 ) ;
return V_13 ;
}
