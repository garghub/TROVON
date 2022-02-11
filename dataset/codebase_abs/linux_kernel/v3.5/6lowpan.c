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
F_5 ( L_6 , V_29 , V_27 ,
V_28 ) ;
F_3 ( NULL , NULL , V_18 -> V_22 , 16 ) ;
return 0 ;
}
static void
F_15 ( T_1 * * V_15 , struct V_23 * V_24 )
{
struct V_32 * V_33 = F_16 ( V_24 ) ;
F_5 ( L_7 , V_29 ) ;
if ( ( ( V_33 -> V_34 & V_35 ) ==
V_36 ) &&
( ( V_33 -> V_5 & V_35 ) ==
V_36 ) ) {
F_5 ( L_8 , V_29 ) ;
* * V_15 = V_37 ;
* * ( V_15 + 1 ) =
( T_1 ) ( ( V_33 -> V_5 - V_36 ) +
( ( V_33 -> V_34 & V_36 ) << 4 ) ) ;
* V_15 += 2 ;
} else if ( ( V_33 -> V_5 & V_38 ) ==
V_39 ) {
F_5 ( L_9 , V_29 ) ;
* * V_15 = V_40 ;
memcpy ( * V_15 + 1 , & V_33 -> V_34 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_33 -> V_5 - V_39 ) ;
* V_15 += 4 ;
} else if ( ( V_33 -> V_34 & V_38 ) ==
V_39 ) {
F_5 ( L_10 , V_29 ) ;
* * V_15 = V_41 ;
memcpy ( * V_15 + 1 , & V_33 -> V_5 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_33 -> V_34 - V_39 ) ;
* V_15 += 4 ;
} else {
F_5 ( L_11 , V_29 ) ;
* * V_15 = V_42 ;
memcpy ( * V_15 + 1 , & V_33 -> V_34 , 2 ) ;
memcpy ( * V_15 + 3 , & V_33 -> V_5 , 2 ) ;
* V_15 += 5 ;
}
memcpy ( * V_15 , & V_33 -> V_43 , 2 ) ;
* V_15 += 2 ;
}
static T_1 F_17 ( struct V_23 * V_24 )
{
T_1 V_44 ;
V_44 = V_24 -> V_30 [ 0 ] ;
F_14 ( V_24 , 1 ) ;
return V_44 ;
}
static T_2 F_18 ( struct V_23 * V_24 )
{
T_2 V_44 ;
F_19 ( ! F_20 ( V_24 , 2 ) ) ;
V_44 = V_24 -> V_30 [ 0 ] | ( V_24 -> V_30 [ 1 ] << 8 ) ;
F_14 ( V_24 , 2 ) ;
return V_44 ;
}
static int
F_21 ( struct V_23 * V_24 )
{
struct V_32 * V_33 = F_16 ( V_24 ) ;
T_1 V_45 ;
V_45 = F_17 ( V_24 ) ;
if ( ( V_45 & V_46 ) == V_47 ) {
F_5 ( L_12 , V_29 ) ;
switch ( V_45 & V_37 ) {
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
F_5 ( L_13 , V_29 ) ;
goto V_48;
break;
}
F_5 ( L_14 ,
V_29 , V_33 -> V_34 , V_33 -> V_5 ) ;
memcpy ( & V_33 -> V_43 , & V_24 -> V_30 [ 0 ] , 2 ) ;
F_14 ( V_24 , 2 ) ;
} else {
F_5 ( L_15 , V_29 ) ;
goto V_48;
}
return 0 ;
V_48:
return - V_31 ;
}
static int F_22 ( struct V_23 * V_24 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_49 ,
const void * V_50 , unsigned int V_11 )
{
T_1 V_45 , V_51 , V_52 , * V_15 ;
struct V_53 * V_54 ;
const T_1 * V_55 = V_50 ;
const T_1 * V_56 = V_49 ;
T_1 * V_57 ;
struct V_58 V_59 , V_60 ;
if ( type != V_61 )
return 0 ;
V_57 = F_23 ( 100 , V_62 ) ;
if ( V_57 == NULL )
return - V_63 ;
V_54 = F_24 ( V_24 ) ;
V_15 = V_57 + 2 ;
F_5 ( L_16
L_17 , V_29 ,
V_54 -> V_64 , F_25 ( V_54 -> V_65 ) , V_54 -> V_66 ,
V_54 -> V_67 ) ;
F_7 ( V_29 , L_18 ,
F_26 ( V_24 ) , sizeof( struct V_53 ) ) ;
if ( ! V_55 )
V_55 = V_3 -> V_68 ;
F_3 ( V_29 , L_19 , ( unsigned char * ) V_55 , 8 ) ;
V_51 = V_69 ;
V_52 = 0 ;
F_3 ( V_29 , L_20 , ( unsigned char * ) V_56 , 8 ) ;
V_45 = ( V_54 -> V_70 << 4 ) | ( V_54 -> V_71 [ 0 ] >> 4 ) ;
V_45 = ( ( V_45 & 0x03 ) << 6 ) | ( V_45 >> 2 ) ;
if ( ( ( V_54 -> V_71 [ 0 ] & 0x0F ) == 0 ) &&
( V_54 -> V_71 [ 1 ] == 0 ) && ( V_54 -> V_71 [ 2 ] == 0 ) ) {
V_51 |= V_72 ;
if ( ( V_54 -> V_70 == 0 ) &&
( ( V_54 -> V_71 [ 0 ] & 0xF0 ) == 0 ) ) {
V_51 |= V_73 ;
} else {
* V_15 = V_45 ;
V_15 += 1 ;
}
} else {
if ( ( V_54 -> V_70 == 0 ) &&
( ( V_54 -> V_71 [ 0 ] & 0xF0 ) == 0 ) ) {
V_51 |= V_73 ;
* V_15 = ( V_45 & 0xc0 ) | ( V_54 -> V_71 [ 0 ] & 0x0F ) ;
memcpy ( V_15 + 1 , & V_54 -> V_71 [ 1 ] , 2 ) ;
V_15 += 3 ;
} else {
memcpy ( V_15 , & V_54 , 4 ) ;
* V_15 = V_45 ;
V_15 += 4 ;
}
}
if ( V_54 -> V_66 == V_74 )
V_51 |= V_75 ;
if ( ( V_51 & V_75 ) == 0 ) {
* V_15 = V_54 -> V_66 ;
V_15 += 1 ;
}
switch ( V_54 -> V_67 ) {
case 1 :
V_51 |= V_76 ;
break;
case 64 :
V_51 |= V_77 ;
break;
case 255 :
V_51 |= V_78 ;
break;
default:
* V_15 = V_54 -> V_67 ;
break;
}
if ( F_27 ( & V_54 -> V_55 ) ) {
F_5 ( L_21 ,
V_29 ) ;
V_52 |= V_79 ;
} else if ( F_28 ( & V_54 -> V_55 ) ) {
F_5 ( L_22 , V_29 ) ;
V_52 |= F_8 ( & V_15 ,
V_80 , & V_54 -> V_55 , V_55 ) ;
} else {
F_5 ( L_23 , V_29 ) ;
memcpy ( V_15 , & V_54 -> V_55 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
if ( F_29 ( & V_54 -> V_56 ) ) {
F_5 ( L_24 , V_29 ) ;
V_52 |= V_81 ;
if ( F_30 ( & V_54 -> V_56 ) ) {
F_5 ( L_25 ) ;
V_52 |= V_82 ;
* V_15 = V_54 -> V_56 . V_22 [ 15 ] ;
V_15 += 1 ;
} else if ( F_31 ( & V_54 -> V_56 ) ) {
F_5 ( L_26 ) ;
V_52 |= V_83 ;
* V_15 = V_54 -> V_56 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_54 -> V_56 . V_22 [ 13 ] , 3 ) ;
V_15 += 4 ;
} else if ( F_32 ( & V_54 -> V_56 ) ) {
F_5 ( L_27 ) ;
V_52 |= V_84 ;
* V_15 = V_54 -> V_56 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_54 -> V_56 . V_22 [ 11 ] , 5 ) ;
V_15 += 6 ;
} else {
F_5 ( L_28 ) ;
V_52 |= V_85 ;
memcpy ( V_15 , & V_54 -> V_56 . V_22 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
} else {
F_5 ( L_29 , V_29 ) ;
if ( F_28 ( & V_54 -> V_56 ) ) {
F_5 ( L_30 ) ;
V_52 |= F_8 ( & V_15 ,
V_86 , & V_54 -> V_56 , V_56 ) ;
} else {
F_5 ( L_28 ) ;
memcpy ( V_15 , & V_54 -> V_56 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
}
if ( V_54 -> V_66 == V_74 )
F_15 ( & V_15 , V_24 ) ;
V_57 [ 0 ] = V_51 ;
V_57 [ 1 ] = V_52 ;
F_14 ( V_24 , sizeof( struct V_53 ) ) ;
memcpy ( F_33 ( V_24 , V_15 - V_57 ) , V_57 , V_15 - V_57 ) ;
F_34 ( V_57 ) ;
F_7 ( V_29 , L_31 , V_24 -> V_30 ,
V_24 -> V_11 ) ;
{
V_59 . V_87 = V_88 ;
V_59 . V_89 = 0xff ;
V_60 . V_87 = V_88 ;
V_60 . V_89 = 0xff ;
memcpy ( & ( V_60 . V_90 ) , V_56 , 8 ) ;
memcpy ( & ( V_59 . V_90 ) , V_55 , 8 ) ;
F_35 ( V_24 ) -> V_91 = V_92 ;
return F_36 ( V_24 , V_1 ( V_3 ) -> V_93 ,
type , ( void * ) & V_60 , ( void * ) & V_59 , V_24 -> V_11 ) ;
}
}
static int F_37 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
struct V_23 * V_94 ;
struct V_95 * V_96 ;
int V_97 = V_98 ;
V_94 = F_38 ( V_24 , sizeof( struct V_53 ) , F_39 ( V_24 ) ,
V_99 ) ;
F_40 ( V_24 ) ;
if ( ! V_94 )
return - V_63 ;
F_33 ( V_94 , sizeof( struct V_53 ) ) ;
F_41 ( V_94 ) ;
F_42 ( V_94 , V_54 , sizeof( struct V_53 ) ) ;
V_94 -> V_100 = F_43 ( V_61 ) ;
V_94 -> V_101 = V_102 ;
F_44 () ;
F_45 (entry, &lowpan_devices, list)
if ( V_1 ( V_96 -> V_103 ) -> V_93 == V_94 -> V_3 ) {
V_24 = F_46 ( V_94 , V_99 ) ;
if ( ! V_24 ) {
V_97 = - V_63 ;
break;
}
V_24 -> V_3 = V_96 -> V_103 ;
V_97 = F_47 ( V_24 ) ;
}
F_48 () ;
F_40 ( V_94 ) ;
return V_97 ;
}
static void F_49 ( unsigned long V_104 )
{
struct V_105 * V_96 = (struct V_105 * ) V_104 ;
F_5 ( L_32 , V_29 ,
V_96 -> V_106 ) ;
F_50 ( & V_107 ) ;
F_51 ( & V_96 -> V_108 ) ;
F_52 ( & V_107 ) ;
F_53 ( V_96 -> V_24 ) ;
F_34 ( V_96 ) ;
}
static struct V_105 *
F_54 ( struct V_23 * V_24 , T_1 V_51 , T_1 V_11 , T_1 V_106 )
{
struct V_105 * V_109 ;
V_109 = F_23 ( sizeof( struct V_105 ) ,
V_99 ) ;
if ( ! V_109 )
goto V_110;
F_55 ( & V_109 -> V_108 ) ;
V_109 -> V_111 = ( V_51 & 7 ) | ( V_11 << 3 ) ;
V_109 -> V_106 = V_106 ;
V_109 -> V_24 = F_56 ( V_109 -> V_111 +
sizeof( struct V_53 ) , V_99 ) ;
if ( ! V_109 -> V_24 )
goto V_112;
V_109 -> V_24 -> V_70 = V_24 -> V_70 ;
V_109 -> V_24 -> V_3 = V_24 -> V_3 ;
F_57 ( V_109 -> V_24 , sizeof( struct V_53 ) ) ;
F_58 ( V_109 -> V_24 , V_109 -> V_111 ) ;
F_59 ( & V_109 -> V_113 ) ;
V_109 -> V_113 . V_114 = V_115 + V_116 ;
V_109 -> V_113 . V_30 = ( unsigned long ) V_109 ;
V_109 -> V_113 . V_117 = F_49 ;
F_60 ( & V_109 -> V_113 ) ;
F_61 ( & V_109 -> V_108 , & V_118 ) ;
return V_109 ;
V_112:
F_34 ( V_109 ) ;
V_110:
return NULL ;
}
static int
F_62 ( struct V_23 * V_24 )
{
struct V_53 V_54 ;
T_1 V_45 , V_51 , V_52 , V_119 = 0 ;
T_1 * V_50 , * V_49 ;
int V_48 ;
F_7 ( V_29 , L_31 , V_24 -> V_30 ,
V_24 -> V_11 ) ;
if ( V_24 -> V_11 < 2 )
goto V_120;
V_51 = F_17 ( V_24 ) ;
switch ( V_51 & V_121 ) {
case V_122 :
case V_123 :
{
struct V_105 * V_109 ;
T_1 V_11 , V_124 ;
T_2 V_106 ;
bool V_125 = false ;
V_11 = F_17 ( V_24 ) ;
V_106 = F_18 ( V_24 ) ;
F_50 ( & V_107 ) ;
F_63 (frame, &lowpan_fragments, list)
if ( V_109 -> V_106 == V_106 ) {
V_125 = true ;
break;
}
if ( ! V_125 ) {
V_109 = F_54 ( V_24 , V_51 , V_11 , V_106 ) ;
if ( ! V_109 )
goto V_126;
}
if ( ( V_51 & V_121 ) == V_122 )
goto V_126;
V_124 = F_17 ( V_24 ) ;
if ( F_64 ( ( V_124 * 8 + V_24 -> V_11 ) <= V_109 -> V_111 ) )
F_65 ( V_109 -> V_24 , V_124 * 8 ,
V_24 -> V_30 , V_24 -> V_11 ) ;
else
goto V_126;
V_109 -> V_127 += V_24 -> V_11 ;
if ( ( V_109 -> V_127 == V_109 -> V_111 ) &&
V_109 -> V_113 . V_114 > V_115 ) {
F_66 ( & V_109 -> V_113 ) ;
F_51 ( & V_109 -> V_108 ) ;
F_52 ( & V_107 ) ;
F_53 ( V_24 ) ;
V_24 = V_109 -> V_24 ;
F_34 ( V_109 ) ;
V_51 = F_17 ( V_24 ) ;
break;
}
F_52 ( & V_107 ) ;
return F_40 ( V_24 ) , 0 ;
}
default:
break;
}
V_52 = F_17 ( V_24 ) ;
V_50 = F_35 ( V_24 ) -> V_59 . V_90 ;
V_49 = F_35 ( V_24 ) -> V_60 . V_90 ;
F_5 ( L_33 , V_29 , V_51 , V_52 ) ;
if ( V_52 & V_128 ) {
F_5 ( L_34 ,
V_29 ) ;
if ( ! V_24 -> V_11 )
goto V_120;
V_119 = F_17 ( V_24 ) ;
}
V_54 . V_64 = 6 ;
switch ( ( V_51 & V_129 ) >> 3 ) {
case 0 :
if ( ! V_24 -> V_11 )
goto V_120;
V_45 = F_17 ( V_24 ) ;
memcpy ( & V_54 . V_71 , & V_24 -> V_30 [ 0 ] , 3 ) ;
F_14 ( V_24 , 3 ) ;
V_54 . V_70 = ( ( V_45 >> 2 ) & 0x0f ) ;
V_54 . V_71 [ 0 ] = ( ( V_45 >> 2 ) & 0x30 ) | ( V_45 << 6 ) |
( V_54 . V_71 [ 0 ] & 0x0f ) ;
break;
case 1 :
if ( ! V_24 -> V_11 )
goto V_120;
V_45 = F_17 ( V_24 ) ;
V_54 . V_70 = ( ( V_45 >> 2 ) & 0x0f ) ;
V_54 . V_71 [ 0 ] = ( ( V_45 << 6 ) & 0xC0 ) | ( ( V_45 >> 2 ) & 0x30 ) ;
V_54 . V_71 [ 1 ] = 0 ;
V_54 . V_71 [ 2 ] = 0 ;
break;
case 2 :
if ( ! V_24 -> V_11 )
goto V_120;
V_45 = F_17 ( V_24 ) ;
V_54 . V_71 [ 0 ] = ( V_24 -> V_30 [ 0 ] & 0x0F ) | ( ( V_45 >> 2 ) & 0x30 ) ;
memcpy ( & V_54 . V_71 [ 1 ] , & V_24 -> V_30 [ 0 ] , 2 ) ;
F_14 ( V_24 , 2 ) ;
break;
case 3 :
V_54 . V_70 = 0 ;
V_54 . V_71 [ 0 ] = 0 ;
V_54 . V_71 [ 1 ] = 0 ;
V_54 . V_71 [ 2 ] = 0 ;
break;
default:
break;
}
if ( ( V_51 & V_75 ) == 0 ) {
if ( ! V_24 -> V_11 )
goto V_120;
V_54 . V_66 = F_17 ( V_24 ) ;
F_5 ( L_35
L_36 , V_29 , V_54 . V_66 ) ;
}
if ( ( V_51 & 0x03 ) != V_130 )
V_54 . V_67 = V_131 [ V_51 & 0x03 ] ;
else {
if ( ! V_24 -> V_11 )
goto V_120;
V_54 . V_67 = F_17 ( V_24 ) ;
}
V_45 = ( ( V_52 & V_132 ) >> V_80 ) & 0x03 ;
F_5 ( L_37 , V_29 ) ;
V_48 = F_13 ( V_24 , & V_54 . V_55 , V_133 ,
V_134 [ V_45 ] , V_24 -> V_30 ) ;
if ( V_48 )
goto V_120;
V_45 = ( ( V_52 & V_82 ) >> V_86 ) & 0x03 ;
if ( V_52 & V_81 ) {
if ( V_52 & V_135 ) {
F_5 ( L_38
L_39 , V_29 ) ;
} else {
T_1 V_25 [] = { 0xff , 0x02 } ;
F_5 ( L_40
L_41 , V_29 ) ;
if ( 0 < V_45 && V_45 < 3 ) {
if ( ! V_24 -> V_11 )
goto V_120;
else
V_25 [ 1 ] = F_17 ( V_24 ) ;
}
V_48 = F_13 ( V_24 , & V_54 . V_56 , V_25 ,
V_136 [ V_45 ] , NULL ) ;
if ( V_48 )
goto V_120;
}
} else {
F_5 ( L_42 ,
V_29 ) ;
V_48 = F_13 ( V_24 , & V_54 . V_56 , V_133 ,
V_134 [ V_45 ] , V_24 -> V_30 ) ;
if ( V_48 )
goto V_120;
}
if ( V_51 & V_75 )
if ( F_21 ( V_24 ) )
goto V_120;
V_54 . V_65 = F_43 ( V_24 -> V_11 ) ;
F_5 ( L_43 , V_29 ,
F_67 ( V_24 ) , V_24 -> V_11 ) ;
F_5 ( L_44
L_45 , V_29 , V_54 . V_64 ,
F_25 ( V_54 . V_65 ) , V_54 . V_66 , V_54 . V_67 ) ;
F_7 ( V_29 , L_46 , ( T_1 * ) & V_54 ,
sizeof( V_54 ) ) ;
return F_37 ( V_24 , & V_54 ) ;
V_126:
F_52 ( & V_107 ) ;
V_120:
F_40 ( V_24 ) ;
return - V_31 ;
}
static int F_68 ( struct V_23 * V_24 )
{
return 21 ;
}
static int
F_69 ( struct V_23 * V_24 , T_1 * V_57 ,
int V_137 , int V_138 , int V_124 )
{
struct V_23 * V_139 ;
int V_140 , V_44 ;
V_140 = ( V_138 == 0 ? V_141 : V_142 ) ;
F_3 ( V_29 , L_47 , V_57 , V_140 ) ;
V_139 = F_70 ( V_140 + V_137 + V_138 + V_143 ) ;
if ( ! V_139 )
return - V_63 ;
V_139 -> V_70 = V_24 -> V_70 ;
V_139 -> V_3 = V_24 -> V_3 ;
memcpy ( F_58 ( V_139 , V_137 ) , V_24 -> V_30 , V_137 ) ;
memcpy ( F_58 ( V_139 , V_140 ) , V_57 , V_140 ) ;
if ( V_138 )
F_71 ( V_24 , V_124 + V_137 ,
F_58 ( V_139 , V_138 ) , V_138 ) ;
F_7 ( V_29 , L_48 , V_139 -> V_30 ,
V_139 -> V_11 ) ;
V_44 = F_72 ( V_139 ) ;
return V_44 ;
}
static int
F_73 ( struct V_23 * V_24 )
{
int V_48 , V_144 , V_145 , V_106 , V_124 = 0 ;
T_1 V_57 [ 5 ] ;
V_144 = F_68 ( V_24 ) ;
V_145 = V_24 -> V_11 - V_144 ;
V_106 = V_146 ++ ;
V_57 [ 0 ] = V_122 | ( V_145 & 0x7 ) ;
V_57 [ 1 ] = ( V_145 >> 3 ) & 0xff ;
V_57 [ 2 ] = V_106 & 0xff ;
V_57 [ 3 ] = V_106 >> 8 ;
V_48 = F_69 ( V_24 , V_57 , V_144 , 0 , 0 ) ;
V_57 [ 0 ] &= ~ V_122 ;
V_57 [ 0 ] |= V_123 ;
while ( ( V_145 - V_124 > 0 ) && ( V_48 >= 0 ) ) {
int V_11 = V_147 ;
V_57 [ 4 ] = V_124 / 8 ;
if ( V_145 - V_124 < V_11 )
V_11 = V_145 - V_124 ;
V_48 = F_69 ( V_24 , V_57 , V_144 ,
V_11 , V_124 ) ;
V_124 += V_11 ;
}
return V_48 ;
}
static T_3 F_74 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
int V_48 = - 1 ;
F_5 ( L_49 , V_29 ) ;
V_24 -> V_3 = V_1 ( V_3 ) -> V_93 ;
if ( V_24 -> V_3 == NULL ) {
F_5 ( L_50 , V_29 ) ;
goto error;
}
if ( V_24 -> V_11 <= V_148 ) {
V_48 = F_72 ( V_24 ) ;
goto V_149;
}
F_5 ( L_51 ,
V_29 ) ;
V_48 = F_73 ( V_24 ) ;
error:
F_53 ( V_24 ) ;
V_149:
if ( V_48 < 0 )
F_5 ( L_52 , V_29 ) ;
return ( V_48 < 0 ? V_150 : V_151 ) ;
}
static void F_75 ( struct V_2 * V_3 )
{
F_76 ( V_1 ( V_3 ) -> V_93 ) ;
F_77 ( V_3 ) ;
}
static struct V_152 * F_78 ( const struct V_2 * V_3 )
{
struct V_2 * V_93 = V_1 ( V_3 ) -> V_93 ;
return F_79 ( V_93 ) -> F_80 ( V_93 ) ;
}
static T_2 F_81 ( const struct V_2 * V_3 )
{
struct V_2 * V_93 = V_1 ( V_3 ) -> V_93 ;
return F_79 ( V_93 ) -> F_82 ( V_93 ) ;
}
static T_2 F_83 ( const struct V_2 * V_3 )
{
struct V_2 * V_93 = V_1 ( V_3 ) -> V_93 ;
return F_79 ( V_93 ) -> F_84 ( V_93 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
F_5 ( L_53 , V_29 ) ;
V_3 -> V_153 = V_7 ;
memset ( V_3 -> V_154 , 0xff , V_7 ) ;
V_3 -> type = V_155 ;
V_3 -> V_156 = 2 + 1 + 20 + 14 ;
V_3 -> V_157 = 2 ;
V_3 -> V_158 = 1281 ;
V_3 -> V_159 = 0 ;
V_3 -> V_91 = V_160 | V_161 ;
V_3 -> V_162 = 0 ;
V_3 -> V_163 = & V_164 ;
V_3 -> V_165 = & V_166 ;
V_3 -> V_167 = & V_168 ;
V_3 -> V_169 = F_75 ;
}
static int F_86 ( struct V_170 * V_171 [] , struct V_170 * V_30 [] )
{
F_5 ( L_53 , V_29 ) ;
if ( V_171 [ V_172 ] ) {
if ( F_87 ( V_171 [ V_172 ] ) != V_7 )
return - V_31 ;
}
return 0 ;
}
static int F_88 ( struct V_23 * V_24 , struct V_2 * V_3 ,
struct V_173 * V_174 , struct V_2 * V_175 )
{
if ( ! F_89 ( V_3 ) )
goto V_120;
if ( V_3 -> type != V_155 )
goto V_120;
switch ( V_24 -> V_30 [ 0 ] & 0xe0 ) {
case V_69 :
case V_122 :
case V_123 :
F_62 ( V_24 ) ;
break;
default:
break;
}
return V_98 ;
V_120:
F_40 ( V_24 ) ;
return V_176 ;
}
static int F_90 ( struct V_177 * V_178 , struct V_2 * V_3 ,
struct V_170 * V_171 [] , struct V_170 * V_30 [] )
{
struct V_2 * V_93 ;
struct V_95 * V_96 ;
F_5 ( L_53 , V_29 ) ;
if ( ! V_171 [ V_179 ] )
return - V_31 ;
V_93 = F_91 ( V_178 , F_92 ( V_171 [ V_179 ] ) ) ;
if ( ! V_93 )
return - V_180 ;
V_1 ( V_3 ) -> V_93 = V_93 ;
F_93 ( & V_1 ( V_3 ) -> V_181 ) ;
V_96 = F_23 ( sizeof( struct V_95 ) , V_62 ) ;
if ( ! V_96 ) {
F_76 ( V_93 ) ;
V_1 ( V_3 ) -> V_93 = NULL ;
return - V_63 ;
}
V_96 -> V_103 = V_3 ;
F_94 ( & V_1 ( V_3 ) -> V_181 ) ;
F_55 ( & V_96 -> V_108 ) ;
F_61 ( & V_96 -> V_108 , & V_182 ) ;
F_95 ( & V_1 ( V_3 ) -> V_181 ) ;
F_96 ( & V_107 ) ;
F_97 ( V_3 ) ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 , struct V_183 * V_57 )
{
struct V_1 * V_184 = V_1 ( V_3 ) ;
struct V_2 * V_93 = V_184 -> V_93 ;
struct V_95 * V_96 , * V_45 ;
struct V_105 * V_109 , * V_185 ;
F_99 () ;
F_50 ( & V_107 ) ;
F_100 (frame, tframe, &lowpan_fragments, list) {
F_66 ( & V_109 -> V_113 ) ;
F_51 ( & V_109 -> V_108 ) ;
F_53 ( V_109 -> V_24 ) ;
F_34 ( V_109 ) ;
}
F_52 ( & V_107 ) ;
F_94 ( & V_1 ( V_3 ) -> V_181 ) ;
F_100 (entry, tmp, &lowpan_devices, list) {
if ( V_96 -> V_103 == V_3 ) {
F_51 ( & V_96 -> V_108 ) ;
F_34 ( V_96 ) ;
}
}
F_95 ( & V_1 ( V_3 ) -> V_181 ) ;
F_101 ( & V_1 ( V_3 ) -> V_181 ) ;
F_102 ( V_3 , V_57 ) ;
F_76 ( V_93 ) ;
}
static inline int T_4 F_103 ( void )
{
return F_104 ( & V_186 ) ;
}
static inline void T_4 F_105 ( void )
{
F_106 ( & V_186 ) ;
}
static int T_4 F_107 ( void )
{
int V_48 = 0 ;
F_5 ( L_53 , V_29 ) ;
V_48 = F_103 () ;
if ( V_48 < 0 )
goto V_149;
F_108 ( & V_187 ) ;
V_149:
return V_48 ;
}
static void T_5 F_109 ( void )
{
F_5 ( L_53 , V_29 ) ;
F_105 () ;
F_110 ( & V_187 ) ;
}
