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
if ( F_11 ( V_14 ) ) {
V_20 -> V_29 = F_12 ( V_14 ) ;
if ( F_13 ( V_14 ) == V_30 )
V_20 -> V_25 |= V_31 ;
else if ( F_13 ( V_14 ) == V_32 )
V_20 -> V_25 |= V_33 ;
}
V_20 -> V_34 = ( ( V_14 -> V_16 -> V_35 << 8 ) | V_14 -> V_36 ) ;
V_20 -> V_37 = V_8 -> V_38 ( V_8 , V_14 -> V_16 , V_14 -> V_36 & 0xff ) ;
F_14 ( V_20 ) ;
F_15 ( true ) ;
F_16 ( V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_39 * V_21 , int V_40 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_41 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_42 )
V_9 = V_8 -> V_11 -> V_42 ( V_21 , V_40 ) ;
return V_9 ;
}
static int F_18 ( struct V_39 * V_21 )
{
return V_21 -> V_43 ;
}
static int F_19 ( struct V_39 * V_21 , int * V_44 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = V_45 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_46 ) {
V_9 = V_8 -> V_11 -> V_46 ( V_21 ) ;
if ( V_44 ) {
* V_44 = 0 ;
if ( V_9 & V_47 )
* V_44 = 1000 ;
}
}
return V_9 ;
}
static int F_20 ( struct V_39 * V_21 , int V_40 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_41 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_48 )
V_9 = V_8 -> V_11 -> V_48 ( V_21 , V_40 ) ;
return V_9 ;
}
static int F_21 ( struct V_39 * V_21 , int V_49 )
{
int V_9 ;
int V_50 ;
while ( 1 ) {
V_9 = F_19 ( V_21 , & V_50 ) ;
if ( V_9 != V_47 )
return V_9 ;
V_49 -= V_50 ;
if ( V_49 <= 0 ) {
F_3 ( L_2 ,
V_2 , V_21 -> V_43 , V_49 ) ;
return V_45 ;
}
F_22 ( V_50 ) ;
}
return V_45 ;
}
static int F_23 ( struct V_39 * V_21 , int V_51 ,
char * V_52 , unsigned long V_53 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_41 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_54 )
V_9 = V_8 -> V_11 -> V_54 ( V_21 , V_51 , V_52 , V_53 ) ;
return V_9 ;
}
static int F_24 ( struct V_39 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = 0 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_55 )
V_9 = V_8 -> V_11 -> V_55 ( V_21 ) ;
return V_9 ;
}
static int F_25 ( struct V_39 * * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
F_6 (hose, &hose_list, list_node) {
V_8 = V_6 -> V_10 ;
break;
}
if ( V_8 && V_8 -> V_11 -> V_56 )
return V_8 -> V_11 -> V_56 ( V_21 ) ;
return - V_41 ;
}
static int F_26 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_10 ( V_18 ) ;
struct V_7 * V_8 ;
T_1 V_9 ;
if ( ! V_20 )
return - V_41 ;
V_8 = V_20 -> V_8 -> V_10 ;
V_9 = F_27 ( V_8 -> V_57 ,
V_58 , V_20 -> V_34 ) ;
if ( V_9 ) {
F_28 ( L_3 ,
V_2 , V_20 -> V_34 , V_9 ) ;
return - V_59 ;
}
return 0 ;
}
static int T_2 F_29 ( void )
{
int V_9 = - V_3 ;
if ( ! F_30 ( V_60 ) )
return V_9 ;
V_9 = F_31 ( & V_61 ) ;
if ( ! V_9 )
F_32 ( L_4 ) ;
else
F_32 ( L_5 , V_9 ) ;
return V_9 ;
}
