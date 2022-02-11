static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
if ( ! V_3 )
V_3 = V_2 -> V_4 -> V_5 ;
return ~ V_3 ;
}
static unsigned long F_2 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_6 = V_7 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
V_6 |= V_10 ;
case V_11 :
V_6 |= V_12 ;
}
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
T_1 V_3 ;
int V_17 ;
V_17 = F_4 ( V_2 -> V_18 , V_2 -> V_4 -> V_19 ,
& V_3 ) ;
if ( V_17 ) {
F_5 ( V_15 ,
L_1 ,
V_17 ) ;
return V_17 ;
}
V_3 = ( V_3 & V_2 -> V_4 -> V_20 ) ;
V_3 >>= V_2 -> V_4 -> V_21 ;
* V_13 = V_2 -> V_4 -> V_22 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 * V_23 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
T_1 V_24 ;
int V_17 ;
V_17 = F_4 ( V_2 -> V_18 , V_2 -> V_4 -> V_25 ,
& V_24 ) ;
if ( V_17 ) {
F_5 ( V_15 ,
L_2 ,
V_17 ) ;
return V_17 ;
}
* V_23 = F_7 ( ( V_24 >> V_26 ) & V_27 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_28 * V_29 = V_2 -> V_30 ;
V_2 -> V_18 = F_9 ( V_29 ,
L_3 ) ;
if ( F_10 ( V_2 -> V_18 ) ) {
F_5 ( V_15 ,
L_4 ) ;
return F_11 ( V_2 -> V_18 ) ;
}
return 0 ;
}
static int F_12 ( void )
{
T_1 V_31 [ V_32 ] ;
struct V_28 * V_29 ;
const struct V_33 * V_34 ;
struct V_1 * V_2 ;
int V_17 ;
V_29 = F_13 ( L_5 ) ;
V_34 = F_14 ( V_35 , V_29 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_4 = V_34 -> V_39 ;
V_2 -> V_16 = F_16 ( 0 ) ;
if ( ! V_2 -> V_16 ) {
F_17 ( L_6 , V_40 ) ;
return - V_36 ;
}
V_2 -> V_30 = F_18 ( V_2 -> V_16 ) ;
if ( ! V_2 -> V_30 ) {
F_19 ( V_2 -> V_16 ,
L_7 ) ;
goto V_41;
}
V_17 = F_8 ( V_2 ) ;
if ( V_17 )
goto V_42;
V_17 = F_6 ( V_2 , & V_31 [ 0 ] ) ;
if ( V_17 )
goto V_42;
V_17 = F_3 ( V_2 , & V_31 [ 1 ] ) ;
if ( V_17 )
goto V_42;
V_17 = F_20 ( F_21 ( V_2 -> V_16 ,
V_31 , V_32 ) ) ;
if ( V_17 ) {
F_5 ( V_2 -> V_16 ,
L_8 ) ;
goto V_42;
}
F_22 ( V_2 -> V_30 ) ;
V_41:
F_23 ( L_9 , - 1 , NULL , 0 ) ;
return 0 ;
V_42:
F_22 ( V_2 -> V_30 ) ;
return V_17 ;
}
