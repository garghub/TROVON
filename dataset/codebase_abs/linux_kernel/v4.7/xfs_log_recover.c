static inline int
F_1 (
struct V_1 * log ,
int V_2 )
{
return V_2 > 0 && V_2 <= log -> V_3 ;
}
STATIC T_1 *
F_2 (
struct V_1 * log ,
int V_4 )
{
struct V_5 * V_6 ;
if ( ! F_1 ( log , V_4 ) ) {
F_3 ( log -> V_7 , L_1 ,
V_4 ) ;
F_4 ( V_8 , V_9 , log -> V_7 ) ;
return NULL ;
}
if ( V_4 > 1 && log -> V_10 > 1 )
V_4 += log -> V_10 ;
V_4 = F_5 ( V_4 , log -> V_10 ) ;
V_6 = F_6 ( log -> V_7 -> V_11 , V_4 , 0 ) ;
if ( V_6 )
F_7 ( V_6 ) ;
return V_6 ;
}
STATIC void
F_8 (
T_1 * V_6 )
{
F_9 ( V_6 ) ;
}
STATIC char *
F_10 (
struct V_1 * log ,
T_2 V_12 ,
int V_4 ,
struct V_5 * V_6 )
{
T_2 V_13 = V_12 & ( ( T_2 ) log -> V_10 - 1 ) ;
ASSERT ( V_13 + V_4 <= V_6 -> V_14 ) ;
return V_6 -> V_15 + F_11 ( V_13 ) ;
}
STATIC int
F_12 (
struct V_1 * log ,
T_2 V_12 ,
int V_4 ,
struct V_5 * V_6 )
{
int error ;
if ( ! F_1 ( log , V_4 ) ) {
F_3 ( log -> V_7 , L_1 ,
V_4 ) ;
F_4 ( V_8 , V_9 , log -> V_7 ) ;
return - V_16 ;
}
V_12 = F_13 ( V_12 , log -> V_10 ) ;
V_4 = F_5 ( V_4 , log -> V_10 ) ;
ASSERT ( V_4 > 0 ) ;
ASSERT ( V_4 <= V_6 -> V_14 ) ;
F_14 ( V_6 , log -> V_17 + V_12 ) ;
V_6 -> V_18 |= V_19 ;
V_6 -> V_20 = V_4 ;
V_6 -> V_21 = 0 ;
error = F_15 ( V_6 ) ;
if ( error && ! F_16 ( log -> V_7 ) )
F_17 ( V_6 , V_8 ) ;
return error ;
}
STATIC int
F_18 (
struct V_1 * log ,
T_2 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
char * * V_13 )
{
int error ;
error = F_12 ( log , V_12 , V_4 , V_6 ) ;
if ( error )
return error ;
* V_13 = F_10 ( log , V_12 , V_4 , V_6 ) ;
return 0 ;
}
STATIC int
F_19 (
struct V_1 * log ,
T_2 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
char * V_13 )
{
char * V_22 = V_6 -> V_15 ;
int V_23 = F_11 ( V_6 -> V_14 ) ;
int error , V_24 ;
error = F_20 ( V_6 , V_13 , F_11 ( V_4 ) ) ;
if ( error )
return error ;
error = F_12 ( log , V_12 , V_4 , V_6 ) ;
V_24 = F_20 ( V_6 , V_22 , V_23 ) ;
if ( error )
return error ;
return V_24 ;
}
STATIC int
F_21 (
struct V_1 * log ,
T_2 V_12 ,
int V_4 ,
struct V_5 * V_6 )
{
int error ;
if ( ! F_1 ( log , V_4 ) ) {
F_3 ( log -> V_7 , L_1 ,
V_4 ) ;
F_4 ( V_8 , V_9 , log -> V_7 ) ;
return - V_16 ;
}
V_12 = F_13 ( V_12 , log -> V_10 ) ;
V_4 = F_5 ( V_4 , log -> V_10 ) ;
ASSERT ( V_4 > 0 ) ;
ASSERT ( V_4 <= V_6 -> V_14 ) ;
F_14 ( V_6 , log -> V_17 + V_12 ) ;
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
V_6 -> V_20 = V_4 ;
V_6 -> V_21 = 0 ;
error = F_24 ( V_6 ) ;
if ( error )
F_17 ( V_6 , V_8 ) ;
F_25 ( V_6 ) ;
return error ;
}
STATIC void
F_26 (
T_3 * V_25 ,
T_4 * V_26 )
{
F_27 ( V_25 , L_2 ,
V_8 , & V_25 -> V_27 . V_28 , V_29 ) ;
F_27 ( V_25 , L_3 ,
& V_26 -> V_30 , F_28 ( V_26 -> V_31 ) ) ;
}
STATIC int
F_29 (
T_3 * V_25 ,
T_4 * V_26 )
{
ASSERT ( V_26 -> V_32 == F_30 ( V_33 ) ) ;
if ( F_31 ( V_26 -> V_31 != F_30 ( V_29 ) ) ) {
F_3 ( V_25 ,
L_4 ) ;
F_26 ( V_25 , V_26 ) ;
F_4 ( L_5 ,
V_9 , V_25 ) ;
return - V_16 ;
} else if ( F_31 ( ! F_32 ( & V_25 -> V_27 . V_28 , & V_26 -> V_30 ) ) ) {
F_3 ( V_25 ,
L_6 ) ;
F_26 ( V_25 , V_26 ) ;
F_4 ( L_7 ,
V_9 , V_25 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_33 (
T_3 * V_25 ,
T_4 * V_26 )
{
ASSERT ( V_26 -> V_32 == F_30 ( V_33 ) ) ;
if ( F_34 ( & V_26 -> V_30 ) ) {
F_3 ( V_25 , L_8 ) ;
} else if ( F_31 ( ! F_32 ( & V_25 -> V_27 . V_28 , & V_26 -> V_30 ) ) ) {
F_3 ( V_25 , L_9 ) ;
F_26 ( V_25 , V_26 ) ;
F_4 ( L_10 ,
V_9 , V_25 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC void
F_35 (
struct V_5 * V_6 )
{
if ( V_6 -> V_21 ) {
if ( ! F_16 ( V_6 -> V_34 -> V_35 ) ) {
F_17 ( V_6 , V_8 ) ;
F_36 ( V_6 -> V_34 -> V_35 ,
V_36 ) ;
}
}
V_6 -> V_37 = NULL ;
F_37 ( V_6 ) ;
}
STATIC int
F_38 (
struct V_1 * log ,
struct V_5 * V_6 ,
T_2 V_38 ,
T_2 * V_39 ,
T_5 V_40 )
{
char * V_13 ;
T_2 V_41 ;
T_2 V_42 ;
T_5 V_43 ;
int error ;
V_42 = * V_39 ;
V_41 = F_39 ( V_38 , V_42 ) ;
while ( V_41 != V_38 && V_41 != V_42 ) {
error = F_18 ( log , V_41 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_43 = F_40 ( V_13 ) ;
if ( V_43 == V_40 )
V_42 = V_41 ;
else
V_38 = V_41 ;
V_41 = F_39 ( V_38 , V_42 ) ;
}
ASSERT ( ( V_41 == V_38 && V_41 + 1 == V_42 ) ||
( V_41 == V_42 && V_41 - 1 == V_38 ) ) ;
* V_39 = V_42 ;
return 0 ;
}
STATIC int
F_41 (
struct V_1 * log ,
T_2 V_44 ,
int V_4 ,
T_5 V_45 ,
T_2 * V_46 )
{
T_2 V_47 , V_48 ;
T_5 V_40 ;
T_1 * V_6 ;
T_2 V_49 ;
char * V_50 = NULL ;
int error = 0 ;
V_49 = 1 << F_42 ( V_4 ) ;
while ( V_49 > log -> V_3 )
V_49 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_49 ) ) ) {
V_49 >>= 1 ;
if ( V_49 < log -> V_10 )
return - V_51 ;
}
for ( V_47 = V_44 ; V_47 < V_44 + V_4 ; V_47 += V_49 ) {
int V_52 ;
V_52 = F_43 ( V_49 , ( V_44 + V_4 - V_47 ) ) ;
error = F_18 ( log , V_47 , V_52 , V_6 , & V_50 ) ;
if ( error )
goto V_53;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
V_40 = F_40 ( V_50 ) ;
if ( V_40 == V_45 ) {
* V_46 = V_47 + V_48 ;
goto V_53;
}
V_50 += V_54 ;
}
}
* V_46 = - 1 ;
V_53:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_44 (
struct V_1 * log ,
T_2 V_44 ,
T_2 * V_39 ,
int V_55 )
{
T_2 V_47 ;
T_1 * V_6 ;
char * V_13 = NULL ;
T_4 * V_26 = NULL ;
int error = 0 ;
int V_56 = 0 ;
int V_57 = * V_39 - V_44 ;
int V_58 ;
ASSERT ( V_44 != 0 || * V_39 != V_44 ) ;
if ( ! ( V_6 = F_2 ( log , V_57 ) ) ) {
if ( ! ( V_6 = F_2 ( log , 1 ) ) )
return - V_51 ;
V_56 = 1 ;
} else {
error = F_18 ( log , V_44 , V_57 , V_6 , & V_13 ) ;
if ( error )
goto V_53;
V_13 += ( ( V_57 - 1 ) << V_59 ) ;
}
for ( V_47 = ( * V_39 ) - 1 ; V_47 >= 0 ; V_47 -- ) {
if ( V_47 < V_44 ) {
F_3 ( log -> V_7 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = - V_60 ;
goto V_53;
}
if ( V_56 ) {
error = F_18 ( log , V_47 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_53;
}
V_26 = ( T_4 * ) V_13 ;
if ( V_26 -> V_32 == F_30 ( V_33 ) )
break;
if ( ! V_56 )
V_13 -= V_54 ;
}
if ( V_47 == - 1 ) {
error = 1 ;
goto V_53;
}
if ( ( error = F_33 ( log -> V_7 , V_26 ) ) )
goto V_53;
if ( F_45 ( & log -> V_7 -> V_27 ) ) {
T_5 V_61 = F_28 ( V_26 -> V_61 ) ;
V_58 = V_61 / V_62 ;
if ( V_61 % V_62 )
V_58 ++ ;
} else {
V_58 = 1 ;
}
if ( * V_39 - V_47 + V_55 !=
F_46 ( F_28 ( V_26 -> V_63 ) ) + V_58 )
* V_39 = V_47 ;
V_53:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_47 (
struct V_1 * log ,
T_2 * V_64 )
{
T_1 * V_6 ;
char * V_13 ;
T_2 V_46 , V_38 , V_44 , V_39 , V_65 ;
int V_66 ;
T_5 V_67 , V_68 ;
T_5 V_69 ;
int error , V_70 = log -> V_3 ;
error = F_48 ( log , & V_38 ) ;
if ( error < 0 ) {
F_3 ( log -> V_7 , L_12 ) ;
return error ;
}
if ( error == 1 ) {
* V_64 = V_38 ;
if ( ! V_38 ) {
F_3 ( log -> V_7 , L_13 ) ;
}
return 0 ;
}
V_38 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_51 ;
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_71;
V_67 = F_40 ( V_13 ) ;
V_39 = V_65 = V_70 - 1 ;
error = F_18 ( log , V_39 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_71;
V_68 = F_40 ( V_13 ) ;
ASSERT ( V_68 != 0 ) ;
if ( V_67 == V_68 ) {
V_65 = V_70 ;
V_69 = V_68 - 1 ;
} else {
V_69 = V_68 ;
if ( ( error = F_38 ( log , V_6 , V_38 ,
& V_65 , V_68 ) ) )
goto V_71;
}
V_66 = F_49 ( log ) ;
if ( V_65 >= V_66 ) {
V_44 = V_65 - V_66 ;
if ( ( error = F_41 ( log ,
V_44 , V_66 ,
V_69 , & V_46 ) ) )
goto V_71;
if ( V_46 != - 1 )
V_65 = V_46 ;
} else {
ASSERT ( V_65 <= V_72 &&
( T_2 ) V_66 >= V_65 ) ;
V_44 = V_70 - ( V_66 - V_65 ) ;
if ( ( error = F_41 ( log , V_44 ,
V_66 - ( int ) V_65 ,
( V_69 - 1 ) , & V_46 ) ) )
goto V_71;
if ( V_46 != - 1 ) {
V_65 = V_46 ;
goto V_73;
}
V_44 = 0 ;
ASSERT ( V_65 <= V_72 ) ;
if ( ( error = F_41 ( log ,
V_44 , ( int ) V_65 ,
V_69 , & V_46 ) ) )
goto V_71;
if ( V_46 != - 1 )
V_65 = V_46 ;
}
V_73:
V_66 = F_50 ( log ) ;
if ( V_65 >= V_66 ) {
V_44 = V_65 - V_66 ;
error = F_44 ( log , V_44 , & V_65 , 0 ) ;
if ( error == 1 )
error = - V_60 ;
if ( error )
goto V_71;
} else {
V_44 = 0 ;
ASSERT ( V_65 <= V_72 ) ;
error = F_44 ( log , V_44 , & V_65 , 0 ) ;
if ( error < 0 )
goto V_71;
if ( error == 1 ) {
V_44 = V_70 - ( V_66 - V_65 ) ;
V_46 = V_70 ;
ASSERT ( V_44 <= V_72 &&
( T_2 ) V_70 - V_44 >= 0 ) ;
ASSERT ( V_65 <= V_72 ) ;
error = F_44 ( log , V_44 ,
& V_46 , ( int ) V_65 ) ;
if ( error == 1 )
error = - V_60 ;
if ( error )
goto V_71;
if ( V_46 != V_70 )
V_65 = V_46 ;
} else if ( error )
goto V_71;
}
F_8 ( V_6 ) ;
if ( V_65 == V_70 )
* V_64 = 0 ;
else
* V_64 = V_65 ;
return 0 ;
V_71:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_14 ) ;
return error ;
}
STATIC int
F_51 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 ,
int V_75 ,
struct V_5 * V_6 ,
T_2 * V_76 ,
struct V_77 * * V_78 ,
bool * V_79 )
{
int V_47 ;
int error ;
int V_80 = 0 ;
char * V_13 = NULL ;
T_2 V_42 ;
* V_79 = false ;
V_42 = V_65 > V_74 ? V_74 : 0 ;
for ( V_47 = ( int ) V_65 - 1 ; V_47 >= V_42 ; V_47 -- ) {
error = F_18 ( log , V_47 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_81;
if ( * ( V_82 * ) V_13 == F_30 ( V_33 ) ) {
* V_76 = V_47 ;
* V_78 = (struct V_77 * ) V_13 ;
if ( ++ V_80 == V_75 )
break;
}
}
if ( V_74 >= V_65 && V_80 != V_75 ) {
for ( V_47 = log -> V_3 - 1 ; V_47 >= ( int ) V_74 ; V_47 -- ) {
error = F_18 ( log , V_47 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_81;
if ( * ( V_82 * ) V_13 ==
F_30 ( V_33 ) ) {
* V_79 = true ;
* V_76 = V_47 ;
* V_78 = (struct V_77 * ) V_13 ;
if ( ++ V_80 == V_75 )
break;
}
}
}
return V_80 ;
V_81:
return error ;
}
STATIC int
F_52 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 ,
int V_75 ,
struct V_5 * V_6 ,
T_2 * V_76 ,
struct V_77 * * V_78 ,
bool * V_79 )
{
int V_47 ;
int error ;
int V_80 = 0 ;
char * V_13 = NULL ;
T_2 V_42 ;
* V_79 = false ;
V_42 = V_65 > V_74 ? V_65 : log -> V_3 - 1 ;
for ( V_47 = ( int ) V_74 ; V_47 <= V_42 ; V_47 ++ ) {
error = F_18 ( log , V_47 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_81;
if ( * ( V_82 * ) V_13 == F_30 ( V_33 ) ) {
* V_76 = V_47 ;
* V_78 = (struct V_77 * ) V_13 ;
if ( ++ V_80 == V_75 )
break;
}
}
if ( V_74 > V_65 && V_80 != V_75 ) {
for ( V_47 = 0 ; V_47 < ( int ) V_65 ; V_47 ++ ) {
error = F_18 ( log , V_47 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_81;
if ( * ( V_82 * ) V_13 ==
F_30 ( V_33 ) ) {
* V_79 = true ;
* V_76 = V_47 ;
* V_78 = (struct V_77 * ) V_13 ;
if ( ++ V_80 == V_75 )
break;
}
}
}
return V_80 ;
V_81:
return error ;
}
STATIC int
F_53 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 )
{
struct V_77 * V_83 ;
struct V_5 * V_6 ;
T_2 V_84 ;
int V_75 ;
int error = 0 ;
bool V_79 ;
T_2 V_85 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_51 ;
V_75 = F_52 ( log , V_65 , V_74 ,
V_86 + 1 , V_6 , & V_85 , & V_83 ,
& V_79 ) ;
if ( V_75 < 0 ) {
error = V_75 ;
goto V_53;
}
if ( V_75 < V_86 + 1 )
V_85 = V_65 ;
error = F_54 ( log , V_85 , V_74 ,
V_87 , & V_84 ) ;
V_53:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_55 (
struct V_1 * log ,
T_2 * V_65 ,
T_2 * V_74 ,
struct V_5 * V_6 ,
T_2 * V_88 ,
struct V_77 * * V_78 ,
bool * V_79 )
{
struct V_77 * V_89 ;
struct V_5 * V_90 ;
T_2 V_84 ;
T_2 V_91 ;
int V_80 ;
int error ;
bool V_92 ;
V_90 = F_2 ( log , 1 ) ;
if ( ! V_90 )
return - V_51 ;
error = F_51 ( log , * V_65 , * V_74 ,
V_86 , V_90 , & V_91 ,
& V_89 , & V_92 ) ;
F_8 ( V_90 ) ;
if ( error < 0 )
return error ;
error = F_54 ( log , * V_65 , V_91 ,
V_87 , & V_84 ) ;
if ( error == - V_93 ) {
error = 0 ;
F_3 ( log -> V_7 ,
L_15 ,
V_84 , * V_65 ) ;
V_80 = F_51 ( log , V_84 , * V_74 , 1 , V_6 ,
V_88 , V_78 , V_79 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_80 == 0 )
return - V_60 ;
* V_65 = V_84 ;
* V_74 = F_56 ( F_57 ( ( * V_78 ) -> V_94 ) ) ;
if ( * V_65 == * V_74 ) {
ASSERT ( 0 ) ;
return 0 ;
}
error = F_53 ( log , * V_65 , * V_74 ) ;
}
return error ;
}
static int
F_58 (
struct V_1 * log ,
T_2 * V_65 ,
T_2 * V_74 ,
struct V_77 * V_78 ,
T_2 V_88 ,
struct V_5 * V_6 ,
bool * V_95 )
{
struct V_96 * V_97 ;
T_2 V_98 ;
T_2 V_99 ;
int V_100 ;
int error ;
char * V_13 ;
* V_95 = false ;
if ( F_45 ( & log -> V_7 -> V_27 ) ) {
int V_61 = F_28 ( V_78 -> V_61 ) ;
int V_101 = F_28 ( V_78 -> V_101 ) ;
if ( ( V_101 & V_102 ) &&
( V_61 > V_62 ) ) {
V_100 = V_61 / V_62 ;
if ( V_61 % V_62 )
V_100 ++ ;
} else {
V_100 = 1 ;
}
} else {
V_100 = 1 ;
}
V_99 = V_88 + V_100 + F_46 ( F_28 ( V_78 -> V_63 ) ) ;
V_99 = F_59 ( V_99 , log -> V_3 ) ;
if ( * V_65 == V_99 &&
F_28 ( V_78 -> V_103 ) == 1 ) {
V_98 = V_88 + V_100 ;
V_98 = F_59 ( V_98 , log -> V_3 ) ;
error = F_18 ( log , V_98 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_97 = (struct V_96 * ) V_13 ;
if ( V_97 -> V_104 & V_105 ) {
F_60 ( & log -> V_106 ,
log -> V_107 , V_99 ) ;
F_60 ( & log -> V_108 ,
log -> V_107 , V_99 ) ;
* V_74 = V_99 ;
* V_95 = true ;
}
}
return 0 ;
}
static void
F_61 (
struct V_1 * log ,
T_2 V_65 ,
struct V_77 * V_78 ,
T_2 V_88 ,
bool V_109 )
{
log -> V_110 = V_88 ;
log -> V_111 = ( int ) V_65 ;
log -> V_107 = F_28 ( V_78 -> V_112 ) ;
if ( V_109 )
log -> V_107 ++ ;
F_62 ( & log -> V_106 , F_57 ( V_78 -> V_94 ) ) ;
F_62 ( & log -> V_108 , F_57 ( V_78 -> V_113 ) ) ;
F_63 ( & log -> V_114 . V_115 , log -> V_107 ,
F_11 ( log -> V_111 ) ) ;
F_63 ( & log -> V_116 . V_115 , log -> V_107 ,
F_11 ( log -> V_111 ) ) ;
}
STATIC int
F_64 (
struct V_1 * log ,
T_2 * V_65 ,
T_2 * V_74 )
{
T_4 * V_78 ;
char * V_13 = NULL ;
T_1 * V_6 ;
int error ;
T_2 V_88 ;
T_6 V_117 ;
bool V_79 = false ;
bool V_95 = false ;
if ( ( error = F_47 ( log , V_65 ) ) )
return error ;
ASSERT ( * V_65 < V_72 ) ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_51 ;
if ( * V_65 == 0 ) {
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_118;
if ( F_40 ( V_13 ) == 0 ) {
* V_74 = 0 ;
goto V_118;
}
}
error = F_51 ( log , * V_65 , * V_65 , 1 , V_6 ,
& V_88 , & V_78 , & V_79 ) ;
if ( error < 0 )
return error ;
if ( ! error ) {
F_3 ( log -> V_7 , L_16 , V_8 ) ;
return - V_60 ;
}
* V_74 = F_56 ( F_57 ( V_78 -> V_94 ) ) ;
F_61 ( log , * V_65 , V_78 , V_88 , V_79 ) ;
V_117 = F_65 ( & log -> V_106 ) ;
error = F_58 ( log , V_65 , V_74 , V_78 ,
V_88 , V_6 , & V_95 ) ;
if ( error )
goto V_118;
if ( ! V_95 ) {
T_2 V_119 = * V_65 ;
error = F_55 ( log , V_65 , V_74 , V_6 ,
& V_88 , & V_78 , & V_79 ) ;
if ( error )
goto V_118;
if ( * V_65 != V_119 ) {
F_61 ( log , * V_65 , V_78 , V_88 ,
V_79 ) ;
V_117 = F_65 ( & log -> V_106 ) ;
error = F_58 ( log , V_65 , V_74 ,
V_78 , V_88 , V_6 ,
& V_95 ) ;
if ( error )
goto V_118;
}
}
if ( V_95 )
log -> V_7 -> V_120 |= V_121 ;
if ( ! F_66 ( log -> V_7 -> V_11 ) )
error = F_67 ( log , V_117 ) ;
V_118:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_17 ) ;
return error ;
}
STATIC int
F_48 (
struct V_1 * log ,
T_2 * V_12 )
{
T_1 * V_6 ;
char * V_13 ;
T_5 V_122 , V_123 ;
T_2 V_46 , V_39 , V_44 ;
T_2 V_66 ;
int error , V_70 = log -> V_3 ;
* V_12 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_51 ;
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_71;
V_122 = F_40 ( V_13 ) ;
if ( V_122 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return 1 ;
}
error = F_18 ( log , V_70 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_71;
V_123 = F_40 ( V_13 ) ;
if ( V_123 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_122 != 1 ) {
F_3 ( log -> V_7 ,
L_18 ) ;
error = - V_124 ;
goto V_71;
}
V_39 = V_70 - 1 ;
if ( ( error = F_38 ( log , V_6 , 0 , & V_39 , 0 ) ) )
goto V_71;
V_66 = F_49 ( log ) ;
ASSERT ( V_66 <= V_72 ) ;
if ( V_39 < V_66 )
V_66 = V_39 ;
V_44 = V_39 - V_66 ;
if ( ( error = F_41 ( log , V_44 ,
( int ) V_66 , 0 , & V_46 ) ) )
goto V_71;
if ( V_46 != - 1 )
V_39 = V_46 ;
error = F_44 ( log , V_44 , & V_39 , 0 ) ;
if ( error == 1 )
error = - V_60 ;
if ( error )
goto V_71;
* V_12 = V_39 ;
V_71:
F_8 ( V_6 ) ;
if ( error )
return error ;
return 1 ;
}
STATIC void
F_68 (
struct V_1 * log ,
char * V_50 ,
int V_40 ,
int V_125 ,
int V_126 ,
int V_127 )
{
T_4 * V_128 = ( T_4 * ) V_50 ;
memset ( V_50 , 0 , V_54 ) ;
V_128 -> V_32 = F_30 ( V_33 ) ;
V_128 -> V_112 = F_30 ( V_40 ) ;
V_128 -> V_101 = F_30 (
F_45 ( & log -> V_7 -> V_27 ) ? 2 : 1 ) ;
V_128 -> V_113 = F_69 ( F_70 ( V_40 , V_125 ) ) ;
V_128 -> V_94 = F_69 ( F_70 ( V_126 , V_127 ) ) ;
V_128 -> V_31 = F_30 ( V_29 ) ;
memcpy ( & V_128 -> V_30 , & log -> V_7 -> V_27 . V_28 , sizeof( V_129 ) ) ;
}
STATIC int
F_71 (
struct V_1 * log ,
int V_40 ,
int V_130 ,
int V_131 ,
int V_126 ,
int V_127 )
{
char * V_13 ;
T_1 * V_6 ;
int V_132 , V_133 ;
int V_134 = log -> V_10 ;
int V_135 = V_130 + V_131 ;
int V_49 ;
int error = 0 ;
int V_47 , V_48 = 0 ;
V_49 = 1 << F_42 ( V_131 ) ;
while ( V_49 > log -> V_3 )
V_49 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_49 ) ) ) {
V_49 >>= 1 ;
if ( V_49 < V_134 )
return - V_51 ;
}
V_132 = F_13 ( V_130 , V_134 ) ;
if ( V_132 != V_130 ) {
error = F_12 ( log , V_130 , 1 , V_6 ) ;
if ( error )
goto V_136;
V_48 = V_130 - V_132 ;
}
for ( V_47 = V_130 ; V_47 < V_135 ; V_47 += V_49 ) {
int V_52 , V_137 ;
V_52 = F_43 ( V_49 , V_135 - V_130 ) ;
V_137 = V_52 - V_48 ;
V_133 = F_13 ( V_135 , V_134 ) ;
if ( V_48 == 0 && ( V_130 + V_137 > V_133 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_133 - V_130 ) ;
error = F_19 ( log , V_133 , V_134 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_130 , V_137 , V_6 ) ;
for (; V_48 < V_137 ; V_48 ++ ) {
F_68 ( log , V_13 , V_40 , V_47 + V_48 ,
V_126 , V_127 ) ;
V_13 += V_54 ;
}
error = F_21 ( log , V_130 , V_137 , V_6 ) ;
if ( error )
break;
V_130 += V_137 ;
V_48 = 0 ;
}
V_136:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_67 (
struct V_1 * log ,
T_6 V_117 )
{
int V_126 , V_138 ;
int V_127 , V_139 ;
int V_140 , V_141 ;
int V_142 ;
int error ;
V_126 = F_72 ( V_117 ) ;
V_127 = F_56 ( V_117 ) ;
V_138 = log -> V_107 ;
V_139 = log -> V_111 ;
if ( V_138 == V_126 ) {
if ( F_31 ( V_139 < V_127 || V_139 >= log -> V_3 ) ) {
F_4 ( L_19 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
V_140 = V_127 + ( log -> V_3 - V_139 ) ;
} else {
if ( F_31 ( V_139 >= V_127 || V_138 != ( V_126 + 1 ) ) ) {
F_4 ( L_20 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
V_140 = V_127 - V_139 ;
}
if ( V_140 <= 0 ) {
ASSERT ( V_140 == 0 ) ;
return 0 ;
}
V_141 = F_49 ( log ) ;
V_141 = F_73 ( V_141 , V_140 ) ;
if ( ( V_139 + V_141 ) <= log -> V_3 ) {
error = F_71 ( log , ( V_138 - 1 ) ,
V_139 , V_141 , V_126 ,
V_127 ) ;
if ( error )
return error ;
} else {
V_142 = log -> V_3 - V_139 ;
error = F_71 ( log , ( V_138 - 1 ) ,
V_139 , V_142 , V_126 ,
V_127 ) ;
if ( error )
return error ;
V_142 = V_141 - ( log -> V_3 - V_139 ) ;
error = F_71 ( log , V_138 , 0 , V_142 ,
V_126 , V_127 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_74 (
struct V_1 * log ,
struct V_144 * V_145 ,
int V_146 )
{
T_7 * V_147 , * V_148 ;
int error = 0 ;
F_75 ( V_149 ) ;
F_75 ( V_150 ) ;
F_75 ( V_151 ) ;
F_75 ( V_152 ) ;
F_75 ( V_153 ) ;
F_76 ( & V_145 -> V_154 , & V_149 ) ;
F_77 (item, n, &sort_list, ri_list) {
T_8 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
switch ( F_78 ( V_147 ) ) {
case V_158 :
F_79 ( & V_147 -> V_159 , & V_151 ) ;
break;
case V_160 :
if ( V_155 -> V_161 & V_162 ) {
F_80 ( log ,
V_145 , V_147 , V_146 ) ;
F_81 ( & V_147 -> V_159 , & V_150 ) ;
break;
}
if ( V_155 -> V_161 & V_163 ) {
F_81 ( & V_147 -> V_159 , & V_152 ) ;
break;
}
F_79 ( & V_147 -> V_159 , & V_151 ) ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
F_82 ( log ,
V_145 , V_147 , V_146 ) ;
F_79 ( & V_147 -> V_159 , & V_153 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_21 ,
V_8 ) ;
ASSERT ( 0 ) ;
if ( ! F_83 ( & V_149 ) )
F_76 ( & V_149 , & V_145 -> V_154 ) ;
error = - V_60 ;
goto V_53;
}
}
V_53:
ASSERT ( F_83 ( & V_149 ) ) ;
if ( ! F_83 ( & V_151 ) )
F_84 ( & V_151 , & V_145 -> V_154 ) ;
if ( ! F_83 ( & V_153 ) )
F_85 ( & V_153 , & V_145 -> V_154 ) ;
if ( ! F_83 ( & V_152 ) )
F_85 ( & V_152 , & V_145 -> V_154 ) ;
if ( ! F_83 ( & V_150 ) )
F_85 ( & V_150 , & V_145 -> V_154 ) ;
return error ;
}
STATIC int
F_86 (
struct V_1 * log ,
struct V_169 * V_147 )
{
T_8 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
if ( ! ( V_155 -> V_161 & V_162 ) ) {
F_87 ( log , V_155 ) ;
return 0 ;
}
V_171 = F_88 ( log , V_155 -> V_174 ) ;
F_89 (bcp, bucket, bc_list) {
if ( V_173 -> V_175 == V_155 -> V_174 &&
V_173 -> V_176 == V_155 -> V_177 ) {
V_173 -> V_178 ++ ;
F_90 ( log , V_155 ) ;
return 0 ;
}
}
V_173 = F_91 ( sizeof( struct V_172 ) , V_179 ) ;
V_173 -> V_175 = V_155 -> V_174 ;
V_173 -> V_176 = V_155 -> V_177 ;
V_173 -> V_178 = 1 ;
F_92 ( & V_173 -> V_180 , V_171 ) ;
F_93 ( log , V_155 ) ;
return 0 ;
}
STATIC struct V_172 *
F_94 (
struct V_1 * log ,
T_2 V_181 ,
T_5 V_182 ,
T_9 V_183 )
{
struct V_170 * V_171 ;
struct V_172 * V_173 ;
if ( ! log -> V_184 ) {
ASSERT ( ! ( V_183 & V_162 ) ) ;
return NULL ;
}
V_171 = F_88 ( log , V_181 ) ;
F_89 (bcp, bucket, bc_list) {
if ( V_173 -> V_175 == V_181 && V_173 -> V_176 == V_182 )
return V_173 ;
}
ASSERT ( ! ( V_183 & V_162 ) ) ;
return NULL ;
}
STATIC int
F_95 (
struct V_1 * log ,
T_2 V_181 ,
T_5 V_182 ,
T_9 V_183 )
{
struct V_172 * V_173 ;
V_173 = F_94 ( log , V_181 , V_182 , V_183 ) ;
if ( ! V_173 )
return 0 ;
if ( V_183 & V_162 ) {
if ( -- V_173 -> V_178 == 0 ) {
F_96 ( & V_173 -> V_180 ) ;
F_97 ( V_173 ) ;
}
}
return 1 ;
}
STATIC int
F_98 (
struct V_185 * V_25 ,
T_7 * V_147 ,
struct V_5 * V_6 ,
T_8 * V_155 )
{
int V_47 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_189 = 0 ;
int V_190 = 0 ;
int V_191 ;
int V_192 ;
T_10 * V_193 ;
T_10 * V_194 ;
F_99 ( V_25 -> V_195 , V_155 ) ;
if ( F_100 ( & V_25 -> V_27 ) )
V_6 -> V_196 = & V_197 ;
V_192 = F_11 ( V_6 -> V_20 ) >> V_25 -> V_27 . V_198 ;
for ( V_47 = 0 ; V_47 < V_192 ; V_47 ++ ) {
V_191 = ( V_47 * V_25 -> V_27 . V_199 ) +
F_101 ( V_200 , V_201 ) ;
while ( V_191 >=
( V_189 + V_190 ) ) {
V_187 += V_188 ;
V_187 = F_102 ( V_155 -> V_202 ,
V_155 -> V_203 , V_187 ) ;
if ( V_187 == - 1 )
return 0 ;
V_188 = F_103 ( V_155 -> V_202 ,
V_155 -> V_203 , V_187 ) ;
ASSERT ( V_188 > 0 ) ;
V_189 = V_187 << V_204 ;
V_190 = V_188 << V_204 ;
V_186 ++ ;
}
if ( V_191 < V_189 )
continue;
ASSERT ( V_147 -> V_156 [ V_186 ] . V_157 != NULL ) ;
ASSERT ( ( V_147 -> V_156 [ V_186 ] . V_205 % V_206 ) == 0 ) ;
ASSERT ( ( V_189 + V_190 ) <=
F_11 ( V_6 -> V_20 ) ) ;
V_193 = V_147 -> V_156 [ V_186 ] . V_157 +
V_191 - V_189 ;
if ( F_31 ( * V_193 == 0 ) ) {
F_104 ( V_25 ,
L_22
L_23 ,
V_147 , V_6 ) ;
F_4 ( L_24 ,
V_143 , V_25 ) ;
return - V_16 ;
}
V_194 = F_105 ( V_6 , V_191 ) ;
* V_194 = * V_193 ;
F_106 ( V_25 ,
F_105 ( V_6 , V_47 * V_25 -> V_27 . V_199 ) ) ;
}
return 0 ;
}
static T_6
F_107 (
struct V_185 * V_25 ,
struct V_5 * V_6 )
{
T_11 V_207 ;
T_12 V_208 ;
T_12 V_209 ;
void * V_210 = V_6 -> V_15 ;
V_129 * V_211 ;
T_6 V_212 = - 1 ;
if ( ! F_100 ( & V_25 -> V_27 ) )
goto V_213;
V_207 = F_28 ( * ( V_82 * ) V_210 ) ;
switch ( V_207 ) {
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 : {
struct V_220 * V_221 = V_210 ;
V_212 = F_57 ( V_221 -> V_222 . V_223 . V_224 ) ;
V_211 = & V_221 -> V_222 . V_223 . V_225 ;
break;
}
case V_226 :
case V_227 : {
struct V_220 * V_221 = V_210 ;
V_212 = F_57 ( V_221 -> V_222 . V_228 . V_224 ) ;
V_211 = & V_221 -> V_222 . V_228 . V_225 ;
break;
}
case V_229 :
V_212 = F_57 ( ( (struct V_230 * ) V_210 ) -> V_231 ) ;
V_211 = & ( (struct V_230 * ) V_210 ) -> V_232 ;
break;
case V_233 :
V_212 = F_57 ( ( (struct V_234 * ) V_210 ) -> V_235 ) ;
V_211 = & ( (struct V_234 * ) V_210 ) -> V_236 ;
break;
case V_237 :
V_212 = F_57 ( ( (struct V_238 * ) V_210 ) -> V_239 ) ;
V_211 = & ( (struct V_238 * ) V_210 ) -> V_240 ;
break;
case V_241 :
V_212 = F_57 ( ( (struct V_242 * ) V_210 ) -> V_243 ) ;
V_211 = & ( (struct V_242 * ) V_210 ) -> V_244 ;
break;
case V_245 :
case V_246 :
case V_247 :
V_212 = F_57 ( ( (struct V_248 * ) V_210 ) -> V_212 ) ;
V_211 = & ( (struct V_248 * ) V_210 ) -> V_211 ;
break;
case V_249 :
goto V_213;
case V_250 :
V_212 = F_57 ( ( (struct V_251 * ) V_210 ) -> V_252 ) ;
if ( F_108 ( & V_25 -> V_27 ) )
V_211 = & ( (struct V_251 * ) V_210 ) -> V_253 ;
else
V_211 = & ( (struct V_251 * ) V_210 ) -> V_28 ;
break;
default:
break;
}
if ( V_212 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_253 , V_211 ) )
goto V_213;
return V_212 ;
}
V_209 = F_109 ( ( (struct V_254 * ) V_210 ) -> V_255 ) ;
switch ( V_209 ) {
case V_256 :
case V_257 :
case V_258 :
V_212 = F_57 ( ( (struct V_259 * ) V_210 ) -> V_212 ) ;
V_211 = & ( (struct V_259 * ) V_210 ) -> V_211 ;
break;
default:
break;
}
if ( V_212 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_28 , V_211 ) )
goto V_213;
return V_212 ;
}
V_208 = F_109 ( * ( V_260 * ) V_210 ) ;
switch ( V_208 ) {
case V_261 :
case V_262 :
goto V_213;
default:
break;
}
V_213:
return ( T_6 ) - 1 ;
}
static void
F_110 (
struct V_185 * V_25 ,
struct V_5 * V_6 ,
T_8 * V_155 )
{
struct V_254 * V_263 = V_6 -> V_15 ;
T_11 V_207 ;
T_12 V_208 ;
T_12 V_209 ;
if ( ! F_100 ( & V_25 -> V_27 ) )
return;
V_207 = F_28 ( * ( V_82 * ) V_6 -> V_15 ) ;
V_208 = F_109 ( * ( V_260 * ) V_6 -> V_15 ) ;
V_209 = F_109 ( V_263 -> V_255 ) ;
switch ( F_111 ( V_155 ) ) {
case V_264 :
switch ( V_207 ) {
case V_214 :
case V_215 :
case V_216 :
case V_217 :
V_6 -> V_196 = & V_265 ;
break;
case V_218 :
case V_266 :
case V_219 :
case V_267 :
V_6 -> V_196 = & V_268 ;
break;
case V_226 :
case V_227 :
V_6 -> V_196 = & V_269 ;
break;
default:
F_3 ( V_25 , L_25 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_270 :
if ( V_207 != V_229 ) {
F_3 ( V_25 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_271 ;
break;
case V_272 :
if ( V_207 != V_233 ) {
F_3 ( V_25 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_273 ;
break;
case V_274 :
if ( V_207 != V_237 ) {
F_3 ( V_25 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_275 ;
break;
case V_276 :
case V_277 :
case V_278 :
#ifdef F_112
if ( V_208 != V_261 ) {
F_3 ( V_25 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_279 ;
#else
F_104 ( V_25 ,
L_30 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_280 :
if ( V_208 != V_262 ) {
F_3 ( V_25 , L_31 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_197 ;
break;
case V_281 :
if ( V_207 != V_241 ) {
F_3 ( V_25 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_282 ;
break;
case V_283 :
if ( V_207 != V_284 &&
V_207 != V_245 ) {
F_3 ( V_25 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_285 ;
break;
case V_286 :
if ( V_207 != V_287 &&
V_207 != V_246 ) {
F_3 ( V_25 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_288 ;
break;
case V_289 :
if ( V_207 != V_290 &&
V_207 != V_247 ) {
F_3 ( V_25 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_291 ;
break;
case V_292 :
if ( V_209 != V_293 &&
V_209 != V_256 ) {
F_3 ( V_25 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_294 ;
break;
case V_295 :
if ( V_209 != V_296 &&
V_209 != V_257 ) {
F_3 ( V_25 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_297 ;
break;
case V_298 :
if ( V_209 != V_299 &&
V_209 != V_258 ) {
F_3 ( V_25 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_300 ;
break;
case V_301 :
if ( V_209 != V_302 &&
V_209 != V_303 ) {
F_3 ( V_25 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_304 ;
break;
case V_305 :
if ( V_207 != V_249 ) {
F_3 ( V_25 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_306 ;
break;
case V_307 :
if ( V_207 != V_250 ) {
F_3 ( V_25 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_196 = & V_308 ;
break;
#ifdef F_113
case V_309 :
case V_310 :
V_6 -> V_196 = & V_311 ;
break;
#endif
default:
F_3 ( V_25 , L_42 ,
F_111 ( V_155 ) ) ;
break;
}
}
STATIC void
F_114 (
struct V_185 * V_25 ,
T_7 * V_147 ,
struct V_5 * V_6 ,
T_8 * V_155 )
{
int V_47 ;
int V_187 ;
int V_188 ;
int error ;
F_115 ( V_25 -> V_195 , V_155 ) ;
V_187 = 0 ;
V_47 = 1 ;
while ( 1 ) {
V_187 = F_102 ( V_155 -> V_202 ,
V_155 -> V_203 , V_187 ) ;
if ( V_187 == - 1 )
break;
V_188 = F_103 ( V_155 -> V_202 ,
V_155 -> V_203 , V_187 ) ;
ASSERT ( V_188 > 0 ) ;
ASSERT ( V_147 -> V_156 [ V_47 ] . V_157 != NULL ) ;
ASSERT ( V_147 -> V_156 [ V_47 ] . V_205 % V_206 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_20 ) >=
( ( T_5 ) V_187 << V_204 ) + ( V_188 << V_204 ) ) ;
if ( V_147 -> V_156 [ V_47 ] . V_205 < ( V_188 << V_204 ) )
V_188 = V_147 -> V_156 [ V_47 ] . V_205 >> V_204 ;
error = 0 ;
if ( V_155 -> V_161 &
( V_312 | V_313 | V_314 ) ) {
if ( V_147 -> V_156 [ V_47 ] . V_157 == NULL ) {
F_104 ( V_25 ,
L_43 , V_8 ) ;
goto V_315;
}
if ( V_147 -> V_156 [ V_47 ] . V_205 < sizeof( V_316 ) ) {
F_104 ( V_25 ,
L_44 ,
V_147 -> V_156 [ V_47 ] . V_205 , V_8 ) ;
goto V_315;
}
error = F_116 ( V_25 , V_147 -> V_156 [ V_47 ] . V_157 ,
- 1 , 0 , V_317 ,
L_45 ) ;
if ( error )
goto V_315;
}
memcpy ( F_105 ( V_6 ,
( T_5 ) V_187 << V_204 ) ,
V_147 -> V_156 [ V_47 ] . V_157 ,
V_188 << V_204 ) ;
V_315:
V_47 ++ ;
V_187 += V_188 ;
}
ASSERT ( V_47 == V_147 -> V_318 ) ;
F_110 ( V_25 , V_6 , V_155 ) ;
}
STATIC bool
F_117 (
struct V_185 * V_25 ,
struct V_1 * log ,
struct V_169 * V_147 ,
struct V_5 * V_6 ,
struct V_319 * V_155 )
{
T_5 type ;
F_118 ( log , V_155 ) ;
if ( ! V_25 -> V_320 )
return false ;
type = 0 ;
if ( V_155 -> V_161 & V_312 )
type |= V_321 ;
if ( V_155 -> V_161 & V_313 )
type |= V_322 ;
if ( V_155 -> V_161 & V_314 )
type |= V_323 ;
if ( log -> V_324 & type )
return false ;
F_114 ( V_25 , V_147 , V_6 , V_155 ) ;
return true ;
}
STATIC int
F_119 (
struct V_1 * log ,
struct V_170 * V_151 ,
struct V_169 * V_147 ,
T_6 V_325 )
{
T_8 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_5 V_326 ;
T_6 V_212 ;
if ( F_95 ( log , V_155 -> V_174 ,
V_155 -> V_177 , V_155 -> V_161 ) ) {
F_120 ( log , V_155 ) ;
return 0 ;
}
F_121 ( log , V_155 ) ;
V_326 = 0 ;
if ( V_155 -> V_161 & V_163 )
V_326 |= V_327 ;
V_6 = F_122 ( V_25 -> V_328 , V_155 -> V_174 , V_155 -> V_177 ,
V_326 , NULL ) ;
if ( ! V_6 )
return - V_51 ;
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_46 ) ;
goto V_329;
}
V_212 = F_107 ( V_25 , V_6 ) ;
if ( V_212 && V_212 != - 1 && F_123 ( V_212 , V_325 ) >= 0 ) {
F_110 ( V_25 , V_6 , V_155 ) ;
goto V_329;
}
if ( V_155 -> V_161 & V_163 ) {
error = F_98 ( V_25 , V_147 , V_6 , V_155 ) ;
if ( error )
goto V_329;
} else if ( V_155 -> V_161 &
( V_312 | V_313 | V_314 ) ) {
bool V_330 ;
V_330 = F_117 ( V_25 , log , V_147 , V_6 , V_155 ) ;
if ( ! V_330 )
goto V_329;
} else {
F_114 ( V_25 , V_147 , V_6 , V_155 ) ;
}
if ( V_262 ==
F_109 ( * ( ( V_260 * ) F_105 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_20 ) != F_124 ( log -> V_7 -> V_27 . V_331 ,
( T_11 ) log -> V_7 -> V_332 ) ) ) {
F_125 ( V_6 ) ;
error = F_24 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_37 = F_35 ;
F_126 ( V_6 , V_151 ) ;
}
V_329:
F_25 ( V_6 ) ;
return error ;
}
STATIC int
F_127 (
struct V_185 * V_25 ,
struct V_333 * V_334 ,
struct V_335 * V_336 ,
struct V_170 * V_151 )
{
struct V_337 * V_338 ;
int error ;
ASSERT ( V_336 -> V_339 & ( V_340 | V_341 ) ) ;
V_338 = F_128 ( V_25 , V_336 -> V_342 ) ;
if ( ! V_338 )
return - V_51 ;
F_129 ( V_338 , V_334 ) ;
ASSERT ( V_338 -> V_343 . V_344 >= 3 ) ;
error = F_130 ( V_338 , V_334 ) ;
if ( error )
goto V_345;
if ( V_336 -> V_339 & V_340 ) {
ASSERT ( V_336 -> V_339 & V_346 ) ;
error = F_131 ( NULL , V_338 , V_347 ,
V_338 -> V_348 , V_151 ) ;
if ( error )
goto V_345;
}
if ( V_336 -> V_339 & V_341 ) {
ASSERT ( V_336 -> V_339 & V_349 ) ;
error = F_131 ( NULL , V_338 , V_350 ,
V_338 -> V_348 , V_151 ) ;
if ( error )
goto V_345;
}
V_345:
F_132 ( V_338 ) ;
return error ;
}
STATIC int
F_133 (
struct V_1 * log ,
struct V_170 * V_151 ,
struct V_169 * V_147 ,
T_6 V_325 )
{
T_13 * V_336 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
V_200 * V_334 ;
int V_182 ;
char * V_351 ;
char * V_352 ;
int error ;
int V_353 ;
T_5 V_354 ;
struct V_355 * V_356 ;
T_5 V_357 ;
int V_358 = 0 ;
if ( V_147 -> V_156 [ 0 ] . V_205 == sizeof( T_13 ) ) {
V_336 = V_147 -> V_156 [ 0 ] . V_157 ;
} else {
V_336 = F_91 ( sizeof( T_13 ) , V_179 ) ;
V_358 = 1 ;
error = F_134 ( & V_147 -> V_156 [ 0 ] , V_336 ) ;
if ( error )
goto error;
}
if ( F_95 ( log , V_336 -> V_359 ,
V_336 -> V_360 , 0 ) ) {
error = 0 ;
F_135 ( log , V_336 ) ;
goto error;
}
F_136 ( log , V_336 ) ;
V_6 = F_122 ( V_25 -> V_328 , V_336 -> V_359 , V_336 -> V_360 , 0 ,
& V_197 ) ;
if ( ! V_6 ) {
error = - V_51 ;
goto error;
}
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_47 ) ;
goto V_329;
}
ASSERT ( V_336 -> V_339 & V_361 ) ;
V_334 = F_105 ( V_6 , V_336 -> V_362 ) ;
if ( F_31 ( V_334 -> V_363 != F_137 ( V_262 ) ) ) {
F_104 ( V_25 ,
L_48 ,
V_8 , V_334 , V_6 , V_336 -> V_342 ) ;
F_4 ( L_49 ,
V_143 , V_25 ) ;
error = - V_16 ;
goto V_329;
}
V_356 = V_147 -> V_156 [ 1 ] . V_157 ;
if ( F_31 ( V_356 -> V_363 != V_262 ) ) {
F_104 ( V_25 ,
L_50 ,
V_8 , V_147 , V_336 -> V_342 ) ;
F_4 ( L_51 ,
V_143 , V_25 ) ;
error = - V_16 ;
goto V_329;
}
if ( V_334 -> V_344 >= 3 ) {
T_6 V_212 = F_57 ( V_334 -> V_364 ) ;
if ( V_212 && V_212 != - 1 && F_123 ( V_212 , V_325 ) >= 0 ) {
F_138 ( log , V_336 ) ;
error = 0 ;
goto V_365;
}
}
if ( ! F_100 ( & V_25 -> V_27 ) &&
V_356 -> V_366 < F_109 ( V_334 -> V_366 ) ) {
if ( F_109 ( V_334 -> V_366 ) == V_367 &&
V_356 -> V_366 < ( V_367 >> 1 ) ) {
} else {
F_138 ( log , V_336 ) ;
error = 0 ;
goto V_329;
}
}
V_356 -> V_366 = 0 ;
if ( F_31 ( F_139 ( V_356 -> V_368 ) ) ) {
if ( ( V_356 -> V_369 != V_370 ) &&
( V_356 -> V_369 != V_371 ) ) {
F_140 ( L_52 ,
V_143 , V_25 , V_356 ) ;
F_104 ( V_25 ,
L_53
L_54 ,
V_8 , V_147 , V_334 , V_6 , V_336 -> V_342 ) ;
error = - V_16 ;
goto V_329;
}
} else if ( F_31 ( F_141 ( V_356 -> V_368 ) ) ) {
if ( ( V_356 -> V_369 != V_370 ) &&
( V_356 -> V_369 != V_371 ) &&
( V_356 -> V_369 != V_372 ) ) {
F_140 ( L_55 ,
V_143 , V_25 , V_356 ) ;
F_104 ( V_25 ,
L_56
L_54 ,
V_8 , V_147 , V_334 , V_6 , V_336 -> V_342 ) ;
error = - V_16 ;
goto V_329;
}
}
if ( F_31 ( V_356 -> V_373 + V_356 -> V_374 > V_356 -> V_375 ) ) {
F_140 ( L_57 ,
V_143 , V_25 , V_356 ) ;
F_104 ( V_25 ,
L_58
L_59 ,
V_8 , V_147 , V_334 , V_6 , V_336 -> V_342 ,
V_356 -> V_373 + V_356 -> V_374 ,
V_356 -> V_375 ) ;
error = - V_16 ;
goto V_329;
}
if ( F_31 ( V_356 -> V_376 > V_25 -> V_27 . V_199 ) ) {
F_140 ( L_60 ,
V_143 , V_25 , V_356 ) ;
F_104 ( V_25 ,
L_58
L_61 , V_8 ,
V_147 , V_334 , V_6 , V_336 -> V_342 , V_356 -> V_376 ) ;
error = - V_16 ;
goto V_329;
}
V_357 = F_142 ( V_356 -> V_344 ) ;
if ( F_31 ( V_147 -> V_156 [ 1 ] . V_205 > V_357 ) ) {
F_140 ( L_62 ,
V_143 , V_25 , V_356 ) ;
F_104 ( V_25 ,
L_63 ,
V_8 , V_147 -> V_156 [ 1 ] . V_205 , V_147 ) ;
error = - V_16 ;
goto V_329;
}
F_143 ( V_356 , V_334 ) ;
if ( V_147 -> V_156 [ 1 ] . V_205 > V_357 ) {
memcpy ( ( char * ) V_334 + V_357 ,
V_147 -> V_156 [ 1 ] . V_157 + V_357 ,
V_147 -> V_156 [ 1 ] . V_205 - V_357 ) ;
}
V_354 = V_336 -> V_339 ;
switch ( V_354 & ( V_377 | V_378 ) ) {
case V_377 :
F_144 ( V_334 , V_336 -> V_379 . V_380 ) ;
break;
case V_378 :
memcpy ( F_145 ( V_334 ) ,
& V_336 -> V_379 . V_381 ,
sizeof( V_129 ) ) ;
break;
}
if ( V_336 -> V_382 == 2 )
goto V_365;
V_182 = V_147 -> V_156 [ 2 ] . V_205 ;
V_351 = V_147 -> V_156 [ 2 ] . V_157 ;
ASSERT ( V_336 -> V_382 <= 4 ) ;
ASSERT ( ( V_336 -> V_382 == 3 ) || ( V_354 & V_383 ) ) ;
ASSERT ( ! ( V_354 & V_384 ) ||
( V_182 == V_336 -> V_385 ) ) ;
switch ( V_354 & V_384 ) {
case V_386 :
case V_387 :
memcpy ( F_145 ( V_334 ) , V_351 , V_182 ) ;
break;
case V_346 :
F_146 ( V_25 , (struct V_220 * ) V_351 , V_182 ,
( V_388 * ) F_145 ( V_334 ) ,
F_147 ( V_334 , V_25 ) ) ;
break;
default:
ASSERT ( ( V_354 & V_384 ) == 0 ) ;
break;
}
if ( V_336 -> V_339 & V_383 ) {
if ( V_336 -> V_339 & V_384 ) {
V_353 = 3 ;
} else {
V_353 = 2 ;
}
V_182 = V_147 -> V_156 [ V_353 ] . V_205 ;
V_351 = V_147 -> V_156 [ V_353 ] . V_157 ;
ASSERT ( V_182 == V_336 -> V_389 ) ;
switch ( V_336 -> V_339 & V_383 ) {
case V_390 :
case V_391 :
V_352 = F_148 ( V_334 ) ;
ASSERT ( V_182 <= F_149 ( V_334 , V_25 ) ) ;
memcpy ( V_352 , V_351 , V_182 ) ;
break;
case V_349 :
V_352 = F_148 ( V_334 ) ;
F_146 ( V_25 , (struct V_220 * ) V_351 ,
V_182 , ( V_388 * ) V_352 ,
F_149 ( V_334 , V_25 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_64 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_60 ;
goto V_329;
}
}
V_365:
if ( V_336 -> V_339 & ( V_340 | V_341 ) )
error = F_127 ( V_25 , V_334 , V_336 ,
V_151 ) ;
F_106 ( log -> V_7 , V_334 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_37 = F_35 ;
F_126 ( V_6 , V_151 ) ;
V_329:
F_25 ( V_6 ) ;
error:
if ( V_358 )
F_97 ( V_336 ) ;
return error ;
}
STATIC int
F_150 (
struct V_1 * log ,
struct V_169 * V_147 )
{
T_14 * V_392 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_392 ) ;
if ( V_392 -> V_393 & V_394 )
log -> V_324 |= V_321 ;
if ( V_392 -> V_393 & V_395 )
log -> V_324 |= V_322 ;
if ( V_392 -> V_393 & V_396 )
log -> V_324 |= V_323 ;
return 0 ;
}
STATIC int
F_151 (
struct V_1 * log ,
struct V_170 * V_151 ,
struct V_169 * V_147 ,
T_6 V_325 )
{
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
struct V_397 * V_398 , * V_399 ;
int error ;
T_15 * V_400 ;
T_5 type ;
if ( V_25 -> V_320 == 0 )
return 0 ;
V_399 = V_147 -> V_156 [ 1 ] . V_157 ;
if ( V_399 == NULL ) {
F_104 ( log -> V_7 , L_65 , V_8 ) ;
return - V_60 ;
}
if ( V_147 -> V_156 [ 1 ] . V_205 < sizeof( V_316 ) ) {
F_104 ( log -> V_7 , L_66 ,
V_147 -> V_156 [ 1 ] . V_205 , V_8 ) ;
return - V_60 ;
}
type = V_399 -> V_401 & ( V_321 | V_322 | V_323 ) ;
ASSERT ( type ) ;
if ( log -> V_324 & type )
return 0 ;
V_400 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_400 ) ;
error = F_116 ( V_25 , V_399 , V_400 -> V_402 , 0 , V_317 ,
L_67 ) ;
if ( error )
return - V_60 ;
ASSERT ( V_400 -> V_403 == 1 ) ;
error = F_152 ( V_25 , NULL , V_25 -> V_328 , V_400 -> V_404 ,
F_153 ( V_25 , V_400 -> V_403 ) , 0 , & V_6 ,
& V_279 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_398 = F_105 ( V_6 , V_400 -> V_405 ) ;
if ( F_100 ( & V_25 -> V_27 ) ) {
struct V_406 * V_407 = (struct V_406 * ) V_398 ;
T_6 V_212 = F_57 ( V_407 -> V_408 ) ;
if ( V_212 && V_212 != - 1 && F_123 ( V_212 , V_325 ) >= 0 ) {
goto V_329;
}
}
memcpy ( V_398 , V_399 , V_147 -> V_156 [ 1 ] . V_205 ) ;
if ( F_100 ( & V_25 -> V_27 ) ) {
F_154 ( ( char * ) V_398 , sizeof( struct V_406 ) ,
V_409 ) ;
}
ASSERT ( V_400 -> V_410 == 2 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_37 = F_35 ;
F_126 ( V_6 , V_151 ) ;
V_329:
F_25 ( V_6 ) ;
return 0 ;
}
STATIC int
F_155 (
struct V_1 * log ,
struct V_169 * V_147 ,
T_6 V_212 )
{
int error ;
struct V_185 * V_25 = log -> V_7 ;
struct V_411 * V_412 ;
struct V_413 * V_414 ;
V_414 = V_147 -> V_156 [ 0 ] . V_157 ;
V_412 = F_156 ( V_25 , V_414 -> V_415 ) ;
error = F_157 ( & V_147 -> V_156 [ 0 ] , & V_412 -> V_416 ) ;
if ( error ) {
F_158 ( V_412 ) ;
return error ;
}
F_159 ( & V_412 -> V_417 , V_414 -> V_415 ) ;
F_160 ( & log -> V_418 -> V_419 ) ;
F_161 ( log -> V_418 , & V_412 -> V_420 , V_212 ) ;
F_162 ( V_412 ) ;
return 0 ;
}
STATIC int
F_163 (
struct V_1 * log ,
struct V_169 * V_147 )
{
T_16 * V_421 ;
T_17 * V_412 = NULL ;
T_18 * V_422 ;
T_19 V_423 ;
struct V_424 V_425 ;
struct V_426 * V_427 = log -> V_418 ;
V_421 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( ( V_147 -> V_156 [ 0 ] . V_205 == ( sizeof( V_428 ) +
( ( V_421 -> V_429 - 1 ) * sizeof( V_430 ) ) ) ) ||
( V_147 -> V_156 [ 0 ] . V_205 == ( sizeof( V_431 ) +
( ( V_421 -> V_429 - 1 ) * sizeof( V_432 ) ) ) ) ) ;
V_423 = V_421 -> V_433 ;
F_160 ( & V_427 -> V_419 ) ;
V_422 = F_164 ( V_427 , & V_425 , 0 ) ;
while ( V_422 != NULL ) {
if ( V_422 -> V_434 == V_168 ) {
V_412 = ( T_17 * ) V_422 ;
if ( V_412 -> V_416 . V_423 == V_423 ) {
F_165 ( & V_427 -> V_419 ) ;
F_162 ( V_412 ) ;
F_160 ( & V_427 -> V_419 ) ;
break;
}
}
V_422 = F_166 ( V_427 , & V_425 ) ;
}
F_167 ( & V_425 ) ;
F_165 ( & V_427 -> V_419 ) ;
return 0 ;
}
STATIC int
F_168 (
struct V_1 * log ,
struct V_170 * V_151 ,
T_7 * V_147 )
{
struct V_185 * V_25 = log -> V_7 ;
struct V_435 * V_436 ;
T_20 V_437 ;
T_21 V_438 ;
unsigned int V_75 ;
unsigned int V_357 ;
T_21 V_439 ;
int V_440 ;
int V_441 ;
int V_442 ;
int V_443 ;
int V_47 ;
V_436 = (struct V_435 * ) V_147 -> V_156 [ 0 ] . V_157 ;
if ( V_436 -> V_444 != V_158 ) {
F_3 ( log -> V_7 , L_68 ) ;
return - V_124 ;
}
if ( V_436 -> V_445 != 1 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_124 ;
}
V_437 = F_28 ( V_436 -> V_446 ) ;
if ( V_437 >= V_25 -> V_27 . V_447 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_124 ;
}
V_438 = F_28 ( V_436 -> V_448 ) ;
if ( ! V_438 || V_438 == V_449 || V_438 >= V_25 -> V_27 . V_450 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_124 ;
}
V_357 = F_28 ( V_436 -> V_451 ) ;
if ( V_357 != V_25 -> V_27 . V_199 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_124 ;
}
V_75 = F_28 ( V_436 -> V_452 ) ;
if ( ! V_75 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_124 ;
}
V_439 = F_28 ( V_436 -> V_453 ) ;
if ( ! V_439 || V_439 >= V_25 -> V_27 . V_450 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_124 ;
}
if ( V_439 != V_25 -> V_454 &&
V_439 != V_25 -> V_455 ) {
F_3 ( log -> V_7 ,
L_75 , V_456 ) ;
return - V_124 ;
}
if ( ( V_75 >> V_25 -> V_27 . V_457 ) != V_439 ) {
F_3 ( log -> V_7 ,
L_76 ,
V_456 ) ;
return - V_124 ;
}
V_440 = F_169 ( V_25 ) ;
V_441 = F_153 ( V_25 , V_440 ) ;
V_443 = V_439 / V_440 ;
for ( V_47 = 0 , V_442 = 0 ; V_47 < V_443 ; V_47 ++ ) {
T_2 V_458 ;
V_458 = F_170 ( V_25 , V_437 ,
V_438 + V_47 * V_440 ) ;
if ( F_95 ( log , V_458 , V_441 , 0 ) )
V_442 ++ ;
}
ASSERT ( ! V_442 || V_442 == V_443 ) ;
if ( V_442 ) {
if ( V_442 != V_443 )
F_3 ( V_25 ,
L_77 ) ;
F_171 ( log , V_436 ) ;
return 0 ;
}
F_172 ( log , V_436 ) ;
return F_173 ( V_25 , NULL , V_151 , V_75 , V_437 , V_438 ,
V_439 , F_28 ( V_436 -> V_459 ) ) ;
}
STATIC void
F_174 (
struct V_1 * log ,
struct V_169 * V_147 )
{
struct V_319 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
struct V_185 * V_25 = log -> V_7 ;
if ( F_94 ( log , V_155 -> V_174 ,
V_155 -> V_177 , V_155 -> V_161 ) ) {
return;
}
F_175 ( V_25 -> V_328 , V_155 -> V_174 ,
V_155 -> V_177 , NULL ) ;
}
STATIC void
F_176 (
struct V_1 * log ,
struct V_169 * V_147 )
{
struct V_335 V_460 ;
struct V_335 * V_461 ;
struct V_185 * V_25 = log -> V_7 ;
int error ;
if ( V_147 -> V_156 [ 0 ] . V_205 == sizeof( struct V_335 ) ) {
V_461 = V_147 -> V_156 [ 0 ] . V_157 ;
} else {
V_461 = & V_460 ;
memset ( V_461 , 0 , sizeof( * V_461 ) ) ;
error = F_134 ( & V_147 -> V_156 [ 0 ] , V_461 ) ;
if ( error )
return;
}
if ( F_94 ( log , V_461 -> V_359 , V_461 -> V_360 , 0 ) )
return;
F_175 ( V_25 -> V_328 , V_461 -> V_359 ,
V_461 -> V_360 , & V_462 ) ;
}
STATIC void
F_177 (
struct V_1 * log ,
struct V_169 * V_147 )
{
struct V_185 * V_25 = log -> V_7 ;
struct V_397 * V_399 ;
struct V_463 * V_400 ;
T_5 type ;
int V_182 ;
if ( V_25 -> V_320 == 0 )
return;
V_399 = V_147 -> V_156 [ 1 ] . V_157 ;
if ( V_399 == NULL )
return;
if ( V_147 -> V_156 [ 1 ] . V_205 < sizeof( struct V_397 ) )
return;
type = V_399 -> V_401 & ( V_321 | V_322 | V_323 ) ;
ASSERT ( type ) ;
if ( log -> V_324 & type )
return;
V_400 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_400 ) ;
ASSERT ( V_400 -> V_403 == 1 ) ;
V_182 = F_153 ( V_25 , V_400 -> V_403 ) ;
if ( F_94 ( log , V_400 -> V_404 , V_182 , 0 ) )
return;
F_175 ( V_25 -> V_328 , V_400 -> V_404 , V_182 ,
& V_464 ) ;
}
STATIC void
F_178 (
struct V_1 * log ,
struct V_169 * V_147 )
{
switch ( F_78 ( V_147 ) ) {
case V_160 :
F_174 ( log , V_147 ) ;
break;
case V_164 :
F_176 ( log , V_147 ) ;
break;
case V_165 :
F_177 ( log , V_147 ) ;
break;
case V_168 :
case V_167 :
case V_166 :
default:
break;
}
}
STATIC int
F_179 (
struct V_1 * log ,
struct V_144 * V_145 ,
struct V_169 * V_147 )
{
F_180 ( log , V_145 , V_147 , V_465 ) ;
switch ( F_78 ( V_147 ) ) {
case V_160 :
return F_86 ( log , V_147 ) ;
case V_166 :
return F_150 ( log , V_147 ) ;
case V_164 :
case V_168 :
case V_167 :
case V_165 :
case V_158 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_78 ( V_147 ) ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
}
STATIC int
F_181 (
struct V_1 * log ,
struct V_144 * V_145 ,
struct V_170 * V_151 ,
struct V_169 * V_147 )
{
F_180 ( log , V_145 , V_147 , V_466 ) ;
switch ( F_78 ( V_147 ) ) {
case V_160 :
return F_119 ( log , V_151 , V_147 ,
V_145 -> V_467 ) ;
case V_164 :
return F_133 ( log , V_151 , V_147 ,
V_145 -> V_467 ) ;
case V_168 :
return F_155 ( log , V_147 , V_145 -> V_467 ) ;
case V_167 :
return F_163 ( log , V_147 ) ;
case V_165 :
return F_151 ( log , V_151 , V_147 ,
V_145 -> V_467 ) ;
case V_158 :
return F_168 ( log , V_151 , V_147 ) ;
case V_166 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_78 ( V_147 ) ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
}
STATIC int
F_182 (
struct V_1 * log ,
struct V_144 * V_145 ,
struct V_170 * V_151 ,
struct V_170 * V_468 )
{
struct V_169 * V_147 ;
int error = 0 ;
F_89 (item, item_list, ri_list) {
error = F_181 ( log , V_145 ,
V_151 , V_147 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_183 (
struct V_1 * log ,
struct V_144 * V_145 ,
int V_146 )
{
int error = 0 ;
int V_24 ;
int V_469 = 0 ;
struct V_169 * V_147 ;
struct V_169 * V_315 ;
F_75 ( V_151 ) ;
F_75 ( V_470 ) ;
F_75 ( V_471 ) ;
#define F_184 100
F_185 ( & V_145 -> V_472 ) ;
error = F_74 ( log , V_145 , V_146 ) ;
if ( error )
return error ;
F_77 (item, next, &trans->r_itemq, ri_list) {
switch ( V_146 ) {
case V_465 :
error = F_179 ( log , V_145 , V_147 ) ;
break;
case V_466 :
F_178 ( log , V_147 ) ;
F_79 ( & V_147 -> V_159 , & V_470 ) ;
V_469 ++ ;
if ( V_469 >= F_184 ) {
error = F_182 ( log , V_145 ,
& V_151 , & V_470 ) ;
F_186 ( & V_470 , & V_471 ) ;
V_469 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_53;
}
V_53:
if ( ! F_83 ( & V_470 ) ) {
if ( ! error )
error = F_182 ( log , V_145 ,
& V_151 , & V_470 ) ;
F_186 ( & V_470 , & V_471 ) ;
}
if ( ! F_83 ( & V_471 ) )
F_76 ( & V_471 , & V_145 -> V_154 ) ;
V_24 = F_187 ( & V_151 ) ;
return error ? error : V_24 ;
}
STATIC void
F_188 (
struct V_170 * V_26 )
{
T_7 * V_147 ;
V_147 = F_189 ( sizeof( T_7 ) , V_179 ) ;
F_190 ( & V_147 -> V_159 ) ;
F_92 ( & V_147 -> V_159 , V_26 ) ;
}
STATIC int
F_191 (
struct V_1 * log ,
struct V_144 * V_145 ,
char * V_473 ,
int V_182 )
{
T_7 * V_147 ;
char * V_474 , * V_475 ;
int V_476 ;
if ( F_83 ( & V_145 -> V_154 ) ) {
ASSERT ( V_182 <= sizeof( struct V_477 ) ) ;
if ( V_182 > sizeof( struct V_477 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
return - V_60 ;
}
F_188 ( & V_145 -> V_154 ) ;
V_474 = ( char * ) & V_145 -> V_478 +
sizeof( struct V_477 ) - V_182 ;
memcpy ( V_474 , V_473 , V_182 ) ;
return 0 ;
}
V_147 = F_192 ( V_145 -> V_154 . V_479 , T_7 , V_159 ) ;
V_475 = V_147 -> V_156 [ V_147 -> V_480 - 1 ] . V_157 ;
V_476 = V_147 -> V_156 [ V_147 -> V_480 - 1 ] . V_205 ;
V_474 = F_193 ( V_475 , V_182 + V_476 , V_179 ) ;
memcpy ( & V_474 [ V_476 ] , V_473 , V_182 ) ;
V_147 -> V_156 [ V_147 -> V_480 - 1 ] . V_205 += V_182 ;
V_147 -> V_156 [ V_147 -> V_480 - 1 ] . V_157 = V_474 ;
F_194 ( log , V_145 , V_147 , 0 ) ;
return 0 ;
}
STATIC int
F_195 (
struct V_1 * log ,
struct V_144 * V_145 ,
char * V_473 ,
int V_182 )
{
T_13 * V_336 ;
T_7 * V_147 ;
char * V_474 ;
if ( ! V_182 )
return 0 ;
if ( F_83 ( & V_145 -> V_154 ) ) {
if ( * ( T_5 * ) V_473 != V_481 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
if ( V_182 > sizeof( struct V_477 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
if ( V_182 == sizeof( struct V_477 ) )
F_188 ( & V_145 -> V_154 ) ;
memcpy ( & V_145 -> V_478 , V_473 , V_182 ) ;
return 0 ;
}
V_474 = F_91 ( V_182 , V_179 ) ;
memcpy ( V_474 , V_473 , V_182 ) ;
V_336 = ( T_13 * ) V_474 ;
V_147 = F_192 ( V_145 -> V_154 . V_479 , T_7 , V_159 ) ;
if ( V_147 -> V_318 != 0 &&
V_147 -> V_318 == V_147 -> V_480 ) {
F_188 ( & V_145 -> V_154 ) ;
V_147 = F_192 ( V_145 -> V_154 . V_479 ,
T_7 , V_159 ) ;
}
if ( V_147 -> V_318 == 0 ) {
if ( V_336 -> V_382 == 0 ||
V_336 -> V_382 > V_482 ) {
F_3 ( log -> V_7 ,
L_81 ,
V_336 -> V_382 ) ;
ASSERT ( 0 ) ;
F_97 ( V_474 ) ;
return - V_60 ;
}
V_147 -> V_318 = V_336 -> V_382 ;
V_147 -> V_156 =
F_189 ( V_147 -> V_318 * sizeof( V_483 ) ,
V_179 ) ;
}
ASSERT ( V_147 -> V_318 > V_147 -> V_480 ) ;
V_147 -> V_156 [ V_147 -> V_480 ] . V_157 = V_474 ;
V_147 -> V_156 [ V_147 -> V_480 ] . V_205 = V_182 ;
V_147 -> V_480 ++ ;
F_196 ( log , V_145 , V_147 , 0 ) ;
return 0 ;
}
STATIC void
F_197 (
struct V_144 * V_145 )
{
T_7 * V_147 , * V_148 ;
int V_47 ;
F_77 (item, n, &trans->r_itemq, ri_list) {
F_96 ( & V_147 -> V_159 ) ;
for ( V_47 = 0 ; V_47 < V_147 -> V_480 ; V_47 ++ )
F_97 ( V_147 -> V_156 [ V_47 ] . V_157 ) ;
F_97 ( V_147 -> V_156 ) ;
F_97 ( V_147 ) ;
}
F_97 ( V_145 ) ;
}
STATIC int
F_198 (
struct V_1 * log ,
struct V_144 * V_145 ,
char * V_473 ,
unsigned int V_182 ,
unsigned int V_183 ,
int V_146 )
{
int error = 0 ;
bool V_484 = false ;
V_183 &= ~ V_485 ;
if ( V_183 & V_486 )
V_183 &= ~ V_487 ;
switch ( V_183 ) {
case 0 :
case V_487 :
error = F_195 ( log , V_145 , V_473 , V_182 ) ;
break;
case V_486 :
error = F_191 ( log , V_145 , V_473 , V_182 ) ;
break;
case V_488 :
error = F_183 ( log , V_145 , V_146 ) ;
V_484 = true ;
break;
case V_105 :
F_3 ( log -> V_7 , L_82 , V_8 ) ;
V_484 = true ;
break;
case V_489 :
default:
F_3 ( log -> V_7 , L_83 , V_8 , V_183 ) ;
ASSERT ( 0 ) ;
error = - V_60 ;
break;
}
if ( error || V_484 )
F_197 ( V_145 ) ;
return error ;
}
STATIC struct V_144 *
F_199 (
struct V_490 V_491 [] ,
struct V_77 * V_78 ,
struct V_96 * V_492 )
{
struct V_144 * V_145 ;
T_22 V_493 ;
struct V_490 * V_494 ;
V_493 = F_28 ( V_492 -> V_495 ) ;
V_494 = & V_491 [ F_200 ( V_493 ) ] ;
F_201 (trans, rhp, r_list) {
if ( V_145 -> V_496 == V_493 )
return V_145 ;
}
if ( ! ( V_492 -> V_104 & V_489 ) )
return NULL ;
ASSERT ( F_28 ( V_492 -> V_497 ) == 0 ) ;
V_145 = F_189 ( sizeof( struct V_144 ) , V_179 ) ;
V_145 -> V_496 = V_493 ;
V_145 -> V_467 = F_57 ( V_78 -> V_113 ) ;
F_190 ( & V_145 -> V_154 ) ;
F_202 ( & V_145 -> V_472 ) ;
F_203 ( & V_145 -> V_472 , V_494 ) ;
return NULL ;
}
STATIC int
F_204 (
struct V_1 * log ,
struct V_490 V_491 [] ,
struct V_77 * V_78 ,
struct V_96 * V_492 ,
char * V_473 ,
char * V_498 ,
int V_146 )
{
struct V_144 * V_145 ;
unsigned int V_182 ;
if ( V_492 -> V_499 != V_500 &&
V_492 -> V_499 != V_501 ) {
F_3 ( log -> V_7 , L_84 ,
V_8 , V_492 -> V_499 ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
V_182 = F_28 ( V_492 -> V_497 ) ;
if ( V_473 + V_182 > V_498 ) {
F_3 ( log -> V_7 , L_85 , V_8 , V_182 ) ;
F_205 ( 1 ) ;
return - V_60 ;
}
V_145 = F_199 ( V_491 , V_78 , V_492 ) ;
if ( ! V_145 ) {
return 0 ;
}
return F_198 ( log , V_145 , V_473 , V_182 ,
V_492 -> V_104 , V_146 ) ;
}
STATIC int
F_206 (
struct V_1 * log ,
struct V_490 V_491 [] ,
struct V_77 * V_78 ,
char * V_473 ,
int V_146 )
{
struct V_96 * V_492 ;
char * V_498 ;
int V_502 ;
int error ;
V_498 = V_473 + F_28 ( V_78 -> V_63 ) ;
V_502 = F_28 ( V_78 -> V_103 ) ;
if ( F_29 ( log -> V_7 , V_78 ) )
return - V_60 ;
while ( ( V_473 < V_498 ) && V_502 ) {
V_492 = (struct V_96 * ) V_473 ;
V_473 += sizeof( * V_492 ) ;
ASSERT ( V_473 <= V_498 ) ;
error = F_204 ( log , V_491 , V_78 , V_492 ,
V_473 , V_498 , V_146 ) ;
if ( error )
return error ;
V_473 += F_28 ( V_492 -> V_497 ) ;
V_502 -- ;
}
return 0 ;
}
STATIC int
F_207 (
T_3 * V_25 ,
T_17 * V_412 )
{
T_23 * V_503 ;
T_24 * V_504 ;
int V_47 ;
int error = 0 ;
T_25 * V_505 ;
T_26 V_506 ;
ASSERT ( ! F_208 ( V_507 , & V_412 -> V_508 ) ) ;
for ( V_47 = 0 ; V_47 < V_412 -> V_416 . V_415 ; V_47 ++ ) {
V_505 = & ( V_412 -> V_416 . V_509 [ V_47 ] ) ;
V_506 = F_209 ( V_25 ,
F_210 ( V_25 , V_505 -> V_510 ) ) ;
if ( ( V_506 == 0 ) ||
( V_505 -> V_511 == 0 ) ||
( V_506 >= V_25 -> V_27 . V_512 ) ||
( V_505 -> V_511 >= V_25 -> V_27 . V_450 ) ) {
F_211 ( V_507 , & V_412 -> V_508 ) ;
F_162 ( V_412 ) ;
return - V_60 ;
}
}
error = F_212 ( V_25 , & F_213 ( V_25 ) -> V_513 , 0 , 0 , 0 , & V_504 ) ;
if ( error )
return error ;
V_503 = F_214 ( V_504 , V_412 , V_412 -> V_416 . V_415 ) ;
for ( V_47 = 0 ; V_47 < V_412 -> V_416 . V_415 ; V_47 ++ ) {
V_505 = & ( V_412 -> V_416 . V_509 [ V_47 ] ) ;
error = F_215 ( V_504 , V_503 , V_505 -> V_510 ,
V_505 -> V_511 ) ;
if ( error )
goto V_514;
}
F_211 ( V_507 , & V_412 -> V_508 ) ;
error = F_216 ( V_504 ) ;
return error ;
V_514:
F_217 ( V_504 ) ;
return error ;
}
STATIC int
F_218 (
struct V_1 * log )
{
struct V_515 * V_422 ;
struct V_411 * V_412 ;
int error = 0 ;
struct V_424 V_425 ;
struct V_426 * V_427 ;
V_427 = log -> V_418 ;
F_160 ( & V_427 -> V_419 ) ;
V_422 = F_164 ( V_427 , & V_425 , 0 ) ;
while ( V_422 != NULL ) {
if ( V_422 -> V_434 != V_168 ) {
#ifdef F_219
for (; V_422 ; V_422 = F_166 ( V_427 , & V_425 ) )
ASSERT ( V_422 -> V_434 != V_168 ) ;
#endif
break;
}
V_412 = F_220 ( V_422 , struct V_411 , V_420 ) ;
if ( F_208 ( V_507 , & V_412 -> V_508 ) ) {
V_422 = F_166 ( V_427 , & V_425 ) ;
continue;
}
F_165 ( & V_427 -> V_419 ) ;
error = F_207 ( log -> V_7 , V_412 ) ;
F_160 ( & V_427 -> V_419 ) ;
if ( error )
goto V_53;
V_422 = F_166 ( V_427 , & V_425 ) ;
}
V_53:
F_167 ( & V_425 ) ;
F_165 ( & V_427 -> V_419 ) ;
return error ;
}
STATIC int
F_221 (
struct V_1 * log )
{
struct V_515 * V_422 ;
struct V_411 * V_412 ;
int error = 0 ;
struct V_424 V_425 ;
struct V_426 * V_427 ;
V_427 = log -> V_418 ;
F_160 ( & V_427 -> V_419 ) ;
V_422 = F_164 ( V_427 , & V_425 , 0 ) ;
while ( V_422 != NULL ) {
if ( V_422 -> V_434 != V_168 ) {
#ifdef F_219
for (; V_422 ; V_422 = F_166 ( V_427 , & V_425 ) )
ASSERT ( V_422 -> V_434 != V_168 ) ;
#endif
break;
}
V_412 = F_220 ( V_422 , struct V_411 , V_420 ) ;
F_165 ( & V_427 -> V_419 ) ;
F_162 ( V_412 ) ;
F_160 ( & V_427 -> V_419 ) ;
V_422 = F_166 ( V_427 , & V_425 ) ;
}
F_167 ( & V_425 ) ;
F_165 ( & V_427 -> V_419 ) ;
return error ;
}
STATIC void
F_222 (
T_3 * V_25 ,
T_20 V_437 ,
int V_171 )
{
T_24 * V_504 ;
T_27 * V_516 ;
T_1 * V_517 ;
int V_13 ;
int error ;
error = F_212 ( V_25 , & F_213 ( V_25 ) -> V_518 , 0 , 0 , 0 , & V_504 ) ;
if ( error )
goto V_81;
error = F_223 ( V_25 , V_504 , V_437 , & V_517 ) ;
if ( error )
goto V_519;
V_516 = F_224 ( V_517 ) ;
V_516 -> V_520 [ V_171 ] = F_30 ( V_521 ) ;
V_13 = F_101 ( T_27 , V_520 ) +
( sizeof( T_10 ) * V_171 ) ;
F_225 ( V_504 , V_517 , V_13 ,
( V_13 + sizeof( T_10 ) - 1 ) ) ;
error = F_216 ( V_504 ) ;
if ( error )
goto V_81;
return;
V_519:
F_217 ( V_504 ) ;
V_81:
F_3 ( V_25 , L_86 , V_8 , V_437 ) ;
return;
}
STATIC T_10
F_226 (
struct V_185 * V_25 ,
T_20 V_437 ,
T_10 V_522 ,
int V_171 )
{
struct V_5 * V_523 ;
struct V_333 * V_334 ;
struct V_337 * V_338 ;
T_28 V_524 ;
int error ;
V_524 = F_227 ( V_25 , V_437 , V_522 ) ;
error = F_228 ( V_25 , NULL , V_524 , 0 , 0 , & V_338 ) ;
if ( error )
goto V_525;
error = F_229 ( V_25 , NULL , & V_338 -> V_526 , & V_334 , & V_523 , 0 , 0 ) ;
if ( error )
goto V_527;
ASSERT ( F_230 ( V_338 ) -> V_528 == 0 ) ;
ASSERT ( F_230 ( V_338 ) -> V_529 != 0 ) ;
V_522 = F_28 ( V_334 -> V_201 ) ;
F_25 ( V_523 ) ;
V_338 -> V_343 . V_530 = 0 ;
F_231 ( V_338 ) ;
return V_522 ;
V_527:
F_231 ( V_338 ) ;
V_525:
F_222 ( V_25 , V_437 , V_171 ) ;
return V_521 ;
}
STATIC void
F_232 (
struct V_1 * log )
{
T_3 * V_25 ;
T_20 V_437 ;
T_27 * V_516 ;
T_1 * V_517 ;
T_10 V_522 ;
int V_171 ;
int error ;
T_5 V_531 ;
V_25 = log -> V_7 ;
V_531 = V_25 -> V_532 ;
V_25 -> V_532 = 0 ;
for ( V_437 = 0 ; V_437 < V_25 -> V_27 . V_447 ; V_437 ++ ) {
error = F_223 ( V_25 , NULL , V_437 , & V_517 ) ;
if ( error ) {
continue;
}
V_516 = F_224 ( V_517 ) ;
F_7 ( V_517 ) ;
for ( V_171 = 0 ; V_171 < V_533 ; V_171 ++ ) {
V_522 = F_28 ( V_516 -> V_520 [ V_171 ] ) ;
while ( V_522 != V_521 ) {
V_522 = F_226 ( V_25 ,
V_437 , V_522 , V_171 ) ;
}
}
F_233 ( V_517 ) ;
}
V_25 -> V_532 = V_531 ;
}
STATIC int
F_234 (
struct V_77 * V_78 ,
char * V_473 ,
struct V_1 * log )
{
int V_47 , V_48 , V_534 ;
for ( V_47 = 0 ; V_47 < F_46 ( F_28 ( V_78 -> V_63 ) ) &&
V_47 < ( V_62 / V_54 ) ; V_47 ++ ) {
* ( V_82 * ) V_473 = * ( V_82 * ) & V_78 -> V_535 [ V_47 ] ;
V_473 += V_54 ;
}
if ( F_45 ( & log -> V_7 -> V_27 ) ) {
T_29 * V_536 = ( T_29 * ) V_78 ;
for ( ; V_47 < F_46 ( F_28 ( V_78 -> V_63 ) ) ; V_47 ++ ) {
V_48 = V_47 / ( V_62 / V_54 ) ;
V_534 = V_47 % ( V_62 / V_54 ) ;
* ( V_82 * ) V_473 = V_536 [ V_48 ] . V_537 . V_538 [ V_534 ] ;
V_473 += V_54 ;
}
}
return 0 ;
}
STATIC int
F_235 (
struct V_1 * log ,
struct V_490 V_491 [] ,
struct V_77 * V_78 ,
char * V_473 ,
int V_146 )
{
int error ;
T_30 V_539 ;
V_539 = F_236 ( log , V_78 , V_473 , F_28 ( V_78 -> V_63 ) ) ;
if ( V_146 == V_87 ) {
if ( V_78 -> V_540 && V_539 != V_78 -> V_540 )
return - V_93 ;
return 0 ;
}
if ( V_539 != V_78 -> V_540 ) {
if ( V_78 -> V_540 || F_100 ( & log -> V_7 -> V_27 ) ) {
F_104 ( log -> V_7 ,
L_87 ,
F_237 ( V_78 -> V_540 ) ,
F_237 ( V_539 ) ) ;
F_238 ( V_473 , 32 ) ;
}
if ( F_100 ( & log -> V_7 -> V_27 ) )
return - V_16 ;
}
error = F_234 ( V_78 , V_473 , log ) ;
if ( error )
return error ;
return F_206 ( log , V_491 , V_78 , V_473 , V_146 ) ;
}
STATIC int
F_239 (
struct V_1 * log ,
struct V_77 * V_78 ,
T_2 V_181 )
{
int V_541 ;
if ( F_31 ( V_78 -> V_32 != F_30 ( V_33 ) ) ) {
F_4 ( L_88 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 (
( ! V_78 -> V_101 ||
( F_28 ( V_78 -> V_101 ) & ( ~ V_542 ) ) ) ) ) {
F_3 ( log -> V_7 , L_89 ,
V_8 , F_28 ( V_78 -> V_101 ) ) ;
return - V_60 ;
}
V_541 = F_28 ( V_78 -> V_63 ) ;
if ( F_31 ( V_541 <= 0 || V_541 > V_72 ) ) {
F_4 ( L_90 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 ( V_181 > log -> V_3 || V_181 > V_72 ) ) {
F_4 ( L_91 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_54 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 ,
int V_146 ,
T_2 * V_84 )
{
T_4 * V_78 ;
T_2 V_12 ;
T_2 V_88 ;
char * V_13 ;
T_1 * V_543 , * V_544 ;
int error = 0 , V_61 , V_63 ;
int V_545 , V_546 ;
int V_100 , V_547 , V_548 ;
struct V_490 V_491 [ V_549 ] ;
ASSERT ( V_65 != V_74 ) ;
V_88 = 0 ;
if ( F_45 ( & log -> V_7 -> V_27 ) ) {
V_543 = F_2 ( log , 1 ) ;
if ( ! V_543 )
return - V_51 ;
error = F_18 ( log , V_74 , 1 , V_543 , & V_13 ) ;
if ( error )
goto V_550;
V_78 = ( T_4 * ) V_13 ;
error = F_239 ( log , V_78 , V_74 ) ;
if ( error )
goto V_550;
V_61 = F_28 ( V_78 -> V_61 ) ;
V_63 = F_28 ( V_78 -> V_63 ) ;
if ( V_63 > V_61 ) {
if ( V_63 <= log -> V_7 -> V_551 &&
F_28 ( V_78 -> V_103 ) == 1 ) {
F_3 ( log -> V_7 ,
L_92 ,
V_61 , log -> V_7 -> V_551 ) ;
V_61 = log -> V_7 -> V_551 ;
} else
return - V_16 ;
}
if ( ( F_28 ( V_78 -> V_101 ) & V_102 ) &&
( V_61 > V_62 ) ) {
V_100 = V_61 / V_62 ;
if ( V_61 % V_62 )
V_100 ++ ;
F_8 ( V_543 ) ;
V_543 = F_2 ( log , V_100 ) ;
} else {
V_100 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_100 = 1 ;
V_543 = F_2 ( log , 1 ) ;
V_61 = V_552 ;
}
if ( ! V_543 )
return - V_51 ;
V_544 = F_2 ( log , F_46 ( V_61 ) ) ;
if ( ! V_544 ) {
F_8 ( V_543 ) ;
return - V_51 ;
}
memset ( V_491 , 0 , sizeof( V_491 ) ) ;
V_12 = V_88 = V_74 ;
if ( V_74 > V_65 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_543 -> V_15 ;
V_547 = 0 ;
V_548 = 0 ;
if ( V_12 + V_100 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_100 , V_543 ,
& V_13 ) ;
if ( error )
goto V_553;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_72 ) ;
V_547 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_547 > 0 ) ;
error = F_18 ( log , V_12 ,
V_547 , V_543 ,
& V_13 ) ;
if ( error )
goto V_553;
}
V_548 = V_100 - V_547 ;
error = F_19 ( log , 0 ,
V_548 , V_543 ,
V_13 + F_11 ( V_547 ) ) ;
if ( error )
goto V_553;
}
V_78 = ( T_4 * ) V_13 ;
error = F_239 ( log , V_78 ,
V_547 ? V_12 : 0 ) ;
if ( error )
goto V_553;
V_545 = ( int ) F_46 ( F_28 ( V_78 -> V_63 ) ) ;
V_12 += V_100 ;
if ( V_12 + V_545 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_545 , V_544 ,
& V_13 ) ;
if ( error )
goto V_553;
} else {
V_13 = V_544 -> V_15 ;
V_546 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_548 ) ;
ASSERT ( V_12 <= V_72 ) ;
V_546 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_546 > 0 ) ;
error = F_18 ( log , V_12 ,
V_546 , V_544 ,
& V_13 ) ;
if ( error )
goto V_553;
}
error = F_19 ( log , 0 ,
V_545 - V_546 , V_544 ,
V_13 + F_11 ( V_546 ) ) ;
if ( error )
goto V_553;
}
error = F_235 ( log , V_491 , V_78 , V_13 ,
V_146 ) ;
if ( error )
goto V_553;
V_12 += V_545 ;
V_88 = V_12 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
V_88 = V_12 ;
}
while ( V_12 < V_65 ) {
error = F_18 ( log , V_12 , V_100 , V_543 , & V_13 ) ;
if ( error )
goto V_553;
V_78 = ( T_4 * ) V_13 ;
error = F_239 ( log , V_78 , V_12 ) ;
if ( error )
goto V_553;
V_545 = ( int ) F_46 ( F_28 ( V_78 -> V_63 ) ) ;
error = F_18 ( log , V_12 + V_100 , V_545 , V_544 ,
& V_13 ) ;
if ( error )
goto V_553;
error = F_235 ( log , V_491 , V_78 , V_13 , V_146 ) ;
if ( error )
goto V_553;
V_12 += V_545 + V_100 ;
V_88 = V_12 ;
}
V_553:
F_8 ( V_544 ) ;
V_550:
F_8 ( V_543 ) ;
if ( error && V_84 )
* V_84 = V_88 ;
return error ;
}
STATIC int
F_240 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 )
{
int error , V_47 ;
ASSERT ( V_65 != V_74 ) ;
log -> V_184 = F_189 ( V_554 *
sizeof( struct V_170 ) ,
V_179 ) ;
for ( V_47 = 0 ; V_47 < V_554 ; V_47 ++ )
F_190 ( & log -> V_184 [ V_47 ] ) ;
error = F_54 ( log , V_65 , V_74 ,
V_465 , NULL ) ;
if ( error != 0 ) {
F_97 ( log -> V_184 ) ;
log -> V_184 = NULL ;
return error ;
}
error = F_54 ( log , V_65 , V_74 ,
V_466 , NULL ) ;
#ifdef F_219
if ( ! error ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_554 ; V_47 ++ )
ASSERT ( F_83 ( & log -> V_184 [ V_47 ] ) ) ;
}
#endif
F_97 ( log -> V_184 ) ;
log -> V_184 = NULL ;
return error ;
}
STATIC int
F_241 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 )
{
struct V_185 * V_25 = log -> V_7 ;
int error ;
T_1 * V_6 ;
T_31 * V_555 ;
error = F_240 ( log , V_65 , V_74 ) ;
if ( error )
return error ;
if ( F_16 ( V_25 ) ) {
return - V_60 ;
}
F_242 ( V_25 ) ;
V_6 = F_243 ( V_25 , 0 ) ;
V_6 -> V_18 &= ~ ( V_556 | V_557 ) ;
ASSERT ( ! ( V_6 -> V_18 & V_558 ) ) ;
V_6 -> V_18 |= V_19 ;
V_6 -> V_196 = & V_308 ;
error = F_15 ( V_6 ) ;
if ( error ) {
if ( ! F_16 ( V_25 ) ) {
F_17 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_25 ( V_6 ) ;
return error ;
}
V_555 = & V_25 -> V_27 ;
F_244 ( V_555 , F_245 ( V_6 ) ) ;
F_25 ( V_6 ) ;
F_246 ( V_25 ) ;
error = F_247 ( V_25 , V_555 -> V_447 , & V_25 -> V_559 ) ;
if ( error ) {
F_3 ( V_25 , L_93 , error ) ;
return error ;
}
F_248 ( log ) ;
log -> V_560 &= ~ V_561 ;
return 0 ;
}
int
V_144 (
struct V_1 * log )
{
T_2 V_65 , V_74 ;
int error ;
error = F_64 ( log , & V_65 , & V_74 ) ;
if ( error )
return error ;
if ( F_100 ( & log -> V_7 -> V_27 ) &&
! F_249 ( log -> V_7 , log -> V_7 -> V_27 . V_252 ) )
return - V_124 ;
if ( V_74 != V_65 ) {
if ( ( error = F_250 ( log -> V_7 , L_94 ) ) ) {
return error ;
}
if ( F_251 ( & log -> V_7 -> V_27 ) == V_562 &&
F_252 ( & log -> V_7 -> V_27 ,
V_563 ) ) {
F_3 ( log -> V_7 ,
L_95 ,
( log -> V_7 -> V_27 . V_564 &
V_563 ) ) ;
F_3 ( log -> V_7 ,
L_96 ) ;
F_3 ( log -> V_7 ,
L_97 ) ;
return - V_124 ;
}
if ( V_565 . V_566 ) {
F_253 ( log -> V_7 ,
L_98 ,
V_565 . V_566 ) ;
F_254 ( V_565 . V_566 * 1000 ) ;
}
F_253 ( log -> V_7 , L_99 ,
log -> V_7 -> V_567 ? log -> V_7 -> V_567
: L_100 ) ;
error = F_241 ( log , V_65 , V_74 ) ;
log -> V_560 |= V_568 ;
}
return error ;
}
int
F_255 (
struct V_1 * log )
{
if ( log -> V_560 & V_568 ) {
int error ;
error = F_218 ( log ) ;
if ( error ) {
F_104 ( log -> V_7 , L_101 ) ;
return error ;
}
F_256 ( log -> V_7 , V_569 ) ;
F_232 ( log ) ;
F_248 ( log ) ;
F_253 ( log -> V_7 , L_102 ,
log -> V_7 -> V_567 ? log -> V_7 -> V_567
: L_100 ) ;
log -> V_560 &= ~ V_568 ;
} else {
F_257 ( log -> V_7 , L_103 ) ;
}
return 0 ;
}
int
F_258 (
struct V_1 * log )
{
int error = 0 ;
if ( log -> V_560 & V_568 )
error = F_221 ( log ) ;
return error ;
}
void
F_248 (
struct V_1 * log )
{
T_3 * V_25 ;
T_32 * V_570 ;
T_1 * V_571 ;
T_1 * V_517 ;
T_20 V_437 ;
T_19 V_572 ;
T_19 V_573 ;
T_19 V_574 ;
int error ;
V_25 = log -> V_7 ;
V_572 = 0LL ;
V_573 = 0LL ;
V_574 = 0LL ;
for ( V_437 = 0 ; V_437 < V_25 -> V_27 . V_447 ; V_437 ++ ) {
error = F_259 ( V_25 , NULL , V_437 , 0 , & V_571 ) ;
if ( error ) {
F_104 ( V_25 , L_104 ,
V_8 , V_437 , error ) ;
} else {
V_570 = F_260 ( V_571 ) ;
V_572 += F_28 ( V_570 -> V_575 ) +
F_28 ( V_570 -> V_576 ) ;
F_25 ( V_571 ) ;
}
error = F_223 ( V_25 , NULL , V_437 , & V_517 ) ;
if ( error ) {
F_104 ( V_25 , L_105 ,
V_8 , V_437 , error ) ;
} else {
struct V_238 * V_516 = F_224 ( V_517 ) ;
V_573 += F_28 ( V_516 -> V_577 ) ;
V_574 += F_28 ( V_516 -> V_578 ) ;
F_25 ( V_517 ) ;
}
}
}
