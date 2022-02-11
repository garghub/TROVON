static T_1 F_1 ( const struct V_1 * V_2 )
{
return 1 << ( F_2 ( V_2 ) & V_3 ) ;
}
static unsigned int F_3 ( T_2 V_4 , const struct V_5 * V_6 ,
const struct V_5 * V_7 )
{
F_4 ( & V_8 . V_9 , sizeof( V_8 . V_9 ) ) ;
return F_5 ( F_6 ( V_6 ) , F_6 ( V_7 ) ,
( V_10 V_11 ) V_4 , V_8 . V_9 ) ;
}
static unsigned int F_7 ( const struct V_12 * V_13 )
{
const struct V_14 * V_15 ;
V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
return F_3 ( V_15 -> V_4 , & V_15 -> V_6 , & V_15 -> V_7 ) ;
}
bool F_9 ( const struct V_12 * V_13 , const void * V_16 )
{
const struct V_14 * V_15 ;
const struct V_17 * V_18 = V_16 ;
V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
return V_15 -> V_4 == V_18 -> V_4 &&
V_15 -> V_19 == V_18 -> V_19 &&
F_10 ( & V_15 -> V_6 , V_18 -> V_20 ) &&
F_10 ( & V_15 -> V_7 , V_18 -> V_21 ) ;
}
void F_11 ( struct V_12 * V_13 , const void * V_16 )
{
struct V_14 * V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
const struct V_17 * V_18 = V_16 ;
V_15 -> V_4 = V_18 -> V_4 ;
V_15 -> V_19 = V_18 -> V_19 ;
V_15 -> V_6 = * V_18 -> V_20 ;
V_15 -> V_7 = * V_18 -> V_21 ;
V_15 -> V_22 = V_18 -> V_22 ;
}
void F_12 ( struct V_23 * V_23 , struct V_14 * V_15 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = NULL ;
F_13 ( & V_15 -> V_13 . V_28 ) ;
if ( V_15 -> V_13 . V_29 & V_30 )
goto V_31;
F_14 ( & V_15 -> V_13 , V_25 ) ;
F_15 () ;
V_27 = F_16 ( V_23 , V_15 -> V_32 ) ;
if ( ! V_27 )
goto V_33;
F_17 ( V_23 , F_18 ( V_27 ) , V_34 ) ;
if ( F_19 ( & V_15 -> V_13 ) )
goto V_33;
F_17 ( V_23 , F_18 ( V_27 ) , V_35 ) ;
if ( ! ( V_15 -> V_13 . V_29 & V_36 ) || ! V_15 -> V_13 . V_37 )
goto V_33;
V_15 -> V_13 . V_37 -> V_27 = V_27 ;
F_20 ( V_15 -> V_13 . V_37 , V_38 , V_39 , 0 ) ;
V_33:
F_21 () ;
V_31:
F_22 ( & V_15 -> V_13 . V_28 ) ;
F_23 ( & V_15 -> V_13 , V_25 ) ;
}
static void F_24 ( unsigned long V_40 )
{
struct V_14 * V_15 ;
struct V_23 * V_23 ;
V_15 = F_8 ( (struct V_12 * ) V_40 , struct V_14 , V_13 ) ;
V_23 = F_8 ( V_15 -> V_13 . V_23 , struct V_23 , V_41 . V_25 ) ;
F_12 ( V_23 , V_15 , & V_8 ) ;
}
static struct V_14 *
F_25 ( struct V_23 * V_23 , T_2 V_4 , const struct V_5 * V_20 ,
const struct V_5 * V_21 , T_1 V_22 )
{
struct V_12 * V_13 ;
struct V_17 V_18 ;
unsigned int V_42 ;
V_18 . V_4 = V_4 ;
V_18 . V_19 = V_43 ;
V_18 . V_20 = V_20 ;
V_18 . V_21 = V_21 ;
V_18 . V_22 = V_22 ;
V_42 = F_3 ( V_4 , V_20 , V_21 ) ;
V_13 = F_26 ( & V_23 -> V_41 . V_25 , & V_8 , & V_18 , V_42 ) ;
if ( F_27 ( V_13 ) ) {
F_28 ( V_13 , F_29 () ) ;
return NULL ;
}
return F_8 ( V_13 , struct V_14 , V_13 ) ;
}
static int F_30 ( struct V_14 * V_15 , struct V_44 * V_45 ,
struct V_46 * V_47 , int V_48 )
{
struct V_44 * V_49 , * V_50 ;
struct V_26 * V_27 ;
int V_51 , V_52 ;
struct V_23 * V_23 = F_31 ( F_32 ( V_45 ) -> V_27 ) ;
T_1 V_22 ;
if ( V_15 -> V_13 . V_29 & V_30 )
goto V_53;
V_51 = F_33 ( V_47 -> V_54 ) & ~ 0x7 ;
V_52 = V_51 + ( F_33 ( F_34 ( V_45 ) -> V_55 ) -
( ( T_1 * ) ( V_47 + 1 ) - ( T_1 * ) ( F_34 ( V_45 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_52 > V_56 ) {
F_17 ( V_23 , F_35 ( F_32 ( V_45 ) ) ,
V_57 ) ;
F_36 ( V_45 , V_58 ,
( ( T_1 * ) & V_47 -> V_54 -
F_37 ( V_45 ) ) ) ;
return - 1 ;
}
V_22 = F_1 ( F_34 ( V_45 ) ) ;
if ( V_45 -> V_59 == V_60 ) {
const unsigned char * V_61 = F_37 ( V_45 ) ;
V_45 -> V_62 = F_38 ( V_45 -> V_62 ,
F_39 ( V_61 , ( T_1 * ) ( V_47 + 1 ) - V_61 ,
0 ) ) ;
}
if ( ! ( V_47 -> V_54 & F_40 ( V_63 ) ) ) {
if ( V_52 < V_15 -> V_13 . V_64 ||
( ( V_15 -> V_13 . V_29 & V_65 ) && V_52 != V_15 -> V_13 . V_64 ) )
goto V_53;
V_15 -> V_13 . V_29 |= V_65 ;
V_15 -> V_13 . V_64 = V_52 ;
} else {
if ( V_52 & 0x7 ) {
F_17 ( V_23 , F_35 ( F_32 ( V_45 ) ) ,
V_57 ) ;
F_36 ( V_45 , V_58 ,
F_41 ( struct V_1 , V_55 ) ) ;
return - 1 ;
}
if ( V_52 > V_15 -> V_13 . V_64 ) {
if ( V_15 -> V_13 . V_29 & V_65 )
goto V_53;
V_15 -> V_13 . V_64 = V_52 ;
}
}
if ( V_52 == V_51 )
goto V_53;
if ( ! F_42 ( V_45 , ( T_1 * ) ( V_47 + 1 ) - V_45 -> V_40 ) )
goto V_53;
if ( F_43 ( V_45 , V_52 - V_51 ) )
goto V_53;
V_49 = V_15 -> V_13 . V_66 ;
if ( ! V_49 || F_44 ( V_49 ) -> V_51 < V_51 ) {
V_50 = NULL ;
goto V_67;
}
V_49 = NULL ;
for ( V_50 = V_15 -> V_13 . V_37 ; V_50 != NULL ; V_50 = V_50 -> V_50 ) {
if ( F_44 ( V_50 ) -> V_51 >= V_51 )
break;
V_49 = V_50 ;
}
V_67:
if ( V_49 &&
( F_44 ( V_49 ) -> V_51 + V_49 -> V_64 ) > V_51 )
goto V_68;
if ( V_50 && F_44 ( V_50 ) -> V_51 < V_52 )
goto V_68;
F_44 ( V_45 ) -> V_51 = V_51 ;
V_45 -> V_50 = V_50 ;
if ( ! V_50 )
V_15 -> V_13 . V_66 = V_45 ;
if ( V_49 )
V_49 -> V_50 = V_45 ;
else
V_15 -> V_13 . V_37 = V_45 ;
V_27 = V_45 -> V_27 ;
if ( V_27 ) {
V_15 -> V_32 = V_27 -> V_69 ;
V_45 -> V_27 = NULL ;
}
V_15 -> V_13 . V_70 = V_45 -> V_71 ;
V_15 -> V_13 . V_72 += V_45 -> V_64 ;
V_15 -> V_22 |= V_22 ;
F_45 ( V_15 -> V_13 . V_23 , V_45 -> V_73 ) ;
if ( V_51 == 0 ) {
V_15 -> V_74 = V_48 ;
V_15 -> V_13 . V_29 |= V_36 ;
}
if ( V_15 -> V_13 . V_29 == ( V_36 | V_65 ) &&
V_15 -> V_13 . V_72 == V_15 -> V_13 . V_64 ) {
int V_75 ;
unsigned long V_76 = V_45 -> V_77 ;
V_45 -> V_77 = 0UL ;
V_75 = F_46 ( V_15 , V_49 , V_27 ) ;
V_45 -> V_77 = V_76 ;
return V_75 ;
}
F_47 ( V_45 ) ;
return - 1 ;
V_68:
F_14 ( & V_15 -> V_13 , & V_8 ) ;
V_53:
F_17 ( V_23 , F_35 ( F_32 ( V_45 ) ) ,
V_34 ) ;
F_48 ( V_45 ) ;
return - 1 ;
}
static int F_46 ( struct V_14 * V_15 , struct V_44 * V_49 ,
struct V_26 * V_27 )
{
struct V_23 * V_23 = F_8 ( V_15 -> V_13 . V_23 , struct V_23 , V_41 . V_25 ) ;
struct V_44 * V_78 , * V_79 = V_15 -> V_13 . V_37 ;
int V_55 ;
unsigned int V_48 ;
int V_80 ;
T_1 V_22 ;
F_14 ( & V_15 -> V_13 , & V_8 ) ;
V_22 = V_81 [ V_15 -> V_22 ] ;
if ( F_49 ( V_22 == 0xff ) )
goto V_82;
if ( V_49 ) {
V_79 = V_49 -> V_50 ;
V_78 = F_50 ( V_79 , V_83 ) ;
if ( ! V_78 )
goto V_84;
V_78 -> V_50 = V_79 -> V_50 ;
if ( ! V_78 -> V_50 )
V_15 -> V_13 . V_66 = V_78 ;
V_49 -> V_50 = V_78 ;
F_51 ( V_79 , V_15 -> V_13 . V_37 ) ;
V_79 -> V_50 = V_15 -> V_13 . V_37 -> V_50 ;
F_52 ( V_15 -> V_13 . V_37 ) ;
V_15 -> V_13 . V_37 = V_79 ;
}
F_53 ( V_79 == NULL ) ;
F_53 ( F_44 ( V_79 ) -> V_51 != 0 ) ;
V_55 = ( ( V_79 -> V_40 - F_37 ( V_79 ) ) -
sizeof( struct V_1 ) + V_15 -> V_13 . V_64 -
sizeof( struct V_46 ) ) ;
if ( V_55 > V_56 )
goto V_85;
if ( F_54 ( V_79 , V_83 ) )
goto V_84;
if ( F_55 ( V_79 ) ) {
struct V_44 * V_86 ;
int V_87 , V_88 = 0 ;
V_86 = F_56 ( 0 , V_83 ) ;
if ( ! V_86 )
goto V_84;
V_86 -> V_50 = V_79 -> V_50 ;
V_79 -> V_50 = V_86 ;
F_57 ( V_86 ) -> V_89 = F_57 ( V_79 ) -> V_89 ;
F_58 ( V_79 ) ;
for ( V_87 = 0 ; V_87 < F_57 ( V_79 ) -> V_90 ; V_87 ++ )
V_88 += F_59 ( & F_57 ( V_79 ) -> V_25 [ V_87 ] ) ;
V_86 -> V_64 = V_86 -> V_91 = V_79 -> V_91 - V_88 ;
V_79 -> V_91 -= V_86 -> V_64 ;
V_79 -> V_64 -= V_86 -> V_64 ;
V_86 -> V_62 = 0 ;
V_86 -> V_59 = V_79 -> V_59 ;
F_45 ( V_15 -> V_13 . V_23 , V_86 -> V_73 ) ;
}
V_48 = V_15 -> V_74 ;
F_37 ( V_79 ) [ V_48 ] = F_60 ( V_79 ) [ 0 ] ;
memmove ( V_79 -> V_79 + sizeof( struct V_46 ) , V_79 -> V_79 ,
( V_79 -> V_40 - V_79 -> V_79 ) - sizeof( struct V_46 ) ) ;
V_79 -> V_92 += sizeof( struct V_46 ) ;
V_79 -> V_93 += sizeof( struct V_46 ) ;
F_61 ( V_79 ) ;
F_62 ( V_79 , V_79 -> V_40 - F_37 ( V_79 ) ) ;
V_80 = V_79 -> V_73 ;
for ( V_78 = V_79 -> V_50 ; V_78 ; ) {
bool V_94 ;
int V_95 ;
struct V_44 * V_50 = V_78 -> V_50 ;
V_80 += V_78 -> V_73 ;
if ( V_79 -> V_59 != V_78 -> V_59 )
V_79 -> V_59 = V_96 ;
else if ( V_79 -> V_59 == V_60 )
V_79 -> V_62 = F_63 ( V_79 -> V_62 , V_78 -> V_62 ) ;
if ( F_64 ( V_79 , V_78 , & V_94 , & V_95 ) ) {
F_65 ( V_78 , V_94 ) ;
} else {
if ( ! F_57 ( V_79 ) -> V_89 )
F_57 ( V_79 ) -> V_89 = V_78 ;
V_79 -> V_91 += V_78 -> V_64 ;
V_79 -> V_64 += V_78 -> V_64 ;
V_79 -> V_73 += V_78 -> V_73 ;
}
V_78 = V_50 ;
}
F_66 ( V_15 -> V_13 . V_23 , V_80 ) ;
V_79 -> V_50 = NULL ;
V_79 -> V_27 = V_27 ;
V_79 -> V_71 = V_15 -> V_13 . V_70 ;
F_34 ( V_79 ) -> V_55 = F_40 ( V_55 ) ;
F_67 ( F_34 ( V_79 ) , 0xff , V_22 ) ;
F_68 ( V_79 ) -> V_48 = V_48 ;
F_68 ( V_79 ) -> V_29 |= V_97 ;
if ( V_79 -> V_59 == V_60 )
V_79 -> V_62 = F_39 ( F_37 ( V_79 ) ,
F_69 ( V_79 ) ,
V_79 -> V_62 ) ;
F_15 () ;
F_17 ( V_23 , F_18 ( V_27 ) , V_98 ) ;
F_21 () ;
V_15 -> V_13 . V_37 = NULL ;
V_15 -> V_13 . V_66 = NULL ;
return 1 ;
V_85:
F_70 ( L_1 , V_55 ) ;
goto V_82;
V_84:
F_70 ( L_2 ) ;
V_82:
F_15 () ;
F_17 ( V_23 , F_18 ( V_27 ) , V_34 ) ;
F_21 () ;
return - 1 ;
}
static int F_71 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_14 * V_15 ;
const struct V_1 * V_99 = F_34 ( V_45 ) ;
struct V_23 * V_23 = F_31 ( F_32 ( V_45 ) -> V_27 ) ;
if ( F_68 ( V_45 ) -> V_29 & V_97 )
goto V_100;
F_17 ( V_23 , F_35 ( F_32 ( V_45 ) ) , V_101 ) ;
if ( V_99 -> V_55 == 0 )
goto V_100;
if ( ! F_72 ( V_45 , ( F_73 ( V_45 ) +
sizeof( struct V_46 ) ) ) )
goto V_100;
V_99 = F_34 ( V_45 ) ;
V_47 = (struct V_46 * ) F_60 ( V_45 ) ;
if ( ! ( V_47 -> V_54 & F_40 ( 0xFFF9 ) ) ) {
V_45 -> V_102 += sizeof( struct V_46 ) ;
F_17 ( V_23 ,
F_35 ( F_32 ( V_45 ) ) , V_98 ) ;
F_68 ( V_45 ) -> V_48 = ( T_1 * ) V_47 - F_37 ( V_45 ) ;
F_68 ( V_45 ) -> V_29 |= V_97 ;
return 1 ;
}
V_15 = F_25 ( V_23 , V_47 -> V_103 , & V_99 -> V_6 , & V_99 -> V_7 ,
F_1 ( V_99 ) ) ;
if ( V_15 ) {
int V_104 ;
F_13 ( & V_15 -> V_13 . V_28 ) ;
V_104 = F_30 ( V_15 , V_45 , V_47 , F_68 ( V_45 ) -> V_48 ) ;
F_22 ( & V_15 -> V_13 . V_28 ) ;
F_23 ( & V_15 -> V_13 , & V_8 ) ;
return V_104 ;
}
F_17 ( V_23 , F_35 ( F_32 ( V_45 ) ) , V_34 ) ;
F_48 ( V_45 ) ;
return - 1 ;
V_100:
F_17 ( V_23 , F_35 ( F_32 ( V_45 ) ) ,
V_57 ) ;
F_36 ( V_45 , V_58 , F_69 ( V_45 ) ) ;
return - 1 ;
}
static int T_3 F_74 ( struct V_23 * V_23 )
{
struct V_105 * V_106 ;
struct V_107 * V_99 ;
V_106 = V_108 ;
if ( ! F_75 ( V_23 , & V_109 ) ) {
V_106 = F_76 ( V_106 , sizeof( V_108 ) , V_110 ) ;
if ( ! V_106 )
goto V_111;
V_106 [ 0 ] . V_40 = & V_23 -> V_41 . V_25 . V_112 ;
V_106 [ 0 ] . V_113 = & V_23 -> V_41 . V_25 . V_114 ;
V_106 [ 0 ] . V_115 = & V_109 . V_41 . V_25 . V_112 ;
V_106 [ 1 ] . V_40 = & V_23 -> V_41 . V_25 . V_114 ;
V_106 [ 1 ] . V_115 = & V_23 -> V_41 . V_25 . V_112 ;
V_106 [ 2 ] . V_40 = & V_23 -> V_41 . V_25 . V_116 ;
if ( V_23 -> V_117 != & V_118 )
V_106 [ 0 ] . V_119 = NULL ;
}
V_99 = F_77 ( V_23 , L_3 , V_106 ) ;
if ( ! V_99 )
goto V_120;
V_23 -> V_41 . V_121 . V_122 = V_99 ;
return 0 ;
V_120:
if ( ! F_75 ( V_23 , & V_109 ) )
F_78 ( V_106 ) ;
V_111:
return - V_123 ;
}
static void T_4 F_79 ( struct V_23 * V_23 )
{
struct V_105 * V_106 ;
V_106 = V_23 -> V_41 . V_121 . V_122 -> V_124 ;
F_80 ( V_23 -> V_41 . V_121 . V_122 ) ;
if ( ! F_75 ( V_23 , & V_109 ) )
F_78 ( V_106 ) ;
}
static int F_81 ( void )
{
V_125 = F_77 ( & V_109 , L_3 ,
V_126 ) ;
return V_125 == NULL ? - V_123 : 0 ;
}
static void F_82 ( void )
{
F_80 ( V_125 ) ;
}
static int F_74 ( struct V_23 * V_23 )
{
return 0 ;
}
static void F_79 ( struct V_23 * V_23 )
{
}
static int F_81 ( void )
{
return 0 ;
}
static void F_82 ( void )
{
}
static int T_3 F_83 ( struct V_23 * V_23 )
{
V_23 -> V_41 . V_25 . V_112 = V_127 ;
V_23 -> V_41 . V_25 . V_114 = V_128 ;
V_23 -> V_41 . V_25 . V_116 = V_129 ;
F_84 ( & V_23 -> V_41 . V_25 ) ;
return F_74 ( V_23 ) ;
}
static void T_4 F_85 ( struct V_23 * V_23 )
{
F_79 ( V_23 ) ;
F_86 ( & V_23 -> V_41 . V_25 , & V_8 ) ;
}
int T_5 F_87 ( void )
{
int V_104 ;
V_104 = F_88 ( & V_130 , V_131 ) ;
if ( V_104 )
goto V_31;
V_104 = F_81 () ;
if ( V_104 )
goto V_132;
V_104 = F_89 ( & V_133 ) ;
if ( V_104 )
goto V_134;
V_8 . V_135 = F_7 ;
V_8 . V_136 = F_11 ;
V_8 . V_137 = NULL ;
V_8 . V_138 = NULL ;
V_8 . V_139 = sizeof( struct V_14 ) ;
V_8 . V_140 = F_9 ;
V_8 . V_141 = F_24 ;
V_8 . V_142 = V_143 ;
V_104 = F_90 ( & V_8 ) ;
if ( V_104 )
goto V_134;
V_31:
return V_104 ;
V_134:
F_82 () ;
V_132:
F_91 ( & V_130 , V_131 ) ;
goto V_31;
}
void F_92 ( void )
{
F_93 ( & V_8 ) ;
F_82 () ;
F_94 ( & V_133 ) ;
F_91 ( & V_130 , V_131 ) ;
}
