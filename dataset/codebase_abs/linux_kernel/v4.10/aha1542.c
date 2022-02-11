static inline void F_1 ( T_1 V_1 )
{
F_2 ( V_2 , F_3 ( V_1 ) ) ;
}
static inline bool F_4 ( T_1 V_3 , T_2 V_4 , T_2 V_5 , T_2 V_6 , int V_7 )
{
bool V_8 = true ;
if ( V_7 == 0 ) {
V_7 = 3000000 ;
V_8 = false ;
}
while ( 1 ) {
T_2 V_9 = F_5 ( V_3 ) & V_4 ;
if ( ( V_9 & V_5 ) == V_5 && ( ( V_9 & V_6 ) == 0 ) )
break;
if ( V_8 )
F_6 ( 1 ) ;
if ( -- V_7 == 0 )
return false ;
}
return true ;
}
static int F_7 ( unsigned int V_1 , T_2 V_10 )
{
if ( ! F_4 ( F_8 ( V_1 ) , V_11 , 0 , V_11 , 0 ) )
return 1 ;
F_2 ( V_10 , F_9 ( V_1 ) ) ;
return 0 ;
}
static int F_10 ( unsigned int V_1 , T_2 * V_12 , int V_13 )
{
while ( V_13 -- ) {
if ( ! F_4 ( F_8 ( V_1 ) , V_11 , 0 , V_11 , 0 ) )
return 1 ;
F_2 ( * V_12 ++ , F_9 ( V_1 ) ) ;
}
if ( ! F_4 ( F_11 ( V_1 ) , V_14 , V_15 , 0 , 0 ) )
return 1 ;
return 0 ;
}
static int F_12 ( unsigned int V_1 , T_2 * V_12 , int V_13 , int V_7 )
{
while ( V_13 -- ) {
if ( ! F_4 ( F_8 ( V_1 ) , V_16 , V_16 , 0 , V_7 ) )
return 1 ;
* V_12 ++ = F_5 ( F_9 ( V_1 ) ) ;
}
return 0 ;
}
static int F_13 ( unsigned V_17 , unsigned V_18 )
{
switch ( V_17 ) {
case 0x0 :
case 0xa :
case 0xb :
V_17 = 0 ;
break;
case 0x11 :
V_17 = V_19 ;
break;
case 0x12 :
case 0x13 :
case 0x15 :
case 0x16 :
case 0x17 :
case 0x18 :
case 0x19 :
case 0x1a :
#ifdef F_14
F_15 ( L_1 , V_17 , V_18 ) ;
#endif
V_17 = V_20 ;
break;
case 0x14 :
V_17 = V_21 ;
break;
default:
F_15 ( V_22 L_2 , V_17 ) ;
break;
}
return V_18 | ( V_17 << 16 ) ;
}
static int F_16 ( struct V_23 * V_24 )
{
T_2 V_25 [ 4 ] ;
int V_26 ;
if ( F_5 ( F_8 ( V_24 -> V_27 ) ) == 0xff )
return 0 ;
F_1 ( V_24 -> V_27 ) ;
F_2 ( V_28 | V_2 , F_3 ( V_24 -> V_27 ) ) ;
F_6 ( 20 ) ;
if ( ! F_4 ( F_8 ( V_24 -> V_27 ) , V_29 , V_30 | V_31 , V_32 | V_33 | V_34 | V_16 | V_11 , 0 ) )
return 0 ;
if ( F_5 ( F_11 ( V_24 -> V_27 ) ) & V_14 )
return 0 ;
F_7 ( V_24 -> V_27 , V_35 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
if ( ! F_4 ( F_8 ( V_24 -> V_27 ) , V_16 , V_16 , 0 , 0 ) )
return 0 ;
V_25 [ V_26 ] = F_5 ( F_9 ( V_24 -> V_27 ) ) ;
}
if ( F_5 ( F_8 ( V_24 -> V_27 ) ) & V_16 )
return 0 ;
if ( ! F_4 ( F_11 ( V_24 -> V_27 ) , V_15 , V_15 , 0 , 0 ) )
return 0 ;
F_2 ( V_2 , F_3 ( V_24 -> V_27 ) ) ;
return 1 ;
}
static T_3 F_17 ( int V_36 , void * V_37 )
{
struct V_23 * V_24 = V_37 ;
struct V_38 * V_39 = F_18 ( V_24 ) ;
void (* F_19)( struct V_40 * ) = NULL ;
int V_41 , V_42 , V_43 , V_44 ;
int V_45 ;
unsigned long V_46 ;
struct V_40 * V_47 ;
int V_48 ;
struct V_49 * V_50 = V_39 -> V_50 ;
struct V_51 * V_51 = V_39 -> V_51 ;
#ifdef F_14
{
V_48 = F_5 ( F_11 ( V_24 -> V_27 ) ) ;
F_20 ( V_52 , V_24 , L_3 ) ;
if ( ! ( V_48 & V_53 ) )
F_15 ( L_4 ) ;
if ( V_48 & V_54 )
F_15 ( L_5 ) ;
if ( V_48 & V_55 )
F_15 ( L_6 ) ;
if ( V_48 & V_15 )
F_15 ( L_7 ) ;
if ( V_48 & V_56 )
F_15 ( L_8 ) ;
F_15 ( L_9 , F_5 ( F_8 ( V_24 -> V_27 ) ) ) ;
} ;
#endif
V_45 = 0 ;
F_21 ( V_24 -> V_57 , V_46 ) ;
while ( 1 ) {
V_48 = F_5 ( F_11 ( V_24 -> V_27 ) ) ;
if ( V_48 & ~ V_54 ) {
if ( V_48 & V_55 )
F_15 ( L_6 ) ;
if ( V_48 & V_15 )
F_15 ( L_7 ) ;
if ( V_48 & V_56 )
F_15 ( L_8 ) ;
}
F_1 ( V_24 -> V_27 ) ;
V_42 = V_39 -> V_58 + 1 ;
if ( V_42 >= 2 * V_59 )
V_42 = V_59 ;
do {
if ( V_50 [ V_42 ] . V_60 != 0 )
break;
V_42 ++ ;
if ( V_42 >= 2 * V_59 )
V_42 = V_59 ;
} while ( V_42 != V_39 -> V_58 );
if ( V_50 [ V_42 ] . V_60 == 0 ) {
F_22 ( V_24 -> V_57 , V_46 ) ;
if ( ! V_45 )
F_20 ( V_61 , V_24 , L_10 ) ;
return V_62 ;
} ;
V_43 = ( F_23 ( V_50 [ V_42 ] . V_63 ) - ( F_24 ( & V_51 [ 0 ] ) ) ) / sizeof( struct V_51 ) ;
V_44 = V_50 [ V_42 ] . V_60 ;
V_50 [ V_42 ] . V_60 = 0 ;
V_39 -> V_58 = V_42 ;
#ifdef F_14
if ( V_51 [ V_43 ] . V_64 | V_51 [ V_43 ] . V_65 )
F_20 ( V_52 , V_24 , L_11 ,
V_51 [ V_43 ] . V_64 + ( ( int ) V_51 [ V_43 ] . V_65 << 16 ) , V_50 [ V_42 ] . V_60 ) ;
#endif
if ( V_44 == 3 )
continue;
#ifdef F_14
F_20 ( V_52 , V_24 , L_12 , V_43 , V_42 ) ;
#endif
V_47 = V_39 -> V_66 [ V_43 ] ;
if ( ! V_47 || ! V_47 -> V_67 ) {
F_22 ( V_24 -> V_57 , V_46 ) ;
F_20 ( V_61 , V_24 , L_13 ) ;
F_20 ( V_61 , V_24 , L_14 , V_51 [ V_43 ] . V_64 ,
V_51 [ V_43 ] . V_65 , V_51 [ V_43 ] . V_68 , V_43 ) ;
return V_62 ;
}
F_19 = V_47 -> V_67 ;
F_25 ( V_47 -> V_69 ) ;
V_47 -> V_69 = NULL ;
if ( V_51 [ V_43 ] . V_64 == 2 )
memcpy ( V_47 -> V_70 , & V_51 [ V_43 ] . V_71 [ V_51 [ V_43 ] . V_72 ] ,
V_73 ) ;
if ( V_44 != 1 )
V_41 = F_13 ( V_51 [ V_43 ] . V_65 , V_51 [ V_43 ] . V_64 ) ;
else
V_41 = 0 ;
#ifdef F_14
if ( V_41 )
F_20 ( V_52 , V_24 , L_15 , V_41 ,
V_51 [ V_43 ] . V_65 , V_51 [ V_43 ] . V_64 ) ;
if ( V_51 [ V_43 ] . V_64 == 2 )
F_26 ( L_16 , V_74 , & V_51 [ V_43 ] . V_71 [ V_51 [ V_43 ] . V_72 ] , 12 ) ;
if ( V_41 )
F_15 ( L_17 , V_41 ) ;
#endif
V_47 -> V_75 = V_41 ;
V_39 -> V_66 [ V_43 ] = NULL ;
F_19 ( V_47 ) ;
V_45 ++ ;
} ;
}
static int F_27 ( struct V_23 * V_24 , struct V_40 * V_76 )
{
struct V_38 * V_39 = F_18 ( V_24 ) ;
T_2 V_77 ;
T_2 V_78 = V_76 -> V_79 -> V_80 ;
T_2 V_81 = V_76 -> V_79 -> V_81 ;
unsigned long V_46 ;
int V_82 = F_28 ( V_76 ) ;
int V_43 , V_83 ;
struct V_49 * V_50 = V_39 -> V_50 ;
struct V_51 * V_51 = V_39 -> V_51 ;
struct V_84 * V_85 ;
if ( * V_76 -> V_86 == V_87 ) {
V_76 -> V_75 = 0 ;
V_76 -> V_67 ( V_76 ) ;
return 0 ;
}
#ifdef F_14
{
int V_26 = - 1 ;
if ( * V_76 -> V_86 == V_88 || * V_76 -> V_86 == V_89 )
V_26 = F_29 ( V_76 -> V_86 + 2 ) ;
else if ( * V_76 -> V_86 == V_90 || * V_76 -> V_86 == V_91 )
V_26 = F_23 ( V_76 -> V_86 + 2 ) ;
F_20 ( V_52 , V_24 , L_18 ,
V_78 , * V_76 -> V_86 , V_26 , V_82 ) ;
F_26 ( L_19 , V_74 , V_76 -> V_86 , V_76 -> V_92 ) ;
}
#endif
if ( V_82 ) {
V_83 = F_30 ( V_76 ) ;
V_85 = F_31 ( sizeof( * V_85 ) * V_83 , V_93 | V_94 ) ;
if ( ! V_85 )
return V_95 ;
} else {
V_83 = 0 ;
V_85 = NULL ;
}
F_21 ( V_24 -> V_57 , V_46 ) ;
V_43 = V_39 -> V_96 + 1 ;
if ( V_43 >= V_59 )
V_43 = 0 ;
do {
if ( V_50 [ V_43 ] . V_60 == 0 && V_39 -> V_66 [ V_43 ] == NULL )
break;
V_43 ++ ;
if ( V_43 >= V_59 )
V_43 = 0 ;
} while ( V_43 != V_39 -> V_96 );
if ( V_50 [ V_43 ] . V_60 || V_39 -> V_66 [ V_43 ] )
F_32 ( L_20 ) ;
V_39 -> V_66 [ V_43 ] = V_76 ;
V_39 -> V_96 = V_43 ;
#ifdef F_14
F_20 ( V_52 , V_24 , L_21 , V_43 , V_76 -> V_67 ) ;
#endif
F_33 ( V_50 [ V_43 ] . V_63 , F_24 ( & V_51 [ V_43 ] ) ) ;
memset ( & V_51 [ V_43 ] , 0 , sizeof( struct V_51 ) ) ;
V_51 [ V_43 ] . V_72 = V_76 -> V_92 ;
V_77 = 0 ;
if ( * V_76 -> V_86 == V_88 || * V_76 -> V_86 == V_90 )
V_77 = 8 ;
else if ( * V_76 -> V_86 == V_89 || * V_76 -> V_86 == V_91 )
V_77 = 16 ;
memcpy ( V_51 [ V_43 ] . V_71 , V_76 -> V_86 , V_51 [ V_43 ] . V_72 ) ;
if ( V_82 ) {
struct V_97 * V_98 ;
int V_26 ;
V_51 [ V_43 ] . V_99 = 2 ;
V_76 -> V_69 = ( void * ) V_85 ;
F_34 (cmd, sg, sg_count, i) {
F_33 ( V_85 [ V_26 ] . V_100 , F_35 ( F_36 ( V_98 ) )
+ V_98 -> V_101 ) ;
F_33 ( V_85 [ V_26 ] . V_102 , V_98 -> V_103 ) ;
} ;
F_33 ( V_51 [ V_43 ] . V_102 , V_83 * sizeof( struct V_84 ) ) ;
F_33 ( V_51 [ V_43 ] . V_100 , F_24 ( V_85 ) ) ;
#ifdef F_14
F_20 ( V_52 , V_24 , L_22 , V_85 ) ;
F_26 ( L_23 , V_74 , V_85 , 18 ) ;
#endif
} else {
V_51 [ V_43 ] . V_99 = 0 ;
V_76 -> V_69 = NULL ;
F_33 ( V_51 [ V_43 ] . V_102 , 0 ) ;
F_33 ( V_51 [ V_43 ] . V_100 , 0 ) ;
} ;
V_51 [ V_43 ] . V_68 = ( V_78 & 7 ) << 5 | V_77 | ( V_81 & 7 ) ;
V_51 [ V_43 ] . V_104 = 16 ;
V_51 [ V_43 ] . V_105 [ 0 ] = V_51 [ V_43 ] . V_105 [ 1 ] = V_51 [ V_43 ] . V_105 [ 2 ] = 0 ;
V_51 [ V_43 ] . V_106 = 0 ;
#ifdef F_14
F_26 ( L_24 , V_74 , & V_51 [ V_43 ] , sizeof( V_51 [ V_43 ] ) - 10 ) ;
F_15 ( L_25 ) ;
#endif
V_50 [ V_43 ] . V_60 = 1 ;
F_7 ( V_76 -> V_79 -> V_107 -> V_27 , V_108 ) ;
F_22 ( V_24 -> V_57 , V_46 ) ;
return 0 ;
}
static void F_37 ( struct V_23 * V_24 )
{
struct V_38 * V_39 = F_18 ( V_24 ) ;
int V_26 ;
struct V_49 * V_50 = V_39 -> V_50 ;
struct V_51 * V_51 = V_39 -> V_51 ;
T_2 V_109 [ 5 ] = { V_110 , V_59 , 0 , 0 , 0 } ;
for ( V_26 = 0 ; V_26 < V_59 ; V_26 ++ ) {
V_50 [ V_26 ] . V_60 = V_50 [ V_59 + V_26 ] . V_60 = 0 ;
F_33 ( V_50 [ V_26 ] . V_63 , F_24 ( & V_51 [ V_26 ] ) ) ;
} ;
F_1 ( V_24 -> V_27 ) ;
F_33 ( ( V_109 + 2 ) , F_24 ( V_50 ) ) ;
if ( F_10 ( V_24 -> V_27 , V_109 , 5 ) )
F_20 ( V_22 , V_24 , L_26 ) ;
F_1 ( V_24 -> V_27 ) ;
}
static int F_38 ( struct V_23 * V_24 )
{
T_2 V_25 [ 3 ] ;
int V_26 ;
V_26 = F_5 ( F_8 ( V_24 -> V_27 ) ) ;
if ( V_26 & V_16 ) {
V_26 = F_5 ( F_9 ( V_24 -> V_27 ) ) ;
} ;
F_7 ( V_24 -> V_27 , V_111 ) ;
F_12 ( V_24 -> V_27 , V_25 , 3 , 0 ) ;
if ( ! F_4 ( F_11 ( V_24 -> V_27 ) , V_14 , V_15 , 0 , 0 ) )
F_20 ( V_22 , V_24 , L_27 ) ;
F_1 ( V_24 -> V_27 ) ;
switch ( V_25 [ 0 ] ) {
case 0x80 :
V_24 -> V_112 = 7 ;
break;
case 0x40 :
V_24 -> V_112 = 6 ;
break;
case 0x20 :
V_24 -> V_112 = 5 ;
break;
case 0x01 :
V_24 -> V_112 = 0 ;
break;
case 0 :
V_24 -> V_112 = 0xFF ;
break;
default:
F_20 ( V_22 , V_24 , L_28 ) ;
return - 1 ;
} ;
switch ( V_25 [ 1 ] ) {
case 0x40 :
V_24 -> V_36 = 15 ;
break;
case 0x20 :
V_24 -> V_36 = 14 ;
break;
case 0x8 :
V_24 -> V_36 = 12 ;
break;
case 0x4 :
V_24 -> V_36 = 11 ;
break;
case 0x2 :
V_24 -> V_36 = 10 ;
break;
case 0x1 :
V_24 -> V_36 = 9 ;
break;
default:
F_20 ( V_22 , V_24 , L_29 ) ;
return - 1 ;
} ;
V_24 -> V_113 = V_25 [ 2 ] & 7 ;
return 0 ;
}
static int F_39 ( struct V_23 * V_24 )
{
static T_2 V_114 [ 3 ] ;
static T_2 V_115 [ 2 ] ;
int V_116 ;
V_116 = V_117 ;
F_7 ( V_24 -> V_27 , V_118 ) ;
if ( F_12 ( V_24 -> V_27 , V_115 , 2 , 100 ) )
return V_116 ;
if ( ! F_4 ( F_11 ( V_24 -> V_27 ) , V_14 , V_15 , 0 , 100 ) )
goto V_119;
F_1 ( V_24 -> V_27 ) ;
if ( ( V_115 [ 0 ] & 0x08 ) || V_115 [ 1 ] ) {
V_114 [ 0 ] = V_120 ;
V_114 [ 1 ] = 0 ;
V_114 [ 2 ] = V_115 [ 1 ] ;
if ( ( V_115 [ 0 ] & 0x08 ) && ( V_115 [ 1 ] & 0x03 ) )
V_116 = V_121 ;
if ( F_10 ( V_24 -> V_27 , V_114 , 3 ) )
goto V_119;
} ;
while ( 0 ) {
V_119:
F_20 ( V_22 , V_24 , L_30 ) ;
}
F_1 ( V_24 -> V_27 ) ;
return V_116 ;
}
static int F_40 ( struct V_23 * V_24 )
{
struct V_38 * V_39 = F_18 ( V_24 ) ;
T_2 V_25 [ 4 ] ;
int V_26 ;
V_26 = F_5 ( F_8 ( V_24 -> V_27 ) ) ;
if ( V_26 & V_16 ) {
V_26 = F_5 ( F_9 ( V_24 -> V_27 ) ) ;
} ;
F_7 ( V_24 -> V_27 , V_35 ) ;
F_12 ( V_24 -> V_27 , V_25 , 4 , 0 ) ;
if ( ! F_4 ( F_11 ( V_24 -> V_27 ) , V_14 , V_15 , 0 , 0 ) )
F_20 ( V_22 , V_24 , L_31 ) ;
F_1 ( V_24 -> V_27 ) ;
V_39 -> V_122 = V_117 ;
if ( V_25 [ 0 ] == 0x43 ) {
F_20 ( V_123 , V_24 , L_32 ) ;
return 1 ;
} ;
V_39 -> V_122 = F_39 ( V_24 ) ;
return 0 ;
}
static T_2 F_41 ( int V_124 )
{
switch ( V_124 ) {
case 5 :
return 0x00 ;
case 6 :
return 0x04 ;
case 7 :
return 0x01 ;
case 8 :
return 0x02 ;
case 10 :
return 0x03 ;
}
return 0xff ;
}
static void F_42 ( struct V_23 * V_24 , int V_125 , int V_126 , int V_124 )
{
if ( V_125 > 0 ) {
T_2 V_127 [] = { V_128 , F_43 (bus_on, 2 , 15 ) } ;
F_1 ( V_24 -> V_27 ) ;
if ( F_10 ( V_24 -> V_27 , V_127 , 2 ) )
goto V_119;
}
if ( V_126 > 0 ) {
T_2 V_129 [] = { V_130 , F_43 (bus_off, 1 , 64 ) } ;
F_1 ( V_24 -> V_27 ) ;
if ( F_10 ( V_24 -> V_27 , V_129 , 2 ) )
goto V_119;
}
if ( F_41 ( V_124 ) != 0xff ) {
T_2 V_131 [] = { V_132 , F_41 (dma_speed) } ;
F_1 ( V_24 -> V_27 ) ;
if ( F_10 ( V_24 -> V_27 , V_131 , 2 ) )
goto V_119;
}
F_1 ( V_24 -> V_27 ) ;
return;
V_119:
F_20 ( V_22 , V_24 , L_33 ) ;
F_1 ( V_24 -> V_27 ) ;
}
static struct V_23 * F_44 ( struct V_133 * V_134 , struct V_79 * V_135 , int V_136 )
{
unsigned int V_137 = V_138 [ V_136 ] ;
struct V_23 * V_24 ;
struct V_38 * V_39 ;
char V_139 [] = L_34 ;
if ( V_137 == 0 )
return NULL ;
if ( ! F_45 ( V_137 , V_140 , L_35 ) )
return NULL ;
V_24 = F_46 ( V_134 , sizeof( struct V_38 ) ) ;
if ( ! V_24 )
goto V_141;
V_39 = F_18 ( V_24 ) ;
V_24 -> V_142 = V_137 ;
V_24 -> V_27 = V_137 ;
V_24 -> V_143 = V_140 ;
V_39 -> V_58 = 2 * V_59 - 1 ;
V_39 -> V_96 = V_59 - 1 ;
if ( ! F_16 ( V_24 ) )
goto V_144;
F_42 ( V_24 , V_125 [ V_136 ] , V_126 [ V_136 ] , V_124 [ V_136 ] ) ;
if ( F_40 ( V_24 ) )
goto V_144;
if ( F_38 ( V_24 ) == - 1 )
goto V_144;
if ( V_24 -> V_112 != 0xFF )
snprintf ( V_139 , sizeof( V_139 ) , L_36 , V_24 -> V_112 ) ;
F_20 ( V_123 , V_24 , L_37 ,
V_24 -> V_113 , V_137 , V_24 -> V_36 , V_139 ) ;
if ( V_39 -> V_122 == V_121 )
F_20 ( V_123 , V_24 , L_38 ) ;
F_37 ( V_24 ) ;
if ( F_47 ( V_24 -> V_36 , F_17 , 0 , L_35 , V_24 ) ) {
F_20 ( V_22 , V_24 , L_39 ) ;
goto V_144;
}
if ( V_24 -> V_112 != 0xFF ) {
if ( F_48 ( V_24 -> V_112 , L_35 ) ) {
F_20 ( V_22 , V_24 , L_40 ) ;
goto V_145;
}
if ( V_24 -> V_112 == 0 || V_24 -> V_112 >= 5 ) {
F_49 ( V_24 -> V_112 , V_146 ) ;
F_50 ( V_24 -> V_112 ) ;
}
}
if ( F_51 ( V_24 , V_135 ) )
goto V_147;
F_52 ( V_24 ) ;
return V_24 ;
V_147:
if ( V_24 -> V_112 != 0xff )
V_147 ( V_24 -> V_112 ) ;
V_145:
V_145 ( V_24 -> V_36 , V_24 ) ;
V_144:
F_53 ( V_24 ) ;
V_141:
F_54 ( V_137 , V_140 ) ;
return NULL ;
}
static int F_55 ( struct V_23 * V_24 )
{
F_56 ( V_24 ) ;
if ( V_24 -> V_112 != 0xff )
V_147 ( V_24 -> V_112 ) ;
if ( V_24 -> V_36 )
V_145 ( V_24 -> V_36 , V_24 ) ;
if ( V_24 -> V_27 && V_24 -> V_143 )
F_54 ( V_24 -> V_27 , V_24 -> V_143 ) ;
F_53 ( V_24 ) ;
return 0 ;
}
static int F_57 ( struct V_40 * V_76 )
{
struct V_23 * V_24 = V_76 -> V_79 -> V_107 ;
struct V_38 * V_39 = F_18 ( V_24 ) ;
unsigned long V_46 ;
struct V_49 * V_50 = V_39 -> V_50 ;
T_2 V_78 = V_76 -> V_79 -> V_80 ;
T_2 V_81 = V_76 -> V_79 -> V_81 ;
int V_43 ;
struct V_51 * V_51 = V_39 -> V_51 ;
F_21 ( V_24 -> V_57 , V_46 ) ;
V_43 = V_39 -> V_96 + 1 ;
if ( V_43 >= V_59 )
V_43 = 0 ;
do {
if ( V_50 [ V_43 ] . V_60 == 0 && V_39 -> V_66 [ V_43 ] == NULL )
break;
V_43 ++ ;
if ( V_43 >= V_59 )
V_43 = 0 ;
} while ( V_43 != V_39 -> V_96 );
if ( V_50 [ V_43 ] . V_60 || V_39 -> V_66 [ V_43 ] )
F_32 ( L_20 ) ;
V_39 -> V_66 [ V_43 ] = V_76 ;
V_39 -> V_96 = V_43 ;
F_33 ( V_50 [ V_43 ] . V_63 , F_24 ( & V_51 [ V_43 ] ) ) ;
memset ( & V_51 [ V_43 ] , 0 , sizeof( struct V_51 ) ) ;
V_51 [ V_43 ] . V_99 = 0x81 ;
V_51 [ V_43 ] . V_68 = ( V_78 & 7 ) << 5 | ( V_81 & 7 ) ;
V_51 [ V_43 ] . V_105 [ 0 ] = V_51 [ V_43 ] . V_105 [ 1 ] = V_51 [ V_43 ] . V_105 [ 2 ] = 0 ;
V_51 [ V_43 ] . V_106 = 0 ;
F_7 ( V_24 -> V_27 , V_108 ) ;
F_22 ( V_24 -> V_57 , V_46 ) ;
F_58 ( V_61 , V_76 ,
L_41 ) ;
return V_148 ;
}
static int F_59 ( struct V_40 * V_76 , T_2 V_149 )
{
struct V_23 * V_24 = V_76 -> V_79 -> V_107 ;
struct V_38 * V_39 = F_18 ( V_24 ) ;
unsigned long V_46 ;
int V_26 ;
F_21 ( V_24 -> V_57 , V_46 ) ;
F_2 ( V_149 , F_3 ( V_76 -> V_79 -> V_107 -> V_27 ) ) ;
if ( ! F_4 ( F_8 ( V_76 -> V_79 -> V_107 -> V_27 ) ,
V_29 , V_31 , V_32 | V_33 | V_34 | V_16 | V_11 , 0 ) ) {
F_22 ( V_24 -> V_57 , V_46 ) ;
return V_150 ;
}
if ( V_149 & V_151 )
F_37 ( V_76 -> V_79 -> V_107 ) ;
F_20 ( V_61 , V_76 -> V_79 -> V_107 , L_42 , V_76 -> V_79 -> V_107 -> V_152 ) ;
for ( V_26 = 0 ; V_26 < V_59 ; V_26 ++ ) {
if ( V_39 -> V_66 [ V_26 ] != NULL ) {
struct V_40 * V_47 ;
V_47 = V_39 -> V_66 [ V_26 ] ;
if ( V_47 -> V_79 -> V_153 ) {
continue;
}
F_25 ( V_47 -> V_69 ) ;
V_47 -> V_69 = NULL ;
V_39 -> V_66 [ V_26 ] = NULL ;
V_39 -> V_50 [ V_26 ] . V_60 = 0 ;
}
}
F_22 ( V_24 -> V_57 , V_46 ) ;
return V_148 ;
}
static int F_60 ( struct V_40 * V_76 )
{
return F_59 ( V_76 , V_154 ) ;
}
static int F_61 ( struct V_40 * V_76 )
{
return F_59 ( V_76 , V_151 | V_154 ) ;
}
static int F_62 ( struct V_155 * V_156 ,
struct V_157 * V_158 , T_4 V_159 , int V_160 [] )
{
struct V_38 * V_39 = F_18 ( V_156 -> V_107 ) ;
if ( V_159 >= 0x200000 &&
V_39 -> V_122 == V_121 ) {
V_160 [ 0 ] = 255 ;
V_160 [ 1 ] = 63 ;
} else {
V_160 [ 0 ] = 64 ;
V_160 [ 1 ] = 32 ;
}
V_160 [ 2 ] = F_63 ( V_159 , V_160 [ 0 ] * V_160 [ 1 ] ) ;
return 0 ;
}
static int F_64 ( struct V_79 * V_135 , unsigned int V_161 )
{
struct V_23 * V_24 = F_44 ( & V_162 , V_135 , V_161 ) ;
if ( ! V_24 )
return 0 ;
F_65 ( V_135 , V_24 ) ;
return 1 ;
}
static int F_66 ( struct V_79 * V_135 ,
unsigned int V_161 )
{
F_55 ( F_67 ( V_135 ) ) ;
F_65 ( V_135 , NULL ) ;
return 0 ;
}
static int F_68 ( struct V_163 * V_135 , const struct V_164 * V_80 )
{
int V_136 ;
struct V_23 * V_24 ;
for ( V_136 = 0 ; V_136 < F_69 ( V_138 ) ; V_136 ++ ) {
if ( V_138 [ V_136 ] )
continue;
if ( F_70 ( V_135 ) < 0 )
continue;
V_138 [ V_136 ] = F_71 ( V_135 , 0 ) ;
F_72 ( & V_135 -> V_165 , L_43 , V_138 [ V_136 ] ) ;
}
V_24 = F_44 ( & V_162 , & V_135 -> V_165 , V_136 ) ;
if ( ! V_24 )
return - V_166 ;
F_73 ( V_135 , V_24 ) ;
return 0 ;
}
static void F_74 ( struct V_163 * V_135 )
{
F_55 ( F_75 ( V_135 ) ) ;
F_73 ( V_135 , NULL ) ;
}
static int T_5 F_76 ( void )
{
int V_167 = 0 ;
#ifdef F_77
if ( V_168 ) {
V_167 = F_78 ( & V_169 ) ;
if ( ! V_167 )
V_170 = 1 ;
}
#endif
V_167 = F_79 ( & V_171 , V_172 ) ;
if ( ! V_167 )
V_173 = 1 ;
#ifdef F_77
if ( V_170 )
V_167 = 0 ;
#endif
if ( V_173 )
V_167 = 0 ;
return V_167 ;
}
static void T_6 F_80 ( void )
{
#ifdef F_77
if ( V_170 )
F_81 ( & V_169 ) ;
#endif
if ( V_173 )
F_82 ( & V_171 ) ;
}
