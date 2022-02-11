static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_10 ;
F_2 ( & V_2 -> V_11 ) ;
V_9 -> V_7 = V_7 ;
V_10 = V_9 -> V_12 + V_4 ;
F_3 ( V_2 , V_3 , V_10 ) = * V_6 ;
F_4 () ;
V_9 -> V_12 += V_4 ;
F_4 () ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_13 ;
bool V_14 ;
struct V_5 V_6 ;
int V_12 = V_15 ;
F_6 ( & V_2 -> V_11 ) ;
do {
V_13 = V_2 -> V_16 -> V_17 ( V_2 , V_3 ) ;
V_14 = F_7 ( V_2 , V_3 , & V_6 , 0 ) ;
} while ( V_13 != V_2 -> V_16 -> V_17 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( ! V_14 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , 1 , & V_6 , V_13 ) ;
F_8 ( & V_2 -> V_11 ) ;
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
V_22 = & F_3 ( V_2 , V_3 , V_9 -> V_12 ) ;
V_23 = F_10 ( & V_6 ) - F_10 ( V_22 ) ;
V_19 = F_11 ( V_23 , V_20 ) ;
if ( V_19 == 0 && V_18 & V_24 )
F_12 ( L_1
L_2 ,
V_3 , ( long long ) V_23 , V_20 ) ;
} else {
V_19 = ( V_18 & V_24 ) != 0 ;
}
F_12 ( L_3
L_4 ,
V_3 , V_9 -> V_12 , V_19 , V_13 , V_9 -> V_7 ) ;
if ( V_19 == 0 ) {
F_13 ( V_13 != V_9 -> V_7 ) ;
return;
}
if ( ! V_14 && ( V_18 & V_24 ) == 0 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , V_19 , & V_6 , V_13 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_25 ;
F_15 ( & V_2 -> V_11 , V_25 ) ;
if ( V_9 -> V_26 ) {
V_2 -> V_16 -> V_27 ( V_2 , V_3 ) ;
V_9 -> V_26 = false ;
}
F_9 ( V_2 , V_3 , 0 ) ;
F_16 ( & V_2 -> V_11 , V_25 ) ;
}
static void F_17 ( unsigned long V_28 )
{
struct V_8 * V_9 = ( void * ) V_28 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_3 = V_9 -> V_3 ;
unsigned long V_25 ;
if ( ! V_2 -> V_29 )
return;
F_15 ( & V_2 -> V_30 , V_25 ) ;
if ( F_18 ( & V_9 -> V_31 ) == 0 && V_9 -> V_26 ) {
F_19 ( L_5 , V_3 ) ;
F_14 ( V_2 , V_3 ) ;
}
F_16 ( & V_2 -> V_30 , V_25 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_32 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_32 ; V_3 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_21 ( V_9 -> V_26 &&
F_22 ( V_2 , V_33 ) ) ;
F_23 ( & V_9 -> V_34 ) ;
}
F_24 ( V_2 -> V_9 ) ;
V_2 -> V_32 = 0 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_32 )
{
int V_35 = - V_36 ;
unsigned int V_37 ;
F_26 ( & V_2 -> V_30 ) ;
F_26 ( & V_2 -> V_11 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_9 = F_27 ( V_32 , sizeof( * V_2 -> V_9 ) , V_38 ) ;
if ( ! V_2 -> V_9 )
goto V_39;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_37 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_3 = V_37 ;
F_28 ( & V_9 -> V_40 ) ;
F_29 ( & V_9 -> V_34 , F_17 ,
( unsigned long ) V_9 ) ;
}
F_30 ( L_6 ) ;
if ( V_2 -> V_16 -> V_41 )
F_30 ( L_7 ) ;
else
F_30 ( L_8 ) ;
if ( V_2 -> V_42 && ! V_2 -> V_16 -> V_41 ) {
V_2 -> V_42 = false ;
F_30 ( L_9
L_10 ) ;
}
V_2 -> V_29 = false ;
return 0 ;
V_39:
V_2 -> V_32 = 0 ;
return V_35 ;
}
static void F_31 ( void * V_43 , bool V_44 )
{
struct V_1 * V_2 = V_43 ;
if ( V_2 -> V_16 -> V_45 ) {
V_2 -> V_16 -> V_45 ( V_2 , V_44 ) ;
return;
}
if ( ! V_2 -> V_46 )
return;
if ( V_44 ) {
if ( V_2 -> V_16 -> V_47 )
V_2 -> V_16 -> V_47 ( V_2 ) ;
} else {
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
}
}
int F_32 ( struct V_1 * V_2 , int V_50 )
{
int V_35 ;
unsigned long V_51 = 0 ;
if ( ! F_22 ( V_2 , V_52 ) )
return - V_53 ;
if ( V_50 == 0 )
return - V_53 ;
if ( ! V_2 -> V_54 )
return - V_53 ;
if ( V_2 -> V_46 )
return - V_55 ;
V_2 -> V_46 = true ;
F_19 ( L_11 , V_50 ) ;
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
if ( F_22 ( V_2 , V_56 ) )
V_51 = V_57 ;
V_35 = F_33 ( V_50 , V_2 -> V_16 -> V_58 ,
V_51 , V_2 -> V_16 -> V_59 , V_2 ) ;
if ( V_35 < 0 ) {
V_2 -> V_46 = false ;
return V_35 ;
}
if ( ! F_22 ( V_2 , V_33 ) )
F_34 ( V_2 -> V_60 , ( void * ) V_2 , F_31 , NULL ) ;
if ( V_2 -> V_16 -> V_49 )
V_35 = V_2 -> V_16 -> V_49 ( V_2 ) ;
if ( V_35 < 0 ) {
V_2 -> V_46 = false ;
if ( ! F_22 ( V_2 , V_33 ) )
F_34 ( V_2 -> V_60 , NULL , NULL , NULL ) ;
F_35 ( V_50 , V_2 ) ;
} else {
V_2 -> V_50 = V_50 ;
}
return V_35 ;
}
int F_36 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
bool V_46 ;
int V_37 ;
if ( ! F_22 ( V_2 , V_52 ) )
return - V_53 ;
V_46 = V_2 -> V_46 ;
V_2 -> V_46 = false ;
if ( V_2 -> V_32 ) {
F_15 ( & V_2 -> V_30 , V_25 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 ; V_37 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_37 ] ;
if ( ! V_9 -> V_26 )
continue;
F_21 ( F_22 ( V_2 , V_33 ) ) ;
F_14 ( V_2 , V_37 ) ;
F_37 ( & V_9 -> V_40 ) ;
}
F_16 ( & V_2 -> V_30 , V_25 ) ;
}
if ( ! V_46 )
return - V_53 ;
F_19 ( L_11 , V_2 -> V_50 ) ;
if ( ! F_22 ( V_2 , V_33 ) )
F_34 ( V_2 -> V_60 , NULL , NULL , NULL ) ;
if ( V_2 -> V_16 -> V_47 )
V_2 -> V_16 -> V_47 ( V_2 ) ;
F_35 ( V_2 -> V_50 , V_2 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct F_38 * V_64 = V_61 ;
int V_35 = 0 , V_50 ;
if ( ! F_22 ( V_2 , V_52 ) )
return 0 ;
if ( F_22 ( V_2 , V_33 ) )
return 0 ;
if ( F_21 ( ! V_2 -> V_60 ) )
return - V_53 ;
switch ( V_64 -> V_65 ) {
case V_66 :
V_50 = V_2 -> V_60 -> V_50 ;
if ( V_2 -> V_67 < F_39 ( 1 , 2 ) &&
V_64 -> V_50 != V_50 )
return - V_53 ;
F_40 ( & V_2 -> V_68 ) ;
V_35 = F_32 ( V_2 , V_50 ) ;
F_41 ( & V_2 -> V_68 ) ;
return V_35 ;
case V_69 :
F_40 ( & V_2 -> V_68 ) ;
V_35 = F_36 ( V_2 ) ;
F_41 ( & V_2 -> V_68 ) ;
return V_35 ;
default:
return - V_53 ;
}
}
void F_42 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
unsigned int V_3 = F_43 ( V_71 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_74 = 0 , V_20 = 0 ;
int V_75 = V_73 -> V_76 ;
if ( ! V_2 -> V_32 )
return;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
if ( V_75 > 0 ) {
int V_77 = V_73 -> V_78 * V_73 -> V_79 ;
V_74 = F_44 ( ( T_2 ) V_73 -> V_78 * 1000000 , V_75 ) ;
V_20 = F_44 ( ( T_2 ) V_77 * 1000000 , V_75 ) ;
if ( V_73 -> V_18 & V_80 )
V_20 /= 2 ;
} else
F_45 ( L_12 ,
V_71 -> V_81 . V_82 ) ;
V_9 -> V_74 = V_74 ;
V_9 -> V_20 = V_20 ;
F_19 ( L_13 ,
V_71 -> V_81 . V_82 , V_73 -> V_78 ,
V_73 -> V_79 , V_73 -> V_83 ) ;
F_19 ( L_14 ,
V_71 -> V_81 . V_82 , V_75 , V_20 , V_74 ) ;
}
int F_46 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_84 ,
struct V_5 * V_85 ,
unsigned V_18 ,
const struct V_72 * V_73 )
{
struct V_5 V_86 ;
T_3 V_87 , V_88 ;
unsigned int V_89 ;
int V_35 = V_90 ;
int V_91 , V_92 , V_37 ;
int V_93 , V_94 ;
if ( V_3 >= V_2 -> V_32 ) {
F_45 ( L_15 , V_3 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_16 -> V_95 ) {
F_45 ( L_16 ) ;
return - V_96 ;
}
if ( V_73 -> V_76 == 0 ) {
F_19 ( L_17 , V_3 ) ;
return - V_97 ;
}
for ( V_37 = 0 ; V_37 < V_15 ; V_37 ++ ) {
V_89 = V_2 -> V_16 -> V_95 ( V_2 , V_3 , V_18 ,
& V_91 , & V_92 ,
& V_87 , & V_88 ,
V_73 ) ;
if ( ! ( V_89 & V_98 ) ) {
F_19 ( L_18 ,
V_3 , V_89 ) ;
return - V_96 ;
}
V_94 = F_47 ( V_88 ) - F_47 ( V_87 ) ;
if ( V_94 <= * V_84 )
break;
}
if ( V_37 == V_15 ) {
F_19 ( L_19 ,
V_3 , V_94 / 1000 , * V_84 / 1000 , V_37 ) ;
}
* V_84 = V_94 ;
if ( V_89 & V_99 )
V_35 |= V_100 ;
V_93 = F_48 ( 1000000LL * ( V_91 * V_73 -> V_78 + V_92 ) ,
V_73 -> V_76 ) ;
if ( ! V_101 )
V_88 = F_49 ( V_88 ) ;
V_86 = F_50 ( V_88 ) ;
if ( V_93 < 0 )
V_88 = F_51 ( V_88 , - V_93 ) ;
else
V_88 = F_52 ( V_88 , V_93 ) ;
* V_85 = F_50 ( V_88 ) ;
F_12 ( L_20 ,
V_3 , V_89 , V_92 , V_91 ,
( long ) V_86 . V_102 , ( long ) V_86 . V_103 ,
( long ) V_85 -> V_102 , ( long ) V_85 -> V_103 ,
V_94 / 1000 , V_37 ) ;
return V_35 ;
}
static struct V_5 F_53 ( void )
{
T_3 V_104 ;
V_104 = V_101 ? F_54 () : F_55 () ;
return F_50 ( V_104 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_105 , unsigned V_18 )
{
int V_35 ;
int V_84 = ( int ) V_106 * 1000 ;
if ( V_2 -> V_16 -> V_41 && ( V_84 > 0 ) ) {
V_35 = V_2 -> V_16 -> V_41 ( V_2 , V_3 , & V_84 ,
V_105 , V_18 ) ;
if ( V_35 > 0 )
return true ;
}
* V_105 = F_53 () ;
return false ;
}
T_1 F_56 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return 0 ;
return V_9 -> V_12 ;
}
T_1 F_57 ( struct V_70 * V_71 )
{
return F_56 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
T_1 F_58 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_107 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_12 = V_15 ;
T_1 V_13 ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return 0 ;
do {
V_13 = V_9 -> V_12 ;
F_59 () ;
* V_107 = F_3 ( V_2 , V_3 , V_13 ) ;
F_59 () ;
} while ( V_13 != V_9 -> V_12 && -- V_12 > 0 );
return V_13 ;
}
T_1 F_60 ( struct V_70 * V_71 ,
struct V_5 * V_107 )
{
return F_58 ( V_71 -> V_2 , F_43 ( V_71 ) ,
V_107 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
unsigned long V_110 , struct V_5 * V_104 )
{
F_2 ( & V_2 -> V_111 ) ;
V_109 -> V_112 . V_113 = V_110 ;
V_109 -> V_112 . V_102 = V_104 -> V_102 ;
V_109 -> V_112 . V_103 = V_104 -> V_103 ;
F_62 ( & V_109 -> V_81 . V_114 ,
& V_109 -> V_81 . V_63 -> V_115 ) ;
F_63 ( & V_109 -> V_81 . V_63 -> V_116 ) ;
F_64 ( V_109 -> V_81 . V_117 , V_109 -> V_3 ,
V_109 -> V_112 . V_113 ) ;
}
void F_65 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_108 * V_109 )
{
F_2 ( & V_2 -> V_111 ) ;
V_109 -> V_3 = V_3 ;
V_109 -> V_112 . V_113 = F_56 ( V_2 , V_3 ) ;
F_62 ( & V_109 -> V_81 . V_114 , & V_2 -> V_118 ) ;
}
void F_66 ( struct V_70 * V_71 ,
struct V_108 * V_109 )
{
F_65 ( V_71 -> V_2 , F_43 ( V_71 ) , V_109 ) ;
}
void F_67 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_108 * V_109 )
{
struct V_5 V_104 ;
unsigned int V_110 ;
if ( V_2 -> V_32 > 0 ) {
V_110 = F_58 ( V_2 , V_3 , & V_104 ) ;
} else {
V_110 = 0 ;
V_104 = F_53 () ;
}
V_109 -> V_3 = V_3 ;
F_61 ( V_2 , V_109 , V_110 , & V_104 ) ;
}
void F_68 ( struct V_70 * V_71 ,
struct V_108 * V_109 )
{
F_67 ( V_71 -> V_2 , F_43 ( V_71 ) , V_109 ) ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_35 = 0 ;
F_2 ( & V_2 -> V_30 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( ! V_9 -> V_26 ) {
V_35 = V_2 -> V_16 -> V_119 ( V_2 , V_3 ) ;
F_19 ( L_21 , V_3 , V_35 ) ;
if ( V_35 )
F_70 ( & V_9 -> V_31 ) ;
else {
V_9 -> V_26 = true ;
F_9 ( V_2 , V_3 , 0 ) ;
}
}
F_8 ( & V_2 -> V_11 ) ;
return V_35 ;
}
int F_71 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_25 ;
int V_35 = 0 ;
if ( ! V_2 -> V_32 )
return - V_53 ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return - V_53 ;
F_15 ( & V_2 -> V_30 , V_25 ) ;
if ( F_72 ( 1 , & V_9 -> V_31 ) == 1 ) {
V_35 = F_69 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_26 ) {
F_70 ( & V_9 -> V_31 ) ;
V_35 = - V_53 ;
}
}
F_16 ( & V_2 -> V_30 , V_25 ) ;
return V_35 ;
}
int F_73 ( struct V_70 * V_71 )
{
return F_71 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
void F_74 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
if ( F_21 ( F_18 ( & V_9 -> V_31 ) == 0 ) )
return;
if ( F_75 ( & V_9 -> V_31 ) ) {
if ( V_120 == 0 )
return;
else if ( V_2 -> V_42 || V_120 < 0 )
F_17 ( ( unsigned long ) V_9 ) ;
else
F_76 ( & V_9 -> V_34 ,
V_121 + ( ( V_120 * V_122 ) / 1000 ) ) ;
}
}
void F_77 ( struct V_70 * V_71 )
{
F_74 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
void F_78 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_35 ;
T_1 V_7 ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
V_35 = F_71 ( V_2 , V_3 ) ;
if ( F_79 ( V_35 , L_22 , V_3 , V_35 ) )
return;
V_7 = F_56 ( V_2 , V_3 ) ;
V_35 = F_80 ( V_9 -> V_40 ,
V_7 != F_56 ( V_2 , V_3 ) ,
F_81 ( 100 ) ) ;
F_79 ( V_35 == 0 , L_23 , V_3 ) ;
F_74 ( V_2 , V_3 ) ;
}
void F_82 ( struct V_70 * V_71 )
{
F_78 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
void F_83 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_108 * V_109 , * V_123 ;
struct V_5 V_104 ;
unsigned long V_25 ;
unsigned int V_110 ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
F_15 ( & V_2 -> V_111 , V_25 ) ;
F_6 ( & V_2 -> V_30 ) ;
F_14 ( V_2 , V_3 ) ;
F_37 ( & V_9 -> V_40 ) ;
if ( ! V_9 -> V_124 ) {
F_84 ( & V_9 -> V_31 ) ;
V_9 -> V_124 = 1 ;
}
F_8 ( & V_2 -> V_30 ) ;
V_110 = F_58 ( V_2 , V_3 , & V_104 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_109 -> V_3 != V_3 )
continue;
F_19 ( L_24
L_25 ,
V_109 -> V_112 . V_113 , V_110 ) ;
F_86 ( & V_109 -> V_81 . V_114 ) ;
F_74 ( V_2 , V_3 ) ;
F_61 ( V_2 , V_109 , V_110 , & V_104 ) ;
}
F_16 ( & V_2 -> V_111 , V_25 ) ;
}
void F_87 ( struct V_70 * V_71 )
{
F_83 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
void F_88 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
unsigned long V_25 ;
unsigned int V_3 = F_43 ( V_71 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_15 ( & V_2 -> V_30 , V_25 ) ;
if ( ! V_9 -> V_124 ) {
F_84 ( & V_9 -> V_31 ) ;
V_9 -> V_124 = 1 ;
}
F_16 ( & V_2 -> V_30 , V_25 ) ;
F_21 ( ! F_89 ( & V_2 -> V_118 ) ) ;
}
void F_90 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_25 ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
F_15 ( & V_2 -> V_30 , V_25 ) ;
if ( V_9 -> V_124 ) {
F_70 ( & V_9 -> V_31 ) ;
V_9 -> V_124 = 0 ;
}
F_5 ( V_2 , V_3 ) ;
if ( F_18 ( & V_9 -> V_31 ) != 0 ||
( ! V_2 -> V_42 && V_120 == 0 ) )
F_21 ( F_69 ( V_2 , V_3 ) ) ;
F_16 ( & V_2 -> V_30 , V_25 ) ;
}
void F_91 ( struct V_70 * V_71 )
{
F_90 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
void F_92 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_32 )
return;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
if ( ! V_9 -> V_124 ) {
V_9 -> V_124 = 0x1 ;
if ( F_71 ( V_2 , V_3 ) == 0 )
V_9 -> V_124 |= 0x2 ;
}
}
void F_93 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_25 ;
if ( ! V_2 -> V_32 )
return;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return;
if ( V_9 -> V_124 ) {
F_15 ( & V_2 -> V_30 , V_25 ) ;
V_2 -> V_29 = true ;
F_16 ( & V_2 -> V_30 , V_25 ) ;
if ( V_9 -> V_124 & 0x2 )
F_74 ( V_2 , V_3 ) ;
V_9 -> V_124 = 0 ;
}
}
int F_94 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct F_94 * V_125 = V_61 ;
unsigned int V_3 ;
if ( ! V_2 -> V_32 )
return 0 ;
if ( F_22 ( V_2 , V_33 ) )
return 0 ;
V_3 = V_125 -> V_71 ;
if ( V_3 >= V_2 -> V_32 )
return - V_53 ;
switch ( V_125 -> V_126 ) {
case V_127 :
F_92 ( V_2 , V_3 ) ;
break;
case V_128 :
F_93 ( V_2 , V_3 ) ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_129 * V_130 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_108 * V_109 ;
struct V_5 V_104 ;
unsigned long V_18 ;
unsigned int V_110 ;
int V_35 ;
V_109 = F_96 ( sizeof( * V_109 ) , V_38 ) ;
if ( V_109 == NULL ) {
V_35 = - V_36 ;
goto V_131;
}
V_109 -> V_3 = V_3 ;
V_109 -> V_81 . V_117 = V_132 -> V_117 ;
V_109 -> V_112 . V_81 . type = V_133 ;
V_109 -> V_112 . V_81 . V_134 = sizeof( V_109 -> V_112 ) ;
V_109 -> V_112 . V_135 = V_130 -> V_136 . signal ;
V_109 -> V_81 . V_112 = & V_109 -> V_112 . V_81 ;
V_109 -> V_81 . V_63 = V_63 ;
V_109 -> V_81 . V_137 = ( void ( * ) ( struct V_138 * ) ) F_24 ;
F_15 ( & V_2 -> V_111 , V_18 ) ;
if ( ! V_9 -> V_26 ) {
V_35 = - V_53 ;
goto V_139;
}
if ( V_63 -> V_140 < sizeof( V_109 -> V_112 ) ) {
V_35 = - V_55 ;
goto V_139;
}
V_63 -> V_140 -= sizeof( V_109 -> V_112 ) ;
V_110 = F_58 ( V_2 , V_3 , & V_104 ) ;
if ( ( V_130 -> V_136 . type & V_141 ) &&
( V_110 - V_130 -> V_136 . V_113 ) <= ( 1 << 23 ) ) {
V_130 -> V_136 . V_113 = V_110 + 1 ;
V_130 -> V_142 . V_113 = V_130 -> V_136 . V_113 ;
}
F_19 ( L_26 ,
V_130 -> V_136 . V_113 , V_110 , V_3 ) ;
F_97 ( V_132 -> V_117 , V_3 ,
V_130 -> V_136 . V_113 ) ;
V_109 -> V_112 . V_113 = V_130 -> V_136 . V_113 ;
if ( ( V_110 - V_130 -> V_136 . V_113 ) <= ( 1 << 23 ) ) {
F_74 ( V_2 , V_3 ) ;
F_61 ( V_2 , V_109 , V_110 , & V_104 ) ;
V_130 -> V_142 . V_113 = V_110 ;
} else {
F_62 ( & V_109 -> V_81 . V_114 , & V_2 -> V_118 ) ;
V_130 -> V_142 . V_113 = V_130 -> V_136 . V_113 ;
}
F_16 ( & V_2 -> V_111 , V_18 ) ;
return 0 ;
V_139:
F_16 ( & V_2 -> V_111 , V_18 ) ;
F_24 ( V_109 ) ;
V_131:
F_74 ( V_2 , V_3 ) ;
return V_35 ;
}
int V_129 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 ;
union V_129 * V_130 = V_61 ;
int V_35 ;
unsigned int V_18 , V_110 , V_3 , V_143 ;
if ( ! V_2 -> V_46 )
return - V_53 ;
if ( V_130 -> V_136 . type & V_144 )
return - V_53 ;
if ( V_130 -> V_136 . type &
~ ( V_145 | V_146 |
V_147 ) ) {
F_45 ( L_27 ,
V_130 -> V_136 . type ,
( V_145 | V_146 |
V_147 ) ) ;
return - V_53 ;
}
V_18 = V_130 -> V_136 . type & V_146 ;
V_143 = ( V_130 -> V_136 . type & V_147 ) ;
if ( V_143 )
V_3 = V_143 >> V_148 ;
else
V_3 = V_18 & V_149 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_32 )
return - V_53 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
V_35 = F_71 ( V_2 , V_3 ) ;
if ( V_35 ) {
F_19 ( L_28 , V_35 ) ;
return V_35 ;
}
V_110 = F_56 ( V_2 , V_3 ) ;
switch ( V_130 -> V_136 . type & V_145 ) {
case V_150 :
V_130 -> V_136 . V_113 += V_110 ;
V_130 -> V_136 . type &= ~ V_150 ;
case V_151 :
break;
default:
V_35 = - V_53 ;
goto V_152;
}
if ( V_18 & V_153 ) {
return F_95 ( V_2 , V_3 , V_130 , V_63 ) ;
}
if ( ( V_18 & V_141 ) &&
( V_110 - V_130 -> V_136 . V_113 ) <= ( 1 << 23 ) ) {
V_130 -> V_136 . V_113 = V_110 + 1 ;
}
F_19 ( L_29 ,
V_130 -> V_136 . V_113 , V_3 ) ;
V_9 -> V_154 = V_130 -> V_136 . V_113 ;
F_98 ( V_35 , V_9 -> V_40 , 3 * V_122 ,
( ( ( F_56 ( V_2 , V_3 ) -
V_130 -> V_136 . V_113 ) <= ( 1 << 23 ) ) ||
! V_9 -> V_26 ||
! V_2 -> V_46 ) ) ;
if ( V_35 != - V_155 ) {
struct V_5 V_104 ;
V_130 -> V_142 . V_113 = F_58 ( V_2 , V_3 , & V_104 ) ;
V_130 -> V_142 . V_156 = V_104 . V_102 ;
V_130 -> V_142 . V_157 = V_104 . V_103 ;
F_19 ( L_30 ,
V_130 -> V_142 . V_113 ) ;
} else {
F_19 ( L_31 ) ;
}
V_152:
F_74 ( V_2 , V_3 ) ;
return V_35 ;
}
static void F_99 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_108 * V_109 , * V_123 ;
struct V_5 V_104 ;
unsigned int V_110 ;
F_2 ( & V_2 -> V_111 ) ;
V_110 = F_58 ( V_2 , V_3 , & V_104 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_109 -> V_3 != V_3 )
continue;
if ( ( V_110 - V_109 -> V_112 . V_113 ) > ( 1 << 23 ) )
continue;
F_19 ( L_32 ,
V_109 -> V_112 . V_113 , V_110 ) ;
F_86 ( & V_109 -> V_81 . V_114 ) ;
F_74 ( V_2 , V_3 ) ;
F_61 ( V_2 , V_109 , V_110 , & V_104 ) ;
}
F_100 ( V_3 , V_110 ) ;
}
bool F_101 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_25 ;
if ( F_13 ( ! V_2 -> V_32 ) )
return false ;
if ( F_21 ( V_3 >= V_2 -> V_32 ) )
return false ;
F_15 ( & V_2 -> V_111 , V_25 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( ! V_9 -> V_26 ) {
F_8 ( & V_2 -> V_11 ) ;
F_16 ( & V_2 -> V_111 , V_25 ) ;
return false ;
}
F_9 ( V_2 , V_3 , V_24 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_37 ( & V_9 -> V_40 ) ;
F_99 ( V_2 , V_3 ) ;
F_16 ( & V_2 -> V_111 , V_25 ) ;
return true ;
}
bool F_102 ( struct V_70 * V_71 )
{
return F_101 ( V_71 -> V_2 , F_43 ( V_71 ) ) ;
}
T_1 F_103 ( struct V_1 * V_2 , unsigned int V_3 )
{
return 0 ;
}
