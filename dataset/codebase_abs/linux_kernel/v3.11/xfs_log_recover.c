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
F_91 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_162 :
if ( V_160 -> V_163 & V_164 ) {
F_92 ( log ,
V_124 , V_132 , V_153 ) ;
F_93 ( & V_132 -> V_133 , & V_156 ) ;
break;
}
if ( V_160 -> V_163 & V_165 ) {
F_93 ( & V_132 -> V_133 , & V_158 ) ;
break;
}
F_91 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
F_94 ( log ,
V_124 , V_132 , V_153 ) ;
F_91 ( & V_132 -> V_133 , & V_159 ) ;
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
struct V_171 * V_132 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_131 * V_172 ;
struct V_173 * V_174 ;
if ( ! ( V_160 -> V_163 & V_164 ) ) {
F_98 ( log , V_160 ) ;
return 0 ;
}
V_172 = F_99 ( log , V_160 -> V_175 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_174 -> V_176 == V_160 -> V_175 &&
V_174 -> V_177 == V_160 -> V_178 ) {
V_174 -> V_179 ++ ;
F_101 ( log , V_160 ) ;
return 0 ;
}
}
V_174 = F_84 ( sizeof( struct V_173 ) , V_127 ) ;
V_174 -> V_176 = V_160 -> V_175 ;
V_174 -> V_177 = V_160 -> V_178 ;
V_174 -> V_179 = 1 ;
F_77 ( & V_174 -> V_180 , V_172 ) ;
F_102 ( log , V_160 ) ;
return 0 ;
}
STATIC int
F_103 (
struct V_1 * log ,
T_3 V_181 ,
T_6 V_136 ,
T_14 V_182 )
{
struct V_131 * V_172 ;
struct V_173 * V_174 ;
if ( log -> V_183 == NULL ) {
ASSERT ( ! ( V_182 & V_164 ) ) ;
return 0 ;
}
V_172 = F_99 ( log , V_181 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_174 -> V_176 == V_181 && V_174 -> V_177 == V_136 )
goto V_75;
}
ASSERT ( ! ( V_182 & V_164 ) ) ;
return 0 ;
V_75:
if ( V_182 & V_164 ) {
if ( -- V_174 -> V_179 == 0 ) {
F_104 ( & V_174 -> V_180 ) ;
F_105 ( V_174 ) ;
}
}
return 1 ;
}
STATIC int
F_106 (
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
F_107 ( V_23 -> V_194 , V_160 ) ;
if ( F_108 ( & V_23 -> V_25 ) )
V_6 -> V_195 = & V_196 ;
V_191 = F_11 ( V_6 -> V_18 ) >> V_23 -> V_25 . V_197 ;
for ( V_45 = 0 ; V_45 < V_191 ; V_45 ++ ) {
V_190 = ( V_45 * V_23 -> V_25 . V_198 ) +
F_109 ( V_199 , V_200 ) ;
while ( V_190 >=
( V_188 + V_189 ) ) {
V_186 += V_187 ;
V_186 = F_110 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
return 0 ;
V_187 = F_111 ( V_160 -> V_201 ,
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
F_112 ( V_23 ,
L_23
L_24 ,
V_132 , V_6 ) ;
F_4 ( L_25 ,
V_121 , V_23 ) ;
return F_34 ( V_16 ) ;
}
V_193 = ( T_15 * ) F_113 ( V_6 ,
V_190 ) ;
* V_193 = * V_192 ;
F_114 ( V_23 , (struct V_205 * )
F_113 ( V_6 , V_45 * V_23 -> V_25 . V_198 ) ) ;
}
return 0 ;
}
static void
F_115 (
struct V_184 * V_23 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
struct V_206 * V_207 = V_6 -> V_15 ;
T_16 V_208 ;
T_17 V_209 ;
T_17 V_210 ;
V_208 = F_30 ( * ( V_81 * ) V_6 -> V_15 ) ;
V_209 = F_116 ( * ( V_211 * ) V_6 -> V_15 ) ;
V_210 = F_116 ( V_207 -> V_212 ) ;
switch ( F_117 ( V_160 ) ) {
case V_213 :
switch ( V_208 ) {
case V_214 :
case V_215 :
case V_216 :
case V_217 :
V_6 -> V_195 = & V_218 ;
break;
case V_219 :
case V_220 :
V_6 -> V_195 = & V_221 ;
break;
case V_222 :
case V_223 :
V_6 -> V_195 = & V_224 ;
break;
default:
F_3 ( V_23 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_225 :
if ( V_208 != V_226 ) {
F_3 ( V_23 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_227 ;
break;
case V_228 :
if ( ! F_108 ( & V_23 -> V_25 ) )
break;
if ( V_208 != V_229 ) {
F_3 ( V_23 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_230 ;
break;
case V_231 :
if ( V_208 != V_232 ) {
F_3 ( V_23 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_233 ;
break;
case V_234 :
case V_235 :
case V_236 :
#ifdef F_118
if ( V_209 != V_237 ) {
F_3 ( V_23 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_238 ;
#else
F_112 ( V_23 ,
L_31 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_239 :
if ( V_209 != V_240 ) {
F_3 ( V_23 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_196 ;
break;
case V_241 :
if ( V_208 != V_242 ) {
F_3 ( V_23 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_243 ;
break;
case V_244 :
if ( V_208 != V_245 &&
V_208 != V_246 ) {
F_3 ( V_23 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_247 ;
break;
case V_248 :
if ( V_208 != V_249 &&
V_208 != V_250 ) {
F_3 ( V_23 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_251 ;
break;
case V_252 :
if ( V_208 != V_253 &&
V_208 != V_254 ) {
F_3 ( V_23 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_255 ;
break;
case V_256 :
if ( V_210 != V_257 &&
V_210 != V_258 ) {
F_3 ( V_23 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_259 ;
break;
case V_260 :
if ( V_210 != V_261 &&
V_210 != V_262 ) {
F_3 ( V_23 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_263 ;
break;
case V_264 :
if ( V_210 != V_265 &&
V_210 != V_266 ) {
F_3 ( V_23 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_267 ;
break;
case V_268 :
if ( V_210 != V_269 &&
V_210 != V_270 ) {
F_3 ( V_23 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_271 ;
break;
case V_272 :
if ( ! F_108 ( & V_23 -> V_25 ) )
break;
if ( V_208 != V_273 ) {
F_3 ( V_23 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_274 ;
break;
case V_275 :
if ( V_208 != V_276 ) {
F_3 ( V_23 , L_42 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_277 ;
break;
default:
F_3 ( V_23 , L_43 ,
F_117 ( V_160 ) ) ;
break;
}
}
STATIC void
F_119 (
struct V_184 * V_23 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_45 ;
int V_186 ;
int V_187 ;
int error ;
F_120 ( V_23 -> V_194 , V_160 ) ;
V_186 = 0 ;
V_45 = 1 ;
while ( 1 ) {
V_186 = F_110 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
break;
V_187 = F_111 ( V_160 -> V_201 ,
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
( V_278 | V_279 | V_280 ) ) {
if ( V_132 -> V_143 [ V_45 ] . V_145 == NULL ) {
F_112 ( V_23 ,
L_44 , V_8 ) ;
goto V_281;
}
if ( V_132 -> V_143 [ V_45 ] . V_146 < sizeof( V_282 ) ) {
F_112 ( V_23 ,
L_45 ,
V_132 -> V_143 [ V_45 ] . V_146 , V_8 ) ;
goto V_281;
}
error = F_121 ( V_23 , V_132 -> V_143 [ V_45 ] . V_145 ,
- 1 , 0 , V_283 ,
L_46 ) ;
if ( error )
goto V_281;
}
memcpy ( F_113 ( V_6 ,
( T_6 ) V_186 << V_203 ) ,
V_132 -> V_143 [ V_45 ] . V_145 ,
V_187 << V_203 ) ;
V_281:
V_45 ++ ;
V_186 += V_187 ;
}
ASSERT ( V_45 == V_132 -> V_149 ) ;
if ( F_108 ( & V_23 -> V_25 ) )
F_115 ( V_23 , V_6 , V_160 ) ;
}
int
F_121 (
struct V_184 * V_23 ,
V_282 * V_284 ,
T_18 V_285 ,
T_6 type ,
T_6 V_182 ,
char * V_286 )
{
T_19 * V_287 = ( T_19 * ) V_284 ;
int V_288 = 0 ;
if ( V_284 -> V_289 != F_122 ( V_237 ) ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_47 ,
V_286 , V_285 , F_116 ( V_284 -> V_289 ) , V_237 ) ;
V_288 ++ ;
}
if ( V_284 -> V_290 != V_291 ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_48 ,
V_286 , V_285 , V_284 -> V_290 , V_291 ) ;
V_288 ++ ;
}
if ( V_284 -> V_292 != V_293 &&
V_284 -> V_292 != V_294 &&
V_284 -> V_292 != V_295 ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_49 ,
V_286 , V_285 , V_284 -> V_292 ) ;
V_288 ++ ;
}
if ( V_285 != - 1 && V_285 != F_30 ( V_284 -> V_296 ) ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_50
L_51 ,
V_286 , V_284 , V_285 , F_30 ( V_284 -> V_296 ) ) ;
V_288 ++ ;
}
if ( ! V_288 && V_284 -> V_296 ) {
if ( V_284 -> V_297 &&
F_56 ( V_284 -> V_298 ) >
F_56 ( V_284 -> V_297 ) ) {
if ( ! V_284 -> V_299 ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_52 ,
V_286 , ( int ) F_30 ( V_284 -> V_296 ) , V_284 ) ;
V_288 ++ ;
}
}
if ( V_284 -> V_300 &&
F_56 ( V_284 -> V_301 ) >
F_56 ( V_284 -> V_300 ) ) {
if ( ! V_284 -> V_302 ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_53 ,
V_286 , ( int ) F_30 ( V_284 -> V_296 ) , V_284 ) ;
V_288 ++ ;
}
}
if ( V_284 -> V_303 &&
F_56 ( V_284 -> V_304 ) >
F_56 ( V_284 -> V_303 ) ) {
if ( ! V_284 -> V_305 ) {
if ( V_182 & V_283 )
F_112 ( V_23 ,
L_54 ,
V_286 , ( int ) F_30 ( V_284 -> V_296 ) , V_284 ) ;
V_288 ++ ;
}
}
}
if ( ! V_288 || ! ( V_182 & V_306 ) )
return V_288 ;
if ( V_182 & V_283 )
F_123 ( V_23 , L_55 , V_285 ) ;
ASSERT ( V_285 != - 1 ) ;
ASSERT ( V_182 & V_306 ) ;
memset ( V_287 , 0 , sizeof( T_19 ) ) ;
V_287 -> V_307 . V_289 = F_122 ( V_237 ) ;
V_287 -> V_307 . V_290 = V_291 ;
V_287 -> V_307 . V_292 = type ;
V_287 -> V_307 . V_296 = F_32 ( V_285 ) ;
if ( F_108 ( & V_23 -> V_25 ) ) {
F_124 ( & V_287 -> V_308 , & V_23 -> V_25 . V_26 ) ;
F_125 ( ( char * ) V_287 , sizeof( struct V_309 ) ,
V_310 ) ;
}
return V_288 ;
}
STATIC void
F_126 (
struct V_184 * V_23 ,
struct V_1 * log ,
struct V_171 * V_132 ,
struct V_5 * V_6 ,
struct V_311 * V_160 )
{
T_6 type ;
F_127 ( log , V_160 ) ;
if ( V_23 -> V_312 == 0 ) {
return;
}
type = 0 ;
if ( V_160 -> V_163 & V_278 )
type |= V_293 ;
if ( V_160 -> V_163 & V_279 )
type |= V_294 ;
if ( V_160 -> V_163 & V_280 )
type |= V_295 ;
if ( log -> V_313 & type )
return;
F_119 ( V_23 , V_132 , V_6 , V_160 ) ;
}
STATIC int
F_128 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_314 ;
if ( F_103 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
F_129 ( log , V_160 ) ;
return 0 ;
}
F_130 ( log , V_160 ) ;
V_314 = 0 ;
if ( V_160 -> V_163 & V_165 )
V_314 |= V_315 ;
V_6 = F_131 ( V_23 -> V_316 , V_160 -> V_175 , V_160 -> V_178 ,
V_314 , NULL ) ;
if ( ! V_6 )
return F_34 ( V_49 ) ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_56 ) ;
F_27 ( V_6 ) ;
return error ;
}
if ( V_160 -> V_163 & V_165 ) {
error = F_106 ( V_23 , V_132 , V_6 , V_160 ) ;
} else if ( V_160 -> V_163 &
( V_278 | V_279 | V_280 ) ) {
F_126 ( V_23 , log , V_132 , V_6 , V_160 ) ;
} else {
F_119 ( V_23 , V_132 , V_6 , V_160 ) ;
}
if ( error )
return F_34 ( error ) ;
if ( V_240 ==
F_116 ( * ( ( V_211 * ) F_113 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_132 ( log -> V_7 -> V_25 . V_317 ,
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
struct V_171 * V_132 )
{
T_12 * V_147 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_199 * V_318 ;
int V_136 ;
T_2 V_319 ;
T_2 V_320 ;
int error ;
int V_321 ;
T_6 V_322 ;
T_20 * V_323 ;
T_6 V_324 ;
int V_325 = 0 ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( T_12 ) ) {
V_147 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_147 = F_84 ( sizeof( T_12 ) , V_127 ) ;
V_325 = 1 ;
error = F_137 ( & V_132 -> V_143 [ 0 ] , V_147 ) ;
if ( error )
goto error;
}
if ( F_103 ( log , V_147 -> V_326 ,
V_147 -> V_327 , 0 ) ) {
error = 0 ;
F_138 ( log , V_147 ) ;
goto error;
}
F_139 ( log , V_147 ) ;
V_6 = F_131 ( V_23 -> V_316 , V_147 -> V_326 , V_147 -> V_327 , 0 ,
& V_196 ) ;
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
ASSERT ( V_147 -> V_328 & V_329 ) ;
V_318 = ( V_199 * ) F_113 ( V_6 , V_147 -> V_330 ) ;
if ( F_33 ( V_318 -> V_331 != F_122 ( V_240 ) ) ) {
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_58 ,
V_8 , V_318 , V_6 , V_147 -> V_332 ) ;
F_4 ( L_59 ,
V_121 , V_23 ) ;
error = V_16 ;
goto error;
}
V_323 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( F_33 ( V_323 -> V_331 != V_240 ) ) {
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_60 ,
V_8 , V_132 , V_147 -> V_332 ) ;
F_4 ( L_61 ,
V_121 , V_23 ) ;
error = V_16 ;
goto error;
}
if ( ! F_108 ( & V_23 -> V_25 ) &&
V_323 -> V_333 < F_116 ( V_318 -> V_333 ) ) {
if ( F_116 ( V_318 -> V_333 ) == V_334 &&
V_323 -> V_333 < ( V_334 >> 1 ) ) {
} else {
F_27 ( V_6 ) ;
F_140 ( log , V_147 ) ;
error = 0 ;
goto error;
}
}
V_323 -> V_333 = 0 ;
if ( F_33 ( F_141 ( V_323 -> V_335 ) ) ) {
if ( ( V_323 -> V_336 != V_337 ) &&
( V_323 -> V_336 != V_338 ) ) {
F_142 ( L_62 ,
V_121 , V_23 , V_323 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_63
L_64 ,
V_8 , V_132 , V_318 , V_6 , V_147 -> V_332 ) ;
error = V_16 ;
goto error;
}
} else if ( F_33 ( F_143 ( V_323 -> V_335 ) ) ) {
if ( ( V_323 -> V_336 != V_337 ) &&
( V_323 -> V_336 != V_338 ) &&
( V_323 -> V_336 != V_339 ) ) {
F_142 ( L_65 ,
V_121 , V_23 , V_323 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_66
L_64 ,
V_8 , V_132 , V_318 , V_6 , V_147 -> V_332 ) ;
error = V_16 ;
goto error;
}
}
if ( F_33 ( V_323 -> V_340 + V_323 -> V_341 > V_323 -> V_342 ) ) {
F_142 ( L_67 ,
V_121 , V_23 , V_323 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_68
L_69 ,
V_8 , V_132 , V_318 , V_6 , V_147 -> V_332 ,
V_323 -> V_340 + V_323 -> V_341 ,
V_323 -> V_342 ) ;
error = V_16 ;
goto error;
}
if ( F_33 ( V_323 -> V_343 > V_23 -> V_25 . V_198 ) ) {
F_142 ( L_70 ,
V_121 , V_23 , V_323 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_68
L_71 , V_8 ,
V_132 , V_318 , V_6 , V_147 -> V_332 , V_323 -> V_343 ) ;
error = V_16 ;
goto error;
}
V_324 = F_144 ( V_323 -> V_344 ) ;
if ( F_33 ( V_132 -> V_143 [ 1 ] . V_146 > V_324 ) ) {
F_142 ( L_72 ,
V_121 , V_23 , V_323 ) ;
F_27 ( V_6 ) ;
F_112 ( V_23 ,
L_73 ,
V_8 , V_132 -> V_143 [ 1 ] . V_146 , V_132 ) ;
error = V_16 ;
goto error;
}
F_145 ( V_318 , V_323 ) ;
if ( V_132 -> V_143 [ 1 ] . V_146 > V_324 ) {
memcpy ( ( char * ) V_318 + V_324 ,
V_132 -> V_143 [ 1 ] . V_145 + V_324 ,
V_132 -> V_143 [ 1 ] . V_146 - V_324 ) ;
}
V_322 = V_147 -> V_328 ;
switch ( V_322 & ( V_345 | V_346 ) ) {
case V_345 :
F_146 ( V_318 , V_147 -> V_347 . V_348 ) ;
break;
case V_346 :
memcpy ( F_147 ( V_318 ) ,
& V_147 -> V_347 . V_349 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_147 -> V_150 == 2 )
goto V_350;
V_136 = V_132 -> V_143 [ 2 ] . V_146 ;
V_319 = V_132 -> V_143 [ 2 ] . V_145 ;
ASSERT ( V_147 -> V_150 <= 4 ) ;
ASSERT ( ( V_147 -> V_150 == 3 ) || ( V_322 & V_351 ) ) ;
ASSERT ( ! ( V_322 & V_352 ) ||
( V_136 == V_147 -> V_353 ) ) ;
switch ( V_322 & V_352 ) {
case V_354 :
case V_355 :
memcpy ( F_147 ( V_318 ) , V_319 , V_136 ) ;
break;
case V_356 :
F_148 ( V_23 , (struct V_357 * ) V_319 , V_136 ,
( V_358 * ) F_147 ( V_318 ) ,
F_149 ( V_318 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_322 & V_352 ) == 0 ) ;
break;
}
if ( V_147 -> V_328 & V_351 ) {
if ( V_147 -> V_328 & V_352 ) {
V_321 = 3 ;
} else {
V_321 = 2 ;
}
V_136 = V_132 -> V_143 [ V_321 ] . V_146 ;
V_319 = V_132 -> V_143 [ V_321 ] . V_145 ;
ASSERT ( V_136 == V_147 -> V_359 ) ;
switch ( V_147 -> V_328 & V_351 ) {
case V_360 :
case V_361 :
V_320 = F_150 ( V_318 ) ;
ASSERT ( V_136 <= F_151 ( V_318 , V_23 ) ) ;
memcpy ( V_320 , V_319 , V_136 ) ;
break;
case V_362 :
V_320 = F_150 ( V_318 ) ;
F_148 ( V_23 , (struct V_357 * ) V_319 ,
V_136 , ( V_358 * ) V_320 ,
F_151 ( V_318 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_74 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
error = V_58 ;
goto error;
}
}
V_350:
F_114 ( log -> V_7 , V_318 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_135 ( V_6 , V_157 ) ;
F_27 ( V_6 ) ;
error:
if ( V_325 )
F_105 ( V_147 ) ;
return F_34 ( error ) ;
}
STATIC int
F_152 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_21 * V_363 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_363 ) ;
if ( V_363 -> V_364 & V_365 )
log -> V_313 |= V_293 ;
if ( V_363 -> V_364 & V_366 )
log -> V_313 |= V_294 ;
if ( V_363 -> V_364 & V_367 )
log -> V_313 |= V_295 ;
return ( 0 ) ;
}
STATIC int
F_153 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 )
{
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_368 * V_284 , * V_369 ;
int error ;
T_22 * V_370 ;
T_6 type ;
if ( V_23 -> V_312 == 0 )
return ( 0 ) ;
V_369 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_369 == NULL ) {
F_112 ( log -> V_7 , L_75 , V_8 ) ;
return F_34 ( V_58 ) ;
}
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( V_282 ) ) {
F_112 ( log -> V_7 , L_76 ,
V_132 -> V_143 [ 1 ] . V_146 , V_8 ) ;
return F_34 ( V_58 ) ;
}
type = V_369 -> V_292 & ( V_293 | V_294 | V_295 ) ;
ASSERT ( type ) ;
if ( log -> V_313 & type )
return ( 0 ) ;
V_370 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_370 ) ;
error = F_121 ( V_23 , V_369 , V_370 -> V_371 , 0 , V_283 ,
L_77 ) ;
if ( error )
return F_34 ( V_58 ) ;
ASSERT ( V_370 -> V_372 == 1 ) ;
error = F_154 ( V_23 , NULL , V_23 -> V_316 , V_370 -> V_373 ,
F_155 ( V_23 , V_370 -> V_372 ) , 0 , & V_6 ,
NULL ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_284 = ( V_282 * ) F_113 ( V_6 , V_370 -> V_374 ) ;
error = F_121 ( V_23 , V_284 , V_370 -> V_371 , 0 , V_283 ,
L_78 ) ;
if ( error ) {
F_27 ( V_6 ) ;
return F_34 ( V_58 ) ;
}
memcpy ( V_284 , V_369 , V_132 -> V_143 [ 1 ] . V_146 ) ;
if ( F_108 ( & V_23 -> V_25 ) ) {
F_125 ( ( char * ) V_284 , sizeof( struct V_309 ) ,
V_310 ) ;
}
ASSERT ( V_370 -> V_375 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_135 ( V_6 , V_157 ) ;
F_27 ( V_6 ) ;
return ( 0 ) ;
}
STATIC int
F_156 (
struct V_1 * log ,
struct V_171 * V_132 ,
T_8 V_126 )
{
int error ;
T_4 * V_23 = log -> V_7 ;
T_23 * V_376 ;
T_24 * V_377 ;
V_377 = V_132 -> V_143 [ 0 ] . V_145 ;
V_376 = F_157 ( V_23 , V_377 -> V_378 ) ;
if ( ( error = F_158 ( & ( V_132 -> V_143 [ 0 ] ) ,
& ( V_376 -> V_379 ) ) ) ) {
F_159 ( V_376 ) ;
return error ;
}
F_160 ( & V_376 -> V_380 , V_377 -> V_378 ) ;
F_161 ( & log -> V_381 -> V_382 ) ;
F_162 ( log -> V_381 , & V_376 -> V_383 , V_126 ) ;
return 0 ;
}
STATIC int
F_163 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_25 * V_384 ;
T_23 * V_376 = NULL ;
T_26 * V_385 ;
T_27 V_386 ;
struct V_387 V_388 ;
struct V_389 * V_390 = log -> V_381 ;
V_384 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( ( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_391 ) +
( ( V_384 -> V_392 - 1 ) * sizeof( V_393 ) ) ) ) ||
( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_394 ) +
( ( V_384 -> V_392 - 1 ) * sizeof( V_395 ) ) ) ) ) ;
V_386 = V_384 -> V_396 ;
F_161 ( & V_390 -> V_382 ) ;
V_385 = F_164 ( V_390 , & V_388 , 0 ) ;
while ( V_385 != NULL ) {
if ( V_385 -> V_397 == V_170 ) {
V_376 = ( T_23 * ) V_385 ;
if ( V_376 -> V_379 . V_386 == V_386 ) {
F_165 ( V_390 , V_385 ,
V_398 ) ;
F_159 ( V_376 ) ;
F_161 ( & V_390 -> V_382 ) ;
break;
}
}
V_385 = F_166 ( V_390 , & V_388 ) ;
}
F_167 ( V_390 , & V_388 ) ;
F_168 ( & V_390 -> V_382 ) ;
return 0 ;
}
STATIC int
F_169 (
struct V_1 * log ,
struct V_131 * V_157 ,
T_11 * V_132 )
{
struct V_184 * V_23 = log -> V_7 ;
struct V_399 * V_400 ;
T_28 V_401 ;
T_29 V_402 ;
unsigned int V_403 ;
unsigned int V_324 ;
T_29 V_404 ;
V_400 = (struct V_399 * ) V_132 -> V_143 [ 0 ] . V_145 ;
if ( V_400 -> V_405 != V_161 ) {
F_3 ( log -> V_7 , L_79 ) ;
return V_102 ;
}
if ( V_400 -> V_406 != 1 ) {
F_3 ( log -> V_7 , L_80 ) ;
return V_102 ;
}
V_401 = F_30 ( V_400 -> V_407 ) ;
if ( V_401 >= V_23 -> V_25 . V_408 ) {
F_3 ( log -> V_7 , L_81 ) ;
return V_102 ;
}
V_402 = F_30 ( V_400 -> V_409 ) ;
if ( ! V_402 || V_402 == V_410 || V_402 >= V_23 -> V_25 . V_411 ) {
F_3 ( log -> V_7 , L_82 ) ;
return V_102 ;
}
V_324 = F_30 ( V_400 -> V_412 ) ;
if ( V_324 != V_23 -> V_25 . V_198 ) {
F_3 ( log -> V_7 , L_83 ) ;
return V_102 ;
}
V_403 = F_30 ( V_400 -> V_413 ) ;
if ( ! V_403 ) {
F_3 ( log -> V_7 , L_84 ) ;
return V_102 ;
}
V_404 = F_30 ( V_400 -> V_414 ) ;
if ( ! V_404 || V_404 >= V_23 -> V_25 . V_411 ) {
F_3 ( log -> V_7 , L_85 ) ;
return V_102 ;
}
ASSERT ( V_403 == F_170 ( V_23 ) ) ;
ASSERT ( V_404 == F_171 ( V_23 ) ) ;
if ( V_403 != F_170 ( V_23 ) ||
V_404 != F_171 ( V_23 ) ) {
F_3 ( log -> V_7 , L_86 ) ;
return V_102 ;
}
if ( F_103 ( log ,
F_172 ( V_23 , V_401 , V_402 ) , V_404 , 0 ) )
return 0 ;
F_173 ( V_23 , NULL , V_157 , V_401 , V_402 , V_404 ,
F_30 ( V_400 -> V_415 ) ) ;
return 0 ;
}
STATIC void
F_174 (
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
F_175 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_171 * V_132 )
{
F_176 ( log , V_124 , V_132 , V_416 ) ;
switch ( F_90 ( V_132 ) ) {
case V_162 :
return F_97 ( log , V_132 ) ;
case V_168 :
return F_152 ( log , V_132 ) ;
case V_166 :
case V_170 :
case V_169 :
case V_167 :
case V_161 :
return 0 ;
default:
F_3 ( log -> V_7 , L_87 ,
V_8 , F_90 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_177 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_171 * V_132 )
{
F_176 ( log , V_124 , V_132 , V_417 ) ;
switch ( F_90 ( V_132 ) ) {
case V_162 :
return F_128 ( log , V_157 , V_132 ) ;
case V_166 :
return F_136 ( log , V_157 , V_132 ) ;
case V_170 :
return F_156 ( log , V_132 , V_124 -> V_128 ) ;
case V_169 :
return F_163 ( log , V_132 ) ;
case V_167 :
return F_153 ( log , V_157 , V_132 ) ;
case V_161 :
return F_169 ( log , V_157 , V_132 ) ;
case V_168 :
return 0 ;
default:
F_3 ( log -> V_7 , L_87 ,
V_8 , F_90 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_178 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
int error = 0 , V_22 ;
T_11 * V_132 ;
F_87 ( V_157 ) ;
F_179 ( & V_124 -> V_130 ) ;
error = F_86 ( log , V_124 , V_153 ) ;
if ( error )
return error ;
F_100 (item, &trans->r_itemq, ri_list) {
switch ( V_153 ) {
case V_416 :
error = F_175 ( log , V_124 , V_132 ) ;
break;
case V_417 :
error = F_177 ( log , V_124 ,
& V_157 , V_132 ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
F_174 ( V_124 ) ;
V_51:
V_22 = F_180 ( & V_157 ) ;
return error ? error : V_22 ;
}
STATIC int
F_181 (
struct V_1 * log ,
struct V_134 * V_124 )
{
F_3 ( log -> V_7 , L_88 , V_8 ) ;
return 0 ;
}
STATIC int
F_182 (
struct V_1 * log ,
struct V_122 V_418 [] ,
struct V_419 * V_73 ,
T_2 V_135 ,
int V_153 )
{
T_2 V_420 ;
int V_421 ;
T_7 * V_422 ;
T_9 * V_124 ;
T_10 V_123 ;
int error ;
unsigned long V_423 ;
T_6 V_182 ;
V_420 = V_135 + F_30 ( V_73 -> V_61 ) ;
V_421 = F_30 ( V_73 -> V_95 ) ;
if ( F_31 ( log -> V_7 , V_73 ) )
return ( F_34 ( V_58 ) ) ;
while ( ( V_135 < V_420 ) && V_421 ) {
ASSERT ( V_135 + sizeof( T_7 ) <= V_420 ) ;
V_422 = ( T_7 * ) V_135 ;
V_135 += sizeof( T_7 ) ;
if ( V_422 -> V_424 != V_425 &&
V_422 -> V_424 != V_426 ) {
F_3 ( log -> V_7 , L_89 ,
V_8 , V_422 -> V_424 ) ;
ASSERT ( 0 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_123 = F_30 ( V_422 -> V_427 ) ;
V_423 = F_183 ( V_123 ) ;
V_124 = F_69 ( & V_418 [ V_423 ] , V_123 ) ;
if ( V_124 == NULL ) {
if ( V_422 -> V_96 & V_428 )
F_71 ( & V_418 [ V_423 ] , V_123 ,
F_56 ( V_73 -> V_89 ) ) ;
} else {
if ( V_135 + F_30 ( V_422 -> V_429 ) > V_420 ) {
F_3 ( log -> V_7 , L_90 ,
V_8 , F_30 ( V_422 -> V_429 ) ) ;
F_184 ( 1 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_182 = V_422 -> V_96 & ~ V_430 ;
if ( V_182 & V_431 )
V_182 &= ~ V_432 ;
switch ( V_182 ) {
case V_433 :
error = F_178 ( log ,
V_124 , V_153 ) ;
break;
case V_97 :
error = F_181 ( log , V_124 ) ;
break;
case V_431 :
error = F_78 ( log ,
V_124 , V_135 ,
F_30 ( V_422 -> V_429 ) ) ;
break;
case V_428 :
F_3 ( log -> V_7 , L_91 ,
V_8 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
case 0 :
case V_432 :
error = F_83 ( log , V_124 ,
V_135 , F_30 ( V_422 -> V_429 ) ) ;
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
V_135 += F_30 ( V_422 -> V_429 ) ;
V_421 -- ;
}
return 0 ;
}
STATIC int
F_185 (
T_4 * V_23 ,
T_23 * V_376 )
{
T_30 * V_434 ;
T_31 * V_435 ;
int V_45 ;
int error = 0 ;
T_32 * V_436 ;
T_33 V_437 ;
ASSERT ( ! F_186 ( V_438 , & V_376 -> V_439 ) ) ;
for ( V_45 = 0 ; V_45 < V_376 -> V_379 . V_378 ; V_45 ++ ) {
V_436 = & ( V_376 -> V_379 . V_440 [ V_45 ] ) ;
V_437 = F_187 ( V_23 ,
F_188 ( V_23 , V_436 -> V_441 ) ) ;
if ( ( V_437 == 0 ) ||
( V_436 -> V_442 == 0 ) ||
( V_437 >= V_23 -> V_25 . V_443 ) ||
( V_436 -> V_442 >= V_23 -> V_25 . V_411 ) ) {
F_189 ( V_438 , & V_376 -> V_439 ) ;
F_190 ( V_376 , V_376 -> V_379 . V_378 ) ;
return F_34 ( V_58 ) ;
}
}
V_435 = F_191 ( V_23 , 0 ) ;
error = F_192 ( V_435 , 0 , F_193 ( V_23 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_444;
V_434 = F_194 ( V_435 , V_376 , V_376 -> V_379 . V_378 ) ;
for ( V_45 = 0 ; V_45 < V_376 -> V_379 . V_378 ; V_45 ++ ) {
V_436 = & ( V_376 -> V_379 . V_440 [ V_45 ] ) ;
error = F_195 ( V_435 , V_436 -> V_441 , V_436 -> V_442 ) ;
if ( error )
goto V_444;
F_196 ( V_435 , V_434 , V_436 -> V_441 ,
V_436 -> V_442 ) ;
}
F_189 ( V_438 , & V_376 -> V_439 ) ;
error = F_197 ( V_435 , 0 ) ;
return error ;
V_444:
F_198 ( V_435 , V_445 ) ;
return error ;
}
STATIC int
F_199 (
struct V_1 * log )
{
T_26 * V_385 ;
T_23 * V_376 ;
int error = 0 ;
struct V_387 V_388 ;
struct V_389 * V_390 ;
V_390 = log -> V_381 ;
F_161 ( & V_390 -> V_382 ) ;
V_385 = F_164 ( V_390 , & V_388 , 0 ) ;
while ( V_385 != NULL ) {
if ( V_385 -> V_397 != V_170 ) {
#ifdef F_200
for (; V_385 ; V_385 = F_166 ( V_390 , & V_388 ) )
ASSERT ( V_385 -> V_397 != V_170 ) ;
#endif
break;
}
V_376 = ( T_23 * ) V_385 ;
if ( F_186 ( V_438 , & V_376 -> V_439 ) ) {
V_385 = F_166 ( V_390 , & V_388 ) ;
continue;
}
F_168 ( & V_390 -> V_382 ) ;
error = F_185 ( log -> V_7 , V_376 ) ;
F_161 ( & V_390 -> V_382 ) ;
if ( error )
goto V_51;
V_385 = F_166 ( V_390 , & V_388 ) ;
}
V_51:
F_167 ( V_390 , & V_388 ) ;
F_168 ( & V_390 -> V_382 ) ;
return error ;
}
STATIC void
F_201 (
T_4 * V_23 ,
T_28 V_401 ,
int V_172 )
{
T_31 * V_435 ;
T_34 * V_446 ;
T_1 * V_447 ;
int V_13 ;
int error ;
V_435 = F_191 ( V_23 , V_448 ) ;
error = F_192 ( V_435 , 0 , F_202 ( V_23 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_449;
error = F_203 ( V_23 , V_435 , V_401 , & V_447 ) ;
if ( error )
goto V_449;
V_446 = F_204 ( V_447 ) ;
V_446 -> V_450 [ V_172 ] = F_32 ( V_451 ) ;
V_13 = F_109 ( T_34 , V_450 ) +
( sizeof( T_15 ) * V_172 ) ;
F_205 ( V_435 , V_447 , V_13 ,
( V_13 + sizeof( T_15 ) - 1 ) ) ;
error = F_197 ( V_435 , 0 ) ;
if ( error )
goto V_452;
return;
V_449:
F_198 ( V_435 , V_445 ) ;
V_452:
F_3 ( V_23 , L_93 , V_8 , V_401 ) ;
return;
}
STATIC T_15
F_206 (
struct V_184 * V_23 ,
T_28 V_401 ,
T_15 V_453 ,
int V_172 )
{
struct V_5 * V_454 ;
struct V_205 * V_318 ;
struct V_455 * V_456 ;
T_35 V_457 ;
int error ;
V_457 = F_207 ( V_23 , V_401 , V_453 ) ;
error = F_208 ( V_23 , NULL , V_457 , 0 , 0 , & V_456 ) ;
if ( error )
goto V_458;
error = F_209 ( V_23 , NULL , & V_456 -> V_459 , & V_318 , & V_454 , 0 , 0 ) ;
if ( error )
goto V_460;
ASSERT ( V_456 -> V_461 . V_462 == 0 ) ;
ASSERT ( V_456 -> V_461 . V_335 != 0 ) ;
V_453 = F_30 ( V_318 -> V_200 ) ;
F_27 ( V_454 ) ;
V_456 -> V_461 . V_463 = 0 ;
F_210 ( V_456 ) ;
return V_453 ;
V_460:
F_210 ( V_456 ) ;
V_458:
F_201 ( V_23 , V_401 , V_172 ) ;
return V_451 ;
}
STATIC void
F_211 (
struct V_1 * log )
{
T_4 * V_23 ;
T_28 V_401 ;
T_34 * V_446 ;
T_1 * V_447 ;
T_15 V_453 ;
int V_172 ;
int error ;
T_6 V_464 ;
V_23 = log -> V_7 ;
V_464 = V_23 -> V_465 ;
V_23 -> V_465 = 0 ;
for ( V_401 = 0 ; V_401 < V_23 -> V_25 . V_408 ; V_401 ++ ) {
error = F_203 ( V_23 , NULL , V_401 , & V_447 ) ;
if ( error ) {
continue;
}
V_446 = F_204 ( V_447 ) ;
F_7 ( V_447 ) ;
for ( V_172 = 0 ; V_172 < V_466 ; V_172 ++ ) {
V_453 = F_30 ( V_446 -> V_450 [ V_172 ] ) ;
while ( V_453 != V_451 ) {
V_453 = F_206 ( V_23 ,
V_401 , V_453 , V_172 ) ;
}
}
F_212 ( V_447 ) ;
}
V_23 -> V_465 = V_464 ;
}
STATIC int
F_213 (
struct V_419 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
T_36 V_467 ;
V_467 = F_214 ( log , V_73 , V_135 , F_30 ( V_73 -> V_61 ) ) ;
if ( V_467 != V_73 -> V_468 ) {
if ( V_73 -> V_468 || F_108 ( & log -> V_7 -> V_25 ) ) {
F_112 ( log -> V_7 ,
L_94 ,
F_215 ( V_73 -> V_468 ) ,
F_215 ( V_467 ) ) ;
F_216 ( V_135 , 32 ) ;
}
if ( F_108 ( & log -> V_7 -> V_25 ) )
return V_16 ;
}
return 0 ;
}
STATIC int
F_217 (
struct V_419 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
int V_45 , V_46 , V_469 ;
int error ;
error = F_213 ( V_73 , V_135 , log ) ;
if ( error )
return error ;
for ( V_45 = 0 ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_81 * ) V_135 = * ( V_81 * ) & V_73 -> V_470 [ V_45 ] ;
V_135 += V_52 ;
}
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
T_37 * V_471 = ( T_37 * ) V_73 ;
for ( ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_469 = V_45 % ( V_60 / V_52 ) ;
* ( V_81 * ) V_135 = V_471 [ V_46 ] . V_472 . V_473 [ V_469 ] ;
V_135 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_218 (
struct V_1 * log ,
struct V_419 * V_73 ,
T_3 V_181 )
{
int V_474 ;
if ( F_33 ( V_73 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_95 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 (
( ! V_73 -> V_93 ||
( F_30 ( V_73 -> V_93 ) & ( ~ V_475 ) ) ) ) ) {
F_3 ( log -> V_7 , L_96 ,
V_8 , F_30 ( V_73 -> V_93 ) ) ;
return F_34 ( V_58 ) ;
}
V_474 = F_30 ( V_73 -> V_61 ) ;
if ( F_33 ( V_474 <= 0 || V_474 > V_70 ) ) {
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
F_219 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_153 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_476 , * V_477 ;
int error = 0 , V_59 ;
int V_478 , V_479 ;
int V_79 , V_480 , V_481 ;
struct V_122 V_418 [ V_482 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
V_476 = F_2 ( log , 1 ) ;
if ( ! V_476 )
return V_49 ;
error = F_19 ( log , V_72 , 1 , V_476 , & V_13 ) ;
if ( error )
goto V_483;
V_73 = ( T_5 * ) V_13 ;
error = F_218 ( log , V_73 , V_72 ) ;
if ( error )
goto V_483;
V_59 = F_30 ( V_73 -> V_59 ) ;
if ( ( F_30 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_476 ) ;
V_476 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_476 = F_2 ( log , 1 ) ;
V_59 = V_484 ;
}
if ( ! V_476 )
return V_49 ;
V_477 = F_2 ( log , F_49 ( V_59 ) ) ;
if ( ! V_477 ) {
F_8 ( V_476 ) ;
return V_49 ;
}
memset ( V_418 , 0 , sizeof( V_418 ) ) ;
if ( V_72 <= V_63 ) {
for ( V_12 = V_72 ; V_12 < V_63 ; ) {
error = F_19 ( log , V_12 , V_79 , V_476 , & V_13 ) ;
if ( error )
goto V_485;
V_73 = ( T_5 * ) V_13 ;
error = F_218 ( log , V_73 , V_12 ) ;
if ( error )
goto V_485;
V_478 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_478 , V_477 ,
& V_13 ) ;
if ( error )
goto V_485;
error = F_217 ( V_73 , V_13 , log ) ;
if ( error )
goto V_485;
error = F_182 ( log ,
V_418 , V_73 , V_13 , V_153 ) ;
if ( error )
goto V_485;
V_12 += V_478 + V_79 ;
}
} else {
V_12 = V_72 ;
while ( V_12 < log -> V_3 ) {
V_13 = V_476 -> V_15 ;
V_480 = 0 ;
V_481 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_79 , V_476 ,
& V_13 ) ;
if ( error )
goto V_485;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_480 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_480 > 0 ) ;
error = F_19 ( log , V_12 ,
V_480 , V_476 ,
& V_13 ) ;
if ( error )
goto V_485;
}
V_481 = V_79 - V_480 ;
error = F_20 ( log , 0 ,
V_481 , V_476 ,
V_13 + F_11 ( V_480 ) ) ;
if ( error )
goto V_485;
}
V_73 = ( T_5 * ) V_13 ;
error = F_218 ( log , V_73 ,
V_480 ? V_12 : 0 ) ;
if ( error )
goto V_485;
V_478 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_478 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_478 , V_477 ,
& V_13 ) ;
if ( error )
goto V_485;
} else {
V_13 = V_477 -> V_15 ;
V_479 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_481 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_479 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_479 > 0 ) ;
error = F_19 ( log , V_12 ,
V_479 , V_477 ,
& V_13 ) ;
if ( error )
goto V_485;
}
error = F_20 ( log , 0 ,
V_478 - V_479 , V_477 ,
V_13 + F_11 ( V_479 ) ) ;
if ( error )
goto V_485;
}
error = F_217 ( V_73 , V_13 , log ) ;
if ( error )
goto V_485;
error = F_182 ( log , V_418 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_485;
V_12 += V_478 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_79 , V_476 , & V_13 ) ;
if ( error )
goto V_485;
V_73 = ( T_5 * ) V_13 ;
error = F_218 ( log , V_73 , V_12 ) ;
if ( error )
goto V_485;
V_478 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_478 , V_477 ,
& V_13 ) ;
if ( error )
goto V_485;
error = F_217 ( V_73 , V_13 , log ) ;
if ( error )
goto V_485;
error = F_182 ( log , V_418 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_485;
V_12 += V_478 + V_79 ;
}
}
V_485:
F_8 ( V_477 ) ;
V_483:
F_8 ( V_476 ) ;
return error ;
}
STATIC int
F_220 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_183 = F_72 ( V_486 *
sizeof( struct V_131 ) ,
V_127 ) ;
for ( V_45 = 0 ; V_45 < V_486 ; V_45 ++ )
F_73 ( & log -> V_183 [ V_45 ] ) ;
error = F_219 ( log , V_63 , V_72 ,
V_416 ) ;
if ( error != 0 ) {
F_105 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
error = F_219 ( log , V_63 , V_72 ,
V_417 ) ;
#ifdef F_200
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_486 ; V_45 ++ )
ASSERT ( F_79 ( & log -> V_183 [ V_45 ] ) ) ;
}
#endif
F_105 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
STATIC int
F_221 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_38 * V_487 ;
error = F_220 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_222 ( log -> V_7 ) ) {
return ( V_58 ) ;
}
F_223 ( log -> V_7 ) ;
V_6 = F_224 ( log -> V_7 , 0 ) ;
F_225 ( V_6 ) ;
ASSERT ( ! ( F_226 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_227 ( V_6 ) ;
V_6 -> V_195 = & V_277 ;
F_16 ( log -> V_7 , V_6 ) ;
error = F_17 ( V_6 ) ;
if ( error ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
return error ;
}
V_487 = & log -> V_7 -> V_25 ;
F_228 ( V_487 , F_229 ( V_6 ) ) ;
ASSERT ( V_487 -> V_488 == V_276 ) ;
ASSERT ( F_230 ( V_487 ) ) ;
F_27 ( V_6 ) ;
F_231 ( log -> V_7 ) ;
F_232 ( log ) ;
log -> V_489 &= ~ V_490 ;
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
if ( ( error = F_233 ( log -> V_7 , L_99 ) ) ) {
return error ;
}
if ( F_234 ( & log -> V_7 -> V_25 ) == V_491 &&
F_235 ( & log -> V_7 -> V_25 ,
V_492 ) ) {
F_3 ( log -> V_7 ,
L_100
L_101
L_102 ,
( log -> V_7 -> V_25 . V_493 &
V_492 ) ) ;
return V_102 ;
}
F_123 ( log -> V_7 , L_103 ,
log -> V_7 -> V_494 ? log -> V_7 -> V_494
: L_104 ) ;
error = F_221 ( log , V_63 , V_72 ) ;
log -> V_489 |= V_495 ;
}
return error ;
}
int
F_236 (
struct V_1 * log )
{
if ( log -> V_489 & V_495 ) {
int error ;
error = F_199 ( log ) ;
if ( error ) {
F_112 ( log -> V_7 , L_105 ) ;
return error ;
}
F_237 ( log -> V_7 , V_496 ) ;
F_211 ( log ) ;
F_232 ( log ) ;
F_123 ( log -> V_7 , L_106 ,
log -> V_7 -> V_494 ? log -> V_7 -> V_494
: L_104 ) ;
log -> V_489 &= ~ V_495 ;
} else {
F_238 ( log -> V_7 , L_107 ) ;
}
return 0 ;
}
void
F_232 (
struct V_1 * log )
{
T_4 * V_23 ;
T_39 * V_497 ;
T_1 * V_498 ;
T_1 * V_447 ;
T_28 V_401 ;
T_27 V_499 ;
T_27 V_500 ;
T_27 V_501 ;
int error ;
V_23 = log -> V_7 ;
V_499 = 0LL ;
V_500 = 0LL ;
V_501 = 0LL ;
for ( V_401 = 0 ; V_401 < V_23 -> V_25 . V_408 ; V_401 ++ ) {
error = F_239 ( V_23 , NULL , V_401 , 0 , & V_498 ) ;
if ( error ) {
F_112 ( V_23 , L_108 ,
V_8 , V_401 , error ) ;
} else {
V_497 = F_240 ( V_498 ) ;
V_499 += F_30 ( V_497 -> V_502 ) +
F_30 ( V_497 -> V_503 ) ;
F_27 ( V_498 ) ;
}
error = F_203 ( V_23 , NULL , V_401 , & V_447 ) ;
if ( error ) {
F_112 ( V_23 , L_109 ,
V_8 , V_401 , error ) ;
} else {
struct V_504 * V_446 = F_204 ( V_447 ) ;
V_500 += F_30 ( V_446 -> V_505 ) ;
V_501 += F_30 ( V_446 -> V_506 ) ;
F_27 ( V_447 ) ;
}
}
}
