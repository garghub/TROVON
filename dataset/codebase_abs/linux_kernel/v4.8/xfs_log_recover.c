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
case V_169 :
case V_170 :
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
struct V_171 * V_147 )
{
T_8 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
if ( ! ( V_155 -> V_161 & V_162 ) ) {
F_87 ( log , V_155 ) ;
return 0 ;
}
V_173 = F_88 ( log , V_155 -> V_176 ) ;
F_89 (bcp, bucket, bc_list) {
if ( V_175 -> V_177 == V_155 -> V_176 &&
V_175 -> V_178 == V_155 -> V_179 ) {
V_175 -> V_180 ++ ;
F_90 ( log , V_155 ) ;
return 0 ;
}
}
V_175 = F_91 ( sizeof( struct V_174 ) , V_181 ) ;
V_175 -> V_177 = V_155 -> V_176 ;
V_175 -> V_178 = V_155 -> V_179 ;
V_175 -> V_180 = 1 ;
F_92 ( & V_175 -> V_182 , V_173 ) ;
F_93 ( log , V_155 ) ;
return 0 ;
}
STATIC struct V_174 *
F_94 (
struct V_1 * log ,
T_2 V_183 ,
T_5 V_184 ,
T_9 V_185 )
{
struct V_172 * V_173 ;
struct V_174 * V_175 ;
if ( ! log -> V_186 ) {
ASSERT ( ! ( V_185 & V_162 ) ) ;
return NULL ;
}
V_173 = F_88 ( log , V_183 ) ;
F_89 (bcp, bucket, bc_list) {
if ( V_175 -> V_177 == V_183 && V_175 -> V_178 == V_184 )
return V_175 ;
}
ASSERT ( ! ( V_185 & V_162 ) ) ;
return NULL ;
}
STATIC int
F_95 (
struct V_1 * log ,
T_2 V_183 ,
T_5 V_184 ,
T_9 V_185 )
{
struct V_174 * V_175 ;
V_175 = F_94 ( log , V_183 , V_184 , V_185 ) ;
if ( ! V_175 )
return 0 ;
if ( V_185 & V_162 ) {
if ( -- V_175 -> V_180 == 0 ) {
F_96 ( & V_175 -> V_182 ) ;
F_97 ( V_175 ) ;
}
}
return 1 ;
}
STATIC int
F_98 (
struct V_187 * V_25 ,
T_7 * V_147 ,
struct V_5 * V_6 ,
T_8 * V_155 )
{
int V_47 ;
int V_188 = 0 ;
int V_189 = 0 ;
int V_190 = 0 ;
int V_191 = 0 ;
int V_192 = 0 ;
int V_193 ;
int V_194 ;
T_10 * V_195 ;
T_10 * V_196 ;
F_99 ( V_25 -> V_197 , V_155 ) ;
if ( F_100 ( & V_25 -> V_27 ) )
V_6 -> V_198 = & V_199 ;
V_194 = F_11 ( V_6 -> V_20 ) >> V_25 -> V_27 . V_200 ;
for ( V_47 = 0 ; V_47 < V_194 ; V_47 ++ ) {
V_193 = ( V_47 * V_25 -> V_27 . V_201 ) +
F_101 ( V_202 , V_203 ) ;
while ( V_193 >=
( V_191 + V_192 ) ) {
V_189 += V_190 ;
V_189 = F_102 ( V_155 -> V_204 ,
V_155 -> V_205 , V_189 ) ;
if ( V_189 == - 1 )
return 0 ;
V_190 = F_103 ( V_155 -> V_204 ,
V_155 -> V_205 , V_189 ) ;
ASSERT ( V_190 > 0 ) ;
V_191 = V_189 << V_206 ;
V_192 = V_190 << V_206 ;
V_188 ++ ;
}
if ( V_193 < V_191 )
continue;
ASSERT ( V_147 -> V_156 [ V_188 ] . V_157 != NULL ) ;
ASSERT ( ( V_147 -> V_156 [ V_188 ] . V_207 % V_208 ) == 0 ) ;
ASSERT ( ( V_191 + V_192 ) <=
F_11 ( V_6 -> V_20 ) ) ;
V_195 = V_147 -> V_156 [ V_188 ] . V_157 +
V_193 - V_191 ;
if ( F_31 ( * V_195 == 0 ) ) {
F_104 ( V_25 ,
L_22
L_23 ,
V_147 , V_6 ) ;
F_4 ( L_24 ,
V_143 , V_25 ) ;
return - V_16 ;
}
V_196 = F_105 ( V_6 , V_193 ) ;
* V_196 = * V_195 ;
F_106 ( V_25 ,
F_105 ( V_6 , V_47 * V_25 -> V_27 . V_201 ) ) ;
}
return 0 ;
}
static T_6
F_107 (
struct V_187 * V_25 ,
struct V_5 * V_6 )
{
T_11 V_209 ;
T_12 V_210 ;
T_12 V_211 ;
void * V_212 = V_6 -> V_15 ;
V_129 * V_213 ;
T_6 V_214 = - 1 ;
if ( ! F_100 ( & V_25 -> V_27 ) )
goto V_215;
V_209 = F_28 ( * ( V_82 * ) V_212 ) ;
switch ( V_209 ) {
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 : {
struct V_223 * V_224 = V_212 ;
V_214 = F_57 ( V_224 -> V_225 . V_226 . V_227 ) ;
V_213 = & V_224 -> V_225 . V_226 . V_228 ;
break;
}
case V_229 :
case V_230 : {
struct V_223 * V_224 = V_212 ;
V_214 = F_57 ( V_224 -> V_225 . V_231 . V_227 ) ;
V_213 = & V_224 -> V_225 . V_231 . V_228 ;
break;
}
case V_232 :
V_214 = F_57 ( ( (struct V_233 * ) V_212 ) -> V_234 ) ;
V_213 = & ( (struct V_233 * ) V_212 ) -> V_235 ;
break;
case V_236 :
V_214 = F_57 ( ( (struct V_237 * ) V_212 ) -> V_238 ) ;
V_213 = & ( (struct V_237 * ) V_212 ) -> V_239 ;
break;
case V_240 :
V_214 = F_57 ( ( (struct V_241 * ) V_212 ) -> V_242 ) ;
V_213 = & ( (struct V_241 * ) V_212 ) -> V_243 ;
break;
case V_244 :
V_214 = F_57 ( ( (struct V_245 * ) V_212 ) -> V_246 ) ;
V_213 = & ( (struct V_245 * ) V_212 ) -> V_247 ;
break;
case V_248 :
case V_249 :
case V_250 :
V_214 = F_57 ( ( (struct V_251 * ) V_212 ) -> V_214 ) ;
V_213 = & ( (struct V_251 * ) V_212 ) -> V_213 ;
break;
case V_252 :
goto V_215;
case V_253 :
V_214 = F_57 ( ( (struct V_254 * ) V_212 ) -> V_255 ) ;
if ( F_108 ( & V_25 -> V_27 ) )
V_213 = & ( (struct V_254 * ) V_212 ) -> V_256 ;
else
V_213 = & ( (struct V_254 * ) V_212 ) -> V_28 ;
break;
default:
break;
}
if ( V_214 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_256 , V_213 ) )
goto V_215;
return V_214 ;
}
V_211 = F_109 ( ( (struct V_257 * ) V_212 ) -> V_258 ) ;
switch ( V_211 ) {
case V_259 :
case V_260 :
case V_261 :
V_214 = F_57 ( ( (struct V_262 * ) V_212 ) -> V_214 ) ;
V_213 = & ( (struct V_262 * ) V_212 ) -> V_213 ;
break;
default:
break;
}
if ( V_214 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_28 , V_213 ) )
goto V_215;
return V_214 ;
}
V_210 = F_109 ( * ( V_263 * ) V_212 ) ;
switch ( V_210 ) {
case V_264 :
case V_265 :
goto V_215;
default:
break;
}
V_215:
return ( T_6 ) - 1 ;
}
static void
F_110 (
struct V_187 * V_25 ,
struct V_5 * V_6 ,
T_8 * V_155 )
{
struct V_257 * V_266 = V_6 -> V_15 ;
T_11 V_209 ;
T_12 V_210 ;
T_12 V_211 ;
if ( ! F_100 ( & V_25 -> V_27 ) )
return;
V_209 = F_28 ( * ( V_82 * ) V_6 -> V_15 ) ;
V_210 = F_109 ( * ( V_263 * ) V_6 -> V_15 ) ;
V_211 = F_109 ( V_266 -> V_258 ) ;
switch ( F_111 ( V_155 ) ) {
case V_267 :
switch ( V_209 ) {
case V_216 :
case V_217 :
case V_218 :
case V_219 :
V_6 -> V_198 = & V_268 ;
break;
case V_221 :
case V_269 :
case V_222 :
case V_270 :
V_6 -> V_198 = & V_271 ;
break;
case V_229 :
case V_230 :
V_6 -> V_198 = & V_272 ;
break;
case V_220 :
V_6 -> V_198 = & V_273 ;
break;
default:
F_3 ( V_25 , L_25 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_274 :
if ( V_209 != V_232 ) {
F_3 ( V_25 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_275 ;
break;
case V_276 :
if ( V_209 != V_236 ) {
F_3 ( V_25 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_277 ;
break;
case V_278 :
if ( V_209 != V_240 ) {
F_3 ( V_25 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_279 ;
break;
case V_280 :
case V_281 :
case V_282 :
#ifdef F_112
if ( V_210 != V_264 ) {
F_3 ( V_25 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_283 ;
#else
F_104 ( V_25 ,
L_30 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_284 :
if ( V_210 != V_265 ) {
F_3 ( V_25 , L_31 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_199 ;
break;
case V_285 :
if ( V_209 != V_244 ) {
F_3 ( V_25 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_286 ;
break;
case V_287 :
if ( V_209 != V_288 &&
V_209 != V_248 ) {
F_3 ( V_25 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_289 ;
break;
case V_290 :
if ( V_209 != V_291 &&
V_209 != V_249 ) {
F_3 ( V_25 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_292 ;
break;
case V_293 :
if ( V_209 != V_294 &&
V_209 != V_250 ) {
F_3 ( V_25 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_295 ;
break;
case V_296 :
if ( V_211 != V_297 &&
V_211 != V_259 ) {
F_3 ( V_25 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_298 ;
break;
case V_299 :
if ( V_211 != V_300 &&
V_211 != V_260 ) {
F_3 ( V_25 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_301 ;
break;
case V_302 :
if ( V_211 != V_303 &&
V_211 != V_261 ) {
F_3 ( V_25 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_304 ;
break;
case V_305 :
if ( V_211 != V_306 &&
V_211 != V_307 ) {
F_3 ( V_25 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_308 ;
break;
case V_309 :
if ( V_209 != V_252 ) {
F_3 ( V_25 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_310 ;
break;
case V_311 :
if ( V_209 != V_253 ) {
F_3 ( V_25 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_198 = & V_312 ;
break;
#ifdef F_113
case V_313 :
case V_314 :
V_6 -> V_198 = & V_315 ;
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
struct V_187 * V_25 ,
T_7 * V_147 ,
struct V_5 * V_6 ,
T_8 * V_155 )
{
int V_47 ;
int V_189 ;
int V_190 ;
int error ;
F_115 ( V_25 -> V_197 , V_155 ) ;
V_189 = 0 ;
V_47 = 1 ;
while ( 1 ) {
V_189 = F_102 ( V_155 -> V_204 ,
V_155 -> V_205 , V_189 ) ;
if ( V_189 == - 1 )
break;
V_190 = F_103 ( V_155 -> V_204 ,
V_155 -> V_205 , V_189 ) ;
ASSERT ( V_190 > 0 ) ;
ASSERT ( V_147 -> V_156 [ V_47 ] . V_157 != NULL ) ;
ASSERT ( V_147 -> V_156 [ V_47 ] . V_207 % V_208 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_20 ) >=
( ( T_5 ) V_189 << V_206 ) + ( V_190 << V_206 ) ) ;
if ( V_147 -> V_156 [ V_47 ] . V_207 < ( V_190 << V_206 ) )
V_190 = V_147 -> V_156 [ V_47 ] . V_207 >> V_206 ;
error = 0 ;
if ( V_155 -> V_161 &
( V_316 | V_317 | V_318 ) ) {
if ( V_147 -> V_156 [ V_47 ] . V_157 == NULL ) {
F_104 ( V_25 ,
L_43 , V_8 ) ;
goto V_319;
}
if ( V_147 -> V_156 [ V_47 ] . V_207 < sizeof( V_320 ) ) {
F_104 ( V_25 ,
L_44 ,
V_147 -> V_156 [ V_47 ] . V_207 , V_8 ) ;
goto V_319;
}
error = F_116 ( V_25 , V_147 -> V_156 [ V_47 ] . V_157 ,
- 1 , 0 , V_321 ,
L_45 ) ;
if ( error )
goto V_319;
}
memcpy ( F_105 ( V_6 ,
( T_5 ) V_189 << V_206 ) ,
V_147 -> V_156 [ V_47 ] . V_157 ,
V_190 << V_206 ) ;
V_319:
V_47 ++ ;
V_189 += V_190 ;
}
ASSERT ( V_47 == V_147 -> V_322 ) ;
F_110 ( V_25 , V_6 , V_155 ) ;
}
STATIC bool
F_117 (
struct V_187 * V_25 ,
struct V_1 * log ,
struct V_171 * V_147 ,
struct V_5 * V_6 ,
struct V_323 * V_155 )
{
T_5 type ;
F_118 ( log , V_155 ) ;
if ( ! V_25 -> V_324 )
return false ;
type = 0 ;
if ( V_155 -> V_161 & V_316 )
type |= V_325 ;
if ( V_155 -> V_161 & V_317 )
type |= V_326 ;
if ( V_155 -> V_161 & V_318 )
type |= V_327 ;
if ( log -> V_328 & type )
return false ;
F_114 ( V_25 , V_147 , V_6 , V_155 ) ;
return true ;
}
STATIC int
F_119 (
struct V_1 * log ,
struct V_172 * V_151 ,
struct V_171 * V_147 ,
T_6 V_329 )
{
T_8 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_5 V_330 ;
T_6 V_214 ;
if ( F_95 ( log , V_155 -> V_176 ,
V_155 -> V_179 , V_155 -> V_161 ) ) {
F_120 ( log , V_155 ) ;
return 0 ;
}
F_121 ( log , V_155 ) ;
V_330 = 0 ;
if ( V_155 -> V_161 & V_163 )
V_330 |= V_331 ;
V_6 = F_122 ( V_25 -> V_332 , V_155 -> V_176 , V_155 -> V_179 ,
V_330 , NULL ) ;
if ( ! V_6 )
return - V_51 ;
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_46 ) ;
goto V_333;
}
V_214 = F_107 ( V_25 , V_6 ) ;
if ( V_214 && V_214 != - 1 && F_123 ( V_214 , V_329 ) >= 0 ) {
F_110 ( V_25 , V_6 , V_155 ) ;
goto V_333;
}
if ( V_155 -> V_161 & V_163 ) {
error = F_98 ( V_25 , V_147 , V_6 , V_155 ) ;
if ( error )
goto V_333;
} else if ( V_155 -> V_161 &
( V_316 | V_317 | V_318 ) ) {
bool V_334 ;
V_334 = F_117 ( V_25 , log , V_147 , V_6 , V_155 ) ;
if ( ! V_334 )
goto V_333;
} else {
F_114 ( V_25 , V_147 , V_6 , V_155 ) ;
}
if ( V_265 ==
F_109 ( * ( ( V_263 * ) F_105 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_20 ) != F_124 ( log -> V_7 -> V_27 . V_335 ,
( T_11 ) log -> V_7 -> V_336 ) ) ) {
F_125 ( V_6 ) ;
error = F_24 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_37 = F_35 ;
F_126 ( V_6 , V_151 ) ;
}
V_333:
F_25 ( V_6 ) ;
return error ;
}
STATIC int
F_127 (
struct V_187 * V_25 ,
struct V_337 * V_338 ,
struct V_339 * V_340 ,
struct V_172 * V_151 )
{
struct V_341 * V_342 ;
int error ;
ASSERT ( V_340 -> V_343 & ( V_344 | V_345 ) ) ;
V_342 = F_128 ( V_25 , V_340 -> V_346 ) ;
if ( ! V_342 )
return - V_51 ;
F_129 ( V_342 , V_338 ) ;
ASSERT ( V_342 -> V_347 . V_348 >= 3 ) ;
error = F_130 ( V_342 , V_338 ) ;
if ( error )
goto V_349;
if ( V_340 -> V_343 & V_344 ) {
ASSERT ( V_340 -> V_343 & V_350 ) ;
error = F_131 ( NULL , V_342 , V_351 ,
V_342 -> V_352 , V_151 ) ;
if ( error )
goto V_349;
}
if ( V_340 -> V_343 & V_345 ) {
ASSERT ( V_340 -> V_343 & V_353 ) ;
error = F_131 ( NULL , V_342 , V_354 ,
V_342 -> V_352 , V_151 ) ;
if ( error )
goto V_349;
}
V_349:
F_132 ( V_342 ) ;
return error ;
}
STATIC int
F_133 (
struct V_1 * log ,
struct V_172 * V_151 ,
struct V_171 * V_147 ,
T_6 V_329 )
{
T_13 * V_340 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
V_202 * V_338 ;
int V_184 ;
char * V_355 ;
char * V_356 ;
int error ;
int V_357 ;
T_5 V_358 ;
struct V_359 * V_360 ;
T_5 V_361 ;
int V_362 = 0 ;
if ( V_147 -> V_156 [ 0 ] . V_207 == sizeof( T_13 ) ) {
V_340 = V_147 -> V_156 [ 0 ] . V_157 ;
} else {
V_340 = F_91 ( sizeof( T_13 ) , V_181 ) ;
V_362 = 1 ;
error = F_134 ( & V_147 -> V_156 [ 0 ] , V_340 ) ;
if ( error )
goto error;
}
if ( F_95 ( log , V_340 -> V_363 ,
V_340 -> V_364 , 0 ) ) {
error = 0 ;
F_135 ( log , V_340 ) ;
goto error;
}
F_136 ( log , V_340 ) ;
V_6 = F_122 ( V_25 -> V_332 , V_340 -> V_363 , V_340 -> V_364 , 0 ,
& V_199 ) ;
if ( ! V_6 ) {
error = - V_51 ;
goto error;
}
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_47 ) ;
goto V_333;
}
ASSERT ( V_340 -> V_343 & V_365 ) ;
V_338 = F_105 ( V_6 , V_340 -> V_366 ) ;
if ( F_31 ( V_338 -> V_367 != F_137 ( V_265 ) ) ) {
F_104 ( V_25 ,
L_48 ,
V_8 , V_338 , V_6 , V_340 -> V_346 ) ;
F_4 ( L_49 ,
V_143 , V_25 ) ;
error = - V_16 ;
goto V_333;
}
V_360 = V_147 -> V_156 [ 1 ] . V_157 ;
if ( F_31 ( V_360 -> V_367 != V_265 ) ) {
F_104 ( V_25 ,
L_50 ,
V_8 , V_147 , V_340 -> V_346 ) ;
F_4 ( L_51 ,
V_143 , V_25 ) ;
error = - V_16 ;
goto V_333;
}
if ( V_338 -> V_348 >= 3 ) {
T_6 V_214 = F_57 ( V_338 -> V_368 ) ;
if ( V_214 && V_214 != - 1 && F_123 ( V_214 , V_329 ) >= 0 ) {
F_138 ( log , V_340 ) ;
error = 0 ;
goto V_369;
}
}
if ( ! F_100 ( & V_25 -> V_27 ) &&
V_360 -> V_370 < F_109 ( V_338 -> V_370 ) ) {
if ( F_109 ( V_338 -> V_370 ) == V_371 &&
V_360 -> V_370 < ( V_371 >> 1 ) ) {
} else {
F_138 ( log , V_340 ) ;
error = 0 ;
goto V_333;
}
}
V_360 -> V_370 = 0 ;
if ( F_31 ( F_139 ( V_360 -> V_372 ) ) ) {
if ( ( V_360 -> V_373 != V_374 ) &&
( V_360 -> V_373 != V_375 ) ) {
F_140 ( L_52 ,
V_143 , V_25 , V_360 ) ;
F_104 ( V_25 ,
L_53
L_54 ,
V_8 , V_147 , V_338 , V_6 , V_340 -> V_346 ) ;
error = - V_16 ;
goto V_333;
}
} else if ( F_31 ( F_141 ( V_360 -> V_372 ) ) ) {
if ( ( V_360 -> V_373 != V_374 ) &&
( V_360 -> V_373 != V_375 ) &&
( V_360 -> V_373 != V_376 ) ) {
F_140 ( L_55 ,
V_143 , V_25 , V_360 ) ;
F_104 ( V_25 ,
L_56
L_54 ,
V_8 , V_147 , V_338 , V_6 , V_340 -> V_346 ) ;
error = - V_16 ;
goto V_333;
}
}
if ( F_31 ( V_360 -> V_377 + V_360 -> V_378 > V_360 -> V_379 ) ) {
F_140 ( L_57 ,
V_143 , V_25 , V_360 ) ;
F_104 ( V_25 ,
L_58
L_59 ,
V_8 , V_147 , V_338 , V_6 , V_340 -> V_346 ,
V_360 -> V_377 + V_360 -> V_378 ,
V_360 -> V_379 ) ;
error = - V_16 ;
goto V_333;
}
if ( F_31 ( V_360 -> V_380 > V_25 -> V_27 . V_201 ) ) {
F_140 ( L_60 ,
V_143 , V_25 , V_360 ) ;
F_104 ( V_25 ,
L_58
L_61 , V_8 ,
V_147 , V_338 , V_6 , V_340 -> V_346 , V_360 -> V_380 ) ;
error = - V_16 ;
goto V_333;
}
V_361 = F_142 ( V_360 -> V_348 ) ;
if ( F_31 ( V_147 -> V_156 [ 1 ] . V_207 > V_361 ) ) {
F_140 ( L_62 ,
V_143 , V_25 , V_360 ) ;
F_104 ( V_25 ,
L_63 ,
V_8 , V_147 -> V_156 [ 1 ] . V_207 , V_147 ) ;
error = - V_16 ;
goto V_333;
}
F_143 ( V_360 , V_338 ) ;
if ( V_147 -> V_156 [ 1 ] . V_207 > V_361 ) {
memcpy ( ( char * ) V_338 + V_361 ,
V_147 -> V_156 [ 1 ] . V_157 + V_361 ,
V_147 -> V_156 [ 1 ] . V_207 - V_361 ) ;
}
V_358 = V_340 -> V_343 ;
switch ( V_358 & ( V_381 | V_382 ) ) {
case V_381 :
F_144 ( V_338 , V_340 -> V_383 . V_384 ) ;
break;
case V_382 :
memcpy ( F_145 ( V_338 ) ,
& V_340 -> V_383 . V_385 ,
sizeof( V_129 ) ) ;
break;
}
if ( V_340 -> V_386 == 2 )
goto V_369;
V_184 = V_147 -> V_156 [ 2 ] . V_207 ;
V_355 = V_147 -> V_156 [ 2 ] . V_157 ;
ASSERT ( V_340 -> V_386 <= 4 ) ;
ASSERT ( ( V_340 -> V_386 == 3 ) || ( V_358 & V_387 ) ) ;
ASSERT ( ! ( V_358 & V_388 ) ||
( V_184 == V_340 -> V_389 ) ) ;
switch ( V_358 & V_388 ) {
case V_390 :
case V_391 :
memcpy ( F_145 ( V_338 ) , V_355 , V_184 ) ;
break;
case V_350 :
F_146 ( V_25 , (struct V_223 * ) V_355 , V_184 ,
( V_392 * ) F_145 ( V_338 ) ,
F_147 ( V_338 , V_25 ) ) ;
break;
default:
ASSERT ( ( V_358 & V_388 ) == 0 ) ;
break;
}
if ( V_340 -> V_343 & V_387 ) {
if ( V_340 -> V_343 & V_388 ) {
V_357 = 3 ;
} else {
V_357 = 2 ;
}
V_184 = V_147 -> V_156 [ V_357 ] . V_207 ;
V_355 = V_147 -> V_156 [ V_357 ] . V_157 ;
ASSERT ( V_184 == V_340 -> V_393 ) ;
switch ( V_340 -> V_343 & V_387 ) {
case V_394 :
case V_395 :
V_356 = F_148 ( V_338 ) ;
ASSERT ( V_184 <= F_149 ( V_338 , V_25 ) ) ;
memcpy ( V_356 , V_355 , V_184 ) ;
break;
case V_353 :
V_356 = F_148 ( V_338 ) ;
F_146 ( V_25 , (struct V_223 * ) V_355 ,
V_184 , ( V_392 * ) V_356 ,
F_149 ( V_338 , V_25 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_64 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_60 ;
goto V_333;
}
}
V_369:
if ( V_340 -> V_343 & ( V_344 | V_345 ) )
error = F_127 ( V_25 , V_338 , V_340 ,
V_151 ) ;
F_106 ( log -> V_7 , V_338 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_37 = F_35 ;
F_126 ( V_6 , V_151 ) ;
V_333:
F_25 ( V_6 ) ;
error:
if ( V_362 )
F_97 ( V_340 ) ;
return error ;
}
STATIC int
F_150 (
struct V_1 * log ,
struct V_171 * V_147 )
{
T_14 * V_396 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_396 ) ;
if ( V_396 -> V_397 & V_398 )
log -> V_328 |= V_325 ;
if ( V_396 -> V_397 & V_399 )
log -> V_328 |= V_326 ;
if ( V_396 -> V_397 & V_400 )
log -> V_328 |= V_327 ;
return 0 ;
}
STATIC int
F_151 (
struct V_1 * log ,
struct V_172 * V_151 ,
struct V_171 * V_147 ,
T_6 V_329 )
{
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
struct V_401 * V_402 , * V_403 ;
int error ;
T_15 * V_404 ;
T_5 type ;
if ( V_25 -> V_324 == 0 )
return 0 ;
V_403 = V_147 -> V_156 [ 1 ] . V_157 ;
if ( V_403 == NULL ) {
F_104 ( log -> V_7 , L_65 , V_8 ) ;
return - V_60 ;
}
if ( V_147 -> V_156 [ 1 ] . V_207 < sizeof( V_320 ) ) {
F_104 ( log -> V_7 , L_66 ,
V_147 -> V_156 [ 1 ] . V_207 , V_8 ) ;
return - V_60 ;
}
type = V_403 -> V_405 & ( V_325 | V_326 | V_327 ) ;
ASSERT ( type ) ;
if ( log -> V_328 & type )
return 0 ;
V_404 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_404 ) ;
error = F_116 ( V_25 , V_403 , V_404 -> V_406 , 0 , V_321 ,
L_67 ) ;
if ( error )
return - V_60 ;
ASSERT ( V_404 -> V_407 == 1 ) ;
error = F_152 ( V_25 , NULL , V_25 -> V_332 , V_404 -> V_408 ,
F_153 ( V_25 , V_404 -> V_407 ) , 0 , & V_6 ,
& V_283 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_402 = F_105 ( V_6 , V_404 -> V_409 ) ;
if ( F_100 ( & V_25 -> V_27 ) ) {
struct V_410 * V_411 = (struct V_410 * ) V_402 ;
T_6 V_214 = F_57 ( V_411 -> V_412 ) ;
if ( V_214 && V_214 != - 1 && F_123 ( V_214 , V_329 ) >= 0 ) {
goto V_333;
}
}
memcpy ( V_402 , V_403 , V_147 -> V_156 [ 1 ] . V_207 ) ;
if ( F_100 ( & V_25 -> V_27 ) ) {
F_154 ( ( char * ) V_402 , sizeof( struct V_410 ) ,
V_413 ) ;
}
ASSERT ( V_404 -> V_414 == 2 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_37 = F_35 ;
F_126 ( V_6 , V_151 ) ;
V_333:
F_25 ( V_6 ) ;
return 0 ;
}
STATIC int
F_155 (
struct V_1 * log ,
struct V_171 * V_147 ,
T_6 V_214 )
{
int error ;
struct V_187 * V_25 = log -> V_7 ;
struct V_415 * V_416 ;
struct V_417 * V_418 ;
V_418 = V_147 -> V_156 [ 0 ] . V_157 ;
V_416 = F_156 ( V_25 , V_418 -> V_419 ) ;
error = F_157 ( & V_147 -> V_156 [ 0 ] , & V_416 -> V_420 ) ;
if ( error ) {
F_158 ( V_416 ) ;
return error ;
}
F_159 ( & V_416 -> V_421 , V_418 -> V_419 ) ;
F_160 ( & log -> V_422 -> V_423 ) ;
F_161 ( log -> V_422 , & V_416 -> V_424 , V_214 ) ;
F_162 ( V_416 ) ;
return 0 ;
}
STATIC int
F_163 (
struct V_1 * log ,
struct V_171 * V_147 )
{
T_16 * V_425 ;
T_17 * V_416 = NULL ;
T_18 * V_426 ;
T_19 V_427 ;
struct V_428 V_429 ;
struct V_430 * V_431 = log -> V_422 ;
V_425 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( ( V_147 -> V_156 [ 0 ] . V_207 == ( sizeof( V_432 ) +
( ( V_425 -> V_433 - 1 ) * sizeof( V_434 ) ) ) ) ||
( V_147 -> V_156 [ 0 ] . V_207 == ( sizeof( V_435 ) +
( ( V_425 -> V_433 - 1 ) * sizeof( V_436 ) ) ) ) ) ;
V_427 = V_425 -> V_437 ;
F_160 ( & V_431 -> V_423 ) ;
V_426 = F_164 ( V_431 , & V_429 , 0 ) ;
while ( V_426 != NULL ) {
if ( V_426 -> V_438 == V_168 ) {
V_416 = ( T_17 * ) V_426 ;
if ( V_416 -> V_420 . V_427 == V_427 ) {
F_165 ( & V_431 -> V_423 ) ;
F_162 ( V_416 ) ;
F_160 ( & V_431 -> V_423 ) ;
break;
}
}
V_426 = F_166 ( V_431 , & V_429 ) ;
}
F_167 ( & V_429 ) ;
F_165 ( & V_431 -> V_423 ) ;
return 0 ;
}
STATIC int
F_168 (
struct V_1 * log ,
struct V_171 * V_147 ,
T_6 V_214 )
{
int error ;
struct V_187 * V_25 = log -> V_7 ;
struct V_439 * V_440 ;
struct V_441 * V_442 ;
V_442 = V_147 -> V_156 [ 0 ] . V_157 ;
V_440 = F_169 ( V_25 , V_442 -> V_443 ) ;
error = F_170 ( & V_147 -> V_156 [ 0 ] , & V_440 -> V_444 ) ;
if ( error ) {
F_171 ( V_440 ) ;
return error ;
}
F_159 ( & V_440 -> V_445 , V_442 -> V_443 ) ;
F_160 ( & log -> V_422 -> V_423 ) ;
F_161 ( log -> V_422 , & V_440 -> V_446 , V_214 ) ;
F_172 ( V_440 ) ;
return 0 ;
}
STATIC int
F_173 (
struct V_1 * log ,
struct V_171 * V_147 )
{
struct V_447 * V_448 ;
struct V_439 * V_440 = NULL ;
struct V_449 * V_426 ;
T_19 V_450 ;
struct V_428 V_429 ;
struct V_430 * V_431 = log -> V_422 ;
V_448 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_147 -> V_156 [ 0 ] . V_207 == sizeof( struct V_447 ) ) ;
V_450 = V_448 -> V_451 ;
F_160 ( & V_431 -> V_423 ) ;
V_426 = F_164 ( V_431 , & V_429 , 0 ) ;
while ( V_426 != NULL ) {
if ( V_426 -> V_438 == V_169 ) {
V_440 = (struct V_439 * ) V_426 ;
if ( V_440 -> V_444 . V_450 == V_450 ) {
F_165 ( & V_431 -> V_423 ) ;
F_172 ( V_440 ) ;
F_160 ( & V_431 -> V_423 ) ;
break;
}
}
V_426 = F_166 ( V_431 , & V_429 ) ;
}
F_167 ( & V_429 ) ;
F_165 ( & V_431 -> V_423 ) ;
return 0 ;
}
STATIC int
F_174 (
struct V_1 * log ,
struct V_172 * V_151 ,
T_7 * V_147 )
{
struct V_187 * V_25 = log -> V_7 ;
struct V_452 * V_453 ;
T_20 V_454 ;
T_21 V_455 ;
unsigned int V_75 ;
unsigned int V_361 ;
T_21 V_456 ;
int V_457 ;
int V_458 ;
int V_459 ;
int V_460 ;
int V_47 ;
V_453 = (struct V_452 * ) V_147 -> V_156 [ 0 ] . V_157 ;
if ( V_453 -> V_461 != V_158 ) {
F_3 ( log -> V_7 , L_68 ) ;
return - V_124 ;
}
if ( V_453 -> V_462 != 1 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_124 ;
}
V_454 = F_28 ( V_453 -> V_463 ) ;
if ( V_454 >= V_25 -> V_27 . V_464 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_124 ;
}
V_455 = F_28 ( V_453 -> V_465 ) ;
if ( ! V_455 || V_455 == V_466 || V_455 >= V_25 -> V_27 . V_467 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_124 ;
}
V_361 = F_28 ( V_453 -> V_468 ) ;
if ( V_361 != V_25 -> V_27 . V_201 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_124 ;
}
V_75 = F_28 ( V_453 -> V_469 ) ;
if ( ! V_75 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_124 ;
}
V_456 = F_28 ( V_453 -> V_470 ) ;
if ( ! V_456 || V_456 >= V_25 -> V_27 . V_467 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_124 ;
}
if ( V_456 != V_25 -> V_471 &&
V_456 != V_25 -> V_472 ) {
F_3 ( log -> V_7 ,
L_75 , V_473 ) ;
return - V_124 ;
}
if ( ( V_75 >> V_25 -> V_27 . V_474 ) != V_456 ) {
F_3 ( log -> V_7 ,
L_76 ,
V_473 ) ;
return - V_124 ;
}
V_457 = F_175 ( V_25 ) ;
V_458 = F_153 ( V_25 , V_457 ) ;
V_460 = V_456 / V_457 ;
for ( V_47 = 0 , V_459 = 0 ; V_47 < V_460 ; V_47 ++ ) {
T_2 V_475 ;
V_475 = F_176 ( V_25 , V_454 ,
V_455 + V_47 * V_457 ) ;
if ( F_95 ( log , V_475 , V_458 , 0 ) )
V_459 ++ ;
}
ASSERT ( ! V_459 || V_459 == V_460 ) ;
if ( V_459 ) {
if ( V_459 != V_460 )
F_3 ( V_25 ,
L_77 ) ;
F_177 ( log , V_453 ) ;
return 0 ;
}
F_178 ( log , V_453 ) ;
return F_179 ( V_25 , NULL , V_151 , V_75 , V_454 , V_455 ,
V_456 , F_28 ( V_453 -> V_476 ) ) ;
}
STATIC void
F_180 (
struct V_1 * log ,
struct V_171 * V_147 )
{
struct V_323 * V_155 = V_147 -> V_156 [ 0 ] . V_157 ;
struct V_187 * V_25 = log -> V_7 ;
if ( F_94 ( log , V_155 -> V_176 ,
V_155 -> V_179 , V_155 -> V_161 ) ) {
return;
}
F_181 ( V_25 -> V_332 , V_155 -> V_176 ,
V_155 -> V_179 , NULL ) ;
}
STATIC void
F_182 (
struct V_1 * log ,
struct V_171 * V_147 )
{
struct V_339 V_477 ;
struct V_339 * V_478 ;
struct V_187 * V_25 = log -> V_7 ;
int error ;
if ( V_147 -> V_156 [ 0 ] . V_207 == sizeof( struct V_339 ) ) {
V_478 = V_147 -> V_156 [ 0 ] . V_157 ;
} else {
V_478 = & V_477 ;
memset ( V_478 , 0 , sizeof( * V_478 ) ) ;
error = F_134 ( & V_147 -> V_156 [ 0 ] , V_478 ) ;
if ( error )
return;
}
if ( F_94 ( log , V_478 -> V_363 , V_478 -> V_364 , 0 ) )
return;
F_181 ( V_25 -> V_332 , V_478 -> V_363 ,
V_478 -> V_364 , & V_479 ) ;
}
STATIC void
F_183 (
struct V_1 * log ,
struct V_171 * V_147 )
{
struct V_187 * V_25 = log -> V_7 ;
struct V_401 * V_403 ;
struct V_480 * V_404 ;
T_5 type ;
int V_184 ;
if ( V_25 -> V_324 == 0 )
return;
V_403 = V_147 -> V_156 [ 1 ] . V_157 ;
if ( V_403 == NULL )
return;
if ( V_147 -> V_156 [ 1 ] . V_207 < sizeof( struct V_401 ) )
return;
type = V_403 -> V_405 & ( V_325 | V_326 | V_327 ) ;
ASSERT ( type ) ;
if ( log -> V_328 & type )
return;
V_404 = V_147 -> V_156 [ 0 ] . V_157 ;
ASSERT ( V_404 ) ;
ASSERT ( V_404 -> V_407 == 1 ) ;
V_184 = F_153 ( V_25 , V_404 -> V_407 ) ;
if ( F_94 ( log , V_404 -> V_408 , V_184 , 0 ) )
return;
F_181 ( V_25 -> V_332 , V_404 -> V_408 , V_184 ,
& V_481 ) ;
}
STATIC void
F_184 (
struct V_1 * log ,
struct V_171 * V_147 )
{
switch ( F_78 ( V_147 ) ) {
case V_160 :
F_180 ( log , V_147 ) ;
break;
case V_164 :
F_182 ( log , V_147 ) ;
break;
case V_165 :
F_183 ( log , V_147 ) ;
break;
case V_168 :
case V_167 :
case V_166 :
case V_169 :
case V_170 :
default:
break;
}
}
STATIC int
F_185 (
struct V_1 * log ,
struct V_144 * V_145 ,
struct V_171 * V_147 )
{
F_186 ( log , V_145 , V_147 , V_482 ) ;
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
case V_169 :
case V_170 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_78 ( V_147 ) ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
}
STATIC int
F_187 (
struct V_1 * log ,
struct V_144 * V_145 ,
struct V_172 * V_151 ,
struct V_171 * V_147 )
{
F_186 ( log , V_145 , V_147 , V_483 ) ;
switch ( F_78 ( V_147 ) ) {
case V_160 :
return F_119 ( log , V_151 , V_147 ,
V_145 -> V_484 ) ;
case V_164 :
return F_133 ( log , V_151 , V_147 ,
V_145 -> V_484 ) ;
case V_168 :
return F_155 ( log , V_147 , V_145 -> V_484 ) ;
case V_167 :
return F_163 ( log , V_147 ) ;
case V_169 :
return F_168 ( log , V_147 , V_145 -> V_484 ) ;
case V_170 :
return F_173 ( log , V_147 ) ;
case V_165 :
return F_151 ( log , V_151 , V_147 ,
V_145 -> V_484 ) ;
case V_158 :
return F_174 ( log , V_151 , V_147 ) ;
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
F_188 (
struct V_1 * log ,
struct V_144 * V_145 ,
struct V_172 * V_151 ,
struct V_172 * V_485 )
{
struct V_171 * V_147 ;
int error = 0 ;
F_89 (item, item_list, ri_list) {
error = F_187 ( log , V_145 ,
V_151 , V_147 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_189 (
struct V_1 * log ,
struct V_144 * V_145 ,
int V_146 )
{
int error = 0 ;
int V_24 ;
int V_486 = 0 ;
struct V_171 * V_147 ;
struct V_171 * V_319 ;
F_75 ( V_151 ) ;
F_75 ( V_487 ) ;
F_75 ( V_488 ) ;
#define F_190 100
F_191 ( & V_145 -> V_489 ) ;
error = F_74 ( log , V_145 , V_146 ) ;
if ( error )
return error ;
F_77 (item, next, &trans->r_itemq, ri_list) {
switch ( V_146 ) {
case V_482 :
error = F_185 ( log , V_145 , V_147 ) ;
break;
case V_483 :
F_184 ( log , V_147 ) ;
F_79 ( & V_147 -> V_159 , & V_487 ) ;
V_486 ++ ;
if ( V_486 >= F_190 ) {
error = F_188 ( log , V_145 ,
& V_151 , & V_487 ) ;
F_192 ( & V_487 , & V_488 ) ;
V_486 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_53;
}
V_53:
if ( ! F_83 ( & V_487 ) ) {
if ( ! error )
error = F_188 ( log , V_145 ,
& V_151 , & V_487 ) ;
F_192 ( & V_487 , & V_488 ) ;
}
if ( ! F_83 ( & V_488 ) )
F_76 ( & V_488 , & V_145 -> V_154 ) ;
V_24 = F_193 ( & V_151 ) ;
return error ? error : V_24 ;
}
STATIC void
F_194 (
struct V_172 * V_26 )
{
T_7 * V_147 ;
V_147 = F_195 ( sizeof( T_7 ) , V_181 ) ;
F_196 ( & V_147 -> V_159 ) ;
F_92 ( & V_147 -> V_159 , V_26 ) ;
}
STATIC int
F_197 (
struct V_1 * log ,
struct V_144 * V_145 ,
char * V_490 ,
int V_184 )
{
T_7 * V_147 ;
char * V_491 , * V_492 ;
int V_493 ;
if ( F_83 ( & V_145 -> V_154 ) ) {
ASSERT ( V_184 <= sizeof( struct V_494 ) ) ;
if ( V_184 > sizeof( struct V_494 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
return - V_60 ;
}
F_194 ( & V_145 -> V_154 ) ;
V_491 = ( char * ) & V_145 -> V_495 +
sizeof( struct V_494 ) - V_184 ;
memcpy ( V_491 , V_490 , V_184 ) ;
return 0 ;
}
V_147 = F_198 ( V_145 -> V_154 . V_496 , T_7 , V_159 ) ;
V_492 = V_147 -> V_156 [ V_147 -> V_497 - 1 ] . V_157 ;
V_493 = V_147 -> V_156 [ V_147 -> V_497 - 1 ] . V_207 ;
V_491 = F_199 ( V_492 , V_184 + V_493 , V_181 ) ;
memcpy ( & V_491 [ V_493 ] , V_490 , V_184 ) ;
V_147 -> V_156 [ V_147 -> V_497 - 1 ] . V_207 += V_184 ;
V_147 -> V_156 [ V_147 -> V_497 - 1 ] . V_157 = V_491 ;
F_200 ( log , V_145 , V_147 , 0 ) ;
return 0 ;
}
STATIC int
F_201 (
struct V_1 * log ,
struct V_144 * V_145 ,
char * V_490 ,
int V_184 )
{
T_13 * V_340 ;
T_7 * V_147 ;
char * V_491 ;
if ( ! V_184 )
return 0 ;
if ( F_83 ( & V_145 -> V_154 ) ) {
if ( * ( T_5 * ) V_490 != V_498 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
if ( V_184 > sizeof( struct V_494 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
if ( V_184 == sizeof( struct V_494 ) )
F_194 ( & V_145 -> V_154 ) ;
memcpy ( & V_145 -> V_495 , V_490 , V_184 ) ;
return 0 ;
}
V_491 = F_91 ( V_184 , V_181 ) ;
memcpy ( V_491 , V_490 , V_184 ) ;
V_340 = ( T_13 * ) V_491 ;
V_147 = F_198 ( V_145 -> V_154 . V_496 , T_7 , V_159 ) ;
if ( V_147 -> V_322 != 0 &&
V_147 -> V_322 == V_147 -> V_497 ) {
F_194 ( & V_145 -> V_154 ) ;
V_147 = F_198 ( V_145 -> V_154 . V_496 ,
T_7 , V_159 ) ;
}
if ( V_147 -> V_322 == 0 ) {
if ( V_340 -> V_386 == 0 ||
V_340 -> V_386 > V_499 ) {
F_3 ( log -> V_7 ,
L_81 ,
V_340 -> V_386 ) ;
ASSERT ( 0 ) ;
F_97 ( V_491 ) ;
return - V_60 ;
}
V_147 -> V_322 = V_340 -> V_386 ;
V_147 -> V_156 =
F_195 ( V_147 -> V_322 * sizeof( V_500 ) ,
V_181 ) ;
}
ASSERT ( V_147 -> V_322 > V_147 -> V_497 ) ;
V_147 -> V_156 [ V_147 -> V_497 ] . V_157 = V_491 ;
V_147 -> V_156 [ V_147 -> V_497 ] . V_207 = V_184 ;
V_147 -> V_497 ++ ;
F_202 ( log , V_145 , V_147 , 0 ) ;
return 0 ;
}
STATIC void
F_203 (
struct V_144 * V_145 )
{
T_7 * V_147 , * V_148 ;
int V_47 ;
F_77 (item, n, &trans->r_itemq, ri_list) {
F_96 ( & V_147 -> V_159 ) ;
for ( V_47 = 0 ; V_47 < V_147 -> V_497 ; V_47 ++ )
F_97 ( V_147 -> V_156 [ V_47 ] . V_157 ) ;
F_97 ( V_147 -> V_156 ) ;
F_97 ( V_147 ) ;
}
F_97 ( V_145 ) ;
}
STATIC int
F_204 (
struct V_1 * log ,
struct V_144 * V_145 ,
char * V_490 ,
unsigned int V_184 ,
unsigned int V_185 ,
int V_146 )
{
int error = 0 ;
bool V_501 = false ;
V_185 &= ~ V_502 ;
if ( V_185 & V_503 )
V_185 &= ~ V_504 ;
switch ( V_185 ) {
case 0 :
case V_504 :
error = F_201 ( log , V_145 , V_490 , V_184 ) ;
break;
case V_503 :
error = F_197 ( log , V_145 , V_490 , V_184 ) ;
break;
case V_505 :
error = F_189 ( log , V_145 , V_146 ) ;
V_501 = true ;
break;
case V_105 :
F_3 ( log -> V_7 , L_82 , V_8 ) ;
V_501 = true ;
break;
case V_506 :
default:
F_3 ( log -> V_7 , L_83 , V_8 , V_185 ) ;
ASSERT ( 0 ) ;
error = - V_60 ;
break;
}
if ( error || V_501 )
F_203 ( V_145 ) ;
return error ;
}
STATIC struct V_144 *
F_205 (
struct V_507 V_508 [] ,
struct V_77 * V_78 ,
struct V_96 * V_509 )
{
struct V_144 * V_145 ;
T_22 V_510 ;
struct V_507 * V_511 ;
V_510 = F_28 ( V_509 -> V_512 ) ;
V_511 = & V_508 [ F_206 ( V_510 ) ] ;
F_207 (trans, rhp, r_list) {
if ( V_145 -> V_513 == V_510 )
return V_145 ;
}
if ( ! ( V_509 -> V_104 & V_506 ) )
return NULL ;
ASSERT ( F_28 ( V_509 -> V_514 ) == 0 ) ;
V_145 = F_195 ( sizeof( struct V_144 ) , V_181 ) ;
V_145 -> V_513 = V_510 ;
V_145 -> V_484 = F_57 ( V_78 -> V_113 ) ;
F_196 ( & V_145 -> V_154 ) ;
F_208 ( & V_145 -> V_489 ) ;
F_209 ( & V_145 -> V_489 , V_511 ) ;
return NULL ;
}
STATIC int
F_210 (
struct V_1 * log ,
struct V_507 V_508 [] ,
struct V_77 * V_78 ,
struct V_96 * V_509 ,
char * V_490 ,
char * V_515 ,
int V_146 )
{
struct V_144 * V_145 ;
unsigned int V_184 ;
if ( V_509 -> V_516 != V_517 &&
V_509 -> V_516 != V_518 ) {
F_3 ( log -> V_7 , L_84 ,
V_8 , V_509 -> V_516 ) ;
ASSERT ( 0 ) ;
return - V_60 ;
}
V_184 = F_28 ( V_509 -> V_514 ) ;
if ( V_490 + V_184 > V_515 ) {
F_3 ( log -> V_7 , L_85 , V_8 , V_184 ) ;
F_211 ( 1 ) ;
return - V_60 ;
}
V_145 = F_205 ( V_508 , V_78 , V_509 ) ;
if ( ! V_145 ) {
return 0 ;
}
return F_204 ( log , V_145 , V_490 , V_184 ,
V_509 -> V_104 , V_146 ) ;
}
STATIC int
F_212 (
struct V_1 * log ,
struct V_507 V_508 [] ,
struct V_77 * V_78 ,
char * V_490 ,
int V_146 )
{
struct V_96 * V_509 ;
char * V_515 ;
int V_519 ;
int error ;
V_515 = V_490 + F_28 ( V_78 -> V_63 ) ;
V_519 = F_28 ( V_78 -> V_103 ) ;
if ( F_29 ( log -> V_7 , V_78 ) )
return - V_60 ;
while ( ( V_490 < V_515 ) && V_519 ) {
V_509 = (struct V_96 * ) V_490 ;
V_490 += sizeof( * V_509 ) ;
ASSERT ( V_490 <= V_515 ) ;
error = F_210 ( log , V_508 , V_78 , V_509 ,
V_490 , V_515 , V_146 ) ;
if ( error )
return error ;
V_490 += F_28 ( V_509 -> V_514 ) ;
V_519 -- ;
}
return 0 ;
}
STATIC int
F_213 (
struct V_187 * V_25 ,
struct V_430 * V_431 ,
struct V_449 * V_426 )
{
struct V_415 * V_416 ;
int error ;
V_416 = F_214 ( V_426 , struct V_415 , V_424 ) ;
if ( F_215 ( V_520 , & V_416 -> V_521 ) )
return 0 ;
F_165 ( & V_431 -> V_423 ) ;
error = F_216 ( V_25 , V_416 ) ;
F_160 ( & V_431 -> V_423 ) ;
return error ;
}
STATIC void
F_217 (
struct V_187 * V_25 ,
struct V_430 * V_431 ,
struct V_449 * V_426 )
{
struct V_415 * V_416 ;
V_416 = F_214 ( V_426 , struct V_415 , V_424 ) ;
F_165 ( & V_431 -> V_423 ) ;
F_162 ( V_416 ) ;
F_160 ( & V_431 -> V_423 ) ;
}
STATIC int
F_218 (
struct V_187 * V_25 ,
struct V_430 * V_431 ,
struct V_449 * V_426 )
{
struct V_439 * V_440 ;
int error ;
V_440 = F_214 ( V_426 , struct V_439 , V_446 ) ;
if ( F_215 ( V_522 , & V_440 -> V_523 ) )
return 0 ;
F_165 ( & V_431 -> V_423 ) ;
error = F_219 ( V_25 , V_440 ) ;
F_160 ( & V_431 -> V_423 ) ;
return error ;
}
STATIC void
F_220 (
struct V_187 * V_25 ,
struct V_430 * V_431 ,
struct V_449 * V_426 )
{
struct V_439 * V_440 ;
V_440 = F_214 ( V_426 , struct V_439 , V_446 ) ;
F_165 ( & V_431 -> V_423 ) ;
F_172 ( V_440 ) ;
F_160 ( & V_431 -> V_423 ) ;
}
static inline bool F_221 ( struct V_449 * V_426 )
{
switch ( V_426 -> V_438 ) {
case V_168 :
case V_169 :
return true ;
default:
return false ;
}
}
STATIC int
F_222 (
struct V_1 * log )
{
struct V_449 * V_426 ;
int error = 0 ;
struct V_428 V_429 ;
struct V_430 * V_431 ;
T_6 V_524 ;
V_431 = log -> V_422 ;
F_160 ( & V_431 -> V_423 ) ;
V_426 = F_164 ( V_431 , & V_429 , 0 ) ;
V_524 = F_70 ( log -> V_107 , log -> V_111 ) ;
while ( V_426 != NULL ) {
if ( ! F_221 ( V_426 ) ) {
#ifdef F_223
for (; V_426 ; V_426 = F_166 ( V_431 , & V_429 ) )
ASSERT ( ! F_221 ( V_426 ) ) ;
#endif
break;
}
ASSERT ( F_123 ( V_524 , V_426 -> V_525 ) >= 0 ) ;
switch ( V_426 -> V_438 ) {
case V_168 :
error = F_213 ( log -> V_7 , V_431 , V_426 ) ;
break;
case V_169 :
error = F_218 ( log -> V_7 , V_431 , V_426 ) ;
break;
}
if ( error )
goto V_53;
V_426 = F_166 ( V_431 , & V_429 ) ;
}
V_53:
F_167 ( & V_429 ) ;
F_165 ( & V_431 -> V_423 ) ;
return error ;
}
STATIC int
F_224 (
struct V_1 * log )
{
struct V_449 * V_426 ;
int error = 0 ;
struct V_428 V_429 ;
struct V_430 * V_431 ;
V_431 = log -> V_422 ;
F_160 ( & V_431 -> V_423 ) ;
V_426 = F_164 ( V_431 , & V_429 , 0 ) ;
while ( V_426 != NULL ) {
if ( ! F_221 ( V_426 ) ) {
#ifdef F_223
for (; V_426 ; V_426 = F_166 ( V_431 , & V_429 ) )
ASSERT ( ! F_221 ( V_426 ) ) ;
#endif
break;
}
switch ( V_426 -> V_438 ) {
case V_168 :
F_217 ( log -> V_7 , V_431 , V_426 ) ;
break;
case V_169 :
F_220 ( log -> V_7 , V_431 , V_426 ) ;
break;
}
V_426 = F_166 ( V_431 , & V_429 ) ;
}
F_167 ( & V_429 ) ;
F_165 ( & V_431 -> V_423 ) ;
return error ;
}
STATIC void
F_225 (
T_3 * V_25 ,
T_20 V_454 ,
int V_173 )
{
T_23 * V_526 ;
T_24 * V_527 ;
T_1 * V_528 ;
int V_13 ;
int error ;
error = F_226 ( V_25 , & F_227 ( V_25 ) -> V_529 , 0 , 0 , 0 , & V_526 ) ;
if ( error )
goto V_81;
error = F_228 ( V_25 , V_526 , V_454 , & V_528 ) ;
if ( error )
goto V_530;
V_527 = F_229 ( V_528 ) ;
V_527 -> V_531 [ V_173 ] = F_30 ( V_532 ) ;
V_13 = F_101 ( T_24 , V_531 ) +
( sizeof( T_10 ) * V_173 ) ;
F_230 ( V_526 , V_528 , V_13 ,
( V_13 + sizeof( T_10 ) - 1 ) ) ;
error = F_231 ( V_526 ) ;
if ( error )
goto V_81;
return;
V_530:
F_232 ( V_526 ) ;
V_81:
F_3 ( V_25 , L_86 , V_8 , V_454 ) ;
return;
}
STATIC T_10
F_233 (
struct V_187 * V_25 ,
T_20 V_454 ,
T_10 V_533 ,
int V_173 )
{
struct V_5 * V_534 ;
struct V_337 * V_338 ;
struct V_341 * V_342 ;
T_25 V_535 ;
int error ;
V_535 = F_234 ( V_25 , V_454 , V_533 ) ;
error = F_235 ( V_25 , NULL , V_535 , 0 , 0 , & V_342 ) ;
if ( error )
goto V_536;
error = F_236 ( V_25 , NULL , & V_342 -> V_537 , & V_338 , & V_534 , 0 , 0 ) ;
if ( error )
goto V_538;
ASSERT ( F_237 ( V_342 ) -> V_539 == 0 ) ;
ASSERT ( F_237 ( V_342 ) -> V_540 != 0 ) ;
V_533 = F_28 ( V_338 -> V_203 ) ;
F_25 ( V_534 ) ;
V_342 -> V_347 . V_541 = 0 ;
F_238 ( V_342 ) ;
return V_533 ;
V_538:
F_238 ( V_342 ) ;
V_536:
F_225 ( V_25 , V_454 , V_173 ) ;
return V_532 ;
}
STATIC void
F_239 (
struct V_1 * log )
{
T_3 * V_25 ;
T_20 V_454 ;
T_24 * V_527 ;
T_1 * V_528 ;
T_10 V_533 ;
int V_173 ;
int error ;
T_5 V_542 ;
V_25 = log -> V_7 ;
V_542 = V_25 -> V_543 ;
V_25 -> V_543 = 0 ;
for ( V_454 = 0 ; V_454 < V_25 -> V_27 . V_464 ; V_454 ++ ) {
error = F_228 ( V_25 , NULL , V_454 , & V_528 ) ;
if ( error ) {
continue;
}
V_527 = F_229 ( V_528 ) ;
F_7 ( V_528 ) ;
for ( V_173 = 0 ; V_173 < V_544 ; V_173 ++ ) {
V_533 = F_28 ( V_527 -> V_531 [ V_173 ] ) ;
while ( V_533 != V_532 ) {
V_533 = F_233 ( V_25 ,
V_454 , V_533 , V_173 ) ;
}
}
F_240 ( V_528 ) ;
}
V_25 -> V_543 = V_542 ;
}
STATIC int
F_241 (
struct V_77 * V_78 ,
char * V_490 ,
struct V_1 * log )
{
int V_47 , V_48 , V_545 ;
for ( V_47 = 0 ; V_47 < F_46 ( F_28 ( V_78 -> V_63 ) ) &&
V_47 < ( V_62 / V_54 ) ; V_47 ++ ) {
* ( V_82 * ) V_490 = * ( V_82 * ) & V_78 -> V_546 [ V_47 ] ;
V_490 += V_54 ;
}
if ( F_45 ( & log -> V_7 -> V_27 ) ) {
T_26 * V_547 = ( T_26 * ) V_78 ;
for ( ; V_47 < F_46 ( F_28 ( V_78 -> V_63 ) ) ; V_47 ++ ) {
V_48 = V_47 / ( V_62 / V_54 ) ;
V_545 = V_47 % ( V_62 / V_54 ) ;
* ( V_82 * ) V_490 = V_547 [ V_48 ] . V_548 . V_549 [ V_545 ] ;
V_490 += V_54 ;
}
}
return 0 ;
}
STATIC int
F_242 (
struct V_1 * log ,
struct V_507 V_508 [] ,
struct V_77 * V_78 ,
char * V_490 ,
int V_146 )
{
int error ;
T_27 V_550 ;
V_550 = F_243 ( log , V_78 , V_490 , F_28 ( V_78 -> V_63 ) ) ;
if ( V_146 == V_87 ) {
if ( V_78 -> V_551 && V_550 != V_78 -> V_551 )
return - V_93 ;
return 0 ;
}
if ( V_550 != V_78 -> V_551 ) {
if ( V_78 -> V_551 || F_100 ( & log -> V_7 -> V_27 ) ) {
F_104 ( log -> V_7 ,
L_87 ,
F_244 ( V_78 -> V_551 ) ,
F_244 ( V_550 ) ) ;
F_245 ( V_490 , 32 ) ;
}
if ( F_100 ( & log -> V_7 -> V_27 ) )
return - V_16 ;
}
error = F_241 ( V_78 , V_490 , log ) ;
if ( error )
return error ;
return F_212 ( log , V_508 , V_78 , V_490 , V_146 ) ;
}
STATIC int
F_246 (
struct V_1 * log ,
struct V_77 * V_78 ,
T_2 V_183 )
{
int V_552 ;
if ( F_31 ( V_78 -> V_32 != F_30 ( V_33 ) ) ) {
F_4 ( L_88 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 (
( ! V_78 -> V_101 ||
( F_28 ( V_78 -> V_101 ) & ( ~ V_553 ) ) ) ) ) {
F_3 ( log -> V_7 , L_89 ,
V_8 , F_28 ( V_78 -> V_101 ) ) ;
return - V_60 ;
}
V_552 = F_28 ( V_78 -> V_63 ) ;
if ( F_31 ( V_552 <= 0 || V_552 > V_72 ) ) {
F_4 ( L_90 ,
V_143 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 ( V_183 > log -> V_3 || V_183 > V_72 ) ) {
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
T_1 * V_554 , * V_555 ;
int error = 0 , V_61 , V_63 ;
int V_556 , V_557 ;
int V_100 , V_558 , V_559 ;
struct V_507 V_508 [ V_560 ] ;
ASSERT ( V_65 != V_74 ) ;
V_88 = 0 ;
if ( F_45 ( & log -> V_7 -> V_27 ) ) {
V_554 = F_2 ( log , 1 ) ;
if ( ! V_554 )
return - V_51 ;
error = F_18 ( log , V_74 , 1 , V_554 , & V_13 ) ;
if ( error )
goto V_561;
V_78 = ( T_4 * ) V_13 ;
error = F_246 ( log , V_78 , V_74 ) ;
if ( error )
goto V_561;
V_61 = F_28 ( V_78 -> V_61 ) ;
V_63 = F_28 ( V_78 -> V_63 ) ;
if ( V_63 > V_61 ) {
if ( V_63 <= log -> V_7 -> V_562 &&
F_28 ( V_78 -> V_103 ) == 1 ) {
F_3 ( log -> V_7 ,
L_92 ,
V_61 , log -> V_7 -> V_562 ) ;
V_61 = log -> V_7 -> V_562 ;
} else
return - V_16 ;
}
if ( ( F_28 ( V_78 -> V_101 ) & V_102 ) &&
( V_61 > V_62 ) ) {
V_100 = V_61 / V_62 ;
if ( V_61 % V_62 )
V_100 ++ ;
F_8 ( V_554 ) ;
V_554 = F_2 ( log , V_100 ) ;
} else {
V_100 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_100 = 1 ;
V_554 = F_2 ( log , 1 ) ;
V_61 = V_563 ;
}
if ( ! V_554 )
return - V_51 ;
V_555 = F_2 ( log , F_46 ( V_61 ) ) ;
if ( ! V_555 ) {
F_8 ( V_554 ) ;
return - V_51 ;
}
memset ( V_508 , 0 , sizeof( V_508 ) ) ;
V_12 = V_88 = V_74 ;
if ( V_74 > V_65 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_554 -> V_15 ;
V_558 = 0 ;
V_559 = 0 ;
if ( V_12 + V_100 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_100 , V_554 ,
& V_13 ) ;
if ( error )
goto V_564;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_72 ) ;
V_558 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_558 > 0 ) ;
error = F_18 ( log , V_12 ,
V_558 , V_554 ,
& V_13 ) ;
if ( error )
goto V_564;
}
V_559 = V_100 - V_558 ;
error = F_19 ( log , 0 ,
V_559 , V_554 ,
V_13 + F_11 ( V_558 ) ) ;
if ( error )
goto V_564;
}
V_78 = ( T_4 * ) V_13 ;
error = F_246 ( log , V_78 ,
V_558 ? V_12 : 0 ) ;
if ( error )
goto V_564;
V_556 = ( int ) F_46 ( F_28 ( V_78 -> V_63 ) ) ;
V_12 += V_100 ;
if ( V_12 + V_556 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_556 , V_555 ,
& V_13 ) ;
if ( error )
goto V_564;
} else {
V_13 = V_555 -> V_15 ;
V_557 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_559 ) ;
ASSERT ( V_12 <= V_72 ) ;
V_557 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_557 > 0 ) ;
error = F_18 ( log , V_12 ,
V_557 , V_555 ,
& V_13 ) ;
if ( error )
goto V_564;
}
error = F_19 ( log , 0 ,
V_556 - V_557 , V_555 ,
V_13 + F_11 ( V_557 ) ) ;
if ( error )
goto V_564;
}
error = F_242 ( log , V_508 , V_78 , V_13 ,
V_146 ) ;
if ( error )
goto V_564;
V_12 += V_556 ;
V_88 = V_12 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
V_88 = V_12 ;
}
while ( V_12 < V_65 ) {
error = F_18 ( log , V_12 , V_100 , V_554 , & V_13 ) ;
if ( error )
goto V_564;
V_78 = ( T_4 * ) V_13 ;
error = F_246 ( log , V_78 , V_12 ) ;
if ( error )
goto V_564;
V_556 = ( int ) F_46 ( F_28 ( V_78 -> V_63 ) ) ;
error = F_18 ( log , V_12 + V_100 , V_556 , V_555 ,
& V_13 ) ;
if ( error )
goto V_564;
error = F_242 ( log , V_508 , V_78 , V_13 , V_146 ) ;
if ( error )
goto V_564;
V_12 += V_556 + V_100 ;
V_88 = V_12 ;
}
V_564:
F_8 ( V_555 ) ;
V_561:
F_8 ( V_554 ) ;
if ( error && V_84 )
* V_84 = V_88 ;
return error ;
}
STATIC int
F_247 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 )
{
int error , V_47 ;
ASSERT ( V_65 != V_74 ) ;
log -> V_186 = F_195 ( V_565 *
sizeof( struct V_172 ) ,
V_181 ) ;
for ( V_47 = 0 ; V_47 < V_565 ; V_47 ++ )
F_196 ( & log -> V_186 [ V_47 ] ) ;
error = F_54 ( log , V_65 , V_74 ,
V_482 , NULL ) ;
if ( error != 0 ) {
F_97 ( log -> V_186 ) ;
log -> V_186 = NULL ;
return error ;
}
error = F_54 ( log , V_65 , V_74 ,
V_483 , NULL ) ;
#ifdef F_223
if ( ! error ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_565 ; V_47 ++ )
ASSERT ( F_83 ( & log -> V_186 [ V_47 ] ) ) ;
}
#endif
F_97 ( log -> V_186 ) ;
log -> V_186 = NULL ;
return error ;
}
STATIC int
F_248 (
struct V_1 * log ,
T_2 V_65 ,
T_2 V_74 )
{
struct V_187 * V_25 = log -> V_7 ;
int error ;
T_1 * V_6 ;
T_28 * V_566 ;
error = F_247 ( log , V_65 , V_74 ) ;
if ( error )
return error ;
if ( F_16 ( V_25 ) ) {
return - V_60 ;
}
F_249 ( V_25 ) ;
V_6 = F_250 ( V_25 , 0 ) ;
V_6 -> V_18 &= ~ ( V_567 | V_568 ) ;
ASSERT ( ! ( V_6 -> V_18 & V_569 ) ) ;
V_6 -> V_18 |= V_19 ;
V_6 -> V_198 = & V_312 ;
error = F_15 ( V_6 ) ;
if ( error ) {
if ( ! F_16 ( V_25 ) ) {
F_17 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_25 ( V_6 ) ;
return error ;
}
V_566 = & V_25 -> V_27 ;
F_251 ( V_566 , F_252 ( V_6 ) ) ;
F_25 ( V_6 ) ;
F_253 ( V_25 ) ;
error = F_254 ( V_25 , V_566 -> V_464 , & V_25 -> V_570 ) ;
if ( error ) {
F_3 ( V_25 , L_93 , error ) ;
return error ;
}
V_25 -> V_571 = F_255 ( V_25 ) ;
F_256 ( log ) ;
log -> V_572 &= ~ V_573 ;
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
! F_257 ( log -> V_7 , log -> V_7 -> V_27 . V_255 ) )
return - V_124 ;
if ( V_74 != V_65 ) {
if ( ( error = F_258 ( log -> V_7 , L_94 ) ) ) {
return error ;
}
if ( F_259 ( & log -> V_7 -> V_27 ) == V_574 &&
F_260 ( & log -> V_7 -> V_27 ,
V_575 ) ) {
F_3 ( log -> V_7 ,
L_95 ,
( log -> V_7 -> V_27 . V_576 &
V_575 ) ) ;
F_3 ( log -> V_7 ,
L_96 ) ;
F_3 ( log -> V_7 ,
L_97 ) ;
return - V_124 ;
}
if ( V_577 . V_578 ) {
F_261 ( log -> V_7 ,
L_98 ,
V_577 . V_578 ) ;
F_262 ( V_577 . V_578 * 1000 ) ;
}
F_261 ( log -> V_7 , L_99 ,
log -> V_7 -> V_579 ? log -> V_7 -> V_579
: L_100 ) ;
error = F_248 ( log , V_65 , V_74 ) ;
log -> V_572 |= V_580 ;
}
return error ;
}
int
F_263 (
struct V_1 * log )
{
if ( log -> V_572 & V_580 ) {
int error ;
error = F_222 ( log ) ;
if ( error ) {
F_104 ( log -> V_7 , L_101 ) ;
return error ;
}
F_264 ( log -> V_7 , V_581 ) ;
F_239 ( log ) ;
F_256 ( log ) ;
F_261 ( log -> V_7 , L_102 ,
log -> V_7 -> V_579 ? log -> V_7 -> V_579
: L_100 ) ;
log -> V_572 &= ~ V_580 ;
} else {
F_265 ( log -> V_7 , L_103 ) ;
}
return 0 ;
}
int
F_266 (
struct V_1 * log )
{
int error = 0 ;
if ( log -> V_572 & V_580 )
error = F_224 ( log ) ;
return error ;
}
void
F_256 (
struct V_1 * log )
{
T_3 * V_25 ;
T_29 * V_582 ;
T_1 * V_583 ;
T_1 * V_528 ;
T_20 V_454 ;
T_19 V_584 ;
T_19 V_585 ;
T_19 V_586 ;
int error ;
V_25 = log -> V_7 ;
V_584 = 0LL ;
V_585 = 0LL ;
V_586 = 0LL ;
for ( V_454 = 0 ; V_454 < V_25 -> V_27 . V_464 ; V_454 ++ ) {
error = F_267 ( V_25 , NULL , V_454 , 0 , & V_583 ) ;
if ( error ) {
F_104 ( V_25 , L_104 ,
V_8 , V_454 , error ) ;
} else {
V_582 = F_268 ( V_583 ) ;
V_584 += F_28 ( V_582 -> V_587 ) +
F_28 ( V_582 -> V_588 ) ;
F_25 ( V_583 ) ;
}
error = F_228 ( V_25 , NULL , V_454 , & V_528 ) ;
if ( error ) {
F_104 ( V_25 , L_105 ,
V_8 , V_454 , error ) ;
} else {
struct V_241 * V_527 = F_229 ( V_528 ) ;
V_585 += F_28 ( V_527 -> V_589 ) ;
V_586 += F_28 ( V_527 -> V_590 ) ;
F_25 ( V_528 ) ;
}
}
}
