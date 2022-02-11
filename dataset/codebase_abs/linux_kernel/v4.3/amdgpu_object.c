static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( V_4 -> V_6 << V_7 < V_2 -> V_8 . V_9 ) {
V_5 = ( T_1 ) ( ( V_4 -> V_6 << V_7 ) + V_4 -> V_10 ) >
V_2 -> V_8 . V_9 ?
V_2 -> V_8 . V_9 - ( V_4 -> V_6 << V_7 ) :
V_4 -> V_10 ;
}
return V_5 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
struct V_3 * V_12 )
{
T_1 V_13 ;
if ( ! V_2 )
return;
if ( V_12 ) {
switch ( V_12 -> V_14 ) {
case V_15 :
F_3 ( V_12 -> V_10 , & V_2 -> V_16 ) ;
break;
case V_17 :
F_3 ( V_12 -> V_10 , & V_2 -> V_18 ) ;
V_13 = F_1 ( V_2 , V_12 ) ;
F_3 ( V_13 , & V_2 -> V_19 ) ;
break;
}
}
if ( V_11 ) {
switch ( V_11 -> V_14 ) {
case V_15 :
F_4 ( V_11 -> V_10 , & V_2 -> V_16 ) ;
break;
case V_17 :
F_4 ( V_11 -> V_10 , & V_2 -> V_18 ) ;
V_13 = F_1 ( V_2 , V_11 ) ;
F_4 ( V_13 , & V_2 -> V_19 ) ;
break;
}
}
}
static void F_5 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
V_23 = F_6 ( V_21 , struct V_22 , V_21 ) ;
F_2 ( V_23 -> V_2 , & V_23 -> V_21 . V_4 , NULL ) ;
F_7 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_8 ( & V_23 -> V_26 ) ;
F_9 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_10 ( & V_23 -> V_27 ) ;
F_11 ( V_23 -> V_28 ) ;
F_11 ( V_23 ) ;
}
bool F_12 ( struct V_20 * V_23 )
{
if ( V_23 -> V_29 == & F_5 )
return true ;
return false ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_2 V_34 , T_1 V_35 )
{
T_2 V_36 = 0 , V_37 ;
V_31 -> V_31 = V_33 ;
V_31 -> V_38 = V_33 ;
if ( V_34 & V_39 ) {
if ( V_35 & V_40 &&
V_2 -> V_8 . V_9 < V_2 -> V_8 . V_41 ) {
V_33 [ V_36 ] . V_42 =
V_2 -> V_8 . V_9 >> V_7 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_44 |
V_45 | V_46 ;
}
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_44 |
V_45 ;
}
if ( V_34 & V_47 ) {
if ( V_35 & V_48 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_49 |
V_44 ;
} else {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_50 | V_49 ;
}
}
if ( V_34 & V_51 ) {
if ( V_35 & V_48 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_52 |
V_44 ;
} else {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_50 | V_52 ;
}
}
if ( V_34 & V_53 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_44 |
V_54 ;
}
if ( V_34 & V_55 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_44 |
V_56 ;
}
if ( V_34 & V_57 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_44 |
V_58 ;
}
if ( ! V_36 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_59 |
V_52 ;
}
V_31 -> V_60 = V_36 ;
V_31 -> V_61 = V_36 ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
if ( ( V_35 & V_62 ) &&
( V_33 [ V_37 ] . V_35 & V_45 ) &&
! V_33 [ V_37 ] . V_42 )
V_33 [ V_37 ] . V_63 =
V_2 -> V_8 . V_9 >> V_7 ;
else
V_33 [ V_37 ] . V_63 = 0 ;
}
}
void F_14 ( struct V_22 * V_64 , T_2 V_34 )
{
F_13 ( V_64 -> V_2 , & V_64 -> V_31 ,
V_64 -> V_33 , V_34 , V_64 -> V_35 ) ;
}
static void F_15 ( struct V_22 * V_23 ,
struct V_30 * V_31 )
{
F_16 ( V_31 -> V_60 > ( V_65 + 1 ) ) ;
memcpy ( V_23 -> V_33 , V_31 -> V_31 ,
V_31 -> V_60 * sizeof( struct V_32 ) ) ;
V_23 -> V_31 . V_60 = V_31 -> V_60 ;
V_23 -> V_31 . V_61 = V_31 -> V_61 ;
V_23 -> V_31 . V_31 = V_23 -> V_33 ;
V_23 -> V_31 . V_38 = V_23 -> V_33 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_66 ,
bool V_67 , T_2 V_34 , T_1 V_35 ,
struct V_68 * V_69 ,
struct V_30 * V_31 ,
struct V_70 * V_71 ,
struct V_22 * * V_72 )
{
struct V_22 * V_23 ;
enum V_73 type ;
unsigned long V_74 ;
T_3 V_75 ;
int V_76 ;
V_74 = F_18 ( V_66 , V_77 ) >> V_7 ;
V_10 = F_19 ( V_10 , V_77 ) ;
if ( V_67 ) {
type = V_78 ;
} else if ( V_69 ) {
type = V_79 ;
} else {
type = V_80 ;
}
* V_72 = NULL ;
V_75 = F_20 ( & V_2 -> V_81 . V_82 , V_10 ,
sizeof( struct V_22 ) ) ;
V_23 = F_21 ( sizeof( struct V_22 ) , V_83 ) ;
if ( V_23 == NULL )
return - V_84 ;
V_76 = F_22 ( V_2 -> V_85 , & V_23 -> V_27 , V_10 ) ;
if ( F_23 ( V_76 ) ) {
F_11 ( V_23 ) ;
return V_76 ;
}
V_23 -> V_2 = V_2 ;
F_24 ( & V_23 -> V_26 ) ;
F_24 ( & V_23 -> V_86 ) ;
V_23 -> V_87 = V_34 & ( V_39 |
V_47 |
V_51 |
V_53 |
V_55 |
V_57 ) ;
V_23 -> V_35 = V_35 ;
F_15 ( V_23 , V_31 ) ;
V_76 = F_25 ( & V_2 -> V_81 . V_82 , & V_23 -> V_21 , V_10 , type ,
& V_23 -> V_31 , V_74 , ! V_67 , NULL ,
V_75 , V_69 , V_71 , & F_5 ) ;
if ( F_23 ( V_76 != 0 ) ) {
return V_76 ;
}
* V_72 = V_23 ;
F_26 ( V_23 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_66 ,
bool V_67 , T_2 V_34 , T_1 V_35 ,
struct V_68 * V_69 ,
struct V_70 * V_71 ,
struct V_22 * * V_72 )
{
struct V_30 V_31 = { 0 } ;
struct V_32 V_33 [ V_65 + 1 ] ;
memset ( & V_33 , 0 ,
( V_65 + 1 ) * sizeof( struct V_32 ) ) ;
F_13 ( V_2 , & V_31 ,
V_33 , V_34 , V_35 ) ;
return F_17 ( V_2 , V_10 , V_66 , V_67 ,
V_34 , V_35 , V_69 , & V_31 ,
V_71 , V_72 ) ;
}
int F_28 ( struct V_22 * V_23 , void * * V_88 )
{
bool V_89 ;
int V_76 ;
if ( V_23 -> V_35 & V_40 )
return - V_90 ;
if ( V_23 -> V_91 ) {
if ( V_88 ) {
* V_88 = V_23 -> V_91 ;
}
return 0 ;
}
V_76 = F_29 ( & V_23 -> V_21 , 0 , V_23 -> V_21 . V_92 , & V_23 -> V_93 ) ;
if ( V_76 ) {
return V_76 ;
}
V_23 -> V_91 = F_30 ( & V_23 -> V_93 , & V_89 ) ;
if ( V_88 ) {
* V_88 = V_23 -> V_91 ;
}
return 0 ;
}
void F_31 ( struct V_22 * V_23 )
{
if ( V_23 -> V_91 == NULL )
return;
V_23 -> V_91 = NULL ;
F_32 ( & V_23 -> V_93 ) ;
}
struct V_22 * F_33 ( struct V_22 * V_23 )
{
if ( V_23 == NULL )
return NULL ;
F_34 ( & V_23 -> V_21 ) ;
return V_23 ;
}
void F_35 ( struct V_22 * * V_23 )
{
struct V_20 * V_21 ;
if ( ( * V_23 ) == NULL )
return;
V_21 = & ( ( * V_23 ) -> V_21 ) ;
F_36 ( & V_21 ) ;
if ( V_21 == NULL )
* V_23 = NULL ;
}
int F_37 ( struct V_22 * V_23 , T_2 V_34 ,
T_1 V_94 , T_1 V_95 ,
T_1 * V_96 )
{
int V_76 , V_37 ;
unsigned V_42 , V_63 ;
if ( F_38 ( V_23 -> V_21 . V_97 ) )
return - V_90 ;
if ( F_39 ( V_94 > V_95 ) )
return - V_98 ;
if ( V_23 -> V_99 ) {
V_23 -> V_99 ++ ;
if ( V_96 )
* V_96 = F_40 ( V_23 ) ;
if ( V_95 != 0 ) {
T_1 V_100 ;
if ( V_34 == V_39 )
V_100 = V_23 -> V_2 -> V_8 . V_101 ;
else
V_100 = V_23 -> V_2 -> V_8 . V_102 ;
F_39 ( V_95 <
( F_40 ( V_23 ) - V_100 ) ) ;
}
return 0 ;
}
F_14 ( V_23 , V_34 ) ;
for ( V_37 = 0 ; V_37 < V_23 -> V_31 . V_60 ; V_37 ++ ) {
if ( ( V_23 -> V_33 [ V_37 ] . V_35 & V_45 ) &&
! ( V_23 -> V_35 & V_40 ) &&
( ! V_95 || V_95 > V_23 -> V_2 -> V_8 . V_9 ) ) {
if ( F_39 ( V_94 >
V_23 -> V_2 -> V_8 . V_9 ) )
return - V_98 ;
V_42 = V_94 >> V_7 ;
V_63 = V_23 -> V_2 -> V_8 . V_9 >> V_7 ;
} else {
V_42 = V_94 >> V_7 ;
V_63 = V_95 >> V_7 ;
}
if ( V_42 > V_23 -> V_33 [ V_37 ] . V_42 )
V_23 -> V_33 [ V_37 ] . V_42 = V_42 ;
if ( V_63 && V_63 < V_23 -> V_33 [ V_37 ] . V_63 )
V_23 -> V_33 [ V_37 ] . V_63 = V_63 ;
V_23 -> V_33 [ V_37 ] . V_35 |= V_103 ;
}
V_76 = F_41 ( & V_23 -> V_21 , & V_23 -> V_31 , false , false ) ;
if ( F_42 ( V_76 == 0 ) ) {
V_23 -> V_99 = 1 ;
if ( V_96 != NULL )
* V_96 = F_40 ( V_23 ) ;
if ( V_34 == V_39 )
V_23 -> V_2 -> V_104 += F_43 ( V_23 ) ;
else
V_23 -> V_2 -> V_105 += F_43 ( V_23 ) ;
} else {
F_44 ( V_23 -> V_2 -> V_106 , L_1 , V_23 ) ;
}
return V_76 ;
}
int F_45 ( struct V_22 * V_23 , T_2 V_34 , T_1 * V_96 )
{
return F_37 ( V_23 , V_34 , 0 , 0 , V_96 ) ;
}
int F_46 ( struct V_22 * V_23 )
{
int V_76 , V_37 ;
if ( ! V_23 -> V_99 ) {
F_47 ( V_23 -> V_2 -> V_106 , L_2 , V_23 ) ;
return 0 ;
}
V_23 -> V_99 -- ;
if ( V_23 -> V_99 )
return 0 ;
for ( V_37 = 0 ; V_37 < V_23 -> V_31 . V_60 ; V_37 ++ ) {
V_23 -> V_33 [ V_37 ] . V_63 = 0 ;
V_23 -> V_33 [ V_37 ] . V_35 &= ~ V_103 ;
}
V_76 = F_41 ( & V_23 -> V_21 , & V_23 -> V_31 , false , false ) ;
if ( F_42 ( V_76 == 0 ) ) {
if ( V_23 -> V_21 . V_4 . V_14 == V_17 )
V_23 -> V_2 -> V_104 -= F_43 ( V_23 ) ;
else
V_23 -> V_2 -> V_105 -= F_43 ( V_23 ) ;
} else {
F_44 ( V_23 -> V_2 -> V_106 , L_3 , V_23 ) ;
}
return V_76 ;
}
int F_48 ( struct V_1 * V_2 )
{
if ( 0 && ( V_2 -> V_35 & V_107 ) ) {
return 0 ;
}
return F_49 ( & V_2 -> V_81 . V_82 , V_17 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_108 ;
if ( F_51 ( & V_2 -> V_24 . V_109 ) ) {
return;
}
F_44 ( V_2 -> V_106 , L_4 ) ;
F_52 (bo, n, &adev->gem.objects, list) {
F_44 ( V_2 -> V_106 , L_5 ,
& V_23 -> V_27 , V_23 , ( unsigned long ) V_23 -> V_27 . V_10 ,
* ( ( unsigned long * ) & V_23 -> V_27 . V_110 ) ) ;
F_7 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_8 ( & V_23 -> V_26 ) ;
F_9 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_53 ( & V_23 -> V_27 ) ;
}
}
int F_54 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_111 = F_55 ( V_2 -> V_8 . V_112 ,
V_2 -> V_8 . V_113 ) ;
F_56 ( L_6 ,
V_2 -> V_8 . V_114 >> 20 ,
( unsigned long long ) V_2 -> V_8 . V_113 >> 20 ) ;
F_56 ( L_7 ,
V_2 -> V_8 . V_115 ) ;
return F_57 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_60 ( V_2 -> V_8 . V_111 ) ;
}
int F_61 ( struct V_22 * V_23 ,
struct V_116 * V_117 )
{
return F_62 ( V_117 , & V_23 -> V_21 ) ;
}
int F_63 ( struct V_22 * V_23 , T_1 V_118 )
{
if ( F_64 ( V_118 , V_119 ) > 6 )
return - V_98 ;
V_23 -> V_118 = V_118 ;
return 0 ;
}
void F_65 ( struct V_22 * V_23 , T_1 * V_118 )
{
F_66 ( & V_23 -> V_21 . V_71 -> V_120 . V_121 ) ;
if ( V_118 )
* V_118 = V_23 -> V_118 ;
}
int F_67 ( struct V_22 * V_23 , void * V_28 ,
T_4 V_122 , T_5 V_35 )
{
void * V_123 ;
if ( ! V_122 ) {
if ( V_23 -> V_122 ) {
F_11 ( V_23 -> V_28 ) ;
V_23 -> V_122 = 0 ;
}
return 0 ;
}
if ( V_28 == NULL )
return - V_98 ;
V_123 = F_68 ( V_28 , V_122 , V_83 ) ;
if ( V_123 == NULL )
return - V_84 ;
F_11 ( V_23 -> V_28 ) ;
V_23 -> V_124 = V_35 ;
V_23 -> V_28 = V_123 ;
V_23 -> V_122 = V_122 ;
return 0 ;
}
int F_69 ( struct V_22 * V_23 , void * V_123 ,
T_3 V_125 , T_4 * V_122 ,
T_5 * V_35 )
{
if ( ! V_123 && ! V_122 )
return - V_98 ;
if ( V_123 ) {
if ( V_125 < V_23 -> V_122 )
return - V_98 ;
if ( V_23 -> V_122 )
memcpy ( V_123 , V_23 -> V_28 , V_23 -> V_122 ) ;
}
if ( V_122 )
* V_122 = V_23 -> V_122 ;
if ( V_35 )
* V_35 = V_23 -> V_124 ;
return 0 ;
}
void F_70 ( struct V_20 * V_23 ,
struct V_3 * V_12 )
{
struct V_22 * V_64 ;
if ( ! F_12 ( V_23 ) )
return;
V_64 = F_6 ( V_23 , struct V_22 , V_21 ) ;
F_71 ( V_64 -> V_2 , V_64 ) ;
if ( ! V_12 )
return;
F_2 ( V_64 -> V_2 , & V_23 -> V_4 , V_12 ) ;
}
int F_72 ( struct V_20 * V_23 )
{
struct V_1 * V_2 ;
struct V_22 * V_126 ;
unsigned long V_127 , V_10 , V_63 ;
int V_37 , V_76 ;
if ( ! F_12 ( V_23 ) )
return 0 ;
V_126 = F_6 ( V_23 , struct V_22 , V_21 ) ;
V_2 = V_126 -> V_2 ;
if ( V_23 -> V_4 . V_14 != V_17 )
return 0 ;
V_10 = V_23 -> V_4 . V_92 << V_7 ;
V_127 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_127 + V_10 ) <= V_2 -> V_8 . V_9 )
return 0 ;
F_14 ( V_126 , V_39 ) ;
V_63 = V_2 -> V_8 . V_9 >> V_7 ;
for ( V_37 = 0 ; V_37 < V_126 -> V_31 . V_60 ; V_37 ++ ) {
if ( ( V_126 -> V_33 [ V_37 ] . V_35 & V_45 ) &&
( ! V_126 -> V_33 [ V_37 ] . V_63 || V_126 -> V_33 [ V_37 ] . V_63 > V_63 ) )
V_126 -> V_33 [ V_37 ] . V_63 = V_63 ;
}
V_76 = F_41 ( V_23 , & V_126 -> V_31 , false , false ) ;
if ( F_23 ( V_76 == - V_84 ) ) {
F_14 ( V_126 , V_47 ) ;
return F_41 ( V_23 , & V_126 -> V_31 , false , false ) ;
} else if ( F_23 ( V_76 != 0 ) ) {
return V_76 ;
}
V_127 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_127 + V_10 ) > V_2 -> V_8 . V_9 )
return - V_98 ;
return 0 ;
}
void F_73 ( struct V_22 * V_23 , struct V_128 * V_128 ,
bool V_129 )
{
struct V_70 * V_71 = V_23 -> V_21 . V_71 ;
if ( V_129 )
F_74 ( V_71 , V_128 ) ;
else
F_75 ( V_71 , V_128 ) ;
}
