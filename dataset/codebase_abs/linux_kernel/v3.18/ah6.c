static void * F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = V_4 + F_2 ( V_2 ) +
( F_3 ( V_2 ) &
~ ( F_4 () - 1 ) ) ;
V_5 = F_5 ( V_5 , F_4 () ) ;
V_5 += sizeof( struct V_6 ) + F_6 ( V_2 ) ;
V_5 = F_5 ( V_5 , F_7 ( struct V_7 ) ) ;
V_5 += sizeof( struct V_7 ) * V_3 ;
return F_8 ( V_5 , V_8 ) ;
}
static inline struct V_9 * F_9 ( void * V_10 )
{
return V_10 + V_11 ;
}
static inline T_1 * F_10 ( T_1 * V_12 , unsigned int V_13 )
{
return V_12 + V_13 ;
}
static inline T_1 * F_11 ( struct V_1 * V_2 , void * V_12 ,
unsigned int V_13 )
{
return F_12 ( ( T_1 * ) V_12 + V_13 , F_3 ( V_2 ) + 1 ) ;
}
static inline struct V_6 * F_13 ( struct V_1 * V_2 ,
T_1 * V_14 )
{
struct V_6 * V_15 ;
V_15 = ( void * ) F_12 ( V_14 + F_2 ( V_2 ) ,
F_4 () ) ;
F_14 ( V_15 , V_2 ) ;
return V_15 ;
}
static inline struct V_7 * F_15 ( struct V_1 * V_2 ,
struct V_6 * V_15 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_15 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static bool F_16 ( struct V_16 * V_17 )
{
T_1 * V_18 = ( T_1 * ) V_17 ;
int V_5 = F_17 ( V_17 ) ;
int V_19 = 0 ;
int V_20 = 0 ;
V_19 += 2 ;
V_5 -= 2 ;
while ( V_5 > 0 ) {
switch ( V_18 [ V_19 ] ) {
case V_21 :
V_20 = 1 ;
break;
default:
if ( V_5 < 2 )
goto V_22;
V_20 = V_18 [ V_19 + 1 ] + 2 ;
if ( V_5 < V_20 )
goto V_22;
if ( V_18 [ V_19 ] & 0x20 )
memset ( & V_18 [ V_19 + 2 ] , 0 , V_18 [ V_19 + 1 ] ) ;
break;
}
V_19 += V_20 ;
V_5 -= V_20 ;
}
if ( V_5 == 0 )
return true ;
V_22:
return false ;
}
static void F_18 ( struct V_23 * V_24 , struct V_16 * V_25 )
{
T_1 * V_18 = ( T_1 * ) V_25 ;
int V_5 = F_17 ( V_25 ) ;
int V_19 = 0 ;
int V_20 = 0 ;
V_19 += 2 ;
V_5 -= 2 ;
while ( V_5 > 0 ) {
switch ( V_18 [ V_19 ] ) {
case V_21 :
V_20 = 1 ;
break;
default:
if ( V_5 < 2 )
goto V_22;
V_20 = V_18 [ V_19 + 1 ] + 2 ;
if ( V_5 < V_20 )
goto V_22;
if ( V_18 [ V_19 ] == V_26 ) {
struct V_27 V_28 ;
struct V_29 * V_30 ;
V_30 = (struct V_29 * ) & V_18 [ V_19 ] ;
if ( V_30 -> V_31 != sizeof( V_30 -> V_32 ) ) {
F_19 ( L_1 ,
V_30 -> V_31 ) ;
goto V_22;
}
V_28 = V_30 -> V_32 ;
V_30 -> V_32 = V_24 -> V_33 ;
V_24 -> V_33 = V_28 ;
}
break;
}
V_19 += V_20 ;
V_5 -= V_20 ;
}
V_22:
return;
}
static void F_18 ( struct V_23 * V_24 , struct V_16 * V_25 ) {}
static void F_20 ( struct V_23 * V_24 , struct V_34 * V_35 )
{
int V_36 , V_37 ;
struct V_27 * V_38 ;
struct V_27 V_28 ;
V_37 = V_35 -> V_37 ;
if ( V_37 == 0 )
return;
V_35 -> V_37 = 0 ;
V_36 = V_35 -> V_39 >> 1 ;
V_38 = ( (struct V_40 * ) V_35 ) -> V_32 ;
V_28 = V_38 [ V_36 - 1 ] ;
V_38 += V_36 - V_37 ;
memmove ( V_38 + 1 , V_38 , ( V_37 - 1 ) * sizeof( * V_38 ) ) ;
V_38 [ 0 ] = V_24 -> V_41 ;
V_24 -> V_41 = V_28 ;
}
static int F_21 ( struct V_23 * V_24 , int V_5 , int V_42 )
{
union {
struct V_23 * V_24 ;
struct V_16 * V_43 ;
struct V_34 * V_44 ;
char * V_45 ;
} V_46 = { . V_24 = V_24 } ;
char * V_47 = V_46 . V_45 + V_5 ;
int V_48 = V_24 -> V_48 ;
V_46 . V_24 ++ ;
while ( V_46 . V_45 < V_47 ) {
switch ( V_48 ) {
case V_49 :
if ( V_42 == V_50 )
F_18 ( V_24 , V_46 . V_43 ) ;
case V_51 :
if ( ! F_16 ( V_46 . V_43 ) ) {
F_22 (
V_52 L_2 ,
V_48 == V_51 ?
L_3 : L_4 ) ;
return - V_53 ;
}
break;
case V_54 :
F_20 ( V_24 , V_46 . V_44 ) ;
break;
default:
return 0 ;
}
V_48 = V_46 . V_43 -> V_48 ;
V_46 . V_45 += F_17 ( V_46 . V_43 ) ;
}
return 0 ;
}
static void F_23 ( struct V_55 * V_10 , int V_56 )
{
int V_57 ;
T_1 * V_58 ;
T_1 * V_14 ;
struct V_59 * V_60 = V_10 -> V_61 ;
struct V_62 * V_63 = F_24 ( V_60 ) -> V_64 ;
struct V_65 * V_66 = V_63 -> V_61 ;
struct V_23 * V_67 = F_25 ( V_60 ) ;
struct V_68 * V_69 = V_68 ( V_60 ) ;
struct V_9 * V_70 ;
V_57 = F_26 ( V_60 ) - sizeof( struct V_23 ) ;
if ( V_57 )
V_57 += sizeof( * V_70 ) ;
V_58 = F_27 ( V_60 ) -> V_12 ;
V_70 = F_9 ( V_58 ) ;
V_14 = F_11 ( V_66 -> V_2 , V_70 , V_57 ) ;
memcpy ( V_69 -> V_71 , V_14 , V_66 -> V_72 ) ;
memcpy ( V_67 , V_58 , V_11 ) ;
if ( V_57 ) {
#if F_28 ( V_73 )
memcpy ( & V_67 -> V_33 , V_70 , V_57 ) ;
#else
memcpy ( & V_67 -> V_41 , V_70 , V_57 ) ;
#endif
}
F_29 ( F_27 ( V_60 ) -> V_12 ) ;
F_30 ( V_60 , V_56 ) ;
}
static int F_31 ( struct V_62 * V_63 , struct V_59 * V_60 )
{
int V_56 ;
int V_3 ;
int V_57 ;
T_1 * V_58 ;
T_1 * V_14 ;
T_1 V_48 ;
struct V_59 * V_74 ;
struct V_1 * V_2 ;
struct V_6 * V_15 ;
struct V_7 * V_75 ;
struct V_23 * V_67 ;
struct V_68 * V_69 ;
struct V_65 * V_66 ;
struct V_9 * V_70 ;
int V_76 = 0 ;
T_2 * V_77 ;
int V_78 = 0 ;
struct V_7 * V_79 ;
V_66 = V_63 -> V_61 ;
V_2 = V_66 -> V_2 ;
if ( ( V_56 = F_32 ( V_60 , 0 , & V_74 ) ) < 0 )
goto V_80;
V_3 = V_56 ;
F_33 ( V_60 , - F_34 ( V_60 ) ) ;
V_57 = F_26 ( V_60 ) - sizeof( struct V_23 ) ;
if ( V_57 )
V_57 += sizeof( * V_70 ) ;
if ( V_63 -> V_81 . V_82 & V_83 ) {
V_78 = 1 ;
V_76 = sizeof( * V_77 ) ;
}
V_56 = - V_84 ;
V_58 = F_1 ( V_2 , V_3 + V_78 , V_11 +
V_57 + V_76 ) ;
if ( ! V_58 )
goto V_80;
V_70 = F_9 ( V_58 ) ;
V_77 = ( T_2 * ) ( ( char * ) V_70 + V_57 ) ;
V_14 = F_11 ( V_2 , V_77 , V_76 ) ;
V_15 = F_13 ( V_2 , V_14 ) ;
V_75 = F_15 ( V_2 , V_15 ) ;
V_79 = V_75 + V_3 ;
V_69 = V_68 ( V_60 ) ;
memset ( V_69 -> V_71 , 0 , V_66 -> V_72 ) ;
V_67 = F_25 ( V_60 ) ;
V_67 -> V_85 = F_35 ( V_60 -> V_5 - sizeof( * V_67 ) ) ;
V_48 = * F_36 ( V_60 ) ;
* F_36 ( V_60 ) = V_86 ;
memcpy ( V_58 , V_67 , V_11 ) ;
if ( V_57 ) {
#if F_28 ( V_73 )
memcpy ( V_70 , & V_67 -> V_33 , V_57 ) ;
#else
memcpy ( V_70 , & V_67 -> V_41 , V_57 ) ;
#endif
V_56 = F_21 ( V_67 ,
V_57 - sizeof( * V_70 ) +
sizeof( * V_67 ) ,
V_50 ) ;
if ( V_56 )
goto V_87;
}
V_69 -> V_48 = V_48 ;
V_67 -> V_88 = 0 ;
V_67 -> V_89 [ 0 ] = 0 ;
V_67 -> V_89 [ 1 ] = 0 ;
V_67 -> V_89 [ 2 ] = 0 ;
V_67 -> V_90 = 0 ;
V_69 -> V_39 = ( F_37 ( sizeof( * V_69 ) + V_66 -> V_72 ) >> 2 ) - 2 ;
V_69 -> V_91 = 0 ;
V_69 -> V_92 = V_63 -> V_93 . V_92 ;
V_69 -> V_94 = F_38 ( F_39 ( V_60 ) -> V_95 . V_96 . V_97 ) ;
F_40 ( V_75 , V_3 + V_78 ) ;
F_41 ( V_60 , V_75 , 0 , V_60 -> V_5 ) ;
if ( V_63 -> V_81 . V_82 & V_83 ) {
* V_77 = F_38 ( F_39 ( V_60 ) -> V_95 . V_96 . V_98 ) ;
F_42 ( V_79 , V_77 , V_76 ) ;
}
F_43 ( V_15 , V_75 , V_14 , V_60 -> V_5 + V_76 ) ;
F_44 ( V_15 , 0 , F_23 , V_60 ) ;
F_27 ( V_60 ) -> V_12 = V_58 ;
V_56 = F_45 ( V_15 ) ;
if ( V_56 ) {
if ( V_56 == - V_99 )
goto V_80;
if ( V_56 == - V_100 )
V_56 = V_101 ;
goto V_87;
}
memcpy ( V_69 -> V_71 , V_14 , V_66 -> V_72 ) ;
memcpy ( V_67 , V_58 , V_11 ) ;
if ( V_57 ) {
#if F_28 ( V_73 )
memcpy ( & V_67 -> V_33 , V_70 , V_57 ) ;
#else
memcpy ( & V_67 -> V_41 , V_70 , V_57 ) ;
#endif
}
V_87:
F_29 ( V_58 ) ;
V_80:
return V_56 ;
}
static void F_46 ( struct V_55 * V_10 , int V_56 )
{
T_1 * V_71 ;
T_1 * V_14 ;
T_1 * V_102 ;
struct V_59 * V_60 = V_10 -> V_61 ;
struct V_62 * V_63 = F_47 ( V_60 ) ;
struct V_65 * V_66 = V_63 -> V_61 ;
struct V_68 * V_69 = V_68 ( V_60 ) ;
int V_103 = F_26 ( V_60 ) ;
int V_104 = ( V_69 -> V_39 + 2 ) << 2 ;
V_102 = F_27 ( V_60 ) -> V_12 ;
V_71 = F_10 ( V_102 , V_103 ) ;
V_14 = F_11 ( V_66 -> V_2 , V_71 , V_66 -> V_72 ) ;
V_56 = memcmp ( V_14 , V_71 , V_66 -> V_72 ) ? - V_105 : 0 ;
if ( V_56 )
goto V_80;
V_56 = V_69 -> V_48 ;
V_60 -> V_106 += V_104 ;
memcpy ( F_48 ( V_60 ) , V_102 , V_103 ) ;
F_49 ( V_60 , V_104 + V_103 ) ;
if ( V_63 -> V_81 . V_107 == V_108 )
F_50 ( V_60 ) ;
else
F_51 ( V_60 , - V_103 ) ;
V_80:
F_29 ( F_27 ( V_60 ) -> V_12 ) ;
F_52 ( V_60 , V_56 ) ;
}
static int F_53 ( struct V_62 * V_63 , struct V_59 * V_60 )
{
T_1 * V_71 ;
T_1 * V_14 ;
T_1 * V_102 ;
struct V_59 * V_74 ;
struct V_1 * V_2 ;
struct V_6 * V_15 ;
struct V_7 * V_75 ;
struct V_68 * V_69 ;
struct V_23 * V_109 ;
struct V_65 * V_66 ;
T_3 V_103 ;
T_3 V_104 ;
int V_48 ;
int V_3 ;
int V_56 = - V_84 ;
int V_76 = 0 ;
T_2 * V_77 ;
int V_78 = 0 ;
struct V_7 * V_79 ;
if ( ! F_54 ( V_60 , sizeof( struct V_68 ) ) )
goto V_80;
if ( F_55 ( V_60 , V_8 ) )
goto V_80;
V_60 -> V_110 = V_111 ;
V_103 = F_26 ( V_60 ) ;
V_69 = (struct V_68 * ) V_60 -> V_61 ;
V_66 = V_63 -> V_61 ;
V_2 = V_66 -> V_2 ;
V_48 = V_69 -> V_48 ;
V_104 = ( V_69 -> V_39 + 2 ) << 2 ;
if ( V_104 != F_37 ( sizeof( * V_69 ) + V_66 -> V_112 ) &&
V_104 != F_37 ( sizeof( * V_69 ) + V_66 -> V_72 ) )
goto V_80;
if ( ! F_54 ( V_60 , V_104 ) )
goto V_80;
if ( ( V_56 = F_32 ( V_60 , 0 , & V_74 ) ) < 0 )
goto V_80;
V_3 = V_56 ;
V_69 = (struct V_68 * ) V_60 -> V_61 ;
V_109 = F_25 ( V_60 ) ;
F_33 ( V_60 , V_103 ) ;
if ( V_63 -> V_81 . V_82 & V_83 ) {
V_78 = 1 ;
V_76 = sizeof( * V_77 ) ;
}
V_102 = F_1 ( V_2 , V_3 + V_78 , V_103 +
V_66 -> V_72 + V_76 ) ;
if ( ! V_102 )
goto V_80;
V_71 = F_10 ( ( T_1 * ) V_102 , V_103 ) ;
V_77 = ( T_2 * ) ( V_71 + V_66 -> V_72 ) ;
V_14 = F_11 ( V_2 , V_77 , V_76 ) ;
V_15 = F_13 ( V_2 , V_14 ) ;
V_75 = F_15 ( V_2 , V_15 ) ;
V_79 = V_75 + V_3 ;
memcpy ( V_102 , V_109 , V_103 ) ;
memcpy ( V_71 , V_69 -> V_71 , V_66 -> V_72 ) ;
memset ( V_69 -> V_71 , 0 , V_66 -> V_72 ) ;
if ( F_21 ( V_109 , V_103 , V_113 ) )
goto V_87;
V_109 -> V_88 = 0 ;
V_109 -> V_89 [ 0 ] = 0 ;
V_109 -> V_89 [ 1 ] = 0 ;
V_109 -> V_89 [ 2 ] = 0 ;
V_109 -> V_90 = 0 ;
F_40 ( V_75 , V_3 + V_78 ) ;
F_41 ( V_60 , V_75 , 0 , V_60 -> V_5 ) ;
if ( V_63 -> V_81 . V_82 & V_83 ) {
* V_77 = F_39 ( V_60 ) -> V_95 . V_114 . V_98 ;
F_42 ( V_79 , V_77 , V_76 ) ;
}
F_43 ( V_15 , V_75 , V_14 , V_60 -> V_5 + V_76 ) ;
F_44 ( V_15 , 0 , F_46 , V_60 ) ;
F_27 ( V_60 ) -> V_12 = V_102 ;
V_56 = F_45 ( V_15 ) ;
if ( V_56 ) {
if ( V_56 == - V_99 )
goto V_80;
goto V_87;
}
V_56 = memcmp ( V_14 , V_71 , V_66 -> V_72 ) ? - V_105 : 0 ;
if ( V_56 )
goto V_87;
V_60 -> V_106 += V_104 ;
memcpy ( F_48 ( V_60 ) , V_102 , V_103 ) ;
F_49 ( V_60 , V_104 + V_103 ) ;
if ( V_63 -> V_81 . V_107 == V_108 )
F_50 ( V_60 ) ;
else
F_51 ( V_60 , - V_103 ) ;
V_56 = V_48 ;
V_87:
F_29 ( V_102 ) ;
V_80:
return V_56 ;
}
static int F_56 ( struct V_59 * V_60 , struct V_115 * V_18 ,
T_1 type , T_1 V_116 , int V_13 , T_2 V_117 )
{
struct V_118 * V_118 = F_57 ( V_60 -> V_119 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_60 -> V_61 ;
struct V_68 * V_69 = (struct V_68 * ) ( V_60 -> V_61 + V_13 ) ;
struct V_62 * V_63 ;
if ( type != V_120 &&
type != V_121 )
return 0 ;
V_63 = F_58 ( V_118 , V_60 -> V_122 , ( V_123 * ) & V_24 -> V_41 , V_69 -> V_92 , V_86 , V_124 ) ;
if ( ! V_63 )
return 0 ;
if ( type == V_121 )
F_59 ( V_60 , V_118 , V_60 -> V_119 -> V_125 , 0 ) ;
else
F_60 ( V_60 , V_118 , V_117 , 0 , 0 ) ;
F_61 ( V_63 ) ;
return 0 ;
}
static int F_62 ( struct V_62 * V_63 )
{
struct V_65 * V_66 = NULL ;
struct V_126 * V_127 ;
struct V_1 * V_2 ;
if ( ! V_63 -> V_128 )
goto error;
if ( V_63 -> V_129 )
goto error;
V_66 = F_63 ( sizeof( * V_66 ) , V_130 ) ;
if ( V_66 == NULL )
return - V_84 ;
V_2 = F_64 ( V_63 -> V_128 -> V_131 , 0 , 0 ) ;
if ( F_65 ( V_2 ) )
goto error;
V_66 -> V_2 = V_2 ;
if ( F_66 ( V_2 , V_63 -> V_128 -> V_132 ,
( V_63 -> V_128 -> V_133 + 7 ) / 8 ) )
goto error;
V_127 = F_67 ( V_63 -> V_128 -> V_131 , 0 ) ;
F_68 ( ! V_127 ) ;
if ( V_127 -> V_134 . V_135 . V_136 / 8 !=
F_2 ( V_2 ) ) {
F_69 ( L_5 ,
V_63 -> V_128 -> V_131 , F_2 ( V_2 ) ,
V_127 -> V_134 . V_135 . V_136 / 8 ) ;
goto error;
}
V_66 -> V_112 = V_127 -> V_134 . V_135 . V_136 / 8 ;
V_66 -> V_72 = V_63 -> V_128 -> V_137 / 8 ;
V_63 -> V_81 . V_138 = F_37 ( sizeof( struct V_68 ) +
V_66 -> V_72 ) ;
switch ( V_63 -> V_81 . V_107 ) {
case V_139 :
case V_140 :
break;
case V_108 :
V_63 -> V_81 . V_138 += sizeof( struct V_23 ) ;
break;
default:
goto error;
}
V_63 -> V_61 = V_66 ;
return 0 ;
error:
if ( V_66 ) {
F_70 ( V_66 -> V_2 ) ;
F_29 ( V_66 ) ;
}
return - V_53 ;
}
static void F_71 ( struct V_62 * V_63 )
{
struct V_65 * V_66 = V_63 -> V_61 ;
if ( ! V_66 )
return;
F_70 ( V_66 -> V_2 ) ;
F_29 ( V_66 ) ;
}
static int F_72 ( struct V_59 * V_60 , int V_56 )
{
return 0 ;
}
static int T_4 F_73 ( void )
{
if ( F_74 ( & V_141 , V_124 ) < 0 ) {
F_69 ( L_6 , V_142 ) ;
return - V_143 ;
}
if ( F_75 ( & V_144 , V_86 ) < 0 ) {
F_69 ( L_7 , V_142 ) ;
F_76 ( & V_141 , V_124 ) ;
return - V_143 ;
}
return 0 ;
}
static void T_5 F_77 ( void )
{
if ( F_78 ( & V_144 , V_86 ) < 0 )
F_69 ( L_8 , V_142 ) ;
if ( F_76 ( & V_141 , V_124 ) < 0 )
F_69 ( L_9 , V_142 ) ;
}
