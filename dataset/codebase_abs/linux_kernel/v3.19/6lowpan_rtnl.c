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
V_6 -> V_26 = F_8 ( V_14 ) ;
V_6 -> V_27 = V_28 ;
F_9 () ;
F_10 (entry, &lowpan_devices, list)
if ( V_1 ( V_22 -> V_29 ) -> V_30 == V_6 -> V_3 ) {
V_23 = F_11 ( V_6 , V_31 ) ;
if ( ! V_23 ) {
F_12 ( V_6 ) ;
F_13 () ;
return V_32 ;
}
V_23 -> V_3 = V_22 -> V_29 ;
V_24 = F_14 ( V_23 ) ;
if ( V_24 == V_32 )
break;
}
F_13 () ;
F_15 ( V_6 ) ;
return V_24 ;
}
static int
F_16 ( struct V_5 * V_6 , const struct V_33 * V_34 )
{
T_1 V_35 , V_36 ;
struct V_37 V_38 , V_39 ;
void * V_40 , * V_41 ;
F_17 ( V_16 , L_3 , V_6 -> V_7 , V_6 -> V_10 ) ;
if ( V_6 -> V_10 < 2 )
return - V_42 ;
if ( F_18 ( V_6 , & V_35 ) )
return - V_42 ;
if ( F_18 ( V_6 , & V_36 ) )
return - V_42 ;
F_19 ( & V_38 , & V_34 -> V_43 ) ;
F_19 ( & V_39 , & V_34 -> V_44 ) ;
if ( V_38 . V_45 == V_46 )
V_40 = & V_38 . V_47 ;
else
V_40 = & V_38 . V_48 ;
if ( V_39 . V_45 == V_46 )
V_41 = & V_39 . V_47 ;
else
V_41 = & V_39 . V_48 ;
return F_20 ( V_6 , V_6 -> V_3 , V_40 , V_38 . V_45 ,
V_49 , V_41 , V_39 . V_45 ,
V_49 , V_35 , V_36 ) ;
}
static struct V_5 *
F_21 ( struct V_5 * V_6 , int V_50 ,
const struct V_33 * V_51 )
{
struct V_2 * V_30 = V_1 ( V_6 -> V_3 ) -> V_30 ;
struct V_5 * V_52 ;
int V_53 ;
V_52 = F_22 ( V_30 -> V_54 +
V_30 -> V_55 + V_50 ,
V_31 ) ;
if ( F_23 ( V_52 ) ) {
V_52 -> V_3 = V_30 ;
V_52 -> V_56 = V_6 -> V_56 ;
F_24 ( V_52 , V_30 -> V_54 ) ;
F_25 ( V_52 ) ;
* F_26 ( V_52 ) = * F_26 ( V_6 ) ;
V_53 = F_27 ( V_52 , V_30 , 0 , & V_51 -> V_44 ,
& V_51 -> V_43 , V_50 ) ;
if ( V_53 < 0 ) {
F_12 ( V_52 ) ;
return F_28 ( V_53 ) ;
}
} else {
V_52 = F_28 ( - V_57 ) ;
}
return V_52 ;
}
static int
F_29 ( struct V_5 * V_6 , const struct V_33 * V_58 ,
T_1 * V_59 , int V_60 ,
int V_61 , int V_10 )
{
struct V_5 * V_52 ;
F_6 ( V_16 , L_4 , V_59 , V_60 ) ;
V_52 = F_21 ( V_6 , V_60 + V_10 , V_58 ) ;
if ( F_30 ( V_52 ) )
return - F_31 ( V_52 ) ;
memcpy ( F_32 ( V_52 , V_60 ) , V_59 , V_60 ) ;
memcpy ( F_32 ( V_52 , V_10 ) , F_33 ( V_6 ) + V_61 , V_10 ) ;
F_17 ( V_16 , L_5 , V_52 -> V_7 , V_52 -> V_10 ) ;
return F_34 ( V_52 ) ;
}
static int
F_35 ( struct V_5 * V_6 , struct V_2 * V_3 ,
const struct V_33 * V_58 )
{
T_2 V_62 , V_63 ;
T_3 V_64 ;
T_1 V_59 [ 5 ] ;
int V_65 , V_66 , V_67 , V_53 ;
int V_68 , V_69 ;
V_62 = F_36 ( V_6 , & V_63 ) -
V_6 -> V_70 ;
V_64 = F_8 ( V_1 ( V_3 ) -> V_71 ) ;
V_1 ( V_3 ) -> V_71 ++ ;
V_59 [ 0 ] = V_72 | ( ( V_62 >> 8 ) & 0x07 ) ;
V_59 [ 1 ] = V_62 & 0xff ;
memcpy ( V_59 + 2 , & V_64 , sizeof( V_64 ) ) ;
V_67 = F_37 ( V_58 ) ;
V_66 = F_38 ( V_67 - V_73 -
F_39 ( V_6 ) , 8 ) ;
V_69 = F_39 ( V_6 ) ;
V_68 = V_6 -> V_10 - V_6 -> V_70 - V_69 ;
V_53 = F_29 ( V_6 , V_58 , V_59 ,
V_73 , 0 ,
V_66 + F_39 ( V_6 ) ) ;
if ( V_53 ) {
F_40 ( L_6 ,
V_16 , F_41 ( V_64 ) ) ;
goto V_74;
}
V_59 [ 0 ] &= ~ V_72 ;
V_59 [ 0 ] |= V_75 ;
V_65 = F_38 ( V_67 - V_76 , 8 ) ;
do {
V_63 += V_66 ;
V_69 += V_66 ;
V_68 -= V_66 ;
V_66 = F_42 ( V_65 , V_68 ) ;
V_59 [ 4 ] = V_63 >> 3 ;
V_53 = F_29 ( V_6 , V_58 , V_59 ,
V_76 , V_69 ,
V_66 ) ;
if ( V_53 ) {
F_40 ( L_7 ,
V_16 , F_41 ( V_64 ) , V_69 ) ;
goto V_74;
}
} while ( V_68 > V_65 );
F_15 ( V_6 ) ;
return V_77 ;
V_74:
F_12 ( V_6 ) ;
return V_53 ;
}
static int F_43 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_78 V_38 , V_39 ;
struct V_79 * V_80 = F_44 ( V_6 ) ;
struct V_4 V_13 ;
void * V_12 , * V_11 ;
memcpy ( & V_13 , F_2 ( V_6 ) , sizeof( V_13 ) ) ;
V_12 = & V_13 . V_12 . V_19 . V_20 ;
V_11 = & V_13 . V_11 . V_19 . V_20 ;
F_45 ( V_6 , V_3 , V_14 , V_12 , V_11 , V_6 -> V_10 ) ;
V_80 -> type = V_81 ;
V_38 . V_17 = V_18 ;
V_38 . V_82 = F_46 ( V_3 ) -> F_47 ( V_3 ) ;
V_38 . V_20 = F_48 ( V_11 ) ;
V_39 . V_82 = V_38 . V_82 ;
if ( F_49 ( ( const T_1 * ) V_12 ) ) {
V_39 . V_17 = V_46 ;
V_39 . V_47 = F_50 ( V_83 ) ;
V_80 -> V_84 = false ;
} else {
V_39 . V_17 = V_18 ;
V_39 . V_20 = F_48 ( V_12 ) ;
V_80 -> V_84 = true ;
}
return F_27 ( V_6 , V_1 ( V_3 ) -> V_30 ,
V_14 , ( void * ) & V_39 , ( void * ) & V_38 , 0 ) ;
}
static T_4 F_51 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_33 V_58 ;
int V_85 , V_86 ;
F_40 ( L_8 ) ;
V_6 = F_52 ( V_6 , V_31 ) ;
if ( ! V_6 )
return V_87 ;
V_86 = F_43 ( V_6 , V_3 ) ;
if ( V_86 < 0 ) {
F_12 ( V_6 ) ;
return V_87 ;
}
if ( F_53 ( V_6 , & V_58 ) < 0 ) {
F_12 ( V_6 ) ;
return V_87 ;
}
V_85 = F_37 ( & V_58 ) ;
if ( F_54 ( V_6 ) - F_33 ( V_6 ) <= V_85 ) {
V_6 -> V_3 = V_1 ( V_3 ) -> V_30 ;
return F_34 ( V_6 ) ;
} else {
T_4 V_53 ;
F_40 ( L_9 ) ;
V_53 = F_35 ( V_6 , V_3 , & V_58 ) ;
return V_53 < 0 ? V_87 : V_53 ;
}
}
static T_5 F_55 ( const struct V_2 * V_3 )
{
struct V_2 * V_30 = V_1 ( V_3 ) -> V_30 ;
return F_46 ( V_30 ) -> F_47 ( V_30 ) ;
}
static T_5 F_56 ( const struct V_2 * V_3 )
{
struct V_2 * V_30 = V_1 ( V_3 ) -> V_30 ;
return F_46 ( V_30 ) -> F_57 ( V_30 ) ;
}
static T_1 F_58 ( const struct V_2 * V_3 )
{
struct V_2 * V_30 = V_1 ( V_3 ) -> V_30 ;
return F_46 ( V_30 ) -> F_59 ( V_30 ) ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_88 * V_89 ,
void * V_90 )
{
F_61 ( & V_89 -> V_91 ,
& V_92 ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
F_63 ( V_3 , F_60 , NULL ) ;
V_3 -> V_93 = & V_94 ;
return 0 ;
}
static void F_64 ( struct V_2 * V_3 )
{
V_3 -> V_95 = V_49 ;
memset ( V_3 -> V_96 , 0xff , V_49 ) ;
V_3 -> type = V_97 ;
V_3 -> V_54 = 2 + 1 + 20 + 14 ;
V_3 -> V_55 = 2 ;
V_3 -> V_98 = V_99 ;
V_3 -> V_100 = 0 ;
V_3 -> V_101 = V_102 | V_103 ;
V_3 -> V_104 = 0 ;
V_3 -> V_105 = & V_106 ;
V_3 -> V_107 = & V_108 ;
V_3 -> V_109 = & V_110 ;
V_3 -> V_111 = V_112 ;
}
static int F_65 ( struct V_113 * V_114 [] , struct V_113 * V_7 [] )
{
if ( V_114 [ V_115 ] ) {
if ( F_66 ( V_114 [ V_115 ] ) != V_49 )
return - V_42 ;
}
return 0 ;
}
static int F_67 ( struct V_5 * V_6 , struct V_2 * V_3 ,
struct V_116 * V_117 , struct V_2 * V_118 )
{
struct V_33 V_34 ;
int V_86 ;
V_6 = F_68 ( V_6 , V_31 ) ;
if ( ! V_6 )
goto V_119;
if ( ! F_69 ( V_3 ) )
goto V_120;
if ( V_6 -> V_27 == V_121 )
goto V_120;
if ( V_3 -> type != V_97 )
goto V_120;
if ( F_70 ( V_6 , & V_34 ) < 0 )
goto V_120;
if ( V_6 -> V_7 [ 0 ] == V_122 ) {
F_71 ( V_6 , 1 ) ;
return F_7 ( V_6 , NULL ) ;
} else {
switch ( V_6 -> V_7 [ 0 ] & 0xe0 ) {
case V_123 :
V_86 = F_16 ( V_6 , & V_34 ) ;
if ( V_86 < 0 )
goto V_120;
return F_7 ( V_6 , NULL ) ;
case V_72 :
V_86 = F_72 ( V_6 , V_72 ) ;
if ( V_86 == 1 ) {
V_86 = F_16 ( V_6 , & V_34 ) ;
if ( V_86 < 0 )
goto V_120;
return F_7 ( V_6 , NULL ) ;
} else if ( V_86 == - 1 ) {
return V_32 ;
} else {
return V_25 ;
}
case V_75 :
V_86 = F_72 ( V_6 , V_75 ) ;
if ( V_86 == 1 ) {
V_86 = F_16 ( V_6 , & V_34 ) ;
if ( V_86 < 0 )
goto V_120;
return F_7 ( V_6 , NULL ) ;
} else if ( V_86 == - 1 ) {
return V_32 ;
} else {
return V_25 ;
}
default:
break;
}
}
V_120:
F_12 ( V_6 ) ;
V_119:
return V_32 ;
}
static int F_73 ( struct V_124 * V_125 , struct V_2 * V_3 ,
struct V_113 * V_114 [] , struct V_113 * V_7 [] )
{
struct V_2 * V_30 ;
struct V_21 * V_22 ;
int V_86 ;
F_74 () ;
F_40 ( L_10 ) ;
if ( ! V_114 [ V_126 ] )
return - V_42 ;
V_30 = F_75 ( V_125 , F_76 ( V_114 [ V_126 ] ) ) ;
if ( ! V_30 )
return - V_127 ;
if ( V_30 -> type != V_97 ) {
F_77 ( V_30 ) ;
return - V_42 ;
}
V_1 ( V_3 ) -> V_30 = V_30 ;
F_78 ( & V_1 ( V_3 ) -> V_128 ) ;
V_22 = F_79 ( sizeof( * V_22 ) , V_129 ) ;
if ( ! V_22 ) {
F_77 ( V_30 ) ;
V_1 ( V_3 ) -> V_30 = NULL ;
return - V_57 ;
}
V_22 -> V_29 = V_3 ;
memcpy ( V_3 -> V_15 , V_30 -> V_15 , V_49 ) ;
F_80 ( & V_1 ( V_3 ) -> V_128 ) ;
F_81 ( & V_22 -> V_130 ) ;
F_82 ( & V_22 -> V_130 , & V_131 ) ;
F_83 ( & V_1 ( V_3 ) -> V_128 ) ;
V_86 = F_84 ( V_3 ) ;
if ( V_86 >= 0 ) {
if ( ! V_132 )
F_85 ( & V_133 ) ;
V_132 ++ ;
}
return V_86 ;
}
static void F_86 ( struct V_2 * V_3 , struct V_134 * V_135 )
{
struct V_1 * V_136 = V_1 ( V_3 ) ;
struct V_2 * V_30 = V_136 -> V_30 ;
struct V_21 * V_22 , * V_137 ;
F_74 () ;
V_132 -- ;
if ( ! V_132 )
F_87 ( & V_133 ) ;
F_80 ( & V_1 ( V_3 ) -> V_128 ) ;
F_88 (entry, tmp, &lowpan_devices, list) {
if ( V_22 -> V_29 == V_3 ) {
F_89 ( & V_22 -> V_130 ) ;
F_90 ( V_22 ) ;
}
}
F_83 ( & V_1 ( V_3 ) -> V_128 ) ;
F_91 ( & V_1 ( V_3 ) -> V_128 ) ;
F_92 ( V_3 , V_135 ) ;
F_77 ( V_30 ) ;
}
static inline int T_6 F_93 ( void )
{
return F_94 ( & V_138 ) ;
}
static inline void F_95 ( void )
{
F_96 ( & V_138 ) ;
}
static int F_97 ( struct V_139 * V_140 ,
unsigned long V_141 , void * V_142 )
{
struct V_2 * V_3 = F_98 ( V_142 ) ;
F_99 ( V_143 ) ;
struct V_21 * V_22 , * V_137 ;
if ( V_3 -> type != V_97 )
goto V_144;
if ( V_141 == V_145 ) {
F_88 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_22 -> V_29 ) -> V_30 == V_3 )
F_86 ( V_22 -> V_29 , & V_143 ) ;
}
F_100 ( & V_143 ) ;
}
V_144:
return V_146 ;
}
static int T_6 F_101 ( void )
{
int V_74 = 0 ;
V_74 = F_102 () ;
if ( V_74 < 0 )
goto V_144;
V_74 = F_93 () ;
if ( V_74 < 0 )
goto V_147;
V_74 = F_103 ( & V_148 ) ;
if ( V_74 < 0 )
goto V_149;
return 0 ;
V_149:
F_95 () ;
V_147:
F_104 () ;
V_144:
return V_74 ;
}
static void T_7 F_105 ( void )
{
F_95 () ;
F_104 () ;
F_106 ( & V_148 ) ;
}
