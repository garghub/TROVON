static void
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_7 V_8 ,
const struct V_9 * V_10 )
{
static T_1 V_11 ;
T_2 * V_12 ;
unsigned int V_13 , V_14 , V_15 ;
if ( ! V_10 -> V_16 )
return;
if ( V_8 == V_17 )
V_12 = & V_4 -> V_18 . V_19 . V_20 . V_11 ;
else
V_12 = & V_4 -> V_21 . V_19 . V_20 . V_11 ;
if ( ! ( V_6 -> V_22 & V_23 ) ) {
F_2 ( L_1 , V_10 ) ;
V_13 = 1 ;
V_15 = 0xffff ;
} else {
V_13 = F_3 ( V_6 -> V_24 . V_20 . V_11 ) ;
V_15 = F_3 ( V_6 -> V_25 . V_20 . V_11 ) - V_13 + 1 ;
}
F_2 ( L_2 , V_13 , V_15 ) ;
for ( V_14 = 0 ; ; ++ V_11 ) {
* V_12 = F_4 ( V_13 + V_11 % V_15 ) ;
if ( ++ V_14 == V_15 || ! F_5 ( V_4 , V_10 ) )
return;
}
F_2 ( L_3 , V_10 ) ;
return;
}
static bool
F_6 ( struct V_26 * V_27 ,
const struct V_1 * V_2 ,
unsigned int V_28 , unsigned int V_29 ,
const struct V_3 * V_4 ,
enum V_7 V_8 )
{
const struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( ! F_7 ( V_27 , V_29 + sizeof( * V_33 ) - 8 ) )
return false ;
V_31 = ( void * ) V_27 -> V_34 + V_29 ;
V_33 = (struct V_32 * ) V_31 ;
if ( V_8 != V_35 )
return true ;
switch ( V_31 -> V_36 ) {
case V_37 :
break;
case V_38 :
F_2 ( L_4 , F_3 ( V_4 -> V_21 . V_19 . V_20 . V_11 ) ) ;
V_33 -> V_39 = V_4 -> V_21 . V_19 . V_20 . V_11 ;
break;
default:
F_2 ( L_5 ) ;
return false ;
}
return true ;
}
static int T_3 F_8 ( void )
{
return F_9 ( V_40 , & V_20 ) ;
}
static void T_4 F_10 ( void )
{
F_11 ( V_40 , & V_20 ) ;
}
void F_12 ( void )
{
return;
}
