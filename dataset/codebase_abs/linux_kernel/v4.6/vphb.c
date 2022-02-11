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
struct V_16 * V_17 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
V_15 = (struct V_14 * ) V_13 -> V_18 ;
if ( ! V_19 -> V_20 ( V_15 -> V_21 , V_15 ) ) {
F_9 ( & V_6 -> V_6 , L_2 , V_4 ) ;
return false ;
}
F_10 ( & V_6 -> V_6 , & V_22 ) ;
F_11 ( & V_6 -> V_6 , V_23 ) ;
V_17 = F_12 ( V_6 ) ;
if ( ! V_17 )
return false ;
V_6 -> V_6 . V_24 . V_25 = V_17 ;
return ( V_19 -> V_26 ( V_15 ) == 0 ) ;
}
static void F_13 ( struct V_1 * V_6 )
{
struct V_16 * V_17 = F_14 ( V_6 ) ;
if ( V_17 ) {
if ( V_17 -> V_27 == V_28 ) {
F_15 ( & V_6 -> V_6 , L_3 ) ;
return;
}
V_6 -> V_6 . V_24 . V_25 = NULL ;
F_16 ( V_17 ) ;
}
}
static T_2 F_17 ( struct V_7 * V_8 ,
unsigned long type )
{
return 1 ;
}
static void F_18 ( struct V_1 * V_6 )
{
}
static int F_19 ( T_3 V_8 , T_3 V_29 )
{
return ( V_8 << 8 ) + V_29 ;
}
static int F_20 ( struct V_7 * V_8 , unsigned int V_29 ,
struct V_14 * * V_30 , int * V_31 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_32 ;
V_13 = F_8 ( V_8 ) ;
if ( V_13 == NULL )
return V_33 ;
V_15 = (struct V_14 * ) V_13 -> V_18 ;
V_32 = F_19 ( V_8 -> V_34 , V_29 ) ;
if ( V_32 > V_15 -> V_35 )
return V_33 ;
* V_30 = V_15 ;
* V_31 = V_32 ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 , unsigned int V_29 ,
int V_36 , int V_37 , T_4 * V_38 )
{
int V_39 , V_32 ;
struct V_14 * V_15 ;
T_3 V_40 ;
T_5 V_41 ;
T_4 V_42 ;
V_39 = F_20 ( V_8 , V_29 , & V_15 , & V_32 ) ;
if ( V_39 )
return V_39 ;
switch ( V_37 ) {
case 1 :
V_39 = V_19 -> V_43 ( V_15 , V_32 , V_36 , & V_40 ) ;
* V_38 = V_40 ;
break;
case 2 :
V_39 = V_19 -> V_44 ( V_15 , V_32 , V_36 , & V_41 ) ;
* V_38 = V_41 ;
break;
case 4 :
V_39 = V_19 -> V_45 ( V_15 , V_32 , V_36 , & V_42 ) ;
* V_38 = V_42 ;
break;
default:
F_22 ( 1 ) ;
}
if ( V_39 )
return V_33 ;
return V_46 ;
}
static int F_23 ( struct V_7 * V_8 , unsigned int V_29 ,
int V_36 , int V_37 , T_4 V_38 )
{
int V_39 , V_32 ;
struct V_14 * V_15 ;
V_39 = F_20 ( V_8 , V_29 , & V_15 , & V_32 ) ;
if ( V_39 )
return V_39 ;
switch ( V_37 ) {
case 1 :
V_39 = V_19 -> V_47 ( V_15 , V_32 , V_36 , V_38 & 0xff ) ;
break;
case 2 :
V_39 = V_19 -> V_48 ( V_15 , V_32 , V_36 , V_38 & 0xffff ) ;
break;
case 4 :
V_39 = V_19 -> V_49 ( V_15 , V_32 , V_36 , V_38 ) ;
break;
default:
F_22 ( 1 ) ;
}
if ( V_39 )
return V_50 ;
return V_46 ;
}
int F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_51 ;
struct V_12 * V_13 , * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
if ( F_25 ( V_57 ) ) {
V_51 = F_26 ( V_15 -> V_21 -> V_6 . V_56 ) ;
V_52 = F_8 ( V_51 -> V_8 ) ;
V_54 = V_52 -> V_58 ;
V_56 = & V_51 -> V_6 ;
} else {
V_54 = V_15 -> V_21 -> V_6 . V_56 -> V_59 ;
V_56 = V_15 -> V_21 -> V_6 . V_56 ;
}
V_13 = F_27 ( V_54 ) ;
if ( ! V_13 )
return - V_11 ;
V_13 -> V_56 = V_56 ;
V_13 -> V_60 = & V_61 ;
V_13 -> V_62 = NULL ;
V_13 -> V_63 = 0 ;
V_13 -> V_18 = V_15 ;
V_13 -> V_64 = V_65 ;
F_28 ( V_13 ) ;
if ( V_13 -> V_8 == NULL )
return - V_66 ;
F_29 ( V_13 -> V_8 ) ;
F_30 ( V_13 -> V_8 ) ;
V_15 -> V_13 = V_13 ;
return 0 ;
}
void F_31 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
if ( ! V_15 || ! V_15 -> V_13 )
return;
V_13 = V_15 -> V_13 ;
V_15 -> V_13 = NULL ;
F_32 ( V_13 -> V_8 ) ;
F_33 ( V_13 ) ;
}
bool F_34 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
return ( V_13 -> V_60 == & V_61 ) ;
}
struct V_14 * F_35 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
return (struct V_14 * ) V_13 -> V_18 ;
}
unsigned int F_36 ( struct V_1 * V_6 )
{
return F_19 ( V_6 -> V_8 -> V_34 , V_6 -> V_29 ) ;
}
