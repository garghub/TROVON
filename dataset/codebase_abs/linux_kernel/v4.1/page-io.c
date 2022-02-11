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
int error = ! F_9 ( V_14 , & V_12 -> V_15 ) ;
struct V_16 * V_17 ;
F_10 (bvec, bio, i) {
struct V_18 * V_18 = V_17 -> V_19 ;
#ifdef F_11
struct V_18 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
#endif
struct V_5 * V_6 , * V_23 ;
unsigned V_24 = V_17 -> V_25 ;
unsigned V_26 = V_24 + V_17 -> V_27 ;
unsigned V_28 = 0 ;
unsigned long V_29 ;
if ( ! V_18 )
continue;
#ifdef F_11
if ( ! V_18 -> V_30 ) {
V_20 = V_18 ;
V_22 = (struct V_21 * ) F_12 ( V_20 ) ;
V_18 = V_22 -> V_31 ;
}
#endif
if ( error ) {
F_13 ( V_18 ) ;
F_14 ( V_32 , & V_18 -> V_30 -> V_29 ) ;
}
V_6 = V_23 = F_15 ( V_18 ) ;
F_16 ( V_29 ) ;
F_17 ( V_33 , & V_23 -> V_34 ) ;
do {
if ( F_18 ( V_6 ) < V_24 ||
F_18 ( V_6 ) + V_6 -> V_35 > V_26 ) {
if ( F_19 ( V_6 ) )
V_28 ++ ;
continue;
}
F_20 ( V_6 ) ;
if ( error )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_36 ) != V_23 );
F_21 ( V_33 , & V_23 -> V_34 ) ;
F_22 ( V_29 ) ;
if ( ! V_28 ) {
#ifdef F_11
if ( V_22 )
F_23 ( V_20 ) ;
#endif
F_24 ( V_18 ) ;
}
}
}
static void F_25 ( T_2 * V_37 )
{
struct V_12 * V_12 , * V_38 ;
F_26 ( ! F_27 ( & V_37 -> V_39 ) ) ;
F_26 ( V_37 -> V_40 & V_41 ) ;
F_28 ( V_37 -> V_42 ) ;
if ( F_29 ( & F_30 ( V_37 -> V_43 ) -> V_44 ) )
F_31 ( F_32 ( V_37 -> V_43 ) ) ;
for ( V_12 = V_37 -> V_12 ; V_12 ; V_12 = V_38 ) {
V_38 = V_12 -> V_45 ;
F_8 ( V_12 ) ;
F_33 ( V_12 ) ;
}
F_34 ( V_1 , V_37 ) ;
}
static void F_35 ( T_2 * V_37 )
{
struct V_43 * V_43 = V_37 -> V_43 ;
V_37 -> V_40 &= ~ V_41 ;
if ( F_29 ( & F_30 ( V_43 ) -> V_46 ) )
F_31 ( F_32 ( V_43 ) ) ;
}
static int F_36 ( T_2 * V_47 )
{
struct V_43 * V_43 = V_47 -> V_43 ;
T_3 V_48 = V_47 -> V_48 ;
T_4 V_49 = V_47 -> V_49 ;
T_5 * V_42 = V_47 -> V_42 ;
int V_50 = 0 ;
F_37 ( L_2
L_3 ,
V_47 , V_43 -> V_51 , V_47 -> V_39 . V_52 , V_47 -> V_39 . V_53 ) ;
V_47 -> V_42 = NULL ;
V_50 = F_38 ( V_42 , V_43 , V_48 , V_49 ) ;
if ( V_50 < 0 ) {
F_39 ( V_43 -> V_54 , V_55 ,
L_4
L_5
L_6 ,
V_43 -> V_51 , V_48 , V_49 , V_50 ) ;
}
F_35 ( V_47 ) ;
F_25 ( V_47 ) ;
return V_50 ;
}
static void F_40 ( struct V_43 * V_43 , struct V_56 * V_23 )
{
#ifdef F_41
struct V_56 * V_57 , * V_58 , * V_59 ;
T_2 * V_47 , * V_60 , * V_61 ;
if ( F_27 ( V_23 ) )
return;
F_37 ( L_7 , V_43 -> V_51 ) ;
F_42 (io, head, list) {
V_57 = & V_47 -> V_39 ;
V_58 = V_57 -> V_53 ;
V_60 = F_43 ( V_58 , T_2 , V_39 ) ;
V_59 = V_57 -> V_52 ;
V_61 = F_43 ( V_59 , T_2 , V_39 ) ;
F_37 ( L_8 ,
V_47 , V_43 -> V_51 , V_60 , V_61 ) ;
}
#endif
}
static void F_44 ( T_2 * V_37 )
{
struct V_62 * V_63 = F_30 ( V_37 -> V_43 ) ;
struct V_64 * V_65 = F_45 ( V_37 -> V_43 -> V_54 ) ;
struct V_66 * V_67 ;
unsigned long V_29 ;
F_28 ( ! ( V_37 -> V_40 & V_41 ) ) ;
F_28 ( ! V_37 -> V_42 && V_65 -> V_68 ) ;
F_46 ( & V_63 -> V_69 , V_29 ) ;
V_67 = V_65 -> V_70 ;
if ( F_27 ( & V_63 -> V_71 ) )
F_47 ( V_67 , & V_63 -> V_72 ) ;
F_48 ( & V_37 -> V_39 , & V_63 -> V_71 ) ;
F_49 ( & V_63 -> V_69 , V_29 ) ;
}
static int F_50 ( struct V_43 * V_43 ,
struct V_56 * V_23 )
{
T_2 * V_47 ;
struct V_56 V_73 ;
unsigned long V_29 ;
struct V_62 * V_63 = F_30 ( V_43 ) ;
int V_74 , V_50 = 0 ;
F_46 ( & V_63 -> V_69 , V_29 ) ;
F_40 ( V_43 , V_23 ) ;
F_51 ( V_23 , & V_73 ) ;
F_49 ( & V_63 -> V_69 , V_29 ) ;
while ( ! F_27 ( & V_73 ) ) {
V_47 = F_52 ( V_73 . V_52 , T_2 , V_39 ) ;
F_26 ( ! ( V_47 -> V_40 & V_41 ) ) ;
F_53 ( & V_47 -> V_39 ) ;
V_74 = F_36 ( V_47 ) ;
if ( F_54 ( ! V_50 && V_74 ) )
V_50 = V_74 ;
}
return V_50 ;
}
void F_55 ( struct V_75 * V_76 )
{
struct V_62 * V_63 = F_43 ( V_76 , struct V_62 ,
V_72 ) ;
F_50 ( & V_63 -> V_77 , & V_63 -> V_71 ) ;
}
T_2 * F_56 ( struct V_43 * V_43 , T_6 V_29 )
{
T_2 * V_47 = F_57 ( V_1 , V_29 ) ;
if ( V_47 ) {
F_58 ( & F_30 ( V_43 ) -> V_44 ) ;
V_47 -> V_43 = V_43 ;
F_59 ( & V_47 -> V_39 ) ;
F_60 ( & V_47 -> V_78 , 1 ) ;
}
return V_47 ;
}
void F_61 ( T_2 * V_37 )
{
if ( F_29 ( & V_37 -> V_78 ) ) {
if ( ! ( V_37 -> V_40 & V_41 ) || ! V_37 -> V_49 ) {
F_25 ( V_37 ) ;
return;
}
F_44 ( V_37 ) ;
}
}
int F_62 ( T_2 * V_37 )
{
int V_74 = 0 ;
if ( F_29 ( & V_37 -> V_78 ) ) {
if ( V_37 -> V_40 & V_41 ) {
V_74 = F_38 ( V_37 -> V_42 ,
V_37 -> V_43 , V_37 -> V_48 ,
V_37 -> V_49 ) ;
V_37 -> V_42 = NULL ;
F_35 ( V_37 ) ;
}
F_25 ( V_37 ) ;
}
return V_74 ;
}
T_2 * F_63 ( T_2 * V_37 )
{
F_58 ( & V_37 -> V_78 ) ;
return V_37 ;
}
static void F_64 ( struct V_12 * V_12 , int error )
{
T_2 * V_37 = V_12 -> V_45 ;
T_7 V_79 = V_12 -> V_80 . V_79 ;
F_26 ( ! V_37 ) ;
V_12 -> V_81 = NULL ;
if ( F_9 ( V_14 , & V_12 -> V_15 ) )
error = 0 ;
if ( error ) {
struct V_43 * V_43 = V_37 -> V_43 ;
F_65 ( V_43 -> V_54 , L_9
L_10 ,
error , V_43 -> V_51 ,
( unsigned long long ) V_37 -> V_48 ,
( long ) V_37 -> V_49 ,
( unsigned long long )
V_79 >> ( V_43 -> V_82 - 9 ) ) ;
F_66 ( V_43 -> V_83 , error ) ;
}
if ( V_37 -> V_40 & V_41 ) {
V_12 -> V_45 = F_67 ( & V_37 -> V_12 , V_12 ) ;
F_61 ( V_37 ) ;
} else {
F_61 ( V_37 ) ;
F_8 ( V_12 ) ;
F_33 ( V_12 ) ;
}
}
void F_68 ( struct F_68 * V_47 )
{
struct V_12 * V_12 = V_47 -> V_84 ;
if ( V_12 ) {
F_69 ( V_47 -> V_84 ) ;
F_70 ( V_47 -> V_85 , V_47 -> V_84 ) ;
F_26 ( F_71 ( V_47 -> V_84 , V_86 ) ) ;
F_33 ( V_47 -> V_84 ) ;
}
V_47 -> V_84 = NULL ;
}
void F_72 ( struct F_68 * V_47 ,
struct V_87 * V_88 )
{
V_47 -> V_85 = ( V_88 -> V_89 == V_90 ? V_91 : V_92 ) ;
V_47 -> V_84 = NULL ;
V_47 -> V_37 = NULL ;
}
static int F_73 ( struct F_68 * V_47 ,
struct V_5 * V_6 )
{
int V_93 = F_74 ( V_6 -> V_10 ) ;
struct V_12 * V_12 ;
V_12 = F_75 ( V_94 , F_76 ( V_93 , V_95 ) ) ;
if ( ! V_12 )
return - V_4 ;
V_12 -> V_80 . V_79 = V_6 -> V_11 * ( V_6 -> V_35 >> 9 ) ;
V_12 -> V_96 = V_6 -> V_10 ;
V_12 -> V_81 = F_64 ;
V_12 -> V_45 = F_63 ( V_47 -> V_37 ) ;
V_47 -> V_84 = V_12 ;
V_47 -> V_97 = V_6 -> V_11 ;
return 0 ;
}
static int F_77 ( struct F_68 * V_47 ,
struct V_43 * V_43 ,
struct V_18 * V_18 ,
struct V_5 * V_6 )
{
int V_50 ;
if ( V_47 -> V_84 && V_6 -> V_11 != V_47 -> V_97 ) {
V_98:
F_68 ( V_47 ) ;
}
if ( V_47 -> V_84 == NULL ) {
V_50 = F_73 ( V_47 , V_6 ) ;
if ( V_50 )
return V_50 ;
}
V_50 = F_78 ( V_47 -> V_84 , V_18 , V_6 -> V_35 , F_18 ( V_6 ) ) ;
if ( V_50 != V_6 -> V_35 )
goto V_98;
V_47 -> V_97 ++ ;
return 0 ;
}
int F_79 ( struct F_68 * V_47 ,
struct V_18 * V_18 ,
int V_99 ,
struct V_87 * V_88 ,
bool V_100 )
{
struct V_18 * V_20 = NULL ;
struct V_43 * V_43 = V_18 -> V_30 -> V_101 ;
unsigned V_102 , V_103 ;
struct V_5 * V_6 , * V_23 ;
int V_50 = 0 ;
int V_104 = 0 ;
V_103 = 1 << V_43 -> V_82 ;
F_26 ( ! F_80 ( V_18 ) ) ;
F_26 ( F_81 ( V_18 ) ) ;
if ( V_100 )
F_82 ( V_18 ) ;
else
F_83 ( V_18 ) ;
F_84 ( V_18 ) ;
if ( V_99 < V_105 )
F_85 ( V_18 , V_99 , V_105 ) ;
V_6 = V_23 = F_15 ( V_18 ) ;
do {
V_102 = F_18 ( V_6 ) ;
if ( V_102 >= V_99 ) {
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
continue;
}
if ( ! F_88 ( V_6 ) || F_89 ( V_6 ) ||
! F_90 ( V_6 ) || F_91 ( V_6 ) ) {
if ( ! F_90 ( V_6 ) )
F_86 ( V_6 ) ;
if ( V_47 -> V_84 )
F_68 ( V_47 ) ;
continue;
}
if ( F_92 ( V_6 ) ) {
F_93 ( V_6 ) ;
F_94 ( V_6 -> V_10 , V_6 -> V_11 ) ;
}
F_95 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_36 ) != V_23 );
V_6 = V_23 = F_15 ( V_18 ) ;
if ( F_96 ( V_43 ) && F_97 ( V_43 -> V_106 ) ) {
V_20 = F_98 ( V_43 , V_18 ) ;
if ( F_99 ( V_20 ) ) {
V_50 = F_100 ( V_20 ) ;
V_20 = NULL ;
goto V_107;
}
}
do {
if ( ! F_19 ( V_6 ) )
continue;
V_50 = F_77 ( V_47 , V_43 ,
V_20 ? V_20 : V_18 , V_6 ) ;
if ( V_50 ) {
break;
}
V_104 ++ ;
F_86 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_36 ) != V_23 );
if ( V_50 ) {
V_107:
if ( V_20 )
F_23 ( V_20 ) ;
F_6 ( V_9 L_11 , V_108 , V_50 ) ;
F_101 ( V_88 , V_18 ) ;
do {
F_20 ( V_6 ) ;
V_6 = V_6 -> V_36 ;
} while ( V_6 != V_23 );
}
F_102 ( V_18 ) ;
if ( ! V_104 )
F_24 ( V_18 ) ;
return V_50 ;
}
