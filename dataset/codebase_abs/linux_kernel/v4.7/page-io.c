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
for ( V_10 = V_35 -> V_10 ; V_10 ; V_10 = V_36 ) {
V_36 = V_10 -> V_41 ;
F_7 ( V_10 ) ;
F_27 ( V_10 ) ;
}
F_28 ( V_1 , V_35 ) ;
}
static int F_29 ( T_2 * V_42 )
{
struct V_43 * V_43 = V_42 -> V_43 ;
T_3 V_44 = V_42 -> V_44 ;
T_4 V_45 = V_42 -> V_45 ;
T_5 * V_40 = V_42 -> V_40 ;
int V_46 = 0 ;
F_30 ( L_2
L_3 ,
V_42 , V_43 -> V_47 , V_42 -> V_37 . V_48 , V_42 -> V_37 . V_49 ) ;
V_42 -> V_40 = NULL ;
V_46 = F_31 ( V_40 , V_43 , V_44 , V_45 ) ;
if ( V_46 < 0 ) {
F_32 ( V_43 -> V_50 , V_51 ,
L_4
L_5
L_6 ,
V_43 -> V_47 , V_44 , V_45 , V_46 ) ;
}
F_33 ( V_42 ) ;
F_23 ( V_42 ) ;
return V_46 ;
}
static void F_34 ( struct V_43 * V_43 , struct V_52 * V_19 )
{
#ifdef F_35
struct V_52 * V_53 , * V_54 , * V_55 ;
T_2 * V_42 , * V_56 , * V_57 ;
if ( F_25 ( V_19 ) )
return;
F_30 ( L_7 , V_43 -> V_47 ) ;
F_36 (io, head, list) {
V_53 = & V_42 -> V_37 ;
V_54 = V_53 -> V_49 ;
V_56 = F_37 ( V_54 , T_2 , V_37 ) ;
V_55 = V_53 -> V_48 ;
V_57 = F_37 ( V_55 , T_2 , V_37 ) ;
F_30 ( L_8 ,
V_42 , V_43 -> V_47 , V_56 , V_57 ) ;
}
#endif
}
static void F_38 ( T_2 * V_35 )
{
struct V_58 * V_59 = F_39 ( V_35 -> V_43 ) ;
struct V_60 * V_61 = F_40 ( V_35 -> V_43 -> V_50 ) ;
struct V_62 * V_63 ;
unsigned long V_25 ;
F_26 ( ! ( V_35 -> V_38 & V_39 ) ) ;
F_26 ( ! V_35 -> V_40 && V_61 -> V_64 ) ;
F_41 ( & V_59 -> V_65 , V_25 ) ;
V_63 = V_61 -> V_66 ;
if ( F_25 ( & V_59 -> V_67 ) )
F_42 ( V_63 , & V_59 -> V_68 ) ;
F_43 ( & V_35 -> V_37 , & V_59 -> V_67 ) ;
F_44 ( & V_59 -> V_65 , V_25 ) ;
}
static int F_45 ( struct V_43 * V_43 ,
struct V_52 * V_19 )
{
T_2 * V_42 ;
struct V_52 V_69 ;
unsigned long V_25 ;
struct V_58 * V_59 = F_39 ( V_43 ) ;
int V_70 , V_46 = 0 ;
F_41 ( & V_59 -> V_65 , V_25 ) ;
F_34 ( V_43 , V_19 ) ;
F_46 ( V_19 , & V_69 ) ;
F_44 ( & V_59 -> V_65 , V_25 ) ;
while ( ! F_25 ( & V_69 ) ) {
V_42 = F_47 ( V_69 . V_48 , T_2 , V_37 ) ;
F_24 ( ! ( V_42 -> V_38 & V_39 ) ) ;
F_48 ( & V_42 -> V_37 ) ;
V_70 = F_29 ( V_42 ) ;
if ( F_49 ( ! V_46 && V_70 ) )
V_46 = V_70 ;
}
return V_46 ;
}
void F_50 ( struct V_71 * V_72 )
{
struct V_58 * V_59 = F_37 ( V_72 , struct V_58 ,
V_68 ) ;
F_45 ( & V_59 -> V_73 , & V_59 -> V_67 ) ;
}
T_2 * F_51 ( struct V_43 * V_43 , T_6 V_25 )
{
T_2 * V_42 = F_52 ( V_1 , V_25 ) ;
if ( V_42 ) {
V_42 -> V_43 = V_43 ;
F_53 ( & V_42 -> V_37 ) ;
F_54 ( & V_42 -> V_74 , 1 ) ;
}
return V_42 ;
}
void F_55 ( T_2 * V_35 )
{
if ( F_56 ( & V_35 -> V_74 ) ) {
if ( ! ( V_35 -> V_38 & V_39 ) || ! V_35 -> V_45 ) {
F_23 ( V_35 ) ;
return;
}
F_38 ( V_35 ) ;
}
}
int F_57 ( T_2 * V_35 )
{
int V_70 = 0 ;
if ( F_56 ( & V_35 -> V_74 ) ) {
if ( V_35 -> V_38 & V_39 ) {
V_70 = F_31 ( V_35 -> V_40 ,
V_35 -> V_43 , V_35 -> V_44 ,
V_35 -> V_45 ) ;
V_35 -> V_40 = NULL ;
F_33 ( V_35 ) ;
}
F_23 ( V_35 ) ;
}
return V_70 ;
}
T_2 * F_58 ( T_2 * V_35 )
{
F_59 ( & V_35 -> V_74 ) ;
return V_35 ;
}
static void F_60 ( struct V_10 * V_10 )
{
T_2 * V_35 = V_10 -> V_41 ;
T_7 V_75 = V_10 -> V_76 . V_75 ;
F_24 ( ! V_35 ) ;
V_10 -> V_77 = NULL ;
if ( V_10 -> V_29 ) {
struct V_43 * V_43 = V_35 -> V_43 ;
F_61 ( V_43 -> V_50 , L_9
L_10 ,
V_10 -> V_29 , V_43 -> V_47 ,
( unsigned long long ) V_35 -> V_44 ,
( long ) V_35 -> V_45 ,
( unsigned long long )
V_75 >> ( V_43 -> V_78 - 9 ) ) ;
F_62 ( V_43 -> V_79 , V_10 -> V_29 ) ;
}
if ( V_35 -> V_38 & V_39 ) {
V_10 -> V_41 = F_63 ( & V_35 -> V_10 , V_10 ) ;
F_55 ( V_35 ) ;
} else {
F_55 ( V_35 ) ;
F_7 ( V_10 ) ;
F_27 ( V_10 ) ;
}
}
void F_64 ( struct F_64 * V_42 )
{
struct V_10 * V_10 = V_42 -> V_80 ;
if ( V_10 ) {
int V_81 = V_42 -> V_82 -> V_83 == V_84 ?
V_85 : V_86 ;
F_65 ( V_81 , V_42 -> V_80 ) ;
}
V_42 -> V_80 = NULL ;
}
void F_66 ( struct F_64 * V_42 ,
struct V_87 * V_88 )
{
V_42 -> V_82 = V_88 ;
V_42 -> V_80 = NULL ;
V_42 -> V_35 = NULL ;
}
static int F_67 ( struct F_64 * V_42 ,
struct V_5 * V_6 )
{
struct V_10 * V_10 ;
V_10 = F_68 ( V_89 , V_90 ) ;
if ( ! V_10 )
return - V_4 ;
F_69 ( V_42 -> V_82 , V_10 ) ;
V_10 -> V_76 . V_75 = V_6 -> V_9 * ( V_6 -> V_33 >> 9 ) ;
V_10 -> V_91 = V_6 -> V_8 ;
V_10 -> V_77 = F_60 ;
V_10 -> V_41 = F_58 ( V_42 -> V_35 ) ;
V_42 -> V_80 = V_10 ;
V_42 -> V_92 = V_6 -> V_9 ;
return 0 ;
}
static int F_70 ( struct F_64 * V_42 ,
struct V_43 * V_43 ,
struct V_14 * V_14 ,
struct V_5 * V_6 )
{
int V_46 ;
if ( V_42 -> V_80 && V_6 -> V_9 != V_42 -> V_92 ) {
V_93:
F_64 ( V_42 ) ;
}
if ( V_42 -> V_80 == NULL ) {
V_46 = F_67 ( V_42 , V_6 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = F_71 ( V_42 -> V_80 , V_14 , V_6 -> V_33 , F_16 ( V_6 ) ) ;
if ( V_46 != V_6 -> V_33 )
goto V_93;
F_72 ( V_42 -> V_82 , V_14 , V_6 -> V_33 ) ;
V_42 -> V_92 ++ ;
return 0 ;
}
int F_73 ( struct F_64 * V_42 ,
struct V_14 * V_14 ,
int V_94 ,
struct V_87 * V_88 ,
bool V_95 )
{
struct V_14 * V_16 = NULL ;
struct V_43 * V_43 = V_14 -> V_26 -> V_96 ;
unsigned V_97 , V_98 ;
struct V_5 * V_6 , * V_19 ;
int V_46 = 0 ;
int V_99 = 0 ;
int V_100 = 0 ;
V_98 = 1 << V_43 -> V_78 ;
F_24 ( ! F_74 ( V_14 ) ) ;
F_24 ( F_75 ( V_14 ) ) ;
if ( V_95 )
F_76 ( V_14 ) ;
else
F_77 ( V_14 ) ;
F_78 ( V_14 ) ;
if ( V_94 < V_101 )
F_79 ( V_14 , V_94 , V_101 ) ;
V_6 = V_19 = F_13 ( V_14 ) ;
do {
V_97 = F_16 ( V_6 ) ;
if ( V_97 >= V_94 ) {
F_80 ( V_6 ) ;
F_81 ( V_6 ) ;
continue;
}
if ( ! F_82 ( V_6 ) || F_83 ( V_6 ) ||
! F_84 ( V_6 ) || F_85 ( V_6 ) ) {
if ( ! F_84 ( V_6 ) )
F_80 ( V_6 ) ;
if ( V_42 -> V_80 )
F_64 ( V_42 ) ;
continue;
}
if ( F_86 ( V_6 ) ) {
F_87 ( V_6 ) ;
F_88 ( V_6 -> V_8 , V_6 -> V_9 ) ;
}
F_89 ( V_6 ) ;
V_100 ++ ;
} while ( ( V_6 = V_6 -> V_34 ) != V_19 );
V_6 = V_19 = F_13 ( V_14 ) ;
if ( F_90 ( V_43 ) && F_91 ( V_43 -> V_102 ) &&
V_100 ) {
T_6 V_103 = V_104 ;
V_105:
V_16 = F_92 ( V_43 , V_14 , V_103 ) ;
if ( F_93 ( V_16 ) ) {
V_46 = F_94 ( V_16 ) ;
if ( V_46 == - V_4 && V_88 -> V_83 == V_84 ) {
if ( V_42 -> V_80 ) {
F_64 ( V_42 ) ;
F_95 ( V_106 , V_107 / 50 ) ;
}
V_103 |= V_108 ;
goto V_105;
}
V_16 = NULL ;
goto V_109;
}
}
do {
if ( ! F_17 ( V_6 ) )
continue;
V_46 = F_70 ( V_42 , V_43 ,
V_16 ? V_16 : V_14 , V_6 ) ;
if ( V_46 ) {
break;
}
V_99 ++ ;
F_80 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_19 );
if ( V_46 ) {
V_109:
if ( V_16 )
F_21 ( V_16 ) ;
F_6 ( V_7 L_11 , V_110 , V_46 ) ;
F_96 ( V_88 , V_14 ) ;
do {
F_18 ( V_6 ) ;
V_6 = V_6 -> V_34 ;
} while ( V_6 != V_19 );
}
F_97 ( V_14 ) ;
if ( ! V_99 )
F_22 ( V_14 ) ;
return V_46 ;
}
