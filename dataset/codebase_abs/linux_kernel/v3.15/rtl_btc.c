void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_3 = F_4 ( V_2 ) ;
F_5 ( V_2 , V_6 , V_7 ,
L_1 , V_8 , V_3 ) ;
V_4 = F_6 ( V_2 ) ;
F_5 ( V_2 , V_6 , V_7 ,
L_2 , V_8 , V_4 ) ;
F_7 ( V_4 ) ;
V_5 = F_8 ( V_2 ) ;
F_5 ( V_2 , V_6 , V_7 , L_3 ,
V_8 , V_5 ) ;
F_9 ( V_5 ) ;
F_10 ( V_9 , V_3 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_10 ) ;
F_13 ( & V_10 ) ;
}
void F_14 ( struct V_1 * V_2 , T_1 type )
{
F_15 ( & V_10 , type ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_11 )
{
F_17 ( & V_10 , V_11 ) ;
}
void F_18 ( struct V_1 * V_2 , T_1 V_12 )
{
F_19 ( & V_10 , V_12 ) ;
}
void F_20 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
F_21 ( & V_10 , V_14 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_10 ) ;
}
void F_24 ( void )
{
F_25 ( & V_10 ) ;
}
void F_26 ( struct V_1 * V_2 , T_1 * V_15 , T_1 V_16 )
{
F_27 ( & V_10 , V_15 , V_16 ) ;
}
bool F_28 ( struct V_1 * V_2 )
{
return V_10 . V_17 . V_18 ;
}
bool F_29 ( struct V_1 * V_2 )
{
bool V_19 = false ;
T_2 V_20 ;
T_2 V_21 = 0x5ea42b , V_22 = 0x5ea42b ;
T_2 V_23 ;
T_2 V_24 = 0x504 ;
V_20 = F_30 ( V_2 , V_24 ) ;
if ( F_31 ( V_2 ) ) {
if ( V_20 != V_21 ) {
V_23 = V_21 ;
V_19 = true ;
}
} else {
if ( V_20 != V_22 ) {
V_23 = V_22 ;
V_19 = true ;
}
}
if ( V_19 )
F_32 ( V_2 , V_24 , V_23 ) ;
return true ;
}
bool F_33 ( struct V_1 * V_2 )
{
if ( V_10 . V_17 . V_25 )
return true ;
else
return false ;
}
struct V_26 * F_34 ( void )
{
return & V_27 ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_28 ;
if ( V_2 -> V_29 . V_30 . V_3 == V_31 )
V_28 = 2 ;
else
V_28 = 1 ;
return V_28 ;
}
enum V_13 F_35 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_1 ( V_33 ) ;
struct V_34 * V_35 = V_34 ( V_1 ( V_33 ) ) ;
enum V_13 V_36 = V_37 ;
T_1 V_38 = ( V_35 -> V_39 == V_40 ) ? 1 : 0 ;
if ( V_38 || V_2 -> V_41 . V_42 >= V_43 )
V_36 = V_44 ;
return V_36 ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_29 . V_30 . V_29 ;
}
T_1 F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_29 . V_30 . V_5 ;
}
static int T_3 F_36 ( void )
{
return 0 ;
}
static void T_4 F_37 ( void )
{
return;
}
