static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_4 ,
V_2 -> V_7 ) ;
else
F_4 ( V_2 -> V_8 ) ;
}
static struct V_1 *
F_5 ( struct V_9 * V_5 , T_1 V_7 , T_2 V_10 ,
int V_11 , int V_12 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_6 ( V_5 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
goto V_15;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_11 ;
V_2 -> V_16 = F_7 ( sizeof( struct V_17 ) , V_12 ) ;
V_2 -> V_18 = V_11 / V_2 -> V_16 ;
V_2 -> V_19 = F_8 ( V_5 , F_9 ( V_2 -> V_16 ) , - 1 ,
L_1 ) ;
if ( F_10 ( V_2 -> V_19 ) ) {
F_11 ( V_5 , L_2 ,
F_12 ( V_2 -> V_19 ) ) ;
goto V_15;
}
if ( V_7 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = F_13 ( V_7 , V_11 ) ;
V_2 -> V_10 = V_10 ;
} else {
V_2 -> V_4 = F_14 ( V_5 , V_11 , & V_2 -> V_10 ,
V_14 ) ;
V_2 -> V_8 = ( void V_20 V_21 * ) V_2 -> V_4 ;
V_2 -> V_7 = V_2 -> V_10 ;
}
if ( ! V_2 -> V_8 )
goto V_15;
V_13 = F_15 ( V_2 -> V_19 , ( unsigned long ) V_2 -> V_8 ,
V_2 -> V_7 , V_2 -> V_6 , - 1 ) ;
if ( V_13 < 0 ) {
F_11 ( V_5 , L_3 , V_13 ) ;
goto V_22;
}
return V_2 ;
V_22:
F_1 ( V_2 ) ;
V_15:
return NULL ;
}
static inline T_2 F_16 ( struct V_1 * V_2 ,
struct V_17 V_20 * V_23 )
{
if ( ! V_23 )
return 0 ;
return V_2 -> V_10 + ( V_21 long ) V_23 - ( V_21 long ) V_2 -> V_8 ;
}
static inline struct V_17 V_20 *
F_17 ( struct V_1 * V_2 , T_2 V_24 )
{
return V_24 ? V_2 -> V_8 + V_24 - V_2 -> V_10 : NULL ;
}
static struct V_17 V_20 *
F_18 ( struct V_1 * V_2 )
{
struct V_17 V_20 * V_23 = NULL ;
V_23 = (struct V_17 V_20 * ) F_19 ( V_2 -> V_19 ,
V_2 -> V_16 ) ;
if ( V_23 )
V_2 -> V_3 ++ ;
return V_23 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_17 V_20 * V_23 , int V_18 )
{
F_21 ( V_2 -> V_19 , ( unsigned long ) V_23 , V_2 -> V_16 ) ;
V_2 -> V_3 -- ;
}
struct V_25 * F_22 ( struct V_26 * V_27 )
{
struct V_25 * V_28 ;
V_28 = F_6 ( V_27 -> V_5 , sizeof( * V_28 ) , V_14 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_29 = V_30 ;
V_28 -> V_27 = * V_27 ;
V_28 -> V_5 = V_27 -> V_5 ;
F_23 ( & V_28 -> V_31 ) ;
V_28 -> V_2 = F_5 ( V_28 -> V_5 ,
V_28 -> V_27 . V_32 ,
V_28 -> V_27 . V_33 ,
V_28 -> V_27 . V_34 ,
V_28 -> V_27 . V_35 ) ;
if ( ! V_28 -> V_2 )
return NULL ;
if ( F_2 ( V_28 -> V_36 > V_37 ) )
V_28 -> V_36 = V_37 ;
return V_28 ;
}
int F_24 ( struct V_25 * V_28 )
{
unsigned long V_38 ;
int V_39 ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
if ( V_28 -> V_29 != V_30 ) {
F_26 ( & V_28 -> V_31 , V_38 ) ;
return - V_40 ;
}
if ( V_28 -> V_27 . V_41 ) {
unsigned V_42 = 10 * 100 ;
F_27 ( V_28 , V_43 , 1 ) ;
while ( V_42 ) {
if ( F_28 ( V_28 , V_43 ) == 0 )
break;
F_29 ( 10 ) ;
V_42 -- ;
}
F_2 ( ! V_42 ) ;
}
for ( V_39 = 0 ; V_39 < V_28 -> V_36 ; V_39 ++ ) {
F_30 ( 0 , V_28 -> V_27 . V_44 + 4 * V_39 ) ;
F_30 ( 0 , V_28 -> V_27 . V_45 + 4 * V_39 ) ;
F_30 ( 0 , V_28 -> V_27 . V_46 + 4 * V_39 ) ;
F_30 ( 0 , V_28 -> V_27 . V_47 + 4 * V_39 ) ;
}
F_27 ( V_28 , V_48 , 0xffffffff ) ;
F_27 ( V_28 , V_49 , 0xffffffff ) ;
F_27 ( V_28 , V_50 , 1 ) ;
F_27 ( V_28 , V_51 , 1 ) ;
V_28 -> V_29 = V_52 ;
for ( V_39 = 0 ; V_39 < F_31 ( V_28 -> V_53 ) ; V_39 ++ ) {
if ( V_28 -> V_53 [ V_39 ] )
F_32 ( V_28 -> V_53 [ V_39 ] ) ;
}
F_26 ( & V_28 -> V_31 , V_38 ) ;
return 0 ;
}
int F_33 ( struct V_25 * V_28 )
{
unsigned long V_38 ;
int V_39 ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
if ( V_28 -> V_29 == V_54 ) {
F_26 ( & V_28 -> V_31 , V_38 ) ;
return - V_55 ;
}
V_28 -> V_29 = V_54 ;
for ( V_39 = 0 ; V_39 < F_31 ( V_28 -> V_53 ) ; V_39 ++ ) {
if ( V_28 -> V_53 [ V_39 ] )
F_34 ( V_28 -> V_53 [ V_39 ] ) ;
}
F_27 ( V_28 , V_48 , 0xffffffff ) ;
F_27 ( V_28 , V_49 , 0xffffffff ) ;
F_27 ( V_28 , V_50 , 0 ) ;
F_27 ( V_28 , V_51 , 0 ) ;
V_28 -> V_29 = V_30 ;
F_26 ( & V_28 -> V_31 , V_38 ) ;
return 0 ;
}
int F_35 ( struct V_25 * V_28 )
{
int V_13 = 0 , V_39 ;
if ( ! V_28 )
return - V_55 ;
if ( V_28 -> V_29 != V_30 )
F_33 ( V_28 ) ;
for ( V_39 = 0 ; V_39 < F_31 ( V_28 -> V_53 ) ; V_39 ++ )
F_36 ( V_28 -> V_53 [ V_39 ] ) ;
F_1 ( V_28 -> V_2 ) ;
return V_13 ;
}
int F_37 ( struct V_25 * V_28 , bool V_56 )
{
unsigned long V_38 ;
int V_39 , V_57 ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
if ( V_28 -> V_29 != V_52 ) {
F_26 ( & V_28 -> V_31 , V_38 ) ;
return - V_55 ;
}
V_57 = V_56 ? V_58 : V_59 ;
F_27 ( V_28 , V_57 , V_60 ) ;
for ( V_39 = 0 ; V_39 < F_31 ( V_28 -> V_53 ) ; V_39 ++ ) {
if ( V_28 -> V_53 [ V_39 ] )
F_38 ( V_28 -> V_53 [ V_39 ] , V_56 ) ;
}
F_26 ( & V_28 -> V_31 , V_38 ) ;
return 0 ;
}
void F_39 ( struct V_25 * V_28 , T_1 V_61 )
{
F_27 ( V_28 , V_62 , V_61 ) ;
}
struct V_63 * F_40 ( struct V_25 * V_28 , int V_64 ,
T_3 V_65 )
{
struct V_63 * V_66 ;
int V_67 = ( V_64 % V_37 ) * 4 ;
unsigned long V_38 ;
if ( F_41 ( V_64 ) >= V_28 -> V_36 )
return NULL ;
V_66 = F_6 ( V_28 -> V_5 , sizeof( * V_66 ) , V_14 ) ;
if ( ! V_66 )
return F_42 ( - V_68 ) ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
if ( V_28 -> V_53 [ V_64 ] ) {
F_26 ( & V_28 -> V_31 , V_38 ) ;
F_43 ( V_28 -> V_5 , V_66 ) ;
return F_42 ( - V_40 ) ;
}
V_66 -> V_28 = V_28 ;
V_66 -> V_29 = V_30 ;
V_66 -> V_64 = V_64 ;
V_66 -> V_65 = V_65 ;
V_66 -> V_69 = V_28 -> V_2 -> V_18 / 2 ;
if ( F_44 ( V_66 ) ) {
V_66 -> V_70 = V_28 -> V_27 . V_45 + V_67 ;
V_66 -> V_71 = V_28 -> V_27 . V_47 + V_67 ;
V_66 -> V_72 = V_28 -> V_27 . V_72 + V_67 ;
V_66 -> V_73 = V_74 ;
V_66 -> V_75 = V_48 ;
V_66 -> V_76 = V_77 ;
V_66 -> V_78 = V_79 ;
} else {
V_66 -> V_70 = V_28 -> V_27 . V_44 + V_67 ;
V_66 -> V_71 = V_28 -> V_27 . V_46 + V_67 ;
V_66 -> V_73 = V_80 ;
V_66 -> V_75 = V_49 ;
V_66 -> V_76 = V_81 ;
V_66 -> V_78 = V_82 ;
}
V_66 -> V_83 = F_45 ( F_46 ( V_66 ) ) ;
F_23 ( & V_66 -> V_31 ) ;
V_28 -> V_53 [ V_64 ] = V_66 ;
F_26 ( & V_28 -> V_31 , V_38 ) ;
return V_66 ;
}
int F_47 ( struct V_25 * V_28 )
{
return V_28 -> V_2 -> V_18 / 2 ;
}
int F_36 ( struct V_63 * V_66 )
{
struct V_25 * V_28 ;
unsigned long V_38 ;
if ( ! V_66 )
return - V_55 ;
V_28 = V_66 -> V_28 ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
if ( V_66 -> V_29 != V_30 )
F_34 ( V_66 ) ;
V_28 -> V_53 [ V_66 -> V_64 ] = NULL ;
F_26 ( & V_28 -> V_31 , V_38 ) ;
return 0 ;
}
int F_48 ( struct V_63 * V_66 ,
struct V_84 * V_85 )
{
unsigned long V_38 ;
if ( ! V_66 )
return - V_55 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
memcpy ( V_85 , & V_66 -> V_85 , sizeof( * V_85 ) ) ;
F_26 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
static void F_49 ( struct V_63 * V_66 ,
struct V_17 V_20 * V_23 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_17 V_20 * V_86 = V_66 -> V_87 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_2 V_88 ;
T_1 V_89 ;
V_88 = F_16 ( V_2 , V_23 ) ;
if ( ! V_66 -> V_90 ) {
V_66 -> V_85 . V_91 ++ ;
V_66 -> V_90 = V_23 ;
V_66 -> V_87 = V_23 ;
if ( V_66 -> V_29 == V_52 )
F_50 ( V_66 , V_70 , V_88 ) ;
return;
}
F_51 ( V_86 , V_92 , V_88 ) ;
V_66 -> V_87 = V_23 ;
V_66 -> V_85 . V_93 ++ ;
V_89 = F_52 ( V_86 , V_94 ) ;
if ( ( ( V_89 & ( V_95 | V_96 ) ) == V_95 ) &&
( V_66 -> V_29 == V_52 ) ) {
F_51 ( V_86 , V_94 , V_89 & ~ V_95 ) ;
F_50 ( V_66 , V_70 , V_88 ) ;
V_66 -> V_85 . V_97 ++ ;
}
}
int F_53 ( struct V_63 * V_66 , void * V_98 , void * V_99 ,
int V_100 , int V_101 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_17 V_20 * V_23 ;
T_2 V_102 ;
unsigned long V_38 ;
T_1 V_89 ;
int V_13 = 0 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_29 == V_54 ) {
V_13 = - V_55 ;
goto V_103;
}
if ( V_66 -> V_104 >= V_66 -> V_69 ) {
V_66 -> V_85 . V_105 ++ ;
V_13 = - V_68 ;
goto V_103;
}
V_23 = F_18 ( V_28 -> V_2 ) ;
if ( ! V_23 ) {
V_66 -> V_85 . V_105 ++ ;
V_13 = - V_68 ;
goto V_103;
}
if ( V_100 < V_28 -> V_27 . V_106 ) {
V_100 = V_28 -> V_27 . V_106 ;
V_66 -> V_85 . V_107 ++ ;
}
V_102 = F_54 ( V_28 -> V_5 , V_99 , V_100 , V_66 -> V_78 ) ;
V_13 = F_55 ( V_28 -> V_5 , V_102 ) ;
if ( V_13 ) {
F_20 ( V_28 -> V_2 , V_23 , 1 ) ;
V_13 = - V_55 ;
goto V_103;
}
V_89 = V_96 | V_108 | V_109 ;
F_56 ( V_66 , V_89 , V_101 ) ;
F_51 ( V_23 , V_92 , 0 ) ;
F_51 ( V_23 , V_110 , V_102 ) ;
F_51 ( V_23 , V_111 , V_100 ) ;
F_51 ( V_23 , V_94 , V_89 | V_100 ) ;
F_51 ( V_23 , V_112 , V_98 ) ;
F_51 ( V_23 , V_113 , V_102 ) ;
F_51 ( V_23 , V_114 , V_100 ) ;
F_49 ( V_66 , V_23 ) ;
if ( V_66 -> V_29 == V_52 && V_66 -> V_72 )
F_50 ( V_66 , V_72 , 1 ) ;
V_66 -> V_104 ++ ;
V_103:
F_26 ( & V_66 -> V_31 , V_38 ) ;
return V_13 ;
}
bool F_57 ( struct V_63 * V_66 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
bool V_115 ;
unsigned long V_38 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
V_115 = ( V_66 -> V_104 < V_66 -> V_69 ) &&
F_58 ( V_2 -> V_19 ) ;
F_26 ( & V_66 -> V_31 , V_38 ) ;
return V_115 ;
}
static void F_59 ( struct V_63 * V_66 ,
struct V_17 V_20 * V_23 ,
int V_116 , int V_117 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_2 V_118 ;
int V_119 ;
void * V_98 ;
V_98 = ( void * ) F_52 ( V_23 , V_112 ) ;
V_118 = F_52 ( V_23 , V_113 ) ;
V_119 = F_52 ( V_23 , V_114 ) ;
F_60 ( V_28 -> V_5 , V_118 , V_119 , V_66 -> V_78 ) ;
F_20 ( V_2 , V_23 , 1 ) ;
(* V_66 -> V_65 )( V_98 , V_116 , V_117 ) ;
}
static int F_61 ( struct V_63 * V_66 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_17 V_20 * V_23 ;
int V_117 , V_116 ;
int V_120 = 0 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_2 V_88 ;
unsigned long V_38 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
V_23 = V_66 -> V_90 ;
if ( ! V_23 ) {
V_66 -> V_85 . V_121 ++ ;
V_117 = - V_122 ;
goto V_103;
}
V_88 = F_16 ( V_2 , V_23 ) ;
V_117 = F_62 ( & V_23 -> V_94 ) ;
V_116 = V_117 & 0x7ff ;
if ( V_117 & V_96 ) {
V_66 -> V_85 . V_123 ++ ;
V_117 = - V_40 ;
goto V_103;
}
if ( V_117 & V_124 )
V_116 -= V_125 ;
V_117 = V_117 & ( V_95 | V_126 |
V_127 ) ;
V_66 -> V_90 = F_17 ( V_2 , F_52 ( V_23 , V_92 ) ) ;
F_50 ( V_66 , V_71 , V_88 ) ;
V_66 -> V_104 -- ;
V_66 -> V_85 . V_128 ++ ;
if ( V_117 & V_95 ) {
V_66 -> V_85 . V_129 ++ ;
F_50 ( V_66 , V_70 , F_16 ( V_2 , V_66 -> V_90 ) ) ;
}
F_26 ( & V_66 -> V_31 , V_38 ) ;
if ( F_63 ( V_117 & V_126 ) )
V_120 = - V_130 ;
else
V_120 = V_117 ;
F_59 ( V_66 , V_23 , V_116 , V_120 ) ;
return V_117 ;
V_103:
F_26 ( & V_66 -> V_31 , V_38 ) ;
return V_117 ;
}
int F_64 ( struct V_63 * V_66 , int V_131 )
{
int V_132 = 0 , V_13 = 0 ;
if ( V_66 -> V_29 != V_52 )
return - V_55 ;
while ( V_132 < V_131 ) {
V_13 = F_61 ( V_66 ) ;
if ( V_13 < 0 )
break;
V_132 ++ ;
}
return V_132 ;
}
int F_32 ( struct V_63 * V_66 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_38 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_29 != V_30 ) {
F_26 ( & V_66 -> V_31 , V_38 ) ;
return - V_40 ;
}
if ( V_28 -> V_29 != V_52 ) {
F_26 ( & V_66 -> V_31 , V_38 ) ;
return - V_55 ;
}
F_27 ( V_28 , V_66 -> V_73 , V_66 -> V_83 ) ;
V_66 -> V_29 = V_52 ;
if ( V_66 -> V_90 ) {
F_50 ( V_66 , V_70 , F_16 ( V_2 , V_66 -> V_90 ) ) ;
if ( V_66 -> V_72 )
F_50 ( V_66 , V_72 , V_66 -> V_104 ) ;
}
F_26 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
int F_34 ( struct V_63 * V_66 )
{
struct V_25 * V_28 = V_66 -> V_28 ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_38 ;
int V_13 ;
unsigned V_42 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_29 == V_54 ) {
F_26 ( & V_66 -> V_31 , V_38 ) ;
return - V_55 ;
}
V_66 -> V_29 = V_54 ;
F_27 ( V_28 , V_66 -> V_75 , V_66 -> V_83 ) ;
F_27 ( V_28 , V_66 -> V_76 , F_46 ( V_66 ) ) ;
V_42 = 100 * 100 ;
while ( V_42 ) {
T_1 V_71 = F_65 ( V_66 , V_71 ) ;
if ( ( V_71 & V_133 ) == V_133 )
break;
F_29 ( 10 ) ;
V_42 -- ;
}
F_2 ( ! V_42 ) ;
F_50 ( V_66 , V_71 , V_133 ) ;
F_26 ( & V_66 -> V_31 , V_38 ) ;
do {
V_13 = F_61 ( V_66 ) ;
if ( V_13 < 0 )
break;
} while ( ( V_13 & V_126 ) == 0 );
F_25 ( & V_66 -> V_31 , V_38 ) ;
while ( V_66 -> V_90 ) {
struct V_17 V_20 * V_23 = V_66 -> V_90 ;
T_2 V_134 ;
V_134 = F_52 ( V_23 , V_92 ) ;
V_66 -> V_90 = F_17 ( V_2 , V_134 ) ;
V_66 -> V_104 -- ;
V_66 -> V_85 . V_135 ++ ;
F_26 ( & V_66 -> V_31 , V_38 ) ;
F_59 ( V_66 , V_23 , 0 , - V_130 ) ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
}
V_66 -> V_29 = V_30 ;
F_26 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
int F_38 ( struct V_63 * V_66 , bool V_56 )
{
unsigned long V_38 ;
F_25 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_29 != V_52 ) {
F_26 ( & V_66 -> V_31 , V_38 ) ;
return - V_55 ;
}
F_27 ( V_66 -> V_28 , V_56 ? V_66 -> V_73 : V_66 -> V_75 ,
V_66 -> V_83 ) ;
F_26 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
int F_66 ( struct V_25 * V_28 , int V_136 )
{
unsigned long V_38 ;
struct V_137 * V_138 = & V_139 [ V_136 ] ;
int V_13 ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
V_13 = - V_140 ;
if ( ! V_28 -> V_27 . V_141 )
goto V_103;
V_13 = - V_55 ;
if ( V_28 -> V_29 != V_52 )
goto V_103;
V_13 = - V_122 ;
if ( V_136 < 0 || V_136 >= F_31 ( V_139 ) )
goto V_103;
V_13 = - V_142 ;
if ( ( V_138 -> V_143 & V_144 ) != V_144 )
goto V_103;
V_13 = ( F_28 ( V_28 , V_138 -> V_57 ) >> V_138 -> V_145 ) & V_138 -> V_83 ;
V_103:
F_26 ( & V_28 -> V_31 , V_38 ) ;
return V_13 ;
}
int F_67 ( struct V_25 * V_28 , int V_136 , int V_61 )
{
unsigned long V_38 ;
struct V_137 * V_138 = & V_139 [ V_136 ] ;
int V_13 ;
T_1 V_146 ;
F_25 ( & V_28 -> V_31 , V_38 ) ;
V_13 = - V_140 ;
if ( ! V_28 -> V_27 . V_141 )
goto V_103;
V_13 = - V_55 ;
if ( V_28 -> V_29 != V_52 )
goto V_103;
V_13 = - V_122 ;
if ( V_136 < 0 || V_136 >= F_31 ( V_139 ) )
goto V_103;
V_13 = - V_142 ;
if ( ( V_138 -> V_143 & V_147 ) != V_147 )
goto V_103;
V_146 = F_28 ( V_28 , V_138 -> V_57 ) ;
V_146 &= ~ ( V_138 -> V_83 << V_138 -> V_145 ) ;
V_146 |= ( V_61 & V_138 -> V_83 ) << V_138 -> V_145 ;
F_27 ( V_28 , V_138 -> V_57 , V_146 ) ;
V_13 = 0 ;
V_103:
F_26 ( & V_28 -> V_31 , V_38 ) ;
return V_13 ;
}
