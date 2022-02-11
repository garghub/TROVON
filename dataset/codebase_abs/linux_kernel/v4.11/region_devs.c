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
if ( V_3 -> V_42 & V_43 )
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
static T_4 F_31 ( struct V_1 * V_2 ,
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
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , V_22 -> V_24 ) ;
}
static T_4 F_33 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , F_30 ( V_22 ) ) ;
}
static T_4 F_34 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_52 * V_53 = V_22 -> V_53 ;
if ( F_24 ( V_2 ) && V_53 )
;
else
return - V_21 ;
return sprintf ( V_49 , L_6 , V_53 -> V_54 ) ;
}
T_5 F_35 ( struct V_22 * V_22 )
{
T_5 V_55 = 0 , V_56 , V_57 ;
int V_7 ;
F_26 ( ! F_36 ( & V_22 -> V_2 ) ) ;
V_58:
V_56 = 0 ;
V_57 = V_55 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_59 * V_60 = F_37 ( V_25 ) ;
if ( ! V_60 )
return 0 ;
if ( F_24 ( & V_22 -> V_2 ) ) {
V_56 += F_38 ( V_22 ,
V_25 , & V_57 ) ;
if ( V_57 > V_55 ) {
V_55 = V_57 ;
goto V_58;
}
} else if ( F_21 ( & V_22 -> V_2 ) )
V_56 += F_39 ( V_22 ) ;
}
return V_56 ;
}
static T_4 F_40 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
unsigned long long V_56 = 0 ;
F_10 ( V_2 ) ;
F_41 ( V_2 ) ;
V_56 = F_35 ( V_22 ) ;
F_12 ( V_2 ) ;
return sprintf ( V_49 , L_4 , V_56 ) ;
}
static T_4 F_42 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_5 * V_6 = F_43 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_6 )
V_29 = sprintf ( V_49 , L_7 , V_6 -> V_61 , V_6 -> V_62 ) ;
else
V_29 = - V_21 ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_44 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_63 )
V_29 = sprintf ( V_49 , L_8 , F_45 ( V_22 -> V_63 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_46 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_64 )
V_29 = sprintf ( V_49 , L_8 , F_45 ( V_22 -> V_64 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_47 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_65 )
V_29 = sprintf ( V_49 , L_8 , F_45 ( V_22 -> V_65 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_48 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
T_4 V_29 ;
F_10 ( V_2 ) ;
if ( V_22 -> V_66 )
V_29 = sprintf ( V_49 , L_8 , F_45 ( V_22 -> V_66 ) ) ;
else
V_29 = sprintf ( V_49 , L_9 ) ;
F_12 ( V_2 ) ;
return V_29 ;
}
static T_4 F_49 ( struct V_1 * V_2 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
return sprintf ( V_49 , L_5 , V_22 -> V_67 ) ;
}
static T_4 F_50 ( struct V_1 * V_2 ,
struct V_47 * V_48 , const char * V_49 , T_2 V_68 )
{
bool V_67 ;
int V_29 = F_51 ( V_49 , & V_67 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_22 -> V_67 = V_67 ;
return V_68 ;
}
static T_6 F_52 ( struct V_69 * V_70 , struct V_71 * V_72 , int V_73 )
{
struct V_1 * V_2 = F_25 ( V_70 , F_53 ( * V_2 ) , V_70 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_52 * V_53 = V_22 -> V_53 ;
int type = F_30 ( V_22 ) ;
if ( ! F_24 ( V_2 ) && V_72 == & V_74 . V_48 )
return 0 ;
if ( ! F_24 ( V_2 ) && V_72 == & V_75 . V_48 )
return 0 ;
if ( V_72 != & V_76 . V_48
&& V_72 != & V_77 . V_48 )
return V_72 -> V_78 ;
if ( ( type == V_44
|| type == V_46 )
&& V_72 == & V_77 . V_48 )
return V_72 -> V_78 ;
else if ( F_24 ( V_2 ) && V_53 )
return V_72 -> V_78 ;
return 0 ;
}
T_7 F_54 ( struct V_22 * V_22 )
{
struct V_52 * V_53 = V_22 -> V_53 ;
if ( V_53 )
return V_53 -> V_54 ;
return 0 ;
}
T_7 F_55 ( struct V_22 * V_22 )
{
struct V_52 * V_53 = V_22 -> V_53 ;
if ( V_53 )
return V_53 -> V_79 ;
return 0 ;
}
void F_56 ( struct V_25 * V_25 )
{
struct V_80 * V_81 , * V_82 ;
F_57 ( & V_25 -> V_83 ) ;
F_58 (label_ent, e, &nd_mapping->labels, list) {
F_59 ( & V_81 -> V_84 ) ;
F_22 ( V_81 ) ;
}
}
static void F_60 ( struct V_85 * V_85 ,
struct V_1 * V_2 , bool V_86 )
{
struct V_22 * V_22 ;
if ( ! V_86 && ( F_24 ( V_2 ) || F_21 ( V_2 ) ) ) {
int V_7 ;
V_22 = F_17 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ ) {
struct V_25 * V_25 = & V_22 -> V_26 [ V_7 ] ;
struct V_59 * V_60 = V_25 -> V_60 ;
struct V_3 * V_3 = V_25 -> V_3 ;
F_61 ( & V_25 -> V_83 ) ;
F_56 ( V_25 ) ;
F_62 ( & V_25 -> V_83 ) ;
F_63 ( V_60 ) ;
V_25 -> V_60 = NULL ;
if ( V_60 )
F_64 ( & V_3 -> V_87 ) ;
}
if ( F_24 ( V_2 ) )
return;
}
if ( V_2 -> V_88 && ( F_21 ( V_2 -> V_88 ) || F_24 ( V_2 -> V_88 ) )
&& V_86 ) {
V_22 = F_17 ( V_2 -> V_88 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_63 == V_2 )
F_65 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_66 ( V_2 ) && V_86 ) {
struct V_89 * V_89 = F_67 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_88 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_64 == V_2 )
F_68 ( V_22 ) ;
if ( V_22 -> V_63 == & V_89 -> V_90 -> V_2 )
F_65 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_69 ( V_2 ) && V_86 ) {
struct V_91 * V_91 = F_70 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_88 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_65 == V_2 )
F_71 ( V_22 ) ;
if ( V_22 -> V_63 == & V_91 -> V_90 -> V_2 )
F_65 ( V_22 ) ;
F_12 ( V_2 ) ;
}
if ( F_72 ( V_2 ) && V_86 ) {
struct V_92 * V_92 = F_73 ( V_2 ) ;
V_22 = F_17 ( V_2 -> V_88 ) ;
F_10 ( V_2 ) ;
if ( V_22 -> V_66 == V_2 )
F_74 ( V_22 ) ;
if ( V_22 -> V_63 == & V_92 -> V_91 . V_90 -> V_2 )
F_65 ( V_22 ) ;
F_12 ( V_2 ) ;
}
}
void F_75 ( struct V_85 * V_85 , struct V_1 * V_2 )
{
F_60 ( V_85 , V_2 , true ) ;
}
void F_76 ( struct V_85 * V_85 , struct V_1 * V_2 )
{
F_60 ( V_85 , V_2 , false ) ;
}
static T_4 F_77 ( struct V_1 * V_2 , char * V_49 , int V_73 )
{
struct V_22 * V_22 = F_17 ( V_2 ) ;
struct V_25 * V_25 ;
struct V_3 * V_3 ;
if ( V_73 >= V_22 -> V_24 )
return - V_21 ;
V_25 = & V_22 -> V_26 [ V_73 ] ;
V_3 = V_25 -> V_3 ;
return sprintf ( V_49 , L_10 , F_45 ( & V_3 -> V_2 ) ,
V_25 -> V_15 , V_25 -> V_50 ) ;
}
static T_6 F_78 ( struct V_69 * V_70 , struct V_71 * V_72 , int V_73 )
{
struct V_1 * V_2 = F_25 ( V_70 , struct V_1 , V_70 ) ;
struct V_22 * V_22 = F_17 ( V_2 ) ;
if ( V_73 < V_22 -> V_24 )
return V_72 -> V_78 ;
return 0 ;
}
int F_79 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = & V_22 -> V_2 ;
struct V_85 * V_85 = F_80 ( V_2 ) ;
if ( ! F_21 ( V_2 ) )
return 0 ;
if ( V_22 -> V_24 < 1 ) {
F_81 ( V_2 , L_11 ) ;
return - V_21 ;
}
return F_23 ( V_2 ) -> F_82 ( V_85 , V_2 ) ;
}
unsigned int F_83 ( struct V_22 * V_22 )
{
unsigned int V_93 , V_30 ;
V_93 = F_84 () ;
if ( V_22 -> V_94 < V_95 ) {
struct V_96 * V_97 , * V_98 ;
V_30 = V_93 % V_22 -> V_94 ;
V_98 = F_85 ( V_22 -> V_30 , V_93 ) ;
V_97 = F_85 ( V_22 -> V_30 , V_30 ) ;
if ( V_98 -> V_99 ++ == 0 )
F_86 ( & V_97 -> V_83 ) ;
} else
V_30 = V_93 ;
return V_30 ;
}
void F_87 ( struct V_22 * V_22 , unsigned int V_30 )
{
if ( V_22 -> V_94 < V_95 ) {
unsigned int V_93 = F_84 () ;
struct V_96 * V_97 , * V_98 ;
V_98 = F_85 ( V_22 -> V_30 , V_93 ) ;
V_97 = F_85 ( V_22 -> V_30 , V_30 ) ;
if ( -- V_98 -> V_99 == 0 )
F_88 ( & V_97 -> V_83 ) ;
F_89 () ;
}
F_89 () ;
}
static struct V_22 * F_90 ( struct V_85 * V_85 ,
struct V_100 * V_101 , struct V_102 * V_103 ,
const char * V_104 )
{
struct V_22 * V_22 ;
struct V_1 * V_2 ;
void * V_105 ;
unsigned int V_7 ;
int V_67 = 0 ;
for ( V_7 = 0 ; V_7 < V_101 -> V_106 ; V_7 ++ ) {
struct V_107 * V_26 = & V_101 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_26 -> V_3 ;
if ( ( V_26 -> V_15 | V_26 -> V_50 ) % V_108 ) {
F_81 ( & V_85 -> V_2 , L_12 ,
V_104 , F_45 ( & V_3 -> V_2 ) , V_7 ) ;
return NULL ;
}
if ( V_3 -> V_42 & V_109 )
V_67 = 1 ;
}
if ( V_103 == & V_34 ) {
struct V_110 * V_111 ;
struct V_36 * V_38 ;
V_111 = F_91 ( V_101 ) ;
V_38 = F_92 ( sizeof( * V_38 ) + sizeof( struct V_25 )
* V_101 -> V_106 ,
V_27 ) ;
if ( V_38 ) {
V_22 = & V_38 -> V_22 ;
V_38 -> F_82 = V_111 -> F_82 ;
V_38 -> V_112 = V_111 -> V_112 ;
}
V_105 = V_38 ;
} else {
V_22 = F_92 ( sizeof( struct V_22 )
+ sizeof( struct V_25 )
* V_101 -> V_106 ,
V_27 ) ;
V_105 = V_22 ;
}
if ( ! V_105 )
return NULL ;
V_22 -> V_32 = F_93 ( & V_31 , 0 , 0 , V_27 ) ;
if ( V_22 -> V_32 < 0 )
goto V_113;
V_22 -> V_30 = F_94 ( struct V_96 ) ;
if ( ! V_22 -> V_30 )
goto V_114;
for ( V_7 = 0 ; V_7 < V_95 ; V_7 ++ ) {
struct V_96 * V_115 ;
V_115 = F_85 ( V_22 -> V_30 , V_7 ) ;
F_95 ( & V_115 -> V_83 ) ;
V_115 -> V_99 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_101 -> V_106 ; V_7 ++ ) {
struct V_107 * V_26 = & V_101 -> V_26 [ V_7 ] ;
struct V_3 * V_3 = V_26 -> V_3 ;
V_22 -> V_26 [ V_7 ] . V_3 = V_3 ;
V_22 -> V_26 [ V_7 ] . V_15 = V_26 -> V_15 ;
V_22 -> V_26 [ V_7 ] . V_50 = V_26 -> V_50 ;
F_96 ( & V_22 -> V_26 [ V_7 ] . V_116 ) ;
F_97 ( & V_22 -> V_26 [ V_7 ] . V_83 ) ;
F_98 ( & V_3 -> V_2 ) ;
}
V_22 -> V_24 = V_101 -> V_106 ;
V_22 -> V_37 = V_101 -> V_37 ;
V_22 -> V_53 = V_101 -> V_53 ;
V_22 -> V_94 = V_101 -> V_94 ;
V_22 -> V_42 = V_101 -> V_42 ;
V_22 -> V_67 = V_67 ;
V_22 -> V_117 = V_101 -> V_117 ;
F_99 ( & V_22 -> V_118 ) ;
F_99 ( & V_22 -> V_119 ) ;
F_99 ( & V_22 -> V_120 ) ;
F_99 ( & V_22 -> V_121 ) ;
V_2 = & V_22 -> V_2 ;
F_100 ( V_2 , L_13 , V_22 -> V_32 ) ;
V_2 -> V_88 = & V_85 -> V_2 ;
V_2 -> type = V_103 ;
V_2 -> V_122 = V_101 -> V_123 ;
V_22 -> V_51 = F_101 ( V_101 -> V_12 ) ;
V_22 -> V_124 = V_101 -> V_12 -> V_15 ;
F_102 ( V_2 ) ;
return V_22 ;
V_114:
F_20 ( & V_31 , V_22 -> V_32 ) ;
V_113:
F_22 ( V_105 ) ;
return NULL ;
}
struct V_22 * F_103 ( struct V_85 * V_85 ,
struct V_100 * V_101 )
{
V_101 -> V_94 = V_125 ;
return F_90 ( V_85 , V_101 , & V_33 ,
V_126 ) ;
}
struct V_22 * F_104 ( struct V_85 * V_85 ,
struct V_100 * V_101 )
{
if ( V_101 -> V_106 > 1 )
return NULL ;
V_101 -> V_94 = F_105 ( V_101 -> V_94 , V_125 ) ;
return F_90 ( V_85 , V_101 , & V_34 ,
V_126 ) ;
}
struct V_22 * F_106 ( struct V_85 * V_85 ,
struct V_100 * V_101 )
{
V_101 -> V_94 = V_125 ;
return F_90 ( V_85 , V_101 , & V_127 ,
V_126 ) ;
}
void F_107 ( struct V_22 * V_22 )
{
struct V_5 * V_6 = F_43 ( & V_22 -> V_2 ) ;
int V_7 , V_128 ;
V_128 = F_108 ( V_129 ) ;
V_128 = F_109 ( V_129 , F_110 ( V_130 -> V_131 + V_128 , 8 ) ) ;
F_111 () ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ )
if ( F_5 ( V_6 , V_7 , 0 ) )
F_112 ( 1 , F_5 ( V_6 , V_7 , V_128 ) ) ;
F_111 () ;
}
int F_113 ( struct V_22 * V_22 )
{
struct V_5 * V_6 = F_43 ( & V_22 -> V_2 ) ;
int V_7 ;
if ( V_22 -> V_24 == 0 )
return - V_21 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_24 ; V_7 ++ )
if ( F_5 ( V_6 , V_7 , 0 ) )
return 1 ;
return 0 ;
}
void T_8 F_114 ( void )
{
F_115 ( & V_31 ) ;
}
