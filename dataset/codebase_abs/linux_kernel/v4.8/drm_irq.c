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
T_1 F_14 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned int V_3 = F_15 ( V_27 ) ;
T_1 V_9 ;
unsigned long V_18 ;
F_16 ( ! V_2 -> V_16 -> V_28 ,
L_7 ) ;
F_17 ( & V_2 -> V_10 , V_18 ) ;
F_9 ( V_2 , V_3 , 0 ) ;
V_9 = F_18 ( V_2 , V_3 ) ;
F_19 ( & V_2 -> V_10 , V_18 ) ;
return V_9 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_29 ;
F_17 ( & V_2 -> V_10 , V_29 ) ;
if ( V_9 -> V_30 ) {
V_2 -> V_16 -> V_31 ( V_2 , V_3 ) ;
V_9 -> V_30 = false ;
}
F_9 ( V_2 , V_3 , 0 ) ;
F_19 ( & V_2 -> V_10 , V_29 ) ;
}
static void F_21 ( unsigned long V_32 )
{
struct V_8 * V_9 = ( void * ) V_32 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_3 = V_9 -> V_3 ;
unsigned long V_29 ;
F_17 ( & V_2 -> V_33 , V_29 ) ;
if ( F_22 ( & V_9 -> V_34 ) == 0 && V_9 -> V_30 ) {
F_23 ( L_8 , V_3 ) ;
F_20 ( V_2 , V_3 ) ;
}
F_19 ( & V_2 -> V_33 , V_29 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_35 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_35 ; V_3 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_25 ( V_9 -> V_30 &&
F_26 ( V_2 , V_36 ) ) ;
F_27 ( & V_9 -> V_37 ) ;
}
F_28 ( V_2 -> V_9 ) ;
V_2 -> V_35 = 0 ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_35 )
{
int V_38 = - V_39 ;
unsigned int V_40 ;
F_30 ( & V_2 -> V_33 ) ;
F_30 ( & V_2 -> V_10 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_9 = F_31 ( V_35 , sizeof( * V_2 -> V_9 ) , V_41 ) ;
if ( ! V_2 -> V_9 )
goto V_42;
for ( V_40 = 0 ; V_40 < V_35 ; V_40 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_40 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_3 = V_40 ;
F_32 ( & V_9 -> V_43 ) ;
F_33 ( & V_9 -> V_37 , F_21 ,
( unsigned long ) V_9 ) ;
F_34 ( & V_9 -> V_11 ) ;
}
F_35 ( L_9 ) ;
if ( V_2 -> V_16 -> V_28 )
F_35 ( L_10 ) ;
else
F_35 ( L_11 ) ;
if ( V_2 -> V_44 && ! V_2 -> V_16 -> V_28 ) {
V_2 -> V_44 = false ;
F_35 ( L_12
L_13 ) ;
}
return 0 ;
V_42:
V_2 -> V_35 = 0 ;
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
F_23 ( L_14 , V_52 ) ;
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
if ( ! F_26 ( V_2 , V_36 ) )
F_39 ( V_2 -> V_62 , ( void * ) V_2 , F_36 , NULL ) ;
if ( V_2 -> V_16 -> V_51 )
V_38 = V_2 -> V_16 -> V_51 ( V_2 ) ;
if ( V_38 < 0 ) {
V_2 -> V_48 = false ;
if ( ! F_26 ( V_2 , V_36 ) )
F_39 ( V_2 -> V_62 , NULL , NULL , NULL ) ;
F_40 ( V_52 , V_2 ) ;
} else {
V_2 -> V_52 = V_52 ;
}
return V_38 ;
}
int F_41 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
bool V_48 ;
int V_40 ;
if ( ! F_26 ( V_2 , V_54 ) )
return - V_55 ;
V_48 = V_2 -> V_48 ;
V_2 -> V_48 = false ;
if ( V_2 -> V_35 ) {
F_17 ( & V_2 -> V_33 , V_29 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_35 ; V_40 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_40 ] ;
if ( ! V_9 -> V_30 )
continue;
F_25 ( F_26 ( V_2 , V_36 ) ) ;
F_20 ( V_2 , V_40 ) ;
F_42 ( & V_9 -> V_43 ) ;
}
F_19 ( & V_2 -> V_33 , V_29 ) ;
}
if ( ! V_48 )
return - V_55 ;
F_23 ( L_14 , V_2 -> V_52 ) ;
if ( ! F_26 ( V_2 , V_36 ) )
F_39 ( V_2 -> V_62 , NULL , NULL , NULL ) ;
if ( V_2 -> V_16 -> V_49 )
V_2 -> V_16 -> V_49 ( V_2 ) ;
F_40 ( V_2 -> V_52 , V_2 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct F_43 * V_66 = V_63 ;
int V_38 = 0 , V_52 ;
if ( ! F_26 ( V_2 , V_54 ) )
return 0 ;
if ( F_26 ( V_2 , V_36 ) )
return 0 ;
if ( F_25 ( ! V_2 -> V_62 ) )
return - V_55 ;
switch ( V_66 -> V_67 ) {
case V_68 :
V_52 = V_2 -> V_62 -> V_52 ;
if ( V_2 -> V_69 < F_44 ( 1 , 2 ) &&
V_66 -> V_52 != V_52 )
return - V_55 ;
F_45 ( & V_2 -> V_70 ) ;
V_38 = F_37 ( V_2 , V_52 ) ;
F_46 ( & V_2 -> V_70 ) ;
return V_38 ;
case V_71 :
F_45 ( & V_2 -> V_70 ) ;
V_38 = F_41 ( V_2 ) ;
F_46 ( & V_2 -> V_70 ) ;
return V_38 ;
default:
return - V_55 ;
}
}
void F_47 ( struct V_26 * V_27 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned int V_3 = F_15 ( V_27 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_74 = 0 , V_20 = 0 ;
int V_75 = V_73 -> V_76 ;
if ( ! V_2 -> V_35 )
return;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
if ( V_75 > 0 ) {
int V_77 = V_73 -> V_78 * V_73 -> V_79 ;
V_74 = F_48 ( ( T_2 ) V_73 -> V_78 * 1000000 , V_75 ) ;
V_20 = F_48 ( ( T_2 ) V_77 * 1000000 , V_75 ) ;
if ( V_73 -> V_18 & V_80 )
V_20 /= 2 ;
} else
F_49 ( L_15 ,
V_27 -> V_81 . V_82 ) ;
V_9 -> V_74 = V_74 ;
V_9 -> V_20 = V_20 ;
F_23 ( L_16 ,
V_27 -> V_81 . V_82 , V_73 -> V_78 ,
V_73 -> V_79 , V_73 -> V_83 ) ;
F_23 ( L_17 ,
V_27 -> V_81 . V_82 , V_75 , V_20 , V_74 ) ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_84 ,
struct V_5 * V_85 ,
unsigned V_18 ,
const struct V_72 * V_73 )
{
struct V_5 V_86 ;
T_3 V_87 , V_88 ;
unsigned int V_89 ;
int V_38 = V_90 ;
int V_91 , V_92 , V_40 ;
int V_93 , V_94 ;
if ( V_3 >= V_2 -> V_35 ) {
F_49 ( L_18 , V_3 ) ;
return - V_55 ;
}
if ( ! V_2 -> V_16 -> V_95 ) {
F_49 ( L_19 ) ;
return - V_96 ;
}
if ( V_73 -> V_76 == 0 ) {
F_23 ( L_20 , V_3 ) ;
return - V_97 ;
}
for ( V_40 = 0 ; V_40 < V_15 ; V_40 ++ ) {
V_89 = V_2 -> V_16 -> V_95 ( V_2 , V_3 , V_18 ,
& V_91 , & V_92 ,
& V_87 , & V_88 ,
V_73 ) ;
if ( ! ( V_89 & V_98 ) ) {
F_23 ( L_21 ,
V_3 , V_89 ) ;
return - V_96 ;
}
V_94 = F_51 ( V_88 ) - F_51 ( V_87 ) ;
if ( V_94 <= * V_84 )
break;
}
if ( V_40 == V_15 ) {
F_23 ( L_22 ,
V_3 , V_94 / 1000 , * V_84 / 1000 , V_40 ) ;
}
* V_84 = V_94 ;
if ( V_89 & V_99 )
V_38 |= V_100 ;
V_93 = F_52 ( 1000000LL * ( V_91 * V_73 -> V_78 + V_92 ) ,
V_73 -> V_76 ) ;
if ( ! V_101 )
V_88 = F_53 ( V_88 ) ;
V_86 = F_54 ( V_88 ) ;
V_88 = F_55 ( V_88 , V_93 ) ;
* V_85 = F_54 ( V_88 ) ;
F_12 ( L_23 ,
V_3 , V_89 , V_92 , V_91 ,
( long ) V_86 . V_102 , ( long ) V_86 . V_103 ,
( long ) V_85 -> V_102 , ( long ) V_85 -> V_103 ,
V_94 / 1000 , V_40 ) ;
return V_38 ;
}
static struct V_5 F_56 ( void )
{
T_3 V_104 ;
V_104 = V_101 ? F_57 () : F_58 () ;
return F_54 ( V_104 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_105 , unsigned V_18 )
{
int V_38 ;
int V_84 = ( int ) V_106 * 1000 ;
if ( V_2 -> V_16 -> V_28 && ( V_84 > 0 ) ) {
V_38 = V_2 -> V_16 -> V_28 ( V_2 , V_3 , & V_84 ,
V_105 , V_18 ) ;
if ( V_38 > 0 )
return true ;
}
* V_105 = F_56 () ;
return false ;
}
T_1 F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return 0 ;
return V_9 -> V_12 ;
}
T_1 F_59 ( struct V_26 * V_27 )
{
return F_18 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
static T_1 F_60 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_107 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_108 ;
unsigned int V_109 ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return 0 ;
do {
V_109 = F_61 ( & V_9 -> V_11 ) ;
V_108 = V_9 -> V_12 ;
* V_107 = V_9 -> time ;
} while ( F_62 ( & V_9 -> V_11 , V_109 ) );
return V_108 ;
}
T_1 F_63 ( struct V_26 * V_27 ,
struct V_5 * V_107 )
{
return F_60 ( V_27 -> V_2 , F_15 ( V_27 ) ,
V_107 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
unsigned long V_109 , struct V_5 * V_104 )
{
V_111 -> V_112 . V_113 = V_109 ;
V_111 -> V_112 . V_102 = V_104 -> V_102 ;
V_111 -> V_112 . V_103 = V_104 -> V_103 ;
F_65 ( V_111 -> V_81 . V_114 , V_111 -> V_3 ,
V_111 -> V_112 . V_113 ) ;
F_66 ( V_2 , & V_111 -> V_81 ) ;
}
void F_67 ( struct V_26 * V_27 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned int V_3 = F_15 ( V_27 ) ;
F_2 ( & V_2 -> V_115 ) ;
V_111 -> V_3 = V_3 ;
V_111 -> V_112 . V_113 = F_18 ( V_2 , V_3 ) ;
F_68 ( & V_111 -> V_81 . V_116 , & V_2 -> V_117 ) ;
}
void F_69 ( struct V_26 * V_27 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned int V_109 , V_3 = F_15 ( V_27 ) ;
struct V_5 V_104 ;
if ( V_2 -> V_35 > 0 ) {
V_109 = F_60 ( V_2 , V_3 , & V_104 ) ;
} else {
V_109 = 0 ;
V_104 = F_56 () ;
}
V_111 -> V_3 = V_3 ;
F_64 ( V_2 , V_111 , V_109 , & V_104 ) ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_38 = 0 ;
F_2 ( & V_2 -> V_33 ) ;
F_6 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_30 ) {
V_38 = V_2 -> V_16 -> V_118 ( V_2 , V_3 ) ;
F_23 ( L_24 , V_3 , V_38 ) ;
if ( V_38 )
F_71 ( & V_9 -> V_34 ) ;
else {
V_9 -> V_30 = true ;
F_9 ( V_2 , V_3 , 0 ) ;
}
}
F_8 ( & V_2 -> V_10 ) ;
return V_38 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_29 ;
int V_38 = 0 ;
if ( ! V_2 -> V_35 )
return - V_55 ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return - V_55 ;
F_17 ( & V_2 -> V_33 , V_29 ) ;
if ( F_73 ( 1 , & V_9 -> V_34 ) == 1 ) {
V_38 = F_70 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_30 ) {
F_71 ( & V_9 -> V_34 ) ;
V_38 = - V_55 ;
}
}
F_19 ( & V_2 -> V_33 , V_29 ) ;
return V_38 ;
}
int F_74 ( struct V_26 * V_27 )
{
return F_72 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
static void F_75 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
if ( F_25 ( F_22 ( & V_9 -> V_34 ) == 0 ) )
return;
if ( F_76 ( & V_9 -> V_34 ) ) {
if ( V_119 == 0 )
return;
else if ( V_2 -> V_44 || V_119 < 0 )
F_21 ( ( unsigned long ) V_9 ) ;
else
F_77 ( & V_9 -> V_37 ,
V_120 + ( ( V_119 * V_121 ) / 1000 ) ) ;
}
}
void F_78 ( struct V_26 * V_27 )
{
F_75 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
void F_79 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_38 ;
T_1 V_7 ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
V_38 = F_72 ( V_2 , V_3 ) ;
if ( F_16 ( V_38 , L_25 , V_3 , V_38 ) )
return;
V_7 = F_18 ( V_2 , V_3 ) ;
V_38 = F_80 ( V_9 -> V_43 ,
V_7 != F_18 ( V_2 , V_3 ) ,
F_81 ( 100 ) ) ;
F_16 ( V_38 == 0 , L_26 , V_3 ) ;
F_75 ( V_2 , V_3 ) ;
}
void F_82 ( struct V_26 * V_27 )
{
F_79 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
void F_83 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_110 * V_111 , * V_122 ;
struct V_5 V_104 ;
unsigned long V_29 ;
unsigned int V_109 ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
F_17 ( & V_2 -> V_115 , V_29 ) ;
F_6 ( & V_2 -> V_33 ) ;
F_12 ( L_27 ,
V_3 , V_9 -> V_30 , V_9 -> V_25 ) ;
if ( F_26 ( V_2 , V_123 ) || ! V_9 -> V_25 )
F_20 ( V_2 , V_3 ) ;
F_42 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_25 ) {
F_84 ( & V_9 -> V_34 ) ;
V_9 -> V_25 = 1 ;
}
F_8 ( & V_2 -> V_33 ) ;
V_109 = F_60 ( V_2 , V_3 , & V_104 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_111 -> V_3 != V_3 )
continue;
F_23 ( L_28
L_29 ,
V_111 -> V_112 . V_113 , V_109 ) ;
F_86 ( & V_111 -> V_81 . V_116 ) ;
F_75 ( V_2 , V_3 ) ;
F_64 ( V_2 , V_111 , V_109 , & V_104 ) ;
}
F_19 ( & V_2 -> V_115 , V_29 ) ;
}
void F_87 ( struct V_26 * V_27 )
{
F_83 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
void F_88 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_29 ;
unsigned int V_3 = F_15 ( V_27 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_17 ( & V_2 -> V_33 , V_29 ) ;
if ( ! V_9 -> V_25 ) {
F_84 ( & V_9 -> V_34 ) ;
V_9 -> V_25 = 1 ;
}
F_19 ( & V_2 -> V_33 , V_29 ) ;
F_25 ( ! F_89 ( & V_2 -> V_117 ) ) ;
}
void F_90 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_29 ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
F_17 ( & V_2 -> V_33 , V_29 ) ;
F_12 ( L_27 ,
V_3 , V_9 -> V_30 , V_9 -> V_25 ) ;
if ( V_9 -> V_25 ) {
F_71 ( & V_9 -> V_34 ) ;
V_9 -> V_25 = 0 ;
}
F_5 ( V_2 , V_3 ) ;
if ( F_22 ( & V_9 -> V_34 ) != 0 || V_119 == 0 )
F_25 ( F_70 ( V_2 , V_3 ) ) ;
F_19 ( & V_2 -> V_33 , V_29 ) ;
}
void F_91 ( struct V_26 * V_27 )
{
F_90 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
void F_92 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_35 )
return;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
if ( ! V_9 -> V_25 ) {
V_9 -> V_25 = 0x1 ;
if ( F_72 ( V_2 , V_3 ) == 0 )
V_9 -> V_25 |= 0x2 ;
}
}
void F_93 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_29 ;
if ( ! V_2 -> V_35 )
return;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return;
if ( V_9 -> V_25 ) {
F_17 ( & V_2 -> V_33 , V_29 ) ;
F_5 ( V_2 , V_3 ) ;
F_19 ( & V_2 -> V_33 , V_29 ) ;
if ( V_9 -> V_25 & 0x2 )
F_75 ( V_2 , V_3 ) ;
V_9 -> V_25 = 0 ;
}
}
int F_94 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct F_94 * V_124 = V_63 ;
unsigned int V_3 ;
if ( ! V_2 -> V_35 )
return 0 ;
if ( F_26 ( V_2 , V_36 ) )
return 0 ;
V_3 = V_124 -> V_27 ;
if ( V_3 >= V_2 -> V_35 )
return - V_55 ;
switch ( V_124 -> V_125 ) {
case V_126 :
F_92 ( V_2 , V_3 ) ;
break;
case V_127 :
F_93 ( V_2 , V_3 ) ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_128 * V_129 ,
struct V_64 * V_65 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_110 * V_111 ;
struct V_5 V_104 ;
unsigned long V_18 ;
unsigned int V_109 ;
int V_38 ;
V_111 = F_96 ( sizeof( * V_111 ) , V_41 ) ;
if ( V_111 == NULL ) {
V_38 = - V_39 ;
goto V_130;
}
V_111 -> V_3 = V_3 ;
V_111 -> V_81 . V_114 = V_131 -> V_114 ;
V_111 -> V_112 . V_81 . type = V_132 ;
V_111 -> V_112 . V_81 . V_133 = sizeof( V_111 -> V_112 ) ;
V_111 -> V_112 . V_134 = V_129 -> V_135 . signal ;
F_17 ( & V_2 -> V_115 , V_18 ) ;
if ( ! V_9 -> V_30 ) {
V_38 = - V_55 ;
goto V_136;
}
V_38 = F_97 ( V_2 , V_65 , & V_111 -> V_81 ,
& V_111 -> V_112 . V_81 ) ;
if ( V_38 )
goto V_136;
V_109 = F_60 ( V_2 , V_3 , & V_104 ) ;
F_23 ( L_30 ,
V_129 -> V_135 . V_113 , V_109 , V_3 ) ;
F_98 ( V_131 -> V_114 , V_3 ,
V_129 -> V_135 . V_113 ) ;
V_111 -> V_112 . V_113 = V_129 -> V_135 . V_113 ;
if ( ( V_109 - V_129 -> V_135 . V_113 ) <= ( 1 << 23 ) ) {
F_75 ( V_2 , V_3 ) ;
F_64 ( V_2 , V_111 , V_109 , & V_104 ) ;
V_129 -> V_137 . V_113 = V_109 ;
} else {
F_68 ( & V_111 -> V_81 . V_116 , & V_2 -> V_117 ) ;
V_129 -> V_137 . V_113 = V_129 -> V_135 . V_113 ;
}
F_19 ( & V_2 -> V_115 , V_18 ) ;
return 0 ;
V_136:
F_19 ( & V_2 -> V_115 , V_18 ) ;
F_28 ( V_111 ) ;
V_130:
F_75 ( V_2 , V_3 ) ;
return V_38 ;
}
int V_128 ( struct V_1 * V_2 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_8 * V_9 ;
union V_128 * V_129 = V_63 ;
int V_38 ;
unsigned int V_18 , V_109 , V_3 , V_138 ;
if ( ! V_2 -> V_48 )
return - V_55 ;
if ( V_129 -> V_135 . type & V_139 )
return - V_55 ;
if ( V_129 -> V_135 . type &
~ ( V_140 | V_141 |
V_142 ) ) {
F_49 ( L_31 ,
V_129 -> V_135 . type ,
( V_140 | V_141 |
V_142 ) ) ;
return - V_55 ;
}
V_18 = V_129 -> V_135 . type & V_141 ;
V_138 = ( V_129 -> V_135 . type & V_142 ) ;
if ( V_138 )
V_3 = V_138 >> V_143 ;
else
V_3 = V_18 & V_144 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_35 )
return - V_55 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
V_38 = F_72 ( V_2 , V_3 ) ;
if ( V_38 ) {
F_23 ( L_32 , V_38 ) ;
return V_38 ;
}
V_109 = F_18 ( V_2 , V_3 ) ;
switch ( V_129 -> V_135 . type & V_140 ) {
case V_145 :
V_129 -> V_135 . V_113 += V_109 ;
V_129 -> V_135 . type &= ~ V_145 ;
case V_146 :
break;
default:
V_38 = - V_55 ;
goto V_147;
}
if ( ( V_18 & V_148 ) &&
( V_109 - V_129 -> V_135 . V_113 ) <= ( 1 << 23 ) ) {
V_129 -> V_135 . V_113 = V_109 + 1 ;
}
if ( V_18 & V_149 ) {
return F_95 ( V_2 , V_3 , V_129 , V_65 ) ;
}
F_23 ( L_33 ,
V_129 -> V_135 . V_113 , V_3 ) ;
F_99 ( V_38 , V_9 -> V_43 , 3 * V_121 ,
( ( ( F_18 ( V_2 , V_3 ) -
V_129 -> V_135 . V_113 ) <= ( 1 << 23 ) ) ||
! V_9 -> V_30 ||
! V_2 -> V_48 ) ) ;
if ( V_38 != - V_150 ) {
struct V_5 V_104 ;
V_129 -> V_137 . V_113 = F_60 ( V_2 , V_3 , & V_104 ) ;
V_129 -> V_137 . V_151 = V_104 . V_102 ;
V_129 -> V_137 . V_152 = V_104 . V_103 ;
F_23 ( L_34 ,
V_129 -> V_137 . V_113 ) ;
} else {
F_23 ( L_35 ) ;
}
V_147:
F_75 ( V_2 , V_3 ) ;
return V_38 ;
}
static void F_100 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_110 * V_111 , * V_122 ;
struct V_5 V_104 ;
unsigned int V_109 ;
F_2 ( & V_2 -> V_115 ) ;
V_109 = F_60 ( V_2 , V_3 , & V_104 ) ;
F_85 (e, t, &dev->vblank_event_list, base.link) {
if ( V_111 -> V_3 != V_3 )
continue;
if ( ( V_109 - V_111 -> V_112 . V_113 ) > ( 1 << 23 ) )
continue;
F_23 ( L_36 ,
V_111 -> V_112 . V_113 , V_109 ) ;
F_86 ( & V_111 -> V_81 . V_116 ) ;
F_75 ( V_2 , V_3 ) ;
F_64 ( V_2 , V_111 , V_109 , & V_104 ) ;
}
F_101 ( V_3 , V_109 ) ;
}
bool F_102 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_29 ;
if ( F_13 ( ! V_2 -> V_35 ) )
return false ;
if ( F_25 ( V_3 >= V_2 -> V_35 ) )
return false ;
F_17 ( & V_2 -> V_115 , V_29 ) ;
F_6 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_30 ) {
F_8 ( & V_2 -> V_10 ) ;
F_19 ( & V_2 -> V_115 , V_29 ) ;
return false ;
}
F_9 ( V_2 , V_3 , V_24 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_42 ( & V_9 -> V_43 ) ;
F_100 ( V_2 , V_3 ) ;
F_19 ( & V_2 -> V_115 , V_29 ) ;
return true ;
}
bool F_103 ( struct V_26 * V_27 )
{
return F_102 ( V_27 -> V_2 , F_15 ( V_27 ) ) ;
}
T_1 F_104 ( struct V_1 * V_2 , unsigned int V_3 )
{
return 0 ;
}
