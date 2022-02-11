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
if ( V_8 -> V_9 >> 16 != 0x17aa )
return false ;
if ( F_3 ( F_4 ( L_1 , F_1 , & V_5 , NULL ) ) && V_5 )
return true ;
V_5 = false ;
return F_3 ( F_4 ( L_2 , F_1 , & V_5 , NULL ) ) && V_5 ;
}
static void F_5 ( void * V_10 , int V_11 )
{
if ( V_12 )
V_12 ( V_10 , V_11 ) ;
if ( V_13 )
V_13 ( V_14 , ! V_11 ) ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
if ( ! V_18 || ! V_13 )
return;
if ( strcmp ( L_3 , V_18 -> V_19 . V_20 ) == 0 && V_18 -> V_19 . V_21 == 0 ) {
bool V_22 = V_18 -> V_23 . integer . V_23 [ 0 ] || V_18 -> V_23 . integer . V_23 [ 1 ] ;
V_13 ( V_24 , ! V_22 ) ;
}
}
static void F_7 ( struct V_7 * V_8 ,
const struct V_25 * V_26 , int V_27 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
bool V_30 = false ;
if ( V_27 == V_31 ) {
if ( ! F_2 ( V_8 ) )
return;
if ( ! V_13 )
V_13 = F_8 ( V_32 ) ;
if ( ! V_13 ) {
F_9 ( V_8 ,
L_4 ) ;
return;
}
V_30 = true ;
if ( V_13 ( V_14 , false ) >= 0 ) {
V_12 = V_29 -> V_33 . V_34 ;
V_29 -> V_33 . V_34 = F_5 ;
V_30 = false ;
}
if ( V_13 ( V_24 , false ) >= 0 ) {
if ( V_29 -> V_35 > 1 )
F_10 ( V_8 ,
L_5 ) ;
else {
V_29 -> V_36 = F_6 ;
V_30 = false ;
}
}
}
if ( V_13 && ( V_27 == V_37 || V_30 ) ) {
F_11 ( V_32 ) ;
V_13 = NULL ;
V_12 = NULL ;
}
}
static void F_7 ( struct V_7 * V_8 ,
const struct V_25 * V_26 , int V_27 )
{
}
