unsigned int F_1 ( T_1 V_1 , const struct V_2 * V_3 ,
const struct V_2 * V_4 , T_2 V_5 )
{
T_2 V_6 ;
V_6 = F_2 ( ( V_7 T_2 ) V_3 -> V_8 [ 0 ] ,
( V_7 T_2 ) V_3 -> V_8 [ 1 ] ,
( V_7 T_2 ) V_3 -> V_8 [ 2 ] ,
V_5 ) ;
V_6 = F_2 ( ( V_7 T_2 ) V_3 -> V_8 [ 3 ] ,
( V_7 T_2 ) V_4 -> V_8 [ 0 ] ,
( V_7 T_2 ) V_4 -> V_8 [ 1 ] ,
V_6 ) ;
V_6 = F_2 ( ( V_7 T_2 ) V_4 -> V_8 [ 2 ] ,
( V_7 T_2 ) V_4 -> V_8 [ 3 ] ,
( V_7 T_2 ) V_1 ,
V_6 ) ;
return V_6 & ( V_9 - 1 ) ;
}
static unsigned int F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_11 , struct V_12 , V_11 ) ;
return F_1 ( V_13 -> V_1 , & V_13 -> V_3 , & V_13 -> V_4 , V_14 . V_5 ) ;
}
bool F_5 ( struct V_10 * V_11 , void * V_15 )
{
struct V_12 * V_13 ;
struct V_16 * V_17 = V_15 ;
V_13 = F_4 ( V_11 , struct V_12 , V_11 ) ;
return V_13 -> V_1 == V_17 -> V_1 &&
V_13 -> V_18 == V_17 -> V_18 &&
F_6 ( & V_13 -> V_3 , V_17 -> V_19 ) &&
F_6 ( & V_13 -> V_4 , V_17 -> V_20 ) ;
}
void F_7 ( struct V_10 * V_11 , void * V_15 )
{
struct V_12 * V_13 = F_4 ( V_11 , struct V_12 , V_11 ) ;
struct V_16 * V_17 = V_15 ;
V_13 -> V_1 = V_17 -> V_1 ;
V_13 -> V_18 = V_17 -> V_18 ;
V_13 -> V_3 = * V_17 -> V_19 ;
V_13 -> V_4 = * V_17 -> V_20 ;
}
void F_8 ( struct V_21 * V_21 , struct V_12 * V_13 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = NULL ;
F_9 ( & V_13 -> V_11 . V_26 ) ;
if ( V_13 -> V_11 . V_27 & V_28 )
goto V_29;
F_10 ( & V_13 -> V_11 , V_23 ) ;
F_11 () ;
V_25 = F_12 ( V_21 , V_13 -> V_30 ) ;
if ( ! V_25 )
goto V_31;
F_13 ( V_21 , F_14 ( V_25 ) , V_32 ) ;
F_13 ( V_21 , F_14 ( V_25 ) , V_33 ) ;
if ( ! ( V_13 -> V_11 . V_27 & V_34 ) || ! V_13 -> V_11 . V_35 )
goto V_31;
V_13 -> V_11 . V_35 -> V_25 = V_25 ;
F_15 ( V_13 -> V_11 . V_35 , V_36 , V_37 , 0 ) ;
V_31:
F_16 () ;
V_29:
F_17 ( & V_13 -> V_11 . V_26 ) ;
F_18 ( & V_13 -> V_11 , V_23 ) ;
}
static void F_19 ( unsigned long V_38 )
{
struct V_12 * V_13 ;
struct V_21 * V_21 ;
V_13 = F_4 ( (struct V_10 * ) V_38 , struct V_12 , V_11 ) ;
V_21 = F_4 ( V_13 -> V_11 . V_21 , struct V_21 , V_39 . V_23 ) ;
F_8 ( V_21 , V_13 , & V_14 ) ;
}
int F_20 ( struct V_12 * V_13 , struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 )
{
struct V_40 * V_45 , * V_46 ;
struct V_24 * V_25 ;
int V_47 , V_48 ;
struct V_21 * V_21 = F_21 ( F_22 ( V_41 ) -> V_25 ) ;
if ( V_13 -> V_11 . V_27 & V_28 )
goto V_49;
V_47 = F_23 ( V_43 -> V_50 ) & ~ 0x7 ;
V_48 = V_47 + ( F_23 ( F_24 ( V_41 ) -> V_51 ) -
( ( V_52 * ) ( V_43 + 1 ) - ( V_52 * ) ( F_24 ( V_41 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_48 > V_53 ) {
F_13 ( V_21 , F_25 ( F_22 ( V_41 ) ) ,
V_54 ) ;
F_26 ( V_41 , V_55 ,
( ( V_52 * ) & V_43 -> V_50 -
F_27 ( V_41 ) ) ) ;
return - 1 ;
}
if ( V_41 -> V_56 == V_57 ) {
const unsigned char * V_58 = F_27 ( V_41 ) ;
V_41 -> V_59 = F_28 ( V_41 -> V_59 ,
F_29 ( V_58 , ( V_52 * ) ( V_43 + 1 ) - V_58 ,
0 ) ) ;
}
if ( ! ( V_43 -> V_50 & F_30 ( V_60 ) ) ) {
if ( V_48 < V_13 -> V_11 . V_61 ||
( ( V_13 -> V_11 . V_27 & V_62 ) && V_48 != V_13 -> V_11 . V_61 ) )
goto V_49;
V_13 -> V_11 . V_27 |= V_62 ;
V_13 -> V_11 . V_61 = V_48 ;
} else {
if ( V_48 & 0x7 ) {
F_13 ( V_21 , F_25 ( F_22 ( V_41 ) ) ,
V_54 ) ;
F_26 ( V_41 , V_55 ,
F_31 ( struct V_63 , V_51 ) ) ;
return - 1 ;
}
if ( V_48 > V_13 -> V_11 . V_61 ) {
if ( V_13 -> V_11 . V_27 & V_62 )
goto V_49;
V_13 -> V_11 . V_61 = V_48 ;
}
}
if ( V_48 == V_47 )
goto V_49;
if ( ! F_32 ( V_41 , ( V_52 * ) ( V_43 + 1 ) - V_41 -> V_38 ) )
goto V_49;
if ( F_33 ( V_41 , V_48 - V_47 ) )
goto V_49;
V_45 = V_13 -> V_11 . V_64 ;
if ( ! V_45 || F_34 ( V_45 ) -> V_47 < V_47 ) {
V_46 = NULL ;
goto V_65;
}
V_45 = NULL ;
for( V_46 = V_13 -> V_11 . V_35 ; V_46 != NULL ; V_46 = V_46 -> V_46 ) {
if ( F_34 ( V_46 ) -> V_47 >= V_47 )
break;
V_45 = V_46 ;
}
V_65:
if ( V_45 &&
( F_34 ( V_45 ) -> V_47 + V_45 -> V_61 ) > V_47 )
goto V_66;
if ( V_46 && F_34 ( V_46 ) -> V_47 < V_48 )
goto V_66;
F_34 ( V_41 ) -> V_47 = V_47 ;
V_41 -> V_46 = V_46 ;
if ( ! V_46 )
V_13 -> V_11 . V_64 = V_41 ;
if ( V_45 )
V_45 -> V_46 = V_41 ;
else
V_13 -> V_11 . V_35 = V_41 ;
V_25 = V_41 -> V_25 ;
if ( V_25 ) {
V_13 -> V_30 = V_25 -> V_67 ;
V_41 -> V_25 = NULL ;
}
V_13 -> V_11 . V_68 = V_41 -> V_69 ;
V_13 -> V_11 . V_70 += V_41 -> V_61 ;
F_35 ( V_41 -> V_71 , & V_13 -> V_11 . V_21 -> V_72 ) ;
if ( V_47 == 0 ) {
V_13 -> V_73 = V_44 ;
V_13 -> V_11 . V_27 |= V_34 ;
}
if ( V_13 -> V_11 . V_27 == ( V_34 | V_62 ) &&
V_13 -> V_11 . V_70 == V_13 -> V_11 . V_61 )
return F_36 ( V_13 , V_45 , V_25 ) ;
F_37 ( & V_14 . V_26 ) ;
F_38 ( & V_13 -> V_11 . V_74 , & V_13 -> V_11 . V_21 -> V_74 ) ;
F_39 ( & V_14 . V_26 ) ;
return - 1 ;
V_66:
F_10 ( & V_13 -> V_11 , & V_14 ) ;
V_49:
F_40 ( V_21 , F_25 ( F_22 ( V_41 ) ) ,
V_33 ) ;
F_41 ( V_41 ) ;
return - 1 ;
}
static int F_36 ( struct V_12 * V_13 , struct V_40 * V_45 ,
struct V_24 * V_25 )
{
struct V_21 * V_21 = F_4 ( V_13 -> V_11 . V_21 , struct V_21 , V_39 . V_23 ) ;
struct V_40 * V_75 , * V_76 = V_13 -> V_11 . V_35 ;
int V_51 ;
unsigned int V_44 ;
int V_77 ;
F_10 ( & V_13 -> V_11 , & V_14 ) ;
if ( V_45 ) {
V_76 = V_45 -> V_46 ;
V_75 = F_42 ( V_76 , V_78 ) ;
if ( ! V_75 )
goto V_79;
V_75 -> V_46 = V_76 -> V_46 ;
if ( ! V_75 -> V_46 )
V_13 -> V_11 . V_64 = V_75 ;
V_45 -> V_46 = V_75 ;
F_43 ( V_76 , V_13 -> V_11 . V_35 ) ;
V_76 -> V_46 = V_13 -> V_11 . V_35 -> V_46 ;
F_44 ( V_13 -> V_11 . V_35 ) ;
V_13 -> V_11 . V_35 = V_76 ;
}
F_45 ( V_76 == NULL ) ;
F_45 ( F_34 ( V_76 ) -> V_47 != 0 ) ;
V_51 = ( ( V_76 -> V_38 - F_27 ( V_76 ) ) -
sizeof( struct V_63 ) + V_13 -> V_11 . V_61 -
sizeof( struct V_42 ) ) ;
if ( V_51 > V_53 )
goto V_80;
if ( F_46 ( V_76 ) && F_47 ( V_76 , 0 , 0 , V_78 ) )
goto V_79;
if ( F_48 ( V_76 ) ) {
struct V_40 * V_81 ;
int V_82 , V_83 = 0 ;
if ( ( V_81 = F_49 ( 0 , V_78 ) ) == NULL )
goto V_79;
V_81 -> V_46 = V_76 -> V_46 ;
V_76 -> V_46 = V_81 ;
F_50 ( V_81 ) -> V_84 = F_50 ( V_76 ) -> V_84 ;
F_51 ( V_76 ) ;
for ( V_82 = 0 ; V_82 < F_50 ( V_76 ) -> V_85 ; V_82 ++ )
V_83 += F_52 ( & F_50 ( V_76 ) -> V_23 [ V_82 ] ) ;
V_81 -> V_61 = V_81 -> V_86 = V_76 -> V_86 - V_83 ;
V_76 -> V_86 -= V_81 -> V_61 ;
V_76 -> V_61 -= V_81 -> V_61 ;
V_81 -> V_59 = 0 ;
V_81 -> V_56 = V_76 -> V_56 ;
F_35 ( V_81 -> V_71 , & V_13 -> V_11 . V_21 -> V_72 ) ;
}
V_44 = V_13 -> V_73 ;
F_27 ( V_76 ) [ V_44 ] = F_53 ( V_76 ) [ 0 ] ;
memmove ( V_76 -> V_76 + sizeof( struct V_42 ) , V_76 -> V_76 ,
( V_76 -> V_38 - V_76 -> V_76 ) - sizeof( struct V_42 ) ) ;
V_76 -> V_87 += sizeof( struct V_42 ) ;
V_76 -> V_88 += sizeof( struct V_42 ) ;
F_54 ( V_76 ) ;
F_55 ( V_76 , V_76 -> V_38 - F_27 ( V_76 ) ) ;
V_77 = V_76 -> V_71 ;
for ( V_75 = V_76 -> V_46 ; V_75 ; ) {
bool V_89 ;
int V_90 ;
struct V_40 * V_46 = V_75 -> V_46 ;
V_77 += V_75 -> V_71 ;
if ( V_76 -> V_56 != V_75 -> V_56 )
V_76 -> V_56 = V_91 ;
else if ( V_76 -> V_56 == V_57 )
V_76 -> V_59 = F_56 ( V_76 -> V_59 , V_75 -> V_59 ) ;
if ( F_57 ( V_76 , V_75 , & V_89 , & V_90 ) ) {
F_58 ( V_75 , V_89 ) ;
} else {
if ( ! F_50 ( V_76 ) -> V_84 )
F_50 ( V_76 ) -> V_84 = V_75 ;
V_76 -> V_86 += V_75 -> V_61 ;
V_76 -> V_61 += V_75 -> V_61 ;
V_76 -> V_71 += V_75 -> V_71 ;
}
V_75 = V_46 ;
}
F_59 ( V_77 , & V_13 -> V_11 . V_21 -> V_72 ) ;
V_76 -> V_46 = NULL ;
V_76 -> V_25 = V_25 ;
V_76 -> V_69 = V_13 -> V_11 . V_68 ;
F_24 ( V_76 ) -> V_51 = F_30 ( V_51 ) ;
F_60 ( V_76 ) -> V_44 = V_44 ;
if ( V_76 -> V_56 == V_57 )
V_76 -> V_59 = F_29 ( F_27 ( V_76 ) ,
F_61 ( V_76 ) ,
V_76 -> V_59 ) ;
F_11 () ;
F_13 ( V_21 , F_14 ( V_25 ) , V_92 ) ;
F_16 () ;
V_13 -> V_11 . V_35 = NULL ;
V_13 -> V_11 . V_64 = NULL ;
return 1 ;
V_80:
F_62 ( L_1 , V_51 ) ;
goto V_93;
V_79:
F_62 ( L_2 ) ;
V_93:
F_11 () ;
F_13 ( V_21 , F_14 ( V_25 ) , V_33 ) ;
F_16 () ;
return - 1 ;
}
static int F_63 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
struct V_12 * V_13 ;
const struct V_63 * V_94 = F_24 ( V_41 ) ;
struct V_21 * V_21 = F_21 ( F_22 ( V_41 ) -> V_25 ) ;
int V_95 ;
F_13 ( V_21 , F_25 ( F_22 ( V_41 ) ) , V_96 ) ;
if ( V_94 -> V_51 == 0 )
goto V_97;
if ( ! F_64 ( V_41 , ( F_65 ( V_41 ) +
sizeof( struct V_42 ) ) ) )
goto V_97;
V_94 = F_24 ( V_41 ) ;
V_43 = (struct V_42 * ) F_53 ( V_41 ) ;
if ( ! ( V_43 -> V_50 & F_30 ( 0xFFF9 ) ) ) {
V_41 -> V_98 += sizeof( struct V_42 ) ;
F_13 ( V_21 ,
F_25 ( F_22 ( V_41 ) ) , V_92 ) ;
F_60 ( V_41 ) -> V_44 = ( V_52 * ) V_43 - F_27 ( V_41 ) ;
return 1 ;
}
V_95 = F_66 ( & V_21 -> V_39 . V_23 , & V_14 , false ) ;
if ( V_95 )
F_67 ( V_21 , F_25 ( F_22 ( V_41 ) ) ,
V_33 , V_95 ) ;
V_13 = F_68 ( V_21 , V_43 -> V_99 , & V_94 -> V_3 , & V_94 -> V_4 ) ;
if ( V_13 != NULL ) {
int V_100 ;
F_9 ( & V_13 -> V_11 . V_26 ) ;
V_100 = F_20 ( V_13 , V_41 , V_43 , F_60 ( V_41 ) -> V_44 ) ;
F_17 ( & V_13 -> V_11 . V_26 ) ;
F_18 ( & V_13 -> V_11 , & V_14 ) ;
return V_100 ;
}
F_13 ( V_21 , F_25 ( F_22 ( V_41 ) ) , V_33 ) ;
F_41 ( V_41 ) ;
return - 1 ;
V_97:
F_40 ( V_21 , F_25 ( F_22 ( V_41 ) ) , V_54 ) ;
F_26 ( V_41 , V_55 , F_61 ( V_41 ) ) ;
return - 1 ;
}
static int T_3 F_69 ( struct V_21 * V_21 )
{
struct V_101 * V_102 ;
struct V_103 * V_94 ;
V_102 = V_104 ;
if ( ! F_70 ( V_21 , & V_105 ) ) {
V_102 = F_71 ( V_102 , sizeof( V_104 ) , V_106 ) ;
if ( V_102 == NULL )
goto V_107;
V_102 [ 0 ] . V_38 = & V_21 -> V_39 . V_23 . V_108 ;
V_102 [ 1 ] . V_38 = & V_21 -> V_39 . V_23 . V_109 ;
V_102 [ 2 ] . V_38 = & V_21 -> V_39 . V_23 . V_110 ;
if ( V_21 -> V_111 != & V_112 )
V_102 [ 0 ] . V_113 = NULL ;
}
V_94 = F_72 ( V_21 , L_3 , V_102 ) ;
if ( V_94 == NULL )
goto V_114;
V_21 -> V_39 . V_115 . V_116 = V_94 ;
return 0 ;
V_114:
if ( ! F_70 ( V_21 , & V_105 ) )
F_73 ( V_102 ) ;
V_107:
return - V_117 ;
}
static void T_4 F_74 ( struct V_21 * V_21 )
{
struct V_101 * V_102 ;
V_102 = V_21 -> V_39 . V_115 . V_116 -> V_118 ;
F_75 ( V_21 -> V_39 . V_115 . V_116 ) ;
if ( ! F_70 ( V_21 , & V_105 ) )
F_73 ( V_102 ) ;
}
static int F_76 ( void )
{
V_119 = F_72 ( & V_105 , L_3 ,
V_120 ) ;
return V_119 == NULL ? - V_117 : 0 ;
}
static void F_77 ( void )
{
F_75 ( V_119 ) ;
}
static inline int F_69 ( struct V_21 * V_21 )
{
return 0 ;
}
static inline void F_74 ( struct V_21 * V_21 )
{
}
static inline int F_76 ( void )
{
return 0 ;
}
static inline void F_77 ( void )
{
}
static int T_3 F_78 ( struct V_21 * V_21 )
{
V_21 -> V_39 . V_23 . V_108 = V_121 ;
V_21 -> V_39 . V_23 . V_109 = V_122 ;
V_21 -> V_39 . V_23 . V_110 = V_123 ;
F_79 ( & V_21 -> V_39 . V_23 ) ;
return F_69 ( V_21 ) ;
}
static void T_4 F_80 ( struct V_21 * V_21 )
{
F_74 ( V_21 ) ;
F_81 ( & V_21 -> V_39 . V_23 , & V_14 ) ;
}
int T_5 F_82 ( void )
{
int V_100 ;
V_100 = F_83 ( & V_124 , V_125 ) ;
if ( V_100 )
goto V_29;
V_100 = F_76 () ;
if ( V_100 )
goto V_126;
V_100 = F_84 ( & V_127 ) ;
if ( V_100 )
goto V_128;
V_14 . V_129 = F_3 ;
V_14 . V_130 = F_7 ;
V_14 . V_131 = NULL ;
V_14 . V_132 = NULL ;
V_14 . V_133 = sizeof( struct V_12 ) ;
V_14 . V_134 = F_5 ;
V_14 . V_135 = F_19 ;
V_14 . V_136 = 10 * 60 * V_137 ;
F_85 ( & V_14 ) ;
V_29:
return V_100 ;
V_128:
F_77 () ;
V_126:
F_86 ( & V_124 , V_125 ) ;
goto V_29;
}
void F_87 ( void )
{
F_88 ( & V_14 ) ;
F_77 () ;
F_89 ( & V_127 ) ;
F_86 ( & V_124 , V_125 ) ;
}
