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
if ( V_19 > 1 && ( V_9 -> V_25 & 0x2 ) ) {
F_12 ( L_3
L_4 , V_3 , V_19 ) ;
V_19 = 1 ;
}
if ( ( V_19 > 1 ) && ( F_13 ( & V_9 -> V_26 ) > 1 ||
( V_18 & V_24 ) ) ) {
F_12 ( L_5
L_6 , V_3 , V_19 ,
F_13 ( & V_9 -> V_26 ) ,
( V_18 & V_24 ) != 0 ) ;
V_19 = 1 ;
}
F_12 ( L_7
L_8 ,
V_3 , V_9 -> V_12 , V_19 , V_13 , V_9 -> V_7 ) ;
if ( V_19 == 0 ) {
F_14 ( V_13 != V_9 -> V_7 ) ;
return;
}
if ( ! V_14 && ( V_18 & V_24 ) == 0 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , V_19 , & V_6 , V_13 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_27 ;
F_16 ( & V_2 -> V_11 , V_27 ) ;
if ( V_9 -> V_28 ) {
V_2 -> V_16 -> V_29 ( V_2 , V_3 ) ;
V_9 -> V_28 = false ;
}
F_9 ( V_2 , V_3 , 0 ) ;
F_17 ( & V_2 -> V_11 , V_27 ) ;
}
static void F_18 ( unsigned long V_30 )
{
struct V_8 * V_9 = ( void * ) V_30 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_3 = V_9 -> V_3 ;
unsigned long V_27 ;
if ( ! V_2 -> V_31 )
return;
F_16 ( & V_2 -> V_32 , V_27 ) ;
if ( F_13 ( & V_9 -> V_26 ) == 0 && V_9 -> V_28 ) {
F_19 ( L_9 , V_3 ) ;
F_15 ( V_2 , V_3 ) ;
}
F_17 ( & V_2 -> V_32 , V_27 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_33 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_33 ; V_3 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_21 ( V_9 -> V_28 &&
F_22 ( V_2 , V_34 ) ) ;
F_23 ( & V_9 -> V_35 ) ;
}
F_24 ( V_2 -> V_9 ) ;
V_2 -> V_33 = 0 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_33 )
{
int V_36 = - V_37 ;
unsigned int V_38 ;
F_26 ( & V_2 -> V_32 ) ;
F_26 ( & V_2 -> V_11 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_9 = F_27 ( V_33 , sizeof( * V_2 -> V_9 ) , V_39 ) ;
if ( ! V_2 -> V_9 )
goto V_40;
for ( V_38 = 0 ; V_38 < V_33 ; V_38 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_38 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_3 = V_38 ;
F_28 ( & V_9 -> V_41 ) ;
F_29 ( & V_9 -> V_35 , F_18 ,
( unsigned long ) V_9 ) ;
}
F_30 ( L_10 ) ;
if ( V_2 -> V_16 -> V_42 )
F_30 ( L_11 ) ;
else
F_30 ( L_12 ) ;
if ( V_2 -> V_43 && ! V_2 -> V_16 -> V_42 ) {
V_2 -> V_43 = false ;
F_30 ( L_13
L_14 ) ;
}
V_2 -> V_31 = false ;
return 0 ;
V_40:
V_2 -> V_33 = 0 ;
return V_36 ;
}
static void F_31 ( void * V_44 , bool V_45 )
{
struct V_1 * V_2 = V_44 ;
if ( V_2 -> V_16 -> V_46 ) {
V_2 -> V_16 -> V_46 ( V_2 , V_45 ) ;
return;
}
if ( ! V_2 -> V_47 )
return;
if ( V_45 ) {
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
} else {
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
if ( V_2 -> V_16 -> V_50 )
V_2 -> V_16 -> V_50 ( V_2 ) ;
}
}
int F_32 ( struct V_1 * V_2 , int V_51 )
{
int V_36 ;
unsigned long V_52 = 0 ;
if ( ! F_22 ( V_2 , V_53 ) )
return - V_54 ;
if ( V_51 == 0 )
return - V_54 ;
if ( ! V_2 -> V_55 )
return - V_54 ;
if ( V_2 -> V_47 )
return - V_56 ;
V_2 -> V_47 = true ;
F_19 ( L_15 , V_51 ) ;
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
if ( F_22 ( V_2 , V_57 ) )
V_52 = V_58 ;
V_36 = F_33 ( V_51 , V_2 -> V_16 -> V_59 ,
V_52 , V_2 -> V_16 -> V_60 , V_2 ) ;
if ( V_36 < 0 ) {
V_2 -> V_47 = false ;
return V_36 ;
}
if ( ! F_22 ( V_2 , V_34 ) )
F_34 ( V_2 -> V_61 , ( void * ) V_2 , F_31 , NULL ) ;
if ( V_2 -> V_16 -> V_50 )
V_36 = V_2 -> V_16 -> V_50 ( V_2 ) ;
if ( V_36 < 0 ) {
V_2 -> V_47 = false ;
if ( ! F_22 ( V_2 , V_34 ) )
F_34 ( V_2 -> V_61 , NULL , NULL , NULL ) ;
F_35 ( V_51 , V_2 ) ;
} else {
V_2 -> V_51 = V_51 ;
}
return V_36 ;
}
int F_36 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
bool V_47 ;
int V_38 ;
if ( ! F_22 ( V_2 , V_53 ) )
return - V_54 ;
V_47 = V_2 -> V_47 ;
V_2 -> V_47 = false ;
if ( V_2 -> V_33 ) {
F_16 ( & V_2 -> V_32 , V_27 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_33 ; V_38 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_38 ] ;
if ( ! V_9 -> V_28 )
continue;
F_21 ( F_22 ( V_2 , V_34 ) ) ;
F_15 ( V_2 , V_38 ) ;
F_37 ( & V_9 -> V_41 ) ;
}
F_17 ( & V_2 -> V_32 , V_27 ) ;
}
if ( ! V_47 )
return - V_54 ;
F_19 ( L_15 , V_2 -> V_51 ) ;
if ( ! F_22 ( V_2 , V_34 ) )
F_34 ( V_2 -> V_61 , NULL , NULL , NULL ) ;
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
F_35 ( V_2 -> V_51 , V_2 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct F_38 * V_65 = V_62 ;
int V_36 = 0 , V_51 ;
if ( ! F_22 ( V_2 , V_53 ) )
return 0 ;
if ( F_22 ( V_2 , V_34 ) )
return 0 ;
if ( F_21 ( ! V_2 -> V_61 ) )
return - V_54 ;
switch ( V_65 -> V_66 ) {
case V_67 :
V_51 = V_2 -> V_61 -> V_51 ;
if ( V_2 -> V_68 < F_39 ( 1 , 2 ) &&
V_65 -> V_51 != V_51 )
return - V_54 ;
F_40 ( & V_2 -> V_69 ) ;
V_36 = F_32 ( V_2 , V_51 ) ;
F_41 ( & V_2 -> V_69 ) ;
return V_36 ;
case V_70 :
F_40 ( & V_2 -> V_69 ) ;
V_36 = F_36 ( V_2 ) ;
F_41 ( & V_2 -> V_69 ) ;
return V_36 ;
default:
return - V_54 ;
}
}
void F_42 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_3 = F_43 ( V_72 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_75 = 0 , V_20 = 0 ;
int V_76 = V_74 -> V_77 ;
if ( ! V_2 -> V_33 )
return;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
if ( V_76 > 0 ) {
int V_78 = V_74 -> V_79 * V_74 -> V_80 ;
V_75 = F_44 ( ( T_2 ) V_74 -> V_79 * 1000000 , V_76 ) ;
V_20 = F_44 ( ( T_2 ) V_78 * 1000000 , V_76 ) ;
if ( V_74 -> V_18 & V_81 )
V_20 /= 2 ;
} else
F_45 ( L_16 ,
V_72 -> V_82 . V_83 ) ;
V_9 -> V_75 = V_75 ;
V_9 -> V_20 = V_20 ;
F_19 ( L_17 ,
V_72 -> V_82 . V_83 , V_74 -> V_79 ,
V_74 -> V_80 , V_74 -> V_84 ) ;
F_19 ( L_18 ,
V_72 -> V_82 . V_83 , V_76 , V_20 , V_75 ) ;
}
int F_46 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_85 ,
struct V_5 * V_86 ,
unsigned V_18 ,
const struct V_73 * V_74 )
{
struct V_5 V_87 ;
T_3 V_88 , V_89 ;
unsigned int V_90 ;
int V_36 = V_91 ;
int V_92 , V_93 , V_38 ;
int V_94 , V_95 ;
if ( V_3 >= V_2 -> V_33 ) {
F_45 ( L_19 , V_3 ) ;
return - V_54 ;
}
if ( ! V_2 -> V_16 -> V_96 ) {
F_45 ( L_20 ) ;
return - V_97 ;
}
if ( V_74 -> V_77 == 0 ) {
F_19 ( L_21 , V_3 ) ;
return - V_98 ;
}
for ( V_38 = 0 ; V_38 < V_15 ; V_38 ++ ) {
V_90 = V_2 -> V_16 -> V_96 ( V_2 , V_3 , V_18 ,
& V_92 , & V_93 ,
& V_88 , & V_89 ,
V_74 ) ;
if ( ! ( V_90 & V_99 ) ) {
F_19 ( L_22 ,
V_3 , V_90 ) ;
return - V_97 ;
}
V_95 = F_47 ( V_89 ) - F_47 ( V_88 ) ;
if ( V_95 <= * V_85 )
break;
}
if ( V_38 == V_15 ) {
F_19 ( L_23 ,
V_3 , V_95 / 1000 , * V_85 / 1000 , V_38 ) ;
}
* V_85 = V_95 ;
if ( V_90 & V_100 )
V_36 |= V_101 ;
V_94 = F_48 ( 1000000LL * ( V_92 * V_74 -> V_79 + V_93 ) ,
V_74 -> V_77 ) ;
if ( ! V_102 )
V_89 = F_49 ( V_89 ) ;
V_87 = F_50 ( V_89 ) ;
if ( V_94 < 0 )
V_89 = F_51 ( V_89 , - V_94 ) ;
else
V_89 = F_52 ( V_89 , V_94 ) ;
* V_86 = F_50 ( V_89 ) ;
F_12 ( L_24 ,
V_3 , V_90 , V_93 , V_92 ,
( long ) V_87 . V_103 , ( long ) V_87 . V_104 ,
( long ) V_86 -> V_103 , ( long ) V_86 -> V_104 ,
V_95 / 1000 , V_38 ) ;
return V_36 ;
}
static struct V_5 F_53 ( void )
{
T_3 V_105 ;
V_105 = V_102 ? F_54 () : F_55 () ;
return F_50 ( V_105 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_106 , unsigned V_18 )
{
int V_36 ;
int V_85 = ( int ) V_107 * 1000 ;
if ( V_2 -> V_16 -> V_42 && ( V_85 > 0 ) ) {
V_36 = V_2 -> V_16 -> V_42 ( V_2 , V_3 , & V_85 ,
V_106 , V_18 ) ;
if ( V_36 > 0 )
return true ;
}
* V_106 = F_53 () ;
return false ;
}
T_1 F_56 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return 0 ;
return V_9 -> V_12 ;
}
T_1 F_57 ( struct V_71 * V_72 )
{
return F_56 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
T_1 F_58 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_108 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_12 = V_15 ;
T_1 V_13 ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return 0 ;
do {
V_13 = V_9 -> V_12 ;
F_59 () ;
* V_108 = F_3 ( V_2 , V_3 , V_13 ) ;
F_59 () ;
} while ( V_13 != V_9 -> V_12 && -- V_12 > 0 );
return V_13 ;
}
T_1 F_60 ( struct V_71 * V_72 ,
struct V_5 * V_108 )
{
return F_58 ( V_72 -> V_2 , F_43 ( V_72 ) ,
V_108 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
unsigned long V_111 , struct V_5 * V_105 )
{
F_2 ( & V_2 -> V_112 ) ;
V_110 -> V_113 . V_114 = V_111 ;
V_110 -> V_113 . V_103 = V_105 -> V_103 ;
V_110 -> V_113 . V_104 = V_105 -> V_104 ;
F_62 ( & V_110 -> V_82 . V_115 ,
& V_110 -> V_82 . V_64 -> V_116 ) ;
F_63 ( & V_110 -> V_82 . V_64 -> V_117 ) ;
F_64 ( V_110 -> V_82 . V_118 , V_110 -> V_3 ,
V_110 -> V_113 . V_114 ) ;
}
void F_65 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_109 * V_110 )
{
F_2 ( & V_2 -> V_112 ) ;
V_110 -> V_3 = V_3 ;
V_110 -> V_113 . V_114 = F_56 ( V_2 , V_3 ) ;
F_62 ( & V_110 -> V_82 . V_115 , & V_2 -> V_119 ) ;
}
void F_66 ( struct V_71 * V_72 ,
struct V_109 * V_110 )
{
F_65 ( V_72 -> V_2 , F_43 ( V_72 ) , V_110 ) ;
}
void F_67 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_109 * V_110 )
{
struct V_5 V_105 ;
unsigned int V_111 ;
if ( V_2 -> V_33 > 0 ) {
V_111 = F_58 ( V_2 , V_3 , & V_105 ) ;
} else {
V_111 = 0 ;
V_105 = F_53 () ;
}
V_110 -> V_3 = V_3 ;
F_61 ( V_2 , V_110 , V_111 , & V_105 ) ;
}
void F_68 ( struct V_71 * V_72 ,
struct V_109 * V_110 )
{
F_67 ( V_72 -> V_2 , F_43 ( V_72 ) , V_110 ) ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_36 = 0 ;
F_2 ( & V_2 -> V_32 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( ! V_9 -> V_28 ) {
V_36 = V_2 -> V_16 -> V_120 ( V_2 , V_3 ) ;
F_19 ( L_25 , V_3 , V_36 ) ;
if ( V_36 )
F_70 ( & V_9 -> V_26 ) ;
else {
V_9 -> V_28 = true ;
F_9 ( V_2 , V_3 , 0 ) ;
}
}
F_8 ( & V_2 -> V_11 ) ;
return V_36 ;
}
int F_71 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_27 ;
int V_36 = 0 ;
if ( ! V_2 -> V_33 )
return - V_54 ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return - V_54 ;
F_16 ( & V_2 -> V_32 , V_27 ) ;
if ( F_72 ( 1 , & V_9 -> V_26 ) == 1 ) {
V_36 = F_69 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_28 ) {
F_70 ( & V_9 -> V_26 ) ;
V_36 = - V_54 ;
}
}
F_17 ( & V_2 -> V_32 , V_27 ) ;
return V_36 ;
}
int F_73 ( struct V_71 * V_72 )
{
return F_71 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
void F_74 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
if ( F_21 ( F_13 ( & V_9 -> V_26 ) == 0 ) )
return;
if ( F_75 ( & V_9 -> V_26 ) ) {
if ( V_121 == 0 )
return;
else if ( V_2 -> V_43 || V_121 < 0 )
F_18 ( ( unsigned long ) V_9 ) ;
else
F_76 ( & V_9 -> V_35 ,
V_122 + ( ( V_121 * V_123 ) / 1000 ) ) ;
}
}
void F_77 ( struct V_71 * V_72 )
{
F_74 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
void F_78 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_36 ;
T_1 V_7 ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
V_36 = F_71 ( V_2 , V_3 ) ;
if ( F_79 ( V_36 , L_26 , V_3 , V_36 ) )
return;
V_7 = F_56 ( V_2 , V_3 ) ;
V_36 = F_80 ( V_9 -> V_41 ,
V_7 != F_56 ( V_2 , V_3 ) ,
F_81 ( 100 ) ) ;
F_79 ( V_36 == 0 , L_27 , V_3 ) ;
F_74 ( V_2 , V_3 ) ;
}
void F_82 ( struct V_71 * V_72 )
{
F_78 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
void F_83 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_109 * V_110 , * V_124 ;
struct V_5 V_105 ;
unsigned long V_27 ;
unsigned int V_111 ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
F_16 ( & V_2 -> V_112 , V_27 ) ;
F_6 ( & V_2 -> V_32 ) ;
F_12 ( L_28 ,
V_3 , V_9 -> V_28 , V_9 -> V_25 ) ;
if ( F_22 ( V_2 , V_125 ) || ! V_9 -> V_25 )
F_15 ( V_2 , V_3 ) ;
F_37 ( & V_9 -> V_41 ) ;
if ( ! V_9 -> V_25 ) {
F_84 ( & V_9 -> V_26 ) ;
V_9 -> V_25 = 1 ;
}
F_8 ( & V_2 -> V_32 ) ;
V_111 = F_58 ( V_2 , V_3 , & V_105 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_110 -> V_3 != V_3 )
continue;
F_19 ( L_29
L_30 ,
V_110 -> V_113 . V_114 , V_111 ) ;
F_86 ( & V_110 -> V_82 . V_115 ) ;
F_74 ( V_2 , V_3 ) ;
F_61 ( V_2 , V_110 , V_111 , & V_105 ) ;
}
F_17 ( & V_2 -> V_112 , V_27 ) ;
}
void F_87 ( struct V_71 * V_72 )
{
F_83 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
void F_88 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_27 ;
unsigned int V_3 = F_43 ( V_72 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_16 ( & V_2 -> V_32 , V_27 ) ;
if ( ! V_9 -> V_25 ) {
F_84 ( & V_9 -> V_26 ) ;
V_9 -> V_25 = 1 ;
}
F_17 ( & V_2 -> V_32 , V_27 ) ;
F_21 ( ! F_89 ( & V_2 -> V_119 ) ) ;
}
void F_90 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_27 ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
F_16 ( & V_2 -> V_32 , V_27 ) ;
F_12 ( L_28 ,
V_3 , V_9 -> V_28 , V_9 -> V_25 ) ;
if ( V_9 -> V_25 ) {
F_70 ( & V_9 -> V_26 ) ;
V_9 -> V_25 = 0 ;
}
F_5 ( V_2 , V_3 ) ;
if ( F_13 ( & V_9 -> V_26 ) != 0 || V_121 == 0 )
F_21 ( F_69 ( V_2 , V_3 ) ) ;
F_17 ( & V_2 -> V_32 , V_27 ) ;
}
void F_91 ( struct V_71 * V_72 )
{
F_90 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
void F_92 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_33 )
return;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
if ( ! V_9 -> V_25 ) {
V_9 -> V_25 = 0x1 ;
if ( F_71 ( V_2 , V_3 ) == 0 )
V_9 -> V_25 |= 0x2 ;
}
}
void F_93 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_27 ;
if ( ! V_2 -> V_33 )
return;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return;
if ( V_9 -> V_25 ) {
F_16 ( & V_2 -> V_32 , V_27 ) ;
V_2 -> V_31 = true ;
F_5 ( V_2 , V_3 ) ;
F_17 ( & V_2 -> V_32 , V_27 ) ;
if ( V_9 -> V_25 & 0x2 )
F_74 ( V_2 , V_3 ) ;
V_9 -> V_25 = 0 ;
}
}
int F_94 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct F_94 * V_126 = V_62 ;
unsigned int V_3 ;
if ( ! V_2 -> V_33 )
return 0 ;
if ( F_22 ( V_2 , V_34 ) )
return 0 ;
V_3 = V_126 -> V_72 ;
if ( V_3 >= V_2 -> V_33 )
return - V_54 ;
switch ( V_126 -> V_127 ) {
case V_128 :
F_92 ( V_2 , V_3 ) ;
break;
case V_129 :
F_93 ( V_2 , V_3 ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_130 * V_131 ,
struct V_63 * V_64 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_109 * V_110 ;
struct V_5 V_105 ;
unsigned long V_18 ;
unsigned int V_111 ;
int V_36 ;
V_110 = F_96 ( sizeof( * V_110 ) , V_39 ) ;
if ( V_110 == NULL ) {
V_36 = - V_37 ;
goto V_132;
}
V_110 -> V_3 = V_3 ;
V_110 -> V_82 . V_118 = V_133 -> V_118 ;
V_110 -> V_113 . V_82 . type = V_134 ;
V_110 -> V_113 . V_82 . V_135 = sizeof( V_110 -> V_113 ) ;
V_110 -> V_113 . V_136 = V_131 -> V_137 . signal ;
V_110 -> V_82 . V_113 = & V_110 -> V_113 . V_82 ;
V_110 -> V_82 . V_64 = V_64 ;
V_110 -> V_82 . V_138 = ( void ( * ) ( struct V_139 * ) ) F_24 ;
F_16 ( & V_2 -> V_112 , V_18 ) ;
if ( ! V_9 -> V_28 ) {
V_36 = - V_54 ;
goto V_140;
}
if ( V_64 -> V_141 < sizeof( V_110 -> V_113 ) ) {
V_36 = - V_56 ;
goto V_140;
}
V_64 -> V_141 -= sizeof( V_110 -> V_113 ) ;
V_111 = F_58 ( V_2 , V_3 , & V_105 ) ;
if ( ( V_131 -> V_137 . type & V_142 ) &&
( V_111 - V_131 -> V_137 . V_114 ) <= ( 1 << 23 ) ) {
V_131 -> V_137 . V_114 = V_111 + 1 ;
V_131 -> V_143 . V_114 = V_131 -> V_137 . V_114 ;
}
F_19 ( L_31 ,
V_131 -> V_137 . V_114 , V_111 , V_3 ) ;
F_97 ( V_133 -> V_118 , V_3 ,
V_131 -> V_137 . V_114 ) ;
V_110 -> V_113 . V_114 = V_131 -> V_137 . V_114 ;
if ( ( V_111 - V_131 -> V_137 . V_114 ) <= ( 1 << 23 ) ) {
F_74 ( V_2 , V_3 ) ;
F_61 ( V_2 , V_110 , V_111 , & V_105 ) ;
V_131 -> V_143 . V_114 = V_111 ;
} else {
F_62 ( & V_110 -> V_82 . V_115 , & V_2 -> V_119 ) ;
V_131 -> V_143 . V_114 = V_131 -> V_137 . V_114 ;
}
F_17 ( & V_2 -> V_112 , V_18 ) ;
return 0 ;
V_140:
F_17 ( & V_2 -> V_112 , V_18 ) ;
F_24 ( V_110 ) ;
V_132:
F_74 ( V_2 , V_3 ) ;
return V_36 ;
}
int V_130 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_8 * V_9 ;
union V_130 * V_131 = V_62 ;
int V_36 ;
unsigned int V_18 , V_111 , V_3 , V_144 ;
if ( ! V_2 -> V_47 )
return - V_54 ;
if ( V_131 -> V_137 . type & V_145 )
return - V_54 ;
if ( V_131 -> V_137 . type &
~ ( V_146 | V_147 |
V_148 ) ) {
F_45 ( L_32 ,
V_131 -> V_137 . type ,
( V_146 | V_147 |
V_148 ) ) ;
return - V_54 ;
}
V_18 = V_131 -> V_137 . type & V_147 ;
V_144 = ( V_131 -> V_137 . type & V_148 ) ;
if ( V_144 )
V_3 = V_144 >> V_149 ;
else
V_3 = V_18 & V_150 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_33 )
return - V_54 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
V_36 = F_71 ( V_2 , V_3 ) ;
if ( V_36 ) {
F_19 ( L_33 , V_36 ) ;
return V_36 ;
}
V_111 = F_56 ( V_2 , V_3 ) ;
switch ( V_131 -> V_137 . type & V_146 ) {
case V_151 :
V_131 -> V_137 . V_114 += V_111 ;
V_131 -> V_137 . type &= ~ V_151 ;
case V_152 :
break;
default:
V_36 = - V_54 ;
goto V_153;
}
if ( V_18 & V_154 ) {
return F_95 ( V_2 , V_3 , V_131 , V_64 ) ;
}
if ( ( V_18 & V_142 ) &&
( V_111 - V_131 -> V_137 . V_114 ) <= ( 1 << 23 ) ) {
V_131 -> V_137 . V_114 = V_111 + 1 ;
}
F_19 ( L_34 ,
V_131 -> V_137 . V_114 , V_3 ) ;
V_9 -> V_155 = V_131 -> V_137 . V_114 ;
F_98 ( V_36 , V_9 -> V_41 , 3 * V_123 ,
( ( ( F_56 ( V_2 , V_3 ) -
V_131 -> V_137 . V_114 ) <= ( 1 << 23 ) ) ||
! V_9 -> V_28 ||
! V_2 -> V_47 ) ) ;
if ( V_36 != - V_156 ) {
struct V_5 V_105 ;
V_131 -> V_143 . V_114 = F_58 ( V_2 , V_3 , & V_105 ) ;
V_131 -> V_143 . V_157 = V_105 . V_103 ;
V_131 -> V_143 . V_158 = V_105 . V_104 ;
F_19 ( L_35 ,
V_131 -> V_143 . V_114 ) ;
} else {
F_19 ( L_36 ) ;
}
V_153:
F_74 ( V_2 , V_3 ) ;
return V_36 ;
}
static void F_99 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_109 * V_110 , * V_124 ;
struct V_5 V_105 ;
unsigned int V_111 ;
F_2 ( & V_2 -> V_112 ) ;
V_111 = F_58 ( V_2 , V_3 , & V_105 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_110 -> V_3 != V_3 )
continue;
if ( ( V_111 - V_110 -> V_113 . V_114 ) > ( 1 << 23 ) )
continue;
F_19 ( L_37 ,
V_110 -> V_113 . V_114 , V_111 ) ;
F_86 ( & V_110 -> V_82 . V_115 ) ;
F_74 ( V_2 , V_3 ) ;
F_61 ( V_2 , V_110 , V_111 , & V_105 ) ;
}
F_100 ( V_3 , V_111 ) ;
}
bool F_101 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_27 ;
if ( F_14 ( ! V_2 -> V_33 ) )
return false ;
if ( F_21 ( V_3 >= V_2 -> V_33 ) )
return false ;
F_16 ( & V_2 -> V_112 , V_27 ) ;
F_6 ( & V_2 -> V_11 ) ;
if ( ! V_9 -> V_28 ) {
F_8 ( & V_2 -> V_11 ) ;
F_17 ( & V_2 -> V_112 , V_27 ) ;
return false ;
}
F_9 ( V_2 , V_3 , V_24 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_37 ( & V_9 -> V_41 ) ;
F_99 ( V_2 , V_3 ) ;
F_17 ( & V_2 -> V_112 , V_27 ) ;
return true ;
}
bool F_102 ( struct V_71 * V_72 )
{
return F_101 ( V_72 -> V_2 , F_43 ( V_72 ) ) ;
}
T_1 F_103 ( struct V_1 * V_2 , unsigned int V_3 )
{
return 0 ;
}
