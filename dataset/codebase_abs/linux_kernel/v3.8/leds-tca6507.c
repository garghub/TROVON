static inline int F_1 ( int V_1 )
{
return V_1 >> 4 ;
}
static inline int F_2 ( int V_2 )
{
if ( V_2 )
return ( V_2 << 4 ) | 0xf ;
return 0 ;
}
static int F_3 ( int V_3 , int * V_4 , int * V_5 )
{
int V_6 , V_7 ;
int V_8 = V_3 * 9 / 8 ;
int V_9 = V_3 * 7 / 8 ;
int V_10 = 65536 ;
for ( V_6 = 1 ; V_6 < V_11 ; V_6 ++ ) {
int V_12 = V_13 [ V_6 ] ;
if ( V_12 * 2 < V_9 )
continue;
if ( V_12 > V_8 )
break;
for ( V_7 = 0 ; V_7 <= V_6 ; V_7 ++ ) {
int V_14 = V_12 + V_13 [ V_7 ] ;
int V_15 ;
if ( V_14 < V_9 )
continue;
if ( V_14 > V_8 )
break;
V_15 = abs ( V_3 - V_14 ) ;
if ( V_15 >= V_10 )
continue;
* V_4 = V_6 ;
* V_5 = V_7 ;
V_10 = V_15 ;
if ( V_15 == 0 )
return V_3 ;
}
}
if ( V_10 < 65536 ) {
int V_16 ;
if ( V_3 & 1 ) {
V_6 = * V_5 ;
* V_5 = * V_4 ;
* V_4 = V_6 ;
}
V_16 = V_13 [ * V_4 ] + V_13 [ * V_5 ] ;
if ( * V_4 < * V_5 )
return V_16 + 1 ;
else
return V_16 ;
}
return - V_17 ;
}
static void F_4 ( struct V_18 * V_19 , int V_20 , int V_21 )
{
int V_22 = ( 1 << V_20 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 3 ; V_23 ++ ) {
int V_24 = V_19 -> V_25 [ V_23 ] & ~ V_22 ;
if ( V_21 & ( 1 << V_23 ) )
V_24 |= V_22 ;
if ( V_19 -> V_25 [ V_23 ] != V_24 ) {
V_19 -> V_25 [ V_23 ] = V_24 ;
V_19 -> V_26 |= ( 1 << V_23 ) ;
}
}
}
static void F_5 ( struct V_18 * V_19 , int V_27 , int V_28 , int V_29 )
{
int V_22 = 0xF ;
int V_24 ;
if ( V_28 ) {
V_22 <<= 4 ;
V_29 <<= 4 ;
}
V_24 = V_19 -> V_25 [ V_27 ] & ~ V_22 ;
V_24 |= V_29 ;
if ( V_19 -> V_25 [ V_27 ] != V_24 ) {
V_19 -> V_25 [ V_27 ] = V_24 ;
V_19 -> V_26 |= 1 << V_27 ;
}
}
static void F_6 ( struct V_18 * V_19 , int V_28 , int V_2 )
{
switch ( V_28 ) {
case V_30 :
case V_31 :
F_5 ( V_19 , V_32 , V_28 , V_2 ) ;
break;
case V_33 :
F_5 ( V_19 , V_34 , 0 , V_2 ) ;
break;
}
V_19 -> V_28 [ V_28 ] . V_2 = V_2 ;
}
static void F_7 ( struct V_18 * V_19 , int V_28 )
{
int V_6 , V_7 ;
int V_35 ;
V_35 = F_3 ( V_19 -> V_28 [ V_28 ] . V_36 , & V_6 , & V_7 ) ;
F_8 ( & V_19 -> V_37 -> V_38 ,
L_1 , V_6 , V_13 [ V_6 ] ,
V_7 , V_13 [ V_7 ] , V_19 -> V_28 [ V_28 ] . V_36 ) ;
F_5 ( V_19 , V_39 , V_28 , V_7 ) ;
F_5 ( V_19 , V_40 , V_28 , V_6 ) ;
V_19 -> V_28 [ V_28 ] . V_36 = V_35 ;
V_35 = F_3 ( V_19 -> V_28 [ V_28 ] . V_41 , & V_6 , & V_7 ) ;
F_8 ( & V_19 -> V_37 -> V_38 ,
L_2 , V_6 , V_13 [ V_6 ] ,
V_7 , V_13 [ V_7 ] , V_19 -> V_28 [ V_28 ] . V_41 ) ;
F_5 ( V_19 , V_42 , V_28 , V_7 ) ;
F_5 ( V_19 , V_43 , V_28 , V_6 ) ;
F_5 ( V_19 , V_44 , V_28 , V_6 ) ;
V_19 -> V_28 [ V_28 ] . V_41 = V_35 ;
F_5 ( V_19 , V_45 , V_28 , V_46 ) ;
}
static void F_9 ( struct V_47 * V_48 )
{
struct V_18 * V_19 = F_10 ( V_48 , struct V_18 ,
V_48 ) ;
struct V_49 * V_50 = V_19 -> V_37 ;
int V_51 ;
T_1 V_52 [ V_53 ] ;
int V_54 ;
F_11 ( & V_19 -> V_55 ) ;
V_51 = V_19 -> V_26 ;
memcpy ( V_52 , V_19 -> V_25 , V_53 ) ;
V_19 -> V_26 = 0 ;
F_12 ( & V_19 -> V_55 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ )
if ( V_51 & ( 1 << V_54 ) )
F_13 ( V_50 , V_54 , V_52 [ V_54 ] ) ;
}
static void F_14 ( struct V_56 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_57 ;
if ( V_20 -> V_28 >= 0 ) {
struct V_28 * V_58 = V_19 -> V_28 + V_20 -> V_28 ;
if ( V_20 -> V_59 )
V_58 -> V_60 -- ;
V_58 -> V_61 -- ;
}
V_20 -> V_59 = 0 ;
V_20 -> V_28 = - 1 ;
}
static int F_15 ( struct V_56 * V_20 )
{
int V_2 = F_1 ( V_20 -> V_62 . V_1 ) ;
struct V_18 * V_19 = V_20 -> V_57 ;
int V_6 , V_7 ;
int V_63 ;
struct V_28 * V_58 ;
int V_64 = 0 ;
V_20 -> V_62 . V_1 = F_2 ( V_2 ) ;
if ( V_2 == 0 ) {
F_4 ( V_19 , V_20 -> V_65 , V_66 ) ;
return 0 ;
}
if ( V_20 -> V_36 == 0 || V_20 -> V_41 == 0 ) {
int V_67 = - 1 ;
int V_10 = 15 - V_2 ;
if ( V_2 == 15 ) {
F_4 ( V_19 , V_20 -> V_65 , V_68 ) ;
return 0 ;
}
for ( V_63 = V_33 ; V_63 >= V_30 ; V_63 -- ) {
int V_15 ;
if ( V_19 -> V_28 [ V_63 ] . V_2 == V_2 ||
V_19 -> V_28 [ V_63 ] . V_61 == 0 ) {
V_67 = V_63 ;
break;
}
V_15 = abs ( V_2 - V_19 -> V_28 [ V_63 ] . V_2 ) ;
if ( V_15 < V_10 ) {
V_10 = V_15 ;
V_67 = V_63 ;
}
}
if ( V_67 == - 1 ) {
F_4 ( V_19 , V_20 -> V_65 , V_68 ) ;
V_20 -> V_62 . V_1 = V_69 ;
return 0 ;
}
if ( ! V_19 -> V_28 [ V_67 ] . V_61 )
F_6 ( V_19 , V_67 , V_2 ) ;
V_19 -> V_28 [ V_67 ] . V_61 ++ ;
V_20 -> V_28 = V_67 ;
F_4 ( V_19 , V_20 -> V_65 , V_70 [ V_67 ] ) ;
V_20 -> V_62 . V_1 = F_2 ( V_19 -> V_28 [ V_67 ] . V_2 ) ;
return 0 ;
}
if ( F_3 ( V_20 -> V_36 , & V_6 , & V_7 ) < 0 )
return - V_17 ;
if ( F_3 ( V_20 -> V_41 , & V_6 , & V_7 ) < 0 )
return - V_17 ;
for ( V_63 = V_30 ; V_63 <= V_31 ; V_63 ++ ) {
if ( V_19 -> V_28 [ V_63 ] . V_61 == 0 )
break;
if ( V_19 -> V_28 [ V_63 ] . V_2 != V_2 )
continue;
if ( V_19 -> V_28 [ V_63 ] . V_60 == 0 )
break;
if ( ! ( V_19 -> V_28 [ V_63 ] . V_71 ||
V_20 -> V_71 ||
V_19 -> V_28 [ V_63 ] . V_36 == V_20 -> V_36 ) )
continue;
if ( ! ( V_19 -> V_28 [ V_63 ] . V_72 ||
V_20 -> V_72 ||
V_19 -> V_28 [ V_63 ] . V_41 == V_20 -> V_41 ) )
continue;
break;
}
if ( V_63 > V_31 )
return - V_17 ;
V_58 = & V_19 -> V_28 [ V_63 ] ;
if ( V_58 -> V_61 == 0 )
F_6 ( V_19 , V_63 , V_2 ) ;
V_58 -> V_61 ++ ;
V_20 -> V_28 = V_63 ;
if ( V_58 -> V_71 ||
! V_20 -> V_71 ||
V_58 -> V_60 == 0 ) {
V_58 -> V_36 = V_20 -> V_36 ;
V_58 -> V_71 = V_20 -> V_71 ;
V_64 = 1 ;
}
if ( V_58 -> V_72 ||
! V_20 -> V_72 ||
V_58 -> V_60 == 0 ) {
V_58 -> V_41 = V_20 -> V_41 ;
V_58 -> V_72 = V_20 -> V_72 ;
V_64 = 1 ;
}
if ( V_64 )
F_7 ( V_19 , V_63 ) ;
V_20 -> V_36 = V_58 -> V_36 ;
V_20 -> V_41 = V_58 -> V_41 ;
V_58 -> V_60 ++ ;
V_20 -> V_59 = 1 ;
V_20 -> V_62 . V_1 = F_2 ( V_58 -> V_2 ) ;
F_4 ( V_19 , V_20 -> V_65 , V_73 [ V_63 ] ) ;
return 0 ;
}
static int F_16 ( struct V_56 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_57 ;
int V_74 ;
unsigned long V_75 ;
F_17 ( & V_19 -> V_55 , V_75 ) ;
F_14 ( V_20 ) ;
V_74 = F_15 ( V_20 ) ;
if ( V_74 ) {
V_20 -> V_36 = 0 ;
V_20 -> V_41 = 0 ;
F_15 ( V_20 ) ;
}
F_18 ( & V_19 -> V_55 , V_75 ) ;
if ( V_19 -> V_26 )
F_19 ( & V_19 -> V_48 ) ;
return V_74 ;
}
static void F_20 ( struct V_76 * V_62 ,
enum V_77 V_1 )
{
struct V_56 * V_20 = F_10 ( V_62 , struct V_56 ,
V_62 ) ;
V_20 -> V_62 . V_1 = V_1 ;
V_20 -> V_36 = 0 ;
V_20 -> V_41 = 0 ;
F_16 ( V_20 ) ;
}
static int F_21 ( struct V_76 * V_62 ,
unsigned long * V_78 ,
unsigned long * V_79 )
{
struct V_56 * V_20 = F_10 ( V_62 , struct V_56 ,
V_62 ) ;
if ( * V_78 == 0 )
V_20 -> V_71 = 1 ;
else if ( V_78 != & V_62 -> V_80 )
V_20 -> V_71 = 0 ;
V_20 -> V_36 = * V_78 ;
if ( * V_79 == 0 )
V_20 -> V_72 = 1 ;
else if ( V_79 != & V_62 -> V_81 )
V_20 -> V_72 = 0 ;
V_20 -> V_41 = * V_79 ;
if ( V_20 -> V_36 == 0 )
V_20 -> V_36 = 512 ;
if ( V_20 -> V_41 == 0 )
V_20 -> V_41 = 512 ;
if ( V_20 -> V_62 . V_1 == V_82 )
V_20 -> V_62 . V_1 = V_69 ;
if ( F_16 ( V_20 ) < 0 ) {
V_20 -> V_36 = 0 ;
V_20 -> V_41 = 0 ;
V_20 -> V_62 . V_1 = V_82 ;
return - V_17 ;
}
* V_78 = V_20 -> V_36 ;
* V_79 = V_20 -> V_41 ;
return 0 ;
}
static void F_22 ( struct V_83 * V_84 ,
unsigned V_85 , int V_21 )
{
struct V_18 * V_19 = F_10 ( V_84 , struct V_18 , V_86 ) ;
unsigned long V_75 ;
F_17 ( & V_19 -> V_55 , V_75 ) ;
F_4 ( V_19 , V_19 -> V_87 [ V_85 ] ,
V_21 ? V_66 : V_68 ) ;
F_18 ( & V_19 -> V_55 , V_75 ) ;
if ( V_19 -> V_26 )
F_19 ( & V_19 -> V_48 ) ;
}
static int F_23 ( struct V_83 * V_84 ,
unsigned V_85 , int V_21 )
{
F_22 ( V_84 , V_85 , V_21 ) ;
return 0 ;
}
static int F_24 ( struct V_49 * V_37 ,
struct V_18 * V_19 ,
struct V_88 * V_89 )
{
int V_74 ;
int V_63 = 0 ;
int V_90 = 0 ;
for ( V_63 = 0 ; V_63 < V_91 ; V_63 ++ )
if ( V_89 -> V_92 . V_92 [ V_63 ] . V_93 && V_89 -> V_92 . V_92 [ V_63 ] . V_75 ) {
V_19 -> V_94 [ V_90 ] = V_89 -> V_92 . V_92 [ V_63 ] . V_93 ;
V_19 -> V_87 [ V_90 ] = V_63 ;
V_90 ++ ;
}
if ( ! V_90 )
return 0 ;
V_19 -> V_86 . V_95 = L_3 ;
V_19 -> V_86 . V_96 = V_19 -> V_94 ;
V_19 -> V_86 . V_97 = V_90 ;
V_19 -> V_86 . V_98 = V_89 -> V_99 ;
V_19 -> V_86 . V_100 = V_101 ;
V_19 -> V_86 . V_102 = F_23 ;
V_19 -> V_86 . V_51 = F_22 ;
V_19 -> V_86 . V_38 = & V_37 -> V_38 ;
V_74 = F_25 ( & V_19 -> V_86 ) ;
if ( V_74 ) {
V_19 -> V_86 . V_97 = 0 ;
return V_74 ;
}
if ( V_89 -> V_103 )
V_89 -> V_103 ( V_19 -> V_86 . V_98 , V_19 -> V_86 . V_97 ) ;
return 0 ;
}
static void F_26 ( struct V_18 * V_19 )
{
if ( V_19 -> V_86 . V_97 ) {
int V_74 = F_27 ( & V_19 -> V_86 ) ;
F_28 ( & V_19 -> V_37 -> V_38 , L_4 ,
L_5 , V_74 ) ;
}
}
static int F_24 ( struct V_49 * V_37 ,
struct V_18 * V_19 ,
struct V_88 * V_89 )
{
return 0 ;
}
static void F_26 ( struct V_18 * V_19 )
{
}
static int F_29 ( struct V_49 * V_37 ,
const struct V_104 * V_105 )
{
struct V_18 * V_19 ;
struct V_106 * V_107 ;
struct V_88 * V_89 ;
int V_74 ;
int V_63 = 0 ;
V_107 = F_30 ( V_37 -> V_38 . V_108 ) ;
V_89 = V_37 -> V_38 . V_109 ;
if ( ! F_31 ( V_107 , V_110 ) )
return - V_111 ;
if ( ! V_89 || V_89 -> V_92 . V_112 != V_91 ) {
F_28 ( & V_37 -> V_38 , L_6 ,
V_91 ) ;
return - V_113 ;
}
V_19 = F_32 ( & V_37 -> V_38 , sizeof( * V_19 ) , V_114 ) ;
if ( ! V_19 )
return - V_115 ;
V_19 -> V_37 = V_37 ;
F_33 ( & V_19 -> V_48 , F_9 ) ;
F_34 ( & V_19 -> V_55 ) ;
F_35 ( V_37 , V_19 ) ;
for ( V_63 = 0 ; V_63 < V_91 ; V_63 ++ ) {
struct V_56 * V_116 = V_19 -> V_92 + V_63 ;
V_116 -> V_57 = V_19 ;
V_116 -> V_65 = V_63 ;
if ( V_89 -> V_92 . V_92 [ V_63 ] . V_93 && ! V_89 -> V_92 . V_92 [ V_63 ] . V_75 ) {
V_116 -> V_62 . V_93 = V_89 -> V_92 . V_92 [ V_63 ] . V_93 ;
V_116 -> V_62 . V_117
= V_89 -> V_92 . V_92 [ V_63 ] . V_117 ;
V_116 -> V_62 . V_118 = F_20 ;
V_116 -> V_62 . V_119 = F_21 ;
V_116 -> V_28 = - 1 ;
V_74 = F_36 ( & V_37 -> V_38 ,
& V_116 -> V_62 ) ;
if ( V_74 < 0 )
goto exit;
}
}
V_74 = F_24 ( V_37 , V_19 , V_89 ) ;
if ( V_74 )
goto exit;
V_19 -> V_26 = 0x7f ;
F_19 ( & V_19 -> V_48 ) ;
return 0 ;
exit:
while ( V_63 -- ) {
if ( V_19 -> V_92 [ V_63 ] . V_62 . V_93 )
F_37 ( & V_19 -> V_92 [ V_63 ] . V_62 ) ;
}
return V_74 ;
}
static int F_38 ( struct V_49 * V_37 )
{
int V_63 ;
struct V_18 * V_19 = F_39 ( V_37 ) ;
struct V_56 * V_120 = V_19 -> V_92 ;
for ( V_63 = 0 ; V_63 < V_91 ; V_63 ++ ) {
if ( V_120 [ V_63 ] . V_62 . V_93 )
F_37 ( & V_120 [ V_63 ] . V_62 ) ;
}
F_26 ( V_19 ) ;
F_40 ( & V_19 -> V_48 ) ;
return 0 ;
}
