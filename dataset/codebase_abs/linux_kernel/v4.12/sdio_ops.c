static void F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_2 * V_5
)
{
switch ( V_3 ) {
case V_6 :
* V_5 = ( ( V_6 << 13 ) | ( V_4 & V_7 ) ) ;
break;
case V_8 :
* V_5 = ( ( V_8 << 13 ) | ( V_4 & V_9 ) ) ;
break;
case V_10 :
* V_5 = ( ( V_10 << 13 ) | ( V_4 & V_11 ) ) ;
break;
case V_12 :
* V_5 = ( ( V_12 << 13 ) | ( V_4 & V_11 ) ) ;
break;
case V_13 :
* V_5 = ( ( V_13 << 13 ) | ( V_4 & V_11 ) ) ;
break;
case V_14 :
* V_5 = ( ( V_14 << 13 ) | ( V_4 & V_15 ) ) ;
break;
default:
break;
}
}
static T_1 F_2 ( T_2 V_16 )
{
T_1 V_17 ;
T_3 V_18 ;
V_18 = ( T_3 ) ( V_16 >> 16 ) ;
switch ( V_18 ) {
case 0x1025 :
V_17 = V_6 ;
break;
case 0x1026 :
V_17 = V_8 ;
break;
case 0x1031 :
V_17 = V_10 ;
break;
case 0x1032 :
V_17 = V_12 ;
break;
case 0x1033 :
V_17 = V_13 ;
break;
case 0x1034 :
V_17 = V_14 ;
break;
default:
V_17 = V_8 ;
break;
}
return V_17 ;
}
static T_2 F_3 ( const T_2 V_16 , T_1 * V_19 , T_3 * V_20 )
{
T_1 V_21 ;
T_3 V_22 ;
T_2 V_23 ;
V_21 = F_2 ( V_16 ) ;
V_22 = 0 ;
switch ( V_21 ) {
case V_6 :
V_22 = V_16 & V_7 ;
break;
case V_10 :
case V_12 :
case V_13 :
V_22 = V_16 & V_11 ;
break;
case V_14 :
V_22 = V_16 & V_15 ;
break;
case V_8 :
default:
V_21 = V_8 ;
V_22 = V_16 & V_9 ;
break;
}
V_23 = ( V_21 << 13 ) | V_22 ;
if ( V_19 )
* V_19 = V_21 ;
if ( V_20 )
* V_20 = V_22 ;
return V_23 ;
}
static T_1 F_4 ( struct V_24 * V_25 , T_2 V_16 )
{
T_2 V_23 ;
T_1 V_26 ;
V_23 = F_3 ( V_16 , NULL , NULL ) ;
V_26 = F_5 ( V_25 , V_23 , NULL ) ;
return V_26 ;
}
static T_3 F_6 ( struct V_24 * V_25 , T_2 V_16 )
{
T_2 V_23 ;
T_3 V_26 ;
T_4 V_27 ;
V_23 = F_3 ( V_16 , NULL , NULL ) ;
F_7 ( V_25 , V_23 , 2 , ( T_1 * ) & V_27 ) ;
V_26 = F_8 ( V_27 ) ;
return V_26 ;
}
static T_2 F_9 ( struct V_24 * V_25 , T_2 V_16 )
{
struct V_1 * V_2 ;
T_1 V_28 ;
T_1 V_21 ;
T_3 V_22 ;
T_2 V_23 ;
T_1 V_29 ;
T_2 V_26 ;
T_5 V_30 ;
T_6 V_27 ;
V_2 = V_25 -> V_2 ;
V_23 = F_3 ( V_16 , & V_21 , & V_22 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if (
( ( V_21 == V_8 ) && ( V_22 < 0x100 ) ) ||
( false == V_28 ) ||
( true == F_11 ( V_2 ) -> V_32 )
) {
V_30 = F_7 ( V_25 , V_23 , 4 , ( T_1 * ) & V_27 ) ;
#ifdef F_12
if ( ! V_30 ) {
#endif
V_26 = F_13 ( V_27 ) ;
return V_26 ;
#ifdef F_12
}
F_14 ( V_33 L_1 , V_34 , V_30 , V_16 ) ;
return V_35 ;
#endif
}
V_29 = V_23 & 0x3 ;
if ( V_29 == 0 ) {
V_26 = F_15 ( V_25 , V_23 , NULL ) ;
} else {
T_1 * V_36 ;
V_36 = ( T_1 * ) F_16 ( 8 ) ;
if ( NULL == V_36 ) {
F_14 ( V_33 L_2 , V_34 , V_16 ) ;
return V_35 ;
}
V_23 &= ~ ( T_3 ) 0x3 ;
F_17 ( V_25 , V_23 , 8 , V_36 ) ;
memcpy ( & V_27 , V_36 + V_29 , 4 ) ;
V_26 = F_13 ( V_27 ) ;
F_18 ( V_36 ) ;
}
return V_26 ;
}
static T_5 F_19 ( struct V_24 * V_25 , T_2 V_16 , T_2 V_37 , T_1 * V_38 )
{
struct V_1 * V_2 ;
T_1 V_28 ;
T_1 V_21 ;
T_3 V_22 ;
T_2 V_23 ;
T_1 V_29 ;
T_5 V_30 ;
V_2 = V_25 -> V_2 ;
V_30 = 0 ;
V_23 = F_3 ( V_16 , & V_21 , & V_22 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if (
( ( V_21 == V_8 ) && ( V_22 < 0x100 ) ) ||
( false == V_28 ) ||
( true == F_11 ( V_2 ) -> V_32 )
) {
V_30 = F_7 ( V_25 , V_23 , V_37 , V_38 ) ;
return V_30 ;
}
V_29 = V_23 & 0x3 ;
if ( V_29 == 0 ) {
V_30 = F_17 ( V_25 , V_23 , V_37 , V_38 ) ;
} else {
T_1 * V_36 ;
T_2 V_39 ;
V_23 &= ~ ( T_3 ) 0x3 ;
V_39 = V_37 + V_29 ;
V_36 = F_16 ( V_39 ) ;
if ( NULL == V_36 )
return - 1 ;
V_30 = F_17 ( V_25 , V_23 , V_39 , V_36 ) ;
if ( ! V_30 )
memcpy ( V_38 , V_36 + V_29 , V_37 ) ;
F_18 ( V_36 ) ;
}
return V_30 ;
}
static T_5 F_20 ( struct V_24 * V_25 , T_2 V_16 , T_1 V_26 )
{
T_2 V_23 ;
T_5 V_30 ;
V_23 = F_3 ( V_16 , NULL , NULL ) ;
F_21 ( V_25 , V_23 , V_26 , & V_30 ) ;
return V_30 ;
}
static T_5 F_22 ( struct V_24 * V_25 , T_2 V_16 , T_3 V_26 )
{
T_2 V_23 ;
T_5 V_30 ;
T_4 V_27 ;
V_23 = F_3 ( V_16 , NULL , NULL ) ;
V_27 = F_23 ( V_26 ) ;
V_30 = F_24 ( V_25 , V_23 , 2 , ( T_1 * ) & V_27 ) ;
return V_30 ;
}
static T_5 F_25 ( struct V_24 * V_25 , T_2 V_16 , T_2 V_26 )
{
struct V_1 * V_2 ;
T_1 V_28 ;
T_1 V_21 ;
T_3 V_22 ;
T_2 V_23 ;
T_1 V_29 ;
T_5 V_30 ;
T_6 V_27 ;
V_2 = V_25 -> V_2 ;
V_30 = 0 ;
V_23 = F_3 ( V_16 , & V_21 , & V_22 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if (
( ( V_21 == V_8 ) && ( V_22 < 0x100 ) ) ||
( ! V_28 ) ||
( F_11 ( V_2 ) -> V_32 )
) {
V_27 = F_26 ( V_26 ) ;
V_30 = F_24 ( V_25 , V_23 , 4 , ( T_1 * ) & V_27 ) ;
return V_30 ;
}
V_29 = V_23 & 0x3 ;
if ( V_29 == 0 ) {
F_27 ( V_25 , V_23 , V_26 , & V_30 ) ;
} else {
V_27 = F_26 ( V_26 ) ;
V_30 = F_24 ( V_25 , V_23 , 4 , ( T_1 * ) & V_27 ) ;
}
return V_30 ;
}
static T_5 F_28 ( struct V_24 * V_25 , T_2 V_16 , T_2 V_37 , T_1 * V_38 )
{
struct V_1 * V_2 ;
T_1 V_28 ;
T_1 V_21 ;
T_3 V_22 ;
T_2 V_23 ;
T_1 V_29 ;
T_5 V_30 ;
V_2 = V_25 -> V_2 ;
V_30 = 0 ;
V_23 = F_3 ( V_16 , & V_21 , & V_22 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if (
( ( V_21 == V_8 ) && ( V_22 < 0x100 ) ) ||
( false == V_28 ) ||
( true == F_11 ( V_2 ) -> V_32 )
) {
V_30 = F_24 ( V_25 , V_23 , V_37 , V_38 ) ;
return V_30 ;
}
V_29 = V_23 & 0x3 ;
if ( V_29 == 0 ) {
V_30 = F_29 ( V_25 , V_23 , V_37 , V_38 ) ;
} else {
T_1 * V_36 ;
T_2 V_39 ;
V_23 &= ~ ( T_3 ) 0x3 ;
V_39 = V_37 + V_29 ;
V_36 = F_16 ( V_39 ) ;
if ( NULL == V_36 )
return - 1 ;
V_30 = F_17 ( V_25 , V_23 , 4 , V_36 ) ;
if ( V_30 ) {
F_18 ( V_36 ) ;
return V_30 ;
}
memcpy ( V_36 + V_29 , V_38 , V_37 ) ;
V_30 = F_29 ( V_25 , V_23 , V_39 , V_36 ) ;
F_18 ( V_36 ) ;
}
return V_30 ;
}
static T_1 F_30 ( struct V_24 * V_25 , T_2 V_16 )
{
return F_31 ( V_25 , V_16 , NULL ) ;
}
static void F_32 (
struct V_24 * V_25 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_40
)
{
T_5 V_30 ;
V_30 = F_19 ( V_25 , V_16 , V_37 , V_40 ) ;
}
static void F_33 (
struct V_24 * V_25 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_41
)
{
F_28 ( V_25 , V_16 , V_37 , V_41 ) ;
}
static T_2 F_34 (
struct V_24 * V_25 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_42
)
{
struct V_1 * V_2 ;
T_7 V_43 ;
struct V_44 * V_45 ;
T_2 V_46 ;
#ifdef F_35
T_1 * V_47 ;
#endif
T_5 V_30 ;
V_2 = V_25 -> V_2 ;
V_43 = & F_36 ( V_2 ) -> V_48 ;
V_45 = F_37 ( V_2 ) ;
F_1 ( V_2 , V_16 , V_45 -> V_49 ++ , & V_16 ) ;
V_46 = V_37 ;
if ( V_37 > V_43 -> V_50 )
V_37 = F_38 ( V_37 , V_43 -> V_50 ) ;
if ( V_46 != V_37 ) {
#ifdef F_35
V_47 = V_42 ;
V_42 = F_16 ( V_37 ) ;
if ( V_42 == NULL ) {
F_14 ( V_51 L_3 , V_34 , V_37 ) ;
V_42 = V_47 ;
V_47 == NULL ;
}
#else
#endif
}
V_30 = F_39 ( V_25 , V_16 , V_37 , V_42 ) ;
#ifdef F_35
if ( ( V_46 != V_37 ) && ( V_47 ) ) {
memcpy ( V_47 , V_42 , V_46 ) ;
F_18 ( V_42 ) ;
}
#endif
if ( V_30 )
return V_52 ;
return V_53 ;
}
static T_2 F_40 (
struct V_24 * V_25 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_42
)
{
struct V_1 * V_2 ;
T_7 V_43 ;
T_5 V_30 ;
struct V_54 * V_55 = (struct V_54 * ) V_42 ;
V_2 = V_25 -> V_2 ;
V_43 = & F_36 ( V_2 ) -> V_48 ;
if ( V_2 -> V_56 == false ) {
F_41 ( L_4 , V_34 , V_16 , V_37 ) ;
return V_52 ;
}
V_37 = F_42 ( V_37 ) ;
F_1 ( V_2 , V_16 , V_37 >> 2 , & V_16 ) ;
if ( V_37 > V_43 -> V_50 )
V_37 = F_38 ( V_37 , V_43 -> V_50 ) ;
V_30 = F_29 ( V_25 , V_16 , V_37 , V_55 -> V_57 ) ;
F_43 (
& V_55 -> V_58 ,
V_30 ? V_59 : V_60
) ;
if ( V_30 )
return V_52 ;
return V_53 ;
}
void F_44 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
V_62 -> V_63 = & F_4 ;
V_62 -> V_64 = & F_6 ;
V_62 -> V_65 = & F_9 ;
V_62 -> V_66 = & F_32 ;
V_62 -> V_67 = & F_34 ;
V_62 -> V_68 = & F_20 ;
V_62 -> V_69 = & F_22 ;
V_62 -> V_70 = & F_25 ;
V_62 -> V_71 = & F_28 ;
V_62 -> V_72 = & F_33 ;
V_62 -> V_73 = & F_40 ;
V_62 -> V_74 = F_30 ;
}
static T_5 F_45 (
struct V_1 * V_2 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_38
)
{
struct V_24 * V_25 ;
T_1 V_28 ;
T_5 V_30 ;
T_1 * V_36 ;
T_2 V_39 ;
V_25 = & V_2 -> V_75 . V_76 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if ( false == V_28 ) {
V_30 = F_46 ( V_25 , V_16 , V_37 , V_38 ) ;
return V_30 ;
}
V_39 = F_47 ( V_37 ) ;
V_36 = ( T_1 * ) F_16 ( V_39 ) ;
if ( ! V_36 )
return ( - 1 ) ;
V_30 = F_39 ( V_25 , V_16 , V_39 , V_36 ) ;
if ( ! V_30 )
memcpy ( V_38 , V_36 , V_37 ) ;
F_18 ( V_36 ) ;
return V_30 ;
}
T_5 F_48 (
struct V_1 * V_2 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_38
)
{
struct V_24 * V_25 ;
T_1 V_28 ;
T_5 V_30 ;
T_1 * V_36 ;
T_2 V_39 ;
V_25 = & V_2 -> V_75 . V_76 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if (
( false == V_28 ) ||
( true == F_11 ( V_2 ) -> V_32 )
) {
V_30 = F_7 ( V_25 , V_16 , V_37 , V_38 ) ;
return V_30 ;
}
V_39 = F_47 ( V_37 ) ;
V_36 = ( T_1 * ) F_16 ( V_39 ) ;
if ( ! V_36 )
return ( - 1 ) ;
V_30 = F_17 ( V_25 , V_16 , V_39 , V_36 ) ;
if ( ! V_30 )
memcpy ( V_38 , V_36 , V_37 ) ;
F_18 ( V_36 ) ;
return V_30 ;
}
T_5 F_49 (
struct V_1 * V_2 ,
T_2 V_16 ,
T_2 V_37 ,
T_1 * V_38
)
{
struct V_24 * V_25 ;
T_1 V_28 ;
T_5 V_30 ;
T_1 * V_36 ;
if ( V_16 & 0x3 )
F_14 ( L_5 , V_34 ) ;
if ( V_37 & 0x3 )
F_14 ( L_6 , V_34 ) ;
V_25 = & V_2 -> V_75 . V_76 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if (
( false == V_28 ) ||
( true == F_11 ( V_2 ) -> V_32 )
) {
V_30 = F_24 ( V_25 , V_16 , V_37 , V_38 ) ;
return V_30 ;
}
V_36 = ( T_1 * ) F_16 ( V_37 ) ;
if ( ! V_36 )
return ( - 1 ) ;
memcpy ( V_36 , V_38 , V_37 ) ;
V_30 = F_29 ( V_25 , V_16 , V_37 , V_36 ) ;
F_18 ( V_36 ) ;
return V_30 ;
}
T_1 F_50 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_26 = 0 ;
struct V_24 * V_25 = & V_2 -> V_75 . V_76 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_7 ( V_25 , V_16 , 1 , & V_26 ) ;
return V_26 ;
}
static T_3 F_51 ( struct V_1 * V_2 , T_2 V_16 )
{
T_4 V_26 = 0 ;
struct V_24 * V_25 = & V_2 -> V_75 . V_76 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_7 ( V_25 , V_16 , 2 , ( T_1 * ) & V_26 ) ;
return F_8 ( V_26 ) ;
}
static T_2 F_52 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_28 ;
T_2 V_26 = 0 ;
struct V_24 * V_25 = & V_2 -> V_75 . V_76 ;
T_6 V_27 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_10 ( V_2 , V_31 , & V_28 ) ;
if ( ! V_28 || F_11 ( V_2 ) -> V_32 ) {
F_7 ( V_25 , V_16 , 4 , ( T_1 * ) & V_27 ) ;
V_26 = F_13 ( V_27 ) ;
} else {
V_26 = F_15 ( V_25 , V_16 , NULL ) ;
}
return V_26 ;
}
void F_53 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_77 )
{
struct V_24 * V_25 = & V_2 -> V_75 . V_76 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
F_24 ( V_25 , V_16 , 1 , & V_77 ) ;
}
static void F_54 ( struct V_1 * V_2 , T_2 V_16 , T_2 V_77 )
{
struct V_24 * V_25 = & V_2 -> V_75 . V_76 ;
T_6 V_27 ;
F_1 ( V_2 , V_6 , V_16 , & V_16 ) ;
V_27 = F_26 ( V_77 ) ;
F_24 ( V_25 , V_16 , 4 , ( T_1 * ) & V_27 ) ;
}
static T_5 F_55 ( struct V_1 * V_2 , T_2 * V_78 )
{
T_2 V_79 , V_80 ;
T_1 V_81 , V_82 ;
if ( V_78 == NULL )
return false ;
V_80 = F_37 ( V_2 ) -> V_83 ;
V_82 = 0 ;
while ( V_80 ) {
V_82 ++ ;
V_80 >>= 8 ;
}
V_79 = 0 ;
while ( V_82 != 0 ) {
V_82 -- ;
V_81 = F_50 ( V_2 , V_84 + V_82 ) ;
V_79 |= ( V_81 << ( 8 * V_82 ) ) ;
}
* V_78 = V_79 ;
return true ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_44 * V_85 ;
V_85 = F_37 ( V_2 ) ;
V_85 -> V_83 = ( T_2 ) ( \
V_86 |
V_87 |
0 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_44 * V_85 ;
V_85 = F_37 ( V_2 ) ;
V_85 -> V_88 = ( \
0 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_44 * V_85 ;
T_1 * V_89 ;
if ( true == V_2 -> V_90 )
return;
V_85 = F_37 ( V_2 ) ;
V_89 = F_59 ( 4 ) ;
* ( T_6 * ) V_89 = F_26 ( V_85 -> V_91 & V_92 ) ;
if ( * ( T_6 * ) V_89 ) {
F_49 ( V_2 , V_84 , 4 , V_89 ) ;
}
F_18 ( V_89 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_44 * V_85 ;
T_6 V_80 ;
T_2 V_93 ;
V_85 = F_37 ( V_2 ) ;
V_80 = F_26 ( V_85 -> V_83 ) ;
F_49 ( V_2 , V_94 , 4 , ( T_1 * ) & V_80 ) ;
F_61 (
V_95 ,
V_96 ,
(
L_7 ,
V_34 ,
V_85 -> V_83
)
) ;
V_93 = F_62 ( V_2 , V_97 ) ;
F_63 ( V_2 , V_97 , V_93 | V_85 -> V_88 ) ;
F_61 (
V_95 ,
V_96 ,
(
L_8 ,
V_34 ,
V_85 -> V_88
)
) ;
F_64 ( V_2 , V_98 , V_99 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
T_6 V_80 ;
V_80 = F_26 ( V_100 ) ;
F_49 ( V_2 , V_94 , 4 , ( T_1 * ) & V_80 ) ;
}
T_1 F_66 ( struct V_1 * V_2 )
{
F_41 (
L_9 ,
V_34 ,
F_67 ( V_2 , 0x100 ) ,
F_67 ( V_2 , 0x86 )
) ;
if ( F_67 ( V_2 , 0x100 ) == 0xEA )
return true ;
else
return false ;
}
static struct V_101 * F_68 ( struct V_1 * V_2 , T_2 V_102 )
{
T_2 V_103 , V_104 ;
T_1 * V_105 ;
struct V_106 * V_107 ;
struct V_101 * V_108 ;
V_103 = F_47 ( V_102 ) ;
V_107 = & V_2 -> V_109 ;
V_108 = F_69 ( & V_107 -> V_110 ) ;
if ( V_108 == NULL ) {
F_70 ( V_111 , L_10 , V_34 ) ;
return NULL ;
}
if ( V_108 -> V_112 == NULL ) {
T_8 V_113 = 0 ;
T_8 V_114 = 0 ;
V_108 -> V_112 = F_71 ( V_115 + V_116 ) ;
if ( V_108 -> V_112 ) {
V_108 -> V_112 -> V_117 = V_2 -> V_118 ;
V_113 = ( T_8 ) V_108 -> V_112 -> V_119 ;
V_114 = V_113 & ( V_116 - 1 ) ;
F_72 ( V_108 -> V_112 , ( V_116 - V_114 ) ) ;
}
if ( V_108 -> V_112 == NULL ) {
F_41 ( L_11 , V_34 , V_103 ) ;
return NULL ;
}
}
V_105 = V_108 -> V_112 -> V_119 ;
V_104 = F_34 ( & V_2 -> V_75 . V_76 , V_14 , V_103 , V_105 ) ;
if ( V_104 == V_52 ) {
F_61 ( V_120 , V_111 , ( L_12 , V_34 ) ) ;
return NULL ;
}
V_108 -> V_121 = V_102 ;
V_108 -> V_122 = V_108 -> V_112 -> V_123 ;
V_108 -> V_57 = V_108 -> V_112 -> V_119 ;
F_73 ( V_108 -> V_112 , V_102 ) ;
V_108 -> V_124 = F_74 ( V_108 -> V_112 ) ;
V_108 -> V_125 = F_75 ( V_108 -> V_112 ) ;
return V_108 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_101 * V_108 )
{
struct V_106 * V_107 ;
struct V_126 * V_127 ;
V_107 = & V_2 -> V_109 ;
V_127 = & V_107 -> V_128 ;
F_77 ( V_108 , V_127 ) ;
F_78 ( & V_107 -> V_129 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_130 * V_131 ;
struct V_24 * V_25 = & V_2 -> V_75 . V_76 ;
struct V_132 * V_133 ;
V_45 = F_37 ( V_2 ) ;
V_131 = F_36 ( V_2 ) ;
V_133 = F_80 ( V_131 ) ;
if ( V_45 -> V_91 & V_134 ) {
T_1 V_135 [ 4 ] ;
F_45 ( V_2 , V_136 , 4 , V_135 ) ;
F_81 ( & ( V_2 -> V_137 . V_138 ) ) ;
}
if ( V_45 -> V_91 & V_139 ) {
struct V_140 V_141 ;
T_1 V_142 ;
F_82 ( & ( V_133 -> V_143 ) , & V_142 ) ;
V_141 . V_144 = F_50 ( V_2 , V_145 ) ;
F_83 ( & ( V_133 -> V_146 ) ) ;
}
if ( V_45 -> V_91 & V_147 ) {
T_1 * V_148 ;
T_2 V_16 ;
V_148 = F_16 ( 4 ) ;
if ( V_148 ) {
V_16 = V_149 ;
F_1 ( V_2 , V_8 , V_16 , & V_16 ) ;
F_39 ( V_25 , V_16 , 4 , V_148 ) ;
F_84 ( V_25 , V_16 , 4 , V_148 ) ;
F_14 ( L_13 , V_34 , F_13 ( * ( T_2 * ) V_148 ) ) ;
F_18 ( V_148 ) ;
} else {
F_14 ( L_14 , V_34 ) ;
}
}
if ( V_45 -> V_91 & V_150 ) {
F_14 ( L_15 , V_34 ) ;
}
if ( V_45 -> V_91 & V_151 ) {
F_14 ( L_16 , V_34 ) ;
}
#ifndef F_85
if ( V_45 -> V_91 & V_152 ) {
struct V_153 * V_154 ;
F_14 ( L_17 , V_34 ) ;
V_154 = (struct V_153 * ) F_59 ( 16 ) ;
if ( V_154 != NULL ) {
if ( F_86 ( V_2 , ( T_1 * ) V_154 ) == V_53 ) {
if ( F_87 ( ( T_1 * ) V_154 ) ) {
F_88 ( V_2 , ( T_1 * ) V_154 ) ;
F_18 ( ( T_1 * ) V_154 ) ;
} else {
F_89 ( V_2 , ( T_1 * ) V_154 ) ;
}
}
} else {
if ( F_90 ( V_2 -> V_155 . V_156 , ( void * ) NULL ) != V_53 )
F_41 ( L_18 , V_34 ) ;
F_83 ( & V_2 -> V_155 . V_157 ) ;
}
}
#endif
if ( V_45 -> V_91 & V_158 ) {
F_14 ( L_19 , V_34 ) ;
}
if ( V_45 -> V_91 & V_159 ) {
F_14 ( L_20 , V_34 ) ;
}
if ( V_45 -> V_91 & V_160 ) {
struct V_101 * V_108 ;
int V_161 = 0 ;
T_2 V_79 ;
V_45 -> V_91 ^= V_160 ;
do {
V_45 -> V_162 = F_51 ( V_2 , V_163 ) ;
if ( V_45 -> V_162 != 0 ) {
V_108 = F_68 ( V_2 , V_45 -> V_162 ) ;
if ( V_108 )
F_76 ( V_2 , V_108 ) ;
else {
V_161 ++ ;
F_41 ( L_21 , V_161 ) ;
if ( V_161 >= 10 )
break;
}
V_45 -> V_162 = 0 ;
} else
break;
V_79 = 0 ;
F_55 ( V_2 , & V_79 ) ;
V_79 &= V_160 ;
if ( ! V_79 )
break;
} while ( 1 );
if ( V_161 == 10 )
F_41 ( L_22 ) ;
}
}
void F_91 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
if (
( V_2 -> V_164 == true ) ||
( V_2 -> V_90 == true )
)
return;
V_45 = F_37 ( V_2 ) ;
V_45 -> V_91 = 0 ;
F_55 ( V_2 , & V_45 -> V_91 ) ;
if ( V_45 -> V_91 & V_45 -> V_83 ) {
T_2 V_165 ;
V_45 -> V_91 &= V_45 -> V_83 ;
V_165 = V_45 -> V_91 & V_92 ;
if ( V_165 ) {
F_54 ( V_2 , V_84 , V_165 ) ;
}
F_79 ( V_2 ) ;
} else {
F_61 ( V_95 , V_111 ,
( L_23 ,
V_34 , V_45 -> V_91 , V_45 -> V_83 ) ) ;
}
}
T_1 F_92 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
T_2 V_166 ;
V_45 = F_37 ( V_2 ) ;
V_166 = F_52 ( V_2 , V_136 ) ;
memcpy ( V_45 -> V_167 , & V_166 , 4 ) ;
F_61 ( V_95 , V_96 ,
( L_24 ,
V_34 ,
V_45 -> V_167 [ V_168 ] ,
V_45 -> V_167 [ V_169 ] ,
V_45 -> V_167 [ V_170 ] ,
V_45 -> V_167 [ V_171 ] ) ) ;
return true ;
}
T_1 F_93 ( struct V_1 * V_2 )
{
struct V_44 * V_85 = F_37 ( V_2 ) ;
V_85 -> V_172 = F_50 ( V_2 , V_173 ) ;
return true ;
}
T_1 F_94 ( struct V_1 * V_2 , T_2 V_102 )
{
struct V_101 * V_108 ;
struct V_130 * V_174 ;
T_7 V_175 ;
struct V_176 * V_177 ;
T_1 V_178 = false ;
F_41 ( L_25 , V_34 , V_102 ) ;
if ( V_2 == NULL ) {
F_41 ( V_33 L_26 , V_34 ) ;
return false ;
}
V_174 = F_36 ( V_2 ) ;
V_175 = & V_174 -> V_48 ;
V_177 = V_175 -> V_177 ;
if ( V_102 ) {
F_95 ( V_177 ) ;
V_108 = F_68 ( V_2 , V_102 ) ;
if ( V_108 ) {
F_76 ( V_2 , V_108 ) ;
V_178 = true ;
} else {
V_178 = false ;
}
F_96 ( V_177 ) ;
}
F_41 ( L_27 , V_34 ) ;
return V_178 ;
}
