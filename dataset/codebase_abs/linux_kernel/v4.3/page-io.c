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
char V_7 [ V_8 ] ;
F_6 ( V_9 L_1 ,
F_7 ( V_6 -> V_10 , V_7 ) ,
( unsigned long long ) V_6 -> V_11 ) ;
}
static void F_8 ( struct V_12 * V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
F_9 (bvec, bio, i) {
struct V_16 * V_16 = V_15 -> V_17 ;
#ifdef F_10
struct V_16 * V_18 = NULL ;
struct V_19 * V_20 = NULL ;
#endif
struct V_5 * V_6 , * V_21 ;
unsigned V_22 = V_15 -> V_23 ;
unsigned V_24 = V_22 + V_15 -> V_25 ;
unsigned V_26 = 0 ;
unsigned long V_27 ;
if ( ! V_16 )
continue;
#ifdef F_10
if ( ! V_16 -> V_28 ) {
V_18 = V_16 ;
V_20 = (struct V_19 * ) F_11 ( V_18 ) ;
V_16 = V_20 -> V_29 . V_30 ;
}
#endif
if ( V_12 -> V_31 ) {
F_12 ( V_16 ) ;
F_13 ( V_32 , & V_16 -> V_28 -> V_27 ) ;
}
V_6 = V_21 = F_14 ( V_16 ) ;
F_15 ( V_27 ) ;
F_16 ( V_33 , & V_21 -> V_34 ) ;
do {
if ( F_17 ( V_6 ) < V_22 ||
F_17 ( V_6 ) + V_6 -> V_35 > V_24 ) {
if ( F_18 ( V_6 ) )
V_26 ++ ;
continue;
}
F_19 ( V_6 ) ;
if ( V_12 -> V_31 )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_36 ) != V_21 );
F_20 ( V_33 , & V_21 -> V_34 ) ;
F_21 ( V_27 ) ;
if ( ! V_26 ) {
#ifdef F_10
if ( V_20 )
F_22 ( V_18 ) ;
#endif
F_23 ( V_16 ) ;
}
}
}
static void F_24 ( T_2 * V_37 )
{
struct V_12 * V_12 , * V_38 ;
F_25 ( ! F_26 ( & V_37 -> V_39 ) ) ;
F_25 ( V_37 -> V_40 & V_41 ) ;
F_27 ( V_37 -> V_42 ) ;
if ( F_28 ( & F_29 ( V_37 -> V_43 ) -> V_44 ) )
F_30 ( F_31 ( V_37 -> V_43 ) ) ;
for ( V_12 = V_37 -> V_12 ; V_12 ; V_12 = V_38 ) {
V_38 = V_12 -> V_45 ;
F_8 ( V_12 ) ;
F_32 ( V_12 ) ;
}
F_33 ( V_1 , V_37 ) ;
}
static void F_34 ( T_2 * V_37 )
{
struct V_43 * V_43 = V_37 -> V_43 ;
V_37 -> V_40 &= ~ V_41 ;
if ( F_28 ( & F_29 ( V_43 ) -> V_46 ) )
F_30 ( F_31 ( V_43 ) ) ;
}
static int F_35 ( T_2 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_3 V_48 = V_47 -> V_48 ;
T_4 V_49 = V_47 -> V_49 ;
T_5 * V_42 = V_47 -> V_42 ;
int V_50 = 0 ;
F_36 ( L_2
L_3 ,
V_47 , V_43 -> V_51 , V_47 -> V_39 . V_52 , V_47 -> V_39 . V_53 ) ;
V_47 -> V_42 = NULL ;
V_50 = F_37 ( V_42 , V_43 , V_48 , V_49 ) ;
if ( V_50 < 0 ) {
F_38 ( V_43 -> V_54 , V_55 ,
L_4
L_5
L_6 ,
V_43 -> V_51 , V_48 , V_49 , V_50 ) ;
}
F_34 ( V_47 ) ;
F_24 ( V_47 ) ;
return V_50 ;
}
static void F_39 ( struct V_43 * V_43 , struct V_56 * V_21 )
{
#ifdef F_40
struct V_56 * V_57 , * V_58 , * V_59 ;
T_2 * V_47 , * V_60 , * V_61 ;
if ( F_26 ( V_21 ) )
return;
F_36 ( L_7 , V_43 -> V_51 ) ;
F_41 (io, head, list) {
V_57 = & V_47 -> V_39 ;
V_58 = V_57 -> V_53 ;
V_60 = F_42 ( V_58 , T_2 , V_39 ) ;
V_59 = V_57 -> V_52 ;
V_61 = F_42 ( V_59 , T_2 , V_39 ) ;
F_36 ( L_8 ,
V_47 , V_43 -> V_51 , V_60 , V_61 ) ;
}
#endif
}
static void F_43 ( T_2 * V_37 )
{
struct V_62 * V_63 = F_29 ( V_37 -> V_43 ) ;
struct V_64 * V_65 = F_44 ( V_37 -> V_43 -> V_54 ) ;
struct V_66 * V_67 ;
unsigned long V_27 ;
F_27 ( ! ( V_37 -> V_40 & V_41 ) ) ;
F_27 ( ! V_37 -> V_42 && V_65 -> V_68 ) ;
F_45 ( & V_63 -> V_69 , V_27 ) ;
V_67 = V_65 -> V_70 ;
if ( F_26 ( & V_63 -> V_71 ) )
F_46 ( V_67 , & V_63 -> V_72 ) ;
F_47 ( & V_37 -> V_39 , & V_63 -> V_71 ) ;
F_48 ( & V_63 -> V_69 , V_27 ) ;
}
static int F_49 ( struct V_43 * V_43 ,
struct V_56 * V_21 )
{
T_2 * V_47 ;
struct V_56 V_73 ;
unsigned long V_27 ;
struct V_62 * V_63 = F_29 ( V_43 ) ;
int V_74 , V_50 = 0 ;
F_45 ( & V_63 -> V_69 , V_27 ) ;
F_39 ( V_43 , V_21 ) ;
F_50 ( V_21 , & V_73 ) ;
F_48 ( & V_63 -> V_69 , V_27 ) ;
while ( ! F_26 ( & V_73 ) ) {
V_47 = F_51 ( V_73 . V_52 , T_2 , V_39 ) ;
F_25 ( ! ( V_47 -> V_40 & V_41 ) ) ;
F_52 ( & V_47 -> V_39 ) ;
V_74 = F_35 ( V_47 ) ;
if ( F_53 ( ! V_50 && V_74 ) )
V_50 = V_74 ;
}
return V_50 ;
}
void F_54 ( struct V_75 * V_76 )
{
struct V_62 * V_63 = F_42 ( V_76 , struct V_62 ,
V_72 ) ;
F_49 ( & V_63 -> V_77 , & V_63 -> V_71 ) ;
}
T_2 * F_55 ( struct V_43 * V_43 , T_6 V_27 )
{
T_2 * V_47 = F_56 ( V_1 , V_27 ) ;
if ( V_47 ) {
F_57 ( & F_29 ( V_43 ) -> V_44 ) ;
V_47 -> V_43 = V_43 ;
F_58 ( & V_47 -> V_39 ) ;
F_59 ( & V_47 -> V_78 , 1 ) ;
}
return V_47 ;
}
void F_60 ( T_2 * V_37 )
{
if ( F_28 ( & V_37 -> V_78 ) ) {
if ( ! ( V_37 -> V_40 & V_41 ) || ! V_37 -> V_49 ) {
F_24 ( V_37 ) ;
return;
}
F_43 ( V_37 ) ;
}
}
int F_61 ( T_2 * V_37 )
{
int V_74 = 0 ;
if ( F_28 ( & V_37 -> V_78 ) ) {
if ( V_37 -> V_40 & V_41 ) {
V_74 = F_37 ( V_37 -> V_42 ,
V_37 -> V_43 , V_37 -> V_48 ,
V_37 -> V_49 ) ;
V_37 -> V_42 = NULL ;
F_34 ( V_37 ) ;
}
F_24 ( V_37 ) ;
}
return V_74 ;
}
T_2 * F_62 ( T_2 * V_37 )
{
F_57 ( & V_37 -> V_78 ) ;
return V_37 ;
}
static void F_63 ( struct V_12 * V_12 )
{
T_2 * V_37 = V_12 -> V_45 ;
T_7 V_79 = V_12 -> V_80 . V_79 ;
F_25 ( ! V_37 ) ;
V_12 -> V_81 = NULL ;
if ( V_12 -> V_31 ) {
struct V_43 * V_43 = V_37 -> V_43 ;
F_64 ( V_43 -> V_54 , L_9
L_10 ,
V_12 -> V_31 , V_43 -> V_51 ,
( unsigned long long ) V_37 -> V_48 ,
( long ) V_37 -> V_49 ,
( unsigned long long )
V_79 >> ( V_43 -> V_82 - 9 ) ) ;
F_65 ( V_43 -> V_83 , V_12 -> V_31 ) ;
}
if ( V_37 -> V_40 & V_41 ) {
V_12 -> V_45 = F_66 ( & V_37 -> V_12 , V_12 ) ;
F_60 ( V_37 ) ;
} else {
F_60 ( V_37 ) ;
F_8 ( V_12 ) ;
F_32 ( V_12 ) ;
}
}
void F_67 ( struct F_67 * V_47 )
{
struct V_12 * V_12 = V_47 -> V_84 ;
if ( V_12 ) {
int V_85 = V_47 -> V_86 -> V_87 == V_88 ?
V_89 : V_90 ;
F_68 ( V_47 -> V_84 ) ;
F_69 ( V_85 , V_47 -> V_84 ) ;
F_32 ( V_47 -> V_84 ) ;
}
V_47 -> V_84 = NULL ;
}
void F_70 ( struct F_67 * V_47 ,
struct V_91 * V_92 )
{
V_47 -> V_86 = V_92 ;
V_47 -> V_84 = NULL ;
V_47 -> V_37 = NULL ;
}
static int F_71 ( struct F_67 * V_47 ,
struct V_5 * V_6 )
{
struct V_12 * V_12 ;
V_12 = F_72 ( V_93 , V_94 ) ;
if ( ! V_12 )
return - V_4 ;
F_73 ( V_47 -> V_86 , V_12 ) ;
V_12 -> V_80 . V_79 = V_6 -> V_11 * ( V_6 -> V_35 >> 9 ) ;
V_12 -> V_95 = V_6 -> V_10 ;
V_12 -> V_81 = F_63 ;
V_12 -> V_45 = F_62 ( V_47 -> V_37 ) ;
V_47 -> V_84 = V_12 ;
V_47 -> V_96 = V_6 -> V_11 ;
return 0 ;
}
static int F_74 ( struct F_67 * V_47 ,
struct V_43 * V_43 ,
struct V_16 * V_16 ,
struct V_5 * V_6 )
{
int V_50 ;
if ( V_47 -> V_84 && V_6 -> V_11 != V_47 -> V_96 ) {
V_97:
F_67 ( V_47 ) ;
}
if ( V_47 -> V_84 == NULL ) {
V_50 = F_71 ( V_47 , V_6 ) ;
if ( V_50 )
return V_50 ;
}
V_50 = F_75 ( V_47 -> V_84 , V_16 , V_6 -> V_35 , F_17 ( V_6 ) ) ;
if ( V_50 != V_6 -> V_35 )
goto V_97;
F_76 ( V_47 -> V_86 , V_16 , V_6 -> V_35 ) ;
V_47 -> V_96 ++ ;
return 0 ;
}
int F_77 ( struct F_67 * V_47 ,
struct V_16 * V_16 ,
int V_98 ,
struct V_91 * V_92 ,
bool V_99 )
{
struct V_16 * V_18 = NULL ;
struct V_43 * V_43 = V_16 -> V_28 -> V_100 ;
unsigned V_101 , V_102 ;
struct V_5 * V_6 , * V_21 ;
int V_50 = 0 ;
int V_103 = 0 ;
V_102 = 1 << V_43 -> V_82 ;
F_25 ( ! F_78 ( V_16 ) ) ;
F_25 ( F_79 ( V_16 ) ) ;
if ( V_99 )
F_80 ( V_16 ) ;
else
F_81 ( V_16 ) ;
F_82 ( V_16 ) ;
if ( V_98 < V_104 )
F_83 ( V_16 , V_98 , V_104 ) ;
V_6 = V_21 = F_14 ( V_16 ) ;
do {
V_101 = F_17 ( V_6 ) ;
if ( V_101 >= V_98 ) {
F_84 ( V_6 ) ;
F_85 ( V_6 ) ;
continue;
}
if ( ! F_86 ( V_6 ) || F_87 ( V_6 ) ||
! F_88 ( V_6 ) || F_89 ( V_6 ) ) {
if ( ! F_88 ( V_6 ) )
F_84 ( V_6 ) ;
if ( V_47 -> V_84 )
F_67 ( V_47 ) ;
continue;
}
if ( F_90 ( V_6 ) ) {
F_91 ( V_6 ) ;
F_92 ( V_6 -> V_10 , V_6 -> V_11 ) ;
}
F_93 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_36 ) != V_21 );
V_6 = V_21 = F_14 ( V_16 ) ;
if ( F_94 ( V_43 ) && F_95 ( V_43 -> V_105 ) ) {
V_18 = F_96 ( V_43 , V_16 ) ;
if ( F_97 ( V_18 ) ) {
V_50 = F_98 ( V_18 ) ;
V_18 = NULL ;
goto V_106;
}
}
do {
if ( ! F_18 ( V_6 ) )
continue;
V_50 = F_74 ( V_47 , V_43 ,
V_18 ? V_18 : V_16 , V_6 ) ;
if ( V_50 ) {
break;
}
V_103 ++ ;
F_84 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_36 ) != V_21 );
if ( V_50 ) {
V_106:
if ( V_18 )
F_22 ( V_18 ) ;
F_6 ( V_9 L_11 , V_107 , V_50 ) ;
F_99 ( V_92 , V_16 ) ;
do {
F_19 ( V_6 ) ;
V_6 = V_6 -> V_36 ;
} while ( V_6 != V_21 );
}
F_100 ( V_16 ) ;
if ( ! V_103 )
F_23 ( V_16 ) ;
return V_50 ;
}
