static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 , int V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 ;
F_2 ( V_2 , L_1 , F_3 ( V_3 ) ,
V_3 -> V_9 , V_3 -> V_9 == 1 ? L_2 : L_3 ) ;
for ( V_7 = 0 ; V_7 < ( 1 << V_6 -> V_10 ) ; V_7 ++ ) {
struct V_11 * V_12 = & V_3 -> V_13 [ V_7 ] ;
unsigned long V_14 = F_4 ( V_12 -> V_15 ) ;
void T_1 * V_16 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
struct V_11 * V_17 = & V_3 -> V_13 [ V_8 ] ;
unsigned long V_18 = F_4 ( V_17 -> V_15 ) ;
if ( V_14 == V_18 )
break;
}
if ( V_8 < V_7 )
V_16 = ( void T_1 * ) ( ( unsigned long )
F_5 ( V_6 , V_4 , V_8 )
& V_19 ) ;
else
V_16 = F_6 ( V_2 ,
F_7 ( V_14 ) , V_20 ) ;
if ( ! V_16 )
return - V_21 ;
F_8 ( V_6 , V_4 , V_7 , V_16
+ ( V_12 -> V_15 & ~ V_19 ) ) ;
}
return 0 ;
}
int F_9 ( struct V_22 * V_22 )
{
int V_7 , V_8 , V_9 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = & V_22 -> V_2 ;
T_2 V_23 = sizeof( void * ) ;
F_10 ( & V_22 -> V_2 ) ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
V_23 += sizeof( void * ) ;
V_9 = F_11 ( V_9 , V_3 -> V_9 ) ;
if ( ! V_3 -> V_9 )
continue;
V_23 += V_3 -> V_9 * sizeof( void * ) ;
}
F_12 ( & V_22 -> V_2 ) ;
V_6 = F_13 ( V_2 , sizeof( * V_6 ) + V_23 , V_27 ) ;
if ( ! V_6 )
return - V_28 ;
F_14 ( V_2 , V_6 ) ;
if ( ! V_9 )
return 0 ;
V_6 -> V_10 = F_15 ( V_9 ) ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
int V_29 = F_1 ( & V_22 -> V_2 , V_3 , V_7 , V_6 ) ;
if ( V_29 )
return V_29 ;
}
for ( V_7 = 0 ; V_7 < V_22 -> V_24 - 1 ; V_7 ++ ) {
if ( ! F_5 ( V_6 , V_7 , 0 ) )
continue;
for ( V_8 = V_7 + 1 ; V_8 < V_22 -> V_24 ; V_8 ++ )
if ( F_5 ( V_6 , V_7 , 0 ) ==
F_5 ( V_6 , V_8 , 0 ) )
F_8 ( V_6 , V_8 , 0 , NULL ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_3 V_7 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
F_18 ( & V_3 -> V_2 ) ;
}
F_19 ( V_22 -> V_30 ) ;
F_20 ( & V_31 , V_22 -> V_32 ) ;
if ( F_21 ( V_2 ) )
F_22 ( F_23 ( V_2 ) ) ;
else
F_22 ( V_22 ) ;
}
bool F_24 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_33 : false ;
}
bool F_21 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_34 : false ;
}
bool F_25 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_35 : false ;
}
struct V_22 * F_17 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_26 ( V_2 , struct V_22 , V_2 ) ;
F_27 ( V_2 -> type -> V_36 != F_16 ) ;
return V_22 ;
}
struct V_37 * F_23 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
F_27 ( ! F_21 ( V_2 ) ) ;
return F_26 ( V_22 , struct V_37 , V_22 ) ;
}
void * F_28 ( struct V_22 * V_22 )
{
return V_22 -> V_38 ;
}
void * F_29 ( struct V_37 * V_39 )
{
return V_39 -> V_40 ;
}
void F_30 ( struct V_37 * V_39 , void * V_41 )
{
V_39 -> V_40 = V_41 ;
}
int F_31 ( struct V_22 * V_22 )
{
if ( F_32 ( & V_22 -> V_2 ) ) {
T_3 V_7 , V_42 ;
for ( V_7 = 0 , V_42 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
if ( F_33 ( V_43 , & V_3 -> V_44 ) )
V_42 ++ ;
}
if ( V_42 )
return V_45 ;
else
return V_46 ;
} else if ( F_21 ( & V_22 -> V_2 ) ) {
return V_47 ;
}
return 0 ;
}
static T_4 F_34 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
unsigned long long V_51 = 0 ;
if ( F_32 ( V_2 ) ) {
V_51 = V_22 -> V_52 ;
} else if ( V_22 -> V_24 == 1 ) {
struct V_25 * V_25 = & V_22 -> V_26 [ 0 ] ;
V_51 = V_25 -> V_51 ;
}
return sprintf ( V_50 , L_4 , V_51 ) ;
}
static T_4 F_35 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_50 , L_5 , F_36 ( V_22 ) ) ;
}
static T_4 F_37 ( struct V_1 * V_2 , struct V_48 * V_49 ,
const char * V_50 , T_2 V_53 )
{
bool V_54 ;
int V_29 = F_38 ( V_50 , & V_54 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_29 )
return V_29 ;
if ( ! V_54 )
return - V_55 ;
F_39 ( V_22 ) ;
return V_53 ;
}
static T_4 F_40 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_50 , L_5 , V_22 -> V_24 ) ;
}
static T_4 F_41 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_50 , L_5 , F_31 ( V_22 ) ) ;
}
static T_4 F_42 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_56 * V_57 = V_22 -> V_57 ;
T_4 V_29 = 0 ;
if ( F_32 ( V_2 ) && V_57 )
;
else
return - V_21 ;
F_43 ( V_2 ) ;
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_22 -> V_24 ) {
struct V_25 * V_25 = & V_22 -> V_26 [ 0 ] ;
struct V_58 * V_59 = F_45 ( V_25 ) ;
if ( V_59 ) {
struct V_60 * V_61 ;
V_61 = F_46 ( V_59 , V_59 -> V_62 ) ;
V_29 = sprintf ( V_50 , L_6 ,
F_47 ( V_22 ,
V_61 ) ) ;
}
}
F_12 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( V_29 )
return V_29 ;
return sprintf ( V_50 , L_6 , V_57 -> V_63 ) ;
}
T_5 F_49 ( struct V_22 * V_22 )
{
T_5 V_64 = 0 , V_65 , V_66 ;
int V_7 ;
F_27 ( ! F_50 ( & V_22 -> V_2 ) ) ;
V_67:
V_65 = 0 ;
V_66 = V_64 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_58 * V_59 = F_45 ( V_25 ) ;
if ( ! V_59 )
return 0 ;
if ( F_32 ( & V_22 -> V_2 ) ) {
V_65 += F_51 ( V_22 ,
V_25 , & V_66 ) ;
if ( V_66 > V_64 ) {
V_64 = V_66 ;
goto V_67;
}
} else if ( F_21 ( & V_22 -> V_2 ) )
V_65 += F_52 ( V_22 ) ;
}
return V_65 ;
}
static T_4 F_53 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
unsigned long long V_65 = 0 ;
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_65 = F_49 ( V_22 ) ;
F_12 ( V_2 ) ;
return sprintf ( V_50 , L_4 , V_65 ) ;
}
static T_4 F_54 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_5 * V_6 = F_55 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_6 )
V_29 = sprintf ( V_50 , L_7 , V_6 -> V_68 , V_6 -> V_69 ) ;
else
V_29 = - V_21 ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_56 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_70 )
V_29 = sprintf ( V_50 , L_8 , F_57 ( V_22 -> V_70 ) ) ;
else
V_29 = sprintf ( V_50 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_58 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_71 )
V_29 = sprintf ( V_50 , L_8 , F_57 ( V_22 -> V_71 ) ) ;
else
V_29 = sprintf ( V_50 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_59 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_72 )
V_29 = sprintf ( V_50 , L_8 , F_57 ( V_22 -> V_72 ) ) ;
else
V_29 = sprintf ( V_50 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_60 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_73 )
V_29 = sprintf ( V_50 , L_8 , F_57 ( V_22 -> V_73 ) ) ;
else
V_29 = sprintf ( V_50 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_61 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_50 , L_5 , V_22 -> V_74 ) ;
}
static T_4 F_62 ( struct V_1 * V_2 ,
struct V_48 * V_49 , const char * V_50 , T_2 V_53 )
{
bool V_74 ;
int V_29 = F_38 ( V_50 , & V_74 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_22 -> V_74 = V_74 ;
return V_53 ;
}
static T_4 F_63 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return F_64 ( & V_22 -> V_75 , V_50 , 0 ) ;
}
static T_4 F_65 ( struct V_1 * V_2 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_50 , L_6 , V_22 -> V_76 ) ;
}
static T_6 F_66 ( struct V_77 * V_78 , struct V_79 * V_80 , int V_81 )
{
struct V_1 * V_2 = F_26 ( V_78 , F_67 ( * V_2 ) , V_78 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_56 * V_57 = V_22 -> V_57 ;
int type = F_31 ( V_22 ) ;
if ( ! F_32 ( V_2 ) && V_80 == & V_82 . V_49 )
return 0 ;
if ( ! F_32 ( V_2 ) && V_80 == & V_83 . V_49 )
return 0 ;
if ( ! F_24 ( V_2 ) && V_80 == & V_84 . V_49 )
return 0 ;
if ( ! F_24 ( V_2 ) && V_80 == & V_85 . V_49 )
return 0 ;
if ( V_80 == & V_86 . V_49 ) {
int V_87 = F_36 ( V_22 ) ;
if ( V_87 == 1 )
return V_80 -> V_88 ;
else if ( V_87 == 0 )
return 0444 ;
else
return 0 ;
}
if ( V_80 != & V_89 . V_49
&& V_80 != & V_90 . V_49 )
return V_80 -> V_88 ;
if ( ( type == V_45
|| type == V_47 )
&& V_80 == & V_90 . V_49 )
return V_80 -> V_88 ;
else if ( F_32 ( V_2 ) && V_57 )
return V_80 -> V_88 ;
return 0 ;
}
T_7 F_47 ( struct V_22 * V_22 ,
struct V_60 * V_61 )
{
struct V_56 * V_57 = V_22 -> V_57 ;
if ( ! V_57 )
return 0 ;
if ( V_61 && F_68 ( V_61 -> V_91 ) == 1
&& F_68 ( V_61 -> V_92 ) == 1 )
return V_57 -> V_63 ;
return V_57 -> V_93 ;
}
T_7 F_69 ( struct V_22 * V_22 )
{
struct V_56 * V_57 = V_22 -> V_57 ;
if ( V_57 )
return V_57 -> V_94 ;
return 0 ;
}
void F_70 ( struct V_25 * V_25 )
{
struct V_95 * V_96 , * V_97 ;
F_71 ( & V_25 -> V_98 ) ;
F_72 (label_ent, e, &nd_mapping->labels, list) {
F_73 ( & V_96 -> V_99 ) ;
F_22 ( V_96 ) ;
}
}
static void F_74 ( struct V_100 * V_100 ,
struct V_1 * V_2 , bool V_101 )
{
struct V_22 * V_22 ;
if ( ! V_101 && F_75 ( V_2 ) ) {
int V_7 ;
V_22 = F_17 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_58 * V_59 = V_25 -> V_59 ;
struct V_3 * V_3 = V_25 -> V_3 ;
F_76 ( & V_25 -> V_98 ) ;
F_70 ( V_25 ) ;
F_77 ( & V_25 -> V_98 ) ;
F_78 ( V_59 ) ;
V_25 -> V_59 = NULL ;
if ( V_59 )
F_79 ( & V_3 -> V_102 ) ;
}
}
if ( V_2 -> V_103 && F_75 ( V_2 -> V_103 ) && V_101 ) {
V_22 = F_17 ( V_2 -> V_103 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_70 == V_2 )
F_80 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_81 ( V_2 ) && V_101 ) {
struct V_104 * V_104 = F_82 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_103 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_71 == V_2 )
F_83 ( V_22 ) ;
if ( V_22 -> V_70 == & V_104 -> V_105 -> V_2 )
F_80 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_84 ( V_2 ) && V_101 ) {
struct V_106 * V_106 = F_85 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_103 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_72 == V_2 )
F_86 ( V_22 ) ;
if ( V_22 -> V_70 == & V_106 -> V_105 -> V_2 )
F_80 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_87 ( V_2 ) && V_101 ) {
struct V_107 * V_107 = F_88 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_103 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_73 == V_2 )
F_89 ( V_22 ) ;
if ( V_22 -> V_70 == & V_107 -> V_106 . V_105 -> V_2 )
F_80 ( V_22 ) ;
F_12 ( V_2 ) ;
}
}
void F_90 ( struct V_100 * V_100 , struct V_1 * V_2 )
{
F_74 ( V_100 , V_2 , true ) ;
}
void F_91 ( struct V_100 * V_100 , struct V_1 * V_2 )
{
F_74 ( V_100 , V_2 , false ) ;
}
static T_4 F_92 ( struct V_1 * V_2 , char * V_50 , int V_81 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_25 * V_25 ;
struct V_3 * V_3 ;
if ( V_81 >= V_22 -> V_24 )
return - V_21 ;
V_25 = & V_22 -> V_26 [ V_81 ] ;
V_3 = V_25 -> V_3 ;
return sprintf ( V_50 , L_10 , F_57 ( & V_3 -> V_2 ) ,
V_25 -> V_15 , V_25 -> V_51 ,
V_25 -> V_108 ) ;
}
static T_6 F_93 ( struct V_77 * V_78 , struct V_79 * V_80 , int V_81 )
{
struct V_1 * V_2 = F_26 ( V_78 , struct V_1 , V_78 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_81 < V_22 -> V_24 )
return V_80 -> V_88 ;
return 0 ;
}
int F_94 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = & V_22 -> V_2 ;
struct V_100 * V_100 = F_95 ( V_2 ) ;
if ( ! F_21 ( V_2 ) )
return 0 ;
if ( V_22 -> V_24 < 1 ) {
F_2 ( V_2 , L_11 ) ;
return - V_21 ;
}
return F_23 ( V_2 ) -> F_96 ( V_100 , V_2 ) ;
}
unsigned int F_97 ( struct V_22 * V_22 )
{
unsigned int V_109 , V_30 ;
V_109 = F_98 () ;
if ( V_22 -> V_110 < V_111 ) {
struct V_112 * V_113 , * V_114 ;
V_30 = V_109 % V_22 -> V_110 ;
V_114 = F_99 ( V_22 -> V_30 , V_109 ) ;
V_113 = F_99 ( V_22 -> V_30 , V_30 ) ;
if ( V_114 -> V_115 ++ == 0 )
F_100 ( & V_113 -> V_98 ) ;
} else
V_30 = V_109 ;
return V_30 ;
}
void F_101 ( struct V_22 * V_22 , unsigned int V_30 )
{
if ( V_22 -> V_110 < V_111 ) {
unsigned int V_109 = F_98 () ;
struct V_112 * V_113 , * V_114 ;
V_114 = F_99 ( V_22 -> V_30 , V_109 ) ;
V_113 = F_99 ( V_22 -> V_30 , V_30 ) ;
if ( -- V_114 -> V_115 == 0 )
F_102 ( & V_113 -> V_98 ) ;
F_103 () ;
}
F_103 () ;
}
static struct V_22 * F_104 ( struct V_100 * V_100 ,
struct V_116 * V_117 , struct V_118 * V_119 ,
const char * V_120 )
{
struct V_22 * V_22 ;
struct V_1 * V_2 ;
void * V_121 ;
unsigned int V_7 ;
int V_74 = 0 ;
for ( V_7 = 0 ; V_7 < V_117 -> V_122 ; V_7 ++ ) {
struct V_123 * V_26 = & V_117 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_26 -> V_3 ;
if ( ( V_26 -> V_15 | V_26 -> V_51 ) % V_124 ) {
F_105 ( & V_100 -> V_2 , L_12 ,
V_120 , F_57 ( & V_3 -> V_2 ) , V_7 ) ;
return NULL ;
}
if ( F_33 ( V_125 , & V_3 -> V_44 ) )
V_74 = 1 ;
}
if ( V_119 == & V_34 ) {
struct V_126 * V_127 ;
struct V_37 * V_39 ;
V_127 = F_106 ( V_117 ) ;
V_39 = F_107 ( sizeof( * V_39 ) + sizeof( struct V_25 )
* V_117 -> V_122 ,
V_27 ) ;
if ( V_39 ) {
V_22 = & V_39 -> V_22 ;
V_39 -> F_96 = V_127 -> F_96 ;
V_39 -> V_128 = V_127 -> V_128 ;
}
V_121 = V_39 ;
} else {
V_22 = F_107 ( sizeof( struct V_22 )
+ sizeof( struct V_25 )
* V_117 -> V_122 ,
V_27 ) ;
V_121 = V_22 ;
}
if ( ! V_121 )
return NULL ;
V_22 -> V_32 = F_108 ( & V_31 , 0 , 0 , V_27 ) ;
if ( V_22 -> V_32 < 0 )
goto V_129;
V_22 -> V_30 = F_109 ( struct V_112 ) ;
if ( ! V_22 -> V_30 )
goto V_130;
for ( V_7 = 0 ; V_7 < V_111 ; V_7 ++ ) {
struct V_112 * V_131 ;
V_131 = F_99 ( V_22 -> V_30 , V_7 ) ;
F_110 ( & V_131 -> V_98 ) ;
V_131 -> V_115 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_117 -> V_122 ; V_7 ++ ) {
struct V_123 * V_26 = & V_117 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_26 -> V_3 ;
V_22 -> V_26 [ V_7 ] . V_3 = V_3 ;
V_22 -> V_26 [ V_7 ] . V_15 = V_26 -> V_15 ;
V_22 -> V_26 [ V_7 ] . V_51 = V_26 -> V_51 ;
V_22 -> V_26 [ V_7 ] . V_108 = V_26 -> V_108 ;
F_111 ( & V_22 -> V_26 [ V_7 ] . V_132 ) ;
F_112 ( & V_22 -> V_26 [ V_7 ] . V_98 ) ;
F_113 ( & V_3 -> V_2 ) ;
}
V_22 -> V_24 = V_117 -> V_122 ;
V_22 -> V_38 = V_117 -> V_38 ;
V_22 -> V_57 = V_117 -> V_57 ;
V_22 -> V_110 = V_117 -> V_110 ;
V_22 -> V_44 = V_117 -> V_44 ;
V_22 -> V_74 = V_74 ;
V_22 -> V_133 = V_117 -> V_133 ;
F_114 ( & V_22 -> V_134 ) ;
F_114 ( & V_22 -> V_135 ) ;
F_114 ( & V_22 -> V_136 ) ;
F_114 ( & V_22 -> V_137 ) ;
V_2 = & V_22 -> V_2 ;
F_115 ( V_2 , L_13 , V_22 -> V_32 ) ;
V_2 -> V_103 = & V_100 -> V_2 ;
V_2 -> type = V_119 ;
V_2 -> V_138 = V_117 -> V_139 ;
V_22 -> V_52 = F_116 ( V_117 -> V_12 ) ;
V_22 -> V_76 = V_117 -> V_12 -> V_15 ;
F_117 ( V_2 ) ;
return V_22 ;
V_130:
F_20 ( & V_31 , V_22 -> V_32 ) ;
V_129:
F_22 ( V_121 ) ;
return NULL ;
}
struct V_22 * F_118 ( struct V_100 * V_100 ,
struct V_116 * V_117 )
{
V_117 -> V_110 = V_140 ;
return F_104 ( V_100 , V_117 , & V_33 ,
V_141 ) ;
}
struct V_22 * F_119 ( struct V_100 * V_100 ,
struct V_116 * V_117 )
{
if ( V_117 -> V_122 > 1 )
return NULL ;
V_117 -> V_110 = F_120 ( V_117 -> V_110 , V_140 ) ;
return F_104 ( V_100 , V_117 , & V_34 ,
V_141 ) ;
}
struct V_22 * F_121 ( struct V_100 * V_100 ,
struct V_116 * V_117 )
{
V_117 -> V_110 = V_140 ;
return F_104 ( V_100 , V_117 , & V_35 ,
V_141 ) ;
}
void F_39 ( struct V_22 * V_22 )
{
struct V_5 * V_6 = F_55 ( & V_22 -> V_2 ) ;
int V_7 , V_142 ;
V_142 = F_122 ( V_143 ) ;
V_142 = F_123 ( V_143 , F_124 ( V_144 -> V_145 + V_142 , 8 ) ) ;
F_125 () ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ )
if ( F_5 ( V_6 , V_7 , 0 ) )
F_126 ( 1 , F_5 ( V_6 , V_7 , V_142 ) ) ;
F_125 () ;
}
int F_36 ( struct V_22 * V_22 )
{
int V_7 ;
if ( V_22 -> V_24 == 0
|| ! F_127 ( V_146 ) )
return - V_21 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
if ( V_3 -> V_9 )
return 1 ;
}
return 0 ;
}
int F_128 ( struct V_22 * V_22 )
{
return F_24 ( & V_22 -> V_2 ) ;
}
void T_8 F_129 ( void )
{
F_130 ( & V_31 ) ;
}
