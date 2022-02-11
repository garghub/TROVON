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
int V_69 ;
unsigned int V_70 = F_39 ( V_68 )
- V_13 -> V_16 ;
struct V_43 V_44 ;
if ( ! F_40 ( & V_13 -> V_71 ) )
return;
V_13 -> V_16 += V_70 ;
V_13 -> V_15 += V_70 ;
V_44 . V_33 = F_1 ( V_13 -> V_17 ) ;
if ( ( V_13 -> V_18 == V_13 -> V_17 ) ||
( V_13 -> V_15 > V_66 ) ) {
V_69 = F_4 ( V_44 . V_33 ) ;
F_5 ( V_11 ) ;
V_13 -> V_14 = V_69 ;
} else {
V_69 = F_33 ( V_13 -> V_15 ,
V_13 -> V_14 ,
V_13 -> V_17 ) ;
}
if ( V_69 != V_13 -> V_17 )
F_35 ( V_13 ) ;
V_44 . V_49 = F_1 ( V_69 ) ;
V_13 -> V_18 = F_4 ( V_44 . V_49 ) ;
V_13 -> V_17 = F_4 ( V_44 . V_33 ) ;
F_41 ( & V_13 -> V_71 ) ;
F_24 ( V_11 -> V_72 , F_26 , & V_44 , 1 ) ;
}
static int F_42 ( struct V_10 * V_11 ,
unsigned int V_73 )
{
struct V_43 V_44 ;
unsigned int V_74 , V_69 ;
struct V_12 * V_13 = V_11 -> V_6 ;
if ( F_2 ( V_75 ) && V_73 != F_27 () )
return 0 ;
if ( ! V_55 )
F_28 ( NULL ) ;
V_74 = F_39 ( F_43 () ) ;
F_44 ( & V_13 -> V_71 ) ;
V_44 . V_33 = F_1 ( V_73 ) ;
if ( ! V_13 -> V_16 ) {
V_69 = V_73 ;
V_13 -> V_14 = V_73 ;
goto V_76;
}
if ( V_13 -> V_18 < V_73 ) {
V_13 -> V_15 += V_74 -
V_13 -> V_16 ;
if ( V_13 -> V_15 > V_66 ) {
F_5 ( V_11 ) ;
V_13 -> V_14 = V_73 ;
V_69 = V_73 ;
} else {
V_69 = F_33 ( V_13 -> V_15 ,
V_13 -> V_14 ,
V_73 ) ;
}
} else {
F_5 ( V_11 ) ;
V_13 -> V_14 = V_73 ;
V_69 = V_73 ;
}
if ( V_69 != V_73 )
F_35 ( V_13 ) ;
else
F_45 ( & V_13 -> V_67 ) ;
V_76:
V_44 . V_49 = F_1 ( V_69 ) ;
V_13 -> V_16 = V_74 ;
V_13 -> V_18 = V_69 ;
V_13 -> V_17 = V_73 ;
F_41 ( & V_13 -> V_71 ) ;
F_24 ( V_11 -> V_72 , F_26 , & V_44 , 1 ) ;
return 0 ;
}
static int F_46 ( struct V_10 * V_11 )
{
int V_77 , V_1 , V_78 ;
struct V_79 * V_80 ;
struct V_12 * V_13 ;
V_77 = F_47 ( V_11 -> V_45 ) ;
for ( V_1 = 0 ; V_1 < V_81 ; V_1 ++ )
F_48 ( V_77 + V_1 , V_11 -> V_72 ) ;
V_80 = F_49 ( V_11 -> V_82 . V_83 , V_84 . V_85 ) ;
if ( ! V_80 ) {
int V_78 ;
V_78 = F_50 ( & V_11 -> V_82 , & V_84 ) ;
if ( V_78 ) {
F_10 ( L_31 ,
V_11 -> V_45 ) ;
return V_78 ;
}
} else {
F_51 ( V_80 ) ;
}
V_13 = F_52 ( sizeof( * V_13 ) , V_86 ) ;
if ( ! V_13 )
return - V_87 ;
V_11 -> V_6 = V_13 ;
F_53 ( & V_13 -> V_67 ) ;
V_13 -> V_67 . V_46 = ( unsigned long ) V_11 ;
V_13 -> V_67 . V_88 = F_38 ;
V_13 -> V_67 . V_89 = V_68 +
F_37 ( V_65 ) ;
F_54 ( & V_13 -> V_71 ) ;
V_78 = F_55 ( V_11 , V_4 ) ;
if ( V_78 < 0 )
F_56 ( V_11 -> V_6 ) ;
return V_78 ;
}
static int F_57 ( struct V_10 * V_11 )
{
F_56 ( V_11 -> V_6 ) ;
return 0 ;
}
static int F_58 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
int V_45 ;
struct V_10 V_94 ;
V_75 = true ;
F_59 (cpu) {
F_60 ( & V_94 , V_45 ) ;
F_42 ( & V_94 , F_27 () ) ;
}
return V_95 ;
}
void F_61 ( struct V_96 * V_97 )
{
struct V_50 * V_50 = F_62 ( V_97 , struct V_50 , V_98 ) ;
unsigned int V_45 ;
T_5 V_99 ;
F_63 () ;
F_64 ( & V_99 , & V_50 -> V_99 , V_100 ) ;
F_24 ( & V_99 ,
F_28 , NULL , 0 ) ;
if ( ! V_50 -> V_101 )
goto V_102;
V_50 -> V_101 = false ;
F_65 (cpu, &mask) {
int V_103 ;
struct V_10 V_11 ;
F_60 ( & V_11 , V_45 ) ;
V_103 = F_66 ( & V_11 , V_11 . V_104 ) ;
F_42 ( & V_11 , V_103 ) ;
F_67 ( & V_99 , & V_99 , V_11 . V_72 ) ;
}
V_102:
F_68 () ;
}
static int F_69 ( struct V_90 * V_91 ,
unsigned long V_105 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
struct V_109 V_110 ;
int V_1 ;
if ( V_105 != V_111 )
return 0 ;
V_110 . type = F_70 ( V_108 -> V_112 [ 0 ] ) ;
switch ( V_110 . type ) {
case V_113 :
V_114 = true ;
F_10 ( L_32 ) ;
if ( ! V_55 ) {
V_55 = true ;
F_8 ( L_33 ) ;
}
break;
case V_115 :
F_10 ( L_34 ) ;
break;
case V_116 :
V_110 . V_50 = F_70 ( V_108 -> V_112 [ 1 ] ) ;
V_110 . V_117 = F_70 ( V_108 -> V_112 [ 2 ] ) ;
if ( V_114 ) {
V_114 = false ;
V_55 = false ;
F_10 ( L_35 ) ;
for ( V_1 = 0 ; V_1 < V_118 ; V_1 ++ ) {
V_119 [ V_1 ] . V_101 = true ;
F_71 ( & V_119 [ V_1 ] . V_98 ) ;
}
return 0 ;
}
for ( V_1 = 0 ; V_1 < V_118 ; V_1 ++ )
if ( V_119 [ V_1 ] . V_29 == V_110 . V_50 )
break;
if ( V_110 . V_117 >= 0 &&
V_110 . V_117 <= V_120 ) {
V_119 [ V_1 ] . V_59 = V_110 . V_117 ;
V_119 [ V_1 ] . V_121 [ V_110 . V_117 ] ++ ;
}
if ( ! V_110 . V_117 )
V_119 [ V_1 ] . V_101 = true ;
F_71 ( & V_119 [ V_1 ] . V_98 ) ;
}
return 0 ;
}
static void F_72 ( struct V_10 * V_11 )
{
struct V_43 V_44 ;
struct V_12 * V_13 = V_11 -> V_6 ;
V_44 . V_33 = F_1 ( V_2 . V_8 ) ;
V_44 . V_49 = F_1 ( V_2 . V_8 ) ;
F_73 ( V_11 -> V_45 , F_26 , & V_44 , 1 ) ;
F_45 ( & V_13 -> V_67 ) ;
}
static int F_74 ( void )
{
unsigned int V_50 [ 256 ] ;
unsigned int V_45 , V_1 ;
unsigned int V_122 = V_123 ;
F_75 (cpu) {
unsigned int V_29 = F_76 ( V_45 ) ;
if ( V_122 != V_29 ) {
V_122 = V_29 ;
V_50 [ V_118 ++ ] = V_29 ;
}
}
V_119 = F_77 ( V_118 , sizeof( struct V_50 ) , V_86 ) ;
if ( ! V_119 )
return - V_87 ;
for ( V_1 = 0 ; V_1 < V_118 ; V_1 ++ ) {
V_119 [ V_1 ] . V_29 = V_50 [ V_1 ] ;
F_78 ( & V_119 [ V_1 ] . V_99 , F_79 ( V_50 [ V_1 ] ) ) ;
F_80 ( & V_119 [ V_1 ] . V_98 , F_61 ) ;
F_65 (cpu, &chips[i].mask)
F_81 ( V_54 , V_45 ) = & V_119 [ V_1 ] ;
}
return 0 ;
}
static inline void F_82 ( void )
{
F_56 ( V_119 ) ;
}
static inline void F_83 ( void )
{
F_84 ( V_111 ,
& V_124 ) ;
F_85 ( & V_125 ) ;
}
static int T_6 F_86 ( void )
{
int V_126 = 0 ;
if ( ! F_87 ( V_127 ) )
return - V_28 ;
V_126 = F_6 () ;
if ( V_126 )
goto V_102;
V_126 = F_74 () ;
if ( V_126 )
goto V_102;
F_88 ( & V_125 ) ;
F_89 ( V_111 , & V_124 ) ;
V_126 = F_90 ( & V_128 ) ;
if ( ! V_126 )
return 0 ;
F_10 ( L_36 , V_126 ) ;
F_83 () ;
F_82 () ;
V_102:
F_10 ( L_37 ) ;
return V_126 ;
}
static void T_7 F_91 ( void )
{
F_92 ( & V_128 ) ;
F_83 () ;
F_82 () ;
}
