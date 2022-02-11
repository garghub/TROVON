static int F_1 ( void )
{
if ( ! F_2 ( V_1 ) ) {
F_3 ( L_1 , V_2 ) ;
return - V_3 ;
}
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( void )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
F_6 (hose, &hose_list, list_node) {
V_8 = V_6 -> V_10 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_12 ) {
V_9 = V_8 -> V_11 -> V_12 ( V_6 ) ;
if ( V_9 )
break;
}
}
return V_9 ;
}
static int F_7 ( struct V_13 * V_14 , void * V_15 )
{
struct V_5 * V_6 = F_8 ( V_14 -> V_16 ) ;
struct V_7 * V_8 = V_6 -> V_10 ;
struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_19 * V_20 = F_10 ( V_18 ) ;
if ( ! V_18 || ! V_20 || V_20 -> V_21 )
return 0 ;
if ( ( V_14 -> V_22 >> 8 ) == V_23 )
return 0 ;
V_20 -> V_24 = V_14 -> V_22 ;
V_20 -> V_25 &= 0xFFFFFF00 ;
if ( V_14 -> V_26 == V_27 )
V_20 -> V_25 |= V_28 ;
V_20 -> V_29 = F_11 ( V_14 , V_30 ) ;
if ( F_12 ( V_14 ) ) {
V_20 -> V_31 = F_13 ( V_14 ) ;
if ( F_14 ( V_14 ) == V_32 )
V_20 -> V_25 |= V_33 ;
else if ( F_14 ( V_14 ) == V_34 )
V_20 -> V_25 |= V_35 ;
V_20 -> V_36 = F_15 ( V_14 ,
V_37 ) ;
}
V_20 -> V_38 = ( ( V_14 -> V_16 -> V_39 << 8 ) | V_14 -> V_40 ) ;
V_20 -> V_41 = V_8 -> V_42 ( V_8 , V_14 -> V_16 , V_14 -> V_40 & 0xff ) ;
F_16 ( V_20 ) ;
F_17 ( true ) ;
F_18 ( V_20 ) ;
return 0 ;
}
static int F_19 ( struct V_43 * V_21 , int V_44 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_45 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_46 )
V_9 = V_8 -> V_11 -> V_46 ( V_21 , V_44 ) ;
return V_9 ;
}
static int F_20 ( struct V_43 * V_21 )
{
return V_21 -> V_47 ;
}
static int F_21 ( struct V_43 * V_21 , int * V_48 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = V_49 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_50 ) {
V_9 = V_8 -> V_11 -> V_50 ( V_21 ) ;
if ( V_48 ) {
* V_48 = 0 ;
if ( V_9 & V_51 )
* V_48 = 1000 ;
}
}
return V_9 ;
}
static int F_22 ( struct V_43 * V_21 , int V_44 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_45 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_52 )
V_9 = V_8 -> V_11 -> V_52 ( V_21 , V_44 ) ;
return V_9 ;
}
static int F_23 ( struct V_43 * V_21 , int V_53 )
{
int V_9 ;
int V_54 ;
while ( 1 ) {
V_9 = F_21 ( V_21 , & V_54 ) ;
if ( V_9 != V_51 )
return V_9 ;
V_53 -= V_54 ;
if ( V_53 <= 0 ) {
F_3 ( L_2 ,
V_2 , V_21 -> V_47 , V_53 ) ;
return V_49 ;
}
F_24 ( V_54 ) ;
}
return V_49 ;
}
static int F_25 ( struct V_43 * V_21 , int V_55 ,
char * V_56 , unsigned long V_57 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_45 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_58 )
V_9 = V_8 -> V_11 -> V_58 ( V_21 , V_55 , V_56 , V_57 ) ;
return V_9 ;
}
static int F_26 ( struct V_43 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = 0 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_59 )
V_9 = V_8 -> V_11 -> V_59 ( V_21 ) ;
return V_9 ;
}
static int F_27 ( struct V_43 * * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
F_6 (hose, &hose_list, list_node) {
V_8 = V_6 -> V_10 ;
break;
}
if ( V_8 && V_8 -> V_11 -> V_60 )
return V_8 -> V_11 -> V_60 ( V_21 ) ;
return - V_45 ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_10 ( V_18 ) ;
struct V_7 * V_8 ;
T_1 V_9 ;
if ( ! V_20 )
return - V_45 ;
V_8 = V_20 -> V_8 -> V_10 ;
V_9 = F_29 ( V_8 -> V_61 ,
V_62 , V_20 -> V_38 ) ;
if ( V_9 ) {
F_30 ( L_3 ,
V_2 , V_20 -> V_38 , V_9 ) ;
return - V_63 ;
}
return 0 ;
}
static int T_2 F_31 ( void )
{
int V_9 = - V_3 ;
if ( ! F_32 ( V_64 ) )
return V_9 ;
V_9 = F_33 ( & V_65 ) ;
if ( ! V_9 )
F_34 ( L_4 ) ;
else
F_34 ( L_5 , V_9 ) ;
return V_9 ;
}
