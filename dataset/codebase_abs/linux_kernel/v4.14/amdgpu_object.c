static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 ;
V_7 = F_3 ( V_2 , struct V_6 , V_2 ) ;
F_4 ( V_7 ) ;
F_5 ( & V_7 -> V_8 ) ;
F_6 ( & V_7 -> V_9 ) ;
if ( ! F_7 ( & V_7 -> V_10 ) ) {
F_8 ( & V_4 -> V_11 ) ;
F_9 ( & V_7 -> V_10 ) ;
F_10 ( & V_4 -> V_11 ) ;
}
F_11 ( V_7 -> V_12 ) ;
F_11 ( V_7 ) ;
}
bool F_12 ( struct V_1 * V_7 )
{
if ( V_7 -> V_13 == & F_1 )
return true ;
return false ;
}
static void F_13 ( struct V_3 * V_4 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
T_1 V_18 , T_2 V_19 )
{
T_1 V_20 = 0 ;
if ( V_18 & V_21 ) {
unsigned V_22 = V_4 -> V_23 . V_24 >> V_25 ;
V_17 [ V_20 ] . V_26 = 0 ;
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_28 | V_29 |
V_30 ;
if ( V_19 & V_31 )
V_17 [ V_20 ] . V_27 = V_22 ;
else
V_17 [ V_20 ] . V_19 |= V_32 ;
if ( V_19 & V_33 )
V_17 [ V_20 ] . V_19 |= V_34 ;
V_20 ++ ;
}
if ( V_18 & V_35 ) {
V_17 [ V_20 ] . V_26 = 0 ;
if ( V_19 & V_36 )
V_17 [ V_20 ] . V_27 = V_4 -> V_23 . V_37 >> V_25 ;
else
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_38 ;
if ( V_19 & V_39 )
V_17 [ V_20 ] . V_19 |= V_28 |
V_29 ;
else
V_17 [ V_20 ] . V_19 |= V_40 ;
V_20 ++ ;
}
if ( V_18 & V_41 ) {
V_17 [ V_20 ] . V_26 = 0 ;
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_42 ;
if ( V_19 & V_39 )
V_17 [ V_20 ] . V_19 |= V_28 |
V_29 ;
else
V_17 [ V_20 ] . V_19 |= V_40 ;
V_20 ++ ;
}
if ( V_18 & V_43 ) {
V_17 [ V_20 ] . V_26 = 0 ;
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_29 | V_44 ;
V_20 ++ ;
}
if ( V_18 & V_45 ) {
V_17 [ V_20 ] . V_26 = 0 ;
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_29 | V_46 ;
V_20 ++ ;
}
if ( V_18 & V_47 ) {
V_17 [ V_20 ] . V_26 = 0 ;
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_29 | V_48 ;
V_20 ++ ;
}
if ( ! V_20 ) {
V_17 [ V_20 ] . V_26 = 0 ;
V_17 [ V_20 ] . V_27 = 0 ;
V_17 [ V_20 ] . V_19 = V_49 | V_42 ;
V_20 ++ ;
}
V_15 -> V_50 = V_20 ;
V_15 -> V_15 = V_17 ;
V_15 -> V_51 = V_20 ;
V_15 -> V_52 = V_17 ;
}
void F_14 ( struct V_6 * V_53 , T_1 V_18 )
{
struct V_3 * V_4 = F_2 ( V_53 -> V_2 . V_5 ) ;
F_13 ( V_4 , & V_53 -> V_15 , V_53 -> V_54 ,
V_18 , V_53 -> V_19 ) ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_14 * V_15 )
{
F_16 ( V_15 -> V_50 > ( V_55 + 1 ) ) ;
memcpy ( V_7 -> V_54 , V_15 -> V_15 ,
V_15 -> V_50 * sizeof( struct V_16 ) ) ;
V_7 -> V_15 . V_50 = V_15 -> V_50 ;
V_7 -> V_15 . V_51 = V_15 -> V_51 ;
V_7 -> V_15 . V_15 = V_7 -> V_54 ;
V_7 -> V_15 . V_52 = V_7 -> V_54 ;
}
int F_17 ( struct V_3 * V_4 ,
unsigned long V_56 , int V_57 ,
T_1 V_18 , struct V_6 * * V_58 ,
T_2 * V_59 , void * * V_60 )
{
bool free = false ;
int V_61 ;
if ( ! * V_58 ) {
V_61 = F_18 ( V_4 , V_56 , V_57 , true , V_18 ,
V_31 |
V_33 ,
NULL , NULL , 0 , V_58 ) ;
if ( V_61 ) {
F_19 ( V_4 -> V_62 , L_1 ,
V_61 ) ;
return V_61 ;
}
free = true ;
}
V_61 = F_20 ( * V_58 , false ) ;
if ( V_61 ) {
F_19 ( V_4 -> V_62 , L_2 , V_61 ) ;
goto V_63;
}
V_61 = F_21 ( * V_58 , V_18 , V_59 ) ;
if ( V_61 ) {
F_19 ( V_4 -> V_62 , L_3 , V_61 ) ;
goto V_64;
}
if ( V_60 ) {
V_61 = F_22 ( * V_58 , V_60 ) ;
if ( V_61 ) {
F_19 ( V_4 -> V_62 , L_4 , V_61 ) ;
goto V_64;
}
}
return 0 ;
V_64:
F_23 ( * V_58 ) ;
V_63:
if ( free )
F_6 ( V_58 ) ;
return V_61 ;
}
int F_24 ( struct V_3 * V_4 ,
unsigned long V_56 , int V_57 ,
T_1 V_18 , struct V_6 * * V_58 ,
T_2 * V_59 , void * * V_60 )
{
int V_61 ;
V_61 = F_17 ( V_4 , V_56 , V_57 , V_18 , V_58 ,
V_59 , V_60 ) ;
if ( V_61 )
return V_61 ;
F_23 ( * V_58 ) ;
return 0 ;
}
void F_25 ( struct V_6 * * V_7 , T_2 * V_59 ,
void * * V_60 )
{
if ( * V_7 == NULL )
return;
if ( F_26 ( F_20 ( * V_7 , true ) == 0 ) ) {
if ( V_60 )
F_4 ( * V_7 ) ;
F_27 ( * V_7 ) ;
F_23 ( * V_7 ) ;
}
F_6 ( V_7 ) ;
if ( V_59 )
* V_59 = 0 ;
if ( V_60 )
* V_60 = NULL ;
}
int F_28 ( struct V_3 * V_4 ,
unsigned long V_56 , int V_65 ,
bool V_66 , T_1 V_18 , T_2 V_19 ,
struct V_67 * V_68 ,
struct V_14 * V_15 ,
struct V_69 * V_70 ,
T_3 V_71 ,
struct V_6 * * V_58 )
{
struct V_6 * V_7 ;
enum V_72 type ;
unsigned long V_73 ;
T_2 V_74 , V_75 ;
T_4 V_76 ;
int V_61 ;
V_73 = F_29 ( V_65 , V_77 ) >> V_25 ;
V_56 = F_30 ( V_56 , V_77 ) ;
if ( V_66 ) {
type = V_78 ;
} else if ( V_68 ) {
type = V_79 ;
} else {
type = V_80 ;
}
* V_58 = NULL ;
V_76 = F_31 ( & V_4 -> V_81 . V_5 , V_56 ,
sizeof( struct V_6 ) ) ;
V_7 = F_32 ( sizeof( struct V_6 ) , V_82 ) ;
if ( V_7 == NULL )
return - V_83 ;
V_61 = F_33 ( V_4 -> V_84 , & V_7 -> V_8 , V_56 ) ;
if ( F_34 ( V_61 ) ) {
F_11 ( V_7 ) ;
return V_61 ;
}
F_35 ( & V_7 -> V_10 ) ;
F_35 ( & V_7 -> V_85 ) ;
V_7 -> V_86 = V_18 & ( V_21 |
V_35 |
V_41 |
V_43 |
V_45 |
V_47 ) ;
V_7 -> V_87 = V_7 -> V_86 ;
if ( ! V_66 && V_7 -> V_87 == V_21 )
V_7 -> V_87 |= V_35 ;
V_7 -> V_19 = V_19 ;
#ifdef F_36
V_7 -> V_19 &= ~ V_39 ;
#elif F_37 ( V_88 ) && ! F_37 ( V_89 )
#ifndef F_38
#warning Please enable CONFIG_MTRR and CONFIG_X86_PAT for better performance \
thanks to write-combining
#endif
if ( V_7 -> V_19 & V_39 )
F_39 ( L_5
L_6 ) ;
V_7 -> V_19 &= ~ V_39 ;
#else
if ( ! F_40 () )
V_7 -> V_19 &= ~ V_39 ;
#endif
F_15 ( V_7 , V_15 ) ;
V_74 = F_41 ( & V_4 -> V_90 ) ;
V_61 = F_42 ( & V_4 -> V_81 . V_5 , & V_7 -> V_2 , V_56 , type ,
& V_7 -> V_15 , V_73 , ! V_66 , NULL ,
V_76 , V_68 , V_70 , & F_1 ) ;
V_75 = F_41 ( & V_4 -> V_90 ) -
V_74 ;
if ( V_4 -> V_23 . V_24 < V_4 -> V_23 . V_91 &&
V_7 -> V_2 . V_92 . V_93 == V_94 &&
V_7 -> V_2 . V_92 . V_95 < V_4 -> V_23 . V_24 >> V_25 )
F_43 ( V_4 , V_75 , V_75 ) ;
else
F_43 ( V_4 , V_75 , 0 ) ;
if ( F_34 ( V_61 != 0 ) )
return V_61 ;
if ( V_66 )
V_7 -> V_2 . V_96 = 1 ;
if ( V_19 & V_97 &&
V_7 -> V_2 . V_92 . V_15 & V_30 ) {
struct V_98 * V_99 ;
V_61 = F_44 ( V_7 , V_71 , V_7 -> V_2 . V_70 , & V_99 ) ;
if ( F_34 ( V_61 ) )
goto V_100;
F_45 ( V_7 , V_99 , false ) ;
F_46 ( V_7 -> V_2 . V_101 ) ;
V_7 -> V_2 . V_101 = F_47 ( V_99 ) ;
F_46 ( V_99 ) ;
}
if ( ! V_70 )
F_23 ( V_7 ) ;
* V_58 = V_7 ;
F_48 ( V_7 ) ;
if ( type == V_80 )
V_7 -> V_19 &= ~ V_31 ;
return 0 ;
V_100:
if ( ! V_70 )
F_49 ( & V_7 -> V_2 . V_70 -> V_102 ) ;
F_6 ( & V_7 ) ;
return V_61 ;
}
static int F_50 ( struct V_3 * V_4 ,
unsigned long V_56 , int V_65 ,
struct V_6 * V_7 )
{
struct V_14 V_15 = { 0 } ;
struct V_16 V_54 [ V_55 + 1 ] ;
int V_61 ;
if ( V_7 -> V_103 )
return 0 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_13 ( V_4 , & V_15 , V_54 ,
V_35 ,
V_39 |
V_36 ) ;
V_61 = F_28 ( V_4 , V_56 , V_65 , true ,
V_35 ,
V_39 |
V_36 ,
NULL , & V_15 ,
V_7 -> V_2 . V_70 ,
0 ,
& V_7 -> V_103 ) ;
if ( ! V_61 ) {
V_7 -> V_103 -> V_9 = F_51 ( V_7 ) ;
F_8 ( & V_4 -> V_11 ) ;
F_52 ( & V_7 -> V_10 , & V_4 -> V_10 ) ;
F_10 ( & V_4 -> V_11 ) ;
}
return V_61 ;
}
int F_18 ( struct V_3 * V_4 ,
unsigned long V_56 , int V_65 ,
bool V_66 , T_1 V_18 , T_2 V_19 ,
struct V_67 * V_68 ,
struct V_69 * V_70 ,
T_3 V_71 ,
struct V_6 * * V_58 )
{
struct V_14 V_15 = { 0 } ;
struct V_16 V_54 [ V_55 + 1 ] ;
T_3 V_104 = V_19 & ~ V_36 ;
int V_61 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_13 ( V_4 , & V_15 , V_54 ,
V_18 , V_104 ) ;
V_61 = F_28 ( V_4 , V_56 , V_65 , V_66 , V_18 ,
V_104 , V_68 , & V_15 , V_70 ,
V_71 , V_58 ) ;
if ( V_61 )
return V_61 ;
if ( ( V_19 & V_36 ) && F_53 ( V_4 ) ) {
if ( ! V_70 )
F_54 ( F_55 ( ( * V_58 ) -> V_2 . V_70 ,
NULL ) ) ;
V_61 = F_50 ( V_4 , V_56 , V_65 , ( * V_58 ) ) ;
if ( ! V_70 )
F_56 ( ( * V_58 ) -> V_2 . V_70 ) ;
if ( V_61 )
F_6 ( V_58 ) ;
}
return V_61 ;
}
int F_57 ( struct V_3 * V_4 ,
struct V_105 * V_106 ,
struct V_6 * V_7 ,
struct V_69 * V_70 ,
struct V_98 * * V_99 ,
bool V_107 )
{
struct V_6 * V_103 = V_7 -> V_103 ;
T_3 V_108 , V_109 ;
int V_61 ;
if ( ! V_103 )
return - V_110 ;
V_108 = F_58 ( V_7 ) ;
V_109 = F_58 ( V_7 -> V_103 ) ;
V_61 = F_59 ( V_7 -> V_2 . V_70 ) ;
if ( V_61 )
goto V_111;
V_61 = F_60 ( V_106 , V_108 , V_109 ,
F_61 ( V_7 ) , V_70 , V_99 ,
V_107 , false ) ;
if ( ! V_61 )
F_45 ( V_7 , * V_99 , true ) ;
V_111:
return V_61 ;
}
int F_62 ( struct V_6 * V_7 )
{
T_5 V_18 ;
int V_61 ;
if ( V_7 -> V_112 )
return 0 ;
V_18 = V_7 -> V_86 ;
V_113:
F_14 ( V_7 , V_18 ) ;
V_61 = F_63 ( & V_7 -> V_2 , & V_7 -> V_15 , false , false ) ;
if ( F_34 ( V_61 == - V_83 ) && V_18 != V_7 -> V_87 ) {
V_18 = V_7 -> V_87 ;
goto V_113;
}
return V_61 ;
}
int F_64 ( struct V_3 * V_4 ,
struct V_105 * V_106 ,
struct V_6 * V_7 ,
struct V_69 * V_70 ,
struct V_98 * * V_99 ,
bool V_107 )
{
struct V_6 * V_103 = V_7 -> V_103 ;
T_3 V_108 , V_109 ;
int V_61 ;
if ( ! V_103 )
return - V_110 ;
V_108 = F_58 ( V_7 ) ;
V_109 = F_58 ( V_7 -> V_103 ) ;
V_61 = F_59 ( V_7 -> V_2 . V_70 ) ;
if ( V_61 )
goto V_111;
V_61 = F_60 ( V_106 , V_109 , V_108 ,
F_61 ( V_7 ) , V_70 , V_99 ,
V_107 , false ) ;
if ( ! V_61 )
F_45 ( V_7 , * V_99 , true ) ;
V_111:
return V_61 ;
}
int F_22 ( struct V_6 * V_7 , void * * V_114 )
{
void * V_115 ;
long V_61 ;
if ( V_7 -> V_19 & V_116 )
return - V_117 ;
V_115 = F_65 ( V_7 ) ;
if ( V_115 ) {
if ( V_114 )
* V_114 = V_115 ;
return 0 ;
}
V_61 = F_66 ( V_7 -> V_2 . V_70 , false , false ,
V_118 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_67 ( & V_7 -> V_2 , 0 , V_7 -> V_2 . V_119 , & V_7 -> V_120 ) ;
if ( V_61 )
return V_61 ;
if ( V_114 )
* V_114 = F_65 ( V_7 ) ;
return 0 ;
}
void * F_65 ( struct V_6 * V_7 )
{
bool V_121 ;
return F_68 ( & V_7 -> V_120 , & V_121 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
if ( V_7 -> V_120 . V_7 )
F_69 ( & V_7 -> V_120 ) ;
}
struct V_6 * F_51 ( struct V_6 * V_7 )
{
if ( V_7 == NULL )
return NULL ;
F_70 ( & V_7 -> V_2 ) ;
return V_7 ;
}
void F_6 ( struct V_6 * * V_7 )
{
struct V_1 * V_2 ;
if ( ( * V_7 ) == NULL )
return;
V_2 = & ( ( * V_7 ) -> V_2 ) ;
F_71 ( & V_2 ) ;
if ( V_2 == NULL )
* V_7 = NULL ;
}
int F_72 ( struct V_6 * V_7 , T_1 V_18 ,
T_2 V_122 , T_2 V_123 ,
T_2 * V_59 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_2 . V_5 ) ;
int V_61 , V_124 ;
unsigned V_26 , V_27 ;
if ( F_73 ( V_7 -> V_2 . V_125 ) )
return - V_117 ;
if ( F_74 ( V_122 > V_123 ) )
return - V_110 ;
if ( V_7 -> V_126 && ( V_18 == V_21 ) )
return - V_110 ;
if ( V_7 -> V_112 ) {
T_5 V_93 = V_7 -> V_2 . V_92 . V_93 ;
if ( V_18 != F_75 ( V_93 ) )
return - V_110 ;
V_7 -> V_112 ++ ;
if ( V_59 )
* V_59 = F_58 ( V_7 ) ;
if ( V_123 != 0 ) {
T_2 V_127 = V_7 -> V_2 . V_5 -> V_128 [ V_93 ] . V_129 ;
F_74 ( V_123 <
( F_58 ( V_7 ) - V_127 ) ) ;
}
return 0 ;
}
V_7 -> V_19 |= V_33 ;
F_14 ( V_7 , V_18 ) ;
for ( V_124 = 0 ; V_124 < V_7 -> V_15 . V_50 ; V_124 ++ ) {
if ( ( V_7 -> V_54 [ V_124 ] . V_19 & V_30 ) &&
! ( V_7 -> V_19 & V_116 ) &&
( ! V_123 || V_123 >
V_4 -> V_23 . V_24 ) ) {
if ( F_74 ( V_122 >
V_4 -> V_23 . V_24 ) )
return - V_110 ;
V_26 = V_122 >> V_25 ;
V_27 = V_4 -> V_23 . V_24 >> V_25 ;
} else {
V_26 = V_122 >> V_25 ;
V_27 = V_123 >> V_25 ;
}
if ( V_26 > V_7 -> V_54 [ V_124 ] . V_26 )
V_7 -> V_54 [ V_124 ] . V_26 = V_26 ;
if ( ! V_7 -> V_54 [ V_124 ] . V_27 ||
( V_27 && V_27 < V_7 -> V_54 [ V_124 ] . V_27 ) )
V_7 -> V_54 [ V_124 ] . V_27 = V_27 ;
V_7 -> V_54 [ V_124 ] . V_19 |= V_130 ;
}
V_61 = F_63 ( & V_7 -> V_2 , & V_7 -> V_15 , false , false ) ;
if ( F_34 ( V_61 ) ) {
F_19 ( V_4 -> V_62 , L_7 , V_7 ) ;
goto error;
}
V_7 -> V_112 = 1 ;
if ( V_59 != NULL ) {
V_61 = F_76 ( & V_7 -> V_2 , & V_7 -> V_2 . V_92 ) ;
if ( F_34 ( V_61 ) ) {
F_19 ( V_4 -> V_62 , L_8 , V_7 ) ;
goto error;
}
* V_59 = F_58 ( V_7 ) ;
}
if ( V_18 == V_21 ) {
V_4 -> V_131 += F_61 ( V_7 ) ;
if ( V_7 -> V_19 & V_116 )
V_4 -> V_132 += F_61 ( V_7 ) ;
} else if ( V_18 == V_35 ) {
V_4 -> V_133 += F_61 ( V_7 ) ;
}
error:
return V_61 ;
}
int F_21 ( struct V_6 * V_7 , T_1 V_18 , T_2 * V_59 )
{
return F_72 ( V_7 , V_18 , 0 , 0 , V_59 ) ;
}
int F_27 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_2 . V_5 ) ;
int V_61 , V_124 ;
if ( ! V_7 -> V_112 ) {
F_77 ( V_4 -> V_62 , L_9 , V_7 ) ;
return 0 ;
}
V_7 -> V_112 -- ;
if ( V_7 -> V_112 )
return 0 ;
for ( V_124 = 0 ; V_124 < V_7 -> V_15 . V_50 ; V_124 ++ ) {
V_7 -> V_54 [ V_124 ] . V_27 = 0 ;
V_7 -> V_54 [ V_124 ] . V_19 &= ~ V_130 ;
}
V_61 = F_63 ( & V_7 -> V_2 , & V_7 -> V_15 , false , false ) ;
if ( F_34 ( V_61 ) ) {
F_19 ( V_4 -> V_62 , L_10 , V_7 ) ;
goto error;
}
if ( V_7 -> V_2 . V_92 . V_93 == V_94 ) {
V_4 -> V_131 -= F_61 ( V_7 ) ;
if ( V_7 -> V_19 & V_116 )
V_4 -> V_132 -= F_61 ( V_7 ) ;
} else if ( V_7 -> V_2 . V_92 . V_93 == V_134 ) {
V_4 -> V_133 -= F_61 ( V_7 ) ;
}
error:
return V_61 ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( 0 && ( V_4 -> V_19 & V_135 ) ) {
return 0 ;
}
return F_79 ( & V_4 -> V_81 . V_5 , V_94 ) ;
}
int F_80 ( struct V_3 * V_4 )
{
F_81 ( V_4 -> V_23 . V_136 ,
V_4 -> V_23 . V_137 ) ;
V_4 -> V_23 . V_138 = F_82 ( V_4 -> V_23 . V_136 ,
V_4 -> V_23 . V_137 ) ;
F_83 ( L_11 ,
V_4 -> V_23 . V_139 >> 20 ,
( unsigned long long ) V_4 -> V_23 . V_137 >> 20 ) ;
F_83 ( L_12 ,
V_4 -> V_23 . V_140 , V_141 [ V_4 -> V_23 . V_142 ] ) ;
return F_84 ( V_4 ) ;
}
void F_85 ( struct V_3 * V_4 )
{
F_86 ( V_4 ) ;
F_87 ( V_4 -> V_23 . V_138 ) ;
F_88 ( V_4 -> V_23 . V_136 , V_4 -> V_23 . V_137 ) ;
}
int F_89 ( struct V_6 * V_7 ,
struct V_143 * V_144 )
{
return F_90 ( V_144 , & V_7 -> V_2 ) ;
}
int F_91 ( struct V_6 * V_7 , T_2 V_145 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_2 . V_5 ) ;
if ( V_4 -> V_146 <= V_147 &&
F_92 ( V_145 , V_148 ) > 6 )
return - V_110 ;
V_7 -> V_145 = V_145 ;
return 0 ;
}
void F_93 ( struct V_6 * V_7 , T_2 * V_145 )
{
F_94 ( & V_7 -> V_2 . V_70 -> V_102 . V_149 ) ;
if ( V_145 )
* V_145 = V_7 -> V_145 ;
}
int F_95 ( struct V_6 * V_7 , void * V_12 ,
T_5 V_150 , T_3 V_19 )
{
void * V_151 ;
if ( ! V_150 ) {
if ( V_7 -> V_150 ) {
F_11 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
V_7 -> V_150 = 0 ;
}
return 0 ;
}
if ( V_12 == NULL )
return - V_110 ;
V_151 = F_96 ( V_12 , V_150 , V_82 ) ;
if ( V_151 == NULL )
return - V_83 ;
F_11 ( V_7 -> V_12 ) ;
V_7 -> V_152 = V_19 ;
V_7 -> V_12 = V_151 ;
V_7 -> V_150 = V_150 ;
return 0 ;
}
int F_97 ( struct V_6 * V_7 , void * V_151 ,
T_4 V_153 , T_5 * V_150 ,
T_3 * V_19 )
{
if ( ! V_151 && ! V_150 )
return - V_110 ;
if ( V_151 ) {
if ( V_153 < V_7 -> V_150 )
return - V_110 ;
if ( V_7 -> V_150 )
memcpy ( V_151 , V_7 -> V_12 , V_7 -> V_150 ) ;
}
if ( V_150 )
* V_150 = V_7 -> V_150 ;
if ( V_19 )
* V_19 = V_7 -> V_152 ;
return 0 ;
}
void F_98 ( struct V_1 * V_7 ,
bool V_154 ,
struct V_155 * V_156 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_5 ) ;
struct V_6 * V_53 ;
struct V_155 * V_157 = & V_7 -> V_92 ;
if ( ! F_12 ( V_7 ) )
return;
V_53 = F_3 ( V_7 , struct V_6 , V_2 ) ;
F_99 ( V_4 , V_53 ) ;
F_4 ( V_53 ) ;
if ( V_154 )
F_100 ( & V_4 -> V_158 ) ;
if ( ! V_156 )
return;
F_101 ( V_53 , V_156 -> V_93 , V_157 -> V_93 ) ;
}
int F_102 ( struct V_1 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_5 ) ;
struct V_6 * V_53 ;
unsigned long V_159 , V_56 ;
int V_61 ;
if ( ! F_12 ( V_7 ) )
return 0 ;
V_53 = F_3 ( V_7 , struct V_6 , V_2 ) ;
V_53 -> V_19 |= V_31 ;
if ( V_7 -> V_92 . V_93 != V_94 )
return 0 ;
V_56 = V_7 -> V_92 . V_119 << V_25 ;
V_159 = V_7 -> V_92 . V_95 << V_25 ;
if ( ( V_159 + V_56 ) <= V_4 -> V_23 . V_24 )
return 0 ;
if ( V_53 -> V_112 > 0 )
return - V_110 ;
F_100 ( & V_4 -> V_160 ) ;
F_14 ( V_53 , V_21 |
V_35 ) ;
V_53 -> V_15 . V_51 = 1 ;
V_53 -> V_15 . V_52 = & V_53 -> V_54 [ 1 ] ;
V_61 = F_63 ( V_7 , & V_53 -> V_15 , false , false ) ;
if ( F_34 ( V_61 != 0 ) )
return V_61 ;
V_159 = V_7 -> V_92 . V_95 << V_25 ;
if ( V_7 -> V_92 . V_93 == V_94 &&
( V_159 + V_56 ) > V_4 -> V_23 . V_24 )
return - V_110 ;
return 0 ;
}
void F_45 ( struct V_6 * V_7 , struct V_98 * V_99 ,
bool V_161 )
{
struct V_69 * V_70 = V_7 -> V_2 . V_70 ;
if ( V_161 )
F_103 ( V_70 , V_99 ) ;
else
F_104 ( V_70 , V_99 ) ;
}
T_2 F_58 ( struct V_6 * V_7 )
{
F_74 ( V_7 -> V_2 . V_92 . V_93 == V_162 ) ;
F_74 ( V_7 -> V_2 . V_92 . V_93 == V_134 &&
! F_105 ( V_7 -> V_2 . V_125 ) ) ;
F_74 ( ! F_106 ( & V_7 -> V_2 . V_70 -> V_102 ) &&
! V_7 -> V_112 ) ;
F_74 ( V_7 -> V_2 . V_92 . V_95 == V_163 ) ;
F_74 ( V_7 -> V_2 . V_92 . V_93 == V_94 &&
! ( V_7 -> V_19 & V_33 ) ) ;
return V_7 -> V_2 . V_159 ;
}
