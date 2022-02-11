static inline int F_1 ( unsigned int V_1 )
{
if ( F_2 ( V_1 >= V_2 . V_3 ) ) {
F_3 ( L_1 , V_1 ) ;
return V_4 [ V_2 . V_5 ] . V_6 ;
}
return V_4 [ V_1 ] . V_6 ;
}
static inline unsigned int F_4 ( int V_7 )
{
int V_8 = V_4 [ V_2 . V_8 ] . V_6 ;
int V_9 = V_4 [ V_2 . V_9 ] . V_6 ;
if ( V_8 > 0 ) {
if ( F_2 ( ( V_7 < V_9 ) || ( V_7 > V_8 ) ) ) {
F_3 ( L_2 , V_7 ) ;
return V_2 . V_5 ;
}
} else {
if ( F_2 ( ( V_7 > V_9 ) || ( V_7 < V_8 ) ) ) {
F_3 ( L_2 , V_7 ) ;
return V_2 . V_5 ;
}
}
return abs ( V_7 - F_1 ( V_2 . V_9 ) ) ;
}
static inline void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_6 ;
V_13 -> V_14 = 0 ;
V_13 -> V_15 = 0 ;
V_13 -> V_16 = 0 ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 = 0 ;
}
static int F_6 ( void )
{
struct V_19 * V_20 ;
int V_1 , V_3 = 0 ;
const T_1 * V_21 , * V_22 ;
T_2 V_23 , V_24 ;
T_2 V_25 , V_26 , V_27 ;
T_2 V_28 , V_29 ;
V_20 = F_7 ( L_3 ) ;
if ( ! V_20 ) {
F_8 ( L_4 ) ;
return - V_30 ;
}
if ( F_9 ( V_20 , L_5 , & V_25 ) ) {
F_8 ( L_6 ) ;
return - V_30 ;
}
if ( F_9 ( V_20 , L_7 , & V_26 ) ) {
F_8 ( L_8 ) ;
return - V_30 ;
}
if ( F_9 ( V_20 , L_9 ,
& V_27 ) ) {
F_8 ( L_10 ) ;
return - V_30 ;
}
if ( F_9 ( V_20 , L_11 ,
& V_29 ) ) {
V_2 . V_31 = false ;
goto V_32;
}
if ( F_9 ( V_20 , L_12 ,
& V_28 ) ) {
V_2 . V_31 = false ;
goto V_32;
}
if ( V_28 == V_29 )
V_2 . V_31 = false ;
else
V_2 . V_31 = true ;
V_32:
F_10 ( L_13 , V_25 ,
V_27 , V_26 ) ;
F_10 ( L_14 ,
( V_2 . V_31 ) ? L_15 : L_16 ) ;
V_21 = F_11 ( V_20 , L_17 , & V_23 ) ;
if ( ! V_21 ) {
F_8 ( L_18 ) ;
return - V_30 ;
}
V_22 = F_11 ( V_20 , L_19 ,
& V_24 ) ;
if ( ! V_22 ) {
F_8 ( L_20 ) ;
return - V_30 ;
}
if ( V_23 != V_24 ) {
F_8 ( L_21
L_22 ) ;
}
V_3 = V_8 ( V_23 , V_24 ) / sizeof( T_2 ) ;
if ( ! V_3 ) {
F_8 ( L_23 ) ;
return - V_30 ;
}
V_2 . V_3 = V_3 ;
F_12 ( L_24 , V_3 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
T_2 V_33 = F_13 ( V_21 [ V_1 ] ) ;
T_2 V_34 = F_13 ( V_22 [ V_1 ] ) ;
F_12 ( L_25 , V_33 , V_34 ) ;
V_4 [ V_1 ] . V_35 = V_34 * 1000 ;
V_4 [ V_1 ] . V_6 = V_33 ;
if ( V_33 == V_26 )
V_2 . V_9 = V_1 ;
else if ( V_33 == V_27 )
V_2 . V_5 = V_1 ;
else if ( V_33 == V_25 )
V_2 . V_8 = V_1 ;
if ( V_2 . V_31 && V_33 == V_28 ) {
int V_36 ;
for ( V_36 = V_1 - 1 ; V_36 >= ( int ) V_2 . V_9 ; V_36 -- )
V_4 [ V_36 ] . V_37 = V_38 ;
}
}
V_4 [ V_1 ] . V_35 = V_39 ;
return 0 ;
}
static unsigned int F_14 ( int V_40 )
{
int V_1 ;
V_1 = F_4 ( V_40 ) ;
if ( V_1 >= V_2 . V_3 || V_1 < 0 ) {
F_8 ( L_26
L_27 ,
V_40 , F_1 ( V_2 . V_5 ) ) ;
V_1 = V_2 . V_5 ;
}
return V_4 [ V_1 ] . V_35 ;
}
static T_3 F_15 ( struct V_10 * V_11 ,
char * V_41 )
{
return sprintf ( V_41 , L_28 ,
V_4 [ V_2 . V_5 ] . V_35 ) ;
}
static inline unsigned long F_16 ( unsigned long V_42 )
{
switch ( V_42 ) {
case V_43 :
return F_17 ( V_43 ) ;
case V_44 :
return F_17 ( V_44 ) ;
case V_45 :
return F_17 ( V_45 ) ;
}
F_18 () ;
}
static inline void F_19 ( unsigned long V_42 , unsigned long V_46 )
{
switch ( V_42 ) {
case V_43 :
F_20 ( V_43 , V_46 ) ;
return;
case V_44 :
F_20 ( V_44 , V_46 ) ;
return;
}
F_18 () ;
}
static void F_21 ( void * V_47 )
{
unsigned long V_48 ;
T_4 V_49 ;
struct V_50 * V_51 = V_47 ;
V_48 = F_16 ( V_45 ) ;
V_49 = ( V_48 >> 48 ) & 0xFF ;
V_51 -> V_40 = V_49 ;
V_51 -> V_34 = F_14 ( V_51 -> V_40 ) ;
F_12 ( L_29 ,
F_22 () , V_48 , V_51 -> V_40 ,
V_51 -> V_34 ) ;
}
static unsigned int F_23 ( unsigned int V_52 )
{
struct V_50 V_51 ;
F_24 ( F_25 ( V_52 ) , F_21 ,
& V_51 , 1 ) ;
return V_51 . V_34 ;
}
static void F_26 ( void * V_53 )
{
unsigned long V_46 ;
struct V_50 * V_51 = V_53 ;
unsigned long V_54 = V_51 -> V_40 ;
unsigned long V_55 = V_51 -> V_56 ;
V_46 = F_16 ( V_43 ) ;
V_46 = V_46 & 0x0000FFFFFFFFFFFFULL ;
V_54 = V_54 & 0xFF ;
V_55 = V_55 & 0xFF ;
V_46 = V_46 | ( V_55 << 56 ) | ( V_54 << 48 ) ;
F_12 ( L_30 ,
F_22 () , V_46 ) ;
F_19 ( V_43 , V_46 ) ;
}
static inline unsigned int F_27 ( void )
{
return V_2 . V_5 ;
}
static void F_28 ( void * V_53 )
{
struct V_57 * V_57 ;
unsigned int V_52 = F_29 () ;
unsigned long V_58 ;
int V_59 ;
unsigned int V_60 ;
V_58 = F_16 ( V_45 ) ;
V_57 = F_30 ( V_61 ) ;
V_59 = ( T_4 ) F_31 ( V_58 ) ;
V_60 = F_4 ( V_59 ) ;
if ( V_60 != V_2 . V_9 ) {
if ( V_57 -> V_62 )
goto V_32;
V_57 -> V_62 = true ;
if ( V_60 > V_2 . V_5 ) {
F_3 ( L_31 ,
V_52 , V_57 -> V_33 , V_59 ,
F_1 ( V_2 . V_5 ) ) ;
V_57 -> V_63 ++ ;
} else {
V_57 -> V_64 ++ ;
}
F_32 ( V_57 -> V_33 ,
V_65 [ V_57 -> V_65 ] ,
V_59 ) ;
} else if ( V_57 -> V_62 ) {
V_57 -> V_62 = false ;
F_32 ( V_57 -> V_33 ,
V_65 [ V_57 -> V_65 ] ,
V_59 ) ;
}
V_32:
if ( V_58 & V_66 ) {
V_62 = true ;
F_10 ( L_32 ) ;
}
if ( V_58 & V_67 ) {
V_62 = true ;
F_10 ( L_33 ) ;
}
if ( V_62 ) {
F_10 ( L_34 , V_58 ) ;
F_8 ( L_35 ) ;
}
}
static inline int F_33 ( unsigned int V_15 ,
int V_14 ,
int V_68 )
{
int V_69 ;
V_69 = ( ( int ) F_34 ( V_15 ) *
( V_2 . V_8 - V_14 ) ) / 100 ;
if ( V_14 + V_69 >= V_68 )
return V_68 ;
else
return V_14 + V_69 ;
}
static inline void F_35 ( struct V_12 * V_13 )
{
unsigned int V_70 ;
if ( ( V_13 -> V_15 + V_71 )
> V_72 )
V_70 = V_72 - V_13 -> V_15 ;
else
V_70 = V_71 ;
F_36 ( & V_13 -> V_73 , V_74 + F_37 ( V_70 ) ) ;
}
void F_38 ( unsigned long V_53 )
{
struct V_10 * V_11 = (struct V_10 * ) V_53 ;
struct V_12 * V_13 = V_11 -> V_6 ;
int V_75 , V_76 ;
unsigned long V_46 ;
unsigned int V_77 = F_39 ( V_74 )
- V_13 -> V_16 ;
struct V_50 V_51 ;
if ( ! F_40 ( & V_13 -> V_78 ) )
return;
V_46 = F_16 ( V_43 ) ;
V_51 . V_56 = ( T_4 ) F_41 ( V_46 ) ;
V_51 . V_40 = ( T_4 ) F_42 ( V_46 ) ;
if ( V_51 . V_56 == V_51 . V_40 ) {
F_5 ( V_11 ) ;
F_43 ( & V_13 -> V_78 ) ;
return;
}
V_13 -> V_16 += V_77 ;
V_13 -> V_15 += V_77 ;
if ( V_13 -> V_15 > V_72 ) {
V_75 = F_4 ( V_51 . V_40 ) ;
V_76 = V_75 ;
F_5 ( V_11 ) ;
V_13 -> V_14 = V_75 ;
} else {
V_76 = F_4 ( V_51 . V_40 ) ;
V_75 = F_33 ( V_13 -> V_15 ,
V_13 -> V_14 ,
V_76 ) ;
}
V_51 . V_56 = F_1 ( V_75 ) ;
V_13 -> V_18 = V_75 ;
V_13 -> V_17 = V_76 ;
if ( V_75 != V_13 -> V_17 )
F_35 ( V_13 ) ;
F_43 ( & V_13 -> V_78 ) ;
F_24 ( V_11 -> V_79 , F_26 , & V_51 , 1 ) ;
}
static int F_44 ( struct V_10 * V_11 ,
unsigned int V_80 )
{
struct V_50 V_51 ;
unsigned int V_81 , V_75 ;
struct V_12 * V_13 = V_11 -> V_6 ;
if ( F_2 ( V_82 ) && V_80 != F_27 () )
return 0 ;
if ( ! V_62 ) {
F_45 () ;
F_28 ( NULL ) ;
F_46 () ;
}
V_81 = F_39 ( F_47 () ) ;
F_48 ( & V_13 -> V_78 ) ;
V_51 . V_40 = F_1 ( V_80 ) ;
if ( ! V_13 -> V_16 ) {
V_75 = V_80 ;
V_13 -> V_14 = V_80 ;
goto V_83;
}
if ( V_13 -> V_18 < V_80 ) {
V_13 -> V_15 += V_81 -
V_13 -> V_16 ;
if ( V_13 -> V_15 > V_72 ) {
F_5 ( V_11 ) ;
V_13 -> V_14 = V_80 ;
V_75 = V_80 ;
} else {
V_75 = F_33 ( V_13 -> V_15 ,
V_13 -> V_14 ,
V_80 ) ;
}
} else {
F_5 ( V_11 ) ;
V_13 -> V_14 = V_80 ;
V_75 = V_80 ;
}
if ( V_75 != V_80 )
F_35 ( V_13 ) ;
else
F_49 ( & V_13 -> V_73 ) ;
V_83:
V_51 . V_56 = F_1 ( V_75 ) ;
V_13 -> V_16 = V_81 ;
V_13 -> V_18 = V_75 ;
V_13 -> V_17 = V_80 ;
F_43 ( & V_13 -> V_78 ) ;
F_24 ( V_11 -> V_79 , F_26 , & V_51 , 1 ) ;
return 0 ;
}
static int F_50 ( struct V_10 * V_11 )
{
int V_84 , V_1 , V_85 ;
struct V_86 * V_87 ;
struct V_12 * V_13 ;
V_84 = F_51 ( V_11 -> V_52 ) ;
for ( V_1 = 0 ; V_1 < V_88 ; V_1 ++ )
F_52 ( V_84 + V_1 , V_11 -> V_79 ) ;
V_87 = F_53 ( V_11 -> V_89 . V_90 , V_91 . V_92 ) ;
if ( ! V_87 ) {
int V_85 ;
V_85 = F_54 ( & V_11 -> V_89 , & V_91 ) ;
if ( V_85 ) {
F_10 ( L_36 ,
V_11 -> V_52 ) ;
return V_85 ;
}
} else {
F_55 ( V_87 ) ;
}
V_13 = F_56 ( sizeof( * V_13 ) , V_93 ) ;
if ( ! V_13 )
return - V_94 ;
V_11 -> V_6 = V_13 ;
F_57 ( & V_13 -> V_73 ) ;
V_13 -> V_73 . V_53 = ( unsigned long ) V_11 ;
V_13 -> V_73 . V_95 = F_38 ;
V_13 -> V_73 . V_96 = V_74 +
F_37 ( V_71 ) ;
F_58 ( & V_13 -> V_78 ) ;
V_85 = F_59 ( V_11 , V_4 ) ;
if ( V_85 < 0 ) {
F_60 ( V_11 -> V_6 ) ;
return V_85 ;
}
V_11 -> V_97 = true ;
return V_85 ;
}
static int F_61 ( struct V_10 * V_11 )
{
F_60 ( V_11 -> V_6 ) ;
return 0 ;
}
static int F_62 ( struct V_98 * V_99 ,
unsigned long V_100 , void * V_101 )
{
int V_52 ;
struct V_10 V_102 ;
V_82 = true ;
F_63 (cpu) {
F_64 ( & V_102 , V_52 ) ;
F_44 ( & V_102 , F_27 () ) ;
}
return V_103 ;
}
void F_65 ( struct V_104 * V_105 )
{
struct V_57 * V_57 = F_66 ( V_105 , struct V_57 , V_106 ) ;
unsigned int V_52 ;
T_5 V_107 ;
F_67 () ;
F_68 ( & V_107 , & V_57 -> V_107 , V_108 ) ;
F_24 ( & V_107 ,
F_28 , NULL , 0 ) ;
if ( ! V_57 -> V_109 )
goto V_110;
V_57 -> V_109 = false ;
F_69 (cpu, &mask) {
int V_111 ;
struct V_10 V_11 ;
F_64 ( & V_11 , V_52 ) ;
V_111 = F_70 ( & V_11 , V_11 . V_112 ) ;
F_44 ( & V_11 , V_111 ) ;
F_71 ( & V_107 , & V_107 , V_11 . V_79 ) ;
}
V_110:
F_72 () ;
}
static int F_73 ( struct V_98 * V_99 ,
unsigned long V_113 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
struct V_117 V_118 ;
int V_1 ;
if ( V_113 != V_119 )
return 0 ;
V_118 . type = F_74 ( V_116 -> V_120 [ 0 ] ) ;
switch ( V_118 . type ) {
case V_121 :
V_122 = true ;
F_10 ( L_37 ) ;
if ( ! V_62 ) {
V_62 = true ;
F_8 ( L_38 ) ;
}
break;
case V_123 :
F_10 ( L_39 ) ;
break;
case V_124 :
V_118 . V_57 = F_74 ( V_116 -> V_120 [ 1 ] ) ;
V_118 . V_125 = F_74 ( V_116 -> V_120 [ 2 ] ) ;
if ( V_122 ) {
V_122 = false ;
V_62 = false ;
F_10 ( L_40 ) ;
for ( V_1 = 0 ; V_1 < V_126 ; V_1 ++ ) {
V_127 [ V_1 ] . V_109 = true ;
F_75 ( & V_127 [ V_1 ] . V_106 ) ;
}
return 0 ;
}
for ( V_1 = 0 ; V_1 < V_126 ; V_1 ++ )
if ( V_127 [ V_1 ] . V_33 == V_118 . V_57 )
break;
if ( V_118 . V_125 >= 0 &&
V_118 . V_125 <= V_128 ) {
V_127 [ V_1 ] . V_65 = V_118 . V_125 ;
V_127 [ V_1 ] . V_129 [ V_118 . V_125 ] ++ ;
}
if ( ! V_118 . V_125 )
V_127 [ V_1 ] . V_109 = true ;
F_75 ( & V_127 [ V_1 ] . V_106 ) ;
}
return 0 ;
}
static void F_76 ( struct V_10 * V_11 )
{
struct V_50 V_51 ;
struct V_12 * V_13 = V_11 -> V_6 ;
V_51 . V_40 = F_1 ( V_2 . V_8 ) ;
V_51 . V_56 = F_1 ( V_2 . V_8 ) ;
F_77 ( V_11 -> V_52 , F_26 , & V_51 , 1 ) ;
F_49 ( & V_13 -> V_73 ) ;
}
static unsigned int F_78 ( struct V_10 * V_11 ,
unsigned int V_130 )
{
int V_111 ;
struct V_50 V_51 ;
V_111 = F_79 ( V_11 , V_130 ) ;
V_51 . V_40 = V_4 [ V_111 ] . V_6 ;
V_51 . V_56 = V_4 [ V_111 ] . V_6 ;
F_26 ( & V_51 ) ;
return V_4 [ V_111 ] . V_35 ;
}
static int F_80 ( void )
{
unsigned int V_57 [ 256 ] ;
unsigned int V_52 , V_1 ;
unsigned int V_131 = V_132 ;
F_81 (cpu) {
unsigned int V_33 = F_82 ( V_52 ) ;
if ( V_131 != V_33 ) {
V_131 = V_33 ;
V_57 [ V_126 ++ ] = V_33 ;
}
}
V_127 = F_83 ( V_126 , sizeof( struct V_57 ) , V_93 ) ;
if ( ! V_127 )
return - V_94 ;
for ( V_1 = 0 ; V_1 < V_126 ; V_1 ++ ) {
V_127 [ V_1 ] . V_33 = V_57 [ V_1 ] ;
F_84 ( & V_127 [ V_1 ] . V_107 , F_85 ( V_57 [ V_1 ] ) ) ;
F_86 ( & V_127 [ V_1 ] . V_106 , F_65 ) ;
F_69 (cpu, &chips[i].mask)
F_87 ( V_61 , V_52 ) = & V_127 [ V_1 ] ;
}
return 0 ;
}
static inline void F_88 ( void )
{
F_60 ( V_127 ) ;
}
static inline void F_89 ( void )
{
F_90 ( V_119 ,
& V_133 ) ;
F_91 ( & V_134 ) ;
}
static int T_6 F_92 ( void )
{
int V_135 = 0 ;
if ( ! F_93 ( V_136 ) )
return - V_30 ;
V_135 = F_6 () ;
if ( V_135 )
goto V_110;
V_135 = F_80 () ;
if ( V_135 )
goto V_110;
F_94 ( & V_134 ) ;
F_95 ( V_119 , & V_133 ) ;
if ( V_2 . V_31 )
V_137 . V_138 = true ;
else
V_139 [ V_140 ] = NULL ;
V_135 = F_96 ( & V_137 ) ;
if ( V_135 ) {
F_10 ( L_41 , V_135 ) ;
goto V_141;
}
if ( V_2 . V_31 )
F_97 () ;
return 0 ;
V_141:
F_89 () ;
F_88 () ;
V_110:
F_10 ( L_42 ) ;
return V_135 ;
}
static void T_7 F_98 ( void )
{
F_99 ( & V_137 ) ;
F_89 () ;
F_88 () ;
}
