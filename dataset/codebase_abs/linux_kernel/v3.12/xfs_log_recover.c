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
return V_16 ;
}
V_12 = F_13 ( V_12 , log -> V_10 ) ;
V_4 = F_5 ( V_4 , log -> V_10 ) ;
ASSERT ( V_4 > 0 ) ;
ASSERT ( V_4 <= V_6 -> V_14 ) ;
F_14 ( V_6 , log -> V_17 + V_12 ) ;
F_15 ( V_6 ) ;
V_6 -> V_18 = V_4 ;
V_6 -> V_19 = 0 ;
F_16 ( log -> V_7 , V_6 ) ;
error = F_17 ( V_6 ) ;
if ( error )
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
return V_16 ;
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
return F_34 ( V_16 ) ;
} else if ( F_33 ( ! F_35 ( & V_23 -> V_25 . V_26 , & V_24 -> V_28 ) ) ) {
F_3 ( V_23 ,
L_6 ) ;
F_28 ( V_23 , V_24 ) ;
F_4 ( L_7 ,
V_9 , V_23 ) ;
return F_34 ( V_16 ) ;
}
return 0 ;
}
STATIC int
F_36 (
T_4 * V_23 ,
T_5 * V_24 )
{
ASSERT ( V_24 -> V_30 == F_32 ( V_31 ) ) ;
if ( F_37 ( & V_24 -> V_28 ) ) {
F_3 ( V_23 , L_8 ) ;
} else if ( F_33 ( ! F_35 ( & V_23 -> V_25 . V_26 , & V_24 -> V_28 ) ) ) {
F_3 ( V_23 , L_9 ) ;
F_28 ( V_23 , V_24 ) ;
F_4 ( L_10 ,
V_9 , V_23 ) ;
return F_34 ( V_16 ) ;
}
return 0 ;
}
STATIC void
F_38 (
struct V_5 * V_6 )
{
if ( V_6 -> V_19 ) {
F_18 ( V_6 , V_8 ) ;
F_39 ( V_6 -> V_32 -> V_33 ,
V_34 ) ;
}
V_6 -> V_35 = NULL ;
F_40 ( V_6 , 0 ) ;
}
STATIC int
F_41 (
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
V_39 = F_42 ( V_36 , V_40 ) ;
while ( V_39 != V_36 && V_39 != V_40 ) {
error = F_19 ( log , V_39 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_41 = F_43 ( V_13 ) ;
if ( V_41 == V_38 )
V_40 = V_39 ;
else
V_36 = V_39 ;
V_39 = F_42 ( V_36 , V_40 ) ;
}
ASSERT ( ( V_39 == V_36 && V_39 + 1 == V_40 ) ||
( V_39 == V_40 && V_39 - 1 == V_36 ) ) ;
* V_37 = V_40 ;
return 0 ;
}
STATIC int
F_44 (
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
V_47 = 1 << F_45 ( V_4 ) ;
while ( V_47 > log -> V_3 )
V_47 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_47 ) ) ) {
V_47 >>= 1 ;
if ( V_47 < log -> V_10 )
return V_49 ;
}
for ( V_45 = V_42 ; V_45 < V_42 + V_4 ; V_45 += V_47 ) {
int V_50 ;
V_50 = F_46 ( V_47 , ( V_42 + V_4 - V_45 ) ) ;
error = F_19 ( log , V_45 , V_50 , V_6 , & V_48 ) ;
if ( error )
goto V_51;
for ( V_46 = 0 ; V_46 < V_50 ; V_46 ++ ) {
V_38 = F_43 ( V_48 ) ;
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
F_47 (
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
return V_49 ;
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
error = F_34 ( V_58 ) ;
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
error = - 1 ;
goto V_51;
}
if ( ( error = F_36 ( log -> V_7 , V_24 ) ) )
goto V_51;
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
T_6 V_59 = F_30 ( V_24 -> V_59 ) ;
V_56 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_56 ++ ;
} else {
V_56 = 1 ;
}
if ( * V_37 - V_45 + V_53 !=
F_49 ( F_30 ( V_24 -> V_61 ) ) + V_56 )
* V_37 = V_45 ;
V_51:
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
T_3 V_44 , V_36 , V_42 , V_37 , V_63 ;
int V_64 ;
T_6 V_65 , V_66 ;
T_6 V_67 ;
int error , V_68 = log -> V_3 ;
if ( ( error = F_51 ( log , & V_36 ) ) == - 1 ) {
* V_62 = V_36 ;
if ( ! V_36 ) {
F_3 ( log -> V_7 , L_12 ) ;
}
return 0 ;
} else if ( error ) {
F_3 ( log -> V_7 , L_13 ) ;
return error ;
}
V_36 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return V_49 ;
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_65 = F_43 ( V_13 ) ;
V_37 = V_63 = V_68 - 1 ;
error = F_19 ( log , V_37 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_66 = F_43 ( V_13 ) ;
ASSERT ( V_66 != 0 ) ;
if ( V_65 == V_66 ) {
V_63 = V_68 ;
V_67 = V_66 - 1 ;
} else {
V_67 = V_66 ;
if ( ( error = F_41 ( log , V_6 , V_36 ,
& V_63 , V_66 ) ) )
goto V_69;
}
V_64 = F_52 ( log ) ;
if ( V_63 >= V_64 ) {
V_42 = V_63 - V_64 ;
if ( ( error = F_44 ( log ,
V_42 , V_64 ,
V_67 , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 )
V_63 = V_44 ;
} else {
ASSERT ( V_63 <= V_70 &&
( T_3 ) V_64 >= V_63 ) ;
V_42 = V_68 - ( V_64 - V_63 ) ;
if ( ( error = F_44 ( log , V_42 ,
V_64 - ( int ) V_63 ,
( V_67 - 1 ) , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 ) {
V_63 = V_44 ;
goto V_71;
}
V_42 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_44 ( log ,
V_42 , ( int ) V_63 ,
V_67 , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 )
V_63 = V_44 ;
}
V_71:
V_64 = F_53 ( log ) ;
if ( V_63 >= V_64 ) {
V_42 = V_63 - V_64 ;
if ( ( error = F_47 ( log , V_42 ,
& V_63 , 0 ) ) == - 1 ) {
error = F_34 ( V_58 ) ;
goto V_69;
} else if ( error )
goto V_69;
} else {
V_42 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_47 ( log , V_42 ,
& V_63 , 0 ) ) == - 1 ) {
V_42 = V_68 - ( V_64 - V_63 ) ;
V_44 = V_68 ;
ASSERT ( V_42 <= V_70 &&
( T_3 ) V_68 - V_42 >= 0 ) ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_47 ( log ,
V_42 , & V_44 ,
( int ) V_63 ) ) == - 1 ) {
error = F_34 ( V_58 ) ;
goto V_69;
} else if ( error )
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
F_54 (
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
if ( ( error = F_50 ( log , V_63 ) ) )
return error ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return V_49 ;
if ( * V_63 == 0 ) {
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( F_43 ( V_13 ) == 0 ) {
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
return F_34 ( V_58 ) ;
}
V_73 = ( T_5 * ) V_13 ;
* V_72 = F_55 ( F_56 ( V_73 -> V_82 ) ) ;
log -> V_83 = V_45 ;
log -> V_84 = ( int ) * V_63 ;
log -> V_85 = F_30 ( V_73 -> V_86 ) ;
if ( V_75 == 2 )
log -> V_85 ++ ;
F_57 ( & log -> V_87 , F_56 ( V_73 -> V_82 ) ) ;
F_57 ( & log -> V_88 , F_56 ( V_73 -> V_89 ) ) ;
F_58 ( & log -> V_90 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
F_58 ( & log -> V_92 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
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
F_49 ( F_30 ( V_73 -> V_61 ) ) ) % log -> V_3 ;
V_78 = F_59 ( & log -> V_87 ) ;
if ( * V_63 == V_77 &&
F_30 ( V_73 -> V_95 ) == 1 ) {
V_76 = ( V_45 + V_79 ) % log -> V_3 ;
error = F_19 ( log , V_76 , 1 , V_6 , & V_13 ) ;
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
T_3 V_44 , V_37 , V_42 ;
T_3 V_64 ;
int error , V_68 = log -> V_3 ;
* V_12 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return V_49 ;
error = F_19 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_100 = F_43 ( V_13 ) ;
if ( V_100 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return - 1 ;
}
error = F_19 ( log , V_68 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_101 = F_43 ( V_13 ) ;
if ( V_101 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_100 != 1 ) {
F_3 ( log -> V_7 ,
L_17 ) ;
error = F_34 ( V_102 ) ;
goto V_69;
}
V_37 = V_68 - 1 ;
if ( ( error = F_41 ( log , V_6 , 0 , & V_37 , 0 ) ) )
goto V_69;
V_64 = F_52 ( log ) ;
ASSERT ( V_64 <= V_70 ) ;
if ( V_37 < V_64 )
V_64 = V_37 ;
V_42 = V_37 - V_64 ;
if ( ( error = F_44 ( log , V_42 ,
( int ) V_64 , 0 , & V_44 ) ) )
goto V_69;
if ( V_44 != - 1 )
V_37 = V_44 ;
if ( ( error = F_47 ( log , V_42 ,
& V_37 , 0 ) ) == - 1 ) {
error = F_34 ( V_58 ) ;
goto V_69;
} else if ( error )
goto V_69;
* V_12 = V_37 ;
V_69:
F_8 ( V_6 ) ;
if ( error )
return error ;
return - 1 ;
}
STATIC void
F_63 (
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
F_48 ( & log -> V_7 -> V_25 ) ? 2 : 1 ) ;
V_106 -> V_89 = F_64 ( F_65 ( V_38 , V_103 ) ) ;
V_106 -> V_82 = F_64 ( F_65 ( V_104 , V_105 ) ) ;
V_106 -> V_29 = F_32 ( V_27 ) ;
memcpy ( & V_106 -> V_28 , & log -> V_7 -> V_25 . V_26 , sizeof( V_107 ) ) ;
}
STATIC int
F_66 (
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
V_47 = 1 << F_45 ( V_109 ) ;
while ( V_47 > log -> V_3 )
V_47 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_47 ) ) ) {
V_47 >>= 1 ;
if ( V_47 < V_112 )
return V_49 ;
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
V_50 = F_46 ( V_47 , V_113 - V_108 ) ;
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
F_63 ( log , V_13 , V_38 , V_45 + V_46 ,
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
if ( F_33 ( V_117 < V_105 || V_117 >= log -> V_3 ) ) {
F_4 ( L_18 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
V_118 = V_105 + ( log -> V_3 - V_117 ) ;
} else {
if ( F_33 ( V_117 >= V_105 || V_116 != ( V_104 + 1 ) ) ) {
F_4 ( L_19 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
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
struct V_122 * V_24 ,
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
struct V_122 * V_24 ,
T_10 V_123 ,
T_8 V_126 )
{
T_9 * V_124 ;
V_124 = F_72 ( sizeof( T_9 ) , V_127 ) ;
V_124 -> V_125 = V_123 ;
V_124 -> V_128 = V_126 ;
F_73 ( & V_124 -> V_129 ) ;
F_74 ( & V_124 -> V_130 ) ;
F_75 ( & V_124 -> V_130 , V_24 ) ;
}
STATIC void
F_76 (
struct V_131 * V_24 )
{
T_11 * V_132 ;
V_132 = F_72 ( sizeof( T_11 ) , V_127 ) ;
F_73 ( & V_132 -> V_133 ) ;
F_77 ( & V_132 -> V_133 , V_24 ) ;
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
return F_34 ( V_58 ) ;
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
return F_34 ( V_58 ) ;
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
return F_34 ( V_58 ) ;
}
}
ASSERT ( F_79 ( & V_155 ) ) ;
if ( ! F_79 ( & V_157 ) )
F_96 ( & V_157 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_159 ) )
F_97 ( & V_159 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_158 ) )
F_97 ( & V_158 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_156 ) )
F_97 ( & V_156 , & V_124 -> V_129 ) ;
return 0 ;
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
struct V_184 * V_23 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_45 ;
int V_185 = 0 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_189 = 0 ;
int V_190 ;
int V_191 ;
T_15 * V_192 ;
T_15 * V_193 ;
F_108 ( V_23 -> V_194 , V_160 ) ;
if ( F_109 ( & V_23 -> V_25 ) )
V_6 -> V_195 = & V_196 ;
V_191 = F_11 ( V_6 -> V_18 ) >> V_23 -> V_25 . V_197 ;
for ( V_45 = 0 ; V_45 < V_191 ; V_45 ++ ) {
V_190 = ( V_45 * V_23 -> V_25 . V_198 ) +
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
if ( F_33 ( * V_192 == 0 ) ) {
F_113 ( V_23 ,
L_23
L_24 ,
V_132 , V_6 ) ;
F_4 ( L_25 ,
V_121 , V_23 ) ;
return F_34 ( V_16 ) ;
}
V_193 = ( T_15 * ) F_114 ( V_6 ,
V_190 ) ;
* V_193 = * V_192 ;
F_115 ( V_23 , (struct V_205 * )
F_114 ( V_6 , V_45 * V_23 -> V_25 . V_198 ) ) ;
}
return 0 ;
}
static T_8
F_116 (
struct V_184 * V_23 ,
struct V_5 * V_6 )
{
T_16 V_206 ;
T_17 V_207 ;
T_17 V_208 ;
void * V_209 = V_6 -> V_15 ;
V_107 * V_210 ;
T_8 V_126 = - 1 ;
if ( ! F_109 ( & V_23 -> V_25 ) )
goto V_211;
V_206 = F_30 ( * ( V_81 * ) V_209 ) ;
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
V_210 = & ( (struct V_252 * ) V_209 ) -> V_26 ;
break;
default:
break;
}
if ( V_126 != ( T_8 ) - 1 ) {
if ( ! F_35 ( & V_23 -> V_25 . V_26 , V_210 ) )
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
if ( ! F_35 ( & V_23 -> V_25 . V_26 , V_210 ) )
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
struct V_184 * V_23 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
struct V_254 * V_263 = V_6 -> V_15 ;
T_16 V_206 ;
T_17 V_207 ;
T_17 V_208 ;
V_206 = F_30 ( * ( V_81 * ) V_6 -> V_15 ) ;
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
case V_217 :
V_6 -> V_195 = & V_266 ;
break;
case V_224 :
case V_225 :
V_6 -> V_195 = & V_267 ;
break;
default:
F_3 ( V_23 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_268 :
if ( V_206 != V_227 ) {
F_3 ( V_23 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_269 ;
break;
case V_270 :
if ( ! F_109 ( & V_23 -> V_25 ) )
break;
if ( V_206 != V_231 ) {
F_3 ( V_23 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_271 ;
break;
case V_272 :
if ( V_206 != V_235 ) {
F_3 ( V_23 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_273 ;
break;
case V_274 :
case V_275 :
case V_276 :
#ifdef F_120
if ( V_207 != V_261 ) {
F_3 ( V_23 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_277 ;
#else
F_113 ( V_23 ,
L_31 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_278 :
if ( V_207 != V_262 ) {
F_3 ( V_23 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_196 ;
break;
case V_279 :
if ( V_206 != V_239 ) {
F_3 ( V_23 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_280 ;
break;
case V_281 :
if ( V_206 != V_282 &&
V_206 != V_243 ) {
F_3 ( V_23 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_283 ;
break;
case V_284 :
if ( V_206 != V_285 &&
V_206 != V_244 ) {
F_3 ( V_23 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_286 ;
break;
case V_287 :
if ( V_206 != V_288 &&
V_206 != V_245 ) {
F_3 ( V_23 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_289 ;
break;
case V_290 :
if ( V_208 != V_291 &&
V_208 != V_256 ) {
F_3 ( V_23 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_292 ;
break;
case V_293 :
if ( V_208 != V_294 &&
V_208 != V_257 ) {
F_3 ( V_23 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_295 ;
break;
case V_296 :
if ( V_208 != V_297 &&
V_208 != V_258 ) {
F_3 ( V_23 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_298 ;
break;
case V_299 :
if ( V_208 != V_300 &&
V_208 != V_301 ) {
F_3 ( V_23 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_302 ;
break;
case V_303 :
if ( ! F_109 ( & V_23 -> V_25 ) )
break;
if ( V_206 != V_247 ) {
F_3 ( V_23 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_304 ;
break;
case V_305 :
if ( V_206 != V_251 ) {
F_3 ( V_23 , L_42 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_306 ;
break;
default:
F_3 ( V_23 , L_43 ,
F_119 ( V_160 ) ) ;
break;
}
}
STATIC void
F_121 (
struct V_184 * V_23 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_45 ;
int V_186 ;
int V_187 ;
int error ;
F_122 ( V_23 -> V_194 , V_160 ) ;
V_186 = 0 ;
V_45 = 1 ;
while ( 1 ) {
V_186 = F_111 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
break;
V_187 = F_112 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
ASSERT ( V_187 > 0 ) ;
ASSERT ( V_132 -> V_143 [ V_45 ] . V_145 != NULL ) ;
ASSERT ( V_132 -> V_143 [ V_45 ] . V_146 % V_204 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_18 ) >=
( ( T_6 ) V_186 << V_203 ) + ( V_187 << V_203 ) ) ;
if ( V_132 -> V_143 [ V_45 ] . V_146 < ( V_187 << V_203 ) )
V_187 = V_132 -> V_143 [ V_45 ] . V_146 >> V_203 ;
error = 0 ;
if ( V_160 -> V_163 &
( V_307 | V_308 | V_309 ) ) {
if ( V_132 -> V_143 [ V_45 ] . V_145 == NULL ) {
F_113 ( V_23 ,
L_44 , V_8 ) ;
goto V_310;
}
if ( V_132 -> V_143 [ V_45 ] . V_146 < sizeof( V_311 ) ) {
F_113 ( V_23 ,
L_45 ,
V_132 -> V_143 [ V_45 ] . V_146 , V_8 ) ;
goto V_310;
}
error = F_123 ( V_23 , V_132 -> V_143 [ V_45 ] . V_145 ,
- 1 , 0 , V_312 ,
L_46 ) ;
if ( error )
goto V_310;
}
memcpy ( F_114 ( V_6 ,
( T_6 ) V_186 << V_203 ) ,
V_132 -> V_143 [ V_45 ] . V_145 ,
V_187 << V_203 ) ;
V_310:
V_45 ++ ;
V_186 += V_187 ;
}
ASSERT ( V_45 == V_132 -> V_149 ) ;
if ( F_109 ( & V_23 -> V_25 ) )
F_118 ( V_23 , V_6 , V_160 ) ;
}
int
F_123 (
struct V_184 * V_23 ,
V_311 * V_313 ,
T_18 V_314 ,
T_6 type ,
T_6 V_182 ,
char * V_315 )
{
T_19 * V_316 = ( T_19 * ) V_313 ;
int V_317 = 0 ;
if ( V_313 -> V_318 != F_124 ( V_261 ) ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_47 ,
V_315 , V_314 , F_117 ( V_313 -> V_318 ) , V_261 ) ;
V_317 ++ ;
}
if ( V_313 -> V_319 != V_320 ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_48 ,
V_315 , V_314 , V_313 -> V_319 , V_320 ) ;
V_317 ++ ;
}
if ( V_313 -> V_321 != V_322 &&
V_313 -> V_321 != V_323 &&
V_313 -> V_321 != V_324 ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_49 ,
V_315 , V_314 , V_313 -> V_321 ) ;
V_317 ++ ;
}
if ( V_314 != - 1 && V_314 != F_30 ( V_313 -> V_325 ) ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_50
L_51 ,
V_315 , V_313 , V_314 , F_30 ( V_313 -> V_325 ) ) ;
V_317 ++ ;
}
if ( ! V_317 && V_313 -> V_325 ) {
if ( V_313 -> V_326 &&
F_56 ( V_313 -> V_327 ) >
F_56 ( V_313 -> V_326 ) ) {
if ( ! V_313 -> V_328 ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_52 ,
V_315 , ( int ) F_30 ( V_313 -> V_325 ) , V_313 ) ;
V_317 ++ ;
}
}
if ( V_313 -> V_329 &&
F_56 ( V_313 -> V_330 ) >
F_56 ( V_313 -> V_329 ) ) {
if ( ! V_313 -> V_331 ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_53 ,
V_315 , ( int ) F_30 ( V_313 -> V_325 ) , V_313 ) ;
V_317 ++ ;
}
}
if ( V_313 -> V_332 &&
F_56 ( V_313 -> V_333 ) >
F_56 ( V_313 -> V_332 ) ) {
if ( ! V_313 -> V_334 ) {
if ( V_182 & V_312 )
F_113 ( V_23 ,
L_54 ,
V_315 , ( int ) F_30 ( V_313 -> V_325 ) , V_313 ) ;
V_317 ++ ;
}
}
}
if ( ! V_317 || ! ( V_182 & V_335 ) )
return V_317 ;
if ( V_182 & V_312 )
F_125 ( V_23 , L_55 , V_314 ) ;
ASSERT ( V_314 != - 1 ) ;
ASSERT ( V_182 & V_335 ) ;
memset ( V_316 , 0 , sizeof( T_19 ) ) ;
V_316 -> V_336 . V_318 = F_124 ( V_261 ) ;
V_316 -> V_336 . V_319 = V_320 ;
V_316 -> V_336 . V_321 = type ;
V_316 -> V_336 . V_325 = F_32 ( V_314 ) ;
if ( F_109 ( & V_23 -> V_25 ) ) {
F_126 ( & V_316 -> V_337 , & V_23 -> V_25 . V_26 ) ;
F_127 ( ( char * ) V_316 , sizeof( struct V_338 ) ,
V_339 ) ;
}
return V_317 ;
}
STATIC void
F_128 (
struct V_184 * V_23 ,
struct V_1 * log ,
struct V_171 * V_132 ,
struct V_5 * V_6 ,
struct V_340 * V_160 )
{
T_6 type ;
F_129 ( log , V_160 ) ;
if ( V_23 -> V_341 == 0 ) {
return;
}
type = 0 ;
if ( V_160 -> V_163 & V_307 )
type |= V_322 ;
if ( V_160 -> V_163 & V_308 )
type |= V_323 ;
if ( V_160 -> V_163 & V_309 )
type |= V_324 ;
if ( log -> V_342 & type )
return;
F_121 ( V_23 , V_132 , V_6 , V_160 ) ;
}
STATIC int
F_130 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_343 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_344 ;
T_8 V_126 ;
if ( F_105 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
F_131 ( log , V_160 ) ;
return 0 ;
}
F_132 ( log , V_160 ) ;
V_344 = 0 ;
if ( V_160 -> V_163 & V_165 )
V_344 |= V_345 ;
V_6 = F_133 ( V_23 -> V_346 , V_160 -> V_175 , V_160 -> V_178 ,
V_344 , NULL ) ;
if ( ! V_6 )
return F_34 ( V_49 ) ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_56 ) ;
goto V_347;
}
V_126 = F_116 ( V_23 , V_6 ) ;
if ( V_126 && V_126 != - 1 && F_134 ( V_126 , V_343 ) >= 0 )
goto V_347;
if ( V_160 -> V_163 & V_165 ) {
error = F_107 ( V_23 , V_132 , V_6 , V_160 ) ;
} else if ( V_160 -> V_163 &
( V_307 | V_308 | V_309 ) ) {
F_128 ( V_23 , log , V_132 , V_6 , V_160 ) ;
} else {
F_121 ( V_23 , V_132 , V_6 , V_160 ) ;
}
if ( error )
goto V_347;
if ( V_262 ==
F_117 ( * ( ( V_260 * ) F_114 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_135 ( log -> V_7 -> V_25 . V_348 ,
( T_16 ) F_136 ( log -> V_7 ) ) ) ) {
F_137 ( V_6 ) ;
error = F_26 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_138 ( V_6 , V_157 ) ;
}
V_347:
F_27 ( V_6 ) ;
return error ;
}
STATIC int
F_139 (
struct V_184 * V_23 ,
struct V_205 * V_349 ,
struct V_350 * V_147 ,
struct V_131 * V_157 )
{
struct V_351 * V_352 ;
int error ;
ASSERT ( V_147 -> V_353 & ( V_354 | V_355 ) ) ;
V_352 = F_140 ( V_23 , V_147 -> V_356 ) ;
if ( ! V_352 )
return V_49 ;
F_141 ( & V_352 -> V_357 , V_349 ) ;
ASSERT ( V_352 -> V_357 . V_358 >= 3 ) ;
error = F_142 ( V_352 , V_349 ) ;
if ( error )
goto V_359;
if ( V_147 -> V_353 & V_354 ) {
ASSERT ( V_147 -> V_353 & V_360 ) ;
error = F_143 ( NULL , V_352 , V_361 ,
V_352 -> V_362 , V_157 ) ;
if ( error )
goto V_359;
}
if ( V_147 -> V_353 & V_355 ) {
ASSERT ( V_147 -> V_353 & V_363 ) ;
error = F_143 ( NULL , V_352 , V_364 ,
V_352 -> V_362 , V_157 ) ;
if ( error )
goto V_359;
}
V_359:
F_144 ( V_352 ) ;
return error ;
}
STATIC int
F_145 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_343 )
{
T_12 * V_147 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_199 * V_349 ;
int V_136 ;
T_2 V_365 ;
T_2 V_366 ;
int error ;
int V_367 ;
T_6 V_368 ;
T_20 * V_369 ;
T_6 V_370 ;
int V_371 = 0 ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( T_12 ) ) {
V_147 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_147 = F_84 ( sizeof( T_12 ) , V_127 ) ;
V_371 = 1 ;
error = F_146 ( & V_132 -> V_143 [ 0 ] , V_147 ) ;
if ( error )
goto error;
}
if ( F_105 ( log , V_147 -> V_372 ,
V_147 -> V_373 , 0 ) ) {
error = 0 ;
F_147 ( log , V_147 ) ;
goto error;
}
F_148 ( log , V_147 ) ;
V_6 = F_133 ( V_23 -> V_346 , V_147 -> V_372 , V_147 -> V_373 , 0 ,
& V_196 ) ;
if ( ! V_6 ) {
error = V_49 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_57 ) ;
goto V_347;
}
ASSERT ( V_147 -> V_353 & V_374 ) ;
V_349 = ( V_199 * ) F_114 ( V_6 , V_147 -> V_375 ) ;
if ( F_33 ( V_349 -> V_376 != F_124 ( V_262 ) ) ) {
F_113 ( V_23 ,
L_58 ,
V_8 , V_349 , V_6 , V_147 -> V_356 ) ;
F_4 ( L_59 ,
V_121 , V_23 ) ;
error = V_16 ;
goto V_347;
}
V_369 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( F_33 ( V_369 -> V_376 != V_262 ) ) {
F_113 ( V_23 ,
L_60 ,
V_8 , V_132 , V_147 -> V_356 ) ;
F_4 ( L_61 ,
V_121 , V_23 ) ;
error = V_16 ;
goto V_347;
}
if ( V_349 -> V_358 >= 3 ) {
T_8 V_126 = F_56 ( V_349 -> V_377 ) ;
if ( V_126 && V_126 != - 1 && F_134 ( V_126 , V_343 ) >= 0 ) {
F_149 ( log , V_147 ) ;
error = 0 ;
goto V_378;
}
}
if ( ! F_109 ( & V_23 -> V_25 ) &&
V_369 -> V_379 < F_117 ( V_349 -> V_379 ) ) {
if ( F_117 ( V_349 -> V_379 ) == V_380 &&
V_369 -> V_379 < ( V_380 >> 1 ) ) {
} else {
F_149 ( log , V_147 ) ;
error = 0 ;
goto V_347;
}
}
V_369 -> V_379 = 0 ;
if ( F_33 ( F_150 ( V_369 -> V_381 ) ) ) {
if ( ( V_369 -> V_382 != V_383 ) &&
( V_369 -> V_382 != V_384 ) ) {
F_151 ( L_62 ,
V_121 , V_23 , V_369 ) ;
F_113 ( V_23 ,
L_63
L_64 ,
V_8 , V_132 , V_349 , V_6 , V_147 -> V_356 ) ;
error = V_16 ;
goto V_347;
}
} else if ( F_33 ( F_152 ( V_369 -> V_381 ) ) ) {
if ( ( V_369 -> V_382 != V_383 ) &&
( V_369 -> V_382 != V_384 ) &&
( V_369 -> V_382 != V_385 ) ) {
F_151 ( L_65 ,
V_121 , V_23 , V_369 ) ;
F_113 ( V_23 ,
L_66
L_64 ,
V_8 , V_132 , V_349 , V_6 , V_147 -> V_356 ) ;
error = V_16 ;
goto V_347;
}
}
if ( F_33 ( V_369 -> V_386 + V_369 -> V_387 > V_369 -> V_388 ) ) {
F_151 ( L_67 ,
V_121 , V_23 , V_369 ) ;
F_113 ( V_23 ,
L_68
L_69 ,
V_8 , V_132 , V_349 , V_6 , V_147 -> V_356 ,
V_369 -> V_386 + V_369 -> V_387 ,
V_369 -> V_388 ) ;
error = V_16 ;
goto V_347;
}
if ( F_33 ( V_369 -> V_389 > V_23 -> V_25 . V_198 ) ) {
F_151 ( L_70 ,
V_121 , V_23 , V_369 ) ;
F_113 ( V_23 ,
L_68
L_71 , V_8 ,
V_132 , V_349 , V_6 , V_147 -> V_356 , V_369 -> V_389 ) ;
error = V_16 ;
goto V_347;
}
V_370 = F_153 ( V_369 -> V_358 ) ;
if ( F_33 ( V_132 -> V_143 [ 1 ] . V_146 > V_370 ) ) {
F_151 ( L_72 ,
V_121 , V_23 , V_369 ) ;
F_113 ( V_23 ,
L_73 ,
V_8 , V_132 -> V_143 [ 1 ] . V_146 , V_132 ) ;
error = V_16 ;
goto V_347;
}
F_154 ( V_349 , V_369 ) ;
if ( V_132 -> V_143 [ 1 ] . V_146 > V_370 ) {
memcpy ( ( char * ) V_349 + V_370 ,
V_132 -> V_143 [ 1 ] . V_145 + V_370 ,
V_132 -> V_143 [ 1 ] . V_146 - V_370 ) ;
}
V_368 = V_147 -> V_353 ;
switch ( V_368 & ( V_390 | V_391 ) ) {
case V_390 :
F_155 ( V_349 , V_147 -> V_392 . V_393 ) ;
break;
case V_391 :
memcpy ( F_156 ( V_349 ) ,
& V_147 -> V_392 . V_394 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_147 -> V_150 == 2 )
goto V_378;
V_136 = V_132 -> V_143 [ 2 ] . V_146 ;
V_365 = V_132 -> V_143 [ 2 ] . V_145 ;
ASSERT ( V_147 -> V_150 <= 4 ) ;
ASSERT ( ( V_147 -> V_150 == 3 ) || ( V_368 & V_395 ) ) ;
ASSERT ( ! ( V_368 & V_396 ) ||
( V_136 == V_147 -> V_397 ) ) ;
switch ( V_368 & V_396 ) {
case V_398 :
case V_399 :
memcpy ( F_156 ( V_349 ) , V_365 , V_136 ) ;
break;
case V_360 :
F_157 ( V_23 , (struct V_218 * ) V_365 , V_136 ,
( V_400 * ) F_156 ( V_349 ) ,
F_158 ( V_349 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_368 & V_396 ) == 0 ) ;
break;
}
if ( V_147 -> V_353 & V_395 ) {
if ( V_147 -> V_353 & V_396 ) {
V_367 = 3 ;
} else {
V_367 = 2 ;
}
V_136 = V_132 -> V_143 [ V_367 ] . V_146 ;
V_365 = V_132 -> V_143 [ V_367 ] . V_145 ;
ASSERT ( V_136 == V_147 -> V_401 ) ;
switch ( V_147 -> V_353 & V_395 ) {
case V_402 :
case V_403 :
V_366 = F_159 ( V_349 ) ;
ASSERT ( V_136 <= F_160 ( V_349 , V_23 ) ) ;
memcpy ( V_366 , V_365 , V_136 ) ;
break;
case V_363 :
V_366 = F_159 ( V_349 ) ;
F_157 ( V_23 , (struct V_218 * ) V_365 ,
V_136 , ( V_400 * ) V_366 ,
F_160 ( V_349 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_74 , V_8 ) ;
ASSERT ( 0 ) ;
error = V_58 ;
goto V_347;
}
}
V_378:
if ( V_147 -> V_353 & ( V_354 | V_355 ) )
error = F_139 ( V_23 , V_349 , V_147 ,
V_157 ) ;
F_115 ( log -> V_7 , V_349 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_138 ( V_6 , V_157 ) ;
V_347:
F_27 ( V_6 ) ;
error:
if ( V_371 )
F_85 ( V_147 ) ;
return F_34 ( error ) ;
}
STATIC int
F_161 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_21 * V_404 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_404 ) ;
if ( V_404 -> V_405 & V_406 )
log -> V_342 |= V_322 ;
if ( V_404 -> V_405 & V_407 )
log -> V_342 |= V_323 ;
if ( V_404 -> V_405 & V_408 )
log -> V_342 |= V_324 ;
return ( 0 ) ;
}
STATIC int
F_162 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_343 )
{
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_409 * V_313 , * V_410 ;
int error ;
T_22 * V_411 ;
T_6 type ;
if ( V_23 -> V_341 == 0 )
return ( 0 ) ;
V_410 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_410 == NULL ) {
F_113 ( log -> V_7 , L_75 , V_8 ) ;
return F_34 ( V_58 ) ;
}
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( V_311 ) ) {
F_113 ( log -> V_7 , L_76 ,
V_132 -> V_143 [ 1 ] . V_146 , V_8 ) ;
return F_34 ( V_58 ) ;
}
type = V_410 -> V_321 & ( V_322 | V_323 | V_324 ) ;
ASSERT ( type ) ;
if ( log -> V_342 & type )
return ( 0 ) ;
V_411 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_411 ) ;
error = F_123 ( V_23 , V_410 , V_411 -> V_412 , 0 , V_312 ,
L_77 ) ;
if ( error )
return F_34 ( V_58 ) ;
ASSERT ( V_411 -> V_413 == 1 ) ;
error = F_163 ( V_23 , NULL , V_23 -> V_346 , V_411 -> V_414 ,
F_164 ( V_23 , V_411 -> V_413 ) , 0 , & V_6 ,
NULL ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_313 = ( V_311 * ) F_114 ( V_6 , V_411 -> V_415 ) ;
error = F_123 ( V_23 , V_313 , V_411 -> V_412 , 0 , V_312 ,
L_78 ) ;
if ( error ) {
F_27 ( V_6 ) ;
return F_34 ( V_58 ) ;
}
if ( F_109 ( & V_23 -> V_25 ) ) {
struct V_338 * V_416 = (struct V_338 * ) V_313 ;
T_8 V_126 = F_56 ( V_416 -> V_417 ) ;
if ( V_126 && V_126 != - 1 && F_134 ( V_126 , V_343 ) >= 0 ) {
goto V_347;
}
}
memcpy ( V_313 , V_410 , V_132 -> V_143 [ 1 ] . V_146 ) ;
if ( F_109 ( & V_23 -> V_25 ) ) {
F_127 ( ( char * ) V_313 , sizeof( struct V_338 ) ,
V_339 ) ;
}
ASSERT ( V_411 -> V_418 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_138 ( V_6 , V_157 ) ;
V_347:
F_27 ( V_6 ) ;
return 0 ;
}
STATIC int
F_165 (
struct V_1 * log ,
struct V_171 * V_132 ,
T_8 V_126 )
{
int error ;
T_4 * V_23 = log -> V_7 ;
T_23 * V_419 ;
T_24 * V_420 ;
V_420 = V_132 -> V_143 [ 0 ] . V_145 ;
V_419 = F_166 ( V_23 , V_420 -> V_421 ) ;
if ( ( error = F_167 ( & ( V_132 -> V_143 [ 0 ] ) ,
& ( V_419 -> V_422 ) ) ) ) {
F_168 ( V_419 ) ;
return error ;
}
F_169 ( & V_419 -> V_423 , V_420 -> V_421 ) ;
F_170 ( & log -> V_424 -> V_425 ) ;
F_171 ( log -> V_424 , & V_419 -> V_426 , V_126 ) ;
return 0 ;
}
STATIC int
F_172 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_25 * V_427 ;
T_23 * V_419 = NULL ;
T_26 * V_428 ;
T_27 V_429 ;
struct V_430 V_431 ;
struct V_432 * V_433 = log -> V_424 ;
V_427 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( ( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_434 ) +
( ( V_427 -> V_435 - 1 ) * sizeof( V_436 ) ) ) ) ||
( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_437 ) +
( ( V_427 -> V_435 - 1 ) * sizeof( V_438 ) ) ) ) ) ;
V_429 = V_427 -> V_439 ;
F_170 ( & V_433 -> V_425 ) ;
V_428 = F_173 ( V_433 , & V_431 , 0 ) ;
while ( V_428 != NULL ) {
if ( V_428 -> V_440 == V_170 ) {
V_419 = ( T_23 * ) V_428 ;
if ( V_419 -> V_422 . V_429 == V_429 ) {
F_174 ( V_433 , V_428 ,
V_441 ) ;
F_168 ( V_419 ) ;
F_170 ( & V_433 -> V_425 ) ;
break;
}
}
V_428 = F_175 ( V_433 , & V_431 ) ;
}
F_176 ( V_433 , & V_431 ) ;
F_177 ( & V_433 -> V_425 ) ;
return 0 ;
}
STATIC int
F_178 (
struct V_1 * log ,
struct V_131 * V_157 ,
T_11 * V_132 )
{
struct V_184 * V_23 = log -> V_7 ;
struct V_442 * V_443 ;
T_28 V_444 ;
T_29 V_445 ;
unsigned int V_446 ;
unsigned int V_370 ;
T_29 V_447 ;
V_443 = (struct V_442 * ) V_132 -> V_143 [ 0 ] . V_145 ;
if ( V_443 -> V_448 != V_161 ) {
F_3 ( log -> V_7 , L_79 ) ;
return V_102 ;
}
if ( V_443 -> V_449 != 1 ) {
F_3 ( log -> V_7 , L_80 ) ;
return V_102 ;
}
V_444 = F_30 ( V_443 -> V_450 ) ;
if ( V_444 >= V_23 -> V_25 . V_451 ) {
F_3 ( log -> V_7 , L_81 ) ;
return V_102 ;
}
V_445 = F_30 ( V_443 -> V_452 ) ;
if ( ! V_445 || V_445 == V_453 || V_445 >= V_23 -> V_25 . V_454 ) {
F_3 ( log -> V_7 , L_82 ) ;
return V_102 ;
}
V_370 = F_30 ( V_443 -> V_455 ) ;
if ( V_370 != V_23 -> V_25 . V_198 ) {
F_3 ( log -> V_7 , L_83 ) ;
return V_102 ;
}
V_446 = F_30 ( V_443 -> V_456 ) ;
if ( ! V_446 ) {
F_3 ( log -> V_7 , L_84 ) ;
return V_102 ;
}
V_447 = F_30 ( V_443 -> V_457 ) ;
if ( ! V_447 || V_447 >= V_23 -> V_25 . V_454 ) {
F_3 ( log -> V_7 , L_85 ) ;
return V_102 ;
}
ASSERT ( V_446 == F_179 ( V_23 ) ) ;
ASSERT ( V_447 == F_180 ( V_23 ) ) ;
if ( V_446 != F_179 ( V_23 ) ||
V_447 != F_180 ( V_23 ) ) {
F_3 ( log -> V_7 , L_86 ) ;
return V_102 ;
}
if ( F_105 ( log ,
F_181 ( V_23 , V_444 , V_445 ) , V_447 , 0 ) )
return 0 ;
F_182 ( V_23 , NULL , V_157 , V_444 , V_445 , V_447 ,
F_30 ( V_443 -> V_458 ) ) ;
return 0 ;
}
STATIC void
F_183 (
struct V_134 * V_124 )
{
T_11 * V_132 , * V_154 ;
int V_45 ;
F_90 (item, n, &trans->r_itemq, ri_list) {
F_106 ( & V_132 -> V_133 ) ;
for ( V_45 = 0 ; V_45 < V_132 -> V_144 ; V_45 ++ )
F_85 ( V_132 -> V_143 [ V_45 ] . V_145 ) ;
F_85 ( V_132 -> V_143 ) ;
F_85 ( V_132 ) ;
}
F_85 ( V_124 ) ;
}
STATIC void
F_184 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_340 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_184 * V_23 = log -> V_7 ;
if ( F_104 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
return;
}
F_185 ( V_23 -> V_346 , V_160 -> V_175 ,
V_160 -> V_178 , NULL ) ;
}
STATIC void
F_186 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_350 V_459 ;
struct V_350 * V_460 ;
struct V_184 * V_23 = log -> V_7 ;
int error ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( struct V_350 ) ) {
V_460 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_460 = & V_459 ;
memset ( V_460 , 0 , sizeof( * V_460 ) ) ;
error = F_146 ( & V_132 -> V_143 [ 0 ] , V_460 ) ;
if ( error )
return;
}
if ( F_104 ( log , V_460 -> V_372 , V_460 -> V_373 , 0 ) )
return;
F_185 ( V_23 -> V_346 , V_460 -> V_372 ,
V_460 -> V_373 , & V_461 ) ;
}
STATIC void
F_187 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_184 * V_23 = log -> V_7 ;
struct V_409 * V_410 ;
struct V_462 * V_411 ;
T_6 type ;
if ( V_23 -> V_341 == 0 )
return;
V_410 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_410 == NULL )
return;
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( struct V_409 ) )
return;
type = V_410 -> V_321 & ( V_322 | V_323 | V_324 ) ;
ASSERT ( type ) ;
if ( log -> V_342 & type )
return;
V_411 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_411 ) ;
ASSERT ( V_411 -> V_413 == 1 ) ;
F_185 ( V_23 -> V_346 , V_411 -> V_414 ,
F_164 ( V_23 , V_411 -> V_413 ) , NULL ) ;
}
STATIC void
F_188 (
struct V_1 * log ,
struct V_171 * V_132 )
{
switch ( F_91 ( V_132 ) ) {
case V_162 :
F_184 ( log , V_132 ) ;
break;
case V_166 :
F_186 ( log , V_132 ) ;
break;
case V_167 :
F_187 ( log , V_132 ) ;
break;
case V_170 :
case V_169 :
case V_168 :
default:
break;
}
}
STATIC int
F_189 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_171 * V_132 )
{
F_190 ( log , V_124 , V_132 , V_463 ) ;
switch ( F_91 ( V_132 ) ) {
case V_162 :
return F_98 ( log , V_132 ) ;
case V_168 :
return F_161 ( log , V_132 ) ;
case V_166 :
case V_170 :
case V_169 :
case V_167 :
case V_161 :
return 0 ;
default:
F_3 ( log -> V_7 , L_87 ,
V_8 , F_91 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_191 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_171 * V_132 )
{
F_190 ( log , V_124 , V_132 , V_464 ) ;
switch ( F_91 ( V_132 ) ) {
case V_162 :
return F_130 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_166 :
return F_145 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_170 :
return F_165 ( log , V_132 , V_124 -> V_128 ) ;
case V_169 :
return F_172 ( log , V_132 ) ;
case V_167 :
return F_162 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_161 :
return F_178 ( log , V_157 , V_132 ) ;
case V_168 :
return 0 ;
default:
F_3 ( log -> V_7 , L_87 ,
V_8 , F_91 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_192 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_131 * V_465 )
{
struct V_171 * V_132 ;
int error = 0 ;
F_101 (item, item_list, ri_list) {
error = F_191 ( log , V_124 ,
V_157 , V_132 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_193 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
int error = 0 ;
int V_22 ;
int V_466 = 0 ;
struct V_171 * V_132 ;
struct V_171 * V_310 ;
F_88 ( V_157 ) ;
F_88 ( V_467 ) ;
F_88 ( V_468 ) ;
#define F_194 100
F_195 ( & V_124 -> V_130 ) ;
error = F_87 ( log , V_124 , V_153 ) ;
if ( error )
return error ;
F_90 (item, next, &trans->r_itemq, ri_list) {
switch ( V_153 ) {
case V_463 :
error = F_189 ( log , V_124 , V_132 ) ;
break;
case V_464 :
F_188 ( log , V_132 ) ;
F_92 ( & V_132 -> V_133 , & V_467 ) ;
V_466 ++ ;
if ( V_466 >= F_194 ) {
error = F_192 ( log , V_124 ,
& V_157 , & V_467 ) ;
F_196 ( & V_467 , & V_468 ) ;
V_466 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
V_51:
if ( ! F_79 ( & V_467 ) ) {
if ( ! error )
error = F_192 ( log , V_124 ,
& V_157 , & V_467 ) ;
F_196 ( & V_467 , & V_468 ) ;
}
if ( ! F_79 ( & V_468 ) )
F_89 ( & V_468 , & V_124 -> V_129 ) ;
F_183 ( V_124 ) ;
V_22 = F_197 ( & V_157 ) ;
return error ? error : V_22 ;
}
STATIC int
F_198 (
struct V_1 * log ,
struct V_134 * V_124 )
{
F_3 ( log -> V_7 , L_88 , V_8 ) ;
return 0 ;
}
STATIC int
F_199 (
struct V_1 * log ,
struct V_122 V_469 [] ,
struct V_470 * V_73 ,
T_2 V_135 ,
int V_153 )
{
T_2 V_471 ;
int V_472 ;
T_7 * V_473 ;
T_9 * V_124 ;
T_10 V_123 ;
int error ;
unsigned long V_474 ;
T_6 V_182 ;
V_471 = V_135 + F_30 ( V_73 -> V_61 ) ;
V_472 = F_30 ( V_73 -> V_95 ) ;
if ( F_31 ( log -> V_7 , V_73 ) )
return ( F_34 ( V_58 ) ) ;
while ( ( V_135 < V_471 ) && V_472 ) {
ASSERT ( V_135 + sizeof( T_7 ) <= V_471 ) ;
V_473 = ( T_7 * ) V_135 ;
V_135 += sizeof( T_7 ) ;
if ( V_473 -> V_475 != V_476 &&
V_473 -> V_475 != V_477 ) {
F_3 ( log -> V_7 , L_89 ,
V_8 , V_473 -> V_475 ) ;
ASSERT ( 0 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_123 = F_30 ( V_473 -> V_478 ) ;
V_474 = F_200 ( V_123 ) ;
V_124 = F_69 ( & V_469 [ V_474 ] , V_123 ) ;
if ( V_124 == NULL ) {
if ( V_473 -> V_96 & V_479 )
F_71 ( & V_469 [ V_474 ] , V_123 ,
F_56 ( V_73 -> V_89 ) ) ;
} else {
if ( V_135 + F_30 ( V_473 -> V_480 ) > V_471 ) {
F_3 ( log -> V_7 , L_90 ,
V_8 , F_30 ( V_473 -> V_480 ) ) ;
F_201 ( 1 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_182 = V_473 -> V_96 & ~ V_481 ;
if ( V_182 & V_482 )
V_182 &= ~ V_483 ;
switch ( V_182 ) {
case V_484 :
error = F_193 ( log ,
V_124 , V_153 ) ;
break;
case V_97 :
error = F_198 ( log , V_124 ) ;
break;
case V_482 :
error = F_78 ( log ,
V_124 , V_135 ,
F_30 ( V_473 -> V_480 ) ) ;
break;
case V_479 :
F_3 ( log -> V_7 , L_91 ,
V_8 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
case 0 :
case V_483 :
error = F_83 ( log , V_124 ,
V_135 , F_30 ( V_473 -> V_480 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_92 ,
V_8 , V_182 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
}
if ( error )
return error ;
}
V_135 += F_30 ( V_473 -> V_480 ) ;
V_472 -- ;
}
return 0 ;
}
STATIC int
F_202 (
T_4 * V_23 ,
T_23 * V_419 )
{
T_30 * V_485 ;
T_31 * V_486 ;
int V_45 ;
int error = 0 ;
T_32 * V_487 ;
T_33 V_488 ;
ASSERT ( ! F_203 ( V_489 , & V_419 -> V_490 ) ) ;
for ( V_45 = 0 ; V_45 < V_419 -> V_422 . V_421 ; V_45 ++ ) {
V_487 = & ( V_419 -> V_422 . V_491 [ V_45 ] ) ;
V_488 = F_204 ( V_23 ,
F_205 ( V_23 , V_487 -> V_492 ) ) ;
if ( ( V_488 == 0 ) ||
( V_487 -> V_493 == 0 ) ||
( V_488 >= V_23 -> V_25 . V_494 ) ||
( V_487 -> V_493 >= V_23 -> V_25 . V_454 ) ) {
F_206 ( V_489 , & V_419 -> V_490 ) ;
F_207 ( V_419 , V_419 -> V_422 . V_421 ) ;
return F_34 ( V_58 ) ;
}
}
V_486 = F_208 ( V_23 , 0 ) ;
error = F_209 ( V_486 , & F_210 ( V_23 ) -> V_495 , 0 , 0 ) ;
if ( error )
goto V_496;
V_485 = F_211 ( V_486 , V_419 , V_419 -> V_422 . V_421 ) ;
for ( V_45 = 0 ; V_45 < V_419 -> V_422 . V_421 ; V_45 ++ ) {
V_487 = & ( V_419 -> V_422 . V_491 [ V_45 ] ) ;
error = F_212 ( V_486 , V_487 -> V_492 , V_487 -> V_493 ) ;
if ( error )
goto V_496;
F_213 ( V_486 , V_485 , V_487 -> V_492 ,
V_487 -> V_493 ) ;
}
F_206 ( V_489 , & V_419 -> V_490 ) ;
error = F_214 ( V_486 , 0 ) ;
return error ;
V_496:
F_215 ( V_486 , V_497 ) ;
return error ;
}
STATIC int
F_216 (
struct V_1 * log )
{
T_26 * V_428 ;
T_23 * V_419 ;
int error = 0 ;
struct V_430 V_431 ;
struct V_432 * V_433 ;
V_433 = log -> V_424 ;
F_170 ( & V_433 -> V_425 ) ;
V_428 = F_173 ( V_433 , & V_431 , 0 ) ;
while ( V_428 != NULL ) {
if ( V_428 -> V_440 != V_170 ) {
#ifdef F_217
for (; V_428 ; V_428 = F_175 ( V_433 , & V_431 ) )
ASSERT ( V_428 -> V_440 != V_170 ) ;
#endif
break;
}
V_419 = ( T_23 * ) V_428 ;
if ( F_203 ( V_489 , & V_419 -> V_490 ) ) {
V_428 = F_175 ( V_433 , & V_431 ) ;
continue;
}
F_177 ( & V_433 -> V_425 ) ;
error = F_202 ( log -> V_7 , V_419 ) ;
F_170 ( & V_433 -> V_425 ) ;
if ( error )
goto V_51;
V_428 = F_175 ( V_433 , & V_431 ) ;
}
V_51:
F_176 ( V_433 , & V_431 ) ;
F_177 ( & V_433 -> V_425 ) ;
return error ;
}
STATIC void
F_218 (
T_4 * V_23 ,
T_28 V_444 ,
int V_172 )
{
T_31 * V_486 ;
T_34 * V_498 ;
T_1 * V_499 ;
int V_13 ;
int error ;
V_486 = F_208 ( V_23 , V_500 ) ;
error = F_209 ( V_486 , & F_210 ( V_23 ) -> V_501 , 0 , 0 ) ;
if ( error )
goto V_502;
error = F_219 ( V_23 , V_486 , V_444 , & V_499 ) ;
if ( error )
goto V_502;
V_498 = F_220 ( V_499 ) ;
V_498 -> V_503 [ V_172 ] = F_32 ( V_504 ) ;
V_13 = F_110 ( T_34 , V_503 ) +
( sizeof( T_15 ) * V_172 ) ;
F_221 ( V_486 , V_499 , V_13 ,
( V_13 + sizeof( T_15 ) - 1 ) ) ;
error = F_214 ( V_486 , 0 ) ;
if ( error )
goto V_505;
return;
V_502:
F_215 ( V_486 , V_497 ) ;
V_505:
F_3 ( V_23 , L_93 , V_8 , V_444 ) ;
return;
}
STATIC T_15
F_222 (
struct V_184 * V_23 ,
T_28 V_444 ,
T_15 V_506 ,
int V_172 )
{
struct V_5 * V_507 ;
struct V_205 * V_349 ;
struct V_351 * V_352 ;
T_35 V_508 ;
int error ;
V_508 = F_223 ( V_23 , V_444 , V_506 ) ;
error = F_224 ( V_23 , NULL , V_508 , 0 , 0 , & V_352 ) ;
if ( error )
goto V_509;
error = F_225 ( V_23 , NULL , & V_352 -> V_510 , & V_349 , & V_507 , 0 , 0 ) ;
if ( error )
goto V_511;
ASSERT ( V_352 -> V_357 . V_512 == 0 ) ;
ASSERT ( V_352 -> V_357 . V_381 != 0 ) ;
V_506 = F_30 ( V_349 -> V_200 ) ;
F_27 ( V_507 ) ;
V_352 -> V_357 . V_513 = 0 ;
F_226 ( V_352 ) ;
return V_506 ;
V_511:
F_226 ( V_352 ) ;
V_509:
F_218 ( V_23 , V_444 , V_172 ) ;
return V_504 ;
}
STATIC void
F_227 (
struct V_1 * log )
{
T_4 * V_23 ;
T_28 V_444 ;
T_34 * V_498 ;
T_1 * V_499 ;
T_15 V_506 ;
int V_172 ;
int error ;
T_6 V_514 ;
V_23 = log -> V_7 ;
V_514 = V_23 -> V_515 ;
V_23 -> V_515 = 0 ;
for ( V_444 = 0 ; V_444 < V_23 -> V_25 . V_451 ; V_444 ++ ) {
error = F_219 ( V_23 , NULL , V_444 , & V_499 ) ;
if ( error ) {
continue;
}
V_498 = F_220 ( V_499 ) ;
F_7 ( V_499 ) ;
for ( V_172 = 0 ; V_172 < V_516 ; V_172 ++ ) {
V_506 = F_30 ( V_498 -> V_503 [ V_172 ] ) ;
while ( V_506 != V_504 ) {
V_506 = F_222 ( V_23 ,
V_444 , V_506 , V_172 ) ;
}
}
F_228 ( V_499 ) ;
}
V_23 -> V_515 = V_514 ;
}
STATIC int
F_229 (
struct V_470 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
T_36 V_517 ;
V_517 = F_230 ( log , V_73 , V_135 , F_30 ( V_73 -> V_61 ) ) ;
if ( V_517 != V_73 -> V_518 ) {
if ( V_73 -> V_518 || F_109 ( & log -> V_7 -> V_25 ) ) {
F_113 ( log -> V_7 ,
L_94 ,
F_231 ( V_73 -> V_518 ) ,
F_231 ( V_517 ) ) ;
F_232 ( V_135 , 32 ) ;
}
if ( F_109 ( & log -> V_7 -> V_25 ) )
return V_16 ;
}
return 0 ;
}
STATIC int
F_233 (
struct V_470 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
int V_45 , V_46 , V_519 ;
int error ;
error = F_229 ( V_73 , V_135 , log ) ;
if ( error )
return error ;
for ( V_45 = 0 ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_81 * ) V_135 = * ( V_81 * ) & V_73 -> V_520 [ V_45 ] ;
V_135 += V_52 ;
}
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
T_37 * V_521 = ( T_37 * ) V_73 ;
for ( ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_519 = V_45 % ( V_60 / V_52 ) ;
* ( V_81 * ) V_135 = V_521 [ V_46 ] . V_522 . V_523 [ V_519 ] ;
V_135 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_234 (
struct V_1 * log ,
struct V_470 * V_73 ,
T_3 V_181 )
{
int V_524 ;
if ( F_33 ( V_73 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_95 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 (
( ! V_73 -> V_93 ||
( F_30 ( V_73 -> V_93 ) & ( ~ V_525 ) ) ) ) ) {
F_3 ( log -> V_7 , L_96 ,
V_8 , F_30 ( V_73 -> V_93 ) ) ;
return F_34 ( V_58 ) ;
}
V_524 = F_30 ( V_73 -> V_61 ) ;
if ( F_33 ( V_524 <= 0 || V_524 > V_70 ) ) {
F_4 ( L_97 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 ( V_181 > log -> V_3 || V_181 > V_70 ) ) {
F_4 ( L_98 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
return 0 ;
}
STATIC int
F_235 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_153 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_526 , * V_527 ;
int error = 0 , V_59 ;
int V_528 , V_529 ;
int V_79 , V_530 , V_531 ;
struct V_122 V_469 [ V_532 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
V_526 = F_2 ( log , 1 ) ;
if ( ! V_526 )
return V_49 ;
error = F_19 ( log , V_72 , 1 , V_526 , & V_13 ) ;
if ( error )
goto V_533;
V_73 = ( T_5 * ) V_13 ;
error = F_234 ( log , V_73 , V_72 ) ;
if ( error )
goto V_533;
V_59 = F_30 ( V_73 -> V_59 ) ;
if ( ( F_30 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_526 ) ;
V_526 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_526 = F_2 ( log , 1 ) ;
V_59 = V_534 ;
}
if ( ! V_526 )
return V_49 ;
V_527 = F_2 ( log , F_49 ( V_59 ) ) ;
if ( ! V_527 ) {
F_8 ( V_526 ) ;
return V_49 ;
}
memset ( V_469 , 0 , sizeof( V_469 ) ) ;
if ( V_72 <= V_63 ) {
for ( V_12 = V_72 ; V_12 < V_63 ; ) {
error = F_19 ( log , V_12 , V_79 , V_526 , & V_13 ) ;
if ( error )
goto V_535;
V_73 = ( T_5 * ) V_13 ;
error = F_234 ( log , V_73 , V_12 ) ;
if ( error )
goto V_535;
V_528 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_528 , V_527 ,
& V_13 ) ;
if ( error )
goto V_535;
error = F_233 ( V_73 , V_13 , log ) ;
if ( error )
goto V_535;
error = F_199 ( log ,
V_469 , V_73 , V_13 , V_153 ) ;
if ( error )
goto V_535;
V_12 += V_528 + V_79 ;
}
} else {
V_12 = V_72 ;
while ( V_12 < log -> V_3 ) {
V_13 = V_526 -> V_15 ;
V_530 = 0 ;
V_531 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_79 , V_526 ,
& V_13 ) ;
if ( error )
goto V_535;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_530 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_530 > 0 ) ;
error = F_19 ( log , V_12 ,
V_530 , V_526 ,
& V_13 ) ;
if ( error )
goto V_535;
}
V_531 = V_79 - V_530 ;
error = F_20 ( log , 0 ,
V_531 , V_526 ,
V_13 + F_11 ( V_530 ) ) ;
if ( error )
goto V_535;
}
V_73 = ( T_5 * ) V_13 ;
error = F_234 ( log , V_73 ,
V_530 ? V_12 : 0 ) ;
if ( error )
goto V_535;
V_528 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_528 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_528 , V_527 ,
& V_13 ) ;
if ( error )
goto V_535;
} else {
V_13 = V_527 -> V_15 ;
V_529 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_531 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_529 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_529 > 0 ) ;
error = F_19 ( log , V_12 ,
V_529 , V_527 ,
& V_13 ) ;
if ( error )
goto V_535;
}
error = F_20 ( log , 0 ,
V_528 - V_529 , V_527 ,
V_13 + F_11 ( V_529 ) ) ;
if ( error )
goto V_535;
}
error = F_233 ( V_73 , V_13 , log ) ;
if ( error )
goto V_535;
error = F_199 ( log , V_469 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_535;
V_12 += V_528 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_79 , V_526 , & V_13 ) ;
if ( error )
goto V_535;
V_73 = ( T_5 * ) V_13 ;
error = F_234 ( log , V_73 , V_12 ) ;
if ( error )
goto V_535;
V_528 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_528 , V_527 ,
& V_13 ) ;
if ( error )
goto V_535;
error = F_233 ( V_73 , V_13 , log ) ;
if ( error )
goto V_535;
error = F_199 ( log , V_469 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_535;
V_12 += V_528 + V_79 ;
}
}
V_535:
F_8 ( V_527 ) ;
V_533:
F_8 ( V_526 ) ;
return error ;
}
STATIC int
F_236 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_183 = F_72 ( V_536 *
sizeof( struct V_131 ) ,
V_127 ) ;
for ( V_45 = 0 ; V_45 < V_536 ; V_45 ++ )
F_73 ( & log -> V_183 [ V_45 ] ) ;
error = F_235 ( log , V_63 , V_72 ,
V_463 ) ;
if ( error != 0 ) {
F_85 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
error = F_235 ( log , V_63 , V_72 ,
V_464 ) ;
#ifdef F_217
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_536 ; V_45 ++ )
ASSERT ( F_79 ( & log -> V_183 [ V_45 ] ) ) ;
}
#endif
F_85 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
STATIC int
F_237 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_38 * V_537 ;
error = F_236 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_238 ( log -> V_7 ) ) {
return ( V_58 ) ;
}
F_239 ( log -> V_7 ) ;
V_6 = F_240 ( log -> V_7 , 0 ) ;
F_241 ( V_6 ) ;
ASSERT ( ! ( F_242 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_243 ( V_6 ) ;
V_6 -> V_195 = & V_306 ;
F_16 ( log -> V_7 , V_6 ) ;
error = F_17 ( V_6 ) ;
if ( error ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
return error ;
}
V_537 = & log -> V_7 -> V_25 ;
F_244 ( V_537 , F_245 ( V_6 ) ) ;
ASSERT ( V_537 -> V_538 == V_251 ) ;
ASSERT ( F_246 ( V_537 ) ) ;
F_27 ( V_6 ) ;
F_247 ( log -> V_7 ) ;
F_248 ( log ) ;
log -> V_539 &= ~ V_540 ;
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
if ( ( error = F_249 ( log -> V_7 , L_99 ) ) ) {
return error ;
}
if ( F_250 ( & log -> V_7 -> V_25 ) == V_541 &&
F_251 ( & log -> V_7 -> V_25 ,
V_542 ) ) {
F_3 ( log -> V_7 ,
L_100
L_101
L_102 ,
( log -> V_7 -> V_25 . V_543 &
V_542 ) ) ;
return V_102 ;
}
F_125 ( log -> V_7 , L_103 ,
log -> V_7 -> V_544 ? log -> V_7 -> V_544
: L_104 ) ;
error = F_237 ( log , V_63 , V_72 ) ;
log -> V_539 |= V_545 ;
}
return error ;
}
int
F_252 (
struct V_1 * log )
{
if ( log -> V_539 & V_545 ) {
int error ;
error = F_216 ( log ) ;
if ( error ) {
F_113 ( log -> V_7 , L_105 ) ;
return error ;
}
F_253 ( log -> V_7 , V_546 ) ;
F_227 ( log ) ;
F_248 ( log ) ;
F_125 ( log -> V_7 , L_106 ,
log -> V_7 -> V_544 ? log -> V_7 -> V_544
: L_104 ) ;
log -> V_539 &= ~ V_545 ;
} else {
F_254 ( log -> V_7 , L_107 ) ;
}
return 0 ;
}
void
F_248 (
struct V_1 * log )
{
T_4 * V_23 ;
T_39 * V_547 ;
T_1 * V_548 ;
T_1 * V_499 ;
T_28 V_444 ;
T_27 V_549 ;
T_27 V_550 ;
T_27 V_551 ;
int error ;
V_23 = log -> V_7 ;
V_549 = 0LL ;
V_550 = 0LL ;
V_551 = 0LL ;
for ( V_444 = 0 ; V_444 < V_23 -> V_25 . V_451 ; V_444 ++ ) {
error = F_255 ( V_23 , NULL , V_444 , 0 , & V_548 ) ;
if ( error ) {
F_113 ( V_23 , L_108 ,
V_8 , V_444 , error ) ;
} else {
V_547 = F_256 ( V_548 ) ;
V_549 += F_30 ( V_547 -> V_552 ) +
F_30 ( V_547 -> V_553 ) ;
F_27 ( V_548 ) ;
}
error = F_219 ( V_23 , NULL , V_444 , & V_499 ) ;
if ( error ) {
F_113 ( V_23 , L_109 ,
V_8 , V_444 , error ) ;
} else {
struct V_236 * V_498 = F_220 ( V_499 ) ;
V_550 += F_30 ( V_498 -> V_554 ) ;
V_551 += F_30 ( V_498 -> V_555 ) ;
F_27 ( V_499 ) ;
}
}
}
