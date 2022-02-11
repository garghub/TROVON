struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = NULL ;
if ( ! F_2 ( & V_3 ) )
V_2 = F_3 ( V_3 . V_4 ,
struct V_1 , V_5 ) ;
return V_2 ;
}
static void F_4 ( char V_6 )
{
V_7 = V_6 ;
if ( V_6 && ! V_8 )
V_8 = F_1 () ;
}
static int F_5 ( struct V_9 T_1 * V_10 )
{
struct V_9 V_11 ;
V_11 . V_12 = V_12 ;
V_11 . V_7 = V_7 ;
return F_6 ( V_10 , & V_11 , sizeof( V_11 ) ) ? - V_13 : 0 ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_16 = F_8 ( V_15 ) -> V_16 ;
if ( ! V_16 )
goto V_17;
F_9 ( V_16 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_11 ( V_15 ) ;
F_12 ( & V_16 -> V_18 ) ;
F_13 ( V_16 ) ;
V_17:
return;
}
static void F_14 ( struct V_14 * V_15 )
{
F_7 ( V_15 ) ;
F_15 ( & V_15 -> V_19 ) ;
F_16 ( V_15 ) ;
}
static void F_17 ( void )
{
V_8 = NULL ;
if ( V_7 )
V_8 = F_1 () ;
}
static struct V_1 * F_18 ( struct V_20 * V_21 ,
T_2 V_22 )
{
struct V_1 * V_23 ;
F_19 (i, &ipx_interfaces, node)
if ( V_23 -> V_24 == V_21 && V_23 -> V_25 == V_22 )
goto V_17;
V_23 = NULL ;
V_17:
return V_23 ;
}
static struct V_1 * F_20 ( struct V_20 * V_21 ,
T_2 V_22 )
{
struct V_1 * V_23 ;
F_10 ( & V_26 ) ;
V_23 = F_18 ( V_21 , V_22 ) ;
if ( V_23 )
F_9 ( V_23 ) ;
F_12 ( & V_26 ) ;
return V_23 ;
}
struct V_1 * F_21 ( T_3 V_27 )
{
struct V_1 * V_23 ;
F_10 ( & V_26 ) ;
if ( V_27 ) {
F_19 (i, &ipx_interfaces, node)
if ( V_23 -> V_28 == V_27 )
goto V_29;
V_23 = NULL ;
goto V_30;
}
V_23 = V_8 ;
if ( V_23 )
V_29:
F_9 ( V_23 ) ;
V_30:
F_12 ( & V_26 ) ;
return V_23 ;
}
static void F_22 ( struct V_1 * V_16 , struct V_14 * V_15 )
{
F_9 ( V_16 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_8 ( V_15 ) -> V_16 = V_16 ;
F_23 ( V_15 , & V_16 -> V_31 ) ;
F_12 ( & V_16 -> V_18 ) ;
F_13 ( V_16 ) ;
}
static struct V_14 * F_24 ( struct V_1 * V_16 ,
T_2 V_32 )
{
struct V_14 * V_33 ;
F_25 (s, &intrfc->if_sklist)
if ( F_8 ( V_33 ) -> V_32 == V_32 )
goto V_34;
V_33 = NULL ;
V_34:
return V_33 ;
}
static struct V_14 * F_26 ( struct V_1 * V_16 ,
T_2 V_32 )
{
struct V_14 * V_33 ;
F_10 ( & V_16 -> V_18 ) ;
V_33 = F_24 ( V_16 , V_32 ) ;
if ( V_33 )
F_27 ( V_33 ) ;
F_12 ( & V_16 -> V_18 ) ;
return V_33 ;
}
static struct V_14 * F_28 ( struct V_1 * V_16 ,
unsigned char * V_35 ,
T_2 V_32 )
{
struct V_14 * V_33 ;
F_9 ( V_16 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_25 (s, &intrfc->if_sklist) {
struct V_36 * V_37 = F_8 ( V_33 ) ;
if ( V_37 -> V_32 == V_32 &&
! memcmp ( V_35 , V_37 -> V_5 , V_38 ) )
goto V_34;
}
V_33 = NULL ;
V_34:
F_12 ( & V_16 -> V_18 ) ;
F_13 ( V_16 ) ;
return V_33 ;
}
static void F_29 ( struct V_1 * V_16 )
{
struct V_14 * V_33 ;
struct V_39 * V_40 ;
F_30 ( V_16 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_31 (s, t, &intrfc->if_sklist) {
struct V_36 * V_37 = F_8 ( V_33 ) ;
V_33 -> V_41 = V_42 ;
V_33 -> V_43 ( V_33 ) ;
V_37 -> V_16 = NULL ;
V_37 -> V_32 = 0 ;
F_32 ( V_33 , V_44 ) ;
F_11 ( V_33 ) ;
}
F_33 ( & V_16 -> V_31 ) ;
F_12 ( & V_16 -> V_18 ) ;
F_34 ( & V_16 -> V_5 ) ;
if ( V_16 == V_8 )
F_17 () ;
if ( V_16 == V_45 )
V_45 = NULL ;
if ( V_16 -> V_24 )
F_35 ( V_16 -> V_24 ) ;
F_36 ( V_16 ) ;
}
void F_37 ( struct V_1 * V_16 )
{
F_10 ( & V_26 ) ;
F_29 ( V_16 ) ;
F_12 ( & V_26 ) ;
}
static T_4 void F_38 ( struct V_1 * V_16 )
{
if ( F_39 ( & V_16 -> V_46 ) )
F_29 ( V_16 ) ;
}
static int F_40 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_50 )
{
struct V_20 * V_21 = F_41 ( V_50 ) ;
struct V_1 * V_23 , * V_51 ;
if ( ! F_42 ( F_43 ( V_21 ) , & V_52 ) )
return V_53 ;
if ( V_49 != V_54 && V_49 != V_55 )
goto V_17;
F_10 ( & V_26 ) ;
F_44 (i, tmp, &ipx_interfaces, node)
if ( V_23 -> V_24 == V_21 ) {
if ( V_49 == V_55 )
F_9 ( V_23 ) ;
else
F_38 ( V_23 ) ;
}
F_12 ( & V_26 ) ;
V_17:
return V_53 ;
}
static T_5 void F_45 ( void )
{
struct V_1 * V_23 , * V_51 ;
F_10 ( & V_26 ) ;
F_44 (i, tmp, &ipx_interfaces, node)
F_38 ( V_23 ) ;
F_12 ( & V_26 ) ;
}
static void F_46 ( struct V_14 * V_14 , struct V_56 * V_57 )
{
if ( F_47 ( V_14 , V_57 ) < 0 )
F_48 ( V_57 ) ;
}
static int F_49 ( struct V_1 * V_16 ,
struct V_56 * V_57 , int V_58 )
{
struct V_59 * V_60 = F_50 ( V_57 ) ;
int V_61 = ! memcmp ( V_60 -> V_62 . V_5 , V_63 ,
V_38 ) ;
struct V_14 * V_33 ;
int V_2 ;
F_10 ( & V_16 -> V_18 ) ;
F_25 (s, &intrfc->if_sklist) {
struct V_36 * V_37 = F_8 ( V_33 ) ;
if ( V_37 -> V_32 == V_60 -> V_62 . V_14 &&
( V_61 || ! memcmp ( V_60 -> V_62 . V_5 ,
V_37 -> V_5 , V_38 ) ) ) {
struct V_56 * V_64 ;
if ( V_58 ) {
V_64 = F_51 ( V_57 , V_65 ) ;
V_2 = - V_66 ;
if ( ! V_64 )
goto V_17;
} else {
V_64 = V_57 ;
V_58 = 1 ;
}
F_46 ( V_33 , V_64 ) ;
if ( V_16 != V_45 )
break;
}
}
if ( ! V_58 )
F_48 ( V_57 ) ;
V_2 = 0 ;
V_17:
F_12 ( & V_16 -> V_18 ) ;
return V_2 ;
}
static struct V_14 * F_52 ( struct V_1 * V_16 ,
struct V_59 * V_60 )
{
struct V_14 * V_15 = NULL ;
int V_67 = 0 ;
T_6 * V_68 = ( T_6 * ) ( V_60 + 1 ) ;
if ( * V_68 == 0x22 && * ( V_68 + 1 ) == 0x22 )
V_67 = ( ( ( int ) * ( V_68 + 5 ) ) << 8 ) | ( int ) * ( V_68 + 3 ) ;
else if ( * V_68 == 0x77 && * ( V_68 + 1 ) == 0x77 )
V_67 = ( ( ( int ) * ( V_68 + 9 ) ) << 8 ) | ( int ) * ( V_68 + 8 ) ;
if ( V_67 ) {
F_10 ( & V_16 -> V_18 ) ;
F_25 (sk, &intrfc->if_sklist)
if ( F_8 ( V_15 ) -> V_69 == V_67 ) {
F_27 ( V_15 ) ;
goto V_34;
}
V_15 = NULL ;
V_34:
F_12 ( & V_16 -> V_18 ) ;
}
return V_15 ;
}
static int F_49 ( struct V_1 * V_16 ,
struct V_56 * V_57 , int V_58 )
{
struct V_59 * V_60 = F_50 ( V_57 ) ;
struct V_14 * V_70 = NULL , * V_71 = NULL ;
struct V_56 * V_64 = NULL , * V_72 = NULL ;
int V_2 ;
if ( V_16 == V_8 && F_53 ( V_60 -> V_62 . V_14 ) == 0x451 )
V_70 = F_52 ( V_16 , V_60 ) ;
if ( ! V_70 )
V_70 = F_26 ( V_16 , V_60 -> V_62 . V_14 ) ;
if ( V_8 && V_16 != V_8 ) {
const int V_73 = F_53 ( V_60 -> V_62 . V_14 ) ;
if ( V_73 == 0x452 || V_73 == 0x453 || V_73 == 0x456 )
V_71 = F_26 ( V_8 ,
V_60 -> V_62 . V_14 ) ;
}
V_2 = 0 ;
if ( ! V_70 && ! V_71 ) {
if ( ! V_58 )
F_48 ( V_57 ) ;
goto V_17;
}
if ( V_58 )
V_64 = F_51 ( V_57 , V_65 ) ;
else
V_64 = V_57 ;
V_2 = - V_66 ;
if ( ! V_64 )
goto V_74;
if ( V_70 && V_71 )
V_72 = F_51 ( V_64 , V_65 ) ;
else
V_72 = V_64 ;
if ( V_70 )
F_46 ( V_70 , V_64 ) ;
if ( ! V_72 )
goto V_74;
if ( V_71 )
F_46 ( V_71 , V_72 ) ;
V_2 = 0 ;
V_74:
if ( V_70 )
F_54 ( V_70 ) ;
if ( V_71 )
F_54 ( V_71 ) ;
V_17:
return V_2 ;
}
static struct V_56 * F_55 ( struct V_1 * V_16 ,
struct V_56 * V_57 )
{
struct V_56 * V_72 ;
int V_75 = ( unsigned char * ) F_50 ( V_57 ) - V_57 -> V_76 ;
int V_77 = V_16 -> V_78 ;
int V_79 ;
if ( V_75 >= V_77 )
return V_57 ;
V_79 = V_57 -> V_79 + V_77 ;
V_72 = F_56 ( V_79 , V_65 ) ;
if ( V_72 ) {
F_57 ( V_72 , V_77 ) ;
F_58 ( V_72 ) ;
F_59 ( V_72 ) ;
F_60 ( V_72 , V_57 -> V_79 ) ;
memcpy ( F_50 ( V_72 ) , F_50 ( V_57 ) , V_57 -> V_79 ) ;
memcpy ( V_72 -> V_80 , V_57 -> V_80 , sizeof( V_57 -> V_80 ) ) ;
}
F_48 ( V_57 ) ;
return V_72 ;
}
int F_61 ( struct V_1 * V_16 , struct V_56 * V_57 , char * V_5 )
{
struct V_59 * V_60 = F_50 ( V_57 ) ;
struct V_20 * V_21 = V_16 -> V_24 ;
struct V_81 * V_82 = V_16 -> V_83 ;
char V_84 [ V_38 ] ;
int V_85 = 1 ;
int V_86 ;
V_60 -> V_87 = F_62 ( V_57 ) -> V_87 ;
V_60 -> V_62 . V_27 = F_62 ( V_57 ) -> V_88 ;
V_60 -> V_89 . V_27 = F_62 ( V_57 ) -> V_90 ;
if ( F_62 ( V_57 ) -> V_91 . V_92 >= 0 ) {
T_3 * V_91 = ( T_3 * ) ( ( ( T_6 * ) V_57 -> V_93 ) +
sizeof( struct V_59 ) +
F_62 ( V_57 ) -> V_91 . V_92 *
sizeof( T_3 ) ) ;
* V_91 = F_62 ( V_57 ) -> V_91 . V_94 ;
F_62 ( V_57 ) -> V_91 . V_92 = - 1 ;
}
if ( ! V_82 || ! V_21 || V_21 -> V_95 & V_96 )
V_85 = 0 ;
if ( V_60 -> V_62 . V_27 == V_16 -> V_28 ) {
if ( V_16 == V_45 ||
! memcmp ( V_16 -> V_97 , V_5 , V_38 ) ) {
F_63 ( V_57 ) ;
return F_49 ( V_16 , V_57 , 0 ) ;
}
if ( ! memcmp ( V_63 , V_5 , V_38 ) ) {
if ( ! V_85 )
F_63 ( V_57 ) ;
F_49 ( V_16 , V_57 , V_85 ) ;
if ( ! V_85 )
goto V_17;
}
}
if ( V_60 -> V_89 . V_27 != V_16 -> V_28 ) {
V_57 = F_64 ( V_57 , V_65 ) ;
if ( ! V_57 )
goto V_17;
if ( ++ V_60 -> V_87 > V_98 )
V_85 = 0 ;
}
if ( ! V_85 ) {
F_48 ( V_57 ) ;
goto V_17;
}
V_86 = V_21 -> V_86 ;
if ( ! memcmp ( V_63 , V_5 , V_38 ) )
memcpy ( V_84 , V_21 -> V_99 , V_86 ) ;
else
memcpy ( V_84 , & ( V_5 [ V_38 - V_86 ] ) , V_86 ) ;
V_57 = F_55 ( V_16 , V_57 ) ;
if ( ! V_57 )
goto V_17;
V_57 -> V_21 = V_21 ;
V_57 -> V_100 = F_65 ( V_101 ) ;
V_82 -> V_102 ( V_82 , V_57 , V_84 ) ;
V_17:
return 0 ;
}
static int F_66 ( struct V_1 * V_16 )
{
return F_67 ( V_16 -> V_28 , V_16 , NULL ) ;
}
static int F_68 ( struct V_1 * V_16 , struct V_56 * V_57 )
{
struct V_59 * V_60 = F_50 ( V_57 ) ;
int V_2 = 0 ;
F_9 ( V_16 ) ;
if ( ! V_16 -> V_28 )
F_69 ( V_16 , V_57 ) ;
F_62 ( V_57 ) -> V_91 . V_92 = - 1 ;
if ( V_60 -> V_103 == V_104 ) {
V_2 = F_70 ( V_16 , V_57 ) ;
if ( V_2 )
goto V_105;
}
if ( ! F_62 ( V_57 ) -> V_88 )
F_62 ( V_57 ) -> V_88 = V_16 -> V_28 ;
if ( ! F_62 ( V_57 ) -> V_90 )
F_62 ( V_57 ) -> V_90 = V_16 -> V_28 ;
if ( V_60 -> V_103 != V_104 &&
V_16 -> V_28 != F_62 ( V_57 ) -> V_88 ) {
if ( V_57 -> V_106 == V_107 ) {
V_57 = F_64 ( V_57 , V_65 ) ;
if ( V_57 )
V_2 = F_71 ( V_57 ) ;
goto V_108;
}
goto V_105;
}
if ( ! memcmp ( V_63 , V_60 -> V_62 . V_5 , V_38 ) ||
! memcmp ( V_16 -> V_97 , V_60 -> V_62 . V_5 , V_38 ) ) {
V_2 = F_49 ( V_16 , V_57 , 0 ) ;
goto V_108;
}
V_105:
F_48 ( V_57 ) ;
V_108:
F_13 ( V_16 ) ;
return V_2 ;
}
static void F_69 ( struct V_1 * V_16 ,
struct V_56 * V_57 )
{
const struct V_109 * V_80 = F_62 ( V_57 ) ;
if ( V_80 -> V_90 == V_80 -> V_88 && V_80 -> V_90 ) {
struct V_1 * V_23 =
F_21 ( V_80 -> V_90 ) ;
if ( ! V_23 ) {
V_16 -> V_28 = V_80 -> V_90 ;
F_66 ( V_16 ) ;
} else {
F_72 ( V_110 L_1
L_2 ,
( unsigned long ) F_73 ( V_80 -> V_90 ) ,
F_74 ( V_23 ) ,
F_75 ( V_23 -> V_25 ) ,
F_74 ( V_16 ) ,
F_75 ( V_16 -> V_25 ) ) ;
F_13 ( V_23 ) ;
}
}
}
static int F_70 ( struct V_1 * V_16 , struct V_56 * V_57 )
{
struct V_59 * V_60 = F_50 ( V_57 ) ;
int V_23 , V_2 = - V_111 ;
struct V_1 * V_112 ;
char * V_113 ;
T_3 * V_114 ;
if ( F_62 ( V_57 ) -> V_87 > V_115 ||
F_53 ( V_60 -> V_116 ) < sizeof( struct V_59 ) +
V_115 * sizeof( V_117 ) )
goto V_17;
V_2 = 0 ;
if ( ! V_118 )
goto V_17;
if ( F_62 ( V_57 ) -> V_87 == V_115 )
goto V_17;
V_113 = ( ( T_6 * ) V_60 ) + sizeof( struct V_59 ) ;
V_114 = ( T_3 * ) V_113 ;
for ( V_23 = 0 ; V_23 < F_62 ( V_57 ) -> V_87 ; V_23 ++ )
if ( * V_114 ++ == V_16 -> V_28 )
goto V_17;
F_62 ( V_57 ) -> V_91 . V_92 = V_23 ;
F_62 ( V_57 ) -> V_91 . V_94 = V_16 -> V_28 ;
F_10 ( & V_26 ) ;
F_19 (ifcs, &ipx_interfaces, node) {
if ( ! V_112 -> V_28 )
continue;
if ( V_112 == V_16 )
continue;
V_114 = ( T_3 * ) V_113 ;
for ( V_23 = 0 ; V_23 < F_62 ( V_57 ) -> V_87 ; V_23 ++ )
if ( V_112 -> V_28 == * V_114 ++ )
break;
if ( V_23 == F_62 ( V_57 ) -> V_87 ) {
struct V_56 * V_33 = F_76 ( V_57 , V_65 ) ;
if ( V_33 ) {
F_62 ( V_33 ) -> V_88 = V_112 -> V_28 ;
F_71 ( V_33 ) ;
}
}
}
F_12 ( & V_26 ) ;
V_17:
return V_2 ;
}
static void F_77 ( struct V_1 * V_16 )
{
F_10 ( & V_26 ) ;
F_78 ( & V_16 -> V_5 , & V_3 ) ;
F_12 ( & V_26 ) ;
if ( V_7 && ! V_8 )
V_8 = V_16 ;
}
static struct V_1 * F_79 ( struct V_20 * V_21 , T_3 V_94 ,
T_2 V_119 ,
struct V_81 * V_120 ,
unsigned char V_121 ,
int V_122 )
{
struct V_1 * V_16 = F_80 ( sizeof( * V_16 ) , V_65 ) ;
if ( V_16 ) {
V_16 -> V_24 = V_21 ;
V_16 -> V_28 = V_94 ;
V_16 -> V_25 = V_119 ;
V_16 -> V_83 = V_120 ;
V_16 -> V_123 = V_121 ;
V_16 -> V_78 = V_122 ;
V_16 -> V_124 = V_125 ;
F_33 ( & V_16 -> V_31 ) ;
F_81 ( & V_16 -> V_46 , 1 ) ;
F_82 ( & V_16 -> V_18 ) ;
}
return V_16 ;
}
static int F_83 ( struct V_126 * V_127 )
{
struct V_1 * V_16 ;
int V_2 = - V_128 ;
if ( V_8 )
goto V_17;
V_2 = - V_129 ;
if ( ! V_127 -> V_130 )
goto V_17;
V_16 = F_21 ( V_127 -> V_130 ) ;
V_2 = - V_131 ;
if ( V_16 ) {
F_13 ( V_16 ) ;
goto V_17;
}
V_16 = F_79 ( NULL , V_127 -> V_130 , 0 , NULL , 1 , 0 ) ;
V_2 = - V_132 ;
if ( ! V_16 )
goto V_17;
memcpy ( ( char * ) & ( V_16 -> V_97 ) , V_127 -> V_35 , V_38 ) ;
V_45 = V_8 = V_16 ;
F_9 ( V_16 ) ;
F_77 ( V_16 ) ;
V_2 = F_66 ( V_16 ) ;
F_13 ( V_16 ) ;
V_17:
return V_2 ;
}
static T_2 F_84 ( unsigned char type )
{
T_2 V_2 = 0 ;
switch ( type ) {
case V_133 : V_2 = F_65 ( V_101 ) ; break;
case V_134 : V_2 = F_65 ( V_135 ) ; break;
case V_136 : V_2 = F_65 ( V_137 ) ; break;
case V_138 : V_2 = F_65 ( V_139 ) ; break;
}
return V_2 ;
}
static int F_85 ( struct V_126 * V_127 )
{
struct V_20 * V_21 ;
T_2 V_119 = 0 ;
struct V_81 * V_22 = NULL ;
struct V_1 * V_16 ;
int V_2 ;
if ( V_127 -> V_140 == V_141 ) {
V_2 = F_83 ( V_127 ) ;
goto V_17;
}
V_2 = - V_128 ;
if ( V_127 -> V_140 == V_142 && V_8 )
goto V_17;
V_16 = F_21 ( V_127 -> V_130 ) ;
V_2 = - V_131 ;
if ( V_127 -> V_130 && V_16 ) {
F_13 ( V_16 ) ;
goto V_17;
}
if ( V_16 )
F_13 ( V_16 ) ;
V_21 = F_86 ( & V_52 , V_127 -> V_143 ) ;
V_2 = - V_144 ;
if ( ! V_21 )
goto V_17;
switch ( V_127 -> V_145 ) {
case V_134 :
V_119 = F_65 ( V_135 ) ;
V_22 = V_146 ;
break;
case V_133 :
if ( V_21 -> type != V_147 ) {
V_119 = F_65 ( V_101 ) ;
V_22 = V_148 ;
break;
}
case V_136 :
V_119 = F_65 ( V_137 ) ;
V_22 = V_149 ;
break;
case V_138 :
V_119 = F_65 ( V_139 ) ;
V_22 = V_150 ;
break;
case V_151 :
default:
V_2 = - V_152 ;
goto V_153;
}
V_2 = - V_154 ;
if ( ! ( V_21 -> V_95 & V_155 ) )
goto V_153;
V_2 = - V_111 ;
if ( V_21 -> V_86 > V_38 )
goto V_153;
V_16 = F_20 ( V_21 , V_119 ) ;
if ( ! V_16 ) {
V_16 = F_79 ( V_21 , V_127 -> V_130 , V_119 ,
V_22 , 0 , V_21 -> V_156 +
V_22 -> V_157 ) ;
V_2 = - V_132 ;
if ( ! V_16 )
goto V_153;
if ( V_127 -> V_140 == V_142 )
V_8 = V_16 ;
if ( ! memcmp ( V_127 -> V_35 , L_3 ,
V_38 ) ) {
memset ( V_16 -> V_97 , 0 , V_38 ) ;
memcpy ( V_16 -> V_97 + V_38 - V_21 -> V_86 ,
V_21 -> V_158 , V_21 -> V_86 ) ;
} else
memcpy ( V_16 -> V_97 , V_127 -> V_35 , V_38 ) ;
F_9 ( V_16 ) ;
F_77 ( V_16 ) ;
}
V_2 = 0 ;
if ( ! V_16 -> V_28 )
goto V_108;
V_2 = F_66 ( V_16 ) ;
V_108:
F_13 ( V_16 ) ;
goto V_17;
V_153:
F_35 ( V_21 ) ;
V_17:
return V_2 ;
}
static int F_87 ( struct V_126 * V_127 )
{
struct V_20 * V_21 = NULL ;
T_2 V_119 = 0 ;
struct V_1 * V_16 ;
int V_2 = 0 ;
F_10 ( & V_26 ) ;
if ( V_127 -> V_140 == V_141 ) {
if ( V_45 ) {
F_38 ( V_45 ) ;
goto V_17;
}
V_2 = - V_159 ;
goto V_17;
}
V_119 = F_84 ( V_127 -> V_145 ) ;
V_2 = - V_152 ;
if ( ! V_119 )
goto V_17;
V_21 = F_88 ( & V_52 , V_127 -> V_143 ) ;
V_2 = - V_144 ;
if ( ! V_21 )
goto V_17;
V_16 = F_18 ( V_21 , V_119 ) ;
V_2 = - V_111 ;
if ( ! V_16 )
goto V_17;
F_38 ( V_16 ) ;
V_2 = 0 ;
V_17:
F_12 ( & V_26 ) ;
return V_2 ;
}
static struct V_1 * F_89 ( struct V_20 * V_21 ,
T_2 V_119 )
{
struct V_1 * V_16 = NULL ;
struct V_81 * V_22 ;
if ( ! V_21 )
goto V_17;
if ( V_21 -> V_86 > V_38 )
goto V_17;
switch ( F_53 ( V_119 ) ) {
case V_101 : V_22 = V_148 ; break;
case V_135 : V_22 = V_146 ; break;
case V_137 : V_22 = V_149 ; break;
case V_139 : V_22 = V_150 ; break;
default: goto V_17;
}
V_16 = F_79 ( V_21 , 0 , V_119 , V_22 , 0 ,
V_21 -> V_156 + V_22 -> V_157 ) ;
if ( V_16 ) {
memset ( V_16 -> V_97 , 0 , V_38 ) ;
memcpy ( ( char * ) & ( V_16 -> V_97 [ V_38 - V_21 -> V_86 ] ) ,
V_21 -> V_158 , V_21 -> V_86 ) ;
F_82 ( & V_16 -> V_18 ) ;
F_81 ( & V_16 -> V_46 , 1 ) ;
F_77 ( V_16 ) ;
F_90 ( V_21 ) ;
}
V_17:
return V_16 ;
}
static int F_91 ( unsigned int V_160 , void T_1 * V_10 )
{
int V_2 = - V_111 ;
struct V_161 V_162 ;
int V_6 ;
switch ( V_160 ) {
case V_163 : {
struct V_164 * V_165 ;
struct V_126 V_166 ;
V_2 = - V_13 ;
if ( F_92 ( & V_162 , V_10 , sizeof( V_162 ) ) )
break;
V_165 = (struct V_164 * ) & V_162 . V_167 ;
V_2 = - V_111 ;
if ( V_165 -> V_168 != V_169 )
break;
V_166 . V_130 = V_165 -> V_170 ;
memcpy ( V_166 . V_143 , V_162 . V_171 ,
sizeof( V_166 . V_143 ) ) ;
memcpy ( V_166 . V_35 , V_165 -> V_172 , V_38 ) ;
V_166 . V_145 = V_165 -> V_173 ;
V_166 . V_140 = V_165 -> V_174 ;
if ( V_165 -> V_175 == V_176 )
V_2 = F_87 ( & V_166 ) ;
else
V_2 = F_85 ( & V_166 ) ;
break;
}
case V_177 : {
struct V_164 * V_165 ;
struct V_1 * V_178 ;
struct V_20 * V_21 ;
V_2 = - V_13 ;
if ( F_92 ( & V_162 , V_10 , sizeof( V_162 ) ) )
break;
V_165 = (struct V_164 * ) & V_162 . V_167 ;
V_21 = F_88 ( & V_52 , V_162 . V_171 ) ;
V_2 = - V_144 ;
if ( ! V_21 )
break;
V_178 = F_20 ( V_21 ,
F_84 ( V_165 -> V_173 ) ) ;
V_2 = - V_129 ;
if ( ! V_178 )
break;
V_165 -> V_168 = V_169 ;
V_165 -> V_170 = V_178 -> V_28 ;
memcpy ( V_165 -> V_172 , V_178 -> V_97 ,
sizeof( V_165 -> V_172 ) ) ;
V_2 = - V_13 ;
if ( F_6 ( V_10 , & V_162 , sizeof( V_162 ) ) )
break;
F_13 ( V_178 ) ;
V_2 = 0 ;
break;
}
case V_179 :
V_2 = - V_13 ;
if ( F_93 ( V_6 , ( unsigned char T_1 * ) V_10 ) )
break;
V_2 = 0 ;
V_12 = V_6 ;
break;
case V_180 :
V_2 = - V_13 ;
if ( F_93 ( V_6 , ( unsigned char T_1 * ) V_10 ) )
break;
V_2 = 0 ;
F_4 ( V_6 ) ;
break;
}
return V_2 ;
}
T_2 F_94 ( struct V_59 * V_181 , int V_182 )
{
T_7 * V_183 = ( T_7 * ) V_181 ;
T_8 V_184 = V_183 [ 1 ] + ( V_183 [ 2 ] & ( V_185 V_186 ) F_65 ( 0x00ff ) ) ;
T_8 V_23 = ( V_182 >> 1 ) - 3 ;
V_183 += 3 ;
while ( V_23 -- )
V_184 += * V_183 ++ ;
if ( V_181 -> V_116 & F_65 ( 1 ) )
V_184 += ( V_185 V_186 ) F_65 ( 0xff00 ) & * V_183 ;
V_184 = ( V_184 & 0xffff ) + ( V_184 >> 16 ) ;
if ( V_184 >= 0x10000 )
V_184 ++ ;
if ( V_184 )
V_184 = ~ V_184 ;
return ( V_185 T_2 ) V_184 ;
}
const char * F_75 ( T_2 V_187 )
{
char * V_2 = L_4 ;
switch ( F_53 ( V_187 ) ) {
case V_101 : V_2 = L_5 ; break;
case V_135 : V_2 = L_6 ; break;
case V_137 : V_2 = L_7 ; break;
case V_139 : V_2 = L_8 ; break;
}
return V_2 ;
}
const char * F_74 ( struct V_1 * V_16 )
{
return V_16 -> V_123 ? L_9 :
V_16 -> V_24 ? V_16 -> V_24 -> V_188 : L_10 ;
}
static int F_95 ( struct V_189 * V_14 , int V_190 , int V_191 ,
char T_1 * V_192 , unsigned int V_193 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
int V_194 ;
int V_2 = - V_111 ;
F_96 ( V_15 ) ;
if ( V_193 != sizeof( int ) )
goto V_17;
V_2 = - V_13 ;
if ( F_93 ( V_194 , ( unsigned int T_1 * ) V_192 ) )
goto V_17;
V_2 = - V_195 ;
if ( ! ( V_190 == V_196 && V_191 == V_197 ) )
goto V_17;
F_8 ( V_15 ) -> type = V_194 ;
V_2 = 0 ;
V_17:
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_98 ( struct V_189 * V_14 , int V_190 , int V_191 ,
char T_1 * V_192 , int T_1 * V_193 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
int V_6 = 0 ;
int V_79 ;
int V_2 = - V_195 ;
F_96 ( V_15 ) ;
if ( ! ( V_190 == V_196 && V_191 == V_197 ) )
goto V_17;
V_6 = F_8 ( V_15 ) -> type ;
V_2 = - V_13 ;
if ( F_93 ( V_79 , V_193 ) )
goto V_17;
V_79 = F_99 (unsigned int, len, sizeof(int)) ;
V_2 = - V_111 ;
if( V_79 < 0 )
goto V_17;
V_2 = - V_13 ;
if ( F_100 ( V_79 , V_193 ) || F_6 ( V_192 , & V_6 , V_79 ) )
goto V_17;
V_2 = 0 ;
V_17:
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_101 ( struct V_27 * V_27 , struct V_189 * V_14 , int V_100 ,
int V_198 )
{
int V_2 = - V_199 ;
struct V_14 * V_15 ;
if ( ! F_42 ( V_27 , & V_52 ) )
return - V_200 ;
if ( V_14 -> type != V_201 )
goto V_17;
V_2 = - V_66 ;
V_15 = F_102 ( V_27 , V_202 , V_203 , & V_204 ) ;
if ( ! V_15 )
goto V_17;
F_103 ( V_15 ) ;
F_104 ( V_14 , V_15 ) ;
V_15 -> V_205 = 1 ;
V_14 -> V_206 = & V_207 ;
V_2 = 0 ;
V_17:
return V_2 ;
}
static int F_105 ( struct V_189 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( ! V_15 )
goto V_17;
F_96 ( V_15 ) ;
if ( ! F_106 ( V_15 , V_208 ) )
V_15 -> V_209 ( V_15 ) ;
F_32 ( V_15 , V_208 ) ;
V_14 -> V_15 = NULL ;
F_107 ( V_15 ) ;
F_14 ( V_15 ) ;
F_97 ( V_15 ) ;
F_54 ( V_15 ) ;
V_17:
return 0 ;
}
static T_2 F_108 ( struct V_1 * V_16 )
{
unsigned short V_210 = V_16 -> V_124 ;
F_10 ( & V_16 -> V_18 ) ;
if ( V_210 < V_125 )
V_210 = V_125 ;
while ( F_24 ( V_16 , F_65 ( V_210 ) ) )
if ( V_210 > V_211 )
V_210 = V_125 ;
else
V_210 ++ ;
F_12 ( & V_16 -> V_18 ) ;
V_16 -> V_124 = V_210 ;
return F_65 ( V_210 ) ;
}
static int F_109 ( struct V_189 * V_14 ,
struct V_212 * V_213 , int V_86 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_36 * V_37 = F_8 ( V_15 ) ;
struct V_1 * V_16 ;
struct V_164 * V_214 = (struct V_164 * ) V_213 ;
int V_2 = - V_111 ;
if ( ! F_106 ( V_15 , V_44 ) || V_86 != sizeof( struct V_164 ) )
goto V_17;
V_16 = F_21 ( V_214 -> V_170 ) ;
V_2 = - V_129 ;
if ( ! V_16 )
goto V_17;
if ( ! V_214 -> V_215 ) {
V_214 -> V_215 = F_108 ( V_16 ) ;
V_2 = - V_111 ;
if ( ! V_214 -> V_215 )
goto V_74;
}
V_2 = - V_216 ;
if ( F_53 ( V_214 -> V_215 ) < V_125 &&
! F_110 ( V_217 ) )
goto V_74;
V_37 -> V_32 = V_214 -> V_215 ;
#ifdef F_111
if ( V_16 == V_45 ) {
V_2 = - V_111 ;
if ( ! memcmp ( V_214 -> V_172 , V_63 , V_38 ) )
goto V_74;
if ( ! memcmp ( V_214 -> V_172 , V_218 , V_38 ) )
memcpy ( V_37 -> V_5 , V_16 -> V_97 , V_38 ) ;
else
memcpy ( V_37 -> V_5 , V_214 -> V_172 , V_38 ) ;
V_2 = - V_131 ;
if ( F_28 ( V_16 , V_37 -> V_5 ,
V_37 -> V_32 ) ) {
F_112 ( V_15 ,
L_11 ,
F_53 ( V_214 -> V_215 ) ) ;
goto V_74;
}
} else {
memcpy ( V_37 -> V_5 , V_16 -> V_97 , V_38 ) ;
V_2 = - V_131 ;
if ( F_26 ( V_16 , V_214 -> V_215 ) ) {
F_112 ( V_15 ,
L_11 ,
F_53 ( V_214 -> V_215 ) ) ;
goto V_74;
}
}
#else
V_2 = - V_131 ;
if ( F_26 ( V_16 , V_214 -> V_215 ) ) {
F_112 ( V_15 , L_11 ,
F_53 ( ( int ) V_214 -> V_215 ) ) ;
goto V_74;
}
#endif
F_22 ( V_16 , V_15 ) ;
F_113 ( V_15 , V_44 ) ;
V_2 = 0 ;
V_74:
F_13 ( V_16 ) ;
V_17:
return V_2 ;
}
static int F_114 ( struct V_189 * V_14 , struct V_212 * V_213 , int V_86 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
int V_2 ;
F_96 ( V_15 ) ;
V_2 = F_109 ( V_14 , V_213 , V_86 ) ;
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_115 ( struct V_189 * V_14 , struct V_212 * V_213 ,
int V_86 , int V_95 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_36 * V_37 = F_8 ( V_15 ) ;
struct V_164 * V_214 ;
int V_2 = - V_111 ;
struct V_219 * V_220 ;
V_15 -> V_221 = V_222 ;
V_14 -> V_223 = V_224 ;
F_96 ( V_15 ) ;
if ( V_86 != sizeof( * V_214 ) )
goto V_17;
V_214 = (struct V_164 * ) V_213 ;
if ( ! V_37 -> V_32 ) {
struct V_164 V_213 ;
V_213 . V_215 = 0 ;
V_213 . V_170 = 0 ;
#ifdef F_111
V_2 = - V_154 ;
if ( ! V_37 -> V_16 )
goto V_17;
memcpy ( V_213 . V_172 , V_37 -> V_16 -> V_97 ,
V_38 ) ;
#endif
V_2 = F_109 ( V_14 , (struct V_212 * ) & V_213 ,
sizeof( struct V_164 ) ) ;
if ( V_2 )
goto V_17;
}
V_220 = F_116 ( V_214 -> V_170 ) ;
V_2 = - V_225 ;
if ( ! V_220 && ! ( ! V_214 -> V_170 && V_8 ) )
goto V_17;
V_37 -> V_226 . V_27 = V_214 -> V_170 ;
V_37 -> V_226 . V_14 = V_214 -> V_215 ;
memcpy ( V_37 -> V_226 . V_5 , V_214 -> V_172 , V_38 ) ;
V_37 -> type = V_214 -> V_173 ;
if ( V_14 -> type == V_201 ) {
V_14 -> V_223 = V_227 ;
V_15 -> V_221 = V_228 ;
}
if ( V_220 )
F_117 ( V_220 ) ;
V_2 = 0 ;
V_17:
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_118 ( struct V_189 * V_14 , struct V_212 * V_213 ,
int * V_229 , int V_230 )
{
struct V_231 * V_214 ;
struct V_164 V_165 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_36 * V_37 = F_8 ( V_15 ) ;
int V_2 ;
* V_229 = sizeof( struct V_164 ) ;
F_96 ( V_15 ) ;
if ( V_230 ) {
V_2 = - V_232 ;
if ( V_15 -> V_221 != V_228 )
goto V_17;
V_214 = & V_37 -> V_226 ;
V_165 . V_170 = V_214 -> V_27 ;
V_165 . V_215 = V_214 -> V_14 ;
memcpy ( V_165 . V_172 , V_214 -> V_5 , V_38 ) ;
} else {
if ( V_37 -> V_16 ) {
V_165 . V_170 = V_37 -> V_16 -> V_28 ;
#ifdef F_111
memcpy ( V_165 . V_172 , V_37 -> V_5 , V_38 ) ;
#else
memcpy ( V_165 . V_172 , V_37 -> V_16 -> V_97 ,
V_38 ) ;
#endif
} else {
V_165 . V_170 = 0 ;
memset ( V_165 . V_172 , '\0' , V_38 ) ;
}
V_165 . V_215 = V_37 -> V_32 ;
}
V_165 . V_168 = V_169 ;
V_165 . V_173 = V_37 -> type ;
V_165 . V_233 = 0 ;
memcpy ( V_213 , & V_165 , sizeof( V_165 ) ) ;
V_2 = 0 ;
V_17:
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_119 ( struct V_56 * V_57 , struct V_20 * V_21 , struct V_234 * V_235 , struct V_20 * V_236 )
{
struct V_1 * V_16 ;
struct V_59 * V_60 ;
V_186 V_116 ;
int V_2 = 0 ;
if ( ! F_42 ( F_43 ( V_21 ) , & V_52 ) )
goto V_237;
if ( V_57 -> V_106 == V_238 )
goto V_237;
if ( ( V_57 = F_120 ( V_57 , V_65 ) ) == NULL )
goto V_17;
if ( ! F_121 ( V_57 , sizeof( struct V_59 ) ) )
goto V_237;
V_116 = F_53 ( F_50 ( V_57 ) -> V_116 ) ;
if ( V_116 < sizeof( struct V_59 ) ||
! F_121 ( V_57 , V_116 ) )
goto V_237;
V_60 = F_50 ( V_57 ) ;
if ( V_60 -> V_239 != V_240 &&
V_60 -> V_239 != F_94 ( V_60 , V_116 ) )
goto V_237;
F_62 ( V_57 ) -> V_87 = V_60 -> V_87 ;
F_62 ( V_57 ) -> V_88 = V_60 -> V_62 . V_27 ;
F_62 ( V_57 ) -> V_90 = V_60 -> V_89 . V_27 ;
V_16 = F_20 ( V_21 , V_235 -> type ) ;
if ( ! V_16 ) {
if ( V_12 &&
F_62 ( V_57 ) -> V_88 ) {
V_16 = F_89 ( V_21 , V_235 -> type ) ;
if ( V_16 )
F_9 ( V_16 ) ;
}
if ( ! V_16 )
goto V_237;
}
V_2 = F_68 ( V_16 , V_57 ) ;
F_13 ( V_16 ) ;
goto V_17;
V_237:
F_48 ( V_57 ) ;
V_17:
return V_2 ;
}
static int F_122 ( struct V_241 * V_242 , struct V_189 * V_14 ,
struct V_243 * V_244 , T_9 V_79 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_36 * V_37 = F_8 ( V_15 ) ;
struct V_164 * V_245 = (struct V_164 * ) V_244 -> V_246 ;
struct V_164 V_247 ;
int V_2 = - V_111 ;
int V_95 = V_244 -> V_248 ;
F_96 ( V_15 ) ;
if ( V_95 & ~ ( V_249 | V_250 ) )
goto V_17;
if ( V_79 >= 65535 - sizeof( struct V_59 ) )
goto V_17;
if ( V_245 ) {
if ( ! V_37 -> V_32 ) {
struct V_164 V_213 ;
V_213 . V_215 = 0 ;
V_213 . V_170 = 0 ;
#ifdef F_111
V_2 = - V_154 ;
if ( ! V_37 -> V_16 )
goto V_17;
memcpy ( V_213 . V_172 , V_37 -> V_16 -> V_97 ,
V_38 ) ;
#endif
V_2 = F_109 ( V_14 , (struct V_212 * ) & V_213 ,
sizeof( struct V_164 ) ) ;
if ( V_2 )
goto V_17;
}
V_2 = - V_111 ;
if ( V_244 -> V_251 < sizeof( * V_245 ) ||
V_245 -> V_168 != V_169 )
goto V_17;
} else {
V_2 = - V_232 ;
if ( V_15 -> V_221 != V_228 )
goto V_17;
V_245 = & V_247 ;
V_245 -> V_168 = V_169 ;
V_245 -> V_173 = V_37 -> type ;
V_245 -> V_215 = V_37 -> V_226 . V_14 ;
V_245 -> V_170 = V_37 -> V_226 . V_27 ;
memcpy ( V_245 -> V_172 , V_37 -> V_226 . V_5 , V_38 ) ;
}
V_2 = F_123 ( V_15 , V_245 , V_244 -> V_252 , V_79 ,
V_95 & V_249 ) ;
if ( V_2 >= 0 )
V_2 = V_79 ;
V_17:
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_124 ( struct V_241 * V_242 , struct V_189 * V_14 ,
struct V_243 * V_244 , T_9 V_253 , int V_95 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_36 * V_37 = F_8 ( V_15 ) ;
struct V_164 * V_165 = (struct V_164 * ) V_244 -> V_246 ;
struct V_59 * V_60 = NULL ;
struct V_56 * V_57 ;
int V_254 , V_2 ;
F_96 ( V_15 ) ;
if ( ! V_37 -> V_32 ) {
struct V_164 V_213 ;
V_213 . V_215 = 0 ;
V_213 . V_170 = 0 ;
#ifdef F_111
V_2 = - V_154 ;
if ( ! V_37 -> V_16 )
goto V_17;
memcpy ( V_213 . V_172 , V_37 -> V_16 -> V_97 , V_38 ) ;
#endif
V_2 = F_109 ( V_14 , (struct V_212 * ) & V_213 ,
sizeof( struct V_164 ) ) ;
if ( V_2 )
goto V_17;
}
V_2 = - V_232 ;
if ( F_106 ( V_15 , V_44 ) )
goto V_17;
V_57 = F_125 ( V_15 , V_95 & ~ V_249 ,
V_95 & V_249 , & V_2 ) ;
if ( ! V_57 )
goto V_17;
V_60 = F_50 ( V_57 ) ;
V_254 = F_53 ( V_60 -> V_116 ) - sizeof( struct V_59 ) ;
if ( V_254 > V_253 ) {
V_254 = V_253 ;
V_244 -> V_248 |= V_255 ;
}
V_2 = F_126 ( V_57 , sizeof( struct V_59 ) , V_244 -> V_252 ,
V_254 ) ;
if ( V_2 )
goto V_256;
if ( V_57 -> V_257 . V_258 )
V_15 -> V_259 = V_57 -> V_257 ;
if ( V_165 ) {
V_165 -> V_168 = V_169 ;
V_165 -> V_215 = V_60 -> V_89 . V_14 ;
memcpy ( V_165 -> V_172 , V_60 -> V_89 . V_5 , V_38 ) ;
V_165 -> V_170 = F_62 ( V_57 ) -> V_90 ;
V_165 -> V_173 = V_60 -> V_103 ;
V_165 -> V_233 = 0 ;
V_244 -> V_251 = sizeof( * V_165 ) ;
}
V_2 = V_254 ;
V_256:
F_127 ( V_15 , V_57 ) ;
V_17:
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_128 ( struct V_189 * V_14 , unsigned int V_160 , unsigned long V_10 )
{
int V_2 = 0 ;
long V_260 = 0 ;
struct V_14 * V_15 = V_14 -> V_15 ;
void T_1 * V_261 = ( void T_1 * ) V_10 ;
F_96 ( V_15 ) ;
switch ( V_160 ) {
case V_262 :
V_260 = V_15 -> V_263 - F_129 ( V_15 ) ;
if ( V_260 < 0 )
V_260 = 0 ;
V_2 = F_100 ( V_260 , ( int T_1 * ) V_261 ) ;
break;
case V_264 : {
struct V_56 * V_57 = F_130 ( & V_15 -> V_19 ) ;
if ( V_57 )
V_260 = V_57 -> V_79 - sizeof( struct V_59 ) ;
V_2 = F_100 ( V_260 , ( int T_1 * ) V_261 ) ;
break;
}
case V_265 :
case V_266 :
V_2 = - V_267 ;
if ( F_110 ( V_217 ) )
V_2 = F_131 ( V_160 , V_261 ) ;
break;
case V_163 :
case V_179 :
case V_180 :
V_2 = - V_267 ;
if ( ! F_110 ( V_217 ) )
break;
case V_177 :
V_2 = F_91 ( V_160 , V_261 ) ;
break;
case V_268 :
V_2 = F_5 ( V_261 ) ;
break;
case V_269 :
V_2 = - V_267 ;
if ( ! F_110 ( V_217 ) )
break;
V_2 = F_93 ( F_8 ( V_15 ) -> V_69 ,
( const unsigned short T_1 * ) V_261 ) ;
break;
case V_270 :
V_2 = F_132 ( V_15 , V_261 ) ;
break;
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
V_2 = - V_111 ;
break;
default:
V_2 = - V_277 ;
break;
}
F_97 ( V_15 ) ;
return V_2 ;
}
static int F_133 ( struct V_189 * V_14 , unsigned int V_160 , unsigned long V_10 )
{
switch ( V_160 ) {
case V_179 :
case V_180 :
case V_268 :
case V_269 :
return F_128 ( V_14 , V_160 , V_10 ) ;
default:
return - V_277 ;
}
}
static int T_10 F_134 ( void )
{
int V_2 = F_135 ( & V_204 , 1 ) ;
if ( V_2 != 0 )
goto V_17;
F_136 ( & V_278 ) ;
V_148 = F_137 () ;
if ( V_148 )
F_138 ( & V_279 ) ;
else
F_72 ( V_280 ) ;
V_150 = F_139 () ;
if ( V_150 )
F_138 ( & V_281 ) ;
else
F_72 ( V_282 ) ;
V_146 = F_140 ( V_283 , F_119 ) ;
if ( ! V_146 )
F_72 ( V_284 ) ;
V_149 = F_141 ( V_285 , F_119 ) ;
if ( ! V_149 )
F_72 ( V_286 ) ;
F_142 ( & V_287 ) ;
F_143 () ;
F_144 () ;
V_17:
return V_2 ;
}
static void T_5 F_145 ( void )
{
F_146 () ;
F_147 () ;
F_148 ( & V_287 ) ;
F_45 () ;
if ( V_149 ) {
F_149 ( V_149 ) ;
V_149 = NULL ;
}
if ( V_146 ) {
F_150 ( V_146 ) ;
V_146 = NULL ;
}
F_151 ( & V_281 ) ;
if ( V_150 ) {
F_152 ( V_150 ) ;
V_150 = NULL ;
}
F_151 ( & V_279 ) ;
if ( V_148 ) {
F_153 ( V_148 ) ;
V_148 = NULL ;
}
F_154 ( & V_204 ) ;
F_155 ( V_278 . V_288 ) ;
}
