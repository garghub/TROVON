static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 < F_2 ( 64 ) ) {
F_3 ( L_1 , V_4 ) ;
return - V_5 ;
}
* ( V_2 -> V_6 . V_3 ) = V_3 ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 )
{
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_10 , int type )
{
return - V_11 ;
}
static void F_6 ( struct V_1 * V_2 )
{
}
static bool F_7 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( ! V_17 -> V_18 ( V_15 -> V_19 , V_15 ) ) {
F_9 ( & V_6 -> V_6 , L_2 , V_4 ) ;
return false ;
}
F_10 ( & V_6 -> V_6 , & V_20 ) ;
F_11 ( & V_6 -> V_6 , V_21 ) ;
return F_12 ( V_6 , V_15 ) ;
}
static T_2 F_13 ( struct V_7 * V_8 ,
unsigned long type )
{
return 1 ;
}
static void F_14 ( struct V_1 * V_6 )
{
}
static int F_15 ( T_3 V_8 , T_3 V_22 )
{
return ( V_8 << 8 ) + V_22 ;
}
static inline struct V_14 * F_16 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = V_8 ? F_8 ( V_8 ) : NULL ;
return V_13 ? V_13 -> V_16 : NULL ;
}
static void F_17 ( struct V_14 * V_15 )
{
F_18 ( & V_15 -> V_23 ) ;
}
static bool F_19 ( struct V_14 * V_15 )
{
return F_20 ( & V_15 -> V_23 ) ;
}
static inline int F_21 ( struct V_7 * V_8 , unsigned int V_22 ,
struct V_14 * V_15 , int * V_24 )
{
int V_25 ;
V_25 = F_15 ( V_8 -> V_26 , V_22 ) ;
if ( V_25 > V_15 -> V_27 )
return V_28 ;
* V_24 = V_25 ;
return 0 ;
}
static int F_22 ( struct V_7 * V_8 , unsigned int V_22 ,
int V_29 , int V_30 , T_4 * V_31 )
{
int V_32 , V_25 ;
struct V_14 * V_15 ;
T_3 V_33 ;
T_5 V_34 ;
T_4 V_35 ;
V_15 = F_16 ( V_8 ) ;
if ( V_15 == NULL || ! F_19 ( V_15 ) )
return V_28 ;
V_32 = F_21 ( V_8 , V_22 , V_15 , & V_25 ) ;
if ( V_32 )
goto V_36;
switch ( V_30 ) {
case 1 :
V_32 = V_17 -> V_37 ( V_15 , V_25 , V_29 , & V_33 ) ;
* V_31 = V_33 ;
break;
case 2 :
V_32 = V_17 -> V_38 ( V_15 , V_25 , V_29 , & V_34 ) ;
* V_31 = V_34 ;
break;
case 4 :
V_32 = V_17 -> V_39 ( V_15 , V_25 , V_29 , & V_35 ) ;
* V_31 = V_35 ;
break;
default:
F_23 ( 1 ) ;
}
V_36:
F_17 ( V_15 ) ;
return V_32 ? V_28 : V_40 ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_22 ,
int V_29 , int V_30 , T_4 V_31 )
{
int V_32 , V_25 ;
struct V_14 * V_15 ;
V_15 = F_16 ( V_8 ) ;
if ( V_15 == NULL || ! F_19 ( V_15 ) )
return V_28 ;
V_32 = F_21 ( V_8 , V_22 , V_15 , & V_25 ) ;
if ( V_32 )
goto V_36;
switch ( V_30 ) {
case 1 :
V_32 = V_17 -> V_41 ( V_15 , V_25 , V_29 , V_31 & 0xff ) ;
break;
case 2 :
V_32 = V_17 -> V_42 ( V_15 , V_25 , V_29 , V_31 & 0xffff ) ;
break;
case 4 :
V_32 = V_17 -> V_43 ( V_15 , V_25 , V_29 , V_31 ) ;
break;
default:
F_23 ( 1 ) ;
}
V_36:
F_17 ( V_15 ) ;
return V_32 ? V_44 : V_40 ;
}
int F_25 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
if ( ! V_15 -> V_27 )
return 0 ;
V_48 = V_15 -> V_19 -> V_6 . V_48 ;
V_46 = V_48 -> V_49 ;
V_13 = F_26 ( V_46 ) ;
if ( ! V_13 )
return - V_11 ;
V_13 -> V_48 = V_48 ;
V_13 -> V_50 = & V_51 ;
V_13 -> V_52 = NULL ;
V_13 -> V_53 = NULL ;
V_13 -> V_16 = V_15 ;
V_13 -> V_54 = V_55 ;
F_27 ( V_13 ) ;
if ( V_13 -> V_8 == NULL )
return - V_56 ;
F_28 ( F_29 ( V_13 -> V_8 -> V_57 ) ,
V_58 ,
( void * ) V_13 ) ;
F_30 ( V_13 -> V_8 ) ;
F_31 ( V_13 -> V_8 ) ;
V_15 -> V_13 = V_13 ;
return 0 ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
if ( ! V_15 || ! V_15 -> V_13 )
return;
V_13 = V_15 -> V_13 ;
V_15 -> V_13 = NULL ;
F_33 ( V_13 -> V_8 ) ;
}
static bool F_34 ( struct V_12 * V_13 )
{
return ( V_13 -> V_50 == & V_51 ) ;
}
bool F_35 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
return F_34 ( V_13 ) ;
}
struct V_14 * F_36 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
if ( F_34 ( V_13 ) )
return (struct V_14 * ) V_13 -> V_16 ;
if ( F_37 ( V_6 ) )
return F_38 ( V_13 ) ;
return F_39 ( - V_11 ) ;
}
unsigned int F_40 ( struct V_1 * V_6 )
{
return F_15 ( V_6 -> V_8 -> V_26 , V_6 -> V_22 ) ;
}
