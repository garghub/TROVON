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
F_30 ( V_32 ) ;
}
static void F_31 ( struct V_26 * V_32 )
{
if ( F_27 ( V_32 , V_41 ) )
F_7 ( V_32 -> V_40 ) ;
}
static void F_32 ( struct V_1 * V_42 )
{
unsigned long V_43 = 0 ;
if ( F_33 ( V_44 , & V_42 -> V_45 ) )
goto V_46;
while ( ! F_34 ( & V_42 -> V_47 ) ) {
struct V_26 * V_32 = F_35 ( V_42 -> V_47 . V_48 ) ;
struct V_5 * V_5 = V_32 -> V_40 ;
unsigned long V_49 = V_32 -> V_50 ;
unsigned long V_51 = V_32 -> V_50 + V_32 -> V_38 ;
if ( F_33 ( V_52 , & V_42 -> V_45 ) ) {
if ( V_43 > V_42 -> V_53 ) {
F_19 ( V_5 , V_49 , V_51 ) ;
} else if ( V_42 -> V_53 - V_43 < V_32 -> V_38 ) {
V_49 += V_42 -> V_53 - V_43 ;
F_36 ( V_49 < V_32 -> V_50 ) ;
F_19 ( V_5 , V_49 , V_51 ) ;
}
}
V_43 += V_32 -> V_38 ;
if ( F_33 ( V_54 , & V_42 -> V_45 ) ) {
if ( V_43 <= V_42 -> V_53 )
F_31 ( V_32 ) ;
} else
F_31 ( V_32 ) ;
F_37 ( V_32 ) ;
F_23 ( V_32 ) ;
}
V_46:
V_42 -> V_55 ( V_42 ) ;
}
static void F_38 ( struct V_1 * V_42 ,
struct V_56 * V_57 ,
struct V_58 * V_59 , int V_60 )
{
struct V_9 * V_9 = V_42 -> V_9 ;
int V_61 = F_39 ( V_9 ) ? V_62 : 0 ;
V_59 -> V_45 |= V_61 ;
F_40 ( V_9 ) -> F_41 ( V_42 , V_57 ) ;
}
static void
F_42 ( struct V_63 * V_64 )
{
struct V_26 * V_32 ;
while ( ! F_34 ( V_64 ) ) {
V_32 = F_35 ( V_64 -> V_48 ) ;
F_37 ( V_32 ) ;
F_23 ( V_32 ) ;
}
}
static int F_43 ( struct V_65 * V_66 ,
struct V_1 * V_42 ,
struct V_9 * V_9 )
{
int V_67 = F_40 ( V_9 ) -> F_44 ( V_66 , V_42 ) ;
if ( V_67 != 0 )
return V_67 ;
F_45 ( V_9 , V_68 , V_42 -> V_69 . V_70 ) ;
if ( V_66 -> V_71 == - V_72 ) {
F_46 ( V_73 , & F_22 ( V_9 ) -> V_45 ) ;
F_47 ( V_9 ) ;
}
return 0 ;
}
static void F_48 ( struct V_65 * V_66 ,
struct V_1 * V_42 )
{
struct V_74 * V_75 = & V_42 -> args ;
struct V_76 * V_77 = & V_42 -> V_69 ;
F_49 ( V_42 -> V_9 , V_78 ) ;
if ( V_77 -> V_70 == 0 ) {
F_50 ( V_42 , - V_79 , V_75 -> V_80 ) ;
return;
}
V_42 -> V_81 += V_77 -> V_70 ;
V_75 -> V_80 += V_77 -> V_70 ;
V_75 -> V_82 += V_77 -> V_70 ;
V_75 -> V_70 -= V_77 -> V_70 ;
F_51 ( V_66 ) ;
}
static void F_52 ( struct V_65 * V_66 ,
struct V_1 * V_42 )
{
if ( V_42 -> V_69 . V_83 ) {
T_1 V_84 ;
V_84 = V_42 -> args . V_80 + V_42 -> V_69 . V_70 ;
F_53 ( & V_42 -> V_85 ) ;
if ( V_84 < V_42 -> V_86 + V_42 -> V_53 ) {
F_46 ( V_52 , & V_42 -> V_45 ) ;
F_54 ( V_54 , & V_42 -> V_45 ) ;
V_42 -> V_53 = V_84 - V_42 -> V_86 ;
}
F_55 ( & V_42 -> V_85 ) ;
} else if ( V_42 -> V_69 . V_70 != V_42 -> args . V_70 )
F_48 ( V_66 , V_42 ) ;
}
int F_56 ( struct V_87 * V_87 , struct V_5 * V_5 )
{
struct V_24 * V_25 ;
struct V_9 * V_9 = F_57 ( V_5 ) -> V_88 ;
int error ;
F_24 ( L_2 ,
V_5 , V_6 , F_58 ( V_5 ) ) ;
F_49 ( V_9 , V_89 ) ;
F_49 ( V_9 , V_90 ) ;
error = F_59 ( V_9 , V_5 ) ;
if ( error )
goto V_91;
if ( F_28 ( V_5 ) )
goto V_91;
error = - V_72 ;
if ( F_60 ( V_9 ) )
goto V_91;
if ( V_87 == NULL ) {
error = - V_92 ;
V_25 = F_61 ( V_9 , NULL , V_93 ) ;
if ( V_25 == NULL )
goto V_91;
} else
V_25 = F_62 ( F_63 ( V_87 ) ) ;
if ( ! F_64 ( V_9 ) ) {
error = F_65 ( V_25 , V_9 , V_5 ) ;
if ( error == 0 )
goto V_46;
}
error = F_14 ( V_25 , V_9 , V_5 ) ;
V_46:
F_66 ( V_25 ) ;
return error ;
V_91:
F_8 ( V_5 ) ;
return error ;
}
static int
F_67 ( void * V_94 , struct V_5 * V_5 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
int error ;
V_28 = F_15 ( V_5 ) ;
if ( V_28 == 0 )
return F_5 ( V_5 ) ;
V_27 = F_16 ( V_96 -> V_25 , V_5 , NULL , 0 , V_28 ) ;
if ( F_17 ( V_27 ) )
goto V_97;
if ( V_28 < V_6 )
F_19 ( V_5 , V_28 , V_6 ) ;
if ( ! F_20 ( V_96 -> V_8 , V_27 ) ) {
error = V_96 -> V_8 -> V_98 ;
goto V_91;
}
return 0 ;
V_97:
error = F_18 ( V_27 ) ;
V_91:
F_8 ( V_5 ) ;
return error ;
}
int F_68 ( struct V_87 * V_99 , struct V_100 * V_101 ,
struct V_63 * V_47 , unsigned V_102 )
{
struct V_7 V_8 ;
struct V_95 V_96 = {
. V_8 = & V_8 ,
} ;
struct V_9 * V_9 = V_101 -> V_88 ;
unsigned long V_103 ;
int V_104 = - V_72 ;
F_24 ( L_3 ,
V_9 -> V_36 -> V_37 ,
( unsigned long long ) F_25 ( V_9 ) ,
V_102 ) ;
F_49 ( V_9 , V_105 ) ;
if ( F_60 ( V_9 ) )
goto V_46;
if ( V_99 == NULL ) {
V_96 . V_25 = F_61 ( V_9 , NULL , V_93 ) ;
if ( V_96 . V_25 == NULL )
return - V_92 ;
} else
V_96 . V_25 = F_62 ( F_63 ( V_99 ) ) ;
V_104 = F_69 ( V_96 . V_25 , V_9 , V_101 ,
V_47 , & V_102 ) ;
if ( V_104 == 0 )
goto V_106;
F_9 ( & V_8 , V_9 , false ,
& V_29 ) ;
V_104 = F_70 ( V_101 , V_47 , F_67 , & V_96 ) ;
F_21 ( & V_8 ) ;
F_22 ( V_9 ) -> V_30 += V_8 . V_31 ;
V_103 = ( V_8 . V_31 + V_6 - 1 ) >> V_107 ;
F_45 ( V_9 , V_90 , V_103 ) ;
V_106:
F_66 ( V_96 . V_25 ) ;
V_46:
return V_104 ;
}
int T_2 F_71 ( void )
{
V_2 = F_72 ( L_4 ,
sizeof( struct V_1 ) ,
0 , V_108 ,
NULL ) ;
if ( V_2 == NULL )
return - V_109 ;
return 0 ;
}
void F_73 ( void )
{
F_74 ( V_2 ) ;
}
