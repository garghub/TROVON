static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
F_4 ( V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 )
{
F_6 ( V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_13 * V_14 = V_10 -> V_15 ;
switch ( V_10 -> V_16 ) {
case 0 :
V_6 -> V_17 . V_18 ++ ;
V_6 -> V_17 . V_19 += V_14 -> V_20 ;
break;
case - V_21 :
case - V_22 :
V_6 -> V_17 . V_23 ++ ;
default:
V_6 -> V_17 . V_24 ++ ;
}
F_8 ( V_14 ) ;
F_4 ( V_6 ) ;
}
static int F_9 ( struct V_13 * V_14 , struct V_5 * V_6 )
{
struct V_25 * V_26 = F_10 ( V_6 ) ;
struct V_1 * V_11 ;
struct V_9 * V_10 ;
unsigned long V_27 ;
if ( V_14 -> V_28 != F_11 ( V_29 ) )
goto V_30;
F_12 ( & V_26 -> V_31 , V_27 ) ;
V_11 = V_26 -> V_32 ;
if ( F_13 ( ! V_11 ) )
goto V_33;
V_10 = V_11 -> V_34 ;
V_10 -> V_35 = V_14 -> V_36 ;
V_10 -> V_37 = V_14 -> V_20 ;
V_10 -> V_38 = F_7 ;
V_10 -> V_39 = 1 ;
V_10 -> V_15 = V_14 ;
if ( F_13 ( F_14 ( V_11 -> V_40 , V_10 , V_41 ) ) )
goto V_33;
F_6 ( V_6 ) ;
V_14 = NULL ;
V_33:
F_15 ( & V_26 -> V_31 , V_27 ) ;
V_30:
if ( F_13 ( V_14 ) ) {
F_16 ( V_14 ) ;
V_6 -> V_17 . V_42 ++ ;
}
return V_43 ;
}
static void F_17 ( struct V_5 * V_6 )
{
V_6 -> V_44 = 0 ;
V_6 -> type = V_45 ;
V_6 -> V_27 = V_46 | V_47 ;
V_6 -> V_48 = V_49 ;
V_6 -> V_50 = V_51 ;
V_6 -> V_52 = V_53 ;
V_6 -> V_54 = 1 ;
V_6 -> V_55 [ 0 ] = V_56 ;
V_6 -> V_57 = 1 ;
V_6 -> V_58 = 1 ;
V_6 -> V_59 = & V_60 ;
V_6 -> V_61 = true ;
V_6 -> V_62 = & V_63 ;
}
static int
F_18 ( struct V_1 * V_11 , struct V_9 * V_10 , T_1 V_64 )
{
struct V_65 * V_65 ;
int V_66 ;
V_65 = F_19 ( V_64 | V_67 ) ;
if ( ! V_65 )
return - V_68 ;
V_10 -> V_35 = F_20 ( V_65 ) ;
V_10 -> V_37 = V_69 ;
V_10 -> V_15 = V_65 ;
V_66 = F_14 ( V_11 -> V_70 , V_10 , V_64 ) ;
if ( F_13 ( V_66 ) )
F_21 ( V_65 ) ;
return V_66 ;
}
static void F_22 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_65 * V_65 = V_10 -> V_15 ;
struct V_13 * V_14 ;
unsigned long V_27 ;
int V_16 = V_10 -> V_16 ;
switch ( V_16 ) {
case 0 :
F_12 ( & V_11 -> V_71 . V_31 , V_27 ) ;
V_14 = V_11 -> V_71 . V_14 ;
if ( ! V_14 )
V_14 = V_11 -> V_71 . V_14 = F_23 ( V_6 , 12 ) ;
if ( V_10 -> V_72 < V_10 -> V_37 )
V_11 -> V_71 . V_14 = NULL ;
F_15 ( & V_11 -> V_71 . V_31 , V_27 ) ;
if ( F_13 ( ! V_14 ) )
break;
if ( V_14 -> V_20 == 0 ) {
V_14 -> V_28 = F_11 ( V_29 ) ;
F_24 ( V_14 ) ;
memcpy ( F_25 ( V_14 , 1 ) , F_20 ( V_65 ) , 1 ) ;
}
F_26 ( V_14 , F_27 ( V_14 ) -> V_73 , V_65 ,
V_14 -> V_20 <= 1 , V_10 -> V_72 , V_69 ) ;
V_65 = NULL ;
if ( V_10 -> V_72 < V_10 -> V_37 ) {
V_14 -> V_6 = V_6 ;
V_6 -> V_17 . V_74 ++ ;
V_6 -> V_17 . V_75 += V_14 -> V_20 ;
F_28 ( V_14 ) ;
}
break;
case - V_21 :
case - V_76 :
case - V_22 :
V_10 = NULL ;
break;
case - V_77 :
V_6 -> V_17 . V_78 ++ ;
default:
V_6 -> V_17 . V_79 ++ ;
break;
}
if ( V_65 )
F_21 ( V_65 ) ;
if ( V_10 )
F_18 ( V_11 , V_10 , V_41 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_25 * V_26 = F_10 ( V_6 ) ;
F_30 ( V_6 ) ;
V_26 -> V_32 = NULL ;
F_31 ( V_11 -> V_70 ) ;
F_31 ( V_11 -> V_40 ) ;
if ( V_11 -> V_71 . V_14 ) {
F_32 ( V_11 -> V_71 . V_14 ) ;
V_11 -> V_71 . V_14 = NULL ;
}
}
static int F_33 ( struct V_2 * V_3 , unsigned V_80 , unsigned V_81 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_82 * V_83 = V_11 -> V_4 . V_84 -> V_85 -> V_83 ;
if ( V_80 == V_86 . V_87 )
return ( V_81 > 0 ) ? - V_88 : 0 ;
if ( V_80 == V_89 . V_87 ) {
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_25 * V_26 = F_10 ( V_6 ) ;
if ( V_81 > 1 )
return - V_88 ;
F_34 ( & V_26 -> V_31 ) ;
if ( V_11 -> V_40 -> V_90 )
F_29 ( V_3 ) ;
if ( V_81 == 1 ) {
int V_91 ;
if ( F_35 ( V_83 , V_3 , V_11 -> V_40 ) ||
F_35 ( V_83 , V_3 , V_11 -> V_70 ) ) {
V_11 -> V_40 -> V_92 = NULL ;
V_11 -> V_70 -> V_92 = NULL ;
F_36 ( & V_26 -> V_31 ) ;
return - V_88 ;
}
F_37 ( V_11 -> V_70 ) ;
F_37 ( V_11 -> V_40 ) ;
V_26 -> V_32 = V_11 ;
V_11 -> V_70 -> V_12 = V_11 ;
V_11 -> V_40 -> V_12 = V_11 ;
F_38 ( V_6 ) ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ )
F_18 ( V_11 , V_11 -> V_94 [ V_91 ] , V_41 ) ;
}
F_36 ( & V_26 -> V_31 ) ;
return 0 ;
}
return - V_88 ;
}
static int F_39 ( struct V_2 * V_3 , unsigned V_80 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_80 == V_86 . V_87 )
return 0 ;
if ( V_80 == V_89 . V_87 ) {
struct V_25 * V_26 = F_10 ( V_11 -> V_6 ) ;
T_2 V_81 ;
F_34 ( & V_26 -> V_31 ) ;
V_81 = V_26 -> V_32 != NULL ;
F_36 ( & V_26 -> V_31 ) ;
return V_81 ;
}
return - V_88 ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_25 * V_26 = F_10 ( V_11 -> V_6 ) ;
unsigned long V_27 ;
F_12 ( & V_26 -> V_31 , V_27 ) ;
F_29 ( V_3 ) ;
F_15 ( & V_26 -> V_31 , V_27 ) ;
}
static int F_41 ( struct V_95 * V_96 , struct V_2 * V_3 )
{
struct V_97 * V_85 = V_96 -> V_85 ;
struct V_82 * V_83 = V_85 -> V_83 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_7 * V_8 ;
int V_16 , V_91 ;
struct V_98 * V_99 ;
V_99 = F_2 ( V_3 -> V_100 , struct V_98 , V_101 ) ;
if ( ! V_99 -> V_102 ) {
F_42 ( V_99 -> V_103 , V_83 ) ;
V_16 = F_43 ( V_99 -> V_103 ) ;
if ( V_16 )
return V_16 ;
V_99 -> V_102 = true ;
}
V_16 = F_44 ( V_96 , V_3 ) ;
if ( V_16 < 0 )
goto V_66;
V_86 . V_87 = V_16 ;
V_104 . V_105 = V_16 ;
V_16 = F_44 ( V_96 , V_3 ) ;
if ( V_16 < 0 )
goto V_66;
V_106 . V_87 = V_16 ;
V_89 . V_87 = V_16 ;
V_104 . V_107 = V_16 ;
V_16 = - V_108 ;
V_8 = F_45 ( V_83 , & V_109 ) ;
if ( ! V_8 )
goto V_66;
V_11 -> V_70 = V_8 ;
V_8 = F_45 ( V_83 , & V_110 ) ;
if ( ! V_8 )
goto V_66;
V_11 -> V_40 = V_8 ;
V_111 . V_112 = V_109 . V_112 ;
V_113 . V_112 = V_110 . V_112 ;
V_16 = F_46 ( V_3 , V_114 , V_115 ,
NULL , NULL ) ;
if ( V_16 )
goto V_66;
V_16 = - V_68 ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
struct V_9 * V_10 ;
V_10 = F_47 ( V_11 -> V_70 , V_116 ) ;
if ( ! V_10 )
goto V_117;
V_10 -> V_38 = F_22 ;
V_11 -> V_94 [ V_91 ] = V_10 ;
}
V_11 -> V_34 = F_47 ( V_11 -> V_40 , V_116 ) ;
if ( ! V_11 -> V_34 )
goto V_117;
F_48 ( V_85 , L_1 ) ;
F_48 ( V_85 , L_2 , V_85 -> V_83 -> V_118 ,
V_11 -> V_70 -> V_118 , V_11 -> V_40 -> V_118 ) ;
return 0 ;
V_117:
for ( V_91 = 0 ; V_91 < V_93 && V_11 -> V_94 [ V_91 ] ; V_91 ++ )
F_49 ( V_11 -> V_70 , V_11 -> V_94 [ V_91 ] ) ;
F_50 ( V_3 ) ;
V_66:
ERROR ( V_85 , L_3 ) ;
return V_16 ;
}
static inline struct V_98 * F_51 ( struct V_119 * V_120 )
{
return F_2 ( F_52 ( V_120 ) , struct V_98 ,
V_101 . V_121 ) ;
}
static void F_53 ( struct V_119 * V_120 )
{
struct V_98 * V_122 = F_51 ( V_120 ) ;
F_54 ( & V_122 -> V_101 ) ;
}
static T_3 F_55 ( struct V_119 * V_120 , char * V_65 )
{
return F_56 ( F_51 ( V_120 ) -> V_103 , V_65 , V_69 ) ;
}
static void F_57 ( struct V_123 * V_3 )
{
struct V_98 * V_122 ;
V_122 = F_2 ( V_3 , struct V_98 , V_101 ) ;
if ( V_122 -> V_102 )
F_58 ( V_122 -> V_103 ) ;
else
F_59 ( V_122 -> V_103 ) ;
F_60 ( V_122 ) ;
}
static struct V_123 * F_61 ( void )
{
struct V_98 * V_122 ;
V_122 = F_62 ( sizeof( * V_122 ) , V_116 ) ;
if ( ! V_122 )
return F_63 ( - V_68 ) ;
V_122 -> V_101 . V_124 = F_57 ;
V_122 -> V_103 = F_64 () ;
if ( F_65 ( V_122 -> V_103 ) ) {
struct V_5 * V_103 = V_122 -> V_103 ;
F_60 ( V_122 ) ;
return F_66 ( V_103 ) ;
}
F_67 ( & V_122 -> V_101 . V_121 , L_4 ,
& V_125 ) ;
return & V_122 -> V_101 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_126 ;
V_126 = F_1 ( V_3 ) ;
F_60 ( V_126 ) ;
}
static void F_69 ( struct V_95 * V_96 , struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_91 ;
if ( V_11 -> V_34 )
F_49 ( V_11 -> V_40 , V_11 -> V_34 ) ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ )
if ( V_11 -> V_94 [ V_91 ] )
F_49 ( V_11 -> V_70 , V_11 -> V_94 [ V_91 ] ) ;
F_50 ( V_3 ) ;
}
static struct V_2 * F_70 ( struct V_123 * V_100 )
{
struct V_1 * V_11 ;
struct V_98 * V_122 ;
int V_127 ;
V_127 = sizeof( * V_11 ) + ( V_93 * sizeof( struct V_9 * ) ) ;
V_11 = F_62 ( V_127 , V_116 ) ;
if ( ! V_11 )
return F_63 ( - V_68 ) ;
V_122 = F_2 ( V_100 , struct V_98 , V_101 ) ;
V_11 -> V_6 = V_122 -> V_103 ;
V_11 -> V_4 . V_118 = L_5 ;
V_11 -> V_4 . V_128 = F_41 ;
V_11 -> V_4 . V_129 = F_69 ;
V_11 -> V_4 . V_130 = F_33 ;
V_11 -> V_4 . V_131 = F_39 ;
V_11 -> V_4 . V_132 = F_40 ;
V_11 -> V_4 . V_133 = F_68 ;
F_71 ( & V_11 -> V_71 . V_31 ) ;
return & V_11 -> V_4 ;
}
struct V_5 * F_64 ( void )
{
struct V_5 * V_6 ;
struct V_25 * V_26 ;
V_6 = F_72 ( sizeof( * V_26 ) , L_6 , V_134 ,
F_17 ) ;
if ( ! V_6 )
return F_63 ( - V_68 ) ;
V_26 = F_10 ( V_6 ) ;
F_71 ( & V_26 -> V_31 ) ;
F_30 ( V_6 ) ;
return V_6 ;
}
void F_42 ( struct V_5 * V_103 , struct V_82 * V_135 )
{
F_73 ( V_103 , & V_135 -> V_6 ) ;
}
int F_43 ( struct V_5 * V_103 )
{
int V_16 ;
V_16 = F_74 ( V_103 ) ;
if ( V_16 )
F_59 ( V_103 ) ;
return V_16 ;
}
void F_58 ( struct V_5 * V_6 )
{
F_75 ( V_6 ) ;
}
