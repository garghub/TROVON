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
STATIC T_2
F_10 (
struct V_1 * log ,
T_3 V_12 ,
int V_4 ,
struct V_5 * V_6 )
{
T_3 V_13 = V_12 & ( ( T_3 ) log -> V_10 - 1 ) ;
ASSERT ( V_13 + V_4 <= V_6 -> V_14 ) ;
return V_6 -> V_15 + F_11 ( V_13 ) ;
}
STATIC int
F_12 (
struct V_1 * log ,
T_3 V_12 ,
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
T_3 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
T_2 * V_13 )
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
T_3 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
T_2 V_13 )
{
T_2 V_20 = V_6 -> V_15 ;
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
T_3 V_12 ,
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
T_4 * V_23 ,
T_5 * V_24 )
{
F_29 ( V_23 , L_2 ,
V_8 , & V_23 -> V_25 . V_26 , V_27 ) ;
F_29 ( V_23 , L_3 ,
& V_24 -> V_28 , F_30 ( V_24 -> V_29 ) ) ;
}
STATIC int
F_31 (
T_4 * V_23 ,
T_5 * V_24 )
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
T_4 * V_23 ,
T_5 * V_24 )
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
T_3 V_36 ,
T_3 * V_37 ,
T_6 V_38 )
{
T_2 V_13 ;
T_3 V_39 ;
T_3 V_40 ;
T_6 V_41 ;
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
T_3 V_42 ,
int V_4 ,
T_6 V_43 ,
T_3 * V_44 )
{
T_3 V_45 , V_46 ;
T_6 V_38 ;
T_1 * V_6 ;
T_3 V_47 ;
T_2 V_48 = NULL ;
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
T_3 V_42 ,
T_3 * V_37 ,
int V_53 )
{
T_3 V_45 ;
T_1 * V_6 ;
T_2 V_13 = NULL ;
T_5 * V_24 = NULL ;
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
V_24 = ( T_5 * ) V_13 ;
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
T_6 V_59 = F_30 ( V_24 -> V_59 ) ;
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
T_3 * V_62 )
{
T_1 * V_6 ;
T_2 V_13 ;
T_3 V_44 , V_36 , V_42 , V_37 , V_63 ;
int V_64 ;
T_6 V_65 , V_66 ;
T_6 V_67 ;
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
( T_3 ) V_64 >= V_63 ) ;
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
( T_3 ) V_68 - V_42 >= 0 ) ;
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
T_3 * V_63 ,
T_3 * V_72 )
{
T_5 * V_73 ;
T_7 * V_74 ;
T_2 V_13 = NULL ;
T_1 * V_6 ;
int error , V_45 , V_75 ;
T_3 V_76 ;
T_3 V_77 ;
T_8 V_78 ;
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
V_73 = ( T_5 * ) V_13 ;
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
V_74 = ( T_7 * ) V_13 ;
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
T_3 * V_12 )
{
T_1 * V_6 ;
T_2 V_13 ;
T_6 V_100 , V_101 ;
T_3 V_44 , V_37 , V_42 ;
T_3 V_64 ;
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
T_2 V_48 ,
int V_38 ,
int V_103 ,
int V_104 ,
int V_105 )
{
T_5 * V_106 = ( T_5 * ) V_48 ;
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
T_2 V_13 ;
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
T_8 V_78 )
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
T_9 * V_125 , * V_126 ;
int error = 0 ;
F_69 ( V_127 ) ;
F_69 ( V_128 ) ;
F_69 ( V_129 ) ;
F_69 ( V_130 ) ;
F_69 ( V_131 ) ;
F_70 ( & V_123 -> V_132 , & V_127 ) ;
F_71 (item, n, &sort_list, ri_list) {
T_10 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
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
T_10 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
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
T_3 V_159 ,
T_6 V_160 ,
T_11 V_161 )
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
T_3 V_159 ,
T_6 V_160 ,
T_11 V_161 )
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
T_9 * V_125 ,
struct V_5 * V_6 ,
T_10 * V_133 )
{
int V_45 ;
int V_164 = 0 ;
int V_165 = 0 ;
int V_166 = 0 ;
int V_167 = 0 ;
int V_168 = 0 ;
int V_169 ;
int V_170 ;
T_12 * V_171 ;
T_12 * V_172 ;
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
V_172 = ( T_12 * ) F_99 ( V_6 ,
V_169 ) ;
* V_172 = * V_171 ;
F_100 ( V_23 , (struct V_185 * )
F_99 ( V_6 , V_45 * V_23 -> V_25 . V_177 ) ) ;
}
return 0 ;
}
static T_8
F_101 (
struct V_163 * V_23 ,
struct V_5 * V_6 )
{
T_13 V_186 ;
T_14 V_187 ;
T_14 V_188 ;
void * V_189 = V_6 -> V_15 ;
V_107 * V_190 ;
T_8 V_191 = - 1 ;
if ( ! F_94 ( & V_23 -> V_25 ) )
goto V_192;
V_186 = F_30 ( * ( V_81 * ) V_189 ) ;
switch ( V_186 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 : {
struct V_199 * V_200 = V_189 ;
V_191 = F_55 ( V_200 -> V_201 . V_202 . V_203 ) ;
V_190 = & V_200 -> V_201 . V_202 . V_204 ;
break;
}
case V_205 :
case V_206 : {
struct V_199 * V_200 = V_189 ;
V_191 = F_55 ( V_200 -> V_201 . V_207 . V_203 ) ;
V_190 = & V_200 -> V_201 . V_207 . V_204 ;
break;
}
case V_208 :
V_191 = F_55 ( ( (struct V_209 * ) V_189 ) -> V_210 ) ;
V_190 = & ( (struct V_209 * ) V_189 ) -> V_211 ;
break;
case V_212 :
V_191 = F_55 ( ( (struct V_213 * ) V_189 ) -> V_214 ) ;
V_190 = & ( (struct V_213 * ) V_189 ) -> V_215 ;
break;
case V_216 :
V_191 = F_55 ( ( (struct V_217 * ) V_189 ) -> V_218 ) ;
V_190 = & ( (struct V_217 * ) V_189 ) -> V_219 ;
break;
case V_220 :
V_191 = F_55 ( ( (struct V_221 * ) V_189 ) -> V_222 ) ;
V_190 = & ( (struct V_221 * ) V_189 ) -> V_223 ;
break;
case V_224 :
case V_225 :
case V_226 :
V_191 = F_55 ( ( (struct V_227 * ) V_189 ) -> V_191 ) ;
V_190 = & ( (struct V_227 * ) V_189 ) -> V_190 ;
break;
case V_228 :
V_191 = F_55 ( ( (struct V_229 * ) V_189 ) -> V_230 ) ;
V_190 = & ( (struct V_229 * ) V_189 ) -> V_231 ;
break;
case V_232 :
V_191 = F_55 ( ( (struct V_233 * ) V_189 ) -> V_234 ) ;
V_190 = & ( (struct V_233 * ) V_189 ) -> V_26 ;
break;
default:
break;
}
if ( V_191 != ( T_8 ) - 1 ) {
if ( ! F_34 ( & V_23 -> V_25 . V_26 , V_190 ) )
goto V_192;
return V_191 ;
}
V_188 = F_102 ( ( (struct V_235 * ) V_189 ) -> V_236 ) ;
switch ( V_188 ) {
case V_237 :
case V_238 :
case V_239 :
V_191 = F_55 ( ( (struct V_240 * ) V_189 ) -> V_191 ) ;
V_190 = & ( (struct V_240 * ) V_189 ) -> V_190 ;
break;
default:
break;
}
if ( V_191 != ( T_8 ) - 1 ) {
if ( ! F_34 ( & V_23 -> V_25 . V_26 , V_190 ) )
goto V_192;
return V_191 ;
}
V_187 = F_102 ( * ( V_241 * ) V_189 ) ;
switch ( V_187 ) {
case V_242 :
case V_243 :
goto V_192;
default:
break;
}
V_192:
return ( T_8 ) - 1 ;
}
static void
F_103 (
struct V_163 * V_23 ,
struct V_5 * V_6 ,
T_10 * V_133 )
{
struct V_235 * V_244 = V_6 -> V_15 ;
T_13 V_186 ;
T_14 V_187 ;
T_14 V_188 ;
if ( ! F_94 ( & V_23 -> V_25 ) )
return;
V_186 = F_30 ( * ( V_81 * ) V_6 -> V_15 ) ;
V_187 = F_102 ( * ( V_241 * ) V_6 -> V_15 ) ;
V_188 = F_102 ( V_244 -> V_236 ) ;
switch ( F_104 ( V_133 ) ) {
case V_245 :
switch ( V_186 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
V_6 -> V_174 = & V_246 ;
break;
case V_197 :
case V_247 :
case V_198 :
case V_248 :
V_6 -> V_174 = & V_249 ;
break;
case V_205 :
case V_206 :
V_6 -> V_174 = & V_250 ;
break;
default:
F_3 ( V_23 , L_24 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_251 :
if ( V_186 != V_208 ) {
F_3 ( V_23 , L_25 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_252 ;
break;
case V_253 :
if ( V_186 != V_212 ) {
F_3 ( V_23 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_254 ;
break;
case V_255 :
if ( V_186 != V_216 ) {
F_3 ( V_23 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_256 ;
break;
case V_257 :
case V_258 :
case V_259 :
#ifdef F_105
if ( V_187 != V_242 ) {
F_3 ( V_23 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_260 ;
#else
F_98 ( V_23 ,
L_29 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_261 :
if ( V_187 != V_243 ) {
F_3 ( V_23 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_175 ;
break;
case V_262 :
if ( V_186 != V_220 ) {
F_3 ( V_23 , L_31 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_263 ;
break;
case V_264 :
if ( V_186 != V_265 &&
V_186 != V_224 ) {
F_3 ( V_23 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_266 ;
break;
case V_267 :
if ( V_186 != V_268 &&
V_186 != V_225 ) {
F_3 ( V_23 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_269 ;
break;
case V_270 :
if ( V_186 != V_271 &&
V_186 != V_226 ) {
F_3 ( V_23 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_272 ;
break;
case V_273 :
if ( V_188 != V_274 &&
V_188 != V_237 ) {
F_3 ( V_23 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_275 ;
break;
case V_276 :
if ( V_188 != V_277 &&
V_188 != V_238 ) {
F_3 ( V_23 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_278 ;
break;
case V_279 :
if ( V_188 != V_280 &&
V_188 != V_239 ) {
F_3 ( V_23 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_281 ;
break;
case V_282 :
if ( V_188 != V_283 &&
V_188 != V_284 ) {
F_3 ( V_23 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_285 ;
break;
case V_286 :
if ( V_186 != V_228 ) {
F_3 ( V_23 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_287 ;
break;
case V_288 :
if ( V_186 != V_232 ) {
F_3 ( V_23 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_174 = & V_289 ;
break;
default:
F_3 ( V_23 , L_41 ,
F_104 ( V_133 ) ) ;
break;
}
}
STATIC void
F_106 (
struct V_163 * V_23 ,
T_9 * V_125 ,
struct V_5 * V_6 ,
T_10 * V_133 )
{
int V_45 ;
int V_165 ;
int V_166 ;
int error ;
F_107 ( V_23 -> V_173 , V_133 ) ;
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
( ( T_6 ) V_165 << V_182 ) + ( V_166 << V_182 ) ) ;
if ( V_125 -> V_134 [ V_45 ] . V_183 < ( V_166 << V_182 ) )
V_166 = V_125 -> V_134 [ V_45 ] . V_183 >> V_182 ;
error = 0 ;
if ( V_133 -> V_139 &
( V_290 | V_291 | V_292 ) ) {
if ( V_125 -> V_134 [ V_45 ] . V_135 == NULL ) {
F_98 ( V_23 ,
L_42 , V_8 ) ;
goto V_293;
}
if ( V_125 -> V_134 [ V_45 ] . V_183 < sizeof( V_294 ) ) {
F_98 ( V_23 ,
L_43 ,
V_125 -> V_134 [ V_45 ] . V_183 , V_8 ) ;
goto V_293;
}
error = F_108 ( V_23 , V_125 -> V_134 [ V_45 ] . V_135 ,
- 1 , 0 , V_295 ,
L_44 ) ;
if ( error )
goto V_293;
}
memcpy ( F_99 ( V_6 ,
( T_6 ) V_165 << V_182 ) ,
V_125 -> V_134 [ V_45 ] . V_135 ,
V_166 << V_182 ) ;
V_293:
V_45 ++ ;
V_165 += V_166 ;
}
ASSERT ( V_45 == V_125 -> V_296 ) ;
F_103 ( V_23 , V_6 , V_133 ) ;
}
STATIC bool
F_109 (
struct V_163 * V_23 ,
struct V_1 * log ,
struct V_147 * V_125 ,
struct V_5 * V_6 ,
struct V_297 * V_133 )
{
T_6 type ;
F_110 ( log , V_133 ) ;
if ( ! V_23 -> V_298 )
return false ;
type = 0 ;
if ( V_133 -> V_139 & V_290 )
type |= V_299 ;
if ( V_133 -> V_139 & V_291 )
type |= V_300 ;
if ( V_133 -> V_139 & V_292 )
type |= V_301 ;
if ( log -> V_302 & type )
return false ;
F_106 ( V_23 , V_125 , V_6 , V_133 ) ;
return true ;
}
STATIC int
F_111 (
struct V_1 * log ,
struct V_148 * V_129 ,
struct V_147 * V_125 ,
T_8 V_303 )
{
T_10 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_304 ;
T_8 V_191 ;
if ( F_89 ( log , V_133 -> V_152 ,
V_133 -> V_155 , V_133 -> V_139 ) ) {
F_112 ( log , V_133 ) ;
return 0 ;
}
F_113 ( log , V_133 ) ;
V_304 = 0 ;
if ( V_133 -> V_139 & V_141 )
V_304 |= V_305 ;
V_6 = F_114 ( V_23 -> V_306 , V_133 -> V_152 , V_133 -> V_155 ,
V_304 , NULL ) ;
if ( ! V_6 )
return - V_49 ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_45 ) ;
goto V_307;
}
V_191 = F_101 ( V_23 , V_6 ) ;
if ( V_191 && V_191 != - 1 && F_115 ( V_191 , V_303 ) >= 0 ) {
F_103 ( V_23 , V_6 , V_133 ) ;
goto V_307;
}
if ( V_133 -> V_139 & V_141 ) {
error = F_92 ( V_23 , V_125 , V_6 , V_133 ) ;
if ( error )
goto V_307;
} else if ( V_133 -> V_139 &
( V_290 | V_291 | V_292 ) ) {
bool V_308 ;
V_308 = F_109 ( V_23 , log , V_125 , V_6 , V_133 ) ;
if ( ! V_308 )
goto V_307;
} else {
F_106 ( V_23 , V_125 , V_6 , V_133 ) ;
}
if ( V_243 ==
F_102 ( * ( ( V_241 * ) F_99 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_116 ( log -> V_7 -> V_25 . V_309 ,
( T_13 ) log -> V_7 -> V_310 ) ) ) {
F_117 ( V_6 ) ;
error = F_26 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_118 ( V_6 , V_129 ) ;
}
V_307:
F_27 ( V_6 ) ;
return error ;
}
STATIC int
F_119 (
struct V_163 * V_23 ,
struct V_185 * V_311 ,
struct V_312 * V_313 ,
struct V_148 * V_129 )
{
struct V_314 * V_315 ;
int error ;
ASSERT ( V_313 -> V_316 & ( V_317 | V_318 ) ) ;
V_315 = F_120 ( V_23 , V_313 -> V_319 ) ;
if ( ! V_315 )
return - V_49 ;
F_121 ( & V_315 -> V_320 , V_311 ) ;
ASSERT ( V_315 -> V_320 . V_321 >= 3 ) ;
error = F_122 ( V_315 , V_311 ) ;
if ( error )
goto V_322;
if ( V_313 -> V_316 & V_317 ) {
ASSERT ( V_313 -> V_316 & V_323 ) ;
error = F_123 ( NULL , V_315 , V_324 ,
V_315 -> V_325 , V_129 ) ;
if ( error )
goto V_322;
}
if ( V_313 -> V_316 & V_318 ) {
ASSERT ( V_313 -> V_316 & V_326 ) ;
error = F_123 ( NULL , V_315 , V_327 ,
V_315 -> V_325 , V_129 ) ;
if ( error )
goto V_322;
}
V_322:
F_124 ( V_315 ) ;
return error ;
}
STATIC int
F_125 (
struct V_1 * log ,
struct V_148 * V_129 ,
struct V_147 * V_125 ,
T_8 V_303 )
{
T_15 * V_313 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_178 * V_311 ;
int V_160 ;
T_2 V_328 ;
T_2 V_329 ;
int error ;
int V_330 ;
T_6 V_331 ;
T_16 * V_332 ;
T_6 V_333 ;
int V_334 = 0 ;
if ( V_125 -> V_134 [ 0 ] . V_183 == sizeof( T_15 ) ) {
V_313 = V_125 -> V_134 [ 0 ] . V_135 ;
} else {
V_313 = F_85 ( sizeof( T_15 ) , V_157 ) ;
V_334 = 1 ;
error = F_126 ( & V_125 -> V_134 [ 0 ] , V_313 ) ;
if ( error )
goto error;
}
if ( F_89 ( log , V_313 -> V_335 ,
V_313 -> V_336 , 0 ) ) {
error = 0 ;
F_127 ( log , V_313 ) ;
goto error;
}
F_128 ( log , V_313 ) ;
V_6 = F_114 ( V_23 -> V_306 , V_313 -> V_335 , V_313 -> V_336 , 0 ,
& V_175 ) ;
if ( ! V_6 ) {
error = - V_49 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_46 ) ;
goto V_307;
}
ASSERT ( V_313 -> V_316 & V_337 ) ;
V_311 = ( V_178 * ) F_99 ( V_6 , V_313 -> V_338 ) ;
if ( F_33 ( V_311 -> V_339 != F_129 ( V_243 ) ) ) {
F_98 ( V_23 ,
L_47 ,
V_8 , V_311 , V_6 , V_313 -> V_319 ) ;
F_4 ( L_48 ,
V_121 , V_23 ) ;
error = - V_16 ;
goto V_307;
}
V_332 = V_125 -> V_134 [ 1 ] . V_135 ;
if ( F_33 ( V_332 -> V_339 != V_243 ) ) {
F_98 ( V_23 ,
L_49 ,
V_8 , V_125 , V_313 -> V_319 ) ;
F_4 ( L_50 ,
V_121 , V_23 ) ;
error = - V_16 ;
goto V_307;
}
if ( V_311 -> V_321 >= 3 ) {
T_8 V_191 = F_55 ( V_311 -> V_340 ) ;
if ( V_191 && V_191 != - 1 && F_115 ( V_191 , V_303 ) >= 0 ) {
F_130 ( log , V_313 ) ;
error = 0 ;
goto V_341;
}
}
if ( ! F_94 ( & V_23 -> V_25 ) &&
V_332 -> V_342 < F_102 ( V_311 -> V_342 ) ) {
if ( F_102 ( V_311 -> V_342 ) == V_343 &&
V_332 -> V_342 < ( V_343 >> 1 ) ) {
} else {
F_130 ( log , V_313 ) ;
error = 0 ;
goto V_307;
}
}
V_332 -> V_342 = 0 ;
if ( F_33 ( F_131 ( V_332 -> V_344 ) ) ) {
if ( ( V_332 -> V_345 != V_346 ) &&
( V_332 -> V_345 != V_347 ) ) {
F_132 ( L_51 ,
V_121 , V_23 , V_332 ) ;
F_98 ( V_23 ,
L_52
L_53 ,
V_8 , V_125 , V_311 , V_6 , V_313 -> V_319 ) ;
error = - V_16 ;
goto V_307;
}
} else if ( F_33 ( F_133 ( V_332 -> V_344 ) ) ) {
if ( ( V_332 -> V_345 != V_346 ) &&
( V_332 -> V_345 != V_347 ) &&
( V_332 -> V_345 != V_348 ) ) {
F_132 ( L_54 ,
V_121 , V_23 , V_332 ) ;
F_98 ( V_23 ,
L_55
L_53 ,
V_8 , V_125 , V_311 , V_6 , V_313 -> V_319 ) ;
error = - V_16 ;
goto V_307;
}
}
if ( F_33 ( V_332 -> V_349 + V_332 -> V_350 > V_332 -> V_351 ) ) {
F_132 ( L_56 ,
V_121 , V_23 , V_332 ) ;
F_98 ( V_23 ,
L_57
L_58 ,
V_8 , V_125 , V_311 , V_6 , V_313 -> V_319 ,
V_332 -> V_349 + V_332 -> V_350 ,
V_332 -> V_351 ) ;
error = - V_16 ;
goto V_307;
}
if ( F_33 ( V_332 -> V_352 > V_23 -> V_25 . V_177 ) ) {
F_132 ( L_59 ,
V_121 , V_23 , V_332 ) ;
F_98 ( V_23 ,
L_57
L_60 , V_8 ,
V_125 , V_311 , V_6 , V_313 -> V_319 , V_332 -> V_352 ) ;
error = - V_16 ;
goto V_307;
}
V_333 = F_134 ( V_332 -> V_321 ) ;
if ( F_33 ( V_125 -> V_134 [ 1 ] . V_183 > V_333 ) ) {
F_132 ( L_61 ,
V_121 , V_23 , V_332 ) ;
F_98 ( V_23 ,
L_62 ,
V_8 , V_125 -> V_134 [ 1 ] . V_183 , V_125 ) ;
error = - V_16 ;
goto V_307;
}
F_135 ( V_311 , V_332 ) ;
if ( V_125 -> V_134 [ 1 ] . V_183 > V_333 ) {
memcpy ( ( char * ) V_311 + V_333 ,
V_125 -> V_134 [ 1 ] . V_135 + V_333 ,
V_125 -> V_134 [ 1 ] . V_183 - V_333 ) ;
}
V_331 = V_313 -> V_316 ;
switch ( V_331 & ( V_353 | V_354 ) ) {
case V_353 :
F_136 ( V_311 , V_313 -> V_355 . V_356 ) ;
break;
case V_354 :
memcpy ( F_137 ( V_311 ) ,
& V_313 -> V_355 . V_357 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_313 -> V_358 == 2 )
goto V_341;
V_160 = V_125 -> V_134 [ 2 ] . V_183 ;
V_328 = V_125 -> V_134 [ 2 ] . V_135 ;
ASSERT ( V_313 -> V_358 <= 4 ) ;
ASSERT ( ( V_313 -> V_358 == 3 ) || ( V_331 & V_359 ) ) ;
ASSERT ( ! ( V_331 & V_360 ) ||
( V_160 == V_313 -> V_361 ) ) ;
switch ( V_331 & V_360 ) {
case V_362 :
case V_363 :
memcpy ( F_137 ( V_311 ) , V_328 , V_160 ) ;
break;
case V_323 :
F_138 ( V_23 , (struct V_199 * ) V_328 , V_160 ,
( V_364 * ) F_137 ( V_311 ) ,
F_139 ( V_311 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_331 & V_360 ) == 0 ) ;
break;
}
if ( V_313 -> V_316 & V_359 ) {
if ( V_313 -> V_316 & V_360 ) {
V_330 = 3 ;
} else {
V_330 = 2 ;
}
V_160 = V_125 -> V_134 [ V_330 ] . V_183 ;
V_328 = V_125 -> V_134 [ V_330 ] . V_135 ;
ASSERT ( V_160 == V_313 -> V_365 ) ;
switch ( V_313 -> V_316 & V_359 ) {
case V_366 :
case V_367 :
V_329 = F_140 ( V_311 ) ;
ASSERT ( V_160 <= F_141 ( V_311 , V_23 ) ) ;
memcpy ( V_329 , V_328 , V_160 ) ;
break;
case V_326 :
V_329 = F_140 ( V_311 ) ;
F_138 ( V_23 , (struct V_199 * ) V_328 ,
V_160 , ( V_364 * ) V_329 ,
F_141 ( V_311 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_63 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
goto V_307;
}
}
V_341:
if ( V_313 -> V_316 & ( V_317 | V_318 ) )
error = F_119 ( V_23 , V_311 , V_313 ,
V_129 ) ;
F_100 ( log -> V_7 , V_311 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_118 ( V_6 , V_129 ) ;
V_307:
F_27 ( V_6 ) ;
error:
if ( V_334 )
F_91 ( V_313 ) ;
return error ;
}
STATIC int
F_142 (
struct V_1 * log ,
struct V_147 * V_125 )
{
T_17 * V_368 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( V_368 ) ;
if ( V_368 -> V_369 & V_370 )
log -> V_302 |= V_299 ;
if ( V_368 -> V_369 & V_371 )
log -> V_302 |= V_300 ;
if ( V_368 -> V_369 & V_372 )
log -> V_302 |= V_301 ;
return 0 ;
}
STATIC int
F_143 (
struct V_1 * log ,
struct V_148 * V_129 ,
struct V_147 * V_125 ,
T_8 V_303 )
{
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_373 * V_374 , * V_375 ;
int error ;
T_18 * V_376 ;
T_6 type ;
if ( V_23 -> V_298 == 0 )
return 0 ;
V_375 = V_125 -> V_134 [ 1 ] . V_135 ;
if ( V_375 == NULL ) {
F_98 ( log -> V_7 , L_64 , V_8 ) ;
return - V_58 ;
}
if ( V_125 -> V_134 [ 1 ] . V_183 < sizeof( V_294 ) ) {
F_98 ( log -> V_7 , L_65 ,
V_125 -> V_134 [ 1 ] . V_183 , V_8 ) ;
return - V_58 ;
}
type = V_375 -> V_377 & ( V_299 | V_300 | V_301 ) ;
ASSERT ( type ) ;
if ( log -> V_302 & type )
return 0 ;
V_376 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( V_376 ) ;
error = F_108 ( V_23 , V_375 , V_376 -> V_378 , 0 , V_295 ,
L_66 ) ;
if ( error )
return - V_58 ;
ASSERT ( V_376 -> V_379 == 1 ) ;
error = F_144 ( V_23 , NULL , V_23 -> V_306 , V_376 -> V_380 ,
F_145 ( V_23 , V_376 -> V_379 ) , 0 , & V_6 ,
& V_260 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_374 = ( V_294 * ) F_99 ( V_6 , V_376 -> V_381 ) ;
if ( F_94 ( & V_23 -> V_25 ) ) {
struct V_382 * V_383 = (struct V_382 * ) V_374 ;
T_8 V_191 = F_55 ( V_383 -> V_384 ) ;
if ( V_191 && V_191 != - 1 && F_115 ( V_191 , V_303 ) >= 0 ) {
goto V_307;
}
}
memcpy ( V_374 , V_375 , V_125 -> V_134 [ 1 ] . V_183 ) ;
if ( F_94 ( & V_23 -> V_25 ) ) {
F_146 ( ( char * ) V_374 , sizeof( struct V_382 ) ,
V_385 ) ;
}
ASSERT ( V_376 -> V_386 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_37 ;
F_118 ( V_6 , V_129 ) ;
V_307:
F_27 ( V_6 ) ;
return 0 ;
}
STATIC int
F_147 (
struct V_1 * log ,
struct V_147 * V_125 ,
T_8 V_191 )
{
int error ;
T_4 * V_23 = log -> V_7 ;
T_19 * V_387 ;
T_20 * V_388 ;
V_388 = V_125 -> V_134 [ 0 ] . V_135 ;
V_387 = F_148 ( V_23 , V_388 -> V_389 ) ;
if ( ( error = F_149 ( & ( V_125 -> V_134 [ 0 ] ) ,
& ( V_387 -> V_390 ) ) ) ) {
F_150 ( V_387 ) ;
return error ;
}
F_151 ( & V_387 -> V_391 , V_388 -> V_389 ) ;
F_152 ( & log -> V_392 -> V_393 ) ;
F_153 ( log -> V_392 , & V_387 -> V_394 , V_191 ) ;
return 0 ;
}
STATIC int
F_154 (
struct V_1 * log ,
struct V_147 * V_125 )
{
T_21 * V_395 ;
T_19 * V_387 = NULL ;
T_22 * V_396 ;
T_23 V_397 ;
struct V_398 V_399 ;
struct V_400 * V_401 = log -> V_392 ;
V_395 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( ( V_125 -> V_134 [ 0 ] . V_183 == ( sizeof( V_402 ) +
( ( V_395 -> V_403 - 1 ) * sizeof( V_404 ) ) ) ) ||
( V_125 -> V_134 [ 0 ] . V_183 == ( sizeof( V_405 ) +
( ( V_395 -> V_403 - 1 ) * sizeof( V_406 ) ) ) ) ) ;
V_397 = V_395 -> V_407 ;
F_152 ( & V_401 -> V_393 ) ;
V_396 = F_155 ( V_401 , & V_399 , 0 ) ;
while ( V_396 != NULL ) {
if ( V_396 -> V_408 == V_146 ) {
V_387 = ( T_19 * ) V_396 ;
if ( V_387 -> V_390 . V_397 == V_397 ) {
F_156 ( V_401 , V_396 ,
V_409 ) ;
F_150 ( V_387 ) ;
F_152 ( & V_401 -> V_393 ) ;
break;
}
}
V_396 = F_157 ( V_401 , & V_399 ) ;
}
F_158 ( & V_399 ) ;
F_159 ( & V_401 -> V_393 ) ;
return 0 ;
}
STATIC int
F_160 (
struct V_1 * log ,
struct V_148 * V_129 ,
T_9 * V_125 )
{
struct V_163 * V_23 = log -> V_7 ;
struct V_410 * V_411 ;
T_24 V_412 ;
T_25 V_413 ;
unsigned int V_414 ;
unsigned int V_333 ;
T_25 V_415 ;
V_411 = (struct V_410 * ) V_125 -> V_134 [ 0 ] . V_135 ;
if ( V_411 -> V_416 != V_136 ) {
F_3 ( log -> V_7 , L_67 ) ;
return - V_102 ;
}
if ( V_411 -> V_417 != 1 ) {
F_3 ( log -> V_7 , L_68 ) ;
return - V_102 ;
}
V_412 = F_30 ( V_411 -> V_418 ) ;
if ( V_412 >= V_23 -> V_25 . V_419 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_102 ;
}
V_413 = F_30 ( V_411 -> V_420 ) ;
if ( ! V_413 || V_413 == V_421 || V_413 >= V_23 -> V_25 . V_422 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_102 ;
}
V_333 = F_30 ( V_411 -> V_423 ) ;
if ( V_333 != V_23 -> V_25 . V_177 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_102 ;
}
V_414 = F_30 ( V_411 -> V_424 ) ;
if ( ! V_414 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_102 ;
}
V_415 = F_30 ( V_411 -> V_425 ) ;
if ( ! V_415 || V_415 >= V_23 -> V_25 . V_422 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_102 ;
}
ASSERT ( V_414 == V_23 -> V_426 ) ;
ASSERT ( V_415 == V_23 -> V_427 ) ;
if ( V_414 != V_23 -> V_426 ||
V_415 != V_23 -> V_427 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_102 ;
}
if ( F_89 ( log ,
F_161 ( V_23 , V_412 , V_413 ) , V_415 , 0 ) )
return 0 ;
F_162 ( V_23 , NULL , V_129 , V_412 , V_413 , V_415 ,
F_30 ( V_411 -> V_428 ) ) ;
return 0 ;
}
STATIC void
F_163 (
struct V_1 * log ,
struct V_147 * V_125 )
{
struct V_297 * V_133 = V_125 -> V_134 [ 0 ] . V_135 ;
struct V_163 * V_23 = log -> V_7 ;
if ( F_88 ( log , V_133 -> V_152 ,
V_133 -> V_155 , V_133 -> V_139 ) ) {
return;
}
F_164 ( V_23 -> V_306 , V_133 -> V_152 ,
V_133 -> V_155 , NULL ) ;
}
STATIC void
F_165 (
struct V_1 * log ,
struct V_147 * V_125 )
{
struct V_312 V_429 ;
struct V_312 * V_430 ;
struct V_163 * V_23 = log -> V_7 ;
int error ;
if ( V_125 -> V_134 [ 0 ] . V_183 == sizeof( struct V_312 ) ) {
V_430 = V_125 -> V_134 [ 0 ] . V_135 ;
} else {
V_430 = & V_429 ;
memset ( V_430 , 0 , sizeof( * V_430 ) ) ;
error = F_126 ( & V_125 -> V_134 [ 0 ] , V_430 ) ;
if ( error )
return;
}
if ( F_88 ( log , V_430 -> V_335 , V_430 -> V_336 , 0 ) )
return;
F_164 ( V_23 -> V_306 , V_430 -> V_335 ,
V_430 -> V_336 , & V_431 ) ;
}
STATIC void
F_166 (
struct V_1 * log ,
struct V_147 * V_125 )
{
struct V_163 * V_23 = log -> V_7 ;
struct V_373 * V_375 ;
struct V_432 * V_376 ;
T_6 type ;
if ( V_23 -> V_298 == 0 )
return;
V_375 = V_125 -> V_134 [ 1 ] . V_135 ;
if ( V_375 == NULL )
return;
if ( V_125 -> V_134 [ 1 ] . V_183 < sizeof( struct V_373 ) )
return;
type = V_375 -> V_377 & ( V_299 | V_300 | V_301 ) ;
ASSERT ( type ) ;
if ( log -> V_302 & type )
return;
V_376 = V_125 -> V_134 [ 0 ] . V_135 ;
ASSERT ( V_376 ) ;
ASSERT ( V_376 -> V_379 == 1 ) ;
F_164 ( V_23 -> V_306 , V_376 -> V_380 ,
F_145 ( V_23 , V_376 -> V_379 ) , NULL ) ;
}
STATIC void
F_167 (
struct V_1 * log ,
struct V_147 * V_125 )
{
switch ( F_72 ( V_125 ) ) {
case V_138 :
F_163 ( log , V_125 ) ;
break;
case V_142 :
F_165 ( log , V_125 ) ;
break;
case V_143 :
F_166 ( log , V_125 ) ;
break;
case V_146 :
case V_145 :
case V_144 :
default:
break;
}
}
STATIC int
F_168 (
struct V_1 * log ,
struct V_122 * V_123 ,
struct V_147 * V_125 )
{
F_169 ( log , V_123 , V_125 , V_433 ) ;
switch ( F_72 ( V_125 ) ) {
case V_138 :
return F_80 ( log , V_125 ) ;
case V_144 :
return F_142 ( log , V_125 ) ;
case V_142 :
case V_146 :
case V_145 :
case V_143 :
case V_136 :
return 0 ;
default:
F_3 ( log -> V_7 , L_75 ,
V_8 , F_72 ( V_125 ) ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
}
STATIC int
F_170 (
struct V_1 * log ,
struct V_122 * V_123 ,
struct V_148 * V_129 ,
struct V_147 * V_125 )
{
F_169 ( log , V_123 , V_125 , V_434 ) ;
switch ( F_72 ( V_125 ) ) {
case V_138 :
return F_111 ( log , V_129 , V_125 ,
V_123 -> V_435 ) ;
case V_142 :
return F_125 ( log , V_129 , V_125 ,
V_123 -> V_435 ) ;
case V_146 :
return F_147 ( log , V_125 , V_123 -> V_435 ) ;
case V_145 :
return F_154 ( log , V_125 ) ;
case V_143 :
return F_143 ( log , V_129 , V_125 ,
V_123 -> V_435 ) ;
case V_136 :
return F_160 ( log , V_129 , V_125 ) ;
case V_144 :
return 0 ;
default:
F_3 ( log -> V_7 , L_75 ,
V_8 , F_72 ( V_125 ) ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
}
STATIC int
F_171 (
struct V_1 * log ,
struct V_122 * V_123 ,
struct V_148 * V_129 ,
struct V_148 * V_436 )
{
struct V_147 * V_125 ;
int error = 0 ;
F_83 (item, item_list, ri_list) {
error = F_170 ( log , V_123 ,
V_129 , V_125 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_172 (
struct V_1 * log ,
struct V_122 * V_123 ,
int V_124 )
{
int error = 0 ;
int V_22 ;
int V_437 = 0 ;
struct V_147 * V_125 ;
struct V_147 * V_293 ;
F_69 ( V_129 ) ;
F_69 ( V_438 ) ;
F_69 ( V_439 ) ;
#define F_173 100
F_174 ( & V_123 -> V_440 ) ;
error = F_68 ( log , V_123 , V_124 ) ;
if ( error )
return error ;
F_71 (item, next, &trans->r_itemq, ri_list) {
switch ( V_124 ) {
case V_433 :
error = F_168 ( log , V_123 , V_125 ) ;
break;
case V_434 :
F_167 ( log , V_125 ) ;
F_73 ( & V_125 -> V_137 , & V_438 ) ;
V_437 ++ ;
if ( V_437 >= F_173 ) {
error = F_171 ( log , V_123 ,
& V_129 , & V_438 ) ;
F_175 ( & V_438 , & V_439 ) ;
V_437 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
V_51:
if ( ! F_77 ( & V_438 ) ) {
if ( ! error )
error = F_171 ( log , V_123 ,
& V_129 , & V_438 ) ;
F_175 ( & V_438 , & V_439 ) ;
}
if ( ! F_77 ( & V_439 ) )
F_70 ( & V_439 , & V_123 -> V_132 ) ;
V_22 = F_176 ( & V_129 ) ;
return error ? error : V_22 ;
}
STATIC void
F_177 (
struct V_148 * V_24 )
{
T_9 * V_125 ;
V_125 = F_178 ( sizeof( T_9 ) , V_157 ) ;
F_179 ( & V_125 -> V_137 ) ;
F_86 ( & V_125 -> V_137 , V_24 ) ;
}
STATIC int
F_180 (
struct V_1 * log ,
struct V_122 * V_123 ,
T_2 V_441 ,
int V_160 )
{
T_9 * V_125 ;
T_2 V_442 , V_443 ;
int V_444 ;
if ( F_77 ( & V_123 -> V_132 ) ) {
F_177 ( & V_123 -> V_132 ) ;
V_442 = ( T_2 ) & V_123 -> V_445 +
sizeof( V_446 ) - V_160 ;
memcpy ( V_442 , V_441 , V_160 ) ;
return 0 ;
}
V_125 = F_181 ( V_123 -> V_132 . V_447 , T_9 , V_137 ) ;
V_443 = V_125 -> V_134 [ V_125 -> V_448 - 1 ] . V_135 ;
V_444 = V_125 -> V_134 [ V_125 -> V_448 - 1 ] . V_183 ;
V_442 = F_182 ( V_443 , V_160 + V_444 , V_444 , V_157 ) ;
memcpy ( & V_442 [ V_444 ] , V_441 , V_160 ) ;
V_125 -> V_134 [ V_125 -> V_448 - 1 ] . V_183 += V_160 ;
V_125 -> V_134 [ V_125 -> V_448 - 1 ] . V_135 = V_442 ;
F_183 ( log , V_123 , V_125 , 0 ) ;
return 0 ;
}
STATIC int
F_184 (
struct V_1 * log ,
struct V_122 * V_123 ,
T_2 V_441 ,
int V_160 )
{
T_15 * V_313 ;
T_9 * V_125 ;
T_2 V_442 ;
if ( ! V_160 )
return 0 ;
if ( F_77 ( & V_123 -> V_132 ) ) {
if ( * ( T_6 * ) V_441 != V_449 ) {
F_3 ( log -> V_7 , L_76 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
if ( V_160 == sizeof( V_446 ) )
F_177 ( & V_123 -> V_132 ) ;
memcpy ( & V_123 -> V_445 , V_441 , V_160 ) ;
return 0 ;
}
V_442 = F_85 ( V_160 , V_157 ) ;
memcpy ( V_442 , V_441 , V_160 ) ;
V_313 = ( T_15 * ) V_442 ;
V_125 = F_181 ( V_123 -> V_132 . V_447 , T_9 , V_137 ) ;
if ( V_125 -> V_296 != 0 &&
V_125 -> V_296 == V_125 -> V_448 ) {
F_177 ( & V_123 -> V_132 ) ;
V_125 = F_181 ( V_123 -> V_132 . V_447 ,
T_9 , V_137 ) ;
}
if ( V_125 -> V_296 == 0 ) {
if ( V_313 -> V_358 == 0 ||
V_313 -> V_358 > V_450 ) {
F_3 ( log -> V_7 ,
L_77 ,
V_313 -> V_358 ) ;
ASSERT ( 0 ) ;
F_91 ( V_442 ) ;
return - V_58 ;
}
V_125 -> V_296 = V_313 -> V_358 ;
V_125 -> V_134 =
F_178 ( V_125 -> V_296 * sizeof( V_451 ) ,
V_157 ) ;
}
ASSERT ( V_125 -> V_296 > V_125 -> V_448 ) ;
V_125 -> V_134 [ V_125 -> V_448 ] . V_135 = V_442 ;
V_125 -> V_134 [ V_125 -> V_448 ] . V_183 = V_160 ;
V_125 -> V_448 ++ ;
F_185 ( log , V_123 , V_125 , 0 ) ;
return 0 ;
}
STATIC void
F_186 (
struct V_122 * V_123 )
{
T_9 * V_125 , * V_126 ;
int V_45 ;
F_71 (item, n, &trans->r_itemq, ri_list) {
F_90 ( & V_125 -> V_137 ) ;
for ( V_45 = 0 ; V_45 < V_125 -> V_448 ; V_45 ++ )
F_91 ( V_125 -> V_134 [ V_45 ] . V_135 ) ;
F_91 ( V_125 -> V_134 ) ;
F_91 ( V_125 ) ;
}
F_91 ( V_123 ) ;
}
STATIC int
F_187 (
struct V_1 * log ,
struct V_122 * V_123 ,
T_2 V_441 ,
unsigned int V_160 ,
unsigned int V_161 ,
int V_124 )
{
int error = 0 ;
bool V_452 = false ;
V_161 &= ~ V_453 ;
if ( V_161 & V_454 )
V_161 &= ~ V_455 ;
switch ( V_161 ) {
case 0 :
case V_455 :
error = F_184 ( log , V_123 , V_441 , V_160 ) ;
break;
case V_454 :
error = F_180 ( log , V_123 , V_441 , V_160 ) ;
break;
case V_456 :
error = F_172 ( log , V_123 , V_124 ) ;
V_452 = true ;
break;
case V_97 :
F_3 ( log -> V_7 , L_78 , V_8 ) ;
V_452 = true ;
break;
case V_457 :
default:
F_3 ( log -> V_7 , L_79 , V_8 , V_161 ) ;
ASSERT ( 0 ) ;
error = - V_58 ;
break;
}
if ( error || V_452 )
F_186 ( V_123 ) ;
return error ;
}
STATIC struct V_122 *
F_188 (
struct V_458 V_459 [] ,
struct V_460 * V_73 ,
struct V_461 * V_462 )
{
struct V_122 * V_123 ;
T_26 V_463 ;
struct V_458 * V_464 ;
V_463 = F_30 ( V_462 -> V_465 ) ;
V_464 = & V_459 [ F_189 ( V_463 ) ] ;
F_190 (trans, rhp, r_list) {
if ( V_123 -> V_466 == V_463 )
return V_123 ;
}
if ( ! ( V_462 -> V_96 & V_457 ) )
return NULL ;
ASSERT ( F_30 ( V_462 -> V_467 ) == 0 ) ;
V_123 = F_178 ( sizeof( struct V_122 ) , V_157 ) ;
V_123 -> V_466 = V_463 ;
V_123 -> V_435 = F_55 ( V_73 -> V_89 ) ;
F_179 ( & V_123 -> V_132 ) ;
F_191 ( & V_123 -> V_440 ) ;
F_192 ( & V_123 -> V_440 , V_464 ) ;
return NULL ;
}
STATIC int
F_193 (
struct V_1 * log ,
struct V_458 V_459 [] ,
struct V_460 * V_73 ,
struct V_461 * V_462 ,
T_2 V_441 ,
T_2 V_468 ,
int V_124 )
{
struct V_122 * V_123 ;
unsigned int V_160 ;
if ( V_462 -> V_469 != V_470 &&
V_462 -> V_469 != V_471 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 , V_462 -> V_469 ) ;
ASSERT ( 0 ) ;
return - V_58 ;
}
V_160 = F_30 ( V_462 -> V_467 ) ;
if ( V_441 + V_160 > V_468 ) {
F_3 ( log -> V_7 , L_81 , V_8 , V_160 ) ;
F_194 ( 1 ) ;
return - V_58 ;
}
V_123 = F_188 ( V_459 , V_73 , V_462 ) ;
if ( ! V_123 ) {
return 0 ;
}
return F_187 ( log , V_123 , V_441 , V_160 ,
V_462 -> V_96 , V_124 ) ;
}
STATIC int
F_195 (
struct V_1 * log ,
struct V_458 V_459 [] ,
struct V_460 * V_73 ,
T_2 V_441 ,
int V_124 )
{
struct V_461 * V_462 ;
T_2 V_468 ;
int V_472 ;
int error ;
V_468 = V_441 + F_30 ( V_73 -> V_61 ) ;
V_472 = F_30 ( V_73 -> V_95 ) ;
if ( F_31 ( log -> V_7 , V_73 ) )
return - V_58 ;
while ( ( V_441 < V_468 ) && V_472 ) {
V_462 = (struct V_461 * ) V_441 ;
V_441 += sizeof( * V_462 ) ;
ASSERT ( V_441 <= V_468 ) ;
error = F_193 ( log , V_459 , V_73 , V_462 ,
V_441 , V_468 , V_124 ) ;
if ( error )
return error ;
V_441 += F_30 ( V_462 -> V_467 ) ;
V_472 -- ;
}
return 0 ;
}
STATIC int
F_196 (
T_4 * V_23 ,
T_19 * V_387 )
{
T_27 * V_473 ;
T_28 * V_474 ;
int V_45 ;
int error = 0 ;
T_29 * V_475 ;
T_30 V_476 ;
ASSERT ( ! F_197 ( V_477 , & V_387 -> V_478 ) ) ;
for ( V_45 = 0 ; V_45 < V_387 -> V_390 . V_389 ; V_45 ++ ) {
V_475 = & ( V_387 -> V_390 . V_479 [ V_45 ] ) ;
V_476 = F_198 ( V_23 ,
F_199 ( V_23 , V_475 -> V_480 ) ) ;
if ( ( V_476 == 0 ) ||
( V_475 -> V_481 == 0 ) ||
( V_476 >= V_23 -> V_25 . V_482 ) ||
( V_475 -> V_481 >= V_23 -> V_25 . V_422 ) ) {
F_200 ( V_477 , & V_387 -> V_478 ) ;
F_201 ( V_387 , V_387 -> V_390 . V_389 ) ;
return - V_58 ;
}
}
V_474 = F_202 ( V_23 , 0 ) ;
error = F_203 ( V_474 , & F_204 ( V_23 ) -> V_483 , 0 , 0 ) ;
if ( error )
goto V_484;
V_473 = F_205 ( V_474 , V_387 , V_387 -> V_390 . V_389 ) ;
for ( V_45 = 0 ; V_45 < V_387 -> V_390 . V_389 ; V_45 ++ ) {
V_475 = & ( V_387 -> V_390 . V_479 [ V_45 ] ) ;
error = F_206 ( V_474 , V_475 -> V_480 , V_475 -> V_481 ) ;
if ( error )
goto V_484;
F_207 ( V_474 , V_473 , V_475 -> V_480 ,
V_475 -> V_481 ) ;
}
F_200 ( V_477 , & V_387 -> V_478 ) ;
error = F_208 ( V_474 , 0 ) ;
return error ;
V_484:
F_209 ( V_474 , V_485 ) ;
return error ;
}
STATIC int
F_210 (
struct V_1 * log )
{
T_22 * V_396 ;
T_19 * V_387 ;
int error = 0 ;
struct V_398 V_399 ;
struct V_400 * V_401 ;
V_401 = log -> V_392 ;
F_152 ( & V_401 -> V_393 ) ;
V_396 = F_155 ( V_401 , & V_399 , 0 ) ;
while ( V_396 != NULL ) {
if ( V_396 -> V_408 != V_146 ) {
#ifdef F_211
for (; V_396 ; V_396 = F_157 ( V_401 , & V_399 ) )
ASSERT ( V_396 -> V_408 != V_146 ) ;
#endif
break;
}
V_387 = ( T_19 * ) V_396 ;
if ( F_197 ( V_477 , & V_387 -> V_478 ) ) {
V_396 = F_157 ( V_401 , & V_399 ) ;
continue;
}
F_159 ( & V_401 -> V_393 ) ;
error = F_196 ( log -> V_7 , V_387 ) ;
F_152 ( & V_401 -> V_393 ) ;
if ( error )
goto V_51;
V_396 = F_157 ( V_401 , & V_399 ) ;
}
V_51:
F_158 ( & V_399 ) ;
F_159 ( & V_401 -> V_393 ) ;
return error ;
}
STATIC void
F_212 (
T_4 * V_23 ,
T_24 V_412 ,
int V_149 )
{
T_28 * V_474 ;
T_31 * V_486 ;
T_1 * V_487 ;
int V_13 ;
int error ;
V_474 = F_202 ( V_23 , V_488 ) ;
error = F_203 ( V_474 , & F_204 ( V_23 ) -> V_489 , 0 , 0 ) ;
if ( error )
goto V_490;
error = F_213 ( V_23 , V_474 , V_412 , & V_487 ) ;
if ( error )
goto V_490;
V_486 = F_214 ( V_487 ) ;
V_486 -> V_491 [ V_149 ] = F_32 ( V_492 ) ;
V_13 = F_95 ( T_31 , V_491 ) +
( sizeof( T_12 ) * V_149 ) ;
F_215 ( V_474 , V_487 , V_13 ,
( V_13 + sizeof( T_12 ) - 1 ) ) ;
error = F_208 ( V_474 , 0 ) ;
if ( error )
goto V_493;
return;
V_490:
F_209 ( V_474 , V_485 ) ;
V_493:
F_3 ( V_23 , L_82 , V_8 , V_412 ) ;
return;
}
STATIC T_12
F_216 (
struct V_163 * V_23 ,
T_24 V_412 ,
T_12 V_494 ,
int V_149 )
{
struct V_5 * V_495 ;
struct V_185 * V_311 ;
struct V_314 * V_315 ;
T_32 V_496 ;
int error ;
V_496 = F_217 ( V_23 , V_412 , V_494 ) ;
error = F_218 ( V_23 , NULL , V_496 , 0 , 0 , & V_315 ) ;
if ( error )
goto V_497;
error = F_219 ( V_23 , NULL , & V_315 -> V_498 , & V_311 , & V_495 , 0 , 0 ) ;
if ( error )
goto V_499;
ASSERT ( V_315 -> V_320 . V_500 == 0 ) ;
ASSERT ( V_315 -> V_320 . V_344 != 0 ) ;
V_494 = F_30 ( V_311 -> V_179 ) ;
F_27 ( V_495 ) ;
V_315 -> V_320 . V_501 = 0 ;
F_220 ( V_315 ) ;
return V_494 ;
V_499:
F_220 ( V_315 ) ;
V_497:
F_212 ( V_23 , V_412 , V_149 ) ;
return V_492 ;
}
STATIC void
F_221 (
struct V_1 * log )
{
T_4 * V_23 ;
T_24 V_412 ;
T_31 * V_486 ;
T_1 * V_487 ;
T_12 V_494 ;
int V_149 ;
int error ;
T_6 V_502 ;
V_23 = log -> V_7 ;
V_502 = V_23 -> V_503 ;
V_23 -> V_503 = 0 ;
for ( V_412 = 0 ; V_412 < V_23 -> V_25 . V_419 ; V_412 ++ ) {
error = F_213 ( V_23 , NULL , V_412 , & V_487 ) ;
if ( error ) {
continue;
}
V_486 = F_214 ( V_487 ) ;
F_7 ( V_487 ) ;
for ( V_149 = 0 ; V_149 < V_504 ; V_149 ++ ) {
V_494 = F_30 ( V_486 -> V_491 [ V_149 ] ) ;
while ( V_494 != V_492 ) {
V_494 = F_216 ( V_23 ,
V_412 , V_494 , V_149 ) ;
}
}
F_222 ( V_487 ) ;
}
V_23 -> V_503 = V_502 ;
}
STATIC int
F_223 (
struct V_460 * V_73 ,
T_2 V_441 ,
struct V_1 * log )
{
T_33 V_505 ;
V_505 = F_224 ( log , V_73 , V_441 , F_30 ( V_73 -> V_61 ) ) ;
if ( V_505 != V_73 -> V_506 ) {
if ( V_73 -> V_506 || F_94 ( & log -> V_7 -> V_25 ) ) {
F_98 ( log -> V_7 ,
L_83 ,
F_225 ( V_73 -> V_506 ) ,
F_225 ( V_505 ) ) ;
F_226 ( V_441 , 32 ) ;
}
if ( F_94 ( & log -> V_7 -> V_25 ) )
return - V_16 ;
}
return 0 ;
}
STATIC int
F_227 (
struct V_460 * V_73 ,
T_2 V_441 ,
struct V_1 * log )
{
int V_45 , V_46 , V_507 ;
int error ;
error = F_223 ( V_73 , V_441 , log ) ;
if ( error )
return error ;
for ( V_45 = 0 ; V_45 < F_48 ( F_30 ( V_73 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_81 * ) V_441 = * ( V_81 * ) & V_73 -> V_508 [ V_45 ] ;
V_441 += V_52 ;
}
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
T_34 * V_509 = ( T_34 * ) V_73 ;
for ( ; V_45 < F_48 ( F_30 ( V_73 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_507 = V_45 % ( V_60 / V_52 ) ;
* ( V_81 * ) V_441 = V_509 [ V_46 ] . V_510 . V_511 [ V_507 ] ;
V_441 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_228 (
struct V_1 * log ,
struct V_460 * V_73 ,
T_3 V_159 )
{
int V_512 ;
if ( F_33 ( V_73 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_84 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_33 (
( ! V_73 -> V_93 ||
( F_30 ( V_73 -> V_93 ) & ( ~ V_513 ) ) ) ) ) {
F_3 ( log -> V_7 , L_85 ,
V_8 , F_30 ( V_73 -> V_93 ) ) ;
return - V_58 ;
}
V_512 = F_30 ( V_73 -> V_61 ) ;
if ( F_33 ( V_512 <= 0 || V_512 > V_70 ) ) {
F_4 ( L_86 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_33 ( V_159 > log -> V_3 || V_159 > V_70 ) ) {
F_4 ( L_87 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_229 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_124 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_514 , * V_515 ;
int error = 0 , V_59 ;
int V_516 , V_517 ;
int V_79 , V_518 , V_519 ;
struct V_458 V_459 [ V_520 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_47 ( & log -> V_7 -> V_25 ) ) {
V_514 = F_2 ( log , 1 ) ;
if ( ! V_514 )
return - V_49 ;
error = F_19 ( log , V_72 , 1 , V_514 , & V_13 ) ;
if ( error )
goto V_521;
V_73 = ( T_5 * ) V_13 ;
error = F_228 ( log , V_73 , V_72 ) ;
if ( error )
goto V_521;
V_59 = F_30 ( V_73 -> V_59 ) ;
if ( ( F_30 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_514 ) ;
V_514 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_514 = F_2 ( log , 1 ) ;
V_59 = V_522 ;
}
if ( ! V_514 )
return - V_49 ;
V_515 = F_2 ( log , F_48 ( V_59 ) ) ;
if ( ! V_515 ) {
F_8 ( V_514 ) ;
return - V_49 ;
}
memset ( V_459 , 0 , sizeof( V_459 ) ) ;
V_12 = V_72 ;
if ( V_72 > V_63 ) {
while ( V_12 < log -> V_3 ) {
V_13 = V_514 -> V_15 ;
V_518 = 0 ;
V_519 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_79 , V_514 ,
& V_13 ) ;
if ( error )
goto V_523;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_518 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_518 > 0 ) ;
error = F_19 ( log , V_12 ,
V_518 , V_514 ,
& V_13 ) ;
if ( error )
goto V_523;
}
V_519 = V_79 - V_518 ;
error = F_20 ( log , 0 ,
V_519 , V_514 ,
V_13 + F_11 ( V_518 ) ) ;
if ( error )
goto V_523;
}
V_73 = ( T_5 * ) V_13 ;
error = F_228 ( log , V_73 ,
V_518 ? V_12 : 0 ) ;
if ( error )
goto V_523;
V_516 = ( int ) F_48 ( F_30 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_516 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_516 , V_515 ,
& V_13 ) ;
if ( error )
goto V_523;
} else {
V_13 = V_515 -> V_15 ;
V_517 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_519 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_517 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_517 > 0 ) ;
error = F_19 ( log , V_12 ,
V_517 , V_515 ,
& V_13 ) ;
if ( error )
goto V_523;
}
error = F_20 ( log , 0 ,
V_516 - V_517 , V_515 ,
V_13 + F_11 ( V_517 ) ) ;
if ( error )
goto V_523;
}
error = F_227 ( V_73 , V_13 , log ) ;
if ( error )
goto V_523;
error = F_195 ( log , V_459 ,
V_73 , V_13 , V_124 ) ;
if ( error )
goto V_523;
V_12 += V_516 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
}
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_79 , V_514 , & V_13 ) ;
if ( error )
goto V_523;
V_73 = ( T_5 * ) V_13 ;
error = F_228 ( log , V_73 , V_12 ) ;
if ( error )
goto V_523;
V_516 = ( int ) F_48 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_516 , V_515 ,
& V_13 ) ;
if ( error )
goto V_523;
error = F_227 ( V_73 , V_13 , log ) ;
if ( error )
goto V_523;
error = F_195 ( log , V_459 ,
V_73 , V_13 , V_124 ) ;
if ( error )
goto V_523;
V_12 += V_516 + V_79 ;
}
V_523:
F_8 ( V_515 ) ;
V_521:
F_8 ( V_514 ) ;
return error ;
}
STATIC int
F_230 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_162 = F_178 ( V_524 *
sizeof( struct V_148 ) ,
V_157 ) ;
for ( V_45 = 0 ; V_45 < V_524 ; V_45 ++ )
F_179 ( & log -> V_162 [ V_45 ] ) ;
error = F_229 ( log , V_63 , V_72 ,
V_433 ) ;
if ( error != 0 ) {
F_91 ( log -> V_162 ) ;
log -> V_162 = NULL ;
return error ;
}
error = F_229 ( log , V_63 , V_72 ,
V_434 ) ;
#ifdef F_211
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_524 ; V_45 ++ )
ASSERT ( F_77 ( & log -> V_162 [ V_45 ] ) ) ;
}
#endif
F_91 ( log -> V_162 ) ;
log -> V_162 = NULL ;
return error ;
}
STATIC int
F_231 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_35 * V_525 ;
error = F_230 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_17 ( log -> V_7 ) ) {
return - V_58 ;
}
F_232 ( log -> V_7 ) ;
V_6 = F_233 ( log -> V_7 , 0 ) ;
F_234 ( V_6 ) ;
ASSERT ( ! ( F_235 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_236 ( V_6 ) ;
V_6 -> V_174 = & V_289 ;
error = F_16 ( V_6 ) ;
if ( error ) {
if ( ! F_17 ( log -> V_7 ) ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
}
F_27 ( V_6 ) ;
return error ;
}
V_525 = & log -> V_7 -> V_25 ;
F_237 ( V_525 , F_238 ( V_6 ) ) ;
ASSERT ( V_525 -> V_526 == V_232 ) ;
ASSERT ( F_239 ( V_525 ) ) ;
F_240 ( log -> V_7 ) ;
F_27 ( V_6 ) ;
F_241 ( log ) ;
log -> V_527 &= ~ V_528 ;
return 0 ;
}
int
V_122 (
struct V_1 * log )
{
T_3 V_63 , V_72 ;
int error ;
if ( ( error = F_53 ( log , & V_63 , & V_72 ) ) )
return error ;
if ( V_72 != V_63 ) {
if ( ( error = F_242 ( log -> V_7 , L_88 ) ) ) {
return error ;
}
if ( F_243 ( & log -> V_7 -> V_25 ) == V_529 &&
F_244 ( & log -> V_7 -> V_25 ,
V_530 ) ) {
F_3 ( log -> V_7 ,
L_89
L_90
L_91 ,
( log -> V_7 -> V_25 . V_531 &
V_530 ) ) ;
return - V_102 ;
}
if ( V_532 . V_533 ) {
F_245 ( log -> V_7 ,
L_92 ,
V_532 . V_533 ) ;
F_246 ( V_532 . V_533 * 1000 ) ;
}
F_245 ( log -> V_7 , L_93 ,
log -> V_7 -> V_534 ? log -> V_7 -> V_534
: L_94 ) ;
error = F_231 ( log , V_63 , V_72 ) ;
log -> V_527 |= V_535 ;
}
return error ;
}
int
F_247 (
struct V_1 * log )
{
if ( log -> V_527 & V_535 ) {
int error ;
error = F_210 ( log ) ;
if ( error ) {
F_98 ( log -> V_7 , L_95 ) ;
return error ;
}
F_248 ( log -> V_7 , V_536 ) ;
F_221 ( log ) ;
F_241 ( log ) ;
F_245 ( log -> V_7 , L_96 ,
log -> V_7 -> V_534 ? log -> V_7 -> V_534
: L_94 ) ;
log -> V_527 &= ~ V_535 ;
} else {
F_249 ( log -> V_7 , L_97 ) ;
}
return 0 ;
}
void
F_241 (
struct V_1 * log )
{
T_4 * V_23 ;
T_36 * V_537 ;
T_1 * V_538 ;
T_1 * V_487 ;
T_24 V_412 ;
T_23 V_539 ;
T_23 V_540 ;
T_23 V_541 ;
int error ;
V_23 = log -> V_7 ;
V_539 = 0LL ;
V_540 = 0LL ;
V_541 = 0LL ;
for ( V_412 = 0 ; V_412 < V_23 -> V_25 . V_419 ; V_412 ++ ) {
error = F_250 ( V_23 , NULL , V_412 , 0 , & V_538 ) ;
if ( error ) {
F_98 ( V_23 , L_98 ,
V_8 , V_412 , error ) ;
} else {
V_537 = F_251 ( V_538 ) ;
V_539 += F_30 ( V_537 -> V_542 ) +
F_30 ( V_537 -> V_543 ) ;
F_27 ( V_538 ) ;
}
error = F_213 ( V_23 , NULL , V_412 , & V_487 ) ;
if ( error ) {
F_98 ( V_23 , L_99 ,
V_8 , V_412 , error ) ;
} else {
struct V_217 * V_486 = F_214 ( V_487 ) ;
V_540 += F_30 ( V_486 -> V_544 ) ;
V_541 += F_30 ( V_486 -> V_545 ) ;
F_27 ( V_487 ) ;
}
}
}
