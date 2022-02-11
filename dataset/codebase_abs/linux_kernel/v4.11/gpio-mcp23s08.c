static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 ) ;
struct V_9 V_10 ;
struct V_11 V_12 [ 2 ] = { { . V_13 = & V_5 -> V_14 , . V_15 = 1 , } ,
{ . V_13 = V_2 , . V_15 = V_3 , } , } ;
F_3 ( & V_10 ) ;
F_4 ( & V_12 [ 0 ] , & V_10 ) ;
F_4 ( & V_12 [ 1 ] , & V_10 ) ;
return F_5 ( V_7 , & V_10 ) ;
}
static int F_6 ( void * V_1 ,
const void * V_16 , T_1 V_17 ,
const void * V_18 , T_1 V_19 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 ) ;
struct V_9 V_10 ;
struct V_11 V_12 [ 3 ] = { { . V_13 = & V_5 -> V_14 , . V_15 = 1 , } ,
{ . V_13 = V_16 , . V_15 = V_17 , } ,
{ . V_13 = V_18 , . V_15 = V_19 , } , } ;
F_3 ( & V_10 ) ;
F_4 ( & V_12 [ 0 ] , & V_10 ) ;
F_4 ( & V_12 [ 1 ] , & V_10 ) ;
F_4 ( & V_12 [ 2 ] , & V_10 ) ;
return F_5 ( V_7 , & V_10 ) ;
}
static int F_7 ( void * V_1 , const void * V_16 , T_1 V_17 ,
void * V_18 , T_1 V_19 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 ) ;
T_2 V_20 [ 2 ] ;
if ( V_17 != 1 )
return - V_21 ;
V_20 [ 0 ] = V_5 -> V_14 | 0x01 ;
V_20 [ 1 ] = * ( ( T_2 * ) V_16 ) ;
return F_8 ( V_7 , V_20 , sizeof( V_20 ) , V_18 , V_19 ) ;
}
static int F_9 ( struct V_4 * V_5 , unsigned int V_16 , unsigned int * V_18 )
{
return F_10 ( V_5 -> V_22 , V_16 << V_5 -> V_23 , V_18 ) ;
}
static int F_11 ( struct V_4 * V_5 , unsigned int V_16 , unsigned int V_18 )
{
return F_12 ( V_5 -> V_22 , V_16 << V_5 -> V_23 , V_18 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
int V_24 , V_16 , V_25 ;
for ( V_25 = 0 ; V_25 < F_14 ( V_5 -> V_26 ) ; V_25 ++ ) {
V_24 = F_9 ( V_5 , V_25 , & V_16 ) ;
if ( V_24 < 0 )
return V_24 ;
V_5 -> V_26 [ V_25 ] = V_16 ;
}
return 0 ;
}
static int F_15 ( struct V_27 * V_28 , unsigned V_29 )
{
struct V_4 * V_5 = F_16 ( V_28 ) ;
int V_30 ;
F_17 ( & V_5 -> V_31 ) ;
V_5 -> V_26 [ V_32 ] |= ( 1 << V_29 ) ;
V_30 = F_11 ( V_5 , V_32 , V_5 -> V_26 [ V_32 ] ) ;
F_18 ( & V_5 -> V_31 ) ;
return V_30 ;
}
static int F_19 ( struct V_27 * V_28 , unsigned V_29 )
{
struct V_4 * V_5 = F_16 ( V_28 ) ;
int V_30 , V_24 ;
F_17 ( & V_5 -> V_31 ) ;
V_24 = F_9 ( V_5 , V_33 , & V_30 ) ;
if ( V_24 < 0 )
V_30 = 0 ;
else {
V_5 -> V_26 [ V_33 ] = V_30 ;
V_30 = ! ! ( V_30 & ( 1 << V_29 ) ) ;
}
F_18 ( & V_5 -> V_31 ) ;
return V_30 ;
}
static int F_20 ( struct V_4 * V_5 , unsigned V_34 , int V_35 )
{
unsigned V_36 = V_5 -> V_26 [ V_37 ] ;
if ( V_35 )
V_36 |= V_34 ;
else
V_36 &= ~ V_34 ;
V_5 -> V_26 [ V_37 ] = V_36 ;
return F_11 ( V_5 , V_37 , V_36 ) ;
}
static void F_21 ( struct V_27 * V_28 , unsigned V_29 , int V_35 )
{
struct V_4 * V_5 = F_16 ( V_28 ) ;
unsigned V_34 = 1 << V_29 ;
F_17 ( & V_5 -> V_31 ) ;
F_20 ( V_5 , V_34 , V_35 ) ;
F_18 ( & V_5 -> V_31 ) ;
}
static int
F_22 ( struct V_27 * V_28 , unsigned V_29 , int V_35 )
{
struct V_4 * V_5 = F_16 ( V_28 ) ;
unsigned V_34 = 1 << V_29 ;
int V_30 ;
F_17 ( & V_5 -> V_31 ) ;
V_30 = F_20 ( V_5 , V_34 , V_35 ) ;
if ( V_30 == 0 ) {
V_5 -> V_26 [ V_32 ] &= ~ V_34 ;
V_30 = F_11 ( V_5 , V_32 , V_5 -> V_26 [ V_32 ] ) ;
}
F_18 ( & V_5 -> V_31 ) ;
return V_30 ;
}
static T_3 F_23 ( int V_38 , void * V_2 )
{
struct V_4 * V_5 = V_2 ;
int V_39 , V_40 , V_25 , V_41 , V_42 , V_43 ;
unsigned int V_44 ;
bool V_45 , V_46 , V_47 ,
V_48 , V_49 ;
F_17 ( & V_5 -> V_31 ) ;
if ( F_9 ( V_5 , V_50 , & V_40 ) < 0 ) {
F_18 ( & V_5 -> V_31 ) ;
return V_51 ;
}
V_5 -> V_26 [ V_50 ] = V_40 ;
if ( F_9 ( V_5 , V_52 , & V_39 ) < 0 ) {
F_18 ( & V_5 -> V_31 ) ;
return V_51 ;
}
V_5 -> V_26 [ V_52 ] = V_39 ;
if ( F_9 ( V_5 , V_33 , & V_41 ) < 0 ) {
F_18 ( & V_5 -> V_31 ) ;
return V_51 ;
}
V_42 = V_5 -> V_26 [ V_33 ] ;
V_5 -> V_26 [ V_33 ] = V_41 ;
F_18 ( & V_5 -> V_31 ) ;
if ( V_5 -> V_26 [ V_50 ] == 0 ) {
return V_51 ;
}
F_24 ( V_5 -> V_28 . V_53 ,
L_1 ,
V_39 , V_40 , V_42 , V_41 ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_28 . V_54 ; V_25 ++ ) {
V_45 = F_25 ( V_25 ) & V_5 -> V_26 [ V_50 ] ;
if ( V_25 < 8 && V_45 )
V_43 = 0x00FF ;
else if ( V_25 >= 8 && V_45 )
V_43 = 0xFF00 ;
else
V_43 = 0x00 ;
V_46 = ( V_43 &
( F_25 ( V_25 ) & V_5 -> V_26 [ V_52 ] ) ) !=
( V_43 & ( F_25 ( V_25 ) & V_42 ) ) ;
V_49 = F_25 ( V_25 ) & V_5 -> V_26 [ V_33 ] ;
V_47 = ( F_25 ( V_25 ) & V_42 ) !=
( F_25 ( V_25 ) & V_5 -> V_26 [ V_33 ] ) ;
V_48 = ( F_25 ( V_25 ) & V_5 -> V_26 [ V_55 ] ) &&
( ( F_25 ( V_25 ) & V_5 -> V_26 [ V_33 ] ) !=
( F_25 ( V_25 ) & V_5 -> V_26 [ V_56 ] ) ) ;
if ( ( ( V_47 || V_46 ) &&
( F_25 ( V_25 ) & V_5 -> V_57 ) && V_49 ) ||
( ( V_47 || V_46 ) &&
( F_25 ( V_25 ) & V_5 -> V_58 ) && ! V_49 ) ||
V_48 ) {
V_44 = F_26 ( V_5 -> V_28 . V_59 , V_25 ) ;
F_27 ( V_44 ) ;
}
}
return V_51 ;
}
static void F_28 ( struct V_60 * V_2 )
{
struct V_27 * V_61 = F_29 ( V_2 ) ;
struct V_4 * V_5 = F_16 ( V_61 ) ;
unsigned int V_62 = V_2 -> V_63 ;
V_5 -> V_26 [ V_64 ] &= ~ F_25 ( V_62 ) ;
}
static void F_30 ( struct V_60 * V_2 )
{
struct V_27 * V_61 = F_29 ( V_2 ) ;
struct V_4 * V_5 = F_16 ( V_61 ) ;
unsigned int V_62 = V_2 -> V_63 ;
V_5 -> V_26 [ V_64 ] |= F_25 ( V_62 ) ;
}
static int F_31 ( struct V_60 * V_2 , unsigned int type )
{
struct V_27 * V_61 = F_29 ( V_2 ) ;
struct V_4 * V_5 = F_16 ( V_61 ) ;
unsigned int V_62 = V_2 -> V_63 ;
int V_30 = 0 ;
if ( ( type & V_65 ) == V_65 ) {
V_5 -> V_26 [ V_55 ] &= ~ F_25 ( V_62 ) ;
V_5 -> V_57 |= F_25 ( V_62 ) ;
V_5 -> V_58 |= F_25 ( V_62 ) ;
} else if ( type & V_66 ) {
V_5 -> V_26 [ V_55 ] &= ~ F_25 ( V_62 ) ;
V_5 -> V_57 |= F_25 ( V_62 ) ;
V_5 -> V_58 &= ~ F_25 ( V_62 ) ;
} else if ( type & V_67 ) {
V_5 -> V_26 [ V_55 ] &= ~ F_25 ( V_62 ) ;
V_5 -> V_57 &= ~ F_25 ( V_62 ) ;
V_5 -> V_58 |= F_25 ( V_62 ) ;
} else if ( type & V_68 ) {
V_5 -> V_26 [ V_55 ] |= F_25 ( V_62 ) ;
V_5 -> V_26 [ V_56 ] &= ~ F_25 ( V_62 ) ;
} else if ( type & V_69 ) {
V_5 -> V_26 [ V_55 ] |= F_25 ( V_62 ) ;
V_5 -> V_26 [ V_56 ] |= F_25 ( V_62 ) ;
} else
return - V_21 ;
return V_30 ;
}
static void F_32 ( struct V_60 * V_2 )
{
struct V_27 * V_61 = F_29 ( V_2 ) ;
struct V_4 * V_5 = F_16 ( V_61 ) ;
F_17 ( & V_5 -> V_70 ) ;
}
static void F_33 ( struct V_60 * V_2 )
{
struct V_27 * V_61 = F_29 ( V_2 ) ;
struct V_4 * V_5 = F_16 ( V_61 ) ;
F_17 ( & V_5 -> V_31 ) ;
F_11 ( V_5 , V_64 , V_5 -> V_26 [ V_64 ] ) ;
F_11 ( V_5 , V_56 , V_5 -> V_26 [ V_56 ] ) ;
F_11 ( V_5 , V_55 , V_5 -> V_26 [ V_55 ] ) ;
F_18 ( & V_5 -> V_31 ) ;
F_18 ( & V_5 -> V_70 ) ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = & V_5 -> V_28 ;
int V_71 ;
unsigned long V_72 = V_73 | V_74 ;
F_35 ( & V_5 -> V_70 ) ;
if ( V_5 -> V_75 )
V_72 |= V_76 ;
else
V_72 |= V_77 ;
V_71 = F_36 ( V_28 -> V_53 , V_5 -> V_38 , NULL ,
F_23 ,
V_72 , F_37 ( V_28 -> V_53 ) , V_5 ) ;
if ( V_71 != 0 ) {
F_38 ( V_28 -> V_53 , L_2 ,
V_5 -> V_38 , V_71 ) ;
return V_71 ;
}
V_71 = F_39 ( V_28 ,
& V_78 ,
0 ,
V_79 ,
V_80 ) ;
if ( V_71 ) {
F_38 ( V_28 -> V_53 ,
L_3 , V_71 ) ;
return V_71 ;
}
F_40 ( V_28 ,
& V_78 ,
V_5 -> V_38 ) ;
return 0 ;
}
static void F_41 ( struct V_81 * V_82 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
char V_83 ;
int V_12 ;
unsigned V_34 ;
V_5 = F_16 ( V_28 ) ;
V_83 = '0' + ( ( V_5 -> V_14 >> 1 ) & 0x7 ) ;
F_17 ( & V_5 -> V_31 ) ;
V_12 = F_13 ( V_5 ) ;
if ( V_12 < 0 ) {
F_42 ( V_82 , L_4 , V_12 ) ;
goto V_84;
}
for ( V_12 = 0 , V_34 = 1 ; V_12 < V_28 -> V_54 ; V_12 ++ , V_34 <<= 1 ) {
const char * V_85 ;
V_85 = F_43 ( V_28 , V_12 ) ;
if ( ! V_85 )
continue;
F_42 ( V_82 , L_5 ,
V_28 -> V_86 + V_12 , V_83 , V_12 , V_85 ,
( V_5 -> V_26 [ V_32 ] & V_34 ) ? L_6 : L_7 ,
( V_5 -> V_26 [ V_33 ] & V_34 ) ? L_8 : L_9 ,
( V_5 -> V_26 [ V_87 ] & V_34 ) ? L_10 : L_11 ) ;
F_44 ( V_82 , L_12 ) ;
}
V_84:
F_18 ( & V_5 -> V_31 ) ;
}
static int F_45 ( struct V_4 * V_5 , struct V_88 * V_8 ,
void * V_2 , unsigned V_14 , unsigned type ,
struct V_89 * V_90 , int V_91 )
{
int V_30 , V_24 ;
bool V_92 = false ;
F_35 ( & V_5 -> V_31 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_75 = false ;
V_5 -> V_28 . V_93 = F_15 ;
V_5 -> V_28 . V_94 = F_19 ;
V_5 -> V_28 . V_95 = F_22 ;
V_5 -> V_28 . V_96 = F_21 ;
V_5 -> V_28 . V_97 = F_41 ;
#ifdef F_46
V_5 -> V_28 . V_98 = 2 ;
V_5 -> V_28 . V_99 = V_8 -> V_99 ;
#endif
switch ( type ) {
#ifdef F_47
case V_100 :
V_5 -> V_22 = F_48 ( V_8 , & V_101 , V_5 ,
& V_102 ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_28 . V_54 = 8 ;
V_5 -> V_28 . V_85 = L_13 ;
break;
case V_103 :
V_5 -> V_22 = F_48 ( V_8 , & V_101 , V_5 ,
& V_104 ) ;
V_5 -> V_23 = 1 ;
V_5 -> V_28 . V_54 = 16 ;
V_5 -> V_28 . V_85 = L_14 ;
break;
case V_105 :
V_5 -> V_22 = F_48 ( V_8 , & V_101 , V_5 ,
& V_104 ) ;
V_5 -> V_23 = 1 ;
V_5 -> V_28 . V_54 = 16 ;
V_5 -> V_28 . V_85 = L_15 ;
break;
#endif
#if F_49 ( V_106 )
case V_107 :
V_5 -> V_22 = F_50 ( V_2 , & V_102 ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_28 . V_54 = 8 ;
V_5 -> V_28 . V_85 = L_16 ;
break;
case V_108 :
V_5 -> V_22 = F_50 ( V_2 , & V_104 ) ;
V_5 -> V_23 = 1 ;
V_5 -> V_28 . V_54 = 16 ;
V_5 -> V_28 . V_85 = L_17 ;
break;
#endif
default:
F_38 ( V_8 , L_18 , type ) ;
return - V_21 ;
}
if ( F_51 ( V_5 -> V_22 ) )
return F_52 ( V_5 -> V_22 ) ;
V_5 -> V_28 . V_86 = V_90 -> V_86 ;
V_5 -> V_28 . V_109 = true ;
V_5 -> V_28 . V_53 = V_8 ;
V_5 -> V_28 . V_110 = V_111 ;
V_24 = F_9 ( V_5 , V_112 , & V_30 ) ;
if ( V_24 < 0 )
goto V_113;
V_5 -> V_114 = V_90 -> V_114 ;
if ( V_5 -> V_38 && V_5 -> V_114 ) {
V_5 -> V_75 =
F_53 ( V_5 -> V_28 . V_53 -> V_99 ,
L_19 ) ;
V_92 = V_90 -> V_92 ;
}
if ( ( V_30 & V_115 ) || ! ( V_30 & V_116 ) || V_92 ||
V_5 -> V_75 ) {
V_30 &= ~ ( V_115 | ( V_115 << 8 ) ) ;
V_30 |= V_116 | ( V_116 << 8 ) ;
if ( V_5 -> V_75 )
V_30 |= V_117 | ( V_117 << 8 ) ;
else
V_30 &= ~ ( V_117 | ( V_117 << 8 ) ) ;
if ( V_92 )
V_30 |= V_118 | ( V_118 << 8 ) ;
if ( type == V_105 )
V_30 |= V_119 | ( V_119 << 8 ) ;
V_24 = F_11 ( V_5 , V_112 , V_30 ) ;
if ( V_24 < 0 )
goto V_113;
}
V_24 = F_11 ( V_5 , V_87 , V_90 -> V_28 [ V_91 ] . V_120 ) ;
if ( V_24 < 0 )
goto V_113;
V_24 = F_13 ( V_5 ) ;
if ( V_24 < 0 )
goto V_113;
if ( V_5 -> V_26 [ V_121 ] != 0 ) {
V_5 -> V_26 [ V_121 ] = 0 ;
V_24 = F_11 ( V_5 , V_121 , 0 ) ;
if ( V_24 < 0 )
goto V_113;
}
if ( V_5 -> V_26 [ V_64 ] != 0 ) {
V_5 -> V_26 [ V_64 ] = 0 ;
V_24 = F_11 ( V_5 , V_64 , 0 ) ;
if ( V_24 < 0 )
goto V_113;
}
V_24 = F_54 ( & V_5 -> V_28 , V_5 ) ;
if ( V_24 < 0 )
goto V_113;
if ( V_5 -> V_38 && V_5 -> V_114 ) {
V_24 = F_34 ( V_5 ) ;
if ( V_24 )
goto V_113;
}
V_113:
if ( V_24 < 0 )
F_24 ( V_8 , L_20 , V_14 , V_24 ) ;
return V_24 ;
}
static int F_55 ( struct V_122 * V_123 ,
const struct V_124 * V_125 )
{
struct V_89 * V_90 , V_126 ;
struct V_4 * V_5 ;
int V_30 ;
const struct V_127 * V_128 ;
V_128 = F_56 ( F_57 ( V_129 ) ,
& V_123 -> V_8 ) ;
if ( V_128 ) {
V_90 = & V_126 ;
V_90 -> V_86 = - 1 ;
V_90 -> V_28 [ 0 ] . V_120 = 0 ;
V_90 -> V_114 = F_53 (
V_123 -> V_8 . V_99 ,
L_21 ) ;
V_90 -> V_92 = F_53 ( V_123 -> V_8 . V_99 ,
L_22 ) ;
V_123 -> V_38 = F_58 ( V_123 -> V_8 . V_99 , 0 ) ;
} else {
V_90 = F_59 ( & V_123 -> V_8 ) ;
if ( ! V_90 ) {
V_90 = F_60 ( & V_123 -> V_8 ,
sizeof( struct V_89 ) ,
V_130 ) ;
if ( ! V_90 )
return - V_131 ;
V_90 -> V_86 = - 1 ;
}
}
V_5 = F_61 ( sizeof( * V_5 ) , V_130 ) ;
if ( ! V_5 )
return - V_131 ;
V_5 -> V_38 = V_123 -> V_38 ;
V_30 = F_45 ( V_5 , & V_123 -> V_8 , V_123 , V_123 -> V_14 ,
V_125 -> V_132 , V_90 , 0 ) ;
if ( V_30 )
goto V_113;
F_62 ( V_123 , V_5 ) ;
return 0 ;
V_113:
F_63 ( V_5 ) ;
return V_30 ;
}
static int F_64 ( struct V_122 * V_123 )
{
struct V_4 * V_5 = F_65 ( V_123 ) ;
F_66 ( & V_5 -> V_28 ) ;
F_63 ( V_5 ) ;
return 0 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_133 ) ;
}
static void F_69 ( void )
{
F_70 ( & V_133 ) ;
}
static int T_4 F_67 ( void ) { return 0 ; }
static void F_69 ( void ) { }
static int F_71 ( struct V_6 * V_7 )
{
struct V_89 * V_90 , V_126 ;
unsigned V_14 ;
int V_134 = 0 ;
struct V_135 * V_2 ;
int V_30 , type ;
unsigned V_54 = 0 ;
const struct V_127 * V_128 ;
T_5 V_136 = 0 ;
V_128 = F_56 ( F_57 ( V_137 ) , & V_7 -> V_8 ) ;
if ( V_128 ) {
type = ( int ) ( V_138 ) V_128 -> V_2 ;
V_30 = F_72 ( V_7 -> V_8 . V_99 ,
L_23 , & V_136 ) ;
if ( V_30 ) {
V_30 = F_72 ( V_7 -> V_8 . V_99 ,
L_24 , & V_136 ) ;
if ( V_30 ) {
F_38 ( & V_7 -> V_8 ,
L_25 ) ;
return - V_139 ;
}
}
if ( ( V_136 <= 0 ) || ( V_136 >= 256 ) ) {
F_38 ( & V_7 -> V_8 , L_26 ) ;
return - V_139 ;
}
V_90 = & V_126 ;
V_90 -> V_86 = - 1 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_90 -> V_28 ) ; V_14 ++ ) {
V_90 -> V_28 [ V_14 ] . V_120 = 0 ;
if ( V_136 & ( 1 << V_14 ) )
V_134 ++ ;
}
V_90 -> V_114 = F_53 (
V_7 -> V_8 . V_99 ,
L_21 ) ;
V_90 -> V_92 = F_53 ( V_7 -> V_8 . V_99 ,
L_22 ) ;
} else {
type = F_73 ( V_7 ) -> V_132 ;
V_90 = F_59 ( & V_7 -> V_8 ) ;
if ( ! V_90 ) {
V_90 = F_60 ( & V_7 -> V_8 ,
sizeof( struct V_89 ) ,
V_130 ) ;
V_90 -> V_86 = - 1 ;
}
for ( V_14 = 0 ; V_14 < F_14 ( V_90 -> V_28 ) ; V_14 ++ ) {
if ( ! V_90 -> V_28 [ V_14 ] . V_140 )
continue;
V_134 ++ ;
if ( ( type == V_100 ) && ( V_14 > 3 ) ) {
F_38 ( & V_7 -> V_8 ,
L_27 ) ;
return - V_21 ;
}
V_136 |= 1 << V_14 ;
}
}
if ( ! V_134 )
return - V_139 ;
V_2 = F_60 ( & V_7 -> V_8 ,
sizeof( * V_2 ) + V_134 * sizeof( struct V_4 ) ,
V_130 ) ;
if ( ! V_2 )
return - V_131 ;
F_74 ( V_7 , V_2 ) ;
V_7 -> V_38 = F_58 ( V_7 -> V_8 . V_99 , 0 ) ;
for ( V_14 = 0 ; V_14 < F_14 ( V_90 -> V_28 ) ; V_14 ++ ) {
if ( ! ( V_136 & ( 1 << V_14 ) ) )
continue;
V_134 -- ;
V_2 -> V_5 [ V_14 ] = & V_2 -> V_28 [ V_134 ] ;
V_2 -> V_5 [ V_14 ] -> V_38 = V_7 -> V_38 ;
V_30 = F_45 ( V_2 -> V_5 [ V_14 ] , & V_7 -> V_8 , V_7 ,
0x40 | ( V_14 << 1 ) , type , V_90 ,
V_14 ) ;
if ( V_30 < 0 )
goto V_113;
if ( V_90 -> V_86 != - 1 )
V_90 -> V_86 += V_2 -> V_5 [ V_14 ] -> V_28 . V_54 ;
V_54 += V_2 -> V_5 [ V_14 ] -> V_28 . V_54 ;
}
V_2 -> V_54 = V_54 ;
return 0 ;
V_113:
for ( V_14 = 0 ; V_14 < F_14 ( V_2 -> V_5 ) ; V_14 ++ ) {
if ( ! V_2 -> V_5 [ V_14 ] )
continue;
F_66 ( & V_2 -> V_5 [ V_14 ] -> V_28 ) ;
}
return V_30 ;
}
static int F_75 ( struct V_6 * V_7 )
{
struct V_135 * V_2 = F_76 ( V_7 ) ;
unsigned V_14 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_2 -> V_5 ) ; V_14 ++ ) {
if ( ! V_2 -> V_5 [ V_14 ] )
continue;
F_66 ( & V_2 -> V_5 [ V_14 ] -> V_28 ) ;
}
return 0 ;
}
static int T_4 F_77 ( void )
{
return F_78 ( & V_141 ) ;
}
static void F_79 ( void )
{
F_80 ( & V_141 ) ;
}
static int T_4 F_77 ( void ) { return 0 ; }
static void F_79 ( void ) { }
static int T_4 F_81 ( void )
{
int V_24 ;
V_24 = F_77 () ;
if ( V_24 )
goto V_142;
V_24 = F_67 () ;
if ( V_24 )
goto V_143;
return 0 ;
V_143:
F_79 () ;
V_142:
return V_24 ;
}
static void T_6 F_82 ( void )
{
F_79 () ;
F_69 () ;
}
