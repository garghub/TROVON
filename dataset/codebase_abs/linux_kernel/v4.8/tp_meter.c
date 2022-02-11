static T_1 F_1 ( const T_2 V_1 [ 2 ] , T_2 V_2 )
{
T_1 V_3 ;
V_3 = V_2 << 16 ;
V_3 |= V_1 [ 0 ] << 8 ;
V_3 |= V_1 [ 1 ] ;
return V_3 ;
}
static T_1 F_2 ( T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = V_4 + V_5 ;
if ( V_7 < V_4 )
V_7 = ( T_1 ) V_8 ;
V_7 = F_3 ( T_1 , V_7 , V_9 ) ;
return F_4 ( T_1 , V_7 , V_6 ) ;
}
static void F_5 ( struct V_10 * V_11 , T_1 V_12 )
{
F_6 ( & V_11 -> V_13 ) ;
if ( V_11 -> V_14 <= V_11 -> V_15 ) {
V_11 -> V_16 = 0 ;
V_11 -> V_14 = F_2 ( V_11 -> V_14 , V_12 , V_12 ) ;
F_7 ( & V_11 -> V_13 ) ;
return;
}
V_11 -> V_16 += F_4 ( T_1 , 1U << 3 ,
( ( V_12 * V_12 ) << 6 ) / ( V_11 -> V_14 << 3 ) ) ;
if ( V_11 -> V_16 < ( V_12 << 3 ) ) {
F_7 ( & V_11 -> V_13 ) ;
return;
}
V_11 -> V_14 = F_2 ( V_11 -> V_14 , V_12 , V_12 ) ;
V_11 -> V_16 = 0 ;
F_7 ( & V_11 -> V_13 ) ;
}
static void F_8 ( struct V_10 * V_11 ,
T_1 V_17 )
{
long V_18 = V_17 ;
if ( V_11 -> V_19 != 0 ) {
V_18 -= ( V_11 -> V_19 >> 3 ) ;
V_11 -> V_19 += V_18 ;
if ( V_18 < 0 )
V_18 = - V_18 ;
V_18 -= ( V_11 -> V_20 >> 2 ) ;
V_11 -> V_20 += V_18 ;
} else {
V_11 -> V_19 = V_18 << 3 ;
V_11 -> V_20 = V_18 << 1 ;
}
V_11 -> V_21 = ( V_11 -> V_19 >> 3 ) + V_11 -> V_20 ;
}
static void F_9 ( enum V_22 V_23 ,
const T_2 * V_24 , struct V_25 * V_26 ,
unsigned long V_27 , T_3 V_28 ,
T_1 V_3 )
{
T_1 V_29 ;
T_2 V_30 ;
T_1 V_31 ;
if ( ! F_10 ( V_23 ) ) {
V_30 = V_32 ;
V_29 = F_11 ( V_33 - V_27 ) ;
V_31 = V_28 ;
} else {
V_30 = V_23 ;
V_29 = 0 ;
V_31 = 0 ;
}
F_12 ( V_26 , V_24 , V_30 , V_29 ,
V_31 , V_3 ) ;
}
static void F_13 ( enum V_22 V_23 ,
const T_2 * V_24 ,
struct V_25 * V_26 ,
T_1 V_3 )
{
F_9 ( V_23 , V_24 , V_26 , 0 , 0 , V_3 ) ;
}
static struct V_10 * F_14 ( struct V_25 * V_26 ,
const T_2 * V_24 )
{
struct V_10 * V_34 , * V_11 = NULL ;
F_15 () ;
F_16 (pos, &bat_priv->tp_list, list) {
if ( ! F_17 ( V_34 -> V_35 , V_24 ) )
continue;
if ( F_18 ( ! F_19 ( & V_34 -> V_36 ) ) )
continue;
V_11 = V_34 ;
break;
}
F_20 () ;
return V_11 ;
}
static struct V_10 *
F_21 ( struct V_25 * V_26 , const T_2 * V_24 ,
const T_2 * V_1 )
{
struct V_10 * V_34 , * V_11 = NULL ;
F_15 () ;
F_16 (pos, &bat_priv->tp_list, list) {
if ( ! F_17 ( V_34 -> V_35 , V_24 ) )
continue;
if ( memcmp ( V_34 -> V_1 , V_1 , sizeof( V_34 -> V_1 ) ) != 0 )
continue;
if ( F_18 ( ! F_19 ( & V_34 -> V_36 ) ) )
continue;
V_11 = V_34 ;
break;
}
F_20 () ;
return V_11 ;
}
static void F_22 ( struct V_37 * V_38 )
{
struct V_10 * V_11 ;
struct V_39 * V_40 , * V_41 ;
V_11 = F_23 ( V_38 , struct V_10 , V_36 ) ;
F_6 ( & V_11 -> V_42 ) ;
F_24 (un, safe, &tp_vars->unacked_list, list) {
F_25 ( & V_40 -> V_43 ) ;
F_26 ( V_40 ) ;
}
F_7 ( & V_11 -> V_42 ) ;
F_27 ( V_11 , V_44 ) ;
}
static void F_28 ( struct V_10 * V_11 )
{
F_29 ( & V_11 -> V_36 , F_22 ) ;
}
static void F_30 ( struct V_25 * V_26 ,
struct V_10 * V_11 )
{
F_31 ( & V_11 -> V_45 ) ;
F_6 ( & V_11 -> V_26 -> V_46 ) ;
F_32 ( & V_11 -> V_43 ) ;
F_7 ( & V_11 -> V_26 -> V_46 ) ;
F_28 ( V_11 ) ;
F_33 ( & V_11 -> V_26 -> V_47 ) ;
F_34 ( & V_11 -> V_48 ) ;
F_35 ( & V_11 -> V_48 ) ;
F_28 ( V_11 ) ;
}
static void F_36 ( struct V_25 * V_26 ,
struct V_10 * V_11 )
{
T_1 V_49 ;
F_37 ( V_50 , V_26 ,
L_1 ,
V_11 -> V_35 , V_11 -> V_23 ) ;
F_37 ( V_50 , V_26 ,
L_2 ,
V_11 -> V_19 >> 3 , V_11 -> V_20 >> 2 , V_11 -> V_21 ) ;
F_37 ( V_50 , V_26 ,
L_3 ,
V_11 -> V_14 , V_11 -> V_15 ) ;
V_49 = F_1 ( V_11 -> V_1 ,
V_11 -> V_2 ) ;
F_9 ( V_11 -> V_23 ,
V_11 -> V_35 ,
V_26 ,
V_11 -> V_27 ,
F_38 ( & V_11 -> V_51 ) ,
V_49 ) ;
}
static void F_39 ( struct V_10 * V_11 ,
enum V_22 V_23 )
{
if ( ! F_40 ( & V_11 -> V_52 ) )
return;
V_11 -> V_23 = V_23 ;
}
static void F_41 ( struct V_53 * V_54 )
{
struct V_55 * V_55 ;
struct V_10 * V_11 ;
V_55 = F_42 ( V_54 ) ;
V_11 = F_23 ( V_55 , struct V_10 ,
V_45 ) ;
F_39 ( V_11 , V_32 ) ;
}
static void F_43 ( struct V_10 * V_11 )
{
if ( F_18 ( F_44 ( & V_11 -> V_52 ) == 0 ) )
return;
F_45 ( & V_11 -> V_48 , V_33 + F_46 ( V_11 -> V_21 ) ) ;
}
static void F_47 ( unsigned long V_56 )
{
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
struct V_25 * V_26 = V_11 -> V_26 ;
if ( F_44 ( & V_11 -> V_52 ) == 0 )
return;
if ( F_18 ( V_11 -> V_21 >= V_57 ) ) {
F_39 ( V_11 ,
V_58 ) ;
return;
}
V_11 -> V_21 <<= 1 ;
F_6 ( & V_11 -> V_13 ) ;
V_11 -> V_15 = V_11 -> V_14 >> 1 ;
if ( V_11 -> V_15 < V_59 * 2 )
V_11 -> V_15 = V_59 * 2 ;
F_37 ( V_50 , V_26 ,
L_4 ,
V_11 -> V_35 , V_11 -> V_14 , V_11 -> V_15 ,
F_44 ( & V_11 -> V_60 ) ) ;
V_11 -> V_14 = V_59 * 3 ;
F_7 ( & V_11 -> V_13 ) ;
V_11 -> V_61 = F_44 ( & V_11 -> V_60 ) ;
F_48 ( & V_11 -> V_62 ) ;
F_43 ( V_11 ) ;
}
static void F_49 ( struct V_10 * V_11 ,
T_2 * V_63 , T_4 V_64 )
{
T_1 V_65 ;
T_4 V_66 ;
T_4 V_67 ;
T_4 V_34 = 0 ;
F_6 ( & V_11 -> V_68 ) ;
V_65 = V_11 -> V_69 ;
V_11 -> V_69 += V_64 ;
V_11 -> V_69 %= sizeof( V_70 ) ;
F_7 ( & V_11 -> V_68 ) ;
while ( V_64 ) {
V_65 %= sizeof( V_70 ) ;
V_66 = sizeof( V_70 ) - V_65 ;
V_67 = V_6 ( V_64 , V_66 ) ;
memcpy ( & V_63 [ V_34 ] , & V_70 [ V_65 ] , V_67 ) ;
V_34 += V_67 ;
V_64 -= V_67 ;
V_65 = 0 ;
}
}
static int F_50 ( struct V_10 * V_11 , const T_2 * V_71 ,
struct V_72 * V_73 ,
T_1 V_74 , T_4 V_75 , const T_2 * V_1 ,
int V_76 , T_1 V_77 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_82 ;
T_2 * V_83 ;
T_4 V_84 ;
V_81 = F_51 ( NULL , V_75 + V_85 ) ;
if ( F_18 ( ! V_81 ) )
return V_86 ;
F_52 ( V_81 , V_85 ) ;
V_79 = (struct V_78 * ) F_53 ( V_81 , sizeof( * V_79 ) ) ;
F_54 ( V_79 -> V_24 , V_73 -> V_87 ) ;
F_54 ( V_79 -> V_87 , V_71 ) ;
V_79 -> V_88 = V_89 ;
V_79 -> V_90 = V_91 ;
V_79 -> V_92 = V_93 ;
V_79 -> V_94 = V_95 ;
V_79 -> V_76 = V_76 ;
V_79 -> V_96 = V_97 ;
memcpy ( V_79 -> V_1 , V_1 , sizeof( V_79 -> V_1 ) ) ;
V_79 -> V_74 = F_55 ( V_74 ) ;
V_79 -> V_77 = F_55 ( V_77 ) ;
V_84 = V_75 - sizeof( * V_79 ) ;
V_83 = ( T_2 * ) F_53 ( V_81 , V_84 ) ;
F_49 ( V_11 , V_83 , V_84 ) ;
V_82 = F_56 ( V_81 , V_73 , NULL ) ;
if ( V_82 == - 1 )
F_57 ( V_81 ) ;
if ( V_82 == V_98 )
return 0 ;
return V_99 ;
}
static void F_58 ( struct V_25 * V_26 ,
const struct V_80 * V_81 )
{
struct V_100 * V_101 = NULL ;
struct V_72 * V_73 = NULL ;
const struct V_78 * V_79 ;
struct V_10 * V_11 ;
T_4 V_102 , V_12 ;
T_1 V_103 , V_104 , V_14 ;
unsigned char * V_105 ;
V_102 = V_59 ;
V_12 = V_59 ;
V_102 += sizeof( struct V_106 ) ;
V_79 = (struct V_78 * ) V_81 -> V_83 ;
V_11 = F_21 ( V_26 , V_79 -> V_87 ,
V_79 -> V_1 ) ;
if ( F_18 ( ! V_11 ) )
return;
if ( F_18 ( F_44 ( & V_11 -> V_52 ) == 0 ) )
goto V_107;
if ( F_59 ( F_60 ( V_79 -> V_74 ) ,
( T_1 ) F_44 ( & V_11 -> V_60 ) ) )
goto V_107;
V_101 = F_61 ( V_26 ) ;
if ( F_18 ( ! V_101 ) )
goto V_107;
V_73 = F_62 ( V_26 , V_79 -> V_87 ) ;
if ( F_18 ( ! V_73 ) )
goto V_107;
V_103 = F_11 ( V_33 ) - F_60 ( V_79 -> V_77 ) ;
if ( V_79 -> V_77 && V_103 )
F_8 ( V_11 , V_103 ) ;
F_43 ( V_11 ) ;
V_104 = F_60 ( V_79 -> V_74 ) ;
if ( F_44 ( & V_11 -> V_60 ) == V_104 ) {
F_63 ( & V_11 -> V_108 ) ;
if ( F_44 ( & V_11 -> V_108 ) != 3 )
goto V_107;
if ( V_104 >= V_11 -> V_109 )
goto V_107;
F_50 ( V_11 , V_101 -> V_110 -> V_105 ,
V_73 , V_104 , V_102 ,
V_79 -> V_1 , V_79 -> V_76 ,
F_11 ( V_33 ) ) ;
F_6 ( & V_11 -> V_13 ) ;
V_11 -> V_111 = true ;
V_11 -> V_109 = V_11 -> V_61 ;
V_11 -> V_15 = V_11 -> V_14 >> 1 ;
F_37 ( V_50 , V_26 ,
L_5 ,
V_11 -> V_14 , V_11 -> V_15 ,
V_11 -> V_61 , V_104 ) ;
V_11 -> V_14 = F_2 ( V_11 -> V_15 , 3 * V_12 ,
V_12 ) ;
V_11 -> V_16 = 0 ;
V_11 -> V_61 = V_104 ;
F_7 ( & V_11 -> V_13 ) ;
} else {
F_64 ( V_104 - F_44 ( & V_11 -> V_60 ) ,
& V_11 -> V_51 ) ;
F_65 ( & V_11 -> V_108 , 0 ) ;
if ( V_11 -> V_111 ) {
if ( F_59 ( V_104 , V_11 -> V_109 ) ) {
V_105 = V_101 -> V_110 -> V_105 ;
F_50 ( V_11 , V_105 ,
V_73 , V_104 ,
V_102 , V_79 -> V_1 ,
V_79 -> V_76 ,
F_11 ( V_33 ) ) ;
V_11 -> V_14 = F_2 ( V_11 -> V_14 ,
V_12 , V_12 ) ;
} else {
V_11 -> V_111 = false ;
V_14 = F_2 ( V_11 -> V_15 , 0 ,
V_12 ) ;
V_11 -> V_14 = V_14 ;
}
goto V_112;
}
if ( V_104 - F_44 ( & V_11 -> V_60 ) >= V_12 )
F_5 ( V_11 , V_12 ) ;
V_112:
F_65 ( & V_11 -> V_60 , V_104 ) ;
}
F_48 ( & V_11 -> V_62 ) ;
V_107:
if ( F_66 ( V_101 ) )
F_67 ( V_101 ) ;
if ( F_66 ( V_73 ) )
F_68 ( V_73 ) ;
if ( F_66 ( V_11 ) )
F_28 ( V_11 ) ;
}
static bool F_69 ( struct V_10 * V_11 ,
T_4 V_113 )
{
T_1 V_114 , V_115 ;
V_115 = F_44 ( & V_11 -> V_60 ) + V_11 -> V_14 ;
V_114 = V_115 - V_11 -> V_61 ;
return V_114 >= V_113 ;
}
static int F_70 ( struct V_10 * V_11 , T_4 V_116 )
{
int V_117 ;
V_117 = F_71 ( V_11 -> V_62 ,
F_69 ( V_11 , V_116 ) ,
V_118 / 10 ) ;
return V_117 ;
}
static int F_72 ( void * V_56 )
{
struct V_10 * V_11 = V_56 ;
struct V_25 * V_26 = V_11 -> V_26 ;
struct V_100 * V_101 = NULL ;
struct V_72 * V_73 = NULL ;
T_4 V_113 , V_102 ;
int V_119 = 0 ;
if ( F_18 ( V_11 -> V_120 != V_121 ) ) {
V_119 = V_58 ;
V_11 -> V_23 = V_119 ;
goto V_107;
}
V_73 = F_62 ( V_26 , V_11 -> V_35 ) ;
if ( F_18 ( ! V_73 ) ) {
V_119 = V_58 ;
V_11 -> V_23 = V_119 ;
goto V_107;
}
V_101 = F_61 ( V_26 ) ;
if ( F_18 ( ! V_101 ) ) {
V_119 = V_58 ;
goto V_107;
}
V_113 = V_59 ;
F_73 ( sizeof( struct V_78 ) > V_59 ) ;
F_43 ( V_11 ) ;
F_74 ( V_122 , & V_11 -> V_45 ,
F_46 ( V_11 -> V_123 ) ) ;
while ( F_44 ( & V_11 -> V_52 ) != 0 ) {
if ( F_18 ( ! F_69 ( V_11 , V_113 ) ) ) {
F_70 ( V_11 , V_113 ) ;
continue;
}
V_102 = V_113 + sizeof( struct V_106 ) ;
V_119 = F_50 ( V_11 , V_101 -> V_110 -> V_105 ,
V_73 , V_11 -> V_61 ,
V_102 ,
V_11 -> V_1 , V_11 -> V_2 ,
F_11 ( V_33 ) ) ;
if ( F_18 ( V_119 && V_119 != V_99 ) ) {
F_37 ( V_50 , V_26 ,
L_6 ,
V_119 ) ;
if ( F_40 ( & V_11 -> V_52 ) )
V_11 -> V_23 = V_119 ;
break;
}
if ( ! V_119 )
V_11 -> V_61 += V_113 ;
F_75 () ;
}
V_107:
if ( F_66 ( V_101 ) )
F_67 ( V_101 ) ;
if ( F_66 ( V_73 ) )
F_68 ( V_73 ) ;
F_36 ( V_26 , V_11 ) ;
F_30 ( V_26 , V_11 ) ;
F_28 ( V_11 ) ;
F_76 ( 0 ) ;
}
static void F_77 ( struct V_10 * V_11 )
{
struct V_124 * V_125 ;
struct V_25 * V_26 = V_11 -> V_26 ;
T_1 V_49 ;
F_78 ( & V_11 -> V_36 ) ;
V_125 = F_79 ( F_72 , V_11 , L_7 ) ;
if ( F_80 ( V_125 ) ) {
V_49 = F_1 ( V_11 -> V_1 ,
V_11 -> V_2 ) ;
F_81 ( L_8 ) ;
F_13 ( V_86 ,
V_11 -> V_35 ,
V_26 , V_49 ) ;
F_28 ( V_11 ) ;
F_30 ( V_26 , V_11 ) ;
return;
}
F_82 ( V_125 ) ;
}
void F_83 ( struct V_25 * V_26 , const T_2 * V_24 ,
T_1 V_123 , T_1 * V_3 )
{
struct V_10 * V_11 ;
T_2 V_126 [ 2 ] ;
T_2 V_2 ;
T_1 V_49 ;
F_84 ( V_126 , sizeof( V_126 ) ) ;
F_84 ( & V_2 , 1 ) ;
V_49 = F_1 ( V_126 , V_2 ) ;
* V_3 = V_49 ;
F_6 ( & V_26 -> V_46 ) ;
V_11 = F_14 ( V_26 , V_24 ) ;
if ( V_11 ) {
F_7 ( & V_26 -> V_46 ) ;
F_28 ( V_11 ) ;
F_37 ( V_50 , V_26 ,
L_9 ) ;
F_13 ( V_127 ,
V_24 , V_26 , V_49 ) ;
return;
}
if ( ! F_85 ( & V_26 -> V_47 , 1 , V_128 ) ) {
F_7 ( & V_26 -> V_46 ) ;
F_37 ( V_50 , V_26 ,
L_10 ) ;
F_13 ( V_129 , V_24 ,
V_26 , V_49 ) ;
return;
}
V_11 = F_86 ( sizeof( * V_11 ) , V_130 ) ;
if ( ! V_11 ) {
F_7 ( & V_26 -> V_46 ) ;
F_37 ( V_50 , V_26 ,
L_11 ) ;
F_13 ( V_86 ,
V_24 , V_26 , V_49 ) ;
return;
}
F_54 ( V_11 -> V_35 , V_24 ) ;
F_87 ( & V_11 -> V_36 ) ;
V_11 -> V_120 = V_121 ;
F_65 ( & V_11 -> V_52 , 1 ) ;
memcpy ( V_11 -> V_1 , V_126 , sizeof( V_126 ) ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_61 = V_131 ;
F_65 ( & V_11 -> V_60 , V_131 ) ;
V_11 -> V_111 = false ;
V_11 -> V_109 = V_131 ;
V_11 -> V_14 = V_59 * 3 ;
V_11 -> V_15 = V_9 ;
V_11 -> V_21 = 1000 ;
V_11 -> V_19 = 0 ;
V_11 -> V_20 = 0 ;
F_88 ( & V_11 -> V_51 , 0 ) ;
F_78 ( & V_11 -> V_36 ) ;
F_89 ( & V_11 -> V_48 , F_47 ,
( unsigned long ) V_11 ) ;
V_11 -> V_26 = V_26 ;
V_11 -> V_27 = V_33 ;
F_90 ( & V_11 -> V_62 ) ;
F_91 ( & V_11 -> V_42 ) ;
F_92 ( & V_11 -> V_132 ) ;
F_91 ( & V_11 -> V_13 ) ;
V_11 -> V_69 = 0 ;
F_91 ( & V_11 -> V_68 ) ;
F_78 ( & V_11 -> V_36 ) ;
F_93 ( & V_11 -> V_43 , & V_26 -> V_133 ) ;
F_7 ( & V_26 -> V_46 ) ;
V_11 -> V_123 = V_123 ;
if ( ! V_11 -> V_123 )
V_11 -> V_123 = V_134 ;
F_37 ( V_50 , V_26 ,
L_12 ,
V_24 , V_123 ) ;
F_94 ( & V_11 -> V_45 , F_41 ) ;
F_77 ( V_11 ) ;
F_28 ( V_11 ) ;
}
void F_95 ( struct V_25 * V_26 , const T_2 * V_24 ,
T_2 V_135 )
{
struct V_72 * V_73 ;
struct V_10 * V_11 ;
F_37 ( V_50 , V_26 ,
L_13 , V_24 ) ;
V_73 = F_62 ( V_26 , V_24 ) ;
if ( ! V_73 )
return;
V_11 = F_14 ( V_26 , V_73 -> V_87 ) ;
if ( ! V_11 ) {
F_37 ( V_50 , V_26 ,
L_14 ) ;
goto V_107;
}
F_39 ( V_11 , V_135 ) ;
F_28 ( V_11 ) ;
V_107:
F_68 ( V_73 ) ;
}
static void F_96 ( struct V_10 * V_11 )
{
F_45 ( & V_11 -> V_48 ,
V_33 + F_46 ( V_136 ) ) ;
}
static void F_97 ( unsigned long V_56 )
{
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
struct V_39 * V_40 , * V_41 ;
struct V_25 * V_26 ;
V_26 = V_11 -> V_26 ;
if ( ! F_98 ( V_11 -> V_137 ,
V_136 ) ) {
F_96 ( V_11 ) ;
return;
}
F_37 ( V_50 , V_26 ,
L_15 ,
V_136 , V_11 -> V_35 ) ;
F_6 ( & V_11 -> V_26 -> V_46 ) ;
F_32 ( & V_11 -> V_43 ) ;
F_7 ( & V_11 -> V_26 -> V_46 ) ;
F_28 ( V_11 ) ;
F_33 ( & V_26 -> V_47 ) ;
F_6 ( & V_11 -> V_42 ) ;
F_24 (un, safe, &tp_vars->unacked_list, list) {
F_25 ( & V_40 -> V_43 ) ;
F_26 ( V_40 ) ;
}
F_7 ( & V_11 -> V_42 ) ;
F_28 ( V_11 ) ;
}
static int F_99 ( struct V_25 * V_26 , const T_2 * V_24 ,
T_1 V_138 , T_5 V_77 , const T_2 * V_1 ,
int V_139 )
{
struct V_100 * V_101 = NULL ;
struct V_72 * V_73 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_82 , V_117 ;
V_73 = F_62 ( V_26 , V_24 ) ;
if ( F_18 ( ! V_73 ) ) {
V_117 = V_58 ;
goto V_107;
}
V_101 = F_61 ( V_26 ) ;
if ( F_18 ( ! V_101 ) ) {
V_117 = V_58 ;
goto V_107;
}
V_81 = F_51 ( NULL , sizeof( * V_79 ) + V_85 ) ;
if ( F_18 ( ! V_81 ) ) {
V_117 = V_86 ;
goto V_107;
}
F_52 ( V_81 , V_85 ) ;
V_79 = (struct V_78 * ) F_53 ( V_81 , sizeof( * V_79 ) ) ;
V_79 -> V_90 = V_91 ;
V_79 -> V_88 = V_89 ;
V_79 -> V_92 = V_93 ;
V_79 -> V_94 = V_95 ;
F_54 ( V_79 -> V_24 , V_73 -> V_87 ) ;
F_54 ( V_79 -> V_87 , V_101 -> V_110 -> V_105 ) ;
V_79 -> V_76 = V_139 ;
V_79 -> V_96 = V_140 ;
memcpy ( V_79 -> V_1 , V_1 , sizeof( V_79 -> V_1 ) ) ;
V_79 -> V_74 = F_55 ( V_138 ) ;
V_79 -> V_77 = V_77 ;
V_82 = F_56 ( V_81 , V_73 , NULL ) ;
if ( V_82 == - 1 )
F_57 ( V_81 ) ;
if ( F_18 ( V_82 < 0 ) || ( V_82 == V_141 ) ) {
V_117 = V_58 ;
goto V_107;
}
V_117 = 0 ;
V_107:
if ( F_66 ( V_73 ) )
F_68 ( V_73 ) ;
if ( F_66 ( V_101 ) )
F_67 ( V_101 ) ;
return V_117 ;
}
static bool F_100 ( struct V_10 * V_11 ,
const struct V_80 * V_81 )
{
const struct V_78 * V_79 ;
struct V_39 * V_40 , * V_142 ;
T_1 V_113 ;
bool V_143 = false ;
V_142 = F_86 ( sizeof( * V_142 ) , V_130 ) ;
if ( F_18 ( ! V_142 ) )
return false ;
V_79 = (struct V_78 * ) V_81 -> V_83 ;
V_142 -> V_74 = F_60 ( V_79 -> V_74 ) ;
V_113 = V_81 -> V_75 - sizeof( struct V_106 ) ;
V_142 -> V_75 = V_113 ;
F_6 ( & V_11 -> V_42 ) ;
if ( F_101 ( & V_11 -> V_132 ) ) {
F_102 ( & V_142 -> V_43 , & V_11 -> V_132 ) ;
goto V_107;
}
F_103 (un, &tp_vars->unacked_list, list) {
if ( V_142 -> V_74 == V_40 -> V_74 ) {
if ( V_142 -> V_75 > V_40 -> V_75 )
V_40 -> V_75 = V_142 -> V_75 ;
F_26 ( V_142 ) ;
V_143 = true ;
break;
}
if ( F_59 ( V_142 -> V_74 , V_40 -> V_74 ) )
continue;
F_104 ( & V_142 -> V_43 , & V_40 -> V_43 ) ;
V_143 = true ;
break;
}
if ( ! V_143 )
F_102 ( & V_142 -> V_43 , & V_11 -> V_132 ) ;
V_107:
F_7 ( & V_11 -> V_42 ) ;
return true ;
}
static void F_105 ( struct V_10 * V_11 )
{
struct V_39 * V_40 , * V_41 ;
T_1 V_144 ;
F_6 ( & V_11 -> V_42 ) ;
F_24 (un, safe, &tp_vars->unacked_list, list) {
if ( F_59 ( V_11 -> V_145 , V_40 -> V_74 ) )
break;
V_144 = V_40 -> V_74 + V_40 -> V_75 - V_11 -> V_145 ;
if ( F_59 ( V_11 -> V_145 , V_40 -> V_74 + V_40 -> V_75 ) )
V_11 -> V_145 += V_144 ;
F_25 ( & V_40 -> V_43 ) ;
F_26 ( V_40 ) ;
}
F_7 ( & V_11 -> V_42 ) ;
}
static struct V_10 *
F_106 ( struct V_25 * V_26 ,
const struct V_78 * V_79 )
{
struct V_10 * V_11 ;
F_6 ( & V_26 -> V_46 ) ;
V_11 = F_21 ( V_26 , V_79 -> V_87 ,
V_79 -> V_1 ) ;
if ( V_11 )
goto V_146;
if ( ! F_85 ( & V_26 -> V_47 , 1 , V_128 ) ) {
F_37 ( V_50 , V_26 ,
L_16 ) ;
goto V_146;
}
V_11 = F_86 ( sizeof( * V_11 ) , V_130 ) ;
if ( ! V_11 )
goto V_146;
F_54 ( V_11 -> V_35 , V_79 -> V_87 ) ;
V_11 -> V_120 = V_147 ;
memcpy ( V_11 -> V_1 , V_79 -> V_1 , sizeof( V_11 -> V_1 ) ) ;
V_11 -> V_145 = V_131 ;
V_11 -> V_26 = V_26 ;
F_87 ( & V_11 -> V_36 ) ;
F_91 ( & V_11 -> V_42 ) ;
F_92 ( & V_11 -> V_132 ) ;
F_78 ( & V_11 -> V_36 ) ;
F_93 ( & V_11 -> V_43 , & V_26 -> V_133 ) ;
F_78 ( & V_11 -> V_36 ) ;
F_89 ( & V_11 -> V_48 , F_97 ,
( unsigned long ) V_11 ) ;
F_96 ( V_11 ) ;
V_146:
F_7 ( & V_26 -> V_46 ) ;
return V_11 ;
}
static void F_107 ( struct V_25 * V_26 ,
const struct V_80 * V_81 )
{
const struct V_78 * V_79 ;
struct V_10 * V_11 ;
T_4 V_148 ;
T_1 V_74 ;
V_79 = (struct V_78 * ) V_81 -> V_83 ;
V_74 = F_60 ( V_79 -> V_74 ) ;
if ( V_74 == V_131 ) {
V_11 = F_106 ( V_26 , V_79 ) ;
if ( ! V_11 ) {
F_37 ( V_50 , V_26 ,
L_17 ) ;
goto V_107;
}
} else {
V_11 = F_21 ( V_26 , V_79 -> V_87 ,
V_79 -> V_1 ) ;
if ( ! V_11 ) {
F_37 ( V_50 , V_26 ,
L_18 ,
V_79 -> V_87 ) ;
goto V_107;
}
}
if ( F_18 ( V_11 -> V_120 != V_147 ) ) {
F_37 ( V_50 , V_26 ,
L_19 ,
V_11 -> V_120 ) ;
goto V_107;
}
V_11 -> V_137 = V_33 ;
if ( F_59 ( V_74 , V_11 -> V_145 ) )
goto V_149;
if ( F_60 ( V_79 -> V_74 ) != V_11 -> V_145 ) {
if ( ! F_100 ( V_11 , V_81 ) )
goto V_107;
goto V_149;
}
V_148 = V_81 -> V_75 - sizeof( struct V_106 ) ;
V_11 -> V_145 += V_148 ;
F_105 ( V_11 ) ;
V_149:
F_99 ( V_26 , V_79 -> V_87 , V_11 -> V_145 ,
V_79 -> V_77 , V_79 -> V_1 , V_79 -> V_76 ) ;
V_107:
if ( F_66 ( V_11 ) )
F_28 ( V_11 ) ;
}
void F_108 ( struct V_25 * V_26 , struct V_80 * V_81 )
{
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) V_81 -> V_83 ;
switch ( V_79 -> V_96 ) {
case V_97 :
F_107 ( V_26 , V_81 ) ;
break;
case V_140 :
F_58 ( V_26 , V_81 ) ;
break;
default:
F_37 ( V_50 , V_26 ,
L_20 ,
V_79 -> V_96 ) ;
}
F_109 ( V_81 ) ;
}
void F_110 ( void )
{
F_84 ( V_70 , sizeof( V_70 ) ) ;
}
