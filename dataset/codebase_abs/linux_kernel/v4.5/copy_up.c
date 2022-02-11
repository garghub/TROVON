int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
T_1 V_4 , V_5 , V_6 = 0 ;
char * V_7 , * V_8 , * V_9 = NULL ;
int V_10 ( error ) ;
if ( ! V_2 -> V_11 -> V_12 -> V_13 ||
! V_3 -> V_11 -> V_12 -> V_13 )
return 0 ;
V_4 = F_2 ( V_2 , NULL , 0 ) ;
if ( V_4 <= 0 ) {
if ( V_4 == - V_14 )
return 0 ;
return V_4 ;
}
V_7 = F_3 ( V_4 , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
V_4 = F_2 ( V_2 , V_7 , V_4 ) ;
if ( V_4 <= 0 ) {
error = V_4 ;
goto V_17;
}
for ( V_8 = V_7 ; V_8 < ( V_7 + V_4 ) ; V_8 += strlen ( V_8 ) + 1 ) {
V_18:
V_5 = F_4 ( V_2 , V_8 , V_9 , V_6 ) ;
if ( V_5 == - V_19 )
V_5 = F_4 ( V_2 , V_8 , NULL , 0 ) ;
if ( V_5 < 0 ) {
error = V_5 ;
break;
}
if ( V_5 > V_6 ) {
void * V_3 ;
V_3 = F_5 ( V_9 , V_5 , V_15 ) ;
if ( ! V_3 ) {
error = - V_16 ;
break;
}
V_9 = V_3 ;
V_6 = V_5 ;
goto V_18;
}
error = F_6 ( V_3 , V_8 , V_9 , V_5 , 0 ) ;
if ( error )
break;
}
F_7 ( V_9 ) ;
V_17:
F_7 ( V_7 ) ;
return error ;
}
static int F_8 ( struct V_20 * V_2 , struct V_20 * V_3 , T_2 V_21 )
{
struct V_22 * V_23 ;
struct V_22 * V_24 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
int error = 0 ;
if ( V_21 == 0 )
return 0 ;
V_23 = F_9 ( V_2 , V_27 | V_28 ) ;
if ( F_10 ( V_23 ) )
return F_11 ( V_23 ) ;
V_24 = F_9 ( V_3 , V_27 | V_29 ) ;
if ( F_10 ( V_24 ) ) {
error = F_11 ( V_24 ) ;
goto V_30;
}
while ( V_21 ) {
T_3 V_31 = V_32 ;
long V_33 ;
if ( V_21 < V_31 )
V_31 = V_21 ;
if ( F_12 ( V_34 , V_35 ) ) {
error = - V_36 ;
break;
}
V_33 = F_13 ( V_23 , & V_25 ,
V_24 , & V_26 ,
V_31 , V_37 ) ;
if ( V_33 <= 0 ) {
error = V_33 ;
break;
}
F_14 ( V_25 != V_26 ) ;
V_21 -= V_33 ;
}
F_15 ( V_24 ) ;
V_30:
F_15 ( V_23 ) ;
return error ;
}
static char * F_16 ( struct V_1 * V_38 )
{
int V_39 ;
char * V_7 ;
struct V_40 * V_40 = V_38 -> V_11 ;
T_4 V_41 ;
V_39 = - V_42 ;
if ( ! V_40 -> V_12 -> V_43 )
goto V_44;
V_39 = - V_16 ;
V_7 = ( char * ) F_17 ( V_15 ) ;
if ( ! V_7 )
goto V_44;
V_41 = F_18 () ;
F_19 ( F_20 () ) ;
V_39 = V_40 -> V_12 -> V_43 ( V_38 ,
( char V_45 * ) V_7 , V_46 - 1 ) ;
F_19 ( V_41 ) ;
if ( V_39 < 0 ) {
F_21 ( ( unsigned long ) V_7 ) ;
goto V_44;
}
V_7 [ V_39 ] = '\0' ;
return V_7 ;
V_44:
return F_22 ( V_39 ) ;
}
static int F_23 ( struct V_1 * V_47 , struct V_48 * V_49 )
{
struct V_50 V_51 = {
. V_52 =
V_53 | V_54 | V_55 | V_56 ,
. V_57 = V_49 -> V_58 ,
. V_59 = V_49 -> V_60 ,
} ;
return F_24 ( V_47 , & V_51 , NULL ) ;
}
int F_25 ( struct V_1 * V_47 , struct V_48 * V_49 )
{
int V_44 = 0 ;
if ( ! F_26 ( V_49 -> V_61 ) ) {
struct V_50 V_51 = {
. V_52 = V_62 ,
. V_63 = V_49 -> V_61 ,
} ;
V_44 = F_24 ( V_47 , & V_51 , NULL ) ;
}
if ( ! V_44 ) {
struct V_50 V_51 = {
. V_52 = V_64 | V_65 ,
. V_66 = V_49 -> V_67 ,
. V_68 = V_49 -> V_69 ,
} ;
V_44 = F_24 ( V_47 , & V_51 , NULL ) ;
}
if ( ! V_44 )
F_23 ( V_47 , V_49 ) ;
return V_44 ;
}
static int F_27 ( struct V_1 * V_70 , struct V_1 * V_71 ,
struct V_1 * V_1 , struct V_20 * V_72 ,
struct V_48 * V_49 , const char * V_73 )
{
struct V_40 * V_74 = V_70 -> V_11 ;
struct V_40 * V_75 = V_71 -> V_11 ;
struct V_1 * V_76 = NULL ;
struct V_1 * V_77 = NULL ;
T_5 V_61 = V_49 -> V_61 ;
int V_44 ;
V_76 = F_28 ( V_70 , V_1 ) ;
V_44 = F_11 ( V_76 ) ;
if ( F_10 ( V_76 ) )
goto V_17;
V_77 = F_29 ( V_1 -> V_78 . V_8 , V_71 ,
V_1 -> V_78 . V_21 ) ;
V_44 = F_11 ( V_77 ) ;
if ( F_10 ( V_77 ) )
goto V_79;
V_49 -> V_61 &= V_80 ;
V_44 = F_30 ( V_74 , V_76 , V_49 , V_73 , NULL , true ) ;
V_49 -> V_61 = V_61 ;
if ( V_44 )
goto V_81;
if ( F_31 ( V_49 -> V_61 ) ) {
struct V_20 V_82 ;
F_32 ( V_1 , & V_82 ) ;
F_33 ( V_82 . V_1 != NULL ) ;
V_82 . V_1 = V_76 ;
V_44 = F_8 ( V_72 , & V_82 , V_49 -> V_5 ) ;
if ( V_44 )
goto V_83;
}
V_44 = F_1 ( V_72 -> V_1 , V_76 ) ;
if ( V_44 )
goto V_83;
F_34 ( V_76 -> V_11 ) ;
V_44 = F_25 ( V_76 , V_49 ) ;
F_35 ( V_76 -> V_11 ) ;
if ( V_44 )
goto V_83;
V_44 = F_36 ( V_74 , V_76 , V_75 , V_77 , 0 ) ;
if ( V_44 )
goto V_83;
F_37 ( V_1 , V_76 ) ;
V_76 = NULL ;
if ( ! F_38 ( V_49 -> V_61 ) )
F_39 ( V_1 , true ) ;
V_81:
F_40 ( V_77 ) ;
V_79:
F_40 ( V_76 ) ;
V_17:
return V_44 ;
V_83:
F_41 ( V_74 , V_76 ) ;
goto V_81;
}
int F_42 ( struct V_1 * V_84 , struct V_1 * V_1 ,
struct V_20 * V_72 , struct V_48 * V_49 )
{
struct V_1 * V_70 = F_43 ( V_1 ) ;
int V_44 ;
struct V_48 V_85 ;
struct V_20 V_86 ;
struct V_1 * V_71 ;
struct V_1 * V_47 ;
const struct V_87 * V_88 ;
struct V_87 * V_89 ;
char * V_73 = NULL ;
if ( F_14 ( ! V_70 ) )
return - V_90 ;
F_32 ( V_84 , & V_86 ) ;
V_71 = V_86 . V_1 ;
V_44 = F_44 ( & V_86 , & V_85 ) ;
if ( V_44 )
return V_44 ;
if ( F_26 ( V_49 -> V_61 ) ) {
V_73 = F_16 ( V_72 -> V_1 ) ;
if ( F_10 ( V_73 ) )
return F_11 ( V_73 ) ;
}
V_44 = - V_16 ;
V_89 = F_45 () ;
if ( ! V_89 )
goto V_91;
V_89 -> V_92 = V_49 -> V_67 ;
V_89 -> V_93 = V_49 -> V_69 ;
F_46 ( V_89 -> V_94 , V_95 ) ;
F_46 ( V_89 -> V_94 , V_96 ) ;
F_46 ( V_89 -> V_94 , V_97 ) ;
F_46 ( V_89 -> V_94 , V_98 ) ;
F_46 ( V_89 -> V_94 , V_99 ) ;
F_46 ( V_89 -> V_94 , V_100 ) ;
V_88 = F_47 ( V_89 ) ;
V_44 = - V_101 ;
if ( F_48 ( V_70 , V_71 ) != NULL ) {
F_49 ( L_1 ) ;
goto V_102;
}
V_47 = F_50 ( V_1 ) ;
if ( V_47 ) {
V_44 = 0 ;
goto V_102;
}
V_44 = F_27 ( V_70 , V_71 , V_1 , V_72 ,
V_49 , V_73 ) ;
if ( ! V_44 ) {
F_23 ( V_71 , & V_85 ) ;
}
V_102:
F_51 ( V_70 , V_71 ) ;
F_52 ( V_88 ) ;
F_53 ( V_89 ) ;
V_91:
if ( V_73 )
F_21 ( ( unsigned long ) V_73 ) ;
return V_44 ;
}
int F_54 ( struct V_1 * V_1 )
{
int V_44 ;
V_44 = 0 ;
while ( ! V_44 ) {
struct V_1 * V_103 ;
struct V_1 * V_84 ;
struct V_20 V_72 ;
struct V_48 V_49 ;
enum V_104 type = V_104 ( V_1 ) ;
if ( F_55 ( type ) )
break;
V_103 = F_56 ( V_1 ) ;
for (; ; ) {
V_84 = F_57 ( V_103 ) ;
type = V_104 ( V_84 ) ;
if ( F_55 ( type ) )
break;
F_40 ( V_103 ) ;
V_103 = V_84 ;
}
F_58 ( V_103 , & V_72 ) ;
V_44 = F_44 ( & V_72 , & V_49 ) ;
if ( ! V_44 )
V_44 = F_42 ( V_84 , V_103 , & V_72 , & V_49 ) ;
F_40 ( V_84 ) ;
F_40 ( V_103 ) ;
}
return V_44 ;
}
