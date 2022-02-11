static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_6 ;
if ( ! F_2 ( V_1 , & V_7 ) ) {
V_3 = F_3 ( V_3 , sizeof( V_6 ) ,
V_8 ) ;
if ( V_3 == NULL )
goto V_9;
V_3 [ 0 ] . V_10 = & V_1 -> V_11 . V_12 . V_13 ;
V_3 [ 1 ] . V_10 = & V_1 -> V_11 . V_12 . V_14 ;
V_3 [ 1 ] . V_15 = & V_1 -> V_11 . V_12 . V_16 ;
V_3 [ 2 ] . V_10 = & V_1 -> V_11 . V_12 . V_16 ;
V_3 [ 2 ] . V_17 = & V_1 -> V_11 . V_12 . V_14 ;
V_3 [ 2 ] . V_15 = & V_7 . V_11 . V_12 . V_16 ;
}
V_5 = F_4 ( V_1 , L_1 , V_3 ) ;
if ( V_5 == NULL )
goto V_18;
V_1 -> V_11 . V_19 . V_20 = V_5 ;
return 0 ;
V_18:
if ( ! F_2 ( V_1 , & V_7 ) )
F_5 ( V_3 ) ;
V_9:
return - V_21 ;
}
static void T_1 F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_11 . V_19 . V_20 -> V_22 ;
F_7 ( V_1 -> V_11 . V_19 . V_20 ) ;
if ( ! F_2 ( V_1 , & V_7 ) )
F_5 ( V_3 ) ;
}
static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
static void T_1 F_6 ( struct V_1 * V_1 )
{
}
static inline T_2 F_8 ( const struct V_23 * V_24 )
{
return 1 << ( F_9 ( V_24 ) & V_25 ) ;
}
static unsigned int F_10 ( T_3 V_26 , const struct V_27 * V_28 ,
const struct V_27 * V_29 )
{
F_11 ( & V_30 . V_31 , sizeof( V_30 . V_31 ) ) ;
return F_12 ( F_13 ( V_28 ) , F_13 ( V_29 ) ,
( V_32 V_33 ) V_26 , V_30 . V_31 ) ;
}
static unsigned int F_14 ( const struct V_34 * V_35 )
{
const struct V_36 * V_37 ;
V_37 = F_15 ( V_35 , struct V_36 , V_35 ) ;
return F_10 ( V_37 -> V_26 , & V_37 -> V_28 , & V_37 -> V_29 ) ;
}
static void F_16 ( struct V_38 * V_39 )
{
if ( F_17 ( V_39 ) -> V_40 )
F_18 ( F_17 ( V_39 ) -> V_40 ) ;
}
static void F_19 ( unsigned long V_10 )
{
struct V_36 * V_41 ;
struct V_1 * V_1 ;
V_41 = F_15 ( (struct V_34 * ) V_10 , struct V_36 , V_35 ) ;
V_1 = F_15 ( V_41 -> V_35 . V_1 , struct V_1 , V_11 . V_12 ) ;
F_20 ( V_1 , V_41 , & V_30 ) ;
}
static inline struct V_36 * F_21 ( struct V_1 * V_1 , T_3 V_26 ,
V_33 V_42 , struct V_27 * V_43 ,
struct V_27 * V_44 , T_2 V_45 )
{
struct V_34 * V_35 ;
struct V_46 V_47 ;
unsigned int V_48 ;
V_47 . V_26 = V_26 ;
V_47 . V_42 = V_42 ;
V_47 . V_43 = V_43 ;
V_47 . V_44 = V_44 ;
V_47 . V_45 = V_45 ;
F_22 () ;
V_48 = F_10 ( V_26 , V_43 , V_44 ) ;
V_35 = F_23 ( & V_1 -> V_11 . V_12 , & V_30 , & V_47 , V_48 ) ;
F_24 () ;
if ( F_25 ( V_35 ) ) {
F_26 ( V_35 , F_27 () ) ;
return NULL ;
}
return F_15 ( V_35 , struct V_36 , V_35 ) ;
}
static int F_28 ( struct V_36 * V_41 , struct V_38 * V_39 ,
const struct V_49 * V_50 , int V_51 )
{
struct V_38 * V_52 , * V_53 ;
unsigned int V_54 ;
int V_55 , V_56 ;
T_2 V_45 ;
if ( V_41 -> V_35 . V_57 & V_58 ) {
F_29 ( L_2 ) ;
goto V_59;
}
V_54 = F_30 ( F_31 ( V_39 ) -> V_54 ) ;
V_55 = F_30 ( V_50 -> V_60 ) & ~ 0x7 ;
V_56 = V_55 + ( V_54 -
( ( T_2 * ) ( V_50 + 1 ) - ( T_2 * ) ( F_31 ( V_39 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_56 > V_61 ) {
F_29 ( L_3 ) ;
return - 1 ;
}
V_45 = F_8 ( F_31 ( V_39 ) ) ;
if ( V_39 -> V_62 == V_63 ) {
const unsigned char * V_64 = F_32 ( V_39 ) ;
V_39 -> V_65 = F_33 ( V_39 -> V_65 ,
F_34 ( V_64 , ( T_2 * ) ( V_50 + 1 ) - V_64 ,
0 ) ) ;
}
if ( ! ( V_50 -> V_60 & F_35 ( V_66 ) ) ) {
if ( V_56 < V_41 -> V_35 . V_67 ||
( ( V_41 -> V_35 . V_57 & V_68 ) && V_56 != V_41 -> V_35 . V_67 ) ) {
F_29 ( L_4 ) ;
goto V_59;
}
V_41 -> V_35 . V_57 |= V_68 ;
V_41 -> V_35 . V_67 = V_56 ;
} else {
if ( V_56 & 0x7 ) {
F_29 ( L_5 ) ;
return - 1 ;
}
if ( V_56 > V_41 -> V_35 . V_67 ) {
if ( V_41 -> V_35 . V_57 & V_68 ) {
F_29 ( L_6 ) ;
goto V_59;
}
V_41 -> V_35 . V_67 = V_56 ;
}
}
if ( V_56 == V_55 )
goto V_59;
if ( ! F_36 ( V_39 , ( T_2 * ) ( V_50 + 1 ) - V_39 -> V_10 ) ) {
F_29 ( L_7 ) ;
goto V_59;
}
if ( F_37 ( V_39 , V_56 - V_55 ) ) {
F_29 ( L_8 ) ;
goto V_59;
}
V_52 = V_41 -> V_35 . V_69 ;
if ( ! V_52 || F_17 ( V_52 ) -> V_55 < V_55 ) {
V_53 = NULL ;
goto V_70;
}
V_52 = NULL ;
for ( V_53 = V_41 -> V_35 . V_71 ; V_53 != NULL ; V_53 = V_53 -> V_53 ) {
if ( F_17 ( V_53 ) -> V_55 >= V_55 )
break;
V_52 = V_53 ;
}
V_70:
if ( V_52 &&
( F_17 ( V_52 ) -> V_55 + V_52 -> V_67 ) > V_55 )
goto V_72;
if ( V_53 && F_17 ( V_53 ) -> V_55 < V_56 )
goto V_72;
F_17 ( V_39 ) -> V_55 = V_55 ;
V_39 -> V_53 = V_53 ;
if ( ! V_53 )
V_41 -> V_35 . V_69 = V_39 ;
if ( V_52 )
V_52 -> V_53 = V_39 ;
else
V_41 -> V_35 . V_71 = V_39 ;
if ( V_39 -> V_73 ) {
V_41 -> V_74 = V_39 -> V_73 -> V_75 ;
V_39 -> V_73 = NULL ;
}
V_41 -> V_35 . V_76 = V_39 -> V_77 ;
V_41 -> V_35 . V_78 += V_39 -> V_67 ;
V_41 -> V_45 |= V_45 ;
if ( V_54 > V_41 -> V_35 . V_79 )
V_41 -> V_35 . V_79 = V_54 ;
F_38 ( V_41 -> V_35 . V_1 , V_39 -> V_80 ) ;
if ( V_55 == 0 ) {
V_41 -> V_81 = V_51 ;
V_41 -> V_35 . V_57 |= V_82 ;
}
return 0 ;
V_72:
F_39 ( & V_41 -> V_35 , & V_30 ) ;
V_59:
return - 1 ;
}
static struct V_38 *
F_40 ( struct V_36 * V_41 , struct V_83 * V_73 )
{
struct V_38 * V_84 , * V_85 , * V_86 = V_41 -> V_35 . V_71 ;
int V_54 ;
T_2 V_45 ;
F_39 ( & V_41 -> V_35 , & V_30 ) ;
F_41 ( V_86 == NULL ) ;
F_41 ( F_17 ( V_86 ) -> V_55 != 0 ) ;
V_45 = V_87 [ V_41 -> V_45 ] ;
if ( F_42 ( V_45 == 0xff ) )
goto V_88;
V_54 = ( ( V_86 -> V_10 - F_32 ( V_86 ) ) -
sizeof( struct V_23 ) + V_41 -> V_35 . V_67 -
sizeof( struct V_49 ) ) ;
if ( V_54 > V_61 ) {
F_29 ( L_9 ) ;
goto V_89;
}
if ( F_43 ( V_86 , V_90 ) ) {
F_29 ( L_10 ) ;
goto V_91;
}
if ( F_44 ( V_86 ) ) {
struct V_38 * V_92 ;
int V_93 , V_94 = 0 ;
V_92 = F_45 ( 0 , V_90 ) ;
if ( V_92 == NULL )
goto V_91;
V_92 -> V_53 = V_86 -> V_53 ;
V_86 -> V_53 = V_92 ;
F_46 ( V_92 ) -> V_95 = F_46 ( V_86 ) -> V_95 ;
F_47 ( V_86 ) ;
for ( V_93 = 0 ; V_93 < F_46 ( V_86 ) -> V_96 ; V_93 ++ )
V_94 += F_48 ( & F_46 ( V_86 ) -> V_12 [ V_93 ] ) ;
V_92 -> V_67 = V_92 -> V_97 = V_86 -> V_97 - V_94 ;
V_86 -> V_97 -= V_92 -> V_67 ;
V_86 -> V_67 -= V_92 -> V_67 ;
V_92 -> V_65 = 0 ;
V_92 -> V_62 = V_86 -> V_62 ;
F_17 ( V_92 ) -> V_40 = NULL ;
F_38 ( V_41 -> V_35 . V_1 , V_92 -> V_80 ) ;
}
F_32 ( V_86 ) [ V_41 -> V_81 ] = F_49 ( V_86 ) [ 0 ] ;
memmove ( V_86 -> V_86 + sizeof( struct V_49 ) , V_86 -> V_86 ,
( V_86 -> V_10 - V_86 -> V_86 ) - sizeof( struct V_49 ) ) ;
V_86 -> V_98 += sizeof( struct V_49 ) ;
V_86 -> V_99 += sizeof( struct V_49 ) ;
F_46 ( V_86 ) -> V_95 = V_86 -> V_53 ;
F_50 ( V_86 ) ;
F_51 ( V_86 , V_86 -> V_10 - F_32 ( V_86 ) ) ;
for ( V_84 = V_86 -> V_53 ; V_84 ; V_84 = V_84 -> V_53 ) {
V_86 -> V_97 += V_84 -> V_67 ;
V_86 -> V_67 += V_84 -> V_67 ;
if ( V_86 -> V_62 != V_84 -> V_62 )
V_86 -> V_62 = V_100 ;
else if ( V_86 -> V_62 == V_63 )
V_86 -> V_65 = F_52 ( V_86 -> V_65 , V_84 -> V_65 ) ;
V_86 -> V_80 += V_84 -> V_80 ;
}
F_53 ( V_41 -> V_35 . V_1 , V_86 -> V_80 ) ;
V_86 -> V_101 = 1 ;
V_86 -> V_53 = NULL ;
V_86 -> V_73 = V_73 ;
V_86 -> V_77 = V_41 -> V_35 . V_76 ;
F_31 ( V_86 ) -> V_54 = F_35 ( V_54 ) ;
F_54 ( F_31 ( V_86 ) , 0xff , V_45 ) ;
F_55 ( V_86 ) -> V_102 = sizeof( struct V_23 ) + V_41 -> V_35 . V_79 ;
if ( V_86 -> V_62 == V_63 )
V_86 -> V_65 = F_34 ( F_32 ( V_86 ) ,
F_56 ( V_86 ) ,
V_86 -> V_65 ) ;
V_41 -> V_35 . V_71 = NULL ;
V_41 -> V_35 . V_69 = NULL ;
V_84 = F_46 ( V_86 ) -> V_95 ;
if ( V_84 && F_17 ( V_84 ) -> V_40 == NULL )
V_84 = V_84 -> V_53 ;
V_85 = F_17 ( V_86 ) -> V_40 ;
for (; V_84 ; V_84 = V_84 -> V_53 ) {
struct V_38 * V_40 = F_17 ( V_84 ) -> V_40 ;
V_85 -> V_53 = V_40 ;
V_85 = V_40 ;
F_17 ( V_84 ) -> V_40 = NULL ;
}
return V_86 ;
V_89:
F_57 ( L_11 ,
V_54 ) ;
goto V_88;
V_91:
F_57 ( L_12 ) ;
V_88:
return NULL ;
}
static int
F_58 ( struct V_38 * V_39 , T_2 * V_103 , int * V_104 , int * V_105 )
{
T_2 V_106 = F_31 ( V_39 ) -> V_106 ;
const int V_107 = F_59 ( V_39 ) ;
T_2 V_108 = V_107 + F_60 ( struct V_23 , V_106 ) ;
int V_109 = V_107 + sizeof( struct V_23 ) ;
int V_67 = V_39 -> V_67 - V_109 ;
T_2 V_110 = V_111 ;
while ( V_106 != V_112 ) {
struct V_113 V_5 ;
int V_114 ;
if ( ! F_61 ( V_106 ) ) {
return - 1 ;
}
if ( V_106 == V_115 ) {
F_29 ( L_13 ) ;
return - 1 ;
}
if ( V_67 < ( int ) sizeof( struct V_113 ) ) {
F_29 ( L_14 ) ;
return - 1 ;
}
if ( F_62 ( V_39 , V_109 , & V_5 , sizeof( V_5 ) ) )
F_63 () ;
if ( V_106 == V_116 )
V_114 = ( V_5 . V_114 + 2 ) << 2 ;
else
V_114 = F_64 ( & V_5 ) ;
V_110 = V_106 ;
V_108 = V_109 ;
V_106 = V_5 . V_106 ;
V_67 -= V_114 ;
V_109 += V_114 ;
}
if ( V_67 < 0 )
return - 1 ;
* V_103 = V_110 ;
* V_104 = V_108 ;
* V_105 = V_109 ;
return 0 ;
}
struct V_38 * F_65 ( struct V_38 * V_39 , V_33 V_42 )
{
struct V_38 * V_92 ;
struct V_83 * V_73 = V_39 -> V_73 ;
struct V_1 * V_1 = F_66 ( V_39 ) ? F_67 ( F_66 ( V_39 ) -> V_73 )
: F_67 ( V_39 -> V_73 ) ;
struct V_49 * V_50 ;
struct V_36 * V_41 ;
struct V_23 * V_5 ;
int V_105 , V_51 ;
T_2 V_110 ;
struct V_38 * V_117 = NULL ;
if ( F_31 ( V_39 ) -> V_54 == 0 ) {
F_29 ( L_15 ) ;
return V_39 ;
}
if ( F_58 ( V_39 , & V_110 , & V_51 , & V_105 ) < 0 )
return V_39 ;
V_92 = F_68 ( V_39 , V_90 ) ;
if ( V_92 == NULL ) {
F_29 ( L_16 ) ;
return V_39 ;
}
F_17 ( V_92 ) -> V_40 = V_39 ;
if ( ! F_69 ( V_92 , V_105 + sizeof( * V_50 ) ) ) {
F_29 ( L_17 ) ;
goto V_118;
}
F_70 ( V_92 , V_105 ) ;
V_5 = F_31 ( V_92 ) ;
V_50 = (struct V_49 * ) F_49 ( V_92 ) ;
V_41 = F_21 ( V_1 , V_50 -> V_119 , V_42 , & V_5 -> V_28 , & V_5 -> V_29 ,
F_8 ( V_5 ) ) ;
if ( V_41 == NULL ) {
F_29 ( L_18 ) ;
goto V_118;
}
F_71 ( & V_41 -> V_35 . V_120 ) ;
if ( F_28 ( V_41 , V_92 , V_50 , V_51 ) < 0 ) {
F_72 ( & V_41 -> V_35 . V_120 ) ;
F_29 ( L_19 ) ;
F_73 ( & V_41 -> V_35 , & V_30 ) ;
goto V_118;
}
if ( V_41 -> V_35 . V_57 == ( V_82 | V_68 ) &&
V_41 -> V_35 . V_78 == V_41 -> V_35 . V_67 ) {
V_117 = F_40 ( V_41 , V_73 ) ;
if ( V_117 == NULL )
F_29 ( L_20 ) ;
}
F_72 ( & V_41 -> V_35 . V_120 ) ;
F_73 ( & V_41 -> V_35 , & V_30 ) ;
return V_117 ;
V_118:
F_18 ( V_92 ) ;
return V_39 ;
}
void F_74 ( struct V_38 * V_39 )
{
struct V_38 * V_121 , * V_122 ;
for ( V_121 = F_17 ( V_39 ) -> V_40 ; V_121 ; ) {
V_122 = V_121 -> V_53 ;
V_121 -> V_53 = NULL ;
F_75 ( V_121 ) ;
V_121 = V_122 ;
}
}
static int F_76 ( struct V_1 * V_1 )
{
V_1 -> V_11 . V_12 . V_16 = V_123 ;
V_1 -> V_11 . V_12 . V_14 = V_124 ;
V_1 -> V_11 . V_12 . V_13 = V_125 ;
F_77 ( & V_1 -> V_11 . V_12 ) ;
return F_1 ( V_1 ) ;
}
static void F_78 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_79 ( & V_1 -> V_11 . V_12 , & V_30 ) ;
}
int F_80 ( void )
{
int V_126 = 0 ;
V_30 . V_127 = F_14 ;
V_30 . V_128 = V_129 ;
V_30 . V_130 = NULL ;
V_30 . V_131 = F_16 ;
V_30 . V_132 = sizeof( struct V_36 ) ;
V_30 . V_133 = V_134 ;
V_30 . V_135 = F_19 ;
V_30 . V_136 = V_137 ;
V_126 = F_81 ( & V_30 ) ;
if ( V_126 )
goto V_138;
V_126 = F_82 ( & V_139 ) ;
if ( V_126 )
F_83 ( & V_30 ) ;
V_138:
return V_126 ;
}
void F_84 ( void )
{
F_85 ( & V_139 ) ;
F_83 ( & V_30 ) ;
}
