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
F_14 ( V_24 , sizeof( struct V_32 ) ) ;
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
F_21 ( struct V_23 * V_24 , struct V_32 * V_33 )
{
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
V_33 -> V_11 = F_22 ( V_24 -> V_11 + sizeof( struct V_32 ) ) ;
F_5 ( L_14 , V_33 -> V_11 ) ;
} else {
F_5 ( L_15 ) ;
goto V_45;
}
return 0 ;
V_45:
return - V_31 ;
}
static int F_23 ( struct V_23 * V_24 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_48 ,
const void * V_49 , unsigned int V_11 )
{
T_1 V_44 , V_50 , V_51 , * V_15 ;
struct V_52 * V_53 ;
const T_1 * V_54 = V_49 ;
const T_1 * V_55 = V_48 ;
T_1 V_56 [ 100 ] ;
struct V_57 V_58 , V_59 ;
if ( type != V_60 )
return 0 ;
V_53 = F_24 ( V_24 ) ;
V_15 = V_56 + 2 ;
F_5 ( L_16
L_17 , V_53 -> V_61 ,
F_25 ( V_53 -> V_62 ) , V_53 -> V_63 , V_53 -> V_64 ) ;
F_7 ( V_29 , L_18 ,
F_26 ( V_24 ) , sizeof( struct V_52 ) ) ;
if ( ! V_54 )
V_54 = V_3 -> V_65 ;
F_3 ( V_29 , L_19 , ( unsigned char * ) V_54 , 8 ) ;
V_50 = V_66 ;
V_51 = 0 ;
F_3 ( V_29 , L_20 , ( unsigned char * ) V_55 , 8 ) ;
V_44 = ( V_53 -> V_67 << 4 ) | ( V_53 -> V_68 [ 0 ] >> 4 ) ;
V_44 = ( ( V_44 & 0x03 ) << 6 ) | ( V_44 >> 2 ) ;
if ( ( ( V_53 -> V_68 [ 0 ] & 0x0F ) == 0 ) &&
( V_53 -> V_68 [ 1 ] == 0 ) && ( V_53 -> V_68 [ 2 ] == 0 ) ) {
V_50 |= V_69 ;
if ( ( V_53 -> V_67 == 0 ) &&
( ( V_53 -> V_68 [ 0 ] & 0xF0 ) == 0 ) ) {
V_50 |= V_70 ;
} else {
* V_15 = V_44 ;
V_15 += 1 ;
}
} else {
if ( ( V_53 -> V_67 == 0 ) &&
( ( V_53 -> V_68 [ 0 ] & 0xF0 ) == 0 ) ) {
V_50 |= V_70 ;
* V_15 = ( V_44 & 0xc0 ) | ( V_53 -> V_68 [ 0 ] & 0x0F ) ;
memcpy ( V_15 + 1 , & V_53 -> V_68 [ 1 ] , 2 ) ;
V_15 += 3 ;
} else {
memcpy ( V_15 , & V_53 , 4 ) ;
* V_15 = V_44 ;
V_15 += 4 ;
}
}
if ( V_53 -> V_63 == V_71 )
V_50 |= V_72 ;
if ( ( V_50 & V_72 ) == 0 ) {
* V_15 = V_53 -> V_63 ;
V_15 += 1 ;
}
switch ( V_53 -> V_64 ) {
case 1 :
V_50 |= V_73 ;
break;
case 64 :
V_50 |= V_74 ;
break;
case 255 :
V_50 |= V_75 ;
break;
default:
* V_15 = V_53 -> V_64 ;
V_15 += 1 ;
break;
}
if ( F_27 ( & V_53 -> V_54 ) ) {
F_5 ( L_21 ) ;
V_51 |= V_76 ;
} else if ( F_28 ( & V_53 -> V_54 ) ) {
F_5 ( L_22 ) ;
V_51 |= F_8 ( & V_15 ,
V_77 , & V_53 -> V_54 , V_54 ) ;
} else {
F_5 ( L_23 ) ;
memcpy ( V_15 , & V_53 -> V_54 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
if ( F_29 ( & V_53 -> V_55 ) ) {
F_5 ( L_24 ) ;
V_51 |= V_78 ;
if ( F_30 ( & V_53 -> V_55 ) ) {
F_5 ( L_25 ) ;
V_51 |= V_79 ;
* V_15 = V_53 -> V_55 . V_22 [ 15 ] ;
V_15 += 1 ;
} else if ( F_31 ( & V_53 -> V_55 ) ) {
F_5 ( L_26 ) ;
V_51 |= V_80 ;
* V_15 = V_53 -> V_55 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_53 -> V_55 . V_22 [ 13 ] , 3 ) ;
V_15 += 4 ;
} else if ( F_32 ( & V_53 -> V_55 ) ) {
F_5 ( L_27 ) ;
V_51 |= V_81 ;
* V_15 = V_53 -> V_55 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_53 -> V_55 . V_22 [ 11 ] , 5 ) ;
V_15 += 6 ;
} else {
F_5 ( L_28 ) ;
V_51 |= V_82 ;
memcpy ( V_15 , & V_53 -> V_55 . V_22 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
} else {
if ( F_28 ( & V_53 -> V_55 ) ) {
F_5 ( L_29 ) ;
V_51 |= F_8 ( & V_15 ,
V_83 , & V_53 -> V_55 , V_55 ) ;
} else {
F_5 ( L_30 ) ;
memcpy ( V_15 , & V_53 -> V_55 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
}
if ( V_53 -> V_63 == V_71 )
F_15 ( & V_15 , V_24 ) ;
V_56 [ 0 ] = V_50 ;
V_56 [ 1 ] = V_51 ;
F_14 ( V_24 , sizeof( struct V_52 ) ) ;
memcpy ( F_33 ( V_24 , V_15 - V_56 ) , V_56 , V_15 - V_56 ) ;
F_7 ( V_29 , L_31 , V_24 -> V_30 ,
V_24 -> V_11 ) ;
{
F_34 ( V_24 ) -> V_84 = V_85 ;
F_34 ( V_24 ) -> V_86 = F_35 ( V_3 ) -> F_36 ( V_3 ) ;
V_58 . V_87 = V_88 ;
V_58 . V_89 = F_35 ( V_3 ) -> F_37 ( V_3 ) ;
memcpy ( & ( V_58 . V_90 ) , V_54 , 8 ) ;
V_59 . V_89 = F_35 ( V_3 ) -> F_37 ( V_3 ) ;
if ( F_38 ( V_55 ) ) {
V_59 . V_87 = V_91 ;
V_59 . V_92 = V_93 ;
} else {
V_59 . V_87 = V_88 ;
memcpy ( & ( V_59 . V_90 ) , V_55 , V_7 ) ;
F_34 ( V_24 ) -> V_84 |= V_94 ;
}
return F_39 ( V_24 , V_1 ( V_3 ) -> V_95 ,
type , ( void * ) & V_59 , ( void * ) & V_58 , V_24 -> V_11 ) ;
}
}
static int F_40 ( struct V_23 * V_24 )
{
struct V_96 * V_97 ;
struct V_23 * V_98 ;
int V_99 = V_100 ;
F_41 () ;
F_42 (entry, &lowpan_devices, list)
if ( V_1 ( V_97 -> V_101 ) -> V_95 == V_24 -> V_3 ) {
V_98 = F_43 ( V_24 , V_102 ) ;
if ( ! V_98 ) {
V_99 = - V_103 ;
break;
}
V_98 -> V_3 = V_97 -> V_101 ;
V_99 = F_44 ( V_98 ) ;
}
F_45 () ;
return V_99 ;
}
static int F_46 ( struct V_23 * V_24 , struct V_52 * V_53 )
{
struct V_23 * V_104 ;
int V_99 = V_100 ;
V_104 = F_47 ( V_24 , sizeof( struct V_52 ) , F_48 ( V_24 ) ,
V_102 ) ;
F_49 ( V_24 ) ;
if ( ! V_104 )
return - V_103 ;
F_33 ( V_104 , sizeof( struct V_52 ) ) ;
F_50 ( V_104 ) ;
F_51 ( V_104 , V_53 , sizeof( struct V_52 ) ) ;
V_104 -> V_105 = F_22 ( V_60 ) ;
V_104 -> V_106 = V_107 ;
V_99 = F_40 ( V_104 ) ;
F_49 ( V_104 ) ;
return V_99 ;
}
static void F_52 ( unsigned long V_108 )
{
struct V_109 * V_97 = (struct V_109 * ) V_108 ;
F_5 ( L_32 , V_97 -> V_110 ) ;
F_53 ( & V_97 -> V_111 ) ;
F_54 ( V_97 -> V_24 ) ;
F_55 ( V_97 ) ;
}
static struct V_109 *
F_56 ( struct V_23 * V_24 , T_2 V_11 , T_2 V_110 )
{
struct V_109 * V_112 ;
V_112 = F_57 ( sizeof( struct V_109 ) ,
V_102 ) ;
if ( ! V_112 )
goto V_113;
F_58 ( & V_112 -> V_111 ) ;
V_112 -> V_114 = V_11 ;
V_112 -> V_110 = V_110 ;
V_112 -> V_24 = F_59 ( V_24 -> V_3 , V_112 -> V_114 +
sizeof( struct V_52 ) ) ;
if ( ! V_112 -> V_24 )
goto V_115;
V_112 -> V_24 -> V_67 = V_24 -> V_67 ;
V_112 -> V_24 -> V_3 = V_24 -> V_3 ;
F_60 ( V_112 -> V_24 , sizeof( struct V_52 ) ) ;
F_61 ( V_112 -> V_24 , V_112 -> V_114 ) ;
F_62 ( & V_112 -> V_116 ) ;
V_112 -> V_116 . V_117 = V_118 + V_119 ;
V_112 -> V_116 . V_30 = ( unsigned long ) V_112 ;
V_112 -> V_116 . V_120 = F_52 ;
F_63 ( & V_112 -> V_116 ) ;
F_64 ( & V_112 -> V_111 , & V_121 ) ;
return V_112 ;
V_115:
F_55 ( V_112 ) ;
V_113:
return NULL ;
}
static int
F_65 ( struct V_23 * V_24 )
{
struct V_52 V_53 ;
T_1 V_44 , V_50 , V_51 , V_122 = 0 ;
T_1 * V_49 , * V_48 ;
int V_45 ;
F_7 ( V_29 , L_31 , V_24 -> V_30 ,
V_24 -> V_11 ) ;
if ( V_24 -> V_11 < 2 )
goto V_123;
if ( F_17 ( V_24 , & V_50 ) )
goto V_123;
switch ( V_50 & V_124 ) {
case V_125 :
case V_126 :
{
struct V_109 * V_112 ;
T_1 V_127 , V_128 = 0 ;
T_2 V_11 , V_110 ;
bool V_129 = false ;
if ( F_17 ( V_24 , & V_127 ) ||
F_20 ( V_24 , & V_110 ) )
goto V_123;
V_11 = ( ( V_50 & 7 ) << 8 ) | V_127 ;
if ( ( V_50 & V_124 ) == V_125 ) {
F_5 ( L_33
L_34 ,
V_29 , V_110 , V_11 ) ;
} else {
if ( F_17 ( V_24 , & V_128 ) )
goto V_130;
F_5 ( L_35
L_36
L_37 , V_29 , V_110 , V_11 , V_128 * 8 ) ;
}
F_66 ( & V_131 ) ;
F_67 (frame, &lowpan_fragments, list)
if ( V_112 -> V_110 == V_110 ) {
V_129 = true ;
break;
}
if ( ! V_129 ) {
F_5 ( L_38
L_39 , V_29 , V_110 ) ;
V_112 = F_56 ( V_24 , V_11 , V_110 ) ;
if ( ! V_112 )
goto V_130;
}
if ( F_68 ( ( V_128 * 8 + V_24 -> V_11 ) <= V_112 -> V_114 ) )
F_69 ( V_112 -> V_24 , V_128 * 8 ,
V_24 -> V_30 , V_24 -> V_11 ) ;
else
goto V_130;
V_112 -> V_132 += V_24 -> V_11 ;
if ( ( V_112 -> V_132 == V_112 -> V_114 ) &&
V_112 -> V_116 . V_117 > V_118 ) {
F_70 ( & V_112 -> V_116 ) ;
F_53 ( & V_112 -> V_111 ) ;
F_71 ( & V_131 ) ;
F_5 ( L_40
L_41 , V_29 , V_110 ) ;
F_54 ( V_24 ) ;
V_24 = V_112 -> V_24 ;
F_55 ( V_112 ) ;
if ( F_17 ( V_24 , & V_50 ) )
goto V_123;
break;
}
F_71 ( & V_131 ) ;
return F_49 ( V_24 ) , 0 ;
}
default:
break;
}
if ( F_17 ( V_24 , & V_51 ) )
goto V_123;
V_49 = F_34 ( V_24 ) -> V_58 . V_90 ;
V_48 = F_34 ( V_24 ) -> V_59 . V_90 ;
F_5 ( L_42 , V_50 , V_51 ) ;
if ( V_51 & V_133 ) {
F_5 ( L_43 ) ;
if ( F_17 ( V_24 , & V_122 ) )
goto V_123;
}
V_53 . V_61 = 6 ;
switch ( ( V_50 & V_134 ) >> 3 ) {
case 0 :
if ( F_17 ( V_24 , & V_44 ) )
goto V_123;
memcpy ( & V_53 . V_68 , & V_24 -> V_30 [ 0 ] , 3 ) ;
F_14 ( V_24 , 3 ) ;
V_53 . V_67 = ( ( V_44 >> 2 ) & 0x0f ) ;
V_53 . V_68 [ 0 ] = ( ( V_44 >> 2 ) & 0x30 ) | ( V_44 << 6 ) |
( V_53 . V_68 [ 0 ] & 0x0f ) ;
break;
case 1 :
if ( F_17 ( V_24 , & V_44 ) )
goto V_123;
V_53 . V_67 = ( ( V_44 >> 2 ) & 0x0f ) ;
V_53 . V_68 [ 0 ] = ( ( V_44 << 6 ) & 0xC0 ) | ( ( V_44 >> 2 ) & 0x30 ) ;
V_53 . V_68 [ 1 ] = 0 ;
V_53 . V_68 [ 2 ] = 0 ;
break;
case 2 :
if ( F_17 ( V_24 , & V_44 ) )
goto V_123;
V_53 . V_68 [ 0 ] = ( V_24 -> V_30 [ 0 ] & 0x0F ) | ( ( V_44 >> 2 ) & 0x30 ) ;
memcpy ( & V_53 . V_68 [ 1 ] , & V_24 -> V_30 [ 0 ] , 2 ) ;
F_14 ( V_24 , 2 ) ;
break;
case 3 :
V_53 . V_67 = 0 ;
V_53 . V_68 [ 0 ] = 0 ;
V_53 . V_68 [ 1 ] = 0 ;
V_53 . V_68 [ 2 ] = 0 ;
break;
default:
break;
}
if ( ( V_50 & V_72 ) == 0 ) {
if ( F_17 ( V_24 , & ( V_53 . V_63 ) ) )
goto V_123;
F_5 ( L_44 ,
V_53 . V_63 ) ;
}
if ( ( V_50 & 0x03 ) != V_135 )
V_53 . V_64 = V_136 [ V_50 & 0x03 ] ;
else {
if ( F_17 ( V_24 , & ( V_53 . V_64 ) ) )
goto V_123;
}
V_44 = ( ( V_51 & V_137 ) >> V_77 ) & 0x03 ;
F_5 ( L_45 ) ;
V_45 = F_13 ( V_24 , & V_53 . V_54 , V_138 ,
V_139 [ V_44 ] , V_24 -> V_30 ) ;
if ( V_45 )
goto V_123;
V_44 = ( ( V_51 & V_79 ) >> V_83 ) & 0x03 ;
if ( V_51 & V_78 ) {
if ( V_51 & V_140 ) {
F_5 ( L_46 ) ;
} else {
T_1 V_25 [] = { 0xff , 0x02 } ;
F_5 ( L_47 ) ;
if ( 0 < V_44 && V_44 < 3 ) {
if ( F_17 ( V_24 , & V_25 [ 1 ] ) )
goto V_123;
}
V_45 = F_13 ( V_24 , & V_53 . V_55 , V_25 ,
V_141 [ V_44 ] , NULL ) ;
if ( V_45 )
goto V_123;
}
} else {
F_5 ( L_48 ) ;
V_45 = F_13 ( V_24 , & V_53 . V_55 , V_138 ,
V_139 [ V_44 ] , V_24 -> V_30 ) ;
if ( V_45 )
goto V_123;
}
if ( V_50 & V_72 ) {
struct V_32 V_33 ;
struct V_23 * V_104 ;
if ( F_21 ( V_24 , & V_33 ) )
goto V_123;
V_104 = F_47 ( V_24 , sizeof( struct V_32 ) ,
F_48 ( V_24 ) , V_102 ) ;
F_49 ( V_24 ) ;
if ( ! V_104 )
return - V_103 ;
V_24 = V_104 ;
F_33 ( V_24 , sizeof( struct V_32 ) ) ;
F_72 ( V_24 ) ;
F_51 ( V_24 , & V_33 , sizeof( struct V_32 ) ) ;
F_7 ( V_29 , L_49 ,
( T_1 * ) & V_33 , sizeof( V_33 ) ) ;
V_53 . V_63 = V_71 ;
}
V_53 . V_62 = F_22 ( V_24 -> V_11 ) ;
F_5 ( L_50 ,
F_73 ( V_24 ) , V_24 -> V_11 ) ;
F_5 ( L_51
L_52 , V_53 . V_61 ,
F_25 ( V_53 . V_62 ) , V_53 . V_63 , V_53 . V_64 ) ;
F_7 ( V_29 , L_53 , ( T_1 * ) & V_53 ,
sizeof( V_53 ) ) ;
return F_46 ( V_24 , & V_53 ) ;
V_130:
F_71 ( & V_131 ) ;
V_123:
F_49 ( V_24 ) ;
return - V_31 ;
}
static int F_74 ( struct V_2 * V_3 , void * V_142 )
{
struct V_143 * V_58 = V_142 ;
if ( F_75 ( V_3 ) )
return - V_144 ;
memcpy ( V_3 -> V_65 , V_58 -> V_145 , V_3 -> V_146 ) ;
return 0 ;
}
static int F_76 ( struct V_23 * V_24 )
{
return 21 ;
}
static int
F_77 ( struct V_23 * V_24 , T_1 * V_56 ,
int V_147 , int V_148 , int V_128 , int type )
{
struct V_23 * V_149 ;
int V_150 , V_151 ;
V_150 = ( type == V_125 ) ?
V_152 : V_153 ;
F_3 ( V_29 , L_54 , V_56 , V_150 ) ;
V_149 = F_78 ( V_150 + V_147 + V_148 + V_154 ) ;
if ( ! V_149 )
return - V_103 ;
V_149 -> V_67 = V_24 -> V_67 ;
V_149 -> V_3 = V_24 -> V_3 ;
memcpy ( F_61 ( V_149 , V_147 ) , V_24 -> V_30 , V_147 ) ;
memcpy ( F_61 ( V_149 , V_150 ) , V_56 , V_150 ) ;
if ( V_148 )
F_79 ( V_24 , V_128 + V_147 ,
F_61 ( V_149 , V_148 ) , V_148 ) ;
F_7 ( V_29 , L_55 , V_149 -> V_30 ,
V_149 -> V_11 ) ;
V_151 = F_80 ( V_149 ) ;
return V_151 ;
}
static int
F_81 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
int V_45 , V_155 , V_156 , V_110 , V_128 = 0 ;
T_1 V_56 [ 5 ] ;
V_155 = F_76 ( V_24 ) ;
V_156 = V_24 -> V_11 - V_155 ;
V_110 = V_1 ( V_3 ) -> V_157 ++ ;
V_56 [ 0 ] = V_125 | ( ( V_156 >> 8 ) & 0x7 ) ;
V_56 [ 1 ] = V_156 & 0xff ;
V_56 [ 2 ] = V_110 >> 8 ;
V_56 [ 3 ] = V_110 & 0xff ;
V_45 = F_77 ( V_24 , V_56 , V_155 , V_158 ,
0 , V_125 ) ;
if ( V_45 ) {
F_5 ( L_56 ,
V_29 , V_110 ) ;
goto exit;
}
V_128 = V_158 ;
V_56 [ 0 ] &= ~ V_125 ;
V_56 [ 0 ] |= V_126 ;
while ( ( V_156 - V_128 > 0 ) && ( V_45 >= 0 ) ) {
int V_11 = V_158 ;
V_56 [ 4 ] = V_128 / 8 ;
if ( V_156 - V_128 < V_11 )
V_11 = V_156 - V_128 ;
V_45 = F_77 ( V_24 , V_56 , V_155 ,
V_11 , V_128 , V_126 ) ;
if ( V_45 ) {
F_5 ( L_57
L_58 , V_29 , V_110 , V_128 ) ;
goto exit;
}
V_128 += V_11 ;
}
exit:
return V_45 ;
}
static T_3 F_82 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
int V_45 = - 1 ;
F_5 ( L_59 ) ;
V_24 -> V_3 = V_1 ( V_3 ) -> V_95 ;
if ( V_24 -> V_3 == NULL ) {
F_5 ( L_60 ) ;
goto error;
}
if ( V_24 -> V_11 <= V_159 - V_154 ) {
V_45 = F_80 ( V_24 ) ;
goto V_160;
}
F_5 ( L_61 ) ;
V_45 = F_81 ( V_24 , V_3 ) ;
error:
F_54 ( V_24 ) ;
V_160:
if ( V_45 )
F_5 ( L_62 ) ;
return ( V_45 < 0 ) ? V_161 : V_45 ;
}
static struct V_162 * F_83 ( const struct V_2 * V_3 )
{
struct V_2 * V_95 = V_1 ( V_3 ) -> V_95 ;
return F_35 ( V_95 ) -> F_84 ( V_95 ) ;
}
static T_2 F_85 ( const struct V_2 * V_3 )
{
struct V_2 * V_95 = V_1 ( V_3 ) -> V_95 ;
return F_35 ( V_95 ) -> F_37 ( V_95 ) ;
}
static T_2 F_86 ( const struct V_2 * V_3 )
{
struct V_2 * V_95 = V_1 ( V_3 ) -> V_95 ;
return F_35 ( V_95 ) -> F_87 ( V_95 ) ;
}
static T_1 F_88 ( const struct V_2 * V_3 )
{
struct V_2 * V_95 = V_1 ( V_3 ) -> V_95 ;
return F_35 ( V_95 ) -> F_36 ( V_95 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
V_3 -> V_146 = V_7 ;
memset ( V_3 -> V_163 , 0xff , V_7 ) ;
V_3 -> type = V_164 ;
V_3 -> V_165 = 2 + 1 + 20 + 14 ;
V_3 -> V_166 = 2 ;
V_3 -> V_167 = 1281 ;
V_3 -> V_168 = 0 ;
V_3 -> V_84 = V_169 | V_170 ;
V_3 -> V_171 = 0 ;
V_3 -> V_172 = & V_173 ;
V_3 -> V_174 = & V_175 ;
V_3 -> V_176 = & V_177 ;
V_3 -> V_178 = V_179 ;
}
static int F_90 ( struct V_180 * V_181 [] , struct V_180 * V_30 [] )
{
if ( V_181 [ V_182 ] ) {
if ( F_91 ( V_181 [ V_182 ] ) != V_7 )
return - V_31 ;
}
return 0 ;
}
static int F_92 ( struct V_23 * V_24 , struct V_2 * V_3 ,
struct V_183 * V_184 , struct V_2 * V_185 )
{
struct V_23 * V_186 ;
if ( ! F_75 ( V_3 ) )
goto V_123;
if ( V_3 -> type != V_164 )
goto V_123;
if ( V_24 -> V_30 [ 0 ] == V_187 ) {
V_186 = F_47 ( V_24 , V_188 - 1 ,
F_48 ( V_24 ) , V_102 ) ;
if ( ! V_186 )
goto V_123;
V_186 -> V_105 = F_22 ( V_60 ) ;
V_186 -> V_106 = V_107 ;
F_14 ( V_186 , 1 ) ;
F_50 ( V_186 ) ;
F_93 ( V_186 , sizeof( struct V_52 ) ) ;
F_40 ( V_186 ) ;
F_49 ( V_186 ) ;
F_49 ( V_24 ) ;
} else {
switch ( V_24 -> V_30 [ 0 ] & 0xe0 ) {
case V_66 :
case V_125 :
case V_126 :
V_186 = F_94 ( V_24 , V_102 ) ;
if ( ! V_186 )
goto V_123;
F_65 ( V_186 ) ;
F_49 ( V_24 ) ;
break;
default:
break;
}
}
return V_100 ;
V_123:
F_49 ( V_24 ) ;
return V_189 ;
}
static int F_95 ( struct V_190 * V_191 , struct V_2 * V_3 ,
struct V_180 * V_181 [] , struct V_180 * V_30 [] )
{
struct V_2 * V_95 ;
struct V_96 * V_97 ;
F_5 ( L_63 ) ;
if ( ! V_181 [ V_192 ] )
return - V_31 ;
V_95 = F_96 ( V_191 , F_97 ( V_181 [ V_192 ] ) ) ;
if ( ! V_95 )
return - V_193 ;
V_1 ( V_3 ) -> V_95 = V_95 ;
V_1 ( V_3 ) -> V_157 = 0 ;
F_98 ( & V_1 ( V_3 ) -> V_194 ) ;
V_97 = F_57 ( sizeof( struct V_96 ) , V_195 ) ;
if ( ! V_97 ) {
F_99 ( V_95 ) ;
V_1 ( V_3 ) -> V_95 = NULL ;
return - V_103 ;
}
V_97 -> V_101 = V_3 ;
F_100 ( & V_1 ( V_3 ) -> V_194 ) ;
F_58 ( & V_97 -> V_111 ) ;
F_64 ( & V_97 -> V_111 , & V_196 ) ;
F_101 ( & V_1 ( V_3 ) -> V_194 ) ;
F_102 ( V_3 ) ;
return 0 ;
}
static void F_103 ( struct V_2 * V_3 , struct V_197 * V_56 )
{
struct V_1 * V_198 = V_1 ( V_3 ) ;
struct V_2 * V_95 = V_198 -> V_95 ;
struct V_96 * V_97 , * V_44 ;
F_104 () ;
F_100 ( & V_1 ( V_3 ) -> V_194 ) ;
F_105 (entry, tmp, &lowpan_devices, list) {
if ( V_97 -> V_101 == V_3 ) {
F_53 ( & V_97 -> V_111 ) ;
F_55 ( V_97 ) ;
}
}
F_101 ( & V_1 ( V_3 ) -> V_194 ) ;
F_106 ( & V_1 ( V_3 ) -> V_194 ) ;
F_107 ( V_3 , V_56 ) ;
F_99 ( V_95 ) ;
}
static inline int T_4 F_108 ( void )
{
return F_109 ( & V_199 ) ;
}
static inline void F_110 ( void )
{
F_111 ( & V_199 ) ;
}
static int F_112 ( struct V_200 * V_201 ,
unsigned long V_202 ,
void * V_203 )
{
struct V_2 * V_3 = V_203 ;
F_113 ( V_204 ) ;
struct V_96 * V_97 , * V_44 ;
if ( V_3 -> type != V_164 )
goto V_160;
if ( V_202 == V_205 ) {
F_105 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_97 -> V_101 ) -> V_95 == V_3 )
F_103 ( V_97 -> V_101 , & V_204 ) ;
}
F_114 ( & V_204 ) ;
}
V_160:
return V_206 ;
}
static int T_4 F_115 ( void )
{
int V_45 = 0 ;
V_45 = F_108 () ;
if ( V_45 < 0 )
goto V_160;
F_116 ( & V_207 ) ;
V_45 = F_117 ( & V_208 ) ;
if ( V_45 < 0 ) {
F_118 ( & V_207 ) ;
F_110 () ;
}
V_160:
return V_45 ;
}
static void T_5 F_119 ( void )
{
struct V_109 * V_112 , * V_209 ;
F_110 () ;
F_118 ( & V_207 ) ;
F_120 ( & V_208 ) ;
F_66 ( & V_131 ) ;
F_105 (frame, tframe, &lowpan_fragments, list) {
F_70 ( & V_112 -> V_116 ) ;
F_53 ( & V_112 -> V_111 ) ;
F_54 ( V_112 -> V_24 ) ;
F_55 ( V_112 ) ;
}
F_71 ( & V_131 ) ;
}
