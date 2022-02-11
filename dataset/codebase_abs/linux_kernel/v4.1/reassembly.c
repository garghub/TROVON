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
if ( V_15 -> V_13 . V_29 & V_35 )
goto V_33;
F_17 ( V_23 , F_18 ( V_27 ) , V_36 ) ;
if ( ! ( V_15 -> V_13 . V_29 & V_37 ) || ! V_15 -> V_13 . V_38 )
goto V_33;
V_15 -> V_13 . V_38 -> V_27 = V_27 ;
F_19 ( V_15 -> V_13 . V_38 , V_39 , V_40 , 0 ) ;
V_33:
F_20 () ;
V_31:
F_21 ( & V_15 -> V_13 . V_28 ) ;
F_22 ( & V_15 -> V_13 , V_25 ) ;
}
static void F_23 ( unsigned long V_41 )
{
struct V_14 * V_15 ;
struct V_23 * V_23 ;
V_15 = F_8 ( (struct V_12 * ) V_41 , struct V_14 , V_13 ) ;
V_23 = F_8 ( V_15 -> V_13 . V_23 , struct V_23 , V_42 . V_25 ) ;
F_12 ( V_23 , V_15 , & V_8 ) ;
}
static struct V_14 *
F_24 ( struct V_23 * V_23 , T_2 V_4 , const struct V_5 * V_20 ,
const struct V_5 * V_21 , T_1 V_22 )
{
struct V_12 * V_13 ;
struct V_17 V_18 ;
unsigned int V_43 ;
V_18 . V_4 = V_4 ;
V_18 . V_19 = V_44 ;
V_18 . V_20 = V_20 ;
V_18 . V_21 = V_21 ;
V_18 . V_22 = V_22 ;
V_43 = F_3 ( V_4 , V_20 , V_21 ) ;
V_13 = F_25 ( & V_23 -> V_42 . V_25 , & V_8 , & V_18 , V_43 ) ;
if ( F_26 ( V_13 ) ) {
F_27 ( V_13 , F_28 () ) ;
return NULL ;
}
return F_8 ( V_13 , struct V_14 , V_13 ) ;
}
static int F_29 ( struct V_14 * V_15 , struct V_45 * V_46 ,
struct V_47 * V_48 , int V_49 )
{
struct V_45 * V_50 , * V_51 ;
struct V_26 * V_27 ;
int V_52 , V_53 ;
struct V_23 * V_23 = F_30 ( F_31 ( V_46 ) -> V_27 ) ;
T_1 V_22 ;
if ( V_15 -> V_13 . V_29 & V_30 )
goto V_54;
V_52 = F_32 ( V_48 -> V_55 ) & ~ 0x7 ;
V_53 = V_52 + ( F_32 ( F_33 ( V_46 ) -> V_56 ) -
( ( T_1 * ) ( V_48 + 1 ) - ( T_1 * ) ( F_33 ( V_46 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_53 > V_57 ) {
F_17 ( V_23 , F_34 ( F_31 ( V_46 ) ) ,
V_58 ) ;
F_35 ( V_46 , V_59 ,
( ( T_1 * ) & V_48 -> V_55 -
F_36 ( V_46 ) ) ) ;
return - 1 ;
}
V_22 = F_1 ( F_33 ( V_46 ) ) ;
if ( V_46 -> V_60 == V_61 ) {
const unsigned char * V_62 = F_36 ( V_46 ) ;
V_46 -> V_63 = F_37 ( V_46 -> V_63 ,
F_38 ( V_62 , ( T_1 * ) ( V_48 + 1 ) - V_62 ,
0 ) ) ;
}
if ( ! ( V_48 -> V_55 & F_39 ( V_64 ) ) ) {
if ( V_53 < V_15 -> V_13 . V_65 ||
( ( V_15 -> V_13 . V_29 & V_66 ) && V_53 != V_15 -> V_13 . V_65 ) )
goto V_54;
V_15 -> V_13 . V_29 |= V_66 ;
V_15 -> V_13 . V_65 = V_53 ;
} else {
if ( V_53 & 0x7 ) {
F_17 ( V_23 , F_34 ( F_31 ( V_46 ) ) ,
V_58 ) ;
F_35 ( V_46 , V_59 ,
F_40 ( struct V_1 , V_56 ) ) ;
return - 1 ;
}
if ( V_53 > V_15 -> V_13 . V_65 ) {
if ( V_15 -> V_13 . V_29 & V_66 )
goto V_54;
V_15 -> V_13 . V_65 = V_53 ;
}
}
if ( V_53 == V_52 )
goto V_54;
if ( ! F_41 ( V_46 , ( T_1 * ) ( V_48 + 1 ) - V_46 -> V_41 ) )
goto V_54;
if ( F_42 ( V_46 , V_53 - V_52 ) )
goto V_54;
V_50 = V_15 -> V_13 . V_67 ;
if ( ! V_50 || F_43 ( V_50 ) -> V_52 < V_52 ) {
V_51 = NULL ;
goto V_68;
}
V_50 = NULL ;
for ( V_51 = V_15 -> V_13 . V_38 ; V_51 != NULL ; V_51 = V_51 -> V_51 ) {
if ( F_43 ( V_51 ) -> V_52 >= V_52 )
break;
V_50 = V_51 ;
}
V_68:
if ( V_50 &&
( F_43 ( V_50 ) -> V_52 + V_50 -> V_65 ) > V_52 )
goto V_69;
if ( V_51 && F_43 ( V_51 ) -> V_52 < V_53 )
goto V_69;
F_43 ( V_46 ) -> V_52 = V_52 ;
V_46 -> V_51 = V_51 ;
if ( ! V_51 )
V_15 -> V_13 . V_67 = V_46 ;
if ( V_50 )
V_50 -> V_51 = V_46 ;
else
V_15 -> V_13 . V_38 = V_46 ;
V_27 = V_46 -> V_27 ;
if ( V_27 ) {
V_15 -> V_32 = V_27 -> V_70 ;
V_46 -> V_27 = NULL ;
}
V_15 -> V_13 . V_71 = V_46 -> V_72 ;
V_15 -> V_13 . V_73 += V_46 -> V_65 ;
V_15 -> V_22 |= V_22 ;
F_44 ( & V_15 -> V_13 , V_46 -> V_74 ) ;
if ( V_52 == 0 ) {
V_15 -> V_75 = V_49 ;
V_15 -> V_13 . V_29 |= V_37 ;
}
if ( V_15 -> V_13 . V_29 == ( V_37 | V_66 ) &&
V_15 -> V_13 . V_73 == V_15 -> V_13 . V_65 ) {
int V_76 ;
unsigned long V_77 = V_46 -> V_78 ;
V_46 -> V_78 = 0UL ;
V_76 = F_45 ( V_15 , V_50 , V_27 ) ;
V_46 -> V_78 = V_77 ;
return V_76 ;
}
F_46 ( V_46 ) ;
return - 1 ;
V_69:
F_14 ( & V_15 -> V_13 , & V_8 ) ;
V_54:
F_17 ( V_23 , F_34 ( F_31 ( V_46 ) ) ,
V_34 ) ;
F_47 ( V_46 ) ;
return - 1 ;
}
static int F_45 ( struct V_14 * V_15 , struct V_45 * V_50 ,
struct V_26 * V_27 )
{
struct V_23 * V_23 = F_8 ( V_15 -> V_13 . V_23 , struct V_23 , V_42 . V_25 ) ;
struct V_45 * V_79 , * V_80 = V_15 -> V_13 . V_38 ;
int V_56 ;
unsigned int V_49 ;
int V_81 ;
T_1 V_22 ;
F_14 ( & V_15 -> V_13 , & V_8 ) ;
V_22 = V_82 [ V_15 -> V_22 ] ;
if ( F_48 ( V_22 == 0xff ) )
goto V_83;
if ( V_50 ) {
V_80 = V_50 -> V_51 ;
V_79 = F_49 ( V_80 , V_84 ) ;
if ( ! V_79 )
goto V_85;
V_79 -> V_51 = V_80 -> V_51 ;
if ( ! V_79 -> V_51 )
V_15 -> V_13 . V_67 = V_79 ;
V_50 -> V_51 = V_79 ;
F_50 ( V_80 , V_15 -> V_13 . V_38 ) ;
V_80 -> V_51 = V_15 -> V_13 . V_38 -> V_51 ;
F_51 ( V_15 -> V_13 . V_38 ) ;
V_15 -> V_13 . V_38 = V_80 ;
}
F_52 ( V_80 == NULL ) ;
F_52 ( F_43 ( V_80 ) -> V_52 != 0 ) ;
V_56 = ( ( V_80 -> V_41 - F_36 ( V_80 ) ) -
sizeof( struct V_1 ) + V_15 -> V_13 . V_65 -
sizeof( struct V_47 ) ) ;
if ( V_56 > V_57 )
goto V_86;
if ( F_53 ( V_80 , V_84 ) )
goto V_85;
if ( F_54 ( V_80 ) ) {
struct V_45 * V_87 ;
int V_88 , V_89 = 0 ;
V_87 = F_55 ( 0 , V_84 ) ;
if ( ! V_87 )
goto V_85;
V_87 -> V_51 = V_80 -> V_51 ;
V_80 -> V_51 = V_87 ;
F_56 ( V_87 ) -> V_90 = F_56 ( V_80 ) -> V_90 ;
F_57 ( V_80 ) ;
for ( V_88 = 0 ; V_88 < F_56 ( V_80 ) -> V_91 ; V_88 ++ )
V_89 += F_58 ( & F_56 ( V_80 ) -> V_25 [ V_88 ] ) ;
V_87 -> V_65 = V_87 -> V_92 = V_80 -> V_92 - V_89 ;
V_80 -> V_92 -= V_87 -> V_65 ;
V_80 -> V_65 -= V_87 -> V_65 ;
V_87 -> V_63 = 0 ;
V_87 -> V_60 = V_80 -> V_60 ;
F_44 ( & V_15 -> V_13 , V_87 -> V_74 ) ;
}
V_49 = V_15 -> V_75 ;
F_36 ( V_80 ) [ V_49 ] = F_59 ( V_80 ) [ 0 ] ;
memmove ( V_80 -> V_80 + sizeof( struct V_47 ) , V_80 -> V_80 ,
( V_80 -> V_41 - V_80 -> V_80 ) - sizeof( struct V_47 ) ) ;
V_80 -> V_93 += sizeof( struct V_47 ) ;
V_80 -> V_94 += sizeof( struct V_47 ) ;
F_60 ( V_80 ) ;
F_61 ( V_80 , V_80 -> V_41 - F_36 ( V_80 ) ) ;
V_81 = V_80 -> V_74 ;
for ( V_79 = V_80 -> V_51 ; V_79 ; ) {
bool V_95 ;
int V_96 ;
struct V_45 * V_51 = V_79 -> V_51 ;
V_81 += V_79 -> V_74 ;
if ( V_80 -> V_60 != V_79 -> V_60 )
V_80 -> V_60 = V_97 ;
else if ( V_80 -> V_60 == V_61 )
V_80 -> V_63 = F_62 ( V_80 -> V_63 , V_79 -> V_63 ) ;
if ( F_63 ( V_80 , V_79 , & V_95 , & V_96 ) ) {
F_64 ( V_79 , V_95 ) ;
} else {
if ( ! F_56 ( V_80 ) -> V_90 )
F_56 ( V_80 ) -> V_90 = V_79 ;
V_80 -> V_92 += V_79 -> V_65 ;
V_80 -> V_65 += V_79 -> V_65 ;
V_80 -> V_74 += V_79 -> V_74 ;
}
V_79 = V_51 ;
}
F_65 ( & V_15 -> V_13 , V_81 ) ;
V_80 -> V_51 = NULL ;
V_80 -> V_27 = V_27 ;
V_80 -> V_72 = V_15 -> V_13 . V_71 ;
F_33 ( V_80 ) -> V_56 = F_39 ( V_56 ) ;
F_66 ( F_33 ( V_80 ) , 0xff , V_22 ) ;
F_67 ( V_80 ) -> V_49 = V_49 ;
F_67 ( V_80 ) -> V_29 |= V_98 ;
if ( V_80 -> V_60 == V_61 )
V_80 -> V_63 = F_38 ( F_36 ( V_80 ) ,
F_68 ( V_80 ) ,
V_80 -> V_63 ) ;
F_15 () ;
F_17 ( V_23 , F_18 ( V_27 ) , V_99 ) ;
F_20 () ;
V_15 -> V_13 . V_38 = NULL ;
V_15 -> V_13 . V_67 = NULL ;
return 1 ;
V_86:
F_69 ( L_1 , V_56 ) ;
goto V_83;
V_85:
F_69 ( L_2 ) ;
V_83:
F_15 () ;
F_17 ( V_23 , F_18 ( V_27 ) , V_34 ) ;
F_20 () ;
return - 1 ;
}
static int F_70 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_14 * V_15 ;
const struct V_1 * V_100 = F_33 ( V_46 ) ;
struct V_23 * V_23 = F_30 ( F_31 ( V_46 ) -> V_27 ) ;
if ( F_67 ( V_46 ) -> V_29 & V_98 )
goto V_101;
F_17 ( V_23 , F_34 ( F_31 ( V_46 ) ) , V_102 ) ;
if ( V_100 -> V_56 == 0 )
goto V_101;
if ( ! F_71 ( V_46 , ( F_72 ( V_46 ) +
sizeof( struct V_47 ) ) ) )
goto V_101;
V_100 = F_33 ( V_46 ) ;
V_48 = (struct V_47 * ) F_59 ( V_46 ) ;
if ( ! ( V_48 -> V_55 & F_39 ( 0xFFF9 ) ) ) {
V_46 -> V_103 += sizeof( struct V_47 ) ;
F_17 ( V_23 ,
F_34 ( F_31 ( V_46 ) ) , V_99 ) ;
F_67 ( V_46 ) -> V_49 = ( T_1 * ) V_48 - F_36 ( V_46 ) ;
F_67 ( V_46 ) -> V_29 |= V_98 ;
return 1 ;
}
V_15 = F_24 ( V_23 , V_48 -> V_104 , & V_100 -> V_6 , & V_100 -> V_7 ,
F_1 ( V_100 ) ) ;
if ( V_15 ) {
int V_105 ;
F_13 ( & V_15 -> V_13 . V_28 ) ;
V_105 = F_29 ( V_15 , V_46 , V_48 , F_67 ( V_46 ) -> V_49 ) ;
F_21 ( & V_15 -> V_13 . V_28 ) ;
F_22 ( & V_15 -> V_13 , & V_8 ) ;
return V_105 ;
}
F_17 ( V_23 , F_34 ( F_31 ( V_46 ) ) , V_34 ) ;
F_47 ( V_46 ) ;
return - 1 ;
V_101:
F_17 ( V_23 , F_34 ( F_31 ( V_46 ) ) ,
V_58 ) ;
F_35 ( V_46 , V_59 , F_68 ( V_46 ) ) ;
return - 1 ;
}
static int T_3 F_73 ( struct V_23 * V_23 )
{
struct V_106 * V_107 ;
struct V_108 * V_100 ;
V_107 = V_109 ;
if ( ! F_74 ( V_23 , & V_110 ) ) {
V_107 = F_75 ( V_107 , sizeof( V_109 ) , V_111 ) ;
if ( ! V_107 )
goto V_112;
V_107 [ 0 ] . V_41 = & V_23 -> V_42 . V_25 . V_113 ;
V_107 [ 0 ] . V_114 = & V_23 -> V_42 . V_25 . V_115 ;
V_107 [ 0 ] . V_116 = & V_110 . V_42 . V_25 . V_113 ;
V_107 [ 1 ] . V_41 = & V_23 -> V_42 . V_25 . V_115 ;
V_107 [ 1 ] . V_116 = & V_23 -> V_42 . V_25 . V_113 ;
V_107 [ 2 ] . V_41 = & V_23 -> V_42 . V_25 . V_117 ;
if ( V_23 -> V_118 != & V_119 )
V_107 [ 0 ] . V_120 = NULL ;
}
V_100 = F_76 ( V_23 , L_3 , V_107 ) ;
if ( ! V_100 )
goto V_121;
V_23 -> V_42 . V_122 . V_123 = V_100 ;
return 0 ;
V_121:
if ( ! F_74 ( V_23 , & V_110 ) )
F_77 ( V_107 ) ;
V_112:
return - V_124 ;
}
static void T_4 F_78 ( struct V_23 * V_23 )
{
struct V_106 * V_107 ;
V_107 = V_23 -> V_42 . V_122 . V_123 -> V_125 ;
F_79 ( V_23 -> V_42 . V_122 . V_123 ) ;
if ( ! F_74 ( V_23 , & V_110 ) )
F_77 ( V_107 ) ;
}
static int F_80 ( void )
{
V_126 = F_76 ( & V_110 , L_3 ,
V_127 ) ;
return V_126 == NULL ? - V_124 : 0 ;
}
static void F_81 ( void )
{
F_79 ( V_126 ) ;
}
static int F_73 ( struct V_23 * V_23 )
{
return 0 ;
}
static void F_78 ( struct V_23 * V_23 )
{
}
static int F_80 ( void )
{
return 0 ;
}
static void F_81 ( void )
{
}
static int T_3 F_82 ( struct V_23 * V_23 )
{
V_23 -> V_42 . V_25 . V_113 = V_128 ;
V_23 -> V_42 . V_25 . V_115 = V_129 ;
V_23 -> V_42 . V_25 . V_117 = V_130 ;
F_83 ( & V_23 -> V_42 . V_25 ) ;
return F_73 ( V_23 ) ;
}
static void T_4 F_84 ( struct V_23 * V_23 )
{
F_78 ( V_23 ) ;
F_85 ( & V_23 -> V_42 . V_25 , & V_8 ) ;
}
int T_5 F_86 ( void )
{
int V_105 ;
V_105 = F_87 ( & V_131 , V_132 ) ;
if ( V_105 )
goto V_31;
V_105 = F_80 () ;
if ( V_105 )
goto V_133;
V_105 = F_88 ( & V_134 ) ;
if ( V_105 )
goto V_135;
V_8 . V_136 = F_7 ;
V_8 . V_137 = F_11 ;
V_8 . V_138 = NULL ;
V_8 . V_139 = NULL ;
V_8 . V_140 = sizeof( struct V_14 ) ;
V_8 . V_141 = F_9 ;
V_8 . V_142 = F_23 ;
V_8 . V_143 = V_144 ;
V_105 = F_89 ( & V_8 ) ;
if ( V_105 )
goto V_135;
V_31:
return V_105 ;
V_135:
F_81 () ;
V_133:
F_90 ( & V_131 , V_132 ) ;
goto V_31;
}
void F_91 ( void )
{
F_92 ( & V_8 ) ;
F_81 () ;
F_93 ( & V_134 ) ;
F_90 ( & V_131 , V_132 ) ;
}
