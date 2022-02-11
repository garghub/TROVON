static T_1 F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 ,
void * * V_4 )
{
bool * V_5 = V_3 ;
* V_5 = true ;
return V_6 ;
}
static bool F_2 ( struct V_7 * V_8 )
{
bool V_5 = false ;
if ( V_8 -> V_9 . V_10 >> 16 != 0x17aa )
return false ;
if ( F_3 ( F_4 ( L_1 , F_1 , & V_5 , NULL ) ) && V_5 )
return true ;
V_5 = false ;
return F_3 ( F_4 ( L_2 , F_1 , & V_5 , NULL ) ) && V_5 ;
}
static void F_5 ( void * V_11 , int V_12 )
{
if ( V_13 )
V_13 ( V_11 , V_12 ) ;
if ( V_14 )
V_14 ( V_15 , ! V_12 ) ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
if ( ! V_19 || ! V_14 )
return;
if ( strcmp ( L_3 , V_19 -> V_20 . V_21 ) == 0 && V_19 -> V_20 . V_22 == 0 ) {
bool V_23 = V_19 -> V_24 . integer . V_24 [ 0 ] || V_19 -> V_24 . integer . V_24 [ 1 ] ;
V_14 ( V_25 , ! V_23 ) ;
}
}
static void F_7 ( struct V_7 * V_8 ,
const struct V_26 * V_27 , int V_28 )
{
struct V_29 * V_30 = V_8 -> V_30 ;
bool V_31 = false ;
if ( V_28 == V_32 ) {
if ( ! F_2 ( V_8 ) )
return;
if ( ! V_14 )
V_14 = F_8 ( V_33 ) ;
if ( ! V_14 ) {
F_9 ( V_8 ,
L_4 ) ;
return;
}
V_31 = true ;
if ( V_14 ( V_15 , false ) >= 0 ) {
V_13 = V_30 -> V_34 . V_35 ;
V_30 -> V_34 . V_35 = F_5 ;
V_31 = false ;
}
if ( V_14 ( V_25 , false ) >= 0 ) {
if ( V_30 -> V_36 > 1 )
F_10 ( V_8 ,
L_5 ) ;
else {
V_30 -> V_37 = F_6 ;
V_31 = false ;
}
}
}
if ( V_14 && ( V_28 == V_38 || V_31 ) ) {
F_11 ( V_33 ) ;
V_14 = NULL ;
V_13 = NULL ;
}
}
static void F_7 ( struct V_7 * V_8 ,
const struct V_26 * V_27 , int V_28 )
{
}
