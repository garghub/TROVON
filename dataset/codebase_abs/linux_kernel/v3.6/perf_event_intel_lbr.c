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
T_1 V_33 , V_34 , V_43 = 0 , V_44 = 0 ;
F_4 ( V_11 . V_13 + V_32 , V_33 ) ;
F_4 ( V_11 . V_14 + V_32 , V_34 ) ;
if ( V_16 == V_45 ) {
V_43 = ! ! ( V_33 & V_46 ) ;
V_44 = ! V_43 ;
V_33 = ( T_1 ) ( ( ( ( V_47 ) V_33 ) << 1 ) >> 1 ) ;
}
V_3 -> V_37 [ V_10 ] . V_33 = V_33 ;
V_3 -> V_37 [ V_10 ] . V_34 = V_34 ;
V_3 -> V_37 [ V_10 ] . V_38 = V_43 ;
V_3 -> V_37 [ V_10 ] . V_39 = V_44 ;
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
T_1 V_48 = V_19 -> V_49 . V_50 ;
int V_31 = 0 ;
if ( V_48 & V_51 )
V_31 |= V_52 ;
if ( V_48 & V_53 )
V_31 |= V_54 ;
if ( V_48 & V_55 )
V_31 |= V_56 ;
if ( V_48 & V_57 )
V_31 |= V_58 ;
if ( V_48 & V_59 )
V_31 |= V_60 | V_61 | V_62 ;
if ( V_48 & V_63 )
V_31 |= V_64 ;
V_19 -> V_24 . V_25 . V_26 = V_31 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_65 * V_26 ;
T_1 V_48 = V_19 -> V_49 . V_50 ;
T_1 V_31 = 0 , V_66 ;
T_1 V_67 ;
F_21 (m) {
if ( ! ( V_48 & V_66 ) )
continue;
V_67 = V_11 . V_68 [ V_66 ] ;
if ( V_67 == V_69 )
return - V_70 ;
if ( V_67 != V_71 )
V_31 |= V_67 ;
}
V_26 = & V_19 -> V_24 . V_25 ;
V_26 -> V_72 = V_73 ;
V_26 -> V_6 = ~ V_31 & V_11 . V_74 ;
return 0 ;
}
int F_22 ( struct V_18 * V_19 )
{
int V_75 = 0 ;
if ( ! V_11 . V_12 )
return - V_70 ;
F_19 ( V_19 ) ;
if ( V_11 . V_68 )
V_75 = F_20 ( V_19 ) ;
return V_75 ;
}
static int F_23 ( unsigned long V_33 , unsigned long V_34 )
{
struct V_76 V_76 ;
void * V_77 ;
int V_78 , V_79 = V_80 ;
int V_75 = V_81 ;
int V_82 , V_83 , V_84 ;
T_3 V_85 [ V_80 ] ;
int V_86 = 0 ;
V_83 = F_24 ( V_34 ) ? V_54 : V_52 ;
V_84 = F_24 ( V_33 ) ? V_54 : V_52 ;
if ( V_33 == 0 || V_34 == 0 )
return V_81 ;
if ( V_84 == V_52 ) {
if ( ! V_87 -> V_88 )
return V_81 ;
V_78 = F_25 ( V_85 , ( void V_89 * ) V_33 , V_79 ) ;
if ( V_78 != V_79 )
return V_81 ;
V_77 = V_85 ;
} else
V_77 = ( void * ) V_33 ;
#ifdef F_26
V_86 = F_24 ( ( unsigned long ) V_77 ) || ! F_27 ( V_90 ) ;
#endif
F_28 ( & V_76 , V_77 , V_86 ) ;
F_29 ( & V_76 ) ;
switch ( V_76 . V_91 . V_78 [ 0 ] ) {
case 0xf :
switch ( V_76 . V_91 . V_78 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_75 = V_92 ;
break;
case 0x07 :
case 0x35 :
V_75 = V_62 ;
break;
case 0x80 ... 0x8f :
V_75 = V_93 ;
break;
default:
V_75 = V_81 ;
}
break;
case 0x70 ... 0x7f :
V_75 = V_93 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_75 = V_60 ;
break;
case 0xcf :
V_75 = V_61 ;
break;
case 0xcc ... 0xce :
V_75 = V_94 ;
break;
case 0xe8 :
case 0x9a :
V_75 = V_95 ;
break;
case 0xe0 ... 0xe3 :
V_75 = V_93 ;
break;
case 0xe9 ... 0xeb :
V_75 = V_96 ;
break;
case 0xff :
F_30 ( & V_76 ) ;
V_82 = ( V_76 . V_97 . V_78 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_82 ) {
case 2 :
case 3 :
V_75 = V_64 ;
break;
case 4 :
case 5 :
V_75 = V_96 ;
break;
}
break;
default:
V_75 = V_81 ;
}
if ( V_84 == V_52 && V_83 == V_54
&& V_75 != V_92 && V_75 != V_94 )
V_75 = V_98 ;
if ( V_75 != V_81 )
V_75 |= V_83 ;
return V_75 ;
}
static void
F_18 ( struct V_2 * V_3 )
{
T_1 V_33 , V_34 ;
int V_23 = V_3 -> V_23 ;
int V_10 , V_99 , type ;
bool V_100 = false ;
if ( ( V_23 & V_101 ) == V_101 )
return;
for ( V_10 = 0 ; V_10 < V_3 -> V_41 . V_42 ; V_10 ++ ) {
V_33 = V_3 -> V_37 [ V_10 ] . V_33 ;
V_34 = V_3 -> V_37 [ V_10 ] . V_34 ;
type = F_23 ( V_33 , V_34 ) ;
if ( type == V_81 || ( V_23 & type ) != type ) {
V_3 -> V_37 [ V_10 ] . V_33 = 0 ;
V_100 = true ;
}
}
if ( ! V_100 )
return;
for ( V_10 = 0 ; V_10 < V_3 -> V_41 . V_42 ; ) {
if ( ! V_3 -> V_37 [ V_10 ] . V_33 ) {
V_99 = V_10 ;
while ( ++ V_99 < V_3 -> V_41 . V_42 )
V_3 -> V_37 [ V_99 - 1 ] = V_3 -> V_37 [ V_99 ] ;
V_3 -> V_41 . V_42 -- ;
if ( ! V_3 -> V_37 [ V_10 ] . V_33 )
continue;
}
V_10 ++ ;
}
}
void F_31 ( void )
{
V_11 . V_12 = 4 ;
V_11 . V_30 = V_102 ;
V_11 . V_13 = V_103 ;
V_11 . V_14 = V_104 ;
F_32 ( L_1 ) ;
}
void F_33 ( void )
{
V_11 . V_12 = 16 ;
V_11 . V_30 = V_102 ;
V_11 . V_13 = V_105 ;
V_11 . V_14 = V_106 ;
V_11 . V_74 = V_107 ;
V_11 . V_68 = V_108 ;
F_32 ( L_2 ) ;
}
void F_34 ( void )
{
V_11 . V_12 = 16 ;
V_11 . V_30 = V_102 ;
V_11 . V_13 = V_105 ;
V_11 . V_14 = V_106 ;
V_11 . V_74 = V_107 ;
V_11 . V_68 = V_109 ;
F_32 ( L_2 ) ;
}
void F_35 ( void )
{
if ( V_110 . V_111 == 28
&& V_110 . V_112 < 10 ) {
F_32 ( L_3 ) ;
return;
}
V_11 . V_12 = 8 ;
V_11 . V_30 = V_102 ;
V_11 . V_13 = V_103 ;
V_11 . V_14 = V_104 ;
F_32 ( L_4 ) ;
}
