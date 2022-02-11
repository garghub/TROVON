static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 )
V_2 -> V_5 = V_6 ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_7 )
{
F_4 ( V_3 , V_7 ) ;
}
static
int F_5 ( struct V_8 * V_8 )
{
F_6 ( V_8 , 0 , V_9 ) ;
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
void F_9 ( struct V_10 * V_11 ,
struct V_12 * V_12 , bool V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
const struct V_18 * V_19 = & V_20 ;
#ifdef F_11
if ( V_17 -> V_21 && ! V_13 )
V_19 = V_17 -> V_21 -> V_22 ;
#endif
F_12 ( V_11 , V_12 , V_19 , V_15 , & V_23 ,
V_17 -> V_24 , 0 , V_4 ) ;
}
void F_13 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
if ( V_11 -> V_19 && V_11 -> V_19 -> V_27 )
V_11 -> V_19 -> V_27 ( V_11 ) ;
V_11 -> V_19 = & V_20 ;
F_14 ( V_11 -> V_28 != 1 ) ;
V_26 = & V_11 -> V_29 [ 0 ] ;
V_26 -> V_30 = F_10 ( V_11 -> V_31 ) -> V_24 ;
}
static void F_15 ( struct V_32 * V_33 )
{
struct V_12 * V_12 = F_16 ( V_33 -> V_34 -> V_35 ) ;
F_17 ( L_1 , V_12 -> V_36 -> V_37 ,
( unsigned long long ) F_18 ( V_12 ) , V_33 -> V_38 ,
( long long ) F_19 ( V_33 ) ) ;
if ( F_20 ( V_33 , V_39 ) ) {
if ( F_21 ( V_33 -> V_40 ) )
F_22 ( V_12 , V_33 -> V_40 , 0 ) ;
F_8 ( V_33 -> V_40 ) ;
}
F_23 ( V_33 ) ;
}
int F_24 ( struct V_41 * V_42 , struct V_12 * V_12 ,
struct V_8 * V_8 )
{
struct V_32 * V_43 ;
unsigned int V_44 ;
struct V_10 V_11 ;
struct V_25 * V_45 ;
V_44 = F_25 ( V_8 ) ;
if ( V_44 == 0 )
return F_5 ( V_8 ) ;
V_43 = F_26 ( V_42 , V_8 , NULL , 0 , V_44 ) ;
if ( F_27 ( V_43 ) ) {
F_8 ( V_8 ) ;
return F_28 ( V_43 ) ;
}
if ( V_44 < V_9 )
F_29 ( V_8 , V_44 , V_9 ) ;
F_9 ( & V_11 , V_12 , false ,
& V_46 ) ;
if ( ! F_30 ( & V_11 , V_43 ) ) {
F_31 ( V_43 ) ;
F_15 ( V_43 ) ;
}
F_32 ( & V_11 ) ;
F_14 ( V_11 . V_28 != 1 ) ;
V_45 = & V_11 . V_29 [ 0 ] ;
F_33 ( V_12 ) -> V_47 += V_45 -> V_48 ;
return V_11 . V_49 < 0 ? V_11 . V_49 : 0 ;
}
static void F_34 ( struct V_32 * V_33 )
{
if ( F_20 ( V_33 , V_50 ) )
F_7 ( V_33 -> V_40 ) ;
}
static void F_35 ( struct V_1 * V_51 )
{
unsigned long V_52 = 0 ;
if ( F_36 ( V_53 , & V_51 -> V_54 ) )
goto V_55;
while ( ! F_37 ( & V_51 -> V_56 ) ) {
struct V_32 * V_33 = F_38 ( V_51 -> V_56 . V_57 ) ;
struct V_8 * V_8 = V_33 -> V_40 ;
unsigned long V_58 = V_33 -> V_59 ;
unsigned long V_60 = V_33 -> V_59 + V_33 -> V_38 ;
if ( F_36 ( V_61 , & V_51 -> V_54 ) ) {
if ( V_52 > V_51 -> V_62 ) {
F_29 ( V_8 , V_58 , V_60 ) ;
} else if ( V_51 -> V_62 - V_52 < V_33 -> V_38 ) {
V_58 += V_51 -> V_62 - V_52 ;
F_39 ( V_58 < V_33 -> V_59 ) ;
F_29 ( V_8 , V_58 , V_60 ) ;
}
}
V_52 += V_33 -> V_38 ;
if ( F_36 ( V_63 , & V_51 -> V_54 ) ) {
if ( V_52 <= V_51 -> V_62 )
F_34 ( V_33 ) ;
} else
F_34 ( V_33 ) ;
F_31 ( V_33 ) ;
F_15 ( V_33 ) ;
}
V_55:
V_51 -> V_64 ( V_51 ) ;
}
static void F_40 ( struct V_1 * V_51 ,
struct V_65 * V_66 ,
const struct V_67 * V_68 ,
struct V_69 * V_70 , int V_71 )
{
struct V_12 * V_12 = V_51 -> V_12 ;
int V_72 = F_41 ( V_12 ) ? V_73 : 0 ;
V_70 -> V_54 |= V_72 ;
V_68 -> V_74 ( V_51 , V_66 ) ;
}
static void
F_42 ( struct V_75 * V_76 )
{
struct V_32 * V_33 ;
while ( ! F_37 ( V_76 ) ) {
V_33 = F_38 ( V_76 -> V_57 ) ;
F_31 ( V_33 ) ;
F_15 ( V_33 ) ;
}
}
static int F_43 ( struct V_77 * V_78 ,
struct V_1 * V_51 ,
struct V_12 * V_12 )
{
int V_79 = F_44 ( V_12 ) -> F_45 ( V_78 , V_51 ) ;
if ( V_79 != 0 )
return V_79 ;
F_46 ( V_12 , V_80 , V_51 -> V_81 . V_82 ) ;
if ( V_78 -> V_83 == - V_84 ) {
F_47 ( V_85 , & F_33 ( V_12 ) -> V_54 ) ;
F_48 ( V_12 ) ;
}
return 0 ;
}
static void F_49 ( struct V_77 * V_78 ,
struct V_1 * V_51 )
{
struct V_86 * V_87 = & V_51 -> args ;
struct V_88 * V_89 = & V_51 -> V_81 ;
F_50 ( V_51 -> V_12 , V_90 ) ;
if ( V_89 -> V_82 == 0 ) {
F_51 ( V_51 , - V_91 , V_87 -> V_92 ) ;
return;
}
if ( ! V_78 -> V_93 ) {
V_51 -> V_94 = - V_95 ;
return;
}
V_51 -> V_96 += V_89 -> V_82 ;
V_87 -> V_92 += V_89 -> V_82 ;
V_87 -> V_97 += V_89 -> V_82 ;
V_87 -> V_82 -= V_89 -> V_82 ;
F_52 ( V_78 ) ;
}
static void F_53 ( struct V_77 * V_78 ,
struct V_1 * V_51 )
{
if ( V_51 -> V_81 . V_98 ) {
T_1 V_99 ;
V_99 = V_51 -> args . V_92 + V_51 -> V_81 . V_82 ;
F_54 ( & V_51 -> V_100 ) ;
if ( V_99 < V_51 -> V_101 + V_51 -> V_62 ) {
F_47 ( V_61 , & V_51 -> V_54 ) ;
F_55 ( V_63 , & V_51 -> V_54 ) ;
V_51 -> V_62 = V_99 - V_51 -> V_101 ;
}
F_56 ( & V_51 -> V_100 ) ;
} else if ( V_51 -> V_81 . V_82 < V_51 -> args . V_82 )
F_49 ( V_78 , V_51 ) ;
}
int F_57 ( struct V_102 * V_102 , struct V_8 * V_8 )
{
struct V_41 * V_42 ;
struct V_12 * V_12 = F_58 ( V_8 ) -> V_103 ;
int error ;
F_17 ( L_2 ,
V_8 , V_9 , F_59 ( V_8 ) ) ;
F_50 ( V_12 , V_104 ) ;
F_46 ( V_12 , V_105 , 1 ) ;
error = F_60 ( V_12 , V_8 ) ;
if ( error )
goto V_106;
if ( F_21 ( V_8 ) )
goto V_106;
error = - V_84 ;
if ( F_61 ( V_12 ) )
goto V_106;
if ( V_102 == NULL ) {
error = - V_107 ;
V_42 = F_62 ( V_12 , NULL , V_6 ) ;
if ( V_42 == NULL )
goto V_106;
} else
V_42 = F_63 ( F_64 ( V_102 ) ) ;
if ( ! F_65 ( V_12 ) ) {
error = F_66 ( V_42 , V_12 , V_8 ) ;
if ( error == 0 )
goto V_55;
}
error = F_24 ( V_42 , V_12 , V_8 ) ;
V_55:
F_67 ( V_42 ) ;
return error ;
V_106:
F_8 ( V_8 ) ;
return error ;
}
static int
F_68 ( void * V_108 , struct V_8 * V_8 )
{
struct V_109 * V_110 = (struct V_109 * ) V_108 ;
struct V_32 * V_43 ;
unsigned int V_44 ;
int error ;
V_44 = F_25 ( V_8 ) ;
if ( V_44 == 0 )
return F_5 ( V_8 ) ;
V_43 = F_26 ( V_110 -> V_42 , V_8 , NULL , 0 , V_44 ) ;
if ( F_27 ( V_43 ) )
goto V_111;
if ( V_44 < V_9 )
F_29 ( V_8 , V_44 , V_9 ) ;
if ( ! F_30 ( V_110 -> V_11 , V_43 ) ) {
F_31 ( V_43 ) ;
F_15 ( V_43 ) ;
error = V_110 -> V_11 -> V_49 ;
goto V_55;
}
return 0 ;
V_111:
error = F_28 ( V_43 ) ;
F_8 ( V_8 ) ;
V_55:
return error ;
}
int F_69 ( struct V_102 * V_112 , struct V_113 * V_114 ,
struct V_75 * V_56 , unsigned V_115 )
{
struct V_10 V_11 ;
struct V_25 * V_45 ;
struct V_109 V_110 = {
. V_11 = & V_11 ,
} ;
struct V_12 * V_12 = V_114 -> V_103 ;
unsigned long V_116 ;
int V_117 = - V_84 ;
F_17 ( L_3 ,
V_12 -> V_36 -> V_37 ,
( unsigned long long ) F_18 ( V_12 ) ,
V_115 ) ;
F_50 ( V_12 , V_118 ) ;
if ( F_61 ( V_12 ) )
goto V_55;
if ( V_112 == NULL ) {
V_110 . V_42 = F_62 ( V_12 , NULL , V_6 ) ;
if ( V_110 . V_42 == NULL )
return - V_107 ;
} else
V_110 . V_42 = F_63 ( F_64 ( V_112 ) ) ;
V_117 = F_70 ( V_110 . V_42 , V_12 , V_114 ,
V_56 , & V_115 ) ;
if ( V_117 == 0 )
goto V_119;
F_9 ( & V_11 , V_12 , false ,
& V_46 ) ;
V_117 = F_71 ( V_114 , V_56 , F_68 , & V_110 ) ;
F_32 ( & V_11 ) ;
F_14 ( V_11 . V_28 != 1 ) ;
V_45 = & V_11 . V_29 [ 0 ] ;
F_33 ( V_12 ) -> V_47 += V_45 -> V_48 ;
V_116 = ( V_45 -> V_48 + V_9 - 1 ) >>
V_120 ;
F_46 ( V_12 , V_105 , V_116 ) ;
V_119:
F_67 ( V_110 . V_42 ) ;
V_55:
return V_117 ;
}
int T_2 F_72 ( void )
{
V_3 = F_73 ( L_4 ,
sizeof( struct V_1 ) ,
0 , V_121 ,
NULL ) ;
if ( V_3 == NULL )
return - V_122 ;
return 0 ;
}
void F_74 ( void )
{
F_75 ( V_3 ) ;
}
