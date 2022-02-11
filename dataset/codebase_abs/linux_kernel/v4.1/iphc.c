static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const T_1 V_5 ,
const T_1 * V_6 , const T_1 V_7 ,
const T_1 V_8 )
{
bool V_9 ;
switch ( V_5 ) {
case V_10 :
V_9 = F_2 ( V_2 , V_4 -> V_11 , 16 ) ;
break;
case V_12 :
V_4 -> V_11 [ 0 ] = 0xFE ;
V_4 -> V_11 [ 1 ] = 0x80 ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 8 ] , 8 ) ;
break;
case V_13 :
V_4 -> V_11 [ 0 ] = 0xFE ;
V_4 -> V_11 [ 1 ] = 0x80 ;
V_4 -> V_11 [ 11 ] = 0xFF ;
V_4 -> V_11 [ 12 ] = 0xFE ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 14 ] , 2 ) ;
break;
case V_14 :
V_9 = false ;
switch ( V_7 ) {
case V_15 :
V_4 -> V_11 [ 0 ] = 0xFE ;
V_4 -> V_11 [ 1 ] = 0x80 ;
memcpy ( & V_4 -> V_11 [ 8 ] , V_6 , V_8 ) ;
V_4 -> V_11 [ 8 ] ^= 0x02 ;
break;
case V_16 :
V_4 -> V_11 [ 0 ] = 0xFE ;
V_4 -> V_11 [ 1 ] = 0x80 ;
V_4 -> V_11 [ 11 ] = 0xFF ;
V_4 -> V_11 [ 12 ] = 0xFE ;
V_4 -> V_17 [ 7 ] = F_3 ( * ( ( V_18 * ) V_6 ) ) ;
break;
default:
F_4 ( L_1 ) ;
return - V_19 ;
}
break;
default:
F_4 ( L_2 , V_5 ) ;
return - V_19 ;
}
if ( V_9 ) {
F_4 ( L_3 ) ;
return - V_20 ;
}
F_5 ( NULL , L_4 ,
V_4 -> V_11 , 16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const T_1 V_21 )
{
switch ( V_21 ) {
case V_10 :
break;
case V_12 :
case V_13 :
case V_14 :
F_7 ( V_2 -> V_22 , L_5 , V_21 ) ;
return - V_19 ;
default:
F_4 ( L_6 , V_21 ) ;
return - V_19 ;
}
F_5 ( NULL ,
L_7 ,
V_4 -> V_11 , 16 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const T_1 V_23 )
{
bool V_9 ;
switch ( V_23 ) {
case V_24 :
V_9 = F_2 ( V_2 , V_4 -> V_11 , 16 ) ;
break;
case V_25 :
V_4 -> V_11 [ 0 ] = 0xFF ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 1 ] , 1 ) ;
V_9 |= F_2 ( V_2 , & V_4 -> V_11 [ 11 ] , 5 ) ;
break;
case V_26 :
V_4 -> V_11 [ 0 ] = 0xFF ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 1 ] , 1 ) ;
V_9 |= F_2 ( V_2 , & V_4 -> V_11 [ 13 ] , 3 ) ;
break;
case V_27 :
V_4 -> V_11 [ 0 ] = 0xFF ;
V_4 -> V_11 [ 1 ] = 0x02 ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 15 ] , 1 ) ;
break;
default:
F_4 ( L_8 , V_23 ) ;
return - V_19 ;
}
if ( V_9 ) {
F_4 ( L_3 ) ;
return - V_20 ;
}
F_5 ( NULL , L_9 ,
V_4 -> V_11 , 16 ) ;
return 0 ;
}
int
F_9 ( struct V_1 * V_2 , struct V_28 * V_22 ,
const T_1 * V_29 , const T_1 V_30 ,
const T_1 V_31 , const T_1 * V_32 ,
const T_1 V_33 , const T_1 V_34 ,
T_1 V_35 , T_1 V_36 )
{
struct V_37 V_38 = {} ;
T_1 V_39 , V_40 = 0 ;
int V_41 ;
F_10 ( V_42 , L_10 ,
V_2 -> V_43 , V_2 -> V_44 ) ;
if ( V_36 & V_45 ) {
F_4 ( L_11 ) ;
if ( F_2 ( V_2 , & V_40 , sizeof( V_40 ) ) )
return - V_19 ;
}
V_38 . V_46 = 6 ;
switch ( ( V_35 & V_47 ) >> 3 ) {
case 0 :
if ( F_2 ( V_2 , & V_39 , sizeof( V_39 ) ) )
return - V_19 ;
memcpy ( & V_38 . V_48 , & V_2 -> V_43 [ 0 ] , 3 ) ;
F_11 ( V_2 , 3 ) ;
V_38 . V_49 = ( ( V_39 >> 2 ) & 0x0f ) ;
V_38 . V_48 [ 0 ] = ( ( V_39 >> 2 ) & 0x30 ) | ( V_39 << 6 ) |
( V_38 . V_48 [ 0 ] & 0x0f ) ;
break;
case 2 :
if ( F_2 ( V_2 , & V_39 , sizeof( V_39 ) ) )
return - V_19 ;
V_38 . V_49 = ( ( V_39 >> 2 ) & 0x0f ) ;
V_38 . V_48 [ 0 ] = ( ( V_39 << 6 ) & 0xC0 ) | ( ( V_39 >> 2 ) & 0x30 ) ;
break;
case 1 :
if ( F_2 ( V_2 , & V_39 , sizeof( V_39 ) ) )
return - V_19 ;
V_38 . V_48 [ 0 ] = ( V_2 -> V_43 [ 0 ] & 0x0F ) | ( ( V_39 >> 2 ) & 0x30 ) ;
memcpy ( & V_38 . V_48 [ 1 ] , & V_2 -> V_43 [ 0 ] , 2 ) ;
F_11 ( V_2 , 2 ) ;
break;
case 3 :
break;
default:
break;
}
if ( ( V_35 & V_50 ) == 0 ) {
if ( F_2 ( V_2 , & V_38 . V_51 , sizeof( V_38 . V_51 ) ) )
return - V_19 ;
F_4 ( L_12 ,
V_38 . V_51 ) ;
}
if ( ( V_35 & 0x03 ) != V_52 ) {
V_38 . V_53 = V_54 [ V_35 & 0x03 ] ;
} else {
if ( F_2 ( V_2 , & V_38 . V_53 ,
sizeof( V_38 . V_53 ) ) )
return - V_19 ;
}
V_39 = ( ( V_36 & V_55 ) >> V_56 ) & 0x03 ;
if ( V_36 & V_57 ) {
F_4 ( L_13 ) ;
V_41 = F_6 ( V_2 , & V_38 . V_29 , V_39 ) ;
} else {
F_4 ( L_14 ) ;
V_41 = F_1 ( V_2 , & V_38 . V_29 , V_39 , V_29 ,
V_30 , V_31 ) ;
}
if ( V_41 )
return - V_19 ;
V_39 = ( ( V_36 & V_27 ) >> V_58 ) & 0x03 ;
if ( V_36 & V_59 ) {
if ( V_36 & V_60 ) {
F_4 ( L_15 ) ;
} else {
V_41 = F_8 ( V_2 , & V_38 . V_32 ,
V_39 ) ;
if ( V_41 )
return - V_19 ;
}
} else {
V_41 = F_1 ( V_2 , & V_38 . V_32 , V_39 , V_32 ,
V_33 , V_34 ) ;
F_4 ( L_16 ,
V_39 , & V_38 . V_32 ) ;
if ( V_41 )
return - V_19 ;
}
if ( V_35 & V_50 ) {
V_41 = F_12 ( V_2 , V_22 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
} else {
V_41 = F_13 ( V_2 , sizeof( V_38 ) ) ;
if ( F_14 ( V_41 ) )
return V_41 ;
}
V_38 . V_61 = F_3 ( V_2 -> V_44 ) ;
F_4 ( L_17 ,
F_15 ( V_2 ) , V_2 -> V_44 ) ;
F_4 ( L_18
L_19 ,
V_38 . V_46 , F_16 ( V_38 . V_61 ) , V_38 . V_51 ,
V_38 . V_53 , & V_38 . V_32 ) ;
F_17 ( V_2 , sizeof( V_38 ) ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , & V_38 , sizeof( V_38 ) ) ;
F_10 ( V_42 , L_20 , ( T_1 * ) & V_38 , sizeof( V_38 ) ) ;
return 0 ;
}
static T_1 F_20 ( T_1 * * V_62 , T_1 V_63 ,
const struct V_3 * V_4 ,
const unsigned char * V_6 )
{
T_1 V_64 = 0 ;
if ( F_21 ( V_4 , V_6 ) ) {
V_64 = 3 ;
F_4 ( L_21 ) ;
} else if ( F_22 ( V_4 ) ) {
F_23 ( V_62 , & V_4 -> V_17 [ 7 ] , 2 ) ;
V_64 = 2 ;
F_5 ( NULL , L_22 ,
* V_62 - 2 , 2 ) ;
} else {
F_23 ( V_62 , & V_4 -> V_17 [ 4 ] , 8 ) ;
V_64 = 1 ;
F_5 ( NULL , L_23 ,
* V_62 - 8 , 8 ) ;
}
return F_24 ( V_64 , V_63 ) ;
}
int F_25 ( struct V_1 * V_2 , struct V_28 * V_22 ,
unsigned short type , const void * V_65 ,
const void * V_66 , unsigned int V_44 )
{
T_1 V_39 , V_35 , V_36 , * V_62 ;
struct V_37 * V_38 ;
T_1 V_67 [ 100 ] = {} ;
int V_68 , V_7 ;
if ( type != V_69 )
return - V_19 ;
V_38 = F_26 ( V_2 ) ;
V_62 = V_67 + 2 ;
F_4 ( L_24
L_25 ,
V_38 -> V_46 , F_16 ( V_38 -> V_61 ) , V_38 -> V_51 ,
V_38 -> V_53 , & V_38 -> V_32 ) ;
F_10 ( V_42 , L_26 ,
F_27 ( V_2 ) , sizeof( struct V_37 ) ) ;
V_35 = V_70 ;
V_36 = 0 ;
F_5 ( V_42 , L_27 ,
( unsigned char * ) V_66 , V_71 ) ;
F_5 ( V_42 , L_28 ,
( unsigned char * ) V_65 , V_71 ) ;
F_10 ( V_42 , L_29 ,
V_2 -> V_43 , V_2 -> V_44 ) ;
V_39 = ( V_38 -> V_49 << 4 ) | ( V_38 -> V_48 [ 0 ] >> 4 ) ;
V_39 = ( ( V_39 & 0x03 ) << 6 ) | ( V_39 >> 2 ) ;
if ( ( ( V_38 -> V_48 [ 0 ] & 0x0F ) == 0 ) &&
( V_38 -> V_48 [ 1 ] == 0 ) && ( V_38 -> V_48 [ 2 ] == 0 ) ) {
V_35 |= V_72 ;
if ( ( V_38 -> V_49 == 0 ) &&
( ( V_38 -> V_48 [ 0 ] & 0xF0 ) == 0 ) ) {
V_35 |= V_73 ;
} else {
* V_62 = V_39 ;
V_62 += 1 ;
}
} else {
if ( ( V_38 -> V_49 == 0 ) &&
( ( V_38 -> V_48 [ 0 ] & 0xF0 ) == 0 ) ) {
V_35 |= V_73 ;
* V_62 = ( V_39 & 0xc0 ) | ( V_38 -> V_48 [ 0 ] & 0x0F ) ;
memcpy ( V_62 + 1 , & V_38 -> V_48 [ 1 ] , 2 ) ;
V_62 += 3 ;
} else {
memcpy ( V_62 , V_38 , 4 ) ;
* V_62 = V_39 ;
V_62 += 4 ;
}
}
V_68 = F_28 ( V_2 , V_38 , & V_62 , & V_35 ) ;
if ( V_68 < 0 )
return V_68 ;
switch ( V_38 -> V_53 ) {
case 1 :
V_35 |= V_74 ;
break;
case 64 :
V_35 |= V_75 ;
break;
case 255 :
V_35 |= V_76 ;
break;
default:
F_23 ( & V_62 , & V_38 -> V_53 ,
sizeof( V_38 -> V_53 ) ) ;
}
V_7 = F_29 ( & V_38 -> V_29 ) ;
if ( V_7 == V_77 ) {
F_4 ( L_30 ) ;
V_36 |= V_57 ;
} else {
if ( V_7 & V_78 ) {
V_36 |= F_20 ( & V_62 ,
V_56 ,
& V_38 -> V_29 , V_66 ) ;
F_4 ( L_31 ,
& V_38 -> V_29 , V_36 ) ;
} else {
F_4 ( L_32 ) ;
F_23 ( & V_62 , V_38 -> V_29 . V_11 , 16 ) ;
}
}
V_7 = F_29 ( & V_38 -> V_32 ) ;
if ( V_7 & V_79 ) {
F_4 ( L_33 ) ;
V_36 |= V_59 ;
if ( F_30 ( & V_38 -> V_32 ) ) {
F_4 ( L_34 ) ;
V_36 |= V_27 ;
F_23 ( & V_62 ,
& V_38 -> V_32 . V_11 [ 15 ] , 1 ) ;
} else if ( F_31 ( & V_38 -> V_32 ) ) {
F_4 ( L_35 ) ;
V_36 |= V_26 ;
F_23 ( & V_62 ,
& V_38 -> V_32 . V_11 [ 1 ] , 1 ) ;
F_23 ( & V_62 ,
& V_38 -> V_32 . V_11 [ 13 ] , 3 ) ;
} else if ( F_32 ( & V_38 -> V_32 ) ) {
F_4 ( L_36 ) ;
V_36 |= V_25 ;
F_23 ( & V_62 ,
& V_38 -> V_32 . V_11 [ 1 ] , 1 ) ;
F_23 ( & V_62 ,
& V_38 -> V_32 . V_11 [ 11 ] , 5 ) ;
} else {
F_4 ( L_37 ) ;
V_36 |= V_24 ;
F_23 ( & V_62 , V_38 -> V_32 . V_11 , 16 ) ;
}
} else {
if ( V_7 & V_78 ) {
V_36 |= F_20 ( & V_62 ,
V_58 , & V_38 -> V_32 , V_65 ) ;
F_4 ( L_38
L_39 , & V_38 -> V_32 , V_36 ) ;
} else {
F_4 ( L_40 , & V_38 -> V_32 ) ;
F_23 ( & V_62 , V_38 -> V_32 . V_11 , 16 ) ;
}
}
if ( V_35 & V_50 ) {
V_68 = F_33 ( V_2 , V_38 , & V_62 ) ;
if ( V_68 < 0 )
return V_68 ;
}
V_67 [ 0 ] = V_35 ;
V_67 [ 1 ] = V_36 ;
F_11 ( V_2 , sizeof( struct V_37 ) ) ;
F_34 ( V_2 ) ;
memcpy ( F_17 ( V_2 , V_62 - V_67 ) , V_67 , V_62 - V_67 ) ;
F_18 ( V_2 ) ;
F_4 ( L_41 , ( int ) ( V_62 - V_67 ) , V_2 -> V_44 ) ;
F_10 ( V_42 , L_42 ,
V_2 -> V_43 , V_2 -> V_44 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
F_36 ( L_43 ) ;
F_36 ( L_44 ) ;
F_36 ( L_45 ) ;
F_36 ( L_46 ) ;
F_36 ( L_47 ) ;
F_36 ( L_48 ) ;
F_36 ( L_49 ) ;
return 0 ;
}
