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
T_1 * V_1 ;
int V_32 ;
V_31 = F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_31 < 1 )
return FALSE ;
V_32 = F_8 ( V_6 -> V_3 , & V_6 -> V_33 , V_7 , V_8 ) ;
if ( V_32 == - 1 )
return FALSE ;
F_9 ( V_6 -> V_34 , V_35 ) ;
V_1 = F_10 ( V_6 -> V_34 ) ;
if ( ! F_11 ( V_6 -> V_3 , V_32 , V_1 , V_7 , V_8 ) )
return FALSE ;
* V_30 = V_31 ;
return TRUE ;
}
static T_6
V_27 ( T_4 * V_6 , T_3 V_36 , struct V_37 * V_33 ,
T_1 * V_38 , int V_2 , int * V_7 , T_5 * * V_8 )
{
int V_32 ;
if ( F_12 ( V_6 -> V_39 , V_36 , V_40 , V_7 ) == - 1 )
return FALSE ;
V_32 = F_8 ( V_6 -> V_39 , V_33 , V_7 , V_8 ) ;
if ( V_32 != V_2 ) {
if ( V_32 != - 1 ) {
* V_7 = V_41 ;
* V_8 = F_13 ( L_1 ,
V_2 , V_32 ) ;
}
return FALSE ;
}
return F_11 ( V_6 -> V_39 , V_32 , V_38 , V_7 ,
V_8 ) ;
}
static int
F_8 ( T_2 V_3 , struct V_37 * V_33 ,
int * V_7 , T_5 * * V_8 )
{
union V_42 * V_43 = & V_33 -> V_43 ;
T_1 V_44 [ V_45 ] ;
T_7 V_46 ;
int V_47 ;
int V_32 ;
T_1 V_48 , V_49 ;
if ( F_1 ( V_44 , V_45 , V_3 ) != V_45 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_17 ;
return - 1 ;
}
V_47 = F_14 ( & V_44 [ 0 ] ) ;
#ifdef F_15
V_46 = V_44 [ 3 ] ;
#else
V_46 = 0 ;
#endif
V_46 = ( V_46 << 8 ) | V_44 [ 4 ] ;
V_46 = ( V_46 << 8 ) | V_44 [ 5 ] ;
V_46 = ( V_46 << 8 ) | V_44 [ 6 ] ;
V_46 = ( V_46 << 8 ) | V_44 [ 7 ] ;
V_48 = V_44 [ 8 ] ;
V_49 = V_44 [ 9 ] ;
V_32 = F_16 ( & V_44 [ 10 ] ) ;
switch( V_49 >> 1 ) {
default:
case V_50 :
V_43 -> V_51 . V_52 = V_49 & 1 ;
V_43 -> V_51 . V_48 = V_48 ;
if( V_48 ) {
V_33 -> V_53 = V_54 ;
V_43 -> V_51 . V_52 = ! V_43 -> V_51 . V_52 ;
} else {
V_33 -> V_53 = V_54 ;
}
break;
case V_55 :
V_33 -> V_53 = V_56 ;
V_43 -> V_57 . V_52 = ( V_49 & 1 ) ;
break;
case V_58 :
V_33 -> V_53 = V_59 ;
V_43 -> V_60 . V_61 = ( V_49 & 1 ) ? 0 : 0x80 ;
break;
case V_62 : {
#define F_17 53
unsigned char V_63 [ F_17 ] ;
T_3 V_10 ;
if( V_32 != F_17 ) {
* V_7 = V_41 ;
* V_8 = F_13 (
L_2 ,
V_32 ) ;
return - 1 ;
}
V_10 = F_4 ( V_3 ) ;
if ( F_1 ( V_63 , F_17 , V_3 ) != F_17 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_17 ;
return - 1 ;
}
if ( F_12 ( V_3 , V_10 , V_40 , V_7 ) == - 1 )
return - 1 ;
V_33 -> V_53 = V_64 ;
V_43 -> V_65 . V_61 = V_66 ;
V_43 -> V_65 . V_67 = V_68 ;
V_43 -> V_65 . type = V_69 ;
V_43 -> V_65 . V_70 = V_71 ;
V_43 -> V_65 . V_72 = ( ( V_63 [ 0 ] & 0xf ) << 4 ) + ( V_63 [ 0 ] & 0xf ) ;
V_43 -> V_65 . V_73 = ( ( V_63 [ 0 ] & 0xf ) << 4 ) + V_63 [ 0 ] ;
V_43 -> V_65 . V_48 = V_49 & 1 ;
}
break;
case V_74 :
V_43 -> V_75 . V_76 = V_49 & 1 ;
V_43 -> V_75 . V_77 = V_78 ;
V_43 -> V_75 . V_79 = V_48 ;
V_33 -> V_53 = V_80 ;
break;
case V_81 :
V_43 -> V_51 . V_52 = V_49 & 1 ;
V_43 -> V_51 . V_48 = V_48 ;
V_33 -> V_53 = V_82 ;
break;
case V_83 :
V_43 -> V_51 . V_52 = V_49 & 1 ;
V_43 -> V_51 . V_48 = V_48 ;
V_33 -> V_53 = V_82 ;
break;
case V_84 :
V_43 -> V_51 . V_52 = V_49 & 1 ;
V_43 -> V_51 . V_48 = V_48 ;
V_33 -> V_53 = V_85 ;
break;
case V_86 :
V_43 -> V_51 . V_52 = V_49 & 1 ;
V_43 -> V_51 . V_48 = V_48 ;
V_33 -> V_53 = V_87 ;
break;
}
if( V_32 > V_35 ) {
* V_7 = V_41 ;
* V_8 = F_13 ( L_3 ,
V_32 , V_35 ) ;
return - 1 ;
}
V_33 -> V_88 = V_89 ;
V_33 -> V_90 . V_46 = V_46 ;
V_33 -> V_90 . V_91 = V_47 * 1000 ;
V_33 -> V_92 = V_32 ;
V_33 -> V_2 = V_32 ;
return V_32 ;
}
static T_6
F_11 ( T_2 V_3 , int V_32 , T_1 * V_1 , int * V_7 ,
T_5 * * V_8 )
{
int V_12 ;
V_15 = V_16 ;
V_12 = F_1 ( V_1 , V_32 , V_3 ) ;
if ( V_12 != V_32 ) {
if ( V_12 == - 2 ) {
* V_7 = F_5 ( V_3 , V_8 ) ;
if ( * V_7 == 0 )
* V_7 = V_17 ;
} else if ( V_12 == - 1 ) {
* V_7 = V_41 ;
* V_8 = F_18 ( L_4 ) ;
} else
* V_7 = V_17 ;
return FALSE ;
}
return TRUE ;
}
static T_6
F_19 ( T_8 * V_93 , const T_1 * V_1 , int V_2 , int * V_7 )
{
int V_4 ;
T_1 V_9 ;
static const T_1 V_94 = 0xfe ;
for( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
V_9 = V_1 [ V_4 ] ;
if( V_9 == 0xff || V_9 == 0xfe ) {
if ( ! F_20 ( V_93 , & V_94 , sizeof V_94 , V_7 ) )
return FALSE ;
V_9 -= 2 ;
}
if ( ! F_20 ( V_93 , & V_9 , sizeof V_9 , V_7 ) )
return FALSE ;
}
return TRUE ;
}
T_6 F_21 ( T_8 * V_93 , int * V_7 )
{
V_93 -> V_95 = V_96 ;
V_93 -> V_97 = NULL ;
if ( ! F_20 ( V_93 , V_18 ,
V_14 , V_7 ) )
return FALSE ;
V_93 -> V_98 += V_14 ;
* V_7 = 0 ;
return TRUE ;
}
int F_22 ( int V_99 )
{
switch ( V_99 ) {
case V_54 :
case V_56 :
case V_82 :
case V_64 :
case V_59 :
case V_80 :
case V_85 :
case V_20 :
return 0 ;
default:
return V_100 ;
}
}
static T_6 V_96 ( T_8 * V_93 ,
const struct V_37 * V_33 ,
const T_1 * V_38 , int * V_7 )
{
static const T_1 V_101 = 0xff ;
const union V_42 * V_43 = & V_33 -> V_43 ;
T_1 V_1 [ V_45 ] ;
int V_47 ;
T_7 V_46 ;
int V_48 ;
int V_102 ;
int V_103 ;
int V_104 ;
V_47 = V_33 -> V_90 . V_91 / 1000 ;
V_46 = V_33 -> V_90 . V_46 ;
V_104 = V_33 -> V_92 ;
V_102 = V_43 -> V_51 . V_52 ;
V_48 = V_43 -> V_51 . V_48 ;
switch( V_33 -> V_53 ) {
case V_54 :
V_103 = V_50 ;
break;
case V_56 :
V_103 = V_55 ;
break;
case V_82 :
V_103 = V_81 ;
break;
#if 0
case WTAP_ENCAP_DASS2:
protocol=EYESDN_ENCAP_DASS2;
break;
#endif
case V_64 :
V_103 = V_62 ;
V_48 = 0x80 ;
break;
case V_59 :
V_103 = V_58 ;
break;
case V_80 :
V_103 = V_74 ;
break;
case V_85 :
V_103 = V_84 ;
break;
case V_87 :
V_103 = V_86 ;
break;
default:
* V_7 = V_100 ;
return FALSE ;
}
F_23 ( & V_1 [ 0 ] , V_47 ) ;
V_1 [ 3 ] = ( T_1 ) 0 ;
V_1 [ 4 ] = ( T_1 ) ( 0xff & ( V_46 >> 24 ) ) ;
V_1 [ 5 ] = ( T_1 ) ( 0xff & ( V_46 >> 16 ) ) ;
V_1 [ 6 ] = ( T_1 ) ( 0xff & ( V_46 >> 8 ) ) ;
V_1 [ 7 ] = ( T_1 ) ( 0xff & ( V_46 >> 0 ) ) ;
V_1 [ 8 ] = ( T_1 ) V_48 ;
V_1 [ 9 ] = ( T_1 ) ( V_102 ? 1 : 0 ) + ( V_103 << 1 ) ;
F_24 ( & V_1 [ 10 ] , V_104 ) ;
if ( ! F_20 ( V_93 , & V_101 , sizeof V_101 , V_7 ) )
return FALSE ;
if ( ! F_19 ( V_93 , V_1 , 12 , V_7 ) )
return FALSE ;
if ( ! F_19 ( V_93 , V_38 , V_104 , V_7 ) )
return FALSE ;
return TRUE ;
}
