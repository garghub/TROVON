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
if ( ! V_12 -> F_2 -> V_21 -> V_22 ||
! V_13 -> F_2 -> V_21 -> V_22 )
return 0 ;
V_14 = F_7 ( V_12 , NULL , 0 ) ;
if ( V_14 <= 0 ) {
if ( V_14 == - V_23 )
return 0 ;
return V_14 ;
}
V_17 = F_8 ( V_14 , V_24 ) ;
if ( ! V_17 )
return - V_25 ;
V_14 = F_7 ( V_12 , V_17 , V_14 ) ;
if ( V_14 <= 0 ) {
error = V_14 ;
goto V_26;
}
for ( V_18 = V_17 ; V_18 < ( V_17 + V_14 ) ; V_18 += strlen ( V_18 ) + 1 ) {
V_27:
V_15 = F_9 ( V_12 , V_18 , V_19 , V_16 ) ;
if ( V_15 == - V_28 )
V_15 = F_9 ( V_12 , V_18 , NULL , 0 ) ;
if ( V_15 < 0 ) {
error = V_15 ;
break;
}
if ( V_15 > V_16 ) {
void * V_13 ;
V_13 = F_10 ( V_19 , V_15 , V_24 ) ;
if ( ! V_13 ) {
error = - V_25 ;
break;
}
V_19 = V_13 ;
V_16 = V_15 ;
goto V_27;
}
error = F_11 ( V_13 , V_18 , V_19 , V_15 , 0 ) ;
if ( error )
break;
}
F_12 ( V_19 ) ;
V_26:
F_12 ( V_17 ) ;
return error ;
}
static int F_13 ( struct V_29 * V_12 , struct V_29 * V_13 , T_2 V_30 )
{
struct V_2 * V_31 ;
struct V_2 * V_32 ;
T_2 V_33 = 0 ;
T_2 V_34 = 0 ;
int error = 0 ;
if ( V_30 == 0 )
return 0 ;
V_31 = F_14 ( V_12 , V_35 | V_36 ) ;
if ( F_15 ( V_31 ) )
return F_16 ( V_31 ) ;
V_32 = F_14 ( V_13 , V_35 | V_37 ) ;
if ( F_15 ( V_32 ) ) {
error = F_16 ( V_32 ) ;
goto V_38;
}
while ( V_30 ) {
T_3 V_39 = V_40 ;
long V_41 ;
if ( V_30 < V_39 )
V_39 = V_30 ;
if ( F_17 ( V_42 , V_7 ) ) {
error = - V_43 ;
break;
}
V_41 = F_18 ( V_31 , & V_33 ,
V_32 , & V_34 ,
V_39 , V_44 ) ;
if ( V_41 <= 0 ) {
error = V_41 ;
break;
}
F_19 ( V_33 != V_34 ) ;
V_30 -= V_41 ;
}
F_20 ( V_32 ) ;
V_38:
F_20 ( V_31 ) ;
return error ;
}
static char * F_21 ( struct V_5 * V_45 )
{
int V_46 ;
char * V_17 ;
struct V_47 * V_47 = V_45 -> F_2 ;
T_4 V_48 ;
V_46 = - V_49 ;
if ( ! V_47 -> V_21 -> V_50 )
goto V_51;
V_46 = - V_25 ;
V_17 = ( char * ) F_22 ( V_24 ) ;
if ( ! V_17 )
goto V_51;
V_48 = F_23 () ;
F_24 ( F_25 () ) ;
V_46 = V_47 -> V_21 -> V_50 ( V_45 ,
( char V_52 * ) V_17 , V_53 - 1 ) ;
F_24 ( V_48 ) ;
if ( V_46 < 0 ) {
F_26 ( ( unsigned long ) V_17 ) ;
goto V_51;
}
V_17 [ V_46 ] = '\0' ;
return V_17 ;
V_51:
return F_27 ( V_46 ) ;
}
static int F_28 ( struct V_5 * V_54 , struct V_55 * V_56 )
{
struct V_57 V_58 = {
. V_59 =
V_60 | V_61 | V_62 | V_63 ,
. V_64 = V_56 -> V_65 ,
. V_66 = V_56 -> V_67 ,
} ;
return F_29 ( V_54 , & V_58 , NULL ) ;
}
int F_30 ( struct V_5 * V_54 , struct V_55 * V_56 )
{
int V_51 = 0 ;
if ( ! F_31 ( V_56 -> V_68 ) ) {
struct V_57 V_58 = {
. V_59 = V_69 ,
. V_70 = V_56 -> V_68 ,
} ;
V_51 = F_29 ( V_54 , & V_58 , NULL ) ;
}
if ( ! V_51 ) {
struct V_57 V_58 = {
. V_59 = V_71 | V_72 ,
. V_73 = V_56 -> V_74 ,
. V_75 = V_56 -> V_76 ,
} ;
V_51 = F_29 ( V_54 , & V_58 , NULL ) ;
}
if ( ! V_51 )
F_28 ( V_54 , V_56 ) ;
return V_51 ;
}
static int F_32 ( struct V_5 * V_77 , struct V_5 * V_78 ,
struct V_5 * V_5 , struct V_29 * V_79 ,
struct V_55 * V_56 , const char * V_80 )
{
struct V_47 * V_81 = V_77 -> F_2 ;
struct V_47 * V_82 = V_78 -> F_2 ;
struct V_5 * V_83 = NULL ;
struct V_5 * V_84 = NULL ;
T_5 V_68 = V_56 -> V_68 ;
int V_51 ;
V_83 = F_33 ( V_77 , V_5 ) ;
V_51 = F_16 ( V_83 ) ;
if ( F_15 ( V_83 ) )
goto V_26;
V_84 = F_34 ( V_5 -> V_85 . V_18 , V_78 ,
V_5 -> V_85 . V_30 ) ;
V_51 = F_16 ( V_84 ) ;
if ( F_15 ( V_84 ) )
goto V_86;
V_56 -> V_68 &= V_87 ;
V_51 = F_35 ( V_81 , V_83 , V_56 , V_80 , NULL , true ) ;
V_56 -> V_68 = V_68 ;
if ( V_51 )
goto V_88;
if ( F_36 ( V_56 -> V_68 ) ) {
struct V_29 V_89 ;
F_37 ( V_5 , & V_89 ) ;
F_38 ( V_89 . V_5 != NULL ) ;
V_89 . V_5 = V_83 ;
V_51 = F_13 ( V_79 , & V_89 , V_56 -> V_15 ) ;
if ( V_51 )
goto V_90;
}
V_51 = F_6 ( V_79 -> V_5 , V_83 ) ;
if ( V_51 )
goto V_90;
F_39 ( V_83 -> F_2 ) ;
V_51 = F_30 ( V_83 , V_56 ) ;
F_40 ( V_83 -> F_2 ) ;
if ( V_51 )
goto V_90;
V_51 = F_41 ( V_81 , V_83 , V_82 , V_84 , 0 ) ;
if ( V_51 )
goto V_90;
F_42 ( V_5 , V_83 ) ;
V_83 = NULL ;
if ( ! F_43 ( V_56 -> V_68 ) )
F_44 ( V_5 , true ) ;
V_88:
F_45 ( V_84 ) ;
V_86:
F_45 ( V_83 ) ;
V_26:
return V_51 ;
V_90:
F_46 ( V_81 , V_83 ) ;
goto V_88;
}
int F_47 ( struct V_5 * V_91 , struct V_5 * V_5 ,
struct V_29 * V_79 , struct V_55 * V_56 )
{
struct V_5 * V_77 = F_48 ( V_5 ) ;
int V_51 ;
struct V_55 V_92 ;
struct V_29 V_93 ;
struct V_5 * V_78 ;
struct V_5 * V_54 ;
const struct V_94 * V_95 ;
struct V_94 * V_96 ;
char * V_80 = NULL ;
if ( F_19 ( ! V_77 ) )
return - V_97 ;
F_4 ( V_79 -> V_5 ) ;
F_37 ( V_91 , & V_93 ) ;
V_78 = V_93 . V_5 ;
V_51 = F_49 ( & V_93 , & V_92 ) ;
if ( V_51 )
return V_51 ;
if ( F_31 ( V_56 -> V_68 ) ) {
V_80 = F_21 ( V_79 -> V_5 ) ;
if ( F_15 ( V_80 ) )
return F_16 ( V_80 ) ;
}
V_51 = - V_25 ;
V_96 = F_50 () ;
if ( ! V_96 )
goto V_98;
V_96 -> V_99 = V_56 -> V_74 ;
V_96 -> V_100 = V_56 -> V_76 ;
F_51 ( V_96 -> V_101 , V_102 ) ;
F_51 ( V_96 -> V_101 , V_103 ) ;
F_51 ( V_96 -> V_101 , V_104 ) ;
F_51 ( V_96 -> V_101 , V_105 ) ;
F_51 ( V_96 -> V_101 , V_106 ) ;
F_51 ( V_96 -> V_101 , V_107 ) ;
V_95 = F_52 ( V_96 ) ;
V_51 = - V_108 ;
if ( F_53 ( V_77 , V_78 ) != NULL ) {
F_54 ( L_2 ) ;
goto V_109;
}
V_54 = F_55 ( V_5 ) ;
if ( V_54 ) {
V_51 = 0 ;
goto V_109;
}
V_51 = F_32 ( V_77 , V_78 , V_5 , V_79 ,
V_56 , V_80 ) ;
if ( ! V_51 ) {
F_28 ( V_78 , & V_92 ) ;
}
V_109:
F_56 ( V_77 , V_78 ) ;
F_57 ( V_95 ) ;
F_58 ( V_96 ) ;
V_98:
if ( V_80 )
F_26 ( ( unsigned long ) V_80 ) ;
return V_51 ;
}
int F_59 ( struct V_5 * V_5 )
{
int V_51 ;
V_51 = 0 ;
while ( ! V_51 ) {
struct V_5 * V_110 ;
struct V_5 * V_91 ;
struct V_29 V_79 ;
struct V_55 V_56 ;
enum V_111 type = V_111 ( V_5 ) ;
if ( F_60 ( type ) )
break;
V_110 = F_61 ( V_5 ) ;
for (; ; ) {
V_91 = F_62 ( V_110 ) ;
type = V_111 ( V_91 ) ;
if ( F_60 ( type ) )
break;
F_45 ( V_110 ) ;
V_110 = V_91 ;
}
F_63 ( V_110 , & V_79 ) ;
V_51 = F_49 ( & V_79 , & V_56 ) ;
if ( ! V_51 )
V_51 = F_47 ( V_91 , V_110 , & V_79 , & V_56 ) ;
F_45 ( V_91 ) ;
F_45 ( V_110 ) ;
}
return V_51 ;
}
