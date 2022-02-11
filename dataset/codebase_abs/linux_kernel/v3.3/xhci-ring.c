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
}
V_12 -> V_25 = V_12 -> V_25 -> V_14 ;
V_12 -> V_22 = V_12 -> V_25 -> V_6 ;
V_14 = V_12 -> V_22 ;
}
V_23 = ( unsigned long long ) F_1 ( V_12 -> V_25 , V_12 -> V_22 ) ;
}
static void F_9 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_21 , bool V_27 , bool V_28 )
{
T_2 V_29 ;
union V_3 * V_14 ;
unsigned long long V_23 ;
V_29 = F_3 ( V_12 -> V_20 -> V_30 . V_31 [ 3 ] ) & V_32 ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_33 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_34 , V_14 ) ) {
if ( ! V_21 ) {
if ( V_12 != V_10 -> V_13 ) {
if ( ! V_29 && ! V_27 )
break;
if ( ! ( V_28 && ( V_10 -> V_35 & V_36 ) )
&& ! F_10 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_11 ( ~ V_32 ) ;
V_14 -> V_16 . V_17 |=
F_11 ( V_29 ) ;
}
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_37 ) ;
}
if ( F_2 ( V_10 , V_12 , V_12 -> V_34 , V_14 ) ) {
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
}
}
V_12 -> V_34 = V_12 -> V_34 -> V_14 ;
V_12 -> V_20 = V_12 -> V_34 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
V_23 = ( unsigned long long ) F_1 ( V_12 -> V_34 , V_12 -> V_20 ) ;
}
static int F_13 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_38 )
{
int V_39 ;
union V_3 * V_40 = V_12 -> V_20 ;
struct V_1 * V_34 = V_12 -> V_34 ;
struct V_1 * V_41 ;
unsigned int V_42 ;
while ( F_4 ( V_10 , V_12 , V_34 , V_40 ) ) {
V_34 = V_34 -> V_14 ;
V_40 = V_34 -> V_6 ;
}
if ( V_40 == V_12 -> V_22 ) {
V_42 = V_7 - 1 ;
for ( V_41 = V_34 -> V_14 ; V_41 != V_34 ;
V_41 = V_41 -> V_14 )
V_42 += V_7 - 1 ;
V_42 -= 1 ;
if ( V_38 > V_42 ) {
F_14 ( V_10 , L_1
L_2 ,
V_38 , V_42 ) ;
return 0 ;
}
return 1 ;
}
for ( V_39 = 0 ; V_39 <= V_38 ; ++ V_39 ) {
if ( V_40 == V_12 -> V_22 )
return 0 ;
V_40 ++ ;
while ( F_4 ( V_10 , V_12 , V_34 , V_40 ) ) {
V_34 = V_34 -> V_14 ;
V_40 = V_34 -> V_6 ;
}
}
return 1 ;
}
void F_15 ( struct V_9 * V_10 )
{
F_16 ( V_10 , L_3 ) ;
F_17 ( V_10 , V_43 , & V_10 -> V_44 -> V_45 [ 0 ] ) ;
F_18 ( V_10 , & V_10 -> V_44 -> V_45 [ 0 ] ) ;
}
void F_19 ( struct V_9 * V_10 ,
unsigned int V_46 ,
unsigned int V_47 ,
unsigned int V_48 )
{
T_3 T_4 * V_49 = & V_10 -> V_44 -> V_45 [ V_46 ] ;
struct V_50 * V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
unsigned int V_54 = V_51 -> V_54 ;
if ( ( V_54 & V_55 ) || ( V_54 & V_56 ) ||
( V_54 & V_57 ) )
return;
F_17 ( V_10 , F_20 ( V_47 , V_48 ) , V_49 ) ;
}
static void F_21 ( struct V_9 * V_10 ,
unsigned int V_46 ,
unsigned int V_47 )
{
unsigned int V_48 ;
struct V_50 * V_51 ;
V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
if ( ! ( V_51 -> V_54 & V_58 ) ) {
if ( ! ( F_22 ( & V_51 -> V_12 -> V_59 ) ) )
F_19 ( V_10 , V_46 , V_47 , 0 ) ;
return;
}
for ( V_48 = 1 ; V_48 < V_51 -> V_60 -> V_61 ;
V_48 ++ ) {
struct V_62 * V_60 = V_51 -> V_60 ;
if ( ! F_22 ( & V_60 -> V_63 [ V_48 ] -> V_59 ) )
F_19 ( V_10 , V_46 , V_47 ,
V_48 ) ;
}
}
static struct V_1 * F_23 (
struct V_1 * V_64 ,
union V_3 * V_4 , int * V_26 )
{
struct V_1 * V_41 = V_64 ;
struct V_65 * V_66 ;
while ( V_41 -> V_6 > V_4 ||
& V_41 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_66 = & V_41 -> V_6 [ V_7 - 1 ] . V_30 ;
if ( V_66 -> V_31 [ 3 ] & F_11 ( V_18 ) )
* V_26 ^= 0x1 ;
V_41 = V_41 -> V_14 ;
if ( V_41 == V_64 )
return NULL ;
}
return V_41 ;
}
static struct V_11 * F_24 ( struct V_9 * V_10 ,
unsigned int V_46 , unsigned int V_47 ,
unsigned int V_48 )
{
struct V_50 * V_51 ;
V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
if ( ! ( V_51 -> V_54 & V_58 ) )
return V_51 -> V_12 ;
if ( V_48 == 0 ) {
F_14 ( V_10 ,
L_4
L_5 ,
V_46 , V_47 ) ;
return NULL ;
}
if ( V_48 < V_51 -> V_60 -> V_61 )
return V_51 -> V_60 -> V_63 [ V_48 ] ;
F_14 ( V_10 ,
L_6
L_7
L_8 ,
V_46 , V_47 ,
V_51 -> V_60 -> V_61 - 1 ,
V_48 ) ;
return NULL ;
}
static struct V_11 * F_25 ( struct V_9 * V_10 ,
struct V_67 * V_67 )
{
return F_24 ( V_10 , V_67 -> V_68 -> V_46 ,
F_26 ( & V_67 -> V_51 -> V_69 ) , V_67 -> V_48 ) ;
}
void F_27 ( struct V_9 * V_10 ,
unsigned int V_46 , unsigned int V_47 ,
unsigned int V_48 , struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_74 * V_68 = V_10 -> V_52 [ V_46 ] ;
struct V_11 * V_75 ;
struct V_65 * V_4 ;
struct V_76 * V_77 ;
T_1 V_23 ;
V_75 = F_24 ( V_10 , V_46 ,
V_47 , V_48 ) ;
if ( ! V_75 ) {
F_14 ( V_10 , L_9
L_10 ,
V_48 ) ;
return;
}
V_73 -> V_78 = 0 ;
F_16 ( V_10 , L_11 ) ;
V_73 -> V_79 = F_23 ( V_71 -> V_64 ,
V_68 -> V_53 [ V_47 ] . V_80 ,
& V_73 -> V_78 ) ;
if ( ! V_73 -> V_79 ) {
F_28 ( 1 ) ;
return;
}
F_16 ( V_10 , L_12 ) ;
V_77 = F_29 ( V_10 , V_68 -> V_81 , V_47 ) ;
V_73 -> V_78 = 0x1 & F_30 ( V_77 -> V_82 ) ;
V_73 -> V_83 = V_71 -> F_4 ;
F_16 ( V_10 , L_13 ) ;
V_73 -> V_79 = F_23 ( V_73 -> V_79 ,
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
V_73 -> V_83 < V_68 -> V_53 [ V_47 ] . V_80 )
V_73 -> V_78 ^= 0x1 ;
F_16 ( V_10 , L_14 , V_73 -> V_78 ) ;
F_16 ( V_10 , L_15 ,
V_73 -> V_79 ) ;
V_23 = F_1 ( V_73 -> V_79 , V_73 -> V_83 ) ;
F_16 ( V_10 , L_16 ,
( unsigned long long ) V_23 ) ;
}
static void F_31 ( struct V_9 * V_10 , struct V_11 * V_75 ,
struct V_70 * V_71 , bool V_84 )
{
struct V_1 * V_41 ;
union V_3 * V_85 ;
for ( V_41 = V_71 -> V_64 , V_85 = V_71 -> V_86 ;
true ;
F_7 ( V_10 , V_75 , & V_41 , & V_85 ) ) {
if ( F_5 ( V_85 -> V_30 . V_31 [ 3 ] ) ) {
V_85 -> V_30 . V_31 [ 3 ] &= F_11 ( ~ V_32 ) ;
if ( V_84 )
V_85 -> V_30 . V_31 [ 3 ] ^=
F_11 ( V_37 ) ;
F_16 ( V_10 , L_17 ) ;
F_16 ( V_10 , L_18
L_19 ,
V_85 ,
( unsigned long long ) F_1 ( V_41 , V_85 ) ,
V_41 ,
( unsigned long long ) V_41 -> V_8 ) ;
} else {
V_85 -> V_30 . V_31 [ 0 ] = 0 ;
V_85 -> V_30 . V_31 [ 1 ] = 0 ;
V_85 -> V_30 . V_31 [ 2 ] = 0 ;
V_85 -> V_30 . V_31 [ 3 ] &= F_11 ( V_37 ) ;
if ( V_84 && V_85 != V_71 -> V_86 &&
V_85 != V_71 -> F_4 )
V_85 -> V_30 . V_31 [ 3 ] ^=
F_11 ( V_37 ) ;
V_85 -> V_30 . V_31 [ 3 ] |= F_11 (
F_32 ( V_87 ) ) ;
F_16 ( V_10 , L_20 ,
( unsigned long long )
F_1 ( V_41 , V_85 ) ) ;
}
if ( V_85 == V_71 -> F_4 )
break;
}
}
void F_33 ( struct V_9 * V_10 ,
unsigned int V_46 , unsigned int V_47 ,
unsigned int V_48 ,
struct V_72 * V_88 )
{
struct V_50 * V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
F_16 ( V_10 , L_21
L_22 ,
V_88 -> V_79 ,
( unsigned long long ) V_88 -> V_79 -> V_8 ,
V_88 -> V_83 ,
( unsigned long long ) F_1 ( V_88 -> V_79 , V_88 -> V_83 ) ,
V_88 -> V_78 ) ;
F_34 ( V_10 , V_46 , V_47 , V_48 ,
V_88 -> V_79 ,
V_88 -> V_83 ,
( T_2 ) V_88 -> V_78 ) ;
V_51 -> V_54 |= V_56 ;
}
static void F_35 ( struct V_9 * V_10 ,
struct V_50 * V_51 )
{
V_51 -> V_54 &= ~ V_55 ;
if ( F_36 ( & V_51 -> V_89 ) )
V_51 -> V_90 -- ;
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
if ( V_10 -> V_35 & V_104 )
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
unsigned int V_46 ;
unsigned int V_47 ;
struct V_74 * V_108 ;
struct V_11 * V_75 ;
struct V_50 * V_51 ;
struct V_109 * V_110 ;
struct V_70 * V_71 = NULL ;
struct V_70 * V_111 ;
struct V_72 V_88 ;
if ( F_48 ( F_49 (
F_3 ( V_10 -> V_112 -> V_22 -> V_30 . V_31 [ 3 ] ) ) ) ) {
V_46 = F_50 (
F_3 ( V_10 -> V_112 -> V_22 -> V_30 . V_31 [ 3 ] ) ) ;
V_108 = V_10 -> V_52 [ V_46 ] ;
if ( V_108 )
F_51 ( V_10 , V_108 ,
V_107 ) ;
else
F_14 ( V_10 , L_23
L_24 ,
V_46 ) ;
return;
}
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_46 = F_50 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_47 = F_52 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
if ( F_22 ( & V_51 -> V_113 ) ) {
F_35 ( V_10 , V_51 ) ;
V_51 -> V_114 = NULL ;
V_51 -> V_80 = NULL ;
F_21 ( V_10 , V_46 , V_47 ) ;
return;
}
F_53 (entry, &ep->cancelled_td_list) {
V_71 = F_54 ( V_110 , struct V_70 , V_113 ) ;
F_16 ( V_10 , L_25 ,
( unsigned long long ) F_1 (
V_71 -> V_64 , V_71 -> V_86 ) ) ;
V_75 = F_25 ( V_10 , V_71 -> V_67 ) ;
if ( ! V_75 ) {
F_14 ( V_10 , L_26
L_27 ,
V_71 -> V_67 ,
V_71 -> V_67 -> V_48 ) ;
goto V_115;
}
if ( V_71 == V_51 -> V_114 )
F_27 ( V_10 , V_46 , V_47 ,
V_71 -> V_67 -> V_48 ,
V_71 , & V_88 ) ;
else
F_31 ( V_10 , V_75 , V_71 , false ) ;
V_115:
F_55 ( & V_71 -> V_59 ) ;
}
V_111 = V_71 ;
F_35 ( V_10 , V_51 ) ;
if ( V_88 . V_83 && V_88 . V_79 ) {
F_33 ( V_10 ,
V_46 , V_47 ,
V_51 -> V_114 -> V_67 -> V_48 ,
& V_88 ) ;
F_15 ( V_10 ) ;
} else {
F_21 ( V_10 , V_46 , V_47 ) ;
}
V_51 -> V_114 = NULL ;
V_51 -> V_80 = NULL ;
do {
V_71 = F_54 ( V_51 -> V_113 . V_14 ,
struct V_70 , V_113 ) ;
F_55 ( & V_71 -> V_113 ) ;
F_37 ( V_10 , V_71 , 0 , L_28 ) ;
if ( V_10 -> V_116 & V_117 )
return;
} while ( V_71 != V_111 );
}
void F_56 ( unsigned long V_118 )
{
struct V_9 * V_10 ;
struct V_50 * V_51 ;
struct V_50 * V_119 ;
struct V_11 * V_12 ;
struct V_70 * V_71 ;
int V_120 , V_39 , V_121 ;
unsigned long V_122 ;
V_51 = (struct V_50 * ) V_118 ;
V_10 = V_51 -> V_10 ;
F_57 ( & V_10 -> V_105 , V_122 ) ;
V_51 -> V_90 -- ;
if ( V_10 -> V_116 & V_117 ) {
F_16 ( V_10 , L_29
L_30 ) ;
F_58 ( & V_10 -> V_105 , V_122 ) ;
return;
}
if ( ! ( V_51 -> V_90 == 0 && ( V_51 -> V_54 & V_55 ) ) ) {
F_16 ( V_10 , L_31
L_32 ) ;
F_58 ( & V_10 -> V_105 , V_122 ) ;
return;
}
F_14 ( V_10 , L_33 ) ;
F_14 ( V_10 , L_34 ) ;
V_10 -> V_116 |= V_117 ;
F_59 ( V_10 ) ;
F_58 ( & V_10 -> V_105 , V_122 ) ;
V_120 = F_60 ( V_10 ) ;
F_57 ( & V_10 -> V_105 , V_122 ) ;
if ( V_120 < 0 ) {
F_14 ( V_10 , L_35 ) ;
F_14 ( V_10 , L_36 ) ;
}
for ( V_39 = 0 ; V_39 < V_123 ; V_39 ++ ) {
if ( ! V_10 -> V_52 [ V_39 ] )
continue;
for ( V_121 = 0 ; V_121 < 31 ; V_121 ++ ) {
V_119 = & V_10 -> V_52 [ V_39 ] -> V_53 [ V_121 ] ;
V_12 = V_119 -> V_12 ;
if ( ! V_12 )
continue;
F_16 ( V_10 , L_37
L_38 , V_39 , V_121 ) ;
while ( ! F_22 ( & V_12 -> V_59 ) ) {
V_71 = F_61 ( & V_12 -> V_59 ,
struct V_70 ,
V_59 ) ;
F_55 ( & V_71 -> V_59 ) ;
if ( ! F_22 ( & V_71 -> V_113 ) )
F_55 ( & V_71 -> V_113 ) ;
F_37 ( V_10 , V_71 ,
- V_124 , L_39 ) ;
}
while ( ! F_22 ( & V_119 -> V_113 ) ) {
V_71 = F_61 (
& V_119 -> V_113 ,
struct V_70 ,
V_113 ) ;
F_55 ( & V_71 -> V_113 ) ;
F_37 ( V_10 , V_71 ,
- V_124 , L_39 ) ;
}
}
}
F_58 ( & V_10 -> V_105 , V_122 ) ;
F_16 ( V_10 , L_40 ) ;
F_62 ( F_40 ( V_10 ) -> V_125 ) ;
F_16 ( V_10 , L_41 ) ;
}
static void F_63 ( struct V_9 * V_10 ,
struct V_106 * V_107 ,
union V_3 * V_4 )
{
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
struct V_11 * V_75 ;
struct V_74 * V_68 ;
struct V_76 * V_77 ;
struct V_126 * V_127 ;
V_46 = F_50 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_47 = F_52 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_48 = F_64 ( F_3 ( V_4 -> V_30 . V_31 [ 2 ] ) ) ;
V_68 = V_10 -> V_52 [ V_46 ] ;
V_75 = F_65 ( V_68 , V_47 , V_48 ) ;
if ( ! V_75 ) {
F_14 ( V_10 , L_42
L_43 ,
V_48 ) ;
V_68 -> V_53 [ V_47 ] . V_54 &= ~ V_56 ;
return;
}
V_77 = F_29 ( V_10 , V_68 -> V_81 , V_47 ) ;
V_127 = F_66 ( V_10 , V_68 -> V_81 ) ;
if ( F_67 ( F_3 ( V_107 -> V_91 ) ) != V_128 ) {
unsigned int V_54 ;
unsigned int V_129 ;
switch ( F_67 ( F_3 ( V_107 -> V_91 ) ) ) {
case V_130 :
F_14 ( V_10 , L_44
L_45 ) ;
break;
case V_131 :
F_14 ( V_10 , L_46
L_47 ) ;
V_54 = F_3 ( V_77 -> V_132 ) ;
V_54 &= V_133 ;
V_129 = F_3 ( V_127 -> V_134 ) ;
V_129 = F_68 ( V_129 ) ;
F_16 ( V_10 , L_48 ,
V_129 , V_54 ) ;
break;
case V_135 :
F_14 ( V_10 , L_49
L_50 , V_46 ) ;
break;
default:
F_14 ( V_10 , L_51
L_52 ,
F_67 ( F_3 ( V_107 -> V_91 ) ) ) ;
break;
}
} else {
F_16 ( V_10 , L_53 ,
F_30 ( V_77 -> V_82 ) ) ;
if ( F_1 ( V_68 -> V_53 [ V_47 ] . V_136 ,
V_68 -> V_53 [ V_47 ] . V_137 ) ==
( F_30 ( V_77 -> V_82 ) & ~ ( V_138 ) ) ) {
V_75 -> V_25 = V_68 -> V_53 [ V_47 ] . V_136 ;
V_75 -> V_22 = V_68 -> V_53 [ V_47 ] . V_137 ;
} else {
F_14 ( V_10 , L_54
L_55 ) ;
F_14 ( V_10 , L_56 ,
V_68 -> V_53 [ V_47 ] . V_136 ,
V_68 -> V_53 [ V_47 ] . V_137 ) ;
}
}
V_68 -> V_53 [ V_47 ] . V_54 &= ~ V_56 ;
V_68 -> V_53 [ V_47 ] . V_136 = NULL ;
V_68 -> V_53 [ V_47 ] . V_137 = NULL ;
F_21 ( V_10 , V_46 , V_47 ) ;
}
static void F_69 ( struct V_9 * V_10 ,
struct V_106 * V_107 ,
union V_3 * V_4 )
{
int V_46 ;
unsigned int V_47 ;
V_46 = F_50 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_47 = F_52 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
F_16 ( V_10 , L_57 ,
F_67 ( F_3 ( V_107 -> V_91 ) ) ) ;
if ( V_10 -> V_35 & V_139 ) {
F_16 ( V_10 , L_58 ) ;
F_70 ( V_10 ,
V_10 -> V_52 [ V_46 ] -> V_140 -> V_8 , V_46 ,
false ) ;
F_15 ( V_10 ) ;
} else {
V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] . V_54 &= ~ V_57 ;
F_21 ( V_10 , V_46 , V_47 ) ;
}
}
static int F_51 ( struct V_9 * V_10 ,
struct V_74 * V_108 ,
struct V_106 * V_107 )
{
struct V_141 * V_142 ;
if ( F_22 ( & V_108 -> V_143 ) )
return 0 ;
V_142 = F_54 ( V_108 -> V_143 . V_14 ,
struct V_141 , V_143 ) ;
if ( V_10 -> V_112 -> V_22 != V_142 -> V_144 )
return 0 ;
V_142 -> V_91 = F_67 ( F_3 ( V_107 -> V_91 ) ) ;
F_71 ( & V_142 -> V_143 ) ;
if ( V_142 -> V_145 )
F_72 ( V_142 -> V_145 ) ;
else
F_73 ( V_10 , V_142 ) ;
return 1 ;
}
static void F_74 ( struct V_9 * V_10 ,
struct V_106 * V_107 )
{
int V_46 = F_50 ( F_3 ( V_107 -> V_122 ) ) ;
T_5 V_146 ;
T_1 V_147 ;
struct V_148 * V_149 ;
struct V_74 * V_108 ;
unsigned int V_47 ;
struct V_11 * V_75 ;
unsigned int V_54 ;
V_146 = F_30 ( V_107 -> V_150 ) ;
V_147 = F_1 ( V_10 -> V_112 -> V_25 ,
V_10 -> V_112 -> V_22 ) ;
if ( V_147 == 0 ) {
V_10 -> V_151 |= 1 << 4 ;
return;
}
if ( V_146 != ( T_5 ) V_147 ) {
V_10 -> V_151 |= 1 << 5 ;
return;
}
switch ( F_3 ( V_10 -> V_112 -> V_22 -> V_30 . V_31 [ 3 ] )
& V_152 ) {
case F_32 ( V_153 ) :
if ( F_67 ( F_3 ( V_107 -> V_91 ) ) == V_128 )
V_10 -> V_46 = V_46 ;
else
V_10 -> V_46 = 0 ;
F_72 ( & V_10 -> V_154 ) ;
break;
case F_32 ( V_155 ) :
if ( V_10 -> V_52 [ V_46 ] ) {
if ( V_10 -> V_35 & V_156 )
F_75 ( V_10 ,
V_10 -> V_52 [ V_46 ] , true ) ;
F_76 ( V_10 , V_46 ) ;
}
break;
case F_32 ( V_157 ) :
V_108 = V_10 -> V_52 [ V_46 ] ;
if ( F_51 ( V_10 , V_108 , V_107 ) )
break;
V_149 = F_77 ( V_10 ,
V_108 -> V_140 ) ;
V_47 = F_78 ( F_3 ( V_149 -> V_158 ) ) - 1 ;
if ( V_10 -> V_35 & V_139 &&
V_47 != ( unsigned int ) - 1 &&
F_3 ( V_149 -> V_158 ) - V_159 ==
F_3 ( V_149 -> V_160 ) ) {
V_75 = V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] . V_12 ;
V_54 = V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] . V_54 ;
if ( ! ( V_54 & V_57 ) )
goto V_161;
F_16 ( V_10 , L_59
L_60 ,
V_47 , V_54 ) ;
V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] . V_54 &=
~ V_57 ;
F_21 ( V_10 , V_46 , V_47 ) ;
break;
}
V_161:
F_16 ( V_10 , L_61 ) ;
V_10 -> V_52 [ V_46 ] -> V_162 =
F_67 ( F_3 ( V_107 -> V_91 ) ) ;
F_72 ( & V_10 -> V_52 [ V_46 ] -> V_163 ) ;
break;
case F_32 ( V_164 ) :
V_108 = V_10 -> V_52 [ V_46 ] ;
if ( F_51 ( V_10 , V_108 , V_107 ) )
break;
V_10 -> V_52 [ V_46 ] -> V_162 = F_67 ( F_3 ( V_107 -> V_91 ) ) ;
F_72 ( & V_10 -> V_52 [ V_46 ] -> V_163 ) ;
break;
case F_32 ( V_165 ) :
V_10 -> V_52 [ V_46 ] -> V_162 = F_67 ( F_3 ( V_107 -> V_91 ) ) ;
F_72 ( & V_10 -> V_154 ) ;
break;
case F_32 ( V_166 ) :
F_47 ( V_10 , V_10 -> V_112 -> V_22 , V_107 ) ;
break;
case F_32 ( V_167 ) :
F_63 ( V_10 , V_107 , V_10 -> V_112 -> V_22 ) ;
break;
case F_32 ( V_168 ) :
break;
case F_32 ( V_169 ) :
F_69 ( V_10 , V_107 , V_10 -> V_112 -> V_22 ) ;
break;
case F_32 ( V_170 ) :
F_16 ( V_10 , L_62 ) ;
V_46 = F_50 (
F_3 ( V_10 -> V_112 -> V_22 -> V_30 . V_31 [ 3 ] ) ) ;
V_108 = V_10 -> V_52 [ V_46 ] ;
if ( V_108 )
F_51 ( V_10 , V_108 , V_107 ) ;
else
F_14 ( V_10 , L_63
L_64 , V_46 ) ;
break;
case F_32 ( V_171 ) :
if ( ! ( V_10 -> V_35 & V_172 ) ) {
V_10 -> V_151 |= 1 << 6 ;
break;
}
F_16 ( V_10 , L_65 ,
F_79 ( F_3 ( V_107 -> V_91 ) ) ,
F_80 ( F_3 ( V_107 -> V_91 ) ) ) ;
break;
default:
V_10 -> V_151 |= 1 << 6 ;
break;
}
F_8 ( V_10 , V_10 -> V_112 , false ) ;
}
static void F_81 ( struct V_9 * V_10 ,
union V_3 * V_107 )
{
T_2 V_173 ;
V_173 = F_82 ( F_3 ( V_107 -> V_30 . V_31 [ 3 ] ) ) ;
F_16 ( V_10 , L_66 , V_173 ) ;
if ( V_173 == V_174 && ( V_10 -> V_35 & V_172 ) )
F_74 ( V_10 , & V_107 -> V_175 ) ;
}
static unsigned int F_83 ( struct V_93 * V_94 ,
struct V_9 * V_10 , T_2 V_176 )
{
unsigned int V_39 ;
unsigned int V_177 = 0 ;
for ( V_39 = 0 ; V_39 < ( V_176 - 1 ) ; V_39 ++ ) {
T_6 V_178 = V_10 -> V_179 [ V_39 ] ;
if ( V_178 == 0 || V_178 == V_180 )
continue;
if ( ( V_178 == 0x03 ) == ( V_94 -> V_181 == V_182 ) )
V_177 ++ ;
}
return V_177 ;
}
static void F_84 ( struct V_9 * V_10 ,
union V_3 * V_107 )
{
struct V_93 * V_94 ;
T_2 V_176 ;
T_2 V_183 , V_184 ;
int V_185 ;
int V_46 ;
unsigned int V_186 ;
T_6 V_187 ;
struct V_188 * V_189 ;
T_3 T_4 * * V_179 ;
bool V_190 = false ;
if ( F_67 ( F_3 ( V_107 -> V_30 . V_31 [ 2 ] ) ) != V_128 ) {
F_14 ( V_10 , L_67 ) ;
V_10 -> V_151 |= 1 << 8 ;
}
V_176 = F_85 ( F_3 ( V_107 -> V_30 . V_31 [ 0 ] ) ) ;
F_16 ( V_10 , L_68 , V_176 ) ;
V_185 = F_86 ( V_10 -> V_191 ) ;
if ( ( V_176 <= 0 ) || ( V_176 > V_185 ) ) {
F_14 ( V_10 , L_69 , V_176 ) ;
V_190 = true ;
goto V_192;
}
V_187 = V_10 -> V_179 [ V_176 - 1 ] ;
if ( V_187 == 0 ) {
F_14 ( V_10 , L_70
L_71 ,
V_176 ) ;
V_190 = true ;
goto V_192;
}
if ( V_187 == V_180 ) {
F_14 ( V_10 , L_72
L_71 ,
V_176 ) ;
V_190 = true ;
goto V_192;
}
V_94 = F_40 ( V_10 ) ;
if ( ( V_187 == 0x03 ) != ( V_94 -> V_181 == V_182 ) )
V_94 = V_10 -> V_193 ;
V_189 = & V_10 -> V_189 [ F_87 ( V_94 ) ] ;
if ( V_94 -> V_181 == V_182 )
V_179 = V_10 -> V_194 ;
else
V_179 = V_10 -> V_195 ;
V_186 = F_83 ( V_94 , V_10 ,
V_176 ) ;
V_183 = F_18 ( V_10 , V_179 [ V_186 ] ) ;
if ( V_94 -> V_73 == V_196 ) {
F_16 ( V_10 , L_73 ) ;
F_88 ( V_94 ) ;
}
if ( ( V_183 & V_197 ) && ( V_183 & V_198 ) == V_199 ) {
F_16 ( V_10 , L_74 , V_176 ) ;
V_184 = F_18 ( V_10 , & V_10 -> V_200 -> V_142 ) ;
if ( ! ( V_184 & V_201 ) ) {
F_14 ( V_10 , L_75 ) ;
goto V_192;
}
if ( F_89 ( V_183 ) ) {
F_16 ( V_10 , L_76 , V_176 ) ;
F_90 ( V_10 , V_179 , V_186 ,
V_202 ) ;
V_46 = F_91 ( V_94 , V_10 ,
V_186 + 1 ) ;
if ( ! V_46 ) {
F_16 ( V_10 , L_77 ) ;
goto V_192;
}
F_92 ( V_10 , V_46 ) ;
F_16 ( V_10 , L_78 , V_176 ) ;
F_93 ( V_10 , V_179 ,
V_186 , V_197 ) ;
} else {
F_16 ( V_10 , L_79 , V_176 ) ;
V_189 -> V_203 [ V_186 ] = V_204 +
F_94 ( 20 ) ;
F_95 ( & V_94 -> V_205 ,
V_189 -> V_203 [ V_186 ] ) ;
}
}
if ( V_94 -> V_181 != V_182 )
F_93 ( V_10 , V_179 , V_186 ,
V_197 ) ;
V_192:
F_8 ( V_10 , V_10 -> V_13 , true ) ;
if ( V_190 )
return;
F_43 ( & V_10 -> V_105 ) ;
F_96 ( V_94 ) ;
F_46 ( & V_10 -> V_105 ) ;
}
struct V_1 * F_97 ( struct V_1 * V_64 ,
union V_3 * V_206 ,
union V_3 * V_207 ,
T_1 V_208 )
{
T_1 V_209 ;
T_1 V_210 ;
T_1 V_211 ;
struct V_1 * V_41 ;
V_209 = F_1 ( V_64 , V_206 ) ;
V_41 = V_64 ;
do {
if ( V_209 == 0 )
return NULL ;
V_210 = F_1 ( V_41 ,
& V_41 -> V_6 [ V_7 - 1 ] ) ;
V_211 = F_1 ( V_41 , V_207 ) ;
if ( V_211 > 0 ) {
if ( V_209 <= V_211 ) {
if ( V_208 >= V_209 && V_208 <= V_211 )
return V_41 ;
} else {
if ( ( V_208 >= V_209 &&
V_208 <= V_210 ) ||
( V_208 >= V_41 -> V_8 &&
V_208 <= V_211 ) )
return V_41 ;
}
return NULL ;
} else {
if ( V_208 >= V_209 && V_208 <= V_210 )
return V_41 ;
}
V_41 = V_41 -> V_14 ;
V_209 = F_1 ( V_41 , & V_41 -> V_6 [ 0 ] ) ;
} while ( V_41 != V_64 );
return NULL ;
}
static void F_98 ( struct V_9 * V_10 ,
unsigned int V_46 , unsigned int V_47 ,
unsigned int V_48 ,
struct V_70 * V_212 , union V_3 * V_213 )
{
struct V_50 * V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
V_51 -> V_54 |= V_57 ;
V_51 -> V_114 = V_212 ;
V_51 -> V_80 = V_213 ;
V_51 -> V_214 = V_48 ;
F_99 ( V_10 , V_46 , V_47 ) ;
F_100 ( V_10 , V_212 -> V_67 -> V_68 , V_47 ) ;
V_51 -> V_114 = NULL ;
V_51 -> V_80 = NULL ;
V_51 -> V_214 = 0 ;
F_15 ( V_10 ) ;
}
static int F_101 ( struct V_9 * V_10 ,
struct V_76 * V_77 ,
unsigned int V_215 )
{
if ( V_215 == V_216 ||
V_215 == V_217 ||
V_215 == V_218 )
if ( ( V_77 -> V_132 & F_11 ( V_133 ) ) ==
F_11 ( V_219 ) )
return 1 ;
return 0 ;
}
int F_102 ( struct V_9 * V_10 , unsigned int V_215 )
{
if ( V_215 >= 224 && V_215 <= 255 ) {
F_16 ( V_10 , L_80 ,
V_215 ) ;
F_16 ( V_10 , L_81 ) ;
return 1 ;
}
return 0 ;
}
static int F_103 ( struct V_9 * V_10 , struct V_70 * V_212 ,
union V_3 * V_213 , struct V_220 * V_107 ,
struct V_50 * V_51 , int * V_91 , bool V_221 )
{
struct V_74 * V_222 ;
struct V_11 * V_75 ;
unsigned int V_46 ;
int V_47 ;
struct V_67 * V_67 = NULL ;
struct V_76 * V_77 ;
int V_120 = 0 ;
struct V_95 * V_95 ;
T_2 V_215 ;
V_46 = F_50 ( F_3 ( V_107 -> V_122 ) ) ;
V_222 = V_10 -> V_52 [ V_46 ] ;
V_47 = F_104 ( F_3 ( V_107 -> V_122 ) ) - 1 ;
V_75 = F_105 ( V_51 , F_30 ( V_107 -> V_223 ) ) ;
V_77 = F_29 ( V_10 , V_222 -> V_81 , V_47 ) ;
V_215 = F_67 ( F_3 ( V_107 -> V_224 ) ) ;
if ( V_221 )
goto V_225;
if ( V_215 == V_226 ||
V_215 == V_227 ) {
V_51 -> V_114 = V_212 ;
V_51 -> V_80 = V_213 ;
return 0 ;
} else {
if ( V_215 == V_228 ) {
V_51 -> V_114 = V_212 ;
V_51 -> V_80 = V_213 ;
V_51 -> V_214 = V_75 -> V_48 ;
} else if ( F_101 ( V_10 ,
V_77 , V_215 ) ) {
F_98 ( V_10 ,
V_46 , V_47 , V_75 -> V_48 ,
V_212 , V_213 ) ;
} else {
while ( V_75 -> V_22 != V_212 -> F_4 )
F_8 ( V_10 , V_75 , false ) ;
F_8 ( V_10 , V_75 , false ) ;
}
V_225:
V_67 = V_212 -> V_67 ;
V_95 = V_67 -> V_96 ;
if ( V_67 -> V_229 > V_67 -> V_230 ) {
F_14 ( V_10 , L_82
L_83
L_84 ,
V_67 -> V_230 ,
V_67 -> V_229 ) ;
V_67 -> V_229 = 0 ;
if ( V_212 -> V_67 -> V_231 & V_232 )
* V_91 = - V_233 ;
else
* V_91 = 0 ;
}
F_55 ( & V_212 -> V_59 ) ;
if ( ! F_22 ( & V_212 -> V_113 ) )
F_55 ( & V_212 -> V_113 ) ;
V_95 -> V_97 ++ ;
if ( V_95 -> V_97 == V_95 -> V_99 ) {
V_120 = 1 ;
if ( F_39 ( V_67 -> V_100 ) == V_101 ) {
F_40 ( V_10 ) -> V_102 . V_103 -- ;
if ( F_40 ( V_10 ) -> V_102 . V_103
== 0 ) {
if ( V_10 -> V_35 & V_104 )
F_41 () ;
}
}
}
}
return V_120 ;
}
static int F_106 ( struct V_9 * V_10 , struct V_70 * V_212 ,
union V_3 * V_213 , struct V_220 * V_107 ,
struct V_50 * V_51 , int * V_91 )
{
struct V_74 * V_222 ;
struct V_11 * V_75 ;
unsigned int V_46 ;
int V_47 ;
struct V_76 * V_77 ;
T_2 V_215 ;
V_46 = F_50 ( F_3 ( V_107 -> V_122 ) ) ;
V_222 = V_10 -> V_52 [ V_46 ] ;
V_47 = F_104 ( F_3 ( V_107 -> V_122 ) ) - 1 ;
V_75 = F_105 ( V_51 , F_30 ( V_107 -> V_223 ) ) ;
V_77 = F_29 ( V_10 , V_222 -> V_81 , V_47 ) ;
V_215 = F_67 ( F_3 ( V_107 -> V_224 ) ) ;
switch ( V_215 ) {
case V_128 :
if ( V_213 == V_75 -> V_22 ) {
F_14 ( V_10 , L_85
L_86 ) ;
* V_91 = - V_124 ;
} else if ( V_213 != V_212 -> F_4 ) {
F_14 ( V_10 , L_87
L_86 ) ;
* V_91 = - V_124 ;
} else {
* V_91 = 0 ;
}
break;
case V_234 :
if ( V_212 -> V_67 -> V_231 & V_232 )
* V_91 = - V_233 ;
else
* V_91 = 0 ;
break;
case V_226 :
case V_227 :
return F_103 ( V_10 , V_212 , V_213 , V_107 , V_51 , V_91 , false ) ;
default:
if ( ! F_101 ( V_10 ,
V_77 , V_215 ) )
break;
F_16 ( V_10 , L_88
L_89 ,
V_215 , V_47 ) ;
case V_228 :
if ( V_213 != V_75 -> V_22 &&
V_213 != V_212 -> F_4 )
V_212 -> V_67 -> V_229 =
V_212 -> V_67 -> V_230
- F_107 ( F_3 ( V_107 -> V_224 ) ) ;
else
V_212 -> V_67 -> V_229 = 0 ;
F_98 ( V_10 ,
V_46 , V_47 , 0 , V_212 , V_213 ) ;
return F_103 ( V_10 , V_212 , V_213 , V_107 , V_51 , V_91 , true ) ;
}
if ( V_213 != V_75 -> V_22 ) {
if ( V_213 == V_212 -> F_4 ) {
if ( V_212 -> V_67 -> V_229 != 0 ) {
if ( ( * V_91 == - V_235 || * V_91 == 0 ) &&
( V_212 -> V_67 -> V_231
& V_232 ) )
* V_91 = - V_233 ;
} else {
V_212 -> V_67 -> V_229 =
V_212 -> V_67 -> V_230 ;
}
} else {
V_212 -> V_67 -> V_229 =
V_212 -> V_67 -> V_230 -
F_107 ( F_3 ( V_107 -> V_224 ) ) ;
F_16 ( V_10 , L_90
L_91 ) ;
return 0 ;
}
}
return F_103 ( V_10 , V_212 , V_213 , V_107 , V_51 , V_91 , false ) ;
}
static int F_108 ( struct V_9 * V_10 , struct V_70 * V_212 ,
union V_3 * V_213 , struct V_220 * V_107 ,
struct V_50 * V_51 , int * V_91 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
int V_236 ;
int V_237 = 0 ;
union V_3 * V_85 ;
struct V_1 * V_41 ;
struct V_238 * V_239 ;
T_2 V_215 ;
bool V_240 = false ;
V_75 = F_105 ( V_51 , F_30 ( V_107 -> V_223 ) ) ;
V_215 = F_67 ( F_3 ( V_107 -> V_224 ) ) ;
V_95 = V_212 -> V_67 -> V_96 ;
V_236 = V_95 -> V_97 ;
V_239 = & V_212 -> V_67 -> V_241 [ V_236 ] ;
switch ( V_215 ) {
case V_128 :
V_239 -> V_91 = 0 ;
break;
case V_234 :
V_239 -> V_91 = V_212 -> V_67 -> V_231 & V_232 ?
- V_233 : 0 ;
break;
case V_242 :
V_239 -> V_91 = - V_243 ;
V_240 = true ;
break;
case V_244 :
case V_217 :
V_239 -> V_91 = - V_245 ;
V_240 = true ;
break;
case V_246 :
case V_228 :
V_239 -> V_91 = - V_247 ;
V_240 = true ;
break;
case V_227 :
case V_226 :
break;
default:
V_239 -> V_91 = - 1 ;
break;
}
if ( V_215 == V_128 || V_240 ) {
V_239 -> V_229 = V_239 -> V_99 ;
V_212 -> V_67 -> V_229 += V_239 -> V_99 ;
} else {
for ( V_85 = V_75 -> V_22 ,
V_41 = V_75 -> V_25 ; V_85 != V_213 ;
F_7 ( V_10 , V_75 , & V_41 , & V_85 ) ) {
if ( ! F_109 ( V_85 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_85 -> V_30 . V_31 [ 3 ] ) )
V_237 += F_107 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) ;
}
V_237 += F_107 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) -
F_107 ( F_3 ( V_107 -> V_224 ) ) ;
if ( V_215 != V_226 ) {
V_239 -> V_229 = V_237 ;
V_212 -> V_67 -> V_229 += V_237 ;
}
}
return F_103 ( V_10 , V_212 , V_213 , V_107 , V_51 , V_91 , false ) ;
}
static int F_110 ( struct V_9 * V_10 , struct V_70 * V_212 ,
struct V_220 * V_107 ,
struct V_50 * V_51 , int * V_91 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
struct V_238 * V_239 ;
int V_236 ;
V_75 = F_105 ( V_51 , F_30 ( V_107 -> V_223 ) ) ;
V_95 = V_212 -> V_67 -> V_96 ;
V_236 = V_95 -> V_97 ;
V_239 = & V_212 -> V_67 -> V_241 [ V_236 ] ;
V_239 -> V_91 = - V_248 ;
V_239 -> V_229 = 0 ;
while ( V_75 -> V_22 != V_212 -> F_4 )
F_8 ( V_10 , V_75 , false ) ;
F_8 ( V_10 , V_75 , false ) ;
return F_103 ( V_10 , V_212 , NULL , V_107 , V_51 , V_91 , true ) ;
}
static int F_111 ( struct V_9 * V_10 , struct V_70 * V_212 ,
union V_3 * V_213 , struct V_220 * V_107 ,
struct V_50 * V_51 , int * V_91 )
{
struct V_11 * V_75 ;
union V_3 * V_85 ;
struct V_1 * V_41 ;
T_2 V_215 ;
V_75 = F_105 ( V_51 , F_30 ( V_107 -> V_223 ) ) ;
V_215 = F_67 ( F_3 ( V_107 -> V_224 ) ) ;
switch ( V_215 ) {
case V_128 :
if ( V_213 != V_212 -> F_4 ) {
F_14 ( V_10 , L_92
L_93 ) ;
if ( V_212 -> V_67 -> V_231 & V_232 )
* V_91 = - V_233 ;
else
* V_91 = 0 ;
} else {
* V_91 = 0 ;
}
break;
case V_234 :
if ( V_212 -> V_67 -> V_231 & V_232 )
* V_91 = - V_233 ;
else
* V_91 = 0 ;
break;
default:
break;
}
if ( V_215 == V_234 )
F_16 ( V_10 , L_94
L_95 ,
V_212 -> V_67 -> V_51 -> V_69 . V_249 ,
V_212 -> V_67 -> V_230 ,
F_107 ( F_3 ( V_107 -> V_224 ) ) ) ;
if ( V_213 == V_212 -> F_4 ) {
if ( F_107 ( F_3 ( V_107 -> V_224 ) ) != 0 ) {
V_212 -> V_67 -> V_229 =
V_212 -> V_67 -> V_230 -
F_107 ( F_3 ( V_107 -> V_224 ) ) ;
if ( V_212 -> V_67 -> V_230 <
V_212 -> V_67 -> V_229 ) {
F_14 ( V_10 , L_96
L_97 ,
F_107 ( F_3 ( V_107 -> V_224 ) ) ) ;
V_212 -> V_67 -> V_229 = 0 ;
if ( V_212 -> V_67 -> V_231 & V_232 )
* V_91 = - V_233 ;
else
* V_91 = 0 ;
}
if ( * V_91 == - V_235 ) {
if ( V_212 -> V_67 -> V_231 & V_232 )
* V_91 = - V_233 ;
else
* V_91 = 0 ;
}
} else {
V_212 -> V_67 -> V_229 =
V_212 -> V_67 -> V_230 ;
if ( * V_91 == - V_233 )
* V_91 = 0 ;
}
} else {
V_212 -> V_67 -> V_229 = 0 ;
for ( V_85 = V_75 -> V_22 , V_41 = V_75 -> V_25 ;
V_85 != V_213 ;
F_7 ( V_10 , V_75 , & V_41 , & V_85 ) ) {
if ( ! F_109 ( V_85 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_85 -> V_30 . V_31 [ 3 ] ) )
V_212 -> V_67 -> V_229 +=
F_107 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) ;
}
if ( V_215 != V_226 )
V_212 -> V_67 -> V_229 +=
F_107 ( F_3 ( V_85 -> V_30 . V_31 [ 2 ] ) ) -
F_107 ( F_3 ( V_107 -> V_224 ) ) ;
}
return F_103 ( V_10 , V_212 , V_213 , V_107 , V_51 , V_91 , false ) ;
}
static int F_112 ( struct V_9 * V_10 ,
struct V_220 * V_107 )
{
struct V_74 * V_222 ;
struct V_50 * V_51 ;
struct V_11 * V_75 ;
unsigned int V_46 ;
int V_47 ;
struct V_70 * V_212 = NULL ;
T_1 V_250 ;
struct V_1 * V_251 ;
union V_3 * V_213 ;
struct V_67 * V_67 = NULL ;
int V_91 = - V_235 ;
struct V_95 * V_95 ;
struct V_76 * V_77 ;
struct V_109 * V_252 ;
T_2 V_215 ;
int V_120 = 0 ;
int V_253 = 0 ;
V_46 = F_50 ( F_3 ( V_107 -> V_122 ) ) ;
V_222 = V_10 -> V_52 [ V_46 ] ;
if ( ! V_222 ) {
F_113 ( V_10 , L_98 ) ;
F_113 ( V_10 , L_99 ,
( unsigned long long ) F_1 (
V_10 -> V_13 -> V_25 ,
V_10 -> V_13 -> V_22 ) ,
F_114 ( F_30 ( V_107 -> V_223 ) ) ,
F_115 ( F_30 ( V_107 -> V_223 ) ) ,
F_3 ( V_107 -> V_224 ) ,
F_3 ( V_107 -> V_122 ) ) ;
F_16 ( V_10 , L_100 ) ;
F_116 ( V_10 , V_10 -> V_13 -> V_25 ) ;
return - V_254 ;
}
V_47 = F_104 ( F_3 ( V_107 -> V_122 ) ) - 1 ;
V_51 = & V_222 -> V_53 [ V_47 ] ;
V_75 = F_105 ( V_51 , F_30 ( V_107 -> V_223 ) ) ;
V_77 = F_29 ( V_10 , V_222 -> V_81 , V_47 ) ;
if ( ! V_75 ||
( F_3 ( V_77 -> V_132 ) & V_133 ) ==
V_255 ) {
F_113 ( V_10 , L_101
L_102 ) ;
F_113 ( V_10 , L_99 ,
( unsigned long long ) F_1 (
V_10 -> V_13 -> V_25 ,
V_10 -> V_13 -> V_22 ) ,
F_114 ( F_30 ( V_107 -> V_223 ) ) ,
F_115 ( F_30 ( V_107 -> V_223 ) ) ,
F_3 ( V_107 -> V_224 ) ,
F_3 ( V_107 -> V_122 ) ) ;
F_16 ( V_10 , L_100 ) ;
F_116 ( V_10 , V_10 -> V_13 -> V_25 ) ;
return - V_254 ;
}
if ( V_51 -> V_221 ) {
F_53 (tmp, &ep_ring->td_list)
V_253 ++ ;
}
V_250 = F_30 ( V_107 -> V_223 ) ;
V_215 = F_67 ( F_3 ( V_107 -> V_224 ) ) ;
switch ( V_215 ) {
case V_128 :
case V_234 :
break;
case V_227 :
F_16 ( V_10 , L_103 ) ;
break;
case V_226 :
F_16 ( V_10 , L_104 ) ;
break;
case V_228 :
F_16 ( V_10 , L_105 ) ;
V_51 -> V_54 |= V_57 ;
V_91 = - V_256 ;
break;
case V_130 :
F_14 ( V_10 , L_106 ) ;
V_91 = - V_257 ;
break;
case V_218 :
case V_216 :
F_16 ( V_10 , L_107 ) ;
V_91 = - V_247 ;
break;
case V_217 :
F_16 ( V_10 , L_108 ) ;
V_91 = - V_245 ;
break;
case V_258 :
F_14 ( V_10 , L_109 ) ;
V_91 = - V_259 ;
break;
case V_242 :
F_14 ( V_10 , L_110 ) ;
break;
case V_244 :
F_14 ( V_10 , L_111 ) ;
break;
case V_260 :
F_16 ( V_10 , L_112 ) ;
if ( ! F_22 ( & V_75 -> V_59 ) )
F_16 ( V_10 , L_113
L_114 ,
F_50 ( F_3 ( V_107 -> V_122 ) ) ,
V_47 ) ;
goto V_192;
case V_261 :
F_16 ( V_10 , L_115 ) ;
if ( ! F_22 ( & V_75 -> V_59 ) )
F_16 ( V_10 , L_116
L_114 ,
F_50 ( F_3 ( V_107 -> V_122 ) ) ,
V_47 ) ;
goto V_192;
case V_246 :
F_14 ( V_10 , L_117 ) ;
V_91 = - V_247 ;
break;
case V_262 :
V_51 -> V_221 = true ;
F_16 ( V_10 , L_118 ) ;
goto V_192;
default:
if ( F_102 ( V_10 , V_215 ) ) {
V_91 = 0 ;
break;
}
F_14 ( V_10 , L_119
L_120 ) ;
goto V_192;
}
do {
if ( F_22 ( & V_75 -> V_59 ) ) {
F_14 ( V_10 , L_121
L_122 ,
F_50 ( F_3 ( V_107 -> V_122 ) ) ,
V_47 ) ;
F_16 ( V_10 , L_123 ,
( F_3 ( V_107 -> V_122 ) &
V_152 ) >> 10 ) ;
F_117 ( V_10 , (union V_3 * ) V_107 ) ;
if ( V_51 -> V_221 ) {
V_51 -> V_221 = false ;
F_16 ( V_10 , L_124
L_125 ) ;
}
V_120 = 0 ;
goto V_192;
}
if ( V_51 -> V_221 && V_253 == 0 ) {
V_51 -> V_221 = false ;
F_16 ( V_10 , L_126
L_127 ) ;
V_120 = 0 ;
goto V_192;
}
V_212 = F_54 ( V_75 -> V_59 . V_14 , struct V_70 , V_59 ) ;
if ( V_51 -> V_221 )
V_253 -- ;
V_251 = F_97 ( V_75 -> V_25 , V_75 -> V_22 ,
V_212 -> F_4 , V_250 ) ;
if ( ! V_251 && V_215 == V_226 ) {
V_120 = 0 ;
goto V_192;
}
if ( ! V_251 ) {
if ( ! V_51 -> V_221 ||
! F_118 ( & V_212 -> V_67 -> V_51 -> V_69 ) ) {
if ( ( V_10 -> V_35 & V_263 ) &&
V_75 -> V_264 ) {
V_75 -> V_264 = false ;
V_120 = 0 ;
goto V_192;
}
F_113 ( V_10 ,
L_128
L_129 ) ;
return - V_124 ;
}
V_120 = F_110 ( V_10 , V_212 , V_107 , V_51 , & V_91 ) ;
goto V_192;
}
if ( V_215 == V_234 )
V_75 -> V_264 = true ;
else
V_75 -> V_264 = false ;
if ( V_51 -> V_221 ) {
F_16 ( V_10 , L_130 ) ;
V_51 -> V_221 = false ;
}
V_213 = & V_251 -> V_6 [ ( V_250 - V_251 -> V_8 ) /
sizeof( * V_213 ) ] ;
if ( F_109 ( V_213 -> V_30 . V_31 [ 3 ] ) ) {
F_16 ( V_10 ,
L_131 ) ;
goto V_192;
}
if ( F_119 ( & V_212 -> V_67 -> V_51 -> V_69 ) )
V_120 = F_106 ( V_10 , V_212 , V_213 , V_107 , V_51 ,
& V_91 ) ;
else if ( F_118 ( & V_212 -> V_67 -> V_51 -> V_69 ) )
V_120 = F_108 ( V_10 , V_212 , V_213 , V_107 , V_51 ,
& V_91 ) ;
else
V_120 = F_111 ( V_10 , V_212 , V_213 , V_107 ,
V_51 , & V_91 ) ;
V_192:
if ( V_215 == V_262 || ! V_51 -> V_221 ) {
F_8 ( V_10 , V_10 -> V_13 , true ) ;
}
if ( V_120 ) {
V_67 = V_212 -> V_67 ;
V_95 = V_67 -> V_96 ;
if ( F_119 ( & V_67 -> V_51 -> V_69 ) ||
( V_215 != V_228 &&
V_215 != V_217 ) )
F_45 ( V_10 , V_95 ) ;
F_42 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 ) ;
if ( ( V_67 -> V_229 != V_67 -> V_230 &&
( V_67 -> V_231 &
V_232 ) ) ||
( V_91 != 0 &&
! F_118 ( & V_67 -> V_51 -> V_69 ) ) )
F_16 ( V_10 , L_132
L_133 ,
V_67 , V_67 -> V_229 ,
V_67 -> V_230 ,
V_91 ) ;
F_43 ( & V_10 -> V_105 ) ;
if ( F_39 ( V_67 -> V_100 ) == V_101 )
V_91 = 0 ;
F_44 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 , V_91 ) ;
F_46 ( & V_10 -> V_105 ) ;
}
} while ( V_51 -> V_221 && V_215 != V_262 );
return 0 ;
}
static int F_120 ( struct V_9 * V_10 )
{
union V_3 * V_107 ;
int V_265 = 1 ;
int V_120 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_22 ) {
V_10 -> V_151 |= 1 << 1 ;
return 0 ;
}
V_107 = V_10 -> V_13 -> V_22 ;
if ( ( F_3 ( V_107 -> V_175 . V_122 ) & V_37 ) !=
V_10 -> V_13 -> V_26 ) {
V_10 -> V_151 |= 1 << 2 ;
return 0 ;
}
F_121 () ;
switch ( ( F_3 ( V_107 -> V_175 . V_122 ) & V_152 ) ) {
case F_32 ( V_266 ) :
F_74 ( V_10 , & V_107 -> V_175 ) ;
break;
case F_32 ( V_267 ) :
F_84 ( V_10 , V_107 ) ;
V_265 = 0 ;
break;
case F_32 ( V_268 ) :
V_120 = F_112 ( V_10 , & V_107 -> V_269 ) ;
if ( V_120 < 0 )
V_10 -> V_151 |= 1 << 9 ;
else
V_265 = 0 ;
break;
default:
if ( ( F_3 ( V_107 -> V_175 . V_122 ) & V_152 ) >=
F_32 ( 48 ) )
F_81 ( V_10 , V_107 ) ;
else
V_10 -> V_151 |= 1 << 3 ;
}
if ( V_10 -> V_116 & V_117 ) {
F_16 ( V_10 , L_134
L_135 ) ;
return 0 ;
}
if ( V_265 )
F_8 ( V_10 , V_10 -> V_13 , true ) ;
return 1 ;
}
T_7 F_122 ( struct V_93 * V_94 )
{
struct V_9 * V_10 = F_123 ( V_94 ) ;
T_2 V_91 ;
union V_3 * V_4 ;
T_5 V_270 ;
union V_3 * V_271 ;
T_1 V_82 ;
F_46 ( & V_10 -> V_105 ) ;
V_4 = V_10 -> V_13 -> V_22 ;
V_91 = F_18 ( V_10 , & V_10 -> V_200 -> V_91 ) ;
if ( V_91 == 0xffffffff )
goto V_272;
if ( ! ( V_91 & V_273 ) ) {
F_43 ( & V_10 -> V_105 ) ;
return V_274 ;
}
if ( V_91 & V_275 ) {
F_14 ( V_10 , L_136 ) ;
F_60 ( V_10 ) ;
V_272:
F_43 ( & V_10 -> V_105 ) ;
return - V_124 ;
}
V_91 |= V_273 ;
F_17 ( V_10 , V_91 , & V_10 -> V_200 -> V_91 ) ;
if ( V_94 -> V_276 != - 1 ) {
T_2 V_277 ;
V_277 = F_18 ( V_10 , & V_10 -> V_278 -> V_277 ) ;
V_277 |= 0x3 ;
F_17 ( V_10 , V_277 , & V_10 -> V_278 -> V_277 ) ;
}
if ( V_10 -> V_116 & V_117 ) {
F_16 ( V_10 , L_137
L_138 ) ;
V_270 = F_124 ( V_10 , & V_10 -> V_278 -> V_279 ) ;
F_125 ( V_10 , V_270 | V_280 ,
& V_10 -> V_278 -> V_279 ) ;
F_43 ( & V_10 -> V_105 ) ;
return V_281 ;
}
V_271 = V_10 -> V_13 -> V_22 ;
while ( F_120 ( V_10 ) > 0 ) {}
V_270 = F_124 ( V_10 , & V_10 -> V_278 -> V_279 ) ;
if ( V_271 != V_10 -> V_13 -> V_22 ) {
V_82 = F_1 ( V_10 -> V_13 -> V_25 ,
V_10 -> V_13 -> V_22 ) ;
if ( V_82 == 0 )
F_14 ( V_10 , L_139
L_140 ) ;
V_270 &= V_282 ;
V_270 |= ( ( T_5 ) V_82 & ( T_5 ) ~ V_282 ) ;
}
V_270 |= V_280 ;
F_125 ( V_10 , V_270 , & V_10 -> V_278 -> V_279 ) ;
F_43 ( & V_10 -> V_105 ) ;
return V_281 ;
}
T_7 F_126 ( int V_276 , struct V_93 * V_94 )
{
return F_122 ( V_94 ) ;
}
static void F_127 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_21 , bool V_27 , bool V_28 ,
T_2 V_283 , T_2 V_284 , T_2 V_285 , T_2 V_286 )
{
struct V_65 * V_4 ;
V_4 = & V_12 -> V_20 -> V_30 ;
V_4 -> V_31 [ 0 ] = F_11 ( V_283 ) ;
V_4 -> V_31 [ 1 ] = F_11 ( V_284 ) ;
V_4 -> V_31 [ 2 ] = F_11 ( V_285 ) ;
V_4 -> V_31 [ 3 ] = F_11 ( V_286 ) ;
F_9 ( V_10 , V_12 , V_21 , V_27 , V_28 ) ;
}
static int F_128 ( struct V_9 * V_10 , struct V_11 * V_75 ,
T_2 V_54 , unsigned int V_38 , bool V_28 , T_8 V_287 )
{
switch ( V_54 ) {
case V_255 :
F_14 ( V_10 , L_141 ) ;
return - V_288 ;
case V_289 :
F_14 ( V_10 , L_142 ) ;
return - V_290 ;
case V_219 :
F_16 ( V_10 , L_143 ) ;
case V_291 :
case V_292 :
break;
default:
F_113 ( V_10 , L_144 ) ;
return - V_290 ;
}
if ( ! F_13 ( V_10 , V_75 , V_38 ) ) {
F_113 ( V_10 , L_145 ) ;
return - V_293 ;
}
if ( F_6 ( V_75 ) ) {
struct V_11 * V_12 = V_75 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_34 , V_14 ) ) {
if ( ! F_10 ( V_10 ) && ! ( V_28 &&
( V_10 -> V_35 & V_36 ) ) )
V_14 -> V_16 . V_17 &= F_11 ( ~ V_32 ) ;
else
V_14 -> V_16 . V_17 |= F_11 ( V_32 ) ;
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_37 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_34 , V_14 ) ) {
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
}
V_12 -> V_34 = V_12 -> V_34 -> V_14 ;
V_12 -> V_20 = V_12 -> V_34 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_129 ( struct V_9 * V_10 ,
struct V_74 * V_222 ,
unsigned int V_47 ,
unsigned int V_48 ,
unsigned int V_38 ,
struct V_67 * V_67 ,
unsigned int V_294 ,
bool V_28 ,
T_8 V_287 )
{
int V_120 ;
struct V_95 * V_95 ;
struct V_70 * V_212 ;
struct V_11 * V_75 ;
struct V_76 * V_77 = F_29 ( V_10 , V_222 -> V_81 , V_47 ) ;
V_75 = F_65 ( V_222 , V_47 , V_48 ) ;
if ( ! V_75 ) {
F_16 ( V_10 , L_146 ,
V_48 ) ;
return - V_290 ;
}
V_120 = F_128 ( V_10 , V_75 ,
F_3 ( V_77 -> V_132 ) & V_133 ,
V_38 , V_28 , V_287 ) ;
if ( V_120 )
return V_120 ;
V_95 = V_67 -> V_96 ;
V_212 = V_95 -> V_212 [ V_294 ] ;
F_130 ( & V_212 -> V_59 ) ;
F_130 ( & V_212 -> V_113 ) ;
if ( V_294 == 0 ) {
V_120 = F_131 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 ) ;
if ( F_48 ( V_120 ) )
return V_120 ;
}
V_212 -> V_67 = V_67 ;
F_132 ( & V_212 -> V_59 , & V_75 -> V_59 ) ;
V_212 -> V_64 = V_75 -> V_34 ;
V_212 -> V_86 = V_75 -> V_20 ;
V_95 -> V_212 [ V_294 ] = V_212 ;
return 0 ;
}
static unsigned int F_133 ( struct V_9 * V_10 , struct V_67 * V_67 )
{
int V_295 , V_38 , V_296 , V_183 , V_39 ;
struct V_297 * V_298 ;
V_298 = NULL ;
V_295 = V_67 -> V_299 ;
V_183 = V_67 -> V_230 ;
V_38 = 0 ;
F_134 (urb->sg, sg, num_sgs, i) {
unsigned int V_237 = F_135 ( V_298 ) ;
V_296 = V_300 -
( F_136 ( V_298 ) & ( V_300 - 1 ) ) ;
V_296 &= V_300 - 1 ;
if ( V_296 != 0 )
V_38 ++ ;
while ( V_296 < F_135 ( V_298 ) && V_296 < V_183 ) {
V_38 ++ ;
V_296 += V_300 ;
}
V_237 = F_137 ( int , V_237 , V_183 ) ;
V_183 -= V_237 ;
if ( V_183 == 0 )
break;
}
return V_38 ;
}
static void F_138 ( struct V_67 * V_67 , int V_38 , int V_296 )
{
if ( V_38 != 0 )
F_139 ( & V_67 -> V_68 -> V_68 , L_147
L_148 , V_301 ,
V_67 -> V_51 -> V_69 . V_249 , V_38 ) ;
if ( V_296 != V_67 -> V_230 )
F_139 ( & V_67 -> V_68 -> V_68 , L_149
L_150 ,
V_301 ,
V_67 -> V_51 -> V_69 . V_249 ,
V_296 , V_296 ,
V_67 -> V_230 ,
V_67 -> V_230 ) ;
}
static void F_140 ( struct V_9 * V_10 , int V_46 ,
unsigned int V_47 , unsigned int V_48 , int V_302 ,
struct V_65 * V_206 )
{
F_12 () ;
if ( V_302 )
V_206 -> V_31 [ 3 ] |= F_11 ( V_302 ) ;
else
V_206 -> V_31 [ 3 ] &= F_11 ( ~ V_37 ) ;
F_19 ( V_10 , V_46 , V_47 , V_48 ) ;
}
int F_141 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_67 * V_67 , int V_46 , unsigned int V_47 )
{
struct V_76 * V_77 = F_29 ( V_10 ,
V_10 -> V_52 [ V_46 ] -> V_81 , V_47 ) ;
int V_303 ;
int V_304 ;
V_303 = F_142 ( F_3 ( V_77 -> V_132 ) ) ;
V_304 = V_67 -> V_305 ;
if ( V_67 -> V_68 -> V_181 == V_306 ||
V_67 -> V_68 -> V_181 == V_307 )
V_304 *= 8 ;
if ( V_303 != V_304 ) {
if ( F_143 () )
F_144 ( & V_67 -> V_68 -> V_68 , L_151
L_152
L_153 ,
V_304 ,
V_304 == 1 ? L_154 : L_155 ,
V_303 ,
V_303 == 1 ? L_154 : L_155 ) ;
V_67 -> V_305 = V_303 ;
if ( V_67 -> V_68 -> V_181 == V_306 ||
V_67 -> V_68 -> V_181 == V_307 )
V_67 -> V_305 /= 8 ;
}
return F_145 ( V_10 , V_308 , V_67 , V_46 , V_47 ) ;
}
static T_2 F_146 ( unsigned int V_309 )
{
T_2 V_310 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_309 >> 10 ) >= V_310 )
return V_310 << 17 ;
else
return ( V_309 >> 10 ) << 17 ;
}
static T_2 F_147 ( int V_296 , int V_311 ,
unsigned int V_312 , struct V_67 * V_67 )
{
int V_313 ;
if ( V_296 == 0 && V_311 == 0 )
return 0 ;
V_313 = ( V_296 + V_311 ) /
F_148 ( & V_67 -> V_51 -> V_69 ) ;
return F_146 ( V_312 - V_313 ) ;
}
static int F_149 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_67 * V_67 , int V_46 , unsigned int V_47 )
{
struct V_11 * V_75 ;
unsigned int V_38 ;
struct V_95 * V_95 ;
struct V_70 * V_212 ;
struct V_297 * V_298 ;
int V_295 ;
int V_311 , V_314 , V_296 ;
unsigned int V_312 ;
bool V_86 ;
T_5 V_23 ;
bool V_27 ;
struct V_65 * V_206 ;
int V_302 ;
V_75 = F_25 ( V_10 , V_67 ) ;
if ( ! V_75 )
return - V_290 ;
V_38 = F_133 ( V_10 , V_67 ) ;
V_295 = V_67 -> V_299 ;
V_312 = F_150 ( V_67 -> V_230 ,
F_148 ( & V_67 -> V_51 -> V_69 ) ) ;
V_311 = F_129 ( V_10 , V_10 -> V_52 [ V_46 ] ,
V_47 , V_67 -> V_48 ,
V_38 , V_67 , 0 , false , V_287 ) ;
if ( V_311 < 0 )
return V_311 ;
V_95 = V_67 -> V_96 ;
V_212 = V_95 -> V_212 [ 0 ] ;
V_206 = & V_75 -> V_20 -> V_30 ;
V_302 = V_75 -> V_26 ;
V_296 = 0 ;
V_298 = V_67 -> V_298 ;
V_23 = ( T_5 ) F_136 ( V_298 ) ;
V_314 = F_135 ( V_298 ) ;
V_311 = V_300 - ( V_23 & ( V_300 - 1 ) ) ;
V_311 = F_137 ( int , V_311 , V_314 ) ;
if ( V_311 > V_67 -> V_230 )
V_311 = V_67 -> V_230 ;
V_86 = true ;
do {
T_2 V_31 = 0 ;
T_2 V_315 = 0 ;
T_2 V_309 = 0 ;
if ( V_86 ) {
V_86 = false ;
if ( V_302 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_75 -> V_26 ;
if ( V_38 > 1 ) {
V_31 |= V_32 ;
} else {
V_212 -> F_4 = V_75 -> V_20 ;
V_31 |= V_316 ;
}
if ( F_151 ( V_67 ) )
V_31 |= V_317 ;
if ( V_300 -
( V_23 & ( V_300 - 1 ) ) < V_311 ) {
F_14 ( V_10 , L_156 ) ;
F_16 ( V_10 , L_157 ,
( unsigned int ) ( V_23 + V_300 ) & ~ ( V_300 - 1 ) ,
( unsigned int ) V_23 + V_311 ) ;
}
if ( V_10 -> V_318 < 0x100 ) {
V_309 = F_146 (
V_67 -> V_230 -
V_296 ) ;
} else {
V_309 = F_147 ( V_296 ,
V_311 , V_312 , V_67 ) ;
}
V_315 = F_107 ( V_311 ) |
V_309 |
F_152 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_127 ( V_10 , V_75 , false , V_27 , false ,
F_114 ( V_23 ) ,
F_115 ( V_23 ) ,
V_315 ,
V_31 | F_32 ( V_319 ) ) ;
-- V_38 ;
V_296 += V_311 ;
V_314 -= V_311 ;
if ( V_314 == 0 ) {
-- V_295 ;
if ( V_295 == 0 )
break;
V_298 = F_153 ( V_298 ) ;
V_23 = ( T_5 ) F_136 ( V_298 ) ;
V_314 = F_135 ( V_298 ) ;
} else {
V_23 += V_311 ;
}
V_311 = V_300 -
( V_23 & ( V_300 - 1 ) ) ;
V_311 = F_137 ( int , V_311 , V_314 ) ;
if ( V_296 + V_311 > V_67 -> V_230 )
V_311 =
V_67 -> V_230 - V_296 ;
} while ( V_296 < V_67 -> V_230 );
F_138 ( V_67 , V_38 , V_296 ) ;
F_140 ( V_10 , V_46 , V_47 , V_67 -> V_48 ,
V_302 , V_206 ) ;
return 0 ;
}
int F_145 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_67 * V_67 , int V_46 , unsigned int V_47 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
struct V_70 * V_212 ;
int V_38 ;
struct V_65 * V_206 ;
bool V_86 ;
bool V_27 ;
int V_302 ;
T_2 V_31 , V_315 ;
int V_296 , V_311 , V_120 ;
unsigned int V_312 ;
T_5 V_23 ;
if ( V_67 -> V_295 )
return F_149 ( V_10 , V_287 , V_67 , V_46 , V_47 ) ;
V_75 = F_25 ( V_10 , V_67 ) ;
if ( ! V_75 )
return - V_290 ;
V_38 = 0 ;
V_296 = V_300 -
( V_67 -> V_320 & ( V_300 - 1 ) ) ;
V_296 &= V_300 - 1 ;
if ( V_296 != 0 || V_67 -> V_230 == 0 )
V_38 ++ ;
while ( V_296 < V_67 -> V_230 ) {
V_38 ++ ;
V_296 += V_300 ;
}
V_120 = F_129 ( V_10 , V_10 -> V_52 [ V_46 ] ,
V_47 , V_67 -> V_48 ,
V_38 , V_67 , 0 , false , V_287 ) ;
if ( V_120 < 0 )
return V_120 ;
V_95 = V_67 -> V_96 ;
V_212 = V_95 -> V_212 [ 0 ] ;
V_206 = & V_75 -> V_20 -> V_30 ;
V_302 = V_75 -> V_26 ;
V_296 = 0 ;
V_312 = F_150 ( V_67 -> V_230 ,
F_148 ( & V_67 -> V_51 -> V_69 ) ) ;
V_23 = ( T_5 ) V_67 -> V_320 ;
V_311 = V_300 -
( V_67 -> V_320 & ( V_300 - 1 ) ) ;
if ( V_311 > V_67 -> V_230 )
V_311 = V_67 -> V_230 ;
V_86 = true ;
do {
T_2 V_309 = 0 ;
V_31 = 0 ;
if ( V_86 ) {
V_86 = false ;
if ( V_302 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_75 -> V_26 ;
if ( V_38 > 1 ) {
V_31 |= V_32 ;
} else {
V_212 -> F_4 = V_75 -> V_20 ;
V_31 |= V_316 ;
}
if ( F_151 ( V_67 ) )
V_31 |= V_317 ;
if ( V_10 -> V_318 < 0x100 ) {
V_309 = F_146 (
V_67 -> V_230 -
V_296 ) ;
} else {
V_309 = F_147 ( V_296 ,
V_311 , V_312 , V_67 ) ;
}
V_315 = F_107 ( V_311 ) |
V_309 |
F_152 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_127 ( V_10 , V_75 , false , V_27 , false ,
F_114 ( V_23 ) ,
F_115 ( V_23 ) ,
V_315 ,
V_31 | F_32 ( V_319 ) ) ;
-- V_38 ;
V_296 += V_311 ;
V_23 += V_311 ;
V_311 = V_67 -> V_230 - V_296 ;
if ( V_311 > V_300 )
V_311 = V_300 ;
} while ( V_296 < V_67 -> V_230 );
F_138 ( V_67 , V_38 , V_296 ) ;
F_140 ( V_10 , V_46 , V_47 , V_67 -> V_48 ,
V_302 , V_206 ) ;
return 0 ;
}
int F_154 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_67 * V_67 , int V_46 , unsigned int V_47 )
{
struct V_11 * V_75 ;
int V_38 ;
int V_120 ;
struct V_321 * V_322 ;
struct V_65 * V_206 ;
int V_302 ;
T_2 V_31 , V_315 ;
struct V_95 * V_95 ;
struct V_70 * V_212 ;
V_75 = F_25 ( V_10 , V_67 ) ;
if ( ! V_75 )
return - V_290 ;
if ( ! V_67 -> V_323 )
return - V_290 ;
V_38 = 2 ;
if ( V_67 -> V_230 > 0 )
V_38 ++ ;
V_120 = F_129 ( V_10 , V_10 -> V_52 [ V_46 ] ,
V_47 , V_67 -> V_48 ,
V_38 , V_67 , 0 , false , V_287 ) ;
if ( V_120 < 0 )
return V_120 ;
V_95 = V_67 -> V_96 ;
V_212 = V_95 -> V_212 [ 0 ] ;
V_206 = & V_75 -> V_20 -> V_30 ;
V_302 = V_75 -> V_26 ;
V_322 = (struct V_321 * ) V_67 -> V_323 ;
V_31 = 0 ;
V_31 |= V_324 | F_32 ( V_325 ) ;
if ( V_302 == 0 )
V_31 |= 0x1 ;
if ( V_10 -> V_318 == 0x100 ) {
if ( V_67 -> V_230 > 0 ) {
if ( V_322 -> V_326 & V_327 )
V_31 |= F_155 ( V_328 ) ;
else
V_31 |= F_155 ( V_329 ) ;
}
}
F_127 ( V_10 , V_75 , false , true , false ,
V_322 -> V_326 | V_322 -> V_330 << 8 | F_156 ( V_322 -> V_331 ) << 16 ,
F_156 ( V_322 -> V_332 ) | F_156 ( V_322 -> V_333 ) << 16 ,
F_107 ( 8 ) | F_152 ( 0 ) ,
V_31 ) ;
if ( F_151 ( V_67 ) )
V_31 = V_317 | F_32 ( V_334 ) ;
else
V_31 = F_32 ( V_334 ) ;
V_315 = F_107 ( V_67 -> V_230 ) |
F_146 ( V_67 -> V_230 ) |
F_152 ( 0 ) ;
if ( V_67 -> V_230 > 0 ) {
if ( V_322 -> V_326 & V_327 )
V_31 |= V_335 ;
F_127 ( V_10 , V_75 , false , true , false ,
F_114 ( V_67 -> V_320 ) ,
F_115 ( V_67 -> V_320 ) ,
V_315 ,
V_31 | V_75 -> V_26 ) ;
}
V_212 -> F_4 = V_75 -> V_20 ;
if ( V_67 -> V_230 > 0 && V_322 -> V_326 & V_327 )
V_31 = 0 ;
else
V_31 = V_335 ;
F_127 ( V_10 , V_75 , false , false , false ,
0 ,
0 ,
F_152 ( 0 ) ,
V_31 | V_316 | F_32 ( V_336 ) | V_75 -> V_26 ) ;
F_140 ( V_10 , V_46 , V_47 , 0 ,
V_302 , V_206 ) ;
return 0 ;
}
static int F_157 ( struct V_9 * V_10 ,
struct V_67 * V_67 , int V_39 )
{
int V_38 = 0 ;
T_5 V_23 , V_337 ;
V_23 = ( T_5 ) ( V_67 -> V_320 + V_67 -> V_241 [ V_39 ] . V_338 ) ;
V_337 = V_67 -> V_241 [ V_39 ] . V_99 ;
V_38 = F_158 ( V_337 + ( V_23 & ( V_300 - 1 ) ) ,
V_300 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_159 ( struct V_9 * V_10 ,
struct V_339 * V_340 ,
struct V_67 * V_67 , unsigned int V_312 )
{
unsigned int V_341 ;
if ( V_10 -> V_318 < 0x100 || V_340 -> V_181 != V_342 )
return 0 ;
V_341 = V_67 -> V_51 -> V_343 . V_344 ;
return F_150 ( V_312 , V_341 + 1 ) - 1 ;
}
static unsigned int F_160 ( struct V_9 * V_10 ,
struct V_339 * V_340 ,
struct V_67 * V_67 , unsigned int V_312 )
{
unsigned int V_341 ;
unsigned int V_345 ;
if ( V_10 -> V_318 < 0x100 )
return 0 ;
switch ( V_340 -> V_181 ) {
case V_342 :
V_341 = V_67 -> V_51 -> V_343 . V_344 ;
V_345 = V_312 % ( V_341 + 1 ) ;
if ( V_345 == 0 )
return V_341 ;
return V_345 - 1 ;
default:
if ( V_312 == 0 )
return 0 ;
return V_312 - 1 ;
}
}
static int F_161 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_67 * V_67 , int V_46 , unsigned int V_47 )
{
struct V_11 * V_75 ;
struct V_95 * V_95 ;
struct V_70 * V_212 ;
int V_346 , V_347 ;
struct V_65 * V_206 ;
bool V_86 ;
int V_302 ;
T_2 V_31 , V_315 ;
int V_296 , V_311 , V_337 , V_348 , V_120 ;
T_5 V_349 , V_23 ;
int V_39 , V_121 ;
bool V_27 ;
V_75 = V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] . V_12 ;
V_346 = V_67 -> V_350 ;
if ( V_346 < 1 ) {
F_16 ( V_10 , L_158 ) ;
return - V_290 ;
}
V_349 = ( T_5 ) V_67 -> V_320 ;
V_206 = & V_75 -> V_20 -> V_30 ;
V_302 = V_75 -> V_26 ;
V_95 = V_67 -> V_96 ;
for ( V_39 = 0 ; V_39 < V_346 ; V_39 ++ ) {
unsigned int V_312 ;
unsigned int V_351 ;
unsigned int V_345 ;
V_86 = true ;
V_296 = 0 ;
V_23 = V_349 + V_67 -> V_241 [ V_39 ] . V_338 ;
V_337 = V_67 -> V_241 [ V_39 ] . V_99 ;
V_348 = V_337 ;
V_312 = F_150 ( V_337 ,
F_148 ( & V_67 -> V_51 -> V_69 ) ) ;
if ( V_312 == 0 )
V_312 ++ ;
V_351 = F_159 ( V_10 , V_67 -> V_68 , V_67 ,
V_312 ) ;
V_345 = F_160 ( V_10 ,
V_67 -> V_68 , V_67 , V_312 ) ;
V_347 = F_157 ( V_10 , V_67 , V_39 ) ;
V_120 = F_129 ( V_10 , V_10 -> V_52 [ V_46 ] , V_47 ,
V_67 -> V_48 , V_347 , V_67 , V_39 , true ,
V_287 ) ;
if ( V_120 < 0 ) {
if ( V_39 == 0 )
return V_120 ;
goto V_192;
}
V_212 = V_95 -> V_212 [ V_39 ] ;
for ( V_121 = 0 ; V_121 < V_347 ; V_121 ++ ) {
T_2 V_309 = 0 ;
V_31 = F_162 ( V_351 ) | F_163 ( V_345 ) ;
if ( V_86 ) {
V_31 |= F_32 ( V_352 ) ;
V_31 |= V_353 ;
if ( V_39 == 0 ) {
if ( V_302 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_75 -> V_26 ;
V_86 = false ;
} else {
V_31 |= F_32 ( V_319 ) ;
V_31 |= V_75 -> V_26 ;
}
if ( F_151 ( V_67 ) )
V_31 |= V_317 ;
if ( V_121 < V_347 - 1 ) {
V_31 |= V_32 ;
V_27 = true ;
} else {
V_212 -> F_4 = V_75 -> V_20 ;
V_31 |= V_316 ;
if ( V_10 -> V_318 == 0x100 ) {
if ( V_39 < V_346 - 1 )
V_31 |= V_354 ;
}
V_27 = false ;
}
V_311 = V_300 -
( V_23 & ( ( 1 << V_355 ) - 1 ) ) ;
if ( V_311 > V_348 )
V_311 = V_348 ;
if ( V_10 -> V_318 < 0x100 ) {
V_309 = F_146 (
V_337 - V_296 ) ;
} else {
V_309 = F_147 (
V_296 , V_311 ,
V_312 , V_67 ) ;
}
V_315 = F_107 ( V_311 ) |
V_309 |
F_152 ( 0 ) ;
F_127 ( V_10 , V_75 , false , V_27 , true ,
F_114 ( V_23 ) ,
F_115 ( V_23 ) ,
V_315 ,
V_31 ) ;
V_296 += V_311 ;
V_23 += V_311 ;
V_348 -= V_311 ;
}
if ( V_296 != V_337 ) {
F_113 ( V_10 , L_159 ) ;
V_120 = - V_290 ;
goto V_192;
}
}
if ( F_40 ( V_10 ) -> V_102 . V_103 == 0 ) {
if ( V_10 -> V_35 & V_104 )
F_164 () ;
}
F_40 ( V_10 ) -> V_102 . V_103 ++ ;
F_140 ( V_10 , V_46 , V_47 , V_67 -> V_48 ,
V_302 , V_206 ) ;
return 0 ;
V_192:
for ( V_39 -- ; V_39 >= 0 ; V_39 -- )
F_55 ( & V_95 -> V_212 [ V_39 ] -> V_59 ) ;
V_95 -> V_212 [ 0 ] -> F_4 = V_75 -> V_20 ;
F_31 ( V_10 , V_75 , V_95 -> V_212 [ 0 ] , true ) ;
V_75 -> V_20 = V_95 -> V_212 [ 0 ] -> V_86 ;
V_75 -> V_34 = V_95 -> V_212 [ 0 ] -> V_64 ;
V_75 -> V_26 = V_302 ;
F_42 ( F_38 ( V_67 -> V_68 -> V_98 ) , V_67 ) ;
return V_120 ;
}
int F_165 ( struct V_9 * V_10 , T_8 V_287 ,
struct V_67 * V_67 , int V_46 , unsigned int V_47 )
{
struct V_74 * V_222 ;
struct V_11 * V_75 ;
struct V_76 * V_77 ;
int V_356 ;
int V_303 ;
int V_304 ;
int V_346 , V_38 , V_39 ;
int V_120 ;
V_222 = V_10 -> V_52 [ V_46 ] ;
V_75 = V_222 -> V_53 [ V_47 ] . V_12 ;
V_77 = F_29 ( V_10 , V_222 -> V_81 , V_47 ) ;
V_38 = 0 ;
V_346 = V_67 -> V_350 ;
for ( V_39 = 0 ; V_39 < V_346 ; V_39 ++ )
V_38 += F_157 ( V_10 , V_67 , V_39 ) ;
V_120 = F_128 ( V_10 , V_75 , F_3 ( V_77 -> V_132 ) & V_133 ,
V_38 , true , V_287 ) ;
if ( V_120 )
return V_120 ;
V_356 = F_18 ( V_10 , & V_10 -> V_357 -> V_358 ) ;
V_356 &= 0x3fff ;
V_67 -> V_356 = V_356 ;
if ( V_67 -> V_68 -> V_181 == V_306 ||
V_67 -> V_68 -> V_181 == V_307 )
V_67 -> V_356 >>= 3 ;
V_303 = F_142 ( F_3 ( V_77 -> V_132 ) ) ;
V_304 = V_67 -> V_305 ;
if ( V_67 -> V_68 -> V_181 == V_306 ||
V_67 -> V_68 -> V_181 == V_307 )
V_304 *= 8 ;
if ( V_303 != V_304 ) {
if ( F_143 () )
F_144 ( & V_67 -> V_68 -> V_68 , L_151
L_152
L_153 ,
V_304 ,
V_304 == 1 ? L_154 : L_155 ,
V_303 ,
V_303 == 1 ? L_154 : L_155 ) ;
V_67 -> V_305 = V_303 ;
if ( V_67 -> V_68 -> V_181 == V_306 ||
V_67 -> V_68 -> V_181 == V_307 )
V_67 -> V_305 /= 8 ;
}
return F_161 ( V_10 , V_308 , V_67 , V_46 , V_47 ) ;
}
static int F_166 ( struct V_9 * V_10 , T_2 V_283 , T_2 V_284 ,
T_2 V_285 , T_2 V_286 , bool V_359 )
{
int V_360 = V_10 -> V_361 ;
int V_120 ;
if ( ! V_359 )
V_360 ++ ;
V_120 = F_128 ( V_10 , V_10 -> V_112 , V_292 ,
V_360 , false , V_308 ) ;
if ( V_120 < 0 ) {
F_113 ( V_10 , L_160 ) ;
if ( V_359 )
F_113 ( V_10 , L_161
L_162 ) ;
return V_120 ;
}
F_127 ( V_10 , V_10 -> V_112 , false , false , false , V_283 , V_284 ,
V_285 , V_286 | V_10 -> V_112 -> V_26 ) ;
return 0 ;
}
int F_167 ( struct V_9 * V_10 , T_2 V_173 , T_2 V_46 )
{
return F_166 ( V_10 , 0 , 0 , 0 ,
F_32 ( V_173 ) | F_168 ( V_46 ) , false ) ;
}
int F_169 ( struct V_9 * V_10 , T_1 V_362 ,
T_2 V_46 )
{
return F_166 ( V_10 , F_114 ( V_362 ) ,
F_115 ( V_362 ) , 0 ,
F_32 ( V_165 ) | F_168 ( V_46 ) ,
false ) ;
}
int F_170 ( struct V_9 * V_10 ,
T_2 V_283 , T_2 V_284 , T_2 V_285 , T_2 V_286 )
{
return F_166 ( V_10 , V_283 , V_284 , V_285 , V_286 , false ) ;
}
int F_171 ( struct V_9 * V_10 , T_2 V_46 )
{
return F_166 ( V_10 , 0 , 0 , 0 ,
F_32 ( V_170 ) | F_168 ( V_46 ) ,
false ) ;
}
int F_70 ( struct V_9 * V_10 , T_1 V_362 ,
T_2 V_46 , bool V_359 )
{
return F_166 ( V_10 , F_114 ( V_362 ) ,
F_115 ( V_362 ) , 0 ,
F_32 ( V_157 ) | F_168 ( V_46 ) ,
V_359 ) ;
}
int F_172 ( struct V_9 * V_10 , T_1 V_362 ,
T_2 V_46 )
{
return F_166 ( V_10 , F_114 ( V_362 ) ,
F_115 ( V_362 ) , 0 ,
F_32 ( V_164 ) | F_168 ( V_46 ) ,
false ) ;
}
int F_173 ( struct V_9 * V_10 , int V_46 ,
unsigned int V_47 , int V_363 )
{
T_2 V_364 = F_168 ( V_46 ) ;
T_2 V_365 = F_174 ( V_47 ) ;
T_2 type = F_32 ( V_166 ) ;
T_2 V_366 = F_175 ( V_363 ) ;
return F_166 ( V_10 , 0 , 0 , 0 ,
V_364 | V_365 | type | V_366 , false ) ;
}
static int F_34 ( struct V_9 * V_10 , int V_46 ,
unsigned int V_47 , unsigned int V_48 ,
struct V_1 * V_25 ,
union V_3 * V_367 , T_2 V_26 )
{
T_1 V_23 ;
T_2 V_364 = F_168 ( V_46 ) ;
T_2 V_365 = F_174 ( V_47 ) ;
T_2 V_368 = F_176 ( V_48 ) ;
T_2 type = F_32 ( V_167 ) ;
struct V_50 * V_51 ;
V_23 = F_1 ( V_25 , V_367 ) ;
if ( V_23 == 0 ) {
F_14 ( V_10 , L_163 ) ;
F_14 ( V_10 , L_164 ,
V_25 , V_367 ) ;
return 0 ;
}
V_51 = & V_10 -> V_52 [ V_46 ] -> V_53 [ V_47 ] ;
if ( ( V_51 -> V_54 & V_56 ) ) {
F_14 ( V_10 , L_163 ) ;
F_14 ( V_10 , L_165 ) ;
return 0 ;
}
V_51 -> V_136 = V_25 ;
V_51 -> V_137 = V_367 ;
return F_166 ( V_10 , F_114 ( V_23 ) | V_26 ,
F_115 ( V_23 ) , V_368 ,
V_364 | V_365 | type , false ) ;
}
int F_99 ( struct V_9 * V_10 , int V_46 ,
unsigned int V_47 )
{
T_2 V_364 = F_168 ( V_46 ) ;
T_2 V_365 = F_174 ( V_47 ) ;
T_2 type = F_32 ( V_169 ) ;
return F_166 ( V_10 , 0 , 0 , 0 , V_364 | V_365 | type ,
false ) ;
}
