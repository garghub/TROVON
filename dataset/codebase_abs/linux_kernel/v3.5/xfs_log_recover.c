static inline int
F_1 (
T_1 * log ,
int V_1 )
{
return V_1 > 0 && V_1 <= log -> V_2 ;
}
STATIC T_2 *
F_2 (
T_1 * log ,
int V_3 )
{
struct V_4 * V_5 ;
if ( ! F_1 ( log , V_3 ) ) {
F_3 ( log -> V_6 , L_1 ,
V_3 ) ;
F_4 ( V_7 , V_8 , log -> V_6 ) ;
return NULL ;
}
if ( V_3 > 1 && log -> V_9 > 1 )
V_3 += log -> V_9 ;
V_3 = F_5 ( V_3 , log -> V_9 ) ;
V_5 = F_6 ( log -> V_6 -> V_10 , V_3 , 0 ) ;
if ( V_5 )
F_7 ( V_5 ) ;
return V_5 ;
}
STATIC void
F_8 (
T_2 * V_5 )
{
F_9 ( V_5 ) ;
}
STATIC T_3
F_10 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 )
{
T_4 V_12 = V_11 & ( ( T_4 ) log -> V_9 - 1 ) ;
ASSERT ( V_12 + V_3 <= V_5 -> V_13 ) ;
return V_5 -> V_14 + F_11 ( V_12 ) ;
}
STATIC int
F_12 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 )
{
int error ;
if ( ! F_1 ( log , V_3 ) ) {
F_3 ( log -> V_6 , L_1 ,
V_3 ) ;
F_4 ( V_7 , V_8 , log -> V_6 ) ;
return V_15 ;
}
V_11 = F_13 ( V_11 , log -> V_9 ) ;
V_3 = F_5 ( V_3 , log -> V_9 ) ;
ASSERT ( V_3 > 0 ) ;
ASSERT ( V_3 <= V_5 -> V_13 ) ;
F_14 ( V_5 , log -> V_16 + V_11 ) ;
F_15 ( V_5 ) ;
V_5 -> V_17 = V_3 ;
V_5 -> V_18 = 0 ;
F_16 ( log -> V_6 , V_5 ) ;
error = F_17 ( V_5 ) ;
if ( error )
F_18 ( V_5 , V_7 ) ;
return error ;
}
STATIC int
F_19 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 ,
T_3 * V_12 )
{
int error ;
error = F_12 ( log , V_11 , V_3 , V_5 ) ;
if ( error )
return error ;
* V_12 = F_10 ( log , V_11 , V_3 , V_5 ) ;
return 0 ;
}
STATIC int
F_20 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 ,
T_3 V_12 )
{
T_3 V_19 = V_5 -> V_14 ;
int V_20 = F_11 ( V_5 -> V_13 ) ;
int error , V_21 ;
error = F_21 ( V_5 , V_12 , F_11 ( V_3 ) ) ;
if ( error )
return error ;
error = F_12 ( log , V_11 , V_3 , V_5 ) ;
V_21 = F_21 ( V_5 , V_19 , V_20 ) ;
if ( error )
return error ;
return V_21 ;
}
STATIC int
F_22 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 )
{
int error ;
if ( ! F_1 ( log , V_3 ) ) {
F_3 ( log -> V_6 , L_1 ,
V_3 ) ;
F_4 ( V_7 , V_8 , log -> V_6 ) ;
return V_15 ;
}
V_11 = F_13 ( V_11 , log -> V_9 ) ;
V_3 = F_5 ( V_3 , log -> V_9 ) ;
ASSERT ( V_3 > 0 ) ;
ASSERT ( V_3 <= V_5 -> V_13 ) ;
F_14 ( V_5 , log -> V_16 + V_11 ) ;
F_23 ( V_5 ) ;
F_24 ( V_5 ) ;
F_25 ( V_5 ) ;
V_5 -> V_17 = V_3 ;
V_5 -> V_18 = 0 ;
error = F_26 ( V_5 ) ;
if ( error )
F_18 ( V_5 , V_7 ) ;
F_27 ( V_5 ) ;
return error ;
}
STATIC void
F_28 (
T_5 * V_22 ,
T_6 * V_23 )
{
F_29 ( V_22 , L_2 ,
V_7 , & V_22 -> V_24 . V_25 , V_26 ) ;
F_29 ( V_22 , L_3 ,
& V_23 -> V_27 , F_30 ( V_23 -> V_28 ) ) ;
}
STATIC int
F_31 (
T_5 * V_22 ,
T_6 * V_23 )
{
ASSERT ( V_23 -> V_29 == F_32 ( V_30 ) ) ;
if ( F_33 ( V_23 -> V_28 != F_32 ( V_26 ) ) ) {
F_3 ( V_22 ,
L_4 ) ;
F_28 ( V_22 , V_23 ) ;
F_4 ( L_5 ,
V_8 , V_22 ) ;
return F_34 ( V_15 ) ;
} else if ( F_33 ( ! F_35 ( & V_22 -> V_24 . V_25 , & V_23 -> V_27 ) ) ) {
F_3 ( V_22 ,
L_6 ) ;
F_28 ( V_22 , V_23 ) ;
F_4 ( L_7 ,
V_8 , V_22 ) ;
return F_34 ( V_15 ) ;
}
return 0 ;
}
STATIC int
F_36 (
T_5 * V_22 ,
T_6 * V_23 )
{
ASSERT ( V_23 -> V_29 == F_32 ( V_30 ) ) ;
if ( F_37 ( & V_23 -> V_27 ) ) {
F_3 ( V_22 , L_8 ) ;
} else if ( F_33 ( ! F_35 ( & V_22 -> V_24 . V_25 , & V_23 -> V_27 ) ) ) {
F_3 ( V_22 , L_9 ) ;
F_28 ( V_22 , V_23 ) ;
F_4 ( L_10 ,
V_8 , V_22 ) ;
return F_34 ( V_15 ) ;
}
return 0 ;
}
STATIC void
F_38 (
struct V_4 * V_5 )
{
if ( V_5 -> V_18 ) {
F_18 ( V_5 , V_7 ) ;
F_39 ( V_5 -> V_31 -> V_32 ,
V_33 ) ;
}
V_5 -> V_34 = NULL ;
F_40 ( V_5 , 0 ) ;
}
STATIC int
F_41 (
T_1 * log ,
T_2 * V_5 ,
T_4 V_35 ,
T_4 * V_36 ,
T_7 V_37 )
{
T_3 V_12 ;
T_4 V_38 ;
T_4 V_39 ;
T_7 V_40 ;
int error ;
V_39 = * V_36 ;
V_38 = F_42 ( V_35 , V_39 ) ;
while ( V_38 != V_35 && V_38 != V_39 ) {
error = F_19 ( log , V_38 , 1 , V_5 , & V_12 ) ;
if ( error )
return error ;
V_40 = F_43 ( V_12 ) ;
if ( V_40 == V_37 )
V_39 = V_38 ;
else
V_35 = V_38 ;
V_38 = F_42 ( V_35 , V_39 ) ;
}
ASSERT ( ( V_38 == V_35 && V_38 + 1 == V_39 ) ||
( V_38 == V_39 && V_38 - 1 == V_35 ) ) ;
* V_36 = V_39 ;
return 0 ;
}
STATIC int
F_44 (
T_1 * log ,
T_4 V_41 ,
int V_3 ,
T_7 V_42 ,
T_4 * V_43 )
{
T_4 V_44 , V_45 ;
T_7 V_37 ;
T_2 * V_5 ;
T_4 V_46 ;
T_3 V_47 = NULL ;
int error = 0 ;
V_46 = 1 << F_45 ( V_3 ) ;
while ( V_46 > log -> V_2 )
V_46 >>= 1 ;
while ( ! ( V_5 = F_2 ( log , V_46 ) ) ) {
V_46 >>= 1 ;
if ( V_46 < log -> V_9 )
return V_48 ;
}
for ( V_44 = V_41 ; V_44 < V_41 + V_3 ; V_44 += V_46 ) {
int V_49 ;
V_49 = F_46 ( V_46 , ( V_41 + V_3 - V_44 ) ) ;
error = F_19 ( log , V_44 , V_49 , V_5 , & V_47 ) ;
if ( error )
goto V_50;
for ( V_45 = 0 ; V_45 < V_49 ; V_45 ++ ) {
V_37 = F_43 ( V_47 ) ;
if ( V_37 == V_42 ) {
* V_43 = V_44 + V_45 ;
goto V_50;
}
V_47 += V_51 ;
}
}
* V_43 = - 1 ;
V_50:
F_8 ( V_5 ) ;
return error ;
}
STATIC int
F_47 (
T_1 * log ,
T_4 V_41 ,
T_4 * V_36 ,
int V_52 )
{
T_4 V_44 ;
T_2 * V_5 ;
T_3 V_12 = NULL ;
T_6 * V_23 = NULL ;
int error = 0 ;
int V_53 = 0 ;
int V_54 = * V_36 - V_41 ;
int V_55 ;
ASSERT ( V_41 != 0 || * V_36 != V_41 ) ;
if ( ! ( V_5 = F_2 ( log , V_54 ) ) ) {
if ( ! ( V_5 = F_2 ( log , 1 ) ) )
return V_48 ;
V_53 = 1 ;
} else {
error = F_19 ( log , V_41 , V_54 , V_5 , & V_12 ) ;
if ( error )
goto V_50;
V_12 += ( ( V_54 - 1 ) << V_56 ) ;
}
for ( V_44 = ( * V_36 ) - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( V_44 < V_41 ) {
F_3 ( log -> V_6 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_57 ) ;
goto V_50;
}
if ( V_53 ) {
error = F_19 ( log , V_44 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_50;
}
V_23 = ( T_6 * ) V_12 ;
if ( V_23 -> V_29 == F_32 ( V_30 ) )
break;
if ( ! V_53 )
V_12 -= V_51 ;
}
if ( V_44 == - 1 ) {
error = - 1 ;
goto V_50;
}
if ( ( error = F_36 ( log -> V_6 , V_23 ) ) )
goto V_50;
if ( F_48 ( & log -> V_6 -> V_24 ) ) {
T_7 V_58 = F_30 ( V_23 -> V_58 ) ;
V_55 = V_58 / V_59 ;
if ( V_58 % V_59 )
V_55 ++ ;
} else {
V_55 = 1 ;
}
if ( * V_36 - V_44 + V_52 !=
F_49 ( F_30 ( V_23 -> V_60 ) ) + V_55 )
* V_36 = V_44 ;
V_50:
F_8 ( V_5 ) ;
return error ;
}
STATIC int
F_50 (
T_1 * log ,
T_4 * V_61 )
{
T_2 * V_5 ;
T_3 V_12 ;
T_4 V_43 , V_35 , V_41 , V_36 , V_62 ;
int V_63 ;
T_7 V_64 , V_65 ;
T_7 V_66 ;
int error , V_67 = log -> V_2 ;
if ( ( error = F_51 ( log , & V_35 ) ) == - 1 ) {
* V_61 = V_35 ;
if ( ! V_35 ) {
F_3 ( log -> V_6 , L_12 ) ;
}
return 0 ;
} else if ( error ) {
F_3 ( log -> V_6 , L_13 ) ;
return error ;
}
V_35 = 0 ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_48 ;
error = F_19 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_68;
V_64 = F_43 ( V_12 ) ;
V_36 = V_62 = V_67 - 1 ;
error = F_19 ( log , V_36 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_68;
V_65 = F_43 ( V_12 ) ;
ASSERT ( V_65 != 0 ) ;
if ( V_64 == V_65 ) {
V_62 = V_67 ;
V_66 = V_65 - 1 ;
} else {
V_66 = V_65 ;
if ( ( error = F_41 ( log , V_5 , V_35 ,
& V_62 , V_65 ) ) )
goto V_68;
}
V_63 = F_52 ( log ) ;
if ( V_62 >= V_63 ) {
V_41 = V_62 - V_63 ;
if ( ( error = F_44 ( log ,
V_41 , V_63 ,
V_66 , & V_43 ) ) )
goto V_68;
if ( V_43 != - 1 )
V_62 = V_43 ;
} else {
ASSERT ( V_62 <= V_69 &&
( T_4 ) V_63 >= V_62 ) ;
V_41 = V_67 - ( V_63 - V_62 ) ;
if ( ( error = F_44 ( log , V_41 ,
V_63 - ( int ) V_62 ,
( V_66 - 1 ) , & V_43 ) ) )
goto V_68;
if ( V_43 != - 1 ) {
V_62 = V_43 ;
goto V_70;
}
V_41 = 0 ;
ASSERT ( V_62 <= V_69 ) ;
if ( ( error = F_44 ( log ,
V_41 , ( int ) V_62 ,
V_66 , & V_43 ) ) )
goto V_68;
if ( V_43 != - 1 )
V_62 = V_43 ;
}
V_70:
V_63 = F_53 ( log ) ;
if ( V_62 >= V_63 ) {
V_41 = V_62 - V_63 ;
if ( ( error = F_47 ( log , V_41 ,
& V_62 , 0 ) ) == - 1 ) {
error = F_34 ( V_57 ) ;
goto V_68;
} else if ( error )
goto V_68;
} else {
V_41 = 0 ;
ASSERT ( V_62 <= V_69 ) ;
if ( ( error = F_47 ( log , V_41 ,
& V_62 , 0 ) ) == - 1 ) {
V_41 = V_67 - ( V_63 - V_62 ) ;
V_43 = V_67 ;
ASSERT ( V_41 <= V_69 &&
( T_4 ) V_67 - V_41 >= 0 ) ;
ASSERT ( V_62 <= V_69 ) ;
if ( ( error = F_47 ( log ,
V_41 , & V_43 ,
( int ) V_62 ) ) == - 1 ) {
error = F_34 ( V_57 ) ;
goto V_68;
} else if ( error )
goto V_68;
if ( V_43 != V_67 )
V_62 = V_43 ;
} else if ( error )
goto V_68;
}
F_8 ( V_5 ) ;
if ( V_62 == V_67 )
* V_61 = 0 ;
else
* V_61 = V_62 ;
return 0 ;
V_68:
F_8 ( V_5 ) ;
if ( error )
F_3 ( log -> V_6 , L_14 ) ;
return error ;
}
STATIC int
F_54 (
T_1 * log ,
T_4 * V_62 ,
T_4 * V_71 )
{
T_6 * V_72 ;
T_8 * V_73 ;
T_3 V_12 = NULL ;
T_2 * V_5 ;
int error , V_44 , V_74 ;
T_4 V_75 ;
T_4 V_76 ;
T_9 V_77 ;
int V_78 ;
V_74 = 0 ;
if ( ( error = F_50 ( log , V_62 ) ) )
return error ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_48 ;
if ( * V_62 == 0 ) {
error = F_19 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_79;
if ( F_43 ( V_12 ) == 0 ) {
* V_71 = 0 ;
goto V_79;
}
}
ASSERT ( * V_62 < V_69 ) ;
for ( V_44 = ( int ) ( * V_62 ) - 1 ; V_44 >= 0 ; V_44 -- ) {
error = F_19 ( log , V_44 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_79;
if ( * ( V_80 * ) V_12 == F_32 ( V_30 ) ) {
V_74 = 1 ;
break;
}
}
if ( ! V_74 ) {
for ( V_44 = log -> V_2 - 1 ; V_44 >= ( int ) ( * V_62 ) ; V_44 -- ) {
error = F_19 ( log , V_44 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_79;
if ( * ( V_80 * ) V_12 ==
F_32 ( V_30 ) ) {
V_74 = 2 ;
break;
}
}
}
if ( ! V_74 ) {
F_3 ( log -> V_6 , L_15 , V_7 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_57 ) ;
}
V_72 = ( T_6 * ) V_12 ;
* V_71 = F_55 ( F_56 ( V_72 -> V_81 ) ) ;
log -> V_82 = V_44 ;
log -> V_83 = ( int ) * V_62 ;
log -> V_84 = F_30 ( V_72 -> V_85 ) ;
if ( V_74 == 2 )
log -> V_84 ++ ;
F_57 ( & log -> V_86 , F_56 ( V_72 -> V_81 ) ) ;
F_57 ( & log -> V_87 , F_56 ( V_72 -> V_88 ) ) ;
F_58 ( & log -> V_89 . V_90 , log -> V_84 ,
F_11 ( log -> V_83 ) ) ;
F_58 ( & log -> V_91 . V_90 , log -> V_84 ,
F_11 ( log -> V_83 ) ) ;
if ( F_48 ( & log -> V_6 -> V_24 ) ) {
int V_58 = F_30 ( V_72 -> V_58 ) ;
int V_92 = F_30 ( V_72 -> V_92 ) ;
if ( ( V_92 & V_93 ) &&
( V_58 > V_59 ) ) {
V_78 = V_58 / V_59 ;
if ( V_58 % V_59 )
V_78 ++ ;
} else {
V_78 = 1 ;
}
} else {
V_78 = 1 ;
}
V_76 = ( V_44 + V_78 + ( int )
F_49 ( F_30 ( V_72 -> V_60 ) ) ) % log -> V_2 ;
V_77 = F_59 ( & log -> V_86 ) ;
if ( * V_62 == V_76 &&
F_30 ( V_72 -> V_94 ) == 1 ) {
V_75 = ( V_44 + V_78 ) % log -> V_2 ;
error = F_19 ( log , V_75 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_79;
V_73 = ( T_8 * ) V_12 ;
if ( V_73 -> V_95 & V_96 ) {
F_60 ( & log -> V_86 ,
log -> V_84 , V_76 ) ;
F_60 ( & log -> V_87 ,
log -> V_84 , V_76 ) ;
* V_71 = V_76 ;
log -> V_6 -> V_97 |= V_98 ;
}
}
if ( ! F_61 ( log -> V_6 -> V_10 ) )
error = F_62 ( log , V_77 ) ;
V_79:
F_8 ( V_5 ) ;
if ( error )
F_3 ( log -> V_6 , L_16 ) ;
return error ;
}
STATIC int
F_51 (
T_1 * log ,
T_4 * V_11 )
{
T_2 * V_5 ;
T_3 V_12 ;
T_7 V_99 , V_100 ;
T_4 V_43 , V_36 , V_41 ;
T_4 V_63 ;
int error , V_67 = log -> V_2 ;
* V_11 = 0 ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_48 ;
error = F_19 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_68;
V_99 = F_43 ( V_12 ) ;
if ( V_99 == 0 ) {
* V_11 = 0 ;
F_8 ( V_5 ) ;
return - 1 ;
}
error = F_19 ( log , V_67 - 1 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_68;
V_100 = F_43 ( V_12 ) ;
if ( V_100 != 0 ) {
F_8 ( V_5 ) ;
return 0 ;
} else if ( V_99 != 1 ) {
F_3 ( log -> V_6 ,
L_17 ) ;
return F_34 ( V_101 ) ;
}
V_36 = V_67 - 1 ;
if ( ( error = F_41 ( log , V_5 , 0 , & V_36 , 0 ) ) )
goto V_68;
V_63 = F_52 ( log ) ;
ASSERT ( V_63 <= V_69 ) ;
if ( V_36 < V_63 )
V_63 = V_36 ;
V_41 = V_36 - V_63 ;
if ( ( error = F_44 ( log , V_41 ,
( int ) V_63 , 0 , & V_43 ) ) )
goto V_68;
if ( V_43 != - 1 )
V_36 = V_43 ;
if ( ( error = F_47 ( log , V_41 ,
& V_36 , 0 ) ) == - 1 ) {
error = F_34 ( V_57 ) ;
goto V_68;
} else if ( error )
goto V_68;
* V_11 = V_36 ;
V_68:
F_8 ( V_5 ) ;
if ( error )
return error ;
return - 1 ;
}
STATIC void
F_63 (
T_1 * log ,
T_3 V_47 ,
int V_37 ,
int V_102 ,
int V_103 ,
int V_104 )
{
T_6 * V_105 = ( T_6 * ) V_47 ;
memset ( V_47 , 0 , V_51 ) ;
V_105 -> V_29 = F_32 ( V_30 ) ;
V_105 -> V_85 = F_32 ( V_37 ) ;
V_105 -> V_92 = F_32 (
F_48 ( & log -> V_6 -> V_24 ) ? 2 : 1 ) ;
V_105 -> V_88 = F_64 ( F_65 ( V_37 , V_102 ) ) ;
V_105 -> V_81 = F_64 ( F_65 ( V_103 , V_104 ) ) ;
V_105 -> V_28 = F_32 ( V_26 ) ;
memcpy ( & V_105 -> V_27 , & log -> V_6 -> V_24 . V_25 , sizeof( V_106 ) ) ;
}
STATIC int
F_66 (
T_1 * log ,
int V_37 ,
int V_107 ,
int V_108 ,
int V_103 ,
int V_104 )
{
T_3 V_12 ;
T_2 * V_5 ;
int V_109 , V_110 ;
int V_111 = log -> V_9 ;
int V_112 = V_107 + V_108 ;
int V_46 ;
int error = 0 ;
int V_44 , V_45 = 0 ;
V_46 = 1 << F_45 ( V_108 ) ;
while ( V_46 > log -> V_2 )
V_46 >>= 1 ;
while ( ! ( V_5 = F_2 ( log , V_46 ) ) ) {
V_46 >>= 1 ;
if ( V_46 < V_111 )
return V_48 ;
}
V_109 = F_13 ( V_107 , V_111 ) ;
if ( V_109 != V_107 ) {
error = F_12 ( log , V_107 , 1 , V_5 ) ;
if ( error )
goto V_113;
V_45 = V_107 - V_109 ;
}
for ( V_44 = V_107 ; V_44 < V_112 ; V_44 += V_46 ) {
int V_49 , V_114 ;
V_49 = F_46 ( V_46 , V_112 - V_107 ) ;
V_114 = V_49 - V_45 ;
V_110 = F_13 ( V_112 , V_111 ) ;
if ( V_45 == 0 && ( V_107 + V_114 > V_110 ) ) {
V_12 = V_5 -> V_14 + F_11 ( V_110 - V_107 ) ;
error = F_20 ( log , V_110 , V_111 ,
V_5 , V_12 ) ;
if ( error )
break;
}
V_12 = F_10 ( log , V_107 , V_114 , V_5 ) ;
for (; V_45 < V_114 ; V_45 ++ ) {
F_63 ( log , V_12 , V_37 , V_44 + V_45 ,
V_103 , V_104 ) ;
V_12 += V_51 ;
}
error = F_22 ( log , V_107 , V_114 , V_5 ) ;
if ( error )
break;
V_107 += V_114 ;
V_45 = 0 ;
}
V_113:
F_8 ( V_5 ) ;
return error ;
}
STATIC int
F_62 (
T_1 * log ,
T_9 V_77 )
{
int V_103 , V_115 ;
int V_104 , V_116 ;
int V_117 , V_118 ;
int V_119 ;
int error ;
V_103 = F_67 ( V_77 ) ;
V_104 = F_55 ( V_77 ) ;
V_115 = log -> V_84 ;
V_116 = log -> V_83 ;
if ( V_115 == V_103 ) {
if ( F_33 ( V_116 < V_104 || V_116 >= log -> V_2 ) ) {
F_4 ( L_18 ,
V_120 , log -> V_6 ) ;
return F_34 ( V_15 ) ;
}
V_117 = V_104 + ( log -> V_2 - V_116 ) ;
} else {
if ( F_33 ( V_116 >= V_104 || V_115 != ( V_103 + 1 ) ) ) {
F_4 ( L_19 ,
V_120 , log -> V_6 ) ;
return F_34 ( V_15 ) ;
}
V_117 = V_104 - V_116 ;
}
if ( V_117 <= 0 ) {
ASSERT ( V_117 == 0 ) ;
return 0 ;
}
V_118 = F_52 ( log ) ;
V_118 = F_68 ( V_118 , V_117 ) ;
if ( ( V_116 + V_118 ) <= log -> V_2 ) {
error = F_66 ( log , ( V_115 - 1 ) ,
V_116 , V_118 , V_103 ,
V_104 ) ;
if ( error )
return error ;
} else {
V_119 = log -> V_2 - V_116 ;
error = F_66 ( log , ( V_115 - 1 ) ,
V_116 , V_119 , V_103 ,
V_104 ) ;
if ( error )
return error ;
V_119 = V_118 - ( log -> V_2 - V_116 ) ;
error = F_66 ( log , V_115 , 0 , V_119 ,
V_103 , V_104 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC T_10 *
F_69 (
struct V_121 * V_23 ,
T_11 V_122 )
{
T_10 * V_123 ;
struct V_124 * V_125 ;
F_70 (trans, n, head, r_list) {
if ( V_123 -> V_126 == V_122 )
return V_123 ;
}
return NULL ;
}
STATIC void
F_71 (
struct V_121 * V_23 ,
T_11 V_122 ,
T_9 V_127 )
{
T_10 * V_123 ;
V_123 = F_72 ( sizeof( T_10 ) , V_128 ) ;
V_123 -> V_126 = V_122 ;
V_123 -> V_129 = V_127 ;
F_73 ( & V_123 -> V_130 ) ;
F_74 ( & V_123 -> V_131 ) ;
F_75 ( & V_123 -> V_131 , V_23 ) ;
}
STATIC void
F_76 (
struct V_132 * V_23 )
{
T_12 * V_133 ;
V_133 = F_72 ( sizeof( T_12 ) , V_128 ) ;
F_73 ( & V_133 -> V_134 ) ;
F_77 ( & V_133 -> V_134 , V_23 ) ;
}
STATIC int
F_78 (
struct V_135 * log ,
struct V_136 * V_123 ,
T_3 V_137 ,
int V_138 )
{
T_12 * V_133 ;
T_3 V_139 , V_140 ;
int V_141 ;
if ( F_79 ( & V_123 -> V_130 ) ) {
F_76 ( & V_123 -> V_130 ) ;
V_139 = ( T_3 ) & V_123 -> V_142 +
sizeof( V_143 ) - V_138 ;
memcpy ( V_139 , V_137 , V_138 ) ;
return 0 ;
}
V_133 = F_80 ( V_123 -> V_130 . V_144 , T_12 , V_134 ) ;
V_140 = V_133 -> V_145 [ V_133 -> V_146 - 1 ] . V_147 ;
V_141 = V_133 -> V_145 [ V_133 -> V_146 - 1 ] . V_148 ;
V_139 = F_81 ( V_140 , V_138 + V_141 , V_141 , V_128 ) ;
memcpy ( & V_139 [ V_141 ] , V_137 , V_138 ) ;
V_133 -> V_145 [ V_133 -> V_146 - 1 ] . V_148 += V_138 ;
V_133 -> V_145 [ V_133 -> V_146 - 1 ] . V_147 = V_139 ;
F_82 ( log , V_123 , V_133 , 0 ) ;
return 0 ;
}
STATIC int
F_83 (
struct V_135 * log ,
struct V_136 * V_123 ,
T_3 V_137 ,
int V_138 )
{
T_13 * V_149 ;
T_12 * V_133 ;
T_3 V_139 ;
if ( ! V_138 )
return 0 ;
if ( F_79 ( & V_123 -> V_130 ) ) {
if ( * ( T_7 * ) V_137 != V_150 ) {
F_3 ( log -> V_6 , L_20 ,
V_7 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_57 ) ;
}
if ( V_138 == sizeof( V_143 ) )
F_76 ( & V_123 -> V_130 ) ;
memcpy ( & V_123 -> V_142 , V_137 , V_138 ) ;
return 0 ;
}
V_139 = F_84 ( V_138 , V_128 ) ;
memcpy ( V_139 , V_137 , V_138 ) ;
V_149 = ( T_13 * ) V_139 ;
V_133 = F_80 ( V_123 -> V_130 . V_144 , T_12 , V_134 ) ;
if ( V_133 -> V_151 != 0 &&
V_133 -> V_151 == V_133 -> V_146 ) {
F_76 ( & V_123 -> V_130 ) ;
V_133 = F_80 ( V_123 -> V_130 . V_144 ,
T_12 , V_134 ) ;
}
if ( V_133 -> V_151 == 0 ) {
if ( V_149 -> V_152 == 0 ||
V_149 -> V_152 > V_153 ) {
F_3 ( log -> V_6 ,
L_21 ,
V_149 -> V_152 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_57 ) ;
}
V_133 -> V_151 = V_149 -> V_152 ;
V_133 -> V_145 =
F_72 ( V_133 -> V_151 * sizeof( V_154 ) ,
V_128 ) ;
}
ASSERT ( V_133 -> V_151 > V_133 -> V_146 ) ;
V_133 -> V_145 [ V_133 -> V_146 ] . V_147 = V_139 ;
V_133 -> V_145 [ V_133 -> V_146 ] . V_148 = V_138 ;
V_133 -> V_146 ++ ;
F_85 ( log , V_123 , V_133 , 0 ) ;
return 0 ;
}
STATIC int
F_86 (
struct V_135 * log ,
struct V_136 * V_123 ,
int V_155 )
{
T_12 * V_133 , * V_125 ;
F_87 ( V_156 ) ;
F_88 ( & V_123 -> V_130 , & V_156 ) ;
F_89 (item, n, &sort_list, ri_list) {
T_14 * V_157 = V_133 -> V_145 [ 0 ] . V_147 ;
switch ( F_90 ( V_133 ) ) {
case V_158 :
if ( ! ( V_157 -> V_159 & V_160 ) ) {
F_91 ( log ,
V_123 , V_133 , V_155 ) ;
F_92 ( & V_133 -> V_134 , & V_123 -> V_130 ) ;
break;
}
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
F_93 ( log ,
V_123 , V_133 , V_155 ) ;
F_94 ( & V_133 -> V_134 , & V_123 -> V_130 ) ;
break;
default:
F_3 ( log -> V_6 ,
L_22 ,
V_7 ) ;
ASSERT ( 0 ) ;
return F_34 ( V_57 ) ;
}
}
ASSERT ( F_79 ( & V_156 ) ) ;
return 0 ;
}
STATIC int
F_95 (
struct V_135 * log ,
struct V_166 * V_133 )
{
T_14 * V_157 = V_133 -> V_145 [ 0 ] . V_147 ;
struct V_132 * V_167 ;
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
V_169 = F_84 ( sizeof( struct V_168 ) , V_128 ) ;
V_169 -> V_171 = V_157 -> V_170 ;
V_169 -> V_172 = V_157 -> V_173 ;
V_169 -> V_174 = 1 ;
F_77 ( & V_169 -> V_175 , V_167 ) ;
F_100 ( log , V_157 ) ;
return 0 ;
}
STATIC int
F_101 (
struct V_135 * log ,
T_4 V_176 ,
T_7 V_138 ,
T_15 V_177 )
{
struct V_132 * V_167 ;
struct V_168 * V_169 ;
if ( log -> V_178 == NULL ) {
ASSERT ( ! ( V_177 & V_160 ) ) ;
return 0 ;
}
V_167 = F_97 ( log , V_176 ) ;
F_98 (bcp, bucket, bc_list) {
if ( V_169 -> V_171 == V_176 && V_169 -> V_172 == V_138 )
goto V_74;
}
ASSERT ( ! ( V_177 & V_160 ) ) ;
return 0 ;
V_74:
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
struct V_179 * V_22 ,
T_12 * V_133 ,
struct V_4 * V_5 ,
T_14 * V_157 )
{
int V_44 ;
int V_180 = 0 ;
int V_181 = 0 ;
int V_182 = 0 ;
int V_183 = 0 ;
int V_184 = 0 ;
int V_185 ;
int V_186 ;
T_16 * V_187 ;
T_16 * V_188 ;
F_105 ( V_22 -> V_189 , V_157 ) ;
V_186 = F_11 ( V_5 -> V_17 ) >> V_22 -> V_24 . V_190 ;
for ( V_44 = 0 ; V_44 < V_186 ; V_44 ++ ) {
V_185 = ( V_44 * V_22 -> V_24 . V_191 ) +
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
ASSERT ( V_133 -> V_145 [ V_180 ] . V_147 != NULL ) ;
ASSERT ( ( V_133 -> V_145 [ V_180 ] . V_148 % V_197 ) == 0 ) ;
ASSERT ( ( V_183 + V_184 ) <=
F_11 ( V_5 -> V_17 ) ) ;
V_187 = V_133 -> V_145 [ V_180 ] . V_147 +
V_185 - V_183 ;
if ( F_33 ( * V_187 == 0 ) ) {
F_109 ( V_22 ,
L_23
L_24 ,
V_133 , V_5 ) ;
F_4 ( L_25 ,
V_120 , V_22 ) ;
return F_34 ( V_15 ) ;
}
V_188 = ( T_16 * ) F_110 ( V_5 ,
V_185 ) ;
* V_188 = * V_187 ;
}
return 0 ;
}
STATIC void
F_111 (
struct V_179 * V_22 ,
T_12 * V_133 ,
struct V_4 * V_5 ,
T_14 * V_157 )
{
int V_44 ;
int V_181 ;
int V_182 ;
int error ;
F_112 ( V_22 -> V_189 , V_157 ) ;
V_181 = 0 ;
V_44 = 1 ;
while ( 1 ) {
V_181 = F_107 ( V_157 -> V_194 ,
V_157 -> V_195 , V_181 ) ;
if ( V_181 == - 1 )
break;
V_182 = F_108 ( V_157 -> V_194 ,
V_157 -> V_195 , V_181 ) ;
ASSERT ( V_182 > 0 ) ;
ASSERT ( V_133 -> V_145 [ V_44 ] . V_147 != NULL ) ;
ASSERT ( V_133 -> V_145 [ V_44 ] . V_148 % V_197 == 0 ) ;
ASSERT ( F_11 ( V_5 -> V_17 ) >=
( ( T_7 ) V_181 << V_196 ) + ( V_182 << V_196 ) ) ;
error = 0 ;
if ( V_157 -> V_159 &
( V_198 | V_199 | V_200 ) ) {
if ( V_133 -> V_145 [ V_44 ] . V_147 == NULL ) {
F_109 ( V_22 ,
L_26 , V_7 ) ;
goto V_201;
}
if ( V_133 -> V_145 [ V_44 ] . V_148 < sizeof( V_202 ) ) {
F_109 ( V_22 ,
L_27 ,
V_133 -> V_145 [ V_44 ] . V_148 , V_7 ) ;
goto V_201;
}
error = F_113 ( V_22 , V_133 -> V_145 [ V_44 ] . V_147 ,
- 1 , 0 , V_203 ,
L_28 ) ;
if ( error )
goto V_201;
}
memcpy ( F_110 ( V_5 ,
( T_7 ) V_181 << V_196 ) ,
V_133 -> V_145 [ V_44 ] . V_147 ,
V_182 << V_196 ) ;
V_201:
V_44 ++ ;
V_181 += V_182 ;
}
ASSERT ( V_44 == V_133 -> V_151 ) ;
}
int
F_113 (
struct V_179 * V_22 ,
V_202 * V_204 ,
T_17 V_205 ,
T_7 type ,
T_7 V_177 ,
char * V_206 )
{
T_18 * V_207 = ( T_18 * ) V_204 ;
int V_208 = 0 ;
if ( V_204 -> V_209 != F_114 ( V_210 ) ) {
if ( V_177 & V_203 )
F_109 ( V_22 ,
L_29 ,
V_206 , V_205 , F_115 ( V_204 -> V_209 ) , V_210 ) ;
V_208 ++ ;
}
if ( V_204 -> V_211 != V_212 ) {
if ( V_177 & V_203 )
F_109 ( V_22 ,
L_30 ,
V_206 , V_205 , V_204 -> V_211 , V_212 ) ;
V_208 ++ ;
}
if ( V_204 -> V_213 != V_214 &&
V_204 -> V_213 != V_215 &&
V_204 -> V_213 != V_216 ) {
if ( V_177 & V_203 )
F_109 ( V_22 ,
L_31 ,
V_206 , V_205 , V_204 -> V_213 ) ;
V_208 ++ ;
}
if ( V_205 != - 1 && V_205 != F_30 ( V_204 -> V_217 ) ) {
if ( V_177 & V_203 )
F_109 ( V_22 ,
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
F_109 ( V_22 ,
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
F_109 ( V_22 ,
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
F_109 ( V_22 ,
L_36 ,
V_206 , ( int ) F_30 ( V_204 -> V_217 ) , V_204 ) ;
V_208 ++ ;
}
}
}
if ( ! V_208 || ! ( V_177 & V_227 ) )
return V_208 ;
if ( V_177 & V_203 )
F_116 ( V_22 , L_37 , V_205 ) ;
ASSERT ( V_205 != - 1 ) ;
ASSERT ( V_177 & V_227 ) ;
memset ( V_207 , 0 , sizeof( T_18 ) ) ;
V_207 -> V_228 . V_209 = F_114 ( V_210 ) ;
V_207 -> V_228 . V_211 = V_212 ;
V_207 -> V_228 . V_213 = type ;
V_207 -> V_228 . V_217 = F_32 ( V_205 ) ;
return V_208 ;
}
STATIC void
F_117 (
T_5 * V_22 ,
T_1 * log ,
T_12 * V_133 ,
T_2 * V_5 ,
T_14 * V_157 )
{
T_7 type ;
F_118 ( log , V_157 ) ;
if ( V_22 -> V_229 == 0 ) {
return;
}
type = 0 ;
if ( V_157 -> V_159 & V_198 )
type |= V_214 ;
if ( V_157 -> V_159 & V_199 )
type |= V_215 ;
if ( V_157 -> V_159 & V_200 )
type |= V_216 ;
if ( log -> V_230 & type )
return;
F_111 ( V_22 , V_133 , V_5 , V_157 ) ;
}
STATIC int
F_119 (
T_1 * log ,
struct V_132 * V_231 ,
T_12 * V_133 )
{
T_14 * V_157 = V_133 -> V_145 [ 0 ] . V_147 ;
T_5 * V_22 = log -> V_6 ;
T_2 * V_5 ;
int error ;
T_7 V_232 ;
if ( F_101 ( log , V_157 -> V_170 ,
V_157 -> V_173 , V_157 -> V_159 ) ) {
F_120 ( log , V_157 ) ;
return 0 ;
}
F_121 ( log , V_157 ) ;
V_232 = 0 ;
if ( V_157 -> V_159 & V_233 )
V_232 |= V_234 ;
V_5 = F_122 ( V_22 -> V_235 , V_157 -> V_170 , V_157 -> V_173 ,
V_232 ) ;
if ( ! V_5 )
return F_34 ( V_48 ) ;
error = V_5 -> V_18 ;
if ( error ) {
F_18 ( V_5 , L_38 ) ;
F_27 ( V_5 ) ;
return error ;
}
if ( V_157 -> V_159 & V_233 ) {
error = F_104 ( V_22 , V_133 , V_5 , V_157 ) ;
} else if ( V_157 -> V_159 &
( V_198 | V_199 | V_200 ) ) {
F_117 ( V_22 , log , V_133 , V_5 , V_157 ) ;
} else {
F_111 ( V_22 , V_133 , V_5 , V_157 ) ;
}
if ( error )
return F_34 ( error ) ;
if ( V_236 ==
F_115 ( * ( ( V_237 * ) F_110 ( V_5 , 0 ) ) ) &&
( F_11 ( V_5 -> V_17 ) != F_123 ( log -> V_6 -> V_24 . V_238 ,
( V_239 ) F_124 ( log -> V_6 ) ) ) ) {
F_125 ( V_5 ) ;
error = F_26 ( V_5 ) ;
} else {
ASSERT ( V_5 -> V_31 -> V_32 == V_22 ) ;
V_5 -> V_34 = F_38 ;
F_126 ( V_5 , V_231 ) ;
}
F_27 ( V_5 ) ;
return error ;
}
STATIC int
F_127 (
T_1 * log ,
struct V_132 * V_231 ,
T_12 * V_133 )
{
T_13 * V_149 ;
T_5 * V_22 = log -> V_6 ;
T_2 * V_5 ;
V_192 * V_240 ;
int V_138 ;
T_3 V_241 ;
T_3 V_242 ;
int error ;
int V_243 ;
T_7 V_244 ;
T_19 * V_245 ;
int V_246 = 0 ;
if ( V_133 -> V_145 [ 0 ] . V_148 == sizeof( T_13 ) ) {
V_149 = V_133 -> V_145 [ 0 ] . V_147 ;
} else {
V_149 = F_84 ( sizeof( T_13 ) , V_128 ) ;
V_246 = 1 ;
error = F_128 ( & V_133 -> V_145 [ 0 ] , V_149 ) ;
if ( error )
goto error;
}
if ( F_101 ( log , V_149 -> V_247 ,
V_149 -> V_248 , 0 ) ) {
error = 0 ;
F_129 ( log , V_149 ) ;
goto error;
}
F_130 ( log , V_149 ) ;
V_5 = F_122 ( V_22 -> V_235 , V_149 -> V_247 , V_149 -> V_248 , 0 ) ;
if ( ! V_5 ) {
error = V_48 ;
goto error;
}
error = V_5 -> V_18 ;
if ( error ) {
F_18 ( V_5 , L_39 ) ;
F_27 ( V_5 ) ;
goto error;
}
ASSERT ( V_149 -> V_249 & V_250 ) ;
V_240 = ( V_192 * ) F_110 ( V_5 , V_149 -> V_251 ) ;
if ( F_33 ( V_240 -> V_252 != F_114 ( V_236 ) ) ) {
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_40 ,
V_7 , V_240 , V_5 , V_149 -> V_253 ) ;
F_4 ( L_41 ,
V_120 , V_22 ) ;
error = V_15 ;
goto error;
}
V_245 = V_133 -> V_145 [ 1 ] . V_147 ;
if ( F_33 ( V_245 -> V_252 != V_236 ) ) {
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_42 ,
V_7 , V_133 , V_149 -> V_253 ) ;
F_4 ( L_43 ,
V_120 , V_22 ) ;
error = V_15 ;
goto error;
}
if ( V_245 -> V_254 < F_115 ( V_240 -> V_254 ) ) {
if ( F_115 ( V_240 -> V_254 ) == V_255 &&
V_245 -> V_254 < ( V_255 >> 1 ) ) {
} else {
F_27 ( V_5 ) ;
F_131 ( log , V_149 ) ;
error = 0 ;
goto error;
}
}
V_245 -> V_254 = 0 ;
if ( F_33 ( F_132 ( V_245 -> V_256 ) ) ) {
if ( ( V_245 -> V_257 != V_258 ) &&
( V_245 -> V_257 != V_259 ) ) {
F_133 ( L_44 ,
V_120 , V_22 , V_245 ) ;
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_45
L_46 ,
V_7 , V_133 , V_240 , V_5 , V_149 -> V_253 ) ;
error = V_15 ;
goto error;
}
} else if ( F_33 ( F_134 ( V_245 -> V_256 ) ) ) {
if ( ( V_245 -> V_257 != V_258 ) &&
( V_245 -> V_257 != V_259 ) &&
( V_245 -> V_257 != V_260 ) ) {
F_133 ( L_47 ,
V_120 , V_22 , V_245 ) ;
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_48
L_46 ,
V_7 , V_133 , V_240 , V_5 , V_149 -> V_253 ) ;
error = V_15 ;
goto error;
}
}
if ( F_33 ( V_245 -> V_261 + V_245 -> V_262 > V_245 -> V_263 ) ) {
F_133 ( L_49 ,
V_120 , V_22 , V_245 ) ;
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_50
L_51 ,
V_7 , V_133 , V_240 , V_5 , V_149 -> V_253 ,
V_245 -> V_261 + V_245 -> V_262 ,
V_245 -> V_263 ) ;
error = V_15 ;
goto error;
}
if ( F_33 ( V_245 -> V_264 > V_22 -> V_24 . V_191 ) ) {
F_133 ( L_52 ,
V_120 , V_22 , V_245 ) ;
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_50
L_53 , V_7 ,
V_133 , V_240 , V_5 , V_149 -> V_253 , V_245 -> V_264 ) ;
error = V_15 ;
goto error;
}
if ( F_33 ( V_133 -> V_145 [ 1 ] . V_148 > sizeof( struct V_265 ) ) ) {
F_133 ( L_54 ,
V_120 , V_22 , V_245 ) ;
F_27 ( V_5 ) ;
F_109 ( V_22 ,
L_55 ,
V_7 , V_133 -> V_145 [ 1 ] . V_148 , V_133 ) ;
error = V_15 ;
goto error;
}
F_135 ( V_240 , V_133 -> V_145 [ 1 ] . V_147 ) ;
if ( V_133 -> V_145 [ 1 ] . V_148 > sizeof( struct V_265 ) ) {
memcpy ( ( T_3 ) V_240 + sizeof( struct V_265 ) ,
V_133 -> V_145 [ 1 ] . V_147 + sizeof( struct V_265 ) ,
V_133 -> V_145 [ 1 ] . V_148 - sizeof( struct V_265 ) ) ;
}
V_244 = V_149 -> V_249 ;
switch ( V_244 & ( V_266 | V_267 ) ) {
case V_266 :
F_136 ( V_240 , V_149 -> V_268 . V_269 ) ;
break;
case V_267 :
memcpy ( F_137 ( V_240 ) ,
& V_149 -> V_268 . V_270 ,
sizeof( V_106 ) ) ;
break;
}
if ( V_149 -> V_152 == 2 )
goto V_271;
V_138 = V_133 -> V_145 [ 2 ] . V_148 ;
V_241 = V_133 -> V_145 [ 2 ] . V_147 ;
ASSERT ( V_149 -> V_152 <= 4 ) ;
ASSERT ( ( V_149 -> V_152 == 3 ) || ( V_244 & V_272 ) ) ;
ASSERT ( ! ( V_244 & V_273 ) ||
( V_138 == V_149 -> V_274 ) ) ;
switch ( V_244 & V_273 ) {
case V_275 :
case V_276 :
memcpy ( F_137 ( V_240 ) , V_241 , V_138 ) ;
break;
case V_277 :
F_138 ( V_22 , (struct V_278 * ) V_241 , V_138 ,
( V_279 * ) F_137 ( V_240 ) ,
F_139 ( V_240 , V_22 ) ) ;
break;
default:
ASSERT ( ( V_244 & V_273 ) == 0 ) ;
break;
}
if ( V_149 -> V_249 & V_272 ) {
if ( V_149 -> V_249 & V_273 ) {
V_243 = 3 ;
} else {
V_243 = 2 ;
}
V_138 = V_133 -> V_145 [ V_243 ] . V_148 ;
V_241 = V_133 -> V_145 [ V_243 ] . V_147 ;
ASSERT ( V_138 == V_149 -> V_280 ) ;
switch ( V_149 -> V_249 & V_272 ) {
case V_281 :
case V_282 :
V_242 = F_140 ( V_240 ) ;
ASSERT ( V_138 <= F_141 ( V_240 , V_22 ) ) ;
memcpy ( V_242 , V_241 , V_138 ) ;
break;
case V_283 :
V_242 = F_140 ( V_240 ) ;
F_138 ( V_22 , (struct V_278 * ) V_241 ,
V_138 , ( V_279 * ) V_242 ,
F_141 ( V_240 , V_22 ) ) ;
break;
default:
F_3 ( log -> V_6 , L_56 , V_7 ) ;
ASSERT ( 0 ) ;
F_27 ( V_5 ) ;
error = V_57 ;
goto error;
}
}
V_271:
ASSERT ( V_5 -> V_31 -> V_32 == V_22 ) ;
V_5 -> V_34 = F_38 ;
F_126 ( V_5 , V_231 ) ;
F_27 ( V_5 ) ;
error:
if ( V_246 )
F_103 ( V_149 ) ;
return F_34 ( error ) ;
}
STATIC int
F_142 (
T_1 * log ,
T_12 * V_133 )
{
T_20 * V_284 = V_133 -> V_145 [ 0 ] . V_147 ;
ASSERT ( V_284 ) ;
if ( V_284 -> V_285 & V_286 )
log -> V_230 |= V_214 ;
if ( V_284 -> V_285 & V_287 )
log -> V_230 |= V_215 ;
if ( V_284 -> V_285 & V_288 )
log -> V_230 |= V_216 ;
return ( 0 ) ;
}
STATIC int
F_143 (
T_1 * log ,
struct V_132 * V_231 ,
T_12 * V_133 )
{
T_5 * V_22 = log -> V_6 ;
T_2 * V_5 ;
struct V_289 * V_204 , * V_290 ;
int error ;
T_21 * V_291 ;
T_7 type ;
if ( V_22 -> V_229 == 0 )
return ( 0 ) ;
V_290 = V_133 -> V_145 [ 1 ] . V_147 ;
if ( V_290 == NULL ) {
F_109 ( log -> V_6 , L_57 , V_7 ) ;
return F_34 ( V_57 ) ;
}
if ( V_133 -> V_145 [ 1 ] . V_148 < sizeof( V_202 ) ) {
F_109 ( log -> V_6 , L_58 ,
V_133 -> V_145 [ 1 ] . V_148 , V_7 ) ;
return F_34 ( V_57 ) ;
}
type = V_290 -> V_213 & ( V_214 | V_215 | V_216 ) ;
ASSERT ( type ) ;
if ( log -> V_230 & type )
return ( 0 ) ;
V_291 = V_133 -> V_145 [ 0 ] . V_147 ;
ASSERT ( V_291 ) ;
error = F_113 ( V_22 , V_290 , V_291 -> V_292 , 0 , V_203 ,
L_59 ) ;
if ( error )
return F_34 ( V_57 ) ;
ASSERT ( V_291 -> V_293 == 1 ) ;
error = F_144 ( V_22 , NULL , V_22 -> V_235 , V_291 -> V_294 ,
F_145 ( V_22 , V_291 -> V_293 ) , 0 , & V_5 ) ;
if ( error )
return error ;
ASSERT ( V_5 ) ;
V_204 = ( V_202 * ) F_110 ( V_5 , V_291 -> V_295 ) ;
error = F_113 ( V_22 , V_204 , V_291 -> V_292 , 0 , V_203 ,
L_60 ) ;
if ( error ) {
F_27 ( V_5 ) ;
return F_34 ( V_57 ) ;
}
memcpy ( V_204 , V_290 , V_133 -> V_145 [ 1 ] . V_148 ) ;
ASSERT ( V_291 -> V_296 == 2 ) ;
ASSERT ( V_5 -> V_31 -> V_32 == V_22 ) ;
V_5 -> V_34 = F_38 ;
F_126 ( V_5 , V_231 ) ;
F_27 ( V_5 ) ;
return ( 0 ) ;
}
STATIC int
F_146 (
T_1 * log ,
T_12 * V_133 ,
T_9 V_127 )
{
int error ;
T_5 * V_22 = log -> V_6 ;
T_22 * V_297 ;
T_23 * V_298 ;
V_298 = V_133 -> V_145 [ 0 ] . V_147 ;
V_297 = F_147 ( V_22 , V_298 -> V_299 ) ;
if ( ( error = F_148 ( & ( V_133 -> V_145 [ 0 ] ) ,
& ( V_297 -> V_300 ) ) ) ) {
F_149 ( V_297 ) ;
return error ;
}
F_150 ( & V_297 -> V_301 , V_298 -> V_299 ) ;
F_151 ( & log -> V_302 -> V_303 ) ;
F_152 ( log -> V_302 , & V_297 -> V_304 , V_127 ) ;
return 0 ;
}
STATIC int
F_153 (
T_1 * log ,
T_12 * V_133 )
{
T_24 * V_305 ;
T_22 * V_297 = NULL ;
T_25 * V_306 ;
T_26 V_307 ;
struct V_308 V_309 ;
struct V_310 * V_311 = log -> V_302 ;
V_305 = V_133 -> V_145 [ 0 ] . V_147 ;
ASSERT ( ( V_133 -> V_145 [ 0 ] . V_148 == ( sizeof( V_312 ) +
( ( V_305 -> V_313 - 1 ) * sizeof( V_314 ) ) ) ) ||
( V_133 -> V_145 [ 0 ] . V_148 == ( sizeof( V_315 ) +
( ( V_305 -> V_313 - 1 ) * sizeof( V_316 ) ) ) ) ) ;
V_307 = V_305 -> V_317 ;
F_151 ( & V_311 -> V_303 ) ;
V_306 = F_154 ( V_311 , & V_309 , 0 ) ;
while ( V_306 != NULL ) {
if ( V_306 -> V_318 == V_165 ) {
V_297 = ( T_22 * ) V_306 ;
if ( V_297 -> V_300 . V_307 == V_307 ) {
F_155 ( V_311 , V_306 ,
V_319 ) ;
F_149 ( V_297 ) ;
F_151 ( & V_311 -> V_303 ) ;
break;
}
}
V_306 = F_156 ( V_311 , & V_309 ) ;
}
F_157 ( V_311 , & V_309 ) ;
F_158 ( & V_311 -> V_303 ) ;
return 0 ;
}
STATIC void
F_159 (
struct V_136 * V_123 )
{
T_12 * V_133 , * V_125 ;
int V_44 ;
F_89 (item, n, &trans->r_itemq, ri_list) {
F_102 ( & V_133 -> V_134 ) ;
for ( V_44 = 0 ; V_44 < V_133 -> V_146 ; V_44 ++ )
F_103 ( V_133 -> V_145 [ V_44 ] . V_147 ) ;
F_103 ( V_133 -> V_145 ) ;
F_103 ( V_133 ) ;
}
F_103 ( V_123 ) ;
}
STATIC int
F_160 (
struct V_135 * log ,
struct V_136 * V_123 ,
struct V_166 * V_133 )
{
F_161 ( log , V_123 , V_133 , V_320 ) ;
switch ( F_90 ( V_133 ) ) {
case V_158 :
return F_95 ( log , V_133 ) ;
case V_163 :
return F_142 ( log , V_133 ) ;
case V_161 :
case V_165 :
case V_164 :
case V_162 :
return 0 ;
default:
F_3 ( log -> V_6 , L_61 ,
V_7 , F_90 ( V_133 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_57 ) ;
}
}
STATIC int
F_162 (
struct V_135 * log ,
struct V_136 * V_123 ,
struct V_132 * V_231 ,
struct V_166 * V_133 )
{
F_161 ( log , V_123 , V_133 , V_321 ) ;
switch ( F_90 ( V_133 ) ) {
case V_158 :
return F_119 ( log , V_231 , V_133 ) ;
case V_161 :
return F_127 ( log , V_231 , V_133 ) ;
case V_165 :
return F_146 ( log , V_133 , V_123 -> V_129 ) ;
case V_164 :
return F_153 ( log , V_133 ) ;
case V_162 :
return F_143 ( log , V_231 , V_133 ) ;
case V_163 :
return 0 ;
default:
F_3 ( log -> V_6 , L_61 ,
V_7 , F_90 ( V_133 ) ) ;
ASSERT ( 0 ) ;
return F_34 ( V_57 ) ;
}
}
STATIC int
F_163 (
struct V_135 * log ,
struct V_136 * V_123 ,
int V_155 )
{
int error = 0 , V_21 ;
T_12 * V_133 ;
F_87 ( V_231 ) ;
F_164 ( & V_123 -> V_131 ) ;
error = F_86 ( log , V_123 , V_155 ) ;
if ( error )
return error ;
F_98 (item, &trans->r_itemq, ri_list) {
switch ( V_155 ) {
case V_320 :
error = F_160 ( log , V_123 , V_133 ) ;
break;
case V_321 :
error = F_162 ( log , V_123 ,
& V_231 , V_133 ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_50;
}
F_159 ( V_123 ) ;
V_50:
V_21 = F_165 ( & V_231 ) ;
return error ? error : V_21 ;
}
STATIC int
F_166 (
struct V_135 * log ,
struct V_136 * V_123 )
{
F_3 ( log -> V_6 , L_62 , V_7 ) ;
return 0 ;
}
STATIC int
F_167 (
T_1 * log ,
struct V_121 V_322 [] ,
T_6 * V_72 ,
T_3 V_137 ,
int V_155 )
{
T_3 V_323 ;
int V_324 ;
T_8 * V_325 ;
T_10 * V_123 ;
T_11 V_122 ;
int error ;
unsigned long V_326 ;
T_7 V_177 ;
V_323 = V_137 + F_30 ( V_72 -> V_60 ) ;
V_324 = F_30 ( V_72 -> V_94 ) ;
if ( F_31 ( log -> V_6 , V_72 ) )
return ( F_34 ( V_57 ) ) ;
while ( ( V_137 < V_323 ) && V_324 ) {
ASSERT ( V_137 + sizeof( T_8 ) <= V_323 ) ;
V_325 = ( T_8 * ) V_137 ;
V_137 += sizeof( T_8 ) ;
if ( V_325 -> V_327 != V_328 &&
V_325 -> V_327 != V_329 ) {
F_3 ( log -> V_6 , L_63 ,
V_7 , V_325 -> V_327 ) ;
ASSERT ( 0 ) ;
return ( F_34 ( V_57 ) ) ;
}
V_122 = F_30 ( V_325 -> V_330 ) ;
V_326 = F_168 ( V_122 ) ;
V_123 = F_69 ( & V_322 [ V_326 ] , V_122 ) ;
if ( V_123 == NULL ) {
if ( V_325 -> V_95 & V_331 )
F_71 ( & V_322 [ V_326 ] , V_122 ,
F_56 ( V_72 -> V_88 ) ) ;
} else {
if ( V_137 + F_30 ( V_325 -> V_332 ) > V_323 ) {
F_3 ( log -> V_6 , L_64 ,
V_7 , F_30 ( V_325 -> V_332 ) ) ;
F_169 ( 1 ) ;
return ( F_34 ( V_57 ) ) ;
}
V_177 = V_325 -> V_95 & ~ V_333 ;
if ( V_177 & V_334 )
V_177 &= ~ V_335 ;
switch ( V_177 ) {
case V_336 :
error = F_163 ( log ,
V_123 , V_155 ) ;
break;
case V_96 :
error = F_166 ( log , V_123 ) ;
break;
case V_334 :
error = F_78 ( log ,
V_123 , V_137 ,
F_30 ( V_325 -> V_332 ) ) ;
break;
case V_331 :
F_3 ( log -> V_6 , L_65 ,
V_7 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_57 ) ;
break;
case 0 :
case V_335 :
error = F_83 ( log , V_123 ,
V_137 , F_30 ( V_325 -> V_332 ) ) ;
break;
default:
F_3 ( log -> V_6 , L_66 ,
V_7 , V_177 ) ;
ASSERT ( 0 ) ;
error = F_34 ( V_57 ) ;
break;
}
if ( error )
return error ;
}
V_137 += F_30 ( V_325 -> V_332 ) ;
V_324 -- ;
}
return 0 ;
}
STATIC int
F_170 (
T_5 * V_22 ,
T_22 * V_297 )
{
T_27 * V_337 ;
T_28 * V_338 ;
int V_44 ;
int error = 0 ;
T_29 * V_339 ;
T_30 V_340 ;
ASSERT ( ! F_171 ( V_341 , & V_297 -> V_342 ) ) ;
for ( V_44 = 0 ; V_44 < V_297 -> V_300 . V_299 ; V_44 ++ ) {
V_339 = & ( V_297 -> V_300 . V_343 [ V_44 ] ) ;
V_340 = F_172 ( V_22 ,
F_173 ( V_22 , V_339 -> V_344 ) ) ;
if ( ( V_340 == 0 ) ||
( V_339 -> V_345 == 0 ) ||
( V_340 >= V_22 -> V_24 . V_346 ) ||
( V_339 -> V_345 >= V_22 -> V_24 . V_347 ) ) {
F_174 ( V_297 , V_297 -> V_300 . V_299 ) ;
return F_34 ( V_57 ) ;
}
}
V_338 = F_175 ( V_22 , 0 ) ;
error = F_176 ( V_338 , 0 , F_177 ( V_22 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_348;
V_337 = F_178 ( V_338 , V_297 , V_297 -> V_300 . V_299 ) ;
for ( V_44 = 0 ; V_44 < V_297 -> V_300 . V_299 ; V_44 ++ ) {
V_339 = & ( V_297 -> V_300 . V_343 [ V_44 ] ) ;
error = F_179 ( V_338 , V_339 -> V_344 , V_339 -> V_345 ) ;
if ( error )
goto V_348;
F_180 ( V_338 , V_337 , V_339 -> V_344 ,
V_339 -> V_345 ) ;
}
F_181 ( V_341 , & V_297 -> V_342 ) ;
error = F_182 ( V_338 , 0 ) ;
return error ;
V_348:
F_183 ( V_338 , V_349 ) ;
return error ;
}
STATIC int
F_184 (
T_1 * log )
{
T_25 * V_306 ;
T_22 * V_297 ;
int error = 0 ;
struct V_308 V_309 ;
struct V_310 * V_311 ;
V_311 = log -> V_302 ;
F_151 ( & V_311 -> V_303 ) ;
V_306 = F_154 ( V_311 , & V_309 , 0 ) ;
while ( V_306 != NULL ) {
if ( V_306 -> V_318 != V_165 ) {
#ifdef F_185
for (; V_306 ; V_306 = F_156 ( V_311 , & V_309 ) )
ASSERT ( V_306 -> V_318 != V_165 ) ;
#endif
break;
}
V_297 = ( T_22 * ) V_306 ;
if ( F_171 ( V_341 , & V_297 -> V_342 ) ) {
V_306 = F_156 ( V_311 , & V_309 ) ;
continue;
}
F_158 ( & V_311 -> V_303 ) ;
error = F_170 ( log -> V_6 , V_297 ) ;
F_151 ( & V_311 -> V_303 ) ;
if ( error )
goto V_50;
V_306 = F_156 ( V_311 , & V_309 ) ;
}
V_50:
F_157 ( V_311 , & V_309 ) ;
F_158 ( & V_311 -> V_303 ) ;
return error ;
}
STATIC void
F_186 (
T_5 * V_22 ,
T_31 V_350 ,
int V_167 )
{
T_28 * V_338 ;
T_32 * V_351 ;
T_2 * V_352 ;
int V_12 ;
int error ;
V_338 = F_175 ( V_22 , V_353 ) ;
error = F_176 ( V_338 , 0 , F_187 ( V_22 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_354;
error = F_188 ( V_22 , V_338 , V_350 , & V_352 ) ;
if ( error )
goto V_354;
V_351 = F_189 ( V_352 ) ;
V_351 -> V_355 [ V_167 ] = F_32 ( V_356 ) ;
V_12 = F_106 ( T_32 , V_355 ) +
( sizeof( T_16 ) * V_167 ) ;
F_190 ( V_338 , V_352 , V_12 ,
( V_12 + sizeof( T_16 ) - 1 ) ) ;
error = F_182 ( V_338 , 0 ) ;
if ( error )
goto V_357;
return;
V_354:
F_183 ( V_338 , V_349 ) ;
V_357:
F_3 ( V_22 , L_67 , V_7 , V_350 ) ;
return;
}
STATIC T_16
F_191 (
struct V_179 * V_22 ,
T_31 V_350 ,
T_16 V_358 ,
int V_167 )
{
struct V_4 * V_359 ;
struct V_360 * V_240 ;
struct V_361 * V_362 ;
T_33 V_363 ;
int error ;
V_363 = F_192 ( V_22 , V_350 , V_358 ) ;
error = F_193 ( V_22 , NULL , V_363 , 0 , 0 , & V_362 ) ;
if ( error )
goto V_364;
error = F_194 ( V_22 , NULL , V_362 , & V_240 , & V_359 , 0 ) ;
if ( error )
goto V_365;
ASSERT ( V_362 -> V_366 . V_367 == 0 ) ;
ASSERT ( V_362 -> V_366 . V_256 != 0 ) ;
V_358 = F_30 ( V_240 -> V_193 ) ;
F_27 ( V_359 ) ;
V_362 -> V_366 . V_368 = 0 ;
F_195 ( V_362 ) ;
return V_358 ;
V_365:
F_195 ( V_362 ) ;
V_364:
F_186 ( V_22 , V_350 , V_167 ) ;
return V_356 ;
}
STATIC void
F_196 (
T_1 * log )
{
T_5 * V_22 ;
T_31 V_350 ;
T_32 * V_351 ;
T_2 * V_352 ;
T_16 V_358 ;
int V_167 ;
int error ;
T_7 V_369 ;
V_22 = log -> V_6 ;
V_369 = V_22 -> V_370 ;
V_22 -> V_370 = 0 ;
for ( V_350 = 0 ; V_350 < V_22 -> V_24 . V_371 ; V_350 ++ ) {
error = F_188 ( V_22 , NULL , V_350 , & V_352 ) ;
if ( error ) {
continue;
}
V_351 = F_189 ( V_352 ) ;
F_7 ( V_352 ) ;
for ( V_167 = 0 ; V_167 < V_372 ; V_167 ++ ) {
V_358 = F_30 ( V_351 -> V_355 [ V_167 ] ) ;
while ( V_358 != V_356 ) {
V_358 = F_191 ( V_22 ,
V_350 , V_358 , V_167 ) ;
}
}
F_197 ( V_352 ) ;
}
V_22 -> V_370 = V_369 ;
}
STATIC void
F_198 (
T_1 * log ,
T_34 * V_373 ,
int V_374 )
{
int V_44 ;
V_80 * V_375 ;
T_7 V_376 = 0 ;
V_375 = ( V_80 * ) V_373 -> V_377 ;
for ( V_44 = 0 ; V_44 < ( V_374 >> 2 ) ; V_44 ++ ) {
V_376 ^= F_30 ( * V_375 ) ;
V_375 ++ ;
}
V_373 -> V_378 . V_379 = F_32 ( V_376 ) ;
}
void
F_199 (
T_1 * log ,
T_34 * V_373 ,
int V_380 )
{
int V_44 , V_45 , V_381 ;
int V_374 = V_373 -> V_382 + V_380 ;
V_80 V_383 ;
T_3 V_137 ;
F_198 ( log , V_373 , V_374 ) ;
V_383 = F_200 ( V_373 -> V_378 . V_88 ) ;
V_137 = V_373 -> V_377 ;
for ( V_44 = 0 ; V_44 < F_49 ( V_374 ) &&
V_44 < ( V_59 / V_51 ) ; V_44 ++ ) {
V_373 -> V_378 . V_384 [ V_44 ] = * ( V_80 * ) V_137 ;
* ( V_80 * ) V_137 = V_383 ;
V_137 += V_51 ;
}
if ( F_48 ( & log -> V_6 -> V_24 ) ) {
T_35 * V_385 = V_373 -> V_386 ;
for ( ; V_44 < F_49 ( V_374 ) ; V_44 ++ ) {
V_45 = V_44 / ( V_59 / V_51 ) ;
V_381 = V_44 % ( V_59 / V_51 ) ;
V_385 [ V_45 ] . V_387 . V_388 [ V_381 ] = * ( V_80 * ) V_137 ;
* ( V_80 * ) V_137 = V_383 ;
V_137 += V_51 ;
}
for ( V_44 = 1 ; V_44 < log -> V_389 ; V_44 ++ ) {
V_385 [ V_44 ] . V_387 . V_390 = V_383 ;
}
}
}
STATIC void
F_201 (
T_6 * V_72 ,
T_3 V_137 ,
T_1 * log )
{
int V_44 , V_45 , V_381 ;
for ( V_44 = 0 ; V_44 < F_49 ( F_30 ( V_72 -> V_60 ) ) &&
V_44 < ( V_59 / V_51 ) ; V_44 ++ ) {
* ( V_80 * ) V_137 = * ( V_80 * ) & V_72 -> V_384 [ V_44 ] ;
V_137 += V_51 ;
}
if ( F_48 ( & log -> V_6 -> V_24 ) ) {
T_35 * V_385 = ( T_35 * ) V_72 ;
for ( ; V_44 < F_49 ( F_30 ( V_72 -> V_60 ) ) ; V_44 ++ ) {
V_45 = V_44 / ( V_59 / V_51 ) ;
V_381 = V_44 % ( V_59 / V_51 ) ;
* ( V_80 * ) V_137 = V_385 [ V_45 ] . V_387 . V_388 [ V_381 ] ;
V_137 += V_51 ;
}
}
}
STATIC int
F_202 (
T_1 * log ,
T_6 * V_72 ,
T_4 V_176 )
{
int V_391 ;
if ( F_33 ( V_72 -> V_29 != F_32 ( V_30 ) ) ) {
F_4 ( L_68 ,
V_120 , log -> V_6 ) ;
return F_34 ( V_15 ) ;
}
if ( F_33 (
( ! V_72 -> V_92 ||
( F_30 ( V_72 -> V_92 ) & ( ~ V_392 ) ) ) ) ) {
F_3 ( log -> V_6 , L_69 ,
V_7 , F_30 ( V_72 -> V_92 ) ) ;
return F_34 ( V_57 ) ;
}
V_391 = F_30 ( V_72 -> V_60 ) ;
if ( F_33 ( V_391 <= 0 || V_391 > V_69 ) ) {
F_4 ( L_70 ,
V_120 , log -> V_6 ) ;
return F_34 ( V_15 ) ;
}
if ( F_33 ( V_176 > log -> V_2 || V_176 > V_69 ) ) {
F_4 ( L_71 ,
V_120 , log -> V_6 ) ;
return F_34 ( V_15 ) ;
}
return 0 ;
}
STATIC int
F_203 (
T_1 * log ,
T_4 V_62 ,
T_4 V_71 ,
int V_155 )
{
T_6 * V_72 ;
T_4 V_11 ;
T_3 V_12 ;
T_2 * V_393 , * V_394 ;
int error = 0 , V_58 ;
int V_395 , V_396 ;
int V_78 , V_397 , V_398 ;
struct V_121 V_322 [ V_399 ] ;
ASSERT ( V_62 != V_71 ) ;
if ( F_48 ( & log -> V_6 -> V_24 ) ) {
V_393 = F_2 ( log , 1 ) ;
if ( ! V_393 )
return V_48 ;
error = F_19 ( log , V_71 , 1 , V_393 , & V_12 ) ;
if ( error )
goto V_400;
V_72 = ( T_6 * ) V_12 ;
error = F_202 ( log , V_72 , V_71 ) ;
if ( error )
goto V_400;
V_58 = F_30 ( V_72 -> V_58 ) ;
if ( ( F_30 ( V_72 -> V_92 ) & V_93 ) &&
( V_58 > V_59 ) ) {
V_78 = V_58 / V_59 ;
if ( V_58 % V_59 )
V_78 ++ ;
F_8 ( V_393 ) ;
V_393 = F_2 ( log , V_78 ) ;
} else {
V_78 = 1 ;
}
} else {
ASSERT ( log -> V_9 == 1 ) ;
V_78 = 1 ;
V_393 = F_2 ( log , 1 ) ;
V_58 = V_401 ;
}
if ( ! V_393 )
return V_48 ;
V_394 = F_2 ( log , F_49 ( V_58 ) ) ;
if ( ! V_394 ) {
F_8 ( V_393 ) ;
return V_48 ;
}
memset ( V_322 , 0 , sizeof( V_322 ) ) ;
if ( V_71 <= V_62 ) {
for ( V_11 = V_71 ; V_11 < V_62 ; ) {
error = F_19 ( log , V_11 , V_78 , V_393 , & V_12 ) ;
if ( error )
goto V_402;
V_72 = ( T_6 * ) V_12 ;
error = F_202 ( log , V_72 , V_11 ) ;
if ( error )
goto V_402;
V_395 = ( int ) F_49 ( F_30 ( V_72 -> V_60 ) ) ;
error = F_19 ( log , V_11 + V_78 , V_395 , V_394 ,
& V_12 ) ;
if ( error )
goto V_402;
F_201 ( V_72 , V_12 , log ) ;
if ( ( error = F_167 ( log ,
V_322 , V_72 , V_12 , V_155 ) ) )
goto V_402;
V_11 += V_395 + V_78 ;
}
} else {
V_11 = V_71 ;
while ( V_11 < log -> V_2 ) {
V_12 = V_393 -> V_14 ;
V_397 = 0 ;
V_398 = 0 ;
if ( V_11 + V_78 <= log -> V_2 ) {
error = F_19 ( log , V_11 , V_78 , V_393 ,
& V_12 ) ;
if ( error )
goto V_402;
} else {
if ( V_11 != log -> V_2 ) {
ASSERT ( V_11 <= V_69 ) ;
V_397 = log -> V_2 - ( int ) V_11 ;
ASSERT ( V_397 > 0 ) ;
error = F_19 ( log , V_11 ,
V_397 , V_393 ,
& V_12 ) ;
if ( error )
goto V_402;
}
V_398 = V_78 - V_397 ;
error = F_20 ( log , 0 ,
V_398 , V_393 ,
V_12 + F_11 ( V_397 ) ) ;
if ( error )
goto V_402;
}
V_72 = ( T_6 * ) V_12 ;
error = F_202 ( log , V_72 ,
V_397 ? V_11 : 0 ) ;
if ( error )
goto V_402;
V_395 = ( int ) F_49 ( F_30 ( V_72 -> V_60 ) ) ;
V_11 += V_78 ;
if ( V_11 + V_395 <= log -> V_2 ) {
error = F_19 ( log , V_11 , V_395 , V_394 ,
& V_12 ) ;
if ( error )
goto V_402;
} else {
V_12 = V_394 -> V_14 ;
V_396 = 0 ;
if ( V_11 != log -> V_2 ) {
ASSERT ( ! V_398 ) ;
ASSERT ( V_11 <= V_69 ) ;
V_396 =
log -> V_2 - ( int ) V_11 ;
ASSERT ( V_396 > 0 ) ;
error = F_19 ( log , V_11 ,
V_396 , V_394 ,
& V_12 ) ;
if ( error )
goto V_402;
}
error = F_20 ( log , 0 ,
V_395 - V_396 , V_393 ,
V_12 + F_11 ( V_396 ) ) ;
if ( error )
goto V_402;
}
F_201 ( V_72 , V_12 , log ) ;
if ( ( error = F_167 ( log , V_322 ,
V_72 , V_12 , V_155 ) ) )
goto V_402;
V_11 += V_395 ;
}
ASSERT ( V_11 >= log -> V_2 ) ;
V_11 -= log -> V_2 ;
while ( V_11 < V_62 ) {
error = F_19 ( log , V_11 , V_78 , V_393 , & V_12 ) ;
if ( error )
goto V_402;
V_72 = ( T_6 * ) V_12 ;
error = F_202 ( log , V_72 , V_11 ) ;
if ( error )
goto V_402;
V_395 = ( int ) F_49 ( F_30 ( V_72 -> V_60 ) ) ;
error = F_19 ( log , V_11 + V_78 , V_395 , V_394 ,
& V_12 ) ;
if ( error )
goto V_402;
F_201 ( V_72 , V_12 , log ) ;
if ( ( error = F_167 ( log , V_322 ,
V_72 , V_12 , V_155 ) ) )
goto V_402;
V_11 += V_395 + V_78 ;
}
}
V_402:
F_8 ( V_394 ) ;
V_400:
F_8 ( V_393 ) ;
return error ;
}
STATIC int
F_204 (
T_1 * log ,
T_4 V_62 ,
T_4 V_71 )
{
int error , V_44 ;
ASSERT ( V_62 != V_71 ) ;
log -> V_178 = F_72 ( V_403 *
sizeof( struct V_132 ) ,
V_128 ) ;
for ( V_44 = 0 ; V_44 < V_403 ; V_44 ++ )
F_73 ( & log -> V_178 [ V_44 ] ) ;
error = F_203 ( log , V_62 , V_71 ,
V_320 ) ;
if ( error != 0 ) {
F_103 ( log -> V_178 ) ;
log -> V_178 = NULL ;
return error ;
}
error = F_203 ( log , V_62 , V_71 ,
V_321 ) ;
#ifdef F_185
if ( ! error ) {
int V_44 ;
for ( V_44 = 0 ; V_44 < V_403 ; V_44 ++ )
ASSERT ( F_79 ( & log -> V_178 [ V_44 ] ) ) ;
}
#endif
F_103 ( log -> V_178 ) ;
log -> V_178 = NULL ;
return error ;
}
STATIC int
F_205 (
T_1 * log ,
T_4 V_62 ,
T_4 V_71 )
{
int error ;
T_2 * V_5 ;
T_36 * V_404 ;
error = F_204 ( log , V_62 , V_71 ) ;
if ( error )
return error ;
if ( F_206 ( log -> V_6 ) ) {
return ( V_57 ) ;
}
F_207 ( log -> V_6 ) ;
V_5 = F_208 ( log -> V_6 , 0 ) ;
F_209 ( V_5 ) ;
ASSERT ( ! ( F_210 ( V_5 ) ) ) ;
F_15 ( V_5 ) ;
F_211 ( V_5 ) ;
F_16 ( log -> V_6 , V_5 ) ;
error = F_17 ( V_5 ) ;
if ( error ) {
F_18 ( V_5 , V_7 ) ;
ASSERT ( 0 ) ;
F_27 ( V_5 ) ;
return error ;
}
V_404 = & log -> V_6 -> V_24 ;
F_212 ( log -> V_6 , F_213 ( V_5 ) ) ;
ASSERT ( V_404 -> V_405 == V_406 ) ;
ASSERT ( F_214 ( V_404 ) ) ;
F_27 ( V_5 ) ;
F_215 ( log -> V_6 ) ;
F_216 ( log ) ;
log -> V_407 &= ~ V_408 ;
return 0 ;
}
int
V_136 (
T_1 * log )
{
T_4 V_62 , V_71 ;
int error ;
if ( ( error = F_54 ( log , & V_62 , & V_71 ) ) )
return error ;
if ( V_71 != V_62 ) {
if ( ( error = F_217 ( log -> V_6 , L_72 ) ) ) {
return error ;
}
F_116 ( log -> V_6 , L_73 ,
log -> V_6 -> V_409 ? log -> V_6 -> V_409
: L_74 ) ;
error = F_205 ( log , V_62 , V_71 ) ;
log -> V_407 |= V_410 ;
}
return error ;
}
int
F_218 (
T_1 * log )
{
if ( log -> V_407 & V_410 ) {
int error ;
error = F_184 ( log ) ;
if ( error ) {
F_109 ( log -> V_6 , L_75 ) ;
return error ;
}
F_219 ( log -> V_6 , V_411 ) ;
F_196 ( log ) ;
F_216 ( log ) ;
F_116 ( log -> V_6 , L_76 ,
log -> V_6 -> V_409 ? log -> V_6 -> V_409
: L_74 ) ;
log -> V_407 &= ~ V_410 ;
} else {
F_220 ( log -> V_6 , L_77 ) ;
}
return 0 ;
}
void
F_216 (
T_1 * log )
{
T_5 * V_22 ;
T_37 * V_412 ;
T_2 * V_413 ;
T_2 * V_352 ;
T_31 V_350 ;
T_26 V_414 ;
T_26 V_415 ;
T_26 V_416 ;
int error ;
V_22 = log -> V_6 ;
V_414 = 0LL ;
V_415 = 0LL ;
V_416 = 0LL ;
for ( V_350 = 0 ; V_350 < V_22 -> V_24 . V_371 ; V_350 ++ ) {
error = F_221 ( V_22 , NULL , V_350 , 0 , & V_413 ) ;
if ( error ) {
F_109 ( V_22 , L_78 ,
V_7 , V_350 , error ) ;
} else {
V_412 = F_222 ( V_413 ) ;
V_414 += F_30 ( V_412 -> V_417 ) +
F_30 ( V_412 -> V_418 ) ;
F_27 ( V_413 ) ;
}
error = F_188 ( V_22 , NULL , V_350 , & V_352 ) ;
if ( error ) {
F_109 ( V_22 , L_79 ,
V_7 , V_350 , error ) ;
} else {
struct V_419 * V_351 = F_189 ( V_352 ) ;
V_415 += F_30 ( V_351 -> V_420 ) ;
V_416 += F_30 ( V_351 -> V_421 ) ;
F_27 ( V_352 ) ;
}
}
}
