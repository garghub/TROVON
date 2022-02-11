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
struct V_22 * F_17 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_25 ( V_2 , struct V_22 , V_2 ) ;
F_26 ( V_2 -> type -> V_35 != F_16 ) ;
return V_22 ;
}
struct V_36 * F_23 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
F_26 ( ! F_21 ( V_2 ) ) ;
return F_25 ( V_22 , struct V_36 , V_22 ) ;
}
void * F_27 ( struct V_22 * V_22 )
{
return V_22 -> V_37 ;
}
void * F_28 ( struct V_36 * V_38 )
{
return V_38 -> V_39 ;
}
void F_29 ( struct V_36 * V_38 , void * V_40 )
{
V_38 -> V_39 = V_40 ;
}
int F_30 ( struct V_22 * V_22 )
{
if ( F_24 ( & V_22 -> V_2 ) ) {
T_3 V_7 , V_41 ;
for ( V_7 = 0 , V_41 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
if ( F_31 ( V_42 , & V_3 -> V_43 ) )
V_41 ++ ;
}
if ( V_41 )
return V_44 ;
else
return V_45 ;
} else if ( F_21 ( & V_22 -> V_2 ) ) {
return V_46 ;
}
return 0 ;
}
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
unsigned long long V_50 = 0 ;
if ( F_24 ( V_2 ) ) {
V_50 = V_22 -> V_51 ;
} else if ( V_22 -> V_24 == 1 ) {
struct V_25 * V_25 = & V_22 -> V_26 [ 0 ] ;
V_50 = V_25 -> V_50 ;
}
return sprintf ( V_49 , L_4 , V_50 ) ;
}
static T_4 F_33 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , F_34 ( V_22 ) ) ;
}
static T_4 F_35 ( struct V_1 * V_2 , struct V_47 * V_48 ,
const char * V_49 , T_2 V_52 )
{
bool V_53 ;
int V_29 = F_36 ( V_49 , & V_53 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_29 )
return V_29 ;
if ( ! V_53 )
return - V_54 ;
F_37 ( V_22 ) ;
return V_52 ;
}
static T_4 F_38 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , V_22 -> V_24 ) ;
}
static T_4 F_39 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , F_30 ( V_22 ) ) ;
}
static T_4 F_40 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_55 * V_56 = V_22 -> V_56 ;
if ( F_24 ( V_2 ) && V_56 )
;
else
return - V_21 ;
return sprintf ( V_49 , L_6 , V_56 -> V_57 ) ;
}
T_5 F_41 ( struct V_22 * V_22 )
{
T_5 V_58 = 0 , V_59 , V_60 ;
int V_7 ;
F_26 ( ! F_42 ( & V_22 -> V_2 ) ) ;
V_61:
V_59 = 0 ;
V_60 = V_58 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_62 * V_63 = F_43 ( V_25 ) ;
if ( ! V_63 )
return 0 ;
if ( F_24 ( & V_22 -> V_2 ) ) {
V_59 += F_44 ( V_22 ,
V_25 , & V_60 ) ;
if ( V_60 > V_58 ) {
V_58 = V_60 ;
goto V_61;
}
} else if ( F_21 ( & V_22 -> V_2 ) )
V_59 += F_45 ( V_22 ) ;
}
return V_59 ;
}
static T_4 F_46 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
unsigned long long V_59 = 0 ;
F_10 ( V_2 ) ;
F_47 ( V_2 ) ;
V_59 = F_41 ( V_22 ) ;
F_12 ( V_2 ) ;
return sprintf ( V_49 , L_4 , V_59 ) ;
}
static T_4 F_48 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_5 * V_6 = F_49 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_6 )
V_29 = sprintf ( V_49 , L_7 , V_6 -> V_64 , V_6 -> V_65 ) ;
else
V_29 = - V_21 ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_50 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_66 )
V_29 = sprintf ( V_49 , L_8 , F_51 ( V_22 -> V_66 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_52 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_67 )
V_29 = sprintf ( V_49 , L_8 , F_51 ( V_22 -> V_67 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_53 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_68 )
V_29 = sprintf ( V_49 , L_8 , F_51 ( V_22 -> V_68 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_54 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_69 )
V_29 = sprintf ( V_49 , L_8 , F_51 ( V_22 -> V_69 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_55 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , V_22 -> V_70 ) ;
}
static T_4 F_56 ( struct V_1 * V_2 ,
struct V_47 * V_48 , const char * V_49 , T_2 V_52 )
{
bool V_70 ;
int V_29 = F_36 ( V_49 , & V_70 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_22 -> V_70 = V_70 ;
return V_52 ;
}
static T_4 F_57 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return F_58 ( & V_22 -> V_71 , V_49 , 0 ) ;
}
static T_4 F_59 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_6 , V_22 -> V_72 ) ;
}
static T_6 F_60 ( struct V_73 * V_74 , struct V_75 * V_76 , int V_77 )
{
struct V_1 * V_2 = F_25 ( V_74 , F_61 ( * V_2 ) , V_74 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_55 * V_56 = V_22 -> V_56 ;
int type = F_30 ( V_22 ) ;
if ( ! F_24 ( V_2 ) && V_76 == & V_78 . V_48 )
return 0 ;
if ( ! F_24 ( V_2 ) && V_76 == & V_79 . V_48 )
return 0 ;
if ( ! F_24 ( V_2 ) && V_76 == & V_80 . V_48 )
return 0 ;
if ( ! F_24 ( V_2 ) && V_76 == & V_81 . V_48 )
return 0 ;
if ( V_76 == & V_82 . V_48 ) {
int V_83 = F_34 ( V_22 ) ;
if ( V_83 == 1 )
return V_76 -> V_84 ;
else if ( V_83 == 0 )
return 0444 ;
else
return 0 ;
}
if ( V_76 != & V_85 . V_48
&& V_76 != & V_86 . V_48 )
return V_76 -> V_84 ;
if ( ( type == V_44
|| type == V_46 )
&& V_76 == & V_86 . V_48 )
return V_76 -> V_84 ;
else if ( F_24 ( V_2 ) && V_56 )
return V_76 -> V_84 ;
return 0 ;
}
T_7 F_62 ( struct V_22 * V_22 )
{
struct V_55 * V_56 = V_22 -> V_56 ;
if ( V_56 )
return V_56 -> V_57 ;
return 0 ;
}
T_7 F_63 ( struct V_22 * V_22 )
{
struct V_55 * V_56 = V_22 -> V_56 ;
if ( V_56 )
return V_56 -> V_87 ;
return 0 ;
}
void F_64 ( struct V_25 * V_25 )
{
struct V_88 * V_89 , * V_90 ;
F_65 ( & V_25 -> V_91 ) ;
F_66 (label_ent, e, &nd_mapping->labels, list) {
F_67 ( & V_89 -> V_92 ) ;
F_22 ( V_89 ) ;
}
}
static void F_68 ( struct V_93 * V_93 ,
struct V_1 * V_2 , bool V_94 )
{
struct V_22 * V_22 ;
if ( ! V_94 && ( F_24 ( V_2 ) || F_21 ( V_2 ) ) ) {
int V_7 ;
V_22 = F_17 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_62 * V_63 = V_25 -> V_63 ;
struct V_3 * V_3 = V_25 -> V_3 ;
F_69 ( & V_25 -> V_91 ) ;
F_64 ( V_25 ) ;
F_70 ( & V_25 -> V_91 ) ;
F_71 ( V_63 ) ;
V_25 -> V_63 = NULL ;
if ( V_63 )
F_72 ( & V_3 -> V_95 ) ;
}
if ( F_24 ( V_2 ) )
return;
}
if ( V_2 -> V_96 && ( F_21 ( V_2 -> V_96 ) || F_24 ( V_2 -> V_96 ) )
&& V_94 ) {
V_22 = F_17 ( V_2 -> V_96 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_66 == V_2 )
F_73 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_74 ( V_2 ) && V_94 ) {
struct V_97 * V_97 = F_75 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_96 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_67 == V_2 )
F_76 ( V_22 ) ;
if ( V_22 -> V_66 == & V_97 -> V_98 -> V_2 )
F_73 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_77 ( V_2 ) && V_94 ) {
struct V_99 * V_99 = F_78 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_96 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_68 == V_2 )
F_79 ( V_22 ) ;
if ( V_22 -> V_66 == & V_99 -> V_98 -> V_2 )
F_73 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_80 ( V_2 ) && V_94 ) {
struct V_100 * V_100 = F_81 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_96 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_69 == V_2 )
F_82 ( V_22 ) ;
if ( V_22 -> V_66 == & V_100 -> V_99 . V_98 -> V_2 )
F_73 ( V_22 ) ;
F_12 ( V_2 ) ;
}
}
void F_83 ( struct V_93 * V_93 , struct V_1 * V_2 )
{
F_68 ( V_93 , V_2 , true ) ;
}
void F_84 ( struct V_93 * V_93 , struct V_1 * V_2 )
{
F_68 ( V_93 , V_2 , false ) ;
}
static T_4 F_85 ( struct V_1 * V_2 , char * V_49 , int V_77 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_25 * V_25 ;
struct V_3 * V_3 ;
if ( V_77 >= V_22 -> V_24 )
return - V_21 ;
V_25 = & V_22 -> V_26 [ V_77 ] ;
V_3 = V_25 -> V_3 ;
return sprintf ( V_49 , L_10 , F_51 ( & V_3 -> V_2 ) ,
V_25 -> V_15 , V_25 -> V_50 ) ;
}
static T_6 F_86 ( struct V_73 * V_74 , struct V_75 * V_76 , int V_77 )
{
struct V_1 * V_2 = F_25 ( V_74 , struct V_1 , V_74 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_77 < V_22 -> V_24 )
return V_76 -> V_84 ;
return 0 ;
}
int F_87 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = & V_22 -> V_2 ;
struct V_93 * V_93 = F_88 ( V_2 ) ;
if ( ! F_21 ( V_2 ) )
return 0 ;
if ( V_22 -> V_24 < 1 ) {
F_89 ( V_2 , L_11 ) ;
return - V_21 ;
}
return F_23 ( V_2 ) -> F_90 ( V_93 , V_2 ) ;
}
unsigned int F_91 ( struct V_22 * V_22 )
{
unsigned int V_101 , V_30 ;
V_101 = F_92 () ;
if ( V_22 -> V_102 < V_103 ) {
struct V_104 * V_105 , * V_106 ;
V_30 = V_101 % V_22 -> V_102 ;
V_106 = F_93 ( V_22 -> V_30 , V_101 ) ;
V_105 = F_93 ( V_22 -> V_30 , V_30 ) ;
if ( V_106 -> V_107 ++ == 0 )
F_94 ( & V_105 -> V_91 ) ;
} else
V_30 = V_101 ;
return V_30 ;
}
void F_95 ( struct V_22 * V_22 , unsigned int V_30 )
{
if ( V_22 -> V_102 < V_103 ) {
unsigned int V_101 = F_92 () ;
struct V_104 * V_105 , * V_106 ;
V_106 = F_93 ( V_22 -> V_30 , V_101 ) ;
V_105 = F_93 ( V_22 -> V_30 , V_30 ) ;
if ( -- V_106 -> V_107 == 0 )
F_96 ( & V_105 -> V_91 ) ;
F_97 () ;
}
F_97 () ;
}
static struct V_22 * F_98 ( struct V_93 * V_93 ,
struct V_108 * V_109 , struct V_110 * V_111 ,
const char * V_112 )
{
struct V_22 * V_22 ;
struct V_1 * V_2 ;
void * V_113 ;
unsigned int V_7 ;
int V_70 = 0 ;
for ( V_7 = 0 ; V_7 < V_109 -> V_114 ; V_7 ++ ) {
struct V_115 * V_26 = & V_109 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_26 -> V_3 ;
if ( ( V_26 -> V_15 | V_26 -> V_50 ) % V_116 ) {
F_89 ( & V_93 -> V_2 , L_12 ,
V_112 , F_51 ( & V_3 -> V_2 ) , V_7 ) ;
return NULL ;
}
if ( F_31 ( V_117 , & V_3 -> V_43 ) )
V_70 = 1 ;
}
if ( V_111 == & V_34 ) {
struct V_118 * V_119 ;
struct V_36 * V_38 ;
V_119 = F_99 ( V_109 ) ;
V_38 = F_100 ( sizeof( * V_38 ) + sizeof( struct V_25 )
* V_109 -> V_114 ,
V_27 ) ;
if ( V_38 ) {
V_22 = & V_38 -> V_22 ;
V_38 -> F_90 = V_119 -> F_90 ;
V_38 -> V_120 = V_119 -> V_120 ;
}
V_113 = V_38 ;
} else {
V_22 = F_100 ( sizeof( struct V_22 )
+ sizeof( struct V_25 )
* V_109 -> V_114 ,
V_27 ) ;
V_113 = V_22 ;
}
if ( ! V_113 )
return NULL ;
V_22 -> V_32 = F_101 ( & V_31 , 0 , 0 , V_27 ) ;
if ( V_22 -> V_32 < 0 )
goto V_121;
V_22 -> V_30 = F_102 ( struct V_104 ) ;
if ( ! V_22 -> V_30 )
goto V_122;
for ( V_7 = 0 ; V_7 < V_103 ; V_7 ++ ) {
struct V_104 * V_123 ;
V_123 = F_93 ( V_22 -> V_30 , V_7 ) ;
F_103 ( & V_123 -> V_91 ) ;
V_123 -> V_107 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_109 -> V_114 ; V_7 ++ ) {
struct V_115 * V_26 = & V_109 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_26 -> V_3 ;
V_22 -> V_26 [ V_7 ] . V_3 = V_3 ;
V_22 -> V_26 [ V_7 ] . V_15 = V_26 -> V_15 ;
V_22 -> V_26 [ V_7 ] . V_50 = V_26 -> V_50 ;
F_104 ( & V_22 -> V_26 [ V_7 ] . V_124 ) ;
F_105 ( & V_22 -> V_26 [ V_7 ] . V_91 ) ;
F_106 ( & V_3 -> V_2 ) ;
}
V_22 -> V_24 = V_109 -> V_114 ;
V_22 -> V_37 = V_109 -> V_37 ;
V_22 -> V_56 = V_109 -> V_56 ;
V_22 -> V_102 = V_109 -> V_102 ;
V_22 -> V_43 = V_109 -> V_43 ;
V_22 -> V_70 = V_70 ;
V_22 -> V_125 = V_109 -> V_125 ;
F_107 ( & V_22 -> V_126 ) ;
F_107 ( & V_22 -> V_127 ) ;
F_107 ( & V_22 -> V_128 ) ;
F_107 ( & V_22 -> V_129 ) ;
V_2 = & V_22 -> V_2 ;
F_108 ( V_2 , L_13 , V_22 -> V_32 ) ;
V_2 -> V_96 = & V_93 -> V_2 ;
V_2 -> type = V_111 ;
V_2 -> V_130 = V_109 -> V_131 ;
V_22 -> V_51 = F_109 ( V_109 -> V_12 ) ;
V_22 -> V_72 = V_109 -> V_12 -> V_15 ;
F_110 ( V_2 ) ;
return V_22 ;
V_122:
F_20 ( & V_31 , V_22 -> V_32 ) ;
V_121:
F_22 ( V_113 ) ;
return NULL ;
}
struct V_22 * F_111 ( struct V_93 * V_93 ,
struct V_108 * V_109 )
{
V_109 -> V_102 = V_132 ;
return F_98 ( V_93 , V_109 , & V_33 ,
V_133 ) ;
}
struct V_22 * F_112 ( struct V_93 * V_93 ,
struct V_108 * V_109 )
{
if ( V_109 -> V_114 > 1 )
return NULL ;
V_109 -> V_102 = F_113 ( V_109 -> V_102 , V_132 ) ;
return F_98 ( V_93 , V_109 , & V_34 ,
V_133 ) ;
}
struct V_22 * F_114 ( struct V_93 * V_93 ,
struct V_108 * V_109 )
{
V_109 -> V_102 = V_132 ;
return F_98 ( V_93 , V_109 , & V_134 ,
V_133 ) ;
}
void F_37 ( struct V_22 * V_22 )
{
struct V_5 * V_6 = F_49 ( & V_22 -> V_2 ) ;
int V_7 , V_135 ;
V_135 = F_115 ( V_136 ) ;
V_135 = F_116 ( V_136 , F_117 ( V_137 -> V_138 + V_135 , 8 ) ) ;
F_118 () ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ )
if ( F_5 ( V_6 , V_7 , 0 ) )
F_119 ( 1 , F_5 ( V_6 , V_7 , V_135 ) ) ;
F_118 () ;
}
int F_34 ( struct V_22 * V_22 )
{
int V_7 ;
if ( V_22 -> V_24 == 0 )
return - V_21 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_25 -> V_3 ;
if ( V_3 -> V_9 )
return 1 ;
}
return 0 ;
}
void T_8 F_120 ( void )
{
F_121 ( & V_31 ) ;
}
