unsigned int F_1 ( T_1 V_1 , const struct V_2 * V_3 ,
const struct V_2 * V_4 , T_2 V_5 )
{
T_2 V_6 ;
V_6 = F_2 ( F_3 ( V_3 ) , F_3 ( V_4 ) ,
( V_7 T_2 ) V_1 , V_5 ) ;
return V_6 & ( V_8 - 1 ) ;
}
static unsigned int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 , struct V_11 , V_10 ) ;
return F_1 ( V_12 -> V_1 , & V_12 -> V_3 , & V_12 -> V_4 , V_13 . V_5 ) ;
}
bool F_6 ( struct V_9 * V_10 , void * V_14 )
{
struct V_11 * V_12 ;
struct V_15 * V_16 = V_14 ;
V_12 = F_5 ( V_10 , struct V_11 , V_10 ) ;
return V_12 -> V_1 == V_16 -> V_1 &&
V_12 -> V_17 == V_16 -> V_17 &&
F_7 ( & V_12 -> V_3 , V_16 -> V_18 ) &&
F_7 ( & V_12 -> V_4 , V_16 -> V_19 ) ;
}
void F_8 ( struct V_9 * V_10 , void * V_14 )
{
struct V_11 * V_12 = F_5 ( V_10 , struct V_11 , V_10 ) ;
struct V_15 * V_16 = V_14 ;
V_12 -> V_1 = V_16 -> V_1 ;
V_12 -> V_17 = V_16 -> V_17 ;
V_12 -> V_3 = * V_16 -> V_18 ;
V_12 -> V_4 = * V_16 -> V_19 ;
}
void F_9 ( struct V_20 * V_20 , struct V_11 * V_12 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = NULL ;
F_10 ( & V_12 -> V_10 . V_25 ) ;
if ( V_12 -> V_10 . V_26 & V_27 )
goto V_28;
F_11 ( & V_12 -> V_10 , V_22 ) ;
F_12 () ;
V_24 = F_13 ( V_20 , V_12 -> V_29 ) ;
if ( ! V_24 )
goto V_30;
F_14 ( V_20 , F_15 ( V_24 ) , V_31 ) ;
F_14 ( V_20 , F_15 ( V_24 ) , V_32 ) ;
if ( ! ( V_12 -> V_10 . V_26 & V_33 ) || ! V_12 -> V_10 . V_34 )
goto V_30;
V_12 -> V_10 . V_34 -> V_24 = V_24 ;
F_16 ( V_12 -> V_10 . V_34 , V_35 , V_36 , 0 ) ;
V_30:
F_17 () ;
V_28:
F_18 ( & V_12 -> V_10 . V_25 ) ;
F_19 ( & V_12 -> V_10 , V_22 ) ;
}
static void F_20 ( unsigned long V_37 )
{
struct V_11 * V_12 ;
struct V_20 * V_20 ;
V_12 = F_5 ( (struct V_9 * ) V_37 , struct V_11 , V_10 ) ;
V_20 = F_5 ( V_12 -> V_10 . V_20 , struct V_20 , V_38 . V_22 ) ;
F_9 ( V_20 , V_12 , & V_13 ) ;
}
int F_21 ( struct V_11 * V_12 , struct V_39 * V_40 ,
struct V_41 * V_42 , int V_43 )
{
struct V_39 * V_44 , * V_45 ;
struct V_23 * V_24 ;
int V_46 , V_47 ;
struct V_20 * V_20 = F_22 ( F_23 ( V_40 ) -> V_24 ) ;
if ( V_12 -> V_10 . V_26 & V_27 )
goto V_48;
V_46 = F_24 ( V_42 -> V_49 ) & ~ 0x7 ;
V_47 = V_46 + ( F_24 ( F_25 ( V_40 ) -> V_50 ) -
( ( V_51 * ) ( V_42 + 1 ) - ( V_51 * ) ( F_25 ( V_40 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_47 > V_52 ) {
F_14 ( V_20 , F_26 ( F_23 ( V_40 ) ) ,
V_53 ) ;
F_27 ( V_40 , V_54 ,
( ( V_51 * ) & V_42 -> V_49 -
F_28 ( V_40 ) ) ) ;
return - 1 ;
}
if ( V_40 -> V_55 == V_56 ) {
const unsigned char * V_57 = F_28 ( V_40 ) ;
V_40 -> V_58 = F_29 ( V_40 -> V_58 ,
F_30 ( V_57 , ( V_51 * ) ( V_42 + 1 ) - V_57 ,
0 ) ) ;
}
if ( ! ( V_42 -> V_49 & F_31 ( V_59 ) ) ) {
if ( V_47 < V_12 -> V_10 . V_60 ||
( ( V_12 -> V_10 . V_26 & V_61 ) && V_47 != V_12 -> V_10 . V_60 ) )
goto V_48;
V_12 -> V_10 . V_26 |= V_61 ;
V_12 -> V_10 . V_60 = V_47 ;
} else {
if ( V_47 & 0x7 ) {
F_14 ( V_20 , F_26 ( F_23 ( V_40 ) ) ,
V_53 ) ;
F_27 ( V_40 , V_54 ,
F_32 ( struct V_62 , V_50 ) ) ;
return - 1 ;
}
if ( V_47 > V_12 -> V_10 . V_60 ) {
if ( V_12 -> V_10 . V_26 & V_61 )
goto V_48;
V_12 -> V_10 . V_60 = V_47 ;
}
}
if ( V_47 == V_46 )
goto V_48;
if ( ! F_33 ( V_40 , ( V_51 * ) ( V_42 + 1 ) - V_40 -> V_37 ) )
goto V_48;
if ( F_34 ( V_40 , V_47 - V_46 ) )
goto V_48;
V_44 = V_12 -> V_10 . V_63 ;
if ( ! V_44 || F_35 ( V_44 ) -> V_46 < V_46 ) {
V_45 = NULL ;
goto V_64;
}
V_44 = NULL ;
for( V_45 = V_12 -> V_10 . V_34 ; V_45 != NULL ; V_45 = V_45 -> V_45 ) {
if ( F_35 ( V_45 ) -> V_46 >= V_46 )
break;
V_44 = V_45 ;
}
V_64:
if ( V_44 &&
( F_35 ( V_44 ) -> V_46 + V_44 -> V_60 ) > V_46 )
goto V_65;
if ( V_45 && F_35 ( V_45 ) -> V_46 < V_47 )
goto V_65;
F_35 ( V_40 ) -> V_46 = V_46 ;
V_40 -> V_45 = V_45 ;
if ( ! V_45 )
V_12 -> V_10 . V_63 = V_40 ;
if ( V_44 )
V_44 -> V_45 = V_40 ;
else
V_12 -> V_10 . V_34 = V_40 ;
V_24 = V_40 -> V_24 ;
if ( V_24 ) {
V_12 -> V_29 = V_24 -> V_66 ;
V_40 -> V_24 = NULL ;
}
V_12 -> V_10 . V_67 = V_40 -> V_68 ;
V_12 -> V_10 . V_69 += V_40 -> V_60 ;
F_36 ( & V_12 -> V_10 , V_40 -> V_70 ) ;
if ( V_46 == 0 ) {
V_12 -> V_71 = V_43 ;
V_12 -> V_10 . V_26 |= V_33 ;
}
if ( V_12 -> V_10 . V_26 == ( V_33 | V_61 ) &&
V_12 -> V_10 . V_69 == V_12 -> V_10 . V_60 ) {
int V_72 ;
unsigned long V_73 = V_40 -> V_74 ;
V_40 -> V_74 = 0UL ;
V_72 = F_37 ( V_12 , V_44 , V_24 ) ;
V_40 -> V_74 = V_73 ;
return V_72 ;
}
F_38 ( V_40 ) ;
F_39 ( & V_12 -> V_10 ) ;
return - 1 ;
V_65:
F_11 ( & V_12 -> V_10 , & V_13 ) ;
V_48:
F_40 ( V_20 , F_26 ( F_23 ( V_40 ) ) ,
V_32 ) ;
F_41 ( V_40 ) ;
return - 1 ;
}
static int F_37 ( struct V_11 * V_12 , struct V_39 * V_44 ,
struct V_23 * V_24 )
{
struct V_20 * V_20 = F_5 ( V_12 -> V_10 . V_20 , struct V_20 , V_38 . V_22 ) ;
struct V_39 * V_75 , * V_76 = V_12 -> V_10 . V_34 ;
int V_50 ;
unsigned int V_43 ;
int V_77 ;
F_11 ( & V_12 -> V_10 , & V_13 ) ;
if ( V_44 ) {
V_76 = V_44 -> V_45 ;
V_75 = F_42 ( V_76 , V_78 ) ;
if ( ! V_75 )
goto V_79;
V_75 -> V_45 = V_76 -> V_45 ;
if ( ! V_75 -> V_45 )
V_12 -> V_10 . V_63 = V_75 ;
V_44 -> V_45 = V_75 ;
F_43 ( V_76 , V_12 -> V_10 . V_34 ) ;
V_76 -> V_45 = V_12 -> V_10 . V_34 -> V_45 ;
F_44 ( V_12 -> V_10 . V_34 ) ;
V_12 -> V_10 . V_34 = V_76 ;
}
F_45 ( V_76 == NULL ) ;
F_45 ( F_35 ( V_76 ) -> V_46 != 0 ) ;
V_50 = ( ( V_76 -> V_37 - F_28 ( V_76 ) ) -
sizeof( struct V_62 ) + V_12 -> V_10 . V_60 -
sizeof( struct V_41 ) ) ;
if ( V_50 > V_52 )
goto V_80;
if ( F_46 ( V_76 , V_78 ) )
goto V_79;
if ( F_47 ( V_76 ) ) {
struct V_39 * V_81 ;
int V_82 , V_83 = 0 ;
if ( ( V_81 = F_48 ( 0 , V_78 ) ) == NULL )
goto V_79;
V_81 -> V_45 = V_76 -> V_45 ;
V_76 -> V_45 = V_81 ;
F_49 ( V_81 ) -> V_84 = F_49 ( V_76 ) -> V_84 ;
F_50 ( V_76 ) ;
for ( V_82 = 0 ; V_82 < F_49 ( V_76 ) -> V_85 ; V_82 ++ )
V_83 += F_51 ( & F_49 ( V_76 ) -> V_22 [ V_82 ] ) ;
V_81 -> V_60 = V_81 -> V_86 = V_76 -> V_86 - V_83 ;
V_76 -> V_86 -= V_81 -> V_60 ;
V_76 -> V_60 -= V_81 -> V_60 ;
V_81 -> V_58 = 0 ;
V_81 -> V_55 = V_76 -> V_55 ;
F_36 ( & V_12 -> V_10 , V_81 -> V_70 ) ;
}
V_43 = V_12 -> V_71 ;
F_28 ( V_76 ) [ V_43 ] = F_52 ( V_76 ) [ 0 ] ;
memmove ( V_76 -> V_76 + sizeof( struct V_41 ) , V_76 -> V_76 ,
( V_76 -> V_37 - V_76 -> V_76 ) - sizeof( struct V_41 ) ) ;
V_76 -> V_87 += sizeof( struct V_41 ) ;
V_76 -> V_88 += sizeof( struct V_41 ) ;
F_53 ( V_76 ) ;
F_54 ( V_76 , V_76 -> V_37 - F_28 ( V_76 ) ) ;
V_77 = V_76 -> V_70 ;
for ( V_75 = V_76 -> V_45 ; V_75 ; ) {
bool V_89 ;
int V_90 ;
struct V_39 * V_45 = V_75 -> V_45 ;
V_77 += V_75 -> V_70 ;
if ( V_76 -> V_55 != V_75 -> V_55 )
V_76 -> V_55 = V_91 ;
else if ( V_76 -> V_55 == V_56 )
V_76 -> V_58 = F_55 ( V_76 -> V_58 , V_75 -> V_58 ) ;
if ( F_56 ( V_76 , V_75 , & V_89 , & V_90 ) ) {
F_57 ( V_75 , V_89 ) ;
} else {
if ( ! F_49 ( V_76 ) -> V_84 )
F_49 ( V_76 ) -> V_84 = V_75 ;
V_76 -> V_86 += V_75 -> V_60 ;
V_76 -> V_60 += V_75 -> V_60 ;
V_76 -> V_70 += V_75 -> V_70 ;
}
V_75 = V_45 ;
}
F_58 ( & V_12 -> V_10 , V_77 ) ;
V_76 -> V_45 = NULL ;
V_76 -> V_24 = V_24 ;
V_76 -> V_68 = V_12 -> V_10 . V_67 ;
F_25 ( V_76 ) -> V_50 = F_31 ( V_50 ) ;
F_59 ( V_76 ) -> V_43 = V_43 ;
if ( V_76 -> V_55 == V_56 )
V_76 -> V_58 = F_30 ( F_28 ( V_76 ) ,
F_60 ( V_76 ) ,
V_76 -> V_58 ) ;
F_12 () ;
F_14 ( V_20 , F_15 ( V_24 ) , V_92 ) ;
F_17 () ;
V_12 -> V_10 . V_34 = NULL ;
V_12 -> V_10 . V_63 = NULL ;
return 1 ;
V_80:
F_61 ( L_1 , V_50 ) ;
goto V_93;
V_79:
F_61 ( L_2 ) ;
V_93:
F_12 () ;
F_14 ( V_20 , F_15 ( V_24 ) , V_32 ) ;
F_17 () ;
return - 1 ;
}
static int F_62 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_11 * V_12 ;
const struct V_62 * V_94 = F_25 ( V_40 ) ;
struct V_20 * V_20 = F_22 ( F_23 ( V_40 ) -> V_24 ) ;
int V_95 ;
F_14 ( V_20 , F_26 ( F_23 ( V_40 ) ) , V_96 ) ;
if ( V_94 -> V_50 == 0 )
goto V_97;
if ( ! F_63 ( V_40 , ( F_64 ( V_40 ) +
sizeof( struct V_41 ) ) ) )
goto V_97;
V_94 = F_25 ( V_40 ) ;
V_42 = (struct V_41 * ) F_52 ( V_40 ) ;
if ( ! ( V_42 -> V_49 & F_31 ( 0xFFF9 ) ) ) {
V_40 -> V_98 += sizeof( struct V_41 ) ;
F_14 ( V_20 ,
F_26 ( F_23 ( V_40 ) ) , V_92 ) ;
F_59 ( V_40 ) -> V_43 = ( V_51 * ) V_42 - F_28 ( V_40 ) ;
return 1 ;
}
V_95 = F_65 ( & V_20 -> V_38 . V_22 , & V_13 , false ) ;
if ( V_95 )
F_66 ( V_20 , F_26 ( F_23 ( V_40 ) ) ,
V_32 , V_95 ) ;
V_12 = F_67 ( V_20 , V_42 -> V_99 , & V_94 -> V_3 , & V_94 -> V_4 ) ;
if ( V_12 != NULL ) {
int V_100 ;
F_10 ( & V_12 -> V_10 . V_25 ) ;
V_100 = F_21 ( V_12 , V_40 , V_42 , F_59 ( V_40 ) -> V_43 ) ;
F_18 ( & V_12 -> V_10 . V_25 ) ;
F_19 ( & V_12 -> V_10 , & V_13 ) ;
return V_100 ;
}
F_14 ( V_20 , F_26 ( F_23 ( V_40 ) ) , V_32 ) ;
F_41 ( V_40 ) ;
return - 1 ;
V_97:
F_40 ( V_20 , F_26 ( F_23 ( V_40 ) ) , V_53 ) ;
F_27 ( V_40 , V_54 , F_60 ( V_40 ) ) ;
return - 1 ;
}
static int T_3 F_68 ( struct V_20 * V_20 )
{
struct V_101 * V_102 ;
struct V_103 * V_94 ;
V_102 = V_104 ;
if ( ! F_69 ( V_20 , & V_105 ) ) {
V_102 = F_70 ( V_102 , sizeof( V_104 ) , V_106 ) ;
if ( V_102 == NULL )
goto V_107;
V_102 [ 0 ] . V_37 = & V_20 -> V_38 . V_22 . V_108 ;
V_102 [ 1 ] . V_37 = & V_20 -> V_38 . V_22 . V_109 ;
V_102 [ 2 ] . V_37 = & V_20 -> V_38 . V_22 . V_110 ;
if ( V_20 -> V_111 != & V_112 )
V_102 [ 0 ] . V_113 = NULL ;
}
V_94 = F_71 ( V_20 , L_3 , V_102 ) ;
if ( V_94 == NULL )
goto V_114;
V_20 -> V_38 . V_115 . V_116 = V_94 ;
return 0 ;
V_114:
if ( ! F_69 ( V_20 , & V_105 ) )
F_72 ( V_102 ) ;
V_107:
return - V_117 ;
}
static void T_4 F_73 ( struct V_20 * V_20 )
{
struct V_101 * V_102 ;
V_102 = V_20 -> V_38 . V_115 . V_116 -> V_118 ;
F_74 ( V_20 -> V_38 . V_115 . V_116 ) ;
if ( ! F_69 ( V_20 , & V_105 ) )
F_72 ( V_102 ) ;
}
static int F_75 ( void )
{
V_119 = F_71 ( & V_105 , L_3 ,
V_120 ) ;
return V_119 == NULL ? - V_117 : 0 ;
}
static void F_76 ( void )
{
F_74 ( V_119 ) ;
}
static inline int F_68 ( struct V_20 * V_20 )
{
return 0 ;
}
static inline void F_73 ( struct V_20 * V_20 )
{
}
static inline int F_75 ( void )
{
return 0 ;
}
static inline void F_76 ( void )
{
}
static int T_3 F_77 ( struct V_20 * V_20 )
{
V_20 -> V_38 . V_22 . V_108 = V_121 ;
V_20 -> V_38 . V_22 . V_109 = V_122 ;
V_20 -> V_38 . V_22 . V_110 = V_123 ;
F_78 ( & V_20 -> V_38 . V_22 ) ;
return F_68 ( V_20 ) ;
}
static void T_4 F_79 ( struct V_20 * V_20 )
{
F_73 ( V_20 ) ;
F_80 ( & V_20 -> V_38 . V_22 , & V_13 ) ;
}
int T_5 F_81 ( void )
{
int V_100 ;
V_100 = F_82 ( & V_124 , V_125 ) ;
if ( V_100 )
goto V_28;
V_100 = F_75 () ;
if ( V_100 )
goto V_126;
V_100 = F_83 ( & V_127 ) ;
if ( V_100 )
goto V_128;
V_13 . V_129 = F_4 ;
V_13 . V_130 = F_8 ;
V_13 . V_131 = NULL ;
V_13 . V_132 = NULL ;
V_13 . V_133 = sizeof( struct V_11 ) ;
V_13 . V_134 = F_6 ;
V_13 . V_135 = F_20 ;
V_13 . V_136 = 10 * 60 * V_137 ;
F_84 ( & V_13 ) ;
V_28:
return V_100 ;
V_128:
F_76 () ;
V_126:
F_85 ( & V_124 , V_125 ) ;
goto V_28;
}
void F_86 ( void )
{
F_87 ( & V_13 ) ;
F_76 () ;
F_88 ( & V_127 ) ;
F_85 ( & V_124 , V_125 ) ;
}
