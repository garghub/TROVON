static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
V_5 -> V_8 = V_3 & 0x00ff ;
V_5 -> V_8 = ( V_3 >> 8 ) & 0x00ff ;
}
static void F_2 ( struct V_1 * V_2 , int V_9 , int V_10 )
{
T_1 V_11 , V_12 , V_13 , V_14 ;
V_11 = 0 ;
V_12 = 0x0004 ;
V_13 = ( V_9 << 6 ) & 0x00c0 ;
switch ( V_9 / 4 ) {
case 0 :
V_14 = 0x0001 ;
break;
case 1 :
V_14 = 0x0002 ;
break;
case 2 :
V_14 = 0x0005 ;
break;
case 3 :
V_14 = 0x0006 ;
break;
case 4 :
V_14 = 0x0041 ;
break;
case 5 :
V_14 = 0x0042 ;
break;
default:
V_14 = 0 ;
break;
}
V_13 |= 0x0800 ;
V_14 |= 0xc000 ;
F_1 ( V_2 , V_11 ) ;
F_1 ( V_2 , V_12 ) ;
F_1 ( V_2 , V_13 ) ;
F_1 ( V_2 , V_14 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
int V_20 ;
struct V_4 * V_5 = V_6 -> V_7 ;
int V_10 , V_9 , V_21 ;
V_5 -> V_22 =
V_23 |
V_24 | V_25 ;
V_5 -> V_26 = 1000000 ;
V_5 -> V_27 = 0 ;
V_10 = F_4 ( V_18 -> V_28 ) ;
V_9 = F_5 ( V_18 -> V_28 ) ;
for ( V_20 = 0 ; V_20 < V_18 -> V_29 ; V_20 ++ ) {
F_2 ( V_2 , V_9 , V_10 ) ;
V_5 -> V_22 = V_30 ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( V_5 -> V_22 & V_31 ) {
break;
}
}
V_5 -> V_22 = V_32 ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( V_5 -> V_22 & V_33 ) {
break;
}
}
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( V_5 -> V_22 &
V_34 ) {
break;
}
}
V_19 [ V_20 ] = V_5 -> V_35 ;
V_5 -> V_22 = V_36 ;
V_5 -> V_22 = V_37 ;
}
return V_20 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
int V_20 ;
int V_9 = F_5 ( V_18 -> V_28 ) ;
for ( V_20 = 0 ; V_20 < V_18 -> V_29 ; V_20 ++ ) {
V_19 [ V_20 ] = V_6 -> V_38 [ V_9 ] ;
}
return V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
int V_20 ;
int V_9 = F_5 ( V_18 -> V_28 ) ;
struct V_4 * V_5 = V_6 -> V_7 ;
int V_21 ;
for ( V_20 = 0 ; V_20 < V_18 -> V_29 ; V_20 ++ ) {
V_5 -> V_39 [ V_9 ] = V_19 [ V_20 ] ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( ( V_5 -> V_40 & ( ( V_9 + 1 ) * 0x0010 ) ) == 0 ) {
break;
}
}
V_6 -> V_38 [ V_9 ] = V_19 [ V_20 ] ;
}
return V_20 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( L_1 ) ;
F_10 ( V_41 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
F_10 ( V_43 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_9 ( L_2 ) ;
F_10 ( V_44 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
F_10 ( V_45 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
F_10 ( V_44 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( L_3 ) ;
F_10 ( V_46 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
F_10 ( V_47 , V_6 -> V_42 + 0x6c ) ;
F_11 ( 10000 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_48 )
{
int V_49 = 0 ;
int V_20 ;
int V_50 ;
for ( V_20 = 0 ; V_20 < 50 ; V_20 ++ ) {
V_50 = F_15 ( V_6 -> V_7 + 0x1000 ) ;
if ( ( V_50 & V_48 ) == V_48 ) {
V_49 = 1 ;
break;
}
F_11 ( 100 ) ;
}
F_11 ( 5 ) ;
return V_49 ;
}
static int F_16 ( struct V_1 * V_2 , int V_19 )
{
int V_49 = 0 ;
F_11 ( 10 ) ;
F_17 ( V_19 , V_6 -> V_7 + 0x1000 ) ;
if ( ( F_15 ( V_6 -> V_7 + 0x1000 ) & V_51 ) ==
V_51 ) {
V_49 = 1 ;
}
return V_49 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned char * V_52 , int V_53 )
{
int V_49 = - V_54 ;
int V_55 ;
int V_56 ;
int V_20 ;
V_55 = F_19 ( V_6 -> V_42 + 0x6c ) ;
if ( ! ( V_55 & V_57 ) ) {
#ifdef F_20
F_9 ( L_4 ) ;
#endif
return - V_54 ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
#ifdef F_20
F_9 ( L_5 , V_56 ) ;
#endif
F_8 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
if ( F_14 ( V_2 , V_51 ) ) {
for ( V_20 = 0 ; V_20 < V_53 ; V_20 ++ ) {
if ( V_52 [ V_20 ] == 0xff
&& V_52 [ V_20 + 1 ] == 0x20 ) {
#ifdef F_20
F_9 ( L_6 , V_20 ) ;
#endif
break;
}
}
for (; V_20 < V_53 ; V_20 += 2 ) {
int V_19 =
( V_52 [ V_20 ] << 8 ) + V_52 [ V_20 + 1 ] ;
if ( ! F_16 ( V_2 , V_19 ) ) {
break;
}
}
if ( V_20 >= V_53 ) {
#ifdef F_20
F_9 ( L_7 ) ;
#endif
F_8 ( V_2 ) ;
F_12 ( V_2 ) ;
V_49 = 0 ;
break;
}
}
}
return V_49 ;
}
static void F_21 ( struct V_1 * V_2 )
{
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
F_11 ( 2 ) ;
V_5 -> V_58 = V_59 | V_60 ;
F_11 ( 2 ) ;
V_5 -> V_58 = V_61 | V_60 ;
F_11 ( 2 ) ;
V_5 -> V_22 = V_37 ;
F_11 ( 2 ) ;
V_5 -> V_22 = V_36 ;
F_21 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
int V_21 ;
V_5 -> V_62 = 0x80 | V_63 ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( ( V_5 -> V_40 & V_64 ) == 0 ) {
break;
}
F_11 ( 2 ) ;
}
V_5 -> V_62 = 0x80 | V_65 ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( ( V_5 -> V_40 & V_64 ) == 0 ) {
break;
}
F_11 ( 2 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_1 * V_2 )
{
}
static void F_27 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
static int F_29 ( int V_66 , int V_67 , int V_19 ,
unsigned long V_68 )
{
int V_49 = 0 ;
if ( V_66 ) {
F_17 ( V_19 , ( ( void * ) V_68 ) + V_67 * 2 ) ;
V_49 = 0 ;
} else {
V_49 = F_15 ( ( ( void * ) V_68 ) + V_67 * 2 ) ;
}
return V_49 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
int V_49 = 0 ;
struct V_15 * V_16 ;
struct V_71 * V_72 = NULL ;
void * V_73 ;
unsigned int V_74 ;
int V_75 , V_76 ;
F_9 ( L_8 , V_2 -> V_77 ) ;
V_75 = V_70 -> V_78 [ 0 ] ;
V_76 = V_70 -> V_78 [ 1 ] ;
V_49 = F_31 ( V_2 , sizeof( struct V_79 ) ) ;
if ( V_49 < 0 ) {
return - V_80 ;
}
for ( V_72 = F_32 ( 0x1616 , 0x0409 , NULL ) ;
V_72 != NULL ; V_72 = F_32 ( 0x1616 , 0x0409 , V_72 ) ) {
if ( V_75 || V_76 ) {
if ( V_72 -> V_75 -> V_81 != V_75 ||
F_33 ( V_72 -> V_82 ) != V_76 ) {
continue;
}
}
break;
}
if ( ! V_72 ) {
if ( V_75 || V_76 )
F_9 ( L_9 ,
V_75 , V_76 ) ;
else
F_9 ( L_10 ) ;
return - V_54 ;
} else {
T_2 V_83 ;
int V_20 ;
V_6 -> V_71 = V_72 ;
V_83 = ( ( T_2 ) V_72 ->
V_84 << 16 ) | V_72 -> V_85 ;
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ ) {
if ( V_87 [ V_20 ] . V_83 == V_83 ) {
F_9 ( L_11 , V_87 [ V_20 ] . V_88 ) ;
V_2 -> V_89 = V_87 + V_20 ;
}
}
if ( ! V_2 -> V_89 ) {
F_9
( L_12 ,
V_83 ) ;
V_2 -> V_89 = V_87 ;
}
}
V_49 = F_34 ( V_72 , L_13 ) ;
if ( V_49 < 0 ) {
F_9 ( L_14 ) ;
return - V_54 ;
}
V_6 -> V_90 = 1 ;
V_6 -> V_42 =
F_35 ( F_36 ( V_72 , 0 ) , V_91 ) ;
V_6 -> V_7 =
F_35 ( F_36 ( V_72 , 2 ) , V_92 ) ;
if ( ! V_6 -> V_42 || ! V_6 -> V_7 ) {
return - V_80 ;
}
V_49 = F_37 ( V_2 , 3 ) ;
if ( V_49 < 0 )
goto V_93;
F_19 ( V_6 -> V_42 + 0x6c ) ;
V_73 = F_38 ( V_70 -> V_78 , 0 ) ;
V_74 = V_70 -> V_78 [ V_94 ] ;
if ( V_73 && V_74 ) {
V_49 = F_18 ( V_2 , V_73 , V_74 ) ;
} else {
F_9 ( L_15 ) ;
V_49 = - V_54 ;
}
if ( V_49 < 0 )
goto V_93;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 -> V_95 = ( unsigned long ) V_6 -> V_7 ;
V_2 -> V_96 = V_97 -> V_88 ;
V_16 = V_2 -> V_98 + 0 ;
V_16 -> type = V_99 ;
V_16 -> V_100 = V_101 | V_102 ;
V_16 -> V_103 = 24 ;
V_16 -> V_104 = 0xffff ;
V_16 -> V_105 = F_3 ;
V_16 -> V_106 = & V_107 ;
V_16 = V_2 -> V_98 + 1 ;
V_16 -> type = V_108 ;
V_16 -> V_100 = V_109 ;
V_16 -> V_103 = 2 ;
V_16 -> V_104 = 0xffff ;
V_16 -> V_105 = F_6 ;
V_16 -> V_110 = F_7 ;
V_16 -> V_106 = & V_111 ;
V_16 = V_2 -> V_98 + 2 ;
V_49 = F_39 ( V_2 , V_16 , F_29 ,
( unsigned long ) ( V_2 -> V_95 + 0x40 ) ) ;
F_9 ( L_16 ) ;
V_93:
return V_49 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_9 ( L_17 , V_2 -> V_77 ) ;
if ( V_2 -> V_98 )
F_41 ( V_2 , V_2 -> V_98 + 2 ) ;
if ( V_2 -> V_112 ) {
F_42 ( V_2 -> V_112 , V_2 ) ;
}
if ( V_6 ) {
if ( V_6 -> V_7 )
F_43 ( V_6 -> V_7 ) ;
if ( V_6 -> V_42 )
F_43 ( V_6 -> V_42 ) ;
if ( V_6 -> V_71 ) {
if ( V_6 -> V_90 ) {
F_44 ( V_6 -> V_71 ) ;
}
F_45 ( V_6 -> V_71 ) ;
}
}
return 0 ;
}
static int T_3 F_46 ( struct V_71 * V_2 ,
const struct V_113
* V_114 )
{
return F_47 ( V_2 , V_115 . V_116 ) ;
}
static void T_4 F_48 ( struct V_71 * V_2 )
{
F_49 ( V_2 ) ;
}
static int T_5 F_50 ( void )
{
int V_117 ;
V_117 = F_51 ( & V_115 ) ;
if ( V_117 < 0 )
return V_117 ;
V_118 . V_88 =
( char * ) V_115 . V_116 ;
return F_52 ( & V_118 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_118 ) ;
F_55 ( & V_115 ) ;
}
