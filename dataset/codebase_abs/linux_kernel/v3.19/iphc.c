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
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
bool V_9 ;
T_1 V_30 = 0 , V_31 = 0 ;
V_9 = F_2 ( V_2 , & V_30 , sizeof( V_30 ) ) ;
if ( ( V_30 & V_32 ) == V_33 ) {
F_4 ( L_10 ) ;
switch ( V_30 & V_34 ) {
case V_35 :
V_9 |= F_2 ( V_2 , & V_29 -> V_36 ,
sizeof( V_29 -> V_36 ) ) ;
V_9 |= F_2 ( V_2 , & V_29 -> V_37 ,
sizeof( V_29 -> V_37 ) ) ;
break;
case V_38 :
V_9 |= F_2 ( V_2 , & V_29 -> V_36 ,
sizeof( V_29 -> V_36 ) ) ;
V_9 |= F_2 ( V_2 , & V_31 , sizeof( V_31 ) ) ;
V_29 -> V_37 = F_3 ( V_31 + V_39 ) ;
break;
case V_40 :
V_9 |= F_2 ( V_2 , & V_31 , sizeof( V_31 ) ) ;
V_29 -> V_36 = F_3 ( V_31 + V_39 ) ;
V_9 |= F_2 ( V_2 , & V_29 -> V_37 ,
sizeof( V_29 -> V_37 ) ) ;
break;
case V_34 :
V_9 |= F_2 ( V_2 , & V_31 , sizeof( V_31 ) ) ;
V_29 -> V_36 = F_3 ( V_41 +
( V_31 >> 4 ) ) ;
V_29 -> V_37 = F_3 ( V_41 +
( V_31 & 0x0f ) ) ;
break;
default:
F_4 ( L_11 ) ;
goto V_42;
}
F_4 ( L_12 ,
F_10 ( V_29 -> V_36 ) , F_10 ( V_29 -> V_37 ) ) ;
if ( V_30 & V_43 ) {
F_11 ( L_13 ) ;
goto V_42;
} else {
V_9 |= F_2 ( V_2 , & V_29 -> V_44 ,
sizeof( V_29 -> V_44 ) ) ;
}
V_29 -> V_45 = F_3 ( V_2 -> V_45 + sizeof( struct V_28 ) ) ;
F_4 ( L_14 , F_10 ( V_29 -> V_45 ) ) ;
} else {
F_4 ( L_15 ) ;
goto V_42;
}
if ( V_9 )
goto V_42;
return 0 ;
V_42:
return - V_19 ;
}
int
F_12 ( struct V_1 * V_2 , struct V_46 * V_22 ,
const T_1 * V_47 , const T_1 V_48 ,
const T_1 V_49 , const T_1 * V_50 ,
const T_1 V_51 , const T_1 V_52 ,
T_1 V_53 , T_1 V_54 )
{
struct V_55 V_56 = {} ;
T_1 V_30 , V_57 = 0 ;
int V_42 ;
F_13 ( V_58 , L_16 ,
V_2 -> V_59 , V_2 -> V_45 ) ;
if ( V_54 & V_60 ) {
F_4 ( L_17 ) ;
if ( F_2 ( V_2 , & V_57 , sizeof( V_57 ) ) )
return - V_19 ;
}
V_56 . V_61 = 6 ;
switch ( ( V_53 & V_62 ) >> 3 ) {
case 0 :
if ( F_2 ( V_2 , & V_30 , sizeof( V_30 ) ) )
return - V_19 ;
memcpy ( & V_56 . V_63 , & V_2 -> V_59 [ 0 ] , 3 ) ;
F_14 ( V_2 , 3 ) ;
V_56 . V_64 = ( ( V_30 >> 2 ) & 0x0f ) ;
V_56 . V_63 [ 0 ] = ( ( V_30 >> 2 ) & 0x30 ) | ( V_30 << 6 ) |
( V_56 . V_63 [ 0 ] & 0x0f ) ;
break;
case 2 :
if ( F_2 ( V_2 , & V_30 , sizeof( V_30 ) ) )
return - V_19 ;
V_56 . V_64 = ( ( V_30 >> 2 ) & 0x0f ) ;
V_56 . V_63 [ 0 ] = ( ( V_30 << 6 ) & 0xC0 ) | ( ( V_30 >> 2 ) & 0x30 ) ;
break;
case 1 :
if ( F_2 ( V_2 , & V_30 , sizeof( V_30 ) ) )
return - V_19 ;
V_56 . V_63 [ 0 ] = ( V_2 -> V_59 [ 0 ] & 0x0F ) | ( ( V_30 >> 2 ) & 0x30 ) ;
memcpy ( & V_56 . V_63 [ 1 ] , & V_2 -> V_59 [ 0 ] , 2 ) ;
F_14 ( V_2 , 2 ) ;
break;
case 3 :
break;
default:
break;
}
if ( ( V_53 & V_65 ) == 0 ) {
if ( F_2 ( V_2 , & V_56 . V_66 , sizeof( V_56 . V_66 ) ) )
return - V_19 ;
F_4 ( L_18 ,
V_56 . V_66 ) ;
}
if ( ( V_53 & 0x03 ) != V_67 ) {
V_56 . V_68 = V_69 [ V_53 & 0x03 ] ;
} else {
if ( F_2 ( V_2 , & V_56 . V_68 ,
sizeof( V_56 . V_68 ) ) )
return - V_19 ;
}
V_30 = ( ( V_54 & V_70 ) >> V_71 ) & 0x03 ;
if ( V_54 & V_72 ) {
F_4 ( L_19 ) ;
V_42 = F_6 ( V_2 , & V_56 . V_47 , V_30 ) ;
} else {
F_4 ( L_20 ) ;
V_42 = F_1 ( V_2 , & V_56 . V_47 , V_30 , V_47 ,
V_48 , V_49 ) ;
}
if ( V_42 )
return - V_19 ;
V_30 = ( ( V_54 & V_27 ) >> V_73 ) & 0x03 ;
if ( V_54 & V_74 ) {
if ( V_54 & V_75 ) {
F_4 ( L_21 ) ;
} else {
V_42 = F_8 ( V_2 , & V_56 . V_50 ,
V_30 ) ;
if ( V_42 )
return - V_19 ;
}
} else {
V_42 = F_1 ( V_2 , & V_56 . V_50 , V_30 , V_50 ,
V_51 , V_52 ) ;
F_4 ( L_22 ,
V_30 , & V_56 . V_50 ) ;
if ( V_42 )
return - V_19 ;
}
if ( V_53 & V_65 ) {
struct V_28 V_29 ;
const int V_76 = sizeof( struct V_28 ) + sizeof( V_56 ) ;
if ( F_9 ( V_2 , & V_29 ) )
return - V_19 ;
V_42 = F_15 ( V_2 , V_76 ) ;
if ( F_16 ( V_42 ) )
return V_42 ;
F_17 ( V_2 , sizeof( struct V_28 ) ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , & V_29 , sizeof( struct V_28 ) ) ;
F_13 ( V_58 , L_23 ,
( T_1 * ) & V_29 , sizeof( V_29 ) ) ;
V_56 . V_66 = V_77 ;
} else {
V_42 = F_15 ( V_2 , sizeof( V_56 ) ) ;
if ( F_16 ( V_42 ) )
return V_42 ;
}
V_56 . V_78 = F_3 ( V_2 -> V_45 ) ;
F_4 ( L_24 ,
F_20 ( V_2 ) , V_2 -> V_45 ) ;
F_4 ( L_25
L_26 ,
V_56 . V_61 , F_10 ( V_56 . V_78 ) , V_56 . V_66 ,
V_56 . V_68 , & V_56 . V_50 ) ;
F_17 ( V_2 , sizeof( V_56 ) ) ;
F_21 ( V_2 ) ;
F_19 ( V_2 , & V_56 , sizeof( V_56 ) ) ;
F_13 ( V_58 , L_27 , ( T_1 * ) & V_56 , sizeof( V_56 ) ) ;
return 0 ;
}
static T_1 F_22 ( T_1 * * V_79 , T_1 V_80 ,
const struct V_3 * V_4 ,
const unsigned char * V_6 )
{
T_1 V_31 = 0 ;
if ( F_23 ( V_4 , V_6 ) ) {
V_31 = 3 ;
F_4 ( L_28 ) ;
} else if ( F_24 ( V_4 ) ) {
F_25 ( V_79 , & V_4 -> V_17 [ 7 ] , 2 ) ;
V_31 = 2 ;
F_5 ( NULL , L_29 ,
* V_79 - 2 , 2 ) ;
} else {
F_25 ( V_79 , & V_4 -> V_17 [ 4 ] , 8 ) ;
V_31 = 1 ;
F_5 ( NULL , L_30 ,
* V_79 - 8 , 8 ) ;
}
return F_26 ( V_31 , V_80 ) ;
}
static void F_27 ( T_1 * * V_79 , struct V_1 * V_2 )
{
struct V_28 * V_29 ;
T_1 V_30 ;
if ( V_2 -> V_81 == V_2 -> V_82 )
F_28 ( V_2 , sizeof( struct V_55 ) ) ;
V_29 = F_29 ( V_2 ) ;
if ( ( ( F_10 ( V_29 -> V_36 ) & V_83 ) ==
V_41 ) &&
( ( F_10 ( V_29 -> V_37 ) & V_83 ) ==
V_41 ) ) {
F_4 ( L_31 ) ;
V_30 = V_34 ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
V_30 = F_10 ( V_29 -> V_37 ) - V_41 +
( ( F_10 ( V_29 -> V_36 ) - V_41 ) << 4 ) ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
} else if ( ( F_10 ( V_29 -> V_37 ) & V_84 ) ==
V_39 ) {
F_4 ( L_32 ) ;
V_30 = V_38 ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
F_25 ( V_79 , & V_29 -> V_36 , sizeof( V_29 -> V_36 ) ) ;
V_30 = F_10 ( V_29 -> V_37 ) - V_39 ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
} else if ( ( F_10 ( V_29 -> V_36 ) & V_84 ) ==
V_39 ) {
F_4 ( L_33 ) ;
V_30 = V_40 ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
V_30 = F_10 ( V_29 -> V_36 ) - V_39 ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
F_25 ( V_79 , & V_29 -> V_37 , sizeof( V_29 -> V_37 ) ) ;
} else {
F_4 ( L_34 ) ;
V_30 = V_35 ;
F_25 ( V_79 , & V_30 , sizeof( V_30 ) ) ;
F_25 ( V_79 , & V_29 -> V_36 , sizeof( V_29 -> V_36 ) ) ;
F_25 ( V_79 , & V_29 -> V_37 , sizeof( V_29 -> V_37 ) ) ;
}
F_25 ( V_79 , & V_29 -> V_44 , sizeof( V_29 -> V_44 ) ) ;
F_14 ( V_2 , sizeof( struct V_28 ) ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_46 * V_22 ,
unsigned short type , const void * V_85 ,
const void * V_86 , unsigned int V_45 )
{
T_1 V_30 , V_53 , V_54 , * V_79 ;
struct V_55 * V_56 ;
T_1 V_87 [ 100 ] = {} ;
int V_7 ;
if ( type != V_88 )
return - V_19 ;
V_56 = F_31 ( V_2 ) ;
V_79 = V_87 + 2 ;
F_4 ( L_35
L_36 ,
V_56 -> V_61 , F_10 ( V_56 -> V_78 ) , V_56 -> V_66 ,
V_56 -> V_68 , & V_56 -> V_50 ) ;
F_13 ( V_58 , L_37 ,
F_32 ( V_2 ) , sizeof( struct V_55 ) ) ;
V_53 = V_89 ;
V_54 = 0 ;
F_5 ( V_58 , L_38 ,
( unsigned char * ) V_86 , V_90 ) ;
F_5 ( V_58 , L_39 ,
( unsigned char * ) V_85 , V_90 ) ;
F_13 ( V_58 , L_40 ,
V_2 -> V_59 , V_2 -> V_45 ) ;
V_30 = ( V_56 -> V_64 << 4 ) | ( V_56 -> V_63 [ 0 ] >> 4 ) ;
V_30 = ( ( V_30 & 0x03 ) << 6 ) | ( V_30 >> 2 ) ;
if ( ( ( V_56 -> V_63 [ 0 ] & 0x0F ) == 0 ) &&
( V_56 -> V_63 [ 1 ] == 0 ) && ( V_56 -> V_63 [ 2 ] == 0 ) ) {
V_53 |= V_91 ;
if ( ( V_56 -> V_64 == 0 ) &&
( ( V_56 -> V_63 [ 0 ] & 0xF0 ) == 0 ) ) {
V_53 |= V_92 ;
} else {
* V_79 = V_30 ;
V_79 += 1 ;
}
} else {
if ( ( V_56 -> V_64 == 0 ) &&
( ( V_56 -> V_63 [ 0 ] & 0xF0 ) == 0 ) ) {
V_53 |= V_92 ;
* V_79 = ( V_30 & 0xc0 ) | ( V_56 -> V_63 [ 0 ] & 0x0F ) ;
memcpy ( V_79 + 1 , & V_56 -> V_63 [ 1 ] , 2 ) ;
V_79 += 3 ;
} else {
memcpy ( V_79 , V_56 , 4 ) ;
* V_79 = V_30 ;
V_79 += 4 ;
}
}
if ( V_56 -> V_66 == V_77 )
V_53 |= V_65 ;
if ( ( V_53 & V_65 ) == 0 )
F_25 ( & V_79 , & V_56 -> V_66 ,
sizeof( V_56 -> V_66 ) ) ;
switch ( V_56 -> V_68 ) {
case 1 :
V_53 |= V_93 ;
break;
case 64 :
V_53 |= V_94 ;
break;
case 255 :
V_53 |= V_95 ;
break;
default:
F_25 ( & V_79 , & V_56 -> V_68 ,
sizeof( V_56 -> V_68 ) ) ;
}
V_7 = F_33 ( & V_56 -> V_47 ) ;
if ( V_7 == V_96 ) {
F_4 ( L_41 ) ;
V_54 |= V_72 ;
} else {
if ( V_7 & V_97 ) {
V_54 |= F_22 ( & V_79 ,
V_71 ,
& V_56 -> V_47 , V_86 ) ;
F_4 ( L_42 ,
& V_56 -> V_47 , V_54 ) ;
} else {
F_4 ( L_43 ) ;
F_25 ( & V_79 , V_56 -> V_47 . V_11 , 16 ) ;
}
}
V_7 = F_33 ( & V_56 -> V_50 ) ;
if ( V_7 & V_98 ) {
F_4 ( L_44 ) ;
V_54 |= V_74 ;
if ( F_34 ( & V_56 -> V_50 ) ) {
F_4 ( L_45 ) ;
V_54 |= V_27 ;
F_25 ( & V_79 ,
& V_56 -> V_50 . V_11 [ 15 ] , 1 ) ;
} else if ( F_35 ( & V_56 -> V_50 ) ) {
F_4 ( L_46 ) ;
V_54 |= V_26 ;
F_25 ( & V_79 ,
& V_56 -> V_50 . V_11 [ 1 ] , 1 ) ;
F_25 ( & V_79 ,
& V_56 -> V_50 . V_11 [ 13 ] , 3 ) ;
} else if ( F_36 ( & V_56 -> V_50 ) ) {
F_4 ( L_47 ) ;
V_54 |= V_25 ;
F_25 ( & V_79 ,
& V_56 -> V_50 . V_11 [ 1 ] , 1 ) ;
F_25 ( & V_79 ,
& V_56 -> V_50 . V_11 [ 11 ] , 5 ) ;
} else {
F_4 ( L_48 ) ;
V_54 |= V_24 ;
F_25 ( & V_79 , V_56 -> V_50 . V_11 , 16 ) ;
}
} else {
if ( V_7 & V_97 ) {
V_54 |= F_22 ( & V_79 ,
V_73 , & V_56 -> V_50 , V_85 ) ;
F_4 ( L_49
L_50 , & V_56 -> V_50 , V_54 ) ;
} else {
F_4 ( L_51 , & V_56 -> V_50 ) ;
F_25 ( & V_79 , V_56 -> V_50 . V_11 , 16 ) ;
}
}
if ( V_56 -> V_66 == V_77 )
F_27 ( & V_79 , V_2 ) ;
V_87 [ 0 ] = V_53 ;
V_87 [ 1 ] = V_54 ;
F_14 ( V_2 , sizeof( struct V_55 ) ) ;
F_18 ( V_2 ) ;
memcpy ( F_17 ( V_2 , V_79 - V_87 ) , V_87 , V_79 - V_87 ) ;
F_21 ( V_2 ) ;
F_4 ( L_52 , ( int ) ( V_79 - V_87 ) , V_2 -> V_45 ) ;
F_13 ( V_58 , L_53 ,
V_2 -> V_59 , V_2 -> V_45 ) ;
return 0 ;
}
