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
V_1 -> V_11 . V_17 . V_18 = V_5 ;
return 0 ;
V_16:
if ( ! F_2 ( V_1 , & V_7 ) )
F_5 ( V_3 ) ;
V_9:
return - V_19 ;
}
static void T_1 F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_11 . V_17 . V_18 -> V_20 ;
F_7 ( V_1 -> V_11 . V_17 . V_18 ) ;
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
static inline T_2 F_8 ( const struct V_21 * V_22 )
{
return 1 << ( F_9 ( V_22 ) & V_23 ) ;
}
static unsigned int F_10 ( struct V_24 * V_25 )
{
const struct V_26 * V_27 ;
V_27 = F_11 ( V_25 , struct V_26 , V_25 ) ;
return F_12 ( V_27 -> V_28 , & V_27 -> V_29 , & V_27 -> V_30 , V_31 . V_32 ) ;
}
static void F_13 ( struct V_33 * V_34 )
{
if ( F_14 ( V_34 ) -> V_35 )
F_15 ( F_14 ( V_34 ) -> V_35 ) ;
}
static void F_16 ( unsigned long V_10 )
{
struct V_26 * V_36 ;
struct V_1 * V_1 ;
V_36 = F_11 ( (struct V_24 * ) V_10 , struct V_26 , V_25 ) ;
V_1 = F_11 ( V_36 -> V_25 . V_1 , struct V_1 , V_11 . V_12 ) ;
F_17 ( V_1 , V_36 , & V_31 ) ;
}
static inline struct V_26 * F_18 ( struct V_1 * V_1 , T_3 V_28 ,
T_4 V_37 , struct V_38 * V_39 ,
struct V_38 * V_40 , T_2 V_41 )
{
struct V_24 * V_25 ;
struct V_42 V_43 ;
unsigned int V_44 ;
V_43 . V_28 = V_28 ;
V_43 . V_37 = V_37 ;
V_43 . V_39 = V_39 ;
V_43 . V_40 = V_40 ;
V_43 . V_41 = V_41 ;
F_19 ( & V_31 . V_45 ) ;
V_44 = F_12 ( V_28 , V_39 , V_40 , V_31 . V_32 ) ;
V_25 = F_20 ( & V_1 -> V_11 . V_12 , & V_31 , & V_43 , V_44 ) ;
F_21 () ;
if ( F_22 ( V_25 ) ) {
F_23 ( V_25 , F_24 () ) ;
return NULL ;
}
return F_11 ( V_25 , struct V_26 , V_25 ) ;
}
static int F_25 ( struct V_26 * V_36 , struct V_33 * V_34 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_33 * V_49 , * V_50 ;
unsigned int V_51 ;
int V_52 , V_53 ;
T_2 V_41 ;
if ( V_36 -> V_25 . V_54 & V_55 ) {
F_26 ( L_2 ) ;
goto V_56;
}
V_51 = F_27 ( F_28 ( V_34 ) -> V_51 ) ;
V_52 = F_27 ( V_47 -> V_57 ) & ~ 0x7 ;
V_53 = V_52 + ( V_51 -
( ( T_2 * ) ( V_47 + 1 ) - ( T_2 * ) ( F_28 ( V_34 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_53 > V_58 ) {
F_26 ( L_3 ) ;
return - 1 ;
}
V_41 = F_8 ( F_28 ( V_34 ) ) ;
if ( V_34 -> V_59 == V_60 ) {
const unsigned char * V_61 = F_29 ( V_34 ) ;
V_34 -> V_62 = F_30 ( V_34 -> V_62 ,
F_31 ( V_61 , ( T_2 * ) ( V_47 + 1 ) - V_61 ,
0 ) ) ;
}
if ( ! ( V_47 -> V_57 & F_32 ( V_63 ) ) ) {
if ( V_53 < V_36 -> V_25 . V_64 ||
( ( V_36 -> V_25 . V_54 & V_65 ) && V_53 != V_36 -> V_25 . V_64 ) ) {
F_26 ( L_4 ) ;
goto V_56;
}
V_36 -> V_25 . V_54 |= V_65 ;
V_36 -> V_25 . V_64 = V_53 ;
} else {
if ( V_53 & 0x7 ) {
F_26 ( L_5 ) ;
return - 1 ;
}
if ( V_53 > V_36 -> V_25 . V_64 ) {
if ( V_36 -> V_25 . V_54 & V_65 ) {
F_26 ( L_6 ) ;
goto V_56;
}
V_36 -> V_25 . V_64 = V_53 ;
}
}
if ( V_53 == V_52 )
goto V_56;
if ( ! F_33 ( V_34 , ( T_2 * ) ( V_47 + 1 ) - V_34 -> V_10 ) ) {
F_26 ( L_7 ) ;
goto V_56;
}
if ( F_34 ( V_34 , V_53 - V_52 ) ) {
F_26 ( L_8 ) ;
goto V_56;
}
V_49 = V_36 -> V_25 . V_66 ;
if ( ! V_49 || F_14 ( V_49 ) -> V_52 < V_52 ) {
V_50 = NULL ;
goto V_67;
}
V_49 = NULL ;
for ( V_50 = V_36 -> V_25 . V_68 ; V_50 != NULL ; V_50 = V_50 -> V_50 ) {
if ( F_14 ( V_50 ) -> V_52 >= V_52 )
break;
V_49 = V_50 ;
}
V_67:
if ( V_49 &&
( F_14 ( V_49 ) -> V_52 + V_49 -> V_64 ) > V_52 )
goto V_69;
if ( V_50 && F_14 ( V_50 ) -> V_52 < V_53 )
goto V_69;
F_14 ( V_34 ) -> V_52 = V_52 ;
V_34 -> V_50 = V_50 ;
if ( ! V_50 )
V_36 -> V_25 . V_66 = V_34 ;
if ( V_49 )
V_49 -> V_50 = V_34 ;
else
V_36 -> V_25 . V_68 = V_34 ;
if ( V_34 -> V_70 ) {
V_36 -> V_71 = V_34 -> V_70 -> V_72 ;
V_34 -> V_70 = NULL ;
}
V_36 -> V_25 . V_73 = V_34 -> V_74 ;
V_36 -> V_25 . V_75 += V_34 -> V_64 ;
V_36 -> V_41 |= V_41 ;
if ( V_51 > V_36 -> V_25 . V_76 )
V_36 -> V_25 . V_76 = V_51 ;
F_35 ( & V_36 -> V_25 , V_34 -> V_77 ) ;
if ( V_52 == 0 ) {
V_36 -> V_78 = V_48 ;
V_36 -> V_25 . V_54 |= V_79 ;
}
F_36 ( & V_36 -> V_25 ) ;
return 0 ;
V_69:
F_37 ( & V_36 -> V_25 , & V_31 ) ;
V_56:
return - 1 ;
}
static struct V_33 *
F_38 ( struct V_26 * V_36 , struct V_80 * V_70 )
{
struct V_33 * V_81 , * V_82 , * V_83 = V_36 -> V_25 . V_68 ;
int V_51 ;
T_2 V_41 ;
F_37 ( & V_36 -> V_25 , & V_31 ) ;
F_39 ( V_83 == NULL ) ;
F_39 ( F_14 ( V_83 ) -> V_52 != 0 ) ;
V_41 = V_84 [ V_36 -> V_41 ] ;
if ( F_40 ( V_41 == 0xff ) )
goto V_85;
V_51 = ( ( V_83 -> V_10 - F_29 ( V_83 ) ) -
sizeof( struct V_21 ) + V_36 -> V_25 . V_64 -
sizeof( struct V_46 ) ) ;
if ( V_51 > V_58 ) {
F_26 ( L_9 ) ;
goto V_86;
}
if ( F_41 ( V_83 , V_87 ) ) {
F_26 ( L_10 ) ;
goto V_88;
}
if ( F_42 ( V_83 ) ) {
struct V_33 * V_89 ;
int V_90 , V_91 = 0 ;
V_89 = F_43 ( 0 , V_87 ) ;
if ( V_89 == NULL )
goto V_88;
V_89 -> V_50 = V_83 -> V_50 ;
V_83 -> V_50 = V_89 ;
F_44 ( V_89 ) -> V_92 = F_44 ( V_83 ) -> V_92 ;
F_45 ( V_83 ) ;
for ( V_90 = 0 ; V_90 < F_44 ( V_83 ) -> V_93 ; V_90 ++ )
V_91 += F_46 ( & F_44 ( V_83 ) -> V_12 [ V_90 ] ) ;
V_89 -> V_64 = V_89 -> V_94 = V_83 -> V_94 - V_91 ;
V_83 -> V_94 -= V_89 -> V_64 ;
V_83 -> V_64 -= V_89 -> V_64 ;
V_89 -> V_62 = 0 ;
V_89 -> V_59 = V_83 -> V_59 ;
F_14 ( V_89 ) -> V_35 = NULL ;
F_35 ( & V_36 -> V_25 , V_89 -> V_77 ) ;
}
F_29 ( V_83 ) [ V_36 -> V_78 ] = F_47 ( V_83 ) [ 0 ] ;
memmove ( V_83 -> V_83 + sizeof( struct V_46 ) , V_83 -> V_83 ,
( V_83 -> V_10 - V_83 -> V_83 ) - sizeof( struct V_46 ) ) ;
V_83 -> V_95 += sizeof( struct V_46 ) ;
V_83 -> V_96 += sizeof( struct V_46 ) ;
F_44 ( V_83 ) -> V_92 = V_83 -> V_50 ;
F_48 ( V_83 ) ;
F_49 ( V_83 , V_83 -> V_10 - F_29 ( V_83 ) ) ;
for ( V_81 = V_83 -> V_50 ; V_81 ; V_81 = V_81 -> V_50 ) {
V_83 -> V_94 += V_81 -> V_64 ;
V_83 -> V_64 += V_81 -> V_64 ;
if ( V_83 -> V_59 != V_81 -> V_59 )
V_83 -> V_59 = V_97 ;
else if ( V_83 -> V_59 == V_60 )
V_83 -> V_62 = F_50 ( V_83 -> V_62 , V_81 -> V_62 ) ;
V_83 -> V_77 += V_81 -> V_77 ;
}
F_51 ( & V_36 -> V_25 , V_83 -> V_77 ) ;
V_83 -> V_98 = 1 ;
V_83 -> V_50 = NULL ;
V_83 -> V_70 = V_70 ;
V_83 -> V_74 = V_36 -> V_25 . V_73 ;
F_28 ( V_83 ) -> V_51 = F_32 ( V_51 ) ;
F_52 ( F_28 ( V_83 ) , 0xff , V_41 ) ;
F_53 ( V_83 ) -> V_99 = sizeof( struct V_21 ) + V_36 -> V_25 . V_76 ;
if ( V_83 -> V_59 == V_60 )
V_83 -> V_62 = F_31 ( F_29 ( V_83 ) ,
F_54 ( V_83 ) ,
V_83 -> V_62 ) ;
V_36 -> V_25 . V_68 = NULL ;
V_36 -> V_25 . V_66 = NULL ;
V_81 = F_44 ( V_83 ) -> V_92 ;
if ( V_81 && F_14 ( V_81 ) -> V_35 == NULL )
V_81 = V_81 -> V_50 ;
V_82 = F_14 ( V_83 ) -> V_35 ;
for (; V_81 ; V_81 = V_81 -> V_50 ) {
struct V_33 * V_35 = F_14 ( V_81 ) -> V_35 ;
V_82 -> V_50 = V_35 ;
V_82 = V_35 ;
F_14 ( V_81 ) -> V_35 = NULL ;
}
return V_83 ;
V_86:
F_55 ( L_11 ,
V_51 ) ;
goto V_85;
V_88:
F_55 ( L_12 ) ;
V_85:
return NULL ;
}
static int
F_56 ( struct V_33 * V_34 , T_2 * V_100 , int * V_101 , int * V_102 )
{
T_2 V_103 = F_28 ( V_34 ) -> V_103 ;
const int V_104 = F_57 ( V_34 ) ;
T_2 V_105 = V_104 + F_58 ( struct V_21 , V_103 ) ;
int V_106 = V_104 + sizeof( struct V_21 ) ;
int V_64 = V_34 -> V_64 - V_106 ;
T_2 V_107 = V_108 ;
while ( V_103 != V_109 ) {
struct V_110 V_5 ;
int V_111 ;
if ( ! F_59 ( V_103 ) ) {
return - 1 ;
}
if ( V_103 == V_112 ) {
F_26 ( L_13 ) ;
return - 1 ;
}
if ( V_64 < ( int ) sizeof( struct V_110 ) ) {
F_26 ( L_14 ) ;
return - 1 ;
}
if ( F_60 ( V_34 , V_106 , & V_5 , sizeof( V_5 ) ) )
F_61 () ;
if ( V_103 == V_113 )
V_111 = ( V_5 . V_111 + 2 ) << 2 ;
else
V_111 = F_62 ( & V_5 ) ;
V_107 = V_103 ;
V_105 = V_106 ;
V_103 = V_5 . V_103 ;
V_64 -= V_111 ;
V_106 += V_111 ;
}
if ( V_64 < 0 )
return - 1 ;
* V_100 = V_107 ;
* V_101 = V_105 ;
* V_102 = V_106 ;
return 0 ;
}
struct V_33 * F_63 ( struct V_33 * V_34 , T_4 V_37 )
{
struct V_33 * V_89 ;
struct V_80 * V_70 = V_34 -> V_70 ;
struct V_1 * V_1 = F_64 ( V_34 ) ? F_65 ( F_64 ( V_34 ) -> V_70 )
: F_65 ( V_34 -> V_70 ) ;
struct V_46 * V_47 ;
struct V_26 * V_36 ;
struct V_21 * V_5 ;
int V_102 , V_48 ;
T_2 V_107 ;
struct V_33 * V_114 = NULL ;
if ( F_28 ( V_34 ) -> V_51 == 0 ) {
F_26 ( L_15 ) ;
return V_34 ;
}
if ( F_56 ( V_34 , & V_107 , & V_48 , & V_102 ) < 0 )
return V_34 ;
V_89 = F_66 ( V_34 , V_87 ) ;
if ( V_89 == NULL ) {
F_26 ( L_16 ) ;
return V_34 ;
}
F_14 ( V_89 ) -> V_35 = V_34 ;
if ( ! F_67 ( V_89 , V_102 + sizeof( * V_47 ) ) ) {
F_26 ( L_17 ) ;
goto V_115;
}
F_68 ( V_89 , V_102 ) ;
V_5 = F_28 ( V_89 ) ;
V_47 = (struct V_46 * ) F_47 ( V_89 ) ;
F_69 () ;
F_70 ( & V_1 -> V_11 . V_12 , & V_31 , false ) ;
F_21 () ;
V_36 = F_18 ( V_1 , V_47 -> V_116 , V_37 , & V_5 -> V_29 , & V_5 -> V_30 ,
F_8 ( V_5 ) ) ;
if ( V_36 == NULL ) {
F_26 ( L_18 ) ;
goto V_115;
}
F_71 ( & V_36 -> V_25 . V_45 ) ;
if ( F_25 ( V_36 , V_89 , V_47 , V_48 ) < 0 ) {
F_72 ( & V_36 -> V_25 . V_45 ) ;
F_26 ( L_19 ) ;
F_73 ( & V_36 -> V_25 , & V_31 ) ;
goto V_115;
}
if ( V_36 -> V_25 . V_54 == ( V_79 | V_65 ) &&
V_36 -> V_25 . V_75 == V_36 -> V_25 . V_64 ) {
V_114 = F_38 ( V_36 , V_70 ) ;
if ( V_114 == NULL )
F_26 ( L_20 ) ;
}
F_72 ( & V_36 -> V_25 . V_45 ) ;
F_73 ( & V_36 -> V_25 , & V_31 ) ;
return V_114 ;
V_115:
F_15 ( V_89 ) ;
return V_34 ;
}
void F_74 ( unsigned int V_117 , struct V_33 * V_34 ,
struct V_80 * V_118 , struct V_80 * V_119 ,
int (* F_75)( struct V_33 * ) )
{
struct V_33 * V_120 , * V_121 ;
unsigned int V_122 = 0 ;
for ( V_120 = F_14 ( V_34 ) -> V_35 ; V_120 ; ) {
F_76 ( V_120 -> V_123 ) ;
F_77 ( V_34 ) ;
V_120 -> V_123 = V_34 ;
V_121 = V_120 -> V_50 ;
V_120 -> V_50 = NULL ;
if ( V_122 != - V_124 )
V_122 = F_78 ( V_125 , V_117 , V_120 ,
V_118 , V_119 , F_75 ,
V_126 + 1 ) ;
else
F_15 ( V_120 ) ;
V_120 = V_121 ;
}
F_76 ( V_34 ) ;
}
static int F_79 ( struct V_1 * V_1 )
{
V_1 -> V_11 . V_12 . V_15 = V_127 ;
V_1 -> V_11 . V_12 . V_14 = V_128 ;
V_1 -> V_11 . V_12 . V_13 = V_129 ;
F_80 ( & V_1 -> V_11 . V_12 ) ;
return F_1 ( V_1 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_82 ( & V_1 -> V_11 . V_12 , & V_31 ) ;
}
int F_83 ( void )
{
int V_122 = 0 ;
V_31 . V_130 = F_10 ;
V_31 . V_131 = V_132 ;
V_31 . V_133 = NULL ;
V_31 . V_134 = F_13 ;
V_31 . V_135 = sizeof( struct V_26 ) ;
V_31 . V_136 = V_137 ;
V_31 . V_138 = F_16 ;
V_31 . V_139 = 10 * 60 * V_140 ;
F_84 ( & V_31 ) ;
V_122 = F_85 ( & V_141 ) ;
if ( V_122 )
F_86 ( & V_31 ) ;
return V_122 ;
}
void F_87 ( void )
{
F_88 ( & V_141 ) ;
F_86 ( & V_31 ) ;
}
