static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
}
static int F_2 ( void )
{
struct V_11 * V_12 ;
int V_13 , V_14 , V_15 , V_16 , V_17 = 0 ;
const T_1 * V_18 , * V_19 ;
T_2 V_20 , V_21 ;
V_12 = F_3 ( L_1 ) ;
if ( ! V_12 ) {
F_4 ( L_2 ) ;
return - V_22 ;
}
if ( F_5 ( V_12 , L_3 , & V_14 ) ) {
F_4 ( L_4 ) ;
return - V_22 ;
}
if ( F_5 ( V_12 , L_5 , & V_15 ) ) {
F_4 ( L_6 ) ;
return - V_22 ;
}
if ( F_5 ( V_12 , L_7 ,
& V_16 ) ) {
F_4 ( L_8 ) ;
return - V_22 ;
}
F_6 ( L_9 , V_14 ,
V_16 , V_15 ) ;
V_18 = F_7 ( V_12 , L_10 , & V_20 ) ;
if ( ! V_18 ) {
F_4 ( L_11 ) ;
return - V_22 ;
}
V_19 = F_7 ( V_12 , L_12 ,
& V_21 ) ;
if ( ! V_19 ) {
F_4 ( L_13 ) ;
return - V_22 ;
}
if ( V_20 != V_21 ) {
F_4 ( L_14
L_15 ) ;
}
V_17 = F_8 ( V_20 , V_21 ) / sizeof( T_2 ) ;
if ( ! V_17 ) {
F_4 ( L_16 ) ;
return - V_22 ;
}
F_9 ( L_17 , V_17 ) ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
T_2 V_23 = F_10 ( V_18 [ V_13 ] ) ;
T_2 V_24 = F_10 ( V_19 [ V_13 ] ) ;
F_9 ( L_18 , V_23 , V_24 ) ;
V_25 [ V_13 ] . V_26 = V_24 * 1000 ;
V_25 [ V_13 ] . V_5 = V_23 ;
}
V_25 [ V_13 ] . V_26 = V_27 ;
V_28 . F_8 = V_14 ;
V_28 . V_29 = V_15 ;
V_28 . V_30 = V_16 ;
V_28 . V_17 = V_17 ;
return 0 ;
}
static unsigned int F_11 ( int V_31 )
{
int V_13 ;
V_13 = V_28 . V_29 - V_31 ;
if ( V_13 >= V_28 . V_17 || V_13 < 0 ) {
F_4 ( L_19
L_20 ,
V_31 , V_28 . V_30 ) ;
V_13 = V_28 . V_29 - V_28 . V_30 ;
}
return V_25 [ V_13 ] . V_26 ;
}
static T_3 F_12 ( struct V_1 * V_2 ,
char * V_32 )
{
return sprintf ( V_32 , L_21 ,
F_11 ( V_28 . V_30 ) ) ;
}
static inline unsigned long F_13 ( unsigned long V_33 )
{
switch ( V_33 ) {
case V_34 :
return F_14 ( V_34 ) ;
case V_35 :
return F_14 ( V_35 ) ;
case V_36 :
return F_14 ( V_36 ) ;
}
F_15 () ;
}
static inline void F_16 ( unsigned long V_33 , unsigned long V_37 )
{
switch ( V_33 ) {
case V_34 :
F_17 ( V_34 , V_37 ) ;
return;
case V_35 :
F_17 ( V_35 , V_37 ) ;
return;
}
F_15 () ;
}
static void F_18 ( void * V_38 )
{
unsigned long V_39 ;
T_4 V_40 ;
struct V_41 * V_42 = V_38 ;
V_39 = F_13 ( V_36 ) ;
V_40 = ( V_39 >> 48 ) & 0xFF ;
V_42 -> V_31 = V_40 ;
V_42 -> V_24 = F_11 ( V_42 -> V_31 ) ;
F_9 ( L_22 ,
F_19 () , V_39 , V_42 -> V_31 ,
V_42 -> V_24 ) ;
}
static unsigned int F_20 ( unsigned int V_43 )
{
struct V_41 V_42 ;
F_21 ( F_22 ( V_43 ) , F_18 ,
& V_42 , 1 ) ;
return V_42 . V_24 ;
}
static void F_23 ( void * V_44 )
{
unsigned long V_37 ;
struct V_41 * V_42 = V_44 ;
unsigned long V_45 = V_42 -> V_31 ;
unsigned long V_46 = V_42 -> V_47 ;
V_37 = F_13 ( V_34 ) ;
V_37 = V_37 & 0x0000FFFFFFFFFFFFULL ;
V_45 = V_45 & 0xFF ;
V_46 = V_46 & 0xFF ;
V_37 = V_37 | ( V_46 << 56 ) | ( V_45 << 48 ) ;
F_9 ( L_23 ,
F_19 () , V_37 ) ;
F_16 ( V_34 , V_37 ) ;
}
static inline unsigned int F_24 ( void )
{
return V_28 . V_29 - V_28 . V_30 ;
}
static void F_25 ( void * V_44 )
{
struct V_48 * V_48 ;
unsigned int V_43 = F_26 () ;
unsigned long V_49 ;
int V_50 ;
V_49 = F_13 ( V_36 ) ;
V_48 = F_27 ( V_51 ) ;
V_50 = ( T_4 ) F_28 ( V_49 ) ;
if ( V_50 != V_28 . V_29 ) {
if ( V_48 -> V_52 )
goto V_53;
V_48 -> V_52 = true ;
if ( V_50 < V_28 . V_30 ) {
F_29 ( L_24 ,
V_43 , V_48 -> V_23 , V_50 ,
V_28 . V_30 ) ;
V_48 -> V_54 ++ ;
} else {
V_48 -> V_55 ++ ;
}
F_30 ( V_48 -> V_23 ,
V_56 [ V_48 -> V_56 ] ,
V_50 ) ;
} else if ( V_48 -> V_52 ) {
V_48 -> V_52 = false ;
F_30 ( V_48 -> V_23 ,
V_56 [ V_48 -> V_56 ] ,
V_50 ) ;
}
V_53:
if ( V_49 & V_57 ) {
V_52 = true ;
F_6 ( L_25 ) ;
}
if ( V_49 & V_58 ) {
V_52 = true ;
F_6 ( L_26 ) ;
}
if ( V_52 ) {
F_6 ( L_27 , V_49 ) ;
F_4 ( L_28 ) ;
}
}
static inline int F_31 ( unsigned int V_7 ,
int V_6 , int V_59 )
{
int V_60 ;
V_60 = ( ( int ) F_32 ( V_7 ) *
( V_6 - V_28 . F_8 ) ) / 100 ;
if ( V_6 - V_60 < V_59 )
return V_59 ;
else
return V_6 - V_60 ;
}
static inline void F_33 ( struct V_3 * V_4 )
{
unsigned int V_61 ;
if ( ( V_4 -> V_7 + V_62 )
> V_63 )
V_61 = V_63 - V_4 -> V_7 ;
else
V_61 = V_62 ;
F_34 ( & V_4 -> V_64 , V_65 +
F_35 ( V_61 ) ) ;
}
void F_36 ( unsigned long V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_47 ;
unsigned int V_66 = F_37 ( V_65 )
- V_4 -> V_8 ;
struct V_41 V_42 ;
if ( ! F_38 ( & V_4 -> V_67 ) )
return;
V_4 -> V_8 += V_66 ;
V_4 -> V_7 += V_66 ;
V_42 . V_31 = V_4 -> V_9 ;
if ( ( V_4 -> V_10 == V_42 . V_31 ) ||
( V_4 -> V_7 > V_63 ) ) {
V_47 = V_42 . V_31 ;
F_1 ( V_2 ) ;
V_4 -> V_6 = V_42 . V_31 ;
} else {
V_47 = F_31 ( V_4 -> V_7 ,
V_4 -> V_6 ,
V_42 . V_31 ) ;
}
if ( V_47 != V_42 . V_31 )
F_33 ( V_4 ) ;
V_42 . V_47 = V_47 ;
V_4 -> V_10 = V_42 . V_47 ;
V_4 -> V_9 = V_42 . V_31 ;
F_39 ( & V_4 -> V_67 ) ;
F_21 ( V_2 -> V_68 , F_23 , & V_42 , 1 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned int V_69 )
{
struct V_41 V_42 ;
unsigned int V_70 , V_47 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_41 ( V_71 ) && V_69 != F_24 () )
return 0 ;
if ( ! V_52 )
F_25 ( NULL ) ;
V_70 = F_37 ( F_42 () ) ;
F_43 ( & V_4 -> V_67 ) ;
V_42 . V_31 = V_25 [ V_69 ] . V_5 ;
if ( ! V_4 -> V_8 ) {
V_47 = V_42 . V_31 ;
V_4 -> V_6 = V_42 . V_31 ;
goto V_72;
}
if ( V_4 -> V_10 > V_42 . V_31 ) {
V_4 -> V_7 += V_70 -
V_4 -> V_8 ;
if ( V_4 -> V_7 > V_63 ) {
F_1 ( V_2 ) ;
V_4 -> V_6 = V_42 . V_31 ;
V_47 = V_42 . V_31 ;
} else {
V_47 = F_31 ( V_4 -> V_7 ,
V_4 -> V_6 ,
V_42 . V_31 ) ;
}
} else {
F_1 ( V_2 ) ;
V_4 -> V_6 = V_42 . V_31 ;
V_47 = V_42 . V_31 ;
}
if ( V_47 != V_42 . V_31 )
F_33 ( V_4 ) ;
else
F_44 ( & V_4 -> V_64 ) ;
V_72:
V_42 . V_47 = V_47 ;
V_4 -> V_8 = V_70 ;
V_4 -> V_10 = V_42 . V_47 ;
V_4 -> V_9 = V_42 . V_31 ;
F_39 ( & V_4 -> V_67 ) ;
F_21 ( V_2 -> V_68 , F_23 , & V_42 , 1 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_73 , V_13 , V_74 ;
struct V_75 * V_76 ;
struct V_3 * V_4 ;
V_73 = F_46 ( V_2 -> V_43 ) ;
for ( V_13 = 0 ; V_13 < V_77 ; V_13 ++ )
F_47 ( V_73 + V_13 , V_2 -> V_68 ) ;
V_76 = F_48 ( V_2 -> V_78 . V_79 , V_80 . V_81 ) ;
if ( ! V_76 ) {
int V_74 ;
V_74 = F_49 ( & V_2 -> V_78 , & V_80 ) ;
if ( V_74 ) {
F_6 ( L_29 ,
V_2 -> V_43 ) ;
return V_74 ;
}
} else {
F_50 ( V_76 ) ;
}
V_4 = F_51 ( sizeof( * V_4 ) , V_82 ) ;
if ( ! V_4 )
return - V_83 ;
V_2 -> V_5 = V_4 ;
F_52 ( & V_4 -> V_64 ) ;
V_4 -> V_64 . V_44 = ( unsigned long ) V_2 ;
V_4 -> V_64 . V_84 = F_36 ;
V_4 -> V_64 . V_85 = V_65 +
F_35 ( V_62 ) ;
F_53 ( & V_4 -> V_67 ) ;
V_74 = F_54 ( V_2 , V_25 ) ;
if ( V_74 < 0 )
F_55 ( V_2 -> V_5 ) ;
return V_74 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_57 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
int V_43 ;
struct V_1 V_90 ;
V_71 = true ;
F_58 (cpu) {
F_59 ( & V_90 , V_43 ) ;
F_40 ( & V_90 , F_24 () ) ;
}
return V_91 ;
}
void F_60 ( struct V_92 * V_93 )
{
struct V_48 * V_48 = F_61 ( V_93 , struct V_48 , V_94 ) ;
unsigned int V_43 ;
T_5 V_95 ;
F_62 () ;
F_63 ( & V_95 , & V_48 -> V_95 , V_96 ) ;
F_21 ( & V_95 ,
F_25 , NULL , 0 ) ;
if ( ! V_48 -> V_97 )
goto V_98;
V_48 -> V_97 = false ;
F_64 (cpu, &mask) {
int V_99 ;
struct V_1 V_2 ;
F_59 ( & V_2 , V_43 ) ;
F_65 ( & V_2 , V_2 . V_100 ,
V_2 . V_101 ,
V_102 , & V_99 ) ;
F_40 ( & V_2 , V_99 ) ;
F_66 ( & V_95 , & V_95 , V_2 . V_68 ) ;
}
V_98:
F_67 () ;
}
static int F_68 ( struct V_86 * V_87 ,
unsigned long V_103 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
struct V_107 V_108 ;
int V_13 ;
if ( V_103 != V_109 )
return 0 ;
V_108 . type = F_69 ( V_106 -> V_110 [ 0 ] ) ;
switch ( V_108 . type ) {
case V_111 :
V_112 = true ;
F_6 ( L_30 ) ;
if ( ! V_52 ) {
V_52 = true ;
F_4 ( L_31 ) ;
}
break;
case V_113 :
F_6 ( L_32 ) ;
break;
case V_114 :
V_108 . V_48 = F_69 ( V_106 -> V_110 [ 1 ] ) ;
V_108 . V_115 = F_69 ( V_106 -> V_110 [ 2 ] ) ;
if ( V_112 ) {
V_112 = false ;
V_52 = false ;
F_6 ( L_33 ) ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
V_117 [ V_13 ] . V_97 = true ;
F_70 ( & V_117 [ V_13 ] . V_94 ) ;
}
return 0 ;
}
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ )
if ( V_117 [ V_13 ] . V_23 == V_108 . V_48 )
break;
if ( V_108 . V_115 >= 0 &&
V_108 . V_115 <= V_118 ) {
V_117 [ V_13 ] . V_56 = V_108 . V_115 ;
V_117 [ V_13 ] . V_119 [ V_108 . V_115 ] ++ ;
}
if ( ! V_108 . V_115 )
V_117 [ V_13 ] . V_97 = true ;
F_70 ( & V_117 [ V_13 ] . V_94 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_41 V_42 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_42 . V_31 = V_28 . F_8 ;
V_42 . V_47 = V_28 . F_8 ;
F_72 ( V_2 -> V_43 , F_23 , & V_42 , 1 ) ;
F_44 ( & V_4 -> V_64 ) ;
}
static int F_73 ( void )
{
unsigned int V_48 [ 256 ] ;
unsigned int V_43 , V_13 ;
unsigned int V_120 = V_121 ;
F_74 (cpu) {
unsigned int V_23 = F_75 ( V_43 ) ;
if ( V_120 != V_23 ) {
V_120 = V_23 ;
V_48 [ V_116 ++ ] = V_23 ;
}
}
V_117 = F_76 ( V_116 , sizeof( struct V_48 ) , V_82 ) ;
if ( ! V_117 )
return - V_83 ;
for ( V_13 = 0 ; V_13 < V_116 ; V_13 ++ ) {
V_117 [ V_13 ] . V_23 = V_48 [ V_13 ] ;
F_77 ( & V_117 [ V_13 ] . V_95 , F_78 ( V_48 [ V_13 ] ) ) ;
F_79 ( & V_117 [ V_13 ] . V_94 , F_60 ) ;
F_64 (cpu, &chips[i].mask)
F_80 ( V_51 , V_43 ) = & V_117 [ V_13 ] ;
}
return 0 ;
}
static inline void F_81 ( void )
{
F_55 ( V_117 ) ;
}
static inline void F_82 ( void )
{
F_83 ( V_109 ,
& V_122 ) ;
F_84 ( & V_123 ) ;
}
static int T_6 F_85 ( void )
{
int V_124 = 0 ;
if ( ! F_86 ( V_125 ) )
return - V_22 ;
V_124 = F_2 () ;
if ( V_124 )
goto V_98;
V_124 = F_73 () ;
if ( V_124 )
goto V_98;
F_87 ( & V_123 ) ;
F_88 ( V_109 , & V_122 ) ;
V_124 = F_89 ( & V_126 ) ;
if ( ! V_124 )
return 0 ;
F_6 ( L_34 , V_124 ) ;
F_82 () ;
F_81 () ;
V_98:
F_6 ( L_35 ) ;
return V_124 ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_126 ) ;
F_82 () ;
F_81 () ;
}
