static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
int V_5 ;
if ( V_1 -> V_6 < 2 ) return;
switch ( V_1 -> V_4 [ 0 ] ) {
case 'D' :
if ( V_1 -> V_6 != 15 ) return;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ )
F_2 ( V_3 , V_7 [ V_5 ] ,
( V_8 ) ( ( V_4 [ 2 * V_5 + 3 ] << 8 ) | V_4 [ 2 * V_5 + 2 ] ) ) ;
break;
case 'K' :
if ( V_1 -> V_6 != 3 ) return;
F_3 ( V_3 , V_9 , ( V_4 [ 2 ] & 0x01 ) || ( V_4 [ 2 ] & 0x20 ) ) ;
F_3 ( V_3 , V_10 , V_4 [ 2 ] & 0x02 ) ;
F_3 ( V_3 , V_11 , V_4 [ 2 ] & 0x04 ) ;
F_3 ( V_3 , V_12 , V_4 [ 2 ] & 0x08 ) ;
F_3 ( V_3 , V_13 , V_4 [ 1 ] & 0x01 ) ;
F_3 ( V_3 , V_14 , V_4 [ 1 ] & 0x02 ) ;
F_3 ( V_3 , V_15 , V_4 [ 1 ] & 0x04 ) ;
F_3 ( V_3 , V_16 , V_4 [ 1 ] & 0x10 ) ;
break;
case '.' :
if ( V_1 -> V_6 != 3 ) return;
F_3 ( V_3 , V_9 , V_4 [ 2 ] & 0x01 ) ;
F_3 ( V_3 , V_10 , V_4 [ 2 ] & 0x02 ) ;
F_3 ( V_3 , V_11 , V_4 [ 2 ] & 0x04 ) ;
F_3 ( V_3 , V_12 , V_4 [ 2 ] & 0x08 ) ;
F_3 ( V_3 , V_13 , V_4 [ 2 ] & 0x10 ) ;
F_3 ( V_3 , V_14 , V_4 [ 2 ] & 0x20 ) ;
F_3 ( V_3 , V_15 , V_4 [ 2 ] & 0x80 ) ;
F_3 ( V_3 , V_16 , V_4 [ 1 ] & 0x01 ) ;
F_3 ( V_3 , V_17 , V_4 [ 1 ] & 0x02 ) ;
F_3 ( V_3 , V_18 , V_4 [ 1 ] & 0x04 ) ;
F_3 ( V_3 , V_19 , V_4 [ 1 ] & 0x08 ) ;
F_3 ( V_3 , V_20 , V_4 [ 1 ] & 0x10 ) ;
F_3 ( V_3 , V_21 , V_4 [ 1 ] & 0x20 ) ;
break;
case 'E' :
V_1 -> V_4 [ V_1 -> V_6 - 1 ] = 0 ;
F_4 ( V_22 L_1 , V_1 -> V_4 + 1 ) ;
break;
case '?' :
V_1 -> V_4 [ V_1 -> V_6 - 1 ] = 0 ;
F_4 ( V_22 L_2 , V_1 -> V_4 + 1 ) ;
break;
}
F_5 ( V_3 ) ;
}
static T_1 F_6 ( struct V_23 * V_23 ,
unsigned char V_4 , unsigned int V_24 )
{
struct V_1 * V_1 = F_7 ( V_23 ) ;
switch ( V_4 ) {
case 0xd :
F_1 ( V_1 ) ;
V_1 -> V_6 = 0 ;
V_1 -> V_25 = 0 ;
break;
case '^' :
if ( ! V_1 -> V_25 ) {
V_1 -> V_25 = 1 ;
break;
}
V_1 -> V_25 = 0 ;
case 'M' :
case 'Q' :
case 'S' :
if ( V_1 -> V_25 ) {
V_1 -> V_25 = 0 ;
V_4 &= 0x1f ;
}
default:
if ( V_1 -> V_25 )
V_1 -> V_25 = 0 ;
if ( V_1 -> V_6 < V_26 )
V_1 -> V_4 [ V_1 -> V_6 ++ ] = V_4 ;
break;
}
return V_27 ;
}
static void F_8 ( struct V_23 * V_23 )
{
struct V_1 * V_1 = F_7 ( V_23 ) ;
F_9 ( V_23 ) ;
F_10 ( V_23 , NULL ) ;
F_11 ( V_1 -> V_3 ) ;
F_12 ( V_1 ) ;
}
static int F_13 ( struct V_23 * V_23 , struct V_28 * V_29 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_30 = - V_31 ;
int V_5 , V_32 ;
if ( ( V_32 = V_23 -> V_32 . V_32 ) > V_33 )
return - V_34 ;
V_1 = F_14 ( sizeof( struct V_1 ) , V_35 ) ;
V_2 = F_15 () ;
if ( ! V_1 || ! V_2 )
goto V_36;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , L_3 , V_23 -> V_37 ) ;
V_2 -> V_38 = V_39 [ V_32 ] ;
V_2 -> V_37 = V_1 -> V_37 ;
V_2 -> V_32 . V_40 = V_41 ;
V_2 -> V_32 . V_42 = V_43 ;
V_2 -> V_32 . V_44 = V_32 ;
V_2 -> V_32 . V_45 = 0x0100 ;
V_2 -> V_3 . V_46 = & V_23 -> V_3 ;
V_2 -> V_47 [ 0 ] = F_16 ( V_48 ) | F_16 ( V_49 ) ;
switch ( V_32 ) {
case V_50 :
case V_51 :
V_2 -> V_52 [ F_17 ( V_53 ) ] |= F_16 ( V_17 ) ;
V_2 -> V_52 [ F_17 ( V_18 ) ] |= F_16 ( V_18 ) |
F_16 ( V_19 ) | F_16 ( V_20 ) |
F_16 ( V_21 ) ;
default:
V_2 -> V_52 [ F_17 ( V_53 ) ] |= F_16 ( V_10 ) |
F_16 ( V_11 ) | F_16 ( V_12 ) |
F_16 ( V_13 ) | F_16 ( V_14 ) |
F_16 ( V_15 ) | F_16 ( V_16 ) ;
case V_54 :
V_2 -> V_52 [ F_17 ( V_53 ) ] |= F_16 ( V_9 ) |
F_16 ( V_16 ) ;
}
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
F_18 ( V_2 , V_55 + V_5 , - 8000 , 8000 , 8 , 40 ) ;
F_18 ( V_2 , V_56 + V_5 , - 1600 , 1600 , 2 , 8 ) ;
}
F_10 ( V_23 , V_1 ) ;
V_30 = F_19 ( V_23 , V_29 ) ;
if ( V_30 )
goto V_57;
V_30 = F_20 ( V_1 -> V_3 ) ;
if ( V_30 )
goto V_58;
return 0 ;
V_58: F_9 ( V_23 ) ;
V_57: F_10 ( V_23 , NULL ) ;
V_36: F_21 ( V_2 ) ;
F_12 ( V_1 ) ;
return V_30 ;
}
