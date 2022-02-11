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
struct V_9 * V_9 = F_25 ( V_37 -> V_38 -> V_39 ) ;
F_26 ( L_1 , V_9 -> V_40 -> V_41 ,
( unsigned long long ) F_27 ( V_9 ) , V_37 -> V_42 ,
( long long ) F_28 ( V_37 ) ) ;
if ( F_29 ( V_37 , V_43 ) ) {
if ( F_30 ( V_37 -> V_44 ) )
F_31 ( V_9 , V_37 -> V_44 , 0 ) ;
F_8 ( V_37 -> V_44 ) ;
}
F_32 ( V_37 ) ;
}
static void F_33 ( struct V_30 * V_37 )
{
if ( F_29 ( V_37 , V_45 ) )
F_7 ( V_37 -> V_44 ) ;
}
static void F_34 ( struct V_1 * V_46 )
{
unsigned long V_47 = 0 ;
if ( F_35 ( V_48 , & V_46 -> V_49 ) )
goto V_50;
while ( ! F_36 ( & V_46 -> V_51 ) ) {
struct V_30 * V_37 = F_37 ( V_46 -> V_51 . V_52 ) ;
struct V_5 * V_5 = V_37 -> V_44 ;
unsigned long V_53 = V_37 -> V_54 ;
unsigned long V_55 = V_37 -> V_54 + V_37 -> V_42 ;
if ( F_35 ( V_56 , & V_46 -> V_49 ) ) {
if ( V_47 > V_46 -> V_57 ) {
F_20 ( V_5 , V_53 , V_55 ) ;
} else if ( V_46 -> V_57 - V_47 < V_37 -> V_42 ) {
V_53 += V_46 -> V_57 - V_47 ;
F_38 ( V_53 < V_37 -> V_54 ) ;
F_20 ( V_5 , V_53 , V_55 ) ;
}
}
V_47 += V_37 -> V_42 ;
if ( F_35 ( V_58 , & V_46 -> V_49 ) ) {
if ( V_47 <= V_46 -> V_57 )
F_33 ( V_37 ) ;
} else
F_33 ( V_37 ) ;
F_39 ( V_37 ) ;
F_24 ( V_37 ) ;
}
V_50:
V_46 -> V_59 ( V_46 ) ;
}
static void F_40 ( struct V_1 * V_46 ,
struct V_60 * V_61 ,
const struct V_62 * V_63 ,
struct V_64 * V_65 , int V_66 )
{
struct V_9 * V_9 = V_46 -> V_9 ;
int V_67 = F_41 ( V_9 ) ? V_68 : 0 ;
V_65 -> V_49 |= V_67 ;
V_63 -> V_69 ( V_46 , V_61 ) ;
}
static void
F_42 ( struct V_70 * V_71 )
{
struct V_30 * V_37 ;
while ( ! F_36 ( V_71 ) ) {
V_37 = F_37 ( V_71 -> V_52 ) ;
F_39 ( V_37 ) ;
F_24 ( V_37 ) ;
}
}
static int F_43 ( struct V_72 * V_73 ,
struct V_1 * V_46 ,
struct V_9 * V_9 )
{
int V_74 = F_44 ( V_9 ) -> F_45 ( V_73 , V_46 ) ;
if ( V_74 != 0 )
return V_74 ;
F_46 ( V_9 , V_75 , V_46 -> V_76 . V_77 ) ;
if ( V_73 -> V_78 == - V_79 ) {
F_47 ( V_80 , & F_23 ( V_9 ) -> V_49 ) ;
F_48 ( V_9 ) ;
}
return 0 ;
}
static void F_49 ( struct V_72 * V_73 ,
struct V_1 * V_46 )
{
struct V_81 * V_82 = & V_46 -> args ;
struct V_83 * V_84 = & V_46 -> V_76 ;
F_50 ( V_46 -> V_9 , V_85 ) ;
if ( V_84 -> V_77 == 0 ) {
F_51 ( V_46 , - V_86 , V_82 -> V_87 ) ;
return;
}
V_46 -> V_88 += V_84 -> V_77 ;
V_82 -> V_87 += V_84 -> V_77 ;
V_82 -> V_89 += V_84 -> V_77 ;
V_82 -> V_77 -= V_84 -> V_77 ;
F_52 ( V_73 ) ;
}
static void F_53 ( struct V_72 * V_73 ,
struct V_1 * V_46 )
{
if ( V_46 -> V_76 . V_90 ) {
T_1 V_91 ;
V_91 = V_46 -> args . V_87 + V_46 -> V_76 . V_77 ;
F_54 ( & V_46 -> V_92 ) ;
if ( V_91 < V_46 -> V_93 + V_46 -> V_57 ) {
F_47 ( V_56 , & V_46 -> V_49 ) ;
F_55 ( V_58 , & V_46 -> V_49 ) ;
V_46 -> V_57 = V_91 - V_46 -> V_93 ;
}
F_56 ( & V_46 -> V_92 ) ;
} else if ( V_46 -> V_76 . V_77 != V_46 -> args . V_77 )
F_49 ( V_73 , V_46 ) ;
}
int F_57 ( struct V_94 * V_94 , struct V_5 * V_5 )
{
struct V_28 * V_29 ;
struct V_9 * V_9 = F_58 ( V_5 ) -> V_95 ;
int error ;
F_26 ( L_2 ,
V_5 , V_6 , F_59 ( V_5 ) ) ;
F_50 ( V_9 , V_96 ) ;
F_46 ( V_9 , V_97 , 1 ) ;
error = F_60 ( V_9 , V_5 ) ;
if ( error )
goto V_98;
if ( F_30 ( V_5 ) )
goto V_98;
error = - V_79 ;
if ( F_61 ( V_9 ) )
goto V_98;
if ( V_94 == NULL ) {
error = - V_99 ;
V_29 = F_62 ( V_9 , NULL , V_100 ) ;
if ( V_29 == NULL )
goto V_98;
} else
V_29 = F_63 ( F_64 ( V_94 ) ) ;
if ( ! F_65 ( V_9 ) ) {
error = F_66 ( V_29 , V_9 , V_5 ) ;
if ( error == 0 )
goto V_50;
}
error = F_15 ( V_29 , V_9 , V_5 ) ;
V_50:
F_67 ( V_29 ) ;
return error ;
V_98:
F_8 ( V_5 ) ;
return error ;
}
static int
F_68 ( void * V_101 , struct V_5 * V_5 )
{
struct V_102 * V_103 = (struct V_102 * ) V_101 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
int error ;
V_32 = F_16 ( V_5 ) ;
if ( V_32 == 0 )
return F_5 ( V_5 ) ;
V_31 = F_17 ( V_103 -> V_29 , V_5 , NULL , 0 , V_32 ) ;
if ( F_18 ( V_31 ) )
goto V_104;
if ( V_32 < V_6 )
F_20 ( V_5 , V_32 , V_6 ) ;
if ( ! F_21 ( V_103 -> V_8 , V_31 ) ) {
error = V_103 -> V_8 -> V_105 ;
goto V_98;
}
return 0 ;
V_104:
error = F_19 ( V_31 ) ;
V_98:
F_8 ( V_5 ) ;
return error ;
}
int F_69 ( struct V_94 * V_106 , struct V_107 * V_108 ,
struct V_70 * V_51 , unsigned V_109 )
{
struct V_7 V_8 ;
struct V_22 * V_33 ;
struct V_102 V_103 = {
. V_8 = & V_8 ,
} ;
struct V_9 * V_9 = V_108 -> V_95 ;
unsigned long V_110 ;
int V_111 = - V_79 ;
F_26 ( L_3 ,
V_9 -> V_40 -> V_41 ,
( unsigned long long ) F_27 ( V_9 ) ,
V_109 ) ;
F_50 ( V_9 , V_112 ) ;
if ( F_61 ( V_9 ) )
goto V_50;
if ( V_106 == NULL ) {
V_103 . V_29 = F_62 ( V_9 , NULL , V_100 ) ;
if ( V_103 . V_29 == NULL )
return - V_99 ;
} else
V_103 . V_29 = F_63 ( F_64 ( V_106 ) ) ;
V_111 = F_70 ( V_103 . V_29 , V_9 , V_108 ,
V_51 , & V_109 ) ;
if ( V_111 == 0 )
goto V_113;
F_9 ( & V_8 , V_9 , false ,
& V_34 ) ;
V_111 = F_71 ( V_108 , V_51 , F_68 , & V_103 ) ;
F_22 ( & V_8 ) ;
F_14 ( V_8 . V_24 != 1 ) ;
V_33 = & V_8 . V_25 [ 0 ] ;
F_23 ( V_9 ) -> V_35 += V_33 -> V_36 ;
V_110 = ( V_33 -> V_36 + V_6 - 1 ) >>
V_114 ;
F_46 ( V_9 , V_97 , V_110 ) ;
V_113:
F_67 ( V_103 . V_29 ) ;
V_50:
return V_111 ;
}
int T_2 F_72 ( void )
{
V_2 = F_73 ( L_4 ,
sizeof( struct V_1 ) ,
0 , V_115 ,
NULL ) ;
if ( V_2 == NULL )
return - V_116 ;
return 0 ;
}
void F_74 ( void )
{
F_75 ( V_2 ) ;
}
