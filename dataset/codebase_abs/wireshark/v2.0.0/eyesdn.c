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
T_7 F_7 ( T_6 * V_10 , int * V_4 , T_4 * * V_5 )
{
char V_14 [ V_15 ] ;
if ( ! F_8 ( V_10 -> V_1 , & V_14 , sizeof V_14 , V_4 , V_5 ) ) {
if ( * V_4 != V_8 )
return V_16 ;
return V_17 ;
}
if ( memcmp ( V_14 , V_18 , V_15 ) != 0 )
return V_17 ;
V_10 -> V_19 = V_20 ;
V_10 -> V_21 = V_22 ;
V_10 -> V_23 = 0 ;
V_10 -> V_24 = V_25 ;
V_10 -> V_26 = V_27 ;
V_10 -> V_28 = V_29 ;
return V_30 ;
}
static T_1 V_25 ( T_6 * V_10 , int * V_4 , T_4 * * V_5 ,
T_5 * V_31 )
{
T_5 V_32 ;
V_32 = F_5 ( V_10 , V_4 , V_5 ) ;
if ( V_32 < 1 )
return FALSE ;
* V_31 = V_32 ;
return F_9 ( V_10 -> V_1 , & V_10 -> V_33 , V_10 -> V_34 ,
V_4 , V_5 ) ;
}
static T_1
V_27 ( T_6 * V_10 , T_5 V_35 , struct V_36 * V_33 ,
T_8 * V_2 , int * V_4 , T_4 * * V_5 )
{
if ( F_10 ( V_10 -> V_37 , V_35 , V_38 , V_4 ) == - 1 )
return FALSE ;
return F_9 ( V_10 -> V_37 , V_33 , V_2 , V_4 , V_5 ) ;
}
static T_1
F_9 ( T_2 V_1 , struct V_36 * V_33 , T_8 * V_2 , int * V_4 ,
T_4 * * V_5 )
{
union V_39 * V_40 = & V_33 -> V_40 ;
T_3 V_41 [ V_42 ] ;
T_9 V_43 ;
int V_44 ;
int V_45 ;
T_3 V_46 , V_47 ;
T_3 * V_48 ;
if ( ! F_1 ( V_1 , V_41 , V_42 , V_4 , V_5 ) )
return FALSE ;
V_44 = F_11 ( & V_41 [ 0 ] ) ;
#ifdef F_12
V_43 = V_41 [ 3 ] ;
#else
V_43 = 0 ;
#endif
V_43 = ( V_43 << 8 ) | V_41 [ 4 ] ;
V_43 = ( V_43 << 8 ) | V_41 [ 5 ] ;
V_43 = ( V_43 << 8 ) | V_41 [ 6 ] ;
V_43 = ( V_43 << 8 ) | V_41 [ 7 ] ;
V_46 = V_41 [ 8 ] ;
V_47 = V_41 [ 9 ] ;
V_45 = F_13 ( & V_41 [ 10 ] ) ;
switch( V_47 >> 1 ) {
default:
case V_49 :
V_40 -> V_50 . V_51 = V_47 & 1 ;
V_40 -> V_50 . V_46 = V_46 ;
if( V_46 ) {
V_33 -> V_52 = V_53 ;
V_40 -> V_50 . V_51 = ! V_40 -> V_50 . V_51 ;
} else {
V_33 -> V_52 = V_53 ;
}
break;
case V_54 :
V_33 -> V_52 = V_55 ;
V_40 -> V_56 . V_51 = ( V_47 & 1 ) ;
break;
case V_57 :
V_33 -> V_52 = V_58 ;
V_40 -> V_59 . V_60 = ( V_47 & 1 ) ? 0 : 0x80 ;
break;
case V_61 : {
#define F_14 53
unsigned char V_62 [ F_14 ] ;
T_5 V_12 ;
if( V_45 != F_14 ) {
* V_4 = V_9 ;
* V_5 = F_15 (
L_2 ,
V_45 ) ;
return FALSE ;
}
V_12 = F_6 ( V_1 ) ;
if ( ! F_1 ( V_1 , V_62 , F_14 , V_4 , V_5 ) )
return FALSE ;
if ( F_10 ( V_1 , V_12 , V_38 , V_4 ) == - 1 )
return FALSE ;
V_33 -> V_52 = V_63 ;
V_40 -> V_64 . V_60 = V_65 ;
V_40 -> V_64 . V_66 = V_67 ;
V_40 -> V_64 . type = V_68 ;
V_40 -> V_64 . V_69 = V_70 ;
V_40 -> V_64 . V_71 = ( ( V_62 [ 0 ] & 0xf ) << 4 ) + ( V_62 [ 0 ] & 0xf ) ;
V_40 -> V_64 . V_72 = ( ( V_62 [ 0 ] & 0xf ) << 4 ) + V_62 [ 0 ] ;
V_40 -> V_64 . V_46 = V_47 & 1 ;
}
break;
case V_73 :
V_40 -> V_74 . V_75 = V_47 & 1 ;
V_40 -> V_74 . V_76 = V_77 ;
V_40 -> V_74 . V_78 = V_46 ;
V_33 -> V_52 = V_79 ;
break;
case V_80 :
V_40 -> V_50 . V_51 = V_47 & 1 ;
V_40 -> V_50 . V_46 = V_46 ;
V_33 -> V_52 = V_81 ;
break;
case V_82 :
V_40 -> V_50 . V_51 = V_47 & 1 ;
V_40 -> V_50 . V_46 = V_46 ;
V_33 -> V_52 = V_81 ;
break;
case V_83 :
V_40 -> V_50 . V_51 = V_47 & 1 ;
V_40 -> V_50 . V_46 = V_46 ;
V_33 -> V_52 = V_84 ;
break;
case V_85 :
V_40 -> V_50 . V_51 = V_47 & 1 ;
V_40 -> V_50 . V_46 = V_46 ;
V_33 -> V_52 = V_86 ;
break;
}
if( V_45 > V_87 ) {
* V_4 = V_9 ;
* V_5 = F_15 ( L_3 ,
V_45 , V_87 ) ;
return FALSE ;
}
V_33 -> V_88 = V_89 ;
V_33 -> V_90 = V_91 ;
V_33 -> V_92 . V_43 = V_43 ;
V_33 -> V_92 . V_93 = V_44 * 1000 ;
V_33 -> V_94 = V_45 ;
V_33 -> V_3 = V_45 ;
F_16 ( V_2 , V_87 ) ;
V_48 = F_17 ( V_2 ) ;
if ( ! F_1 ( V_1 , V_48 , V_45 , V_4 , V_5 ) )
return FALSE ;
return TRUE ;
}
static T_1
F_18 ( T_10 * V_95 , const T_3 * V_2 , int V_3 , int * V_4 )
{
int V_6 ;
T_3 V_11 ;
static const T_3 V_96 = 0xfe ;
for( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_11 = V_2 [ V_6 ] ;
if( V_11 == 0xff || V_11 == 0xfe ) {
if ( ! F_19 ( V_95 , & V_96 , sizeof V_96 , V_4 ) )
return FALSE ;
V_11 -= 2 ;
}
if ( ! F_19 ( V_95 , & V_11 , sizeof V_11 , V_4 ) )
return FALSE ;
}
return TRUE ;
}
T_1 F_20 ( T_10 * V_95 , int * V_4 )
{
V_95 -> V_97 = V_98 ;
if ( ! F_19 ( V_95 , V_18 ,
V_15 , V_4 ) )
return FALSE ;
V_95 -> V_99 += V_15 ;
* V_4 = 0 ;
return TRUE ;
}
int F_21 ( int V_100 )
{
switch ( V_100 ) {
case V_53 :
case V_55 :
case V_81 :
case V_63 :
case V_58 :
case V_79 :
case V_84 :
case V_20 :
return 0 ;
default:
return V_101 ;
}
}
static T_1 V_98 ( T_10 * V_95 ,
const struct V_36 * V_33 ,
const T_3 * V_48 , int * V_4 , T_4 * * V_5 V_102 )
{
static const T_3 V_103 = 0xff ;
const union V_39 * V_40 = & V_33 -> V_40 ;
T_3 V_2 [ V_42 ] ;
int V_44 ;
T_9 V_43 ;
int V_46 ;
int V_104 ;
int V_105 ;
int V_106 ;
if ( V_33 -> V_88 != V_89 ) {
* V_4 = V_107 ;
return FALSE ;
}
if ( V_33 -> V_94 > 65535 ) {
* V_4 = V_108 ;
return FALSE ;
}
V_44 = V_33 -> V_92 . V_93 / 1000 ;
V_43 = V_33 -> V_92 . V_43 ;
V_106 = V_33 -> V_94 ;
V_104 = V_40 -> V_50 . V_51 ;
V_46 = V_40 -> V_50 . V_46 ;
switch( V_33 -> V_52 ) {
case V_53 :
V_105 = V_49 ;
break;
case V_55 :
V_105 = V_54 ;
break;
case V_81 :
V_105 = V_80 ;
break;
#if 0
case WTAP_ENCAP_DASS2:
protocol=EYESDN_ENCAP_DASS2;
break;
#endif
case V_63 :
V_105 = V_61 ;
V_46 = 0x80 ;
break;
case V_58 :
V_105 = V_57 ;
break;
case V_79 :
V_105 = V_73 ;
break;
case V_84 :
V_105 = V_83 ;
break;
case V_86 :
V_105 = V_85 ;
break;
default:
* V_4 = V_101 ;
return FALSE ;
}
F_22 ( & V_2 [ 0 ] , V_44 ) ;
V_2 [ 3 ] = ( T_3 ) 0 ;
V_2 [ 4 ] = ( T_3 ) ( 0xff & ( V_43 >> 24 ) ) ;
V_2 [ 5 ] = ( T_3 ) ( 0xff & ( V_43 >> 16 ) ) ;
V_2 [ 6 ] = ( T_3 ) ( 0xff & ( V_43 >> 8 ) ) ;
V_2 [ 7 ] = ( T_3 ) ( 0xff & ( V_43 >> 0 ) ) ;
V_2 [ 8 ] = ( T_3 ) V_46 ;
V_2 [ 9 ] = ( T_3 ) ( V_104 ? 1 : 0 ) + ( V_105 << 1 ) ;
F_23 ( & V_2 [ 10 ] , V_106 ) ;
if ( ! F_19 ( V_95 , & V_103 , sizeof V_103 , V_4 ) )
return FALSE ;
if ( ! F_18 ( V_95 , V_2 , 12 , V_4 ) )
return FALSE ;
if ( ! F_18 ( V_95 , V_48 , V_106 , V_4 ) )
return FALSE ;
return TRUE ;
}
