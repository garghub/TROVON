static int
F_1 ( unsigned int V_1 , T_1 V_2 ,
T_2 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_7 . V_8 [ V_1 ] ;
int V_9 ;
V_9 = ! V_4 &&
V_2 . V_10 != V_11 &&
V_2 . V_12 != V_13 ;
F_2 ( ! F_3 ( V_6 ) || ! F_4 ( V_6 ) ) ;
if ( F_5 ( F_3 ( V_6 ) || F_4 ( V_6 ) ) )
goto V_14;
F_6 ( V_6 ) ;
if ( F_7 ( F_3 ( V_6 ) || F_4 ( V_6 ) ) ) {
F_8 ( V_6 ) ;
goto V_14;
}
if ( V_9 )
F_9 ( V_6 , V_15 ) ;
else
F_9 ( V_6 , V_16 ) ;
F_8 ( V_6 ) ;
return 1 ;
V_14:
if ( ( F_3 ( V_6 ) && ! V_9 ) ||
( F_4 ( V_6 ) && V_9 ) )
return 0 ;
return 1 ;
}
static void
F_10 ( struct V_5 * V_6 , int V_17 )
{
struct V_18 * V_19 = V_6 -> V_20 [ V_17 ] ;
int V_21 ;
F_2 ( F_4 ( V_6 ) ) ;
V_19 -> V_22 = 1 ;
V_6 -> V_23 [ V_6 -> V_24 ] = V_17 ;
for ( V_21 = V_6 -> V_24 - 1 ; V_21 >= 0 ; V_21 -- ) {
F_2 ( V_6 -> V_23 [ V_21 ] != V_17 ) ;
if ( V_6 -> V_23 [ V_21 ] < V_17 )
break;
V_6 -> V_23 [ V_21 + 1 ] = V_6 -> V_23 [ V_21 ] ;
V_6 -> V_23 [ V_21 ] = V_17 ;
}
V_6 -> V_24 ++ ;
}
static void
F_11 ( struct V_5 * V_6 , int V_17 )
{
struct V_18 * V_19 = V_6 -> V_20 [ V_17 ] ;
int V_21 ;
F_2 ( F_4 ( V_6 ) ) ;
if ( V_25 == 1 )
return;
V_19 -> V_22 = 0 ;
F_2 ( V_6 -> V_24 > 0 &&
V_6 -> V_24 <= V_25 ) ;
V_6 -> V_24 -- ;
for ( V_21 = 0 ; V_21 < V_6 -> V_24 ; V_21 ++ ) {
if ( V_6 -> V_23 [ V_21 ] >= V_17 )
V_6 -> V_23 [ V_21 ] = V_6 -> V_23 [ V_21 + 1 ] ;
}
}
static int
F_12 ( T_3 * V_26 ,
struct V_27 * V_28 , struct V_29 * V_30 )
{
unsigned int V_31 ;
unsigned int V_32 ;
T_4 * V_33 = V_26 -> V_34 ;
if ( F_13 ( V_26 ) )
return V_35 | V_36 ;
if ( ! ( V_26 -> V_37 & V_28 -> V_38 ) )
return V_35 ;
if ( V_33 -> V_39 . V_10 != V_11 &&
V_33 -> V_39 . V_10 != V_28 -> V_40 . V_10 )
return V_35 ;
if ( V_33 -> V_39 . V_12 != V_13 &&
V_33 -> V_39 . V_12 != V_28 -> V_40 . V_12 )
return V_35 ;
if ( ( V_33 -> V_41 ^ V_28 -> V_42 ) & ~ V_33 -> V_43 )
return V_35 ;
if ( ! ( V_26 -> V_37 & V_44 ) )
V_31 = V_26 -> V_45 ;
else
V_31 = V_28 -> V_46 ;
if ( V_26 -> V_37 & V_47 ) {
V_32 = V_26 -> V_48 ;
F_2 ( V_26 -> V_45 + V_32 <= V_26 -> V_49 ) ;
} else {
V_32 = V_26 -> V_49 - V_31 ;
}
if ( V_28 -> V_50 <= V_32 ) {
V_32 = V_28 -> V_50 ;
} else if ( ! ( V_26 -> V_37 & V_51 ) ) {
F_14 ( L_1 ,
F_15 ( V_28 -> V_40 ) , V_28 -> V_42 ,
V_28 -> V_50 , V_26 -> V_49 - V_31 , V_32 ) ;
return V_52 ;
}
F_16 ( V_53 , L_2 ,
( V_28 -> V_38 == V_54 ) ? L_3 : L_4 ,
V_28 -> V_55 , F_15 ( V_28 -> V_40 ) , V_32 ,
V_28 -> V_50 , V_26 -> V_56 . V_57 , V_26 -> V_58 , V_31 ) ;
F_17 ( V_30 , V_26 , V_31 , V_32 ) ;
V_26 -> V_45 = V_31 + V_32 ;
if ( ! F_13 ( V_26 ) )
return V_59 ;
if ( V_26 -> V_60 & V_61 )
F_18 ( V_26 ) ;
return V_59 | V_36 ;
}
static struct V_18 *
F_19 ( struct V_5 * V_6 , T_1 V_62 , T_2 V_3 )
{
if ( V_25 == 1 )
return V_6 -> V_20 [ 0 ] ;
return F_3 ( V_6 ) ?
V_6 -> V_20 [ F_20 ( V_62 . V_10 ) ] : NULL ;
}
struct V_18 *
F_21 ( unsigned int V_1 , T_1 V_62 ,
T_2 V_3 , T_2 V_4 , T_5 V_63 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
F_2 ( V_1 < V_7 . V_64 ) ;
if ( ! F_1 ( V_1 , V_62 , V_3 , V_4 ) )
return NULL ;
V_6 = V_7 . V_8 [ V_1 ] ;
V_19 = F_19 ( V_6 , V_62 , V_3 ) ;
if ( V_19 )
return V_19 ;
switch ( V_63 ) {
default:
return NULL ;
case V_65 :
case V_66 :
return V_6 -> V_20 [ V_6 -> V_67 % V_25 ] ;
case V_68 :
return V_6 -> V_20 [ F_22 () ] ;
}
}
static struct V_18 *
F_23 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
struct V_18 * V_19 ;
struct V_5 * V_6 ;
unsigned int V_69 ;
unsigned int V_70 ;
unsigned int V_17 ;
bool V_71 ;
F_2 ( V_28 -> V_55 < V_7 . V_64 ) ;
V_6 = V_7 . V_8 [ V_28 -> V_55 ] ;
F_2 ( F_4 ( V_6 ) || F_3 ( V_6 ) ) ;
V_19 = F_19 ( V_6 , V_28 -> V_40 , V_28 -> V_42 ) ;
if ( V_19 )
return V_19 ;
V_71 = F_24 ( V_30 -> V_72 . V_73 ) !=
F_24 ( V_30 -> V_72 . V_74 ) ;
if ( V_75 == V_76 ||
( V_75 != V_77 && ! V_71 ) ) {
V_17 = F_22 () ;
if ( V_6 -> V_20 [ V_17 ] -> V_22 )
return V_6 -> V_20 [ V_17 ] ;
}
V_70 = V_6 -> V_78 ++ ;
if ( V_75 == V_79 && V_71 )
V_17 = F_20 ( V_30 -> V_72 . V_73 ) ;
else
V_17 = V_70 % V_25 ;
if ( ! V_6 -> V_20 [ V_17 ] -> V_22 ) {
V_69 = V_6 -> V_24 ;
if ( V_69 ) {
V_17 = V_6 -> V_23 [ V_70 % V_69 ] ;
}
}
return V_6 -> V_20 [ V_17 ] ;
}
static int
F_25 ( struct V_18 * V_19 , int V_63 )
{
T_2 * V_80 ;
int V_21 ;
if ( ! F_4 ( V_7 . V_8 [ V_19 -> V_81 ] ) )
return 0 ;
if ( V_63 < 0 ) {
for ( V_21 = 0 ; V_21 < V_82 ; V_21 ++ ) {
if ( V_19 -> V_83 [ V_21 ] != ( T_2 ) ( - 1 ) )
return 0 ;
}
return 1 ;
}
F_2 ( V_63 <= V_84 ) ;
V_80 = & V_19 -> V_83 [ V_63 >> V_85 ] ;
V_63 &= ( 1 << V_85 ) - 1 ;
return ( * V_80 & ( 1ULL << V_63 ) ) ;
}
static void
F_26 ( struct V_18 * V_19 , int V_63 , int V_86 )
{
T_2 * V_80 ;
F_2 ( F_4 ( V_7 . V_8 [ V_19 -> V_81 ] ) ) ;
F_2 ( V_63 <= V_84 ) ;
V_80 = & V_19 -> V_83 [ V_63 >> V_85 ] ;
V_63 &= ( 1 << V_85 ) - 1 ;
if ( ! V_86 )
* V_80 &= ~ ( 1ULL << V_63 ) ;
else
* V_80 |= 1ULL << V_63 ;
}
struct V_87 *
F_27 ( struct V_18 * V_19 ,
T_1 V_62 , T_2 V_3 )
{
struct V_5 * V_6 = V_7 . V_8 [ V_19 -> V_81 ] ;
unsigned long V_88 = V_3 ;
if ( ! F_4 ( V_6 ) ) {
V_88 += V_62 . V_10 + V_62 . V_12 ;
F_2 ( F_3 ( V_6 ) ) ;
V_88 = F_28 ( V_88 , V_89 ) ;
}
return & V_19 -> V_90 [ V_88 & V_91 ] ;
}
int
F_29 ( struct V_18 * V_19 ,
struct V_27 * V_28 , struct V_29 * V_30 )
{
struct V_87 * V_92 ;
T_4 * V_33 ;
T_4 * V_93 ;
int V_86 = 0 ;
int V_94 ;
if ( ! F_30 ( & V_19 -> V_90 [ V_84 ] ) )
V_92 = & V_19 -> V_90 [ V_84 ] ;
else
V_92 = F_27 ( V_19 , V_28 -> V_40 , V_28 -> V_42 ) ;
V_95:
if ( F_4 ( V_7 . V_8 [ V_19 -> V_81 ] ) )
V_86 = V_36 ;
F_31 (me, tmp, head, me_list) {
if ( ! V_33 -> V_96 )
continue;
F_2 ( V_33 == V_33 -> V_96 -> V_34 ) ;
V_94 = F_12 ( V_33 -> V_96 , V_28 , V_30 ) ;
if ( ! ( V_94 & V_36 ) )
V_86 = 0 ;
if ( V_94 & V_97 ) {
return V_94 & ~ V_36 ;
}
}
if ( V_86 == V_36 ) {
F_26 ( V_19 , V_92 - V_19 -> V_90 , 1 ) ;
if ( ! F_25 ( V_19 , - 1 ) )
V_86 = 0 ;
}
if ( ! V_86 && V_92 == & V_19 -> V_90 [ V_84 ] ) {
V_92 = F_27 ( V_19 , V_28 -> V_40 , V_28 -> V_42 ) ;
goto V_95;
}
if ( V_28 -> V_38 == V_98 ||
! F_32 ( V_7 . V_8 [ V_28 -> V_55 ] ) )
return V_86 | V_52 ;
return V_86 | V_35 ;
}
static int
F_33 ( struct V_5 * V_6 , struct V_29 * V_30 )
{
int V_94 ;
if ( F_5 ( F_4 ( V_6 ) || F_3 ( V_6 ) ) )
return 0 ;
F_6 ( V_6 ) ;
if ( F_4 ( V_6 ) || F_3 ( V_6 ) ) {
F_8 ( V_6 ) ;
return 0 ;
}
if ( F_32 ( V_6 ) ) {
if ( V_30 -> V_99 ) {
V_30 -> V_100 = 1 ;
F_34 ( & V_30 -> V_101 ,
& V_6 -> V_102 ) ;
}
V_94 = V_35 ;
} else {
V_94 = V_52 ;
}
F_8 ( V_6 ) ;
return V_94 ;
}
static int
F_35 ( struct V_5 * V_6 ,
struct V_27 * V_28 , struct V_29 * V_30 )
{
int V_103 = V_6 -> V_23 [ 0 ] ;
int V_94 = 0 ;
int V_21 ;
F_2 ( F_4 ( V_6 ) ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
struct V_18 * V_19 ;
int V_17 ;
V_17 = ( V_103 + V_21 ) % V_25 ;
V_19 = V_6 -> V_20 [ V_17 ] ;
if ( V_21 && V_21 != V_25 - 1 && ! V_19 -> V_22 )
continue;
F_36 ( V_17 ) ;
F_6 ( V_6 ) ;
if ( ! V_21 ) {
F_34 ( & V_30 -> V_101 ,
& V_6 -> V_104 ) ;
}
if ( ! F_30 ( & V_30 -> V_101 ) ) {
V_94 = F_29 ( V_19 , V_28 , V_30 ) ;
if ( ( V_94 & V_36 ) &&
V_19 -> V_22 )
F_11 ( V_6 , V_17 ) ;
if ( V_94 & V_97 ) {
F_37 ( & V_30 -> V_101 ) ;
} else if ( V_21 == V_25 - 1 ||
! V_6 -> V_24 ||
( V_6 -> V_24 == 1 &&
V_6 -> V_23 [ 0 ] == V_17 ) ) {
F_37 ( & V_30 -> V_101 ) ;
if ( F_32 ( V_6 ) ) {
V_30 -> V_100 = 1 ;
F_34 ( & V_30 -> V_101 ,
& V_6 -> V_102 ) ;
V_94 = V_35 ;
} else {
V_94 = V_52 ;
}
} else {
V_94 = 0 ;
}
} else {
V_94 = ! V_30 -> V_105 ?
V_52 : V_59 ;
}
F_8 ( V_6 ) ;
F_38 ( V_17 ) ;
if ( V_94 & ( V_97 | V_35 ) )
break;
}
return V_94 ;
}
int
F_39 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
struct V_18 * V_19 ;
struct V_5 * V_6 ;
int V_94 ;
F_16 ( V_53 , L_5 ,
F_15 ( V_28 -> V_40 ) , V_28 -> V_50 , V_28 -> V_55 ,
V_28 -> V_42 ) ;
if ( V_28 -> V_55 >= V_7 . V_64 ) {
F_14 ( L_6 ,
V_28 -> V_55 , V_7 . V_64 ) ;
return V_52 ;
}
V_6 = V_7 . V_8 [ V_28 -> V_55 ] ;
V_94 = F_33 ( V_6 , V_30 ) ;
if ( V_94 )
return V_94 ;
V_19 = F_23 ( V_28 , V_30 ) ;
F_36 ( V_19 -> V_106 ) ;
if ( V_7 . V_107 ) {
V_94 = V_52 ;
goto V_108;
}
V_94 = F_29 ( V_19 , V_28 , V_30 ) ;
if ( ( V_94 & V_36 ) && V_19 -> V_22 ) {
F_6 ( V_6 ) ;
F_11 ( V_6 , V_19 -> V_106 ) ;
F_8 ( V_6 ) ;
}
if ( V_94 & V_97 )
goto V_108;
if ( ! V_30 -> V_99 )
goto V_108;
F_2 ( F_32 ( V_6 ) ) ;
F_2 ( ! V_30 -> V_100 ) ;
if ( F_3 ( V_6 ) || V_25 == 1 ) {
F_6 ( V_6 ) ;
V_30 -> V_100 = 1 ;
F_34 ( & V_30 -> V_101 , & V_6 -> V_102 ) ;
F_8 ( V_6 ) ;
F_38 ( V_19 -> V_106 ) ;
V_94 = V_35 ;
} else {
F_38 ( V_19 -> V_106 ) ;
V_94 = F_35 ( V_6 , V_28 , V_30 ) ;
}
if ( V_94 & V_35 ) {
F_16 ( V_53 ,
L_7 ,
V_28 -> V_38 == V_54 ? L_8 : L_9 ,
F_15 ( V_28 -> V_40 ) , V_28 -> V_55 ,
V_28 -> V_42 , V_28 -> V_46 , V_28 -> V_50 ) ;
}
goto V_109;
V_108:
F_38 ( V_19 -> V_106 ) ;
V_109:
return V_94 & ~ V_36 ;
}
void
F_40 ( T_4 * V_33 , T_3 * V_26 )
{
F_2 ( V_33 -> V_96 == V_26 && V_26 -> V_34 == V_33 ) ;
V_33 -> V_96 = NULL ;
V_26 -> V_34 = NULL ;
}
void
F_41 ( T_4 * V_33 , T_3 * V_26 ,
struct V_87 * V_110 , struct V_87 * V_111 )
{
struct V_5 * V_6 = V_7 . V_8 [ V_33 -> V_112 ] ;
struct V_18 * V_19 ;
struct V_87 * V_92 ;
T_6 * V_93 ;
T_6 * V_30 ;
int V_86 = 0 ;
int V_17 ;
F_2 ( ! V_26 -> V_113 ) ;
V_33 -> V_96 = V_26 ;
V_26 -> V_34 = V_33 ;
V_17 = F_42 ( V_26 -> V_56 . V_57 ) ;
V_19 = V_6 -> V_20 [ V_17 ] ;
if ( F_30 ( & V_6 -> V_104 ) &&
F_30 ( & V_6 -> V_102 ) &&
! F_25 ( V_19 , V_33 -> V_114 ) )
return;
F_6 ( V_6 ) ;
V_92 = & V_6 -> V_104 ;
V_95:
F_31 (msg, tmp, head, msg_list) {
struct V_27 V_28 ;
struct V_115 * V_116 ;
int V_94 ;
F_2 ( V_30 -> V_100 || V_92 == & V_6 -> V_104 ) ;
V_116 = & V_30 -> V_72 ;
V_28 . V_40 . V_10 = V_116 -> V_73 ;
V_28 . V_40 . V_12 = V_116 -> V_117 ;
V_28 . V_38 = V_54 ;
V_28 . V_55 = V_116 -> V_30 . V_118 . V_67 ;
V_28 . V_50 = V_116 -> V_119 ;
V_28 . V_46 = V_116 -> V_30 . V_118 . V_31 ;
V_28 . V_42 = V_116 -> V_30 . V_118 . V_120 ;
V_94 = F_12 ( V_26 , & V_28 , V_30 ) ;
V_86 = ( V_94 & V_36 ) ;
if ( V_94 & V_35 ) {
if ( V_86 )
break;
continue;
}
F_2 ( V_94 & V_97 ) ;
F_37 ( & V_30 -> V_101 ) ;
if ( V_92 == & V_6 -> V_104 ) {
if ( V_86 )
break;
continue;
}
if ( V_94 & V_59 ) {
F_34 ( & V_30 -> V_101 , V_110 ) ;
F_16 ( V_53 , L_10 ,
F_15 ( V_28 . V_40 ) ,
V_28 . V_55 , V_28 . V_42 ,
V_28 . V_46 , V_28 . V_50 ) ;
} else {
F_34 ( & V_30 -> V_101 , V_111 ) ;
}
if ( V_86 )
break;
}
if ( ! V_86 && V_92 == & V_6 -> V_104 ) {
V_92 = & V_6 -> V_102 ;
goto V_95;
}
if ( F_4 ( V_6 ) && ! V_86 ) {
F_26 ( V_19 , V_33 -> V_114 , 0 ) ;
if ( ! V_19 -> V_22 )
F_10 ( V_6 , V_17 ) ;
}
F_8 ( V_6 ) ;
}
static void
F_43 ( struct V_5 * V_6 )
{
struct V_18 * V_19 ;
int V_21 ;
if ( ! V_6 -> V_20 )
return;
F_2 ( F_30 ( & V_6 -> V_102 ) ) ;
F_2 ( F_30 ( & V_6 -> V_104 ) ) ;
F_44 (mtable, i, ptl->ptl_mtables) {
struct V_87 * V_121 ;
T_4 * V_33 ;
int V_122 ;
if ( ! V_19 -> V_90 )
continue;
V_121 = V_19 -> V_90 ;
for ( V_122 = 0 ; V_122 < V_123 + 1 ; V_122 ++ ) {
while ( ! F_30 ( & V_121 [ V_122 ] ) ) {
V_33 = F_45 ( V_121 [ V_122 ] . V_124 ,
T_4 , V_125 ) ;
F_14 ( L_11 , V_33 ) ;
F_46 ( & V_33 -> V_125 ) ;
F_47 ( V_33 ) ;
}
}
F_48 ( V_121 , sizeof( * V_121 ) * ( V_123 + 1 ) ) ;
}
F_49 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
static int
F_50 ( struct V_5 * V_6 , int V_1 )
{
struct V_18 * V_19 ;
struct V_87 * V_121 ;
int V_21 ;
int V_122 ;
V_6 -> V_20 = F_51 ( F_52 () ,
sizeof( struct V_18 ) ) ;
if ( ! V_6 -> V_20 ) {
F_14 ( L_12 , V_1 ) ;
return - V_126 ;
}
V_6 -> V_67 = V_1 ;
F_53 ( & V_6 -> V_102 ) ;
F_53 ( & V_6 -> V_104 ) ;
F_54 ( & V_6 -> V_127 ) ;
F_44 (mtable, i, ptl->ptl_mtables) {
F_55 ( V_121 , F_52 () , V_21 ,
sizeof( * V_121 ) * ( V_123 + 1 ) ) ;
if ( ! V_121 ) {
F_14 ( L_13 ,
V_1 ) ;
goto V_128;
}
memset ( & V_19 -> V_83 [ 0 ] , - 1 ,
sizeof( V_19 -> V_83 [ 0 ] ) *
V_82 ) ;
V_19 -> V_90 = V_121 ;
for ( V_122 = 0 ; V_122 < V_123 + 1 ; V_122 ++ )
F_53 ( & V_121 [ V_122 ] ) ;
V_19 -> V_81 = V_1 ;
V_19 -> V_106 = V_21 ;
}
return 0 ;
V_128:
F_43 ( V_6 ) ;
return - V_126 ;
}
void
F_56 ( void )
{
int V_21 ;
if ( ! V_7 . V_8 )
return;
for ( V_21 = 0 ; V_21 < V_7 . V_64 ; V_21 ++ )
F_43 ( V_7 . V_8 [ V_21 ] ) ;
F_57 ( V_7 . V_8 ) ;
V_7 . V_8 = NULL ;
}
int
F_58 ( void )
{
int V_129 ;
int V_21 ;
V_129 = F_59 ( struct V_5 , V_23 [ V_25 ] ) ;
V_7 . V_64 = V_130 ;
V_7 . V_8 = F_60 ( V_7 . V_64 , V_129 ) ;
if ( ! V_7 . V_8 ) {
F_14 ( L_14 ) ;
return - V_126 ;
}
for ( V_21 = 0 ; V_21 < V_7 . V_64 ; V_21 ++ ) {
if ( F_50 ( V_7 . V_8 [ V_21 ] , V_21 ) ) {
F_56 () ;
return - V_126 ;
}
}
return 0 ;
}
int
F_61 ( int V_131 )
{
struct V_5 * V_6 ;
if ( V_131 < 0 || V_131 >= V_7 . V_64 )
return - V_132 ;
F_16 ( V_53 , L_15 , V_131 ) ;
V_6 = V_7 . V_8 [ V_131 ] ;
F_36 ( V_133 ) ;
F_6 ( V_6 ) ;
F_9 ( V_6 , V_134 ) ;
F_8 ( V_6 ) ;
F_38 ( V_133 ) ;
return 0 ;
}
int
F_62 ( struct V_135 * V_136 , int V_131 , char * V_137 )
{
struct V_5 * V_6 ;
F_63 ( V_138 ) ;
if ( V_131 < 0 || V_131 >= V_7 . V_64 )
return - V_132 ;
V_6 = V_7 . V_8 [ V_131 ] ;
F_36 ( V_133 ) ;
F_6 ( V_6 ) ;
if ( ! F_32 ( V_6 ) ) {
F_8 ( V_6 ) ;
F_38 ( V_133 ) ;
return 0 ;
}
if ( V_136 ) {
struct V_29 * V_30 , * V_93 ;
F_31 (msg, tmp, &ptl->ptl_msg_delayed,
msg_list) {
if ( V_30 -> V_139 -> V_140 == V_136 )
F_64 ( & V_30 -> V_101 , & V_138 ) ;
}
} else {
if ( V_7 . V_107 )
F_65 ( L_16 , V_131 ) ;
else
F_16 ( V_53 , L_17 , V_131 ) ;
F_66 ( & V_6 -> V_102 , & V_138 ) ;
F_67 ( V_6 , V_134 ) ;
}
F_8 ( V_6 ) ;
F_38 ( V_133 ) ;
F_68 ( & V_138 , V_137 ) ;
return 0 ;
}
int
F_69 ( int V_131 )
{
return F_62 ( NULL , V_131 ,
L_18 ) ;
}
