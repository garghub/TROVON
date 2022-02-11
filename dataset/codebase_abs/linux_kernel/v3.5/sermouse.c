static void F_1 ( struct V_1 * V_1 , signed char V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
signed char * V_5 = V_1 -> V_5 ;
switch ( V_1 -> V_6 ) {
case 0 :
if ( ( V_2 & 0xf8 ) != 0x80 )
return;
F_2 ( V_4 , V_7 , ! ( V_2 & 4 ) ) ;
F_2 ( V_4 , V_8 , ! ( V_2 & 1 ) ) ;
F_2 ( V_4 , V_9 , ! ( V_2 & 2 ) ) ;
break;
case 1 :
case 3 :
F_3 ( V_4 , V_10 , V_2 / 2 ) ;
F_3 ( V_4 , V_11 , - V_5 [ 1 ] ) ;
V_5 [ 0 ] = V_2 - V_2 / 2 ;
break;
case 2 :
case 4 :
F_3 ( V_4 , V_10 , V_5 [ 0 ] ) ;
F_3 ( V_4 , V_11 , V_5 [ 1 ] - V_2 ) ;
V_5 [ 1 ] = V_2 / 2 ;
break;
}
F_4 ( V_4 ) ;
if ( ++ V_1 -> V_6 == 5 )
V_1 -> V_6 = 0 ;
}
static void F_5 ( struct V_1 * V_1 , signed char V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
signed char * V_5 = V_1 -> V_5 ;
if ( V_2 & 0x40 )
V_1 -> V_6 = 0 ;
else if ( V_1 -> V_6 == 0 )
return;
switch ( V_1 -> V_6 ) {
case 0 :
V_5 [ 1 ] = V_2 ;
F_2 ( V_4 , V_7 , ( V_2 >> 5 ) & 1 ) ;
F_2 ( V_4 , V_8 , ( V_2 >> 4 ) & 1 ) ;
break;
case 1 :
V_5 [ 2 ] = V_2 ;
V_2 = ( signed char ) ( ( ( V_5 [ 1 ] << 6 ) & 0xc0 ) | ( V_2 & 0x3f ) ) ;
F_3 ( V_4 , V_10 , V_2 / 2 ) ;
F_3 ( V_4 , V_11 , V_5 [ 4 ] ) ;
V_5 [ 3 ] = V_2 - V_2 / 2 ;
break;
case 2 :
if ( ( V_1 -> type == V_12 ) && ! V_2 && ! V_5 [ 2 ] && ! ( ( V_5 [ 0 ] & 0xf0 ) ^ V_5 [ 1 ] ) )
F_2 ( V_4 , V_9 , ! F_6 ( V_9 , V_4 -> V_13 ) ) ;
V_5 [ 0 ] = V_5 [ 1 ] ;
V_2 = ( signed char ) ( ( ( V_5 [ 1 ] << 4 ) & 0xc0 ) | ( V_2 & 0x3f ) ) ;
F_3 ( V_4 , V_10 , V_5 [ 3 ] ) ;
F_3 ( V_4 , V_11 , V_2 - V_5 [ 4 ] ) ;
V_5 [ 4 ] = V_2 / 2 ;
break;
case 3 :
switch ( V_1 -> type ) {
case V_12 :
V_1 -> type = V_14 ;
case V_14 :
if ( ( V_2 >> 2 ) & 3 ) break;
F_2 ( V_4 , V_9 , ( V_2 >> 5 ) & 1 ) ;
F_2 ( V_4 , V_15 , ( V_2 >> 4 ) & 1 ) ;
break;
case V_16 :
case V_17 :
F_2 ( V_4 , V_15 , ( V_2 >> 5 ) & 1 ) ;
case V_18 :
F_2 ( V_4 , V_9 , ( V_2 >> 4 ) & 1 ) ;
F_3 ( V_4 , V_19 , ( V_2 & 8 ) - ( V_2 & 7 ) ) ;
break;
}
break;
case 4 :
case 6 :
V_5 [ 1 ] = ( V_2 >> 2 ) & 0x0f ;
break;
case 5 :
case 7 :
if ( V_1 -> type != V_17 )
break;
switch ( V_5 [ 1 ] ) {
case 1 :
F_2 ( V_4 , V_15 , ( V_2 >> 4 ) & 1 ) ;
F_2 ( V_4 , V_20 , ( V_2 >> 5 ) & 1 ) ;
F_3 ( V_4 , V_2 & 0x80 ? V_21 : V_19 , ( V_2 & 7 ) - ( V_2 & 8 ) ) ;
break;
default:
F_7 ( V_22
L_1 , V_5 [ 1 ] ) ;
break;
}
break;
}
F_4 ( V_4 ) ;
V_1 -> V_6 ++ ;
}
static T_1 F_8 ( struct V_23 * V_23 ,
unsigned char V_2 , unsigned int V_24 )
{
struct V_1 * V_1 = F_9 ( V_23 ) ;
if ( F_10 ( V_25 , V_1 -> V_26 + V_27 / 10 ) )
V_1 -> V_6 = 0 ;
V_1 -> V_26 = V_25 ;
if ( V_1 -> type > V_28 )
F_5 ( V_1 , V_2 ) ;
else
F_1 ( V_1 , V_2 ) ;
return V_29 ;
}
static void F_11 ( struct V_23 * V_23 )
{
struct V_1 * V_1 = F_9 ( V_23 ) ;
F_12 ( V_23 ) ;
F_13 ( V_23 , NULL ) ;
F_14 ( V_1 -> V_4 ) ;
F_15 ( V_1 ) ;
}
static int F_16 ( struct V_23 * V_23 , struct V_30 * V_31 )
{
struct V_1 * V_1 ;
struct V_3 * V_3 ;
unsigned char V_32 = V_23 -> V_33 . V_34 ;
int V_35 = - V_36 ;
V_1 = F_17 ( sizeof( struct V_1 ) , V_37 ) ;
V_3 = F_18 () ;
if ( ! V_1 || ! V_3 )
goto V_38;
V_1 -> V_4 = V_3 ;
snprintf ( V_1 -> V_39 , sizeof( V_1 -> V_39 ) , L_2 , V_23 -> V_39 ) ;
V_1 -> type = V_23 -> V_33 . V_40 ;
V_3 -> V_41 = V_42 [ V_1 -> type ] ;
V_3 -> V_39 = V_1 -> V_39 ;
V_3 -> V_33 . V_43 = V_44 ;
V_3 -> V_33 . V_45 = V_1 -> type ;
V_3 -> V_33 . V_46 = V_32 ;
V_3 -> V_33 . V_47 = 0x0100 ;
V_3 -> V_4 . V_48 = & V_23 -> V_4 ;
V_3 -> V_49 [ 0 ] = F_19 ( V_50 ) | F_19 ( V_51 ) ;
V_3 -> V_52 [ F_20 ( V_53 ) ] = F_19 ( V_7 ) |
F_19 ( V_8 ) ;
V_3 -> V_54 [ 0 ] = F_19 ( V_10 ) | F_19 ( V_11 ) ;
if ( V_32 & 0x01 ) F_21 ( V_9 , V_3 -> V_52 ) ;
if ( V_32 & 0x02 ) F_21 ( V_15 , V_3 -> V_52 ) ;
if ( V_32 & 0x04 ) F_21 ( V_20 , V_3 -> V_52 ) ;
if ( V_32 & 0x10 ) F_21 ( V_19 , V_3 -> V_54 ) ;
if ( V_32 & 0x20 ) F_21 ( V_21 , V_3 -> V_54 ) ;
F_13 ( V_23 , V_1 ) ;
V_35 = F_22 ( V_23 , V_31 ) ;
if ( V_35 )
goto V_55;
V_35 = F_23 ( V_1 -> V_4 ) ;
if ( V_35 )
goto V_56;
return 0 ;
V_56: F_12 ( V_23 ) ;
V_55: F_13 ( V_23 , NULL ) ;
V_38: F_24 ( V_3 ) ;
F_15 ( V_1 ) ;
return V_35 ;
}
