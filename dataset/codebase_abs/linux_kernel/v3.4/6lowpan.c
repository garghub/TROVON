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
static void
F_15 ( T_1 * * V_15 , struct V_24 * V_25 )
{
struct V_33 * V_34 = F_16 ( V_25 ) ;
F_5 ( L_7 , V_30 ) ;
if ( ( ( V_34 -> V_35 & V_36 ) ==
V_37 ) &&
( ( V_34 -> V_5 & V_36 ) ==
V_37 ) ) {
F_5 ( L_8 , V_30 ) ;
* * V_15 = V_38 ;
* * ( V_15 + 1 ) =
( T_1 ) ( ( V_34 -> V_5 - V_37 ) +
( ( V_34 -> V_35 & V_37 ) << 4 ) ) ;
* V_15 += 2 ;
} else if ( ( V_34 -> V_5 & V_39 ) ==
V_40 ) {
F_5 ( L_9 , V_30 ) ;
* * V_15 = V_41 ;
memcpy ( * V_15 + 1 , & V_34 -> V_35 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_34 -> V_5 - V_40 ) ;
* V_15 += 4 ;
} else if ( ( V_34 -> V_35 & V_39 ) ==
V_40 ) {
F_5 ( L_10 , V_30 ) ;
* * V_15 = V_42 ;
memcpy ( * V_15 + 1 , & V_34 -> V_5 , 2 ) ;
* * ( V_15 + 3 ) = ( T_1 ) ( V_34 -> V_35 - V_40 ) ;
* V_15 += 4 ;
} else {
F_5 ( L_11 , V_30 ) ;
* * V_15 = V_43 ;
memcpy ( * V_15 + 1 , & V_34 -> V_35 , 2 ) ;
memcpy ( * V_15 + 3 , & V_34 -> V_5 , 2 ) ;
* V_15 += 5 ;
}
memcpy ( * V_15 , & V_34 -> V_44 , 2 ) ;
* V_15 += 2 ;
}
static T_1 F_17 ( struct V_24 * V_25 )
{
T_1 V_45 ;
V_45 = V_25 -> V_31 [ 0 ] ;
F_14 ( V_25 , 1 ) ;
return V_45 ;
}
static T_2 F_18 ( struct V_24 * V_25 )
{
T_2 V_45 ;
F_19 ( ! F_20 ( V_25 , 2 ) ) ;
V_45 = V_25 -> V_31 [ 0 ] | ( V_25 -> V_31 [ 1 ] << 8 ) ;
F_14 ( V_25 , 2 ) ;
return V_45 ;
}
static int
F_21 ( struct V_24 * V_25 )
{
struct V_33 * V_34 = F_16 ( V_25 ) ;
T_1 V_46 ;
V_46 = F_17 ( V_25 ) ;
if ( ( V_46 & V_47 ) == V_48 ) {
F_5 ( L_12 , V_30 ) ;
switch ( V_46 & V_38 ) {
case V_43 :
memcpy ( & V_34 -> V_35 , & V_25 -> V_31 [ 0 ] , 2 ) ;
memcpy ( & V_34 -> V_5 , & V_25 -> V_31 [ 2 ] , 2 ) ;
F_14 ( V_25 , 4 ) ;
break;
case V_41 :
memcpy ( & V_34 -> V_35 , & V_25 -> V_31 [ 0 ] , 2 ) ;
V_34 -> V_5 =
V_25 -> V_31 [ 2 ] + V_40 ;
F_14 ( V_25 , 3 ) ;
break;
case V_42 :
V_34 -> V_35 = V_25 -> V_31 [ 0 ] + V_40 ;
memcpy ( & V_34 -> V_5 , & V_25 -> V_31 [ 1 ] , 2 ) ;
F_14 ( V_25 , 3 ) ;
break;
case V_38 :
V_34 -> V_35 =
V_37 + ( V_25 -> V_31 [ 0 ] >> 4 ) ;
V_34 -> V_5 =
V_37 + ( V_25 -> V_31 [ 0 ] & 0x0f ) ;
F_14 ( V_25 , 1 ) ;
break;
default:
F_5 ( L_13 , V_30 ) ;
goto V_49;
break;
}
F_5 ( L_14 ,
V_30 , V_34 -> V_35 , V_34 -> V_5 ) ;
memcpy ( & V_34 -> V_44 , & V_25 -> V_31 [ 0 ] , 2 ) ;
F_14 ( V_25 , 2 ) ;
} else {
F_5 ( L_15 , V_30 ) ;
goto V_49;
}
return 0 ;
V_49:
return - V_32 ;
}
static int F_22 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_50 ,
const void * V_51 , unsigned V_11 )
{
T_1 V_46 , V_52 , V_53 , * V_15 ;
struct V_54 * V_55 ;
const T_1 * V_56 = V_51 ;
const T_1 * V_57 = V_50 ;
T_1 * V_58 ;
struct V_59 V_60 , V_61 ;
if ( type != V_62 )
return 0 ;
V_58 = F_23 ( 100 , V_63 ) ;
if ( V_58 == NULL )
return - V_64 ;
V_55 = F_24 ( V_25 ) ;
V_15 = V_58 + 2 ;
F_5 ( L_16
L_17 , V_30 ,
V_55 -> V_65 , F_25 ( V_55 -> V_66 ) , V_55 -> V_67 ,
V_55 -> V_68 ) ;
F_7 ( V_30 , L_18 ,
F_26 ( V_25 ) , sizeof( struct V_54 ) ) ;
if ( ! V_56 )
V_56 = V_3 -> V_69 ;
F_3 ( V_30 , L_19 , ( unsigned char * ) V_56 , 8 ) ;
V_52 = V_70 ;
V_53 = 0 ;
F_3 ( V_30 , L_20 , ( unsigned char * ) V_57 , 8 ) ;
V_46 = ( V_55 -> V_71 << 4 ) | ( V_55 -> V_72 [ 0 ] >> 4 ) ;
V_46 = ( ( V_46 & 0x03 ) << 6 ) | ( V_46 >> 2 ) ;
if ( ( ( V_55 -> V_72 [ 0 ] & 0x0F ) == 0 ) &&
( V_55 -> V_72 [ 1 ] == 0 ) && ( V_55 -> V_72 [ 2 ] == 0 ) ) {
V_52 |= V_73 ;
if ( ( V_55 -> V_71 == 0 ) &&
( ( V_55 -> V_72 [ 0 ] & 0xF0 ) == 0 ) ) {
V_52 |= V_74 ;
} else {
* V_15 = V_46 ;
V_15 += 1 ;
}
} else {
if ( ( V_55 -> V_71 == 0 ) &&
( ( V_55 -> V_72 [ 0 ] & 0xF0 ) == 0 ) ) {
V_52 |= V_74 ;
* V_15 = ( V_46 & 0xc0 ) | ( V_55 -> V_72 [ 0 ] & 0x0F ) ;
memcpy ( V_15 + 1 , & V_55 -> V_72 [ 1 ] , 2 ) ;
V_15 += 3 ;
} else {
memcpy ( V_15 , & V_55 , 4 ) ;
* V_15 = V_46 ;
V_15 += 4 ;
}
}
if ( V_55 -> V_67 == V_75 )
V_52 |= V_76 ;
if ( ( V_52 & V_76 ) == 0 ) {
* V_15 = V_55 -> V_67 ;
V_15 += 1 ;
}
switch ( V_55 -> V_68 ) {
case 1 :
V_52 |= V_77 ;
break;
case 64 :
V_52 |= V_78 ;
break;
case 255 :
V_52 |= V_79 ;
break;
default:
* V_15 = V_55 -> V_68 ;
break;
}
if ( F_27 ( & V_55 -> V_56 ) ) {
F_5 ( L_21 ,
V_30 ) ;
V_53 |= V_80 ;
} else if ( F_28 ( & V_55 -> V_56 ) ) {
F_5 ( L_22 , V_30 ) ;
V_53 |= F_8 ( & V_15 ,
V_81 , & V_55 -> V_56 , V_56 ) ;
} else {
F_5 ( L_23 , V_30 ) ;
memcpy ( V_15 , & V_55 -> V_56 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
if ( F_29 ( & V_55 -> V_57 ) ) {
F_5 ( L_24 , V_30 ) ;
V_53 |= V_82 ;
if ( F_30 ( & V_55 -> V_57 ) ) {
F_5 ( L_25 ) ;
V_53 |= V_83 ;
* V_15 = V_55 -> V_57 . V_22 [ 15 ] ;
V_15 += 1 ;
} else if ( F_31 ( & V_55 -> V_57 ) ) {
F_5 ( L_26 ) ;
V_53 |= V_84 ;
* V_15 = V_55 -> V_57 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_55 -> V_57 . V_22 [ 13 ] , 3 ) ;
V_15 += 4 ;
} else if ( F_32 ( & V_55 -> V_57 ) ) {
F_5 ( L_27 ) ;
V_53 |= V_85 ;
* V_15 = V_55 -> V_57 . V_22 [ 1 ] ;
memcpy ( V_15 + 1 , & V_55 -> V_57 . V_22 [ 11 ] , 5 ) ;
V_15 += 6 ;
} else {
F_5 ( L_28 ) ;
V_53 |= V_86 ;
memcpy ( V_15 , & V_55 -> V_57 . V_22 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
} else {
F_5 ( L_29 , V_30 ) ;
if ( F_28 ( & V_55 -> V_57 ) ) {
F_5 ( L_30 ) ;
V_53 |= F_8 ( & V_15 ,
V_87 , & V_55 -> V_57 , V_57 ) ;
} else {
F_5 ( L_28 ) ;
memcpy ( V_15 , & V_55 -> V_57 . V_21 [ 0 ] , 16 ) ;
V_15 += 16 ;
}
}
if ( V_55 -> V_67 == V_75 )
F_15 ( & V_15 , V_25 ) ;
V_58 [ 0 ] = V_52 ;
V_58 [ 1 ] = V_53 ;
F_14 ( V_25 , sizeof( struct V_54 ) ) ;
memcpy ( F_33 ( V_25 , V_15 - V_58 ) , V_58 , V_15 - V_58 ) ;
F_34 ( V_58 ) ;
F_7 ( V_30 , L_31 , V_25 -> V_31 ,
V_25 -> V_11 ) ;
{
V_60 . V_88 = V_89 ;
V_60 . V_90 = 0xff ;
V_61 . V_88 = V_89 ;
V_61 . V_90 = 0xff ;
memcpy ( & ( V_61 . V_91 ) , V_57 , 8 ) ;
memcpy ( & ( V_60 . V_91 ) , V_56 , 8 ) ;
F_35 ( V_25 ) -> V_92 = V_93 ;
return F_36 ( V_25 , V_1 ( V_3 ) -> V_94 ,
type , ( void * ) & V_61 , ( void * ) & V_60 , V_25 -> V_11 ) ;
}
}
static int F_37 ( struct V_24 * V_25 , struct V_54 * V_55 )
{
struct V_24 * V_95 ;
struct V_96 * V_97 ;
int V_98 = V_99 ;
V_95 = F_38 ( V_25 , sizeof( struct V_54 ) , F_39 ( V_25 ) ,
V_100 ) ;
F_40 ( V_25 ) ;
if ( ! V_95 )
return - V_64 ;
F_33 ( V_95 , sizeof( struct V_54 ) ) ;
F_41 ( V_95 ) ;
F_42 ( V_95 , V_55 , sizeof( struct V_54 ) ) ;
V_95 -> V_101 = F_43 ( V_62 ) ;
V_95 -> V_102 = V_103 ;
F_44 () ;
F_45 (entry, &lowpan_devices, list)
if ( V_1 ( V_97 -> V_104 ) -> V_94 == V_95 -> V_3 ) {
V_25 = F_46 ( V_95 , V_100 ) ;
if ( ! V_25 ) {
V_98 = - V_64 ;
break;
}
V_25 -> V_3 = V_97 -> V_104 ;
V_98 = F_47 ( V_25 ) ;
}
F_48 () ;
F_40 ( V_95 ) ;
return V_98 ;
}
static void F_49 ( unsigned long V_105 )
{
struct V_106 * V_97 = (struct V_106 * ) V_105 ;
F_5 ( L_32 , V_30 ,
V_97 -> V_107 ) ;
F_50 ( & V_108 ) ;
F_51 ( & V_97 -> V_109 ) ;
F_52 ( & V_108 ) ;
F_53 ( V_97 -> V_25 ) ;
F_34 ( V_97 ) ;
}
static int
F_54 ( struct V_24 * V_25 )
{
struct V_54 V_55 ;
T_1 V_46 , V_52 , V_53 , V_110 = 0 ;
T_1 * V_51 , * V_50 ;
int V_49 ;
F_7 ( V_30 , L_31 , V_25 -> V_31 ,
V_25 -> V_11 ) ;
if ( V_25 -> V_11 < 2 )
goto V_111;
V_52 = F_17 ( V_25 ) ;
switch ( V_52 & V_112 ) {
case V_113 :
case V_114 :
{
struct V_106 * V_115 ;
T_1 V_11 , V_116 ;
T_2 V_107 ;
bool V_117 = false ;
V_11 = F_17 ( V_25 ) ;
V_107 = F_18 ( V_25 ) ;
F_50 ( & V_108 ) ;
F_55 (frame, &lowpan_fragments, list)
if ( V_115 -> V_107 == V_107 ) {
V_117 = true ;
break;
}
if ( ! V_117 ) {
V_115 = F_23 ( sizeof( struct V_106 ) ,
V_100 ) ;
if ( ! V_115 )
goto V_118;
F_56 ( & V_115 -> V_109 ) ;
V_115 -> V_119 = ( V_52 & 7 ) | ( V_11 << 3 ) ;
V_115 -> V_107 = V_107 ;
V_115 -> V_25 = F_57 ( V_115 -> V_119 +
sizeof( struct V_54 ) , V_100 ) ;
if ( ! V_115 -> V_25 ) {
F_34 ( V_115 ) ;
goto V_118;
}
V_115 -> V_25 -> V_71 = V_25 -> V_71 ;
V_115 -> V_25 -> V_3 = V_25 -> V_3 ;
F_58 ( V_115 -> V_25 , sizeof( struct V_54 ) ) ;
F_59 ( V_115 -> V_25 , V_115 -> V_119 ) ;
F_60 ( & V_115 -> V_120 ) ;
V_115 -> V_120 . V_121 = V_122 + V_123 ;
V_115 -> V_120 . V_31 = ( unsigned long ) V_115 ;
V_115 -> V_120 . V_124 = F_49 ;
F_61 ( & V_115 -> V_120 ) ;
F_62 ( & V_115 -> V_109 , & V_125 ) ;
}
if ( ( V_52 & V_112 ) == V_113 )
goto V_118;
V_116 = F_17 ( V_25 ) ;
if ( F_63 ( ( V_116 * 8 + V_25 -> V_11 ) <= V_115 -> V_119 ) )
F_64 ( V_115 -> V_25 , V_116 * 8 ,
V_25 -> V_31 , V_25 -> V_11 ) ;
else
goto V_118;
V_115 -> V_126 += V_25 -> V_11 ;
if ( ( V_115 -> V_126 == V_115 -> V_119 ) &&
V_115 -> V_120 . V_121 > V_122 ) {
F_65 ( & V_115 -> V_120 ) ;
F_51 ( & V_115 -> V_109 ) ;
F_52 ( & V_108 ) ;
F_53 ( V_25 ) ;
V_25 = V_115 -> V_25 ;
F_34 ( V_115 ) ;
V_52 = F_17 ( V_25 ) ;
break;
}
F_52 ( & V_108 ) ;
return F_40 ( V_25 ) , 0 ;
}
default:
break;
}
V_53 = F_17 ( V_25 ) ;
V_51 = F_35 ( V_25 ) -> V_60 . V_91 ;
V_50 = F_35 ( V_25 ) -> V_61 . V_91 ;
F_5 ( L_33 , V_30 , V_52 , V_53 ) ;
if ( V_53 & V_127 ) {
F_5 ( L_34 ,
V_30 ) ;
if ( ! V_25 -> V_11 )
goto V_111;
V_110 = F_17 ( V_25 ) ;
}
V_55 . V_65 = 6 ;
switch ( ( V_52 & V_128 ) >> 3 ) {
case 0 :
if ( ! V_25 -> V_11 )
goto V_111;
V_46 = F_17 ( V_25 ) ;
memcpy ( & V_55 . V_72 , & V_25 -> V_31 [ 0 ] , 3 ) ;
F_14 ( V_25 , 3 ) ;
V_55 . V_71 = ( ( V_46 >> 2 ) & 0x0f ) ;
V_55 . V_72 [ 0 ] = ( ( V_46 >> 2 ) & 0x30 ) | ( V_46 << 6 ) |
( V_55 . V_72 [ 0 ] & 0x0f ) ;
break;
case 1 :
if ( ! V_25 -> V_11 )
goto V_111;
V_46 = F_17 ( V_25 ) ;
V_55 . V_71 = ( ( V_46 >> 2 ) & 0x0f ) ;
V_55 . V_72 [ 0 ] = ( ( V_46 << 6 ) & 0xC0 ) | ( ( V_46 >> 2 ) & 0x30 ) ;
V_55 . V_72 [ 1 ] = 0 ;
V_55 . V_72 [ 2 ] = 0 ;
break;
case 2 :
if ( ! V_25 -> V_11 )
goto V_111;
V_46 = F_17 ( V_25 ) ;
V_55 . V_72 [ 0 ] = ( V_25 -> V_31 [ 0 ] & 0x0F ) | ( ( V_46 >> 2 ) & 0x30 ) ;
memcpy ( & V_55 . V_72 [ 1 ] , & V_25 -> V_31 [ 0 ] , 2 ) ;
F_14 ( V_25 , 2 ) ;
break;
case 3 :
V_55 . V_71 = 0 ;
V_55 . V_72 [ 0 ] = 0 ;
V_55 . V_72 [ 1 ] = 0 ;
V_55 . V_72 [ 2 ] = 0 ;
break;
default:
break;
}
if ( ( V_52 & V_76 ) == 0 ) {
if ( ! V_25 -> V_11 )
goto V_111;
V_55 . V_67 = F_17 ( V_25 ) ;
F_5 ( L_35
L_36 , V_30 , V_55 . V_67 ) ;
}
if ( ( V_52 & 0x03 ) != V_129 )
V_55 . V_68 = V_130 [ V_52 & 0x03 ] ;
else {
if ( ! V_25 -> V_11 )
goto V_111;
V_55 . V_68 = F_17 ( V_25 ) ;
}
V_46 = ( ( V_53 & V_131 ) >> V_81 ) & 0x03 ;
F_5 ( L_37 , V_30 ) ;
V_49 = F_13 ( V_25 , & V_55 . V_56 , V_132 ,
V_133 [ V_46 ] , V_25 -> V_31 ) ;
if ( V_49 )
goto V_111;
V_46 = ( ( V_53 & V_83 ) >> V_87 ) & 0x03 ;
if ( V_53 & V_82 ) {
if ( V_53 & V_134 ) {
F_5 ( L_38
L_39 , V_30 ) ;
} else {
T_1 V_26 [] = { 0xff , 0x02 } ;
F_5 ( L_40
L_41 , V_30 ) ;
if ( 0 < V_46 && V_46 < 3 ) {
if ( ! V_25 -> V_11 )
goto V_111;
else
V_26 [ 1 ] = F_17 ( V_25 ) ;
}
V_49 = F_13 ( V_25 , & V_55 . V_57 , V_26 ,
V_135 [ V_46 ] , NULL ) ;
if ( V_49 )
goto V_111;
}
} else {
F_5 ( L_42 ,
V_30 ) ;
V_49 = F_13 ( V_25 , & V_55 . V_57 , V_132 ,
V_133 [ V_46 ] , V_25 -> V_31 ) ;
if ( V_49 )
goto V_111;
}
if ( V_52 & V_76 )
if ( F_21 ( V_25 ) )
goto V_111;
V_55 . V_66 = F_43 ( V_25 -> V_11 ) ;
F_5 ( L_43 , V_30 ,
F_66 ( V_25 ) , V_25 -> V_11 ) ;
F_5 ( L_44
L_45 , V_30 , V_55 . V_65 ,
F_25 ( V_55 . V_66 ) , V_55 . V_67 , V_55 . V_68 ) ;
F_7 ( V_30 , L_46 , ( T_1 * ) & V_55 ,
sizeof( V_55 ) ) ;
return F_37 ( V_25 , & V_55 ) ;
V_118:
F_52 ( & V_108 ) ;
V_111:
F_40 ( V_25 ) ;
return - V_32 ;
}
static int F_67 ( struct V_24 * V_25 )
{
return 21 ;
}
static int
F_68 ( struct V_24 * V_25 , T_1 * V_58 ,
int V_136 , int V_137 , int V_116 )
{
struct V_24 * V_138 ;
int V_139 , V_45 ;
V_139 = ( V_137 == 0 ? V_140 : V_141 ) ;
F_3 ( V_30 , L_47 , V_58 , V_139 ) ;
V_138 = F_69 ( V_139 + V_136 + V_137 + V_142 ) ;
if ( ! V_138 )
return - V_64 ;
V_138 -> V_71 = V_25 -> V_71 ;
V_138 -> V_3 = V_25 -> V_3 ;
memcpy ( F_59 ( V_138 , V_136 ) , V_25 -> V_31 , V_136 ) ;
memcpy ( F_59 ( V_138 , V_139 ) , V_58 , V_139 ) ;
if ( V_137 )
F_70 ( V_25 , V_116 + V_136 ,
F_59 ( V_138 , V_137 ) , V_137 ) ;
F_7 ( V_30 , L_48 , V_138 -> V_31 ,
V_138 -> V_11 ) ;
V_45 = F_71 ( V_138 ) ;
return V_45 ;
}
static int
F_72 ( struct V_24 * V_25 )
{
int V_49 , V_143 , V_144 , V_107 , V_116 = 0 ;
T_1 V_58 [ 5 ] ;
V_143 = F_67 ( V_25 ) ;
V_144 = V_25 -> V_11 - V_143 ;
V_107 = V_145 ++ ;
V_58 [ 0 ] = V_113 | ( V_144 & 0x7 ) ;
V_58 [ 1 ] = ( V_144 >> 3 ) & 0xff ;
V_58 [ 2 ] = V_107 & 0xff ;
V_58 [ 3 ] = V_107 >> 8 ;
V_49 = F_68 ( V_25 , V_58 , V_143 , 0 , 0 ) ;
V_58 [ 0 ] &= ~ V_113 ;
V_58 [ 0 ] |= V_114 ;
while ( ( V_144 - V_116 > 0 ) && ( V_49 >= 0 ) ) {
int V_11 = V_146 ;
V_58 [ 4 ] = V_116 / 8 ;
if ( V_144 - V_116 < V_11 )
V_11 = V_144 - V_116 ;
V_49 = F_68 ( V_25 , V_58 , V_143 ,
V_11 , V_116 ) ;
V_116 += V_11 ;
}
return V_49 ;
}
static T_3 F_73 ( struct V_24 * V_25 , struct V_2 * V_3 )
{
int V_49 = - 1 ;
F_5 ( L_49 , V_30 ) ;
V_25 -> V_3 = V_1 ( V_3 ) -> V_94 ;
if ( V_25 -> V_3 == NULL ) {
F_5 ( L_50 , V_30 ) ;
goto error;
}
if ( V_25 -> V_11 <= V_147 ) {
V_49 = F_71 ( V_25 ) ;
goto V_148;
}
F_5 ( L_51 ,
V_30 ) ;
V_49 = F_72 ( V_25 ) ;
error:
F_53 ( V_25 ) ;
V_148:
if ( V_49 < 0 )
F_5 ( L_52 , V_30 ) ;
return ( V_49 < 0 ? V_149 : V_150 ) ;
}
static void F_74 ( struct V_2 * V_3 )
{
F_75 ( V_1 ( V_3 ) -> V_94 ) ;
F_76 ( V_3 ) ;
}
static struct V_151 * F_77 ( const struct V_2 * V_3 )
{
struct V_2 * V_94 = V_1 ( V_3 ) -> V_94 ;
return F_78 ( V_94 ) -> F_79 ( V_94 ) ;
}
static T_2 F_80 ( const struct V_2 * V_3 )
{
struct V_2 * V_94 = V_1 ( V_3 ) -> V_94 ;
return F_78 ( V_94 ) -> F_81 ( V_94 ) ;
}
static T_2 F_82 ( const struct V_2 * V_3 )
{
struct V_2 * V_94 = V_1 ( V_3 ) -> V_94 ;
return F_78 ( V_94 ) -> F_83 ( V_94 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
F_5 ( L_53 , V_30 ) ;
V_3 -> V_152 = V_7 ;
memset ( V_3 -> V_153 , 0xff , V_7 ) ;
V_3 -> type = V_154 ;
V_3 -> V_155 = 2 + 1 + 20 + 14 ;
V_3 -> V_156 = 2 ;
V_3 -> V_157 = 1281 ;
V_3 -> V_158 = 0 ;
V_3 -> V_92 = V_159 | V_160 ;
V_3 -> V_161 = 0 ;
V_3 -> V_162 = & V_163 ;
V_3 -> V_164 = & V_165 ;
V_3 -> V_166 = & V_167 ;
V_3 -> V_168 = F_74 ;
}
static int F_85 ( struct V_169 * V_170 [] , struct V_169 * V_31 [] )
{
F_5 ( L_53 , V_30 ) ;
if ( V_170 [ V_171 ] ) {
if ( F_86 ( V_170 [ V_171 ] ) != V_7 )
return - V_32 ;
}
return 0 ;
}
static int F_87 ( struct V_24 * V_25 , struct V_2 * V_3 ,
struct V_172 * V_173 , struct V_2 * V_174 )
{
if ( ! F_88 ( V_3 ) )
goto V_111;
if ( V_3 -> type != V_154 )
goto V_111;
switch ( V_25 -> V_31 [ 0 ] & 0xe0 ) {
case V_70 :
case V_113 :
case V_114 :
F_54 ( V_25 ) ;
break;
default:
break;
}
return V_99 ;
V_111:
F_40 ( V_25 ) ;
return V_175 ;
}
static int F_89 ( struct V_176 * V_177 , struct V_2 * V_3 ,
struct V_169 * V_170 [] , struct V_169 * V_31 [] )
{
struct V_2 * V_94 ;
struct V_96 * V_97 ;
F_5 ( L_53 , V_30 ) ;
if ( ! V_170 [ V_178 ] )
return - V_32 ;
V_94 = F_90 ( V_177 , F_91 ( V_170 [ V_178 ] ) ) ;
if ( ! V_94 )
return - V_179 ;
V_1 ( V_3 ) -> V_94 = V_94 ;
F_92 ( & V_1 ( V_3 ) -> V_180 ) ;
V_97 = F_23 ( sizeof( struct V_96 ) , V_63 ) ;
if ( ! V_97 ) {
F_75 ( V_94 ) ;
V_1 ( V_3 ) -> V_94 = NULL ;
return - V_64 ;
}
V_97 -> V_104 = V_3 ;
F_93 ( & V_1 ( V_3 ) -> V_180 ) ;
F_56 ( & V_97 -> V_109 ) ;
F_62 ( & V_97 -> V_109 , & V_181 ) ;
F_94 ( & V_1 ( V_3 ) -> V_180 ) ;
F_95 ( & V_108 ) ;
F_96 ( V_3 ) ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_182 * V_58 )
{
struct V_1 * V_183 = V_1 ( V_3 ) ;
struct V_2 * V_94 = V_183 -> V_94 ;
struct V_96 * V_97 , * V_46 ;
struct V_106 * V_115 , * V_184 ;
F_98 () ;
F_50 ( & V_108 ) ;
F_99 (frame, tframe, &lowpan_fragments, list) {
F_65 ( & V_115 -> V_120 ) ;
F_51 ( & V_115 -> V_109 ) ;
F_53 ( V_115 -> V_25 ) ;
F_34 ( V_115 ) ;
}
F_52 ( & V_108 ) ;
F_93 ( & V_1 ( V_3 ) -> V_180 ) ;
F_99 (entry, tmp, &lowpan_devices, list) {
if ( V_97 -> V_104 == V_3 ) {
F_51 ( & V_97 -> V_109 ) ;
F_34 ( V_97 ) ;
}
}
F_94 ( & V_1 ( V_3 ) -> V_180 ) ;
F_100 ( & V_1 ( V_3 ) -> V_180 ) ;
F_101 ( V_3 , V_58 ) ;
F_75 ( V_94 ) ;
}
static inline int T_4 F_102 ( void )
{
return F_103 ( & V_185 ) ;
}
static inline void T_4 F_104 ( void )
{
F_105 ( & V_185 ) ;
}
static int T_4 F_106 ( void )
{
int V_49 = 0 ;
F_5 ( L_53 , V_30 ) ;
V_49 = F_102 () ;
if ( V_49 < 0 )
goto V_148;
F_107 ( & V_186 ) ;
V_148:
return V_49 ;
}
static void T_5 F_108 ( void )
{
F_5 ( L_53 , V_30 ) ;
F_104 () ;
F_109 ( & V_186 ) ;
}
