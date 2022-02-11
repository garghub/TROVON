bool F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
int V_5 = V_3 + 1 ;
V_4 = F_2 ( V_2 ,
V_5 ) ;
if ( V_4 )
return F_3 ( V_4 ) ;
else
return false ;
}
int F_4 ( struct V_1 * V_2 , int V_3 , bool V_6 )
{
T_1 V_4 ;
unsigned char V_7 ;
int V_5 = V_3 + 1 ;
int error = - V_8 ;
V_4 = ( T_1 ) F_2 ( V_2 ,
V_5 ) ;
if ( ! V_4 )
return error ;
if ( V_6 )
V_7 = V_9 ;
else
V_7 = V_10 ;
error = F_5 ( V_4 , V_7 ) ;
if ( ! error )
F_6 ( & V_2 -> V_11 , L_1 ,
V_5 , V_6 ) ;
else
F_6 ( & V_2 -> V_11 , L_2 ) ;
return error ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_12 , int V_5 )
{
T_2 V_13 ;
struct V_14 V_15 = { V_16 , NULL } ;
union V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 = 0 ;
V_13 = F_8 ( V_12 , & V_20 ) ;
if ( F_9 ( V_13 ) )
return - V_22 ;
V_13 = F_10 ( V_12 , L_3 , NULL , & V_15 ) ;
V_18 = V_15 . V_23 ;
if ( ! V_18 || ( V_18 -> type != V_24 )
|| V_18 -> V_25 . V_26 != 4 ) {
V_21 = - V_8 ;
goto V_27;
}
if ( V_18 -> V_25 . V_28 [ 0 ] . integer . V_29 )
if ( V_20 -> V_30 )
F_11 ( V_2 , V_5 ,
V_31 ) ;
else
F_11 ( V_2 , V_5 ,
V_32 ) ;
else if ( ! V_20 -> V_30 )
F_11 ( V_2 , V_5 , V_33 ) ;
V_27:
F_12 ( V_20 ) ;
F_13 ( V_18 ) ;
return V_21 ;
}
static struct V_34 * F_14 ( struct V_35 * V_11 )
{
struct V_1 * V_36 ;
T_1 * V_37 ;
int V_38 ;
if ( F_15 ( V_11 ) ) {
V_36 = F_16 ( V_11 ) ;
if ( V_36 -> V_39 ) {
enum V_40 type ;
type = F_17 ( V_36 -> V_39 ,
V_36 -> V_41 ) ;
switch ( type ) {
case V_31 :
V_36 -> V_42 = V_43 ;
break;
case V_32 :
V_36 -> V_42 = V_44 ;
break;
default:
V_36 -> V_42 = V_45 ;
break;
}
return NULL ;
}
return F_18 ( F_19 ( V_11 -> V_39 ) ,
V_36 -> V_41 , false ) ;
} else if ( F_20 ( V_11 ) ) {
struct V_34 * V_46 = NULL ;
sscanf ( F_21 ( V_11 ) , L_4 , & V_38 ) ;
V_36 = F_16 ( V_11 -> V_39 -> V_39 ) ;
if ( ! V_36 -> V_39 ) {
struct V_47 * V_48 = F_22 ( V_36 -> V_49 ) ;
int V_50 ;
V_50 = F_23 ( V_48 ,
V_38 ) ;
V_46 = F_18 ( F_19 ( & V_36 -> V_11 ) ,
V_50 , false ) ;
if ( ! V_46 )
return NULL ;
} else {
V_37 =
F_2 ( V_36 -> V_39 ,
V_36 -> V_41 ) ;
if ( ! V_37 )
return NULL ;
F_24 ( V_37 , & V_46 ) ;
V_46 = F_18 ( V_46 , V_38 , false ) ;
if ( ! V_46 )
return NULL ;
}
F_7 ( V_36 , V_46 -> V_12 , V_38 ) ;
return V_46 ;
}
return NULL ;
}
static bool F_25 ( struct V_35 * V_11 )
{
return F_15 ( V_11 ) || F_20 ( V_11 ) ;
}
int F_26 ( void )
{
return F_27 ( & V_51 ) ;
}
void F_28 ( void )
{
F_29 ( & V_51 ) ;
}
