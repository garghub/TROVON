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
F_24 ( ! V_31 ) ;
V_10 -> V_73 = NULL ;
if ( V_10 -> V_25 ) {
struct V_39 * V_39 = V_31 -> V_39 ;
F_62 ( V_39 -> V_46 , L_9
L_10 ,
V_10 -> V_25 , V_39 -> V_43 ,
( unsigned long long ) V_31 -> V_40 ,
( long ) V_31 -> V_41 ,
( unsigned long long )
V_71 >> ( V_39 -> V_74 - 9 ) ) ;
F_12 ( V_39 -> V_75 , V_10 -> V_25 ) ;
}
if ( V_31 -> V_34 & V_35 ) {
V_10 -> V_37 = F_63 ( & V_31 -> V_10 , V_10 ) ;
F_56 ( V_31 ) ;
} else {
F_56 ( V_31 ) ;
F_7 ( V_10 ) ;
F_27 ( V_10 ) ;
}
}
void F_64 ( struct F_64 * V_38 )
{
struct V_10 * V_10 = V_38 -> V_76 ;
if ( V_10 ) {
int V_77 = V_38 -> V_78 -> V_79 == V_80 ?
V_81 : 0 ;
F_65 ( V_38 -> V_76 , V_82 , V_77 ) ;
F_66 ( V_38 -> V_76 ) ;
}
V_38 -> V_76 = NULL ;
}
void F_67 ( struct F_64 * V_38 ,
struct V_83 * V_84 )
{
V_38 -> V_78 = V_84 ;
V_38 -> V_76 = NULL ;
V_38 -> V_31 = NULL ;
}
static int F_68 ( struct F_64 * V_38 ,
struct V_5 * V_6 )
{
struct V_10 * V_10 ;
V_10 = F_69 ( V_85 , V_86 ) ;
if ( ! V_10 )
return - V_4 ;
F_70 ( V_38 -> V_78 , V_10 ) ;
V_10 -> V_72 . V_71 = V_6 -> V_9 * ( V_6 -> V_29 >> 9 ) ;
V_10 -> V_87 = V_6 -> V_8 ;
V_10 -> V_73 = F_61 ;
V_10 -> V_37 = F_59 ( V_38 -> V_31 ) ;
V_38 -> V_76 = V_10 ;
V_38 -> V_88 = V_6 -> V_9 ;
return 0 ;
}
static int F_71 ( struct F_64 * V_38 ,
struct V_39 * V_39 ,
struct V_14 * V_14 ,
struct V_5 * V_6 )
{
int V_42 ;
if ( V_38 -> V_76 && V_6 -> V_9 != V_38 -> V_88 ) {
V_89:
F_64 ( V_38 ) ;
}
if ( V_38 -> V_76 == NULL ) {
V_42 = F_68 ( V_38 , V_6 ) ;
if ( V_42 )
return V_42 ;
}
V_42 = F_72 ( V_38 -> V_76 , V_14 , V_6 -> V_29 , F_16 ( V_6 ) ) ;
if ( V_42 != V_6 -> V_29 )
goto V_89;
F_73 ( V_38 -> V_78 , V_14 , V_6 -> V_29 ) ;
V_38 -> V_88 ++ ;
return 0 ;
}
int F_74 ( struct F_64 * V_38 ,
struct V_14 * V_14 ,
int V_90 ,
struct V_83 * V_84 ,
bool V_91 )
{
struct V_14 * V_16 = NULL ;
struct V_39 * V_39 = V_14 -> V_24 -> V_92 ;
unsigned V_93 ;
struct V_5 * V_6 , * V_17 ;
int V_42 = 0 ;
int V_94 = 0 ;
int V_95 = 0 ;
F_24 ( ! F_75 ( V_14 ) ) ;
F_24 ( F_76 ( V_14 ) ) ;
if ( V_91 )
F_77 ( V_14 ) ;
else
F_78 ( V_14 ) ;
F_79 ( V_14 ) ;
if ( V_90 < V_96 )
F_80 ( V_14 , V_90 , V_96 ) ;
V_6 = V_17 = F_13 ( V_14 ) ;
do {
V_93 = F_16 ( V_6 ) ;
if ( V_93 >= V_90 ) {
F_81 ( V_6 ) ;
F_82 ( V_6 ) ;
continue;
}
if ( ! F_83 ( V_6 ) || F_84 ( V_6 ) ||
! F_85 ( V_6 ) || F_86 ( V_6 ) ) {
if ( ! F_85 ( V_6 ) )
F_81 ( V_6 ) ;
if ( V_38 -> V_76 )
F_64 ( V_38 ) ;
continue;
}
if ( F_87 ( V_6 ) ) {
F_88 ( V_6 ) ;
F_89 ( V_6 ) ;
}
F_90 ( V_6 ) ;
V_95 ++ ;
} while ( ( V_6 = V_6 -> V_30 ) != V_17 );
V_6 = V_17 = F_13 ( V_14 ) ;
if ( F_91 ( V_39 ) && F_92 ( V_39 -> V_97 ) &&
V_95 ) {
T_6 V_98 = V_99 ;
V_100:
V_16 = F_93 ( V_39 , V_14 , V_96 , 0 ,
V_14 -> V_101 , V_98 ) ;
if ( F_94 ( V_16 ) ) {
V_42 = F_95 ( V_16 ) ;
if ( V_42 == - V_4 && V_84 -> V_79 == V_80 ) {
if ( V_38 -> V_76 ) {
F_64 ( V_38 ) ;
F_96 ( V_102 , V_103 / 50 ) ;
}
V_98 |= V_104 ;
goto V_100;
}
V_16 = NULL ;
goto V_105;
}
}
do {
if ( ! F_17 ( V_6 ) )
continue;
V_42 = F_71 ( V_38 , V_39 ,
V_16 ? V_16 : V_14 , V_6 ) ;
if ( V_42 ) {
break;
}
V_94 ++ ;
F_81 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_30 ) != V_17 );
if ( V_42 ) {
V_105:
if ( V_16 )
F_21 ( V_16 ) ;
F_6 ( V_7 L_11 , V_106 , V_42 ) ;
F_97 ( V_84 , V_14 ) ;
do {
F_18 ( V_6 ) ;
V_6 = V_6 -> V_30 ;
} while ( V_6 != V_17 );
}
F_98 ( V_14 ) ;
if ( ! V_94 )
F_22 ( V_14 ) ;
return V_42 ;
}
