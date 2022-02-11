static int F_1 ( const void * V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
const struct V_5 * V_5 = V_1 ;
if ( F_2 ( V_3 ) == F_3 ( V_5 ) )
F_4 ( L_1 ,
V_3 , V_4 , V_6 -> V_7 , V_6 -> V_8 ) ;
return 0 ;
}
static void F_5 ( struct V_5 * V_5 )
{
if ( V_9 )
F_6 ( V_6 -> V_10 , 0 , F_1 , V_5 ) ;
}
int F_7 ( struct V_5 * V_11 , struct V_5 * V_12 )
{
T_1 V_13 , V_14 , V_15 = 0 ;
char * V_16 , * V_17 , * V_18 = NULL ;
int V_19 ( error ) ;
T_2 V_20 ;
if ( ! ( V_11 -> F_3 -> V_21 & V_22 ) ||
! ( V_12 -> F_3 -> V_21 & V_22 ) )
return 0 ;
V_13 = F_8 ( V_11 , NULL , 0 ) ;
if ( V_13 <= 0 ) {
if ( V_13 == - V_23 )
return 0 ;
return V_13 ;
}
V_16 = F_9 ( V_13 , V_24 ) ;
if ( ! V_16 )
return - V_25 ;
V_13 = F_8 ( V_11 , V_16 , V_13 ) ;
if ( V_13 <= 0 ) {
error = V_13 ;
goto V_26;
}
for ( V_17 = V_16 ; V_13 ; V_17 += V_20 ) {
V_20 = F_10 ( V_17 , V_13 ) + 1 ;
if ( F_11 ( V_20 > V_13 ) ) {
error = - V_27 ;
break;
}
V_13 -= V_20 ;
if ( F_12 ( V_17 ) )
continue;
V_28:
V_14 = F_13 ( V_11 , V_17 , V_18 , V_15 ) ;
if ( V_14 == - V_29 )
V_14 = F_13 ( V_11 , V_17 , NULL , 0 ) ;
if ( V_14 < 0 ) {
error = V_14 ;
break;
}
if ( V_14 > V_15 ) {
void * V_12 ;
V_12 = F_14 ( V_18 , V_14 , V_24 ) ;
if ( ! V_12 ) {
error = - V_25 ;
break;
}
V_18 = V_12 ;
V_15 = V_14 ;
goto V_28;
}
error = F_15 ( V_17 ) ;
if ( error < 0 && error != - V_23 )
break;
if ( error == 1 ) {
error = 0 ;
continue;
}
error = F_16 ( V_12 , V_17 , V_18 , V_14 , 0 ) ;
if ( error )
break;
}
F_17 ( V_18 ) ;
V_26:
F_17 ( V_16 ) ;
return error ;
}
static int F_18 ( struct V_30 * V_11 , struct V_30 * V_12 , T_3 V_31 )
{
struct V_2 * V_32 ;
struct V_2 * V_33 ;
T_3 V_34 = 0 ;
T_3 V_35 = 0 ;
int error = 0 ;
if ( V_31 == 0 )
return 0 ;
V_32 = F_19 ( V_11 , V_36 | V_37 ) ;
if ( F_20 ( V_32 ) )
return F_21 ( V_32 ) ;
V_33 = F_19 ( V_12 , V_36 | V_38 ) ;
if ( F_20 ( V_33 ) ) {
error = F_21 ( V_33 ) ;
goto V_39;
}
error = F_22 ( V_32 , 0 , V_33 , 0 , V_31 ) ;
if ( ! error )
goto V_26;
error = 0 ;
while ( V_31 ) {
T_2 V_40 = V_41 ;
long V_42 ;
if ( V_31 < V_40 )
V_40 = V_31 ;
if ( F_23 ( V_43 , V_6 ) ) {
error = - V_44 ;
break;
}
V_42 = F_24 ( V_32 , & V_34 ,
V_33 , & V_35 ,
V_40 , V_45 ) ;
if ( V_42 <= 0 ) {
error = V_42 ;
break;
}
F_11 ( V_34 != V_35 ) ;
V_31 -= V_42 ;
}
V_26:
if ( ! error )
error = F_25 ( V_33 , 0 ) ;
F_26 ( V_33 ) ;
V_39:
F_26 ( V_32 ) ;
return error ;
}
static int F_27 ( struct V_5 * V_46 , struct V_47 * V_48 )
{
struct V_49 V_50 = {
. V_51 =
V_52 | V_53 | V_54 | V_55 ,
. V_56 = V_48 -> V_57 ,
. V_58 = V_48 -> V_59 ,
} ;
return F_28 ( V_46 , & V_50 , NULL ) ;
}
int F_29 ( struct V_5 * V_46 , struct V_47 * V_48 )
{
int V_60 = 0 ;
if ( ! F_30 ( V_48 -> V_61 ) ) {
struct V_49 V_50 = {
. V_51 = V_62 ,
. V_63 = V_48 -> V_61 ,
} ;
V_60 = F_28 ( V_46 , & V_50 , NULL ) ;
}
if ( ! V_60 ) {
struct V_49 V_50 = {
. V_51 = V_64 | V_65 ,
. V_66 = V_48 -> V_67 ,
. V_68 = V_48 -> V_69 ,
} ;
V_60 = F_28 ( V_46 , & V_50 , NULL ) ;
}
if ( ! V_60 )
F_27 ( V_46 , V_48 ) ;
return V_60 ;
}
static int F_31 ( struct V_5 * V_70 , struct V_5 * V_71 ,
struct V_5 * V_5 , struct V_30 * V_72 ,
struct V_47 * V_48 , const char * V_73 ,
struct V_47 * V_74 , bool tmpfile )
{
struct V_75 * V_76 = V_70 -> F_3 ;
struct V_75 * V_77 = V_71 -> F_3 ;
struct V_5 * V_78 = NULL ;
struct V_5 * V_79 = NULL ;
struct V_5 * V_80 = NULL ;
int V_60 ;
const struct V_81 * V_82 = NULL ;
struct V_81 * V_83 = NULL ;
struct V_84 V_84 = {
. V_61 = V_48 -> V_61 & V_85 ,
. V_86 = V_48 -> V_86 ,
. V_73 = V_73
} ;
V_79 = F_32 ( V_5 -> V_87 . V_17 , V_71 ,
V_5 -> V_87 . V_31 ) ;
V_60 = F_21 ( V_79 ) ;
if ( F_20 ( V_79 ) )
goto V_26;
V_60 = F_33 ( V_5 , & V_83 ) ;
if ( V_60 < 0 )
goto V_88;
if ( V_83 )
V_82 = F_34 ( V_83 ) ;
if ( tmpfile )
V_80 = F_35 ( V_71 , V_48 -> V_61 ) ;
else
V_80 = F_36 ( V_70 , V_5 ) ;
V_60 = F_21 ( V_80 ) ;
if ( F_20 ( V_80 ) )
goto V_88;
V_60 = 0 ;
if ( ! tmpfile )
V_60 = F_37 ( V_76 , V_80 , & V_84 , NULL , true ) ;
if ( V_83 ) {
F_38 ( V_82 ) ;
F_39 ( V_83 ) ;
}
if ( V_60 )
goto V_89;
if ( F_40 ( V_48 -> V_61 ) ) {
struct V_30 V_90 ;
F_41 ( V_5 , & V_90 ) ;
F_42 ( V_90 . V_5 != NULL ) ;
V_90 . V_5 = V_80 ;
if ( tmpfile ) {
F_43 ( V_77 ) ;
V_60 = F_18 ( V_72 , & V_90 ,
V_48 -> V_14 ) ;
F_44 ( V_77 , V_91 ) ;
} else {
V_60 = F_18 ( V_72 , & V_90 ,
V_48 -> V_14 ) ;
}
if ( V_60 )
goto V_92;
}
V_60 = F_7 ( V_72 -> V_5 , V_80 ) ;
if ( V_60 )
goto V_92;
F_45 ( V_80 -> F_3 ) ;
V_60 = F_29 ( V_80 , V_48 ) ;
F_43 ( V_80 -> F_3 ) ;
if ( V_60 )
goto V_92;
if ( tmpfile )
V_60 = F_46 ( V_80 , V_77 , V_79 , true ) ;
else
V_60 = F_47 ( V_76 , V_80 , V_77 , V_79 , 0 ) ;
if ( V_60 )
goto V_92;
V_78 = F_48 ( tmpfile ? V_79 : V_80 ) ;
F_49 ( V_5 , V_78 ) ;
F_50 ( F_3 ( V_5 ) , F_3 ( V_78 ) ) ;
F_27 ( V_71 , V_74 ) ;
V_89:
F_51 ( V_80 ) ;
V_88:
F_51 ( V_79 ) ;
V_26:
return V_60 ;
V_92:
if ( ! tmpfile )
F_52 ( V_76 , V_80 ) ;
goto V_89;
}
static int F_53 ( struct V_5 * V_93 , struct V_5 * V_5 ,
struct V_30 * V_72 , struct V_47 * V_48 )
{
F_54 ( V_94 ) ;
struct V_5 * V_70 = F_55 ( V_5 ) ;
int V_60 ;
struct V_47 V_74 ;
struct V_30 V_95 ;
struct V_5 * V_96 = V_72 -> V_5 ;
struct V_5 * V_71 ;
const char * V_73 = NULL ;
struct V_97 * V_98 = V_5 -> V_99 -> V_100 ;
if ( F_11 ( ! V_70 ) )
return - V_101 ;
F_5 ( V_96 ) ;
F_41 ( V_93 , & V_95 ) ;
V_71 = V_95 . V_5 ;
V_60 = F_56 ( & V_95 , & V_74 ,
V_102 | V_103 , V_104 ) ;
if ( V_60 )
return V_60 ;
if ( F_30 ( V_48 -> V_61 ) ) {
V_73 = F_57 ( V_96 , & V_94 ) ;
if ( F_20 ( V_73 ) )
return F_21 ( V_73 ) ;
}
if ( F_40 ( V_48 -> V_61 ) && V_98 -> tmpfile ) {
V_60 = F_58 ( V_5 ) ;
if ( F_59 ( V_60 ) ) {
F_60 ( L_2 , V_5 , V_60 ) ;
if ( V_60 > 0 )
V_60 = 0 ;
goto V_105;
}
F_44 ( V_71 -> F_3 , V_91 ) ;
V_60 = F_31 ( V_70 , V_71 , V_5 , V_72 ,
V_48 , V_73 , & V_74 , true ) ;
F_43 ( V_71 -> F_3 ) ;
F_61 ( V_5 ) ;
goto V_105;
}
V_60 = - V_27 ;
if ( F_62 ( V_70 , V_71 ) != NULL ) {
F_63 ( L_3 ) ;
goto V_106;
}
if ( F_64 ( V_5 ) ) {
V_60 = 0 ;
goto V_106;
}
V_60 = F_31 ( V_70 , V_71 , V_5 , V_72 ,
V_48 , V_73 , & V_74 , false ) ;
V_106:
F_65 ( V_70 , V_71 ) ;
V_105:
F_66 ( & V_94 ) ;
return V_60 ;
}
int F_67 ( struct V_5 * V_5 , int V_107 )
{
int V_60 = 0 ;
const struct V_81 * V_108 = F_68 ( V_5 -> V_99 ) ;
while ( ! V_60 ) {
struct V_5 * V_109 ;
struct V_5 * V_93 ;
struct V_30 V_72 ;
struct V_47 V_48 ;
enum V_110 type = V_110 ( V_5 ) ;
if ( F_69 ( type ) )
break;
V_109 = F_48 ( V_5 ) ;
for (; ; ) {
V_93 = F_70 ( V_109 ) ;
type = V_110 ( V_93 ) ;
if ( F_69 ( type ) )
break;
F_51 ( V_109 ) ;
V_109 = V_93 ;
}
F_71 ( V_109 , & V_72 ) ;
V_60 = F_56 ( & V_72 , & V_48 ,
V_111 , V_104 ) ;
if ( V_107 & V_112 )
V_48 . V_14 = 0 ;
if ( ! V_60 )
V_60 = F_53 ( V_93 , V_109 , & V_72 , & V_48 ) ;
F_51 ( V_93 ) ;
F_51 ( V_109 ) ;
}
F_38 ( V_108 ) ;
return V_60 ;
}
int F_72 ( struct V_5 * V_5 )
{
return F_67 ( V_5 , 0 ) ;
}
