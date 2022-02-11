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
F_15 ( V_6 ) ;
V_6 -> V_18 = V_4 ;
V_6 -> V_19 = 0 ;
error = F_16 ( V_6 ) ;
if ( error && ! F_17 ( log -> V_7 ) )
F_18 ( V_6 , V_8 ) ;
return error ;
}
STATIC int
F_19 (
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
F_20 (
struct V_1 * log ,
T_2 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
char * V_13 )
{
char * V_20 = V_6 -> V_15 ;
int V_21 = F_11 ( V_6 -> V_14 ) ;
int error , V_22 ;
error = F_21 ( V_6 , V_13 , F_11 ( V_4 ) ) ;
if ( error )
return error ;
error = F_12 ( log , V_12 , V_4 , V_6 ) ;
V_22 = F_21 ( V_6 , V_20 , V_21 ) ;
if ( error )
return error ;
return V_22 ;
}
STATIC int
F_22 (
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
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
V_6 -> V_18 = V_4 ;
V_6 -> V_19 = 0 ;
error = F_26 ( V_6 ) ;
if ( error )
F_18 ( V_6 , V_8 ) ;
F_27 ( V_6 ) ;
return error ;
}
STATIC void
F_28 (
T_3 * V_23 ,
T_4 * V_24 )
{
F_29 ( V_23 , L_2 ,
V_8 , & V_23 -> V_25 . V_26 , V_27 ) ;
F_29 ( V_23 , L_3 ,
& V_24 -> V_28 , F_30 ( V_24 -> V_29 ) ) ;
}
STATIC int
F_31 (
T_3 * V_23 ,
T_4 * V_24 )
{
ASSERT ( V_24 -> V_30 == F_32 ( V_31 ) ) ;
if ( F_33 ( V_24 -> V_29 != F_32 ( V_27 ) ) ) {
F_3 ( V_23 ,
L_4 ) ;
F_28 ( V_23 , V_24 ) ;
F_4 ( L_5 ,
V_9 , V_23 ) ;
return - V_16 ;
} else if ( F_33 ( ! F_34 ( & V_23 -> V_25 . V_26 , & V_24 -> V_28 ) ) ) {
F_3 ( V_23 ,
L_6 ) ;
F_28 ( V_23 , V_24 ) ;
F_4 ( L_7 ,
V_9 , V_23 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_35 (
T_3 * V_23 ,
T_4 * V_24 )
{
ASSERT ( V_24 -> V_30 == F_32 ( V_31 ) ) ;
if ( F_36 ( & V_24 -> V_28 ) ) {
F_3 ( V_23 , L_8 ) ;
} else if ( F_33 ( ! F_34 ( & V_23 -> V_25 . V_26 , & V_24 -> V_28 ) ) ) {
F_3 ( V_23 , L_9 ) ;
F_28 ( V_23 , V_24 ) ;
F_4 ( L_10 ,
V_9 , V_23 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC void
F_37 (
struct V_5 * V_6 )
{
if ( V_6 -> V_19 ) {
if ( ! F_17 ( V_6 -> V_32 -> V_33 ) ) {
F_18 ( V_6 , V_8 ) ;
F_38 ( V_6 -> V_32 -> V_33 ,
V_34 ) ;
}
}
V_6 -> V_35 = NULL ;
F_39 ( V_6 ) ;
}
STATIC int
F_40 (
struct V_1 * log ,
struct V_5 * V_6 ,
T_2 V_36 ,
T_2 * V_37 ,
T_5 V_38 )
{
char * V_13 ;
T_2 V_39 ;
T_2 V_40 ;
T_5 V_41 ;
int error ;
V_40 = * V_37 ;
V_39 = F_41 ( V_36 , V_40 ) ;
while ( V_39 != V_36 && V_39 != V_40 ) {
error = F_19 ( log , V_39 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_41 = F_42 ( V_13 ) ;
if ( V_41 == V_38 )
V_40 = V_39 ;
else
V_36 = V_39 ;
V_39 = F_41 ( V_36 , V_40 ) ;
}
ASSERT ( ( V_39 == V_36 && V_39 + 1 == V_40 ) ||
( V_39 == V_40 && V_39 - 1 == V_36 ) ) ;
* V_37 = V_40 ;
return 0 ;
}
STATIC int
F_43 (
struct V_1 * log ,
T_2 V_42 ,
int V_4 ,
T_5 V_43 ,
T_2 * V_44 )
{
T_2 V_45 , V_46 ;
T_5 V_38 ;
T_1 * V_6 ;
T_2 V_47 ;
char * V_48 = NULL ;
int error = 0 ;
V_47 = 1 << F_44 ( V_4 ) ;
while ( V_47 > log -> V_3 )
V_47 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_47 ) ) ) {
V_47 >>= 1 ;
if ( V_47 < log -> V_10 )
return - V_49 ;
}
for ( V_45 = V_42 ; V_45 < V_42 + V_4 ; V_45 += V_47 ) {
int V_50 ;
V_50 = F_45 ( V_47 , ( V_42 + V_4 - V_45 ) ) ;
error = F_19 ( log , V_45 , V_50 , V_6 , & V_48 ) ;
if ( error )
goto V_51;
for ( V_46 = 0 ; V_46 < V_50 ; V_46 ++ ) {
V_38 = F_42 ( V_48 ) ;
if ( V_38 == V_43 ) {
* V_44 = V_45 + V_46 ;
goto V_51;
}
V_48 += V_52 ;
}
}
* V_44 = - 1 ;
V_51:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_46 (
struct V_1 * log ,
T_2 V_42 ,
T_2 * V_37 ,
int V_53 )
{
T_2 V_45 ;
T_1 * V_6 ;
char * V_13 = NULL ;
T_4 * V_24 = NULL ;
int error = 0 ;
int V_54 = 0 ;
int V_55 = * V_37 - V_42 ;
int V_56 ;
ASSERT ( V_42 != 0 || * V_37 != V_42 ) ;
if ( ! ( V_6 = F_2 ( log , V_55 ) ) ) {
if ( ! ( V_6 = F_2 ( log , 1 ) ) )
return - V_49 ;
V_54 = 1 ;
} else {
error = F_19 ( log , V_42 , V_55 , V_6 , & V_13 ) ;
if ( error )
goto V_51;
V_13 += ( ( V_55 - 1 ) << V_57 ) ;
}
for ( V_45 = ( * V_37 ) - 1 ; V_45 >= 0 ; V_45 -- ) {
if ( V_45 < V_42 ) {
F_3 ( log -> V_7 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
goto V_51;
}
if ( V_54 ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_51;
}
V_24 = ( T_4 * ) V_13 ;
if ( V_24 -> V_30 == F_32 ( V_31 ) )
break;
if ( ! V_54 )
V_13 -= V_52 ;
}
if ( V_45 == - 1 ) {
error = 1 ;
goto V_51;
}
if ( ( error = F_35 ( log -> V_7 , V_24 ) ) )
goto V_51;
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
T_5 V_59 = F_30 ( V_24 -> V_59 ) ;
V_56 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_56 ++ ;
} else {
V_56 = 1 ;
}
if ( * V_37 - V_45 + V_53 !=
F_48 ( F_30 ( V_24 -> V_61 ) ) + V_56 )
* V_37 = V_45 ;
V_51:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_49 (
struct V_1 * log ,
T_2 * V_62 )
{
T_1 * V_6 ;
char * V_13 ;
T_2 V_44 , V_36 , V_42 , V_37 , V_63 ;
int V_64 ;
T_5 V_65 , V_66 ;
T_5 V_67 ;
int error , V_68 = log -> V_3 ;
error = F_50 ( log , & V_36 ) ;
if ( error < 0 ) {
F_3 ( log -> V_7 , L_12 ) ;
return error ;
}
if ( error == 1 ) {
* V_62 = V_36 ;
if ( ! V_36 ) {
F_3 ( log -> V_7 , L_13 ) ;
}
return 0 ;
}
V_36 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_49 ;
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_65 = F_42 ( V_13 ) ;
V_37 = V_63 = V_68 - 1 ;
error = F_19 ( log , V_37 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_66 = F_42 ( V_13 ) ;
ASSERT ( V_66 != 0 ) ;
if ( V_65 == V_66 ) {
V_63 = V_68 ;
V_67 = V_66 - 1 ;
} else {
V_67 = V_66 ;
if ( ( error = F_40 ( log , V_6 , V_36 ,
& V_63 , V_66 ) ) )
goto V_69;
}
V_64 = F_51 ( log ) ;
if ( V_63 >= V_64 ) {
V_42 = V_63 - V_64 ;
if ( ( error = F_43 ( log ,
V_42 , V_64 ,
V_67 , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 )
V_63 = V_44 ;
} else {
ASSERT ( V_63 <= V_70 &&
( T_2 ) V_64 >= V_63 ) ;
V_42 = V_68 - ( V_64 - V_63 ) ;
if ( ( error = F_43 ( log , V_42 ,
V_64 - ( int ) V_63 ,
( V_67 - 1 ) , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 ) {
V_63 = V_44 ;
goto V_71;
}
V_42 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_43 ( log ,
V_42 , ( int ) V_63 ,
V_67 , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 )
V_63 = V_44 ;
}
V_71:
V_64 = F_52 ( log ) ;
if ( V_63 >= V_64 ) {
V_42 = V_63 - V_64 ;
error = F_46 ( log , V_42 , & V_63 , 0 ) ;
if ( error == 1 )
error = - V_58 ;
if ( error )
goto V_69;
} else {
V_42 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
error = F_46 ( log , V_42 , & V_63 , 0 ) ;
if ( error < 0 )
goto V_69;
if ( error == 1 ) {
V_42 = V_68 - ( V_64 - V_63 ) ;
V_44 = V_68 ;
ASSERT ( V_42 <= V_70 &&
( T_2 ) V_68 - V_42 >= 0 ) ;
ASSERT ( V_63 <= V_70 ) ;
error = F_46 ( log , V_42 ,
& V_44 , ( int ) V_63 ) ;
if ( error == 1 )
error = - V_58 ;
if ( error )
goto V_69;
if ( V_44 != V_68 )
V_63 = V_44 ;
} else if ( error )
goto V_69;
}
F_8 ( V_6 ) ;
if ( V_63 == V_68 )
* V_62 = 0 ;
else
* V_62 = V_63 ;
return 0 ;
V_69:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_14 ) ;
return error ;
}
STATIC int
F_53 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 ,
int V_73 ,
struct V_5 * V_6 ,
T_2 * V_74 ,
struct V_75 * * V_76 ,
bool * V_77 )
{
int V_45 ;
int error ;
int V_78 = 0 ;
char * V_13 = NULL ;
T_2 V_40 ;
* V_77 = false ;
V_40 = V_63 > V_72 ? V_72 : 0 ;
for ( V_45 = ( int ) V_63 - 1 ; V_45 >= V_40 ; V_45 -- ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_79;
if ( * ( V_80 * ) V_13 == F_32 ( V_31 ) ) {
* V_74 = V_45 ;
* V_76 = (struct V_75 * ) V_13 ;
if ( ++ V_78 == V_73 )
break;
}
}
if ( V_72 >= V_63 && V_78 != V_73 ) {
for ( V_45 = log -> V_3 - 1 ; V_45 >= ( int ) V_72 ; V_45 -- ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_79;
if ( * ( V_80 * ) V_13 ==
F_32 ( V_31 ) ) {
* V_77 = true ;
* V_74 = V_45 ;
* V_76 = (struct V_75 * ) V_13 ;
if ( ++ V_78 == V_73 )
break;
}
}
}
return V_78 ;
V_79:
return error ;
}
STATIC int
F_54 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 ,
int V_73 ,
struct V_5 * V_6 ,
T_2 * V_74 ,
struct V_75 * * V_76 ,
bool * V_77 )
{
int V_45 ;
int error ;
int V_78 = 0 ;
char * V_13 = NULL ;
T_2 V_40 ;
* V_77 = false ;
V_40 = V_63 > V_72 ? V_63 : log -> V_3 - 1 ;
for ( V_45 = ( int ) V_72 ; V_45 <= V_40 ; V_45 ++ ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_79;
if ( * ( V_80 * ) V_13 == F_32 ( V_31 ) ) {
* V_74 = V_45 ;
* V_76 = (struct V_75 * ) V_13 ;
if ( ++ V_78 == V_73 )
break;
}
}
if ( V_72 > V_63 && V_78 != V_73 ) {
for ( V_45 = 0 ; V_45 < ( int ) V_63 ; V_45 ++ ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_79;
if ( * ( V_80 * ) V_13 ==
F_32 ( V_31 ) ) {
* V_77 = true ;
* V_74 = V_45 ;
* V_76 = (struct V_75 * ) V_13 ;
if ( ++ V_78 == V_73 )
break;
}
}
}
return V_78 ;
V_79:
return error ;
}
STATIC int
F_55 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 )
{
struct V_75 * V_81 ;
struct V_5 * V_6 ;
T_2 V_82 ;
int V_73 ;
int error = 0 ;
bool V_77 ;
T_2 V_83 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_49 ;
V_73 = F_54 ( log , V_63 , V_72 ,
V_84 + 1 , V_6 , & V_83 , & V_81 ,
& V_77 ) ;
if ( V_73 < 0 ) {
error = V_73 ;
goto V_51;
}
if ( V_73 < V_84 + 1 )
V_83 = V_63 ;
error = F_56 ( log , V_83 , V_72 ,
V_85 , & V_82 ) ;
V_51:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_57 (
struct V_1 * log ,
T_2 * V_63 ,
T_2 * V_72 ,
struct V_5 * V_6 ,
T_2 * V_86 ,
struct V_75 * * V_76 ,
bool * V_77 )
{
struct V_75 * V_87 ;
struct V_5 * V_88 ;
T_2 V_82 ;
T_2 V_89 ;
int V_78 ;
int error ;
bool V_90 ;
V_88 = F_2 ( log , 1 ) ;
if ( ! V_88 )
return - V_49 ;
error = F_53 ( log , * V_63 , * V_72 ,
V_84 , V_88 , & V_89 ,
& V_87 , & V_90 ) ;
F_8 ( V_88 ) ;
if ( error < 0 )
return error ;
error = F_56 ( log , * V_63 , V_89 ,
V_85 , & V_82 ) ;
if ( error == - V_91 ) {
error = 0 ;
F_3 ( log -> V_7 ,
L_15 ,
V_82 , * V_63 ) ;
V_78 = F_53 ( log , V_82 , * V_72 , 1 , V_6 ,
V_86 , V_76 , V_77 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( V_78 == 0 )
return - V_58 ;
* V_63 = V_82 ;
* V_72 = F_58 ( F_59 ( ( * V_76 ) -> V_92 ) ) ;
if ( * V_63 == * V_72 ) {
ASSERT ( 0 ) ;
return 0 ;
}
error = F_55 ( log , * V_63 , * V_72 ) ;
}
return error ;
}
static int
F_60 (
struct V_1 * log ,
T_2 * V_63 ,
T_2 * V_72 ,
struct V_75 * V_76 ,
T_2 V_86 ,
struct V_5 * V_6 ,
bool * V_93 )
{
struct V_94 * V_95 ;
T_2 V_96 ;
T_2 V_97 ;
int V_98 ;
int error ;
char * V_13 ;
* V_93 = false ;
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
int V_59 = F_30 ( V_76 -> V_59 ) ;
int V_99 = F_30 ( V_76 -> V_99 ) ;
if ( ( V_99 & V_100 ) &&
( V_59 > V_60 ) ) {
V_98 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_98 ++ ;
} else {
V_98 = 1 ;
}
} else {
V_98 = 1 ;
}
V_97 = V_86 + V_98 + F_48 ( F_30 ( V_76 -> V_61 ) ) ;
V_97 = F_61 ( V_97 , log -> V_3 ) ;
if ( * V_63 == V_97 &&
F_30 ( V_76 -> V_101 ) == 1 ) {
V_96 = V_86 + V_98 ;
V_96 = F_61 ( V_96 , log -> V_3 ) ;
error = F_19 ( log , V_96 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_95 = (struct V_94 * ) V_13 ;
if ( V_95 -> V_102 & V_103 ) {
F_62 ( & log -> V_104 ,
log -> V_105 , V_97 ) ;
F_62 ( & log -> V_106 ,
log -> V_105 , V_97 ) ;
* V_72 = V_97 ;
* V_93 = true ;
}
}
return 0 ;
}
static void
F_63 (
struct V_1 * log ,
T_2 V_63 ,
struct V_75 * V_76 ,
T_2 V_86 ,
bool V_107 )
{
log -> V_108 = V_86 ;
log -> V_109 = ( int ) V_63 ;
log -> V_105 = F_30 ( V_76 -> V_110 ) ;
if ( V_107 )
log -> V_105 ++ ;
F_64 ( & log -> V_104 , F_59 ( V_76 -> V_92 ) ) ;
F_64 ( & log -> V_106 , F_59 ( V_76 -> V_111 ) ) ;
F_65 ( & log -> V_112 . V_113 , log -> V_105 ,
F_11 ( log -> V_109 ) ) ;
F_65 ( & log -> V_114 . V_113 , log -> V_105 ,
F_11 ( log -> V_109 ) ) ;
}
STATIC int
F_66 (
struct V_1 * log ,
T_2 * V_63 ,
T_2 * V_72 )
{
T_4 * V_76 ;
char * V_13 = NULL ;
T_1 * V_6 ;
int error ;
T_2 V_86 ;
T_6 V_115 ;
bool V_77 = false ;
bool V_93 = false ;
if ( ( error = F_49 ( log , V_63 ) ) )
return error ;
ASSERT ( * V_63 < V_70 ) ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_49 ;
if ( * V_63 == 0 ) {
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_116;
if ( F_42 ( V_13 ) == 0 ) {
* V_72 = 0 ;
goto V_116;
}
}
error = F_53 ( log , * V_63 , * V_63 , 1 , V_6 ,
& V_86 , & V_76 , & V_77 ) ;
if ( error < 0 )
return error ;
if ( ! error ) {
F_3 ( log -> V_7 , L_16 , V_8 ) ;
return - V_58 ;
}
* V_72 = F_58 ( F_59 ( V_76 -> V_92 ) ) ;
F_63 ( log , * V_63 , V_76 , V_86 , V_77 ) ;
V_115 = F_67 ( & log -> V_104 ) ;
error = F_60 ( log , V_63 , V_72 , V_76 ,
V_86 , V_6 , & V_93 ) ;
if ( error )
goto V_116;
if ( ! V_93 ) {
T_2 V_117 = * V_63 ;
error = F_57 ( log , V_63 , V_72 , V_6 ,
& V_86 , & V_76 , & V_77 ) ;
if ( error )
goto V_116;
if ( * V_63 != V_117 ) {
F_63 ( log , * V_63 , V_76 , V_86 ,
V_77 ) ;
V_115 = F_67 ( & log -> V_104 ) ;
error = F_60 ( log , V_63 , V_72 ,
V_76 , V_86 , V_6 ,
& V_93 ) ;
if ( error )
goto V_116;
}
}
if ( V_93 )
log -> V_7 -> V_118 |= V_119 ;
if ( ! F_68 ( log -> V_7 -> V_11 ) )
error = F_69 ( log , V_115 ) ;
V_116:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_17 ) ;
return error ;
}
STATIC int
F_50 (
struct V_1 * log ,
T_2 * V_12 )
{
T_1 * V_6 ;
char * V_13 ;
T_5 V_120 , V_121 ;
T_2 V_44 , V_37 , V_42 ;
T_2 V_64 ;
int error , V_68 = log -> V_3 ;
* V_12 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_49 ;
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_120 = F_42 ( V_13 ) ;
if ( V_120 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return 1 ;
}
error = F_19 ( log , V_68 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_121 = F_42 ( V_13 ) ;
if ( V_121 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_120 != 1 ) {
F_3 ( log -> V_7 ,
L_18 ) ;
error = - V_122 ;
goto V_69;
}
V_37 = V_68 - 1 ;
if ( ( error = F_40 ( log , V_6 , 0 , & V_37 , 0 ) ) )
goto V_69;
V_64 = F_51 ( log ) ;
ASSERT ( V_64 <= V_70 ) ;
if ( V_37 < V_64 )
V_64 = V_37 ;
V_42 = V_37 - V_64 ;
if ( ( error = F_43 ( log , V_42 ,
( int ) V_64 , 0 , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 )
V_37 = V_44 ;
error = F_46 ( log , V_42 , & V_37 , 0 ) ;
if ( error == 1 )
error = - V_58 ;
if ( error )
goto V_69;
* V_12 = V_37 ;
V_69:
F_8 ( V_6 ) ;
if ( error )
return error ;
return 1 ;
}
STATIC void
F_70 (
struct V_1 * log ,
char * V_48 ,
int V_38 ,
int V_123 ,
int V_124 ,
int V_125 )
{
T_4 * V_126 = ( T_4 * ) V_48 ;
memset ( V_48 , 0 , V_52 ) ;
V_126 -> V_30 = F_32 ( V_31 ) ;
V_126 -> V_110 = F_32 ( V_38 ) ;
V_126 -> V_99 = F_32 (
F_47 ( & log -> V_7 -> V_25 ) ? 2 : 1 ) ;
V_126 -> V_111 = F_71 ( F_72 ( V_38 , V_123 ) ) ;
V_126 -> V_92 = F_71 ( F_72 ( V_124 , V_125 ) ) ;
V_126 -> V_29 = F_32 ( V_27 ) ;
memcpy ( & V_126 -> V_28 , & log -> V_7 -> V_25 . V_26 , sizeof( V_127 ) ) ;
}
STATIC int
F_73 (
struct V_1 * log ,
int V_38 ,
int V_128 ,
int V_129 ,
int V_124 ,
int V_125 )
{
char * V_13 ;
T_1 * V_6 ;
int V_130 , V_131 ;
int V_132 = log -> V_10 ;
int V_133 = V_128 + V_129 ;
int V_47 ;
int error = 0 ;
int V_45 , V_46 = 0 ;
V_47 = 1 << F_44 ( V_129 ) ;
while ( V_47 > log -> V_3 )
V_47 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_47 ) ) ) {
V_47 >>= 1 ;
if ( V_47 < V_132 )
return - V_49 ;
}
V_130 = F_13 ( V_128 , V_132 ) ;
if ( V_130 != V_128 ) {
error = F_12 ( log , V_128 , 1 , V_6 ) ;
if ( error )
goto V_134;
V_46 = V_128 - V_130 ;
}
for ( V_45 = V_128 ; V_45 < V_133 ; V_45 += V_47 ) {
int V_50 , V_135 ;
V_50 = F_45 ( V_47 , V_133 - V_128 ) ;
V_135 = V_50 - V_46 ;
V_131 = F_13 ( V_133 , V_132 ) ;
if ( V_46 == 0 && ( V_128 + V_135 > V_131 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_131 - V_128 ) ;
error = F_20 ( log , V_131 , V_132 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_128 , V_135 , V_6 ) ;
for (; V_46 < V_135 ; V_46 ++ ) {
F_70 ( log , V_13 , V_38 , V_45 + V_46 ,
V_124 , V_125 ) ;
V_13 += V_52 ;
}
error = F_22 ( log , V_128 , V_135 , V_6 ) ;
if ( error )
break;
V_128 += V_135 ;
V_46 = 0 ;
}
V_134:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_69 (
struct V_1 * log ,
T_6 V_115 )
{
int V_124 , V_136 ;
int V_125 , V_137 ;
int V_138 , V_139 ;
int V_140 ;
int error ;
V_124 = F_74 ( V_115 ) ;
V_125 = F_58 ( V_115 ) ;
V_136 = log -> V_105 ;
V_137 = log -> V_109 ;
if ( V_136 == V_124 ) {
if ( F_33 ( V_137 < V_125 || V_137 >= log -> V_3 ) ) {
F_4 ( L_19 ,
V_141 , log -> V_7 ) ;
return - V_16 ;
}
V_138 = V_125 + ( log -> V_3 - V_137 ) ;
} else {
if ( F_33 ( V_137 >= V_125 || V_136 != ( V_124 + 1 ) ) ) {
F_4 ( L_20 ,
V_141 , log -> V_7 ) ;
return - V_16 ;
}
V_138 = V_125 - V_137 ;
}
if ( V_138 <= 0 ) {
ASSERT ( V_138 == 0 ) ;
return 0 ;
}
V_139 = F_51 ( log ) ;
V_139 = F_75 ( V_139 , V_138 ) ;
if ( ( V_137 + V_139 ) <= log -> V_3 ) {
error = F_73 ( log , ( V_136 - 1 ) ,
V_137 , V_139 , V_124 ,
V_125 ) ;
if ( error )
return error ;
} else {
V_140 = log -> V_3 - V_137 ;
error = F_73 ( log , ( V_136 - 1 ) ,
V_137 , V_140 , V_124 ,
V_125 ) ;
if ( error )
return error ;
V_140 = V_139 - ( log -> V_3 - V_137 ) ;
error = F_73 ( log , V_136 , 0 , V_140 ,
V_124 , V_125 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_76 (
struct V_1 * log ,
struct V_142 * V_143 ,
int V_144 )
{
T_7 * V_145 , * V_146 ;
int error = 0 ;
F_77 ( V_147 ) ;
F_77 ( V_148 ) ;
F_77 ( V_149 ) ;
F_77 ( V_150 ) ;
F_77 ( V_151 ) ;
F_78 ( & V_143 -> V_152 , & V_147 ) ;
F_79 (item, n, &sort_list, ri_list) {
T_8 * V_153 = V_145 -> V_154 [ 0 ] . V_155 ;
switch ( F_80 ( V_145 ) ) {
case V_156 :
F_81 ( & V_145 -> V_157 , & V_149 ) ;
break;
case V_158 :
if ( V_153 -> V_159 & V_160 ) {
F_82 ( log ,
V_143 , V_145 , V_144 ) ;
F_83 ( & V_145 -> V_157 , & V_148 ) ;
break;
}
if ( V_153 -> V_159 & V_161 ) {
F_83 ( & V_145 -> V_157 , & V_150 ) ;
break;
}
F_81 ( & V_145 -> V_157 , & V_149 ) ;
break;
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
F_84 ( log ,
V_143 , V_145 , V_144 ) ;
F_81 ( & V_145 -> V_157 , & V_151 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_21 ,
V_8 ) ;
ASSERT ( 0 ) ;
if ( ! F_85 ( & V_147 ) )
F_78 ( & V_147 , & V_143 -> V_152 ) ;
error = - V_58 ;
goto V_51;
}
}
V_51:
ASSERT ( F_85 ( & V_147 ) ) ;
if ( ! F_85 ( & V_149 ) )
F_86 ( & V_149 , & V_143 -> V_152 ) ;
if ( ! F_85 ( & V_151 ) )
F_87 ( & V_151 , & V_143 -> V_152 ) ;
if ( ! F_85 ( & V_150 ) )
F_87 ( & V_150 , & V_143 -> V_152 ) ;
if ( ! F_85 ( & V_148 ) )
F_87 ( & V_148 , & V_143 -> V_152 ) ;
return error ;
}
STATIC int
F_88 (
struct V_1 * log ,
struct V_167 * V_145 )
{
T_8 * V_153 = V_145 -> V_154 [ 0 ] . V_155 ;
struct V_168 * V_169 ;
struct V_170 * V_171 ;
if ( ! ( V_153 -> V_159 & V_160 ) ) {
F_89 ( log , V_153 ) ;
return 0 ;
}
V_169 = F_90 ( log , V_153 -> V_172 ) ;
F_91 (bcp, bucket, bc_list) {
if ( V_171 -> V_173 == V_153 -> V_172 &&
V_171 -> V_174 == V_153 -> V_175 ) {
V_171 -> V_176 ++ ;
F_92 ( log , V_153 ) ;
return 0 ;
}
}
V_171 = F_93 ( sizeof( struct V_170 ) , V_177 ) ;
V_171 -> V_173 = V_153 -> V_172 ;
V_171 -> V_174 = V_153 -> V_175 ;
V_171 -> V_176 = 1 ;
F_94 ( & V_171 -> V_178 , V_169 ) ;
F_95 ( log , V_153 ) ;
return 0 ;
}
STATIC struct V_170 *
F_96 (
struct V_1 * log ,
T_2 V_179 ,
T_5 V_180 ,
T_9 V_181 )
{
struct V_168 * V_169 ;
struct V_170 * V_171 ;
if ( ! log -> V_182 ) {
ASSERT ( ! ( V_181 & V_160 ) ) ;
return NULL ;
}
V_169 = F_90 ( log , V_179 ) ;
F_91 (bcp, bucket, bc_list) {
if ( V_171 -> V_173 == V_179 && V_171 -> V_174 == V_180 )
return V_171 ;
}
ASSERT ( ! ( V_181 & V_160 ) ) ;
return NULL ;
}
STATIC int
F_97 (
struct V_1 * log ,
T_2 V_179 ,
T_5 V_180 ,
T_9 V_181 )
{
struct V_170 * V_171 ;
V_171 = F_96 ( log , V_179 , V_180 , V_181 ) ;
if ( ! V_171 )
return 0 ;
if ( V_181 & V_160 ) {
if ( -- V_171 -> V_176 == 0 ) {
F_98 ( & V_171 -> V_178 ) ;
F_99 ( V_171 ) ;
}
}
return 1 ;
}
STATIC int
F_100 (
struct V_183 * V_23 ,
T_7 * V_145 ,
struct V_5 * V_6 ,
T_8 * V_153 )
{
int V_45 ;
int V_184 = 0 ;
int V_185 = 0 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_189 ;
int V_190 ;
T_10 * V_191 ;
T_10 * V_192 ;
F_101 ( V_23 -> V_193 , V_153 ) ;
if ( F_102 ( & V_23 -> V_25 ) )
V_6 -> V_194 = & V_195 ;
V_190 = F_11 ( V_6 -> V_18 ) >> V_23 -> V_25 . V_196 ;
for ( V_45 = 0 ; V_45 < V_190 ; V_45 ++ ) {
V_189 = ( V_45 * V_23 -> V_25 . V_197 ) +
F_103 ( V_198 , V_199 ) ;
while ( V_189 >=
( V_187 + V_188 ) ) {
V_185 += V_186 ;
V_185 = F_104 ( V_153 -> V_200 ,
V_153 -> V_201 , V_185 ) ;
if ( V_185 == - 1 )
return 0 ;
V_186 = F_105 ( V_153 -> V_200 ,
V_153 -> V_201 , V_185 ) ;
ASSERT ( V_186 > 0 ) ;
V_187 = V_185 << V_202 ;
V_188 = V_186 << V_202 ;
V_184 ++ ;
}
if ( V_189 < V_187 )
continue;
ASSERT ( V_145 -> V_154 [ V_184 ] . V_155 != NULL ) ;
ASSERT ( ( V_145 -> V_154 [ V_184 ] . V_203 % V_204 ) == 0 ) ;
ASSERT ( ( V_187 + V_188 ) <=
F_11 ( V_6 -> V_18 ) ) ;
V_191 = V_145 -> V_154 [ V_184 ] . V_155 +
V_189 - V_187 ;
if ( F_33 ( * V_191 == 0 ) ) {
F_106 ( V_23 ,
L_22
L_23 ,
V_145 , V_6 ) ;
F_4 ( L_24 ,
V_141 , V_23 ) ;
return - V_16 ;
}
V_192 = F_107 ( V_6 , V_189 ) ;
* V_192 = * V_191 ;
F_108 ( V_23 ,
F_107 ( V_6 , V_45 * V_23 -> V_25 . V_197 ) ) ;
}
return 0 ;
}
static T_6
F_109 (
struct V_183 * V_23 ,
struct V_5 * V_6 )
{
T_11 V_205 ;
T_12 V_206 ;
T_12 V_207 ;
void * V_208 = V_6 -> V_15 ;
V_127 * V_209 ;
T_6 V_210 = - 1 ;
if ( ! F_102 ( & V_23 -> V_25 ) )
goto V_211;
V_205 = F_30 ( * ( V_80 * ) V_208 ) ;
switch ( V_205 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 : {
struct V_218 * V_219 = V_208 ;
V_210 = F_59 ( V_219 -> V_220 . V_221 . V_222 ) ;
V_209 = & V_219 -> V_220 . V_221 . V_223 ;
break;
}
case V_224 :
case V_225 : {
struct V_218 * V_219 = V_208 ;
V_210 = F_59 ( V_219 -> V_220 . V_226 . V_222 ) ;
V_209 = & V_219 -> V_220 . V_226 . V_223 ;
break;
}
case V_227 :
V_210 = F_59 ( ( (struct V_228 * ) V_208 ) -> V_229 ) ;
V_209 = & ( (struct V_228 * ) V_208 ) -> V_230 ;
break;
case V_231 :
V_210 = F_59 ( ( (struct V_232 * ) V_208 ) -> V_233 ) ;
V_209 = & ( (struct V_232 * ) V_208 ) -> V_234 ;
break;
case V_235 :
V_210 = F_59 ( ( (struct V_236 * ) V_208 ) -> V_237 ) ;
V_209 = & ( (struct V_236 * ) V_208 ) -> V_238 ;
break;
case V_239 :
V_210 = F_59 ( ( (struct V_240 * ) V_208 ) -> V_241 ) ;
V_209 = & ( (struct V_240 * ) V_208 ) -> V_242 ;
break;
case V_243 :
case V_244 :
case V_245 :
V_210 = F_59 ( ( (struct V_246 * ) V_208 ) -> V_210 ) ;
V_209 = & ( (struct V_246 * ) V_208 ) -> V_209 ;
break;
case V_247 :
goto V_211;
case V_248 :
V_210 = F_59 ( ( (struct V_249 * ) V_208 ) -> V_250 ) ;
if ( F_110 ( & V_23 -> V_25 ) )
V_209 = & ( (struct V_249 * ) V_208 ) -> V_251 ;
else
V_209 = & ( (struct V_249 * ) V_208 ) -> V_26 ;
break;
default:
break;
}
if ( V_210 != ( T_6 ) - 1 ) {
if ( ! F_34 ( & V_23 -> V_25 . V_251 , V_209 ) )
goto V_211;
return V_210 ;
}
V_207 = F_111 ( ( (struct V_252 * ) V_208 ) -> V_253 ) ;
switch ( V_207 ) {
case V_254 :
case V_255 :
case V_256 :
V_210 = F_59 ( ( (struct V_257 * ) V_208 ) -> V_210 ) ;
V_209 = & ( (struct V_257 * ) V_208 ) -> V_209 ;
break;
default:
break;
}
if ( V_210 != ( T_6 ) - 1 ) {
if ( ! F_34 ( & V_23 -> V_25 . V_26 , V_209 ) )
goto V_211;
return V_210 ;
}
V_206 = F_111 ( * ( V_258 * ) V_208 ) ;
switch ( V_206 ) {
case V_259 :
case V_260 :
goto V_211;
default:
break;
}
V_211:
return ( T_6 ) - 1 ;
}
static void
F_112 (
struct V_183 * V_23 ,
struct V_5 * V_6 ,
T_8 * V_153 )
{
struct V_252 * V_261 = V_6 -> V_15 ;
T_11 V_205 ;
T_12 V_206 ;
T_12 V_207 ;
if ( ! F_102 ( & V_23 -> V_25 ) )
return;
V_205 = F_30 ( * ( V_80 * ) V_6 -> V_15 ) ;
V_206 = F_111 ( * ( V_258 * ) V_6 -> V_15 ) ;
V_207 = F_111 ( V_261 -> V_253 ) ;
switch ( F_113 ( V_153 ) ) {
case V_262 :
switch ( V_205 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
V_6 -> V_194 = & V_263 ;
break;
case V_216 :
case V_264 :
case V_217 :
case V_265 :
V_6 -> V_194 = & V_266 ;
break;
case V_224 :
case V_225 :
V_6 -> V_194 = & V_267 ;
break;
default:
F_3 ( V_23 , L_25 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_268 :
if ( V_205 != V_227 ) {
F_3 ( V_23 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_269 ;
break;
case V_270 :
if ( V_205 != V_231 ) {
F_3 ( V_23 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_271 ;
break;
case V_272 :
if ( V_205 != V_235 ) {
F_3 ( V_23 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_273 ;
break;
case V_274 :
case V_275 :
case V_276 :
#ifdef F_114
if ( V_206 != V_259 ) {
F_3 ( V_23 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_277 ;
#else
F_106 ( V_23 ,
L_30 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_278 :
if ( V_206 != V_260 ) {
F_3 ( V_23 , L_31 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_195 ;
break;
case V_279 :
if ( V_205 != V_239 ) {
F_3 ( V_23 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_280 ;
break;
case V_281 :
if ( V_205 != V_282 &&
V_205 != V_243 ) {
F_3 ( V_23 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_283 ;
break;
case V_284 :
if ( V_205 != V_285 &&
V_205 != V_244 ) {
F_3 ( V_23 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_286 ;
break;
case V_287 :
if ( V_205 != V_288 &&
V_205 != V_245 ) {
F_3 ( V_23 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_289 ;
break;
case V_290 :
if ( V_207 != V_291 &&
V_207 != V_254 ) {
F_3 ( V_23 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_292 ;
break;
case V_293 :
if ( V_207 != V_294 &&
V_207 != V_255 ) {
F_3 ( V_23 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_295 ;
break;
case V_296 :
if ( V_207 != V_297 &&
V_207 != V_256 ) {
F_3 ( V_23 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_298 ;
break;
case V_299 :
if ( V_207 != V_300 &&
V_207 != V_301 ) {
F_3 ( V_23 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_302 ;
break;
case V_303 :
if ( V_205 != V_247 ) {
F_3 ( V_23 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_304 ;
break;
case V_305 :
if ( V_205 != V_248 ) {
F_3 ( V_23 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_306 ;
break;
default:
F_3 ( V_23 , L_42 ,
F_113 ( V_153 ) ) ;
break;
}
}
STATIC void
F_115 (
struct V_183 * V_23 ,
T_7 * V_145 ,
struct V_5 * V_6 ,
T_8 * V_153 )
{
int V_45 ;
int V_185 ;
int V_186 ;
int error ;
F_116 ( V_23 -> V_193 , V_153 ) ;
V_185 = 0 ;
V_45 = 1 ;
while ( 1 ) {
V_185 = F_104 ( V_153 -> V_200 ,
V_153 -> V_201 , V_185 ) ;
if ( V_185 == - 1 )
break;
V_186 = F_105 ( V_153 -> V_200 ,
V_153 -> V_201 , V_185 ) ;
ASSERT ( V_186 > 0 ) ;
ASSERT ( V_145 -> V_154 [ V_45 ] . V_155 != NULL ) ;
ASSERT ( V_145 -> V_154 [ V_45 ] . V_203 % V_204 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_18 ) >=
( ( T_5 ) V_185 << V_202 ) + ( V_186 << V_202 ) ) ;
if ( V_145 -> V_154 [ V_45 ] . V_203 < ( V_186 << V_202 ) )
V_186 = V_145 -> V_154 [ V_45 ] . V_203 >> V_202 ;
error = 0 ;
if ( V_153 -> V_159 &
( V_307 | V_308 | V_309 ) ) {
if ( V_145 -> V_154 [ V_45 ] . V_155 == NULL ) {
F_106 ( V_23 ,
L_43 , V_8 ) ;
goto V_310;
}
if ( V_145 -> V_154 [ V_45 ] . V_203 < sizeof( V_311 ) ) {
F_106 ( V_23 ,
L_44 ,
V_145 -> V_154 [ V_45 ] . V_203 , V_8 ) ;
goto V_310;
}
error = F_117 ( V_23 , V_145 -> V_154 [ V_45 ] . V_155 ,
- 1 , 0 , V_312 ,
L_45 ) ;
if ( error )
goto V_310;
}
memcpy ( F_107 ( V_6 ,
( T_5 ) V_185 << V_202 ) ,
V_145 -> V_154 [ V_45 ] . V_155 ,
V_186 << V_202 ) ;
V_310:
V_45 ++ ;
V_185 += V_186 ;
}
ASSERT ( V_45 == V_145 -> V_313 ) ;
F_112 ( V_23 , V_6 , V_153 ) ;
}
STATIC bool
F_118 (
struct V_183 * V_23 ,
struct V_1 * log ,
struct V_167 * V_145 ,
struct V_5 * V_6 ,
struct V_314 * V_153 )
{
T_5 type ;
F_119 ( log , V_153 ) ;
if ( ! V_23 -> V_315 )
return false ;
type = 0 ;
if ( V_153 -> V_159 & V_307 )
type |= V_316 ;
if ( V_153 -> V_159 & V_308 )
type |= V_317 ;
if ( V_153 -> V_159 & V_309 )
type |= V_318 ;
if ( log -> V_319 & type )
return false ;
F_115 ( V_23 , V_145 , V_6 , V_153 ) ;
return true ;
}
STATIC int
F_120 (
struct V_1 * log ,
struct V_168 * V_149 ,
struct V_167 * V_145 ,
T_6 V_320 )
{
T_8 * V_153 = V_145 -> V_154 [ 0 ] . V_155 ;
T_3 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_5 V_321 ;
T_6 V_210 ;
if ( F_97 ( log , V_153 -> V_172 ,
V_153 -> V_175 , V_153 -> V_159 ) ) {
F_121 ( log , V_153 ) ;
return 0 ;
}
F_122 ( log , V_153 ) ;
V_321 = 0 ;
if ( V_153 -> V_159 & V_161 )
V_321 |= V_322 ;
V_6 = F_123 ( V_23 -> V_323 , V_153 -> V_172 , V_153 -> V_175 ,
V_321 , NULL ) ;
if ( ! V_6 )
return - V_49 ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_46 ) ;
goto V_324;
}
V_210 = F_109 ( V_23 , V_6 ) ;
if ( V_210 && V_210 != - 1 && F_124 ( V_210 , V_320 ) >= 0 ) {
F_112 ( V_23 , V_6 , V_153 ) ;
goto V_324;
}
if ( V_153 -> V_159 & V_161 ) {
error = F_100 ( V_23 , V_145 , V_6 , V_153 ) ;
if ( error )
goto V_324;
} else if ( V_153 -> V_159 &
( V_307 | V_308 | V_309 ) ) {
bool V_325 ;
V_325 = F_118 ( V_23 , log , V_145 , V_6 , V_153 ) ;
if ( ! V_325 )
goto V_324;
} else {
F_115 ( V_23 , V_145 , V_6 , V_153 ) ;
}
if ( V_260 ==
F_111 ( * ( ( V_258 * ) F_107 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_125 ( log -> V_7 -> V_25 . V_326 ,
( T_11 ) log -> V_7 -> V_327 ) ) ) {
F_126 ( V_6 ) ;
error = F_26 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_127 ( V_6 , V_149 ) ;
}
V_324:
F_27 ( V_6 ) ;
return error ;
}
STATIC int
F_128 (
struct V_183 * V_23 ,
struct V_328 * V_329 ,
struct V_330 * V_331 ,
struct V_168 * V_149 )
{
struct V_332 * V_333 ;
int error ;
ASSERT ( V_331 -> V_334 & ( V_335 | V_336 ) ) ;
V_333 = F_129 ( V_23 , V_331 -> V_337 ) ;
if ( ! V_333 )
return - V_49 ;
F_130 ( & V_333 -> V_338 , V_329 ) ;
ASSERT ( V_333 -> V_338 . V_339 >= 3 ) ;
error = F_131 ( V_333 , V_329 ) ;
if ( error )
goto V_340;
if ( V_331 -> V_334 & V_335 ) {
ASSERT ( V_331 -> V_334 & V_341 ) ;
error = F_132 ( NULL , V_333 , V_342 ,
V_333 -> V_343 , V_149 ) ;
if ( error )
goto V_340;
}
if ( V_331 -> V_334 & V_336 ) {
ASSERT ( V_331 -> V_334 & V_344 ) ;
error = F_132 ( NULL , V_333 , V_345 ,
V_333 -> V_343 , V_149 ) ;
if ( error )
goto V_340;
}
V_340:
F_133 ( V_333 ) ;
return error ;
}
STATIC int
F_134 (
struct V_1 * log ,
struct V_168 * V_149 ,
struct V_167 * V_145 ,
T_6 V_320 )
{
T_13 * V_331 ;
T_3 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_198 * V_329 ;
int V_180 ;
char * V_346 ;
char * V_347 ;
int error ;
int V_348 ;
T_5 V_349 ;
T_14 * V_350 ;
T_5 V_351 ;
int V_352 = 0 ;
if ( V_145 -> V_154 [ 0 ] . V_203 == sizeof( T_13 ) ) {
V_331 = V_145 -> V_154 [ 0 ] . V_155 ;
} else {
V_331 = F_93 ( sizeof( T_13 ) , V_177 ) ;
V_352 = 1 ;
error = F_135 ( & V_145 -> V_154 [ 0 ] , V_331 ) ;
if ( error )
goto error;
}
if ( F_97 ( log , V_331 -> V_353 ,
V_331 -> V_354 , 0 ) ) {
error = 0 ;
F_136 ( log , V_331 ) ;
goto error;
}
F_137 ( log , V_331 ) ;
V_6 = F_123 ( V_23 -> V_323 , V_331 -> V_353 , V_331 -> V_354 , 0 ,
& V_195 ) ;
if ( ! V_6 ) {
error = - V_49 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_47 ) ;
goto V_324;
}
ASSERT ( V_331 -> V_334 & V_355 ) ;
V_329 = F_107 ( V_6 , V_331 -> V_356 ) ;
if ( F_33 ( V_329 -> V_357 != F_138 ( V_260 ) ) ) {
F_106 ( V_23 ,
L_48 ,
V_8 , V_329 , V_6 , V_331 -> V_337 ) ;
F_4 ( L_49 ,
V_141 , V_23 ) ;
error = - V_16 ;
goto V_324;
}
V_350 = V_145 -> V_154 [ 1 ] . V_155 ;
if ( F_33 ( V_350 -> V_357 != V_260 ) ) {
F_106 ( V_23 ,
L_50 ,
V_8 , V_145 , V_331 -> V_337 ) ;
F_4 ( L_51 ,
V_141 , V_23 ) ;
error = - V_16 ;
goto V_324;
}
if ( V_329 -> V_339 >= 3 ) {
T_6 V_210 = F_59 ( V_329 -> V_358 ) ;
if ( V_210 && V_210 != - 1 && F_124 ( V_210 , V_320 ) >= 0 ) {
F_139 ( log , V_331 ) ;
error = 0 ;
goto V_359;
}
}
if ( ! F_102 ( & V_23 -> V_25 ) &&
V_350 -> V_360 < F_111 ( V_329 -> V_360 ) ) {
if ( F_111 ( V_329 -> V_360 ) == V_361 &&
V_350 -> V_360 < ( V_361 >> 1 ) ) {
} else {
F_139 ( log , V_331 ) ;
error = 0 ;
goto V_324;
}
}
V_350 -> V_360 = 0 ;
if ( F_33 ( F_140 ( V_350 -> V_362 ) ) ) {
if ( ( V_350 -> V_363 != V_364 ) &&
( V_350 -> V_363 != V_365 ) ) {
F_141 ( L_52 ,
V_141 , V_23 , V_350 ) ;
F_106 ( V_23 ,
L_53
L_54 ,
V_8 , V_145 , V_329 , V_6 , V_331 -> V_337 ) ;
error = - V_16 ;
goto V_324;
}
} else if ( F_33 ( F_142 ( V_350 -> V_362 ) ) ) {
if ( ( V_350 -> V_363 != V_364 ) &&
( V_350 -> V_363 != V_365 ) &&
( V_350 -> V_363 != V_366 ) ) {
F_141 ( L_55 ,
V_141 , V_23 , V_350 ) ;
F_106 ( V_23 ,
L_56
L_54 ,
V_8 , V_145 , V_329 , V_6 , V_331 -> V_337 ) ;
error = - V_16 ;
goto V_324;
}
}
if ( F_33 ( V_350 -> V_367 + V_350 -> V_368 > V_350 -> V_369 ) ) {
F_141 ( L_57 ,
V_141 , V_23 , V_350 ) ;
F_106 ( V_23 ,
L_58
L_59 ,
V_8 , V_145 , V_329 , V_6 , V_331 -> V_337 ,
V_350 -> V_367 + V_350 -> V_368 ,
V_350 -> V_369 ) ;
error = - V_16 ;
goto V_324;
}
if ( F_33 ( V_350 -> V_370 > V_23 -> V_25 . V_197 ) ) {
F_141 ( L_60 ,
V_141 , V_23 , V_350 ) ;
F_106 ( V_23 ,
L_58
L_61 , V_8 ,
V_145 , V_329 , V_6 , V_331 -> V_337 , V_350 -> V_370 ) ;
error = - V_16 ;
goto V_324;
}
V_351 = F_143 ( V_350 -> V_339 ) ;
if ( F_33 ( V_145 -> V_154 [ 1 ] . V_203 > V_351 ) ) {
F_141 ( L_62 ,
V_141 , V_23 , V_350 ) ;
F_106 ( V_23 ,
L_63 ,
V_8 , V_145 -> V_154 [ 1 ] . V_203 , V_145 ) ;
error = - V_16 ;
goto V_324;
}
F_144 ( V_329 , V_350 ) ;
if ( V_145 -> V_154 [ 1 ] . V_203 > V_351 ) {
memcpy ( ( char * ) V_329 + V_351 ,
V_145 -> V_154 [ 1 ] . V_155 + V_351 ,
V_145 -> V_154 [ 1 ] . V_203 - V_351 ) ;
}
V_349 = V_331 -> V_334 ;
switch ( V_349 & ( V_371 | V_372 ) ) {
case V_371 :
F_145 ( V_329 , V_331 -> V_373 . V_374 ) ;
break;
case V_372 :
memcpy ( F_146 ( V_329 ) ,
& V_331 -> V_373 . V_375 ,
sizeof( V_127 ) ) ;
break;
}
if ( V_331 -> V_376 == 2 )
goto V_359;
V_180 = V_145 -> V_154 [ 2 ] . V_203 ;
V_346 = V_145 -> V_154 [ 2 ] . V_155 ;
ASSERT ( V_331 -> V_376 <= 4 ) ;
ASSERT ( ( V_331 -> V_376 == 3 ) || ( V_349 & V_377 ) ) ;
ASSERT ( ! ( V_349 & V_378 ) ||
( V_180 == V_331 -> V_379 ) ) ;
switch ( V_349 & V_378 ) {
case V_380 :
case V_381 :
memcpy ( F_146 ( V_329 ) , V_346 , V_180 ) ;
break;
case V_341 :
F_147 ( V_23 , (struct V_218 * ) V_346 , V_180 ,
( V_382 * ) F_146 ( V_329 ) ,
F_148 ( V_329 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_349 & V_378 ) == 0 ) ;
break;
}
if ( V_331 -> V_334 & V_377 ) {
if ( V_331 -> V_334 & V_378 ) {
V_348 = 3 ;
} else {
V_348 = 2 ;
}
V_180 = V_145 -> V_154 [ V_348 ] . V_203 ;
V_346 = V_145 -> V_154 [ V_348 ] . V_155 ;
ASSERT ( V_180 == V_331 -> V_383 ) ;
switch ( V_331 -> V_334 & V_377 ) {
case V_384 :
case V_385 :
V_347 = F_149 ( V_329 ) ;
ASSERT ( V_180 <= F_150 ( V_329 , V_23 ) ) ;
memcpy ( V_347 , V_346 , V_180 ) ;
break;
case V_344 :
V_347 = F_149 ( V_329 ) ;
F_147 ( V_23 , (struct V_218 * ) V_346 ,
V_180 , ( V_382 * ) V_347 ,
F_150 ( V_329 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_64 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
goto V_324;
}
}
V_359:
if ( V_331 -> V_334 & ( V_335 | V_336 ) )
error = F_128 ( V_23 , V_329 , V_331 ,
V_149 ) ;
F_108 ( log -> V_7 , V_329 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_127 ( V_6 , V_149 ) ;
V_324:
F_27 ( V_6 ) ;
error:
if ( V_352 )
F_99 ( V_331 ) ;
return error ;
}
STATIC int
F_151 (
struct V_1 * log ,
struct V_167 * V_145 )
{
T_15 * V_386 = V_145 -> V_154 [ 0 ] . V_155 ;
ASSERT ( V_386 ) ;
if ( V_386 -> V_387 & V_388 )
log -> V_319 |= V_316 ;
if ( V_386 -> V_387 & V_389 )
log -> V_319 |= V_317 ;
if ( V_386 -> V_387 & V_390 )
log -> V_319 |= V_318 ;
return 0 ;
}
STATIC int
F_152 (
struct V_1 * log ,
struct V_168 * V_149 ,
struct V_167 * V_145 ,
T_6 V_320 )
{
T_3 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_391 * V_392 , * V_393 ;
int error ;
T_16 * V_394 ;
T_5 type ;
if ( V_23 -> V_315 == 0 )
return 0 ;
V_393 = V_145 -> V_154 [ 1 ] . V_155 ;
if ( V_393 == NULL ) {
F_106 ( log -> V_7 , L_65 , V_8 ) ;
return - V_58 ;
}
if ( V_145 -> V_154 [ 1 ] . V_203 < sizeof( V_311 ) ) {
F_106 ( log -> V_7 , L_66 ,
V_145 -> V_154 [ 1 ] . V_203 , V_8 ) ;
return - V_58 ;
}
type = V_393 -> V_395 & ( V_316 | V_317 | V_318 ) ;
ASSERT ( type ) ;
if ( log -> V_319 & type )
return 0 ;
V_394 = V_145 -> V_154 [ 0 ] . V_155 ;
ASSERT ( V_394 ) ;
error = F_117 ( V_23 , V_393 , V_394 -> V_396 , 0 , V_312 ,
L_67 ) ;
if ( error )
return - V_58 ;
ASSERT ( V_394 -> V_397 == 1 ) ;
error = F_153 ( V_23 , NULL , V_23 -> V_323 , V_394 -> V_398 ,
F_154 ( V_23 , V_394 -> V_397 ) , 0 , & V_6 ,
& V_277 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_392 = F_107 ( V_6 , V_394 -> V_399 ) ;
if ( F_102 ( & V_23 -> V_25 ) ) {
struct V_400 * V_401 = (struct V_400 * ) V_392 ;
T_6 V_210 = F_59 ( V_401 -> V_402 ) ;
if ( V_210 && V_210 != - 1 && F_124 ( V_210 , V_320 ) >= 0 ) {
goto V_324;
}
}
memcpy ( V_392 , V_393 , V_145 -> V_154 [ 1 ] . V_203 ) ;
if ( F_102 ( & V_23 -> V_25 ) ) {
F_155 ( ( char * ) V_392 , sizeof( struct V_400 ) ,
V_403 ) ;
}
ASSERT ( V_394 -> V_404 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_127 ( V_6 , V_149 ) ;
V_324:
F_27 ( V_6 ) ;
return 0 ;
}
STATIC int
F_156 (
struct V_1 * log ,
struct V_167 * V_145 ,
T_6 V_210 )
{
int error ;
struct V_183 * V_23 = log -> V_7 ;
struct V_405 * V_406 ;
struct V_407 * V_408 ;
V_408 = V_145 -> V_154 [ 0 ] . V_155 ;
V_406 = F_157 ( V_23 , V_408 -> V_409 ) ;
error = F_158 ( & V_145 -> V_154 [ 0 ] , & V_406 -> V_410 ) ;
if ( error ) {
F_159 ( V_406 ) ;
return error ;
}
F_160 ( & V_406 -> V_411 , V_408 -> V_409 ) ;
F_161 ( & log -> V_412 -> V_413 ) ;
F_162 ( log -> V_412 , & V_406 -> V_414 , V_210 ) ;
F_163 ( V_406 ) ;
return 0 ;
}
STATIC int
F_164 (
struct V_1 * log ,
struct V_167 * V_145 )
{
T_17 * V_415 ;
T_18 * V_406 = NULL ;
T_19 * V_416 ;
T_20 V_417 ;
struct V_418 V_419 ;
struct V_420 * V_421 = log -> V_412 ;
V_415 = V_145 -> V_154 [ 0 ] . V_155 ;
ASSERT ( ( V_145 -> V_154 [ 0 ] . V_203 == ( sizeof( V_422 ) +
( ( V_415 -> V_423 - 1 ) * sizeof( V_424 ) ) ) ) ||
( V_145 -> V_154 [ 0 ] . V_203 == ( sizeof( V_425 ) +
( ( V_415 -> V_423 - 1 ) * sizeof( V_426 ) ) ) ) ) ;
V_417 = V_415 -> V_427 ;
F_161 ( & V_421 -> V_413 ) ;
V_416 = F_165 ( V_421 , & V_419 , 0 ) ;
while ( V_416 != NULL ) {
if ( V_416 -> V_428 == V_166 ) {
V_406 = ( T_18 * ) V_416 ;
if ( V_406 -> V_410 . V_417 == V_417 ) {
F_166 ( & V_421 -> V_413 ) ;
F_163 ( V_406 ) ;
F_161 ( & V_421 -> V_413 ) ;
break;
}
}
V_416 = F_167 ( V_421 , & V_419 ) ;
}
F_168 ( & V_419 ) ;
F_166 ( & V_421 -> V_413 ) ;
return 0 ;
}
STATIC int
F_169 (
struct V_1 * log ,
struct V_168 * V_149 ,
T_7 * V_145 )
{
struct V_183 * V_23 = log -> V_7 ;
struct V_429 * V_430 ;
T_21 V_431 ;
T_22 V_432 ;
unsigned int V_73 ;
unsigned int V_351 ;
T_22 V_433 ;
int V_434 ;
int V_435 ;
int V_436 ;
int V_437 ;
int V_45 ;
V_430 = (struct V_429 * ) V_145 -> V_154 [ 0 ] . V_155 ;
if ( V_430 -> V_438 != V_156 ) {
F_3 ( log -> V_7 , L_68 ) ;
return - V_122 ;
}
if ( V_430 -> V_439 != 1 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_122 ;
}
V_431 = F_30 ( V_430 -> V_440 ) ;
if ( V_431 >= V_23 -> V_25 . V_441 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_122 ;
}
V_432 = F_30 ( V_430 -> V_442 ) ;
if ( ! V_432 || V_432 == V_443 || V_432 >= V_23 -> V_25 . V_444 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_122 ;
}
V_351 = F_30 ( V_430 -> V_445 ) ;
if ( V_351 != V_23 -> V_25 . V_197 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_122 ;
}
V_73 = F_30 ( V_430 -> V_446 ) ;
if ( ! V_73 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_122 ;
}
V_433 = F_30 ( V_430 -> V_447 ) ;
if ( ! V_433 || V_433 >= V_23 -> V_25 . V_444 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_122 ;
}
if ( V_433 != V_23 -> V_448 &&
V_433 != V_23 -> V_449 ) {
F_3 ( log -> V_7 ,
L_75 , V_450 ) ;
return - V_122 ;
}
if ( ( V_73 >> V_23 -> V_25 . V_451 ) != V_433 ) {
F_3 ( log -> V_7 ,
L_76 ,
V_450 ) ;
return - V_122 ;
}
V_434 = F_170 ( V_23 ) ;
V_435 = F_154 ( V_23 , V_434 ) ;
V_437 = V_433 / V_434 ;
for ( V_45 = 0 , V_436 = 0 ; V_45 < V_437 ; V_45 ++ ) {
T_2 V_452 ;
V_452 = F_171 ( V_23 , V_431 ,
V_432 + V_45 * V_434 ) ;
if ( F_97 ( log , V_452 , V_435 , 0 ) )
V_436 ++ ;
}
ASSERT ( ! V_436 || V_436 == V_437 ) ;
if ( V_436 ) {
if ( V_436 != V_437 )
F_3 ( V_23 ,
L_77 ) ;
F_172 ( log , V_430 ) ;
return 0 ;
}
F_173 ( log , V_430 ) ;
return F_174 ( V_23 , NULL , V_149 , V_73 , V_431 , V_432 ,
V_433 , F_30 ( V_430 -> V_453 ) ) ;
}
STATIC void
F_175 (
struct V_1 * log ,
struct V_167 * V_145 )
{
struct V_314 * V_153 = V_145 -> V_154 [ 0 ] . V_155 ;
struct V_183 * V_23 = log -> V_7 ;
if ( F_96 ( log , V_153 -> V_172 ,
V_153 -> V_175 , V_153 -> V_159 ) ) {
return;
}
F_176 ( V_23 -> V_323 , V_153 -> V_172 ,
V_153 -> V_175 , NULL ) ;
}
STATIC void
F_177 (
struct V_1 * log ,
struct V_167 * V_145 )
{
struct V_330 V_454 ;
struct V_330 * V_455 ;
struct V_183 * V_23 = log -> V_7 ;
int error ;
if ( V_145 -> V_154 [ 0 ] . V_203 == sizeof( struct V_330 ) ) {
V_455 = V_145 -> V_154 [ 0 ] . V_155 ;
} else {
V_455 = & V_454 ;
memset ( V_455 , 0 , sizeof( * V_455 ) ) ;
error = F_135 ( & V_145 -> V_154 [ 0 ] , V_455 ) ;
if ( error )
return;
}
if ( F_96 ( log , V_455 -> V_353 , V_455 -> V_354 , 0 ) )
return;
F_176 ( V_23 -> V_323 , V_455 -> V_353 ,
V_455 -> V_354 , & V_456 ) ;
}
STATIC void
F_178 (
struct V_1 * log ,
struct V_167 * V_145 )
{
struct V_183 * V_23 = log -> V_7 ;
struct V_391 * V_393 ;
struct V_457 * V_394 ;
T_5 type ;
int V_180 ;
if ( V_23 -> V_315 == 0 )
return;
V_393 = V_145 -> V_154 [ 1 ] . V_155 ;
if ( V_393 == NULL )
return;
if ( V_145 -> V_154 [ 1 ] . V_203 < sizeof( struct V_391 ) )
return;
type = V_393 -> V_395 & ( V_316 | V_317 | V_318 ) ;
ASSERT ( type ) ;
if ( log -> V_319 & type )
return;
V_394 = V_145 -> V_154 [ 0 ] . V_155 ;
ASSERT ( V_394 ) ;
ASSERT ( V_394 -> V_397 == 1 ) ;
V_180 = F_154 ( V_23 , V_394 -> V_397 ) ;
if ( F_96 ( log , V_394 -> V_398 , V_180 , 0 ) )
return;
F_176 ( V_23 -> V_323 , V_394 -> V_398 , V_180 ,
& V_458 ) ;
}
STATIC void
F_179 (
struct V_1 * log ,
struct V_167 * V_145 )
{
switch ( F_80 ( V_145 ) ) {
case V_158 :
F_175 ( log , V_145 ) ;
break;
case V_162 :
F_177 ( log , V_145 ) ;
break;
case V_163 :
F_178 ( log , V_145 ) ;
break;
case V_166 :
case V_165 :
case V_164 :
default:
break;
}
}
STATIC int
F_180 (
struct V_1 * log ,
struct V_142 * V_143 ,
struct V_167 * V_145 )
{
F_181 ( log , V_143 , V_145 , V_459 ) ;
switch ( F_80 ( V_145 ) ) {
case V_158 :
return F_88 ( log , V_145 ) ;
case V_164 :
return F_151 ( log , V_145 ) ;
case V_162 :
case V_166 :
case V_165 :
case V_163 :
case V_156 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_80 ( V_145 ) ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
}
STATIC int
F_182 (
struct V_1 * log ,
struct V_142 * V_143 ,
struct V_168 * V_149 ,
struct V_167 * V_145 )
{
F_181 ( log , V_143 , V_145 , V_460 ) ;
switch ( F_80 ( V_145 ) ) {
case V_158 :
return F_120 ( log , V_149 , V_145 ,
V_143 -> V_461 ) ;
case V_162 :
return F_134 ( log , V_149 , V_145 ,
V_143 -> V_461 ) ;
case V_166 :
return F_156 ( log , V_145 , V_143 -> V_461 ) ;
case V_165 :
return F_164 ( log , V_145 ) ;
case V_163 :
return F_152 ( log , V_149 , V_145 ,
V_143 -> V_461 ) ;
case V_156 :
return F_169 ( log , V_149 , V_145 ) ;
case V_164 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_80 ( V_145 ) ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
}
STATIC int
F_183 (
struct V_1 * log ,
struct V_142 * V_143 ,
struct V_168 * V_149 ,
struct V_168 * V_462 )
{
struct V_167 * V_145 ;
int error = 0 ;
F_91 (item, item_list, ri_list) {
error = F_182 ( log , V_143 ,
V_149 , V_145 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_184 (
struct V_1 * log ,
struct V_142 * V_143 ,
int V_144 )
{
int error = 0 ;
int V_22 ;
int V_463 = 0 ;
struct V_167 * V_145 ;
struct V_167 * V_310 ;
F_77 ( V_149 ) ;
F_77 ( V_464 ) ;
F_77 ( V_465 ) ;
#define F_185 100
F_186 ( & V_143 -> V_466 ) ;
error = F_76 ( log , V_143 , V_144 ) ;
if ( error )
return error ;
F_79 (item, next, &trans->r_itemq, ri_list) {
switch ( V_144 ) {
case V_459 :
error = F_180 ( log , V_143 , V_145 ) ;
break;
case V_460 :
F_179 ( log , V_145 ) ;
F_81 ( & V_145 -> V_157 , & V_464 ) ;
V_463 ++ ;
if ( V_463 >= F_185 ) {
error = F_183 ( log , V_143 ,
& V_149 , & V_464 ) ;
F_187 ( & V_464 , & V_465 ) ;
V_463 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
V_51:
if ( ! F_85 ( & V_464 ) ) {
if ( ! error )
error = F_183 ( log , V_143 ,
& V_149 , & V_464 ) ;
F_187 ( & V_464 , & V_465 ) ;
}
if ( ! F_85 ( & V_465 ) )
F_78 ( & V_465 , & V_143 -> V_152 ) ;
V_22 = F_188 ( & V_149 ) ;
return error ? error : V_22 ;
}
STATIC void
F_189 (
struct V_168 * V_24 )
{
T_7 * V_145 ;
V_145 = F_190 ( sizeof( T_7 ) , V_177 ) ;
F_191 ( & V_145 -> V_157 ) ;
F_94 ( & V_145 -> V_157 , V_24 ) ;
}
STATIC int
F_192 (
struct V_1 * log ,
struct V_142 * V_143 ,
char * V_467 ,
int V_180 )
{
T_7 * V_145 ;
char * V_468 , * V_469 ;
int V_470 ;
if ( F_85 ( & V_143 -> V_152 ) ) {
ASSERT ( V_180 <= sizeof( struct V_471 ) ) ;
if ( V_180 > sizeof( struct V_471 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
return - V_58 ;
}
F_189 ( & V_143 -> V_152 ) ;
V_468 = ( char * ) & V_143 -> V_472 +
sizeof( struct V_471 ) - V_180 ;
memcpy ( V_468 , V_467 , V_180 ) ;
return 0 ;
}
V_145 = F_193 ( V_143 -> V_152 . V_473 , T_7 , V_157 ) ;
V_469 = V_145 -> V_154 [ V_145 -> V_474 - 1 ] . V_155 ;
V_470 = V_145 -> V_154 [ V_145 -> V_474 - 1 ] . V_203 ;
V_468 = F_194 ( V_469 , V_180 + V_470 , V_470 , V_177 ) ;
memcpy ( & V_468 [ V_470 ] , V_467 , V_180 ) ;
V_145 -> V_154 [ V_145 -> V_474 - 1 ] . V_203 += V_180 ;
V_145 -> V_154 [ V_145 -> V_474 - 1 ] . V_155 = V_468 ;
F_195 ( log , V_143 , V_145 , 0 ) ;
return 0 ;
}
STATIC int
F_196 (
struct V_1 * log ,
struct V_142 * V_143 ,
char * V_467 ,
int V_180 )
{
T_13 * V_331 ;
T_7 * V_145 ;
char * V_468 ;
if ( ! V_180 )
return 0 ;
if ( F_85 ( & V_143 -> V_152 ) ) {
if ( * ( T_5 * ) V_467 != V_475 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
if ( V_180 > sizeof( struct V_471 ) ) {
F_3 ( log -> V_7 , L_79 , V_8 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
if ( V_180 == sizeof( struct V_471 ) )
F_189 ( & V_143 -> V_152 ) ;
memcpy ( & V_143 -> V_472 , V_467 , V_180 ) ;
return 0 ;
}
V_468 = F_93 ( V_180 , V_177 ) ;
memcpy ( V_468 , V_467 , V_180 ) ;
V_331 = ( T_13 * ) V_468 ;
V_145 = F_193 ( V_143 -> V_152 . V_473 , T_7 , V_157 ) ;
if ( V_145 -> V_313 != 0 &&
V_145 -> V_313 == V_145 -> V_474 ) {
F_189 ( & V_143 -> V_152 ) ;
V_145 = F_193 ( V_143 -> V_152 . V_473 ,
T_7 , V_157 ) ;
}
if ( V_145 -> V_313 == 0 ) {
if ( V_331 -> V_376 == 0 ||
V_331 -> V_376 > V_476 ) {
F_3 ( log -> V_7 ,
L_81 ,
V_331 -> V_376 ) ;
ASSERT ( 0 ) ;
F_99 ( V_468 ) ;
return - V_58 ;
}
V_145 -> V_313 = V_331 -> V_376 ;
V_145 -> V_154 =
F_190 ( V_145 -> V_313 * sizeof( V_477 ) ,
V_177 ) ;
}
ASSERT ( V_145 -> V_313 > V_145 -> V_474 ) ;
V_145 -> V_154 [ V_145 -> V_474 ] . V_155 = V_468 ;
V_145 -> V_154 [ V_145 -> V_474 ] . V_203 = V_180 ;
V_145 -> V_474 ++ ;
F_197 ( log , V_143 , V_145 , 0 ) ;
return 0 ;
}
STATIC void
F_198 (
struct V_142 * V_143 )
{
T_7 * V_145 , * V_146 ;
int V_45 ;
F_79 (item, n, &trans->r_itemq, ri_list) {
F_98 ( & V_145 -> V_157 ) ;
for ( V_45 = 0 ; V_45 < V_145 -> V_474 ; V_45 ++ )
F_99 ( V_145 -> V_154 [ V_45 ] . V_155 ) ;
F_99 ( V_145 -> V_154 ) ;
F_99 ( V_145 ) ;
}
F_99 ( V_143 ) ;
}
STATIC int
F_199 (
struct V_1 * log ,
struct V_142 * V_143 ,
char * V_467 ,
unsigned int V_180 ,
unsigned int V_181 ,
int V_144 )
{
int error = 0 ;
bool V_478 = false ;
V_181 &= ~ V_479 ;
if ( V_181 & V_480 )
V_181 &= ~ V_481 ;
switch ( V_181 ) {
case 0 :
case V_481 :
error = F_196 ( log , V_143 , V_467 , V_180 ) ;
break;
case V_480 :
error = F_192 ( log , V_143 , V_467 , V_180 ) ;
break;
case V_482 :
error = F_184 ( log , V_143 , V_144 ) ;
V_478 = true ;
break;
case V_103 :
F_3 ( log -> V_7 , L_82 , V_8 ) ;
V_478 = true ;
break;
case V_483 :
default:
F_3 ( log -> V_7 , L_83 , V_8 , V_181 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
break;
}
if ( error || V_478 )
F_198 ( V_143 ) ;
return error ;
}
STATIC struct V_142 *
F_200 (
struct V_484 V_485 [] ,
struct V_75 * V_76 ,
struct V_94 * V_486 )
{
struct V_142 * V_143 ;
T_23 V_487 ;
struct V_484 * V_488 ;
V_487 = F_30 ( V_486 -> V_489 ) ;
V_488 = & V_485 [ F_201 ( V_487 ) ] ;
F_202 (trans, rhp, r_list) {
if ( V_143 -> V_490 == V_487 )
return V_143 ;
}
if ( ! ( V_486 -> V_102 & V_483 ) )
return NULL ;
ASSERT ( F_30 ( V_486 -> V_491 ) == 0 ) ;
V_143 = F_190 ( sizeof( struct V_142 ) , V_177 ) ;
V_143 -> V_490 = V_487 ;
V_143 -> V_461 = F_59 ( V_76 -> V_111 ) ;
F_191 ( & V_143 -> V_152 ) ;
F_203 ( & V_143 -> V_466 ) ;
F_204 ( & V_143 -> V_466 , V_488 ) ;
return NULL ;
}
STATIC int
F_205 (
struct V_1 * log ,
struct V_484 V_485 [] ,
struct V_75 * V_76 ,
struct V_94 * V_486 ,
char * V_467 ,
char * V_492 ,
int V_144 )
{
struct V_142 * V_143 ;
unsigned int V_180 ;
if ( V_486 -> V_493 != V_494 &&
V_486 -> V_493 != V_495 ) {
F_3 ( log -> V_7 , L_84 ,
V_8 , V_486 -> V_493 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
V_180 = F_30 ( V_486 -> V_491 ) ;
if ( V_467 + V_180 > V_492 ) {
F_3 ( log -> V_7 , L_85 , V_8 , V_180 ) ;
F_206 ( 1 ) ;
return - V_58 ;
}
V_143 = F_200 ( V_485 , V_76 , V_486 ) ;
if ( ! V_143 ) {
return 0 ;
}
return F_199 ( log , V_143 , V_467 , V_180 ,
V_486 -> V_102 , V_144 ) ;
}
STATIC int
F_207 (
struct V_1 * log ,
struct V_484 V_485 [] ,
struct V_75 * V_76 ,
char * V_467 ,
int V_144 )
{
struct V_94 * V_486 ;
char * V_492 ;
int V_496 ;
int error ;
V_492 = V_467 + F_30 ( V_76 -> V_61 ) ;
V_496 = F_30 ( V_76 -> V_101 ) ;
if ( F_31 ( log -> V_7 , V_76 ) )
return - V_58 ;
while ( ( V_467 < V_492 ) && V_496 ) {
V_486 = (struct V_94 * ) V_467 ;
V_467 += sizeof( * V_486 ) ;
ASSERT ( V_467 <= V_492 ) ;
error = F_205 ( log , V_485 , V_76 , V_486 ,
V_467 , V_492 , V_144 ) ;
if ( error )
return error ;
V_467 += F_30 ( V_486 -> V_491 ) ;
V_496 -- ;
}
return 0 ;
}
STATIC int
F_208 (
T_3 * V_23 ,
T_18 * V_406 )
{
T_24 * V_497 ;
T_25 * V_498 ;
int V_45 ;
int error = 0 ;
T_26 * V_499 ;
T_27 V_500 ;
ASSERT ( ! F_209 ( V_501 , & V_406 -> V_502 ) ) ;
for ( V_45 = 0 ; V_45 < V_406 -> V_410 . V_409 ; V_45 ++ ) {
V_499 = & ( V_406 -> V_410 . V_503 [ V_45 ] ) ;
V_500 = F_210 ( V_23 ,
F_211 ( V_23 , V_499 -> V_504 ) ) ;
if ( ( V_500 == 0 ) ||
( V_499 -> V_505 == 0 ) ||
( V_500 >= V_23 -> V_25 . V_506 ) ||
( V_499 -> V_505 >= V_23 -> V_25 . V_444 ) ) {
F_212 ( V_501 , & V_406 -> V_502 ) ;
F_163 ( V_406 ) ;
return - V_58 ;
}
}
V_498 = F_213 ( V_23 , 0 ) ;
error = F_214 ( V_498 , & F_215 ( V_23 ) -> V_507 , 0 , 0 ) ;
if ( error )
goto V_508;
V_497 = F_216 ( V_498 , V_406 , V_406 -> V_410 . V_409 ) ;
for ( V_45 = 0 ; V_45 < V_406 -> V_410 . V_409 ; V_45 ++ ) {
V_499 = & ( V_406 -> V_410 . V_503 [ V_45 ] ) ;
error = F_217 ( V_498 , V_497 , V_499 -> V_504 ,
V_499 -> V_505 ) ;
if ( error )
goto V_508;
}
F_212 ( V_501 , & V_406 -> V_502 ) ;
error = F_218 ( V_498 ) ;
return error ;
V_508:
F_219 ( V_498 ) ;
return error ;
}
STATIC int
F_220 (
struct V_1 * log )
{
struct V_509 * V_416 ;
struct V_405 * V_406 ;
int error = 0 ;
struct V_418 V_419 ;
struct V_420 * V_421 ;
V_421 = log -> V_412 ;
F_161 ( & V_421 -> V_413 ) ;
V_416 = F_165 ( V_421 , & V_419 , 0 ) ;
while ( V_416 != NULL ) {
if ( V_416 -> V_428 != V_166 ) {
#ifdef F_221
for (; V_416 ; V_416 = F_167 ( V_421 , & V_419 ) )
ASSERT ( V_416 -> V_428 != V_166 ) ;
#endif
break;
}
V_406 = F_222 ( V_416 , struct V_405 , V_414 ) ;
if ( F_209 ( V_501 , & V_406 -> V_502 ) ) {
V_416 = F_167 ( V_421 , & V_419 ) ;
continue;
}
F_166 ( & V_421 -> V_413 ) ;
error = F_208 ( log -> V_7 , V_406 ) ;
F_161 ( & V_421 -> V_413 ) ;
if ( error )
goto V_51;
V_416 = F_167 ( V_421 , & V_419 ) ;
}
V_51:
F_168 ( & V_419 ) ;
F_166 ( & V_421 -> V_413 ) ;
return error ;
}
STATIC int
F_223 (
struct V_1 * log )
{
struct V_509 * V_416 ;
struct V_405 * V_406 ;
int error = 0 ;
struct V_418 V_419 ;
struct V_420 * V_421 ;
V_421 = log -> V_412 ;
F_161 ( & V_421 -> V_413 ) ;
V_416 = F_165 ( V_421 , & V_419 , 0 ) ;
while ( V_416 != NULL ) {
if ( V_416 -> V_428 != V_166 ) {
#ifdef F_221
for (; V_416 ; V_416 = F_167 ( V_421 , & V_419 ) )
ASSERT ( V_416 -> V_428 != V_166 ) ;
#endif
break;
}
V_406 = F_222 ( V_416 , struct V_405 , V_414 ) ;
F_166 ( & V_421 -> V_413 ) ;
F_163 ( V_406 ) ;
F_161 ( & V_421 -> V_413 ) ;
V_416 = F_167 ( V_421 , & V_419 ) ;
}
F_168 ( & V_419 ) ;
F_166 ( & V_421 -> V_413 ) ;
return error ;
}
STATIC void
F_224 (
T_3 * V_23 ,
T_21 V_431 ,
int V_169 )
{
T_25 * V_498 ;
T_28 * V_510 ;
T_1 * V_511 ;
int V_13 ;
int error ;
V_498 = F_213 ( V_23 , V_512 ) ;
error = F_214 ( V_498 , & F_215 ( V_23 ) -> V_513 , 0 , 0 ) ;
if ( error )
goto V_514;
error = F_225 ( V_23 , V_498 , V_431 , & V_511 ) ;
if ( error )
goto V_514;
V_510 = F_226 ( V_511 ) ;
V_510 -> V_515 [ V_169 ] = F_32 ( V_516 ) ;
V_13 = F_103 ( T_28 , V_515 ) +
( sizeof( T_10 ) * V_169 ) ;
F_227 ( V_498 , V_511 , V_13 ,
( V_13 + sizeof( T_10 ) - 1 ) ) ;
error = F_218 ( V_498 ) ;
if ( error )
goto V_79;
return;
V_514:
F_219 ( V_498 ) ;
V_79:
F_3 ( V_23 , L_86 , V_8 , V_431 ) ;
return;
}
STATIC T_10
F_228 (
struct V_183 * V_23 ,
T_21 V_431 ,
T_10 V_517 ,
int V_169 )
{
struct V_5 * V_518 ;
struct V_328 * V_329 ;
struct V_332 * V_333 ;
T_29 V_519 ;
int error ;
V_519 = F_229 ( V_23 , V_431 , V_517 ) ;
error = F_230 ( V_23 , NULL , V_519 , 0 , 0 , & V_333 ) ;
if ( error )
goto V_520;
error = F_231 ( V_23 , NULL , & V_333 -> V_521 , & V_329 , & V_518 , 0 , 0 ) ;
if ( error )
goto V_522;
ASSERT ( V_333 -> V_338 . V_523 == 0 ) ;
ASSERT ( V_333 -> V_338 . V_362 != 0 ) ;
V_517 = F_30 ( V_329 -> V_199 ) ;
F_27 ( V_518 ) ;
V_333 -> V_338 . V_524 = 0 ;
F_232 ( V_333 ) ;
return V_517 ;
V_522:
F_232 ( V_333 ) ;
V_520:
F_224 ( V_23 , V_431 , V_169 ) ;
return V_516 ;
}
STATIC void
F_233 (
struct V_1 * log )
{
T_3 * V_23 ;
T_21 V_431 ;
T_28 * V_510 ;
T_1 * V_511 ;
T_10 V_517 ;
int V_169 ;
int error ;
T_5 V_525 ;
V_23 = log -> V_7 ;
V_525 = V_23 -> V_526 ;
V_23 -> V_526 = 0 ;
for ( V_431 = 0 ; V_431 < V_23 -> V_25 . V_441 ; V_431 ++ ) {
error = F_225 ( V_23 , NULL , V_431 , & V_511 ) ;
if ( error ) {
continue;
}
V_510 = F_226 ( V_511 ) ;
F_7 ( V_511 ) ;
for ( V_169 = 0 ; V_169 < V_527 ; V_169 ++ ) {
V_517 = F_30 ( V_510 -> V_515 [ V_169 ] ) ;
while ( V_517 != V_516 ) {
V_517 = F_228 ( V_23 ,
V_431 , V_517 , V_169 ) ;
}
}
F_234 ( V_511 ) ;
}
V_23 -> V_526 = V_525 ;
}
STATIC int
F_235 (
struct V_75 * V_76 ,
char * V_467 ,
struct V_1 * log )
{
int V_45 , V_46 , V_528 ;
for ( V_45 = 0 ; V_45 < F_48 ( F_30 ( V_76 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_80 * ) V_467 = * ( V_80 * ) & V_76 -> V_529 [ V_45 ] ;
V_467 += V_52 ;
}
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
T_30 * V_530 = ( T_30 * ) V_76 ;
for ( ; V_45 < F_48 ( F_30 ( V_76 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_528 = V_45 % ( V_60 / V_52 ) ;
* ( V_80 * ) V_467 = V_530 [ V_46 ] . V_531 . V_532 [ V_528 ] ;
V_467 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_236 (
struct V_1 * log ,
struct V_484 V_485 [] ,
struct V_75 * V_76 ,
char * V_467 ,
int V_144 )
{
int error ;
T_31 V_533 ;
V_533 = F_237 ( log , V_76 , V_467 , F_30 ( V_76 -> V_61 ) ) ;
if ( V_144 == V_85 ) {
if ( V_76 -> V_534 && V_533 != V_76 -> V_534 )
return - V_91 ;
return 0 ;
}
if ( V_533 != V_76 -> V_534 ) {
if ( V_76 -> V_534 || F_102 ( & log -> V_7 -> V_25 ) ) {
F_106 ( log -> V_7 ,
L_87 ,
F_238 ( V_76 -> V_534 ) ,
F_238 ( V_533 ) ) ;
F_239 ( V_467 , 32 ) ;
}
if ( F_102 ( & log -> V_7 -> V_25 ) )
return - V_16 ;
}
error = F_235 ( V_76 , V_467 , log ) ;
if ( error )
return error ;
return F_207 ( log , V_485 , V_76 , V_467 , V_144 ) ;
}
STATIC int
F_240 (
struct V_1 * log ,
struct V_75 * V_76 ,
T_2 V_179 )
{
int V_535 ;
if ( F_33 ( V_76 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_88 ,
V_141 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_33 (
( ! V_76 -> V_99 ||
( F_30 ( V_76 -> V_99 ) & ( ~ V_536 ) ) ) ) ) {
F_3 ( log -> V_7 , L_89 ,
V_8 , F_30 ( V_76 -> V_99 ) ) ;
return - V_58 ;
}
V_535 = F_30 ( V_76 -> V_61 ) ;
if ( F_33 ( V_535 <= 0 || V_535 > V_70 ) ) {
F_4 ( L_90 ,
V_141 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_33 ( V_179 > log -> V_3 || V_179 > V_70 ) ) {
F_4 ( L_91 ,
V_141 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_56 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 ,
int V_144 ,
T_2 * V_82 )
{
T_4 * V_76 ;
T_2 V_12 ;
T_2 V_86 ;
char * V_13 ;
T_1 * V_537 , * V_538 ;
int error = 0 , V_59 , V_61 ;
int V_539 , V_540 ;
int V_98 , V_541 , V_542 ;
struct V_484 V_485 [ V_543 ] ;
ASSERT ( V_63 != V_72 ) ;
V_86 = 0 ;
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
V_537 = F_2 ( log , 1 ) ;
if ( ! V_537 )
return - V_49 ;
error = F_19 ( log , V_72 , 1 , V_537 , & V_13 ) ;
if ( error )
goto V_544;
V_76 = ( T_4 * ) V_13 ;
error = F_240 ( log , V_76 , V_72 ) ;
if ( error )
goto V_544;
V_59 = F_30 ( V_76 -> V_59 ) ;
V_61 = F_30 ( V_76 -> V_61 ) ;
if ( V_61 > V_59 ) {
if ( V_61 <= log -> V_7 -> V_545 &&
F_30 ( V_76 -> V_101 ) == 1 ) {
F_3 ( log -> V_7 ,
L_92 ,
V_59 , log -> V_7 -> V_545 ) ;
V_59 = log -> V_7 -> V_545 ;
} else
return - V_16 ;
}
if ( ( F_30 ( V_76 -> V_99 ) & V_100 ) &&
( V_59 > V_60 ) ) {
V_98 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_98 ++ ;
F_8 ( V_537 ) ;
V_537 = F_2 ( log , V_98 ) ;
} else {
V_98 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_98 = 1 ;
V_537 = F_2 ( log , 1 ) ;
V_59 = V_546 ;
}
if ( ! V_537 )
return - V_49 ;
V_538 = F_2 ( log , F_48 ( V_59 ) ) ;
if ( ! V_538 ) {
F_8 ( V_537 ) ;
return - V_49 ;
}
memset ( V_485 , 0 , sizeof( V_485 ) ) ;
V_12 = V_86 = V_72 ;
if ( V_72 > V_63 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_537 -> V_15 ;
V_541 = 0 ;
V_542 = 0 ;
if ( V_12 + V_98 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_98 , V_537 ,
& V_13 ) ;
if ( error )
goto V_547;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_541 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_541 > 0 ) ;
error = F_19 ( log , V_12 ,
V_541 , V_537 ,
& V_13 ) ;
if ( error )
goto V_547;
}
V_542 = V_98 - V_541 ;
error = F_20 ( log , 0 ,
V_542 , V_537 ,
V_13 + F_11 ( V_541 ) ) ;
if ( error )
goto V_547;
}
V_76 = ( T_4 * ) V_13 ;
error = F_240 ( log , V_76 ,
V_541 ? V_12 : 0 ) ;
if ( error )
goto V_547;
V_539 = ( int ) F_48 ( F_30 ( V_76 -> V_61 ) ) ;
V_12 += V_98 ;
if ( V_12 + V_539 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_539 , V_538 ,
& V_13 ) ;
if ( error )
goto V_547;
} else {
V_13 = V_538 -> V_15 ;
V_540 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_542 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_540 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_540 > 0 ) ;
error = F_19 ( log , V_12 ,
V_540 , V_538 ,
& V_13 ) ;
if ( error )
goto V_547;
}
error = F_20 ( log , 0 ,
V_539 - V_540 , V_538 ,
V_13 + F_11 ( V_540 ) ) ;
if ( error )
goto V_547;
}
error = F_236 ( log , V_485 , V_76 , V_13 ,
V_144 ) ;
if ( error )
goto V_547;
V_12 += V_539 ;
V_86 = V_12 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
V_86 = V_12 ;
}
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_98 , V_537 , & V_13 ) ;
if ( error )
goto V_547;
V_76 = ( T_4 * ) V_13 ;
error = F_240 ( log , V_76 , V_12 ) ;
if ( error )
goto V_547;
V_539 = ( int ) F_48 ( F_30 ( V_76 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_98 , V_539 , V_538 ,
& V_13 ) ;
if ( error )
goto V_547;
error = F_236 ( log , V_485 , V_76 , V_13 , V_144 ) ;
if ( error )
goto V_547;
V_12 += V_539 + V_98 ;
V_86 = V_12 ;
}
V_547:
F_8 ( V_538 ) ;
V_544:
F_8 ( V_537 ) ;
if ( error && V_82 )
* V_82 = V_86 ;
return error ;
}
STATIC int
F_241 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_182 = F_190 ( V_548 *
sizeof( struct V_168 ) ,
V_177 ) ;
for ( V_45 = 0 ; V_45 < V_548 ; V_45 ++ )
F_191 ( & log -> V_182 [ V_45 ] ) ;
error = F_56 ( log , V_63 , V_72 ,
V_459 , NULL ) ;
if ( error != 0 ) {
F_99 ( log -> V_182 ) ;
log -> V_182 = NULL ;
return error ;
}
error = F_56 ( log , V_63 , V_72 ,
V_460 , NULL ) ;
#ifdef F_221
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_548 ; V_45 ++ )
ASSERT ( F_85 ( & log -> V_182 [ V_45 ] ) ) ;
}
#endif
F_99 ( log -> V_182 ) ;
log -> V_182 = NULL ;
return error ;
}
STATIC int
F_242 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 )
{
int error ;
T_1 * V_6 ;
T_32 * V_549 ;
error = F_241 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_17 ( log -> V_7 ) ) {
return - V_58 ;
}
F_243 ( log -> V_7 ) ;
V_6 = F_244 ( log -> V_7 , 0 ) ;
F_245 ( V_6 ) ;
ASSERT ( ! ( F_246 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_247 ( V_6 ) ;
V_6 -> V_194 = & V_306 ;
error = F_16 ( V_6 ) ;
if ( error ) {
if ( ! F_17 ( log -> V_7 ) ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_27 ( V_6 ) ;
return error ;
}
V_549 = & log -> V_7 -> V_25 ;
F_248 ( V_549 , F_249 ( V_6 ) ) ;
ASSERT ( V_549 -> V_550 == V_248 ) ;
ASSERT ( F_250 ( V_549 ) ) ;
F_251 ( log -> V_7 ) ;
F_27 ( V_6 ) ;
F_252 ( log ) ;
log -> V_551 &= ~ V_552 ;
return 0 ;
}
int
V_142 (
struct V_1 * log )
{
T_2 V_63 , V_72 ;
int error ;
error = F_66 ( log , & V_63 , & V_72 ) ;
if ( error )
return error ;
if ( F_102 ( & log -> V_7 -> V_25 ) &&
! F_253 ( log -> V_7 , log -> V_7 -> V_25 . V_250 ) )
return - V_122 ;
if ( V_72 != V_63 ) {
if ( ( error = F_254 ( log -> V_7 , L_93 ) ) ) {
return error ;
}
if ( F_255 ( & log -> V_7 -> V_25 ) == V_553 &&
F_256 ( & log -> V_7 -> V_25 ,
V_554 ) ) {
F_3 ( log -> V_7 ,
L_94 ,
( log -> V_7 -> V_25 . V_555 &
V_554 ) ) ;
F_3 ( log -> V_7 ,
L_95 ) ;
F_3 ( log -> V_7 ,
L_96 ) ;
return - V_122 ;
}
if ( V_556 . V_557 ) {
F_257 ( log -> V_7 ,
L_97 ,
V_556 . V_557 ) ;
F_258 ( V_556 . V_557 * 1000 ) ;
}
F_257 ( log -> V_7 , L_98 ,
log -> V_7 -> V_558 ? log -> V_7 -> V_558
: L_99 ) ;
error = F_242 ( log , V_63 , V_72 ) ;
log -> V_551 |= V_559 ;
}
return error ;
}
int
F_259 (
struct V_1 * log )
{
if ( log -> V_551 & V_559 ) {
int error ;
error = F_220 ( log ) ;
if ( error ) {
F_106 ( log -> V_7 , L_100 ) ;
return error ;
}
F_260 ( log -> V_7 , V_560 ) ;
F_233 ( log ) ;
F_252 ( log ) ;
F_257 ( log -> V_7 , L_101 ,
log -> V_7 -> V_558 ? log -> V_7 -> V_558
: L_99 ) ;
log -> V_551 &= ~ V_559 ;
} else {
F_261 ( log -> V_7 , L_102 ) ;
}
return 0 ;
}
int
F_262 (
struct V_1 * log )
{
int error = 0 ;
if ( log -> V_551 & V_559 )
error = F_223 ( log ) ;
return error ;
}
void
F_252 (
struct V_1 * log )
{
T_3 * V_23 ;
T_33 * V_561 ;
T_1 * V_562 ;
T_1 * V_511 ;
T_21 V_431 ;
T_20 V_563 ;
T_20 V_564 ;
T_20 V_565 ;
int error ;
V_23 = log -> V_7 ;
V_563 = 0LL ;
V_564 = 0LL ;
V_565 = 0LL ;
for ( V_431 = 0 ; V_431 < V_23 -> V_25 . V_441 ; V_431 ++ ) {
error = F_263 ( V_23 , NULL , V_431 , 0 , & V_562 ) ;
if ( error ) {
F_106 ( V_23 , L_103 ,
V_8 , V_431 , error ) ;
} else {
V_561 = F_264 ( V_562 ) ;
V_563 += F_30 ( V_561 -> V_566 ) +
F_30 ( V_561 -> V_567 ) ;
F_27 ( V_562 ) ;
}
error = F_225 ( V_23 , NULL , V_431 , & V_511 ) ;
if ( error ) {
F_106 ( V_23 , L_104 ,
V_8 , V_431 , error ) ;
} else {
struct V_236 * V_510 = F_226 ( V_511 ) ;
V_564 += F_30 ( V_510 -> V_568 ) ;
V_565 += F_30 ( V_510 -> V_569 ) ;
F_27 ( V_511 ) ;
}
}
}
