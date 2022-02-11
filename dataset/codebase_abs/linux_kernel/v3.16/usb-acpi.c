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
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_9 * V_10 ;
T_1 V_4 ;
unsigned char V_11 ;
int V_5 = V_3 + 1 ;
int error = - V_12 ;
if ( ! V_8 )
return - V_13 ;
V_10 = V_8 -> V_14 [ V_5 - 1 ] ;
V_4 = ( T_1 ) F_2 ( V_2 , V_5 ) ;
if ( ! V_4 )
return error ;
if ( V_6 )
V_11 = V_15 ;
else
V_11 = V_16 ;
error = F_6 ( V_4 , V_11 ) ;
if ( ! error )
F_7 ( & V_10 -> V_17 , L_1 , V_6 ) ;
else
F_7 ( & V_10 -> V_17 , L_2 ) ;
return error ;
}
static enum V_18 F_8 ( T_1 V_19 ,
struct V_20 * V_21 )
{
enum V_18 V_22 = V_23 ;
struct V_24 V_25 = { V_26 , NULL } ;
union V_27 * V_28 ;
T_2 V_29 ;
V_29 = F_9 ( V_19 , L_3 , NULL , & V_25 ) ;
V_28 = V_25 . V_30 ;
if ( ! V_28 || ( V_28 -> type != V_31 )
|| V_28 -> V_32 . V_33 != 4 ) {
goto V_34;
}
if ( V_28 -> V_32 . V_35 [ 0 ] . integer . V_36 )
if ( V_21 -> V_37 )
V_22 = V_38 ;
else
V_22 = V_39 ;
else if ( ! V_21 -> V_37 )
V_22 = V_40 ;
V_34:
F_10 ( V_28 ) ;
return V_22 ;
}
static struct V_41 * F_11 ( struct V_42 * V_17 )
{
struct V_1 * V_43 ;
struct V_41 * V_44 ;
T_1 * V_45 ;
if ( F_12 ( V_17 ) ) {
V_43 = F_13 ( V_17 ) ;
if ( V_43 -> V_46 )
return NULL ;
V_44 = F_14 ( V_17 -> V_46 ) ;
return F_15 ( V_44 , 0 , false ) ;
} else if ( F_16 ( V_17 ) ) {
struct V_9 * V_10 = F_17 ( V_17 ) ;
int V_5 = V_10 -> V_47 ;
struct V_20 * V_21 ;
T_1 * V_19 ;
T_2 V_29 ;
V_43 = F_13 ( V_17 -> V_46 -> V_46 ) ;
if ( ! V_43 -> V_46 ) {
struct V_48 * V_49 = F_18 ( V_43 -> V_50 ) ;
int V_51 ;
V_51 = F_19 ( V_49 , V_5 ) ;
V_44 = F_15 ( F_14 ( & V_43 -> V_17 ) ,
V_51 , false ) ;
if ( ! V_44 )
return NULL ;
} else {
V_45 =
F_2 ( V_43 -> V_46 ,
V_43 -> V_47 ) ;
if ( ! V_45 )
return NULL ;
F_20 ( V_45 , & V_44 ) ;
V_44 = F_15 ( V_44 , V_5 , false ) ;
if ( ! V_44 )
return NULL ;
}
V_19 = V_44 -> V_19 ;
V_29 = F_21 ( V_19 , & V_21 ) ;
if ( F_22 ( V_29 ) || ! V_21 )
return V_44 ;
V_10 -> V_52 = V_53
| V_21 -> V_54 << 8 | V_21 -> V_55 ;
V_10 -> V_22 = F_8 ( V_19 , V_21 ) ;
F_23 ( V_21 ) ;
return V_44 ;
}
return NULL ;
}
static bool F_24 ( struct V_42 * V_17 )
{
return F_12 ( V_17 ) || F_16 ( V_17 ) ;
}
int F_25 ( void )
{
return F_26 ( & V_56 ) ;
}
void F_27 ( void )
{
F_28 ( & V_56 ) ;
}
