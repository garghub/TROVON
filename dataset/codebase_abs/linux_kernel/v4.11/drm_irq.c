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
int F_36 ( struct V_1 * V_2 , int V_45 )
{
int V_38 ;
unsigned long V_46 = 0 ;
if ( ! F_26 ( V_2 , V_47 ) )
return - V_48 ;
if ( V_45 == 0 )
return - V_48 ;
if ( ! V_2 -> V_49 )
return - V_48 ;
if ( V_2 -> V_50 )
return - V_51 ;
V_2 -> V_50 = true ;
F_24 ( L_14 , V_45 ) ;
if ( V_2 -> V_16 -> V_52 )
V_2 -> V_16 -> V_52 ( V_2 ) ;
if ( F_26 ( V_2 , V_53 ) )
V_46 = V_54 ;
V_38 = F_37 ( V_45 , V_2 -> V_16 -> V_55 ,
V_46 , V_2 -> V_16 -> V_56 , V_2 ) ;
if ( V_38 < 0 ) {
V_2 -> V_50 = false ;
return V_38 ;
}
if ( V_2 -> V_16 -> V_57 )
V_38 = V_2 -> V_16 -> V_57 ( V_2 ) ;
if ( V_38 < 0 ) {
V_2 -> V_50 = false ;
if ( F_26 ( V_2 , V_58 ) )
F_38 ( V_2 -> V_59 , NULL , NULL , NULL ) ;
F_39 ( V_45 , V_2 ) ;
} else {
V_2 -> V_45 = V_45 ;
}
return V_38 ;
}
int F_40 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
bool V_50 ;
int V_40 ;
if ( ! F_26 ( V_2 , V_47 ) )
return - V_48 ;
V_50 = V_2 -> V_50 ;
V_2 -> V_50 = false ;
if ( V_2 -> V_26 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_26 ; V_40 ++ ) {
struct V_8 * V_9 = & V_2 -> V_9 [ V_40 ] ;
if ( ! V_9 -> V_31 )
continue;
F_15 ( F_26 ( V_2 , V_36 ) ) ;
F_21 ( V_2 , V_40 ) ;
F_41 ( & V_9 -> V_43 ) ;
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
}
if ( ! V_50 )
return - V_48 ;
F_24 ( L_14 , V_2 -> V_45 ) ;
if ( F_26 ( V_2 , V_58 ) )
F_38 ( V_2 -> V_59 , NULL , NULL , NULL ) ;
if ( V_2 -> V_16 -> V_60 )
V_2 -> V_16 -> V_60 ( V_2 ) ;
F_39 ( V_2 -> V_45 , V_2 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = V_61 ;
int V_38 = 0 , V_45 ;
if ( ! F_26 ( V_2 , V_47 ) )
return 0 ;
if ( ! F_26 ( V_2 , V_58 ) )
return 0 ;
if ( F_15 ( ! V_2 -> V_59 ) )
return - V_48 ;
switch ( V_65 -> V_66 ) {
case V_67 :
V_45 = V_2 -> V_59 -> V_45 ;
if ( V_2 -> V_68 < F_43 ( 1 , 2 ) &&
V_65 -> V_45 != V_45 )
return - V_48 ;
F_44 ( & V_2 -> V_69 ) ;
V_38 = F_36 ( V_2 , V_45 ) ;
F_45 ( & V_2 -> V_69 ) ;
return V_38 ;
case V_70 :
F_44 ( & V_2 -> V_69 ) ;
V_38 = F_40 ( V_2 ) ;
F_45 ( & V_2 -> V_69 ) ;
return V_38 ;
default:
return - V_48 ;
}
}
void F_46 ( struct V_27 * V_28 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_73 = 0 , V_20 = 0 ;
int V_74 = V_72 -> V_75 ;
if ( ! V_2 -> V_26 )
return;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( V_74 > 0 ) {
int V_76 = V_72 -> V_77 * V_72 -> V_78 ;
V_73 = F_47 ( ( T_2 ) V_72 -> V_77 * 1000000 , V_74 ) ;
V_20 = F_47 ( ( T_2 ) V_76 * 1000000 , V_74 ) ;
if ( V_72 -> V_18 & V_79 )
V_20 /= 2 ;
} else
F_48 ( L_15 ,
V_28 -> V_80 . V_81 ) ;
V_9 -> V_73 = V_73 ;
V_9 -> V_20 = V_20 ;
F_24 ( L_16 ,
V_28 -> V_80 . V_81 , V_72 -> V_77 ,
V_72 -> V_78 , V_72 -> V_82 ) ;
F_24 ( L_17 ,
V_28 -> V_80 . V_81 , V_74 , V_20 , V_73 ) ;
}
int F_49 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int * V_83 ,
struct V_5 * V_84 ,
unsigned V_18 ,
const struct V_71 * V_72 )
{
struct V_5 V_85 ;
T_3 V_86 , V_87 ;
unsigned int V_88 ;
int V_38 = V_89 ;
int V_90 , V_91 , V_40 ;
int V_92 , V_93 ;
if ( V_3 >= V_2 -> V_26 ) {
F_48 ( L_18 , V_3 ) ;
return - V_48 ;
}
if ( ! V_2 -> V_16 -> V_94 ) {
F_48 ( L_19 ) ;
return - V_95 ;
}
if ( V_72 -> V_75 == 0 ) {
F_24 ( L_20 , V_3 ) ;
return - V_96 ;
}
for ( V_40 = 0 ; V_40 < V_15 ; V_40 ++ ) {
V_88 = V_2 -> V_16 -> V_94 ( V_2 , V_3 , V_18 ,
& V_90 , & V_91 ,
& V_86 , & V_87 ,
V_72 ) ;
if ( ! ( V_88 & V_97 ) ) {
F_24 ( L_21 ,
V_3 , V_88 ) ;
return - V_95 ;
}
V_93 = F_50 ( V_87 ) - F_50 ( V_86 ) ;
if ( V_93 <= * V_83 )
break;
}
if ( V_40 == V_15 ) {
F_24 ( L_22 ,
V_3 , V_93 / 1000 , * V_83 / 1000 , V_40 ) ;
}
* V_83 = V_93 ;
if ( V_88 & V_98 )
V_38 |= V_99 ;
V_92 = F_51 ( 1000000LL * ( V_90 * V_72 -> V_77 + V_91 ) ,
V_72 -> V_75 ) ;
if ( ! V_100 )
V_87 = F_52 ( V_87 ) ;
V_85 = F_53 ( V_87 ) ;
V_87 = F_54 ( V_87 , V_92 ) ;
* V_84 = F_53 ( V_87 ) ;
F_12 ( L_23 ,
V_3 , V_88 , V_91 , V_90 ,
( long ) V_85 . V_101 , ( long ) V_85 . V_102 ,
( long ) V_84 -> V_101 , ( long ) V_84 -> V_102 ,
V_93 / 1000 , V_40 ) ;
return V_38 ;
}
static struct V_5 F_55 ( void )
{
T_3 V_103 ;
V_103 = V_100 ? F_56 () : F_57 () ;
return F_53 ( V_103 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_104 , unsigned V_18 )
{
int V_38 ;
int V_83 = ( int ) V_105 * 1000 ;
if ( V_2 -> V_16 -> V_29 && ( V_83 > 0 ) ) {
V_38 = V_2 -> V_16 -> V_29 ( V_2 , V_3 , & V_83 ,
V_104 , V_18 ) ;
if ( V_38 > 0 )
return true ;
}
* V_104 = F_55 () ;
return false ;
}
T_1 F_58 ( struct V_27 * V_28 )
{
return F_14 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
static T_1 F_59 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_5 * V_106 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
T_1 V_107 ;
unsigned int V_108 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) ) {
* V_106 = (struct V_5 ) { 0 } ;
return 0 ;
}
do {
V_108 = F_60 ( & V_9 -> V_11 ) ;
V_107 = V_9 -> V_12 ;
* V_106 = V_9 -> time ;
} while ( F_61 ( & V_9 -> V_11 , V_108 ) );
return V_107 ;
}
T_1 F_62 ( struct V_27 * V_28 ,
struct V_5 * V_106 )
{
return F_59 ( V_28 -> V_2 , F_17 ( V_28 ) ,
V_106 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
unsigned long V_108 , struct V_5 * V_103 )
{
V_110 -> V_111 . V_112 = V_108 ;
V_110 -> V_111 . V_101 = V_103 -> V_101 ;
V_110 -> V_111 . V_102 = V_103 -> V_102 ;
F_64 ( V_110 -> V_80 . V_113 , V_110 -> V_3 ,
V_110 -> V_111 . V_112 ) ;
F_65 ( V_2 , & V_110 -> V_80 ) ;
}
void F_66 ( struct V_27 * V_28 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
F_2 ( & V_2 -> V_114 ) ;
V_110 -> V_3 = V_3 ;
V_110 -> V_111 . V_112 = F_14 ( V_2 , V_3 ) ;
F_67 ( & V_110 -> V_80 . V_115 , & V_2 -> V_116 ) ;
}
void F_68 ( struct V_27 * V_28 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_108 , V_3 = F_17 ( V_28 ) ;
struct V_5 V_103 ;
if ( V_2 -> V_26 > 0 ) {
V_108 = F_59 ( V_2 , V_3 , & V_103 ) ;
} else {
V_108 = 0 ;
V_103 = F_55 () ;
}
V_110 -> V_3 = V_3 ;
F_63 ( V_2 , V_110 , V_108 , & V_103 ) ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_38 = 0 ;
F_2 ( & V_2 -> V_34 ) ;
F_6 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_31 ) {
V_38 = V_2 -> V_16 -> V_117 ( V_2 , V_3 ) ;
F_24 ( L_24 , V_3 , V_38 ) ;
if ( V_38 )
F_70 ( & V_9 -> V_35 ) ;
else {
V_9 -> V_31 = true ;
F_9 ( V_2 , V_3 , 0 ) ;
}
}
F_8 ( & V_2 -> V_10 ) ;
return V_38 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
int V_38 = 0 ;
if ( ! V_2 -> V_26 )
return - V_48 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return - V_48 ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
if ( F_72 ( 1 , & V_9 -> V_35 ) == 1 ) {
V_38 = F_69 ( V_2 , V_3 ) ;
} else {
if ( ! V_9 -> V_31 ) {
F_70 ( & V_9 -> V_35 ) ;
V_38 = - V_48 ;
}
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
return V_38 ;
}
int F_73 ( struct V_27 * V_28 )
{
return F_71 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
static void F_74 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( F_15 ( F_23 ( & V_9 -> V_35 ) == 0 ) )
return;
if ( F_75 ( & V_9 -> V_35 ) ) {
if ( V_118 == 0 )
return;
else if ( V_2 -> V_44 || V_118 < 0 )
F_22 ( ( unsigned long ) V_9 ) ;
else
F_76 ( & V_9 -> V_37 ,
V_119 + ( ( V_118 * V_120 ) / 1000 ) ) ;
}
}
void F_77 ( struct V_27 * V_28 )
{
F_74 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
void F_78 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
int V_38 ;
T_1 V_7 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
V_38 = F_71 ( V_2 , V_3 ) ;
if ( F_18 ( V_38 , L_25 , V_3 , V_38 ) )
return;
V_7 = F_14 ( V_2 , V_3 ) ;
V_38 = F_79 ( V_9 -> V_43 ,
V_7 != F_14 ( V_2 , V_3 ) ,
F_80 ( 100 ) ) ;
F_18 ( V_38 == 0 , L_26 , V_3 ) ;
F_74 ( V_2 , V_3 ) ;
}
void F_81 ( struct V_27 * V_28 )
{
F_78 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
void F_82 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_109 * V_110 , * V_121 ;
struct V_5 V_103 ;
unsigned long V_30 ;
unsigned int V_108 ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
F_19 ( & V_2 -> V_114 , V_30 ) ;
F_6 ( & V_2 -> V_34 ) ;
F_12 ( L_27 ,
V_3 , V_9 -> V_31 , V_9 -> V_25 ) ;
if ( F_26 ( V_2 , V_122 ) || ! V_9 -> V_25 )
F_21 ( V_2 , V_3 ) ;
F_41 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_25 ) {
F_83 ( & V_9 -> V_35 ) ;
V_9 -> V_25 = 1 ;
}
F_8 ( & V_2 -> V_34 ) ;
V_108 = F_59 ( V_2 , V_3 , & V_103 ) ;
F_84 (e, t, &dev->vblank_event_list, base.link) {
if ( V_110 -> V_3 != V_3 )
continue;
F_24 ( L_28
L_29 ,
V_110 -> V_111 . V_112 , V_108 ) ;
F_85 ( & V_110 -> V_80 . V_115 ) ;
F_74 ( V_2 , V_3 ) ;
F_63 ( V_2 , V_110 , V_108 , & V_103 ) ;
}
F_20 ( & V_2 -> V_114 , V_30 ) ;
}
void F_86 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_30 ;
unsigned int V_3 = F_17 ( V_28 ) ;
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
if ( ! V_9 -> V_25 ) {
F_83 ( & V_9 -> V_35 ) ;
V_9 -> V_25 = 1 ;
}
F_20 ( & V_2 -> V_34 , V_30 ) ;
F_15 ( ! F_87 ( & V_2 -> V_116 ) ) ;
}
void F_88 ( struct V_27 * V_28 )
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
F_70 ( & V_9 -> V_35 ) ;
V_9 -> V_25 = 0 ;
}
F_5 ( V_2 , V_3 ) ;
if ( F_23 ( & V_9 -> V_35 ) != 0 || V_118 == 0 )
F_15 ( F_69 ( V_2 , V_3 ) ) ;
F_20 ( & V_2 -> V_34 , V_30 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( ! V_2 -> V_26 )
return;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return;
if ( ! V_9 -> V_25 ) {
V_9 -> V_25 = 0x1 ;
if ( F_71 ( V_2 , V_3 ) == 0 )
V_9 -> V_25 |= 0x2 ;
}
}
static void F_90 ( struct V_1 * V_2 ,
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
F_74 ( V_2 , V_3 ) ;
V_9 -> V_25 = 0 ;
}
}
int F_91 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_123 * V_124 = V_61 ;
unsigned int V_3 ;
if ( ! V_2 -> V_26 )
return 0 ;
if ( ! F_26 ( V_2 , V_58 ) )
return 0 ;
V_3 = V_124 -> V_28 ;
if ( V_3 >= V_2 -> V_26 )
return - V_48 ;
switch ( V_124 -> V_125 ) {
case V_126 :
F_89 ( V_2 , V_3 ) ;
break;
case V_127 :
F_90 ( V_2 , V_3 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , unsigned int V_3 ,
union V_128 * V_129 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
struct V_109 * V_110 ;
struct V_5 V_103 ;
unsigned long V_18 ;
unsigned int V_108 ;
int V_38 ;
V_110 = F_93 ( sizeof( * V_110 ) , V_41 ) ;
if ( V_110 == NULL ) {
V_38 = - V_39 ;
goto V_130;
}
V_110 -> V_3 = V_3 ;
V_110 -> V_80 . V_113 = V_131 -> V_113 ;
V_110 -> V_111 . V_80 . type = V_132 ;
V_110 -> V_111 . V_80 . V_133 = sizeof( V_110 -> V_111 ) ;
V_110 -> V_111 . V_134 = V_129 -> V_135 . signal ;
F_19 ( & V_2 -> V_114 , V_18 ) ;
if ( ! V_9 -> V_31 ) {
V_38 = - V_48 ;
goto V_136;
}
V_38 = F_94 ( V_2 , V_63 , & V_110 -> V_80 ,
& V_110 -> V_111 . V_80 ) ;
if ( V_38 )
goto V_136;
V_108 = F_59 ( V_2 , V_3 , & V_103 ) ;
F_24 ( L_30 ,
V_129 -> V_135 . V_112 , V_108 , V_3 ) ;
F_95 ( V_131 -> V_113 , V_3 ,
V_129 -> V_135 . V_112 ) ;
V_110 -> V_111 . V_112 = V_129 -> V_135 . V_112 ;
if ( ( V_108 - V_129 -> V_135 . V_112 ) <= ( 1 << 23 ) ) {
F_74 ( V_2 , V_3 ) ;
F_63 ( V_2 , V_110 , V_108 , & V_103 ) ;
V_129 -> V_137 . V_112 = V_108 ;
} else {
F_67 ( & V_110 -> V_80 . V_115 , & V_2 -> V_116 ) ;
V_129 -> V_137 . V_112 = V_129 -> V_135 . V_112 ;
}
F_20 ( & V_2 -> V_114 , V_18 ) ;
return 0 ;
V_136:
F_20 ( & V_2 -> V_114 , V_18 ) ;
F_28 ( V_110 ) ;
V_130:
F_74 ( V_2 , V_3 ) ;
return V_38 ;
}
int V_128 ( struct V_1 * V_2 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 ;
union V_128 * V_129 = V_61 ;
int V_38 ;
unsigned int V_18 , V_108 , V_3 , V_138 ;
if ( ! V_2 -> V_50 )
return - V_48 ;
if ( V_129 -> V_135 . type & V_139 )
return - V_48 ;
if ( V_129 -> V_135 . type &
~ ( V_140 | V_141 |
V_142 ) ) {
F_48 ( L_31 ,
V_129 -> V_135 . type ,
( V_140 | V_141 |
V_142 ) ) ;
return - V_48 ;
}
V_18 = V_129 -> V_135 . type & V_141 ;
V_138 = ( V_129 -> V_135 . type & V_142 ) ;
if ( V_138 )
V_3 = V_138 >> V_143 ;
else
V_3 = V_18 & V_144 ? 1 : 0 ;
if ( V_3 >= V_2 -> V_26 )
return - V_48 ;
V_9 = & V_2 -> V_9 [ V_3 ] ;
V_38 = F_71 ( V_2 , V_3 ) ;
if ( V_38 ) {
F_24 ( L_32 , V_38 ) ;
return V_38 ;
}
V_108 = F_14 ( V_2 , V_3 ) ;
switch ( V_129 -> V_135 . type & V_140 ) {
case V_145 :
V_129 -> V_135 . V_112 += V_108 ;
V_129 -> V_135 . type &= ~ V_145 ;
case V_146 :
break;
default:
V_38 = - V_48 ;
goto V_147;
}
if ( ( V_18 & V_148 ) &&
( V_108 - V_129 -> V_135 . V_112 ) <= ( 1 << 23 ) ) {
V_129 -> V_135 . V_112 = V_108 + 1 ;
}
if ( V_18 & V_149 ) {
return F_92 ( V_2 , V_3 , V_129 , V_63 ) ;
}
F_24 ( L_33 ,
V_129 -> V_135 . V_112 , V_3 ) ;
F_96 ( V_38 , V_9 -> V_43 , 3 * V_120 ,
( ( ( F_14 ( V_2 , V_3 ) -
V_129 -> V_135 . V_112 ) <= ( 1 << 23 ) ) ||
! V_9 -> V_31 ||
! V_2 -> V_50 ) ) ;
if ( V_38 != - V_150 ) {
struct V_5 V_103 ;
V_129 -> V_137 . V_112 = F_59 ( V_2 , V_3 , & V_103 ) ;
V_129 -> V_137 . V_151 = V_103 . V_101 ;
V_129 -> V_137 . V_152 = V_103 . V_102 ;
F_24 ( L_34 ,
V_129 -> V_137 . V_112 ) ;
} else {
F_24 ( L_35 ) ;
}
V_147:
F_74 ( V_2 , V_3 ) ;
return V_38 ;
}
static void F_97 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_109 * V_110 , * V_121 ;
struct V_5 V_103 ;
unsigned int V_108 ;
F_2 ( & V_2 -> V_114 ) ;
V_108 = F_59 ( V_2 , V_3 , & V_103 ) ;
F_84 (e, t, &dev->vblank_event_list, base.link) {
if ( V_110 -> V_3 != V_3 )
continue;
if ( ( V_108 - V_110 -> V_111 . V_112 ) > ( 1 << 23 ) )
continue;
F_24 ( L_36 ,
V_110 -> V_111 . V_112 , V_108 ) ;
F_85 ( & V_110 -> V_80 . V_115 ) ;
F_74 ( V_2 , V_3 ) ;
F_63 ( V_2 , V_110 , V_108 , & V_103 ) ;
}
F_98 ( V_3 , V_108 ) ;
}
bool F_99 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_3 ] ;
unsigned long V_30 ;
if ( F_13 ( ! V_2 -> V_26 ) )
return false ;
if ( F_15 ( V_3 >= V_2 -> V_26 ) )
return false ;
F_19 ( & V_2 -> V_114 , V_30 ) ;
F_6 ( & V_2 -> V_10 ) ;
if ( ! V_9 -> V_31 ) {
F_8 ( & V_2 -> V_10 ) ;
F_20 ( & V_2 -> V_114 , V_30 ) ;
return false ;
}
F_9 ( V_2 , V_3 , V_24 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_41 ( & V_9 -> V_43 ) ;
F_97 ( V_2 , V_3 ) ;
F_20 ( & V_2 -> V_114 , V_30 ) ;
return true ;
}
bool F_100 ( struct V_27 * V_28 )
{
return F_99 ( V_28 -> V_2 , F_17 ( V_28 ) ) ;
}
T_1 F_101 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_13 ( V_2 -> V_21 != 0 ) ;
return 0 ;
}
