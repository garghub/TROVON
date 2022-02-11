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
struct V_125 * V_126 ;
F_70 (trans, n, head, r_list) {
if ( V_124 -> V_127 == V_123 )
return V_124 ;
}
return NULL ;
}
STATIC void
F_71 (
struct V_122 * V_24 ,
T_10 V_123 ,
T_8 V_128 )
{
T_9 * V_124 ;
V_124 = F_72 ( sizeof( T_9 ) , V_129 ) ;
V_124 -> V_127 = V_123 ;
V_124 -> V_130 = V_128 ;
F_73 ( & V_124 -> V_131 ) ;
F_74 ( & V_124 -> V_132 ) ;
F_75 ( & V_124 -> V_132 , V_24 ) ;
}
STATIC void
F_76 (
struct V_133 * V_24 )
{
T_11 * V_134 ;
V_134 = F_72 ( sizeof( T_11 ) , V_129 ) ;
F_73 ( & V_134 -> V_135 ) ;
F_77 ( & V_134 -> V_135 , V_24 ) ;
}
STATIC int
F_78 (
struct V_1 * log ,
struct V_136 * V_124 ,
T_2 V_137 ,
int V_138 )
{
T_11 * V_134 ;
T_2 V_139 , V_140 ;
int V_141 ;
if ( F_79 ( & V_124 -> V_131 ) ) {
F_76 ( & V_124 -> V_131 ) ;
V_139 = ( T_2 ) & V_124 -> V_142 +
sizeof( V_143 ) - V_138 ;
memcpy ( V_139 , V_137 , V_138 ) ;
return 0 ;
}
V_134 = F_80 ( V_124 -> V_131 . V_144 , T_11 , V_135 ) ;
V_140 = V_134 -> V_145 [ V_134 -> V_146 - 1 ] . V_147 ;
V_141 = V_134 -> V_145 [ V_134 -> V_146 - 1 ] . V_148 ;
V_139 = F_81 ( V_140 , V_138 + V_141 , V_141 , V_129 ) ;
memcpy ( & V_139 [ V_141 ] , V_137 , V_138 ) ;
V_134 -> V_145 [ V_134 -> V_146 - 1 ] . V_148 += V_138 ;
V_134 -> V_145 [ V_134 -> V_146 - 1 ] . V_147 = V_139 ;
F_82 ( log , V_124 , V_134 , 0 ) ;
return 0 ;
}
STATIC int
F_83 (
struct V_1 * log ,
struct V_136 * V_124 ,
T_2 V_137 ,
int V_138 )
{
T_12 * V_149 ;
T_11 * V_134 ;
T_2 V_139 ;
if ( ! V_138 )
return 0 ;
if ( F_79 ( & V_124 -> V_131 ) ) {
if ( * ( T_6 * ) V_137 != V_150 ) {
F_3 ( log -> V_7 , L_20 ,
V_8 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
if ( V_138 == sizeof( V_143 ) )
F_76 ( & V_124 -> V_131 ) ;
memcpy ( & V_124 -> V_142 , V_137 , V_138 ) ;
return 0 ;
}
V_139 = F_84 ( V_138 , V_129 ) ;
memcpy ( V_139 , V_137 , V_138 ) ;
V_149 = ( T_12 * ) V_139 ;
V_134 = F_80 ( V_124 -> V_131 . V_144 , T_11 , V_135 ) ;
if ( V_134 -> V_151 != 0 &&
V_134 -> V_151 == V_134 -> V_146 ) {
F_76 ( & V_124 -> V_131 ) ;
V_134 = F_80 ( V_124 -> V_131 . V_144 ,
T_11 , V_135 ) ;
}
if ( V_134 -> V_151 == 0 ) {
if ( V_149 -> V_152 == 0 ||
V_149 -> V_152 > V_153 ) {
F_3 ( log -> V_7 ,
L_21 ,
V_149 -> V_152 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
V_134 -> V_151 = V_149 -> V_152 ;
V_134 -> V_145 =
F_72 ( V_134 -> V_151 * sizeof( V_154 ) ,
V_129 ) ;
}
ASSERT ( V_134 -> V_151 > V_134 -> V_146 ) ;
V_134 -> V_145 [ V_134 -> V_146 ] . V_147 = V_139 ;
V_134 -> V_145 [ V_134 -> V_146 ] . V_148 = V_138 ;
V_134 -> V_146 ++ ;
F_85 ( log , V_124 , V_134 , 0 ) ;
return 0 ;
}
STATIC int
F_86 (
struct V_1 * log ,
struct V_136 * V_124 ,
int V_155 )
{
T_11 * V_134 , * V_126 ;
F_87 ( V_156 ) ;
F_88 ( & V_124 -> V_131 , & V_156 ) ;
F_89 (item, n, &sort_list, ri_list) {
T_13 * V_157 = V_134 -> V_145 [ 0 ] . V_147 ;
switch ( F_90 ( V_134 ) ) {
case V_158 :
if ( ! ( V_157 -> V_159 & V_160 ) ) {
F_91 ( log ,
V_124 , V_134 , V_155 ) ;
F_92 ( & V_134 -> V_135 , & V_124 -> V_131 ) ;
break;
}
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
F_93 ( log ,
V_124 , V_134 , V_155 ) ;
F_94 ( & V_134 -> V_135 , & V_124 -> V_131 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_22 ,
V_8 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
ASSERT ( F_79 ( & V_156 ) ) ;
return 0 ;
}
STATIC int
F_95 (
struct V_1 * log ,
struct V_166 * V_134 )
{
T_13 * V_157 = V_134 -> V_145 [ 0 ] . V_147 ;
struct V_133 * V_167 ;
struct V_168 * V_169 ;
if ( ! ( V_157 -> V_159 & V_160 ) ) {
F_96 ( log , V_157 ) ;
return 0 ;
}
V_167 = F_97 ( log , V_157 -> V_170 ) ;
F_98 (bcp, bucket, bc_list) {
if ( V_169 -> V_171 == V_157 -> V_170 &&
V_169 -> V_172 == V_157 -> V_173 ) {
V_169 -> V_174 ++ ;
F_99 ( log , V_157 ) ;
return 0 ;
}
}
V_169 = F_84 ( sizeof( struct V_168 ) , V_129 ) ;
V_169 -> V_171 = V_157 -> V_170 ;
V_169 -> V_172 = V_157 -> V_173 ;
V_169 -> V_174 = 1 ;
F_77 ( & V_169 -> V_175 , V_167 ) ;
F_100 ( log , V_157 ) ;
return 0 ;
}
STATIC int
F_101 (
struct V_1 * log ,
T_3 V_176 ,
T_6 V_138 ,
T_14 V_177 )
{
struct V_133 * V_167 ;
struct V_168 * V_169 ;
if ( log -> V_178 == NULL ) {
ASSERT ( ! ( V_177 & V_160 ) ) ;
return 0 ;
}
V_167 = F_97 ( log , V_176 ) ;
F_98 (bcp, bucket, bc_list) {
if ( V_169 -> V_171 == V_176 && V_169 -> V_172 == V_138 )
goto V_75;
}
ASSERT ( ! ( V_177 & V_160 ) ) ;
return 0 ;
V_75:
if ( V_177 & V_160 ) {
if ( -- V_169 -> V_174 == 0 ) {
F_102 ( & V_169 -> V_175 ) ;
F_103 ( V_169 ) ;
}
}
return 1 ;
}
STATIC int
F_104 (
struct V_179 * V_23 ,
T_11 * V_134 ,
struct V_5 * V_6 ,
T_13 * V_157 )
{
int V_45 ;
int V_180 = 0 ;
int V_181 = 0 ;
int V_182 = 0 ;
int V_183 = 0 ;
int V_184 = 0 ;
int V_185 ;
int V_186 ;
T_15 * V_187 ;
T_15 * V_188 ;
F_105 ( V_23 -> V_189 , V_157 ) ;
V_186 = F_11 ( V_6 -> V_18 ) >> V_23 -> V_25 . V_190 ;
for ( V_45 = 0 ; V_45 < V_186 ; V_45 ++ ) {
V_185 = ( V_45 * V_23 -> V_25 . V_191 ) +
F_106 ( V_192 , V_193 ) ;
while ( V_185 >=
( V_183 + V_184 ) ) {
V_181 += V_182 ;
V_181 = F_107 ( V_157 -> V_194 ,
V_157 -> V_195 , V_181 ) ;
if ( V_181 == - 1 )
return 0 ;
V_182 = F_108 ( V_157 -> V_194 ,
V_157 -> V_195 , V_181 ) ;
ASSERT ( V_182 > 0 ) ;
V_183 = V_181 << V_196 ;
V_184 = V_182 << V_196 ;
V_180 ++ ;
}
if ( V_185 < V_183 )
continue;
ASSERT ( V_134 -> V_145 [ V_180 ] . V_147 != NULL ) ;
ASSERT ( ( V_134 -> V_145 [ V_180 ] . V_148 % V_197 ) == 0 ) ;
ASSERT ( ( V_183 + V_184 ) <=
F_11 ( V_6 -> V_18 ) ) ;
V_187 = V_134 -> V_145 [ V_180 ] . V_147 +
V_185 - V_183 ;
if ( F_33 ( * V_187 == 0 ) ) {
F_109 ( V_23 ,
L_23
L_24 ,
V_134 , V_6 ) ;
F_4 ( L_25 ,
V_121 , V_23 ) ;
return F_34 ( V_16 ) ;
}
V_188 = ( T_15 * ) F_110 ( V_6 ,
V_185 ) ;
* V_188 = * V_187 ;
}
return 0 ;
}
STATIC void
F_111 (
struct V_179 * V_23 ,
T_11 * V_134 ,
struct V_5 * V_6 ,
T_13 * V_157 )
{
int V_45 ;
int V_181 ;
int V_182 ;
int error ;
F_112 ( V_23 -> V_189 , V_157 ) ;
V_181 = 0 ;
V_45 = 1 ;
while ( 1 ) {
V_181 = F_107 ( V_157 -> V_194 ,
V_157 -> V_195 , V_181 ) ;
if ( V_181 == - 1 )
break;
V_182 = F_108 ( V_157 -> V_194 ,
V_157 -> V_195 , V_181 ) ;
ASSERT ( V_182 > 0 ) ;
ASSERT ( V_134 -> V_145 [ V_45 ] . V_147 != NULL ) ;
ASSERT ( V_134 -> V_145 [ V_45 ] . V_148 % V_197 == 0 ) ;
ASSERT ( F_11 ( V_6 -> V_18 ) >=
( ( T_6 ) V_181 << V_196 ) + ( V_182 << V_196 ) ) ;
error = 0 ;
if ( V_157 -> V_159 &
( V_198 | V_199 | V_200 ) ) {
if ( V_134 -> V_145 [ V_45 ] . V_147 == NULL ) {
F_109 ( V_23 ,
L_26 , V_8 ) ;
goto V_201;
}
if ( V_134 -> V_145 [ V_45 ] . V_148 < sizeof( V_202 ) ) {
F_109 ( V_23 ,
L_27 ,
V_134 -> V_145 [ V_45 ] . V_148 , V_8 ) ;
goto V_201;
}
error = F_113 ( V_23 , V_134 -> V_145 [ V_45 ] . V_147 ,
- 1 , 0 , V_203 ,
L_28 ) ;
if ( error )
goto V_201;
}
memcpy ( F_110 ( V_6 ,
( T_6 ) V_181 << V_196 ) ,
V_134 -> V_145 [ V_45 ] . V_147 ,
V_182 << V_196 ) ;
V_201:
V_45 ++ ;
V_181 += V_182 ;
}
ASSERT ( V_45 == V_134 -> V_151 ) ;
}
int
F_113 (
struct V_179 * V_23 ,
V_202 * V_204 ,
T_16 V_205 ,
T_6 type ,
T_6 V_177 ,
char * V_206 )
{
T_17 * V_207 = ( T_17 * ) V_204 ;
int V_208 = 0 ;
if ( V_204 -> V_209 != F_114 ( V_210 ) ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_29 ,
V_206 , V_205 , F_115 ( V_204 -> V_209 ) , V_210 ) ;
V_208 ++ ;
}
if ( V_204 -> V_211 != V_212 ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_30 ,
V_206 , V_205 , V_204 -> V_211 , V_212 ) ;
V_208 ++ ;
}
if ( V_204 -> V_213 != V_214 &&
V_204 -> V_213 != V_215 &&
V_204 -> V_213 != V_216 ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_31 ,
V_206 , V_205 , V_204 -> V_213 ) ;
V_208 ++ ;
}
if ( V_205 != - 1 && V_205 != F_30 ( V_204 -> V_217 ) ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_32
L_33 ,
V_206 , V_204 , V_205 , F_30 ( V_204 -> V_217 ) ) ;
V_208 ++ ;
}
if ( ! V_208 && V_204 -> V_217 ) {
if ( V_204 -> V_218 &&
F_56 ( V_204 -> V_219 ) >
F_56 ( V_204 -> V_218 ) ) {
if ( ! V_204 -> V_220 ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_34 ,
V_206 , ( int ) F_30 ( V_204 -> V_217 ) , V_204 ) ;
V_208 ++ ;
}
}
if ( V_204 -> V_221 &&
F_56 ( V_204 -> V_222 ) >
F_56 ( V_204 -> V_221 ) ) {
if ( ! V_204 -> V_223 ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_35 ,
V_206 , ( int ) F_30 ( V_204 -> V_217 ) , V_204 ) ;
V_208 ++ ;
}
}
if ( V_204 -> V_224 &&
F_56 ( V_204 -> V_225 ) >
F_56 ( V_204 -> V_224 ) ) {
if ( ! V_204 -> V_226 ) {
if ( V_177 & V_203 )
F_109 ( V_23 ,
L_36 ,
V_206 , ( int ) F_30 ( V_204 -> V_217 ) , V_204 ) ;
V_208 ++ ;
}
}
}
if ( ! V_208 || ! ( V_177 & V_227 ) )
return V_208 ;
if ( V_177 & V_203 )
F_116 ( V_23 , L_37 , V_205 ) ;
ASSERT ( V_205 != - 1 ) ;
ASSERT ( V_177 & V_227 ) ;
memset ( V_207 , 0 , sizeof( T_17 ) ) ;
V_207 -> V_228 . V_209 = F_114 ( V_210 ) ;
V_207 -> V_228 . V_211 = V_212 ;
V_207 -> V_228 . V_213 = type ;
V_207 -> V_228 . V_217 = F_32 ( V_205 ) ;
return V_208 ;
}
STATIC void
F_117 (
struct V_179 * V_23 ,
struct V_1 * log ,
struct V_166 * V_134 ,
struct V_5 * V_6 ,
struct V_229 * V_157 )
{
T_6 type ;
F_118 ( log , V_157 ) ;
if ( V_23 -> V_230 == 0 ) {
return;
}
type = 0 ;
if ( V_157 -> V_159 & V_198 )
type |= V_214 ;
if ( V_157 -> V_159 & V_199 )
type |= V_215 ;
if ( V_157 -> V_159 & V_200 )
type |= V_216 ;
if ( log -> V_231 & type )
return;
F_111 ( V_23 , V_134 , V_6 , V_157 ) ;
}
STATIC int
F_119 (
struct V_1 * log ,
struct V_133 * V_232 ,
struct V_166 * V_134 )
{
T_13 * V_157 = V_134 -> V_145 [ 0 ] . V_147 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_233 ;
if ( F_101 ( log , V_157 -> V_170 ,
V_157 -> V_173 , V_157 -> V_159 ) ) {
F_120 ( log , V_157 ) ;
return 0 ;
}
F_121 ( log , V_157 ) ;
V_233 = 0 ;
if ( V_157 -> V_159 & V_234 )
V_233 |= V_235 ;
V_6 = F_122 ( V_23 -> V_236 , V_157 -> V_170 , V_157 -> V_173 ,
V_233 , NULL ) ;
if ( ! V_6 )
return F_34 ( V_49 ) ;
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_38 ) ;
F_27 ( V_6 ) ;
return error ;
}
if ( V_157 -> V_159 & V_234 ) {
error = F_104 ( V_23 , V_134 , V_6 , V_157 ) ;
} else if ( V_157 -> V_159 &
( V_198 | V_199 | V_200 ) ) {
F_117 ( V_23 , log , V_134 , V_6 , V_157 ) ;
} else {
F_111 ( V_23 , V_134 , V_6 , V_157 ) ;
}
if ( error )
return F_34 ( error ) ;
if ( V_237 ==
F_115 ( * ( ( V_238 * ) F_110 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_123 ( log -> V_7 -> V_25 . V_239 ,
( V_240 ) F_124 ( log -> V_7 ) ) ) ) {
F_125 ( V_6 ) ;
error = F_26 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_126 ( V_6 , V_232 ) ;
}
F_27 ( V_6 ) ;
return error ;
}
STATIC int
F_127 (
struct V_1 * log ,
struct V_133 * V_232 ,
struct V_166 * V_134 )
{
T_12 * V_149 ;
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
V_192 * V_241 ;
int V_138 ;
T_2 V_242 ;
T_2 V_243 ;
int error ;
int V_244 ;
T_6 V_245 ;
T_18 * V_246 ;
int V_247 = 0 ;
if ( V_134 -> V_145 [ 0 ] . V_148 == sizeof( T_12 ) ) {
V_149 = V_134 -> V_145 [ 0 ] . V_147 ;
} else {
V_149 = F_84 ( sizeof( T_12 ) , V_129 ) ;
V_247 = 1 ;
error = F_128 ( & V_134 -> V_145 [ 0 ] , V_149 ) ;
if ( error )
goto error;
}
if ( F_101 ( log , V_149 -> V_248 ,
V_149 -> V_249 , 0 ) ) {
error = 0 ;
F_129 ( log , V_149 ) ;
goto error;
}
F_130 ( log , V_149 ) ;
V_6 = F_122 ( V_23 -> V_236 , V_149 -> V_248 , V_149 -> V_249 , 0 ,
NULL ) ;
if ( ! V_6 ) {
error = V_49 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_18 ( V_6 , L_39 ) ;
F_27 ( V_6 ) ;
goto error;
}
ASSERT ( V_149 -> V_250 & V_251 ) ;
V_241 = ( V_192 * ) F_110 ( V_6 , V_149 -> V_252 ) ;
if ( F_33 ( V_241 -> V_253 != F_114 ( V_237 ) ) ) {
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_40 ,
V_8 , V_241 , V_6 , V_149 -> V_254 ) ;
F_4 ( L_41 ,
V_121 , V_23 ) ;
error = V_16 ;
goto error;
}
V_246 = V_134 -> V_145 [ 1 ] . V_147 ;
if ( F_33 ( V_246 -> V_253 != V_237 ) ) {
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_42 ,
V_8 , V_134 , V_149 -> V_254 ) ;
F_4 ( L_43 ,
V_121 , V_23 ) ;
error = V_16 ;
goto error;
}
if ( V_246 -> V_255 < F_115 ( V_241 -> V_255 ) ) {
if ( F_115 ( V_241 -> V_255 ) == V_256 &&
V_246 -> V_255 < ( V_256 >> 1 ) ) {
} else {
F_27 ( V_6 ) ;
F_131 ( log , V_149 ) ;
error = 0 ;
goto error;
}
}
V_246 -> V_255 = 0 ;
if ( F_33 ( F_132 ( V_246 -> V_257 ) ) ) {
if ( ( V_246 -> V_258 != V_259 ) &&
( V_246 -> V_258 != V_260 ) ) {
F_133 ( L_44 ,
V_121 , V_23 , V_246 ) ;
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_45
L_46 ,
V_8 , V_134 , V_241 , V_6 , V_149 -> V_254 ) ;
error = V_16 ;
goto error;
}
} else if ( F_33 ( F_134 ( V_246 -> V_257 ) ) ) {
if ( ( V_246 -> V_258 != V_259 ) &&
( V_246 -> V_258 != V_260 ) &&
( V_246 -> V_258 != V_261 ) ) {
F_133 ( L_47 ,
V_121 , V_23 , V_246 ) ;
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_48
L_46 ,
V_8 , V_134 , V_241 , V_6 , V_149 -> V_254 ) ;
error = V_16 ;
goto error;
}
}
if ( F_33 ( V_246 -> V_262 + V_246 -> V_263 > V_246 -> V_264 ) ) {
F_133 ( L_49 ,
V_121 , V_23 , V_246 ) ;
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_50
L_51 ,
V_8 , V_134 , V_241 , V_6 , V_149 -> V_254 ,
V_246 -> V_262 + V_246 -> V_263 ,
V_246 -> V_264 ) ;
error = V_16 ;
goto error;
}
if ( F_33 ( V_246 -> V_265 > V_23 -> V_25 . V_191 ) ) {
F_133 ( L_52 ,
V_121 , V_23 , V_246 ) ;
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_50
L_53 , V_8 ,
V_134 , V_241 , V_6 , V_149 -> V_254 , V_246 -> V_265 ) ;
error = V_16 ;
goto error;
}
if ( F_33 ( V_134 -> V_145 [ 1 ] . V_148 > sizeof( struct V_266 ) ) ) {
F_133 ( L_54 ,
V_121 , V_23 , V_246 ) ;
F_27 ( V_6 ) ;
F_109 ( V_23 ,
L_55 ,
V_8 , V_134 -> V_145 [ 1 ] . V_148 , V_134 ) ;
error = V_16 ;
goto error;
}
F_135 ( V_241 , V_134 -> V_145 [ 1 ] . V_147 ) ;
if ( V_134 -> V_145 [ 1 ] . V_148 > sizeof( struct V_266 ) ) {
memcpy ( ( T_2 ) V_241 + sizeof( struct V_266 ) ,
V_134 -> V_145 [ 1 ] . V_147 + sizeof( struct V_266 ) ,
V_134 -> V_145 [ 1 ] . V_148 - sizeof( struct V_266 ) ) ;
}
V_245 = V_149 -> V_250 ;
switch ( V_245 & ( V_267 | V_268 ) ) {
case V_267 :
F_136 ( V_241 , V_149 -> V_269 . V_270 ) ;
break;
case V_268 :
memcpy ( F_137 ( V_241 ) ,
& V_149 -> V_269 . V_271 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_149 -> V_152 == 2 )
goto V_272;
V_138 = V_134 -> V_145 [ 2 ] . V_148 ;
V_242 = V_134 -> V_145 [ 2 ] . V_147 ;
ASSERT ( V_149 -> V_152 <= 4 ) ;
ASSERT ( ( V_149 -> V_152 == 3 ) || ( V_245 & V_273 ) ) ;
ASSERT ( ! ( V_245 & V_274 ) ||
( V_138 == V_149 -> V_275 ) ) ;
switch ( V_245 & V_274 ) {
case V_276 :
case V_277 :
memcpy ( F_137 ( V_241 ) , V_242 , V_138 ) ;
break;
case V_278 :
F_138 ( V_23 , (struct V_279 * ) V_242 , V_138 ,
( V_280 * ) F_137 ( V_241 ) ,
F_139 ( V_241 , V_23 ) ) ;
break;
default:
ASSERT ( ( V_245 & V_274 ) == 0 ) ;
break;
}
if ( V_149 -> V_250 & V_273 ) {
if ( V_149 -> V_250 & V_274 ) {
V_244 = 3 ;
} else {
V_244 = 2 ;
}
V_138 = V_134 -> V_145 [ V_244 ] . V_148 ;
V_242 = V_134 -> V_145 [ V_244 ] . V_147 ;
ASSERT ( V_138 == V_149 -> V_281 ) ;
switch ( V_149 -> V_250 & V_273 ) {
case V_282 :
case V_283 :
V_243 = F_140 ( V_241 ) ;
ASSERT ( V_138 <= F_141 ( V_241 , V_23 ) ) ;
memcpy ( V_243 , V_242 , V_138 ) ;
break;
case V_284 :
V_243 = F_140 ( V_241 ) ;
F_138 ( V_23 , (struct V_279 * ) V_242 ,
V_138 , ( V_280 * ) V_243 ,
F_141 ( V_241 , V_23 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_56 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
error = V_58 ;
goto error;
}
}
V_272:
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_126 ( V_6 , V_232 ) ;
F_27 ( V_6 ) ;
error:
if ( V_247 )
F_103 ( V_149 ) ;
return F_34 ( error ) ;
}
STATIC int
F_142 (
struct V_1 * log ,
struct V_166 * V_134 )
{
T_19 * V_285 = V_134 -> V_145 [ 0 ] . V_147 ;
ASSERT ( V_285 ) ;
if ( V_285 -> V_286 & V_287 )
log -> V_231 |= V_214 ;
if ( V_285 -> V_286 & V_288 )
log -> V_231 |= V_215 ;
if ( V_285 -> V_286 & V_289 )
log -> V_231 |= V_216 ;
return ( 0 ) ;
}
STATIC int
F_143 (
struct V_1 * log ,
struct V_133 * V_232 ,
struct V_166 * V_134 )
{
T_4 * V_23 = log -> V_7 ;
T_1 * V_6 ;
struct V_290 * V_204 , * V_291 ;
int error ;
T_20 * V_292 ;
T_6 type ;
if ( V_23 -> V_230 == 0 )
return ( 0 ) ;
V_291 = V_134 -> V_145 [ 1 ] . V_147 ;
if ( V_291 == NULL ) {
F_109 ( log -> V_7 , L_57 , V_8 ) ;
return F_34 ( V_58 ) ;
}
if ( V_134 -> V_145 [ 1 ] . V_148 < sizeof( V_202 ) ) {
F_109 ( log -> V_7 , L_58 ,
V_134 -> V_145 [ 1 ] . V_148 , V_8 ) ;
return F_34 ( V_58 ) ;
}
type = V_291 -> V_213 & ( V_214 | V_215 | V_216 ) ;
ASSERT ( type ) ;
if ( log -> V_231 & type )
return ( 0 ) ;
V_292 = V_134 -> V_145 [ 0 ] . V_147 ;
ASSERT ( V_292 ) ;
error = F_113 ( V_23 , V_291 , V_292 -> V_293 , 0 , V_203 ,
L_59 ) ;
if ( error )
return F_34 ( V_58 ) ;
ASSERT ( V_292 -> V_294 == 1 ) ;
error = F_144 ( V_23 , NULL , V_23 -> V_236 , V_292 -> V_295 ,
F_145 ( V_23 , V_292 -> V_294 ) , 0 , & V_6 ,
NULL ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_204 = ( V_202 * ) F_110 ( V_6 , V_292 -> V_296 ) ;
error = F_113 ( V_23 , V_204 , V_292 -> V_293 , 0 , V_203 ,
L_60 ) ;
if ( error ) {
F_27 ( V_6 ) ;
return F_34 ( V_58 ) ;
}
memcpy ( V_204 , V_291 , V_134 -> V_145 [ 1 ] . V_148 ) ;
ASSERT ( V_292 -> V_297 == 2 ) ;
ASSERT ( V_6 -> V_32 -> V_33 == V_23 ) ;
V_6 -> V_35 = F_38 ;
F_126 ( V_6 , V_232 ) ;
F_27 ( V_6 ) ;
return ( 0 ) ;
}
STATIC int
F_146 (
struct V_1 * log ,
struct V_166 * V_134 ,
T_8 V_128 )
{
int error ;
T_4 * V_23 = log -> V_7 ;
T_21 * V_298 ;
T_22 * V_299 ;
V_299 = V_134 -> V_145 [ 0 ] . V_147 ;
V_298 = F_147 ( V_23 , V_299 -> V_300 ) ;
if ( ( error = F_148 ( & ( V_134 -> V_145 [ 0 ] ) ,
& ( V_298 -> V_301 ) ) ) ) {
F_149 ( V_298 ) ;
return error ;
}
F_150 ( & V_298 -> V_302 , V_299 -> V_300 ) ;
F_151 ( & log -> V_303 -> V_304 ) ;
F_152 ( log -> V_303 , & V_298 -> V_305 , V_128 ) ;
return 0 ;
}
STATIC int
F_153 (
struct V_1 * log ,
struct V_166 * V_134 )
{
T_23 * V_306 ;
T_21 * V_298 = NULL ;
T_24 * V_307 ;
T_25 V_308 ;
struct V_309 V_310 ;
struct V_311 * V_312 = log -> V_303 ;
V_306 = V_134 -> V_145 [ 0 ] . V_147 ;
ASSERT ( ( V_134 -> V_145 [ 0 ] . V_148 == ( sizeof( V_313 ) +
( ( V_306 -> V_314 - 1 ) * sizeof( V_315 ) ) ) ) ||
( V_134 -> V_145 [ 0 ] . V_148 == ( sizeof( V_316 ) +
( ( V_306 -> V_314 - 1 ) * sizeof( V_317 ) ) ) ) ) ;
V_308 = V_306 -> V_318 ;
F_151 ( & V_312 -> V_304 ) ;
V_307 = F_154 ( V_312 , & V_310 , 0 ) ;
while ( V_307 != NULL ) {
if ( V_307 -> V_319 == V_165 ) {
V_298 = ( T_21 * ) V_307 ;
if ( V_298 -> V_301 . V_308 == V_308 ) {
F_155 ( V_312 , V_307 ,
V_320 ) ;
F_149 ( V_298 ) ;
F_151 ( & V_312 -> V_304 ) ;
break;
}
}
V_307 = F_156 ( V_312 , & V_310 ) ;
}
F_157 ( V_312 , & V_310 ) ;
F_158 ( & V_312 -> V_304 ) ;
return 0 ;
}
STATIC void
F_159 (
struct V_136 * V_124 )
{
T_11 * V_134 , * V_126 ;
int V_45 ;
F_89 (item, n, &trans->r_itemq, ri_list) {
F_102 ( & V_134 -> V_135 ) ;
for ( V_45 = 0 ; V_45 < V_134 -> V_146 ; V_45 ++ )
F_103 ( V_134 -> V_145 [ V_45 ] . V_147 ) ;
F_103 ( V_134 -> V_145 ) ;
F_103 ( V_134 ) ;
}
F_103 ( V_124 ) ;
}
STATIC int
F_160 (
struct V_1 * log ,
struct V_136 * V_124 ,
struct V_166 * V_134 )
{
F_161 ( log , V_124 , V_134 , V_321 ) ;
switch ( F_90 ( V_134 ) ) {
case V_158 :
return F_95 ( log , V_134 ) ;
case V_163 :
return F_142 ( log , V_134 ) ;
case V_161 :
case V_165 :
case V_164 :
case V_162 :
return 0 ;
default:
F_3 ( log -> V_7 , L_61 ,
V_8 , F_90 ( V_134 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_162 (
struct V_1 * log ,
struct V_136 * V_124 ,
struct V_133 * V_232 ,
struct V_166 * V_134 )
{
F_161 ( log , V_124 , V_134 , V_322 ) ;
switch ( F_90 ( V_134 ) ) {
case V_158 :
return F_119 ( log , V_232 , V_134 ) ;
case V_161 :
return F_127 ( log , V_232 , V_134 ) ;
case V_165 :
return F_146 ( log , V_134 , V_124 -> V_130 ) ;
case V_164 :
return F_153 ( log , V_134 ) ;
case V_162 :
return F_143 ( log , V_232 , V_134 ) ;
case V_163 :
return 0 ;
default:
F_3 ( log -> V_7 , L_61 ,
V_8 , F_90 ( V_134 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_58 ) ;
}
}
STATIC int
F_163 (
struct V_1 * log ,
struct V_136 * V_124 ,
int V_155 )
{
int error = 0 , V_22 ;
T_11 * V_134 ;
F_87 ( V_232 ) ;
F_164 ( & V_124 -> V_132 ) ;
error = F_86 ( log , V_124 , V_155 ) ;
if ( error )
return error ;
F_98 (item, &trans->r_itemq, ri_list) {
switch ( V_155 ) {
case V_321 :
error = F_160 ( log , V_124 , V_134 ) ;
break;
case V_322 :
error = F_162 ( log , V_124 ,
& V_232 , V_134 ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_51;
}
F_159 ( V_124 ) ;
V_51:
V_22 = F_165 ( & V_232 ) ;
return error ? error : V_22 ;
}
STATIC int
F_166 (
struct V_1 * log ,
struct V_136 * V_124 )
{
F_3 ( log -> V_7 , L_62 , V_8 ) ;
return 0 ;
}
STATIC int
F_167 (
struct V_1 * log ,
struct V_122 V_323 [] ,
struct V_324 * V_73 ,
T_2 V_137 ,
int V_155 )
{
T_2 V_325 ;
int V_326 ;
T_7 * V_327 ;
T_9 * V_124 ;
T_10 V_123 ;
int error ;
unsigned long V_328 ;
T_6 V_177 ;
V_325 = V_137 + F_30 ( V_73 -> V_61 ) ;
V_326 = F_30 ( V_73 -> V_95 ) ;
if ( F_31 ( log -> V_7 , V_73 ) )
return ( F_34 ( V_58 ) ) ;
while ( ( V_137 < V_325 ) && V_326 ) {
ASSERT ( V_137 + sizeof( T_7 ) <= V_325 ) ;
V_327 = ( T_7 * ) V_137 ;
V_137 += sizeof( T_7 ) ;
if ( V_327 -> V_329 != V_330 &&
V_327 -> V_329 != V_331 ) {
F_3 ( log -> V_7 , L_63 ,
V_8 , V_327 -> V_329 ) ;
ASSERT ( 0 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_123 = F_30 ( V_327 -> V_332 ) ;
V_328 = F_168 ( V_123 ) ;
V_124 = F_69 ( & V_323 [ V_328 ] , V_123 ) ;
if ( V_124 == NULL ) {
if ( V_327 -> V_96 & V_333 )
F_71 ( & V_323 [ V_328 ] , V_123 ,
F_56 ( V_73 -> V_89 ) ) ;
} else {
if ( V_137 + F_30 ( V_327 -> V_334 ) > V_325 ) {
F_3 ( log -> V_7 , L_64 ,
V_8 , F_30 ( V_327 -> V_334 ) ) ;
F_169 ( 1 ) ;
return ( F_34 ( V_58 ) ) ;
}
V_177 = V_327 -> V_96 & ~ V_335 ;
if ( V_177 & V_336 )
V_177 &= ~ V_337 ;
switch ( V_177 ) {
case V_338 :
error = F_163 ( log ,
V_124 , V_155 ) ;
break;
case V_97 :
error = F_166 ( log , V_124 ) ;
break;
case V_336 :
error = F_78 ( log ,
V_124 , V_137 ,
F_30 ( V_327 -> V_334 ) ) ;
break;
case V_333 :
F_3 ( log -> V_7 , L_65 ,
V_8 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
case 0 :
case V_337 :
error = F_83 ( log , V_124 ,
V_137 , F_30 ( V_327 -> V_334 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_66 ,
V_8 , V_177 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_58 ) ;
break;
}
if ( error )
return error ;
}
V_137 += F_30 ( V_327 -> V_334 ) ;
V_326 -- ;
}
return 0 ;
}
STATIC int
F_170 (
T_4 * V_23 ,
T_21 * V_298 )
{
T_26 * V_339 ;
T_27 * V_340 ;
int V_45 ;
int error = 0 ;
T_28 * V_341 ;
T_29 V_342 ;
ASSERT ( ! F_171 ( V_343 , & V_298 -> V_344 ) ) ;
for ( V_45 = 0 ; V_45 < V_298 -> V_301 . V_300 ; V_45 ++ ) {
V_341 = & ( V_298 -> V_301 . V_345 [ V_45 ] ) ;
V_342 = F_172 ( V_23 ,
F_173 ( V_23 , V_341 -> V_346 ) ) ;
if ( ( V_342 == 0 ) ||
( V_341 -> V_347 == 0 ) ||
( V_342 >= V_23 -> V_25 . V_348 ) ||
( V_341 -> V_347 >= V_23 -> V_25 . V_349 ) ) {
F_174 ( V_298 , V_298 -> V_301 . V_300 ) ;
return F_34 ( V_58 ) ;
}
}
V_340 = F_175 ( V_23 , 0 ) ;
error = F_176 ( V_340 , 0 , F_177 ( V_23 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_350;
V_339 = F_178 ( V_340 , V_298 , V_298 -> V_301 . V_300 ) ;
for ( V_45 = 0 ; V_45 < V_298 -> V_301 . V_300 ; V_45 ++ ) {
V_341 = & ( V_298 -> V_301 . V_345 [ V_45 ] ) ;
error = F_179 ( V_340 , V_341 -> V_346 , V_341 -> V_347 ) ;
if ( error )
goto V_350;
F_180 ( V_340 , V_339 , V_341 -> V_346 ,
V_341 -> V_347 ) ;
}
F_181 ( V_343 , & V_298 -> V_344 ) ;
error = F_182 ( V_340 , 0 ) ;
return error ;
V_350:
F_183 ( V_340 , V_351 ) ;
return error ;
}
STATIC int
F_184 (
struct V_1 * log )
{
T_24 * V_307 ;
T_21 * V_298 ;
int error = 0 ;
struct V_309 V_310 ;
struct V_311 * V_312 ;
V_312 = log -> V_303 ;
F_151 ( & V_312 -> V_304 ) ;
V_307 = F_154 ( V_312 , & V_310 , 0 ) ;
while ( V_307 != NULL ) {
if ( V_307 -> V_319 != V_165 ) {
#ifdef F_185
for (; V_307 ; V_307 = F_156 ( V_312 , & V_310 ) )
ASSERT ( V_307 -> V_319 != V_165 ) ;
#endif
break;
}
V_298 = ( T_21 * ) V_307 ;
if ( F_171 ( V_343 , & V_298 -> V_344 ) ) {
V_307 = F_156 ( V_312 , & V_310 ) ;
continue;
}
F_158 ( & V_312 -> V_304 ) ;
error = F_170 ( log -> V_7 , V_298 ) ;
F_151 ( & V_312 -> V_304 ) ;
if ( error )
goto V_51;
V_307 = F_156 ( V_312 , & V_310 ) ;
}
V_51:
F_157 ( V_312 , & V_310 ) ;
F_158 ( & V_312 -> V_304 ) ;
return error ;
}
STATIC void
F_186 (
T_4 * V_23 ,
T_30 V_352 ,
int V_167 )
{
T_27 * V_340 ;
T_31 * V_353 ;
T_1 * V_354 ;
int V_13 ;
int error ;
V_340 = F_175 ( V_23 , V_355 ) ;
error = F_176 ( V_340 , 0 , F_187 ( V_23 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_356;
error = F_188 ( V_23 , V_340 , V_352 , & V_354 ) ;
if ( error )
goto V_356;
V_353 = F_189 ( V_354 ) ;
V_353 -> V_357 [ V_167 ] = F_32 ( V_358 ) ;
V_13 = F_106 ( T_31 , V_357 ) +
( sizeof( T_15 ) * V_167 ) ;
F_190 ( V_340 , V_354 , V_13 ,
( V_13 + sizeof( T_15 ) - 1 ) ) ;
error = F_182 ( V_340 , 0 ) ;
if ( error )
goto V_359;
return;
V_356:
F_183 ( V_340 , V_351 ) ;
V_359:
F_3 ( V_23 , L_67 , V_8 , V_352 ) ;
return;
}
STATIC T_15
F_191 (
struct V_179 * V_23 ,
T_30 V_352 ,
T_15 V_360 ,
int V_167 )
{
struct V_5 * V_361 ;
struct V_362 * V_241 ;
struct V_363 * V_364 ;
T_32 V_365 ;
int error ;
V_365 = F_192 ( V_23 , V_352 , V_360 ) ;
error = F_193 ( V_23 , NULL , V_365 , 0 , 0 , & V_364 ) ;
if ( error )
goto V_366;
error = F_194 ( V_23 , NULL , & V_364 -> V_367 , & V_241 , & V_361 , 0 , 0 ) ;
if ( error )
goto V_368;
ASSERT ( V_364 -> V_369 . V_370 == 0 ) ;
ASSERT ( V_364 -> V_369 . V_257 != 0 ) ;
V_360 = F_30 ( V_241 -> V_193 ) ;
F_27 ( V_361 ) ;
V_364 -> V_369 . V_371 = 0 ;
F_195 ( V_364 ) ;
return V_360 ;
V_368:
F_195 ( V_364 ) ;
V_366:
F_186 ( V_23 , V_352 , V_167 ) ;
return V_358 ;
}
STATIC void
F_196 (
struct V_1 * log )
{
T_4 * V_23 ;
T_30 V_352 ;
T_31 * V_353 ;
T_1 * V_354 ;
T_15 V_360 ;
int V_167 ;
int error ;
T_6 V_372 ;
V_23 = log -> V_7 ;
V_372 = V_23 -> V_373 ;
V_23 -> V_373 = 0 ;
for ( V_352 = 0 ; V_352 < V_23 -> V_25 . V_374 ; V_352 ++ ) {
error = F_188 ( V_23 , NULL , V_352 , & V_354 ) ;
if ( error ) {
continue;
}
V_353 = F_189 ( V_354 ) ;
F_7 ( V_354 ) ;
for ( V_167 = 0 ; V_167 < V_375 ; V_167 ++ ) {
V_360 = F_30 ( V_353 -> V_357 [ V_167 ] ) ;
while ( V_360 != V_358 ) {
V_360 = F_191 ( V_23 ,
V_352 , V_360 , V_167 ) ;
}
}
F_197 ( V_354 ) ;
}
V_23 -> V_373 = V_372 ;
}
STATIC int
F_198 (
struct V_324 * V_73 ,
T_2 V_137 ,
struct V_1 * log )
{
T_33 V_376 ;
V_376 = F_199 ( log , V_73 , V_137 , F_30 ( V_73 -> V_61 ) ) ;
if ( V_376 != V_73 -> V_377 ) {
if ( V_73 -> V_377 || F_200 ( & log -> V_7 -> V_25 ) ) {
F_109 ( log -> V_7 ,
L_68 ,
F_201 ( V_73 -> V_377 ) ,
F_201 ( V_376 ) ) ;
F_202 ( V_137 , 32 ) ;
}
if ( F_200 ( & log -> V_7 -> V_25 ) )
return V_16 ;
}
return 0 ;
}
STATIC int
F_203 (
struct V_324 * V_73 ,
T_2 V_137 ,
struct V_1 * log )
{
int V_45 , V_46 , V_378 ;
int error ;
error = F_198 ( V_73 , V_137 , log ) ;
if ( error )
return error ;
for ( V_45 = 0 ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) &&
V_45 < ( V_60 / V_52 ) ; V_45 ++ ) {
* ( V_81 * ) V_137 = * ( V_81 * ) & V_73 -> V_379 [ V_45 ] ;
V_137 += V_52 ;
}
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
T_34 * V_380 = ( T_34 * ) V_73 ;
for ( ; V_45 < F_49 ( F_30 ( V_73 -> V_61 ) ) ; V_45 ++ ) {
V_46 = V_45 / ( V_60 / V_52 ) ;
V_378 = V_45 % ( V_60 / V_52 ) ;
* ( V_81 * ) V_137 = V_380 [ V_46 ] . V_381 . V_382 [ V_378 ] ;
V_137 += V_52 ;
}
}
return 0 ;
}
STATIC int
F_204 (
struct V_1 * log ,
struct V_324 * V_73 ,
T_3 V_176 )
{
int V_383 ;
if ( F_33 ( V_73 -> V_30 != F_32 ( V_31 ) ) ) {
F_4 ( L_69 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 (
( ! V_73 -> V_93 ||
( F_30 ( V_73 -> V_93 ) & ( ~ V_384 ) ) ) ) ) {
F_3 ( log -> V_7 , L_70 ,
V_8 , F_30 ( V_73 -> V_93 ) ) ;
return F_34 ( V_58 ) ;
}
V_383 = F_30 ( V_73 -> V_61 ) ;
if ( F_33 ( V_383 <= 0 || V_383 > V_70 ) ) {
F_4 ( L_71 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
if ( F_33 ( V_176 > log -> V_3 || V_176 > V_70 ) ) {
F_4 ( L_72 ,
V_121 , log -> V_7 ) ;
return F_34 ( V_16 ) ;
}
return 0 ;
}
STATIC int
F_205 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_155 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_385 , * V_386 ;
int error = 0 , V_59 ;
int V_387 , V_388 ;
int V_79 , V_389 , V_390 ;
struct V_122 V_323 [ V_391 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_48 ( & log -> V_7 -> V_25 ) ) {
V_385 = F_2 ( log , 1 ) ;
if ( ! V_385 )
return V_49 ;
error = F_19 ( log , V_72 , 1 , V_385 , & V_13 ) ;
if ( error )
goto V_392;
V_73 = ( T_5 * ) V_13 ;
error = F_204 ( log , V_73 , V_72 ) ;
if ( error )
goto V_392;
V_59 = F_30 ( V_73 -> V_59 ) ;
if ( ( F_30 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_385 ) ;
V_385 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_385 = F_2 ( log , 1 ) ;
V_59 = V_393 ;
}
if ( ! V_385 )
return V_49 ;
V_386 = F_2 ( log , F_49 ( V_59 ) ) ;
if ( ! V_386 ) {
F_8 ( V_385 ) ;
return V_49 ;
}
memset ( V_323 , 0 , sizeof( V_323 ) ) ;
if ( V_72 <= V_63 ) {
for ( V_12 = V_72 ; V_12 < V_63 ; ) {
error = F_19 ( log , V_12 , V_79 , V_385 , & V_13 ) ;
if ( error )
goto V_394;
V_73 = ( T_5 * ) V_13 ;
error = F_204 ( log , V_73 , V_12 ) ;
if ( error )
goto V_394;
V_387 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_387 , V_386 ,
& V_13 ) ;
if ( error )
goto V_394;
error = F_203 ( V_73 , V_13 , log ) ;
if ( error )
goto V_394;
error = F_167 ( log ,
V_323 , V_73 , V_13 , V_155 ) ;
if ( error )
goto V_394;
V_12 += V_387 + V_79 ;
}
} else {
V_12 = V_72 ;
while ( V_12 < log -> V_3 ) {
V_13 = V_385 -> V_15 ;
V_389 = 0 ;
V_390 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_79 , V_385 ,
& V_13 ) ;
if ( error )
goto V_394;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_389 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_389 > 0 ) ;
error = F_19 ( log , V_12 ,
V_389 , V_385 ,
& V_13 ) ;
if ( error )
goto V_394;
}
V_390 = V_79 - V_389 ;
error = F_20 ( log , 0 ,
V_390 , V_385 ,
V_13 + F_11 ( V_389 ) ) ;
if ( error )
goto V_394;
}
V_73 = ( T_5 * ) V_13 ;
error = F_204 ( log , V_73 ,
V_389 ? V_12 : 0 ) ;
if ( error )
goto V_394;
V_387 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_387 <= log -> V_3 ) {
error = F_19 ( log , V_12 , V_387 , V_386 ,
& V_13 ) ;
if ( error )
goto V_394;
} else {
V_13 = V_386 -> V_15 ;
V_388 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_390 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_388 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_388 > 0 ) ;
error = F_19 ( log , V_12 ,
V_388 , V_386 ,
& V_13 ) ;
if ( error )
goto V_394;
}
error = F_20 ( log , 0 ,
V_387 - V_388 , V_386 ,
V_13 + F_11 ( V_388 ) ) ;
if ( error )
goto V_394;
}
error = F_203 ( V_73 , V_13 , log ) ;
if ( error )
goto V_394;
error = F_167 ( log , V_323 ,
V_73 , V_13 , V_155 ) ;
if ( error )
goto V_394;
V_12 += V_387 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
while ( V_12 < V_63 ) {
error = F_19 ( log , V_12 , V_79 , V_385 , & V_13 ) ;
if ( error )
goto V_394;
V_73 = ( T_5 * ) V_13 ;
error = F_204 ( log , V_73 , V_12 ) ;
if ( error )
goto V_394;
V_387 = ( int ) F_49 ( F_30 ( V_73 -> V_61 ) ) ;
error = F_19 ( log , V_12 + V_79 , V_387 , V_386 ,
& V_13 ) ;
if ( error )
goto V_394;
error = F_203 ( V_73 , V_13 , log ) ;
if ( error )
goto V_394;
error = F_167 ( log , V_323 ,
V_73 , V_13 , V_155 ) ;
if ( error )
goto V_394;
V_12 += V_387 + V_79 ;
}
}
V_394:
F_8 ( V_386 ) ;
V_392:
F_8 ( V_385 ) ;
return error ;
}
STATIC int
F_206 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_45 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_178 = F_72 ( V_395 *
sizeof( struct V_133 ) ,
V_129 ) ;
for ( V_45 = 0 ; V_45 < V_395 ; V_45 ++ )
F_73 ( & log -> V_178 [ V_45 ] ) ;
error = F_205 ( log , V_63 , V_72 ,
V_321 ) ;
if ( error != 0 ) {
F_103 ( log -> V_178 ) ;
log -> V_178 = NULL ;
return error ;
}
error = F_205 ( log , V_63 , V_72 ,
V_322 ) ;
#ifdef F_185
if ( ! error ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_395 ; V_45 ++ )
ASSERT ( F_79 ( & log -> V_178 [ V_45 ] ) ) ;
}
#endif
F_103 ( log -> V_178 ) ;
log -> V_178 = NULL ;
return error ;
}
STATIC int
F_207 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_35 * V_396 ;
error = F_206 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_208 ( log -> V_7 ) ) {
return ( V_58 ) ;
}
F_209 ( log -> V_7 ) ;
V_6 = F_210 ( log -> V_7 , 0 ) ;
F_211 ( V_6 ) ;
ASSERT ( ! ( F_212 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_213 ( V_6 ) ;
V_6 -> V_397 = & V_398 ;
F_16 ( log -> V_7 , V_6 ) ;
error = F_17 ( V_6 ) ;
if ( error ) {
F_18 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
F_27 ( V_6 ) ;
return error ;
}
V_396 = & log -> V_7 -> V_25 ;
F_214 ( V_396 , F_215 ( V_6 ) ) ;
ASSERT ( V_396 -> V_399 == V_400 ) ;
ASSERT ( F_216 ( V_396 ) ) ;
F_27 ( V_6 ) ;
F_217 ( log -> V_7 ) ;
F_218 ( log ) ;
log -> V_401 &= ~ V_402 ;
return 0 ;
}
int
V_136 (
struct V_1 * log )
{
T_3 V_63 , V_72 ;
int error ;
if ( ( error = F_54 ( log , & V_63 , & V_72 ) ) )
return error ;
if ( V_72 != V_63 ) {
if ( ( error = F_219 ( log -> V_7 , L_73 ) ) ) {
return error ;
}
F_116 ( log -> V_7 , L_74 ,
log -> V_7 -> V_403 ? log -> V_7 -> V_403
: L_75 ) ;
error = F_207 ( log , V_63 , V_72 ) ;
log -> V_401 |= V_404 ;
}
return error ;
}
int
F_220 (
struct V_1 * log )
{
if ( log -> V_401 & V_404 ) {
int error ;
error = F_184 ( log ) ;
if ( error ) {
F_109 ( log -> V_7 , L_76 ) ;
return error ;
}
F_221 ( log -> V_7 , V_405 ) ;
F_196 ( log ) ;
F_218 ( log ) ;
F_116 ( log -> V_7 , L_77 ,
log -> V_7 -> V_403 ? log -> V_7 -> V_403
: L_75 ) ;
log -> V_401 &= ~ V_404 ;
} else {
F_222 ( log -> V_7 , L_78 ) ;
}
return 0 ;
}
void
F_218 (
struct V_1 * log )
{
T_4 * V_23 ;
T_36 * V_406 ;
T_1 * V_407 ;
T_1 * V_354 ;
T_30 V_352 ;
T_25 V_408 ;
T_25 V_409 ;
T_25 V_410 ;
int error ;
V_23 = log -> V_7 ;
V_408 = 0LL ;
V_409 = 0LL ;
V_410 = 0LL ;
for ( V_352 = 0 ; V_352 < V_23 -> V_25 . V_374 ; V_352 ++ ) {
error = F_223 ( V_23 , NULL , V_352 , 0 , & V_407 ) ;
if ( error ) {
F_109 ( V_23 , L_79 ,
V_8 , V_352 , error ) ;
} else {
V_406 = F_224 ( V_407 ) ;
V_408 += F_30 ( V_406 -> V_411 ) +
F_30 ( V_406 -> V_412 ) ;
F_27 ( V_407 ) ;
}
error = F_188 ( V_23 , NULL , V_352 , & V_354 ) ;
if ( error ) {
F_109 ( V_23 , L_80 ,
V_8 , V_352 , error ) ;
} else {
struct V_413 * V_353 = F_189 ( V_354 ) ;
V_409 += F_30 ( V_353 -> V_414 ) ;
V_410 += F_30 ( V_353 -> V_415 ) ;
F_27 ( V_354 ) ;
}
}
}
