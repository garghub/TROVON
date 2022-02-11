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
static int
F_12 ( struct V_22 * V_23 ,
struct V_17 * V_18 ,
const T_1 V_24 ,
const struct V_25 * V_19 )
{
bool V_26 ;
switch ( V_24 ) {
case V_27 :
V_26 = F_13 ( V_23 , V_18 -> V_28 , 16 ) ;
break;
case V_29 :
V_18 -> V_28 [ 0 ] = 0xFE ;
V_18 -> V_28 [ 1 ] = 0x80 ;
V_26 = F_13 ( V_23 , & V_18 -> V_28 [ 8 ] , 8 ) ;
break;
case V_30 :
V_18 -> V_28 [ 0 ] = 0xFE ;
V_18 -> V_28 [ 1 ] = 0x80 ;
V_18 -> V_28 [ 11 ] = 0xFF ;
V_18 -> V_28 [ 12 ] = 0xFE ;
V_26 = F_13 ( V_23 , & V_18 -> V_28 [ 14 ] , 2 ) ;
break;
case V_31 :
V_26 = false ;
switch ( V_19 -> V_32 ) {
case V_33 :
V_18 -> V_28 [ 0 ] = 0xFE ;
V_18 -> V_28 [ 1 ] = 0x80 ;
memcpy ( & V_18 -> V_28 [ 8 ] , V_19 -> V_34 ,
V_7 ) ;
V_18 -> V_28 [ 8 ] ^= 0x02 ;
break;
case V_35 :
V_18 -> V_28 [ 0 ] = 0xFE ;
V_18 -> V_28 [ 1 ] = 0x80 ;
V_18 -> V_28 [ 11 ] = 0xFF ;
V_18 -> V_28 [ 12 ] = 0xFE ;
V_18 -> V_21 [ 7 ] = F_14 ( V_19 -> V_36 ) ;
break;
default:
F_5 ( L_5 ) ;
return - V_37 ;
}
break;
default:
F_5 ( L_6 , V_24 ) ;
return - V_37 ;
}
if ( V_26 ) {
F_5 ( L_7 ) ;
return - V_38 ;
}
F_3 ( NULL , L_8 ,
V_18 -> V_28 , 16 ) ;
return 0 ;
}
static int
F_15 ( struct V_22 * V_23 ,
struct V_17 * V_18 ,
const T_1 V_39 )
{
switch ( V_39 ) {
case V_27 :
break;
case V_29 :
case V_30 :
case V_31 :
F_16 ( V_23 -> V_3 , L_9 , V_39 ) ;
return - V_37 ;
default:
F_5 ( L_10 , V_39 ) ;
return - V_37 ;
}
F_3 ( NULL ,
L_11 ,
V_18 -> V_28 , 16 ) ;
return 0 ;
}
static int
F_17 ( struct V_22 * V_23 ,
struct V_17 * V_18 ,
const T_1 V_40 )
{
bool V_26 ;
switch ( V_40 ) {
case V_41 :
V_26 = F_13 ( V_23 , V_18 -> V_28 , 16 ) ;
break;
case V_42 :
V_18 -> V_28 [ 0 ] = 0xFF ;
V_26 = F_13 ( V_23 , & V_18 -> V_28 [ 1 ] , 1 ) ;
V_26 |= F_13 ( V_23 , & V_18 -> V_28 [ 11 ] , 5 ) ;
break;
case V_43 :
V_18 -> V_28 [ 0 ] = 0xFF ;
V_26 = F_13 ( V_23 , & V_18 -> V_28 [ 1 ] , 1 ) ;
V_26 |= F_13 ( V_23 , & V_18 -> V_28 [ 13 ] , 3 ) ;
break;
case V_44 :
V_18 -> V_28 [ 0 ] = 0xFF ;
V_18 -> V_28 [ 1 ] = 0x02 ;
V_26 = F_13 ( V_23 , & V_18 -> V_28 [ 15 ] , 1 ) ;
break;
default:
F_5 ( L_12 , V_40 ) ;
return - V_37 ;
}
if ( V_26 ) {
F_5 ( L_7 ) ;
return - V_38 ;
}
F_3 ( NULL , L_13 ,
V_18 -> V_28 , 16 ) ;
return 0 ;
}
static void
F_18 ( T_1 * * V_15 , struct V_22 * V_23 )
{
struct V_45 * V_46 = F_19 ( V_23 ) ;
if ( ( ( V_46 -> V_47 & V_48 ) ==
V_49 ) &&
( ( V_46 -> V_5 & V_48 ) ==
V_49 ) ) {
F_5 ( L_14 ) ;
* * V_15 = V_50 ;
* * ( V_15 + 1 ) =
( T_1 ) ( ( V_46 -> V_5 - V_49 ) +
( ( V_46 -> V_47 & V_49 ) << 4 ) ) ;
* V_15 += 2 ;
} else if ( ( V_46 -> V_5 & V_51 ) ==
V_52 ) {
F_5 ( L_15 ) ;
* * V_15 = V_53 ;
memcpy ( * V_15 + 1 , & V_46 -> V_47 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_46 -> V_5 - V_52 ) ;
* V_15 += 4 ;
} else if ( ( V_46 -> V_47 & V_51 ) ==
V_52 ) {
F_5 ( L_16 ) ;
* * V_15 = V_54 ;
memcpy ( * V_15 + 1 , & V_46 -> V_5 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_46 -> V_47 - V_52 ) ;
* V_15 += 4 ;
} else {
F_5 ( L_17 ) ;
* * V_15 = V_55 ;
memcpy ( * V_15 + 1 , & V_46 -> V_47 , 2 ) ;
memcpy ( * V_15 + 3 , & V_46 -> V_5 , 2 ) ;
* V_15 += 5 ;
}
memcpy ( * V_15 , & V_46 -> V_56 , 2 ) ;
* V_15 += 2 ;
F_20 ( V_23 , sizeof( struct V_45 ) ) ;
}
static inline int F_21 ( struct V_22 * V_23 , T_1 * V_20 )
{
if ( F_22 ( ! F_23 ( V_23 , 1 ) ) )
return - V_37 ;
* V_20 = V_23 -> V_57 [ 0 ] ;
F_20 ( V_23 , 1 ) ;
return 0 ;
}
static inline int F_24 ( struct V_22 * V_23 , T_2 * V_20 )
{
if ( F_22 ( ! F_23 ( V_23 , 2 ) ) )
return - V_37 ;
* V_20 = ( V_23 -> V_57 [ 0 ] << 8 ) | V_23 -> V_57 [ 1 ] ;
F_20 ( V_23 , 2 ) ;
return 0 ;
}
static int
F_25 ( struct V_22 * V_23 , struct V_45 * V_46 )
{
T_1 V_58 ;
if ( ! V_46 )
goto V_59;
if ( F_21 ( V_23 , & V_58 ) )
goto V_59;
if ( ( V_58 & V_60 ) == V_61 ) {
F_5 ( L_18 ) ;
switch ( V_58 & V_50 ) {
case V_55 :
memcpy ( & V_46 -> V_47 , & V_23 -> V_57 [ 0 ] , 2 ) ;
memcpy ( & V_46 -> V_5 , & V_23 -> V_57 [ 2 ] , 2 ) ;
F_20 ( V_23 , 4 ) ;
break;
case V_53 :
memcpy ( & V_46 -> V_47 , & V_23 -> V_57 [ 0 ] , 2 ) ;
V_46 -> V_5 =
V_23 -> V_57 [ 2 ] + V_52 ;
F_20 ( V_23 , 3 ) ;
break;
case V_54 :
V_46 -> V_47 = V_23 -> V_57 [ 0 ] + V_52 ;
memcpy ( & V_46 -> V_5 , & V_23 -> V_57 [ 1 ] , 2 ) ;
F_20 ( V_23 , 3 ) ;
break;
case V_50 :
V_46 -> V_47 =
V_49 + ( V_23 -> V_57 [ 0 ] >> 4 ) ;
V_46 -> V_5 =
V_49 + ( V_23 -> V_57 [ 0 ] & 0x0f ) ;
F_20 ( V_23 , 1 ) ;
break;
default:
F_5 ( L_19 ) ;
goto V_59;
}
F_5 ( L_20 ,
V_46 -> V_47 , V_46 -> V_5 ) ;
memcpy ( & V_46 -> V_56 , & V_23 -> V_57 [ 0 ] , 2 ) ;
F_20 ( V_23 , 2 ) ;
V_46 -> V_11 = F_14 ( V_23 -> V_11 + sizeof( struct V_45 ) ) ;
F_5 ( L_21 , V_46 -> V_11 ) ;
} else {
F_5 ( L_22 ) ;
goto V_59;
}
return 0 ;
V_59:
return - V_37 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_62 ,
const void * V_63 , unsigned int V_11 )
{
T_1 V_58 , V_64 , V_65 , * V_15 ;
struct V_66 * V_67 ;
const T_1 * V_68 = V_63 ;
const T_1 * V_69 = V_62 ;
T_1 V_70 [ 100 ] ;
struct V_25 V_71 , V_72 ;
if ( type != V_73 )
return 0 ;
V_67 = F_27 ( V_23 ) ;
V_15 = V_70 + 2 ;
F_5 ( L_23
L_24 , V_67 -> V_74 ,
F_28 ( V_67 -> V_75 ) , V_67 -> V_76 , V_67 -> V_77 ) ;
F_7 ( V_78 , L_25 ,
F_29 ( V_23 ) , sizeof( struct V_66 ) ) ;
if ( ! V_68 )
V_68 = V_3 -> V_79 ;
F_3 ( V_78 , L_26 , ( unsigned char * ) V_68 , 8 ) ;
V_64 = V_80 ;
V_65 = 0 ;
F_3 ( V_78 , L_27 , ( unsigned char * ) V_69 , 8 ) ;
V_58 = ( V_67 -> V_81 << 4 ) | ( V_67 -> V_82 [ 0 ] >> 4 ) ;
V_58 = ( ( V_58 & 0x03 ) << 6 ) | ( V_58 >> 2 ) ;
if ( ( ( V_67 -> V_82 [ 0 ] & 0x0F ) == 0 ) &&
( V_67 -> V_82 [ 1 ] == 0 ) && ( V_67 -> V_82 [ 2 ] == 0 ) ) {
V_64 |= V_83 ;
if ( ( V_67 -> V_81 == 0 ) &&
( ( V_67 -> V_82 [ 0 ] & 0xF0 ) == 0 ) ) {
V_64 |= V_84 ;
} else {
* V_15 = V_58 ;
V_15 += 1 ;
}
} else {
if ( ( V_67 -> V_81 == 0 ) &&
( ( V_67 -> V_82 [ 0 ] & 0xF0 ) == 0 ) ) {
V_64 |= V_84 ;
* V_15 = ( V_58 & 0xc0 ) | ( V_67 -> V_82 [ 0 ] & 0x0F ) ;
memcpy ( V_15 + 1 , & V_67 -> V_82 [ 1 ] , 2 ) ;
V_15 += 3 ;
} else {
memcpy ( V_15 , V_67 , 4 ) ;
* V_15 = V_58 ;
V_15 += 4 ;
}
}
if ( V_67 -> V_76 == V_85 )
V_64 |= V_86 ;
if ( ( V_64 & V_86 ) == 0 ) {
* V_15 = V_67 -> V_76 ;
V_15 += 1 ;
}
switch ( V_67 -> V_77 ) {
case 1 :
V_64 |= V_87 ;
break;
case 64 :
V_64 |= V_88 ;
break;
case 255 :
V_64 |= V_89 ;
break;
default:
* V_15 = V_67 -> V_77 ;
V_15 += 1 ;
break;
}
if ( F_30 ( & V_67 -> V_68 ) ) {
F_5 ( L_28 ) ;
V_65 |= V_90 ;
} else if ( F_31 ( & V_67 -> V_68 ) ) {
F_5 ( L_29 ) ;
V_65 |= F_8 ( & V_15 ,
V_91 , & V_67 -> V_68 , V_68 ) ;
} else {
F_5 ( L_30 ) ;
memcpy ( V_15 , & V_67 -> V_68 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
if ( F_32 ( & V_67 -> V_69 ) ) {
F_5 ( L_31 ) ;
V_65 |= V_92 ;
if ( F_33 ( & V_67 -> V_69 ) ) {
F_5 ( L_32 ) ;
V_65 |= V_44 ;
* V_15 = V_67 -> V_69 . V_28 [ 15 ] ;
V_15 += 1 ;
} else if ( F_34 ( & V_67 -> V_69 ) ) {
F_5 ( L_33 ) ;
V_65 |= V_43 ;
* V_15 = V_67 -> V_69 . V_28 [ 1 ] ;
memcpy ( V_15 + 1 , & V_67 -> V_69 . V_28 [ 13 ] , 3 ) ;
V_15 += 4 ;
} else if ( F_35 ( & V_67 -> V_69 ) ) {
F_5 ( L_34 ) ;
V_65 |= V_42 ;
* V_15 = V_67 -> V_69 . V_28 [ 1 ] ;
memcpy ( V_15 + 1 , & V_67 -> V_69 . V_28 [ 11 ] , 5 ) ;
V_15 += 6 ;
} else {
F_5 ( L_35 ) ;
V_65 |= V_41 ;
memcpy ( V_15 , & V_67 -> V_69 . V_28 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
} else {
if ( F_31 ( & V_67 -> V_69 ) ) {
F_5 ( L_36 ) ;
V_65 |= F_8 ( & V_15 ,
V_93 , & V_67 -> V_69 , V_69 ) ;
} else {
F_5 ( L_37 ) ;
memcpy ( V_15 , & V_67 -> V_69 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
}
if ( V_67 -> V_76 == V_85 )
F_18 ( & V_15 , V_23 ) ;
V_70 [ 0 ] = V_64 ;
V_70 [ 1 ] = V_65 ;
F_20 ( V_23 , sizeof( struct V_66 ) ) ;
F_36 ( V_23 ) ;
memcpy ( F_37 ( V_23 , V_15 - V_70 ) , V_70 , V_15 - V_70 ) ;
F_38 ( V_23 ) ;
F_7 ( V_78 , L_38 , V_23 -> V_57 ,
V_23 -> V_11 ) ;
{
F_39 ( V_23 ) -> V_94 = V_95 ;
F_39 ( V_23 ) -> V_96 = F_40 ( V_3 ) -> F_41 ( V_3 ) ;
V_71 . V_32 = V_33 ;
V_71 . V_97 = F_40 ( V_3 ) -> F_42 ( V_3 ) ;
memcpy ( & ( V_71 . V_34 ) , V_68 , 8 ) ;
V_72 . V_97 = F_40 ( V_3 ) -> F_42 ( V_3 ) ;
if ( F_43 ( V_69 ) ) {
V_72 . V_32 = V_35 ;
V_72 . V_36 = V_98 ;
} else {
V_72 . V_32 = V_33 ;
memcpy ( & ( V_72 . V_34 ) , V_69 , V_7 ) ;
F_39 ( V_23 ) -> V_94 |= V_99 ;
}
return F_44 ( V_23 , V_1 ( V_3 ) -> V_100 ,
type , ( void * ) & V_72 , ( void * ) & V_71 , V_23 -> V_11 ) ;
}
}
static int F_45 ( struct V_22 * V_23 )
{
struct V_101 * V_102 ;
struct V_22 * V_103 ;
int V_104 = V_105 ;
F_46 () ;
F_47 (entry, &lowpan_devices, list)
if ( V_1 ( V_102 -> V_106 ) -> V_100 == V_23 -> V_3 ) {
V_103 = F_48 ( V_23 , V_107 ) ;
if ( ! V_103 ) {
V_104 = - V_108 ;
break;
}
V_103 -> V_3 = V_102 -> V_106 ;
V_104 = F_49 ( V_103 ) ;
}
F_50 () ;
return V_104 ;
}
static int F_51 ( struct V_22 * V_23 , struct V_66 * V_67 )
{
struct V_22 * V_109 ;
int V_104 = V_105 ;
V_109 = F_52 ( V_23 , sizeof( struct V_66 ) , F_53 ( V_23 ) ,
V_107 ) ;
F_54 ( V_23 ) ;
if ( ! V_109 )
return - V_108 ;
F_37 ( V_109 , sizeof( struct V_66 ) ) ;
F_55 ( V_109 , V_67 , sizeof( struct V_66 ) ) ;
V_109 -> V_110 = F_14 ( V_73 ) ;
V_109 -> V_111 = V_112 ;
V_104 = F_45 ( V_109 ) ;
F_54 ( V_109 ) ;
return V_104 ;
}
static void F_56 ( unsigned long V_113 )
{
struct V_114 * V_102 = (struct V_114 * ) V_113 ;
F_5 ( L_39 , V_102 -> V_115 ) ;
F_57 ( & V_102 -> V_116 ) ;
F_58 ( V_102 -> V_23 ) ;
F_59 ( V_102 ) ;
}
static struct V_114 *
F_60 ( struct V_22 * V_23 , T_2 V_11 , T_2 V_115 )
{
struct V_114 * V_117 ;
V_117 = F_61 ( sizeof( struct V_114 ) ,
V_107 ) ;
if ( ! V_117 )
goto V_118;
F_62 ( & V_117 -> V_116 ) ;
V_117 -> V_119 = V_11 ;
V_117 -> V_115 = V_115 ;
V_117 -> V_23 = F_63 ( V_23 -> V_3 , V_117 -> V_119 +
sizeof( struct V_66 ) ) ;
if ( ! V_117 -> V_23 )
goto V_120;
V_117 -> V_23 -> V_81 = V_23 -> V_81 ;
F_64 ( V_117 -> V_23 , sizeof( struct V_66 ) ) ;
F_65 ( V_117 -> V_23 , V_117 -> V_119 ) ;
memcpy ( V_117 -> V_23 -> V_121 , V_23 -> V_121 , sizeof( V_23 -> V_121 ) ) ;
F_66 ( & V_117 -> V_122 ) ;
V_117 -> V_122 . V_123 = V_124 + V_125 ;
V_117 -> V_122 . V_57 = ( unsigned long ) V_117 ;
V_117 -> V_122 . V_126 = F_56 ;
F_67 ( & V_117 -> V_122 ) ;
F_68 ( & V_117 -> V_116 , & V_127 ) ;
return V_117 ;
V_120:
F_59 ( V_117 ) ;
V_118:
return NULL ;
}
static int
F_69 ( struct V_22 * V_23 )
{
struct V_66 V_67 = {} ;
T_1 V_58 , V_64 , V_65 , V_128 = 0 ;
const struct V_25 * V_63 , * V_62 ;
int V_59 ;
F_7 ( V_78 , L_38 , V_23 -> V_57 ,
V_23 -> V_11 ) ;
if ( V_23 -> V_11 < 2 )
goto V_129;
if ( F_21 ( V_23 , & V_64 ) )
goto V_129;
switch ( V_64 & V_130 ) {
case V_131 :
case V_132 :
{
struct V_114 * V_117 ;
T_1 V_133 , V_134 = 0 ;
T_2 V_11 , V_115 ;
bool V_135 = false ;
if ( F_21 ( V_23 , & V_133 ) ||
F_24 ( V_23 , & V_115 ) )
goto V_129;
V_11 = ( ( V_64 & 7 ) << 8 ) | V_133 ;
if ( ( V_64 & V_130 ) == V_131 ) {
F_5 ( L_40
L_41 ,
V_78 , V_115 , V_11 ) ;
} else {
if ( F_21 ( V_23 , & V_134 ) )
goto V_136;
F_5 ( L_42
L_43
L_44 , V_78 , V_115 , V_11 , V_134 * 8 ) ;
}
F_70 ( & V_137 ) ;
F_71 (frame, &lowpan_fragments, list)
if ( V_117 -> V_115 == V_115 ) {
V_135 = true ;
break;
}
if ( ! V_135 ) {
F_5 ( L_45
L_46 , V_78 , V_115 ) ;
V_117 = F_60 ( V_23 , V_11 , V_115 ) ;
if ( ! V_117 )
goto V_136;
}
if ( F_72 ( ( V_134 * 8 + V_23 -> V_11 ) <= V_117 -> V_119 ) )
F_73 ( V_117 -> V_23 , V_134 * 8 ,
V_23 -> V_57 , V_23 -> V_11 ) ;
else
goto V_136;
V_117 -> V_138 += V_23 -> V_11 ;
if ( ( V_117 -> V_138 == V_117 -> V_119 ) &&
V_117 -> V_122 . V_123 > V_124 ) {
F_74 ( & V_117 -> V_122 ) ;
F_57 ( & V_117 -> V_116 ) ;
F_75 ( & V_137 ) ;
F_5 ( L_47
L_48 , V_78 , V_115 ) ;
F_58 ( V_23 ) ;
V_23 = V_117 -> V_23 ;
F_59 ( V_117 ) ;
if ( F_21 ( V_23 , & V_64 ) )
goto V_129;
break;
}
F_75 ( & V_137 ) ;
return F_54 ( V_23 ) , 0 ;
}
default:
break;
}
if ( F_21 ( V_23 , & V_65 ) )
goto V_129;
V_63 = & F_39 ( V_23 ) -> V_71 ;
V_62 = & F_39 ( V_23 ) -> V_72 ;
F_5 ( L_49 , V_64 , V_65 ) ;
if ( V_65 & V_139 ) {
F_5 ( L_50 ) ;
if ( F_21 ( V_23 , & V_128 ) )
goto V_129;
}
V_67 . V_74 = 6 ;
switch ( ( V_64 & V_140 ) >> 3 ) {
case 0 :
if ( F_21 ( V_23 , & V_58 ) )
goto V_129;
memcpy ( & V_67 . V_82 , & V_23 -> V_57 [ 0 ] , 3 ) ;
F_20 ( V_23 , 3 ) ;
V_67 . V_81 = ( ( V_58 >> 2 ) & 0x0f ) ;
V_67 . V_82 [ 0 ] = ( ( V_58 >> 2 ) & 0x30 ) | ( V_58 << 6 ) |
( V_67 . V_82 [ 0 ] & 0x0f ) ;
break;
case 2 :
if ( F_21 ( V_23 , & V_58 ) )
goto V_129;
V_67 . V_81 = ( ( V_58 >> 2 ) & 0x0f ) ;
V_67 . V_82 [ 0 ] = ( ( V_58 << 6 ) & 0xC0 ) | ( ( V_58 >> 2 ) & 0x30 ) ;
break;
case 1 :
if ( F_21 ( V_23 , & V_58 ) )
goto V_129;
V_67 . V_82 [ 0 ] = ( V_23 -> V_57 [ 0 ] & 0x0F ) | ( ( V_58 >> 2 ) & 0x30 ) ;
memcpy ( & V_67 . V_82 [ 1 ] , & V_23 -> V_57 [ 0 ] , 2 ) ;
F_20 ( V_23 , 2 ) ;
break;
case 3 :
break;
default:
break;
}
if ( ( V_64 & V_86 ) == 0 ) {
if ( F_21 ( V_23 , & ( V_67 . V_76 ) ) )
goto V_129;
F_5 ( L_51 ,
V_67 . V_76 ) ;
}
if ( ( V_64 & 0x03 ) != V_141 )
V_67 . V_77 = V_142 [ V_64 & 0x03 ] ;
else {
if ( F_21 ( V_23 , & ( V_67 . V_77 ) ) )
goto V_129;
}
V_58 = ( ( V_65 & V_143 ) >> V_91 ) & 0x03 ;
if ( V_65 & V_90 ) {
F_5 ( L_52 ) ;
V_59 = F_15 (
V_23 , & V_67 . V_68 , V_58 ) ;
} else {
F_5 ( L_53 ) ;
V_59 = F_12 ( V_23 , & V_67 . V_68 , V_58 , V_63 ) ;
}
if ( V_59 )
goto V_129;
V_58 = ( ( V_65 & V_44 ) >> V_93 ) & 0x03 ;
if ( V_65 & V_92 ) {
if ( V_65 & V_144 ) {
F_5 ( L_54 ) ;
} else {
V_59 = F_17 (
V_23 , & V_67 . V_69 , V_58 ) ;
if ( V_59 )
goto V_129;
}
} else {
F_5 ( L_55 ) ;
V_59 = F_12 ( V_23 , & V_67 . V_69 , V_58 , V_62 ) ;
if ( V_59 )
goto V_129;
}
if ( V_64 & V_86 ) {
struct V_45 V_46 ;
struct V_22 * V_109 ;
if ( F_25 ( V_23 , & V_46 ) )
goto V_129;
V_109 = F_52 ( V_23 , sizeof( struct V_45 ) ,
F_53 ( V_23 ) , V_107 ) ;
F_54 ( V_23 ) ;
if ( ! V_109 )
return - V_108 ;
V_23 = V_109 ;
F_37 ( V_23 , sizeof( struct V_45 ) ) ;
F_55 ( V_23 , & V_46 , sizeof( struct V_45 ) ) ;
F_7 ( V_78 , L_56 ,
( T_1 * ) & V_46 , sizeof( V_46 ) ) ;
V_67 . V_76 = V_85 ;
}
V_67 . V_75 = F_14 ( V_23 -> V_11 ) ;
F_5 ( L_57 ,
F_76 ( V_23 ) , V_23 -> V_11 ) ;
F_5 ( L_58
L_59 , V_67 . V_74 ,
F_28 ( V_67 . V_75 ) , V_67 . V_76 , V_67 . V_77 ) ;
F_7 ( V_78 , L_60 , ( T_1 * ) & V_67 ,
sizeof( V_67 ) ) ;
return F_51 ( V_23 , & V_67 ) ;
V_136:
F_75 ( & V_137 ) ;
V_129:
F_54 ( V_23 ) ;
return - V_37 ;
}
static int F_77 ( struct V_2 * V_3 , void * V_145 )
{
struct V_146 * V_71 = V_145 ;
if ( F_78 ( V_3 ) )
return - V_147 ;
memcpy ( V_3 -> V_79 , V_71 -> V_148 , V_3 -> V_149 ) ;
return 0 ;
}
static int
F_79 ( struct V_22 * V_23 , T_1 * V_70 ,
int V_150 , int V_151 , int V_134 , int type )
{
struct V_22 * V_152 ;
int V_153 ;
V_153 = ( type == V_131 ) ?
V_154 : V_155 ;
F_3 ( V_78 , L_61 , V_70 , V_153 ) ;
V_152 = F_80 ( V_23 -> V_3 ,
V_153 + V_150 + V_151 + V_156 ) ;
if ( ! V_152 )
return - V_108 ;
V_152 -> V_81 = V_23 -> V_81 ;
F_65 ( V_152 , V_150 ) ;
F_55 ( V_152 , F_81 ( V_23 ) , V_150 ) ;
F_65 ( V_152 , V_153 ) ;
F_73 ( V_152 , V_150 , V_70 , V_153 ) ;
F_65 ( V_152 , V_151 ) ;
F_73 ( V_152 , V_150 + V_153 ,
F_29 ( V_23 ) + V_134 , V_151 ) ;
F_7 ( V_78 , L_62 , V_152 -> V_57 ,
V_152 -> V_11 ) ;
return F_82 ( V_152 ) ;
}
static int
F_83 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
int V_59 , V_157 , V_158 , V_115 , V_134 = 0 ;
T_1 V_70 [ 5 ] ;
V_157 = V_23 -> V_159 ;
V_158 = V_23 -> V_11 - V_157 ;
V_115 = V_1 ( V_3 ) -> V_160 ++ ;
V_70 [ 0 ] = V_131 | ( ( V_158 >> 8 ) & 0x7 ) ;
V_70 [ 1 ] = V_158 & 0xff ;
V_70 [ 2 ] = V_115 >> 8 ;
V_70 [ 3 ] = V_115 & 0xff ;
V_59 = F_79 ( V_23 , V_70 , V_157 , V_161 ,
0 , V_131 ) ;
if ( V_59 ) {
F_5 ( L_63 ,
V_78 , V_115 ) ;
goto exit;
}
V_134 = V_161 ;
V_70 [ 0 ] &= ~ V_131 ;
V_70 [ 0 ] |= V_132 ;
while ( V_158 - V_134 > 0 ) {
int V_11 = V_161 ;
V_70 [ 4 ] = V_134 / 8 ;
if ( V_158 - V_134 < V_11 )
V_11 = V_158 - V_134 ;
V_59 = F_79 ( V_23 , V_70 , V_157 ,
V_11 , V_134 , V_132 ) ;
if ( V_59 ) {
F_5 ( L_64
L_65 , V_78 , V_115 , V_134 ) ;
goto exit;
}
V_134 += V_11 ;
}
exit:
return V_59 ;
}
static T_3 F_84 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
int V_59 = - 1 ;
F_5 ( L_66 ) ;
V_23 -> V_3 = V_1 ( V_3 ) -> V_100 ;
if ( V_23 -> V_3 == NULL ) {
F_5 ( L_67 ) ;
goto error;
}
if ( V_23 -> V_11 <= V_162 - V_156 ) {
V_59 = F_82 ( V_23 ) ;
goto V_163;
}
F_5 ( L_68 ) ;
V_59 = F_83 ( V_23 , V_3 ) ;
error:
F_58 ( V_23 ) ;
V_163:
if ( V_59 )
F_5 ( L_69 ) ;
return ( V_59 < 0 ) ? V_164 : V_59 ;
}
static struct V_165 * F_85 ( const struct V_2 * V_3 )
{
struct V_2 * V_100 = V_1 ( V_3 ) -> V_100 ;
return F_40 ( V_100 ) -> F_86 ( V_100 ) ;
}
static T_2 F_87 ( const struct V_2 * V_3 )
{
struct V_2 * V_100 = V_1 ( V_3 ) -> V_100 ;
return F_40 ( V_100 ) -> F_42 ( V_100 ) ;
}
static T_2 F_88 ( const struct V_2 * V_3 )
{
struct V_2 * V_100 = V_1 ( V_3 ) -> V_100 ;
return F_40 ( V_100 ) -> F_89 ( V_100 ) ;
}
static T_1 F_90 ( const struct V_2 * V_3 )
{
struct V_2 * V_100 = V_1 ( V_3 ) -> V_100 ;
return F_40 ( V_100 ) -> F_41 ( V_100 ) ;
}
static void F_91 ( struct V_2 * V_3 )
{
V_3 -> V_149 = V_7 ;
memset ( V_3 -> V_166 , 0xff , V_7 ) ;
V_3 -> type = V_167 ;
V_3 -> V_168 = 2 + 1 + 20 + 14 ;
V_3 -> V_169 = 2 ;
V_3 -> V_170 = 1281 ;
V_3 -> V_171 = 0 ;
V_3 -> V_94 = V_172 | V_173 ;
V_3 -> V_174 = 0 ;
V_3 -> V_175 = & V_176 ;
V_3 -> V_177 = & V_178 ;
V_3 -> V_179 = & V_180 ;
V_3 -> V_181 = V_182 ;
}
static int F_92 ( struct V_183 * V_184 [] , struct V_183 * V_57 [] )
{
if ( V_184 [ V_185 ] ) {
if ( F_93 ( V_184 [ V_185 ] ) != V_7 )
return - V_37 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_23 , struct V_2 * V_3 ,
struct V_186 * V_187 , struct V_2 * V_188 )
{
struct V_22 * V_189 ;
if ( ! F_78 ( V_3 ) )
goto V_129;
if ( V_3 -> type != V_167 )
goto V_129;
if ( V_23 -> V_57 [ 0 ] == V_190 ) {
V_189 = F_52 ( V_23 , V_191 - 1 ,
F_53 ( V_23 ) , V_107 ) ;
if ( ! V_189 )
goto V_129;
V_189 -> V_110 = F_14 ( V_73 ) ;
V_189 -> V_111 = V_112 ;
F_20 ( V_189 , 1 ) ;
F_45 ( V_189 ) ;
F_54 ( V_189 ) ;
F_54 ( V_23 ) ;
} else {
switch ( V_23 -> V_57 [ 0 ] & 0xe0 ) {
case V_80 :
case V_131 :
case V_132 :
V_189 = F_95 ( V_23 , V_107 ) ;
if ( ! V_189 )
goto V_129;
F_69 ( V_189 ) ;
F_54 ( V_23 ) ;
break;
default:
break;
}
}
return V_105 ;
V_129:
F_54 ( V_23 ) ;
return V_192 ;
}
static int F_96 ( struct V_193 * V_194 , struct V_2 * V_3 ,
struct V_183 * V_184 [] , struct V_183 * V_57 [] )
{
struct V_2 * V_100 ;
struct V_101 * V_102 ;
F_5 ( L_70 ) ;
if ( ! V_184 [ V_195 ] )
return - V_37 ;
V_100 = F_97 ( V_194 , F_98 ( V_184 [ V_195 ] ) ) ;
if ( ! V_100 )
return - V_196 ;
if ( V_100 -> type != V_167 ) {
F_99 ( V_100 ) ;
return - V_37 ;
}
V_1 ( V_3 ) -> V_100 = V_100 ;
V_1 ( V_3 ) -> V_160 = 0 ;
F_100 ( & V_1 ( V_3 ) -> V_197 ) ;
V_102 = F_61 ( sizeof( struct V_101 ) , V_198 ) ;
if ( ! V_102 ) {
F_99 ( V_100 ) ;
V_1 ( V_3 ) -> V_100 = NULL ;
return - V_108 ;
}
V_102 -> V_106 = V_3 ;
memcpy ( V_3 -> V_79 , V_100 -> V_79 , V_7 ) ;
F_101 ( & V_1 ( V_3 ) -> V_197 ) ;
F_62 ( & V_102 -> V_116 ) ;
F_68 ( & V_102 -> V_116 , & V_199 ) ;
F_102 ( & V_1 ( V_3 ) -> V_197 ) ;
F_103 ( V_3 ) ;
return 0 ;
}
static void F_104 ( struct V_2 * V_3 , struct V_200 * V_70 )
{
struct V_1 * V_201 = V_1 ( V_3 ) ;
struct V_2 * V_100 = V_201 -> V_100 ;
struct V_101 * V_102 , * V_58 ;
F_105 () ;
F_101 ( & V_1 ( V_3 ) -> V_197 ) ;
F_106 (entry, tmp, &lowpan_devices, list) {
if ( V_102 -> V_106 == V_3 ) {
F_57 ( & V_102 -> V_116 ) ;
F_59 ( V_102 ) ;
}
}
F_102 ( & V_1 ( V_3 ) -> V_197 ) ;
F_107 ( & V_1 ( V_3 ) -> V_197 ) ;
F_108 ( V_3 , V_70 ) ;
F_99 ( V_100 ) ;
}
static inline int T_4 F_109 ( void )
{
return F_110 ( & V_202 ) ;
}
static inline void F_111 ( void )
{
F_112 ( & V_202 ) ;
}
static int F_113 ( struct V_203 * V_204 ,
unsigned long V_205 , void * V_206 )
{
struct V_2 * V_3 = F_114 ( V_206 ) ;
F_115 ( V_207 ) ;
struct V_101 * V_102 , * V_58 ;
if ( V_3 -> type != V_167 )
goto V_163;
if ( V_205 == V_208 ) {
F_106 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_102 -> V_106 ) -> V_100 == V_3 )
F_104 ( V_102 -> V_106 , & V_207 ) ;
}
F_116 ( & V_207 ) ;
}
V_163:
return V_209 ;
}
static int T_4 F_117 ( void )
{
int V_59 = 0 ;
V_59 = F_109 () ;
if ( V_59 < 0 )
goto V_163;
F_118 ( & V_210 ) ;
V_59 = F_119 ( & V_211 ) ;
if ( V_59 < 0 ) {
F_120 ( & V_210 ) ;
F_111 () ;
}
V_163:
return V_59 ;
}
static void T_5 F_121 ( void )
{
struct V_114 * V_117 , * V_212 ;
F_111 () ;
F_120 ( & V_210 ) ;
F_122 ( & V_211 ) ;
F_70 ( & V_137 ) ;
F_106 (frame, tframe, &lowpan_fragments, list) {
F_74 ( & V_117 -> V_122 ) ;
F_57 ( & V_117 -> V_116 ) ;
F_58 ( V_117 -> V_23 ) ;
F_59 ( V_117 ) ;
}
F_75 ( & V_137 ) ;
}
