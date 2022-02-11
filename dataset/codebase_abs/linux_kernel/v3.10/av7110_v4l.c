int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 V_5 [ 5 ] = { V_2 , V_3 >> 8 , V_3 & 0xff , V_4 >> 8 , V_4 & 0xff } ;
struct V_6 V_7 = { . V_8 = 0 , . V_9 = 5 , . V_10 = V_5 } ;
switch ( V_1 -> V_11 ) {
case V_12 :
V_7 . V_13 = 0x40 ;
break;
case V_14 :
V_7 . V_13 = 0x42 ;
break;
default:
return 0 ;
}
if ( F_2 ( & V_1 -> V_15 , & V_7 , 1 ) != 1 ) {
F_3 ( 1 , L_1 ,
V_1 -> V_16 . V_17 , V_3 , V_4 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 , T_2 * V_4 )
{
T_1 V_19 [ 3 ] = { V_2 , V_3 >> 8 , V_3 & 0xff } ;
T_1 V_20 [ 2 ] ;
struct V_6 V_7 [ 2 ] = {
{ . V_8 = 0 , . V_9 = 3 , . V_10 = V_19 } ,
{ . V_8 = V_21 , . V_9 = 2 , . V_10 = V_20 }
} ;
switch ( V_1 -> V_11 ) {
case V_12 :
V_7 [ 0 ] . V_13 = 0x40 ;
V_7 [ 1 ] . V_13 = 0x40 ;
break;
case V_14 :
V_7 [ 0 ] . V_13 = 0x42 ;
V_7 [ 1 ] . V_13 = 0x42 ;
break;
default:
return 0 ;
}
if ( F_2 ( & V_1 -> V_15 , & V_7 [ 0 ] , 2 ) != 2 ) {
F_3 ( 1 , L_2 ,
V_1 -> V_16 . V_17 , V_3 ) ;
return - V_18 ;
}
* V_4 = ( V_20 [ 0 ] << 8 ) | V_20 [ 1 ] ;
return 0 ;
}
static int F_5 ( struct V_22 * V_2 , T_1 V_13 , T_1 V_3 , T_1 V_23 )
{
struct V_1 * V_1 = V_2 -> V_24 ;
T_1 V_10 [] = { 0x00 , V_3 , V_23 } ;
struct V_6 V_5 = { . V_13 = V_13 , . V_8 = 0 , . V_10 = V_10 , . V_9 = 3 } ;
F_3 ( 4 , L_3 , V_2 ) ;
if ( 1 != F_2 ( & V_1 -> V_15 , & V_5 , 1 ) )
return - 1 ;
return 0 ;
}
static int F_6 ( struct V_22 * V_2 , T_1 V_13 , T_1 V_23 [ 4 ] )
{
struct V_1 * V_1 = V_2 -> V_24 ;
struct V_6 V_5 = { . V_13 = V_13 , . V_8 = 0 , . V_10 = V_23 , . V_9 = 4 } ;
F_3 ( 4 , L_3 , V_2 ) ;
if ( 1 != F_2 ( & V_1 -> V_15 , & V_5 , 1 ) )
return - 1 ;
return 0 ;
}
static int F_7 ( struct V_22 * V_2 , T_3 V_25 )
{
T_3 div ;
T_1 V_26 ;
T_1 V_10 [ 4 ] ;
F_3 ( 4 , L_4 , V_25 ) ;
div = V_25 + 614 ;
V_10 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_10 [ 1 ] = div & 0xff ;
V_10 [ 2 ] = 0x8e ;
if ( V_25 < ( T_3 ) ( 16 * 168.25 ) )
V_26 = 0xa0 ;
else if ( V_25 < ( T_3 ) ( 16 * 447.25 ) )
V_26 = 0x90 ;
else
V_26 = 0x30 ;
V_26 &= ~ 0x02 ;
V_10 [ 3 ] = V_26 ;
return F_6 ( V_2 , 0x61 , V_10 ) ;
}
static int F_8 ( struct V_22 * V_2 , T_3 V_25 )
{
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
T_3 div ;
T_1 V_23 [ 4 ] ;
div = ( V_25 + 38900000 + 31250 ) / 62500 ;
V_23 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_23 [ 1 ] = div & 0xff ;
V_23 [ 2 ] = 0xce ;
if ( V_25 < 45000000 )
return - V_27 ;
else if ( V_25 < 137000000 )
V_23 [ 3 ] = 0x01 ;
else if ( V_25 < 403000000 )
V_23 [ 3 ] = 0x02 ;
else if ( V_25 < 860000000 )
V_23 [ 3 ] = 0x04 ;
else
return - V_27 ;
if ( V_1 -> V_28 -> V_29 . V_30 )
V_1 -> V_28 -> V_29 . V_30 ( V_1 -> V_28 , 1 ) ;
return F_6 ( V_2 , 0x63 , V_23 ) ;
}
static int F_9 ( struct V_31 * V_32 )
{
struct V_22 * V_2 = V_32 -> V_2 ;
struct V_33 * V_34 = V_2 -> V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
T_2 V_36 ;
int V_37 , V_38 , V_39 ;
F_3 ( 4 , L_5 , V_1 ) ;
if ( ( V_34 -> V_40 & V_41 ) != 0 ) {
V_34 -> V_42 = V_34 -> V_43 ;
V_39 = F_10 ( V_34 -> V_43 ) ;
if ( V_39 != 0 ) {
F_3 ( 2 , L_6 ) ;
V_34 -> V_42 = NULL ;
}
}
if ( 0 != V_1 -> V_44 ) {
F_3 ( 1 , L_7 ) ;
V_36 = 1 ;
V_37 = V_45 ;
V_38 = V_46 ;
memcpy ( V_47 , V_48 , sizeof( struct V_49 ) * 2 ) ;
switch ( V_1 -> V_44 ) {
case 1 :
F_3 ( 1 , L_8 ) ;
F_1 ( V_1 , V_50 , 0x0008 , 0x0000 ) ;
F_1 ( V_1 , V_50 , 0x0009 , 0x0000 ) ;
F_1 ( V_1 , V_50 , 0x000a , 0x0000 ) ;
F_1 ( V_1 , V_50 , 0x000e , 0x3000 ) ;
F_1 ( V_1 , V_50 , 0x0000 , 0x4f00 ) ;
F_1 ( V_1 , V_50 , 0x0007 , 0x4f00 ) ;
if ( V_1 -> V_51 & V_52 ) {
if ( F_5 ( V_2 , 0x09 , 0x0f , 0x60 ) )
F_3 ( 1 , L_9 ) ;
} else if ( V_1 -> V_51 & V_53 ) {
F_11 ( V_2 , 1 , V_54 ) ;
F_11 ( V_2 , 3 , V_54 ) ;
}
if ( F_12 ( V_1 , 0x48 , 0x02 , 0xd0 ) != 1 )
F_3 ( 1 , L_10 , V_1 -> V_16 . V_17 ) ;
break;
case 2 :
F_3 ( 1 , L_11 ) ;
if ( F_12 ( V_1 , 0x48 , 0x02 , 0xd2 ) != 1 )
F_3 ( 1 , L_10 , V_1 -> V_16 . V_17 ) ;
break;
case 3 :
F_3 ( 1 , L_12 ) ;
if ( F_12 ( V_1 , 0x48 , 0x02 , 0xd9 ) != 1 )
F_3 ( 1 , L_10 , V_1 -> V_16 . V_17 ) ;
break;
default:
F_3 ( 1 , L_13 ) ;
}
} else {
V_36 = 0 ;
V_37 = V_55 ;
V_38 = V_56 ;
memcpy ( V_47 , V_57 , sizeof( struct V_49 ) * 2 ) ;
F_3 ( 1 , L_14 ) ;
F_1 ( V_1 , V_50 , 0x0008 , 0x0220 ) ;
F_1 ( V_1 , V_50 , 0x0009 , 0x0220 ) ;
F_1 ( V_1 , V_50 , 0x000a , 0x0220 ) ;
F_1 ( V_1 , V_50 , 0x000e , 0x3000 ) ;
F_1 ( V_1 , V_50 , 0x0000 , 0x7f00 ) ;
F_1 ( V_1 , V_50 , 0x0007 , 0x7f00 ) ;
if ( V_1 -> V_51 & V_52 ) {
if ( F_5 ( V_2 , 0x09 , 0x0f , 0x20 ) )
F_3 ( 1 , L_9 ) ;
} else if ( V_1 -> V_51 & V_53 ) {
F_11 ( V_2 , 1 , V_58 ) ;
F_11 ( V_2 , 3 , V_58 ) ;
}
}
if ( F_13 ( V_1 , V_59 , V_60 , 1 , V_36 ) )
F_3 ( 1 , L_15 ) ;
F_14 ( V_2 , V_37 , V_38 ) ;
if ( V_34 -> V_42 != NULL ) {
F_15 ( V_34 -> V_42 ) ;
V_34 -> V_42 = NULL ;
}
return 0 ;
}
static int F_16 ( struct V_61 * V_61 , void * V_32 , struct V_62 * V_63 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
T_2 V_64 ;
T_4 V_65 ;
F_3 ( 2 , L_16 , V_63 -> V_66 ) ;
if ( ! V_1 -> V_51 || V_63 -> V_66 != 0 )
return - V_27 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
strcpy ( ( char * ) V_63 -> V_67 , L_17 ) ;
V_63 -> type = V_68 ;
V_63 -> V_69 = V_70 | V_71 |
V_72 | V_73 | V_74 ;
V_63 -> V_75 = 772 ;
V_63 -> V_76 = 13684 ;
V_63 -> signal = 0xffff ;
V_63 -> V_77 = 0 ;
F_4 ( V_1 , V_78 , 0x007e , & V_64 ) ;
F_3 ( 1 , L_18 , V_64 ) ;
F_4 ( V_1 , V_79 , 0x0018 , & V_64 ) ;
F_3 ( 1 , L_19 , V_64 ) ;
V_65 = ( T_4 ) ( V_64 >> 8 ) ;
if ( V_65 > 0x10 ) {
V_63 -> V_80 = V_81 | V_82 ;
V_63 -> V_83 = V_84 ;
} else if ( V_65 < - 0x10 ) {
V_63 -> V_80 = V_85 | V_86 ;
V_63 -> V_83 = V_87 ;
} else
V_63 -> V_80 = V_82 ;
return 0 ;
}
static int F_17 ( struct V_61 * V_61 , void * V_32 , const struct V_62 * V_63 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
T_2 V_88 , V_89 ;
F_3 ( 2 , L_20 , V_63 -> V_66 ) ;
if ( ! V_1 -> V_51 || V_1 -> V_44 != 1 )
return - V_27 ;
switch ( V_63 -> V_83 ) {
case V_84 :
F_3 ( 2 , L_21 ) ;
V_88 = 0x3001 ;
V_89 = 0x0020 ;
break;
case V_90 :
F_3 ( 2 , L_22 ) ;
V_88 = 0x3000 ;
V_89 = 0x0020 ;
break;
case V_87 :
F_3 ( 2 , L_23 ) ;
V_88 = 0x3000 ;
V_89 = 0x0000 ;
break;
case V_91 :
F_3 ( 2 , L_24 ) ;
V_88 = 0x3000 ;
V_89 = 0x0010 ;
break;
default:
F_3 ( 2 , L_25 ) ;
V_88 = 0x3000 ;
V_89 = 0x0030 ;
break;
}
F_1 ( V_1 , V_50 , 0x000e , V_88 ) ;
F_1 ( V_1 , V_50 , 0x0008 , V_89 ) ;
F_1 ( V_1 , V_50 , 0x0009 , V_89 ) ;
F_1 ( V_1 , V_50 , 0x000a , V_89 ) ;
return 0 ;
}
static int F_18 ( struct V_61 * V_61 , void * V_32 , struct V_92 * V_93 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_26 , V_93 -> V_94 ) ;
if ( ! V_1 -> V_51 || V_1 -> V_44 != 1 )
return - V_27 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> type = V_68 ;
V_93 -> V_94 = V_1 -> V_95 ;
return 0 ;
}
static int F_19 ( struct V_61 * V_61 , void * V_32 , const struct V_92 * V_93 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_27 , V_93 -> V_94 ) ;
if ( ! V_1 -> V_51 || V_1 -> V_44 != 1 )
return - V_27 ;
if ( V_68 != V_93 -> type )
return - V_27 ;
F_1 ( V_1 , V_50 , 0x0000 , 0xffe0 ) ;
F_1 ( V_1 , V_50 , 0x0007 , 0xffe0 ) ;
if ( V_1 -> V_51 & V_52 )
F_7 ( V_2 , V_93 -> V_94 ) ;
else if ( V_1 -> V_51 & V_53 )
F_8 ( V_2 , V_93 -> V_94 ) ;
V_1 -> V_95 = V_93 -> V_94 ;
F_1 ( V_1 , V_50 , 0x0015 , 0x003f ) ;
F_1 ( V_1 , V_50 , 0x0015 , 0x0000 ) ;
F_1 ( V_1 , V_50 , 0x0000 , 0x4f00 ) ;
F_1 ( V_1 , V_50 , 0x0007 , 0x4f00 ) ;
return 0 ;
}
static int F_20 ( struct V_61 * V_61 , void * V_32 , struct V_96 * V_97 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_28 , V_97 -> V_66 ) ;
if ( V_1 -> V_51 ) {
if ( V_97 -> V_66 >= 4 )
return - V_27 ;
} else {
if ( V_97 -> V_66 != 0 )
return - V_27 ;
}
memcpy ( V_97 , & V_98 [ V_97 -> V_66 ] , sizeof( struct V_96 ) ) ;
return 0 ;
}
static int F_21 ( struct V_61 * V_61 , void * V_32 , unsigned int * V_99 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
* V_99 = V_1 -> V_44 ;
F_3 ( 2 , L_29 , * V_99 ) ;
return 0 ;
}
static int F_22 ( struct V_61 * V_61 , void * V_32 , unsigned int V_99 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_30 , V_99 ) ;
if ( ! V_1 -> V_51 )
return V_99 ? - V_27 : 0 ;
if ( V_99 >= 4 )
return - V_27 ;
V_1 -> V_44 = V_99 ;
return F_9 ( V_32 ) ;
}
static int F_23 ( struct V_61 * V_61 , void * V_32 , struct V_100 * V_101 )
{
F_3 ( 2 , L_31 , V_101 -> V_66 ) ;
if ( V_101 -> V_66 != 0 )
return - V_27 ;
* V_101 = V_102 ;
return 0 ;
}
static int F_24 ( struct V_61 * V_61 , void * V_32 , struct V_100 * V_101 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_31 , V_101 -> V_66 ) ;
if ( V_101 -> V_66 != 0 )
return - V_27 ;
if ( V_1 -> V_44 >= 2 )
return - V_27 ;
* V_101 = V_102 ;
return 0 ;
}
static int F_25 ( struct V_61 * V_61 , void * V_32 , const struct V_100 * V_101 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_32 , V_101 -> V_66 ) ;
if ( V_1 -> V_44 >= 2 )
return - V_27 ;
return V_101 -> V_66 ? - V_27 : 0 ;
}
static int F_26 ( struct V_61 * V_61 , void * V_32 ,
struct V_103 * V_104 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_33 ) ;
if ( V_104 -> type != V_105 )
return - V_27 ;
if ( F_27 ( V_1 -> V_106 ) >= 0x2623 ) {
V_104 -> V_107 = V_108 ;
V_104 -> V_109 [ 0 ] [ 23 ] = V_108 ;
}
return 0 ;
}
static int F_28 ( struct V_61 * V_61 , void * V_32 ,
struct V_110 * V_93 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_34 ) ;
if ( F_27 ( V_1 -> V_106 ) < 0x2623 )
return - V_27 ;
memset ( & V_93 -> V_111 . V_112 , 0 , sizeof V_93 -> V_111 . V_112 ) ;
if ( V_1 -> V_113 ) {
V_93 -> V_111 . V_112 . V_107 = V_108 ;
V_93 -> V_111 . V_112 . V_109 [ 0 ] [ 23 ] = V_108 ;
V_93 -> V_111 . V_112 . V_114 = sizeof( struct V_115 ) ;
}
return 0 ;
}
static int F_29 ( struct V_61 * V_61 , void * V_32 ,
struct V_110 * V_93 )
{
struct V_22 * V_2 = ( (struct V_31 * ) V_32 ) -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_35 ) ;
if ( F_27 ( V_1 -> V_106 ) < 0x2623 )
return - V_27 ;
if ( V_93 -> V_111 . V_112 . V_107 != V_108 &&
V_93 -> V_111 . V_112 . V_109 [ 0 ] [ 23 ] != V_108 ) {
memset ( & V_93 -> V_111 . V_112 , 0 , sizeof( V_93 -> V_111 . V_112 ) ) ;
V_1 -> V_113 = 0 ;
V_1 -> V_116 = 0 ;
return F_13 ( V_1 , V_117 ,
V_118 , 1 , 0 ) ;
} else {
memset ( & V_93 -> V_111 . V_112 , 0 , sizeof( V_93 -> V_111 . V_112 ) ) ;
V_93 -> V_111 . V_112 . V_107 = V_108 ;
V_93 -> V_111 . V_112 . V_109 [ 0 ] [ 23 ] = V_108 ;
V_93 -> V_111 . V_112 . V_114 = sizeof( struct V_115 ) ;
V_1 -> V_113 = 1 ;
V_1 -> V_116 = 0 ;
}
return 0 ;
}
static int F_30 ( struct V_61 * V_61 )
{
struct V_31 * V_32 = V_61 -> V_119 ;
struct V_22 * V_2 = V_32 -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
F_3 ( 2 , L_36 , V_120 ) ;
V_1 -> V_113 = 0 ;
V_1 -> V_116 = 0 ;
if ( F_27 ( V_1 -> V_106 ) < 0x2623 )
return 0 ;
else
return F_13 ( V_1 , V_117 , V_118 , 1 , 0 ) ;
}
static T_5 F_31 ( struct V_61 * V_61 , const char T_6 * V_23 , T_7 V_121 , T_8 * V_122 )
{
struct V_31 * V_32 = V_61 -> V_119 ;
struct V_22 * V_2 = V_32 -> V_2 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
struct V_115 V_123 ;
int V_124 ;
F_3 ( 2 , L_36 , V_120 ) ;
if ( F_27 ( V_1 -> V_106 ) < 0x2623 || ! V_1 -> V_113 || V_121 != sizeof V_123 )
return - V_27 ;
if ( F_32 ( & V_123 , V_23 , V_121 ) )
return - V_125 ;
if ( ( V_123 . V_126 != 0 && V_123 . V_126 != V_108 ) || V_123 . V_127 != 0 || V_123 . line != 23 )
return - V_27 ;
if ( V_123 . V_126 )
V_1 -> V_116 = ( ( V_123 . V_23 [ 1 ] << 8 ) & 0x3f00 ) | V_123 . V_23 [ 0 ] ;
else
V_1 -> V_116 = 0x8000 ;
V_124 = F_13 ( V_1 , V_117 , V_118 , 2 , 1 , V_1 -> V_116 ) ;
return ( V_124 < 0 ) ? V_124 : V_121 ;
}
int F_33 ( struct V_1 * V_1 )
{
T_2 V_128 , V_129 ;
if ( F_12 ( V_1 , 0x80 , 0x0 , 0x80 ) == 1 &&
F_12 ( V_1 , 0x80 , 0x0 , 0 ) == 1 ) {
F_34 ( L_37 ,
V_1 -> V_16 . V_17 ) ;
V_1 -> V_11 = V_12 ;
} else if ( F_12 ( V_1 , 0x84 , 0x0 , 0x80 ) == 1 &&
F_12 ( V_1 , 0x84 , 0x0 , 0 ) == 1 ) {
F_34 ( L_38 ,
V_1 -> V_16 . V_17 ) ;
V_1 -> V_11 = V_14 ;
} else
return - V_130 ;
F_35 ( 100 ) ;
F_4 ( V_1 , V_79 , 0x001e , & V_128 ) ;
F_4 ( V_1 , V_79 , 0x001f , & V_129 ) ;
F_3 ( 1 , L_39 ,
V_1 -> V_16 . V_17 , V_128 , V_129 ) ;
F_1 ( V_1 , V_50 , 0x0013 , 0x0c00 ) ;
F_1 ( V_1 , V_50 , 0x0000 , 0x7f00 ) ;
F_1 ( V_1 , V_50 , 0x0008 , 0x0220 ) ;
F_1 ( V_1 , V_50 , 0x0009 , 0x0220 ) ;
F_1 ( V_1 , V_50 , 0x0004 , 0x7f00 ) ;
F_1 ( V_1 , V_50 , 0x000a , 0x0220 ) ;
F_1 ( V_1 , V_50 , 0x0007 , 0x7f00 ) ;
F_1 ( V_1 , V_50 , 0x000d , 0x1900 ) ;
if ( F_12 ( V_1 , 0x48 , 0x01 , 0x00 ) != 1 ) {
F_34 ( L_40 ) ;
} else {
T_1 * V_97 = V_131 ;
if ( ( V_1 -> V_2 -> V_132 -> V_133 == 0x110a ) && ( V_1 -> V_2 -> V_132 -> V_134 == 0x0000 ) ) {
V_1 -> V_51 |= V_52 ;
} else if ( ( V_1 -> V_2 -> V_132 -> V_133 == 0x13c2 ) && ( V_1 -> V_2 -> V_132 -> V_134 == 0x0002 ) ) {
V_1 -> V_51 |= V_52 ;
} else if ( ( V_1 -> V_2 -> V_132 -> V_133 == 0x13c2 ) && ( V_1 -> V_2 -> V_132 -> V_134 == 0x000A ) ) {
V_1 -> V_51 |= V_53 ;
}
if ( V_1 -> V_51 & V_52 ) {
if ( F_5 ( V_1 -> V_2 , 0x09 , 0x0f , 0x20 ) )
F_3 ( 1 , L_9 ) ;
} else if ( V_1 -> V_51 & V_53 ) {
F_11 ( V_1 -> V_2 , 1 , V_58 ) ;
F_11 ( V_1 -> V_2 , 3 , V_58 ) ;
}
while ( * V_97 != 0xff ) {
if ( F_12 ( V_1 , 0x48 , V_97 [ 0 ] , V_97 [ 1 ] ) != 1 ) {
F_3 ( 1 , L_41 , V_1 -> V_16 . V_17 ) ;
break;
}
V_97 += 2 ;
}
F_1 ( V_1 , V_135 , 0x00bb , 0x02d0 ) ;
F_1 ( V_1 , V_135 , 0x0001 , 3 ) ;
F_1 ( V_1 , V_135 , 0x0001 , 18 ) ;
F_1 ( V_1 , V_135 , 0x0001 , 27 ) ;
F_1 ( V_1 , V_135 , 0x0001 , 48 ) ;
F_1 ( V_1 , V_135 , 0x0001 , 66 ) ;
F_1 ( V_1 , V_135 , 0x0001 , 72 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 4 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 64 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 0 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 3 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 18 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 27 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 48 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 66 ) ;
F_1 ( V_1 , V_135 , 0x0005 , 72 ) ;
F_1 ( V_1 , V_135 , 0x0083 , 0xa000 ) ;
F_1 ( V_1 , V_135 , 0x0093 , 0x00aa ) ;
F_1 ( V_1 , V_135 , 0x009b , 0x04fc ) ;
F_1 ( V_1 , V_135 , 0x00a3 , 0x038e ) ;
F_1 ( V_1 , V_135 , 0x00ab , 0x04c6 ) ;
F_1 ( V_1 , V_135 , 0x0056 , 0 ) ;
}
memcpy ( V_47 , V_57 , sizeof( struct V_49 ) * 2 ) ;
F_36 ( V_1 -> V_2 , V_136 , 0x00000000 ) ;
F_36 ( V_1 -> V_2 , V_137 , 0x03000700 ) ;
F_36 ( V_1 -> V_2 , V_138 , ( V_139 | V_140 | V_141 | V_142 ) ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 )
{
struct V_22 * V_2 = V_1 -> V_2 ;
struct V_143 * V_35 ;
int V_144 ;
if ( V_1 -> V_51 )
V_35 = & V_145 ;
else
V_35 = & V_146 ;
V_144 = F_38 ( V_2 , V_35 ) ;
if ( V_144 ) {
F_39 ( L_42 ) ;
return - V_130 ;
}
V_35 -> V_147 . F_20 = F_20 ;
V_35 -> V_147 . F_21 = F_21 ;
V_35 -> V_147 . F_22 = F_22 ;
V_35 -> V_147 . F_16 = F_16 ;
V_35 -> V_147 . F_17 = F_17 ;
V_35 -> V_147 . F_18 = F_18 ;
V_35 -> V_147 . F_19 = F_19 ;
V_35 -> V_147 . F_23 = F_23 ;
V_35 -> V_147 . F_24 = F_24 ;
V_35 -> V_147 . F_25 = F_25 ;
V_35 -> V_147 . V_148 = NULL ;
V_35 -> V_149 . F_16 = F_16 ;
V_35 -> V_149 . F_17 = F_17 ;
V_35 -> V_149 . F_18 = F_18 ;
V_35 -> V_149 . F_19 = F_19 ;
V_35 -> V_149 . V_148 = NULL ;
V_35 -> V_149 . F_26 = F_26 ;
V_35 -> V_149 . F_28 = F_28 ;
V_35 -> V_149 . F_29 = F_29 ;
if ( F_27 ( V_1 -> V_106 ) < 0x2623 )
V_35 -> V_150 &= ~ V_151 ;
if ( F_40 ( & V_1 -> V_152 , V_2 , L_43 , V_153 ) ) {
F_39 ( L_44 ) ;
F_41 ( V_2 ) ;
return - V_130 ;
}
if ( F_27 ( V_1 -> V_106 ) >= 0x2623 ) {
if ( F_40 ( & V_1 -> V_154 , V_2 , L_43 , V_155 ) )
F_39 ( L_45 ) ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_1 )
{
struct V_22 * V_2 = V_1 -> V_2 ;
F_43 ( & V_1 -> V_152 , V_1 -> V_2 ) ;
F_43 ( & V_1 -> V_154 , V_1 -> V_2 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_22 * V_2 , struct V_49 * V_156 )
{
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_24 ;
if ( V_156 -> V_126 & V_157 ) {
V_1 -> V_158 = V_159 ;
F_45 ( V_1 , V_1 -> V_158 ) ;
}
else if ( V_156 -> V_126 & V_160 ) {
V_1 -> V_158 = V_161 ;
F_45 ( V_1 , V_1 -> V_158 ) ;
}
else
return - 1 ;
return 0 ;
}
