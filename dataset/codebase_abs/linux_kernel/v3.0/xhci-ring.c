T_1 F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
unsigned long V_5 ;
if ( ! V_2 || ! V_4 || V_4 < V_2 -> V_6 )
return 0 ;
V_5 = V_4 - V_2 -> V_6 ;
if ( V_5 > V_7 )
return 0 ;
return V_2 -> V_8 + ( V_5 * sizeof( * V_4 ) ) ;
}
static bool F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_1 * V_2 , union V_3 * V_4 )
{
if ( V_12 == V_10 -> V_13 )
return ( V_4 == & V_2 -> V_6 [ V_7 ] ) &&
( V_2 -> V_14 == V_10 -> V_13 -> V_15 ) ;
else
return F_3 ( V_4 -> V_16 . V_17 ) & V_18 ;
}
static int F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_1 * V_2 , union V_3 * V_4 )
{
if ( V_12 == V_10 -> V_13 )
return V_4 == & V_2 -> V_6 [ V_7 ] ;
else
return ( F_3 ( V_4 -> V_16 . V_17 ) & V_19 )
== F_5 ( V_20 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_21 * V_16 = & V_12 -> V_22 -> V_16 ;
return ( ( F_3 ( V_16 -> V_17 ) & V_19 ) ==
F_5 ( V_20 ) ) ;
}
static void F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_1 * * V_2 ,
union V_3 * * V_4 )
{
if ( F_4 ( V_10 , V_12 , * V_2 , * V_4 ) ) {
* V_2 = ( * V_2 ) -> V_14 ;
* V_4 = ( ( * V_2 ) -> V_6 ) ;
} else {
( * V_4 ) ++ ;
}
}
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_12 , bool V_23 )
{
union V_3 * V_14 = ++ ( V_12 -> V_24 ) ;
unsigned long long V_25 ;
V_12 -> V_26 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_27 , V_14 ) ) {
if ( V_23 && F_2 ( V_10 , V_12 , V_12 -> V_27 , V_14 ) ) {
V_12 -> V_28 = ( V_12 -> V_28 ? 0 : 1 ) ;
if ( ! F_9 () )
F_10 ( V_10 , L_1 ,
V_12 ,
( unsigned int ) V_12 -> V_28 ) ;
}
V_12 -> V_27 = V_12 -> V_27 -> V_14 ;
V_12 -> V_24 = V_12 -> V_27 -> V_6 ;
V_14 = V_12 -> V_24 ;
}
V_25 = ( unsigned long long ) F_1 ( V_12 -> V_27 , V_12 -> V_24 ) ;
}
static void F_11 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_23 , bool V_29 )
{
T_2 V_30 ;
union V_3 * V_14 ;
unsigned long long V_25 ;
V_30 = F_3 ( V_12 -> V_22 -> V_31 . V_32 [ 3 ] ) & V_33 ;
V_14 = ++ ( V_12 -> V_22 ) ;
V_12 -> V_34 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_35 , V_14 ) ) {
if ( ! V_23 ) {
if ( V_12 != V_10 -> V_13 ) {
if ( ! V_30 && ! V_29 )
break;
if ( ! F_12 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_13 ( ~ V_33 ) ;
V_14 -> V_16 . V_17 |=
F_13 ( V_30 ) ;
}
F_14 () ;
V_14 -> V_16 . V_17 ^= F_13 ( V_36 ) ;
}
if ( F_2 ( V_10 , V_12 , V_12 -> V_35 , V_14 ) ) {
V_12 -> V_28 = ( V_12 -> V_28 ? 0 : 1 ) ;
if ( ! F_9 () )
F_10 ( V_10 , L_1 ,
V_12 ,
( unsigned int ) V_12 -> V_28 ) ;
}
}
V_12 -> V_35 = V_12 -> V_35 -> V_14 ;
V_12 -> V_22 = V_12 -> V_35 -> V_6 ;
V_14 = V_12 -> V_22 ;
}
V_25 = ( unsigned long long ) F_1 ( V_12 -> V_35 , V_12 -> V_22 ) ;
}
static int F_15 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_37 )
{
int V_38 ;
union V_3 * V_39 = V_12 -> V_22 ;
struct V_1 * V_35 = V_12 -> V_35 ;
struct V_1 * V_40 ;
unsigned int V_41 ;
while ( F_4 ( V_10 , V_12 , V_35 , V_39 ) ) {
V_35 = V_35 -> V_14 ;
V_39 = V_35 -> V_6 ;
}
if ( V_39 == V_12 -> V_24 ) {
V_41 = V_7 - 1 ;
for ( V_40 = V_35 -> V_14 ; V_40 != V_35 ;
V_40 = V_40 -> V_14 )
V_41 += V_7 - 1 ;
V_41 -= 1 ;
if ( V_37 > V_41 ) {
F_16 ( V_10 , L_2
L_3 ,
V_37 , V_41 ) ;
return 0 ;
}
return 1 ;
}
for ( V_38 = 0 ; V_38 <= V_37 ; ++ V_38 ) {
if ( V_39 == V_12 -> V_24 )
return 0 ;
V_39 ++ ;
while ( F_4 ( V_10 , V_12 , V_35 , V_39 ) ) {
V_35 = V_35 -> V_14 ;
V_39 = V_35 -> V_6 ;
}
}
return 1 ;
}
void F_17 ( struct V_9 * V_10 )
{
F_10 ( V_10 , L_4 ) ;
F_18 ( V_10 , V_42 , & V_10 -> V_43 -> V_44 [ 0 ] ) ;
F_19 ( V_10 , & V_10 -> V_43 -> V_44 [ 0 ] ) ;
}
void F_20 ( struct V_9 * V_10 ,
unsigned int V_45 ,
unsigned int V_46 ,
unsigned int V_47 )
{
T_3 T_4 * V_48 = & V_10 -> V_43 -> V_44 [ V_45 ] ;
struct V_49 * V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
unsigned int V_53 = V_50 -> V_53 ;
if ( ( V_53 & V_54 ) || ( V_53 & V_55 ) ||
( V_53 & V_56 ) )
return;
F_18 ( V_10 , F_21 ( V_46 , V_47 ) , V_48 ) ;
}
static void F_22 ( struct V_9 * V_10 ,
unsigned int V_45 ,
unsigned int V_46 )
{
unsigned int V_47 ;
struct V_49 * V_50 ;
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( ! ( V_50 -> V_53 & V_57 ) ) {
if ( ! ( F_23 ( & V_50 -> V_12 -> V_58 ) ) )
F_20 ( V_10 , V_45 , V_46 , 0 ) ;
return;
}
for ( V_47 = 1 ; V_47 < V_50 -> V_59 -> V_60 ;
V_47 ++ ) {
struct V_61 * V_59 = V_50 -> V_59 ;
if ( ! F_23 ( & V_59 -> V_62 [ V_47 ] -> V_58 ) )
F_20 ( V_10 , V_45 , V_46 ,
V_47 ) ;
}
}
static struct V_1 * F_24 (
struct V_1 * V_63 ,
union V_3 * V_4 , int * V_28 )
{
struct V_1 * V_40 = V_63 ;
struct V_64 * V_65 ;
while ( V_40 -> V_6 > V_4 ||
& V_40 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_65 = & V_40 -> V_6 [ V_7 - 1 ] . V_31 ;
if ( F_3 ( V_65 -> V_32 [ 3 ] ) & V_18 )
* V_28 ^= 0x1 ;
V_40 = V_40 -> V_14 ;
if ( V_40 == V_63 )
return NULL ;
}
return V_40 ;
}
static struct V_11 * F_25 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 )
{
struct V_49 * V_50 ;
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( ! ( V_50 -> V_53 & V_57 ) )
return V_50 -> V_12 ;
if ( V_47 == 0 ) {
F_16 ( V_10 ,
L_5
L_6 ,
V_45 , V_46 ) ;
return NULL ;
}
if ( V_47 < V_50 -> V_59 -> V_60 )
return V_50 -> V_59 -> V_62 [ V_47 ] ;
F_16 ( V_10 ,
L_7
L_8
L_9 ,
V_45 , V_46 ,
V_50 -> V_59 -> V_60 - 1 ,
V_47 ) ;
return NULL ;
}
static struct V_11 * F_26 ( struct V_9 * V_10 ,
struct V_66 * V_66 )
{
return F_25 ( V_10 , V_66 -> V_67 -> V_45 ,
F_27 ( & V_66 -> V_50 -> V_68 ) , V_66 -> V_47 ) ;
}
void F_28 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 , struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_67 = V_10 -> V_51 [ V_45 ] ;
struct V_11 * V_74 ;
struct V_64 * V_4 ;
struct V_75 * V_76 ;
T_1 V_25 ;
V_74 = F_25 ( V_10 , V_45 ,
V_46 , V_47 ) ;
if ( ! V_74 ) {
F_16 ( V_10 , L_10
L_11 ,
V_47 ) ;
return;
}
V_72 -> V_77 = 0 ;
F_10 ( V_10 , L_12 ) ;
V_72 -> V_78 = F_24 ( V_70 -> V_63 ,
V_67 -> V_52 [ V_46 ] . V_79 ,
& V_72 -> V_77 ) ;
if ( ! V_72 -> V_78 ) {
F_29 ( 1 ) ;
return;
}
F_10 ( V_10 , L_13 ) ;
V_76 = F_30 ( V_10 , V_67 -> V_80 , V_46 ) ;
V_72 -> V_77 = 0x1 & F_31 ( V_76 -> V_81 ) ;
V_72 -> V_82 = V_70 -> F_4 ;
F_10 ( V_10 , L_14 ) ;
V_72 -> V_78 = F_24 ( V_72 -> V_78 ,
V_72 -> V_82 ,
& V_72 -> V_77 ) ;
if ( ! V_72 -> V_78 ) {
F_29 ( 1 ) ;
return;
}
V_4 = & V_72 -> V_82 -> V_31 ;
if ( ( F_3 ( V_4 -> V_32 [ 3 ] ) & V_19 ) ==
F_5 ( V_20 ) && ( F_3 ( V_4 -> V_32 [ 3 ] ) & V_18 ) )
V_72 -> V_77 ^= 0x1 ;
F_7 ( V_10 , V_74 , & V_72 -> V_78 , & V_72 -> V_82 ) ;
if ( V_74 -> V_15 == V_74 -> V_15 -> V_14 &&
V_72 -> V_82 < V_67 -> V_52 [ V_46 ] . V_79 )
V_72 -> V_77 ^= 0x1 ;
F_10 ( V_10 , L_15 , V_72 -> V_77 ) ;
F_10 ( V_10 , L_16 ,
V_72 -> V_78 ) ;
V_25 = F_1 ( V_72 -> V_78 , V_72 -> V_82 ) ;
F_10 ( V_10 , L_17 ,
( unsigned long long ) V_25 ) ;
}
static void F_32 ( struct V_9 * V_10 , struct V_11 * V_74 ,
struct V_69 * V_70 )
{
struct V_1 * V_40 ;
union V_3 * V_83 ;
for ( V_40 = V_70 -> V_63 , V_83 = V_70 -> V_84 ;
true ;
F_7 ( V_10 , V_74 , & V_40 , & V_83 ) ) {
if ( ( F_3 ( V_83 -> V_31 . V_32 [ 3 ] ) & V_19 )
== F_5 ( V_20 ) ) {
V_83 -> V_31 . V_32 [ 3 ] &= F_13 ( ~ V_33 ) ;
F_10 ( V_10 , L_18 ) ;
F_10 ( V_10 , L_19
L_20 ,
V_83 ,
( unsigned long long ) F_1 ( V_40 , V_83 ) ,
V_40 ,
( unsigned long long ) V_40 -> V_8 ) ;
} else {
V_83 -> V_31 . V_32 [ 0 ] = 0 ;
V_83 -> V_31 . V_32 [ 1 ] = 0 ;
V_83 -> V_31 . V_32 [ 2 ] = 0 ;
V_83 -> V_31 . V_32 [ 3 ] &= F_13 ( V_36 ) ;
V_83 -> V_31 . V_32 [ 3 ] |= F_13 (
F_5 ( V_85 ) ) ;
F_10 ( V_10 , L_21
L_20 ,
V_83 ,
( unsigned long long ) F_1 ( V_40 , V_83 ) ,
V_40 ,
( unsigned long long ) V_40 -> V_8 ) ;
}
if ( V_83 == V_70 -> F_4 )
break;
}
}
void F_33 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 ,
struct V_71 * V_86 )
{
struct V_49 * V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
F_10 ( V_10 , L_22
L_23 ,
V_86 -> V_78 ,
( unsigned long long ) V_86 -> V_78 -> V_8 ,
V_86 -> V_82 ,
( unsigned long long ) F_1 ( V_86 -> V_78 , V_86 -> V_82 ) ,
V_86 -> V_77 ) ;
F_34 ( V_10 , V_45 , V_46 , V_47 ,
V_86 -> V_78 ,
V_86 -> V_82 ,
( T_2 ) V_86 -> V_77 ) ;
V_50 -> V_53 |= V_55 ;
}
static void F_35 ( struct V_9 * V_10 ,
struct V_49 * V_50 )
{
V_50 -> V_53 &= ~ V_54 ;
if ( F_36 ( & V_50 -> V_87 ) )
V_50 -> V_88 -- ;
}
static void F_37 ( struct V_9 * V_10 ,
struct V_69 * V_70 , int V_89 , char * V_90 )
{
struct V_91 * V_92 ;
struct V_66 * V_66 ;
struct V_93 * V_93 ;
V_66 = V_70 -> V_66 ;
V_93 = V_66 -> V_94 ;
V_93 -> V_95 ++ ;
V_92 = F_38 ( V_66 -> V_67 -> V_96 ) ;
if ( V_93 -> V_95 == V_93 -> V_97 ) {
if ( F_39 ( V_66 -> V_98 ) == V_99 ) {
F_40 ( V_10 ) -> V_100 . V_101 -- ;
if ( F_40 ( V_10 ) -> V_100 . V_101 == 0 ) {
if ( V_10 -> V_102 & V_103 )
F_41 () ;
}
}
F_42 ( V_92 , V_66 ) ;
F_43 ( & V_10 -> V_104 ) ;
F_44 ( V_92 , V_66 , V_89 ) ;
F_45 ( V_10 , V_93 ) ;
F_46 ( & V_10 -> V_104 ) ;
}
}
static void F_47 ( struct V_9 * V_10 ,
union V_3 * V_4 , struct V_105 * V_106 )
{
unsigned int V_45 ;
unsigned int V_46 ;
struct V_73 * V_107 ;
struct V_11 * V_74 ;
struct V_49 * V_50 ;
struct V_108 * V_109 ;
struct V_69 * V_70 = NULL ;
struct V_69 * V_110 ;
struct V_71 V_86 ;
if ( F_48 ( F_49 (
F_3 ( V_10 -> V_111 -> V_24 -> V_31 . V_32 [ 3 ] ) ) ) ) {
V_45 = F_50 (
F_3 ( V_10 -> V_111 -> V_24 -> V_31 . V_32 [ 3 ] ) ) ;
V_107 = V_10 -> V_51 [ V_45 ] ;
if ( V_107 )
F_51 ( V_10 , V_107 ,
V_106 ) ;
else
F_16 ( V_10 , L_24
L_25 ,
V_45 ) ;
return;
}
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_45 = F_50 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_46 = F_52 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( F_23 ( & V_50 -> V_112 ) ) {
F_35 ( V_10 , V_50 ) ;
V_50 -> V_113 = NULL ;
V_50 -> V_79 = NULL ;
F_22 ( V_10 , V_45 , V_46 ) ;
return;
}
F_53 (entry, &ep->cancelled_td_list) {
V_70 = F_54 ( V_109 , struct V_69 , V_112 ) ;
F_10 ( V_10 , L_26 ,
V_70 -> V_84 ,
( unsigned long long ) F_1 ( V_70 -> V_63 , V_70 -> V_84 ) ) ;
V_74 = F_26 ( V_10 , V_70 -> V_66 ) ;
if ( ! V_74 ) {
F_16 ( V_10 , L_27
L_28 ,
V_70 -> V_66 ,
V_70 -> V_66 -> V_47 ) ;
goto V_114;
}
if ( V_70 == V_50 -> V_113 )
F_28 ( V_10 , V_45 , V_46 ,
V_70 -> V_66 -> V_47 ,
V_70 , & V_86 ) ;
else
F_32 ( V_10 , V_74 , V_70 ) ;
V_114:
F_55 ( & V_70 -> V_58 ) ;
}
V_110 = V_70 ;
F_35 ( V_10 , V_50 ) ;
if ( V_86 . V_82 && V_86 . V_78 ) {
F_33 ( V_10 ,
V_45 , V_46 ,
V_50 -> V_113 -> V_66 -> V_47 ,
& V_86 ) ;
F_17 ( V_10 ) ;
} else {
F_22 ( V_10 , V_45 , V_46 ) ;
}
V_50 -> V_113 = NULL ;
V_50 -> V_79 = NULL ;
do {
V_70 = F_54 ( V_50 -> V_112 . V_14 ,
struct V_69 , V_112 ) ;
F_55 ( & V_70 -> V_112 ) ;
F_37 ( V_10 , V_70 , 0 , L_29 ) ;
if ( V_10 -> V_115 & V_116 )
return;
} while ( V_70 != V_110 );
}
void F_56 ( unsigned long V_117 )
{
struct V_9 * V_10 ;
struct V_49 * V_50 ;
struct V_49 * V_118 ;
struct V_11 * V_12 ;
struct V_69 * V_70 ;
int V_119 , V_38 , V_120 ;
V_50 = (struct V_49 * ) V_117 ;
V_10 = V_50 -> V_10 ;
F_46 ( & V_10 -> V_104 ) ;
V_50 -> V_88 -- ;
if ( V_10 -> V_115 & V_116 ) {
F_10 ( V_10 , L_30
L_31 ) ;
F_43 ( & V_10 -> V_104 ) ;
return;
}
if ( ! ( V_50 -> V_88 == 0 && ( V_50 -> V_53 & V_54 ) ) ) {
F_10 ( V_10 , L_32
L_33 ) ;
F_43 ( & V_10 -> V_104 ) ;
return;
}
F_16 ( V_10 , L_34 ) ;
F_16 ( V_10 , L_35 ) ;
V_10 -> V_115 |= V_116 ;
F_57 ( V_10 ) ;
F_43 ( & V_10 -> V_104 ) ;
V_119 = F_58 ( V_10 ) ;
F_46 ( & V_10 -> V_104 ) ;
if ( V_119 < 0 ) {
F_16 ( V_10 , L_36 ) ;
F_16 ( V_10 , L_37 ) ;
}
for ( V_38 = 0 ; V_38 < V_121 ; V_38 ++ ) {
if ( ! V_10 -> V_51 [ V_38 ] )
continue;
for ( V_120 = 0 ; V_120 < 31 ; V_120 ++ ) {
V_118 = & V_10 -> V_51 [ V_38 ] -> V_52 [ V_120 ] ;
V_12 = V_118 -> V_12 ;
if ( ! V_12 )
continue;
F_10 ( V_10 , L_38
L_39 , V_38 , V_120 ) ;
while ( ! F_23 ( & V_12 -> V_58 ) ) {
V_70 = F_59 ( & V_12 -> V_58 ,
struct V_69 ,
V_58 ) ;
F_55 ( & V_70 -> V_58 ) ;
if ( ! F_23 ( & V_70 -> V_112 ) )
F_55 ( & V_70 -> V_112 ) ;
F_37 ( V_10 , V_70 ,
- V_122 , L_40 ) ;
}
while ( ! F_23 ( & V_118 -> V_112 ) ) {
V_70 = F_59 (
& V_118 -> V_112 ,
struct V_69 ,
V_112 ) ;
F_55 ( & V_70 -> V_112 ) ;
F_37 ( V_10 , V_70 ,
- V_122 , L_40 ) ;
}
}
}
F_43 ( & V_10 -> V_104 ) ;
F_10 ( V_10 , L_41 ) ;
F_60 ( F_40 ( V_10 ) -> V_123 ) ;
F_10 ( V_10 , L_42 ) ;
}
static void F_61 ( struct V_9 * V_10 ,
struct V_105 * V_106 ,
union V_3 * V_4 )
{
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
struct V_11 * V_74 ;
struct V_73 * V_67 ;
struct V_75 * V_76 ;
struct V_124 * V_125 ;
V_45 = F_50 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_46 = F_52 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_47 = F_62 ( F_3 ( V_4 -> V_31 . V_32 [ 2 ] ) ) ;
V_67 = V_10 -> V_51 [ V_45 ] ;
V_74 = F_63 ( V_67 , V_46 , V_47 ) ;
if ( ! V_74 ) {
F_16 ( V_10 , L_43
L_44 ,
V_47 ) ;
V_67 -> V_52 [ V_46 ] . V_53 &= ~ V_55 ;
return;
}
V_76 = F_30 ( V_10 , V_67 -> V_80 , V_46 ) ;
V_125 = F_64 ( V_10 , V_67 -> V_80 ) ;
if ( F_65 ( F_3 ( V_106 -> V_89 ) ) != V_126 ) {
unsigned int V_53 ;
unsigned int V_127 ;
switch ( F_65 ( F_3 ( V_106 -> V_89 ) ) ) {
case V_128 :
F_16 ( V_10 , L_45
L_46 ) ;
break;
case V_129 :
F_16 ( V_10 , L_47
L_48 ) ;
V_53 = F_3 ( V_76 -> V_130 ) ;
V_53 &= V_131 ;
V_127 = F_3 ( V_125 -> V_132 ) ;
V_127 = F_66 ( V_127 ) ;
F_10 ( V_10 , L_49 ,
V_127 , V_53 ) ;
break;
case V_133 :
F_16 ( V_10 , L_50
L_51 , V_45 ) ;
break;
default:
F_16 ( V_10 , L_52
L_53 ,
F_65 ( F_3 ( V_106 -> V_89 ) ) ) ;
break;
}
} else {
F_10 ( V_10 , L_54 ,
F_31 ( V_76 -> V_81 ) ) ;
if ( F_1 ( V_67 -> V_52 [ V_46 ] . V_134 ,
V_67 -> V_52 [ V_46 ] . V_135 ) ==
( F_31 ( V_76 -> V_81 ) & ~ ( V_136 ) ) ) {
V_74 -> V_27 = V_67 -> V_52 [ V_46 ] . V_134 ;
V_74 -> V_24 = V_67 -> V_52 [ V_46 ] . V_135 ;
} else {
F_16 ( V_10 , L_55
L_56 ) ;
F_16 ( V_10 , L_57 ,
V_67 -> V_52 [ V_46 ] . V_134 ,
V_67 -> V_52 [ V_46 ] . V_135 ) ;
}
}
V_67 -> V_52 [ V_46 ] . V_53 &= ~ V_55 ;
V_67 -> V_52 [ V_46 ] . V_134 = NULL ;
V_67 -> V_52 [ V_46 ] . V_135 = NULL ;
F_22 ( V_10 , V_45 , V_46 ) ;
}
static void F_67 ( struct V_9 * V_10 ,
struct V_105 * V_106 ,
union V_3 * V_4 )
{
int V_45 ;
unsigned int V_46 ;
V_45 = F_50 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_46 = F_52 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
F_10 ( V_10 , L_58 ,
( unsigned int ) F_65 ( F_3 ( V_106 -> V_89 ) ) ) ;
if ( V_10 -> V_102 & V_137 ) {
F_10 ( V_10 , L_59 ) ;
F_68 ( V_10 ,
V_10 -> V_51 [ V_45 ] -> V_138 -> V_8 , V_45 ,
false ) ;
F_17 ( V_10 ) ;
} else {
V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_53 &= ~ V_56 ;
F_22 ( V_10 , V_45 , V_46 ) ;
}
}
static int F_51 ( struct V_9 * V_10 ,
struct V_73 * V_107 ,
struct V_105 * V_106 )
{
struct V_139 * V_140 ;
if ( F_23 ( & V_107 -> V_141 ) )
return 0 ;
V_140 = F_54 ( V_107 -> V_141 . V_14 ,
struct V_139 , V_141 ) ;
if ( V_10 -> V_111 -> V_24 != V_140 -> V_142 )
return 0 ;
V_140 -> V_89 = F_65 ( F_3 ( V_106 -> V_89 ) ) ;
F_55 ( & V_140 -> V_141 ) ;
if ( V_140 -> V_143 )
F_69 ( V_140 -> V_143 ) ;
else
F_70 ( V_10 , V_140 ) ;
return 1 ;
}
static void F_71 ( struct V_9 * V_10 ,
struct V_105 * V_106 )
{
int V_45 = F_50 ( F_3 ( V_106 -> V_144 ) ) ;
T_5 V_145 ;
T_1 V_146 ;
struct V_147 * V_148 ;
struct V_73 * V_107 ;
unsigned int V_46 ;
struct V_11 * V_74 ;
unsigned int V_53 ;
V_145 = F_31 ( V_106 -> V_149 ) ;
V_146 = F_1 ( V_10 -> V_111 -> V_27 ,
V_10 -> V_111 -> V_24 ) ;
if ( V_146 == 0 ) {
V_10 -> V_150 |= 1 << 4 ;
return;
}
if ( V_145 != ( T_5 ) V_146 ) {
V_10 -> V_150 |= 1 << 5 ;
return;
}
switch ( F_3 ( V_10 -> V_111 -> V_24 -> V_31 . V_32 [ 3 ] )
& V_19 ) {
case F_5 ( V_151 ) :
if ( F_65 ( F_3 ( V_106 -> V_89 ) ) == V_126 )
V_10 -> V_45 = V_45 ;
else
V_10 -> V_45 = 0 ;
F_69 ( & V_10 -> V_152 ) ;
break;
case F_5 ( V_153 ) :
if ( V_10 -> V_51 [ V_45 ] ) {
if ( V_10 -> V_102 & V_154 )
F_72 ( V_10 ,
V_10 -> V_51 [ V_45 ] , true ) ;
F_73 ( V_10 , V_45 ) ;
}
break;
case F_5 ( V_155 ) :
V_107 = V_10 -> V_51 [ V_45 ] ;
if ( F_51 ( V_10 , V_107 , V_106 ) )
break;
V_148 = F_74 ( V_10 ,
V_107 -> V_138 ) ;
V_46 = F_75 ( F_3 ( V_148 -> V_156 ) ) - 1 ;
if ( V_10 -> V_102 & V_137 &&
V_46 != ( unsigned int ) - 1 &&
F_3 ( V_148 -> V_156 ) - V_157 ==
F_3 ( V_148 -> V_158 ) ) {
V_74 = V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_12 ;
V_53 = V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_53 ;
if ( ! ( V_53 & V_56 ) )
goto V_159;
F_10 ( V_10 , L_60
L_61 ,
V_46 , V_53 ) ;
V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_53 &=
~ V_56 ;
F_22 ( V_10 , V_45 , V_46 ) ;
break;
}
V_159:
F_10 ( V_10 , L_62 ) ;
V_10 -> V_51 [ V_45 ] -> V_160 =
F_65 ( F_3 ( V_106 -> V_89 ) ) ;
F_69 ( & V_10 -> V_51 [ V_45 ] -> V_161 ) ;
break;
case F_5 ( V_162 ) :
V_107 = V_10 -> V_51 [ V_45 ] ;
if ( F_51 ( V_10 , V_107 , V_106 ) )
break;
V_10 -> V_51 [ V_45 ] -> V_160 = F_65 ( F_3 ( V_106 -> V_89 ) ) ;
F_69 ( & V_10 -> V_51 [ V_45 ] -> V_161 ) ;
break;
case F_5 ( V_163 ) :
V_10 -> V_51 [ V_45 ] -> V_160 = F_65 ( F_3 ( V_106 -> V_89 ) ) ;
F_69 ( & V_10 -> V_152 ) ;
break;
case F_5 ( V_164 ) :
F_47 ( V_10 , V_10 -> V_111 -> V_24 , V_106 ) ;
break;
case F_5 ( V_165 ) :
F_61 ( V_10 , V_106 , V_10 -> V_111 -> V_24 ) ;
break;
case F_5 ( V_166 ) :
break;
case F_5 ( V_167 ) :
F_67 ( V_10 , V_106 , V_10 -> V_111 -> V_24 ) ;
break;
case F_5 ( V_168 ) :
F_10 ( V_10 , L_63 ) ;
V_45 = F_50 (
F_3 ( V_10 -> V_111 -> V_24 -> V_31 . V_32 [ 3 ] ) ) ;
V_107 = V_10 -> V_51 [ V_45 ] ;
if ( V_107 )
F_51 ( V_10 , V_107 , V_106 ) ;
else
F_16 ( V_10 , L_64
L_65 , V_45 ) ;
break;
case F_5 ( V_169 ) :
if ( ! ( V_10 -> V_102 & V_170 ) ) {
V_10 -> V_150 |= 1 << 6 ;
break;
}
F_10 ( V_10 , L_66 ,
F_76 ( F_3 ( V_106 -> V_89 ) ) ,
F_77 ( F_3 ( V_106 -> V_89 ) ) ) ;
break;
default:
V_10 -> V_150 |= 1 << 6 ;
break;
}
F_8 ( V_10 , V_10 -> V_111 , false ) ;
}
static void F_78 ( struct V_9 * V_10 ,
union V_3 * V_106 )
{
T_2 V_171 ;
V_171 = F_79 ( F_3 ( V_106 -> V_31 . V_32 [ 3 ] ) ) ;
F_10 ( V_10 , L_67 , V_171 ) ;
if ( V_171 == V_172 && ( V_10 -> V_102 & V_170 ) )
F_71 ( V_10 , & V_106 -> V_173 ) ;
}
static unsigned int F_80 ( struct V_91 * V_92 ,
struct V_9 * V_10 , T_2 V_174 )
{
unsigned int V_38 ;
unsigned int V_175 = 0 ;
for ( V_38 = 0 ; V_38 < ( V_174 - 1 ) ; V_38 ++ ) {
T_6 V_176 = V_10 -> V_177 [ V_38 ] ;
if ( V_176 == 0 || V_176 == V_178 )
continue;
if ( ( V_176 == 0x03 ) == ( V_92 -> V_179 == V_180 ) )
V_175 ++ ;
}
return V_175 ;
}
static void F_81 ( struct V_9 * V_10 ,
union V_3 * V_106 )
{
struct V_91 * V_92 ;
T_2 V_174 ;
T_2 V_181 , V_182 ;
int V_183 ;
int V_45 ;
unsigned int V_184 ;
T_6 V_185 ;
struct V_186 * V_187 ;
T_3 T_4 * * V_177 ;
bool V_188 = false ;
if ( F_65 ( F_3 ( V_106 -> V_31 . V_32 [ 2 ] ) ) != V_126 ) {
F_16 ( V_10 , L_68 ) ;
V_10 -> V_150 |= 1 << 8 ;
}
V_174 = F_82 ( F_3 ( V_106 -> V_31 . V_32 [ 0 ] ) ) ;
F_10 ( V_10 , L_69 , V_174 ) ;
V_183 = F_83 ( V_10 -> V_189 ) ;
if ( ( V_174 <= 0 ) || ( V_174 > V_183 ) ) {
F_16 ( V_10 , L_70 , V_174 ) ;
V_188 = true ;
goto V_190;
}
V_185 = V_10 -> V_177 [ V_174 - 1 ] ;
if ( V_185 == 0 ) {
F_16 ( V_10 , L_71
L_72 ,
V_174 ) ;
V_188 = true ;
goto V_190;
}
if ( V_185 == V_178 ) {
F_16 ( V_10 , L_73
L_72 ,
V_174 ) ;
V_188 = true ;
goto V_190;
}
V_92 = F_40 ( V_10 ) ;
if ( ( V_185 == 0x03 ) != ( V_92 -> V_179 == V_180 ) )
V_92 = V_10 -> V_191 ;
V_187 = & V_10 -> V_187 [ F_84 ( V_92 ) ] ;
if ( V_92 -> V_179 == V_180 )
V_177 = V_10 -> V_192 ;
else
V_177 = V_10 -> V_193 ;
V_184 = F_80 ( V_92 , V_10 ,
V_174 ) ;
V_181 = F_19 ( V_10 , V_177 [ V_184 ] ) ;
if ( V_92 -> V_72 == V_194 ) {
F_10 ( V_10 , L_74 ) ;
F_85 ( V_92 ) ;
}
if ( ( V_181 & V_195 ) && ( V_181 & V_196 ) == V_197 ) {
F_10 ( V_10 , L_75 , V_174 ) ;
V_182 = F_19 ( V_10 , & V_10 -> V_198 -> V_140 ) ;
if ( ! ( V_182 & V_199 ) ) {
F_16 ( V_10 , L_76 ) ;
goto V_190;
}
if ( F_86 ( V_181 ) ) {
F_10 ( V_10 , L_77 , V_174 ) ;
V_181 = F_87 ( V_181 ) ;
V_181 &= ~ V_196 ;
V_181 |= V_200 | V_201 ;
F_18 ( V_10 , V_181 , V_177 [ V_184 ] ) ;
V_45 = F_88 ( V_92 , V_10 ,
V_184 ) ;
if ( ! V_45 ) {
F_10 ( V_10 , L_78 ) ;
goto V_190;
}
F_89 ( V_10 , V_45 ) ;
F_10 ( V_10 , L_79 , V_174 ) ;
V_181 = F_19 ( V_10 , V_177 [ V_184 ] ) ;
V_181 = F_87 ( V_181 ) ;
V_181 |= V_195 ;
F_18 ( V_10 , V_181 , V_177 [ V_184 ] ) ;
} else {
F_10 ( V_10 , L_80 , V_174 ) ;
V_187 -> V_202 [ V_184 ] = V_203 +
F_90 ( 20 ) ;
F_91 ( & V_92 -> V_204 ,
V_187 -> V_202 [ V_184 ] ) ;
}
}
V_190:
F_8 ( V_10 , V_10 -> V_13 , true ) ;
if ( V_188 )
return;
F_43 ( & V_10 -> V_104 ) ;
F_92 ( V_92 ) ;
F_46 ( & V_10 -> V_104 ) ;
}
struct V_1 * F_93 ( struct V_1 * V_63 ,
union V_3 * V_205 ,
union V_3 * V_206 ,
T_1 V_207 )
{
T_1 V_208 ;
T_1 V_209 ;
T_1 V_210 ;
struct V_1 * V_40 ;
V_208 = F_1 ( V_63 , V_205 ) ;
V_40 = V_63 ;
do {
if ( V_208 == 0 )
return NULL ;
V_209 = F_1 ( V_40 ,
& V_40 -> V_6 [ V_7 - 1 ] ) ;
V_210 = F_1 ( V_40 , V_206 ) ;
if ( V_210 > 0 ) {
if ( V_208 <= V_210 ) {
if ( V_207 >= V_208 && V_207 <= V_210 )
return V_40 ;
} else {
if ( ( V_207 >= V_208 &&
V_207 <= V_209 ) ||
( V_207 >= V_40 -> V_8 &&
V_207 <= V_210 ) )
return V_40 ;
}
return NULL ;
} else {
if ( V_207 >= V_208 && V_207 <= V_209 )
return V_40 ;
}
V_40 = V_40 -> V_14 ;
V_208 = F_1 ( V_40 , & V_40 -> V_6 [ 0 ] ) ;
} while ( V_40 != V_63 );
return NULL ;
}
static void F_94 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 ,
struct V_69 * V_211 , union V_3 * V_212 )
{
struct V_49 * V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
V_50 -> V_53 |= V_56 ;
V_50 -> V_113 = V_211 ;
V_50 -> V_79 = V_212 ;
V_50 -> V_213 = V_47 ;
F_95 ( V_10 , V_45 , V_46 ) ;
F_96 ( V_10 , V_211 -> V_66 -> V_67 , V_46 ) ;
V_50 -> V_113 = NULL ;
V_50 -> V_79 = NULL ;
V_50 -> V_213 = 0 ;
F_17 ( V_10 ) ;
}
static int F_97 ( struct V_9 * V_10 ,
struct V_75 * V_76 ,
unsigned int V_214 )
{
if ( V_214 == V_215 ||
V_214 == V_216 ||
V_214 == V_217 )
if ( ( F_3 ( V_76 -> V_130 ) & V_131 ) == V_218 )
return 1 ;
return 0 ;
}
int F_98 ( struct V_9 * V_10 , unsigned int V_214 )
{
if ( V_214 >= 224 && V_214 <= 255 ) {
F_10 ( V_10 , L_81 ,
V_214 ) ;
F_10 ( V_10 , L_82 ) ;
return 1 ;
}
return 0 ;
}
static int F_99 ( struct V_9 * V_10 , struct V_69 * V_211 ,
union V_3 * V_212 , struct V_219 * V_106 ,
struct V_49 * V_50 , int * V_89 , bool V_220 )
{
struct V_73 * V_221 ;
struct V_11 * V_74 ;
unsigned int V_45 ;
int V_46 ;
struct V_66 * V_66 = NULL ;
struct V_75 * V_76 ;
int V_119 = 0 ;
struct V_93 * V_93 ;
T_2 V_214 ;
V_45 = F_50 ( F_3 ( V_106 -> V_144 ) ) ;
V_221 = V_10 -> V_51 [ V_45 ] ;
V_46 = F_100 ( F_3 ( V_106 -> V_144 ) ) - 1 ;
V_74 = F_101 ( V_50 , F_31 ( V_106 -> V_222 ) ) ;
V_76 = F_30 ( V_10 , V_221 -> V_80 , V_46 ) ;
V_214 = F_65 ( F_3 ( V_106 -> V_223 ) ) ;
if ( V_220 )
goto V_224;
if ( V_214 == V_225 ||
V_214 == V_226 ) {
V_50 -> V_113 = V_211 ;
V_50 -> V_79 = V_212 ;
return 0 ;
} else {
if ( V_214 == V_227 ) {
V_50 -> V_113 = V_211 ;
V_50 -> V_79 = V_212 ;
V_50 -> V_213 = V_74 -> V_47 ;
} else if ( F_97 ( V_10 ,
V_76 , V_214 ) ) {
F_94 ( V_10 ,
V_45 , V_46 , V_74 -> V_47 ,
V_211 , V_212 ) ;
} else {
while ( V_74 -> V_24 != V_211 -> F_4 )
F_8 ( V_10 , V_74 , false ) ;
F_8 ( V_10 , V_74 , false ) ;
}
V_224:
V_66 = V_211 -> V_66 ;
V_93 = V_66 -> V_94 ;
if ( V_66 -> V_228 > V_66 -> V_229 ) {
F_16 ( V_10 , L_83
L_84
L_85 ,
V_66 -> V_229 ,
V_66 -> V_228 ) ;
V_66 -> V_228 = 0 ;
if ( V_211 -> V_66 -> V_230 & V_231 )
* V_89 = - V_232 ;
else
* V_89 = 0 ;
}
F_55 ( & V_211 -> V_58 ) ;
if ( ! F_23 ( & V_211 -> V_112 ) )
F_55 ( & V_211 -> V_112 ) ;
V_93 -> V_95 ++ ;
if ( V_93 -> V_95 == V_93 -> V_97 ) {
V_119 = 1 ;
if ( F_39 ( V_66 -> V_98 ) == V_99 ) {
F_40 ( V_10 ) -> V_100 . V_101 -- ;
if ( F_40 ( V_10 ) -> V_100 . V_101
== 0 ) {
if ( V_10 -> V_102 & V_103 )
F_41 () ;
}
}
}
}
return V_119 ;
}
static int F_102 ( struct V_9 * V_10 , struct V_69 * V_211 ,
union V_3 * V_212 , struct V_219 * V_106 ,
struct V_49 * V_50 , int * V_89 )
{
struct V_73 * V_221 ;
struct V_11 * V_74 ;
unsigned int V_45 ;
int V_46 ;
struct V_75 * V_76 ;
T_2 V_214 ;
V_45 = F_50 ( F_3 ( V_106 -> V_144 ) ) ;
V_221 = V_10 -> V_51 [ V_45 ] ;
V_46 = F_100 ( F_3 ( V_106 -> V_144 ) ) - 1 ;
V_74 = F_101 ( V_50 , F_31 ( V_106 -> V_222 ) ) ;
V_76 = F_30 ( V_10 , V_221 -> V_80 , V_46 ) ;
V_214 = F_65 ( F_3 ( V_106 -> V_223 ) ) ;
F_103 ( V_10 , V_10 -> V_13 -> V_24 ) ;
switch ( V_214 ) {
case V_126 :
if ( V_212 == V_74 -> V_24 ) {
F_16 ( V_10 , L_86
L_87 ) ;
* V_89 = - V_122 ;
} else if ( V_212 != V_211 -> F_4 ) {
F_16 ( V_10 , L_88
L_87 ) ;
* V_89 = - V_122 ;
} else {
* V_89 = 0 ;
}
break;
case V_233 :
F_16 ( V_10 , L_89 ) ;
if ( V_211 -> V_66 -> V_230 & V_231 )
* V_89 = - V_232 ;
else
* V_89 = 0 ;
break;
case V_225 :
case V_226 :
return F_99 ( V_10 , V_211 , V_212 , V_106 , V_50 , V_89 , false ) ;
default:
if ( ! F_97 ( V_10 ,
V_76 , V_214 ) )
break;
F_10 ( V_10 , L_90
L_91 ,
V_214 , V_46 ) ;
case V_227 :
if ( V_212 != V_74 -> V_24 &&
V_212 != V_211 -> F_4 )
V_211 -> V_66 -> V_228 =
V_211 -> V_66 -> V_229
- F_104 ( F_3 ( V_106 -> V_223 ) ) ;
else
V_211 -> V_66 -> V_228 = 0 ;
F_94 ( V_10 ,
V_45 , V_46 , 0 , V_211 , V_212 ) ;
return F_99 ( V_10 , V_211 , V_212 , V_106 , V_50 , V_89 , true ) ;
}
if ( V_212 != V_74 -> V_24 ) {
if ( V_212 == V_211 -> F_4 ) {
if ( V_211 -> V_66 -> V_228 != 0 ) {
if ( ( * V_89 == - V_234 || * V_89 == 0 ) &&
( V_211 -> V_66 -> V_230
& V_231 ) )
* V_89 = - V_232 ;
} else {
V_211 -> V_66 -> V_228 =
V_211 -> V_66 -> V_229 ;
}
} else {
V_211 -> V_66 -> V_228 =
V_211 -> V_66 -> V_229 -
F_104 ( F_3 ( V_106 -> V_223 ) ) ;
F_10 ( V_10 , L_92
L_93 ) ;
return 0 ;
}
}
return F_99 ( V_10 , V_211 , V_212 , V_106 , V_50 , V_89 , false ) ;
}
static int F_105 ( struct V_9 * V_10 , struct V_69 * V_211 ,
union V_3 * V_212 , struct V_219 * V_106 ,
struct V_49 * V_50 , int * V_89 )
{
struct V_11 * V_74 ;
struct V_93 * V_93 ;
int V_235 ;
int V_236 = 0 ;
union V_3 * V_83 ;
struct V_1 * V_40 ;
struct V_237 * V_238 ;
T_2 V_214 ;
bool V_239 = false ;
V_74 = F_101 ( V_50 , F_31 ( V_106 -> V_222 ) ) ;
V_214 = F_65 ( F_3 ( V_106 -> V_223 ) ) ;
V_93 = V_211 -> V_66 -> V_94 ;
V_235 = V_93 -> V_95 ;
V_238 = & V_211 -> V_66 -> V_240 [ V_235 ] ;
switch ( V_214 ) {
case V_126 :
V_238 -> V_89 = 0 ;
break;
case V_233 :
V_238 -> V_89 = V_211 -> V_66 -> V_230 & V_231 ?
- V_232 : 0 ;
break;
case V_241 :
V_238 -> V_89 = - V_242 ;
V_239 = true ;
break;
case V_243 :
case V_216 :
V_238 -> V_89 = - V_244 ;
V_239 = true ;
break;
case V_245 :
case V_227 :
V_238 -> V_89 = - V_246 ;
V_239 = true ;
break;
case V_226 :
case V_225 :
break;
default:
V_238 -> V_89 = - 1 ;
break;
}
if ( V_214 == V_126 || V_239 ) {
V_238 -> V_228 = V_238 -> V_97 ;
V_211 -> V_66 -> V_228 += V_238 -> V_97 ;
} else {
for ( V_83 = V_74 -> V_24 ,
V_40 = V_74 -> V_27 ; V_83 != V_212 ;
F_7 ( V_10 , V_74 , & V_40 , & V_83 ) ) {
if ( ( F_3 ( V_83 -> V_31 . V_32 [ 3 ] ) &
V_19 ) != F_5 ( V_85 ) &&
( F_3 ( V_83 -> V_31 . V_32 [ 3 ] ) &
V_19 ) != F_5 ( V_20 ) )
V_236 += F_104 ( F_3 ( V_83 -> V_31 . V_32 [ 2 ] ) ) ;
}
V_236 += F_104 ( F_3 ( V_83 -> V_31 . V_32 [ 2 ] ) ) -
F_104 ( F_3 ( V_106 -> V_223 ) ) ;
if ( V_214 != V_225 ) {
V_238 -> V_228 = V_236 ;
V_211 -> V_66 -> V_228 += V_236 ;
}
}
return F_99 ( V_10 , V_211 , V_212 , V_106 , V_50 , V_89 , false ) ;
}
static int F_106 ( struct V_9 * V_10 , struct V_69 * V_211 ,
struct V_219 * V_106 ,
struct V_49 * V_50 , int * V_89 )
{
struct V_11 * V_74 ;
struct V_93 * V_93 ;
struct V_237 * V_238 ;
int V_235 ;
V_74 = F_101 ( V_50 , F_31 ( V_106 -> V_222 ) ) ;
V_93 = V_211 -> V_66 -> V_94 ;
V_235 = V_93 -> V_95 ;
V_238 = & V_211 -> V_66 -> V_240 [ V_235 ] ;
V_238 -> V_89 = - V_247 ;
V_238 -> V_228 = 0 ;
while ( V_74 -> V_24 != V_211 -> F_4 )
F_8 ( V_10 , V_74 , false ) ;
F_8 ( V_10 , V_74 , false ) ;
return F_99 ( V_10 , V_211 , NULL , V_106 , V_50 , V_89 , true ) ;
}
static int F_107 ( struct V_9 * V_10 , struct V_69 * V_211 ,
union V_3 * V_212 , struct V_219 * V_106 ,
struct V_49 * V_50 , int * V_89 )
{
struct V_11 * V_74 ;
union V_3 * V_83 ;
struct V_1 * V_40 ;
T_2 V_214 ;
V_74 = F_101 ( V_50 , F_31 ( V_106 -> V_222 ) ) ;
V_214 = F_65 ( F_3 ( V_106 -> V_223 ) ) ;
switch ( V_214 ) {
case V_126 :
if ( V_212 != V_211 -> F_4 ) {
F_16 ( V_10 , L_94
L_95 ) ;
if ( V_211 -> V_66 -> V_230 & V_231 )
* V_89 = - V_232 ;
else
* V_89 = 0 ;
} else {
* V_89 = 0 ;
}
break;
case V_233 :
if ( V_211 -> V_66 -> V_230 & V_231 )
* V_89 = - V_232 ;
else
* V_89 = 0 ;
break;
default:
break;
}
if ( V_214 == V_233 )
F_10 ( V_10 , L_96
L_97 ,
V_211 -> V_66 -> V_50 -> V_68 . V_248 ,
V_211 -> V_66 -> V_229 ,
F_104 ( F_3 ( V_106 -> V_223 ) ) ) ;
if ( V_212 == V_211 -> F_4 ) {
if ( F_104 ( F_3 ( V_106 -> V_223 ) ) != 0 ) {
V_211 -> V_66 -> V_228 =
V_211 -> V_66 -> V_229 -
F_104 ( F_3 ( V_106 -> V_223 ) ) ;
if ( V_211 -> V_66 -> V_229 <
V_211 -> V_66 -> V_228 ) {
F_16 ( V_10 , L_98
L_99 ,
F_104 ( F_3 ( V_106 -> V_223 ) ) ) ;
V_211 -> V_66 -> V_228 = 0 ;
if ( V_211 -> V_66 -> V_230 & V_231 )
* V_89 = - V_232 ;
else
* V_89 = 0 ;
}
if ( * V_89 == - V_234 ) {
if ( V_211 -> V_66 -> V_230 & V_231 )
* V_89 = - V_232 ;
else
* V_89 = 0 ;
}
} else {
V_211 -> V_66 -> V_228 =
V_211 -> V_66 -> V_229 ;
if ( * V_89 == - V_232 )
* V_89 = 0 ;
}
} else {
V_211 -> V_66 -> V_228 = 0 ;
for ( V_83 = V_74 -> V_24 , V_40 = V_74 -> V_27 ;
V_83 != V_212 ;
F_7 ( V_10 , V_74 , & V_40 , & V_83 ) ) {
if ( ( F_3 ( V_83 -> V_31 . V_32 [ 3 ] ) &
V_19 ) != F_5 ( V_85 ) &&
( F_3 ( V_83 -> V_31 . V_32 [ 3 ] ) &
V_19 ) != F_5 ( V_20 ) )
V_211 -> V_66 -> V_228 +=
F_104 ( F_3 ( V_83 -> V_31 . V_32 [ 2 ] ) ) ;
}
if ( V_214 != V_225 )
V_211 -> V_66 -> V_228 +=
F_104 ( F_3 ( V_83 -> V_31 . V_32 [ 2 ] ) ) -
F_104 ( F_3 ( V_106 -> V_223 ) ) ;
}
return F_99 ( V_10 , V_211 , V_212 , V_106 , V_50 , V_89 , false ) ;
}
static int F_108 ( struct V_9 * V_10 ,
struct V_219 * V_106 )
{
struct V_73 * V_221 ;
struct V_49 * V_50 ;
struct V_11 * V_74 ;
unsigned int V_45 ;
int V_46 ;
struct V_69 * V_211 = NULL ;
T_1 V_249 ;
struct V_1 * V_250 ;
union V_3 * V_212 ;
struct V_66 * V_66 = NULL ;
int V_89 = - V_234 ;
struct V_93 * V_93 ;
struct V_75 * V_76 ;
T_2 V_214 ;
int V_119 = 0 ;
V_45 = F_50 ( F_3 ( V_106 -> V_144 ) ) ;
V_221 = V_10 -> V_51 [ V_45 ] ;
if ( ! V_221 ) {
F_109 ( V_10 , L_100 ) ;
return - V_251 ;
}
V_46 = F_100 ( F_3 ( V_106 -> V_144 ) ) - 1 ;
V_50 = & V_221 -> V_52 [ V_46 ] ;
V_74 = F_101 ( V_50 , F_31 ( V_106 -> V_222 ) ) ;
V_76 = F_30 ( V_10 , V_221 -> V_80 , V_46 ) ;
if ( ! V_74 ||
( F_3 ( V_76 -> V_130 ) & V_131 ) ==
V_252 ) {
F_109 ( V_10 , L_101
L_102 ) ;
return - V_251 ;
}
V_249 = F_31 ( V_106 -> V_222 ) ;
V_214 = F_65 ( F_3 ( V_106 -> V_223 ) ) ;
switch ( V_214 ) {
case V_126 :
case V_233 :
break;
case V_226 :
F_10 ( V_10 , L_103 ) ;
break;
case V_225 :
F_10 ( V_10 , L_104 ) ;
break;
case V_227 :
F_16 ( V_10 , L_105 ) ;
V_50 -> V_53 |= V_56 ;
V_89 = - V_253 ;
break;
case V_128 :
F_16 ( V_10 , L_106 ) ;
V_89 = - V_254 ;
break;
case V_217 :
case V_215 :
F_16 ( V_10 , L_107 ) ;
V_89 = - V_246 ;
break;
case V_216 :
F_16 ( V_10 , L_108 ) ;
V_89 = - V_244 ;
break;
case V_255 :
F_16 ( V_10 , L_109 ) ;
V_89 = - V_256 ;
break;
case V_241 :
F_16 ( V_10 , L_110 ) ;
break;
case V_243 :
F_16 ( V_10 , L_111 ) ;
break;
case V_257 :
F_10 ( V_10 , L_112 ) ;
if ( ! F_23 ( & V_74 -> V_58 ) )
F_10 ( V_10 , L_113
L_114 ,
F_50 ( F_3 ( V_106 -> V_144 ) ) ,
V_46 ) ;
goto V_190;
case V_258 :
F_10 ( V_10 , L_115 ) ;
if ( ! F_23 ( & V_74 -> V_58 ) )
F_10 ( V_10 , L_116
L_114 ,
F_50 ( F_3 ( V_106 -> V_144 ) ) ,
V_46 ) ;
goto V_190;
case V_245 :
F_16 ( V_10 , L_117 ) ;
V_89 = - V_246 ;
break;
case V_259 :
V_50 -> V_220 = true ;
F_10 ( V_10 , L_118 ) ;
goto V_190;
default:
if ( F_98 ( V_10 , V_214 ) ) {
V_89 = 0 ;
break;
}
F_16 ( V_10 , L_119
L_120 ) ;
goto V_190;
}
do {
if ( F_23 ( & V_74 -> V_58 ) ) {
F_16 ( V_10 , L_121
L_122 ,
F_50 ( F_3 ( V_106 -> V_144 ) ) ,
V_46 ) ;
F_10 ( V_10 , L_123 ,
( unsigned int ) ( F_3 ( V_106 -> V_144 )
& V_19 ) >> 10 ) ;
F_110 ( V_10 , (union V_3 * ) V_106 ) ;
if ( V_50 -> V_220 ) {
V_50 -> V_220 = false ;
F_10 ( V_10 , L_124
L_125 ) ;
}
V_119 = 0 ;
goto V_190;
}
V_211 = F_54 ( V_74 -> V_58 . V_14 , struct V_69 , V_58 ) ;
V_250 = F_93 ( V_74 -> V_27 , V_74 -> V_24 ,
V_211 -> F_4 , V_249 ) ;
if ( ! V_250 && V_214 == V_225 ) {
V_119 = 0 ;
goto V_190;
}
if ( ! V_250 ) {
if ( ! V_50 -> V_220 ||
! F_111 ( & V_211 -> V_66 -> V_50 -> V_68 ) ) {
if ( ( V_10 -> V_102 & V_260 ) &&
V_74 -> V_261 ) {
V_74 -> V_261 = false ;
V_119 = 0 ;
goto V_190;
}
F_109 ( V_10 ,
L_126
L_127 ) ;
return - V_122 ;
}
V_119 = F_106 ( V_10 , V_211 , V_106 , V_50 , & V_89 ) ;
goto V_190;
}
if ( V_214 == V_233 )
V_74 -> V_261 = true ;
else
V_74 -> V_261 = false ;
if ( V_50 -> V_220 ) {
F_10 ( V_10 , L_128 ) ;
V_50 -> V_220 = false ;
}
V_212 = & V_250 -> V_6 [ ( V_249 - V_250 -> V_8 ) /
sizeof( * V_212 ) ] ;
if ( ( F_3 ( V_212 -> V_31 . V_32 [ 3 ] )
& V_19 )
== F_5 ( V_85 ) ) {
F_10 ( V_10 ,
L_129 ) ;
goto V_190;
}
if ( F_112 ( & V_211 -> V_66 -> V_50 -> V_68 ) )
V_119 = F_102 ( V_10 , V_211 , V_212 , V_106 , V_50 ,
& V_89 ) ;
else if ( F_111 ( & V_211 -> V_66 -> V_50 -> V_68 ) )
V_119 = F_105 ( V_10 , V_211 , V_212 , V_106 , V_50 ,
& V_89 ) ;
else
V_119 = F_107 ( V_10 , V_211 , V_212 , V_106 ,
V_50 , & V_89 ) ;
V_190:
if ( V_214 == V_259 || ! V_50 -> V_220 ) {
F_8 ( V_10 , V_10 -> V_13 , true ) ;
}
if ( V_119 ) {
V_66 = V_211 -> V_66 ;
V_93 = V_66 -> V_94 ;
if ( F_112 ( & V_66 -> V_50 -> V_68 ) ||
( V_214 != V_227 &&
V_214 != V_216 ) )
F_45 ( V_10 , V_93 ) ;
F_42 ( F_38 ( V_66 -> V_67 -> V_96 ) , V_66 ) ;
if ( ( V_66 -> V_228 != V_66 -> V_229 &&
( V_66 -> V_230 &
V_231 ) ) ||
V_89 != 0 )
F_10 ( V_10 , L_130
L_131 ,
V_66 , V_66 -> V_228 ,
V_66 -> V_229 ,
V_89 ) ;
F_43 ( & V_10 -> V_104 ) ;
if ( F_39 ( V_66 -> V_98 ) == V_99 )
V_89 = 0 ;
F_44 ( F_38 ( V_66 -> V_67 -> V_96 ) , V_66 , V_89 ) ;
F_46 ( & V_10 -> V_104 ) ;
}
} while ( V_50 -> V_220 && V_214 != V_259 );
return 0 ;
}
static int F_113 ( struct V_9 * V_10 )
{
union V_3 * V_106 ;
int V_262 = 1 ;
int V_119 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_24 ) {
V_10 -> V_150 |= 1 << 1 ;
return 0 ;
}
V_106 = V_10 -> V_13 -> V_24 ;
if ( ( F_3 ( V_106 -> V_173 . V_144 ) & V_36 ) !=
V_10 -> V_13 -> V_28 ) {
V_10 -> V_150 |= 1 << 2 ;
return 0 ;
}
F_114 () ;
switch ( ( F_3 ( V_106 -> V_173 . V_144 ) & V_19 ) ) {
case F_5 ( V_263 ) :
F_71 ( V_10 , & V_106 -> V_173 ) ;
break;
case F_5 ( V_264 ) :
F_81 ( V_10 , V_106 ) ;
V_262 = 0 ;
break;
case F_5 ( V_265 ) :
V_119 = F_108 ( V_10 , & V_106 -> V_266 ) ;
if ( V_119 < 0 )
V_10 -> V_150 |= 1 << 9 ;
else
V_262 = 0 ;
break;
default:
if ( ( F_3 ( V_106 -> V_173 . V_144 ) & V_19 ) >=
F_5 ( 48 ) )
F_78 ( V_10 , V_106 ) ;
else
V_10 -> V_150 |= 1 << 3 ;
}
if ( V_10 -> V_115 & V_116 ) {
F_10 ( V_10 , L_132
L_133 ) ;
return 0 ;
}
if ( V_262 )
F_8 ( V_10 , V_10 -> V_13 , true ) ;
return 1 ;
}
T_7 F_115 ( struct V_91 * V_92 )
{
struct V_9 * V_10 = F_116 ( V_92 ) ;
T_2 V_89 ;
union V_3 * V_4 ;
T_5 V_267 ;
union V_3 * V_268 ;
T_1 V_81 ;
F_46 ( & V_10 -> V_104 ) ;
V_4 = V_10 -> V_13 -> V_24 ;
V_89 = F_19 ( V_10 , & V_10 -> V_198 -> V_89 ) ;
if ( V_89 == 0xffffffff )
goto V_269;
if ( ! ( V_89 & V_270 ) ) {
F_43 ( & V_10 -> V_104 ) ;
return V_271 ;
}
if ( V_89 & V_272 ) {
F_16 ( V_10 , L_134 ) ;
F_58 ( V_10 ) ;
V_269:
F_43 ( & V_10 -> V_104 ) ;
return - V_122 ;
}
V_89 |= V_270 ;
F_18 ( V_10 , V_89 , & V_10 -> V_198 -> V_89 ) ;
if ( V_92 -> V_273 != - 1 ) {
T_2 V_274 ;
V_274 = F_19 ( V_10 , & V_10 -> V_275 -> V_274 ) ;
V_274 |= 0x3 ;
F_18 ( V_10 , V_274 , & V_10 -> V_275 -> V_274 ) ;
}
if ( V_10 -> V_115 & V_116 ) {
F_10 ( V_10 , L_135
L_136 ) ;
V_267 = F_117 ( V_10 , & V_10 -> V_275 -> V_276 ) ;
F_118 ( V_10 , V_267 | V_277 ,
& V_10 -> V_275 -> V_276 ) ;
F_43 ( & V_10 -> V_104 ) ;
return V_278 ;
}
V_268 = V_10 -> V_13 -> V_24 ;
while ( F_113 ( V_10 ) > 0 ) {}
V_267 = F_117 ( V_10 , & V_10 -> V_275 -> V_276 ) ;
if ( V_268 != V_10 -> V_13 -> V_24 ) {
V_81 = F_1 ( V_10 -> V_13 -> V_27 ,
V_10 -> V_13 -> V_24 ) ;
if ( V_81 == 0 )
F_16 ( V_10 , L_137
L_138 ) ;
V_267 &= V_279 ;
V_267 |= ( ( T_5 ) V_81 & ( T_5 ) ~ V_279 ) ;
}
V_267 |= V_277 ;
F_118 ( V_10 , V_267 , & V_10 -> V_275 -> V_276 ) ;
F_43 ( & V_10 -> V_104 ) ;
return V_278 ;
}
T_7 F_119 ( int V_273 , struct V_91 * V_92 )
{
T_7 V_119 ;
struct V_9 * V_10 ;
V_10 = F_116 ( V_92 ) ;
F_120 ( V_280 , & V_92 -> V_144 ) ;
if ( V_10 -> V_191 )
F_120 ( V_280 , & V_10 -> V_191 -> V_144 ) ;
V_119 = F_115 ( V_92 ) ;
return V_119 ;
}
static void F_121 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_23 , bool V_29 ,
T_2 V_281 , T_2 V_282 , T_2 V_283 , T_2 V_284 )
{
struct V_64 * V_4 ;
V_4 = & V_12 -> V_22 -> V_31 ;
V_4 -> V_32 [ 0 ] = F_13 ( V_281 ) ;
V_4 -> V_32 [ 1 ] = F_13 ( V_282 ) ;
V_4 -> V_32 [ 2 ] = F_13 ( V_283 ) ;
V_4 -> V_32 [ 3 ] = F_13 ( V_284 ) ;
F_11 ( V_10 , V_12 , V_23 , V_29 ) ;
}
static int F_122 ( struct V_9 * V_10 , struct V_11 * V_74 ,
T_2 V_53 , unsigned int V_37 , T_8 V_285 )
{
switch ( V_53 ) {
case V_252 :
F_16 ( V_10 , L_139 ) ;
return - V_286 ;
case V_287 :
F_16 ( V_10 , L_140 ) ;
return - V_288 ;
case V_218 :
F_10 ( V_10 , L_141 ) ;
case V_289 :
case V_290 :
break;
default:
F_109 ( V_10 , L_142 ) ;
return - V_288 ;
}
if ( ! F_15 ( V_10 , V_74 , V_37 ) ) {
F_109 ( V_10 , L_143 ) ;
return - V_291 ;
}
if ( F_6 ( V_74 ) ) {
struct V_11 * V_12 = V_74 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_22 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_35 , V_14 ) ) {
if ( ! F_12 ( V_10 ) )
V_14 -> V_16 . V_17 &= F_13 ( ~ V_33 ) ;
else
V_14 -> V_16 . V_17 |= F_13 ( V_33 ) ;
F_14 () ;
V_14 -> V_16 . V_17 ^= F_13 ( ( T_2 ) V_36 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_35 , V_14 ) ) {
V_12 -> V_28 = ( V_12 -> V_28 ? 0 : 1 ) ;
if ( ! F_9 () ) {
F_10 ( V_10 , L_144
L_145 ,
V_12 , ( unsigned int ) V_12 -> V_28 ) ;
}
}
V_12 -> V_35 = V_12 -> V_35 -> V_14 ;
V_12 -> V_22 = V_12 -> V_35 -> V_6 ;
V_14 = V_12 -> V_22 ;
}
}
return 0 ;
}
static int F_123 ( struct V_9 * V_10 ,
struct V_73 * V_221 ,
unsigned int V_46 ,
unsigned int V_47 ,
unsigned int V_37 ,
struct V_66 * V_66 ,
unsigned int V_292 ,
T_8 V_285 )
{
int V_119 ;
struct V_93 * V_93 ;
struct V_69 * V_211 ;
struct V_11 * V_74 ;
struct V_75 * V_76 = F_30 ( V_10 , V_221 -> V_80 , V_46 ) ;
V_74 = F_63 ( V_221 , V_46 , V_47 ) ;
if ( ! V_74 ) {
F_10 ( V_10 , L_146 ,
V_47 ) ;
return - V_288 ;
}
V_119 = F_122 ( V_10 , V_74 ,
F_3 ( V_76 -> V_130 ) & V_131 ,
V_37 , V_285 ) ;
if ( V_119 )
return V_119 ;
V_93 = V_66 -> V_94 ;
V_211 = V_93 -> V_211 [ V_292 ] ;
F_124 ( & V_211 -> V_58 ) ;
F_124 ( & V_211 -> V_112 ) ;
if ( V_292 == 0 ) {
V_119 = F_125 ( F_38 ( V_66 -> V_67 -> V_96 ) , V_66 ) ;
if ( F_48 ( V_119 ) ) {
F_45 ( V_10 , V_93 ) ;
V_66 -> V_94 = NULL ;
return V_119 ;
}
}
V_211 -> V_66 = V_66 ;
F_126 ( & V_211 -> V_58 , & V_74 -> V_58 ) ;
V_211 -> V_63 = V_74 -> V_35 ;
V_211 -> V_84 = V_74 -> V_22 ;
V_93 -> V_211 [ V_292 ] = V_211 ;
return 0 ;
}
static unsigned int F_127 ( struct V_9 * V_10 , struct V_66 * V_66 )
{
int V_293 , V_37 , V_294 , V_181 , V_38 ;
struct V_295 * V_296 ;
V_296 = NULL ;
V_293 = V_66 -> V_293 ;
V_181 = V_66 -> V_229 ;
F_10 ( V_10 , L_147 ) ;
V_37 = 0 ;
F_128 (urb->sg, sg, num_sgs, i) {
unsigned int V_297 = V_37 ;
unsigned int V_236 = F_129 ( V_296 ) ;
V_294 = V_298 -
( F_130 ( V_296 ) & ( V_298 - 1 ) ) ;
V_294 &= V_298 - 1 ;
if ( V_294 != 0 )
V_37 ++ ;
while ( V_294 < F_129 ( V_296 ) && V_294 < V_181 ) {
V_37 ++ ;
V_294 += V_298 ;
}
F_10 ( V_10 , L_148 ,
V_38 , ( unsigned long long ) F_130 ( V_296 ) ,
V_236 , V_236 , V_37 - V_297 ) ;
V_236 = F_131 ( int , V_236 , V_181 ) ;
V_181 -= V_236 ;
if ( V_181 == 0 )
break;
}
F_10 ( V_10 , L_149 ) ;
if ( ! F_9 () )
F_10 ( V_10 , L_150
L_151 ,
V_66 -> V_50 -> V_68 . V_248 ,
V_66 -> V_229 ,
V_37 ) ;
return V_37 ;
}
static void F_132 ( struct V_66 * V_66 , int V_37 , int V_294 )
{
if ( V_37 != 0 )
F_133 ( & V_66 -> V_67 -> V_67 , L_152
L_153 , V_299 ,
V_66 -> V_50 -> V_68 . V_248 , V_37 ) ;
if ( V_294 != V_66 -> V_229 )
F_133 ( & V_66 -> V_67 -> V_67 , L_154
L_155 ,
V_299 ,
V_66 -> V_50 -> V_68 . V_248 ,
V_294 , V_294 ,
V_66 -> V_229 ,
V_66 -> V_229 ) ;
}
static void F_134 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 , unsigned int V_47 , int V_300 ,
struct V_64 * V_205 )
{
F_14 () ;
if ( V_300 )
V_205 -> V_32 [ 3 ] |= F_13 ( V_300 ) ;
else
V_205 -> V_32 [ 3 ] &= F_13 ( ~ V_36 ) ;
F_20 ( V_10 , V_45 , V_46 , V_47 ) ;
}
int F_135 ( struct V_9 * V_10 , T_8 V_285 ,
struct V_66 * V_66 , int V_45 , unsigned int V_46 )
{
struct V_75 * V_76 = F_30 ( V_10 ,
V_10 -> V_51 [ V_45 ] -> V_80 , V_46 ) ;
int V_301 ;
int V_302 ;
V_301 = F_136 ( F_3 ( V_76 -> V_130 ) ) ;
V_302 = V_66 -> V_303 ;
if ( V_66 -> V_67 -> V_179 == V_304 ||
V_66 -> V_67 -> V_179 == V_305 )
V_302 *= 8 ;
if ( V_301 != V_302 ) {
if ( F_137 () )
F_138 ( & V_66 -> V_67 -> V_67 , L_156
L_157
L_158 ,
V_302 ,
V_302 == 1 ? L_159 : L_160 ,
V_301 ,
V_301 == 1 ? L_159 : L_160 ) ;
V_66 -> V_303 = V_301 ;
if ( V_66 -> V_67 -> V_179 == V_304 ||
V_66 -> V_67 -> V_179 == V_305 )
V_66 -> V_303 /= 8 ;
}
return F_139 ( V_10 , V_306 , V_66 , V_45 , V_46 ) ;
}
static T_2 F_140 ( unsigned int V_307 )
{
T_2 V_308 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_307 >> 10 ) >= V_308 )
return V_308 << 17 ;
else
return ( V_307 >> 10 ) << 17 ;
}
static T_2 F_141 ( int V_294 , int V_309 ,
unsigned int V_310 , struct V_66 * V_66 )
{
int V_311 ;
V_311 = ( V_294 + V_309 ) /
F_142 ( V_66 -> V_50 -> V_68 . V_312 ) ;
return F_140 ( V_310 - V_311 ) ;
}
static int F_143 ( struct V_9 * V_10 , T_8 V_285 ,
struct V_66 * V_66 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_74 ;
unsigned int V_37 ;
struct V_93 * V_93 ;
struct V_69 * V_211 ;
struct V_295 * V_296 ;
int V_293 ;
int V_309 , V_313 , V_294 ;
unsigned int V_310 ;
bool V_84 ;
T_5 V_25 ;
bool V_29 ;
struct V_64 * V_205 ;
int V_300 ;
V_74 = F_26 ( V_10 , V_66 ) ;
if ( ! V_74 )
return - V_288 ;
V_37 = F_127 ( V_10 , V_66 ) ;
V_293 = V_66 -> V_293 ;
V_310 = F_144 ( V_66 -> V_229 ,
F_142 ( V_66 -> V_50 -> V_68 . V_312 ) ) ;
V_309 = F_123 ( V_10 , V_10 -> V_51 [ V_45 ] ,
V_46 , V_66 -> V_47 ,
V_37 , V_66 , 0 , V_285 ) ;
if ( V_309 < 0 )
return V_309 ;
V_93 = V_66 -> V_94 ;
V_211 = V_93 -> V_211 [ 0 ] ;
V_205 = & V_74 -> V_22 -> V_31 ;
V_300 = V_74 -> V_28 ;
V_294 = 0 ;
V_296 = V_66 -> V_296 ;
V_25 = ( T_5 ) F_130 ( V_296 ) ;
V_313 = F_129 ( V_296 ) ;
V_309 = V_298 - ( V_25 & ( V_298 - 1 ) ) ;
V_309 = F_131 ( int , V_309 , V_313 ) ;
if ( V_309 > V_66 -> V_229 )
V_309 = V_66 -> V_229 ;
F_10 ( V_10 , L_161 ,
V_309 ) ;
V_84 = true ;
do {
T_2 V_32 = 0 ;
T_2 V_314 = 0 ;
T_2 V_307 = 0 ;
if ( V_84 ) {
V_84 = false ;
if ( V_300 == 0 )
V_32 |= 0x1 ;
} else
V_32 |= V_74 -> V_28 ;
if ( V_37 > 1 ) {
V_32 |= V_33 ;
} else {
V_211 -> F_4 = V_74 -> V_22 ;
V_32 |= V_315 ;
}
if ( F_145 ( V_66 ) )
V_32 |= V_316 ;
F_10 ( V_10 , L_162
L_163 ,
( unsigned int ) V_25 , V_309 , V_309 ,
( unsigned int ) ( V_25 + V_298 ) & ~ ( V_298 - 1 ) ,
( unsigned int ) V_25 + V_309 ) ;
if ( V_298 -
( V_25 & ( V_298 - 1 ) ) < V_309 ) {
F_16 ( V_10 , L_164 ) ;
F_10 ( V_10 , L_165 ,
( unsigned int ) ( V_25 + V_298 ) & ~ ( V_298 - 1 ) ,
( unsigned int ) V_25 + V_309 ) ;
}
if ( V_10 -> V_317 < 0x100 ) {
V_307 = F_140 (
V_66 -> V_229 -
V_294 ) ;
} else {
V_307 = F_141 ( V_294 ,
V_309 , V_310 , V_66 ) ;
}
V_314 = F_104 ( V_309 ) |
V_307 |
F_146 ( 0 ) ;
if ( V_37 > 1 )
V_29 = true ;
else
V_29 = false ;
F_121 ( V_10 , V_74 , false , V_29 ,
F_147 ( V_25 ) ,
F_148 ( V_25 ) ,
V_314 ,
V_32 | F_5 ( V_318 ) ) ;
-- V_37 ;
V_294 += V_309 ;
V_313 -= V_309 ;
if ( V_313 == 0 ) {
-- V_293 ;
if ( V_293 == 0 )
break;
V_296 = F_149 ( V_296 ) ;
V_25 = ( T_5 ) F_130 ( V_296 ) ;
V_313 = F_129 ( V_296 ) ;
} else {
V_25 += V_309 ;
}
V_309 = V_298 -
( V_25 & ( V_298 - 1 ) ) ;
V_309 = F_131 ( int , V_309 , V_313 ) ;
if ( V_294 + V_309 > V_66 -> V_229 )
V_309 =
V_66 -> V_229 - V_294 ;
} while ( V_294 < V_66 -> V_229 );
F_132 ( V_66 , V_37 , V_294 ) ;
F_134 ( V_10 , V_45 , V_46 , V_66 -> V_47 ,
V_300 , V_205 ) ;
return 0 ;
}
int F_139 ( struct V_9 * V_10 , T_8 V_285 ,
struct V_66 * V_66 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_74 ;
struct V_93 * V_93 ;
struct V_69 * V_211 ;
int V_37 ;
struct V_64 * V_205 ;
bool V_84 ;
bool V_29 ;
int V_300 ;
T_2 V_32 , V_314 ;
int V_294 , V_309 , V_119 ;
unsigned int V_310 ;
T_5 V_25 ;
if ( V_66 -> V_293 )
return F_143 ( V_10 , V_285 , V_66 , V_45 , V_46 ) ;
V_74 = F_26 ( V_10 , V_66 ) ;
if ( ! V_74 )
return - V_288 ;
V_37 = 0 ;
V_294 = V_298 -
( V_66 -> V_319 & ( V_298 - 1 ) ) ;
V_294 &= V_298 - 1 ;
if ( V_294 != 0 || V_66 -> V_229 == 0 )
V_37 ++ ;
while ( V_294 < V_66 -> V_229 ) {
V_37 ++ ;
V_294 += V_298 ;
}
if ( ! F_9 () )
F_10 ( V_10 , L_166
L_167 ,
V_66 -> V_50 -> V_68 . V_248 ,
V_66 -> V_229 ,
V_66 -> V_229 ,
( unsigned long long ) V_66 -> V_319 ,
V_37 ) ;
V_119 = F_123 ( V_10 , V_10 -> V_51 [ V_45 ] ,
V_46 , V_66 -> V_47 ,
V_37 , V_66 , 0 , V_285 ) ;
if ( V_119 < 0 )
return V_119 ;
V_93 = V_66 -> V_94 ;
V_211 = V_93 -> V_211 [ 0 ] ;
V_205 = & V_74 -> V_22 -> V_31 ;
V_300 = V_74 -> V_28 ;
V_294 = 0 ;
V_310 = F_144 ( V_66 -> V_229 ,
F_142 ( V_66 -> V_50 -> V_68 . V_312 ) ) ;
V_25 = ( T_5 ) V_66 -> V_319 ;
V_309 = V_298 -
( V_66 -> V_319 & ( V_298 - 1 ) ) ;
if ( V_309 > V_66 -> V_229 )
V_309 = V_66 -> V_229 ;
V_84 = true ;
do {
T_2 V_307 = 0 ;
V_32 = 0 ;
if ( V_84 ) {
V_84 = false ;
if ( V_300 == 0 )
V_32 |= 0x1 ;
} else
V_32 |= V_74 -> V_28 ;
if ( V_37 > 1 ) {
V_32 |= V_33 ;
} else {
V_211 -> F_4 = V_74 -> V_22 ;
V_32 |= V_315 ;
}
if ( F_145 ( V_66 ) )
V_32 |= V_316 ;
if ( V_10 -> V_317 < 0x100 ) {
V_307 = F_140 (
V_66 -> V_229 -
V_294 ) ;
} else {
V_307 = F_141 ( V_294 ,
V_309 , V_310 , V_66 ) ;
}
V_314 = F_104 ( V_309 ) |
V_307 |
F_146 ( 0 ) ;
if ( V_37 > 1 )
V_29 = true ;
else
V_29 = false ;
F_121 ( V_10 , V_74 , false , V_29 ,
F_147 ( V_25 ) ,
F_148 ( V_25 ) ,
V_314 ,
V_32 | F_5 ( V_318 ) ) ;
-- V_37 ;
V_294 += V_309 ;
V_25 += V_309 ;
V_309 = V_66 -> V_229 - V_294 ;
if ( V_309 > V_298 )
V_309 = V_298 ;
} while ( V_294 < V_66 -> V_229 );
F_132 ( V_66 , V_37 , V_294 ) ;
F_134 ( V_10 , V_45 , V_46 , V_66 -> V_47 ,
V_300 , V_205 ) ;
return 0 ;
}
int F_150 ( struct V_9 * V_10 , T_8 V_285 ,
struct V_66 * V_66 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_74 ;
int V_37 ;
int V_119 ;
struct V_320 * V_321 ;
struct V_64 * V_205 ;
int V_300 ;
T_2 V_32 , V_314 ;
struct V_93 * V_93 ;
struct V_69 * V_211 ;
V_74 = F_26 ( V_10 , V_66 ) ;
if ( ! V_74 )
return - V_288 ;
if ( ! V_66 -> V_322 )
return - V_288 ;
if ( ! F_9 () )
F_10 ( V_10 , L_168 ,
V_45 , V_46 ) ;
V_37 = 2 ;
if ( V_66 -> V_229 > 0 )
V_37 ++ ;
V_119 = F_123 ( V_10 , V_10 -> V_51 [ V_45 ] ,
V_46 , V_66 -> V_47 ,
V_37 , V_66 , 0 , V_285 ) ;
if ( V_119 < 0 )
return V_119 ;
V_93 = V_66 -> V_94 ;
V_211 = V_93 -> V_211 [ 0 ] ;
V_205 = & V_74 -> V_22 -> V_31 ;
V_300 = V_74 -> V_28 ;
V_321 = (struct V_320 * ) V_66 -> V_322 ;
V_32 = 0 ;
V_32 |= V_323 | F_5 ( V_324 ) ;
if ( V_300 == 0 )
V_32 |= 0x1 ;
if ( V_10 -> V_317 == 0x100 ) {
if ( V_66 -> V_229 > 0 ) {
if ( V_321 -> V_325 & V_326 )
V_32 |= F_151 ( V_327 ) ;
else
V_32 |= F_151 ( V_328 ) ;
}
}
F_121 ( V_10 , V_74 , false , true ,
V_321 -> V_325 | V_321 -> V_329 << 8 | F_142 ( V_321 -> V_330 ) << 16 ,
F_142 ( V_321 -> V_331 ) | F_142 ( V_321 -> V_332 ) << 16 ,
F_104 ( 8 ) | F_146 ( 0 ) ,
V_32 ) ;
if ( F_145 ( V_66 ) )
V_32 = V_316 | F_5 ( V_333 ) ;
else
V_32 = F_5 ( V_333 ) ;
V_314 = F_104 ( V_66 -> V_229 ) |
F_140 ( V_66 -> V_229 ) |
F_146 ( 0 ) ;
if ( V_66 -> V_229 > 0 ) {
if ( V_321 -> V_325 & V_326 )
V_32 |= V_334 ;
F_121 ( V_10 , V_74 , false , true ,
F_147 ( V_66 -> V_319 ) ,
F_148 ( V_66 -> V_319 ) ,
V_314 ,
V_32 | V_74 -> V_28 ) ;
}
V_211 -> F_4 = V_74 -> V_22 ;
if ( V_66 -> V_229 > 0 && V_321 -> V_325 & V_326 )
V_32 = 0 ;
else
V_32 = V_334 ;
F_121 ( V_10 , V_74 , false , false ,
0 ,
0 ,
F_146 ( 0 ) ,
V_32 | V_315 | F_5 ( V_335 ) | V_74 -> V_28 ) ;
F_134 ( V_10 , V_45 , V_46 , 0 ,
V_300 , V_205 ) ;
return 0 ;
}
static int F_152 ( struct V_9 * V_10 ,
struct V_66 * V_66 , int V_38 )
{
int V_37 = 0 ;
T_5 V_25 , V_336 , V_294 ;
V_25 = ( T_5 ) ( V_66 -> V_319 + V_66 -> V_240 [ V_38 ] . V_337 ) ;
V_336 = V_66 -> V_240 [ V_38 ] . V_97 ;
V_294 = V_298 - ( V_25 & ( V_298 - 1 ) ) ;
V_294 &= V_298 - 1 ;
if ( V_294 != 0 )
V_37 ++ ;
while ( V_294 < V_336 ) {
V_37 ++ ;
V_294 += V_298 ;
}
return V_37 ;
}
static unsigned int F_153 ( struct V_9 * V_10 ,
struct V_338 * V_339 ,
struct V_66 * V_66 , unsigned int V_310 )
{
unsigned int V_340 ;
if ( V_10 -> V_317 < 0x100 || V_339 -> V_179 != V_341 )
return 0 ;
V_340 = V_66 -> V_50 -> V_342 . V_343 ;
return F_144 ( V_310 , V_340 + 1 ) - 1 ;
}
static unsigned int F_154 ( struct V_9 * V_10 ,
struct V_338 * V_339 ,
struct V_66 * V_66 , unsigned int V_310 )
{
unsigned int V_340 ;
unsigned int V_344 ;
if ( V_10 -> V_317 < 0x100 )
return 0 ;
switch ( V_339 -> V_179 ) {
case V_341 :
V_340 = V_66 -> V_50 -> V_342 . V_343 ;
V_344 = V_310 % ( V_340 + 1 ) ;
if ( V_344 == 0 )
return V_340 ;
return V_344 - 1 ;
default:
if ( V_310 == 0 )
return 0 ;
return V_310 - 1 ;
}
}
static int F_155 ( struct V_9 * V_10 , T_8 V_285 ,
struct V_66 * V_66 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_74 ;
struct V_93 * V_93 ;
struct V_69 * V_211 ;
int V_345 , V_346 ;
struct V_64 * V_205 ;
bool V_84 ;
int V_300 ;
T_2 V_32 , V_314 ;
int V_294 , V_309 , V_336 , V_347 , V_119 ;
T_5 V_348 , V_25 ;
int V_38 , V_120 ;
bool V_29 ;
V_74 = V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_12 ;
V_345 = V_66 -> V_349 ;
if ( V_345 < 1 ) {
F_10 ( V_10 , L_169 ) ;
return - V_288 ;
}
if ( ! F_9 () )
F_10 ( V_10 , L_170
L_171 ,
V_66 -> V_50 -> V_68 . V_248 ,
V_66 -> V_229 ,
V_66 -> V_229 ,
( unsigned long long ) V_66 -> V_319 ,
V_345 ) ;
V_348 = ( T_5 ) V_66 -> V_319 ;
V_205 = & V_74 -> V_22 -> V_31 ;
V_300 = V_74 -> V_28 ;
for ( V_38 = 0 ; V_38 < V_345 ; V_38 ++ ) {
unsigned int V_310 ;
unsigned int V_350 ;
unsigned int V_344 ;
V_84 = true ;
V_294 = 0 ;
V_25 = V_348 + V_66 -> V_240 [ V_38 ] . V_337 ;
V_336 = V_66 -> V_240 [ V_38 ] . V_97 ;
V_347 = V_336 ;
V_310 = F_144 ( V_336 ,
F_142 ( V_66 -> V_50 -> V_68 . V_312 ) ) ;
V_350 = F_153 ( V_10 , V_66 -> V_67 , V_66 ,
V_310 ) ;
V_344 = F_154 ( V_10 ,
V_66 -> V_67 , V_66 , V_310 ) ;
V_346 = F_152 ( V_10 , V_66 , V_38 ) ;
V_119 = F_123 ( V_10 , V_10 -> V_51 [ V_45 ] , V_46 ,
V_66 -> V_47 , V_346 , V_66 , V_38 , V_285 ) ;
if ( V_119 < 0 )
return V_119 ;
V_93 = V_66 -> V_94 ;
V_211 = V_93 -> V_211 [ V_38 ] ;
for ( V_120 = 0 ; V_120 < V_346 ; V_120 ++ ) {
T_2 V_307 = 0 ;
V_32 = F_156 ( V_350 ) | F_157 ( V_344 ) ;
if ( V_84 ) {
V_32 |= F_5 ( V_351 ) ;
V_32 |= V_352 ;
if ( V_38 == 0 ) {
if ( V_300 == 0 )
V_32 |= 0x1 ;
} else
V_32 |= V_74 -> V_28 ;
V_84 = false ;
} else {
V_32 |= F_5 ( V_318 ) ;
V_32 |= V_74 -> V_28 ;
}
if ( F_145 ( V_66 ) )
V_32 |= V_316 ;
if ( V_120 < V_346 - 1 ) {
V_32 |= V_33 ;
V_29 = true ;
} else {
V_211 -> F_4 = V_74 -> V_22 ;
V_32 |= V_315 ;
if ( V_10 -> V_317 == 0x100 ) {
if ( V_38 < V_345 - 1 )
V_32 |= V_353 ;
}
V_29 = false ;
}
V_309 = V_298 -
( V_25 & ( ( 1 << V_354 ) - 1 ) ) ;
if ( V_309 > V_347 )
V_309 = V_347 ;
if ( V_10 -> V_317 < 0x100 ) {
V_307 = F_140 (
V_336 - V_294 ) ;
} else {
V_307 = F_141 (
V_294 , V_309 ,
V_310 , V_66 ) ;
}
V_314 = F_104 ( V_309 ) |
V_307 |
F_146 ( 0 ) ;
F_121 ( V_10 , V_74 , false , V_29 ,
F_147 ( V_25 ) ,
F_148 ( V_25 ) ,
V_314 ,
V_32 ) ;
V_294 += V_309 ;
V_25 += V_309 ;
V_347 -= V_309 ;
}
if ( V_294 != V_336 ) {
F_109 ( V_10 , L_172 ) ;
return - V_288 ;
}
}
if ( F_40 ( V_10 ) -> V_100 . V_101 == 0 ) {
if ( V_10 -> V_102 & V_103 )
F_158 () ;
}
F_40 ( V_10 ) -> V_100 . V_101 ++ ;
F_134 ( V_10 , V_45 , V_46 , V_66 -> V_47 ,
V_300 , V_205 ) ;
return 0 ;
}
int F_159 ( struct V_9 * V_10 , T_8 V_285 ,
struct V_66 * V_66 , int V_45 , unsigned int V_46 )
{
struct V_73 * V_221 ;
struct V_11 * V_74 ;
struct V_75 * V_76 ;
int V_355 ;
int V_301 ;
int V_302 ;
int V_345 , V_37 , V_38 ;
int V_119 ;
V_221 = V_10 -> V_51 [ V_45 ] ;
V_74 = V_221 -> V_52 [ V_46 ] . V_12 ;
V_76 = F_30 ( V_10 , V_221 -> V_80 , V_46 ) ;
V_37 = 0 ;
V_345 = V_66 -> V_349 ;
for ( V_38 = 0 ; V_38 < V_345 ; V_38 ++ )
V_37 += F_152 ( V_10 , V_66 , V_38 ) ;
V_119 = F_122 ( V_10 , V_74 , F_3 ( V_76 -> V_130 ) & V_131 ,
V_37 , V_285 ) ;
if ( V_119 )
return V_119 ;
V_355 = F_19 ( V_10 , & V_10 -> V_356 -> V_357 ) ;
V_355 &= 0x3fff ;
V_66 -> V_355 = V_355 ;
if ( V_66 -> V_67 -> V_179 == V_304 ||
V_66 -> V_67 -> V_179 == V_305 )
V_66 -> V_355 >>= 3 ;
V_301 = F_136 ( F_3 ( V_76 -> V_130 ) ) ;
V_302 = V_66 -> V_303 ;
if ( V_66 -> V_67 -> V_179 == V_304 ||
V_66 -> V_67 -> V_179 == V_305 )
V_302 *= 8 ;
if ( V_301 != V_302 ) {
if ( F_137 () )
F_138 ( & V_66 -> V_67 -> V_67 , L_156
L_157
L_158 ,
V_302 ,
V_302 == 1 ? L_159 : L_160 ,
V_301 ,
V_301 == 1 ? L_159 : L_160 ) ;
V_66 -> V_303 = V_301 ;
if ( V_66 -> V_67 -> V_179 == V_304 ||
V_66 -> V_67 -> V_179 == V_305 )
V_66 -> V_303 /= 8 ;
}
return F_155 ( V_10 , V_306 , V_66 , V_45 , V_46 ) ;
}
static int F_160 ( struct V_9 * V_10 , T_2 V_281 , T_2 V_282 ,
T_2 V_283 , T_2 V_284 , bool V_358 )
{
int V_359 = V_10 -> V_360 ;
int V_119 ;
if ( ! V_358 )
V_359 ++ ;
V_119 = F_122 ( V_10 , V_10 -> V_111 , V_290 ,
V_359 , V_306 ) ;
if ( V_119 < 0 ) {
F_109 ( V_10 , L_173 ) ;
if ( V_358 )
F_109 ( V_10 , L_174
L_175 ) ;
return V_119 ;
}
F_121 ( V_10 , V_10 -> V_111 , false , false , V_281 , V_282 , V_283 ,
V_284 | V_10 -> V_111 -> V_28 ) ;
return 0 ;
}
int F_161 ( struct V_9 * V_10 , T_2 V_171 , T_2 V_45 )
{
return F_160 ( V_10 , 0 , 0 , 0 ,
F_5 ( V_171 ) | F_162 ( V_45 ) , false ) ;
}
int F_163 ( struct V_9 * V_10 , T_1 V_361 ,
T_2 V_45 )
{
return F_160 ( V_10 , F_147 ( V_361 ) ,
F_148 ( V_361 ) , 0 ,
F_5 ( V_163 ) | F_162 ( V_45 ) ,
false ) ;
}
int F_164 ( struct V_9 * V_10 ,
T_2 V_281 , T_2 V_282 , T_2 V_283 , T_2 V_284 )
{
return F_160 ( V_10 , V_281 , V_282 , V_283 , V_284 , false ) ;
}
int F_165 ( struct V_9 * V_10 , T_2 V_45 )
{
return F_160 ( V_10 , 0 , 0 , 0 ,
F_5 ( V_168 ) | F_162 ( V_45 ) ,
false ) ;
}
int F_68 ( struct V_9 * V_10 , T_1 V_361 ,
T_2 V_45 , bool V_358 )
{
return F_160 ( V_10 , F_147 ( V_361 ) ,
F_148 ( V_361 ) , 0 ,
F_5 ( V_155 ) | F_162 ( V_45 ) ,
V_358 ) ;
}
int F_166 ( struct V_9 * V_10 , T_1 V_361 ,
T_2 V_45 )
{
return F_160 ( V_10 , F_147 ( V_361 ) ,
F_148 ( V_361 ) , 0 ,
F_5 ( V_162 ) | F_162 ( V_45 ) ,
false ) ;
}
int F_167 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 , int V_362 )
{
T_2 V_363 = F_162 ( V_45 ) ;
T_2 V_364 = F_168 ( V_46 ) ;
T_2 type = F_5 ( V_164 ) ;
T_2 V_365 = F_169 ( V_362 ) ;
return F_160 ( V_10 , 0 , 0 , 0 ,
V_363 | V_364 | type | V_365 , false ) ;
}
static int F_34 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
struct V_1 * V_27 ,
union V_3 * V_366 , T_2 V_28 )
{
T_1 V_25 ;
T_2 V_363 = F_162 ( V_45 ) ;
T_2 V_364 = F_168 ( V_46 ) ;
T_2 V_367 = F_170 ( V_47 ) ;
T_2 type = F_5 ( V_165 ) ;
struct V_49 * V_50 ;
V_25 = F_1 ( V_27 , V_366 ) ;
if ( V_25 == 0 ) {
F_16 ( V_10 , L_176 ) ;
F_16 ( V_10 , L_177 ,
V_27 , V_366 ) ;
return 0 ;
}
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( ( V_50 -> V_53 & V_55 ) ) {
F_16 ( V_10 , L_176 ) ;
F_16 ( V_10 , L_178 ) ;
return 0 ;
}
V_50 -> V_134 = V_27 ;
V_50 -> V_135 = V_366 ;
return F_160 ( V_10 , F_147 ( V_25 ) | V_28 ,
F_148 ( V_25 ) , V_367 ,
V_363 | V_364 | type , false ) ;
}
int F_95 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 )
{
T_2 V_363 = F_162 ( V_45 ) ;
T_2 V_364 = F_168 ( V_46 ) ;
T_2 type = F_5 ( V_167 ) ;
return F_160 ( V_10 , 0 , 0 , 0 , V_363 | V_364 | type ,
false ) ;
}
