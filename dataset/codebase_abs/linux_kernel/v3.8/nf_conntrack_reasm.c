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
V_3 [ 2 ] . V_10 = & V_1 -> V_11 . V_12 . V_15 ;
}
V_5 = F_4 ( V_1 , L_1 , V_3 ) ;
if ( V_5 == NULL )
goto V_16;
V_1 -> V_17 . V_18 . V_19 = V_5 ;
return 0 ;
V_16:
if ( ! F_2 ( V_1 , & V_7 ) )
F_5 ( V_3 ) ;
V_9:
return - V_20 ;
}
static void T_1 F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_17 . V_18 . V_19 -> V_21 ;
F_7 ( V_1 -> V_17 . V_18 . V_19 ) ;
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
static unsigned int F_8 ( struct V_22 * V_23 )
{
const struct V_24 * V_25 ;
V_25 = F_9 ( V_23 , struct V_24 , V_23 ) ;
return F_10 ( V_25 -> V_26 , & V_25 -> V_27 , & V_25 -> V_28 , V_29 . V_30 ) ;
}
static void F_11 ( struct V_31 * V_32 )
{
if ( F_12 ( V_32 ) -> V_33 )
F_13 ( F_12 ( V_32 ) -> V_33 ) ;
}
static void F_14 ( unsigned long V_10 )
{
struct V_24 * V_34 ;
struct V_1 * V_1 ;
V_34 = F_9 ( (struct V_22 * ) V_10 , struct V_24 , V_23 ) ;
V_1 = F_9 ( V_34 -> V_23 . V_1 , struct V_1 , V_17 . V_12 ) ;
F_15 ( V_1 , V_34 , & V_29 ) ;
}
static inline struct V_24 * F_16 ( struct V_1 * V_1 , T_2 V_26 ,
T_3 V_35 , struct V_36 * V_37 ,
struct V_36 * V_38 )
{
struct V_22 * V_23 ;
struct V_39 V_40 ;
unsigned int V_41 ;
V_40 . V_26 = V_26 ;
V_40 . V_35 = V_35 ;
V_40 . V_37 = V_37 ;
V_40 . V_38 = V_38 ;
F_17 ( & V_29 . V_42 ) ;
V_41 = F_10 ( V_26 , V_37 , V_38 , V_29 . V_30 ) ;
V_23 = F_18 ( & V_1 -> V_17 . V_12 , & V_29 , & V_40 , V_41 ) ;
F_19 () ;
if ( V_23 == NULL )
goto V_43;
return F_9 ( V_23 , struct V_24 , V_23 ) ;
V_43:
return NULL ;
}
static int F_20 ( struct V_24 * V_34 , struct V_31 * V_32 ,
const struct V_44 * V_45 , int V_46 )
{
struct V_31 * V_47 , * V_48 ;
unsigned int V_49 ;
int V_50 , V_51 ;
if ( V_34 -> V_23 . V_52 & V_53 ) {
F_21 ( L_2 ) ;
goto V_54;
}
V_49 = F_22 ( F_23 ( V_32 ) -> V_49 ) ;
V_50 = F_22 ( V_45 -> V_55 ) & ~ 0x7 ;
V_51 = V_50 + ( V_49 -
( ( V_56 * ) ( V_45 + 1 ) - ( V_56 * ) ( F_23 ( V_32 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_51 > V_57 ) {
F_21 ( L_3 ) ;
return - 1 ;
}
if ( V_32 -> V_58 == V_59 ) {
const unsigned char * V_60 = F_24 ( V_32 ) ;
V_32 -> V_61 = F_25 ( V_32 -> V_61 ,
F_26 ( V_60 , ( V_56 * ) ( V_45 + 1 ) - V_60 ,
0 ) ) ;
}
if ( ! ( V_45 -> V_55 & F_27 ( V_62 ) ) ) {
if ( V_51 < V_34 -> V_23 . V_63 ||
( ( V_34 -> V_23 . V_52 & V_64 ) && V_51 != V_34 -> V_23 . V_63 ) ) {
F_21 ( L_4 ) ;
goto V_54;
}
V_34 -> V_23 . V_52 |= V_64 ;
V_34 -> V_23 . V_63 = V_51 ;
} else {
if ( V_51 & 0x7 ) {
F_21 ( L_5 ) ;
return - 1 ;
}
if ( V_51 > V_34 -> V_23 . V_63 ) {
if ( V_34 -> V_23 . V_52 & V_64 ) {
F_21 ( L_6 ) ;
goto V_54;
}
V_34 -> V_23 . V_63 = V_51 ;
}
}
if ( V_51 == V_50 )
goto V_54;
if ( ! F_28 ( V_32 , ( V_56 * ) ( V_45 + 1 ) - V_32 -> V_10 ) ) {
F_21 ( L_7 ) ;
goto V_54;
}
if ( F_29 ( V_32 , V_51 - V_50 ) ) {
F_21 ( L_8 ) ;
goto V_54;
}
V_47 = V_34 -> V_23 . V_65 ;
if ( ! V_47 || F_12 ( V_47 ) -> V_50 < V_50 ) {
V_48 = NULL ;
goto V_66;
}
V_47 = NULL ;
for ( V_48 = V_34 -> V_23 . V_67 ; V_48 != NULL ; V_48 = V_48 -> V_48 ) {
if ( F_12 ( V_48 ) -> V_50 >= V_50 )
break;
V_47 = V_48 ;
}
V_66:
if ( V_47 &&
( F_12 ( V_47 ) -> V_50 + V_47 -> V_63 ) > V_50 )
goto V_68;
if ( V_48 && F_12 ( V_48 ) -> V_50 < V_51 )
goto V_68;
F_12 ( V_32 ) -> V_50 = V_50 ;
V_32 -> V_48 = V_48 ;
if ( ! V_48 )
V_34 -> V_23 . V_65 = V_32 ;
if ( V_47 )
V_47 -> V_48 = V_32 ;
else
V_34 -> V_23 . V_67 = V_32 ;
if ( V_32 -> V_69 ) {
V_34 -> V_70 = V_32 -> V_69 -> V_71 ;
V_32 -> V_69 = NULL ;
}
V_34 -> V_23 . V_72 = V_32 -> V_73 ;
V_34 -> V_23 . V_74 += V_32 -> V_63 ;
if ( V_49 > V_34 -> V_23 . V_75 )
V_34 -> V_23 . V_75 = V_49 ;
F_30 ( V_32 -> V_76 , & V_34 -> V_23 . V_1 -> V_77 ) ;
if ( V_50 == 0 ) {
V_34 -> V_78 = V_46 ;
V_34 -> V_23 . V_52 |= V_79 ;
}
F_31 ( & V_29 . V_42 ) ;
F_32 ( & V_34 -> V_23 . V_80 , & V_34 -> V_23 . V_1 -> V_80 ) ;
F_33 ( & V_29 . V_42 ) ;
return 0 ;
V_68:
F_34 ( & V_34 -> V_23 , & V_29 ) ;
V_54:
return - 1 ;
}
static struct V_31 *
F_35 ( struct V_24 * V_34 , struct V_81 * V_69 )
{
struct V_31 * V_82 , * V_83 , * V_84 = V_34 -> V_23 . V_67 ;
int V_49 ;
F_34 ( & V_34 -> V_23 , & V_29 ) ;
F_36 ( V_84 == NULL ) ;
F_36 ( F_12 ( V_84 ) -> V_50 != 0 ) ;
V_49 = ( ( V_84 -> V_10 - F_24 ( V_84 ) ) -
sizeof( struct V_85 ) + V_34 -> V_23 . V_63 -
sizeof( struct V_44 ) ) ;
if ( V_49 > V_57 ) {
F_21 ( L_9 ) ;
goto V_86;
}
if ( F_37 ( V_84 ) && F_38 ( V_84 , 0 , 0 , V_87 ) ) {
F_21 ( L_10 ) ;
goto V_88;
}
if ( F_39 ( V_84 ) ) {
struct V_31 * V_89 ;
int V_90 , V_91 = 0 ;
V_89 = F_40 ( 0 , V_87 ) ;
if ( V_89 == NULL )
goto V_88;
V_89 -> V_48 = V_84 -> V_48 ;
V_84 -> V_48 = V_89 ;
F_41 ( V_89 ) -> V_92 = F_41 ( V_84 ) -> V_92 ;
F_42 ( V_84 ) ;
for ( V_90 = 0 ; V_90 < F_41 ( V_84 ) -> V_93 ; V_90 ++ )
V_91 += F_43 ( & F_41 ( V_84 ) -> V_12 [ V_90 ] ) ;
V_89 -> V_63 = V_89 -> V_94 = V_84 -> V_94 - V_91 ;
V_84 -> V_94 -= V_89 -> V_63 ;
V_84 -> V_63 -= V_89 -> V_63 ;
V_89 -> V_61 = 0 ;
V_89 -> V_58 = V_84 -> V_58 ;
F_12 ( V_89 ) -> V_33 = NULL ;
F_30 ( V_89 -> V_76 , & V_34 -> V_23 . V_1 -> V_77 ) ;
}
F_24 ( V_84 ) [ V_34 -> V_78 ] = F_44 ( V_84 ) [ 0 ] ;
memmove ( V_84 -> V_84 + sizeof( struct V_44 ) , V_84 -> V_84 ,
( V_84 -> V_10 - V_84 -> V_84 ) - sizeof( struct V_44 ) ) ;
V_84 -> V_95 += sizeof( struct V_44 ) ;
V_84 -> V_96 += sizeof( struct V_44 ) ;
F_41 ( V_84 ) -> V_92 = V_84 -> V_48 ;
F_45 ( V_84 ) ;
F_46 ( V_84 , V_84 -> V_10 - F_24 ( V_84 ) ) ;
for ( V_82 = V_84 -> V_48 ; V_82 ; V_82 = V_82 -> V_48 ) {
V_84 -> V_94 += V_82 -> V_63 ;
V_84 -> V_63 += V_82 -> V_63 ;
if ( V_84 -> V_58 != V_82 -> V_58 )
V_84 -> V_58 = V_97 ;
else if ( V_84 -> V_58 == V_59 )
V_84 -> V_61 = F_47 ( V_84 -> V_61 , V_82 -> V_61 ) ;
V_84 -> V_76 += V_82 -> V_76 ;
}
F_48 ( V_84 -> V_76 , & V_34 -> V_23 . V_1 -> V_77 ) ;
V_84 -> V_98 = 1 ;
V_84 -> V_48 = NULL ;
V_84 -> V_69 = V_69 ;
V_84 -> V_73 = V_34 -> V_23 . V_72 ;
F_23 ( V_84 ) -> V_49 = F_27 ( V_49 ) ;
F_49 ( V_84 ) -> V_99 = sizeof( struct V_85 ) + V_34 -> V_23 . V_75 ;
if ( V_84 -> V_58 == V_59 )
V_84 -> V_61 = F_26 ( F_24 ( V_84 ) ,
F_50 ( V_84 ) ,
V_84 -> V_61 ) ;
V_34 -> V_23 . V_67 = NULL ;
V_34 -> V_23 . V_65 = NULL ;
V_82 = F_41 ( V_84 ) -> V_92 ;
if ( V_82 && F_12 ( V_82 ) -> V_33 == NULL )
V_82 = V_82 -> V_48 ;
V_83 = F_12 ( V_84 ) -> V_33 ;
for (; V_82 ; V_82 = V_82 -> V_48 ) {
struct V_31 * V_33 = F_12 ( V_82 ) -> V_33 ;
V_83 -> V_48 = V_33 ;
V_83 = V_33 ;
F_12 ( V_82 ) -> V_33 = NULL ;
}
return V_84 ;
V_86:
F_51 ( L_11 ,
V_49 ) ;
goto V_100;
V_88:
F_51 ( L_12 ) ;
V_100:
return NULL ;
}
static int
F_52 ( struct V_31 * V_32 , V_56 * V_101 , int * V_102 , int * V_103 )
{
V_56 V_104 = F_23 ( V_32 ) -> V_104 ;
const int V_105 = F_53 ( V_32 ) ;
V_56 V_106 = V_105 + F_54 ( struct V_85 , V_104 ) ;
int V_107 = V_105 + sizeof( struct V_85 ) ;
int V_63 = V_32 -> V_63 - V_107 ;
V_56 V_108 = V_109 ;
while ( V_104 != V_110 ) {
struct V_111 V_5 ;
int V_112 ;
if ( ! F_55 ( V_104 ) ) {
return - 1 ;
}
if ( V_104 == V_113 ) {
F_21 ( L_13 ) ;
return - 1 ;
}
if ( V_63 < ( int ) sizeof( struct V_111 ) ) {
F_21 ( L_14 ) ;
return - 1 ;
}
if ( F_56 ( V_32 , V_107 , & V_5 , sizeof( V_5 ) ) )
F_57 () ;
if ( V_104 == V_114 )
V_112 = ( V_5 . V_112 + 2 ) << 2 ;
else
V_112 = F_58 ( & V_5 ) ;
V_108 = V_104 ;
V_106 = V_107 ;
V_104 = V_5 . V_104 ;
V_63 -= V_112 ;
V_107 += V_112 ;
}
if ( V_63 < 0 )
return - 1 ;
* V_101 = V_108 ;
* V_102 = V_106 ;
* V_103 = V_107 ;
return 0 ;
}
struct V_31 * F_59 ( struct V_31 * V_32 , T_3 V_35 )
{
struct V_31 * V_89 ;
struct V_81 * V_69 = V_32 -> V_69 ;
struct V_1 * V_1 = F_60 ( V_32 ) ? F_61 ( F_60 ( V_32 ) -> V_69 )
: F_61 ( V_32 -> V_69 ) ;
struct V_44 * V_45 ;
struct V_24 * V_34 ;
struct V_85 * V_5 ;
int V_103 , V_46 ;
V_56 V_108 ;
struct V_31 * V_115 = NULL ;
if ( F_23 ( V_32 ) -> V_49 == 0 ) {
F_21 ( L_15 ) ;
return V_32 ;
}
if ( F_52 ( V_32 , & V_108 , & V_46 , & V_103 ) < 0 )
return V_32 ;
V_89 = F_62 ( V_32 , V_87 ) ;
if ( V_89 == NULL ) {
F_21 ( L_16 ) ;
return V_32 ;
}
F_12 ( V_89 ) -> V_33 = V_32 ;
if ( ! F_63 ( V_89 , V_103 + sizeof( * V_45 ) ) ) {
F_21 ( L_17 ) ;
goto V_116;
}
F_64 ( V_89 , V_103 ) ;
V_5 = F_23 ( V_89 ) ;
V_45 = (struct V_44 * ) F_44 ( V_89 ) ;
F_65 () ;
F_66 ( & V_1 -> V_17 . V_12 , & V_29 , false ) ;
F_19 () ;
V_34 = F_16 ( V_1 , V_45 -> V_117 , V_35 , & V_5 -> V_27 , & V_5 -> V_28 ) ;
if ( V_34 == NULL ) {
F_21 ( L_18 ) ;
goto V_116;
}
F_67 ( & V_34 -> V_23 . V_42 ) ;
if ( F_20 ( V_34 , V_89 , V_45 , V_46 ) < 0 ) {
F_68 ( & V_34 -> V_23 . V_42 ) ;
F_21 ( L_19 ) ;
F_69 ( & V_34 -> V_23 , & V_29 ) ;
goto V_116;
}
if ( V_34 -> V_23 . V_52 == ( V_79 | V_64 ) &&
V_34 -> V_23 . V_74 == V_34 -> V_23 . V_63 ) {
V_115 = F_35 ( V_34 , V_69 ) ;
if ( V_115 == NULL )
F_21 ( L_20 ) ;
}
F_68 ( & V_34 -> V_23 . V_42 ) ;
F_69 ( & V_34 -> V_23 , & V_29 ) ;
return V_115 ;
V_116:
F_13 ( V_89 ) ;
return V_32 ;
}
void F_70 ( unsigned int V_118 , struct V_31 * V_32 ,
struct V_81 * V_119 , struct V_81 * V_120 ,
int (* F_71)( struct V_31 * ) )
{
struct V_31 * V_121 , * V_122 ;
unsigned int V_123 = 0 ;
for ( V_121 = F_12 ( V_32 ) -> V_33 ; V_121 ; ) {
F_72 ( V_121 -> V_124 ) ;
F_73 ( V_32 ) ;
V_121 -> V_124 = V_32 ;
V_122 = V_121 -> V_48 ;
V_121 -> V_48 = NULL ;
if ( V_123 != - V_125 )
V_123 = F_74 ( V_126 , V_118 , V_121 ,
V_119 , V_120 , F_71 ,
V_127 + 1 ) ;
else
F_13 ( V_121 ) ;
V_121 = V_122 ;
}
F_72 ( V_32 ) ;
}
static int F_75 ( struct V_1 * V_1 )
{
V_1 -> V_17 . V_12 . V_13 = V_128 ;
V_1 -> V_17 . V_12 . V_14 = V_129 ;
V_1 -> V_17 . V_12 . V_15 = V_130 ;
F_76 ( & V_1 -> V_17 . V_12 ) ;
return F_1 ( V_1 ) ;
}
static void F_77 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_78 ( & V_1 -> V_17 . V_12 , & V_29 ) ;
}
int F_79 ( void )
{
int V_123 = 0 ;
V_29 . V_131 = F_8 ;
V_29 . V_132 = V_133 ;
V_29 . V_134 = NULL ;
V_29 . V_135 = F_11 ;
V_29 . V_136 = sizeof( struct V_24 ) ;
V_29 . V_137 = V_138 ;
V_29 . V_139 = F_14 ;
V_29 . V_140 = 10 * 60 * V_141 ;
F_80 ( & V_29 ) ;
V_123 = F_81 ( & V_142 ) ;
if ( V_123 )
F_82 ( & V_29 ) ;
return V_123 ;
}
void F_83 ( void )
{
F_84 ( & V_142 ) ;
F_82 ( & V_29 ) ;
}
