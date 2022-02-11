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
STATIC int
F_54 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 )
{
struct V_78 * V_84 ;
struct V_5 * V_6 ;
T_2 V_85 ;
int V_76 ;
int error = 0 ;
bool V_80 ;
T_2 V_86 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_52 ;
V_76 = F_53 ( log , V_66 , V_75 ,
V_87 + 1 , V_6 , & V_86 , & V_84 ,
& V_80 ) ;
if ( V_76 < 0 ) {
error = V_76 ;
goto V_54;
}
if ( V_76 < V_87 + 1 )
V_86 = V_66 ;
error = F_55 ( log , V_86 , V_75 ,
V_88 , & V_85 ) ;
V_54:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_56 (
struct V_1 * log ,
T_2 * V_66 ,
T_2 * V_75 ,
struct V_5 * V_6 ,
T_2 * V_89 ,
struct V_78 * * V_79 ,
bool * V_80 )
{
struct V_78 * V_90 ;
struct V_5 * V_91 ;
T_2 V_85 ;
T_2 V_92 ;
int V_81 ;
int error ;
bool V_93 ;
V_91 = F_2 ( log , 1 ) ;
if ( ! V_91 )
return - V_52 ;
error = F_52 ( log , * V_66 , * V_75 ,
V_87 , V_91 , & V_92 ,
& V_90 , & V_93 ) ;
F_8 ( V_91 ) ;
if ( error < 0 )
return error ;
error = F_55 ( log , * V_66 , V_92 ,
V_88 , & V_85 ) ;
if ( error == - V_94 ) {
error = 0 ;
F_3 ( log -> V_7 ,
L_15 ,
V_85 , * V_66 ) ;
V_81 = F_52 ( log , V_85 , * V_75 , 1 , V_6 ,
V_89 , V_79 , V_80 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_81 == 0 )
return - V_61 ;
* V_66 = V_85 ;
* V_75 = F_57 ( F_58 ( ( * V_79 ) -> V_95 ) ) ;
if ( * V_66 == * V_75 ) {
ASSERT ( 0 ) ;
return 0 ;
}
error = F_54 ( log , * V_66 , * V_75 ) ;
}
return error ;
}
static int
F_59 (
struct V_1 * log ,
T_2 * V_66 ,
T_2 * V_75 ,
struct V_78 * V_79 ,
T_2 V_89 ,
struct V_5 * V_6 ,
bool * V_96 )
{
struct V_97 * V_98 ;
T_2 V_99 ;
T_2 V_100 ;
int V_101 ;
int error ;
char * V_13 ;
* V_96 = false ;
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
int V_62 = F_28 ( V_79 -> V_62 ) ;
int V_102 = F_28 ( V_79 -> V_102 ) ;
if ( ( V_102 & V_103 ) &&
( V_62 > V_63 ) ) {
V_101 = V_62 / V_63 ;
if ( V_62 % V_63 )
V_101 ++ ;
} else {
V_101 = 1 ;
}
} else {
V_101 = 1 ;
}
V_100 = V_89 + V_101 + F_47 ( F_28 ( V_79 -> V_64 ) ) ;
V_100 = F_60 ( V_100 , log -> V_3 ) ;
if ( * V_66 == V_100 &&
F_28 ( V_79 -> V_104 ) == 1 ) {
V_99 = V_89 + V_101 ;
V_99 = F_60 ( V_99 , log -> V_3 ) ;
error = F_18 ( log , V_99 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_98 = (struct V_97 * ) V_13 ;
if ( V_98 -> V_105 & V_106 ) {
F_61 ( & log -> V_107 ,
log -> V_108 , V_100 ) ;
F_61 ( & log -> V_109 ,
log -> V_108 , V_100 ) ;
* V_75 = V_100 ;
* V_96 = true ;
}
}
return 0 ;
}
static void
F_62 (
struct V_1 * log ,
T_2 V_66 ,
struct V_78 * V_79 ,
T_2 V_89 ,
bool V_110 )
{
log -> V_111 = V_89 ;
log -> V_112 = ( int ) V_66 ;
log -> V_108 = F_28 ( V_79 -> V_113 ) ;
if ( V_110 )
log -> V_108 ++ ;
F_63 ( & log -> V_107 , F_58 ( V_79 -> V_95 ) ) ;
F_63 ( & log -> V_109 , F_58 ( V_79 -> V_114 ) ) ;
F_64 ( & log -> V_115 . V_116 , log -> V_108 ,
F_11 ( log -> V_112 ) ) ;
F_64 ( & log -> V_117 . V_116 , log -> V_108 ,
F_11 ( log -> V_112 ) ) ;
}
STATIC int
F_65 (
struct V_1 * log ,
T_2 * V_66 ,
T_2 * V_75 )
{
T_4 * V_79 ;
char * V_13 = NULL ;
T_1 * V_6 ;
int error ;
T_2 V_89 ;
T_6 V_118 ;
bool V_80 = false ;
bool V_96 = false ;
if ( ( error = F_48 ( log , V_66 ) ) )
return error ;
ASSERT ( * V_66 < V_73 ) ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_52 ;
if ( * V_66 == 0 ) {
error = F_18 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_119;
if ( F_41 ( V_13 ) == 0 ) {
* V_75 = 0 ;
goto V_119;
}
}
error = F_52 ( log , * V_66 , * V_66 , 1 , V_6 ,
& V_89 , & V_79 , & V_80 ) ;
if ( error < 0 )
return error ;
if ( ! error ) {
F_3 ( log -> V_7 , L_16 , V_8 ) ;
return - V_61 ;
}
* V_75 = F_57 ( F_58 ( V_79 -> V_95 ) ) ;
F_62 ( log , * V_66 , V_79 , V_89 , V_80 ) ;
V_118 = F_66 ( & log -> V_107 ) ;
error = F_59 ( log , V_66 , V_75 , V_79 ,
V_89 , V_6 , & V_96 ) ;
if ( error )
goto V_119;
if ( ! V_96 ) {
T_2 V_120 = * V_66 ;
error = F_56 ( log , V_66 , V_75 , V_6 ,
& V_89 , & V_79 , & V_80 ) ;
if ( error )
goto V_119;
if ( * V_66 != V_120 ) {
F_62 ( log , * V_66 , V_79 , V_89 ,
V_80 ) ;
V_118 = F_66 ( & log -> V_107 ) ;
error = F_59 ( log , V_66 , V_75 ,
V_79 , V_89 , V_6 ,
& V_96 ) ;
if ( error )
goto V_119;
}
}
if ( V_96 )
log -> V_7 -> V_121 |= V_122 ;
if ( ! F_67 ( log -> V_7 -> V_11 ) )
error = F_68 ( log , V_118 ) ;
V_119:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_17 ) ;
return error ;
}
STATIC int
F_49 (
struct V_1 * log ,
T_2 * V_12 )
{
T_1 * V_6 ;
char * V_13 ;
T_5 V_123 , V_124 ;
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
V_123 = F_41 ( V_13 ) ;
if ( V_123 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return 1 ;
}
error = F_18 ( log , V_71 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_72;
V_124 = F_41 ( V_13 ) ;
if ( V_124 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_123 != 1 ) {
F_3 ( log -> V_7 ,
L_18 ) ;
error = - V_125 ;
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
F_69 (
struct V_1 * log ,
char * V_51 ,
int V_41 ,
int V_126 ,
int V_127 ,
int V_128 )
{
T_4 * V_129 = ( T_4 * ) V_51 ;
memset ( V_51 , 0 , V_55 ) ;
V_129 -> V_32 = F_30 ( V_33 ) ;
V_129 -> V_113 = F_30 ( V_41 ) ;
V_129 -> V_102 = F_30 (
F_46 ( & log -> V_7 -> V_27 ) ? 2 : 1 ) ;
V_129 -> V_114 = F_70 ( F_71 ( V_41 , V_126 ) ) ;
V_129 -> V_95 = F_70 ( F_71 ( V_127 , V_128 ) ) ;
V_129 -> V_31 = F_30 ( V_29 ) ;
memcpy ( & V_129 -> V_30 , & log -> V_7 -> V_27 . V_28 , sizeof( V_130 ) ) ;
}
STATIC int
F_72 (
struct V_1 * log ,
int V_41 ,
int V_131 ,
int V_132 ,
int V_127 ,
int V_128 )
{
char * V_13 ;
T_1 * V_6 ;
int V_133 , V_134 ;
int V_135 = log -> V_10 ;
int V_136 = V_131 + V_132 ;
int V_50 ;
int error = 0 ;
int V_48 , V_49 = 0 ;
V_50 = 1 << F_43 ( V_132 ) ;
while ( V_50 > log -> V_3 )
V_50 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_50 ) ) ) {
V_50 >>= 1 ;
if ( V_50 < V_135 )
return - V_52 ;
}
V_133 = F_13 ( V_131 , V_135 ) ;
if ( V_133 != V_131 ) {
error = F_12 ( log , V_131 , 1 , V_6 ) ;
if ( error )
goto V_137;
V_49 = V_131 - V_133 ;
}
for ( V_48 = V_131 ; V_48 < V_136 ; V_48 += V_50 ) {
int V_53 , V_138 ;
V_53 = F_44 ( V_50 , V_136 - V_131 ) ;
V_138 = V_53 - V_49 ;
V_134 = F_13 ( V_136 , V_135 ) ;
if ( V_49 == 0 && ( V_131 + V_138 > V_134 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_134 - V_131 ) ;
error = F_19 ( log , V_134 , V_135 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_131 , V_138 , V_6 ) ;
for (; V_49 < V_138 ; V_49 ++ ) {
F_69 ( log , V_13 , V_41 , V_48 + V_49 ,
V_127 , V_128 ) ;
V_13 += V_55 ;
}
error = F_21 ( log , V_131 , V_138 , V_6 ) ;
if ( error )
break;
V_131 += V_138 ;
V_49 = 0 ;
}
V_137:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_68 (
struct V_1 * log ,
T_6 V_118 )
{
int V_127 , V_139 ;
int V_128 , V_140 ;
int V_141 , V_142 ;
int V_143 ;
int error ;
V_127 = F_73 ( V_118 ) ;
V_128 = F_57 ( V_118 ) ;
V_139 = log -> V_108 ;
V_140 = log -> V_112 ;
if ( V_139 == V_127 ) {
if ( F_31 ( V_140 < V_128 || V_140 >= log -> V_3 ) ) {
F_4 ( L_19 ,
V_144 , log -> V_7 ) ;
return - V_16 ;
}
V_141 = V_128 + ( log -> V_3 - V_140 ) ;
} else {
if ( F_31 ( V_140 >= V_128 || V_139 != ( V_127 + 1 ) ) ) {
F_4 ( L_20 ,
V_144 , log -> V_7 ) ;
return - V_16 ;
}
V_141 = V_128 - V_140 ;
}
if ( V_141 <= 0 ) {
ASSERT ( V_141 == 0 ) ;
return 0 ;
}
V_142 = F_50 ( log ) ;
V_142 = F_74 ( V_142 , V_141 ) ;
if ( ( V_140 + V_142 ) <= log -> V_3 ) {
error = F_72 ( log , ( V_139 - 1 ) ,
V_140 , V_142 , V_127 ,
V_128 ) ;
if ( error )
return error ;
} else {
V_143 = log -> V_3 - V_140 ;
error = F_72 ( log , ( V_139 - 1 ) ,
V_140 , V_143 , V_127 ,
V_128 ) ;
if ( error )
return error ;
V_143 = V_142 - ( log -> V_3 - V_140 ) ;
error = F_72 ( log , V_139 , 0 , V_143 ,
V_127 , V_128 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_75 (
struct V_1 * log ,
struct V_145 * V_146 ,
int V_147 )
{
T_7 * V_148 , * V_149 ;
int error = 0 ;
F_76 ( V_150 ) ;
F_76 ( V_151 ) ;
F_76 ( V_152 ) ;
F_76 ( V_153 ) ;
F_76 ( V_154 ) ;
F_77 ( & V_146 -> V_155 , & V_150 ) ;
F_78 (item, n, &sort_list, ri_list) {
T_8 * V_156 = V_148 -> V_157 [ 0 ] . V_158 ;
switch ( F_79 ( V_148 ) ) {
case V_159 :
F_80 ( & V_148 -> V_160 , & V_152 ) ;
break;
case V_161 :
if ( V_156 -> V_162 & V_163 ) {
F_81 ( log ,
V_146 , V_148 , V_147 ) ;
F_82 ( & V_148 -> V_160 , & V_151 ) ;
break;
}
if ( V_156 -> V_162 & V_164 ) {
F_82 ( & V_148 -> V_160 , & V_153 ) ;
break;
}
F_80 ( & V_148 -> V_160 , & V_152 ) ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
F_83 ( log ,
V_146 , V_148 , V_147 ) ;
F_80 ( & V_148 -> V_160 , & V_154 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_21 ,
V_8 ) ;
ASSERT ( 0 ) ;
if ( ! F_84 ( & V_150 ) )
F_77 ( & V_150 , & V_146 -> V_155 ) ;
error = - V_61 ;
goto V_54;
}
}
V_54:
ASSERT ( F_84 ( & V_150 ) ) ;
if ( ! F_84 ( & V_152 ) )
F_85 ( & V_152 , & V_146 -> V_155 ) ;
if ( ! F_84 ( & V_154 ) )
F_86 ( & V_154 , & V_146 -> V_155 ) ;
if ( ! F_84 ( & V_153 ) )
F_86 ( & V_153 , & V_146 -> V_155 ) ;
if ( ! F_84 ( & V_151 ) )
F_86 ( & V_151 , & V_146 -> V_155 ) ;
return error ;
}
STATIC int
F_87 (
struct V_1 * log ,
struct V_176 * V_148 )
{
T_8 * V_156 = V_148 -> V_157 [ 0 ] . V_158 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
if ( ! ( V_156 -> V_162 & V_163 ) ) {
F_88 ( log , V_156 ) ;
return 0 ;
}
V_178 = F_89 ( log , V_156 -> V_181 ) ;
F_90 (bcp, bucket, bc_list) {
if ( V_180 -> V_182 == V_156 -> V_181 &&
V_180 -> V_183 == V_156 -> V_184 ) {
V_180 -> V_185 ++ ;
F_91 ( log , V_156 ) ;
return 0 ;
}
}
V_180 = F_92 ( sizeof( struct V_179 ) , V_186 ) ;
V_180 -> V_182 = V_156 -> V_181 ;
V_180 -> V_183 = V_156 -> V_184 ;
V_180 -> V_185 = 1 ;
F_93 ( & V_180 -> V_187 , V_178 ) ;
F_94 ( log , V_156 ) ;
return 0 ;
}
STATIC struct V_179 *
F_95 (
struct V_1 * log ,
T_2 V_188 ,
T_5 V_189 ,
unsigned short V_190 )
{
struct V_177 * V_178 ;
struct V_179 * V_180 ;
if ( ! log -> V_191 ) {
ASSERT ( ! ( V_190 & V_163 ) ) ;
return NULL ;
}
V_178 = F_89 ( log , V_188 ) ;
F_90 (bcp, bucket, bc_list) {
if ( V_180 -> V_182 == V_188 && V_180 -> V_183 == V_189 )
return V_180 ;
}
ASSERT ( ! ( V_190 & V_163 ) ) ;
return NULL ;
}
STATIC int
F_96 (
struct V_1 * log ,
T_2 V_188 ,
T_5 V_189 ,
unsigned short V_190 )
{
struct V_179 * V_180 ;
V_180 = F_95 ( log , V_188 , V_189 , V_190 ) ;
if ( ! V_180 )
return 0 ;
if ( V_190 & V_163 ) {
if ( -- V_180 -> V_185 == 0 ) {
F_97 ( & V_180 -> V_187 ) ;
F_98 ( V_180 ) ;
}
}
return 1 ;
}
STATIC int
F_99 (
struct V_192 * V_25 ,
T_7 * V_148 ,
struct V_5 * V_6 ,
T_8 * V_156 )
{
int V_48 ;
int V_193 = 0 ;
int V_194 = 0 ;
int V_195 = 0 ;
int V_196 = 0 ;
int V_197 = 0 ;
int V_198 ;
int V_199 ;
T_9 * V_200 ;
T_9 * V_201 ;
F_100 ( V_25 -> V_202 , V_156 ) ;
if ( F_101 ( & V_25 -> V_27 ) )
V_6 -> V_203 = & V_204 ;
V_199 = F_11 ( V_6 -> V_20 ) >> V_25 -> V_27 . V_205 ;
for ( V_48 = 0 ; V_48 < V_199 ; V_48 ++ ) {
V_198 = ( V_48 * V_25 -> V_27 . V_206 ) +
F_102 ( V_207 , V_208 ) ;
while ( V_198 >=
( V_196 + V_197 ) ) {
V_194 += V_195 ;
V_194 = F_103 ( V_156 -> V_209 ,
V_156 -> V_210 , V_194 ) ;
if ( V_194 == - 1 )
return 0 ;
V_195 = F_104 ( V_156 -> V_209 ,
V_156 -> V_210 , V_194 ) ;
ASSERT ( V_195 > 0 ) ;
V_196 = V_194 << V_211 ;
V_197 = V_195 << V_211 ;
V_193 ++ ;
}
if ( V_198 < V_196 )
continue;
ASSERT ( V_148 -> V_157 [ V_193 ] . V_158 != NULL ) ;
ASSERT ( ( V_148 -> V_157 [ V_193 ] . V_212 % V_213 ) == 0 ) ;
ASSERT ( ( V_196 + V_197 ) <=
F_11 ( V_6 -> V_20 ) ) ;
V_200 = V_148 -> V_157 [ V_193 ] . V_158 +
V_198 - V_196 ;
if ( F_31 ( * V_200 == 0 ) ) {
F_105 ( V_25 ,
L_22
L_23 ,
V_148 , V_6 ) ;
F_4 ( L_24 ,
V_144 , V_25 ) ;
return - V_16 ;
}
V_201 = F_106 ( V_6 , V_198 ) ;
* V_201 = * V_200 ;
F_107 ( V_25 ,
F_106 ( V_6 , V_48 * V_25 -> V_27 . V_206 ) ) ;
}
return 0 ;
}
static T_6
F_108 (
struct V_192 * V_25 ,
struct V_5 * V_6 )
{
T_10 V_214 ;
T_11 V_215 ;
T_11 V_216 ;
void * V_217 = V_6 -> V_15 ;
V_130 * V_218 ;
T_6 V_219 = - 1 ;
if ( ! F_101 ( & V_25 -> V_27 ) )
goto V_220;
V_214 = F_28 ( * ( V_83 * ) V_217 ) ;
switch ( V_214 ) {
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 : {
struct V_229 * V_230 = V_217 ;
V_219 = F_58 ( V_230 -> V_231 . V_232 . V_233 ) ;
V_218 = & V_230 -> V_231 . V_232 . V_234 ;
break;
}
case V_235 :
case V_236 : {
struct V_229 * V_230 = V_217 ;
V_219 = F_58 ( V_230 -> V_231 . V_237 . V_233 ) ;
V_218 = & V_230 -> V_231 . V_237 . V_234 ;
break;
}
case V_238 :
V_219 = F_58 ( ( (struct V_239 * ) V_217 ) -> V_240 ) ;
V_218 = & ( (struct V_239 * ) V_217 ) -> V_241 ;
break;
case V_242 :
V_219 = F_58 ( ( (struct V_243 * ) V_217 ) -> V_244 ) ;
V_218 = & ( (struct V_243 * ) V_217 ) -> V_245 ;
break;
case V_246 :
V_219 = F_58 ( ( (struct V_247 * ) V_217 ) -> V_248 ) ;
V_218 = & ( (struct V_247 * ) V_217 ) -> V_249 ;
break;
case V_250 :
V_219 = F_58 ( ( (struct V_251 * ) V_217 ) -> V_252 ) ;
V_218 = & ( (struct V_251 * ) V_217 ) -> V_253 ;
break;
case V_254 :
case V_255 :
case V_256 :
V_219 = F_58 ( ( (struct V_257 * ) V_217 ) -> V_219 ) ;
V_218 = & ( (struct V_257 * ) V_217 ) -> V_218 ;
break;
case V_258 :
goto V_220;
case V_259 :
V_219 = F_58 ( ( (struct V_260 * ) V_217 ) -> V_261 ) ;
if ( F_109 ( & V_25 -> V_27 ) )
V_218 = & ( (struct V_260 * ) V_217 ) -> V_262 ;
else
V_218 = & ( (struct V_260 * ) V_217 ) -> V_28 ;
break;
default:
break;
}
if ( V_219 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_262 , V_218 ) )
goto V_220;
return V_219 ;
}
V_216 = F_110 ( ( (struct V_263 * ) V_217 ) -> V_264 ) ;
switch ( V_216 ) {
case V_265 :
case V_266 :
case V_267 :
V_219 = F_58 ( ( (struct V_268 * ) V_217 ) -> V_219 ) ;
V_218 = & ( (struct V_268 * ) V_217 ) -> V_218 ;
break;
default:
break;
}
if ( V_219 != ( T_6 ) - 1 ) {
if ( ! F_32 ( & V_25 -> V_27 . V_28 , V_218 ) )
goto V_220;
return V_219 ;
}
V_215 = F_110 ( * ( V_269 * ) V_217 ) ;
switch ( V_215 ) {
case V_270 :
case V_271 :
goto V_220;
default:
break;
}
V_220:
return ( T_6 ) - 1 ;
}
static void
F_111 (
struct V_192 * V_25 ,
struct V_5 * V_6 ,
T_8 * V_156 ,
T_6 V_272 )
{
struct V_263 * V_273 = V_6 -> V_15 ;
T_10 V_214 ;
T_11 V_215 ;
T_11 V_216 ;
char * V_274 = NULL ;
if ( ! F_101 ( & V_25 -> V_27 ) )
return;
V_214 = F_28 ( * ( V_83 * ) V_6 -> V_15 ) ;
V_215 = F_110 ( * ( V_269 * ) V_6 -> V_15 ) ;
V_216 = F_110 ( V_273 -> V_264 ) ;
switch ( F_112 ( V_156 ) ) {
case V_275 :
switch ( V_214 ) {
case V_221 :
case V_222 :
case V_223 :
case V_224 :
V_6 -> V_203 = & V_276 ;
break;
case V_227 :
case V_277 :
case V_228 :
case V_278 :
V_6 -> V_203 = & V_279 ;
break;
case V_235 :
case V_236 :
V_6 -> V_203 = & V_280 ;
break;
case V_225 :
V_6 -> V_203 = & V_281 ;
break;
case V_226 :
V_6 -> V_203 = & V_282 ;
break;
default:
V_274 = L_25 ;
break;
}
break;
case V_283 :
if ( V_214 != V_238 ) {
V_274 = L_26 ;
break;
}
V_6 -> V_203 = & V_284 ;
break;
case V_285 :
if ( V_214 != V_242 ) {
V_274 = L_27 ;
break;
}
V_6 -> V_203 = & V_286 ;
break;
case V_287 :
if ( V_214 != V_246 ) {
V_274 = L_28 ;
break;
}
V_6 -> V_203 = & V_288 ;
break;
case V_289 :
case V_290 :
case V_291 :
#ifdef F_113
if ( V_215 != V_270 ) {
V_274 = L_29 ;
break;
}
V_6 -> V_203 = & V_292 ;
#else
F_105 ( V_25 ,
L_30 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_293 :
if ( V_215 != V_271 ) {
V_274 = L_31 ;
break;
}
V_6 -> V_203 = & V_204 ;
break;
case V_294 :
if ( V_214 != V_250 ) {
V_274 = L_32 ;
break;
}
V_6 -> V_203 = & V_295 ;
break;
case V_296 :
if ( V_214 != V_297 &&
V_214 != V_254 ) {
V_274 = L_33 ;
break;
}
V_6 -> V_203 = & V_298 ;
break;
case V_299 :
if ( V_214 != V_300 &&
V_214 != V_255 ) {
V_274 = L_34 ;
break;
}
V_6 -> V_203 = & V_301 ;
break;
case V_302 :
if ( V_214 != V_303 &&
V_214 != V_256 ) {
V_274 = L_35 ;
break;
}
V_6 -> V_203 = & V_304 ;
break;
case V_305 :
if ( V_216 != V_306 &&
V_216 != V_265 ) {
V_274 = L_36 ;
break;
}
V_6 -> V_203 = & V_307 ;
break;
case V_308 :
if ( V_216 != V_309 &&
V_216 != V_266 ) {
V_274 = L_37 ;
break;
}
V_6 -> V_203 = & V_310 ;
break;
case V_311 :
if ( V_216 != V_312 &&
V_216 != V_267 ) {
V_274 = L_38 ;
break;
}
V_6 -> V_203 = & V_313 ;
break;
case V_314 :
if ( V_216 != V_315 &&
V_216 != V_316 ) {
V_274 = L_39 ;
break;
}
V_6 -> V_203 = & V_317 ;
break;
case V_318 :
if ( V_214 != V_258 ) {
V_274 = L_40 ;
break;
}
V_6 -> V_203 = & V_319 ;
break;
case V_320 :
if ( V_214 != V_259 ) {
V_274 = L_41 ;
break;
}
V_6 -> V_203 = & V_321 ;
break;
#ifdef F_114
case V_322 :
case V_323 :
V_6 -> V_203 = & V_324 ;
break;
#endif
default:
F_3 ( V_25 , L_42 ,
F_112 ( V_156 ) ) ;
break;
}
if ( V_272 == V_325 )
return;
if ( V_274 ) {
F_3 ( V_25 , V_274 ) ;
ASSERT ( 0 ) ;
}
if ( V_6 -> V_203 ) {
struct V_326 * V_327 ;
ASSERT ( ! V_6 -> V_38 || V_6 -> V_38 == F_35 ) ;
V_6 -> V_38 = F_35 ;
F_115 ( V_6 , V_25 ) ;
V_327 = V_6 -> V_37 ;
V_327 -> V_328 . V_329 = V_272 ;
}
}
STATIC void
F_116 (
struct V_192 * V_25 ,
T_7 * V_148 ,
struct V_5 * V_6 ,
T_8 * V_156 ,
T_6 V_272 )
{
int V_48 ;
int V_194 ;
int V_195 ;
int error ;
F_117 ( V_25 -> V_202 , V_156 ) ;
V_194 = 0 ;
V_48 = 1 ;
while ( 1 ) {
V_194 = F_103 ( V_156 -> V_209 ,
V_156 -> V_210 , V_194 ) ;
if ( V_194 == - 1 )
break;
V_195 = F_104 ( V_156 -> V_209 ,
V_156 -> V_210 , V_194 ) ;
ASSERT ( V_195 > 0 ) ;
ASSERT ( V_148 -> V_157 [ V_48 ] . V_158 != NULL ) ;
ASSERT ( V_148 -> V_157 [ V_48 ] . V_212 % V_213 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_20 ) >=
( ( T_5 ) V_194 << V_211 ) + ( V_195 << V_211 ) ) ;
if ( V_148 -> V_157 [ V_48 ] . V_212 < ( V_195 << V_211 ) )
V_195 = V_148 -> V_157 [ V_48 ] . V_212 >> V_211 ;
error = 0 ;
if ( V_156 -> V_162 &
( V_330 | V_331 | V_332 ) ) {
if ( V_148 -> V_157 [ V_48 ] . V_158 == NULL ) {
F_105 ( V_25 ,
L_43 , V_8 ) ;
goto V_333;
}
if ( V_148 -> V_157 [ V_48 ] . V_212 < sizeof( V_334 ) ) {
F_105 ( V_25 ,
L_44 ,
V_148 -> V_157 [ V_48 ] . V_212 , V_8 ) ;
goto V_333;
}
error = F_118 ( V_25 , V_148 -> V_157 [ V_48 ] . V_158 ,
- 1 , 0 , V_335 ,
L_45 ) ;
if ( error )
goto V_333;
}
memcpy ( F_106 ( V_6 ,
( T_5 ) V_194 << V_211 ) ,
V_148 -> V_157 [ V_48 ] . V_158 ,
V_195 << V_211 ) ;
V_333:
V_48 ++ ;
V_194 += V_195 ;
}
ASSERT ( V_48 == V_148 -> V_336 ) ;
F_111 ( V_25 , V_6 , V_156 , V_272 ) ;
}
STATIC bool
F_119 (
struct V_192 * V_25 ,
struct V_1 * log ,
struct V_176 * V_148 ,
struct V_5 * V_6 ,
struct V_337 * V_156 )
{
T_5 type ;
F_120 ( log , V_156 ) ;
if ( ! V_25 -> V_338 )
return false ;
type = 0 ;
if ( V_156 -> V_162 & V_330 )
type |= V_339 ;
if ( V_156 -> V_162 & V_331 )
type |= V_340 ;
if ( V_156 -> V_162 & V_332 )
type |= V_341 ;
if ( log -> V_342 & type )
return false ;
F_116 ( V_25 , V_148 , V_6 , V_156 , V_325 ) ;
return true ;
}
STATIC int
F_121 (
struct V_1 * log ,
struct V_177 * V_152 ,
struct V_176 * V_148 ,
T_6 V_272 )
{
T_8 * V_156 = V_148 -> V_157 [ 0 ] . V_158 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_5 V_343 ;
T_6 V_219 ;
if ( F_96 ( log , V_156 -> V_181 ,
V_156 -> V_184 , V_156 -> V_162 ) ) {
F_122 ( log , V_156 ) ;
return 0 ;
}
F_123 ( log , V_156 ) ;
V_343 = 0 ;
if ( V_156 -> V_162 & V_164 )
V_343 |= V_344 ;
V_6 = F_124 ( V_25 -> V_345 , V_156 -> V_181 , V_156 -> V_184 ,
V_343 , NULL ) ;
if ( ! V_6 )
return - V_52 ;
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_46 ) ;
goto V_346;
}
V_219 = F_108 ( V_25 , V_6 ) ;
if ( V_219 && V_219 != - 1 && F_125 ( V_219 , V_272 ) >= 0 ) {
F_126 ( log , V_156 ) ;
F_111 ( V_25 , V_6 , V_156 , V_325 ) ;
goto V_346;
}
if ( V_156 -> V_162 & V_164 ) {
error = F_99 ( V_25 , V_148 , V_6 , V_156 ) ;
if ( error )
goto V_346;
} else if ( V_156 -> V_162 &
( V_330 | V_331 | V_332 ) ) {
bool V_347 ;
V_347 = F_119 ( V_25 , log , V_148 , V_6 , V_156 ) ;
if ( ! V_347 )
goto V_346;
} else {
F_116 ( V_25 , V_148 , V_6 , V_156 , V_272 ) ;
}
if ( V_271 ==
F_110 ( * ( ( V_269 * ) F_106 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_20 ) != F_127 ( log -> V_7 -> V_27 . V_348 ,
( T_10 ) log -> V_7 -> V_349 ) ) ) {
F_128 ( V_6 ) ;
error = F_24 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_38 = F_35 ;
F_129 ( V_6 , V_152 ) ;
}
V_346:
F_25 ( V_6 ) ;
return error ;
}
STATIC int
F_130 (
struct V_192 * V_25 ,
struct V_350 * V_351 ,
struct V_352 * V_353 ,
struct V_177 * V_152 )
{
struct V_354 * V_355 ;
int error ;
ASSERT ( V_353 -> V_356 & ( V_357 | V_358 ) ) ;
V_355 = F_131 ( V_25 , V_353 -> V_359 ) ;
if ( ! V_355 )
return - V_52 ;
F_132 ( V_355 , V_351 ) ;
ASSERT ( V_355 -> V_360 . V_361 >= 3 ) ;
error = F_133 ( V_355 , V_351 ) ;
if ( error )
goto V_362;
if ( V_353 -> V_356 & V_357 ) {
ASSERT ( V_353 -> V_356 & V_363 ) ;
error = F_134 ( NULL , V_355 , V_364 ,
V_355 -> V_365 , V_152 ) ;
if ( error )
goto V_362;
}
if ( V_353 -> V_356 & V_358 ) {
ASSERT ( V_353 -> V_356 & V_366 ) ;
error = F_134 ( NULL , V_355 , V_367 ,
V_355 -> V_365 , V_152 ) ;
if ( error )
goto V_362;
}
V_362:
F_135 ( V_355 ) ;
return error ;
}
STATIC int
F_136 (
struct V_1 * log ,
struct V_177 * V_152 ,
struct V_176 * V_148 ,
T_6 V_272 )
{
T_12 * V_353 ;
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
V_207 * V_351 ;
int V_189 ;
char * V_368 ;
char * V_369 ;
int error ;
int V_370 ;
T_5 V_371 ;
struct V_372 * V_373 ;
T_5 V_374 ;
int V_375 = 0 ;
if ( V_148 -> V_157 [ 0 ] . V_212 == sizeof( T_12 ) ) {
V_353 = V_148 -> V_157 [ 0 ] . V_158 ;
} else {
V_353 = F_92 ( sizeof( T_12 ) , V_186 ) ;
V_375 = 1 ;
error = F_137 ( & V_148 -> V_157 [ 0 ] , V_353 ) ;
if ( error )
goto error;
}
if ( F_96 ( log , V_353 -> V_376 ,
V_353 -> V_377 , 0 ) ) {
error = 0 ;
F_138 ( log , V_353 ) ;
goto error;
}
F_139 ( log , V_353 ) ;
V_6 = F_124 ( V_25 -> V_345 , V_353 -> V_376 , V_353 -> V_377 , 0 ,
& V_204 ) ;
if ( ! V_6 ) {
error = - V_52 ;
goto error;
}
error = V_6 -> V_21 ;
if ( error ) {
F_17 ( V_6 , L_47 ) ;
goto V_346;
}
ASSERT ( V_353 -> V_356 & V_378 ) ;
V_351 = F_106 ( V_6 , V_353 -> V_379 ) ;
if ( F_31 ( V_351 -> V_380 != F_140 ( V_271 ) ) ) {
F_105 ( V_25 ,
L_48 ,
V_8 , V_351 , V_6 , V_353 -> V_359 ) ;
F_4 ( L_49 ,
V_144 , V_25 ) ;
error = - V_16 ;
goto V_346;
}
V_373 = V_148 -> V_157 [ 1 ] . V_158 ;
if ( F_31 ( V_373 -> V_380 != V_271 ) ) {
F_105 ( V_25 ,
L_50 ,
V_8 , V_148 , V_353 -> V_359 ) ;
F_4 ( L_51 ,
V_144 , V_25 ) ;
error = - V_16 ;
goto V_346;
}
if ( V_351 -> V_361 >= 3 ) {
T_6 V_219 = F_58 ( V_351 -> V_381 ) ;
if ( V_219 && V_219 != - 1 && F_125 ( V_219 , V_272 ) >= 0 ) {
F_141 ( log , V_353 ) ;
error = 0 ;
goto V_382;
}
}
if ( ! F_101 ( & V_25 -> V_27 ) &&
V_373 -> V_383 < F_110 ( V_351 -> V_383 ) ) {
if ( F_110 ( V_351 -> V_383 ) == V_384 &&
V_373 -> V_383 < ( V_384 >> 1 ) ) {
} else {
F_141 ( log , V_353 ) ;
error = 0 ;
goto V_346;
}
}
V_373 -> V_383 = 0 ;
if ( F_31 ( F_142 ( V_373 -> V_385 ) ) ) {
if ( ( V_373 -> V_386 != V_387 ) &&
( V_373 -> V_386 != V_388 ) ) {
F_143 ( L_52 ,
V_144 , V_25 , V_373 ) ;
F_105 ( V_25 ,
L_53
L_54 ,
V_8 , V_148 , V_351 , V_6 , V_353 -> V_359 ) ;
error = - V_16 ;
goto V_346;
}
} else if ( F_31 ( F_144 ( V_373 -> V_385 ) ) ) {
if ( ( V_373 -> V_386 != V_387 ) &&
( V_373 -> V_386 != V_388 ) &&
( V_373 -> V_386 != V_389 ) ) {
F_143 ( L_55 ,
V_144 , V_25 , V_373 ) ;
F_105 ( V_25 ,
L_56
L_54 ,
V_8 , V_148 , V_351 , V_6 , V_353 -> V_359 ) ;
error = - V_16 ;
goto V_346;
}
}
if ( F_31 ( V_373 -> V_390 + V_373 -> V_391 > V_373 -> V_392 ) ) {
F_143 ( L_57 ,
V_144 , V_25 , V_373 ) ;
F_105 ( V_25 ,
L_58
L_59 ,
V_8 , V_148 , V_351 , V_6 , V_353 -> V_359 ,
V_373 -> V_390 + V_373 -> V_391 ,
V_373 -> V_392 ) ;
error = - V_16 ;
goto V_346;
}
if ( F_31 ( V_373 -> V_393 > V_25 -> V_27 . V_206 ) ) {
F_143 ( L_60 ,
V_144 , V_25 , V_373 ) ;
F_105 ( V_25 ,
L_58
L_61 , V_8 ,
V_148 , V_351 , V_6 , V_353 -> V_359 , V_373 -> V_393 ) ;
error = - V_16 ;
goto V_346;
}
V_374 = F_145 ( V_373 -> V_361 ) ;
if ( F_31 ( V_148 -> V_157 [ 1 ] . V_212 > V_374 ) ) {
F_143 ( L_62 ,
V_144 , V_25 , V_373 ) ;
F_105 ( V_25 ,
L_63 ,
V_8 , V_148 -> V_157 [ 1 ] . V_212 , V_148 ) ;
error = - V_16 ;
goto V_346;
}
F_146 ( V_373 , V_351 ) ;
if ( V_148 -> V_157 [ 1 ] . V_212 > V_374 ) {
memcpy ( ( char * ) V_351 + V_374 ,
V_148 -> V_157 [ 1 ] . V_158 + V_374 ,
V_148 -> V_157 [ 1 ] . V_212 - V_374 ) ;
}
V_371 = V_353 -> V_356 ;
switch ( V_371 & ( V_394 | V_395 ) ) {
case V_394 :
F_147 ( V_351 , V_353 -> V_396 . V_397 ) ;
break;
case V_395 :
memcpy ( F_148 ( V_351 ) ,
& V_353 -> V_396 . V_398 ,
sizeof( V_130 ) ) ;
break;
}
if ( V_353 -> V_399 == 2 )
goto V_382;
V_189 = V_148 -> V_157 [ 2 ] . V_212 ;
V_368 = V_148 -> V_157 [ 2 ] . V_158 ;
ASSERT ( V_353 -> V_399 <= 4 ) ;
ASSERT ( ( V_353 -> V_399 == 3 ) || ( V_371 & V_400 ) ) ;
ASSERT ( ! ( V_371 & V_401 ) ||
( V_189 == V_353 -> V_402 ) ) ;
switch ( V_371 & V_401 ) {
case V_403 :
case V_404 :
memcpy ( F_148 ( V_351 ) , V_368 , V_189 ) ;
break;
case V_363 :
F_149 ( V_25 , (struct V_229 * ) V_368 , V_189 ,
( V_405 * ) F_148 ( V_351 ) ,
F_150 ( V_351 , V_25 ) ) ;
break;
default:
ASSERT ( ( V_371 & V_401 ) == 0 ) ;
break;
}
if ( V_353 -> V_356 & V_400 ) {
if ( V_353 -> V_356 & V_401 ) {
V_370 = 3 ;
} else {
V_370 = 2 ;
}
V_189 = V_148 -> V_157 [ V_370 ] . V_212 ;
V_368 = V_148 -> V_157 [ V_370 ] . V_158 ;
ASSERT ( V_189 == V_353 -> V_406 ) ;
switch ( V_353 -> V_356 & V_400 ) {
case V_407 :
case V_408 :
V_369 = F_151 ( V_351 ) ;
ASSERT ( V_189 <= F_152 ( V_351 , V_25 ) ) ;
memcpy ( V_369 , V_368 , V_189 ) ;
break;
case V_366 :
V_369 = F_151 ( V_351 ) ;
F_149 ( V_25 , (struct V_229 * ) V_368 ,
V_189 , ( V_405 * ) V_369 ,
F_152 ( V_351 , V_25 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_64 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_61 ;
goto V_346;
}
}
V_382:
if ( V_353 -> V_356 & ( V_357 | V_358 ) )
error = F_130 ( V_25 , V_351 , V_353 ,
V_152 ) ;
F_107 ( log -> V_7 , V_351 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_38 = F_35 ;
F_129 ( V_6 , V_152 ) ;
V_346:
F_25 ( V_6 ) ;
error:
if ( V_375 )
F_98 ( V_353 ) ;
return error ;
}
STATIC int
F_153 (
struct V_1 * log ,
struct V_176 * V_148 )
{
T_13 * V_409 = V_148 -> V_157 [ 0 ] . V_158 ;
ASSERT ( V_409 ) ;
if ( V_409 -> V_410 & V_411 )
log -> V_342 |= V_339 ;
if ( V_409 -> V_410 & V_412 )
log -> V_342 |= V_340 ;
if ( V_409 -> V_410 & V_413 )
log -> V_342 |= V_341 ;
return 0 ;
}
STATIC int
F_154 (
struct V_1 * log ,
struct V_177 * V_152 ,
struct V_176 * V_148 ,
T_6 V_272 )
{
T_3 * V_25 = log -> V_7 ;
T_1 * V_6 ;
struct V_414 * V_415 , * V_416 ;
int error ;
T_14 * V_417 ;
T_5 type ;
if ( V_25 -> V_338 == 0 )
return 0 ;
V_416 = V_148 -> V_157 [ 1 ] . V_158 ;
if ( V_416 == NULL ) {
F_105 ( log -> V_7 , L_65 , V_8 ) ;
return - V_61 ;
}
if ( V_148 -> V_157 [ 1 ] . V_212 < sizeof( V_334 ) ) {
F_105 ( log -> V_7 , L_66 ,
V_148 -> V_157 [ 1 ] . V_212 , V_8 ) ;
return - V_61 ;
}
type = V_416 -> V_418 & ( V_339 | V_340 | V_341 ) ;
ASSERT ( type ) ;
if ( log -> V_342 & type )
return 0 ;
V_417 = V_148 -> V_157 [ 0 ] . V_158 ;
ASSERT ( V_417 ) ;
error = F_118 ( V_25 , V_416 , V_417 -> V_419 , 0 , V_335 ,
L_67 ) ;
if ( error )
return - V_61 ;
ASSERT ( V_417 -> V_420 == 1 ) ;
error = F_155 ( V_25 , NULL , V_25 -> V_345 , V_417 -> V_421 ,
F_156 ( V_25 , V_417 -> V_420 ) , 0 , & V_6 ,
& V_292 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_415 = F_106 ( V_6 , V_417 -> V_422 ) ;
if ( F_101 ( & V_25 -> V_27 ) ) {
struct V_423 * V_424 = (struct V_423 * ) V_415 ;
T_6 V_219 = F_58 ( V_424 -> V_425 ) ;
if ( V_219 && V_219 != - 1 && F_125 ( V_219 , V_272 ) >= 0 ) {
goto V_346;
}
}
memcpy ( V_415 , V_416 , V_148 -> V_157 [ 1 ] . V_212 ) ;
if ( F_101 ( & V_25 -> V_27 ) ) {
F_157 ( ( char * ) V_415 , sizeof( struct V_423 ) ,
V_426 ) ;
}
ASSERT ( V_417 -> V_427 == 2 ) ;
ASSERT ( V_6 -> V_34 -> V_35 == V_25 ) ;
V_6 -> V_38 = F_35 ;
F_129 ( V_6 , V_152 ) ;
V_346:
F_25 ( V_6 ) ;
return 0 ;
}
STATIC int
F_158 (
struct V_1 * log ,
struct V_176 * V_148 ,
T_6 V_219 )
{
int error ;
struct V_192 * V_25 = log -> V_7 ;
struct V_428 * V_429 ;
struct V_430 * V_431 ;
V_431 = V_148 -> V_157 [ 0 ] . V_158 ;
V_429 = F_159 ( V_25 , V_431 -> V_432 ) ;
error = F_160 ( & V_148 -> V_157 [ 0 ] , & V_429 -> V_433 ) ;
if ( error ) {
F_161 ( V_429 ) ;
return error ;
}
F_162 ( & V_429 -> V_434 , V_431 -> V_432 ) ;
F_163 ( & log -> V_435 -> V_436 ) ;
F_164 ( log -> V_435 , & V_429 -> V_437 , V_219 ) ;
F_165 ( V_429 ) ;
return 0 ;
}
STATIC int
F_166 (
struct V_1 * log ,
struct V_176 * V_148 )
{
T_15 * V_438 ;
T_16 * V_429 = NULL ;
T_17 * V_439 ;
T_18 V_440 ;
struct V_441 V_442 ;
struct V_443 * V_444 = log -> V_435 ;
V_438 = V_148 -> V_157 [ 0 ] . V_158 ;
ASSERT ( ( V_148 -> V_157 [ 0 ] . V_212 == ( sizeof( V_445 ) +
( ( V_438 -> V_446 - 1 ) * sizeof( V_447 ) ) ) ) ||
( V_148 -> V_157 [ 0 ] . V_212 == ( sizeof( V_448 ) +
( ( V_438 -> V_446 - 1 ) * sizeof( V_449 ) ) ) ) ) ;
V_440 = V_438 -> V_450 ;
F_163 ( & V_444 -> V_436 ) ;
V_439 = F_167 ( V_444 , & V_442 , 0 ) ;
while ( V_439 != NULL ) {
if ( V_439 -> V_451 == V_169 ) {
V_429 = ( T_16 * ) V_439 ;
if ( V_429 -> V_433 . V_440 == V_440 ) {
F_168 ( & V_444 -> V_436 ) ;
F_165 ( V_429 ) ;
F_163 ( & V_444 -> V_436 ) ;
break;
}
}
V_439 = F_169 ( V_444 , & V_442 ) ;
}
F_170 ( & V_442 ) ;
F_168 ( & V_444 -> V_436 ) ;
return 0 ;
}
STATIC int
F_171 (
struct V_1 * log ,
struct V_176 * V_148 ,
T_6 V_219 )
{
int error ;
struct V_192 * V_25 = log -> V_7 ;
struct V_452 * V_453 ;
struct V_454 * V_455 ;
V_455 = V_148 -> V_157 [ 0 ] . V_158 ;
V_453 = F_172 ( V_25 , V_455 -> V_456 ) ;
error = F_173 ( & V_148 -> V_157 [ 0 ] , & V_453 -> V_457 ) ;
if ( error ) {
F_174 ( V_453 ) ;
return error ;
}
F_162 ( & V_453 -> V_458 , V_455 -> V_456 ) ;
F_163 ( & log -> V_435 -> V_436 ) ;
F_164 ( log -> V_435 , & V_453 -> V_459 , V_219 ) ;
F_175 ( V_453 ) ;
return 0 ;
}
STATIC int
F_176 (
struct V_1 * log ,
struct V_176 * V_148 )
{
struct V_460 * V_461 ;
struct V_452 * V_453 = NULL ;
struct V_462 * V_439 ;
T_18 V_463 ;
struct V_441 V_442 ;
struct V_443 * V_444 = log -> V_435 ;
V_461 = V_148 -> V_157 [ 0 ] . V_158 ;
ASSERT ( V_148 -> V_157 [ 0 ] . V_212 == sizeof( struct V_460 ) ) ;
V_463 = V_461 -> V_464 ;
F_163 ( & V_444 -> V_436 ) ;
V_439 = F_167 ( V_444 , & V_442 , 0 ) ;
while ( V_439 != NULL ) {
if ( V_439 -> V_451 == V_170 ) {
V_453 = (struct V_452 * ) V_439 ;
if ( V_453 -> V_457 . V_463 == V_463 ) {
F_168 ( & V_444 -> V_436 ) ;
F_175 ( V_453 ) ;
F_163 ( & V_444 -> V_436 ) ;
break;
}
}
V_439 = F_169 ( V_444 , & V_442 ) ;
}
F_170 ( & V_442 ) ;
F_168 ( & V_444 -> V_436 ) ;
return 0 ;
}
static int
F_177 (
struct V_465 * V_51 ,
struct V_466 * V_467 )
{
struct V_466 * V_468 ;
T_5 V_189 ;
V_468 = V_51 -> V_158 ;
V_189 = F_178 ( V_468 -> V_469 ) ;
if ( V_51 -> V_212 == V_189 ) {
memcpy ( V_467 , V_468 , V_189 ) ;
return 0 ;
}
return - V_16 ;
}
STATIC int
F_179 (
struct V_1 * log ,
struct V_176 * V_148 ,
T_6 V_219 )
{
int error ;
struct V_192 * V_25 = log -> V_7 ;
struct V_470 * V_471 ;
struct V_466 * V_472 ;
V_472 = V_148 -> V_157 [ 0 ] . V_158 ;
V_471 = F_180 ( V_25 , V_472 -> V_469 ) ;
error = F_177 ( & V_148 -> V_157 [ 0 ] , & V_471 -> V_473 ) ;
if ( error ) {
F_181 ( V_471 ) ;
return error ;
}
F_162 ( & V_471 -> V_474 , V_472 -> V_469 ) ;
F_163 ( & log -> V_435 -> V_436 ) ;
F_164 ( log -> V_435 , & V_471 -> V_475 , V_219 ) ;
F_182 ( V_471 ) ;
return 0 ;
}
STATIC int
F_183 (
struct V_1 * log ,
struct V_176 * V_148 )
{
struct V_476 * V_477 ;
struct V_470 * V_471 = NULL ;
struct V_462 * V_439 ;
T_18 V_478 ;
struct V_441 V_442 ;
struct V_443 * V_444 = log -> V_435 ;
V_477 = V_148 -> V_157 [ 0 ] . V_158 ;
if ( V_148 -> V_157 [ 0 ] . V_212 != sizeof( struct V_476 ) )
return - V_16 ;
V_478 = V_477 -> V_479 ;
F_163 ( & V_444 -> V_436 ) ;
V_439 = F_167 ( V_444 , & V_442 , 0 ) ;
while ( V_439 != NULL ) {
if ( V_439 -> V_451 == V_172 ) {
V_471 = (struct V_470 * ) V_439 ;
if ( V_471 -> V_473 . V_478 == V_478 ) {
F_168 ( & V_444 -> V_436 ) ;
F_182 ( V_471 ) ;
F_163 ( & V_444 -> V_436 ) ;
break;
}
}
V_439 = F_169 ( V_444 , & V_442 ) ;
}
F_170 ( & V_442 ) ;
F_168 ( & V_444 -> V_436 ) ;
return 0 ;
}
static int
F_184 (
struct V_465 * V_51 ,
struct V_480 * V_481 )
{
struct V_480 * V_482 ;
T_5 V_189 ;
V_482 = V_51 -> V_158 ;
V_189 = F_185 ( V_482 -> V_483 ) ;
if ( V_51 -> V_212 == V_189 ) {
memcpy ( V_481 , V_482 , V_189 ) ;
return 0 ;
}
return - V_16 ;
}
STATIC int
F_186 (
struct V_1 * log ,
struct V_176 * V_148 ,
T_6 V_219 )
{
int error ;
struct V_192 * V_25 = log -> V_7 ;
struct V_484 * V_485 ;
struct V_480 * V_486 ;
V_486 = V_148 -> V_157 [ 0 ] . V_158 ;
if ( V_486 -> V_483 != V_487 )
return - V_16 ;
V_485 = F_187 ( V_25 ) ;
error = F_184 ( & V_148 -> V_157 [ 0 ] , & V_485 -> V_488 ) ;
if ( error ) {
F_188 ( V_485 ) ;
return error ;
}
F_162 ( & V_485 -> V_489 , V_486 -> V_483 ) ;
F_163 ( & log -> V_435 -> V_436 ) ;
F_164 ( log -> V_435 , & V_485 -> V_490 , V_219 ) ;
F_189 ( V_485 ) ;
return 0 ;
}
STATIC int
F_190 (
struct V_1 * log ,
struct V_176 * V_148 )
{
struct V_491 * V_492 ;
struct V_484 * V_485 = NULL ;
struct V_462 * V_439 ;
T_18 V_493 ;
struct V_441 V_442 ;
struct V_443 * V_444 = log -> V_435 ;
V_492 = V_148 -> V_157 [ 0 ] . V_158 ;
if ( V_148 -> V_157 [ 0 ] . V_212 != sizeof( struct V_491 ) )
return - V_16 ;
V_493 = V_492 -> V_494 ;
F_163 ( & V_444 -> V_436 ) ;
V_439 = F_167 ( V_444 , & V_442 , 0 ) ;
while ( V_439 != NULL ) {
if ( V_439 -> V_451 == V_174 ) {
V_485 = (struct V_484 * ) V_439 ;
if ( V_485 -> V_488 . V_493 == V_493 ) {
F_168 ( & V_444 -> V_436 ) ;
F_189 ( V_485 ) ;
F_163 ( & V_444 -> V_436 ) ;
break;
}
}
V_439 = F_169 ( V_444 , & V_442 ) ;
}
F_170 ( & V_442 ) ;
F_168 ( & V_444 -> V_436 ) ;
return 0 ;
}
STATIC int
F_191 (
struct V_1 * log ,
struct V_177 * V_152 ,
T_7 * V_148 )
{
struct V_192 * V_25 = log -> V_7 ;
struct V_495 * V_496 ;
T_19 V_497 ;
T_20 V_498 ;
unsigned int V_76 ;
unsigned int V_374 ;
T_20 V_499 ;
int V_500 ;
int V_501 ;
int V_502 ;
int V_503 ;
int V_48 ;
V_496 = (struct V_495 * ) V_148 -> V_157 [ 0 ] . V_158 ;
if ( V_496 -> V_504 != V_159 ) {
F_3 ( log -> V_7 , L_68 ) ;
return - V_125 ;
}
if ( V_496 -> V_505 != 1 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_125 ;
}
V_497 = F_28 ( V_496 -> V_506 ) ;
if ( V_497 >= V_25 -> V_27 . V_507 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_125 ;
}
V_498 = F_28 ( V_496 -> V_508 ) ;
if ( ! V_498 || V_498 == V_509 || V_498 >= V_25 -> V_27 . V_510 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_125 ;
}
V_374 = F_28 ( V_496 -> V_511 ) ;
if ( V_374 != V_25 -> V_27 . V_206 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_125 ;
}
V_76 = F_28 ( V_496 -> V_512 ) ;
if ( ! V_76 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_125 ;
}
V_499 = F_28 ( V_496 -> V_513 ) ;
if ( ! V_499 || V_499 >= V_25 -> V_27 . V_510 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_125 ;
}
if ( V_499 != V_25 -> V_514 &&
V_499 != V_25 -> V_515 ) {
F_3 ( log -> V_7 ,
L_75 , V_516 ) ;
return - V_125 ;
}
if ( ( V_76 >> V_25 -> V_27 . V_517 ) != V_499 ) {
F_3 ( log -> V_7 ,
L_76 ,
V_516 ) ;
return - V_125 ;
}
V_500 = F_192 ( V_25 ) ;
V_501 = F_156 ( V_25 , V_500 ) ;
V_503 = V_499 / V_500 ;
for ( V_48 = 0 , V_502 = 0 ; V_48 < V_503 ; V_48 ++ ) {
T_2 V_518 ;
V_518 = F_193 ( V_25 , V_497 ,
V_498 + V_48 * V_500 ) ;
if ( F_96 ( log , V_518 , V_501 , 0 ) )
V_502 ++ ;
}
ASSERT ( ! V_502 || V_502 == V_503 ) ;
if ( V_502 ) {
if ( V_502 != V_503 )
F_3 ( V_25 ,
L_77 ) ;
F_194 ( log , V_496 ) ;
return 0 ;
}
F_195 ( log , V_496 ) ;
return F_196 ( V_25 , NULL , V_152 , V_76 , V_497 , V_498 ,
V_499 , F_28 ( V_496 -> V_519 ) ) ;
}
STATIC void
F_197 (
struct V_1 * log ,
struct V_176 * V_148 )
{
struct V_337 * V_156 = V_148 -> V_157 [ 0 ] . V_158 ;
struct V_192 * V_25 = log -> V_7 ;
if ( F_95 ( log , V_156 -> V_181 ,
V_156 -> V_184 , V_156 -> V_162 ) ) {
return;
}
F_198 ( V_25 -> V_345 , V_156 -> V_181 ,
V_156 -> V_184 , NULL ) ;
}
STATIC void
F_199 (
struct V_1 * log ,
struct V_176 * V_148 )
{
struct V_352 V_520 ;
struct V_352 * V_521 ;
struct V_192 * V_25 = log -> V_7 ;
int error ;
if ( V_148 -> V_157 [ 0 ] . V_212 == sizeof( struct V_352 ) ) {
V_521 = V_148 -> V_157 [ 0 ] . V_158 ;
} else {
V_521 = & V_520 ;
memset ( V_521 , 0 , sizeof( * V_521 ) ) ;
error = F_137 ( & V_148 -> V_157 [ 0 ] , V_521 ) ;
if ( error )
return;
}
if ( F_95 ( log , V_521 -> V_376 , V_521 -> V_377 , 0 ) )
return;
F_198 ( V_25 -> V_345 , V_521 -> V_376 ,
V_521 -> V_377 , & V_522 ) ;
}
STATIC void
F_200 (
struct V_1 * log ,
struct V_176 * V_148 )
{
struct V_192 * V_25 = log -> V_7 ;
struct V_414 * V_416 ;
struct V_523 * V_417 ;
T_5 type ;
int V_189 ;
if ( V_25 -> V_338 == 0 )
return;
V_416 = V_148 -> V_157 [ 1 ] . V_158 ;
if ( V_416 == NULL )
return;
if ( V_148 -> V_157 [ 1 ] . V_212 < sizeof( struct V_414 ) )
return;
type = V_416 -> V_418 & ( V_339 | V_340 | V_341 ) ;
ASSERT ( type ) ;
if ( log -> V_342 & type )
return;
V_417 = V_148 -> V_157 [ 0 ] . V_158 ;
ASSERT ( V_417 ) ;
ASSERT ( V_417 -> V_420 == 1 ) ;
V_189 = F_156 ( V_25 , V_417 -> V_420 ) ;
if ( F_95 ( log , V_417 -> V_421 , V_189 , 0 ) )
return;
F_198 ( V_25 -> V_345 , V_417 -> V_421 , V_189 ,
& V_524 ) ;
}
STATIC void
F_201 (
struct V_1 * log ,
struct V_176 * V_148 )
{
switch ( F_79 ( V_148 ) ) {
case V_161 :
F_197 ( log , V_148 ) ;
break;
case V_165 :
F_199 ( log , V_148 ) ;
break;
case V_166 :
F_200 ( log , V_148 ) ;
break;
case V_169 :
case V_168 :
case V_167 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
default:
break;
}
}
STATIC int
F_202 (
struct V_1 * log ,
struct V_145 * V_146 ,
struct V_176 * V_148 )
{
F_203 ( log , V_146 , V_148 , V_525 ) ;
switch ( F_79 ( V_148 ) ) {
case V_161 :
return F_87 ( log , V_148 ) ;
case V_167 :
return F_153 ( log , V_148 ) ;
case V_165 :
case V_169 :
case V_168 :
case V_166 :
case V_159 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_79 ( V_148 ) ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
}
STATIC int
F_204 (
struct V_1 * log ,
struct V_145 * V_146 ,
struct V_177 * V_152 ,
struct V_176 * V_148 )
{
F_203 ( log , V_146 , V_148 , V_526 ) ;
switch ( F_79 ( V_148 ) ) {
case V_161 :
return F_121 ( log , V_152 , V_148 ,
V_146 -> V_527 ) ;
case V_165 :
return F_136 ( log , V_152 , V_148 ,
V_146 -> V_527 ) ;
case V_169 :
return F_158 ( log , V_148 , V_146 -> V_527 ) ;
case V_168 :
return F_166 ( log , V_148 ) ;
case V_170 :
return F_171 ( log , V_148 , V_146 -> V_527 ) ;
case V_171 :
return F_176 ( log , V_148 ) ;
case V_172 :
return F_179 ( log , V_148 , V_146 -> V_527 ) ;
case V_173 :
return F_183 ( log , V_148 ) ;
case V_174 :
return F_186 ( log , V_148 , V_146 -> V_527 ) ;
case V_175 :
return F_190 ( log , V_148 ) ;
case V_166 :
return F_154 ( log , V_152 , V_148 ,
V_146 -> V_527 ) ;
case V_159 :
return F_191 ( log , V_152 , V_148 ) ;
case V_167 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_79 ( V_148 ) ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
}
STATIC int
F_205 (
struct V_1 * log ,
struct V_145 * V_146 ,
struct V_177 * V_152 ,
struct V_177 * V_528 )
{
struct V_176 * V_148 ;
int error = 0 ;
F_90 (item, item_list, ri_list) {
error = F_204 ( log , V_146 ,
V_152 , V_148 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_206 (
struct V_1 * log ,
struct V_145 * V_146 ,
int V_147 ,
struct V_177 * V_152 )
{
int error = 0 ;
int V_529 = 0 ;
struct V_176 * V_148 ;
struct V_176 * V_333 ;
F_76 ( V_530 ) ;
F_76 ( V_531 ) ;
#define F_207 100
F_208 ( & V_146 -> V_532 ) ;
error = F_75 ( log , V_146 , V_147 ) ;
if ( error )
return error ;
F_78 (item, next, &trans->r_itemq, ri_list) {
switch ( V_147 ) {
case V_525 :
error = F_202 ( log , V_146 , V_148 ) ;
break;
case V_526 :
F_201 ( log , V_148 ) ;
F_80 ( & V_148 -> V_160 , & V_530 ) ;
V_529 ++ ;
if ( V_529 >= F_207 ) {
error = F_205 ( log , V_146 ,
V_152 , & V_530 ) ;
F_209 ( & V_530 , & V_531 ) ;
V_529 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_54;
}
V_54:
if ( ! F_84 ( & V_530 ) ) {
if ( ! error )
error = F_205 ( log , V_146 ,
V_152 , & V_530 ) ;
F_209 ( & V_530 , & V_531 ) ;
}
if ( ! F_84 ( & V_531 ) )
F_77 ( & V_531 , & V_146 -> V_155 ) ;
return error ;
}
STATIC void
F_210 (
struct V_177 * V_26 )
{
T_7 * V_148 ;
V_148 = F_211 ( sizeof( T_7 ) , V_186 ) ;
F_212 ( & V_148 -> V_160 ) ;
F_93 ( & V_148 -> V_160 , V_26 ) ;
}
STATIC int
F_213 (
struct V_1 * log ,
struct V_145 * V_146 ,
char * V_533 ,
int V_189 )
{
T_7 * V_148 ;
char * V_534 , * V_535 ;
int V_536 ;
if ( F_84 ( & V_146 -> V_155 ) ) {
ASSERT ( V_189 <= sizeof( struct V_537 ) ) ;
if ( V_189 > sizeof( struct V_537 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
return - V_61 ;
}
F_210 ( & V_146 -> V_155 ) ;
V_534 = ( char * ) & V_146 -> V_538 +
sizeof( struct V_537 ) - V_189 ;
memcpy ( V_534 , V_533 , V_189 ) ;
return 0 ;
}
V_148 = F_214 ( V_146 -> V_155 . V_539 , T_7 , V_160 ) ;
V_535 = V_148 -> V_157 [ V_148 -> V_540 - 1 ] . V_158 ;
V_536 = V_148 -> V_157 [ V_148 -> V_540 - 1 ] . V_212 ;
V_534 = F_215 ( V_535 , V_189 + V_536 , V_186 ) ;
memcpy ( & V_534 [ V_536 ] , V_533 , V_189 ) ;
V_148 -> V_157 [ V_148 -> V_540 - 1 ] . V_212 += V_189 ;
V_148 -> V_157 [ V_148 -> V_540 - 1 ] . V_158 = V_534 ;
F_216 ( log , V_146 , V_148 , 0 ) ;
return 0 ;
}
STATIC int
F_217 (
struct V_1 * log ,
struct V_145 * V_146 ,
char * V_533 ,
int V_189 )
{
T_12 * V_353 ;
T_7 * V_148 ;
char * V_534 ;
if ( ! V_189 )
return 0 ;
if ( F_84 ( & V_146 -> V_155 ) ) {
if ( * ( T_5 * ) V_533 != V_541 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
if ( V_189 > sizeof( struct V_537 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
if ( V_189 == sizeof( struct V_537 ) )
F_210 ( & V_146 -> V_155 ) ;
memcpy ( & V_146 -> V_538 , V_533 , V_189 ) ;
return 0 ;
}
V_534 = F_92 ( V_189 , V_186 ) ;
memcpy ( V_534 , V_533 , V_189 ) ;
V_353 = ( T_12 * ) V_534 ;
V_148 = F_214 ( V_146 -> V_155 . V_539 , T_7 , V_160 ) ;
if ( V_148 -> V_336 != 0 &&
V_148 -> V_336 == V_148 -> V_540 ) {
F_210 ( & V_146 -> V_155 ) ;
V_148 = F_214 ( V_146 -> V_155 . V_539 ,
T_7 , V_160 ) ;
}
if ( V_148 -> V_336 == 0 ) {
if ( V_353 -> V_399 == 0 ||
V_353 -> V_399 > V_542 ) {
F_3 ( log -> V_7 ,
L_81 ,
V_353 -> V_399 ) ;
ASSERT ( 0 ) ;
F_98 ( V_534 ) ;
return - V_61 ;
}
V_148 -> V_336 = V_353 -> V_399 ;
V_148 -> V_157 =
F_211 ( V_148 -> V_336 * sizeof( V_543 ) ,
V_186 ) ;
}
ASSERT ( V_148 -> V_336 > V_148 -> V_540 ) ;
V_148 -> V_157 [ V_148 -> V_540 ] . V_158 = V_534 ;
V_148 -> V_157 [ V_148 -> V_540 ] . V_212 = V_189 ;
V_148 -> V_540 ++ ;
F_218 ( log , V_146 , V_148 , 0 ) ;
return 0 ;
}
STATIC void
F_219 (
struct V_145 * V_146 )
{
T_7 * V_148 , * V_149 ;
int V_48 ;
F_208 ( & V_146 -> V_532 ) ;
F_78 (item, n, &trans->r_itemq, ri_list) {
F_97 ( & V_148 -> V_160 ) ;
for ( V_48 = 0 ; V_48 < V_148 -> V_540 ; V_48 ++ )
F_98 ( V_148 -> V_157 [ V_48 ] . V_158 ) ;
F_98 ( V_148 -> V_157 ) ;
F_98 ( V_148 ) ;
}
F_98 ( V_146 ) ;
}
STATIC int
F_220 (
struct V_1 * log ,
struct V_145 * V_146 ,
char * V_533 ,
unsigned int V_189 ,
unsigned int V_190 ,
int V_147 ,
struct V_177 * V_152 )
{
int error = 0 ;
bool V_544 = false ;
V_190 &= ~ V_545 ;
if ( V_190 & V_546 )
V_190 &= ~ V_547 ;
switch ( V_190 ) {
case 0 :
case V_547 :
error = F_217 ( log , V_146 , V_533 , V_189 ) ;
break;
case V_546 :
error = F_213 ( log , V_146 , V_533 , V_189 ) ;
break;
case V_548 :
error = F_206 ( log , V_146 , V_147 ,
V_152 ) ;
V_544 = true ;
break;
case V_106 :
F_3 ( log -> V_7 , L_82 , V_8 ) ;
V_544 = true ;
break;
case V_549 :
default:
F_3 ( log -> V_7 , L_83 , V_8 , V_190 ) ;
ASSERT ( 0 ) ;
error = - V_61 ;
break;
}
if ( error || V_544 )
F_219 ( V_146 ) ;
return error ;
}
STATIC struct V_145 *
F_221 (
struct V_550 V_551 [] ,
struct V_78 * V_79 ,
struct V_97 * V_552 )
{
struct V_145 * V_146 ;
T_21 V_553 ;
struct V_550 * V_554 ;
V_553 = F_28 ( V_552 -> V_555 ) ;
V_554 = & V_551 [ F_222 ( V_553 ) ] ;
F_223 (trans, rhp, r_list) {
if ( V_146 -> V_556 == V_553 )
return V_146 ;
}
if ( ! ( V_552 -> V_105 & V_549 ) )
return NULL ;
ASSERT ( F_28 ( V_552 -> V_557 ) == 0 ) ;
V_146 = F_211 ( sizeof( struct V_145 ) , V_186 ) ;
V_146 -> V_556 = V_553 ;
V_146 -> V_527 = F_58 ( V_79 -> V_114 ) ;
F_212 ( & V_146 -> V_155 ) ;
F_224 ( & V_146 -> V_532 ) ;
F_225 ( & V_146 -> V_532 , V_554 ) ;
return NULL ;
}
STATIC int
F_226 (
struct V_1 * log ,
struct V_550 V_551 [] ,
struct V_78 * V_79 ,
struct V_97 * V_552 ,
char * V_533 ,
char * V_558 ,
int V_147 ,
struct V_177 * V_152 )
{
struct V_145 * V_146 ;
unsigned int V_189 ;
int error ;
if ( V_552 -> V_559 != V_560 &&
V_552 -> V_559 != V_561 ) {
F_3 ( log -> V_7 , L_84 ,
V_8 , V_552 -> V_559 ) ;
ASSERT ( 0 ) ;
return - V_61 ;
}
V_189 = F_28 ( V_552 -> V_557 ) ;
if ( V_533 + V_189 > V_558 ) {
F_3 ( log -> V_7 , L_85 , V_8 , V_189 ) ;
F_227 ( 1 ) ;
return - V_61 ;
}
V_146 = F_221 ( V_551 , V_79 , V_552 ) ;
if ( ! V_146 ) {
return 0 ;
}
if ( log -> V_562 != V_146 -> V_527 &&
V_552 -> V_105 & V_548 ) {
error = F_228 ( V_152 ) ;
if ( error )
return error ;
log -> V_562 = V_146 -> V_527 ;
}
return F_220 ( log , V_146 , V_533 , V_189 ,
V_552 -> V_105 , V_147 , V_152 ) ;
}
STATIC int
F_229 (
struct V_1 * log ,
struct V_550 V_551 [] ,
struct V_78 * V_79 ,
char * V_533 ,
int V_147 ,
struct V_177 * V_152 )
{
struct V_97 * V_552 ;
char * V_558 ;
int V_563 ;
int error ;
V_558 = V_533 + F_28 ( V_79 -> V_64 ) ;
V_563 = F_28 ( V_79 -> V_104 ) ;
if ( F_29 ( log -> V_7 , V_79 ) )
return - V_61 ;
F_230 ( log , V_79 , V_147 ) ;
while ( ( V_533 < V_558 ) && V_563 ) {
V_552 = (struct V_97 * ) V_533 ;
V_533 += sizeof( * V_552 ) ;
ASSERT ( V_533 <= V_558 ) ;
error = F_226 ( log , V_551 , V_79 , V_552 ,
V_533 , V_558 , V_147 , V_152 ) ;
if ( error )
return error ;
V_533 += F_28 ( V_552 -> V_557 ) ;
V_563 -- ;
}
return 0 ;
}
STATIC int
F_231 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_428 * V_429 ;
int error ;
V_429 = F_232 ( V_439 , struct V_428 , V_437 ) ;
if ( F_233 ( V_564 , & V_429 -> V_565 ) )
return 0 ;
F_168 ( & V_444 -> V_436 ) ;
error = F_234 ( V_25 , V_429 ) ;
F_163 ( & V_444 -> V_436 ) ;
return error ;
}
STATIC void
F_235 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_428 * V_429 ;
V_429 = F_232 ( V_439 , struct V_428 , V_437 ) ;
F_168 ( & V_444 -> V_436 ) ;
F_165 ( V_429 ) ;
F_163 ( & V_444 -> V_436 ) ;
}
STATIC int
F_236 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_452 * V_453 ;
int error ;
V_453 = F_232 ( V_439 , struct V_452 , V_459 ) ;
if ( F_233 ( V_566 , & V_453 -> V_567 ) )
return 0 ;
F_168 ( & V_444 -> V_436 ) ;
error = F_237 ( V_25 , V_453 ) ;
F_163 ( & V_444 -> V_436 ) ;
return error ;
}
STATIC void
F_238 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_452 * V_453 ;
V_453 = F_232 ( V_439 , struct V_452 , V_459 ) ;
F_168 ( & V_444 -> V_436 ) ;
F_175 ( V_453 ) ;
F_163 ( & V_444 -> V_436 ) ;
}
STATIC int
F_239 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_470 * V_471 ;
int error ;
V_471 = F_232 ( V_439 , struct V_470 , V_475 ) ;
if ( F_233 ( V_568 , & V_471 -> V_569 ) )
return 0 ;
F_168 ( & V_444 -> V_436 ) ;
error = F_240 ( V_25 , V_471 ) ;
F_163 ( & V_444 -> V_436 ) ;
return error ;
}
STATIC void
F_241 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_470 * V_471 ;
V_471 = F_232 ( V_439 , struct V_470 , V_475 ) ;
F_168 ( & V_444 -> V_436 ) ;
F_182 ( V_471 ) ;
F_163 ( & V_444 -> V_436 ) ;
}
STATIC int
F_242 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_484 * V_485 ;
int error ;
V_485 = F_232 ( V_439 , struct V_484 , V_490 ) ;
if ( F_233 ( V_570 , & V_485 -> V_571 ) )
return 0 ;
F_168 ( & V_444 -> V_436 ) ;
error = F_243 ( V_25 , V_485 ) ;
F_163 ( & V_444 -> V_436 ) ;
return error ;
}
STATIC void
F_244 (
struct V_192 * V_25 ,
struct V_443 * V_444 ,
struct V_462 * V_439 )
{
struct V_484 * V_485 ;
V_485 = F_232 ( V_439 , struct V_484 , V_490 ) ;
F_168 ( & V_444 -> V_436 ) ;
F_189 ( V_485 ) ;
F_163 ( & V_444 -> V_436 ) ;
}
static inline bool F_245 ( struct V_462 * V_439 )
{
switch ( V_439 -> V_451 ) {
case V_169 :
case V_170 :
case V_172 :
case V_174 :
return true ;
default:
return false ;
}
}
STATIC int
F_246 (
struct V_1 * log )
{
struct V_462 * V_439 ;
int error = 0 ;
struct V_441 V_442 ;
struct V_443 * V_444 ;
T_6 V_572 ;
V_444 = log -> V_435 ;
F_163 ( & V_444 -> V_436 ) ;
V_439 = F_167 ( V_444 , & V_442 , 0 ) ;
V_572 = F_71 ( log -> V_108 , log -> V_112 ) ;
while ( V_439 != NULL ) {
if ( ! F_245 ( V_439 ) ) {
#ifdef F_247
for (; V_439 ; V_439 = F_169 ( V_444 , & V_442 ) )
ASSERT ( ! F_245 ( V_439 ) ) ;
#endif
break;
}
ASSERT ( F_125 ( V_572 , V_439 -> V_329 ) >= 0 ) ;
switch ( V_439 -> V_451 ) {
case V_169 :
error = F_231 ( log -> V_7 , V_444 , V_439 ) ;
break;
case V_170 :
error = F_236 ( log -> V_7 , V_444 , V_439 ) ;
break;
case V_172 :
error = F_239 ( log -> V_7 , V_444 , V_439 ) ;
break;
case V_174 :
error = F_242 ( log -> V_7 , V_444 , V_439 ) ;
break;
}
if ( error )
goto V_54;
V_439 = F_169 ( V_444 , & V_442 ) ;
}
V_54:
F_170 ( & V_442 ) ;
F_168 ( & V_444 -> V_436 ) ;
return error ;
}
STATIC int
F_248 (
struct V_1 * log )
{
struct V_462 * V_439 ;
int error = 0 ;
struct V_441 V_442 ;
struct V_443 * V_444 ;
V_444 = log -> V_435 ;
F_163 ( & V_444 -> V_436 ) ;
V_439 = F_167 ( V_444 , & V_442 , 0 ) ;
while ( V_439 != NULL ) {
if ( ! F_245 ( V_439 ) ) {
#ifdef F_247
for (; V_439 ; V_439 = F_169 ( V_444 , & V_442 ) )
ASSERT ( ! F_245 ( V_439 ) ) ;
#endif
break;
}
switch ( V_439 -> V_451 ) {
case V_169 :
F_235 ( log -> V_7 , V_444 , V_439 ) ;
break;
case V_170 :
F_238 ( log -> V_7 , V_444 , V_439 ) ;
break;
case V_172 :
F_241 ( log -> V_7 , V_444 , V_439 ) ;
break;
case V_174 :
F_244 ( log -> V_7 , V_444 , V_439 ) ;
break;
}
V_439 = F_169 ( V_444 , & V_442 ) ;
}
F_170 ( & V_442 ) ;
F_168 ( & V_444 -> V_436 ) ;
return error ;
}
STATIC void
F_249 (
T_3 * V_25 ,
T_19 V_497 ,
int V_178 )
{
T_22 * V_573 ;
T_23 * V_574 ;
T_1 * V_575 ;
int V_13 ;
int error ;
error = F_250 ( V_25 , & F_251 ( V_25 ) -> V_576 , 0 , 0 , 0 , & V_573 ) ;
if ( error )
goto V_82;
error = F_252 ( V_25 , V_573 , V_497 , & V_575 ) ;
if ( error )
goto V_577;
V_574 = F_253 ( V_575 ) ;
V_574 -> V_578 [ V_178 ] = F_30 ( V_579 ) ;
V_13 = F_102 ( T_23 , V_578 ) +
( sizeof( T_9 ) * V_178 ) ;
F_254 ( V_573 , V_575 , V_13 ,
( V_13 + sizeof( T_9 ) - 1 ) ) ;
error = F_255 ( V_573 ) ;
if ( error )
goto V_82;
return;
V_577:
F_256 ( V_573 ) ;
V_82:
F_3 ( V_25 , L_86 , V_8 , V_497 ) ;
return;
}
STATIC T_9
F_257 (
struct V_192 * V_25 ,
T_19 V_497 ,
T_9 V_580 ,
int V_178 )
{
struct V_5 * V_581 ;
struct V_350 * V_351 ;
struct V_354 * V_355 ;
T_24 V_582 ;
int error ;
V_582 = F_258 ( V_25 , V_497 , V_580 ) ;
error = F_259 ( V_25 , NULL , V_582 , 0 , 0 , & V_355 ) ;
if ( error )
goto V_583;
error = F_260 ( V_25 , NULL , & V_355 -> V_584 , & V_351 , & V_581 , 0 , 0 ) ;
if ( error )
goto V_585;
F_261 ( V_355 , V_586 ) ;
ASSERT ( F_262 ( V_355 ) -> V_587 == 0 ) ;
ASSERT ( F_262 ( V_355 ) -> V_588 != 0 ) ;
V_580 = F_28 ( V_351 -> V_208 ) ;
F_25 ( V_581 ) ;
V_355 -> V_360 . V_589 = 0 ;
F_263 ( V_355 ) ;
return V_580 ;
V_585:
F_263 ( V_355 ) ;
V_583:
F_249 ( V_25 , V_497 , V_178 ) ;
return V_579 ;
}
STATIC void
F_264 (
struct V_1 * log )
{
T_3 * V_25 ;
T_19 V_497 ;
T_23 * V_574 ;
T_1 * V_575 ;
T_9 V_580 ;
int V_178 ;
int error ;
T_5 V_590 ;
V_25 = log -> V_7 ;
V_590 = V_25 -> V_591 ;
V_25 -> V_591 = 0 ;
for ( V_497 = 0 ; V_497 < V_25 -> V_27 . V_507 ; V_497 ++ ) {
error = F_252 ( V_25 , NULL , V_497 , & V_575 ) ;
if ( error ) {
continue;
}
V_574 = F_253 ( V_575 ) ;
F_7 ( V_575 ) ;
for ( V_178 = 0 ; V_178 < V_592 ; V_178 ++ ) {
V_580 = F_28 ( V_574 -> V_578 [ V_178 ] ) ;
while ( V_580 != V_579 ) {
V_580 = F_257 ( V_25 ,
V_497 , V_580 , V_178 ) ;
}
}
F_265 ( V_575 ) ;
}
V_25 -> V_591 = V_590 ;
}
STATIC int
F_266 (
struct V_78 * V_79 ,
char * V_533 ,
struct V_1 * log )
{
int V_48 , V_49 , V_593 ;
for ( V_48 = 0 ; V_48 < F_47 ( F_28 ( V_79 -> V_64 ) ) &&
V_48 < ( V_63 / V_55 ) ; V_48 ++ ) {
* ( V_83 * ) V_533 = * ( V_83 * ) & V_79 -> V_594 [ V_48 ] ;
V_533 += V_55 ;
}
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
T_25 * V_595 = ( T_25 * ) V_79 ;
for ( ; V_48 < F_47 ( F_28 ( V_79 -> V_64 ) ) ; V_48 ++ ) {
V_49 = V_48 / ( V_63 / V_55 ) ;
V_593 = V_48 % ( V_63 / V_55 ) ;
* ( V_83 * ) V_533 = V_595 [ V_49 ] . V_596 . V_597 [ V_593 ] ;
V_533 += V_55 ;
}
}
return 0 ;
}
STATIC int
F_267 (
struct V_1 * log ,
struct V_550 V_551 [] ,
struct V_78 * V_79 ,
char * V_533 ,
int V_147 ,
struct V_177 * V_152 )
{
int error ;
T_26 V_598 = V_79 -> V_599 ;
T_26 V_600 ;
V_600 = F_268 ( log , V_79 , V_533 , F_28 ( V_79 -> V_64 ) ) ;
if ( V_147 == V_88 ) {
if ( V_598 && V_600 != V_598 )
return - V_94 ;
return 0 ;
}
if ( V_600 != V_598 ) {
if ( V_598 || F_101 ( & log -> V_7 -> V_27 ) ) {
F_105 ( log -> V_7 ,
L_87 ,
F_269 ( V_598 ) ,
F_269 ( V_600 ) ) ;
F_270 ( V_533 , 32 ) ;
}
if ( F_101 ( & log -> V_7 -> V_27 ) )
return - V_16 ;
}
error = F_266 ( V_79 , V_533 , log ) ;
if ( error )
return error ;
return F_229 ( log , V_551 , V_79 , V_533 , V_147 ,
V_152 ) ;
}
STATIC int
F_271 (
struct V_1 * log ,
struct V_78 * V_79 ,
T_2 V_188 )
{
int V_601 ;
if ( F_31 ( V_79 -> V_32 != F_30 ( V_33 ) ) ) {
F_4 ( L_88 ,
V_144 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 (
( ! V_79 -> V_102 ||
( F_28 ( V_79 -> V_102 ) & ( ~ V_602 ) ) ) ) ) {
F_3 ( log -> V_7 , L_89 ,
V_8 , F_28 ( V_79 -> V_102 ) ) ;
return - V_61 ;
}
V_601 = F_28 ( V_79 -> V_64 ) ;
if ( F_31 ( V_601 <= 0 || V_601 > V_73 ) ) {
F_4 ( L_90 ,
V_144 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_31 ( V_188 > log -> V_3 || V_188 > V_73 ) ) {
F_4 ( L_91 ,
V_144 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_55 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 ,
int V_147 ,
T_2 * V_85 )
{
T_4 * V_79 ;
T_2 V_12 ;
T_2 V_89 ;
char * V_13 ;
T_1 * V_603 , * V_604 ;
int error = 0 , V_62 , V_64 ;
int V_24 = 0 ;
int V_605 , V_606 ;
int V_101 , V_607 , V_608 ;
int V_48 ;
struct V_550 V_551 [ V_609 ] ;
F_76 ( V_152 ) ;
ASSERT ( V_66 != V_75 ) ;
V_89 = 0 ;
for ( V_48 = 0 ; V_48 < V_609 ; V_48 ++ )
F_272 ( & V_551 [ V_48 ] ) ;
if ( F_46 ( & log -> V_7 -> V_27 ) ) {
V_603 = F_2 ( log , 1 ) ;
if ( ! V_603 )
return - V_52 ;
error = F_18 ( log , V_75 , 1 , V_603 , & V_13 ) ;
if ( error )
goto V_610;
V_79 = ( T_4 * ) V_13 ;
error = F_271 ( log , V_79 , V_75 ) ;
if ( error )
goto V_610;
V_62 = F_28 ( V_79 -> V_62 ) ;
V_64 = F_28 ( V_79 -> V_64 ) ;
if ( V_64 > V_62 ) {
if ( V_64 <= log -> V_7 -> V_611 &&
F_28 ( V_79 -> V_104 ) == 1 ) {
F_3 ( log -> V_7 ,
L_92 ,
V_62 , log -> V_7 -> V_611 ) ;
V_62 = log -> V_7 -> V_611 ;
} else
return - V_16 ;
}
if ( ( F_28 ( V_79 -> V_102 ) & V_103 ) &&
( V_62 > V_63 ) ) {
V_101 = V_62 / V_63 ;
if ( V_62 % V_63 )
V_101 ++ ;
F_8 ( V_603 ) ;
V_603 = F_2 ( log , V_101 ) ;
} else {
V_101 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_101 = 1 ;
V_603 = F_2 ( log , 1 ) ;
V_62 = V_612 ;
}
if ( ! V_603 )
return - V_52 ;
V_604 = F_2 ( log , F_47 ( V_62 ) ) ;
if ( ! V_604 ) {
F_8 ( V_603 ) ;
return - V_52 ;
}
memset ( V_551 , 0 , sizeof( V_551 ) ) ;
V_12 = V_89 = V_75 ;
if ( V_75 > V_66 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_603 -> V_15 ;
V_607 = 0 ;
V_608 = 0 ;
if ( V_12 + V_101 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_101 , V_603 ,
& V_13 ) ;
if ( error )
goto V_613;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_73 ) ;
V_607 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_607 > 0 ) ;
error = F_18 ( log , V_12 ,
V_607 , V_603 ,
& V_13 ) ;
if ( error )
goto V_613;
}
V_608 = V_101 - V_607 ;
error = F_19 ( log , 0 ,
V_608 , V_603 ,
V_13 + F_11 ( V_607 ) ) ;
if ( error )
goto V_613;
}
V_79 = ( T_4 * ) V_13 ;
error = F_271 ( log , V_79 ,
V_607 ? V_12 : 0 ) ;
if ( error )
goto V_613;
V_605 = ( int ) F_47 ( F_28 ( V_79 -> V_64 ) ) ;
V_12 += V_101 ;
if ( V_12 + V_605 <= log -> V_3 ) {
error = F_18 ( log , V_12 , V_605 , V_604 ,
& V_13 ) ;
if ( error )
goto V_613;
} else {
V_13 = V_604 -> V_15 ;
V_606 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_608 ) ;
ASSERT ( V_12 <= V_73 ) ;
V_606 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_606 > 0 ) ;
error = F_18 ( log , V_12 ,
V_606 , V_604 ,
& V_13 ) ;
if ( error )
goto V_613;
}
error = F_19 ( log , 0 ,
V_605 - V_606 , V_604 ,
V_13 + F_11 ( V_606 ) ) ;
if ( error )
goto V_613;
}
error = F_267 ( log , V_551 , V_79 , V_13 ,
V_147 , & V_152 ) ;
if ( error )
goto V_613;
V_12 += V_605 ;
V_89 = V_12 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
V_89 = V_12 ;
}
while ( V_12 < V_66 ) {
error = F_18 ( log , V_12 , V_101 , V_603 , & V_13 ) ;
if ( error )
goto V_613;
V_79 = ( T_4 * ) V_13 ;
error = F_271 ( log , V_79 , V_12 ) ;
if ( error )
goto V_613;
V_605 = ( int ) F_47 ( F_28 ( V_79 -> V_64 ) ) ;
error = F_18 ( log , V_12 + V_101 , V_605 , V_604 ,
& V_13 ) ;
if ( error )
goto V_613;
error = F_267 ( log , V_551 , V_79 , V_13 , V_147 ,
& V_152 ) ;
if ( error )
goto V_613;
V_12 += V_605 + V_101 ;
V_89 = V_12 ;
}
V_613:
F_8 ( V_604 ) ;
V_610:
F_8 ( V_603 ) ;
if ( ! F_84 ( & V_152 ) )
V_24 = F_228 ( & V_152 ) ;
if ( error && V_85 )
* V_85 = V_89 ;
for ( V_48 = 0 ; V_48 < V_609 ; V_48 ++ ) {
struct V_614 * V_615 ;
struct V_145 * V_146 ;
F_273 (trans, tmp, &rhash[i], r_list)
F_219 ( V_146 ) ;
}
return error ? error : V_24 ;
}
STATIC int
F_274 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 )
{
int error , V_48 ;
ASSERT ( V_66 != V_75 ) ;
log -> V_191 = F_211 ( V_616 *
sizeof( struct V_177 ) ,
V_186 ) ;
for ( V_48 = 0 ; V_48 < V_616 ; V_48 ++ )
F_212 ( & log -> V_191 [ V_48 ] ) ;
error = F_55 ( log , V_66 , V_75 ,
V_525 , NULL ) ;
if ( error != 0 ) {
F_98 ( log -> V_191 ) ;
log -> V_191 = NULL ;
return error ;
}
error = F_55 ( log , V_66 , V_75 ,
V_526 , NULL ) ;
#ifdef F_247
if ( ! error ) {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_616 ; V_48 ++ )
ASSERT ( F_84 ( & log -> V_191 [ V_48 ] ) ) ;
}
#endif
F_98 ( log -> V_191 ) ;
log -> V_191 = NULL ;
return error ;
}
STATIC int
F_275 (
struct V_1 * log ,
T_2 V_66 ,
T_2 V_75 )
{
struct V_192 * V_25 = log -> V_7 ;
int error ;
T_1 * V_6 ;
T_27 * V_617 ;
error = F_274 ( log , V_66 , V_75 ) ;
if ( error )
return error ;
if ( F_16 ( V_25 ) ) {
return - V_61 ;
}
F_276 ( V_25 ) ;
V_6 = F_277 ( V_25 , 0 ) ;
V_6 -> V_18 &= ~ ( V_618 | V_619 ) ;
ASSERT ( ! ( V_6 -> V_18 & V_620 ) ) ;
V_6 -> V_18 |= V_19 ;
V_6 -> V_203 = & V_321 ;
error = F_15 ( V_6 ) ;
if ( error ) {
if ( ! F_16 ( V_25 ) ) {
F_17 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_25 ( V_6 ) ;
return error ;
}
V_617 = & V_25 -> V_27 ;
F_278 ( V_617 , F_279 ( V_6 ) ) ;
F_25 ( V_6 ) ;
F_280 ( V_25 ) ;
error = F_281 ( V_25 , V_617 -> V_507 , & V_25 -> V_621 ) ;
if ( error ) {
F_3 ( V_25 , L_93 , error ) ;
return error ;
}
V_25 -> V_622 = F_282 ( V_25 ) ;
F_283 ( log ) ;
log -> V_623 &= ~ V_624 ;
return 0 ;
}
int
V_145 (
struct V_1 * log )
{
T_2 V_66 , V_75 ;
int error ;
error = F_65 ( log , & V_66 , & V_75 ) ;
if ( error )
return error ;
if ( F_101 ( & log -> V_7 -> V_27 ) &&
! F_284 ( log -> V_7 , log -> V_7 -> V_27 . V_261 ) )
return - V_125 ;
if ( V_75 != V_66 ) {
if ( ( error = F_285 ( log -> V_7 , L_94 ) ) ) {
return error ;
}
if ( F_286 ( & log -> V_7 -> V_27 ) == V_625 &&
F_287 ( & log -> V_7 -> V_27 ,
V_626 ) ) {
F_3 ( log -> V_7 ,
L_95 ,
( log -> V_7 -> V_27 . V_627 &
V_626 ) ) ;
F_3 ( log -> V_7 ,
L_96 ) ;
F_3 ( log -> V_7 ,
L_97 ) ;
return - V_125 ;
}
if ( V_628 . V_629 ) {
F_288 ( log -> V_7 ,
L_98 ,
V_628 . V_629 ) ;
F_289 ( V_628 . V_629 * 1000 ) ;
}
F_288 ( log -> V_7 , L_99 ,
log -> V_7 -> V_630 ? log -> V_7 -> V_630
: L_100 ) ;
error = F_275 ( log , V_66 , V_75 ) ;
log -> V_623 |= V_631 ;
}
return error ;
}
int
F_290 (
struct V_1 * log )
{
if ( log -> V_623 & V_631 ) {
int error ;
error = F_246 ( log ) ;
if ( error ) {
F_105 ( log -> V_7 , L_101 ) ;
return error ;
}
F_291 ( log -> V_7 , V_632 ) ;
F_264 ( log ) ;
F_283 ( log ) ;
F_288 ( log -> V_7 , L_102 ,
log -> V_7 -> V_630 ? log -> V_7 -> V_630
: L_100 ) ;
log -> V_623 &= ~ V_631 ;
} else {
F_292 ( log -> V_7 , L_103 ) ;
}
return 0 ;
}
int
F_293 (
struct V_1 * log )
{
int error = 0 ;
if ( log -> V_623 & V_631 )
error = F_248 ( log ) ;
return error ;
}
void
F_283 (
struct V_1 * log )
{
T_3 * V_25 ;
T_28 * V_633 ;
T_1 * V_634 ;
T_1 * V_575 ;
T_19 V_497 ;
T_18 V_635 ;
T_18 V_636 ;
T_18 V_637 ;
int error ;
V_25 = log -> V_7 ;
V_635 = 0LL ;
V_636 = 0LL ;
V_637 = 0LL ;
for ( V_497 = 0 ; V_497 < V_25 -> V_27 . V_507 ; V_497 ++ ) {
error = F_294 ( V_25 , NULL , V_497 , 0 , & V_634 ) ;
if ( error ) {
F_105 ( V_25 , L_104 ,
V_8 , V_497 , error ) ;
} else {
V_633 = F_295 ( V_634 ) ;
V_635 += F_28 ( V_633 -> V_638 ) +
F_28 ( V_633 -> V_639 ) ;
F_25 ( V_634 ) ;
}
error = F_252 ( V_25 , NULL , V_497 , & V_575 ) ;
if ( error ) {
F_105 ( V_25 , L_105 ,
V_8 , V_497 , error ) ;
} else {
struct V_247 * V_574 = F_253 ( V_575 ) ;
V_636 += F_28 ( V_574 -> V_640 ) ;
V_637 += F_28 ( V_574 -> V_641 ) ;
F_25 ( V_575 ) ;
}
}
}
