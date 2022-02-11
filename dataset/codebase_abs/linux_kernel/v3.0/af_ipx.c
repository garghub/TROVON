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
struct V_34 * V_5 ;
F_25 (s, node, &intrfc->if_sklist)
if ( F_8 ( V_33 ) -> V_32 == V_32 )
goto V_35;
V_33 = NULL ;
V_35:
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
unsigned char * V_36 ,
T_2 V_32 )
{
struct V_14 * V_33 ;
struct V_34 * V_5 ;
F_9 ( V_16 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_25 (s, node, &intrfc->if_sklist) {
struct V_37 * V_38 = F_8 ( V_33 ) ;
if ( V_38 -> V_32 == V_32 &&
! memcmp ( V_36 , V_38 -> V_5 , V_39 ) )
goto V_35;
}
V_33 = NULL ;
V_35:
F_12 ( & V_16 -> V_18 ) ;
F_13 ( V_16 ) ;
return V_33 ;
}
static void F_29 ( struct V_1 * V_16 )
{
struct V_14 * V_33 ;
struct V_34 * V_5 , * V_40 ;
F_30 ( V_16 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_31 (s, node, t, &intrfc->if_sklist) {
struct V_37 * V_38 = F_8 ( V_33 ) ;
V_33 -> V_41 = V_42 ;
V_33 -> V_43 ( V_33 ) ;
V_38 -> V_16 = NULL ;
V_38 -> V_32 = 0 ;
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
struct V_20 * V_21 = V_50 ;
struct V_1 * V_23 , * V_51 ;
if ( ! F_41 ( F_42 ( V_21 ) , & V_52 ) )
return V_53 ;
if ( V_49 != V_54 && V_49 != V_55 )
goto V_17;
F_10 ( & V_26 ) ;
F_43 (i, tmp, &ipx_interfaces, node)
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
static T_5 void F_44 ( void )
{
struct V_1 * V_23 , * V_51 ;
F_10 ( & V_26 ) ;
F_43 (i, tmp, &ipx_interfaces, node)
F_38 ( V_23 ) ;
F_12 ( & V_26 ) ;
}
static void F_45 ( struct V_14 * V_14 , struct V_56 * V_57 )
{
if ( F_46 ( V_14 , V_57 ) < 0 )
F_47 ( V_57 ) ;
}
static int F_48 ( struct V_1 * V_16 ,
struct V_56 * V_57 , int V_58 )
{
struct V_59 * V_60 = F_49 ( V_57 ) ;
int V_61 = ! memcmp ( V_60 -> V_62 . V_5 , V_63 ,
V_39 ) ;
struct V_14 * V_33 ;
struct V_34 * V_5 ;
int V_2 ;
F_10 ( & V_16 -> V_18 ) ;
F_25 (s, node, &intrfc->if_sklist) {
struct V_37 * V_38 = F_8 ( V_33 ) ;
if ( V_38 -> V_32 == V_60 -> V_62 . V_14 &&
( V_61 || ! memcmp ( V_60 -> V_62 . V_5 ,
V_38 -> V_5 , V_39 ) ) ) {
struct V_56 * V_64 ;
if ( V_58 ) {
V_64 = F_50 ( V_57 , V_65 ) ;
V_2 = - V_66 ;
if ( ! V_64 )
goto V_17;
} else {
V_64 = V_57 ;
V_58 = 1 ;
}
F_45 ( V_33 , V_64 ) ;
if ( V_16 != V_45 )
break;
}
}
if ( ! V_58 )
F_47 ( V_57 ) ;
V_2 = 0 ;
V_17:
F_12 ( & V_16 -> V_18 ) ;
return V_2 ;
}
static struct V_14 * F_51 ( struct V_1 * V_16 ,
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
struct V_34 * V_5 ;
F_10 ( & V_16 -> V_18 ) ;
F_25 (sk, node, &intrfc->if_sklist)
if ( F_8 ( V_15 ) -> V_69 == V_67 ) {
F_27 ( V_15 ) ;
goto V_35;
}
V_15 = NULL ;
V_35:
F_12 ( & V_16 -> V_18 ) ;
}
return V_15 ;
}
static int F_48 ( struct V_1 * V_16 ,
struct V_56 * V_57 , int V_58 )
{
struct V_59 * V_60 = F_49 ( V_57 ) ;
struct V_14 * V_70 = NULL , * V_71 = NULL ;
struct V_56 * V_64 = NULL , * V_72 = NULL ;
int V_2 ;
if ( V_16 == V_8 && F_52 ( V_60 -> V_62 . V_14 ) == 0x451 )
V_70 = F_51 ( V_16 , V_60 ) ;
if ( ! V_70 )
V_70 = F_26 ( V_16 , V_60 -> V_62 . V_14 ) ;
if ( V_8 && V_16 != V_8 ) {
const int V_73 = F_52 ( V_60 -> V_62 . V_14 ) ;
if ( V_73 == 0x452 || V_73 == 0x453 || V_73 == 0x456 )
V_71 = F_26 ( V_8 ,
V_60 -> V_62 . V_14 ) ;
}
V_2 = 0 ;
if ( ! V_70 && ! V_71 ) {
if ( ! V_58 )
F_47 ( V_57 ) ;
goto V_17;
}
if ( V_58 )
V_64 = F_50 ( V_57 , V_65 ) ;
else
V_64 = V_57 ;
V_2 = - V_66 ;
if ( ! V_64 )
goto V_74;
if ( V_70 && V_71 )
V_72 = F_50 ( V_64 , V_65 ) ;
else
V_72 = V_64 ;
if ( V_70 )
F_45 ( V_70 , V_64 ) ;
if ( ! V_72 )
goto V_74;
if ( V_71 )
F_45 ( V_71 , V_72 ) ;
V_2 = 0 ;
V_74:
if ( V_70 )
F_53 ( V_70 ) ;
if ( V_71 )
F_53 ( V_71 ) ;
V_17:
return V_2 ;
}
static struct V_56 * F_54 ( struct V_1 * V_16 ,
struct V_56 * V_57 )
{
struct V_56 * V_72 ;
int V_75 = ( unsigned char * ) F_49 ( V_57 ) - V_57 -> V_76 ;
int V_77 = V_16 -> V_78 ;
int V_79 ;
if ( V_75 >= V_77 )
return V_57 ;
V_79 = V_57 -> V_79 + V_77 ;
V_72 = F_55 ( V_79 , V_65 ) ;
if ( V_72 ) {
F_56 ( V_72 , V_77 ) ;
F_57 ( V_72 ) ;
F_58 ( V_72 ) ;
F_59 ( V_72 , V_57 -> V_79 ) ;
memcpy ( F_49 ( V_72 ) , F_49 ( V_57 ) , V_57 -> V_79 ) ;
memcpy ( V_72 -> V_80 , V_57 -> V_80 , sizeof( V_57 -> V_80 ) ) ;
}
F_47 ( V_57 ) ;
return V_72 ;
}
int F_60 ( struct V_1 * V_16 , struct V_56 * V_57 , char * V_5 )
{
struct V_59 * V_60 = F_49 ( V_57 ) ;
struct V_20 * V_21 = V_16 -> V_24 ;
struct V_81 * V_82 = V_16 -> V_83 ;
char V_84 [ V_39 ] ;
int V_85 = 1 ;
int V_86 ;
V_60 -> V_87 = F_61 ( V_57 ) -> V_87 ;
V_60 -> V_62 . V_27 = F_61 ( V_57 ) -> V_88 ;
V_60 -> V_89 . V_27 = F_61 ( V_57 ) -> V_90 ;
if ( F_61 ( V_57 ) -> V_91 . V_92 >= 0 ) {
T_3 * V_91 = ( T_3 * ) ( ( ( T_6 * ) V_57 -> V_93 ) +
sizeof( struct V_59 ) +
F_61 ( V_57 ) -> V_91 . V_92 *
sizeof( T_3 ) ) ;
* V_91 = F_61 ( V_57 ) -> V_91 . V_94 ;
F_61 ( V_57 ) -> V_91 . V_92 = - 1 ;
}
if ( ! V_82 || ! V_21 || V_21 -> V_95 & V_96 )
V_85 = 0 ;
if ( V_60 -> V_62 . V_27 == V_16 -> V_28 ) {
if ( V_16 == V_45 ||
! memcmp ( V_16 -> V_97 , V_5 , V_39 ) ) {
F_62 ( V_57 ) ;
return F_48 ( V_16 , V_57 , 0 ) ;
}
if ( ! memcmp ( V_63 , V_5 , V_39 ) ) {
if ( ! V_85 )
F_62 ( V_57 ) ;
F_48 ( V_16 , V_57 , V_85 ) ;
if ( ! V_85 )
goto V_17;
}
}
if ( V_60 -> V_89 . V_27 != V_16 -> V_28 ) {
V_57 = F_63 ( V_57 , V_65 ) ;
if ( ! V_57 )
goto V_17;
if ( ++ V_60 -> V_87 > V_98 )
V_85 = 0 ;
}
if ( ! V_85 ) {
F_47 ( V_57 ) ;
goto V_17;
}
V_86 = V_21 -> V_86 ;
if ( ! memcmp ( V_63 , V_5 , V_39 ) )
memcpy ( V_84 , V_21 -> V_99 , V_86 ) ;
else
memcpy ( V_84 , & ( V_5 [ V_39 - V_86 ] ) , V_86 ) ;
V_57 = F_54 ( V_16 , V_57 ) ;
if ( ! V_57 )
goto V_17;
V_57 -> V_21 = V_21 ;
V_57 -> V_100 = F_64 ( V_101 ) ;
V_82 -> V_102 ( V_82 , V_57 , V_84 ) ;
V_17:
return 0 ;
}
static int F_65 ( struct V_1 * V_16 )
{
return F_66 ( V_16 -> V_28 , V_16 , NULL ) ;
}
static int F_67 ( struct V_1 * V_16 , struct V_56 * V_57 )
{
struct V_59 * V_60 = F_49 ( V_57 ) ;
int V_2 = 0 ;
F_9 ( V_16 ) ;
if ( ! V_16 -> V_28 )
F_68 ( V_16 , V_57 ) ;
F_61 ( V_57 ) -> V_91 . V_92 = - 1 ;
if ( V_60 -> V_103 == V_104 ) {
V_2 = F_69 ( V_16 , V_57 ) ;
if ( V_2 )
goto V_105;
}
if ( ! F_61 ( V_57 ) -> V_88 )
F_61 ( V_57 ) -> V_88 = V_16 -> V_28 ;
if ( ! F_61 ( V_57 ) -> V_90 )
F_61 ( V_57 ) -> V_90 = V_16 -> V_28 ;
if ( V_60 -> V_103 != V_104 &&
V_16 -> V_28 != F_61 ( V_57 ) -> V_88 ) {
if ( V_57 -> V_106 == V_107 ) {
V_57 = F_63 ( V_57 , V_65 ) ;
if ( V_57 )
V_2 = F_70 ( V_57 ) ;
goto V_108;
}
goto V_105;
}
if ( ! memcmp ( V_63 , V_60 -> V_62 . V_5 , V_39 ) ||
! memcmp ( V_16 -> V_97 , V_60 -> V_62 . V_5 , V_39 ) ) {
V_2 = F_48 ( V_16 , V_57 , 0 ) ;
goto V_108;
}
V_105:
F_47 ( V_57 ) ;
V_108:
F_13 ( V_16 ) ;
return V_2 ;
}
static void F_68 ( struct V_1 * V_16 ,
struct V_56 * V_57 )
{
const struct V_109 * V_80 = F_61 ( V_57 ) ;
if ( V_80 -> V_90 == V_80 -> V_88 && V_80 -> V_90 ) {
struct V_1 * V_23 =
F_21 ( V_80 -> V_90 ) ;
if ( ! V_23 ) {
V_16 -> V_28 = V_80 -> V_90 ;
F_65 ( V_16 ) ;
} else {
F_71 ( V_110 L_1
L_2 ,
( unsigned long ) F_72 ( V_80 -> V_90 ) ,
F_73 ( V_23 ) ,
F_74 ( V_23 -> V_25 ) ,
F_73 ( V_16 ) ,
F_74 ( V_16 -> V_25 ) ) ;
F_13 ( V_23 ) ;
}
}
}
static int F_69 ( struct V_1 * V_16 , struct V_56 * V_57 )
{
struct V_59 * V_60 = F_49 ( V_57 ) ;
int V_23 , V_2 = - V_111 ;
struct V_1 * V_112 ;
char * V_113 ;
T_3 * V_114 ;
if ( F_61 ( V_57 ) -> V_87 > V_115 ||
F_52 ( V_60 -> V_116 ) < sizeof( struct V_59 ) +
V_115 * sizeof( V_117 ) )
goto V_17;
V_2 = 0 ;
if ( ! V_118 )
goto V_17;
if ( F_61 ( V_57 ) -> V_87 == V_115 )
goto V_17;
V_113 = ( ( T_6 * ) V_60 ) + sizeof( struct V_59 ) ;
V_114 = ( T_3 * ) V_113 ;
for ( V_23 = 0 ; V_23 < F_61 ( V_57 ) -> V_87 ; V_23 ++ )
if ( * V_114 ++ == V_16 -> V_28 )
goto V_17;
F_61 ( V_57 ) -> V_91 . V_92 = V_23 ;
F_61 ( V_57 ) -> V_91 . V_94 = V_16 -> V_28 ;
F_10 ( & V_26 ) ;
F_19 (ifcs, &ipx_interfaces, node) {
if ( ! V_112 -> V_28 )
continue;
if ( V_112 == V_16 )
continue;
V_114 = ( T_3 * ) V_113 ;
for ( V_23 = 0 ; V_23 < F_61 ( V_57 ) -> V_87 ; V_23 ++ )
if ( V_112 -> V_28 == * V_114 ++ )
break;
if ( V_23 == F_61 ( V_57 ) -> V_87 ) {
struct V_56 * V_33 = F_75 ( V_57 , V_65 ) ;
if ( V_33 ) {
F_61 ( V_33 ) -> V_88 = V_112 -> V_28 ;
F_70 ( V_33 ) ;
}
}
}
F_12 ( & V_26 ) ;
V_17:
return V_2 ;
}
static void F_76 ( struct V_1 * V_16 )
{
F_10 ( & V_26 ) ;
F_77 ( & V_16 -> V_5 , & V_3 ) ;
F_12 ( & V_26 ) ;
if ( V_7 && ! V_8 )
V_8 = V_16 ;
}
static struct V_1 * F_78 ( struct V_20 * V_21 , T_3 V_94 ,
T_2 V_119 ,
struct V_81 * V_120 ,
unsigned char V_121 ,
int V_122 )
{
struct V_1 * V_16 = F_79 ( sizeof( * V_16 ) , V_65 ) ;
if ( V_16 ) {
V_16 -> V_24 = V_21 ;
V_16 -> V_28 = V_94 ;
V_16 -> V_25 = V_119 ;
V_16 -> V_83 = V_120 ;
V_16 -> V_123 = V_121 ;
V_16 -> V_78 = V_122 ;
V_16 -> V_124 = V_125 ;
F_33 ( & V_16 -> V_31 ) ;
F_80 ( & V_16 -> V_46 , 1 ) ;
F_81 ( & V_16 -> V_18 ) ;
}
return V_16 ;
}
static int F_82 ( struct V_126 * V_127 )
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
V_16 = F_78 ( NULL , V_127 -> V_130 , 0 , NULL , 1 , 0 ) ;
V_2 = - V_132 ;
if ( ! V_16 )
goto V_17;
memcpy ( ( char * ) & ( V_16 -> V_97 ) , V_127 -> V_36 , V_39 ) ;
V_45 = V_8 = V_16 ;
F_9 ( V_16 ) ;
F_76 ( V_16 ) ;
V_2 = F_65 ( V_16 ) ;
F_13 ( V_16 ) ;
V_17:
return V_2 ;
}
static T_2 F_83 ( unsigned char type )
{
T_2 V_2 = 0 ;
switch ( type ) {
case V_133 : V_2 = F_64 ( V_101 ) ; break;
case V_134 : V_2 = F_64 ( V_135 ) ; break;
case V_136 : V_2 = F_64 ( V_137 ) ; break;
case V_138 : V_2 = F_64 ( V_139 ) ; break;
}
return V_2 ;
}
static int F_84 ( struct V_126 * V_127 )
{
struct V_20 * V_21 ;
T_2 V_119 = 0 ;
struct V_81 * V_22 = NULL ;
struct V_1 * V_16 ;
int V_2 ;
if ( V_127 -> V_140 == V_141 ) {
V_2 = F_82 ( V_127 ) ;
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
V_21 = F_85 ( & V_52 , V_127 -> V_143 ) ;
V_2 = - V_144 ;
if ( ! V_21 )
goto V_17;
switch ( V_127 -> V_145 ) {
case V_146 :
F_71 ( V_110 L_3
L_4 ) ;
case V_134 :
V_119 = F_64 ( V_135 ) ;
V_22 = V_147 ;
break;
case V_133 :
if ( V_21 -> type != V_148 ) {
V_119 = F_64 ( V_101 ) ;
V_22 = V_149 ;
break;
} else
F_71 ( V_110 L_5
L_6
L_7 ) ;
case V_136 :
V_119 = F_64 ( V_137 ) ;
V_22 = V_150 ;
break;
case V_138 :
V_119 = F_64 ( V_139 ) ;
V_22 = V_151 ;
break;
case V_152 :
default:
V_2 = - V_153 ;
goto V_154;
}
V_2 = - V_155 ;
if ( ! ( V_21 -> V_95 & V_156 ) )
goto V_154;
V_2 = - V_111 ;
if ( V_21 -> V_86 > V_39 )
goto V_154;
V_16 = F_20 ( V_21 , V_119 ) ;
if ( ! V_16 ) {
V_16 = F_78 ( V_21 , V_127 -> V_130 , V_119 ,
V_22 , 0 , V_21 -> V_157 +
V_22 -> V_158 ) ;
V_2 = - V_132 ;
if ( ! V_16 )
goto V_154;
if ( V_127 -> V_140 == V_142 )
V_8 = V_16 ;
if ( ! memcmp ( V_127 -> V_36 , L_8 ,
V_39 ) ) {
memset ( V_16 -> V_97 , 0 , V_39 ) ;
memcpy ( V_16 -> V_97 + V_39 - V_21 -> V_86 ,
V_21 -> V_159 , V_21 -> V_86 ) ;
} else
memcpy ( V_16 -> V_97 , V_127 -> V_36 , V_39 ) ;
F_9 ( V_16 ) ;
F_76 ( V_16 ) ;
}
V_2 = 0 ;
if ( ! V_16 -> V_28 )
goto V_108;
V_2 = F_65 ( V_16 ) ;
V_108:
F_13 ( V_16 ) ;
goto V_17;
V_154:
F_35 ( V_21 ) ;
V_17:
return V_2 ;
}
static int F_86 ( struct V_126 * V_127 )
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
V_2 = - V_160 ;
goto V_17;
}
V_119 = F_83 ( V_127 -> V_145 ) ;
V_2 = - V_153 ;
if ( ! V_119 )
goto V_17;
V_21 = F_87 ( & V_52 , V_127 -> V_143 ) ;
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
static struct V_1 * F_88 ( struct V_20 * V_21 ,
T_2 V_119 )
{
struct V_1 * V_16 = NULL ;
struct V_81 * V_22 ;
if ( ! V_21 )
goto V_17;
if ( V_21 -> V_86 > V_39 )
goto V_17;
switch ( F_52 ( V_119 ) ) {
case V_101 : V_22 = V_149 ; break;
case V_135 : V_22 = V_147 ; break;
case V_137 : V_22 = V_150 ; break;
case V_139 : V_22 = V_151 ; break;
default: goto V_17;
}
V_16 = F_78 ( V_21 , 0 , V_119 , V_22 , 0 ,
V_21 -> V_157 + V_22 -> V_158 ) ;
if ( V_16 ) {
memset ( V_16 -> V_97 , 0 , V_39 ) ;
memcpy ( ( char * ) & ( V_16 -> V_97 [ V_39 - V_21 -> V_86 ] ) ,
V_21 -> V_159 , V_21 -> V_86 ) ;
F_81 ( & V_16 -> V_18 ) ;
F_80 ( & V_16 -> V_46 , 1 ) ;
F_76 ( V_16 ) ;
F_89 ( V_21 ) ;
}
V_17:
return V_16 ;
}
static int F_90 ( unsigned int V_161 , void T_1 * V_10 )
{
int V_2 = - V_111 ;
struct V_162 V_163 ;
int V_6 ;
switch ( V_161 ) {
case V_164 : {
struct V_165 * V_166 ;
struct V_126 V_167 ;
V_2 = - V_13 ;
if ( F_91 ( & V_163 , V_10 , sizeof( V_163 ) ) )
break;
V_166 = (struct V_165 * ) & V_163 . V_168 ;
V_2 = - V_111 ;
if ( V_166 -> V_169 != V_170 )
break;
V_167 . V_130 = V_166 -> V_171 ;
memcpy ( V_167 . V_143 , V_163 . V_172 ,
sizeof( V_167 . V_143 ) ) ;
memcpy ( V_167 . V_36 , V_166 -> V_173 , V_39 ) ;
V_167 . V_145 = V_166 -> V_174 ;
V_167 . V_140 = V_166 -> V_175 ;
if ( V_166 -> V_176 == V_177 )
V_2 = F_86 ( & V_167 ) ;
else
V_2 = F_84 ( & V_167 ) ;
break;
}
case V_178 : {
struct V_165 * V_166 ;
struct V_1 * V_179 ;
struct V_20 * V_21 ;
V_2 = - V_13 ;
if ( F_91 ( & V_163 , V_10 , sizeof( V_163 ) ) )
break;
V_166 = (struct V_165 * ) & V_163 . V_168 ;
V_21 = F_87 ( & V_52 , V_163 . V_172 ) ;
V_2 = - V_144 ;
if ( ! V_21 )
break;
V_179 = F_20 ( V_21 ,
F_83 ( V_166 -> V_174 ) ) ;
V_2 = - V_129 ;
if ( ! V_179 )
break;
V_166 -> V_169 = V_170 ;
V_166 -> V_171 = V_179 -> V_28 ;
memcpy ( V_166 -> V_173 , V_179 -> V_97 ,
sizeof( V_166 -> V_173 ) ) ;
V_2 = - V_13 ;
if ( F_6 ( V_10 , & V_163 , sizeof( V_163 ) ) )
break;
F_13 ( V_179 ) ;
V_2 = 0 ;
break;
}
case V_180 :
V_2 = - V_13 ;
if ( F_92 ( V_6 , ( unsigned char T_1 * ) V_10 ) )
break;
V_2 = 0 ;
V_12 = V_6 ;
break;
case V_181 :
V_2 = - V_13 ;
if ( F_92 ( V_6 , ( unsigned char T_1 * ) V_10 ) )
break;
V_2 = 0 ;
F_4 ( V_6 ) ;
break;
}
return V_2 ;
}
T_2 F_93 ( struct V_59 * V_182 , int V_183 )
{
T_7 * V_184 = ( T_7 * ) V_182 ;
T_8 V_185 = V_184 [ 1 ] + ( V_184 [ 2 ] & ( V_186 V_187 ) F_64 ( 0x00ff ) ) ;
T_8 V_23 = ( V_183 >> 1 ) - 3 ;
V_184 += 3 ;
while ( V_23 -- )
V_185 += * V_184 ++ ;
if ( V_182 -> V_116 & F_64 ( 1 ) )
V_185 += ( V_186 V_187 ) F_64 ( 0xff00 ) & * V_184 ;
V_185 = ( V_185 & 0xffff ) + ( V_185 >> 16 ) ;
if ( V_185 >= 0x10000 )
V_185 ++ ;
if ( V_185 )
V_185 = ~ V_185 ;
return ( V_186 T_2 ) V_185 ;
}
const char * F_74 ( T_2 V_188 )
{
char * V_2 = L_9 ;
switch ( F_52 ( V_188 ) ) {
case V_101 : V_2 = L_10 ; break;
case V_135 : V_2 = L_11 ; break;
case V_137 : V_2 = L_12 ; break;
case V_139 : V_2 = L_13 ; break;
case V_189 : V_2 = L_14 ; break;
}
return V_2 ;
}
const char * F_73 ( struct V_1 * V_16 )
{
return V_16 -> V_123 ? L_15 :
V_16 -> V_24 ? V_16 -> V_24 -> V_190 : L_16 ;
}
static int F_94 ( struct V_191 * V_14 , int V_192 , int V_193 ,
char T_1 * V_194 , unsigned int V_195 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
int V_196 ;
int V_2 = - V_111 ;
F_95 ( V_15 ) ;
if ( V_195 != sizeof( int ) )
goto V_17;
V_2 = - V_13 ;
if ( F_92 ( V_196 , ( unsigned int T_1 * ) V_194 ) )
goto V_17;
V_2 = - V_197 ;
if ( ! ( V_192 == V_198 && V_193 == V_199 ) )
goto V_17;
F_8 ( V_15 ) -> type = V_196 ;
V_2 = 0 ;
V_17:
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_97 ( struct V_191 * V_14 , int V_192 , int V_193 ,
char T_1 * V_194 , int T_1 * V_195 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
int V_6 = 0 ;
int V_79 ;
int V_2 = - V_197 ;
F_95 ( V_15 ) ;
if ( ! ( V_192 == V_198 && V_193 == V_199 ) )
goto V_17;
V_6 = F_8 ( V_15 ) -> type ;
V_2 = - V_13 ;
if ( F_92 ( V_79 , V_195 ) )
goto V_17;
V_79 = F_98 (unsigned int, len, sizeof(int)) ;
V_2 = - V_111 ;
if( V_79 < 0 )
goto V_17;
V_2 = - V_13 ;
if ( F_99 ( V_79 , V_195 ) || F_6 ( V_194 , & V_6 , V_79 ) )
goto V_17;
V_2 = 0 ;
V_17:
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_100 ( struct V_27 * V_27 , struct V_191 * V_14 , int V_100 ,
int V_200 )
{
int V_2 = - V_201 ;
struct V_14 * V_15 ;
if ( ! F_41 ( V_27 , & V_52 ) )
return - V_202 ;
if ( V_14 -> type != V_203 )
goto V_17;
V_2 = - V_66 ;
V_15 = F_101 ( V_27 , V_204 , V_205 , & V_206 ) ;
if ( ! V_15 )
goto V_17;
F_102 ( V_15 ) ;
F_103 ( V_14 , V_15 ) ;
V_15 -> V_207 = 1 ;
V_14 -> V_208 = & V_209 ;
V_2 = 0 ;
V_17:
return V_2 ;
}
static int F_104 ( struct V_191 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( ! V_15 )
goto V_17;
F_95 ( V_15 ) ;
if ( ! F_105 ( V_15 , V_210 ) )
V_15 -> V_211 ( V_15 ) ;
F_32 ( V_15 , V_210 ) ;
V_14 -> V_15 = NULL ;
F_106 ( V_15 ) ;
F_14 ( V_15 ) ;
F_96 ( V_15 ) ;
F_53 ( V_15 ) ;
V_17:
return 0 ;
}
static T_2 F_107 ( struct V_1 * V_16 )
{
unsigned short V_212 = V_16 -> V_124 ;
F_10 ( & V_16 -> V_18 ) ;
if ( V_212 < V_125 )
V_212 = V_125 ;
while ( F_24 ( V_16 , F_64 ( V_212 ) ) )
if ( V_212 > V_213 )
V_212 = V_125 ;
else
V_212 ++ ;
F_12 ( & V_16 -> V_18 ) ;
V_16 -> V_124 = V_212 ;
return F_64 ( V_212 ) ;
}
static int F_108 ( struct V_191 * V_14 ,
struct V_214 * V_215 , int V_86 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_8 ( V_15 ) ;
struct V_1 * V_16 ;
struct V_165 * V_216 = (struct V_165 * ) V_215 ;
int V_2 = - V_111 ;
if ( ! F_105 ( V_15 , V_44 ) || V_86 != sizeof( struct V_165 ) )
goto V_17;
V_16 = F_21 ( V_216 -> V_171 ) ;
V_2 = - V_129 ;
if ( ! V_16 )
goto V_17;
if ( ! V_216 -> V_217 ) {
V_216 -> V_217 = F_107 ( V_16 ) ;
V_2 = - V_111 ;
if ( ! V_216 -> V_217 )
goto V_74;
}
V_2 = - V_218 ;
if ( F_52 ( V_216 -> V_217 ) < V_125 &&
! F_109 ( V_219 ) )
goto V_74;
V_38 -> V_32 = V_216 -> V_217 ;
#ifdef F_110
if ( V_16 == V_45 ) {
V_2 = - V_111 ;
if ( ! memcmp ( V_216 -> V_173 , V_63 , V_39 ) )
goto V_74;
if ( ! memcmp ( V_216 -> V_173 , V_220 , V_39 ) )
memcpy ( V_38 -> V_5 , V_16 -> V_97 , V_39 ) ;
else
memcpy ( V_38 -> V_5 , V_216 -> V_173 , V_39 ) ;
V_2 = - V_131 ;
if ( F_28 ( V_16 , V_38 -> V_5 ,
V_38 -> V_32 ) ) {
F_111 ( V_15 ,
L_17 ,
F_52 ( V_216 -> V_217 ) ) ;
goto V_74;
}
} else {
memcpy ( V_38 -> V_5 , V_16 -> V_97 , V_39 ) ;
V_2 = - V_131 ;
if ( F_26 ( V_16 , V_216 -> V_217 ) ) {
F_111 ( V_15 ,
L_17 ,
F_52 ( V_216 -> V_217 ) ) ;
goto V_74;
}
}
#else
V_2 = - V_131 ;
if ( F_26 ( V_16 , V_216 -> V_217 ) ) {
F_111 ( V_15 , L_17 ,
F_52 ( ( int ) V_216 -> V_217 ) ) ;
goto V_74;
}
#endif
F_22 ( V_16 , V_15 ) ;
F_112 ( V_15 , V_44 ) ;
V_2 = 0 ;
V_74:
F_13 ( V_16 ) ;
V_17:
return V_2 ;
}
static int F_113 ( struct V_191 * V_14 , struct V_214 * V_215 , int V_86 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
int V_2 ;
F_95 ( V_15 ) ;
V_2 = F_108 ( V_14 , V_215 , V_86 ) ;
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_114 ( struct V_191 * V_14 , struct V_214 * V_215 ,
int V_86 , int V_95 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_8 ( V_15 ) ;
struct V_165 * V_216 ;
int V_2 = - V_111 ;
struct V_221 * V_222 ;
V_15 -> V_223 = V_224 ;
V_14 -> V_225 = V_226 ;
F_95 ( V_15 ) ;
if ( V_86 != sizeof( * V_216 ) )
goto V_17;
V_216 = (struct V_165 * ) V_215 ;
if ( ! V_38 -> V_32 ) {
struct V_165 V_215 ;
V_215 . V_217 = 0 ;
V_215 . V_171 = 0 ;
#ifdef F_110
V_2 = - V_155 ;
if ( ! V_38 -> V_16 )
goto V_17;
memcpy ( V_215 . V_173 , V_38 -> V_16 -> V_97 ,
V_39 ) ;
#endif
V_2 = F_108 ( V_14 , (struct V_214 * ) & V_215 ,
sizeof( struct V_165 ) ) ;
if ( V_2 )
goto V_17;
}
V_222 = F_115 ( V_216 -> V_171 ) ;
V_2 = - V_227 ;
if ( ! V_222 && ! ( ! V_216 -> V_171 && V_8 ) )
goto V_17;
V_38 -> V_228 . V_27 = V_216 -> V_171 ;
V_38 -> V_228 . V_14 = V_216 -> V_217 ;
memcpy ( V_38 -> V_228 . V_5 , V_216 -> V_173 , V_39 ) ;
V_38 -> type = V_216 -> V_174 ;
if ( V_14 -> type == V_203 ) {
V_14 -> V_225 = V_229 ;
V_15 -> V_223 = V_230 ;
}
if ( V_222 )
F_116 ( V_222 ) ;
V_2 = 0 ;
V_17:
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_117 ( struct V_191 * V_14 , struct V_214 * V_215 ,
int * V_231 , int V_232 )
{
struct V_233 * V_216 ;
struct V_165 V_166 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_8 ( V_15 ) ;
int V_2 ;
* V_231 = sizeof( struct V_165 ) ;
F_95 ( V_15 ) ;
if ( V_232 ) {
V_2 = - V_234 ;
if ( V_15 -> V_223 != V_230 )
goto V_17;
V_216 = & V_38 -> V_228 ;
V_166 . V_171 = V_216 -> V_27 ;
V_166 . V_217 = V_216 -> V_14 ;
memcpy ( V_166 . V_173 , V_216 -> V_5 , V_39 ) ;
} else {
if ( V_38 -> V_16 ) {
V_166 . V_171 = V_38 -> V_16 -> V_28 ;
#ifdef F_110
memcpy ( V_166 . V_173 , V_38 -> V_5 , V_39 ) ;
#else
memcpy ( V_166 . V_173 , V_38 -> V_16 -> V_97 ,
V_39 ) ;
#endif
} else {
V_166 . V_171 = 0 ;
memset ( V_166 . V_173 , '\0' , V_39 ) ;
}
V_166 . V_217 = V_38 -> V_32 ;
}
V_166 . V_169 = V_170 ;
V_166 . V_174 = V_38 -> type ;
V_166 . V_235 = 0 ;
memcpy ( V_215 , & V_166 , sizeof( V_166 ) ) ;
V_2 = 0 ;
V_17:
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_118 ( struct V_56 * V_57 , struct V_20 * V_21 , struct V_236 * V_237 , struct V_20 * V_238 )
{
struct V_1 * V_16 ;
struct V_59 * V_60 ;
V_187 V_116 ;
int V_2 = 0 ;
if ( ! F_41 ( F_42 ( V_21 ) , & V_52 ) )
goto V_239;
if ( V_57 -> V_106 == V_240 )
goto V_239;
if ( ( V_57 = F_119 ( V_57 , V_65 ) ) == NULL )
goto V_17;
if ( ! F_120 ( V_57 , sizeof( struct V_59 ) ) )
goto V_239;
V_116 = F_52 ( F_49 ( V_57 ) -> V_116 ) ;
if ( V_116 < sizeof( struct V_59 ) ||
! F_120 ( V_57 , V_116 ) )
goto V_239;
V_60 = F_49 ( V_57 ) ;
if ( V_60 -> V_241 != V_242 &&
V_60 -> V_241 != F_93 ( V_60 , V_116 ) )
goto V_239;
F_61 ( V_57 ) -> V_87 = V_60 -> V_87 ;
F_61 ( V_57 ) -> V_88 = V_60 -> V_62 . V_27 ;
F_61 ( V_57 ) -> V_90 = V_60 -> V_89 . V_27 ;
V_16 = F_20 ( V_21 , V_237 -> type ) ;
if ( ! V_16 ) {
if ( V_12 &&
F_61 ( V_57 ) -> V_88 ) {
V_16 = F_88 ( V_21 , V_237 -> type ) ;
if ( V_16 )
F_9 ( V_16 ) ;
}
if ( ! V_16 )
goto V_239;
}
V_2 = F_67 ( V_16 , V_57 ) ;
F_13 ( V_16 ) ;
goto V_17;
V_239:
F_47 ( V_57 ) ;
V_17:
return V_2 ;
}
static int F_121 ( struct V_243 * V_244 , struct V_191 * V_14 ,
struct V_245 * V_246 , T_9 V_79 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_8 ( V_15 ) ;
struct V_165 * V_247 = (struct V_165 * ) V_246 -> V_248 ;
struct V_165 V_249 ;
int V_2 = - V_111 ;
int V_95 = V_246 -> V_250 ;
F_95 ( V_15 ) ;
if ( V_95 & ~ ( V_251 | V_252 ) )
goto V_17;
if ( V_79 >= 65535 - sizeof( struct V_59 ) )
goto V_17;
if ( V_247 ) {
if ( ! V_38 -> V_32 ) {
struct V_165 V_215 ;
V_215 . V_217 = 0 ;
V_215 . V_171 = 0 ;
#ifdef F_110
V_2 = - V_155 ;
if ( ! V_38 -> V_16 )
goto V_17;
memcpy ( V_215 . V_173 , V_38 -> V_16 -> V_97 ,
V_39 ) ;
#endif
V_2 = F_108 ( V_14 , (struct V_214 * ) & V_215 ,
sizeof( struct V_165 ) ) ;
if ( V_2 )
goto V_17;
}
V_2 = - V_111 ;
if ( V_246 -> V_253 < sizeof( * V_247 ) ||
V_247 -> V_169 != V_170 )
goto V_17;
} else {
V_2 = - V_234 ;
if ( V_15 -> V_223 != V_230 )
goto V_17;
V_247 = & V_249 ;
V_247 -> V_169 = V_170 ;
V_247 -> V_174 = V_38 -> type ;
V_247 -> V_217 = V_38 -> V_228 . V_14 ;
V_247 -> V_171 = V_38 -> V_228 . V_27 ;
memcpy ( V_247 -> V_173 , V_38 -> V_228 . V_5 , V_39 ) ;
}
V_2 = F_122 ( V_15 , V_247 , V_246 -> V_254 , V_79 ,
V_95 & V_251 ) ;
if ( V_2 >= 0 )
V_2 = V_79 ;
V_17:
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_123 ( struct V_243 * V_244 , struct V_191 * V_14 ,
struct V_245 * V_246 , T_9 V_255 , int V_95 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_8 ( V_15 ) ;
struct V_165 * V_166 = (struct V_165 * ) V_246 -> V_248 ;
struct V_59 * V_60 = NULL ;
struct V_56 * V_57 ;
int V_256 , V_2 ;
F_95 ( V_15 ) ;
if ( ! V_38 -> V_32 ) {
struct V_165 V_215 ;
V_215 . V_217 = 0 ;
V_215 . V_171 = 0 ;
#ifdef F_110
V_2 = - V_155 ;
if ( ! V_38 -> V_16 )
goto V_17;
memcpy ( V_215 . V_173 , V_38 -> V_16 -> V_97 , V_39 ) ;
#endif
V_2 = F_108 ( V_14 , (struct V_214 * ) & V_215 ,
sizeof( struct V_165 ) ) ;
if ( V_2 )
goto V_17;
}
V_2 = - V_234 ;
if ( F_105 ( V_15 , V_44 ) )
goto V_17;
V_57 = F_124 ( V_15 , V_95 & ~ V_251 ,
V_95 & V_251 , & V_2 ) ;
if ( ! V_57 )
goto V_17;
V_60 = F_49 ( V_57 ) ;
V_256 = F_52 ( V_60 -> V_116 ) - sizeof( struct V_59 ) ;
if ( V_256 > V_255 ) {
V_256 = V_255 ;
V_246 -> V_250 |= V_257 ;
}
V_2 = F_125 ( V_57 , sizeof( struct V_59 ) , V_246 -> V_254 ,
V_256 ) ;
if ( V_2 )
goto V_258;
if ( V_57 -> V_259 . V_260 )
V_15 -> V_261 = V_57 -> V_259 ;
V_246 -> V_253 = sizeof( * V_166 ) ;
if ( V_166 ) {
V_166 -> V_169 = V_170 ;
V_166 -> V_217 = V_60 -> V_89 . V_14 ;
memcpy ( V_166 -> V_173 , V_60 -> V_89 . V_5 , V_39 ) ;
V_166 -> V_171 = F_61 ( V_57 ) -> V_90 ;
V_166 -> V_174 = V_60 -> V_103 ;
V_166 -> V_235 = 0 ;
}
V_2 = V_256 ;
V_258:
F_126 ( V_15 , V_57 ) ;
V_17:
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_127 ( struct V_191 * V_14 , unsigned int V_161 , unsigned long V_10 )
{
int V_2 = 0 ;
long V_262 = 0 ;
struct V_14 * V_15 = V_14 -> V_15 ;
void T_1 * V_263 = ( void T_1 * ) V_10 ;
F_95 ( V_15 ) ;
switch ( V_161 ) {
case V_264 :
V_262 = V_15 -> V_265 - F_128 ( V_15 ) ;
if ( V_262 < 0 )
V_262 = 0 ;
V_2 = F_99 ( V_262 , ( int T_1 * ) V_263 ) ;
break;
case V_266 : {
struct V_56 * V_57 = F_129 ( & V_15 -> V_19 ) ;
if ( V_57 )
V_262 = V_57 -> V_79 - sizeof( struct V_59 ) ;
V_2 = F_99 ( V_262 , ( int T_1 * ) V_263 ) ;
break;
}
case V_267 :
case V_268 :
V_2 = - V_269 ;
if ( F_109 ( V_219 ) )
V_2 = F_130 ( V_161 , V_263 ) ;
break;
case V_164 :
case V_180 :
case V_181 :
V_2 = - V_269 ;
if ( ! F_109 ( V_219 ) )
break;
case V_178 :
V_2 = F_90 ( V_161 , V_263 ) ;
break;
case V_270 :
V_2 = F_5 ( V_263 ) ;
break;
case V_271 :
V_2 = - V_269 ;
if ( ! F_109 ( V_219 ) )
break;
V_2 = F_92 ( F_8 ( V_15 ) -> V_69 ,
( const unsigned short T_1 * ) V_263 ) ;
break;
case V_272 :
V_2 = - V_111 ;
if ( V_15 )
V_2 = F_131 ( V_15 , V_263 ) ;
break;
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
V_2 = - V_111 ;
break;
default:
V_2 = - V_279 ;
break;
}
F_96 ( V_15 ) ;
return V_2 ;
}
static int F_132 ( struct V_191 * V_14 , unsigned int V_161 , unsigned long V_10 )
{
switch ( V_161 ) {
case V_180 :
case V_181 :
case V_270 :
case V_271 :
return F_127 ( V_14 , V_161 , V_10 ) ;
default:
return - V_279 ;
}
}
static int T_10 F_133 ( void )
{
int V_2 = F_134 ( & V_206 , 1 ) ;
if ( V_2 != 0 )
goto V_17;
F_135 ( & V_280 ) ;
V_149 = F_136 () ;
if ( V_149 )
F_137 ( & V_281 ) ;
else
F_71 ( V_282 ) ;
V_151 = F_138 () ;
if ( V_151 )
F_137 ( & V_283 ) ;
else
F_71 ( V_284 ) ;
V_147 = F_139 ( V_285 , F_118 ) ;
if ( ! V_147 )
F_71 ( V_286 ) ;
V_150 = F_140 ( V_287 , F_118 ) ;
if ( ! V_150 )
F_71 ( V_288 ) ;
F_141 ( & V_289 ) ;
F_142 () ;
F_143 () ;
V_17:
return V_2 ;
}
static void T_5 F_144 ( void )
{
F_145 () ;
F_146 () ;
F_147 ( & V_289 ) ;
F_44 () ;
if ( V_150 ) {
F_148 ( V_150 ) ;
V_150 = NULL ;
}
if ( V_147 ) {
F_149 ( V_147 ) ;
V_147 = NULL ;
}
F_150 ( & V_283 ) ;
if ( V_151 ) {
F_151 ( V_151 ) ;
V_151 = NULL ;
}
F_150 ( & V_281 ) ;
if ( V_149 ) {
F_152 ( V_149 ) ;
V_149 = NULL ;
}
F_153 ( & V_206 ) ;
F_154 ( V_280 . V_290 ) ;
}
