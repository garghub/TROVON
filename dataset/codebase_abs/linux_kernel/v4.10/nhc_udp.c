static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 = 0 , V_5 = 0 ;
struct V_6 V_7 ;
bool V_8 ;
int V_9 ;
V_8 = F_2 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
F_3 ( L_1 ) ;
switch ( V_4 & V_10 ) {
case V_11 :
V_8 |= F_2 ( V_2 , & V_7 . V_12 , sizeof( V_7 . V_12 ) ) ;
V_8 |= F_2 ( V_2 , & V_7 . V_13 , sizeof( V_7 . V_13 ) ) ;
break;
case V_14 :
V_8 |= F_2 ( V_2 , & V_7 . V_12 , sizeof( V_7 . V_12 ) ) ;
V_8 |= F_2 ( V_2 , & V_5 , sizeof( V_5 ) ) ;
V_7 . V_13 = F_4 ( V_5 + V_15 ) ;
break;
case V_16 :
V_8 |= F_2 ( V_2 , & V_5 , sizeof( V_5 ) ) ;
V_7 . V_12 = F_4 ( V_5 + V_15 ) ;
V_8 |= F_2 ( V_2 , & V_7 . V_13 , sizeof( V_7 . V_13 ) ) ;
break;
case V_10 :
V_8 |= F_2 ( V_2 , & V_5 , sizeof( V_5 ) ) ;
V_7 . V_12 = F_4 ( V_17 + ( V_5 >> 4 ) ) ;
V_7 . V_13 = F_4 ( V_17 + ( V_5 & 0x0f ) ) ;
break;
default:
F_5 () ;
}
F_3 ( L_2 ,
F_6 ( V_7 . V_12 ) , F_6 ( V_7 . V_13 ) ) ;
if ( V_4 & V_18 ) {
F_7 ( L_3 ) ;
V_8 = true ;
} else {
V_8 |= F_2 ( V_2 , & V_7 . V_19 , sizeof( V_7 . V_19 ) ) ;
}
if ( V_8 )
return - V_20 ;
switch ( F_8 ( V_2 -> V_21 ) -> V_22 ) {
case V_23 :
if ( F_9 ( V_2 ) -> V_24 )
V_7 . V_25 = F_4 ( F_9 ( V_2 ) -> V_24 -
sizeof( struct V_26 ) ) ;
else
V_7 . V_25 = F_4 ( V_2 -> V_25 + sizeof( struct V_6 ) ) ;
break;
default:
V_7 . V_25 = F_4 ( V_2 -> V_25 + sizeof( struct V_6 ) ) ;
break;
}
F_3 ( L_4 , F_6 ( V_7 . V_25 ) ) ;
V_9 = F_10 ( V_2 , V_3 ) ;
if ( F_11 ( V_9 ) )
return V_9 ;
F_12 ( V_2 , sizeof( struct V_6 ) ) ;
F_13 ( V_2 , & V_7 , sizeof( struct V_6 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 * * V_27 )
{
const struct V_6 * V_7 = F_15 ( V_2 ) ;
T_2 V_4 ;
if ( ( ( F_6 ( V_7 -> V_12 ) & V_28 ) ==
V_17 ) &&
( ( F_6 ( V_7 -> V_13 ) & V_28 ) ==
V_17 ) ) {
F_3 ( L_5 ) ;
V_4 = V_10 ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
V_4 = F_6 ( V_7 -> V_13 ) - V_17 +
( ( F_6 ( V_7 -> V_12 ) - V_17 ) << 4 ) ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
} else if ( ( F_6 ( V_7 -> V_13 ) & V_29 ) ==
V_15 ) {
F_3 ( L_6 ) ;
V_4 = V_14 ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
F_16 ( V_27 , & V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
V_4 = F_6 ( V_7 -> V_13 ) - V_15 ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
} else if ( ( F_6 ( V_7 -> V_12 ) & V_29 ) ==
V_15 ) {
F_3 ( L_7 ) ;
V_4 = V_16 ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
V_4 = F_6 ( V_7 -> V_12 ) - V_15 ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
F_16 ( V_27 , & V_7 -> V_13 , sizeof( V_7 -> V_13 ) ) ;
} else {
F_3 ( L_8 ) ;
V_4 = V_11 ;
F_16 ( V_27 , & V_4 , sizeof( V_4 ) ) ;
F_16 ( V_27 , & V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
F_16 ( V_27 , & V_7 -> V_13 , sizeof( V_7 -> V_13 ) ) ;
}
F_16 ( V_27 , & V_7 -> V_19 , sizeof( V_7 -> V_19 ) ) ;
return 0 ;
}
static void F_17 ( struct V_30 * V_31 )
{
V_31 -> V_32 [ 0 ] = V_33 ;
V_31 -> V_34 [ 0 ] = V_35 ;
}
