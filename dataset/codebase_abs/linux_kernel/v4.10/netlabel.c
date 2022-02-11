static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 ,
T_2 * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_5 , V_6 ) ;
if ( V_7 == 0 &&
( V_5 -> V_8 & V_9 ) &&
( V_5 -> V_8 & V_10 ) )
F_3 ( V_2 , V_3 , V_5 ) ;
return V_7 ;
}
static struct V_4 * F_4 ( struct V_11 * V_12 )
{
int V_7 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_4 * V_5 ;
if ( V_14 -> V_16 != NULL )
return V_14 -> V_16 ;
V_5 = F_5 ( V_17 ) ;
if ( V_5 == NULL )
return NULL ;
V_7 = F_6 ( V_14 -> V_6 , V_5 ) ;
if ( V_7 != 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_14 -> V_16 = V_5 ;
return V_5 ;
}
static struct V_4 * F_8 (
const struct V_11 * V_12 ,
T_2 V_6 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_4 * V_5 = V_14 -> V_16 ;
if ( V_5 == NULL )
return NULL ;
if ( ( V_5 -> V_8 & V_18 ) &&
( V_5 -> V_19 . V_20 == V_6 ) )
return V_5 ;
return NULL ;
}
void F_9 ( void )
{
F_10 () ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_3 , int error , int V_21 )
{
F_12 ( V_2 , V_3 , error , V_21 ) ;
}
void F_13 ( struct V_13 * V_14 )
{
if ( V_14 -> V_16 != NULL )
F_7 ( V_14 -> V_16 ) ;
}
void F_14 ( struct V_13 * V_14 )
{
V_14 -> V_22 = V_23 ;
}
int F_15 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * type ,
T_2 * V_6 )
{
int V_7 ;
struct V_4 V_5 ;
if ( ! F_16 () ) {
* V_6 = V_24 ;
return 0 ;
}
F_17 ( & V_5 ) ;
V_7 = F_18 ( V_2 , V_3 , & V_5 ) ;
if ( V_7 == 0 && V_5 . V_8 != V_25 )
V_7 = F_1 ( V_2 , V_3 ,
& V_5 , V_6 ) ;
else
* V_6 = V_24 ;
* type = V_5 . type ;
F_19 ( & V_5 ) ;
return V_7 ;
}
int F_20 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_6 )
{
int V_7 ;
struct V_4 V_26 ;
struct V_4 * V_5 = NULL ;
struct V_11 * V_12 ;
V_12 = F_21 ( V_2 ) ;
if ( V_12 != NULL ) {
struct V_13 * V_14 = V_12 -> V_15 ;
if ( V_14 -> V_22 != V_27 )
return 0 ;
V_5 = F_8 ( V_12 , V_6 ) ;
}
if ( V_5 == NULL ) {
V_5 = & V_26 ;
F_17 ( V_5 ) ;
V_7 = F_6 ( V_6 , V_5 ) ;
if ( V_7 != 0 )
goto V_28;
}
V_7 = F_22 ( V_2 , V_3 , V_5 ) ;
V_28:
if ( V_5 == & V_26 )
F_19 ( V_5 ) ;
return V_7 ;
}
int F_23 ( struct V_29 * V_30 , T_1 V_3 )
{
int V_7 ;
struct V_4 V_5 ;
if ( V_3 != V_31 && V_3 != V_32 )
return 0 ;
F_17 ( & V_5 ) ;
V_7 = F_6 ( V_30 -> V_20 , & V_5 ) ;
if ( V_7 != 0 )
goto V_33;
V_7 = F_24 ( V_30 , & V_5 ) ;
V_33:
F_19 ( & V_5 ) ;
return V_7 ;
}
void F_25 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
if ( V_3 == V_31 )
V_14 -> V_22 = V_34 ;
else
V_14 -> V_22 = V_23 ;
}
int F_26 ( struct V_11 * V_12 , T_1 V_3 )
{
int V_7 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_4 * V_5 ;
if ( V_3 != V_31 && V_3 != V_32 )
return 0 ;
V_5 = F_4 ( V_12 ) ;
if ( V_5 == NULL )
return - V_35 ;
V_7 = F_27 ( V_12 , V_3 , V_5 ) ;
switch ( V_7 ) {
case 0 :
V_14 -> V_22 = V_34 ;
break;
case - V_36 :
V_14 -> V_22 = V_27 ;
V_7 = 0 ;
break;
}
return V_7 ;
}
int F_28 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
T_1 V_3 ,
struct V_37 * V_38 )
{
int V_7 ;
T_2 V_39 ;
T_2 V_40 ;
struct V_4 V_5 ;
if ( ! F_16 () )
return 0 ;
F_17 ( & V_5 ) ;
V_7 = F_18 ( V_2 , V_3 , & V_5 ) ;
if ( V_7 == 0 && V_5 . V_8 != V_25 )
V_7 = F_1 ( V_2 , V_3 ,
& V_5 , & V_39 ) ;
else
V_39 = V_41 ;
F_19 ( & V_5 ) ;
if ( V_7 != 0 )
return V_7 ;
switch ( V_14 -> V_42 ) {
case V_43 :
V_40 = V_44 ;
break;
case V_45 :
V_40 = V_46 ;
break;
default:
V_40 = V_47 ;
}
V_7 = F_29 ( V_14 -> V_6 , V_39 , V_14 -> V_42 , V_40 , V_38 ) ;
if ( V_7 == 0 )
return 0 ;
if ( V_39 != V_41 )
F_12 ( V_2 , V_3 , V_7 , 0 ) ;
return V_7 ;
}
static inline int F_30 ( int V_48 , int V_49 )
{
return ( V_48 == V_50 && V_49 == V_51 ) ||
( V_48 == V_52 && V_49 == V_53 ) ;
}
int F_31 ( struct V_54 * V_11 ,
int V_48 ,
int V_49 )
{
int V_7 = 0 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_4 V_5 ;
if ( F_30 ( V_48 , V_49 ) &&
( V_14 -> V_22 == V_34 ||
V_14 -> V_22 == V_55 ) ) {
F_17 ( & V_5 ) ;
F_32 ( V_12 ) ;
V_7 = F_33 ( V_12 , & V_5 ) ;
F_34 ( V_12 ) ;
if ( V_7 == 0 )
V_7 = - V_56 ;
else if ( V_7 == - V_57 )
V_7 = 0 ;
F_19 ( & V_5 ) ;
}
return V_7 ;
}
int F_35 ( struct V_11 * V_12 , struct V_58 * V_59 )
{
int V_7 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_4 * V_5 ;
if ( V_14 -> V_22 != V_27 &&
V_14 -> V_22 != V_55 )
return 0 ;
F_32 ( V_12 ) ;
if ( V_59 -> V_60 == V_61 ) {
F_36 ( V_12 ) ;
V_14 -> V_22 = V_27 ;
V_7 = 0 ;
goto V_62;
}
V_5 = F_4 ( V_12 ) ;
if ( V_5 == NULL ) {
V_7 = - V_35 ;
goto V_62;
}
V_7 = F_37 ( V_12 , V_59 , V_5 ) ;
if ( V_7 == 0 )
V_14 -> V_22 = V_55 ;
V_62:
F_34 ( V_12 ) ;
return V_7 ;
}
