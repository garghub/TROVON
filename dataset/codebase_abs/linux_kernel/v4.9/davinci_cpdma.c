static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( F_3 ( V_2 -> V_3 ) != F_4 ( V_2 -> V_3 ) ,
L_1 ,
F_3 ( V_2 -> V_3 ) ,
F_4 ( V_2 -> V_3 ) ) ;
if ( V_2 -> V_4 )
F_5 ( V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_4 ,
V_2 -> V_7 ) ;
else
F_6 ( V_2 -> V_8 ) ;
}
static struct V_1 *
F_7 ( struct V_9 * V_5 , T_1 V_7 , T_2 V_10 ,
int V_11 , int V_12 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_8 ( V_5 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
goto V_15;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_11 ;
V_2 -> V_16 = F_9 ( sizeof( struct V_17 ) , V_12 ) ;
V_2 -> V_18 = V_11 / V_2 -> V_16 ;
V_2 -> V_3 = F_10 ( V_5 , F_11 ( V_2 -> V_16 ) , - 1 ,
L_2 ) ;
if ( F_12 ( V_2 -> V_3 ) ) {
F_13 ( V_5 , L_3 ,
F_14 ( V_2 -> V_3 ) ) ;
goto V_15;
}
if ( V_7 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = F_15 ( V_7 , V_11 ) ;
V_2 -> V_10 = V_10 ;
} else {
V_2 -> V_4 = F_16 ( V_5 , V_11 , & V_2 -> V_10 ,
V_14 ) ;
V_2 -> V_8 = ( void V_19 V_20 * ) V_2 -> V_4 ;
V_2 -> V_7 = V_2 -> V_10 ;
}
if ( ! V_2 -> V_8 )
goto V_15;
V_13 = F_17 ( V_2 -> V_3 , ( unsigned long ) V_2 -> V_8 ,
V_2 -> V_7 , V_2 -> V_6 , - 1 ) ;
if ( V_13 < 0 ) {
F_13 ( V_5 , L_4 , V_13 ) ;
goto V_21;
}
return V_2 ;
V_21:
F_1 ( V_2 ) ;
V_15:
return NULL ;
}
static inline T_2 F_18 ( struct V_1 * V_2 ,
struct V_17 V_19 * V_22 )
{
if ( ! V_22 )
return 0 ;
return V_2 -> V_10 + ( V_20 long ) V_22 - ( V_20 long ) V_2 -> V_8 ;
}
static inline struct V_17 V_19 *
F_19 ( struct V_1 * V_2 , T_2 V_23 )
{
return V_23 ? V_2 -> V_8 + V_23 - V_2 -> V_10 : NULL ;
}
static struct V_17 V_19 *
F_20 ( struct V_1 * V_2 )
{
return (struct V_17 V_19 * )
F_21 ( V_2 -> V_3 , V_2 -> V_16 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_17 V_19 * V_22 , int V_18 )
{
F_23 ( V_2 -> V_3 , ( unsigned long ) V_22 , V_2 -> V_16 ) ;
}
struct V_24 * F_24 ( struct V_25 * V_26 )
{
struct V_24 * V_27 ;
V_27 = F_8 ( V_26 -> V_5 , sizeof( * V_27 ) , V_14 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_28 = V_29 ;
V_27 -> V_26 = * V_26 ;
V_27 -> V_5 = V_26 -> V_5 ;
V_27 -> V_30 = 0 ;
F_25 ( & V_27 -> V_31 ) ;
V_27 -> V_2 = F_7 ( V_27 -> V_5 ,
V_27 -> V_26 . V_32 ,
V_27 -> V_26 . V_33 ,
V_27 -> V_26 . V_34 ,
V_27 -> V_26 . V_35 ) ;
if ( ! V_27 -> V_2 )
return NULL ;
if ( F_26 ( V_27 -> V_36 > V_37 ) )
V_27 -> V_36 = V_37 ;
return V_27 ;
}
int F_27 ( struct V_24 * V_27 )
{
unsigned long V_38 ;
int V_39 ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
if ( V_27 -> V_28 != V_29 ) {
F_29 ( & V_27 -> V_31 , V_38 ) ;
return - V_40 ;
}
if ( V_27 -> V_26 . V_41 ) {
unsigned V_42 = 10 * 100 ;
F_30 ( V_27 , V_43 , 1 ) ;
while ( V_42 ) {
if ( F_31 ( V_27 , V_43 ) == 0 )
break;
F_32 ( 10 ) ;
V_42 -- ;
}
F_26 ( ! V_42 ) ;
}
for ( V_39 = 0 ; V_39 < V_27 -> V_36 ; V_39 ++ ) {
F_33 ( 0 , V_27 -> V_26 . V_44 + 4 * V_39 ) ;
F_33 ( 0 , V_27 -> V_26 . V_45 + 4 * V_39 ) ;
F_33 ( 0 , V_27 -> V_26 . V_46 + 4 * V_39 ) ;
F_33 ( 0 , V_27 -> V_26 . V_47 + 4 * V_39 ) ;
}
F_30 ( V_27 , V_48 , 0xffffffff ) ;
F_30 ( V_27 , V_49 , 0xffffffff ) ;
F_30 ( V_27 , V_50 , 1 ) ;
F_30 ( V_27 , V_51 , 1 ) ;
V_27 -> V_28 = V_52 ;
for ( V_39 = 0 ; V_39 < F_34 ( V_27 -> V_53 ) ; V_39 ++ ) {
if ( V_27 -> V_53 [ V_39 ] )
F_35 ( V_27 -> V_53 [ V_39 ] ) ;
}
F_29 ( & V_27 -> V_31 , V_38 ) ;
return 0 ;
}
int F_36 ( struct V_24 * V_27 )
{
unsigned long V_38 ;
int V_39 ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
if ( V_27 -> V_28 == V_54 ) {
F_29 ( & V_27 -> V_31 , V_38 ) ;
return - V_55 ;
}
V_27 -> V_28 = V_54 ;
F_29 ( & V_27 -> V_31 , V_38 ) ;
for ( V_39 = 0 ; V_39 < F_34 ( V_27 -> V_53 ) ; V_39 ++ ) {
if ( V_27 -> V_53 [ V_39 ] )
F_37 ( V_27 -> V_53 [ V_39 ] ) ;
}
F_28 ( & V_27 -> V_31 , V_38 ) ;
F_30 ( V_27 , V_48 , 0xffffffff ) ;
F_30 ( V_27 , V_49 , 0xffffffff ) ;
F_30 ( V_27 , V_50 , 0 ) ;
F_30 ( V_27 , V_51 , 0 ) ;
V_27 -> V_28 = V_29 ;
F_29 ( & V_27 -> V_31 , V_38 ) ;
return 0 ;
}
int F_38 ( struct V_24 * V_27 )
{
int V_13 = 0 , V_39 ;
if ( ! V_27 )
return - V_55 ;
if ( V_27 -> V_28 != V_29 )
F_36 ( V_27 ) ;
for ( V_39 = 0 ; V_39 < F_34 ( V_27 -> V_53 ) ; V_39 ++ )
F_39 ( V_27 -> V_53 [ V_39 ] ) ;
F_1 ( V_27 -> V_2 ) ;
return V_13 ;
}
int F_40 ( struct V_24 * V_27 , bool V_56 )
{
unsigned long V_38 ;
int V_39 , V_57 ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
if ( V_27 -> V_28 != V_52 ) {
F_29 ( & V_27 -> V_31 , V_38 ) ;
return - V_55 ;
}
V_57 = V_56 ? V_58 : V_59 ;
F_30 ( V_27 , V_57 , V_60 ) ;
for ( V_39 = 0 ; V_39 < F_34 ( V_27 -> V_53 ) ; V_39 ++ ) {
if ( V_27 -> V_53 [ V_39 ] )
F_41 ( V_27 -> V_53 [ V_39 ] , V_56 ) ;
}
F_29 ( & V_27 -> V_31 , V_38 ) ;
return 0 ;
}
void F_42 ( struct V_24 * V_27 , T_1 V_61 )
{
F_30 ( V_27 , V_62 , V_61 ) ;
}
T_1 F_43 ( struct V_24 * V_27 )
{
return F_31 ( V_27 , V_63 ) ;
}
T_1 F_44 ( struct V_24 * V_27 )
{
return F_31 ( V_27 , V_64 ) ;
}
static void F_45 ( struct V_24 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_65 * V_66 ;
int V_67 ;
int V_39 ;
if ( ! V_27 -> V_30 )
return;
V_67 = V_2 -> V_18 / V_27 -> V_30 ;
for ( V_39 = 0 ; V_39 < F_34 ( V_27 -> V_53 ) ; V_39 ++ ) {
V_66 = V_27 -> V_53 [ V_39 ] ;
if ( V_66 )
V_66 -> V_68 = V_67 ;
}
}
struct V_65 * F_46 ( struct V_24 * V_27 , int V_30 ,
T_3 V_69 , int V_70 )
{
int V_71 = V_30 * 4 ;
struct V_65 * V_66 ;
unsigned long V_38 ;
V_30 = V_70 ? F_47 ( V_30 ) : F_48 ( V_30 ) ;
if ( F_49 ( V_30 ) >= V_27 -> V_36 )
return NULL ;
V_66 = F_8 ( V_27 -> V_5 , sizeof( * V_66 ) , V_14 ) ;
if ( ! V_66 )
return F_50 ( - V_72 ) ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
if ( V_27 -> V_53 [ V_30 ] ) {
F_29 ( & V_27 -> V_31 , V_38 ) ;
F_51 ( V_27 -> V_5 , V_66 ) ;
return F_50 ( - V_40 ) ;
}
V_66 -> V_27 = V_27 ;
V_66 -> V_28 = V_29 ;
V_66 -> V_30 = V_30 ;
V_66 -> V_69 = V_69 ;
V_66 -> V_68 = V_27 -> V_2 -> V_18 / 2 ;
if ( F_52 ( V_66 ) ) {
V_66 -> V_73 = V_27 -> V_26 . V_45 + V_71 ;
V_66 -> V_74 = V_27 -> V_26 . V_47 + V_71 ;
V_66 -> V_75 = V_27 -> V_26 . V_75 + V_71 ;
V_66 -> V_76 = V_77 ;
V_66 -> V_78 = V_48 ;
V_66 -> V_79 = V_80 ;
V_66 -> V_81 = V_82 ;
} else {
V_66 -> V_73 = V_27 -> V_26 . V_44 + V_71 ;
V_66 -> V_74 = V_27 -> V_26 . V_46 + V_71 ;
V_66 -> V_76 = V_83 ;
V_66 -> V_78 = V_49 ;
V_66 -> V_79 = V_84 ;
V_66 -> V_81 = V_85 ;
}
V_66 -> V_86 = F_53 ( F_54 ( V_66 ) ) ;
F_25 ( & V_66 -> V_31 ) ;
V_27 -> V_53 [ V_30 ] = V_66 ;
V_27 -> V_30 ++ ;
F_45 ( V_27 ) ;
F_29 ( & V_27 -> V_31 , V_38 ) ;
return V_66 ;
}
int F_55 ( struct V_65 * V_66 )
{
unsigned long V_38 ;
int V_68 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
V_68 = V_66 -> V_68 ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
return V_68 ;
}
int F_39 ( struct V_65 * V_66 )
{
struct V_24 * V_27 ;
unsigned long V_38 ;
if ( ! V_66 )
return - V_55 ;
V_27 = V_66 -> V_27 ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
if ( V_66 -> V_28 != V_29 )
F_37 ( V_66 ) ;
V_27 -> V_53 [ V_66 -> V_30 ] = NULL ;
V_27 -> V_30 -- ;
F_45 ( V_27 ) ;
F_29 ( & V_27 -> V_31 , V_38 ) ;
return 0 ;
}
int F_56 ( struct V_65 * V_66 ,
struct V_87 * V_88 )
{
unsigned long V_38 ;
if ( ! V_66 )
return - V_55 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
memcpy ( V_88 , & V_66 -> V_88 , sizeof( * V_88 ) ) ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
static void F_57 ( struct V_65 * V_66 ,
struct V_17 V_19 * V_22 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_17 V_19 * V_89 = V_66 -> V_90 ;
struct V_1 * V_2 = V_27 -> V_2 ;
T_2 V_91 ;
T_1 V_92 ;
V_91 = F_18 ( V_2 , V_22 ) ;
if ( ! V_66 -> V_93 ) {
V_66 -> V_88 . V_94 ++ ;
V_66 -> V_93 = V_22 ;
V_66 -> V_90 = V_22 ;
if ( V_66 -> V_28 == V_52 )
F_58 ( V_66 , V_73 , V_91 ) ;
return;
}
F_59 ( V_89 , V_95 , V_91 ) ;
V_66 -> V_90 = V_22 ;
V_66 -> V_88 . V_96 ++ ;
V_92 = F_60 ( V_89 , V_97 ) ;
if ( ( ( V_92 & ( V_98 | V_99 ) ) == V_98 ) &&
( V_66 -> V_28 == V_52 ) ) {
F_59 ( V_89 , V_97 , V_92 & ~ V_98 ) ;
F_58 ( V_66 , V_73 , V_91 ) ;
V_66 -> V_88 . V_100 ++ ;
}
}
int F_61 ( struct V_65 * V_66 , void * V_101 , void * V_102 ,
int V_103 , int V_104 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_17 V_19 * V_22 ;
T_2 V_105 ;
unsigned long V_38 ;
T_1 V_92 ;
int V_13 = 0 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_28 == V_54 ) {
V_13 = - V_55 ;
goto V_106;
}
if ( V_66 -> V_107 >= V_66 -> V_68 ) {
V_66 -> V_88 . V_108 ++ ;
V_13 = - V_72 ;
goto V_106;
}
V_22 = F_20 ( V_27 -> V_2 ) ;
if ( ! V_22 ) {
V_66 -> V_88 . V_108 ++ ;
V_13 = - V_72 ;
goto V_106;
}
if ( V_103 < V_27 -> V_26 . V_109 ) {
V_103 = V_27 -> V_26 . V_109 ;
V_66 -> V_88 . V_110 ++ ;
}
V_105 = F_62 ( V_27 -> V_5 , V_102 , V_103 , V_66 -> V_81 ) ;
V_13 = F_63 ( V_27 -> V_5 , V_105 ) ;
if ( V_13 ) {
F_22 ( V_27 -> V_2 , V_22 , 1 ) ;
V_13 = - V_55 ;
goto V_106;
}
V_92 = V_99 | V_111 | V_112 ;
F_64 ( V_66 , V_92 , V_104 ) ;
F_59 ( V_22 , V_95 , 0 ) ;
F_59 ( V_22 , V_113 , V_105 ) ;
F_59 ( V_22 , V_114 , V_103 ) ;
F_59 ( V_22 , V_97 , V_92 | V_103 ) ;
F_59 ( V_22 , V_115 , V_101 ) ;
F_59 ( V_22 , V_116 , V_105 ) ;
F_59 ( V_22 , V_117 , V_103 ) ;
F_57 ( V_66 , V_22 ) ;
if ( V_66 -> V_28 == V_52 && V_66 -> V_75 )
F_58 ( V_66 , V_75 , 1 ) ;
V_66 -> V_107 ++ ;
V_106:
F_29 ( & V_66 -> V_31 , V_38 ) ;
return V_13 ;
}
bool F_65 ( struct V_65 * V_66 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_2 ;
bool V_118 ;
unsigned long V_38 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
V_118 = ( V_66 -> V_107 < V_66 -> V_68 ) &&
F_4 ( V_2 -> V_3 ) ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
return V_118 ;
}
static void F_66 ( struct V_65 * V_66 ,
struct V_17 V_19 * V_22 ,
int V_119 , int V_120 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_2 ;
T_2 V_121 ;
int V_122 ;
void * V_101 ;
V_101 = ( void * ) F_60 ( V_22 , V_115 ) ;
V_121 = F_60 ( V_22 , V_116 ) ;
V_122 = F_60 ( V_22 , V_117 ) ;
F_67 ( V_27 -> V_5 , V_121 , V_122 , V_66 -> V_81 ) ;
F_22 ( V_2 , V_22 , 1 ) ;
(* V_66 -> V_69 )( V_101 , V_119 , V_120 ) ;
}
static int F_68 ( struct V_65 * V_66 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_17 V_19 * V_22 ;
int V_120 , V_119 ;
int V_123 = 0 ;
struct V_1 * V_2 = V_27 -> V_2 ;
T_2 V_91 ;
unsigned long V_38 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
V_22 = V_66 -> V_93 ;
if ( ! V_22 ) {
V_66 -> V_88 . V_124 ++ ;
V_120 = - V_125 ;
goto V_106;
}
V_91 = F_18 ( V_2 , V_22 ) ;
V_120 = F_69 ( & V_22 -> V_97 ) ;
V_119 = V_120 & 0x7ff ;
if ( V_120 & V_99 ) {
V_66 -> V_88 . V_126 ++ ;
V_120 = - V_40 ;
goto V_106;
}
if ( V_120 & V_127 )
V_119 -= V_128 ;
V_120 = V_120 & ( V_98 | V_129 |
V_130 ) ;
V_66 -> V_93 = F_19 ( V_2 , F_60 ( V_22 , V_95 ) ) ;
F_58 ( V_66 , V_74 , V_91 ) ;
V_66 -> V_107 -- ;
V_66 -> V_88 . V_131 ++ ;
if ( V_120 & V_98 ) {
V_66 -> V_88 . V_132 ++ ;
F_58 ( V_66 , V_73 , F_18 ( V_2 , V_66 -> V_93 ) ) ;
}
F_29 ( & V_66 -> V_31 , V_38 ) ;
if ( F_70 ( V_120 & V_129 ) )
V_123 = - V_133 ;
else
V_123 = V_120 ;
F_66 ( V_66 , V_22 , V_119 , V_123 ) ;
return V_120 ;
V_106:
F_29 ( & V_66 -> V_31 , V_38 ) ;
return V_120 ;
}
int F_71 ( struct V_65 * V_66 , int V_134 )
{
int V_135 = 0 , V_13 = 0 ;
if ( V_66 -> V_28 != V_52 )
return - V_55 ;
while ( V_135 < V_134 ) {
V_13 = F_68 ( V_66 ) ;
if ( V_13 < 0 )
break;
V_135 ++ ;
}
return V_135 ;
}
int F_35 ( struct V_65 * V_66 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_38 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_28 != V_29 ) {
F_29 ( & V_66 -> V_31 , V_38 ) ;
return - V_40 ;
}
if ( V_27 -> V_28 != V_52 ) {
F_29 ( & V_66 -> V_31 , V_38 ) ;
return - V_55 ;
}
F_30 ( V_27 , V_66 -> V_76 , V_66 -> V_86 ) ;
V_66 -> V_28 = V_52 ;
if ( V_66 -> V_93 ) {
F_58 ( V_66 , V_73 , F_18 ( V_2 , V_66 -> V_93 ) ) ;
if ( V_66 -> V_75 )
F_58 ( V_66 , V_75 , V_66 -> V_107 ) ;
}
F_29 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
int F_37 ( struct V_65 * V_66 )
{
struct V_24 * V_27 = V_66 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_38 ;
int V_13 ;
unsigned V_42 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_28 == V_54 ) {
F_29 ( & V_66 -> V_31 , V_38 ) ;
return - V_55 ;
}
V_66 -> V_28 = V_54 ;
F_30 ( V_27 , V_66 -> V_78 , V_66 -> V_86 ) ;
F_30 ( V_27 , V_66 -> V_79 , F_54 ( V_66 ) ) ;
V_42 = 100 * 100 ;
while ( V_42 ) {
T_1 V_74 = F_72 ( V_66 , V_74 ) ;
if ( ( V_74 & V_136 ) == V_136 )
break;
F_32 ( 10 ) ;
V_42 -- ;
}
F_26 ( ! V_42 ) ;
F_58 ( V_66 , V_74 , V_136 ) ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
do {
V_13 = F_68 ( V_66 ) ;
if ( V_13 < 0 )
break;
} while ( ( V_13 & V_129 ) == 0 );
F_28 ( & V_66 -> V_31 , V_38 ) ;
while ( V_66 -> V_93 ) {
struct V_17 V_19 * V_22 = V_66 -> V_93 ;
T_2 V_137 ;
V_137 = F_60 ( V_22 , V_95 ) ;
V_66 -> V_93 = F_19 ( V_2 , V_137 ) ;
V_66 -> V_107 -- ;
V_66 -> V_88 . V_138 ++ ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
F_66 ( V_66 , V_22 , 0 , - V_133 ) ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
}
V_66 -> V_28 = V_29 ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
int F_41 ( struct V_65 * V_66 , bool V_56 )
{
unsigned long V_38 ;
F_28 ( & V_66 -> V_31 , V_38 ) ;
if ( V_66 -> V_28 != V_52 ) {
F_29 ( & V_66 -> V_31 , V_38 ) ;
return - V_55 ;
}
F_30 ( V_66 -> V_27 , V_56 ? V_66 -> V_76 : V_66 -> V_78 ,
V_66 -> V_86 ) ;
F_29 ( & V_66 -> V_31 , V_38 ) ;
return 0 ;
}
int F_73 ( struct V_24 * V_27 , int V_139 )
{
unsigned long V_38 ;
struct V_140 * V_141 = & V_142 [ V_139 ] ;
int V_13 ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
V_13 = - V_143 ;
if ( ! V_27 -> V_26 . V_144 )
goto V_106;
V_13 = - V_55 ;
if ( V_27 -> V_28 != V_52 )
goto V_106;
V_13 = - V_125 ;
if ( V_139 < 0 || V_139 >= F_34 ( V_142 ) )
goto V_106;
V_13 = - V_145 ;
if ( ( V_141 -> V_146 & V_147 ) != V_147 )
goto V_106;
V_13 = ( F_31 ( V_27 , V_141 -> V_57 ) >> V_141 -> V_148 ) & V_141 -> V_86 ;
V_106:
F_29 ( & V_27 -> V_31 , V_38 ) ;
return V_13 ;
}
int F_74 ( struct V_24 * V_27 , int V_139 , int V_61 )
{
unsigned long V_38 ;
struct V_140 * V_141 = & V_142 [ V_139 ] ;
int V_13 ;
T_1 V_149 ;
F_28 ( & V_27 -> V_31 , V_38 ) ;
V_13 = - V_143 ;
if ( ! V_27 -> V_26 . V_144 )
goto V_106;
V_13 = - V_55 ;
if ( V_27 -> V_28 != V_52 )
goto V_106;
V_13 = - V_125 ;
if ( V_139 < 0 || V_139 >= F_34 ( V_142 ) )
goto V_106;
V_13 = - V_145 ;
if ( ( V_141 -> V_146 & V_150 ) != V_150 )
goto V_106;
V_149 = F_31 ( V_27 , V_141 -> V_57 ) ;
V_149 &= ~ ( V_141 -> V_86 << V_141 -> V_148 ) ;
V_149 |= ( V_61 & V_141 -> V_86 ) << V_141 -> V_148 ;
F_30 ( V_27 , V_141 -> V_57 , V_149 ) ;
V_13 = 0 ;
V_106:
F_29 ( & V_27 -> V_31 , V_38 ) ;
return V_13 ;
}
