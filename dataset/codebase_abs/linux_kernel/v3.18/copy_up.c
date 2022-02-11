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
V_21 = F_9 ( V_2 , V_25 ) ;
if ( F_10 ( V_21 ) )
return F_11 ( V_21 ) ;
V_22 = F_9 ( V_3 , V_26 ) ;
if ( F_10 ( V_22 ) ) {
error = F_11 ( V_22 ) ;
goto V_27;
}
while ( V_19 ) {
T_3 V_28 = V_29 ;
long V_30 ;
if ( V_19 < V_28 )
V_28 = V_19 ;
if ( F_12 ( V_31 , V_32 ) ) {
error = - V_33 ;
break;
}
V_30 = F_13 ( V_21 , & V_23 ,
V_22 , & V_24 ,
V_28 , V_34 ) ;
if ( V_30 <= 0 ) {
error = V_30 ;
break;
}
F_14 ( V_23 != V_24 ) ;
V_19 -= V_30 ;
}
F_15 ( V_22 ) ;
V_27:
F_15 ( V_21 ) ;
return error ;
}
static char * F_16 ( struct V_1 * V_35 )
{
int V_36 ;
char * V_6 ;
struct V_37 * V_37 = V_35 -> V_9 ;
T_4 V_38 ;
V_36 = - V_39 ;
if ( ! V_37 -> V_10 -> V_40 )
goto V_41;
V_36 = - V_14 ;
V_6 = ( char * ) F_17 ( V_13 ) ;
if ( ! V_6 )
goto V_41;
V_38 = F_18 () ;
F_19 ( F_20 () ) ;
V_36 = V_37 -> V_10 -> V_40 ( V_35 ,
( char V_42 * ) V_6 , V_43 - 1 ) ;
F_19 ( V_38 ) ;
if ( V_36 < 0 ) {
F_21 ( ( unsigned long ) V_6 ) ;
goto V_41;
}
V_6 [ V_36 ] = '\0' ;
return V_6 ;
V_41:
return F_22 ( V_36 ) ;
}
static int F_23 ( struct V_1 * V_44 , struct V_45 * V_46 )
{
struct V_47 V_48 = {
. V_49 =
V_50 | V_51 | V_52 | V_53 ,
. V_54 = V_46 -> V_55 ,
. V_56 = V_46 -> V_57 ,
} ;
return F_24 ( V_44 , & V_48 , NULL ) ;
}
int F_25 ( struct V_1 * V_44 , struct V_45 * V_46 )
{
int V_41 = 0 ;
if ( ! F_26 ( V_46 -> V_58 ) ) {
struct V_47 V_48 = {
. V_49 = V_59 ,
. V_60 = V_46 -> V_58 ,
} ;
V_41 = F_24 ( V_44 , & V_48 , NULL ) ;
}
if ( ! V_41 ) {
struct V_47 V_48 = {
. V_49 = V_61 | V_62 ,
. V_63 = V_46 -> V_64 ,
. V_65 = V_46 -> V_66 ,
} ;
V_41 = F_24 ( V_44 , & V_48 , NULL ) ;
}
if ( ! V_41 )
F_23 ( V_44 , V_46 ) ;
return V_41 ;
}
static int F_27 ( struct V_1 * V_67 , struct V_1 * V_68 ,
struct V_1 * V_1 , struct V_18 * V_69 ,
struct V_45 * V_46 , struct V_47 * V_48 ,
const char * V_70 )
{
struct V_37 * V_71 = V_67 -> V_9 ;
struct V_37 * V_72 = V_68 -> V_9 ;
struct V_1 * V_73 = NULL ;
struct V_1 * V_74 = NULL ;
T_5 V_58 = V_46 -> V_58 ;
int V_41 ;
V_73 = F_28 ( V_67 , V_1 ) ;
V_41 = F_11 ( V_73 ) ;
if ( F_10 ( V_73 ) )
goto V_16;
V_74 = F_29 ( V_1 -> V_75 . V_7 , V_68 ,
V_1 -> V_75 . V_19 ) ;
V_41 = F_11 ( V_74 ) ;
if ( F_10 ( V_74 ) )
goto V_76;
V_46 -> V_58 &= V_77 ;
V_41 = F_30 ( V_71 , V_73 , V_46 , V_70 , NULL , true ) ;
V_46 -> V_58 = V_58 ;
if ( V_41 )
goto V_78;
if ( F_31 ( V_46 -> V_58 ) ) {
struct V_18 V_79 ;
F_32 ( V_1 , & V_79 ) ;
F_33 ( V_79 . V_1 != NULL ) ;
V_79 . V_1 = V_73 ;
V_41 = F_8 ( V_69 , & V_79 , V_46 -> V_5 ) ;
if ( V_41 )
goto V_80;
}
V_41 = F_1 ( V_69 -> V_1 , V_73 ) ;
if ( V_41 )
goto V_80;
F_34 ( & V_73 -> V_9 -> V_81 ) ;
V_41 = F_25 ( V_73 , V_46 ) ;
if ( ! V_41 && V_48 )
V_41 = F_24 ( V_73 , V_48 , NULL ) ;
F_35 ( & V_73 -> V_9 -> V_81 ) ;
if ( V_41 )
goto V_80;
V_41 = F_36 ( V_71 , V_73 , V_72 , V_74 , 0 ) ;
if ( V_41 )
goto V_80;
F_37 ( V_1 , V_73 ) ;
V_73 = NULL ;
if ( ! F_38 ( V_46 -> V_58 ) )
F_39 ( V_1 , true ) ;
V_78:
F_40 ( V_74 ) ;
V_76:
F_40 ( V_73 ) ;
V_16:
return V_41 ;
V_80:
F_41 ( V_71 , V_73 ) ;
goto V_16;
}
int F_42 ( struct V_1 * V_82 , struct V_1 * V_1 ,
struct V_18 * V_69 , struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_67 = F_43 ( V_1 ) ;
int V_41 ;
struct V_45 V_83 ;
struct V_18 V_84 ;
struct V_1 * V_68 ;
struct V_1 * V_44 ;
const struct V_85 * V_86 ;
struct V_85 * V_87 ;
char * V_70 = NULL ;
F_32 ( V_82 , & V_84 ) ;
V_68 = V_84 . V_1 ;
V_41 = F_44 ( & V_84 , & V_83 ) ;
if ( V_41 )
return V_41 ;
if ( F_26 ( V_46 -> V_58 ) ) {
V_70 = F_16 ( V_69 -> V_1 ) ;
if ( F_10 ( V_70 ) )
return F_11 ( V_70 ) ;
}
V_41 = - V_14 ;
V_87 = F_45 () ;
if ( ! V_87 )
goto V_88;
V_87 -> V_89 = V_46 -> V_64 ;
V_87 -> V_90 = V_46 -> V_66 ;
F_46 ( V_87 -> V_91 , V_92 ) ;
F_46 ( V_87 -> V_91 , V_93 ) ;
F_46 ( V_87 -> V_91 , V_94 ) ;
F_46 ( V_87 -> V_91 , V_95 ) ;
F_46 ( V_87 -> V_91 , V_96 ) ;
F_46 ( V_87 -> V_91 , V_97 ) ;
V_86 = F_47 ( V_87 ) ;
V_41 = - V_98 ;
if ( F_48 ( V_67 , V_68 ) != NULL ) {
F_49 ( L_1 ) ;
goto V_99;
}
V_44 = F_50 ( V_1 ) ;
if ( V_44 ) {
F_51 ( V_67 , V_68 ) ;
V_41 = 0 ;
if ( V_48 ) {
F_34 ( & V_44 -> V_9 -> V_81 ) ;
V_41 = F_24 ( V_44 , V_48 , NULL ) ;
F_35 ( & V_44 -> V_9 -> V_81 ) ;
}
goto V_100;
}
V_41 = F_27 ( V_67 , V_68 , V_1 , V_69 ,
V_46 , V_48 , V_70 ) ;
if ( ! V_41 ) {
F_23 ( V_68 , & V_83 ) ;
}
V_99:
F_51 ( V_67 , V_68 ) ;
V_100:
F_52 ( V_86 ) ;
F_53 ( V_87 ) ;
V_88:
if ( V_70 )
F_21 ( ( unsigned long ) V_70 ) ;
return V_41 ;
}
int F_54 ( struct V_1 * V_1 )
{
int V_41 ;
V_41 = 0 ;
while ( ! V_41 ) {
struct V_1 * V_101 ;
struct V_1 * V_82 ;
struct V_18 V_69 ;
struct V_45 V_46 ;
enum V_102 type = V_102 ( V_1 ) ;
if ( type != V_103 )
break;
V_101 = F_55 ( V_1 ) ;
for (; ; ) {
V_82 = F_56 ( V_101 ) ;
type = V_102 ( V_82 ) ;
if ( type != V_103 )
break;
F_40 ( V_101 ) ;
V_101 = V_82 ;
}
F_57 ( V_101 , & V_69 ) ;
V_41 = F_44 ( & V_69 , & V_46 ) ;
if ( ! V_41 )
V_41 = F_42 ( V_82 , V_101 , & V_69 , & V_46 , NULL ) ;
F_40 ( V_82 ) ;
F_40 ( V_101 ) ;
}
return V_41 ;
}
