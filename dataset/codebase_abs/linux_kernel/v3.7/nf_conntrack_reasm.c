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
V_32 -> V_69 = NULL ;
V_34 -> V_23 . V_70 = V_32 -> V_71 ;
V_34 -> V_23 . V_72 += V_32 -> V_63 ;
if ( V_49 > V_34 -> V_23 . V_73 )
V_34 -> V_23 . V_73 = V_49 ;
F_30 ( V_32 -> V_74 , & V_34 -> V_23 . V_1 -> V_75 ) ;
if ( V_50 == 0 ) {
V_34 -> V_76 = V_46 ;
V_34 -> V_23 . V_52 |= V_77 ;
}
F_31 ( & V_29 . V_42 ) ;
F_32 ( & V_34 -> V_23 . V_78 , & V_34 -> V_23 . V_1 -> V_78 ) ;
F_33 ( & V_29 . V_42 ) ;
return 0 ;
V_68:
F_34 ( & V_34 -> V_23 , & V_29 ) ;
V_54:
return - 1 ;
}
static struct V_31 *
F_35 ( struct V_24 * V_34 , struct V_79 * V_69 )
{
struct V_31 * V_80 , * V_81 , * V_82 = V_34 -> V_23 . V_67 ;
int V_49 ;
F_34 ( & V_34 -> V_23 , & V_29 ) ;
F_36 ( V_82 == NULL ) ;
F_36 ( F_12 ( V_82 ) -> V_50 != 0 ) ;
V_49 = ( ( V_82 -> V_10 - F_24 ( V_82 ) ) -
sizeof( struct V_83 ) + V_34 -> V_23 . V_63 -
sizeof( struct V_44 ) ) ;
if ( V_49 > V_57 ) {
F_21 ( L_9 ) ;
goto V_84;
}
if ( F_37 ( V_82 ) && F_38 ( V_82 , 0 , 0 , V_85 ) ) {
F_21 ( L_10 ) ;
goto V_86;
}
if ( F_39 ( V_82 ) ) {
struct V_31 * V_87 ;
int V_88 , V_89 = 0 ;
V_87 = F_40 ( 0 , V_85 ) ;
if ( V_87 == NULL )
goto V_86;
V_87 -> V_48 = V_82 -> V_48 ;
V_82 -> V_48 = V_87 ;
F_41 ( V_87 ) -> V_90 = F_41 ( V_82 ) -> V_90 ;
F_42 ( V_82 ) ;
for ( V_88 = 0 ; V_88 < F_41 ( V_82 ) -> V_91 ; V_88 ++ )
V_89 += F_43 ( & F_41 ( V_82 ) -> V_12 [ V_88 ] ) ;
V_87 -> V_63 = V_87 -> V_92 = V_82 -> V_92 - V_89 ;
V_82 -> V_92 -= V_87 -> V_63 ;
V_82 -> V_63 -= V_87 -> V_63 ;
V_87 -> V_61 = 0 ;
V_87 -> V_58 = V_82 -> V_58 ;
F_12 ( V_87 ) -> V_33 = NULL ;
F_30 ( V_87 -> V_74 , & V_34 -> V_23 . V_1 -> V_75 ) ;
}
F_24 ( V_82 ) [ V_34 -> V_76 ] = F_44 ( V_82 ) [ 0 ] ;
memmove ( V_82 -> V_82 + sizeof( struct V_44 ) , V_82 -> V_82 ,
( V_82 -> V_10 - V_82 -> V_82 ) - sizeof( struct V_44 ) ) ;
V_82 -> V_93 += sizeof( struct V_44 ) ;
V_82 -> V_94 += sizeof( struct V_44 ) ;
F_41 ( V_82 ) -> V_90 = V_82 -> V_48 ;
F_45 ( V_82 ) ;
F_46 ( V_82 , V_82 -> V_10 - F_24 ( V_82 ) ) ;
for ( V_80 = V_82 -> V_48 ; V_80 ; V_80 = V_80 -> V_48 ) {
V_82 -> V_92 += V_80 -> V_63 ;
V_82 -> V_63 += V_80 -> V_63 ;
if ( V_82 -> V_58 != V_80 -> V_58 )
V_82 -> V_58 = V_95 ;
else if ( V_82 -> V_58 == V_59 )
V_82 -> V_61 = F_47 ( V_82 -> V_61 , V_80 -> V_61 ) ;
V_82 -> V_74 += V_80 -> V_74 ;
}
F_48 ( V_82 -> V_74 , & V_34 -> V_23 . V_1 -> V_75 ) ;
V_82 -> V_96 = 1 ;
V_82 -> V_48 = NULL ;
V_82 -> V_69 = V_69 ;
V_82 -> V_71 = V_34 -> V_23 . V_70 ;
F_23 ( V_82 ) -> V_49 = F_27 ( V_49 ) ;
F_49 ( V_82 ) -> V_97 = sizeof( struct V_83 ) + V_34 -> V_23 . V_73 ;
if ( V_82 -> V_58 == V_59 )
V_82 -> V_61 = F_26 ( F_24 ( V_82 ) ,
F_50 ( V_82 ) ,
V_82 -> V_61 ) ;
V_34 -> V_23 . V_67 = NULL ;
V_34 -> V_23 . V_65 = NULL ;
V_80 = F_41 ( V_82 ) -> V_90 ;
if ( V_80 && F_12 ( V_80 ) -> V_33 == NULL )
V_80 = V_80 -> V_48 ;
V_81 = F_12 ( V_82 ) -> V_33 ;
for (; V_80 ; V_80 = V_80 -> V_48 ) {
struct V_31 * V_33 = F_12 ( V_80 ) -> V_33 ;
V_81 -> V_48 = V_33 ;
V_81 = V_33 ;
F_12 ( V_80 ) -> V_33 = NULL ;
}
return V_82 ;
V_84:
F_51 ( L_11 ,
V_49 ) ;
goto V_98;
V_86:
F_51 ( L_12 ) ;
V_98:
return NULL ;
}
static int
F_52 ( struct V_31 * V_32 , V_56 * V_99 , int * V_100 , int * V_101 )
{
V_56 V_102 = F_23 ( V_32 ) -> V_102 ;
const int V_103 = F_53 ( V_32 ) ;
V_56 V_104 = V_103 + F_54 ( struct V_83 , V_102 ) ;
int V_105 = V_103 + sizeof( struct V_83 ) ;
int V_63 = V_32 -> V_63 - V_105 ;
V_56 V_106 = V_107 ;
while ( V_102 != V_108 ) {
struct V_109 V_5 ;
int V_110 ;
if ( ! F_55 ( V_102 ) ) {
return - 1 ;
}
if ( V_102 == V_111 ) {
F_21 ( L_13 ) ;
return - 1 ;
}
if ( V_63 < ( int ) sizeof( struct V_109 ) ) {
F_21 ( L_14 ) ;
return - 1 ;
}
if ( F_56 ( V_32 , V_105 , & V_5 , sizeof( V_5 ) ) )
F_57 () ;
if ( V_102 == V_112 )
V_110 = ( V_5 . V_110 + 2 ) << 2 ;
else
V_110 = F_58 ( & V_5 ) ;
V_106 = V_102 ;
V_104 = V_105 ;
V_102 = V_5 . V_102 ;
V_63 -= V_110 ;
V_105 += V_110 ;
}
if ( V_63 < 0 )
return - 1 ;
* V_99 = V_106 ;
* V_100 = V_104 ;
* V_101 = V_105 ;
return 0 ;
}
struct V_31 * F_59 ( struct V_31 * V_32 , T_3 V_35 )
{
struct V_31 * V_87 ;
struct V_79 * V_69 = V_32 -> V_69 ;
struct V_1 * V_1 = F_60 ( V_32 ) ? F_61 ( F_60 ( V_32 ) -> V_69 )
: F_61 ( V_32 -> V_69 ) ;
struct V_44 * V_45 ;
struct V_24 * V_34 ;
struct V_83 * V_5 ;
int V_101 , V_46 ;
V_56 V_106 ;
struct V_31 * V_113 = NULL ;
if ( F_23 ( V_32 ) -> V_49 == 0 ) {
F_21 ( L_15 ) ;
return V_32 ;
}
if ( F_52 ( V_32 , & V_106 , & V_46 , & V_101 ) < 0 )
return V_32 ;
V_87 = F_62 ( V_32 , V_85 ) ;
if ( V_87 == NULL ) {
F_21 ( L_16 ) ;
return V_32 ;
}
F_12 ( V_87 ) -> V_33 = V_32 ;
if ( ! F_63 ( V_87 , V_101 + sizeof( * V_45 ) ) ) {
F_21 ( L_17 ) ;
goto V_114;
}
F_64 ( V_87 , V_101 ) ;
V_5 = F_23 ( V_87 ) ;
V_45 = (struct V_44 * ) F_44 ( V_87 ) ;
F_65 () ;
F_66 ( & V_1 -> V_17 . V_12 , & V_29 , false ) ;
F_19 () ;
V_34 = F_16 ( V_1 , V_45 -> V_115 , V_35 , & V_5 -> V_27 , & V_5 -> V_28 ) ;
if ( V_34 == NULL ) {
F_21 ( L_18 ) ;
goto V_114;
}
F_67 ( & V_34 -> V_23 . V_42 ) ;
if ( F_20 ( V_34 , V_87 , V_45 , V_46 ) < 0 ) {
F_68 ( & V_34 -> V_23 . V_42 ) ;
F_21 ( L_19 ) ;
F_69 ( & V_34 -> V_23 , & V_29 ) ;
goto V_114;
}
if ( V_34 -> V_23 . V_52 == ( V_77 | V_64 ) &&
V_34 -> V_23 . V_72 == V_34 -> V_23 . V_63 ) {
V_113 = F_35 ( V_34 , V_69 ) ;
if ( V_113 == NULL )
F_21 ( L_20 ) ;
}
F_68 ( & V_34 -> V_23 . V_42 ) ;
F_69 ( & V_34 -> V_23 , & V_29 ) ;
return V_113 ;
V_114:
F_13 ( V_87 ) ;
return V_32 ;
}
void F_70 ( unsigned int V_116 , struct V_31 * V_32 ,
struct V_79 * V_117 , struct V_79 * V_118 ,
int (* F_71)( struct V_31 * ) )
{
struct V_31 * V_119 , * V_120 ;
unsigned int V_121 = 0 ;
for ( V_119 = F_12 ( V_32 ) -> V_33 ; V_119 ; ) {
F_72 ( V_119 -> V_122 ) ;
F_73 ( V_32 ) ;
V_119 -> V_122 = V_32 ;
V_120 = V_119 -> V_48 ;
V_119 -> V_48 = NULL ;
if ( V_121 != - V_123 )
V_121 = F_74 ( V_124 , V_116 , V_119 ,
V_117 , V_118 , F_71 ,
V_125 + 1 ) ;
else
F_13 ( V_119 ) ;
V_119 = V_120 ;
}
F_72 ( V_32 ) ;
}
static int F_75 ( struct V_1 * V_1 )
{
V_1 -> V_17 . V_12 . V_13 = V_126 ;
V_1 -> V_17 . V_12 . V_14 = V_127 ;
V_1 -> V_17 . V_12 . V_15 = V_128 ;
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
int V_121 = 0 ;
V_29 . V_129 = F_8 ;
V_29 . V_130 = V_131 ;
V_29 . V_132 = NULL ;
V_29 . V_133 = F_11 ;
V_29 . V_134 = sizeof( struct V_24 ) ;
V_29 . V_135 = V_136 ;
V_29 . V_137 = F_14 ;
V_29 . V_138 = 10 * 60 * V_139 ;
F_80 ( & V_29 ) ;
V_121 = F_81 ( & V_140 ) ;
if ( V_121 )
F_82 ( & V_29 ) ;
return V_121 ;
}
void F_83 ( void )
{
F_84 ( & V_140 ) ;
F_82 ( & V_29 ) ;
}
