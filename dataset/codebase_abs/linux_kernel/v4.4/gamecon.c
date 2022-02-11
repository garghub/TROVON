static void F_1 ( struct V_1 * V_1 , unsigned long V_2 ,
unsigned char V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_5 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
unsigned char V_9 = ( V_2 >> V_7 ) & 1 ? V_3 : 0 ;
F_2 ( V_5 , V_10 | V_9 ) ;
F_3 ( V_11 ) ;
}
}
static void F_4 ( struct V_1 * V_1 , unsigned char V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_5 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
unsigned char V_9 = ( V_13 >> V_7 ) & 1 ? V_3 : 0 ;
F_2 ( V_5 , V_10 | V_9 ) ;
F_3 ( V_11 ) ;
}
}
static void F_5 ( struct V_1 * V_1 , unsigned char * V_9 )
{
int V_7 ;
unsigned long V_14 ;
F_6 ( V_14 ) ;
F_1 ( V_1 , V_15 , V_16 ) ;
F_4 ( V_1 , V_16 ) ;
F_7 ( V_14 ) ;
F_3 ( V_17 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
F_2 ( V_1 -> V_6 -> V_5 , V_18 ) ;
F_3 ( 2 ) ;
V_9 [ V_7 ] = F_8 ( V_1 -> V_6 -> V_5 ) ;
F_2 ( V_1 -> V_6 -> V_5 , V_18 | V_19 ) ;
}
}
static void F_9 ( struct V_1 * V_1 )
{
unsigned char V_9 [ V_8 ] ;
struct V_20 * V_21 ;
int V_7 , V_22 , V_23 ;
signed char V_24 , V_25 ;
F_5 ( V_1 , V_9 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
if ( V_1 -> V_27 [ V_7 ] . type != V_28 )
continue;
V_21 = V_1 -> V_27 [ V_7 ] . V_21 ;
V_23 = V_29 [ V_7 ] ;
if ( V_23 & ~ ( V_9 [ 8 ] | V_9 [ 9 ] ) ) {
V_24 = V_25 = 0 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_9 [ 23 - V_22 ] & V_23 )
V_24 |= 1 << V_22 ;
if ( V_9 [ 31 - V_22 ] & V_23 )
V_25 |= 1 << V_22 ;
}
F_10 ( V_21 , V_30 , V_24 ) ;
F_10 ( V_21 , V_31 , - V_25 ) ;
F_10 ( V_21 , V_32 ,
! ( V_23 & V_9 [ 6 ] ) - ! ( V_23 & V_9 [ 7 ] ) ) ;
F_10 ( V_21 , V_33 ,
! ( V_23 & V_9 [ 4 ] ) - ! ( V_23 & V_9 [ 5 ] ) ) ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ )
F_11 ( V_21 , V_34 [ V_22 ] ,
V_23 & V_9 [ V_35 [ V_22 ] ] ) ;
F_12 ( V_21 ) ;
}
}
}
static int F_13 ( struct V_20 * V_21 , void * V_9 ,
struct V_36 * V_37 )
{
int V_7 ;
unsigned long V_14 ;
struct V_1 * V_1 = F_14 ( V_21 ) ;
struct V_38 * V_39 = V_9 ;
unsigned char V_3 = 1 << V_39 -> V_40 ;
if ( V_37 -> type == V_41 ) {
struct V_42 * V_43 = & V_37 -> V_44 . V_43 ;
unsigned int V_2 =
V_43 -> V_45 || V_43 -> V_46 ?
V_47 : V_48 ;
F_6 ( V_14 ) ;
F_1 ( V_1 , V_49 , V_3 ) ;
F_1 ( V_1 , V_50 , V_3 ) ;
F_1 ( V_1 , V_47 , V_3 ) ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
F_1 ( V_1 , V_50 , V_3 ) ;
F_4 ( V_1 , V_3 ) ;
F_3 ( V_17 ) ;
F_1 ( V_1 , V_49 , V_3 ) ;
F_1 ( V_1 , V_51 , V_3 ) ;
F_1 ( V_1 , V_52 , V_3 ) ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
F_1 ( V_1 , V_2 , V_3 ) ;
F_4 ( V_1 , V_3 ) ;
F_7 ( V_14 ) ;
}
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , int V_7 )
{
struct V_38 * V_39 ;
int V_53 ;
V_39 = F_16 ( sizeof( * V_39 ) , V_54 ) ;
if ( ! V_39 )
return - V_55 ;
V_39 -> V_40 = V_7 ;
F_17 ( V_21 , V_56 , V_41 ) ;
V_53 = F_18 ( V_21 , V_39 , F_13 ) ;
if ( V_53 ) {
F_19 ( V_39 ) ;
return V_53 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_1 , int V_57 , unsigned char * V_9 )
{
int V_7 ;
F_2 ( V_1 -> V_6 -> V_5 , V_58 | V_59 | V_60 ) ;
F_3 ( V_61 * 2 ) ;
F_2 ( V_1 -> V_6 -> V_5 , V_58 | V_59 ) ;
for ( V_7 = 0 ; V_7 < V_57 ; V_7 ++ ) {
F_3 ( V_61 ) ;
F_2 ( V_1 -> V_6 -> V_5 , V_58 ) ;
V_9 [ V_7 ] = F_8 ( V_1 -> V_6 -> V_5 ) ^ 0x7f ;
F_3 ( V_61 ) ;
F_2 ( V_1 -> V_6 -> V_5 , V_58 | V_59 ) ;
}
}
static void F_21 ( struct V_1 * V_1 )
{
unsigned char V_9 [ V_62 ] ;
struct V_63 * V_64 ;
struct V_20 * V_21 ;
int V_7 , V_22 , V_23 , V_65 ;
char V_66 , V_67 ;
V_65 = V_1 -> V_68 [ V_69 ] ? V_62 :
( V_1 -> V_68 [ V_70 ] ? V_71 : V_72 ) ;
F_20 ( V_1 , V_65 , V_9 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
V_64 = & V_1 -> V_27 [ V_7 ] ;
V_21 = V_64 -> V_21 ;
V_23 = V_29 [ V_7 ] ;
switch ( V_64 -> type ) {
case V_73 :
F_10 ( V_21 , V_30 , ! ( V_23 & V_9 [ 6 ] ) - ! ( V_23 & V_9 [ 7 ] ) ) ;
F_10 ( V_21 , V_31 , ! ( V_23 & V_9 [ 4 ] ) - ! ( V_23 & V_9 [ 5 ] ) ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
F_11 ( V_21 , V_74 [ V_22 ] ,
V_23 & V_9 [ V_75 [ V_22 ] ] ) ;
F_12 ( V_21 ) ;
break;
case V_70 :
F_10 ( V_21 , V_30 , ! ( V_23 & V_9 [ 6 ] ) - ! ( V_23 & V_9 [ 7 ] ) ) ;
F_10 ( V_21 , V_31 , ! ( V_23 & V_9 [ 4 ] ) - ! ( V_23 & V_9 [ 5 ] ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_11 ( V_21 , V_74 [ V_22 ] ,
V_23 & V_9 [ V_76 [ V_22 ] ] ) ;
F_12 ( V_21 ) ;
break;
case V_69 :
if ( ! ( V_23 & V_9 [ 12 ] ) && ! ( V_23 & V_9 [ 13 ] ) &&
! ( V_23 & V_9 [ 14 ] ) && ( V_23 & V_9 [ 15 ] ) ) {
F_11 ( V_21 , V_77 , V_23 & V_9 [ 9 ] ) ;
F_11 ( V_21 , V_78 , V_23 & V_9 [ 8 ] ) ;
V_66 = V_67 = 0 ;
for ( V_22 = 0 ; V_22 < 7 ; V_22 ++ ) {
V_66 <<= 1 ;
if ( V_9 [ 25 + V_22 ] & V_23 )
V_66 |= 1 ;
V_67 <<= 1 ;
if ( V_9 [ 17 + V_22 ] & V_23 )
V_67 |= 1 ;
}
if ( V_66 ) {
if ( V_9 [ 24 ] & V_23 )
V_66 = - V_66 ;
F_22 ( V_21 , V_79 , V_66 ) ;
}
if ( V_67 ) {
if ( V_9 [ 16 ] & V_23 )
V_67 = - V_67 ;
F_22 ( V_21 , V_80 , V_67 ) ;
}
F_12 ( V_21 ) ;
}
break;
default:
break;
}
}
}
static void F_23 ( struct V_1 * V_1 , int V_57 , unsigned char * V_9 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_57 ; V_7 ++ ) {
F_2 ( V_1 -> V_6 -> V_5 , ~ ( 1 << V_7 ) ) ;
V_9 [ V_7 ] = F_8 ( V_1 -> V_6 -> V_5 ) ^ 0x7f ;
}
}
static void F_24 ( struct V_1 * V_1 )
{
unsigned char V_9 [ V_81 ] ;
int V_82 = V_1 -> V_68 [ V_83 ] ? V_81 : V_84 ;
struct V_63 * V_64 ;
struct V_20 * V_21 ;
int V_7 , V_23 ;
F_23 ( V_1 , V_82 , V_9 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
V_64 = & V_1 -> V_27 [ V_7 ] ;
V_21 = V_64 -> V_21 ;
V_23 = V_29 [ V_7 ] ;
switch ( V_64 -> type ) {
case V_83 :
F_11 ( V_21 , V_85 , V_23 & V_9 [ 5 ] ) ;
case V_86 :
F_10 ( V_21 , V_30 ,
! ( V_23 & V_9 [ 2 ] ) - ! ( V_23 & V_9 [ 3 ] ) ) ;
F_10 ( V_21 , V_31 ,
! ( V_23 & V_9 [ 0 ] ) - ! ( V_23 & V_9 [ 1 ] ) ) ;
F_11 ( V_21 , V_87 , V_23 & V_9 [ 4 ] ) ;
F_12 ( V_21 ) ;
break;
default:
break;
}
}
}
static void F_25 ( struct V_1 * V_1 , int V_88 , unsigned char * V_9 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_5 ;
int V_7 , V_22 , V_2 , V_89 ;
memset ( V_9 , 0 , V_26 ) ;
for ( V_7 = 0 ; V_7 < V_90 ; V_7 ++ , V_88 >>= 1 ) {
V_2 = ( V_88 & 1 ) ? V_91 : 0 ;
F_2 ( V_5 , V_2 | V_92 ) ;
F_3 ( V_93 ) ;
V_89 = F_8 ( V_5 ) ^ 0x80 ;
for ( V_22 = 0 ; V_22 < V_26 ; V_22 ++ ) {
struct V_63 * V_64 = & V_1 -> V_27 [ V_22 ] ;
if ( V_64 -> type == V_94 || V_64 -> type == V_95 )
V_9 [ V_22 ] |= ( V_89 & V_29 [ V_22 ] ) ? ( 1 << V_7 ) : 0 ;
}
F_2 ( V_1 -> V_6 -> V_5 , V_2 | V_96 | V_92 ) ;
F_3 ( V_93 ) ;
}
}
static void F_26 ( struct V_1 * V_1 ,
unsigned char V_9 [ V_26 ] [ V_97 ] ,
unsigned char V_98 [ V_26 ] )
{
int V_7 , V_22 , V_99 = 0 ;
unsigned long V_14 ;
unsigned char V_100 [ V_26 ] ;
F_2 ( V_1 -> V_6 -> V_5 , V_96 | V_101 | V_92 ) ;
F_3 ( V_93 ) ;
F_2 ( V_1 -> V_6 -> V_5 , V_96 | V_92 ) ;
F_3 ( V_93 ) ;
F_6 ( V_14 ) ;
F_25 ( V_1 , 0x01 , V_100 ) ;
F_25 ( V_1 , 0x42 , V_98 ) ;
F_25 ( V_1 , 0 , V_100 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
struct V_63 * V_64 = & V_1 -> V_27 [ V_7 ] ;
if ( ( V_64 -> type == V_94 || V_64 -> type == V_95 ) &&
F_27 ( V_98 [ V_7 ] ) > V_99 &&
F_27 ( V_98 [ V_7 ] ) <= V_97 ) {
V_99 = F_27 ( V_98 [ V_7 ] ) ;
}
}
for ( V_7 = 0 ; V_7 < V_99 ; V_7 ++ ) {
F_25 ( V_1 , 0 , V_100 ) ;
for ( V_22 = 0 ; V_22 < V_26 ; V_22 ++ )
V_9 [ V_22 ] [ V_7 ] = V_100 [ V_22 ] ;
}
F_7 ( V_14 ) ;
F_2 ( V_1 -> V_6 -> V_5 , V_96 | V_101 | V_92 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ )
V_98 [ V_7 ] = F_28 ( V_98 [ V_7 ] ) ;
}
static void F_29 ( struct V_63 * V_64 , unsigned char V_102 ,
unsigned char * V_9 )
{
struct V_20 * V_21 = V_64 -> V_21 ;
int V_7 ;
switch ( V_102 ) {
case V_103 :
F_11 ( V_21 , V_104 , ~ V_9 [ 0 ] & 0x04 ) ;
F_11 ( V_21 , V_105 , ~ V_9 [ 0 ] & 0x02 ) ;
case V_106 :
case V_107 :
if ( V_64 -> type == V_95 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_11 ( V_21 , V_108 [ V_7 ] ,
~ V_9 [ 0 ] & ( 0x10 << V_7 ) ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_10 ( V_21 , V_109 [ V_7 + 2 ] ,
V_9 [ V_7 + 2 ] ) ;
F_10 ( V_21 , V_30 ,
! ! ( V_9 [ 0 ] & 0x80 ) * 128 + ! ( V_9 [ 0 ] & 0x20 ) * 127 ) ;
F_10 ( V_21 , V_31 ,
! ! ( V_9 [ 0 ] & 0x10 ) * 128 + ! ( V_9 [ 0 ] & 0x40 ) * 127 ) ;
}
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
F_11 ( V_21 , V_110 [ V_7 ] , ~ V_9 [ 1 ] & ( 1 << V_7 ) ) ;
F_11 ( V_21 , V_111 , ~ V_9 [ 0 ] & 0x08 ) ;
F_11 ( V_21 , V_112 , ~ V_9 [ 0 ] & 0x01 ) ;
F_12 ( V_21 ) ;
break;
case V_113 :
if ( V_64 -> type == V_95 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_11 ( V_21 , V_108 [ V_7 ] ,
~ V_9 [ 0 ] & ( 0x10 << V_7 ) ) ;
} else {
F_10 ( V_21 , V_30 ,
! ! ( V_9 [ 0 ] & 0x80 ) * 128 + ! ( V_9 [ 0 ] & 0x20 ) * 127 ) ;
F_10 ( V_21 , V_31 ,
! ! ( V_9 [ 0 ] & 0x10 ) * 128 + ! ( V_9 [ 0 ] & 0x40 ) * 127 ) ;
}
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
F_11 ( V_21 , V_110 [ V_7 ] , ~ V_9 [ 1 ] & ( 1 << V_7 ) ) ;
F_11 ( V_21 , V_111 , ~ V_9 [ 0 ] & 0x08 ) ;
F_11 ( V_21 , V_112 , ~ V_9 [ 0 ] & 0x01 ) ;
F_12 ( V_21 ) ;
break;
default:
break;
}
}
static void F_30 ( struct V_1 * V_1 )
{
unsigned char V_9 [ V_26 ] [ V_97 ] ;
unsigned char V_98 [ V_26 ] ;
struct V_63 * V_64 ;
int V_7 ;
F_26 ( V_1 , V_9 , V_98 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
V_64 = & V_1 -> V_27 [ V_7 ] ;
if ( V_64 -> type == V_94 || V_64 -> type == V_95 )
F_29 ( V_64 , V_98 [ V_7 ] , V_9 [ V_7 ] ) ;
}
}
static void F_31 ( unsigned long V_114 )
{
struct V_1 * V_1 = ( void * ) V_114 ;
if ( V_1 -> V_68 [ V_28 ] )
F_9 ( V_1 ) ;
if ( V_1 -> V_68 [ V_73 ] ||
V_1 -> V_68 [ V_70 ] ||
V_1 -> V_68 [ V_69 ] ) {
F_21 ( V_1 ) ;
}
if ( V_1 -> V_68 [ V_86 ] || V_1 -> V_68 [ V_83 ] )
F_24 ( V_1 ) ;
if ( V_1 -> V_68 [ V_94 ] || V_1 -> V_68 [ V_95 ] )
F_30 ( V_1 ) ;
F_32 ( & V_1 -> V_115 , V_116 + V_117 ) ;
}
static int F_33 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
int V_53 ;
V_53 = F_34 ( & V_1 -> V_118 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_1 -> V_119 ++ ) {
F_35 ( V_1 -> V_6 ) ;
F_36 ( V_1 -> V_6 -> V_5 , 0x04 ) ;
F_32 ( & V_1 -> V_115 , V_116 + V_117 ) ;
}
F_37 ( & V_1 -> V_118 ) ;
return 0 ;
}
static void F_38 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
F_39 ( & V_1 -> V_118 ) ;
if ( ! -- V_1 -> V_119 ) {
F_40 ( & V_1 -> V_115 ) ;
F_36 ( V_1 -> V_6 -> V_5 , 0x00 ) ;
F_41 ( V_1 -> V_6 ) ;
}
F_37 ( & V_1 -> V_118 ) ;
}
static int F_42 ( struct V_1 * V_1 , int V_40 , int V_120 )
{
struct V_63 * V_64 = & V_1 -> V_27 [ V_40 ] ;
struct V_20 * V_20 ;
int V_7 ;
int V_53 ;
if ( V_120 < 1 || V_120 >= V_121 ) {
F_43 ( L_1 , V_120 ) ;
return - V_122 ;
}
V_64 -> V_21 = V_20 = F_44 () ;
if ( ! V_20 ) {
F_43 ( L_2 ) ;
return - V_55 ;
}
V_64 -> type = V_120 ;
snprintf ( V_64 -> V_123 , sizeof( V_64 -> V_123 ) ,
L_3 , V_1 -> V_6 -> V_5 -> V_124 , V_40 ) ;
V_20 -> V_124 = V_125 [ V_120 ] ;
V_20 -> V_123 = V_64 -> V_123 ;
V_20 -> V_98 . V_126 = V_127 ;
V_20 -> V_98 . V_128 = 0x0001 ;
V_20 -> V_98 . V_129 = V_120 ;
V_20 -> V_98 . V_130 = 0x0100 ;
F_45 ( V_20 , V_1 ) ;
V_20 -> V_131 = F_33 ;
V_20 -> V_132 = F_38 ;
if ( V_120 != V_69 ) {
V_20 -> V_133 [ 0 ] = F_46 ( V_134 ) | F_46 ( V_135 ) ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ )
F_47 ( V_20 , V_30 + V_7 , - 1 , 1 , 0 , 0 ) ;
} else
V_20 -> V_133 [ 0 ] = F_46 ( V_134 ) | F_46 ( V_136 ) ;
V_1 -> V_68 [ V_120 ] ++ ;
switch ( V_120 ) {
case V_28 :
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ )
F_48 ( V_34 [ V_7 ] , V_20 -> V_137 ) ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
F_47 ( V_20 , V_30 + V_7 , - 127 , 126 , 0 , 2 ) ;
F_47 ( V_20 , V_32 + V_7 , - 1 , 1 , 0 , 0 ) ;
}
V_53 = F_15 ( V_20 , V_40 ) ;
if ( V_53 ) {
F_49 ( L_4 , V_40 ) ;
goto V_138;
}
break;
case V_69 :
F_48 ( V_77 , V_20 -> V_137 ) ;
F_48 ( V_78 , V_20 -> V_137 ) ;
F_48 ( V_79 , V_20 -> V_139 ) ;
F_48 ( V_80 , V_20 -> V_139 ) ;
break;
case V_70 :
for ( V_7 = 4 ; V_7 < 8 ; V_7 ++ )
F_48 ( V_74 [ V_7 ] , V_20 -> V_137 ) ;
case V_73 :
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_48 ( V_74 [ V_7 ] , V_20 -> V_137 ) ;
break;
case V_83 :
F_48 ( V_85 , V_20 -> V_137 ) ;
case V_86 :
F_48 ( V_87 , V_20 -> V_137 ) ;
break;
case V_94 :
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_47 ( V_20 ,
V_109 [ V_7 ] , 4 , 252 , 0 , 2 ) ;
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ )
F_48 ( V_110 [ V_7 ] , V_20 -> V_137 ) ;
break;
case V_95 :
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_48 ( V_108 [ V_7 ] , V_20 -> V_137 ) ;
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ )
F_48 ( V_110 [ V_7 ] , V_20 -> V_137 ) ;
break;
}
V_53 = F_50 ( V_64 -> V_21 ) ;
if ( V_53 )
goto V_138;
return 0 ;
V_138:
F_51 ( V_64 -> V_21 ) ;
V_64 -> V_21 = NULL ;
return V_53 ;
}
static void F_52 ( struct V_4 * V_140 )
{
struct V_1 * V_1 ;
struct V_141 * V_6 ;
int V_7 , V_142 ;
int V_143 = 0 ;
int * V_27 , V_144 ;
struct V_145 V_146 ;
for ( V_142 = 0 ; V_142 < V_147 ; V_142 ++ ) {
if ( V_148 [ V_142 ] . V_149 == 0 || V_148 [ V_142 ] . args [ 0 ] < 0 )
continue;
if ( V_148 [ V_142 ] . args [ 0 ] == V_140 -> V_150 )
break;
}
if ( V_142 == V_147 ) {
F_53 ( L_5 , V_140 -> V_150 ) ;
return;
}
V_27 = V_148 [ V_142 ] . args + 1 ;
V_144 = V_148 [ V_142 ] . V_149 - 1 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 . V_14 = V_151 ;
V_6 = F_54 ( V_140 , L_6 , & V_146 ,
V_142 ) ;
if ( ! V_6 ) {
F_43 ( L_7 ) ;
return;
}
V_1 = F_55 ( sizeof( struct V_1 ) , V_54 ) ;
if ( ! V_1 ) {
F_43 ( L_8 ) ;
goto V_152;
}
F_56 ( & V_1 -> V_118 ) ;
V_1 -> V_6 = V_6 ;
V_1 -> V_153 = V_140 -> V_150 ;
F_57 ( & V_1 -> V_115 , F_31 , ( long ) V_1 ) ;
for ( V_7 = 0 ; V_7 < V_144 && V_7 < V_26 ; V_7 ++ ) {
if ( ! V_27 [ V_7 ] )
continue;
if ( F_42 ( V_1 , V_7 , V_27 [ V_7 ] ) )
goto V_154;
V_143 ++ ;
}
if ( V_143 == 0 ) {
F_43 ( L_9 ) ;
goto V_155;
}
V_156 [ V_142 ] = V_1 ;
return;
V_154:
while ( -- V_7 >= 0 )
if ( V_1 -> V_27 [ V_7 ] . V_21 )
F_58 ( V_1 -> V_27 [ V_7 ] . V_21 ) ;
V_155:
F_19 ( V_1 ) ;
V_152:
F_59 ( V_6 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
int V_7 ;
struct V_1 * V_1 ;
for ( V_7 = 0 ; V_7 < V_147 ; V_7 ++ ) {
if ( V_156 [ V_7 ] && V_156 [ V_7 ] -> V_153 == V_5 -> V_150 )
break;
}
if ( V_7 == V_147 )
return;
V_1 = V_156 [ V_7 ] ;
V_156 [ V_7 ] = NULL ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ )
if ( V_1 -> V_27 [ V_7 ] . V_21 )
F_58 ( V_1 -> V_27 [ V_7 ] . V_21 ) ;
F_59 ( V_1 -> V_6 ) ;
F_19 ( V_1 ) ;
}
static int T_1 F_61 ( void )
{
int V_7 ;
int V_157 = 0 ;
for ( V_7 = 0 ; V_7 < V_147 ; V_7 ++ ) {
if ( V_148 [ V_7 ] . V_149 == 0 || V_148 [ V_7 ] . args [ 0 ] < 0 )
continue;
if ( V_148 [ V_7 ] . V_149 < 2 ) {
F_43 ( L_10 ) ;
return - V_122 ;
}
V_157 = 1 ;
}
if ( ! V_157 )
return - V_158 ;
return F_62 ( & V_159 ) ;
}
static void T_2 F_63 ( void )
{
F_64 ( & V_159 ) ;
}
