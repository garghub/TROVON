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
if ( V_8 -> type == V_39 )
V_40 = 1 ;
F_15 ( V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_41 * V_21 , int V_42 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_43 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_44 )
V_9 = V_8 -> V_11 -> V_44 ( V_21 , V_42 ) ;
return V_9 ;
}
static int F_17 ( struct V_41 * V_21 )
{
return V_21 -> V_45 ;
}
static int F_18 ( struct V_41 * V_21 , int * V_46 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = V_47 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_48 ) {
V_9 = V_8 -> V_11 -> V_48 ( V_21 ) ;
if ( V_46 ) {
* V_46 = 0 ;
if ( V_9 & V_49 )
* V_46 = 1000 ;
}
}
return V_9 ;
}
static int F_19 ( struct V_41 * V_21 , int V_42 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_43 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_50 )
V_9 = V_8 -> V_11 -> V_50 ( V_21 , V_42 ) ;
return V_9 ;
}
static int F_20 ( struct V_41 * V_21 , int V_51 )
{
int V_9 ;
int V_52 ;
while ( 1 ) {
V_9 = F_18 ( V_21 , & V_52 ) ;
if ( V_9 != V_49 )
return V_9 ;
V_51 -= V_52 ;
if ( V_51 <= 0 ) {
F_3 ( L_2 ,
V_2 , V_21 -> V_45 , V_51 ) ;
return V_47 ;
}
F_21 ( V_52 ) ;
}
return V_47 ;
}
static int F_22 ( struct V_41 * V_21 , int V_53 ,
char * V_54 , unsigned long V_55 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = - V_43 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_56 )
V_9 = V_8 -> V_11 -> V_56 ( V_21 , V_53 , V_54 , V_55 ) ;
return V_9 ;
}
static int F_23 ( struct V_41 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_8 ;
struct V_7 * V_8 = V_6 -> V_10 ;
int V_9 = 0 ;
if ( V_8 -> V_11 && V_8 -> V_11 -> V_57 )
V_9 = V_8 -> V_11 -> V_57 ( V_21 ) ;
return V_9 ;
}
static int F_24 ( struct V_41 * * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
F_6 (hose, &hose_list, list_node) {
V_8 = V_6 -> V_10 ;
break;
}
if ( V_8 && V_8 -> V_11 -> V_58 )
return V_8 -> V_11 -> V_58 ( V_21 ) ;
return - V_43 ;
}
static int T_1 F_25 ( void )
{
int V_9 = - V_3 ;
if ( ! F_26 ( V_59 ) )
return V_9 ;
V_9 = F_27 ( & V_60 ) ;
if ( ! V_9 )
F_28 ( L_3 ) ;
else
F_28 ( L_4 , V_9 ) ;
return V_9 ;
}
