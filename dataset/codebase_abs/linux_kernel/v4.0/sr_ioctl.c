static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 ;
unsigned char * V_11 ;
V_11 = F_2 ( 32 , V_12 | F_3 ( V_6 ) ) ;
if ( ! V_11 )
return - V_13 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_14 = V_15 ;
V_9 . V_16 [ 0 ] = V_17 ;
V_9 . V_16 [ 8 ] = 12 ;
V_9 . V_11 = V_11 ;
V_9 . V_18 = 12 ;
V_9 . V_19 = 1 ;
V_9 . V_20 = V_21 ;
V_10 = F_4 ( V_6 , & V_9 ) ;
V_4 -> V_22 = V_11 [ 2 ] ;
V_4 -> V_23 = V_11 [ 3 ] ;
F_5 ( V_11 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 ;
unsigned char * V_11 ;
V_11 = F_2 ( 32 , V_12 | F_3 ( V_6 ) ) ;
if ( ! V_11 )
return - V_13 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_14 = V_15 ;
V_9 . V_16 [ 0 ] = V_17 ;
V_9 . V_16 [ 1 ] |= ( V_25 -> V_26 == V_27 ) ? 0x02 : 0 ;
V_9 . V_16 [ 6 ] = V_25 -> V_28 ;
V_9 . V_16 [ 8 ] = 12 ;
V_9 . V_11 = V_11 ;
V_9 . V_18 = 12 ;
V_9 . V_20 = V_21 ;
V_10 = F_4 ( V_6 , & V_9 ) ;
V_25 -> V_29 = V_11 [ 5 ] & 0xf ;
V_25 -> V_30 = V_11 [ 5 ] >> 4 ;
V_25 -> V_31 = ( V_25 -> V_29 & 0x04 ) ? 1 : 0 ;
if ( V_25 -> V_26 == V_27 ) {
V_25 -> V_32 . V_33 . V_34 = V_11 [ 9 ] ;
V_25 -> V_32 . V_33 . V_35 = V_11 [ 10 ] ;
V_25 -> V_32 . V_33 . V_36 = V_11 [ 11 ] ;
} else
V_25 -> V_32 . V_37 = ( ( ( ( ( V_11 [ 8 ] << 8 ) + V_11 [ 9 ] ) << 8 )
+ V_11 [ 10 ] ) << 8 ) + V_11 [ 11 ] ;
F_5 ( V_11 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_24 V_40 , V_41 ;
struct V_3 V_4 ;
struct V_8 V_9 ;
int V_42 , V_43 ;
V_43 = F_1 ( V_2 , & V_4 ) ;
if ( V_43 )
return V_43 ;
V_42 = V_4 . V_23 - V_4 . V_22 + 1 ;
if ( V_39 -> V_44 == V_42 )
V_39 -> V_44 = V_45 ;
else if ( V_39 -> V_44 != V_45 )
V_39 -> V_44 ++ ;
V_40 . V_28 = V_39 -> V_46 ;
V_40 . V_26 = V_27 ;
V_41 . V_28 = V_39 -> V_44 ;
V_41 . V_26 = V_27 ;
V_43 = F_6 ( V_2 , & V_40 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_6 ( V_2 , & V_41 ) ;
if ( V_43 )
return V_43 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_47 ;
V_9 . V_16 [ 3 ] = V_40 . V_32 . V_33 . V_34 ;
V_9 . V_16 [ 4 ] = V_40 . V_32 . V_33 . V_35 ;
V_9 . V_16 [ 5 ] = V_40 . V_32 . V_33 . V_36 ;
V_9 . V_16 [ 6 ] = V_41 . V_32 . V_33 . V_34 ;
V_9 . V_16 [ 7 ] = V_41 . V_32 . V_33 . V_35 ;
V_9 . V_16 [ 8 ] = V_41 . V_32 . V_33 . V_36 ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_2 -> V_7 , & V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_14 = V_15 ;
V_9 . V_16 [ 0 ] = V_49 ;
V_9 . V_16 [ 4 ] = V_39 -> V_46 ;
V_9 . V_16 [ 5 ] = V_39 -> V_50 ;
V_9 . V_16 [ 7 ] = V_39 -> V_44 ;
V_9 . V_16 [ 8 ] = V_39 -> V_51 ;
V_9 . V_20 = V_48 ;
V_10 = F_4 ( V_6 , & V_9 ) ;
if ( V_10 == - V_52 )
V_10 = F_7 ( V_2 , V_39 ) ;
return V_10 ;
}
int F_4 ( T_1 * V_6 , struct V_8 * V_9 )
{
struct V_53 * V_54 ;
struct V_55 V_56 ;
int V_10 , V_57 = 0 , V_58 = 0 ;
struct V_59 * V_60 = V_9 -> V_60 ;
V_54 = V_6 -> V_61 ;
if ( ! V_60 ) {
V_60 = F_2 ( V_62 , V_12 ) ;
if ( ! V_60 ) {
V_57 = - V_13 ;
goto V_63;
}
}
V_64:
if ( ! F_9 ( V_54 ) ) {
V_57 = - V_65 ;
goto V_63;
}
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_10 = F_10 ( V_54 , V_9 -> V_16 , V_9 -> V_20 ,
V_9 -> V_11 , V_9 -> V_18 , ( char * ) V_60 ,
V_9 -> V_14 , V_66 , 0 , NULL ) ;
F_11 ( ( char * ) V_60 , sizeof( * V_60 ) , & V_56 ) ;
if ( F_12 ( V_10 ) != 0 ) {
switch ( V_56 . V_67 ) {
case V_68 :
V_54 -> V_69 = 1 ;
if ( ! V_9 -> V_19 )
F_13 ( V_70 , V_6 ,
L_1 ) ;
if ( V_58 ++ < 10 )
goto V_64;
V_57 = - V_71 ;
break;
case V_72 :
if ( V_56 . V_73 == 0x04 &&
V_56 . V_74 == 0x01 ) {
if ( ! V_9 -> V_19 )
F_13 ( V_70 , V_6 ,
L_2 ) ;
if ( V_58 ++ < 10 ) {
F_14 ( 2 ) ;
goto V_64;
} else {
V_57 = - V_71 ;
break;
}
}
if ( ! V_9 -> V_19 )
F_13 ( V_70 , V_6 ,
L_3
L_4 ) ;
V_57 = - V_71 ;
break;
case V_75 :
V_57 = - V_76 ;
if ( V_56 . V_73 == 0x20 &&
V_56 . V_74 == 0x00 )
V_57 = - V_52 ;
break;
default:
V_57 = - V_76 ;
}
}
V_63:
if ( ! V_9 -> V_60 )
F_5 ( V_60 ) ;
V_9 -> V_77 = V_57 ;
return V_57 ;
}
int F_15 ( struct V_1 * V_2 , int V_78 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_79 ;
V_9 . V_16 [ 4 ] = ( V_78 == 0 ) ? 0x03 : 0x02 ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_6 , & V_9 ) ;
}
int F_16 ( struct V_1 * V_2 , int V_80 )
{
T_1 * V_6 = V_2 -> V_7 ;
return F_17 ( V_6 -> V_61 , V_80 ?
V_81 : V_82 ) ;
}
int F_18 ( struct V_1 * V_2 , int V_83 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 V_56 ;
struct V_84 V_85 ;
if ( V_86 != V_83 ) {
return - V_87 ;
}
if ( ! F_19 ( V_6 -> V_61 , V_88 , V_89 , & V_56 ) )
return V_90 ;
if ( F_20 ( & V_56 ) && V_56 . V_67 == V_72
&& V_56 . V_73 == 0x04 && V_56 . V_74 == 0x01 )
return V_91 ;
if ( ! F_21 ( V_2 , & V_85 ) ) {
if ( V_85 . V_92 )
return V_90 ;
else if ( V_85 . V_93 )
return V_94 ;
else
return V_95 ;
}
if ( F_20 ( & V_56 ) && V_56 . V_67 == V_72
&& V_56 . V_73 == 0x04 && V_56 . V_74 == 0x02 )
return V_94 ;
if ( V_56 . V_67 == V_72 && V_56 . V_73 == 0x04 )
return V_90 ;
if ( F_20 ( & V_56 ) &&
V_56 . V_73 == 0x3a )
return V_95 ;
else
return V_94 ;
return V_91 ;
}
int F_22 ( struct V_1 * V_2 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_3 V_96 ;
struct V_24 V_97 ;
int V_98 , V_99 , V_100 = 0 ;
V_99 = F_1 ( V_2 , & V_96 ) ;
if ( V_99 )
return ( V_99 == - V_71 ) ? V_95 : V_101 ;
for ( V_98 = V_96 . V_22 ; V_98 <= V_96 . V_23 ; V_98 ++ ) {
V_97 . V_28 = V_98 ;
V_97 . V_26 = V_102 ;
if ( F_6 ( V_2 , & V_97 ) )
return V_101 ;
if ( V_97 . V_29 & V_103 ) {
V_100 = 1 ;
break;
}
}
if ( ! V_100 )
return V_104 ;
if ( V_6 -> V_105 )
return V_106 ;
else
return V_107 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
T_1 * V_6 = V_2 -> V_7 ;
V_109 -> V_110 . V_37 = V_6 -> V_111 ;
V_109 -> V_105 = V_6 -> V_105 || V_6 -> V_111 > 0 ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
char * V_11 = F_2 ( 32 , V_12 | F_3 ( V_6 ) ) ;
int V_10 ;
if ( ! V_11 )
return - V_13 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_114 ;
V_9 . V_16 [ 2 ] = 0x40 ;
V_9 . V_16 [ 3 ] = 0x02 ;
V_9 . V_16 [ 8 ] = 24 ;
V_9 . V_11 = V_11 ;
V_9 . V_18 = 24 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
V_10 = F_4 ( V_6 , & V_9 ) ;
memcpy ( V_113 -> V_115 , V_11 + 9 , 13 ) ;
V_113 -> V_115 [ 13 ] = 0 ;
F_5 ( V_11 ) ;
return V_10 ;
}
int F_25 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_26 ( struct V_1 * V_2 , int V_116 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
if ( V_116 == 0 )
V_116 = 0xffff ;
else
V_116 *= 177 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_117 ;
V_9 . V_16 [ 2 ] = ( V_116 >> 8 ) & 0xff ;
V_9 . V_16 [ 3 ] = V_116 & 0xff ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
if ( F_4 ( V_6 , & V_9 ) )
return - V_76 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_16 , void * V_118 )
{
switch ( V_16 ) {
case V_119 :
return F_1 ( V_2 , V_118 ) ;
case V_120 :
return F_6 ( V_2 , V_118 ) ;
case V_121 :
return F_8 ( V_2 , V_118 ) ;
default:
return - V_87 ;
}
}
static int F_28 ( T_1 * V_6 , unsigned char * V_122 , int V_37 , int V_123 , int V_124 )
{
struct V_8 V_9 ;
#ifdef F_29
F_13 ( V_70 , V_6 , L_5 ,
V_37 , V_123 , V_124 ) ;
#endif
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_125 ;
V_9 . V_16 [ 1 ] = ( ( V_123 & 7 ) << 2 ) ;
V_9 . V_16 [ 2 ] = ( unsigned char ) ( V_37 >> 24 ) & 0xff ;
V_9 . V_16 [ 3 ] = ( unsigned char ) ( V_37 >> 16 ) & 0xff ;
V_9 . V_16 [ 4 ] = ( unsigned char ) ( V_37 >> 8 ) & 0xff ;
V_9 . V_16 [ 5 ] = ( unsigned char ) V_37 & 0xff ;
V_9 . V_16 [ 8 ] = 1 ;
switch ( V_124 ) {
case 2336 :
V_9 . V_16 [ 9 ] = 0x58 ;
break;
case 2340 :
V_9 . V_16 [ 9 ] = 0x78 ;
break;
case 2352 :
V_9 . V_16 [ 9 ] = 0xf8 ;
break;
default:
V_9 . V_16 [ 9 ] = 0x10 ;
break;
}
V_9 . V_11 = V_122 ;
V_9 . V_18 = V_124 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_6 , & V_9 ) ;
}
static int F_30 ( T_1 * V_6 , int V_37 , int V_124 , unsigned char * V_122 )
{
struct V_8 V_9 ;
int V_99 ;
if ( V_6 -> V_126 ) {
V_99 = F_28 ( V_6 , V_122 , V_37 , 0 , V_124 ) ;
if ( - V_52 != V_99 )
return V_99 ;
V_6 -> V_126 = 0 ;
F_13 ( V_70 , V_6 ,
L_6 ) ;
}
if ( V_124 != V_6 -> V_61 -> V_127 ) {
if ( 0 != ( V_99 = F_31 ( V_6 , V_124 ) ) )
return V_99 ;
}
#ifdef F_29
F_13 ( V_70 , V_6 , L_7 ,
V_37 , V_124 ) ;
#endif
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_128 ;
V_9 . V_16 [ 2 ] = ( unsigned char ) ( V_37 >> 24 ) & 0xff ;
V_9 . V_16 [ 3 ] = ( unsigned char ) ( V_37 >> 16 ) & 0xff ;
V_9 . V_16 [ 4 ] = ( unsigned char ) ( V_37 >> 8 ) & 0xff ;
V_9 . V_16 [ 5 ] = ( unsigned char ) V_37 & 0xff ;
V_9 . V_16 [ 8 ] = 1 ;
V_9 . V_11 = V_122 ;
V_9 . V_18 = V_124 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
V_99 = F_4 ( V_6 , & V_9 ) ;
return V_99 ;
}
int F_32 ( T_1 * V_6 )
{
unsigned char * V_129 ;
int V_130 ;
if ( ! V_131 )
return 0 ;
V_129 = F_2 ( 2048 , V_12 | F_3 ( V_6 ) ) ;
if ( ! V_129 )
return - V_13 ;
if ( 0 == F_30 ( V_6 , V_6 -> V_111 + 16 ,
V_132 , V_129 ) ) {
V_130 = ( V_129 [ 3 ] == 0x02 ) ? 1 : 0 ;
} else {
V_130 = - 1 ;
}
F_5 ( V_129 ) ;
#ifdef F_29
F_13 ( V_70 , V_6 , L_8 , V_130 ) ;
#endif
return V_130 ;
}
