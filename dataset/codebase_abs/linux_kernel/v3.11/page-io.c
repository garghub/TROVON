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
for ( V_13 = 0 ; V_13 < V_12 -> V_16 ; V_13 ++ ) {
struct V_17 * V_18 = & V_12 -> V_19 [ V_13 ] ;
struct V_20 * V_20 = V_18 -> V_21 ;
struct V_5 * V_6 , * V_22 ;
unsigned V_23 = V_18 -> V_24 ;
unsigned V_25 = V_23 + V_18 -> V_26 ;
unsigned V_27 = 0 ;
unsigned long V_28 ;
if ( ! V_20 )
continue;
if ( error ) {
F_10 ( V_20 ) ;
F_11 ( V_29 , & V_20 -> V_30 -> V_28 ) ;
}
V_6 = V_22 = F_12 ( V_20 ) ;
F_13 ( V_28 ) ;
F_14 ( V_31 , & V_22 -> V_32 ) ;
do {
if ( F_15 ( V_6 ) < V_23 ||
F_15 ( V_6 ) + V_6 -> V_33 > V_25 ) {
if ( F_16 ( V_6 ) )
V_27 ++ ;
continue;
}
F_17 ( V_6 ) ;
if ( error )
F_5 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_22 );
F_18 ( V_31 , & V_22 -> V_32 ) ;
F_19 ( V_28 ) ;
if ( ! V_27 )
F_20 ( V_20 ) ;
}
}
static void F_21 ( T_2 * V_35 )
{
struct V_12 * V_12 , * V_36 ;
F_22 ( ! F_23 ( & V_35 -> V_37 ) ) ;
F_22 ( V_35 -> V_38 & V_39 ) ;
F_24 ( V_35 -> V_40 ) ;
if ( F_25 ( & F_26 ( V_35 -> V_41 ) -> V_42 ) )
F_27 ( F_28 ( V_35 -> V_41 ) ) ;
for ( V_12 = V_35 -> V_12 ; V_12 ; V_12 = V_36 ) {
V_36 = V_12 -> V_43 ;
F_8 ( V_12 ) ;
F_29 ( V_12 ) ;
}
if ( V_35 -> V_38 & V_44 )
F_30 ( V_35 -> V_41 ) ;
if ( V_35 -> V_45 )
F_31 ( V_35 -> V_45 , V_35 -> V_46 , 0 ) ;
F_32 ( V_1 , V_35 ) ;
}
static void F_33 ( T_2 * V_35 )
{
struct V_41 * V_41 = V_35 -> V_41 ;
V_35 -> V_38 &= ~ V_39 ;
if ( F_25 ( & F_26 ( V_41 ) -> V_47 ) )
F_27 ( F_28 ( V_41 ) ) ;
}
static int F_34 ( T_2 * V_48 )
{
struct V_41 * V_41 = V_48 -> V_41 ;
T_3 V_49 = V_48 -> V_49 ;
T_4 V_50 = V_48 -> V_50 ;
T_5 * V_40 = V_48 -> V_40 ;
int V_51 = 0 ;
F_35 ( L_2
L_3 ,
V_48 , V_41 -> V_52 , V_48 -> V_37 . V_53 , V_48 -> V_37 . V_54 ) ;
V_48 -> V_40 = NULL ;
V_51 = F_36 ( V_40 , V_41 , V_49 , V_50 ) ;
if ( V_51 < 0 ) {
F_37 ( V_41 -> V_55 , V_56 ,
L_4
L_5
L_6 ,
V_41 -> V_52 , V_49 , V_50 , V_51 ) ;
}
F_33 ( V_48 ) ;
F_21 ( V_48 ) ;
return V_51 ;
}
static void F_38 ( struct V_41 * V_41 , struct V_57 * V_22 )
{
#ifdef F_39
struct V_57 * V_58 , * V_59 , * V_60 ;
T_2 * V_48 , * V_61 , * V_62 ;
if ( F_23 ( V_22 ) )
return;
F_35 ( L_7 , V_41 -> V_52 ) ;
F_40 (io, head, list) {
V_58 = & V_48 -> V_37 ;
V_59 = V_58 -> V_54 ;
V_61 = F_41 ( V_59 , T_2 , V_37 ) ;
V_60 = V_58 -> V_53 ;
V_62 = F_41 ( V_60 , T_2 , V_37 ) ;
F_35 ( L_8 ,
V_48 , V_41 -> V_52 , V_61 , V_62 ) ;
}
#endif
}
static void F_42 ( T_2 * V_35 )
{
struct V_63 * V_64 = F_26 ( V_35 -> V_41 ) ;
struct V_65 * V_66 ;
unsigned long V_28 ;
F_22 ( ! ( V_35 -> V_38 & V_39 ) ) ;
F_43 ( & V_64 -> V_67 , V_28 ) ;
if ( V_35 -> V_40 ) {
V_66 = F_44 ( V_35 -> V_41 -> V_55 ) -> V_68 ;
if ( F_23 ( & V_64 -> V_69 ) )
F_45 ( V_66 , & V_64 -> V_70 ) ;
F_46 ( & V_35 -> V_37 , & V_64 -> V_69 ) ;
} else {
V_66 = F_44 ( V_35 -> V_41 -> V_55 ) -> V_71 ;
if ( F_23 ( & V_64 -> V_72 ) )
F_45 ( V_66 , & V_64 -> V_73 ) ;
F_46 ( & V_35 -> V_37 , & V_64 -> V_72 ) ;
}
F_47 ( & V_64 -> V_67 , V_28 ) ;
}
static int F_48 ( struct V_41 * V_41 ,
struct V_57 * V_22 )
{
T_2 * V_48 ;
struct V_57 V_74 ;
unsigned long V_28 ;
struct V_63 * V_64 = F_26 ( V_41 ) ;
int V_75 , V_51 = 0 ;
F_43 ( & V_64 -> V_67 , V_28 ) ;
F_38 ( V_41 , V_22 ) ;
F_49 ( V_22 , & V_74 ) ;
F_47 ( & V_64 -> V_67 , V_28 ) ;
while ( ! F_23 ( & V_74 ) ) {
V_48 = F_50 ( V_74 . V_53 , T_2 , V_37 ) ;
F_22 ( ! ( V_48 -> V_38 & V_39 ) ) ;
F_51 ( & V_48 -> V_37 ) ;
V_75 = F_34 ( V_48 ) ;
if ( F_52 ( ! V_51 && V_75 ) )
V_51 = V_75 ;
}
return V_51 ;
}
void F_53 ( struct V_76 * V_77 )
{
struct V_63 * V_64 = F_41 ( V_77 , struct V_63 ,
V_70 ) ;
F_48 ( & V_64 -> V_78 , & V_64 -> V_69 ) ;
}
void F_54 ( struct V_76 * V_77 )
{
struct V_63 * V_64 = F_41 ( V_77 , struct V_63 ,
V_73 ) ;
F_48 ( & V_64 -> V_78 , & V_64 -> V_72 ) ;
}
T_2 * F_55 ( struct V_41 * V_41 , T_6 V_28 )
{
T_2 * V_48 = F_56 ( V_1 , V_28 ) ;
if ( V_48 ) {
F_57 ( & F_26 ( V_41 ) -> V_42 ) ;
V_48 -> V_41 = V_41 ;
F_58 ( & V_48 -> V_37 ) ;
F_59 ( & V_48 -> V_79 , 1 ) ;
}
return V_48 ;
}
void F_60 ( T_2 * V_35 )
{
if ( F_25 ( & V_35 -> V_79 ) ) {
if ( ! ( V_35 -> V_38 & V_39 ) || ! V_35 -> V_50 ) {
F_21 ( V_35 ) ;
return;
}
F_42 ( V_35 ) ;
}
}
int F_61 ( T_2 * V_35 )
{
int V_75 = 0 ;
if ( F_25 ( & V_35 -> V_79 ) ) {
if ( V_35 -> V_38 & V_39 ) {
V_75 = F_36 ( V_35 -> V_40 ,
V_35 -> V_41 , V_35 -> V_49 ,
V_35 -> V_50 ) ;
V_35 -> V_40 = NULL ;
F_33 ( V_35 ) ;
}
F_21 ( V_35 ) ;
}
return V_75 ;
}
T_2 * F_62 ( T_2 * V_35 )
{
F_57 ( & V_35 -> V_79 ) ;
return V_35 ;
}
static void F_63 ( struct V_12 * V_12 , int error )
{
T_2 * V_35 = V_12 -> V_43 ;
T_7 V_80 = V_12 -> V_80 ;
F_22 ( ! V_35 ) ;
V_12 -> V_81 = NULL ;
if ( F_9 ( V_14 , & V_12 -> V_15 ) )
error = 0 ;
if ( error ) {
struct V_41 * V_41 = V_35 -> V_41 ;
F_64 ( V_41 -> V_55 , L_9
L_10 ,
V_41 -> V_52 ,
( unsigned long long ) V_35 -> V_49 ,
( long ) V_35 -> V_50 ,
( unsigned long long )
V_80 >> ( V_41 -> V_82 - 9 ) ) ;
}
if ( V_35 -> V_38 & V_39 ) {
V_12 -> V_43 = F_65 ( & V_35 -> V_12 , V_12 ) ;
F_60 ( V_35 ) ;
} else {
F_60 ( V_35 ) ;
F_8 ( V_12 ) ;
F_29 ( V_12 ) ;
}
}
void F_66 ( struct F_66 * V_48 )
{
struct V_12 * V_12 = V_48 -> V_83 ;
if ( V_12 ) {
F_67 ( V_48 -> V_83 ) ;
F_68 ( V_48 -> V_84 , V_48 -> V_83 ) ;
F_22 ( F_69 ( V_48 -> V_83 , V_85 ) ) ;
F_29 ( V_48 -> V_83 ) ;
}
V_48 -> V_83 = NULL ;
}
void F_70 ( struct F_66 * V_48 ,
struct V_86 * V_87 )
{
V_48 -> V_84 = ( V_87 -> V_88 == V_89 ? V_90 : V_91 ) ;
V_48 -> V_83 = NULL ;
V_48 -> V_35 = NULL ;
}
static int F_71 ( struct F_66 * V_48 ,
struct V_5 * V_6 )
{
int V_92 = F_72 ( V_6 -> V_10 ) ;
struct V_12 * V_12 ;
V_12 = F_73 ( V_93 , F_74 ( V_92 , V_94 ) ) ;
if ( ! V_12 )
return - V_4 ;
V_12 -> V_80 = V_6 -> V_11 * ( V_6 -> V_33 >> 9 ) ;
V_12 -> V_95 = V_6 -> V_10 ;
V_12 -> V_81 = F_63 ;
V_12 -> V_43 = F_62 ( V_48 -> V_35 ) ;
V_48 -> V_83 = V_12 ;
V_48 -> V_96 = V_6 -> V_11 ;
return 0 ;
}
static int F_75 ( struct F_66 * V_48 ,
struct V_41 * V_41 ,
struct V_5 * V_6 )
{
int V_51 ;
if ( V_48 -> V_83 && V_6 -> V_11 != V_48 -> V_96 ) {
V_97:
F_66 ( V_48 ) ;
}
if ( V_48 -> V_83 == NULL ) {
V_51 = F_71 ( V_48 , V_6 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_76 ( V_48 -> V_83 , V_6 -> V_98 , V_6 -> V_33 , F_15 ( V_6 ) ) ;
if ( V_51 != V_6 -> V_33 )
goto V_97;
V_48 -> V_96 ++ ;
return 0 ;
}
int F_77 ( struct F_66 * V_48 ,
struct V_20 * V_20 ,
int V_99 ,
struct V_86 * V_87 )
{
struct V_41 * V_41 = V_20 -> V_30 -> V_100 ;
unsigned V_101 , V_102 ;
struct V_5 * V_6 , * V_22 ;
int V_51 = 0 ;
int V_103 = 0 ;
V_102 = 1 << V_41 -> V_82 ;
F_22 ( ! F_78 ( V_20 ) ) ;
F_22 ( F_79 ( V_20 ) ) ;
F_80 ( V_20 ) ;
F_81 ( V_20 ) ;
V_6 = V_22 = F_12 ( V_20 ) ;
do {
V_101 = F_15 ( V_6 ) ;
if ( V_101 >= V_99 ) {
F_82 ( V_20 , V_101 ,
V_101 + V_102 ) ;
F_83 ( V_6 ) ;
F_84 ( V_6 ) ;
continue;
}
if ( ! F_85 ( V_6 ) || F_86 ( V_6 ) ||
! F_87 ( V_6 ) || F_88 ( V_6 ) ) {
if ( ! F_87 ( V_6 ) )
F_83 ( V_6 ) ;
if ( V_48 -> V_83 )
F_66 ( V_48 ) ;
continue;
}
if ( F_89 ( V_6 ) ) {
F_90 ( V_6 ) ;
F_91 ( V_6 -> V_10 , V_6 -> V_11 ) ;
}
F_92 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_22 );
V_6 = V_22 = F_12 ( V_20 ) ;
do {
if ( ! F_16 ( V_6 ) )
continue;
V_51 = F_75 ( V_48 , V_41 , V_6 ) ;
if ( V_51 ) {
F_93 ( V_87 , V_20 ) ;
break;
}
V_103 ++ ;
F_83 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_22 );
if ( V_51 ) {
do {
F_17 ( V_6 ) ;
V_6 = V_6 -> V_34 ;
} while ( V_6 != V_22 );
}
F_94 ( V_20 ) ;
if ( ! V_103 )
F_20 ( V_20 ) ;
return V_51 ;
}
