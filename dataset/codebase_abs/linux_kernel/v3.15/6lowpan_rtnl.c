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
static int F_3 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
unsigned short type , const void * V_10 ,
const void * V_11 , unsigned int V_12 )
{
const T_1 * V_13 = V_11 ;
const T_1 * V_14 = V_10 ;
struct V_15 V_16 , V_17 ;
if ( type != V_18 )
return 0 ;
if ( ! V_13 )
V_13 = V_3 -> V_19 ;
F_4 ( V_20 , L_1 , ( unsigned char * ) V_13 , 8 ) ;
F_4 ( V_20 , L_2 , ( unsigned char * ) V_14 , 8 ) ;
F_5 ( V_9 , V_3 , type , V_14 , V_13 , V_12 ) ;
F_6 ( V_9 ) -> V_21 = V_22 ;
F_6 ( V_9 ) -> V_23 = F_7 ( V_3 ) -> F_8 ( V_3 ) ;
V_16 . V_24 = V_25 ;
V_16 . V_26 = F_7 ( V_3 ) -> F_9 ( V_3 ) ;
V_16 . V_27 = F_10 ( V_13 ) ;
V_17 . V_26 = V_16 . V_26 ;
if ( F_11 ( V_14 ) ) {
V_17 . V_24 = V_28 ;
V_17 . V_29 = F_12 ( V_30 ) ;
} else {
V_17 . V_24 = V_25 ;
V_17 . V_27 = F_10 ( V_14 ) ;
F_6 ( V_9 ) -> V_21 |= V_31 ;
}
return F_13 ( V_9 , V_1 ( V_3 ) -> V_32 ,
type , ( void * ) & V_17 , ( void * ) & V_16 , 0 ) ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_8 * V_35 ;
int V_36 = V_37 ;
F_15 () ;
F_16 (entry, &lowpan_devices, list)
if ( V_1 ( V_34 -> V_38 ) -> V_32 == V_9 -> V_3 ) {
V_35 = F_17 ( V_9 , V_39 ) ;
if ( ! V_35 ) {
V_36 = - V_40 ;
break;
}
V_35 -> V_3 = V_34 -> V_38 ;
V_36 = F_18 ( V_35 ) ;
}
F_19 () ;
return V_36 ;
}
static int F_20 ( struct V_8 * V_9 , const struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
struct V_45 V_16 , V_17 ;
void * V_46 , * V_47 ;
F_21 ( V_20 , L_3 , V_9 -> V_48 , V_9 -> V_12 ) ;
if ( V_9 -> V_12 < 2 )
goto V_49;
if ( F_22 ( V_9 , & V_43 ) )
goto V_49;
if ( F_22 ( V_9 , & V_44 ) )
goto V_49;
F_23 ( & V_16 , & V_42 -> V_50 ) ;
F_23 ( & V_17 , & V_42 -> V_5 ) ;
if ( V_16 . V_51 == V_28 )
V_46 = & V_16 . V_29 ;
else
V_46 = & V_16 . V_52 ;
if ( V_17 . V_51 == V_28 )
V_47 = & V_17 . V_29 ;
else
V_47 = & V_17 . V_52 ;
return F_24 ( V_9 , V_9 -> V_3 , V_46 , V_16 . V_51 ,
V_7 , V_47 , V_17 . V_51 ,
V_7 , V_43 , V_44 ,
F_14 ) ;
V_49:
F_25 ( V_9 ) ;
return - V_53 ;
}
static int F_26 ( struct V_2 * V_3 , void * V_54 )
{
struct V_55 * V_16 = V_54 ;
if ( F_27 ( V_3 ) )
return - V_56 ;
memcpy ( V_3 -> V_19 , V_16 -> V_57 , V_3 -> V_58 ) ;
return 0 ;
}
static int
F_28 ( struct V_8 * V_9 , T_1 * V_59 ,
int V_60 , int V_61 , int V_62 , int type )
{
struct V_8 * V_63 ;
int V_64 ;
V_64 = ( type == V_65 ) ?
V_66 : V_67 ;
F_4 ( V_20 , L_4 , V_59 , V_64 ) ;
V_63 = F_29 ( V_9 -> V_3 ,
V_64 + V_60 + V_61 + V_68 ) ;
if ( ! V_63 )
return - V_40 ;
V_63 -> V_69 = V_9 -> V_69 ;
F_30 ( V_63 , V_60 ) ;
F_31 ( V_63 , F_32 ( V_9 ) , V_60 ) ;
F_30 ( V_63 , V_64 ) ;
F_33 ( V_63 , V_60 , V_59 , V_64 ) ;
F_30 ( V_63 , V_61 ) ;
F_33 ( V_63 , V_60 + V_64 ,
F_34 ( V_9 ) + V_62 , V_61 ) ;
F_21 ( V_20 , L_5 , V_63 -> V_48 , V_63 -> V_12 ) ;
return F_35 ( V_63 ) ;
}
static int
F_36 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
int V_70 ;
T_2 V_71 , V_72 , V_73 , V_74 ,
V_75 , V_76 , V_62 ;
T_3 V_77 ;
T_1 V_59 [ 5 ] ;
V_74 = V_9 -> V_78 ;
V_73 = V_9 -> V_12 - V_74 ;
V_77 = V_1 ( V_3 ) -> V_79 ++ ;
V_75 = F_37 ( V_9 ) ;
V_72 = F_38 ( V_9 , & V_71 ) -
V_74 ;
V_59 [ 0 ] = V_65 | ( ( V_72 >> 8 ) & 0x7 ) ;
V_59 [ 1 ] = V_72 & 0xff ;
memcpy ( V_59 + 2 , & V_77 , sizeof( V_77 ) ) ;
V_76 = F_39 ( V_80 - V_74 -
V_66 - V_75 -
V_68 , 8 ) ;
V_70 = F_28 ( V_9 , V_59 , V_74 ,
V_76 + V_75 , 0 ,
V_65 ) ;
if ( V_70 ) {
F_40 ( L_6 ,
V_20 , V_77 ) ;
goto exit;
}
V_62 = V_75 + V_76 ;
V_71 += V_76 ;
V_59 [ 0 ] &= ~ V_65 ;
V_59 [ 0 ] |= V_81 ;
V_76 = F_39 ( V_80 - V_74 -
V_67 - V_68 , 8 ) ;
while ( V_73 - V_62 > 0 ) {
int V_12 = V_76 ;
V_59 [ 4 ] = V_71 >> 3 ;
if ( V_73 - V_62 < V_12 )
V_12 = V_73 - V_62 ;
V_70 = F_28 ( V_9 , V_59 , V_74 , V_12 ,
V_62 , V_81 ) ;
if ( V_70 ) {
F_40 ( L_7 ,
V_20 , V_77 , V_62 ) ;
goto exit;
}
V_62 += V_12 ;
V_71 += V_12 ;
}
exit:
return V_70 ;
}
static T_4 F_41 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
int V_70 = - 1 ;
F_40 ( L_8 ) ;
V_9 -> V_3 = V_1 ( V_3 ) -> V_32 ;
if ( V_9 -> V_3 == NULL ) {
F_40 ( L_9 ) ;
goto error;
}
if ( V_9 -> V_12 <= V_80 - V_68 ) {
V_70 = F_35 ( V_9 ) ;
goto V_82;
}
F_40 ( L_10 ) ;
V_70 = F_36 ( V_9 , V_3 ) ;
error:
F_42 ( V_9 ) ;
V_82:
if ( V_70 )
F_40 ( L_11 ) ;
return ( V_70 < 0 ) ? V_83 : V_70 ;
}
static struct V_84 * F_43 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_44 ( V_32 ) ;
}
static T_5 F_45 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_9 ( V_32 ) ;
}
static T_5 F_46 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_47 ( V_32 ) ;
}
static T_1 F_48 ( const struct V_2 * V_3 )
{
struct V_2 * V_32 = V_1 ( V_3 ) -> V_32 ;
return F_7 ( V_32 ) -> F_8 ( V_32 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_85 * V_86 ,
void * V_87 )
{
F_50 ( & V_86 -> V_88 ,
& V_89 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
F_52 ( V_3 , F_49 , NULL ) ;
V_3 -> V_90 = & V_91 ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 )
{
V_3 -> V_58 = V_7 ;
memset ( V_3 -> V_92 , 0xff , V_7 ) ;
V_3 -> type = V_93 ;
V_3 -> V_94 = 2 + 1 + 20 + 14 ;
V_3 -> V_95 = 2 ;
V_3 -> V_96 = 1281 ;
V_3 -> V_97 = 0 ;
V_3 -> V_21 = V_98 | V_99 ;
V_3 -> V_100 = 0 ;
V_3 -> V_101 = & V_102 ;
V_3 -> V_103 = & V_104 ;
V_3 -> V_105 = & V_106 ;
V_3 -> V_107 = V_108 ;
}
static int F_54 ( struct V_109 * V_110 [] , struct V_109 * V_48 [] )
{
if ( V_110 [ V_111 ] ) {
if ( F_55 ( V_110 [ V_111 ] ) != V_7 )
return - V_53 ;
}
return 0 ;
}
static int F_56 ( struct V_8 * V_9 , struct V_2 * V_3 ,
struct V_112 * V_113 , struct V_2 * V_114 )
{
struct V_41 V_42 ;
int V_115 ;
V_9 = F_57 ( V_9 , V_39 ) ;
if ( ! V_9 )
goto V_49;
if ( ! F_27 ( V_3 ) )
goto V_116;
if ( V_3 -> type != V_93 )
goto V_116;
if ( F_58 ( V_9 , & V_42 ) < 0 )
goto V_116;
if ( V_9 -> V_48 [ 0 ] == V_117 ) {
V_9 -> V_118 = F_59 ( V_18 ) ;
V_9 -> V_119 = V_120 ;
F_60 ( V_9 , 1 ) ;
V_115 = F_14 ( V_9 , NULL ) ;
if ( V_115 == V_121 )
goto V_49;
} else {
switch ( V_9 -> V_48 [ 0 ] & 0xe0 ) {
case V_122 :
V_115 = F_20 ( V_9 , & V_42 ) ;
if ( V_115 == V_121 )
goto V_49;
break;
case V_65 :
V_115 = F_61 ( V_9 , V_65 ) ;
if ( V_115 == 1 ) {
V_115 = F_20 ( V_9 , & V_42 ) ;
if ( V_115 == V_121 )
goto V_49;
}
break;
case V_81 :
V_115 = F_61 ( V_9 , V_81 ) ;
if ( V_115 == 1 ) {
V_115 = F_20 ( V_9 , & V_42 ) ;
if ( V_115 == V_121 )
goto V_49;
}
break;
default:
break;
}
}
return V_37 ;
V_116:
F_25 ( V_9 ) ;
V_49:
return V_121 ;
}
static int F_62 ( struct V_123 * V_124 , struct V_2 * V_3 ,
struct V_109 * V_110 [] , struct V_109 * V_48 [] )
{
struct V_2 * V_32 ;
struct V_33 * V_34 ;
F_40 ( L_12 ) ;
if ( ! V_110 [ V_125 ] )
return - V_53 ;
V_32 = F_63 ( V_124 , F_64 ( V_110 [ V_125 ] ) ) ;
if ( ! V_32 )
return - V_126 ;
if ( V_32 -> type != V_93 ) {
F_65 ( V_32 ) ;
return - V_53 ;
}
V_1 ( V_3 ) -> V_32 = V_32 ;
F_66 ( & V_1 ( V_3 ) -> V_127 ) ;
V_34 = F_67 ( sizeof( * V_34 ) , V_128 ) ;
if ( ! V_34 ) {
F_65 ( V_32 ) ;
V_1 ( V_3 ) -> V_32 = NULL ;
return - V_40 ;
}
V_34 -> V_38 = V_3 ;
memcpy ( V_3 -> V_19 , V_32 -> V_19 , V_7 ) ;
F_68 ( & V_1 ( V_3 ) -> V_127 ) ;
F_69 ( & V_34 -> V_129 ) ;
F_70 ( & V_34 -> V_129 , & V_130 ) ;
F_71 ( & V_1 ( V_3 ) -> V_127 ) ;
F_72 ( V_3 ) ;
return 0 ;
}
static void F_73 ( struct V_2 * V_3 , struct V_131 * V_59 )
{
struct V_1 * V_132 = V_1 ( V_3 ) ;
struct V_2 * V_32 = V_132 -> V_32 ;
struct V_33 * V_34 , * V_133 ;
F_74 () ;
F_68 ( & V_1 ( V_3 ) -> V_127 ) ;
F_75 (entry, tmp, &lowpan_devices, list) {
if ( V_34 -> V_38 == V_3 ) {
F_76 ( & V_34 -> V_129 ) ;
F_77 ( V_34 ) ;
}
}
F_71 ( & V_1 ( V_3 ) -> V_127 ) ;
F_78 ( & V_1 ( V_3 ) -> V_127 ) ;
F_79 ( V_3 , V_59 ) ;
F_65 ( V_32 ) ;
}
static inline int T_6 F_80 ( void )
{
return F_81 ( & V_134 ) ;
}
static inline void F_82 ( void )
{
F_83 ( & V_134 ) ;
}
static int F_84 ( struct V_135 * V_136 ,
unsigned long V_137 , void * V_138 )
{
struct V_2 * V_3 = F_85 ( V_138 ) ;
F_86 ( V_139 ) ;
struct V_33 * V_34 , * V_133 ;
if ( V_3 -> type != V_93 )
goto V_82;
if ( V_137 == V_140 ) {
F_75 (entry, tmp, &lowpan_devices, list) {
if ( V_1 ( V_34 -> V_38 ) -> V_32 == V_3 )
F_73 ( V_34 -> V_38 , & V_139 ) ;
}
F_87 ( & V_139 ) ;
}
V_82:
return V_141 ;
}
static int T_6 F_88 ( void )
{
int V_70 = 0 ;
V_70 = F_89 () ;
if ( V_70 < 0 )
goto V_82;
V_70 = F_80 () ;
if ( V_70 < 0 )
goto V_142;
F_90 ( & V_143 ) ;
V_70 = F_91 ( & V_144 ) ;
if ( V_70 < 0 )
goto V_145;
return 0 ;
V_145:
F_92 ( & V_143 ) ;
F_82 () ;
V_142:
F_93 () ;
V_82:
return V_70 ;
}
static void T_7 F_94 ( void )
{
F_82 () ;
F_92 ( & V_143 ) ;
F_93 () ;
F_95 ( & V_144 ) ;
}
