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
#ifdef F_15
F_16 ( L_5 , & V_56 ) ;
#endif
V_57 = - V_71 ;
break;
case V_75 :
V_57 = - V_76 ;
if ( V_56 . V_73 == 0x20 &&
V_56 . V_74 == 0x00 )
V_57 = - V_52 ;
#ifdef F_15
F_17 ( V_9 -> V_16 ) ;
F_16 ( L_5 , & V_56 ) ;
#endif
break;
default:
F_13 ( V_77 , V_6 ,
L_6 ) ;
F_17 ( V_9 -> V_16 ) ;
F_16 ( L_5 , & V_56 ) ;
V_57 = - V_76 ;
}
}
V_63:
if ( ! V_9 -> V_60 )
F_5 ( V_60 ) ;
V_9 -> V_78 = V_57 ;
return V_57 ;
}
int F_18 ( struct V_1 * V_2 , int V_79 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_80 ;
V_9 . V_16 [ 4 ] = ( V_79 == 0 ) ? 0x03 : 0x02 ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_6 , & V_9 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_81 )
{
T_1 * V_6 = V_2 -> V_7 ;
return F_20 ( V_6 -> V_61 , V_81 ?
V_82 : V_83 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_84 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 V_56 ;
struct V_85 V_86 ;
if ( V_87 != V_84 ) {
return - V_88 ;
}
if ( ! F_22 ( V_6 -> V_61 , V_89 , V_90 , & V_56 ) )
return V_91 ;
if ( F_23 ( & V_56 ) && V_56 . V_67 == V_72
&& V_56 . V_73 == 0x04 && V_56 . V_74 == 0x01 )
return V_92 ;
if ( ! F_24 ( V_2 , & V_86 ) ) {
if ( V_86 . V_93 )
return V_91 ;
else if ( V_86 . V_94 )
return V_95 ;
else
return V_96 ;
}
if ( F_23 ( & V_56 ) && V_56 . V_67 == V_72
&& V_56 . V_73 == 0x04 && V_56 . V_74 == 0x02 )
return V_95 ;
if ( V_56 . V_67 == V_72 && V_56 . V_73 == 0x04 )
return V_91 ;
if ( F_23 ( & V_56 ) &&
V_56 . V_73 == 0x3a )
return V_96 ;
else
return V_95 ;
return V_92 ;
}
int F_25 ( struct V_1 * V_2 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_3 V_97 ;
struct V_24 V_98 ;
int V_99 , V_100 , V_101 = 0 ;
V_100 = F_1 ( V_2 , & V_97 ) ;
if ( V_100 )
return ( V_100 == - V_71 ) ? V_96 : V_102 ;
for ( V_99 = V_97 . V_22 ; V_99 <= V_97 . V_23 ; V_99 ++ ) {
V_98 . V_28 = V_99 ;
V_98 . V_26 = V_103 ;
if ( F_6 ( V_2 , & V_98 ) )
return V_102 ;
if ( V_98 . V_29 & V_104 ) {
V_101 = 1 ;
break;
}
}
if ( ! V_101 )
return V_105 ;
if ( V_6 -> V_106 )
return V_107 ;
else
return V_108 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
T_1 * V_6 = V_2 -> V_7 ;
V_110 -> V_111 . V_37 = V_6 -> V_112 ;
V_110 -> V_106 = V_6 -> V_106 || V_6 -> V_112 > 0 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
char * V_11 = F_2 ( 32 , V_12 | F_3 ( V_6 ) ) ;
int V_10 ;
if ( ! V_11 )
return - V_13 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_115 ;
V_9 . V_16 [ 2 ] = 0x40 ;
V_9 . V_16 [ 3 ] = 0x02 ;
V_9 . V_16 [ 8 ] = 24 ;
V_9 . V_11 = V_11 ;
V_9 . V_18 = 24 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
V_10 = F_4 ( V_6 , & V_9 ) ;
memcpy ( V_114 -> V_116 , V_11 + 9 , 13 ) ;
V_114 -> V_116 [ 13 ] = 0 ;
F_5 ( V_11 ) ;
return V_10 ;
}
int F_28 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_29 ( struct V_1 * V_2 , int V_117 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
if ( V_117 == 0 )
V_117 = 0xffff ;
else
V_117 *= 177 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_118 ;
V_9 . V_16 [ 2 ] = ( V_117 >> 8 ) & 0xff ;
V_9 . V_16 [ 3 ] = V_117 & 0xff ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
if ( F_4 ( V_6 , & V_9 ) )
return - V_76 ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_16 , void * V_119 )
{
switch ( V_16 ) {
case V_120 :
return F_1 ( V_2 , V_119 ) ;
case V_121 :
return F_6 ( V_2 , V_119 ) ;
case V_122 :
return F_8 ( V_2 , V_119 ) ;
default:
return - V_88 ;
}
}
static int F_31 ( T_1 * V_6 , unsigned char * V_123 , int V_37 , int V_124 , int V_125 )
{
struct V_8 V_9 ;
#ifdef F_15
F_13 ( V_70 , V_6 , L_7 ,
V_37 , V_124 , V_125 ) ;
#endif
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_126 ;
V_9 . V_16 [ 1 ] = ( ( V_124 & 7 ) << 2 ) ;
V_9 . V_16 [ 2 ] = ( unsigned char ) ( V_37 >> 24 ) & 0xff ;
V_9 . V_16 [ 3 ] = ( unsigned char ) ( V_37 >> 16 ) & 0xff ;
V_9 . V_16 [ 4 ] = ( unsigned char ) ( V_37 >> 8 ) & 0xff ;
V_9 . V_16 [ 5 ] = ( unsigned char ) V_37 & 0xff ;
V_9 . V_16 [ 8 ] = 1 ;
switch ( V_125 ) {
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
V_9 . V_11 = V_123 ;
V_9 . V_18 = V_125 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_6 , & V_9 ) ;
}
static int F_32 ( T_1 * V_6 , int V_37 , int V_125 , unsigned char * V_123 )
{
struct V_8 V_9 ;
int V_100 ;
if ( V_6 -> V_127 ) {
V_100 = F_31 ( V_6 , V_123 , V_37 , 0 , V_125 ) ;
if ( - V_52 != V_100 )
return V_100 ;
V_6 -> V_127 = 0 ;
F_13 ( V_70 , V_6 ,
L_8 ) ;
}
if ( V_125 != V_6 -> V_61 -> V_128 ) {
if ( 0 != ( V_100 = F_33 ( V_6 , V_125 ) ) )
return V_100 ;
}
#ifdef F_15
F_13 ( V_70 , V_6 , L_9 ,
V_37 , V_125 ) ;
#endif
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_129 ;
V_9 . V_16 [ 2 ] = ( unsigned char ) ( V_37 >> 24 ) & 0xff ;
V_9 . V_16 [ 3 ] = ( unsigned char ) ( V_37 >> 16 ) & 0xff ;
V_9 . V_16 [ 4 ] = ( unsigned char ) ( V_37 >> 8 ) & 0xff ;
V_9 . V_16 [ 5 ] = ( unsigned char ) V_37 & 0xff ;
V_9 . V_16 [ 8 ] = 1 ;
V_9 . V_11 = V_123 ;
V_9 . V_18 = V_125 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
V_100 = F_4 ( V_6 , & V_9 ) ;
return V_100 ;
}
int F_34 ( T_1 * V_6 )
{
unsigned char * V_130 ;
int V_131 ;
if ( ! V_132 )
return 0 ;
V_130 = F_2 ( 2048 , V_12 | F_3 ( V_6 ) ) ;
if ( ! V_130 )
return - V_13 ;
if ( 0 == F_32 ( V_6 , V_6 -> V_112 + 16 ,
V_133 , V_130 ) ) {
V_131 = ( V_130 [ 3 ] == 0x02 ) ? 1 : 0 ;
} else {
V_131 = - 1 ;
}
F_5 ( V_130 ) ;
#ifdef F_15
F_13 ( V_70 , V_6 , L_10 , V_131 ) ;
#endif
return V_131 ;
}
