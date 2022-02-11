static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
struct V_1 * F_3 ( struct V_1 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_6 ;
if ( F_4 ( ! V_5 ) )
return NULL ;
if ( F_4 ( ! V_5 -> V_7 . V_8 ) )
return NULL ;
V_3 = F_5 ( V_5 -> V_7 . V_8 , L_1 , 0 ) ;
if ( ! V_3 )
return NULL ;
V_6 = F_1 ( V_3 ) ;
F_6 ( V_3 ) ;
return V_6 ;
}
struct V_1 * F_7 ( struct V_1 * V_6 , int V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_5 ;
if ( F_4 ( ! V_6 ) )
return NULL ;
if ( ! V_6 -> V_7 . V_8 )
return NULL ;
V_3 = F_5 ( V_6 -> V_7 . V_8 , L_2 , V_9 ) ;
if ( ! V_3 )
return NULL ;
V_5 = F_1 ( V_3 ) ;
F_6 ( V_3 ) ;
return V_5 ;
}
static void * F_8 ( struct V_10 * V_7 , T_1 V_11 ,
T_2 * V_12 , T_3 V_13 ,
unsigned long V_14 )
{
F_9 () ;
return NULL ;
}
static void F_10 ( struct V_10 * V_7 , T_1 V_11 ,
void * V_15 , T_2 V_12 ,
unsigned long V_14 )
{
F_9 () ;
}
static T_2 F_11 ( struct V_10 * V_7 , struct V_16 * V_16 ,
unsigned long V_17 , T_1 V_11 ,
enum V_18 V_19 ,
unsigned long V_14 )
{
F_9 () ;
return 0 ;
}
static int F_12 ( struct V_10 * V_7 , struct V_20 * V_21 ,
int V_22 , enum V_18 V_19 ,
unsigned long V_14 )
{
F_9 () ;
return 0 ;
}
static int F_13 ( struct V_10 * V_7 , T_4 V_23 )
{
F_9 () ;
return 0 ;
}
static T_4 F_14 ( struct V_10 * V_7 )
{
F_9 () ;
return 0 ;
}
static struct V_24 * F_15 ( struct V_24 * V_25 ,
struct V_1 * * V_6 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
struct V_24 * V_31 ;
struct V_32 * V_33 ;
V_30 = F_3 ( V_25 -> V_30 ) ;
if ( ! V_30 )
return NULL ;
V_33 = F_16 ( V_30 ) ;
if ( F_4 ( ! V_33 || V_33 -> V_34 == V_35 ) )
return NULL ;
V_29 = F_17 ( V_30 -> V_36 ) ;
V_27 = V_29 -> V_37 ;
V_31 = & V_27 -> V_38 . V_39 [ V_33 -> V_34 ] ;
if ( V_6 )
* V_6 = V_30 ;
return V_31 ;
}
long F_18 ( struct V_24 * V_25 , int V_40 ,
struct V_41 * V_42 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 ;
const unsigned long V_11 = V_42 -> V_44 ?
V_42 -> V_45 : V_42 -> V_46 ;
const T_6 V_47 = V_42 -> V_48 << V_42 -> V_49 ;
const T_6 V_50 = V_42 -> V_46 << V_42 -> V_49 ;
F_19 ( V_25 , L_3 ,
V_47 , V_47 + V_50 - 1 ,
F_20 ( V_42 ) ) ;
V_43 = F_21 ( V_27 -> V_51 ,
V_25 -> V_34 ,
V_25 -> V_34 ,
V_42 -> V_44 + 1 ,
F_22 ( V_42 -> V_52 ) ,
V_11 << 3 ,
F_20 ( V_42 ) ) ;
if ( V_43 ) {
F_23 ( V_25 , L_4 , V_43 ) ;
return V_43 ;
}
F_24 ( V_27 , false ) ;
F_25 ( V_27 -> V_29 -> V_53 , V_40 ,
V_42 , & V_25 -> V_54 ) ;
return 0 ;
}
long F_26 ( struct V_24 * V_25 , int V_40 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 ;
F_19 ( V_25 , L_5 ) ;
V_43 = F_21 ( V_27 -> V_51 , V_25 -> V_34 ,
V_25 -> V_34 ,
0 , 0 ,
0 , 0 ) ;
if ( V_43 ) {
F_23 ( V_25 , L_6 , V_43 ) ;
return V_43 ;
}
F_24 ( V_27 , false ) ;
F_27 ( V_25 -> V_54 . V_55 [ V_40 ] ,
& V_25 -> V_54 ) ;
return 0 ;
}
static void F_28 ( struct V_24 * V_25 )
{
struct V_1 * V_6 ;
struct V_24 * V_56 ;
T_5 V_43 ;
if ( ! V_25 -> V_30 || ! ( V_25 -> V_57 & V_58 ) )
return;
V_56 = F_15 ( V_25 , & V_6 ) ;
if ( ! V_56 )
return;
V_43 = F_18 ( V_25 , 0 , V_56 -> V_54 . V_55 [ 0 ] ) ;
F_29 ( & V_25 -> V_30 -> V_7 , & V_59 ) ;
}
static int F_30 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 = 0 ;
T_7 V_60 = F_31 () ;
if ( V_27 -> type != V_61 || ! V_25 -> V_30 )
return - V_62 ;
V_43 = F_26 ( V_25 , 0 ) ;
if ( V_43 != V_63 )
return V_43 ;
V_60 = F_32 ( V_60 ) ;
F_33 ( & V_25 -> V_30 -> V_7 , L_7 ,
V_25 -> V_34 ) ;
V_43 = F_34 ( V_27 -> V_51 ,
V_25 -> V_34 , V_25 -> V_34 ,
0 , V_60 ) ;
if ( V_43 == V_63 )
F_24 ( V_27 , false ) ;
return V_43 ;
}
void F_35 ( struct V_1 * V_6 , bool V_64 )
{
int V_65 ;
struct V_26 * V_27 ;
struct V_32 * V_33 ;
struct V_24 * V_25 ;
struct V_1 * V_5 ;
for ( V_65 = 0 ; ; ++ V_65 ) {
V_5 = F_7 ( V_6 , V_65 ) ;
if ( ! V_5 )
break;
V_33 = F_16 ( V_5 ) ;
if ( F_4 ( ! V_33 || V_33 -> V_34 == V_35 ) )
return;
V_27 = F_17 ( V_5 -> V_36 ) -> V_37 ;
V_25 = & V_27 -> V_38 . V_39 [ V_33 -> V_34 ] ;
if ( V_64 ) {
F_33 ( & V_5 -> V_7 ,
L_8 ) ;
F_30 ( V_25 ) ;
} else {
F_33 ( & V_5 -> V_7 , L_9 ) ;
F_28 ( V_25 ) ;
}
}
}
void F_36 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 ;
if ( V_25 -> V_54 . V_55 [ 0 ] ) {
F_26 ( V_25 , 0 ) ;
return;
}
V_43 = F_34 ( V_27 -> V_51 ,
V_25 -> V_34 , V_25 -> V_34 ,
0 , 0 ) ;
if ( V_43 ) {
F_23 ( V_25 , L_10 , V_43 ) ;
return;
}
F_24 ( V_25 -> V_27 , false ) ;
}
struct V_24 * F_37 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_66 * V_67 = V_27 -> V_29 -> V_36 ;
struct V_1 * V_5 , * V_6 = NULL , * V_68 ;
struct V_24 * V_56 = F_15 ( V_25 , & V_6 ) ;
if ( ! V_56 || ! V_6 )
return NULL ;
F_38 (npdev, &pbus->devices, bus_list) {
V_68 = F_3 ( V_5 ) ;
if ( V_68 != V_6 )
continue;
F_19 ( V_56 , L_11 , F_39 ( & V_5 -> V_7 ) ) ;
F_40 ( V_56 -> V_54 . V_69 , & V_5 -> V_7 ) ;
}
return V_56 ;
}
static int F_41 ( struct V_70 * V_70 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_70 -> V_71 ; V_65 ++ ) {
if ( ! F_42 ( V_65 , & V_70 -> V_72 ) )
return V_65 ;
}
return - V_73 ;
}
static void F_43 ( struct V_70 * V_70 , int V_74 )
{
F_44 ( V_74 , & V_70 -> V_72 ) ;
}
static int F_45 ( struct V_70 * V_70 , unsigned long V_75 ,
unsigned long V_76 )
{
int V_77 ;
do {
V_77 = F_41 ( V_70 ) ;
F_46 () ;
} while ( V_77 < 0 );
F_47 ( F_48 ( V_76 ) ,
V_70 -> V_78 [ V_77 ] + V_79 ) ;
F_49 () ;
F_47 ( F_48 ( V_75 ) , V_70 -> V_78 [ V_77 ] ) ;
return V_77 ;
}
static int F_50 ( struct V_70 * V_70 , unsigned long V_80 , bool V_81 )
{
unsigned long V_75 ;
V_75 = F_51 ( 12 ) ;
V_75 |= F_51 ( 13 ) ;
V_75 |= ( T_4 ) F_52 ( V_82 ) << F_53 ( 17 ) ;
V_75 |= V_80 << F_53 ( 38 ) ;
V_75 |= ! V_81 << F_53 ( 39 ) ;
return F_45 ( V_70 , V_75 , 0 ) ;
}
static int F_54 ( struct V_70 * V_70 , unsigned long V_76 ,
unsigned long V_80 , bool V_81 )
{
unsigned long V_75 ;
V_75 = 0 ;
V_75 |= F_51 ( 13 ) ;
V_75 |= ( T_4 ) F_52 ( V_82 ) << F_53 ( 17 ) ;
V_75 |= V_80 << F_53 ( 38 ) ;
V_75 |= ! V_81 << F_53 ( 39 ) ;
return F_45 ( V_70 , V_75 , V_76 ) ;
}
static void F_55 (
struct V_77 V_77 [ V_83 ] , bool V_81 )
{
struct V_70 * V_70 ;
int V_65 , V_74 ;
for ( V_65 = 0 ; V_65 <= V_84 ; V_65 ++ ) {
if ( V_77 [ V_65 ] . V_74 < 0 )
continue;
V_70 = V_77 [ V_65 ] . V_70 ;
V_74 = V_77 [ V_65 ] . V_74 ;
while ( F_56 ( V_70 -> V_78 [ V_74 ] + V_85 ) )
F_46 () ;
F_43 ( V_70 , V_74 ) ;
if ( V_81 )
F_50 ( V_70 , 0 , true ) ;
}
}
static void F_57 ( struct V_86 * V_86 , int V_76 ,
unsigned long V_87 , bool V_81 )
{
int V_65 , V_88 ;
struct V_70 * V_70 ;
struct V_26 * V_89 ;
struct V_1 * V_5 ;
struct V_77 V_77 [ V_83 ] ;
unsigned long V_80 = V_86 -> V_90 -> V_91 . V_92 ;
for ( V_65 = 0 ; V_65 <= V_84 ; V_65 ++ ) {
V_77 [ V_65 ] . V_74 = - 1 ;
for ( V_88 = 0 ; V_88 < V_93 ; V_88 ++ ) {
V_5 = V_86 -> V_5 [ V_65 ] [ V_88 ] ;
if ( ! V_5 )
continue;
V_89 = F_17 ( V_5 -> V_36 ) -> V_37 ;
V_70 = & V_89 -> V_70 ;
V_77 [ V_65 ] . V_70 = V_70 ;
if ( V_76 )
V_77 [ V_65 ] . V_74 =
F_54 ( V_70 , V_87 , V_80 ,
V_81 ) ;
else
V_77 [ V_65 ] . V_74 =
F_50 ( V_70 , V_80 , V_81 ) ;
break;
}
}
F_58 ( V_86 -> V_90 ) ;
F_55 ( V_77 , V_81 ) ;
if ( V_81 )
F_55 ( V_77 , false ) ;
}
static void F_59 ( struct V_94 * V_95 ,
struct V_96 * V_90 )
{
struct V_86 * V_86 = F_60 ( V_95 ) ;
if ( V_86 -> V_97 )
V_86 -> V_97 ( V_86 , V_86 -> V_98 ) ;
F_57 ( V_86 , 0 , 0 , true ) ;
}
static void F_61 ( struct V_94 * V_95 ,
struct V_96 * V_90 ,
unsigned long V_87 ,
T_8 V_99 )
{
struct V_86 * V_86 = F_60 ( V_95 ) ;
F_57 ( V_86 , 1 , V_87 , true ) ;
}
static void F_62 ( struct V_94 * V_95 ,
struct V_96 * V_90 ,
unsigned long V_100 , unsigned long V_101 )
{
struct V_86 * V_86 = F_60 ( V_95 ) ;
unsigned long V_87 ;
for ( V_87 = V_100 ; V_87 < V_101 ; V_87 += V_102 )
F_57 ( V_86 , 1 , V_87 , false ) ;
F_57 ( V_86 , 1 , V_87 , true ) ;
}
static void F_63 ( struct V_103 * V_103 )
{
struct V_86 * V_86 =
F_64 ( V_103 , struct V_86 , V_103 ) ;
V_86 -> V_90 -> V_91 . V_86 = NULL ;
F_65 ( & V_86 -> V_95 ,
V_86 -> V_90 ) ;
F_66 ( V_86 ) ;
}
void F_67 ( struct V_86 * V_86 ,
struct V_1 * V_6 )
{
struct V_26 * V_89 ;
struct V_70 * V_70 ;
struct V_1 * V_5 = F_7 ( V_6 , 0 ) ;
struct V_2 * V_104 ;
T_9 V_105 ;
if ( F_4 ( ! V_5 ) )
return;
if ( ! F_68 ( V_106 ) )
return;
V_89 = F_17 ( V_5 -> V_36 ) -> V_37 ;
V_70 = & V_89 -> V_70 ;
V_104 = F_5 ( V_5 -> V_7 . V_8 , L_12 , 0 ) ;
if ( F_4 ( F_69 ( V_104 , L_13 ,
& V_105 ) ) )
return;
V_86 -> V_5 [ V_70 -> V_9 ] [ V_105 ] = NULL ;
F_70 ( V_89 -> V_51 , V_86 -> V_90 -> V_91 . V_92 ,
F_71 ( V_6 -> V_36 -> V_107 , V_6 -> V_108 ) ) ;
F_72 ( & V_86 -> V_103 , F_63 ) ;
}
int F_73 ( struct V_86 * V_91 , T_10 * V_109 ,
unsigned long * V_57 , unsigned long * V_110 , int V_111 )
{
T_4 V_43 = 0 , V_112 = 0 ;
int V_65 , V_113 ;
struct V_16 * V_16 [ 1 ] ;
struct V_96 * V_90 = V_91 -> V_90 ;
if ( ! F_68 ( V_106 ) )
return - V_114 ;
F_4 ( ! F_74 ( & V_90 -> V_115 ) ) ;
for ( V_65 = 0 ; V_65 < V_111 ; V_65 ++ ) {
V_113 = V_57 [ V_65 ] & V_116 ;
V_43 = F_75 ( NULL , V_90 , V_109 [ V_65 ] , 1 ,
V_113 ? V_117 : 0 ,
V_16 , NULL , NULL ) ;
if ( V_43 != 1 ) {
V_110 [ V_65 ] = V_43 ;
V_112 = - V_118 ;
continue;
}
V_110 [ V_65 ] = 0 ;
F_76 ( V_16 [ 0 ] ) ;
}
return V_112 ;
}
int F_77 ( struct V_26 * V_27 )
{
unsigned int V_65 ;
T_4 V_119 ;
struct V_2 * V_3 ;
struct V_1 * V_6 ;
static int V_120 ;
T_11 V_43 = 0 ;
F_78 (phb->hose->dn, dn) {
V_6 = F_3 ( F_1 ( V_3 ) ) ;
if ( V_6 ) {
V_43 = F_79 ( V_27 -> V_51 ,
F_71 ( V_6 -> V_36 -> V_107 , V_6 -> V_108 ) ,
0 , 0 ) ;
if ( V_43 )
F_80 ( & V_6 -> V_7 ,
L_14 ,
V_43 ) ;
}
}
for ( V_65 = 0 ; ! F_81 ( V_27 -> V_29 -> V_3 , L_15 ,
V_65 , & V_119 ) ; V_65 ++ )
V_27 -> V_70 . V_78 [ V_65 ] = F_82 ( V_119 , 32 ) ;
F_83 ( L_16 , V_27 -> V_51 , V_65 ) ;
V_27 -> V_70 . V_71 = V_65 ;
V_27 -> V_70 . V_72 = 0 ;
V_120 ++ ;
if ( F_4 ( V_120 >= V_83 ) )
return - V_73 ;
V_84 = V_120 ;
V_27 -> V_70 . V_9 = V_120 ;
return 0 ;
}
