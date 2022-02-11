int F_1 ( T_1 * V_1 )
{
char V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( * V_1 ++ != 0xFF )
return ERROR ;
return V_4 ;
}
int F_2 ( T_1 * V_1 )
{
V_1 += V_5 ;
if ( * V_1 == 0xFF )
return V_4 ;
if ( ! * V_1 )
return ERROR ;
if ( F_3 ( * V_1 ) < 7 )
return ERROR ;
return V_4 ;
}
int F_4 ( T_1 * V_1 )
{
V_1 += V_6 ;
if ( * V_1 == 0xFF )
return V_4 ;
if ( ! * V_1 ) {
V_7 = V_8 ;
return ERROR ;
} else
V_7 = V_9 ;
if ( F_3 ( * V_1 ) < 5 )
return ERROR ;
return V_4 ;
}
int F_5 ( T_1 * V_1 )
{
T_2 V_10 , V_11 ;
V_10 = ( T_2 ) * ( V_1 + V_12 ) * 0x0100 +
( T_2 ) * ( V_1 + V_13 ) ;
V_11 = ( T_2 ) * ( V_1 + V_14 ) * 0x0100 +
( T_2 ) * ( V_1 + V_15 ) ;
if ( V_10 == V_11 )
if ( ( V_10 & 0xF000 ) == 0x1000 ) {
V_16 . V_17 = ( V_10 & 0x0FFF ) / 2 ;
return V_4 ;
}
if ( F_6 ( ( T_2 ) ( V_10 ^ V_11 ) ) != 0x01 )
return ERROR ;
if ( ( V_10 & 0xF000 ) == 0x1000 )
if ( ! ( F_6 ( V_10 ) & 0x01 ) ) {
V_16 . V_17 = ( V_10 & 0x0FFF ) / 2 ;
return V_4 ;
}
if ( ( V_11 & 0xF000 ) == 0x1000 )
if ( ! ( F_6 ( V_11 ) & 0x01 ) ) {
V_16 . V_17 = ( V_11 & 0x0FFF ) / 2 ;
return V_4 ;
}
return ERROR ;
}
void F_7 ( T_1 * V_1 )
{
char V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
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
* ( V_1 + V_12 ) = * ( V_1 + V_14 ) =
( T_1 ) ( V_18 / 0x0100 ) ;
* ( V_1 + V_13 ) = * ( V_1 + V_15 ) = ( T_1 ) V_18 ;
}
void F_9 ( T_1 * V_1 )
{
char V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
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
if ( F_13 ( V_20 , V_21 , V_1 ) ) {
V_16 . V_25 = V_22 ;
V_16 . V_26 = V_24 ;
V_16 . V_27 = V_23 ;
return ERROR ;
}
V_16 . V_25 = V_22 ; V_16 . V_26 = V_24 ; V_16 . V_27 = V_23 ;
return V_4 ;
}
int F_13 ( struct V_19 * V_20 , T_1 * V_21 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_38 . V_40 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x200 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF1 ;
V_30 -> V_45 [ 1 ] = 0x02 ;
V_30 -> V_45 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 2 ] = V_16 . V_25 / 2 ;
V_32 = F_17 ( V_20 , V_46 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x10 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF1 ;
V_30 -> V_45 [ 1 ] = 0x03 ;
V_30 -> V_45 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 2 ] = V_16 . V_25 / 2 ;
V_30 -> V_45 [ 8 ] = 0 ;
V_30 -> V_45 [ 9 ] = 1 ;
V_32 = F_17 ( V_20 , V_46 , V_1 , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_18 ( struct V_19 * V_20 , T_2 V_48 , T_1 * V_21 ,
T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_38 . V_40 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x200 * V_48 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF1 ;
V_30 -> V_45 [ 1 ] = 0x02 ;
V_30 -> V_45 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 2 ] = V_16 . V_25 / 2 ;
V_32 = F_17 ( V_20 , V_46 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x10 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF1 ;
V_30 -> V_45 [ 1 ] = 0x03 ;
V_30 -> V_45 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 2 ] = V_16 . V_25 / 2 ;
V_30 -> V_45 [ 8 ] = 0 ;
V_30 -> V_45 [ 9 ] = 1 ;
V_32 = F_17 ( V_20 , V_46 , V_1 , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_19 ( struct V_19 * V_20 , T_2 V_48 , T_1 * V_21 ,
T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_49 , V_50 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_49 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_51 ;
V_49 = V_49 * ( T_2 ) V_38 . V_40 ;
V_50 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_52 ;
V_50 = V_50 * ( T_2 ) V_38 . V_40 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x200 * V_48 ;
V_30 -> V_44 = 0x00 ;
V_30 -> V_45 [ 0 ] = 0xF0 ;
V_30 -> V_45 [ 1 ] = 0x08 ;
V_30 -> V_45 [ 7 ] = ( T_1 ) V_50 ;
V_30 -> V_45 [ 6 ] = ( T_1 ) ( V_50 / 0x0100 ) ;
V_30 -> V_45 [ 5 ] = V_16 . V_25 / 2 ;
V_30 -> V_45 [ 8 ] = * ( V_1 + V_12 ) ;
V_30 -> V_45 [ 9 ] = * ( V_1 + V_13 ) ;
V_30 -> V_45 [ 10 ] = V_16 . V_27 ;
if ( V_51 != V_53 ) {
V_30 -> V_45 [ 4 ] = ( T_1 ) V_49 ;
V_30 -> V_45 [ 3 ] = ( T_1 ) ( V_49 / 0x0100 ) ;
V_30 -> V_45 [ 2 ] = V_16 . V_25 / 2 ;
} else
V_30 -> V_45 [ 11 ] = 1 ;
V_32 = F_17 ( V_20 , V_54 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_20 ( struct V_19 * V_20 , T_1 * V_21 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_38 . V_40 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x200 ;
V_30 -> V_44 = 0x00 ;
V_30 -> V_45 [ 0 ] = 0xF0 ;
V_30 -> V_45 [ 1 ] = 0x04 ;
V_30 -> V_45 [ 7 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 6 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 5 ] = V_16 . V_25 / 2 ;
V_30 -> V_45 [ 8 ] = * ( V_1 + V_12 ) ;
V_30 -> V_45 [ 9 ] = * ( V_1 + V_13 ) ;
V_32 = F_17 ( V_20 , V_54 , V_21 , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_21 ( struct V_19 * V_20 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_38 . V_40 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x200 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF2 ;
V_30 -> V_45 [ 1 ] = 0x06 ;
V_30 -> V_45 [ 7 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 6 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 5 ] = V_16 . V_25 / 2 ;
V_32 = F_17 ( V_20 , V_46 , NULL , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_22 ( struct V_19 * V_20 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
T_1 * V_21 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_38 . V_40 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x10 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF1 ;
V_30 -> V_45 [ 1 ] = 0x03 ;
V_30 -> V_45 [ 4 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 3 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 2 ] = V_16 . V_25 / 2 ;
V_30 -> V_45 [ 8 ] = 0 ;
V_30 -> V_45 [ 9 ] = 1 ;
V_21 = F_23 ( 0x10 , V_55 ) ;
V_32 = F_17 ( V_20 , V_46 , V_21 , 0 ) ;
memcpy ( V_1 , V_21 , 0x10 ) ;
F_24 ( V_21 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_25 ( struct V_19 * V_20 , T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_20 -> V_31 ;
int V_32 ;
T_2 V_18 ;
V_32 = F_14 ( V_20 , V_33 ) ;
if ( V_32 != V_34 ) {
F_15 ( & V_20 -> V_35 -> V_36 ,
L_1 ) ;
return V_37 ;
}
V_18 = ( T_2 ) V_16 . V_25 * V_38 . V_39 + V_16 . V_26 ;
V_18 = V_18 * ( T_2 ) V_38 . V_40 + V_16 . V_27 ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_41 = F_16 ( V_42 ) ;
V_30 -> V_43 = 0x10 ;
V_30 -> V_44 = 0x80 ;
V_30 -> V_45 [ 0 ] = 0xF2 ;
V_30 -> V_45 [ 1 ] = 0x05 ;
V_30 -> V_45 [ 7 ] = ( T_1 ) V_18 ;
V_30 -> V_45 [ 6 ] = ( T_1 ) ( V_18 / 0x0100 ) ;
V_30 -> V_45 [ 5 ] = V_16 . V_25 / 2 ;
V_30 -> V_45 [ 8 ] = * ( V_1 + V_12 ) ;
V_30 -> V_45 [ 9 ] = * ( V_1 + V_13 ) ;
V_32 = F_17 ( V_20 , V_46 , NULL , 0 ) ;
if ( V_32 != V_34 )
return V_37 ;
return V_47 ;
}
int F_26 ( void )
{
return V_4 ;
}
int F_27 ( T_1 V_56 )
{
switch ( F_28 ( V_56 ) ) {
case V_57 :
V_38 . V_58 = V_57 ;
V_38 . V_59 = V_60 | V_61 | V_62 | V_63 ;
V_38 . V_64 = 1 ;
V_38 . V_39 = 256 ;
V_38 . V_65 = 250 ;
V_38 . V_40 = 8 ;
break;
case V_66 :
V_38 . V_58 = V_66 ;
V_38 . V_59 = V_60 | V_61 | V_62 | V_63 ;
V_38 . V_64 = 1 ;
V_38 . V_39 = 512 ;
V_38 . V_65 = 500 ;
V_38 . V_40 = 8 ;
break;
case V_67 :
V_38 . V_58 = V_67 ;
V_38 . V_59 = V_60 | V_61 | V_62 | V_68 ;
V_38 . V_64 = 1 ;
V_38 . V_39 = 512 ;
V_38 . V_65 = 500 ;
V_38 . V_40 = 16 ;
break;
case V_69 :
V_38 . V_58 = V_69 ;
V_38 . V_59 = V_60 | V_61 | V_62 | V_68 ;
V_38 . V_64 = 1 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 16 ;
break;
case V_70 :
V_38 . V_58 = V_70 ;
V_38 . V_59 = V_60 | V_61 | V_71 | V_68 ;
V_38 . V_64 = 1 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_72 :
V_38 . V_58 = V_72 ;
V_38 . V_59 = V_60 | V_61 | V_71 | V_68 ;
V_38 . V_64 = 2 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_73 :
V_38 . V_58 = V_73 ;
V_38 . V_59 = V_60 | V_74 | V_71 | V_68 ;
V_38 . V_64 = 4 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_75 :
V_38 . V_58 = V_75 ;
V_38 . V_59 = V_60 | V_74 | V_71 | V_68 ;
V_38 . V_64 = 8 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_76 :
V_38 . V_58 = V_76 ;
V_38 . V_59 = V_60 | V_74 | V_71 | V_68 ;
V_38 . V_64 = 16 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_77 :
V_38 . V_58 = V_77 ;
V_38 . V_59 = V_60 | V_74 | V_71 | V_68 ;
V_38 . V_64 = 32 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_78 :
V_38 . V_58 = V_78 ;
V_38 . V_59 = V_60 | V_74 | V_71 | V_68 ;
V_38 . V_64 = 64 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
case V_79 :
V_38 . V_58 = V_79 ;
V_38 . V_59 = V_60 | V_74 | V_71 | V_68 ;
V_38 . V_64 = 128 ;
V_38 . V_39 = 1024 ;
V_38 . V_65 = 1000 ;
V_38 . V_40 = 32 ;
break;
default:
V_38 . V_58 = V_80 ;
return ERROR ;
}
return V_4 ;
}
T_1 F_28 ( T_1 V_56 )
{
switch ( V_56 ) {
case 0x6E :
case 0xE8 :
case 0xEC : return V_57 ;
case 0x64 :
case 0xEA : return V_66 ;
case 0x6B :
case 0xE3 :
case 0xE5 : return V_67 ;
case 0xE6 : return V_69 ;
case 0x73 : return V_70 ;
case 0x75 : return V_72 ;
case 0x76 : return V_73 ;
case 0x79 : return V_75 ;
case 0x71 : return V_76 ;
case 0xDC : return V_77 ;
case 0xD3 : return V_78 ;
case 0xD5 : return V_79 ;
default: return V_80 ;
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
T_1 V_81 [] = { 0x01 , 0x03 , 0xD9 , 0x01 , 0xFF , 0x18 , 0x02 ,
0xDF , 0x01 , 0x20 } ;
int V_82 = sizeof( V_81 ) ;
if ( ! V_83 && ! V_84 )
return V_4 ;
if ( ! memcmp ( V_1 + 0x0D , V_85 , 3 ) )
return memcmp ( V_21 , V_81 , V_82 ) ;
if ( ! F_32 ( V_21 , V_1 + 0x0D , V_85 ) )
return memcmp ( V_21 , V_81 , V_82 ) ;
V_21 += 0x100 ;
if ( ! memcmp ( V_1 + 0x08 , V_85 + 0x03 , 3 ) )
return memcmp ( V_21 , V_81 , V_82 ) ;
if ( ! F_32 ( V_21 , V_1 + 0x08 , V_85 + 0x03 ) )
return memcmp ( V_21 , V_81 , V_82 ) ;
return ERROR ;
}
void F_33 ( T_1 * V_1 )
{
return;
}
