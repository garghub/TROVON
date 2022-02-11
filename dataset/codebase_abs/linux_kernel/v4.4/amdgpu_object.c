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
F_11 ( & V_23 -> V_28 ) ;
F_12 ( V_23 -> V_29 ) ;
F_12 ( V_23 ) ;
}
bool F_13 ( struct V_20 * V_23 )
{
if ( V_23 -> V_30 == & F_5 )
return true ;
return false ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_2 V_35 , T_1 V_36 )
{
T_2 V_37 = 0 , V_38 ;
V_32 -> V_32 = V_34 ;
V_32 -> V_39 = V_34 ;
if ( V_35 & V_40 ) {
if ( V_36 & V_41 &&
V_2 -> V_8 . V_9 < V_2 -> V_8 . V_42 ) {
V_34 [ V_37 ] . V_43 =
V_2 -> V_8 . V_9 >> V_7 ;
V_34 [ V_37 ++ ] . V_36 = V_44 | V_45 |
V_46 | V_47 ;
}
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_44 | V_45 |
V_46 ;
if ( ! ( V_36 & V_48 ) )
V_34 [ V_37 - 1 ] . V_36 |= V_47 ;
}
if ( V_35 & V_49 ) {
if ( V_36 & V_50 ) {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_44 | V_51 |
V_45 ;
} else {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_52 | V_51 ;
}
}
if ( V_35 & V_53 ) {
if ( V_36 & V_50 ) {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_44 | V_54 |
V_45 ;
} else {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_52 | V_54 ;
}
}
if ( V_35 & V_55 ) {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_45 |
V_56 ;
}
if ( V_35 & V_57 ) {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_45 |
V_58 ;
}
if ( V_35 & V_59 ) {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_45 |
V_60 ;
}
if ( ! V_37 ) {
V_34 [ V_37 ] . V_43 = 0 ;
V_34 [ V_37 ++ ] . V_36 = V_61 |
V_54 ;
}
V_32 -> V_62 = V_37 ;
V_32 -> V_63 = V_37 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
if ( ( V_36 & V_48 ) &&
( V_34 [ V_38 ] . V_36 & V_46 ) &&
! V_34 [ V_38 ] . V_43 )
V_34 [ V_38 ] . V_64 =
V_2 -> V_8 . V_9 >> V_7 ;
else
V_34 [ V_38 ] . V_64 = 0 ;
}
}
void F_15 ( struct V_22 * V_65 , T_2 V_35 )
{
F_14 ( V_65 -> V_2 , & V_65 -> V_32 ,
V_65 -> V_34 , V_35 , V_65 -> V_36 ) ;
}
static void F_16 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
F_17 ( V_32 -> V_62 > ( V_66 + 1 ) ) ;
memcpy ( V_23 -> V_34 , V_32 -> V_32 ,
V_32 -> V_62 * sizeof( struct V_33 ) ) ;
V_23 -> V_32 . V_62 = V_32 -> V_62 ;
V_23 -> V_32 . V_63 = V_32 -> V_63 ;
V_23 -> V_32 . V_32 = V_23 -> V_34 ;
V_23 -> V_32 . V_39 = V_23 -> V_34 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_67 ,
bool V_68 , T_2 V_35 , T_1 V_36 ,
struct V_69 * V_70 ,
struct V_31 * V_32 ,
struct V_71 * V_72 ,
struct V_22 * * V_73 )
{
struct V_22 * V_23 ;
enum V_74 type ;
unsigned long V_75 ;
T_3 V_76 ;
int V_77 ;
V_75 = F_19 ( V_67 , V_78 ) >> V_7 ;
V_10 = F_20 ( V_10 , V_78 ) ;
if ( V_68 ) {
type = V_79 ;
} else if ( V_70 ) {
type = V_80 ;
} else {
type = V_81 ;
}
* V_73 = NULL ;
V_76 = F_21 ( & V_2 -> V_82 . V_83 , V_10 ,
sizeof( struct V_22 ) ) ;
V_23 = F_22 ( sizeof( struct V_22 ) , V_84 ) ;
if ( V_23 == NULL )
return - V_85 ;
V_77 = F_23 ( V_2 -> V_86 , & V_23 -> V_27 , V_10 ) ;
if ( F_24 ( V_77 ) ) {
F_12 ( V_23 ) ;
return V_77 ;
}
V_23 -> V_2 = V_2 ;
F_25 ( & V_23 -> V_26 ) ;
F_25 ( & V_23 -> V_87 ) ;
V_23 -> V_88 = V_35 & ( V_40 |
V_49 |
V_53 |
V_55 |
V_57 |
V_59 ) ;
V_23 -> V_36 = V_36 ;
F_16 ( V_23 , V_32 ) ;
V_77 = F_26 ( & V_2 -> V_82 . V_83 , & V_23 -> V_21 , V_10 , type ,
& V_23 -> V_32 , V_75 , ! V_68 , NULL ,
V_76 , V_70 , V_72 , & F_5 ) ;
if ( F_24 ( V_77 != 0 ) ) {
return V_77 ;
}
* V_73 = V_23 ;
F_27 ( V_23 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_67 ,
bool V_68 , T_2 V_35 , T_1 V_36 ,
struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_22 * * V_73 )
{
struct V_31 V_32 = { 0 } ;
struct V_33 V_34 [ V_66 + 1 ] ;
memset ( & V_34 , 0 ,
( V_66 + 1 ) * sizeof( struct V_33 ) ) ;
F_14 ( V_2 , & V_32 ,
V_34 , V_35 , V_36 ) ;
return F_18 ( V_2 , V_10 , V_67 , V_68 ,
V_35 , V_36 , V_70 , & V_32 ,
V_72 , V_73 ) ;
}
int F_29 ( struct V_22 * V_23 , void * * V_89 )
{
bool V_90 ;
int V_77 ;
if ( V_23 -> V_36 & V_41 )
return - V_91 ;
if ( V_23 -> V_92 ) {
if ( V_89 ) {
* V_89 = V_23 -> V_92 ;
}
return 0 ;
}
V_77 = F_30 ( & V_23 -> V_21 , 0 , V_23 -> V_21 . V_93 , & V_23 -> V_94 ) ;
if ( V_77 ) {
return V_77 ;
}
V_23 -> V_92 = F_31 ( & V_23 -> V_94 , & V_90 ) ;
if ( V_89 ) {
* V_89 = V_23 -> V_92 ;
}
return 0 ;
}
void F_32 ( struct V_22 * V_23 )
{
if ( V_23 -> V_92 == NULL )
return;
V_23 -> V_92 = NULL ;
F_33 ( & V_23 -> V_94 ) ;
}
struct V_22 * F_34 ( struct V_22 * V_23 )
{
if ( V_23 == NULL )
return NULL ;
F_35 ( & V_23 -> V_21 ) ;
return V_23 ;
}
void F_11 ( struct V_22 * * V_23 )
{
struct V_20 * V_21 ;
if ( ( * V_23 ) == NULL )
return;
V_21 = & ( ( * V_23 ) -> V_21 ) ;
F_36 ( & V_21 ) ;
if ( V_21 == NULL )
* V_23 = NULL ;
}
int F_37 ( struct V_22 * V_23 , T_2 V_35 ,
T_1 V_95 , T_1 V_96 ,
T_1 * V_97 )
{
int V_77 , V_38 ;
unsigned V_43 , V_64 ;
if ( F_38 ( V_23 -> V_21 . V_98 ) )
return - V_91 ;
if ( F_39 ( V_95 > V_96 ) )
return - V_99 ;
if ( V_23 -> V_100 ) {
V_23 -> V_100 ++ ;
if ( V_97 )
* V_97 = F_40 ( V_23 ) ;
if ( V_96 != 0 ) {
T_1 V_101 ;
if ( V_35 == V_40 )
V_101 = V_23 -> V_2 -> V_8 . V_102 ;
else
V_101 = V_23 -> V_2 -> V_8 . V_103 ;
F_39 ( V_96 <
( F_40 ( V_23 ) - V_101 ) ) ;
}
return 0 ;
}
F_15 ( V_23 , V_35 ) ;
for ( V_38 = 0 ; V_38 < V_23 -> V_32 . V_62 ; V_38 ++ ) {
if ( ( V_23 -> V_34 [ V_38 ] . V_36 & V_46 ) &&
! ( V_23 -> V_36 & V_41 ) &&
( ! V_96 || V_96 > V_23 -> V_2 -> V_8 . V_9 ) ) {
if ( F_39 ( V_95 >
V_23 -> V_2 -> V_8 . V_9 ) )
return - V_99 ;
V_43 = V_95 >> V_7 ;
V_64 = V_23 -> V_2 -> V_8 . V_9 >> V_7 ;
} else {
V_43 = V_95 >> V_7 ;
V_64 = V_96 >> V_7 ;
}
if ( V_43 > V_23 -> V_34 [ V_38 ] . V_43 )
V_23 -> V_34 [ V_38 ] . V_43 = V_43 ;
if ( V_64 && V_64 < V_23 -> V_34 [ V_38 ] . V_64 )
V_23 -> V_34 [ V_38 ] . V_64 = V_64 ;
V_23 -> V_34 [ V_38 ] . V_36 |= V_104 ;
}
V_77 = F_41 ( & V_23 -> V_21 , & V_23 -> V_32 , false , false ) ;
if ( F_42 ( V_77 == 0 ) ) {
V_23 -> V_100 = 1 ;
if ( V_97 != NULL )
* V_97 = F_40 ( V_23 ) ;
if ( V_35 == V_40 )
V_23 -> V_2 -> V_105 += F_43 ( V_23 ) ;
else
V_23 -> V_2 -> V_106 += F_43 ( V_23 ) ;
} else {
F_44 ( V_23 -> V_2 -> V_107 , L_1 , V_23 ) ;
}
return V_77 ;
}
int F_45 ( struct V_22 * V_23 , T_2 V_35 , T_1 * V_97 )
{
return F_37 ( V_23 , V_35 , 0 , 0 , V_97 ) ;
}
int F_46 ( struct V_22 * V_23 )
{
int V_77 , V_38 ;
if ( ! V_23 -> V_100 ) {
F_47 ( V_23 -> V_2 -> V_107 , L_2 , V_23 ) ;
return 0 ;
}
V_23 -> V_100 -- ;
if ( V_23 -> V_100 )
return 0 ;
for ( V_38 = 0 ; V_38 < V_23 -> V_32 . V_62 ; V_38 ++ ) {
V_23 -> V_34 [ V_38 ] . V_64 = 0 ;
V_23 -> V_34 [ V_38 ] . V_36 &= ~ V_104 ;
}
V_77 = F_41 ( & V_23 -> V_21 , & V_23 -> V_32 , false , false ) ;
if ( F_42 ( V_77 == 0 ) ) {
if ( V_23 -> V_21 . V_4 . V_14 == V_17 )
V_23 -> V_2 -> V_105 -= F_43 ( V_23 ) ;
else
V_23 -> V_2 -> V_106 -= F_43 ( V_23 ) ;
} else {
F_44 ( V_23 -> V_2 -> V_107 , L_3 , V_23 ) ;
}
return V_77 ;
}
int F_48 ( struct V_1 * V_2 )
{
if ( 0 && ( V_2 -> V_36 & V_108 ) ) {
return 0 ;
}
return F_49 ( & V_2 -> V_82 . V_83 , V_17 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_109 ;
if ( F_51 ( & V_2 -> V_24 . V_110 ) ) {
return;
}
F_44 ( V_2 -> V_107 , L_4 ) ;
F_52 (bo, n, &adev->gem.objects, list) {
F_44 ( V_2 -> V_107 , L_5 ,
& V_23 -> V_27 , V_23 , ( unsigned long ) V_23 -> V_27 . V_10 ,
* ( ( unsigned long * ) & V_23 -> V_27 . V_111 ) ) ;
F_7 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_8 ( & V_23 -> V_26 ) ;
F_9 ( & V_23 -> V_2 -> V_24 . V_25 ) ;
F_53 ( & V_23 -> V_27 ) ;
}
}
int F_54 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_112 = F_55 ( V_2 -> V_8 . V_113 ,
V_2 -> V_8 . V_114 ) ;
F_56 ( L_6 ,
V_2 -> V_8 . V_115 >> 20 ,
( unsigned long long ) V_2 -> V_8 . V_114 >> 20 ) ;
F_56 ( L_7 ,
V_2 -> V_8 . V_116 ) ;
return F_57 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_60 ( V_2 -> V_8 . V_112 ) ;
}
int F_61 ( struct V_22 * V_23 ,
struct V_117 * V_118 )
{
return F_62 ( V_118 , & V_23 -> V_21 ) ;
}
int F_63 ( struct V_22 * V_23 , T_1 V_119 )
{
if ( F_64 ( V_119 , V_120 ) > 6 )
return - V_99 ;
V_23 -> V_119 = V_119 ;
return 0 ;
}
void F_65 ( struct V_22 * V_23 , T_1 * V_119 )
{
F_66 ( & V_23 -> V_21 . V_72 -> V_121 . V_122 ) ;
if ( V_119 )
* V_119 = V_23 -> V_119 ;
}
int F_67 ( struct V_22 * V_23 , void * V_29 ,
T_4 V_123 , T_5 V_36 )
{
void * V_124 ;
if ( ! V_123 ) {
if ( V_23 -> V_123 ) {
F_12 ( V_23 -> V_29 ) ;
V_23 -> V_123 = 0 ;
}
return 0 ;
}
if ( V_29 == NULL )
return - V_99 ;
V_124 = F_68 ( V_29 , V_123 , V_84 ) ;
if ( V_124 == NULL )
return - V_85 ;
F_12 ( V_23 -> V_29 ) ;
V_23 -> V_125 = V_36 ;
V_23 -> V_29 = V_124 ;
V_23 -> V_123 = V_123 ;
return 0 ;
}
int F_69 ( struct V_22 * V_23 , void * V_124 ,
T_3 V_126 , T_4 * V_123 ,
T_5 * V_36 )
{
if ( ! V_124 && ! V_123 )
return - V_99 ;
if ( V_124 ) {
if ( V_126 < V_23 -> V_123 )
return - V_99 ;
if ( V_23 -> V_123 )
memcpy ( V_124 , V_23 -> V_29 , V_23 -> V_123 ) ;
}
if ( V_123 )
* V_123 = V_23 -> V_123 ;
if ( V_36 )
* V_36 = V_23 -> V_125 ;
return 0 ;
}
void F_70 ( struct V_20 * V_23 ,
struct V_3 * V_12 )
{
struct V_22 * V_65 ;
if ( ! F_13 ( V_23 ) )
return;
V_65 = F_6 ( V_23 , struct V_22 , V_21 ) ;
F_71 ( V_65 -> V_2 , V_65 ) ;
if ( ! V_12 )
return;
F_2 ( V_65 -> V_2 , & V_23 -> V_4 , V_12 ) ;
}
int F_72 ( struct V_20 * V_23 )
{
struct V_1 * V_2 ;
struct V_22 * V_127 ;
unsigned long V_128 , V_10 , V_64 ;
int V_38 , V_77 ;
if ( ! F_13 ( V_23 ) )
return 0 ;
V_127 = F_6 ( V_23 , struct V_22 , V_21 ) ;
V_2 = V_127 -> V_2 ;
if ( V_23 -> V_4 . V_14 != V_17 )
return 0 ;
V_10 = V_23 -> V_4 . V_93 << V_7 ;
V_128 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_128 + V_10 ) <= V_2 -> V_8 . V_9 )
return 0 ;
F_15 ( V_127 , V_40 ) ;
V_64 = V_2 -> V_8 . V_9 >> V_7 ;
for ( V_38 = 0 ; V_38 < V_127 -> V_32 . V_62 ; V_38 ++ ) {
if ( ( V_127 -> V_34 [ V_38 ] . V_36 & V_46 ) &&
( ! V_127 -> V_34 [ V_38 ] . V_64 || V_127 -> V_34 [ V_38 ] . V_64 > V_64 ) )
V_127 -> V_34 [ V_38 ] . V_64 = V_64 ;
}
V_77 = F_41 ( V_23 , & V_127 -> V_32 , false , false ) ;
if ( F_24 ( V_77 == - V_85 ) ) {
F_15 ( V_127 , V_49 ) ;
return F_41 ( V_23 , & V_127 -> V_32 , false , false ) ;
} else if ( F_24 ( V_77 != 0 ) ) {
return V_77 ;
}
V_128 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_128 + V_10 ) > V_2 -> V_8 . V_9 )
return - V_99 ;
return 0 ;
}
void F_73 ( struct V_22 * V_23 , struct V_129 * V_129 ,
bool V_130 )
{
struct V_71 * V_72 = V_23 -> V_21 . V_72 ;
if ( V_130 )
F_74 ( V_72 , V_129 ) ;
else
F_75 ( V_72 , V_129 ) ;
}
