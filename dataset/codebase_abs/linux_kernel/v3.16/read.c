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
V_8 -> V_16 = & V_17 ;
V_8 -> V_22 = F_10 ( V_8 -> V_23 ) -> V_21 ;
}
int F_14 ( struct V_24 * V_25 , struct V_9 * V_9 ,
struct V_5 * V_5 )
{
struct V_26 * V_27 ;
unsigned int V_28 ;
struct V_7 V_8 ;
V_28 = F_15 ( V_5 ) ;
if ( V_28 == 0 )
return F_5 ( V_5 ) ;
V_27 = F_16 ( V_25 , V_5 , NULL , 0 , V_28 ) ;
if ( F_17 ( V_27 ) ) {
F_8 ( V_5 ) ;
return F_18 ( V_27 ) ;
}
if ( V_28 < V_6 )
F_19 ( V_5 , V_28 , V_6 ) ;
F_9 ( & V_8 , V_9 , false ,
& V_29 ) ;
F_20 ( & V_8 , V_27 ) ;
F_21 ( & V_8 ) ;
F_22 ( V_9 ) -> V_30 += V_8 . V_31 ;
return 0 ;
}
static void F_23 ( struct V_26 * V_32 )
{
struct V_9 * V_33 = V_32 -> V_34 -> V_35 -> V_33 ;
F_24 ( L_1 , V_33 -> V_36 -> V_37 ,
( unsigned long long ) F_25 ( V_33 ) , V_32 -> V_38 ,
( long long ) F_26 ( V_32 ) ) ;
if ( F_27 ( V_32 , V_39 ) ) {
if ( F_28 ( V_32 -> V_40 ) )
F_29 ( V_33 , V_32 -> V_40 , 0 ) ;
F_8 ( V_32 -> V_40 ) ;
}
F_24 ( L_2 ,
V_32 -> V_34 -> V_35 -> V_33 -> V_36 -> V_37 ,
( unsigned long long ) F_25 ( V_32 -> V_34 -> V_35 -> V_33 ) ,
V_32 -> V_38 ,
( long long ) F_26 ( V_32 ) ) ;
F_30 ( V_32 ) ;
}
static void F_31 ( struct V_26 * V_32 )
{
if ( F_27 ( V_32 , V_41 ) )
F_7 ( V_32 -> V_40 ) ;
}
static void F_32 ( struct V_42 * V_43 )
{
unsigned long V_44 = 0 ;
if ( F_33 ( V_45 , & V_43 -> V_46 ) )
goto V_47;
while ( ! F_34 ( & V_43 -> V_48 ) ) {
struct V_26 * V_32 = F_35 ( V_43 -> V_48 . V_49 ) ;
struct V_5 * V_5 = V_32 -> V_40 ;
unsigned long V_50 = V_32 -> V_51 ;
unsigned long V_52 = V_32 -> V_51 + V_32 -> V_38 ;
if ( F_33 ( V_53 , & V_43 -> V_46 ) ) {
if ( V_44 > V_43 -> V_54 ) {
F_19 ( V_5 , V_50 , V_52 ) ;
} else if ( V_43 -> V_54 - V_44 < V_32 -> V_38 ) {
V_50 += V_43 -> V_54 - V_44 ;
F_36 ( V_50 < V_32 -> V_51 ) ;
F_19 ( V_5 , V_50 , V_52 ) ;
}
}
V_44 += V_32 -> V_38 ;
if ( F_33 ( V_55 , & V_43 -> V_46 ) ) {
if ( V_44 <= V_43 -> V_54 )
F_31 ( V_32 ) ;
} else
F_31 ( V_32 ) ;
F_37 ( V_32 ) ;
F_23 ( V_32 ) ;
}
V_47:
V_43 -> V_56 ( V_43 ) ;
}
static void F_38 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_61 * V_62 , int V_63 )
{
struct V_9 * V_9 = V_58 -> V_64 -> V_9 ;
int V_65 = F_39 ( V_9 ) ? V_66 : 0 ;
V_62 -> V_46 |= V_65 ;
F_40 ( V_9 ) -> F_41 ( V_58 , V_60 ) ;
}
static void
F_42 ( struct V_67 * V_68 )
{
struct V_26 * V_32 ;
while ( ! F_34 ( V_68 ) ) {
V_32 = F_35 ( V_68 -> V_49 ) ;
F_37 ( V_32 ) ;
F_23 ( V_32 ) ;
}
}
static int F_43 ( struct V_69 * V_70 , struct V_57 * V_58 ,
struct V_9 * V_9 )
{
int V_71 = F_40 ( V_9 ) -> F_44 ( V_70 , V_58 ) ;
if ( V_71 != 0 )
return V_71 ;
F_45 ( V_9 , V_72 , V_58 -> V_73 . V_74 ) ;
if ( V_70 -> V_75 == - V_76 ) {
F_46 ( V_77 , & F_22 ( V_9 ) -> V_46 ) ;
F_47 ( V_9 ) ;
}
return 0 ;
}
static void F_48 ( struct V_69 * V_70 , struct V_57 * V_58 )
{
struct V_78 * V_79 = & V_58 -> args ;
struct V_80 * V_81 = & V_58 -> V_73 ;
F_49 ( V_58 -> V_64 -> V_9 , V_82 ) ;
if ( V_81 -> V_74 == 0 ) {
F_50 ( V_58 -> V_64 , - V_83 , V_79 -> V_84 ) ;
return;
}
V_58 -> V_85 += V_81 -> V_74 ;
V_79 -> V_84 += V_81 -> V_74 ;
V_79 -> V_86 += V_81 -> V_74 ;
V_79 -> V_74 -= V_81 -> V_74 ;
F_51 ( V_70 ) ;
}
static void F_52 ( struct V_69 * V_70 , struct V_57 * V_58 )
{
struct V_42 * V_43 = V_58 -> V_64 ;
if ( V_58 -> V_73 . V_87 ) {
T_1 V_88 ;
V_88 = V_58 -> args . V_84 + V_58 -> V_73 . V_74 ;
F_53 ( & V_43 -> V_89 ) ;
if ( V_88 < V_43 -> V_90 + V_43 -> V_54 ) {
F_46 ( V_53 , & V_43 -> V_46 ) ;
F_54 ( V_55 , & V_43 -> V_46 ) ;
V_43 -> V_54 = V_88 - V_43 -> V_90 ;
}
F_55 ( & V_43 -> V_89 ) ;
} else if ( V_58 -> V_73 . V_74 != V_58 -> args . V_74 )
F_48 ( V_70 , V_58 ) ;
}
int F_56 ( struct V_91 * V_91 , struct V_5 * V_5 )
{
struct V_24 * V_25 ;
struct V_9 * V_9 = F_57 ( V_5 ) -> V_92 ;
int error ;
F_24 ( L_3 ,
V_5 , V_6 , F_58 ( V_5 ) ) ;
F_49 ( V_9 , V_93 ) ;
F_45 ( V_9 , V_94 , 1 ) ;
error = F_59 ( V_9 , V_5 ) ;
if ( error )
goto V_95;
if ( F_28 ( V_5 ) )
goto V_95;
error = - V_76 ;
if ( F_60 ( V_9 ) )
goto V_95;
if ( V_91 == NULL ) {
error = - V_96 ;
V_25 = F_61 ( V_9 , NULL , V_97 ) ;
if ( V_25 == NULL )
goto V_95;
} else
V_25 = F_62 ( F_63 ( V_91 ) ) ;
if ( ! F_64 ( V_9 ) ) {
error = F_65 ( V_25 , V_9 , V_5 ) ;
if ( error == 0 )
goto V_47;
}
error = F_14 ( V_25 , V_9 , V_5 ) ;
V_47:
F_66 ( V_25 ) ;
return error ;
V_95:
F_8 ( V_5 ) ;
return error ;
}
static int
F_67 ( void * V_58 , struct V_5 * V_5 )
{
struct V_98 * V_99 = (struct V_98 * ) V_58 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
int error ;
V_28 = F_15 ( V_5 ) ;
if ( V_28 == 0 )
return F_5 ( V_5 ) ;
V_27 = F_16 ( V_99 -> V_25 , V_5 , NULL , 0 , V_28 ) ;
if ( F_17 ( V_27 ) )
goto V_100;
if ( V_28 < V_6 )
F_19 ( V_5 , V_28 , V_6 ) ;
if ( ! F_20 ( V_99 -> V_8 , V_27 ) ) {
error = V_99 -> V_8 -> V_101 ;
goto V_95;
}
return 0 ;
V_100:
error = F_18 ( V_27 ) ;
V_95:
F_8 ( V_5 ) ;
return error ;
}
int F_68 ( struct V_91 * V_102 , struct V_103 * V_104 ,
struct V_67 * V_48 , unsigned V_105 )
{
struct V_7 V_8 ;
struct V_98 V_99 = {
. V_8 = & V_8 ,
} ;
struct V_9 * V_9 = V_104 -> V_92 ;
unsigned long V_106 ;
int V_107 = - V_76 ;
F_24 ( L_4 ,
V_9 -> V_36 -> V_37 ,
( unsigned long long ) F_25 ( V_9 ) ,
V_105 ) ;
F_49 ( V_9 , V_108 ) ;
if ( F_60 ( V_9 ) )
goto V_47;
if ( V_102 == NULL ) {
V_99 . V_25 = F_61 ( V_9 , NULL , V_97 ) ;
if ( V_99 . V_25 == NULL )
return - V_96 ;
} else
V_99 . V_25 = F_62 ( F_63 ( V_102 ) ) ;
V_107 = F_69 ( V_99 . V_25 , V_9 , V_104 ,
V_48 , & V_105 ) ;
if ( V_107 == 0 )
goto V_109;
F_9 ( & V_8 , V_9 , false ,
& V_29 ) ;
V_107 = F_70 ( V_104 , V_48 , F_67 , & V_99 ) ;
F_21 ( & V_8 ) ;
F_22 ( V_9 ) -> V_30 += V_8 . V_31 ;
V_106 = ( V_8 . V_31 + V_6 - 1 ) >> V_110 ;
F_45 ( V_9 , V_94 , V_106 ) ;
V_109:
F_66 ( V_99 . V_25 ) ;
V_47:
return V_107 ;
}
int T_2 F_71 ( void )
{
V_2 = F_72 ( L_5 ,
sizeof( struct V_1 ) ,
0 , V_111 ,
NULL ) ;
if ( V_2 == NULL )
return - V_112 ;
return 0 ;
}
void F_73 ( void )
{
F_74 ( V_2 ) ;
}
