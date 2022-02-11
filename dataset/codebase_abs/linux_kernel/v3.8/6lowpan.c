static inline struct
V_1 * V_1 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static inline void F_2 ( T_1 * V_4 , T_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
( V_5 ) [ V_7 - V_6 - 1 ] = ( V_4 ) [ V_6 ] ;
}
static inline void F_3 ( const char * V_8 , char * V_9 ,
unsigned char * V_10 , int V_11 )
{
#ifdef F_4
if ( V_9 )
F_5 ( L_1 , V_8 , V_9 ) ;
F_6 ( V_12 , L_2 , V_13 ,
16 , 1 , V_10 , V_11 , false ) ;
#endif
}
static inline void F_7 ( const char * V_8 , char * V_9 ,
unsigned char * V_10 , int V_11 )
{
#ifdef F_4
if ( V_9 )
F_5 ( L_3 , V_8 , V_9 ) ;
F_6 ( V_12 , L_4 , V_14 ,
16 , 1 , V_10 , V_11 , false ) ;
#endif
}
static T_1
F_8 ( T_1 * * V_15 , T_1 V_16 , const struct V_17 * V_18 ,
const unsigned char * V_19 )
{
T_1 V_20 = 0 ;
if ( F_9 ( V_18 , V_19 ) )
V_20 = 3 ;
else if ( F_10 ( V_18 ) ) {
memcpy ( * V_15 , & V_18 -> V_21 [ 7 ] , 2 ) ;
* V_15 += 2 ;
V_20 = 2 ;
} else {
memcpy ( * V_15 , & V_18 -> V_21 [ 4 ] , 8 ) ;
* V_15 += 8 ;
V_20 = 1 ;
}
return F_11 ( V_20 , V_16 ) ;
}
static void
F_12 ( struct V_17 * V_18 , unsigned char * V_19 )
{
memcpy ( & V_18 -> V_22 [ 8 ] , V_19 , V_7 ) ;
V_18 -> V_22 [ 8 ] ^= 0x02 ;
}
static int
F_13 ( struct V_23 * V_24 , struct V_17 * V_18 ,
T_1 const * V_25 , T_1 V_26 , unsigned char * V_19 )
{
T_1 V_27 = V_26 >> 4 ;
T_1 V_28 = V_26 & 0x0f ;
V_27 = ( V_27 == 15 ? 16 : V_27 ) ;
V_28 = ( V_28 == 15 ? 16 : V_28 ) ;
if ( V_19 )
F_3 ( V_29 , L_5 ,
V_19 , V_7 ) ;
if ( V_27 > 0 )
memcpy ( V_18 , V_25 , V_27 ) ;
if ( V_27 + V_28 < 16 )
memset ( & V_18 -> V_22 [ V_27 ] , 0 ,
16 - ( V_27 + V_28 ) ) ;
if ( V_28 > 0 ) {
memcpy ( & V_18 -> V_22 [ 16 - V_28 ] , V_24 -> V_30 , V_28 ) ;
F_14 ( V_24 , V_28 ) ;
} else if ( V_27 > 0 ) {
if ( V_19 == NULL )
return - V_31 ;
F_12 ( V_18 , V_19 ) ;
}
F_5 ( L_6 , V_27 , V_28 ) ;
F_3 ( NULL , NULL , V_18 -> V_22 , 16 ) ;
return 0 ;
}
static void
F_15 ( T_1 * * V_15 , struct V_23 * V_24 )
{
struct V_32 * V_33 = F_16 ( V_24 ) ;
if ( ( ( V_33 -> V_34 & V_35 ) ==
V_36 ) &&
( ( V_33 -> V_5 & V_35 ) ==
V_36 ) ) {
F_5 ( L_7 ) ;
* * V_15 = V_37 ;
* * ( V_15 + 1 ) =
( T_1 ) ( ( V_33 -> V_5 - V_36 ) +
( ( V_33 -> V_34 & V_36 ) << 4 ) ) ;
* V_15 += 2 ;
} else if ( ( V_33 -> V_5 & V_38 ) ==
V_39 ) {
F_5 ( L_8 ) ;
* * V_15 = V_40 ;
memcpy ( * V_15 + 1 , & V_33 -> V_34 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_33 -> V_5 - V_39 ) ;
* V_15 += 4 ;
} else if ( ( V_33 -> V_34 & V_38 ) ==
V_39 ) {
F_5 ( L_9 ) ;
* * V_15 = V_41 ;
memcpy ( * V_15 + 1 , & V_33 -> V_5 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_33 -> V_34 - V_39 ) ;
* V_15 += 4 ;
} else {
F_5 ( L_10 ) ;
* * V_15 = V_42 ;
memcpy ( * V_15 + 1 , & V_33 -> V_34 , 2 ) ;
memcpy ( * V_15 + 3 , & V_33 -> V_5 , 2 ) ;
* V_15 += 5 ;
}
memcpy ( * V_15 , & V_33 -> V_43 , 2 ) ;
* V_15 += 2 ;
}
static inline int F_17 ( struct V_23 * V_24 , T_1 * V_20 )
{
if ( F_18 ( ! F_19 ( V_24 , 1 ) ) )
return - V_31 ;
* V_20 = V_24 -> V_30 [ 0 ] ;
F_14 ( V_24 , 1 ) ;
return 0 ;
}
static inline int F_20 ( struct V_23 * V_24 , T_2 * V_20 )
{
if ( F_18 ( ! F_19 ( V_24 , 2 ) ) )
return - V_31 ;
* V_20 = ( V_24 -> V_30 [ 0 ] << 8 ) | V_24 -> V_30 [ 1 ] ;
F_14 ( V_24 , 2 ) ;
return 0 ;
}
static int
F_21 ( struct V_23 * V_24 )
{
struct V_32 * V_33 = F_16 ( V_24 ) ;
T_1 V_44 ;
if ( ! V_33 )
goto V_45;
if ( F_17 ( V_24 , & V_44 ) )
goto V_45;
if ( ( V_44 & V_46 ) == V_47 ) {
F_5 ( L_11 ) ;
switch ( V_44 & V_37 ) {
case V_42 :
memcpy ( & V_33 -> V_34 , & V_24 -> V_30 [ 0 ] , 2 ) ;
memcpy ( & V_33 -> V_5 , & V_24 -> V_30 [ 2 ] , 2 ) ;
F_14 ( V_24 , 4 ) ;
break;
case V_40 :
memcpy ( & V_33 -> V_34 , & V_24 -> V_30 [ 0 ] , 2 ) ;
V_33 -> V_5 =
V_24 -> V_30 [ 2 ] + V_39 ;
F_14 ( V_24 , 3 ) ;
break;
case V_41 :
V_33 -> V_34 = V_24 -> V_30 [ 0 ] + V_39 ;
memcpy ( & V_33 -> V_5 , & V_24 -> V_30 [ 1 ] , 2 ) ;
F_14 ( V_24 , 3 ) ;
break;
case V_37 :
V_33 -> V_34 =
V_36 + ( V_24 -> V_30 [ 0 ] >> 4 ) ;
V_33 -> V_5 =
V_36 + ( V_24 -> V_30 [ 0 ] & 0x0f ) ;
F_14 ( V_24 , 1 ) ;
break;
default:
F_5 ( L_12 ) ;
goto V_45;
break;
}
F_5 ( L_13 ,
V_33 -> V_34 , V_33 -> V_5 ) ;
memcpy ( & V_33 -> V_43 , & V_24 -> V_30 [ 0 ] , 2 ) ;
F_14 ( V_24 , 2 ) ;
} else {
F_5 ( L_14 ) ;
goto V_45;
}
return 0 ;
V_45:
return - V_31 ;
}
static int F_22 ( struct V_23 * V_24 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_48 ,
const void * V_49 , unsigned int V_11 )
{
T_1 V_44 , V_50 , V_51 , * V_15 ;
struct V_52 * V_53 ;
const T_1 * V_54 = V_49 ;
const T_1 * V_55 = V_48 ;
T_1 * V_56 ;
struct V_57 V_58 , V_59 ;
if ( type != V_60 )
return 0 ;
V_56 = F_23 ( 100 , V_61 ) ;
if ( V_56 == NULL )
return - V_62 ;
V_53 = F_24 ( V_24 ) ;
V_15 = V_56 + 2 ;
F_5 ( L_15
L_16 , V_53 -> V_63 ,
F_25 ( V_53 -> V_64 ) , V_53 -> V_65 , V_53 -> V_66 ) ;
F_7 ( V_29 , L_17 ,
F_26 ( V_24 ) , sizeof( struct V_52 ) ) ;
if ( ! V_54 )
V_54 = V_3 -> V_67 ;
F_3 ( V_29 , L_18 , ( unsigned char * ) V_54 , 8 ) ;
V_50 = V_68 ;
V_51 = 0 ;
F_3 ( V_29 , L_19 , ( unsigned char * ) V_55 , 8 ) ;
V_44 = ( V_53 -> V_69 << 4 ) | ( V_53 -> V_70 [ 0 ] >> 4 ) ;
V_44 = ( ( V_44 & 0x03 ) << 6 ) | ( V_44 >> 2 ) ;
if ( ( ( V_53 -> V_70 [ 0 ] & 0x0F ) == 0 ) &&
( V_53 -> V_70 [ 1 ] == 0 ) && ( V_53 -> V_70 [ 2 ] == 0 ) ) {
V_50 |= V_71 ;
if ( ( V_53 -> V_69 == 0 ) &&
( ( V_53 -> V_70 [ 0 ] & 0xF0 ) == 0 ) ) {
V_50 |= V_72 ;
} else {
* V_15 = V_44 ;
V_15 += 1 ;
}
} else {
if ( ( V_53 -> V_69 == 0 ) &&
( ( V_53 -> V_70 [ 0 ] & 0xF0 ) == 0 ) ) {
V_50 |= V_72 ;
* V_15 = ( V_44 & 0xc0 ) | ( V_53 -> V_70 [ 0 ] & 0x0F ) ;
memcpy ( V_15 + 1 , & V_53 -> V_70 [ 1 ] , 2 ) ;
V_15 += 3 ;
} else {
memcpy ( V_15 , & V_53 , 4 ) ;
* V_15 = V_44 ;
V_15 += 4 ;
}
}
if ( V_53 -> V_65 == V_73 )
V_50 |= V_74 ;
if ( ( V_50 & V_74 ) == 0 ) {
* V_15 = V_53 -> V_65 ;
V_15 += 1 ;
}
switch ( V_53 -> V_66 ) {
case 1 :
V_50 |= V_75 ;
break;
case 64 :
V_50 |= V_76 ;
break;
case 255 :
V_50 |= V_77 ;
break;
default:
* V_15 = V_53 -> V_66 ;
V_15 += 1 ;
break;
}
if ( F_27 ( & V_53 -> V_54 ) ) {
F_5 ( L_20 ) ;
V_51 |= V_78 ;
} else if ( F_28 ( & V_53 -> V_54 ) ) {
F_5 ( L_21 ) ;
V_51 |= F_8 ( & V_15 ,
V_79 , & V_53 -> V_54 , V_54 ) ;
} else {
F_5 ( L_22 ) ;
memcpy ( V_15 , & V_53 -> V_54 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
if ( F_29 ( & V_53 -> V_55 ) ) {
F_5 ( L_23 ) ;
V_51 |= V_80 ;
if ( F_30 ( & V_53 -> V_55 ) ) {
F_5 ( L_24 ) ;
V_51 |= V_81 ;
* V_15 = V_53 -> V_55 . V_22 [ 15 ] ;
V_15 += 1 ;
} else if ( F_31 ( & V_53 -> V_55 ) ) {
F_5 ( L_25 ) ;
V_51 |= V_82 ;
* V_15 = V_53 -> V_55 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_53 -> V_55 . V_22 [ 13 ] , 3 ) ;
V_15 += 4 ;
} else if ( F_32 ( & V_53 -> V_55 ) ) {
F_5 ( L_26 ) ;
V_51 |= V_83 ;
* V_15 = V_53 -> V_55 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_53 -> V_55 . V_22 [ 11 ] , 5 ) ;
V_15 += 6 ;
} else {
F_5 ( L_27 ) ;
V_51 |= V_84 ;
memcpy ( V_15 , & V_53 -> V_55 . V_22 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
} else {
if ( F_28 ( & V_53 -> V_55 ) ) {
F_5 ( L_28 ) ;
V_51 |= F_8 ( & V_15 ,
V_85 , & V_53 -> V_55 , V_55 ) ;
} else {
F_5 ( L_29 ) ;
memcpy ( V_15 , & V_53 -> V_55 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
}
if ( V_53 -> V_65 == V_73 )
F_15 ( & V_15 , V_24 ) ;
V_56 [ 0 ] = V_50 ;
V_56 [ 1 ] = V_51 ;
F_14 ( V_24 , sizeof( struct V_52 ) ) ;
memcpy ( F_33 ( V_24 , V_15 - V_56 ) , V_56 , V_15 - V_56 ) ;
F_34 ( V_56 ) ;
F_7 ( V_29 , L_30 , V_24 -> V_30 ,
V_24 -> V_11 ) ;
{
V_58 . V_86 = V_87 ;
V_58 . V_88 = 0xff ;
V_59 . V_86 = V_87 ;
V_59 . V_88 = 0xff ;
memcpy ( & ( V_59 . V_89 ) , V_55 , 8 ) ;
memcpy ( & ( V_58 . V_89 ) , V_54 , 8 ) ;
F_35 ( V_24 ) -> V_90 = V_91 ;
return F_36 ( V_24 , V_1 ( V_3 ) -> V_92 ,
type , ( void * ) & V_59 , ( void * ) & V_58 , V_24 -> V_11 ) ;
}
}
static int F_37 ( struct V_23 * V_24 , struct V_52 * V_53 )
{
struct V_23 * V_93 ;
struct V_94 * V_95 ;
int V_96 = V_97 ;
V_93 = F_38 ( V_24 , sizeof( struct V_52 ) , F_39 ( V_24 ) ,
V_98 ) ;
F_40 ( V_24 ) ;
if ( ! V_93 )
return - V_62 ;
F_33 ( V_93 , sizeof( struct V_52 ) ) ;
F_41 ( V_93 ) ;
F_42 ( V_93 , V_53 , sizeof( struct V_52 ) ) ;
V_93 -> V_99 = F_43 ( V_60 ) ;
V_93 -> V_100 = V_101 ;
F_44 () ;
F_45 (entry, &lowpan_devices, list)
if ( V_1 ( V_95 -> V_102 ) -> V_92 == V_93 -> V_3 ) {
V_24 = F_46 ( V_93 , V_98 ) ;
if ( ! V_24 ) {
V_96 = - V_62 ;
break;
}
V_24 -> V_3 = V_95 -> V_102 ;
V_96 = F_47 ( V_24 ) ;
}
F_48 () ;
F_40 ( V_93 ) ;
return V_96 ;
}
static void F_49 ( unsigned long V_103 )
{
struct V_104 * V_95 = (struct V_104 * ) V_103 ;
F_5 ( L_31 , V_95 -> V_105 ) ;
F_50 ( & V_95 -> V_106 ) ;
F_51 ( V_95 -> V_24 ) ;
F_34 ( V_95 ) ;
}
static struct V_104 *
F_52 ( struct V_23 * V_24 , T_1 V_11 , T_2 V_105 )
{
struct V_104 * V_107 ;
V_107 = F_23 ( sizeof( struct V_104 ) ,
V_98 ) ;
if ( ! V_107 )
goto V_108;
F_53 ( & V_107 -> V_106 ) ;
V_107 -> V_109 = V_11 ;
V_107 -> V_105 = V_105 ;
V_107 -> V_24 = F_54 ( V_24 -> V_3 , V_107 -> V_109 +
sizeof( struct V_52 ) ) ;
if ( ! V_107 -> V_24 )
goto V_110;
V_107 -> V_24 -> V_69 = V_24 -> V_69 ;
V_107 -> V_24 -> V_3 = V_24 -> V_3 ;
F_55 ( V_107 -> V_24 , sizeof( struct V_52 ) ) ;
F_56 ( V_107 -> V_24 , V_107 -> V_109 ) ;
F_57 ( & V_107 -> V_111 ) ;
V_107 -> V_111 . V_112 = V_113 + V_114 ;
V_107 -> V_111 . V_30 = ( unsigned long ) V_107 ;
V_107 -> V_111 . V_115 = F_49 ;
F_58 ( & V_107 -> V_111 ) ;
F_59 ( & V_107 -> V_106 , & V_116 ) ;
return V_107 ;
V_110:
F_34 ( V_107 ) ;
V_108:
return NULL ;
}
static int
F_60 ( struct V_23 * V_24 )
{
struct V_52 V_53 ;
T_1 V_44 , V_50 , V_51 , V_117 = 0 ;
T_1 * V_49 , * V_48 ;
int V_45 ;
F_7 ( V_29 , L_30 , V_24 -> V_30 ,
V_24 -> V_11 ) ;
if ( V_24 -> V_11 < 2 )
goto V_118;
if ( F_17 ( V_24 , & V_50 ) )
goto V_118;
switch ( V_50 & V_119 ) {
case V_120 :
case V_121 :
{
struct V_104 * V_107 ;
T_1 V_122 , V_123 ;
T_2 V_11 , V_105 ;
bool V_124 = false ;
if ( F_17 ( V_24 , & V_122 ) ||
F_20 ( V_24 , & V_105 ) )
goto V_118;
V_11 = ( ( V_50 & 7 ) << 8 ) | V_122 ;
F_61 ( & V_125 ) ;
F_62 (frame, &lowpan_fragments, list)
if ( V_107 -> V_105 == V_105 ) {
V_124 = true ;
break;
}
if ( ! V_124 ) {
V_107 = F_52 ( V_24 , V_11 , V_105 ) ;
if ( ! V_107 )
goto V_126;
}
if ( ( V_50 & V_119 ) == V_120 )
goto V_126;
if ( F_17 ( V_24 , & V_123 ) )
goto V_126;
if ( F_63 ( ( V_123 * 8 + V_24 -> V_11 ) <= V_107 -> V_109 ) )
F_64 ( V_107 -> V_24 , V_123 * 8 ,
V_24 -> V_30 , V_24 -> V_11 ) ;
else
goto V_126;
V_107 -> V_127 += V_24 -> V_11 ;
if ( ( V_107 -> V_127 == V_107 -> V_109 ) &&
V_107 -> V_111 . V_112 > V_113 ) {
F_65 ( & V_107 -> V_111 ) ;
F_50 ( & V_107 -> V_106 ) ;
F_66 ( & V_125 ) ;
F_51 ( V_24 ) ;
V_24 = V_107 -> V_24 ;
F_34 ( V_107 ) ;
if ( F_17 ( V_24 , & V_50 ) )
goto V_118;
break;
}
F_66 ( & V_125 ) ;
return F_40 ( V_24 ) , 0 ;
}
default:
break;
}
if ( F_17 ( V_24 , & V_51 ) )
goto V_118;
V_49 = F_35 ( V_24 ) -> V_58 . V_89 ;
V_48 = F_35 ( V_24 ) -> V_59 . V_89 ;
F_5 ( L_32 , V_50 , V_51 ) ;
if ( V_51 & V_128 ) {
F_5 ( L_33 ) ;
if ( F_17 ( V_24 , & V_117 ) )
goto V_118;
}
V_53 . V_63 = 6 ;
switch ( ( V_50 & V_129 ) >> 3 ) {
case 0 :
if ( F_17 ( V_24 , & V_44 ) )
goto V_118;
memcpy ( & V_53 . V_70 , & V_24 -> V_30 [ 0 ] , 3 ) ;
F_14 ( V_24 , 3 ) ;
V_53 . V_69 = ( ( V_44 >> 2 ) & 0x0f ) ;
V_53 . V_70 [ 0 ] = ( ( V_44 >> 2 ) & 0x30 ) | ( V_44 << 6 ) |
( V_53 . V_70 [ 0 ] & 0x0f ) ;
break;
case 1 :
if ( F_17 ( V_24 , & V_44 ) )
goto V_118;
V_53 . V_69 = ( ( V_44 >> 2 ) & 0x0f ) ;
V_53 . V_70 [ 0 ] = ( ( V_44 << 6 ) & 0xC0 ) | ( ( V_44 >> 2 ) & 0x30 ) ;
V_53 . V_70 [ 1 ] = 0 ;
V_53 . V_70 [ 2 ] = 0 ;
break;
case 2 :
if ( F_17 ( V_24 , & V_44 ) )
goto V_118;
V_53 . V_70 [ 0 ] = ( V_24 -> V_30 [ 0 ] & 0x0F ) | ( ( V_44 >> 2 ) & 0x30 ) ;
memcpy ( & V_53 . V_70 [ 1 ] , & V_24 -> V_30 [ 0 ] , 2 ) ;
F_14 ( V_24 , 2 ) ;
break;
case 3 :
V_53 . V_69 = 0 ;
V_53 . V_70 [ 0 ] = 0 ;
V_53 . V_70 [ 1 ] = 0 ;
V_53 . V_70 [ 2 ] = 0 ;
break;
default:
break;
}
if ( ( V_50 & V_74 ) == 0 ) {
if ( F_17 ( V_24 , & ( V_53 . V_65 ) ) )
goto V_118;
F_5 ( L_34 ,
V_53 . V_65 ) ;
}
if ( ( V_50 & 0x03 ) != V_130 )
V_53 . V_66 = V_131 [ V_50 & 0x03 ] ;
else {
if ( F_17 ( V_24 , & ( V_53 . V_66 ) ) )
goto V_118;
}
V_44 = ( ( V_51 & V_132 ) >> V_79 ) & 0x03 ;
F_5 ( L_35 ) ;
V_45 = F_13 ( V_24 , & V_53 . V_54 , V_133 ,
V_134 [ V_44 ] , V_24 -> V_30 ) ;
if ( V_45 )
goto V_118;
V_44 = ( ( V_51 & V_81 ) >> V_85 ) & 0x03 ;
if ( V_51 & V_80 ) {
if ( V_51 & V_135 ) {
F_5 ( L_36 ) ;
} else {
T_1 V_25 [] = { 0xff , 0x02 } ;
F_5 ( L_37 ) ;
if ( 0 < V_44 && V_44 < 3 ) {
if ( F_17 ( V_24 , & V_25 [ 1 ] ) )
goto V_118;
}
V_45 = F_13 ( V_24 , & V_53 . V_55 , V_25 ,
V_136 [ V_44 ] , NULL ) ;
if ( V_45 )
goto V_118;
}
} else {
F_5 ( L_38 ) ;
V_45 = F_13 ( V_24 , & V_53 . V_55 , V_133 ,
V_134 [ V_44 ] , V_24 -> V_30 ) ;
if ( V_45 )
goto V_118;
}
if ( V_50 & V_74 )
if ( F_21 ( V_24 ) )
goto V_118;
V_53 . V_64 = F_43 ( V_24 -> V_11 ) ;
F_5 ( L_39 ,
F_67 ( V_24 ) , V_24 -> V_11 ) ;
F_5 ( L_40
L_41 , V_53 . V_63 ,
F_25 ( V_53 . V_64 ) , V_53 . V_65 , V_53 . V_66 ) ;
F_7 ( V_29 , L_42 , ( T_1 * ) & V_53 ,
sizeof( V_53 ) ) ;
return F_37 ( V_24 , & V_53 ) ;
V_126:
F_66 ( & V_125 ) ;
V_118:
F_40 ( V_24 ) ;
return - V_31 ;
}
static int F_68 ( struct V_2 * V_3 , void * V_137 )
{
struct V_138 * V_58 = V_137 ;
if ( F_69 ( V_3 ) )
return - V_139 ;
memcpy ( V_3 -> V_67 , V_58 -> V_140 , V_3 -> V_141 ) ;
return 0 ;
}
static int F_70 ( struct V_23 * V_24 )
{
return 21 ;
}
static int
F_71 ( struct V_23 * V_24 , T_1 * V_56 ,
int V_142 , int V_143 , int V_123 )
{
struct V_23 * V_144 ;
int V_145 , V_146 ;
V_145 = ( V_143 == 0 ? V_147 : V_148 ) ;
F_3 ( V_29 , L_43 , V_56 , V_145 ) ;
V_144 = F_72 ( V_145 + V_142 + V_143 + V_149 ) ;
if ( ! V_144 )
return - V_62 ;
V_144 -> V_69 = V_24 -> V_69 ;
V_144 -> V_3 = V_24 -> V_3 ;
memcpy ( F_56 ( V_144 , V_142 ) , V_24 -> V_30 , V_142 ) ;
memcpy ( F_56 ( V_144 , V_145 ) , V_56 , V_145 ) ;
if ( V_143 )
F_73 ( V_24 , V_123 + V_142 ,
F_56 ( V_144 , V_143 ) , V_143 ) ;
F_7 ( V_29 , L_44 , V_144 -> V_30 ,
V_144 -> V_11 ) ;
V_146 = F_74 ( V_144 ) ;
return V_146 ;
}
static int
F_75 ( struct V_23 * V_24 )
{
int V_45 , V_150 , V_151 , V_105 , V_123 = 0 ;
T_1 V_56 [ 5 ] ;
V_150 = F_70 ( V_24 ) ;
V_151 = V_24 -> V_11 - V_150 ;
V_105 = V_152 ++ ;
V_56 [ 0 ] = V_120 | ( ( V_151 >> 8 ) & 0x7 ) ;
V_56 [ 1 ] = V_151 & 0xff ;
V_56 [ 2 ] = V_105 >> 8 ;
V_56 [ 3 ] = V_105 & 0xff ;
V_45 = F_71 ( V_24 , V_56 , V_150 , 0 , 0 ) ;
V_56 [ 0 ] &= ~ V_120 ;
V_56 [ 0 ] |= V_121 ;
while ( ( V_151 - V_123 > 0 ) && ( V_45 >= 0 ) ) {
int V_11 = V_153 ;
V_56 [ 4 ] = V_123 / 8 ;
if ( V_151 - V_123 < V_11 )
V_11 = V_151 - V_123 ;
V_45 = F_71 ( V_24 , V_56 , V_150 ,
V_11 , V_123 ) ;
V_123 += V_11 ;
}
return V_45 ;
}
static T_3 F_76 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
int V_45 = - 1 ;
F_5 ( L_45 ) ;
V_24 -> V_3 = V_1 ( V_3 ) -> V_92 ;
if ( V_24 -> V_3 == NULL ) {
F_5 ( L_46 ) ;
goto error;
}
if ( V_24 -> V_11 <= V_154 - V_149 ) {
V_45 = F_74 ( V_24 ) ;
goto V_155;
}
F_5 ( L_47 ) ;
V_45 = F_75 ( V_24 ) ;
error:
F_51 ( V_24 ) ;
V_155:
if ( V_45 < 0 )
F_5 ( L_48 ) ;
return ( V_45 < 0 ? V_156 : V_157 ) ;
}
static struct V_158 * F_77 ( const struct V_2 * V_3 )
{
struct V_2 * V_92 = V_1 ( V_3 ) -> V_92 ;
return F_78 ( V_92 ) -> F_79 ( V_92 ) ;
}
static T_2 F_80 ( const struct V_2 * V_3 )
{
struct V_2 * V_92 = V_1 ( V_3 ) -> V_92 ;
return F_78 ( V_92 ) -> F_81 ( V_92 ) ;
}
static T_2 F_82 ( const struct V_2 * V_3 )
{
struct V_2 * V_92 = V_1 ( V_3 ) -> V_92 ;
return F_78 ( V_92 ) -> F_83 ( V_92 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
V_3 -> V_141 = V_7 ;
memset ( V_3 -> V_159 , 0xff , V_7 ) ;
V_3 -> type = V_160 ;
V_3 -> V_161 = 2 + 1 + 20 + 14 ;
V_3 -> V_162 = 2 ;
V_3 -> V_163 = 1281 ;
V_3 -> V_164 = 0 ;
V_3 -> V_90 = V_165 | V_166 ;
V_3 -> V_167 = 0 ;
V_3 -> V_168 = & V_169 ;
V_3 -> V_170 = & V_171 ;
V_3 -> V_172 = & V_173 ;
V_3 -> V_174 = V_175 ;
}
static int F_85 ( struct V_176 * V_177 [] , struct V_176 * V_30 [] )
{
if ( V_177 [ V_178 ] ) {
if ( F_86 ( V_177 [ V_178 ] ) != V_7 )
return - V_31 ;
}
return 0 ;
}
static int F_87 ( struct V_23 * V_24 , struct V_2 * V_3 ,
struct V_179 * V_180 , struct V_2 * V_181 )
{
struct V_23 * V_182 ;
if ( ! F_69 ( V_3 ) )
goto V_118;
if ( V_3 -> type != V_160 )
goto V_118;
switch ( V_24 -> V_30 [ 0 ] & 0xe0 ) {
case V_68 :
case V_120 :
case V_121 :
V_182 = F_88 ( V_24 , V_98 ) ;
if ( ! V_182 )
goto V_118;
F_60 ( V_182 ) ;
F_40 ( V_24 ) ;
break;
default:
break;
}
return V_97 ;
V_118:
F_40 ( V_24 ) ;
return V_183 ;
}
static int F_89 ( struct V_184 * V_185 , struct V_2 * V_3 ,
struct V_176 * V_177 [] , struct V_176 * V_30 [] )
{
struct V_2 * V_92 ;
struct V_94 * V_95 ;
F_5 ( L_49 ) ;
if ( ! V_177 [ V_186 ] )
return - V_31 ;
V_92 = F_90 ( V_185 , F_91 ( V_177 [ V_186 ] ) ) ;
if ( ! V_92 )
return - V_187 ;
V_1 ( V_3 ) -> V_92 = V_92 ;
F_92 ( & V_1 ( V_3 ) -> V_188 ) ;
V_95 = F_23 ( sizeof( struct V_94 ) , V_61 ) ;
if ( ! V_95 ) {
F_93 ( V_92 ) ;
V_1 ( V_3 ) -> V_92 = NULL ;
return - V_62 ;
}
V_95 -> V_102 = V_3 ;
F_94 ( & V_1 ( V_3 ) -> V_188 ) ;
F_53 ( & V_95 -> V_106 ) ;
F_59 ( & V_95 -> V_106 , & V_189 ) ;
F_95 ( & V_1 ( V_3 ) -> V_188 ) ;
F_96 ( V_3 ) ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_190 * V_56 )
{
struct V_1 * V_191 = V_1 ( V_3 ) ;
struct V_2 * V_92 = V_191 -> V_92 ;
struct V_94 * V_95 , * V_44 ;
F_98 () ;
F_94 ( & V_1 ( V_3 ) -> V_188 ) ;
F_99 (entry, tmp, &lowpan_devices, list) {
if ( V_95 -> V_102 == V_3 ) {
F_50 ( & V_95 -> V_106 ) ;
F_34 ( V_95 ) ;
}
}
F_95 ( & V_1 ( V_3 ) -> V_188 ) ;
F_100 ( & V_1 ( V_3 ) -> V_188 ) ;
F_101 ( V_3 , V_56 ) ;
F_93 ( V_92 ) ;
}
static inline int T_4 F_102 ( void )
{
return F_103 ( & V_192 ) ;
}
static inline void T_4 F_104 ( void )
{
F_105 ( & V_192 ) ;
}
static int F_106 ( struct V_193 * V_194 ,
unsigned long V_195 ,
void * V_196 )
{
struct V_2 * V_3 = V_196 ;
F_107 ( V_197 ) ;
struct V_94 * V_95 , * V_44 ;
if ( V_3 -> type != V_160 )
goto V_155;
if ( V_195 == V_198 ) {
F_99 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_95 -> V_102 ) -> V_92 == V_3 )
F_97 ( V_95 -> V_102 , & V_197 ) ;
}
F_108 ( & V_197 ) ;
}
V_155:
return V_199 ;
}
static int T_4 F_109 ( void )
{
int V_45 = 0 ;
V_45 = F_102 () ;
if ( V_45 < 0 )
goto V_155;
F_110 ( & V_200 ) ;
V_45 = F_111 ( & V_201 ) ;
if ( V_45 < 0 ) {
F_112 ( & V_200 ) ;
F_104 () ;
}
V_155:
return V_45 ;
}
static void T_5 F_113 ( void )
{
struct V_104 * V_107 , * V_202 ;
F_104 () ;
F_112 ( & V_200 ) ;
F_114 ( & V_201 ) ;
F_61 ( & V_125 ) ;
F_99 (frame, tframe, &lowpan_fragments, list) {
F_65 ( & V_107 -> V_111 ) ;
F_50 ( & V_107 -> V_106 ) ;
F_51 ( V_107 -> V_24 ) ;
F_34 ( V_107 ) ;
}
F_66 ( & V_125 ) ;
}
