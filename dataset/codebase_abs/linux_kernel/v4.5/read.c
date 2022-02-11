static struct V_1 * F_1 ( void )
{
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
F_4 ( V_2 , V_4 ) ;
}
static
int F_5 ( struct V_5 * V_5 )
{
F_6 ( V_5 , 0 , V_6 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
void F_9 ( struct V_7 * V_8 ,
struct V_9 * V_9 , bool V_10 ,
const struct V_11 * V_12 )
{
struct V_13 * V_14 = F_10 ( V_9 ) ;
const struct V_15 * V_16 = & V_17 ;
#ifdef F_11
if ( V_14 -> V_18 && ! V_10 )
V_16 = V_14 -> V_18 -> V_19 ;
#endif
F_12 ( V_8 , V_9 , V_16 , V_12 , & V_20 ,
V_14 -> V_21 , 0 ) ;
}
void F_13 ( struct V_7 * V_8 )
{
struct V_22 * V_23 ;
if ( V_8 -> V_16 && V_8 -> V_16 -> V_24 )
V_8 -> V_16 -> V_24 ( V_8 ) ;
V_8 -> V_16 = & V_17 ;
F_14 ( V_8 -> V_25 != 1 ) ;
V_23 = & V_8 -> V_26 [ 0 ] ;
V_23 -> V_27 = F_10 ( V_8 -> V_28 ) -> V_21 ;
}
static void F_15 ( struct V_29 * V_30 )
{
struct V_9 * V_9 = F_16 ( V_30 -> V_31 -> V_32 ) ;
F_17 ( L_1 , V_9 -> V_33 -> V_34 ,
( unsigned long long ) F_18 ( V_9 ) , V_30 -> V_35 ,
( long long ) F_19 ( V_30 ) ) ;
if ( F_20 ( V_30 , V_36 ) ) {
if ( F_21 ( V_30 -> V_37 ) )
F_22 ( V_9 , V_30 -> V_37 , 0 ) ;
F_8 ( V_30 -> V_37 ) ;
}
F_23 ( V_30 ) ;
}
int F_24 ( struct V_38 * V_39 , struct V_9 * V_9 ,
struct V_5 * V_5 )
{
struct V_29 * V_40 ;
unsigned int V_41 ;
struct V_7 V_8 ;
struct V_22 * V_42 ;
V_41 = F_25 ( V_5 ) ;
if ( V_41 == 0 )
return F_5 ( V_5 ) ;
V_40 = F_26 ( V_39 , V_5 , NULL , 0 , V_41 ) ;
if ( F_27 ( V_40 ) ) {
F_8 ( V_5 ) ;
return F_28 ( V_40 ) ;
}
if ( V_41 < V_6 )
F_29 ( V_5 , V_41 , V_6 ) ;
F_9 ( & V_8 , V_9 , false ,
& V_43 ) ;
if ( ! F_30 ( & V_8 , V_40 ) ) {
F_31 ( V_40 ) ;
F_15 ( V_40 ) ;
}
F_32 ( & V_8 ) ;
F_14 ( V_8 . V_25 != 1 ) ;
V_42 = & V_8 . V_26 [ 0 ] ;
F_33 ( V_9 ) -> V_44 += V_42 -> V_45 ;
return V_8 . V_46 < 0 ? V_8 . V_46 : 0 ;
}
static void F_34 ( struct V_29 * V_30 )
{
if ( F_20 ( V_30 , V_47 ) )
F_7 ( V_30 -> V_37 ) ;
}
static void F_35 ( struct V_1 * V_48 )
{
unsigned long V_49 = 0 ;
if ( F_36 ( V_50 , & V_48 -> V_51 ) )
goto V_52;
while ( ! F_37 ( & V_48 -> V_53 ) ) {
struct V_29 * V_30 = F_38 ( V_48 -> V_53 . V_54 ) ;
struct V_5 * V_5 = V_30 -> V_37 ;
unsigned long V_55 = V_30 -> V_56 ;
unsigned long V_57 = V_30 -> V_56 + V_30 -> V_35 ;
if ( F_36 ( V_58 , & V_48 -> V_51 ) ) {
if ( V_49 > V_48 -> V_59 ) {
F_29 ( V_5 , V_55 , V_57 ) ;
} else if ( V_48 -> V_59 - V_49 < V_30 -> V_35 ) {
V_55 += V_48 -> V_59 - V_49 ;
F_39 ( V_55 < V_30 -> V_56 ) ;
F_29 ( V_5 , V_55 , V_57 ) ;
}
}
V_49 += V_30 -> V_35 ;
if ( F_36 ( V_60 , & V_48 -> V_51 ) ) {
if ( V_49 <= V_48 -> V_59 )
F_34 ( V_30 ) ;
} else
F_34 ( V_30 ) ;
F_31 ( V_30 ) ;
F_15 ( V_30 ) ;
}
V_52:
V_48 -> V_61 ( V_48 ) ;
}
static void F_40 ( struct V_1 * V_48 ,
struct V_62 * V_63 ,
const struct V_64 * V_65 ,
struct V_66 * V_67 , int V_68 )
{
struct V_9 * V_9 = V_48 -> V_9 ;
int V_69 = F_41 ( V_9 ) ? V_70 : 0 ;
V_67 -> V_51 |= V_69 ;
V_65 -> V_71 ( V_48 , V_63 ) ;
}
static void
F_42 ( struct V_72 * V_73 )
{
struct V_29 * V_30 ;
while ( ! F_37 ( V_73 ) ) {
V_30 = F_38 ( V_73 -> V_54 ) ;
F_31 ( V_30 ) ;
F_15 ( V_30 ) ;
}
}
static int F_43 ( struct V_74 * V_75 ,
struct V_1 * V_48 ,
struct V_9 * V_9 )
{
int V_76 = F_44 ( V_9 ) -> F_45 ( V_75 , V_48 ) ;
if ( V_76 != 0 )
return V_76 ;
F_46 ( V_9 , V_77 , V_48 -> V_78 . V_79 ) ;
if ( V_75 -> V_80 == - V_81 ) {
F_47 ( V_82 , & F_33 ( V_9 ) -> V_51 ) ;
F_48 ( V_9 ) ;
}
return 0 ;
}
static void F_49 ( struct V_74 * V_75 ,
struct V_1 * V_48 )
{
struct V_83 * V_84 = & V_48 -> args ;
struct V_85 * V_86 = & V_48 -> V_78 ;
F_50 ( V_48 -> V_9 , V_87 ) ;
if ( V_86 -> V_79 == 0 ) {
F_51 ( V_48 , - V_88 , V_84 -> V_89 ) ;
return;
}
if ( ! V_75 -> V_90 ) {
V_48 -> V_91 = - V_92 ;
return;
}
V_48 -> V_93 += V_86 -> V_79 ;
V_84 -> V_89 += V_86 -> V_79 ;
V_84 -> V_94 += V_86 -> V_79 ;
V_84 -> V_79 -= V_86 -> V_79 ;
F_52 ( V_75 ) ;
}
static void F_53 ( struct V_74 * V_75 ,
struct V_1 * V_48 )
{
if ( V_48 -> V_78 . V_95 ) {
T_1 V_96 ;
V_96 = V_48 -> args . V_89 + V_48 -> V_78 . V_79 ;
F_54 ( & V_48 -> V_97 ) ;
if ( V_96 < V_48 -> V_98 + V_48 -> V_59 ) {
F_47 ( V_58 , & V_48 -> V_51 ) ;
F_55 ( V_60 , & V_48 -> V_51 ) ;
V_48 -> V_59 = V_96 - V_48 -> V_98 ;
}
F_56 ( & V_48 -> V_97 ) ;
} else if ( V_48 -> V_78 . V_79 < V_48 -> args . V_79 )
F_49 ( V_75 , V_48 ) ;
}
int F_57 ( struct V_99 * V_99 , struct V_5 * V_5 )
{
struct V_38 * V_39 ;
struct V_9 * V_9 = F_58 ( V_5 ) -> V_100 ;
int error ;
F_17 ( L_2 ,
V_5 , V_6 , F_59 ( V_5 ) ) ;
F_50 ( V_9 , V_101 ) ;
F_46 ( V_9 , V_102 , 1 ) ;
error = F_60 ( V_9 , V_5 ) ;
if ( error )
goto V_103;
if ( F_21 ( V_5 ) )
goto V_103;
error = - V_81 ;
if ( F_61 ( V_9 ) )
goto V_103;
if ( V_99 == NULL ) {
error = - V_104 ;
V_39 = F_62 ( V_9 , NULL , V_105 ) ;
if ( V_39 == NULL )
goto V_103;
} else
V_39 = F_63 ( F_64 ( V_99 ) ) ;
if ( ! F_65 ( V_9 ) ) {
error = F_66 ( V_39 , V_9 , V_5 ) ;
if ( error == 0 )
goto V_52;
}
error = F_24 ( V_39 , V_9 , V_5 ) ;
V_52:
F_67 ( V_39 ) ;
return error ;
V_103:
F_8 ( V_5 ) ;
return error ;
}
static int
F_68 ( void * V_106 , struct V_5 * V_5 )
{
struct V_107 * V_108 = (struct V_107 * ) V_106 ;
struct V_29 * V_40 ;
unsigned int V_41 ;
int error ;
V_41 = F_25 ( V_5 ) ;
if ( V_41 == 0 )
return F_5 ( V_5 ) ;
V_40 = F_26 ( V_108 -> V_39 , V_5 , NULL , 0 , V_41 ) ;
if ( F_27 ( V_40 ) )
goto V_109;
if ( V_41 < V_6 )
F_29 ( V_5 , V_41 , V_6 ) ;
if ( ! F_30 ( V_108 -> V_8 , V_40 ) ) {
F_31 ( V_40 ) ;
F_15 ( V_40 ) ;
error = V_108 -> V_8 -> V_46 ;
goto V_103;
}
return 0 ;
V_109:
error = F_28 ( V_40 ) ;
V_103:
F_8 ( V_5 ) ;
return error ;
}
int F_69 ( struct V_99 * V_110 , struct V_111 * V_112 ,
struct V_72 * V_53 , unsigned V_113 )
{
struct V_7 V_8 ;
struct V_22 * V_42 ;
struct V_107 V_108 = {
. V_8 = & V_8 ,
} ;
struct V_9 * V_9 = V_112 -> V_100 ;
unsigned long V_114 ;
int V_115 = - V_81 ;
F_17 ( L_3 ,
V_9 -> V_33 -> V_34 ,
( unsigned long long ) F_18 ( V_9 ) ,
V_113 ) ;
F_50 ( V_9 , V_116 ) ;
if ( F_61 ( V_9 ) )
goto V_52;
if ( V_110 == NULL ) {
V_108 . V_39 = F_62 ( V_9 , NULL , V_105 ) ;
if ( V_108 . V_39 == NULL )
return - V_104 ;
} else
V_108 . V_39 = F_63 ( F_64 ( V_110 ) ) ;
V_115 = F_70 ( V_108 . V_39 , V_9 , V_112 ,
V_53 , & V_113 ) ;
if ( V_115 == 0 )
goto V_117;
F_9 ( & V_8 , V_9 , false ,
& V_43 ) ;
V_115 = F_71 ( V_112 , V_53 , F_68 , & V_108 ) ;
F_32 ( & V_8 ) ;
F_14 ( V_8 . V_25 != 1 ) ;
V_42 = & V_8 . V_26 [ 0 ] ;
F_33 ( V_9 ) -> V_44 += V_42 -> V_45 ;
V_114 = ( V_42 -> V_45 + V_6 - 1 ) >>
V_118 ;
F_46 ( V_9 , V_102 , V_114 ) ;
V_117:
F_67 ( V_108 . V_39 ) ;
V_52:
return V_115 ;
}
int T_2 F_72 ( void )
{
V_2 = F_73 ( L_4 ,
sizeof( struct V_1 ) ,
0 , V_119 ,
NULL ) ;
if ( V_2 == NULL )
return - V_120 ;
return 0 ;
}
void F_74 ( void )
{
F_75 ( V_2 ) ;
}
