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
F_22 ( L_2 ,
V_48 == V_51 ?
L_3 : L_4 ) ;
return - V_52 ;
}
break;
case V_53 :
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
static void F_23 ( struct V_54 * V_10 , int V_55 )
{
int V_56 ;
T_1 * V_57 ;
T_1 * V_14 ;
struct V_58 * V_59 = V_10 -> V_60 ;
struct V_61 * V_62 = F_24 ( V_59 ) -> V_63 ;
struct V_64 * V_65 = V_62 -> V_60 ;
struct V_23 * V_66 = F_25 ( V_59 ) ;
struct V_67 * V_68 = V_67 ( V_59 ) ;
struct V_9 * V_69 ;
V_56 = F_26 ( V_59 ) - sizeof( struct V_23 ) ;
if ( V_56 )
V_56 += sizeof( * V_69 ) ;
V_57 = F_27 ( V_59 ) -> V_12 ;
V_69 = F_9 ( V_57 ) ;
V_14 = F_11 ( V_65 -> V_2 , V_69 , V_56 ) ;
memcpy ( V_68 -> V_70 , V_14 , V_65 -> V_71 ) ;
memcpy ( V_66 , V_57 , V_11 ) ;
if ( V_56 ) {
#if F_28 ( V_72 )
memcpy ( & V_66 -> V_33 , V_69 , V_56 ) ;
#else
memcpy ( & V_66 -> V_41 , V_69 , V_56 ) ;
#endif
}
F_29 ( F_27 ( V_59 ) -> V_12 ) ;
F_30 ( V_59 , V_55 ) ;
}
static int F_31 ( struct V_61 * V_62 , struct V_58 * V_59 )
{
int V_55 ;
int V_3 ;
int V_56 ;
T_1 * V_57 ;
T_1 * V_14 ;
T_1 V_48 ;
struct V_58 * V_73 ;
struct V_1 * V_2 ;
struct V_6 * V_15 ;
struct V_7 * V_74 ;
struct V_23 * V_66 ;
struct V_67 * V_68 ;
struct V_64 * V_65 ;
struct V_9 * V_69 ;
int V_75 = 0 ;
T_2 * V_76 ;
int V_77 = 0 ;
struct V_7 * V_78 ;
V_65 = V_62 -> V_60 ;
V_2 = V_65 -> V_2 ;
V_55 = F_32 ( V_59 , 0 , & V_73 ) ;
if ( V_55 < 0 )
goto V_79;
V_3 = V_55 ;
F_33 ( V_59 , - F_34 ( V_59 ) ) ;
V_56 = F_26 ( V_59 ) - sizeof( struct V_23 ) ;
if ( V_56 )
V_56 += sizeof( * V_69 ) ;
if ( V_62 -> V_80 . V_81 & V_82 ) {
V_77 = 1 ;
V_75 = sizeof( * V_76 ) ;
}
V_55 = - V_83 ;
V_57 = F_1 ( V_2 , V_3 + V_77 , V_11 +
V_56 + V_75 ) ;
if ( ! V_57 )
goto V_79;
V_69 = F_9 ( V_57 ) ;
V_76 = ( T_2 * ) ( ( char * ) V_69 + V_56 ) ;
V_14 = F_11 ( V_2 , V_76 , V_75 ) ;
V_15 = F_13 ( V_2 , V_14 ) ;
V_74 = F_15 ( V_2 , V_15 ) ;
V_78 = V_74 + V_3 ;
V_68 = V_67 ( V_59 ) ;
memset ( V_68 -> V_70 , 0 , V_65 -> V_71 ) ;
V_66 = F_25 ( V_59 ) ;
V_66 -> V_84 = F_35 ( V_59 -> V_5 - sizeof( * V_66 ) ) ;
V_48 = * F_36 ( V_59 ) ;
* F_36 ( V_59 ) = V_85 ;
memcpy ( V_57 , V_66 , V_11 ) ;
if ( V_56 ) {
#if F_28 ( V_72 )
memcpy ( V_69 , & V_66 -> V_33 , V_56 ) ;
#else
memcpy ( V_69 , & V_66 -> V_41 , V_56 ) ;
#endif
V_55 = F_21 ( V_66 ,
V_56 - sizeof( * V_69 ) +
sizeof( * V_66 ) ,
V_50 ) ;
if ( V_55 )
goto V_86;
}
V_68 -> V_48 = V_48 ;
V_66 -> V_87 = 0 ;
V_66 -> V_88 [ 0 ] = 0 ;
V_66 -> V_88 [ 1 ] = 0 ;
V_66 -> V_88 [ 2 ] = 0 ;
V_66 -> V_89 = 0 ;
V_68 -> V_39 = ( F_37 ( sizeof( * V_68 ) + V_65 -> V_71 ) >> 2 ) - 2 ;
V_68 -> V_90 = 0 ;
V_68 -> V_91 = V_62 -> V_92 . V_91 ;
V_68 -> V_93 = F_38 ( F_39 ( V_59 ) -> V_94 . V_95 . V_96 ) ;
F_40 ( V_74 , V_3 + V_77 ) ;
F_41 ( V_59 , V_74 , 0 , V_59 -> V_5 ) ;
if ( V_62 -> V_80 . V_81 & V_82 ) {
* V_76 = F_38 ( F_39 ( V_59 ) -> V_94 . V_95 . V_97 ) ;
F_42 ( V_78 , V_76 , V_75 ) ;
}
F_43 ( V_15 , V_74 , V_14 , V_59 -> V_5 + V_75 ) ;
F_44 ( V_15 , 0 , F_23 , V_59 ) ;
F_27 ( V_59 ) -> V_12 = V_57 ;
V_55 = F_45 ( V_15 ) ;
if ( V_55 ) {
if ( V_55 == - V_98 )
goto V_79;
if ( V_55 == - V_99 )
V_55 = V_100 ;
goto V_86;
}
memcpy ( V_68 -> V_70 , V_14 , V_65 -> V_71 ) ;
memcpy ( V_66 , V_57 , V_11 ) ;
if ( V_56 ) {
#if F_28 ( V_72 )
memcpy ( & V_66 -> V_33 , V_69 , V_56 ) ;
#else
memcpy ( & V_66 -> V_41 , V_69 , V_56 ) ;
#endif
}
V_86:
F_29 ( V_57 ) ;
V_79:
return V_55 ;
}
static void F_46 ( struct V_54 * V_10 , int V_55 )
{
T_1 * V_70 ;
T_1 * V_14 ;
T_1 * V_101 ;
struct V_58 * V_59 = V_10 -> V_60 ;
struct V_61 * V_62 = F_47 ( V_59 ) ;
struct V_64 * V_65 = V_62 -> V_60 ;
struct V_67 * V_68 = V_67 ( V_59 ) ;
int V_102 = F_26 ( V_59 ) ;
int V_103 = ( V_68 -> V_39 + 2 ) << 2 ;
V_101 = F_27 ( V_59 ) -> V_12 ;
V_70 = F_10 ( V_101 , V_102 ) ;
V_14 = F_11 ( V_65 -> V_2 , V_70 , V_65 -> V_71 ) ;
V_55 = memcmp ( V_14 , V_70 , V_65 -> V_71 ) ? - V_104 : 0 ;
if ( V_55 )
goto V_79;
V_55 = V_68 -> V_48 ;
V_59 -> V_105 += V_103 ;
memcpy ( F_48 ( V_59 ) , V_101 , V_102 ) ;
F_49 ( V_59 , V_103 + V_102 ) ;
if ( V_62 -> V_80 . V_106 == V_107 )
F_50 ( V_59 ) ;
else
F_51 ( V_59 , - V_102 ) ;
V_79:
F_29 ( F_27 ( V_59 ) -> V_12 ) ;
F_52 ( V_59 , V_55 ) ;
}
static int F_53 ( struct V_61 * V_62 , struct V_58 * V_59 )
{
T_1 * V_70 ;
T_1 * V_14 ;
T_1 * V_101 ;
struct V_58 * V_73 ;
struct V_1 * V_2 ;
struct V_6 * V_15 ;
struct V_7 * V_74 ;
struct V_67 * V_68 ;
struct V_23 * V_108 ;
struct V_64 * V_65 ;
T_3 V_102 ;
T_3 V_103 ;
int V_48 ;
int V_3 ;
int V_55 = - V_83 ;
int V_75 = 0 ;
T_2 * V_76 ;
int V_77 = 0 ;
struct V_7 * V_78 ;
if ( ! F_54 ( V_59 , sizeof( struct V_67 ) ) )
goto V_79;
if ( F_55 ( V_59 , V_8 ) )
goto V_79;
V_59 -> V_109 = V_110 ;
V_102 = F_26 ( V_59 ) ;
V_68 = (struct V_67 * ) V_59 -> V_60 ;
V_65 = V_62 -> V_60 ;
V_2 = V_65 -> V_2 ;
V_48 = V_68 -> V_48 ;
V_103 = ( V_68 -> V_39 + 2 ) << 2 ;
if ( V_103 != F_37 ( sizeof( * V_68 ) + V_65 -> V_111 ) &&
V_103 != F_37 ( sizeof( * V_68 ) + V_65 -> V_71 ) )
goto V_79;
if ( ! F_54 ( V_59 , V_103 ) )
goto V_79;
V_55 = F_32 ( V_59 , 0 , & V_73 ) ;
if ( V_55 < 0 )
goto V_79;
V_3 = V_55 ;
V_68 = (struct V_67 * ) V_59 -> V_60 ;
V_108 = F_25 ( V_59 ) ;
F_33 ( V_59 , V_102 ) ;
if ( V_62 -> V_80 . V_81 & V_82 ) {
V_77 = 1 ;
V_75 = sizeof( * V_76 ) ;
}
V_101 = F_1 ( V_2 , V_3 + V_77 , V_102 +
V_65 -> V_71 + V_75 ) ;
if ( ! V_101 ) {
V_55 = - V_83 ;
goto V_79;
}
V_70 = F_10 ( ( T_1 * ) V_101 , V_102 ) ;
V_76 = ( T_2 * ) ( V_70 + V_65 -> V_71 ) ;
V_14 = F_11 ( V_2 , V_76 , V_75 ) ;
V_15 = F_13 ( V_2 , V_14 ) ;
V_74 = F_15 ( V_2 , V_15 ) ;
V_78 = V_74 + V_3 ;
memcpy ( V_101 , V_108 , V_102 ) ;
memcpy ( V_70 , V_68 -> V_70 , V_65 -> V_71 ) ;
memset ( V_68 -> V_70 , 0 , V_65 -> V_71 ) ;
if ( F_21 ( V_108 , V_102 , V_112 ) )
goto V_86;
V_108 -> V_87 = 0 ;
V_108 -> V_88 [ 0 ] = 0 ;
V_108 -> V_88 [ 1 ] = 0 ;
V_108 -> V_88 [ 2 ] = 0 ;
V_108 -> V_89 = 0 ;
F_40 ( V_74 , V_3 + V_77 ) ;
F_41 ( V_59 , V_74 , 0 , V_59 -> V_5 ) ;
if ( V_62 -> V_80 . V_81 & V_82 ) {
* V_76 = F_39 ( V_59 ) -> V_94 . V_113 . V_97 ;
F_42 ( V_78 , V_76 , V_75 ) ;
}
F_43 ( V_15 , V_74 , V_14 , V_59 -> V_5 + V_75 ) ;
F_44 ( V_15 , 0 , F_46 , V_59 ) ;
F_27 ( V_59 ) -> V_12 = V_101 ;
V_55 = F_45 ( V_15 ) ;
if ( V_55 ) {
if ( V_55 == - V_98 )
goto V_79;
goto V_86;
}
V_55 = memcmp ( V_14 , V_70 , V_65 -> V_71 ) ? - V_104 : 0 ;
if ( V_55 )
goto V_86;
V_59 -> V_105 += V_103 ;
memcpy ( F_48 ( V_59 ) , V_101 , V_102 ) ;
F_49 ( V_59 , V_103 + V_102 ) ;
if ( V_62 -> V_80 . V_106 == V_107 )
F_50 ( V_59 ) ;
else
F_51 ( V_59 , - V_102 ) ;
V_55 = V_48 ;
V_86:
F_29 ( V_101 ) ;
V_79:
return V_55 ;
}
static int F_56 ( struct V_58 * V_59 , struct V_114 * V_18 ,
T_1 type , T_1 V_115 , int V_13 , T_2 V_116 )
{
struct V_117 * V_117 = F_57 ( V_59 -> V_118 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_59 -> V_60 ;
struct V_67 * V_68 = (struct V_67 * ) ( V_59 -> V_60 + V_13 ) ;
struct V_61 * V_62 ;
if ( type != V_119 &&
type != V_120 )
return 0 ;
V_62 = F_58 ( V_117 , V_59 -> V_121 , ( V_122 * ) & V_24 -> V_41 , V_68 -> V_91 , V_85 , V_123 ) ;
if ( ! V_62 )
return 0 ;
if ( type == V_120 )
F_59 ( V_59 , V_117 , V_59 -> V_118 -> V_124 , 0 ,
F_60 ( V_117 , NULL ) ) ;
else
F_61 ( V_59 , V_117 , V_116 , 0 , 0 , F_60 ( V_117 , NULL ) ) ;
F_62 ( V_62 ) ;
return 0 ;
}
static int F_63 ( struct V_61 * V_62 )
{
struct V_64 * V_65 = NULL ;
struct V_125 * V_126 ;
struct V_1 * V_2 ;
if ( ! V_62 -> V_127 )
goto error;
if ( V_62 -> V_128 )
goto error;
V_65 = F_64 ( sizeof( * V_65 ) , V_129 ) ;
if ( ! V_65 )
return - V_83 ;
V_2 = F_65 ( V_62 -> V_127 -> V_130 , 0 , 0 ) ;
if ( F_66 ( V_2 ) )
goto error;
V_65 -> V_2 = V_2 ;
if ( F_67 ( V_2 , V_62 -> V_127 -> V_131 ,
( V_62 -> V_127 -> V_132 + 7 ) / 8 ) )
goto error;
V_126 = F_68 ( V_62 -> V_127 -> V_130 , 0 ) ;
F_69 ( ! V_126 ) ;
if ( V_126 -> V_133 . V_134 . V_135 / 8 !=
F_2 ( V_2 ) ) {
F_70 ( L_5 ,
V_62 -> V_127 -> V_130 , F_2 ( V_2 ) ,
V_126 -> V_133 . V_134 . V_135 / 8 ) ;
goto error;
}
V_65 -> V_111 = V_126 -> V_133 . V_134 . V_135 / 8 ;
V_65 -> V_71 = V_62 -> V_127 -> V_136 / 8 ;
V_62 -> V_80 . V_137 = F_37 ( sizeof( struct V_67 ) +
V_65 -> V_71 ) ;
switch ( V_62 -> V_80 . V_106 ) {
case V_138 :
case V_139 :
break;
case V_107 :
V_62 -> V_80 . V_137 += sizeof( struct V_23 ) ;
break;
default:
goto error;
}
V_62 -> V_60 = V_65 ;
return 0 ;
error:
if ( V_65 ) {
F_71 ( V_65 -> V_2 ) ;
F_29 ( V_65 ) ;
}
return - V_52 ;
}
static void F_72 ( struct V_61 * V_62 )
{
struct V_64 * V_65 = V_62 -> V_60 ;
if ( ! V_65 )
return;
F_71 ( V_65 -> V_2 ) ;
F_29 ( V_65 ) ;
}
static int F_73 ( struct V_58 * V_59 , int V_55 )
{
return 0 ;
}
static int T_4 F_74 ( void )
{
if ( F_75 ( & V_140 , V_123 ) < 0 ) {
F_70 ( L_6 , V_141 ) ;
return - V_142 ;
}
if ( F_76 ( & V_143 , V_85 ) < 0 ) {
F_70 ( L_7 , V_141 ) ;
F_77 ( & V_140 , V_123 ) ;
return - V_142 ;
}
return 0 ;
}
static void T_5 F_78 ( void )
{
if ( F_79 ( & V_143 , V_85 ) < 0 )
F_70 ( L_8 , V_141 ) ;
if ( F_77 ( & V_140 , V_123 ) < 0 )
F_70 ( L_9 , V_141 ) ;
}
