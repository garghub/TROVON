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
return F_5 ( V_4 -> V_16 . V_17 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_19 * V_16 = & V_12 -> V_20 -> V_16 ;
return F_5 ( V_16 -> V_17 ) ;
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
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_12 , bool V_21 )
{
union V_3 * V_14 = ++ ( V_12 -> V_22 ) ;
unsigned long long V_23 ;
V_12 -> V_24 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_25 , V_14 ) ) {
if ( V_21 && F_2 ( V_10 , V_12 , V_12 -> V_25 , V_14 ) ) {
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
if ( ! F_9 () )
F_10 ( V_10 , L_1 ,
V_12 ,
( unsigned int ) V_12 -> V_26 ) ;
}
V_12 -> V_25 = V_12 -> V_25 -> V_14 ;
V_12 -> V_22 = V_12 -> V_25 -> V_6 ;
V_14 = V_12 -> V_22 ;
}
V_23 = ( unsigned long long ) F_1 ( V_12 -> V_25 , V_12 -> V_22 ) ;
}
static void F_11 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_21 , bool V_27 )
{
T_2 V_28 ;
union V_3 * V_14 ;
unsigned long long V_23 ;
V_28 = F_3 ( V_12 -> V_20 -> V_29 . V_30 [ 3 ] ) & V_31 ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_32 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
if ( ! V_21 ) {
if ( V_12 != V_10 -> V_13 ) {
if ( ! V_28 && ! V_27 )
break;
if ( ! F_12 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_13 ( ~ V_31 ) ;
V_14 -> V_16 . V_17 |=
F_13 ( V_28 ) ;
}
F_14 () ;
V_14 -> V_16 . V_17 ^= F_13 ( V_34 ) ;
}
if ( F_2 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
if ( ! F_9 () )
F_10 ( V_10 , L_1 ,
V_12 ,
( unsigned int ) V_12 -> V_26 ) ;
}
}
V_12 -> V_33 = V_12 -> V_33 -> V_14 ;
V_12 -> V_20 = V_12 -> V_33 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
V_23 = ( unsigned long long ) F_1 ( V_12 -> V_33 , V_12 -> V_20 ) ;
}
static int F_15 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_35 )
{
int V_36 ;
union V_3 * V_37 = V_12 -> V_20 ;
struct V_1 * V_33 = V_12 -> V_33 ;
struct V_1 * V_38 ;
unsigned int V_39 ;
while ( F_4 ( V_10 , V_12 , V_33 , V_37 ) ) {
V_33 = V_33 -> V_14 ;
V_37 = V_33 -> V_6 ;
}
if ( V_37 == V_12 -> V_22 ) {
V_39 = V_7 - 1 ;
for ( V_38 = V_33 -> V_14 ; V_38 != V_33 ;
V_38 = V_38 -> V_14 )
V_39 += V_7 - 1 ;
V_39 -= 1 ;
if ( V_35 > V_39 ) {
F_16 ( V_10 , L_2
L_3 ,
V_35 , V_39 ) ;
return 0 ;
}
return 1 ;
}
for ( V_36 = 0 ; V_36 <= V_35 ; ++ V_36 ) {
if ( V_37 == V_12 -> V_22 )
return 0 ;
V_37 ++ ;
while ( F_4 ( V_10 , V_12 , V_33 , V_37 ) ) {
V_33 = V_33 -> V_14 ;
V_37 = V_33 -> V_6 ;
}
}
return 1 ;
}
void F_17 ( struct V_9 * V_10 )
{
F_10 ( V_10 , L_4 ) ;
F_18 ( V_10 , V_40 , & V_10 -> V_41 -> V_42 [ 0 ] ) ;
F_19 ( V_10 , & V_10 -> V_41 -> V_42 [ 0 ] ) ;
}
void F_20 ( struct V_9 * V_10 ,
unsigned int V_43 ,
unsigned int V_44 ,
unsigned int V_45 )
{
T_3 T_4 * V_46 = & V_10 -> V_41 -> V_42 [ V_43 ] ;
struct V_47 * V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
unsigned int V_51 = V_48 -> V_51 ;
if ( ( V_51 & V_52 ) || ( V_51 & V_53 ) ||
( V_51 & V_54 ) )
return;
F_18 ( V_10 , F_21 ( V_44 , V_45 ) , V_46 ) ;
}
static void F_22 ( struct V_9 * V_10 ,
unsigned int V_43 ,
unsigned int V_44 )
{
unsigned int V_45 ;
struct V_47 * V_48 ;
V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
if ( ! ( V_48 -> V_51 & V_55 ) ) {
if ( ! ( F_23 ( & V_48 -> V_12 -> V_56 ) ) )
F_20 ( V_10 , V_43 , V_44 , 0 ) ;
return;
}
for ( V_45 = 1 ; V_45 < V_48 -> V_57 -> V_58 ;
V_45 ++ ) {
struct V_59 * V_57 = V_48 -> V_57 ;
if ( ! F_23 ( & V_57 -> V_60 [ V_45 ] -> V_56 ) )
F_20 ( V_10 , V_43 , V_44 ,
V_45 ) ;
}
}
static struct V_1 * F_24 (
struct V_1 * V_61 ,
union V_3 * V_4 , int * V_26 )
{
struct V_1 * V_38 = V_61 ;
struct V_62 * V_63 ;
while ( V_38 -> V_6 > V_4 ||
& V_38 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_63 = & V_38 -> V_6 [ V_7 - 1 ] . V_29 ;
if ( V_63 -> V_30 [ 3 ] & F_13 ( V_18 ) )
* V_26 ^= 0x1 ;
V_38 = V_38 -> V_14 ;
if ( V_38 == V_61 )
return NULL ;
}
return V_38 ;
}
static struct V_11 * F_25 ( struct V_9 * V_10 ,
unsigned int V_43 , unsigned int V_44 ,
unsigned int V_45 )
{
struct V_47 * V_48 ;
V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
if ( ! ( V_48 -> V_51 & V_55 ) )
return V_48 -> V_12 ;
if ( V_45 == 0 ) {
F_16 ( V_10 ,
L_5
L_6 ,
V_43 , V_44 ) ;
return NULL ;
}
if ( V_45 < V_48 -> V_57 -> V_58 )
return V_48 -> V_57 -> V_60 [ V_45 ] ;
F_16 ( V_10 ,
L_7
L_8
L_9 ,
V_43 , V_44 ,
V_48 -> V_57 -> V_58 - 1 ,
V_45 ) ;
return NULL ;
}
static struct V_11 * F_26 ( struct V_9 * V_10 ,
struct V_64 * V_64 )
{
return F_25 ( V_10 , V_64 -> V_65 -> V_43 ,
F_27 ( & V_64 -> V_48 -> V_66 ) , V_64 -> V_45 ) ;
}
void F_28 ( struct V_9 * V_10 ,
unsigned int V_43 , unsigned int V_44 ,
unsigned int V_45 , struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_71 * V_65 = V_10 -> V_49 [ V_43 ] ;
struct V_11 * V_72 ;
struct V_62 * V_4 ;
struct V_73 * V_74 ;
T_1 V_23 ;
V_72 = F_25 ( V_10 , V_43 ,
V_44 , V_45 ) ;
if ( ! V_72 ) {
F_16 ( V_10 , L_10
L_11 ,
V_45 ) ;
return;
}
V_70 -> V_75 = 0 ;
F_10 ( V_10 , L_12 ) ;
V_70 -> V_76 = F_24 ( V_68 -> V_61 ,
V_65 -> V_50 [ V_44 ] . V_77 ,
& V_70 -> V_75 ) ;
if ( ! V_70 -> V_76 ) {
F_29 ( 1 ) ;
return;
}
F_10 ( V_10 , L_13 ) ;
V_74 = F_30 ( V_10 , V_65 -> V_78 , V_44 ) ;
V_70 -> V_75 = 0x1 & F_31 ( V_74 -> V_79 ) ;
V_70 -> V_80 = V_68 -> F_4 ;
F_10 ( V_10 , L_14 ) ;
V_70 -> V_76 = F_24 ( V_70 -> V_76 ,
V_70 -> V_80 ,
& V_70 -> V_75 ) ;
if ( ! V_70 -> V_76 ) {
F_29 ( 1 ) ;
return;
}
V_4 = & V_70 -> V_80 -> V_29 ;
if ( F_5 ( V_4 -> V_30 [ 3 ] ) &&
( V_4 -> V_30 [ 3 ] & F_13 ( V_18 ) ) )
V_70 -> V_75 ^= 0x1 ;
F_7 ( V_10 , V_72 , & V_70 -> V_76 , & V_70 -> V_80 ) ;
if ( V_72 -> V_15 == V_72 -> V_15 -> V_14 &&
V_70 -> V_80 < V_65 -> V_50 [ V_44 ] . V_77 )
V_70 -> V_75 ^= 0x1 ;
F_10 ( V_10 , L_15 , V_70 -> V_75 ) ;
F_10 ( V_10 , L_16 ,
V_70 -> V_76 ) ;
V_23 = F_1 ( V_70 -> V_76 , V_70 -> V_80 ) ;
F_10 ( V_10 , L_17 ,
( unsigned long long ) V_23 ) ;
}
static void F_32 ( struct V_9 * V_10 , struct V_11 * V_72 ,
struct V_67 * V_68 , bool V_81 )
{
struct V_1 * V_38 ;
union V_3 * V_82 ;
for ( V_38 = V_68 -> V_61 , V_82 = V_68 -> V_83 ;
true ;
F_7 ( V_10 , V_72 , & V_38 , & V_82 ) ) {
if ( F_5 ( V_82 -> V_29 . V_30 [ 3 ] ) ) {
V_82 -> V_29 . V_30 [ 3 ] &= F_13 ( ~ V_31 ) ;
if ( V_81 )
V_82 -> V_29 . V_30 [ 3 ] ^=
F_13 ( V_34 ) ;
F_10 ( V_10 , L_18 ) ;
F_10 ( V_10 , L_19
L_20 ,
V_82 ,
( unsigned long long ) F_1 ( V_38 , V_82 ) ,
V_38 ,
( unsigned long long ) V_38 -> V_8 ) ;
} else {
V_82 -> V_29 . V_30 [ 0 ] = 0 ;
V_82 -> V_29 . V_30 [ 1 ] = 0 ;
V_82 -> V_29 . V_30 [ 2 ] = 0 ;
V_82 -> V_29 . V_30 [ 3 ] &= F_13 ( V_34 ) ;
if ( V_81 && V_82 != V_68 -> V_83 &&
V_82 != V_68 -> F_4 )
V_82 -> V_29 . V_30 [ 3 ] ^=
F_13 ( V_34 ) ;
V_82 -> V_29 . V_30 [ 3 ] |= F_13 (
F_33 ( V_84 ) ) ;
F_10 ( V_10 , L_21
L_20 ,
V_82 ,
( unsigned long long ) F_1 ( V_38 , V_82 ) ,
V_38 ,
( unsigned long long ) V_38 -> V_8 ) ;
}
if ( V_82 == V_68 -> F_4 )
break;
}
}
void F_34 ( struct V_9 * V_10 ,
unsigned int V_43 , unsigned int V_44 ,
unsigned int V_45 ,
struct V_69 * V_85 )
{
struct V_47 * V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
F_10 ( V_10 , L_22
L_23 ,
V_85 -> V_76 ,
( unsigned long long ) V_85 -> V_76 -> V_8 ,
V_85 -> V_80 ,
( unsigned long long ) F_1 ( V_85 -> V_76 , V_85 -> V_80 ) ,
V_85 -> V_75 ) ;
F_35 ( V_10 , V_43 , V_44 , V_45 ,
V_85 -> V_76 ,
V_85 -> V_80 ,
( T_2 ) V_85 -> V_75 ) ;
V_48 -> V_51 |= V_53 ;
}
static void F_36 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
V_48 -> V_51 &= ~ V_52 ;
if ( F_37 ( & V_48 -> V_86 ) )
V_48 -> V_87 -- ;
}
static void F_38 ( struct V_9 * V_10 ,
struct V_67 * V_68 , int V_88 , char * V_89 )
{
struct V_90 * V_91 ;
struct V_64 * V_64 ;
struct V_92 * V_92 ;
V_64 = V_68 -> V_64 ;
V_92 = V_64 -> V_93 ;
V_92 -> V_94 ++ ;
V_91 = F_39 ( V_64 -> V_65 -> V_95 ) ;
if ( V_92 -> V_94 == V_92 -> V_96 ) {
if ( F_40 ( V_64 -> V_97 ) == V_98 ) {
F_41 ( V_10 ) -> V_99 . V_100 -- ;
if ( F_41 ( V_10 ) -> V_99 . V_100 == 0 ) {
if ( V_10 -> V_101 & V_102 )
F_42 () ;
}
}
F_43 ( V_91 , V_64 ) ;
F_44 ( & V_10 -> V_103 ) ;
F_45 ( V_91 , V_64 , V_88 ) ;
F_46 ( V_10 , V_92 ) ;
F_47 ( & V_10 -> V_103 ) ;
}
}
static void F_48 ( struct V_9 * V_10 ,
union V_3 * V_4 , struct V_104 * V_105 )
{
unsigned int V_43 ;
unsigned int V_44 ;
struct V_71 * V_106 ;
struct V_11 * V_72 ;
struct V_47 * V_48 ;
struct V_107 * V_108 ;
struct V_67 * V_68 = NULL ;
struct V_67 * V_109 ;
struct V_69 V_85 ;
if ( F_49 ( F_50 (
F_3 ( V_10 -> V_110 -> V_22 -> V_29 . V_30 [ 3 ] ) ) ) ) {
V_43 = F_51 (
F_3 ( V_10 -> V_110 -> V_22 -> V_29 . V_30 [ 3 ] ) ) ;
V_106 = V_10 -> V_49 [ V_43 ] ;
if ( V_106 )
F_52 ( V_10 , V_106 ,
V_105 ) ;
else
F_16 ( V_10 , L_24
L_25 ,
V_43 ) ;
return;
}
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_43 = F_51 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_44 = F_53 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
if ( F_23 ( & V_48 -> V_111 ) ) {
F_36 ( V_10 , V_48 ) ;
V_48 -> V_112 = NULL ;
V_48 -> V_77 = NULL ;
F_22 ( V_10 , V_43 , V_44 ) ;
return;
}
F_54 (entry, &ep->cancelled_td_list) {
V_68 = F_55 ( V_108 , struct V_67 , V_111 ) ;
F_10 ( V_10 , L_26 ,
V_68 -> V_83 ,
( unsigned long long ) F_1 ( V_68 -> V_61 , V_68 -> V_83 ) ) ;
V_72 = F_26 ( V_10 , V_68 -> V_64 ) ;
if ( ! V_72 ) {
F_16 ( V_10 , L_27
L_28 ,
V_68 -> V_64 ,
V_68 -> V_64 -> V_45 ) ;
goto V_113;
}
if ( V_68 == V_48 -> V_112 )
F_28 ( V_10 , V_43 , V_44 ,
V_68 -> V_64 -> V_45 ,
V_68 , & V_85 ) ;
else
F_32 ( V_10 , V_72 , V_68 , false ) ;
V_113:
F_56 ( & V_68 -> V_56 ) ;
}
V_109 = V_68 ;
F_36 ( V_10 , V_48 ) ;
if ( V_85 . V_80 && V_85 . V_76 ) {
F_34 ( V_10 ,
V_43 , V_44 ,
V_48 -> V_112 -> V_64 -> V_45 ,
& V_85 ) ;
F_17 ( V_10 ) ;
} else {
F_22 ( V_10 , V_43 , V_44 ) ;
}
V_48 -> V_112 = NULL ;
V_48 -> V_77 = NULL ;
do {
V_68 = F_55 ( V_48 -> V_111 . V_14 ,
struct V_67 , V_111 ) ;
F_56 ( & V_68 -> V_111 ) ;
F_38 ( V_10 , V_68 , 0 , L_29 ) ;
if ( V_10 -> V_114 & V_115 )
return;
} while ( V_68 != V_109 );
}
void F_57 ( unsigned long V_116 )
{
struct V_9 * V_10 ;
struct V_47 * V_48 ;
struct V_47 * V_117 ;
struct V_11 * V_12 ;
struct V_67 * V_68 ;
int V_118 , V_36 , V_119 ;
V_48 = (struct V_47 * ) V_116 ;
V_10 = V_48 -> V_10 ;
F_47 ( & V_10 -> V_103 ) ;
V_48 -> V_87 -- ;
if ( V_10 -> V_114 & V_115 ) {
F_10 ( V_10 , L_30
L_31 ) ;
F_44 ( & V_10 -> V_103 ) ;
return;
}
if ( ! ( V_48 -> V_87 == 0 && ( V_48 -> V_51 & V_52 ) ) ) {
F_10 ( V_10 , L_32
L_33 ) ;
F_44 ( & V_10 -> V_103 ) ;
return;
}
F_16 ( V_10 , L_34 ) ;
F_16 ( V_10 , L_35 ) ;
V_10 -> V_114 |= V_115 ;
F_58 ( V_10 ) ;
F_44 ( & V_10 -> V_103 ) ;
V_118 = F_59 ( V_10 ) ;
F_47 ( & V_10 -> V_103 ) ;
if ( V_118 < 0 ) {
F_16 ( V_10 , L_36 ) ;
F_16 ( V_10 , L_37 ) ;
}
for ( V_36 = 0 ; V_36 < V_120 ; V_36 ++ ) {
if ( ! V_10 -> V_49 [ V_36 ] )
continue;
for ( V_119 = 0 ; V_119 < 31 ; V_119 ++ ) {
V_117 = & V_10 -> V_49 [ V_36 ] -> V_50 [ V_119 ] ;
V_12 = V_117 -> V_12 ;
if ( ! V_12 )
continue;
F_10 ( V_10 , L_38
L_39 , V_36 , V_119 ) ;
while ( ! F_23 ( & V_12 -> V_56 ) ) {
V_68 = F_60 ( & V_12 -> V_56 ,
struct V_67 ,
V_56 ) ;
F_56 ( & V_68 -> V_56 ) ;
if ( ! F_23 ( & V_68 -> V_111 ) )
F_56 ( & V_68 -> V_111 ) ;
F_38 ( V_10 , V_68 ,
- V_121 , L_40 ) ;
}
while ( ! F_23 ( & V_117 -> V_111 ) ) {
V_68 = F_60 (
& V_117 -> V_111 ,
struct V_67 ,
V_111 ) ;
F_56 ( & V_68 -> V_111 ) ;
F_38 ( V_10 , V_68 ,
- V_121 , L_40 ) ;
}
}
}
F_44 ( & V_10 -> V_103 ) ;
F_10 ( V_10 , L_41 ) ;
F_61 ( F_41 ( V_10 ) -> V_122 ) ;
F_10 ( V_10 , L_42 ) ;
}
static void F_62 ( struct V_9 * V_10 ,
struct V_104 * V_105 ,
union V_3 * V_4 )
{
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
struct V_11 * V_72 ;
struct V_71 * V_65 ;
struct V_73 * V_74 ;
struct V_123 * V_124 ;
V_43 = F_51 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_44 = F_53 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_45 = F_63 ( F_3 ( V_4 -> V_29 . V_30 [ 2 ] ) ) ;
V_65 = V_10 -> V_49 [ V_43 ] ;
V_72 = F_64 ( V_65 , V_44 , V_45 ) ;
if ( ! V_72 ) {
F_16 ( V_10 , L_43
L_44 ,
V_45 ) ;
V_65 -> V_50 [ V_44 ] . V_51 &= ~ V_53 ;
return;
}
V_74 = F_30 ( V_10 , V_65 -> V_78 , V_44 ) ;
V_124 = F_65 ( V_10 , V_65 -> V_78 ) ;
if ( F_66 ( F_3 ( V_105 -> V_88 ) ) != V_125 ) {
unsigned int V_51 ;
unsigned int V_126 ;
switch ( F_66 ( F_3 ( V_105 -> V_88 ) ) ) {
case V_127 :
F_16 ( V_10 , L_45
L_46 ) ;
break;
case V_128 :
F_16 ( V_10 , L_47
L_48 ) ;
V_51 = F_3 ( V_74 -> V_129 ) ;
V_51 &= V_130 ;
V_126 = F_3 ( V_124 -> V_131 ) ;
V_126 = F_67 ( V_126 ) ;
F_10 ( V_10 , L_49 ,
V_126 , V_51 ) ;
break;
case V_132 :
F_16 ( V_10 , L_50
L_51 , V_43 ) ;
break;
default:
F_16 ( V_10 , L_52
L_53 ,
F_66 ( F_3 ( V_105 -> V_88 ) ) ) ;
break;
}
} else {
F_10 ( V_10 , L_54 ,
F_31 ( V_74 -> V_79 ) ) ;
if ( F_1 ( V_65 -> V_50 [ V_44 ] . V_133 ,
V_65 -> V_50 [ V_44 ] . V_134 ) ==
( F_31 ( V_74 -> V_79 ) & ~ ( V_135 ) ) ) {
V_72 -> V_25 = V_65 -> V_50 [ V_44 ] . V_133 ;
V_72 -> V_22 = V_65 -> V_50 [ V_44 ] . V_134 ;
} else {
F_16 ( V_10 , L_55
L_56 ) ;
F_16 ( V_10 , L_57 ,
V_65 -> V_50 [ V_44 ] . V_133 ,
V_65 -> V_50 [ V_44 ] . V_134 ) ;
}
}
V_65 -> V_50 [ V_44 ] . V_51 &= ~ V_53 ;
V_65 -> V_50 [ V_44 ] . V_133 = NULL ;
V_65 -> V_50 [ V_44 ] . V_134 = NULL ;
F_22 ( V_10 , V_43 , V_44 ) ;
}
static void F_68 ( struct V_9 * V_10 ,
struct V_104 * V_105 ,
union V_3 * V_4 )
{
int V_43 ;
unsigned int V_44 ;
V_43 = F_51 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_44 = F_53 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
F_10 ( V_10 , L_58 ,
F_66 ( F_3 ( V_105 -> V_88 ) ) ) ;
if ( V_10 -> V_101 & V_136 ) {
F_10 ( V_10 , L_59 ) ;
F_69 ( V_10 ,
V_10 -> V_49 [ V_43 ] -> V_137 -> V_8 , V_43 ,
false ) ;
F_17 ( V_10 ) ;
} else {
V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] . V_51 &= ~ V_54 ;
F_22 ( V_10 , V_43 , V_44 ) ;
}
}
static int F_52 ( struct V_9 * V_10 ,
struct V_71 * V_106 ,
struct V_104 * V_105 )
{
struct V_138 * V_139 ;
if ( F_23 ( & V_106 -> V_140 ) )
return 0 ;
V_139 = F_55 ( V_106 -> V_140 . V_14 ,
struct V_138 , V_140 ) ;
if ( V_10 -> V_110 -> V_22 != V_139 -> V_141 )
return 0 ;
V_139 -> V_88 = F_66 ( F_3 ( V_105 -> V_88 ) ) ;
F_70 ( & V_139 -> V_140 ) ;
if ( V_139 -> V_142 )
F_71 ( V_139 -> V_142 ) ;
else
F_72 ( V_10 , V_139 ) ;
return 1 ;
}
static void F_73 ( struct V_9 * V_10 ,
struct V_104 * V_105 )
{
int V_43 = F_51 ( F_3 ( V_105 -> V_143 ) ) ;
T_5 V_144 ;
T_1 V_145 ;
struct V_146 * V_147 ;
struct V_71 * V_106 ;
unsigned int V_44 ;
struct V_11 * V_72 ;
unsigned int V_51 ;
V_144 = F_31 ( V_105 -> V_148 ) ;
V_145 = F_1 ( V_10 -> V_110 -> V_25 ,
V_10 -> V_110 -> V_22 ) ;
if ( V_145 == 0 ) {
V_10 -> V_149 |= 1 << 4 ;
return;
}
if ( V_144 != ( T_5 ) V_145 ) {
V_10 -> V_149 |= 1 << 5 ;
return;
}
switch ( F_3 ( V_10 -> V_110 -> V_22 -> V_29 . V_30 [ 3 ] )
& V_150 ) {
case F_33 ( V_151 ) :
if ( F_66 ( F_3 ( V_105 -> V_88 ) ) == V_125 )
V_10 -> V_43 = V_43 ;
else
V_10 -> V_43 = 0 ;
F_71 ( & V_10 -> V_152 ) ;
break;
case F_33 ( V_153 ) :
if ( V_10 -> V_49 [ V_43 ] ) {
if ( V_10 -> V_101 & V_154 )
F_74 ( V_10 ,
V_10 -> V_49 [ V_43 ] , true ) ;
F_75 ( V_10 , V_43 ) ;
}
break;
case F_33 ( V_155 ) :
V_106 = V_10 -> V_49 [ V_43 ] ;
if ( F_52 ( V_10 , V_106 , V_105 ) )
break;
V_147 = F_76 ( V_10 ,
V_106 -> V_137 ) ;
V_44 = F_77 ( F_3 ( V_147 -> V_156 ) ) - 1 ;
if ( V_10 -> V_101 & V_136 &&
V_44 != ( unsigned int ) - 1 &&
F_3 ( V_147 -> V_156 ) - V_157 ==
F_3 ( V_147 -> V_158 ) ) {
V_72 = V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] . V_12 ;
V_51 = V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] . V_51 ;
if ( ! ( V_51 & V_54 ) )
goto V_159;
F_10 ( V_10 , L_60
L_61 ,
V_44 , V_51 ) ;
V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] . V_51 &=
~ V_54 ;
F_22 ( V_10 , V_43 , V_44 ) ;
break;
}
V_159:
F_10 ( V_10 , L_62 ) ;
V_10 -> V_49 [ V_43 ] -> V_160 =
F_66 ( F_3 ( V_105 -> V_88 ) ) ;
F_71 ( & V_10 -> V_49 [ V_43 ] -> V_161 ) ;
break;
case F_33 ( V_162 ) :
V_106 = V_10 -> V_49 [ V_43 ] ;
if ( F_52 ( V_10 , V_106 , V_105 ) )
break;
V_10 -> V_49 [ V_43 ] -> V_160 = F_66 ( F_3 ( V_105 -> V_88 ) ) ;
F_71 ( & V_10 -> V_49 [ V_43 ] -> V_161 ) ;
break;
case F_33 ( V_163 ) :
V_10 -> V_49 [ V_43 ] -> V_160 = F_66 ( F_3 ( V_105 -> V_88 ) ) ;
F_71 ( & V_10 -> V_152 ) ;
break;
case F_33 ( V_164 ) :
F_48 ( V_10 , V_10 -> V_110 -> V_22 , V_105 ) ;
break;
case F_33 ( V_165 ) :
F_62 ( V_10 , V_105 , V_10 -> V_110 -> V_22 ) ;
break;
case F_33 ( V_166 ) :
break;
case F_33 ( V_167 ) :
F_68 ( V_10 , V_105 , V_10 -> V_110 -> V_22 ) ;
break;
case F_33 ( V_168 ) :
F_10 ( V_10 , L_63 ) ;
V_43 = F_51 (
F_3 ( V_10 -> V_110 -> V_22 -> V_29 . V_30 [ 3 ] ) ) ;
V_106 = V_10 -> V_49 [ V_43 ] ;
if ( V_106 )
F_52 ( V_10 , V_106 , V_105 ) ;
else
F_16 ( V_10 , L_64
L_65 , V_43 ) ;
break;
case F_33 ( V_169 ) :
if ( ! ( V_10 -> V_101 & V_170 ) ) {
V_10 -> V_149 |= 1 << 6 ;
break;
}
F_10 ( V_10 , L_66 ,
F_78 ( F_3 ( V_105 -> V_88 ) ) ,
F_79 ( F_3 ( V_105 -> V_88 ) ) ) ;
break;
default:
V_10 -> V_149 |= 1 << 6 ;
break;
}
F_8 ( V_10 , V_10 -> V_110 , false ) ;
}
static void F_80 ( struct V_9 * V_10 ,
union V_3 * V_105 )
{
T_2 V_171 ;
V_171 = F_81 ( F_3 ( V_105 -> V_29 . V_30 [ 3 ] ) ) ;
F_10 ( V_10 , L_67 , V_171 ) ;
if ( V_171 == V_172 && ( V_10 -> V_101 & V_170 ) )
F_73 ( V_10 , & V_105 -> V_173 ) ;
}
static unsigned int F_82 ( struct V_90 * V_91 ,
struct V_9 * V_10 , T_2 V_174 )
{
unsigned int V_36 ;
unsigned int V_175 = 0 ;
for ( V_36 = 0 ; V_36 < ( V_174 - 1 ) ; V_36 ++ ) {
T_6 V_176 = V_10 -> V_177 [ V_36 ] ;
if ( V_176 == 0 || V_176 == V_178 )
continue;
if ( ( V_176 == 0x03 ) == ( V_91 -> V_179 == V_180 ) )
V_175 ++ ;
}
return V_175 ;
}
static void F_83 ( struct V_9 * V_10 ,
union V_3 * V_105 )
{
struct V_90 * V_91 ;
T_2 V_174 ;
T_2 V_181 , V_182 ;
int V_183 ;
int V_43 ;
unsigned int V_184 ;
T_6 V_185 ;
struct V_186 * V_187 ;
T_3 T_4 * * V_177 ;
bool V_188 = false ;
if ( F_66 ( F_3 ( V_105 -> V_29 . V_30 [ 2 ] ) ) != V_125 ) {
F_16 ( V_10 , L_68 ) ;
V_10 -> V_149 |= 1 << 8 ;
}
V_174 = F_84 ( F_3 ( V_105 -> V_29 . V_30 [ 0 ] ) ) ;
F_10 ( V_10 , L_69 , V_174 ) ;
V_183 = F_85 ( V_10 -> V_189 ) ;
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
V_91 = F_41 ( V_10 ) ;
if ( ( V_185 == 0x03 ) != ( V_91 -> V_179 == V_180 ) )
V_91 = V_10 -> V_191 ;
V_187 = & V_10 -> V_187 [ F_86 ( V_91 ) ] ;
if ( V_91 -> V_179 == V_180 )
V_177 = V_10 -> V_192 ;
else
V_177 = V_10 -> V_193 ;
V_184 = F_82 ( V_91 , V_10 ,
V_174 ) ;
V_181 = F_19 ( V_10 , V_177 [ V_184 ] ) ;
if ( V_91 -> V_70 == V_194 ) {
F_10 ( V_10 , L_74 ) ;
F_87 ( V_91 ) ;
}
if ( ( V_181 & V_195 ) && ( V_181 & V_196 ) == V_197 ) {
F_10 ( V_10 , L_75 , V_174 ) ;
V_182 = F_19 ( V_10 , & V_10 -> V_198 -> V_139 ) ;
if ( ! ( V_182 & V_199 ) ) {
F_16 ( V_10 , L_76 ) ;
goto V_190;
}
if ( F_88 ( V_181 ) ) {
F_10 ( V_10 , L_77 , V_174 ) ;
V_181 = F_89 ( V_181 ) ;
V_181 &= ~ V_196 ;
V_181 |= V_200 | V_201 ;
F_18 ( V_10 , V_181 , V_177 [ V_184 ] ) ;
V_43 = F_90 ( V_91 , V_10 ,
V_184 ) ;
if ( ! V_43 ) {
F_10 ( V_10 , L_78 ) ;
goto V_190;
}
F_91 ( V_10 , V_43 ) ;
F_10 ( V_10 , L_79 , V_174 ) ;
V_181 = F_19 ( V_10 , V_177 [ V_184 ] ) ;
V_181 = F_89 ( V_181 ) ;
V_181 |= V_195 ;
F_18 ( V_10 , V_181 , V_177 [ V_184 ] ) ;
} else {
F_10 ( V_10 , L_80 , V_174 ) ;
V_187 -> V_202 [ V_184 ] = V_203 +
F_92 ( 20 ) ;
F_93 ( & V_91 -> V_204 ,
V_187 -> V_202 [ V_184 ] ) ;
}
}
V_190:
F_8 ( V_10 , V_10 -> V_13 , true ) ;
if ( V_188 )
return;
F_44 ( & V_10 -> V_103 ) ;
F_94 ( V_91 ) ;
F_47 ( & V_10 -> V_103 ) ;
}
struct V_1 * F_95 ( struct V_1 * V_61 ,
union V_3 * V_205 ,
union V_3 * V_206 ,
T_1 V_207 )
{
T_1 V_208 ;
T_1 V_209 ;
T_1 V_210 ;
struct V_1 * V_38 ;
V_208 = F_1 ( V_61 , V_205 ) ;
V_38 = V_61 ;
do {
if ( V_208 == 0 )
return NULL ;
V_209 = F_1 ( V_38 ,
& V_38 -> V_6 [ V_7 - 1 ] ) ;
V_210 = F_1 ( V_38 , V_206 ) ;
if ( V_210 > 0 ) {
if ( V_208 <= V_210 ) {
if ( V_207 >= V_208 && V_207 <= V_210 )
return V_38 ;
} else {
if ( ( V_207 >= V_208 &&
V_207 <= V_209 ) ||
( V_207 >= V_38 -> V_8 &&
V_207 <= V_210 ) )
return V_38 ;
}
return NULL ;
} else {
if ( V_207 >= V_208 && V_207 <= V_209 )
return V_38 ;
}
V_38 = V_38 -> V_14 ;
V_208 = F_1 ( V_38 , & V_38 -> V_6 [ 0 ] ) ;
} while ( V_38 != V_61 );
return NULL ;
}
static void F_96 ( struct V_9 * V_10 ,
unsigned int V_43 , unsigned int V_44 ,
unsigned int V_45 ,
struct V_67 * V_211 , union V_3 * V_212 )
{
struct V_47 * V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
V_48 -> V_51 |= V_54 ;
V_48 -> V_112 = V_211 ;
V_48 -> V_77 = V_212 ;
V_48 -> V_213 = V_45 ;
F_97 ( V_10 , V_43 , V_44 ) ;
F_98 ( V_10 , V_211 -> V_64 -> V_65 , V_44 ) ;
V_48 -> V_112 = NULL ;
V_48 -> V_77 = NULL ;
V_48 -> V_213 = 0 ;
F_17 ( V_10 ) ;
}
static int F_99 ( struct V_9 * V_10 ,
struct V_73 * V_74 ,
unsigned int V_214 )
{
if ( V_214 == V_215 ||
V_214 == V_216 ||
V_214 == V_217 )
if ( ( V_74 -> V_129 & F_13 ( V_130 ) ) ==
F_13 ( V_218 ) )
return 1 ;
return 0 ;
}
int F_100 ( struct V_9 * V_10 , unsigned int V_214 )
{
if ( V_214 >= 224 && V_214 <= 255 ) {
F_10 ( V_10 , L_81 ,
V_214 ) ;
F_10 ( V_10 , L_82 ) ;
return 1 ;
}
return 0 ;
}
static int F_101 ( struct V_9 * V_10 , struct V_67 * V_211 ,
union V_3 * V_212 , struct V_219 * V_105 ,
struct V_47 * V_48 , int * V_88 , bool V_220 )
{
struct V_71 * V_221 ;
struct V_11 * V_72 ;
unsigned int V_43 ;
int V_44 ;
struct V_64 * V_64 = NULL ;
struct V_73 * V_74 ;
int V_118 = 0 ;
struct V_92 * V_92 ;
T_2 V_214 ;
V_43 = F_51 ( F_3 ( V_105 -> V_143 ) ) ;
V_221 = V_10 -> V_49 [ V_43 ] ;
V_44 = F_102 ( F_3 ( V_105 -> V_143 ) ) - 1 ;
V_72 = F_103 ( V_48 , F_31 ( V_105 -> V_222 ) ) ;
V_74 = F_30 ( V_10 , V_221 -> V_78 , V_44 ) ;
V_214 = F_66 ( F_3 ( V_105 -> V_223 ) ) ;
if ( V_220 )
goto V_224;
if ( V_214 == V_225 ||
V_214 == V_226 ) {
V_48 -> V_112 = V_211 ;
V_48 -> V_77 = V_212 ;
return 0 ;
} else {
if ( V_214 == V_227 ) {
V_48 -> V_112 = V_211 ;
V_48 -> V_77 = V_212 ;
V_48 -> V_213 = V_72 -> V_45 ;
} else if ( F_99 ( V_10 ,
V_74 , V_214 ) ) {
F_96 ( V_10 ,
V_43 , V_44 , V_72 -> V_45 ,
V_211 , V_212 ) ;
} else {
while ( V_72 -> V_22 != V_211 -> F_4 )
F_8 ( V_10 , V_72 , false ) ;
F_8 ( V_10 , V_72 , false ) ;
}
V_224:
V_64 = V_211 -> V_64 ;
V_92 = V_64 -> V_93 ;
if ( V_64 -> V_228 > V_64 -> V_229 ) {
F_16 ( V_10 , L_83
L_84
L_85 ,
V_64 -> V_229 ,
V_64 -> V_228 ) ;
V_64 -> V_228 = 0 ;
if ( V_211 -> V_64 -> V_230 & V_231 )
* V_88 = - V_232 ;
else
* V_88 = 0 ;
}
F_56 ( & V_211 -> V_56 ) ;
if ( ! F_23 ( & V_211 -> V_111 ) )
F_56 ( & V_211 -> V_111 ) ;
V_92 -> V_94 ++ ;
if ( V_92 -> V_94 == V_92 -> V_96 ) {
V_118 = 1 ;
if ( F_40 ( V_64 -> V_97 ) == V_98 ) {
F_41 ( V_10 ) -> V_99 . V_100 -- ;
if ( F_41 ( V_10 ) -> V_99 . V_100
== 0 ) {
if ( V_10 -> V_101 & V_102 )
F_42 () ;
}
}
}
}
return V_118 ;
}
static int F_104 ( struct V_9 * V_10 , struct V_67 * V_211 ,
union V_3 * V_212 , struct V_219 * V_105 ,
struct V_47 * V_48 , int * V_88 )
{
struct V_71 * V_221 ;
struct V_11 * V_72 ;
unsigned int V_43 ;
int V_44 ;
struct V_73 * V_74 ;
T_2 V_214 ;
V_43 = F_51 ( F_3 ( V_105 -> V_143 ) ) ;
V_221 = V_10 -> V_49 [ V_43 ] ;
V_44 = F_102 ( F_3 ( V_105 -> V_143 ) ) - 1 ;
V_72 = F_103 ( V_48 , F_31 ( V_105 -> V_222 ) ) ;
V_74 = F_30 ( V_10 , V_221 -> V_78 , V_44 ) ;
V_214 = F_66 ( F_3 ( V_105 -> V_223 ) ) ;
F_105 ( V_10 , V_10 -> V_13 -> V_22 ) ;
switch ( V_214 ) {
case V_125 :
if ( V_212 == V_72 -> V_22 ) {
F_16 ( V_10 , L_86
L_87 ) ;
* V_88 = - V_121 ;
} else if ( V_212 != V_211 -> F_4 ) {
F_16 ( V_10 , L_88
L_87 ) ;
* V_88 = - V_121 ;
} else {
* V_88 = 0 ;
}
break;
case V_233 :
F_16 ( V_10 , L_89 ) ;
if ( V_211 -> V_64 -> V_230 & V_231 )
* V_88 = - V_232 ;
else
* V_88 = 0 ;
break;
case V_225 :
case V_226 :
return F_101 ( V_10 , V_211 , V_212 , V_105 , V_48 , V_88 , false ) ;
default:
if ( ! F_99 ( V_10 ,
V_74 , V_214 ) )
break;
F_10 ( V_10 , L_90
L_91 ,
V_214 , V_44 ) ;
case V_227 :
if ( V_212 != V_72 -> V_22 &&
V_212 != V_211 -> F_4 )
V_211 -> V_64 -> V_228 =
V_211 -> V_64 -> V_229
- F_106 ( F_3 ( V_105 -> V_223 ) ) ;
else
V_211 -> V_64 -> V_228 = 0 ;
F_96 ( V_10 ,
V_43 , V_44 , 0 , V_211 , V_212 ) ;
return F_101 ( V_10 , V_211 , V_212 , V_105 , V_48 , V_88 , true ) ;
}
if ( V_212 != V_72 -> V_22 ) {
if ( V_212 == V_211 -> F_4 ) {
if ( V_211 -> V_64 -> V_228 != 0 ) {
if ( ( * V_88 == - V_234 || * V_88 == 0 ) &&
( V_211 -> V_64 -> V_230
& V_231 ) )
* V_88 = - V_232 ;
} else {
V_211 -> V_64 -> V_228 =
V_211 -> V_64 -> V_229 ;
}
} else {
V_211 -> V_64 -> V_228 =
V_211 -> V_64 -> V_229 -
F_106 ( F_3 ( V_105 -> V_223 ) ) ;
F_10 ( V_10 , L_92
L_93 ) ;
return 0 ;
}
}
return F_101 ( V_10 , V_211 , V_212 , V_105 , V_48 , V_88 , false ) ;
}
static int F_107 ( struct V_9 * V_10 , struct V_67 * V_211 ,
union V_3 * V_212 , struct V_219 * V_105 ,
struct V_47 * V_48 , int * V_88 )
{
struct V_11 * V_72 ;
struct V_92 * V_92 ;
int V_235 ;
int V_236 = 0 ;
union V_3 * V_82 ;
struct V_1 * V_38 ;
struct V_237 * V_238 ;
T_2 V_214 ;
bool V_239 = false ;
V_72 = F_103 ( V_48 , F_31 ( V_105 -> V_222 ) ) ;
V_214 = F_66 ( F_3 ( V_105 -> V_223 ) ) ;
V_92 = V_211 -> V_64 -> V_93 ;
V_235 = V_92 -> V_94 ;
V_238 = & V_211 -> V_64 -> V_240 [ V_235 ] ;
switch ( V_214 ) {
case V_125 :
V_238 -> V_88 = 0 ;
break;
case V_233 :
V_238 -> V_88 = V_211 -> V_64 -> V_230 & V_231 ?
- V_232 : 0 ;
break;
case V_241 :
V_238 -> V_88 = - V_242 ;
V_239 = true ;
break;
case V_243 :
case V_216 :
V_238 -> V_88 = - V_244 ;
V_239 = true ;
break;
case V_245 :
case V_227 :
V_238 -> V_88 = - V_246 ;
V_239 = true ;
break;
case V_226 :
case V_225 :
break;
default:
V_238 -> V_88 = - 1 ;
break;
}
if ( V_214 == V_125 || V_239 ) {
V_238 -> V_228 = V_238 -> V_96 ;
V_211 -> V_64 -> V_228 += V_238 -> V_96 ;
} else {
for ( V_82 = V_72 -> V_22 ,
V_38 = V_72 -> V_25 ; V_82 != V_212 ;
F_7 ( V_10 , V_72 , & V_38 , & V_82 ) ) {
if ( ! F_108 ( V_82 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_82 -> V_29 . V_30 [ 3 ] ) )
V_236 += F_106 ( F_3 ( V_82 -> V_29 . V_30 [ 2 ] ) ) ;
}
V_236 += F_106 ( F_3 ( V_82 -> V_29 . V_30 [ 2 ] ) ) -
F_106 ( F_3 ( V_105 -> V_223 ) ) ;
if ( V_214 != V_225 ) {
V_238 -> V_228 = V_236 ;
V_211 -> V_64 -> V_228 += V_236 ;
}
}
return F_101 ( V_10 , V_211 , V_212 , V_105 , V_48 , V_88 , false ) ;
}
static int F_109 ( struct V_9 * V_10 , struct V_67 * V_211 ,
struct V_219 * V_105 ,
struct V_47 * V_48 , int * V_88 )
{
struct V_11 * V_72 ;
struct V_92 * V_92 ;
struct V_237 * V_238 ;
int V_235 ;
V_72 = F_103 ( V_48 , F_31 ( V_105 -> V_222 ) ) ;
V_92 = V_211 -> V_64 -> V_93 ;
V_235 = V_92 -> V_94 ;
V_238 = & V_211 -> V_64 -> V_240 [ V_235 ] ;
V_238 -> V_88 = - V_247 ;
V_238 -> V_228 = 0 ;
while ( V_72 -> V_22 != V_211 -> F_4 )
F_8 ( V_10 , V_72 , false ) ;
F_8 ( V_10 , V_72 , false ) ;
return F_101 ( V_10 , V_211 , NULL , V_105 , V_48 , V_88 , true ) ;
}
static int F_110 ( struct V_9 * V_10 , struct V_67 * V_211 ,
union V_3 * V_212 , struct V_219 * V_105 ,
struct V_47 * V_48 , int * V_88 )
{
struct V_11 * V_72 ;
union V_3 * V_82 ;
struct V_1 * V_38 ;
T_2 V_214 ;
V_72 = F_103 ( V_48 , F_31 ( V_105 -> V_222 ) ) ;
V_214 = F_66 ( F_3 ( V_105 -> V_223 ) ) ;
switch ( V_214 ) {
case V_125 :
if ( V_212 != V_211 -> F_4 ) {
F_16 ( V_10 , L_94
L_95 ) ;
if ( V_211 -> V_64 -> V_230 & V_231 )
* V_88 = - V_232 ;
else
* V_88 = 0 ;
} else {
* V_88 = 0 ;
}
break;
case V_233 :
if ( V_211 -> V_64 -> V_230 & V_231 )
* V_88 = - V_232 ;
else
* V_88 = 0 ;
break;
default:
break;
}
if ( V_214 == V_233 )
F_10 ( V_10 , L_96
L_97 ,
V_211 -> V_64 -> V_48 -> V_66 . V_248 ,
V_211 -> V_64 -> V_229 ,
F_106 ( F_3 ( V_105 -> V_223 ) ) ) ;
if ( V_212 == V_211 -> F_4 ) {
if ( F_106 ( F_3 ( V_105 -> V_223 ) ) != 0 ) {
V_211 -> V_64 -> V_228 =
V_211 -> V_64 -> V_229 -
F_106 ( F_3 ( V_105 -> V_223 ) ) ;
if ( V_211 -> V_64 -> V_229 <
V_211 -> V_64 -> V_228 ) {
F_16 ( V_10 , L_98
L_99 ,
F_106 ( F_3 ( V_105 -> V_223 ) ) ) ;
V_211 -> V_64 -> V_228 = 0 ;
if ( V_211 -> V_64 -> V_230 & V_231 )
* V_88 = - V_232 ;
else
* V_88 = 0 ;
}
if ( * V_88 == - V_234 ) {
if ( V_211 -> V_64 -> V_230 & V_231 )
* V_88 = - V_232 ;
else
* V_88 = 0 ;
}
} else {
V_211 -> V_64 -> V_228 =
V_211 -> V_64 -> V_229 ;
if ( * V_88 == - V_232 )
* V_88 = 0 ;
}
} else {
V_211 -> V_64 -> V_228 = 0 ;
for ( V_82 = V_72 -> V_22 , V_38 = V_72 -> V_25 ;
V_82 != V_212 ;
F_7 ( V_10 , V_72 , & V_38 , & V_82 ) ) {
if ( ! F_108 ( V_82 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_82 -> V_29 . V_30 [ 3 ] ) )
V_211 -> V_64 -> V_228 +=
F_106 ( F_3 ( V_82 -> V_29 . V_30 [ 2 ] ) ) ;
}
if ( V_214 != V_225 )
V_211 -> V_64 -> V_228 +=
F_106 ( F_3 ( V_82 -> V_29 . V_30 [ 2 ] ) ) -
F_106 ( F_3 ( V_105 -> V_223 ) ) ;
}
return F_101 ( V_10 , V_211 , V_212 , V_105 , V_48 , V_88 , false ) ;
}
static int F_111 ( struct V_9 * V_10 ,
struct V_219 * V_105 )
{
struct V_71 * V_221 ;
struct V_47 * V_48 ;
struct V_11 * V_72 ;
unsigned int V_43 ;
int V_44 ;
struct V_67 * V_211 = NULL ;
T_1 V_249 ;
struct V_1 * V_250 ;
union V_3 * V_212 ;
struct V_64 * V_64 = NULL ;
int V_88 = - V_234 ;
struct V_92 * V_92 ;
struct V_73 * V_74 ;
struct V_107 * V_251 ;
T_2 V_214 ;
int V_118 = 0 ;
int V_252 = 0 ;
V_43 = F_51 ( F_3 ( V_105 -> V_143 ) ) ;
V_221 = V_10 -> V_49 [ V_43 ] ;
if ( ! V_221 ) {
F_112 ( V_10 , L_100 ) ;
return - V_253 ;
}
V_44 = F_102 ( F_3 ( V_105 -> V_143 ) ) - 1 ;
V_48 = & V_221 -> V_50 [ V_44 ] ;
V_72 = F_103 ( V_48 , F_31 ( V_105 -> V_222 ) ) ;
V_74 = F_30 ( V_10 , V_221 -> V_78 , V_44 ) ;
if ( ! V_72 ||
( F_3 ( V_74 -> V_129 ) & V_130 ) ==
V_254 ) {
F_112 ( V_10 , L_101
L_102 ) ;
return - V_253 ;
}
if ( V_48 -> V_220 ) {
F_54 (tmp, &ep_ring->td_list)
V_252 ++ ;
}
V_249 = F_31 ( V_105 -> V_222 ) ;
V_214 = F_66 ( F_3 ( V_105 -> V_223 ) ) ;
switch ( V_214 ) {
case V_125 :
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
V_48 -> V_51 |= V_54 ;
V_88 = - V_255 ;
break;
case V_127 :
F_16 ( V_10 , L_106 ) ;
V_88 = - V_256 ;
break;
case V_217 :
case V_215 :
F_16 ( V_10 , L_107 ) ;
V_88 = - V_246 ;
break;
case V_216 :
F_16 ( V_10 , L_108 ) ;
V_88 = - V_244 ;
break;
case V_257 :
F_16 ( V_10 , L_109 ) ;
V_88 = - V_258 ;
break;
case V_241 :
F_16 ( V_10 , L_110 ) ;
break;
case V_243 :
F_16 ( V_10 , L_111 ) ;
break;
case V_259 :
F_10 ( V_10 , L_112 ) ;
if ( ! F_23 ( & V_72 -> V_56 ) )
F_10 ( V_10 , L_113
L_114 ,
F_51 ( F_3 ( V_105 -> V_143 ) ) ,
V_44 ) ;
goto V_190;
case V_260 :
F_10 ( V_10 , L_115 ) ;
if ( ! F_23 ( & V_72 -> V_56 ) )
F_10 ( V_10 , L_116
L_114 ,
F_51 ( F_3 ( V_105 -> V_143 ) ) ,
V_44 ) ;
goto V_190;
case V_245 :
F_16 ( V_10 , L_117 ) ;
V_88 = - V_246 ;
break;
case V_261 :
V_48 -> V_220 = true ;
F_10 ( V_10 , L_118 ) ;
goto V_190;
default:
if ( F_100 ( V_10 , V_214 ) ) {
V_88 = 0 ;
break;
}
F_16 ( V_10 , L_119
L_120 ) ;
goto V_190;
}
do {
if ( F_23 ( & V_72 -> V_56 ) ) {
F_16 ( V_10 , L_121
L_122 ,
F_51 ( F_3 ( V_105 -> V_143 ) ) ,
V_44 ) ;
F_10 ( V_10 , L_123 ,
( F_3 ( V_105 -> V_143 ) &
V_150 ) >> 10 ) ;
F_113 ( V_10 , (union V_3 * ) V_105 ) ;
if ( V_48 -> V_220 ) {
V_48 -> V_220 = false ;
F_10 ( V_10 , L_124
L_125 ) ;
}
V_118 = 0 ;
goto V_190;
}
if ( V_48 -> V_220 && V_252 == 0 ) {
V_48 -> V_220 = false ;
F_10 ( V_10 , L_126
L_127 ) ;
V_118 = 0 ;
goto V_190;
}
V_211 = F_55 ( V_72 -> V_56 . V_14 , struct V_67 , V_56 ) ;
if ( V_48 -> V_220 )
V_252 -- ;
V_250 = F_95 ( V_72 -> V_25 , V_72 -> V_22 ,
V_211 -> F_4 , V_249 ) ;
if ( ! V_250 && V_214 == V_225 ) {
V_118 = 0 ;
goto V_190;
}
if ( ! V_250 ) {
if ( ! V_48 -> V_220 ||
! F_114 ( & V_211 -> V_64 -> V_48 -> V_66 ) ) {
if ( ( V_10 -> V_101 & V_262 ) &&
V_72 -> V_263 ) {
V_72 -> V_263 = false ;
V_118 = 0 ;
goto V_190;
}
F_112 ( V_10 ,
L_128
L_129 ) ;
return - V_121 ;
}
V_118 = F_109 ( V_10 , V_211 , V_105 , V_48 , & V_88 ) ;
goto V_190;
}
if ( V_214 == V_233 )
V_72 -> V_263 = true ;
else
V_72 -> V_263 = false ;
if ( V_48 -> V_220 ) {
F_10 ( V_10 , L_130 ) ;
V_48 -> V_220 = false ;
}
V_212 = & V_250 -> V_6 [ ( V_249 - V_250 -> V_8 ) /
sizeof( * V_212 ) ] ;
if ( F_108 ( V_212 -> V_29 . V_30 [ 3 ] ) ) {
F_10 ( V_10 ,
L_131 ) ;
goto V_190;
}
if ( F_115 ( & V_211 -> V_64 -> V_48 -> V_66 ) )
V_118 = F_104 ( V_10 , V_211 , V_212 , V_105 , V_48 ,
& V_88 ) ;
else if ( F_114 ( & V_211 -> V_64 -> V_48 -> V_66 ) )
V_118 = F_107 ( V_10 , V_211 , V_212 , V_105 , V_48 ,
& V_88 ) ;
else
V_118 = F_110 ( V_10 , V_211 , V_212 , V_105 ,
V_48 , & V_88 ) ;
V_190:
if ( V_214 == V_261 || ! V_48 -> V_220 ) {
F_8 ( V_10 , V_10 -> V_13 , true ) ;
}
if ( V_118 ) {
V_64 = V_211 -> V_64 ;
V_92 = V_64 -> V_93 ;
if ( F_115 ( & V_64 -> V_48 -> V_66 ) ||
( V_214 != V_227 &&
V_214 != V_216 ) )
F_46 ( V_10 , V_92 ) ;
F_43 ( F_39 ( V_64 -> V_65 -> V_95 ) , V_64 ) ;
if ( ( V_64 -> V_228 != V_64 -> V_229 &&
( V_64 -> V_230 &
V_231 ) ) ||
V_88 != 0 )
F_10 ( V_10 , L_132
L_133 ,
V_64 , V_64 -> V_228 ,
V_64 -> V_229 ,
V_88 ) ;
F_44 ( & V_10 -> V_103 ) ;
if ( F_40 ( V_64 -> V_97 ) == V_98 )
V_88 = 0 ;
F_45 ( F_39 ( V_64 -> V_65 -> V_95 ) , V_64 , V_88 ) ;
F_47 ( & V_10 -> V_103 ) ;
}
} while ( V_48 -> V_220 && V_214 != V_261 );
return 0 ;
}
static int F_116 ( struct V_9 * V_10 )
{
union V_3 * V_105 ;
int V_264 = 1 ;
int V_118 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_22 ) {
V_10 -> V_149 |= 1 << 1 ;
return 0 ;
}
V_105 = V_10 -> V_13 -> V_22 ;
if ( ( F_3 ( V_105 -> V_173 . V_143 ) & V_34 ) !=
V_10 -> V_13 -> V_26 ) {
V_10 -> V_149 |= 1 << 2 ;
return 0 ;
}
F_117 () ;
switch ( ( F_3 ( V_105 -> V_173 . V_143 ) & V_150 ) ) {
case F_33 ( V_265 ) :
F_73 ( V_10 , & V_105 -> V_173 ) ;
break;
case F_33 ( V_266 ) :
F_83 ( V_10 , V_105 ) ;
V_264 = 0 ;
break;
case F_33 ( V_267 ) :
V_118 = F_111 ( V_10 , & V_105 -> V_268 ) ;
if ( V_118 < 0 )
V_10 -> V_149 |= 1 << 9 ;
else
V_264 = 0 ;
break;
default:
if ( ( F_3 ( V_105 -> V_173 . V_143 ) & V_150 ) >=
F_33 ( 48 ) )
F_80 ( V_10 , V_105 ) ;
else
V_10 -> V_149 |= 1 << 3 ;
}
if ( V_10 -> V_114 & V_115 ) {
F_10 ( V_10 , L_134
L_135 ) ;
return 0 ;
}
if ( V_264 )
F_8 ( V_10 , V_10 -> V_13 , true ) ;
return 1 ;
}
T_7 F_118 ( struct V_90 * V_91 )
{
struct V_9 * V_10 = F_119 ( V_91 ) ;
T_2 V_88 ;
union V_3 * V_4 ;
T_5 V_269 ;
union V_3 * V_270 ;
T_1 V_79 ;
F_47 ( & V_10 -> V_103 ) ;
V_4 = V_10 -> V_13 -> V_22 ;
V_88 = F_19 ( V_10 , & V_10 -> V_198 -> V_88 ) ;
if ( V_88 == 0xffffffff )
goto V_271;
if ( ! ( V_88 & V_272 ) ) {
F_44 ( & V_10 -> V_103 ) ;
return V_273 ;
}
if ( V_88 & V_274 ) {
F_16 ( V_10 , L_136 ) ;
F_59 ( V_10 ) ;
V_271:
F_44 ( & V_10 -> V_103 ) ;
return - V_121 ;
}
V_88 |= V_272 ;
F_18 ( V_10 , V_88 , & V_10 -> V_198 -> V_88 ) ;
if ( V_91 -> V_275 != - 1 ) {
T_2 V_276 ;
V_276 = F_19 ( V_10 , & V_10 -> V_277 -> V_276 ) ;
V_276 |= 0x3 ;
F_18 ( V_10 , V_276 , & V_10 -> V_277 -> V_276 ) ;
}
if ( V_10 -> V_114 & V_115 ) {
F_10 ( V_10 , L_137
L_138 ) ;
V_269 = F_120 ( V_10 , & V_10 -> V_277 -> V_278 ) ;
F_121 ( V_10 , V_269 | V_279 ,
& V_10 -> V_277 -> V_278 ) ;
F_44 ( & V_10 -> V_103 ) ;
return V_280 ;
}
V_270 = V_10 -> V_13 -> V_22 ;
while ( F_116 ( V_10 ) > 0 ) {}
V_269 = F_120 ( V_10 , & V_10 -> V_277 -> V_278 ) ;
if ( V_270 != V_10 -> V_13 -> V_22 ) {
V_79 = F_1 ( V_10 -> V_13 -> V_25 ,
V_10 -> V_13 -> V_22 ) ;
if ( V_79 == 0 )
F_16 ( V_10 , L_139
L_140 ) ;
V_269 &= V_281 ;
V_269 |= ( ( T_5 ) V_79 & ( T_5 ) ~ V_281 ) ;
}
V_269 |= V_279 ;
F_121 ( V_10 , V_269 , & V_10 -> V_277 -> V_278 ) ;
F_44 ( & V_10 -> V_103 ) ;
return V_280 ;
}
T_7 F_122 ( int V_275 , struct V_90 * V_91 )
{
T_7 V_118 ;
struct V_9 * V_10 ;
V_10 = F_119 ( V_91 ) ;
F_123 ( V_282 , & V_91 -> V_143 ) ;
if ( V_10 -> V_191 )
F_123 ( V_282 , & V_10 -> V_191 -> V_143 ) ;
V_118 = F_118 ( V_91 ) ;
return V_118 ;
}
static void F_124 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_21 , bool V_27 ,
T_2 V_283 , T_2 V_284 , T_2 V_285 , T_2 V_286 )
{
struct V_62 * V_4 ;
V_4 = & V_12 -> V_20 -> V_29 ;
V_4 -> V_30 [ 0 ] = F_13 ( V_283 ) ;
V_4 -> V_30 [ 1 ] = F_13 ( V_284 ) ;
V_4 -> V_30 [ 2 ] = F_13 ( V_285 ) ;
V_4 -> V_30 [ 3 ] = F_13 ( V_286 ) ;
F_11 ( V_10 , V_12 , V_21 , V_27 ) ;
}
static int F_125 ( struct V_9 * V_10 , struct V_11 * V_72 ,
T_2 V_51 , unsigned int V_35 , T_8 V_287 )
{
switch ( V_51 ) {
case V_254 :
F_16 ( V_10 , L_141 ) ;
return - V_288 ;
case V_289 :
F_16 ( V_10 , L_142 ) ;
return - V_290 ;
case V_218 :
F_10 ( V_10 , L_143 ) ;
case V_291 :
case V_292 :
break;
default:
F_112 ( V_10 , L_144 ) ;
return - V_290 ;
}
if ( ! F_15 ( V_10 , V_72 , V_35 ) ) {
F_112 ( V_10 , L_145 ) ;
return - V_293 ;
}
if ( F_6 ( V_72 ) ) {
struct V_11 * V_12 = V_72 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
if ( ! F_12 ( V_10 ) )
V_14 -> V_16 . V_17 &= F_13 ( ~ V_31 ) ;
else
V_14 -> V_16 . V_17 |= F_13 ( V_31 ) ;
F_14 () ;
V_14 -> V_16 . V_17 ^= F_13 ( V_34 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
if ( ! F_9 () ) {
F_10 ( V_10 , L_146
L_147 ,
V_12 , ( unsigned int ) V_12 -> V_26 ) ;
}
}
V_12 -> V_33 = V_12 -> V_33 -> V_14 ;
V_12 -> V_20 = V_12 -> V_33 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_126 ( struct V_9 * V_10 ,
struct V_71 * V_221 ,
unsigned int V_44 ,
unsigned int V_45 ,
unsigned int V_35 ,
struct V_64 * V_64 ,
unsigned int V_294 ,
T_8 V_287 )
{
int V_118 ;
struct V_92 * V_92 ;
struct V_67 * V_211 ;
struct V_11 * V_72 ;
struct V_73 * V_74 = F_30 ( V_10 , V_221 -> V_78 , V_44 ) ;
V_72 = F_64 ( V_221 , V_44 , V_45 ) ;
if ( ! V_72 ) {
F_10 ( V_10 , L_148 ,
V_45 ) ;
return - V_290 ;
}
V_118 = F_125 ( V_10 , V_72 ,
F_3 ( V_74 -> V_129 ) & V_130 ,
V_35 , V_287 ) ;
if ( V_118 )
return V_118 ;
V_92 = V_64 -> V_93 ;
V_211 = V_92 -> V_211 [ V_294 ] ;
F_127 ( & V_211 -> V_56 ) ;
F_127 ( & V_211 -> V_111 ) ;
if ( V_294 == 0 ) {
V_118 = F_128 ( F_39 ( V_64 -> V_65 -> V_95 ) , V_64 ) ;
if ( F_49 ( V_118 ) )
return V_118 ;
}
V_211 -> V_64 = V_64 ;
F_129 ( & V_211 -> V_56 , & V_72 -> V_56 ) ;
V_211 -> V_61 = V_72 -> V_33 ;
V_211 -> V_83 = V_72 -> V_20 ;
V_92 -> V_211 [ V_294 ] = V_211 ;
return 0 ;
}
static unsigned int F_130 ( struct V_9 * V_10 , struct V_64 * V_64 )
{
int V_295 , V_35 , V_296 , V_181 , V_36 ;
struct V_297 * V_298 ;
V_298 = NULL ;
V_295 = V_64 -> V_295 ;
V_181 = V_64 -> V_229 ;
F_10 ( V_10 , L_149 ) ;
V_35 = 0 ;
F_131 (urb->sg, sg, num_sgs, i) {
unsigned int V_299 = V_35 ;
unsigned int V_236 = F_132 ( V_298 ) ;
V_296 = V_300 -
( F_133 ( V_298 ) & ( V_300 - 1 ) ) ;
V_296 &= V_300 - 1 ;
if ( V_296 != 0 )
V_35 ++ ;
while ( V_296 < F_132 ( V_298 ) && V_296 < V_181 ) {
V_35 ++ ;
V_296 += V_300 ;
}
F_10 ( V_10 , L_150 ,
V_36 , ( unsigned long long ) F_133 ( V_298 ) ,
V_236 , V_236 , V_35 - V_299 ) ;
V_236 = F_134 ( int , V_236 , V_181 ) ;
V_181 -= V_236 ;
if ( V_181 == 0 )
break;
}
F_10 ( V_10 , L_151 ) ;
if ( ! F_9 () )
F_10 ( V_10 , L_152
L_153 ,
V_64 -> V_48 -> V_66 . V_248 ,
V_64 -> V_229 ,
V_35 ) ;
return V_35 ;
}
static void F_135 ( struct V_64 * V_64 , int V_35 , int V_296 )
{
if ( V_35 != 0 )
F_136 ( & V_64 -> V_65 -> V_65 , L_154
L_155 , V_301 ,
V_64 -> V_48 -> V_66 . V_248 , V_35 ) ;
if ( V_296 != V_64 -> V_229 )
F_136 ( & V_64 -> V_65 -> V_65 , L_156
L_157 ,
V_301 ,
V_64 -> V_48 -> V_66 . V_248 ,
V_296 , V_296 ,
V_64 -> V_229 ,
V_64 -> V_229 ) ;
}
static void F_137 ( struct V_9 * V_10 , int V_43 ,
unsigned int V_44 , unsigned int V_45 , int V_302 ,
struct V_62 * V_205 )
{
F_14 () ;
if ( V_302 )
V_205 -> V_30 [ 3 ] |= F_13 ( V_302 ) ;
else
V_205 -> V_30 [ 3 ] &= F_13 ( ~ V_34 ) ;
F_20 ( V_10 , V_43 , V_44 , V_45 ) ;
}
int F_138 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_64 * V_64 , int V_43 , unsigned int V_44 )
{
struct V_73 * V_74 = F_30 ( V_10 ,
V_10 -> V_49 [ V_43 ] -> V_78 , V_44 ) ;
int V_303 ;
int V_304 ;
V_303 = F_139 ( F_3 ( V_74 -> V_129 ) ) ;
V_304 = V_64 -> V_305 ;
if ( V_64 -> V_65 -> V_179 == V_306 ||
V_64 -> V_65 -> V_179 == V_307 )
V_304 *= 8 ;
if ( V_303 != V_304 ) {
if ( F_140 () )
F_141 ( & V_64 -> V_65 -> V_65 , L_158
L_159
L_160 ,
V_304 ,
V_304 == 1 ? L_161 : L_162 ,
V_303 ,
V_303 == 1 ? L_161 : L_162 ) ;
V_64 -> V_305 = V_303 ;
if ( V_64 -> V_65 -> V_179 == V_306 ||
V_64 -> V_65 -> V_179 == V_307 )
V_64 -> V_305 /= 8 ;
}
return F_142 ( V_10 , V_308 , V_64 , V_43 , V_44 ) ;
}
static T_2 F_143 ( unsigned int V_309 )
{
T_2 V_310 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_309 >> 10 ) >= V_310 )
return V_310 << 17 ;
else
return ( V_309 >> 10 ) << 17 ;
}
static T_2 F_144 ( int V_296 , int V_311 ,
unsigned int V_312 , struct V_64 * V_64 )
{
int V_313 ;
if ( V_296 == 0 && V_311 == 0 )
return 0 ;
V_313 = ( V_296 + V_311 ) /
F_145 ( V_64 -> V_48 -> V_66 . V_314 ) ;
return F_143 ( V_312 - V_313 ) ;
}
static int F_146 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_64 * V_64 , int V_43 , unsigned int V_44 )
{
struct V_11 * V_72 ;
unsigned int V_35 ;
struct V_92 * V_92 ;
struct V_67 * V_211 ;
struct V_297 * V_298 ;
int V_295 ;
int V_311 , V_315 , V_296 ;
unsigned int V_312 ;
bool V_83 ;
T_5 V_23 ;
bool V_27 ;
struct V_62 * V_205 ;
int V_302 ;
V_72 = F_26 ( V_10 , V_64 ) ;
if ( ! V_72 )
return - V_290 ;
V_35 = F_130 ( V_10 , V_64 ) ;
V_295 = V_64 -> V_295 ;
V_312 = F_147 ( V_64 -> V_229 ,
F_145 ( V_64 -> V_48 -> V_66 . V_314 ) ) ;
V_311 = F_126 ( V_10 , V_10 -> V_49 [ V_43 ] ,
V_44 , V_64 -> V_45 ,
V_35 , V_64 , 0 , V_287 ) ;
if ( V_311 < 0 )
return V_311 ;
V_92 = V_64 -> V_93 ;
V_211 = V_92 -> V_211 [ 0 ] ;
V_205 = & V_72 -> V_20 -> V_29 ;
V_302 = V_72 -> V_26 ;
V_296 = 0 ;
V_298 = V_64 -> V_298 ;
V_23 = ( T_5 ) F_133 ( V_298 ) ;
V_315 = F_132 ( V_298 ) ;
V_311 = V_300 - ( V_23 & ( V_300 - 1 ) ) ;
V_311 = F_134 ( int , V_311 , V_315 ) ;
if ( V_311 > V_64 -> V_229 )
V_311 = V_64 -> V_229 ;
F_10 ( V_10 , L_163 ,
V_311 ) ;
V_83 = true ;
do {
T_2 V_30 = 0 ;
T_2 V_316 = 0 ;
T_2 V_309 = 0 ;
if ( V_83 ) {
V_83 = false ;
if ( V_302 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_72 -> V_26 ;
if ( V_35 > 1 ) {
V_30 |= V_31 ;
} else {
V_211 -> F_4 = V_72 -> V_20 ;
V_30 |= V_317 ;
}
if ( F_148 ( V_64 ) )
V_30 |= V_318 ;
F_10 ( V_10 , L_164
L_165 ,
( unsigned int ) V_23 , V_311 , V_311 ,
( unsigned int ) ( V_23 + V_300 ) & ~ ( V_300 - 1 ) ,
( unsigned int ) V_23 + V_311 ) ;
if ( V_300 -
( V_23 & ( V_300 - 1 ) ) < V_311 ) {
F_16 ( V_10 , L_166 ) ;
F_10 ( V_10 , L_167 ,
( unsigned int ) ( V_23 + V_300 ) & ~ ( V_300 - 1 ) ,
( unsigned int ) V_23 + V_311 ) ;
}
if ( V_10 -> V_319 < 0x100 ) {
V_309 = F_143 (
V_64 -> V_229 -
V_296 ) ;
} else {
V_309 = F_144 ( V_296 ,
V_311 , V_312 , V_64 ) ;
}
V_316 = F_106 ( V_311 ) |
V_309 |
F_149 ( 0 ) ;
if ( V_35 > 1 )
V_27 = true ;
else
V_27 = false ;
F_124 ( V_10 , V_72 , false , V_27 ,
F_150 ( V_23 ) ,
F_151 ( V_23 ) ,
V_316 ,
V_30 | F_33 ( V_320 ) ) ;
-- V_35 ;
V_296 += V_311 ;
V_315 -= V_311 ;
if ( V_315 == 0 ) {
-- V_295 ;
if ( V_295 == 0 )
break;
V_298 = F_152 ( V_298 ) ;
V_23 = ( T_5 ) F_133 ( V_298 ) ;
V_315 = F_132 ( V_298 ) ;
} else {
V_23 += V_311 ;
}
V_311 = V_300 -
( V_23 & ( V_300 - 1 ) ) ;
V_311 = F_134 ( int , V_311 , V_315 ) ;
if ( V_296 + V_311 > V_64 -> V_229 )
V_311 =
V_64 -> V_229 - V_296 ;
} while ( V_296 < V_64 -> V_229 );
F_135 ( V_64 , V_35 , V_296 ) ;
F_137 ( V_10 , V_43 , V_44 , V_64 -> V_45 ,
V_302 , V_205 ) ;
return 0 ;
}
int F_142 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_64 * V_64 , int V_43 , unsigned int V_44 )
{
struct V_11 * V_72 ;
struct V_92 * V_92 ;
struct V_67 * V_211 ;
int V_35 ;
struct V_62 * V_205 ;
bool V_83 ;
bool V_27 ;
int V_302 ;
T_2 V_30 , V_316 ;
int V_296 , V_311 , V_118 ;
unsigned int V_312 ;
T_5 V_23 ;
if ( V_64 -> V_295 )
return F_146 ( V_10 , V_287 , V_64 , V_43 , V_44 ) ;
V_72 = F_26 ( V_10 , V_64 ) ;
if ( ! V_72 )
return - V_290 ;
V_35 = 0 ;
V_296 = V_300 -
( V_64 -> V_321 & ( V_300 - 1 ) ) ;
V_296 &= V_300 - 1 ;
if ( V_296 != 0 || V_64 -> V_229 == 0 )
V_35 ++ ;
while ( V_296 < V_64 -> V_229 ) {
V_35 ++ ;
V_296 += V_300 ;
}
if ( ! F_9 () )
F_10 ( V_10 , L_168
L_169 ,
V_64 -> V_48 -> V_66 . V_248 ,
V_64 -> V_229 ,
V_64 -> V_229 ,
( unsigned long long ) V_64 -> V_321 ,
V_35 ) ;
V_118 = F_126 ( V_10 , V_10 -> V_49 [ V_43 ] ,
V_44 , V_64 -> V_45 ,
V_35 , V_64 , 0 , V_287 ) ;
if ( V_118 < 0 )
return V_118 ;
V_92 = V_64 -> V_93 ;
V_211 = V_92 -> V_211 [ 0 ] ;
V_205 = & V_72 -> V_20 -> V_29 ;
V_302 = V_72 -> V_26 ;
V_296 = 0 ;
V_312 = F_147 ( V_64 -> V_229 ,
F_145 ( V_64 -> V_48 -> V_66 . V_314 ) ) ;
V_23 = ( T_5 ) V_64 -> V_321 ;
V_311 = V_300 -
( V_64 -> V_321 & ( V_300 - 1 ) ) ;
if ( V_311 > V_64 -> V_229 )
V_311 = V_64 -> V_229 ;
V_83 = true ;
do {
T_2 V_309 = 0 ;
V_30 = 0 ;
if ( V_83 ) {
V_83 = false ;
if ( V_302 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_72 -> V_26 ;
if ( V_35 > 1 ) {
V_30 |= V_31 ;
} else {
V_211 -> F_4 = V_72 -> V_20 ;
V_30 |= V_317 ;
}
if ( F_148 ( V_64 ) )
V_30 |= V_318 ;
if ( V_10 -> V_319 < 0x100 ) {
V_309 = F_143 (
V_64 -> V_229 -
V_296 ) ;
} else {
V_309 = F_144 ( V_296 ,
V_311 , V_312 , V_64 ) ;
}
V_316 = F_106 ( V_311 ) |
V_309 |
F_149 ( 0 ) ;
if ( V_35 > 1 )
V_27 = true ;
else
V_27 = false ;
F_124 ( V_10 , V_72 , false , V_27 ,
F_150 ( V_23 ) ,
F_151 ( V_23 ) ,
V_316 ,
V_30 | F_33 ( V_320 ) ) ;
-- V_35 ;
V_296 += V_311 ;
V_23 += V_311 ;
V_311 = V_64 -> V_229 - V_296 ;
if ( V_311 > V_300 )
V_311 = V_300 ;
} while ( V_296 < V_64 -> V_229 );
F_135 ( V_64 , V_35 , V_296 ) ;
F_137 ( V_10 , V_43 , V_44 , V_64 -> V_45 ,
V_302 , V_205 ) ;
return 0 ;
}
int F_153 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_64 * V_64 , int V_43 , unsigned int V_44 )
{
struct V_11 * V_72 ;
int V_35 ;
int V_118 ;
struct V_322 * V_323 ;
struct V_62 * V_205 ;
int V_302 ;
T_2 V_30 , V_316 ;
struct V_92 * V_92 ;
struct V_67 * V_211 ;
V_72 = F_26 ( V_10 , V_64 ) ;
if ( ! V_72 )
return - V_290 ;
if ( ! V_64 -> V_324 )
return - V_290 ;
if ( ! F_9 () )
F_10 ( V_10 , L_170 ,
V_43 , V_44 ) ;
V_35 = 2 ;
if ( V_64 -> V_229 > 0 )
V_35 ++ ;
V_118 = F_126 ( V_10 , V_10 -> V_49 [ V_43 ] ,
V_44 , V_64 -> V_45 ,
V_35 , V_64 , 0 , V_287 ) ;
if ( V_118 < 0 )
return V_118 ;
V_92 = V_64 -> V_93 ;
V_211 = V_92 -> V_211 [ 0 ] ;
V_205 = & V_72 -> V_20 -> V_29 ;
V_302 = V_72 -> V_26 ;
V_323 = (struct V_322 * ) V_64 -> V_324 ;
V_30 = 0 ;
V_30 |= V_325 | F_33 ( V_326 ) ;
if ( V_302 == 0 )
V_30 |= 0x1 ;
if ( V_10 -> V_319 == 0x100 ) {
if ( V_64 -> V_229 > 0 ) {
if ( V_323 -> V_327 & V_328 )
V_30 |= F_154 ( V_329 ) ;
else
V_30 |= F_154 ( V_330 ) ;
}
}
F_124 ( V_10 , V_72 , false , true ,
V_323 -> V_327 | V_323 -> V_331 << 8 | F_145 ( V_323 -> V_332 ) << 16 ,
F_145 ( V_323 -> V_333 ) | F_145 ( V_323 -> V_334 ) << 16 ,
F_106 ( 8 ) | F_149 ( 0 ) ,
V_30 ) ;
if ( F_148 ( V_64 ) )
V_30 = V_318 | F_33 ( V_335 ) ;
else
V_30 = F_33 ( V_335 ) ;
V_316 = F_106 ( V_64 -> V_229 ) |
F_143 ( V_64 -> V_229 ) |
F_149 ( 0 ) ;
if ( V_64 -> V_229 > 0 ) {
if ( V_323 -> V_327 & V_328 )
V_30 |= V_336 ;
F_124 ( V_10 , V_72 , false , true ,
F_150 ( V_64 -> V_321 ) ,
F_151 ( V_64 -> V_321 ) ,
V_316 ,
V_30 | V_72 -> V_26 ) ;
}
V_211 -> F_4 = V_72 -> V_20 ;
if ( V_64 -> V_229 > 0 && V_323 -> V_327 & V_328 )
V_30 = 0 ;
else
V_30 = V_336 ;
F_124 ( V_10 , V_72 , false , false ,
0 ,
0 ,
F_149 ( 0 ) ,
V_30 | V_317 | F_33 ( V_337 ) | V_72 -> V_26 ) ;
F_137 ( V_10 , V_43 , V_44 , 0 ,
V_302 , V_205 ) ;
return 0 ;
}
static int F_155 ( struct V_9 * V_10 ,
struct V_64 * V_64 , int V_36 )
{
int V_35 = 0 ;
T_5 V_23 , V_338 ;
V_23 = ( T_5 ) ( V_64 -> V_321 + V_64 -> V_240 [ V_36 ] . V_339 ) ;
V_338 = V_64 -> V_240 [ V_36 ] . V_96 ;
V_35 = F_156 ( V_338 + ( V_23 & ( V_300 - 1 ) ) ,
V_300 ) ;
if ( V_35 == 0 )
V_35 ++ ;
return V_35 ;
}
static unsigned int F_157 ( struct V_9 * V_10 ,
struct V_340 * V_341 ,
struct V_64 * V_64 , unsigned int V_312 )
{
unsigned int V_342 ;
if ( V_10 -> V_319 < 0x100 || V_341 -> V_179 != V_343 )
return 0 ;
V_342 = V_64 -> V_48 -> V_344 . V_345 ;
return F_147 ( V_312 , V_342 + 1 ) - 1 ;
}
static unsigned int F_158 ( struct V_9 * V_10 ,
struct V_340 * V_341 ,
struct V_64 * V_64 , unsigned int V_312 )
{
unsigned int V_342 ;
unsigned int V_346 ;
if ( V_10 -> V_319 < 0x100 )
return 0 ;
switch ( V_341 -> V_179 ) {
case V_343 :
V_342 = V_64 -> V_48 -> V_344 . V_345 ;
V_346 = V_312 % ( V_342 + 1 ) ;
if ( V_346 == 0 )
return V_342 ;
return V_346 - 1 ;
default:
if ( V_312 == 0 )
return 0 ;
return V_312 - 1 ;
}
}
static int F_159 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_64 * V_64 , int V_43 , unsigned int V_44 )
{
struct V_11 * V_72 ;
struct V_92 * V_92 ;
struct V_67 * V_211 ;
int V_347 , V_348 ;
struct V_62 * V_205 ;
bool V_83 ;
int V_302 ;
T_2 V_30 , V_316 ;
int V_296 , V_311 , V_338 , V_349 , V_118 ;
T_5 V_350 , V_23 ;
int V_36 , V_119 ;
bool V_27 ;
V_72 = V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] . V_12 ;
V_347 = V_64 -> V_351 ;
if ( V_347 < 1 ) {
F_10 ( V_10 , L_171 ) ;
return - V_290 ;
}
if ( ! F_9 () )
F_10 ( V_10 , L_172
L_173 ,
V_64 -> V_48 -> V_66 . V_248 ,
V_64 -> V_229 ,
V_64 -> V_229 ,
( unsigned long long ) V_64 -> V_321 ,
V_347 ) ;
V_350 = ( T_5 ) V_64 -> V_321 ;
V_205 = & V_72 -> V_20 -> V_29 ;
V_302 = V_72 -> V_26 ;
V_92 = V_64 -> V_93 ;
for ( V_36 = 0 ; V_36 < V_347 ; V_36 ++ ) {
unsigned int V_312 ;
unsigned int V_352 ;
unsigned int V_346 ;
V_83 = true ;
V_296 = 0 ;
V_23 = V_350 + V_64 -> V_240 [ V_36 ] . V_339 ;
V_338 = V_64 -> V_240 [ V_36 ] . V_96 ;
V_349 = V_338 ;
V_312 = F_147 ( V_338 ,
F_145 ( V_64 -> V_48 -> V_66 . V_314 ) ) ;
if ( V_312 == 0 )
V_312 ++ ;
V_352 = F_157 ( V_10 , V_64 -> V_65 , V_64 ,
V_312 ) ;
V_346 = F_158 ( V_10 ,
V_64 -> V_65 , V_64 , V_312 ) ;
V_348 = F_155 ( V_10 , V_64 , V_36 ) ;
V_118 = F_126 ( V_10 , V_10 -> V_49 [ V_43 ] , V_44 ,
V_64 -> V_45 , V_348 , V_64 , V_36 , V_287 ) ;
if ( V_118 < 0 ) {
if ( V_36 == 0 )
return V_118 ;
goto V_190;
}
V_211 = V_92 -> V_211 [ V_36 ] ;
for ( V_119 = 0 ; V_119 < V_348 ; V_119 ++ ) {
T_2 V_309 = 0 ;
V_30 = F_160 ( V_352 ) | F_161 ( V_346 ) ;
if ( V_83 ) {
V_30 |= F_33 ( V_353 ) ;
V_30 |= V_354 ;
if ( V_36 == 0 ) {
if ( V_302 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_72 -> V_26 ;
V_83 = false ;
} else {
V_30 |= F_33 ( V_320 ) ;
V_30 |= V_72 -> V_26 ;
}
if ( F_148 ( V_64 ) )
V_30 |= V_318 ;
if ( V_119 < V_348 - 1 ) {
V_30 |= V_31 ;
V_27 = true ;
} else {
V_211 -> F_4 = V_72 -> V_20 ;
V_30 |= V_317 ;
if ( V_10 -> V_319 == 0x100 ) {
if ( V_36 < V_347 - 1 )
V_30 |= V_355 ;
}
V_27 = false ;
}
V_311 = V_300 -
( V_23 & ( ( 1 << V_356 ) - 1 ) ) ;
if ( V_311 > V_349 )
V_311 = V_349 ;
if ( V_10 -> V_319 < 0x100 ) {
V_309 = F_143 (
V_338 - V_296 ) ;
} else {
V_309 = F_144 (
V_296 , V_311 ,
V_312 , V_64 ) ;
}
V_316 = F_106 ( V_311 ) |
V_309 |
F_149 ( 0 ) ;
F_124 ( V_10 , V_72 , false , V_27 ,
F_150 ( V_23 ) ,
F_151 ( V_23 ) ,
V_316 ,
V_30 ) ;
V_296 += V_311 ;
V_23 += V_311 ;
V_349 -= V_311 ;
}
if ( V_296 != V_338 ) {
F_112 ( V_10 , L_174 ) ;
return - V_290 ;
}
}
if ( F_41 ( V_10 ) -> V_99 . V_100 == 0 ) {
if ( V_10 -> V_101 & V_102 )
F_162 () ;
}
F_41 ( V_10 ) -> V_99 . V_100 ++ ;
F_137 ( V_10 , V_43 , V_44 , V_64 -> V_45 ,
V_302 , V_205 ) ;
return 0 ;
V_190:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- )
F_56 ( & V_92 -> V_211 [ V_36 ] -> V_56 ) ;
V_92 -> V_211 [ 0 ] -> F_4 = V_72 -> V_20 ;
F_32 ( V_10 , V_72 , V_92 -> V_211 [ 0 ] , true ) ;
V_72 -> V_20 = V_92 -> V_211 [ 0 ] -> V_83 ;
V_72 -> V_33 = V_92 -> V_211 [ 0 ] -> V_61 ;
V_72 -> V_26 = V_302 ;
F_43 ( F_39 ( V_64 -> V_65 -> V_95 ) , V_64 ) ;
return V_118 ;
}
int F_163 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_64 * V_64 , int V_43 , unsigned int V_44 )
{
struct V_71 * V_221 ;
struct V_11 * V_72 ;
struct V_73 * V_74 ;
int V_357 ;
int V_303 ;
int V_304 ;
int V_347 , V_35 , V_36 ;
int V_118 ;
V_221 = V_10 -> V_49 [ V_43 ] ;
V_72 = V_221 -> V_50 [ V_44 ] . V_12 ;
V_74 = F_30 ( V_10 , V_221 -> V_78 , V_44 ) ;
V_35 = 0 ;
V_347 = V_64 -> V_351 ;
for ( V_36 = 0 ; V_36 < V_347 ; V_36 ++ )
V_35 += F_155 ( V_10 , V_64 , V_36 ) ;
V_118 = F_125 ( V_10 , V_72 , F_3 ( V_74 -> V_129 ) & V_130 ,
V_35 , V_287 ) ;
if ( V_118 )
return V_118 ;
V_357 = F_19 ( V_10 , & V_10 -> V_358 -> V_359 ) ;
V_357 &= 0x3fff ;
V_64 -> V_357 = V_357 ;
if ( V_64 -> V_65 -> V_179 == V_306 ||
V_64 -> V_65 -> V_179 == V_307 )
V_64 -> V_357 >>= 3 ;
V_303 = F_139 ( F_3 ( V_74 -> V_129 ) ) ;
V_304 = V_64 -> V_305 ;
if ( V_64 -> V_65 -> V_179 == V_306 ||
V_64 -> V_65 -> V_179 == V_307 )
V_304 *= 8 ;
if ( V_303 != V_304 ) {
if ( F_140 () )
F_141 ( & V_64 -> V_65 -> V_65 , L_158
L_159
L_160 ,
V_304 ,
V_304 == 1 ? L_161 : L_162 ,
V_303 ,
V_303 == 1 ? L_161 : L_162 ) ;
V_64 -> V_305 = V_303 ;
if ( V_64 -> V_65 -> V_179 == V_306 ||
V_64 -> V_65 -> V_179 == V_307 )
V_64 -> V_305 /= 8 ;
}
return F_159 ( V_10 , V_308 , V_64 , V_43 , V_44 ) ;
}
static int F_164 ( struct V_9 * V_10 , T_2 V_283 , T_2 V_284 ,
T_2 V_285 , T_2 V_286 , bool V_360 )
{
int V_361 = V_10 -> V_362 ;
int V_118 ;
if ( ! V_360 )
V_361 ++ ;
V_118 = F_125 ( V_10 , V_10 -> V_110 , V_292 ,
V_361 , V_308 ) ;
if ( V_118 < 0 ) {
F_112 ( V_10 , L_175 ) ;
if ( V_360 )
F_112 ( V_10 , L_176
L_177 ) ;
return V_118 ;
}
F_124 ( V_10 , V_10 -> V_110 , false , false , V_283 , V_284 , V_285 ,
V_286 | V_10 -> V_110 -> V_26 ) ;
return 0 ;
}
int F_165 ( struct V_9 * V_10 , T_2 V_171 , T_2 V_43 )
{
return F_164 ( V_10 , 0 , 0 , 0 ,
F_33 ( V_171 ) | F_166 ( V_43 ) , false ) ;
}
int F_167 ( struct V_9 * V_10 , T_1 V_363 ,
T_2 V_43 )
{
return F_164 ( V_10 , F_150 ( V_363 ) ,
F_151 ( V_363 ) , 0 ,
F_33 ( V_163 ) | F_166 ( V_43 ) ,
false ) ;
}
int F_168 ( struct V_9 * V_10 ,
T_2 V_283 , T_2 V_284 , T_2 V_285 , T_2 V_286 )
{
return F_164 ( V_10 , V_283 , V_284 , V_285 , V_286 , false ) ;
}
int F_169 ( struct V_9 * V_10 , T_2 V_43 )
{
return F_164 ( V_10 , 0 , 0 , 0 ,
F_33 ( V_168 ) | F_166 ( V_43 ) ,
false ) ;
}
int F_69 ( struct V_9 * V_10 , T_1 V_363 ,
T_2 V_43 , bool V_360 )
{
return F_164 ( V_10 , F_150 ( V_363 ) ,
F_151 ( V_363 ) , 0 ,
F_33 ( V_155 ) | F_166 ( V_43 ) ,
V_360 ) ;
}
int F_170 ( struct V_9 * V_10 , T_1 V_363 ,
T_2 V_43 )
{
return F_164 ( V_10 , F_150 ( V_363 ) ,
F_151 ( V_363 ) , 0 ,
F_33 ( V_162 ) | F_166 ( V_43 ) ,
false ) ;
}
int F_171 ( struct V_9 * V_10 , int V_43 ,
unsigned int V_44 , int V_364 )
{
T_2 V_365 = F_166 ( V_43 ) ;
T_2 V_366 = F_172 ( V_44 ) ;
T_2 type = F_33 ( V_164 ) ;
T_2 V_367 = F_173 ( V_364 ) ;
return F_164 ( V_10 , 0 , 0 , 0 ,
V_365 | V_366 | type | V_367 , false ) ;
}
static int F_35 ( struct V_9 * V_10 , int V_43 ,
unsigned int V_44 , unsigned int V_45 ,
struct V_1 * V_25 ,
union V_3 * V_368 , T_2 V_26 )
{
T_1 V_23 ;
T_2 V_365 = F_166 ( V_43 ) ;
T_2 V_366 = F_172 ( V_44 ) ;
T_2 V_369 = F_174 ( V_45 ) ;
T_2 type = F_33 ( V_165 ) ;
struct V_47 * V_48 ;
V_23 = F_1 ( V_25 , V_368 ) ;
if ( V_23 == 0 ) {
F_16 ( V_10 , L_178 ) ;
F_16 ( V_10 , L_179 ,
V_25 , V_368 ) ;
return 0 ;
}
V_48 = & V_10 -> V_49 [ V_43 ] -> V_50 [ V_44 ] ;
if ( ( V_48 -> V_51 & V_53 ) ) {
F_16 ( V_10 , L_178 ) ;
F_16 ( V_10 , L_180 ) ;
return 0 ;
}
V_48 -> V_133 = V_25 ;
V_48 -> V_134 = V_368 ;
return F_164 ( V_10 , F_150 ( V_23 ) | V_26 ,
F_151 ( V_23 ) , V_369 ,
V_365 | V_366 | type , false ) ;
}
int F_97 ( struct V_9 * V_10 , int V_43 ,
unsigned int V_44 )
{
T_2 V_365 = F_166 ( V_43 ) ;
T_2 V_366 = F_172 ( V_44 ) ;
T_2 type = F_33 ( V_167 ) ;
return F_164 ( V_10 , 0 , 0 , 0 , V_365 | V_366 | type ,
false ) ;
}
