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
static int F_3 ( struct V_8 * V_9 , struct V_2 * V_3 ,
unsigned short type , const void * V_10 ,
const void * V_11 , unsigned int V_12 )
{
const T_1 * V_13 = V_11 ;
const T_1 * V_14 = V_10 ;
struct V_15 V_16 , V_17 ;
struct V_18 * V_19 = F_4 ( V_9 ) ;
if ( type != V_20 )
return 0 ;
if ( ! V_13 )
V_13 = V_3 -> V_21 ;
F_5 ( V_22 , L_1 , ( unsigned char * ) V_13 , 8 ) ;
F_5 ( V_22 , L_2 , ( unsigned char * ) V_14 , 8 ) ;
F_6 ( V_9 , V_3 , type , V_14 , V_13 , V_12 ) ;
V_19 -> type = V_23 ;
V_16 . V_24 = V_25 ;
V_16 . V_26 = F_7 ( V_3 ) -> F_8 ( V_3 ) ;
V_16 . V_27 = F_9 ( V_13 ) ;
V_17 . V_26 = V_16 . V_26 ;
if ( F_10 ( V_14 ) ) {
V_17 . V_24 = V_28 ;
V_17 . V_29 = F_11 ( V_30 ) ;
} else {
V_17 . V_24 = V_25 ;
V_17 . V_27 = F_9 ( V_14 ) ;
}
V_19 -> V_31 = ! F_10 ( V_14 ) ;
return F_12 ( V_9 , V_1 ( V_3 ) -> V_32 ,
type , ( void * ) & V_17 , ( void * ) & V_16 , 0 ) ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_8 * V_35 ;
int V_36 = V_37 ;
F_14 () ;
F_15 (entry, &lowpan_devices, list)
if ( V_1 ( V_34 -> V_38 ) -> V_32 == V_9 -> V_3 ) {
V_35 = F_16 ( V_9 , V_39 ) ;
if ( ! V_35 ) {
V_36 = - V_40 ;
break;
}
V_35 -> V_3 = V_34 -> V_38 ;
V_36 = F_17 ( V_35 ) ;
}
F_18 () ;
return V_36 ;
}
static int F_19 ( struct V_8 * V_9 , const struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
struct V_45 V_16 , V_17 ;
void * V_46 , * V_47 ;
F_20 ( V_22 , L_3 , V_9 -> V_48 , V_9 -> V_12 ) ;
if ( V_9 -> V_12 < 2 )
goto V_49;
if ( F_21 ( V_9 , & V_43 ) )
goto V_49;
if ( F_21 ( V_9 , & V_44 ) )
goto V_49;
F_22 ( & V_16 , & V_42 -> V_50 ) ;
F_22 ( & V_17 , & V_42 -> V_5 ) ;
if ( V_16 . V_51 == V_28 )
V_46 = & V_16 . V_29 ;
else
V_46 = & V_16 . V_52 ;
if ( V_17 . V_51 == V_28 )
V_47 = & V_17 . V_29 ;
else
V_47 = & V_17 . V_52 ;
return F_23 ( V_9 , V_9 -> V_3 , V_46 , V_16 . V_51 ,
V_7 , V_47 , V_17 . V_51 ,
V_7 , V_43 , V_44 ,
F_13 ) ;
V_49:
F_24 ( V_9 ) ;
return - V_53 ;
}
static int F_25 ( struct V_2 * V_3 , void * V_54 )
{
struct V_55 * V_16 = V_54 ;
if ( F_26 ( V_3 ) )
return - V_56 ;
memcpy ( V_3 -> V_21 , V_16 -> V_57 , V_3 -> V_58 ) ;
return 0 ;
}
static struct V_8 *
F_27 ( struct V_8 * V_9 , int V_59 ,
const struct V_41 * V_60 )
{
struct V_2 * V_32 = V_1 ( V_9 -> V_3 ) -> V_32 ;
struct V_8 * V_61 ;
int V_62 ;
V_61 = F_28 ( V_32 -> V_63 +
V_32 -> V_64 + V_59 ,
V_39 ) ;
if ( F_29 ( V_61 ) ) {
V_61 -> V_3 = V_32 ;
V_61 -> V_65 = V_9 -> V_65 ;
F_30 ( V_61 , V_32 -> V_63 ) ;
F_31 ( V_61 ) ;
* F_32 ( V_61 ) = * F_32 ( V_9 ) ;
V_62 = F_12 ( V_61 , V_32 , 0 , & V_60 -> V_5 ,
& V_60 -> V_50 , V_59 ) ;
if ( V_62 < 0 ) {
F_24 ( V_61 ) ;
return F_33 ( - V_62 ) ;
}
} else {
V_61 = F_33 ( - V_40 ) ;
}
return V_61 ;
}
static int
F_34 ( struct V_8 * V_9 , const struct V_41 * V_66 ,
T_1 * V_67 , int V_68 ,
int V_69 , int V_12 )
{
struct V_8 * V_61 ;
F_5 ( V_22 , L_4 , V_67 , V_68 ) ;
V_61 = F_27 ( V_9 , V_68 + V_12 , V_66 ) ;
if ( F_35 ( V_61 ) )
return - F_36 ( V_61 ) ;
memcpy ( F_37 ( V_61 , V_68 ) , V_67 , V_68 ) ;
memcpy ( F_37 ( V_61 , V_12 ) , F_38 ( V_9 ) + V_69 , V_12 ) ;
F_20 ( V_22 , L_5 , V_61 -> V_48 , V_61 -> V_12 ) ;
return F_39 ( V_61 ) ;
}
static int
F_40 ( struct V_8 * V_9 , struct V_2 * V_3 ,
const struct V_41 * V_66 )
{
T_2 V_70 , V_71 ;
T_3 V_72 ;
T_1 V_67 [ 5 ] ;
int V_73 , V_74 , V_75 , V_62 ;
int V_76 , V_77 ;
V_70 = F_41 ( V_9 , & V_71 ) -
V_9 -> V_78 ;
V_72 = V_1 ( V_3 ) -> V_79 ++ ;
V_67 [ 0 ] = V_80 | ( ( V_70 >> 8 ) & 0x07 ) ;
V_67 [ 1 ] = V_70 & 0xff ;
memcpy ( V_67 + 2 , & V_72 , sizeof( V_72 ) ) ;
V_75 = F_42 ( V_66 ) ;
V_74 = F_43 ( V_75 - V_81 -
F_44 ( V_9 ) , 8 ) ;
V_77 = F_44 ( V_9 ) ;
V_76 = V_9 -> V_12 - V_9 -> V_78 - V_77 ;
V_62 = F_34 ( V_9 , V_66 , V_67 ,
V_81 , 0 ,
V_74 + F_44 ( V_9 ) ) ;
if ( V_62 ) {
F_45 ( L_6 ,
V_22 , V_72 ) ;
goto V_82;
}
V_67 [ 0 ] &= ~ V_80 ;
V_67 [ 0 ] |= V_83 ;
V_73 = F_43 ( V_75 - V_84 , 8 ) ;
do {
V_71 += V_74 ;
V_77 += V_74 ;
V_76 -= V_74 ;
V_74 = F_46 ( V_73 , V_76 ) ;
V_67 [ 4 ] = V_71 >> 3 ;
V_62 = F_34 ( V_9 , V_66 , V_67 ,
V_84 , V_77 ,
V_74 ) ;
if ( V_62 ) {
F_45 ( L_7 ,
V_22 , V_72 , V_77 ) ;
goto V_82;
}
} while ( V_76 > V_73 );
F_47 ( V_9 ) ;
return V_85 ;
V_82:
F_24 ( V_9 ) ;
return V_62 ;
}
static T_4 F_48 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
struct V_41 V_66 ;
int V_86 ;
F_45 ( L_8 ) ;
if ( F_49 ( V_9 , & V_66 ) < 0 ) {
F_24 ( V_9 ) ;
return V_87 ;
}
V_86 = F_42 ( & V_66 ) ;
if ( F_50 ( V_9 ) - F_38 ( V_9 ) <= V_86 ) {
V_9 -> V_3 = V_1 ( V_3 ) -> V_32 ;
return F_39 ( V_9 ) ;
} else {
T_4 V_62 ;
F_45 ( L_9 ) ;
V_62 = F_40 ( V_9 , V_3 , & V_66 ) ;
return V_62 < 0 ? V_87 : V_62 ;
}
}
static struct V_88 * F_51 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_52 ( V_32 ) ;
}
static T_5 F_53 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_8 ( V_32 ) ;
}
static T_5 F_54 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_55 ( V_32 ) ;
}
static T_1 F_56 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_57 ( V_32 ) ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_89 * V_90 ,
void * V_91 )
{
F_59 ( & V_90 -> V_92 ,
& V_93 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
F_61 ( V_3 , F_58 , NULL ) ;
V_3 -> V_94 = & V_95 ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
V_3 -> V_58 = V_7 ;
memset ( V_3 -> V_96 , 0xff , V_7 ) ;
V_3 -> type = V_97 ;
V_3 -> V_63 = 2 + 1 + 20 + 14 ;
V_3 -> V_64 = 2 ;
V_3 -> V_98 = V_99 ;
V_3 -> V_100 = 0 ;
V_3 -> V_101 = V_102 | V_103 ;
V_3 -> V_104 = 0 ;
V_3 -> V_105 = & V_106 ;
V_3 -> V_107 = & V_108 ;
V_3 -> V_109 = & V_110 ;
V_3 -> V_111 = V_112 ;
}
static int F_63 ( struct V_113 * V_114 [] , struct V_113 * V_48 [] )
{
if ( V_114 [ V_115 ] ) {
if ( F_64 ( V_114 [ V_115 ] ) != V_7 )
return - V_53 ;
}
return 0 ;
}
static int F_65 ( struct V_8 * V_9 , struct V_2 * V_3 ,
struct V_116 * V_117 , struct V_2 * V_118 )
{
struct V_41 V_42 ;
int V_119 ;
V_9 = F_66 ( V_9 , V_39 ) ;
if ( ! V_9 )
goto V_49;
if ( ! F_26 ( V_3 ) )
goto V_120;
if ( V_3 -> type != V_97 )
goto V_120;
if ( F_67 ( V_9 , & V_42 ) < 0 )
goto V_120;
if ( V_9 -> V_48 [ 0 ] == V_121 ) {
V_9 -> V_122 = F_68 ( V_20 ) ;
V_9 -> V_123 = V_124 ;
F_69 ( V_9 , 1 ) ;
V_119 = F_13 ( V_9 , NULL ) ;
if ( V_119 == V_125 )
goto V_49;
} else {
switch ( V_9 -> V_48 [ 0 ] & 0xe0 ) {
case V_126 :
V_119 = F_19 ( V_9 , & V_42 ) ;
if ( V_119 == V_125 )
goto V_49;
break;
case V_80 :
V_119 = F_70 ( V_9 , V_80 ) ;
if ( V_119 == 1 ) {
V_119 = F_19 ( V_9 , & V_42 ) ;
if ( V_119 == V_125 )
goto V_49;
}
break;
case V_83 :
V_119 = F_70 ( V_9 , V_83 ) ;
if ( V_119 == 1 ) {
V_119 = F_19 ( V_9 , & V_42 ) ;
if ( V_119 == V_125 )
goto V_49;
}
break;
default:
break;
}
}
return V_37 ;
V_120:
F_24 ( V_9 ) ;
V_49:
return V_125 ;
}
static int F_71 ( struct V_127 * V_128 , struct V_2 * V_3 ,
struct V_113 * V_114 [] , struct V_113 * V_48 [] )
{
struct V_2 * V_32 ;
struct V_33 * V_34 ;
F_45 ( L_10 ) ;
if ( ! V_114 [ V_129 ] )
return - V_53 ;
V_32 = F_72 ( V_128 , F_73 ( V_114 [ V_129 ] ) ) ;
if ( ! V_32 )
return - V_130 ;
if ( V_32 -> type != V_97 ) {
F_74 ( V_32 ) ;
return - V_53 ;
}
V_1 ( V_3 ) -> V_32 = V_32 ;
F_75 ( & V_1 ( V_3 ) -> V_131 ) ;
V_34 = F_76 ( sizeof( * V_34 ) , V_132 ) ;
if ( ! V_34 ) {
F_74 ( V_32 ) ;
V_1 ( V_3 ) -> V_32 = NULL ;
return - V_40 ;
}
V_34 -> V_38 = V_3 ;
memcpy ( V_3 -> V_21 , V_32 -> V_21 , V_7 ) ;
F_77 ( & V_1 ( V_3 ) -> V_131 ) ;
F_78 ( & V_34 -> V_133 ) ;
F_79 ( & V_34 -> V_133 , & V_134 ) ;
F_80 ( & V_1 ( V_3 ) -> V_131 ) ;
F_81 ( V_3 ) ;
return 0 ;
}
static void F_82 ( struct V_2 * V_3 , struct V_135 * V_136 )
{
struct V_1 * V_137 = V_1 ( V_3 ) ;
struct V_2 * V_32 = V_137 -> V_32 ;
struct V_33 * V_34 , * V_138 ;
F_83 () ;
F_77 ( & V_1 ( V_3 ) -> V_131 ) ;
F_84 (entry, tmp, &lowpan_devices, list) {
if ( V_34 -> V_38 == V_3 ) {
F_85 ( & V_34 -> V_133 ) ;
F_86 ( V_34 ) ;
}
}
F_80 ( & V_1 ( V_3 ) -> V_131 ) ;
F_87 ( & V_1 ( V_3 ) -> V_131 ) ;
F_88 ( V_3 , V_136 ) ;
F_74 ( V_32 ) ;
}
static inline int T_6 F_89 ( void )
{
return F_90 ( & V_139 ) ;
}
static inline void F_91 ( void )
{
F_92 ( & V_139 ) ;
}
static int F_93 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_2 * V_3 = F_94 ( V_143 ) ;
F_95 ( V_144 ) ;
struct V_33 * V_34 , * V_138 ;
if ( V_3 -> type != V_97 )
goto V_145;
if ( V_142 == V_146 ) {
F_84 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_34 -> V_38 ) -> V_32 == V_3 )
F_82 ( V_34 -> V_38 , & V_144 ) ;
}
F_96 ( & V_144 ) ;
}
V_145:
return V_147 ;
}
static int T_6 F_97 ( void )
{
int V_82 = 0 ;
V_82 = F_98 () ;
if ( V_82 < 0 )
goto V_145;
V_82 = F_89 () ;
if ( V_82 < 0 )
goto V_148;
F_99 ( & V_149 ) ;
V_82 = F_100 ( & V_150 ) ;
if ( V_82 < 0 )
goto V_151;
return 0 ;
V_151:
F_101 ( & V_149 ) ;
F_91 () ;
V_148:
F_102 () ;
V_145:
return V_82 ;
}
static void T_7 F_103 ( void )
{
F_91 () ;
F_101 ( & V_149 ) ;
F_102 () ;
F_104 ( & V_150 ) ;
}
