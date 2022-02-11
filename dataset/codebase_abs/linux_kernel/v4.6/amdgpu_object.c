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
F_7 ( & V_23 -> V_24 ) ;
F_8 ( & V_23 -> V_25 ) ;
F_9 ( V_23 -> V_26 ) ;
F_9 ( V_23 ) ;
}
bool F_10 ( struct V_20 * V_23 )
{
if ( V_23 -> V_27 == & F_5 )
return true ;
return false ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_30 * V_31 ,
T_2 V_32 , T_1 V_33 )
{
T_2 V_34 = 0 , V_35 ;
V_29 -> V_29 = V_31 ;
V_29 -> V_36 = V_31 ;
if ( V_32 & V_37 ) {
if ( V_33 & V_38 &&
V_2 -> V_8 . V_9 < V_2 -> V_8 . V_39 ) {
V_31 [ V_34 ] . V_40 =
V_2 -> V_8 . V_9 >> V_7 ;
V_31 [ V_34 ++ ] . V_33 = V_41 | V_42 |
V_43 | V_44 ;
}
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_41 | V_42 |
V_43 ;
if ( ! ( V_33 & V_45 ) )
V_31 [ V_34 - 1 ] . V_33 |= V_44 ;
}
if ( V_32 & V_46 ) {
if ( V_33 & V_47 ) {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_41 | V_48 |
V_42 ;
} else {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_49 | V_48 ;
}
}
if ( V_32 & V_50 ) {
if ( V_33 & V_47 ) {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_41 | V_51 |
V_42 ;
} else {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_49 | V_51 ;
}
}
if ( V_32 & V_52 ) {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_42 |
V_53 ;
}
if ( V_32 & V_54 ) {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_42 |
V_55 ;
}
if ( V_32 & V_56 ) {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_42 |
V_57 ;
}
if ( ! V_34 ) {
V_31 [ V_34 ] . V_40 = 0 ;
V_31 [ V_34 ++ ] . V_33 = V_58 |
V_51 ;
}
V_29 -> V_59 = V_34 ;
V_29 -> V_60 = V_34 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
if ( ( V_33 & V_45 ) &&
( V_31 [ V_35 ] . V_33 & V_43 ) &&
! V_31 [ V_35 ] . V_40 )
V_31 [ V_35 ] . V_61 =
V_2 -> V_8 . V_9 >> V_7 ;
else
V_31 [ V_35 ] . V_61 = 0 ;
}
}
void F_12 ( struct V_22 * V_62 , T_2 V_32 )
{
F_11 ( V_62 -> V_2 , & V_62 -> V_29 ,
V_62 -> V_31 , V_32 , V_62 -> V_33 ) ;
}
static void F_13 ( struct V_22 * V_23 ,
struct V_28 * V_29 )
{
F_14 ( V_29 -> V_59 > ( V_63 + 1 ) ) ;
memcpy ( V_23 -> V_31 , V_29 -> V_29 ,
V_29 -> V_59 * sizeof( struct V_30 ) ) ;
V_23 -> V_29 . V_59 = V_29 -> V_59 ;
V_23 -> V_29 . V_60 = V_29 -> V_60 ;
V_23 -> V_29 . V_29 = V_23 -> V_31 ;
V_23 -> V_29 . V_36 = V_23 -> V_31 ;
}
int F_15 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_64 ,
bool V_65 , T_2 V_32 , T_1 V_33 ,
struct V_66 * V_67 ,
struct V_28 * V_29 ,
struct V_68 * V_69 ,
struct V_22 * * V_70 )
{
struct V_22 * V_23 ;
enum V_71 type ;
unsigned long V_72 ;
T_3 V_73 ;
int V_74 ;
V_72 = F_16 ( V_64 , V_75 ) >> V_7 ;
V_10 = F_17 ( V_10 , V_75 ) ;
if ( V_65 ) {
type = V_76 ;
} else if ( V_67 ) {
type = V_77 ;
} else {
type = V_78 ;
}
* V_70 = NULL ;
V_73 = F_18 ( & V_2 -> V_79 . V_80 , V_10 ,
sizeof( struct V_22 ) ) ;
V_23 = F_19 ( sizeof( struct V_22 ) , V_81 ) ;
if ( V_23 == NULL )
return - V_82 ;
V_74 = F_20 ( V_2 -> V_83 , & V_23 -> V_24 , V_10 ) ;
if ( F_21 ( V_74 ) ) {
F_9 ( V_23 ) ;
return V_74 ;
}
V_23 -> V_2 = V_2 ;
F_22 ( & V_23 -> V_84 ) ;
F_22 ( & V_23 -> V_85 ) ;
V_23 -> V_86 = V_32 & ( V_37 |
V_46 |
V_50 |
V_52 |
V_54 |
V_56 ) ;
V_23 -> V_87 = V_23 -> V_86 ;
if ( ! V_65 && V_23 -> V_87 == V_37 )
V_23 -> V_87 |= V_46 ;
V_23 -> V_33 = V_33 ;
if ( ! F_23 () )
V_23 -> V_33 &= ~ V_47 ;
F_13 ( V_23 , V_29 ) ;
V_74 = F_24 ( & V_2 -> V_79 . V_80 , & V_23 -> V_21 , V_10 , type ,
& V_23 -> V_29 , V_72 , ! V_65 , NULL ,
V_73 , V_67 , V_69 , & F_5 ) ;
if ( F_21 ( V_74 != 0 ) ) {
return V_74 ;
}
* V_70 = V_23 ;
F_25 ( V_23 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
unsigned long V_10 , int V_64 ,
bool V_65 , T_2 V_32 , T_1 V_33 ,
struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_22 * * V_70 )
{
struct V_28 V_29 = { 0 } ;
struct V_30 V_31 [ V_63 + 1 ] ;
memset ( & V_31 , 0 ,
( V_63 + 1 ) * sizeof( struct V_30 ) ) ;
F_11 ( V_2 , & V_29 ,
V_31 , V_32 , V_33 ) ;
return F_15 ( V_2 , V_10 , V_64 , V_65 ,
V_32 , V_33 , V_67 , & V_29 ,
V_69 , V_70 ) ;
}
int F_27 ( struct V_22 * V_23 , void * * V_88 )
{
bool V_89 ;
long V_74 ;
if ( V_23 -> V_33 & V_38 )
return - V_90 ;
if ( V_23 -> V_91 ) {
if ( V_88 ) {
* V_88 = V_23 -> V_91 ;
}
return 0 ;
}
V_74 = F_28 ( V_23 -> V_21 . V_69 , false , false ,
V_92 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_29 ( & V_23 -> V_21 , 0 , V_23 -> V_21 . V_93 , & V_23 -> V_94 ) ;
if ( V_74 )
return V_74 ;
V_23 -> V_91 = F_30 ( & V_23 -> V_94 , & V_89 ) ;
if ( V_88 )
* V_88 = V_23 -> V_91 ;
return 0 ;
}
void F_31 ( struct V_22 * V_23 )
{
if ( V_23 -> V_91 == NULL )
return;
V_23 -> V_91 = NULL ;
F_32 ( & V_23 -> V_94 ) ;
}
struct V_22 * F_33 ( struct V_22 * V_23 )
{
if ( V_23 == NULL )
return NULL ;
F_34 ( & V_23 -> V_21 ) ;
return V_23 ;
}
void F_8 ( struct V_22 * * V_23 )
{
struct V_20 * V_21 ;
if ( ( * V_23 ) == NULL )
return;
V_21 = & ( ( * V_23 ) -> V_21 ) ;
F_35 ( & V_21 ) ;
if ( V_21 == NULL )
* V_23 = NULL ;
}
int F_36 ( struct V_22 * V_23 , T_2 V_32 ,
T_1 V_95 , T_1 V_96 ,
T_1 * V_97 )
{
int V_74 , V_35 ;
unsigned V_40 , V_61 ;
if ( F_37 ( V_23 -> V_21 . V_98 ) )
return - V_90 ;
if ( F_38 ( V_95 > V_96 ) )
return - V_99 ;
if ( V_23 -> V_100 ) {
V_23 -> V_100 ++ ;
if ( V_97 )
* V_97 = F_39 ( V_23 ) ;
if ( V_96 != 0 ) {
T_1 V_101 ;
if ( V_32 == V_37 )
V_101 = V_23 -> V_2 -> V_8 . V_102 ;
else
V_101 = V_23 -> V_2 -> V_8 . V_103 ;
F_38 ( V_96 <
( F_39 ( V_23 ) - V_101 ) ) ;
}
return 0 ;
}
F_12 ( V_23 , V_32 ) ;
for ( V_35 = 0 ; V_35 < V_23 -> V_29 . V_59 ; V_35 ++ ) {
if ( ( V_23 -> V_31 [ V_35 ] . V_33 & V_43 ) &&
! ( V_23 -> V_33 & V_38 ) &&
( ! V_96 || V_96 > V_23 -> V_2 -> V_8 . V_9 ) ) {
if ( F_38 ( V_95 >
V_23 -> V_2 -> V_8 . V_9 ) )
return - V_99 ;
V_40 = V_95 >> V_7 ;
V_61 = V_23 -> V_2 -> V_8 . V_9 >> V_7 ;
} else {
V_40 = V_95 >> V_7 ;
V_61 = V_96 >> V_7 ;
}
if ( V_40 > V_23 -> V_31 [ V_35 ] . V_40 )
V_23 -> V_31 [ V_35 ] . V_40 = V_40 ;
if ( ! V_23 -> V_31 [ V_35 ] . V_61 ||
( V_61 && V_61 < V_23 -> V_31 [ V_35 ] . V_61 ) )
V_23 -> V_31 [ V_35 ] . V_61 = V_61 ;
V_23 -> V_31 [ V_35 ] . V_33 |= V_104 ;
}
V_74 = F_40 ( & V_23 -> V_21 , & V_23 -> V_29 , false , false ) ;
if ( F_41 ( V_74 == 0 ) ) {
V_23 -> V_100 = 1 ;
if ( V_97 != NULL )
* V_97 = F_39 ( V_23 ) ;
if ( V_32 == V_37 ) {
V_23 -> V_2 -> V_105 += F_42 ( V_23 ) ;
if ( V_23 -> V_33 & V_38 )
V_23 -> V_2 -> V_106 += F_42 ( V_23 ) ;
} else
V_23 -> V_2 -> V_107 += F_42 ( V_23 ) ;
} else {
F_43 ( V_23 -> V_2 -> V_108 , L_1 , V_23 ) ;
}
return V_74 ;
}
int F_44 ( struct V_22 * V_23 , T_2 V_32 , T_1 * V_97 )
{
return F_36 ( V_23 , V_32 , 0 , 0 , V_97 ) ;
}
int F_45 ( struct V_22 * V_23 )
{
int V_74 , V_35 ;
if ( ! V_23 -> V_100 ) {
F_46 ( V_23 -> V_2 -> V_108 , L_2 , V_23 ) ;
return 0 ;
}
V_23 -> V_100 -- ;
if ( V_23 -> V_100 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_23 -> V_29 . V_59 ; V_35 ++ ) {
V_23 -> V_31 [ V_35 ] . V_61 = 0 ;
V_23 -> V_31 [ V_35 ] . V_33 &= ~ V_104 ;
}
V_74 = F_40 ( & V_23 -> V_21 , & V_23 -> V_29 , false , false ) ;
if ( F_41 ( V_74 == 0 ) ) {
if ( V_23 -> V_21 . V_4 . V_14 == V_17 ) {
V_23 -> V_2 -> V_105 -= F_42 ( V_23 ) ;
if ( V_23 -> V_33 & V_38 )
V_23 -> V_2 -> V_106 -= F_42 ( V_23 ) ;
} else
V_23 -> V_2 -> V_107 -= F_42 ( V_23 ) ;
} else {
F_43 ( V_23 -> V_2 -> V_108 , L_3 , V_23 ) ;
}
return V_74 ;
}
int F_47 ( struct V_1 * V_2 )
{
if ( 0 && ( V_2 -> V_33 & V_109 ) ) {
return 0 ;
}
return F_48 ( & V_2 -> V_79 . V_80 , V_17 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_110 = F_50 ( V_2 -> V_8 . V_111 ,
V_2 -> V_8 . V_112 ) ;
F_51 ( L_4 ,
V_2 -> V_8 . V_113 >> 20 ,
( unsigned long long ) V_2 -> V_8 . V_112 >> 20 ) ;
F_51 ( L_5 ,
V_2 -> V_8 . V_114 , V_115 [ V_2 -> V_8 . V_116 ] ) ;
return F_52 ( V_2 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
F_55 ( V_2 -> V_8 . V_110 ) ;
}
int F_56 ( struct V_22 * V_23 ,
struct V_117 * V_118 )
{
return F_57 ( V_118 , & V_23 -> V_21 ) ;
}
int F_58 ( struct V_22 * V_23 , T_1 V_119 )
{
if ( F_59 ( V_119 , V_120 ) > 6 )
return - V_99 ;
V_23 -> V_119 = V_119 ;
return 0 ;
}
void F_60 ( struct V_22 * V_23 , T_1 * V_119 )
{
F_61 ( & V_23 -> V_21 . V_69 -> V_121 . V_122 ) ;
if ( V_119 )
* V_119 = V_23 -> V_119 ;
}
int F_62 ( struct V_22 * V_23 , void * V_26 ,
T_4 V_123 , T_5 V_33 )
{
void * V_124 ;
if ( ! V_123 ) {
if ( V_23 -> V_123 ) {
F_9 ( V_23 -> V_26 ) ;
V_23 -> V_26 = NULL ;
V_23 -> V_123 = 0 ;
}
return 0 ;
}
if ( V_26 == NULL )
return - V_99 ;
V_124 = F_63 ( V_26 , V_123 , V_81 ) ;
if ( V_124 == NULL )
return - V_82 ;
F_9 ( V_23 -> V_26 ) ;
V_23 -> V_125 = V_33 ;
V_23 -> V_26 = V_124 ;
V_23 -> V_123 = V_123 ;
return 0 ;
}
int F_64 ( struct V_22 * V_23 , void * V_124 ,
T_3 V_126 , T_4 * V_123 ,
T_5 * V_33 )
{
if ( ! V_124 && ! V_123 )
return - V_99 ;
if ( V_124 ) {
if ( V_126 < V_23 -> V_123 )
return - V_99 ;
if ( V_23 -> V_123 )
memcpy ( V_124 , V_23 -> V_26 , V_23 -> V_123 ) ;
}
if ( V_123 )
* V_123 = V_23 -> V_123 ;
if ( V_33 )
* V_33 = V_23 -> V_125 ;
return 0 ;
}
void F_65 ( struct V_20 * V_23 ,
struct V_3 * V_12 )
{
struct V_22 * V_62 ;
if ( ! F_10 ( V_23 ) )
return;
V_62 = F_6 ( V_23 , struct V_22 , V_21 ) ;
F_66 ( V_62 -> V_2 , V_62 ) ;
if ( ! V_12 )
return;
F_2 ( V_62 -> V_2 , & V_23 -> V_4 , V_12 ) ;
}
int F_67 ( struct V_20 * V_23 )
{
struct V_1 * V_2 ;
struct V_22 * V_127 ;
unsigned long V_128 , V_10 , V_61 ;
int V_35 , V_74 ;
if ( ! F_10 ( V_23 ) )
return 0 ;
V_127 = F_6 ( V_23 , struct V_22 , V_21 ) ;
V_2 = V_127 -> V_2 ;
if ( V_23 -> V_4 . V_14 != V_17 )
return 0 ;
V_10 = V_23 -> V_4 . V_93 << V_7 ;
V_128 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_128 + V_10 ) <= V_2 -> V_8 . V_9 )
return 0 ;
if ( V_127 -> V_100 > 0 )
return - V_99 ;
F_12 ( V_127 , V_37 ) ;
V_61 = V_2 -> V_8 . V_9 >> V_7 ;
for ( V_35 = 0 ; V_35 < V_127 -> V_29 . V_59 ; V_35 ++ ) {
if ( ( V_127 -> V_31 [ V_35 ] . V_33 & V_43 ) &&
( ! V_127 -> V_31 [ V_35 ] . V_61 || V_127 -> V_31 [ V_35 ] . V_61 > V_61 ) )
V_127 -> V_31 [ V_35 ] . V_61 = V_61 ;
}
V_74 = F_40 ( V_23 , & V_127 -> V_29 , false , false ) ;
if ( F_21 ( V_74 == - V_82 ) ) {
F_12 ( V_127 , V_46 ) ;
return F_40 ( V_23 , & V_127 -> V_29 , false , false ) ;
} else if ( F_21 ( V_74 != 0 ) ) {
return V_74 ;
}
V_128 = V_23 -> V_4 . V_6 << V_7 ;
if ( ( V_128 + V_10 ) > V_2 -> V_8 . V_9 )
return - V_99 ;
return 0 ;
}
void F_68 ( struct V_22 * V_23 , struct V_129 * V_129 ,
bool V_130 )
{
struct V_68 * V_69 = V_23 -> V_21 . V_69 ;
if ( V_130 )
F_69 ( V_69 , V_129 ) ;
else
F_70 ( V_69 , V_129 ) ;
}
