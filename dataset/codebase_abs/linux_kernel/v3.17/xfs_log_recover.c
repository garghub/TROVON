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
if ( F_16 ( log -> V_7 ) )
return - V_20 ;
F_17 ( V_6 ) ;
error = F_18 ( V_6 ) ;
if ( error )
F_19 ( V_6 , V_8 ) ;
return error ;
}
STATIC int
F_20 (
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
F_21 (
struct V_1 * log ,
T_3 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
T_2 V_13 )
{
T_2 V_21 = V_6 -> V_15 ;
int V_22 = F_11 ( V_6 -> V_14 ) ;
int error , V_23 ;
error = F_22 ( V_6 , V_13 , F_11 ( V_4 ) ) ;
if ( error )
return error ;
error = F_12 ( log , V_12 , V_4 , V_6 ) ;
V_23 = F_22 ( V_6 , V_21 , V_22 ) ;
if ( error )
return error ;
return V_23 ;
}
STATIC int
F_23 (
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
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
V_6 -> V_18 = V_4 ;
V_6 -> V_19 = 0 ;
error = F_27 ( V_6 ) ;
if ( error )
F_19 ( V_6 , V_8 ) ;
F_28 ( V_6 ) ;
return error ;
}
STATIC void
F_29 (
T_4 * V_24 ,
T_5 * V_25 )
{
F_30 ( V_24 , L_2 ,
V_8 , & V_24 -> V_26 . V_27 , V_28 ) ;
F_30 ( V_24 , L_3 ,
& V_25 -> V_29 , F_31 ( V_25 -> V_30 ) ) ;
}
STATIC int
F_32 (
T_4 * V_24 ,
T_5 * V_25 )
{
ASSERT ( V_25 -> V_31 == F_33 ( V_32 ) ) ;
if ( F_34 ( V_25 -> V_30 != F_33 ( V_28 ) ) ) {
F_3 ( V_24 ,
L_4 ) ;
F_29 ( V_24 , V_25 ) ;
F_4 ( L_5 ,
V_9 , V_24 ) ;
return - V_16 ;
} else if ( F_34 ( ! F_35 ( & V_24 -> V_26 . V_27 , & V_25 -> V_29 ) ) ) {
F_3 ( V_24 ,
L_6 ) ;
F_29 ( V_24 , V_25 ) ;
F_4 ( L_7 ,
V_9 , V_24 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_36 (
T_4 * V_24 ,
T_5 * V_25 )
{
ASSERT ( V_25 -> V_31 == F_33 ( V_32 ) ) ;
if ( F_37 ( & V_25 -> V_29 ) ) {
F_3 ( V_24 , L_8 ) ;
} else if ( F_34 ( ! F_35 ( & V_24 -> V_26 . V_27 , & V_25 -> V_29 ) ) ) {
F_3 ( V_24 , L_9 ) ;
F_29 ( V_24 , V_25 ) ;
F_4 ( L_10 ,
V_9 , V_24 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC void
F_38 (
struct V_5 * V_6 )
{
if ( V_6 -> V_19 ) {
F_19 ( V_6 , V_8 ) ;
F_39 ( V_6 -> V_33 -> V_34 ,
V_35 ) ;
}
V_6 -> V_36 = NULL ;
F_40 ( V_6 , 0 ) ;
}
STATIC int
F_41 (
struct V_1 * log ,
struct V_5 * V_6 ,
T_3 V_37 ,
T_3 * V_38 ,
T_6 V_39 )
{
T_2 V_13 ;
T_3 V_40 ;
T_3 V_41 ;
T_6 V_42 ;
int error ;
V_41 = * V_38 ;
V_40 = F_42 ( V_37 , V_41 ) ;
while ( V_40 != V_37 && V_40 != V_41 ) {
error = F_20 ( log , V_40 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_42 = F_43 ( V_13 ) ;
if ( V_42 == V_39 )
V_41 = V_40 ;
else
V_37 = V_40 ;
V_40 = F_42 ( V_37 , V_41 ) ;
}
ASSERT ( ( V_40 == V_37 && V_40 + 1 == V_41 ) ||
( V_40 == V_41 && V_40 - 1 == V_37 ) ) ;
* V_38 = V_41 ;
return 0 ;
}
STATIC int
F_44 (
struct V_1 * log ,
T_3 V_43 ,
int V_4 ,
T_6 V_44 ,
T_3 * V_45 )
{
T_3 V_46 , V_47 ;
T_6 V_39 ;
T_1 * V_6 ;
T_3 V_48 ;
T_2 V_49 = NULL ;
int error = 0 ;
V_48 = 1 << F_45 ( V_4 ) ;
while ( V_48 > log -> V_3 )
V_48 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_48 ) ) ) {
V_48 >>= 1 ;
if ( V_48 < log -> V_10 )
return - V_50 ;
}
for ( V_46 = V_43 ; V_46 < V_43 + V_4 ; V_46 += V_48 ) {
int V_51 ;
V_51 = F_46 ( V_48 , ( V_43 + V_4 - V_46 ) ) ;
error = F_20 ( log , V_46 , V_51 , V_6 , & V_49 ) ;
if ( error )
goto V_52;
for ( V_47 = 0 ; V_47 < V_51 ; V_47 ++ ) {
V_39 = F_43 ( V_49 ) ;
if ( V_39 == V_44 ) {
* V_45 = V_46 + V_47 ;
goto V_52;
}
V_49 += V_53 ;
}
}
* V_45 = - 1 ;
V_52:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_47 (
struct V_1 * log ,
T_3 V_43 ,
T_3 * V_38 ,
int V_54 )
{
T_3 V_46 ;
T_1 * V_6 ;
T_2 V_13 = NULL ;
T_5 * V_25 = NULL ;
int error = 0 ;
int V_55 = 0 ;
int V_56 = * V_38 - V_43 ;
int V_57 ;
ASSERT ( V_43 != 0 || * V_38 != V_43 ) ;
if ( ! ( V_6 = F_2 ( log , V_56 ) ) ) {
if ( ! ( V_6 = F_2 ( log , 1 ) ) )
return - V_50 ;
V_55 = 1 ;
} else {
error = F_20 ( log , V_43 , V_56 , V_6 , & V_13 ) ;
if ( error )
goto V_52;
V_13 += ( ( V_56 - 1 ) << V_58 ) ;
}
for ( V_46 = ( * V_38 ) - 1 ; V_46 >= 0 ; V_46 -- ) {
if ( V_46 < V_43 ) {
F_3 ( log -> V_7 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = - V_20 ;
goto V_52;
}
if ( V_55 ) {
error = F_20 ( log , V_46 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_52;
}
V_25 = ( T_5 * ) V_13 ;
if ( V_25 -> V_31 == F_33 ( V_32 ) )
break;
if ( ! V_55 )
V_13 -= V_53 ;
}
if ( V_46 == - 1 ) {
error = 1 ;
goto V_52;
}
if ( ( error = F_36 ( log -> V_7 , V_25 ) ) )
goto V_52;
if ( F_48 ( & log -> V_7 -> V_26 ) ) {
T_6 V_59 = F_31 ( V_25 -> V_59 ) ;
V_57 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_57 ++ ;
} else {
V_57 = 1 ;
}
if ( * V_38 - V_46 + V_54 !=
F_49 ( F_31 ( V_25 -> V_61 ) ) + V_57 )
* V_38 = V_46 ;
V_52:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_50 (
struct V_1 * log ,
T_3 * V_62 )
{
T_1 * V_6 ;
T_2 V_13 ;
T_3 V_45 , V_37 , V_43 , V_38 , V_63 ;
int V_64 ;
T_6 V_65 , V_66 ;
T_6 V_67 ;
int error , V_68 = log -> V_3 ;
error = F_51 ( log , & V_37 ) ;
if ( error < 0 ) {
F_3 ( log -> V_7 , L_12 ) ;
return error ;
}
if ( error == 1 ) {
* V_62 = V_37 ;
if ( ! V_37 ) {
F_3 ( log -> V_7 , L_13 ) ;
}
return 0 ;
}
V_37 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_50 ;
error = F_20 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_65 = F_43 ( V_13 ) ;
V_38 = V_63 = V_68 - 1 ;
error = F_20 ( log , V_38 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_66 = F_43 ( V_13 ) ;
ASSERT ( V_66 != 0 ) ;
if ( V_65 == V_66 ) {
V_63 = V_68 ;
V_67 = V_66 - 1 ;
} else {
V_67 = V_66 ;
if ( ( error = F_41 ( log , V_6 , V_37 ,
& V_63 , V_66 ) ) )
goto V_69;
}
V_64 = F_52 ( log ) ;
if ( V_63 >= V_64 ) {
V_43 = V_63 - V_64 ;
if ( ( error = F_44 ( log ,
V_43 , V_64 ,
V_67 , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 )
V_63 = V_45 ;
} else {
ASSERT ( V_63 <= V_70 &&
( T_3 ) V_64 >= V_63 ) ;
V_43 = V_68 - ( V_64 - V_63 ) ;
if ( ( error = F_44 ( log , V_43 ,
V_64 - ( int ) V_63 ,
( V_67 - 1 ) , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 ) {
V_63 = V_45 ;
goto V_71;
}
V_43 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_44 ( log ,
V_43 , ( int ) V_63 ,
V_67 , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 )
V_63 = V_45 ;
}
V_71:
V_64 = F_53 ( log ) ;
if ( V_63 >= V_64 ) {
V_43 = V_63 - V_64 ;
error = F_47 ( log , V_43 , & V_63 , 0 ) ;
if ( error == 1 )
error = - V_20 ;
if ( error )
goto V_69;
} else {
V_43 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
error = F_47 ( log , V_43 , & V_63 , 0 ) ;
if ( error < 0 )
goto V_69;
if ( error == 1 ) {
V_43 = V_68 - ( V_64 - V_63 ) ;
V_45 = V_68 ;
ASSERT ( V_43 <= V_70 &&
( T_3 ) V_68 - V_43 >= 0 ) ;
ASSERT ( V_63 <= V_70 ) ;
error = F_47 ( log , V_43 ,
& V_45 , ( int ) V_63 ) ;
if ( error == 1 )
error = - V_20 ;
if ( error )
goto V_69;
if ( V_45 != V_68 )
V_63 = V_45 ;
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
F_54 (
struct V_1 * log ,
T_3 * V_63 ,
T_3 * V_72 )
{
T_5 * V_73 ;
T_7 * V_74 ;
T_2 V_13 = NULL ;
T_1 * V_6 ;
int error , V_46 , V_75 ;
T_3 V_76 ;
T_3 V_77 ;
T_8 V_78 ;
int V_79 ;
V_75 = 0 ;
if ( ( error = F_50 ( log , V_63 ) ) )
return error ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_50 ;
if ( * V_63 == 0 ) {
error = F_20 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( F_43 ( V_13 ) == 0 ) {
* V_72 = 0 ;
goto V_80;
}
}
ASSERT ( * V_63 < V_70 ) ;
for ( V_46 = ( int ) ( * V_63 ) - 1 ; V_46 >= 0 ; V_46 -- ) {
error = F_20 ( log , V_46 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( * ( V_81 * ) V_13 == F_33 ( V_32 ) ) {
V_75 = 1 ;
break;
}
}
if ( ! V_75 ) {
for ( V_46 = log -> V_3 - 1 ; V_46 >= ( int ) ( * V_63 ) ; V_46 -- ) {
error = F_20 ( log , V_46 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( * ( V_81 * ) V_13 ==
F_33 ( V_32 ) ) {
V_75 = 2 ;
break;
}
}
}
if ( ! V_75 ) {
F_3 ( log -> V_7 , L_15 , V_8 ) ;
F_8 ( V_6 ) ;
ASSERT ( 0 ) ;
return - V_20 ;
}
V_73 = ( T_5 * ) V_13 ;
* V_72 = F_55 ( F_56 ( V_73 -> V_82 ) ) ;
log -> V_83 = V_46 ;
log -> V_84 = ( int ) * V_63 ;
log -> V_85 = F_31 ( V_73 -> V_86 ) ;
if ( V_75 == 2 )
log -> V_85 ++ ;
F_57 ( & log -> V_87 , F_56 ( V_73 -> V_82 ) ) ;
F_57 ( & log -> V_88 , F_56 ( V_73 -> V_89 ) ) ;
F_58 ( & log -> V_90 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
F_58 ( & log -> V_92 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
if ( F_48 ( & log -> V_7 -> V_26 ) ) {
int V_59 = F_31 ( V_73 -> V_59 ) ;
int V_93 = F_31 ( V_73 -> V_93 ) ;
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
V_77 = ( V_46 + V_79 + ( int )
F_49 ( F_31 ( V_73 -> V_61 ) ) ) % log -> V_3 ;
V_78 = F_59 ( & log -> V_87 ) ;
if ( * V_63 == V_77 &&
F_31 ( V_73 -> V_95 ) == 1 ) {
V_76 = ( V_46 + V_79 ) % log -> V_3 ;
error = F_20 ( log , V_76 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
V_74 = ( T_7 * ) V_13 ;
if ( V_74 -> V_96 & V_97 ) {
F_60 ( & log -> V_87 ,
log -> V_85 , V_77 ) ;
F_60 ( & log -> V_88 ,
log -> V_85 , V_77 ) ;
* V_72 = V_77 ;
log -> V_7 -> V_98 |= V_99 ;
}
}
if ( ! F_61 ( log -> V_7 -> V_11 ) )
error = F_62 ( log , V_78 ) ;
V_80:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_16 ) ;
return error ;
}
STATIC int
F_51 (
struct V_1 * log ,
T_3 * V_12 )
{
T_1 * V_6 ;
T_2 V_13 ;
T_6 V_100 , V_101 ;
T_3 V_45 , V_38 , V_43 ;
T_3 V_64 ;
int error , V_68 = log -> V_3 ;
* V_12 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return - V_50 ;
error = F_20 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_100 = F_43 ( V_13 ) ;
if ( V_100 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return 1 ;
}
error = F_20 ( log , V_68 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_101 = F_43 ( V_13 ) ;
if ( V_101 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_100 != 1 ) {
F_3 ( log -> V_7 ,
L_17 ) ;
error = - V_102 ;
goto V_69;
}
V_38 = V_68 - 1 ;
if ( ( error = F_41 ( log , V_6 , 0 , & V_38 , 0 ) ) )
goto V_69;
V_64 = F_52 ( log ) ;
ASSERT ( V_64 <= V_70 ) ;
if ( V_38 < V_64 )
V_64 = V_38 ;
V_43 = V_38 - V_64 ;
if ( ( error = F_44 ( log , V_43 ,
( int ) V_64 , 0 , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 )
V_38 = V_45 ;
error = F_47 ( log , V_43 , & V_38 , 0 ) ;
if ( error == 1 )
error = - V_20 ;
if ( error )
goto V_69;
* V_12 = V_38 ;
V_69:
F_8 ( V_6 ) ;
if ( error )
return error ;
return 1 ;
}
STATIC void
F_63 (
struct V_1 * log ,
T_2 V_49 ,
int V_39 ,
int V_103 ,
int V_104 ,
int V_105 )
{
T_5 * V_106 = ( T_5 * ) V_49 ;
memset ( V_49 , 0 , V_53 ) ;
V_106 -> V_31 = F_33 ( V_32 ) ;
V_106 -> V_86 = F_33 ( V_39 ) ;
V_106 -> V_93 = F_33 (
F_48 ( & log -> V_7 -> V_26 ) ? 2 : 1 ) ;
V_106 -> V_89 = F_64 ( F_65 ( V_39 , V_103 ) ) ;
V_106 -> V_82 = F_64 ( F_65 ( V_104 , V_105 ) ) ;
V_106 -> V_30 = F_33 ( V_28 ) ;
memcpy ( & V_106 -> V_29 , & log -> V_7 -> V_26 . V_27 , sizeof( V_107 ) ) ;
}
STATIC int
F_66 (
struct V_1 * log ,
int V_39 ,
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
int V_48 ;
int error = 0 ;
int V_46 , V_47 = 0 ;
V_48 = 1 << F_45 ( V_109 ) ;
while ( V_48 > log -> V_3 )
V_48 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_48 ) ) ) {
V_48 >>= 1 ;
if ( V_48 < V_112 )
return - V_50 ;
}
V_110 = F_13 ( V_108 , V_112 ) ;
if ( V_110 != V_108 ) {
error = F_12 ( log , V_108 , 1 , V_6 ) ;
if ( error )
goto V_114;
V_47 = V_108 - V_110 ;
}
for ( V_46 = V_108 ; V_46 < V_113 ; V_46 += V_48 ) {
int V_51 , V_115 ;
V_51 = F_46 ( V_48 , V_113 - V_108 ) ;
V_115 = V_51 - V_47 ;
V_111 = F_13 ( V_113 , V_112 ) ;
if ( V_47 == 0 && ( V_108 + V_115 > V_111 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_111 - V_108 ) ;
error = F_21 ( log , V_111 , V_112 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_108 , V_115 , V_6 ) ;
for (; V_47 < V_115 ; V_47 ++ ) {
F_63 ( log , V_13 , V_39 , V_46 + V_47 ,
V_104 , V_105 ) ;
V_13 += V_53 ;
}
error = F_23 ( log , V_108 , V_115 , V_6 ) ;
if ( error )
break;
V_108 += V_115 ;
V_47 = 0 ;
}
V_114:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_62 (
struct V_1 * log ,
T_8 V_78 )
{
int V_104 , V_116 ;
int V_105 , V_117 ;
int V_118 , V_119 ;
int V_120 ;
int error ;
V_104 = F_67 ( V_78 ) ;
V_105 = F_55 ( V_78 ) ;
V_116 = log -> V_85 ;
V_117 = log -> V_84 ;
if ( V_116 == V_104 ) {
if ( F_34 ( V_117 < V_105 || V_117 >= log -> V_3 ) ) {
F_4 ( L_18 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
V_118 = V_105 + ( log -> V_3 - V_117 ) ;
} else {
if ( F_34 ( V_117 >= V_105 || V_116 != ( V_104 + 1 ) ) ) {
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
V_119 = F_52 ( log ) ;
V_119 = F_68 ( V_119 , V_118 ) ;
if ( ( V_117 + V_119 ) <= log -> V_3 ) {
error = F_66 ( log , ( V_116 - 1 ) ,
V_117 , V_119 , V_104 ,
V_105 ) ;
if ( error )
return error ;
} else {
V_120 = log -> V_3 - V_117 ;
error = F_66 ( log , ( V_116 - 1 ) ,
V_117 , V_120 , V_104 ,
V_105 ) ;
if ( error )
return error ;
V_120 = V_119 - ( log -> V_3 - V_117 ) ;
error = F_66 ( log , V_116 , 0 , V_120 ,
V_104 , V_105 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC T_9 *
F_69 (
struct V_122 * V_25 ,
T_10 V_123 )
{
T_9 * V_124 ;
F_70 (trans, head, r_list) {
if ( V_124 -> V_125 == V_123 )
return V_124 ;
}
return NULL ;
}
STATIC void
F_71 (
struct V_122 * V_25 ,
T_10 V_123 ,
T_8 V_126 )
{
T_9 * V_124 ;
V_124 = F_72 ( sizeof( T_9 ) , V_127 ) ;
V_124 -> V_125 = V_123 ;
V_124 -> V_128 = V_126 ;
F_73 ( & V_124 -> V_129 ) ;
F_74 ( & V_124 -> V_130 ) ;
F_75 ( & V_124 -> V_130 , V_25 ) ;
}
STATIC void
F_76 (
struct V_131 * V_25 )
{
T_11 * V_132 ;
V_132 = F_72 ( sizeof( T_11 ) , V_127 ) ;
F_73 ( & V_132 -> V_133 ) ;
F_77 ( & V_132 -> V_133 , V_25 ) ;
}
STATIC int
F_78 (
struct V_1 * log ,
struct V_134 * V_124 ,
T_2 V_135 ,
int V_136 )
{
T_11 * V_132 ;
T_2 V_137 , V_138 ;
int V_139 ;
if ( F_79 ( & V_124 -> V_129 ) ) {
F_76 ( & V_124 -> V_129 ) ;
V_137 = ( T_2 ) & V_124 -> V_140 +
sizeof( V_141 ) - V_136 ;
memcpy ( V_137 , V_135 , V_136 ) ;
return 0 ;
}
V_132 = F_80 ( V_124 -> V_129 . V_142 , T_11 , V_133 ) ;
V_138 = V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_145 ;
V_139 = V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_146 ;
V_137 = F_81 ( V_138 , V_136 + V_139 , V_139 , V_127 ) ;
memcpy ( & V_137 [ V_139 ] , V_135 , V_136 ) ;
V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_146 += V_136 ;
V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_145 = V_137 ;
F_82 ( log , V_124 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_83 (
struct V_1 * log ,
struct V_134 * V_124 ,
T_2 V_135 ,
int V_136 )
{
T_12 * V_147 ;
T_11 * V_132 ;
T_2 V_137 ;
if ( ! V_136 )
return 0 ;
if ( F_79 ( & V_124 -> V_129 ) ) {
if ( * ( T_6 * ) V_135 != V_148 ) {
F_3 ( log -> V_7 , L_20 ,
V_8 ) ;
ASSERT ( 0 ) ;
return - V_20 ;
}
if ( V_136 == sizeof( V_141 ) )
F_76 ( & V_124 -> V_129 ) ;
memcpy ( & V_124 -> V_140 , V_135 , V_136 ) ;
return 0 ;
}
V_137 = F_84 ( V_136 , V_127 ) ;
memcpy ( V_137 , V_135 , V_136 ) ;
V_147 = ( T_12 * ) V_137 ;
V_132 = F_80 ( V_124 -> V_129 . V_142 , T_11 , V_133 ) ;
if ( V_132 -> V_149 != 0 &&
V_132 -> V_149 == V_132 -> V_144 ) {
F_76 ( & V_124 -> V_129 ) ;
V_132 = F_80 ( V_124 -> V_129 . V_142 ,
T_11 , V_133 ) ;
}
if ( V_132 -> V_149 == 0 ) {
if ( V_147 -> V_150 == 0 ||
V_147 -> V_150 > V_151 ) {
F_3 ( log -> V_7 ,
L_21 ,
V_147 -> V_150 ) ;
ASSERT ( 0 ) ;
F_85 ( V_137 ) ;
return - V_20 ;
}
V_132 -> V_149 = V_147 -> V_150 ;
V_132 -> V_143 =
F_72 ( V_132 -> V_149 * sizeof( V_152 ) ,
V_127 ) ;
}
ASSERT ( V_132 -> V_149 > V_132 -> V_144 ) ;
V_132 -> V_143 [ V_132 -> V_144 ] . V_145 = V_137 ;
V_132 -> V_143 [ V_132 -> V_144 ] . V_146 = V_136 ;
V_132 -> V_144 ++ ;
F_86 ( log , V_124 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_87 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
T_11 * V_132 , * V_154 ;
int error = 0 ;
F_88 ( V_155 ) ;
F_88 ( V_156 ) ;
F_88 ( V_157 ) ;
F_88 ( V_158 ) ;
F_88 ( V_159 ) ;
F_89 ( & V_124 -> V_129 , & V_155 ) ;
F_90 (item, n, &sort_list, ri_list) {
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
switch ( F_91 ( V_132 ) ) {
case V_161 :
F_92 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_162 :
if ( V_160 -> V_163 & V_164 ) {
F_93 ( log ,
V_124 , V_132 , V_153 ) ;
F_94 ( & V_132 -> V_133 , & V_156 ) ;
break;
}
if ( V_160 -> V_163 & V_165 ) {
F_94 ( & V_132 -> V_133 , & V_158 ) ;
break;
}
F_92 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
F_95 ( log ,
V_124 , V_132 , V_153 ) ;
F_92 ( & V_132 -> V_133 , & V_159 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_22 ,
V_8 ) ;
ASSERT ( 0 ) ;
if ( ! F_79 ( & V_155 ) )
F_89 ( & V_155 , & V_124 -> V_129 ) ;
error = - V_20 ;
goto V_52;
}
}
V_52:
ASSERT ( F_79 ( & V_155 ) ) ;
if ( ! F_79 ( & V_157 ) )
F_96 ( & V_157 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_159 ) )
F_97 ( & V_159 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_158 ) )
F_97 ( & V_158 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_156 ) )
F_97 ( & V_156 , & V_124 -> V_129 ) ;
return error ;
}
STATIC int
F_98 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_131 * V_172 ;
struct V_173 * V_174 ;
if ( ! ( V_160 -> V_163 & V_164 ) ) {
F_99 ( log , V_160 ) ;
return 0 ;
}
V_172 = F_100 ( log , V_160 -> V_175 ) ;
F_101 (bcp, bucket, bc_list) {
if ( V_174 -> V_176 == V_160 -> V_175 &&
V_174 -> V_177 == V_160 -> V_178 ) {
V_174 -> V_179 ++ ;
F_102 ( log , V_160 ) ;
return 0 ;
}
}
V_174 = F_84 ( sizeof( struct V_173 ) , V_127 ) ;
V_174 -> V_176 = V_160 -> V_175 ;
V_174 -> V_177 = V_160 -> V_178 ;
V_174 -> V_179 = 1 ;
F_77 ( & V_174 -> V_180 , V_172 ) ;
F_103 ( log , V_160 ) ;
return 0 ;
}
STATIC struct V_173 *
F_104 (
struct V_1 * log ,
T_3 V_181 ,
T_6 V_136 ,
T_14 V_182 )
{
struct V_131 * V_172 ;
struct V_173 * V_174 ;
if ( ! log -> V_183 ) {
ASSERT ( ! ( V_182 & V_164 ) ) ;
return NULL ;
}
V_172 = F_100 ( log , V_181 ) ;
F_101 (bcp, bucket, bc_list) {
if ( V_174 -> V_176 == V_181 && V_174 -> V_177 == V_136 )
return V_174 ;
}
ASSERT ( ! ( V_182 & V_164 ) ) ;
return NULL ;
}
STATIC int
F_105 (
struct V_1 * log ,
T_3 V_181 ,
T_6 V_136 ,
T_14 V_182 )
{
struct V_173 * V_174 ;
V_174 = F_104 ( log , V_181 , V_136 , V_182 ) ;
if ( ! V_174 )
return 0 ;
if ( V_182 & V_164 ) {
if ( -- V_174 -> V_179 == 0 ) {
F_106 ( & V_174 -> V_180 ) ;
F_85 ( V_174 ) ;
}
}
return 1 ;
}
STATIC int
F_107 (
struct V_184 * V_24 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_46 ;
int V_185 = 0 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_189 = 0 ;
int V_190 ;
int V_191 ;
T_15 * V_192 ;
T_15 * V_193 ;
F_108 ( V_24 -> V_194 , V_160 ) ;
if ( F_109 ( & V_24 -> V_26 ) )
V_6 -> V_195 = & V_196 ;
V_191 = F_11 ( V_6 -> V_18 ) >> V_24 -> V_26 . V_197 ;
for ( V_46 = 0 ; V_46 < V_191 ; V_46 ++ ) {
V_190 = ( V_46 * V_24 -> V_26 . V_198 ) +
F_110 ( V_199 , V_200 ) ;
while ( V_190 >=
( V_188 + V_189 ) ) {
V_186 += V_187 ;
V_186 = F_111 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
return 0 ;
V_187 = F_112 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
ASSERT ( V_187 > 0 ) ;
V_188 = V_186 << V_203 ;
V_189 = V_187 << V_203 ;
V_185 ++ ;
}
if ( V_190 < V_188 )
continue;
ASSERT ( V_132 -> V_143 [ V_185 ] . V_145 != NULL ) ;
ASSERT ( ( V_132 -> V_143 [ V_185 ] . V_146 % V_204 ) == 0 ) ;
ASSERT ( ( V_188 + V_189 ) <=
F_11 ( V_6 -> V_18 ) ) ;
V_192 = V_132 -> V_143 [ V_185 ] . V_145 +
V_190 - V_188 ;
if ( F_34 ( * V_192 == 0 ) ) {
F_113 ( V_24 ,
L_23
L_24 ,
V_132 , V_6 ) ;
F_4 ( L_25 ,
V_121 , V_24 ) ;
return - V_16 ;
}
V_193 = ( T_15 * ) F_114 ( V_6 ,
V_190 ) ;
* V_193 = * V_192 ;
F_115 ( V_24 , (struct V_205 * )
F_114 ( V_6 , V_46 * V_24 -> V_26 . V_198 ) ) ;
}
return 0 ;
}
static T_8
F_116 (
struct V_184 * V_24 ,
struct V_5 * V_6 )
{
T_16 V_206 ;
T_17 V_207 ;
T_17 V_208 ;
void * V_209 = V_6 -> V_15 ;
V_107 * V_210 ;
T_8 V_126 = - 1 ;
if ( ! F_109 ( & V_24 -> V_26 ) )
goto V_211;
V_206 = F_31 ( * ( V_81 * ) V_209 ) ;
switch ( V_206 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 : {
struct V_218 * V_219 = V_209 ;
V_126 = F_56 ( V_219 -> V_220 . V_221 . V_222 ) ;
V_210 = & V_219 -> V_220 . V_221 . V_223 ;
break;
}
case V_224 :
case V_225 : {
struct V_218 * V_219 = V_209 ;
V_126 = F_56 ( V_219 -> V_220 . V_226 . V_222 ) ;
V_210 = & V_219 -> V_220 . V_226 . V_223 ;
break;
}
case V_227 :
V_126 = F_56 ( ( (struct V_228 * ) V_209 ) -> V_229 ) ;
V_210 = & ( (struct V_228 * ) V_209 ) -> V_230 ;
break;
case V_231 :
V_126 = F_56 ( ( (struct V_232 * ) V_209 ) -> V_233 ) ;
V_210 = & ( (struct V_232 * ) V_209 ) -> V_234 ;
break;
case V_235 :
V_126 = F_56 ( ( (struct V_236 * ) V_209 ) -> V_237 ) ;
V_210 = & ( (struct V_236 * ) V_209 ) -> V_238 ;
break;
case V_239 :
V_126 = F_56 ( ( (struct V_240 * ) V_209 ) -> V_241 ) ;
V_210 = & ( (struct V_240 * ) V_209 ) -> V_242 ;
break;
case V_243 :
case V_244 :
case V_245 :
V_126 = F_56 ( ( (struct V_246 * ) V_209 ) -> V_126 ) ;
V_210 = & ( (struct V_246 * ) V_209 ) -> V_210 ;
break;
case V_247 :
V_126 = F_56 ( ( (struct V_248 * ) V_209 ) -> V_249 ) ;
V_210 = & ( (struct V_248 * ) V_209 ) -> V_250 ;
break;
case V_251 :
V_126 = F_56 ( ( (struct V_252 * ) V_209 ) -> V_253 ) ;
V_210 = & ( (struct V_252 * ) V_209 ) -> V_27 ;
break;
default:
break;
}
if ( V_126 != ( T_8 ) - 1 ) {
if ( ! F_35 ( & V_24 -> V_26 . V_27 , V_210 ) )
goto V_211;
return V_126 ;
}
V_208 = F_117 ( ( (struct V_254 * ) V_209 ) -> V_255 ) ;
switch ( V_208 ) {
case V_256 :
case V_257 :
case V_258 :
V_126 = F_56 ( ( (struct V_259 * ) V_209 ) -> V_126 ) ;
V_210 = & ( (struct V_259 * ) V_209 ) -> V_210 ;
break;
default:
break;
}
if ( V_126 != ( T_8 ) - 1 ) {
if ( ! F_35 ( & V_24 -> V_26 . V_27 , V_210 ) )
goto V_211;
return V_126 ;
}
V_207 = F_117 ( * ( V_260 * ) V_209 ) ;
switch ( V_207 ) {
case V_261 :
case V_262 :
goto V_211;
default:
break;
}
V_211:
return ( T_8 ) - 1 ;
}
static void
F_118 (
struct V_184 * V_24 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
struct V_254 * V_263 = V_6 -> V_15 ;
T_16 V_206 ;
T_17 V_207 ;
T_17 V_208 ;
if ( ! F_109 ( & V_24 -> V_26 ) )
return;
V_206 = F_31 ( * ( V_81 * ) V_6 -> V_15 ) ;
V_207 = F_117 ( * ( V_260 * ) V_6 -> V_15 ) ;
V_208 = F_117 ( V_263 -> V_255 ) ;
switch ( F_119 ( V_160 ) ) {
case V_264 :
switch ( V_206 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
V_6 -> V_195 = & V_265 ;
break;
case V_216 :
case V_266 :
case V_217 :
case V_267 :
V_6 -> V_195 = & V_268 ;
break;
case V_224 :
case V_225 :
V_6 -> V_195 = & V_269 ;
break;
default:
F_3 ( V_24 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_270 :
if ( V_206 != V_227 ) {
F_3 ( V_24 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_271 ;
break;
case V_272 :
if ( V_206 != V_231 ) {
F_3 ( V_24 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_273 ;
break;
case V_274 :
if ( V_206 != V_235 ) {
F_3 ( V_24 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_275 ;
break;
case V_276 :
case V_277 :
case V_278 :
#ifdef F_120
if ( V_207 != V_261 ) {
F_3 ( V_24 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_279 ;
#else
F_113 ( V_24 ,
L_31 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_280 :
if ( V_207 != V_262 ) {
F_3 ( V_24 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_196 ;
break;
case V_281 :
if ( V_206 != V_239 ) {
F_3 ( V_24 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_282 ;
break;
case V_283 :
if ( V_206 != V_284 &&
V_206 != V_243 ) {
F_3 ( V_24 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_285 ;
break;
case V_286 :
if ( V_206 != V_287 &&
V_206 != V_244 ) {
F_3 ( V_24 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_288 ;
break;
case V_289 :
if ( V_206 != V_290 &&
V_206 != V_245 ) {
F_3 ( V_24 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_291 ;
break;
case V_292 :
if ( V_208 != V_293 &&
V_208 != V_256 ) {
F_3 ( V_24 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_294 ;
break;
case V_295 :
if ( V_208 != V_296 &&
V_208 != V_257 ) {
F_3 ( V_24 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_297 ;
break;
case V_298 :
if ( V_208 != V_299 &&
V_208 != V_258 ) {
F_3 ( V_24 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_300 ;
break;
case V_301 :
if ( V_208 != V_302 &&
V_208 != V_303 ) {
F_3 ( V_24 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_304 ;
break;
case V_305 :
if ( V_206 != V_247 ) {
F_3 ( V_24 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_306 ;
break;
case V_307 :
if ( V_206 != V_251 ) {
F_3 ( V_24 , L_42 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_308 ;
break;
default:
F_3 ( V_24 , L_43 ,
F_119 ( V_160 ) ) ;
break;
}
}
STATIC void
F_121 (
struct V_184 * V_24 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_46 ;
int V_186 ;
int V_187 ;
int error ;
F_122 ( V_24 -> V_194 , V_160 ) ;
V_186 = 0 ;
V_46 = 1 ;
while ( 1 ) {
V_186 = F_111 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
break;
V_187 = F_112 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
ASSERT ( V_187 > 0 ) ;
ASSERT ( V_132 -> V_143 [ V_46 ] . V_145 != NULL ) ;
ASSERT ( V_132 -> V_143 [ V_46 ] . V_146 % V_204 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_18 ) >=
( ( T_6 ) V_186 << V_203 ) + ( V_187 << V_203 ) ) ;
if ( V_132 -> V_143 [ V_46 ] . V_146 < ( V_187 << V_203 ) )
V_187 = V_132 -> V_143 [ V_46 ] . V_146 >> V_203 ;
error = 0 ;
if ( V_160 -> V_163 &
( V_309 | V_310 | V_311 ) ) {
if ( V_132 -> V_143 [ V_46 ] . V_145 == NULL ) {
F_113 ( V_24 ,
L_44 , V_8 ) ;
goto V_312;
}
if ( V_132 -> V_143 [ V_46 ] . V_146 < sizeof( V_313 ) ) {
F_113 ( V_24 ,
L_45 ,
V_132 -> V_143 [ V_46 ] . V_146 , V_8 ) ;
goto V_312;
}
error = F_123 ( V_24 , V_132 -> V_143 [ V_46 ] . V_145 ,
- 1 , 0 , V_314 ,
L_46 ) ;
if ( error )
goto V_312;
}
memcpy ( F_114 ( V_6 ,
( T_6 ) V_186 << V_203 ) ,
V_132 -> V_143 [ V_46 ] . V_145 ,
V_187 << V_203 ) ;
V_312:
V_46 ++ ;
V_186 += V_187 ;
}
ASSERT ( V_46 == V_132 -> V_149 ) ;
F_118 ( V_24 , V_6 , V_160 ) ;
}
STATIC bool
F_124 (
struct V_184 * V_24 ,
struct V_1 * log ,
struct V_171 * V_132 ,
struct V_5 * V_6 ,
struct V_315 * V_160 )
{
T_6 type ;
F_125 ( log , V_160 ) ;
if ( ! V_24 -> V_316 )
return false ;
type = 0 ;
if ( V_160 -> V_163 & V_309 )
type |= V_317 ;
if ( V_160 -> V_163 & V_310 )
type |= V_318 ;
if ( V_160 -> V_163 & V_311 )
type |= V_319 ;
if ( log -> V_320 & type )
return false ;
F_121 ( V_24 , V_132 , V_6 , V_160 ) ;
return true ;
}
STATIC int
F_126 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_321 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
T_4 * V_24 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_322 ;
T_8 V_126 ;
if ( F_105 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
F_127 ( log , V_160 ) ;
return 0 ;
}
F_128 ( log , V_160 ) ;
V_322 = 0 ;
if ( V_160 -> V_163 & V_165 )
V_322 |= V_323 ;
V_6 = F_129 ( V_24 -> V_324 , V_160 -> V_175 , V_160 -> V_178 ,
V_322 , NULL ) ;
if ( ! V_6 )
return - V_50 ;
error = V_6 -> V_19 ;
if ( error ) {
F_19 ( V_6 , L_47 ) ;
goto V_325;
}
V_126 = F_116 ( V_24 , V_6 ) ;
if ( V_126 && V_126 != - 1 && F_130 ( V_126 , V_321 ) >= 0 ) {
F_118 ( V_24 , V_6 , V_160 ) ;
goto V_325;
}
if ( V_160 -> V_163 & V_165 ) {
error = F_107 ( V_24 , V_132 , V_6 , V_160 ) ;
if ( error )
goto V_325;
} else if ( V_160 -> V_163 &
( V_309 | V_310 | V_311 ) ) {
bool V_326 ;
V_326 = F_124 ( V_24 , log , V_132 , V_6 , V_160 ) ;
if ( ! V_326 )
goto V_325;
} else {
F_121 ( V_24 , V_132 , V_6 , V_160 ) ;
}
if ( V_262 ==
F_117 ( * ( ( V_260 * ) F_114 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_131 ( log -> V_7 -> V_26 . V_327 ,
( T_16 ) log -> V_7 -> V_328 ) ) ) {
F_132 ( V_6 ) ;
error = F_27 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_33 -> V_34 == V_24 ) ;
V_6 -> V_36 = F_38 ;
F_133 ( V_6 , V_157 ) ;
}
V_325:
F_28 ( V_6 ) ;
return error ;
}
STATIC int
F_134 (
struct V_184 * V_24 ,
struct V_205 * V_329 ,
struct V_330 * V_147 ,
struct V_131 * V_157 )
{
struct V_331 * V_332 ;
int error ;
ASSERT ( V_147 -> V_333 & ( V_334 | V_335 ) ) ;
V_332 = F_135 ( V_24 , V_147 -> V_336 ) ;
if ( ! V_332 )
return - V_50 ;
F_136 ( & V_332 -> V_337 , V_329 ) ;
ASSERT ( V_332 -> V_337 . V_338 >= 3 ) ;
error = F_137 ( V_332 , V_329 ) ;
if ( error )
goto V_339;
if ( V_147 -> V_333 & V_334 ) {
ASSERT ( V_147 -> V_333 & V_340 ) ;
error = F_138 ( NULL , V_332 , V_341 ,
V_332 -> V_342 , V_157 ) ;
if ( error )
goto V_339;
}
if ( V_147 -> V_333 & V_335 ) {
ASSERT ( V_147 -> V_333 & V_343 ) ;
error = F_138 ( NULL , V_332 , V_344 ,
V_332 -> V_342 , V_157 ) ;
if ( error )
goto V_339;
}
V_339:
F_139 ( V_332 ) ;
return error ;
}
STATIC int
F_140 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_321 )
{
T_12 * V_147 ;
T_4 * V_24 = log -> V_7 ;
T_1 * V_6 ;
V_199 * V_329 ;
int V_136 ;
T_2 V_345 ;
T_2 V_346 ;
int error ;
int V_347 ;
T_6 V_348 ;
T_18 * V_349 ;
T_6 V_350 ;
int V_351 = 0 ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( T_12 ) ) {
V_147 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_147 = F_84 ( sizeof( T_12 ) , V_127 ) ;
V_351 = 1 ;
error = F_141 ( & V_132 -> V_143 [ 0 ] , V_147 ) ;
if ( error )
goto error;
}
if ( F_105 ( log , V_147 -> V_352 ,
V_147 -> V_353 , 0 ) ) {
error = 0 ;
F_142 ( log , V_147 ) ;
goto error;
}
F_143 ( log , V_147 ) ;
V_6 = F_129 ( V_24 -> V_324 , V_147 -> V_352 , V_147 -> V_353 , 0 ,
& V_196 ) ;
if ( ! V_6 ) {
error = - V_50 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_19 ( V_6 , L_48 ) ;
goto V_325;
}
ASSERT ( V_147 -> V_333 & V_354 ) ;
V_329 = ( V_199 * ) F_114 ( V_6 , V_147 -> V_355 ) ;
if ( F_34 ( V_329 -> V_356 != F_144 ( V_262 ) ) ) {
F_113 ( V_24 ,
L_49 ,
V_8 , V_329 , V_6 , V_147 -> V_336 ) ;
F_4 ( L_50 ,
V_121 , V_24 ) ;
error = - V_16 ;
goto V_325;
}
V_349 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( F_34 ( V_349 -> V_356 != V_262 ) ) {
F_113 ( V_24 ,
L_51 ,
V_8 , V_132 , V_147 -> V_336 ) ;
F_4 ( L_52 ,
V_121 , V_24 ) ;
error = - V_16 ;
goto V_325;
}
if ( V_329 -> V_338 >= 3 ) {
T_8 V_126 = F_56 ( V_329 -> V_357 ) ;
if ( V_126 && V_126 != - 1 && F_130 ( V_126 , V_321 ) >= 0 ) {
F_145 ( log , V_147 ) ;
error = 0 ;
goto V_358;
}
}
if ( ! F_109 ( & V_24 -> V_26 ) &&
V_349 -> V_359 < F_117 ( V_329 -> V_359 ) ) {
if ( F_117 ( V_329 -> V_359 ) == V_360 &&
V_349 -> V_359 < ( V_360 >> 1 ) ) {
} else {
F_145 ( log , V_147 ) ;
error = 0 ;
goto V_325;
}
}
V_349 -> V_359 = 0 ;
if ( F_34 ( F_146 ( V_349 -> V_361 ) ) ) {
if ( ( V_349 -> V_362 != V_363 ) &&
( V_349 -> V_362 != V_364 ) ) {
F_147 ( L_53 ,
V_121 , V_24 , V_349 ) ;
F_113 ( V_24 ,
L_54
L_55 ,
V_8 , V_132 , V_329 , V_6 , V_147 -> V_336 ) ;
error = - V_16 ;
goto V_325;
}
} else if ( F_34 ( F_148 ( V_349 -> V_361 ) ) ) {
if ( ( V_349 -> V_362 != V_363 ) &&
( V_349 -> V_362 != V_364 ) &&
( V_349 -> V_362 != V_365 ) ) {
F_147 ( L_56 ,
V_121 , V_24 , V_349 ) ;
F_113 ( V_24 ,
L_57
L_55 ,
V_8 , V_132 , V_329 , V_6 , V_147 -> V_336 ) ;
error = - V_16 ;
goto V_325;
}
}
if ( F_34 ( V_349 -> V_366 + V_349 -> V_367 > V_349 -> V_368 ) ) {
F_147 ( L_58 ,
V_121 , V_24 , V_349 ) ;
F_113 ( V_24 ,
L_59
L_60 ,
V_8 , V_132 , V_329 , V_6 , V_147 -> V_336 ,
V_349 -> V_366 + V_349 -> V_367 ,
V_349 -> V_368 ) ;
error = - V_16 ;
goto V_325;
}
if ( F_34 ( V_349 -> V_369 > V_24 -> V_26 . V_198 ) ) {
F_147 ( L_61 ,
V_121 , V_24 , V_349 ) ;
F_113 ( V_24 ,
L_59
L_62 , V_8 ,
V_132 , V_329 , V_6 , V_147 -> V_336 , V_349 -> V_369 ) ;
error = - V_16 ;
goto V_325;
}
V_350 = F_149 ( V_349 -> V_338 ) ;
if ( F_34 ( V_132 -> V_143 [ 1 ] . V_146 > V_350 ) ) {
F_147 ( L_63 ,
V_121 , V_24 , V_349 ) ;
F_113 ( V_24 ,
L_64 ,
V_8 , V_132 -> V_143 [ 1 ] . V_146 , V_132 ) ;
error = - V_16 ;
goto V_325;
}
F_150 ( V_329 , V_349 ) ;
if ( V_132 -> V_143 [ 1 ] . V_146 > V_350 ) {
memcpy ( ( char * ) V_329 + V_350 ,
V_132 -> V_143 [ 1 ] . V_145 + V_350 ,
V_132 -> V_143 [ 1 ] . V_146 - V_350 ) ;
}
V_348 = V_147 -> V_333 ;
switch ( V_348 & ( V_370 | V_371 ) ) {
case V_370 :
F_151 ( V_329 , V_147 -> V_372 . V_373 ) ;
break;
case V_371 :
memcpy ( F_152 ( V_329 ) ,
& V_147 -> V_372 . V_374 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_147 -> V_150 == 2 )
goto V_358;
V_136 = V_132 -> V_143 [ 2 ] . V_146 ;
V_345 = V_132 -> V_143 [ 2 ] . V_145 ;
ASSERT ( V_147 -> V_150 <= 4 ) ;
ASSERT ( ( V_147 -> V_150 == 3 ) || ( V_348 & V_375 ) ) ;
ASSERT ( ! ( V_348 & V_376 ) ||
( V_136 == V_147 -> V_377 ) ) ;
switch ( V_348 & V_376 ) {
case V_378 :
case V_379 :
memcpy ( F_152 ( V_329 ) , V_345 , V_136 ) ;
break;
case V_340 :
F_153 ( V_24 , (struct V_218 * ) V_345 , V_136 ,
( V_380 * ) F_152 ( V_329 ) ,
F_154 ( V_329 , V_24 ) ) ;
break;
default:
ASSERT ( ( V_348 & V_376 ) == 0 ) ;
break;
}
if ( V_147 -> V_333 & V_375 ) {
if ( V_147 -> V_333 & V_376 ) {
V_347 = 3 ;
} else {
V_347 = 2 ;
}
V_136 = V_132 -> V_143 [ V_347 ] . V_146 ;
V_345 = V_132 -> V_143 [ V_347 ] . V_145 ;
ASSERT ( V_136 == V_147 -> V_381 ) ;
switch ( V_147 -> V_333 & V_375 ) {
case V_382 :
case V_383 :
V_346 = F_155 ( V_329 ) ;
ASSERT ( V_136 <= F_156 ( V_329 , V_24 ) ) ;
memcpy ( V_346 , V_345 , V_136 ) ;
break;
case V_343 :
V_346 = F_155 ( V_329 ) ;
F_153 ( V_24 , (struct V_218 * ) V_345 ,
V_136 , ( V_380 * ) V_346 ,
F_156 ( V_329 , V_24 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_65 , V_8 ) ;
ASSERT ( 0 ) ;
error = - V_20 ;
goto V_325;
}
}
V_358:
if ( V_147 -> V_333 & ( V_334 | V_335 ) )
error = F_134 ( V_24 , V_329 , V_147 ,
V_157 ) ;
F_115 ( log -> V_7 , V_329 ) ;
ASSERT ( V_6 -> V_33 -> V_34 == V_24 ) ;
V_6 -> V_36 = F_38 ;
F_133 ( V_6 , V_157 ) ;
V_325:
F_28 ( V_6 ) ;
error:
if ( V_351 )
F_85 ( V_147 ) ;
return error ;
}
STATIC int
F_157 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_19 * V_384 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_384 ) ;
if ( V_384 -> V_385 & V_386 )
log -> V_320 |= V_317 ;
if ( V_384 -> V_385 & V_387 )
log -> V_320 |= V_318 ;
if ( V_384 -> V_385 & V_388 )
log -> V_320 |= V_319 ;
return 0 ;
}
STATIC int
F_158 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_321 )
{
T_4 * V_24 = log -> V_7 ;
T_1 * V_6 ;
struct V_389 * V_390 , * V_391 ;
int error ;
T_20 * V_392 ;
T_6 type ;
if ( V_24 -> V_316 == 0 )
return 0 ;
V_391 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_391 == NULL ) {
F_113 ( log -> V_7 , L_66 , V_8 ) ;
return - V_20 ;
}
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( V_313 ) ) {
F_113 ( log -> V_7 , L_67 ,
V_132 -> V_143 [ 1 ] . V_146 , V_8 ) ;
return - V_20 ;
}
type = V_391 -> V_393 & ( V_317 | V_318 | V_319 ) ;
ASSERT ( type ) ;
if ( log -> V_320 & type )
return 0 ;
V_392 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_392 ) ;
error = F_123 ( V_24 , V_391 , V_392 -> V_394 , 0 , V_314 ,
L_68 ) ;
if ( error )
return - V_20 ;
ASSERT ( V_392 -> V_395 == 1 ) ;
error = F_159 ( V_24 , NULL , V_24 -> V_324 , V_392 -> V_396 ,
F_160 ( V_24 , V_392 -> V_395 ) , 0 , & V_6 ,
& V_279 ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_390 = ( V_313 * ) F_114 ( V_6 , V_392 -> V_397 ) ;
if ( F_109 ( & V_24 -> V_26 ) ) {
struct V_398 * V_399 = (struct V_398 * ) V_390 ;
T_8 V_126 = F_56 ( V_399 -> V_400 ) ;
if ( V_126 && V_126 != - 1 && F_130 ( V_126 , V_321 ) >= 0 ) {
goto V_325;
}
}
memcpy ( V_390 , V_391 , V_132 -> V_143 [ 1 ] . V_146 ) ;
if ( F_109 ( & V_24 -> V_26 ) ) {
F_161 ( ( char * ) V_390 , sizeof( struct V_398 ) ,
V_401 ) ;
}
ASSERT ( V_392 -> V_402 == 2 ) ;
ASSERT ( V_6 -> V_33 -> V_34 == V_24 ) ;
V_6 -> V_36 = F_38 ;
F_133 ( V_6 , V_157 ) ;
V_325:
F_28 ( V_6 ) ;
return 0 ;
}
STATIC int
F_162 (
struct V_1 * log ,
struct V_171 * V_132 ,
T_8 V_126 )
{
int error ;
T_4 * V_24 = log -> V_7 ;
T_21 * V_403 ;
T_22 * V_404 ;
V_404 = V_132 -> V_143 [ 0 ] . V_145 ;
V_403 = F_163 ( V_24 , V_404 -> V_405 ) ;
if ( ( error = F_164 ( & ( V_132 -> V_143 [ 0 ] ) ,
& ( V_403 -> V_406 ) ) ) ) {
F_165 ( V_403 ) ;
return error ;
}
F_166 ( & V_403 -> V_407 , V_404 -> V_405 ) ;
F_167 ( & log -> V_408 -> V_409 ) ;
F_168 ( log -> V_408 , & V_403 -> V_410 , V_126 ) ;
return 0 ;
}
STATIC int
F_169 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_23 * V_411 ;
T_21 * V_403 = NULL ;
T_24 * V_412 ;
T_25 V_413 ;
struct V_414 V_415 ;
struct V_416 * V_417 = log -> V_408 ;
V_411 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( ( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_418 ) +
( ( V_411 -> V_419 - 1 ) * sizeof( V_420 ) ) ) ) ||
( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_421 ) +
( ( V_411 -> V_419 - 1 ) * sizeof( V_422 ) ) ) ) ) ;
V_413 = V_411 -> V_423 ;
F_167 ( & V_417 -> V_409 ) ;
V_412 = F_170 ( V_417 , & V_415 , 0 ) ;
while ( V_412 != NULL ) {
if ( V_412 -> V_424 == V_170 ) {
V_403 = ( T_21 * ) V_412 ;
if ( V_403 -> V_406 . V_413 == V_413 ) {
F_171 ( V_417 , V_412 ,
V_425 ) ;
F_165 ( V_403 ) ;
F_167 ( & V_417 -> V_409 ) ;
break;
}
}
V_412 = F_172 ( V_417 , & V_415 ) ;
}
F_173 ( & V_415 ) ;
F_174 ( & V_417 -> V_409 ) ;
return 0 ;
}
STATIC int
F_175 (
struct V_1 * log ,
struct V_131 * V_157 ,
T_11 * V_132 )
{
struct V_184 * V_24 = log -> V_7 ;
struct V_426 * V_427 ;
T_26 V_428 ;
T_27 V_429 ;
unsigned int V_430 ;
unsigned int V_350 ;
T_27 V_431 ;
V_427 = (struct V_426 * ) V_132 -> V_143 [ 0 ] . V_145 ;
if ( V_427 -> V_432 != V_161 ) {
F_3 ( log -> V_7 , L_69 ) ;
return - V_102 ;
}
if ( V_427 -> V_433 != 1 ) {
F_3 ( log -> V_7 , L_70 ) ;
return - V_102 ;
}
V_428 = F_31 ( V_427 -> V_434 ) ;
if ( V_428 >= V_24 -> V_26 . V_435 ) {
F_3 ( log -> V_7 , L_71 ) ;
return - V_102 ;
}
V_429 = F_31 ( V_427 -> V_436 ) ;
if ( ! V_429 || V_429 == V_437 || V_429 >= V_24 -> V_26 . V_438 ) {
F_3 ( log -> V_7 , L_72 ) ;
return - V_102 ;
}
V_350 = F_31 ( V_427 -> V_439 ) ;
if ( V_350 != V_24 -> V_26 . V_198 ) {
F_3 ( log -> V_7 , L_73 ) ;
return - V_102 ;
}
V_430 = F_31 ( V_427 -> V_440 ) ;
if ( ! V_430 ) {
F_3 ( log -> V_7 , L_74 ) ;
return - V_102 ;
}
V_431 = F_31 ( V_427 -> V_441 ) ;
if ( ! V_431 || V_431 >= V_24 -> V_26 . V_438 ) {
F_3 ( log -> V_7 , L_75 ) ;
return - V_102 ;
}
ASSERT ( V_430 == V_24 -> V_442 ) ;
ASSERT ( V_431 == V_24 -> V_443 ) ;
if ( V_430 != V_24 -> V_442 ||
V_431 != V_24 -> V_443 ) {
F_3 ( log -> V_7 , L_76 ) ;
return - V_102 ;
}
if ( F_105 ( log ,
F_176 ( V_24 , V_428 , V_429 ) , V_431 , 0 ) )
return 0 ;
F_177 ( V_24 , NULL , V_157 , V_428 , V_429 , V_431 ,
F_31 ( V_427 -> V_444 ) ) ;
return 0 ;
}
STATIC void
F_178 (
struct V_134 * V_124 )
{
T_11 * V_132 , * V_154 ;
int V_46 ;
F_90 (item, n, &trans->r_itemq, ri_list) {
F_106 ( & V_132 -> V_133 ) ;
for ( V_46 = 0 ; V_46 < V_132 -> V_144 ; V_46 ++ )
F_85 ( V_132 -> V_143 [ V_46 ] . V_145 ) ;
F_85 ( V_132 -> V_143 ) ;
F_85 ( V_132 ) ;
}
F_85 ( V_124 ) ;
}
STATIC void
F_179 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_315 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_184 * V_24 = log -> V_7 ;
if ( F_104 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
return;
}
F_180 ( V_24 -> V_324 , V_160 -> V_175 ,
V_160 -> V_178 , NULL ) ;
}
STATIC void
F_181 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_330 V_445 ;
struct V_330 * V_446 ;
struct V_184 * V_24 = log -> V_7 ;
int error ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( struct V_330 ) ) {
V_446 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_446 = & V_445 ;
memset ( V_446 , 0 , sizeof( * V_446 ) ) ;
error = F_141 ( & V_132 -> V_143 [ 0 ] , V_446 ) ;
if ( error )
return;
}
if ( F_104 ( log , V_446 -> V_352 , V_446 -> V_353 , 0 ) )
return;
F_180 ( V_24 -> V_324 , V_446 -> V_352 ,
V_446 -> V_353 , & V_447 ) ;
}
STATIC void
F_182 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_184 * V_24 = log -> V_7 ;
struct V_389 * V_391 ;
struct V_448 * V_392 ;
T_6 type ;
if ( V_24 -> V_316 == 0 )
return;
V_391 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_391 == NULL )
return;
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( struct V_389 ) )
return;
type = V_391 -> V_393 & ( V_317 | V_318 | V_319 ) ;
ASSERT ( type ) ;
if ( log -> V_320 & type )
return;
V_392 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_392 ) ;
ASSERT ( V_392 -> V_395 == 1 ) ;
F_180 ( V_24 -> V_324 , V_392 -> V_396 ,
F_160 ( V_24 , V_392 -> V_395 ) , NULL ) ;
}
STATIC void
F_183 (
struct V_1 * log ,
struct V_171 * V_132 )
{
switch ( F_91 ( V_132 ) ) {
case V_162 :
F_179 ( log , V_132 ) ;
break;
case V_166 :
F_181 ( log , V_132 ) ;
break;
case V_167 :
F_182 ( log , V_132 ) ;
break;
case V_170 :
case V_169 :
case V_168 :
default:
break;
}
}
STATIC int
F_184 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_171 * V_132 )
{
F_185 ( log , V_124 , V_132 , V_449 ) ;
switch ( F_91 ( V_132 ) ) {
case V_162 :
return F_98 ( log , V_132 ) ;
case V_168 :
return F_157 ( log , V_132 ) ;
case V_166 :
case V_170 :
case V_169 :
case V_167 :
case V_161 :
return 0 ;
default:
F_3 ( log -> V_7 , L_77 ,
V_8 , F_91 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return - V_20 ;
}
}
STATIC int
F_186 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_171 * V_132 )
{
F_185 ( log , V_124 , V_132 , V_450 ) ;
switch ( F_91 ( V_132 ) ) {
case V_162 :
return F_126 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_166 :
return F_140 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_170 :
return F_162 ( log , V_132 , V_124 -> V_128 ) ;
case V_169 :
return F_169 ( log , V_132 ) ;
case V_167 :
return F_158 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_161 :
return F_175 ( log , V_157 , V_132 ) ;
case V_168 :
return 0 ;
default:
F_3 ( log -> V_7 , L_77 ,
V_8 , F_91 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return - V_20 ;
}
}
STATIC int
F_187 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_131 * V_451 )
{
struct V_171 * V_132 ;
int error = 0 ;
F_101 (item, item_list, ri_list) {
error = F_186 ( log , V_124 ,
V_157 , V_132 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_188 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
int error = 0 ;
int V_23 ;
int V_452 = 0 ;
struct V_171 * V_132 ;
struct V_171 * V_312 ;
F_88 ( V_157 ) ;
F_88 ( V_453 ) ;
F_88 ( V_454 ) ;
#define F_189 100
F_190 ( & V_124 -> V_130 ) ;
error = F_87 ( log , V_124 , V_153 ) ;
if ( error )
return error ;
F_90 (item, next, &trans->r_itemq, ri_list) {
switch ( V_153 ) {
case V_449 :
error = F_184 ( log , V_124 , V_132 ) ;
break;
case V_450 :
F_183 ( log , V_132 ) ;
F_92 ( & V_132 -> V_133 , & V_453 ) ;
V_452 ++ ;
if ( V_452 >= F_189 ) {
error = F_187 ( log , V_124 ,
& V_157 , & V_453 ) ;
F_191 ( & V_453 , & V_454 ) ;
V_452 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_52;
}
V_52:
if ( ! F_79 ( & V_453 ) ) {
if ( ! error )
error = F_187 ( log , V_124 ,
& V_157 , & V_453 ) ;
F_191 ( & V_453 , & V_454 ) ;
}
if ( ! F_79 ( & V_454 ) )
F_89 ( & V_454 , & V_124 -> V_129 ) ;
F_178 ( V_124 ) ;
V_23 = F_192 ( & V_157 ) ;
return error ? error : V_23 ;
}
STATIC int
F_193 (
struct V_1 * log )
{
F_3 ( log -> V_7 , L_78 , V_8 ) ;
return 0 ;
}
STATIC int
F_194 (
struct V_1 * log ,
struct V_122 V_455 [] ,
struct V_456 * V_73 ,
T_2 V_135 ,
int V_153 )
{
T_2 V_457 ;
int V_458 ;
T_7 * V_459 ;
T_9 * V_124 ;
T_10 V_123 ;
int error ;
unsigned long V_460 ;
T_6 V_182 ;
V_457 = V_135 + F_31 ( V_73 -> V_61 ) ;
V_458 = F_31 ( V_73 -> V_95 ) ;
if ( F_32 ( log -> V_7 , V_73 ) )
return - V_20 ;
while ( ( V_135 < V_457 ) && V_458 ) {
ASSERT ( V_135 + sizeof( T_7 ) <= V_457 ) ;
V_459 = ( T_7 * ) V_135 ;
V_135 += sizeof( T_7 ) ;
if ( V_459 -> V_461 != V_462 &&
V_459 -> V_461 != V_463 ) {
F_3 ( log -> V_7 , L_79 ,
V_8 , V_459 -> V_461 ) ;
ASSERT ( 0 ) ;
return - V_20 ;
}
V_123 = F_31 ( V_459 -> V_464 ) ;
V_460 = F_195 ( V_123 ) ;
V_124 = F_69 ( & V_455 [ V_460 ] , V_123 ) ;
if ( V_124 == NULL ) {
if ( V_459 -> V_96 & V_465 )
F_71 ( & V_455 [ V_460 ] , V_123 ,
F_56 ( V_73 -> V_89 ) ) ;
} else {
if ( V_135 + F_31 ( V_459 -> V_466 ) > V_457 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 , F_31 ( V_459 -> V_466 ) ) ;
F_196 ( 1 ) ;
return - V_20 ;
}
V_182 = V_459 -> V_96 & ~ V_467 ;
if ( V_182 & V_468 )
V_182 &= ~ V_469 ;
switch ( V_182 ) {
case V_470 :
error = F_188 ( log ,
V_124 , V_153 ) ;
break;
case V_97 :
error = F_193 ( log ) ;
break;
case V_468 :
error = F_78 ( log ,
V_124 , V_135 ,
F_31 ( V_459 -> V_466 ) ) ;
break;
case V_465 :
F_3 ( log -> V_7 , L_81 ,
V_8 ) ;
ASSERT ( 0 ) ;
error = - V_20 ;
break;
case 0 :
case V_469 :
error = F_83 ( log , V_124 ,
V_135 , F_31 ( V_459 -> V_466 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_82 ,
V_8 , V_182 ) ;
ASSERT ( 0 ) ;
error = - V_20 ;
break;
}
if ( error ) {
F_178 ( V_124 ) ;
return error ;
}
}
V_135 += F_31 ( V_459 -> V_466 ) ;
V_458 -- ;
}
return 0 ;
}
STATIC int
F_197 (
T_4 * V_24 ,
T_21 * V_403 )
{
T_28 * V_471 ;
T_29 * V_472 ;
int V_46 ;
int error = 0 ;
T_30 * V_473 ;
T_31 V_474 ;
ASSERT ( ! F_198 ( V_475 , & V_403 -> V_476 ) ) ;
for ( V_46 = 0 ; V_46 < V_403 -> V_406 . V_405 ; V_46 ++ ) {
V_473 = & ( V_403 -> V_406 . V_477 [ V_46 ] ) ;
V_474 = F_199 ( V_24 ,
F_200 ( V_24 , V_473 -> V_478 ) ) ;
if ( ( V_474 == 0 ) ||
( V_473 -> V_479 == 0 ) ||
( V_474 >= V_24 -> V_26 . V_480 ) ||
( V_473 -> V_479 >= V_24 -> V_26 . V_438 ) ) {
F_201 ( V_475 , & V_403 -> V_476 ) ;
F_202 ( V_403 , V_403 -> V_406 . V_405 ) ;
return - V_20 ;
}
}
V_472 = F_203 ( V_24 , 0 ) ;
error = F_204 ( V_472 , & F_205 ( V_24 ) -> V_481 , 0 , 0 ) ;
if ( error )
goto V_482;
V_471 = F_206 ( V_472 , V_403 , V_403 -> V_406 . V_405 ) ;
for ( V_46 = 0 ; V_46 < V_403 -> V_406 . V_405 ; V_46 ++ ) {
V_473 = & ( V_403 -> V_406 . V_477 [ V_46 ] ) ;
error = F_207 ( V_472 , V_473 -> V_478 , V_473 -> V_479 ) ;
if ( error )
goto V_482;
F_208 ( V_472 , V_471 , V_473 -> V_478 ,
V_473 -> V_479 ) ;
}
F_201 ( V_475 , & V_403 -> V_476 ) ;
error = F_209 ( V_472 , 0 ) ;
return error ;
V_482:
F_210 ( V_472 , V_483 ) ;
return error ;
}
STATIC int
F_211 (
struct V_1 * log )
{
T_24 * V_412 ;
T_21 * V_403 ;
int error = 0 ;
struct V_414 V_415 ;
struct V_416 * V_417 ;
V_417 = log -> V_408 ;
F_167 ( & V_417 -> V_409 ) ;
V_412 = F_170 ( V_417 , & V_415 , 0 ) ;
while ( V_412 != NULL ) {
if ( V_412 -> V_424 != V_170 ) {
#ifdef F_212
for (; V_412 ; V_412 = F_172 ( V_417 , & V_415 ) )
ASSERT ( V_412 -> V_424 != V_170 ) ;
#endif
break;
}
V_403 = ( T_21 * ) V_412 ;
if ( F_198 ( V_475 , & V_403 -> V_476 ) ) {
V_412 = F_172 ( V_417 , & V_415 ) ;
continue;
}
F_174 ( & V_417 -> V_409 ) ;
error = F_197 ( log -> V_7 , V_403 ) ;
F_167 ( & V_417 -> V_409 ) ;
if ( error )
goto V_52;
V_412 = F_172 ( V_417 , & V_415 ) ;
}
V_52:
F_173 ( & V_415 ) ;
F_174 ( & V_417 -> V_409 ) ;
return error ;
}
STATIC void
F_213 (
T_4 * V_24 ,
T_26 V_428 ,
int V_172 )
{
T_29 * V_472 ;
T_32 * V_484 ;
T_1 * V_485 ;
int V_13 ;
int error ;
V_472 = F_203 ( V_24 , V_486 ) ;
error = F_204 ( V_472 , & F_205 ( V_24 ) -> V_487 , 0 , 0 ) ;
if ( error )
goto V_488;
error = F_214 ( V_24 , V_472 , V_428 , & V_485 ) ;
if ( error )
goto V_488;
V_484 = F_215 ( V_485 ) ;
V_484 -> V_489 [ V_172 ] = F_33 ( V_490 ) ;
V_13 = F_110 ( T_32 , V_489 ) +
( sizeof( T_15 ) * V_172 ) ;
F_216 ( V_472 , V_485 , V_13 ,
( V_13 + sizeof( T_15 ) - 1 ) ) ;
error = F_209 ( V_472 , 0 ) ;
if ( error )
goto V_491;
return;
V_488:
F_210 ( V_472 , V_483 ) ;
V_491:
F_3 ( V_24 , L_83 , V_8 , V_428 ) ;
return;
}
STATIC T_15
F_217 (
struct V_184 * V_24 ,
T_26 V_428 ,
T_15 V_492 ,
int V_172 )
{
struct V_5 * V_493 ;
struct V_205 * V_329 ;
struct V_331 * V_332 ;
T_33 V_494 ;
int error ;
V_494 = F_218 ( V_24 , V_428 , V_492 ) ;
error = F_219 ( V_24 , NULL , V_494 , 0 , 0 , & V_332 ) ;
if ( error )
goto V_495;
error = F_220 ( V_24 , NULL , & V_332 -> V_496 , & V_329 , & V_493 , 0 , 0 ) ;
if ( error )
goto V_497;
ASSERT ( V_332 -> V_337 . V_498 == 0 ) ;
ASSERT ( V_332 -> V_337 . V_361 != 0 ) ;
V_492 = F_31 ( V_329 -> V_200 ) ;
F_28 ( V_493 ) ;
V_332 -> V_337 . V_499 = 0 ;
F_221 ( V_332 ) ;
return V_492 ;
V_497:
F_221 ( V_332 ) ;
V_495:
F_213 ( V_24 , V_428 , V_172 ) ;
return V_490 ;
}
STATIC void
F_222 (
struct V_1 * log )
{
T_4 * V_24 ;
T_26 V_428 ;
T_32 * V_484 ;
T_1 * V_485 ;
T_15 V_492 ;
int V_172 ;
int error ;
T_6 V_500 ;
V_24 = log -> V_7 ;
V_500 = V_24 -> V_501 ;
V_24 -> V_501 = 0 ;
for ( V_428 = 0 ; V_428 < V_24 -> V_26 . V_435 ; V_428 ++ ) {
error = F_214 ( V_24 , NULL , V_428 , & V_485 ) ;
if ( error ) {
continue;
}
V_484 = F_215 ( V_485 ) ;
F_7 ( V_485 ) ;
for ( V_172 = 0 ; V_172 < V_502 ; V_172 ++ ) {
V_492 = F_31 ( V_484 -> V_489 [ V_172 ] ) ;
while ( V_492 != V_490 ) {
V_492 = F_217 ( V_24 ,
V_428 , V_492 , V_172 ) ;
}
}
F_223 ( V_485 ) ;
}
V_24 -> V_501 = V_500 ;
}
STATIC int
F_224 (
struct V_456 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
T_34 V_503 ;
V_503 = F_225 ( log , V_73 , V_135 , F_31 ( V_73 -> V_61 ) ) ;
if ( V_503 != V_73 -> V_504 ) {
if ( V_73 -> V_504 || F_109 ( & log -> V_7 -> V_26 ) ) {
F_113 ( log -> V_7 ,
L_84 ,
F_226 ( V_73 -> V_504 ) ,
F_226 ( V_503 ) ) ;
F_227 ( V_135 , 32 ) ;
}
if ( F_109 ( & log -> V_7 -> V_26 ) )
return - V_16 ;
}
return 0 ;
}
STATIC int
F_228 (
struct V_456 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
int V_46 , V_47 , V_505 ;
int error ;
error = F_224 ( V_73 , V_135 , log ) ;
if ( error )
return error ;
for ( V_46 = 0 ; V_46 < F_49 ( F_31 ( V_73 -> V_61 ) ) &&
V_46 < ( V_60 / V_53 ) ; V_46 ++ ) {
* ( V_81 * ) V_135 = * ( V_81 * ) & V_73 -> V_506 [ V_46 ] ;
V_135 += V_53 ;
}
if ( F_48 ( & log -> V_7 -> V_26 ) ) {
T_35 * V_507 = ( T_35 * ) V_73 ;
for ( ; V_46 < F_49 ( F_31 ( V_73 -> V_61 ) ) ; V_46 ++ ) {
V_47 = V_46 / ( V_60 / V_53 ) ;
V_505 = V_46 % ( V_60 / V_53 ) ;
* ( V_81 * ) V_135 = V_507 [ V_47 ] . V_508 . V_509 [ V_505 ] ;
V_135 += V_53 ;
}
}
return 0 ;
}
STATIC int
F_229 (
struct V_1 * log ,
struct V_456 * V_73 ,
T_3 V_181 )
{
int V_510 ;
if ( F_34 ( V_73 -> V_31 != F_33 ( V_32 ) ) ) {
F_4 ( L_85 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_34 (
( ! V_73 -> V_93 ||
( F_31 ( V_73 -> V_93 ) & ( ~ V_511 ) ) ) ) ) {
F_3 ( log -> V_7 , L_86 ,
V_8 , F_31 ( V_73 -> V_93 ) ) ;
return - V_20 ;
}
V_510 = F_31 ( V_73 -> V_61 ) ;
if ( F_34 ( V_510 <= 0 || V_510 > V_70 ) ) {
F_4 ( L_87 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
if ( F_34 ( V_181 > log -> V_3 || V_181 > V_70 ) ) {
F_4 ( L_88 ,
V_121 , log -> V_7 ) ;
return - V_16 ;
}
return 0 ;
}
STATIC int
F_230 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_153 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_512 , * V_513 ;
int error = 0 , V_59 ;
int V_514 , V_515 ;
int V_79 , V_516 , V_517 ;
struct V_122 V_455 [ V_518 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_48 ( & log -> V_7 -> V_26 ) ) {
V_512 = F_2 ( log , 1 ) ;
if ( ! V_512 )
return - V_50 ;
error = F_20 ( log , V_72 , 1 , V_512 , & V_13 ) ;
if ( error )
goto V_519;
V_73 = ( T_5 * ) V_13 ;
error = F_229 ( log , V_73 , V_72 ) ;
if ( error )
goto V_519;
V_59 = F_31 ( V_73 -> V_59 ) ;
if ( ( F_31 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_512 ) ;
V_512 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_512 = F_2 ( log , 1 ) ;
V_59 = V_520 ;
}
if ( ! V_512 )
return - V_50 ;
V_513 = F_2 ( log , F_49 ( V_59 ) ) ;
if ( ! V_513 ) {
F_8 ( V_512 ) ;
return - V_50 ;
}
memset ( V_455 , 0 , sizeof( V_455 ) ) ;
if ( V_72 <= V_63 ) {
for ( V_12 = V_72 ; V_12 < V_63 ; ) {
error = F_20 ( log , V_12 , V_79 , V_512 , & V_13 ) ;
if ( error )
goto V_521;
V_73 = ( T_5 * ) V_13 ;
error = F_229 ( log , V_73 , V_12 ) ;
if ( error )
goto V_521;
V_514 = ( int ) F_49 ( F_31 ( V_73 -> V_61 ) ) ;
error = F_20 ( log , V_12 + V_79 , V_514 , V_513 ,
& V_13 ) ;
if ( error )
goto V_521;
error = F_228 ( V_73 , V_13 , log ) ;
if ( error )
goto V_521;
error = F_194 ( log ,
V_455 , V_73 , V_13 , V_153 ) ;
if ( error )
goto V_521;
V_12 += V_514 + V_79 ;
}
} else {
V_12 = V_72 ;
while ( V_12 < log -> V_3 ) {
V_13 = V_512 -> V_15 ;
V_516 = 0 ;
V_517 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_20 ( log , V_12 , V_79 , V_512 ,
& V_13 ) ;
if ( error )
goto V_521;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_516 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_516 > 0 ) ;
error = F_20 ( log , V_12 ,
V_516 , V_512 ,
& V_13 ) ;
if ( error )
goto V_521;
}
V_517 = V_79 - V_516 ;
error = F_21 ( log , 0 ,
V_517 , V_512 ,
V_13 + F_11 ( V_516 ) ) ;
if ( error )
goto V_521;
}
V_73 = ( T_5 * ) V_13 ;
error = F_229 ( log , V_73 ,
V_516 ? V_12 : 0 ) ;
if ( error )
goto V_521;
V_514 = ( int ) F_49 ( F_31 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_514 <= log -> V_3 ) {
error = F_20 ( log , V_12 , V_514 , V_513 ,
& V_13 ) ;
if ( error )
goto V_521;
} else {
V_13 = V_513 -> V_15 ;
V_515 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_517 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_515 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_515 > 0 ) ;
error = F_20 ( log , V_12 ,
V_515 , V_513 ,
& V_13 ) ;
if ( error )
goto V_521;
}
error = F_21 ( log , 0 ,
V_514 - V_515 , V_513 ,
V_13 + F_11 ( V_515 ) ) ;
if ( error )
goto V_521;
}
error = F_228 ( V_73 , V_13 , log ) ;
if ( error )
goto V_521;
error = F_194 ( log , V_455 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_521;
V_12 += V_514 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
while ( V_12 < V_63 ) {
error = F_20 ( log , V_12 , V_79 , V_512 , & V_13 ) ;
if ( error )
goto V_521;
V_73 = ( T_5 * ) V_13 ;
error = F_229 ( log , V_73 , V_12 ) ;
if ( error )
goto V_521;
V_514 = ( int ) F_49 ( F_31 ( V_73 -> V_61 ) ) ;
error = F_20 ( log , V_12 + V_79 , V_514 , V_513 ,
& V_13 ) ;
if ( error )
goto V_521;
error = F_228 ( V_73 , V_13 , log ) ;
if ( error )
goto V_521;
error = F_194 ( log , V_455 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_521;
V_12 += V_514 + V_79 ;
}
}
V_521:
F_8 ( V_513 ) ;
V_519:
F_8 ( V_512 ) ;
return error ;
}
STATIC int
F_231 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_46 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_183 = F_72 ( V_522 *
sizeof( struct V_131 ) ,
V_127 ) ;
for ( V_46 = 0 ; V_46 < V_522 ; V_46 ++ )
F_73 ( & log -> V_183 [ V_46 ] ) ;
error = F_230 ( log , V_63 , V_72 ,
V_449 ) ;
if ( error != 0 ) {
F_85 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
error = F_230 ( log , V_63 , V_72 ,
V_450 ) ;
#ifdef F_212
if ( ! error ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_522 ; V_46 ++ )
ASSERT ( F_79 ( & log -> V_183 [ V_46 ] ) ) ;
}
#endif
F_85 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
STATIC int
F_232 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_36 * V_523 ;
error = F_231 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_16 ( log -> V_7 ) ) {
return - V_20 ;
}
F_233 ( log -> V_7 ) ;
V_6 = F_234 ( log -> V_7 , 0 ) ;
F_235 ( V_6 ) ;
ASSERT ( ! ( F_236 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_237 ( V_6 ) ;
V_6 -> V_195 = & V_308 ;
if ( F_16 ( log -> V_7 ) ) {
F_28 ( V_6 ) ;
return - V_20 ;
}
F_17 ( V_6 ) ;
error = F_18 ( V_6 ) ;
if ( error ) {
F_19 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
F_28 ( V_6 ) ;
return error ;
}
V_523 = & log -> V_7 -> V_26 ;
F_238 ( V_523 , F_239 ( V_6 ) ) ;
ASSERT ( V_523 -> V_524 == V_251 ) ;
ASSERT ( F_240 ( V_523 ) ) ;
F_28 ( V_6 ) ;
F_241 ( log -> V_7 ) ;
F_242 ( log ) ;
log -> V_525 &= ~ V_526 ;
return 0 ;
}
int
V_134 (
struct V_1 * log )
{
T_3 V_63 , V_72 ;
int error ;
if ( ( error = F_54 ( log , & V_63 , & V_72 ) ) )
return error ;
if ( V_72 != V_63 ) {
if ( ( error = F_243 ( log -> V_7 , L_89 ) ) ) {
return error ;
}
if ( F_244 ( & log -> V_7 -> V_26 ) == V_527 &&
F_245 ( & log -> V_7 -> V_26 ,
V_528 ) ) {
F_3 ( log -> V_7 ,
L_90
L_91
L_92 ,
( log -> V_7 -> V_26 . V_529 &
V_528 ) ) ;
return - V_102 ;
}
F_246 ( log -> V_7 , L_93 ,
log -> V_7 -> V_530 ? log -> V_7 -> V_530
: L_94 ) ;
error = F_232 ( log , V_63 , V_72 ) ;
log -> V_525 |= V_531 ;
}
return error ;
}
int
F_247 (
struct V_1 * log )
{
if ( log -> V_525 & V_531 ) {
int error ;
error = F_211 ( log ) ;
if ( error ) {
F_113 ( log -> V_7 , L_95 ) ;
return error ;
}
F_248 ( log -> V_7 , V_532 ) ;
F_222 ( log ) ;
F_242 ( log ) ;
F_246 ( log -> V_7 , L_96 ,
log -> V_7 -> V_530 ? log -> V_7 -> V_530
: L_94 ) ;
log -> V_525 &= ~ V_531 ;
} else {
F_249 ( log -> V_7 , L_97 ) ;
}
return 0 ;
}
void
F_242 (
struct V_1 * log )
{
T_4 * V_24 ;
T_37 * V_533 ;
T_1 * V_534 ;
T_1 * V_485 ;
T_26 V_428 ;
T_25 V_535 ;
T_25 V_536 ;
T_25 V_537 ;
int error ;
V_24 = log -> V_7 ;
V_535 = 0LL ;
V_536 = 0LL ;
V_537 = 0LL ;
for ( V_428 = 0 ; V_428 < V_24 -> V_26 . V_435 ; V_428 ++ ) {
error = F_250 ( V_24 , NULL , V_428 , 0 , & V_534 ) ;
if ( error ) {
F_113 ( V_24 , L_98 ,
V_8 , V_428 , error ) ;
} else {
V_533 = F_251 ( V_534 ) ;
V_535 += F_31 ( V_533 -> V_538 ) +
F_31 ( V_533 -> V_539 ) ;
F_28 ( V_534 ) ;
}
error = F_214 ( V_24 , NULL , V_428 , & V_485 ) ;
if ( error ) {
F_113 ( V_24 , L_99 ,
V_8 , V_428 , error ) ;
} else {
struct V_236 * V_484 = F_215 ( V_485 ) ;
V_536 += F_31 ( V_484 -> V_540 ) ;
V_537 += F_31 ( V_484 -> V_541 ) ;
F_28 ( V_485 ) ;
}
}
}
