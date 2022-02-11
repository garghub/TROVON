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
return F_34 ( V_102 ) ;
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
F_85 ( log , V_124 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_86 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
T_11 * V_132 , * V_154 ;
F_87 ( V_155 ) ;
F_87 ( V_156 ) ;
F_87 ( V_157 ) ;
F_87 ( V_158 ) ;
F_87 ( V_159 ) ;
F_88 ( & V_124 -> V_129 , & V_155 ) ;
F_89 (item, n, &sort_list, ri_list) {
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
switch ( F_90 ( V_132 ) ) {
case V_161 :
if ( V_160 -> V_162 & V_163 ) {
F_91 ( log ,
V_124 , V_132 , V_153 ) ;
F_92 ( & V_132 -> V_133 , & V_156 ) ;
break;
}
if ( V_160 -> V_162 & V_164 ) {
F_92 ( & V_132 -> V_133 , & V_158 ) ;
break;
}
F_93 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
F_94 ( log ,
V_124 , V_132 , V_153 ) ;
F_93 ( & V_132 -> V_133 , & V_159 ) ;
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
F_95 ( & V_157 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_159 ) )
F_96 ( & V_159 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_158 ) )
F_96 ( & V_158 , & V_124 -> V_129 ) ;
if ( ! F_79 ( & V_156 ) )
F_96 ( & V_156 , & V_124 -> V_129 ) ;
return 0 ;
}
STATIC int
F_97 (
struct V_1 * log ,
struct V_170 * V_132 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_131 * V_171 ;
struct V_172 * V_173 ;
if ( ! ( V_160 -> V_162 & V_163 ) ) {
F_98 ( log , V_160 ) ;
return 0 ;
}
V_171 = F_99 ( log , V_160 -> V_174 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_173 -> V_175 == V_160 -> V_174 &&
V_173 -> V_176 == V_160 -> V_177 ) {
V_173 -> V_178 ++ ;
F_101 ( log , V_160 ) ;
return 0 ;
}
}
V_173 = F_84 ( sizeof( struct V_172 ) , V_127 ) ;
V_173 -> V_175 = V_160 -> V_174 ;
V_173 -> V_176 = V_160 -> V_177 ;
V_173 -> V_178 = 1 ;
F_77 ( & V_173 -> V_179 , V_171 ) ;
F_102 ( log , V_160 ) ;
return 0 ;
}
STATIC int
F_103 (
struct V_1 * log ,
T_3 V_180 ,
T_6 V_136 ,
T_14 V_181 )
{
struct V_131 * V_171 ;
struct V_172 * V_173 ;
if ( log -> V_182 == NULL ) {
ASSERT ( ! ( V_181 & V_163 ) ) ;
return 0 ;
}
V_171 = F_99 ( log , V_180 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_173 -> V_175 == V_180 && V_173 -> V_176 == V_136 )
goto V_75;
}
ASSERT ( ! ( V_181 & V_163 ) ) ;
return 0 ;
V_75:
if ( V_181 & V_163 ) {
if ( -- V_173 -> V_178 == 0 ) {
F_104 ( & V_173 -> V_179 ) ;
F_105 ( V_173 ) ;
}
}
return 1 ;
}
STATIC int
F_106 (
struct V_183 * V_23 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_45 ;
int V_184 = 0 ;
int V_185 = 0 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_189 ;
int V_190 ;
T_15 * V_191 ;
T_15 * V_192 ;
F_107 ( V_23 -> V_193 , V_160 ) ;
if ( F_108 ( & V_23 -> V_25 ) )
V_6 -> V_194 = & V_195 ;
V_190 = F_11 ( V_6 -> V_18 ) >> V_23 -> V_25 . V_196 ;
for ( V_45 = 0 ; V_45 < V_190 ; V_45 ++ ) {
V_189 = ( V_45 * V_23 -> V_25 . V_197 ) +
F_109 ( V_198 , V_199 ) ;
while ( V_189 >=
( V_187 + V_188 ) ) {
V_185 += V_186 ;
V_185 = F_110 ( V_160 -> V_200 ,
V_160 -> V_201 , V_185 ) ;
if ( V_185 == - 1 )
return 0 ;
V_186 = F_111 ( V_160 -> V_200 ,
V_160 -> V_201 , V_185 ) ;
ASSERT ( V_186 > 0 ) ;
V_187 = V_185 << V_202 ;
V_188 = V_186 << V_202 ;
V_184 ++ ;
}
if ( V_189 < V_187 )
continue;
ASSERT ( V_132 -> V_143 [ V_184 ] . V_145 != NULL ) ;
ASSERT ( ( V_132 -> V_143 [ V_184 ] . V_146 % V_203 ) == 0 ) ;
ASSERT ( ( V_187 + V_188 ) <=
F_11 ( V_6 -> V_18 ) ) ;
V_191 = V_132 -> V_143 [ V_184 ] . V_145 +
V_189 - V_187 ;
if ( F_33 ( * V_191 == 0 ) ) {
F_112 ( V_23 ,
L_23
L_24 ,
V_132 , V_6 ) ;
F_4 ( L_25 ,
V_121 , V_23 ) ;
return F_34 ( V_16 ) ;
}
V_192 = ( T_15 * ) F_113 ( V_6 ,
V_189 ) ;
* V_192 = * V_191 ;
F_114 ( V_23 , (struct V_204 * )
F_113 ( V_6 , V_45 * V_23 -> V_25 . V_197 ) ) ;
}
return 0 ;
}
static void
F_115 (
struct V_183 * V_23 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
struct V_205 * V_206 = V_6 -> V_15 ;
T_16 V_207 ;
T_17 V_208 ;
T_17 V_209 ;
V_207 = F_30 ( * ( V_81 * ) V_6 -> V_15 ) ;
V_208 = F_116 ( * ( V_210 * ) V_6 -> V_15 ) ;
V_209 = F_116 ( V_206 -> V_211 ) ;
switch ( F_117 ( V_160 ) ) {
case V_212 :
switch ( V_207 ) {
case V_213 :
case V_214 :
case V_215 :
case V_216 :
V_6 -> V_194 = & V_217 ;
break;
case V_218 :
case V_219 :
V_6 -> V_194 = & V_220 ;
break;
case V_221 :
case V_222 :
V_6 -> V_194 = & V_223 ;
break;
default:
F_3 ( V_23 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_224 :
if ( V_207 != V_225 ) {
F_3 ( V_23 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_226 ;
break;
case V_227 :
if ( ! F_108 ( & V_23 -> V_25 ) )
break;
if ( V_207 != V_228 ) {
F_3 ( V_23 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_229 ;
break;
case V_230 :
if ( V_207 != V_231 ) {
F_3 ( V_23 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_232 ;
break;
case V_233 :
case V_234 :
case V_235 :
#ifdef F_118
if ( V_208 != V_236 ) {
F_3 ( V_23 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_237 ;
#else
F_112 ( V_23 ,
L_31 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_238 :
if ( V_208 != V_239 ) {
F_3 ( V_23 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_195 ;
break;
case V_240 :
if ( V_207 != V_241 ) {
F_3 ( V_23 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_242 ;
break;
case V_243 :
if ( V_207 != V_244 &&
V_207 != V_245 ) {
F_3 ( V_23 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_246 ;
break;
case V_247 :
if ( V_207 != V_248 &&
V_207 != V_249 ) {
F_3 ( V_23 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_250 ;
break;
case V_251 :
if ( V_207 != V_252 &&
V_207 != V_253 ) {
F_3 ( V_23 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_254 ;
break;
case V_255 :
if ( V_209 != V_256 &&
V_209 != V_257 ) {
F_3 ( V_23 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_258 ;
break;
case V_259 :
if ( V_209 != V_260 &&
V_209 != V_261 ) {
F_3 ( V_23 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_262 ;
break;
case V_263 :
if ( V_209 != V_264 &&
V_209 != V_265 ) {
F_3 ( V_23 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_266 ;
break;
case V_267 :
if ( V_209 != V_268 &&
V_209 != V_269 ) {
F_3 ( V_23 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_270 ;
break;
case V_271 :
if ( ! F_108 ( & V_23 -> V_25 ) )
break;
if ( V_207 != V_272 ) {
F_3 ( V_23 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_273 ;
break;
case V_274 :
if ( V_207 != V_275 ) {
F_3 ( V_23 , L_42 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_194 = & V_276 ;
break;
default:
F_3 ( V_23 , L_43 ,
F_117 ( V_160 ) ) ;
break;
}
}
STATIC void
F_119 (
struct V_183 * V_23 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_45 ;
int V_185 ;
int V_186 ;
int error ;
F_120 ( V_23 -> V_193 , V_160 ) ;
V_185 = 0 ;
V_45 = 1 ;
while ( 1 ) {
V_185 = F_110 ( V_160 -> V_200 ,
V_160 -> V_201 , V_185 ) ;
if ( V_185 == - 1 )
break;
V_186 = F_111 ( V_160 -> V_200 ,
V_160 -> V_201 , V_185 ) ;
ASSERT ( V_186 > 0 ) ;
ASSERT ( V_132 -> V_143 [ V_45 ] . V_145 != NULL ) ;
ASSERT ( V_132 -> V_143 [ V_45 ] . V_146 % V_203 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_18 ) >=
( ( T_6 ) V_185 << V_202 ) + ( V_186 << V_202 ) ) ;
if ( V_132 -> V_143 [ V_45 ] . V_146 < ( V_186 << V_202 ) )
V_186 = V_132 -> V_143 [ V_45 ] . V_146 >> V_202 ;
error = 0 ;
if ( V_160 -> V_162 &
( V_277 | V_278 | V_279 ) ) {
if ( V_132 -> V_143 [ V_45 ] . V_145 == NULL ) {
F_112 ( V_23 ,
L_44 , V_8 ) ;
goto V_280;
}
if ( V_132 -> V_143 [ V_45 ] . V_146 < sizeof( V_281 ) ) {
F_112 ( V_23 ,
L_45 ,
V_132 -> V_143 [ V_45 ] . V_146 , V_8 ) ;
goto V_280;
}
error = F_121 ( V_23 , V_132 -> V_143 [ V_45 ] . V_145 ,
- 1 , 0 , V_282 ,
L_46 ) ;
if ( error )
goto V_280;
}
memcpy ( F_113 ( V_6 ,
( T_6 ) V_185 << V_202 ) ,
V_132 -> V_143 [ V_45 ] . V_145 ,
V_186 << V_202 ) ;
V_280:
V_45 ++ ;
V_185 += V_186 ;
}
ASSERT ( V_45 == V_132 -> V_149 ) ;
if ( F_108 ( & V_23 -> V_25 ) )
F_115 ( V_23 , V_6 , V_160 ) ;
}
int
F_121 (
struct V_183 * V_23 ,
V_281 * V_283 ,
T_18 V_284 ,
T_6 type ,
T_6 V_181 ,
char * V_285 )
{
T_19 * V_286 = ( T_19 * ) V_283 ;
int V_287 = 0 ;
if ( V_283 -> V_288 != F_122 ( V_236 ) ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_47 ,
V_285 , V_284 , F_116 ( V_283 -> V_288 ) , V_236 ) ;
V_287 ++ ;
}
if ( V_283 -> V_289 != V_290 ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_48 ,
V_285 , V_284 , V_283 -> V_289 , V_290 ) ;
V_287 ++ ;
}
if ( V_283 -> V_291 != V_292 &&
V_283 -> V_291 != V_293 &&
V_283 -> V_291 != V_294 ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_49 ,
V_285 , V_284 , V_283 -> V_291 ) ;
V_287 ++ ;
}
if ( V_284 != - 1 && V_284 != F_30 ( V_283 -> V_295 ) ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_50
L_51 ,
V_285 , V_283 , V_284 , F_30 ( V_283 -> V_295 ) ) ;
V_287 ++ ;
}
if ( ! V_287 && V_283 -> V_295 ) {
if ( V_283 -> V_296 &&
F_56 ( V_283 -> V_297 ) >
F_56 ( V_283 -> V_296 ) ) {
if ( ! V_283 -> V_298 ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_52 ,
V_285 , ( int ) F_30 ( V_283 -> V_295 ) , V_283 ) ;
V_287 ++ ;
}
}
if ( V_283 -> V_299 &&
F_56 ( V_283 -> V_300 ) >
F_56 ( V_283 -> V_299 ) ) {
if ( ! V_283 -> V_301 ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_53 ,
V_285 , ( int ) F_30 ( V_283 -> V_295 ) , V_283 ) ;
V_287 ++ ;
}
}
if ( V_283 -> V_302 &&
F_56 ( V_283 -> V_303 ) >
F_56 ( V_283 -> V_302 ) ) {
if ( ! V_283 -> V_304 ) {
if ( V_181 & V_282 )
F_112 ( V_23 ,
L_54 ,
V_285 , ( int ) F_30 ( V_283 -> V_295 ) , V_283 ) ;
V_287 ++ ;
}
}
}
if ( ! V_287 || ! ( V_181 & V_305 ) )
return V_287 ;
if ( V_181 & V_282 )
F_123 ( V_23 , L_55 , V_284 ) ;
ASSERT ( V_284 != - 1 ) ;
ASSERT ( V_181 & V_305 ) ;
memset ( V_286 , 0 , sizeof( T_19 ) ) ;
V_286 -> V_306 . V_288 = F_122 ( V_236 ) ;
V_286 -> V_306 . V_289 = V_290 ;
V_286 -> V_306 . V_291 = type ;
V_286 -> V_306 . V_295 = F_32 ( V_284 ) ;
if ( F_108 ( & V_23 -> V_25 ) ) {
F_124 ( & V_286 -> V_307 , & V_23 -> V_25 . V_26 ) ;
F_125 ( ( char * ) V_286 , sizeof( struct V_308 ) ,
V_309 ) ;
}
return V_287 ;
}
STATIC void
F_126 (
struct V_183 * V_23 ,
struct V_1 * log ,
struct V_170 * V_132 ,
struct V_5 * V_6 ,
struct V_310 * V_160 )
{
T_6 type ;
F_127 ( log , V_160 ) ;
if ( V_23 -> V_311 == 0 ) {
return;
}
type = 0 ;
if ( V_160 -> V_162 & V_277 )
type |= V_292 ;
if ( V_160 -> V_162 & V_278 )
type |= V_293 ;
if ( V_160 -> V_162 & V_279 )
type |= V_294 ;
if ( log -> V_312 & type )
return;
F_119 ( V_23 , V_132 , V_6 , V_160 ) ;
}
STATIC int
F_128 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_170 * V_132 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_313 ;
if ( F_103 ( log , V_160 -> V_174 ,
V_160 -> V_177 , V_160 -> V_162 ) ) {
F_129 ( log , V_160 ) ;
return 0 ;
}
F_130 ( log , V_160 ) ;
V_313 = 0 ;
if ( V_160 -> V_162 & V_164 )
V_313 |= V_314 ;
V_6 = F_131 ( V_23 -> V_315 , V_160 -> V_174 , V_160 -> V_177 ,
V_313 , NULL ) ;
if ( ! V_6 )
return F_34 ( V_49 ) ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_56 ) ;
F_27 ( V_6 ) ;
return error ;
}
if ( V_160 -> V_162 & V_164 ) {
error = F_106 ( V_23 , V_132 , V_6 , V_160 ) ;
} else if ( V_160 -> V_162 &
( V_277 | V_278 | V_279 ) ) {
F_126 ( V_23 , log , V_132 , V_6 , V_160 ) ;
} else {
F_119 ( V_23 , V_132 , V_6 , V_160 ) ;
}
if ( error )
return F_34 ( error ) ;
if ( V_239 ==
F_116 ( * ( ( V_210 * ) F_113 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_132 ( log -> V_7 -> V_25 . V_316 ,
( T_16 ) F_133 ( log -> V_7 ) ) ) ) {
F_134 ( V_6 ) ;
error = F_26 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_135 ( V_6 , V_157 ) ;
}
F_27 ( V_6 ) ;
return error ;
}
STATIC int
F_136 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_170 * V_132 )
{
T_12 * V_147 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_198 * V_317 ;
int V_136 ;
T_2 V_318 ;
T_2 V_319 ;
int error ;
int V_320 ;
T_6 V_321 ;
T_20 * V_322 ;
T_6 V_323 ;
int V_324 = 0 ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( T_12 ) ) {
V_147 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_147 = F_84 ( sizeof( T_12 ) , V_127 ) ;
V_324 = 1 ;
error = F_137 ( & V_132 -> V_143 [ 0 ] , V_147 ) ;
if ( error )
goto error;
}
if ( F_103 ( log , V_147 -> V_325 ,
V_147 -> V_326 , 0 ) ) {
error = 0 ;
F_138 ( log , V_147 ) ;
goto error;
}
F_139 ( log , V_147 ) ;
V_6 = F_131 ( V_23 -> V_315 , V_147 -> V_325 , V_147 -> V_326 , 0 ,
& V_195 ) ;
if ( ! V_6 ) {
error = V_49 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_57 ) ;
F_27 ( V_6 ) ;
goto error;
}
ASSERT ( V_147 -> V_327 & V_328 ) ;
V_317 = ( V_198 * ) F_113 ( V_6 , V_147 -> V_329 ) ;
if ( F_33 ( V_317 -> V_330 != F_122 ( V_239 ) ) ) {
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_58 ,
V_8 , V_317 , V_6 , V_147 -> V_331 ) ;
F_4 ( L_59 ,
V_121 , V_23 ) ;
error = V_16 ;
goto error;
}
V_322 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( F_33 ( V_322 -> V_330 != V_239 ) ) {
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_60 ,
V_8 , V_132 , V_147 -> V_331 ) ;
F_4 ( L_61 ,
V_121 , V_23 ) ;
error = V_16 ;
goto error;
}
if ( V_322 -> V_332 < F_116 ( V_317 -> V_332 ) ) {
if ( F_116 ( V_317 -> V_332 ) == V_333 &&
V_322 -> V_332 < ( V_333 >> 1 ) ) {
} else {
F_27 ( V_6 ) ;
F_140 ( log , V_147 ) ;
error = 0 ;
goto error;
}
}
V_322 -> V_332 = 0 ;
if ( F_33 ( F_141 ( V_322 -> V_334 ) ) ) {
if ( ( V_322 -> V_335 != V_336 ) &&
( V_322 -> V_335 != V_337 ) ) {
F_142 ( L_62 ,
V_121 , V_23 , V_322 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_63
L_64 ,
V_8 , V_132 , V_317 , V_6 , V_147 -> V_331 ) ;
error = V_16 ;
goto error;
}
} else if ( F_33 ( F_143 ( V_322 -> V_334 ) ) ) {
if ( ( V_322 -> V_335 != V_336 ) &&
( V_322 -> V_335 != V_337 ) &&
( V_322 -> V_335 != V_338 ) ) {
F_142 ( L_65 ,
V_121 , V_23 , V_322 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_66
L_64 ,
V_8 , V_132 , V_317 , V_6 , V_147 -> V_331 ) ;
error = V_16 ;
goto error;
}
}
if ( F_33 ( V_322 -> V_339 + V_322 -> V_340 > V_322 -> V_341 ) ) {
F_142 ( L_67 ,
V_121 , V_23 , V_322 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_68
L_69 ,
V_8 , V_132 , V_317 , V_6 , V_147 -> V_331 ,
V_322 -> V_339 + V_322 -> V_340 ,
V_322 -> V_341 ) ;
error = V_16 ;
goto error;
}
if ( F_33 ( V_322 -> V_342 > V_23 -> V_25 . V_197 ) ) {
F_142 ( L_70 ,
V_121 , V_23 , V_322 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_68
L_71 , V_8 ,
V_132 , V_317 , V_6 , V_147 -> V_331 , V_322 -> V_342 ) ;
error = V_16 ;
goto error;
}
V_323 = F_144 ( V_322 -> V_343 ) ;
if ( F_33 ( V_132 -> V_143 [ 1 ] . V_146 > V_323 ) ) {
F_142 ( L_72 ,
V_121 , V_23 , V_322 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_73 ,
V_8 , V_132 -> V_143 [ 1 ] . V_146 , V_132 ) ;
error = V_16 ;
goto error;
}
F_145 ( V_317 , V_322 ) ;
if ( V_132 -> V_143 [ 1 ] . V_146 > V_323 ) {
memcpy ( ( char * ) V_317 + V_323 ,
V_132 -> V_143 [ 1 ] . V_145 + V_323 ,
V_132 -> V_143 [ 1 ] . V_146 - V_323 ) ;
}
V_321 = V_147 -> V_327 ;
switch ( V_321 & ( V_344 | V_345 ) ) {
case V_344 :
F_146 ( V_317 , V_147 -> V_346 . V_347 ) ;
break;
case V_345 :
memcpy ( F_147 ( V_317 ) ,
& V_147 -> V_346 . V_348 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_147 -> V_150 == 2 )
goto V_349;
V_136 = V_132 -> V_143 [ 2 ] . V_146 ;
V_318 = V_132 -> V_143 [ 2 ] . V_145 ;
ASSERT ( V_147 -> V_150 <= 4 ) ;
ASSERT ( ( V_147 -> V_150 == 3 ) || ( V_321 & V_350 ) ) ;
ASSERT ( ! ( V_321 & V_351 ) ||
( V_136 == V_147 -> V_352 ) ) ;
switch ( V_321 & V_351 ) {
case V_353 :
case V_354 :
memcpy ( F_147 ( V_317 ) , V_318 , V_136 ) ;
break;
case V_355 :
F_148 ( V_23 , (struct V_356 * ) V_318 , V_136 ,
( V_357 * ) F_147 ( V_317 ) ,
F_149 ( V_317 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_321 & V_351 ) == 0 ) ;
break;
}
if ( V_147 -> V_327 & V_350 ) {
if ( V_147 -> V_327 & V_351 ) {
V_320 = 3 ;
} else {
V_320 = 2 ;
}
V_136 = V_132 -> V_143 [ V_320 ] . V_146 ;
V_318 = V_132 -> V_143 [ V_320 ] . V_145 ;
ASSERT ( V_136 == V_147 -> V_358 ) ;
switch ( V_147 -> V_327 & V_350 ) {
case V_359 :
case V_360 :
V_319 = F_150 ( V_317 ) ;
ASSERT ( V_136 <= F_151 ( V_317 , V_23 ) ) ;
memcpy ( V_319 , V_318 , V_136 ) ;
break;
case V_361 :
V_319 = F_150 ( V_317 ) ;
F_148 ( V_23 , (struct V_356 * ) V_318 ,
V_136 , ( V_357 * ) V_319 ,
F_151 ( V_317 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_74 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
error = V_58 ;
goto error;
}
}
V_349:
F_114 ( log -> V_7 , V_317 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_135 ( V_6 , V_157 ) ;
F_27 ( V_6 ) ;
error:
if ( V_324 )
F_105 ( V_147 ) ;
return F_34 ( error ) ;
}
STATIC int
F_152 (
struct V_1 * log ,
struct V_170 * V_132 )
{
T_21 * V_362 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_362 ) ;
if ( V_362 -> V_363 & V_364 )
log -> V_312 |= V_292 ;
if ( V_362 -> V_363 & V_365 )
log -> V_312 |= V_293 ;
if ( V_362 -> V_363 & V_366 )
log -> V_312 |= V_294 ;
return ( 0 ) ;
}
STATIC int
F_153 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_170 * V_132 )
{
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_367 * V_283 , * V_368 ;
int error ;
T_22 * V_369 ;
T_6 type ;
if ( V_23 -> V_311 == 0 )
return ( 0 ) ;
V_368 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_368 == NULL ) {
F_112 ( log -> V_7 , L_75 , V_8 ) ;
return F_34 ( V_58 ) ;
}
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( V_281 ) ) {
F_112 ( log -> V_7 , L_76 ,
V_132 -> V_143 [ 1 ] . V_146 , V_8 ) ;
return F_34 ( V_58 ) ;
}
type = V_368 -> V_291 & ( V_292 | V_293 | V_294 ) ;
ASSERT ( type ) ;
if ( log -> V_312 & type )
return ( 0 ) ;
V_369 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_369 ) ;
error = F_121 ( V_23 , V_368 , V_369 -> V_370 , 0 , V_282 ,
L_77 ) ;
if ( error )
return F_34 ( V_58 ) ;
ASSERT ( V_369 -> V_371 == 1 ) ;
error = F_154 ( V_23 , NULL , V_23 -> V_315 , V_369 -> V_372 ,
F_155 ( V_23 , V_369 -> V_371 ) , 0 , & V_6 ,
NULL ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_283 = ( V_281 * ) F_113 ( V_6 , V_369 -> V_373 ) ;
error = F_121 ( V_23 , V_283 , V_369 -> V_370 , 0 , V_282 ,
L_78 ) ;
if ( error ) {
F_27 ( V_6 ) ;
return F_34 ( V_58 ) ;
}
memcpy ( V_283 , V_368 , V_132 -> V_143 [ 1 ] . V_146 ) ;
if ( F_108 ( & V_23 -> V_25 ) ) {
F_125 ( ( char * ) V_283 , sizeof( struct V_308 ) ,
V_309 ) ;
}
ASSERT ( V_369 -> V_374 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_135 ( V_6 , V_157 ) ;
F_27 ( V_6 ) ;
return ( 0 ) ;
}
STATIC int
F_156 (
struct V_1 * log ,
struct V_170 * V_132 ,
T_8 V_126 )
{
int error ;
T_4 * V_23 = log -> V_7 ;
T_23 * V_375 ;
T_24 * V_376 ;
V_376 = V_132 -> V_143 [ 0 ] . V_145 ;
V_375 = F_157 ( V_23 , V_376 -> V_377 ) ;
if ( ( error = F_158 ( & ( V_132 -> V_143 [ 0 ] ) ,
& ( V_375 -> V_378 ) ) ) ) {
F_159 ( V_375 ) ;
return error ;
}
F_160 ( & V_375 -> V_379 , V_376 -> V_377 ) ;
F_161 ( & log -> V_380 -> V_381 ) ;
F_162 ( log -> V_380 , & V_375 -> V_382 , V_126 ) ;
return 0 ;
}
STATIC int
F_163 (
struct V_1 * log ,
struct V_170 * V_132 )
{
T_25 * V_383 ;
T_23 * V_375 = NULL ;
T_26 * V_384 ;
T_27 V_385 ;
struct V_386 V_387 ;
struct V_388 * V_389 = log -> V_380 ;
V_383 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( ( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_390 ) +
( ( V_383 -> V_391 - 1 ) * sizeof( V_392 ) ) ) ) ||
( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_393 ) +
( ( V_383 -> V_391 - 1 ) * sizeof( V_394 ) ) ) ) ) ;
V_385 = V_383 -> V_395 ;
F_161 ( & V_389 -> V_381 ) ;
V_384 = F_164 ( V_389 , & V_387 , 0 ) ;
while ( V_384 != NULL ) {
if ( V_384 -> V_396 == V_169 ) {
V_375 = ( T_23 * ) V_384 ;
if ( V_375 -> V_378 . V_385 == V_385 ) {
F_165 ( V_389 , V_384 ,
V_397 ) ;
F_159 ( V_375 ) ;
F_161 ( & V_389 -> V_381 ) ;
break;
}
}
V_384 = F_166 ( V_389 , & V_387 ) ;
}
F_167 ( V_389 , & V_387 ) ;
F_168 ( & V_389 -> V_381 ) ;
return 0 ;
}
STATIC void
F_169 (
struct V_134 * V_124 )
{
T_11 * V_132 , * V_154 ;
int V_45 ;
F_89 (item, n, &trans->r_itemq, ri_list) {
F_104 ( & V_132 -> V_133 ) ;
for ( V_45 = 0 ; V_45 < V_132 -> V_144 ; V_45 ++ )
F_105 ( V_132 -> V_143 [ V_45 ] . V_145 ) ;
F_105 ( V_132 -> V_143 ) ;
F_105 ( V_132 ) ;
}
F_105 ( V_124 ) ;
}
STATIC int
F_170 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_170 * V_132 )
{
F_171 ( log , V_124 , V_132 , V_398 ) ;
switch ( F_90 ( V_132 ) ) {
case V_161 :
return F_97 ( log , V_132 ) ;
case V_167 :
return F_152 ( log , V_132 ) ;
case V_165 :
case V_169 :
case V_168 :
case V_166 :
return 0 ;
default:
F_3 ( log -> V_7 , L_79 ,
V_8 , F_90 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_172 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_170 * V_132 )
{
F_171 ( log , V_124 , V_132 , V_399 ) ;
switch ( F_90 ( V_132 ) ) {
case V_161 :
return F_128 ( log , V_157 , V_132 ) ;
case V_165 :
return F_136 ( log , V_157 , V_132 ) ;
case V_169 :
return F_156 ( log , V_132 , V_124 -> V_128 ) ;
case V_168 :
return F_163 ( log , V_132 ) ;
case V_166 :
return F_153 ( log , V_157 , V_132 ) ;
case V_167 :
return 0 ;
default:
F_3 ( log -> V_7 , L_79 ,
V_8 , F_90 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_173 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
int error = 0 , V_22 ;
T_11 * V_132 ;
F_87 ( V_157 ) ;
F_174 ( & V_124 -> V_130 ) ;
error = F_86 ( log , V_124 , V_153 ) ;
if ( error )
return error ;
F_100 (item, &trans->r_itemq, ri_list) {
switch ( V_153 ) {
case V_398 :
error = F_170 ( log , V_124 , V_132 ) ;
break;
case V_399 :
error = F_172 ( log , V_124 ,
& V_157 , V_132 ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
F_169 ( V_124 ) ;
V_51:
V_22 = F_175 ( & V_157 ) ;
return error ? error : V_22 ;
}
STATIC int
F_176 (
struct V_1 * log ,
struct V_134 * V_124 )
{
F_3 ( log -> V_7 , L_80 , V_8 ) ;
return 0 ;
}
STATIC int
F_177 (
struct V_1 * log ,
struct V_122 V_400 [] ,
struct V_401 * V_73 ,
T_2 V_135 ,
int V_153 )
{
T_2 V_402 ;
int V_403 ;
T_7 * V_404 ;
T_9 * V_124 ;
T_10 V_123 ;
int error ;
unsigned long V_405 ;
T_6 V_181 ;
V_402 = V_135 + F_30 ( V_73 -> V_61 ) ;
V_403 = F_30 ( V_73 -> V_95 ) ;
if ( F_31 ( log -> V_7 , V_73 ) )
return ( F_34 ( V_58 ) ) ;
while ( ( V_135 < V_402 ) && V_403 ) {
ASSERT ( V_135 + sizeof( T_7 ) <= V_402 ) ;
V_404 = ( T_7 * ) V_135 ;
V_135 += sizeof( T_7 ) ;
if ( V_404 -> V_406 != V_407 &&
V_404 -> V_406 != V_408 ) {
F_3 ( log -> V_7 , L_81 ,
V_8 , V_404 -> V_406 ) ;
ASSERT ( 0 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_123 = F_30 ( V_404 -> V_409 ) ;
V_405 = F_178 ( V_123 ) ;
V_124 = F_69 ( & V_400 [ V_405 ] , V_123 ) ;
if ( V_124 == NULL ) {
if ( V_404 -> V_96 & V_410 )
F_71 ( & V_400 [ V_405 ] , V_123 ,
F_56 ( V_73 -> V_89 ) ) ;
} else {
if ( V_135 + F_30 ( V_404 -> V_411 ) > V_402 ) {
F_3 ( log -> V_7 , L_82 ,
V_8 , F_30 ( V_404 -> V_411 ) ) ;
F_179 ( 1 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_181 = V_404 -> V_96 & ~ V_412 ;
if ( V_181 & V_413 )
V_181 &= ~ V_414 ;
switch ( V_181 ) {
case V_415 :
error = F_173 ( log ,
V_124 , V_153 ) ;
break;
case V_97 :
error = F_176 ( log , V_124 ) ;
break;
case V_413 :
error = F_78 ( log ,
V_124 , V_135 ,
F_30 ( V_404 -> V_411 ) ) ;
break;
case V_410 :
F_3 ( log -> V_7 , L_83 ,
V_8 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
case 0 :
case V_414 :
error = F_83 ( log , V_124 ,
V_135 , F_30 ( V_404 -> V_411 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_84 ,
V_8 , V_181 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
}
if ( error )
return error ;
}
V_135 += F_30 ( V_404 -> V_411 ) ;
V_403 -- ;
}
return 0 ;
}
STATIC int
F_180 (
T_4 * V_23 ,
T_23 * V_375 )
{
T_28 * V_416 ;
T_29 * V_417 ;
int V_45 ;
int error = 0 ;
T_30 * V_418 ;
T_31 V_419 ;
ASSERT ( ! F_181 ( V_420 , & V_375 -> V_421 ) ) ;
for ( V_45 = 0 ; V_45 < V_375 -> V_378 . V_377 ; V_45 ++ ) {
V_418 = & ( V_375 -> V_378 . V_422 [ V_45 ] ) ;
V_419 = F_182 ( V_23 ,
F_183 ( V_23 , V_418 -> V_423 ) ) ;
if ( ( V_419 == 0 ) ||
( V_418 -> V_424 == 0 ) ||
( V_419 >= V_23 -> V_25 . V_425 ) ||
( V_418 -> V_424 >= V_23 -> V_25 . V_426 ) ) {
F_184 ( V_420 , & V_375 -> V_421 ) ;
F_185 ( V_375 , V_375 -> V_378 . V_377 ) ;
return F_34 ( V_58 ) ;
}
}
V_417 = F_186 ( V_23 , 0 ) ;
error = F_187 ( V_417 , 0 , F_188 ( V_23 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_427;
V_416 = F_189 ( V_417 , V_375 , V_375 -> V_378 . V_377 ) ;
for ( V_45 = 0 ; V_45 < V_375 -> V_378 . V_377 ; V_45 ++ ) {
V_418 = & ( V_375 -> V_378 . V_422 [ V_45 ] ) ;
error = F_190 ( V_417 , V_418 -> V_423 , V_418 -> V_424 ) ;
if ( error )
goto V_427;
F_191 ( V_417 , V_416 , V_418 -> V_423 ,
V_418 -> V_424 ) ;
}
F_184 ( V_420 , & V_375 -> V_421 ) ;
error = F_192 ( V_417 , 0 ) ;
return error ;
V_427:
F_193 ( V_417 , V_428 ) ;
return error ;
}
STATIC int
F_194 (
struct V_1 * log )
{
T_26 * V_384 ;
T_23 * V_375 ;
int error = 0 ;
struct V_386 V_387 ;
struct V_388 * V_389 ;
V_389 = log -> V_380 ;
F_161 ( & V_389 -> V_381 ) ;
V_384 = F_164 ( V_389 , & V_387 , 0 ) ;
while ( V_384 != NULL ) {
if ( V_384 -> V_396 != V_169 ) {
#ifdef F_195
for (; V_384 ; V_384 = F_166 ( V_389 , & V_387 ) )
ASSERT ( V_384 -> V_396 != V_169 ) ;
#endif
break;
}
V_375 = ( T_23 * ) V_384 ;
if ( F_181 ( V_420 , & V_375 -> V_421 ) ) {
V_384 = F_166 ( V_389 , & V_387 ) ;
continue;
}
F_168 ( & V_389 -> V_381 ) ;
error = F_180 ( log -> V_7 , V_375 ) ;
F_161 ( & V_389 -> V_381 ) ;
if ( error )
goto V_51;
V_384 = F_166 ( V_389 , & V_387 ) ;
}
V_51:
F_167 ( V_389 , & V_387 ) ;
F_168 ( & V_389 -> V_381 ) ;
return error ;
}
STATIC void
F_196 (
T_4 * V_23 ,
T_32 V_429 ,
int V_171 )
{
T_29 * V_417 ;
T_33 * V_430 ;
T_1 * V_431 ;
int V_13 ;
int error ;
V_417 = F_186 ( V_23 , V_432 ) ;
error = F_187 ( V_417 , 0 , F_197 ( V_23 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_433;
error = F_198 ( V_23 , V_417 , V_429 , & V_431 ) ;
if ( error )
goto V_433;
V_430 = F_199 ( V_431 ) ;
V_430 -> V_434 [ V_171 ] = F_32 ( V_435 ) ;
V_13 = F_109 ( T_33 , V_434 ) +
( sizeof( T_15 ) * V_171 ) ;
F_200 ( V_417 , V_431 , V_13 ,
( V_13 + sizeof( T_15 ) - 1 ) ) ;
error = F_192 ( V_417 , 0 ) ;
if ( error )
goto V_436;
return;
V_433:
F_193 ( V_417 , V_428 ) ;
V_436:
F_3 ( V_23 , L_85 , V_8 , V_429 ) ;
return;
}
STATIC T_15
F_201 (
struct V_183 * V_23 ,
T_32 V_429 ,
T_15 V_437 ,
int V_171 )
{
struct V_5 * V_438 ;
struct V_204 * V_317 ;
struct V_439 * V_440 ;
T_34 V_441 ;
int error ;
V_441 = F_202 ( V_23 , V_429 , V_437 ) ;
error = F_203 ( V_23 , NULL , V_441 , 0 , 0 , & V_440 ) ;
if ( error )
goto V_442;
error = F_204 ( V_23 , NULL , & V_440 -> V_443 , & V_317 , & V_438 , 0 , 0 ) ;
if ( error )
goto V_444;
ASSERT ( V_440 -> V_445 . V_446 == 0 ) ;
ASSERT ( V_440 -> V_445 . V_334 != 0 ) ;
V_437 = F_30 ( V_317 -> V_199 ) ;
F_27 ( V_438 ) ;
V_440 -> V_445 . V_447 = 0 ;
F_205 ( V_440 ) ;
return V_437 ;
V_444:
F_205 ( V_440 ) ;
V_442:
F_196 ( V_23 , V_429 , V_171 ) ;
return V_435 ;
}
STATIC void
F_206 (
struct V_1 * log )
{
T_4 * V_23 ;
T_32 V_429 ;
T_33 * V_430 ;
T_1 * V_431 ;
T_15 V_437 ;
int V_171 ;
int error ;
T_6 V_448 ;
V_23 = log -> V_7 ;
V_448 = V_23 -> V_449 ;
V_23 -> V_449 = 0 ;
for ( V_429 = 0 ; V_429 < V_23 -> V_25 . V_450 ; V_429 ++ ) {
error = F_198 ( V_23 , NULL , V_429 , & V_431 ) ;
if ( error ) {
continue;
}
V_430 = F_199 ( V_431 ) ;
F_7 ( V_431 ) ;
for ( V_171 = 0 ; V_171 < V_451 ; V_171 ++ ) {
V_437 = F_30 ( V_430 -> V_434 [ V_171 ] ) ;
while ( V_437 != V_435 ) {
V_437 = F_201 ( V_23 ,
V_429 , V_437 , V_171 ) ;
}
}
F_207 ( V_431 ) ;
}
V_23 -> V_449 = V_448 ;
}
STATIC int
F_208 (
struct V_401 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
T_35 V_452 ;
V_452 = F_209 ( log , V_73 , V_135 , F_30 ( V_73 -> V_61 ) ) ;
if ( V_452 != V_73 -> V_453 ) {
if ( V_73 -> V_453 || F_108 ( & log -> V_7 -> V_25 ) ) {
F_112 ( log -> V_7 ,
L_86 ,
F_210 ( V_73 -> V_453 ) ,
F_210 ( V_452 ) ) ;
F_211 ( V_135 , 32 ) ;
}
if ( F_108 ( & log -> V_7 -> V_25 ) )
return V_16 ;
}
return 0 ;
}
STATIC int
F_212 (
struct V_401 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
int V_45 , V_46 , V_454 ;
int error ;
error = F_208 ( V_73 , V_135 , log ) ;
if ( error )
return error ;
for ( V_45 = 0 ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_81 * ) V_135 = * ( V_81 * ) & V_73 -> V_455 [ V_45 ] ;
V_135 += V_52 ;
}
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
T_36 * V_456 = ( T_36 * ) V_73 ;
for ( ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_454 = V_45 % ( V_60 / V_52 ) ;
* ( V_81 * ) V_135 = V_456 [ V_46 ] . V_457 . V_458 [ V_454 ] ;
V_135 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_213 (
struct V_1 * log ,
struct V_401 * V_73 ,
T_3 V_180 )
{
int V_459 ;
if ( F_33 ( V_73 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_87 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 (
( ! V_73 -> V_93 ||
( F_30 ( V_73 -> V_93 ) & ( ~ V_460 ) ) ) ) ) {
F_3 ( log -> V_7 , L_88 ,
V_8 , F_30 ( V_73 -> V_93 ) ) ;
return F_34 ( V_58 ) ;
}
V_459 = F_30 ( V_73 -> V_61 ) ;
if ( F_33 ( V_459 <= 0 || V_459 > V_70 ) ) {
F_4 ( L_89 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 ( V_180 > log -> V_3 || V_180 > V_70 ) ) {
F_4 ( L_90 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
return 0 ;
}
STATIC int
F_214 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_153 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_461 , * V_462 ;
int error = 0 , V_59 ;
int V_463 , V_464 ;
int V_79 , V_465 , V_466 ;
struct V_122 V_400 [ V_467 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
V_461 = F_2 ( log , 1 ) ;
if ( ! V_461 )
return V_49 ;
error = F_19 ( log , V_72 , 1 , V_461 , & V_13 ) ;
if ( error )
goto V_468;
V_73 = ( T_5 * ) V_13 ;
error = F_213 ( log , V_73 , V_72 ) ;
if ( error )
goto V_468;
V_59 = F_30 ( V_73 -> V_59 ) ;
if ( ( F_30 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_461 ) ;
V_461 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_461 = F_2 ( log , 1 ) ;
V_59 = V_469 ;
}
if ( ! V_461 )
return V_49 ;
V_462 = F_2 ( log , F_49 ( V_59 ) ) ;
if ( ! V_462 ) {
F_8 ( V_461 ) ;
return V_49 ;
}
memset ( V_400 , 0 , sizeof( V_400 ) ) ;
if ( V_72 <= V_63 ) {
for ( V_12 = V_72 ; V_12 < V_63 ; ) {
error = F_19 ( log , V_12 , V_79 , V_461 , & V_13 ) ;
if ( error )
goto V_470;
V_73 = ( T_5 * ) V_13 ;
error = F_213 ( log , V_73 , V_12 ) ;
if ( error )
goto V_470;
V_463 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_463 , V_462 ,
& V_13 ) ;
if ( error )
goto V_470;
error = F_212 ( V_73 , V_13 , log ) ;
if ( error )
goto V_470;
error = F_177 ( log ,
V_400 , V_73 , V_13 , V_153 ) ;
if ( error )
goto V_470;
V_12 += V_463 + V_79 ;
}
} else {
V_12 = V_72 ;
while ( V_12 < log -> V_3 ) {
V_13 = V_461 -> V_15 ;
V_465 = 0 ;
V_466 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_79 , V_461 ,
& V_13 ) ;
if ( error )
goto V_470;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_465 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_465 > 0 ) ;
error = F_19 ( log , V_12 ,
V_465 , V_461 ,
& V_13 ) ;
if ( error )
goto V_470;
}
V_466 = V_79 - V_465 ;
error = F_20 ( log , 0 ,
V_466 , V_461 ,
V_13 + F_11 ( V_465 ) ) ;
if ( error )
goto V_470;
}
V_73 = ( T_5 * ) V_13 ;
error = F_213 ( log , V_73 ,
V_465 ? V_12 : 0 ) ;
if ( error )
goto V_470;
V_463 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_463 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_463 , V_462 ,
& V_13 ) ;
if ( error )
goto V_470;
} else {
V_13 = V_462 -> V_15 ;
V_464 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_466 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_464 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_464 > 0 ) ;
error = F_19 ( log , V_12 ,
V_464 , V_462 ,
& V_13 ) ;
if ( error )
goto V_470;
}
error = F_20 ( log , 0 ,
V_463 - V_464 , V_462 ,
V_13 + F_11 ( V_464 ) ) ;
if ( error )
goto V_470;
}
error = F_212 ( V_73 , V_13 , log ) ;
if ( error )
goto V_470;
error = F_177 ( log , V_400 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_470;
V_12 += V_463 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_79 , V_461 , & V_13 ) ;
if ( error )
goto V_470;
V_73 = ( T_5 * ) V_13 ;
error = F_213 ( log , V_73 , V_12 ) ;
if ( error )
goto V_470;
V_463 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_463 , V_462 ,
& V_13 ) ;
if ( error )
goto V_470;
error = F_212 ( V_73 , V_13 , log ) ;
if ( error )
goto V_470;
error = F_177 ( log , V_400 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_470;
V_12 += V_463 + V_79 ;
}
}
V_470:
F_8 ( V_462 ) ;
V_468:
F_8 ( V_461 ) ;
return error ;
}
STATIC int
F_215 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_182 = F_72 ( V_471 *
sizeof( struct V_131 ) ,
V_127 ) ;
for ( V_45 = 0 ; V_45 < V_471 ; V_45 ++ )
F_73 ( & log -> V_182 [ V_45 ] ) ;
error = F_214 ( log , V_63 , V_72 ,
V_398 ) ;
if ( error != 0 ) {
F_105 ( log -> V_182 ) ;
log -> V_182 = NULL ;
return error ;
}
error = F_214 ( log , V_63 , V_72 ,
V_399 ) ;
#ifdef F_195
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_471 ; V_45 ++ )
ASSERT ( F_79 ( & log -> V_182 [ V_45 ] ) ) ;
}
#endif
F_105 ( log -> V_182 ) ;
log -> V_182 = NULL ;
return error ;
}
STATIC int
F_216 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_37 * V_472 ;
error = F_215 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_217 ( log -> V_7 ) ) {
return ( V_58 ) ;
}
F_218 ( log -> V_7 ) ;
V_6 = F_219 ( log -> V_7 , 0 ) ;
F_220 ( V_6 ) ;
ASSERT ( ! ( F_221 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_222 ( V_6 ) ;
V_6 -> V_194 = & V_276 ;
F_16 ( log -> V_7 , V_6 ) ;
error = F_17 ( V_6 ) ;
if ( error ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
return error ;
}
V_472 = & log -> V_7 -> V_25 ;
F_223 ( V_472 , F_224 ( V_6 ) ) ;
ASSERT ( V_472 -> V_473 == V_275 ) ;
ASSERT ( F_225 ( V_472 ) ) ;
F_27 ( V_6 ) ;
F_226 ( log -> V_7 ) ;
F_227 ( log ) ;
log -> V_474 &= ~ V_475 ;
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
if ( ( error = F_228 ( log -> V_7 , L_91 ) ) ) {
return error ;
}
if ( F_229 ( & log -> V_7 -> V_25 ) == V_476 &&
F_230 ( & log -> V_7 -> V_25 ,
V_477 ) ) {
F_3 ( log -> V_7 ,
L_92
L_93
L_94 ,
( log -> V_7 -> V_25 . V_478 &
V_477 ) ) ;
return V_102 ;
}
F_123 ( log -> V_7 , L_95 ,
log -> V_7 -> V_479 ? log -> V_7 -> V_479
: L_96 ) ;
error = F_216 ( log , V_63 , V_72 ) ;
log -> V_474 |= V_480 ;
}
return error ;
}
int
F_231 (
struct V_1 * log )
{
if ( log -> V_474 & V_480 ) {
int error ;
error = F_194 ( log ) ;
if ( error ) {
F_112 ( log -> V_7 , L_97 ) ;
return error ;
}
F_232 ( log -> V_7 , V_481 ) ;
F_206 ( log ) ;
F_227 ( log ) ;
F_123 ( log -> V_7 , L_98 ,
log -> V_7 -> V_479 ? log -> V_7 -> V_479
: L_96 ) ;
log -> V_474 &= ~ V_480 ;
} else {
F_233 ( log -> V_7 , L_99 ) ;
}
return 0 ;
}
void
F_227 (
struct V_1 * log )
{
T_4 * V_23 ;
T_38 * V_482 ;
T_1 * V_483 ;
T_1 * V_431 ;
T_32 V_429 ;
T_27 V_484 ;
T_27 V_485 ;
T_27 V_486 ;
int error ;
V_23 = log -> V_7 ;
V_484 = 0LL ;
V_485 = 0LL ;
V_486 = 0LL ;
for ( V_429 = 0 ; V_429 < V_23 -> V_25 . V_450 ; V_429 ++ ) {
error = F_234 ( V_23 , NULL , V_429 , 0 , & V_483 ) ;
if ( error ) {
F_112 ( V_23 , L_100 ,
V_8 , V_429 , error ) ;
} else {
V_482 = F_235 ( V_483 ) ;
V_484 += F_30 ( V_482 -> V_487 ) +
F_30 ( V_482 -> V_488 ) ;
F_27 ( V_483 ) ;
}
error = F_198 ( V_23 , NULL , V_429 , & V_431 ) ;
if ( error ) {
F_112 ( V_23 , L_101 ,
V_8 , V_429 , error ) ;
} else {
struct V_489 * V_430 = F_199 ( V_431 ) ;
V_485 += F_30 ( V_430 -> V_490 ) ;
V_486 += F_30 ( V_430 -> V_491 ) ;
F_27 ( V_431 ) ;
}
}
}
