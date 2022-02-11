static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_2 ( & V_2 -> V_10 ) ;
V_9 -> V_7 = V_7 ;
F_3 ( & V_9 -> V_11 ) ;
V_9 -> time = * V_6 ;
V_9 -> V_12 += V_4 ;
F_4 ( & V_9 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_13 ;
bool V_14 ;
struct V_5 V_6 ;
int V_12 = V_15 ;
F_6 ( & V_2 -> V_10 ) ;
do {
V_13 = V_2 -> V_16 -> V_17 ( V_2 , V_3 ) ;
V_14 = F_7 ( V_2 , V_3 , & V_6 , 0 ) ;
} while ( V_13 != V_2 -> V_16 -> V_17 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( ! V_14 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , 1 , & V_6 , V_13 ) ;
F_8 ( & V_2 -> V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_18 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_13 , V_19 ;
bool V_14 ;
struct V_5 V_6 ;
int V_12 = V_15 ;
int V_20 = V_9 -> V_20 ;
do {
V_13 = V_2 -> V_16 -> V_17 ( V_2 , V_3 ) ;
V_14 = F_7 ( V_2 , V_3 , & V_6 , V_18 ) ;
} while ( V_13 != V_2 -> V_16 -> V_17 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( V_2 -> V_21 != 0 ) {
V_19 = ( V_13 - V_9 -> V_7 ) & V_2 -> V_21 ;
} else if ( V_14 && V_20 ) {
const struct V_5 * V_22 ;
T_2 V_23 ;
V_22 = & V_9 -> time ;
V_23 = F_10 ( & V_6 ) - F_10 ( V_22 ) ;
V_19 = F_11 ( V_23 , V_20 ) ;
if ( V_19 == 0 && V_18 & V_24 )
F_12 ( L_1
L_2 ,
V_3 , ( long long ) V_23 , V_20 ) ;
} else {
V_19 = ( V_18 & V_24 ) != 0 ;
}
if ( V_19 > 1 && ( V_9 -> V_25 & 0x2 ) ) {
F_12 ( L_3
L_4 , V_3 , V_19 ) ;
V_19 = 1 ;
}
F_12 ( L_5
L_6 ,
V_3 , V_9 -> V_12 , V_19 , V_13 , V_9 -> V_7 ) ;
if ( V_19 == 0 ) {
F_13 ( V_13 != V_9 -> V_7 ) ;
return;
}
if ( ! V_14 && ( V_18 & V_24 ) == 0 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , V_19 , & V_6 , V_13 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return 0 ;
return V_9 -> V_12 ;
}
T_1 F_16 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
T_1 V_9 ;
unsigned long V_18 ;
F_18 ( ! V_2 -> V_16 -> V_29 ,
L_7 ) ;
F_19 ( & V_2 -> V_10 , V_18 ) ;
F_9 ( V_2 , V_3 , 0 ) ;
V_9 = F_14 ( V_2 , V_3 ) ;
F_20 ( & V_2 -> V_10 , V_18 ) ;
return V_9 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
F_19 ( & V_2 -> V_10 , V_30 ) ;
if ( V_9 -> V_31 ) {
V_2 -> V_16 -> V_32 ( V_2 , V_3 ) ;
V_9 -> V_31 = false ;
}
F_9 ( V_2 , V_3 , 0 ) ;
F_20 ( & V_2 -> V_10 , V_30 ) ;
}
static void F_22 ( unsigned long V_33 )
{
struct V_8 * V_9 = ( void * ) V_33 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_3 = V_9 -> V_3 ;
unsigned long V_30 ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
if ( F_23 ( & V_9 -> V_35 ) == 0 && V_9 -> V_31 ) {
F_24 ( L_8 , V_3 ) ;
F_21 ( V_2 , V_3 ) ;
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_26 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_26 ; V_3 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_15 ( V_9 -> V_31 &&
F_26 ( V_2 , V_36 ) ) ;
F_27 ( & V_9 -> V_37 ) ;
}
F_28 ( V_2 -> V_9 ) ;
V_2 -> V_26 = 0 ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_26 )
{
int V_38 = - V_39 ;
unsigned int V_40 ;
F_30 ( & V_2 -> V_34 ) ;
F_30 ( & V_2 -> V_10 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_9 = F_31 ( V_26 , sizeof( * V_2 -> V_9 ) , V_41 ) ;
if ( ! V_2 -> V_9 )
goto V_42;
for ( V_40 = 0 ; V_40 < V_26 ; V_40 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_40 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_3 = V_40 ;
F_32 ( & V_9 -> V_43 ) ;
F_33 ( & V_9 -> V_37 , F_22 ,
( unsigned long ) V_9 ) ;
F_34 ( & V_9 -> V_11 ) ;
}
F_35 ( L_9 ) ;
if ( V_2 -> V_16 -> V_29 )
F_35 ( L_10 ) ;
else
F_35 ( L_11 ) ;
if ( V_2 -> V_44 && ! V_2 -> V_16 -> V_29 ) {
V_2 -> V_44 = false ;
F_35 ( L_12
L_13 ) ;
}
return 0 ;
V_42:
V_2 -> V_26 = 0 ;
return V_38 ;
}
static void F_36 ( void * V_45 , bool V_46 )
{
struct V_1 * V_2 = V_45 ;
if ( V_2 -> V_16 -> V_47 ) {
V_2 -> V_16 -> V_47 ( V_2 , V_46 ) ;
return;
}
if ( ! V_2 -> V_48 )
return;
if ( V_46 ) {
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
} else {
if ( V_2 -> V_16 -> V_50 )
V_2 -> V_16 -> V_50 ( V_2 ) ;
if ( V_2 -> V_16 -> V_51 )
V_2 -> V_16 -> V_51 ( V_2 ) ;
}
}
int F_37 ( struct V_1 * V_2 , int V_52 )
{
int V_38 ;
unsigned long V_53 = 0 ;
if ( ! F_26 ( V_2 , V_54 ) )
return - V_55 ;
if ( V_52 == 0 )
return - V_55 ;
if ( ! V_2 -> V_56 )
return - V_55 ;
if ( V_2 -> V_48 )
return - V_57 ;
V_2 -> V_48 = true ;
F_24 ( L_14 , V_52 ) ;
if ( V_2 -> V_16 -> V_50 )
V_2 -> V_16 -> V_50 ( V_2 ) ;
if ( F_26 ( V_2 , V_58 ) )
V_53 = V_59 ;
V_38 = F_38 ( V_52 , V_2 -> V_16 -> V_60 ,
V_53 , V_2 -> V_16 -> V_61 , V_2 ) ;
if ( V_38 < 0 ) {
V_2 -> V_48 = false ;
return V_38 ;
}
if ( F_26 ( V_2 , V_62 ) )
F_39 ( V_2 -> V_63 , ( void * ) V_2 , F_36 , NULL ) ;
if ( V_2 -> V_16 -> V_51 )
V_38 = V_2 -> V_16 -> V_51 ( V_2 ) ;
if ( V_38 < 0 ) {
V_2 -> V_48 = false ;
if ( F_26 ( V_2 , V_62 ) )
F_39 ( V_2 -> V_63 , NULL , NULL , NULL ) ;
F_40 ( V_52 , V_2 ) ;
} else {
V_2 -> V_52 = V_52 ;
}
return V_38 ;
}
int F_41 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
bool V_48 ;
int V_40 ;
if ( ! F_26 ( V_2 , V_54 ) )
return - V_55 ;
V_48 = V_2 -> V_48 ;
V_2 -> V_48 = false ;
if ( V_2 -> V_26 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_26 ; V_40 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_40 ] ;
if ( ! V_9 -> V_31 )
continue;
F_15 ( F_26 ( V_2 , V_36 ) ) ;
F_21 ( V_2 , V_40 ) ;
F_42 ( & V_9 -> V_43 ) ;
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
}
if ( ! V_48 )
return - V_55 ;
F_24 ( L_14 , V_2 -> V_52 ) ;
if ( F_26 ( V_2 , V_62 ) )
F_39 ( V_2 -> V_63 , NULL , NULL , NULL ) ;
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
F_40 ( V_2 -> V_52 , V_2 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , void * V_64 ,
struct V_65 * V_66 )
{
struct F_43 * V_67 = V_64 ;
int V_38 = 0 , V_52 ;
if ( ! F_26 ( V_2 , V_54 ) )
return 0 ;
if ( ! F_26 ( V_2 , V_62 ) )
return 0 ;
if ( F_15 ( ! V_2 -> V_63 ) )
return - V_55 ;
switch ( V_67 -> V_68 ) {
case V_69 :
V_52 = V_2 -> V_63 -> V_52 ;
if ( V_2 -> V_70 < F_44 ( 1 , 2 ) &&
V_67 -> V_52 != V_52 )
return - V_55 ;
F_45 ( & V_2 -> V_71 ) ;
V_38 = F_37 ( V_2 , V_52 ) ;
F_46 ( & V_2 -> V_71 ) ;
return V_38 ;
case V_72 :
F_45 ( & V_2 -> V_71 ) ;
V_38 = F_41 ( V_2 ) ;
F_46 ( & V_2 -> V_71 ) ;
return V_38 ;
default:
return - V_55 ;
}
}
void F_47 ( struct V_27 * V_28 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_75 = 0 , V_20 = 0 ;
int V_76 = V_74 -> V_77 ;
if ( ! V_2 -> V_26 )
return;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( V_76 > 0 ) {
int V_78 = V_74 -> V_79 * V_74 -> V_80 ;
V_75 = F_48 ( ( T_2 ) V_74 -> V_79 * 1000000 , V_76 ) ;
V_20 = F_48 ( ( T_2 ) V_78 * 1000000 , V_76 ) ;
if ( V_74 -> V_18 & V_81 )
V_20 /= 2 ;
} else
F_49 ( L_15 ,
V_28 -> V_82 . V_83 ) ;
V_9 -> V_75 = V_75 ;
V_9 -> V_20 = V_20 ;
F_24 ( L_16 ,
V_28 -> V_82 . V_83 , V_74 -> V_79 ,
V_74 -> V_80 , V_74 -> V_84 ) ;
F_24 ( L_17 ,
V_28 -> V_82 . V_83 , V_76 , V_20 , V_75 ) ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_85 ,
struct V_5 * V_86 ,
unsigned V_18 ,
const struct V_73 * V_74 )
{
struct V_5 V_87 ;
T_3 V_88 , V_89 ;
unsigned int V_90 ;
int V_38 = V_91 ;
int V_92 , V_93 , V_40 ;
int V_94 , V_95 ;
if ( V_3 >= V_2 -> V_26 ) {
F_49 ( L_18 , V_3 ) ;
return - V_55 ;
}
if ( ! V_2 -> V_16 -> V_96 ) {
F_49 ( L_19 ) ;
return - V_97 ;
}
if ( V_74 -> V_77 == 0 ) {
F_24 ( L_20 , V_3 ) ;
return - V_98 ;
}
for ( V_40 = 0 ; V_40 < V_15 ; V_40 ++ ) {
V_90 = V_2 -> V_16 -> V_96 ( V_2 , V_3 , V_18 ,
& V_92 , & V_93 ,
& V_88 , & V_89 ,
V_74 ) ;
if ( ! ( V_90 & V_99 ) ) {
F_24 ( L_21 ,
V_3 , V_90 ) ;
return - V_97 ;
}
V_95 = F_51 ( V_89 ) - F_51 ( V_88 ) ;
if ( V_95 <= * V_85 )
break;
}
if ( V_40 == V_15 ) {
F_24 ( L_22 ,
V_3 , V_95 / 1000 , * V_85 / 1000 , V_40 ) ;
}
* V_85 = V_95 ;
if ( V_90 & V_100 )
V_38 |= V_101 ;
V_94 = F_52 ( 1000000LL * ( V_92 * V_74 -> V_79 + V_93 ) ,
V_74 -> V_77 ) ;
if ( ! V_102 )
V_89 = F_53 ( V_89 ) ;
V_87 = F_54 ( V_89 ) ;
V_89 = F_55 ( V_89 , V_94 ) ;
* V_86 = F_54 ( V_89 ) ;
F_12 ( L_23 ,
V_3 , V_90 , V_93 , V_92 ,
( long ) V_87 . V_103 , ( long ) V_87 . V_104 ,
( long ) V_86 -> V_103 , ( long ) V_86 -> V_104 ,
V_95 / 1000 , V_40 ) ;
return V_38 ;
}
static struct V_5 F_56 ( void )
{
T_3 V_105 ;
V_105 = V_102 ? F_57 () : F_58 () ;
return F_54 ( V_105 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_106 , unsigned V_18 )
{
int V_38 ;
int V_85 = ( int ) V_107 * 1000 ;
if ( V_2 -> V_16 -> V_29 && ( V_85 > 0 ) ) {
V_38 = V_2 -> V_16 -> V_29 ( V_2 , V_3 , & V_85 ,
V_106 , V_18 ) ;
if ( V_38 > 0 )
return true ;
}
* V_106 = F_56 () ;
return false ;
}
T_1 F_59 ( struct V_27 * V_28 )
{
return F_14 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
static T_1 F_60 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_108 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_109 ;
unsigned int V_110 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) ) {
* V_108 = (struct V_5 ) { 0 } ;
return 0 ;
}
do {
V_110 = F_61 ( & V_9 -> V_11 ) ;
V_109 = V_9 -> V_12 ;
* V_108 = V_9 -> time ;
} while ( F_62 ( & V_9 -> V_11 , V_110 ) );
return V_109 ;
}
T_1 F_63 ( struct V_27 * V_28 ,
struct V_5 * V_108 )
{
return F_60 ( V_28 -> V_2 , F_17 ( V_28 ) ,
V_108 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
unsigned long V_110 , struct V_5 * V_105 )
{
V_112 -> V_113 . V_114 = V_110 ;
V_112 -> V_113 . V_103 = V_105 -> V_103 ;
V_112 -> V_113 . V_104 = V_105 -> V_104 ;
F_65 ( V_112 -> V_82 . V_115 , V_112 -> V_3 ,
V_112 -> V_113 . V_114 ) ;
F_66 ( V_2 , & V_112 -> V_82 ) ;
}
void F_67 ( struct V_27 * V_28 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
F_2 ( & V_2 -> V_116 ) ;
V_112 -> V_3 = V_3 ;
V_112 -> V_113 . V_114 = F_14 ( V_2 , V_3 ) ;
F_68 ( & V_112 -> V_82 . V_117 , & V_2 -> V_118 ) ;
}
void F_69 ( struct V_27 * V_28 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_110 , V_3 = F_17 ( V_28 ) ;
struct V_5 V_105 ;
if ( V_2 -> V_26 > 0 ) {
V_110 = F_60 ( V_2 , V_3 , & V_105 ) ;
} else {
V_110 = 0 ;
V_105 = F_56 () ;
}
V_112 -> V_3 = V_3 ;
F_64 ( V_2 , V_112 , V_110 , & V_105 ) ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_38 = 0 ;
F_2 ( & V_2 -> V_34 ) ;
F_6 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_31 ) {
V_38 = V_2 -> V_16 -> V_119 ( V_2 , V_3 ) ;
F_24 ( L_24 , V_3 , V_38 ) ;
if ( V_38 )
F_71 ( & V_9 -> V_35 ) ;
else {
V_9 -> V_31 = true ;
F_9 ( V_2 , V_3 , 0 ) ;
}
}
F_8 ( & V_2 -> V_10 ) ;
return V_38 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
int V_38 = 0 ;
if ( ! V_2 -> V_26 )
return - V_55 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return - V_55 ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
if ( F_73 ( 1 , & V_9 -> V_35 ) == 1 ) {
V_38 = F_70 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_31 ) {
F_71 ( & V_9 -> V_35 ) ;
V_38 = - V_55 ;
}
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
return V_38 ;
}
int F_74 ( struct V_27 * V_28 )
{
return F_72 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
static void F_75 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( F_15 ( F_23 ( & V_9 -> V_35 ) == 0 ) )
return;
if ( F_76 ( & V_9 -> V_35 ) ) {
if ( V_120 == 0 )
return;
else if ( V_2 -> V_44 || V_120 < 0 )
F_22 ( ( unsigned long ) V_9 ) ;
else
F_77 ( & V_9 -> V_37 ,
V_121 + ( ( V_120 * V_122 ) / 1000 ) ) ;
}
}
void F_78 ( struct V_27 * V_28 )
{
F_75 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
void F_79 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_38 ;
T_1 V_7 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
V_38 = F_72 ( V_2 , V_3 ) ;
if ( F_18 ( V_38 , L_25 , V_3 , V_38 ) )
return;
V_7 = F_14 ( V_2 , V_3 ) ;
V_38 = F_80 ( V_9 -> V_43 ,
V_7 != F_14 ( V_2 , V_3 ) ,
F_81 ( 100 ) ) ;
F_18 ( V_38 == 0 , L_26 , V_3 ) ;
F_75 ( V_2 , V_3 ) ;
}
void F_82 ( struct V_27 * V_28 )
{
F_79 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
void F_83 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_111 * V_112 , * V_123 ;
struct V_5 V_105 ;
unsigned long V_30 ;
unsigned int V_110 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
F_19 ( & V_2 -> V_116 , V_30 ) ;
F_6 ( & V_2 -> V_34 ) ;
F_12 ( L_27 ,
V_3 , V_9 -> V_31 , V_9 -> V_25 ) ;
if ( F_26 ( V_2 , V_124 ) || ! V_9 -> V_25 )
F_21 ( V_2 , V_3 ) ;
F_42 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_25 ) {
F_84 ( & V_9 -> V_35 ) ;
V_9 -> V_25 = 1 ;
}
F_8 ( & V_2 -> V_34 ) ;
V_110 = F_60 ( V_2 , V_3 , & V_105 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_112 -> V_3 != V_3 )
continue;
F_24 ( L_28
L_29 ,
V_112 -> V_113 . V_114 , V_110 ) ;
F_86 ( & V_112 -> V_82 . V_117 ) ;
F_75 ( V_2 , V_3 ) ;
F_64 ( V_2 , V_112 , V_110 , & V_105 ) ;
}
F_20 ( & V_2 -> V_116 , V_30 ) ;
}
void F_87 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_30 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
if ( ! V_9 -> V_25 ) {
F_84 ( & V_9 -> V_35 ) ;
V_9 -> V_25 = 1 ;
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
F_15 ( ! F_88 ( & V_2 -> V_118 ) ) ;
}
void F_89 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
F_19 ( & V_2 -> V_34 , V_30 ) ;
F_12 ( L_27 ,
V_3 , V_9 -> V_31 , V_9 -> V_25 ) ;
if ( V_9 -> V_25 ) {
F_71 ( & V_9 -> V_35 ) ;
V_9 -> V_25 = 0 ;
}
F_5 ( V_2 , V_3 ) ;
if ( F_23 ( & V_9 -> V_35 ) != 0 || V_120 == 0 )
F_15 ( F_70 ( V_2 , V_3 ) ) ;
F_20 ( & V_2 -> V_34 , V_30 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_26 )
return;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( ! V_9 -> V_25 ) {
V_9 -> V_25 = 0x1 ;
if ( F_72 ( V_2 , V_3 ) == 0 )
V_9 -> V_25 |= 0x2 ;
}
}
static void F_91 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
if ( ! V_2 -> V_26 )
return;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( V_9 -> V_25 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
F_5 ( V_2 , V_3 ) ;
F_20 ( & V_2 -> V_34 , V_30 ) ;
if ( V_9 -> V_25 & 0x2 )
F_75 ( V_2 , V_3 ) ;
V_9 -> V_25 = 0 ;
}
}
int F_92 ( struct V_1 * V_2 , void * V_64 ,
struct V_65 * V_66 )
{
struct F_92 * V_125 = V_64 ;
unsigned int V_3 ;
if ( ! V_2 -> V_26 )
return 0 ;
if ( ! F_26 ( V_2 , V_62 ) )
return 0 ;
V_3 = V_125 -> V_28 ;
if ( V_3 >= V_2 -> V_26 )
return - V_55 ;
switch ( V_125 -> V_126 ) {
case V_127 :
F_90 ( V_2 , V_3 ) ;
break;
case V_128 :
F_91 ( V_2 , V_3 ) ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_129 * V_130 ,
struct V_65 * V_66 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_111 * V_112 ;
struct V_5 V_105 ;
unsigned long V_18 ;
unsigned int V_110 ;
int V_38 ;
V_112 = F_94 ( sizeof( * V_112 ) , V_41 ) ;
if ( V_112 == NULL ) {
V_38 = - V_39 ;
goto V_131;
}
V_112 -> V_3 = V_3 ;
V_112 -> V_82 . V_115 = V_132 -> V_115 ;
V_112 -> V_113 . V_82 . type = V_133 ;
V_112 -> V_113 . V_82 . V_134 = sizeof( V_112 -> V_113 ) ;
V_112 -> V_113 . V_135 = V_130 -> V_136 . signal ;
F_19 ( & V_2 -> V_116 , V_18 ) ;
if ( ! V_9 -> V_31 ) {
V_38 = - V_55 ;
goto V_137;
}
V_38 = F_95 ( V_2 , V_66 , & V_112 -> V_82 ,
& V_112 -> V_113 . V_82 ) ;
if ( V_38 )
goto V_137;
V_110 = F_60 ( V_2 , V_3 , & V_105 ) ;
F_24 ( L_30 ,
V_130 -> V_136 . V_114 , V_110 , V_3 ) ;
F_96 ( V_132 -> V_115 , V_3 ,
V_130 -> V_136 . V_114 ) ;
V_112 -> V_113 . V_114 = V_130 -> V_136 . V_114 ;
if ( ( V_110 - V_130 -> V_136 . V_114 ) <= ( 1 << 23 ) ) {
F_75 ( V_2 , V_3 ) ;
F_64 ( V_2 , V_112 , V_110 , & V_105 ) ;
V_130 -> V_138 . V_114 = V_110 ;
} else {
F_68 ( & V_112 -> V_82 . V_117 , & V_2 -> V_118 ) ;
V_130 -> V_138 . V_114 = V_130 -> V_136 . V_114 ;
}
F_20 ( & V_2 -> V_116 , V_18 ) ;
return 0 ;
V_137:
F_20 ( & V_2 -> V_116 , V_18 ) ;
F_28 ( V_112 ) ;
V_131:
F_75 ( V_2 , V_3 ) ;
return V_38 ;
}
int V_129 ( struct V_1 * V_2 , void * V_64 ,
struct V_65 * V_66 )
{
struct V_8 * V_9 ;
union V_129 * V_130 = V_64 ;
int V_38 ;
unsigned int V_18 , V_110 , V_3 , V_139 ;
if ( ! V_2 -> V_48 )
return - V_55 ;
if ( V_130 -> V_136 . type & V_140 )
return - V_55 ;
if ( V_130 -> V_136 . type &
~ ( V_141 | V_142 |
V_143 ) ) {
F_49 ( L_31 ,
V_130 -> V_136 . type ,
( V_141 | V_142 |
V_143 ) ) ;
return - V_55 ;
}
V_18 = V_130 -> V_136 . type & V_142 ;
V_139 = ( V_130 -> V_136 . type & V_143 ) ;
if ( V_139 )
V_3 = V_139 >> V_144 ;
else
V_3 = V_18 & V_145 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_26 )
return - V_55 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
V_38 = F_72 ( V_2 , V_3 ) ;
if ( V_38 ) {
F_24 ( L_32 , V_38 ) ;
return V_38 ;
}
V_110 = F_14 ( V_2 , V_3 ) ;
switch ( V_130 -> V_136 . type & V_141 ) {
case V_146 :
V_130 -> V_136 . V_114 += V_110 ;
V_130 -> V_136 . type &= ~ V_146 ;
case V_147 :
break;
default:
V_38 = - V_55 ;
goto V_148;
}
if ( ( V_18 & V_149 ) &&
( V_110 - V_130 -> V_136 . V_114 ) <= ( 1 << 23 ) ) {
V_130 -> V_136 . V_114 = V_110 + 1 ;
}
if ( V_18 & V_150 ) {
return F_93 ( V_2 , V_3 , V_130 , V_66 ) ;
}
F_24 ( L_33 ,
V_130 -> V_136 . V_114 , V_3 ) ;
F_97 ( V_38 , V_9 -> V_43 , 3 * V_122 ,
( ( ( F_14 ( V_2 , V_3 ) -
V_130 -> V_136 . V_114 ) <= ( 1 << 23 ) ) ||
! V_9 -> V_31 ||
! V_2 -> V_48 ) ) ;
if ( V_38 != - V_151 ) {
struct V_5 V_105 ;
V_130 -> V_138 . V_114 = F_60 ( V_2 , V_3 , & V_105 ) ;
V_130 -> V_138 . V_152 = V_105 . V_103 ;
V_130 -> V_138 . V_153 = V_105 . V_104 ;
F_24 ( L_34 ,
V_130 -> V_138 . V_114 ) ;
} else {
F_24 ( L_35 ) ;
}
V_148:
F_75 ( V_2 , V_3 ) ;
return V_38 ;
}
static void F_98 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_111 * V_112 , * V_123 ;
struct V_5 V_105 ;
unsigned int V_110 ;
F_2 ( & V_2 -> V_116 ) ;
V_110 = F_60 ( V_2 , V_3 , & V_105 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_112 -> V_3 != V_3 )
continue;
if ( ( V_110 - V_112 -> V_113 . V_114 ) > ( 1 << 23 ) )
continue;
F_24 ( L_36 ,
V_112 -> V_113 . V_114 , V_110 ) ;
F_86 ( & V_112 -> V_82 . V_117 ) ;
F_75 ( V_2 , V_3 ) ;
F_64 ( V_2 , V_112 , V_110 , & V_105 ) ;
}
F_99 ( V_3 , V_110 ) ;
}
bool F_100 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
if ( F_13 ( ! V_2 -> V_26 ) )
return false ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return false ;
F_19 ( & V_2 -> V_116 , V_30 ) ;
F_6 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_31 ) {
F_8 ( & V_2 -> V_10 ) ;
F_20 ( & V_2 -> V_116 , V_30 ) ;
return false ;
}
F_9 ( V_2 , V_3 , V_24 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_42 ( & V_9 -> V_43 ) ;
F_98 ( V_2 , V_3 ) ;
F_20 ( & V_2 -> V_116 , V_30 ) ;
return true ;
}
bool F_101 ( struct V_27 * V_28 )
{
return F_100 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
T_1 F_102 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_13 ( V_2 -> V_21 != 0 ) ;
return 0 ;
}
