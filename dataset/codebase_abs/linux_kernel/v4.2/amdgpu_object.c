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
V_45 ;
}
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_44 |
V_45 ;
}
if ( V_34 & V_46 ) {
if ( V_35 & V_47 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_48 |
V_44 ;
} else {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_49 | V_48 ;
}
}
if ( V_34 & V_50 ) {
if ( V_35 & V_47 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_43 | V_51 |
V_44 ;
} else {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_49 | V_51 ;
}
}
if ( V_34 & V_52 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_44 |
V_53 ;
}
if ( V_34 & V_54 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_44 |
V_55 ;
}
if ( V_34 & V_56 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_44 |
V_57 ;
}
if ( ! V_36 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ++ ] . V_35 = V_58 |
V_51 ;
}
V_31 -> V_59 = V_36 ;
V_31 -> V_60 = V_36 ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
if ( ( V_35 & V_61 ) &&
( V_33 [ V_37 ] . V_35 & V_45 ) &&
! V_33 [ V_37 ] . V_42 )
V_33 [ V_37 ] . V_62 =
V_2 -> V_8 . V_9 >> V_7 ;
else
V_33 [ V_37 ] . V_62 = 0 ;
}
}
void F_14 ( struct V_22 * V_63 , T_2 V_34 )
{
F_13 ( V_63 -> V_2 , & V_63 -> V_31 ,
V_63 -> V_33 , V_34 , V_63 -> V_35 ) ;
}
static void F_15 ( struct V_22 * V_23 ,
struct V_30 * V_31 )
{
F_16 ( V_31 -> V_59 > ( V_64 + 1 ) ) ;
memcpy ( V_23 -> V_33 , V_31 -> V_31 ,
V_31 -> V_59 * sizeof( struct V_32 ) ) ;
V_23 -> V_31 . V_59 = V_31 -> V_59 ;
V_23 -> V_31 . V_60 = V_31 -> V_60 ;
V_23 -> V_31 . V_31 = V_23 -> V_33 ;
V_23 -> V_31 . V_38 = V_23 -> V_33 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_65 ,
bool V_66 , T_2 V_34 , T_1 V_35 ,
struct V_67 * V_68 ,
struct V_30 * V_31 ,
struct V_22 * * V_69 )
{
struct V_22 * V_23 ;
enum V_70 type ;
unsigned long V_71 ;
T_3 V_72 ;
int V_73 ;
if ( ! ( V_34 & ( V_52 | V_54 | V_56 ) ) ) {
if ( V_2 -> V_74 >= V_75 ) {
if ( V_65 & 0x7fff )
V_65 = F_18 ( V_65 , 0x8000 ) ;
if ( V_10 & 0x7fff )
V_10 = F_18 ( V_10 , 0x8000 ) ;
}
}
V_71 = F_19 ( V_65 , V_76 ) >> V_7 ;
V_10 = F_18 ( V_10 , V_76 ) ;
if ( V_66 ) {
type = V_77 ;
} else if ( V_68 ) {
type = V_78 ;
} else {
type = V_79 ;
}
* V_69 = NULL ;
V_72 = F_20 ( & V_2 -> V_80 . V_81 , V_10 ,
sizeof( struct V_22 ) ) ;
V_23 = F_21 ( sizeof( struct V_22 ) , V_82 ) ;
if ( V_23 == NULL )
return - V_83 ;
V_73 = F_22 ( V_2 -> V_84 , & V_23 -> V_27 , V_10 ) ;
if ( F_23 ( V_73 ) ) {
F_11 ( V_23 ) ;
return V_73 ;
}
V_23 -> V_2 = V_2 ;
F_24 ( & V_23 -> V_26 ) ;
F_24 ( & V_23 -> V_85 ) ;
V_23 -> V_86 = V_34 & ( V_39 |
V_46 |
V_50 |
V_52 |
V_54 |
V_56 ) ;
V_23 -> V_35 = V_35 ;
F_15 ( V_23 , V_31 ) ;
V_73 = F_25 ( & V_2 -> V_80 . V_81 , & V_23 -> V_21 , V_10 , type ,
& V_23 -> V_31 , V_71 , ! V_66 , NULL ,
V_72 , V_68 , NULL , & F_5 ) ;
if ( F_23 ( V_73 != 0 ) ) {
return V_73 ;
}
* V_69 = V_23 ;
F_26 ( V_23 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_65 ,
bool V_66 , T_2 V_34 , T_1 V_35 ,
struct V_67 * V_68 , struct V_22 * * V_69 )
{
struct V_30 V_31 = { 0 } ;
struct V_32 V_33 [ V_64 + 1 ] ;
memset ( & V_33 , 0 ,
( V_64 + 1 ) * sizeof( struct V_32 ) ) ;
F_13 ( V_2 , & V_31 ,
V_33 , V_34 , V_35 ) ;
return F_17 ( V_2 , V_10 , V_65 ,
V_66 , V_34 , V_35 ,
V_68 ,
& V_31 ,
V_69 ) ;
}
int F_28 ( struct V_22 * V_23 , void * * V_87 )
{
bool V_88 ;
int V_73 ;
if ( V_23 -> V_35 & V_40 )
return - V_89 ;
if ( V_23 -> V_90 ) {
if ( V_87 ) {
* V_87 = V_23 -> V_90 ;
}
return 0 ;
}
V_73 = F_29 ( & V_23 -> V_21 , 0 , V_23 -> V_21 . V_91 , & V_23 -> V_92 ) ;
if ( V_73 ) {
return V_73 ;
}
V_23 -> V_90 = F_30 ( & V_23 -> V_92 , & V_88 ) ;
if ( V_87 ) {
* V_87 = V_23 -> V_90 ;
}
return 0 ;
}
void F_31 ( struct V_22 * V_23 )
{
if ( V_23 -> V_90 == NULL )
return;
V_23 -> V_90 = NULL ;
F_32 ( & V_23 -> V_92 ) ;
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
T_1 V_93 , T_1 V_94 ,
T_1 * V_95 )
{
int V_73 , V_37 ;
unsigned V_42 , V_62 ;
if ( F_38 ( V_23 -> V_21 . V_96 ) )
return - V_89 ;
if ( F_39 ( V_93 > V_94 ) )
return - V_97 ;
if ( V_23 -> V_98 ) {
V_23 -> V_98 ++ ;
if ( V_95 )
* V_95 = F_40 ( V_23 ) ;
if ( V_94 != 0 ) {
T_1 V_99 ;
if ( V_34 == V_39 )
V_99 = V_23 -> V_2 -> V_8 . V_100 ;
else
V_99 = V_23 -> V_2 -> V_8 . V_101 ;
F_39 ( V_94 <
( F_40 ( V_23 ) - V_99 ) ) ;
}
return 0 ;
}
F_14 ( V_23 , V_34 ) ;
for ( V_37 = 0 ; V_37 < V_23 -> V_31 . V_59 ; V_37 ++ ) {
if ( ( V_23 -> V_33 [ V_37 ] . V_35 & V_45 ) &&
! ( V_23 -> V_35 & V_40 ) &&
( ! V_94 || V_94 > V_23 -> V_2 -> V_8 . V_9 ) ) {
if ( F_39 ( V_93 >
V_23 -> V_2 -> V_8 . V_9 ) )
return - V_97 ;
V_42 = V_93 >> V_7 ;
V_62 = V_23 -> V_2 -> V_8 . V_9 >> V_7 ;
} else {
V_42 = V_93 >> V_7 ;
V_62 = V_94 >> V_7 ;
}
if ( V_42 > V_23 -> V_33 [ V_37 ] . V_42 )
V_23 -> V_33 [ V_37 ] . V_42 = V_42 ;
if ( V_62 && V_62 < V_23 -> V_33 [ V_37 ] . V_62 )
V_23 -> V_33 [ V_37 ] . V_62 = V_62 ;
V_23 -> V_33 [ V_37 ] . V_35 |= V_102 ;
}
V_73 = F_41 ( & V_23 -> V_21 , & V_23 -> V_31 , false , false ) ;
if ( F_42 ( V_73 == 0 ) ) {
V_23 -> V_98 = 1 ;
if ( V_95 != NULL )
* V_95 = F_40 ( V_23 ) ;
if ( V_34 == V_39 )
V_23 -> V_2 -> V_103 += F_43 ( V_23 ) ;
else
V_23 -> V_2 -> V_104 += F_43 ( V_23 ) ;
} else {
F_44 ( V_23 -> V_2 -> V_105 , L_1 , V_23 ) ;
}
return V_73 ;
}
int F_45 ( struct V_22 * V_23 , T_2 V_34 , T_1 * V_95 )
{
return F_37 ( V_23 , V_34 , 0 , 0 , V_95 ) ;
}
int F_46 ( struct V_22 * V_23 )
{
int V_73 , V_37 ;
if ( ! V_23 -> V_98 ) {
F_47 ( V_23 -> V_2 -> V_105 , L_2 , V_23 ) ;
return 0 ;
}
V_23 -> V_98 -- ;
if ( V_23 -> V_98 )
return 0 ;
for ( V_37 = 0 ; V_37 < V_23 -> V_31 . V_59 ; V_37 ++ ) {
V_23 -> V_33 [ V_37 ] . V_62 = 0 ;
V_23 -> V_33 [ V_37 ] . V_35 &= ~ V_102 ;
}
V_73 = F_41 ( & V_23 -> V_21 , & V_23 -> V_31 , false , false ) ;
if ( F_42 ( V_73 == 0 ) ) {
if ( V_23 -> V_21 . V_4 . V_14 == V_17 )
V_23 -> V_2 -> V_103 -= F_43 ( V_23 ) ;
else
V_23 -> V_2 -> V_104 -= F_43 ( V_23 ) ;
} else {
F_44 ( V_23 -> V_2 -> V_105 , L_3 , V_23 ) ;
}
return V_73 ;
}
int F_48 ( struct V_1 * V_2 )
{
if ( 0 && ( V_2 -> V_35 & V_106 ) ) {
return 0 ;
}
return F_49 ( & V_2 -> V_80 . V_81 , V_17 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_107 ;
if ( F_51 ( & V_2 -> V_24 . V_108 ) ) {
return;
}
F_44 ( V_2 -> V_105 , L_4 ) ;
F_52 (bo, n, &adev->gem.objects, list) {
F_7 ( & V_2 -> V_84 -> V_109 ) ;
F_44 ( V_2 -> V_105 , L_5 ,
& V_23 -> V_27 , V_23 , ( unsigned long ) V_23 -> V_27 . V_10 ,
* ( ( unsigned long * ) & V_23 -> V_27 . V_110 ) ) ;
F_7 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_8 ( & V_23 -> V_26 ) ;
F_9 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_53 ( & V_23 -> V_27 ) ;
F_9 ( & V_2 -> V_84 -> V_109 ) ;
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
return - V_97 ;
V_23 -> V_118 = V_118 ;
return 0 ;
}
void F_65 ( struct V_22 * V_23 , T_1 * V_118 )
{
F_66 ( & V_23 -> V_21 . V_120 -> V_121 . V_122 ) ;
if ( V_118 )
* V_118 = V_23 -> V_118 ;
}
int F_67 ( struct V_22 * V_23 , void * V_28 ,
T_4 V_123 , T_5 V_35 )
{
void * V_124 ;
if ( ! V_123 ) {
if ( V_23 -> V_123 ) {
F_11 ( V_23 -> V_28 ) ;
V_23 -> V_123 = 0 ;
}
return 0 ;
}
if ( V_28 == NULL )
return - V_97 ;
V_124 = F_21 ( V_123 , V_82 ) ;
if ( V_124 == NULL )
return - V_83 ;
memcpy ( V_124 , V_28 , V_123 ) ;
F_11 ( V_23 -> V_28 ) ;
V_23 -> V_125 = V_35 ;
V_23 -> V_28 = V_124 ;
V_23 -> V_123 = V_123 ;
return 0 ;
}
int F_68 ( struct V_22 * V_23 , void * V_124 ,
T_3 V_126 , T_4 * V_123 ,
T_5 * V_35 )
{
if ( ! V_124 && ! V_123 )
return - V_97 ;
if ( V_124 ) {
if ( V_126 < V_23 -> V_123 )
return - V_97 ;
if ( V_23 -> V_123 )
memcpy ( V_124 , V_23 -> V_28 , V_23 -> V_123 ) ;
}
if ( V_123 )
* V_123 = V_23 -> V_123 ;
if ( V_35 )
* V_35 = V_23 -> V_125 ;
return 0 ;
}
void F_69 ( struct V_20 * V_23 ,
struct V_3 * V_12 )
{
struct V_22 * V_63 ;
if ( ! F_12 ( V_23 ) )
return;
V_63 = F_6 ( V_23 , struct V_22 , V_21 ) ;
F_70 ( V_63 -> V_2 , V_63 ) ;
if ( ! V_12 )
return;
F_2 ( V_63 -> V_2 , & V_23 -> V_4 , V_12 ) ;
}
int F_71 ( struct V_20 * V_23 )
{
struct V_1 * V_2 ;
struct V_22 * V_127 ;
unsigned long V_128 , V_10 , V_62 ;
int V_37 , V_73 ;
if ( ! F_12 ( V_23 ) )
return 0 ;
V_127 = F_6 ( V_23 , struct V_22 , V_21 ) ;
V_2 = V_127 -> V_2 ;
if ( V_23 -> V_4 . V_14 != V_17 )
return 0 ;
V_10 = V_23 -> V_4 . V_91 << V_7 ;
V_128 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_128 + V_10 ) <= V_2 -> V_8 . V_9 )
return 0 ;
F_14 ( V_127 , V_39 ) ;
V_62 = V_2 -> V_8 . V_9 >> V_7 ;
for ( V_37 = 0 ; V_37 < V_127 -> V_31 . V_59 ; V_37 ++ ) {
if ( ( V_127 -> V_33 [ V_37 ] . V_35 & V_45 ) &&
( ! V_127 -> V_33 [ V_37 ] . V_62 || V_127 -> V_33 [ V_37 ] . V_62 > V_62 ) )
V_127 -> V_33 [ V_37 ] . V_62 = V_62 ;
}
V_73 = F_41 ( V_23 , & V_127 -> V_31 , false , false ) ;
if ( F_23 ( V_73 == - V_83 ) ) {
F_14 ( V_127 , V_46 ) ;
return F_41 ( V_23 , & V_127 -> V_31 , false , false ) ;
} else if ( F_23 ( V_73 != 0 ) ) {
return V_73 ;
}
V_128 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_128 + V_10 ) > V_2 -> V_8 . V_9 )
return - V_97 ;
return 0 ;
}
void F_72 ( struct V_22 * V_23 , struct V_129 * V_130 ,
bool V_131 )
{
struct V_132 * V_120 = V_23 -> V_21 . V_120 ;
if ( V_131 )
F_73 ( V_120 , & V_130 -> V_122 ) ;
else
F_74 ( V_120 , & V_130 -> V_122 ) ;
}
