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
V_54 = V_6 -> V_59 ;
V_60:
if ( ! F_9 ( V_54 ) ) {
V_57 = - V_61 ;
goto V_62;
}
V_10 = F_10 ( V_54 , V_9 -> V_16 , V_9 -> V_20 ,
V_9 -> V_11 , V_9 -> V_18 ,
( unsigned char * ) V_9 -> V_63 , & V_56 ,
V_9 -> V_14 , V_64 , 0 , 0 , NULL ) ;
if ( F_11 ( V_10 ) != 0 ) {
switch ( V_56 . V_65 ) {
case V_66 :
V_54 -> V_67 = 1 ;
if ( ! V_9 -> V_19 )
F_12 ( V_68 , V_6 ,
L_1 ) ;
if ( V_58 ++ < 10 )
goto V_60;
V_57 = - V_69 ;
break;
case V_70 :
if ( V_56 . V_71 == 0x04 &&
V_56 . V_72 == 0x01 ) {
if ( ! V_9 -> V_19 )
F_12 ( V_68 , V_6 ,
L_2 ) ;
if ( V_58 ++ < 10 ) {
F_13 ( 2 ) ;
goto V_60;
} else {
V_57 = - V_69 ;
break;
}
}
if ( ! V_9 -> V_19 )
F_12 ( V_68 , V_6 ,
L_3
L_4 ) ;
V_57 = - V_69 ;
break;
case V_73 :
V_57 = - V_74 ;
if ( V_56 . V_71 == 0x20 &&
V_56 . V_72 == 0x00 )
V_57 = - V_52 ;
break;
default:
V_57 = - V_74 ;
}
}
V_62:
V_9 -> V_75 = V_57 ;
return V_57 ;
}
int F_14 ( struct V_1 * V_2 , int V_76 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_77 ;
V_9 . V_16 [ 4 ] = ( V_76 == 0 ) ? 0x03 : 0x02 ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_6 , & V_9 ) ;
}
int F_15 ( struct V_1 * V_2 , int V_78 )
{
T_1 * V_6 = V_2 -> V_7 ;
return F_16 ( V_6 -> V_59 , V_78 ?
V_79 : V_80 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_81 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 V_56 ;
struct V_82 V_83 ;
if ( V_84 != V_81 ) {
return - V_85 ;
}
if ( ! F_18 ( V_6 -> V_59 , V_86 , V_87 , & V_56 ) )
return V_88 ;
if ( F_19 ( & V_56 ) && V_56 . V_65 == V_70
&& V_56 . V_71 == 0x04 && V_56 . V_72 == 0x01 )
return V_89 ;
if ( ! F_20 ( V_2 , & V_83 ) ) {
if ( V_83 . V_90 )
return V_88 ;
else if ( V_83 . V_91 )
return V_92 ;
else
return V_93 ;
}
if ( F_19 ( & V_56 ) && V_56 . V_65 == V_70
&& V_56 . V_71 == 0x04 && V_56 . V_72 == 0x02 )
return V_92 ;
if ( V_56 . V_65 == V_70 && V_56 . V_71 == 0x04 )
return V_88 ;
if ( F_19 ( & V_56 ) &&
V_56 . V_71 == 0x3a )
return V_93 ;
else
return V_92 ;
return V_89 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_3 V_94 ;
struct V_24 V_95 ;
int V_96 , V_97 , V_98 = 0 ;
V_97 = F_1 ( V_2 , & V_94 ) ;
if ( V_97 )
return ( V_97 == - V_69 ) ? V_93 : V_99 ;
for ( V_96 = V_94 . V_22 ; V_96 <= V_94 . V_23 ; V_96 ++ ) {
V_95 . V_28 = V_96 ;
V_95 . V_26 = V_100 ;
if ( F_6 ( V_2 , & V_95 ) )
return V_99 ;
if ( V_95 . V_29 & V_101 ) {
V_98 = 1 ;
break;
}
}
if ( ! V_98 )
return V_102 ;
if ( V_6 -> V_103 )
return V_104 ;
else
return V_105 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
T_1 * V_6 = V_2 -> V_7 ;
V_107 -> V_108 . V_37 = V_6 -> V_109 ;
V_107 -> V_103 = V_6 -> V_103 || V_6 -> V_109 > 0 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
char * V_11 = F_2 ( 32 , V_12 | F_3 ( V_6 ) ) ;
int V_10 ;
if ( ! V_11 )
return - V_13 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_112 ;
V_9 . V_16 [ 2 ] = 0x40 ;
V_9 . V_16 [ 3 ] = 0x02 ;
V_9 . V_16 [ 8 ] = 24 ;
V_9 . V_11 = V_11 ;
V_9 . V_18 = 24 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
V_10 = F_4 ( V_6 , & V_9 ) ;
memcpy ( V_111 -> V_113 , V_11 + 9 , 13 ) ;
V_111 -> V_113 [ 13 ] = 0 ;
F_5 ( V_11 ) ;
return V_10 ;
}
int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_25 ( struct V_1 * V_2 , int V_114 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
if ( V_114 == 0 )
V_114 = 0xffff ;
else
V_114 *= 177 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_115 ;
V_9 . V_16 [ 2 ] = ( V_114 >> 8 ) & 0xff ;
V_9 . V_16 [ 3 ] = V_114 & 0xff ;
V_9 . V_20 = V_48 ;
V_9 . V_14 = V_15 ;
if ( F_4 ( V_6 , & V_9 ) )
return - V_74 ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_16 , void * V_116 )
{
switch ( V_16 ) {
case V_117 :
return F_1 ( V_2 , V_116 ) ;
case V_118 :
return F_6 ( V_2 , V_116 ) ;
case V_119 :
return F_8 ( V_2 , V_116 ) ;
default:
return - V_85 ;
}
}
static int F_27 ( T_1 * V_6 , unsigned char * V_120 , int V_37 , int V_121 , int V_122 )
{
struct V_8 V_9 ;
#ifdef F_28
F_12 ( V_68 , V_6 , L_5 ,
V_37 , V_121 , V_122 ) ;
#endif
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_123 ;
V_9 . V_16 [ 1 ] = ( ( V_121 & 7 ) << 2 ) ;
V_9 . V_16 [ 2 ] = ( unsigned char ) ( V_37 >> 24 ) & 0xff ;
V_9 . V_16 [ 3 ] = ( unsigned char ) ( V_37 >> 16 ) & 0xff ;
V_9 . V_16 [ 4 ] = ( unsigned char ) ( V_37 >> 8 ) & 0xff ;
V_9 . V_16 [ 5 ] = ( unsigned char ) V_37 & 0xff ;
V_9 . V_16 [ 8 ] = 1 ;
switch ( V_122 ) {
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
V_9 . V_11 = V_120 ;
V_9 . V_18 = V_122 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
return F_4 ( V_6 , & V_9 ) ;
}
static int F_29 ( T_1 * V_6 , int V_37 , int V_122 , unsigned char * V_120 )
{
struct V_8 V_9 ;
int V_97 ;
if ( V_6 -> V_124 ) {
V_97 = F_27 ( V_6 , V_120 , V_37 , 0 , V_122 ) ;
if ( - V_52 != V_97 )
return V_97 ;
V_6 -> V_124 = 0 ;
F_12 ( V_68 , V_6 ,
L_6 ) ;
}
if ( V_122 != V_6 -> V_59 -> V_125 ) {
if ( 0 != ( V_97 = F_30 ( V_6 , V_122 ) ) )
return V_97 ;
}
#ifdef F_28
F_12 ( V_68 , V_6 , L_7 ,
V_37 , V_122 ) ;
#endif
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_16 [ 0 ] = V_126 ;
V_9 . V_16 [ 2 ] = ( unsigned char ) ( V_37 >> 24 ) & 0xff ;
V_9 . V_16 [ 3 ] = ( unsigned char ) ( V_37 >> 16 ) & 0xff ;
V_9 . V_16 [ 4 ] = ( unsigned char ) ( V_37 >> 8 ) & 0xff ;
V_9 . V_16 [ 5 ] = ( unsigned char ) V_37 & 0xff ;
V_9 . V_16 [ 8 ] = 1 ;
V_9 . V_11 = V_120 ;
V_9 . V_18 = V_122 ;
V_9 . V_20 = V_21 ;
V_9 . V_14 = V_15 ;
V_97 = F_4 ( V_6 , & V_9 ) ;
return V_97 ;
}
int F_31 ( T_1 * V_6 )
{
unsigned char * V_127 ;
int V_128 ;
if ( ! V_129 )
return 0 ;
V_127 = F_2 ( 2048 , V_12 | F_3 ( V_6 ) ) ;
if ( ! V_127 )
return - V_13 ;
if ( 0 == F_29 ( V_6 , V_6 -> V_109 + 16 ,
V_130 , V_127 ) ) {
V_128 = ( V_127 [ 3 ] == 0x02 ) ? 1 : 0 ;
} else {
V_128 = - 1 ;
}
F_5 ( V_127 ) ;
#ifdef F_28
F_12 ( V_68 , V_6 , L_8 , V_128 ) ;
#endif
return V_128 ;
}
