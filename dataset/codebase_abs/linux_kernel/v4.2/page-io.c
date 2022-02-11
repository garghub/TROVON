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
V_18 = V_22 -> V_31 . V_32 ;
}
#endif
if ( error ) {
F_13 ( V_18 ) ;
F_14 ( V_33 , & V_18 -> V_30 -> V_29 ) ;
}
V_6 = V_23 = F_15 ( V_18 ) ;
F_16 ( V_29 ) ;
F_17 ( V_34 , & V_23 -> V_35 ) ;
do {
if ( F_18 ( V_6 ) < V_24 ||
F_18 ( V_6 ) + V_6 -> V_36 > V_26 ) {
if ( F_19 ( V_6 ) )
V_28 ++ ;
continue;
}
F_20 ( V_6 ) ;
if ( error )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_37 ) != V_23 );
F_21 ( V_34 , & V_23 -> V_35 ) ;
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
static void F_25 ( T_2 * V_38 )
{
struct V_12 * V_12 , * V_39 ;
F_26 ( ! F_27 ( & V_38 -> V_40 ) ) ;
F_26 ( V_38 -> V_41 & V_42 ) ;
F_28 ( V_38 -> V_43 ) ;
if ( F_29 ( & F_30 ( V_38 -> V_44 ) -> V_45 ) )
F_31 ( F_32 ( V_38 -> V_44 ) ) ;
for ( V_12 = V_38 -> V_12 ; V_12 ; V_12 = V_39 ) {
V_39 = V_12 -> V_46 ;
F_8 ( V_12 ) ;
F_33 ( V_12 ) ;
}
F_34 ( V_1 , V_38 ) ;
}
static void F_35 ( T_2 * V_38 )
{
struct V_44 * V_44 = V_38 -> V_44 ;
V_38 -> V_41 &= ~ V_42 ;
if ( F_29 ( & F_30 ( V_44 ) -> V_47 ) )
F_31 ( F_32 ( V_44 ) ) ;
}
static int F_36 ( T_2 * V_48 )
{
struct V_44 * V_44 = V_48 -> V_44 ;
T_3 V_49 = V_48 -> V_49 ;
T_4 V_50 = V_48 -> V_50 ;
T_5 * V_43 = V_48 -> V_43 ;
int V_51 = 0 ;
F_37 ( L_2
L_3 ,
V_48 , V_44 -> V_52 , V_48 -> V_40 . V_53 , V_48 -> V_40 . V_54 ) ;
V_48 -> V_43 = NULL ;
V_51 = F_38 ( V_43 , V_44 , V_49 , V_50 ) ;
if ( V_51 < 0 ) {
F_39 ( V_44 -> V_55 , V_56 ,
L_4
L_5
L_6 ,
V_44 -> V_52 , V_49 , V_50 , V_51 ) ;
}
F_35 ( V_48 ) ;
F_25 ( V_48 ) ;
return V_51 ;
}
static void F_40 ( struct V_44 * V_44 , struct V_57 * V_23 )
{
#ifdef F_41
struct V_57 * V_58 , * V_59 , * V_60 ;
T_2 * V_48 , * V_61 , * V_62 ;
if ( F_27 ( V_23 ) )
return;
F_37 ( L_7 , V_44 -> V_52 ) ;
F_42 (io, head, list) {
V_58 = & V_48 -> V_40 ;
V_59 = V_58 -> V_54 ;
V_61 = F_43 ( V_59 , T_2 , V_40 ) ;
V_60 = V_58 -> V_53 ;
V_62 = F_43 ( V_60 , T_2 , V_40 ) ;
F_37 ( L_8 ,
V_48 , V_44 -> V_52 , V_61 , V_62 ) ;
}
#endif
}
static void F_44 ( T_2 * V_38 )
{
struct V_63 * V_64 = F_30 ( V_38 -> V_44 ) ;
struct V_65 * V_66 = F_45 ( V_38 -> V_44 -> V_55 ) ;
struct V_67 * V_68 ;
unsigned long V_29 ;
F_28 ( ! ( V_38 -> V_41 & V_42 ) ) ;
F_28 ( ! V_38 -> V_43 && V_66 -> V_69 ) ;
F_46 ( & V_64 -> V_70 , V_29 ) ;
V_68 = V_66 -> V_71 ;
if ( F_27 ( & V_64 -> V_72 ) )
F_47 ( V_68 , & V_64 -> V_73 ) ;
F_48 ( & V_38 -> V_40 , & V_64 -> V_72 ) ;
F_49 ( & V_64 -> V_70 , V_29 ) ;
}
static int F_50 ( struct V_44 * V_44 ,
struct V_57 * V_23 )
{
T_2 * V_48 ;
struct V_57 V_74 ;
unsigned long V_29 ;
struct V_63 * V_64 = F_30 ( V_44 ) ;
int V_75 , V_51 = 0 ;
F_46 ( & V_64 -> V_70 , V_29 ) ;
F_40 ( V_44 , V_23 ) ;
F_51 ( V_23 , & V_74 ) ;
F_49 ( & V_64 -> V_70 , V_29 ) ;
while ( ! F_27 ( & V_74 ) ) {
V_48 = F_52 ( V_74 . V_53 , T_2 , V_40 ) ;
F_26 ( ! ( V_48 -> V_41 & V_42 ) ) ;
F_53 ( & V_48 -> V_40 ) ;
V_75 = F_36 ( V_48 ) ;
if ( F_54 ( ! V_51 && V_75 ) )
V_51 = V_75 ;
}
return V_51 ;
}
void F_55 ( struct V_76 * V_77 )
{
struct V_63 * V_64 = F_43 ( V_77 , struct V_63 ,
V_73 ) ;
F_50 ( & V_64 -> V_78 , & V_64 -> V_72 ) ;
}
T_2 * F_56 ( struct V_44 * V_44 , T_6 V_29 )
{
T_2 * V_48 = F_57 ( V_1 , V_29 ) ;
if ( V_48 ) {
F_58 ( & F_30 ( V_44 ) -> V_45 ) ;
V_48 -> V_44 = V_44 ;
F_59 ( & V_48 -> V_40 ) ;
F_60 ( & V_48 -> V_79 , 1 ) ;
}
return V_48 ;
}
void F_61 ( T_2 * V_38 )
{
if ( F_29 ( & V_38 -> V_79 ) ) {
if ( ! ( V_38 -> V_41 & V_42 ) || ! V_38 -> V_50 ) {
F_25 ( V_38 ) ;
return;
}
F_44 ( V_38 ) ;
}
}
int F_62 ( T_2 * V_38 )
{
int V_75 = 0 ;
if ( F_29 ( & V_38 -> V_79 ) ) {
if ( V_38 -> V_41 & V_42 ) {
V_75 = F_38 ( V_38 -> V_43 ,
V_38 -> V_44 , V_38 -> V_49 ,
V_38 -> V_50 ) ;
V_38 -> V_43 = NULL ;
F_35 ( V_38 ) ;
}
F_25 ( V_38 ) ;
}
return V_75 ;
}
T_2 * F_63 ( T_2 * V_38 )
{
F_58 ( & V_38 -> V_79 ) ;
return V_38 ;
}
static void F_64 ( struct V_12 * V_12 , int error )
{
T_2 * V_38 = V_12 -> V_46 ;
T_7 V_80 = V_12 -> V_81 . V_80 ;
F_26 ( ! V_38 ) ;
V_12 -> V_82 = NULL ;
if ( F_9 ( V_14 , & V_12 -> V_15 ) )
error = 0 ;
if ( error ) {
struct V_44 * V_44 = V_38 -> V_44 ;
F_65 ( V_44 -> V_55 , L_9
L_10 ,
error , V_44 -> V_52 ,
( unsigned long long ) V_38 -> V_49 ,
( long ) V_38 -> V_50 ,
( unsigned long long )
V_80 >> ( V_44 -> V_83 - 9 ) ) ;
F_66 ( V_44 -> V_84 , error ) ;
}
if ( V_38 -> V_41 & V_42 ) {
V_12 -> V_46 = F_67 ( & V_38 -> V_12 , V_12 ) ;
F_61 ( V_38 ) ;
} else {
F_61 ( V_38 ) ;
F_8 ( V_12 ) ;
F_33 ( V_12 ) ;
}
}
void F_68 ( struct F_68 * V_48 )
{
struct V_12 * V_12 = V_48 -> V_85 ;
if ( V_12 ) {
F_69 ( V_48 -> V_85 ) ;
F_70 ( V_48 -> V_86 , V_48 -> V_85 ) ;
F_33 ( V_48 -> V_85 ) ;
}
V_48 -> V_85 = NULL ;
}
void F_71 ( struct F_68 * V_48 ,
struct V_87 * V_88 )
{
V_48 -> V_86 = ( V_88 -> V_89 == V_90 ? V_91 : V_92 ) ;
V_48 -> V_85 = NULL ;
V_48 -> V_38 = NULL ;
}
static int F_72 ( struct F_68 * V_48 ,
struct V_5 * V_6 )
{
int V_93 = F_73 ( V_6 -> V_10 ) ;
struct V_12 * V_12 ;
V_12 = F_74 ( V_94 , F_75 ( V_93 , V_95 ) ) ;
if ( ! V_12 )
return - V_4 ;
V_12 -> V_81 . V_80 = V_6 -> V_11 * ( V_6 -> V_36 >> 9 ) ;
V_12 -> V_96 = V_6 -> V_10 ;
V_12 -> V_82 = F_64 ;
V_12 -> V_46 = F_63 ( V_48 -> V_38 ) ;
V_48 -> V_85 = V_12 ;
V_48 -> V_97 = V_6 -> V_11 ;
return 0 ;
}
static int F_76 ( struct F_68 * V_48 ,
struct V_44 * V_44 ,
struct V_18 * V_18 ,
struct V_5 * V_6 )
{
int V_51 ;
if ( V_48 -> V_85 && V_6 -> V_11 != V_48 -> V_97 ) {
V_98:
F_68 ( V_48 ) ;
}
if ( V_48 -> V_85 == NULL ) {
V_51 = F_72 ( V_48 , V_6 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_77 ( V_48 -> V_85 , V_18 , V_6 -> V_36 , F_18 ( V_6 ) ) ;
if ( V_51 != V_6 -> V_36 )
goto V_98;
V_48 -> V_97 ++ ;
return 0 ;
}
int F_78 ( struct F_68 * V_48 ,
struct V_18 * V_18 ,
int V_99 ,
struct V_87 * V_88 ,
bool V_100 )
{
struct V_18 * V_20 = NULL ;
struct V_44 * V_44 = V_18 -> V_30 -> V_101 ;
unsigned V_102 , V_103 ;
struct V_5 * V_6 , * V_23 ;
int V_51 = 0 ;
int V_104 = 0 ;
V_103 = 1 << V_44 -> V_83 ;
F_26 ( ! F_79 ( V_18 ) ) ;
F_26 ( F_80 ( V_18 ) ) ;
if ( V_100 )
F_81 ( V_18 ) ;
else
F_82 ( V_18 ) ;
F_83 ( V_18 ) ;
if ( V_99 < V_105 )
F_84 ( V_18 , V_99 , V_105 ) ;
V_6 = V_23 = F_15 ( V_18 ) ;
do {
V_102 = F_18 ( V_6 ) ;
if ( V_102 >= V_99 ) {
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
continue;
}
if ( ! F_87 ( V_6 ) || F_88 ( V_6 ) ||
! F_89 ( V_6 ) || F_90 ( V_6 ) ) {
if ( ! F_89 ( V_6 ) )
F_85 ( V_6 ) ;
if ( V_48 -> V_85 )
F_68 ( V_48 ) ;
continue;
}
if ( F_91 ( V_6 ) ) {
F_92 ( V_6 ) ;
F_93 ( V_6 -> V_10 , V_6 -> V_11 ) ;
}
F_94 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_37 ) != V_23 );
V_6 = V_23 = F_15 ( V_18 ) ;
if ( F_95 ( V_44 ) && F_96 ( V_44 -> V_106 ) ) {
V_20 = F_97 ( V_44 , V_18 ) ;
if ( F_98 ( V_20 ) ) {
V_51 = F_99 ( V_20 ) ;
V_20 = NULL ;
goto V_107;
}
}
do {
if ( ! F_19 ( V_6 ) )
continue;
V_51 = F_76 ( V_48 , V_44 ,
V_20 ? V_20 : V_18 , V_6 ) ;
if ( V_51 ) {
break;
}
V_104 ++ ;
F_85 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_37 ) != V_23 );
if ( V_51 ) {
V_107:
if ( V_20 )
F_23 ( V_20 ) ;
F_6 ( V_9 L_11 , V_108 , V_51 ) ;
F_100 ( V_88 , V_18 ) ;
do {
F_20 ( V_6 ) ;
V_6 = V_6 -> V_37 ;
} while ( V_6 != V_23 );
}
F_101 ( V_18 ) ;
if ( ! V_104 )
F_24 ( V_18 ) ;
return V_51 ;
}
