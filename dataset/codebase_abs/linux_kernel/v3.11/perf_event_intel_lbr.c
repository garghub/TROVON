static void F_1 ( void )
{
T_1 V_1 ;
struct V_2 * V_3 = & F_2 ( V_2 ) ;
if ( V_3 -> V_4 )
F_3 ( V_5 , V_3 -> V_4 -> V_6 ) ;
F_4 ( V_7 , V_1 ) ;
V_1 |= ( V_8 | V_9 ) ;
F_3 ( V_7 , V_1 ) ;
}
static void F_5 ( void )
{
T_1 V_1 ;
F_4 ( V_7 , V_1 ) ;
V_1 &= ~ ( V_8 | V_9 ) ;
F_3 ( V_7 , V_1 ) ;
}
static void F_6 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 . V_12 ; V_10 ++ )
F_3 ( V_11 . V_13 + V_10 , 0 ) ;
}
static void F_7 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 . V_12 ; V_10 ++ ) {
F_3 ( V_11 . V_13 + V_10 , 0 ) ;
F_3 ( V_11 . V_14 + V_10 , 0 ) ;
}
}
void F_8 ( void )
{
if ( ! V_11 . V_12 )
return;
if ( V_11 . V_15 . V_16 == V_17 )
F_6 () ;
else
F_7 () ;
}
void F_9 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = & F_2 ( V_2 ) ;
if ( ! V_11 . V_12 )
return;
if ( V_19 -> V_20 -> V_21 && V_3 -> V_22 != V_19 -> V_20 ) {
F_8 () ;
V_3 -> V_22 = V_19 -> V_20 ;
}
V_3 -> V_23 = V_19 -> V_24 . V_25 . V_26 ;
V_3 -> V_27 ++ ;
}
void F_10 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = & F_2 ( V_2 ) ;
if ( ! V_11 . V_12 )
return;
V_3 -> V_27 -- ;
F_11 ( V_3 -> V_27 < 0 ) ;
if ( V_3 -> V_28 && ! V_3 -> V_27 ) {
F_5 () ;
V_3 -> V_22 = NULL ;
}
}
void F_12 ( void )
{
struct V_2 * V_3 = & F_2 ( V_2 ) ;
if ( V_3 -> V_27 )
F_1 () ;
}
void F_13 ( void )
{
struct V_2 * V_3 = & F_2 ( V_2 ) ;
if ( V_3 -> V_27 )
F_5 () ;
}
static inline T_1 F_14 ( void )
{
T_1 V_29 ;
F_4 ( V_11 . V_30 , V_29 ) ;
return V_29 ;
}
static void F_15 ( struct V_2 * V_3 )
{
unsigned long V_31 = V_11 . V_12 - 1 ;
T_1 V_29 = F_14 () ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 . V_12 ; V_10 ++ ) {
unsigned long V_32 = ( V_29 - V_10 ) & V_31 ;
union {
struct {
T_2 V_33 ;
T_2 V_34 ;
};
T_1 V_35 ;
} V_36 ;
F_4 ( V_11 . V_13 + V_32 , V_36 . V_35 ) ;
V_3 -> V_37 [ V_10 ] . V_33 = V_36 . V_33 ;
V_3 -> V_37 [ V_10 ] . V_34 = V_36 . V_34 ;
V_3 -> V_37 [ V_10 ] . V_38 = 0 ;
V_3 -> V_37 [ V_10 ] . V_39 = 0 ;
V_3 -> V_37 [ V_10 ] . V_40 = 0 ;
}
V_3 -> V_41 . V_42 = V_10 ;
}
static void F_16 ( struct V_2 * V_3 )
{
unsigned long V_31 = V_11 . V_12 - 1 ;
int V_16 = V_11 . V_15 . V_16 ;
T_1 V_29 = F_14 () ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 . V_12 ; V_10 ++ ) {
unsigned long V_32 = ( V_29 - V_10 ) & V_31 ;
T_1 V_33 , V_34 , V_43 = 0 , V_44 = 0 , V_45 = 0 , abort = 0 ;
int V_46 = 0 ;
int V_47 = V_48 [ V_16 ] ;
F_4 ( V_11 . V_13 + V_32 , V_33 ) ;
F_4 ( V_11 . V_14 + V_32 , V_34 ) ;
if ( V_47 & V_49 ) {
V_43 = ! ! ( V_33 & V_50 ) ;
V_44 = ! V_43 ;
V_46 = 1 ;
}
if ( V_47 & V_51 ) {
V_45 = ! ! ( V_33 & V_52 ) ;
abort = ! ! ( V_33 & V_53 ) ;
V_46 = 3 ;
}
V_33 = ( T_1 ) ( ( ( ( V_54 ) V_33 ) << V_46 ) >> V_46 ) ;
V_3 -> V_37 [ V_10 ] . V_33 = V_33 ;
V_3 -> V_37 [ V_10 ] . V_34 = V_34 ;
V_3 -> V_37 [ V_10 ] . V_38 = V_43 ;
V_3 -> V_37 [ V_10 ] . V_39 = V_44 ;
V_3 -> V_37 [ V_10 ] . V_45 = V_45 ;
V_3 -> V_37 [ V_10 ] . abort = abort ;
V_3 -> V_37 [ V_10 ] . V_40 = 0 ;
}
V_3 -> V_41 . V_42 = V_10 ;
}
void F_17 ( void )
{
struct V_2 * V_3 = & F_2 ( V_2 ) ;
if ( ! V_3 -> V_27 )
return;
if ( V_11 . V_15 . V_16 == V_17 )
F_15 ( V_3 ) ;
else
F_16 ( V_3 ) ;
F_18 ( V_3 ) ;
}
static void F_19 ( struct V_18 * V_19 )
{
T_1 V_55 = V_19 -> V_56 . V_57 ;
int V_31 = 0 ;
if ( V_55 & V_58 )
V_31 |= V_59 ;
if ( V_55 & V_60 )
V_31 |= V_61 ;
if ( V_55 & V_62 )
V_31 |= V_63 ;
if ( V_55 & V_64 )
V_31 |= V_65 ;
if ( V_55 & V_66 )
V_31 |= V_67 | V_68 | V_69 ;
if ( V_55 & V_70 )
V_31 |= V_71 ;
if ( V_55 & V_72 )
V_31 |= V_73 ;
if ( V_55 & V_74 )
V_31 |= V_75 ;
if ( V_55 & V_76 )
V_31 |= V_77 ;
V_19 -> V_24 . V_25 . V_26 = V_31 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_78 * V_26 ;
T_1 V_55 = V_19 -> V_56 . V_57 ;
T_1 V_31 = 0 , V_79 ;
T_1 V_80 ;
F_21 (m) {
if ( ! ( V_55 & V_79 ) )
continue;
V_80 = V_11 . V_81 [ V_79 ] ;
if ( V_80 == V_82 )
return - V_83 ;
if ( V_80 != V_84 )
V_31 |= V_80 ;
}
V_26 = & V_19 -> V_24 . V_25 ;
V_26 -> V_85 = V_86 ;
V_26 -> V_6 = ~ V_31 & V_11 . V_87 ;
return 0 ;
}
int F_22 ( struct V_18 * V_19 )
{
int V_88 = 0 ;
if ( ! V_11 . V_12 )
return - V_83 ;
F_19 ( V_19 ) ;
if ( V_11 . V_81 )
V_88 = F_20 ( V_19 ) ;
return V_88 ;
}
static int F_23 ( unsigned long V_33 , unsigned long V_34 , int abort )
{
struct V_89 V_89 ;
void * V_90 ;
int V_91 , V_92 = V_93 ;
int V_88 = V_94 ;
int V_95 , V_96 , V_97 ;
T_3 V_98 [ V_93 ] ;
int V_99 = 0 ;
V_96 = F_24 ( V_34 ) ? V_61 : V_59 ;
V_97 = F_24 ( V_33 ) ? V_61 : V_59 ;
if ( V_33 == 0 || V_34 == 0 )
return V_94 ;
if ( abort )
return V_73 | V_96 ;
if ( V_97 == V_59 ) {
if ( ! V_100 -> V_101 )
return V_94 ;
V_91 = F_25 ( V_98 , ( void V_102 * ) V_33 , V_92 ) ;
if ( V_91 != V_92 )
return V_94 ;
V_90 = V_98 ;
} else {
if ( F_26 ( V_33 ) )
V_90 = ( void * ) V_33 ;
else
return V_94 ;
}
#ifdef F_27
V_99 = F_24 ( ( unsigned long ) V_90 ) || ! F_28 ( V_103 ) ;
#endif
F_29 ( & V_89 , V_90 , V_99 ) ;
F_30 ( & V_89 ) ;
switch ( V_89 . V_104 . V_91 [ 0 ] ) {
case 0xf :
switch ( V_89 . V_104 . V_91 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_88 = V_105 ;
break;
case 0x07 :
case 0x35 :
V_88 = V_69 ;
break;
case 0x80 ... 0x8f :
V_88 = V_106 ;
break;
default:
V_88 = V_94 ;
}
break;
case 0x70 ... 0x7f :
V_88 = V_106 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_88 = V_67 ;
break;
case 0xcf :
V_88 = V_68 ;
break;
case 0xcc ... 0xce :
V_88 = V_107 ;
break;
case 0xe8 :
case 0x9a :
V_88 = V_108 ;
break;
case 0xe0 ... 0xe3 :
V_88 = V_106 ;
break;
case 0xe9 ... 0xeb :
V_88 = V_109 ;
break;
case 0xff :
F_31 ( & V_89 ) ;
V_95 = ( V_89 . V_110 . V_91 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_95 ) {
case 2 :
case 3 :
V_88 = V_71 ;
break;
case 4 :
case 5 :
V_88 = V_109 ;
break;
}
break;
default:
V_88 = V_94 ;
}
if ( V_97 == V_59 && V_96 == V_61
&& V_88 != V_105 && V_88 != V_107 )
V_88 = V_111 ;
if ( V_88 != V_94 )
V_88 |= V_96 ;
return V_88 ;
}
static void
F_18 ( struct V_2 * V_3 )
{
T_1 V_33 , V_34 ;
int V_23 = V_3 -> V_23 ;
int V_10 , V_112 , type ;
bool V_113 = false ;
if ( ( V_23 & V_114 ) == V_114 )
return;
for ( V_10 = 0 ; V_10 < V_3 -> V_41 . V_42 ; V_10 ++ ) {
V_33 = V_3 -> V_37 [ V_10 ] . V_33 ;
V_34 = V_3 -> V_37 [ V_10 ] . V_34 ;
type = F_23 ( V_33 , V_34 , V_3 -> V_37 [ V_10 ] . abort ) ;
if ( type != V_94 && ( V_23 & V_115 ) ) {
if ( V_3 -> V_37 [ V_10 ] . V_45 )
type |= V_75 ;
else
type |= V_77 ;
}
if ( type == V_94 || ( V_23 & type ) != type ) {
V_3 -> V_37 [ V_10 ] . V_33 = 0 ;
V_113 = true ;
}
}
if ( ! V_113 )
return;
for ( V_10 = 0 ; V_10 < V_3 -> V_41 . V_42 ; ) {
if ( ! V_3 -> V_37 [ V_10 ] . V_33 ) {
V_112 = V_10 ;
while ( ++ V_112 < V_3 -> V_41 . V_42 )
V_3 -> V_37 [ V_112 - 1 ] = V_3 -> V_37 [ V_112 ] ;
V_3 -> V_41 . V_42 -- ;
if ( ! V_3 -> V_37 [ V_10 ] . V_33 )
continue;
}
V_10 ++ ;
}
}
void F_32 ( void )
{
V_11 . V_12 = 4 ;
V_11 . V_30 = V_116 ;
V_11 . V_13 = V_117 ;
V_11 . V_14 = V_118 ;
F_33 ( L_1 ) ;
}
void F_34 ( void )
{
V_11 . V_12 = 16 ;
V_11 . V_30 = V_116 ;
V_11 . V_13 = V_119 ;
V_11 . V_14 = V_120 ;
V_11 . V_87 = V_121 ;
V_11 . V_81 = V_122 ;
F_33 ( L_2 ) ;
}
void F_35 ( void )
{
V_11 . V_12 = 16 ;
V_11 . V_30 = V_116 ;
V_11 . V_13 = V_119 ;
V_11 . V_14 = V_120 ;
V_11 . V_87 = V_121 ;
V_11 . V_81 = V_123 ;
F_33 ( L_2 ) ;
}
void F_36 ( void )
{
if ( V_124 . V_125 == 28
&& V_124 . V_126 < 10 ) {
F_33 ( L_3 ) ;
return;
}
V_11 . V_12 = 8 ;
V_11 . V_30 = V_116 ;
V_11 . V_13 = V_117 ;
V_11 . V_14 = V_118 ;
F_33 ( L_4 ) ;
}
