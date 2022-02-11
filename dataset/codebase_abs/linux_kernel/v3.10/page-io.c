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
void F_5 ( struct V_5 * V_5 )
{
T_2 * V_6 = F_6 ( V_5 ) ;
F_7 ( * V_6 , ( F_8 ( & F_9 ( V_5 ) -> V_7 ) == 0 ) ) ;
if ( F_10 ( & F_9 ( V_5 ) -> V_8 ) )
F_11 ( & F_9 ( V_5 ) -> V_8 ) ;
}
void F_12 ( T_3 * V_9 )
{
F_13 ( ! V_9 ) ;
F_13 ( ! F_14 ( & V_9 -> V_10 ) ) ;
F_13 ( V_9 -> V_11 & V_12 ) ;
if ( F_15 ( & F_9 ( V_9 -> V_5 ) -> V_7 ) )
F_16 ( F_6 ( V_9 -> V_5 ) ) ;
F_17 ( V_1 , V_9 ) ;
}
static int F_18 ( T_3 * V_9 )
{
struct V_5 * V_5 = V_9 -> V_5 ;
T_4 V_13 = V_9 -> V_13 ;
T_5 V_14 = V_9 -> V_14 ;
int V_15 = 0 ;
F_19 ( L_1
L_2 ,
V_9 , V_5 -> V_16 , V_9 -> V_10 . V_17 , V_9 -> V_10 . V_18 ) ;
V_15 = F_20 ( V_5 , V_13 , V_14 ) ;
if ( V_15 < 0 ) {
F_21 ( V_5 -> V_19 , V_20 ,
L_3
L_4
L_5 ,
V_5 -> V_16 , V_13 , V_14 , V_15 ) ;
}
if ( F_15 ( & F_9 ( V_5 ) -> V_21 ) )
F_16 ( F_6 ( V_5 ) ) ;
if ( V_9 -> V_11 & V_22 )
F_22 ( V_5 ) ;
if ( V_9 -> V_23 )
F_23 ( V_9 -> V_23 , V_9 -> V_24 , 0 ) ;
return V_15 ;
}
static void F_24 ( struct V_5 * V_5 )
{
#ifdef F_25
struct V_25 * V_26 , * V_27 , * V_28 ;
T_3 * V_9 , * V_29 , * V_30 ;
if ( F_14 ( & F_9 ( V_5 ) -> V_31 ) ) {
F_19 ( L_6 ,
V_5 -> V_16 ) ;
return;
}
F_19 ( L_7 , V_5 -> V_16 ) ;
F_26 (io, &EXT4_I(inode)->i_completed_io_list, list) {
V_26 = & V_9 -> V_10 ;
V_27 = V_26 -> V_18 ;
V_29 = F_27 ( V_27 , T_3 , V_10 ) ;
V_28 = V_26 -> V_17 ;
V_30 = F_27 ( V_28 , T_3 , V_10 ) ;
F_19 ( L_8 ,
V_9 , V_5 -> V_16 , V_29 , V_30 ) ;
}
#endif
}
void F_28 ( T_3 * V_32 )
{
struct V_33 * V_34 = F_9 ( V_32 -> V_5 ) ;
struct V_35 * V_6 ;
unsigned long V_36 ;
F_13 ( ! ( V_32 -> V_11 & V_12 ) ) ;
V_6 = F_29 ( V_32 -> V_5 -> V_19 ) -> V_37 ;
F_30 ( & V_34 -> V_38 , V_36 ) ;
if ( F_14 ( & V_34 -> V_31 ) )
F_31 ( V_6 , & V_34 -> V_8 ) ;
F_32 ( & V_32 -> V_10 , & V_34 -> V_31 ) ;
F_33 ( & V_34 -> V_38 , V_36 ) ;
}
static int F_34 ( struct V_5 * V_5 )
{
T_3 * V_9 ;
struct V_25 V_39 ;
unsigned long V_36 ;
struct V_33 * V_34 = F_9 ( V_5 ) ;
int V_40 , V_15 = 0 ;
F_30 ( & V_34 -> V_38 , V_36 ) ;
F_24 ( V_5 ) ;
F_35 ( & V_34 -> V_31 , & V_39 ) ;
F_33 ( & V_34 -> V_38 , V_36 ) ;
while ( ! F_14 ( & V_39 ) ) {
V_9 = F_36 ( V_39 . V_17 , T_3 , V_10 ) ;
F_13 ( ! ( V_9 -> V_11 & V_12 ) ) ;
F_37 ( & V_9 -> V_10 ) ;
V_40 = F_18 ( V_9 ) ;
if ( F_38 ( ! V_15 && V_40 ) )
V_15 = V_40 ;
V_9 -> V_11 &= ~ V_12 ;
F_12 ( V_9 ) ;
}
return V_15 ;
}
void F_39 ( struct V_41 * V_42 )
{
struct V_33 * V_34 = F_27 ( V_42 , struct V_33 ,
V_8 ) ;
F_34 ( & V_34 -> V_43 ) ;
}
int F_40 ( struct V_5 * V_5 )
{
int V_15 ;
F_41 ( ! F_42 ( & V_5 -> V_44 ) &&
! ( V_5 -> V_45 & V_46 ) ) ;
V_15 = F_34 ( V_5 ) ;
F_43 ( V_5 ) ;
return V_15 ;
}
T_3 * F_44 ( struct V_5 * V_5 , T_6 V_36 )
{
T_3 * V_9 = F_45 ( V_1 , V_36 ) ;
if ( V_9 ) {
F_46 ( & F_9 ( V_5 ) -> V_7 ) ;
V_9 -> V_5 = V_5 ;
F_47 ( & V_9 -> V_10 ) ;
}
return V_9 ;
}
static void F_48 ( struct V_47 * V_48 )
{
char V_49 [ V_50 ] ;
F_49 ( V_51 L_9 ,
F_50 ( V_48 -> V_52 , V_49 ) ,
( unsigned long long ) V_48 -> V_53 ) ;
}
static void F_51 ( struct V_54 * V_54 , int error )
{
T_3 * V_32 = V_54 -> V_55 ;
struct V_5 * V_5 ;
int V_56 ;
int V_57 ;
T_7 V_58 = V_54 -> V_58 ;
F_13 ( ! V_32 ) ;
V_5 = V_32 -> V_5 ;
V_57 = 1 << V_5 -> V_59 ;
V_54 -> V_55 = NULL ;
V_54 -> V_60 = NULL ;
if ( F_52 ( V_61 , & V_54 -> V_62 ) )
error = 0 ;
for ( V_56 = 0 ; V_56 < V_54 -> V_63 ; V_56 ++ ) {
struct V_64 * V_65 = & V_54 -> V_66 [ V_56 ] ;
struct V_67 * V_67 = V_65 -> V_68 ;
struct V_47 * V_48 , * V_69 ;
unsigned V_70 = V_65 -> V_71 ;
unsigned V_72 = V_70 + V_65 -> V_73 ;
unsigned V_74 = 0 ;
unsigned long V_36 ;
if ( ! V_67 )
continue;
if ( error ) {
F_53 ( V_67 ) ;
F_54 ( V_75 , & V_67 -> V_76 -> V_36 ) ;
}
V_48 = V_69 = F_55 ( V_67 ) ;
F_56 ( V_36 ) ;
F_57 ( V_77 , & V_69 -> V_78 ) ;
do {
if ( F_58 ( V_48 ) < V_70 ||
F_58 ( V_48 ) + V_57 > V_72 ) {
if ( F_59 ( V_48 ) )
V_74 ++ ;
continue;
}
F_60 ( V_48 ) ;
if ( error )
F_48 ( V_48 ) ;
} while ( ( V_48 = V_48 -> V_79 ) != V_69 );
F_61 ( V_77 , & V_69 -> V_78 ) ;
F_62 ( V_36 ) ;
if ( ! V_74 )
F_63 ( V_67 ) ;
}
F_64 ( V_54 ) ;
if ( error ) {
V_32 -> V_11 |= V_80 ;
F_65 ( V_5 -> V_19 , L_10
L_11 ,
V_5 -> V_16 ,
( unsigned long long ) V_32 -> V_13 ,
( long ) V_32 -> V_14 ,
( unsigned long long )
V_58 >> ( V_5 -> V_59 - 9 ) ) ;
}
if ( ! ( V_32 -> V_11 & V_12 ) ) {
F_12 ( V_32 ) ;
return;
}
F_28 ( V_32 ) ;
}
void F_66 ( struct F_66 * V_9 )
{
struct V_54 * V_54 = V_9 -> V_81 ;
if ( V_54 ) {
F_67 ( V_9 -> V_81 ) ;
F_68 ( V_9 -> V_82 , V_9 -> V_81 ) ;
F_13 ( F_69 ( V_9 -> V_81 , V_83 ) ) ;
F_64 ( V_9 -> V_81 ) ;
}
V_9 -> V_81 = NULL ;
V_9 -> V_82 = 0 ;
V_9 -> V_32 = NULL ;
}
static int F_70 ( struct F_66 * V_9 ,
struct V_5 * V_5 ,
struct V_84 * V_85 ,
struct V_47 * V_48 )
{
T_3 * V_32 ;
struct V_67 * V_67 = V_48 -> V_86 ;
int V_87 = F_71 ( V_48 -> V_52 ) ;
struct V_54 * V_54 ;
V_32 = F_44 ( V_5 , V_88 ) ;
if ( ! V_32 )
return - V_4 ;
V_54 = F_72 ( V_89 , F_73 ( V_87 , V_90 ) ) ;
V_54 -> V_58 = V_48 -> V_53 * ( V_48 -> V_91 >> 9 ) ;
V_54 -> V_92 = V_48 -> V_52 ;
V_54 -> V_55 = V_9 -> V_32 = V_32 ;
V_54 -> V_60 = F_51 ;
V_32 -> V_13 = ( V_67 -> V_93 << V_94 ) + F_58 ( V_48 ) ;
V_9 -> V_81 = V_54 ;
V_9 -> V_82 = ( V_85 -> V_95 == V_96 ? V_97 : V_98 ) ;
V_9 -> V_99 = V_48 -> V_53 ;
return 0 ;
}
static int F_74 ( struct F_66 * V_9 ,
struct V_5 * V_5 ,
struct V_84 * V_85 ,
struct V_47 * V_48 )
{
T_3 * V_32 ;
int V_15 ;
if ( V_9 -> V_81 && V_48 -> V_53 != V_9 -> V_99 ) {
V_100:
F_66 ( V_9 ) ;
}
if ( V_9 -> V_81 == NULL ) {
V_15 = F_70 ( V_9 , V_5 , V_85 , V_48 ) ;
if ( V_15 )
return V_15 ;
}
V_32 = V_9 -> V_32 ;
if ( F_75 ( V_48 ) )
F_76 ( V_5 , V_32 ) ;
V_9 -> V_32 -> V_14 += V_48 -> V_91 ;
V_9 -> V_99 ++ ;
V_15 = F_77 ( V_9 -> V_81 , V_48 -> V_86 , V_48 -> V_91 , F_58 ( V_48 ) ) ;
if ( V_15 != V_48 -> V_91 )
goto V_100;
return 0 ;
}
int F_78 ( struct F_66 * V_9 ,
struct V_67 * V_67 ,
int V_101 ,
struct V_84 * V_85 )
{
struct V_5 * V_5 = V_67 -> V_76 -> V_102 ;
unsigned V_103 , V_57 ;
struct V_47 * V_48 , * V_69 ;
int V_15 = 0 ;
int V_104 = 0 ;
V_57 = 1 << V_5 -> V_59 ;
F_13 ( ! F_79 ( V_67 ) ) ;
F_13 ( F_80 ( V_67 ) ) ;
F_81 ( V_67 ) ;
F_82 ( V_67 ) ;
V_48 = V_69 = F_55 ( V_67 ) ;
do {
V_103 = F_58 ( V_48 ) ;
if ( V_103 >= V_101 ) {
F_83 ( V_67 , V_103 ,
V_103 + V_57 ) ;
F_84 ( V_48 ) ;
F_85 ( V_48 ) ;
continue;
}
if ( ! F_86 ( V_48 ) || F_87 ( V_48 ) ||
! F_88 ( V_48 ) || F_89 ( V_48 ) ) {
if ( ! F_88 ( V_48 ) )
F_84 ( V_48 ) ;
if ( V_9 -> V_81 )
F_66 ( V_9 ) ;
continue;
}
if ( F_90 ( V_48 ) ) {
F_91 ( V_48 ) ;
F_92 ( V_48 -> V_52 , V_48 -> V_53 ) ;
}
F_93 ( V_48 ) ;
} while ( ( V_48 = V_48 -> V_79 ) != V_69 );
V_48 = V_69 = F_55 ( V_67 ) ;
do {
if ( ! F_59 ( V_48 ) )
continue;
V_15 = F_74 ( V_9 , V_5 , V_85 , V_48 ) ;
if ( V_15 ) {
F_94 ( V_85 , V_67 ) ;
break;
}
V_104 ++ ;
F_84 ( V_48 ) ;
} while ( ( V_48 = V_48 -> V_79 ) != V_69 );
if ( V_15 ) {
do {
F_60 ( V_48 ) ;
V_48 = V_48 -> V_79 ;
} while ( V_48 != V_69 );
}
F_95 ( V_67 ) ;
if ( ! V_104 )
F_63 ( V_67 ) ;
return V_15 ;
}
