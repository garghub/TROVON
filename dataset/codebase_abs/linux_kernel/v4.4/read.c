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
int F_15 ( struct V_29 * V_30 , struct V_9 * V_9 ,
struct V_5 * V_5 )
{
struct V_31 * V_32 ;
unsigned int V_33 ;
struct V_7 V_8 ;
struct V_22 * V_34 ;
V_33 = F_16 ( V_5 ) ;
if ( V_33 == 0 )
return F_5 ( V_5 ) ;
V_32 = F_17 ( V_30 , V_5 , NULL , 0 , V_33 ) ;
if ( F_18 ( V_32 ) ) {
F_8 ( V_5 ) ;
return F_19 ( V_32 ) ;
}
if ( V_33 < V_6 )
F_20 ( V_5 , V_33 , V_6 ) ;
F_9 ( & V_8 , V_9 , false ,
& V_35 ) ;
F_21 ( & V_8 , V_32 ) ;
F_22 ( & V_8 ) ;
F_14 ( V_8 . V_25 != 1 ) ;
V_34 = & V_8 . V_26 [ 0 ] ;
F_23 ( V_9 ) -> V_36 += V_34 -> V_37 ;
return 0 ;
}
static void F_24 ( struct V_31 * V_38 )
{
struct V_9 * V_9 = F_25 ( V_38 -> V_39 -> V_40 ) ;
F_26 ( L_1 , V_9 -> V_41 -> V_42 ,
( unsigned long long ) F_27 ( V_9 ) , V_38 -> V_43 ,
( long long ) F_28 ( V_38 ) ) ;
if ( F_29 ( V_38 , V_44 ) ) {
if ( F_30 ( V_38 -> V_45 ) )
F_31 ( V_9 , V_38 -> V_45 , 0 ) ;
F_8 ( V_38 -> V_45 ) ;
}
F_32 ( V_38 ) ;
}
static void F_33 ( struct V_31 * V_38 )
{
if ( F_29 ( V_38 , V_46 ) )
F_7 ( V_38 -> V_45 ) ;
}
static void F_34 ( struct V_1 * V_47 )
{
unsigned long V_48 = 0 ;
if ( F_35 ( V_49 , & V_47 -> V_50 ) )
goto V_51;
while ( ! F_36 ( & V_47 -> V_52 ) ) {
struct V_31 * V_38 = F_37 ( V_47 -> V_52 . V_53 ) ;
struct V_5 * V_5 = V_38 -> V_45 ;
unsigned long V_54 = V_38 -> V_55 ;
unsigned long V_56 = V_38 -> V_55 + V_38 -> V_43 ;
if ( F_35 ( V_57 , & V_47 -> V_50 ) ) {
if ( V_48 > V_47 -> V_58 ) {
F_20 ( V_5 , V_54 , V_56 ) ;
} else if ( V_47 -> V_58 - V_48 < V_38 -> V_43 ) {
V_54 += V_47 -> V_58 - V_48 ;
F_38 ( V_54 < V_38 -> V_55 ) ;
F_20 ( V_5 , V_54 , V_56 ) ;
}
}
V_48 += V_38 -> V_43 ;
if ( F_35 ( V_59 , & V_47 -> V_50 ) ) {
if ( V_48 <= V_47 -> V_58 )
F_33 ( V_38 ) ;
} else
F_33 ( V_38 ) ;
F_39 ( V_38 ) ;
F_24 ( V_38 ) ;
}
V_51:
V_47 -> V_60 ( V_47 ) ;
}
static void F_40 ( struct V_1 * V_47 ,
struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_65 * V_66 , int V_67 )
{
struct V_9 * V_9 = V_47 -> V_9 ;
int V_68 = F_41 ( V_9 ) ? V_69 : 0 ;
V_66 -> V_50 |= V_68 ;
V_64 -> V_70 ( V_47 , V_62 ) ;
}
static void
F_42 ( struct V_71 * V_72 )
{
struct V_31 * V_38 ;
while ( ! F_36 ( V_72 ) ) {
V_38 = F_37 ( V_72 -> V_53 ) ;
F_39 ( V_38 ) ;
F_24 ( V_38 ) ;
}
}
static int F_43 ( struct V_73 * V_74 ,
struct V_1 * V_47 ,
struct V_9 * V_9 )
{
int V_75 = F_44 ( V_9 ) -> F_45 ( V_74 , V_47 ) ;
if ( V_75 != 0 )
return V_75 ;
F_46 ( V_9 , V_76 , V_47 -> V_77 . V_78 ) ;
if ( V_74 -> V_79 == - V_80 ) {
F_47 ( V_81 , & F_23 ( V_9 ) -> V_50 ) ;
F_48 ( V_9 ) ;
}
return 0 ;
}
static void F_49 ( struct V_73 * V_74 ,
struct V_1 * V_47 )
{
struct V_82 * V_83 = & V_47 -> args ;
struct V_84 * V_85 = & V_47 -> V_77 ;
F_50 ( V_47 -> V_9 , V_86 ) ;
if ( V_85 -> V_78 == 0 ) {
F_51 ( V_47 , - V_87 , V_83 -> V_88 ) ;
return;
}
if ( ! V_74 -> V_89 ) {
V_47 -> V_90 = - V_91 ;
return;
}
V_47 -> V_92 += V_85 -> V_78 ;
V_83 -> V_88 += V_85 -> V_78 ;
V_83 -> V_93 += V_85 -> V_78 ;
V_83 -> V_78 -= V_85 -> V_78 ;
F_52 ( V_74 ) ;
}
static void F_53 ( struct V_73 * V_74 ,
struct V_1 * V_47 )
{
if ( V_47 -> V_77 . V_94 ) {
T_1 V_95 ;
V_95 = V_47 -> args . V_88 + V_47 -> V_77 . V_78 ;
F_54 ( & V_47 -> V_96 ) ;
if ( V_95 < V_47 -> V_97 + V_47 -> V_58 ) {
F_47 ( V_57 , & V_47 -> V_50 ) ;
F_55 ( V_59 , & V_47 -> V_50 ) ;
V_47 -> V_58 = V_95 - V_47 -> V_97 ;
}
F_56 ( & V_47 -> V_96 ) ;
} else if ( V_47 -> V_77 . V_78 < V_47 -> args . V_78 )
F_49 ( V_74 , V_47 ) ;
}
int F_57 ( struct V_98 * V_98 , struct V_5 * V_5 )
{
struct V_29 * V_30 ;
struct V_9 * V_9 = F_58 ( V_5 ) -> V_99 ;
int error ;
F_26 ( L_2 ,
V_5 , V_6 , F_59 ( V_5 ) ) ;
F_50 ( V_9 , V_100 ) ;
F_46 ( V_9 , V_101 , 1 ) ;
error = F_60 ( V_9 , V_5 ) ;
if ( error )
goto V_102;
if ( F_30 ( V_5 ) )
goto V_102;
error = - V_80 ;
if ( F_61 ( V_9 ) )
goto V_102;
if ( V_98 == NULL ) {
error = - V_103 ;
V_30 = F_62 ( V_9 , NULL , V_104 ) ;
if ( V_30 == NULL )
goto V_102;
} else
V_30 = F_63 ( F_64 ( V_98 ) ) ;
if ( ! F_65 ( V_9 ) ) {
error = F_66 ( V_30 , V_9 , V_5 ) ;
if ( error == 0 )
goto V_51;
}
error = F_15 ( V_30 , V_9 , V_5 ) ;
V_51:
F_67 ( V_30 ) ;
return error ;
V_102:
F_8 ( V_5 ) ;
return error ;
}
static int
F_68 ( void * V_105 , struct V_5 * V_5 )
{
struct V_106 * V_107 = (struct V_106 * ) V_105 ;
struct V_31 * V_32 ;
unsigned int V_33 ;
int error ;
V_33 = F_16 ( V_5 ) ;
if ( V_33 == 0 )
return F_5 ( V_5 ) ;
V_32 = F_17 ( V_107 -> V_30 , V_5 , NULL , 0 , V_33 ) ;
if ( F_18 ( V_32 ) )
goto V_108;
if ( V_33 < V_6 )
F_20 ( V_5 , V_33 , V_6 ) ;
if ( ! F_21 ( V_107 -> V_8 , V_32 ) ) {
error = V_107 -> V_8 -> V_109 ;
goto V_102;
}
return 0 ;
V_108:
error = F_19 ( V_32 ) ;
V_102:
F_8 ( V_5 ) ;
return error ;
}
int F_69 ( struct V_98 * V_110 , struct V_111 * V_112 ,
struct V_71 * V_52 , unsigned V_113 )
{
struct V_7 V_8 ;
struct V_22 * V_34 ;
struct V_106 V_107 = {
. V_8 = & V_8 ,
} ;
struct V_9 * V_9 = V_112 -> V_99 ;
unsigned long V_114 ;
int V_115 = - V_80 ;
F_26 ( L_3 ,
V_9 -> V_41 -> V_42 ,
( unsigned long long ) F_27 ( V_9 ) ,
V_113 ) ;
F_50 ( V_9 , V_116 ) ;
if ( F_61 ( V_9 ) )
goto V_51;
if ( V_110 == NULL ) {
V_107 . V_30 = F_62 ( V_9 , NULL , V_104 ) ;
if ( V_107 . V_30 == NULL )
return - V_103 ;
} else
V_107 . V_30 = F_63 ( F_64 ( V_110 ) ) ;
V_115 = F_70 ( V_107 . V_30 , V_9 , V_112 ,
V_52 , & V_113 ) ;
if ( V_115 == 0 )
goto V_117;
F_9 ( & V_8 , V_9 , false ,
& V_35 ) ;
V_115 = F_71 ( V_112 , V_52 , F_68 , & V_107 ) ;
F_22 ( & V_8 ) ;
F_14 ( V_8 . V_25 != 1 ) ;
V_34 = & V_8 . V_26 [ 0 ] ;
F_23 ( V_9 ) -> V_36 += V_34 -> V_37 ;
V_114 = ( V_34 -> V_37 + V_6 - 1 ) >>
V_118 ;
F_46 ( V_9 , V_101 , V_114 ) ;
V_117:
F_67 ( V_107 . V_30 ) ;
V_51:
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
