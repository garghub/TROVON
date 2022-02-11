static inline void F_1 ( struct V_1 * V_2 ,
const void * V_3 )
{
V_2 -> V_4 [ 0 ] = 0xFE ;
V_2 -> V_4 [ 1 ] = 0x80 ;
memcpy ( & V_2 -> V_4 [ 8 ] , V_3 , V_5 ) ;
V_2 -> V_4 [ 8 ] ^= 0x02 ;
}
static inline void F_2 ( struct V_1 * V_2 ,
const void * V_3 )
{
const struct V_6 * V_7 = V_3 ;
T_1 V_8 [ V_5 ] = { } ;
switch ( V_7 -> V_9 ) {
case V_10 :
F_3 ( V_8 , & V_7 -> V_11 ) ;
F_1 ( V_2 , V_8 ) ;
break;
case V_12 :
V_2 -> V_4 [ 0 ] = 0xFE ;
V_2 -> V_4 [ 1 ] = 0x80 ;
V_2 -> V_4 [ 11 ] = 0xFF ;
V_2 -> V_4 [ 12 ] = 0xFE ;
F_4 ( & V_2 -> V_13 [ 7 ] ,
& V_7 -> V_14 ) ;
break;
default:
F_5 ( 1 ) ;
break;
}
}
static int F_6 ( struct V_15 * V_16 , const struct V_17 * V_18 ,
struct V_1 * V_2 , T_1 V_19 ,
const void * V_3 )
{
bool V_20 ;
switch ( V_19 ) {
case V_21 :
V_20 = F_7 ( V_16 , V_2 -> V_4 , 16 ) ;
break;
case V_22 :
case V_23 :
V_2 -> V_4 [ 0 ] = 0xFE ;
V_2 -> V_4 [ 1 ] = 0x80 ;
V_20 = F_7 ( V_16 , & V_2 -> V_4 [ 8 ] , 8 ) ;
break;
case V_24 :
case V_25 :
V_2 -> V_4 [ 0 ] = 0xFE ;
V_2 -> V_4 [ 1 ] = 0x80 ;
V_2 -> V_4 [ 11 ] = 0xFF ;
V_2 -> V_4 [ 12 ] = 0xFE ;
V_20 = F_7 ( V_16 , & V_2 -> V_4 [ 14 ] , 2 ) ;
break;
case V_26 :
case V_27 :
V_20 = false ;
switch ( F_8 ( V_18 ) -> V_28 ) {
case V_29 :
F_2 ( V_2 , V_3 ) ;
break;
default:
F_1 ( V_2 , V_3 ) ;
break;
}
break;
default:
F_9 ( L_1 , V_19 ) ;
return - V_30 ;
}
if ( V_20 ) {
F_9 ( L_2 ) ;
return - V_31 ;
}
F_10 ( NULL , L_3 ,
V_2 -> V_4 , 16 ) ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
T_1 V_19 )
{
switch ( V_19 ) {
case V_32 :
break;
case V_22 :
case V_24 :
case V_26 :
F_12 ( V_16 -> V_18 , L_4 ,
V_19 ) ;
return - V_30 ;
default:
F_9 ( L_5 , V_19 ) ;
return - V_30 ;
}
F_10 ( NULL ,
L_6 ,
V_2 -> V_4 , 16 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
T_1 V_19 )
{
bool V_20 ;
switch ( V_19 ) {
case V_21 :
V_20 = F_7 ( V_16 , V_2 -> V_4 , 16 ) ;
break;
case V_23 :
V_2 -> V_4 [ 0 ] = 0xFF ;
V_20 = F_7 ( V_16 , & V_2 -> V_4 [ 1 ] , 1 ) ;
V_20 |= F_7 ( V_16 , & V_2 -> V_4 [ 11 ] , 5 ) ;
break;
case V_25 :
V_2 -> V_4 [ 0 ] = 0xFF ;
V_20 = F_7 ( V_16 , & V_2 -> V_4 [ 1 ] , 1 ) ;
V_20 |= F_7 ( V_16 , & V_2 -> V_4 [ 13 ] , 3 ) ;
break;
case V_27 :
V_2 -> V_4 [ 0 ] = 0xFF ;
V_2 -> V_4 [ 1 ] = 0x02 ;
V_20 = F_7 ( V_16 , & V_2 -> V_4 [ 15 ] , 1 ) ;
break;
default:
F_9 ( L_7 , V_19 ) ;
return - V_30 ;
}
if ( V_20 ) {
F_9 ( L_2 ) ;
return - V_31 ;
}
F_10 ( NULL , L_8 ,
V_2 -> V_4 , 16 ) ;
return 0 ;
}
static inline void F_14 ( struct V_33 * V_34 , const T_1 * V_35 )
{
T_1 V_36 = V_35 [ 0 ] & 0xc0 ;
V_34 -> V_37 [ 0 ] |= ( V_36 >> 2 ) ;
}
static inline void F_15 ( struct V_33 * V_34 , const T_1 * V_35 )
{
T_1 V_38 = V_35 [ 0 ] & 0x3f ;
V_34 -> V_39 |= ( ( V_38 & 0x3c ) >> 2 ) ;
V_34 -> V_37 [ 0 ] |= ( ( V_38 & 0x03 ) << 6 ) ;
}
static inline void F_16 ( struct V_33 * V_34 , const T_1 * V_40 )
{
V_34 -> V_37 [ 0 ] |= V_40 [ 0 ] & 0x0f ;
memcpy ( & V_34 -> V_37 [ 1 ] , & V_40 [ 1 ] , 2 ) ;
}
static int F_17 ( struct V_15 * V_16 , struct V_33 * V_34 ,
T_1 V_41 )
{
T_1 V_35 [ 4 ] ;
switch ( V_41 ) {
case V_42 :
if ( F_7 ( V_16 , V_35 , 4 ) )
return - V_30 ;
F_14 ( V_34 , V_35 ) ;
F_15 ( V_34 , V_35 ) ;
F_16 ( V_34 , & V_35 [ 1 ] ) ;
break;
case V_43 :
if ( F_7 ( V_16 , V_35 , 3 ) )
return - V_30 ;
F_14 ( V_34 , V_35 ) ;
F_16 ( V_34 , & V_35 [ 0 ] ) ;
break;
case V_44 :
if ( F_7 ( V_16 , V_35 , 1 ) )
return - V_30 ;
F_14 ( V_34 , V_35 ) ;
F_15 ( V_34 , V_35 ) ;
break;
case V_45 :
break;
default:
F_5 ( 1 ) ;
return - V_30 ;
}
return 0 ;
}
int F_18 ( struct V_15 * V_16 , const struct V_17 * V_18 ,
const void * V_46 , const void * V_47 )
{
struct V_33 V_34 = {} ;
T_1 V_48 , V_49 ;
int V_50 ;
F_19 ( V_51 , L_9 ,
V_16 -> V_52 , V_16 -> V_53 ) ;
if ( F_7 ( V_16 , & V_48 , sizeof( V_48 ) ) ||
F_7 ( V_16 , & V_49 , sizeof( V_49 ) ) )
return - V_30 ;
if ( V_49 & V_54 )
return - V_55 ;
V_34 . V_56 = 6 ;
V_50 = F_17 ( V_16 , & V_34 ,
V_48 & V_57 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( ! ( V_48 & V_58 ) ) {
if ( F_7 ( V_16 , & V_34 . V_59 , sizeof( V_34 . V_59 ) ) )
return - V_30 ;
F_9 ( L_10 ,
V_34 . V_59 ) ;
}
if ( ( V_48 & V_60 ) != V_61 ) {
V_34 . V_62 = V_63 [ V_48 & V_60 ] ;
} else {
if ( F_7 ( V_16 , & V_34 . V_62 ,
sizeof( V_34 . V_62 ) ) )
return - V_30 ;
}
if ( V_49 & V_64 ) {
F_9 ( L_11 ) ;
V_50 = F_11 ( V_16 , & V_34 . V_47 ,
V_49 & V_65 ) ;
} else {
F_9 ( L_12 ) ;
V_50 = F_6 ( V_16 , V_18 , & V_34 . V_47 ,
V_49 & V_65 , V_47 ) ;
}
if ( V_50 )
return - V_30 ;
if ( V_49 & V_66 ) {
if ( V_49 & V_67 ) {
F_9 ( L_13 ) ;
} else {
V_50 = F_13 ( V_16 , & V_34 . V_46 ,
V_49 & V_68 ) ;
if ( V_50 )
return - V_30 ;
}
} else {
V_50 = F_6 ( V_16 , V_18 , & V_34 . V_46 ,
V_49 & V_68 , V_46 ) ;
F_9 ( L_14 ,
V_49 & V_68 , & V_34 . V_46 ) ;
if ( V_50 )
return - V_30 ;
}
if ( V_48 & V_58 ) {
V_50 = F_20 ( V_16 , V_18 , & V_34 ) ;
if ( V_50 < 0 )
return V_50 ;
} else {
V_50 = F_21 ( V_16 , sizeof( V_34 ) ) ;
if ( F_22 ( V_50 ) )
return V_50 ;
}
switch ( F_8 ( V_18 ) -> V_28 ) {
case V_29 :
if ( F_23 ( V_16 ) -> V_69 )
V_34 . V_70 = F_24 ( F_23 ( V_16 ) -> V_69 -
sizeof( struct V_33 ) ) ;
else
V_34 . V_70 = F_24 ( V_16 -> V_53 ) ;
break;
default:
V_34 . V_70 = F_24 ( V_16 -> V_53 ) ;
break;
}
F_9 ( L_15 ,
F_25 ( V_16 ) , V_16 -> V_53 ) ;
F_9 ( L_16
L_17 ,
V_34 . V_56 , F_26 ( V_34 . V_70 ) , V_34 . V_59 ,
V_34 . V_62 , & V_34 . V_46 ) ;
F_27 ( V_16 , sizeof( V_34 ) ) ;
F_28 ( V_16 ) ;
F_29 ( V_16 , & V_34 , sizeof( V_34 ) ) ;
F_19 ( V_51 , L_18 , ( T_1 * ) & V_34 , sizeof( V_34 ) ) ;
return 0 ;
}
static T_1 F_30 ( T_1 * * V_71 , const struct V_1 * V_2 ,
const unsigned char * V_3 , bool V_72 )
{
T_1 V_73 = V_21 ;
if ( F_31 ( V_2 , V_3 ) ) {
V_73 = V_27 ;
F_9 ( L_19 ) ;
} else if ( F_32 ( V_2 ) ) {
F_33 ( V_71 , & V_2 -> V_13 [ 7 ] , 2 ) ;
V_73 = V_25 ;
F_10 ( NULL , L_20 ,
* V_71 - 2 , 2 ) ;
} else {
F_33 ( V_71 , & V_2 -> V_13 [ 4 ] , 8 ) ;
V_73 = V_23 ;
F_10 ( NULL , L_21 ,
* V_71 - 8 , 8 ) ;
}
if ( V_72 )
return V_74 [ V_73 ] ;
else
return V_73 ;
}
static inline T_1 F_34 ( const struct V_33 * V_34 )
{
T_1 V_38 , V_36 ;
V_38 = ( V_34 -> V_39 << 2 ) | ( ( V_34 -> V_37 [ 0 ] & 0xc0 ) >> 6 ) ;
V_36 = ( V_34 -> V_37 [ 0 ] & 0x30 ) ;
F_9 ( L_22 , V_36 >> 4 , V_38 ) ;
return ( V_36 << 2 ) | V_38 ;
}
static inline bool F_35 ( const struct V_33 * V_34 )
{
return ( ( ! ( V_34 -> V_37 [ 0 ] & 0x0f ) ) &&
! V_34 -> V_37 [ 1 ] && ! V_34 -> V_37 [ 2 ] ) ;
}
static T_1 F_36 ( T_1 * * V_71 , const struct V_33 * V_34 )
{
T_1 V_75 = F_34 ( V_34 ) , V_35 [ 4 ] , V_41 ;
F_9 ( L_23 , V_75 ) ;
if ( F_35 ( V_34 ) ) {
if ( ! V_75 ) {
V_41 = V_45 ;
} else {
F_33 ( V_71 , & V_75 , sizeof( V_75 ) ) ;
V_41 = V_44 ;
}
} else {
if ( ! ( V_75 & 0x3f ) ) {
memcpy ( & V_35 [ 0 ] , & V_34 -> V_37 [ 0 ] , 3 ) ;
V_35 [ 0 ] &= ~ 0xf0 ;
V_35 [ 0 ] |= ( V_75 & 0xc0 ) ;
F_33 ( V_71 , V_35 , 3 ) ;
V_41 = V_43 ;
} else {
memcpy ( & V_35 [ 0 ] , & V_75 , sizeof( V_75 ) ) ;
memcpy ( & V_35 [ 1 ] , & V_34 -> V_37 [ 0 ] , 3 ) ;
V_35 [ 1 ] &= ~ 0xf0 ;
F_33 ( V_71 , V_35 , 4 ) ;
V_41 = V_42 ;
}
}
return V_41 ;
}
static T_1 F_37 ( T_1 * * V_71 ,
const struct V_1 * V_2 )
{
T_1 V_41 ;
if ( F_38 ( V_2 ) ) {
F_9 ( L_24 ) ;
F_33 ( V_71 , & V_2 -> V_4 [ 15 ] , 1 ) ;
V_41 = V_27 ;
} else if ( F_39 ( V_2 ) ) {
F_9 ( L_25 ) ;
F_33 ( V_71 , & V_2 -> V_4 [ 1 ] , 1 ) ;
F_33 ( V_71 , & V_2 -> V_4 [ 13 ] , 3 ) ;
V_41 = V_25 ;
} else if ( F_40 ( V_2 ) ) {
F_9 ( L_26 ) ;
F_33 ( V_71 , & V_2 -> V_4 [ 1 ] , 1 ) ;
F_33 ( V_71 , & V_2 -> V_4 [ 11 ] , 5 ) ;
V_41 = V_23 ;
} else {
F_9 ( L_27 ) ;
F_33 ( V_71 , V_2 -> V_4 , 16 ) ;
V_41 = V_21 ;
}
return V_41 ;
}
int F_41 ( struct V_15 * V_16 , const struct V_17 * V_18 ,
const void * V_46 , const void * V_47 )
{
T_1 V_48 , V_49 , * V_71 ;
struct V_33 * V_34 ;
T_1 V_76 [ V_77 ] = {} ;
int V_78 , V_79 ;
if ( V_16 -> V_80 != F_24 ( V_81 ) )
return - V_30 ;
V_34 = F_42 ( V_16 ) ;
V_71 = V_76 + 2 ;
F_9 ( L_28
L_29 ,
V_34 -> V_56 , F_26 ( V_34 -> V_70 ) , V_34 -> V_59 ,
V_34 -> V_62 , & V_34 -> V_46 ) ;
F_19 ( V_51 , L_30 ,
F_43 ( V_16 ) , sizeof( struct V_33 ) ) ;
V_48 = V_82 ;
V_49 = 0 ;
F_10 ( V_51 , L_31 , V_47 , V_5 ) ;
F_10 ( V_51 , L_32 , V_46 , V_5 ) ;
F_19 ( V_51 , L_33 ,
V_16 -> V_52 , V_16 -> V_53 ) ;
V_48 |= F_36 ( & V_71 , V_34 ) ;
V_78 = F_44 ( V_16 , V_34 , & V_71 ) ;
if ( V_78 == - V_83 )
F_33 ( & V_71 , & V_34 -> V_59 ,
sizeof( V_34 -> V_59 ) ) ;
else
V_48 |= V_58 ;
switch ( V_34 -> V_62 ) {
case 1 :
V_48 |= V_84 ;
break;
case 64 :
V_48 |= V_85 ;
break;
case 255 :
V_48 |= V_86 ;
break;
default:
F_33 ( & V_71 , & V_34 -> V_62 ,
sizeof( V_34 -> V_62 ) ) ;
}
V_79 = F_45 ( & V_34 -> V_47 ) ;
if ( V_79 == V_87 ) {
F_9 ( L_34 ) ;
V_49 |= V_64 ;
} else {
if ( V_79 & V_88 ) {
V_49 |= F_30 ( & V_71 , & V_34 -> V_47 ,
V_47 , true ) ;
F_9 ( L_35 ,
& V_34 -> V_47 , V_49 ) ;
} else {
F_9 ( L_36 ) ;
F_33 ( & V_71 , V_34 -> V_47 . V_4 , 16 ) ;
}
}
V_79 = F_45 ( & V_34 -> V_46 ) ;
if ( V_79 & V_89 ) {
F_9 ( L_37 ) ;
V_49 |= V_66 ;
V_49 |= F_37 ( & V_71 , & V_34 -> V_46 ) ;
} else {
if ( V_79 & V_88 ) {
V_49 |= F_30 ( & V_71 , & V_34 -> V_46 ,
V_46 , false ) ;
F_9 ( L_38
L_39 , & V_34 -> V_46 , V_49 ) ;
} else {
F_9 ( L_40 , & V_34 -> V_46 ) ;
F_33 ( & V_71 , V_34 -> V_46 . V_4 , 16 ) ;
}
}
if ( V_48 & V_58 ) {
V_78 = F_46 ( V_16 , V_34 , & V_71 ) ;
if ( V_78 < 0 )
return V_78 ;
}
V_76 [ 0 ] = V_48 ;
V_76 [ 1 ] = V_49 ;
F_47 ( V_16 , sizeof( struct V_33 ) ) ;
F_48 ( V_16 ) ;
memcpy ( F_27 ( V_16 , V_71 - V_76 ) , V_76 , V_71 - V_76 ) ;
F_28 ( V_16 ) ;
F_9 ( L_41 , ( int ) ( V_71 - V_76 ) , V_16 -> V_53 ) ;
F_19 ( V_51 , L_42 ,
V_16 -> V_52 , V_16 -> V_53 ) ;
return 0 ;
}
