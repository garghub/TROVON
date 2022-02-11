static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_6 , const char * V_7 )
{
int V_8 = 0 , V_9 = 0 ;
V_9 = ( V_6 ) ? 0 : V_5 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( ( V_11 -> V_12 ( V_4 ) & V_5 ) == V_9 )
break;
F_2 ( 1 ) ;
}
if ( V_8 < V_10 )
F_3 ( L_1 ,
V_7 , V_8 ) ;
else
F_4 ( L_2 ,
V_7 , V_10 ) ;
return ( V_8 < V_10 ) ? 1 : 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 V_13 , V_14 ;
T_2 V_15 , V_16 , V_17 , V_18 ;
T_3 V_19 ;
int V_20 ;
if ( V_2 -> V_21 -> V_22 ) {
V_2 -> V_21 -> V_22 ( V_2 , & V_13 , & V_15 ) ;
if ( ! ( V_11 -> V_12 ( & V_13 ) &
( 1 << V_15 ) ) )
return;
}
V_2 -> V_21 -> V_23 ( V_2 , & V_14 , & V_16 , & V_17 ) ;
V_20 = V_11 -> V_24 ( & V_14 , & V_19 ,
& V_18 ) ;
if ( V_20 ) {
F_1 ( V_2 , & V_14 , ( 1 << V_16 ) ,
V_17 , F_6 ( & V_2 -> V_25 ) ) ;
} else {
V_11 -> V_26 ( 0 , V_19 , V_18 ,
V_16 ) ;
}
}
void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_27 ,
T_2 * V_15 )
{
memcpy ( V_27 , & V_2 -> V_28 , sizeof( * V_27 ) ) ;
V_27 -> V_29 ^= ( V_30 ^ V_31 ) ;
* V_15 = V_2 -> V_32 ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_14 , T_2 * V_16 ,
T_2 * V_17 )
{
memcpy ( V_14 , & V_2 -> V_28 , sizeof( * V_14 ) ) ;
V_14 -> V_29 &= ~ 0xf0 ;
V_14 -> V_29 |= 0x20 ;
* V_16 = V_2 -> V_32 ;
* V_17 = F_9 () -> V_33 ;
}
int F_10 ( struct V_34 * V_25 )
{
struct V_1 * V_2 ;
T_1 V_35 ;
int V_36 = 0 ;
bool V_37 ;
if ( F_9 () -> V_38 & V_39 )
V_37 = false ;
else
V_37 = true ;
V_2 = F_11 ( V_25 ) ;
if ( V_37 && V_2 -> V_40 ) {
V_36 = V_11 -> V_41 ( V_2 -> V_40 , V_25 -> V_2 ) ;
if ( V_36 ) {
F_12 ( 1 ,
L_3 ,
V_42 , F_6 ( V_25 ) ,
V_2 -> V_43 , V_36 ) ;
return V_36 ;
}
}
V_35 = V_11 -> V_12 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_38 & V_44 )
V_35 &= ~ ( 1 << V_2 -> V_32 ) ;
else
V_35 |= ( 1 << V_2 -> V_32 ) ;
V_11 -> V_45 ( V_35 , & V_2 -> V_28 ) ;
V_35 = V_11 -> V_12 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_21 && V_2 -> V_21 -> V_23 )
F_5 ( V_2 ) ;
return 0 ;
}
void F_13 ( struct V_34 * V_25 )
{
struct V_1 * V_2 ;
T_1 V_35 ;
V_2 = F_11 ( V_25 ) ;
V_35 = V_11 -> V_12 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_38 & V_44 )
V_35 |= ( 1 << V_2 -> V_32 ) ;
else
V_35 &= ~ ( 1 << V_2 -> V_32 ) ;
V_11 -> V_45 ( V_35 , & V_2 -> V_28 ) ;
if ( ! ( F_9 () -> V_38 & V_39 ) &&
V_2 -> V_40 )
V_11 -> V_46 ( V_2 -> V_40 , V_25 -> V_2 ) ;
}
int F_14 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) ;
T_1 V_35 ;
V_35 = V_11 -> V_12 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_38 & V_44 )
V_35 ^= F_15 ( V_2 -> V_32 ) ;
V_35 &= F_15 ( V_2 -> V_32 ) ;
return V_35 ? 1 : 0 ;
}
