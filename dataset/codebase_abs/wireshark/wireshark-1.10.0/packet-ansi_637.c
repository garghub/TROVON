static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_3 * V_4 , T_3 * V_5 , T_4 * V_6 )
{
T_3 V_7 , V_8 , V_9 ;
T_2 V_10 ;
if ( V_3 == 0 )
{
return 0 ;
}
V_7 = V_8 = * V_4 ;
V_9 = * V_5 ;
if ( V_9 == 1 )
{
V_8 = F_2 ( V_1 , * V_2 ) ;
( * V_2 ) ++ ;
}
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
{
if ( V_9 != 1 )
{
V_7 = V_8 ;
if ( ( ( V_10 + 1 ) != V_3 ) ||
( ( V_9 != 7 ) && ( V_9 != 8 ) ) )
{
V_8 = F_2 ( V_1 , * V_2 ) ;
( * V_2 ) ++ ;
}
}
switch ( V_9 )
{
case 1 :
V_6 [ V_10 ] = ( ( V_7 & 0x01 ) << 6 ) | ( ( V_8 & 0xfc ) >> 2 ) ;
break;
case 2 :
V_6 [ V_10 ] = ( ( V_7 & 0x03 ) << 5 ) | ( ( V_8 & 0xf8 ) >> 3 ) ;
break;
case 3 :
V_6 [ V_10 ] = ( ( V_7 & 0x07 ) << 4 ) | ( ( V_8 & 0xf0 ) >> 4 ) ;
break;
case 4 :
V_6 [ V_10 ] = ( ( V_7 & 0x0f ) << 3 ) | ( ( V_8 & 0xe0 ) >> 5 ) ;
break;
case 5 :
V_6 [ V_10 ] = ( ( V_7 & 0x1f ) << 2 ) | ( ( V_8 & 0xc0 ) >> 6 ) ;
break;
case 6 :
V_6 [ V_10 ] = ( ( V_7 & 0x3f ) << 1 ) | ( ( V_8 & 0x80 ) >> 7 ) ;
break;
case 7 :
V_6 [ V_10 ] = V_7 & 0x7f ;
break;
case 8 :
V_6 [ V_10 ] = ( V_7 & 0xfe ) >> 1 ;
break;
}
V_9 = ( V_9 % 8 ) + 1 ;
}
V_6 [ V_10 ] = '\0' ;
* V_5 = V_9 ;
* V_4 = ( V_9 == 1 ) ? V_7 : V_8 ;
return V_10 ;
}
static void
F_3 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_2 V_13 ;
F_4 ( V_12 , 3 ) ;
V_13 = F_5 ( V_1 , V_2 ) ;
F_6 ( V_11 , V_14 ,
V_1 , V_2 , 3 , V_13 ) ;
F_6 ( V_11 , V_15 ,
V_1 , V_2 , 3 , V_13 ) ;
F_6 ( V_11 , V_16 ,
V_1 , V_2 , 3 , V_13 ) ;
}
static void
F_7 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
T_3 V_17 ;
T_3 V_18 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_8 ( V_11 , V_20 , V_1 , V_2 , 1 , V_21 ) ;
V_17 = ( ( V_7 & 0xc0 ) >> 6 ) ;
switch ( V_17 )
{
case 0x00 : V_19 = L_1 ; break;
case 0x01 : V_19 = L_2 ; break;
case 0x02 : V_19 = L_3 ; break;
case 0x03 : V_19 = L_4 ; break;
default: V_19 = L_2 ; break;
}
F_9 ( V_22 , V_7 , 0xc0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_5 ,
V_22 ,
V_19 ) ;
V_18 = ( V_7 & 0x3f ) ;
if ( V_17 == 0x00 ) {
switch ( V_18 )
{
case 0x00 : V_19 = L_6 ; break;
case 0x01 : V_19 = L_7 ; break;
case 0x02 : V_19 = L_8 ; break;
case 0x03 : V_19 = L_9 ; break;
default: V_19 = L_2 ; break;
}
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_10 ,
V_22 ,
V_19 ) ;
}
if ( V_17 == 0x02 ) {
switch ( V_18 )
{
case 0x04 : V_19 = L_11 ; break;
case 0x05 : V_19 = L_12 ; break;
case 0x1f : V_19 = L_13 ; break;
default: V_19 = L_2 ; break;
}
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_10 ,
V_22 ,
V_19 ) ;
}
if ( V_17 == 0x03 ) {
switch ( V_18 )
{
case 0x04 : V_19 = L_11 ; break;
case 0x05 : V_19 = L_12 ; break;
case 0x06 : V_19 = L_14 ; break;
case 0x07 : V_19 = L_15 ; break;
case 0x08 : V_19 = L_16 ; break;
case 0x09 : V_19 = L_17 ; break;
case 0x0a : V_19 = L_18 ; break;
case 0x0d : V_19 = L_19 ; break;
case 0x1f : V_19 = L_13 ; break;
default: V_19 = L_2 ; break;
}
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_10 ,
V_22 ,
V_19 ) ;
}
}
static void
F_11 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 , V_8 ;
T_3 V_23 ;
T_3 V_24 ;
T_3 V_3 ;
T_3 V_25 ;
T_3 V_9 ;
T_2 V_26 ;
T_2 V_27 ;
T_2 V_10 , V_28 ;
const T_4 * V_19 = NULL ;
T_4 * V_29 = NULL ;
T_7 V_30 ;
T_8 * V_31 = NULL ;
F_12 ( V_12 , 2 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
V_8 = 0 ;
V_24 = 0 ;
V_25 = 0 ;
V_23 = ( ( V_7 & 0xf8 ) >> 3 ) ;
switch ( V_23 )
{
case 0x00 : V_19 = L_20 ; break;
case 0x01 : V_19 = L_21 ;
V_8 = F_2 ( V_1 , V_2 + 1 ) ;
V_24 = ( ( V_7 & 0x07 ) << 5 ) | ( ( V_8 & 0xf8 ) >> 3 ) ;
break;
case 0x02 : V_19 = L_22 ; break;
case 0x03 : V_19 = L_23 ; break;
case 0x04 : V_19 = L_24 ; break;
case 0x05 : V_19 = L_25 ; break;
case 0x06 : V_19 = L_26 ; break;
case 0x07 : V_19 = L_27 ; break;
case 0x08 : V_19 = L_28 ; break;
case 0x09 : V_19 = L_29 ; break;
default: V_19 = L_2 ; break;
}
F_9 ( V_22 , V_7 , 0xf8 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_30 ,
V_22 ,
V_19 ) ;
if ( V_23 == 0x01 )
{
F_9 ( V_22 , V_7 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_31 ,
V_22 ,
V_24 ) ;
F_9 ( V_22 , V_8 , 0xf8 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 + 1 , 1 ,
L_32 ,
V_22 ) ;
V_7 = V_8 ;
V_2 ++ ;
V_25 ++ ;
}
V_2 ++ ;
V_25 ++ ;
V_8 = F_2 ( V_1 , V_2 ) ;
V_3 = ( ( V_7 & 0x07 ) << 5 ) | ( ( V_8 & 0xf8 ) >> 3 ) ;
F_9 ( V_22 , V_7 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_33 ,
V_22 ,
V_3 ) ;
F_9 ( V_22 , V_8 , 0xf8 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_34 ,
V_22 ) ;
F_9 ( V_22 , V_8 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_35 ,
V_22 ) ;
V_2 ++ ;
V_25 ++ ;
V_7 = V_8 ;
if ( V_12 <= V_25 ) return;
if ( V_23 == 0x02 )
{
V_10 = ( V_3 * 7 ) - 3 ;
V_26 = ( V_10 / 8 ) + ( ( V_10 % 8 ) ? 1 : 0 ) ;
if ( V_26 + V_25 > V_12 )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_26 + V_25 ) - V_12 ) ;
return;
}
V_9 = 3 ;
V_27 = V_2 ;
F_1 ( V_1 , & V_2 , V_3 , & V_7 , & V_9 , V_22 ) ;
F_13 ( V_11 , V_32 , V_1 , V_27 ,
V_2 - V_27 , V_22 ) ;
switch ( V_9 )
{
case 1 : V_8 = 0x01 ; break;
case 2 : V_8 = 0x03 ; break;
case 3 : V_8 = 0x07 ; break;
case 4 : V_8 = 0x0f ; break;
case 5 : V_8 = 0x1f ; break;
case 6 : V_8 = 0x3f ; break;
case 7 : V_8 = 0x7f ; break;
}
if ( V_9 != 8 )
{
F_9 ( V_22 , V_7 , V_8 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_37 ,
V_22 ) ;
}
}
else if ( V_23 == 0x03 )
{
V_10 = ( V_3 * 7 ) - 3 ;
V_26 = ( V_10 / 8 ) + ( ( V_10 % 8 ) ? 1 : 0 ) ;
if ( V_26 + V_25 > V_12 )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_26 + V_25 ) - V_12 ) ;
return;
}
V_9 = 3 ;
V_27 = V_2 ;
V_28 = F_1 ( V_1 , & V_2 , V_3 , & V_7 , & V_9 , V_22 ) ;
F_14 ( V_33 , V_22 , V_28 ) ;
F_13 ( V_11 , V_32 , V_1 , V_27 ,
V_2 - V_27 , V_33 ) ;
}
else if ( V_23 == 0x07 )
{
V_27 = V_2 - 1 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
{
V_7 = F_2 ( V_1 , V_27 ) ;
V_8 = F_2 ( V_1 , V_27 + 1 ) ;
V_22 [ V_10 ] = ( ( V_7 & 0x07 ) << 5 ) | ( ( V_8 & 0xf8 ) >> 3 ) ;
V_27 ++ ;
}
if ( ( V_30 = F_15 ( L_38 , L_39 ) ) != ( T_7 ) - 1 )
{
V_29 = F_16 ( F_17 ( V_1 , V_2 , V_3 ) , V_3 , V_30 , NULL , NULL , & V_31 ) ;
if( ! V_31 )
{
F_13 ( V_11 , V_32 , V_1 , V_2 ,
V_3 , V_29 ) ;
}
else
{
F_10 ( V_11 , V_1 , V_2 , V_3 , L_40 , L_41 ) ;
}
if( V_29 )
F_18 ( V_29 ) ;
F_19 ( V_30 ) ;
}
}
else if ( V_23 == 0x08 )
{
V_27 = V_2 - 1 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
{
V_7 = F_2 ( V_1 , V_27 ) ;
V_8 = F_2 ( V_1 , V_27 + 1 ) ;
V_22 [ V_10 ] = ( ( V_7 & 0x07 ) << 5 ) | ( ( V_8 & 0xf8 ) >> 3 ) ;
V_27 ++ ;
}
if ( ( V_30 = F_15 ( L_38 , L_42 ) ) != ( T_7 ) - 1 )
{
V_29 = F_16 ( V_22 , V_3 , V_30 , NULL , NULL , & V_31 ) ;
if( ! V_31 )
{
F_13 ( V_11 , V_32 , V_1 , V_2 ,
V_3 , V_29 ) ;
}
else
{
F_10 ( V_11 , V_1 , V_2 , V_3 , L_40 , L_43 ) ;
}
if( V_29 )
F_18 ( V_29 ) ;
F_19 ( V_30 ) ;
}
}
else if ( V_23 == 0x09 )
{
V_10 = ( V_3 * 7 ) - 3 ;
V_26 = ( V_10 / 8 ) + ( ( V_10 % 8 ) ? 1 : 0 ) ;
if ( V_26 + V_25 > V_12 )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_26 + V_25 ) - V_12 ) ;
return;
}
V_27 = V_2 - 1 ;
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ )
{
V_7 = F_2 ( V_1 , V_27 ) ;
V_8 = F_2 ( V_1 , V_27 + 1 ) ;
V_22 [ V_10 ] = ( ( V_7 & 0x07 ) << 5 ) | ( ( V_8 & 0xf8 ) >> 3 ) ;
V_27 ++ ;
}
V_28 = F_20 ( 0 , V_26 + 1 , V_3 , V_22 , V_34 ) ;
V_34 [ V_28 ] = '\0' ;
F_13 ( V_11 , V_32 , V_1 , V_2 ,
V_26 , F_21 ( V_34 , V_3 ) ) ;
}
else
{
F_10 ( V_11 , V_1 , V_2 , V_12 - V_25 ,
L_44 ) ;
}
}
static void
F_22 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_45 ,
V_7 ) ;
}
static void
F_23 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 , V_8 , V_35 ;
F_4 ( V_12 , 6 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
V_8 = F_2 ( V_1 , V_2 + 1 ) ;
V_35 = F_2 ( V_1 , V_2 + 2 ) ;
F_10 ( V_11 , V_1 , V_2 , 3 ,
L_46 ,
( V_7 & 0xf0 ) >> 4 ,
V_7 & 0x0f ,
( V_8 & 0xf0 ) >> 4 ,
V_8 & 0x0f ,
( V_35 & 0xf0 ) >> 4 ,
V_35 & 0x0f ) ;
V_2 += 3 ;
V_7 = F_2 ( V_1 , V_2 ) ;
V_8 = F_2 ( V_1 , V_2 + 1 ) ;
V_35 = F_2 ( V_1 , V_2 + 2 ) ;
F_10 ( V_11 , V_1 , V_2 , 3 ,
L_47 ,
( V_7 & 0xf0 ) >> 4 ,
V_7 & 0x0f ,
( V_8 & 0xf0 ) >> 4 ,
V_8 & 0x0f ,
( V_35 & 0xf0 ) >> 4 ,
V_35 & 0x0f ) ;
}
static void
F_24 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
T_2 V_36 = 0 ;
const T_4 * V_19 = NULL ;
const T_4 * V_37 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( V_7 )
{
case 245 : V_19 = L_48 ; break;
case 246 : V_19 = L_49 ; break;
case 247 : V_19 = L_50 ; break;
case 248 : V_19 = L_51 ; break;
default:
if ( V_7 <= 143 ) { V_36 = ( V_7 + 1 ) * 5 ; V_37 = L_52 ; break; }
else if ( ( V_7 >= 144 ) && ( V_7 <= 167 ) ) { V_36 = ( V_7 - 143 ) * 30 ; V_37 = L_53 ; break; }
else if ( ( V_7 >= 168 ) && ( V_7 <= 196 ) ) { V_36 = V_7 - 166 ; V_37 = L_54 ; break; }
else if ( ( V_7 >= 197 ) && ( V_7 <= 244 ) ) { V_36 = V_7 - 192 ; V_37 = L_55 ; break; }
else { V_19 = L_2 ; break; }
}
if ( V_19 == NULL )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_40 , V_37 ) ;
}
else
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_56 ,
V_36 , V_37 ) ;
}
}
static void
F_25 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
V_19 = F_26 ( ( V_7 & 0xc0 ) >> 6 , V_38 , L_57 ) ;
F_9 ( V_22 , V_7 , 0xc0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_58 ,
V_22 ,
V_19 ) ;
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_27 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( ( V_7 & 0xc0 ) >> 6 )
{
case 0 : V_19 = L_59 ; break;
case 1 : V_19 = L_60 ; break;
case 2 : V_19 = L_61 ; break;
case 3 : V_19 = L_62 ; break;
}
F_9 ( V_22 , V_7 , 0xc0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_58 ,
V_22 ,
V_19 ) ;
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_28 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_22 , V_7 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_63 ,
V_22 ,
( V_7 & 0x80 ) ? L_64 : L_65 ) ;
F_9 ( V_22 , V_7 , 0x40 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_66 ,
V_22 ,
( V_7 & 0x40 ) ? L_67 : L_68 ) ;
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_29 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_69 ,
( V_7 & 0xf0 ) >> 4 ,
V_7 & 0x0f ) ;
}
static void
F_30 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( ( V_7 & 0xc0 ) >> 6 )
{
case 0 : V_19 = L_70 ; break;
case 1 : V_19 = L_71 ; break;
case 2 : V_19 = L_72 ; break;
case 3 : V_19 = L_73 ; break;
}
F_9 ( V_22 , V_7 , 0xc0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_58 ,
V_22 ,
V_19 ) ;
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_31 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( V_7 )
{
case 0x00 : V_19 = L_74 ; break;
case 0x01 : V_19 = L_75 ; break;
case 0x02 : V_19 = L_76 ; break;
case 0x03 : V_19 = L_77 ; break;
case 0x04 : V_19 = L_78 ; break;
case 0x05 : V_19 = L_26 ; break;
case 0x06 : V_19 = L_79 ; break;
case 0x07 : V_19 = L_80 ; break;
default: V_19 = L_2 ; break;
}
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_40 , V_19 ) ;
}
static void
F_32 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 , V_8 , V_3 , V_39 ;
T_2 V_27 ;
T_2 V_26 ;
T_2 V_10 ;
F_12 ( V_12 , 2 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_22 , V_7 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_81 ,
V_22 ,
( V_7 & 0x80 ) ? L_82 : L_83 ) ;
if ( V_7 & 0x80 )
{
F_9 ( V_22 , V_7 , 0x70 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_84 ,
V_22 ,
( V_7 & 0x70 ) >> 4 ) ;
F_9 ( V_22 , V_7 , 0x0f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_85 ,
V_22 ,
V_7 & 0x0f ) ;
V_2 ++ ;
V_3 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_22 , V_7 , 0xff , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_86 ,
V_22 ,
V_3 ) ;
if ( V_3 == 0 ) return;
if ( V_3 > ( V_12 - 2 ) )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_3 + 2 ) - V_12 ) ;
return;
}
V_2 ++ ;
V_10 = 0 ;
while ( V_10 < V_3 )
{
V_22 [ V_10 ] = F_2 ( V_1 , V_2 + V_10 ) & 0x7f ;
V_10 ++ ;
}
V_22 [ V_10 ] = '\0' ;
F_10 ( V_11 , V_1 , V_2 , V_3 ,
L_87 ,
V_22 ) ;
}
else
{
V_2 ++ ;
V_3 = ( V_7 & 0x7f ) << 1 ;
V_8 = F_2 ( V_1 , V_2 ) ;
V_3 |= ( ( V_8 & 0x80 ) >> 7 ) ;
F_9 ( V_22 , V_7 , 0x7f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_88 ,
V_22 ,
V_3 ) ;
F_9 ( V_22 , V_8 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_34 ,
V_22 ) ;
V_7 = V_8 ;
V_39 = FALSE ;
if ( V_3 > 0 )
{
V_10 = ( V_3 - 1 ) * 4 ;
V_26 = ( V_10 / 8 ) + ( ( V_10 % 8 ) ? 1 : 0 ) ;
if ( V_26 + 2 > V_12 )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_26 + 2 ) - V_12 ) ;
return;
}
V_39 = V_3 & 0x01 ;
memset ( ( void * ) V_22 , 0 , sizeof( V_22 ) ) ;
V_27 = V_2 ;
V_2 ++ ;
V_10 = 0 ;
while ( V_10 < V_3 )
{
V_22 [ V_10 ] =
V_40 [ ( V_7 & 0x78 ) >> 3 ] ;
V_10 ++ ;
if ( V_10 >= V_3 ) break;
V_8 = F_2 ( V_1 , V_2 ) ;
V_2 ++ ;
V_22 [ V_10 ] =
V_40 [ ( ( V_7 & 0x07 ) << 1 ) | ( ( V_8 & 0x80 ) >> 7 ) ] ;
V_7 = V_8 ;
V_10 ++ ;
}
F_10 ( V_11 , V_1 , V_27 , V_2 - V_27 ,
L_87 ,
V_22 ) ;
}
F_9 ( V_22 , V_7 , V_39 ? 0x07 : 0x7f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
}
static void
F_33 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 )
{
T_3 V_7 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 1 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( ( V_7 & 0xc0 ) >> 6 )
{
case 0 : V_19 = L_89 ; break;
case 1 : V_19 = L_90 ; break;
case 2 : V_19 = L_91 ; break;
case 3 : V_19 = L_2 ; break;
}
F_9 ( V_22 , V_7 , 0xc0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_58 ,
V_22 ,
V_19 ) ;
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_34 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 , T_4 * V_41 , int V_42 )
{
T_2 V_36 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 2 ) ;
V_36 = F_35 ( V_1 , V_2 ) ;
V_43 = V_36 ;
V_19 = F_36 ( V_36 , V_44 ) ;
if ( NULL == V_19 )
{
switch ( V_36 )
{
case 1 :
V_19 = L_92 ;
break;
case 4102 :
V_19 = L_93 ;
break;
case 4103 :
V_19 = L_94 ;
break;
case 32513 :
V_19 = L_95 ;
break;
case 32514 :
V_19 = L_96 ;
break;
case 32515 :
V_19 = L_97 ;
break;
case 32520 :
V_19 = L_98 ;
break;
case 32584 :
V_19 = L_99 ;
break;
default:
if ( ( V_36 >= 2 ) && ( V_36 <= 4095 ) )
{
V_19 = L_100 ;
}
else if ( ( V_36 >= 4104 ) && ( V_36 <= 4113 ) )
{
V_19 = L_101 ;
}
else if ( ( V_36 >= 4114 ) && ( V_36 <= 32512 ) )
{
V_19 = L_100 ;
}
else if ( ( V_36 >= 32521 ) && ( V_36 <= 32575 ) )
{
V_19 = L_102 ;
}
else if ( ( V_36 >= 49152 ) && ( V_36 <= 65535 ) )
{
V_19 = L_103 ;
}
else
{
V_19 = L_104 ;
}
break;
}
}
F_10 ( V_11 , V_1 , V_2 , 2 ,
L_105 ,
V_19 ,
V_36 ) ;
F_37 ( V_41 , V_42 , L_106 , V_19 , V_36 ) ;
}
static void
F_38 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 , T_4 * V_41 , int V_42 )
{
T_2 V_36 ;
const T_4 * V_19 = NULL ;
F_4 ( V_12 , 2 ) ;
V_36 = F_35 ( V_1 , V_2 ) ;
V_19 = F_26 ( V_36 , V_45 , L_2 ) ;
F_10 ( V_11 , V_1 , V_2 , 2 ,
L_40 , V_19 ) ;
F_37 ( V_41 , V_42 , L_106 , V_19 , V_36 ) ;
}
static void
F_39 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 , T_4 * V_41 V_46 , int V_42 V_46 )
{
T_3 V_7 , V_8 , V_3 , V_39 ;
T_9 V_47 ;
T_2 V_27 ;
T_2 V_26 ;
T_2 V_10 ;
const T_4 * V_19 ;
F_12 ( V_12 , 2 ) ;
V_47 = FALSE ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_22 , V_7 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_81 ,
V_22 ,
( V_7 & 0x80 ) ? L_82 : L_83 ) ;
F_9 ( V_22 , V_7 , 0x40 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_107 ,
V_22 ,
( V_7 & 0x40 ) ? L_108 : L_109 ) ;
if ( V_7 & 0x80 )
{
if ( V_7 & 0x40 )
{
switch ( ( V_7 & 0x38 ) >> 3 )
{
case 0 : V_19 = L_57 ; break;
case 1 : V_19 = L_110 ; break;
case 2 : V_19 = L_111 ; V_47 = TRUE ; break;
default:
V_19 = L_2 ;
break;
}
F_9 ( V_22 , V_7 , 0x38 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_112 ,
V_22 ,
V_19 ,
( V_7 & 0x38 ) >> 3 ) ;
V_2 ++ ;
V_3 = ( V_7 & 0x07 ) << 5 ;
V_8 = F_2 ( V_1 , V_2 ) ;
V_3 |= ( ( V_8 & 0xf8 ) >> 3 ) ;
F_9 ( V_22 , V_7 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_113 ,
V_22 ,
V_3 ) ;
F_9 ( V_22 , V_8 , 0xf8 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_34 ,
V_22 ) ;
if ( V_3 == 0 ) return;
if ( V_3 > ( V_12 - 2 ) )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_3 + 2 ) - V_12 ) ;
return;
}
F_9 ( V_22 , V_8 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_35 ,
V_22 ) ;
V_2 ++ ;
V_7 = V_8 ;
V_10 = 0 ;
while ( V_10 < V_3 )
{
V_22 [ V_10 ] = ( V_7 & 0x07 ) << 5 ;
V_22 [ V_10 ] |= ( ( V_7 = F_2 ( V_1 , V_2 + V_10 ) ) & 0xf8 ) >> 3 ;
V_10 ++ ;
}
V_22 [ V_10 ] = '\0' ;
if ( V_47 )
{
F_10 ( V_11 , V_1 , V_2 , V_3 - 1 ,
L_87 ,
V_22 ) ;
}
else
{
F_40 ( V_11 , V_48 , V_1 , V_2 , V_3 - 1 ,
( T_3 * ) V_22 ) ;
}
V_2 += ( V_3 - 1 ) ;
F_9 ( V_22 , V_7 , 0xf8 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_114 ,
V_22 ) ;
F_9 ( V_22 , V_7 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
else
{
F_9 ( V_22 , V_7 , 0x38 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_84 ,
V_22 ,
( V_7 & 0x38 ) >> 3 ) ;
V_8 = F_2 ( V_1 , V_2 + 1 ) ;
F_9 ( V_22 , V_7 , 0x07 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_115 ,
V_22 ,
( ( V_7 & 0x07 ) << 1 ) | ( ( V_8 & 0x80 ) >> 7 ) ) ;
V_2 ++ ;
V_7 = V_8 ;
F_9 ( V_22 , V_7 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_116 ,
V_22 ) ;
V_2 ++ ;
V_3 = ( V_7 & 0x7f ) << 1 ;
V_8 = F_2 ( V_1 , V_2 ) ;
V_3 |= ( ( V_8 & 0x80 ) >> 7 ) ;
F_9 ( V_22 , V_7 , 0x7f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_113 ,
V_22 ,
V_3 ) ;
F_9 ( V_22 , V_8 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_34 ,
V_22 ) ;
if ( V_3 == 0 ) return;
if ( V_3 > ( V_12 - 3 ) )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_3 + 3 ) - V_12 ) ;
return;
}
F_9 ( V_22 , V_8 , 0x7f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_35 ,
V_22 ) ;
V_2 ++ ;
V_7 = V_8 ;
V_10 = 0 ;
while ( V_10 < V_3 )
{
V_22 [ V_10 ] = ( V_7 & 0x7f ) << 1 ;
V_22 [ V_10 ] |= ( ( V_7 = F_2 ( V_1 , V_2 + V_10 ) ) & 0x80 ) >> 7 ;
V_10 ++ ;
}
V_22 [ V_10 ] = '\0' ;
F_10 ( V_11 , V_1 , V_2 , V_3 - 1 ,
L_87 ,
V_22 ) ;
V_2 += ( V_3 - 1 ) ;
F_9 ( V_22 , V_7 , 0x80 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_117 ,
V_22 ) ;
F_9 ( V_22 , V_7 , 0x7f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
}
else
{
V_2 ++ ;
V_3 = ( V_7 & 0x3f ) << 2 ;
V_8 = F_2 ( V_1 , V_2 ) ;
V_3 |= ( ( V_8 & 0xc0 ) >> 6 ) ;
F_9 ( V_22 , V_7 , 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_113 ,
V_22 ,
V_3 ) ;
F_9 ( V_22 , V_8 , 0xc0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_34 ,
V_22 ) ;
V_7 = V_8 ;
V_39 = FALSE ;
if ( V_3 > 0 )
{
V_10 = ( V_3 - 1 ) * 4 ;
V_26 = ( V_10 / 8 ) + ( ( V_10 % 8 ) ? 1 : 0 ) ;
if ( V_26 + 2 > V_12 )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_26 + 2 ) - V_12 ) ;
return;
}
V_39 = V_3 & 0x01 ;
memset ( ( void * ) V_22 , 0 , sizeof( V_22 ) ) ;
V_27 = V_2 ;
V_2 ++ ;
V_10 = 0 ;
while ( V_10 < V_3 )
{
V_22 [ V_10 ] =
V_40 [ ( V_7 & 0x3c ) >> 2 ] ;
V_10 ++ ;
if ( V_10 >= V_3 ) break;
V_8 = F_2 ( V_1 , V_2 ) ;
V_2 ++ ;
V_22 [ V_10 ] =
V_40 [ ( ( V_7 & 0x03 ) << 2 ) | ( ( V_8 & 0xc0 ) >> 6 ) ] ;
V_7 = V_8 ;
V_10 ++ ;
}
F_10 ( V_11 , V_1 , V_27 , V_2 - V_27 ,
L_87 ,
V_22 ) ;
}
F_9 ( V_22 , V_7 , V_39 ? 0x03 : 0x3f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
}
static void
F_41 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 , T_4 * V_41 V_46 , int V_42 V_46 )
{
T_3 V_7 , V_8 , V_3 ;
T_2 V_10 ;
const T_4 * V_19 ;
F_12 ( V_12 , 2 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( ( V_7 & 0xe0 ) >> 5 )
{
case 0 : V_19 = L_118 ; break;
case 1 : V_19 = L_119 ; break;
default:
V_19 = L_2 ;
break;
}
F_9 ( V_22 , V_7 , 0xe0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_120 ,
V_22 ,
V_19 ) ;
F_9 ( V_22 , V_7 , 0x10 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_121 ,
V_22 ) ;
V_2 ++ ;
V_3 = ( V_7 & 0x0f ) << 4 ;
V_8 = F_2 ( V_1 , V_2 ) ;
V_3 |= ( ( V_8 & 0xf0 ) >> 4 ) ;
F_9 ( V_22 , V_7 , 0x0f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 - 1 , 1 ,
L_113 ,
V_22 ,
V_3 ) ;
F_9 ( V_22 , V_8 , 0xf0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_34 ,
V_22 ) ;
if ( V_3 == 0 ) return;
if ( V_3 > ( V_12 - 2 ) )
{
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_36 ,
( V_3 + 2 ) - V_12 ) ;
return;
}
F_9 ( V_22 , V_8 , 0x0f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_35 ,
V_22 ) ;
V_2 ++ ;
V_7 = V_8 ;
V_10 = 0 ;
while ( V_10 < V_3 )
{
V_22 [ V_10 ] = ( V_7 & 0x0f ) << 4 ;
V_22 [ V_10 ] |= ( ( V_7 = F_2 ( V_1 , V_2 + V_10 ) ) & 0xf0 ) >> 4 ;
V_10 ++ ;
}
V_22 [ V_10 ] = '\0' ;
F_40 ( V_11 , V_48 , V_1 , V_2 , V_3 - 1 ,
( T_3 * ) V_22 ) ;
V_2 += ( V_3 - 1 ) ;
F_9 ( V_22 , V_7 , 0xf0 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_114 ,
V_22 ) ;
F_9 ( V_22 , V_7 , 0x0f , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_42 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 V_46 , T_2 V_2 , T_4 * V_41 , int V_42 )
{
T_3 V_7 ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_22 , V_7 , 0xfc , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_122 ,
V_22 ,
( V_7 & 0xfc ) >> 2 ) ;
F_37 ( V_41 , V_42 , L_123 , ( V_7 & 0xfc ) >> 2 ) ;
F_9 ( V_22 , V_7 , 0x03 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_37 ,
V_22 ) ;
}
static void
F_43 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 , T_4 * V_41 , int V_42 )
{
T_3 V_7 ;
const T_4 * V_19 = NULL ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_22 , V_7 , 0xfc , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_122 ,
V_22 ,
( V_7 & 0xfc ) >> 2 ) ;
switch ( V_7 & 0x03 )
{
case 0x00 : V_19 = L_124 ; break;
case 0x02 : V_19 = L_3 ; break;
case 0x03 : V_19 = L_4 ; break;
default:
V_19 = L_2 ;
break;
}
F_37 ( V_41 , V_42 , L_123 , ( V_7 & 0xfc ) >> 2 ) ;
F_9 ( V_22 , V_7 , 0x03 , 8 ) ;
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_125 ,
V_22 ,
V_19 ) ;
V_2 ++ ;
if ( ! ( V_7 & 0x03 ) ) return;
if ( V_12 == 1 ) return;
V_7 = F_2 ( V_1 , V_2 ) ;
switch ( V_7 )
{
case 0 : V_19 = L_126 ; break;
case 1 : V_19 = L_127 ; break;
case 2 : V_19 = L_128 ; break;
case 3 : V_19 = L_129 ; break;
case 4 : V_19 = L_130 ; break;
case 5 : V_19 = L_131 ; break;
case 6 : V_19 = L_132 ; break;
case 32 : V_19 = L_133 ; break;
case 33 : V_19 = L_134 ; break;
case 34 : V_19 = L_135 ; break;
case 35 : V_19 = L_136 ; break;
case 36 : V_19 = L_137 ; break;
case 37 : V_19 = L_138 ; break;
case 38 : V_19 = L_139 ; break;
case 39 : V_19 = L_140 ; break;
case 64 : V_19 = L_141 ; break;
case 65 : V_19 = L_142 ; break;
case 66 : V_19 = L_143 ; break;
case 67 : V_19 = L_144 ; break;
case 96 : V_19 = L_145 ; break;
case 97 : V_19 = L_146 ; break;
case 98 : V_19 = L_147 ; break;
case 99 : V_19 = L_148 ; break;
case 100 : V_19 = L_149 ; break;
case 101 : V_19 = L_2 ; break;
case 102 : V_19 = L_150 ; break;
case 103 : V_19 = L_151 ; break;
case 104 : V_19 = L_152 ; break;
case 105 : V_19 = L_153 ; break;
case 106 : V_19 = L_154 ; break;
case 107 : V_19 = L_155 ; break;
case 108 : V_19 = L_156 ; break;
default:
if ( ( V_7 >= 7 ) && ( V_7 <= 31 ) ) { V_19 = L_157 ; }
else if ( ( V_7 >= 40 ) && ( V_7 <= 47 ) ) { V_19 = L_158 ; }
else if ( ( V_7 >= 48 ) && ( V_7 <= 63 ) ) { V_19 = L_159 ; }
else if ( ( V_7 >= 68 ) && ( V_7 <= 95 ) ) { V_19 = L_160 ; }
else if ( ( V_7 >= 109 ) && ( V_7 <= 223 ) ) { V_19 = L_161 ; }
else { V_19 = L_162 ; }
break;
}
F_10 ( V_11 , V_1 , V_2 , 1 ,
L_40 , V_19 ) ;
}
static void
F_44 ( T_1 * V_1 , T_5 * V_11 , T_6 V_12 , T_2 V_2 , T_4 * V_41 V_46 , int V_42 V_46 )
{
T_1 * V_49 ;
F_10 ( V_11 , V_1 , V_2 , V_12 ,
L_163 ) ;
V_49 = F_45 ( V_1 , V_2 , V_12 , V_12 ) ;
F_46 ( V_50 , V_43 ,
V_49 , V_51 , V_52 ) ;
}
static T_9
F_47 ( T_1 * V_1 , T_5 * V_11 , T_2 * V_2 )
{
void (* F_48)( T_1 * , T_5 * , T_6 , T_2 ) = NULL ;
T_3 V_7 ;
T_3 V_12 ;
T_2 V_53 ;
T_10 V_54 , V_55 ;
T_5 * V_56 ;
T_11 * V_57 ;
const T_4 * V_19 = NULL ;
V_53 = * V_2 ;
V_7 = F_2 ( V_1 , V_53 ) ;
V_19 = F_49 ( ( T_2 ) V_7 , V_58 , & V_55 ) ;
if ( NULL == V_19 )
{
return ( FALSE ) ;
}
V_54 = V_59 [ V_55 ] ;
F_48 = V_60 [ V_55 ] ;
V_57 =
F_10 ( V_11 , V_1 , V_53 , - 1 , L_40 , V_19 ) ;
V_56 = F_50 ( V_57 , V_54 ) ;
F_6 ( V_56 , V_61 ,
V_1 , V_53 , 1 , V_7 ) ;
V_53 ++ ;
V_12 = F_2 ( V_1 , V_53 ) ;
F_51 ( V_57 , ( V_53 - * V_2 ) + V_12 + 1 ) ;
F_6 ( V_56 , V_62 ,
V_1 , V_53 , 1 , V_12 ) ;
V_53 ++ ;
if ( V_12 > 0 )
{
if ( F_48 == NULL )
{
F_10 ( V_56 , V_1 , V_53 ,
V_12 , L_164 ) ;
}
else
{
(* F_48)( V_1 , V_56 , V_12 , V_53 ) ;
}
V_53 += V_12 ;
}
* V_2 = V_53 ;
return ( TRUE ) ;
}
static void
F_52 ( T_1 * V_1 , T_5 * V_63 )
{
T_3 V_12 ;
T_2 V_53 ;
V_53 = 0 ;
V_12 = F_53 ( V_1 ) ;
while ( ( V_12 - V_53 ) > 0 )
{
if ( ! F_47 ( V_1 , V_63 , & V_53 ) )
{
F_10 ( V_63 , V_1 , V_53 , V_12 - V_53 ,
L_165 ) ;
break;
}
}
}
static void
F_54 ( T_1 * V_1 , T_12 * V_64 , T_5 * V_11 )
{
T_11 * V_65 ;
T_5 * V_63 = NULL ;
const T_4 * V_19 = NULL ;
T_2 V_36 ;
F_55 ( V_64 -> V_66 , V_67 , V_68 ) ;
if ( V_11 )
{
V_36 = V_64 -> V_69 ;
V_19 = F_36 ( V_36 , V_44 ) ;
if ( NULL == V_19 )
{
switch ( V_36 )
{
case 1 :
V_19 = L_92 ;
break;
case 4102 :
V_19 = L_93 ;
break;
case 4103 :
V_19 = L_94 ;
break;
case 32513 :
V_19 = L_95 ;
break;
case 32514 :
V_19 = L_96 ;
break;
case 32515 :
V_19 = L_97 ;
break;
case 32520 :
V_19 = L_98 ;
break;
case 32584 :
V_19 = L_99 ;
break;
default:
if ( ( V_36 >= 2 ) && ( V_36 <= 4095 ) )
{
V_19 = L_100 ;
}
else if ( ( V_36 >= 4104 ) && ( V_36 <= 4113 ) )
{
V_19 = L_101 ;
}
else if ( ( V_36 >= 4114 ) && ( V_36 <= 32512 ) )
{
V_19 = L_100 ;
}
else if ( ( V_36 >= 32521 ) && ( V_36 <= 32575 ) )
{
V_19 = L_102 ;
}
else if ( ( V_36 >= 49152 ) && ( V_36 < 65535 ) )
{
V_19 = L_103 ;
}
else if ( V_36 == 65535 )
{
V_19 = L_166 ;
}
else
{
V_19 = L_104 ;
}
break;
}
}
V_65 =
F_56 ( V_11 , V_70 , V_1 , 0 , - 1 ,
L_167 ,
V_71 ,
V_19 ,
V_64 -> V_69 ) ;
V_63 =
F_50 ( V_65 , V_72 ) ;
F_52 ( V_1 , V_63 ) ;
}
}
static T_9
F_57 ( T_1 * V_1 , T_5 * V_11 , T_2 * V_2 )
{
void (* F_48)( T_1 * , T_5 * , T_6 , T_2 , T_4 * , int ) = NULL ;
T_3 V_7 ;
T_3 V_12 ;
T_2 V_53 ;
T_10 V_54 , V_55 ;
T_5 * V_56 ;
T_11 * V_57 ;
const T_4 * V_19 = NULL ;
V_53 = * V_2 ;
V_7 = F_2 ( V_1 , V_53 ) ;
V_19 = F_49 ( ( T_2 ) V_7 , V_73 , & V_55 ) ;
if ( NULL == V_19 )
{
return ( FALSE ) ;
}
V_54 = V_74 [ V_55 ] ;
F_48 = V_75 [ V_55 ] ;
V_57 =
F_10 ( V_11 , V_1 , V_53 , - 1 , L_40 , V_19 ) ;
V_56 = F_50 ( V_57 , V_54 ) ;
F_6 ( V_56 , V_76 ,
V_1 , V_53 , 1 , V_7 ) ;
V_53 ++ ;
V_12 = F_2 ( V_1 , V_53 ) ;
F_51 ( V_57 , ( V_53 - * V_2 ) + V_12 + 1 ) ;
F_6 ( V_56 , V_77 ,
V_1 , V_53 , 1 , V_12 ) ;
V_53 ++ ;
if ( V_12 > 0 )
{
if ( F_48 == NULL )
{
F_10 ( V_56 , V_1 , V_53 ,
V_12 , L_164 ) ;
}
else
{
T_4 * V_78 ;
V_78 = ( T_4 * ) F_58 ( 1024 ) ;
V_78 [ 0 ] = '\0' ;
(* F_48)( V_1 , V_56 , V_12 , V_53 , V_78 , 1024 ) ;
if ( V_78 [ 0 ] != '\0' )
{
F_59 ( V_57 , L_40 , V_78 ) ;
}
}
V_53 += V_12 ;
}
* V_2 = V_53 ;
return ( TRUE ) ;
}
static void
F_60 ( T_1 * V_1 , T_12 * V_64 , T_5 * V_11 )
{
T_11 * V_65 ;
T_5 * V_63 = NULL ;
T_2 V_53 ;
T_10 V_55 ;
const T_4 * V_19 = NULL ;
T_3 V_7 ;
T_3 V_12 ;
F_55 ( V_64 -> V_66 , V_67 , V_68 ) ;
if ( V_11 )
{
V_51 = V_64 ;
V_52 = V_11 ;
V_43 = 0 ;
V_7 = F_2 ( V_1 , 0 ) ;
V_19 = F_49 ( V_7 , V_79 , & V_55 ) ;
if ( NULL == V_19 )
{
V_65 =
F_56 ( V_11 , V_80 , V_1 , 0 , - 1 ,
L_168 ,
V_81 ,
V_7 ) ;
V_63 =
F_50 ( V_65 , V_82 ) ;
}
else
{
V_65 =
F_56 ( V_11 , V_80 , V_1 , 0 , - 1 ,
L_169 ,
V_81 ,
V_19 ) ;
V_63 =
F_50 ( V_65 , V_83 [ V_55 ] ) ;
if ( V_7 == V_84 )
{
V_43 = 65535 ;
}
}
V_53 = 1 ;
V_12 = F_53 ( V_1 ) ;
while ( ( V_12 - V_53 ) > 0 )
{
if ( ! F_57 ( V_1 , V_63 , & V_53 ) )
{
F_10 ( V_63 , V_1 , V_53 , V_12 - V_53 ,
L_165 ) ;
break;
}
}
}
}
static void
F_61 ( T_1 * V_1 , T_12 * V_64 , T_5 * V_11 )
{
F_55 ( V_64 -> V_66 , V_67 , L_170 ) ;
F_62 ( V_64 -> V_66 , V_85 ) ;
F_60 ( V_1 , V_64 , V_11 ) ;
}
void
F_63 ( void )
{
T_6 V_10 ;
static T_13 V_86 [] =
{
#if 0
{ &hf_ansi_637_trans_msg_type,
{ "Message Type",
"ansi_637_trans.msg_type",
FT_UINT24, BASE_DEC, VALS(ansi_trans_msg_type_strings), 0xf00000,
NULL, HFILL }},
#endif
{ & V_76 ,
{ L_171 , L_172 ,
V_87 , V_88 , F_64 ( V_73 ) , 0 ,
NULL , V_89 } } ,
{ & V_77 ,
{ L_173 , L_174 ,
V_87 , V_88 , NULL , 0 ,
NULL , V_89 } } ,
{ & V_48 ,
{ L_175 , L_176 ,
V_90 , V_91 , 0 , 0 ,
NULL , V_89 } } ,
} ;
static T_13 V_92 [] =
{
{ & V_14 ,
{ L_177 ,
L_178 ,
V_93 , V_88 , F_64 ( V_94 ) , 0xf00000 ,
NULL , V_89 } } ,
{ & V_15 ,
{ L_179 ,
L_180 ,
V_93 , V_88 , NULL , 0x0ffff0 ,
NULL , V_89 } } ,
{ & V_20 ,
{ L_181 ,
L_182 ,
V_87 , V_88 , F_64 ( V_95 ) , 0 ,
NULL , V_89 } } ,
{ & V_16 ,
{ L_2 ,
L_183 ,
V_93 , V_88 , NULL , 0x00000f ,
NULL , V_89 } } ,
{ & V_62 ,
{ L_173 , L_184 ,
V_87 , V_88 , NULL , 0 ,
NULL , V_89 } } ,
{ & V_61 ,
{ L_185 , L_186 ,
V_87 , V_88 , F_64 ( V_58 ) , 0 ,
NULL , V_89 } } ,
{ & V_32 ,
{ L_44 , L_187 ,
V_96 , V_91 , NULL , 0 ,
NULL , V_89 } } ,
} ;
#define F_65 3
T_10 * V_97 [ F_65 + V_98 + V_99 + V_100 ] ;
memset ( ( void * ) V_97 , 0 , sizeof( V_97 ) ) ;
V_97 [ 0 ] = & V_72 ;
V_97 [ 1 ] = & V_82 ;
V_97 [ 2 ] = & V_101 ;
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ )
{
V_59 [ V_10 ] = - 1 ;
V_97 [ F_65 + V_10 ] = & V_59 [ V_10 ] ;
}
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ )
{
V_83 [ V_10 ] = - 1 ;
V_97 [ F_65 + V_98 + V_10 ] = & V_83 [ V_10 ] ;
}
for ( V_10 = 0 ; V_10 < V_100 ; V_10 ++ )
{
V_74 [ V_10 ] = - 1 ;
V_97 [ F_65 + V_98 + V_99 + V_10 ] = & V_74 [ V_10 ] ;
}
V_70 =
F_66 ( V_71 , L_188 , L_189 ) ;
V_80 =
F_66 ( V_81 , L_190 , L_191 ) ;
F_67 ( L_189 , F_54 , V_70 ) ;
F_67 ( L_191 , F_60 , V_80 ) ;
F_68 ( V_70 , V_92 , F_69 ( V_92 ) ) ;
F_68 ( V_80 , V_86 , F_69 ( V_86 ) ) ;
F_70 ( V_97 , F_69 ( V_97 ) ) ;
V_50 =
F_71 ( L_192 ,
L_193 , V_87 , V_88 ) ;
}
void
F_72 ( void )
{
T_14 V_102 ;
T_14 V_103 ;
T_14 V_104 ;
T_6 V_10 ;
V_102 = F_73 ( F_54 , V_70 ) ;
V_103 = F_73 ( F_60 , V_80 ) ;
V_104 = F_73 ( F_61 , V_80 ) ;
F_74 ( L_194 , L_195 , V_104 ) ;
for ( V_10 = 0 ; V_10 < ( ( sizeof( V_44 ) / sizeof( V_105 ) ) - 1 ) ; V_10 ++ )
{
F_75 ( L_196 , V_44 [ V_10 ] . V_36 , V_102 ) ;
F_75 ( L_192 , V_44 [ V_10 ] . V_36 , V_102 ) ;
}
F_75 ( L_197 , 0 , V_103 ) ;
}
