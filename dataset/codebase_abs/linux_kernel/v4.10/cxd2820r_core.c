int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
int V_8 ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
struct V_13 * V_13 ;
F_2 ( & V_7 -> V_14 , L_1 , V_5 ) ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ ) {
if ( ( V_4 [ V_9 ] . V_10 >> 16 ) & 0x1 )
V_13 = V_2 -> V_13 [ 1 ] ;
else
V_13 = V_2 -> V_13 [ 0 ] ;
V_10 = ( V_4 [ V_9 ] . V_10 >> 0 ) & 0xffff ;
V_12 = V_4 [ V_9 ] . V_12 ;
V_11 = V_4 [ V_9 ] . V_11 ;
if ( V_11 == 0xff )
V_8 = F_3 ( V_13 , V_10 , V_12 ) ;
else
V_8 = F_4 ( V_13 , V_10 , V_11 , V_12 ) ;
if ( V_8 )
goto error;
}
return 0 ;
error:
F_2 ( & V_7 -> V_14 , L_2 , V_8 ) ;
return V_8 ;
}
int F_5 ( struct V_15 * V_16 , T_1 * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 , V_9 ;
T_1 V_22 , V_23 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
if ( ! memcmp ( V_17 , V_2 -> V_17 , sizeof( V_2 -> V_17 ) ) )
return 0 ;
V_22 = 0x00 ;
V_23 = 0x00 ;
for ( V_9 = 0 ; V_9 < sizeof( V_2 -> V_17 ) ; V_9 ++ ) {
if ( V_17 [ V_9 ] & V_25 )
V_22 |= ( 2 << 6 ) >> ( 2 * V_9 ) ;
else
V_22 |= ( 1 << 6 ) >> ( 2 * V_9 ) ;
if ( V_17 [ V_9 ] & V_26 )
V_23 |= ( 1 << ( 3 + V_9 ) ) ;
else
V_23 |= ( 0 << ( 3 + V_9 ) ) ;
if ( V_17 [ V_9 ] & V_27 )
V_23 |= ( 1 << ( 0 + V_9 ) ) ;
else
V_23 |= ( 0 << ( 0 + V_9 ) ) ;
F_2 ( & V_7 -> V_14 , L_4 , V_9 , V_22 , V_23 ) ;
}
F_2 ( & V_7 -> V_14 , L_5 , V_22 , V_23 ) ;
V_8 = F_6 ( V_2 -> V_13 [ 0 ] , 0x0089 , 0xfc , V_22 ) ;
if ( V_8 )
goto error;
V_8 = F_6 ( V_2 -> V_13 [ 0 ] , 0x008e , 0x3f , V_23 ) ;
if ( V_8 )
goto error;
memcpy ( V_2 -> V_17 , V_17 , sizeof( V_2 -> V_17 ) ) ;
return V_8 ;
error:
F_2 ( & V_7 -> V_14 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
switch ( V_20 -> V_24 ) {
case V_28 :
V_8 = F_8 ( V_16 ) ;
if ( V_8 < 0 )
goto V_29;
V_8 = F_9 ( V_16 ) ;
if ( V_8 < 0 )
goto V_29;
break;
case V_30 :
V_8 = F_8 ( V_16 ) ;
if ( V_8 < 0 )
goto V_29;
V_8 = F_10 ( V_16 ) ;
if ( V_8 < 0 )
goto V_29;
break;
case V_31 :
V_8 = F_11 ( V_16 ) ;
if ( V_8 < 0 )
goto V_29;
V_8 = F_12 ( V_16 ) ;
if ( V_8 < 0 )
goto V_29;
break;
default:
F_2 ( & V_7 -> V_14 , L_6 ) ;
V_8 = - V_32 ;
break;
}
V_29:
return V_8 ;
}
static int F_13 ( struct V_15 * V_16 , enum V_33 * V_34 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
switch ( V_20 -> V_24 ) {
case V_28 :
V_8 = F_14 ( V_16 , V_34 ) ;
break;
case V_30 :
V_8 = F_15 ( V_16 , V_34 ) ;
break;
case V_31 :
V_8 = F_16 ( V_16 , V_34 ) ;
break;
default:
V_8 = - V_32 ;
break;
}
return V_8 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_19 * V_35 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
if ( V_2 -> V_24 == V_36 )
return 0 ;
switch ( V_20 -> V_24 ) {
case V_28 :
V_8 = F_18 ( V_16 , V_35 ) ;
break;
case V_30 :
V_8 = F_19 ( V_16 , V_35 ) ;
break;
case V_31 :
V_8 = F_20 ( V_16 , V_35 ) ;
break;
default:
V_8 = - V_32 ;
break;
}
return V_8 ;
}
static int F_21 ( struct V_15 * V_16 , T_2 * V_37 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
* V_37 = ( V_2 -> V_38 - V_2 -> V_39 ) ;
V_2 -> V_39 = V_2 -> V_38 ;
return 0 ;
}
static int F_22 ( struct V_15 * V_16 , T_3 * V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
if ( V_20 -> V_40 . V_41 [ 0 ] . V_42 == V_43 )
* V_40 = V_20 -> V_40 . V_41 [ 0 ] . V_44 ;
else
* V_40 = 0 ;
return 0 ;
}
static int F_23 ( struct V_15 * V_16 , T_3 * V_45 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
if ( V_20 -> V_46 . V_41 [ 0 ] . V_42 == V_47 )
* V_45 = F_24 ( V_20 -> V_46 . V_41 [ 0 ] . V_48 , 100 ) ;
else
* V_45 = 0 ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 , T_2 * V_49 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
* V_49 = 0 ;
return 0 ;
}
static int F_26 ( struct V_15 * V_16 )
{
return 0 ;
}
static int F_27 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
switch ( V_20 -> V_24 ) {
case V_28 :
V_8 = F_28 ( V_16 ) ;
break;
case V_30 :
V_8 = F_29 ( V_16 ) ;
break;
case V_31 :
V_8 = F_30 ( V_16 ) ;
break;
default:
V_8 = - V_32 ;
break;
}
return V_8 ;
}
static int F_31 ( struct V_15 * V_16 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
switch ( V_20 -> V_24 ) {
case V_28 :
V_8 = F_32 ( V_16 , V_51 ) ;
break;
case V_30 :
V_8 = F_33 ( V_16 , V_51 ) ;
break;
case V_31 :
V_8 = F_34 ( V_16 , V_51 ) ;
break;
default:
V_8 = - V_32 ;
break;
}
return V_8 ;
}
static enum V_52 F_35 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
struct V_19 * V_20 = & V_16 -> V_21 ;
int V_8 , V_9 ;
enum V_33 V_34 = 0 ;
F_2 ( & V_7 -> V_14 , L_3 , V_20 -> V_24 ) ;
if ( V_2 -> V_53 ) {
if ( V_2 -> V_24 == V_28 ) {
V_8 = F_28 ( V_16 ) ;
if ( V_8 )
goto error;
V_20 -> V_24 = V_30 ;
} else if ( V_2 -> V_24 == V_30 ) {
V_8 = F_29 ( V_16 ) ;
if ( V_8 )
goto error;
V_20 -> V_24 = V_28 ;
}
}
V_8 = F_7 ( V_16 ) ;
if ( V_8 )
goto error;
switch ( V_2 -> V_24 ) {
case V_28 :
case V_31 :
V_9 = 20 ;
break;
case V_30 :
V_9 = 40 ;
break;
case V_36 :
default:
V_9 = 0 ;
break;
}
for (; V_9 > 0 ; V_9 -- ) {
F_2 ( & V_7 -> V_14 , L_7 , V_9 ) ;
F_36 ( 50 ) ;
V_8 = F_13 ( V_16 , & V_34 ) ;
if ( V_8 )
goto error;
if ( V_34 & V_54 )
break;
}
if ( V_34 & V_54 ) {
V_2 -> V_53 = false ;
return V_55 ;
} else {
V_2 -> V_53 = true ;
return V_56 ;
}
error:
F_2 ( & V_7 -> V_14 , L_2 , V_8 ) ;
return V_57 ;
}
static int F_37 ( struct V_15 * V_16 )
{
return V_58 ;
}
static void F_38 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
F_2 ( & V_7 -> V_14 , L_8 ) ;
F_39 ( V_7 ) ;
return;
}
static int F_40 ( struct V_15 * V_16 , int V_59 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
F_41 ( & V_7 -> V_14 , L_9 , V_59 ) ;
return F_6 ( V_2 -> V_13 [ 0 ] , 0x00db , 0x01 , V_59 ? 1 : 0 ) ;
}
static int F_42 ( struct V_60 * V_61 , unsigned V_62 ,
int V_12 )
{
struct V_1 * V_2 = F_43 ( V_61 ) ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
T_1 V_17 [ V_63 ] ;
F_2 ( & V_7 -> V_14 , L_10 , V_62 , V_12 ) ;
memcpy ( V_17 , V_2 -> V_17 , sizeof( V_17 ) ) ;
V_17 [ V_62 ] = V_25 | V_64 | ( V_12 << 2 ) ;
return F_5 ( & V_2 -> V_16 , V_17 ) ;
}
static void F_44 ( struct V_60 * V_61 , unsigned V_62 , int V_12 )
{
struct V_1 * V_2 = F_43 ( V_61 ) ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
T_1 V_17 [ V_63 ] ;
F_2 ( & V_7 -> V_14 , L_10 , V_62 , V_12 ) ;
memcpy ( V_17 , V_2 -> V_17 , sizeof( V_17 ) ) ;
V_17 [ V_62 ] = V_25 | V_64 | ( V_12 << 2 ) ;
( void ) F_5 ( & V_2 -> V_16 , V_17 ) ;
return;
}
static int F_45 ( struct V_60 * V_61 , unsigned V_62 )
{
struct V_1 * V_2 = F_43 ( V_61 ) ;
struct V_6 * V_7 = V_2 -> V_7 [ 0 ] ;
F_2 ( & V_7 -> V_14 , L_11 , V_62 ) ;
return ( V_2 -> V_17 [ V_62 ] >> 2 ) & 0x01 ;
}
struct V_15 * F_46 ( const struct V_65 * V_66 ,
struct V_67 * V_68 ,
int * V_69 )
{
struct V_6 * V_7 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
V_73 . V_74 = V_66 -> V_74 ;
V_73 . V_75 = V_66 -> V_76 ;
V_73 . V_77 = V_66 -> V_77 ;
V_73 . V_78 = V_66 -> V_78 ;
V_73 . V_69 = & V_69 ;
V_73 . V_79 = true ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
F_47 ( V_71 . type , L_12 , V_80 ) ;
V_71 . V_81 = V_66 -> V_82 ;
V_71 . V_83 = & V_73 ;
V_7 = F_48 ( V_68 , & V_71 ) ;
if ( ! V_7 || ! V_7 -> V_14 . V_84 )
return NULL ;
return V_73 . V_85 ( V_7 ) ;
}
static struct V_15 * F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_50 ( V_7 ) ;
F_2 ( & V_7 -> V_14 , L_8 ) ;
return & V_2 -> V_16 ;
}
static int F_51 ( struct V_6 * V_7 ,
const struct V_86 * V_87 )
{
struct V_72 * V_73 = V_7 -> V_14 . V_83 ;
struct V_1 * V_2 ;
int V_8 , * V_69 ;
unsigned int V_88 ;
static const struct V_89 V_90 [] = {
{
. V_91 = 0x0000 ,
. V_92 = 0x3fff ,
. V_93 = 0x00 ,
. V_94 = 0xff ,
. V_95 = 0 ,
. V_96 = 0x00 ,
. V_97 = 0x100 ,
} ,
} ;
static const struct V_89 V_98 [] = {
{
. V_91 = 0x0000 ,
. V_92 = 0x01ff ,
. V_93 = 0x00 ,
. V_94 = 0xff ,
. V_95 = 0 ,
. V_96 = 0x00 ,
. V_97 = 0x100 ,
} ,
} ;
static const struct V_99 V_100 = {
. V_101 = 8 ,
. V_102 = 8 ,
. V_103 = 0x3fff ,
. V_104 = V_90 ,
. V_105 = F_52 ( V_90 ) ,
. V_106 = V_107 ,
} ;
static const struct V_99 V_108 = {
. V_101 = 8 ,
. V_102 = 8 ,
. V_103 = 0x01ff ,
. V_104 = V_98 ,
. V_105 = F_52 ( V_98 ) ,
. V_106 = V_107 ,
} ;
F_2 ( & V_7 -> V_14 , L_8 ) ;
V_2 = F_53 ( sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 ) {
V_8 = - V_110 ;
goto V_29;
}
V_2 -> V_7 [ 0 ] = V_7 ;
V_2 -> V_111 = V_7 -> V_68 ;
V_2 -> V_74 = V_73 -> V_74 ;
V_2 -> V_75 = V_73 -> V_75 ;
V_2 -> V_77 = V_73 -> V_77 ;
V_2 -> V_78 = V_73 -> V_78 ;
V_69 = * V_73 -> V_69 ;
V_2 -> V_13 [ 0 ] = F_54 ( V_2 -> V_7 [ 0 ] , & V_100 ) ;
if ( F_55 ( V_2 -> V_13 [ 0 ] ) ) {
V_8 = F_56 ( V_2 -> V_13 [ 0 ] ) ;
goto V_112;
}
V_8 = F_57 ( V_2 -> V_13 [ 0 ] , 0x00fd , & V_88 ) ;
if ( V_8 )
goto V_113;
F_2 ( & V_7 -> V_14 , L_13 , V_88 ) ;
if ( V_88 != 0xe1 ) {
V_8 = - V_114 ;
goto V_113;
}
V_2 -> V_7 [ 1 ] = F_58 ( V_7 -> V_68 , V_7 -> V_81 | ( 1 << 1 ) ) ;
if ( ! V_2 -> V_7 [ 1 ] ) {
V_8 = - V_114 ;
F_59 ( & V_7 -> V_14 , L_14 ) ;
if ( V_8 )
goto V_113;
}
V_2 -> V_13 [ 1 ] = F_54 ( V_2 -> V_7 [ 1 ] , & V_108 ) ;
if ( F_55 ( V_2 -> V_13 [ 1 ] ) ) {
V_8 = F_56 ( V_2 -> V_13 [ 1 ] ) ;
goto V_115;
}
if ( V_69 ) {
#ifdef F_60
V_2 -> V_60 . V_116 = V_117 ;
V_2 -> V_60 . V_118 = & V_7 -> V_14 ;
V_2 -> V_60 . V_119 = V_120 ;
V_2 -> V_60 . V_121 = F_42 ;
V_2 -> V_60 . V_122 = F_44 ;
V_2 -> V_60 . V_123 = F_45 ;
V_2 -> V_60 . V_124 = - 1 ;
V_2 -> V_60 . V_125 = V_63 ;
V_2 -> V_60 . V_126 = 1 ;
V_8 = F_61 ( & V_2 -> V_60 , V_2 ) ;
if ( V_8 )
goto V_127;
F_2 ( & V_7 -> V_14 , L_15 ,
V_2 -> V_60 . V_124 ) ;
* V_69 = V_2 -> V_60 . V_124 ;
#else
T_1 V_17 [ V_63 ] ;
V_17 [ 0 ] = ( * V_69 >> 0 ) & 0x07 ;
V_17 [ 1 ] = ( * V_69 >> 3 ) & 0x07 ;
V_17 [ 2 ] = 0 ;
V_8 = F_5 ( & V_2 -> V_16 , V_17 ) ;
if ( V_8 )
goto V_127;
#endif
}
memcpy ( & V_2 -> V_16 . V_128 , & V_129 , sizeof( V_2 -> V_16 . V_128 ) ) ;
if ( ! V_73 -> V_79 )
V_2 -> V_16 . V_128 . V_130 = NULL ;
V_2 -> V_16 . V_18 = V_2 ;
F_62 ( V_7 , V_2 ) ;
V_73 -> V_85 = F_49 ;
F_63 ( & V_7 -> V_14 , L_16 ) ;
return 0 ;
V_127:
F_64 ( V_2 -> V_13 [ 1 ] ) ;
V_115:
F_39 ( V_2 -> V_7 [ 1 ] ) ;
V_113:
F_64 ( V_2 -> V_13 [ 0 ] ) ;
V_112:
F_65 ( V_2 ) ;
V_29:
F_2 ( & V_7 -> V_14 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_50 ( V_7 ) ;
F_2 ( & V_7 -> V_14 , L_8 ) ;
#ifdef F_60
if ( V_2 -> V_60 . V_116 )
F_67 ( & V_2 -> V_60 ) ;
#endif
F_64 ( V_2 -> V_13 [ 1 ] ) ;
F_39 ( V_2 -> V_7 [ 1 ] ) ;
F_64 ( V_2 -> V_13 [ 0 ] ) ;
F_65 ( V_2 ) ;
return 0 ;
}
