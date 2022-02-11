static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_8 , V_9 ,
V_10 , & V_3 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 & V_11 ) {
V_5 -> V_12 = V_13 ;
return 0 ;
}
if ( ! V_5 -> V_14 ) {
V_3 |= V_11 ;
V_7 = F_3 ( V_8 , V_15 ,
V_10 , V_3 ) ;
if ( V_7 )
return V_7 ;
V_5 -> V_12 = V_13 ;
} else {
V_5 -> V_12 = V_16 ;
F_4 ( L_1 ) ;
V_7 = - V_17 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_8 , V_9 ,
V_10 , & V_3 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_3 & V_11 ) ) {
V_5 -> V_12 = V_16 ;
return 0 ;
}
if ( ! V_5 -> V_14 ) {
V_3 &= ~ V_11 ;
V_7 = F_3 ( V_8 , V_15 ,
V_10 , V_3 ) ;
if ( V_7 )
return V_7 ;
V_5 -> V_12 = V_16 ;
} else {
V_5 -> V_12 = V_13 ;
F_4 ( L_2 ) ;
V_7 = - V_17 ;
}
return V_7 ;
}
static int F_6 ( int V_18 , int * V_19 )
{
int V_20 ;
T_1 V_3 ;
F_7 ( & V_21 ) ;
V_20 = F_2 ( V_8 , V_9 ,
V_22 , & V_3 ) ;
F_8 ( & V_21 ) ;
if ( V_20 )
return V_20 ;
* V_19 = ( V_3 >> ( V_18 * V_23 ) ) & V_24 ;
* V_19 -= V_25 ;
return 0 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
int V_18 , int * V_19 )
{
return F_6 ( V_18 , V_19 ) ;
}
static inline int F_10 ( struct V_1 * V_2 , int * V_19 )
{
return F_6 ( V_26 , V_19 ) ;
}
static int F_11 ( struct V_4 * V_5 ,
int V_18 , int V_19 )
{
T_1 V_3 ;
T_1 V_27 ;
T_1 V_28 ;
int V_7 ;
F_7 ( & V_21 ) ;
if ( V_5 -> V_14 ) {
V_7 = - V_17 ;
goto V_29;
}
V_7 = F_2 ( V_8 , V_9 ,
V_22 , & V_28 ) ;
if ( V_7 )
goto V_29;
if ( V_19 > V_30 )
V_19 = V_30 ;
V_27 = V_19 + V_25 ;
V_3 = ( V_28 & ~ ( V_24 <<
( V_18 * V_23 ) ) ) ;
V_3 |= ( V_27 & V_24 ) <<
( V_18 * V_23 ) ;
V_7 = F_3 ( V_8 , V_15 ,
V_22 , V_3 ) ;
V_29:
F_8 ( & V_21 ) ;
return V_7 ;
}
static inline int F_12 ( struct V_1 * V_2 , int V_18 ,
int V_19 )
{
return F_11 ( V_2 -> V_6 , V_18 , V_19 ) ;
}
static int F_13 ( struct V_1 * V_31 ,
int V_18 , enum V_32 * type )
{
if ( V_18 )
* type = V_33 ;
else
* type = V_34 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
int * V_19 )
{
T_1 V_3 ;
int V_7 ;
F_7 ( & V_21 ) ;
V_7 = F_2 ( V_8 , V_9 ,
V_35 , & V_3 ) ;
F_8 ( & V_21 ) ;
if ( V_7 )
return V_7 ;
V_3 = ( V_3 >> V_36 ) & V_37 ;
* V_19 = V_3 - V_25 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_38 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_12 = V_5 -> V_12 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_38 V_12 )
{
int V_7 ;
F_7 ( & V_21 ) ;
if ( V_12 == V_13 )
V_7 = F_1 ( V_2 ) ;
else
V_7 = F_5 ( V_2 ) ;
F_8 ( & V_21 ) ;
return V_7 ;
}
static void F_17 ( struct V_4 * V_5 )
{
if ( V_5 ) {
if ( ! V_5 -> V_14 ) {
F_7 ( & V_21 ) ;
F_3 ( V_8 , V_15 ,
V_10 ,
V_5 -> V_39 ) ;
F_3 ( V_8 , V_15 ,
V_22 ,
V_5 -> V_28 ) ;
F_8 ( & V_21 ) ;
}
F_18 ( V_5 -> V_40 ) ;
F_19 ( V_5 ) ;
}
}
static struct V_4 * F_20 ( void )
{
struct V_4 * V_5 ;
int V_41 ;
T_1 V_3 ;
int V_42 ;
V_5 = F_21 ( sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 ) {
V_41 = - V_44 ;
return F_22 ( - V_44 ) ;
}
V_41 = F_2 ( V_8 , V_9 ,
V_45 ,
& V_3 ) ;
if ( V_41 )
goto V_46;
if ( V_3 & V_47 ) {
V_5 -> V_14 = true ;
V_42 = V_48 ;
} else {
V_5 -> V_14 = false ;
V_42 = V_49 ;
}
if ( ! V_5 -> V_14 ) {
V_41 = F_2 ( V_8 , V_9 ,
V_10 ,
& V_5 -> V_39 ) ;
if ( V_41 )
goto V_46;
V_41 = F_2 ( V_8 , V_9 ,
V_22 ,
& V_5 -> V_28 ) ;
if ( V_41 )
goto V_46;
}
V_5 -> V_40 = F_23 ( L_3 ,
V_50 ,
V_42 ,
V_5 , & V_51 , NULL , 0 , V_52 ) ;
if ( F_24 ( V_5 -> V_40 ) ) {
V_41 = F_25 ( V_5 -> V_40 ) ;
goto V_46;
}
F_7 ( & V_21 ) ;
V_41 = F_1 ( V_5 -> V_40 ) ;
F_8 ( & V_21 ) ;
if ( V_41 )
goto V_53;
return V_5 ;
V_53:
F_18 ( V_5 -> V_40 ) ;
V_46:
F_19 ( V_5 ) ;
return F_22 ( V_41 ) ;
}
static int T_2 F_26 ( void )
{
int V_41 = 0 ;
if ( ! F_27 ( V_54 ) || ! F_28 () )
return - V_55 ;
V_56 = F_20 () ;
if ( F_24 ( V_56 ) ) {
V_41 = F_25 ( V_56 ) ;
goto V_57;
}
return 0 ;
V_57:
F_17 ( V_56 ) ;
return V_41 ;
}
static void T_3 F_29 ( void )
{
F_17 ( V_56 ) ;
}
