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
static struct V_41 * F_11 ( struct V_41 * V_42 ,
int V_43 )
{
struct V_41 * V_44 ;
if ( ! V_42 )
return NULL ;
F_12 (adev, &parent->children, node) {
if ( F_13 ( V_44 ) == V_43 )
return V_44 ;
}
return F_14 ( V_42 , V_43 , false ) ;
}
static struct V_41 * F_15 ( struct V_45 * V_17 )
{
struct V_1 * V_46 ;
struct V_41 * V_44 ;
T_1 * V_47 ;
if ( F_16 ( V_17 ) ) {
V_46 = F_17 ( V_17 ) ;
if ( V_46 -> V_42 )
return NULL ;
V_44 = F_18 ( V_17 -> V_42 ) ;
return F_14 ( V_44 , 0 , false ) ;
} else if ( F_19 ( V_17 ) ) {
struct V_9 * V_10 = F_20 ( V_17 ) ;
int V_5 = V_10 -> V_48 ;
struct V_20 * V_21 ;
T_1 * V_19 ;
T_2 V_29 ;
V_46 = F_17 ( V_17 -> V_42 -> V_42 ) ;
if ( ! V_46 -> V_42 ) {
struct V_49 * V_50 = F_21 ( V_46 -> V_51 ) ;
int V_43 ;
V_43 = F_22 ( V_50 , V_5 ) ;
V_44 = F_11 ( F_18 ( & V_46 -> V_17 ) ,
V_43 ) ;
if ( ! V_44 )
return NULL ;
} else {
V_47 =
F_2 ( V_46 -> V_42 ,
V_46 -> V_48 ) ;
if ( ! V_47 )
return NULL ;
F_23 ( V_47 , & V_44 ) ;
V_44 = F_11 ( V_44 , V_5 ) ;
if ( ! V_44 )
return NULL ;
}
V_19 = V_44 -> V_19 ;
V_29 = F_24 ( V_19 , & V_21 ) ;
if ( F_25 ( V_29 ) || ! V_21 )
return V_44 ;
V_10 -> V_52 = V_53
| V_21 -> V_54 << 8 | V_21 -> V_55 ;
V_10 -> V_22 = F_8 ( V_19 , V_21 ) ;
F_26 ( V_21 ) ;
return V_44 ;
}
return NULL ;
}
static bool F_27 ( struct V_45 * V_17 )
{
return F_16 ( V_17 ) || F_19 ( V_17 ) ;
}
int F_28 ( void )
{
return F_29 ( & V_56 ) ;
}
void F_30 ( void )
{
F_31 ( & V_56 ) ;
}
