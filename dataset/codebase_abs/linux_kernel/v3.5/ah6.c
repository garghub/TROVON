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
default :
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
#if F_28 ( V_73 ) || F_28 ( V_74 )
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
struct V_59 * V_75 ;
struct V_1 * V_2 ;
struct V_6 * V_15 ;
struct V_7 * V_76 ;
struct V_23 * V_67 ;
struct V_68 * V_69 ;
struct V_65 * V_66 ;
struct V_9 * V_70 ;
V_66 = V_63 -> V_61 ;
V_2 = V_66 -> V_2 ;
if ( ( V_56 = F_32 ( V_60 , 0 , & V_75 ) ) < 0 )
goto V_77;
V_3 = V_56 ;
F_33 ( V_60 , - F_34 ( V_60 ) ) ;
V_57 = F_26 ( V_60 ) - sizeof( struct V_23 ) ;
if ( V_57 )
V_57 += sizeof( * V_70 ) ;
V_56 = - V_78 ;
V_58 = F_1 ( V_2 , V_3 , V_11 + V_57 ) ;
if ( ! V_58 )
goto V_77;
V_70 = F_9 ( V_58 ) ;
V_14 = F_11 ( V_2 , V_70 , V_57 ) ;
V_15 = F_13 ( V_2 , V_14 ) ;
V_76 = F_15 ( V_2 , V_15 ) ;
V_69 = V_68 ( V_60 ) ;
memset ( V_69 -> V_71 , 0 , V_66 -> V_72 ) ;
V_67 = F_25 ( V_60 ) ;
V_67 -> V_79 = F_35 ( V_60 -> V_5 - sizeof( * V_67 ) ) ;
V_48 = * F_36 ( V_60 ) ;
* F_36 ( V_60 ) = V_80 ;
memcpy ( V_58 , V_67 , V_11 ) ;
if ( V_57 ) {
#if F_28 ( V_73 ) || F_28 ( V_74 )
memcpy ( V_70 , & V_67 -> V_33 , V_57 ) ;
#else
memcpy ( V_70 , & V_67 -> V_41 , V_57 ) ;
#endif
V_56 = F_21 ( V_67 ,
V_57 - sizeof( * V_70 ) +
sizeof( * V_67 ) ,
V_50 ) ;
if ( V_56 )
goto V_81;
}
V_69 -> V_48 = V_48 ;
V_67 -> V_82 = 0 ;
V_67 -> V_83 [ 0 ] = 0 ;
V_67 -> V_83 [ 1 ] = 0 ;
V_67 -> V_83 [ 2 ] = 0 ;
V_67 -> V_84 = 0 ;
V_69 -> V_39 = ( F_37 ( sizeof( * V_69 ) + V_66 -> V_72 ) >> 2 ) - 2 ;
V_69 -> V_85 = 0 ;
V_69 -> V_86 = V_63 -> V_87 . V_86 ;
V_69 -> V_88 = F_38 ( F_39 ( V_60 ) -> V_89 . V_90 . V_91 ) ;
F_40 ( V_76 , V_3 ) ;
F_41 ( V_60 , V_76 , 0 , V_60 -> V_5 ) ;
F_42 ( V_15 , V_76 , V_14 , V_60 -> V_5 ) ;
F_43 ( V_15 , 0 , F_23 , V_60 ) ;
F_27 ( V_60 ) -> V_12 = V_58 ;
V_56 = F_44 ( V_15 ) ;
if ( V_56 ) {
if ( V_56 == - V_92 )
goto V_77;
if ( V_56 == - V_93 )
V_56 = V_94 ;
goto V_81;
}
memcpy ( V_69 -> V_71 , V_14 , V_66 -> V_72 ) ;
memcpy ( V_67 , V_58 , V_11 ) ;
if ( V_57 ) {
#if F_28 ( V_73 ) || F_28 ( V_74 )
memcpy ( & V_67 -> V_33 , V_70 , V_57 ) ;
#else
memcpy ( & V_67 -> V_41 , V_70 , V_57 ) ;
#endif
}
V_81:
F_29 ( V_58 ) ;
V_77:
return V_56 ;
}
static void F_45 ( struct V_55 * V_10 , int V_56 )
{
T_1 * V_71 ;
T_1 * V_14 ;
T_1 * V_95 ;
struct V_59 * V_60 = V_10 -> V_61 ;
struct V_62 * V_63 = F_46 ( V_60 ) ;
struct V_65 * V_66 = V_63 -> V_61 ;
struct V_68 * V_69 = V_68 ( V_60 ) ;
int V_96 = F_26 ( V_60 ) ;
int V_97 = ( V_69 -> V_39 + 2 ) << 2 ;
V_95 = F_27 ( V_60 ) -> V_12 ;
V_71 = F_10 ( V_95 , V_96 ) ;
V_14 = F_11 ( V_66 -> V_2 , V_71 , V_66 -> V_72 ) ;
V_56 = memcmp ( V_14 , V_71 , V_66 -> V_72 ) ? - V_98 : 0 ;
if ( V_56 )
goto V_77;
V_56 = V_69 -> V_48 ;
V_60 -> V_99 += V_97 ;
memcpy ( F_47 ( V_60 ) , V_95 , V_96 ) ;
F_48 ( V_60 , V_97 + V_96 ) ;
F_49 ( V_60 , - V_96 ) ;
V_77:
F_29 ( F_27 ( V_60 ) -> V_12 ) ;
F_50 ( V_60 , V_56 ) ;
}
static int F_51 ( struct V_62 * V_63 , struct V_59 * V_60 )
{
T_1 * V_71 ;
T_1 * V_14 ;
T_1 * V_95 ;
struct V_59 * V_75 ;
struct V_1 * V_2 ;
struct V_6 * V_15 ;
struct V_7 * V_76 ;
struct V_68 * V_69 ;
struct V_23 * V_100 ;
struct V_65 * V_66 ;
T_2 V_96 ;
T_2 V_97 ;
int V_48 ;
int V_3 ;
int V_56 = - V_78 ;
if ( ! F_52 ( V_60 , sizeof( struct V_68 ) ) )
goto V_77;
if ( F_53 ( V_60 ) &&
F_54 ( V_60 , 0 , 0 , V_8 ) )
goto V_77;
V_60 -> V_101 = V_102 ;
V_96 = F_26 ( V_60 ) ;
V_69 = (struct V_68 * ) V_60 -> V_61 ;
V_66 = V_63 -> V_61 ;
V_2 = V_66 -> V_2 ;
V_48 = V_69 -> V_48 ;
V_97 = ( V_69 -> V_39 + 2 ) << 2 ;
if ( V_97 != F_37 ( sizeof( * V_69 ) + V_66 -> V_103 ) &&
V_97 != F_37 ( sizeof( * V_69 ) + V_66 -> V_72 ) )
goto V_77;
if ( ! F_52 ( V_60 , V_97 ) )
goto V_77;
if ( ( V_56 = F_32 ( V_60 , 0 , & V_75 ) ) < 0 )
goto V_77;
V_3 = V_56 ;
V_69 = (struct V_68 * ) V_60 -> V_61 ;
V_100 = F_25 ( V_60 ) ;
F_33 ( V_60 , V_96 ) ;
V_95 = F_1 ( V_2 , V_3 , V_96 + V_66 -> V_72 ) ;
if ( ! V_95 )
goto V_77;
V_71 = F_10 ( V_95 , V_96 ) ;
V_14 = F_11 ( V_2 , V_71 , V_66 -> V_72 ) ;
V_15 = F_13 ( V_2 , V_14 ) ;
V_76 = F_15 ( V_2 , V_15 ) ;
memcpy ( V_95 , V_100 , V_96 ) ;
memcpy ( V_71 , V_69 -> V_71 , V_66 -> V_72 ) ;
memset ( V_69 -> V_71 , 0 , V_66 -> V_72 ) ;
if ( F_21 ( V_100 , V_96 , V_104 ) )
goto V_81;
V_100 -> V_82 = 0 ;
V_100 -> V_83 [ 0 ] = 0 ;
V_100 -> V_83 [ 1 ] = 0 ;
V_100 -> V_83 [ 2 ] = 0 ;
V_100 -> V_84 = 0 ;
F_40 ( V_76 , V_3 ) ;
F_41 ( V_60 , V_76 , 0 , V_60 -> V_5 ) ;
F_42 ( V_15 , V_76 , V_14 , V_60 -> V_5 ) ;
F_43 ( V_15 , 0 , F_45 , V_60 ) ;
F_27 ( V_60 ) -> V_12 = V_95 ;
V_56 = F_44 ( V_15 ) ;
if ( V_56 ) {
if ( V_56 == - V_92 )
goto V_77;
goto V_81;
}
V_56 = memcmp ( V_14 , V_71 , V_66 -> V_72 ) ? - V_98 : 0 ;
if ( V_56 )
goto V_81;
V_60 -> V_99 += V_97 ;
memcpy ( F_47 ( V_60 ) , V_95 , V_96 ) ;
V_60 -> V_105 = V_60 -> V_99 ;
F_48 ( V_60 , V_97 + V_96 ) ;
V_56 = V_48 ;
V_81:
F_29 ( V_95 ) ;
V_77:
return V_56 ;
}
static void F_55 ( struct V_59 * V_60 , struct V_106 * V_18 ,
T_1 type , T_1 V_107 , int V_13 , T_3 V_108 )
{
struct V_109 * V_109 = F_56 ( V_60 -> V_110 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_60 -> V_61 ;
struct V_68 * V_69 = (struct V_68 * ) ( V_60 -> V_61 + V_13 ) ;
struct V_62 * V_63 ;
if ( type != V_111 &&
type != V_112 )
return;
V_63 = F_57 ( V_109 , V_60 -> V_113 , ( V_114 * ) & V_24 -> V_41 , V_69 -> V_86 , V_80 , V_115 ) ;
if ( ! V_63 )
return;
F_58 ( V_116 L_5 ,
F_59 ( V_69 -> V_86 ) , & V_24 -> V_41 ) ;
F_60 ( V_63 ) ;
}
static int F_61 ( struct V_62 * V_63 )
{
struct V_65 * V_66 = NULL ;
struct V_117 * V_118 ;
struct V_1 * V_2 ;
if ( ! V_63 -> V_119 )
goto error;
if ( V_63 -> V_120 )
goto error;
V_66 = F_62 ( sizeof( * V_66 ) , V_121 ) ;
if ( V_66 == NULL )
return - V_78 ;
V_2 = F_63 ( V_63 -> V_119 -> V_122 , 0 , 0 ) ;
if ( F_64 ( V_2 ) )
goto error;
V_66 -> V_2 = V_2 ;
if ( F_65 ( V_2 , V_63 -> V_119 -> V_123 ,
( V_63 -> V_119 -> V_124 + 7 ) / 8 ) )
goto error;
V_118 = F_66 ( V_63 -> V_119 -> V_122 , 0 ) ;
F_67 ( ! V_118 ) ;
if ( V_118 -> V_125 . V_126 . V_127 / 8 !=
F_2 ( V_2 ) ) {
F_68 ( L_6 ,
V_63 -> V_119 -> V_122 , F_2 ( V_2 ) ,
V_118 -> V_125 . V_126 . V_127 / 8 ) ;
goto error;
}
V_66 -> V_103 = V_118 -> V_125 . V_126 . V_127 / 8 ;
V_66 -> V_72 = V_63 -> V_119 -> V_128 / 8 ;
F_67 ( V_66 -> V_72 > V_129 ) ;
V_63 -> V_130 . V_131 = F_37 ( sizeof( struct V_68 ) +
V_66 -> V_72 ) ;
switch ( V_63 -> V_130 . V_132 ) {
case V_133 :
case V_134 :
break;
case V_135 :
V_63 -> V_130 . V_131 += sizeof( struct V_23 ) ;
break;
default:
goto error;
}
V_63 -> V_61 = V_66 ;
return 0 ;
error:
if ( V_66 ) {
F_69 ( V_66 -> V_2 ) ;
F_29 ( V_66 ) ;
}
return - V_53 ;
}
static void F_70 ( struct V_62 * V_63 )
{
struct V_65 * V_66 = V_63 -> V_61 ;
if ( ! V_66 )
return;
F_69 ( V_66 -> V_2 ) ;
F_29 ( V_66 ) ;
}
static int T_4 F_71 ( void )
{
if ( F_72 ( & V_136 , V_115 ) < 0 ) {
F_68 ( L_7 , V_137 ) ;
return - V_138 ;
}
if ( F_73 ( & V_139 , V_80 ) < 0 ) {
F_68 ( L_8 , V_137 ) ;
F_74 ( & V_136 , V_115 ) ;
return - V_138 ;
}
return 0 ;
}
static void T_5 F_75 ( void )
{
if ( F_76 ( & V_139 , V_80 ) < 0 )
F_68 ( L_9 , V_137 ) ;
if ( F_74 ( & V_136 , V_115 ) < 0 )
F_68 ( L_10 , V_137 ) ;
}
