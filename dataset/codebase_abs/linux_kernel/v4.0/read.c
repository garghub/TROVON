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
V_8 -> V_16 = & V_17 ;
F_14 ( V_8 -> V_24 != 1 ) ;
V_23 = & V_8 -> V_25 [ 0 ] ;
V_23 -> V_26 = F_10 ( V_8 -> V_27 ) -> V_21 ;
}
int F_15 ( struct V_28 * V_29 , struct V_9 * V_9 ,
struct V_5 * V_5 )
{
struct V_30 * V_31 ;
unsigned int V_32 ;
struct V_7 V_8 ;
struct V_22 * V_33 ;
V_32 = F_16 ( V_5 ) ;
if ( V_32 == 0 )
return F_5 ( V_5 ) ;
V_31 = F_17 ( V_29 , V_5 , NULL , 0 , V_32 ) ;
if ( F_18 ( V_31 ) ) {
F_8 ( V_5 ) ;
return F_19 ( V_31 ) ;
}
if ( V_32 < V_6 )
F_20 ( V_5 , V_32 , V_6 ) ;
F_9 ( & V_8 , V_9 , false ,
& V_34 ) ;
F_21 ( & V_8 , V_31 ) ;
F_22 ( & V_8 ) ;
F_14 ( V_8 . V_24 != 1 ) ;
V_33 = & V_8 . V_25 [ 0 ] ;
F_23 ( V_9 ) -> V_35 += V_33 -> V_36 ;
return 0 ;
}
static void F_24 ( struct V_30 * V_37 )
{
struct V_9 * V_38 = V_37 -> V_39 -> V_40 -> V_38 ;
F_25 ( L_1 , V_38 -> V_41 -> V_42 ,
( unsigned long long ) F_26 ( V_38 ) , V_37 -> V_43 ,
( long long ) F_27 ( V_37 ) ) ;
if ( F_28 ( V_37 , V_44 ) ) {
if ( F_29 ( V_37 -> V_45 ) )
F_30 ( V_38 , V_37 -> V_45 , 0 ) ;
F_8 ( V_37 -> V_45 ) ;
}
F_31 ( V_37 ) ;
}
static void F_32 ( struct V_30 * V_37 )
{
if ( F_28 ( V_37 , V_46 ) )
F_7 ( V_37 -> V_45 ) ;
}
static void F_33 ( struct V_1 * V_47 )
{
unsigned long V_48 = 0 ;
if ( F_34 ( V_49 , & V_47 -> V_50 ) )
goto V_51;
while ( ! F_35 ( & V_47 -> V_52 ) ) {
struct V_30 * V_37 = F_36 ( V_47 -> V_52 . V_53 ) ;
struct V_5 * V_5 = V_37 -> V_45 ;
unsigned long V_54 = V_37 -> V_55 ;
unsigned long V_56 = V_37 -> V_55 + V_37 -> V_43 ;
if ( F_34 ( V_57 , & V_47 -> V_50 ) ) {
if ( V_48 > V_47 -> V_58 ) {
F_20 ( V_5 , V_54 , V_56 ) ;
} else if ( V_47 -> V_58 - V_48 < V_37 -> V_43 ) {
V_54 += V_47 -> V_58 - V_48 ;
F_37 ( V_54 < V_37 -> V_55 ) ;
F_20 ( V_5 , V_54 , V_56 ) ;
}
}
V_48 += V_37 -> V_43 ;
if ( F_34 ( V_59 , & V_47 -> V_50 ) ) {
if ( V_48 <= V_47 -> V_58 )
F_32 ( V_37 ) ;
} else
F_32 ( V_37 ) ;
F_38 ( V_37 ) ;
F_24 ( V_37 ) ;
}
V_51:
V_47 -> V_60 ( V_47 ) ;
}
static void F_39 ( struct V_1 * V_47 ,
struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_65 * V_66 , int V_67 )
{
struct V_9 * V_9 = V_47 -> V_9 ;
int V_68 = F_40 ( V_9 ) ? V_69 : 0 ;
V_66 -> V_50 |= V_68 ;
V_64 -> V_70 ( V_47 , V_62 ) ;
}
static void
F_41 ( struct V_71 * V_72 )
{
struct V_30 * V_37 ;
while ( ! F_35 ( V_72 ) ) {
V_37 = F_36 ( V_72 -> V_53 ) ;
F_38 ( V_37 ) ;
F_24 ( V_37 ) ;
}
}
static int F_42 ( struct V_73 * V_74 ,
struct V_1 * V_47 ,
struct V_9 * V_9 )
{
int V_75 = F_43 ( V_9 ) -> F_44 ( V_74 , V_47 ) ;
if ( V_75 != 0 )
return V_75 ;
F_45 ( V_9 , V_76 , V_47 -> V_77 . V_78 ) ;
if ( V_74 -> V_79 == - V_80 ) {
F_46 ( V_81 , & F_23 ( V_9 ) -> V_50 ) ;
F_47 ( V_9 ) ;
}
return 0 ;
}
static void F_48 ( struct V_73 * V_74 ,
struct V_1 * V_47 )
{
struct V_82 * V_83 = & V_47 -> args ;
struct V_84 * V_85 = & V_47 -> V_77 ;
F_49 ( V_47 -> V_9 , V_86 ) ;
if ( V_85 -> V_78 == 0 ) {
F_50 ( V_47 , - V_87 , V_83 -> V_88 ) ;
return;
}
V_47 -> V_89 += V_85 -> V_78 ;
V_83 -> V_88 += V_85 -> V_78 ;
V_83 -> V_90 += V_85 -> V_78 ;
V_83 -> V_78 -= V_85 -> V_78 ;
F_51 ( V_74 ) ;
}
static void F_52 ( struct V_73 * V_74 ,
struct V_1 * V_47 )
{
if ( V_47 -> V_77 . V_91 ) {
T_1 V_92 ;
V_92 = V_47 -> args . V_88 + V_47 -> V_77 . V_78 ;
F_53 ( & V_47 -> V_93 ) ;
if ( V_92 < V_47 -> V_94 + V_47 -> V_58 ) {
F_46 ( V_57 , & V_47 -> V_50 ) ;
F_54 ( V_59 , & V_47 -> V_50 ) ;
V_47 -> V_58 = V_92 - V_47 -> V_94 ;
}
F_55 ( & V_47 -> V_93 ) ;
} else if ( V_47 -> V_77 . V_78 != V_47 -> args . V_78 )
F_48 ( V_74 , V_47 ) ;
}
int F_56 ( struct V_95 * V_95 , struct V_5 * V_5 )
{
struct V_28 * V_29 ;
struct V_9 * V_9 = F_57 ( V_5 ) -> V_96 ;
int error ;
F_25 ( L_2 ,
V_5 , V_6 , F_58 ( V_5 ) ) ;
F_49 ( V_9 , V_97 ) ;
F_49 ( V_9 , V_98 ) ;
error = F_59 ( V_9 , V_5 ) ;
if ( error )
goto V_99;
if ( F_29 ( V_5 ) )
goto V_99;
error = - V_80 ;
if ( F_60 ( V_9 ) )
goto V_99;
if ( V_95 == NULL ) {
error = - V_100 ;
V_29 = F_61 ( V_9 , NULL , V_101 ) ;
if ( V_29 == NULL )
goto V_99;
} else
V_29 = F_62 ( F_63 ( V_95 ) ) ;
if ( ! F_64 ( V_9 ) ) {
error = F_65 ( V_29 , V_9 , V_5 ) ;
if ( error == 0 )
goto V_51;
}
error = F_15 ( V_29 , V_9 , V_5 ) ;
V_51:
F_66 ( V_29 ) ;
return error ;
V_99:
F_8 ( V_5 ) ;
return error ;
}
static int
F_67 ( void * V_102 , struct V_5 * V_5 )
{
struct V_103 * V_104 = (struct V_103 * ) V_102 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
int error ;
V_32 = F_16 ( V_5 ) ;
if ( V_32 == 0 )
return F_5 ( V_5 ) ;
V_31 = F_17 ( V_104 -> V_29 , V_5 , NULL , 0 , V_32 ) ;
if ( F_18 ( V_31 ) )
goto V_105;
if ( V_32 < V_6 )
F_20 ( V_5 , V_32 , V_6 ) ;
if ( ! F_21 ( V_104 -> V_8 , V_31 ) ) {
error = V_104 -> V_8 -> V_106 ;
goto V_99;
}
return 0 ;
V_105:
error = F_19 ( V_31 ) ;
V_99:
F_8 ( V_5 ) ;
return error ;
}
int F_68 ( struct V_95 * V_107 , struct V_108 * V_109 ,
struct V_71 * V_52 , unsigned V_110 )
{
struct V_7 V_8 ;
struct V_22 * V_33 ;
struct V_103 V_104 = {
. V_8 = & V_8 ,
} ;
struct V_9 * V_9 = V_109 -> V_96 ;
unsigned long V_111 ;
int V_112 = - V_80 ;
F_25 ( L_3 ,
V_9 -> V_41 -> V_42 ,
( unsigned long long ) F_26 ( V_9 ) ,
V_110 ) ;
F_49 ( V_9 , V_113 ) ;
if ( F_60 ( V_9 ) )
goto V_51;
if ( V_107 == NULL ) {
V_104 . V_29 = F_61 ( V_9 , NULL , V_101 ) ;
if ( V_104 . V_29 == NULL )
return - V_100 ;
} else
V_104 . V_29 = F_62 ( F_63 ( V_107 ) ) ;
V_112 = F_69 ( V_104 . V_29 , V_9 , V_109 ,
V_52 , & V_110 ) ;
if ( V_112 == 0 )
goto V_114;
F_9 ( & V_8 , V_9 , false ,
& V_34 ) ;
V_112 = F_70 ( V_109 , V_52 , F_67 , & V_104 ) ;
F_22 ( & V_8 ) ;
F_14 ( V_8 . V_24 != 1 ) ;
V_33 = & V_8 . V_25 [ 0 ] ;
F_23 ( V_9 ) -> V_35 += V_33 -> V_36 ;
V_111 = ( V_33 -> V_36 + V_6 - 1 ) >>
V_115 ;
F_45 ( V_9 , V_98 , V_111 ) ;
V_114:
F_66 ( V_104 . V_29 ) ;
V_51:
return V_112 ;
}
int T_2 F_71 ( void )
{
V_2 = F_72 ( L_4 ,
sizeof( struct V_1 ) ,
0 , V_116 ,
NULL ) ;
if ( V_2 == NULL )
return - V_117 ;
return 0 ;
}
void F_73 ( void )
{
F_74 ( V_2 ) ;
}
