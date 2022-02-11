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
void F_8 ( void )
{
F_9 () ;
}
void F_10 ( struct V_1 * V_2 , int error , int V_17 )
{
F_11 ( V_2 , error , V_17 ) ;
}
void F_12 ( struct V_12 * V_13 )
{
if ( V_13 -> V_15 != NULL )
F_7 ( V_13 -> V_15 ) ;
}
void F_13 ( struct V_12 * V_13 )
{
V_13 -> V_18 = V_19 ;
}
int F_14 ( struct V_1 * V_2 ,
T_2 V_20 ,
T_1 * type ,
T_1 * V_5 )
{
int V_6 ;
struct V_3 V_4 ;
if ( ! F_15 () ) {
* V_5 = V_21 ;
return 0 ;
}
F_16 ( & V_4 ) ;
V_6 = F_17 ( V_2 , V_20 , & V_4 ) ;
if ( V_6 == 0 && V_4 . V_7 != V_22 )
V_6 = F_1 ( V_2 , & V_4 , V_5 ) ;
else
* V_5 = V_21 ;
* type = V_4 . type ;
F_18 ( & V_4 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_2 ,
T_2 V_20 ,
T_1 V_5 )
{
int V_6 ;
struct V_3 V_23 ;
struct V_3 * V_4 = NULL ;
struct V_10 * V_11 ;
V_11 = V_2 -> V_11 ;
if ( V_11 != NULL ) {
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_13 -> V_18 != V_24 )
return 0 ;
V_4 = V_13 -> V_15 ;
}
if ( V_4 == NULL ) {
V_4 = & V_23 ;
F_16 ( V_4 ) ;
V_6 = F_6 ( V_5 , V_4 ) ;
if ( V_6 != 0 )
goto V_25;
}
V_6 = F_20 ( V_2 , V_20 , V_4 ) ;
V_25:
if ( V_4 == & V_23 )
F_18 ( V_4 ) ;
return V_6 ;
}
int F_21 ( struct V_26 * V_27 , T_2 V_20 )
{
int V_6 ;
struct V_3 V_4 ;
if ( V_20 != V_28 )
return 0 ;
F_16 ( & V_4 ) ;
V_6 = F_6 ( V_27 -> V_29 , & V_4 ) ;
if ( V_6 != 0 )
goto V_30;
V_6 = F_22 ( V_27 , & V_4 ) ;
V_30:
F_18 ( & V_4 ) ;
return V_6 ;
}
void F_23 ( struct V_10 * V_11 , T_2 V_20 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_20 == V_28 )
V_13 -> V_18 = V_31 ;
else
V_13 -> V_18 = V_19 ;
}
int F_24 ( struct V_10 * V_11 , T_2 V_20 )
{
int V_6 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
if ( V_20 != V_28 )
return 0 ;
V_4 = F_4 ( V_11 ) ;
if ( V_4 == NULL )
return - V_32 ;
V_6 = F_25 ( V_11 , V_20 , V_4 ) ;
switch ( V_6 ) {
case 0 :
V_13 -> V_18 = V_31 ;
break;
case - V_33 :
V_13 -> V_18 = V_24 ;
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_26 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_2 V_20 ,
struct V_34 * V_35 )
{
int V_6 ;
T_1 V_36 ;
T_1 V_37 ;
struct V_3 V_4 ;
if ( ! F_15 () )
return 0 ;
F_16 ( & V_4 ) ;
V_6 = F_17 ( V_2 , V_20 , & V_4 ) ;
if ( V_6 == 0 && V_4 . V_7 != V_22 )
V_6 = F_1 ( V_2 , & V_4 , & V_36 ) ;
else
V_36 = V_38 ;
F_18 ( & V_4 ) ;
if ( V_6 != 0 )
return V_6 ;
switch ( V_13 -> V_39 ) {
case V_40 :
V_37 = V_41 ;
break;
case V_42 :
V_37 = V_43 ;
break;
default:
V_37 = V_44 ;
}
V_6 = F_27 ( V_13 -> V_5 , V_36 , V_13 -> V_39 , V_37 , V_35 ) ;
if ( V_6 == 0 )
return 0 ;
if ( V_36 != V_38 )
F_11 ( V_2 , V_6 , 0 ) ;
return V_6 ;
}
int F_28 ( struct V_45 * V_10 ,
int V_46 ,
int V_47 )
{
int V_6 = 0 ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 V_4 ;
if ( V_46 == V_48 && V_47 == V_49 &&
( V_13 -> V_18 == V_31 ||
V_13 -> V_18 == V_50 ) ) {
F_16 ( & V_4 ) ;
F_29 ( V_11 ) ;
V_6 = F_30 ( V_11 , & V_4 ) ;
F_31 ( V_11 ) ;
if ( V_6 == 0 )
V_6 = - V_51 ;
else if ( V_6 == - V_52 )
V_6 = 0 ;
F_18 ( & V_4 ) ;
}
return V_6 ;
}
int F_32 ( struct V_10 * V_11 , struct V_53 * V_54 )
{
int V_6 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
if ( V_13 -> V_18 != V_24 &&
V_13 -> V_18 != V_50 )
return 0 ;
F_29 ( V_11 ) ;
if ( V_54 -> V_55 == V_56 ) {
F_33 ( V_11 ) ;
V_13 -> V_18 = V_24 ;
V_6 = 0 ;
goto V_57;
}
V_4 = F_4 ( V_11 ) ;
if ( V_4 == NULL ) {
V_6 = - V_32 ;
goto V_57;
}
V_6 = F_34 ( V_11 , V_54 , V_4 ) ;
if ( V_6 == 0 )
V_13 -> V_18 = V_50 ;
V_57:
F_31 ( V_11 ) ;
return V_6 ;
}
