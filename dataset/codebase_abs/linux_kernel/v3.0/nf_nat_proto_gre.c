static void
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 V_6 ,
const struct V_7 * V_8 )
{
static T_1 V_9 ;
T_2 * V_10 ;
unsigned int V_11 , V_12 , V_13 ;
if ( ! V_8 -> V_14 )
return;
if ( V_6 == V_15 )
V_10 = & V_2 -> V_16 . V_17 . V_18 . V_9 ;
else
V_10 = & V_2 -> V_19 . V_17 . V_18 . V_9 ;
if ( ! ( V_4 -> V_20 & V_21 ) ) {
F_2 ( L_1 , V_8 ) ;
V_11 = 1 ;
V_13 = 0xffff ;
} else {
V_11 = F_3 ( V_4 -> V_11 . V_18 . V_9 ) ;
V_13 = F_3 ( V_4 -> V_22 . V_18 . V_9 ) - V_11 + 1 ;
}
F_2 ( L_2 , V_11 , V_13 ) ;
for ( V_12 = 0 ; ; ++ V_9 ) {
* V_10 = F_4 ( V_11 + V_9 % V_13 ) ;
if ( ++ V_12 == V_13 || ! F_5 ( V_2 , V_8 ) )
return;
}
F_2 ( L_3 , V_8 ) ;
return;
}
static bool
F_6 ( struct V_23 * V_24 , unsigned int V_25 ,
const struct V_1 * V_2 ,
enum V_5 V_6 )
{
const struct V_26 * V_27 ;
struct V_28 * V_29 ;
const struct V_30 * V_31 = (struct V_30 * ) ( V_24 -> V_32 + V_25 ) ;
unsigned int V_33 = V_25 + V_31 -> V_34 * 4 ;
if ( ! F_7 ( V_24 , V_33 + sizeof( * V_29 ) - 8 ) )
return false ;
V_27 = ( void * ) V_24 -> V_32 + V_33 ;
V_29 = (struct V_28 * ) V_27 ;
if ( V_6 != V_35 )
return true ;
switch ( V_27 -> V_36 ) {
case V_37 :
break;
case V_38 :
F_2 ( L_4 , F_3 ( V_2 -> V_19 . V_17 . V_18 . V_9 ) ) ;
V_29 -> V_39 = V_2 -> V_19 . V_17 . V_18 . V_9 ;
break;
default:
F_2 ( L_5 ) ;
return false ;
}
return true ;
}
static int T_3 F_8 ( void )
{
return F_9 ( & V_18 ) ;
}
static void T_4 F_10 ( void )
{
F_11 ( & V_18 ) ;
}
void F_12 ( void )
{
return;
}
