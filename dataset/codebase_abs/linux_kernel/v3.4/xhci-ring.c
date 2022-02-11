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
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
union V_3 * V_14 ;
unsigned long long V_21 ;
V_12 -> V_22 ++ ;
if ( V_12 -> type != V_23 &&
! F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) )
V_12 -> V_26 ++ ;
V_14 = ++ ( V_12 -> V_25 ) ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_24 , V_14 ) ) {
if ( V_12 -> type == V_23 && F_2 ( V_10 ,
V_12 , V_12 -> V_24 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
V_12 -> V_24 = V_12 -> V_24 -> V_14 ;
V_12 -> V_25 = V_12 -> V_24 -> V_6 ;
V_14 = V_12 -> V_25 ;
}
V_21 = ( unsigned long long ) F_1 ( V_12 -> V_24 , V_12 -> V_25 ) ;
}
static void F_9 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 )
{
T_2 V_29 ;
union V_3 * V_14 ;
unsigned long long V_21 ;
V_29 = F_3 ( V_12 -> V_20 -> V_30 . V_31 [ 3 ] ) & V_32 ;
if ( V_12 -> type != V_23 &&
! F_4 ( V_10 , V_12 , V_12 -> V_33 , V_12 -> V_20 ) )
V_12 -> V_26 -- ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_34 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
if ( V_12 -> type != V_23 ) {
if ( ! V_29 && ! V_28 )
break;
if ( ! ( V_12 -> type == V_35 &&
( V_10 -> V_36 & V_37 ) )
&& ! F_10 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_11 ( ~ V_32 ) ;
V_14 -> V_16 . V_17 |=
F_11 ( V_29 ) ;
}
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_38 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
}
V_12 -> V_33 = V_12 -> V_33 -> V_14 ;
V_12 -> V_20 = V_12 -> V_33 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
V_21 = ( unsigned long long ) F_1 ( V_12 -> V_33 , V_12 -> V_20 ) ;
}
static inline int F_13 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_39 )
{
int V_40 ;
if ( V_12 -> V_26 < V_39 )
return 0 ;
if ( V_12 -> type != V_41 && V_12 -> type != V_23 ) {
V_40 = V_12 -> V_25 - V_12 -> V_24 -> V_6 ;
if ( V_12 -> V_26 < V_39 + V_40 )
return 0 ;
}
return 1 ;
}
void F_14 ( struct V_9 * V_10 )
{
F_15 ( V_10 , L_1 ) ;
F_16 ( V_10 , V_42 , & V_10 -> V_43 -> V_44 [ 0 ] ) ;
F_17 ( V_10 , & V_10 -> V_43 -> V_44 [ 0 ] ) ;
}
void F_18 ( struct V_9 * V_10 ,
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
F_16 ( V_10 , F_19 ( V_46 , V_47 ) , V_48 ) ;
}
static void F_20 ( struct V_9 * V_10 ,
unsigned int V_45 ,
unsigned int V_46 )
{
unsigned int V_47 ;
struct V_49 * V_50 ;
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( ! ( V_50 -> V_53 & V_57 ) ) {
if ( ! ( F_21 ( & V_50 -> V_12 -> V_58 ) ) )
F_18 ( V_10 , V_45 , V_46 , 0 ) ;
return;
}
for ( V_47 = 1 ; V_47 < V_50 -> V_59 -> V_60 ;
V_47 ++ ) {
struct V_61 * V_59 = V_50 -> V_59 ;
if ( ! F_21 ( & V_59 -> V_62 [ V_47 ] -> V_58 ) )
F_18 ( V_10 , V_45 , V_46 ,
V_47 ) ;
}
}
static struct V_1 * F_22 (
struct V_1 * V_63 ,
union V_3 * V_4 , int * V_27 )
{
struct V_1 * V_64 = V_63 ;
struct V_65 * V_66 ;
while ( V_64 -> V_6 > V_4 ||
& V_64 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_66 = & V_64 -> V_6 [ V_7 - 1 ] . V_30 ;
if ( V_66 -> V_31 [ 3 ] & F_11 ( V_18 ) )
* V_27 ^= 0x1 ;
V_64 = V_64 -> V_14 ;
if ( V_64 == V_63 )
return NULL ;
}
return V_64 ;
}
static struct V_11 * F_23 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 )
{
struct V_49 * V_50 ;
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( ! ( V_50 -> V_53 & V_57 ) )
return V_50 -> V_12 ;
if ( V_47 == 0 ) {
F_24 ( V_10 ,
L_2
L_3 ,
V_45 , V_46 ) ;
return NULL ;
}
if ( V_47 < V_50 -> V_59 -> V_60 )
return V_50 -> V_59 -> V_62 [ V_47 ] ;
F_24 ( V_10 ,
L_4
L_5
L_6 ,
V_45 , V_46 ,
V_50 -> V_59 -> V_60 - 1 ,
V_47 ) ;
return NULL ;
}
static struct V_11 * F_25 ( struct V_9 * V_10 ,
struct V_67 * V_67 )
{
return F_23 ( V_10 , V_67 -> V_68 -> V_45 ,
F_26 ( & V_67 -> V_50 -> V_69 ) , V_67 -> V_47 ) ;
}
void F_27 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 , struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_74 * V_68 = V_10 -> V_51 [ V_45 ] ;
struct V_11 * V_75 ;
struct V_65 * V_4 ;
struct V_76 * V_77 ;
T_1 V_21 ;
V_75 = F_23 ( V_10 , V_45 ,
V_46 , V_47 ) ;
if ( ! V_75 ) {
F_24 ( V_10 , L_7
L_8 ,
V_47 ) ;
return;
}
V_73 -> V_78 = 0 ;
F_15 ( V_10 , L_9 ) ;
V_73 -> V_79 = F_22 ( V_71 -> V_63 ,
V_68 -> V_52 [ V_46 ] . V_80 ,
& V_73 -> V_78 ) ;
if ( ! V_73 -> V_79 ) {
F_28 ( 1 ) ;
return;
}
F_15 ( V_10 , L_10 ) ;
V_77 = F_29 ( V_10 , V_68 -> V_81 , V_46 ) ;
V_73 -> V_78 = 0x1 & F_30 ( V_77 -> V_82 ) ;
V_73 -> V_83 = V_71 -> F_4 ;
F_15 ( V_10 , L_11 ) ;
V_73 -> V_79 = F_22 ( V_73 -> V_79 ,
V_73 -> V_83 ,
& V_73 -> V_78 ) ;
if ( ! V_73 -> V_79 ) {
F_28 ( 1 ) ;
return;
}
V_4 = & V_73 -> V_83 -> V_30 ;
if ( F_5 ( V_4 -> V_31 [ 3 ] ) &&
( V_4 -> V_31 [ 3 ] & F_11 ( V_18 ) ) )
V_73 -> V_78 ^= 0x1 ;
F_7 ( V_10 , V_75 , & V_73 -> V_79 , & V_73 -> V_83 ) ;
if ( V_75 -> V_15 == V_75 -> V_15 -> V_14 &&
V_73 -> V_83 < V_68 -> V_52 [ V_46 ] . V_80 )
V_73 -> V_78 ^= 0x1 ;
F_15 ( V_10 , L_12 , V_73 -> V_78 ) ;
F_15 ( V_10 , L_13 ,
V_73 -> V_79 ) ;
V_21 = F_1 ( V_73 -> V_79 , V_73 -> V_83 ) ;
F_15 ( V_10 , L_14 ,
( unsigned long long ) V_21 ) ;
}
static void F_31 ( struct V_9 * V_10 , struct V_11 * V_75 ,
struct V_70 * V_71 , bool V_84 )
{
struct V_1 * V_64 ;
union V_3 * V_85 ;
for ( V_64 = V_71 -> V_63 , V_85 = V_71 -> V_86 ;
true ;
F_7 ( V_10 , V_75 , & V_64 , & V_85 ) ) {
if ( F_5 ( V_85 -> V_30 . V_31 [ 3 ] ) ) {
V_85 -> V_30 . V_31 [ 3 ] &= F_11 ( ~ V_32 ) ;
if ( V_84 )
V_85 -> V_30 . V_31 [ 3 ] ^=
F_11 ( V_38 ) ;
F_15 ( V_10 , L_15 ) ;
F_15 ( V_10 , L_16
L_17 ,
V_85 ,
( unsigned long long ) F_1 ( V_64 , V_85 ) ,
V_64 ,
( unsigned long long ) V_64 -> V_8 ) ;
} else {
V_85 -> V_30 . V_31 [ 0 ] = 0 ;
V_85 -> V_30 . V_31 [ 1 ] = 0 ;
V_85 -> V_30 . V_31 [ 2 ] = 0 ;
V_85 -> V_30 . V_31 [ 3 ] &= F_11 ( V_38 ) ;
if ( V_84 && V_85 != V_71 -> V_86 &&
V_85 != V_71 -> F_4 )
V_85 -> V_30 . V_31 [ 3 ] ^=
F_11 ( V_38 ) ;
V_85 -> V_30 . V_31 [ 3 ] |= F_11 (
F_32 ( V_87 ) ) ;
F_15 ( V_10 , L_18 ,
( unsigned long long )
F_1 ( V_64 , V_85 ) ) ;
}
if ( V_85 == V_71 -> F_4 )
break;
}
}
void F_33 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 ,
struct V_72 * V_88 )
{
struct V_49 * V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
F_15 ( V_10 , L_19
L_20 ,
V_88 -> V_79 ,
( unsigned long long ) V_88 -> V_79 -> V_8 ,
V_88 -> V_83 ,
( unsigned long long ) F_1 ( V_88 -> V_79 , V_88 -> V_83 ) ,
V_88 -> V_78 ) ;
F_34 ( V_10 , V_45 , V_46 , V_47 ,
V_88 -> V_79 ,
V_88 -> V_83 ,
( T_2 ) V_88 -> V_78 ) ;
V_50 -> V_53 |= V_55 ;
}
static void F_35 ( struct V_9 * V_10 ,
struct V_49 * V_50 )
{
V_50 -> V_53 &= ~ V_54 ;
if ( F_36 ( & V_50 -> V_89 ) )
V_50 -> V_90 -- ;
}
static void F_37 ( struct V_9 * V_10 ,
struct V_70 * V_71 , int V_91 , char * V_92 )
{
struct V_93 * V_94 ;
struct V_67 * V_67 ;
struct V_95 * V_95 ;
V_67 = V_71 -> V_67 ;
V_95 = V_67 -> V_96 ;
V_95 -> V_97 ++ ;
V_94 = F_38 ( V_67 -> V_68 -> V_98 ) ;
if ( V_95 -> V_97 == V_95 -> V_99 ) {
if ( F_39 ( V_67 -> V_100 ) == V_101 ) {
F_40 ( V_10 ) -> V_102 . V_103 -- ;
if ( F_40 ( V_10 ) -> V_102 . V_103 == 0 ) {
if ( V_10 -> V_36 & V_104 )
F_41 () ;
}
}
F_42 ( V_94 , V_67 ) ;
F_43 ( & V_10 -> V_105 ) ;
F_44 ( V_94 , V_67 , V_91 ) ;
F_45 ( V_10 , V_95 ) ;
F_46 ( & V_10 -> V_105 ) ;
}
}
static void F_47 ( struct V_9 * V_10 ,
union V_3 * V_4 , struct V_106 * V_107 )
{
unsigned int V_45 ;
unsigned int V_46 ;
struct V_74 * V_108 ;
struct V_11 * V_75 ;
struct V_49 * V_50 ;
struct V_109 * V_110 ;
struct V_70 * V_71 = NULL ;
struct V_70 * V_111 ;
struct V_72 V_88 ;
if ( F_48 ( F_49 (
F_3 ( V_10 -> V_112 -> V_25 -> V_30 . V_31 [ 3 ] ) ) ) ) {
V_45 = F_50 (
F_3 ( V_10 -> V_112 -> V_25 -> V_30 . V_31 [ 3 ] ) ) ;
V_108 = V_10 -> V_51 [ V_45 ] ;
if ( V_108 )
F_51 ( V_10 , V_108 ,
V_107 ) ;
else
F_24 ( V_10 , L_21
L_22 ,
V_45 ) ;
return;
}
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_45 = F_50 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_46 = F_52 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( F_21 ( & V_50 -> V_113 ) ) {
F_35 ( V_10 , V_50 ) ;
V_50 -> V_114 = NULL ;
V_50 -> V_80 = NULL ;
F_20 ( V_10 , V_45 , V_46 ) ;
return;
}
F_53 (entry, &ep->cancelled_td_list) {
V_71 = F_54 ( V_110 , struct V_70 , V_113 ) ;
F_15 ( V_10 , L_23 ,
( unsigned long long ) F_1 (
V_71 -> V_63 , V_71 -> V_86 ) ) ;
V_75 = F_25 ( V_10 , V_71 -> V_67 ) ;
if ( ! V_75 ) {
F_24 ( V_10 , L_24
L_25 ,
V_71 -> V_67 ,
V_71 -> V_67 -> V_47 ) ;
goto V_115;
}
if ( V_71 == V_50 -> V_114 )
F_27 ( V_10 , V_45 , V_46 ,
V_71 -> V_67 -> V_47 ,
V_71 , & V_88 ) ;
else
F_31 ( V_10 , V_75 , V_71 , false ) ;
V_115:
F_55 ( & V_71 -> V_58 ) ;
}
V_111 = V_71 ;
F_35 ( V_10 , V_50 ) ;
if ( V_88 . V_83 && V_88 . V_79 ) {
F_33 ( V_10 ,
V_45 , V_46 ,
V_50 -> V_114 -> V_67 -> V_47 ,
& V_88 ) ;
F_14 ( V_10 ) ;
} else {
F_20 ( V_10 , V_45 , V_46 ) ;
}
V_50 -> V_114 = NULL ;
V_50 -> V_80 = NULL ;
do {
V_71 = F_54 ( V_50 -> V_113 . V_14 ,
struct V_70 , V_113 ) ;
F_55 ( & V_71 -> V_113 ) ;
F_37 ( V_10 , V_71 , 0 , L_26 ) ;
if ( V_10 -> V_116 & V_117 )
return;
} while ( V_71 != V_111 );
}
void F_56 ( unsigned long V_118 )
{
struct V_9 * V_10 ;
struct V_49 * V_50 ;
struct V_49 * V_119 ;
struct V_11 * V_12 ;
struct V_70 * V_71 ;
int V_120 , V_121 , V_122 ;
unsigned long V_123 ;
V_50 = (struct V_49 * ) V_118 ;
V_10 = V_50 -> V_10 ;
F_57 ( & V_10 -> V_105 , V_123 ) ;
V_50 -> V_90 -- ;
if ( V_10 -> V_116 & V_117 ) {
F_15 ( V_10 , L_27
L_28 ) ;
F_58 ( & V_10 -> V_105 , V_123 ) ;
return;
}
if ( ! ( V_50 -> V_90 == 0 && ( V_50 -> V_53 & V_54 ) ) ) {
F_15 ( V_10 , L_29
L_30 ) ;
F_58 ( & V_10 -> V_105 , V_123 ) ;
return;
}
F_24 ( V_10 , L_31 ) ;
F_24 ( V_10 , L_32 ) ;
V_10 -> V_116 |= V_117 ;
F_59 ( V_10 ) ;
F_58 ( & V_10 -> V_105 , V_123 ) ;
V_120 = F_60 ( V_10 ) ;
F_57 ( & V_10 -> V_105 , V_123 ) ;
if ( V_120 < 0 ) {
F_24 ( V_10 , L_33 ) ;
F_24 ( V_10 , L_34 ) ;
}
for ( V_121 = 0 ; V_121 < V_124 ; V_121 ++ ) {
if ( ! V_10 -> V_51 [ V_121 ] )
continue;
for ( V_122 = 0 ; V_122 < 31 ; V_122 ++ ) {
V_119 = & V_10 -> V_51 [ V_121 ] -> V_52 [ V_122 ] ;
V_12 = V_119 -> V_12 ;
if ( ! V_12 )
continue;
F_15 ( V_10 , L_35
L_36 , V_121 , V_122 ) ;
while ( ! F_21 ( & V_12 -> V_58 ) ) {
V_71 = F_61 ( & V_12 -> V_58 ,
struct V_70 ,
V_58 ) ;
F_55 ( & V_71 -> V_58 ) ;
if ( ! F_21 ( & V_71 -> V_113 ) )
F_55 ( & V_71 -> V_113 ) ;
F_37 ( V_10 , V_71 ,
- V_125 , L_37 ) ;
}
while ( ! F_21 ( & V_119 -> V_113 ) ) {
V_71 = F_61 (
& V_119 -> V_113 ,
struct V_70 ,
V_113 ) ;
F_55 ( & V_71 -> V_113 ) ;
F_37 ( V_10 , V_71 ,
- V_125 , L_37 ) ;
}
}
}
F_58 ( & V_10 -> V_105 , V_123 ) ;
F_15 ( V_10 , L_38 ) ;
F_62 ( F_40 ( V_10 ) -> V_126 ) ;
F_15 ( V_10 , L_39 ) ;
}
static void F_63 ( struct V_9 * V_10 ,
struct V_74 * V_68 ,
struct V_11 * V_75 ,
unsigned int V_46 )
{
union V_3 * V_127 ;
int V_128 ;
bool V_129 = false ;
V_128 = V_75 -> V_26 ;
V_127 = V_75 -> V_25 ;
while ( V_75 -> V_25 != V_68 -> V_52 [ V_46 ] . V_130 ) {
V_75 -> V_26 ++ ;
V_75 -> V_25 ++ ;
if ( F_4 ( V_10 , V_75 , V_75 -> V_24 ,
V_75 -> V_25 ) ) {
if ( V_75 -> V_25 ==
V_68 -> V_52 [ V_46 ] . V_130 )
break;
V_75 -> V_24 = V_75 -> V_24 -> V_14 ;
V_75 -> V_25 = V_75 -> V_24 -> V_6 ;
}
if ( V_75 -> V_25 == V_127 ) {
V_129 = true ;
break;
}
}
if ( V_129 ) {
F_15 ( V_10 , L_40 ) ;
V_75 -> V_26 = V_128 ;
}
}
static void F_64 ( struct V_9 * V_10 ,
struct V_106 * V_107 ,
union V_3 * V_4 )
{
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
struct V_11 * V_75 ;
struct V_74 * V_68 ;
struct V_76 * V_77 ;
struct V_131 * V_132 ;
V_45 = F_50 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_46 = F_52 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_47 = F_65 ( F_3 ( V_4 -> V_30 . V_31 [ 2 ] ) ) ;
V_68 = V_10 -> V_51 [ V_45 ] ;
V_75 = F_66 ( V_68 , V_46 , V_47 ) ;
if ( ! V_75 ) {
F_24 ( V_10 , L_41
L_42 ,
V_47 ) ;
V_68 -> V_52 [ V_46 ] . V_53 &= ~ V_55 ;
return;
}
V_77 = F_29 ( V_10 , V_68 -> V_81 , V_46 ) ;
V_132 = F_67 ( V_10 , V_68 -> V_81 ) ;
if ( F_68 ( F_3 ( V_107 -> V_91 ) ) != V_133 ) {
unsigned int V_53 ;
unsigned int V_134 ;
switch ( F_68 ( F_3 ( V_107 -> V_91 ) ) ) {
case V_135 :
F_24 ( V_10 , L_43
L_44 ) ;
break;
case V_136 :
F_24 ( V_10 , L_45
L_46 ) ;
V_53 = F_3 ( V_77 -> V_137 ) ;
V_53 &= V_138 ;
V_134 = F_3 ( V_132 -> V_139 ) ;
V_134 = F_69 ( V_134 ) ;
F_15 ( V_10 , L_47 ,
V_134 , V_53 ) ;
break;
case V_140 :
F_24 ( V_10 , L_48
L_49 , V_45 ) ;
break;
default:
F_24 ( V_10 , L_50
L_51 ,
F_68 ( F_3 ( V_107 -> V_91 ) ) ) ;
break;
}
} else {
F_15 ( V_10 , L_52 ,
F_30 ( V_77 -> V_82 ) ) ;
if ( F_1 ( V_68 -> V_52 [ V_46 ] . V_141 ,
V_68 -> V_52 [ V_46 ] . V_130 ) ==
( F_30 ( V_77 -> V_82 ) & ~ ( V_142 ) ) ) {
F_63 ( V_10 , V_68 ,
V_75 , V_46 ) ;
} else {
F_24 ( V_10 , L_53
L_54 ) ;
F_24 ( V_10 , L_55 ,
V_68 -> V_52 [ V_46 ] . V_141 ,
V_68 -> V_52 [ V_46 ] . V_130 ) ;
}
}
V_68 -> V_52 [ V_46 ] . V_53 &= ~ V_55 ;
V_68 -> V_52 [ V_46 ] . V_141 = NULL ;
V_68 -> V_52 [ V_46 ] . V_130 = NULL ;
F_20 ( V_10 , V_45 , V_46 ) ;
}
static void F_70 ( struct V_9 * V_10 ,
struct V_106 * V_107 ,
union V_3 * V_4 )
{
int V_45 ;
unsigned int V_46 ;
V_45 = F_50 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_46 = F_52 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
F_15 ( V_10 , L_56 ,
F_68 ( F_3 ( V_107 -> V_91 ) ) ) ;
if ( V_10 -> V_36 & V_143 ) {
F_15 ( V_10 , L_57 ) ;
F_71 ( V_10 ,
V_10 -> V_51 [ V_45 ] -> V_144 -> V_8 , V_45 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_53 &= ~ V_56 ;
F_20 ( V_10 , V_45 , V_46 ) ;
}
}
static int F_51 ( struct V_9 * V_10 ,
struct V_74 * V_108 ,
struct V_106 * V_107 )
{
struct V_145 * V_146 ;
if ( F_21 ( & V_108 -> V_147 ) )
return 0 ;
V_146 = F_54 ( V_108 -> V_147 . V_14 ,
struct V_145 , V_147 ) ;
if ( V_10 -> V_112 -> V_25 != V_146 -> V_148 )
return 0 ;
V_146 -> V_91 = F_68 ( F_3 ( V_107 -> V_91 ) ) ;
F_72 ( & V_146 -> V_147 ) ;
if ( V_146 -> V_149 )
F_73 ( V_146 -> V_149 ) ;
else
F_74 ( V_10 , V_146 ) ;
return 1 ;
}
static void F_75 ( struct V_9 * V_10 ,
struct V_106 * V_107 )
{
int V_45 = F_50 ( F_3 ( V_107 -> V_123 ) ) ;
T_5 V_150 ;
T_1 V_151 ;
struct V_152 * V_153 ;
struct V_74 * V_108 ;
unsigned int V_46 ;
struct V_11 * V_75 ;
unsigned int V_53 ;
V_150 = F_30 ( V_107 -> V_154 ) ;
V_151 = F_1 ( V_10 -> V_112 -> V_24 ,
V_10 -> V_112 -> V_25 ) ;
if ( V_151 == 0 ) {
V_10 -> V_155 |= 1 << 4 ;
return;
}
if ( V_150 != ( T_5 ) V_151 ) {
V_10 -> V_155 |= 1 << 5 ;
return;
}
switch ( F_3 ( V_10 -> V_112 -> V_25 -> V_30 . V_31 [ 3 ] )
& V_156 ) {
case F_32 ( V_157 ) :
if ( F_68 ( F_3 ( V_107 -> V_91 ) ) == V_133 )
V_10 -> V_45 = V_45 ;
else
V_10 -> V_45 = 0 ;
F_73 ( & V_10 -> V_158 ) ;
break;
case F_32 ( V_159 ) :
if ( V_10 -> V_51 [ V_45 ] ) {
if ( V_10 -> V_36 & V_160 )
F_76 ( V_10 ,
V_10 -> V_51 [ V_45 ] , true ) ;
F_77 ( V_10 , V_45 ) ;
}
break;
case F_32 ( V_161 ) :
V_108 = V_10 -> V_51 [ V_45 ] ;
if ( F_51 ( V_10 , V_108 , V_107 ) )
break;
V_153 = F_78 ( V_10 ,
V_108 -> V_144 ) ;
V_46 = F_79 ( F_3 ( V_153 -> V_162 ) ) - 1 ;
if ( V_10 -> V_36 & V_143 &&
V_46 != ( unsigned int ) - 1 &&
F_3 ( V_153 -> V_162 ) - V_163 ==
F_3 ( V_153 -> V_164 ) ) {
V_75 = V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_12 ;
V_53 = V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_53 ;
if ( ! ( V_53 & V_56 ) )
goto V_165;
F_15 ( V_10 , L_58
L_59 ,
V_46 , V_53 ) ;
V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_53 &=
~ V_56 ;
F_20 ( V_10 , V_45 , V_46 ) ;
break;
}
V_165:
F_15 ( V_10 , L_60 ) ;
V_10 -> V_51 [ V_45 ] -> V_166 =
F_68 ( F_3 ( V_107 -> V_91 ) ) ;
F_73 ( & V_10 -> V_51 [ V_45 ] -> V_167 ) ;
break;
case F_32 ( V_168 ) :
V_108 = V_10 -> V_51 [ V_45 ] ;
if ( F_51 ( V_10 , V_108 , V_107 ) )
break;
V_10 -> V_51 [ V_45 ] -> V_166 = F_68 ( F_3 ( V_107 -> V_91 ) ) ;
F_73 ( & V_10 -> V_51 [ V_45 ] -> V_167 ) ;
break;
case F_32 ( V_169 ) :
V_10 -> V_51 [ V_45 ] -> V_166 = F_68 ( F_3 ( V_107 -> V_91 ) ) ;
F_73 ( & V_10 -> V_158 ) ;
break;
case F_32 ( V_170 ) :
F_47 ( V_10 , V_10 -> V_112 -> V_25 , V_107 ) ;
break;
case F_32 ( V_171 ) :
F_64 ( V_10 , V_107 , V_10 -> V_112 -> V_25 ) ;
break;
case F_32 ( V_172 ) :
break;
case F_32 ( V_173 ) :
F_70 ( V_10 , V_107 , V_10 -> V_112 -> V_25 ) ;
break;
case F_32 ( V_174 ) :
F_15 ( V_10 , L_61 ) ;
V_45 = F_50 (
F_3 ( V_10 -> V_112 -> V_25 -> V_30 . V_31 [ 3 ] ) ) ;
V_108 = V_10 -> V_51 [ V_45 ] ;
if ( V_108 )
F_51 ( V_10 , V_108 , V_107 ) ;
else
F_24 ( V_10 , L_62
L_63 , V_45 ) ;
break;
case F_32 ( V_175 ) :
if ( ! ( V_10 -> V_36 & V_176 ) ) {
V_10 -> V_155 |= 1 << 6 ;
break;
}
F_15 ( V_10 , L_64 ,
F_80 ( F_3 ( V_107 -> V_91 ) ) ,
F_81 ( F_3 ( V_107 -> V_91 ) ) ) ;
break;
default:
V_10 -> V_155 |= 1 << 6 ;
break;
}
F_8 ( V_10 , V_10 -> V_112 ) ;
}
static void F_82 ( struct V_9 * V_10 ,
union V_3 * V_107 )
{
T_2 V_177 ;
V_177 = F_83 ( F_3 ( V_107 -> V_30 . V_31 [ 3 ] ) ) ;
F_15 ( V_10 , L_65 , V_177 ) ;
if ( V_177 == V_178 && ( V_10 -> V_36 & V_176 ) )
F_75 ( V_10 , & V_107 -> V_179 ) ;
}
static unsigned int F_84 ( struct V_93 * V_94 ,
struct V_9 * V_10 , T_2 V_180 )
{
unsigned int V_121 ;
unsigned int V_181 = 0 ;
for ( V_121 = 0 ; V_121 < ( V_180 - 1 ) ; V_121 ++ ) {
T_6 V_182 = V_10 -> V_183 [ V_121 ] ;
if ( V_182 == 0 || V_182 == V_184 )
continue;
if ( ( V_182 == 0x03 ) == ( V_94 -> V_185 == V_186 ) )
V_181 ++ ;
}
return V_181 ;
}
static void F_85 ( struct V_9 * V_10 ,
union V_3 * V_107 )
{
T_2 V_45 ;
struct V_187 * V_188 ;
V_45 = F_50 ( V_107 -> V_30 . V_31 [ 3 ] ) ;
if ( ! V_10 -> V_51 [ V_45 ] ) {
F_24 ( V_10 , L_66
L_67 , V_45 ) ;
return;
}
F_15 ( V_10 , L_68 ,
V_45 ) ;
V_188 = V_10 -> V_51 [ V_45 ] -> V_188 ;
if ( V_188 && V_188 -> V_189 )
F_86 ( V_188 -> V_189 , V_188 -> V_190 ) ;
}
static void F_87 ( struct V_9 * V_10 ,
union V_3 * V_107 )
{
struct V_93 * V_94 ;
T_2 V_180 ;
T_2 V_191 , V_192 ;
int V_193 ;
int V_45 ;
unsigned int V_194 ;
T_6 V_195 ;
struct V_196 * V_197 ;
T_3 T_4 * * V_183 ;
bool V_198 = false ;
if ( F_68 ( F_3 ( V_107 -> V_30 . V_31 [ 2 ] ) ) != V_133 ) {
F_24 ( V_10 , L_69 ) ;
V_10 -> V_155 |= 1 << 8 ;
}
V_180 = F_88 ( F_3 ( V_107 -> V_30 . V_31 [ 0 ] ) ) ;
F_15 ( V_10 , L_70 , V_180 ) ;
V_193 = F_89 ( V_10 -> V_199 ) ;
if ( ( V_180 <= 0 ) || ( V_180 > V_193 ) ) {
F_24 ( V_10 , L_71 , V_180 ) ;
V_198 = true ;
goto V_200;
}
V_195 = V_10 -> V_183 [ V_180 - 1 ] ;
if ( V_195 == 0 ) {
F_24 ( V_10 , L_72
L_73 ,
V_180 ) ;
V_198 = true ;
goto V_200;
}
if ( V_195 == V_184 ) {
F_24 ( V_10 , L_74
L_73 ,
V_180 ) ;
V_198 = true ;
goto V_200;
}
V_94 = F_40 ( V_10 ) ;
if ( ( V_195 == 0x03 ) != ( V_94 -> V_185 == V_186 ) )
V_94 = V_10 -> V_201 ;
V_197 = & V_10 -> V_197 [ F_90 ( V_94 ) ] ;
if ( V_94 -> V_185 == V_186 )
V_183 = V_10 -> V_202 ;
else
V_183 = V_10 -> V_203 ;
V_194 = F_84 ( V_94 , V_10 ,
V_180 ) ;
V_191 = F_17 ( V_10 , V_183 [ V_194 ] ) ;
if ( V_94 -> V_73 == V_204 ) {
F_15 ( V_10 , L_75 ) ;
F_91 ( V_94 ) ;
}
if ( ( V_191 & V_205 ) && ( V_191 & V_206 ) == V_207 ) {
F_15 ( V_10 , L_76 , V_180 ) ;
V_192 = F_17 ( V_10 , & V_10 -> V_208 -> V_146 ) ;
if ( ! ( V_192 & V_209 ) ) {
F_24 ( V_10 , L_77 ) ;
goto V_200;
}
if ( F_92 ( V_191 ) ) {
F_15 ( V_10 , L_78 , V_180 ) ;
V_197 -> V_210 |= 1 << V_194 ;
F_93 ( V_10 , V_183 ,
V_194 , V_205 ) ;
F_94 ( V_10 , V_183 , V_194 ,
V_211 ) ;
V_198 = true ;
goto V_200;
} else {
F_15 ( V_10 , L_79 , V_180 ) ;
V_197 -> V_212 [ V_194 ] = V_213 +
F_95 ( 20 ) ;
F_96 ( & V_94 -> V_214 ,
V_197 -> V_212 [ V_194 ] ) ;
}
}
if ( ( V_191 & V_205 ) && ( V_191 & V_206 ) == V_211 &&
F_92 ( V_191 ) ) {
F_15 ( V_10 , L_80 , V_180 ) ;
V_45 = F_97 ( V_94 , V_10 ,
V_194 + 1 ) ;
if ( V_45 && V_10 -> V_51 [ V_45 ] )
F_98 ( V_10 , V_45 ) ;
if ( V_197 -> V_210 && ( 1 << V_194 ) ) {
V_197 -> V_210 &=
~ ( 1 << V_194 ) ;
F_93 ( V_10 , V_183 ,
V_194 , V_205 ) ;
F_86 ( V_94 -> V_102 . V_215 ,
V_194 + 1 ) ;
V_198 = true ;
goto V_200;
}
}
if ( V_94 -> V_185 != V_186 )
F_93 ( V_10 , V_183 , V_194 ,
V_205 ) ;
V_200:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_198 )
return;
F_43 ( & V_10 -> V_105 ) ;
F_99 ( V_94 ) ;
F_46 ( & V_10 -> V_105 ) ;
}
struct V_1 * F_100 ( struct V_1 * V_63 ,
union V_3 * V_216 ,
union V_3 * V_217 ,
T_1 V_218 )
{
T_1 V_219 ;
T_1 V_220 ;
T_1 V_221 ;
struct V_1 * V_64 ;
V_219 = F_1 ( V_63 , V_216 ) ;
V_64 = V_63 ;
do {
if ( V_219 == 0 )
return NULL ;
V_220 = F_1 ( V_64 ,
& V_64 -> V_6 [ V_7 - 1 ] ) ;
V_221 = F_1 ( V_64 , V_217 ) ;
if ( V_221 > 0 ) {
if ( V_219 <= V_221 ) {
if ( V_218 >= V_219 && V_218 <= V_221 )
return V_64 ;
} else {
if ( ( V_218 >= V_219 &&
V_218 <= V_220 ) ||
( V_218 >= V_64 -> V_8 &&
V_218 <= V_221 ) )
return V_64 ;
}
return NULL ;
} else {
if ( V_218 >= V_219 && V_218 <= V_220 )
return V_64 ;
}
V_64 = V_64 -> V_14 ;
V_219 = F_1 ( V_64 , & V_64 -> V_6 [ 0 ] ) ;
} while ( V_64 != V_63 );
return NULL ;
}
static void F_101 ( struct V_9 * V_10 ,
unsigned int V_45 , unsigned int V_46 ,
unsigned int V_47 ,
struct V_70 * V_222 , union V_3 * V_223 )
{
struct V_49 * V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
V_50 -> V_53 |= V_56 ;
V_50 -> V_114 = V_222 ;
V_50 -> V_80 = V_223 ;
V_50 -> V_224 = V_47 ;
F_102 ( V_10 , V_45 , V_46 ) ;
F_103 ( V_10 , V_222 -> V_67 -> V_68 , V_46 ) ;
V_50 -> V_114 = NULL ;
V_50 -> V_80 = NULL ;
V_50 -> V_224 = 0 ;
F_14 ( V_10 ) ;
}
static int F_104 ( struct V_9 * V_10 ,
struct V_76 * V_77 ,
unsigned int V_225 )
{
if ( V_225 == V_226 ||
V_225 == V_227 ||
V_225 == V_228 )
if ( ( V_77 -> V_137 & F_11 ( V_138 ) ) ==
F_11 ( V_229 ) )
return 1 ;
return 0 ;
}
int F_105 ( struct V_9 * V_10 , unsigned int V_225 )
{
if ( V_225 >= 224 && V_225 <= 255 ) {
F_15 ( V_10 , L_81 ,
V_225 ) ;
F_15 ( V_10 , L_82 ) ;
return 1 ;
}
return 0 ;
}
static int F_106 ( struct V_9 * V_10 , struct V_70 * V_222 ,
union V_3 * V_223 , struct V_230 * V_107 ,
struct V_49 * V_50 , int * V_91 , bool V_231 )
{
struct V_74 * V_232 ;
struct V_11 * V_75 ;
unsigned int V_45 ;
int V_46 ;
struct V_67 * V_67 = NULL ;
struct V_76 * V_77 ;
int V_120 = 0 ;
struct V_95 * V_95 ;
T_2 V_225 ;
V_45 = F_50 ( F_3 ( V_107 -> V_123 ) ) ;
V_232 = V_10 -> V_51 [ V_45 ] ;
V_46 = F_107 ( F_3 ( V_107 -> V_123 ) ) - 1 ;
V_75 = F_108 ( V_50 , F_30 ( V_107 -> V_233 ) ) ;
V_77 = F_29 ( V_10 , V_232 -> V_81 , V_46 ) ;
V_225 = F_68 ( F_3 ( V_107 -> V_234 ) ) ;
if ( V_231 )
goto V_235;
if ( V_225 == V_236 ||
V_225 == V_237 ) {
V_50 -> V_114 = V_222 ;
V_50 -> V_80 = V_223 ;
return 0 ;
} else {
if ( V_225 == V_238 ) {
V_50 -> V_114 = V_222 ;
V_50 -> V_80 = V_223 ;
V_50 -> V_224 = V_75 -> V_47 ;
} else if ( F_104 ( V_10 ,
V_77 , V_225 ) ) {
F_101 ( V_10 ,
V_45 , V_46 , V_75 -> V_47 ,
V_222 , V_223 ) ;
} else {
while ( V_75 -> V_25 != V_222 -> F_4 )
F_8 ( V_10 , V_75 ) ;
F_8 ( V_10 , V_75 ) ;
}
V_235:
V_67 = V_222 -> V_67 ;
V_95 = V_67 -> V_96 ;
if ( V_67 -> V_239 > V_67 -> V_240 ) {
F_24 ( V_10 , L_83
L_84
L_85 ,
V_67 -> V_240 ,
V_67 -> V_239 ) ;
V_67 -> V_239 = 0 ;
if ( V_222 -> V_67 -> V_241 & V_242 )
* V_91 = - V_243 ;
else
* V_91 = 0 ;
}
F_55 ( & V_222 -> V_58 ) ;
if ( ! F_21 ( & V_222 -> V_113 ) )
F_55 ( & V_222 -> V_113 ) ;
V_95 -> V_97 ++ ;
if ( V_95 -> V_97 == V_95 -> V_99 ) {
V_120 = 1 ;
if ( F_39 ( V_67 -> V_100 ) == V_101 ) {
F_40 ( V_10 ) -> V_102 . V_103 -- ;
if ( F_40 ( V_10 ) -> V_102 . V_103
== 0 ) {
if ( V_10 -> V_36 & V_104 )
F_41 () ;
}
}
}
}
return V_120 ;
}
static int F_109 ( struct V_9 * V_10 , struct V_70 * V_222 ,
union V_3 * V_223 , struct V_230 * V_107 ,
struct V_49 * V_50 , int * V_91 )
{
struct V_74 * V_232 ;
struct V_11 * V_75 ;
unsigned int V_45 ;
int V_46 ;
struct V_76 * V_77 ;
T_2 V_225 ;
V_45 = F_50 ( F_3 ( V_107 -> V_123 ) ) ;
V_232 = V_10 -> V_51 [ V_45 ] ;
V_46 = F_107 ( F_3 ( V_107 -> V_123 ) ) - 1 ;
V_75 = F_108 ( V_50 , F_30 ( V_107 -> V_233 ) ) ;
V_77 = F_29 ( V_10 , V_232 -> V_81 , V_46 ) ;
V_225 = F_68 ( F_3 ( V_107 -> V_234 ) ) ;
switch ( V_225 ) {
case V_133 :
if ( V_223 == V_75 -> V_25 ) {
F_24 ( V_10 , L_86
L_87 ) ;
* V_91 = - V_125 ;
} else if ( V_223 != V_222 -> F_4 ) {
F_24 ( V_10 , L_88
L_87 ) ;
* V_91 = - V_125 ;
} else {
* V_91 = 0 ;
}
break;
case V_244 :
if ( V_222 -> V_67 -> V_241 & V_242 )
* V_91 = - V_243 ;
else
* V_91 = 0 ;
break;
case V_236 :
case V_237 :
return F_106 ( V_10 , V_222 , V_223 , V_107 , V_50 , V_91 , false ) ;
default:
if ( ! F_104 ( V_10 ,
V_77 , V_225 ) )
break;
F_15 ( V_10 , L_89
L_90 ,
V_225 , V_46 ) ;
case V_238 :
if ( V_223 != V_75 -> V_25 &&
V_223 != V_222 -> F_4 )
V_222 -> V_67 -> V_239 =
V_222 -> V_67 -> V_240
- F_110 ( F_3 ( V_107 -> V_234 ) ) ;
else
V_222 -> V_67 -> V_239 = 0 ;
F_101 ( V_10 ,
V_45 , V_46 , 0 , V_222 , V_223 ) ;
return F_106 ( V_10 , V_222 , V_223 , V_107 , V_50 , V_91 , true ) ;
}
if ( V_223 != V_75 -> V_25 ) {
if ( V_223 == V_222 -> F_4 ) {
if ( V_222 -> V_67 -> V_239 != 0 ) {
if ( ( * V_91 == - V_245 || * V_91 == 0 ) &&
( V_222 -> V_67 -> V_241
& V_242 ) )
* V_91 = - V_243 ;
} else {
V_222 -> V_67 -> V_239 =
V_222 -> V_67 -> V_240 ;
}
} else {
V_222 -> V_67 -> V_239 =
V_222 -> V_67 -> V_240 -
F_110 ( F_3 ( V_107 -> V_234 ) ) ;
F_15 ( V_10 , L_91
L_92 ) ;
return 0 ;
}
}
return F_106 ( V_10 , V_222 , V_223 , V_107 , V_50 , V_91 , false ) ;
}
static int F_111 ( struct V_9 * V_10 , struct V_70 * V_222 ,
union V_3 * V_223 , struct V_230 * V_107 ,
struct V_49 * V_50 , int * V_91 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
int V_246 ;
int V_247 = 0 ;
union V_3 * V_85 ;
struct V_1 * V_64 ;
struct V_248 * V_249 ;
T_2 V_225 ;
bool V_250 = false ;
V_75 = F_108 ( V_50 , F_30 ( V_107 -> V_233 ) ) ;
V_225 = F_68 ( F_3 ( V_107 -> V_234 ) ) ;
V_95 = V_222 -> V_67 -> V_96 ;
V_246 = V_95 -> V_97 ;
V_249 = & V_222 -> V_67 -> V_251 [ V_246 ] ;
switch ( V_225 ) {
case V_133 :
V_249 -> V_91 = 0 ;
break;
case V_244 :
V_249 -> V_91 = V_222 -> V_67 -> V_241 & V_242 ?
- V_243 : 0 ;
break;
case V_252 :
V_249 -> V_91 = - V_253 ;
V_250 = true ;
break;
case V_254 :
case V_227 :
V_249 -> V_91 = - V_255 ;
V_250 = true ;
break;
case V_256 :
case V_238 :
V_249 -> V_91 = - V_257 ;
V_250 = true ;
break;
case V_237 :
case V_236 :
break;
default:
V_249 -> V_91 = - 1 ;
break;
}
if ( V_225 == V_133 || V_250 ) {
V_249 -> V_239 = V_249 -> V_99 ;
V_222 -> V_67 -> V_239 += V_249 -> V_99 ;
} else {
for ( V_85 = V_75 -> V_25 ,
V_64 = V_75 -> V_24 ; V_85 != V_223 ;
F_7 ( V_10 , V_75 , & V_64 , & V_85 ) ) {
if ( ! F_112 ( V_85 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_85 -> V_30 . V_31 [ 3 ] ) )
V_247 += F_110 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) ;
}
V_247 += F_110 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) -
F_110 ( F_3 ( V_107 -> V_234 ) ) ;
if ( V_225 != V_236 ) {
V_249 -> V_239 = V_247 ;
V_222 -> V_67 -> V_239 += V_247 ;
}
}
return F_106 ( V_10 , V_222 , V_223 , V_107 , V_50 , V_91 , false ) ;
}
static int F_113 ( struct V_9 * V_10 , struct V_70 * V_222 ,
struct V_230 * V_107 ,
struct V_49 * V_50 , int * V_91 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
struct V_248 * V_249 ;
int V_246 ;
V_75 = F_108 ( V_50 , F_30 ( V_107 -> V_233 ) ) ;
V_95 = V_222 -> V_67 -> V_96 ;
V_246 = V_95 -> V_97 ;
V_249 = & V_222 -> V_67 -> V_251 [ V_246 ] ;
V_249 -> V_91 = - V_258 ;
V_249 -> V_239 = 0 ;
while ( V_75 -> V_25 != V_222 -> F_4 )
F_8 ( V_10 , V_75 ) ;
F_8 ( V_10 , V_75 ) ;
return F_106 ( V_10 , V_222 , NULL , V_107 , V_50 , V_91 , true ) ;
}
static int F_114 ( struct V_9 * V_10 , struct V_70 * V_222 ,
union V_3 * V_223 , struct V_230 * V_107 ,
struct V_49 * V_50 , int * V_91 )
{
struct V_11 * V_75 ;
union V_3 * V_85 ;
struct V_1 * V_64 ;
T_2 V_225 ;
V_75 = F_108 ( V_50 , F_30 ( V_107 -> V_233 ) ) ;
V_225 = F_68 ( F_3 ( V_107 -> V_234 ) ) ;
switch ( V_225 ) {
case V_133 :
if ( V_223 != V_222 -> F_4 ) {
F_24 ( V_10 , L_93
L_94 ) ;
if ( V_222 -> V_67 -> V_241 & V_242 )
* V_91 = - V_243 ;
else
* V_91 = 0 ;
} else {
* V_91 = 0 ;
}
break;
case V_244 :
if ( V_222 -> V_67 -> V_241 & V_242 )
* V_91 = - V_243 ;
else
* V_91 = 0 ;
break;
default:
break;
}
if ( V_225 == V_244 )
F_15 ( V_10 , L_95
L_96 ,
V_222 -> V_67 -> V_50 -> V_69 . V_259 ,
V_222 -> V_67 -> V_240 ,
F_110 ( F_3 ( V_107 -> V_234 ) ) ) ;
if ( V_223 == V_222 -> F_4 ) {
if ( F_110 ( F_3 ( V_107 -> V_234 ) ) != 0 ) {
V_222 -> V_67 -> V_239 =
V_222 -> V_67 -> V_240 -
F_110 ( F_3 ( V_107 -> V_234 ) ) ;
if ( V_222 -> V_67 -> V_240 <
V_222 -> V_67 -> V_239 ) {
F_24 ( V_10 , L_97
L_98 ,
F_110 ( F_3 ( V_107 -> V_234 ) ) ) ;
V_222 -> V_67 -> V_239 = 0 ;
if ( V_222 -> V_67 -> V_241 & V_242 )
* V_91 = - V_243 ;
else
* V_91 = 0 ;
}
if ( * V_91 == - V_245 ) {
if ( V_222 -> V_67 -> V_241 & V_242 )
* V_91 = - V_243 ;
else
* V_91 = 0 ;
}
} else {
V_222 -> V_67 -> V_239 =
V_222 -> V_67 -> V_240 ;
if ( * V_91 == - V_243 )
* V_91 = 0 ;
}
} else {
V_222 -> V_67 -> V_239 = 0 ;
for ( V_85 = V_75 -> V_25 , V_64 = V_75 -> V_24 ;
V_85 != V_223 ;
F_7 ( V_10 , V_75 , & V_64 , & V_85 ) ) {
if ( ! F_112 ( V_85 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_85 -> V_30 . V_31 [ 3 ] ) )
V_222 -> V_67 -> V_239 +=
F_110 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) ;
}
if ( V_225 != V_236 )
V_222 -> V_67 -> V_239 +=
F_110 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) -
F_110 ( F_3 ( V_107 -> V_234 ) ) ;
}
return F_106 ( V_10 , V_222 , V_223 , V_107 , V_50 , V_91 , false ) ;
}
static int F_115 ( struct V_9 * V_10 ,
struct V_230 * V_107 )
{
struct V_74 * V_232 ;
struct V_49 * V_50 ;
struct V_11 * V_75 ;
unsigned int V_45 ;
int V_46 ;
struct V_70 * V_222 = NULL ;
T_1 V_260 ;
struct V_1 * V_261 ;
union V_3 * V_223 ;
struct V_67 * V_67 = NULL ;
int V_91 = - V_245 ;
struct V_95 * V_95 ;
struct V_76 * V_77 ;
struct V_109 * V_262 ;
T_2 V_225 ;
int V_120 = 0 ;
int V_263 = 0 ;
V_45 = F_50 ( F_3 ( V_107 -> V_123 ) ) ;
V_232 = V_10 -> V_51 [ V_45 ] ;
if ( ! V_232 ) {
F_116 ( V_10 , L_99 ) ;
F_116 ( V_10 , L_100 ,
( unsigned long long ) F_1 (
V_10 -> V_13 -> V_24 ,
V_10 -> V_13 -> V_25 ) ,
F_117 ( F_30 ( V_107 -> V_233 ) ) ,
F_118 ( F_30 ( V_107 -> V_233 ) ) ,
F_3 ( V_107 -> V_234 ) ,
F_3 ( V_107 -> V_123 ) ) ;
F_15 ( V_10 , L_101 ) ;
F_119 ( V_10 , V_10 -> V_13 -> V_24 ) ;
return - V_264 ;
}
V_46 = F_107 ( F_3 ( V_107 -> V_123 ) ) - 1 ;
V_50 = & V_232 -> V_52 [ V_46 ] ;
V_75 = F_108 ( V_50 , F_30 ( V_107 -> V_233 ) ) ;
V_77 = F_29 ( V_10 , V_232 -> V_81 , V_46 ) ;
if ( ! V_75 ||
( F_3 ( V_77 -> V_137 ) & V_138 ) ==
V_265 ) {
F_116 ( V_10 , L_102
L_103 ) ;
F_116 ( V_10 , L_100 ,
( unsigned long long ) F_1 (
V_10 -> V_13 -> V_24 ,
V_10 -> V_13 -> V_25 ) ,
F_117 ( F_30 ( V_107 -> V_233 ) ) ,
F_118 ( F_30 ( V_107 -> V_233 ) ) ,
F_3 ( V_107 -> V_234 ) ,
F_3 ( V_107 -> V_123 ) ) ;
F_15 ( V_10 , L_101 ) ;
F_119 ( V_10 , V_10 -> V_13 -> V_24 ) ;
return - V_264 ;
}
if ( V_50 -> V_231 ) {
F_53 (tmp, &ep_ring->td_list)
V_263 ++ ;
}
V_260 = F_30 ( V_107 -> V_233 ) ;
V_225 = F_68 ( F_3 ( V_107 -> V_234 ) ) ;
switch ( V_225 ) {
case V_133 :
case V_244 :
break;
case V_237 :
F_15 ( V_10 , L_104 ) ;
break;
case V_236 :
F_15 ( V_10 , L_105 ) ;
break;
case V_238 :
F_15 ( V_10 , L_106 ) ;
V_50 -> V_53 |= V_56 ;
V_91 = - V_266 ;
break;
case V_135 :
F_24 ( V_10 , L_107 ) ;
V_91 = - V_267 ;
break;
case V_228 :
case V_226 :
F_15 ( V_10 , L_108 ) ;
V_91 = - V_257 ;
break;
case V_227 :
F_15 ( V_10 , L_109 ) ;
V_91 = - V_255 ;
break;
case V_268 :
F_24 ( V_10 , L_110 ) ;
V_91 = - V_269 ;
break;
case V_252 :
F_24 ( V_10 , L_111 ) ;
break;
case V_254 :
F_24 ( V_10 , L_112 ) ;
break;
case V_270 :
F_15 ( V_10 , L_113 ) ;
if ( ! F_21 ( & V_75 -> V_58 ) )
F_15 ( V_10 , L_114
L_115 ,
F_50 ( F_3 ( V_107 -> V_123 ) ) ,
V_46 ) ;
goto V_200;
case V_271 :
F_15 ( V_10 , L_116 ) ;
if ( ! F_21 ( & V_75 -> V_58 ) )
F_15 ( V_10 , L_117
L_115 ,
F_50 ( F_3 ( V_107 -> V_123 ) ) ,
V_46 ) ;
goto V_200;
case V_256 :
F_24 ( V_10 , L_118 ) ;
V_91 = - V_257 ;
break;
case V_272 :
V_50 -> V_231 = true ;
F_15 ( V_10 , L_119 ) ;
goto V_200;
default:
if ( F_105 ( V_10 , V_225 ) ) {
V_91 = 0 ;
break;
}
F_24 ( V_10 , L_120
L_121 ) ;
goto V_200;
}
do {
if ( F_21 ( & V_75 -> V_58 ) ) {
F_24 ( V_10 , L_122
L_123 ,
F_50 ( F_3 ( V_107 -> V_123 ) ) ,
V_46 ) ;
F_15 ( V_10 , L_124 ,
( F_3 ( V_107 -> V_123 ) &
V_156 ) >> 10 ) ;
F_120 ( V_10 , (union V_3 * ) V_107 ) ;
if ( V_50 -> V_231 ) {
V_50 -> V_231 = false ;
F_15 ( V_10 , L_125
L_126 ) ;
}
V_120 = 0 ;
goto V_200;
}
if ( V_50 -> V_231 && V_263 == 0 ) {
V_50 -> V_231 = false ;
F_15 ( V_10 , L_127
L_128 ) ;
V_120 = 0 ;
goto V_200;
}
V_222 = F_54 ( V_75 -> V_58 . V_14 , struct V_70 , V_58 ) ;
if ( V_50 -> V_231 )
V_263 -- ;
V_261 = F_100 ( V_75 -> V_24 , V_75 -> V_25 ,
V_222 -> F_4 , V_260 ) ;
if ( ! V_261 && V_225 == V_236 ) {
V_120 = 0 ;
goto V_200;
}
if ( ! V_261 ) {
if ( ! V_50 -> V_231 ||
! F_121 ( & V_222 -> V_67 -> V_50 -> V_69 ) ) {
if ( ( V_10 -> V_36 & V_273 ) &&
V_75 -> V_274 ) {
V_75 -> V_274 = false ;
V_120 = 0 ;
goto V_200;
}
F_116 ( V_10 ,
L_129
L_130 ) ;
return - V_125 ;
}
V_120 = F_113 ( V_10 , V_222 , V_107 , V_50 , & V_91 ) ;
goto V_200;
}
if ( V_225 == V_244 )
V_75 -> V_274 = true ;
else
V_75 -> V_274 = false ;
if ( V_50 -> V_231 ) {
F_15 ( V_10 , L_131 ) ;
V_50 -> V_231 = false ;
}
V_223 = & V_261 -> V_6 [ ( V_260 - V_261 -> V_8 ) /
sizeof( * V_223 ) ] ;
if ( F_112 ( V_223 -> V_30 . V_31 [ 3 ] ) ) {
F_15 ( V_10 ,
L_132 ) ;
goto V_200;
}
if ( F_122 ( & V_222 -> V_67 -> V_50 -> V_69 ) )
V_120 = F_109 ( V_10 , V_222 , V_223 , V_107 , V_50 ,
& V_91 ) ;
else if ( F_121 ( & V_222 -> V_67 -> V_50 -> V_69 ) )
V_120 = F_111 ( V_10 , V_222 , V_223 , V_107 , V_50 ,
& V_91 ) ;
else
V_120 = F_114 ( V_10 , V_222 , V_223 , V_107 ,
V_50 , & V_91 ) ;
V_200:
if ( V_225 == V_272 || ! V_50 -> V_231 ) {
F_8 ( V_10 , V_10 -> V_13 ) ;
}
if ( V_120 ) {
V_67 = V_222 -> V_67 ;
V_95 = V_67 -> V_96 ;
if ( F_122 ( & V_67 -> V_50 -> V_69 ) ||
( V_225 != V_238 &&
V_225 != V_227 ) )
F_45 ( V_10 , V_95 ) ;
F_42 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 ) ;
if ( ( V_67 -> V_239 != V_67 -> V_240 &&
( V_67 -> V_241 &
V_242 ) ) ||
( V_91 != 0 &&
! F_121 ( & V_67 -> V_50 -> V_69 ) ) )
F_15 ( V_10 , L_133
L_134 ,
V_67 , V_67 -> V_239 ,
V_67 -> V_240 ,
V_91 ) ;
F_43 ( & V_10 -> V_105 ) ;
if ( F_39 ( V_67 -> V_100 ) == V_101 )
V_91 = 0 ;
F_44 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 , V_91 ) ;
F_46 ( & V_10 -> V_105 ) ;
}
} while ( V_50 -> V_231 && V_225 != V_272 );
return 0 ;
}
static int F_123 ( struct V_9 * V_10 )
{
union V_3 * V_107 ;
int V_275 = 1 ;
int V_120 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_25 ) {
V_10 -> V_155 |= 1 << 1 ;
return 0 ;
}
V_107 = V_10 -> V_13 -> V_25 ;
if ( ( F_3 ( V_107 -> V_179 . V_123 ) & V_38 ) !=
V_10 -> V_13 -> V_27 ) {
V_10 -> V_155 |= 1 << 2 ;
return 0 ;
}
F_124 () ;
switch ( ( F_3 ( V_107 -> V_179 . V_123 ) & V_156 ) ) {
case F_32 ( V_276 ) :
F_75 ( V_10 , & V_107 -> V_179 ) ;
break;
case F_32 ( V_277 ) :
F_87 ( V_10 , V_107 ) ;
V_275 = 0 ;
break;
case F_32 ( V_278 ) :
V_120 = F_115 ( V_10 , & V_107 -> V_279 ) ;
if ( V_120 < 0 )
V_10 -> V_155 |= 1 << 9 ;
else
V_275 = 0 ;
break;
case F_32 ( V_280 ) :
F_85 ( V_10 , V_107 ) ;
break;
default:
if ( ( F_3 ( V_107 -> V_179 . V_123 ) & V_156 ) >=
F_32 ( 48 ) )
F_82 ( V_10 , V_107 ) ;
else
V_10 -> V_155 |= 1 << 3 ;
}
if ( V_10 -> V_116 & V_117 ) {
F_15 ( V_10 , L_135
L_136 ) ;
return 0 ;
}
if ( V_275 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_125 ( struct V_93 * V_94 )
{
struct V_9 * V_10 = F_126 ( V_94 ) ;
T_2 V_91 ;
union V_3 * V_4 ;
T_5 V_281 ;
union V_3 * V_282 ;
T_1 V_82 ;
F_46 ( & V_10 -> V_105 ) ;
V_4 = V_10 -> V_13 -> V_25 ;
V_91 = F_17 ( V_10 , & V_10 -> V_208 -> V_91 ) ;
if ( V_91 == 0xffffffff )
goto V_283;
if ( ! ( V_91 & V_284 ) ) {
F_43 ( & V_10 -> V_105 ) ;
return V_285 ;
}
if ( V_91 & V_286 ) {
F_24 ( V_10 , L_137 ) ;
F_60 ( V_10 ) ;
V_283:
F_43 ( & V_10 -> V_105 ) ;
return - V_125 ;
}
V_91 |= V_284 ;
F_16 ( V_10 , V_91 , & V_10 -> V_208 -> V_91 ) ;
if ( V_94 -> V_287 ) {
T_2 V_288 ;
V_288 = F_17 ( V_10 , & V_10 -> V_289 -> V_288 ) ;
V_288 |= V_290 ;
F_16 ( V_10 , V_288 , & V_10 -> V_289 -> V_288 ) ;
}
if ( V_10 -> V_116 & V_117 ) {
F_15 ( V_10 , L_138
L_139 ) ;
V_281 = F_127 ( V_10 , & V_10 -> V_289 -> V_291 ) ;
F_128 ( V_10 , V_281 | V_292 ,
& V_10 -> V_289 -> V_291 ) ;
F_43 ( & V_10 -> V_105 ) ;
return V_293 ;
}
V_282 = V_10 -> V_13 -> V_25 ;
while ( F_123 ( V_10 ) > 0 ) {}
V_281 = F_127 ( V_10 , & V_10 -> V_289 -> V_291 ) ;
if ( V_282 != V_10 -> V_13 -> V_25 ) {
V_82 = F_1 ( V_10 -> V_13 -> V_24 ,
V_10 -> V_13 -> V_25 ) ;
if ( V_82 == 0 )
F_24 ( V_10 , L_140
L_141 ) ;
V_281 &= V_294 ;
V_281 |= ( ( T_5 ) V_82 & ( T_5 ) ~ V_294 ) ;
}
V_281 |= V_292 ;
F_128 ( V_10 , V_281 , & V_10 -> V_289 -> V_291 ) ;
F_43 ( & V_10 -> V_105 ) ;
return V_293 ;
}
T_7 F_129 ( int V_287 , struct V_93 * V_94 )
{
return F_125 ( V_94 ) ;
}
static void F_130 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 ,
T_2 V_295 , T_2 V_296 , T_2 V_297 , T_2 V_298 )
{
struct V_65 * V_4 ;
V_4 = & V_12 -> V_20 -> V_30 ;
V_4 -> V_31 [ 0 ] = F_11 ( V_295 ) ;
V_4 -> V_31 [ 1 ] = F_11 ( V_296 ) ;
V_4 -> V_31 [ 2 ] = F_11 ( V_297 ) ;
V_4 -> V_31 [ 3 ] = F_11 ( V_298 ) ;
F_9 ( V_10 , V_12 , V_28 ) ;
}
static int F_131 ( struct V_9 * V_10 , struct V_11 * V_75 ,
T_2 V_53 , unsigned int V_39 , T_8 V_299 )
{
unsigned int V_300 ;
switch ( V_53 ) {
case V_265 :
F_24 ( V_10 , L_142 ) ;
return - V_301 ;
case V_302 :
F_24 ( V_10 , L_143 ) ;
return - V_303 ;
case V_229 :
F_15 ( V_10 , L_144 ) ;
case V_304 :
case V_305 :
break;
default:
F_116 ( V_10 , L_145 ) ;
return - V_303 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_75 , V_39 ) )
break;
if ( V_75 == V_10 -> V_112 ) {
F_116 ( V_10 , L_146 ) ;
return - V_306 ;
}
F_15 ( V_10 , L_147
L_148 ) ;
V_300 = V_39 - V_75 -> V_26 ;
if ( F_132 ( V_10 , V_75 , V_300 ,
V_299 ) ) {
F_116 ( V_10 , L_149 ) ;
return - V_306 ;
}
} ;
if ( F_6 ( V_75 ) ) {
struct V_11 * V_12 = V_75 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
if ( ! F_10 ( V_10 ) &&
! ( V_12 -> type == V_35 &&
( V_10 -> V_36 & V_37 ) ) )
V_14 -> V_16 . V_17 &= F_11 ( ~ V_32 ) ;
else
V_14 -> V_16 . V_17 |= F_11 ( V_32 ) ;
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_38 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
V_12 -> V_33 = V_12 -> V_33 -> V_14 ;
V_12 -> V_20 = V_12 -> V_33 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_133 ( struct V_9 * V_10 ,
struct V_74 * V_232 ,
unsigned int V_46 ,
unsigned int V_47 ,
unsigned int V_39 ,
struct V_67 * V_67 ,
unsigned int V_307 ,
T_8 V_299 )
{
int V_120 ;
struct V_95 * V_95 ;
struct V_70 * V_222 ;
struct V_11 * V_75 ;
struct V_76 * V_77 = F_29 ( V_10 , V_232 -> V_81 , V_46 ) ;
V_75 = F_66 ( V_232 , V_46 , V_47 ) ;
if ( ! V_75 ) {
F_15 ( V_10 , L_150 ,
V_47 ) ;
return - V_303 ;
}
V_120 = F_131 ( V_10 , V_75 ,
F_3 ( V_77 -> V_137 ) & V_138 ,
V_39 , V_299 ) ;
if ( V_120 )
return V_120 ;
V_95 = V_67 -> V_96 ;
V_222 = V_95 -> V_222 [ V_307 ] ;
F_134 ( & V_222 -> V_58 ) ;
F_134 ( & V_222 -> V_113 ) ;
if ( V_307 == 0 ) {
V_120 = F_135 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 ) ;
if ( F_48 ( V_120 ) )
return V_120 ;
}
V_222 -> V_67 = V_67 ;
F_136 ( & V_222 -> V_58 , & V_75 -> V_58 ) ;
V_222 -> V_63 = V_75 -> V_33 ;
V_222 -> V_86 = V_75 -> V_20 ;
V_95 -> V_222 [ V_307 ] = V_222 ;
return 0 ;
}
static unsigned int F_137 ( struct V_9 * V_10 , struct V_67 * V_67 )
{
int V_308 , V_39 , V_309 , V_191 , V_121 ;
struct V_310 * V_311 ;
V_311 = NULL ;
V_308 = V_67 -> V_312 ;
V_191 = V_67 -> V_240 ;
V_39 = 0 ;
F_138 (urb->sg, sg, num_sgs, i) {
unsigned int V_247 = F_139 ( V_311 ) ;
V_309 = V_313 -
( F_140 ( V_311 ) & ( V_313 - 1 ) ) ;
V_309 &= V_313 - 1 ;
if ( V_309 != 0 )
V_39 ++ ;
while ( V_309 < F_139 ( V_311 ) && V_309 < V_191 ) {
V_39 ++ ;
V_309 += V_313 ;
}
V_247 = F_141 ( int , V_247 , V_191 ) ;
V_191 -= V_247 ;
if ( V_191 == 0 )
break;
}
return V_39 ;
}
static void F_142 ( struct V_67 * V_67 , int V_39 , int V_309 )
{
if ( V_39 != 0 )
F_143 ( & V_67 -> V_68 -> V_68 , L_151
L_152 , V_314 ,
V_67 -> V_50 -> V_69 . V_259 , V_39 ) ;
if ( V_309 != V_67 -> V_240 )
F_143 ( & V_67 -> V_68 -> V_68 , L_153
L_154 ,
V_314 ,
V_67 -> V_50 -> V_69 . V_259 ,
V_309 , V_309 ,
V_67 -> V_240 ,
V_67 -> V_240 ) ;
}
static void F_144 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 , unsigned int V_47 , int V_315 ,
struct V_65 * V_216 )
{
F_12 () ;
if ( V_315 )
V_216 -> V_31 [ 3 ] |= F_11 ( V_315 ) ;
else
V_216 -> V_31 [ 3 ] &= F_11 ( ~ V_38 ) ;
F_18 ( V_10 , V_45 , V_46 , V_47 ) ;
}
int F_145 ( struct V_9 * V_10 , T_8 V_299 ,
struct V_67 * V_67 , int V_45 , unsigned int V_46 )
{
struct V_76 * V_77 = F_29 ( V_10 ,
V_10 -> V_51 [ V_45 ] -> V_81 , V_46 ) ;
int V_316 ;
int V_317 ;
V_316 = F_146 ( F_3 ( V_77 -> V_137 ) ) ;
V_317 = V_67 -> V_318 ;
if ( V_67 -> V_68 -> V_185 == V_319 ||
V_67 -> V_68 -> V_185 == V_320 )
V_317 *= 8 ;
if ( V_316 != V_317 ) {
if ( F_147 () )
F_148 ( & V_67 -> V_68 -> V_68 , L_155
L_156
L_157 ,
V_317 ,
V_317 == 1 ? L_158 : L_159 ,
V_316 ,
V_316 == 1 ? L_158 : L_159 ) ;
V_67 -> V_318 = V_316 ;
if ( V_67 -> V_68 -> V_185 == V_319 ||
V_67 -> V_68 -> V_185 == V_320 )
V_67 -> V_318 /= 8 ;
}
return F_149 ( V_10 , V_299 , V_67 , V_45 , V_46 ) ;
}
static T_2 F_150 ( unsigned int V_321 )
{
T_2 V_322 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_321 >> 10 ) >= V_322 )
return V_322 << 17 ;
else
return ( V_321 >> 10 ) << 17 ;
}
static T_2 F_151 ( int V_309 , int V_323 ,
unsigned int V_324 , struct V_67 * V_67 )
{
int V_325 ;
if ( V_309 == 0 && V_323 == 0 )
return 0 ;
V_325 = ( V_309 + V_323 ) /
F_152 ( & V_67 -> V_50 -> V_69 ) ;
return F_150 ( V_324 - V_325 ) ;
}
static int F_153 ( struct V_9 * V_10 , T_8 V_299 ,
struct V_67 * V_67 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_75 ;
unsigned int V_39 ;
struct V_95 * V_95 ;
struct V_70 * V_222 ;
struct V_310 * V_311 ;
int V_308 ;
int V_323 , V_326 , V_309 ;
unsigned int V_324 ;
bool V_86 ;
T_5 V_21 ;
bool V_28 ;
struct V_65 * V_216 ;
int V_315 ;
V_75 = F_25 ( V_10 , V_67 ) ;
if ( ! V_75 )
return - V_303 ;
V_39 = F_137 ( V_10 , V_67 ) ;
V_308 = V_67 -> V_312 ;
V_324 = F_154 ( V_67 -> V_240 ,
F_152 ( & V_67 -> V_50 -> V_69 ) ) ;
V_323 = F_133 ( V_10 , V_10 -> V_51 [ V_45 ] ,
V_46 , V_67 -> V_47 ,
V_39 , V_67 , 0 , V_299 ) ;
if ( V_323 < 0 )
return V_323 ;
V_95 = V_67 -> V_96 ;
V_222 = V_95 -> V_222 [ 0 ] ;
V_216 = & V_75 -> V_20 -> V_30 ;
V_315 = V_75 -> V_27 ;
V_309 = 0 ;
V_311 = V_67 -> V_311 ;
V_21 = ( T_5 ) F_140 ( V_311 ) ;
V_326 = F_139 ( V_311 ) ;
V_323 = V_313 - ( V_21 & ( V_313 - 1 ) ) ;
V_323 = F_141 ( int , V_323 , V_326 ) ;
if ( V_323 > V_67 -> V_240 )
V_323 = V_67 -> V_240 ;
V_86 = true ;
do {
T_2 V_31 = 0 ;
T_2 V_327 = 0 ;
T_2 V_321 = 0 ;
if ( V_86 ) {
V_86 = false ;
if ( V_315 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_75 -> V_27 ;
if ( V_39 > 1 ) {
V_31 |= V_32 ;
} else {
V_222 -> F_4 = V_75 -> V_20 ;
V_31 |= V_328 ;
}
if ( F_155 ( V_67 ) )
V_31 |= V_329 ;
if ( V_313 -
( V_21 & ( V_313 - 1 ) ) < V_323 ) {
F_24 ( V_10 , L_160 ) ;
F_15 ( V_10 , L_161 ,
( unsigned int ) ( V_21 + V_313 ) & ~ ( V_313 - 1 ) ,
( unsigned int ) V_21 + V_323 ) ;
}
if ( V_10 -> V_330 < 0x100 ) {
V_321 = F_150 (
V_67 -> V_240 -
V_309 ) ;
} else {
V_321 = F_151 ( V_309 ,
V_323 , V_324 , V_67 ) ;
}
V_327 = F_110 ( V_323 ) |
V_321 |
F_156 ( 0 ) ;
if ( V_39 > 1 )
V_28 = true ;
else
V_28 = false ;
F_130 ( V_10 , V_75 , V_28 ,
F_117 ( V_21 ) ,
F_118 ( V_21 ) ,
V_327 ,
V_31 | F_32 ( V_331 ) ) ;
-- V_39 ;
V_309 += V_323 ;
V_326 -= V_323 ;
if ( V_326 == 0 ) {
-- V_308 ;
if ( V_308 == 0 )
break;
V_311 = F_157 ( V_311 ) ;
V_21 = ( T_5 ) F_140 ( V_311 ) ;
V_326 = F_139 ( V_311 ) ;
} else {
V_21 += V_323 ;
}
V_323 = V_313 -
( V_21 & ( V_313 - 1 ) ) ;
V_323 = F_141 ( int , V_323 , V_326 ) ;
if ( V_309 + V_323 > V_67 -> V_240 )
V_323 =
V_67 -> V_240 - V_309 ;
} while ( V_309 < V_67 -> V_240 );
F_142 ( V_67 , V_39 , V_309 ) ;
F_144 ( V_10 , V_45 , V_46 , V_67 -> V_47 ,
V_315 , V_216 ) ;
return 0 ;
}
int F_149 ( struct V_9 * V_10 , T_8 V_299 ,
struct V_67 * V_67 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
struct V_70 * V_222 ;
int V_39 ;
struct V_65 * V_216 ;
bool V_86 ;
bool V_28 ;
int V_315 ;
T_2 V_31 , V_327 ;
int V_309 , V_323 , V_120 ;
unsigned int V_324 ;
T_5 V_21 ;
if ( V_67 -> V_308 )
return F_153 ( V_10 , V_299 , V_67 , V_45 , V_46 ) ;
V_75 = F_25 ( V_10 , V_67 ) ;
if ( ! V_75 )
return - V_303 ;
V_39 = 0 ;
V_309 = V_313 -
( V_67 -> V_332 & ( V_313 - 1 ) ) ;
V_309 &= V_313 - 1 ;
if ( V_309 != 0 || V_67 -> V_240 == 0 )
V_39 ++ ;
while ( V_309 < V_67 -> V_240 ) {
V_39 ++ ;
V_309 += V_313 ;
}
V_120 = F_133 ( V_10 , V_10 -> V_51 [ V_45 ] ,
V_46 , V_67 -> V_47 ,
V_39 , V_67 , 0 , V_299 ) ;
if ( V_120 < 0 )
return V_120 ;
V_95 = V_67 -> V_96 ;
V_222 = V_95 -> V_222 [ 0 ] ;
V_216 = & V_75 -> V_20 -> V_30 ;
V_315 = V_75 -> V_27 ;
V_309 = 0 ;
V_324 = F_154 ( V_67 -> V_240 ,
F_152 ( & V_67 -> V_50 -> V_69 ) ) ;
V_21 = ( T_5 ) V_67 -> V_332 ;
V_323 = V_313 -
( V_67 -> V_332 & ( V_313 - 1 ) ) ;
if ( V_323 > V_67 -> V_240 )
V_323 = V_67 -> V_240 ;
V_86 = true ;
do {
T_2 V_321 = 0 ;
V_31 = 0 ;
if ( V_86 ) {
V_86 = false ;
if ( V_315 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_75 -> V_27 ;
if ( V_39 > 1 ) {
V_31 |= V_32 ;
} else {
V_222 -> F_4 = V_75 -> V_20 ;
V_31 |= V_328 ;
}
if ( F_155 ( V_67 ) )
V_31 |= V_329 ;
if ( V_10 -> V_330 < 0x100 ) {
V_321 = F_150 (
V_67 -> V_240 -
V_309 ) ;
} else {
V_321 = F_151 ( V_309 ,
V_323 , V_324 , V_67 ) ;
}
V_327 = F_110 ( V_323 ) |
V_321 |
F_156 ( 0 ) ;
if ( V_39 > 1 )
V_28 = true ;
else
V_28 = false ;
F_130 ( V_10 , V_75 , V_28 ,
F_117 ( V_21 ) ,
F_118 ( V_21 ) ,
V_327 ,
V_31 | F_32 ( V_331 ) ) ;
-- V_39 ;
V_309 += V_323 ;
V_21 += V_323 ;
V_323 = V_67 -> V_240 - V_309 ;
if ( V_323 > V_313 )
V_323 = V_313 ;
} while ( V_309 < V_67 -> V_240 );
F_142 ( V_67 , V_39 , V_309 ) ;
F_144 ( V_10 , V_45 , V_46 , V_67 -> V_47 ,
V_315 , V_216 ) ;
return 0 ;
}
int F_158 ( struct V_9 * V_10 , T_8 V_299 ,
struct V_67 * V_67 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_75 ;
int V_39 ;
int V_120 ;
struct V_333 * V_334 ;
struct V_65 * V_216 ;
int V_315 ;
T_2 V_31 , V_327 ;
struct V_95 * V_95 ;
struct V_70 * V_222 ;
V_75 = F_25 ( V_10 , V_67 ) ;
if ( ! V_75 )
return - V_303 ;
if ( ! V_67 -> V_335 )
return - V_303 ;
V_39 = 2 ;
if ( V_67 -> V_240 > 0 )
V_39 ++ ;
V_120 = F_133 ( V_10 , V_10 -> V_51 [ V_45 ] ,
V_46 , V_67 -> V_47 ,
V_39 , V_67 , 0 , V_299 ) ;
if ( V_120 < 0 )
return V_120 ;
V_95 = V_67 -> V_96 ;
V_222 = V_95 -> V_222 [ 0 ] ;
V_216 = & V_75 -> V_20 -> V_30 ;
V_315 = V_75 -> V_27 ;
V_334 = (struct V_333 * ) V_67 -> V_335 ;
V_31 = 0 ;
V_31 |= V_336 | F_32 ( V_337 ) ;
if ( V_315 == 0 )
V_31 |= 0x1 ;
if ( V_10 -> V_330 == 0x100 ) {
if ( V_67 -> V_240 > 0 ) {
if ( V_334 -> V_338 & V_339 )
V_31 |= F_159 ( V_340 ) ;
else
V_31 |= F_159 ( V_341 ) ;
}
}
F_130 ( V_10 , V_75 , true ,
V_334 -> V_338 | V_334 -> V_342 << 8 | F_160 ( V_334 -> V_343 ) << 16 ,
F_160 ( V_334 -> V_344 ) | F_160 ( V_334 -> V_345 ) << 16 ,
F_110 ( 8 ) | F_156 ( 0 ) ,
V_31 ) ;
if ( F_155 ( V_67 ) )
V_31 = V_329 | F_32 ( V_346 ) ;
else
V_31 = F_32 ( V_346 ) ;
V_327 = F_110 ( V_67 -> V_240 ) |
F_150 ( V_67 -> V_240 ) |
F_156 ( 0 ) ;
if ( V_67 -> V_240 > 0 ) {
if ( V_334 -> V_338 & V_339 )
V_31 |= V_347 ;
F_130 ( V_10 , V_75 , true ,
F_117 ( V_67 -> V_332 ) ,
F_118 ( V_67 -> V_332 ) ,
V_327 ,
V_31 | V_75 -> V_27 ) ;
}
V_222 -> F_4 = V_75 -> V_20 ;
if ( V_67 -> V_240 > 0 && V_334 -> V_338 & V_339 )
V_31 = 0 ;
else
V_31 = V_347 ;
F_130 ( V_10 , V_75 , false ,
0 ,
0 ,
F_156 ( 0 ) ,
V_31 | V_328 | F_32 ( V_348 ) | V_75 -> V_27 ) ;
F_144 ( V_10 , V_45 , V_46 , 0 ,
V_315 , V_216 ) ;
return 0 ;
}
static int F_161 ( struct V_9 * V_10 ,
struct V_67 * V_67 , int V_121 )
{
int V_39 = 0 ;
T_5 V_21 , V_349 ;
V_21 = ( T_5 ) ( V_67 -> V_332 + V_67 -> V_251 [ V_121 ] . V_350 ) ;
V_349 = V_67 -> V_251 [ V_121 ] . V_99 ;
V_39 = F_162 ( V_349 + ( V_21 & ( V_313 - 1 ) ) ,
V_313 ) ;
if ( V_39 == 0 )
V_39 ++ ;
return V_39 ;
}
static unsigned int F_163 ( struct V_9 * V_10 ,
struct V_187 * V_188 ,
struct V_67 * V_67 , unsigned int V_324 )
{
unsigned int V_351 ;
if ( V_10 -> V_330 < 0x100 || V_188 -> V_185 != V_352 )
return 0 ;
V_351 = V_67 -> V_50 -> V_353 . V_354 ;
return F_154 ( V_324 , V_351 + 1 ) - 1 ;
}
static unsigned int F_164 ( struct V_9 * V_10 ,
struct V_187 * V_188 ,
struct V_67 * V_67 , unsigned int V_324 )
{
unsigned int V_351 ;
unsigned int V_355 ;
if ( V_10 -> V_330 < 0x100 )
return 0 ;
switch ( V_188 -> V_185 ) {
case V_352 :
V_351 = V_67 -> V_50 -> V_353 . V_354 ;
V_355 = V_324 % ( V_351 + 1 ) ;
if ( V_355 == 0 )
return V_351 ;
return V_355 - 1 ;
default:
if ( V_324 == 0 )
return 0 ;
return V_324 - 1 ;
}
}
static int F_165 ( struct V_9 * V_10 , T_8 V_299 ,
struct V_67 * V_67 , int V_45 , unsigned int V_46 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
struct V_70 * V_222 ;
int V_356 , V_357 ;
struct V_65 * V_216 ;
bool V_86 ;
int V_315 ;
T_2 V_31 , V_327 ;
int V_309 , V_323 , V_349 , V_358 , V_120 ;
T_5 V_359 , V_21 ;
int V_121 , V_122 ;
bool V_28 ;
V_75 = V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] . V_12 ;
V_356 = V_67 -> V_360 ;
if ( V_356 < 1 ) {
F_15 ( V_10 , L_162 ) ;
return - V_303 ;
}
V_359 = ( T_5 ) V_67 -> V_332 ;
V_216 = & V_75 -> V_20 -> V_30 ;
V_315 = V_75 -> V_27 ;
V_95 = V_67 -> V_96 ;
for ( V_121 = 0 ; V_121 < V_356 ; V_121 ++ ) {
unsigned int V_324 ;
unsigned int V_361 ;
unsigned int V_355 ;
V_86 = true ;
V_309 = 0 ;
V_21 = V_359 + V_67 -> V_251 [ V_121 ] . V_350 ;
V_349 = V_67 -> V_251 [ V_121 ] . V_99 ;
V_358 = V_349 ;
V_324 = F_154 ( V_349 ,
F_152 ( & V_67 -> V_50 -> V_69 ) ) ;
if ( V_324 == 0 )
V_324 ++ ;
V_361 = F_163 ( V_10 , V_67 -> V_68 , V_67 ,
V_324 ) ;
V_355 = F_164 ( V_10 ,
V_67 -> V_68 , V_67 , V_324 ) ;
V_357 = F_161 ( V_10 , V_67 , V_121 ) ;
V_120 = F_133 ( V_10 , V_10 -> V_51 [ V_45 ] , V_46 ,
V_67 -> V_47 , V_357 , V_67 , V_121 , V_299 ) ;
if ( V_120 < 0 ) {
if ( V_121 == 0 )
return V_120 ;
goto V_200;
}
V_222 = V_95 -> V_222 [ V_121 ] ;
for ( V_122 = 0 ; V_122 < V_357 ; V_122 ++ ) {
T_2 V_321 = 0 ;
V_31 = F_166 ( V_361 ) | F_167 ( V_355 ) ;
if ( V_86 ) {
V_31 |= F_32 ( V_362 ) ;
V_31 |= V_363 ;
if ( V_121 == 0 ) {
if ( V_315 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_75 -> V_27 ;
V_86 = false ;
} else {
V_31 |= F_32 ( V_331 ) ;
V_31 |= V_75 -> V_27 ;
}
if ( F_155 ( V_67 ) )
V_31 |= V_329 ;
if ( V_122 < V_357 - 1 ) {
V_31 |= V_32 ;
V_28 = true ;
} else {
V_222 -> F_4 = V_75 -> V_20 ;
V_31 |= V_328 ;
if ( V_10 -> V_330 == 0x100 ) {
if ( V_121 < V_356 - 1 )
V_31 |= V_364 ;
}
V_28 = false ;
}
V_323 = V_313 -
( V_21 & ( ( 1 << V_365 ) - 1 ) ) ;
if ( V_323 > V_358 )
V_323 = V_358 ;
if ( V_10 -> V_330 < 0x100 ) {
V_321 = F_150 (
V_349 - V_309 ) ;
} else {
V_321 = F_151 (
V_309 , V_323 ,
V_324 , V_67 ) ;
}
V_327 = F_110 ( V_323 ) |
V_321 |
F_156 ( 0 ) ;
F_130 ( V_10 , V_75 , V_28 ,
F_117 ( V_21 ) ,
F_118 ( V_21 ) ,
V_327 ,
V_31 ) ;
V_309 += V_323 ;
V_21 += V_323 ;
V_358 -= V_323 ;
}
if ( V_309 != V_349 ) {
F_116 ( V_10 , L_163 ) ;
V_120 = - V_303 ;
goto V_200;
}
}
if ( F_40 ( V_10 ) -> V_102 . V_103 == 0 ) {
if ( V_10 -> V_36 & V_104 )
F_168 () ;
}
F_40 ( V_10 ) -> V_102 . V_103 ++ ;
F_144 ( V_10 , V_45 , V_46 , V_67 -> V_47 ,
V_315 , V_216 ) ;
return 0 ;
V_200:
for ( V_121 -- ; V_121 >= 0 ; V_121 -- )
F_55 ( & V_95 -> V_222 [ V_121 ] -> V_58 ) ;
V_95 -> V_222 [ 0 ] -> F_4 = V_75 -> V_20 ;
F_31 ( V_10 , V_75 , V_95 -> V_222 [ 0 ] , true ) ;
V_75 -> V_20 = V_95 -> V_222 [ 0 ] -> V_86 ;
V_75 -> V_33 = V_95 -> V_222 [ 0 ] -> V_63 ;
V_75 -> V_27 = V_315 ;
V_75 -> V_26 = V_75 -> V_128 ;
F_42 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 ) ;
return V_120 ;
}
int F_169 ( struct V_9 * V_10 , T_8 V_299 ,
struct V_67 * V_67 , int V_45 , unsigned int V_46 )
{
struct V_74 * V_232 ;
struct V_11 * V_75 ;
struct V_76 * V_77 ;
int V_366 ;
int V_316 ;
int V_317 ;
int V_356 , V_39 , V_121 ;
int V_120 ;
V_232 = V_10 -> V_51 [ V_45 ] ;
V_75 = V_232 -> V_52 [ V_46 ] . V_12 ;
V_77 = F_29 ( V_10 , V_232 -> V_81 , V_46 ) ;
V_39 = 0 ;
V_356 = V_67 -> V_360 ;
for ( V_121 = 0 ; V_121 < V_356 ; V_121 ++ )
V_39 += F_161 ( V_10 , V_67 , V_121 ) ;
V_120 = F_131 ( V_10 , V_75 , F_3 ( V_77 -> V_137 ) & V_138 ,
V_39 , V_299 ) ;
if ( V_120 )
return V_120 ;
V_366 = F_17 ( V_10 , & V_10 -> V_367 -> V_368 ) ;
V_366 &= 0x3fff ;
V_67 -> V_366 = V_366 ;
if ( V_67 -> V_68 -> V_185 == V_319 ||
V_67 -> V_68 -> V_185 == V_320 )
V_67 -> V_366 >>= 3 ;
V_316 = F_146 ( F_3 ( V_77 -> V_137 ) ) ;
V_317 = V_67 -> V_318 ;
if ( V_67 -> V_68 -> V_185 == V_319 ||
V_67 -> V_68 -> V_185 == V_320 )
V_317 *= 8 ;
if ( V_316 != V_317 ) {
if ( F_147 () )
F_148 ( & V_67 -> V_68 -> V_68 , L_155
L_156
L_157 ,
V_317 ,
V_317 == 1 ? L_158 : L_159 ,
V_316 ,
V_316 == 1 ? L_158 : L_159 ) ;
V_67 -> V_318 = V_316 ;
if ( V_67 -> V_68 -> V_185 == V_319 ||
V_67 -> V_68 -> V_185 == V_320 )
V_67 -> V_318 /= 8 ;
}
V_75 -> V_128 = V_75 -> V_26 ;
return F_165 ( V_10 , V_299 , V_67 , V_45 , V_46 ) ;
}
static int F_170 ( struct V_9 * V_10 , T_2 V_295 , T_2 V_296 ,
T_2 V_297 , T_2 V_298 , bool V_369 )
{
int V_370 = V_10 -> V_371 ;
int V_120 ;
if ( ! V_369 )
V_370 ++ ;
V_120 = F_131 ( V_10 , V_10 -> V_112 , V_305 ,
V_370 , V_372 ) ;
if ( V_120 < 0 ) {
F_116 ( V_10 , L_164 ) ;
if ( V_369 )
F_116 ( V_10 , L_165
L_166 ) ;
return V_120 ;
}
F_130 ( V_10 , V_10 -> V_112 , false , V_295 , V_296 , V_297 ,
V_298 | V_10 -> V_112 -> V_27 ) ;
return 0 ;
}
int F_171 ( struct V_9 * V_10 , T_2 V_177 , T_2 V_45 )
{
return F_170 ( V_10 , 0 , 0 , 0 ,
F_32 ( V_177 ) | F_172 ( V_45 ) , false ) ;
}
int F_173 ( struct V_9 * V_10 , T_1 V_373 ,
T_2 V_45 )
{
return F_170 ( V_10 , F_117 ( V_373 ) ,
F_118 ( V_373 ) , 0 ,
F_32 ( V_169 ) | F_172 ( V_45 ) ,
false ) ;
}
int F_174 ( struct V_9 * V_10 ,
T_2 V_295 , T_2 V_296 , T_2 V_297 , T_2 V_298 )
{
return F_170 ( V_10 , V_295 , V_296 , V_297 , V_298 , false ) ;
}
int F_175 ( struct V_9 * V_10 , T_2 V_45 )
{
return F_170 ( V_10 , 0 , 0 , 0 ,
F_32 ( V_174 ) | F_172 ( V_45 ) ,
false ) ;
}
int F_71 ( struct V_9 * V_10 , T_1 V_373 ,
T_2 V_45 , bool V_369 )
{
return F_170 ( V_10 , F_117 ( V_373 ) ,
F_118 ( V_373 ) , 0 ,
F_32 ( V_161 ) | F_172 ( V_45 ) ,
V_369 ) ;
}
int F_176 ( struct V_9 * V_10 , T_1 V_373 ,
T_2 V_45 )
{
return F_170 ( V_10 , F_117 ( V_373 ) ,
F_118 ( V_373 ) , 0 ,
F_32 ( V_168 ) | F_172 ( V_45 ) ,
false ) ;
}
int F_177 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 , int V_374 )
{
T_2 V_375 = F_172 ( V_45 ) ;
T_2 V_376 = F_178 ( V_46 ) ;
T_2 type = F_32 ( V_170 ) ;
T_2 V_377 = F_179 ( V_374 ) ;
return F_170 ( V_10 , 0 , 0 , 0 ,
V_375 | V_376 | type | V_377 , false ) ;
}
static int F_34 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
struct V_1 * V_24 ,
union V_3 * V_378 , T_2 V_27 )
{
T_1 V_21 ;
T_2 V_375 = F_172 ( V_45 ) ;
T_2 V_376 = F_178 ( V_46 ) ;
T_2 V_379 = F_180 ( V_47 ) ;
T_2 type = F_32 ( V_171 ) ;
struct V_49 * V_50 ;
V_21 = F_1 ( V_24 , V_378 ) ;
if ( V_21 == 0 ) {
F_24 ( V_10 , L_167 ) ;
F_24 ( V_10 , L_168 ,
V_24 , V_378 ) ;
return 0 ;
}
V_50 = & V_10 -> V_51 [ V_45 ] -> V_52 [ V_46 ] ;
if ( ( V_50 -> V_53 & V_55 ) ) {
F_24 ( V_10 , L_167 ) ;
F_24 ( V_10 , L_169 ) ;
return 0 ;
}
V_50 -> V_141 = V_24 ;
V_50 -> V_130 = V_378 ;
return F_170 ( V_10 , F_117 ( V_21 ) | V_27 ,
F_118 ( V_21 ) , V_379 ,
V_375 | V_376 | type , false ) ;
}
int F_102 ( struct V_9 * V_10 , int V_45 ,
unsigned int V_46 )
{
T_2 V_375 = F_172 ( V_45 ) ;
T_2 V_376 = F_178 ( V_46 ) ;
T_2 type = F_32 ( V_173 ) ;
return F_170 ( V_10 , 0 , 0 , 0 , V_375 | V_376 | type ,
false ) ;
}
