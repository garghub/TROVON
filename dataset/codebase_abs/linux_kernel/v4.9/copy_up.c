static int F_1 ( const void * V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
const struct V_5 * V_5 = V_1 ;
if ( V_3 -> V_6 == F_2 ( V_5 ) )
F_3 ( L_1 ,
V_3 , V_4 , V_7 -> V_8 , V_7 -> V_9 ) ;
return 0 ;
}
static void F_4 ( struct V_5 * V_5 )
{
if ( V_10 )
F_5 ( V_7 -> V_11 , 0 , F_1 , V_5 ) ;
}
int F_6 ( struct V_5 * V_12 , struct V_5 * V_13 )
{
T_1 V_14 , V_15 , V_16 = 0 ;
char * V_17 , * V_18 , * V_19 = NULL ;
int V_20 ( error ) ;
T_2 V_21 ;
if ( ! ( V_12 -> F_2 -> V_22 & V_23 ) ||
! ( V_13 -> F_2 -> V_22 & V_23 ) )
return 0 ;
V_14 = F_7 ( V_12 , NULL , 0 ) ;
if ( V_14 <= 0 ) {
if ( V_14 == - V_24 )
return 0 ;
return V_14 ;
}
V_17 = F_8 ( V_14 , V_25 ) ;
if ( ! V_17 )
return - V_26 ;
V_14 = F_7 ( V_12 , V_17 , V_14 ) ;
if ( V_14 <= 0 ) {
error = V_14 ;
goto V_27;
}
for ( V_18 = V_17 ; V_14 ; V_18 += V_21 ) {
V_21 = F_9 ( V_18 , V_14 ) + 1 ;
if ( F_10 ( V_21 > V_14 ) ) {
error = - V_28 ;
break;
}
V_14 -= V_21 ;
if ( F_11 ( V_18 ) )
continue;
V_29:
V_15 = F_12 ( V_12 , V_18 , V_19 , V_16 ) ;
if ( V_15 == - V_30 )
V_15 = F_12 ( V_12 , V_18 , NULL , 0 ) ;
if ( V_15 < 0 ) {
error = V_15 ;
break;
}
if ( V_15 > V_16 ) {
void * V_13 ;
V_13 = F_13 ( V_19 , V_15 , V_25 ) ;
if ( ! V_13 ) {
error = - V_26 ;
break;
}
V_19 = V_13 ;
V_16 = V_15 ;
goto V_29;
}
error = F_14 ( V_18 ) ;
if ( error < 0 && error != - V_24 )
break;
if ( error == 1 ) {
error = 0 ;
continue;
}
error = F_15 ( V_13 , V_18 , V_19 , V_15 , 0 ) ;
if ( error )
break;
}
F_16 ( V_19 ) ;
V_27:
F_16 ( V_17 ) ;
return error ;
}
static int F_17 ( struct V_31 * V_12 , struct V_31 * V_13 , T_3 V_32 )
{
struct V_2 * V_33 ;
struct V_2 * V_34 ;
T_3 V_35 = 0 ;
T_3 V_36 = 0 ;
int error = 0 ;
if ( V_32 == 0 )
return 0 ;
V_33 = F_18 ( V_12 , V_37 | V_38 ) ;
if ( F_19 ( V_33 ) )
return F_20 ( V_33 ) ;
V_34 = F_18 ( V_13 , V_37 | V_39 ) ;
if ( F_19 ( V_34 ) ) {
error = F_20 ( V_34 ) ;
goto V_40;
}
while ( V_32 ) {
T_2 V_41 = V_42 ;
long V_43 ;
if ( V_32 < V_41 )
V_41 = V_32 ;
if ( F_21 ( V_44 , V_7 ) ) {
error = - V_45 ;
break;
}
V_43 = F_22 ( V_33 , & V_35 ,
V_34 , & V_36 ,
V_41 , V_46 ) ;
if ( V_43 <= 0 ) {
error = V_43 ;
break;
}
F_10 ( V_35 != V_36 ) ;
V_32 -= V_43 ;
}
if ( ! error )
error = F_23 ( V_34 , 0 ) ;
F_24 ( V_34 ) ;
V_40:
F_24 ( V_33 ) ;
return error ;
}
static int F_25 ( struct V_5 * V_47 , struct V_48 * V_49 )
{
struct V_50 V_51 = {
. V_52 =
V_53 | V_54 | V_55 | V_56 ,
. V_57 = V_49 -> V_58 ,
. V_59 = V_49 -> V_60 ,
} ;
return F_26 ( V_47 , & V_51 , NULL ) ;
}
int F_27 ( struct V_5 * V_47 , struct V_48 * V_49 )
{
int V_61 = 0 ;
if ( ! F_28 ( V_49 -> V_62 ) ) {
struct V_50 V_51 = {
. V_52 = V_63 ,
. V_64 = V_49 -> V_62 ,
} ;
V_61 = F_26 ( V_47 , & V_51 , NULL ) ;
}
if ( ! V_61 ) {
struct V_50 V_51 = {
. V_52 = V_65 | V_66 ,
. V_67 = V_49 -> V_68 ,
. V_69 = V_49 -> V_70 ,
} ;
V_61 = F_26 ( V_47 , & V_51 , NULL ) ;
}
if ( ! V_61 )
F_25 ( V_47 , V_49 ) ;
return V_61 ;
}
static int F_29 ( struct V_5 * V_71 , struct V_5 * V_72 ,
struct V_5 * V_5 , struct V_31 * V_73 ,
struct V_48 * V_49 , const char * V_74 )
{
struct V_75 * V_76 = V_71 -> F_2 ;
struct V_75 * V_77 = V_72 -> F_2 ;
struct V_5 * V_78 = NULL ;
struct V_5 * V_79 = NULL ;
T_4 V_62 = V_49 -> V_62 ;
int V_61 ;
const struct V_80 * V_81 = NULL ;
struct V_80 * V_82 = NULL ;
V_78 = F_30 ( V_71 , V_5 ) ;
V_61 = F_20 ( V_78 ) ;
if ( F_19 ( V_78 ) )
goto V_27;
V_79 = F_31 ( V_5 -> V_83 . V_18 , V_72 ,
V_5 -> V_83 . V_32 ) ;
V_61 = F_20 ( V_79 ) ;
if ( F_19 ( V_79 ) )
goto V_84;
V_61 = F_32 ( V_5 , & V_82 ) ;
if ( V_61 < 0 )
goto V_85;
if ( V_82 )
V_81 = F_33 ( V_82 ) ;
V_49 -> V_62 &= V_86 ;
V_61 = F_34 ( V_76 , V_78 , V_49 , V_74 , NULL , true ) ;
V_49 -> V_62 = V_62 ;
if ( V_82 ) {
F_35 ( V_81 ) ;
F_36 ( V_82 ) ;
}
if ( V_61 )
goto V_85;
if ( F_37 ( V_49 -> V_62 ) ) {
struct V_31 V_87 ;
F_38 ( V_5 , & V_87 ) ;
F_39 ( V_87 . V_5 != NULL ) ;
V_87 . V_5 = V_78 ;
V_61 = F_17 ( V_73 , & V_87 , V_49 -> V_15 ) ;
if ( V_61 )
goto V_88;
}
V_61 = F_6 ( V_73 -> V_5 , V_78 ) ;
if ( V_61 )
goto V_88;
F_40 ( V_78 -> F_2 ) ;
V_61 = F_27 ( V_78 , V_49 ) ;
F_41 ( V_78 -> F_2 ) ;
if ( V_61 )
goto V_88;
V_61 = F_42 ( V_76 , V_78 , V_77 , V_79 , 0 ) ;
if ( V_61 )
goto V_88;
F_43 ( V_5 , V_78 ) ;
F_44 ( F_2 ( V_5 ) , F_2 ( V_78 ) ) ;
V_78 = NULL ;
if ( ! F_45 ( V_49 -> V_62 ) )
F_46 ( V_5 , true ) ;
V_85:
F_47 ( V_79 ) ;
V_84:
F_47 ( V_78 ) ;
V_27:
return V_61 ;
V_88:
F_48 ( V_76 , V_78 ) ;
goto V_85;
}
int F_49 ( struct V_5 * V_89 , struct V_5 * V_5 ,
struct V_31 * V_73 , struct V_48 * V_49 )
{
F_50 ( V_90 ) ;
struct V_5 * V_71 = F_51 ( V_5 ) ;
int V_61 ;
struct V_48 V_91 ;
struct V_31 V_92 ;
struct V_5 * V_93 = V_73 -> V_5 ;
struct V_5 * V_72 ;
struct V_5 * V_47 ;
const char * V_74 = NULL ;
if ( F_10 ( ! V_71 ) )
return - V_94 ;
F_4 ( V_93 ) ;
F_38 ( V_89 , & V_92 ) ;
V_72 = V_92 . V_5 ;
V_61 = F_52 ( & V_92 , & V_91 ) ;
if ( V_61 )
return V_61 ;
if ( F_28 ( V_49 -> V_62 ) ) {
V_74 = F_53 ( V_93 , & V_90 ) ;
if ( F_19 ( V_74 ) )
return F_20 ( V_74 ) ;
}
V_61 = - V_28 ;
if ( F_54 ( V_71 , V_72 ) != NULL ) {
F_55 ( L_2 ) ;
goto V_95;
}
V_47 = F_56 ( V_5 ) ;
if ( V_47 ) {
V_61 = 0 ;
goto V_95;
}
V_61 = F_29 ( V_71 , V_72 , V_5 , V_73 ,
V_49 , V_74 ) ;
if ( ! V_61 ) {
F_25 ( V_72 , & V_91 ) ;
}
V_95:
F_57 ( V_71 , V_72 ) ;
F_58 ( & V_90 ) ;
return V_61 ;
}
int F_59 ( struct V_5 * V_5 )
{
int V_61 = 0 ;
const struct V_80 * V_96 = F_60 ( V_5 -> V_97 ) ;
while ( ! V_61 ) {
struct V_5 * V_98 ;
struct V_5 * V_89 ;
struct V_31 V_73 ;
struct V_48 V_49 ;
enum V_99 type = V_99 ( V_5 ) ;
if ( F_61 ( type ) )
break;
V_98 = F_62 ( V_5 ) ;
for (; ; ) {
V_89 = F_63 ( V_98 ) ;
type = V_99 ( V_89 ) ;
if ( F_61 ( type ) )
break;
F_47 ( V_98 ) ;
V_98 = V_89 ;
}
F_64 ( V_98 , & V_73 ) ;
V_61 = F_52 ( & V_73 , & V_49 ) ;
if ( ! V_61 )
V_61 = F_49 ( V_89 , V_98 , & V_73 , & V_49 ) ;
F_47 ( V_89 ) ;
F_47 ( V_98 ) ;
}
F_35 ( V_96 ) ;
return V_61 ;
}
