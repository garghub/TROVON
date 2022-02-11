int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
T_1 V_4 , V_5 ;
char * V_6 , * V_7 , * V_8 ;
int error ;
if ( ! V_2 -> V_9 -> V_10 -> V_11 ||
! V_3 -> V_9 -> V_10 -> V_11 )
return 0 ;
V_4 = F_2 ( V_2 , NULL , 0 ) ;
if ( V_4 <= 0 ) {
if ( V_4 == - V_12 )
return 0 ;
return V_4 ;
}
V_6 = F_3 ( V_4 , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
error = - V_14 ;
V_8 = F_4 ( V_15 , V_13 ) ;
if ( ! V_8 )
goto V_16;
V_4 = F_2 ( V_2 , V_6 , V_4 ) ;
if ( V_4 <= 0 ) {
error = V_4 ;
goto V_17;
}
for ( V_7 = V_6 ; V_7 < ( V_6 + V_4 ) ; V_7 += strlen ( V_7 ) + 1 ) {
V_5 = F_5 ( V_2 , V_7 , V_8 , V_15 ) ;
if ( V_5 <= 0 ) {
error = V_5 ;
goto V_17;
}
error = F_6 ( V_3 , V_7 , V_8 , V_5 , 0 ) ;
if ( error )
goto V_17;
}
V_17:
F_7 ( V_8 ) ;
V_16:
F_7 ( V_6 ) ;
return error ;
}
static int F_8 ( struct V_18 * V_2 , struct V_18 * V_3 , T_2 V_19 )
{
struct V_20 * V_21 ;
struct V_20 * V_22 ;
T_2 V_23 = 0 ;
T_2 V_24 = 0 ;
int error = 0 ;
if ( V_19 == 0 )
return 0 ;
V_21 = F_9 ( V_2 , V_25 | V_26 ) ;
if ( F_10 ( V_21 ) )
return F_11 ( V_21 ) ;
V_22 = F_9 ( V_3 , V_25 | V_27 ) ;
if ( F_10 ( V_22 ) ) {
error = F_11 ( V_22 ) ;
goto V_28;
}
while ( V_19 ) {
T_3 V_29 = V_30 ;
long V_31 ;
if ( V_19 < V_29 )
V_29 = V_19 ;
if ( F_12 ( V_32 , V_33 ) ) {
error = - V_34 ;
break;
}
V_31 = F_13 ( V_21 , & V_23 ,
V_22 , & V_24 ,
V_29 , V_35 ) ;
if ( V_31 <= 0 ) {
error = V_31 ;
break;
}
F_14 ( V_23 != V_24 ) ;
V_19 -= V_31 ;
}
F_15 ( V_22 ) ;
V_28:
F_15 ( V_21 ) ;
return error ;
}
static char * F_16 ( struct V_1 * V_36 )
{
int V_37 ;
char * V_6 ;
struct V_38 * V_38 = V_36 -> V_9 ;
T_4 V_39 ;
V_37 = - V_40 ;
if ( ! V_38 -> V_10 -> V_41 )
goto V_42;
V_37 = - V_14 ;
V_6 = ( char * ) F_17 ( V_13 ) ;
if ( ! V_6 )
goto V_42;
V_39 = F_18 () ;
F_19 ( F_20 () ) ;
V_37 = V_38 -> V_10 -> V_41 ( V_36 ,
( char V_43 * ) V_6 , V_44 - 1 ) ;
F_19 ( V_39 ) ;
if ( V_37 < 0 ) {
F_21 ( ( unsigned long ) V_6 ) ;
goto V_42;
}
V_6 [ V_37 ] = '\0' ;
return V_6 ;
V_42:
return F_22 ( V_37 ) ;
}
static int F_23 ( struct V_1 * V_45 , struct V_46 * V_47 )
{
struct V_48 V_49 = {
. V_50 =
V_51 | V_52 | V_53 | V_54 ,
. V_55 = V_47 -> V_56 ,
. V_57 = V_47 -> V_58 ,
} ;
return F_24 ( V_45 , & V_49 , NULL ) ;
}
int F_25 ( struct V_1 * V_45 , struct V_46 * V_47 )
{
int V_42 = 0 ;
if ( ! F_26 ( V_47 -> V_59 ) ) {
struct V_48 V_49 = {
. V_50 = V_60 ,
. V_61 = V_47 -> V_59 ,
} ;
V_42 = F_24 ( V_45 , & V_49 , NULL ) ;
}
if ( ! V_42 ) {
struct V_48 V_49 = {
. V_50 = V_62 | V_63 ,
. V_64 = V_47 -> V_65 ,
. V_66 = V_47 -> V_67 ,
} ;
V_42 = F_24 ( V_45 , & V_49 , NULL ) ;
}
if ( ! V_42 )
F_23 ( V_45 , V_47 ) ;
return V_42 ;
}
static int F_27 ( struct V_1 * V_68 , struct V_1 * V_69 ,
struct V_1 * V_1 , struct V_18 * V_70 ,
struct V_46 * V_47 , const char * V_71 )
{
struct V_38 * V_72 = V_68 -> V_9 ;
struct V_38 * V_73 = V_69 -> V_9 ;
struct V_1 * V_74 = NULL ;
struct V_1 * V_75 = NULL ;
T_5 V_59 = V_47 -> V_59 ;
int V_42 ;
V_74 = F_28 ( V_68 , V_1 ) ;
V_42 = F_11 ( V_74 ) ;
if ( F_10 ( V_74 ) )
goto V_16;
V_75 = F_29 ( V_1 -> V_76 . V_7 , V_69 ,
V_1 -> V_76 . V_19 ) ;
V_42 = F_11 ( V_75 ) ;
if ( F_10 ( V_75 ) )
goto V_77;
V_47 -> V_59 &= V_78 ;
V_42 = F_30 ( V_72 , V_74 , V_47 , V_71 , NULL , true ) ;
V_47 -> V_59 = V_59 ;
if ( V_42 )
goto V_79;
if ( F_31 ( V_47 -> V_59 ) ) {
struct V_18 V_80 ;
F_32 ( V_1 , & V_80 ) ;
F_33 ( V_80 . V_1 != NULL ) ;
V_80 . V_1 = V_74 ;
V_42 = F_8 ( V_70 , & V_80 , V_47 -> V_5 ) ;
if ( V_42 )
goto V_81;
}
V_42 = F_1 ( V_70 -> V_1 , V_74 ) ;
if ( V_42 )
goto V_81;
F_34 ( & V_74 -> V_9 -> V_82 ) ;
V_42 = F_25 ( V_74 , V_47 ) ;
F_35 ( & V_74 -> V_9 -> V_82 ) ;
if ( V_42 )
goto V_81;
V_42 = F_36 ( V_72 , V_74 , V_73 , V_75 , 0 ) ;
if ( V_42 )
goto V_81;
F_37 ( V_1 , V_74 ) ;
V_74 = NULL ;
if ( ! F_38 ( V_47 -> V_59 ) )
F_39 ( V_1 , true ) ;
V_79:
F_40 ( V_75 ) ;
V_77:
F_40 ( V_74 ) ;
V_16:
return V_42 ;
V_81:
F_41 ( V_72 , V_74 ) ;
goto V_79;
}
int F_42 ( struct V_1 * V_83 , struct V_1 * V_1 ,
struct V_18 * V_70 , struct V_46 * V_47 )
{
struct V_1 * V_68 = F_43 ( V_1 ) ;
int V_42 ;
struct V_46 V_84 ;
struct V_18 V_85 ;
struct V_1 * V_69 ;
struct V_1 * V_45 ;
const struct V_86 * V_87 ;
struct V_86 * V_88 ;
char * V_71 = NULL ;
if ( F_14 ( ! V_68 ) )
return - V_89 ;
F_32 ( V_83 , & V_85 ) ;
V_69 = V_85 . V_1 ;
V_42 = F_44 ( & V_85 , & V_84 ) ;
if ( V_42 )
return V_42 ;
if ( F_26 ( V_47 -> V_59 ) ) {
V_71 = F_16 ( V_70 -> V_1 ) ;
if ( F_10 ( V_71 ) )
return F_11 ( V_71 ) ;
}
V_42 = - V_14 ;
V_88 = F_45 () ;
if ( ! V_88 )
goto V_90;
V_88 -> V_91 = V_47 -> V_65 ;
V_88 -> V_92 = V_47 -> V_67 ;
F_46 ( V_88 -> V_93 , V_94 ) ;
F_46 ( V_88 -> V_93 , V_95 ) ;
F_46 ( V_88 -> V_93 , V_96 ) ;
F_46 ( V_88 -> V_93 , V_97 ) ;
F_46 ( V_88 -> V_93 , V_98 ) ;
F_46 ( V_88 -> V_93 , V_99 ) ;
V_87 = F_47 ( V_88 ) ;
V_42 = - V_100 ;
if ( F_48 ( V_68 , V_69 ) != NULL ) {
F_49 ( L_1 ) ;
goto V_101;
}
V_45 = F_50 ( V_1 ) ;
if ( V_45 ) {
V_42 = 0 ;
goto V_101;
}
V_42 = F_27 ( V_68 , V_69 , V_1 , V_70 ,
V_47 , V_71 ) ;
if ( ! V_42 ) {
F_23 ( V_69 , & V_84 ) ;
}
V_101:
F_51 ( V_68 , V_69 ) ;
F_52 ( V_87 ) ;
F_53 ( V_88 ) ;
V_90:
if ( V_71 )
F_21 ( ( unsigned long ) V_71 ) ;
return V_42 ;
}
int F_54 ( struct V_1 * V_1 )
{
int V_42 ;
V_42 = 0 ;
while ( ! V_42 ) {
struct V_1 * V_102 ;
struct V_1 * V_83 ;
struct V_18 V_70 ;
struct V_46 V_47 ;
enum V_103 type = V_103 ( V_1 ) ;
if ( F_55 ( type ) )
break;
V_102 = F_56 ( V_1 ) ;
for (; ; ) {
V_83 = F_57 ( V_102 ) ;
type = V_103 ( V_83 ) ;
if ( F_55 ( type ) )
break;
F_40 ( V_102 ) ;
V_102 = V_83 ;
}
F_58 ( V_102 , & V_70 ) ;
V_42 = F_44 ( & V_70 , & V_47 ) ;
if ( ! V_42 )
V_42 = F_42 ( V_83 , V_102 , & V_70 , & V_47 ) ;
F_40 ( V_83 ) ;
F_40 ( V_102 ) ;
}
return V_42 ;
}
