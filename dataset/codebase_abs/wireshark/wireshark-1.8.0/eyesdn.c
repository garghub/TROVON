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
if ( F_6 ( V_6 -> V_3 ) ) {
* V_7 = 0 ;
} else {
* V_7 = F_5 ( V_6 -> V_3 , V_8 ) ;
}
return - 1 ;
}
int F_7 ( T_4 * V_6 , int * V_7 , T_5 * * V_8 )
{
int V_12 ;
char V_13 [ V_14 ] ;
V_15 = V_16 ;
V_12 = F_8 ( & V_13 , sizeof V_13 , V_6 -> V_3 ) ;
if ( V_12 != sizeof V_13 ) {
* V_7 = F_5 ( V_6 -> V_3 , V_8 ) ;
if ( * V_7 != 0 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_13 , V_17 , V_14 ) != 0 )
return 0 ;
V_6 -> V_18 = V_19 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = V_24 ;
V_6 -> V_25 = V_26 ;
V_6 -> V_27 = V_28 ;
return 1 ;
}
static T_6 V_24 ( T_4 * V_6 , int * V_7 , T_5 * * V_8 ,
T_3 * V_29 )
{
T_3 V_30 ;
T_1 * V_1 ;
int V_31 ;
V_30 = F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_30 < 1 )
return FALSE ;
V_31 = F_9 ( V_6 , V_6 -> V_3 , & V_6 -> V_32 , V_7 ,
V_8 ) ;
if ( V_31 == - 1 )
return FALSE ;
F_10 ( V_6 -> V_33 , V_34 ) ;
V_1 = F_11 ( V_6 -> V_33 ) ;
if ( ! F_12 ( V_6 -> V_3 , V_31 , V_1 , V_7 , V_8 ) )
return FALSE ;
* V_29 = V_30 ;
return TRUE ;
}
static T_6
V_26 ( T_4 * V_6 , T_3 V_35 ,
union V_36 * V_32 , T_1 * V_37 , int V_2 ,
int * V_7 , T_5 * * V_8 )
{
int V_31 ;
if ( F_13 ( V_6 -> V_38 , V_35 , V_39 , V_7 ) == - 1 )
return FALSE ;
V_31 = F_9 ( NULL , V_6 -> V_38 , V_32 ,
V_7 , V_8 ) ;
if ( V_31 != V_2 ) {
if ( V_31 != - 1 ) {
* V_7 = V_40 ;
* V_8 = F_14 ( L_1 ,
V_2 , V_31 ) ;
}
return FALSE ;
}
return F_12 ( V_6 -> V_38 , V_31 , V_37 , V_7 ,
V_8 ) ;
}
static int
F_9 ( T_4 * V_6 , T_2 V_3 ,
union V_36 * V_32 , int * V_7 , T_5 * * V_8 )
{
T_1 V_41 [ V_42 ] ;
T_7 V_43 ;
int V_44 ;
int V_31 ;
T_1 V_45 , V_46 ;
if ( F_1 ( V_41 , V_42 , V_3 ) != V_42 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_47 ;
return - 1 ;
}
V_44 = F_15 ( & V_41 [ 0 ] ) ;
#ifdef F_16
V_43 = V_41 [ 3 ] ;
#else
V_43 = 0 ;
#endif
V_43 = ( V_43 << 8 ) | V_41 [ 4 ] ;
V_43 = ( V_43 << 8 ) | V_41 [ 5 ] ;
V_43 = ( V_43 << 8 ) | V_41 [ 6 ] ;
V_43 = ( V_43 << 8 ) | V_41 [ 7 ] ;
V_45 = V_41 [ 8 ] ;
V_46 = V_41 [ 9 ] ;
V_31 = F_17 ( & V_41 [ 10 ] ) ;
switch( V_46 >> 1 ) {
default:
case V_48 :
V_32 -> V_49 . V_50 = V_46 & 1 ;
V_32 -> V_49 . V_45 = V_45 ;
if( V_45 ) {
if( V_6 ) {
V_6 -> V_51 . V_52 = V_53 ;
V_32 -> V_49 . V_50 = ! V_32 -> V_49 . V_50 ;
}
} else {
if( V_6 ) {
V_6 -> V_51 . V_52 = V_53 ;
}
}
break;
case V_54 :
if( V_6 ) {
V_6 -> V_51 . V_52 = V_55 ;
}
V_32 -> V_56 . V_50 = ( V_46 & 1 ) ;
break;
case V_57 :
if( V_6 ) {
V_6 -> V_51 . V_52 = V_58 ;
}
V_32 -> V_59 . V_60 = ( V_46 & 1 ) ? 0 : 0x80 ;
break;
case V_61 : {
#define F_18 53
unsigned char V_62 [ F_18 ] ;
T_3 V_10 ;
if( V_31 != F_18 ) {
* V_7 = V_40 ;
* V_8 = F_14 (
L_2 ,
V_31 ) ;
return - 1 ;
}
V_10 = F_4 ( V_3 ) ;
if ( F_1 ( V_62 , F_18 , V_3 ) != F_18 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_47 ;
return - 1 ;
}
if ( F_13 ( V_3 , V_10 , V_39 , V_7 ) == - 1 )
return - 1 ;
if( V_6 ) {
V_6 -> V_51 . V_52 = V_63 ;
}
V_32 -> V_64 . V_60 = V_65 ;
V_32 -> V_64 . V_66 = V_67 ;
V_32 -> V_64 . type = V_68 ;
V_32 -> V_64 . V_69 = V_70 ;
V_32 -> V_64 . V_71 = ( ( V_62 [ 0 ] & 0xf ) << 4 ) + ( V_62 [ 0 ] & 0xf ) ;
V_32 -> V_64 . V_72 = ( ( V_62 [ 0 ] & 0xf ) << 4 ) + V_62 [ 0 ] ;
V_32 -> V_64 . V_45 = V_46 & 1 ;
}
break;
case V_73 :
V_32 -> V_74 . V_75 = V_46 & 1 ;
V_32 -> V_74 . V_76 = V_77 ;
V_32 -> V_74 . V_78 = V_45 ;
if( V_6 ) {
V_6 -> V_51 . V_52 = V_79 ;
}
break;
case V_80 :
V_32 -> V_49 . V_50 = V_46 & 1 ;
V_32 -> V_49 . V_45 = V_45 ;
if( V_6 ) {
V_6 -> V_51 . V_52 = V_81 ;
}
break;
case V_82 :
V_32 -> V_49 . V_50 = V_46 & 1 ;
V_32 -> V_49 . V_45 = V_45 ;
if( V_6 ) {
V_6 -> V_51 . V_52 = V_81 ;
}
break;
case V_83 :
V_32 -> V_49 . V_50 = V_46 & 1 ;
V_32 -> V_49 . V_45 = V_45 ;
if( V_6 ) {
V_6 -> V_51 . V_52 = V_84 ;
}
break;
case V_85 :
V_32 -> V_49 . V_50 = V_46 & 1 ;
V_32 -> V_49 . V_45 = V_45 ;
if( V_6 ) {
V_6 -> V_51 . V_52 = V_86 ;
}
break;
}
if( V_31 > V_34 ) {
* V_7 = V_40 ;
* V_8 = F_14 ( L_3 ,
V_31 , V_34 ) ;
return - 1 ;
}
if ( V_6 ) {
V_6 -> V_51 . V_87 = V_88 ;
V_6 -> V_51 . V_89 . V_43 = V_43 ;
V_6 -> V_51 . V_89 . V_90 = V_44 * 1000 ;
V_6 -> V_51 . V_91 = V_31 ;
V_6 -> V_51 . V_2 = V_31 ;
}
return V_31 ;
}
static T_6
F_12 ( T_2 V_3 , int V_31 , T_1 * V_1 , int * V_7 ,
T_5 * * V_8 )
{
int V_12 ;
V_15 = V_16 ;
V_12 = F_1 ( V_1 , V_31 , V_3 ) ;
if ( V_12 != V_31 ) {
if ( V_12 == - 2 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_47 ;
} else if ( V_12 == - 1 ) {
* V_7 = V_40 ;
* V_8 = F_19 ( L_4 ) ;
} else
* V_7 = V_47 ;
return FALSE ;
}
return TRUE ;
}
static T_6
F_20 ( T_8 * V_92 , const T_1 * V_1 , int V_2 , int * V_7 )
{
int V_4 ;
T_1 V_9 ;
static const T_1 V_93 = 0xfe ;
for( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
V_9 = V_1 [ V_4 ] ;
if( V_9 == 0xff || V_9 == 0xfe ) {
if ( ! F_21 ( V_92 , & V_93 , sizeof V_93 , V_7 ) )
return FALSE ;
V_9 -= 2 ;
}
if ( ! F_21 ( V_92 , & V_9 , sizeof V_9 , V_7 ) )
return FALSE ;
}
return TRUE ;
}
T_6 F_22 ( T_8 * V_92 , int * V_7 )
{
V_92 -> V_94 = V_95 ;
V_92 -> V_96 = NULL ;
if ( ! F_21 ( V_92 , V_17 ,
V_14 , V_7 ) )
return FALSE ;
V_92 -> V_97 += V_14 ;
* V_7 = 0 ;
return TRUE ;
}
int F_23 ( int V_98 )
{
switch ( V_98 ) {
case V_53 :
case V_55 :
case V_81 :
case V_63 :
case V_58 :
case V_79 :
case V_84 :
case V_19 :
return 0 ;
default:
return V_99 ;
}
}
static T_6 V_95 ( T_8 * V_92 ,
const struct V_100 * V_51 ,
const union V_36 * V_32 V_101 ,
const T_1 * V_37 , int * V_7 )
{
static const T_1 V_102 = 0xff ;
T_1 V_1 [ V_42 ] ;
int V_44 ;
T_7 V_43 ;
int V_45 ;
int V_103 ;
int V_104 ;
int V_105 ;
V_44 = V_51 -> V_89 . V_90 / 1000 ;
V_43 = V_51 -> V_89 . V_43 ;
V_105 = V_51 -> V_91 ;
V_103 = V_32 -> V_49 . V_50 ;
V_45 = V_32 -> V_49 . V_45 ;
switch( V_51 -> V_52 ) {
case V_53 :
V_104 = V_48 ;
break;
case V_55 :
V_104 = V_54 ;
break;
case V_81 :
V_104 = V_80 ;
break;
#if 0
case WTAP_ENCAP_DASS2:
protocol=EYESDN_ENCAP_DASS2;
break;
#endif
case V_63 :
V_104 = V_61 ;
V_45 = 0x80 ;
break;
case V_58 :
V_104 = V_57 ;
break;
case V_79 :
V_104 = V_73 ;
break;
case V_84 :
V_104 = V_83 ;
break;
case V_86 :
V_104 = V_85 ;
break;
default:
* V_7 = V_99 ;
return FALSE ;
}
F_24 ( & V_1 [ 0 ] , V_44 ) ;
V_1 [ 3 ] = ( T_1 ) 0 ;
V_1 [ 4 ] = ( T_1 ) ( 0xff & ( V_43 >> 24 ) ) ;
V_1 [ 5 ] = ( T_1 ) ( 0xff & ( V_43 >> 16 ) ) ;
V_1 [ 6 ] = ( T_1 ) ( 0xff & ( V_43 >> 8 ) ) ;
V_1 [ 7 ] = ( T_1 ) ( 0xff & ( V_43 >> 0 ) ) ;
V_1 [ 8 ] = ( T_1 ) V_45 ;
V_1 [ 9 ] = ( T_1 ) ( V_103 ? 1 : 0 ) + ( V_104 << 1 ) ;
F_25 ( & V_1 [ 10 ] , V_105 ) ;
if ( ! F_21 ( V_92 , & V_102 , sizeof V_102 , V_7 ) )
return FALSE ;
if ( ! F_20 ( V_92 , V_1 , 12 , V_7 ) )
return FALSE ;
if ( ! F_20 ( V_92 , V_37 , V_105 , V_7 ) )
return FALSE ;
return TRUE ;
}
