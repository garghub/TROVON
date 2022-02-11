static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
const struct V_5 * V_7 ;
const struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_11 ;
unsigned int V_12 = 0 ;
unsigned int V_13 = 0 ;
bool V_14 = false ;
T_1 V_15 ;
T_1 V_16 ;
const T_2 * V_17 = NULL ;
const T_2 * V_18 = NULL ;
unsigned int V_19 ;
int V_20 ;
V_20 = F_2 ( V_2 , & V_12 ,
( V_4 -> V_21 == & V_22 [ 0 ] ) ?
V_23 : V_24 , NULL , NULL ) ;
if ( V_20 < 0 ) {
if ( V_20 != - V_25 )
V_4 -> V_26 = true ;
return false ;
}
V_7 = F_3 ( V_2 , V_12 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 == NULL ) {
V_4 -> V_26 = true ;
return false ;
}
V_13 = F_4 ( V_7 ) ;
if ( V_2 -> V_27 - V_12 < V_13 ) {
return false ;
}
F_5 ( L_1 , V_13 , V_7 -> V_13 ) ;
F_5 ( L_2 ,
V_9 -> V_13 , V_13 ,
( ! ( V_9 -> V_28 & V_29 ) ||
( ( V_9 -> V_13 == V_13 ) ^
! ! ( V_9 -> V_30 & V_31 ) ) ) ) ;
V_14 = ( V_7 != NULL ) &&
( ! ( V_9 -> V_28 & V_29 ) ||
( ( V_9 -> V_13 == V_13 ) ^
! ! ( V_9 -> V_30 & V_31 ) ) ) ;
V_12 += 2 ;
V_13 -= 2 ;
if ( ! ( V_9 -> V_28 & V_32 ) ) {
return V_14 ;
} else {
F_5 ( L_3 ) ;
F_5 ( L_4 , V_9 -> V_33 ) ;
for ( V_11 = 0 ; V_11 < V_9 -> V_33 ; V_11 ++ ) {
if ( V_13 < 1 )
break;
V_17 = F_3 ( V_2 , V_12 , sizeof( V_15 ) ,
& V_15 ) ;
if ( V_17 == NULL )
break;
if ( * V_17 != ( V_9 -> V_34 [ V_11 ] & 0xFF00 ) >> 8 ) {
F_5 ( L_5 , * V_17 ,
( V_9 -> V_34 [ V_11 ] & 0xFF00 ) >> 8 ) ;
return false ;
} else {
F_5 ( L_6 ) ;
}
if ( * V_17 ) {
T_3 V_35 ;
if ( V_13 < 2 )
break;
V_18 = F_3 ( V_2 , V_12 + 1 ,
sizeof( V_16 ) ,
& V_16 ) ;
if ( V_18 == NULL )
break;
V_35 = V_9 -> V_34 [ V_11 ] & 0x00FF ;
if ( V_35 != 0x00FF && V_35 != * V_18 ) {
F_5 ( L_7 , * V_18 ,
V_35 ) ;
return false ;
}
F_5 ( L_8 ) ;
V_19 = * V_18 + 2 ;
} else {
F_5 ( L_9 ) ;
V_19 = 1 ;
}
F_5 ( L_10 , V_19 ) ;
if ( ( V_12 > V_2 -> V_27 - V_19 || V_13 < V_19 ) &&
V_11 < V_9 -> V_33 - 1 ) {
F_5 ( L_11 ) ;
break;
}
V_12 += V_19 ;
V_13 -= V_19 ;
}
if ( V_11 == V_9 -> V_33 )
return V_14 ;
else
return false ;
}
return false ;
}
static int F_6 ( const struct V_36 * V_4 )
{
const struct V_8 * V_37 = V_4 -> V_10 ;
if ( V_37 -> V_30 & ~ V_38 ) {
F_5 ( L_12 , V_37 -> V_30 ) ;
return - V_39 ;
}
if ( V_37 -> V_28 & V_40 ) {
F_5 ( L_13 ) ;
return - V_39 ;
}
return 0 ;
}
static int T_4 F_7 ( void )
{
return F_8 ( V_22 , F_9 ( V_22 ) ) ;
}
static void T_5 F_10 ( void )
{
F_11 ( V_22 , F_9 ( V_22 ) ) ;
}
