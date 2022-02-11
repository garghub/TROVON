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
static unsigned int F_8 ( struct V_21 * V_22 )
{
const struct V_23 * V_24 ;
V_24 = F_9 ( V_22 , struct V_23 , V_22 ) ;
return F_10 ( V_24 -> V_25 , & V_24 -> V_26 , & V_24 -> V_27 , V_28 . V_29 ) ;
}
static void F_11 ( struct V_30 * V_31 )
{
if ( F_12 ( V_31 ) -> V_32 )
F_13 ( F_12 ( V_31 ) -> V_32 ) ;
}
static void F_14 ( unsigned long V_10 )
{
struct V_23 * V_33 ;
struct V_1 * V_1 ;
V_33 = F_9 ( (struct V_21 * ) V_10 , struct V_23 , V_22 ) ;
V_1 = F_9 ( V_33 -> V_22 . V_1 , struct V_1 , V_11 . V_12 ) ;
F_15 ( V_1 , V_33 , & V_28 ) ;
}
static inline struct V_23 * F_16 ( struct V_1 * V_1 , T_2 V_25 ,
T_3 V_34 , struct V_35 * V_36 ,
struct V_35 * V_37 )
{
struct V_21 * V_22 ;
struct V_38 V_39 ;
unsigned int V_40 ;
V_39 . V_25 = V_25 ;
V_39 . V_34 = V_34 ;
V_39 . V_36 = V_36 ;
V_39 . V_37 = V_37 ;
F_17 ( & V_28 . V_41 ) ;
V_40 = F_10 ( V_25 , V_36 , V_37 , V_28 . V_29 ) ;
V_22 = F_18 ( & V_1 -> V_11 . V_12 , & V_28 , & V_39 , V_40 ) ;
F_19 () ;
if ( F_20 ( V_22 ) ) {
F_21 ( V_22 , F_22 () ) ;
return NULL ;
}
return F_9 ( V_22 , struct V_23 , V_22 ) ;
}
static int F_23 ( struct V_23 * V_33 , struct V_30 * V_31 ,
const struct V_42 * V_43 , int V_44 )
{
struct V_30 * V_45 , * V_46 ;
unsigned int V_47 ;
int V_48 , V_49 ;
if ( V_33 -> V_22 . V_50 & V_51 ) {
F_24 ( L_2 ) ;
goto V_52;
}
V_47 = F_25 ( F_26 ( V_31 ) -> V_47 ) ;
V_48 = F_25 ( V_43 -> V_53 ) & ~ 0x7 ;
V_49 = V_48 + ( V_47 -
( ( V_54 * ) ( V_43 + 1 ) - ( V_54 * ) ( F_26 ( V_31 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_49 > V_55 ) {
F_24 ( L_3 ) ;
return - 1 ;
}
if ( V_31 -> V_56 == V_57 ) {
const unsigned char * V_58 = F_27 ( V_31 ) ;
V_31 -> V_59 = F_28 ( V_31 -> V_59 ,
F_29 ( V_58 , ( V_54 * ) ( V_43 + 1 ) - V_58 ,
0 ) ) ;
}
if ( ! ( V_43 -> V_53 & F_30 ( V_60 ) ) ) {
if ( V_49 < V_33 -> V_22 . V_61 ||
( ( V_33 -> V_22 . V_50 & V_62 ) && V_49 != V_33 -> V_22 . V_61 ) ) {
F_24 ( L_4 ) ;
goto V_52;
}
V_33 -> V_22 . V_50 |= V_62 ;
V_33 -> V_22 . V_61 = V_49 ;
} else {
if ( V_49 & 0x7 ) {
F_24 ( L_5 ) ;
return - 1 ;
}
if ( V_49 > V_33 -> V_22 . V_61 ) {
if ( V_33 -> V_22 . V_50 & V_62 ) {
F_24 ( L_6 ) ;
goto V_52;
}
V_33 -> V_22 . V_61 = V_49 ;
}
}
if ( V_49 == V_48 )
goto V_52;
if ( ! F_31 ( V_31 , ( V_54 * ) ( V_43 + 1 ) - V_31 -> V_10 ) ) {
F_24 ( L_7 ) ;
goto V_52;
}
if ( F_32 ( V_31 , V_49 - V_48 ) ) {
F_24 ( L_8 ) ;
goto V_52;
}
V_45 = V_33 -> V_22 . V_63 ;
if ( ! V_45 || F_12 ( V_45 ) -> V_48 < V_48 ) {
V_46 = NULL ;
goto V_64;
}
V_45 = NULL ;
for ( V_46 = V_33 -> V_22 . V_65 ; V_46 != NULL ; V_46 = V_46 -> V_46 ) {
if ( F_12 ( V_46 ) -> V_48 >= V_48 )
break;
V_45 = V_46 ;
}
V_64:
if ( V_45 &&
( F_12 ( V_45 ) -> V_48 + V_45 -> V_61 ) > V_48 )
goto V_66;
if ( V_46 && F_12 ( V_46 ) -> V_48 < V_49 )
goto V_66;
F_12 ( V_31 ) -> V_48 = V_48 ;
V_31 -> V_46 = V_46 ;
if ( ! V_46 )
V_33 -> V_22 . V_63 = V_31 ;
if ( V_45 )
V_45 -> V_46 = V_31 ;
else
V_33 -> V_22 . V_65 = V_31 ;
if ( V_31 -> V_67 ) {
V_33 -> V_68 = V_31 -> V_67 -> V_69 ;
V_31 -> V_67 = NULL ;
}
V_33 -> V_22 . V_70 = V_31 -> V_71 ;
V_33 -> V_22 . V_72 += V_31 -> V_61 ;
if ( V_47 > V_33 -> V_22 . V_73 )
V_33 -> V_22 . V_73 = V_47 ;
F_33 ( & V_33 -> V_22 , V_31 -> V_74 ) ;
if ( V_48 == 0 ) {
V_33 -> V_75 = V_44 ;
V_33 -> V_22 . V_50 |= V_76 ;
}
F_34 ( & V_33 -> V_22 ) ;
return 0 ;
V_66:
F_35 ( & V_33 -> V_22 , & V_28 ) ;
V_52:
return - 1 ;
}
static struct V_30 *
F_36 ( struct V_23 * V_33 , struct V_77 * V_67 )
{
struct V_30 * V_78 , * V_79 , * V_80 = V_33 -> V_22 . V_65 ;
int V_47 ;
F_35 ( & V_33 -> V_22 , & V_28 ) ;
F_37 ( V_80 == NULL ) ;
F_37 ( F_12 ( V_80 ) -> V_48 != 0 ) ;
V_47 = ( ( V_80 -> V_10 - F_27 ( V_80 ) ) -
sizeof( struct V_81 ) + V_33 -> V_22 . V_61 -
sizeof( struct V_42 ) ) ;
if ( V_47 > V_55 ) {
F_24 ( L_9 ) ;
goto V_82;
}
if ( F_38 ( V_80 , V_83 ) ) {
F_24 ( L_10 ) ;
goto V_84;
}
if ( F_39 ( V_80 ) ) {
struct V_30 * V_85 ;
int V_86 , V_87 = 0 ;
V_85 = F_40 ( 0 , V_83 ) ;
if ( V_85 == NULL )
goto V_84;
V_85 -> V_46 = V_80 -> V_46 ;
V_80 -> V_46 = V_85 ;
F_41 ( V_85 ) -> V_88 = F_41 ( V_80 ) -> V_88 ;
F_42 ( V_80 ) ;
for ( V_86 = 0 ; V_86 < F_41 ( V_80 ) -> V_89 ; V_86 ++ )
V_87 += F_43 ( & F_41 ( V_80 ) -> V_12 [ V_86 ] ) ;
V_85 -> V_61 = V_85 -> V_90 = V_80 -> V_90 - V_87 ;
V_80 -> V_90 -= V_85 -> V_61 ;
V_80 -> V_61 -= V_85 -> V_61 ;
V_85 -> V_59 = 0 ;
V_85 -> V_56 = V_80 -> V_56 ;
F_12 ( V_85 ) -> V_32 = NULL ;
F_33 ( & V_33 -> V_22 , V_85 -> V_74 ) ;
}
F_27 ( V_80 ) [ V_33 -> V_75 ] = F_44 ( V_80 ) [ 0 ] ;
memmove ( V_80 -> V_80 + sizeof( struct V_42 ) , V_80 -> V_80 ,
( V_80 -> V_10 - V_80 -> V_80 ) - sizeof( struct V_42 ) ) ;
V_80 -> V_91 += sizeof( struct V_42 ) ;
V_80 -> V_92 += sizeof( struct V_42 ) ;
F_41 ( V_80 ) -> V_88 = V_80 -> V_46 ;
F_45 ( V_80 ) ;
F_46 ( V_80 , V_80 -> V_10 - F_27 ( V_80 ) ) ;
for ( V_78 = V_80 -> V_46 ; V_78 ; V_78 = V_78 -> V_46 ) {
V_80 -> V_90 += V_78 -> V_61 ;
V_80 -> V_61 += V_78 -> V_61 ;
if ( V_80 -> V_56 != V_78 -> V_56 )
V_80 -> V_56 = V_93 ;
else if ( V_80 -> V_56 == V_57 )
V_80 -> V_59 = F_47 ( V_80 -> V_59 , V_78 -> V_59 ) ;
V_80 -> V_74 += V_78 -> V_74 ;
}
F_48 ( & V_33 -> V_22 , V_80 -> V_74 ) ;
V_80 -> V_94 = 1 ;
V_80 -> V_46 = NULL ;
V_80 -> V_67 = V_67 ;
V_80 -> V_71 = V_33 -> V_22 . V_70 ;
F_26 ( V_80 ) -> V_47 = F_30 ( V_47 ) ;
F_49 ( V_80 ) -> V_95 = sizeof( struct V_81 ) + V_33 -> V_22 . V_73 ;
if ( V_80 -> V_56 == V_57 )
V_80 -> V_59 = F_29 ( F_27 ( V_80 ) ,
F_50 ( V_80 ) ,
V_80 -> V_59 ) ;
V_33 -> V_22 . V_65 = NULL ;
V_33 -> V_22 . V_63 = NULL ;
V_78 = F_41 ( V_80 ) -> V_88 ;
if ( V_78 && F_12 ( V_78 ) -> V_32 == NULL )
V_78 = V_78 -> V_46 ;
V_79 = F_12 ( V_80 ) -> V_32 ;
for (; V_78 ; V_78 = V_78 -> V_46 ) {
struct V_30 * V_32 = F_12 ( V_78 ) -> V_32 ;
V_79 -> V_46 = V_32 ;
V_79 = V_32 ;
F_12 ( V_78 ) -> V_32 = NULL ;
}
return V_80 ;
V_82:
F_51 ( L_11 ,
V_47 ) ;
goto V_96;
V_84:
F_51 ( L_12 ) ;
V_96:
return NULL ;
}
static int
F_52 ( struct V_30 * V_31 , V_54 * V_97 , int * V_98 , int * V_99 )
{
V_54 V_100 = F_26 ( V_31 ) -> V_100 ;
const int V_101 = F_53 ( V_31 ) ;
V_54 V_102 = V_101 + F_54 ( struct V_81 , V_100 ) ;
int V_103 = V_101 + sizeof( struct V_81 ) ;
int V_61 = V_31 -> V_61 - V_103 ;
V_54 V_104 = V_105 ;
while ( V_100 != V_106 ) {
struct V_107 V_5 ;
int V_108 ;
if ( ! F_55 ( V_100 ) ) {
return - 1 ;
}
if ( V_100 == V_109 ) {
F_24 ( L_13 ) ;
return - 1 ;
}
if ( V_61 < ( int ) sizeof( struct V_107 ) ) {
F_24 ( L_14 ) ;
return - 1 ;
}
if ( F_56 ( V_31 , V_103 , & V_5 , sizeof( V_5 ) ) )
F_57 () ;
if ( V_100 == V_110 )
V_108 = ( V_5 . V_108 + 2 ) << 2 ;
else
V_108 = F_58 ( & V_5 ) ;
V_104 = V_100 ;
V_102 = V_103 ;
V_100 = V_5 . V_100 ;
V_61 -= V_108 ;
V_103 += V_108 ;
}
if ( V_61 < 0 )
return - 1 ;
* V_97 = V_104 ;
* V_98 = V_102 ;
* V_99 = V_103 ;
return 0 ;
}
struct V_30 * F_59 ( struct V_30 * V_31 , T_3 V_34 )
{
struct V_30 * V_85 ;
struct V_77 * V_67 = V_31 -> V_67 ;
struct V_1 * V_1 = F_60 ( V_31 ) ? F_61 ( F_60 ( V_31 ) -> V_67 )
: F_61 ( V_31 -> V_67 ) ;
struct V_42 * V_43 ;
struct V_23 * V_33 ;
struct V_81 * V_5 ;
int V_99 , V_44 ;
V_54 V_104 ;
struct V_30 * V_111 = NULL ;
if ( F_26 ( V_31 ) -> V_47 == 0 ) {
F_24 ( L_15 ) ;
return V_31 ;
}
if ( F_52 ( V_31 , & V_104 , & V_44 , & V_99 ) < 0 )
return V_31 ;
V_85 = F_62 ( V_31 , V_83 ) ;
if ( V_85 == NULL ) {
F_24 ( L_16 ) ;
return V_31 ;
}
F_12 ( V_85 ) -> V_32 = V_31 ;
if ( ! F_63 ( V_85 , V_99 + sizeof( * V_43 ) ) ) {
F_24 ( L_17 ) ;
goto V_112;
}
F_64 ( V_85 , V_99 ) ;
V_5 = F_26 ( V_85 ) ;
V_43 = (struct V_42 * ) F_44 ( V_85 ) ;
F_65 () ;
F_66 ( & V_1 -> V_11 . V_12 , & V_28 , false ) ;
F_19 () ;
V_33 = F_16 ( V_1 , V_43 -> V_113 , V_34 , & V_5 -> V_26 , & V_5 -> V_27 ) ;
if ( V_33 == NULL ) {
F_24 ( L_18 ) ;
goto V_112;
}
F_67 ( & V_33 -> V_22 . V_41 ) ;
if ( F_23 ( V_33 , V_85 , V_43 , V_44 ) < 0 ) {
F_68 ( & V_33 -> V_22 . V_41 ) ;
F_24 ( L_19 ) ;
F_69 ( & V_33 -> V_22 , & V_28 ) ;
goto V_112;
}
if ( V_33 -> V_22 . V_50 == ( V_76 | V_62 ) &&
V_33 -> V_22 . V_72 == V_33 -> V_22 . V_61 ) {
V_111 = F_36 ( V_33 , V_67 ) ;
if ( V_111 == NULL )
F_24 ( L_20 ) ;
}
F_68 ( & V_33 -> V_22 . V_41 ) ;
F_69 ( & V_33 -> V_22 , & V_28 ) ;
return V_111 ;
V_112:
F_13 ( V_85 ) ;
return V_31 ;
}
void F_70 ( unsigned int V_114 , struct V_30 * V_31 ,
struct V_77 * V_115 , struct V_77 * V_116 ,
int (* F_71)( struct V_30 * ) )
{
struct V_30 * V_117 , * V_118 ;
unsigned int V_119 = 0 ;
for ( V_117 = F_12 ( V_31 ) -> V_32 ; V_117 ; ) {
F_72 ( V_117 -> V_120 ) ;
F_73 ( V_31 ) ;
V_117 -> V_120 = V_31 ;
V_118 = V_117 -> V_46 ;
V_117 -> V_46 = NULL ;
if ( V_119 != - V_121 )
V_119 = F_74 ( V_122 , V_114 , V_117 ,
V_115 , V_116 , F_71 ,
V_123 + 1 ) ;
else
F_13 ( V_117 ) ;
V_117 = V_118 ;
}
F_72 ( V_31 ) ;
}
static int F_75 ( struct V_1 * V_1 )
{
V_1 -> V_11 . V_12 . V_15 = V_124 ;
V_1 -> V_11 . V_12 . V_14 = V_125 ;
V_1 -> V_11 . V_12 . V_13 = V_126 ;
F_76 ( & V_1 -> V_11 . V_12 ) ;
return F_1 ( V_1 ) ;
}
static void F_77 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_78 ( & V_1 -> V_11 . V_12 , & V_28 ) ;
}
int F_79 ( void )
{
int V_119 = 0 ;
V_28 . V_127 = F_8 ;
V_28 . V_128 = V_129 ;
V_28 . V_130 = NULL ;
V_28 . V_131 = F_11 ;
V_28 . V_132 = sizeof( struct V_23 ) ;
V_28 . V_133 = V_134 ;
V_28 . V_135 = F_14 ;
V_28 . V_136 = 10 * 60 * V_137 ;
F_80 ( & V_28 ) ;
V_119 = F_81 ( & V_138 ) ;
if ( V_119 )
F_82 ( & V_28 ) ;
return V_119 ;
}
void F_83 ( void )
{
F_84 ( & V_138 ) ;
F_82 ( & V_28 ) ;
}
