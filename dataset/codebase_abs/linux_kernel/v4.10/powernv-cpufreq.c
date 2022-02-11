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
V_20 = F_7 ( L_3 ) ;
if ( ! V_20 ) {
F_8 ( L_4 ) ;
return - V_28 ;
}
if ( F_9 ( V_20 , L_5 , & V_25 ) ) {
F_8 ( L_6 ) ;
return - V_28 ;
}
if ( F_9 ( V_20 , L_7 , & V_26 ) ) {
F_8 ( L_8 ) ;
return - V_28 ;
}
if ( F_9 ( V_20 , L_9 ,
& V_27 ) ) {
F_8 ( L_10 ) ;
return - V_28 ;
}
F_10 ( L_11 , V_25 ,
V_27 , V_26 ) ;
V_21 = F_11 ( V_20 , L_12 , & V_23 ) ;
if ( ! V_21 ) {
F_8 ( L_13 ) ;
return - V_28 ;
}
V_22 = F_11 ( V_20 , L_14 ,
& V_24 ) ;
if ( ! V_22 ) {
F_8 ( L_15 ) ;
return - V_28 ;
}
if ( V_23 != V_24 ) {
F_8 ( L_16
L_17 ) ;
}
V_3 = V_8 ( V_23 , V_24 ) / sizeof( T_2 ) ;
if ( ! V_3 ) {
F_8 ( L_18 ) ;
return - V_28 ;
}
V_2 . V_3 = V_3 ;
F_12 ( L_19 , V_3 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
T_2 V_29 = F_13 ( V_21 [ V_1 ] ) ;
T_2 V_30 = F_13 ( V_22 [ V_1 ] ) ;
F_12 ( L_20 , V_29 , V_30 ) ;
V_4 [ V_1 ] . V_31 = V_30 * 1000 ;
V_4 [ V_1 ] . V_6 = V_29 ;
if ( V_29 == V_26 )
V_2 . V_9 = V_1 ;
else if ( V_29 == V_27 )
V_2 . V_5 = V_1 ;
else if ( V_29 == V_25 )
V_2 . V_8 = V_1 ;
}
V_4 [ V_1 ] . V_31 = V_32 ;
return 0 ;
}
static unsigned int F_14 ( int V_33 )
{
int V_1 ;
V_1 = F_4 ( V_33 ) ;
if ( V_1 >= V_2 . V_3 || V_1 < 0 ) {
F_8 ( L_21
L_22 ,
V_33 , F_1 ( V_2 . V_5 ) ) ;
V_1 = V_2 . V_5 ;
}
return V_4 [ V_1 ] . V_31 ;
}
static T_3 F_15 ( struct V_10 * V_11 ,
char * V_34 )
{
return sprintf ( V_34 , L_23 ,
V_4 [ V_2 . V_5 ] . V_31 ) ;
}
static inline unsigned long F_16 ( unsigned long V_35 )
{
switch ( V_35 ) {
case V_36 :
return F_17 ( V_36 ) ;
case V_37 :
return F_17 ( V_37 ) ;
case V_38 :
return F_17 ( V_38 ) ;
}
F_18 () ;
}
static inline void F_19 ( unsigned long V_35 , unsigned long V_39 )
{
switch ( V_35 ) {
case V_36 :
F_20 ( V_36 , V_39 ) ;
return;
case V_37 :
F_20 ( V_37 , V_39 ) ;
return;
}
F_18 () ;
}
static void F_21 ( void * V_40 )
{
unsigned long V_41 ;
T_4 V_42 ;
struct V_43 * V_44 = V_40 ;
V_41 = F_16 ( V_38 ) ;
V_42 = ( V_41 >> 48 ) & 0xFF ;
V_44 -> V_33 = V_42 ;
V_44 -> V_30 = F_14 ( V_44 -> V_33 ) ;
F_12 ( L_24 ,
F_22 () , V_41 , V_44 -> V_33 ,
V_44 -> V_30 ) ;
}
static unsigned int F_23 ( unsigned int V_45 )
{
struct V_43 V_44 ;
F_24 ( F_25 ( V_45 ) , F_21 ,
& V_44 , 1 ) ;
return V_44 . V_30 ;
}
static void F_26 ( void * V_46 )
{
unsigned long V_39 ;
struct V_43 * V_44 = V_46 ;
unsigned long V_47 = V_44 -> V_33 ;
unsigned long V_48 = V_44 -> V_49 ;
V_39 = F_16 ( V_36 ) ;
V_39 = V_39 & 0x0000FFFFFFFFFFFFULL ;
V_47 = V_47 & 0xFF ;
V_48 = V_48 & 0xFF ;
V_39 = V_39 | ( V_48 << 56 ) | ( V_47 << 48 ) ;
F_12 ( L_25 ,
F_22 () , V_39 ) ;
F_19 ( V_36 , V_39 ) ;
}
static inline unsigned int F_27 ( void )
{
return V_2 . V_5 ;
}
static void F_28 ( void * V_46 )
{
struct V_50 * V_50 ;
unsigned int V_45 = F_29 () ;
unsigned long V_51 ;
int V_52 ;
unsigned int V_53 ;
V_51 = F_16 ( V_38 ) ;
V_50 = F_30 ( V_54 ) ;
V_52 = ( T_4 ) F_31 ( V_51 ) ;
V_53 = F_4 ( V_52 ) ;
if ( V_53 != V_2 . V_9 ) {
if ( V_50 -> V_55 )
goto V_56;
V_50 -> V_55 = true ;
if ( V_53 > V_2 . V_5 ) {
F_3 ( L_26 ,
V_45 , V_50 -> V_29 , V_52 ,
F_1 ( V_2 . V_5 ) ) ;
V_50 -> V_57 ++ ;
} else {
V_50 -> V_58 ++ ;
}
F_32 ( V_50 -> V_29 ,
V_59 [ V_50 -> V_59 ] ,
V_52 ) ;
} else if ( V_50 -> V_55 ) {
V_50 -> V_55 = false ;
F_32 ( V_50 -> V_29 ,
V_59 [ V_50 -> V_59 ] ,
V_52 ) ;
}
V_56:
if ( V_51 & V_60 ) {
V_55 = true ;
F_10 ( L_27 ) ;
}
if ( V_51 & V_61 ) {
V_55 = true ;
F_10 ( L_28 ) ;
}
if ( V_55 ) {
F_10 ( L_29 , V_51 ) ;
F_8 ( L_30 ) ;
}
}
static inline int F_33 ( unsigned int V_15 ,
int V_14 ,
int V_62 )
{
int V_63 ;
V_63 = ( ( int ) F_34 ( V_15 ) *
( V_2 . V_8 - V_14 ) ) / 100 ;
if ( V_14 + V_63 >= V_62 )
return V_62 ;
else
return V_14 + V_63 ;
}
static inline void F_35 ( struct V_12 * V_13 )
{
unsigned int V_64 ;
if ( ( V_13 -> V_15 + V_65 )
> V_66 )
V_64 = V_66 - V_13 -> V_15 ;
else
V_64 = V_65 ;
F_36 ( & V_13 -> V_67 , V_68 + F_37 ( V_64 ) ) ;
}
void F_38 ( unsigned long V_46 )
{
struct V_10 * V_11 = (struct V_10 * ) V_46 ;
struct V_12 * V_13 = V_11 -> V_6 ;
int V_69 , V_70 ;
unsigned long V_39 ;
unsigned int V_71 = F_39 ( V_68 )
- V_13 -> V_16 ;
struct V_43 V_44 ;
if ( ! F_40 ( & V_13 -> V_72 ) )
return;
V_39 = F_16 ( V_36 ) ;
V_44 . V_49 = ( T_4 ) F_41 ( V_39 ) ;
V_44 . V_33 = ( T_4 ) F_42 ( V_39 ) ;
if ( V_44 . V_49 == V_44 . V_33 ) {
F_5 ( V_11 ) ;
F_43 ( & V_13 -> V_72 ) ;
return;
}
V_13 -> V_16 += V_71 ;
V_13 -> V_15 += V_71 ;
if ( V_13 -> V_15 > V_66 ) {
V_69 = F_4 ( V_44 . V_33 ) ;
V_70 = V_69 ;
F_5 ( V_11 ) ;
V_13 -> V_14 = V_69 ;
} else {
V_70 = F_4 ( V_44 . V_33 ) ;
V_69 = F_33 ( V_13 -> V_15 ,
V_13 -> V_14 ,
V_70 ) ;
}
V_44 . V_49 = F_1 ( V_69 ) ;
V_13 -> V_18 = V_69 ;
V_13 -> V_17 = V_70 ;
if ( V_69 != V_13 -> V_17 )
F_35 ( V_13 ) ;
F_43 ( & V_13 -> V_72 ) ;
F_24 ( V_11 -> V_73 , F_26 , & V_44 , 1 ) ;
}
static int F_44 ( struct V_10 * V_11 ,
unsigned int V_74 )
{
struct V_43 V_44 ;
unsigned int V_75 , V_69 ;
struct V_12 * V_13 = V_11 -> V_6 ;
if ( F_2 ( V_76 ) && V_74 != F_27 () )
return 0 ;
if ( ! V_55 ) {
F_45 () ;
F_28 ( NULL ) ;
F_46 () ;
}
V_75 = F_39 ( F_47 () ) ;
F_48 ( & V_13 -> V_72 ) ;
V_44 . V_33 = F_1 ( V_74 ) ;
if ( ! V_13 -> V_16 ) {
V_69 = V_74 ;
V_13 -> V_14 = V_74 ;
goto V_77;
}
if ( V_13 -> V_18 < V_74 ) {
V_13 -> V_15 += V_75 -
V_13 -> V_16 ;
if ( V_13 -> V_15 > V_66 ) {
F_5 ( V_11 ) ;
V_13 -> V_14 = V_74 ;
V_69 = V_74 ;
} else {
V_69 = F_33 ( V_13 -> V_15 ,
V_13 -> V_14 ,
V_74 ) ;
}
} else {
F_5 ( V_11 ) ;
V_13 -> V_14 = V_74 ;
V_69 = V_74 ;
}
if ( V_69 != V_74 )
F_35 ( V_13 ) ;
else
F_49 ( & V_13 -> V_67 ) ;
V_77:
V_44 . V_49 = F_1 ( V_69 ) ;
V_13 -> V_16 = V_75 ;
V_13 -> V_18 = V_69 ;
V_13 -> V_17 = V_74 ;
F_43 ( & V_13 -> V_72 ) ;
F_24 ( V_11 -> V_73 , F_26 , & V_44 , 1 ) ;
return 0 ;
}
static int F_50 ( struct V_10 * V_11 )
{
int V_78 , V_1 , V_79 ;
struct V_80 * V_81 ;
struct V_12 * V_13 ;
V_78 = F_51 ( V_11 -> V_45 ) ;
for ( V_1 = 0 ; V_1 < V_82 ; V_1 ++ )
F_52 ( V_78 + V_1 , V_11 -> V_73 ) ;
V_81 = F_53 ( V_11 -> V_83 . V_84 , V_85 . V_86 ) ;
if ( ! V_81 ) {
int V_79 ;
V_79 = F_54 ( & V_11 -> V_83 , & V_85 ) ;
if ( V_79 ) {
F_10 ( L_31 ,
V_11 -> V_45 ) ;
return V_79 ;
}
} else {
F_55 ( V_81 ) ;
}
V_13 = F_56 ( sizeof( * V_13 ) , V_87 ) ;
if ( ! V_13 )
return - V_88 ;
V_11 -> V_6 = V_13 ;
F_57 ( & V_13 -> V_67 ) ;
V_13 -> V_67 . V_46 = ( unsigned long ) V_11 ;
V_13 -> V_67 . V_89 = F_38 ;
V_13 -> V_67 . V_90 = V_68 +
F_37 ( V_65 ) ;
F_58 ( & V_13 -> V_72 ) ;
V_79 = F_59 ( V_11 , V_4 ) ;
if ( V_79 < 0 ) {
F_60 ( V_11 -> V_6 ) ;
return V_79 ;
}
V_11 -> V_91 = true ;
return V_79 ;
}
static int F_61 ( struct V_10 * V_11 )
{
F_60 ( V_11 -> V_6 ) ;
return 0 ;
}
static int F_62 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
int V_45 ;
struct V_10 V_96 ;
V_76 = true ;
F_63 (cpu) {
F_64 ( & V_96 , V_45 ) ;
F_44 ( & V_96 , F_27 () ) ;
}
return V_97 ;
}
void F_65 ( struct V_98 * V_99 )
{
struct V_50 * V_50 = F_66 ( V_99 , struct V_50 , V_100 ) ;
unsigned int V_45 ;
T_5 V_101 ;
F_67 () ;
F_68 ( & V_101 , & V_50 -> V_101 , V_102 ) ;
F_24 ( & V_101 ,
F_28 , NULL , 0 ) ;
if ( ! V_50 -> V_103 )
goto V_104;
V_50 -> V_103 = false ;
F_69 (cpu, &mask) {
int V_105 ;
struct V_10 V_11 ;
F_64 ( & V_11 , V_45 ) ;
V_105 = F_70 ( & V_11 , V_11 . V_106 ) ;
F_44 ( & V_11 , V_105 ) ;
F_71 ( & V_101 , & V_101 , V_11 . V_73 ) ;
}
V_104:
F_72 () ;
}
static int F_73 ( struct V_92 * V_93 ,
unsigned long V_107 , void * V_108 )
{
struct V_109 * V_110 = V_108 ;
struct V_111 V_112 ;
int V_1 ;
if ( V_107 != V_113 )
return 0 ;
V_112 . type = F_74 ( V_110 -> V_114 [ 0 ] ) ;
switch ( V_112 . type ) {
case V_115 :
V_116 = true ;
F_10 ( L_32 ) ;
if ( ! V_55 ) {
V_55 = true ;
F_8 ( L_33 ) ;
}
break;
case V_117 :
F_10 ( L_34 ) ;
break;
case V_118 :
V_112 . V_50 = F_74 ( V_110 -> V_114 [ 1 ] ) ;
V_112 . V_119 = F_74 ( V_110 -> V_114 [ 2 ] ) ;
if ( V_116 ) {
V_116 = false ;
V_55 = false ;
F_10 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_120 ; V_1 ++ ) {
V_121 [ V_1 ] . V_103 = true ;
F_75 ( & V_121 [ V_1 ] . V_100 ) ;
}
return 0 ;
}
for ( V_1 = 0 ; V_1 < V_120 ; V_1 ++ )
if ( V_121 [ V_1 ] . V_29 == V_112 . V_50 )
break;
if ( V_112 . V_119 >= 0 &&
V_112 . V_119 <= V_122 ) {
V_121 [ V_1 ] . V_59 = V_112 . V_119 ;
V_121 [ V_1 ] . V_123 [ V_112 . V_119 ] ++ ;
}
if ( ! V_112 . V_119 )
V_121 [ V_1 ] . V_103 = true ;
F_75 ( & V_121 [ V_1 ] . V_100 ) ;
}
return 0 ;
}
static void F_76 ( struct V_10 * V_11 )
{
struct V_43 V_44 ;
struct V_12 * V_13 = V_11 -> V_6 ;
V_44 . V_33 = F_1 ( V_2 . V_8 ) ;
V_44 . V_49 = F_1 ( V_2 . V_8 ) ;
F_77 ( V_11 -> V_45 , F_26 , & V_44 , 1 ) ;
F_49 ( & V_13 -> V_67 ) ;
}
static unsigned int F_78 ( struct V_10 * V_11 ,
unsigned int V_124 )
{
int V_105 ;
struct V_43 V_44 ;
V_105 = F_79 ( V_11 , V_124 ) ;
V_44 . V_33 = V_4 [ V_105 ] . V_6 ;
V_44 . V_49 = V_4 [ V_105 ] . V_6 ;
F_26 ( & V_44 ) ;
return V_4 [ V_105 ] . V_31 ;
}
static int F_80 ( void )
{
unsigned int V_50 [ 256 ] ;
unsigned int V_45 , V_1 ;
unsigned int V_125 = V_126 ;
F_81 (cpu) {
unsigned int V_29 = F_82 ( V_45 ) ;
if ( V_125 != V_29 ) {
V_125 = V_29 ;
V_50 [ V_120 ++ ] = V_29 ;
}
}
V_121 = F_83 ( V_120 , sizeof( struct V_50 ) , V_87 ) ;
if ( ! V_121 )
return - V_88 ;
for ( V_1 = 0 ; V_1 < V_120 ; V_1 ++ ) {
V_121 [ V_1 ] . V_29 = V_50 [ V_1 ] ;
F_84 ( & V_121 [ V_1 ] . V_101 , F_85 ( V_50 [ V_1 ] ) ) ;
F_86 ( & V_121 [ V_1 ] . V_100 , F_65 ) ;
F_69 (cpu, &chips[i].mask)
F_87 ( V_54 , V_45 ) = & V_121 [ V_1 ] ;
}
return 0 ;
}
static inline void F_88 ( void )
{
F_60 ( V_121 ) ;
}
static inline void F_89 ( void )
{
F_90 ( V_113 ,
& V_127 ) ;
F_91 ( & V_128 ) ;
}
static int T_6 F_92 ( void )
{
int V_129 = 0 ;
if ( ! F_93 ( V_130 ) )
return - V_28 ;
V_129 = F_6 () ;
if ( V_129 )
goto V_104;
V_129 = F_80 () ;
if ( V_129 )
goto V_104;
F_94 ( & V_128 ) ;
F_95 ( V_113 , & V_127 ) ;
V_129 = F_96 ( & V_131 ) ;
if ( ! V_129 )
return 0 ;
F_10 ( L_36 , V_129 ) ;
F_89 () ;
F_88 () ;
V_104:
F_10 ( L_37 ) ;
return V_129 ;
}
static void T_7 F_97 ( void )
{
F_98 ( & V_131 ) ;
F_89 () ;
F_88 () ;
}
