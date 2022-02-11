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
struct V_5 * V_6 , * V_20 ;
unsigned V_21 = V_17 -> V_22 ;
unsigned V_23 = V_21 + V_17 -> V_24 ;
unsigned V_25 = 0 ;
unsigned long V_26 ;
if ( ! V_18 )
continue;
if ( error ) {
F_11 ( V_18 ) ;
F_12 ( V_27 , & V_18 -> V_28 -> V_26 ) ;
}
V_6 = V_20 = F_13 ( V_18 ) ;
F_14 ( V_26 ) ;
F_15 ( V_29 , & V_20 -> V_30 ) ;
do {
if ( F_16 ( V_6 ) < V_21 ||
F_16 ( V_6 ) + V_6 -> V_31 > V_23 ) {
if ( F_17 ( V_6 ) )
V_25 ++ ;
continue;
}
F_18 ( V_6 ) ;
if ( error )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_32 ) != V_20 );
F_19 ( V_29 , & V_20 -> V_30 ) ;
F_20 ( V_26 ) ;
if ( ! V_25 )
F_21 ( V_18 ) ;
}
}
static void F_22 ( T_2 * V_33 )
{
struct V_12 * V_12 , * V_34 ;
F_23 ( ! F_24 ( & V_33 -> V_35 ) ) ;
F_23 ( V_33 -> V_36 & V_37 ) ;
F_25 ( V_33 -> V_38 ) ;
if ( F_26 ( & F_27 ( V_33 -> V_39 ) -> V_40 ) )
F_28 ( F_29 ( V_33 -> V_39 ) ) ;
for ( V_12 = V_33 -> V_12 ; V_12 ; V_12 = V_34 ) {
V_34 = V_12 -> V_41 ;
F_8 ( V_12 ) ;
F_30 ( V_12 ) ;
}
F_31 ( V_1 , V_33 ) ;
}
static void F_32 ( T_2 * V_33 )
{
struct V_39 * V_39 = V_33 -> V_39 ;
V_33 -> V_36 &= ~ V_37 ;
if ( F_26 ( & F_27 ( V_39 ) -> V_42 ) )
F_28 ( F_29 ( V_39 ) ) ;
}
static int F_33 ( T_2 * V_43 )
{
struct V_39 * V_39 = V_43 -> V_39 ;
T_3 V_44 = V_43 -> V_44 ;
T_4 V_45 = V_43 -> V_45 ;
T_5 * V_38 = V_43 -> V_38 ;
int V_46 = 0 ;
F_34 ( L_2
L_3 ,
V_43 , V_39 -> V_47 , V_43 -> V_35 . V_48 , V_43 -> V_35 . V_49 ) ;
V_43 -> V_38 = NULL ;
V_46 = F_35 ( V_38 , V_39 , V_44 , V_45 ) ;
if ( V_46 < 0 ) {
F_36 ( V_39 -> V_50 , V_51 ,
L_4
L_5
L_6 ,
V_39 -> V_47 , V_44 , V_45 , V_46 ) ;
}
F_32 ( V_43 ) ;
F_22 ( V_43 ) ;
return V_46 ;
}
static void F_37 ( struct V_39 * V_39 , struct V_52 * V_20 )
{
#ifdef F_38
struct V_52 * V_53 , * V_54 , * V_55 ;
T_2 * V_43 , * V_56 , * V_57 ;
if ( F_24 ( V_20 ) )
return;
F_34 ( L_7 , V_39 -> V_47 ) ;
F_39 (io, head, list) {
V_53 = & V_43 -> V_35 ;
V_54 = V_53 -> V_49 ;
V_56 = F_40 ( V_54 , T_2 , V_35 ) ;
V_55 = V_53 -> V_48 ;
V_57 = F_40 ( V_55 , T_2 , V_35 ) ;
F_34 ( L_8 ,
V_43 , V_39 -> V_47 , V_56 , V_57 ) ;
}
#endif
}
static void F_41 ( T_2 * V_33 )
{
struct V_58 * V_59 = F_27 ( V_33 -> V_39 ) ;
struct V_60 * V_61 = F_42 ( V_33 -> V_39 -> V_50 ) ;
struct V_62 * V_63 ;
unsigned long V_26 ;
F_25 ( ! ( V_33 -> V_36 & V_37 ) ) ;
F_25 ( ! V_33 -> V_38 && V_61 -> V_64 ) ;
F_43 ( & V_59 -> V_65 , V_26 ) ;
V_63 = V_61 -> V_66 ;
if ( F_24 ( & V_59 -> V_67 ) )
F_44 ( V_63 , & V_59 -> V_68 ) ;
F_45 ( & V_33 -> V_35 , & V_59 -> V_67 ) ;
F_46 ( & V_59 -> V_65 , V_26 ) ;
}
static int F_47 ( struct V_39 * V_39 ,
struct V_52 * V_20 )
{
T_2 * V_43 ;
struct V_52 V_69 ;
unsigned long V_26 ;
struct V_58 * V_59 = F_27 ( V_39 ) ;
int V_70 , V_46 = 0 ;
F_43 ( & V_59 -> V_65 , V_26 ) ;
F_37 ( V_39 , V_20 ) ;
F_48 ( V_20 , & V_69 ) ;
F_46 ( & V_59 -> V_65 , V_26 ) ;
while ( ! F_24 ( & V_69 ) ) {
V_43 = F_49 ( V_69 . V_48 , T_2 , V_35 ) ;
F_23 ( ! ( V_43 -> V_36 & V_37 ) ) ;
F_50 ( & V_43 -> V_35 ) ;
V_70 = F_33 ( V_43 ) ;
if ( F_51 ( ! V_46 && V_70 ) )
V_46 = V_70 ;
}
return V_46 ;
}
void F_52 ( struct V_71 * V_72 )
{
struct V_58 * V_59 = F_40 ( V_72 , struct V_58 ,
V_68 ) ;
F_47 ( & V_59 -> V_73 , & V_59 -> V_67 ) ;
}
T_2 * F_53 ( struct V_39 * V_39 , T_6 V_26 )
{
T_2 * V_43 = F_54 ( V_1 , V_26 ) ;
if ( V_43 ) {
F_55 ( & F_27 ( V_39 ) -> V_40 ) ;
V_43 -> V_39 = V_39 ;
F_56 ( & V_43 -> V_35 ) ;
F_57 ( & V_43 -> V_74 , 1 ) ;
}
return V_43 ;
}
void F_58 ( T_2 * V_33 )
{
if ( F_26 ( & V_33 -> V_74 ) ) {
if ( ! ( V_33 -> V_36 & V_37 ) || ! V_33 -> V_45 ) {
F_22 ( V_33 ) ;
return;
}
F_41 ( V_33 ) ;
}
}
int F_59 ( T_2 * V_33 )
{
int V_70 = 0 ;
if ( F_26 ( & V_33 -> V_74 ) ) {
if ( V_33 -> V_36 & V_37 ) {
V_70 = F_35 ( V_33 -> V_38 ,
V_33 -> V_39 , V_33 -> V_44 ,
V_33 -> V_45 ) ;
V_33 -> V_38 = NULL ;
F_32 ( V_33 ) ;
}
F_22 ( V_33 ) ;
}
return V_70 ;
}
T_2 * F_60 ( T_2 * V_33 )
{
F_55 ( & V_33 -> V_74 ) ;
return V_33 ;
}
static void F_61 ( struct V_12 * V_12 , int error )
{
T_2 * V_33 = V_12 -> V_41 ;
T_7 V_75 = V_12 -> V_76 . V_75 ;
F_23 ( ! V_33 ) ;
V_12 -> V_77 = NULL ;
if ( F_9 ( V_14 , & V_12 -> V_15 ) )
error = 0 ;
if ( error ) {
struct V_39 * V_39 = V_33 -> V_39 ;
F_62 ( V_39 -> V_50 , L_9
L_10 ,
V_39 -> V_47 ,
( unsigned long long ) V_33 -> V_44 ,
( long ) V_33 -> V_45 ,
( unsigned long long )
V_75 >> ( V_39 -> V_78 - 9 ) ) ;
}
if ( V_33 -> V_36 & V_37 ) {
V_12 -> V_41 = F_63 ( & V_33 -> V_12 , V_12 ) ;
F_58 ( V_33 ) ;
} else {
F_58 ( V_33 ) ;
F_8 ( V_12 ) ;
F_30 ( V_12 ) ;
}
}
void F_64 ( struct F_64 * V_43 )
{
struct V_12 * V_12 = V_43 -> V_79 ;
if ( V_12 ) {
F_65 ( V_43 -> V_79 ) ;
F_66 ( V_43 -> V_80 , V_43 -> V_79 ) ;
F_23 ( F_67 ( V_43 -> V_79 , V_81 ) ) ;
F_30 ( V_43 -> V_79 ) ;
}
V_43 -> V_79 = NULL ;
}
void F_68 ( struct F_64 * V_43 ,
struct V_82 * V_83 )
{
V_43 -> V_80 = ( V_83 -> V_84 == V_85 ? V_86 : V_87 ) ;
V_43 -> V_79 = NULL ;
V_43 -> V_33 = NULL ;
}
static int F_69 ( struct F_64 * V_43 ,
struct V_5 * V_6 )
{
int V_88 = F_70 ( V_6 -> V_10 ) ;
struct V_12 * V_12 ;
V_12 = F_71 ( V_89 , F_72 ( V_88 , V_90 ) ) ;
if ( ! V_12 )
return - V_4 ;
V_12 -> V_76 . V_75 = V_6 -> V_11 * ( V_6 -> V_31 >> 9 ) ;
V_12 -> V_91 = V_6 -> V_10 ;
V_12 -> V_77 = F_61 ;
V_12 -> V_41 = F_60 ( V_43 -> V_33 ) ;
V_43 -> V_79 = V_12 ;
V_43 -> V_92 = V_6 -> V_11 ;
return 0 ;
}
static int F_73 ( struct F_64 * V_43 ,
struct V_39 * V_39 ,
struct V_5 * V_6 )
{
int V_46 ;
if ( V_43 -> V_79 && V_6 -> V_11 != V_43 -> V_92 ) {
V_93:
F_64 ( V_43 ) ;
}
if ( V_43 -> V_79 == NULL ) {
V_46 = F_69 ( V_43 , V_6 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = F_74 ( V_43 -> V_79 , V_6 -> V_94 , V_6 -> V_31 , F_16 ( V_6 ) ) ;
if ( V_46 != V_6 -> V_31 )
goto V_93;
V_43 -> V_92 ++ ;
return 0 ;
}
int F_75 ( struct F_64 * V_43 ,
struct V_18 * V_18 ,
int V_95 ,
struct V_82 * V_83 )
{
struct V_39 * V_39 = V_18 -> V_28 -> V_96 ;
unsigned V_97 , V_98 ;
struct V_5 * V_6 , * V_20 ;
int V_46 = 0 ;
int V_99 = 0 ;
V_98 = 1 << V_39 -> V_78 ;
F_23 ( ! F_76 ( V_18 ) ) ;
F_23 ( F_77 ( V_18 ) ) ;
F_78 ( V_18 ) ;
F_79 ( V_18 ) ;
V_6 = V_20 = F_13 ( V_18 ) ;
do {
V_97 = F_16 ( V_6 ) ;
if ( V_97 >= V_95 ) {
F_80 ( V_18 , V_97 ,
V_97 + V_98 ) ;
F_81 ( V_6 ) ;
F_82 ( V_6 ) ;
continue;
}
if ( ! F_83 ( V_6 ) || F_84 ( V_6 ) ||
! F_85 ( V_6 ) || F_86 ( V_6 ) ) {
if ( ! F_85 ( V_6 ) )
F_81 ( V_6 ) ;
if ( V_43 -> V_79 )
F_64 ( V_43 ) ;
continue;
}
if ( F_87 ( V_6 ) ) {
F_88 ( V_6 ) ;
F_89 ( V_6 -> V_10 , V_6 -> V_11 ) ;
}
F_90 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_32 ) != V_20 );
V_6 = V_20 = F_13 ( V_18 ) ;
do {
if ( ! F_17 ( V_6 ) )
continue;
V_46 = F_73 ( V_43 , V_39 , V_6 ) ;
if ( V_46 ) {
F_91 ( V_83 , V_18 ) ;
break;
}
V_99 ++ ;
F_81 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_32 ) != V_20 );
if ( V_46 ) {
do {
F_18 ( V_6 ) ;
V_6 = V_6 -> V_32 ;
} while ( V_6 != V_20 );
}
F_92 ( V_18 ) ;
if ( ! V_99 )
F_21 ( V_18 ) ;
return V_46 ;
}
