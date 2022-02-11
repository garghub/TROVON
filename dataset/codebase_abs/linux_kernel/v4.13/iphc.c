static inline void
F_1 ( struct V_1 * V_2 ,
const void * V_3 )
{
const struct V_4 * V_5 = V_3 ;
T_1 V_6 [ V_7 ] ;
switch ( V_5 -> V_8 ) {
case V_9 :
F_2 ( V_6 , & V_5 -> V_10 ) ;
F_3 ( V_2 , V_6 ) ;
break;
case V_11 :
V_2 -> V_12 [ 0 ] = 0xFE ;
V_2 -> V_12 [ 1 ] = 0x80 ;
V_2 -> V_12 [ 11 ] = 0xFF ;
V_2 -> V_12 [ 12 ] = 0xFE ;
F_4 ( & V_2 -> V_13 [ 7 ] ,
& V_5 -> V_14 ) ;
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
const struct V_1 * V_5 )
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
F_11 ( & V_22 , V_5 , V_21 [ V_24 ] . V_26 ) ;
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
const struct V_1 * V_5 )
{
struct V_15 * V_21 = F_7 ( V_17 ) -> V_20 . V_21 ;
struct V_15 * V_19 = NULL ;
struct V_1 V_28 , V_29 = {} ;
int V_24 ;
memcpy ( & V_28 , V_5 , sizeof( * V_5 ) ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( ! F_8 ( & V_21 [ V_24 ] ) ||
! F_10 ( & V_21 [ V_24 ] ) )
continue;
V_28 . V_12 [ 3 ] = V_21 [ V_24 ] . V_26 ;
F_11 ( & V_29 , & V_21 [ V_24 ] . V_27 ,
V_21 [ V_24 ] . V_26 ) ;
memcpy ( & V_28 . V_12 [ 4 ] , & V_29 , 8 ) ;
if ( F_14 ( V_5 , & V_28 ) ) {
V_19 = & V_21 [ V_24 ] ;
break;
}
}
return V_19 ;
}
static void F_15 ( const struct V_16 * V_17 ,
struct V_1 * V_2 ,
const void * V_3 )
{
switch ( V_17 -> V_30 ) {
case V_31 :
F_16 ( V_2 , V_3 ) ;
break;
case V_7 :
F_3 ( V_2 , V_3 ) ;
break;
default:
F_5 ( 1 ) ;
break;
}
}
static int F_17 ( struct V_32 * V_33 ,
const struct V_16 * V_17 ,
struct V_1 * V_2 ,
T_1 V_34 , const void * V_3 )
{
bool V_35 ;
switch ( V_34 ) {
case V_36 :
V_35 = F_18 ( V_33 , V_2 -> V_12 , 16 ) ;
break;
case V_37 :
case V_38 :
V_2 -> V_12 [ 0 ] = 0xFE ;
V_2 -> V_12 [ 1 ] = 0x80 ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 8 ] , 8 ) ;
break;
case V_39 :
case V_40 :
V_2 -> V_12 [ 0 ] = 0xFE ;
V_2 -> V_12 [ 1 ] = 0x80 ;
V_2 -> V_12 [ 11 ] = 0xFF ;
V_2 -> V_12 [ 12 ] = 0xFE ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 14 ] , 2 ) ;
break;
case V_41 :
case V_42 :
V_35 = false ;
switch ( F_7 ( V_17 ) -> V_43 ) {
case V_44 :
F_1 ( V_2 , V_3 ) ;
break;
default:
F_15 ( V_17 , V_2 , V_3 ) ;
break;
}
break;
default:
F_19 ( L_1 , V_34 ) ;
return - V_45 ;
}
if ( V_35 ) {
F_19 ( L_2 ) ;
return - V_46 ;
}
F_20 ( NULL , L_3 ,
V_2 -> V_12 , 16 ) ;
return 0 ;
}
static int F_21 ( struct V_32 * V_33 ,
const struct V_16 * V_17 ,
const struct V_15 * V_20 ,
struct V_1 * V_2 ,
T_1 V_34 , const void * V_3 )
{
bool V_35 ;
switch ( V_34 ) {
case V_36 :
V_35 = false ;
break;
case V_37 :
case V_38 :
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 8 ] , 8 ) ;
F_22 ( V_2 , & V_20 -> V_27 , V_20 -> V_26 ) ;
break;
case V_39 :
case V_40 :
V_2 -> V_12 [ 11 ] = 0xFF ;
V_2 -> V_12 [ 12 ] = 0xFE ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 14 ] , 2 ) ;
F_22 ( V_2 , & V_20 -> V_27 , V_20 -> V_26 ) ;
break;
case V_41 :
case V_42 :
V_35 = false ;
switch ( F_7 ( V_17 ) -> V_43 ) {
case V_44 :
F_1 ( V_2 , V_3 ) ;
break;
default:
F_15 ( V_17 , V_2 , V_3 ) ;
break;
}
F_22 ( V_2 , & V_20 -> V_27 , V_20 -> V_26 ) ;
break;
default:
F_19 ( L_4 , V_34 ) ;
return - V_45 ;
}
if ( V_35 ) {
F_19 ( L_2 ) ;
return - V_46 ;
}
F_20 ( NULL ,
L_5 ,
V_2 -> V_12 , 16 ) ;
return 0 ;
}
static int F_23 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
T_1 V_34 )
{
bool V_35 ;
switch ( V_34 ) {
case V_36 :
V_35 = F_18 ( V_33 , V_2 -> V_12 , 16 ) ;
break;
case V_38 :
V_2 -> V_12 [ 0 ] = 0xFF ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 1 ] , 1 ) ;
V_35 |= F_18 ( V_33 , & V_2 -> V_12 [ 11 ] , 5 ) ;
break;
case V_40 :
V_2 -> V_12 [ 0 ] = 0xFF ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 1 ] , 1 ) ;
V_35 |= F_18 ( V_33 , & V_2 -> V_12 [ 13 ] , 3 ) ;
break;
case V_42 :
V_2 -> V_12 [ 0 ] = 0xFF ;
V_2 -> V_12 [ 1 ] = 0x02 ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 15 ] , 1 ) ;
break;
default:
F_19 ( L_6 , V_34 ) ;
return - V_45 ;
}
if ( V_35 ) {
F_19 ( L_2 ) ;
return - V_46 ;
}
F_20 ( NULL , L_7 ,
V_2 -> V_12 , 16 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_33 ,
struct V_15 * V_20 ,
struct V_1 * V_2 ,
T_1 V_34 )
{
struct V_1 V_29 = {} ;
bool V_35 ;
V_2 -> V_12 [ 0 ] = 0xFF ;
V_35 = F_18 ( V_33 , & V_2 -> V_12 [ 1 ] , 2 ) ;
V_35 |= F_18 ( V_33 , & V_2 -> V_12 [ 12 ] , 4 ) ;
if ( V_35 )
return - V_46 ;
V_2 -> V_12 [ 3 ] = V_20 -> V_26 ;
F_11 ( & V_29 , & V_20 -> V_27 , V_20 -> V_26 ) ;
memcpy ( & V_2 -> V_12 [ 4 ] , & V_29 , 8 ) ;
return 0 ;
}
static inline void F_25 ( struct V_47 * V_48 , const T_1 * V_49 )
{
T_1 V_50 = V_49 [ 0 ] & 0xc0 ;
V_48 -> V_51 [ 0 ] |= ( V_50 >> 2 ) ;
}
static inline void F_26 ( struct V_47 * V_48 , const T_1 * V_49 )
{
T_1 V_52 = V_49 [ 0 ] & 0x3f ;
V_48 -> V_53 |= ( ( V_52 & 0x3c ) >> 2 ) ;
V_48 -> V_51 [ 0 ] |= ( ( V_52 & 0x03 ) << 6 ) ;
}
static inline void F_27 ( struct V_47 * V_48 , const T_1 * V_54 )
{
V_48 -> V_51 [ 0 ] |= V_54 [ 0 ] & 0x0f ;
memcpy ( & V_48 -> V_51 [ 1 ] , & V_54 [ 1 ] , 2 ) ;
}
static int F_28 ( struct V_32 * V_33 , struct V_47 * V_48 ,
T_1 V_55 )
{
T_1 V_49 [ 4 ] ;
switch ( V_55 ) {
case V_56 :
if ( F_18 ( V_33 , V_49 , 4 ) )
return - V_45 ;
F_25 ( V_48 , V_49 ) ;
F_26 ( V_48 , V_49 ) ;
F_27 ( V_48 , & V_49 [ 1 ] ) ;
break;
case V_57 :
if ( F_18 ( V_33 , V_49 , 3 ) )
return - V_45 ;
F_25 ( V_48 , V_49 ) ;
F_27 ( V_48 , & V_49 [ 0 ] ) ;
break;
case V_58 :
if ( F_18 ( V_33 , V_49 , 1 ) )
return - V_45 ;
F_25 ( V_48 , V_49 ) ;
F_26 ( V_48 , V_49 ) ;
break;
case V_59 :
break;
default:
F_5 ( 1 ) ;
return - V_45 ;
}
return 0 ;
}
int F_29 ( struct V_32 * V_33 , const struct V_16 * V_17 ,
const void * V_60 , const void * V_61 )
{
struct V_47 V_48 = {} ;
struct V_15 * V_62 ;
T_1 V_63 , V_64 , V_65 = 0 ;
int V_66 ;
F_30 ( V_67 , L_8 ,
V_33 -> V_68 , V_33 -> V_69 ) ;
if ( F_18 ( V_33 , & V_63 , sizeof( V_63 ) ) ||
F_18 ( V_33 , & V_64 , sizeof( V_64 ) ) )
return - V_45 ;
V_48 . V_70 = 6 ;
if ( V_64 & V_71 ) {
if ( F_18 ( V_33 , & V_65 , sizeof( V_65 ) ) )
return - V_45 ;
}
V_66 = F_28 ( V_33 , & V_48 ,
V_63 & V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! ( V_63 & V_73 ) ) {
if ( F_18 ( V_33 , & V_48 . V_74 , sizeof( V_48 . V_74 ) ) )
return - V_45 ;
F_19 ( L_9 ,
V_48 . V_74 ) ;
}
if ( ( V_63 & V_75 ) != V_76 ) {
V_48 . V_77 = V_78 [ V_63 & V_75 ] ;
} else {
if ( F_18 ( V_33 , & V_48 . V_77 ,
sizeof( V_48 . V_77 ) ) )
return - V_45 ;
}
if ( V_64 & V_79 ) {
F_31 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
V_62 = F_6 ( V_17 , F_32 ( V_65 ) ) ;
if ( ! V_62 ) {
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
return - V_45 ;
}
F_19 ( L_10 ) ;
V_66 = F_21 ( V_33 , V_17 , V_62 , & V_48 . V_61 ,
V_64 & V_81 ,
V_61 ) ;
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
} else {
F_19 ( L_11 ) ;
V_66 = F_17 ( V_33 , V_17 , & V_48 . V_61 ,
V_64 & V_81 ,
V_61 ) ;
}
if ( V_66 )
return - V_45 ;
switch ( V_64 & ( V_82 | V_83 ) ) {
case V_82 | V_83 :
V_33 -> V_84 = V_85 ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
V_62 = F_6 ( V_17 , F_34 ( V_65 ) ) ;
if ( ! V_62 ) {
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
return - V_45 ;
}
F_19 ( L_12 ) ;
V_66 = F_24 ( V_33 , V_62 ,
& V_48 . V_60 ,
V_64 & V_86 ) ;
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
break;
case V_82 :
V_33 -> V_84 = V_85 ;
V_66 = F_23 ( V_33 , & V_48 . V_60 ,
V_64 & V_86 ) ;
break;
case V_83 :
V_33 -> V_84 = V_87 ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
V_62 = F_6 ( V_17 , F_34 ( V_65 ) ) ;
if ( ! V_62 ) {
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
return - V_45 ;
}
F_19 ( L_13 ) ;
V_66 = F_21 ( V_33 , V_17 , V_62 , & V_48 . V_60 ,
V_64 & V_86 ,
V_60 ) ;
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
break;
default:
V_33 -> V_84 = V_87 ;
V_66 = F_17 ( V_33 , V_17 , & V_48 . V_60 ,
V_64 & V_86 ,
V_60 ) ;
F_19 ( L_14 ,
V_64 & V_86 , & V_48 . V_60 ) ;
break;
}
if ( V_66 )
return - V_45 ;
if ( V_63 & V_73 ) {
V_66 = F_35 ( V_33 , V_17 , & V_48 ) ;
if ( V_66 < 0 )
return V_66 ;
} else {
V_66 = F_36 ( V_33 , sizeof( V_48 ) ) ;
if ( F_37 ( V_66 ) )
return V_66 ;
}
switch ( F_7 ( V_17 ) -> V_43 ) {
case V_44 :
if ( F_38 ( V_33 ) -> V_88 )
V_48 . V_89 = F_39 ( F_38 ( V_33 ) -> V_88 -
sizeof( struct V_47 ) ) ;
else
V_48 . V_89 = F_39 ( V_33 -> V_69 ) ;
break;
default:
V_48 . V_89 = F_39 ( V_33 -> V_69 ) ;
break;
}
F_19 ( L_15 ,
F_40 ( V_33 ) , V_33 -> V_69 ) ;
F_19 ( L_16
L_17 ,
V_48 . V_70 , F_41 ( V_48 . V_89 ) , V_48 . V_74 ,
V_48 . V_77 , & V_48 . V_60 ) ;
F_42 ( V_33 , sizeof( V_48 ) ) ;
F_43 ( V_33 ) ;
F_44 ( V_33 , & V_48 , sizeof( V_48 ) ) ;
F_30 ( V_67 , L_18 , ( T_1 * ) & V_48 , sizeof( V_48 ) ) ;
return 0 ;
}
static inline bool
F_45 ( const struct V_1 * V_2 ,
const struct V_15 * V_20 ,
const void * V_3 )
{
const struct V_4 * V_5 = V_3 ;
unsigned char V_10 [ V_7 ] ;
bool V_90 = false ;
struct V_1 V_91 = {} ;
switch ( V_5 -> V_8 ) {
case V_9 :
F_2 ( & V_10 , & V_5 -> V_10 ) ;
memcpy ( & V_91 . V_12 [ 8 ] , & V_10 , V_7 ) ;
V_91 . V_12 [ 8 ] ^= 0x02 ;
F_22 ( & V_91 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_91 , V_2 ) )
V_90 = true ;
break;
case V_11 :
V_91 . V_12 [ 11 ] = 0xFF ;
V_91 . V_12 [ 12 ] = 0xFE ;
F_4 ( & V_91 . V_13 [ 7 ] ,
& V_5 -> V_14 ) ;
F_22 ( & V_91 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_91 , V_2 ) )
V_90 = true ;
break;
default:
F_5 ( 1 ) ;
break;
}
return V_90 ;
}
static bool F_46 ( const struct V_16 * V_17 ,
const struct V_15 * V_20 ,
const struct V_1 * V_2 ,
const void * V_3 )
{
struct V_1 V_91 = {} ;
F_15 ( V_17 , & V_91 , V_3 ) ;
if ( V_20 )
F_22 ( & V_91 , & V_20 -> V_27 , V_20 -> V_26 ) ;
return F_14 ( & V_91 , V_2 ) ;
}
static T_1 F_47 ( T_1 * * V_92 , const struct V_16 * V_17 ,
const struct V_1 * V_2 ,
const struct V_15 * V_20 ,
const unsigned char * V_3 , bool V_93 )
{
struct V_1 V_91 = {} ;
T_1 V_94 ;
switch ( F_7 ( V_17 ) -> V_43 ) {
case V_44 :
if ( F_45 ( V_2 , V_20 ,
V_3 ) ) {
V_94 = V_42 ;
goto V_95;
}
break;
default:
if ( F_46 ( V_17 , V_20 , V_2 , V_3 ) ) {
V_94 = V_42 ;
goto V_95;
}
break;
}
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_12 [ 11 ] = 0xFF ;
V_91 . V_12 [ 12 ] = 0xFE ;
memcpy ( & V_91 . V_12 [ 14 ] , & V_2 -> V_12 [ 14 ] , 2 ) ;
F_22 ( & V_91 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_91 , V_2 ) ) {
F_48 ( V_92 , & V_2 -> V_12 [ 14 ] , 2 ) ;
V_94 = V_40 ;
goto V_95;
}
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
memcpy ( & V_91 . V_12 [ 8 ] , & V_2 -> V_12 [ 8 ] , 8 ) ;
F_22 ( & V_91 , & V_20 -> V_27 , V_20 -> V_26 ) ;
if ( F_14 ( & V_91 , V_2 ) ) {
F_48 ( V_92 , & V_2 -> V_12 [ 8 ] , 8 ) ;
V_94 = V_38 ;
goto V_95;
}
F_49 ( 1 , L_19 ) ;
return V_36 ;
V_95:
if ( V_93 )
return V_96 [ V_94 ] ;
else
return V_94 ;
}
static inline bool
F_50 ( const struct V_1 * V_2 ,
const void * V_3 )
{
const struct V_4 * V_5 = V_3 ;
unsigned char V_10 [ V_7 ] ;
bool V_90 = false ;
struct V_1 V_91 = {} ;
switch ( V_5 -> V_8 ) {
case V_9 :
F_2 ( & V_10 , & V_5 -> V_10 ) ;
if ( F_51 ( V_2 , V_10 ) )
V_90 = true ;
break;
case V_11 :
V_91 . V_12 [ 0 ] = 0xFE ;
V_91 . V_12 [ 1 ] = 0x80 ;
V_91 . V_12 [ 11 ] = 0xFF ;
V_91 . V_12 [ 12 ] = 0xFE ;
F_4 ( & V_91 . V_13 [ 7 ] ,
& V_5 -> V_14 ) ;
if ( F_14 ( & V_91 , V_2 ) )
V_90 = true ;
break;
default:
F_5 ( 1 ) ;
break;
}
return V_90 ;
}
static T_1 F_52 ( T_1 * * V_92 , const struct V_16 * V_17 ,
const struct V_1 * V_2 ,
const unsigned char * V_3 , bool V_93 )
{
T_1 V_94 = V_38 ;
switch ( F_7 ( V_17 ) -> V_43 ) {
case V_44 :
if ( F_50 ( V_2 , V_3 ) ) {
V_94 = V_42 ;
F_19 ( L_20 ) ;
goto V_95;
}
break;
default:
if ( F_46 ( V_17 , NULL , V_2 , V_3 ) ) {
V_94 = V_42 ;
F_19 ( L_20 ) ;
goto V_95;
}
break;
}
if ( F_53 ( V_2 ) ) {
F_48 ( V_92 , & V_2 -> V_13 [ 7 ] , 2 ) ;
V_94 = V_40 ;
F_20 ( NULL , L_21 ,
* V_92 - 2 , 2 ) ;
goto V_95;
}
F_48 ( V_92 , & V_2 -> V_13 [ 4 ] , 8 ) ;
F_20 ( NULL , L_22 ,
* V_92 - 8 , 8 ) ;
V_95:
if ( V_93 )
return V_96 [ V_94 ] ;
else
return V_94 ;
}
static inline T_1 F_54 ( const struct V_47 * V_48 )
{
T_1 V_52 , V_50 ;
V_52 = ( V_48 -> V_53 << 2 ) | ( ( V_48 -> V_51 [ 0 ] & 0xc0 ) >> 6 ) ;
V_50 = ( V_48 -> V_51 [ 0 ] & 0x30 ) ;
F_19 ( L_23 , V_50 >> 4 , V_52 ) ;
return ( V_50 << 2 ) | V_52 ;
}
static inline bool F_55 ( const struct V_47 * V_48 )
{
return ( ( ! ( V_48 -> V_51 [ 0 ] & 0x0f ) ) &&
! V_48 -> V_51 [ 1 ] && ! V_48 -> V_51 [ 2 ] ) ;
}
static T_1 F_56 ( T_1 * * V_92 , const struct V_47 * V_48 )
{
T_1 V_97 = F_54 ( V_48 ) , V_49 [ 4 ] , V_55 ;
F_19 ( L_24 , V_97 ) ;
if ( F_55 ( V_48 ) ) {
if ( ! V_97 ) {
V_55 = V_59 ;
} else {
F_48 ( V_92 , & V_97 , sizeof( V_97 ) ) ;
V_55 = V_58 ;
}
} else {
if ( ! ( V_97 & 0x3f ) ) {
memcpy ( & V_49 [ 0 ] , & V_48 -> V_51 [ 0 ] , 3 ) ;
V_49 [ 0 ] &= ~ 0xf0 ;
V_49 [ 0 ] |= ( V_97 & 0xc0 ) ;
F_48 ( V_92 , V_49 , 3 ) ;
V_55 = V_57 ;
} else {
memcpy ( & V_49 [ 0 ] , & V_97 , sizeof( V_97 ) ) ;
memcpy ( & V_49 [ 1 ] , & V_48 -> V_51 [ 0 ] , 3 ) ;
V_49 [ 1 ] &= ~ 0xf0 ;
F_48 ( V_92 , V_49 , 4 ) ;
V_55 = V_56 ;
}
}
return V_55 ;
}
static T_1 F_57 ( T_1 * * V_92 ,
const struct V_15 * V_20 ,
const struct V_1 * V_2 )
{
T_1 V_68 [ 6 ] ;
memcpy ( V_68 , & V_2 -> V_12 [ 1 ] , 2 ) ;
memcpy ( & V_68 [ 1 ] , & V_2 -> V_12 [ 11 ] , 4 ) ;
F_48 ( V_92 , V_68 , 6 ) ;
return V_36 ;
}
static T_1 F_58 ( T_1 * * V_92 ,
const struct V_1 * V_2 )
{
T_1 V_55 ;
if ( F_59 ( V_2 ) ) {
F_19 ( L_25 ) ;
F_48 ( V_92 , & V_2 -> V_12 [ 15 ] , 1 ) ;
V_55 = V_42 ;
} else if ( F_60 ( V_2 ) ) {
F_19 ( L_26 ) ;
F_48 ( V_92 , & V_2 -> V_12 [ 1 ] , 1 ) ;
F_48 ( V_92 , & V_2 -> V_12 [ 13 ] , 3 ) ;
V_55 = V_40 ;
} else if ( F_61 ( V_2 ) ) {
F_19 ( L_27 ) ;
F_48 ( V_92 , & V_2 -> V_12 [ 1 ] , 1 ) ;
F_48 ( V_92 , & V_2 -> V_12 [ 11 ] , 5 ) ;
V_55 = V_38 ;
} else {
F_19 ( L_28 ) ;
F_48 ( V_92 , V_2 -> V_12 , 16 ) ;
V_55 = V_36 ;
}
return V_55 ;
}
int F_62 ( struct V_32 * V_33 , const struct V_16 * V_17 ,
const void * V_60 , const void * V_61 )
{
T_1 V_63 , V_64 , * V_92 , V_65 = 0 ;
struct V_47 * V_48 ;
T_1 V_98 [ V_99 ] = {} ;
struct V_15 * V_100 , * V_101 , V_102 , V_103 ;
int V_19 , V_104 , V_105 ;
if ( V_33 -> V_106 != F_39 ( V_107 ) )
return - V_45 ;
V_48 = F_63 ( V_33 ) ;
V_92 = V_98 + 2 ;
F_19 ( L_29
L_30 ,
V_48 -> V_70 , F_41 ( V_48 -> V_89 ) , V_48 -> V_74 ,
V_48 -> V_77 , & V_48 -> V_60 ) ;
F_30 ( V_67 , L_31 ,
F_64 ( V_33 ) , sizeof( struct V_47 ) ) ;
V_63 = V_108 ;
V_64 = 0 ;
F_30 ( V_67 , L_32 ,
V_33 -> V_68 , V_33 -> V_69 ) ;
V_104 = F_65 ( & V_48 -> V_60 ) ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
if ( V_104 & V_109 )
V_100 = F_13 ( V_17 , & V_48 -> V_60 ) ;
else
V_100 = F_9 ( V_17 , & V_48 -> V_60 ) ;
if ( V_100 ) {
memcpy ( & V_102 , V_100 , sizeof( * V_100 ) ) ;
V_65 |= V_100 -> V_18 ;
}
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
F_31 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
V_101 = F_9 ( V_17 , & V_48 -> V_61 ) ;
if ( V_101 ) {
memcpy ( & V_103 , V_101 , sizeof( * V_101 ) ) ;
V_65 |= ( V_101 -> V_18 << 4 ) ;
}
F_33 ( & F_7 ( V_17 ) -> V_20 . V_80 ) ;
if ( V_65 ) {
V_64 |= V_71 ;
F_48 ( & V_92 , & V_65 , sizeof( V_65 ) ) ;
}
V_63 |= F_56 ( & V_92 , V_48 ) ;
V_19 = F_66 ( V_33 , V_48 , & V_92 ) ;
if ( V_19 == - V_110 )
F_48 ( & V_92 , & V_48 -> V_74 ,
sizeof( V_48 -> V_74 ) ) ;
else
V_63 |= V_73 ;
switch ( V_48 -> V_77 ) {
case 1 :
V_63 |= V_111 ;
break;
case 64 :
V_63 |= V_112 ;
break;
case 255 :
V_63 |= V_113 ;
break;
default:
F_48 ( & V_92 , & V_48 -> V_77 ,
sizeof( V_48 -> V_77 ) ) ;
}
V_105 = F_65 ( & V_48 -> V_61 ) ;
if ( V_105 == V_114 ) {
F_19 ( L_33 ) ;
V_64 |= V_79 ;
} else {
if ( V_101 ) {
V_64 |= F_47 ( & V_92 , V_17 ,
& V_48 -> V_61 ,
& V_103 , V_61 ,
true ) ;
V_64 |= V_79 ;
} else {
if ( V_105 & V_115 &&
F_67 ( V_48 -> V_61 ) ) {
V_64 |= F_52 ( & V_92 , V_17 ,
& V_48 -> V_61 ,
V_61 , true ) ;
F_19 ( L_34 ,
& V_48 -> V_61 , V_64 ) ;
} else {
F_19 ( L_35 ) ;
F_48 ( & V_92 ,
V_48 -> V_61 . V_12 , 16 ) ;
}
}
}
if ( V_104 & V_109 ) {
F_19 ( L_36 ) ;
V_64 |= V_82 ;
if ( V_100 ) {
V_64 |= F_57 ( & V_92 ,
& V_102 ,
& V_48 -> V_60 ) ;
V_64 |= V_83 ;
} else {
V_64 |= F_58 ( & V_92 ,
& V_48 -> V_60 ) ;
}
} else {
if ( V_100 ) {
V_64 |= F_47 ( & V_92 , V_17 ,
& V_48 -> V_60 ,
& V_102 , V_60 ,
false ) ;
V_64 |= V_83 ;
} else {
if ( V_104 & V_115 &&
F_67 ( V_48 -> V_60 ) ) {
V_64 |= F_52 ( & V_92 , V_17 ,
& V_48 -> V_60 ,
V_60 , false ) ;
F_19 ( L_37 ,
& V_48 -> V_60 , V_64 ) ;
} else {
F_19 ( L_38 ,
& V_48 -> V_60 ) ;
F_48 ( & V_92 ,
V_48 -> V_60 . V_12 , 16 ) ;
}
}
}
if ( V_63 & V_73 ) {
V_19 = F_68 ( V_33 , V_48 , & V_92 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_98 [ 0 ] = V_63 ;
V_98 [ 1 ] = V_64 ;
F_69 ( V_33 , sizeof( struct V_47 ) ) ;
F_70 ( V_33 ) ;
memcpy ( F_42 ( V_33 , V_92 - V_98 ) , V_98 , V_92 - V_98 ) ;
F_43 ( V_33 ) ;
F_19 ( L_39 , ( int ) ( V_92 - V_98 ) , V_33 -> V_69 ) ;
F_30 ( V_67 , L_40 ,
V_33 -> V_68 , V_33 -> V_69 ) ;
return 0 ;
}
