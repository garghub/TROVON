void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
T_1 V_5 ;
V_5 = sizeof( V_6 . V_7 ) ;
if ( V_5 > V_4 )
V_5 = V_4 ;
memcpy ( V_6 . V_7 , V_3 , V_5 ) ;
}
T_1 F_2 ( struct V_1 * V_2 )
{
return V_6 . V_8 . V_9 ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
return V_6 . V_8 . V_10 ;
}
bool F_4 ( struct V_1 * V_2 )
{
return V_6 . V_8 . V_11 ;
}
bool F_5 ( struct V_1 * V_2 )
{
return V_6 . V_8 . V_12 ;
}
void F_6 ( struct V_1 * V_2 , T_1 * V_13 ,
T_1 * V_14 , T_1 * V_15 )
{
if ( V_13 )
* V_13 = V_6 . V_8 . V_16 ;
if ( V_14 )
* V_14 = V_6 . V_8 . V_17 ;
if ( V_15 )
* V_15 = V_6 . V_8 . V_18 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 () ;
F_9 ( V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_19 ;
V_19 = F_12 ( V_2 ) ;
F_13 ( V_2 , V_20 , V_21 ,
L_1 , V_22 , V_19 ) ;
F_14 ( & V_6 , ! V_19 ) ;
F_15 ( & V_6 ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 type )
{
F_17 ( & V_6 , type ) ;
}
void F_18 ( struct V_1 * V_2 , T_1 type )
{
F_19 ( & V_6 , type ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_23 )
{
F_21 ( & V_6 , V_23 ) ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_24 )
{
F_23 ( & V_6 , V_24 ) ;
}
void F_24 ( struct V_1 * V_2 ,
enum V_25 V_26 )
{
F_25 ( & V_6 , V_26 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_6 ) ;
}
void F_28 ( void )
{
struct V_27 * V_28 = & V_6 ;
F_29 ( V_28 ) ;
}
void F_30 ( struct V_1 * V_2 , T_1 * V_29 , T_1 V_30 )
{
F_31 ( & V_6 , V_29 , V_30 ) ;
}
bool F_32 ( struct V_1 * V_2 )
{
return V_6 . V_8 . V_31 ;
}
bool F_33 ( struct V_1 * V_2 )
{
bool V_32 = false ;
T_2 V_33 ;
T_2 V_34 = 0x5ea42b , V_35 = 0x5ea42b ;
T_2 V_36 ;
T_2 V_37 = 0x504 ;
V_33 = F_34 ( V_2 , V_37 ) ;
if ( F_35 ( V_2 ) ) {
if ( V_33 != V_34 ) {
V_36 = V_34 ;
V_32 = true ;
}
} else {
if ( V_33 != V_35 ) {
V_36 = V_35 ;
V_32 = true ;
}
}
if ( V_32 )
F_36 ( V_2 , V_37 , V_36 ) ;
return true ;
}
bool F_37 ( struct V_1 * V_2 )
{
if ( V_6 . V_8 . V_38 )
return true ;
else
return false ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_39 )
{
return F_39 ( & V_6 , V_39 ) ;
}
struct V_40 * F_40 ( void )
{
return & V_41 ;
}
enum V_25 F_41 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_1 ( V_43 ) ;
struct V_44 * V_45 = V_44 ( V_1 ( V_43 ) ) ;
enum V_25 V_46 = V_47 ;
T_1 V_48 = ( V_45 -> V_49 == V_50 ) ? 1 : 0 ;
if ( V_48 || V_2 -> V_51 . V_52 >= V_53 )
V_46 = V_54 ;
return V_46 ;
}
T_1 F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_28 . V_55 . V_28 ;
}
static int T_3 F_42 ( void )
{
return 0 ;
}
static void T_4 F_43 ( void )
{
return;
}
