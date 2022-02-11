int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 , V_3 ) ;
if ( V_1 == NULL )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
F_6 ( V_7 L_1 ,
V_6 -> V_8 ,
( unsigned long long ) V_6 -> V_9 ) ;
}
static void F_7 ( struct V_10 * V_10 )
{
int V_11 ;
struct V_12 * V_13 ;
F_8 (bvec, bio, i) {
struct V_14 * V_14 = V_13 -> V_15 ;
#ifdef F_9
struct V_14 * V_16 = NULL ;
#endif
struct V_5 * V_6 , * V_17 ;
unsigned V_18 = V_13 -> V_19 ;
unsigned V_20 = V_18 + V_13 -> V_21 ;
unsigned V_22 = 0 ;
unsigned long V_23 ;
if ( ! V_14 )
continue;
#ifdef F_9
if ( ! V_14 -> V_24 ) {
V_16 = V_14 ;
F_10 ( & V_14 , false ) ;
}
#endif
if ( V_10 -> V_25 ) {
F_11 ( V_14 ) ;
F_12 ( V_14 -> V_24 , - V_26 ) ;
}
V_6 = V_17 = F_13 ( V_14 ) ;
F_14 ( V_23 ) ;
F_15 ( V_27 , & V_17 -> V_28 ) ;
do {
if ( F_16 ( V_6 ) < V_18 ||
F_16 ( V_6 ) + V_6 -> V_29 > V_20 ) {
if ( F_17 ( V_6 ) )
V_22 ++ ;
continue;
}
F_18 ( V_6 ) ;
if ( V_10 -> V_25 )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_30 ) != V_17 );
F_19 ( V_27 , & V_17 -> V_28 ) ;
F_20 ( V_23 ) ;
if ( ! V_22 ) {
#ifdef F_9
if ( V_16 )
F_21 ( V_16 ) ;
#endif
F_22 ( V_14 ) ;
}
}
}
static void F_23 ( T_2 * V_31 )
{
struct V_10 * V_10 , * V_32 ;
F_24 ( ! F_25 ( & V_31 -> V_33 ) ) ;
F_24 ( V_31 -> V_34 & V_35 ) ;
F_26 ( V_31 -> V_36 ) ;
for ( V_10 = V_31 -> V_10 ; V_10 ; V_10 = V_32 ) {
V_32 = V_10 -> V_37 ;
F_7 ( V_10 ) ;
F_27 ( V_10 ) ;
}
F_28 ( V_1 , V_31 ) ;
}
static int F_29 ( T_2 * V_38 )
{
struct V_39 * V_39 = V_38 -> V_39 ;
T_3 V_40 = V_38 -> V_40 ;
T_4 V_41 = V_38 -> V_41 ;
T_5 * V_36 = V_38 -> V_36 ;
int V_42 = 0 ;
F_30 ( L_2
L_3 ,
V_38 , V_39 -> V_43 , V_38 -> V_33 . V_44 , V_38 -> V_33 . V_45 ) ;
V_38 -> V_36 = NULL ;
V_42 = F_31 ( V_36 , V_39 , V_40 , V_41 ) ;
if ( V_42 < 0 && ! F_32 ( F_33 ( V_39 -> V_46 ) ) ) {
F_34 ( V_39 -> V_46 , V_47 ,
L_4
L_5
L_6 ,
V_39 -> V_43 , V_40 , V_41 , V_42 ) ;
}
F_35 ( V_38 ) ;
F_23 ( V_38 ) ;
return V_42 ;
}
static void F_36 ( struct V_39 * V_39 , struct V_48 * V_17 )
{
#ifdef F_37
struct V_48 * V_49 , * V_50 , * V_51 ;
T_2 * V_38 , * V_52 , * V_53 ;
if ( F_25 ( V_17 ) )
return;
F_30 ( L_7 , V_39 -> V_43 ) ;
F_38 (io, head, list) {
V_49 = & V_38 -> V_33 ;
V_50 = V_49 -> V_45 ;
V_52 = F_39 ( V_50 , T_2 , V_33 ) ;
V_51 = V_49 -> V_44 ;
V_53 = F_39 ( V_51 , T_2 , V_33 ) ;
F_30 ( L_8 ,
V_38 , V_39 -> V_43 , V_52 , V_53 ) ;
}
#endif
}
static void F_40 ( T_2 * V_31 )
{
struct V_54 * V_55 = F_41 ( V_31 -> V_39 ) ;
struct V_56 * V_57 = F_33 ( V_31 -> V_39 -> V_46 ) ;
struct V_58 * V_59 ;
unsigned long V_23 ;
F_26 ( ! ( V_31 -> V_34 & V_35 ) ) ;
F_26 ( ! V_31 -> V_36 && V_57 -> V_60 ) ;
F_42 ( & V_55 -> V_61 , V_23 ) ;
V_59 = V_57 -> V_62 ;
if ( F_25 ( & V_55 -> V_63 ) )
F_43 ( V_59 , & V_55 -> V_64 ) ;
F_44 ( & V_31 -> V_33 , & V_55 -> V_63 ) ;
F_45 ( & V_55 -> V_61 , V_23 ) ;
}
static int F_46 ( struct V_39 * V_39 ,
struct V_48 * V_17 )
{
T_2 * V_38 ;
struct V_48 V_65 ;
unsigned long V_23 ;
struct V_54 * V_55 = F_41 ( V_39 ) ;
int V_66 , V_42 = 0 ;
F_42 ( & V_55 -> V_61 , V_23 ) ;
F_36 ( V_39 , V_17 ) ;
F_47 ( V_17 , & V_65 ) ;
F_45 ( & V_55 -> V_61 , V_23 ) ;
while ( ! F_25 ( & V_65 ) ) {
V_38 = F_48 ( V_65 . V_44 , T_2 , V_33 ) ;
F_24 ( ! ( V_38 -> V_34 & V_35 ) ) ;
F_49 ( & V_38 -> V_33 ) ;
V_66 = F_29 ( V_38 ) ;
if ( F_50 ( ! V_42 && V_66 ) )
V_42 = V_66 ;
}
return V_42 ;
}
void F_51 ( struct V_67 * V_68 )
{
struct V_54 * V_55 = F_39 ( V_68 , struct V_54 ,
V_64 ) ;
F_46 ( & V_55 -> V_69 , & V_55 -> V_63 ) ;
}
T_2 * F_52 ( struct V_39 * V_39 , T_6 V_23 )
{
T_2 * V_38 = F_53 ( V_1 , V_23 ) ;
if ( V_38 ) {
V_38 -> V_39 = V_39 ;
F_54 ( & V_38 -> V_33 ) ;
F_55 ( & V_38 -> V_70 , 1 ) ;
}
return V_38 ;
}
void F_56 ( T_2 * V_31 )
{
if ( F_57 ( & V_31 -> V_70 ) ) {
if ( ! ( V_31 -> V_34 & V_35 ) || ! V_31 -> V_41 ) {
F_23 ( V_31 ) ;
return;
}
F_40 ( V_31 ) ;
}
}
int F_58 ( T_2 * V_31 )
{
int V_66 = 0 ;
if ( F_57 ( & V_31 -> V_70 ) ) {
if ( V_31 -> V_34 & V_35 ) {
V_66 = F_31 ( V_31 -> V_36 ,
V_31 -> V_39 , V_31 -> V_40 ,
V_31 -> V_41 ) ;
V_31 -> V_36 = NULL ;
F_35 ( V_31 ) ;
}
F_23 ( V_31 ) ;
}
return V_66 ;
}
T_2 * F_59 ( T_2 * V_31 )
{
F_60 ( & V_31 -> V_70 ) ;
return V_31 ;
}
static void F_61 ( struct V_10 * V_10 )
{
T_2 * V_31 = V_10 -> V_37 ;
T_7 V_71 = V_10 -> V_72 . V_71 ;
char V_73 [ V_74 ] ;
if ( F_62 ( ! V_31 , L_9 ,
F_63 ( V_10 -> V_75 , V_73 ) ,
( long long ) V_10 -> V_72 . V_71 ,
( unsigned ) F_64 ( V_10 ) ,
V_10 -> V_25 ) ) {
F_7 ( V_10 ) ;
F_27 ( V_10 ) ;
return;
}
V_10 -> V_76 = NULL ;
if ( V_10 -> V_25 ) {
struct V_39 * V_39 = V_31 -> V_39 ;
F_65 ( V_39 -> V_46 , L_10
L_11 ,
V_10 -> V_25 , V_39 -> V_43 ,
( unsigned long long ) V_31 -> V_40 ,
( long ) V_31 -> V_41 ,
( unsigned long long )
V_71 >> ( V_39 -> V_77 - 9 ) ) ;
F_12 ( V_39 -> V_78 ,
F_66 ( V_10 -> V_25 ) ) ;
}
if ( V_31 -> V_34 & V_35 ) {
V_10 -> V_37 = F_67 ( & V_31 -> V_10 , V_10 ) ;
F_56 ( V_31 ) ;
} else {
F_56 ( V_31 ) ;
F_7 ( V_10 ) ;
F_27 ( V_10 ) ;
}
}
void F_68 ( struct F_68 * V_38 )
{
struct V_10 * V_10 = V_38 -> V_79 ;
if ( V_10 ) {
int V_80 = V_38 -> V_81 -> V_82 == V_83 ?
V_84 : 0 ;
V_38 -> V_79 -> V_85 = V_38 -> V_31 -> V_39 -> V_86 ;
F_69 ( V_38 -> V_79 , V_87 , V_80 ) ;
F_70 ( V_38 -> V_79 ) ;
}
V_38 -> V_79 = NULL ;
}
void F_71 ( struct F_68 * V_38 ,
struct V_88 * V_89 )
{
V_38 -> V_81 = V_89 ;
V_38 -> V_79 = NULL ;
V_38 -> V_31 = NULL ;
}
static int F_72 ( struct F_68 * V_38 ,
struct V_5 * V_6 )
{
struct V_10 * V_10 ;
V_10 = F_73 ( V_90 , V_91 ) ;
if ( ! V_10 )
return - V_4 ;
F_74 ( V_38 -> V_81 , V_10 ) ;
V_10 -> V_72 . V_71 = V_6 -> V_9 * ( V_6 -> V_29 >> 9 ) ;
V_10 -> V_75 = V_6 -> V_8 ;
V_10 -> V_76 = F_61 ;
V_10 -> V_37 = F_59 ( V_38 -> V_31 ) ;
V_38 -> V_79 = V_10 ;
V_38 -> V_92 = V_6 -> V_9 ;
return 0 ;
}
static int F_75 ( struct F_68 * V_38 ,
struct V_39 * V_39 ,
struct V_14 * V_14 ,
struct V_5 * V_6 )
{
int V_42 ;
if ( V_38 -> V_79 && V_6 -> V_9 != V_38 -> V_92 ) {
V_93:
F_68 ( V_38 ) ;
}
if ( V_38 -> V_79 == NULL ) {
V_42 = F_72 ( V_38 , V_6 ) ;
if ( V_42 )
return V_42 ;
V_38 -> V_79 -> V_85 = V_39 -> V_86 ;
}
V_42 = F_76 ( V_38 -> V_79 , V_14 , V_6 -> V_29 , F_16 ( V_6 ) ) ;
if ( V_42 != V_6 -> V_29 )
goto V_93;
F_77 ( V_38 -> V_81 , V_14 , V_6 -> V_29 ) ;
V_38 -> V_92 ++ ;
return 0 ;
}
int F_78 ( struct F_68 * V_38 ,
struct V_14 * V_14 ,
int V_94 ,
struct V_88 * V_89 ,
bool V_95 )
{
struct V_14 * V_16 = NULL ;
struct V_39 * V_39 = V_14 -> V_24 -> V_96 ;
unsigned V_97 ;
struct V_5 * V_6 , * V_17 ;
int V_42 = 0 ;
int V_98 = 0 ;
int V_99 = 0 ;
F_24 ( ! F_79 ( V_14 ) ) ;
F_24 ( F_80 ( V_14 ) ) ;
if ( V_95 )
F_81 ( V_14 ) ;
else
F_82 ( V_14 ) ;
F_83 ( V_14 ) ;
if ( V_94 < V_100 )
F_84 ( V_14 , V_94 , V_100 ) ;
V_6 = V_17 = F_13 ( V_14 ) ;
do {
V_97 = F_16 ( V_6 ) ;
if ( V_97 >= V_94 ) {
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
continue;
}
if ( ! F_87 ( V_6 ) || F_88 ( V_6 ) ||
! F_89 ( V_6 ) || F_90 ( V_6 ) ) {
if ( ! F_89 ( V_6 ) )
F_85 ( V_6 ) ;
if ( V_38 -> V_79 )
F_68 ( V_38 ) ;
continue;
}
if ( F_91 ( V_6 ) ) {
F_92 ( V_6 ) ;
F_93 ( V_6 ) ;
}
F_94 ( V_6 ) ;
V_99 ++ ;
} while ( ( V_6 = V_6 -> V_30 ) != V_17 );
V_6 = V_17 = F_13 ( V_14 ) ;
if ( F_95 ( V_39 ) && F_96 ( V_39 -> V_101 ) &&
V_99 ) {
T_6 V_102 = V_103 ;
V_104:
V_16 = F_97 ( V_39 , V_14 , V_100 , 0 ,
V_14 -> V_105 , V_102 ) ;
if ( F_98 ( V_16 ) ) {
V_42 = F_99 ( V_16 ) ;
if ( V_42 == - V_4 && V_89 -> V_82 == V_83 ) {
if ( V_38 -> V_79 ) {
F_68 ( V_38 ) ;
F_100 ( V_106 , V_107 / 50 ) ;
}
V_102 |= V_108 ;
goto V_104;
}
V_16 = NULL ;
goto V_109;
}
}
do {
if ( ! F_17 ( V_6 ) )
continue;
V_42 = F_75 ( V_38 , V_39 ,
V_16 ? V_16 : V_14 , V_6 ) ;
if ( V_42 ) {
break;
}
V_98 ++ ;
F_85 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_30 ) != V_17 );
if ( V_42 ) {
V_109:
if ( V_16 )
F_21 ( V_16 ) ;
F_6 ( V_7 L_12 , V_110 , V_42 ) ;
F_101 ( V_89 , V_14 ) ;
do {
F_18 ( V_6 ) ;
V_6 = V_6 -> V_30 ;
} while ( V_6 != V_17 );
}
F_102 ( V_14 ) ;
if ( ! V_98 )
F_22 ( V_14 ) ;
return V_42 ;
}
