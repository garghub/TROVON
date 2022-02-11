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
struct V_17 * V_18 = NULL ;
#endif
struct V_5 * V_6 , * V_19 ;
unsigned V_20 = V_13 -> V_21 ;
unsigned V_22 = V_20 + V_13 -> V_23 ;
unsigned V_24 = 0 ;
unsigned long V_25 ;
if ( ! V_14 )
continue;
#ifdef F_9
if ( ! V_14 -> V_26 ) {
V_16 = V_14 ;
V_18 = (struct V_17 * ) F_10 ( V_16 ) ;
V_14 = V_18 -> V_27 . V_28 ;
}
#endif
if ( V_10 -> V_29 ) {
F_11 ( V_14 ) ;
F_12 ( V_30 , & V_14 -> V_26 -> V_25 ) ;
}
V_6 = V_19 = F_13 ( V_14 ) ;
F_14 ( V_25 ) ;
F_15 ( V_31 , & V_19 -> V_32 ) ;
do {
if ( F_16 ( V_6 ) < V_20 ||
F_16 ( V_6 ) + V_6 -> V_33 > V_22 ) {
if ( F_17 ( V_6 ) )
V_24 ++ ;
continue;
}
F_18 ( V_6 ) ;
if ( V_10 -> V_29 )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_19 );
F_19 ( V_31 , & V_19 -> V_32 ) ;
F_20 ( V_25 ) ;
if ( ! V_24 ) {
#ifdef F_9
if ( V_18 )
F_21 ( V_16 ) ;
#endif
F_22 ( V_14 ) ;
}
}
}
static void F_23 ( T_2 * V_35 )
{
struct V_10 * V_10 , * V_36 ;
F_24 ( ! F_25 ( & V_35 -> V_37 ) ) ;
F_24 ( V_35 -> V_38 & V_39 ) ;
F_26 ( V_35 -> V_40 ) ;
if ( F_27 ( & F_28 ( V_35 -> V_41 ) -> V_42 ) )
F_29 ( F_30 ( V_35 -> V_41 ) ) ;
for ( V_10 = V_35 -> V_10 ; V_10 ; V_10 = V_36 ) {
V_36 = V_10 -> V_43 ;
F_7 ( V_10 ) ;
F_31 ( V_10 ) ;
}
F_32 ( V_1 , V_35 ) ;
}
static void F_33 ( T_2 * V_35 )
{
struct V_41 * V_41 = V_35 -> V_41 ;
V_35 -> V_38 &= ~ V_39 ;
if ( F_27 ( & F_28 ( V_41 ) -> V_44 ) )
F_29 ( F_30 ( V_41 ) ) ;
}
static int F_34 ( T_2 * V_45 )
{
struct V_41 * V_41 = V_45 -> V_41 ;
T_3 V_46 = V_45 -> V_46 ;
T_4 V_47 = V_45 -> V_47 ;
T_5 * V_40 = V_45 -> V_40 ;
int V_48 = 0 ;
F_35 ( L_2
L_3 ,
V_45 , V_41 -> V_49 , V_45 -> V_37 . V_50 , V_45 -> V_37 . V_51 ) ;
V_45 -> V_40 = NULL ;
V_48 = F_36 ( V_40 , V_41 , V_46 , V_47 ) ;
if ( V_48 < 0 ) {
F_37 ( V_41 -> V_52 , V_53 ,
L_4
L_5
L_6 ,
V_41 -> V_49 , V_46 , V_47 , V_48 ) ;
}
F_33 ( V_45 ) ;
F_23 ( V_45 ) ;
return V_48 ;
}
static void F_38 ( struct V_41 * V_41 , struct V_54 * V_19 )
{
#ifdef F_39
struct V_54 * V_55 , * V_56 , * V_57 ;
T_2 * V_45 , * V_58 , * V_59 ;
if ( F_25 ( V_19 ) )
return;
F_35 ( L_7 , V_41 -> V_49 ) ;
F_40 (io, head, list) {
V_55 = & V_45 -> V_37 ;
V_56 = V_55 -> V_51 ;
V_58 = F_41 ( V_56 , T_2 , V_37 ) ;
V_57 = V_55 -> V_50 ;
V_59 = F_41 ( V_57 , T_2 , V_37 ) ;
F_35 ( L_8 ,
V_45 , V_41 -> V_49 , V_58 , V_59 ) ;
}
#endif
}
static void F_42 ( T_2 * V_35 )
{
struct V_60 * V_61 = F_28 ( V_35 -> V_41 ) ;
struct V_62 * V_63 = F_43 ( V_35 -> V_41 -> V_52 ) ;
struct V_64 * V_65 ;
unsigned long V_25 ;
F_26 ( ! ( V_35 -> V_38 & V_39 ) ) ;
F_26 ( ! V_35 -> V_40 && V_63 -> V_66 ) ;
F_44 ( & V_61 -> V_67 , V_25 ) ;
V_65 = V_63 -> V_68 ;
if ( F_25 ( & V_61 -> V_69 ) )
F_45 ( V_65 , & V_61 -> V_70 ) ;
F_46 ( & V_35 -> V_37 , & V_61 -> V_69 ) ;
F_47 ( & V_61 -> V_67 , V_25 ) ;
}
static int F_48 ( struct V_41 * V_41 ,
struct V_54 * V_19 )
{
T_2 * V_45 ;
struct V_54 V_71 ;
unsigned long V_25 ;
struct V_60 * V_61 = F_28 ( V_41 ) ;
int V_72 , V_48 = 0 ;
F_44 ( & V_61 -> V_67 , V_25 ) ;
F_38 ( V_41 , V_19 ) ;
F_49 ( V_19 , & V_71 ) ;
F_47 ( & V_61 -> V_67 , V_25 ) ;
while ( ! F_25 ( & V_71 ) ) {
V_45 = F_50 ( V_71 . V_50 , T_2 , V_37 ) ;
F_24 ( ! ( V_45 -> V_38 & V_39 ) ) ;
F_51 ( & V_45 -> V_37 ) ;
V_72 = F_34 ( V_45 ) ;
if ( F_52 ( ! V_48 && V_72 ) )
V_48 = V_72 ;
}
return V_48 ;
}
void F_53 ( struct V_73 * V_74 )
{
struct V_60 * V_61 = F_41 ( V_74 , struct V_60 ,
V_70 ) ;
F_48 ( & V_61 -> V_75 , & V_61 -> V_69 ) ;
}
T_2 * F_54 ( struct V_41 * V_41 , T_6 V_25 )
{
T_2 * V_45 = F_55 ( V_1 , V_25 ) ;
if ( V_45 ) {
F_56 ( & F_28 ( V_41 ) -> V_42 ) ;
V_45 -> V_41 = V_41 ;
F_57 ( & V_45 -> V_37 ) ;
F_58 ( & V_45 -> V_76 , 1 ) ;
}
return V_45 ;
}
void F_59 ( T_2 * V_35 )
{
if ( F_27 ( & V_35 -> V_76 ) ) {
if ( ! ( V_35 -> V_38 & V_39 ) || ! V_35 -> V_47 ) {
F_23 ( V_35 ) ;
return;
}
F_42 ( V_35 ) ;
}
}
int F_60 ( T_2 * V_35 )
{
int V_72 = 0 ;
if ( F_27 ( & V_35 -> V_76 ) ) {
if ( V_35 -> V_38 & V_39 ) {
V_72 = F_36 ( V_35 -> V_40 ,
V_35 -> V_41 , V_35 -> V_46 ,
V_35 -> V_47 ) ;
V_35 -> V_40 = NULL ;
F_33 ( V_35 ) ;
}
F_23 ( V_35 ) ;
}
return V_72 ;
}
T_2 * F_61 ( T_2 * V_35 )
{
F_56 ( & V_35 -> V_76 ) ;
return V_35 ;
}
static void F_62 ( struct V_10 * V_10 )
{
T_2 * V_35 = V_10 -> V_43 ;
T_7 V_77 = V_10 -> V_78 . V_77 ;
F_24 ( ! V_35 ) ;
V_10 -> V_79 = NULL ;
if ( V_10 -> V_29 ) {
struct V_41 * V_41 = V_35 -> V_41 ;
F_63 ( V_41 -> V_52 , L_9
L_10 ,
V_10 -> V_29 , V_41 -> V_49 ,
( unsigned long long ) V_35 -> V_46 ,
( long ) V_35 -> V_47 ,
( unsigned long long )
V_77 >> ( V_41 -> V_80 - 9 ) ) ;
F_64 ( V_41 -> V_81 , V_10 -> V_29 ) ;
}
if ( V_35 -> V_38 & V_39 ) {
V_10 -> V_43 = F_65 ( & V_35 -> V_10 , V_10 ) ;
F_59 ( V_35 ) ;
} else {
F_59 ( V_35 ) ;
F_7 ( V_10 ) ;
F_31 ( V_10 ) ;
}
}
void F_66 ( struct F_66 * V_45 )
{
struct V_10 * V_10 = V_45 -> V_82 ;
if ( V_10 ) {
int V_83 = V_45 -> V_84 -> V_85 == V_86 ?
V_87 : V_88 ;
F_67 ( V_45 -> V_82 ) ;
F_68 ( V_83 , V_45 -> V_82 ) ;
F_31 ( V_45 -> V_82 ) ;
}
V_45 -> V_82 = NULL ;
}
void F_69 ( struct F_66 * V_45 ,
struct V_89 * V_90 )
{
V_45 -> V_84 = V_90 ;
V_45 -> V_82 = NULL ;
V_45 -> V_35 = NULL ;
}
static int F_70 ( struct F_66 * V_45 ,
struct V_5 * V_6 )
{
struct V_10 * V_10 ;
V_10 = F_71 ( V_91 , V_92 ) ;
if ( ! V_10 )
return - V_4 ;
F_72 ( V_45 -> V_84 , V_10 ) ;
V_10 -> V_78 . V_77 = V_6 -> V_9 * ( V_6 -> V_33 >> 9 ) ;
V_10 -> V_93 = V_6 -> V_8 ;
V_10 -> V_79 = F_62 ;
V_10 -> V_43 = F_61 ( V_45 -> V_35 ) ;
V_45 -> V_82 = V_10 ;
V_45 -> V_94 = V_6 -> V_9 ;
return 0 ;
}
static int F_73 ( struct F_66 * V_45 ,
struct V_41 * V_41 ,
struct V_14 * V_14 ,
struct V_5 * V_6 )
{
int V_48 ;
if ( V_45 -> V_82 && V_6 -> V_9 != V_45 -> V_94 ) {
V_95:
F_66 ( V_45 ) ;
}
if ( V_45 -> V_82 == NULL ) {
V_48 = F_70 ( V_45 , V_6 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_74 ( V_45 -> V_82 , V_14 , V_6 -> V_33 , F_16 ( V_6 ) ) ;
if ( V_48 != V_6 -> V_33 )
goto V_95;
F_75 ( V_45 -> V_84 , V_14 , V_6 -> V_33 ) ;
V_45 -> V_94 ++ ;
return 0 ;
}
int F_76 ( struct F_66 * V_45 ,
struct V_14 * V_14 ,
int V_96 ,
struct V_89 * V_90 ,
bool V_97 )
{
struct V_14 * V_16 = NULL ;
struct V_41 * V_41 = V_14 -> V_26 -> V_98 ;
unsigned V_99 , V_100 ;
struct V_5 * V_6 , * V_19 ;
int V_48 = 0 ;
int V_101 = 0 ;
int V_102 = 0 ;
V_100 = 1 << V_41 -> V_80 ;
F_24 ( ! F_77 ( V_14 ) ) ;
F_24 ( F_78 ( V_14 ) ) ;
if ( V_97 )
F_79 ( V_14 ) ;
else
F_80 ( V_14 ) ;
F_81 ( V_14 ) ;
if ( V_96 < V_103 )
F_82 ( V_14 , V_96 , V_103 ) ;
V_6 = V_19 = F_13 ( V_14 ) ;
do {
V_99 = F_16 ( V_6 ) ;
if ( V_99 >= V_96 ) {
F_83 ( V_6 ) ;
F_84 ( V_6 ) ;
continue;
}
if ( ! F_85 ( V_6 ) || F_86 ( V_6 ) ||
! F_87 ( V_6 ) || F_88 ( V_6 ) ) {
if ( ! F_87 ( V_6 ) )
F_83 ( V_6 ) ;
if ( V_45 -> V_82 )
F_66 ( V_45 ) ;
continue;
}
if ( F_89 ( V_6 ) ) {
F_90 ( V_6 ) ;
F_91 ( V_6 -> V_8 , V_6 -> V_9 ) ;
}
F_92 ( V_6 ) ;
V_102 ++ ;
} while ( ( V_6 = V_6 -> V_34 ) != V_19 );
V_6 = V_19 = F_13 ( V_14 ) ;
if ( F_93 ( V_41 ) && F_94 ( V_41 -> V_104 ) &&
V_102 ) {
V_16 = F_95 ( V_41 , V_14 ) ;
if ( F_96 ( V_16 ) ) {
V_48 = F_97 ( V_16 ) ;
V_16 = NULL ;
goto V_105;
}
}
do {
if ( ! F_17 ( V_6 ) )
continue;
V_48 = F_73 ( V_45 , V_41 ,
V_16 ? V_16 : V_14 , V_6 ) ;
if ( V_48 ) {
break;
}
V_101 ++ ;
F_83 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_19 );
if ( V_48 ) {
V_105:
if ( V_16 )
F_21 ( V_16 ) ;
F_6 ( V_7 L_11 , V_106 , V_48 ) ;
F_98 ( V_90 , V_14 ) ;
do {
F_18 ( V_6 ) ;
V_6 = V_6 -> V_34 ;
} while ( V_6 != V_19 );
}
F_99 ( V_14 ) ;
if ( ! V_101 )
F_22 ( V_14 ) ;
return V_48 ;
}
