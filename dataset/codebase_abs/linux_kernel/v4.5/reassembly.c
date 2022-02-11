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
F_10 ( & V_15 -> V_7 , V_18 -> V_21 ) &&
( V_18 -> V_22 == V_15 -> V_22 ||
! ( F_11 ( V_18 -> V_21 ) & ( V_23 |
V_24 ) ) ) ;
}
void F_12 ( struct V_12 * V_13 , const void * V_16 )
{
struct V_14 * V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
const struct V_17 * V_18 = V_16 ;
V_15 -> V_4 = V_18 -> V_4 ;
V_15 -> V_19 = V_18 -> V_19 ;
V_15 -> V_6 = * V_18 -> V_20 ;
V_15 -> V_7 = * V_18 -> V_21 ;
V_15 -> V_25 = V_18 -> V_25 ;
}
void F_13 ( struct V_26 * V_26 , struct V_14 * V_15 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = NULL ;
F_14 ( & V_15 -> V_13 . V_31 ) ;
if ( V_15 -> V_13 . V_32 & V_33 )
goto V_34;
F_15 ( & V_15 -> V_13 , V_28 ) ;
F_16 () ;
V_30 = F_17 ( V_26 , V_15 -> V_22 ) ;
if ( ! V_30 )
goto V_35;
F_18 ( V_26 , F_19 ( V_30 ) , V_36 ) ;
if ( F_20 ( & V_15 -> V_13 ) )
goto V_35;
F_18 ( V_26 , F_19 ( V_30 ) , V_37 ) ;
if ( ! ( V_15 -> V_13 . V_32 & V_38 ) || ! V_15 -> V_13 . V_39 )
goto V_35;
V_15 -> V_13 . V_39 -> V_30 = V_30 ;
F_21 ( V_15 -> V_13 . V_39 , V_40 , V_41 , 0 ) ;
V_35:
F_22 () ;
V_34:
F_23 ( & V_15 -> V_13 . V_31 ) ;
F_24 ( & V_15 -> V_13 , V_28 ) ;
}
static void F_25 ( unsigned long V_42 )
{
struct V_14 * V_15 ;
struct V_26 * V_26 ;
V_15 = F_8 ( (struct V_12 * ) V_42 , struct V_14 , V_13 ) ;
V_26 = F_8 ( V_15 -> V_13 . V_26 , struct V_26 , V_43 . V_28 ) ;
F_13 ( V_26 , V_15 , & V_8 ) ;
}
static struct V_14 *
F_26 ( struct V_26 * V_26 , T_2 V_4 , const struct V_5 * V_20 ,
const struct V_5 * V_21 , int V_22 , T_1 V_25 )
{
struct V_12 * V_13 ;
struct V_17 V_18 ;
unsigned int V_44 ;
V_18 . V_4 = V_4 ;
V_18 . V_19 = V_45 ;
V_18 . V_20 = V_20 ;
V_18 . V_21 = V_21 ;
V_18 . V_22 = V_22 ;
V_18 . V_25 = V_25 ;
V_44 = F_3 ( V_4 , V_20 , V_21 ) ;
V_13 = F_27 ( & V_26 -> V_43 . V_28 , & V_8 , & V_18 , V_44 ) ;
if ( F_28 ( V_13 ) ) {
F_29 ( V_13 , F_30 () ) ;
return NULL ;
}
return F_8 ( V_13 , struct V_14 , V_13 ) ;
}
static int F_31 ( struct V_14 * V_15 , struct V_46 * V_47 ,
struct V_48 * V_49 , int V_50 )
{
struct V_46 * V_51 , * V_52 ;
struct V_29 * V_30 ;
int V_53 , V_54 ;
struct V_26 * V_26 = F_32 ( F_33 ( V_47 ) -> V_30 ) ;
T_1 V_25 ;
if ( V_15 -> V_13 . V_32 & V_33 )
goto V_55;
V_53 = F_34 ( V_49 -> V_56 ) & ~ 0x7 ;
V_54 = V_53 + ( F_34 ( F_35 ( V_47 ) -> V_57 ) -
( ( T_1 * ) ( V_49 + 1 ) - ( T_1 * ) ( F_35 ( V_47 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_54 > V_58 ) {
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_59 ) ;
F_37 ( V_47 , V_60 ,
( ( T_1 * ) & V_49 -> V_56 -
F_38 ( V_47 ) ) ) ;
return - 1 ;
}
V_25 = F_1 ( F_35 ( V_47 ) ) ;
if ( V_47 -> V_61 == V_62 ) {
const unsigned char * V_63 = F_38 ( V_47 ) ;
V_47 -> V_64 = F_39 ( V_47 -> V_64 ,
F_40 ( V_63 , ( T_1 * ) ( V_49 + 1 ) - V_63 ,
0 ) ) ;
}
if ( ! ( V_49 -> V_56 & F_41 ( V_65 ) ) ) {
if ( V_54 < V_15 -> V_13 . V_66 ||
( ( V_15 -> V_13 . V_32 & V_67 ) && V_54 != V_15 -> V_13 . V_66 ) )
goto V_55;
V_15 -> V_13 . V_32 |= V_67 ;
V_15 -> V_13 . V_66 = V_54 ;
} else {
if ( V_54 & 0x7 ) {
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_59 ) ;
F_37 ( V_47 , V_60 ,
F_42 ( struct V_1 , V_57 ) ) ;
return - 1 ;
}
if ( V_54 > V_15 -> V_13 . V_66 ) {
if ( V_15 -> V_13 . V_32 & V_67 )
goto V_55;
V_15 -> V_13 . V_66 = V_54 ;
}
}
if ( V_54 == V_53 )
goto V_55;
if ( ! F_43 ( V_47 , ( T_1 * ) ( V_49 + 1 ) - V_47 -> V_42 ) )
goto V_55;
if ( F_44 ( V_47 , V_54 - V_53 ) )
goto V_55;
V_51 = V_15 -> V_13 . V_68 ;
if ( ! V_51 || F_45 ( V_51 ) -> V_53 < V_53 ) {
V_52 = NULL ;
goto V_69;
}
V_51 = NULL ;
for ( V_52 = V_15 -> V_13 . V_39 ; V_52 != NULL ; V_52 = V_52 -> V_52 ) {
if ( F_45 ( V_52 ) -> V_53 >= V_53 )
break;
V_51 = V_52 ;
}
V_69:
if ( V_51 &&
( F_45 ( V_51 ) -> V_53 + V_51 -> V_66 ) > V_53 )
goto V_70;
if ( V_52 && F_45 ( V_52 ) -> V_53 < V_54 )
goto V_70;
F_45 ( V_47 ) -> V_53 = V_53 ;
V_47 -> V_52 = V_52 ;
if ( ! V_52 )
V_15 -> V_13 . V_68 = V_47 ;
if ( V_51 )
V_51 -> V_52 = V_47 ;
else
V_15 -> V_13 . V_39 = V_47 ;
V_30 = V_47 -> V_30 ;
if ( V_30 ) {
V_15 -> V_22 = V_30 -> V_71 ;
V_47 -> V_30 = NULL ;
}
V_15 -> V_13 . V_72 = V_47 -> V_73 ;
V_15 -> V_13 . V_74 += V_47 -> V_66 ;
V_15 -> V_25 |= V_25 ;
F_46 ( V_15 -> V_13 . V_26 , V_47 -> V_75 ) ;
if ( V_53 == 0 ) {
V_15 -> V_76 = V_50 ;
V_15 -> V_13 . V_32 |= V_38 ;
}
if ( V_15 -> V_13 . V_32 == ( V_38 | V_67 ) &&
V_15 -> V_13 . V_74 == V_15 -> V_13 . V_66 ) {
int V_77 ;
unsigned long V_78 = V_47 -> V_79 ;
V_47 -> V_79 = 0UL ;
V_77 = F_47 ( V_15 , V_51 , V_30 ) ;
V_47 -> V_79 = V_78 ;
return V_77 ;
}
F_48 ( V_47 ) ;
return - 1 ;
V_70:
F_15 ( & V_15 -> V_13 , & V_8 ) ;
V_55:
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_36 ) ;
F_49 ( V_47 ) ;
return - 1 ;
}
static int F_47 ( struct V_14 * V_15 , struct V_46 * V_51 ,
struct V_29 * V_30 )
{
struct V_26 * V_26 = F_8 ( V_15 -> V_13 . V_26 , struct V_26 , V_43 . V_28 ) ;
struct V_46 * V_80 , * V_81 = V_15 -> V_13 . V_39 ;
int V_57 ;
unsigned int V_50 ;
int V_82 ;
T_1 V_25 ;
F_15 ( & V_15 -> V_13 , & V_8 ) ;
V_25 = V_83 [ V_15 -> V_25 ] ;
if ( F_50 ( V_25 == 0xff ) )
goto V_84;
if ( V_51 ) {
V_81 = V_51 -> V_52 ;
V_80 = F_51 ( V_81 , V_85 ) ;
if ( ! V_80 )
goto V_86;
V_80 -> V_52 = V_81 -> V_52 ;
if ( ! V_80 -> V_52 )
V_15 -> V_13 . V_68 = V_80 ;
V_51 -> V_52 = V_80 ;
F_52 ( V_81 , V_15 -> V_13 . V_39 ) ;
V_81 -> V_52 = V_15 -> V_13 . V_39 -> V_52 ;
F_53 ( V_15 -> V_13 . V_39 ) ;
V_15 -> V_13 . V_39 = V_81 ;
}
F_54 ( V_81 == NULL ) ;
F_54 ( F_45 ( V_81 ) -> V_53 != 0 ) ;
V_57 = ( ( V_81 -> V_42 - F_38 ( V_81 ) ) -
sizeof( struct V_1 ) + V_15 -> V_13 . V_66 -
sizeof( struct V_48 ) ) ;
if ( V_57 > V_58 )
goto V_87;
if ( F_55 ( V_81 , V_85 ) )
goto V_86;
if ( F_56 ( V_81 ) ) {
struct V_46 * V_88 ;
int V_89 , V_90 = 0 ;
V_88 = F_57 ( 0 , V_85 ) ;
if ( ! V_88 )
goto V_86;
V_88 -> V_52 = V_81 -> V_52 ;
V_81 -> V_52 = V_88 ;
F_58 ( V_88 ) -> V_91 = F_58 ( V_81 ) -> V_91 ;
F_59 ( V_81 ) ;
for ( V_89 = 0 ; V_89 < F_58 ( V_81 ) -> V_92 ; V_89 ++ )
V_90 += F_60 ( & F_58 ( V_81 ) -> V_28 [ V_89 ] ) ;
V_88 -> V_66 = V_88 -> V_93 = V_81 -> V_93 - V_90 ;
V_81 -> V_93 -= V_88 -> V_66 ;
V_81 -> V_66 -= V_88 -> V_66 ;
V_88 -> V_64 = 0 ;
V_88 -> V_61 = V_81 -> V_61 ;
F_46 ( V_15 -> V_13 . V_26 , V_88 -> V_75 ) ;
}
V_50 = V_15 -> V_76 ;
F_38 ( V_81 ) [ V_50 ] = F_61 ( V_81 ) [ 0 ] ;
memmove ( V_81 -> V_81 + sizeof( struct V_48 ) , V_81 -> V_81 ,
( V_81 -> V_42 - V_81 -> V_81 ) - sizeof( struct V_48 ) ) ;
V_81 -> V_94 += sizeof( struct V_48 ) ;
V_81 -> V_95 += sizeof( struct V_48 ) ;
F_62 ( V_81 ) ;
F_63 ( V_81 , V_81 -> V_42 - F_38 ( V_81 ) ) ;
V_82 = V_81 -> V_75 ;
for ( V_80 = V_81 -> V_52 ; V_80 ; ) {
bool V_96 ;
int V_97 ;
struct V_46 * V_52 = V_80 -> V_52 ;
V_82 += V_80 -> V_75 ;
if ( V_81 -> V_61 != V_80 -> V_61 )
V_81 -> V_61 = V_98 ;
else if ( V_81 -> V_61 == V_62 )
V_81 -> V_64 = F_64 ( V_81 -> V_64 , V_80 -> V_64 ) ;
if ( F_65 ( V_81 , V_80 , & V_96 , & V_97 ) ) {
F_66 ( V_80 , V_96 ) ;
} else {
if ( ! F_58 ( V_81 ) -> V_91 )
F_58 ( V_81 ) -> V_91 = V_80 ;
V_81 -> V_93 += V_80 -> V_66 ;
V_81 -> V_66 += V_80 -> V_66 ;
V_81 -> V_75 += V_80 -> V_75 ;
}
V_80 = V_52 ;
}
F_67 ( V_15 -> V_13 . V_26 , V_82 ) ;
V_81 -> V_52 = NULL ;
V_81 -> V_30 = V_30 ;
V_81 -> V_73 = V_15 -> V_13 . V_72 ;
F_35 ( V_81 ) -> V_57 = F_41 ( V_57 ) ;
F_68 ( F_35 ( V_81 ) , 0xff , V_25 ) ;
F_69 ( V_81 ) -> V_50 = V_50 ;
F_69 ( V_81 ) -> V_32 |= V_99 ;
if ( V_81 -> V_61 == V_62 )
V_81 -> V_64 = F_40 ( F_38 ( V_81 ) ,
F_70 ( V_81 ) ,
V_81 -> V_64 ) ;
F_16 () ;
F_18 ( V_26 , F_19 ( V_30 ) , V_100 ) ;
F_22 () ;
V_15 -> V_13 . V_39 = NULL ;
V_15 -> V_13 . V_68 = NULL ;
return 1 ;
V_87:
F_71 ( L_1 , V_57 ) ;
goto V_84;
V_86:
F_71 ( L_2 ) ;
V_84:
F_16 () ;
F_18 ( V_26 , F_19 ( V_30 ) , V_36 ) ;
F_22 () ;
return - 1 ;
}
static int F_72 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_14 * V_15 ;
const struct V_1 * V_101 = F_35 ( V_47 ) ;
struct V_26 * V_26 = F_32 ( F_33 ( V_47 ) -> V_30 ) ;
if ( F_69 ( V_47 ) -> V_32 & V_99 )
goto V_102;
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) , V_103 ) ;
if ( V_101 -> V_57 == 0 )
goto V_102;
if ( ! F_73 ( V_47 , ( F_74 ( V_47 ) +
sizeof( struct V_48 ) ) ) )
goto V_102;
V_101 = F_35 ( V_47 ) ;
V_49 = (struct V_48 * ) F_61 ( V_47 ) ;
if ( ! ( V_49 -> V_56 & F_41 ( 0xFFF9 ) ) ) {
V_47 -> V_104 += sizeof( struct V_48 ) ;
F_18 ( V_26 ,
F_36 ( F_33 ( V_47 ) ) , V_100 ) ;
F_69 ( V_47 ) -> V_50 = ( T_1 * ) V_49 - F_38 ( V_47 ) ;
F_69 ( V_47 ) -> V_32 |= V_99 ;
return 1 ;
}
V_15 = F_26 ( V_26 , V_49 -> V_105 , & V_101 -> V_6 , & V_101 -> V_7 ,
V_47 -> V_30 ? V_47 -> V_30 -> V_71 : 0 , F_1 ( V_101 ) ) ;
if ( V_15 ) {
int V_106 ;
F_14 ( & V_15 -> V_13 . V_31 ) ;
V_106 = F_31 ( V_15 , V_47 , V_49 , F_69 ( V_47 ) -> V_50 ) ;
F_23 ( & V_15 -> V_13 . V_31 ) ;
F_24 ( & V_15 -> V_13 , & V_8 ) ;
return V_106 ;
}
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) , V_36 ) ;
F_49 ( V_47 ) ;
return - 1 ;
V_102:
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_59 ) ;
F_37 ( V_47 , V_60 , F_70 ( V_47 ) ) ;
return - 1 ;
}
static int T_3 F_75 ( struct V_26 * V_26 )
{
struct V_107 * V_108 ;
struct V_109 * V_101 ;
V_108 = V_110 ;
if ( ! F_76 ( V_26 , & V_111 ) ) {
V_108 = F_77 ( V_108 , sizeof( V_110 ) , V_112 ) ;
if ( ! V_108 )
goto V_113;
V_108 [ 0 ] . V_42 = & V_26 -> V_43 . V_28 . V_114 ;
V_108 [ 0 ] . V_115 = & V_26 -> V_43 . V_28 . V_116 ;
V_108 [ 0 ] . V_117 = & V_111 . V_43 . V_28 . V_114 ;
V_108 [ 1 ] . V_42 = & V_26 -> V_43 . V_28 . V_116 ;
V_108 [ 1 ] . V_117 = & V_26 -> V_43 . V_28 . V_114 ;
V_108 [ 2 ] . V_42 = & V_26 -> V_43 . V_28 . V_118 ;
if ( V_26 -> V_119 != & V_120 )
V_108 [ 0 ] . V_121 = NULL ;
}
V_101 = F_78 ( V_26 , L_3 , V_108 ) ;
if ( ! V_101 )
goto V_122;
V_26 -> V_43 . V_123 . V_124 = V_101 ;
return 0 ;
V_122:
if ( ! F_76 ( V_26 , & V_111 ) )
F_79 ( V_108 ) ;
V_113:
return - V_125 ;
}
static void T_4 F_80 ( struct V_26 * V_26 )
{
struct V_107 * V_108 ;
V_108 = V_26 -> V_43 . V_123 . V_124 -> V_126 ;
F_81 ( V_26 -> V_43 . V_123 . V_124 ) ;
if ( ! F_76 ( V_26 , & V_111 ) )
F_79 ( V_108 ) ;
}
static int F_82 ( void )
{
V_127 = F_78 ( & V_111 , L_3 ,
V_128 ) ;
return V_127 == NULL ? - V_125 : 0 ;
}
static void F_83 ( void )
{
F_81 ( V_127 ) ;
}
static int F_75 ( struct V_26 * V_26 )
{
return 0 ;
}
static void F_80 ( struct V_26 * V_26 )
{
}
static int F_82 ( void )
{
return 0 ;
}
static void F_83 ( void )
{
}
static int T_3 F_84 ( struct V_26 * V_26 )
{
int V_77 ;
V_26 -> V_43 . V_28 . V_114 = V_129 ;
V_26 -> V_43 . V_28 . V_116 = V_130 ;
V_26 -> V_43 . V_28 . V_118 = V_131 ;
V_77 = F_85 ( & V_26 -> V_43 . V_28 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_75 ( V_26 ) ;
if ( V_77 )
F_86 ( & V_26 -> V_43 . V_28 ) ;
return V_77 ;
}
static void T_4 F_87 ( struct V_26 * V_26 )
{
F_80 ( V_26 ) ;
F_88 ( & V_26 -> V_43 . V_28 , & V_8 ) ;
}
int T_5 F_89 ( void )
{
int V_106 ;
V_106 = F_90 ( & V_132 , V_133 ) ;
if ( V_106 )
goto V_34;
V_106 = F_82 () ;
if ( V_106 )
goto V_134;
V_106 = F_91 ( & V_135 ) ;
if ( V_106 )
goto V_136;
V_8 . V_137 = F_7 ;
V_8 . V_138 = F_12 ;
V_8 . V_139 = NULL ;
V_8 . V_140 = sizeof( struct V_14 ) ;
V_8 . V_141 = F_9 ;
V_8 . V_142 = F_25 ;
V_8 . V_143 = V_144 ;
V_106 = F_92 ( & V_8 ) ;
if ( V_106 )
goto V_136;
V_34:
return V_106 ;
V_136:
F_83 () ;
V_134:
F_93 ( & V_132 , V_133 ) ;
goto V_34;
}
void F_94 ( void )
{
F_95 ( & V_8 ) ;
F_83 () ;
F_96 ( & V_135 ) ;
F_93 ( & V_132 , V_133 ) ;
}
