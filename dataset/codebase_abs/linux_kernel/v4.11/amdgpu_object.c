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
struct V_1 * V_2 = F_6 ( V_20 -> V_21 ) ;
struct V_22 * V_23 ;
V_23 = F_7 ( V_20 , struct V_22 , V_20 ) ;
F_2 ( V_2 , & V_23 -> V_20 . V_4 , NULL ) ;
F_8 ( & V_23 -> V_24 ) ;
F_9 ( & V_23 -> V_25 ) ;
if ( ! F_10 ( & V_23 -> V_26 ) ) {
F_11 ( & V_2 -> V_27 ) ;
F_12 ( & V_23 -> V_26 ) ;
F_13 ( & V_2 -> V_27 ) ;
}
F_14 ( V_23 -> V_28 ) ;
F_14 ( V_23 ) ;
}
bool F_15 ( struct V_19 * V_23 )
{
if ( V_23 -> V_29 == & F_5 )
return true ;
return false ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_2 V_34 , T_1 V_35 )
{
T_2 V_36 = 0 ;
if ( V_34 & V_37 ) {
unsigned V_38 = V_2 -> V_7 . V_8 >> V_6 ;
unsigned V_39 = 0 ;
if ( V_35 & V_40 )
V_39 = V_2 -> V_7 . V_41 >> V_6 ;
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = V_39 ;
V_33 [ V_36 ] . V_35 = V_43 | V_44 |
V_45 ;
if ( V_35 & V_46 )
V_33 [ V_36 ] . V_39 = V_38 ;
else
V_33 [ V_36 ] . V_35 |= V_47 ;
V_36 ++ ;
}
if ( V_34 & V_48 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = 0 ;
V_33 [ V_36 ] . V_35 = V_49 ;
if ( V_35 & V_50 )
V_33 [ V_36 ] . V_35 |= V_43 |
V_44 ;
else
V_33 [ V_36 ] . V_35 |= V_51 ;
V_36 ++ ;
}
if ( V_34 & V_52 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = 0 ;
V_33 [ V_36 ] . V_35 = V_53 ;
if ( V_35 & V_50 )
V_33 [ V_36 ] . V_35 |= V_43 |
V_44 ;
else
V_33 [ V_36 ] . V_35 |= V_51 ;
V_36 ++ ;
}
if ( V_34 & V_54 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = 0 ;
V_33 [ V_36 ] . V_35 = V_44 | V_55 ;
V_36 ++ ;
}
if ( V_34 & V_56 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = 0 ;
V_33 [ V_36 ] . V_35 = V_44 | V_57 ;
V_36 ++ ;
}
if ( V_34 & V_58 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = 0 ;
V_33 [ V_36 ] . V_35 = V_44 | V_59 ;
V_36 ++ ;
}
if ( ! V_36 ) {
V_33 [ V_36 ] . V_42 = 0 ;
V_33 [ V_36 ] . V_39 = 0 ;
V_33 [ V_36 ] . V_35 = V_60 | V_53 ;
V_36 ++ ;
}
V_31 -> V_61 = V_36 ;
V_31 -> V_31 = V_33 ;
V_31 -> V_62 = V_36 ;
V_31 -> V_63 = V_33 ;
}
void F_17 ( struct V_22 * V_64 , T_2 V_34 )
{
struct V_1 * V_2 = F_6 ( V_64 -> V_20 . V_21 ) ;
F_16 ( V_2 , & V_64 -> V_31 , V_64 -> V_65 ,
V_34 , V_64 -> V_35 ) ;
}
static void F_18 ( struct V_22 * V_23 ,
struct V_30 * V_31 )
{
F_19 ( V_31 -> V_61 > ( V_66 + 1 ) ) ;
memcpy ( V_23 -> V_65 , V_31 -> V_31 ,
V_31 -> V_61 * sizeof( struct V_32 ) ) ;
V_23 -> V_31 . V_61 = V_31 -> V_61 ;
V_23 -> V_31 . V_62 = V_31 -> V_62 ;
V_23 -> V_31 . V_31 = V_23 -> V_65 ;
V_23 -> V_31 . V_63 = V_23 -> V_65 ;
}
int F_20 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_67 ,
T_2 V_34 , struct V_22 * * V_68 ,
T_1 * V_69 , void * * V_70 )
{
int V_71 ;
V_71 = F_21 ( V_2 , V_9 , V_67 , true , V_34 ,
V_46 |
V_40 ,
NULL , NULL , V_68 ) ;
if ( V_71 ) {
F_22 ( V_2 -> V_72 , L_1 , V_71 ) ;
return V_71 ;
}
V_71 = F_23 ( * V_68 , false ) ;
if ( V_71 ) {
F_22 ( V_2 -> V_72 , L_2 , V_71 ) ;
goto V_73;
}
V_71 = F_24 ( * V_68 , V_34 , V_69 ) ;
if ( V_71 ) {
F_22 ( V_2 -> V_72 , L_3 , V_71 ) ;
goto V_74;
}
if ( V_70 ) {
V_71 = F_25 ( * V_68 , V_70 ) ;
if ( V_71 ) {
F_22 ( V_2 -> V_72 , L_4 , V_71 ) ;
goto V_74;
}
}
F_26 ( * V_68 ) ;
return 0 ;
V_74:
F_26 ( * V_68 ) ;
V_73:
F_9 ( V_68 ) ;
return V_71 ;
}
void F_27 ( struct V_22 * * V_23 , T_1 * V_69 ,
void * * V_70 )
{
if ( * V_23 == NULL )
return;
if ( F_28 ( F_23 ( * V_23 , false ) == 0 ) ) {
if ( V_70 )
F_29 ( * V_23 ) ;
F_30 ( * V_23 ) ;
F_26 ( * V_23 ) ;
}
F_9 ( V_23 ) ;
if ( V_69 )
* V_69 = 0 ;
if ( V_70 )
* V_70 = NULL ;
}
int F_31 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_75 ,
bool V_76 , T_2 V_34 , T_1 V_35 ,
struct V_77 * V_78 ,
struct V_30 * V_31 ,
struct V_79 * V_80 ,
struct V_22 * * V_68 )
{
struct V_22 * V_23 ;
enum V_81 type ;
unsigned long V_82 ;
T_1 V_83 ;
T_3 V_84 ;
int V_71 ;
V_82 = F_32 ( V_75 , V_85 ) >> V_6 ;
V_9 = F_33 ( V_9 , V_85 ) ;
if ( V_76 ) {
type = V_86 ;
} else if ( V_78 ) {
type = V_87 ;
} else {
type = V_88 ;
}
* V_68 = NULL ;
V_84 = F_34 ( & V_2 -> V_89 . V_21 , V_9 ,
sizeof( struct V_22 ) ) ;
V_23 = F_35 ( sizeof( struct V_22 ) , V_90 ) ;
if ( V_23 == NULL )
return - V_91 ;
V_71 = F_36 ( V_2 -> V_92 , & V_23 -> V_24 , V_9 ) ;
if ( F_37 ( V_71 ) ) {
F_14 ( V_23 ) ;
return V_71 ;
}
F_38 ( & V_23 -> V_26 ) ;
F_38 ( & V_23 -> V_93 ) ;
V_23 -> V_94 = V_34 & ( V_37 |
V_48 |
V_52 |
V_54 |
V_56 |
V_58 ) ;
V_23 -> V_95 = V_23 -> V_94 ;
if ( ! V_76 && V_23 -> V_95 == V_37 )
V_23 -> V_95 |= V_48 ;
V_23 -> V_35 = V_35 ;
#ifdef F_39
V_23 -> V_35 &= ~ V_50 ;
#elif F_40 ( V_96 ) && ! F_40 ( V_97 )
#ifndef F_41
#warning Please enable CONFIG_MTRR and CONFIG_X86_PAT for better performance \
thanks to write-combining
#endif
if ( V_23 -> V_35 & V_50 )
F_42 ( L_5
L_6 ) ;
V_23 -> V_35 &= ~ V_50 ;
#else
if ( ! F_43 () )
V_23 -> V_35 &= ~ V_50 ;
#endif
F_18 ( V_23 , V_31 ) ;
if ( ! V_80 ) {
bool V_98 ;
F_44 ( & V_23 -> V_20 . V_99 ) ;
V_98 = F_45 ( & V_23 -> V_20 . V_99 . V_100 ) ;
F_46 ( ! V_98 ) ;
}
V_83 = F_47 ( & V_2 -> V_101 ) ;
V_71 = F_48 ( & V_2 -> V_89 . V_21 , & V_23 -> V_20 , V_9 , type ,
& V_23 -> V_31 , V_82 , ! V_76 , NULL ,
V_84 , V_78 , V_80 ? V_80 : & V_23 -> V_20 . V_99 ,
& F_5 ) ;
F_49 ( V_2 ,
F_47 ( & V_2 -> V_101 ) - V_83 ) ;
if ( F_37 ( V_71 != 0 ) ) {
if ( ! V_80 )
F_50 ( & V_23 -> V_20 . V_80 -> V_100 ) ;
return V_71 ;
}
V_23 -> V_20 . V_102 = F_51 ( V_23 -> V_20 . V_103 ) ;
if ( V_76 )
V_23 -> V_20 . V_102 *= 2 ;
V_23 -> V_20 . V_102 = F_52 ( V_23 -> V_20 . V_102 , ( unsigned ) ( V_104 - 1 ) ) ;
if ( V_35 & V_105 &&
V_23 -> V_20 . V_4 . V_31 & V_45 ) {
struct V_106 * V_107 ;
V_71 = F_53 ( V_23 , 0 , V_23 -> V_20 . V_80 , & V_107 ) ;
if ( F_37 ( V_71 ) )
goto V_108;
F_54 ( V_23 , V_107 , false ) ;
F_55 ( V_23 -> V_20 . V_109 ) ;
V_23 -> V_20 . V_109 = F_56 ( V_107 ) ;
F_55 ( V_107 ) ;
}
if ( ! V_80 )
F_50 ( & V_23 -> V_20 . V_80 -> V_100 ) ;
* V_68 = V_23 ;
F_57 ( V_23 ) ;
return 0 ;
V_108:
if ( ! V_80 )
F_50 ( & V_23 -> V_20 . V_80 -> V_100 ) ;
F_9 ( & V_23 ) ;
return V_71 ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_75 ,
struct V_22 * V_23 )
{
struct V_30 V_31 = { 0 } ;
struct V_32 V_65 [ V_66 + 1 ] ;
int V_71 ;
if ( V_23 -> V_110 )
return 0 ;
V_23 -> V_35 |= V_111 ;
memset ( & V_65 , 0 ,
( V_66 + 1 ) * sizeof( struct V_32 ) ) ;
F_16 ( V_2 , & V_31 ,
V_65 , V_48 ,
V_50 ) ;
V_71 = F_31 ( V_2 , V_9 , V_75 , true ,
V_48 ,
V_50 ,
NULL , & V_31 ,
V_23 -> V_20 . V_80 ,
& V_23 -> V_110 ) ;
if ( ! V_71 ) {
V_23 -> V_110 -> V_25 = F_59 ( V_23 ) ;
F_11 ( & V_2 -> V_27 ) ;
F_60 ( & V_23 -> V_26 , & V_2 -> V_26 ) ;
F_13 ( & V_2 -> V_27 ) ;
}
return V_71 ;
}
int F_21 ( struct V_1 * V_2 ,
unsigned long V_9 , int V_75 ,
bool V_76 , T_2 V_34 , T_1 V_35 ,
struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_22 * * V_68 )
{
struct V_30 V_31 = { 0 } ;
struct V_32 V_65 [ V_66 + 1 ] ;
int V_71 ;
memset ( & V_65 , 0 ,
( V_66 + 1 ) * sizeof( struct V_32 ) ) ;
F_16 ( V_2 , & V_31 ,
V_65 , V_34 , V_35 ) ;
V_71 = F_31 ( V_2 , V_9 , V_75 , V_76 ,
V_34 , V_35 , V_78 , & V_31 ,
V_80 , V_68 ) ;
if ( V_71 )
return V_71 ;
if ( F_61 ( V_2 ) && ( V_35 & V_111 ) ) {
if ( ! V_80 ) {
V_71 = F_62 ( & ( * V_68 ) -> V_20 . V_80 -> V_100 , NULL ) ;
F_46 ( V_71 != 0 ) ;
}
V_71 = F_58 ( V_2 , V_9 , V_75 , ( * V_68 ) ) ;
if ( ! V_80 )
F_50 ( & ( * V_68 ) -> V_20 . V_80 -> V_100 ) ;
if ( V_71 )
F_9 ( V_68 ) ;
}
return V_71 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
struct V_22 * V_23 ,
struct V_79 * V_80 ,
struct V_106 * * V_107 ,
bool V_114 )
{
struct V_22 * V_110 = V_23 -> V_110 ;
T_4 V_115 , V_116 ;
int V_71 ;
if ( ! V_110 )
return - V_117 ;
V_115 = F_64 ( V_23 ) ;
V_116 = F_64 ( V_23 -> V_110 ) ;
V_71 = F_65 ( V_23 -> V_20 . V_80 ) ;
if ( V_71 )
goto V_118;
V_71 = F_66 ( V_113 , V_115 , V_116 ,
F_67 ( V_23 ) , V_80 , V_107 ,
V_114 ) ;
if ( ! V_71 )
F_54 ( V_23 , * V_107 , true ) ;
V_118:
return V_71 ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
struct V_22 * V_23 ,
struct V_79 * V_80 ,
struct V_106 * * V_107 ,
bool V_114 )
{
struct V_22 * V_110 = V_23 -> V_110 ;
T_4 V_115 , V_116 ;
int V_71 ;
if ( ! V_110 )
return - V_117 ;
V_115 = F_64 ( V_23 ) ;
V_116 = F_64 ( V_23 -> V_110 ) ;
V_71 = F_65 ( V_23 -> V_20 . V_80 ) ;
if ( V_71 )
goto V_118;
V_71 = F_66 ( V_113 , V_116 , V_115 ,
F_67 ( V_23 ) , V_80 , V_107 ,
V_114 ) ;
if ( ! V_71 )
F_54 ( V_23 , * V_107 , true ) ;
V_118:
return V_71 ;
}
int F_25 ( struct V_22 * V_23 , void * * V_119 )
{
bool V_120 ;
long V_71 ;
if ( V_23 -> V_35 & V_121 )
return - V_122 ;
if ( V_23 -> V_123 ) {
if ( V_119 ) {
* V_119 = V_23 -> V_123 ;
}
return 0 ;
}
V_71 = F_69 ( V_23 -> V_20 . V_80 , false , false ,
V_124 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_70 ( & V_23 -> V_20 , 0 , V_23 -> V_20 . V_103 , & V_23 -> V_125 ) ;
if ( V_71 )
return V_71 ;
V_23 -> V_123 = F_71 ( & V_23 -> V_125 , & V_120 ) ;
if ( V_119 )
* V_119 = V_23 -> V_123 ;
return 0 ;
}
void F_29 ( struct V_22 * V_23 )
{
if ( V_23 -> V_123 == NULL )
return;
V_23 -> V_123 = NULL ;
F_72 ( & V_23 -> V_125 ) ;
}
struct V_22 * F_59 ( struct V_22 * V_23 )
{
if ( V_23 == NULL )
return NULL ;
F_73 ( & V_23 -> V_20 ) ;
return V_23 ;
}
void F_9 ( struct V_22 * * V_23 )
{
struct V_19 * V_20 ;
if ( ( * V_23 ) == NULL )
return;
V_20 = & ( ( * V_23 ) -> V_20 ) ;
F_74 ( & V_20 ) ;
if ( V_20 == NULL )
* V_23 = NULL ;
}
int F_75 ( struct V_22 * V_23 , T_2 V_34 ,
T_1 V_126 , T_1 V_127 ,
T_1 * V_69 )
{
struct V_1 * V_2 = F_6 ( V_23 -> V_20 . V_21 ) ;
int V_71 , V_128 ;
unsigned V_42 , V_39 ;
if ( F_76 ( V_23 -> V_20 . V_129 ) )
return - V_122 ;
if ( F_77 ( V_126 > V_127 ) )
return - V_117 ;
if ( V_23 -> V_130 ) {
T_5 V_13 = V_23 -> V_20 . V_4 . V_13 ;
if ( V_34 != F_78 ( V_13 ) )
return - V_117 ;
V_23 -> V_130 ++ ;
if ( V_69 )
* V_69 = F_64 ( V_23 ) ;
if ( V_127 != 0 ) {
T_1 V_131 = V_23 -> V_20 . V_21 -> V_132 [ V_13 ] . V_133 ;
F_77 ( V_127 <
( F_64 ( V_23 ) - V_131 ) ) ;
}
return 0 ;
}
V_23 -> V_35 |= V_40 ;
F_17 ( V_23 , V_34 ) ;
for ( V_128 = 0 ; V_128 < V_23 -> V_31 . V_61 ; V_128 ++ ) {
if ( ( V_23 -> V_65 [ V_128 ] . V_35 & V_45 ) &&
! ( V_23 -> V_35 & V_121 ) &&
( ! V_127 || V_127 >
V_2 -> V_7 . V_8 ) ) {
if ( F_77 ( V_126 >
V_2 -> V_7 . V_8 ) )
return - V_117 ;
V_42 = V_126 >> V_6 ;
V_39 = V_2 -> V_7 . V_8 >> V_6 ;
} else {
V_42 = V_126 >> V_6 ;
V_39 = V_127 >> V_6 ;
}
if ( V_42 > V_23 -> V_65 [ V_128 ] . V_42 )
V_23 -> V_65 [ V_128 ] . V_42 = V_42 ;
if ( ! V_23 -> V_65 [ V_128 ] . V_39 ||
( V_39 && V_39 < V_23 -> V_65 [ V_128 ] . V_39 ) )
V_23 -> V_65 [ V_128 ] . V_39 = V_39 ;
V_23 -> V_65 [ V_128 ] . V_35 |= V_134 ;
}
V_71 = F_79 ( & V_23 -> V_20 , & V_23 -> V_31 , false , false ) ;
if ( F_37 ( V_71 ) ) {
F_22 ( V_2 -> V_72 , L_7 , V_23 ) ;
goto error;
}
V_71 = F_80 ( & V_23 -> V_20 , & V_23 -> V_20 . V_4 ) ;
if ( F_37 ( V_71 ) ) {
F_22 ( V_2 -> V_72 , L_8 , V_23 ) ;
goto error;
}
V_23 -> V_130 = 1 ;
if ( V_69 != NULL )
* V_69 = F_64 ( V_23 ) ;
if ( V_34 == V_37 ) {
V_2 -> V_135 += F_67 ( V_23 ) ;
if ( V_23 -> V_35 & V_121 )
V_2 -> V_136 += F_67 ( V_23 ) ;
} else if ( V_34 == V_48 ) {
V_2 -> V_137 += F_67 ( V_23 ) ;
}
error:
return V_71 ;
}
int F_24 ( struct V_22 * V_23 , T_2 V_34 , T_1 * V_69 )
{
return F_75 ( V_23 , V_34 , 0 , 0 , V_69 ) ;
}
int F_30 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_6 ( V_23 -> V_20 . V_21 ) ;
int V_71 , V_128 ;
if ( ! V_23 -> V_130 ) {
F_81 ( V_2 -> V_72 , L_9 , V_23 ) ;
return 0 ;
}
V_23 -> V_130 -- ;
if ( V_23 -> V_130 )
return 0 ;
for ( V_128 = 0 ; V_128 < V_23 -> V_31 . V_61 ; V_128 ++ ) {
V_23 -> V_65 [ V_128 ] . V_39 = 0 ;
V_23 -> V_65 [ V_128 ] . V_35 &= ~ V_134 ;
}
V_71 = F_79 ( & V_23 -> V_20 , & V_23 -> V_31 , false , false ) ;
if ( F_37 ( V_71 ) ) {
F_22 ( V_2 -> V_72 , L_10 , V_23 ) ;
goto error;
}
if ( V_23 -> V_20 . V_4 . V_13 == V_16 ) {
V_2 -> V_135 -= F_67 ( V_23 ) ;
if ( V_23 -> V_35 & V_121 )
V_2 -> V_136 -= F_67 ( V_23 ) ;
} else if ( V_23 -> V_20 . V_4 . V_13 == V_14 ) {
V_2 -> V_137 -= F_67 ( V_23 ) ;
}
error:
return V_71 ;
}
int F_82 ( struct V_1 * V_2 )
{
if ( 0 && ( V_2 -> V_35 & V_138 ) ) {
return 0 ;
}
return F_83 ( & V_2 -> V_89 . V_21 , V_16 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
F_85 ( V_2 -> V_7 . V_139 ,
V_2 -> V_7 . V_140 ) ;
V_2 -> V_7 . V_141 = F_86 ( V_2 -> V_7 . V_139 ,
V_2 -> V_7 . V_140 ) ;
F_87 ( L_11 ,
V_2 -> V_7 . V_142 >> 20 ,
( unsigned long long ) V_2 -> V_7 . V_140 >> 20 ) ;
F_87 ( L_12 ,
V_2 -> V_7 . V_143 , V_144 [ V_2 -> V_7 . V_145 ] ) ;
return F_88 ( V_2 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
F_90 ( V_2 ) ;
F_91 ( V_2 -> V_7 . V_141 ) ;
F_92 ( V_2 -> V_7 . V_139 , V_2 -> V_7 . V_140 ) ;
}
int F_93 ( struct V_22 * V_23 ,
struct V_146 * V_147 )
{
return F_94 ( V_147 , & V_23 -> V_20 ) ;
}
int F_95 ( struct V_22 * V_23 , T_1 V_148 )
{
if ( F_96 ( V_148 , V_149 ) > 6 )
return - V_117 ;
V_23 -> V_148 = V_148 ;
return 0 ;
}
void F_97 ( struct V_22 * V_23 , T_1 * V_148 )
{
F_98 ( & V_23 -> V_20 . V_80 -> V_100 . V_150 ) ;
if ( V_148 )
* V_148 = V_23 -> V_148 ;
}
int F_99 ( struct V_22 * V_23 , void * V_28 ,
T_5 V_151 , T_4 V_35 )
{
void * V_152 ;
if ( ! V_151 ) {
if ( V_23 -> V_151 ) {
F_14 ( V_23 -> V_28 ) ;
V_23 -> V_28 = NULL ;
V_23 -> V_151 = 0 ;
}
return 0 ;
}
if ( V_28 == NULL )
return - V_117 ;
V_152 = F_100 ( V_28 , V_151 , V_90 ) ;
if ( V_152 == NULL )
return - V_91 ;
F_14 ( V_23 -> V_28 ) ;
V_23 -> V_153 = V_35 ;
V_23 -> V_28 = V_152 ;
V_23 -> V_151 = V_151 ;
return 0 ;
}
int F_101 ( struct V_22 * V_23 , void * V_152 ,
T_3 V_154 , T_5 * V_151 ,
T_4 * V_35 )
{
if ( ! V_152 && ! V_151 )
return - V_117 ;
if ( V_152 ) {
if ( V_154 < V_23 -> V_151 )
return - V_117 ;
if ( V_23 -> V_151 )
memcpy ( V_152 , V_23 -> V_28 , V_23 -> V_151 ) ;
}
if ( V_151 )
* V_151 = V_23 -> V_151 ;
if ( V_35 )
* V_35 = V_23 -> V_153 ;
return 0 ;
}
void F_102 ( struct V_19 * V_23 ,
bool V_155 ,
struct V_3 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_23 -> V_21 ) ;
struct V_22 * V_64 ;
struct V_3 * V_10 = & V_23 -> V_4 ;
if ( ! F_15 ( V_23 ) )
return;
V_64 = F_7 ( V_23 , struct V_22 , V_20 ) ;
F_103 ( V_2 , V_64 ) ;
if ( V_155 )
F_104 ( & V_2 -> V_156 ) ;
if ( ! V_11 )
return;
F_2 ( V_2 , & V_23 -> V_4 , V_11 ) ;
F_105 ( V_64 , V_11 -> V_13 , V_10 -> V_13 ) ;
}
int F_106 ( struct V_19 * V_23 )
{
struct V_1 * V_2 = F_6 ( V_23 -> V_21 ) ;
struct V_22 * V_64 ;
unsigned long V_157 , V_9 , V_39 ;
int V_128 , V_71 ;
if ( ! F_15 ( V_23 ) )
return 0 ;
V_64 = F_7 ( V_23 , struct V_22 , V_20 ) ;
if ( V_23 -> V_4 . V_13 != V_16 )
return 0 ;
V_9 = V_23 -> V_4 . V_103 << V_6 ;
V_157 = V_23 -> V_4 . V_5 << V_6 ;
if ( ( V_157 + V_9 ) <= V_2 -> V_7 . V_8 &&
( V_64 -> V_35 & V_40 ) )
return 0 ;
if ( V_64 -> V_130 > 0 )
return - V_117 ;
V_64 -> V_35 |= V_40 ;
F_17 ( V_64 , V_37 ) ;
V_39 = V_2 -> V_7 . V_8 >> V_6 ;
for ( V_128 = 0 ; V_128 < V_64 -> V_31 . V_61 ; V_128 ++ ) {
if ( ( V_64 -> V_65 [ V_128 ] . V_35 & V_45 ) &&
( ! V_64 -> V_65 [ V_128 ] . V_39 ||
V_64 -> V_65 [ V_128 ] . V_39 > V_39 ) )
V_64 -> V_65 [ V_128 ] . V_39 = V_39 ;
}
V_71 = F_79 ( V_23 , & V_64 -> V_31 , false , false ) ;
if ( F_37 ( V_71 == - V_91 ) ) {
F_17 ( V_64 , V_48 ) ;
return F_79 ( V_23 , & V_64 -> V_31 , false , false ) ;
} else if ( F_37 ( V_71 != 0 ) ) {
return V_71 ;
}
V_157 = V_23 -> V_4 . V_5 << V_6 ;
if ( ( V_157 + V_9 ) > V_2 -> V_7 . V_8 )
return - V_117 ;
return 0 ;
}
void F_54 ( struct V_22 * V_23 , struct V_106 * V_107 ,
bool V_158 )
{
struct V_79 * V_80 = V_23 -> V_20 . V_80 ;
if ( V_158 )
F_107 ( V_80 , V_107 ) ;
else
F_108 ( V_80 , V_107 ) ;
}
T_1 F_64 ( struct V_22 * V_23 )
{
F_77 ( V_23 -> V_20 . V_4 . V_13 == V_159 ) ;
F_77 ( V_23 -> V_20 . V_4 . V_13 == V_14 &&
! F_109 ( V_23 -> V_20 . V_129 ) ) ;
F_77 ( ! F_110 ( & V_23 -> V_20 . V_80 -> V_100 ) &&
! V_23 -> V_130 ) ;
F_77 ( V_23 -> V_20 . V_4 . V_5 == V_160 ) ;
F_77 ( V_23 -> V_20 . V_4 . V_13 == V_16 &&
! ( V_23 -> V_35 & V_40 ) ) ;
return V_23 -> V_20 . V_157 ;
}
