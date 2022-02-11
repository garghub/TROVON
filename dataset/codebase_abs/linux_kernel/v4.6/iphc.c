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
static struct V_15 *
F_6 ( const struct V_16 * V_17 , T_1 V_18 )
{
struct V_15 * V_19 = & F_7 ( V_17 ) -> V_20 . V_21 [ V_18 ] ;
if ( ! F_8 ( V_19 ) )
return NULL ;
return V_19 ;
}
static struct V_15 *
F_9 ( const struct V_16 * V_17 ,
const struct V_1 * V_7 )
{
struct V_15 * V_21 = F_7 ( V_17 ) -> V_20 . V_21 ;
struct V_15 * V_19 = NULL ;
struct V_1 V_22 ;
T_1 V_23 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( ! F_8 ( & V_21 [ V_24 ] ) ||
! F_10 ( & V_21 [ V_24 ] ) )
continue;
F_11 ( & V_22 , V_7 , V_21 [ V_24 ] . V_26 ) ;
if ( V_21 [ V_24 ] . V_26 < 64 )
V_23 = 64 ;
else
V_23 = V_21 [ V_24 ] . V_26 ;
if ( F_12 ( & V_22 , & V_21 [ V_24 ] . V_27 , V_23 ) ) {
if ( ! V_19 ) {
V_19 = & V_21 [ V_24 ] ;
continue;
}
if ( V_21 [ V_24 ] . V_26 > V_19 -> V_26 )
V_19 = & V_21 [ V_24 ] ;
}
}
return V_19 ;
}
static struct V_15 *
F_13 ( const struct V_16 * V_17 ,
const struct V_1 * V_7 )
{
struct V_15 * V_21 = F_7 ( V_17 ) -> V_20 . V_21 ;
struct V_15 * V_19 = NULL ;
struct V_1 V_28 , V_29 = {} ;
int V_24 ;
memcpy ( & V_28 , V_7 , sizeof( * V_7 ) ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( ! F_8 ( & V_21 [ V_24 ] ) ||
! F_10 ( & V_21 [ V_24 ] ) )
continue;
V_28 . V_4 [ 3 ] = V_21 [ V_24 ] . V_26 ;
F_11 ( & V_29 , & V_21 [ V_24 ] . V_27 ,
V_21 [ V_24 ] . V_26 ) ;
memcpy ( & V_28 . V_4 [ 4 ] , & V_29 , 8 ) ;
if ( F_14 ( V_7 , & V_28 ) ) {
V_19 = & V_21 [ V_24 ] ;
break;
}
}
return V_19 ;
}
static int F_15 ( struct V_30 * V_31 , const struct V_16 * V_17 ,
struct V_1 * V_2 , T_1 V_32 ,
const void * V_3 )
{
bool V_33 ;
switch ( V_32 ) {
case V_34 :
V_33 = F_16 ( V_31 , V_2 -> V_4 , 16 ) ;
break;
case V_35 :
case V_36 :
V_2 -> V_4 [ 0 ] = 0xFE ;
V_2 -> V_4 [ 1 ] = 0x80 ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 8 ] , 8 ) ;
break;
case V_37 :
case V_38 :
V_2 -> V_4 [ 0 ] = 0xFE ;
V_2 -> V_4 [ 1 ] = 0x80 ;
V_2 -> V_4 [ 11 ] = 0xFF ;
V_2 -> V_4 [ 12 ] = 0xFE ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 14 ] , 2 ) ;
break;
case V_39 :
case V_40 :
V_33 = false ;
switch ( F_7 ( V_17 ) -> V_41 ) {
case V_42 :
F_2 ( V_2 , V_3 ) ;
break;
default:
F_1 ( V_2 , V_3 ) ;
break;
}
break;
default:
F_17 ( L_1 , V_32 ) ;
return - V_43 ;
}
if ( V_33 ) {
F_17 ( L_2 ) ;
return - V_44 ;
}
F_18 ( NULL , L_3 ,
V_2 -> V_4 , 16 ) ;
return 0 ;
}
static int F_19 ( struct V_30 * V_31 ,
const struct V_16 * V_17 ,
const struct V_15 * V_20 ,
struct V_1 * V_2 , T_1 V_32 ,
const void * V_3 )
{
bool V_33 ;
switch ( V_32 ) {
case V_34 :
V_33 = false ;
break;
case V_35 :
case V_36 :
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 8 ] , 8 ) ;
F_20 ( V_2 , & V_20 -> V_27 , V_20 -> V_26 ) ;
break;
case V_37 :
case V_38 :
V_2 -> V_4 [ 11 ] = 0xFF ;
V_2 -> V_4 [ 12 ] = 0xFE ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 14 ] , 2 ) ;
F_20 ( V_2 , & V_20 -> V_27 , V_20 -> V_26 ) ;
break;
case V_39 :
case V_40 :
V_33 = false ;
switch ( F_7 ( V_17 ) -> V_41 ) {
case V_42 :
F_2 ( V_2 , V_3 ) ;
break;
default:
F_1 ( V_2 , V_3 ) ;
break;
}
F_20 ( V_2 , & V_20 -> V_27 , V_20 -> V_26 ) ;
break;
default:
F_17 ( L_4 , V_32 ) ;
return - V_43 ;
}
if ( V_33 ) {
F_17 ( L_2 ) ;
return - V_44 ;
}
F_18 ( NULL ,
L_5 ,
V_2 -> V_4 , 16 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 V_32 )
{
bool V_33 ;
switch ( V_32 ) {
case V_34 :
V_33 = F_16 ( V_31 , V_2 -> V_4 , 16 ) ;
break;
case V_36 :
V_2 -> V_4 [ 0 ] = 0xFF ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 1 ] , 1 ) ;
V_33 |= F_16 ( V_31 , & V_2 -> V_4 [ 11 ] , 5 ) ;
break;
case V_38 :
V_2 -> V_4 [ 0 ] = 0xFF ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 1 ] , 1 ) ;
V_33 |= F_16 ( V_31 , & V_2 -> V_4 [ 13 ] , 3 ) ;
break;
case V_40 :
V_2 -> V_4 [ 0 ] = 0xFF ;
V_2 -> V_4 [ 1 ] = 0x02 ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 15 ] , 1 ) ;
break;
default:
F_17 ( L_6 , V_32 ) ;
return - V_43 ;
}
if ( V_33 ) {
F_17 ( L_2 ) ;
return - V_44 ;
}
F_18 ( NULL , L_7 ,
V_2 -> V_4 , 16 ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 ,
struct V_15 * V_20 ,
struct V_1 * V_2 ,
T_1 V_32 )
{
struct V_1 V_29 = {} ;
bool V_33 ;
V_2 -> V_4 [ 0 ] = 0xFF ;
V_33 = F_16 ( V_31 , & V_2 -> V_4 [ 1 ] , 2 ) ;
V_33 |= F_16 ( V_31 , & V_2 -> V_4 [ 12 ] , 4 ) ;
if ( V_33 )
return - V_44 ;
V_2 -> V_4 [ 3 ] = V_20 -> V_26 ;
F_11 ( & V_29 , & V_20 -> V_27 , V_20 -> V_26 ) ;
memcpy ( & V_2 -> V_4 [ 4 ] , & V_29 , 8 ) ;
return 0 ;
}
static inline void F_23 ( struct V_45 * V_46 , const T_1 * V_47 )
{
T_1 V_48 = V_47 [ 0 ] & 0xc0 ;
V_46 -> V_49 [ 0 ] |= ( V_48 >> 2 ) ;
}
static inline void F_24 ( struct V_45 * V_46 , const T_1 * V_47 )
{
T_1 V_50 = V_47 [ 0 ] & 0x3f ;
V_46 -> V_51 |= ( ( V_50 & 0x3c ) >> 2 ) ;
V_46 -> V_49 [ 0 ] |= ( ( V_50 & 0x03 ) << 6 ) ;
}
static inline void F_25 ( struct V_45 * V_46 , const T_1 * V_52 )
{
V_46 -> V_49 [ 0 ] |= V_52 [ 0 ] & 0x0f ;
memcpy ( & V_46 -> V_49 [ 1 ] , & V_52 [ 1 ] , 2 ) ;
}
static int F_26 ( struct V_30 * V_31 , struct V_45 * V_46 ,
T_1 V_53 )
{
T_1 V_47 [ 4 ] ;
switch ( V_53 ) {
case V_54 :
if ( F_16 ( V_31 , V_47 , 4 ) )
return - V_43 ;
F_23 ( V_46 , V_47 ) ;
F_24 ( V_46 , V_47 ) ;
F_25 ( V_46 , & V_47 [ 1 ] ) ;
break;
case V_55 :
if ( F_16 ( V_31 , V_47 , 3 ) )
return - V_43 ;
F_23 ( V_46 , V_47 ) ;
F_25 ( V_46 , & V_47 [ 0 ] ) ;
break;
case V_56 :
if ( F_16 ( V_31 , V_47 , 1 ) )
return - V_43 ;
F_23 ( V_46 , V_47 ) ;
F_24 ( V_46 , V_47 ) ;
break;
case V_57 :
break;
default:
F_5 ( 1 ) ;
return - V_43 ;
}
return 0 ;
}
int F_27 ( struct V_30 * V_31 , const struct V_16 * V_17 ,
const void * V_58 , const void * V_59 )
{
struct V_45 V_46 = {} ;
struct V_15 * V_60 ;
T_1 V_61 , V_62 , V_63 = 0 ;
int V_64 ;
F_28 ( V_65 , L_8 ,
V_31 -> V_66 , V_31 -> V_67 ) ;
if ( F_16 ( V_31 , & V_61 , sizeof( V_61 ) ) ||
F_16 ( V_31 , & V_62 , sizeof( V_62 ) ) )
return - V_43 ;
V_46 . V_68 = 6 ;
if ( V_62 & V_69 ) {
if ( F_16 ( V_31 , & V_63 , sizeof( V_63 ) ) )
return - V_43 ;
}
V_64 = F_26 ( V_31 , & V_46 ,
V_61 & V_70 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( ! ( V_61 & V_71 ) ) {
if ( F_16 ( V_31 , & V_46 . V_72 , sizeof( V_46 . V_72 ) ) )
return - V_43 ;
F_17 ( L_9 ,
V_46 . V_72 ) ;
}
if ( ( V_61 & V_73 ) != V_74 ) {
V_46 . V_75 = V_76 [ V_61 & V_73 ] ;
} else {
if ( F_16 ( V_31 , & V_46 . V_75 ,
sizeof( V_46 . V_75 ) ) )
return - V_43 ;
}
if ( V_62 & V_77 ) {
F_29 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
V_60 = F_6 ( V_17 , F_30 ( V_63 ) ) ;
if ( ! V_60 ) {
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
return - V_43 ;
}
F_17 ( L_10 ) ;
V_64 = F_19 ( V_31 , V_17 , V_60 , & V_46 . V_59 ,
V_62 & V_79 , V_59 ) ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
} else {
F_17 ( L_11 ) ;
V_64 = F_15 ( V_31 , V_17 , & V_46 . V_59 ,
V_62 & V_79 , V_59 ) ;
}
if ( V_64 )
return - V_43 ;
switch ( V_62 & ( V_80 | V_81 ) ) {
case V_80 | V_81 :
F_29 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
V_60 = F_6 ( V_17 , F_32 ( V_63 ) ) ;
if ( ! V_60 ) {
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
return - V_43 ;
}
F_17 ( L_12 ) ;
V_64 = F_22 ( V_31 , V_60 ,
& V_46 . V_58 ,
V_62 & V_82 ) ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
break;
case V_80 :
V_64 = F_21 ( V_31 , & V_46 . V_58 ,
V_62 & V_82 ) ;
break;
case V_81 :
F_29 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
V_60 = F_6 ( V_17 , F_32 ( V_63 ) ) ;
if ( ! V_60 ) {
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
return - V_43 ;
}
F_17 ( L_13 ) ;
V_64 = F_19 ( V_31 , V_17 , V_60 , & V_46 . V_58 ,
V_62 & V_82 , V_58 ) ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
break;
default:
V_64 = F_15 ( V_31 , V_17 , & V_46 . V_58 ,
V_62 & V_82 , V_58 ) ;
F_17 ( L_14 ,
V_62 & V_82 , & V_46 . V_58 ) ;
break;
}
if ( V_64 )
return - V_43 ;
if ( V_61 & V_71 ) {
V_64 = F_33 ( V_31 , V_17 , & V_46 ) ;
if ( V_64 < 0 )
return V_64 ;
} else {
V_64 = F_34 ( V_31 , sizeof( V_46 ) ) ;
if ( F_35 ( V_64 ) )
return V_64 ;
}
switch ( F_7 ( V_17 ) -> V_41 ) {
case V_42 :
if ( F_36 ( V_31 ) -> V_83 )
V_46 . V_84 = F_37 ( F_36 ( V_31 ) -> V_83 -
sizeof( struct V_45 ) ) ;
else
V_46 . V_84 = F_37 ( V_31 -> V_67 ) ;
break;
default:
V_46 . V_84 = F_37 ( V_31 -> V_67 ) ;
break;
}
F_17 ( L_15 ,
F_38 ( V_31 ) , V_31 -> V_67 ) ;
F_17 ( L_16
L_17 ,
V_46 . V_68 , F_39 ( V_46 . V_84 ) , V_46 . V_72 ,
V_46 . V_75 , & V_46 . V_58 ) ;
F_40 ( V_31 , sizeof( V_46 ) ) ;
F_41 ( V_31 ) ;
F_42 ( V_31 , & V_46 , sizeof( V_46 ) ) ;
F_28 ( V_65 , L_18 , ( T_1 * ) & V_46 , sizeof( V_46 ) ) ;
return 0 ;
}
static T_1 F_43 ( T_1 * * V_85 , const struct V_1 * V_2 ,
const struct V_15 * V_20 ,
const unsigned char * V_3 , bool V_86 )
{
struct V_1 V_87 = {} ;
T_1 V_88 ;
memcpy ( & V_87 . V_4 [ 8 ] , V_3 , 8 ) ;
V_87 . V_4 [ 8 ] ^= 0x02 ;
F_20 ( & V_87 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_87 , V_2 ) ) {
V_88 = V_40 ;
goto V_89;
}
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_4 [ 11 ] = 0xFF ;
V_87 . V_4 [ 12 ] = 0xFE ;
memcpy ( & V_87 . V_4 [ 14 ] , & V_2 -> V_4 [ 14 ] , 2 ) ;
F_20 ( & V_87 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_87 , V_2 ) ) {
F_44 ( V_85 , & V_2 -> V_4 [ 14 ] , 2 ) ;
V_88 = V_38 ;
goto V_89;
}
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
memcpy ( & V_87 . V_4 [ 8 ] , & V_2 -> V_4 [ 8 ] , 8 ) ;
F_20 ( & V_87 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_87 , V_2 ) ) {
F_44 ( V_85 , & V_2 -> V_4 [ 8 ] , 8 ) ;
V_88 = V_36 ;
goto V_89;
}
F_45 ( 1 , L_19 ) ;
return V_34 ;
V_89:
if ( V_86 )
return V_90 [ V_88 ] ;
else
return V_88 ;
}
static T_1 F_46 ( T_1 * * V_85 , const struct V_1 * V_2 ,
const unsigned char * V_3 , bool V_86 )
{
T_1 V_88 = V_34 ;
if ( F_47 ( V_2 , V_3 ) ) {
V_88 = V_40 ;
F_17 ( L_20 ) ;
} else if ( F_48 ( V_2 ) ) {
F_44 ( V_85 , & V_2 -> V_13 [ 7 ] , 2 ) ;
V_88 = V_38 ;
F_18 ( NULL , L_21 ,
* V_85 - 2 , 2 ) ;
} else {
F_44 ( V_85 , & V_2 -> V_13 [ 4 ] , 8 ) ;
V_88 = V_36 ;
F_18 ( NULL , L_22 ,
* V_85 - 8 , 8 ) ;
}
if ( V_86 )
return V_90 [ V_88 ] ;
else
return V_88 ;
}
static inline T_1 F_49 ( const struct V_45 * V_46 )
{
T_1 V_50 , V_48 ;
V_50 = ( V_46 -> V_51 << 2 ) | ( ( V_46 -> V_49 [ 0 ] & 0xc0 ) >> 6 ) ;
V_48 = ( V_46 -> V_49 [ 0 ] & 0x30 ) ;
F_17 ( L_23 , V_48 >> 4 , V_50 ) ;
return ( V_48 << 2 ) | V_50 ;
}
static inline bool F_50 ( const struct V_45 * V_46 )
{
return ( ( ! ( V_46 -> V_49 [ 0 ] & 0x0f ) ) &&
! V_46 -> V_49 [ 1 ] && ! V_46 -> V_49 [ 2 ] ) ;
}
static T_1 F_51 ( T_1 * * V_85 , const struct V_45 * V_46 )
{
T_1 V_91 = F_49 ( V_46 ) , V_47 [ 4 ] , V_53 ;
F_17 ( L_24 , V_91 ) ;
if ( F_50 ( V_46 ) ) {
if ( ! V_91 ) {
V_53 = V_57 ;
} else {
F_44 ( V_85 , & V_91 , sizeof( V_91 ) ) ;
V_53 = V_56 ;
}
} else {
if ( ! ( V_91 & 0x3f ) ) {
memcpy ( & V_47 [ 0 ] , & V_46 -> V_49 [ 0 ] , 3 ) ;
V_47 [ 0 ] &= ~ 0xf0 ;
V_47 [ 0 ] |= ( V_91 & 0xc0 ) ;
F_44 ( V_85 , V_47 , 3 ) ;
V_53 = V_55 ;
} else {
memcpy ( & V_47 [ 0 ] , & V_91 , sizeof( V_91 ) ) ;
memcpy ( & V_47 [ 1 ] , & V_46 -> V_49 [ 0 ] , 3 ) ;
V_47 [ 1 ] &= ~ 0xf0 ;
F_44 ( V_85 , V_47 , 4 ) ;
V_53 = V_54 ;
}
}
return V_53 ;
}
static T_1 F_52 ( T_1 * * V_85 ,
const struct V_15 * V_20 ,
const struct V_1 * V_2 )
{
T_1 V_66 [ 6 ] ;
memcpy ( V_66 , & V_2 -> V_4 [ 1 ] , 2 ) ;
memcpy ( & V_66 [ 1 ] , & V_2 -> V_4 [ 11 ] , 4 ) ;
F_44 ( V_85 , V_66 , 6 ) ;
return V_34 ;
}
static T_1 F_53 ( T_1 * * V_85 ,
const struct V_1 * V_2 )
{
T_1 V_53 ;
if ( F_54 ( V_2 ) ) {
F_17 ( L_25 ) ;
F_44 ( V_85 , & V_2 -> V_4 [ 15 ] , 1 ) ;
V_53 = V_40 ;
} else if ( F_55 ( V_2 ) ) {
F_17 ( L_26 ) ;
F_44 ( V_85 , & V_2 -> V_4 [ 1 ] , 1 ) ;
F_44 ( V_85 , & V_2 -> V_4 [ 13 ] , 3 ) ;
V_53 = V_38 ;
} else if ( F_56 ( V_2 ) ) {
F_17 ( L_27 ) ;
F_44 ( V_85 , & V_2 -> V_4 [ 1 ] , 1 ) ;
F_44 ( V_85 , & V_2 -> V_4 [ 11 ] , 5 ) ;
V_53 = V_36 ;
} else {
F_17 ( L_28 ) ;
F_44 ( V_85 , V_2 -> V_4 , 16 ) ;
V_53 = V_34 ;
}
return V_53 ;
}
int F_57 ( struct V_30 * V_31 , const struct V_16 * V_17 ,
const void * V_58 , const void * V_59 )
{
T_1 V_61 , V_62 , * V_85 , V_63 = 0 ;
struct V_45 * V_46 ;
T_1 V_92 [ V_93 ] = {} ;
struct V_15 * V_94 , * V_95 , V_96 , V_97 ;
int V_19 , V_98 , V_99 ;
if ( V_31 -> V_100 != F_37 ( V_101 ) )
return - V_43 ;
V_46 = F_58 ( V_31 ) ;
V_85 = V_92 + 2 ;
F_17 ( L_29
L_30 ,
V_46 -> V_68 , F_39 ( V_46 -> V_84 ) , V_46 -> V_72 ,
V_46 -> V_75 , & V_46 -> V_58 ) ;
F_28 ( V_65 , L_31 ,
F_59 ( V_31 ) , sizeof( struct V_45 ) ) ;
V_61 = V_102 ;
V_62 = 0 ;
F_18 ( V_65 , L_32 , V_59 , V_5 ) ;
F_18 ( V_65 , L_33 , V_58 , V_5 ) ;
F_28 ( V_65 , L_34 ,
V_31 -> V_66 , V_31 -> V_67 ) ;
V_98 = F_60 ( & V_46 -> V_58 ) ;
F_29 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
if ( V_98 & V_103 )
V_94 = F_13 ( V_17 , & V_46 -> V_58 ) ;
else
V_94 = F_9 ( V_17 , & V_46 -> V_58 ) ;
if ( V_94 ) {
memcpy ( & V_96 , V_94 , sizeof( * V_94 ) ) ;
V_63 |= V_94 -> V_18 ;
}
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
F_29 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
V_95 = F_9 ( V_17 , & V_46 -> V_59 ) ;
if ( V_95 ) {
memcpy ( & V_97 , V_95 , sizeof( * V_95 ) ) ;
V_63 |= ( V_95 -> V_18 << 4 ) ;
}
F_31 ( & F_7 ( V_17 ) -> V_20 . V_78 ) ;
if ( V_63 ) {
V_62 |= V_69 ;
F_44 ( & V_85 , & V_63 , sizeof( V_63 ) ) ;
}
V_61 |= F_51 ( & V_85 , V_46 ) ;
V_19 = F_61 ( V_31 , V_46 , & V_85 ) ;
if ( V_19 == - V_104 )
F_44 ( & V_85 , & V_46 -> V_72 ,
sizeof( V_46 -> V_72 ) ) ;
else
V_61 |= V_71 ;
switch ( V_46 -> V_75 ) {
case 1 :
V_61 |= V_105 ;
break;
case 64 :
V_61 |= V_106 ;
break;
case 255 :
V_61 |= V_107 ;
break;
default:
F_44 ( & V_85 , & V_46 -> V_75 ,
sizeof( V_46 -> V_75 ) ) ;
}
V_99 = F_60 ( & V_46 -> V_59 ) ;
if ( V_99 == V_108 ) {
F_17 ( L_35 ) ;
V_62 |= V_77 ;
} else {
if ( V_95 ) {
V_62 |= F_43 ( & V_85 , & V_46 -> V_59 ,
& V_97 , V_59 ,
true ) ;
V_62 |= V_77 ;
} else {
if ( V_99 & V_109 ) {
V_62 |= F_46 ( & V_85 ,
& V_46 -> V_59 ,
V_59 , true ) ;
F_17 ( L_36 ,
& V_46 -> V_59 , V_62 ) ;
} else {
F_17 ( L_37 ) ;
F_44 ( & V_85 ,
V_46 -> V_59 . V_4 , 16 ) ;
}
}
}
if ( V_98 & V_103 ) {
F_17 ( L_38 ) ;
V_62 |= V_80 ;
if ( V_94 ) {
V_62 |= F_52 ( & V_85 ,
& V_96 ,
& V_46 -> V_58 ) ;
V_62 |= V_81 ;
} else {
V_62 |= F_53 ( & V_85 ,
& V_46 -> V_58 ) ;
}
} else {
if ( V_94 ) {
V_62 |= F_43 ( & V_85 , & V_46 -> V_58 ,
& V_96 , V_58 ,
false ) ;
V_62 |= V_81 ;
} else {
if ( V_98 & V_109 ) {
V_62 |= F_46 ( & V_85 ,
& V_46 -> V_58 ,
V_58 , false ) ;
F_17 ( L_39 ,
& V_46 -> V_58 , V_62 ) ;
} else {
F_17 ( L_40 ,
& V_46 -> V_58 ) ;
F_44 ( & V_85 ,
V_46 -> V_58 . V_4 , 16 ) ;
}
}
}
if ( V_61 & V_71 ) {
V_19 = F_62 ( V_31 , V_46 , & V_85 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_92 [ 0 ] = V_61 ;
V_92 [ 1 ] = V_62 ;
F_63 ( V_31 , sizeof( struct V_45 ) ) ;
F_64 ( V_31 ) ;
memcpy ( F_40 ( V_31 , V_85 - V_92 ) , V_92 , V_85 - V_92 ) ;
F_41 ( V_31 ) ;
F_17 ( L_41 , ( int ) ( V_85 - V_92 ) , V_31 -> V_67 ) ;
F_28 ( V_65 , L_42 ,
V_31 -> V_66 , V_31 -> V_67 ) ;
return 0 ;
}
