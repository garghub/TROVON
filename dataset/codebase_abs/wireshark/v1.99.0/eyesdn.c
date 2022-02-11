static T_1 F_1 ( T_2 V_1 , T_3 * V_2 , int V_3 , int * V_4 , T_4 * * V_5 )
{
int V_6 ;
int V_7 ;
for( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_7 = F_2 ( V_1 ) ;
if( V_7 == - 1 ) {
* V_4 = F_3 ( V_1 , V_5 ) ;
if( * V_4 == 0 )
* V_4 = V_8 ;
return FALSE ;
}
if( V_7 == 0xff ) {
* V_4 = V_9 ;
* V_5 = F_4 ( L_1 ) ;
return FALSE ;
}
if( V_7 == 0xfe ) {
V_7 = F_2 ( V_1 ) ;
if( V_7 == - 1 ) {
* V_4 = F_3 ( V_1 , V_5 ) ;
if( * V_4 == 0 )
* V_4 = V_8 ;
return FALSE ;
}
V_7 += 2 ;
}
V_2 [ V_6 ] = V_7 ;
}
return TRUE ;
}
static T_5 F_5 ( T_6 * V_10 , int * V_4 , T_4 * * V_5 )
{
int V_11 ;
T_5 V_12 ;
while ( ( V_11 = F_2 ( V_10 -> V_1 ) ) != V_13 ) {
if ( V_11 == 0xff ) {
V_12 = F_6 ( V_10 -> V_1 ) ;
if ( V_12 == - 1 ) {
* V_4 = F_3 ( V_10 -> V_1 , V_5 ) ;
return - 1 ;
}
return V_12 ;
}
}
* V_4 = F_3 ( V_10 -> V_1 , V_5 ) ;
return - 1 ;
}
int F_7 ( T_6 * V_10 , int * V_4 , T_4 * * V_5 )
{
char V_14 [ V_15 ] ;
V_16 = V_17 ;
if ( ! F_8 ( V_10 -> V_1 , & V_14 , sizeof V_14 , V_4 , V_5 ) ) {
if ( * V_4 != V_8 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_14 , V_18 , V_15 ) != 0 )
return 0 ;
V_10 -> V_19 = V_20 ;
V_10 -> V_21 = V_22 ;
V_10 -> V_23 = 0 ;
V_10 -> V_24 = V_25 ;
V_10 -> V_26 = V_27 ;
V_10 -> V_28 = V_29 ;
return 1 ;
}
static T_1 V_25 ( T_6 * V_10 , int * V_4 , T_4 * * V_5 ,
T_5 * V_30 )
{
T_5 V_31 ;
V_31 = F_5 ( V_10 , V_4 , V_5 ) ;
if ( V_31 < 1 )
return FALSE ;
* V_30 = V_31 ;
return F_9 ( V_10 -> V_1 , & V_10 -> V_32 , V_10 -> V_33 ,
V_4 , V_5 ) ;
}
static T_1
V_27 ( T_6 * V_10 , T_5 V_34 , struct V_35 * V_32 ,
T_7 * V_2 , int * V_4 , T_4 * * V_5 )
{
if ( F_10 ( V_10 -> V_36 , V_34 , V_37 , V_4 ) == - 1 )
return FALSE ;
return F_9 ( V_10 -> V_36 , V_32 , V_2 , V_4 , V_5 ) ;
}
static T_1
F_9 ( T_2 V_1 , struct V_35 * V_32 , T_7 * V_2 , int * V_4 ,
T_4 * * V_5 )
{
union V_38 * V_39 = & V_32 -> V_39 ;
T_3 V_40 [ V_41 ] ;
T_8 V_42 ;
int V_43 ;
int V_44 ;
T_3 V_45 , V_46 ;
T_3 * V_47 ;
if ( ! F_1 ( V_1 , V_40 , V_41 , V_4 , V_5 ) )
return FALSE ;
V_43 = F_11 ( & V_40 [ 0 ] ) ;
#ifdef F_12
V_42 = V_40 [ 3 ] ;
#else
V_42 = 0 ;
#endif
V_42 = ( V_42 << 8 ) | V_40 [ 4 ] ;
V_42 = ( V_42 << 8 ) | V_40 [ 5 ] ;
V_42 = ( V_42 << 8 ) | V_40 [ 6 ] ;
V_42 = ( V_42 << 8 ) | V_40 [ 7 ] ;
V_45 = V_40 [ 8 ] ;
V_46 = V_40 [ 9 ] ;
V_44 = F_13 ( & V_40 [ 10 ] ) ;
switch( V_46 >> 1 ) {
default:
case V_48 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
if( V_45 ) {
V_32 -> V_51 = V_52 ;
V_39 -> V_49 . V_50 = ! V_39 -> V_49 . V_50 ;
} else {
V_32 -> V_51 = V_52 ;
}
break;
case V_53 :
V_32 -> V_51 = V_54 ;
V_39 -> V_55 . V_50 = ( V_46 & 1 ) ;
break;
case V_56 :
V_32 -> V_51 = V_57 ;
V_39 -> V_58 . V_59 = ( V_46 & 1 ) ? 0 : 0x80 ;
break;
case V_60 : {
#define F_14 53
unsigned char V_61 [ F_14 ] ;
T_5 V_12 ;
if( V_44 != F_14 ) {
* V_4 = V_9 ;
* V_5 = F_15 (
L_2 ,
V_44 ) ;
return FALSE ;
}
V_12 = F_6 ( V_1 ) ;
if ( ! F_1 ( V_1 , V_61 , F_14 , V_4 , V_5 ) )
return FALSE ;
if ( F_10 ( V_1 , V_12 , V_37 , V_4 ) == - 1 )
return FALSE ;
V_32 -> V_51 = V_62 ;
V_39 -> V_63 . V_59 = V_64 ;
V_39 -> V_63 . V_65 = V_66 ;
V_39 -> V_63 . type = V_67 ;
V_39 -> V_63 . V_68 = V_69 ;
V_39 -> V_63 . V_70 = ( ( V_61 [ 0 ] & 0xf ) << 4 ) + ( V_61 [ 0 ] & 0xf ) ;
V_39 -> V_63 . V_71 = ( ( V_61 [ 0 ] & 0xf ) << 4 ) + V_61 [ 0 ] ;
V_39 -> V_63 . V_45 = V_46 & 1 ;
}
break;
case V_72 :
V_39 -> V_73 . V_74 = V_46 & 1 ;
V_39 -> V_73 . V_75 = V_76 ;
V_39 -> V_73 . V_77 = V_45 ;
V_32 -> V_51 = V_78 ;
break;
case V_79 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_80 ;
break;
case V_81 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_80 ;
break;
case V_82 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_83 ;
break;
case V_84 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_85 ;
break;
}
if( V_44 > V_86 ) {
* V_4 = V_9 ;
* V_5 = F_15 ( L_3 ,
V_44 , V_86 ) ;
return FALSE ;
}
V_32 -> V_87 = V_88 ;
V_32 -> V_89 = V_90 ;
V_32 -> V_91 . V_42 = V_42 ;
V_32 -> V_91 . V_92 = V_43 * 1000 ;
V_32 -> V_93 = V_44 ;
V_32 -> V_3 = V_44 ;
F_16 ( V_2 , V_86 ) ;
V_16 = V_17 ;
V_47 = F_17 ( V_2 ) ;
if ( ! F_1 ( V_1 , V_47 , V_44 , V_4 , V_5 ) )
return FALSE ;
return TRUE ;
}
static T_1
F_18 ( T_9 * V_94 , const T_3 * V_2 , int V_3 , int * V_4 )
{
int V_6 ;
T_3 V_11 ;
static const T_3 V_95 = 0xfe ;
for( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_11 = V_2 [ V_6 ] ;
if( V_11 == 0xff || V_11 == 0xfe ) {
if ( ! F_19 ( V_94 , & V_95 , sizeof V_95 , V_4 ) )
return FALSE ;
V_11 -= 2 ;
}
if ( ! F_19 ( V_94 , & V_11 , sizeof V_11 , V_4 ) )
return FALSE ;
}
return TRUE ;
}
T_1 F_20 ( T_9 * V_94 , int * V_4 )
{
V_94 -> V_96 = V_97 ;
V_94 -> V_98 = NULL ;
if ( ! F_19 ( V_94 , V_18 ,
V_15 , V_4 ) )
return FALSE ;
V_94 -> V_99 += V_15 ;
* V_4 = 0 ;
return TRUE ;
}
int F_21 ( int V_100 )
{
switch ( V_100 ) {
case V_52 :
case V_54 :
case V_80 :
case V_62 :
case V_57 :
case V_78 :
case V_83 :
case V_20 :
return 0 ;
default:
return V_101 ;
}
}
static T_1 V_97 ( T_9 * V_94 ,
const struct V_35 * V_32 ,
const T_3 * V_47 , int * V_4 )
{
static const T_3 V_102 = 0xff ;
const union V_38 * V_39 = & V_32 -> V_39 ;
T_3 V_2 [ V_41 ] ;
int V_43 ;
T_8 V_42 ;
int V_45 ;
int V_103 ;
int V_104 ;
int V_105 ;
if ( V_32 -> V_87 != V_88 ) {
* V_4 = V_106 ;
return FALSE ;
}
if ( V_32 -> V_93 > 65535 ) {
* V_4 = V_107 ;
return FALSE ;
}
V_43 = V_32 -> V_91 . V_92 / 1000 ;
V_42 = V_32 -> V_91 . V_42 ;
V_105 = V_32 -> V_93 ;
V_103 = V_39 -> V_49 . V_50 ;
V_45 = V_39 -> V_49 . V_45 ;
switch( V_32 -> V_51 ) {
case V_52 :
V_104 = V_48 ;
break;
case V_54 :
V_104 = V_53 ;
break;
case V_80 :
V_104 = V_79 ;
break;
#if 0
case WTAP_ENCAP_DASS2:
protocol=EYESDN_ENCAP_DASS2;
break;
#endif
case V_62 :
V_104 = V_60 ;
V_45 = 0x80 ;
break;
case V_57 :
V_104 = V_56 ;
break;
case V_78 :
V_104 = V_72 ;
break;
case V_83 :
V_104 = V_82 ;
break;
case V_85 :
V_104 = V_84 ;
break;
default:
* V_4 = V_101 ;
return FALSE ;
}
F_22 ( & V_2 [ 0 ] , V_43 ) ;
V_2 [ 3 ] = ( T_3 ) 0 ;
V_2 [ 4 ] = ( T_3 ) ( 0xff & ( V_42 >> 24 ) ) ;
V_2 [ 5 ] = ( T_3 ) ( 0xff & ( V_42 >> 16 ) ) ;
V_2 [ 6 ] = ( T_3 ) ( 0xff & ( V_42 >> 8 ) ) ;
V_2 [ 7 ] = ( T_3 ) ( 0xff & ( V_42 >> 0 ) ) ;
V_2 [ 8 ] = ( T_3 ) V_45 ;
V_2 [ 9 ] = ( T_3 ) ( V_103 ? 1 : 0 ) + ( V_104 << 1 ) ;
F_23 ( & V_2 [ 10 ] , V_105 ) ;
if ( ! F_19 ( V_94 , & V_102 , sizeof V_102 , V_4 ) )
return FALSE ;
if ( ! F_18 ( V_94 , V_2 , 12 , V_4 ) )
return FALSE ;
if ( ! F_18 ( V_94 , V_47 , V_105 , V_4 ) )
return FALSE ;
return TRUE ;
}
