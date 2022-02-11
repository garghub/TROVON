static int F_1 ( T_1 * V_1 , int V_2 , T_2 V_3 )
{
int V_4 ;
int V_5 ;
for( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
V_5 = F_2 ( V_3 ) ;
if( V_5 == - 1 )
return - 2 ;
if( V_5 == 0xff )
return - 1 ;
if( V_5 == 0xfe ) {
V_5 = F_2 ( V_3 ) ;
if( V_5 == - 1 )
return - 2 ;
V_5 += 2 ;
}
V_1 [ V_4 ] = V_5 ;
}
return V_4 ;
}
static T_3 F_3 ( T_4 * V_6 , int * V_7 , T_5 * * V_8 )
{
int V_9 ;
T_3 V_10 ;
while ( ( V_9 = F_2 ( V_6 -> V_3 ) ) != V_11 ) {
if ( V_9 == 0xff ) {
V_10 = F_4 ( V_6 -> V_3 ) ;
if ( V_10 == - 1 ) {
* V_7 = F_5 ( V_6 -> V_3 , V_8 ) ;
return - 1 ;
}
return V_10 ;
}
}
* V_7 = F_5 ( V_6 -> V_3 , V_8 ) ;
return - 1 ;
}
int F_6 ( T_4 * V_6 , int * V_7 , T_5 * * V_8 )
{
int V_12 ;
char V_13 [ V_14 ] ;
V_15 = V_16 ;
V_12 = F_7 ( & V_13 , sizeof V_13 , V_6 -> V_3 ) ;
if ( V_12 != sizeof V_13 ) {
* V_7 = F_5 ( V_6 -> V_3 , V_8 ) ;
if ( * V_7 != 0 && * V_7 != V_17 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_13 , V_18 , V_14 ) != 0 )
return 0 ;
V_6 -> V_19 = V_20 ;
V_6 -> V_21 = V_22 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = V_25 ;
V_6 -> V_26 = V_27 ;
V_6 -> V_28 = V_29 ;
return 1 ;
}
static T_6 V_25 ( T_4 * V_6 , int * V_7 , T_5 * * V_8 ,
T_3 * V_30 )
{
T_3 V_31 ;
V_31 = F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_31 < 1 )
return FALSE ;
* V_30 = V_31 ;
return F_8 ( V_6 -> V_3 , & V_6 -> V_32 , V_6 -> V_33 ,
V_7 , V_8 ) ;
}
static T_6
V_27 ( T_4 * V_6 , T_3 V_34 , struct V_35 * V_32 ,
T_7 * V_1 , int * V_7 , T_5 * * V_8 )
{
if ( F_9 ( V_6 -> V_36 , V_34 , V_37 , V_7 ) == - 1 )
return FALSE ;
return F_8 ( V_6 -> V_36 , V_32 , V_1 , V_7 , V_8 ) ;
}
static T_6
F_8 ( T_2 V_3 , struct V_35 * V_32 , T_7 * V_1 , int * V_7 ,
T_5 * * V_8 )
{
union V_38 * V_39 = & V_32 -> V_39 ;
T_1 V_40 [ V_41 ] ;
T_8 V_42 ;
int V_43 ;
int V_44 ;
T_1 V_45 , V_46 ;
int V_12 ;
T_1 * V_47 ;
if ( F_1 ( V_40 , V_41 , V_3 ) != V_41 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_17 ;
return FALSE ;
}
V_43 = F_10 ( & V_40 [ 0 ] ) ;
#ifdef F_11
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
V_44 = F_12 ( & V_40 [ 10 ] ) ;
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
#define F_13 53
unsigned char V_61 [ F_13 ] ;
T_3 V_10 ;
if( V_44 != F_13 ) {
* V_7 = V_62 ;
* V_8 = F_14 (
L_1 ,
V_44 ) ;
return FALSE ;
}
V_10 = F_4 ( V_3 ) ;
if ( F_1 ( V_61 , F_13 , V_3 ) != F_13 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_17 ;
return FALSE ;
}
if ( F_9 ( V_3 , V_10 , V_37 , V_7 ) == - 1 )
return FALSE ;
V_32 -> V_51 = V_63 ;
V_39 -> V_64 . V_59 = V_65 ;
V_39 -> V_64 . V_66 = V_67 ;
V_39 -> V_64 . type = V_68 ;
V_39 -> V_64 . V_69 = V_70 ;
V_39 -> V_64 . V_71 = ( ( V_61 [ 0 ] & 0xf ) << 4 ) + ( V_61 [ 0 ] & 0xf ) ;
V_39 -> V_64 . V_72 = ( ( V_61 [ 0 ] & 0xf ) << 4 ) + V_61 [ 0 ] ;
V_39 -> V_64 . V_45 = V_46 & 1 ;
}
break;
case V_73 :
V_39 -> V_74 . V_75 = V_46 & 1 ;
V_39 -> V_74 . V_76 = V_77 ;
V_39 -> V_74 . V_78 = V_45 ;
V_32 -> V_51 = V_79 ;
break;
case V_80 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_81 ;
break;
case V_82 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_81 ;
break;
case V_83 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_84 ;
break;
case V_85 :
V_39 -> V_49 . V_50 = V_46 & 1 ;
V_39 -> V_49 . V_45 = V_45 ;
V_32 -> V_51 = V_86 ;
break;
}
if( V_44 > V_87 ) {
* V_7 = V_62 ;
* V_8 = F_14 ( L_2 ,
V_44 , V_87 ) ;
return FALSE ;
}
V_32 -> V_88 = V_89 ;
V_32 -> V_90 = V_91 ;
V_32 -> V_92 . V_42 = V_42 ;
V_32 -> V_92 . V_93 = V_43 * 1000 ;
V_32 -> V_94 = V_44 ;
V_32 -> V_2 = V_44 ;
F_15 ( V_1 , V_87 ) ;
V_15 = V_16 ;
V_47 = F_16 ( V_1 ) ;
V_12 = F_1 ( V_47 , V_44 , V_3 ) ;
if ( V_12 != V_44 ) {
if ( V_12 == - 2 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_17 ;
} else if ( V_12 == - 1 ) {
* V_7 = V_62 ;
* V_8 = F_17 ( L_3 ) ;
} else
* V_7 = V_17 ;
return FALSE ;
}
return TRUE ;
}
static T_6
F_18 ( T_9 * V_95 , const T_1 * V_1 , int V_2 , int * V_7 )
{
int V_4 ;
T_1 V_9 ;
static const T_1 V_96 = 0xfe ;
for( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
V_9 = V_1 [ V_4 ] ;
if( V_9 == 0xff || V_9 == 0xfe ) {
if ( ! F_19 ( V_95 , & V_96 , sizeof V_96 , V_7 ) )
return FALSE ;
V_9 -= 2 ;
}
if ( ! F_19 ( V_95 , & V_9 , sizeof V_9 , V_7 ) )
return FALSE ;
}
return TRUE ;
}
T_6 F_20 ( T_9 * V_95 , int * V_7 )
{
V_95 -> V_97 = V_98 ;
V_95 -> V_99 = NULL ;
if ( ! F_19 ( V_95 , V_18 ,
V_14 , V_7 ) )
return FALSE ;
V_95 -> V_100 += V_14 ;
* V_7 = 0 ;
return TRUE ;
}
int F_21 ( int V_101 )
{
switch ( V_101 ) {
case V_52 :
case V_54 :
case V_81 :
case V_63 :
case V_57 :
case V_79 :
case V_84 :
case V_20 :
return 0 ;
default:
return V_102 ;
}
}
static T_6 V_98 ( T_9 * V_95 ,
const struct V_35 * V_32 ,
const T_1 * V_47 , int * V_7 )
{
static const T_1 V_103 = 0xff ;
const union V_38 * V_39 = & V_32 -> V_39 ;
T_1 V_1 [ V_41 ] ;
int V_43 ;
T_8 V_42 ;
int V_45 ;
int V_104 ;
int V_105 ;
int V_106 ;
if ( V_32 -> V_88 != V_89 ) {
* V_7 = V_107 ;
return FALSE ;
}
if ( V_32 -> V_94 > 65535 ) {
* V_7 = V_108 ;
return FALSE ;
}
V_43 = V_32 -> V_92 . V_93 / 1000 ;
V_42 = V_32 -> V_92 . V_42 ;
V_106 = V_32 -> V_94 ;
V_104 = V_39 -> V_49 . V_50 ;
V_45 = V_39 -> V_49 . V_45 ;
switch( V_32 -> V_51 ) {
case V_52 :
V_105 = V_48 ;
break;
case V_54 :
V_105 = V_53 ;
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
V_105 = V_60 ;
V_45 = 0x80 ;
break;
case V_57 :
V_105 = V_56 ;
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
* V_7 = V_102 ;
return FALSE ;
}
F_22 ( & V_1 [ 0 ] , V_43 ) ;
V_1 [ 3 ] = ( T_1 ) 0 ;
V_1 [ 4 ] = ( T_1 ) ( 0xff & ( V_42 >> 24 ) ) ;
V_1 [ 5 ] = ( T_1 ) ( 0xff & ( V_42 >> 16 ) ) ;
V_1 [ 6 ] = ( T_1 ) ( 0xff & ( V_42 >> 8 ) ) ;
V_1 [ 7 ] = ( T_1 ) ( 0xff & ( V_42 >> 0 ) ) ;
V_1 [ 8 ] = ( T_1 ) V_45 ;
V_1 [ 9 ] = ( T_1 ) ( V_104 ? 1 : 0 ) + ( V_105 << 1 ) ;
F_23 ( & V_1 [ 10 ] , V_106 ) ;
if ( ! F_19 ( V_95 , & V_103 , sizeof V_103 , V_7 ) )
return FALSE ;
if ( ! F_18 ( V_95 , V_1 , 12 , V_7 ) )
return FALSE ;
if ( ! F_18 ( V_95 , V_47 , V_106 , V_7 ) )
return FALSE ;
return TRUE ;
}
