static inline struct
V_1 * V_1 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static inline struct
V_4 * F_2 ( const struct V_5 * V_6 )
{
F_3 ( F_4 ( V_6 ) < sizeof( struct V_4 ) ) ;
return (struct V_4 * ) ( V_6 -> V_7 -
sizeof( struct V_4 ) ) ;
}
static int F_5 ( struct V_5 * V_6 , struct V_2 * V_3 ,
unsigned short type , const void * V_8 ,
const void * V_9 , unsigned int V_10 )
{
const T_1 * V_11 = V_9 ;
const T_1 * V_12 = V_8 ;
struct V_4 * V_13 ;
if ( type != V_14 )
return 0 ;
if ( ! V_11 )
V_11 = V_3 -> V_15 ;
F_6 ( V_16 , L_1 , ( unsigned char * ) V_11 , 8 ) ;
F_6 ( V_16 , L_2 , ( unsigned char * ) V_12 , 8 ) ;
V_13 = F_2 ( V_6 ) ;
V_13 -> V_12 . V_17 = V_18 ;
memcpy ( & V_13 -> V_12 . V_19 . V_20 , V_12 ,
sizeof( V_13 -> V_12 . V_19 . V_20 ) ) ;
V_13 -> V_11 . V_17 = V_18 ;
memcpy ( & V_13 -> V_11 . V_19 . V_20 , V_11 ,
sizeof( V_13 -> V_12 . V_19 . V_20 ) ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
struct V_21 * V_22 ;
struct V_5 * V_23 ;
int V_24 = V_25 ;
F_8 () ;
F_9 (entry, &lowpan_devices, list)
if ( V_1 ( V_22 -> V_26 ) -> V_27 == V_6 -> V_3 ) {
V_23 = F_10 ( V_6 , V_28 ) ;
if ( ! V_23 ) {
V_24 = - V_29 ;
break;
}
V_23 -> V_3 = V_22 -> V_26 ;
V_24 = F_11 ( V_23 ) ;
}
F_12 () ;
return V_24 ;
}
static int F_13 ( struct V_5 * V_6 , const struct V_30 * V_31 )
{
T_1 V_32 , V_33 ;
struct V_34 V_35 , V_36 ;
void * V_37 , * V_38 ;
F_14 ( V_16 , L_3 , V_6 -> V_7 , V_6 -> V_10 ) ;
if ( V_6 -> V_10 < 2 )
goto V_39;
if ( F_15 ( V_6 , & V_32 ) )
goto V_39;
if ( F_15 ( V_6 , & V_33 ) )
goto V_39;
F_16 ( & V_35 , & V_31 -> V_40 ) ;
F_16 ( & V_36 , & V_31 -> V_41 ) ;
if ( V_35 . V_42 == V_43 )
V_37 = & V_35 . V_44 ;
else
V_37 = & V_35 . V_45 ;
if ( V_36 . V_42 == V_43 )
V_38 = & V_36 . V_44 ;
else
V_38 = & V_36 . V_45 ;
return F_17 ( V_6 , V_6 -> V_3 , V_37 , V_35 . V_42 ,
V_46 , V_38 , V_36 . V_42 ,
V_46 , V_32 , V_33 ,
F_7 ) ;
V_39:
F_18 ( V_6 ) ;
return - V_47 ;
}
static int F_19 ( struct V_2 * V_3 , void * V_48 )
{
struct V_49 * V_35 = V_48 ;
if ( F_20 ( V_3 ) )
return - V_50 ;
memcpy ( V_3 -> V_15 , V_35 -> V_51 , V_3 -> V_52 ) ;
return 0 ;
}
static struct V_5 *
F_21 ( struct V_5 * V_6 , int V_53 ,
const struct V_30 * V_54 )
{
struct V_2 * V_27 = V_1 ( V_6 -> V_3 ) -> V_27 ;
struct V_5 * V_55 ;
int V_56 ;
V_55 = F_22 ( V_27 -> V_57 +
V_27 -> V_58 + V_53 ,
V_28 ) ;
if ( F_23 ( V_55 ) ) {
V_55 -> V_3 = V_27 ;
V_55 -> V_59 = V_6 -> V_59 ;
F_24 ( V_55 , V_27 -> V_57 ) ;
F_25 ( V_55 ) ;
* F_26 ( V_55 ) = * F_26 ( V_6 ) ;
V_56 = F_27 ( V_55 , V_27 , 0 , & V_54 -> V_41 ,
& V_54 -> V_40 , V_53 ) ;
if ( V_56 < 0 ) {
F_18 ( V_55 ) ;
return F_28 ( - V_56 ) ;
}
} else {
V_55 = F_28 ( - V_29 ) ;
}
return V_55 ;
}
static int
F_29 ( struct V_5 * V_6 , const struct V_30 * V_60 ,
T_1 * V_61 , int V_62 ,
int V_63 , int V_10 )
{
struct V_5 * V_55 ;
F_6 ( V_16 , L_4 , V_61 , V_62 ) ;
V_55 = F_21 ( V_6 , V_62 + V_10 , V_60 ) ;
if ( F_30 ( V_55 ) )
return - F_31 ( V_55 ) ;
memcpy ( F_32 ( V_55 , V_62 ) , V_61 , V_62 ) ;
memcpy ( F_32 ( V_55 , V_10 ) , F_33 ( V_6 ) + V_63 , V_10 ) ;
F_14 ( V_16 , L_5 , V_55 -> V_7 , V_55 -> V_10 ) ;
return F_34 ( V_55 ) ;
}
static int
F_35 ( struct V_5 * V_6 , struct V_2 * V_3 ,
const struct V_30 * V_60 )
{
T_2 V_64 , V_65 ;
T_3 V_66 ;
T_1 V_61 [ 5 ] ;
int V_67 , V_68 , V_69 , V_56 ;
int V_70 , V_71 ;
V_64 = F_36 ( V_6 , & V_65 ) -
V_6 -> V_72 ;
V_66 = V_1 ( V_3 ) -> V_73 ++ ;
V_61 [ 0 ] = V_74 | ( ( V_64 >> 8 ) & 0x07 ) ;
V_61 [ 1 ] = V_64 & 0xff ;
memcpy ( V_61 + 2 , & V_66 , sizeof( V_66 ) ) ;
V_69 = F_37 ( V_60 ) ;
V_68 = F_38 ( V_69 - V_75 -
F_39 ( V_6 ) , 8 ) ;
V_71 = F_39 ( V_6 ) ;
V_70 = V_6 -> V_10 - V_6 -> V_72 - V_71 ;
V_56 = F_29 ( V_6 , V_60 , V_61 ,
V_75 , 0 ,
V_68 + F_39 ( V_6 ) ) ;
if ( V_56 ) {
F_40 ( L_6 ,
V_16 , V_66 ) ;
goto V_76;
}
V_61 [ 0 ] &= ~ V_74 ;
V_61 [ 0 ] |= V_77 ;
V_67 = F_38 ( V_69 - V_78 , 8 ) ;
do {
V_65 += V_68 ;
V_71 += V_68 ;
V_70 -= V_68 ;
V_68 = F_41 ( V_67 , V_70 ) ;
V_61 [ 4 ] = V_65 >> 3 ;
V_56 = F_29 ( V_6 , V_60 , V_61 ,
V_78 , V_71 ,
V_68 ) ;
if ( V_56 ) {
F_40 ( L_7 ,
V_16 , V_66 , V_71 ) ;
goto V_76;
}
} while ( V_70 > V_67 );
F_42 ( V_6 ) ;
return V_79 ;
V_76:
F_18 ( V_6 ) ;
return V_56 ;
}
static int F_43 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_80 V_35 , V_36 ;
struct V_81 * V_82 = F_44 ( V_6 ) ;
struct V_4 V_13 ;
void * V_12 , * V_11 ;
memcpy ( & V_13 , F_2 ( V_6 ) , sizeof( V_13 ) ) ;
V_12 = & V_13 . V_12 . V_19 . V_20 ;
V_11 = & V_13 . V_11 . V_19 . V_20 ;
F_45 ( V_6 , V_3 , V_14 , V_12 , V_11 , V_6 -> V_10 ) ;
V_82 -> type = V_83 ;
V_35 . V_17 = V_18 ;
V_35 . V_84 = F_46 ( V_3 ) -> F_47 ( V_3 ) ;
V_35 . V_20 = F_48 ( V_11 ) ;
V_36 . V_84 = V_35 . V_84 ;
if ( F_49 ( ( const T_1 * ) V_12 ) ) {
V_36 . V_17 = V_43 ;
V_36 . V_44 = F_50 ( V_85 ) ;
V_82 -> V_86 = false ;
} else {
V_36 . V_17 = V_18 ;
V_36 . V_20 = F_48 ( V_12 ) ;
V_82 -> V_86 = true ;
}
return F_27 ( V_6 , V_1 ( V_3 ) -> V_27 ,
V_14 , ( void * ) & V_36 , ( void * ) & V_35 , 0 ) ;
}
static T_4 F_51 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_30 V_60 ;
int V_87 , V_88 ;
F_40 ( L_8 ) ;
V_6 = F_52 ( V_6 , V_28 ) ;
if ( ! V_6 )
return V_89 ;
V_88 = F_43 ( V_6 , V_3 ) ;
if ( V_88 < 0 ) {
F_18 ( V_6 ) ;
return V_89 ;
}
if ( F_53 ( V_6 , & V_60 ) < 0 ) {
F_18 ( V_6 ) ;
return V_89 ;
}
V_87 = F_37 ( & V_60 ) ;
if ( F_54 ( V_6 ) - F_33 ( V_6 ) <= V_87 ) {
V_6 -> V_3 = V_1 ( V_3 ) -> V_27 ;
return F_34 ( V_6 ) ;
} else {
T_4 V_56 ;
F_40 ( L_9 ) ;
V_56 = F_35 ( V_6 , V_3 , & V_60 ) ;
return V_56 < 0 ? V_89 : V_56 ;
}
}
static struct V_90 * F_55 ( const struct V_2 * V_3 )
{
struct V_2 * V_27 = V_1 ( V_3 ) -> V_27 ;
return F_46 ( V_27 ) -> F_56 ( V_27 ) ;
}
static T_5 F_57 ( const struct V_2 * V_3 )
{
struct V_2 * V_27 = V_1 ( V_3 ) -> V_27 ;
return F_46 ( V_27 ) -> F_47 ( V_27 ) ;
}
static T_5 F_58 ( const struct V_2 * V_3 )
{
struct V_2 * V_27 = V_1 ( V_3 ) -> V_27 ;
return F_46 ( V_27 ) -> F_59 ( V_27 ) ;
}
static T_1 F_60 ( const struct V_2 * V_3 )
{
struct V_2 * V_27 = V_1 ( V_3 ) -> V_27 ;
return F_46 ( V_27 ) -> F_61 ( V_27 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_91 * V_92 ,
void * V_93 )
{
F_63 ( & V_92 -> V_94 ,
& V_95 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
F_65 ( V_3 , F_62 , NULL ) ;
V_3 -> V_96 = & V_97 ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 )
{
V_3 -> V_52 = V_46 ;
memset ( V_3 -> V_98 , 0xff , V_46 ) ;
V_3 -> type = V_99 ;
V_3 -> V_57 = 2 + 1 + 20 + 14 ;
V_3 -> V_58 = 2 ;
V_3 -> V_100 = V_101 ;
V_3 -> V_102 = 0 ;
V_3 -> V_103 = V_104 | V_105 ;
V_3 -> V_106 = 0 ;
V_3 -> V_107 = & V_108 ;
V_3 -> V_109 = & V_110 ;
V_3 -> V_111 = & V_112 ;
V_3 -> V_113 = V_114 ;
}
static int F_67 ( struct V_115 * V_116 [] , struct V_115 * V_7 [] )
{
if ( V_116 [ V_117 ] ) {
if ( F_68 ( V_116 [ V_117 ] ) != V_46 )
return - V_47 ;
}
return 0 ;
}
static int F_69 ( struct V_5 * V_6 , struct V_2 * V_3 ,
struct V_118 * V_119 , struct V_2 * V_120 )
{
struct V_30 V_31 ;
int V_88 ;
V_6 = F_70 ( V_6 , V_28 ) ;
if ( ! V_6 )
goto V_39;
if ( ! F_20 ( V_3 ) )
goto V_121;
if ( V_3 -> type != V_99 )
goto V_121;
if ( F_71 ( V_6 , & V_31 ) < 0 )
goto V_121;
if ( V_6 -> V_7 [ 0 ] == V_122 ) {
V_6 -> V_123 = F_72 ( V_14 ) ;
V_6 -> V_124 = V_125 ;
F_73 ( V_6 , 1 ) ;
V_88 = F_7 ( V_6 , NULL ) ;
if ( V_88 == V_126 )
goto V_39;
} else {
switch ( V_6 -> V_7 [ 0 ] & 0xe0 ) {
case V_127 :
V_88 = F_13 ( V_6 , & V_31 ) ;
if ( V_88 == V_126 )
goto V_39;
break;
case V_74 :
V_88 = F_74 ( V_6 , V_74 ) ;
if ( V_88 == 1 ) {
V_88 = F_13 ( V_6 , & V_31 ) ;
if ( V_88 == V_126 )
goto V_39;
}
break;
case V_77 :
V_88 = F_74 ( V_6 , V_77 ) ;
if ( V_88 == 1 ) {
V_88 = F_13 ( V_6 , & V_31 ) ;
if ( V_88 == V_126 )
goto V_39;
}
break;
default:
break;
}
}
return V_25 ;
V_121:
F_18 ( V_6 ) ;
V_39:
return V_126 ;
}
static int F_75 ( struct V_128 * V_129 , struct V_2 * V_3 ,
struct V_115 * V_116 [] , struct V_115 * V_7 [] )
{
struct V_2 * V_27 ;
struct V_21 * V_22 ;
F_40 ( L_10 ) ;
if ( ! V_116 [ V_130 ] )
return - V_47 ;
V_27 = F_76 ( V_129 , F_77 ( V_116 [ V_130 ] ) ) ;
if ( ! V_27 )
return - V_131 ;
if ( V_27 -> type != V_99 ) {
F_78 ( V_27 ) ;
return - V_47 ;
}
V_1 ( V_3 ) -> V_27 = V_27 ;
F_79 ( & V_1 ( V_3 ) -> V_132 ) ;
V_22 = F_80 ( sizeof( * V_22 ) , V_133 ) ;
if ( ! V_22 ) {
F_78 ( V_27 ) ;
V_1 ( V_3 ) -> V_27 = NULL ;
return - V_29 ;
}
V_22 -> V_26 = V_3 ;
memcpy ( V_3 -> V_15 , V_27 -> V_15 , V_46 ) ;
F_81 ( & V_1 ( V_3 ) -> V_132 ) ;
F_82 ( & V_22 -> V_134 ) ;
F_83 ( & V_22 -> V_134 , & V_135 ) ;
F_84 ( & V_1 ( V_3 ) -> V_132 ) ;
F_85 ( V_3 ) ;
return 0 ;
}
static void F_86 ( struct V_2 * V_3 , struct V_136 * V_137 )
{
struct V_1 * V_138 = V_1 ( V_3 ) ;
struct V_2 * V_27 = V_138 -> V_27 ;
struct V_21 * V_22 , * V_139 ;
F_87 () ;
F_81 ( & V_1 ( V_3 ) -> V_132 ) ;
F_88 (entry, tmp, &lowpan_devices, list) {
if ( V_22 -> V_26 == V_3 ) {
F_89 ( & V_22 -> V_134 ) ;
F_90 ( V_22 ) ;
}
}
F_84 ( & V_1 ( V_3 ) -> V_132 ) ;
F_91 ( & V_1 ( V_3 ) -> V_132 ) ;
F_92 ( V_3 , V_137 ) ;
F_78 ( V_27 ) ;
}
static inline int T_6 F_93 ( void )
{
return F_94 ( & V_140 ) ;
}
static inline void F_95 ( void )
{
F_96 ( & V_140 ) ;
}
static int F_97 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
struct V_2 * V_3 = F_98 ( V_144 ) ;
F_99 ( V_145 ) ;
struct V_21 * V_22 , * V_139 ;
if ( V_3 -> type != V_99 )
goto V_146;
if ( V_143 == V_147 ) {
F_88 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_22 -> V_26 ) -> V_27 == V_3 )
F_86 ( V_22 -> V_26 , & V_145 ) ;
}
F_100 ( & V_145 ) ;
}
V_146:
return V_148 ;
}
static int T_6 F_101 ( void )
{
int V_76 = 0 ;
V_76 = F_102 () ;
if ( V_76 < 0 )
goto V_146;
V_76 = F_93 () ;
if ( V_76 < 0 )
goto V_149;
F_103 ( & V_150 ) ;
V_76 = F_104 ( & V_151 ) ;
if ( V_76 < 0 )
goto V_152;
return 0 ;
V_152:
F_105 ( & V_150 ) ;
F_95 () ;
V_149:
F_106 () ;
V_146:
return V_76 ;
}
static void T_7 F_107 ( void )
{
F_95 () ;
F_105 ( & V_150 ) ;
F_106 () ;
F_108 ( & V_151 ) ;
}
