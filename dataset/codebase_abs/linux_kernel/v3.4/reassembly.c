int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 . V_3 . V_4 ;
}
int F_2 ( struct V_1 * V_1 )
{
return F_3 ( & V_1 -> V_2 . V_3 . V_5 ) ;
}
unsigned int F_4 ( T_1 V_6 , const struct V_7 * V_8 ,
const struct V_7 * V_9 , T_2 V_10 )
{
T_2 V_11 ;
V_11 = F_5 ( ( V_12 T_2 ) V_8 -> V_13 [ 0 ] ,
( V_12 T_2 ) V_8 -> V_13 [ 1 ] ,
( V_12 T_2 ) V_8 -> V_13 [ 2 ] ,
V_10 ) ;
V_11 = F_5 ( ( V_12 T_2 ) V_8 -> V_13 [ 3 ] ,
( V_12 T_2 ) V_9 -> V_13 [ 0 ] ,
( V_12 T_2 ) V_9 -> V_13 [ 1 ] ,
V_11 ) ;
V_11 = F_5 ( ( V_12 T_2 ) V_9 -> V_13 [ 2 ] ,
( V_12 T_2 ) V_9 -> V_13 [ 3 ] ,
( V_12 T_2 ) V_6 ,
V_11 ) ;
return V_11 & ( V_14 - 1 ) ;
}
static unsigned int F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
V_18 = F_7 ( V_16 , struct V_17 , V_16 ) ;
return F_4 ( V_18 -> V_6 , & V_18 -> V_8 , & V_18 -> V_9 , V_19 . V_10 ) ;
}
int F_8 ( struct V_15 * V_16 , void * V_20 )
{
struct V_17 * V_18 ;
struct V_21 * V_22 = V_20 ;
V_18 = F_7 ( V_16 , struct V_17 , V_16 ) ;
return ( V_18 -> V_6 == V_22 -> V_6 && V_18 -> V_23 == V_22 -> V_23 &&
F_9 ( & V_18 -> V_8 , V_22 -> V_24 ) &&
F_9 ( & V_18 -> V_9 , V_22 -> V_25 ) ) ;
}
void F_10 ( struct V_15 * V_16 , void * V_20 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 , V_16 ) ;
struct V_21 * V_22 = V_20 ;
V_18 -> V_6 = V_22 -> V_6 ;
V_18 -> V_23 = V_22 -> V_23 ;
V_18 -> V_8 = * V_22 -> V_24 ;
V_18 -> V_9 = * V_22 -> V_25 ;
}
static T_3 void F_11 ( struct V_17 * V_18 )
{
F_12 ( & V_18 -> V_16 , & V_19 ) ;
}
static T_3 void F_13 ( struct V_17 * V_18 )
{
F_14 ( & V_18 -> V_16 , & V_19 ) ;
}
static void F_15 ( struct V_1 * V_1 , struct V_26 * V_27 )
{
int V_28 ;
V_28 = F_16 ( & V_1 -> V_2 . V_3 , & V_19 ) ;
if ( V_28 )
F_17 ( V_1 , V_27 , V_29 , V_28 ) ;
}
static void F_18 ( unsigned long V_30 )
{
struct V_17 * V_18 ;
struct V_31 * V_32 = NULL ;
struct V_1 * V_1 ;
V_18 = F_7 ( (struct V_15 * ) V_30 , struct V_17 , V_16 ) ;
F_19 ( & V_18 -> V_16 . V_33 ) ;
if ( V_18 -> V_16 . V_34 & V_35 )
goto V_36;
F_13 ( V_18 ) ;
V_1 = F_7 ( V_18 -> V_16 . V_1 , struct V_1 , V_2 . V_3 ) ;
F_20 () ;
V_32 = F_21 ( V_1 , V_18 -> V_37 ) ;
if ( ! V_32 )
goto V_38;
F_22 ( V_1 , F_23 ( V_32 ) , V_39 ) ;
F_22 ( V_1 , F_23 ( V_32 ) , V_29 ) ;
if ( ! ( V_18 -> V_16 . V_34 & V_40 ) || ! V_18 -> V_16 . V_41 )
goto V_38;
V_18 -> V_16 . V_41 -> V_32 = V_32 ;
F_24 ( V_18 -> V_16 . V_41 , V_42 , V_43 , 0 ) ;
V_38:
F_25 () ;
V_36:
F_26 ( & V_18 -> V_16 . V_33 ) ;
F_11 ( V_18 ) ;
}
int F_27 ( struct V_17 * V_18 , struct V_44 * V_45 ,
struct V_46 * V_47 , int V_48 )
{
struct V_44 * V_49 , * V_50 ;
struct V_31 * V_32 ;
int V_51 , V_52 ;
struct V_1 * V_1 = F_28 ( F_29 ( V_45 ) -> V_32 ) ;
if ( V_18 -> V_16 . V_34 & V_35 )
goto V_53;
V_51 = F_30 ( V_47 -> V_54 ) & ~ 0x7 ;
V_52 = V_51 + ( F_30 ( F_31 ( V_45 ) -> V_55 ) -
( ( V_56 * ) ( V_47 + 1 ) - ( V_56 * ) ( F_31 ( V_45 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_52 > V_57 ) {
F_22 ( V_1 , F_32 ( F_29 ( V_45 ) ) ,
V_58 ) ;
F_33 ( V_45 , V_59 ,
( ( V_56 * ) & V_47 -> V_54 -
F_34 ( V_45 ) ) ) ;
return - 1 ;
}
if ( V_45 -> V_60 == V_61 ) {
const unsigned char * V_62 = F_34 ( V_45 ) ;
V_45 -> V_63 = F_35 ( V_45 -> V_63 ,
F_36 ( V_62 , ( V_56 * ) ( V_47 + 1 ) - V_62 ,
0 ) ) ;
}
if ( ! ( V_47 -> V_54 & F_37 ( V_64 ) ) ) {
if ( V_52 < V_18 -> V_16 . V_65 ||
( ( V_18 -> V_16 . V_34 & V_66 ) && V_52 != V_18 -> V_16 . V_65 ) )
goto V_53;
V_18 -> V_16 . V_34 |= V_66 ;
V_18 -> V_16 . V_65 = V_52 ;
} else {
if ( V_52 & 0x7 ) {
F_22 ( V_1 , F_32 ( F_29 ( V_45 ) ) ,
V_58 ) ;
F_33 ( V_45 , V_59 ,
F_38 ( struct V_67 , V_55 ) ) ;
return - 1 ;
}
if ( V_52 > V_18 -> V_16 . V_65 ) {
if ( V_18 -> V_16 . V_34 & V_66 )
goto V_53;
V_18 -> V_16 . V_65 = V_52 ;
}
}
if ( V_52 == V_51 )
goto V_53;
if ( ! F_39 ( V_45 , ( V_56 * ) ( V_47 + 1 ) - V_45 -> V_30 ) )
goto V_53;
if ( F_40 ( V_45 , V_52 - V_51 ) )
goto V_53;
V_49 = V_18 -> V_16 . V_68 ;
if ( ! V_49 || F_41 ( V_49 ) -> V_51 < V_51 ) {
V_50 = NULL ;
goto V_69;
}
V_49 = NULL ;
for( V_50 = V_18 -> V_16 . V_41 ; V_50 != NULL ; V_50 = V_50 -> V_50 ) {
if ( F_41 ( V_50 ) -> V_51 >= V_51 )
break;
V_49 = V_50 ;
}
V_69:
if ( V_49 &&
( F_41 ( V_49 ) -> V_51 + V_49 -> V_65 ) > V_51 )
goto V_70;
if ( V_50 && F_41 ( V_50 ) -> V_51 < V_52 )
goto V_70;
F_41 ( V_45 ) -> V_51 = V_51 ;
V_45 -> V_50 = V_50 ;
if ( ! V_50 )
V_18 -> V_16 . V_68 = V_45 ;
if ( V_49 )
V_49 -> V_50 = V_45 ;
else
V_18 -> V_16 . V_41 = V_45 ;
V_32 = V_45 -> V_32 ;
if ( V_32 ) {
V_18 -> V_37 = V_32 -> V_71 ;
V_45 -> V_32 = NULL ;
}
V_18 -> V_16 . V_72 = V_45 -> V_73 ;
V_18 -> V_16 . V_74 += V_45 -> V_65 ;
F_42 ( V_45 -> V_75 , & V_18 -> V_16 . V_1 -> V_5 ) ;
if ( V_51 == 0 ) {
V_18 -> V_76 = V_48 ;
V_18 -> V_16 . V_34 |= V_40 ;
}
if ( V_18 -> V_16 . V_34 == ( V_40 | V_66 ) &&
V_18 -> V_16 . V_74 == V_18 -> V_16 . V_65 )
return F_43 ( V_18 , V_49 , V_32 ) ;
F_44 ( & V_19 . V_33 ) ;
F_45 ( & V_18 -> V_16 . V_77 , & V_18 -> V_16 . V_1 -> V_77 ) ;
F_46 ( & V_19 . V_33 ) ;
return - 1 ;
V_70:
F_13 ( V_18 ) ;
V_53:
F_47 ( V_1 , F_32 ( F_29 ( V_45 ) ) ,
V_29 ) ;
F_48 ( V_45 ) ;
return - 1 ;
}
static int F_43 ( struct V_17 * V_18 , struct V_44 * V_49 ,
struct V_31 * V_32 )
{
struct V_1 * V_1 = F_7 ( V_18 -> V_16 . V_1 , struct V_1 , V_2 . V_3 ) ;
struct V_44 * V_78 , * V_79 = V_18 -> V_16 . V_41 ;
int V_55 ;
unsigned int V_48 ;
F_13 ( V_18 ) ;
if ( V_49 ) {
V_79 = V_49 -> V_50 ;
V_78 = F_49 ( V_79 , V_80 ) ;
if ( ! V_78 )
goto V_81;
V_78 -> V_50 = V_79 -> V_50 ;
if ( ! V_78 -> V_50 )
V_18 -> V_16 . V_68 = V_78 ;
V_49 -> V_50 = V_78 ;
F_50 ( V_79 , V_18 -> V_16 . V_41 ) ;
V_79 -> V_50 = V_18 -> V_16 . V_41 -> V_50 ;
F_48 ( V_18 -> V_16 . V_41 ) ;
V_18 -> V_16 . V_41 = V_79 ;
}
F_51 ( V_79 == NULL ) ;
F_51 ( F_41 ( V_79 ) -> V_51 != 0 ) ;
V_55 = ( ( V_79 -> V_30 - F_34 ( V_79 ) ) -
sizeof( struct V_67 ) + V_18 -> V_16 . V_65 -
sizeof( struct V_46 ) ) ;
if ( V_55 > V_57 )
goto V_82;
if ( F_52 ( V_79 ) && F_53 ( V_79 , 0 , 0 , V_80 ) )
goto V_81;
if ( F_54 ( V_79 ) ) {
struct V_44 * V_83 ;
int V_84 , V_85 = 0 ;
if ( ( V_83 = F_55 ( 0 , V_80 ) ) == NULL )
goto V_81;
V_83 -> V_50 = V_79 -> V_50 ;
V_79 -> V_50 = V_83 ;
F_56 ( V_83 ) -> V_86 = F_56 ( V_79 ) -> V_86 ;
F_57 ( V_79 ) ;
for ( V_84 = 0 ; V_84 < F_56 ( V_79 ) -> V_87 ; V_84 ++ )
V_85 += F_58 ( & F_56 ( V_79 ) -> V_3 [ V_84 ] ) ;
V_83 -> V_65 = V_83 -> V_88 = V_79 -> V_88 - V_85 ;
V_79 -> V_88 -= V_83 -> V_65 ;
V_79 -> V_65 -= V_83 -> V_65 ;
V_83 -> V_63 = 0 ;
V_83 -> V_60 = V_79 -> V_60 ;
F_42 ( V_83 -> V_75 , & V_18 -> V_16 . V_1 -> V_5 ) ;
}
V_48 = V_18 -> V_76 ;
F_34 ( V_79 ) [ V_48 ] = F_59 ( V_79 ) [ 0 ] ;
memmove ( V_79 -> V_79 + sizeof( struct V_46 ) , V_79 -> V_79 ,
( V_79 -> V_30 - V_79 -> V_79 ) - sizeof( struct V_46 ) ) ;
V_79 -> V_89 += sizeof( struct V_46 ) ;
V_79 -> V_90 += sizeof( struct V_46 ) ;
F_56 ( V_79 ) -> V_86 = V_79 -> V_50 ;
F_60 ( V_79 ) ;
F_61 ( V_79 , V_79 -> V_30 - F_34 ( V_79 ) ) ;
for ( V_78 = V_79 -> V_50 ; V_78 ; V_78 = V_78 -> V_50 ) {
V_79 -> V_88 += V_78 -> V_65 ;
V_79 -> V_65 += V_78 -> V_65 ;
if ( V_79 -> V_60 != V_78 -> V_60 )
V_79 -> V_60 = V_91 ;
else if ( V_79 -> V_60 == V_61 )
V_79 -> V_63 = F_62 ( V_79 -> V_63 , V_78 -> V_63 ) ;
V_79 -> V_75 += V_78 -> V_75 ;
}
F_63 ( V_79 -> V_75 , & V_18 -> V_16 . V_1 -> V_5 ) ;
V_79 -> V_50 = NULL ;
V_79 -> V_32 = V_32 ;
V_79 -> V_73 = V_18 -> V_16 . V_72 ;
F_31 ( V_79 ) -> V_55 = F_37 ( V_55 ) ;
F_64 ( V_79 ) -> V_48 = V_48 ;
if ( V_79 -> V_60 == V_61 )
V_79 -> V_63 = F_36 ( F_34 ( V_79 ) ,
F_65 ( V_79 ) ,
V_79 -> V_63 ) ;
F_20 () ;
F_22 ( V_1 , F_23 ( V_32 ) , V_92 ) ;
F_25 () ;
V_18 -> V_16 . V_41 = NULL ;
V_18 -> V_16 . V_68 = NULL ;
return 1 ;
V_82:
if ( F_66 () )
F_67 ( V_93 L_1 , V_55 ) ;
goto V_94;
V_81:
if ( F_66 () )
F_67 ( V_93 L_2 ) ;
V_94:
F_20 () ;
F_22 ( V_1 , F_23 ( V_32 ) , V_29 ) ;
F_25 () ;
return - 1 ;
}
static int F_68 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_17 * V_18 ;
const struct V_67 * V_95 = F_31 ( V_45 ) ;
struct V_1 * V_1 = F_28 ( F_29 ( V_45 ) -> V_32 ) ;
F_22 ( V_1 , F_32 ( F_29 ( V_45 ) ) , V_96 ) ;
if ( V_95 -> V_55 == 0 )
goto V_97;
if ( ! F_69 ( V_45 , ( F_70 ( V_45 ) +
sizeof( struct V_46 ) ) ) )
goto V_97;
V_95 = F_31 ( V_45 ) ;
V_47 = (struct V_46 * ) F_59 ( V_45 ) ;
if ( ! ( V_47 -> V_54 & F_37 ( 0xFFF9 ) ) ) {
V_45 -> V_98 += sizeof( struct V_46 ) ;
F_22 ( V_1 ,
F_32 ( F_29 ( V_45 ) ) , V_92 ) ;
F_64 ( V_45 ) -> V_48 = ( V_56 * ) V_47 - F_34 ( V_45 ) ;
return 1 ;
}
if ( F_3 ( & V_1 -> V_2 . V_3 . V_5 ) > V_1 -> V_2 . V_3 . V_99 )
F_15 ( V_1 , F_32 ( F_29 ( V_45 ) ) ) ;
V_18 = F_71 ( V_1 , V_47 -> V_100 , & V_95 -> V_8 , & V_95 -> V_9 ) ;
if ( V_18 != NULL ) {
int V_101 ;
F_19 ( & V_18 -> V_16 . V_33 ) ;
V_101 = F_27 ( V_18 , V_45 , V_47 , F_64 ( V_45 ) -> V_48 ) ;
F_26 ( & V_18 -> V_16 . V_33 ) ;
F_11 ( V_18 ) ;
return V_101 ;
}
F_22 ( V_1 , F_32 ( F_29 ( V_45 ) ) , V_29 ) ;
F_48 ( V_45 ) ;
return - 1 ;
V_97:
F_47 ( V_1 , F_32 ( F_29 ( V_45 ) ) , V_58 ) ;
F_33 ( V_45 , V_59 , F_65 ( V_45 ) ) ;
return - 1 ;
}
static int T_4 F_72 ( struct V_1 * V_1 )
{
struct V_102 * V_103 ;
struct V_104 * V_95 ;
V_103 = V_105 ;
if ( ! F_73 ( V_1 , & V_106 ) ) {
V_103 = F_74 ( V_103 , sizeof( V_105 ) , V_107 ) ;
if ( V_103 == NULL )
goto V_108;
V_103 [ 0 ] . V_30 = & V_1 -> V_2 . V_3 . V_99 ;
V_103 [ 1 ] . V_30 = & V_1 -> V_2 . V_3 . V_109 ;
V_103 [ 2 ] . V_30 = & V_1 -> V_2 . V_3 . V_110 ;
}
V_95 = F_75 ( V_1 , V_111 , V_103 ) ;
if ( V_95 == NULL )
goto V_112;
V_1 -> V_2 . V_113 . V_114 = V_95 ;
return 0 ;
V_112:
if ( ! F_73 ( V_1 , & V_106 ) )
F_76 ( V_103 ) ;
V_108:
return - V_115 ;
}
static void T_5 F_77 ( struct V_1 * V_1 )
{
struct V_102 * V_103 ;
V_103 = V_1 -> V_2 . V_113 . V_114 -> V_116 ;
F_78 ( V_1 -> V_2 . V_113 . V_114 ) ;
if ( ! F_73 ( V_1 , & V_106 ) )
F_76 ( V_103 ) ;
}
static int F_79 ( void )
{
V_117 = F_80 ( V_111 ,
V_118 ) ;
return V_117 == NULL ? - V_115 : 0 ;
}
static void F_81 ( void )
{
F_78 ( V_117 ) ;
}
static inline int F_72 ( struct V_1 * V_1 )
{
return 0 ;
}
static inline void F_77 ( struct V_1 * V_1 )
{
}
static inline int F_79 ( void )
{
return 0 ;
}
static inline void F_81 ( void )
{
}
static int T_4 F_82 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 . V_99 = V_119 ;
V_1 -> V_2 . V_3 . V_109 = V_120 ;
V_1 -> V_2 . V_3 . V_110 = V_121 ;
F_83 ( & V_1 -> V_2 . V_3 ) ;
return F_72 ( V_1 ) ;
}
static void T_5 F_84 ( struct V_1 * V_1 )
{
F_77 ( V_1 ) ;
F_85 ( & V_1 -> V_2 . V_3 , & V_19 ) ;
}
int T_6 F_86 ( void )
{
int V_101 ;
V_101 = F_87 ( & V_122 , V_123 ) ;
if ( V_101 )
goto V_36;
V_101 = F_79 () ;
if ( V_101 )
goto V_124;
V_101 = F_88 ( & V_125 ) ;
if ( V_101 )
goto V_126;
V_19 . V_127 = F_6 ;
V_19 . V_128 = F_10 ;
V_19 . V_129 = NULL ;
V_19 . V_130 = NULL ;
V_19 . V_131 = sizeof( struct V_17 ) ;
V_19 . V_132 = F_8 ;
V_19 . V_133 = F_18 ;
V_19 . V_134 = 10 * 60 * V_135 ;
F_89 ( & V_19 ) ;
V_36:
return V_101 ;
V_126:
F_81 () ;
V_124:
F_90 ( & V_122 , V_123 ) ;
goto V_36;
}
void F_91 ( void )
{
F_92 ( & V_19 ) ;
F_81 () ;
F_93 ( & V_125 ) ;
F_90 ( & V_122 , V_123 ) ;
}
