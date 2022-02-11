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
if ( V_6 -> V_37 )
F_37 ( V_6 ) ;
ASSERT ( V_6 -> V_37 == NULL ) ;
V_6 -> V_38 = NULL ;
F_38 ( V_6 ) ;
}
STATIC int
F_39 (
struct V_1 * log ,
struct V_5 * V_6 ,
T_2 V_39 ,
T_2 * V_40 ,
T_5 V_41 )
{
char * V_13 ;
T_2 V_42 ;
T_2 V_43 ;
T_5 V_44 ;
int error ;
V_43 = * V_40 ;
V_42 = F_40 ( V_39 , V_43 ) ;
while ( V_42 != V_39 && V_42 != V_43 ) {
error = F_18 ( log , V_42 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_44 = F_41 ( V_13 ) ;
if ( V_44 == V_41 )
V_43 = V_42 ;
else
V_39 = V_42 ;
V_42 = F_40 ( V_39 , V_43 ) ;
}
ASSERT ( ( V_42 == V_39 && V_42 + 1 == V_43 ) ||
( V_42 == V_43 && V_42 - 1 == V_39 ) ) ;
* V_40 = V_43 ;
return 0 ;
}
STATIC int
F_42 (
struct V_1 * log ,
T_2 V_45 ,
int V_4 ,
T_5 V_46 ,
T_2 * V_47 )
{
T_2 V_48 , V_49 ;
T_5 V_41 ;
T_1 * V_6 ;
T_2 V_50 ;
char * V_51 = NULL ;
int error = 0 ;
V_50 = 1 << F_43 ( V_4 ) ;
while ( V_50 > log -> V_3 )
V_50 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_50 ) ) ) {
V_50 >>= 1 ;
if ( V_50 < log -> V_10 )
return - V_52 ;
}
for ( V_48 = V_45 ; V_48 < V_45 + V_4 ; V_48 += V_50 ) {
int V_53 ;
V_53 = F_44 ( V_50 , ( V_45 + V_4 - V_48 ) ) ;
error = F_18 ( log , V_48 , V_53 , V_6 , & V_51 ) ;
if ( error )
goto V_54;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
V_41 = F_41 ( V_51 ) ;
if ( V_41 == V_46 ) {
* V_47 = V_48 + V_49 ;
goto V_54;
}
V_51 += V_55 ;
}
}
* V_47 = - 1 ;
V_54:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_45 (
struct V_1 * log ,
T_2 V_45 ,
T_2 * V_40 ,
int V_56 )
{
T_2 V_48 ;
T_1 * V_6 ;
char * V_13 = NULL ;
T_4 * V_26 = NULL ;
int error = 0 ;
int V_57 = 0 ;
int V_58 = * V_40 - V_45 ;
int V_59 ;
ASSERT ( V_45 != 0 || * V_40 != V_45 ) ;
if ( ! ( V_6 = F_2 ( log , V_58 ) ) ) {
if ( ! ( V_6 = F_2 ( log , 1 ) ) )
return - V_52 ;
V_57 = 1 ;
} else {
error = F_18 ( log , V_45 , V_58 , V_6 , & V_13 ) ;
if ( error )
goto V_54;
V_13 += ( ( V_58 - 1 ) << V_60 ) ;
}
for ( V_48 = ( * V_40 ) - 1 ; V_48 >= 0 ; V_48 -- ) {
if ( V_48 < V_45 ) {
F_3 ( log -> V_7 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = - V_61 ;
goto V_54;
}
if ( V_57 ) {
error = F_18 ( log , V_48 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_54;
}
V_26 = ( T_4 * ) V_13 ;
if ( V_26 -> V_32 == F_30 ( V_33 ) )
break;
if ( ! V_57 )
V_13 -= V_55 ;
}
if ( V_48 == - 1 ) {
error = 1 ;
goto V_54;
}
if ( ( error = F_33 ( log -> V_7 , V_26 ) ) )
goto V_54;
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
T_5 V_62 = F_28 ( V_26 -> V_62 ) ;
V_59 = V_62 / V_63 ;
if ( V_62 % V_63 )
V_59 ++ ;
} else {
V_59 = 1 ;
}
if ( * V_40 - V_48 + V_56 !=
F_47 ( F_28 ( V_26 -> V_64 ) ) + V_59 )
* V_40 = V_48 ;
V_54:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_48 (
struct V_1 * log ,
T_2 * V_65 )
{
T_1 * V_6 ;
char * V_13 ;
T_2 V_47 , V_39 , V_45 , V_40 , V_66 ;
int V_67 ;
T_5 V_68 , V_69 ;
T_5 V_70 ;
int error , V_71 = log -> V_3 ;
error = F_49 ( log , & V_39 ) ;
if ( error < 0 ) {
F_3 ( log -> V_7 , L_12 ) ;
return error ;
}
if ( error == 1 ) {
* V_65 = V_39 ;
if ( ! V_39 ) {
F_3 ( log -> V_7 , L_13 ) ;
}
return 0 ;
}
V_39 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_52 ;
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_72;
V_68 = F_41 ( V_13 ) ;
V_40 = V_66 = V_71 - 1 ;
error = F_18 ( log , V_40 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_72;
V_69 = F_41 ( V_13 ) ;
ASSERT ( V_69 != 0 ) ;
if ( V_68 == V_69 ) {
V_66 = V_71 ;
V_70 = V_69 - 1 ;
} else {
V_70 = V_69 ;
if ( ( error = F_39 ( log , V_6 , V_39 ,
& V_66 , V_69 ) ) )
goto V_72;
}
V_67 = F_50 ( log ) ;
if ( V_66 >= V_67 ) {
V_45 = V_66 - V_67 ;
if ( ( error = F_42 ( log ,
V_45 , V_67 ,
V_70 , & V_47 ) ) )
goto V_72;
if ( V_47 != - 1 )
V_66 = V_47 ;
} else {
ASSERT ( V_66 <= V_73 &&
( T_2 ) V_67 >= V_66 ) ;
V_45 = V_71 - ( V_67 - V_66 ) ;
if ( ( error = F_42 ( log , V_45 ,
V_67 - ( int ) V_66 ,
( V_70 - 1 ) , & V_47 ) ) )
goto V_72;
if ( V_47 != - 1 ) {
V_66 = V_47 ;
goto V_74;
}
V_45 = 0 ;
ASSERT ( V_66 <= V_73 ) ;
if ( ( error = F_42 ( log ,
V_45 , ( int ) V_66 ,
V_70 , & V_47 ) ) )
goto V_72;
if ( V_47 != - 1 )
V_66 = V_47 ;
}
V_74:
V_67 = F_51 ( log ) ;
if ( V_66 >= V_67 ) {
V_45 = V_66 - V_67 ;
error = F_45 ( log , V_45 , & V_66 , 0 ) ;
if ( error == 1 )
error = - V_61 ;
if ( error )
goto V_72;
} else {
V_45 = 0 ;
ASSERT ( V_66 <= V_73 ) ;
error = F_45 ( log , V_45 , & V_66 , 0 ) ;
if ( error < 0 )
goto V_72;
if ( error == 1 ) {
V_45 = V_71 - ( V_67 - V_66 ) ;
V_47 = V_71 ;
ASSERT ( V_45 <= V_73 &&
( T_2 ) V_71 - V_45 >= 0 ) ;
ASSERT ( V_66 <= V_73 ) ;
error = F_45 ( log , V_45 ,
& V_47 , ( int ) V_66 ) ;
if ( error == 1 )
error = - V_61 ;
if ( error )
goto V_72;
if ( V_47 != V_71 )
V_66 = V_47 ;
} else if ( error )
goto V_72;
}
F_8 ( V_6 ) ;
if ( V_66 == V_71 )
* V_65 = 0 ;
else
* V_65 = V_66 ;
return 0 ;
V_72:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_14 ) ;
return error ;
}
STATIC int
F_52 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 ,
int V_76 ,
struct V_5 * V_6 ,
T_2 * V_77 ,
struct V_78 * * V_79 ,
bool * V_80 )
{
int V_48 ;
int error ;
int V_81 = 0 ;
char * V_13 = NULL ;
T_2 V_43 ;
* V_80 = false ;
V_43 = V_66 > V_75 ? V_75 : 0 ;
for ( V_48 = ( int ) V_66 - 1 ; V_48 >= V_43 ; V_48 -- ) {
error = F_18 ( log , V_48 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_82;
if ( * ( V_83 * ) V_13 == F_30 ( V_33 ) ) {
* V_77 = V_48 ;
* V_79 = (struct V_78 * ) V_13 ;
if ( ++ V_81 == V_76 )
break;
}
}
if ( V_75 >= V_66 && V_81 != V_76 ) {
for ( V_48 = log -> V_3 - 1 ; V_48 >= ( int ) V_75 ; V_48 -- ) {
error = F_18 ( log , V_48 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_82;
if ( * ( V_83 * ) V_13 ==
F_30 ( V_33 ) ) {
* V_80 = true ;
* V_77 = V_48 ;
* V_79 = (struct V_78 * ) V_13 ;
if ( ++ V_81 == V_76 )
break;
}
}
}
return V_81 ;
V_82:
return error ;
}
STATIC int
F_53 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 ,
int V_76 ,
struct V_5 * V_6 ,
T_2 * V_77 ,
struct V_78 * * V_79 ,
bool * V_80 )
{
int V_48 ;
int error ;
int V_81 = 0 ;
char * V_13 = NULL ;
T_2 V_43 ;
* V_80 = false ;
V_43 = V_66 > V_75 ? V_66 : log -> V_3 - 1 ;
for ( V_48 = ( int ) V_75 ; V_48 <= V_43 ; V_48 ++ ) {
error = F_18 ( log , V_48 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_82;
if ( * ( V_83 * ) V_13 == F_30 ( V_33 ) ) {
* V_77 = V_48 ;
* V_79 = (struct V_78 * ) V_13 ;
if ( ++ V_81 == V_76 )
break;
}
}
if ( V_75 > V_66 && V_81 != V_76 ) {
for ( V_48 = 0 ; V_48 < ( int ) V_66 ; V_48 ++ ) {
error = F_18 ( log , V_48 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_82;
if ( * ( V_83 * ) V_13 ==
F_30 ( V_33 ) ) {
* V_80 = true ;
* V_77 = V_48 ;
* V_79 = (struct V_78 * ) V_13 ;
if ( ++ V_81 == V_76 )
break;
}
}
}
return V_81 ;
V_82:
return error ;
}
static inline int
F_54 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 )
{
if ( V_66 < V_75 )
return V_75 - V_66 ;
return V_75 + ( log -> V_3 - V_66 ) ;
}
STATIC int
F_55 (
struct V_1 * log ,
T_2 V_66 ,
T_2 * V_75 ,
int V_84 )
{
struct V_78 * V_85 ;
struct V_5 * V_6 ;
T_2 V_86 ;
int error = 0 ;
bool V_80 ;
T_2 V_87 ;
T_2 V_88 = * V_75 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_52 ;
error = F_53 ( log , V_66 , * V_75 , 1 , V_6 ,
& V_87 , & V_85 , & V_80 ) ;
if ( error < 0 )
goto V_54;
if ( * V_75 != V_87 )
* V_75 = V_87 ;
V_86 = 0 ;
error = F_56 ( log , V_66 , * V_75 ,
V_89 , & V_86 ) ;
while ( ( error == - V_90 || error == - V_16 ) && V_86 ) {
int V_91 ;
V_91 = F_54 ( log , V_66 , V_86 ) ;
if ( V_91 > F_47 ( V_92 * V_84 ) )
break;
error = F_53 ( log , V_66 , V_86 , 2 , V_6 ,
& V_87 , & V_85 , & V_80 ) ;
if ( error < 0 )
goto V_54;
* V_75 = V_87 ;
V_86 = 0 ;
error = F_56 ( log , V_66 , * V_75 ,
V_89 , & V_86 ) ;
}
if ( ! error && * V_75 != V_88 )
F_3 ( log -> V_7 ,
L_15 ,
V_88 , * V_75 ) ;
V_54:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_57 (
struct V_1 * log ,
T_2 * V_66 ,
T_2 * V_75 ,
struct V_5 * V_6 ,
T_2 * V_93 ,
struct V_78 * * V_79 ,
bool * V_80 )
{
struct V_78 * V_94 ;
struct V_5 * V_95 ;
T_2 V_86 ;
T_2 V_96 ;
int V_81 ;
int error ;
bool V_97 ;
V_95 = F_2 ( log , 1 ) ;
if ( ! V_95 )
return - V_52 ;
error = F_52 ( log , * V_66 , * V_75 ,
V_92 , V_95 , & V_96 ,
& V_94 , & V_97 ) ;
F_8 ( V_95 ) ;
if ( error < 0 )
return error ;
error = F_56 ( log , * V_66 , V_96 ,
V_89 , & V_86 ) ;
if ( ( error == - V_90 || error == - V_16 ) && V_86 ) {
error = 0 ;
F_3 ( log -> V_7 ,
L_16 ,
V_86 , * V_66 ) ;
V_81 = F_52 ( log , V_86 , * V_75 , 1 , V_6 ,
V_93 , V_79 , V_80 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_81 == 0 )
return - V_61 ;
* V_66 = V_86 ;
* V_75 = F_58 ( F_59 ( ( * V_79 ) -> V_98 ) ) ;
if ( * V_66 == * V_75 ) {
ASSERT ( 0 ) ;
return 0 ;
}
}
if ( error )
return error ;
return F_55 ( log , * V_66 , V_75 ,
F_28 ( ( * V_79 ) -> V_62 ) ) ;
}
static int
F_60 (
struct V_1 * log ,
T_2 * V_66 ,
T_2 * V_75 ,
struct V_78 * V_79 ,
T_2 V_93 ,
struct V_5 * V_6 ,
bool * V_99 )
{
struct V_100 * V_101 ;
T_2 V_102 ;
T_2 V_103 ;
int V_104 ;
int error ;
char * V_13 ;
* V_99 = false ;
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
int V_62 = F_28 ( V_79 -> V_62 ) ;
int V_105 = F_28 ( V_79 -> V_105 ) ;
if ( ( V_105 & V_106 ) &&
( V_62 > V_63 ) ) {
V_104 = V_62 / V_63 ;
if ( V_62 % V_63 )
V_104 ++ ;
} else {
V_104 = 1 ;
}
} else {
V_104 = 1 ;
}
V_103 = V_93 + V_104 + F_47 ( F_28 ( V_79 -> V_64 ) ) ;
V_103 = F_61 ( V_103 , log -> V_3 ) ;
if ( * V_66 == V_103 &&
F_28 ( V_79 -> V_107 ) == 1 ) {
V_102 = V_93 + V_104 ;
V_102 = F_61 ( V_102 , log -> V_3 ) ;
error = F_18 ( log , V_102 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_101 = (struct V_100 * ) V_13 ;
if ( V_101 -> V_108 & V_109 ) {
F_62 ( & log -> V_110 ,
log -> V_111 , V_103 ) ;
F_62 ( & log -> V_112 ,
log -> V_111 , V_103 ) ;
* V_75 = V_103 ;
* V_99 = true ;
}
}
return 0 ;
}
static void
F_63 (
struct V_1 * log ,
T_2 V_66 ,
struct V_78 * V_79 ,
T_2 V_93 ,
bool V_113 )
{
log -> V_114 = V_93 ;
log -> V_115 = ( int ) V_66 ;
log -> V_111 = F_28 ( V_79 -> V_116 ) ;
if ( V_113 )
log -> V_111 ++ ;
F_64 ( & log -> V_110 , F_59 ( V_79 -> V_98 ) ) ;
F_64 ( & log -> V_112 , F_59 ( V_79 -> V_117 ) ) ;
F_65 ( & log -> V_118 . V_119 , log -> V_111 ,
F_11 ( log -> V_115 ) ) ;
F_65 ( & log -> V_120 . V_119 , log -> V_111 ,
F_11 ( log -> V_115 ) ) ;
}
STATIC int
F_66 (
struct V_1 * log ,
T_2 * V_66 ,
T_2 * V_75 )
{
T_4 * V_79 ;
char * V_13 = NULL ;
T_1 * V_6 ;
int error ;
T_2 V_93 ;
T_6 V_121 ;
bool V_80 = false ;
bool V_99 = false ;
if ( ( error = F_48 ( log , V_66 ) ) )
return error ;
ASSERT ( * V_66 < V_73 ) ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_52 ;
if ( * V_66 == 0 ) {
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_122;
if ( F_41 ( V_13 ) == 0 ) {
* V_75 = 0 ;
goto V_122;
}
}
error = F_52 ( log , * V_66 , * V_66 , 1 , V_6 ,
& V_93 , & V_79 , & V_80 ) ;
if ( error < 0 )
return error ;
if ( ! error ) {
F_3 ( log -> V_7 , L_17 , V_8 ) ;
return - V_61 ;
}
* V_75 = F_58 ( F_59 ( V_79 -> V_98 ) ) ;
F_63 ( log , * V_66 , V_79 , V_93 , V_80 ) ;
V_121 = F_67 ( & log -> V_110 ) ;
error = F_60 ( log , V_66 , V_75 , V_79 ,
V_93 , V_6 , & V_99 ) ;
if ( error )
goto V_122;
if ( ! V_99 ) {
T_2 V_123 = * V_66 ;
error = F_57 ( log , V_66 , V_75 , V_6 ,
& V_93 , & V_79 , & V_80 ) ;
if ( error )
goto V_122;
if ( * V_66 != V_123 ) {
F_63 ( log , * V_66 , V_79 , V_93 ,
V_80 ) ;
V_121 = F_67 ( & log -> V_110 ) ;
error = F_60 ( log , V_66 , V_75 ,
V_79 , V_93 , V_6 ,
& V_99 ) ;
if ( error )
goto V_122;
}
}
if ( V_99 )
log -> V_7 -> V_124 |= V_125 ;
if ( ! F_68 ( log -> V_7 -> V_11 ) )
error = F_69 ( log , V_121 ) ;
V_122:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_18 ) ;
return error ;
}
STATIC int
F_49 (
struct V_1 * log ,
T_2 * V_12 )
{
T_1 * V_6 ;
char * V_13 ;
T_5 V_126 , V_127 ;
T_2 V_47 , V_40 , V_45 ;
T_2 V_67 ;
int error , V_71 = log -> V_3 ;
* V_12 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_52 ;
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_72;
V_126 = F_41 ( V_13 ) ;
if ( V_126 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return 1 ;
}
error = F_18 ( log , V_71 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_72;
V_127 = F_41 ( V_13 ) ;
if ( V_127 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_126 != 1 ) {
F_3 ( log -> V_7 ,
L_19 ) ;
error = - V_128 ;
goto V_72;
}
V_40 = V_71 - 1 ;
if ( ( error = F_39 ( log , V_6 , 0 , & V_40 , 0 ) ) )
goto V_72;
V_67 = F_50 ( log ) ;
ASSERT ( V_67 <= V_73 ) ;
if ( V_40 < V_67 )
V_67 = V_40 ;
V_45 = V_40 - V_67 ;
if ( ( error = F_42 ( log , V_45 ,
( int ) V_67 , 0 , & V_47 ) ) )
goto V_72;
if ( V_47 != - 1 )
V_40 = V_47 ;
error = F_45 ( log , V_45 , & V_40 , 0 ) ;
if ( error == 1 )
error = - V_61 ;
if ( error )
goto V_72;
* V_12 = V_40 ;
V_72:
F_8 ( V_6 ) ;
if ( error )
return error ;
return 1 ;
}
STATIC void
F_70 (
struct V_1 * log ,
char * V_51 ,
int V_41 ,
int V_129 ,
int V_130 ,
int V_131 )
{
T_4 * V_132 = ( T_4 * ) V_51 ;
memset ( V_51 , 0 , V_55 ) ;
V_132 -> V_32 = F_30 ( V_33 ) ;
V_132 -> V_116 = F_30 ( V_41 ) ;
V_132 -> V_105 = F_30 (
F_46 ( & log -> V_7 -> V_27 ) ? 2 : 1 ) ;
V_132 -> V_117 = F_71 ( F_72 ( V_41 , V_129 ) ) ;
V_132 -> V_98 = F_71 ( F_72 ( V_130 , V_131 ) ) ;
V_132 -> V_31 = F_30 ( V_29 ) ;
memcpy ( & V_132 -> V_30 , & log -> V_7 -> V_27 . V_28 , sizeof( V_133 ) ) ;
}
STATIC int
F_73 (
struct V_1 * log ,
int V_41 ,
int V_134 ,
int V_135 ,
int V_130 ,
int V_131 )
{
char * V_13 ;
T_1 * V_6 ;
int V_136 , V_137 ;
int V_138 = log -> V_10 ;
int V_139 = V_134 + V_135 ;
int V_50 ;
int error = 0 ;
int V_48 , V_49 = 0 ;
V_50 = 1 << F_43 ( V_135 ) ;
while ( V_50 > log -> V_3 )
V_50 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_50 ) ) ) {
V_50 >>= 1 ;
if ( V_50 < V_138 )
return - V_52 ;
}
V_136 = F_13 ( V_134 , V_138 ) ;
if ( V_136 != V_134 ) {
error = F_12 ( log , V_134 , 1 , V_6 ) ;
if ( error )
goto V_140;
V_49 = V_134 - V_136 ;
}
for ( V_48 = V_134 ; V_48 < V_139 ; V_48 += V_50 ) {
int V_53 , V_141 ;
V_53 = F_44 ( V_50 , V_139 - V_134 ) ;
V_141 = V_53 - V_49 ;
V_137 = F_13 ( V_139 , V_138 ) ;
if ( V_49 == 0 && ( V_134 + V_141 > V_137 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_137 - V_134 ) ;
error = F_19 ( log , V_137 , V_138 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_134 , V_141 , V_6 ) ;
for (; V_49 < V_141 ; V_49 ++ ) {
F_70 ( log , V_13 , V_41 , V_48 + V_49 ,
V_130 , V_131 ) ;
V_13 += V_55 ;
}
error = F_21 ( log , V_134 , V_141 , V_6 ) ;
if ( error )
break;
V_134 += V_141 ;
V_49 = 0 ;
}
V_140:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_69 (
struct V_1 * log ,
T_6 V_121 )
{
int V_130 , V_142 ;
int V_131 , V_143 ;
int V_91 , V_144 ;
int V_145 ;
int error ;
V_130 = F_74 ( V_121 ) ;
V_131 = F_58 ( V_121 ) ;
V_142 = log -> V_111 ;
V_143 = log -> V_115 ;
if ( V_142 == V_130 ) {
if ( F_31 ( V_143 < V_131 || V_143 >= log -> V_3 ) ) {
F_4 ( L_20 ,
V_146 , log -> V_7 ) ;
return - V_16 ;
}
V_91 = V_131 + ( log -> V_3 - V_143 ) ;
} else {
if ( F_31 ( V_143 >= V_131 || V_142 != ( V_130 + 1 ) ) ) {
F_4 ( L_21 ,
V_146 , log -> V_7 ) ;
return - V_16 ;
}
V_91 = V_131 - V_143 ;
}
if ( V_91 <= 0 ) {
ASSERT ( V_91 == 0 ) ;
return 0 ;
}
V_144 = F_50 ( log ) ;
V_144 = F_75 ( V_144 , V_91 ) ;
if ( ( V_143 + V_144 ) <= log -> V_3 ) {
error = F_73 ( log , ( V_142 - 1 ) ,
V_143 , V_144 , V_130 ,
V_131 ) ;
if ( error )
return error ;
} else {
V_145 = log -> V_3 - V_143 ;
error = F_73 ( log , ( V_142 - 1 ) ,
V_143 , V_145 , V_130 ,
V_131 ) ;
if ( error )
return error ;
V_145 = V_144 - ( log -> V_3 - V_143 ) ;
error = F_73 ( log , V_142 , 0 , V_145 ,
V_130 , V_131 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_76 (
struct V_1 * log ,
struct V_147 * V_148 ,
int V_149 )
{
T_7 * V_150 , * V_151 ;
int error = 0 ;
F_77 ( V_152 ) ;
F_77 ( V_153 ) ;
F_77 ( V_154 ) ;
F_77 ( V_155 ) ;
F_77 ( V_156 ) ;
F_78 ( & V_148 -> V_157 , & V_152 ) ;
F_79 (item, n, &sort_list, ri_list) {
T_8 * V_158 = V_150 -> V_159 [ 0 ] . V_160 ;
switch ( F_80 ( V_150 ) ) {
case V_161 :
F_81 ( & V_150 -> V_162 , & V_154 ) ;
break;
case V_163 :
if ( V_158 -> V_164 & V_165 ) {
F_82 ( log ,
V_148 , V_150 , V_149 ) ;
F_83 ( & V_150 -> V_162 , & V_153 ) ;
break;
}
if ( V_158 -> V_164 & V_166 ) {
F_83 ( & V_150 -> V_162 , & V_155 ) ;
break;
}
F_81 ( & V_150 -> V_162 , & V_154 ) ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
F_84 ( log ,
V_148 , V_150 , V_149 ) ;
F_81 ( & V_150 -> V_162 , & V_156 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_22 ,
V_8 ) ;
ASSERT ( 0 ) ;
if ( ! F_85 ( & V_152 ) )
F_78 ( & V_152 , & V_148 -> V_157 ) ;
error = - V_61 ;
goto V_54;
}
}
V_54:
ASSERT ( F_85 ( & V_152 ) ) ;
if ( ! F_85 ( & V_154 ) )
F_86 ( & V_154 , & V_148 -> V_157 ) ;
if ( ! F_85 ( & V_156 ) )
F_87 ( & V_156 , & V_148 -> V_157 ) ;
if ( ! F_85 ( & V_155 ) )
F_87 ( & V_155 , & V_148 -> V_157 ) ;
if ( ! F_85 ( & V_153 ) )
F_87 ( & V_153 , & V_148 -> V_157 ) ;
return error ;
}
STATIC int
F_88 (
struct V_1 * log ,
struct V_178 * V_150 )
{
T_8 * V_158 = V_150 -> V_159 [ 0 ] . V_160 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
if ( ! ( V_158 -> V_164 & V_165 ) ) {
F_89 ( log , V_158 ) ;
return 0 ;
}
V_180 = F_90 ( log , V_158 -> V_183 ) ;
F_91 (bcp, bucket, bc_list) {
if ( V_182 -> V_184 == V_158 -> V_183 &&
V_182 -> V_185 == V_158 -> V_186 ) {
V_182 -> V_187 ++ ;
F_92 ( log , V_158 ) ;
return 0 ;
}
}
V_182 = F_93 ( sizeof( struct V_181 ) , V_188 ) ;
V_182 -> V_184 = V_158 -> V_183 ;
V_182 -> V_185 = V_158 -> V_186 ;
V_182 -> V_187 = 1 ;
F_94 ( & V_182 -> V_189 , V_180 ) ;
F_95 ( log , V_158 ) ;
return 0 ;
}
STATIC struct V_181 *
F_96 (
struct V_1 * log ,
T_2 V_190 ,
T_5 V_191 ,
unsigned short V_192 )
{
struct V_179 * V_180 ;
struct V_181 * V_182 ;
if ( ! log -> V_193 ) {
ASSERT ( ! ( V_192 & V_165 ) ) ;
return NULL ;
}
V_180 = F_90 ( log , V_190 ) ;
F_91 (bcp, bucket, bc_list) {
if ( V_182 -> V_184 == V_190 && V_182 -> V_185 == V_191 )
return V_182 ;
}
ASSERT ( ! ( V_192 & V_165 ) ) ;
return NULL ;
}
STATIC int
F_97 (
struct V_1 * log ,
T_2 V_190 ,
T_5 V_191 ,
unsigned short V_192 )
{
struct V_181 * V_182 ;
V_182 = F_96 ( log , V_190 , V_191 , V_192 ) ;
if ( ! V_182 )
return 0 ;
if ( V_192 & V_165 ) {
if ( -- V_182 -> V_187 == 0 ) {
F_98 ( & V_182 -> V_189 ) ;
F_99 ( V_182 ) ;
}
}
return 1 ;
}
STATIC int
F_100 (
struct V_194 * V_25 ,
T_7 * V_150 ,
struct V_5 * V_6 ,
T_8 * V_158 )
{
int V_48 ;
int V_195 = 0 ;
int V_196 = 0 ;
int V_197 = 0 ;
int V_198 = 0 ;
int V_199 = 0 ;
int V_200 ;
int V_201 ;
T_9 * V_202 ;
T_9 * V_203 ;
F_101 ( V_25 -> V_204 , V_158 ) ;
if ( F_102 ( & V_25 -> V_27 ) )
V_6 -> V_205 = & V_206 ;
V_201 = F_11 ( V_6 -> V_20 ) >> V_25 -> V_27 . V_207 ;
for ( V_48 = 0 ; V_48 < V_201 ; V_48 ++ ) {
V_200 = ( V_48 * V_25 -> V_27 . V_208 ) +
F_103 ( V_209 , V_210 ) ;
while ( V_200 >=
( V_198 + V_199 ) ) {
V_196 += V_197 ;
V_196 = F_104 ( V_158 -> V_211 ,
V_158 -> V_212 , V_196 ) ;
if ( V_196 == - 1 )
return 0 ;
V_197 = F_105 ( V_158 -> V_211 ,
V_158 -> V_212 , V_196 ) ;
ASSERT ( V_197 > 0 ) ;
V_198 = V_196 << V_213 ;
V_199 = V_197 << V_213 ;
V_195 ++ ;
}
if ( V_200 < V_198 )
continue;
ASSERT ( V_150 -> V_159 [ V_195 ] . V_160 != NULL ) ;
ASSERT ( ( V_150 -> V_159 [ V_195 ] . V_214 % V_215 ) == 0 ) ;
ASSERT ( ( V_198 + V_199 ) <=
F_11 ( V_6 -> V_20 ) ) ;
V_202 = V_150 -> V_159 [ V_195 ] . V_160 +
V_200 - V_198 ;
if ( F_31 ( * V_202 == 0 ) ) {
F_106 ( V_25 ,
L_23
L_24 ,
V_150 , V_6 ) ;
F_4 ( L_25 ,
V_146 , V_25 ) ;
return - V_16 ;
}
V_203 = F_107 ( V_6 , V_200 ) ;
* V_203 = * V_202 ;
F_108 ( V_25 ,
F_107 ( V_6 , V_48 * V_25 -> V_27 . V_208 ) ) ;
}
return 0 ;
}
static T_6
F_109 (
struct V_194 * V_25 ,
struct V_5 * V_6 )
{
T_10 V_216 ;
T_11 V_217 ;
T_11 V_218 ;
void * V_219 = V_6 -> V_15 ;
V_133 * V_220 ;
T_6 V_221 = - 1 ;
if ( ! F_102 ( & V_25 -> V_27 ) )
goto V_222;
V_216 = F_28 ( * ( V_83 * ) V_219 ) ;
switch ( V_216 ) {
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 : {
struct V_231 * V_232 = V_219 ;
V_221 = F_59 ( V_232 -> V_233 . V_234 . V_235 ) ;
V_220 = & V_232 -> V_233 . V_234 . V_236 ;
break;
}
case V_237 :
case V_238 : {
struct V_231 * V_232 = V_219 ;
V_221 = F_59 ( V_232 -> V_233 . V_239 . V_235 ) ;
V_220 = & V_232 -> V_233 . V_239 . V_236 ;
break;
}
case V_240 :
V_221 = F_59 ( ( (struct V_241 * ) V_219 ) -> V_242 ) ;
V_220 = & ( (struct V_241 * ) V_219 ) -> V_243 ;
break;
case V_244 :
V_221 = F_59 ( ( (struct V_245 * ) V_219 ) -> V_246 ) ;
V_220 = & ( (struct V_245 * ) V_219 ) -> V_247 ;
break;
case V_248 :
V_221 = F_59 ( ( (struct V_249 * ) V_219 ) -> V_250 ) ;
V_220 = & ( (struct V_249 * ) V_219 ) -> V_251 ;
break;
case V_252 :
V_221 = F_59 ( ( (struct V_253 * ) V_219 ) -> V_254 ) ;
V_220 = & ( (struct V_253 * ) V_219 ) -> V_255 ;
break;
case V_256 :
case V_257 :
case V_258 :
V_221 = F_59 ( ( (struct V_259 * ) V_219 ) -> V_221 ) ;
V_220 = & ( (struct V_259 * ) V_219 ) -> V_220 ;
break;
case V_260 :
goto V_222;
case V_261 :
V_221 = F_59 ( ( (struct V_262 * ) V_219 ) -> V_263 ) ;
if ( F_110 ( & V_25 -> V_27 ) )
V_220 = & ( (struct V_262 * ) V_219 ) -> V_264 ;
else
V_220 = & ( (struct V_262 * ) V_219 ) -> V_28 ;
break;
default:
break;
}
if ( V_221 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_264 , V_220 ) )
goto V_222;
return V_221 ;
}
V_218 = F_111 ( ( (struct V_265 * ) V_219 ) -> V_266 ) ;
switch ( V_218 ) {
case V_267 :
case V_268 :
case V_269 :
V_221 = F_59 ( ( (struct V_270 * ) V_219 ) -> V_221 ) ;
V_220 = & ( (struct V_270 * ) V_219 ) -> V_220 ;
break;
default:
break;
}
if ( V_221 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_28 , V_220 ) )
goto V_222;
return V_221 ;
}
V_217 = F_111 ( * ( V_271 * ) V_219 ) ;
switch ( V_217 ) {
case V_272 :
case V_273 :
goto V_222;
default:
break;
}
V_222:
return ( T_6 ) - 1 ;
}
static void
F_112 (
struct V_194 * V_25 ,
struct V_5 * V_6 ,
T_8 * V_158 ,
T_6 V_274 )
{
struct V_265 * V_275 = V_6 -> V_15 ;
T_10 V_216 ;
T_11 V_217 ;
T_11 V_218 ;
char * V_276 = NULL ;
if ( ! F_102 ( & V_25 -> V_27 ) )
return;
V_216 = F_28 ( * ( V_83 * ) V_6 -> V_15 ) ;
V_217 = F_111 ( * ( V_271 * ) V_6 -> V_15 ) ;
V_218 = F_111 ( V_275 -> V_266 ) ;
switch ( F_113 ( V_158 ) ) {
case V_277 :
switch ( V_216 ) {
case V_223 :
case V_224 :
case V_225 :
case V_226 :
V_6 -> V_205 = & V_278 ;
break;
case V_229 :
case V_279 :
case V_230 :
case V_280 :
V_6 -> V_205 = & V_281 ;
break;
case V_237 :
case V_238 :
V_6 -> V_205 = & V_282 ;
break;
case V_227 :
V_6 -> V_205 = & V_283 ;
break;
case V_228 :
V_6 -> V_205 = & V_284 ;
break;
default:
V_276 = L_26 ;
break;
}
break;
case V_285 :
if ( V_216 != V_240 ) {
V_276 = L_27 ;
break;
}
V_6 -> V_205 = & V_286 ;
break;
case V_287 :
if ( V_216 != V_244 ) {
V_276 = L_28 ;
break;
}
V_6 -> V_205 = & V_288 ;
break;
case V_289 :
if ( V_216 != V_248 ) {
V_276 = L_29 ;
break;
}
V_6 -> V_205 = & V_290 ;
break;
case V_291 :
case V_292 :
case V_293 :
#ifdef F_114
if ( V_217 != V_272 ) {
V_276 = L_30 ;
break;
}
V_6 -> V_205 = & V_294 ;
#else
F_106 ( V_25 ,
L_31 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_295 :
if ( V_217 != V_273 ) {
V_276 = L_32 ;
break;
}
V_6 -> V_205 = & V_206 ;
break;
case V_296 :
if ( V_216 != V_252 ) {
V_276 = L_33 ;
break;
}
V_6 -> V_205 = & V_297 ;
break;
case V_298 :
if ( V_216 != V_299 &&
V_216 != V_256 ) {
V_276 = L_34 ;
break;
}
V_6 -> V_205 = & V_300 ;
break;
case V_301 :
if ( V_216 != V_302 &&
V_216 != V_257 ) {
V_276 = L_35 ;
break;
}
V_6 -> V_205 = & V_303 ;
break;
case V_304 :
if ( V_216 != V_305 &&
V_216 != V_258 ) {
V_276 = L_36 ;
break;
}
V_6 -> V_205 = & V_306 ;
break;
case V_307 :
if ( V_218 != V_308 &&
V_218 != V_267 ) {
V_276 = L_37 ;
break;
}
V_6 -> V_205 = & V_309 ;
break;
case V_310 :
if ( V_218 != V_311 &&
V_218 != V_268 ) {
V_276 = L_38 ;
break;
}
V_6 -> V_205 = & V_312 ;
break;
case V_313 :
if ( V_218 != V_314 &&
V_218 != V_269 ) {
V_276 = L_39 ;
break;
}
V_6 -> V_205 = & V_315 ;
break;
case V_316 :
if ( V_218 != V_317 &&
V_218 != V_318 ) {
V_276 = L_40 ;
break;
}
V_6 -> V_205 = & V_319 ;
break;
case V_320 :
if ( V_216 != V_260 ) {
V_276 = L_41 ;
break;
}
V_6 -> V_205 = & V_321 ;
break;
case V_322 :
if ( V_216 != V_261 ) {
V_276 = L_42 ;
break;
}
V_6 -> V_205 = & V_323 ;
break;
#ifdef F_115
case V_324 :
case V_325 :
V_6 -> V_205 = & V_326 ;
break;
#endif
default:
F_3 ( V_25 , L_43 ,
F_113 ( V_158 ) ) ;
break;
}
if ( V_274 == V_327 )
return;
if ( V_276 ) {
F_3 ( V_25 , V_276 ) ;
ASSERT ( 0 ) ;
}
if ( V_6 -> V_205 ) {
struct V_328 * V_329 ;
ASSERT ( ! V_6 -> V_38 || V_6 -> V_38 == F_35 ) ;
V_6 -> V_38 = F_35 ;
F_116 ( V_6 , V_25 ) ;
V_329 = V_6 -> V_37 ;
V_329 -> V_330 . V_331 = V_274 ;
}
}
STATIC void
F_117 (
struct V_194 * V_25 ,
T_7 * V_150 ,
struct V_5 * V_6 ,
T_8 * V_158 ,
T_6 V_274 )
{
int V_48 ;
int V_196 ;
int V_197 ;
int error ;
F_118 ( V_25 -> V_204 , V_158 ) ;
V_196 = 0 ;
V_48 = 1 ;
while ( 1 ) {
V_196 = F_104 ( V_158 -> V_211 ,
V_158 -> V_212 , V_196 ) ;
if ( V_196 == - 1 )
break;
V_197 = F_105 ( V_158 -> V_211 ,
V_158 -> V_212 , V_196 ) ;
ASSERT ( V_197 > 0 ) ;
ASSERT ( V_150 -> V_159 [ V_48 ] . V_160 != NULL ) ;
ASSERT ( V_150 -> V_159 [ V_48 ] . V_214 % V_215 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_20 ) >=
( ( T_5 ) V_196 << V_213 ) + ( V_197 << V_213 ) ) ;
if ( V_150 -> V_159 [ V_48 ] . V_214 < ( V_197 << V_213 ) )
V_197 = V_150 -> V_159 [ V_48 ] . V_214 >> V_213 ;
error = 0 ;
if ( V_158 -> V_164 &
( V_332 | V_333 | V_334 ) ) {
if ( V_150 -> V_159 [ V_48 ] . V_160 == NULL ) {
F_106 ( V_25 ,
L_44 , V_8 ) ;
goto V_335;
}
if ( V_150 -> V_159 [ V_48 ] . V_214 < sizeof( V_336 ) ) {
F_106 ( V_25 ,
L_45 ,
V_150 -> V_159 [ V_48 ] . V_214 , V_8 ) ;
goto V_335;
}
error = F_119 ( V_25 , V_150 -> V_159 [ V_48 ] . V_160 ,
- 1 , 0 , V_337 ,
L_46 ) ;
if ( error )
goto V_335;
}
memcpy ( F_107 ( V_6 ,
( T_5 ) V_196 << V_213 ) ,
V_150 -> V_159 [ V_48 ] . V_160 ,
V_197 << V_213 ) ;
V_335:
V_48 ++ ;
V_196 += V_197 ;
}
ASSERT ( V_48 == V_150 -> V_338 ) ;
F_112 ( V_25 , V_6 , V_158 , V_274 ) ;
}
STATIC bool
F_120 (
struct V_194 * V_25 ,
struct V_1 * log ,
struct V_178 * V_150 ,
struct V_5 * V_6 ,
struct V_339 * V_158 )
{
T_5 type ;
F_121 ( log , V_158 ) ;
if ( ! V_25 -> V_340 )
return false ;
type = 0 ;
if ( V_158 -> V_164 & V_332 )
type |= V_341 ;
if ( V_158 -> V_164 & V_333 )
type |= V_342 ;
if ( V_158 -> V_164 & V_334 )
type |= V_343 ;
if ( log -> V_344 & type )
return false ;
F_117 ( V_25 , V_150 , V_6 , V_158 , V_327 ) ;
return true ;
}
STATIC int
F_122 (
struct V_1 * log ,
struct V_179 * V_154 ,
struct V_178 * V_150 ,
T_6 V_274 )
{
T_8 * V_158 = V_150 -> V_159 [ 0 ] . V_160 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_5 V_345 ;
T_6 V_221 ;
if ( F_97 ( log , V_158 -> V_183 ,
V_158 -> V_186 , V_158 -> V_164 ) ) {
F_123 ( log , V_158 ) ;
return 0 ;
}
F_124 ( log , V_158 ) ;
V_345 = 0 ;
if ( V_158 -> V_164 & V_166 )
V_345 |= V_346 ;
V_6 = F_125 ( V_25 -> V_347 , V_158 -> V_183 , V_158 -> V_186 ,
V_345 , NULL ) ;
if ( ! V_6 )
return - V_52 ;
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_47 ) ;
goto V_348;
}
V_221 = F_109 ( V_25 , V_6 ) ;
if ( V_221 && V_221 != - 1 && F_126 ( V_221 , V_274 ) >= 0 ) {
F_127 ( log , V_158 ) ;
F_112 ( V_25 , V_6 , V_158 , V_327 ) ;
goto V_348;
}
if ( V_158 -> V_164 & V_166 ) {
error = F_100 ( V_25 , V_150 , V_6 , V_158 ) ;
if ( error )
goto V_348;
} else if ( V_158 -> V_164 &
( V_332 | V_333 | V_334 ) ) {
bool V_349 ;
V_349 = F_120 ( V_25 , log , V_150 , V_6 , V_158 ) ;
if ( ! V_349 )
goto V_348;
} else {
F_117 ( V_25 , V_150 , V_6 , V_158 , V_274 ) ;
}
if ( V_273 ==
F_111 ( * ( ( V_271 * ) F_107 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_20 ) != F_128 ( log -> V_7 -> V_27 . V_350 ,
( T_10 ) log -> V_7 -> V_351 ) ) ) {
F_129 ( V_6 ) ;
error = F_24 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_38 = F_35 ;
F_130 ( V_6 , V_154 ) ;
}
V_348:
F_25 ( V_6 ) ;
return error ;
}
STATIC int
F_131 (
struct V_194 * V_25 ,
struct V_352 * V_353 ,
struct V_354 * V_355 ,
struct V_179 * V_154 )
{
struct V_356 * V_357 ;
int error ;
ASSERT ( V_355 -> V_358 & ( V_359 | V_360 ) ) ;
V_357 = F_132 ( V_25 , V_355 -> V_361 ) ;
if ( ! V_357 )
return - V_52 ;
F_133 ( V_357 , V_353 ) ;
ASSERT ( V_357 -> V_362 . V_363 >= 3 ) ;
error = F_134 ( V_357 , V_353 ) ;
if ( error )
goto V_364;
if ( V_355 -> V_358 & V_359 ) {
ASSERT ( V_355 -> V_358 & V_365 ) ;
error = F_135 ( NULL , V_357 , V_366 ,
V_357 -> V_367 , V_154 ) ;
if ( error )
goto V_364;
}
if ( V_355 -> V_358 & V_360 ) {
ASSERT ( V_355 -> V_358 & V_368 ) ;
error = F_135 ( NULL , V_357 , V_369 ,
V_357 -> V_367 , V_154 ) ;
if ( error )
goto V_364;
}
V_364:
F_136 ( V_357 ) ;
return error ;
}
STATIC int
F_137 (
struct V_1 * log ,
struct V_179 * V_154 ,
struct V_178 * V_150 ,
T_6 V_274 )
{
T_12 * V_355 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
V_209 * V_353 ;
int V_191 ;
char * V_370 ;
char * V_371 ;
int error ;
int V_372 ;
T_5 V_373 ;
struct V_374 * V_375 ;
T_5 V_376 ;
int V_377 = 0 ;
if ( V_150 -> V_159 [ 0 ] . V_214 == sizeof( T_12 ) ) {
V_355 = V_150 -> V_159 [ 0 ] . V_160 ;
} else {
V_355 = F_93 ( sizeof( T_12 ) , V_188 ) ;
V_377 = 1 ;
error = F_138 ( & V_150 -> V_159 [ 0 ] , V_355 ) ;
if ( error )
goto error;
}
if ( F_97 ( log , V_355 -> V_378 ,
V_355 -> V_379 , 0 ) ) {
error = 0 ;
F_139 ( log , V_355 ) ;
goto error;
}
F_140 ( log , V_355 ) ;
V_6 = F_125 ( V_25 -> V_347 , V_355 -> V_378 , V_355 -> V_379 , 0 ,
& V_206 ) ;
if ( ! V_6 ) {
error = - V_52 ;
goto error;
}
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_48 ) ;
goto V_348;
}
ASSERT ( V_355 -> V_358 & V_380 ) ;
V_353 = F_107 ( V_6 , V_355 -> V_381 ) ;
if ( F_31 ( V_353 -> V_382 != F_141 ( V_273 ) ) ) {
F_106 ( V_25 ,
L_49 ,
V_8 , V_353 , V_6 , V_355 -> V_361 ) ;
F_4 ( L_50 ,
V_146 , V_25 ) ;
error = - V_16 ;
goto V_348;
}
V_375 = V_150 -> V_159 [ 1 ] . V_160 ;
if ( F_31 ( V_375 -> V_382 != V_273 ) ) {
F_106 ( V_25 ,
L_51 ,
V_8 , V_150 , V_355 -> V_361 ) ;
F_4 ( L_52 ,
V_146 , V_25 ) ;
error = - V_16 ;
goto V_348;
}
if ( V_353 -> V_363 >= 3 ) {
T_6 V_221 = F_59 ( V_353 -> V_383 ) ;
if ( V_221 && V_221 != - 1 && F_126 ( V_221 , V_274 ) >= 0 ) {
F_142 ( log , V_355 ) ;
error = 0 ;
goto V_384;
}
}
if ( ! F_102 ( & V_25 -> V_27 ) &&
V_375 -> V_385 < F_111 ( V_353 -> V_385 ) ) {
if ( F_111 ( V_353 -> V_385 ) == V_386 &&
V_375 -> V_385 < ( V_386 >> 1 ) ) {
} else {
F_142 ( log , V_355 ) ;
error = 0 ;
goto V_348;
}
}
V_375 -> V_385 = 0 ;
if ( F_31 ( F_143 ( V_375 -> V_387 ) ) ) {
if ( ( V_375 -> V_388 != V_389 ) &&
( V_375 -> V_388 != V_390 ) ) {
F_144 ( L_53 ,
V_146 , V_25 , V_375 ) ;
F_106 ( V_25 ,
L_54
L_55 ,
V_8 , V_150 , V_353 , V_6 , V_355 -> V_361 ) ;
error = - V_16 ;
goto V_348;
}
} else if ( F_31 ( F_145 ( V_375 -> V_387 ) ) ) {
if ( ( V_375 -> V_388 != V_389 ) &&
( V_375 -> V_388 != V_390 ) &&
( V_375 -> V_388 != V_391 ) ) {
F_144 ( L_56 ,
V_146 , V_25 , V_375 ) ;
F_106 ( V_25 ,
L_57
L_55 ,
V_8 , V_150 , V_353 , V_6 , V_355 -> V_361 ) ;
error = - V_16 ;
goto V_348;
}
}
if ( F_31 ( V_375 -> V_392 + V_375 -> V_393 > V_375 -> V_394 ) ) {
F_144 ( L_58 ,
V_146 , V_25 , V_375 ) ;
F_106 ( V_25 ,
L_59
L_60 ,
V_8 , V_150 , V_353 , V_6 , V_355 -> V_361 ,
V_375 -> V_392 + V_375 -> V_393 ,
V_375 -> V_394 ) ;
error = - V_16 ;
goto V_348;
}
if ( F_31 ( V_375 -> V_395 > V_25 -> V_27 . V_208 ) ) {
F_144 ( L_61 ,
V_146 , V_25 , V_375 ) ;
F_106 ( V_25 ,
L_59
L_62 , V_8 ,
V_150 , V_353 , V_6 , V_355 -> V_361 , V_375 -> V_395 ) ;
error = - V_16 ;
goto V_348;
}
V_376 = F_146 ( V_375 -> V_363 ) ;
if ( F_31 ( V_150 -> V_159 [ 1 ] . V_214 > V_376 ) ) {
F_144 ( L_63 ,
V_146 , V_25 , V_375 ) ;
F_106 ( V_25 ,
L_64 ,
V_8 , V_150 -> V_159 [ 1 ] . V_214 , V_150 ) ;
error = - V_16 ;
goto V_348;
}
F_147 ( V_375 , V_353 ) ;
if ( V_150 -> V_159 [ 1 ] . V_214 > V_376 ) {
memcpy ( ( char * ) V_353 + V_376 ,
V_150 -> V_159 [ 1 ] . V_160 + V_376 ,
V_150 -> V_159 [ 1 ] . V_214 - V_376 ) ;
}
V_373 = V_355 -> V_358 ;
switch ( V_373 & ( V_396 | V_397 ) ) {
case V_396 :
F_148 ( V_353 , V_355 -> V_398 . V_399 ) ;
break;
case V_397 :
memcpy ( F_149 ( V_353 ) ,
& V_355 -> V_398 . V_400 ,
sizeof( V_133 ) ) ;
break;
}
if ( V_355 -> V_401 == 2 )
goto V_384;
V_191 = V_150 -> V_159 [ 2 ] . V_214 ;
V_370 = V_150 -> V_159 [ 2 ] . V_160 ;
ASSERT ( V_355 -> V_401 <= 4 ) ;
ASSERT ( ( V_355 -> V_401 == 3 ) || ( V_373 & V_402 ) ) ;
ASSERT ( ! ( V_373 & V_403 ) ||
( V_191 == V_355 -> V_404 ) ) ;
switch ( V_373 & V_403 ) {
case V_405 :
case V_406 :
memcpy ( F_149 ( V_353 ) , V_370 , V_191 ) ;
break;
case V_365 :
F_150 ( V_25 , (struct V_231 * ) V_370 , V_191 ,
( V_407 * ) F_149 ( V_353 ) ,
F_151 ( V_353 , V_25 ) ) ;
break;
default:
ASSERT ( ( V_373 & V_403 ) == 0 ) ;
break;
}
if ( V_355 -> V_358 & V_402 ) {
if ( V_355 -> V_358 & V_403 ) {
V_372 = 3 ;
} else {
V_372 = 2 ;
}
V_191 = V_150 -> V_159 [ V_372 ] . V_214 ;
V_370 = V_150 -> V_159 [ V_372 ] . V_160 ;
ASSERT ( V_191 == V_355 -> V_408 ) ;
switch ( V_355 -> V_358 & V_402 ) {
case V_409 :
case V_410 :
V_371 = F_152 ( V_353 ) ;
ASSERT ( V_191 <= F_153 ( V_353 , V_25 ) ) ;
memcpy ( V_371 , V_370 , V_191 ) ;
break;
case V_368 :
V_371 = F_152 ( V_353 ) ;
F_150 ( V_25 , (struct V_231 * ) V_370 ,
V_191 , ( V_407 * ) V_371 ,
F_153 ( V_353 , V_25 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_65 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_61 ;
goto V_348;
}
}
V_384:
if ( V_355 -> V_358 & ( V_359 | V_360 ) )
error = F_131 ( V_25 , V_353 , V_355 ,
V_154 ) ;
F_108 ( log -> V_7 , V_353 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_38 = F_35 ;
F_130 ( V_6 , V_154 ) ;
V_348:
F_25 ( V_6 ) ;
error:
if ( V_377 )
F_99 ( V_355 ) ;
return error ;
}
STATIC int
F_154 (
struct V_1 * log ,
struct V_178 * V_150 )
{
T_13 * V_411 = V_150 -> V_159 [ 0 ] . V_160 ;
ASSERT ( V_411 ) ;
if ( V_411 -> V_412 & V_413 )
log -> V_344 |= V_341 ;
if ( V_411 -> V_412 & V_414 )
log -> V_344 |= V_342 ;
if ( V_411 -> V_412 & V_415 )
log -> V_344 |= V_343 ;
return 0 ;
}
STATIC int
F_155 (
struct V_1 * log ,
struct V_179 * V_154 ,
struct V_178 * V_150 ,
T_6 V_274 )
{
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
struct V_416 * V_417 , * V_418 ;
int error ;
T_14 * V_419 ;
T_5 type ;
if ( V_25 -> V_340 == 0 )
return 0 ;
V_418 = V_150 -> V_159 [ 1 ] . V_160 ;
if ( V_418 == NULL ) {
F_106 ( log -> V_7 , L_66 , V_8 ) ;
return - V_61 ;
}
if ( V_150 -> V_159 [ 1 ] . V_214 < sizeof( V_336 ) ) {
F_106 ( log -> V_7 , L_67 ,
V_150 -> V_159 [ 1 ] . V_214 , V_8 ) ;
return - V_61 ;
}
type = V_418 -> V_420 & ( V_341 | V_342 | V_343 ) ;
ASSERT ( type ) ;
if ( log -> V_344 & type )
return 0 ;
V_419 = V_150 -> V_159 [ 0 ] . V_160 ;
ASSERT ( V_419 ) ;
error = F_119 ( V_25 , V_418 , V_419 -> V_421 , 0 , V_337 ,
L_68 ) ;
if ( error )
return - V_61 ;
ASSERT ( V_419 -> V_422 == 1 ) ;
error = F_156 ( V_25 , NULL , V_25 -> V_347 , V_419 -> V_423 ,
F_157 ( V_25 , V_419 -> V_422 ) , 0 , & V_6 ,
& V_294 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_417 = F_107 ( V_6 , V_419 -> V_424 ) ;
if ( F_102 ( & V_25 -> V_27 ) ) {
struct V_425 * V_426 = (struct V_425 * ) V_417 ;
T_6 V_221 = F_59 ( V_426 -> V_427 ) ;
if ( V_221 && V_221 != - 1 && F_126 ( V_221 , V_274 ) >= 0 ) {
goto V_348;
}
}
memcpy ( V_417 , V_418 , V_150 -> V_159 [ 1 ] . V_214 ) ;
if ( F_102 ( & V_25 -> V_27 ) ) {
F_158 ( ( char * ) V_417 , sizeof( struct V_425 ) ,
V_428 ) ;
}
ASSERT ( V_419 -> V_429 == 2 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_38 = F_35 ;
F_130 ( V_6 , V_154 ) ;
V_348:
F_25 ( V_6 ) ;
return 0 ;
}
STATIC int
F_159 (
struct V_1 * log ,
struct V_178 * V_150 ,
T_6 V_221 )
{
int error ;
struct V_194 * V_25 = log -> V_7 ;
struct V_430 * V_431 ;
struct V_432 * V_433 ;
V_433 = V_150 -> V_159 [ 0 ] . V_160 ;
V_431 = F_160 ( V_25 , V_433 -> V_434 ) ;
error = F_161 ( & V_150 -> V_159 [ 0 ] , & V_431 -> V_435 ) ;
if ( error ) {
F_162 ( V_431 ) ;
return error ;
}
F_163 ( & V_431 -> V_436 , V_433 -> V_434 ) ;
F_164 ( & log -> V_437 -> V_438 ) ;
F_165 ( log -> V_437 , & V_431 -> V_439 , V_221 ) ;
F_166 ( V_431 ) ;
return 0 ;
}
STATIC int
F_167 (
struct V_1 * log ,
struct V_178 * V_150 )
{
T_15 * V_440 ;
T_16 * V_431 = NULL ;
T_17 * V_441 ;
T_18 V_442 ;
struct V_443 V_444 ;
struct V_445 * V_446 = log -> V_437 ;
V_440 = V_150 -> V_159 [ 0 ] . V_160 ;
ASSERT ( ( V_150 -> V_159 [ 0 ] . V_214 == ( sizeof( V_447 ) +
( ( V_440 -> V_448 - 1 ) * sizeof( V_449 ) ) ) ) ||
( V_150 -> V_159 [ 0 ] . V_214 == ( sizeof( V_450 ) +
( ( V_440 -> V_448 - 1 ) * sizeof( V_451 ) ) ) ) ) ;
V_442 = V_440 -> V_452 ;
F_164 ( & V_446 -> V_438 ) ;
V_441 = F_168 ( V_446 , & V_444 , 0 ) ;
while ( V_441 != NULL ) {
if ( V_441 -> V_453 == V_171 ) {
V_431 = ( T_16 * ) V_441 ;
if ( V_431 -> V_435 . V_442 == V_442 ) {
F_169 ( & V_446 -> V_438 ) ;
F_166 ( V_431 ) ;
F_164 ( & V_446 -> V_438 ) ;
break;
}
}
V_441 = F_170 ( V_446 , & V_444 ) ;
}
F_171 ( & V_444 ) ;
F_169 ( & V_446 -> V_438 ) ;
return 0 ;
}
STATIC int
F_172 (
struct V_1 * log ,
struct V_178 * V_150 ,
T_6 V_221 )
{
int error ;
struct V_194 * V_25 = log -> V_7 ;
struct V_454 * V_455 ;
struct V_456 * V_457 ;
V_457 = V_150 -> V_159 [ 0 ] . V_160 ;
V_455 = F_173 ( V_25 , V_457 -> V_458 ) ;
error = F_174 ( & V_150 -> V_159 [ 0 ] , & V_455 -> V_459 ) ;
if ( error ) {
F_175 ( V_455 ) ;
return error ;
}
F_163 ( & V_455 -> V_460 , V_457 -> V_458 ) ;
F_164 ( & log -> V_437 -> V_438 ) ;
F_165 ( log -> V_437 , & V_455 -> V_461 , V_221 ) ;
F_176 ( V_455 ) ;
return 0 ;
}
STATIC int
F_177 (
struct V_1 * log ,
struct V_178 * V_150 )
{
struct V_462 * V_463 ;
struct V_454 * V_455 = NULL ;
struct V_464 * V_441 ;
T_18 V_465 ;
struct V_443 V_444 ;
struct V_445 * V_446 = log -> V_437 ;
V_463 = V_150 -> V_159 [ 0 ] . V_160 ;
ASSERT ( V_150 -> V_159 [ 0 ] . V_214 == sizeof( struct V_462 ) ) ;
V_465 = V_463 -> V_466 ;
F_164 ( & V_446 -> V_438 ) ;
V_441 = F_168 ( V_446 , & V_444 , 0 ) ;
while ( V_441 != NULL ) {
if ( V_441 -> V_453 == V_172 ) {
V_455 = (struct V_454 * ) V_441 ;
if ( V_455 -> V_459 . V_465 == V_465 ) {
F_169 ( & V_446 -> V_438 ) ;
F_176 ( V_455 ) ;
F_164 ( & V_446 -> V_438 ) ;
break;
}
}
V_441 = F_170 ( V_446 , & V_444 ) ;
}
F_171 ( & V_444 ) ;
F_169 ( & V_446 -> V_438 ) ;
return 0 ;
}
static int
F_178 (
struct V_467 * V_51 ,
struct V_468 * V_469 )
{
struct V_468 * V_470 ;
T_5 V_191 ;
V_470 = V_51 -> V_160 ;
V_191 = F_179 ( V_470 -> V_471 ) ;
if ( V_51 -> V_214 == V_191 ) {
memcpy ( V_469 , V_470 , V_191 ) ;
return 0 ;
}
return - V_16 ;
}
STATIC int
F_180 (
struct V_1 * log ,
struct V_178 * V_150 ,
T_6 V_221 )
{
int error ;
struct V_194 * V_25 = log -> V_7 ;
struct V_472 * V_473 ;
struct V_468 * V_474 ;
V_474 = V_150 -> V_159 [ 0 ] . V_160 ;
V_473 = F_181 ( V_25 , V_474 -> V_471 ) ;
error = F_178 ( & V_150 -> V_159 [ 0 ] , & V_473 -> V_475 ) ;
if ( error ) {
F_182 ( V_473 ) ;
return error ;
}
F_163 ( & V_473 -> V_476 , V_474 -> V_471 ) ;
F_164 ( & log -> V_437 -> V_438 ) ;
F_165 ( log -> V_437 , & V_473 -> V_477 , V_221 ) ;
F_183 ( V_473 ) ;
return 0 ;
}
STATIC int
F_184 (
struct V_1 * log ,
struct V_178 * V_150 )
{
struct V_478 * V_479 ;
struct V_472 * V_473 = NULL ;
struct V_464 * V_441 ;
T_18 V_480 ;
struct V_443 V_444 ;
struct V_445 * V_446 = log -> V_437 ;
V_479 = V_150 -> V_159 [ 0 ] . V_160 ;
if ( V_150 -> V_159 [ 0 ] . V_214 != sizeof( struct V_478 ) )
return - V_16 ;
V_480 = V_479 -> V_481 ;
F_164 ( & V_446 -> V_438 ) ;
V_441 = F_168 ( V_446 , & V_444 , 0 ) ;
while ( V_441 != NULL ) {
if ( V_441 -> V_453 == V_174 ) {
V_473 = (struct V_472 * ) V_441 ;
if ( V_473 -> V_475 . V_480 == V_480 ) {
F_169 ( & V_446 -> V_438 ) ;
F_183 ( V_473 ) ;
F_164 ( & V_446 -> V_438 ) ;
break;
}
}
V_441 = F_170 ( V_446 , & V_444 ) ;
}
F_171 ( & V_444 ) ;
F_169 ( & V_446 -> V_438 ) ;
return 0 ;
}
static int
F_185 (
struct V_467 * V_51 ,
struct V_482 * V_483 )
{
struct V_482 * V_484 ;
T_5 V_191 ;
V_484 = V_51 -> V_160 ;
V_191 = F_186 ( V_484 -> V_485 ) ;
if ( V_51 -> V_214 == V_191 ) {
memcpy ( V_483 , V_484 , V_191 ) ;
return 0 ;
}
return - V_16 ;
}
STATIC int
F_187 (
struct V_1 * log ,
struct V_178 * V_150 ,
T_6 V_221 )
{
int error ;
struct V_194 * V_25 = log -> V_7 ;
struct V_486 * V_487 ;
struct V_482 * V_488 ;
V_488 = V_150 -> V_159 [ 0 ] . V_160 ;
if ( V_488 -> V_485 != V_489 )
return - V_16 ;
V_487 = F_188 ( V_25 ) ;
error = F_185 ( & V_150 -> V_159 [ 0 ] , & V_487 -> V_490 ) ;
if ( error ) {
F_189 ( V_487 ) ;
return error ;
}
F_163 ( & V_487 -> V_491 , V_488 -> V_485 ) ;
F_164 ( & log -> V_437 -> V_438 ) ;
F_165 ( log -> V_437 , & V_487 -> V_492 , V_221 ) ;
F_190 ( V_487 ) ;
return 0 ;
}
STATIC int
F_191 (
struct V_1 * log ,
struct V_178 * V_150 )
{
struct V_493 * V_494 ;
struct V_486 * V_487 = NULL ;
struct V_464 * V_441 ;
T_18 V_495 ;
struct V_443 V_444 ;
struct V_445 * V_446 = log -> V_437 ;
V_494 = V_150 -> V_159 [ 0 ] . V_160 ;
if ( V_150 -> V_159 [ 0 ] . V_214 != sizeof( struct V_493 ) )
return - V_16 ;
V_495 = V_494 -> V_496 ;
F_164 ( & V_446 -> V_438 ) ;
V_441 = F_168 ( V_446 , & V_444 , 0 ) ;
while ( V_441 != NULL ) {
if ( V_441 -> V_453 == V_176 ) {
V_487 = (struct V_486 * ) V_441 ;
if ( V_487 -> V_490 . V_495 == V_495 ) {
F_169 ( & V_446 -> V_438 ) ;
F_190 ( V_487 ) ;
F_164 ( & V_446 -> V_438 ) ;
break;
}
}
V_441 = F_170 ( V_446 , & V_444 ) ;
}
F_171 ( & V_444 ) ;
F_169 ( & V_446 -> V_438 ) ;
return 0 ;
}
STATIC int
F_192 (
struct V_1 * log ,
struct V_179 * V_154 ,
T_7 * V_150 )
{
struct V_194 * V_25 = log -> V_7 ;
struct V_497 * V_498 ;
T_19 V_499 ;
T_20 V_500 ;
unsigned int V_76 ;
unsigned int V_376 ;
T_20 V_501 ;
int V_502 ;
int V_503 ;
int V_504 ;
int V_505 ;
int V_48 ;
V_498 = (struct V_497 * ) V_150 -> V_159 [ 0 ] . V_160 ;
if ( V_498 -> V_506 != V_161 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_128 ;
}
if ( V_498 -> V_507 != 1 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_128 ;
}
V_499 = F_28 ( V_498 -> V_508 ) ;
if ( V_499 >= V_25 -> V_27 . V_509 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_128 ;
}
V_500 = F_28 ( V_498 -> V_510 ) ;
if ( ! V_500 || V_500 == V_511 || V_500 >= V_25 -> V_27 . V_512 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_128 ;
}
V_376 = F_28 ( V_498 -> V_513 ) ;
if ( V_376 != V_25 -> V_27 . V_208 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_128 ;
}
V_76 = F_28 ( V_498 -> V_514 ) ;
if ( ! V_76 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_128 ;
}
V_501 = F_28 ( V_498 -> V_515 ) ;
if ( ! V_501 || V_501 >= V_25 -> V_27 . V_512 ) {
F_3 ( log -> V_7 , L_75 ) ;
return - V_128 ;
}
if ( V_501 != V_25 -> V_516 &&
V_501 != V_25 -> V_517 ) {
F_3 ( log -> V_7 ,
L_76 , V_518 ) ;
return - V_128 ;
}
if ( ( V_76 >> V_25 -> V_27 . V_519 ) != V_501 ) {
F_3 ( log -> V_7 ,
L_77 ,
V_518 ) ;
return - V_128 ;
}
V_502 = F_193 ( V_25 ) ;
V_503 = F_157 ( V_25 , V_502 ) ;
V_505 = V_501 / V_502 ;
for ( V_48 = 0 , V_504 = 0 ; V_48 < V_505 ; V_48 ++ ) {
T_2 V_520 ;
V_520 = F_194 ( V_25 , V_499 ,
V_500 + V_48 * V_502 ) ;
if ( F_97 ( log , V_520 , V_503 , 0 ) )
V_504 ++ ;
}
ASSERT ( ! V_504 || V_504 == V_505 ) ;
if ( V_504 ) {
if ( V_504 != V_505 )
F_3 ( V_25 ,
L_78 ) ;
F_195 ( log , V_498 ) ;
return 0 ;
}
F_196 ( log , V_498 ) ;
return F_197 ( V_25 , NULL , V_154 , V_76 , V_499 , V_500 ,
V_501 , F_28 ( V_498 -> V_521 ) ) ;
}
STATIC void
F_198 (
struct V_1 * log ,
struct V_178 * V_150 )
{
struct V_339 * V_158 = V_150 -> V_159 [ 0 ] . V_160 ;
struct V_194 * V_25 = log -> V_7 ;
if ( F_96 ( log , V_158 -> V_183 ,
V_158 -> V_186 , V_158 -> V_164 ) ) {
return;
}
F_199 ( V_25 -> V_347 , V_158 -> V_183 ,
V_158 -> V_186 , NULL ) ;
}
STATIC void
F_200 (
struct V_1 * log ,
struct V_178 * V_150 )
{
struct V_354 V_522 ;
struct V_354 * V_523 ;
struct V_194 * V_25 = log -> V_7 ;
int error ;
if ( V_150 -> V_159 [ 0 ] . V_214 == sizeof( struct V_354 ) ) {
V_523 = V_150 -> V_159 [ 0 ] . V_160 ;
} else {
V_523 = & V_522 ;
memset ( V_523 , 0 , sizeof( * V_523 ) ) ;
error = F_138 ( & V_150 -> V_159 [ 0 ] , V_523 ) ;
if ( error )
return;
}
if ( F_96 ( log , V_523 -> V_378 , V_523 -> V_379 , 0 ) )
return;
F_199 ( V_25 -> V_347 , V_523 -> V_378 ,
V_523 -> V_379 , & V_524 ) ;
}
STATIC void
F_201 (
struct V_1 * log ,
struct V_178 * V_150 )
{
struct V_194 * V_25 = log -> V_7 ;
struct V_416 * V_418 ;
struct V_525 * V_419 ;
T_5 type ;
int V_191 ;
if ( V_25 -> V_340 == 0 )
return;
V_418 = V_150 -> V_159 [ 1 ] . V_160 ;
if ( V_418 == NULL )
return;
if ( V_150 -> V_159 [ 1 ] . V_214 < sizeof( struct V_416 ) )
return;
type = V_418 -> V_420 & ( V_341 | V_342 | V_343 ) ;
ASSERT ( type ) ;
if ( log -> V_344 & type )
return;
V_419 = V_150 -> V_159 [ 0 ] . V_160 ;
ASSERT ( V_419 ) ;
ASSERT ( V_419 -> V_422 == 1 ) ;
V_191 = F_157 ( V_25 , V_419 -> V_422 ) ;
if ( F_96 ( log , V_419 -> V_423 , V_191 , 0 ) )
return;
F_199 ( V_25 -> V_347 , V_419 -> V_423 , V_191 ,
& V_526 ) ;
}
STATIC void
F_202 (
struct V_1 * log ,
struct V_178 * V_150 )
{
switch ( F_80 ( V_150 ) ) {
case V_163 :
F_198 ( log , V_150 ) ;
break;
case V_167 :
F_200 ( log , V_150 ) ;
break;
case V_168 :
F_201 ( log , V_150 ) ;
break;
case V_171 :
case V_170 :
case V_169 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
default:
break;
}
}
STATIC int
F_203 (
struct V_1 * log ,
struct V_147 * V_148 ,
struct V_178 * V_150 )
{
F_204 ( log , V_148 , V_150 , V_527 ) ;
switch ( F_80 ( V_150 ) ) {
case V_163 :
return F_88 ( log , V_150 ) ;
case V_169 :
return F_154 ( log , V_150 ) ;
case V_167 :
case V_171 :
case V_170 :
case V_168 :
case V_161 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
return 0 ;
default:
F_3 ( log -> V_7 , L_79 ,
V_8 , F_80 ( V_150 ) ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
}
STATIC int
F_205 (
struct V_1 * log ,
struct V_147 * V_148 ,
struct V_179 * V_154 ,
struct V_178 * V_150 )
{
F_204 ( log , V_148 , V_150 , V_528 ) ;
switch ( F_80 ( V_150 ) ) {
case V_163 :
return F_122 ( log , V_154 , V_150 ,
V_148 -> V_529 ) ;
case V_167 :
return F_137 ( log , V_154 , V_150 ,
V_148 -> V_529 ) ;
case V_171 :
return F_159 ( log , V_150 , V_148 -> V_529 ) ;
case V_170 :
return F_167 ( log , V_150 ) ;
case V_172 :
return F_172 ( log , V_150 , V_148 -> V_529 ) ;
case V_173 :
return F_177 ( log , V_150 ) ;
case V_174 :
return F_180 ( log , V_150 , V_148 -> V_529 ) ;
case V_175 :
return F_184 ( log , V_150 ) ;
case V_176 :
return F_187 ( log , V_150 , V_148 -> V_529 ) ;
case V_177 :
return F_191 ( log , V_150 ) ;
case V_168 :
return F_155 ( log , V_154 , V_150 ,
V_148 -> V_529 ) ;
case V_161 :
return F_192 ( log , V_154 , V_150 ) ;
case V_169 :
return 0 ;
default:
F_3 ( log -> V_7 , L_79 ,
V_8 , F_80 ( V_150 ) ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
}
STATIC int
F_206 (
struct V_1 * log ,
struct V_147 * V_148 ,
struct V_179 * V_154 ,
struct V_179 * V_530 )
{
struct V_178 * V_150 ;
int error = 0 ;
F_91 (item, item_list, ri_list) {
error = F_205 ( log , V_148 ,
V_154 , V_150 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_207 (
struct V_1 * log ,
struct V_147 * V_148 ,
int V_149 ,
struct V_179 * V_154 )
{
int error = 0 ;
int V_531 = 0 ;
struct V_178 * V_150 ;
struct V_178 * V_335 ;
F_77 ( V_532 ) ;
F_77 ( V_533 ) ;
#define F_208 100
F_209 ( & V_148 -> V_534 ) ;
error = F_76 ( log , V_148 , V_149 ) ;
if ( error )
return error ;
F_79 (item, next, &trans->r_itemq, ri_list) {
switch ( V_149 ) {
case V_527 :
error = F_203 ( log , V_148 , V_150 ) ;
break;
case V_528 :
F_202 ( log , V_150 ) ;
F_81 ( & V_150 -> V_162 , & V_532 ) ;
V_531 ++ ;
if ( V_531 >= F_208 ) {
error = F_206 ( log , V_148 ,
V_154 , & V_532 ) ;
F_210 ( & V_532 , & V_533 ) ;
V_531 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_54;
}
V_54:
if ( ! F_85 ( & V_532 ) ) {
if ( ! error )
error = F_206 ( log , V_148 ,
V_154 , & V_532 ) ;
F_210 ( & V_532 , & V_533 ) ;
}
if ( ! F_85 ( & V_533 ) )
F_78 ( & V_533 , & V_148 -> V_157 ) ;
return error ;
}
STATIC void
F_211 (
struct V_179 * V_26 )
{
T_7 * V_150 ;
V_150 = F_212 ( sizeof( T_7 ) , V_188 ) ;
F_213 ( & V_150 -> V_162 ) ;
F_94 ( & V_150 -> V_162 , V_26 ) ;
}
STATIC int
F_214 (
struct V_1 * log ,
struct V_147 * V_148 ,
char * V_535 ,
int V_191 )
{
T_7 * V_150 ;
char * V_536 , * V_537 ;
int V_538 ;
if ( F_85 ( & V_148 -> V_157 ) ) {
ASSERT ( V_191 <= sizeof( struct V_539 ) ) ;
if ( V_191 > sizeof( struct V_539 ) ) {
F_3 ( log -> V_7 , L_80 , V_8 ) ;
return - V_61 ;
}
F_211 ( & V_148 -> V_157 ) ;
V_536 = ( char * ) & V_148 -> V_540 +
sizeof( struct V_539 ) - V_191 ;
memcpy ( V_536 , V_535 , V_191 ) ;
return 0 ;
}
V_150 = F_215 ( V_148 -> V_157 . V_541 , T_7 , V_162 ) ;
V_537 = V_150 -> V_159 [ V_150 -> V_542 - 1 ] . V_160 ;
V_538 = V_150 -> V_159 [ V_150 -> V_542 - 1 ] . V_214 ;
V_536 = F_216 ( V_537 , V_191 + V_538 , V_188 ) ;
memcpy ( & V_536 [ V_538 ] , V_535 , V_191 ) ;
V_150 -> V_159 [ V_150 -> V_542 - 1 ] . V_214 += V_191 ;
V_150 -> V_159 [ V_150 -> V_542 - 1 ] . V_160 = V_536 ;
F_217 ( log , V_148 , V_150 , 0 ) ;
return 0 ;
}
STATIC int
F_218 (
struct V_1 * log ,
struct V_147 * V_148 ,
char * V_535 ,
int V_191 )
{
T_12 * V_355 ;
T_7 * V_150 ;
char * V_536 ;
if ( ! V_191 )
return 0 ;
if ( F_85 ( & V_148 -> V_157 ) ) {
if ( * ( T_5 * ) V_535 != V_543 ) {
F_3 ( log -> V_7 , L_81 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
if ( V_191 > sizeof( struct V_539 ) ) {
F_3 ( log -> V_7 , L_80 , V_8 ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
if ( V_191 == sizeof( struct V_539 ) )
F_211 ( & V_148 -> V_157 ) ;
memcpy ( & V_148 -> V_540 , V_535 , V_191 ) ;
return 0 ;
}
V_536 = F_93 ( V_191 , V_188 ) ;
memcpy ( V_536 , V_535 , V_191 ) ;
V_355 = ( T_12 * ) V_536 ;
V_150 = F_215 ( V_148 -> V_157 . V_541 , T_7 , V_162 ) ;
if ( V_150 -> V_338 != 0 &&
V_150 -> V_338 == V_150 -> V_542 ) {
F_211 ( & V_148 -> V_157 ) ;
V_150 = F_215 ( V_148 -> V_157 . V_541 ,
T_7 , V_162 ) ;
}
if ( V_150 -> V_338 == 0 ) {
if ( V_355 -> V_401 == 0 ||
V_355 -> V_401 > V_544 ) {
F_3 ( log -> V_7 ,
L_82 ,
V_355 -> V_401 ) ;
ASSERT ( 0 ) ;
F_99 ( V_536 ) ;
return - V_61 ;
}
V_150 -> V_338 = V_355 -> V_401 ;
V_150 -> V_159 =
F_212 ( V_150 -> V_338 * sizeof( V_545 ) ,
V_188 ) ;
}
ASSERT ( V_150 -> V_338 > V_150 -> V_542 ) ;
V_150 -> V_159 [ V_150 -> V_542 ] . V_160 = V_536 ;
V_150 -> V_159 [ V_150 -> V_542 ] . V_214 = V_191 ;
V_150 -> V_542 ++ ;
F_219 ( log , V_148 , V_150 , 0 ) ;
return 0 ;
}
STATIC void
F_220 (
struct V_147 * V_148 )
{
T_7 * V_150 , * V_151 ;
int V_48 ;
F_209 ( & V_148 -> V_534 ) ;
F_79 (item, n, &trans->r_itemq, ri_list) {
F_98 ( & V_150 -> V_162 ) ;
for ( V_48 = 0 ; V_48 < V_150 -> V_542 ; V_48 ++ )
F_99 ( V_150 -> V_159 [ V_48 ] . V_160 ) ;
F_99 ( V_150 -> V_159 ) ;
F_99 ( V_150 ) ;
}
F_99 ( V_148 ) ;
}
STATIC int
F_221 (
struct V_1 * log ,
struct V_147 * V_148 ,
char * V_535 ,
unsigned int V_191 ,
unsigned int V_192 ,
int V_149 ,
struct V_179 * V_154 )
{
int error = 0 ;
bool V_546 = false ;
V_192 &= ~ V_547 ;
if ( V_192 & V_548 )
V_192 &= ~ V_549 ;
switch ( V_192 ) {
case 0 :
case V_549 :
error = F_218 ( log , V_148 , V_535 , V_191 ) ;
break;
case V_548 :
error = F_214 ( log , V_148 , V_535 , V_191 ) ;
break;
case V_550 :
error = F_207 ( log , V_148 , V_149 ,
V_154 ) ;
V_546 = true ;
break;
case V_109 :
F_3 ( log -> V_7 , L_83 , V_8 ) ;
V_546 = true ;
break;
case V_551 :
default:
F_3 ( log -> V_7 , L_84 , V_8 , V_192 ) ;
ASSERT ( 0 ) ;
error = - V_61 ;
break;
}
if ( error || V_546 )
F_220 ( V_148 ) ;
return error ;
}
STATIC struct V_147 *
F_222 (
struct V_552 V_553 [] ,
struct V_78 * V_79 ,
struct V_100 * V_554 )
{
struct V_147 * V_148 ;
T_21 V_555 ;
struct V_552 * V_556 ;
V_555 = F_28 ( V_554 -> V_557 ) ;
V_556 = & V_553 [ F_223 ( V_555 ) ] ;
F_224 (trans, rhp, r_list) {
if ( V_148 -> V_558 == V_555 )
return V_148 ;
}
if ( ! ( V_554 -> V_108 & V_551 ) )
return NULL ;
ASSERT ( F_28 ( V_554 -> V_559 ) == 0 ) ;
V_148 = F_212 ( sizeof( struct V_147 ) , V_188 ) ;
V_148 -> V_558 = V_555 ;
V_148 -> V_529 = F_59 ( V_79 -> V_117 ) ;
F_213 ( & V_148 -> V_157 ) ;
F_225 ( & V_148 -> V_534 ) ;
F_226 ( & V_148 -> V_534 , V_556 ) ;
return NULL ;
}
STATIC int
F_227 (
struct V_1 * log ,
struct V_552 V_553 [] ,
struct V_78 * V_79 ,
struct V_100 * V_554 ,
char * V_535 ,
char * V_560 ,
int V_149 ,
struct V_179 * V_154 )
{
struct V_147 * V_148 ;
unsigned int V_191 ;
int error ;
if ( V_554 -> V_561 != V_562 &&
V_554 -> V_561 != V_563 ) {
F_3 ( log -> V_7 , L_85 ,
V_8 , V_554 -> V_561 ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
V_191 = F_28 ( V_554 -> V_559 ) ;
if ( V_535 + V_191 > V_560 ) {
F_3 ( log -> V_7 , L_86 , V_8 , V_191 ) ;
F_228 ( 1 ) ;
return - V_61 ;
}
V_148 = F_222 ( V_553 , V_79 , V_554 ) ;
if ( ! V_148 ) {
return 0 ;
}
if ( log -> V_564 != V_148 -> V_529 &&
V_554 -> V_108 & V_550 ) {
error = F_229 ( V_154 ) ;
if ( error )
return error ;
log -> V_564 = V_148 -> V_529 ;
}
return F_221 ( log , V_148 , V_535 , V_191 ,
V_554 -> V_108 , V_149 , V_154 ) ;
}
STATIC int
F_230 (
struct V_1 * log ,
struct V_552 V_553 [] ,
struct V_78 * V_79 ,
char * V_535 ,
int V_149 ,
struct V_179 * V_154 )
{
struct V_100 * V_554 ;
char * V_560 ;
int V_565 ;
int error ;
V_560 = V_535 + F_28 ( V_79 -> V_64 ) ;
V_565 = F_28 ( V_79 -> V_107 ) ;
if ( F_29 ( log -> V_7 , V_79 ) )
return - V_61 ;
F_231 ( log , V_79 , V_149 ) ;
while ( ( V_535 < V_560 ) && V_565 ) {
V_554 = (struct V_100 * ) V_535 ;
V_535 += sizeof( * V_554 ) ;
ASSERT ( V_535 <= V_560 ) ;
error = F_227 ( log , V_553 , V_79 , V_554 ,
V_535 , V_560 , V_149 , V_154 ) ;
if ( error )
return error ;
V_535 += F_28 ( V_554 -> V_559 ) ;
V_565 -- ;
}
return 0 ;
}
STATIC int
F_232 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_430 * V_431 ;
int error ;
V_431 = F_233 ( V_441 , struct V_430 , V_439 ) ;
if ( F_234 ( V_566 , & V_431 -> V_567 ) )
return 0 ;
F_169 ( & V_446 -> V_438 ) ;
error = F_235 ( V_25 , V_431 ) ;
F_164 ( & V_446 -> V_438 ) ;
return error ;
}
STATIC void
F_236 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_430 * V_431 ;
V_431 = F_233 ( V_441 , struct V_430 , V_439 ) ;
F_169 ( & V_446 -> V_438 ) ;
F_166 ( V_431 ) ;
F_164 ( & V_446 -> V_438 ) ;
}
STATIC int
F_237 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_454 * V_455 ;
int error ;
V_455 = F_233 ( V_441 , struct V_454 , V_461 ) ;
if ( F_234 ( V_568 , & V_455 -> V_569 ) )
return 0 ;
F_169 ( & V_446 -> V_438 ) ;
error = F_238 ( V_25 , V_455 ) ;
F_164 ( & V_446 -> V_438 ) ;
return error ;
}
STATIC void
F_239 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_454 * V_455 ;
V_455 = F_233 ( V_441 , struct V_454 , V_461 ) ;
F_169 ( & V_446 -> V_438 ) ;
F_176 ( V_455 ) ;
F_164 ( & V_446 -> V_438 ) ;
}
STATIC int
F_240 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_472 * V_473 ;
int error ;
V_473 = F_233 ( V_441 , struct V_472 , V_477 ) ;
if ( F_234 ( V_570 , & V_473 -> V_571 ) )
return 0 ;
F_169 ( & V_446 -> V_438 ) ;
error = F_241 ( V_25 , V_473 ) ;
F_164 ( & V_446 -> V_438 ) ;
return error ;
}
STATIC void
F_242 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_472 * V_473 ;
V_473 = F_233 ( V_441 , struct V_472 , V_477 ) ;
F_169 ( & V_446 -> V_438 ) ;
F_183 ( V_473 ) ;
F_164 ( & V_446 -> V_438 ) ;
}
STATIC int
F_243 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_486 * V_487 ;
int error ;
V_487 = F_233 ( V_441 , struct V_486 , V_492 ) ;
if ( F_234 ( V_572 , & V_487 -> V_573 ) )
return 0 ;
F_169 ( & V_446 -> V_438 ) ;
error = F_244 ( V_25 , V_487 ) ;
F_164 ( & V_446 -> V_438 ) ;
return error ;
}
STATIC void
F_245 (
struct V_194 * V_25 ,
struct V_445 * V_446 ,
struct V_464 * V_441 )
{
struct V_486 * V_487 ;
V_487 = F_233 ( V_441 , struct V_486 , V_492 ) ;
F_169 ( & V_446 -> V_438 ) ;
F_190 ( V_487 ) ;
F_164 ( & V_446 -> V_438 ) ;
}
static inline bool F_246 ( struct V_464 * V_441 )
{
switch ( V_441 -> V_453 ) {
case V_171 :
case V_172 :
case V_174 :
case V_176 :
return true ;
default:
return false ;
}
}
STATIC int
F_247 (
struct V_1 * log )
{
struct V_464 * V_441 ;
int error = 0 ;
struct V_443 V_444 ;
struct V_445 * V_446 ;
#if F_248 ( V_574 ) || F_248 ( V_575 )
T_6 V_576 ;
#endif
V_446 = log -> V_437 ;
F_164 ( & V_446 -> V_438 ) ;
V_441 = F_168 ( V_446 , & V_444 , 0 ) ;
#if F_248 ( V_574 ) || F_248 ( V_575 )
V_576 = F_72 ( log -> V_111 , log -> V_115 ) ;
#endif
while ( V_441 != NULL ) {
if ( ! F_246 ( V_441 ) ) {
#ifdef V_574
for (; V_441 ; V_441 = F_170 ( V_446 , & V_444 ) )
ASSERT ( ! F_246 ( V_441 ) ) ;
#endif
break;
}
ASSERT ( F_126 ( V_576 , V_441 -> V_331 ) >= 0 ) ;
switch ( V_441 -> V_453 ) {
case V_171 :
error = F_232 ( log -> V_7 , V_446 , V_441 ) ;
break;
case V_172 :
error = F_237 ( log -> V_7 , V_446 , V_441 ) ;
break;
case V_174 :
error = F_240 ( log -> V_7 , V_446 , V_441 ) ;
break;
case V_176 :
error = F_243 ( log -> V_7 , V_446 , V_441 ) ;
break;
}
if ( error )
goto V_54;
V_441 = F_170 ( V_446 , & V_444 ) ;
}
V_54:
F_171 ( & V_444 ) ;
F_169 ( & V_446 -> V_438 ) ;
return error ;
}
STATIC int
F_249 (
struct V_1 * log )
{
struct V_464 * V_441 ;
int error = 0 ;
struct V_443 V_444 ;
struct V_445 * V_446 ;
V_446 = log -> V_437 ;
F_164 ( & V_446 -> V_438 ) ;
V_441 = F_168 ( V_446 , & V_444 , 0 ) ;
while ( V_441 != NULL ) {
if ( ! F_246 ( V_441 ) ) {
#ifdef V_574
for (; V_441 ; V_441 = F_170 ( V_446 , & V_444 ) )
ASSERT ( ! F_246 ( V_441 ) ) ;
#endif
break;
}
switch ( V_441 -> V_453 ) {
case V_171 :
F_236 ( log -> V_7 , V_446 , V_441 ) ;
break;
case V_172 :
F_239 ( log -> V_7 , V_446 , V_441 ) ;
break;
case V_174 :
F_242 ( log -> V_7 , V_446 , V_441 ) ;
break;
case V_176 :
F_245 ( log -> V_7 , V_446 , V_441 ) ;
break;
}
V_441 = F_170 ( V_446 , & V_444 ) ;
}
F_171 ( & V_444 ) ;
F_169 ( & V_446 -> V_438 ) ;
return error ;
}
STATIC void
F_250 (
T_3 * V_25 ,
T_19 V_499 ,
int V_180 )
{
T_22 * V_577 ;
T_23 * V_578 ;
T_1 * V_579 ;
int V_13 ;
int error ;
error = F_251 ( V_25 , & F_252 ( V_25 ) -> V_580 , 0 , 0 , 0 , & V_577 ) ;
if ( error )
goto V_82;
error = F_253 ( V_25 , V_577 , V_499 , & V_579 ) ;
if ( error )
goto V_581;
V_578 = F_254 ( V_579 ) ;
V_578 -> V_582 [ V_180 ] = F_30 ( V_583 ) ;
V_13 = F_103 ( T_23 , V_582 ) +
( sizeof( T_9 ) * V_180 ) ;
F_255 ( V_577 , V_579 , V_13 ,
( V_13 + sizeof( T_9 ) - 1 ) ) ;
error = F_256 ( V_577 ) ;
if ( error )
goto V_82;
return;
V_581:
F_257 ( V_577 ) ;
V_82:
F_3 ( V_25 , L_87 , V_8 , V_499 ) ;
return;
}
STATIC T_9
F_258 (
struct V_194 * V_25 ,
T_19 V_499 ,
T_9 V_584 ,
int V_180 )
{
struct V_5 * V_585 ;
struct V_352 * V_353 ;
struct V_356 * V_357 ;
T_24 V_586 ;
int error ;
V_586 = F_259 ( V_25 , V_499 , V_584 ) ;
error = F_260 ( V_25 , NULL , V_586 , 0 , 0 , & V_357 ) ;
if ( error )
goto V_587;
error = F_261 ( V_25 , NULL , & V_357 -> V_588 , & V_353 , & V_585 , 0 , 0 ) ;
if ( error )
goto V_589;
F_262 ( V_357 , V_590 ) ;
ASSERT ( F_263 ( V_357 ) -> V_591 == 0 ) ;
ASSERT ( F_263 ( V_357 ) -> V_592 != 0 ) ;
V_584 = F_28 ( V_353 -> V_210 ) ;
F_25 ( V_585 ) ;
V_357 -> V_362 . V_593 = 0 ;
F_264 ( V_357 ) ;
return V_584 ;
V_589:
F_264 ( V_357 ) ;
V_587:
F_250 ( V_25 , V_499 , V_180 ) ;
return V_583 ;
}
STATIC void
F_265 (
struct V_1 * log )
{
T_3 * V_25 ;
T_19 V_499 ;
T_23 * V_578 ;
T_1 * V_579 ;
T_9 V_584 ;
int V_180 ;
int error ;
T_5 V_594 ;
V_25 = log -> V_7 ;
V_594 = V_25 -> V_595 ;
V_25 -> V_595 = 0 ;
for ( V_499 = 0 ; V_499 < V_25 -> V_27 . V_509 ; V_499 ++ ) {
error = F_253 ( V_25 , NULL , V_499 , & V_579 ) ;
if ( error ) {
continue;
}
V_578 = F_254 ( V_579 ) ;
F_7 ( V_579 ) ;
for ( V_180 = 0 ; V_180 < V_596 ; V_180 ++ ) {
V_584 = F_28 ( V_578 -> V_582 [ V_180 ] ) ;
while ( V_584 != V_583 ) {
V_584 = F_258 ( V_25 ,
V_499 , V_584 , V_180 ) ;
}
}
F_266 ( V_579 ) ;
}
V_25 -> V_595 = V_594 ;
}
STATIC int
F_267 (
struct V_78 * V_79 ,
char * V_535 ,
struct V_1 * log )
{
int V_48 , V_49 , V_597 ;
for ( V_48 = 0 ; V_48 < F_47 ( F_28 ( V_79 -> V_64 ) ) &&
V_48 < ( V_63 / V_55 ) ; V_48 ++ ) {
* ( V_83 * ) V_535 = * ( V_83 * ) & V_79 -> V_598 [ V_48 ] ;
V_535 += V_55 ;
}
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
T_25 * V_599 = ( T_25 * ) V_79 ;
for ( ; V_48 < F_47 ( F_28 ( V_79 -> V_64 ) ) ; V_48 ++ ) {
V_49 = V_48 / ( V_63 / V_55 ) ;
V_597 = V_48 % ( V_63 / V_55 ) ;
* ( V_83 * ) V_535 = V_599 [ V_49 ] . V_600 . V_601 [ V_597 ] ;
V_535 += V_55 ;
}
}
return 0 ;
}
STATIC int
F_268 (
struct V_1 * log ,
struct V_552 V_553 [] ,
struct V_78 * V_79 ,
char * V_535 ,
int V_149 ,
struct V_179 * V_154 )
{
int error ;
T_26 V_602 = V_79 -> V_603 ;
T_26 V_604 ;
V_604 = F_269 ( log , V_79 , V_535 , F_28 ( V_79 -> V_64 ) ) ;
if ( V_149 == V_89 ) {
if ( V_602 && V_604 != V_602 )
return - V_90 ;
return 0 ;
}
if ( V_604 != V_602 ) {
if ( V_602 || F_102 ( & log -> V_7 -> V_27 ) ) {
F_106 ( log -> V_7 ,
L_88 ,
F_270 ( V_602 ) ,
F_270 ( V_604 ) ) ;
F_271 ( V_535 , 32 ) ;
}
if ( F_102 ( & log -> V_7 -> V_27 ) )
return - V_16 ;
}
error = F_267 ( V_79 , V_535 , log ) ;
if ( error )
return error ;
return F_230 ( log , V_553 , V_79 , V_535 , V_149 ,
V_154 ) ;
}
STATIC int
F_272 (
struct V_1 * log ,
struct V_78 * V_79 ,
T_2 V_190 )
{
int V_605 ;
if ( F_31 ( V_79 -> V_32 != F_30 ( V_33 ) ) ) {
F_4 ( L_89 ,
V_146 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 (
( ! V_79 -> V_105 ||
( F_28 ( V_79 -> V_105 ) & ( ~ V_606 ) ) ) ) ) {
F_3 ( log -> V_7 , L_90 ,
V_8 , F_28 ( V_79 -> V_105 ) ) ;
return - V_61 ;
}
V_605 = F_28 ( V_79 -> V_64 ) ;
if ( F_31 ( V_605 <= 0 || V_605 > V_73 ) ) {
F_4 ( L_91 ,
V_146 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 ( V_190 > log -> V_3 || V_190 > V_73 ) ) {
F_4 ( L_92 ,
V_146 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_56 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 ,
int V_149 ,
T_2 * V_86 )
{
T_4 * V_79 ;
T_2 V_12 , V_607 ;
T_2 V_93 ;
char * V_13 ;
T_1 * V_608 , * V_609 ;
int error = 0 , V_62 , V_64 ;
int V_24 = 0 ;
int V_610 , V_611 ;
int V_104 , V_612 , V_613 ;
int V_48 ;
struct V_552 V_553 [ V_614 ] ;
F_77 ( V_154 ) ;
ASSERT ( V_66 != V_75 ) ;
V_12 = V_93 = V_75 ;
for ( V_48 = 0 ; V_48 < V_614 ; V_48 ++ )
F_273 ( & V_553 [ V_48 ] ) ;
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
V_608 = F_2 ( log , 1 ) ;
if ( ! V_608 )
return - V_52 ;
error = F_18 ( log , V_75 , 1 , V_608 , & V_13 ) ;
if ( error )
goto V_615;
V_79 = ( T_4 * ) V_13 ;
error = F_272 ( log , V_79 , V_75 ) ;
if ( error )
goto V_615;
V_62 = F_28 ( V_79 -> V_62 ) ;
V_64 = F_28 ( V_79 -> V_64 ) ;
if ( V_64 > V_62 ) {
if ( V_64 <= log -> V_7 -> V_616 &&
F_28 ( V_79 -> V_107 ) == 1 ) {
F_3 ( log -> V_7 ,
L_93 ,
V_62 , log -> V_7 -> V_616 ) ;
V_62 = log -> V_7 -> V_616 ;
} else
return - V_16 ;
}
if ( ( F_28 ( V_79 -> V_105 ) & V_106 ) &&
( V_62 > V_63 ) ) {
V_104 = V_62 / V_63 ;
if ( V_62 % V_63 )
V_104 ++ ;
F_8 ( V_608 ) ;
V_608 = F_2 ( log , V_104 ) ;
} else {
V_104 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_104 = 1 ;
V_608 = F_2 ( log , 1 ) ;
V_62 = V_617 ;
}
if ( ! V_608 )
return - V_52 ;
V_609 = F_2 ( log , F_47 ( V_62 ) ) ;
if ( ! V_609 ) {
F_8 ( V_608 ) ;
return - V_52 ;
}
memset ( V_553 , 0 , sizeof( V_553 ) ) ;
if ( V_75 > V_66 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_608 -> V_15 ;
V_612 = 0 ;
V_613 = 0 ;
if ( V_12 + V_104 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_104 , V_608 ,
& V_13 ) ;
if ( error )
goto V_618;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_73 ) ;
V_612 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_612 > 0 ) ;
error = F_18 ( log , V_12 ,
V_612 , V_608 ,
& V_13 ) ;
if ( error )
goto V_618;
}
V_613 = V_104 - V_612 ;
error = F_19 ( log , 0 ,
V_613 , V_608 ,
V_13 + F_11 ( V_612 ) ) ;
if ( error )
goto V_618;
}
V_79 = ( T_4 * ) V_13 ;
error = F_272 ( log , V_79 ,
V_612 ? V_12 : 0 ) ;
if ( error )
goto V_618;
V_610 = ( int ) F_47 ( F_28 ( V_79 -> V_64 ) ) ;
V_12 += V_104 ;
if ( V_12 + V_610 <= log -> V_3 ||
V_12 >= log -> V_3 ) {
V_607 = F_61 ( V_12 , log -> V_3 ) ;
error = F_18 ( log , V_607 , V_610 , V_609 ,
& V_13 ) ;
if ( error )
goto V_618;
} else {
V_13 = V_609 -> V_15 ;
V_611 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_613 ) ;
ASSERT ( V_12 <= V_73 ) ;
V_611 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_611 > 0 ) ;
error = F_18 ( log , V_12 ,
V_611 , V_609 ,
& V_13 ) ;
if ( error )
goto V_618;
}
error = F_19 ( log , 0 ,
V_610 - V_611 , V_609 ,
V_13 + F_11 ( V_611 ) ) ;
if ( error )
goto V_618;
}
error = F_268 ( log , V_553 , V_79 , V_13 ,
V_149 , & V_154 ) ;
if ( error )
goto V_618;
V_12 += V_610 ;
V_93 = V_12 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
V_93 = V_12 ;
}
while ( V_12 < V_66 ) {
error = F_18 ( log , V_12 , V_104 , V_608 , & V_13 ) ;
if ( error )
goto V_618;
V_79 = ( T_4 * ) V_13 ;
error = F_272 ( log , V_79 , V_12 ) ;
if ( error )
goto V_618;
V_610 = ( int ) F_47 ( F_28 ( V_79 -> V_64 ) ) ;
error = F_18 ( log , V_12 + V_104 , V_610 , V_609 ,
& V_13 ) ;
if ( error )
goto V_618;
error = F_268 ( log , V_553 , V_79 , V_13 , V_149 ,
& V_154 ) ;
if ( error )
goto V_618;
V_12 += V_610 + V_104 ;
V_93 = V_12 ;
}
V_618:
F_8 ( V_609 ) ;
V_615:
F_8 ( V_608 ) ;
if ( ! F_85 ( & V_154 ) )
V_24 = F_229 ( & V_154 ) ;
if ( error && V_86 )
* V_86 = V_93 ;
for ( V_48 = 0 ; V_48 < V_614 ; V_48 ++ ) {
struct V_619 * V_620 ;
struct V_147 * V_148 ;
F_274 (trans, tmp, &rhash[i], r_list)
F_220 ( V_148 ) ;
}
return error ? error : V_24 ;
}
STATIC int
F_275 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 )
{
int error , V_48 ;
ASSERT ( V_66 != V_75 ) ;
log -> V_193 = F_212 ( V_621 *
sizeof( struct V_179 ) ,
V_188 ) ;
for ( V_48 = 0 ; V_48 < V_621 ; V_48 ++ )
F_213 ( & log -> V_193 [ V_48 ] ) ;
error = F_56 ( log , V_66 , V_75 ,
V_527 , NULL ) ;
if ( error != 0 ) {
F_99 ( log -> V_193 ) ;
log -> V_193 = NULL ;
return error ;
}
error = F_56 ( log , V_66 , V_75 ,
V_528 , NULL ) ;
#ifdef V_574
if ( ! error ) {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_621 ; V_48 ++ )
ASSERT ( F_85 ( & log -> V_193 [ V_48 ] ) ) ;
}
#endif
F_99 ( log -> V_193 ) ;
log -> V_193 = NULL ;
return error ;
}
STATIC int
F_276 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 )
{
struct V_194 * V_25 = log -> V_7 ;
int error ;
T_1 * V_6 ;
T_27 * V_622 ;
F_277 ( log , V_66 , V_75 ) ;
error = F_275 ( log , V_66 , V_75 ) ;
if ( error )
return error ;
if ( F_16 ( V_25 ) ) {
return - V_61 ;
}
F_278 ( V_25 ) ;
V_6 = F_279 ( V_25 , 0 ) ;
V_6 -> V_18 &= ~ ( V_623 | V_624 ) ;
ASSERT ( ! ( V_6 -> V_18 & V_625 ) ) ;
V_6 -> V_18 |= V_19 ;
V_6 -> V_205 = & V_323 ;
error = F_15 ( V_6 ) ;
if ( error ) {
if ( ! F_16 ( V_25 ) ) {
F_17 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_25 ( V_6 ) ;
return error ;
}
V_622 = & V_25 -> V_27 ;
F_280 ( V_622 , F_281 ( V_6 ) ) ;
F_25 ( V_6 ) ;
F_282 ( V_25 ) ;
error = F_283 ( V_25 , V_622 -> V_509 , & V_25 -> V_626 ) ;
if ( error ) {
F_3 ( V_25 , L_94 , error ) ;
return error ;
}
V_25 -> V_627 = F_284 ( V_25 ) ;
F_285 ( log ) ;
log -> V_628 &= ~ V_629 ;
return 0 ;
}
int
V_147 (
struct V_1 * log )
{
T_2 V_66 , V_75 ;
int error ;
error = F_66 ( log , & V_66 , & V_75 ) ;
if ( error )
return error ;
if ( F_102 ( & log -> V_7 -> V_27 ) &&
! F_286 ( log -> V_7 , log -> V_7 -> V_27 . V_263 ) )
return - V_128 ;
if ( V_75 != V_66 ) {
if ( ( error = F_287 ( log -> V_7 , L_95 ) ) ) {
return error ;
}
if ( F_288 ( & log -> V_7 -> V_27 ) == V_630 &&
F_289 ( & log -> V_7 -> V_27 ,
V_631 ) ) {
F_3 ( log -> V_7 ,
L_96 ,
( log -> V_7 -> V_27 . V_632 &
V_631 ) ) ;
F_3 ( log -> V_7 ,
L_97 ) ;
F_3 ( log -> V_7 ,
L_98 ) ;
return - V_128 ;
}
if ( V_633 . V_634 ) {
F_290 ( log -> V_7 ,
L_99 ,
V_633 . V_634 ) ;
F_291 ( V_633 . V_634 * 1000 ) ;
}
F_290 ( log -> V_7 , L_100 ,
log -> V_7 -> V_635 ? log -> V_7 -> V_635
: L_101 ) ;
error = F_276 ( log , V_66 , V_75 ) ;
log -> V_628 |= V_636 ;
}
return error ;
}
int
F_292 (
struct V_1 * log )
{
if ( log -> V_628 & V_636 ) {
int error ;
error = F_247 ( log ) ;
if ( error ) {
F_106 ( log -> V_7 , L_102 ) ;
return error ;
}
F_293 ( log -> V_7 , V_637 ) ;
F_265 ( log ) ;
F_285 ( log ) ;
F_290 ( log -> V_7 , L_103 ,
log -> V_7 -> V_635 ? log -> V_7 -> V_635
: L_101 ) ;
log -> V_628 &= ~ V_636 ;
} else {
F_294 ( log -> V_7 , L_104 ) ;
}
return 0 ;
}
int
F_295 (
struct V_1 * log )
{
int error = 0 ;
if ( log -> V_628 & V_636 )
error = F_249 ( log ) ;
return error ;
}
void
F_285 (
struct V_1 * log )
{
T_3 * V_25 ;
T_28 * V_638 ;
T_1 * V_639 ;
T_1 * V_579 ;
T_19 V_499 ;
T_18 V_640 ;
T_18 V_641 ;
T_18 V_642 ;
int error ;
V_25 = log -> V_7 ;
V_640 = 0LL ;
V_641 = 0LL ;
V_642 = 0LL ;
for ( V_499 = 0 ; V_499 < V_25 -> V_27 . V_509 ; V_499 ++ ) {
error = F_296 ( V_25 , NULL , V_499 , 0 , & V_639 ) ;
if ( error ) {
F_106 ( V_25 , L_105 ,
V_8 , V_499 , error ) ;
} else {
V_638 = F_297 ( V_639 ) ;
V_640 += F_28 ( V_638 -> V_643 ) +
F_28 ( V_638 -> V_644 ) ;
F_25 ( V_639 ) ;
}
error = F_253 ( V_25 , NULL , V_499 , & V_579 ) ;
if ( error ) {
F_106 ( V_25 , L_106 ,
V_8 , V_499 , error ) ;
} else {
struct V_249 * V_578 = F_254 ( V_579 ) ;
V_641 += F_28 ( V_578 -> V_645 ) ;
V_642 += F_28 ( V_578 -> V_646 ) ;
F_25 ( V_579 ) ;
}
}
}
