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
static int F_8 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_22 , T_2 V_26 )
{
struct V_1 * V_27 ;
int V_28 ;
V_27 = F_9 ( V_2 , sizeof( struct V_23 ) , F_10 ( V_2 ) ,
V_29 ) ;
F_11 ( V_2 ) ;
if ( ! V_27 )
return - V_30 ;
F_12 ( V_27 , sizeof( struct V_23 ) ) ;
F_13 ( V_27 ) ;
F_14 ( V_27 , V_24 , sizeof( struct V_23 ) ) ;
V_27 -> V_31 = F_3 ( V_32 ) ;
V_27 -> V_33 = V_34 ;
V_27 -> V_22 = V_22 ;
F_15 ( V_35 , L_8 ,
V_27 -> V_36 , V_27 -> V_37 ) ;
V_28 = V_26 ( V_27 , V_22 ) ;
F_11 ( V_27 ) ;
return V_28 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const T_1 V_38 )
{
bool V_9 ;
switch ( V_38 ) {
case V_39 :
V_9 = F_2 ( V_2 , V_4 -> V_11 , 16 ) ;
break;
case V_40 :
V_4 -> V_11 [ 0 ] = 0xFF ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 1 ] , 1 ) ;
V_9 |= F_2 ( V_2 , & V_4 -> V_11 [ 11 ] , 5 ) ;
break;
case V_41 :
V_4 -> V_11 [ 0 ] = 0xFF ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 1 ] , 1 ) ;
V_9 |= F_2 ( V_2 , & V_4 -> V_11 [ 13 ] , 3 ) ;
break;
case V_42 :
V_4 -> V_11 [ 0 ] = 0xFF ;
V_4 -> V_11 [ 1 ] = 0x02 ;
V_9 = F_2 ( V_2 , & V_4 -> V_11 [ 15 ] , 1 ) ;
break;
default:
F_4 ( L_9 , V_38 ) ;
return - V_19 ;
}
if ( V_9 ) {
F_4 ( L_3 ) ;
return - V_20 ;
}
F_5 ( NULL , L_10 ,
V_4 -> V_11 , 16 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
bool V_9 ;
T_1 V_45 = 0 , V_46 = 0 ;
V_9 = F_2 ( V_2 , & V_45 , sizeof( V_45 ) ) ;
if ( ( V_45 & V_47 ) == V_48 ) {
F_4 ( L_11 ) ;
switch ( V_45 & V_49 ) {
case V_50 :
V_9 |= F_2 ( V_2 , & V_44 -> V_51 ,
sizeof( V_44 -> V_51 ) ) ;
V_9 |= F_2 ( V_2 , & V_44 -> V_52 ,
sizeof( V_44 -> V_52 ) ) ;
break;
case V_53 :
V_9 |= F_2 ( V_2 , & V_44 -> V_51 ,
sizeof( V_44 -> V_51 ) ) ;
V_9 |= F_2 ( V_2 , & V_46 , sizeof( V_46 ) ) ;
V_44 -> V_52 = F_3 ( V_46 + V_54 ) ;
break;
case V_55 :
V_9 |= F_2 ( V_2 , & V_46 , sizeof( V_46 ) ) ;
V_44 -> V_51 = F_3 ( V_46 + V_54 ) ;
V_9 |= F_2 ( V_2 , & V_44 -> V_52 ,
sizeof( V_44 -> V_52 ) ) ;
break;
case V_49 :
V_9 |= F_2 ( V_2 , & V_46 , sizeof( V_46 ) ) ;
V_44 -> V_51 = F_3 ( V_56 +
( V_46 >> 4 ) ) ;
V_44 -> V_52 = F_3 ( V_56 +
( V_46 & 0x0f ) ) ;
break;
default:
F_4 ( L_12 ) ;
goto V_57;
}
F_4 ( L_13 ,
F_18 ( V_44 -> V_51 ) , F_18 ( V_44 -> V_52 ) ) ;
if ( V_45 & V_58 ) {
F_19 ( L_14 ) ;
goto V_57;
} else {
V_9 |= F_2 ( V_2 , & V_44 -> V_59 ,
sizeof( V_44 -> V_59 ) ) ;
}
V_44 -> V_37 = F_3 ( V_2 -> V_37 + sizeof( struct V_43 ) ) ;
F_4 ( L_15 , F_18 ( V_44 -> V_37 ) ) ;
} else {
F_4 ( L_16 ) ;
goto V_57;
}
if ( V_9 )
goto V_57;
return 0 ;
V_57:
return - V_19 ;
}
int F_20 ( struct V_1 * V_2 , struct V_25 * V_22 ,
const T_1 * V_60 , const T_1 V_61 , const T_1 V_62 ,
const T_1 * V_63 , const T_1 V_64 , const T_1 V_65 ,
T_1 V_66 , T_1 V_67 , T_2 V_26 )
{
struct V_23 V_24 = {} ;
T_1 V_45 , V_68 = 0 ;
int V_57 ;
F_15 ( V_35 , L_17 ,
V_2 -> V_36 , V_2 -> V_37 ) ;
if ( V_67 & V_69 ) {
F_4 ( L_18 ) ;
if ( F_2 ( V_2 , & V_68 , sizeof( V_68 ) ) )
goto V_70;
}
V_24 . V_71 = 6 ;
switch ( ( V_66 & V_72 ) >> 3 ) {
case 0 :
if ( F_2 ( V_2 , & V_45 , sizeof( V_45 ) ) )
goto V_70;
memcpy ( & V_24 . V_73 , & V_2 -> V_36 [ 0 ] , 3 ) ;
F_21 ( V_2 , 3 ) ;
V_24 . V_74 = ( ( V_45 >> 2 ) & 0x0f ) ;
V_24 . V_73 [ 0 ] = ( ( V_45 >> 2 ) & 0x30 ) | ( V_45 << 6 ) |
( V_24 . V_73 [ 0 ] & 0x0f ) ;
break;
case 2 :
if ( F_2 ( V_2 , & V_45 , sizeof( V_45 ) ) )
goto V_70;
V_24 . V_74 = ( ( V_45 >> 2 ) & 0x0f ) ;
V_24 . V_73 [ 0 ] = ( ( V_45 << 6 ) & 0xC0 ) | ( ( V_45 >> 2 ) & 0x30 ) ;
break;
case 1 :
if ( F_2 ( V_2 , & V_45 , sizeof( V_45 ) ) )
goto V_70;
V_24 . V_73 [ 0 ] = ( V_2 -> V_36 [ 0 ] & 0x0F ) | ( ( V_45 >> 2 ) & 0x30 ) ;
memcpy ( & V_24 . V_73 [ 1 ] , & V_2 -> V_36 [ 0 ] , 2 ) ;
F_21 ( V_2 , 2 ) ;
break;
case 3 :
break;
default:
break;
}
if ( ( V_66 & V_75 ) == 0 ) {
if ( F_2 ( V_2 , & V_24 . V_76 , sizeof( V_24 . V_76 ) ) )
goto V_70;
F_4 ( L_19 ,
V_24 . V_76 ) ;
}
if ( ( V_66 & 0x03 ) != V_77 ) {
V_24 . V_78 = V_79 [ V_66 & 0x03 ] ;
} else {
if ( F_2 ( V_2 , & V_24 . V_78 ,
sizeof( V_24 . V_78 ) ) )
goto V_70;
}
V_45 = ( ( V_67 & V_80 ) >> V_81 ) & 0x03 ;
if ( V_67 & V_82 ) {
F_4 ( L_20 ) ;
V_57 = F_6 ( V_2 , & V_24 . V_60 , V_45 ) ;
} else {
F_4 ( L_21 ) ;
V_57 = F_1 ( V_2 , & V_24 . V_60 , V_45 , V_60 ,
V_61 , V_62 ) ;
}
if ( V_57 )
goto V_70;
V_45 = ( ( V_67 & V_42 ) >> V_83 ) & 0x03 ;
if ( V_67 & V_84 ) {
if ( V_67 & V_85 ) {
F_4 ( L_22 ) ;
} else {
V_57 = F_16 ( V_2 , & V_24 . V_63 ,
V_45 ) ;
if ( V_57 )
goto V_70;
}
} else {
V_57 = F_1 ( V_2 , & V_24 . V_63 , V_45 , V_63 ,
V_64 , V_65 ) ;
F_4 ( L_23 ,
V_45 , & V_24 . V_63 ) ;
if ( V_57 )
goto V_70;
}
if ( V_66 & V_75 ) {
struct V_43 V_44 ;
struct V_1 * V_27 ;
if ( F_17 ( V_2 , & V_44 ) )
goto V_70;
V_27 = F_9 ( V_2 , sizeof( struct V_43 ) ,
F_10 ( V_2 ) , V_29 ) ;
F_11 ( V_2 ) ;
if ( ! V_27 )
return - V_30 ;
V_2 = V_27 ;
F_12 ( V_2 , sizeof( struct V_43 ) ) ;
F_22 ( V_2 ) ;
F_14 ( V_2 , & V_44 , sizeof( struct V_43 ) ) ;
F_15 ( V_35 , L_24 ,
( T_1 * ) & V_44 , sizeof( V_44 ) ) ;
V_24 . V_76 = V_86 ;
}
V_24 . V_87 = F_3 ( V_2 -> V_37 ) ;
F_4 ( L_25 ,
F_23 ( V_2 ) , V_2 -> V_37 ) ;
F_4 ( L_26
L_27 ,
V_24 . V_71 , F_18 ( V_24 . V_87 ) , V_24 . V_76 ,
V_24 . V_78 , & V_24 . V_63 ) ;
F_15 ( V_35 , L_28 , ( T_1 * ) & V_24 , sizeof( V_24 ) ) ;
return F_8 ( V_2 , & V_24 , V_22 , V_26 ) ;
V_70:
F_11 ( V_2 ) ;
return - V_19 ;
}
static T_1 F_24 ( T_1 * * V_88 , T_1 V_89 ,
const struct V_3 * V_4 ,
const unsigned char * V_6 )
{
T_1 V_46 = 0 ;
if ( F_25 ( V_4 , V_6 ) ) {
V_46 = 3 ;
F_4 ( L_29 ) ;
} else if ( F_26 ( V_4 ) ) {
F_27 ( V_88 , & V_4 -> V_17 [ 7 ] , 2 ) ;
V_46 = 2 ;
F_5 ( NULL , L_30 ,
* V_88 - 2 , 2 ) ;
} else {
F_27 ( V_88 , & V_4 -> V_17 [ 4 ] , 8 ) ;
V_46 = 1 ;
F_5 ( NULL , L_31 ,
* V_88 - 8 , 8 ) ;
}
return F_28 ( V_46 , V_89 ) ;
}
static void F_29 ( T_1 * * V_88 , struct V_1 * V_2 )
{
struct V_43 * V_44 = F_30 ( V_2 ) ;
T_1 V_45 ;
if ( ( ( F_18 ( V_44 -> V_51 ) & V_90 ) ==
V_56 ) &&
( ( F_18 ( V_44 -> V_52 ) & V_90 ) ==
V_56 ) ) {
F_4 ( L_32 ) ;
V_45 = V_49 ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
V_45 = F_18 ( V_44 -> V_52 ) - V_56 +
( ( F_18 ( V_44 -> V_51 ) - V_56 ) << 4 ) ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
} else if ( ( F_18 ( V_44 -> V_52 ) & V_91 ) ==
V_54 ) {
F_4 ( L_33 ) ;
V_45 = V_53 ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
F_27 ( V_88 , & V_44 -> V_51 , sizeof( V_44 -> V_51 ) ) ;
V_45 = F_18 ( V_44 -> V_52 ) - V_54 ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
} else if ( ( F_18 ( V_44 -> V_51 ) & V_91 ) ==
V_54 ) {
F_4 ( L_34 ) ;
V_45 = V_55 ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
V_45 = F_18 ( V_44 -> V_51 ) - V_54 ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
F_27 ( V_88 , & V_44 -> V_52 , sizeof( V_44 -> V_52 ) ) ;
} else {
F_4 ( L_35 ) ;
V_45 = V_50 ;
F_27 ( V_88 , & V_45 , sizeof( V_45 ) ) ;
F_27 ( V_88 , & V_44 -> V_51 , sizeof( V_44 -> V_51 ) ) ;
F_27 ( V_88 , & V_44 -> V_52 , sizeof( V_44 -> V_52 ) ) ;
}
F_27 ( V_88 , & V_44 -> V_59 , sizeof( V_44 -> V_59 ) ) ;
F_21 ( V_2 , sizeof( struct V_43 ) ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_25 * V_22 ,
unsigned short type , const void * V_92 ,
const void * V_93 , unsigned int V_37 )
{
T_1 V_45 , V_66 , V_67 , * V_88 ;
struct V_23 * V_24 ;
T_1 V_94 [ 100 ] = {} ;
int V_7 ;
if ( type != V_32 )
return - V_19 ;
V_24 = F_32 ( V_2 ) ;
V_88 = V_94 + 2 ;
F_4 ( L_36
L_37 ,
V_24 -> V_71 , F_18 ( V_24 -> V_87 ) , V_24 -> V_76 ,
V_24 -> V_78 , & V_24 -> V_63 ) ;
F_15 ( V_35 , L_38 ,
F_33 ( V_2 ) , sizeof( struct V_23 ) ) ;
V_66 = V_95 ;
V_67 = 0 ;
F_5 ( V_35 , L_39 ,
( unsigned char * ) V_93 , V_96 ) ;
F_5 ( V_35 , L_40 ,
( unsigned char * ) V_92 , V_96 ) ;
F_15 ( V_35 , L_41 ,
V_2 -> V_36 , V_2 -> V_37 ) ;
V_45 = ( V_24 -> V_74 << 4 ) | ( V_24 -> V_73 [ 0 ] >> 4 ) ;
V_45 = ( ( V_45 & 0x03 ) << 6 ) | ( V_45 >> 2 ) ;
if ( ( ( V_24 -> V_73 [ 0 ] & 0x0F ) == 0 ) &&
( V_24 -> V_73 [ 1 ] == 0 ) && ( V_24 -> V_73 [ 2 ] == 0 ) ) {
V_66 |= V_97 ;
if ( ( V_24 -> V_74 == 0 ) &&
( ( V_24 -> V_73 [ 0 ] & 0xF0 ) == 0 ) ) {
V_66 |= V_98 ;
} else {
* V_88 = V_45 ;
V_88 += 1 ;
}
} else {
if ( ( V_24 -> V_74 == 0 ) &&
( ( V_24 -> V_73 [ 0 ] & 0xF0 ) == 0 ) ) {
V_66 |= V_98 ;
* V_88 = ( V_45 & 0xc0 ) | ( V_24 -> V_73 [ 0 ] & 0x0F ) ;
memcpy ( V_88 + 1 , & V_24 -> V_73 [ 1 ] , 2 ) ;
V_88 += 3 ;
} else {
memcpy ( V_88 , V_24 , 4 ) ;
* V_88 = V_45 ;
V_88 += 4 ;
}
}
if ( V_24 -> V_76 == V_86 )
V_66 |= V_75 ;
if ( ( V_66 & V_75 ) == 0 )
F_27 ( & V_88 , & V_24 -> V_76 ,
sizeof( V_24 -> V_76 ) ) ;
switch ( V_24 -> V_78 ) {
case 1 :
V_66 |= V_99 ;
break;
case 64 :
V_66 |= V_100 ;
break;
case 255 :
V_66 |= V_101 ;
break;
default:
F_27 ( & V_88 , & V_24 -> V_78 ,
sizeof( V_24 -> V_78 ) ) ;
}
V_7 = F_34 ( & V_24 -> V_60 ) ;
if ( V_7 == V_102 ) {
F_4 ( L_42 ) ;
V_67 |= V_82 ;
} else {
if ( V_7 & V_103 ) {
V_67 |= F_24 ( & V_88 ,
V_81 ,
& V_24 -> V_60 , V_93 ) ;
F_4 ( L_43 ,
& V_24 -> V_60 , V_67 ) ;
} else {
F_4 ( L_44 ) ;
F_27 ( & V_88 , V_24 -> V_60 . V_11 , 16 ) ;
}
}
V_7 = F_34 ( & V_24 -> V_63 ) ;
if ( V_7 & V_104 ) {
F_4 ( L_45 ) ;
V_67 |= V_84 ;
if ( F_35 ( & V_24 -> V_63 ) ) {
F_4 ( L_46 ) ;
V_67 |= V_42 ;
F_27 ( & V_88 ,
& V_24 -> V_63 . V_11 [ 15 ] , 1 ) ;
} else if ( F_36 ( & V_24 -> V_63 ) ) {
F_4 ( L_47 ) ;
V_67 |= V_41 ;
F_27 ( & V_88 ,
& V_24 -> V_63 . V_11 [ 1 ] , 1 ) ;
F_27 ( & V_88 ,
& V_24 -> V_63 . V_11 [ 13 ] , 3 ) ;
} else if ( F_37 ( & V_24 -> V_63 ) ) {
F_4 ( L_48 ) ;
V_67 |= V_40 ;
F_27 ( & V_88 ,
& V_24 -> V_63 . V_11 [ 1 ] , 1 ) ;
F_27 ( & V_88 ,
& V_24 -> V_63 . V_11 [ 11 ] , 5 ) ;
} else {
F_4 ( L_49 ) ;
V_67 |= V_39 ;
F_27 ( & V_88 , V_24 -> V_63 . V_11 , 16 ) ;
}
} else {
if ( V_7 & V_103 ) {
V_67 |= F_24 ( & V_88 ,
V_83 , & V_24 -> V_63 , V_92 ) ;
F_4 ( L_50
L_51 , & V_24 -> V_63 , V_67 ) ;
} else {
F_4 ( L_52 , & V_24 -> V_63 ) ;
F_27 ( & V_88 , V_24 -> V_63 . V_11 , 16 ) ;
}
}
if ( V_24 -> V_76 == V_86 )
F_29 ( & V_88 , V_2 ) ;
V_94 [ 0 ] = V_66 ;
V_94 [ 1 ] = V_67 ;
F_21 ( V_2 , sizeof( struct V_23 ) ) ;
F_22 ( V_2 ) ;
memcpy ( F_12 ( V_2 , V_88 - V_94 ) , V_94 , V_88 - V_94 ) ;
F_13 ( V_2 ) ;
F_4 ( L_53 , ( int ) ( V_88 - V_94 ) , V_2 -> V_37 ) ;
F_15 ( V_35 , L_54 ,
V_2 -> V_36 , V_2 -> V_37 ) ;
return 0 ;
}
