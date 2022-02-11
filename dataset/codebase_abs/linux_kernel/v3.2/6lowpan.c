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
memcpy ( & V_18 -> V_22 [ 8 ] , V_19 , V_23 ) ;
V_18 -> V_22 [ 8 ] ^= 0x02 ;
}
static int
F_13 ( struct V_24 * V_25 , struct V_17 * V_18 ,
T_1 const * V_26 , T_1 V_27 , unsigned char * V_19 )
{
T_1 V_28 = V_27 >> 4 ;
T_1 V_29 = V_27 & 0x0f ;
V_28 = ( V_28 == 15 ? 16 : V_28 ) ;
V_29 = ( V_29 == 15 ? 16 : V_29 ) ;
if ( V_19 )
F_3 ( V_30 , L_5 ,
V_19 , V_23 ) ;
if ( V_28 > 0 )
memcpy ( V_18 , V_26 , V_28 ) ;
if ( V_28 + V_29 < 16 )
memset ( & V_18 -> V_22 [ V_28 ] , 0 ,
16 - ( V_28 + V_29 ) ) ;
if ( V_29 > 0 ) {
memcpy ( & V_18 -> V_22 [ 16 - V_29 ] , V_25 -> V_31 , V_29 ) ;
F_14 ( V_25 , V_29 ) ;
} else if ( V_28 > 0 ) {
if ( V_19 == NULL )
return - V_32 ;
F_12 ( V_18 , V_19 ) ;
}
F_5 ( L_6 , V_30 , V_28 ,
V_29 ) ;
F_3 ( NULL , NULL , V_18 -> V_22 , 16 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_24 * V_25 )
{
T_1 V_33 ;
V_33 = V_25 -> V_31 [ 0 ] ;
F_14 ( V_25 , 1 ) ;
return V_33 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_34 ,
const void * V_35 , unsigned V_11 )
{
T_1 V_36 , V_37 , V_38 , * V_15 ;
struct V_39 * V_40 ;
const T_1 * V_41 = V_35 ;
const T_1 * V_42 = V_34 ;
T_1 * V_43 ;
struct V_44 V_45 , V_46 ;
if ( type != V_47 )
return 0 ;
V_43 = F_17 ( 100 , V_48 ) ;
if ( V_43 == NULL )
return - V_49 ;
V_40 = F_18 ( V_25 ) ;
V_15 = V_43 + 2 ;
F_5 ( L_7
L_8 , V_30 ,
V_40 -> V_50 , F_19 ( V_40 -> V_51 ) , V_40 -> V_52 ,
V_40 -> V_53 ) ;
F_7 ( V_30 , L_9 ,
F_20 ( V_25 ) , sizeof( struct V_39 ) ) ;
if ( ! V_41 )
V_41 = V_3 -> V_54 ;
F_3 ( V_30 , L_10 , ( unsigned char * ) V_41 , 8 ) ;
V_37 = V_55 ;
V_38 = 0 ;
F_3 ( V_30 , L_11 , ( unsigned char * ) V_42 , 8 ) ;
V_36 = ( V_40 -> V_56 << 4 ) | ( V_40 -> V_57 [ 0 ] >> 4 ) ;
V_36 = ( ( V_36 & 0x03 ) << 6 ) | ( V_36 >> 2 ) ;
if ( ( ( V_40 -> V_57 [ 0 ] & 0x0F ) == 0 ) &&
( V_40 -> V_57 [ 1 ] == 0 ) && ( V_40 -> V_57 [ 2 ] == 0 ) ) {
V_37 |= V_58 ;
if ( ( V_40 -> V_56 == 0 ) &&
( ( V_40 -> V_57 [ 0 ] & 0xF0 ) == 0 ) ) {
V_37 |= V_59 ;
} else {
* V_15 = V_36 ;
V_15 += 1 ;
}
} else {
if ( ( V_40 -> V_56 == 0 ) &&
( ( V_40 -> V_57 [ 0 ] & 0xF0 ) == 0 ) ) {
V_37 |= V_59 ;
* V_15 = ( V_36 & 0xc0 ) | ( V_40 -> V_57 [ 0 ] & 0x0F ) ;
memcpy ( V_15 + 1 , & V_40 -> V_57 [ 1 ] , 2 ) ;
V_15 += 3 ;
} else {
memcpy ( V_15 , & V_40 , 4 ) ;
* V_15 = V_36 ;
V_15 += 4 ;
}
}
if ( V_40 -> V_52 == V_60 )
V_37 |= V_61 ;
if ( ( V_37 & V_61 ) == 0 ) {
* V_15 = V_40 -> V_52 ;
V_15 += 1 ;
}
switch ( V_40 -> V_53 ) {
case 1 :
V_37 |= V_62 ;
break;
case 64 :
V_37 |= V_63 ;
break;
case 255 :
V_37 |= V_64 ;
break;
default:
* V_15 = V_40 -> V_53 ;
break;
}
if ( F_21 ( & V_40 -> V_41 ) ) {
F_5 ( L_12 ,
V_30 ) ;
V_38 |= V_65 ;
} else if ( F_22 ( & V_40 -> V_41 ) ) {
F_5 ( L_13 , V_30 ) ;
V_38 |= F_8 ( & V_15 ,
V_66 , & V_40 -> V_41 , V_41 ) ;
} else {
F_5 ( L_14 , V_30 ) ;
memcpy ( V_15 , & V_40 -> V_41 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
if ( F_23 ( & V_40 -> V_42 ) ) {
F_5 ( L_15 , V_30 ) ;
V_38 |= V_67 ;
if ( F_24 ( & V_40 -> V_42 ) ) {
F_5 ( L_16 ) ;
V_38 |= V_68 ;
* V_15 = V_40 -> V_42 . V_22 [ 15 ] ;
V_15 += 1 ;
} else if ( F_25 ( & V_40 -> V_42 ) ) {
F_5 ( L_17 ) ;
V_38 |= V_69 ;
* V_15 = V_40 -> V_42 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_40 -> V_42 . V_22 [ 13 ] , 3 ) ;
V_15 += 4 ;
} else if ( F_26 ( & V_40 -> V_42 ) ) {
F_5 ( L_18 ) ;
V_38 |= V_70 ;
* V_15 = V_40 -> V_42 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_40 -> V_42 . V_22 [ 11 ] , 5 ) ;
V_15 += 6 ;
} else {
F_5 ( L_19 ) ;
V_38 |= V_71 ;
memcpy ( V_15 , & V_40 -> V_42 . V_22 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
} else {
F_5 ( L_20 , V_30 ) ;
if ( F_22 ( & V_40 -> V_42 ) ) {
F_5 ( L_21 ) ;
V_38 |= F_8 ( & V_15 ,
V_72 , & V_40 -> V_42 , V_42 ) ;
} else {
F_5 ( L_19 ) ;
memcpy ( V_15 , & V_40 -> V_42 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
}
V_43 [ 0 ] = V_37 ;
V_43 [ 1 ] = V_38 ;
F_14 ( V_25 , sizeof( struct V_39 ) ) ;
memcpy ( F_27 ( V_25 , V_15 - V_43 ) , V_43 , V_15 - V_43 ) ;
F_28 ( V_43 ) ;
F_7 ( V_30 , L_22 , V_25 -> V_31 ,
V_25 -> V_11 ) ;
{
V_45 . V_73 = V_74 ;
V_45 . V_75 = 0xff ;
V_46 . V_73 = V_74 ;
V_46 . V_75 = 0xff ;
memcpy ( & ( V_46 . V_76 ) , V_42 , 8 ) ;
memcpy ( & ( V_45 . V_76 ) , V_41 , 8 ) ;
F_29 ( V_25 ) -> V_77 = V_78 ;
return F_30 ( V_25 , V_1 ( V_3 ) -> V_79 ,
type , ( void * ) & V_46 , ( void * ) & V_45 , V_25 -> V_11 ) ;
}
}
static int F_31 ( struct V_24 * V_25 , struct V_39 * V_40 )
{
struct V_24 * V_80 ;
struct V_81 * V_82 ;
int V_83 = V_84 ;
V_80 = F_32 ( V_25 , sizeof( struct V_39 ) , F_33 ( V_25 ) ,
V_85 ) ;
F_34 ( V_25 ) ;
if ( ! V_80 )
return - V_49 ;
F_27 ( V_80 , sizeof( struct V_39 ) ) ;
F_35 ( V_80 ) ;
F_36 ( V_80 , V_40 , sizeof( struct V_39 ) ) ;
V_80 -> V_86 = F_37 ( V_47 ) ;
V_80 -> V_87 = V_88 ;
F_38 () ;
F_39 (entry, &lowpan_devices, list)
if ( V_1 ( V_82 -> V_89 ) -> V_79 == V_80 -> V_3 ) {
V_25 = F_40 ( V_80 , V_85 ) ;
if ( ! V_25 ) {
V_83 = - V_49 ;
break;
}
V_25 -> V_3 = V_82 -> V_89 ;
V_83 = F_41 ( V_25 ) ;
}
F_42 () ;
F_34 ( V_80 ) ;
return V_83 ;
}
static int
F_43 ( struct V_24 * V_25 )
{
struct V_39 V_40 ;
T_1 V_36 , V_37 , V_38 , V_90 = 0 ;
T_1 * V_35 , * V_34 ;
int V_91 ;
F_7 ( V_30 , L_22 , V_25 -> V_31 ,
V_25 -> V_11 ) ;
if ( V_25 -> V_11 < 2 )
goto V_92;
V_37 = F_15 ( V_25 ) ;
V_38 = F_15 ( V_25 ) ;
V_35 = F_29 ( V_25 ) -> V_45 . V_76 ;
V_34 = F_29 ( V_25 ) -> V_46 . V_76 ;
F_5 ( L_23 , V_30 , V_37 , V_38 ) ;
if ( V_38 & V_93 ) {
F_5 ( L_24 ,
V_30 ) ;
if ( ! V_25 -> V_11 )
goto V_92;
V_90 = F_15 ( V_25 ) ;
}
V_40 . V_50 = 6 ;
switch ( ( V_37 & V_94 ) >> 3 ) {
case 0 :
if ( ! V_25 -> V_11 )
goto V_92;
V_36 = F_15 ( V_25 ) ;
memcpy ( & V_40 . V_57 , & V_25 -> V_31 [ 0 ] , 3 ) ;
F_14 ( V_25 , 3 ) ;
V_40 . V_56 = ( ( V_36 >> 2 ) & 0x0f ) ;
V_40 . V_57 [ 0 ] = ( ( V_36 >> 2 ) & 0x30 ) | ( V_36 << 6 ) |
( V_40 . V_57 [ 0 ] & 0x0f ) ;
break;
case 1 :
if ( ! V_25 -> V_11 )
goto V_92;
V_36 = F_15 ( V_25 ) ;
V_40 . V_56 = ( ( V_36 >> 2 ) & 0x0f ) ;
V_40 . V_57 [ 0 ] = ( ( V_36 << 6 ) & 0xC0 ) | ( ( V_36 >> 2 ) & 0x30 ) ;
V_40 . V_57 [ 1 ] = 0 ;
V_40 . V_57 [ 2 ] = 0 ;
break;
case 2 :
if ( ! V_25 -> V_11 )
goto V_92;
V_36 = F_15 ( V_25 ) ;
V_40 . V_57 [ 0 ] = ( V_25 -> V_31 [ 0 ] & 0x0F ) | ( ( V_36 >> 2 ) & 0x30 ) ;
memcpy ( & V_40 . V_57 [ 1 ] , & V_25 -> V_31 [ 0 ] , 2 ) ;
F_14 ( V_25 , 2 ) ;
break;
case 3 :
V_40 . V_56 = 0 ;
V_40 . V_57 [ 0 ] = 0 ;
V_40 . V_57 [ 1 ] = 0 ;
V_40 . V_57 [ 2 ] = 0 ;
break;
default:
break;
}
if ( ( V_37 & V_61 ) == 0 ) {
if ( ! V_25 -> V_11 )
goto V_92;
V_40 . V_52 = F_15 ( V_25 ) ;
F_5 ( L_25
L_26 , V_30 , V_40 . V_52 ) ;
}
if ( ( V_37 & 0x03 ) != V_95 )
V_40 . V_53 = V_96 [ V_37 & 0x03 ] ;
else {
if ( ! V_25 -> V_11 )
goto V_92;
V_40 . V_53 = F_15 ( V_25 ) ;
}
V_36 = ( ( V_38 & V_97 ) >> V_66 ) & 0x03 ;
F_5 ( L_27 , V_30 ) ;
V_91 = F_13 ( V_25 , & V_40 . V_41 , V_98 ,
V_99 [ V_36 ] , V_25 -> V_31 ) ;
if ( V_91 )
goto V_92;
V_36 = ( ( V_38 & V_68 ) >> V_72 ) & 0x03 ;
if ( V_38 & V_67 ) {
if ( V_38 & V_100 ) {
F_5 ( L_28
L_29 , V_30 ) ;
} else {
T_1 V_26 [] = { 0xff , 0x02 } ;
F_5 ( L_30
L_31 , V_30 ) ;
if ( 0 < V_36 && V_36 < 3 ) {
if ( ! V_25 -> V_11 )
goto V_92;
else
V_26 [ 1 ] = F_15 ( V_25 ) ;
}
V_91 = F_13 ( V_25 , & V_40 . V_42 , V_26 ,
V_101 [ V_36 ] , NULL ) ;
if ( V_91 )
goto V_92;
}
} else {
F_5 ( L_32 ,
V_30 ) ;
V_91 = F_13 ( V_25 , & V_40 . V_42 , V_98 ,
V_99 [ V_36 ] , V_25 -> V_31 ) ;
if ( V_91 )
goto V_92;
}
V_40 . V_51 = F_37 ( V_25 -> V_11 ) ;
F_5 ( L_33 , V_30 ,
F_44 ( V_25 ) , V_25 -> V_11 ) ;
F_5 ( L_34
L_35 , V_30 , V_40 . V_50 ,
F_19 ( V_40 . V_51 ) , V_40 . V_52 , V_40 . V_53 ) ;
F_7 ( V_30 , L_36 , ( T_1 * ) & V_40 ,
sizeof( V_40 ) ) ;
return F_31 ( V_25 , & V_40 ) ;
V_92:
F_34 ( V_25 ) ;
return - V_32 ;
}
static int F_45 ( struct V_2 * V_3 , void * V_102 )
{
struct V_103 * V_45 = V_102 ;
if ( F_46 ( V_3 ) )
return - V_104 ;
memcpy ( V_3 -> V_54 , V_45 -> V_105 , V_3 -> V_106 ) ;
return 0 ;
}
static T_2 F_47 ( struct V_24 * V_25 , struct V_2 * V_3 )
{
int V_91 = 0 ;
F_5 ( L_37 , V_30 ) ;
V_25 -> V_3 = V_1 ( V_3 ) -> V_79 ;
if ( V_25 -> V_3 == NULL ) {
F_5 ( L_38 , V_30 ) ;
F_48 ( V_25 ) ;
} else
V_91 = F_49 ( V_25 ) ;
return ( V_91 < 0 ? V_107 : V_108 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_51 ( V_1 ( V_3 ) -> V_79 ) ;
F_52 ( V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
F_5 ( L_39 , V_30 ) ;
V_3 -> V_106 = V_7 ;
memset ( V_3 -> V_109 , 0xff , V_7 ) ;
V_3 -> type = V_110 ;
V_3 -> V_111 = V_112 ;
V_3 -> V_113 = 2 + 1 + 20 + 14 ;
V_3 -> V_114 = 2 ;
V_3 -> V_115 = 1281 ;
V_3 -> V_116 = 0 ;
V_3 -> V_77 = V_117 | V_118 ;
V_3 -> V_119 = 0 ;
V_3 -> V_120 = & V_121 ;
V_3 -> V_122 = & V_123 ;
V_3 -> V_124 = F_50 ;
}
static int F_54 ( struct V_125 * V_126 [] , struct V_125 * V_31 [] )
{
F_5 ( L_39 , V_30 ) ;
if ( V_126 [ V_127 ] ) {
if ( F_55 ( V_126 [ V_127 ] ) != V_7 )
return - V_32 ;
}
return 0 ;
}
static int F_56 ( struct V_24 * V_25 , struct V_2 * V_3 ,
struct V_128 * V_129 , struct V_2 * V_130 )
{
if ( ! F_46 ( V_3 ) )
goto V_92;
if ( V_3 -> type != V_110 )
goto V_92;
if ( ( V_25 -> V_31 [ 0 ] & 0xe0 ) == 0x60 )
F_43 ( V_25 ) ;
return V_84 ;
V_92:
F_34 ( V_25 ) ;
return V_131 ;
}
static int F_57 ( struct V_132 * V_133 , struct V_2 * V_3 ,
struct V_125 * V_126 [] , struct V_125 * V_31 [] )
{
struct V_2 * V_79 ;
struct V_81 * V_82 ;
F_5 ( L_39 , V_30 ) ;
if ( ! V_126 [ V_134 ] )
return - V_32 ;
V_79 = F_58 ( V_133 , F_59 ( V_126 [ V_134 ] ) ) ;
if ( ! V_79 )
return - V_135 ;
V_1 ( V_3 ) -> V_79 = V_79 ;
F_60 ( & V_1 ( V_3 ) -> V_136 ) ;
V_82 = F_17 ( sizeof( struct V_81 ) , V_48 ) ;
if ( ! V_82 ) {
F_51 ( V_79 ) ;
V_1 ( V_3 ) -> V_79 = NULL ;
return - V_49 ;
}
V_82 -> V_89 = V_3 ;
F_61 ( & V_1 ( V_3 ) -> V_136 ) ;
F_62 ( & V_82 -> V_137 ) ;
F_63 ( & V_82 -> V_137 , & V_138 ) ;
F_64 ( & V_1 ( V_3 ) -> V_136 ) ;
F_65 ( V_3 ) ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 , struct V_139 * V_43 )
{
struct V_1 * V_140 = V_1 ( V_3 ) ;
struct V_2 * V_79 = V_140 -> V_79 ;
struct V_81 * V_82 ;
struct V_81 * V_36 ;
F_67 () ;
F_61 ( & V_1 ( V_3 ) -> V_136 ) ;
F_68 (entry, tmp, &lowpan_devices, list) {
if ( V_82 -> V_89 == V_3 ) {
F_69 ( & V_82 -> V_137 ) ;
F_28 ( V_82 ) ;
}
}
F_64 ( & V_1 ( V_3 ) -> V_136 ) ;
F_70 ( & V_1 ( V_3 ) -> V_136 ) ;
F_71 ( V_3 , V_43 ) ;
F_51 ( V_79 ) ;
}
static inline int T_3 F_72 ( void )
{
return F_73 ( & V_141 ) ;
}
static inline void T_3 F_74 ( void )
{
F_75 ( & V_141 ) ;
}
static int T_3 F_76 ( void )
{
int V_91 = 0 ;
F_5 ( L_39 , V_30 ) ;
V_91 = F_72 () ;
if ( V_91 < 0 )
goto V_142;
F_77 ( & V_143 ) ;
V_142:
return V_91 ;
}
static void T_4 F_78 ( void )
{
F_5 ( L_39 , V_30 ) ;
F_74 () ;
F_79 ( & V_143 ) ;
}
