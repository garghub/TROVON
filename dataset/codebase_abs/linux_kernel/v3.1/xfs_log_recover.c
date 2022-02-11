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
V_5 = F_6 ( log -> V_6 -> V_10 , F_7 ( V_3 ) , 0 ) ;
if ( V_5 )
F_8 ( V_5 ) ;
return V_5 ;
}
STATIC void
F_9 (
T_2 * V_5 )
{
F_10 ( V_5 ) ;
}
STATIC T_3
F_11 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 )
{
T_4 V_12 = V_11 & ( ( T_4 ) log -> V_9 - 1 ) ;
ASSERT ( F_7 ( V_12 + V_3 ) <= F_12 ( V_5 ) ) ;
return V_5 -> V_13 + F_7 ( V_12 ) ;
}
STATIC int
F_13 (
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
return V_14 ;
}
V_11 = F_14 ( V_11 , log -> V_9 ) ;
V_3 = F_5 ( V_3 , log -> V_9 ) ;
ASSERT ( V_3 > 0 ) ;
ASSERT ( F_7 ( V_3 ) <= F_12 ( V_5 ) ) ;
F_15 ( V_5 , log -> V_15 + V_11 ) ;
F_16 ( V_5 ) ;
F_17 ( V_5 , F_7 ( V_3 ) ) ;
F_18 ( log -> V_6 , V_5 ) ;
error = F_19 ( V_5 ) ;
if ( error )
F_20 ( L_2 , log -> V_6 ,
V_5 , F_21 ( V_5 ) ) ;
return error ;
}
STATIC int
F_22 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 ,
T_3 * V_12 )
{
int error ;
error = F_13 ( log , V_11 , V_3 , V_5 ) ;
if ( error )
return error ;
* V_12 = F_11 ( log , V_11 , V_3 , V_5 ) ;
return 0 ;
}
STATIC int
F_23 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 ,
T_3 V_12 )
{
T_3 V_16 = V_5 -> V_13 ;
int V_17 = V_5 -> V_18 ;
int error , V_19 ;
error = F_24 ( V_5 , V_12 , F_7 ( V_3 ) ) ;
if ( error )
return error ;
error = F_13 ( log , V_11 , V_3 , V_5 ) ;
V_19 = F_24 ( V_5 , V_16 , V_17 ) ;
if ( error )
return error ;
return V_19 ;
}
STATIC int
F_25 (
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
return V_14 ;
}
V_11 = F_14 ( V_11 , log -> V_9 ) ;
V_3 = F_5 ( V_3 , log -> V_9 ) ;
ASSERT ( V_3 > 0 ) ;
ASSERT ( F_7 ( V_3 ) <= F_12 ( V_5 ) ) ;
F_15 ( V_5 , log -> V_15 + V_11 ) ;
F_26 ( V_5 ) ;
F_27 ( V_5 ) ;
F_28 ( V_5 ) ;
F_17 ( V_5 , F_7 ( V_3 ) ) ;
if ( ( error = F_29 ( log -> V_6 , V_5 ) ) )
F_20 ( L_3 , log -> V_6 ,
V_5 , F_21 ( V_5 ) ) ;
return error ;
}
STATIC void
F_30 (
T_5 * V_20 ,
T_6 * V_21 )
{
F_31 ( V_20 , L_4 ,
V_7 , & V_20 -> V_22 . V_23 , V_24 ) ;
F_31 ( V_20 , L_5 ,
& V_21 -> V_25 , F_32 ( V_21 -> V_26 ) ) ;
}
STATIC int
F_33 (
T_5 * V_20 ,
T_6 * V_21 )
{
ASSERT ( V_21 -> V_27 == F_34 ( V_28 ) ) ;
if ( F_35 ( V_21 -> V_26 != F_34 ( V_24 ) ) ) {
F_3 ( V_20 ,
L_6 ) ;
F_30 ( V_20 , V_21 ) ;
F_4 ( L_7 ,
V_8 , V_20 ) ;
return F_36 ( V_14 ) ;
} else if ( F_35 ( ! F_37 ( & V_20 -> V_22 . V_23 , & V_21 -> V_25 ) ) ) {
F_3 ( V_20 ,
L_8 ) ;
F_30 ( V_20 , V_21 ) ;
F_4 ( L_9 ,
V_8 , V_20 ) ;
return F_36 ( V_14 ) ;
}
return 0 ;
}
STATIC int
F_38 (
T_5 * V_20 ,
T_6 * V_21 )
{
ASSERT ( V_21 -> V_27 == F_34 ( V_28 ) ) ;
if ( F_39 ( & V_21 -> V_25 ) ) {
F_3 ( V_20 , L_10 ) ;
} else if ( F_35 ( ! F_37 ( & V_20 -> V_22 . V_23 , & V_21 -> V_25 ) ) ) {
F_3 ( V_20 , L_11 ) ;
F_30 ( V_20 , V_21 ) ;
F_4 ( L_12 ,
V_8 , V_20 ) ;
return F_36 ( V_14 ) ;
}
return 0 ;
}
STATIC void
F_40 (
struct V_4 * V_5 )
{
if ( V_5 -> V_29 ) {
F_20 ( L_13 ,
V_5 -> V_30 -> V_31 , V_5 ,
F_21 ( V_5 ) ) ;
F_41 ( V_5 -> V_30 -> V_31 ,
V_32 ) ;
}
V_5 -> V_33 = NULL ;
F_42 ( V_5 , 0 ) ;
}
STATIC int
F_43 (
T_1 * log ,
T_2 * V_5 ,
T_4 V_34 ,
T_4 * V_35 ,
T_7 V_36 )
{
T_3 V_12 ;
T_4 V_37 ;
T_4 V_38 ;
T_7 V_39 ;
int error ;
V_38 = * V_35 ;
V_37 = F_44 ( V_34 , V_38 ) ;
while ( V_37 != V_34 && V_37 != V_38 ) {
error = F_22 ( log , V_37 , 1 , V_5 , & V_12 ) ;
if ( error )
return error ;
V_39 = F_45 ( V_12 ) ;
if ( V_39 == V_36 )
V_38 = V_37 ;
else
V_34 = V_37 ;
V_37 = F_44 ( V_34 , V_38 ) ;
}
ASSERT ( ( V_37 == V_34 && V_37 + 1 == V_38 ) ||
( V_37 == V_38 && V_37 - 1 == V_34 ) ) ;
* V_35 = V_38 ;
return 0 ;
}
STATIC int
F_46 (
T_1 * log ,
T_4 V_40 ,
int V_3 ,
T_7 V_41 ,
T_4 * V_42 )
{
T_4 V_43 , V_44 ;
T_7 V_36 ;
T_2 * V_5 ;
T_4 V_45 ;
T_3 V_46 = NULL ;
int error = 0 ;
V_45 = 1 << F_47 ( V_3 ) ;
while ( ! ( V_5 = F_2 ( log , V_45 ) ) ) {
V_45 >>= 1 ;
if ( V_45 < log -> V_9 )
return V_47 ;
}
for ( V_43 = V_40 ; V_43 < V_40 + V_3 ; V_43 += V_45 ) {
int V_48 ;
V_48 = F_48 ( V_45 , ( V_40 + V_3 - V_43 ) ) ;
error = F_22 ( log , V_43 , V_48 , V_5 , & V_46 ) ;
if ( error )
goto V_49;
for ( V_44 = 0 ; V_44 < V_48 ; V_44 ++ ) {
V_36 = F_45 ( V_46 ) ;
if ( V_36 == V_41 ) {
* V_42 = V_43 + V_44 ;
goto V_49;
}
V_46 += V_50 ;
}
}
* V_42 = - 1 ;
V_49:
F_9 ( V_5 ) ;
return error ;
}
STATIC int
F_49 (
T_1 * log ,
T_4 V_40 ,
T_4 * V_35 ,
int V_51 )
{
T_4 V_43 ;
T_2 * V_5 ;
T_3 V_12 = NULL ;
T_6 * V_21 = NULL ;
int error = 0 ;
int V_52 = 0 ;
int V_53 = * V_35 - V_40 ;
int V_54 ;
ASSERT ( V_40 != 0 || * V_35 != V_40 ) ;
if ( ! ( V_5 = F_2 ( log , V_53 ) ) ) {
if ( ! ( V_5 = F_2 ( log , 1 ) ) )
return V_47 ;
V_52 = 1 ;
} else {
error = F_22 ( log , V_40 , V_53 , V_5 , & V_12 ) ;
if ( error )
goto V_49;
V_12 += ( ( V_53 - 1 ) << V_55 ) ;
}
for ( V_43 = ( * V_35 ) - 1 ; V_43 >= 0 ; V_43 -- ) {
if ( V_43 < V_40 ) {
F_3 ( log -> V_6 ,
L_14 ) ;
ASSERT ( 0 ) ;
error = F_36 ( V_56 ) ;
goto V_49;
}
if ( V_52 ) {
error = F_22 ( log , V_43 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_49;
}
V_21 = ( T_6 * ) V_12 ;
if ( V_21 -> V_27 == F_34 ( V_28 ) )
break;
if ( ! V_52 )
V_12 -= V_50 ;
}
if ( V_43 == - 1 ) {
error = - 1 ;
goto V_49;
}
if ( ( error = F_38 ( log -> V_6 , V_21 ) ) )
goto V_49;
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
T_7 V_57 = F_32 ( V_21 -> V_57 ) ;
V_54 = V_57 / V_58 ;
if ( V_57 % V_58 )
V_54 ++ ;
} else {
V_54 = 1 ;
}
if ( * V_35 - V_43 + V_51 !=
F_51 ( F_32 ( V_21 -> V_59 ) ) + V_54 )
* V_35 = V_43 ;
V_49:
F_9 ( V_5 ) ;
return error ;
}
STATIC int
F_52 (
T_1 * log ,
T_4 * V_60 )
{
T_2 * V_5 ;
T_3 V_12 ;
T_4 V_42 , V_34 , V_40 , V_35 , V_61 ;
int V_62 ;
T_7 V_63 , V_64 ;
T_7 V_65 ;
int error , V_66 = log -> V_2 ;
if ( ( error = F_53 ( log , & V_34 ) ) == - 1 ) {
* V_60 = V_34 ;
if ( ! V_34 ) {
F_3 ( log -> V_6 , L_15 ) ;
}
return 0 ;
} else if ( error ) {
F_3 ( log -> V_6 , L_16 ) ;
return error ;
}
V_34 = 0 ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_47 ;
error = F_22 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_63 = F_45 ( V_12 ) ;
V_35 = V_61 = V_66 - 1 ;
error = F_22 ( log , V_35 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_64 = F_45 ( V_12 ) ;
ASSERT ( V_64 != 0 ) ;
if ( V_63 == V_64 ) {
V_61 = V_66 ;
V_65 = V_64 - 1 ;
} else {
V_65 = V_64 ;
if ( ( error = F_43 ( log , V_5 , V_34 ,
& V_61 , V_64 ) ) )
goto V_67;
}
V_62 = F_54 ( log ) ;
if ( V_61 >= V_62 ) {
V_40 = V_61 - V_62 ;
if ( ( error = F_46 ( log ,
V_40 , V_62 ,
V_65 , & V_42 ) ) )
goto V_67;
if ( V_42 != - 1 )
V_61 = V_42 ;
} else {
ASSERT ( V_61 <= V_68 &&
( T_4 ) V_62 >= V_61 ) ;
V_40 = V_66 - ( V_62 - V_61 ) ;
if ( ( error = F_46 ( log , V_40 ,
V_62 - ( int ) V_61 ,
( V_65 - 1 ) , & V_42 ) ) )
goto V_67;
if ( V_42 != - 1 ) {
V_61 = V_42 ;
goto V_69;
}
V_40 = 0 ;
ASSERT ( V_61 <= V_68 ) ;
if ( ( error = F_46 ( log ,
V_40 , ( int ) V_61 ,
V_65 , & V_42 ) ) )
goto V_67;
if ( V_42 != - 1 )
V_61 = V_42 ;
}
V_69:
V_62 = F_55 ( log ) ;
if ( V_61 >= V_62 ) {
V_40 = V_61 - V_62 ;
if ( ( error = F_49 ( log , V_40 ,
& V_61 , 0 ) ) == - 1 ) {
error = F_36 ( V_56 ) ;
goto V_67;
} else if ( error )
goto V_67;
} else {
V_40 = 0 ;
ASSERT ( V_61 <= V_68 ) ;
if ( ( error = F_49 ( log , V_40 ,
& V_61 , 0 ) ) == - 1 ) {
V_40 = V_66 - ( V_62 - V_61 ) ;
V_42 = V_66 ;
ASSERT ( V_40 <= V_68 &&
( T_4 ) V_66 - V_40 >= 0 ) ;
ASSERT ( V_61 <= V_68 ) ;
if ( ( error = F_49 ( log ,
V_40 , & V_42 ,
( int ) V_61 ) ) == - 1 ) {
error = F_36 ( V_56 ) ;
goto V_67;
} else if ( error )
goto V_67;
if ( V_42 != V_66 )
V_61 = V_42 ;
} else if ( error )
goto V_67;
}
F_9 ( V_5 ) ;
if ( V_61 == V_66 )
* V_60 = 0 ;
else
* V_60 = V_61 ;
return 0 ;
V_67:
F_9 ( V_5 ) ;
if ( error )
F_3 ( log -> V_6 , L_17 ) ;
return error ;
}
STATIC int
F_56 (
T_1 * log ,
T_4 * V_61 ,
T_4 * V_70 )
{
T_6 * V_71 ;
T_8 * V_72 ;
T_3 V_12 = NULL ;
T_2 * V_5 ;
int error , V_43 , V_73 ;
T_4 V_74 ;
T_4 V_75 ;
T_9 V_76 ;
int V_77 ;
V_73 = 0 ;
if ( ( error = F_52 ( log , V_61 ) ) )
return error ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_47 ;
if ( * V_61 == 0 ) {
error = F_22 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
if ( F_45 ( V_12 ) == 0 ) {
* V_70 = 0 ;
goto V_78;
}
}
ASSERT ( * V_61 < V_68 ) ;
for ( V_43 = ( int ) ( * V_61 ) - 1 ; V_43 >= 0 ; V_43 -- ) {
error = F_22 ( log , V_43 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
if ( * ( V_79 * ) V_12 == F_34 ( V_28 ) ) {
V_73 = 1 ;
break;
}
}
if ( ! V_73 ) {
for ( V_43 = log -> V_2 - 1 ; V_43 >= ( int ) ( * V_61 ) ; V_43 -- ) {
error = F_22 ( log , V_43 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
if ( * ( V_79 * ) V_12 ==
F_34 ( V_28 ) ) {
V_73 = 2 ;
break;
}
}
}
if ( ! V_73 ) {
F_3 ( log -> V_6 , L_18 , V_7 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
V_71 = ( T_6 * ) V_12 ;
* V_70 = F_57 ( F_58 ( V_71 -> V_80 ) ) ;
log -> V_81 = V_43 ;
log -> V_82 = ( int ) * V_61 ;
log -> V_83 = F_32 ( V_71 -> V_84 ) ;
if ( V_73 == 2 )
log -> V_83 ++ ;
F_59 ( & log -> V_85 , F_58 ( V_71 -> V_80 ) ) ;
F_59 ( & log -> V_86 , F_58 ( V_71 -> V_87 ) ) ;
F_60 ( & log -> V_88 , log -> V_83 ,
F_7 ( log -> V_82 ) ) ;
F_60 ( & log -> V_89 , log -> V_83 ,
F_7 ( log -> V_82 ) ) ;
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
int V_57 = F_32 ( V_71 -> V_57 ) ;
int V_90 = F_32 ( V_71 -> V_90 ) ;
if ( ( V_90 & V_91 ) &&
( V_57 > V_58 ) ) {
V_77 = V_57 / V_58 ;
if ( V_57 % V_58 )
V_77 ++ ;
} else {
V_77 = 1 ;
}
} else {
V_77 = 1 ;
}
V_75 = ( V_43 + V_77 + ( int )
F_51 ( F_32 ( V_71 -> V_59 ) ) ) % log -> V_2 ;
V_76 = F_61 ( & log -> V_85 ) ;
if ( * V_61 == V_75 &&
F_32 ( V_71 -> V_92 ) == 1 ) {
V_74 = ( V_43 + V_77 ) % log -> V_2 ;
error = F_22 ( log , V_74 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
V_72 = ( T_8 * ) V_12 ;
if ( V_72 -> V_93 & V_94 ) {
F_62 ( & log -> V_85 ,
log -> V_83 , V_75 ) ;
F_62 ( & log -> V_86 ,
log -> V_83 , V_75 ) ;
* V_70 = V_75 ;
log -> V_6 -> V_95 |= V_96 ;
}
}
if ( ! F_63 ( log -> V_6 -> V_10 ) )
error = F_64 ( log , V_76 ) ;
V_78:
F_9 ( V_5 ) ;
if ( error )
F_3 ( log -> V_6 , L_19 ) ;
return error ;
}
STATIC int
F_53 (
T_1 * log ,
T_4 * V_11 )
{
T_2 * V_5 ;
T_3 V_12 ;
T_7 V_97 , V_98 ;
T_4 V_42 , V_35 , V_40 ;
T_4 V_62 ;
int error , V_66 = log -> V_2 ;
* V_11 = 0 ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_47 ;
error = F_22 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_97 = F_45 ( V_12 ) ;
if ( V_97 == 0 ) {
* V_11 = 0 ;
F_9 ( V_5 ) ;
return - 1 ;
}
error = F_22 ( log , V_66 - 1 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_98 = F_45 ( V_12 ) ;
if ( V_98 != 0 ) {
F_9 ( V_5 ) ;
return 0 ;
} else if ( V_97 != 1 ) {
F_3 ( log -> V_6 ,
L_20 ) ;
return F_36 ( V_99 ) ;
}
V_35 = V_66 - 1 ;
if ( ( error = F_43 ( log , V_5 , 0 , & V_35 , 0 ) ) )
goto V_67;
V_62 = F_54 ( log ) ;
ASSERT ( V_62 <= V_68 ) ;
if ( V_35 < V_62 )
V_62 = V_35 ;
V_40 = V_35 - V_62 ;
if ( ( error = F_46 ( log , V_40 ,
( int ) V_62 , 0 , & V_42 ) ) )
goto V_67;
if ( V_42 != - 1 )
V_35 = V_42 ;
if ( ( error = F_49 ( log , V_40 ,
& V_35 , 0 ) ) == - 1 ) {
error = F_36 ( V_56 ) ;
goto V_67;
} else if ( error )
goto V_67;
* V_11 = V_35 ;
V_67:
F_9 ( V_5 ) ;
if ( error )
return error ;
return - 1 ;
}
STATIC void
F_65 (
T_1 * log ,
T_3 V_46 ,
int V_36 ,
int V_100 ,
int V_101 ,
int V_102 )
{
T_6 * V_103 = ( T_6 * ) V_46 ;
memset ( V_46 , 0 , V_50 ) ;
V_103 -> V_27 = F_34 ( V_28 ) ;
V_103 -> V_84 = F_34 ( V_36 ) ;
V_103 -> V_90 = F_34 (
F_50 ( & log -> V_6 -> V_22 ) ? 2 : 1 ) ;
V_103 -> V_87 = F_66 ( F_67 ( V_36 , V_100 ) ) ;
V_103 -> V_80 = F_66 ( F_67 ( V_101 , V_102 ) ) ;
V_103 -> V_26 = F_34 ( V_24 ) ;
memcpy ( & V_103 -> V_25 , & log -> V_6 -> V_22 . V_23 , sizeof( V_104 ) ) ;
}
STATIC int
F_68 (
T_1 * log ,
int V_36 ,
int V_105 ,
int V_106 ,
int V_101 ,
int V_102 )
{
T_3 V_12 ;
T_2 * V_5 ;
int V_107 , V_108 ;
int V_109 = log -> V_9 ;
int V_110 = V_105 + V_106 ;
int V_45 ;
int error = 0 ;
int V_43 , V_44 = 0 ;
V_45 = 1 << F_47 ( V_106 ) ;
while ( ! ( V_5 = F_2 ( log , V_45 ) ) ) {
V_45 >>= 1 ;
if ( V_45 < V_109 )
return V_47 ;
}
V_107 = F_14 ( V_105 , V_109 ) ;
if ( V_107 != V_105 ) {
error = F_13 ( log , V_105 , 1 , V_5 ) ;
if ( error )
goto V_111;
V_44 = V_105 - V_107 ;
}
for ( V_43 = V_105 ; V_43 < V_110 ; V_43 += V_45 ) {
int V_48 , V_112 ;
V_48 = F_48 ( V_45 , V_110 - V_105 ) ;
V_112 = V_48 - V_44 ;
V_108 = F_14 ( V_110 , V_109 ) ;
if ( V_44 == 0 && ( V_105 + V_112 > V_108 ) ) {
V_12 = V_5 -> V_13 + F_7 ( V_108 - V_105 ) ;
error = F_23 ( log , V_108 , V_109 ,
V_5 , V_12 ) ;
if ( error )
break;
}
V_12 = F_11 ( log , V_105 , V_112 , V_5 ) ;
for (; V_44 < V_112 ; V_44 ++ ) {
F_65 ( log , V_12 , V_36 , V_43 + V_44 ,
V_101 , V_102 ) ;
V_12 += V_50 ;
}
error = F_25 ( log , V_105 , V_112 , V_5 ) ;
if ( error )
break;
V_105 += V_112 ;
V_44 = 0 ;
}
V_111:
F_9 ( V_5 ) ;
return error ;
}
STATIC int
F_64 (
T_1 * log ,
T_9 V_76 )
{
int V_101 , V_113 ;
int V_102 , V_114 ;
int V_115 , V_116 ;
int V_117 ;
int error ;
V_101 = F_69 ( V_76 ) ;
V_102 = F_57 ( V_76 ) ;
V_113 = log -> V_83 ;
V_114 = log -> V_82 ;
if ( V_113 == V_101 ) {
if ( F_35 ( V_114 < V_102 || V_114 >= log -> V_2 ) ) {
F_4 ( L_21 ,
V_118 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
V_115 = V_102 + ( log -> V_2 - V_114 ) ;
} else {
if ( F_35 ( V_114 >= V_102 || V_113 != ( V_101 + 1 ) ) ) {
F_4 ( L_22 ,
V_118 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
V_115 = V_102 - V_114 ;
}
if ( V_115 <= 0 ) {
ASSERT ( V_115 == 0 ) ;
return 0 ;
}
V_116 = F_54 ( log ) ;
V_116 = F_70 ( V_116 , V_115 ) ;
if ( ( V_114 + V_116 ) <= log -> V_2 ) {
error = F_68 ( log , ( V_113 - 1 ) ,
V_114 , V_116 , V_101 ,
V_102 ) ;
if ( error )
return error ;
} else {
V_117 = log -> V_2 - V_114 ;
error = F_68 ( log , ( V_113 - 1 ) ,
V_114 , V_117 , V_101 ,
V_102 ) ;
if ( error )
return error ;
V_117 = V_116 - ( log -> V_2 - V_114 ) ;
error = F_68 ( log , V_113 , 0 , V_117 ,
V_101 , V_102 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC T_10 *
F_71 (
struct V_119 * V_21 ,
T_11 V_120 )
{
T_10 * V_121 ;
struct V_122 * V_123 ;
F_72 (trans, n, head, r_list) {
if ( V_121 -> V_124 == V_120 )
return V_121 ;
}
return NULL ;
}
STATIC void
F_73 (
struct V_119 * V_21 ,
T_11 V_120 ,
T_9 V_125 )
{
T_10 * V_121 ;
V_121 = F_74 ( sizeof( T_10 ) , V_126 ) ;
V_121 -> V_124 = V_120 ;
V_121 -> V_127 = V_125 ;
F_75 ( & V_121 -> V_128 ) ;
F_76 ( & V_121 -> V_129 ) ;
F_77 ( & V_121 -> V_129 , V_21 ) ;
}
STATIC void
F_78 (
struct V_130 * V_21 )
{
T_12 * V_131 ;
V_131 = F_74 ( sizeof( T_12 ) , V_126 ) ;
F_75 ( & V_131 -> V_132 ) ;
F_79 ( & V_131 -> V_132 , V_21 ) ;
}
STATIC int
F_80 (
struct log * log ,
T_10 * V_121 ,
T_3 V_133 ,
int V_134 )
{
T_12 * V_131 ;
T_3 V_135 , V_136 ;
int V_137 ;
if ( F_81 ( & V_121 -> V_128 ) ) {
F_78 ( & V_121 -> V_128 ) ;
V_135 = ( T_3 ) & V_121 -> V_138 +
sizeof( V_139 ) - V_134 ;
memcpy ( V_135 , V_133 , V_134 ) ;
return 0 ;
}
V_131 = F_82 ( V_121 -> V_128 . V_140 , T_12 , V_132 ) ;
V_136 = V_131 -> V_141 [ V_131 -> V_142 - 1 ] . V_143 ;
V_137 = V_131 -> V_141 [ V_131 -> V_142 - 1 ] . V_144 ;
V_135 = F_83 ( V_136 , V_134 + V_137 , V_137 , 0u ) ;
memcpy ( & V_135 [ V_137 ] , V_133 , V_134 ) ;
V_131 -> V_141 [ V_131 -> V_142 - 1 ] . V_144 += V_134 ;
V_131 -> V_141 [ V_131 -> V_142 - 1 ] . V_143 = V_135 ;
F_84 ( log , V_121 , V_131 , 0 ) ;
return 0 ;
}
STATIC int
F_85 (
struct log * log ,
T_10 * V_121 ,
T_3 V_133 ,
int V_134 )
{
T_13 * V_145 ;
T_12 * V_131 ;
T_3 V_135 ;
if ( ! V_134 )
return 0 ;
if ( F_81 ( & V_121 -> V_128 ) ) {
if ( * ( T_7 * ) V_133 != V_146 ) {
F_3 ( log -> V_6 , L_23 ,
V_7 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
if ( V_134 == sizeof( V_139 ) )
F_78 ( & V_121 -> V_128 ) ;
memcpy ( & V_121 -> V_138 , V_133 , V_134 ) ;
return 0 ;
}
V_135 = F_86 ( V_134 , V_126 ) ;
memcpy ( V_135 , V_133 , V_134 ) ;
V_145 = ( T_13 * ) V_135 ;
V_131 = F_82 ( V_121 -> V_128 . V_140 , T_12 , V_132 ) ;
if ( V_131 -> V_147 != 0 &&
V_131 -> V_147 == V_131 -> V_142 ) {
F_78 ( & V_121 -> V_128 ) ;
V_131 = F_82 ( V_121 -> V_128 . V_140 ,
T_12 , V_132 ) ;
}
if ( V_131 -> V_147 == 0 ) {
if ( V_145 -> V_148 == 0 ||
V_145 -> V_148 > V_149 ) {
F_3 ( log -> V_6 ,
L_24 ,
V_145 -> V_148 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
V_131 -> V_147 = V_145 -> V_148 ;
V_131 -> V_141 =
F_74 ( V_131 -> V_147 * sizeof( V_150 ) ,
V_126 ) ;
}
ASSERT ( V_131 -> V_147 > V_131 -> V_142 ) ;
V_131 -> V_141 [ V_131 -> V_142 ] . V_143 = V_135 ;
V_131 -> V_141 [ V_131 -> V_142 ] . V_144 = V_134 ;
V_131 -> V_142 ++ ;
F_87 ( log , V_121 , V_131 , 0 ) ;
return 0 ;
}
STATIC int
F_88 (
struct log * log ,
T_10 * V_121 ,
int V_151 )
{
T_12 * V_131 , * V_123 ;
F_89 ( V_152 ) ;
F_90 ( & V_121 -> V_128 , & V_152 ) ;
F_91 (item, n, &sort_list, ri_list) {
T_14 * V_153 = V_131 -> V_141 [ 0 ] . V_143 ;
switch ( F_92 ( V_131 ) ) {
case V_154 :
if ( ! ( V_153 -> V_155 & V_156 ) ) {
F_93 ( log ,
V_121 , V_131 , V_151 ) ;
F_94 ( & V_131 -> V_132 , & V_121 -> V_128 ) ;
break;
}
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
F_95 ( log ,
V_121 , V_131 , V_151 ) ;
F_96 ( & V_131 -> V_132 , & V_121 -> V_128 ) ;
break;
default:
F_3 ( log -> V_6 ,
L_25 ,
V_7 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
}
ASSERT ( F_81 ( & V_152 ) ) ;
return 0 ;
}
STATIC int
F_97 (
struct log * log ,
T_12 * V_131 )
{
T_14 * V_153 = V_131 -> V_141 [ 0 ] . V_143 ;
struct V_130 * V_162 ;
struct V_163 * V_164 ;
if ( ! ( V_153 -> V_155 & V_156 ) ) {
F_98 ( log , V_153 ) ;
return 0 ;
}
V_162 = F_99 ( log , V_153 -> V_165 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_164 -> V_166 == V_153 -> V_165 &&
V_164 -> V_167 == V_153 -> V_168 ) {
V_164 -> V_169 ++ ;
F_101 ( log , V_153 ) ;
return 0 ;
}
}
V_164 = F_86 ( sizeof( struct V_163 ) , V_126 ) ;
V_164 -> V_166 = V_153 -> V_165 ;
V_164 -> V_167 = V_153 -> V_168 ;
V_164 -> V_169 = 1 ;
F_79 ( & V_164 -> V_170 , V_162 ) ;
F_102 ( log , V_153 ) ;
return 0 ;
}
STATIC int
F_103 (
struct log * log ,
T_4 V_171 ,
T_7 V_134 ,
T_15 V_172 )
{
struct V_130 * V_162 ;
struct V_163 * V_164 ;
if ( log -> V_173 == NULL ) {
ASSERT ( ! ( V_172 & V_156 ) ) ;
return 0 ;
}
V_162 = F_99 ( log , V_171 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_164 -> V_166 == V_171 && V_164 -> V_167 == V_134 )
goto V_73;
}
ASSERT ( ! ( V_172 & V_156 ) ) ;
return 0 ;
V_73:
if ( V_172 & V_156 ) {
if ( -- V_164 -> V_169 == 0 ) {
F_104 ( & V_164 -> V_170 ) ;
F_105 ( V_164 ) ;
}
}
return 1 ;
}
STATIC int
F_106 (
struct V_174 * V_20 ,
T_12 * V_131 ,
struct V_4 * V_5 ,
T_14 * V_153 )
{
int V_43 ;
int V_175 = 0 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 = 0 ;
int V_180 ;
int V_181 ;
T_16 * V_182 ;
T_16 * V_183 ;
F_107 ( V_20 -> V_184 , V_153 ) ;
V_181 = F_108 ( V_5 ) >> V_20 -> V_22 . V_185 ;
for ( V_43 = 0 ; V_43 < V_181 ; V_43 ++ ) {
V_180 = ( V_43 * V_20 -> V_22 . V_186 ) +
F_109 ( V_187 , V_188 ) ;
while ( V_180 >=
( V_178 + V_179 ) ) {
V_176 += V_177 ;
V_176 = F_110 ( V_153 -> V_189 ,
V_153 -> V_190 , V_176 ) ;
if ( V_176 == - 1 )
return 0 ;
V_177 = F_111 ( V_153 -> V_189 ,
V_153 -> V_190 , V_176 ) ;
ASSERT ( V_177 > 0 ) ;
V_178 = V_176 << V_191 ;
V_179 = V_177 << V_191 ;
V_175 ++ ;
}
if ( V_180 < V_178 )
continue;
ASSERT ( V_131 -> V_141 [ V_175 ] . V_143 != NULL ) ;
ASSERT ( ( V_131 -> V_141 [ V_175 ] . V_144 % V_192 ) == 0 ) ;
ASSERT ( ( V_178 + V_179 ) <= F_108 ( V_5 ) ) ;
V_182 = V_131 -> V_141 [ V_175 ] . V_143 +
V_180 - V_178 ;
if ( F_35 ( * V_182 == 0 ) ) {
F_112 ( V_20 ,
L_26
L_27 ,
V_131 , V_5 ) ;
F_4 ( L_28 ,
V_118 , V_20 ) ;
return F_36 ( V_14 ) ;
}
V_183 = ( T_16 * ) F_113 ( V_5 ,
V_180 ) ;
* V_183 = * V_182 ;
}
return 0 ;
}
STATIC void
F_114 (
struct V_174 * V_20 ,
T_12 * V_131 ,
struct V_4 * V_5 ,
T_14 * V_153 )
{
int V_43 ;
int V_176 ;
int V_177 ;
int error ;
F_115 ( V_20 -> V_184 , V_153 ) ;
V_176 = 0 ;
V_43 = 1 ;
while ( 1 ) {
V_176 = F_110 ( V_153 -> V_189 ,
V_153 -> V_190 , V_176 ) ;
if ( V_176 == - 1 )
break;
V_177 = F_111 ( V_153 -> V_189 ,
V_153 -> V_190 , V_176 ) ;
ASSERT ( V_177 > 0 ) ;
ASSERT ( V_131 -> V_141 [ V_43 ] . V_143 != NULL ) ;
ASSERT ( V_131 -> V_141 [ V_43 ] . V_144 % V_192 == 0 ) ;
ASSERT ( F_108 ( V_5 ) >=
( ( T_7 ) V_176 << V_191 ) + ( V_177 << V_191 ) ) ;
error = 0 ;
if ( V_153 -> V_155 &
( V_193 | V_194 | V_195 ) ) {
if ( V_131 -> V_141 [ V_43 ] . V_143 == NULL ) {
F_112 ( V_20 ,
L_29 , V_7 ) ;
goto V_196;
}
if ( V_131 -> V_141 [ V_43 ] . V_144 < sizeof( V_197 ) ) {
F_112 ( V_20 ,
L_30 ,
V_131 -> V_141 [ V_43 ] . V_144 , V_7 ) ;
goto V_196;
}
error = F_116 ( V_20 , V_131 -> V_141 [ V_43 ] . V_143 ,
- 1 , 0 , V_198 ,
L_31 ) ;
if ( error )
goto V_196;
}
memcpy ( F_113 ( V_5 ,
( T_7 ) V_176 << V_191 ) ,
V_131 -> V_141 [ V_43 ] . V_143 ,
V_177 << V_191 ) ;
V_196:
V_43 ++ ;
V_176 += V_177 ;
}
ASSERT ( V_43 == V_131 -> V_147 ) ;
}
int
F_116 (
struct V_174 * V_20 ,
V_197 * V_199 ,
T_17 V_200 ,
T_7 type ,
T_7 V_172 ,
char * V_201 )
{
T_18 * V_202 = ( T_18 * ) V_199 ;
int V_203 = 0 ;
if ( V_199 -> V_204 != F_117 ( V_205 ) ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_32 ,
V_201 , V_200 , F_118 ( V_199 -> V_204 ) , V_205 ) ;
V_203 ++ ;
}
if ( V_199 -> V_206 != V_207 ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_33 ,
V_201 , V_200 , V_199 -> V_206 , V_207 ) ;
V_203 ++ ;
}
if ( V_199 -> V_208 != V_209 &&
V_199 -> V_208 != V_210 &&
V_199 -> V_208 != V_211 ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_34 ,
V_201 , V_200 , V_199 -> V_208 ) ;
V_203 ++ ;
}
if ( V_200 != - 1 && V_200 != F_32 ( V_199 -> V_212 ) ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_35
L_36 ,
V_201 , V_199 , V_200 , F_32 ( V_199 -> V_212 ) ) ;
V_203 ++ ;
}
if ( ! V_203 && V_199 -> V_212 ) {
if ( V_199 -> V_213 &&
F_58 ( V_199 -> V_214 ) >=
F_58 ( V_199 -> V_213 ) ) {
if ( ! V_199 -> V_215 ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_37 ,
V_201 , ( int ) F_32 ( V_199 -> V_212 ) , V_199 ) ;
V_203 ++ ;
}
}
if ( V_199 -> V_216 &&
F_58 ( V_199 -> V_217 ) >=
F_58 ( V_199 -> V_216 ) ) {
if ( ! V_199 -> V_218 ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_38 ,
V_201 , ( int ) F_32 ( V_199 -> V_212 ) , V_199 ) ;
V_203 ++ ;
}
}
if ( V_199 -> V_219 &&
F_58 ( V_199 -> V_220 ) >=
F_58 ( V_199 -> V_219 ) ) {
if ( ! V_199 -> V_221 ) {
if ( V_172 & V_198 )
F_112 ( V_20 ,
L_39 ,
V_201 , ( int ) F_32 ( V_199 -> V_212 ) , V_199 ) ;
V_203 ++ ;
}
}
}
if ( ! V_203 || ! ( V_172 & V_222 ) )
return V_203 ;
if ( V_172 & V_198 )
F_119 ( V_20 , L_40 , V_200 ) ;
ASSERT ( V_200 != - 1 ) ;
ASSERT ( V_172 & V_222 ) ;
memset ( V_202 , 0 , sizeof( T_18 ) ) ;
V_202 -> V_223 . V_204 = F_117 ( V_205 ) ;
V_202 -> V_223 . V_206 = V_207 ;
V_202 -> V_223 . V_208 = type ;
V_202 -> V_223 . V_212 = F_34 ( V_200 ) ;
return V_203 ;
}
STATIC void
F_120 (
T_5 * V_20 ,
T_1 * log ,
T_12 * V_131 ,
T_2 * V_5 ,
T_14 * V_153 )
{
T_7 type ;
F_121 ( log , V_153 ) ;
if ( V_20 -> V_224 == 0 ) {
return;
}
type = 0 ;
if ( V_153 -> V_155 & V_193 )
type |= V_209 ;
if ( V_153 -> V_155 & V_194 )
type |= V_210 ;
if ( V_153 -> V_155 & V_195 )
type |= V_211 ;
if ( log -> V_225 & type )
return;
F_114 ( V_20 , V_131 , V_5 , V_153 ) ;
}
STATIC int
F_122 (
T_1 * log ,
T_12 * V_131 )
{
T_14 * V_153 = V_131 -> V_141 [ 0 ] . V_143 ;
T_5 * V_20 = log -> V_6 ;
T_2 * V_5 ;
int error ;
T_7 V_226 ;
if ( F_103 ( log , V_153 -> V_165 ,
V_153 -> V_168 , V_153 -> V_155 ) ) {
F_123 ( log , V_153 ) ;
return 0 ;
}
F_124 ( log , V_153 ) ;
V_226 = V_227 ;
if ( ! ( V_153 -> V_155 & V_228 ) )
V_226 |= V_229 ;
V_5 = F_125 ( V_20 -> V_230 , V_153 -> V_165 , V_153 -> V_168 ,
V_226 ) ;
if ( ! V_5 )
return F_36 ( V_47 ) ;
error = V_5 -> V_29 ;
if ( error ) {
F_20 ( L_41 , V_20 ,
V_5 , V_153 -> V_165 ) ;
F_126 ( V_5 ) ;
return error ;
}
if ( V_153 -> V_155 & V_228 ) {
error = F_106 ( V_20 , V_131 , V_5 , V_153 ) ;
} else if ( V_153 -> V_155 &
( V_193 | V_194 | V_195 ) ) {
F_120 ( V_20 , log , V_131 , V_5 , V_153 ) ;
} else {
F_114 ( V_20 , V_131 , V_5 , V_153 ) ;
}
if ( error )
return F_36 ( error ) ;
if ( V_231 ==
F_118 ( * ( ( V_232 * ) F_113 ( V_5 , 0 ) ) ) &&
( F_108 ( V_5 ) != F_127 ( log -> V_6 -> V_22 . V_233 ,
( V_234 ) F_128 ( log -> V_6 ) ) ) ) {
F_129 ( V_5 ) ;
error = F_29 ( V_20 , V_5 ) ;
} else {
ASSERT ( V_5 -> V_30 -> V_31 == V_20 ) ;
V_5 -> V_33 = F_40 ;
F_130 ( V_20 , V_5 ) ;
}
return ( error ) ;
}
STATIC int
F_131 (
T_1 * log ,
T_12 * V_131 )
{
T_13 * V_145 ;
T_5 * V_20 = log -> V_6 ;
T_2 * V_5 ;
V_187 * V_235 ;
int V_134 ;
T_3 V_236 ;
T_3 V_237 ;
int error ;
int V_238 ;
T_7 V_239 ;
T_19 * V_240 ;
int V_241 = 0 ;
if ( V_131 -> V_141 [ 0 ] . V_144 == sizeof( T_13 ) ) {
V_145 = V_131 -> V_141 [ 0 ] . V_143 ;
} else {
V_145 = F_86 ( sizeof( T_13 ) , V_126 ) ;
V_241 = 1 ;
error = F_132 ( & V_131 -> V_141 [ 0 ] , V_145 ) ;
if ( error )
goto error;
}
if ( F_103 ( log , V_145 -> V_242 ,
V_145 -> V_243 , 0 ) ) {
error = 0 ;
F_133 ( log , V_145 ) ;
goto error;
}
F_134 ( log , V_145 ) ;
V_5 = F_125 ( V_20 -> V_230 , V_145 -> V_242 , V_145 -> V_243 ,
V_227 ) ;
if ( ! V_5 ) {
error = V_47 ;
goto error;
}
error = V_5 -> V_29 ;
if ( error ) {
F_20 ( L_42 , V_20 ,
V_5 , V_145 -> V_242 ) ;
F_126 ( V_5 ) ;
goto error;
}
ASSERT ( V_145 -> V_244 & V_245 ) ;
V_235 = ( V_187 * ) F_113 ( V_5 , V_145 -> V_246 ) ;
if ( F_35 ( V_235 -> V_247 != F_117 ( V_231 ) ) ) {
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_43 ,
V_7 , V_235 , V_5 , V_145 -> V_248 ) ;
F_4 ( L_44 ,
V_118 , V_20 ) ;
error = V_14 ;
goto error;
}
V_240 = V_131 -> V_141 [ 1 ] . V_143 ;
if ( F_35 ( V_240 -> V_247 != V_231 ) ) {
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_45 ,
V_7 , V_131 , V_145 -> V_248 ) ;
F_4 ( L_46 ,
V_118 , V_20 ) ;
error = V_14 ;
goto error;
}
if ( V_240 -> V_249 < F_118 ( V_235 -> V_249 ) ) {
if ( F_118 ( V_235 -> V_249 ) == V_250 &&
V_240 -> V_249 < ( V_250 >> 1 ) ) {
} else {
F_126 ( V_5 ) ;
F_135 ( log , V_145 ) ;
error = 0 ;
goto error;
}
}
V_240 -> V_249 = 0 ;
if ( F_35 ( F_136 ( V_240 -> V_251 ) ) ) {
if ( ( V_240 -> V_252 != V_253 ) &&
( V_240 -> V_252 != V_254 ) ) {
F_137 ( L_47 ,
V_118 , V_20 , V_240 ) ;
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_48
L_49 ,
V_7 , V_131 , V_235 , V_5 , V_145 -> V_248 ) ;
error = V_14 ;
goto error;
}
} else if ( F_35 ( F_138 ( V_240 -> V_251 ) ) ) {
if ( ( V_240 -> V_252 != V_253 ) &&
( V_240 -> V_252 != V_254 ) &&
( V_240 -> V_252 != V_255 ) ) {
F_137 ( L_50 ,
V_118 , V_20 , V_240 ) ;
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_51
L_49 ,
V_7 , V_131 , V_235 , V_5 , V_145 -> V_248 ) ;
error = V_14 ;
goto error;
}
}
if ( F_35 ( V_240 -> V_256 + V_240 -> V_257 > V_240 -> V_258 ) ) {
F_137 ( L_52 ,
V_118 , V_20 , V_240 ) ;
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_53
L_54 ,
V_7 , V_131 , V_235 , V_5 , V_145 -> V_248 ,
V_240 -> V_256 + V_240 -> V_257 ,
V_240 -> V_258 ) ;
error = V_14 ;
goto error;
}
if ( F_35 ( V_240 -> V_259 > V_20 -> V_22 . V_186 ) ) {
F_137 ( L_55 ,
V_118 , V_20 , V_240 ) ;
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_53
L_56 , V_7 ,
V_131 , V_235 , V_5 , V_145 -> V_248 , V_240 -> V_259 ) ;
error = V_14 ;
goto error;
}
if ( F_35 ( V_131 -> V_141 [ 1 ] . V_144 > sizeof( struct V_260 ) ) ) {
F_137 ( L_57 ,
V_118 , V_20 , V_240 ) ;
F_126 ( V_5 ) ;
F_112 ( V_20 ,
L_58 ,
V_7 , V_131 -> V_141 [ 1 ] . V_144 , V_131 ) ;
error = V_14 ;
goto error;
}
F_139 ( V_235 , V_131 -> V_141 [ 1 ] . V_143 ) ;
if ( V_131 -> V_141 [ 1 ] . V_144 > sizeof( struct V_260 ) ) {
memcpy ( ( T_3 ) V_235 + sizeof( struct V_260 ) ,
V_131 -> V_141 [ 1 ] . V_143 + sizeof( struct V_260 ) ,
V_131 -> V_141 [ 1 ] . V_144 - sizeof( struct V_260 ) ) ;
}
V_239 = V_145 -> V_244 ;
switch ( V_239 & ( V_261 | V_262 ) ) {
case V_261 :
F_140 ( V_235 , V_145 -> V_263 . V_264 ) ;
break;
case V_262 :
memcpy ( F_141 ( V_235 ) ,
& V_145 -> V_263 . V_265 ,
sizeof( V_104 ) ) ;
break;
}
if ( V_145 -> V_148 == 2 )
goto V_266;
V_134 = V_131 -> V_141 [ 2 ] . V_144 ;
V_236 = V_131 -> V_141 [ 2 ] . V_143 ;
ASSERT ( V_145 -> V_148 <= 4 ) ;
ASSERT ( ( V_145 -> V_148 == 3 ) || ( V_239 & V_267 ) ) ;
ASSERT ( ! ( V_239 & V_268 ) ||
( V_134 == V_145 -> V_269 ) ) ;
switch ( V_239 & V_268 ) {
case V_270 :
case V_271 :
memcpy ( F_141 ( V_235 ) , V_236 , V_134 ) ;
break;
case V_272 :
F_142 ( V_20 , (struct V_273 * ) V_236 , V_134 ,
( V_274 * ) F_141 ( V_235 ) ,
F_143 ( V_235 , V_20 ) ) ;
break;
default:
ASSERT ( ( V_239 & V_268 ) == 0 ) ;
break;
}
if ( V_145 -> V_244 & V_267 ) {
if ( V_145 -> V_244 & V_268 ) {
V_238 = 3 ;
} else {
V_238 = 2 ;
}
V_134 = V_131 -> V_141 [ V_238 ] . V_144 ;
V_236 = V_131 -> V_141 [ V_238 ] . V_143 ;
ASSERT ( V_134 == V_145 -> V_275 ) ;
switch ( V_145 -> V_244 & V_267 ) {
case V_276 :
case V_277 :
V_237 = F_144 ( V_235 ) ;
ASSERT ( V_134 <= F_145 ( V_235 , V_20 ) ) ;
memcpy ( V_237 , V_236 , V_134 ) ;
break;
case V_278 :
V_237 = F_144 ( V_235 ) ;
F_142 ( V_20 , (struct V_273 * ) V_236 ,
V_134 , ( V_274 * ) V_237 ,
F_145 ( V_235 , V_20 ) ) ;
break;
default:
F_3 ( log -> V_6 , L_59 , V_7 ) ;
ASSERT ( 0 ) ;
F_126 ( V_5 ) ;
error = V_56 ;
goto error;
}
}
V_266:
ASSERT ( V_5 -> V_30 -> V_31 == V_20 ) ;
V_5 -> V_33 = F_40 ;
F_130 ( V_20 , V_5 ) ;
error:
if ( V_241 )
F_105 ( V_145 ) ;
return F_36 ( error ) ;
}
STATIC int
F_146 (
T_1 * log ,
T_12 * V_131 )
{
T_20 * V_279 = V_131 -> V_141 [ 0 ] . V_143 ;
ASSERT ( V_279 ) ;
if ( V_279 -> V_280 & V_281 )
log -> V_225 |= V_209 ;
if ( V_279 -> V_280 & V_282 )
log -> V_225 |= V_210 ;
if ( V_279 -> V_280 & V_283 )
log -> V_225 |= V_211 ;
return ( 0 ) ;
}
STATIC int
F_147 (
T_1 * log ,
T_12 * V_131 )
{
T_5 * V_20 = log -> V_6 ;
T_2 * V_5 ;
struct V_284 * V_199 , * V_285 ;
int error ;
T_21 * V_286 ;
T_7 type ;
if ( V_20 -> V_224 == 0 )
return ( 0 ) ;
V_285 = V_131 -> V_141 [ 1 ] . V_143 ;
if ( V_285 == NULL ) {
F_112 ( log -> V_6 , L_60 , V_7 ) ;
return F_36 ( V_56 ) ;
}
if ( V_131 -> V_141 [ 1 ] . V_144 < sizeof( V_197 ) ) {
F_112 ( log -> V_6 , L_61 ,
V_131 -> V_141 [ 1 ] . V_144 , V_7 ) ;
return F_36 ( V_56 ) ;
}
type = V_285 -> V_208 & ( V_209 | V_210 | V_211 ) ;
ASSERT ( type ) ;
if ( log -> V_225 & type )
return ( 0 ) ;
V_286 = V_131 -> V_141 [ 0 ] . V_143 ;
ASSERT ( V_286 ) ;
error = F_116 ( V_20 , V_285 , V_286 -> V_287 , 0 , V_198 ,
L_62 ) ;
if ( error )
return F_36 ( V_56 ) ;
ASSERT ( V_286 -> V_288 == 1 ) ;
error = F_148 ( V_20 , V_20 -> V_230 ,
V_286 -> V_289 ,
F_149 ( V_20 , V_286 -> V_288 ) ,
0 , & V_5 ) ;
if ( error ) {
F_20 ( L_63 , V_20 ,
V_5 , V_286 -> V_289 ) ;
return error ;
}
ASSERT ( V_5 ) ;
V_199 = ( V_197 * ) F_113 ( V_5 , V_286 -> V_290 ) ;
error = F_116 ( V_20 , V_199 , V_286 -> V_287 , 0 , V_198 ,
L_64 ) ;
if ( error ) {
F_126 ( V_5 ) ;
return F_36 ( V_56 ) ;
}
memcpy ( V_199 , V_285 , V_131 -> V_141 [ 1 ] . V_144 ) ;
ASSERT ( V_286 -> V_291 == 2 ) ;
ASSERT ( V_5 -> V_30 -> V_31 == V_20 ) ;
V_5 -> V_33 = F_40 ;
F_130 ( V_20 , V_5 ) ;
return ( 0 ) ;
}
STATIC int
F_150 (
T_1 * log ,
T_12 * V_131 ,
T_9 V_125 )
{
int error ;
T_5 * V_20 = log -> V_6 ;
T_22 * V_292 ;
T_23 * V_293 ;
V_293 = V_131 -> V_141 [ 0 ] . V_143 ;
V_292 = F_151 ( V_20 , V_293 -> V_294 ) ;
if ( ( error = F_152 ( & ( V_131 -> V_141 [ 0 ] ) ,
& ( V_292 -> V_295 ) ) ) ) {
F_153 ( V_292 ) ;
return error ;
}
F_154 ( & V_292 -> V_296 , V_293 -> V_294 ) ;
F_155 ( & log -> V_297 -> V_298 ) ;
F_156 ( log -> V_297 , & V_292 -> V_299 , V_125 ) ;
return 0 ;
}
STATIC int
F_157 (
T_1 * log ,
T_12 * V_131 )
{
T_24 * V_300 ;
T_22 * V_292 = NULL ;
T_25 * V_301 ;
T_26 V_302 ;
struct V_303 V_304 ;
struct V_305 * V_306 = log -> V_297 ;
V_300 = V_131 -> V_141 [ 0 ] . V_143 ;
ASSERT ( ( V_131 -> V_141 [ 0 ] . V_144 == ( sizeof( V_307 ) +
( ( V_300 -> V_308 - 1 ) * sizeof( V_309 ) ) ) ) ||
( V_131 -> V_141 [ 0 ] . V_144 == ( sizeof( V_310 ) +
( ( V_300 -> V_308 - 1 ) * sizeof( V_311 ) ) ) ) ) ;
V_302 = V_300 -> V_312 ;
F_155 ( & V_306 -> V_298 ) ;
V_301 = F_158 ( V_306 , & V_304 , 0 ) ;
while ( V_301 != NULL ) {
if ( V_301 -> V_313 == V_161 ) {
V_292 = ( T_22 * ) V_301 ;
if ( V_292 -> V_295 . V_302 == V_302 ) {
F_159 ( V_306 , V_301 ) ;
F_153 ( V_292 ) ;
F_155 ( & V_306 -> V_298 ) ;
break;
}
}
V_301 = F_160 ( V_306 , & V_304 ) ;
}
F_161 ( V_306 , & V_304 ) ;
F_162 ( & V_306 -> V_298 ) ;
return 0 ;
}
STATIC void
F_163 (
struct V_314 * V_121 )
{
T_12 * V_131 , * V_123 ;
int V_43 ;
F_91 (item, n, &trans->r_itemq, ri_list) {
F_104 ( & V_131 -> V_132 ) ;
for ( V_43 = 0 ; V_43 < V_131 -> V_142 ; V_43 ++ )
F_105 ( V_131 -> V_141 [ V_43 ] . V_143 ) ;
F_105 ( V_131 -> V_141 ) ;
F_105 ( V_131 ) ;
}
F_105 ( V_121 ) ;
}
STATIC int
F_164 (
struct log * log ,
struct V_314 * V_121 ,
T_12 * V_131 )
{
F_165 ( log , V_121 , V_131 , V_315 ) ;
switch ( F_92 ( V_131 ) ) {
case V_154 :
return F_97 ( log , V_131 ) ;
case V_159 :
return F_146 ( log , V_131 ) ;
case V_157 :
case V_161 :
case V_160 :
case V_158 :
return 0 ;
default:
F_3 ( log -> V_6 , L_65 ,
V_7 , F_92 ( V_131 ) ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
}
STATIC int
F_166 (
struct log * log ,
struct V_314 * V_121 ,
T_12 * V_131 )
{
F_165 ( log , V_121 , V_131 , V_316 ) ;
switch ( F_92 ( V_131 ) ) {
case V_154 :
return F_122 ( log , V_131 ) ;
case V_157 :
return F_131 ( log , V_131 ) ;
case V_161 :
return F_150 ( log , V_131 , V_121 -> V_127 ) ;
case V_160 :
return F_157 ( log , V_131 ) ;
case V_158 :
return F_147 ( log , V_131 ) ;
case V_159 :
return 0 ;
default:
F_3 ( log -> V_6 , L_65 ,
V_7 , F_92 ( V_131 ) ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
}
STATIC int
F_167 (
struct log * log ,
struct V_314 * V_121 ,
int V_151 )
{
int error = 0 ;
T_12 * V_131 ;
F_168 ( & V_121 -> V_129 ) ;
error = F_88 ( log , V_121 , V_151 ) ;
if ( error )
return error ;
F_100 (item, &trans->r_itemq, ri_list) {
if ( V_151 == V_315 )
error = F_164 ( log , V_121 , V_131 ) ;
else
error = F_166 ( log , V_121 , V_131 ) ;
if ( error )
return error ;
}
F_163 ( V_121 ) ;
return 0 ;
}
STATIC int
F_169 (
struct log * log ,
T_10 * V_121 )
{
F_3 ( log -> V_6 , L_66 , V_7 ) ;
return 0 ;
}
STATIC int
F_170 (
T_1 * log ,
struct V_119 V_317 [] ,
T_6 * V_71 ,
T_3 V_133 ,
int V_151 )
{
T_3 V_318 ;
int V_319 ;
T_8 * V_320 ;
T_10 * V_121 ;
T_11 V_120 ;
int error ;
unsigned long V_321 ;
T_7 V_172 ;
V_318 = V_133 + F_32 ( V_71 -> V_59 ) ;
V_319 = F_32 ( V_71 -> V_92 ) ;
if ( F_33 ( log -> V_6 , V_71 ) )
return ( F_36 ( V_56 ) ) ;
while ( ( V_133 < V_318 ) && V_319 ) {
ASSERT ( V_133 + sizeof( T_8 ) <= V_318 ) ;
V_320 = ( T_8 * ) V_133 ;
V_133 += sizeof( T_8 ) ;
if ( V_320 -> V_322 != V_323 &&
V_320 -> V_322 != V_324 ) {
F_3 ( log -> V_6 , L_67 ,
V_7 , V_320 -> V_322 ) ;
ASSERT ( 0 ) ;
return ( F_36 ( V_56 ) ) ;
}
V_120 = F_32 ( V_320 -> V_325 ) ;
V_321 = F_171 ( V_120 ) ;
V_121 = F_71 ( & V_317 [ V_321 ] , V_120 ) ;
if ( V_121 == NULL ) {
if ( V_320 -> V_93 & V_326 )
F_73 ( & V_317 [ V_321 ] , V_120 ,
F_58 ( V_71 -> V_87 ) ) ;
} else {
if ( V_133 + F_32 ( V_320 -> V_327 ) > V_318 ) {
F_3 ( log -> V_6 , L_68 ,
V_7 , F_32 ( V_320 -> V_327 ) ) ;
F_172 ( 1 ) ;
return ( F_36 ( V_56 ) ) ;
}
V_172 = V_320 -> V_93 & ~ V_328 ;
if ( V_172 & V_329 )
V_172 &= ~ V_330 ;
switch ( V_172 ) {
case V_331 :
error = F_167 ( log ,
V_121 , V_151 ) ;
break;
case V_94 :
error = F_169 ( log , V_121 ) ;
break;
case V_329 :
error = F_80 ( log ,
V_121 , V_133 ,
F_32 ( V_320 -> V_327 ) ) ;
break;
case V_326 :
F_3 ( log -> V_6 , L_69 ,
V_7 ) ;
ASSERT ( 0 ) ;
error = F_36 ( V_56 ) ;
break;
case 0 :
case V_330 :
error = F_85 ( log , V_121 ,
V_133 , F_32 ( V_320 -> V_327 ) ) ;
break;
default:
F_3 ( log -> V_6 , L_70 ,
V_7 , V_172 ) ;
ASSERT ( 0 ) ;
error = F_36 ( V_56 ) ;
break;
}
if ( error )
return error ;
}
V_133 += F_32 ( V_320 -> V_327 ) ;
V_319 -- ;
}
return 0 ;
}
STATIC int
F_173 (
T_5 * V_20 ,
T_22 * V_292 )
{
T_27 * V_332 ;
T_28 * V_333 ;
int V_43 ;
int error = 0 ;
T_29 * V_334 ;
T_30 V_335 ;
ASSERT ( ! F_174 ( V_336 , & V_292 -> V_337 ) ) ;
for ( V_43 = 0 ; V_43 < V_292 -> V_295 . V_294 ; V_43 ++ ) {
V_334 = & ( V_292 -> V_295 . V_338 [ V_43 ] ) ;
V_335 = F_175 ( V_20 ,
F_176 ( V_20 , V_334 -> V_339 ) ) ;
if ( ( V_335 == 0 ) ||
( V_334 -> V_340 == 0 ) ||
( V_335 >= V_20 -> V_22 . V_341 ) ||
( V_334 -> V_340 >= V_20 -> V_22 . V_342 ) ) {
F_177 ( V_292 , V_292 -> V_295 . V_294 ) ;
return F_36 ( V_56 ) ;
}
}
V_333 = F_178 ( V_20 , 0 ) ;
error = F_179 ( V_333 , 0 , F_180 ( V_20 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_343;
V_332 = F_181 ( V_333 , V_292 , V_292 -> V_295 . V_294 ) ;
for ( V_43 = 0 ; V_43 < V_292 -> V_295 . V_294 ; V_43 ++ ) {
V_334 = & ( V_292 -> V_295 . V_338 [ V_43 ] ) ;
error = F_182 ( V_333 , V_334 -> V_339 , V_334 -> V_340 ) ;
if ( error )
goto V_343;
F_183 ( V_333 , V_332 , V_334 -> V_339 ,
V_334 -> V_340 ) ;
}
F_184 ( V_336 , & V_292 -> V_337 ) ;
error = F_185 ( V_333 , 0 ) ;
return error ;
V_343:
F_186 ( V_333 , V_344 ) ;
return error ;
}
STATIC int
F_187 (
T_1 * log )
{
T_25 * V_301 ;
T_22 * V_292 ;
int error = 0 ;
struct V_303 V_304 ;
struct V_305 * V_306 ;
V_306 = log -> V_297 ;
F_155 ( & V_306 -> V_298 ) ;
V_301 = F_158 ( V_306 , & V_304 , 0 ) ;
while ( V_301 != NULL ) {
if ( V_301 -> V_313 != V_161 ) {
#ifdef F_188
for (; V_301 ; V_301 = F_160 ( V_306 , & V_304 ) )
ASSERT ( V_301 -> V_313 != V_161 ) ;
#endif
break;
}
V_292 = ( T_22 * ) V_301 ;
if ( F_174 ( V_336 , & V_292 -> V_337 ) ) {
V_301 = F_160 ( V_306 , & V_304 ) ;
continue;
}
F_162 ( & V_306 -> V_298 ) ;
error = F_173 ( log -> V_6 , V_292 ) ;
F_155 ( & V_306 -> V_298 ) ;
if ( error )
goto V_49;
V_301 = F_160 ( V_306 , & V_304 ) ;
}
V_49:
F_161 ( V_306 , & V_304 ) ;
F_162 ( & V_306 -> V_298 ) ;
return error ;
}
STATIC void
F_189 (
T_5 * V_20 ,
T_31 V_345 ,
int V_162 )
{
T_28 * V_333 ;
T_32 * V_346 ;
T_2 * V_347 ;
int V_12 ;
int error ;
V_333 = F_178 ( V_20 , V_348 ) ;
error = F_179 ( V_333 , 0 , F_190 ( V_20 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_349;
error = F_191 ( V_20 , V_333 , V_345 , & V_347 ) ;
if ( error )
goto V_349;
V_346 = F_192 ( V_347 ) ;
V_346 -> V_350 [ V_162 ] = F_34 ( V_351 ) ;
V_12 = F_109 ( T_32 , V_350 ) +
( sizeof( T_16 ) * V_162 ) ;
F_193 ( V_333 , V_347 , V_12 ,
( V_12 + sizeof( T_16 ) - 1 ) ) ;
error = F_185 ( V_333 , 0 ) ;
if ( error )
goto V_352;
return;
V_349:
F_186 ( V_333 , V_344 ) ;
V_352:
F_3 ( V_20 , L_71 , V_7 , V_345 ) ;
return;
}
STATIC T_16
F_194 (
struct V_174 * V_20 ,
T_31 V_345 ,
T_16 V_353 ,
int V_162 )
{
struct V_4 * V_354 ;
struct V_355 * V_235 ;
struct V_356 * V_357 ;
T_33 V_358 ;
int error ;
V_358 = F_195 ( V_20 , V_345 , V_353 ) ;
error = F_196 ( V_20 , NULL , V_358 , 0 , 0 , & V_357 ) ;
if ( error )
goto V_359;
error = F_197 ( V_20 , NULL , V_357 , & V_235 , & V_354 , V_227 ) ;
if ( error )
goto V_360;
ASSERT ( V_357 -> V_361 . V_362 == 0 ) ;
ASSERT ( V_357 -> V_361 . V_251 != 0 ) ;
V_353 = F_32 ( V_235 -> V_188 ) ;
F_126 ( V_354 ) ;
V_357 -> V_361 . V_363 = 0 ;
F_198 ( V_357 ) ;
return V_353 ;
V_360:
F_198 ( V_357 ) ;
V_359:
F_189 ( V_20 , V_345 , V_162 ) ;
return V_351 ;
}
STATIC void
F_199 (
T_1 * log )
{
T_5 * V_20 ;
T_31 V_345 ;
T_32 * V_346 ;
T_2 * V_347 ;
T_16 V_353 ;
int V_162 ;
int error ;
T_7 V_364 ;
V_20 = log -> V_6 ;
V_364 = V_20 -> V_365 ;
V_20 -> V_365 = 0 ;
for ( V_345 = 0 ; V_345 < V_20 -> V_22 . V_366 ; V_345 ++ ) {
error = F_191 ( V_20 , NULL , V_345 , & V_347 ) ;
if ( error ) {
continue;
}
V_346 = F_192 ( V_347 ) ;
for ( V_162 = 0 ; V_162 < V_367 ; V_162 ++ ) {
V_353 = F_32 ( V_346 -> V_350 [ V_162 ] ) ;
while ( V_353 != V_351 ) {
F_126 ( V_347 ) ;
V_353 = F_194 ( V_20 ,
V_345 , V_353 , V_162 ) ;
error = F_191 ( V_20 , NULL , V_345 , & V_347 ) ;
ASSERT ( error == 0 ) ;
V_346 = F_192 ( V_347 ) ;
}
}
F_126 ( V_347 ) ;
}
V_20 -> V_365 = V_364 ;
}
STATIC void
F_200 (
T_1 * log ,
T_34 * V_368 ,
int V_369 )
{
int V_43 ;
V_79 * V_370 ;
T_7 V_371 = 0 ;
V_370 = ( V_79 * ) V_368 -> V_372 ;
for ( V_43 = 0 ; V_43 < ( V_369 >> 2 ) ; V_43 ++ ) {
V_371 ^= F_32 ( * V_370 ) ;
V_370 ++ ;
}
V_368 -> V_373 . V_374 = F_34 ( V_371 ) ;
}
void
F_201 (
T_1 * log ,
T_34 * V_368 ,
int V_375 )
{
int V_43 , V_44 , V_376 ;
int V_369 = V_368 -> V_377 + V_375 ;
V_79 V_378 ;
T_3 V_133 ;
F_200 ( log , V_368 , V_369 ) ;
V_378 = F_202 ( V_368 -> V_373 . V_87 ) ;
V_133 = V_368 -> V_372 ;
for ( V_43 = 0 ; V_43 < F_51 ( V_369 ) &&
V_43 < ( V_58 / V_50 ) ; V_43 ++ ) {
V_368 -> V_373 . V_379 [ V_43 ] = * ( V_79 * ) V_133 ;
* ( V_79 * ) V_133 = V_378 ;
V_133 += V_50 ;
}
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
T_35 * V_380 = V_368 -> V_381 ;
for ( ; V_43 < F_51 ( V_369 ) ; V_43 ++ ) {
V_44 = V_43 / ( V_58 / V_50 ) ;
V_376 = V_43 % ( V_58 / V_50 ) ;
V_380 [ V_44 ] . V_382 . V_383 [ V_376 ] = * ( V_79 * ) V_133 ;
* ( V_79 * ) V_133 = V_378 ;
V_133 += V_50 ;
}
for ( V_43 = 1 ; V_43 < log -> V_384 ; V_43 ++ ) {
V_380 [ V_43 ] . V_382 . V_385 = V_378 ;
}
}
}
STATIC void
F_203 (
T_6 * V_71 ,
T_3 V_133 ,
T_1 * log )
{
int V_43 , V_44 , V_376 ;
for ( V_43 = 0 ; V_43 < F_51 ( F_32 ( V_71 -> V_59 ) ) &&
V_43 < ( V_58 / V_50 ) ; V_43 ++ ) {
* ( V_79 * ) V_133 = * ( V_79 * ) & V_71 -> V_379 [ V_43 ] ;
V_133 += V_50 ;
}
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
T_35 * V_380 = ( T_35 * ) V_71 ;
for ( ; V_43 < F_51 ( F_32 ( V_71 -> V_59 ) ) ; V_43 ++ ) {
V_44 = V_43 / ( V_58 / V_50 ) ;
V_376 = V_43 % ( V_58 / V_50 ) ;
* ( V_79 * ) V_133 = V_380 [ V_44 ] . V_382 . V_383 [ V_376 ] ;
V_133 += V_50 ;
}
}
}
STATIC int
F_204 (
T_1 * log ,
T_6 * V_71 ,
T_4 V_171 )
{
int V_386 ;
if ( F_35 ( V_71 -> V_27 != F_34 ( V_28 ) ) ) {
F_4 ( L_72 ,
V_118 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
if ( F_35 (
( ! V_71 -> V_90 ||
( F_32 ( V_71 -> V_90 ) & ( ~ V_387 ) ) ) ) ) {
F_3 ( log -> V_6 , L_73 ,
V_7 , F_32 ( V_71 -> V_90 ) ) ;
return F_36 ( V_56 ) ;
}
V_386 = F_32 ( V_71 -> V_59 ) ;
if ( F_35 ( V_386 <= 0 || V_386 > V_68 ) ) {
F_4 ( L_74 ,
V_118 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
if ( F_35 ( V_171 > log -> V_2 || V_171 > V_68 ) ) {
F_4 ( L_75 ,
V_118 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
return 0 ;
}
STATIC int
F_205 (
T_1 * log ,
T_4 V_61 ,
T_4 V_70 ,
int V_151 )
{
T_6 * V_71 ;
T_4 V_11 ;
T_3 V_12 ;
T_2 * V_388 , * V_389 ;
int error = 0 , V_57 ;
int V_390 , V_391 ;
int V_77 , V_392 , V_393 ;
struct V_119 V_317 [ V_394 ] ;
ASSERT ( V_61 != V_70 ) ;
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
V_388 = F_2 ( log , 1 ) ;
if ( ! V_388 )
return V_47 ;
error = F_22 ( log , V_70 , 1 , V_388 , & V_12 ) ;
if ( error )
goto V_395;
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 , V_70 ) ;
if ( error )
goto V_395;
V_57 = F_32 ( V_71 -> V_57 ) ;
if ( ( F_32 ( V_71 -> V_90 ) & V_91 ) &&
( V_57 > V_58 ) ) {
V_77 = V_57 / V_58 ;
if ( V_57 % V_58 )
V_77 ++ ;
F_9 ( V_388 ) ;
V_388 = F_2 ( log , V_77 ) ;
} else {
V_77 = 1 ;
}
} else {
ASSERT ( log -> V_9 == 1 ) ;
V_77 = 1 ;
V_388 = F_2 ( log , 1 ) ;
V_57 = V_396 ;
}
if ( ! V_388 )
return V_47 ;
V_389 = F_2 ( log , F_51 ( V_57 ) ) ;
if ( ! V_389 ) {
F_9 ( V_388 ) ;
return V_47 ;
}
memset ( V_317 , 0 , sizeof( V_317 ) ) ;
if ( V_70 <= V_61 ) {
for ( V_11 = V_70 ; V_11 < V_61 ; ) {
error = F_22 ( log , V_11 , V_77 , V_388 , & V_12 ) ;
if ( error )
goto V_397;
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 , V_11 ) ;
if ( error )
goto V_397;
V_390 = ( int ) F_51 ( F_32 ( V_71 -> V_59 ) ) ;
error = F_22 ( log , V_11 + V_77 , V_390 , V_389 ,
& V_12 ) ;
if ( error )
goto V_397;
F_203 ( V_71 , V_12 , log ) ;
if ( ( error = F_170 ( log ,
V_317 , V_71 , V_12 , V_151 ) ) )
goto V_397;
V_11 += V_390 + V_77 ;
}
} else {
V_11 = V_70 ;
while ( V_11 < log -> V_2 ) {
V_12 = V_388 -> V_13 ;
V_392 = 0 ;
V_393 = 0 ;
if ( V_11 + V_77 <= log -> V_2 ) {
error = F_22 ( log , V_11 , V_77 , V_388 ,
& V_12 ) ;
if ( error )
goto V_397;
} else {
if ( V_11 != log -> V_2 ) {
ASSERT ( V_11 <= V_68 ) ;
V_392 = log -> V_2 - ( int ) V_11 ;
ASSERT ( V_392 > 0 ) ;
error = F_22 ( log , V_11 ,
V_392 , V_388 ,
& V_12 ) ;
if ( error )
goto V_397;
}
V_393 = V_77 - V_392 ;
error = F_23 ( log , 0 ,
V_393 , V_388 ,
V_12 + F_7 ( V_392 ) ) ;
if ( error )
goto V_397;
}
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 ,
V_392 ? V_11 : 0 ) ;
if ( error )
goto V_397;
V_390 = ( int ) F_51 ( F_32 ( V_71 -> V_59 ) ) ;
V_11 += V_77 ;
if ( V_11 + V_390 <= log -> V_2 ) {
error = F_22 ( log , V_11 , V_390 , V_389 ,
& V_12 ) ;
if ( error )
goto V_397;
} else {
V_12 = V_389 -> V_13 ;
V_391 = 0 ;
if ( V_11 != log -> V_2 ) {
ASSERT ( ! V_393 ) ;
ASSERT ( V_11 <= V_68 ) ;
V_391 =
log -> V_2 - ( int ) V_11 ;
ASSERT ( V_391 > 0 ) ;
error = F_22 ( log , V_11 ,
V_391 , V_389 ,
& V_12 ) ;
if ( error )
goto V_397;
}
error = F_23 ( log , 0 ,
V_390 - V_391 , V_388 ,
V_12 + F_7 ( V_391 ) ) ;
if ( error )
goto V_397;
}
F_203 ( V_71 , V_12 , log ) ;
if ( ( error = F_170 ( log , V_317 ,
V_71 , V_12 , V_151 ) ) )
goto V_397;
V_11 += V_390 ;
}
ASSERT ( V_11 >= log -> V_2 ) ;
V_11 -= log -> V_2 ;
while ( V_11 < V_61 ) {
error = F_22 ( log , V_11 , V_77 , V_388 , & V_12 ) ;
if ( error )
goto V_397;
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 , V_11 ) ;
if ( error )
goto V_397;
V_390 = ( int ) F_51 ( F_32 ( V_71 -> V_59 ) ) ;
error = F_22 ( log , V_11 + V_77 , V_390 , V_389 ,
& V_12 ) ;
if ( error )
goto V_397;
F_203 ( V_71 , V_12 , log ) ;
if ( ( error = F_170 ( log , V_317 ,
V_71 , V_12 , V_151 ) ) )
goto V_397;
V_11 += V_390 + V_77 ;
}
}
V_397:
F_9 ( V_389 ) ;
V_395:
F_9 ( V_388 ) ;
return error ;
}
STATIC int
F_206 (
T_1 * log ,
T_4 V_61 ,
T_4 V_70 )
{
int error , V_43 ;
ASSERT ( V_61 != V_70 ) ;
log -> V_173 = F_74 ( V_398 *
sizeof( struct V_130 ) ,
V_126 ) ;
for ( V_43 = 0 ; V_43 < V_398 ; V_43 ++ )
F_75 ( & log -> V_173 [ V_43 ] ) ;
error = F_205 ( log , V_61 , V_70 ,
V_315 ) ;
if ( error != 0 ) {
F_105 ( log -> V_173 ) ;
log -> V_173 = NULL ;
return error ;
}
error = F_205 ( log , V_61 , V_70 ,
V_316 ) ;
#ifdef F_188
if ( ! error ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_398 ; V_43 ++ )
ASSERT ( F_81 ( & log -> V_173 [ V_43 ] ) ) ;
}
#endif
F_105 ( log -> V_173 ) ;
log -> V_173 = NULL ;
return error ;
}
STATIC int
F_207 (
T_1 * log ,
T_4 V_61 ,
T_4 V_70 )
{
int error ;
T_2 * V_5 ;
T_36 * V_399 ;
error = F_206 ( log , V_61 , V_70 ) ;
if ( error ) {
return error ;
}
F_208 ( log -> V_6 -> V_230 ) ;
if ( F_209 ( log -> V_6 ) ) {
return ( V_56 ) ;
}
F_210 ( log -> V_6 ) ;
V_5 = F_211 ( log -> V_6 , 0 ) ;
F_212 ( V_5 ) ;
ASSERT ( ! ( F_213 ( V_5 ) ) ) ;
ASSERT ( ! ( F_214 ( V_5 ) ) ) ;
F_16 ( V_5 ) ;
F_215 ( V_5 ) ;
F_18 ( log -> V_6 , V_5 ) ;
error = F_19 ( V_5 ) ;
if ( error ) {
F_20 ( L_76 ,
log -> V_6 , V_5 , F_21 ( V_5 ) ) ;
ASSERT ( 0 ) ;
F_126 ( V_5 ) ;
return error ;
}
V_399 = & log -> V_6 -> V_22 ;
F_216 ( V_399 , F_217 ( V_5 ) ) ;
ASSERT ( V_399 -> V_400 == V_401 ) ;
ASSERT ( F_218 ( V_399 ) ) ;
F_126 ( V_5 ) ;
F_219 ( log -> V_6 ) ;
F_220 ( log ) ;
log -> V_402 &= ~ V_403 ;
return 0 ;
}
int
V_314 (
T_1 * log )
{
T_4 V_61 , V_70 ;
int error ;
if ( ( error = F_56 ( log , & V_61 , & V_70 ) ) )
return error ;
if ( V_70 != V_61 ) {
if ( ( error = F_221 ( log -> V_6 , L_77 ) ) ) {
return error ;
}
F_119 ( log -> V_6 , L_78 ,
log -> V_6 -> V_404 ? log -> V_6 -> V_404
: L_79 ) ;
error = F_207 ( log , V_61 , V_70 ) ;
log -> V_402 |= V_405 ;
}
return error ;
}
int
F_222 (
T_1 * log )
{
if ( log -> V_402 & V_405 ) {
int error ;
error = F_187 ( log ) ;
if ( error ) {
F_112 ( log -> V_6 , L_80 ) ;
return error ;
}
F_223 ( log -> V_6 , V_406 ) ;
F_199 ( log ) ;
F_220 ( log ) ;
F_119 ( log -> V_6 , L_81 ,
log -> V_6 -> V_404 ? log -> V_6 -> V_404
: L_79 ) ;
log -> V_402 &= ~ V_405 ;
} else {
F_224 ( log -> V_6 , L_82 ) ;
}
return 0 ;
}
void
F_220 (
T_1 * log )
{
T_5 * V_20 ;
T_37 * V_407 ;
T_2 * V_408 ;
T_2 * V_347 ;
T_31 V_345 ;
T_26 V_409 ;
T_26 V_410 ;
T_26 V_411 ;
int error ;
V_20 = log -> V_6 ;
V_409 = 0LL ;
V_410 = 0LL ;
V_411 = 0LL ;
for ( V_345 = 0 ; V_345 < V_20 -> V_22 . V_366 ; V_345 ++ ) {
error = F_225 ( V_20 , NULL , V_345 , 0 , & V_408 ) ;
if ( error ) {
F_112 ( V_20 , L_83 ,
V_7 , V_345 , error ) ;
} else {
V_407 = F_226 ( V_408 ) ;
V_409 += F_32 ( V_407 -> V_412 ) +
F_32 ( V_407 -> V_413 ) ;
F_126 ( V_408 ) ;
}
error = F_191 ( V_20 , NULL , V_345 , & V_347 ) ;
if ( error ) {
F_112 ( V_20 , L_84 ,
V_7 , V_345 , error ) ;
} else {
struct V_414 * V_346 = F_192 ( V_347 ) ;
V_410 += F_32 ( V_346 -> V_415 ) ;
V_411 += F_32 ( V_346 -> V_416 ) ;
F_126 ( V_347 ) ;
}
}
}
