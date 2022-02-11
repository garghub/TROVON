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
static T_1 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_6 ( V_2 -> V_13 != 0 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_8 ( V_2 , V_14 ) ) {
struct V_15 * V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_16 -> V_17 -> V_18 )
return V_16 -> V_17 -> V_18 ( V_16 ) ;
}
if ( V_2 -> V_19 -> V_18 )
return V_2 -> V_19 -> V_18 ( V_2 , V_3 ) ;
return F_5 ( V_2 , V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_20 ;
bool V_21 ;
struct V_5 V_6 ;
int V_12 = V_22 ;
F_11 ( & V_2 -> V_10 ) ;
do {
V_20 = F_7 ( V_2 , V_3 ) ;
V_21 = F_12 ( V_2 , V_3 , & V_6 , 0 ) ;
} while ( V_20 != F_7 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( ! V_21 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , 1 , & V_6 , V_20 ) ;
F_13 ( & V_2 -> V_10 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_23 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_20 , V_24 ;
bool V_21 ;
struct V_5 V_6 ;
int V_12 = V_22 ;
int V_25 = V_9 -> V_25 ;
do {
V_20 = F_7 ( V_2 , V_3 ) ;
V_21 = F_12 ( V_2 , V_3 , & V_6 , V_23 ) ;
} while ( V_20 != F_7 ( V_2 , V_3 ) && -- V_12 > 0 );
if ( V_2 -> V_13 != 0 ) {
V_24 = ( V_20 - V_9 -> V_7 ) & V_2 -> V_13 ;
} else if ( V_21 && V_25 ) {
const struct V_5 * V_26 ;
T_2 V_27 ;
V_26 = & V_9 -> time ;
V_27 = F_15 ( & V_6 ) - F_15 ( V_26 ) ;
V_24 = F_16 ( V_27 , V_25 ) ;
if ( V_24 == 0 && V_23 & V_28 )
F_17 ( L_1
L_2 ,
V_3 , ( long long ) V_27 , V_25 ) ;
} else {
V_24 = ( V_23 & V_28 ) != 0 ;
}
if ( V_24 > 1 && ( V_9 -> V_29 & 0x2 ) ) {
F_17 ( L_3
L_4 , V_3 , V_24 ) ;
V_24 = 1 ;
}
F_17 ( L_5
L_6 ,
V_3 , V_9 -> V_12 , V_24 , V_20 , V_9 -> V_7 ) ;
if ( V_24 == 0 ) {
F_6 ( V_20 != V_9 -> V_7 ) ;
return;
}
if ( ! V_21 && ( V_23 & V_28 ) == 0 )
V_6 = (struct V_5 ) { 0 , 0 } ;
F_1 ( V_2 , V_3 , V_24 , & V_6 , V_20 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return 0 ;
return V_9 -> V_12 ;
}
T_1 F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
T_1 V_9 ;
unsigned long V_23 ;
F_22 ( ! V_2 -> V_19 -> V_31 ,
L_7 ) ;
F_23 ( & V_2 -> V_10 , V_23 ) ;
F_14 ( V_2 , V_3 , 0 ) ;
V_9 = F_18 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_10 , V_23 ) ;
return V_9 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_8 ( V_2 , V_14 ) ) {
struct V_15 * V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_16 -> V_17 -> V_32 ) {
V_16 -> V_17 -> V_32 ( V_16 ) ;
return;
}
}
V_2 -> V_19 -> V_32 ( V_2 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
F_2 ( & V_2 -> V_34 ) ;
F_23 ( & V_2 -> V_10 , V_33 ) ;
if ( V_9 -> V_35 ) {
F_25 ( V_2 , V_3 ) ;
V_9 -> V_35 = false ;
}
F_14 ( V_2 , V_3 , 0 ) ;
F_24 ( & V_2 -> V_10 , V_33 ) ;
}
static void F_27 ( unsigned long V_36 )
{
struct V_8 * V_9 = ( void * ) V_36 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_3 = V_9 -> V_3 ;
unsigned long V_33 ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( F_28 ( & V_9 -> V_37 ) == 0 && V_9 -> V_35 ) {
F_29 ( L_8 , V_3 ) ;
F_26 ( V_2 , V_3 ) ;
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_30 == 0 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_30 ; V_3 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_19 ( F_31 ( V_9 -> V_35 ) &&
F_8 ( V_2 , V_14 ) ) ;
F_32 ( & V_9 -> V_38 ) ;
}
F_33 ( V_2 -> V_9 ) ;
V_2 -> V_30 = 0 ;
}
int F_34 ( struct V_1 * V_2 , unsigned int V_30 )
{
int V_39 = - V_40 ;
unsigned int V_41 ;
F_35 ( & V_2 -> V_34 ) ;
F_35 ( & V_2 -> V_10 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_9 = F_36 ( V_30 , sizeof( * V_2 -> V_9 ) , V_42 ) ;
if ( ! V_2 -> V_9 )
goto V_43;
for ( V_41 = 0 ; V_41 < V_30 ; V_41 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_41 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_3 = V_41 ;
F_37 ( & V_9 -> V_44 ) ;
F_38 ( & V_9 -> V_38 , F_27 ,
( unsigned long ) V_9 ) ;
F_39 ( & V_9 -> V_11 ) ;
}
F_40 ( L_9 ) ;
if ( V_2 -> V_19 -> V_31 )
F_40 ( L_10 ) ;
else
F_40 ( L_11 ) ;
if ( V_2 -> V_45 && ! V_2 -> V_19 -> V_31 ) {
V_2 -> V_45 = false ;
F_40 ( L_12
L_13 ) ;
}
return 0 ;
V_43:
V_2 -> V_30 = 0 ;
return V_39 ;
}
int F_41 ( struct V_1 * V_2 , int V_46 )
{
int V_39 ;
unsigned long V_47 = 0 ;
if ( ! F_8 ( V_2 , V_48 ) )
return - V_49 ;
if ( V_46 == 0 )
return - V_49 ;
if ( ! V_2 -> V_50 )
return - V_49 ;
if ( V_2 -> V_51 )
return - V_52 ;
V_2 -> V_51 = true ;
F_29 ( L_14 , V_46 ) ;
if ( V_2 -> V_19 -> V_53 )
V_2 -> V_19 -> V_53 ( V_2 ) ;
if ( F_8 ( V_2 , V_54 ) )
V_47 = V_55 ;
V_39 = F_42 ( V_46 , V_2 -> V_19 -> V_56 ,
V_47 , V_2 -> V_19 -> V_57 , V_2 ) ;
if ( V_39 < 0 ) {
V_2 -> V_51 = false ;
return V_39 ;
}
if ( V_2 -> V_19 -> V_58 )
V_39 = V_2 -> V_19 -> V_58 ( V_2 ) ;
if ( V_39 < 0 ) {
V_2 -> V_51 = false ;
if ( F_8 ( V_2 , V_59 ) )
F_43 ( V_2 -> V_60 , NULL , NULL , NULL ) ;
F_44 ( V_46 , V_2 ) ;
} else {
V_2 -> V_46 = V_46 ;
}
return V_39 ;
}
int F_45 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
bool V_51 ;
int V_41 ;
if ( ! F_8 ( V_2 , V_48 ) )
return - V_49 ;
V_51 = V_2 -> V_51 ;
V_2 -> V_51 = false ;
if ( V_2 -> V_30 ) {
F_23 ( & V_2 -> V_34 , V_33 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_30 ; V_41 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_41 ] ;
if ( ! V_9 -> V_35 )
continue;
F_19 ( F_8 ( V_2 , V_14 ) ) ;
F_26 ( V_2 , V_41 ) ;
F_46 ( & V_9 -> V_44 ) ;
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
}
if ( ! V_51 )
return - V_49 ;
F_29 ( L_14 , V_2 -> V_46 ) ;
if ( F_8 ( V_2 , V_59 ) )
F_43 ( V_2 -> V_60 , NULL , NULL , NULL ) ;
if ( V_2 -> V_19 -> V_61 )
V_2 -> V_19 -> V_61 ( V_2 ) ;
F_44 ( V_2 -> V_46 , V_2 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = V_62 ;
int V_39 = 0 , V_46 ;
if ( ! F_8 ( V_2 , V_48 ) )
return 0 ;
if ( ! F_8 ( V_2 , V_59 ) )
return 0 ;
if ( F_19 ( ! V_2 -> V_60 ) )
return - V_49 ;
switch ( V_66 -> V_67 ) {
case V_68 :
V_46 = V_2 -> V_60 -> V_46 ;
if ( V_2 -> V_69 < F_48 ( 1 , 2 ) &&
V_66 -> V_46 != V_46 )
return - V_49 ;
F_49 ( & V_2 -> V_70 ) ;
V_39 = F_41 ( V_2 , V_46 ) ;
F_50 ( & V_2 -> V_70 ) ;
return V_39 ;
case V_71 :
F_49 ( & V_2 -> V_70 ) ;
V_39 = F_45 ( V_2 ) ;
F_50 ( & V_2 -> V_70 ) ;
return V_39 ;
default:
return - V_49 ;
}
}
void F_51 ( struct V_15 * V_16 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_74 = 0 , V_25 = 0 ;
int V_75 = V_73 -> V_76 ;
if ( ! V_2 -> V_30 )
return;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
if ( V_75 > 0 ) {
int V_77 = V_73 -> V_78 * V_73 -> V_79 ;
V_74 = F_52 ( ( T_2 ) V_73 -> V_78 * 1000000 , V_75 ) ;
V_25 = F_52 ( ( T_2 ) V_77 * 1000000 , V_75 ) ;
if ( V_73 -> V_23 & V_80 )
V_25 /= 2 ;
} else
F_53 ( L_15 ,
V_16 -> V_81 . V_82 ) ;
V_9 -> V_74 = V_74 ;
V_9 -> V_25 = V_25 ;
F_29 ( L_16 ,
V_16 -> V_81 . V_82 , V_73 -> V_78 ,
V_73 -> V_79 , V_73 -> V_83 ) ;
F_29 ( L_17 ,
V_16 -> V_81 . V_82 , V_75 , V_25 , V_74 ) ;
}
int F_54 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_84 ,
struct V_5 * V_85 ,
unsigned V_23 ,
const struct V_72 * V_73 )
{
struct V_5 V_86 ;
T_3 V_87 , V_88 ;
unsigned int V_89 ;
int V_39 = V_90 ;
int V_91 , V_92 , V_41 ;
int V_93 , V_94 ;
if ( V_3 >= V_2 -> V_30 ) {
F_53 ( L_18 , V_3 ) ;
return - V_49 ;
}
if ( ! V_2 -> V_19 -> V_95 ) {
F_53 ( L_19 ) ;
return - V_96 ;
}
if ( V_73 -> V_76 == 0 ) {
F_29 ( L_20 , V_3 ) ;
return - V_97 ;
}
for ( V_41 = 0 ; V_41 < V_22 ; V_41 ++ ) {
V_89 = V_2 -> V_19 -> V_95 ( V_2 , V_3 , V_23 ,
& V_91 , & V_92 ,
& V_87 , & V_88 ,
V_73 ) ;
if ( ! ( V_89 & V_98 ) ) {
F_29 ( L_21 ,
V_3 , V_89 ) ;
return - V_96 ;
}
V_94 = F_55 ( V_88 ) - F_55 ( V_87 ) ;
if ( V_94 <= * V_84 )
break;
}
if ( V_41 == V_22 ) {
F_29 ( L_22 ,
V_3 , V_94 / 1000 , * V_84 / 1000 , V_41 ) ;
}
* V_84 = V_94 ;
V_93 = F_56 ( 1000000LL * ( V_91 * V_73 -> V_78 + V_92 ) ,
V_73 -> V_76 ) ;
if ( ! V_99 )
V_88 = F_57 ( V_88 ) ;
V_86 = F_58 ( V_88 ) ;
V_88 = F_59 ( V_88 , V_93 ) ;
* V_85 = F_58 ( V_88 ) ;
F_17 ( L_23 ,
V_3 , V_89 , V_92 , V_91 ,
( long ) V_86 . V_100 , ( long ) V_86 . V_101 ,
( long ) V_85 -> V_100 , ( long ) V_85 -> V_101 ,
V_94 / 1000 , V_41 ) ;
return V_39 ;
}
static struct V_5 F_60 ( void )
{
T_3 V_102 ;
V_102 = V_99 ? F_61 () : F_62 () ;
return F_58 ( V_102 ) ;
}
static bool
F_12 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_103 , unsigned V_23 )
{
int V_39 ;
int V_84 = ( int ) V_104 * 1000 ;
if ( V_2 -> V_19 -> V_31 && ( V_84 > 0 ) ) {
V_39 = V_2 -> V_19 -> V_31 ( V_2 , V_3 , & V_84 ,
V_103 , V_23 ) ;
if ( V_39 > 0 )
return true ;
}
* V_103 = F_60 () ;
return false ;
}
T_1 F_63 ( struct V_15 * V_16 )
{
return F_18 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
static T_1 F_64 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_105 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_106 ;
unsigned int V_107 ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) ) {
* V_105 = (struct V_5 ) { 0 } ;
return 0 ;
}
do {
V_107 = F_65 ( & V_9 -> V_11 ) ;
V_106 = V_9 -> V_12 ;
* V_105 = V_9 -> time ;
} while ( F_66 ( & V_9 -> V_11 , V_107 ) );
return V_106 ;
}
T_1 F_67 ( struct V_15 * V_16 ,
struct V_5 * V_105 )
{
return F_64 ( V_16 -> V_2 , F_21 ( V_16 ) ,
V_105 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
unsigned long V_107 , struct V_5 * V_102 )
{
V_109 -> V_110 . V_111 = V_107 ;
V_109 -> V_110 . V_100 = V_102 -> V_100 ;
V_109 -> V_110 . V_101 = V_102 -> V_101 ;
F_69 ( V_109 -> V_81 . V_64 , V_109 -> V_3 ,
V_109 -> V_110 . V_111 ) ;
F_70 ( V_2 , & V_109 -> V_81 ) ;
}
void F_71 ( struct V_15 * V_16 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
F_2 ( & V_2 -> V_112 ) ;
V_109 -> V_3 = V_3 ;
V_109 -> V_110 . V_111 = F_18 ( V_2 , V_3 ) ;
V_109 -> V_110 . V_113 = V_16 -> V_81 . V_82 ;
F_72 ( & V_109 -> V_81 . V_114 , & V_2 -> V_115 ) ;
}
void F_73 ( struct V_15 * V_16 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_107 , V_3 = F_21 ( V_16 ) ;
struct V_5 V_102 ;
if ( V_2 -> V_30 > 0 ) {
V_107 = F_64 ( V_2 , V_3 , & V_102 ) ;
} else {
V_107 = 0 ;
V_102 = F_60 () ;
}
V_109 -> V_3 = V_3 ;
V_109 -> V_110 . V_113 = V_16 -> V_81 . V_82 ;
F_68 ( V_2 , V_109 , V_107 , & V_102 ) ;
}
static int F_74 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_8 ( V_2 , V_14 ) ) {
struct V_15 * V_16 = F_9 ( V_2 , V_3 ) ;
if ( V_16 -> V_17 -> V_116 )
return V_16 -> V_17 -> V_116 ( V_16 ) ;
}
return V_2 -> V_19 -> V_116 ( V_2 , V_3 ) ;
}
static int F_75 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_39 = 0 ;
F_2 ( & V_2 -> V_34 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_35 ) {
V_39 = F_74 ( V_2 , V_3 ) ;
F_29 ( L_24 , V_3 , V_39 ) ;
if ( V_39 ) {
F_76 ( & V_9 -> V_37 ) ;
} else {
F_14 ( V_2 , V_3 , 0 ) ;
F_77 ( V_9 -> V_35 , true ) ;
}
}
F_13 ( & V_2 -> V_10 ) ;
return V_39 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
int V_39 = 0 ;
if ( ! V_2 -> V_30 )
return - V_49 ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return - V_49 ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( F_79 ( 1 , & V_9 -> V_37 ) == 1 ) {
V_39 = F_75 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_35 ) {
F_76 ( & V_9 -> V_37 ) ;
V_39 = - V_49 ;
}
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
return V_39 ;
}
int F_80 ( struct V_15 * V_16 )
{
return F_78 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
static void F_81 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
if ( F_19 ( F_28 ( & V_9 -> V_37 ) == 0 ) )
return;
if ( F_82 ( & V_9 -> V_37 ) ) {
if ( V_117 == 0 )
return;
else if ( V_117 < 0 )
F_27 ( ( unsigned long ) V_9 ) ;
else if ( ! V_2 -> V_45 )
F_83 ( & V_9 -> V_38 ,
V_118 + ( ( V_117 * V_119 ) / 1000 ) ) ;
}
}
void F_84 ( struct V_15 * V_16 )
{
F_81 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
void F_85 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_39 ;
T_1 V_7 ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
V_39 = F_78 ( V_2 , V_3 ) ;
if ( F_22 ( V_39 , L_25 , V_3 , V_39 ) )
return;
V_7 = F_18 ( V_2 , V_3 ) ;
V_39 = F_86 ( V_9 -> V_44 ,
V_7 != F_18 ( V_2 , V_3 ) ,
F_87 ( 100 ) ) ;
F_22 ( V_39 == 0 , L_26 , V_3 ) ;
F_81 ( V_2 , V_3 ) ;
}
void F_88 ( struct V_15 * V_16 )
{
F_85 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
void F_89 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_108 * V_109 , * V_120 ;
struct V_5 V_102 ;
unsigned long V_33 ;
unsigned int V_107 ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
F_23 ( & V_2 -> V_112 , V_33 ) ;
F_11 ( & V_2 -> V_34 ) ;
F_17 ( L_27 ,
V_3 , V_9 -> V_35 , V_9 -> V_29 ) ;
if ( F_8 ( V_2 , V_121 ) || ! V_9 -> V_29 )
F_26 ( V_2 , V_3 ) ;
F_46 ( & V_9 -> V_44 ) ;
if ( ! V_9 -> V_29 ) {
F_90 ( & V_9 -> V_37 ) ;
V_9 -> V_29 = 1 ;
}
F_13 ( & V_2 -> V_34 ) ;
V_107 = F_64 ( V_2 , V_3 , & V_102 ) ;
F_91 (e, t, &dev->vblank_event_list, base.link) {
if ( V_109 -> V_3 != V_3 )
continue;
F_29 ( L_28
L_29 ,
V_109 -> V_110 . V_111 , V_107 ) ;
F_92 ( & V_109 -> V_81 . V_114 ) ;
F_81 ( V_2 , V_3 ) ;
F_68 ( V_2 , V_109 , V_107 , & V_102 ) ;
}
F_24 ( & V_2 -> V_112 , V_33 ) ;
}
void F_93 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_33 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( ! V_9 -> V_29 ) {
F_90 ( & V_9 -> V_37 ) ;
V_9 -> V_29 = 1 ;
}
F_24 ( & V_2 -> V_34 , V_33 ) ;
F_19 ( ! F_94 ( & V_2 -> V_115 ) ) ;
}
void F_95 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_3 = F_21 ( V_16 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
F_23 ( & V_2 -> V_34 , V_33 ) ;
F_17 ( L_27 ,
V_3 , V_9 -> V_35 , V_9 -> V_29 ) ;
if ( V_9 -> V_29 ) {
F_76 ( & V_9 -> V_37 ) ;
V_9 -> V_29 = 0 ;
}
F_10 ( V_2 , V_3 ) ;
if ( F_28 ( & V_9 -> V_37 ) != 0 || V_117 == 0 )
F_19 ( F_75 ( V_2 , V_3 ) ) ;
F_24 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_30 )
return;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
if ( ! V_9 -> V_29 ) {
V_9 -> V_29 = 0x1 ;
if ( F_78 ( V_2 , V_3 ) == 0 )
V_9 -> V_29 |= 0x2 ;
}
}
static void F_97 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
if ( ! V_2 -> V_30 )
return;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return;
if ( V_9 -> V_29 ) {
F_23 ( & V_2 -> V_34 , V_33 ) ;
F_10 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_34 , V_33 ) ;
if ( V_9 -> V_29 & 0x2 )
F_81 ( V_2 , V_3 ) ;
V_9 -> V_29 = 0 ;
}
}
int F_98 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_122 * V_123 = V_62 ;
unsigned int V_3 ;
if ( ! V_2 -> V_30 )
return 0 ;
if ( ! F_8 ( V_2 , V_59 ) )
return 0 ;
V_3 = V_123 -> V_16 ;
if ( V_3 >= V_2 -> V_30 )
return - V_49 ;
switch ( V_123 -> V_124 ) {
case V_125 :
F_96 ( V_2 , V_3 ) ;
break;
case V_126 :
F_97 ( V_2 , V_3 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static inline bool F_99 ( T_1 V_107 , T_1 V_127 )
{
return ( V_107 - V_127 ) <= ( 1 << 23 ) ;
}
static int F_100 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_128 * V_129 ,
struct V_63 * V_64 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_108 * V_109 ;
struct V_5 V_102 ;
unsigned long V_23 ;
unsigned int V_107 ;
int V_39 ;
V_109 = F_101 ( sizeof( * V_109 ) , V_42 ) ;
if ( V_109 == NULL ) {
V_39 = - V_40 ;
goto V_130;
}
V_109 -> V_3 = V_3 ;
V_109 -> V_110 . V_81 . type = V_131 ;
V_109 -> V_110 . V_81 . V_132 = sizeof( V_109 -> V_110 ) ;
V_109 -> V_110 . V_133 = V_129 -> V_134 . signal ;
F_23 ( & V_2 -> V_112 , V_23 ) ;
if ( ! F_31 ( V_9 -> V_35 ) ) {
V_39 = - V_49 ;
goto V_135;
}
V_39 = F_102 ( V_2 , V_64 , & V_109 -> V_81 ,
& V_109 -> V_110 . V_81 ) ;
if ( V_39 )
goto V_135;
V_107 = F_64 ( V_2 , V_3 , & V_102 ) ;
F_29 ( L_30 ,
V_129 -> V_134 . V_111 , V_107 , V_3 ) ;
F_103 ( V_64 , V_3 ,
V_129 -> V_134 . V_111 ) ;
V_109 -> V_110 . V_111 = V_129 -> V_134 . V_111 ;
if ( F_99 ( V_107 , V_129 -> V_134 . V_111 ) ) {
F_81 ( V_2 , V_3 ) ;
F_68 ( V_2 , V_109 , V_107 , & V_102 ) ;
V_129 -> V_136 . V_111 = V_107 ;
} else {
F_72 ( & V_109 -> V_81 . V_114 , & V_2 -> V_115 ) ;
V_129 -> V_136 . V_111 = V_129 -> V_134 . V_111 ;
}
F_24 ( & V_2 -> V_112 , V_23 ) ;
return 0 ;
V_135:
F_24 ( & V_2 -> V_112 , V_23 ) ;
F_33 ( V_109 ) ;
V_130:
F_81 ( V_2 , V_3 ) ;
return V_39 ;
}
static bool F_104 ( union V_128 * V_129 )
{
if ( V_129 -> V_134 . V_111 )
return false ;
return V_137 ==
( V_129 -> V_134 . type & ( V_138 |
V_139 |
V_140 ) ) ;
}
int V_128 ( struct V_1 * V_2 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_8 * V_9 ;
union V_128 * V_129 = V_62 ;
int V_39 ;
unsigned int V_23 , V_107 , V_3 , V_141 ;
if ( ! V_2 -> V_51 )
return - V_49 ;
if ( V_129 -> V_134 . type & V_142 )
return - V_49 ;
if ( V_129 -> V_134 . type &
~ ( V_138 | V_143 |
V_144 ) ) {
F_53 ( L_31 ,
V_129 -> V_134 . type ,
( V_138 | V_143 |
V_144 ) ) ;
return - V_49 ;
}
V_23 = V_129 -> V_134 . type & V_143 ;
V_141 = ( V_129 -> V_134 . type & V_144 ) ;
if ( V_141 )
V_3 = V_141 >> V_145 ;
else
V_3 = V_23 & V_146 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_30 )
return - V_49 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( V_2 -> V_45 &&
F_104 ( V_129 ) &&
F_31 ( V_9 -> V_35 ) ) {
struct V_5 V_102 ;
V_129 -> V_136 . V_111 =
F_64 ( V_2 , V_3 , & V_102 ) ;
V_129 -> V_136 . V_147 = V_102 . V_100 ;
V_129 -> V_136 . V_148 = V_102 . V_101 ;
return 0 ;
}
V_39 = F_78 ( V_2 , V_3 ) ;
if ( V_39 ) {
F_29 ( L_32 , V_3 , V_39 ) ;
return V_39 ;
}
V_107 = F_18 ( V_2 , V_3 ) ;
switch ( V_129 -> V_134 . type & V_138 ) {
case V_137 :
V_129 -> V_134 . V_111 += V_107 ;
V_129 -> V_134 . type &= ~ V_137 ;
case V_149 :
break;
default:
V_39 = - V_49 ;
goto V_150;
}
if ( ( V_23 & V_140 ) &&
F_99 ( V_107 , V_129 -> V_134 . V_111 ) )
V_129 -> V_134 . V_111 = V_107 + 1 ;
if ( V_23 & V_139 ) {
return F_100 ( V_2 , V_3 , V_129 , V_64 ) ;
}
if ( V_129 -> V_134 . V_111 != V_107 ) {
F_29 ( L_33 ,
V_129 -> V_134 . V_111 , V_3 ) ;
F_105 ( V_39 , V_9 -> V_44 , 3 * V_119 ,
F_99 ( F_18 ( V_2 , V_3 ) ,
V_129 -> V_134 . V_111 ) ||
! F_31 ( V_9 -> V_35 ) ) ;
}
if ( V_39 != - V_151 ) {
struct V_5 V_102 ;
V_129 -> V_136 . V_111 = F_64 ( V_2 , V_3 , & V_102 ) ;
V_129 -> V_136 . V_147 = V_102 . V_100 ;
V_129 -> V_136 . V_148 = V_102 . V_101 ;
F_29 ( L_34 ,
V_3 , V_129 -> V_136 . V_111 ) ;
} else {
F_29 ( L_35 , V_3 ) ;
}
V_150:
F_81 ( V_2 , V_3 ) ;
return V_39 ;
}
static void F_106 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_108 * V_109 , * V_120 ;
struct V_5 V_102 ;
unsigned int V_107 ;
F_2 ( & V_2 -> V_112 ) ;
V_107 = F_64 ( V_2 , V_3 , & V_102 ) ;
F_91 (e, t, &dev->vblank_event_list, base.link) {
if ( V_109 -> V_3 != V_3 )
continue;
if ( ! F_99 ( V_107 , V_109 -> V_110 . V_111 ) )
continue;
F_29 ( L_36 ,
V_109 -> V_110 . V_111 , V_107 ) ;
F_92 ( & V_109 -> V_81 . V_114 ) ;
F_81 ( V_2 , V_3 ) ;
F_68 ( V_2 , V_109 , V_107 , & V_102 ) ;
}
F_107 ( V_3 , V_107 ) ;
}
bool F_108 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_33 ;
bool V_152 ;
if ( F_6 ( ! V_2 -> V_30 ) )
return false ;
if ( F_19 ( V_3 >= V_2 -> V_30 ) )
return false ;
F_23 ( & V_2 -> V_112 , V_33 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_35 ) {
F_13 ( & V_2 -> V_10 ) ;
F_24 ( & V_2 -> V_112 , V_33 ) ;
return false ;
}
F_14 ( V_2 , V_3 , V_28 ) ;
F_13 ( & V_2 -> V_10 ) ;
F_46 ( & V_9 -> V_44 ) ;
V_152 = ( V_2 -> V_45 &&
V_117 > 0 &&
! F_28 ( & V_9 -> V_37 ) ) ;
F_106 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_112 , V_33 ) ;
if ( V_152 )
F_27 ( ( unsigned long ) V_9 ) ;
return true ;
}
bool F_109 ( struct V_15 * V_16 )
{
return F_108 ( V_16 -> V_2 , F_21 ( V_16 ) ) ;
}
