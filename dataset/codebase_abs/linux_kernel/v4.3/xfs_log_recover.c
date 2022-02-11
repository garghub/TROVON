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
T_2 * V_63 ,
T_2 * V_72 )
{
T_4 * V_73 ;
T_6 * V_74 ;
char * V_13 = NULL ;
T_1 * V_6 ;
int error , V_45 , V_75 ;
T_2 V_76 ;
T_2 V_77 ;
T_7 V_78 ;
int V_79 ;
V_75 = 0 ;
if ( ( error = F_49 ( log , V_63 ) ) )
return error ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_49 ;
if ( * V_63 == 0 ) {
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( F_42 ( V_13 ) == 0 ) {
* V_72 = 0 ;
goto V_80;
}
}
ASSERT ( * V_63 < V_70 ) ;
for ( V_45 = ( int ) ( * V_63 ) - 1 ; V_45 >= 0 ; V_45 -- ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( * ( V_81 * ) V_13 == F_32 ( V_31 ) ) {
V_75 = 1 ;
break;
}
}
if ( ! V_75 ) {
for ( V_45 = log -> V_3 - 1 ; V_45 >= ( int ) ( * V_63 ) ; V_45 -- ) {
error = F_19 ( log , V_45 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( * ( V_81 * ) V_13 ==
F_32 ( V_31 ) ) {
V_75 = 2 ;
break;
}
}
}
if ( ! V_75 ) {
F_3 ( log -> V_7 , L_15 , V_8 ) ;
F_8 ( V_6 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
V_73 = ( T_4 * ) V_13 ;
* V_72 = F_54 ( F_55 ( V_73 -> V_82 ) ) ;
log -> V_83 = V_45 ;
log -> V_84 = ( int ) * V_63 ;
log -> V_85 = F_30 ( V_73 -> V_86 ) ;
if ( V_75 == 2 )
log -> V_85 ++ ;
F_56 ( & log -> V_87 , F_55 ( V_73 -> V_82 ) ) ;
F_56 ( & log -> V_88 , F_55 ( V_73 -> V_89 ) ) ;
F_57 ( & log -> V_90 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
F_57 ( & log -> V_92 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
int V_59 = F_30 ( V_73 -> V_59 ) ;
int V_93 = F_30 ( V_73 -> V_93 ) ;
if ( ( V_93 & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
} else {
V_79 = 1 ;
}
} else {
V_79 = 1 ;
}
V_77 = ( V_45 + V_79 + ( int )
F_48 ( F_30 ( V_73 -> V_61 ) ) ) % log -> V_3 ;
V_78 = F_58 ( & log -> V_87 ) ;
if ( * V_63 == V_77 &&
F_30 ( V_73 -> V_95 ) == 1 ) {
V_76 = ( V_45 + V_79 ) % log -> V_3 ;
error = F_19 ( log , V_76 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
V_74 = ( T_6 * ) V_13 ;
if ( V_74 -> V_96 & V_97 ) {
F_59 ( & log -> V_87 ,
log -> V_85 , V_77 ) ;
F_59 ( & log -> V_88 ,
log -> V_85 , V_77 ) ;
* V_72 = V_77 ;
log -> V_7 -> V_98 |= V_99 ;
}
}
if ( ! F_60 ( log -> V_7 -> V_11 ) )
error = F_61 ( log , V_78 ) ;
V_80:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_16 ) ;
return error ;
}
STATIC int
F_50 (
struct V_1 * log ,
T_2 * V_12 )
{
T_1 * V_6 ;
char * V_13 ;
T_5 V_100 , V_101 ;
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
V_100 = F_42 ( V_13 ) ;
if ( V_100 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return 1 ;
}
error = F_19 ( log , V_68 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_101 = F_42 ( V_13 ) ;
if ( V_101 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_100 != 1 ) {
F_3 ( log -> V_7 ,
L_17 ) ;
error = - V_102 ;
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
F_62 (
struct V_1 * log ,
char * V_48 ,
int V_38 ,
int V_103 ,
int V_104 ,
int V_105 )
{
T_4 * V_106 = ( T_4 * ) V_48 ;
memset ( V_48 , 0 , V_52 ) ;
V_106 -> V_30 = F_32 ( V_31 ) ;
V_106 -> V_86 = F_32 ( V_38 ) ;
V_106 -> V_93 = F_32 (
F_47 ( & log -> V_7 -> V_25 ) ? 2 : 1 ) ;
V_106 -> V_89 = F_63 ( F_64 ( V_38 , V_103 ) ) ;
V_106 -> V_82 = F_63 ( F_64 ( V_104 , V_105 ) ) ;
V_106 -> V_29 = F_32 ( V_27 ) ;
memcpy ( & V_106 -> V_28 , & log -> V_7 -> V_25 . V_26 , sizeof( V_107 ) ) ;
}
STATIC int
F_65 (
struct V_1 * log ,
int V_38 ,
int V_108 ,
int V_109 ,
int V_104 ,
int V_105 )
{
char * V_13 ;
T_1 * V_6 ;
int V_110 , V_111 ;
int V_112 = log -> V_10 ;
int V_113 = V_108 + V_109 ;
int V_47 ;
int error = 0 ;
int V_45 , V_46 = 0 ;
V_47 = 1 << F_44 ( V_109 ) ;
while ( V_47 > log -> V_3 )
V_47 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_47 ) ) ) {
V_47 >>= 1 ;
if ( V_47 < V_112 )
return - V_49 ;
}
V_110 = F_13 ( V_108 , V_112 ) ;
if ( V_110 != V_108 ) {
error = F_12 ( log , V_108 , 1 , V_6 ) ;
if ( error )
goto V_114;
V_46 = V_108 - V_110 ;
}
for ( V_45 = V_108 ; V_45 < V_113 ; V_45 += V_47 ) {
int V_50 , V_115 ;
V_50 = F_45 ( V_47 , V_113 - V_108 ) ;
V_115 = V_50 - V_46 ;
V_111 = F_13 ( V_113 , V_112 ) ;
if ( V_46 == 0 && ( V_108 + V_115 > V_111 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_111 - V_108 ) ;
error = F_20 ( log , V_111 , V_112 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_108 , V_115 , V_6 ) ;
for (; V_46 < V_115 ; V_46 ++ ) {
F_62 ( log , V_13 , V_38 , V_45 + V_46 ,
V_104 , V_105 ) ;
V_13 += V_52 ;
}
error = F_22 ( log , V_108 , V_115 , V_6 ) ;
if ( error )
break;
V_108 += V_115 ;
V_46 = 0 ;
}
V_114:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_61 (
struct V_1 * log ,
T_7 V_78 )
{
int V_104 , V_116 ;
int V_105 , V_117 ;
int V_118 , V_119 ;
int V_120 ;
int error ;
V_104 = F_66 ( V_78 ) ;
V_105 = F_54 ( V_78 ) ;
V_116 = log -> V_85 ;
V_117 = log -> V_84 ;
if ( V_116 == V_104 ) {
if ( F_33 ( V_117 < V_105 || V_117 >= log -> V_3 ) ) {
F_4 ( L_18 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
V_118 = V_105 + ( log -> V_3 - V_117 ) ;
} else {
if ( F_33 ( V_117 >= V_105 || V_116 != ( V_104 + 1 ) ) ) {
F_4 ( L_19 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
V_118 = V_105 - V_117 ;
}
if ( V_118 <= 0 ) {
ASSERT ( V_118 == 0 ) ;
return 0 ;
}
V_119 = F_51 ( log ) ;
V_119 = F_67 ( V_119 , V_118 ) ;
if ( ( V_117 + V_119 ) <= log -> V_3 ) {
error = F_65 ( log , ( V_116 - 1 ) ,
V_117 , V_119 , V_104 ,
V_105 ) ;
if ( error )
return error ;
} else {
V_120 = log -> V_3 - V_117 ;
error = F_65 ( log , ( V_116 - 1 ) ,
V_117 , V_120 , V_104 ,
V_105 ) ;
if ( error )
return error ;
V_120 = V_119 - ( log -> V_3 - V_117 ) ;
error = F_65 ( log , V_116 , 0 , V_120 ,
V_104 , V_105 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_68 (
struct V_1 * log ,
struct V_122 * V_123 ,
int V_124 )
{
T_8 * V_125 , * V_126 ;
int error = 0 ;
F_69 ( V_127 ) ;
F_69 ( V_128 ) ;
F_69 ( V_129 ) ;
F_69 ( V_130 ) ;
F_69 ( V_131 ) ;
F_70 ( & V_123 -> V_132 , & V_127 ) ;
F_71 (item, n, &sort_list, ri_list) {
T_9 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
switch ( F_72 ( V_125 ) ) {
case V_136 :
F_73 ( & V_125 -> V_137 , & V_129 ) ;
break;
case V_138 :
if ( V_133 -> V_139 & V_140 ) {
F_74 ( log ,
V_123 , V_125 , V_124 ) ;
F_75 ( & V_125 -> V_137 , & V_128 ) ;
break;
}
if ( V_133 -> V_139 & V_141 ) {
F_75 ( & V_125 -> V_137 , & V_130 ) ;
break;
}
F_73 ( & V_125 -> V_137 , & V_129 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
F_76 ( log ,
V_123 , V_125 , V_124 ) ;
F_73 ( & V_125 -> V_137 , & V_131 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_20 ,
V_8 ) ;
ASSERT ( 0 ) ;
if ( ! F_77 ( & V_127 ) )
F_70 ( & V_127 , & V_123 -> V_132 ) ;
error = - V_58 ;
goto V_51;
}
}
V_51:
ASSERT ( F_77 ( & V_127 ) ) ;
if ( ! F_77 ( & V_129 ) )
F_78 ( & V_129 , & V_123 -> V_132 ) ;
if ( ! F_77 ( & V_131 ) )
F_79 ( & V_131 , & V_123 -> V_132 ) ;
if ( ! F_77 ( & V_130 ) )
F_79 ( & V_130 , & V_123 -> V_132 ) ;
if ( ! F_77 ( & V_128 ) )
F_79 ( & V_128 , & V_123 -> V_132 ) ;
return error ;
}
STATIC int
F_80 (
struct V_1 * log ,
struct V_147 * V_125 )
{
T_9 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
if ( ! ( V_133 -> V_139 & V_140 ) ) {
F_81 ( log , V_133 ) ;
return 0 ;
}
V_149 = F_82 ( log , V_133 -> V_152 ) ;
F_83 (bcp, bucket, bc_list) {
if ( V_151 -> V_153 == V_133 -> V_152 &&
V_151 -> V_154 == V_133 -> V_155 ) {
V_151 -> V_156 ++ ;
F_84 ( log , V_133 ) ;
return 0 ;
}
}
V_151 = F_85 ( sizeof( struct V_150 ) , V_157 ) ;
V_151 -> V_153 = V_133 -> V_152 ;
V_151 -> V_154 = V_133 -> V_155 ;
V_151 -> V_156 = 1 ;
F_86 ( & V_151 -> V_158 , V_149 ) ;
F_87 ( log , V_133 ) ;
return 0 ;
}
STATIC struct V_150 *
F_88 (
struct V_1 * log ,
T_2 V_159 ,
T_5 V_160 ,
T_10 V_161 )
{
struct V_148 * V_149 ;
struct V_150 * V_151 ;
if ( ! log -> V_162 ) {
ASSERT ( ! ( V_161 & V_140 ) ) ;
return NULL ;
}
V_149 = F_82 ( log , V_159 ) ;
F_83 (bcp, bucket, bc_list) {
if ( V_151 -> V_153 == V_159 && V_151 -> V_154 == V_160 )
return V_151 ;
}
ASSERT ( ! ( V_161 & V_140 ) ) ;
return NULL ;
}
STATIC int
F_89 (
struct V_1 * log ,
T_2 V_159 ,
T_5 V_160 ,
T_10 V_161 )
{
struct V_150 * V_151 ;
V_151 = F_88 ( log , V_159 , V_160 , V_161 ) ;
if ( ! V_151 )
return 0 ;
if ( V_161 & V_140 ) {
if ( -- V_151 -> V_156 == 0 ) {
F_90 ( & V_151 -> V_158 ) ;
F_91 ( V_151 ) ;
}
}
return 1 ;
}
STATIC int
F_92 (
struct V_163 * V_23 ,
T_8 * V_125 ,
struct V_5 * V_6 ,
T_9 * V_133 )
{
int V_45 ;
int V_164 = 0 ;
int V_165 = 0 ;
int V_166 = 0 ;
int V_167 = 0 ;
int V_168 = 0 ;
int V_169 ;
int V_170 ;
T_11 * V_171 ;
T_11 * V_172 ;
F_93 ( V_23 -> V_173 , V_133 ) ;
if ( F_94 ( & V_23 -> V_25 ) )
V_6 -> V_174 = & V_175 ;
V_170 = F_11 ( V_6 -> V_18 ) >> V_23 -> V_25 . V_176 ;
for ( V_45 = 0 ; V_45 < V_170 ; V_45 ++ ) {
V_169 = ( V_45 * V_23 -> V_25 . V_177 ) +
F_95 ( V_178 , V_179 ) ;
while ( V_169 >=
( V_167 + V_168 ) ) {
V_165 += V_166 ;
V_165 = F_96 ( V_133 -> V_180 ,
V_133 -> V_181 , V_165 ) ;
if ( V_165 == - 1 )
return 0 ;
V_166 = F_97 ( V_133 -> V_180 ,
V_133 -> V_181 , V_165 ) ;
ASSERT ( V_166 > 0 ) ;
V_167 = V_165 << V_182 ;
V_168 = V_166 << V_182 ;
V_164 ++ ;
}
if ( V_169 < V_167 )
continue;
ASSERT ( V_125 -> V_134 [ V_164 ] . V_135 != NULL ) ;
ASSERT ( ( V_125 -> V_134 [ V_164 ] . V_183 % V_184 ) == 0 ) ;
ASSERT ( ( V_167 + V_168 ) <=
F_11 ( V_6 -> V_18 ) ) ;
V_171 = V_125 -> V_134 [ V_164 ] . V_135 +
V_169 - V_167 ;
if ( F_33 ( * V_171 == 0 ) ) {
F_98 ( V_23 ,
L_21
L_22 ,
V_125 , V_6 ) ;
F_4 ( L_23 ,
V_121 , V_23 ) ;
return - V_16 ;
}
V_172 = F_99 ( V_6 , V_169 ) ;
* V_172 = * V_171 ;
F_100 ( V_23 ,
F_99 ( V_6 , V_45 * V_23 -> V_25 . V_177 ) ) ;
}
return 0 ;
}
static T_7
F_101 (
struct V_163 * V_23 ,
struct V_5 * V_6 )
{
T_12 V_185 ;
T_13 V_186 ;
T_13 V_187 ;
void * V_188 = V_6 -> V_15 ;
V_107 * V_189 ;
T_7 V_190 = - 1 ;
if ( ! F_94 ( & V_23 -> V_25 ) )
goto V_191;
V_185 = F_30 ( * ( V_81 * ) V_188 ) ;
switch ( V_185 ) {
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 : {
struct V_198 * V_199 = V_188 ;
V_190 = F_55 ( V_199 -> V_200 . V_201 . V_202 ) ;
V_189 = & V_199 -> V_200 . V_201 . V_203 ;
break;
}
case V_204 :
case V_205 : {
struct V_198 * V_199 = V_188 ;
V_190 = F_55 ( V_199 -> V_200 . V_206 . V_202 ) ;
V_189 = & V_199 -> V_200 . V_206 . V_203 ;
break;
}
case V_207 :
V_190 = F_55 ( ( (struct V_208 * ) V_188 ) -> V_209 ) ;
V_189 = & ( (struct V_208 * ) V_188 ) -> V_210 ;
break;
case V_211 :
V_190 = F_55 ( ( (struct V_212 * ) V_188 ) -> V_213 ) ;
V_189 = & ( (struct V_212 * ) V_188 ) -> V_214 ;
break;
case V_215 :
V_190 = F_55 ( ( (struct V_216 * ) V_188 ) -> V_217 ) ;
V_189 = & ( (struct V_216 * ) V_188 ) -> V_218 ;
break;
case V_219 :
V_190 = F_55 ( ( (struct V_220 * ) V_188 ) -> V_221 ) ;
V_189 = & ( (struct V_220 * ) V_188 ) -> V_222 ;
break;
case V_223 :
case V_224 :
case V_225 :
V_190 = F_55 ( ( (struct V_226 * ) V_188 ) -> V_190 ) ;
V_189 = & ( (struct V_226 * ) V_188 ) -> V_189 ;
break;
case V_227 :
goto V_191;
case V_228 :
V_190 = F_55 ( ( (struct V_229 * ) V_188 ) -> V_230 ) ;
if ( F_102 ( & V_23 -> V_25 ) )
V_189 = & ( (struct V_229 * ) V_188 ) -> V_231 ;
else
V_189 = & ( (struct V_229 * ) V_188 ) -> V_26 ;
break;
default:
break;
}
if ( V_190 != ( T_7 ) - 1 ) {
if ( ! F_34 ( & V_23 -> V_25 . V_231 , V_189 ) )
goto V_191;
return V_190 ;
}
V_187 = F_103 ( ( (struct V_232 * ) V_188 ) -> V_233 ) ;
switch ( V_187 ) {
case V_234 :
case V_235 :
case V_236 :
V_190 = F_55 ( ( (struct V_237 * ) V_188 ) -> V_190 ) ;
V_189 = & ( (struct V_237 * ) V_188 ) -> V_189 ;
break;
default:
break;
}
if ( V_190 != ( T_7 ) - 1 ) {
if ( ! F_34 ( & V_23 -> V_25 . V_26 , V_189 ) )
goto V_191;
return V_190 ;
}
V_186 = F_103 ( * ( V_238 * ) V_188 ) ;
switch ( V_186 ) {
case V_239 :
case V_240 :
goto V_191;
default:
break;
}
V_191:
return ( T_7 ) - 1 ;
}
static void
F_104 (
struct V_163 * V_23 ,
struct V_5 * V_6 ,
T_9 * V_133 )
{
struct V_232 * V_241 = V_6 -> V_15 ;
T_12 V_185 ;
T_13 V_186 ;
T_13 V_187 ;
if ( ! F_94 ( & V_23 -> V_25 ) )
return;
V_185 = F_30 ( * ( V_81 * ) V_6 -> V_15 ) ;
V_186 = F_103 ( * ( V_238 * ) V_6 -> V_15 ) ;
V_187 = F_103 ( V_241 -> V_233 ) ;
switch ( F_105 ( V_133 ) ) {
case V_242 :
switch ( V_185 ) {
case V_192 :
case V_193 :
case V_194 :
case V_195 :
V_6 -> V_174 = & V_243 ;
break;
case V_196 :
case V_244 :
case V_197 :
case V_245 :
V_6 -> V_174 = & V_246 ;
break;
case V_204 :
case V_205 :
V_6 -> V_174 = & V_247 ;
break;
default:
F_3 ( V_23 , L_24 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_248 :
if ( V_185 != V_207 ) {
F_3 ( V_23 , L_25 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_249 ;
break;
case V_250 :
if ( V_185 != V_211 ) {
F_3 ( V_23 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_251 ;
break;
case V_252 :
if ( V_185 != V_215 ) {
F_3 ( V_23 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_253 ;
break;
case V_254 :
case V_255 :
case V_256 :
#ifdef F_106
if ( V_186 != V_239 ) {
F_3 ( V_23 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_257 ;
#else
F_98 ( V_23 ,
L_29 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_258 :
if ( V_186 != V_240 ) {
F_3 ( V_23 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_175 ;
break;
case V_259 :
if ( V_185 != V_219 ) {
F_3 ( V_23 , L_31 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_260 ;
break;
case V_261 :
if ( V_185 != V_262 &&
V_185 != V_223 ) {
F_3 ( V_23 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_263 ;
break;
case V_264 :
if ( V_185 != V_265 &&
V_185 != V_224 ) {
F_3 ( V_23 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_266 ;
break;
case V_267 :
if ( V_185 != V_268 &&
V_185 != V_225 ) {
F_3 ( V_23 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_269 ;
break;
case V_270 :
if ( V_187 != V_271 &&
V_187 != V_234 ) {
F_3 ( V_23 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_272 ;
break;
case V_273 :
if ( V_187 != V_274 &&
V_187 != V_235 ) {
F_3 ( V_23 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_275 ;
break;
case V_276 :
if ( V_187 != V_277 &&
V_187 != V_236 ) {
F_3 ( V_23 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_278 ;
break;
case V_279 :
if ( V_187 != V_280 &&
V_187 != V_281 ) {
F_3 ( V_23 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_282 ;
break;
case V_283 :
if ( V_185 != V_227 ) {
F_3 ( V_23 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_284 ;
break;
case V_285 :
if ( V_185 != V_228 ) {
F_3 ( V_23 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_286 ;
break;
default:
F_3 ( V_23 , L_41 ,
F_105 ( V_133 ) ) ;
break;
}
}
STATIC void
F_107 (
struct V_163 * V_23 ,
T_8 * V_125 ,
struct V_5 * V_6 ,
T_9 * V_133 )
{
int V_45 ;
int V_165 ;
int V_166 ;
int error ;
F_108 ( V_23 -> V_173 , V_133 ) ;
V_165 = 0 ;
V_45 = 1 ;
while ( 1 ) {
V_165 = F_96 ( V_133 -> V_180 ,
V_133 -> V_181 , V_165 ) ;
if ( V_165 == - 1 )
break;
V_166 = F_97 ( V_133 -> V_180 ,
V_133 -> V_181 , V_165 ) ;
ASSERT ( V_166 > 0 ) ;
ASSERT ( V_125 -> V_134 [ V_45 ] . V_135 != NULL ) ;
ASSERT ( V_125 -> V_134 [ V_45 ] . V_183 % V_184 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_18 ) >=
( ( T_5 ) V_165 << V_182 ) + ( V_166 << V_182 ) ) ;
if ( V_125 -> V_134 [ V_45 ] . V_183 < ( V_166 << V_182 ) )
V_166 = V_125 -> V_134 [ V_45 ] . V_183 >> V_182 ;
error = 0 ;
if ( V_133 -> V_139 &
( V_287 | V_288 | V_289 ) ) {
if ( V_125 -> V_134 [ V_45 ] . V_135 == NULL ) {
F_98 ( V_23 ,
L_42 , V_8 ) ;
goto V_290;
}
if ( V_125 -> V_134 [ V_45 ] . V_183 < sizeof( V_291 ) ) {
F_98 ( V_23 ,
L_43 ,
V_125 -> V_134 [ V_45 ] . V_183 , V_8 ) ;
goto V_290;
}
error = F_109 ( V_23 , V_125 -> V_134 [ V_45 ] . V_135 ,
- 1 , 0 , V_292 ,
L_44 ) ;
if ( error )
goto V_290;
}
memcpy ( F_99 ( V_6 ,
( T_5 ) V_165 << V_182 ) ,
V_125 -> V_134 [ V_45 ] . V_135 ,
V_166 << V_182 ) ;
V_290:
V_45 ++ ;
V_165 += V_166 ;
}
ASSERT ( V_45 == V_125 -> V_293 ) ;
F_104 ( V_23 , V_6 , V_133 ) ;
}
STATIC bool
F_110 (
struct V_163 * V_23 ,
struct V_1 * log ,
struct V_147 * V_125 ,
struct V_5 * V_6 ,
struct V_294 * V_133 )
{
T_5 type ;
F_111 ( log , V_133 ) ;
if ( ! V_23 -> V_295 )
return false ;
type = 0 ;
if ( V_133 -> V_139 & V_287 )
type |= V_296 ;
if ( V_133 -> V_139 & V_288 )
type |= V_297 ;
if ( V_133 -> V_139 & V_289 )
type |= V_298 ;
if ( log -> V_299 & type )
return false ;
F_107 ( V_23 , V_125 , V_6 , V_133 ) ;
return true ;
}
STATIC int
F_112 (
struct V_1 * log ,
struct V_148 * V_129 ,
struct V_147 * V_125 ,
T_7 V_300 )
{
T_9 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
T_3 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_5 V_301 ;
T_7 V_190 ;
if ( F_89 ( log , V_133 -> V_152 ,
V_133 -> V_155 , V_133 -> V_139 ) ) {
F_113 ( log , V_133 ) ;
return 0 ;
}
F_114 ( log , V_133 ) ;
V_301 = 0 ;
if ( V_133 -> V_139 & V_141 )
V_301 |= V_302 ;
V_6 = F_115 ( V_23 -> V_303 , V_133 -> V_152 , V_133 -> V_155 ,
V_301 , NULL ) ;
if ( ! V_6 )
return - V_49 ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_45 ) ;
goto V_304;
}
V_190 = F_101 ( V_23 , V_6 ) ;
if ( V_190 && V_190 != - 1 && F_116 ( V_190 , V_300 ) >= 0 ) {
F_104 ( V_23 , V_6 , V_133 ) ;
goto V_304;
}
if ( V_133 -> V_139 & V_141 ) {
error = F_92 ( V_23 , V_125 , V_6 , V_133 ) ;
if ( error )
goto V_304;
} else if ( V_133 -> V_139 &
( V_287 | V_288 | V_289 ) ) {
bool V_305 ;
V_305 = F_110 ( V_23 , log , V_125 , V_6 , V_133 ) ;
if ( ! V_305 )
goto V_304;
} else {
F_107 ( V_23 , V_125 , V_6 , V_133 ) ;
}
if ( V_240 ==
F_103 ( * ( ( V_238 * ) F_99 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_117 ( log -> V_7 -> V_25 . V_306 ,
( T_12 ) log -> V_7 -> V_307 ) ) ) {
F_118 ( V_6 ) ;
error = F_26 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_119 ( V_6 , V_129 ) ;
}
V_304:
F_27 ( V_6 ) ;
return error ;
}
STATIC int
F_120 (
struct V_163 * V_23 ,
struct V_308 * V_309 ,
struct V_310 * V_311 ,
struct V_148 * V_129 )
{
struct V_312 * V_313 ;
int error ;
ASSERT ( V_311 -> V_314 & ( V_315 | V_316 ) ) ;
V_313 = F_121 ( V_23 , V_311 -> V_317 ) ;
if ( ! V_313 )
return - V_49 ;
F_122 ( & V_313 -> V_318 , V_309 ) ;
ASSERT ( V_313 -> V_318 . V_319 >= 3 ) ;
error = F_123 ( V_313 , V_309 ) ;
if ( error )
goto V_320;
if ( V_311 -> V_314 & V_315 ) {
ASSERT ( V_311 -> V_314 & V_321 ) ;
error = F_124 ( NULL , V_313 , V_322 ,
V_313 -> V_323 , V_129 ) ;
if ( error )
goto V_320;
}
if ( V_311 -> V_314 & V_316 ) {
ASSERT ( V_311 -> V_314 & V_324 ) ;
error = F_124 ( NULL , V_313 , V_325 ,
V_313 -> V_323 , V_129 ) ;
if ( error )
goto V_320;
}
V_320:
F_125 ( V_313 ) ;
return error ;
}
STATIC int
F_126 (
struct V_1 * log ,
struct V_148 * V_129 ,
struct V_147 * V_125 ,
T_7 V_300 )
{
T_14 * V_311 ;
T_3 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_178 * V_309 ;
int V_160 ;
char * V_326 ;
char * V_327 ;
int error ;
int V_328 ;
T_5 V_329 ;
T_15 * V_330 ;
T_5 V_331 ;
int V_332 = 0 ;
if ( V_125 -> V_134 [ 0 ] . V_183 == sizeof( T_14 ) ) {
V_311 = V_125 -> V_134 [ 0 ] . V_135 ;
} else {
V_311 = F_85 ( sizeof( T_14 ) , V_157 ) ;
V_332 = 1 ;
error = F_127 ( & V_125 -> V_134 [ 0 ] , V_311 ) ;
if ( error )
goto error;
}
if ( F_89 ( log , V_311 -> V_333 ,
V_311 -> V_334 , 0 ) ) {
error = 0 ;
F_128 ( log , V_311 ) ;
goto error;
}
F_129 ( log , V_311 ) ;
V_6 = F_115 ( V_23 -> V_303 , V_311 -> V_333 , V_311 -> V_334 , 0 ,
& V_175 ) ;
if ( ! V_6 ) {
error = - V_49 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_46 ) ;
goto V_304;
}
ASSERT ( V_311 -> V_314 & V_335 ) ;
V_309 = F_99 ( V_6 , V_311 -> V_336 ) ;
if ( F_33 ( V_309 -> V_337 != F_130 ( V_240 ) ) ) {
F_98 ( V_23 ,
L_47 ,
V_8 , V_309 , V_6 , V_311 -> V_317 ) ;
F_4 ( L_48 ,
V_121 , V_23 ) ;
error = - V_16 ;
goto V_304;
}
V_330 = V_125 -> V_134 [ 1 ] . V_135 ;
if ( F_33 ( V_330 -> V_337 != V_240 ) ) {
F_98 ( V_23 ,
L_49 ,
V_8 , V_125 , V_311 -> V_317 ) ;
F_4 ( L_50 ,
V_121 , V_23 ) ;
error = - V_16 ;
goto V_304;
}
if ( V_309 -> V_319 >= 3 ) {
T_7 V_190 = F_55 ( V_309 -> V_338 ) ;
if ( V_190 && V_190 != - 1 && F_116 ( V_190 , V_300 ) >= 0 ) {
F_131 ( log , V_311 ) ;
error = 0 ;
goto V_339;
}
}
if ( ! F_94 ( & V_23 -> V_25 ) &&
V_330 -> V_340 < F_103 ( V_309 -> V_340 ) ) {
if ( F_103 ( V_309 -> V_340 ) == V_341 &&
V_330 -> V_340 < ( V_341 >> 1 ) ) {
} else {
F_131 ( log , V_311 ) ;
error = 0 ;
goto V_304;
}
}
V_330 -> V_340 = 0 ;
if ( F_33 ( F_132 ( V_330 -> V_342 ) ) ) {
if ( ( V_330 -> V_343 != V_344 ) &&
( V_330 -> V_343 != V_345 ) ) {
F_133 ( L_51 ,
V_121 , V_23 , V_330 ) ;
F_98 ( V_23 ,
L_52
L_53 ,
V_8 , V_125 , V_309 , V_6 , V_311 -> V_317 ) ;
error = - V_16 ;
goto V_304;
}
} else if ( F_33 ( F_134 ( V_330 -> V_342 ) ) ) {
if ( ( V_330 -> V_343 != V_344 ) &&
( V_330 -> V_343 != V_345 ) &&
( V_330 -> V_343 != V_346 ) ) {
F_133 ( L_54 ,
V_121 , V_23 , V_330 ) ;
F_98 ( V_23 ,
L_55
L_53 ,
V_8 , V_125 , V_309 , V_6 , V_311 -> V_317 ) ;
error = - V_16 ;
goto V_304;
}
}
if ( F_33 ( V_330 -> V_347 + V_330 -> V_348 > V_330 -> V_349 ) ) {
F_133 ( L_56 ,
V_121 , V_23 , V_330 ) ;
F_98 ( V_23 ,
L_57
L_58 ,
V_8 , V_125 , V_309 , V_6 , V_311 -> V_317 ,
V_330 -> V_347 + V_330 -> V_348 ,
V_330 -> V_349 ) ;
error = - V_16 ;
goto V_304;
}
if ( F_33 ( V_330 -> V_350 > V_23 -> V_25 . V_177 ) ) {
F_133 ( L_59 ,
V_121 , V_23 , V_330 ) ;
F_98 ( V_23 ,
L_57
L_60 , V_8 ,
V_125 , V_309 , V_6 , V_311 -> V_317 , V_330 -> V_350 ) ;
error = - V_16 ;
goto V_304;
}
V_331 = F_135 ( V_330 -> V_319 ) ;
if ( F_33 ( V_125 -> V_134 [ 1 ] . V_183 > V_331 ) ) {
F_133 ( L_61 ,
V_121 , V_23 , V_330 ) ;
F_98 ( V_23 ,
L_62 ,
V_8 , V_125 -> V_134 [ 1 ] . V_183 , V_125 ) ;
error = - V_16 ;
goto V_304;
}
F_136 ( V_309 , V_330 ) ;
if ( V_125 -> V_134 [ 1 ] . V_183 > V_331 ) {
memcpy ( ( char * ) V_309 + V_331 ,
V_125 -> V_134 [ 1 ] . V_135 + V_331 ,
V_125 -> V_134 [ 1 ] . V_183 - V_331 ) ;
}
V_329 = V_311 -> V_314 ;
switch ( V_329 & ( V_351 | V_352 ) ) {
case V_351 :
F_137 ( V_309 , V_311 -> V_353 . V_354 ) ;
break;
case V_352 :
memcpy ( F_138 ( V_309 ) ,
& V_311 -> V_353 . V_355 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_311 -> V_356 == 2 )
goto V_339;
V_160 = V_125 -> V_134 [ 2 ] . V_183 ;
V_326 = V_125 -> V_134 [ 2 ] . V_135 ;
ASSERT ( V_311 -> V_356 <= 4 ) ;
ASSERT ( ( V_311 -> V_356 == 3 ) || ( V_329 & V_357 ) ) ;
ASSERT ( ! ( V_329 & V_358 ) ||
( V_160 == V_311 -> V_359 ) ) ;
switch ( V_329 & V_358 ) {
case V_360 :
case V_361 :
memcpy ( F_138 ( V_309 ) , V_326 , V_160 ) ;
break;
case V_321 :
F_139 ( V_23 , (struct V_198 * ) V_326 , V_160 ,
( V_362 * ) F_138 ( V_309 ) ,
F_140 ( V_309 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_329 & V_358 ) == 0 ) ;
break;
}
if ( V_311 -> V_314 & V_357 ) {
if ( V_311 -> V_314 & V_358 ) {
V_328 = 3 ;
} else {
V_328 = 2 ;
}
V_160 = V_125 -> V_134 [ V_328 ] . V_183 ;
V_326 = V_125 -> V_134 [ V_328 ] . V_135 ;
ASSERT ( V_160 == V_311 -> V_363 ) ;
switch ( V_311 -> V_314 & V_357 ) {
case V_364 :
case V_365 :
V_327 = F_141 ( V_309 ) ;
ASSERT ( V_160 <= F_142 ( V_309 , V_23 ) ) ;
memcpy ( V_327 , V_326 , V_160 ) ;
break;
case V_324 :
V_327 = F_141 ( V_309 ) ;
F_139 ( V_23 , (struct V_198 * ) V_326 ,
V_160 , ( V_362 * ) V_327 ,
F_142 ( V_309 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_63 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
goto V_304;
}
}
V_339:
if ( V_311 -> V_314 & ( V_315 | V_316 ) )
error = F_120 ( V_23 , V_309 , V_311 ,
V_129 ) ;
F_100 ( log -> V_7 , V_309 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_119 ( V_6 , V_129 ) ;
V_304:
F_27 ( V_6 ) ;
error:
if ( V_332 )
F_91 ( V_311 ) ;
return error ;
}
STATIC int
F_143 (
struct V_1 * log ,
struct V_147 * V_125 )
{
T_16 * V_366 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( V_366 ) ;
if ( V_366 -> V_367 & V_368 )
log -> V_299 |= V_296 ;
if ( V_366 -> V_367 & V_369 )
log -> V_299 |= V_297 ;
if ( V_366 -> V_367 & V_370 )
log -> V_299 |= V_298 ;
return 0 ;
}
STATIC int
F_144 (
struct V_1 * log ,
struct V_148 * V_129 ,
struct V_147 * V_125 ,
T_7 V_300 )
{
T_3 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_371 * V_372 , * V_373 ;
int error ;
T_17 * V_374 ;
T_5 type ;
if ( V_23 -> V_295 == 0 )
return 0 ;
V_373 = V_125 -> V_134 [ 1 ] . V_135 ;
if ( V_373 == NULL ) {
F_98 ( log -> V_7 , L_64 , V_8 ) ;
return - V_58 ;
}
if ( V_125 -> V_134 [ 1 ] . V_183 < sizeof( V_291 ) ) {
F_98 ( log -> V_7 , L_65 ,
V_125 -> V_134 [ 1 ] . V_183 , V_8 ) ;
return - V_58 ;
}
type = V_373 -> V_375 & ( V_296 | V_297 | V_298 ) ;
ASSERT ( type ) ;
if ( log -> V_299 & type )
return 0 ;
V_374 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( V_374 ) ;
error = F_109 ( V_23 , V_373 , V_374 -> V_376 , 0 , V_292 ,
L_66 ) ;
if ( error )
return - V_58 ;
ASSERT ( V_374 -> V_377 == 1 ) ;
error = F_145 ( V_23 , NULL , V_23 -> V_303 , V_374 -> V_378 ,
F_146 ( V_23 , V_374 -> V_377 ) , 0 , & V_6 ,
& V_257 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_372 = F_99 ( V_6 , V_374 -> V_379 ) ;
if ( F_94 ( & V_23 -> V_25 ) ) {
struct V_380 * V_381 = (struct V_380 * ) V_372 ;
T_7 V_190 = F_55 ( V_381 -> V_382 ) ;
if ( V_190 && V_190 != - 1 && F_116 ( V_190 , V_300 ) >= 0 ) {
goto V_304;
}
}
memcpy ( V_372 , V_373 , V_125 -> V_134 [ 1 ] . V_183 ) ;
if ( F_94 ( & V_23 -> V_25 ) ) {
F_147 ( ( char * ) V_372 , sizeof( struct V_380 ) ,
V_383 ) ;
}
ASSERT ( V_374 -> V_384 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_119 ( V_6 , V_129 ) ;
V_304:
F_27 ( V_6 ) ;
return 0 ;
}
STATIC int
F_148 (
struct V_1 * log ,
struct V_147 * V_125 ,
T_7 V_190 )
{
int error ;
struct V_163 * V_23 = log -> V_7 ;
struct V_385 * V_386 ;
struct V_387 * V_388 ;
V_388 = V_125 -> V_134 [ 0 ] . V_135 ;
V_386 = F_149 ( V_23 , V_388 -> V_389 ) ;
error = F_150 ( & V_125 -> V_134 [ 0 ] , & V_386 -> V_390 ) ;
if ( error ) {
F_151 ( V_386 ) ;
return error ;
}
F_152 ( & V_386 -> V_391 , V_388 -> V_389 ) ;
F_153 ( & log -> V_392 -> V_393 ) ;
F_154 ( log -> V_392 , & V_386 -> V_394 , V_190 ) ;
F_155 ( V_386 ) ;
return 0 ;
}
STATIC int
F_156 (
struct V_1 * log ,
struct V_147 * V_125 )
{
T_18 * V_395 ;
T_19 * V_386 = NULL ;
T_20 * V_396 ;
T_21 V_397 ;
struct V_398 V_399 ;
struct V_400 * V_401 = log -> V_392 ;
V_395 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( ( V_125 -> V_134 [ 0 ] . V_183 == ( sizeof( V_402 ) +
( ( V_395 -> V_403 - 1 ) * sizeof( V_404 ) ) ) ) ||
( V_125 -> V_134 [ 0 ] . V_183 == ( sizeof( V_405 ) +
( ( V_395 -> V_403 - 1 ) * sizeof( V_406 ) ) ) ) ) ;
V_397 = V_395 -> V_407 ;
F_153 ( & V_401 -> V_393 ) ;
V_396 = F_157 ( V_401 , & V_399 , 0 ) ;
while ( V_396 != NULL ) {
if ( V_396 -> V_408 == V_146 ) {
V_386 = ( T_19 * ) V_396 ;
if ( V_386 -> V_390 . V_397 == V_397 ) {
F_158 ( & V_401 -> V_393 ) ;
F_155 ( V_386 ) ;
F_153 ( & V_401 -> V_393 ) ;
break;
}
}
V_396 = F_159 ( V_401 , & V_399 ) ;
}
F_160 ( & V_399 ) ;
F_158 ( & V_401 -> V_393 ) ;
return 0 ;
}
STATIC int
F_161 (
struct V_1 * log ,
struct V_148 * V_129 ,
T_8 * V_125 )
{
struct V_163 * V_23 = log -> V_7 ;
struct V_409 * V_410 ;
T_22 V_411 ;
T_23 V_412 ;
unsigned int V_413 ;
unsigned int V_331 ;
T_23 V_414 ;
int V_415 ;
int V_416 ;
int V_417 ;
int V_418 ;
int V_45 ;
V_410 = (struct V_409 * ) V_125 -> V_134 [ 0 ] . V_135 ;
if ( V_410 -> V_419 != V_136 ) {
F_3 ( log -> V_7 , L_67 ) ;
return - V_102 ;
}
if ( V_410 -> V_420 != 1 ) {
F_3 ( log -> V_7 , L_68 ) ;
return - V_102 ;
}
V_411 = F_30 ( V_410 -> V_421 ) ;
if ( V_411 >= V_23 -> V_25 . V_422 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_102 ;
}
V_412 = F_30 ( V_410 -> V_423 ) ;
if ( ! V_412 || V_412 == V_424 || V_412 >= V_23 -> V_25 . V_425 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_102 ;
}
V_331 = F_30 ( V_410 -> V_426 ) ;
if ( V_331 != V_23 -> V_25 . V_177 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_102 ;
}
V_413 = F_30 ( V_410 -> V_427 ) ;
if ( ! V_413 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_102 ;
}
V_414 = F_30 ( V_410 -> V_428 ) ;
if ( ! V_414 || V_414 >= V_23 -> V_25 . V_425 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_102 ;
}
if ( V_414 != V_23 -> V_429 &&
V_414 != V_23 -> V_430 ) {
F_3 ( log -> V_7 ,
L_74 , V_431 ) ;
return - V_102 ;
}
if ( ( V_413 >> V_23 -> V_25 . V_432 ) != V_414 ) {
F_3 ( log -> V_7 ,
L_75 ,
V_431 ) ;
return - V_102 ;
}
V_415 = F_162 ( V_23 ) ;
V_416 = F_146 ( V_23 , V_415 ) ;
V_418 = V_414 / V_415 ;
for ( V_45 = 0 , V_417 = 0 ; V_45 < V_418 ; V_45 ++ ) {
T_2 V_433 ;
V_433 = F_163 ( V_23 , V_411 ,
V_412 + V_45 * V_415 ) ;
if ( F_89 ( log , V_433 , V_416 , 0 ) )
V_417 ++ ;
}
ASSERT ( ! V_417 || V_417 == V_418 ) ;
if ( V_417 ) {
if ( V_417 != V_418 )
F_3 ( V_23 ,
L_76 ) ;
F_164 ( log , V_410 ) ;
return 0 ;
}
F_165 ( log , V_410 ) ;
return F_166 ( V_23 , NULL , V_129 , V_413 , V_411 , V_412 ,
V_414 , F_30 ( V_410 -> V_434 ) ) ;
}
STATIC void
F_167 (
struct V_1 * log ,
struct V_147 * V_125 )
{
struct V_294 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
struct V_163 * V_23 = log -> V_7 ;
if ( F_88 ( log , V_133 -> V_152 ,
V_133 -> V_155 , V_133 -> V_139 ) ) {
return;
}
F_168 ( V_23 -> V_303 , V_133 -> V_152 ,
V_133 -> V_155 , NULL ) ;
}
STATIC void
F_169 (
struct V_1 * log ,
struct V_147 * V_125 )
{
struct V_310 V_435 ;
struct V_310 * V_436 ;
struct V_163 * V_23 = log -> V_7 ;
int error ;
if ( V_125 -> V_134 [ 0 ] . V_183 == sizeof( struct V_310 ) ) {
V_436 = V_125 -> V_134 [ 0 ] . V_135 ;
} else {
V_436 = & V_435 ;
memset ( V_436 , 0 , sizeof( * V_436 ) ) ;
error = F_127 ( & V_125 -> V_134 [ 0 ] , V_436 ) ;
if ( error )
return;
}
if ( F_88 ( log , V_436 -> V_333 , V_436 -> V_334 , 0 ) )
return;
F_168 ( V_23 -> V_303 , V_436 -> V_333 ,
V_436 -> V_334 , & V_437 ) ;
}
STATIC void
F_170 (
struct V_1 * log ,
struct V_147 * V_125 )
{
struct V_163 * V_23 = log -> V_7 ;
struct V_371 * V_373 ;
struct V_438 * V_374 ;
T_5 type ;
if ( V_23 -> V_295 == 0 )
return;
V_373 = V_125 -> V_134 [ 1 ] . V_135 ;
if ( V_373 == NULL )
return;
if ( V_125 -> V_134 [ 1 ] . V_183 < sizeof( struct V_371 ) )
return;
type = V_373 -> V_375 & ( V_296 | V_297 | V_298 ) ;
ASSERT ( type ) ;
if ( log -> V_299 & type )
return;
V_374 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( V_374 ) ;
ASSERT ( V_374 -> V_377 == 1 ) ;
F_168 ( V_23 -> V_303 , V_374 -> V_378 ,
F_146 ( V_23 , V_374 -> V_377 ) , NULL ) ;
}
STATIC void
F_171 (
struct V_1 * log ,
struct V_147 * V_125 )
{
switch ( F_72 ( V_125 ) ) {
case V_138 :
F_167 ( log , V_125 ) ;
break;
case V_142 :
F_169 ( log , V_125 ) ;
break;
case V_143 :
F_170 ( log , V_125 ) ;
break;
case V_146 :
case V_145 :
case V_144 :
default:
break;
}
}
STATIC int
F_172 (
struct V_1 * log ,
struct V_122 * V_123 ,
struct V_147 * V_125 )
{
F_173 ( log , V_123 , V_125 , V_439 ) ;
switch ( F_72 ( V_125 ) ) {
case V_138 :
return F_80 ( log , V_125 ) ;
case V_144 :
return F_143 ( log , V_125 ) ;
case V_142 :
case V_146 :
case V_145 :
case V_143 :
case V_136 :
return 0 ;
default:
F_3 ( log -> V_7 , L_77 ,
V_8 , F_72 ( V_125 ) ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
}
STATIC int
F_174 (
struct V_1 * log ,
struct V_122 * V_123 ,
struct V_148 * V_129 ,
struct V_147 * V_125 )
{
F_173 ( log , V_123 , V_125 , V_440 ) ;
switch ( F_72 ( V_125 ) ) {
case V_138 :
return F_112 ( log , V_129 , V_125 ,
V_123 -> V_441 ) ;
case V_142 :
return F_126 ( log , V_129 , V_125 ,
V_123 -> V_441 ) ;
case V_146 :
return F_148 ( log , V_125 , V_123 -> V_441 ) ;
case V_145 :
return F_156 ( log , V_125 ) ;
case V_143 :
return F_144 ( log , V_129 , V_125 ,
V_123 -> V_441 ) ;
case V_136 :
return F_161 ( log , V_129 , V_125 ) ;
case V_144 :
return 0 ;
default:
F_3 ( log -> V_7 , L_77 ,
V_8 , F_72 ( V_125 ) ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
}
STATIC int
F_175 (
struct V_1 * log ,
struct V_122 * V_123 ,
struct V_148 * V_129 ,
struct V_148 * V_442 )
{
struct V_147 * V_125 ;
int error = 0 ;
F_83 (item, item_list, ri_list) {
error = F_174 ( log , V_123 ,
V_129 , V_125 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_176 (
struct V_1 * log ,
struct V_122 * V_123 ,
int V_124 )
{
int error = 0 ;
int V_22 ;
int V_443 = 0 ;
struct V_147 * V_125 ;
struct V_147 * V_290 ;
F_69 ( V_129 ) ;
F_69 ( V_444 ) ;
F_69 ( V_445 ) ;
#define F_177 100
F_178 ( & V_123 -> V_446 ) ;
error = F_68 ( log , V_123 , V_124 ) ;
if ( error )
return error ;
F_71 (item, next, &trans->r_itemq, ri_list) {
switch ( V_124 ) {
case V_439 :
error = F_172 ( log , V_123 , V_125 ) ;
break;
case V_440 :
F_171 ( log , V_125 ) ;
F_73 ( & V_125 -> V_137 , & V_444 ) ;
V_443 ++ ;
if ( V_443 >= F_177 ) {
error = F_175 ( log , V_123 ,
& V_129 , & V_444 ) ;
F_179 ( & V_444 , & V_445 ) ;
V_443 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
V_51:
if ( ! F_77 ( & V_444 ) ) {
if ( ! error )
error = F_175 ( log , V_123 ,
& V_129 , & V_444 ) ;
F_179 ( & V_444 , & V_445 ) ;
}
if ( ! F_77 ( & V_445 ) )
F_70 ( & V_445 , & V_123 -> V_132 ) ;
V_22 = F_180 ( & V_129 ) ;
return error ? error : V_22 ;
}
STATIC void
F_181 (
struct V_148 * V_24 )
{
T_8 * V_125 ;
V_125 = F_182 ( sizeof( T_8 ) , V_157 ) ;
F_183 ( & V_125 -> V_137 ) ;
F_86 ( & V_125 -> V_137 , V_24 ) ;
}
STATIC int
F_184 (
struct V_1 * log ,
struct V_122 * V_123 ,
char * V_447 ,
int V_160 )
{
T_8 * V_125 ;
char * V_448 , * V_449 ;
int V_450 ;
if ( F_77 ( & V_123 -> V_132 ) ) {
ASSERT ( V_160 < sizeof( struct V_451 ) ) ;
if ( V_160 > sizeof( struct V_451 ) ) {
F_3 ( log -> V_7 , L_78 , V_8 ) ;
return - V_58 ;
}
F_181 ( & V_123 -> V_132 ) ;
V_448 = ( char * ) & V_123 -> V_452 +
sizeof( struct V_451 ) - V_160 ;
memcpy ( V_448 , V_447 , V_160 ) ;
return 0 ;
}
V_125 = F_185 ( V_123 -> V_132 . V_453 , T_8 , V_137 ) ;
V_449 = V_125 -> V_134 [ V_125 -> V_454 - 1 ] . V_135 ;
V_450 = V_125 -> V_134 [ V_125 -> V_454 - 1 ] . V_183 ;
V_448 = F_186 ( V_449 , V_160 + V_450 , V_450 , V_157 ) ;
memcpy ( & V_448 [ V_450 ] , V_447 , V_160 ) ;
V_125 -> V_134 [ V_125 -> V_454 - 1 ] . V_183 += V_160 ;
V_125 -> V_134 [ V_125 -> V_454 - 1 ] . V_135 = V_448 ;
F_187 ( log , V_123 , V_125 , 0 ) ;
return 0 ;
}
STATIC int
F_188 (
struct V_1 * log ,
struct V_122 * V_123 ,
char * V_447 ,
int V_160 )
{
T_14 * V_311 ;
T_8 * V_125 ;
char * V_448 ;
if ( ! V_160 )
return 0 ;
if ( F_77 ( & V_123 -> V_132 ) ) {
if ( * ( T_5 * ) V_447 != V_455 ) {
F_3 ( log -> V_7 , L_79 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
if ( V_160 > sizeof( struct V_451 ) ) {
F_3 ( log -> V_7 , L_78 , V_8 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
if ( V_160 == sizeof( struct V_451 ) )
F_181 ( & V_123 -> V_132 ) ;
memcpy ( & V_123 -> V_452 , V_447 , V_160 ) ;
return 0 ;
}
V_448 = F_85 ( V_160 , V_157 ) ;
memcpy ( V_448 , V_447 , V_160 ) ;
V_311 = ( T_14 * ) V_448 ;
V_125 = F_185 ( V_123 -> V_132 . V_453 , T_8 , V_137 ) ;
if ( V_125 -> V_293 != 0 &&
V_125 -> V_293 == V_125 -> V_454 ) {
F_181 ( & V_123 -> V_132 ) ;
V_125 = F_185 ( V_123 -> V_132 . V_453 ,
T_8 , V_137 ) ;
}
if ( V_125 -> V_293 == 0 ) {
if ( V_311 -> V_356 == 0 ||
V_311 -> V_356 > V_456 ) {
F_3 ( log -> V_7 ,
L_80 ,
V_311 -> V_356 ) ;
ASSERT ( 0 ) ;
F_91 ( V_448 ) ;
return - V_58 ;
}
V_125 -> V_293 = V_311 -> V_356 ;
V_125 -> V_134 =
F_182 ( V_125 -> V_293 * sizeof( V_457 ) ,
V_157 ) ;
}
ASSERT ( V_125 -> V_293 > V_125 -> V_454 ) ;
V_125 -> V_134 [ V_125 -> V_454 ] . V_135 = V_448 ;
V_125 -> V_134 [ V_125 -> V_454 ] . V_183 = V_160 ;
V_125 -> V_454 ++ ;
F_189 ( log , V_123 , V_125 , 0 ) ;
return 0 ;
}
STATIC void
F_190 (
struct V_122 * V_123 )
{
T_8 * V_125 , * V_126 ;
int V_45 ;
F_71 (item, n, &trans->r_itemq, ri_list) {
F_90 ( & V_125 -> V_137 ) ;
for ( V_45 = 0 ; V_45 < V_125 -> V_454 ; V_45 ++ )
F_91 ( V_125 -> V_134 [ V_45 ] . V_135 ) ;
F_91 ( V_125 -> V_134 ) ;
F_91 ( V_125 ) ;
}
F_91 ( V_123 ) ;
}
STATIC int
F_191 (
struct V_1 * log ,
struct V_122 * V_123 ,
char * V_447 ,
unsigned int V_160 ,
unsigned int V_161 ,
int V_124 )
{
int error = 0 ;
bool V_458 = false ;
V_161 &= ~ V_459 ;
if ( V_161 & V_460 )
V_161 &= ~ V_461 ;
switch ( V_161 ) {
case 0 :
case V_461 :
error = F_188 ( log , V_123 , V_447 , V_160 ) ;
break;
case V_460 :
error = F_184 ( log , V_123 , V_447 , V_160 ) ;
break;
case V_462 :
error = F_176 ( log , V_123 , V_124 ) ;
V_458 = true ;
break;
case V_97 :
F_3 ( log -> V_7 , L_81 , V_8 ) ;
V_458 = true ;
break;
case V_463 :
default:
F_3 ( log -> V_7 , L_82 , V_8 , V_161 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
break;
}
if ( error || V_458 )
F_190 ( V_123 ) ;
return error ;
}
STATIC struct V_122 *
F_192 (
struct V_464 V_465 [] ,
struct V_466 * V_73 ,
struct V_467 * V_468 )
{
struct V_122 * V_123 ;
T_24 V_469 ;
struct V_464 * V_470 ;
V_469 = F_30 ( V_468 -> V_471 ) ;
V_470 = & V_465 [ F_193 ( V_469 ) ] ;
F_194 (trans, rhp, r_list) {
if ( V_123 -> V_472 == V_469 )
return V_123 ;
}
if ( ! ( V_468 -> V_96 & V_463 ) )
return NULL ;
ASSERT ( F_30 ( V_468 -> V_473 ) == 0 ) ;
V_123 = F_182 ( sizeof( struct V_122 ) , V_157 ) ;
V_123 -> V_472 = V_469 ;
V_123 -> V_441 = F_55 ( V_73 -> V_89 ) ;
F_183 ( & V_123 -> V_132 ) ;
F_195 ( & V_123 -> V_446 ) ;
F_196 ( & V_123 -> V_446 , V_470 ) ;
return NULL ;
}
STATIC int
F_197 (
struct V_1 * log ,
struct V_464 V_465 [] ,
struct V_466 * V_73 ,
struct V_467 * V_468 ,
char * V_447 ,
char * V_474 ,
int V_124 )
{
struct V_122 * V_123 ;
unsigned int V_160 ;
if ( V_468 -> V_475 != V_476 &&
V_468 -> V_475 != V_477 ) {
F_3 ( log -> V_7 , L_83 ,
V_8 , V_468 -> V_475 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
V_160 = F_30 ( V_468 -> V_473 ) ;
if ( V_447 + V_160 > V_474 ) {
F_3 ( log -> V_7 , L_84 , V_8 , V_160 ) ;
F_198 ( 1 ) ;
return - V_58 ;
}
V_123 = F_192 ( V_465 , V_73 , V_468 ) ;
if ( ! V_123 ) {
return 0 ;
}
return F_191 ( log , V_123 , V_447 , V_160 ,
V_468 -> V_96 , V_124 ) ;
}
STATIC int
F_199 (
struct V_1 * log ,
struct V_464 V_465 [] ,
struct V_466 * V_73 ,
char * V_447 ,
int V_124 )
{
struct V_467 * V_468 ;
char * V_474 ;
int V_478 ;
int error ;
V_474 = V_447 + F_30 ( V_73 -> V_61 ) ;
V_478 = F_30 ( V_73 -> V_95 ) ;
if ( F_31 ( log -> V_7 , V_73 ) )
return - V_58 ;
while ( ( V_447 < V_474 ) && V_478 ) {
V_468 = (struct V_467 * ) V_447 ;
V_447 += sizeof( * V_468 ) ;
ASSERT ( V_447 <= V_474 ) ;
error = F_197 ( log , V_465 , V_73 , V_468 ,
V_447 , V_474 , V_124 ) ;
if ( error )
return error ;
V_447 += F_30 ( V_468 -> V_473 ) ;
V_478 -- ;
}
return 0 ;
}
STATIC int
F_200 (
T_3 * V_23 ,
T_19 * V_386 )
{
T_25 * V_479 ;
T_26 * V_480 ;
int V_45 ;
int error = 0 ;
T_27 * V_481 ;
T_28 V_482 ;
ASSERT ( ! F_201 ( V_483 , & V_386 -> V_484 ) ) ;
for ( V_45 = 0 ; V_45 < V_386 -> V_390 . V_389 ; V_45 ++ ) {
V_481 = & ( V_386 -> V_390 . V_485 [ V_45 ] ) ;
V_482 = F_202 ( V_23 ,
F_203 ( V_23 , V_481 -> V_486 ) ) ;
if ( ( V_482 == 0 ) ||
( V_481 -> V_487 == 0 ) ||
( V_482 >= V_23 -> V_25 . V_488 ) ||
( V_481 -> V_487 >= V_23 -> V_25 . V_425 ) ) {
F_204 ( V_483 , & V_386 -> V_484 ) ;
F_155 ( V_386 ) ;
return - V_58 ;
}
}
V_480 = F_205 ( V_23 , 0 ) ;
error = F_206 ( V_480 , & F_207 ( V_23 ) -> V_489 , 0 , 0 ) ;
if ( error )
goto V_490;
V_479 = F_208 ( V_480 , V_386 , V_386 -> V_390 . V_389 ) ;
for ( V_45 = 0 ; V_45 < V_386 -> V_390 . V_389 ; V_45 ++ ) {
V_481 = & ( V_386 -> V_390 . V_485 [ V_45 ] ) ;
error = F_209 ( V_480 , V_479 , V_481 -> V_486 ,
V_481 -> V_487 ) ;
if ( error )
goto V_490;
}
F_204 ( V_483 , & V_386 -> V_484 ) ;
error = F_210 ( V_480 ) ;
return error ;
V_490:
F_211 ( V_480 ) ;
return error ;
}
STATIC int
F_212 (
struct V_1 * log )
{
struct V_491 * V_396 ;
struct V_385 * V_386 ;
int error = 0 ;
struct V_398 V_399 ;
struct V_400 * V_401 ;
V_401 = log -> V_392 ;
F_153 ( & V_401 -> V_393 ) ;
V_396 = F_157 ( V_401 , & V_399 , 0 ) ;
while ( V_396 != NULL ) {
if ( V_396 -> V_408 != V_146 ) {
#ifdef F_213
for (; V_396 ; V_396 = F_159 ( V_401 , & V_399 ) )
ASSERT ( V_396 -> V_408 != V_146 ) ;
#endif
break;
}
V_386 = F_214 ( V_396 , struct V_385 , V_394 ) ;
if ( F_201 ( V_483 , & V_386 -> V_484 ) ) {
V_396 = F_159 ( V_401 , & V_399 ) ;
continue;
}
F_158 ( & V_401 -> V_393 ) ;
error = F_200 ( log -> V_7 , V_386 ) ;
F_153 ( & V_401 -> V_393 ) ;
if ( error )
goto V_51;
V_396 = F_159 ( V_401 , & V_399 ) ;
}
V_51:
F_160 ( & V_399 ) ;
F_158 ( & V_401 -> V_393 ) ;
return error ;
}
STATIC int
F_215 (
struct V_1 * log )
{
struct V_491 * V_396 ;
struct V_385 * V_386 ;
int error = 0 ;
struct V_398 V_399 ;
struct V_400 * V_401 ;
V_401 = log -> V_392 ;
F_153 ( & V_401 -> V_393 ) ;
V_396 = F_157 ( V_401 , & V_399 , 0 ) ;
while ( V_396 != NULL ) {
if ( V_396 -> V_408 != V_146 ) {
#ifdef F_213
for (; V_396 ; V_396 = F_159 ( V_401 , & V_399 ) )
ASSERT ( V_396 -> V_408 != V_146 ) ;
#endif
break;
}
V_386 = F_214 ( V_396 , struct V_385 , V_394 ) ;
F_158 ( & V_401 -> V_393 ) ;
F_155 ( V_386 ) ;
F_153 ( & V_401 -> V_393 ) ;
V_396 = F_159 ( V_401 , & V_399 ) ;
}
F_160 ( & V_399 ) ;
F_158 ( & V_401 -> V_393 ) ;
return error ;
}
STATIC void
F_216 (
T_3 * V_23 ,
T_22 V_411 ,
int V_149 )
{
T_26 * V_480 ;
T_29 * V_492 ;
T_1 * V_493 ;
int V_13 ;
int error ;
V_480 = F_205 ( V_23 , V_494 ) ;
error = F_206 ( V_480 , & F_207 ( V_23 ) -> V_495 , 0 , 0 ) ;
if ( error )
goto V_496;
error = F_217 ( V_23 , V_480 , V_411 , & V_493 ) ;
if ( error )
goto V_496;
V_492 = F_218 ( V_493 ) ;
V_492 -> V_497 [ V_149 ] = F_32 ( V_498 ) ;
V_13 = F_95 ( T_29 , V_497 ) +
( sizeof( T_11 ) * V_149 ) ;
F_219 ( V_480 , V_493 , V_13 ,
( V_13 + sizeof( T_11 ) - 1 ) ) ;
error = F_210 ( V_480 ) ;
if ( error )
goto V_499;
return;
V_496:
F_211 ( V_480 ) ;
V_499:
F_3 ( V_23 , L_85 , V_8 , V_411 ) ;
return;
}
STATIC T_11
F_220 (
struct V_163 * V_23 ,
T_22 V_411 ,
T_11 V_500 ,
int V_149 )
{
struct V_5 * V_501 ;
struct V_308 * V_309 ;
struct V_312 * V_313 ;
T_30 V_502 ;
int error ;
V_502 = F_221 ( V_23 , V_411 , V_500 ) ;
error = F_222 ( V_23 , NULL , V_502 , 0 , 0 , & V_313 ) ;
if ( error )
goto V_503;
error = F_223 ( V_23 , NULL , & V_313 -> V_504 , & V_309 , & V_501 , 0 , 0 ) ;
if ( error )
goto V_505;
ASSERT ( V_313 -> V_318 . V_506 == 0 ) ;
ASSERT ( V_313 -> V_318 . V_342 != 0 ) ;
V_500 = F_30 ( V_309 -> V_179 ) ;
F_27 ( V_501 ) ;
V_313 -> V_318 . V_507 = 0 ;
F_224 ( V_313 ) ;
return V_500 ;
V_505:
F_224 ( V_313 ) ;
V_503:
F_216 ( V_23 , V_411 , V_149 ) ;
return V_498 ;
}
STATIC void
F_225 (
struct V_1 * log )
{
T_3 * V_23 ;
T_22 V_411 ;
T_29 * V_492 ;
T_1 * V_493 ;
T_11 V_500 ;
int V_149 ;
int error ;
T_5 V_508 ;
V_23 = log -> V_7 ;
V_508 = V_23 -> V_509 ;
V_23 -> V_509 = 0 ;
for ( V_411 = 0 ; V_411 < V_23 -> V_25 . V_422 ; V_411 ++ ) {
error = F_217 ( V_23 , NULL , V_411 , & V_493 ) ;
if ( error ) {
continue;
}
V_492 = F_218 ( V_493 ) ;
F_7 ( V_493 ) ;
for ( V_149 = 0 ; V_149 < V_510 ; V_149 ++ ) {
V_500 = F_30 ( V_492 -> V_497 [ V_149 ] ) ;
while ( V_500 != V_498 ) {
V_500 = F_220 ( V_23 ,
V_411 , V_500 , V_149 ) ;
}
}
F_226 ( V_493 ) ;
}
V_23 -> V_509 = V_508 ;
}
STATIC int
F_227 (
struct V_466 * V_73 ,
char * V_447 ,
struct V_1 * log )
{
T_31 V_511 ;
V_511 = F_228 ( log , V_73 , V_447 , F_30 ( V_73 -> V_61 ) ) ;
if ( V_511 != V_73 -> V_512 ) {
if ( V_73 -> V_512 || F_94 ( & log -> V_7 -> V_25 ) ) {
F_98 ( log -> V_7 ,
L_86 ,
F_229 ( V_73 -> V_512 ) ,
F_229 ( V_511 ) ) ;
F_230 ( V_447 , 32 ) ;
}
if ( F_94 ( & log -> V_7 -> V_25 ) )
return - V_16 ;
}
return 0 ;
}
STATIC int
F_231 (
struct V_466 * V_73 ,
char * V_447 ,
struct V_1 * log )
{
int V_45 , V_46 , V_513 ;
int error ;
error = F_227 ( V_73 , V_447 , log ) ;
if ( error )
return error ;
for ( V_45 = 0 ; V_45 < F_48 ( F_30 ( V_73 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_81 * ) V_447 = * ( V_81 * ) & V_73 -> V_514 [ V_45 ] ;
V_447 += V_52 ;
}
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
T_32 * V_515 = ( T_32 * ) V_73 ;
for ( ; V_45 < F_48 ( F_30 ( V_73 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_513 = V_45 % ( V_60 / V_52 ) ;
* ( V_81 * ) V_447 = V_515 [ V_46 ] . V_516 . V_517 [ V_513 ] ;
V_447 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_232 (
struct V_1 * log ,
struct V_466 * V_73 ,
T_2 V_159 )
{
int V_518 ;
if ( F_33 ( V_73 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_87 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_33 (
( ! V_73 -> V_93 ||
( F_30 ( V_73 -> V_93 ) & ( ~ V_519 ) ) ) ) ) {
F_3 ( log -> V_7 , L_88 ,
V_8 , F_30 ( V_73 -> V_93 ) ) ;
return - V_58 ;
}
V_518 = F_30 ( V_73 -> V_61 ) ;
if ( F_33 ( V_518 <= 0 || V_518 > V_70 ) ) {
F_4 ( L_89 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_33 ( V_159 > log -> V_3 || V_159 > V_70 ) ) {
F_4 ( L_90 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_233 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 ,
int V_124 )
{
T_4 * V_73 ;
T_2 V_12 ;
char * V_13 ;
T_1 * V_520 , * V_521 ;
int error = 0 , V_59 ;
int V_522 , V_523 ;
int V_79 , V_524 , V_525 ;
struct V_464 V_465 [ V_526 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
V_520 = F_2 ( log , 1 ) ;
if ( ! V_520 )
return - V_49 ;
error = F_19 ( log , V_72 , 1 , V_520 , & V_13 ) ;
if ( error )
goto V_527;
V_73 = ( T_4 * ) V_13 ;
error = F_232 ( log , V_73 , V_72 ) ;
if ( error )
goto V_527;
V_59 = F_30 ( V_73 -> V_59 ) ;
if ( ( F_30 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_520 ) ;
V_520 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_520 = F_2 ( log , 1 ) ;
V_59 = V_528 ;
}
if ( ! V_520 )
return - V_49 ;
V_521 = F_2 ( log , F_48 ( V_59 ) ) ;
if ( ! V_521 ) {
F_8 ( V_520 ) ;
return - V_49 ;
}
memset ( V_465 , 0 , sizeof( V_465 ) ) ;
V_12 = V_72 ;
if ( V_72 > V_63 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_520 -> V_15 ;
V_524 = 0 ;
V_525 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_79 , V_520 ,
& V_13 ) ;
if ( error )
goto V_529;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_524 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_524 > 0 ) ;
error = F_19 ( log , V_12 ,
V_524 , V_520 ,
& V_13 ) ;
if ( error )
goto V_529;
}
V_525 = V_79 - V_524 ;
error = F_20 ( log , 0 ,
V_525 , V_520 ,
V_13 + F_11 ( V_524 ) ) ;
if ( error )
goto V_529;
}
V_73 = ( T_4 * ) V_13 ;
error = F_232 ( log , V_73 ,
V_524 ? V_12 : 0 ) ;
if ( error )
goto V_529;
V_522 = ( int ) F_48 ( F_30 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_522 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_522 , V_521 ,
& V_13 ) ;
if ( error )
goto V_529;
} else {
V_13 = V_521 -> V_15 ;
V_523 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_525 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_523 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_523 > 0 ) ;
error = F_19 ( log , V_12 ,
V_523 , V_521 ,
& V_13 ) ;
if ( error )
goto V_529;
}
error = F_20 ( log , 0 ,
V_522 - V_523 , V_521 ,
V_13 + F_11 ( V_523 ) ) ;
if ( error )
goto V_529;
}
error = F_231 ( V_73 , V_13 , log ) ;
if ( error )
goto V_529;
error = F_199 ( log , V_465 ,
V_73 , V_13 , V_124 ) ;
if ( error )
goto V_529;
V_12 += V_522 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
}
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_79 , V_520 , & V_13 ) ;
if ( error )
goto V_529;
V_73 = ( T_4 * ) V_13 ;
error = F_232 ( log , V_73 , V_12 ) ;
if ( error )
goto V_529;
V_522 = ( int ) F_48 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_522 , V_521 ,
& V_13 ) ;
if ( error )
goto V_529;
error = F_231 ( V_73 , V_13 , log ) ;
if ( error )
goto V_529;
error = F_199 ( log , V_465 ,
V_73 , V_13 , V_124 ) ;
if ( error )
goto V_529;
V_12 += V_522 + V_79 ;
}
V_529:
F_8 ( V_521 ) ;
V_527:
F_8 ( V_520 ) ;
return error ;
}
STATIC int
F_234 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_162 = F_182 ( V_530 *
sizeof( struct V_148 ) ,
V_157 ) ;
for ( V_45 = 0 ; V_45 < V_530 ; V_45 ++ )
F_183 ( & log -> V_162 [ V_45 ] ) ;
error = F_233 ( log , V_63 , V_72 ,
V_439 ) ;
if ( error != 0 ) {
F_91 ( log -> V_162 ) ;
log -> V_162 = NULL ;
return error ;
}
error = F_233 ( log , V_63 , V_72 ,
V_440 ) ;
#ifdef F_213
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_530 ; V_45 ++ )
ASSERT ( F_77 ( & log -> V_162 [ V_45 ] ) ) ;
}
#endif
F_91 ( log -> V_162 ) ;
log -> V_162 = NULL ;
return error ;
}
STATIC int
F_235 (
struct V_1 * log ,
T_2 V_63 ,
T_2 V_72 )
{
int error ;
T_1 * V_6 ;
T_33 * V_531 ;
error = F_234 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_17 ( log -> V_7 ) ) {
return - V_58 ;
}
F_236 ( log -> V_7 ) ;
V_6 = F_237 ( log -> V_7 , 0 ) ;
F_238 ( V_6 ) ;
ASSERT ( ! ( F_239 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_240 ( V_6 ) ;
V_6 -> V_174 = & V_286 ;
error = F_16 ( V_6 ) ;
if ( error ) {
if ( ! F_17 ( log -> V_7 ) ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_27 ( V_6 ) ;
return error ;
}
V_531 = & log -> V_7 -> V_25 ;
F_241 ( V_531 , F_242 ( V_6 ) ) ;
ASSERT ( V_531 -> V_532 == V_228 ) ;
ASSERT ( F_243 ( V_531 ) ) ;
F_244 ( log -> V_7 ) ;
F_27 ( V_6 ) ;
F_245 ( log ) ;
log -> V_533 &= ~ V_534 ;
return 0 ;
}
int
V_122 (
struct V_1 * log )
{
T_2 V_63 , V_72 ;
int error ;
if ( ( error = F_53 ( log , & V_63 , & V_72 ) ) )
return error ;
if ( V_72 != V_63 ) {
if ( ( error = F_246 ( log -> V_7 , L_91 ) ) ) {
return error ;
}
if ( F_247 ( & log -> V_7 -> V_25 ) == V_535 &&
F_248 ( & log -> V_7 -> V_25 ,
V_536 ) ) {
F_3 ( log -> V_7 ,
L_92 ,
( log -> V_7 -> V_25 . V_537 &
V_536 ) ) ;
F_3 ( log -> V_7 ,
L_93 ) ;
F_3 ( log -> V_7 ,
L_94 ) ;
return - V_102 ;
}
if ( V_538 . V_539 ) {
F_249 ( log -> V_7 ,
L_95 ,
V_538 . V_539 ) ;
F_250 ( V_538 . V_539 * 1000 ) ;
}
F_249 ( log -> V_7 , L_96 ,
log -> V_7 -> V_540 ? log -> V_7 -> V_540
: L_97 ) ;
error = F_235 ( log , V_63 , V_72 ) ;
log -> V_533 |= V_541 ;
}
return error ;
}
int
F_251 (
struct V_1 * log )
{
if ( log -> V_533 & V_541 ) {
int error ;
error = F_212 ( log ) ;
if ( error ) {
F_98 ( log -> V_7 , L_98 ) ;
return error ;
}
F_252 ( log -> V_7 , V_542 ) ;
F_225 ( log ) ;
F_245 ( log ) ;
F_249 ( log -> V_7 , L_99 ,
log -> V_7 -> V_540 ? log -> V_7 -> V_540
: L_97 ) ;
log -> V_533 &= ~ V_541 ;
} else {
F_253 ( log -> V_7 , L_100 ) ;
}
return 0 ;
}
int
F_254 (
struct V_1 * log )
{
int error = 0 ;
if ( log -> V_533 & V_541 )
error = F_215 ( log ) ;
return error ;
}
void
F_245 (
struct V_1 * log )
{
T_3 * V_23 ;
T_34 * V_543 ;
T_1 * V_544 ;
T_1 * V_493 ;
T_22 V_411 ;
T_21 V_545 ;
T_21 V_546 ;
T_21 V_547 ;
int error ;
V_23 = log -> V_7 ;
V_545 = 0LL ;
V_546 = 0LL ;
V_547 = 0LL ;
for ( V_411 = 0 ; V_411 < V_23 -> V_25 . V_422 ; V_411 ++ ) {
error = F_255 ( V_23 , NULL , V_411 , 0 , & V_544 ) ;
if ( error ) {
F_98 ( V_23 , L_101 ,
V_8 , V_411 , error ) ;
} else {
V_543 = F_256 ( V_544 ) ;
V_545 += F_30 ( V_543 -> V_548 ) +
F_30 ( V_543 -> V_549 ) ;
F_27 ( V_544 ) ;
}
error = F_217 ( V_23 , NULL , V_411 , & V_493 ) ;
if ( error ) {
F_98 ( V_23 , L_102 ,
V_8 , V_411 , error ) ;
} else {
struct V_216 * V_492 = F_218 ( V_493 ) ;
V_546 += F_30 ( V_492 -> V_550 ) ;
V_547 += F_30 ( V_492 -> V_551 ) ;
F_27 ( V_493 ) ;
}
}
}
