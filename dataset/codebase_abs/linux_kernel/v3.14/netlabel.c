static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_4 , V_5 ) ;
if ( V_6 == 0 &&
( V_4 -> V_7 & V_8 ) &&
( V_4 -> V_7 & V_9 ) )
F_3 ( V_2 , V_4 ) ;
return V_6 ;
}
static struct V_3 * F_4 ( struct V_10 * V_11 )
{
int V_6 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
if ( V_13 -> V_15 != NULL )
return V_13 -> V_15 ;
V_4 = F_5 ( V_16 ) ;
if ( V_4 == NULL )
return NULL ;
V_6 = F_6 ( V_13 -> V_5 , V_4 ) ;
if ( V_6 != 0 ) {
F_7 ( V_4 ) ;
return NULL ;
}
V_13 -> V_15 = V_4 ;
return V_4 ;
}
static struct V_3 * F_8 (
const struct V_10 * V_11 ,
T_1 V_5 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 = V_13 -> V_15 ;
if ( V_4 == NULL )
return NULL ;
if ( ( V_4 -> V_7 & V_17 ) &&
( V_4 -> V_18 . V_19 == V_5 ) )
return V_4 ;
return NULL ;
}
void F_9 ( void )
{
F_10 () ;
}
void F_11 ( struct V_1 * V_2 , int error , int V_20 )
{
F_12 ( V_2 , error , V_20 ) ;
}
void F_13 ( struct V_12 * V_13 )
{
if ( V_13 -> V_15 != NULL )
F_7 ( V_13 -> V_15 ) ;
}
void F_14 ( struct V_12 * V_13 )
{
V_13 -> V_21 = V_22 ;
}
int F_15 ( struct V_1 * V_2 ,
T_2 V_23 ,
T_1 * type ,
T_1 * V_5 )
{
int V_6 ;
struct V_3 V_4 ;
if ( ! F_16 () ) {
* V_5 = V_24 ;
return 0 ;
}
F_17 ( & V_4 ) ;
V_6 = F_18 ( V_2 , V_23 , & V_4 ) ;
if ( V_6 == 0 && V_4 . V_7 != V_25 )
V_6 = F_1 ( V_2 , & V_4 , V_5 ) ;
else
* V_5 = V_24 ;
* type = V_4 . type ;
F_19 ( & V_4 ) ;
return V_6 ;
}
int F_20 ( struct V_1 * V_2 ,
T_2 V_23 ,
T_1 V_5 )
{
int V_6 ;
struct V_3 V_26 ;
struct V_3 * V_4 = NULL ;
struct V_10 * V_11 ;
V_11 = V_2 -> V_11 ;
if ( V_11 != NULL ) {
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_13 -> V_21 != V_27 )
return 0 ;
V_4 = F_8 ( V_11 , V_5 ) ;
}
if ( V_4 == NULL ) {
V_4 = & V_26 ;
F_17 ( V_4 ) ;
V_6 = F_6 ( V_5 , V_4 ) ;
if ( V_6 != 0 )
goto V_28;
}
V_6 = F_21 ( V_2 , V_23 , V_4 ) ;
V_28:
if ( V_4 == & V_26 )
F_19 ( V_4 ) ;
return V_6 ;
}
int F_22 ( struct V_29 * V_30 , T_2 V_23 )
{
int V_6 ;
struct V_3 V_4 ;
if ( V_23 != V_31 )
return 0 ;
F_17 ( & V_4 ) ;
V_6 = F_6 ( V_30 -> V_19 , & V_4 ) ;
if ( V_6 != 0 )
goto V_32;
V_6 = F_23 ( V_30 , & V_4 ) ;
V_32:
F_19 ( & V_4 ) ;
return V_6 ;
}
void F_24 ( struct V_10 * V_11 , T_2 V_23 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_23 == V_31 )
V_13 -> V_21 = V_33 ;
else
V_13 -> V_21 = V_22 ;
}
int F_25 ( struct V_10 * V_11 , T_2 V_23 )
{
int V_6 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
if ( V_23 != V_31 )
return 0 ;
V_4 = F_4 ( V_11 ) ;
if ( V_4 == NULL )
return - V_34 ;
V_6 = F_26 ( V_11 , V_23 , V_4 ) ;
switch ( V_6 ) {
case 0 :
V_13 -> V_21 = V_33 ;
break;
case - V_35 :
V_13 -> V_21 = V_27 ;
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_27 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_2 V_23 ,
struct V_36 * V_37 )
{
int V_6 ;
T_1 V_38 ;
T_1 V_39 ;
struct V_3 V_4 ;
if ( ! F_16 () )
return 0 ;
F_17 ( & V_4 ) ;
V_6 = F_18 ( V_2 , V_23 , & V_4 ) ;
if ( V_6 == 0 && V_4 . V_7 != V_25 )
V_6 = F_1 ( V_2 , & V_4 , & V_38 ) ;
else
V_38 = V_40 ;
F_19 ( & V_4 ) ;
if ( V_6 != 0 )
return V_6 ;
switch ( V_13 -> V_41 ) {
case V_42 :
V_39 = V_43 ;
break;
case V_44 :
V_39 = V_45 ;
break;
default:
V_39 = V_46 ;
}
V_6 = F_28 ( V_13 -> V_5 , V_38 , V_13 -> V_41 , V_39 , V_37 ) ;
if ( V_6 == 0 )
return 0 ;
if ( V_38 != V_40 )
F_12 ( V_2 , V_6 , 0 ) ;
return V_6 ;
}
int F_29 ( struct V_47 * V_10 ,
int V_48 ,
int V_49 )
{
int V_6 = 0 ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 V_4 ;
if ( V_48 == V_50 && V_49 == V_51 &&
( V_13 -> V_21 == V_33 ||
V_13 -> V_21 == V_52 ) ) {
F_17 ( & V_4 ) ;
F_30 ( V_11 ) ;
V_6 = F_31 ( V_11 , & V_4 ) ;
F_32 ( V_11 ) ;
if ( V_6 == 0 )
V_6 = - V_53 ;
else if ( V_6 == - V_54 )
V_6 = 0 ;
F_19 ( & V_4 ) ;
}
return V_6 ;
}
int F_33 ( struct V_10 * V_11 , struct V_55 * V_56 )
{
int V_6 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
if ( V_13 -> V_21 != V_27 &&
V_13 -> V_21 != V_52 )
return 0 ;
F_30 ( V_11 ) ;
if ( V_56 -> V_57 == V_58 ) {
F_34 ( V_11 ) ;
V_13 -> V_21 = V_27 ;
V_6 = 0 ;
goto V_59;
}
V_4 = F_4 ( V_11 ) ;
if ( V_4 == NULL ) {
V_6 = - V_34 ;
goto V_59;
}
V_6 = F_35 ( V_11 , V_56 , V_4 ) ;
if ( V_6 == 0 )
V_13 -> V_21 = V_52 ;
V_59:
F_32 ( V_11 ) ;
return V_6 ;
}
