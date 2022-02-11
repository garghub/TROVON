int F_1 ( T_1 * V_1 )
{
char V_2 ;
for( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( * V_1 ++ != 0xFF )
return ( ERROR ) ;
return ( V_4 ) ;
}
int F_2 ( T_1 * V_1 )
{
V_1 += V_5 ;
if ( * V_1 == 0xFF )
return ( V_4 ) ;
if ( ! * V_1 )
return ( ERROR ) ;
if ( F_3 ( * V_1 ) < 7 )
return ( ERROR ) ;
return ( V_4 ) ;
}
int F_4 ( T_1 * V_1 )
{
V_1 += V_6 ;
if ( * V_1 == 0xFF )
return ( V_4 ) ;
if ( ! * V_1 )
{
V_7 = V_8 ;
return ( ERROR ) ;
}
else
V_7 = V_9 ;
if ( F_3 ( * V_1 ) < 5 )
return ( ERROR ) ;
return ( V_4 ) ;
}
int F_5 ( T_1 * V_1 )
{
T_2 V_10 , V_11 ;
V_10 = ( T_2 ) * ( V_1 + V_12 ) * 0x0100 + ( T_2 ) * ( V_1 + V_13 ) ;
V_11 = ( T_2 ) * ( V_1 + V_14 ) * 0x0100 + ( T_2 ) * ( V_1 + V_15 ) ;
if ( V_10 == V_11 )
if ( ( V_10 & 0xF000 ) == 0x1000 )
{ V_16 . V_17 = ( V_10 & 0x0FFF ) / 2 ; return ( V_4 ) ; }
if ( F_6 ( ( T_2 ) ( V_10 ^ V_11 ) ) != 0x01 ) return ( ERROR ) ;
if ( ( V_10 & 0xF000 ) == 0x1000 )
if ( ! ( F_6 ( V_10 ) & 0x01 ) )
{ V_16 . V_17 = ( V_10 & 0x0FFF ) / 2 ; return ( V_4 ) ; }
if ( ( V_11 & 0xF000 ) == 0x1000 )
if ( ! ( F_6 ( V_11 ) & 0x01 ) )
{ V_16 . V_17 = ( V_11 & 0x0FFF ) / 2 ; return ( V_4 ) ; }
return ( ERROR ) ;
}
void F_7 ( T_1 * V_1 )
{
char V_2 ;
for( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
* ( V_1 + V_2 ) = 0xFF ;
}
void F_8 ( T_1 * V_1 )
{
T_2 V_18 ;
* ( V_1 + V_5 ) = 0xFF ;
* ( V_1 + V_6 ) = 0xFF ;
V_18 = V_16 . V_17 * 2 + 0x1000 ;
if ( ( F_6 ( V_18 ) % 2 ) )
V_18 ++ ;
* ( V_1 + V_12 ) = * ( V_1 + V_14 ) = ( T_1 ) ( V_18 / 0x0100 ) ;
* ( V_1 + V_13 ) = * ( V_1 + V_15 ) = ( T_1 ) V_18 ;
}
void F_9 ( T_1 * V_1 )
{
char V_2 ;
for( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
* V_1 ++ = ( T_1 ) ( ( V_2 == V_5 ) ? 0xF0 : 0xFF ) ;
}
void F_10 ( T_1 * V_1 )
{
V_1 += V_6 ;
* V_1 = 0x00 ;
}
void F_11 ( struct V_19 * V_20 )
{
return;
}
int F_12 ( struct V_19 * V_20 , T_1 * V_21 , T_1 * V_1 )
{
T_1 V_22 , V_23 ;
T_2 V_24 ;
V_22 = V_16 . V_25 ; V_24 = V_16 . V_26 ; V_23 = V_16 . V_27 ;
V_16 . V_25 = 0 ;
V_16 . V_26 = V_28 . V_26 ;
V_16 . V_27 = V_28 . V_27 ;
if ( F_13 ( V_20 , V_21 , V_1 ) )
{
V_16 . V_25 = V_22 ; V_16 . V_26 = V_24 ; V_16 . V_27 = V_23 ;
return ( ERROR ) ;
}
V_16 . V_25 = V_22 ; V_16 . V_26 = V_24 ; V_16 . V_27 = V_23 ;
return ( V_4 ) ;
}
int F_13 ( struct V_19 * V_20 , T_1 * V_21 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_36 . V_38 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x200 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF1 ;
V_30 -> V_43 [ 1 ] = 0x02 ;
V_30 -> V_43 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 2 ] = V_16 . V_25 / 2 ;
V_32 = F_17 ( V_20 , V_44 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x10 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF1 ;
V_30 -> V_43 [ 1 ] = 0x03 ;
V_30 -> V_43 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 2 ] = V_16 . V_25 / 2 ;
V_30 -> V_43 [ 8 ] = 0 ;
V_30 -> V_43 [ 9 ] = 1 ;
V_32 = F_17 ( V_20 , V_44 , V_1 , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_18 ( struct V_19 * V_20 , T_2 V_46 , T_1 * V_21 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_36 . V_38 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x200 * V_46 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF1 ;
V_30 -> V_43 [ 1 ] = 0x02 ;
V_30 -> V_43 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 2 ] = V_16 . V_25 / 2 ;
V_32 = F_17 ( V_20 , V_44 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x10 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF1 ;
V_30 -> V_43 [ 1 ] = 0x03 ;
V_30 -> V_43 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 2 ] = V_16 . V_25 / 2 ;
V_30 -> V_43 [ 8 ] = 0 ;
V_30 -> V_43 [ 9 ] = 1 ;
V_32 = F_17 ( V_20 , V_44 , V_1 , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_19 ( struct V_19 * V_20 , T_2 V_46 , T_1 * V_21 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_47 , V_48 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_47 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_49 ;
V_47 = V_47 * ( T_2 ) V_36 . V_38 ;
V_48 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_50 ;
V_48 = V_48 * ( T_2 ) V_36 . V_38 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x200 * V_46 ;
V_30 -> V_42 = 0x00 ;
V_30 -> V_43 [ 0 ] = 0xF0 ;
V_30 -> V_43 [ 1 ] = 0x08 ;
V_30 -> V_43 [ 7 ] = ( T_1 ) V_48 ;
V_30 -> V_43 [ 6 ] = ( T_1 ) ( V_48 / 0x0100 ) ;
V_30 -> V_43 [ 5 ] = V_16 . V_25 / 2 ;
V_30 -> V_43 [ 8 ] = * ( V_1 + V_12 ) ;
V_30 -> V_43 [ 9 ] = * ( V_1 + V_13 ) ;
V_30 -> V_43 [ 10 ] = V_16 . V_27 ;
if ( V_49 != V_51 )
{
V_30 -> V_43 [ 4 ] = ( T_1 ) V_47 ;
V_30 -> V_43 [ 3 ] = ( T_1 ) ( V_47 / 0x0100 ) ;
V_30 -> V_43 [ 2 ] = V_16 . V_25 / 2 ;
}
else
V_30 -> V_43 [ 11 ] = 1 ;
V_32 = F_17 ( V_20 , V_52 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_20 ( struct V_19 * V_20 , T_1 * V_21 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_36 . V_38 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x200 ;
V_30 -> V_42 = 0x00 ;
V_30 -> V_43 [ 0 ] = 0xF0 ;
V_30 -> V_43 [ 1 ] = 0x04 ;
V_30 -> V_43 [ 7 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 6 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 5 ] = V_16 . V_25 / 2 ;
V_30 -> V_43 [ 8 ] = * ( V_1 + V_12 ) ;
V_30 -> V_43 [ 9 ] = * ( V_1 + V_13 ) ;
V_32 = F_17 ( V_20 , V_52 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_21 ( struct V_19 * V_20 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_36 . V_38 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x200 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF2 ;
V_30 -> V_43 [ 1 ] = 0x06 ;
V_30 -> V_43 [ 7 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 6 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 5 ] = V_16 . V_25 / 2 ;
V_32 = F_17 ( V_20 , V_44 , NULL , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_22 ( struct V_19 * V_20 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
T_1 * V_21 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_36 . V_38 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x10 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF1 ;
V_30 -> V_43 [ 1 ] = 0x03 ;
V_30 -> V_43 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 2 ] = V_16 . V_25 / 2 ;
V_30 -> V_43 [ 8 ] = 0 ;
V_30 -> V_43 [ 9 ] = 1 ;
V_21 = F_23 ( 0x10 , V_53 ) ;
V_32 = F_17 ( V_20 , V_44 , V_21 , 0 ) ;
memcpy ( V_1 , V_21 , 0x10 ) ;
F_24 ( V_21 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_25 ( struct V_19 * V_20 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 )
{
F_15 ( L_1 ) ;
return V_35 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_36 . V_37 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_36 . V_38 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_39 = F_16 ( V_40 ) ;
V_30 -> V_41 = 0x10 ;
V_30 -> V_42 = 0x80 ;
V_30 -> V_43 [ 0 ] = 0xF2 ;
V_30 -> V_43 [ 1 ] = 0x05 ;
V_30 -> V_43 [ 7 ] = ( T_1 ) V_18 ;
V_30 -> V_43 [ 6 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_43 [ 5 ] = V_16 . V_25 / 2 ;
V_30 -> V_43 [ 8 ] = * ( V_1 + V_12 ) ;
V_30 -> V_43 [ 9 ] = * ( V_1 + V_13 ) ;
V_32 = F_17 ( V_20 , V_44 , NULL , 0 ) ;
if ( V_32 != V_34 )
return V_35 ;
return V_45 ;
}
int F_26 ( void )
{
return ( V_4 ) ;
}
int F_27 ( T_1 V_54 )
{
switch ( F_28 ( V_54 ) ) {
case V_55 :
V_36 . V_56 = V_55 ;
V_36 . V_57 = V_58 | V_59 | V_60 | V_61 ;
V_36 . V_62 = 1 ;
V_36 . V_37 = 256 ;
V_36 . V_63 = 250 ;
V_36 . V_38 = 8 ;
break;
case V_64 :
V_36 . V_56 = V_64 ;
V_36 . V_57 = V_58 | V_59 | V_60 | V_61 ;
V_36 . V_62 = 1 ;
V_36 . V_37 = 512 ;
V_36 . V_63 = 500 ;
V_36 . V_38 = 8 ;
break;
case V_65 :
V_36 . V_56 = V_65 ;
V_36 . V_57 = V_58 | V_59 | V_60 | V_66 ;
V_36 . V_62 = 1 ;
V_36 . V_37 = 512 ;
V_36 . V_63 = 500 ;
V_36 . V_38 = 16 ;
break;
case V_67 :
V_36 . V_56 = V_67 ;
V_36 . V_57 = V_58 | V_59 | V_60 | V_66 ;
V_36 . V_62 = 1 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 16 ;
break;
case V_68 :
V_36 . V_56 = V_68 ;
V_36 . V_57 = V_58 | V_59 | V_69 | V_66 ;
V_36 . V_62 = 1 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_70 :
V_36 . V_56 = V_70 ;
V_36 . V_57 = V_58 | V_59 | V_69 | V_66 ;
V_36 . V_62 = 2 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_71 :
V_36 . V_56 = V_71 ;
V_36 . V_57 = V_58 | V_72 | V_69 | V_66 ;
V_36 . V_62 = 4 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_73 :
V_36 . V_56 = V_73 ;
V_36 . V_57 = V_58 | V_72 | V_69 | V_66 ;
V_36 . V_62 = 8 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_74 :
V_36 . V_56 = V_74 ;
V_36 . V_57 = V_58 | V_72 | V_69 | V_66 ;
V_36 . V_62 = 16 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_75 :
V_36 . V_56 = V_75 ;
V_36 . V_57 = V_58 | V_72 | V_69 | V_66 ;
V_36 . V_62 = 32 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_76 :
V_36 . V_56 = V_76 ;
V_36 . V_57 = V_58 | V_72 | V_69 | V_66 ;
V_36 . V_62 = 64 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
case V_77 :
V_36 . V_56 = V_77 ;
V_36 . V_57 = V_58 | V_72 | V_69 | V_66 ;
V_36 . V_62 = 128 ;
V_36 . V_37 = 1024 ;
V_36 . V_63 = 1000 ;
V_36 . V_38 = 32 ;
break;
default:
V_36 . V_56 = V_78 ;
return ( ERROR ) ;
}
return ( V_4 ) ;
}
T_1 F_28 ( T_1 V_54 )
{
switch( V_54 ) {
case 0x6E :
case 0xE8 :
case 0xEC : return ( V_55 ) ;
case 0x64 :
case 0xEA : return ( V_64 ) ;
case 0x6B :
case 0xE3 :
case 0xE5 : return ( V_65 ) ;
case 0xE6 : return ( V_67 ) ;
case 0x73 : return ( V_68 ) ;
case 0x75 : return ( V_70 ) ;
case 0x76 : return ( V_71 ) ;
case 0x79 : return ( V_73 ) ;
case 0x71 : return ( V_74 ) ;
case 0xDC : return ( V_75 ) ;
case 0xD3 : return ( V_76 ) ;
case 0xD5 : return ( V_77 ) ;
default: return ( V_78 ) ;
}
}
int F_29 ( T_1 * V_1 )
{
return V_4 ;
}
int F_30 ( T_1 * V_21 , T_1 * V_1 )
{
return V_4 ;
}
int F_31 ( T_1 * V_21 , T_1 * V_1 )
{
T_1 V_79 [] = { 0x01 , 0x03 , 0xD9 , 0x01 , 0xFF , 0x18 , 0x02 ,
0xDF , 0x01 , 0x20 } ;
int V_80 = sizeof( V_79 ) ;
if ( ! V_81 && ! V_82 )
return V_4 ;
if ( ! memcmp ( V_1 + 0x0D , V_83 , 3 ) )
return memcmp ( V_21 , V_79 , V_80 ) ;
if ( ! F_32 ( V_21 , V_1 + 0x0D , V_83 ) )
return memcmp ( V_21 , V_79 , V_80 ) ;
V_21 += 0x100 ;
if ( ! memcmp ( V_1 + 0x08 , V_83 + 0x03 , 3 ) )
return memcmp ( V_21 , V_79 , V_80 ) ;
if ( ! F_32 ( V_21 , V_1 + 0x08 , V_83 + 0x03 ) )
return memcmp ( V_21 , V_79 , V_80 ) ;
return ERROR ;
}
void F_33 ( T_1 * V_1 )
{
return;
}
