static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 << V_6 >= V_2 -> V_7 . V_8 )
return 0 ;
return ( ( V_4 -> V_5 << V_6 ) + V_4 -> V_9 ) >
V_2 -> V_7 . V_8 ?
V_2 -> V_7 . V_8 - ( V_4 -> V_5 << V_6 ) :
V_4 -> V_9 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_10 ,
struct V_3 * V_11 )
{
T_1 V_12 ;
if ( ! V_2 )
return;
if ( V_11 ) {
switch ( V_11 -> V_13 ) {
case V_14 :
F_3 ( V_11 -> V_9 , & V_2 -> V_15 ) ;
break;
case V_16 :
F_3 ( V_11 -> V_9 , & V_2 -> V_17 ) ;
V_12 = F_1 ( V_2 , V_11 ) ;
F_3 ( V_12 , & V_2 -> V_18 ) ;
break;
}
}
if ( V_10 ) {
switch ( V_10 -> V_13 ) {
case V_14 :
F_4 ( V_10 -> V_9 , & V_2 -> V_15 ) ;
break;
case V_16 :
F_4 ( V_10 -> V_9 , & V_2 -> V_17 ) ;
V_12 = F_1 ( V_2 , V_10 ) ;
F_4 ( V_12 , & V_2 -> V_18 ) ;
break;
}
}
}
static void F_5 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_6 ( V_20 , struct V_21 , V_20 ) ;
F_2 ( V_22 -> V_2 , & V_22 -> V_20 . V_4 , NULL ) ;
F_7 ( & V_22 -> V_23 ) ;
F_8 ( & V_22 -> V_24 ) ;
if ( ! F_9 ( & V_22 -> V_25 ) ) {
F_10 ( & V_22 -> V_2 -> V_26 ) ;
F_11 ( & V_22 -> V_25 ) ;
F_12 ( & V_22 -> V_2 -> V_26 ) ;
}
F_13 ( V_22 -> V_27 ) ;
F_13 ( V_22 ) ;
}
bool F_14 ( struct V_19 * V_22 )
{
if ( V_22 -> V_28 == & F_5 )
return true ;
return false ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
T_2 V_33 , T_1 V_34 )
{
T_2 V_35 = 0 ;
if ( V_33 & V_36 ) {
unsigned V_37 = V_2 -> V_7 . V_8 >> V_6 ;
if ( V_34 & V_38 &&
! ( V_34 & V_39 ) &&
V_2 -> V_7 . V_8 < V_2 -> V_7 . V_40 ) {
V_32 [ V_35 ] . V_41 = V_37 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_43 |
V_44 | V_45 |
V_46 ;
V_35 ++ ;
}
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_43 | V_44 |
V_45 ;
if ( V_34 & V_39 )
V_32 [ V_35 ] . V_42 = V_37 ;
else
V_32 [ V_35 ] . V_34 |= V_46 ;
V_35 ++ ;
}
if ( V_33 & V_47 ) {
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_48 ;
if ( V_34 & V_49 )
V_32 [ V_35 ] . V_34 |= V_43 |
V_44 ;
else
V_32 [ V_35 ] . V_34 |= V_50 ;
V_35 ++ ;
}
if ( V_33 & V_51 ) {
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_52 ;
if ( V_34 & V_49 )
V_32 [ V_35 ] . V_34 |= V_43 |
V_44 ;
else
V_32 [ V_35 ] . V_34 |= V_50 ;
V_35 ++ ;
}
if ( V_33 & V_53 ) {
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_44 | V_54 ;
V_35 ++ ;
}
if ( V_33 & V_55 ) {
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_44 | V_56 ;
V_35 ++ ;
}
if ( V_33 & V_57 ) {
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_44 | V_58 ;
V_35 ++ ;
}
if ( ! V_35 ) {
V_32 [ V_35 ] . V_41 = 0 ;
V_32 [ V_35 ] . V_42 = 0 ;
V_32 [ V_35 ] . V_34 = V_59 | V_52 ;
V_35 ++ ;
}
V_30 -> V_60 = V_35 ;
V_30 -> V_30 = V_32 ;
V_30 -> V_61 = V_35 ;
V_30 -> V_62 = V_32 ;
}
void F_16 ( struct V_21 * V_63 , T_2 V_33 )
{
F_15 ( V_63 -> V_2 , & V_63 -> V_30 ,
V_63 -> V_64 , V_33 , V_63 -> V_34 ) ;
}
static void F_17 ( struct V_21 * V_22 ,
struct V_29 * V_30 )
{
F_18 ( V_30 -> V_60 > ( V_65 + 1 ) ) ;
memcpy ( V_22 -> V_64 , V_30 -> V_30 ,
V_30 -> V_60 * sizeof( struct V_31 ) ) ;
V_22 -> V_30 . V_60 = V_30 -> V_60 ;
V_22 -> V_30 . V_61 = V_30 -> V_61 ;
V_22 -> V_30 . V_30 = V_22 -> V_64 ;
V_22 -> V_30 . V_62 = V_22 -> V_64 ;
}
int F_19 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_66 ,
T_2 V_33 , struct V_21 * * V_67 ,
T_1 * V_68 , void * * V_69 )
{
int V_70 ;
V_70 = F_20 ( V_2 , V_9 , V_66 , true , V_33 ,
V_39 ,
NULL , NULL , V_67 ) ;
if ( V_70 ) {
F_21 ( V_2 -> V_71 , L_1 , V_70 ) ;
return V_70 ;
}
V_70 = F_22 ( * V_67 , false ) ;
if ( V_70 ) {
F_21 ( V_2 -> V_71 , L_2 , V_70 ) ;
goto V_72;
}
V_70 = F_23 ( * V_67 , V_33 , V_68 ) ;
if ( V_70 ) {
F_21 ( V_2 -> V_71 , L_3 , V_70 ) ;
goto V_73;
}
if ( V_69 ) {
V_70 = F_24 ( * V_67 , V_69 ) ;
if ( V_70 ) {
F_21 ( V_2 -> V_71 , L_4 , V_70 ) ;
goto V_73;
}
}
F_25 ( * V_67 ) ;
return 0 ;
V_73:
F_25 ( * V_67 ) ;
V_72:
F_8 ( V_67 ) ;
return V_70 ;
}
void F_26 ( struct V_21 * * V_22 , T_1 * V_68 ,
void * * V_69 )
{
if ( * V_22 == NULL )
return;
if ( F_27 ( F_22 ( * V_22 , false ) == 0 ) ) {
if ( V_69 )
F_28 ( * V_22 ) ;
F_29 ( * V_22 ) ;
F_25 ( * V_22 ) ;
}
F_8 ( V_22 ) ;
if ( V_68 )
* V_68 = 0 ;
if ( V_69 )
* V_69 = NULL ;
}
int F_30 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_74 ,
bool V_75 , T_2 V_33 , T_1 V_34 ,
struct V_76 * V_77 ,
struct V_29 * V_30 ,
struct V_78 * V_79 ,
struct V_21 * * V_67 )
{
struct V_21 * V_22 ;
enum V_80 type ;
unsigned long V_81 ;
T_3 V_82 ;
int V_70 ;
V_81 = F_31 ( V_74 , V_83 ) >> V_6 ;
V_9 = F_32 ( V_9 , V_83 ) ;
if ( V_75 ) {
type = V_84 ;
} else if ( V_77 ) {
type = V_85 ;
} else {
type = V_86 ;
}
* V_67 = NULL ;
V_82 = F_33 ( & V_2 -> V_87 . V_88 , V_9 ,
sizeof( struct V_21 ) ) ;
V_22 = F_34 ( sizeof( struct V_21 ) , V_89 ) ;
if ( V_22 == NULL )
return - V_90 ;
V_70 = F_35 ( V_2 -> V_91 , & V_22 -> V_23 , V_9 ) ;
if ( F_36 ( V_70 ) ) {
F_13 ( V_22 ) ;
return V_70 ;
}
V_22 -> V_2 = V_2 ;
F_37 ( & V_22 -> V_25 ) ;
F_37 ( & V_22 -> V_92 ) ;
V_22 -> V_93 = V_33 & ( V_36 |
V_47 |
V_51 |
V_53 |
V_55 |
V_57 ) ;
V_22 -> V_94 = V_22 -> V_93 ;
if ( ! V_75 && V_22 -> V_94 == V_36 )
V_22 -> V_94 |= V_47 ;
V_22 -> V_34 = V_34 ;
if ( ! F_38 () )
V_22 -> V_34 &= ~ V_49 ;
F_17 ( V_22 , V_30 ) ;
V_70 = F_39 ( & V_2 -> V_87 . V_88 , & V_22 -> V_20 , V_9 , type ,
& V_22 -> V_30 , V_81 , ! V_75 , NULL ,
V_82 , V_77 , V_79 , & F_5 ) ;
if ( F_36 ( V_70 != 0 ) ) {
return V_70 ;
}
if ( V_34 & V_95 &&
V_22 -> V_20 . V_4 . V_30 & V_45 ) {
struct V_96 * V_96 ;
if ( V_2 -> V_87 . V_97 == NULL ||
! V_2 -> V_87 . V_97 -> V_98 ) {
V_70 = - V_99 ;
goto V_100;
}
V_70 = F_22 ( V_22 , false ) ;
if ( F_36 ( V_70 != 0 ) )
goto V_100;
F_16 ( V_22 , V_36 ) ;
V_70 = F_40 ( & V_22 -> V_20 , & V_22 -> V_30 , false , false ) ;
if ( F_36 ( V_70 != 0 ) )
goto V_101;
F_41 ( V_22 , 0 , V_22 -> V_20 . V_79 , & V_96 ) ;
F_42 ( V_22 , V_96 , false ) ;
F_25 ( V_22 ) ;
F_43 ( V_22 -> V_20 . V_102 ) ;
V_22 -> V_20 . V_102 = F_44 ( V_96 ) ;
F_43 ( V_96 ) ;
}
* V_67 = V_22 ;
F_45 ( V_22 ) ;
return 0 ;
V_101:
F_25 ( V_22 ) ;
V_100:
F_8 ( & V_22 ) ;
return V_70 ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_74 ,
struct V_21 * V_22 )
{
struct V_29 V_30 = { 0 } ;
struct V_31 V_64 [ V_65 + 1 ] ;
int V_70 ;
if ( V_22 -> V_103 )
return 0 ;
V_22 -> V_34 |= V_104 ;
memset ( & V_64 , 0 ,
( V_65 + 1 ) * sizeof( struct V_31 ) ) ;
F_15 ( V_2 , & V_30 ,
V_64 , V_47 ,
V_49 ) ;
V_70 = F_30 ( V_2 , V_9 , V_74 , true ,
V_47 ,
V_49 ,
NULL , & V_30 ,
V_22 -> V_20 . V_79 ,
& V_22 -> V_103 ) ;
if ( ! V_70 ) {
V_22 -> V_103 -> V_24 = F_47 ( V_22 ) ;
F_10 ( & V_2 -> V_26 ) ;
F_48 ( & V_22 -> V_25 , & V_2 -> V_25 ) ;
F_12 ( & V_2 -> V_26 ) ;
}
return V_70 ;
}
int F_20 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_74 ,
bool V_75 , T_2 V_33 , T_1 V_34 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_21 * * V_67 )
{
struct V_29 V_30 = { 0 } ;
struct V_31 V_64 [ V_65 + 1 ] ;
int V_70 ;
memset ( & V_64 , 0 ,
( V_65 + 1 ) * sizeof( struct V_31 ) ) ;
F_15 ( V_2 , & V_30 ,
V_64 , V_33 , V_34 ) ;
V_70 = F_30 ( V_2 , V_9 , V_74 , V_75 ,
V_33 , V_34 , V_77 , & V_30 ,
V_79 , V_67 ) ;
if ( V_70 )
return V_70 ;
if ( F_49 ( V_2 ) && ( V_34 & V_104 ) ) {
V_70 = F_46 ( V_2 , V_9 , V_74 , ( * V_67 ) ) ;
if ( V_70 )
F_8 ( V_67 ) ;
}
return V_70 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_21 * V_22 ,
struct V_78 * V_79 ,
struct V_96 * * V_96 ,
bool V_107 )
{
struct V_21 * V_103 = V_22 -> V_103 ;
T_4 V_108 , V_109 ;
int V_70 ;
if ( ! V_103 )
return - V_110 ;
V_108 = F_51 ( V_22 ) ;
V_109 = F_51 ( V_22 -> V_103 ) ;
V_70 = F_52 ( V_22 -> V_20 . V_79 ) ;
if ( V_70 )
goto V_111;
V_70 = F_53 ( V_106 , V_108 , V_109 ,
F_54 ( V_22 ) , V_79 , V_96 ,
V_107 ) ;
if ( ! V_70 )
F_42 ( V_22 , * V_96 , true ) ;
V_111:
return V_70 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_21 * V_22 ,
struct V_78 * V_79 ,
struct V_96 * * V_96 ,
bool V_107 )
{
struct V_21 * V_103 = V_22 -> V_103 ;
T_4 V_108 , V_109 ;
int V_70 ;
if ( ! V_103 )
return - V_110 ;
V_108 = F_51 ( V_22 ) ;
V_109 = F_51 ( V_22 -> V_103 ) ;
V_70 = F_52 ( V_22 -> V_20 . V_79 ) ;
if ( V_70 )
goto V_111;
V_70 = F_53 ( V_106 , V_109 , V_108 ,
F_54 ( V_22 ) , V_79 , V_96 ,
V_107 ) ;
if ( ! V_70 )
F_42 ( V_22 , * V_96 , true ) ;
V_111:
return V_70 ;
}
int F_24 ( struct V_21 * V_22 , void * * V_112 )
{
bool V_113 ;
long V_70 ;
if ( V_22 -> V_34 & V_38 )
return - V_114 ;
if ( V_22 -> V_115 ) {
if ( V_112 ) {
* V_112 = V_22 -> V_115 ;
}
return 0 ;
}
V_70 = F_56 ( V_22 -> V_20 . V_79 , false , false ,
V_116 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_57 ( & V_22 -> V_20 , 0 , V_22 -> V_20 . V_117 , & V_22 -> V_118 ) ;
if ( V_70 )
return V_70 ;
V_22 -> V_115 = F_58 ( & V_22 -> V_118 , & V_113 ) ;
if ( V_112 )
* V_112 = V_22 -> V_115 ;
return 0 ;
}
void F_28 ( struct V_21 * V_22 )
{
if ( V_22 -> V_115 == NULL )
return;
V_22 -> V_115 = NULL ;
F_59 ( & V_22 -> V_118 ) ;
}
struct V_21 * F_47 ( struct V_21 * V_22 )
{
if ( V_22 == NULL )
return NULL ;
F_60 ( & V_22 -> V_20 ) ;
return V_22 ;
}
void F_8 ( struct V_21 * * V_22 )
{
struct V_19 * V_20 ;
if ( ( * V_22 ) == NULL )
return;
V_20 = & ( ( * V_22 ) -> V_20 ) ;
F_61 ( & V_20 ) ;
if ( V_20 == NULL )
* V_22 = NULL ;
}
int F_62 ( struct V_21 * V_22 , T_2 V_33 ,
T_1 V_119 , T_1 V_120 ,
T_1 * V_68 )
{
int V_70 , V_121 ;
unsigned V_41 , V_42 ;
if ( F_63 ( V_22 -> V_20 . V_122 ) )
return - V_114 ;
if ( F_64 ( V_119 > V_120 ) )
return - V_110 ;
if ( V_22 -> V_123 ) {
T_5 V_13 = V_22 -> V_20 . V_4 . V_13 ;
if ( V_33 != F_65 ( V_13 ) )
return - V_110 ;
V_22 -> V_123 ++ ;
if ( V_68 )
* V_68 = F_51 ( V_22 ) ;
if ( V_120 != 0 ) {
T_1 V_124 = V_22 -> V_20 . V_88 -> V_125 [ V_13 ] . V_126 ;
F_64 ( V_120 <
( F_51 ( V_22 ) - V_124 ) ) ;
}
return 0 ;
}
F_16 ( V_22 , V_33 ) ;
for ( V_121 = 0 ; V_121 < V_22 -> V_30 . V_60 ; V_121 ++ ) {
if ( ( V_22 -> V_64 [ V_121 ] . V_34 & V_45 ) &&
! ( V_22 -> V_34 & V_38 ) &&
( ! V_120 || V_120 >
V_22 -> V_2 -> V_7 . V_8 ) ) {
if ( F_64 ( V_119 >
V_22 -> V_2 -> V_7 . V_8 ) )
return - V_110 ;
V_41 = V_119 >> V_6 ;
V_42 = V_22 -> V_2 -> V_7 . V_8 >> V_6 ;
} else {
V_41 = V_119 >> V_6 ;
V_42 = V_120 >> V_6 ;
}
if ( V_41 > V_22 -> V_64 [ V_121 ] . V_41 )
V_22 -> V_64 [ V_121 ] . V_41 = V_41 ;
if ( ! V_22 -> V_64 [ V_121 ] . V_42 ||
( V_42 && V_42 < V_22 -> V_64 [ V_121 ] . V_42 ) )
V_22 -> V_64 [ V_121 ] . V_42 = V_42 ;
V_22 -> V_64 [ V_121 ] . V_34 |= V_127 ;
}
V_70 = F_40 ( & V_22 -> V_20 , & V_22 -> V_30 , false , false ) ;
if ( F_36 ( V_70 ) ) {
F_21 ( V_22 -> V_2 -> V_71 , L_5 , V_22 ) ;
goto error;
}
V_70 = F_66 ( & V_22 -> V_20 , & V_22 -> V_20 . V_4 ) ;
if ( F_36 ( V_70 ) ) {
F_21 ( V_22 -> V_2 -> V_71 , L_6 , V_22 ) ;
goto error;
}
V_22 -> V_123 = 1 ;
if ( V_68 != NULL )
* V_68 = F_51 ( V_22 ) ;
if ( V_33 == V_36 ) {
V_22 -> V_2 -> V_128 += F_54 ( V_22 ) ;
if ( V_22 -> V_34 & V_38 )
V_22 -> V_2 -> V_129 += F_54 ( V_22 ) ;
} else if ( V_33 == V_47 ) {
V_22 -> V_2 -> V_130 += F_54 ( V_22 ) ;
}
error:
return V_70 ;
}
int F_23 ( struct V_21 * V_22 , T_2 V_33 , T_1 * V_68 )
{
return F_62 ( V_22 , V_33 , 0 , 0 , V_68 ) ;
}
int F_29 ( struct V_21 * V_22 )
{
int V_70 , V_121 ;
if ( ! V_22 -> V_123 ) {
F_67 ( V_22 -> V_2 -> V_71 , L_7 , V_22 ) ;
return 0 ;
}
V_22 -> V_123 -- ;
if ( V_22 -> V_123 )
return 0 ;
for ( V_121 = 0 ; V_121 < V_22 -> V_30 . V_60 ; V_121 ++ ) {
V_22 -> V_64 [ V_121 ] . V_42 = 0 ;
V_22 -> V_64 [ V_121 ] . V_34 &= ~ V_127 ;
}
V_70 = F_40 ( & V_22 -> V_20 , & V_22 -> V_30 , false , false ) ;
if ( F_36 ( V_70 ) ) {
F_21 ( V_22 -> V_2 -> V_71 , L_8 , V_22 ) ;
goto error;
}
if ( V_22 -> V_20 . V_4 . V_13 == V_16 ) {
V_22 -> V_2 -> V_128 -= F_54 ( V_22 ) ;
if ( V_22 -> V_34 & V_38 )
V_22 -> V_2 -> V_129 -= F_54 ( V_22 ) ;
} else if ( V_22 -> V_20 . V_4 . V_13 == V_14 ) {
V_22 -> V_2 -> V_130 -= F_54 ( V_22 ) ;
}
error:
return V_70 ;
}
int F_68 ( struct V_1 * V_2 )
{
if ( 0 && ( V_2 -> V_34 & V_131 ) ) {
return 0 ;
}
return F_69 ( & V_2 -> V_87 . V_88 , V_16 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
F_71 ( V_2 -> V_7 . V_132 ,
V_2 -> V_7 . V_133 ) ;
V_2 -> V_7 . V_134 = F_72 ( V_2 -> V_7 . V_132 ,
V_2 -> V_7 . V_133 ) ;
F_73 ( L_9 ,
V_2 -> V_7 . V_135 >> 20 ,
( unsigned long long ) V_2 -> V_7 . V_133 >> 20 ) ;
F_73 ( L_10 ,
V_2 -> V_7 . V_136 , V_137 [ V_2 -> V_7 . V_138 ] ) ;
return F_74 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
F_77 ( V_2 -> V_7 . V_134 ) ;
F_78 ( V_2 -> V_7 . V_132 , V_2 -> V_7 . V_133 ) ;
}
int F_79 ( struct V_21 * V_22 ,
struct V_139 * V_140 )
{
return F_80 ( V_140 , & V_22 -> V_20 ) ;
}
int F_81 ( struct V_21 * V_22 , T_1 V_141 )
{
if ( F_82 ( V_141 , V_142 ) > 6 )
return - V_110 ;
V_22 -> V_141 = V_141 ;
return 0 ;
}
void F_83 ( struct V_21 * V_22 , T_1 * V_141 )
{
F_84 ( & V_22 -> V_20 . V_79 -> V_143 . V_144 ) ;
if ( V_141 )
* V_141 = V_22 -> V_141 ;
}
int F_85 ( struct V_21 * V_22 , void * V_27 ,
T_5 V_145 , T_4 V_34 )
{
void * V_146 ;
if ( ! V_145 ) {
if ( V_22 -> V_145 ) {
F_13 ( V_22 -> V_27 ) ;
V_22 -> V_27 = NULL ;
V_22 -> V_145 = 0 ;
}
return 0 ;
}
if ( V_27 == NULL )
return - V_110 ;
V_146 = F_86 ( V_27 , V_145 , V_89 ) ;
if ( V_146 == NULL )
return - V_90 ;
F_13 ( V_22 -> V_27 ) ;
V_22 -> V_147 = V_34 ;
V_22 -> V_27 = V_146 ;
V_22 -> V_145 = V_145 ;
return 0 ;
}
int F_87 ( struct V_21 * V_22 , void * V_146 ,
T_3 V_148 , T_5 * V_145 ,
T_4 * V_34 )
{
if ( ! V_146 && ! V_145 )
return - V_110 ;
if ( V_146 ) {
if ( V_148 < V_22 -> V_145 )
return - V_110 ;
if ( V_22 -> V_145 )
memcpy ( V_146 , V_22 -> V_27 , V_22 -> V_145 ) ;
}
if ( V_145 )
* V_145 = V_22 -> V_145 ;
if ( V_34 )
* V_34 = V_22 -> V_147 ;
return 0 ;
}
void F_88 ( struct V_19 * V_22 ,
struct V_3 * V_11 )
{
struct V_21 * V_63 ;
struct V_3 * V_10 = & V_22 -> V_4 ;
if ( ! F_14 ( V_22 ) )
return;
V_63 = F_6 ( V_22 , struct V_21 , V_20 ) ;
F_89 ( V_63 -> V_2 , V_63 ) ;
if ( ! V_11 )
return;
F_2 ( V_63 -> V_2 , & V_22 -> V_4 , V_11 ) ;
F_90 ( V_63 , V_11 -> V_13 , V_10 -> V_13 ) ;
}
int F_91 ( struct V_19 * V_22 )
{
struct V_1 * V_2 ;
struct V_21 * V_63 ;
unsigned long V_149 , V_9 , V_42 ;
int V_121 , V_70 ;
if ( ! F_14 ( V_22 ) )
return 0 ;
V_63 = F_6 ( V_22 , struct V_21 , V_20 ) ;
V_2 = V_63 -> V_2 ;
if ( V_22 -> V_4 . V_13 != V_16 )
return 0 ;
V_9 = V_22 -> V_4 . V_117 << V_6 ;
V_149 = V_22 -> V_4 . V_5 << V_6 ;
if ( ( V_149 + V_9 ) <= V_2 -> V_7 . V_8 )
return 0 ;
if ( V_63 -> V_123 > 0 )
return - V_110 ;
F_16 ( V_63 , V_36 ) ;
V_42 = V_2 -> V_7 . V_8 >> V_6 ;
for ( V_121 = 0 ; V_121 < V_63 -> V_30 . V_60 ; V_121 ++ ) {
if ( ( V_63 -> V_64 [ V_121 ] . V_34 & V_45 ) &&
( ! V_63 -> V_64 [ V_121 ] . V_42 ||
V_63 -> V_64 [ V_121 ] . V_42 > V_42 ) )
V_63 -> V_64 [ V_121 ] . V_42 = V_42 ;
}
V_70 = F_40 ( V_22 , & V_63 -> V_30 , false , false ) ;
if ( F_36 ( V_70 == - V_90 ) ) {
F_16 ( V_63 , V_47 ) ;
return F_40 ( V_22 , & V_63 -> V_30 , false , false ) ;
} else if ( F_36 ( V_70 != 0 ) ) {
return V_70 ;
}
V_149 = V_22 -> V_4 . V_5 << V_6 ;
if ( ( V_149 + V_9 ) > V_2 -> V_7 . V_8 )
return - V_110 ;
return 0 ;
}
void F_42 ( struct V_21 * V_22 , struct V_96 * V_96 ,
bool V_150 )
{
struct V_78 * V_79 = V_22 -> V_20 . V_79 ;
if ( V_150 )
F_92 ( V_79 , V_96 ) ;
else
F_93 ( V_79 , V_96 ) ;
}
T_1 F_51 ( struct V_21 * V_22 )
{
F_64 ( V_22 -> V_20 . V_4 . V_13 == V_151 ) ;
F_64 ( V_22 -> V_20 . V_4 . V_13 == V_14 &&
! F_94 ( V_22 -> V_20 . V_122 ) ) ;
F_64 ( ! F_95 ( & V_22 -> V_20 . V_79 -> V_143 ) &&
! V_22 -> V_123 ) ;
F_64 ( V_22 -> V_20 . V_4 . V_5 == V_152 ) ;
return V_22 -> V_20 . V_149 ;
}
