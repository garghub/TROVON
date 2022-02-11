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
F_30 ( V_1 , V_35 ) ;
}
static void F_31 ( T_2 * V_35 )
{
struct V_41 * V_41 = V_35 -> V_41 ;
V_35 -> V_38 &= ~ V_39 ;
if ( F_25 ( & F_26 ( V_41 ) -> V_44 ) )
F_27 ( F_28 ( V_41 ) ) ;
}
static int F_32 ( T_2 * V_45 )
{
struct V_41 * V_41 = V_45 -> V_41 ;
T_3 V_46 = V_45 -> V_46 ;
T_4 V_47 = V_45 -> V_47 ;
T_5 * V_40 = V_45 -> V_40 ;
int V_48 = 0 ;
F_33 ( L_2
L_3 ,
V_45 , V_41 -> V_49 , V_45 -> V_37 . V_50 , V_45 -> V_37 . V_51 ) ;
V_45 -> V_40 = NULL ;
V_48 = F_34 ( V_40 , V_41 , V_46 , V_47 ) ;
if ( V_48 < 0 ) {
F_35 ( V_41 -> V_52 , V_53 ,
L_4
L_5
L_6 ,
V_41 -> V_49 , V_46 , V_47 , V_48 ) ;
}
F_31 ( V_45 ) ;
F_21 ( V_45 ) ;
return V_48 ;
}
static void F_36 ( struct V_41 * V_41 , struct V_54 * V_22 )
{
#ifdef F_37
struct V_54 * V_55 , * V_56 , * V_57 ;
T_2 * V_45 , * V_58 , * V_59 ;
if ( F_23 ( V_22 ) )
return;
F_33 ( L_7 , V_41 -> V_49 ) ;
F_38 (io, head, list) {
V_55 = & V_45 -> V_37 ;
V_56 = V_55 -> V_51 ;
V_58 = F_39 ( V_56 , T_2 , V_37 ) ;
V_57 = V_55 -> V_50 ;
V_59 = F_39 ( V_57 , T_2 , V_37 ) ;
F_33 ( L_8 ,
V_45 , V_41 -> V_49 , V_58 , V_59 ) ;
}
#endif
}
static void F_40 ( T_2 * V_35 )
{
struct V_60 * V_61 = F_26 ( V_35 -> V_41 ) ;
struct V_62 * V_63 ;
unsigned long V_28 ;
F_24 ( ! ( V_35 -> V_38 & V_39 ) ) ;
F_24 ( ! V_35 -> V_40 ) ;
F_41 ( & V_61 -> V_64 , V_28 ) ;
V_63 = F_42 ( V_35 -> V_41 -> V_52 ) -> V_65 ;
if ( F_23 ( & V_61 -> V_66 ) )
F_43 ( V_63 , & V_61 -> V_67 ) ;
F_44 ( & V_35 -> V_37 , & V_61 -> V_66 ) ;
F_45 ( & V_61 -> V_64 , V_28 ) ;
}
static int F_46 ( struct V_41 * V_41 ,
struct V_54 * V_22 )
{
T_2 * V_45 ;
struct V_54 V_68 ;
unsigned long V_28 ;
struct V_60 * V_61 = F_26 ( V_41 ) ;
int V_69 , V_48 = 0 ;
F_41 ( & V_61 -> V_64 , V_28 ) ;
F_36 ( V_41 , V_22 ) ;
F_47 ( V_22 , & V_68 ) ;
F_45 ( & V_61 -> V_64 , V_28 ) ;
while ( ! F_23 ( & V_68 ) ) {
V_45 = F_48 ( V_68 . V_50 , T_2 , V_37 ) ;
F_22 ( ! ( V_45 -> V_38 & V_39 ) ) ;
F_49 ( & V_45 -> V_37 ) ;
V_69 = F_32 ( V_45 ) ;
if ( F_50 ( ! V_48 && V_69 ) )
V_48 = V_69 ;
}
return V_48 ;
}
void F_51 ( struct V_70 * V_71 )
{
struct V_60 * V_61 = F_39 ( V_71 , struct V_60 ,
V_67 ) ;
F_46 ( & V_61 -> V_72 , & V_61 -> V_66 ) ;
}
T_2 * F_52 ( struct V_41 * V_41 , T_6 V_28 )
{
T_2 * V_45 = F_53 ( V_1 , V_28 ) ;
if ( V_45 ) {
F_54 ( & F_26 ( V_41 ) -> V_42 ) ;
V_45 -> V_41 = V_41 ;
F_55 ( & V_45 -> V_37 ) ;
F_56 ( & V_45 -> V_73 , 1 ) ;
}
return V_45 ;
}
void F_57 ( T_2 * V_35 )
{
if ( F_25 ( & V_35 -> V_73 ) ) {
if ( ! ( V_35 -> V_38 & V_39 ) || ! V_35 -> V_47 ) {
F_21 ( V_35 ) ;
return;
}
F_40 ( V_35 ) ;
}
}
int F_58 ( T_2 * V_35 )
{
int V_69 = 0 ;
if ( F_25 ( & V_35 -> V_73 ) ) {
if ( V_35 -> V_38 & V_39 ) {
V_69 = F_34 ( V_35 -> V_40 ,
V_35 -> V_41 , V_35 -> V_46 ,
V_35 -> V_47 ) ;
V_35 -> V_40 = NULL ;
F_31 ( V_35 ) ;
}
F_21 ( V_35 ) ;
}
return V_69 ;
}
T_2 * F_59 ( T_2 * V_35 )
{
F_54 ( & V_35 -> V_73 ) ;
return V_35 ;
}
static void F_60 ( struct V_12 * V_12 , int error )
{
T_2 * V_35 = V_12 -> V_43 ;
T_7 V_74 = V_12 -> V_74 ;
F_22 ( ! V_35 ) ;
V_12 -> V_75 = NULL ;
if ( F_9 ( V_14 , & V_12 -> V_15 ) )
error = 0 ;
if ( error ) {
struct V_41 * V_41 = V_35 -> V_41 ;
F_61 ( V_41 -> V_52 , L_9
L_10 ,
V_41 -> V_49 ,
( unsigned long long ) V_35 -> V_46 ,
( long ) V_35 -> V_47 ,
( unsigned long long )
V_74 >> ( V_41 -> V_76 - 9 ) ) ;
}
if ( V_35 -> V_38 & V_39 ) {
V_12 -> V_43 = F_62 ( & V_35 -> V_12 , V_12 ) ;
F_57 ( V_35 ) ;
} else {
F_57 ( V_35 ) ;
F_8 ( V_12 ) ;
F_29 ( V_12 ) ;
}
}
void F_63 ( struct F_63 * V_45 )
{
struct V_12 * V_12 = V_45 -> V_77 ;
if ( V_12 ) {
F_64 ( V_45 -> V_77 ) ;
F_65 ( V_45 -> V_78 , V_45 -> V_77 ) ;
F_22 ( F_66 ( V_45 -> V_77 , V_79 ) ) ;
F_29 ( V_45 -> V_77 ) ;
}
V_45 -> V_77 = NULL ;
}
void F_67 ( struct F_63 * V_45 ,
struct V_80 * V_81 )
{
V_45 -> V_78 = ( V_81 -> V_82 == V_83 ? V_84 : V_85 ) ;
V_45 -> V_77 = NULL ;
V_45 -> V_35 = NULL ;
}
static int F_68 ( struct F_63 * V_45 ,
struct V_5 * V_6 )
{
int V_86 = F_69 ( V_6 -> V_10 ) ;
struct V_12 * V_12 ;
V_12 = F_70 ( V_87 , F_71 ( V_86 , V_88 ) ) ;
if ( ! V_12 )
return - V_4 ;
V_12 -> V_74 = V_6 -> V_11 * ( V_6 -> V_33 >> 9 ) ;
V_12 -> V_89 = V_6 -> V_10 ;
V_12 -> V_75 = F_60 ;
V_12 -> V_43 = F_59 ( V_45 -> V_35 ) ;
V_45 -> V_77 = V_12 ;
V_45 -> V_90 = V_6 -> V_11 ;
return 0 ;
}
static int F_72 ( struct F_63 * V_45 ,
struct V_41 * V_41 ,
struct V_5 * V_6 )
{
int V_48 ;
if ( V_45 -> V_77 && V_6 -> V_11 != V_45 -> V_90 ) {
V_91:
F_63 ( V_45 ) ;
}
if ( V_45 -> V_77 == NULL ) {
V_48 = F_68 ( V_45 , V_6 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_73 ( V_45 -> V_77 , V_6 -> V_92 , V_6 -> V_33 , F_15 ( V_6 ) ) ;
if ( V_48 != V_6 -> V_33 )
goto V_91;
V_45 -> V_90 ++ ;
return 0 ;
}
int F_74 ( struct F_63 * V_45 ,
struct V_20 * V_20 ,
int V_93 ,
struct V_80 * V_81 )
{
struct V_41 * V_41 = V_20 -> V_30 -> V_94 ;
unsigned V_95 , V_96 ;
struct V_5 * V_6 , * V_22 ;
int V_48 = 0 ;
int V_97 = 0 ;
V_96 = 1 << V_41 -> V_76 ;
F_22 ( ! F_75 ( V_20 ) ) ;
F_22 ( F_76 ( V_20 ) ) ;
F_77 ( V_20 ) ;
F_78 ( V_20 ) ;
V_6 = V_22 = F_12 ( V_20 ) ;
do {
V_95 = F_15 ( V_6 ) ;
if ( V_95 >= V_93 ) {
F_79 ( V_20 , V_95 ,
V_95 + V_96 ) ;
F_80 ( V_6 ) ;
F_81 ( V_6 ) ;
continue;
}
if ( ! F_82 ( V_6 ) || F_83 ( V_6 ) ||
! F_84 ( V_6 ) || F_85 ( V_6 ) ) {
if ( ! F_84 ( V_6 ) )
F_80 ( V_6 ) ;
if ( V_45 -> V_77 )
F_63 ( V_45 ) ;
continue;
}
if ( F_86 ( V_6 ) ) {
F_87 ( V_6 ) ;
F_88 ( V_6 -> V_10 , V_6 -> V_11 ) ;
}
F_89 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_22 );
V_6 = V_22 = F_12 ( V_20 ) ;
do {
if ( ! F_16 ( V_6 ) )
continue;
V_48 = F_72 ( V_45 , V_41 , V_6 ) ;
if ( V_48 ) {
F_90 ( V_81 , V_20 ) ;
break;
}
V_97 ++ ;
F_80 ( V_6 ) ;
} while ( ( V_6 = V_6 -> V_34 ) != V_22 );
if ( V_48 ) {
do {
F_17 ( V_6 ) ;
V_6 = V_6 -> V_34 ;
} while ( V_6 != V_22 );
}
F_91 ( V_20 ) ;
if ( ! V_97 )
F_20 ( V_20 ) ;
return V_48 ;
}
