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
if ( ! F_1 ( log , V_3 ) ) {
F_3 ( log -> V_4 , L_1 ,
V_3 ) ;
F_4 ( V_5 , V_6 , log -> V_4 ) ;
return NULL ;
}
if ( V_3 > 1 && log -> V_7 > 1 )
V_3 += log -> V_7 ;
V_3 = F_5 ( V_3 , log -> V_7 ) ;
return F_6 ( log -> V_4 -> V_8 ,
F_7 ( V_3 ) , 0 ) ;
}
STATIC void
F_8 (
T_2 * V_9 )
{
F_9 ( V_9 ) ;
}
STATIC T_3
F_10 (
T_1 * log ,
T_4 V_10 ,
int V_3 ,
T_2 * V_9 )
{
T_4 V_11 = V_10 & ( ( T_4 ) log -> V_7 - 1 ) ;
ASSERT ( F_7 ( V_11 + V_3 ) <= F_11 ( V_9 ) ) ;
return F_12 ( V_9 ) + F_7 ( V_11 ) ;
}
STATIC int
F_13 (
T_1 * log ,
T_4 V_10 ,
int V_3 ,
T_2 * V_9 )
{
int error ;
if ( ! F_1 ( log , V_3 ) ) {
F_3 ( log -> V_4 , L_1 ,
V_3 ) ;
F_4 ( V_5 , V_6 , log -> V_4 ) ;
return V_12 ;
}
V_10 = F_14 ( V_10 , log -> V_7 ) ;
V_3 = F_5 ( V_3 , log -> V_7 ) ;
ASSERT ( V_3 > 0 ) ;
ASSERT ( F_7 ( V_3 ) <= F_11 ( V_9 ) ) ;
F_15 ( V_9 , log -> V_13 + V_10 ) ;
F_16 ( V_9 ) ;
F_17 ( V_9 ) ;
F_18 ( V_9 , F_7 ( V_3 ) ) ;
F_19 ( V_9 , log -> V_4 -> V_8 ) ;
F_20 ( log -> V_4 , V_9 ) ;
error = F_21 ( V_9 ) ;
if ( error )
F_22 ( L_2 , log -> V_4 ,
V_9 , F_23 ( V_9 ) ) ;
return error ;
}
STATIC int
F_24 (
T_1 * log ,
T_4 V_10 ,
int V_3 ,
T_2 * V_9 ,
T_3 * V_11 )
{
int error ;
error = F_13 ( log , V_10 , V_3 , V_9 ) ;
if ( error )
return error ;
* V_11 = F_10 ( log , V_10 , V_3 , V_9 ) ;
return 0 ;
}
STATIC int
F_25 (
T_1 * log ,
T_4 V_10 ,
int V_3 ,
T_2 * V_9 ,
T_3 V_11 )
{
T_3 V_14 = F_12 ( V_9 ) ;
int V_15 = V_9 -> V_16 ;
int error , V_17 ;
error = F_26 ( V_9 , V_11 , F_7 ( V_3 ) ) ;
if ( error )
return error ;
error = F_13 ( log , V_10 , V_3 , V_9 ) ;
V_17 = F_26 ( V_9 , V_14 , V_15 ) ;
if ( error )
return error ;
return V_17 ;
}
STATIC int
F_27 (
T_1 * log ,
T_4 V_10 ,
int V_3 ,
T_2 * V_9 )
{
int error ;
if ( ! F_1 ( log , V_3 ) ) {
F_3 ( log -> V_4 , L_1 ,
V_3 ) ;
F_4 ( V_5 , V_6 , log -> V_4 ) ;
return V_12 ;
}
V_10 = F_14 ( V_10 , log -> V_7 ) ;
V_3 = F_5 ( V_3 , log -> V_7 ) ;
ASSERT ( V_3 > 0 ) ;
ASSERT ( F_7 ( V_3 ) <= F_11 ( V_9 ) ) ;
F_15 ( V_9 , log -> V_13 + V_10 ) ;
F_28 ( V_9 ) ;
F_17 ( V_9 ) ;
F_29 ( V_9 ) ;
F_30 ( V_9 , V_18 ) ;
F_18 ( V_9 , F_7 ( V_3 ) ) ;
F_19 ( V_9 , log -> V_4 -> V_8 ) ;
if ( ( error = F_31 ( log -> V_4 , V_9 ) ) )
F_22 ( L_3 , log -> V_4 ,
V_9 , F_23 ( V_9 ) ) ;
return error ;
}
STATIC void
F_32 (
T_5 * V_19 ,
T_6 * V_20 )
{
F_33 ( V_19 , L_4 ,
V_5 , & V_19 -> V_21 . V_22 , V_23 ) ;
F_33 ( V_19 , L_5 ,
& V_20 -> V_24 , F_34 ( V_20 -> V_25 ) ) ;
}
STATIC int
F_35 (
T_5 * V_19 ,
T_6 * V_20 )
{
ASSERT ( F_34 ( V_20 -> V_26 ) == V_27 ) ;
if ( F_36 ( F_34 ( V_20 -> V_25 ) != V_23 ) ) {
F_3 ( V_19 ,
L_6 ) ;
F_32 ( V_19 , V_20 ) ;
F_4 ( L_7 ,
V_6 , V_19 ) ;
return F_37 ( V_12 ) ;
} else if ( F_36 ( ! F_38 ( & V_19 -> V_21 . V_22 , & V_20 -> V_24 ) ) ) {
F_3 ( V_19 ,
L_8 ) ;
F_32 ( V_19 , V_20 ) ;
F_4 ( L_9 ,
V_6 , V_19 ) ;
return F_37 ( V_12 ) ;
}
return 0 ;
}
STATIC int
F_39 (
T_5 * V_19 ,
T_6 * V_20 )
{
ASSERT ( F_34 ( V_20 -> V_26 ) == V_27 ) ;
if ( F_40 ( & V_20 -> V_24 ) ) {
F_3 ( V_19 , L_10 ) ;
} else if ( F_36 ( ! F_38 ( & V_19 -> V_21 . V_22 , & V_20 -> V_24 ) ) ) {
F_3 ( V_19 , L_11 ) ;
F_32 ( V_19 , V_20 ) ;
F_4 ( L_12 ,
V_6 , V_19 ) ;
return F_37 ( V_12 ) ;
}
return 0 ;
}
STATIC void
F_41 (
struct V_28 * V_9 )
{
if ( F_42 ( V_9 ) ) {
F_22 ( L_13 ,
V_9 -> V_29 -> V_30 , V_9 ,
F_23 ( V_9 ) ) ;
F_43 ( V_9 -> V_29 -> V_30 ,
V_31 ) ;
}
F_44 ( V_9 ) ;
F_45 ( V_9 , 0 ) ;
}
STATIC int
F_46 (
T_1 * log ,
T_2 * V_9 ,
T_4 V_32 ,
T_4 * V_33 ,
T_7 V_34 )
{
T_3 V_11 ;
T_4 V_35 ;
T_4 V_36 ;
T_7 V_37 ;
int error ;
V_36 = * V_33 ;
V_35 = F_47 ( V_32 , V_36 ) ;
while ( V_35 != V_32 && V_35 != V_36 ) {
error = F_24 ( log , V_35 , 1 , V_9 , & V_11 ) ;
if ( error )
return error ;
V_37 = F_48 ( V_11 ) ;
if ( V_37 == V_34 )
V_36 = V_35 ;
else
V_32 = V_35 ;
V_35 = F_47 ( V_32 , V_36 ) ;
}
ASSERT ( ( V_35 == V_32 && V_35 + 1 == V_36 ) ||
( V_35 == V_36 && V_35 - 1 == V_32 ) ) ;
* V_33 = V_36 ;
return 0 ;
}
STATIC int
F_49 (
T_1 * log ,
T_4 V_38 ,
int V_3 ,
T_7 V_39 ,
T_4 * V_40 )
{
T_4 V_41 , V_42 ;
T_7 V_34 ;
T_2 * V_9 ;
T_4 V_43 ;
T_3 V_44 = NULL ;
int error = 0 ;
V_43 = 1 << F_50 ( V_3 ) ;
while ( ! ( V_9 = F_2 ( log , V_43 ) ) ) {
V_43 >>= 1 ;
if ( V_43 < log -> V_7 )
return V_45 ;
}
for ( V_41 = V_38 ; V_41 < V_38 + V_3 ; V_41 += V_43 ) {
int V_46 ;
V_46 = F_51 ( V_43 , ( V_38 + V_3 - V_41 ) ) ;
error = F_24 ( log , V_41 , V_46 , V_9 , & V_44 ) ;
if ( error )
goto V_47;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_34 = F_48 ( V_44 ) ;
if ( V_34 == V_39 ) {
* V_40 = V_41 + V_42 ;
goto V_47;
}
V_44 += V_48 ;
}
}
* V_40 = - 1 ;
V_47:
F_8 ( V_9 ) ;
return error ;
}
STATIC int
F_52 (
T_1 * log ,
T_4 V_38 ,
T_4 * V_33 ,
int V_49 )
{
T_4 V_41 ;
T_2 * V_9 ;
T_3 V_11 = NULL ;
T_6 * V_20 = NULL ;
int error = 0 ;
int V_50 = 0 ;
int V_51 = * V_33 - V_38 ;
int V_52 ;
ASSERT ( V_38 != 0 || * V_33 != V_38 ) ;
if ( ! ( V_9 = F_2 ( log , V_51 ) ) ) {
if ( ! ( V_9 = F_2 ( log , 1 ) ) )
return V_45 ;
V_50 = 1 ;
} else {
error = F_24 ( log , V_38 , V_51 , V_9 , & V_11 ) ;
if ( error )
goto V_47;
V_11 += ( ( V_51 - 1 ) << V_53 ) ;
}
for ( V_41 = ( * V_33 ) - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( V_41 < V_38 ) {
F_3 ( log -> V_4 ,
L_14 ) ;
ASSERT ( 0 ) ;
error = F_37 ( V_54 ) ;
goto V_47;
}
if ( V_50 ) {
error = F_24 ( log , V_41 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_47;
}
V_20 = ( T_6 * ) V_11 ;
if ( V_27 == F_34 ( V_20 -> V_26 ) )
break;
if ( ! V_50 )
V_11 -= V_48 ;
}
if ( V_41 == - 1 ) {
error = - 1 ;
goto V_47;
}
if ( ( error = F_39 ( log -> V_4 , V_20 ) ) )
goto V_47;
if ( F_53 ( & log -> V_4 -> V_21 ) ) {
T_7 V_55 = F_34 ( V_20 -> V_55 ) ;
V_52 = V_55 / V_56 ;
if ( V_55 % V_56 )
V_52 ++ ;
} else {
V_52 = 1 ;
}
if ( * V_33 - V_41 + V_49 !=
F_54 ( F_34 ( V_20 -> V_57 ) ) + V_52 )
* V_33 = V_41 ;
V_47:
F_8 ( V_9 ) ;
return error ;
}
STATIC int
F_55 (
T_1 * log ,
T_4 * V_58 )
{
T_2 * V_9 ;
T_3 V_11 ;
T_4 V_40 , V_32 , V_38 , V_33 , V_59 ;
int V_60 ;
T_7 V_61 , V_62 ;
T_7 V_63 ;
int error , V_64 = log -> V_2 ;
if ( ( error = F_56 ( log , & V_32 ) ) == - 1 ) {
* V_58 = V_32 ;
if ( ! V_32 ) {
F_3 ( log -> V_4 , L_15 ) ;
}
return 0 ;
} else if ( error ) {
F_3 ( log -> V_4 , L_16 ) ;
return error ;
}
V_32 = 0 ;
V_9 = F_2 ( log , 1 ) ;
if ( ! V_9 )
return V_45 ;
error = F_24 ( log , 0 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_65;
V_61 = F_48 ( V_11 ) ;
V_33 = V_59 = V_64 - 1 ;
error = F_24 ( log , V_33 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_65;
V_62 = F_48 ( V_11 ) ;
ASSERT ( V_62 != 0 ) ;
if ( V_61 == V_62 ) {
V_59 = V_64 ;
V_63 = V_62 - 1 ;
} else {
V_63 = V_62 ;
if ( ( error = F_46 ( log , V_9 , V_32 ,
& V_59 , V_62 ) ) )
goto V_65;
}
V_60 = F_57 ( log ) ;
if ( V_59 >= V_60 ) {
V_38 = V_59 - V_60 ;
if ( ( error = F_49 ( log ,
V_38 , V_60 ,
V_63 , & V_40 ) ) )
goto V_65;
if ( V_40 != - 1 )
V_59 = V_40 ;
} else {
ASSERT ( V_59 <= V_66 &&
( T_4 ) V_60 >= V_59 ) ;
V_38 = V_64 - ( V_60 - V_59 ) ;
if ( ( error = F_49 ( log , V_38 ,
V_60 - ( int ) V_59 ,
( V_63 - 1 ) , & V_40 ) ) )
goto V_65;
if ( V_40 != - 1 ) {
V_59 = V_40 ;
goto V_67;
}
V_38 = 0 ;
ASSERT ( V_59 <= V_66 ) ;
if ( ( error = F_49 ( log ,
V_38 , ( int ) V_59 ,
V_63 , & V_40 ) ) )
goto V_65;
if ( V_40 != - 1 )
V_59 = V_40 ;
}
V_67:
V_60 = F_58 ( log ) ;
if ( V_59 >= V_60 ) {
V_38 = V_59 - V_60 ;
if ( ( error = F_52 ( log , V_38 ,
& V_59 , 0 ) ) == - 1 ) {
error = F_37 ( V_54 ) ;
goto V_65;
} else if ( error )
goto V_65;
} else {
V_38 = 0 ;
ASSERT ( V_59 <= V_66 ) ;
if ( ( error = F_52 ( log , V_38 ,
& V_59 , 0 ) ) == - 1 ) {
V_38 = V_64 - ( V_60 - V_59 ) ;
V_40 = V_64 ;
ASSERT ( V_38 <= V_66 &&
( T_4 ) V_64 - V_38 >= 0 ) ;
ASSERT ( V_59 <= V_66 ) ;
if ( ( error = F_52 ( log ,
V_38 , & V_40 ,
( int ) V_59 ) ) == - 1 ) {
error = F_37 ( V_54 ) ;
goto V_65;
} else if ( error )
goto V_65;
if ( V_40 != V_64 )
V_59 = V_40 ;
} else if ( error )
goto V_65;
}
F_8 ( V_9 ) ;
if ( V_59 == V_64 )
* V_58 = 0 ;
else
* V_58 = V_59 ;
return 0 ;
V_65:
F_8 ( V_9 ) ;
if ( error )
F_3 ( log -> V_4 , L_17 ) ;
return error ;
}
STATIC int
F_59 (
T_1 * log ,
T_4 * V_59 ,
T_4 * V_68 )
{
T_6 * V_69 ;
T_8 * V_70 ;
T_3 V_11 = NULL ;
T_2 * V_9 ;
int error , V_41 , V_71 ;
T_4 V_72 ;
T_4 V_73 ;
T_9 V_74 ;
int V_75 ;
V_71 = 0 ;
if ( ( error = F_55 ( log , V_59 ) ) )
return error ;
V_9 = F_2 ( log , 1 ) ;
if ( ! V_9 )
return V_45 ;
if ( * V_59 == 0 ) {
error = F_24 ( log , 0 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_76;
if ( F_48 ( V_11 ) == 0 ) {
* V_68 = 0 ;
goto V_76;
}
}
ASSERT ( * V_59 < V_66 ) ;
for ( V_41 = ( int ) ( * V_59 ) - 1 ; V_41 >= 0 ; V_41 -- ) {
error = F_24 ( log , V_41 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_76;
if ( V_27 == F_34 ( * ( V_77 * ) V_11 ) ) {
V_71 = 1 ;
break;
}
}
if ( ! V_71 ) {
for ( V_41 = log -> V_2 - 1 ; V_41 >= ( int ) ( * V_59 ) ; V_41 -- ) {
error = F_24 ( log , V_41 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_76;
if ( V_27 ==
F_34 ( * ( V_77 * ) V_11 ) ) {
V_71 = 2 ;
break;
}
}
}
if ( ! V_71 ) {
F_3 ( log -> V_4 , L_18 , V_5 ) ;
ASSERT ( 0 ) ;
return F_37 ( V_54 ) ;
}
V_69 = ( T_6 * ) V_11 ;
* V_68 = F_60 ( F_61 ( V_69 -> V_78 ) ) ;
log -> V_79 = V_41 ;
log -> V_80 = ( int ) * V_59 ;
log -> V_81 = F_34 ( V_69 -> V_82 ) ;
if ( V_71 == 2 )
log -> V_81 ++ ;
F_62 ( & log -> V_83 , F_61 ( V_69 -> V_78 ) ) ;
F_62 ( & log -> V_84 , F_61 ( V_69 -> V_85 ) ) ;
F_63 ( & log -> V_86 , log -> V_81 ,
F_7 ( log -> V_80 ) ) ;
F_63 ( & log -> V_87 , log -> V_81 ,
F_7 ( log -> V_80 ) ) ;
if ( F_53 ( & log -> V_4 -> V_21 ) ) {
int V_55 = F_34 ( V_69 -> V_55 ) ;
int V_88 = F_34 ( V_69 -> V_88 ) ;
if ( ( V_88 & V_89 ) &&
( V_55 > V_56 ) ) {
V_75 = V_55 / V_56 ;
if ( V_55 % V_56 )
V_75 ++ ;
} else {
V_75 = 1 ;
}
} else {
V_75 = 1 ;
}
V_73 = ( V_41 + V_75 + ( int )
F_54 ( F_34 ( V_69 -> V_57 ) ) ) % log -> V_2 ;
V_74 = F_64 ( & log -> V_83 ) ;
if ( * V_59 == V_73 &&
F_34 ( V_69 -> V_90 ) == 1 ) {
V_72 = ( V_41 + V_75 ) % log -> V_2 ;
error = F_24 ( log , V_72 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_76;
V_70 = ( T_8 * ) V_11 ;
if ( V_70 -> V_91 & V_92 ) {
F_65 ( & log -> V_83 ,
log -> V_81 , V_73 ) ;
F_65 ( & log -> V_84 ,
log -> V_81 , V_73 ) ;
* V_68 = V_73 ;
log -> V_4 -> V_93 |= V_94 ;
}
}
if ( ! F_66 ( log -> V_4 -> V_8 ) )
error = F_67 ( log , V_74 ) ;
V_76:
F_8 ( V_9 ) ;
if ( error )
F_3 ( log -> V_4 , L_19 ) ;
return error ;
}
STATIC int
F_56 (
T_1 * log ,
T_4 * V_10 )
{
T_2 * V_9 ;
T_3 V_11 ;
T_7 V_95 , V_96 ;
T_4 V_40 , V_33 , V_38 ;
T_4 V_60 ;
int error , V_64 = log -> V_2 ;
* V_10 = 0 ;
V_9 = F_2 ( log , 1 ) ;
if ( ! V_9 )
return V_45 ;
error = F_24 ( log , 0 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_65;
V_95 = F_48 ( V_11 ) ;
if ( V_95 == 0 ) {
* V_10 = 0 ;
F_8 ( V_9 ) ;
return - 1 ;
}
error = F_24 ( log , V_64 - 1 , 1 , V_9 , & V_11 ) ;
if ( error )
goto V_65;
V_96 = F_48 ( V_11 ) ;
if ( V_96 != 0 ) {
F_8 ( V_9 ) ;
return 0 ;
} else if ( V_95 != 1 ) {
F_3 ( log -> V_4 ,
L_20 ) ;
return F_37 ( V_97 ) ;
}
V_33 = V_64 - 1 ;
if ( ( error = F_46 ( log , V_9 , 0 , & V_33 , 0 ) ) )
goto V_65;
V_60 = F_57 ( log ) ;
ASSERT ( V_60 <= V_66 ) ;
if ( V_33 < V_60 )
V_60 = V_33 ;
V_38 = V_33 - V_60 ;
if ( ( error = F_49 ( log , V_38 ,
( int ) V_60 , 0 , & V_40 ) ) )
goto V_65;
if ( V_40 != - 1 )
V_33 = V_40 ;
if ( ( error = F_52 ( log , V_38 ,
& V_33 , 0 ) ) == - 1 ) {
error = F_37 ( V_54 ) ;
goto V_65;
} else if ( error )
goto V_65;
* V_10 = V_33 ;
V_65:
F_8 ( V_9 ) ;
if ( error )
return error ;
return - 1 ;
}
STATIC void
F_68 (
T_1 * log ,
T_3 V_44 ,
int V_34 ,
int V_98 ,
int V_99 ,
int V_100 )
{
T_6 * V_101 = ( T_6 * ) V_44 ;
memset ( V_44 , 0 , V_48 ) ;
V_101 -> V_26 = F_69 ( V_27 ) ;
V_101 -> V_82 = F_69 ( V_34 ) ;
V_101 -> V_88 = F_69 (
F_53 ( & log -> V_4 -> V_21 ) ? 2 : 1 ) ;
V_101 -> V_85 = F_70 ( F_71 ( V_34 , V_98 ) ) ;
V_101 -> V_78 = F_70 ( F_71 ( V_99 , V_100 ) ) ;
V_101 -> V_25 = F_69 ( V_23 ) ;
memcpy ( & V_101 -> V_24 , & log -> V_4 -> V_21 . V_22 , sizeof( V_102 ) ) ;
}
STATIC int
F_72 (
T_1 * log ,
int V_34 ,
int V_103 ,
int V_104 ,
int V_99 ,
int V_100 )
{
T_3 V_11 ;
T_2 * V_9 ;
int V_105 , V_106 ;
int V_107 = log -> V_7 ;
int V_108 = V_103 + V_104 ;
int V_43 ;
int error = 0 ;
int V_41 , V_42 = 0 ;
V_43 = 1 << F_50 ( V_104 ) ;
while ( ! ( V_9 = F_2 ( log , V_43 ) ) ) {
V_43 >>= 1 ;
if ( V_43 < V_107 )
return V_45 ;
}
V_105 = F_14 ( V_103 , V_107 ) ;
if ( V_105 != V_103 ) {
error = F_13 ( log , V_103 , 1 , V_9 ) ;
if ( error )
goto V_109;
V_42 = V_103 - V_105 ;
}
for ( V_41 = V_103 ; V_41 < V_108 ; V_41 += V_43 ) {
int V_46 , V_110 ;
V_46 = F_51 ( V_43 , V_108 - V_103 ) ;
V_110 = V_46 - V_42 ;
V_106 = F_14 ( V_108 , V_107 ) ;
if ( V_42 == 0 && ( V_103 + V_110 > V_106 ) ) {
V_11 = F_12 ( V_9 ) + F_7 ( V_106 - V_103 ) ;
error = F_25 ( log , V_106 , V_107 ,
V_9 , V_11 ) ;
if ( error )
break;
}
V_11 = F_10 ( log , V_103 , V_110 , V_9 ) ;
for (; V_42 < V_110 ; V_42 ++ ) {
F_68 ( log , V_11 , V_34 , V_41 + V_42 ,
V_99 , V_100 ) ;
V_11 += V_48 ;
}
error = F_27 ( log , V_103 , V_110 , V_9 ) ;
if ( error )
break;
V_103 += V_110 ;
V_42 = 0 ;
}
V_109:
F_8 ( V_9 ) ;
return error ;
}
STATIC int
F_67 (
T_1 * log ,
T_9 V_74 )
{
int V_99 , V_111 ;
int V_100 , V_112 ;
int V_113 , V_114 ;
int V_115 ;
int error ;
V_99 = F_73 ( V_74 ) ;
V_100 = F_60 ( V_74 ) ;
V_111 = log -> V_81 ;
V_112 = log -> V_80 ;
if ( V_111 == V_99 ) {
if ( F_36 ( V_112 < V_100 || V_112 >= log -> V_2 ) ) {
F_4 ( L_21 ,
V_116 , log -> V_4 ) ;
return F_37 ( V_12 ) ;
}
V_113 = V_100 + ( log -> V_2 - V_112 ) ;
} else {
if ( F_36 ( V_112 >= V_100 || V_111 != ( V_99 + 1 ) ) ) {
F_4 ( L_22 ,
V_116 , log -> V_4 ) ;
return F_37 ( V_12 ) ;
}
V_113 = V_100 - V_112 ;
}
if ( V_113 <= 0 ) {
ASSERT ( V_113 == 0 ) ;
return 0 ;
}
V_114 = F_57 ( log ) ;
V_114 = F_74 ( V_114 , V_113 ) ;
if ( ( V_112 + V_114 ) <= log -> V_2 ) {
error = F_72 ( log , ( V_111 - 1 ) ,
V_112 , V_114 , V_99 ,
V_100 ) ;
if ( error )
return error ;
} else {
V_115 = log -> V_2 - V_112 ;
error = F_72 ( log , ( V_111 - 1 ) ,
V_112 , V_115 , V_99 ,
V_100 ) ;
if ( error )
return error ;
V_115 = V_114 - ( log -> V_2 - V_112 ) ;
error = F_72 ( log , V_111 , 0 , V_115 ,
V_99 , V_100 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC T_10 *
F_75 (
struct V_117 * V_20 ,
T_11 V_118 )
{
T_10 * V_119 ;
struct V_120 * V_121 ;
F_76 (trans, n, head, r_list) {
if ( V_119 -> V_122 == V_118 )
return V_119 ;
}
return NULL ;
}
STATIC void
F_77 (
struct V_117 * V_20 ,
T_11 V_118 ,
T_9 V_123 )
{
T_10 * V_119 ;
V_119 = F_78 ( sizeof( T_10 ) , V_124 ) ;
V_119 -> V_122 = V_118 ;
V_119 -> V_125 = V_123 ;
F_79 ( & V_119 -> V_126 ) ;
F_80 ( & V_119 -> V_127 ) ;
F_81 ( & V_119 -> V_127 , V_20 ) ;
}
STATIC void
F_82 (
struct V_128 * V_20 )
{
T_12 * V_129 ;
V_129 = F_78 ( sizeof( T_12 ) , V_124 ) ;
F_79 ( & V_129 -> V_130 ) ;
F_83 ( & V_129 -> V_130 , V_20 ) ;
}
STATIC int
F_84 (
struct log * log ,
T_10 * V_119 ,
T_3 V_131 ,
int V_132 )
{
T_12 * V_129 ;
T_3 V_133 , V_134 ;
int V_135 ;
if ( F_85 ( & V_119 -> V_126 ) ) {
F_82 ( & V_119 -> V_126 ) ;
V_133 = ( T_3 ) & V_119 -> V_136 +
sizeof( V_137 ) - V_132 ;
memcpy ( V_133 , V_131 , V_132 ) ;
return 0 ;
}
V_129 = F_86 ( V_119 -> V_126 . V_138 , T_12 , V_130 ) ;
V_134 = V_129 -> V_139 [ V_129 -> V_140 - 1 ] . V_141 ;
V_135 = V_129 -> V_139 [ V_129 -> V_140 - 1 ] . V_142 ;
V_133 = F_87 ( V_134 , V_132 + V_135 , V_135 , 0u ) ;
memcpy ( & V_133 [ V_135 ] , V_131 , V_132 ) ;
V_129 -> V_139 [ V_129 -> V_140 - 1 ] . V_142 += V_132 ;
V_129 -> V_139 [ V_129 -> V_140 - 1 ] . V_141 = V_133 ;
F_88 ( log , V_119 , V_129 , 0 ) ;
return 0 ;
}
STATIC int
F_89 (
struct log * log ,
T_10 * V_119 ,
T_3 V_131 ,
int V_132 )
{
T_13 * V_143 ;
T_12 * V_129 ;
T_3 V_133 ;
if ( ! V_132 )
return 0 ;
if ( F_85 ( & V_119 -> V_126 ) ) {
if ( * ( T_7 * ) V_131 != V_144 ) {
F_3 ( log -> V_4 , L_23 ,
V_5 ) ;
ASSERT ( 0 ) ;
return F_37 ( V_54 ) ;
}
if ( V_132 == sizeof( V_137 ) )
F_82 ( & V_119 -> V_126 ) ;
memcpy ( & V_119 -> V_136 , V_131 , V_132 ) ;
return 0 ;
}
V_133 = F_90 ( V_132 , V_124 ) ;
memcpy ( V_133 , V_131 , V_132 ) ;
V_143 = ( T_13 * ) V_133 ;
V_129 = F_86 ( V_119 -> V_126 . V_138 , T_12 , V_130 ) ;
if ( V_129 -> V_145 != 0 &&
V_129 -> V_145 == V_129 -> V_140 ) {
F_82 ( & V_119 -> V_126 ) ;
V_129 = F_86 ( V_119 -> V_126 . V_138 ,
T_12 , V_130 ) ;
}
if ( V_129 -> V_145 == 0 ) {
if ( V_143 -> V_146 == 0 ||
V_143 -> V_146 > V_147 ) {
F_3 ( log -> V_4 ,
L_24 ,
V_143 -> V_146 ) ;
ASSERT ( 0 ) ;
return F_37 ( V_54 ) ;
}
V_129 -> V_145 = V_143 -> V_146 ;
V_129 -> V_139 =
F_78 ( V_129 -> V_145 * sizeof( V_148 ) ,
V_124 ) ;
}
ASSERT ( V_129 -> V_145 > V_129 -> V_140 ) ;
V_129 -> V_139 [ V_129 -> V_140 ] . V_141 = V_133 ;
V_129 -> V_139 [ V_129 -> V_140 ] . V_142 = V_132 ;
V_129 -> V_140 ++ ;
F_91 ( log , V_119 , V_129 , 0 ) ;
return 0 ;
}
STATIC int
F_92 (
struct log * log ,
T_10 * V_119 ,
int V_149 )
{
T_12 * V_129 , * V_121 ;
F_93 ( V_150 ) ;
F_94 ( & V_119 -> V_126 , & V_150 ) ;
F_95 (item, n, &sort_list, ri_list) {
T_14 * V_151 = V_129 -> V_139 [ 0 ] . V_141 ;
switch ( F_96 ( V_129 ) ) {
case V_152 :
if ( ! ( V_151 -> V_153 & V_154 ) ) {
F_97 ( log ,
V_119 , V_129 , V_149 ) ;
F_98 ( & V_129 -> V_130 , & V_119 -> V_126 ) ;
break;
}
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
F_99 ( log ,
V_119 , V_129 , V_149 ) ;
F_100 ( & V_129 -> V_130 , & V_119 -> V_126 ) ;
break;
default:
F_3 ( log -> V_4 ,
L_25 ,
V_5 ) ;
ASSERT ( 0 ) ;
return F_37 ( V_54 ) ;
}
}
ASSERT ( F_85 ( & V_150 ) ) ;
return 0 ;
}
STATIC int
F_101 (
struct log * log ,
T_12 * V_129 )
{
T_14 * V_151 = V_129 -> V_139 [ 0 ] . V_141 ;
struct V_128 * V_160 ;
struct V_161 * V_162 ;
if ( ! ( V_151 -> V_153 & V_154 ) ) {
F_102 ( log , V_151 ) ;
return 0 ;
}
V_160 = F_103 ( log , V_151 -> V_163 ) ;
F_104 (bcp, bucket, bc_list) {
if ( V_162 -> V_164 == V_151 -> V_163 &&
V_162 -> V_165 == V_151 -> V_166 ) {
V_162 -> V_167 ++ ;
F_105 ( log , V_151 ) ;
return 0 ;
}
}
V_162 = F_90 ( sizeof( struct V_161 ) , V_124 ) ;
V_162 -> V_164 = V_151 -> V_163 ;
V_162 -> V_165 = V_151 -> V_166 ;
V_162 -> V_167 = 1 ;
F_83 ( & V_162 -> V_168 , V_160 ) ;
F_106 ( log , V_151 ) ;
return 0 ;
}
STATIC int
F_107 (
struct log * log ,
T_4 V_169 ,
T_7 V_132 ,
T_15 V_170 )
{
struct V_128 * V_160 ;
struct V_161 * V_162 ;
if ( log -> V_171 == NULL ) {
ASSERT ( ! ( V_170 & V_154 ) ) ;
return 0 ;
}
V_160 = F_103 ( log , V_169 ) ;
F_104 (bcp, bucket, bc_list) {
if ( V_162 -> V_164 == V_169 && V_162 -> V_165 == V_132 )
goto V_71;
}
ASSERT ( ! ( V_170 & V_154 ) ) ;
return 0 ;
V_71:
if ( V_170 & V_154 ) {
if ( -- V_162 -> V_167 == 0 ) {
F_108 ( & V_162 -> V_168 ) ;
F_109 ( V_162 ) ;
}
}
return 1 ;
}
STATIC int
F_110 (
struct V_172 * V_19 ,
T_12 * V_129 ,
struct V_28 * V_9 ,
T_14 * V_151 )
{
int V_41 ;
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 ;
int V_179 ;
T_16 * V_180 ;
T_16 * V_181 ;
F_111 ( V_19 -> V_182 , V_151 ) ;
V_179 = F_112 ( V_9 ) >> V_19 -> V_21 . V_183 ;
for ( V_41 = 0 ; V_41 < V_179 ; V_41 ++ ) {
V_178 = ( V_41 * V_19 -> V_21 . V_184 ) +
F_113 ( V_185 , V_186 ) ;
while ( V_178 >=
( V_176 + V_177 ) ) {
V_174 += V_175 ;
V_174 = F_114 ( V_151 -> V_187 ,
V_151 -> V_188 , V_174 ) ;
if ( V_174 == - 1 )
return 0 ;
V_175 = F_115 ( V_151 -> V_187 ,
V_151 -> V_188 , V_174 ) ;
ASSERT ( V_175 > 0 ) ;
V_176 = V_174 << V_189 ;
V_177 = V_175 << V_189 ;
V_173 ++ ;
}
if ( V_178 < V_176 )
continue;
ASSERT ( V_129 -> V_139 [ V_173 ] . V_141 != NULL ) ;
ASSERT ( ( V_129 -> V_139 [ V_173 ] . V_142 % V_190 ) == 0 ) ;
ASSERT ( ( V_176 + V_177 ) <= F_112 ( V_9 ) ) ;
V_180 = V_129 -> V_139 [ V_173 ] . V_141 +
V_178 - V_176 ;
if ( F_36 ( * V_180 == 0 ) ) {
F_116 ( V_19 ,
L_26
L_27 ,
V_129 , V_9 ) ;
F_4 ( L_28 ,
V_116 , V_19 ) ;
return F_37 ( V_12 ) ;
}
V_181 = ( T_16 * ) F_117 ( V_9 ,
V_178 ) ;
* V_181 = * V_180 ;
}
return 0 ;
}
STATIC void
F_118 (
struct V_172 * V_19 ,
T_12 * V_129 ,
struct V_28 * V_9 ,
T_14 * V_151 )
{
int V_41 ;
int V_174 ;
int V_175 ;
int error ;
F_119 ( V_19 -> V_182 , V_151 ) ;
V_174 = 0 ;
V_41 = 1 ;
while ( 1 ) {
V_174 = F_114 ( V_151 -> V_187 ,
V_151 -> V_188 , V_174 ) ;
if ( V_174 == - 1 )
break;
V_175 = F_115 ( V_151 -> V_187 ,
V_151 -> V_188 , V_174 ) ;
ASSERT ( V_175 > 0 ) ;
ASSERT ( V_129 -> V_139 [ V_41 ] . V_141 != NULL ) ;
ASSERT ( V_129 -> V_139 [ V_41 ] . V_142 % V_190 == 0 ) ;
ASSERT ( F_112 ( V_9 ) >=
( ( T_7 ) V_174 << V_189 ) + ( V_175 << V_189 ) ) ;
error = 0 ;
if ( V_151 -> V_153 &
( V_191 | V_192 | V_193 ) ) {
if ( V_129 -> V_139 [ V_41 ] . V_141 == NULL ) {
F_116 ( V_19 ,
L_29 , V_5 ) ;
goto V_194;
}
if ( V_129 -> V_139 [ V_41 ] . V_142 < sizeof( V_195 ) ) {
F_116 ( V_19 ,
L_30 ,
V_129 -> V_139 [ V_41 ] . V_142 , V_5 ) ;
goto V_194;
}
error = F_120 ( V_19 , V_129 -> V_139 [ V_41 ] . V_141 ,
- 1 , 0 , V_196 ,
L_31 ) ;
if ( error )
goto V_194;
}
memcpy ( F_117 ( V_9 ,
( T_7 ) V_174 << V_189 ) ,
V_129 -> V_139 [ V_41 ] . V_141 ,
V_175 << V_189 ) ;
V_194:
V_41 ++ ;
V_174 += V_175 ;
}
ASSERT ( V_41 == V_129 -> V_145 ) ;
}
int
F_120 (
struct V_172 * V_19 ,
V_195 * V_197 ,
T_17 V_198 ,
T_7 type ,
T_7 V_170 ,
char * V_199 )
{
T_18 * V_200 = ( T_18 * ) V_197 ;
int V_201 = 0 ;
if ( F_121 ( V_197 -> V_202 ) != V_203 ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_32 ,
V_199 , V_198 , F_121 ( V_197 -> V_202 ) , V_203 ) ;
V_201 ++ ;
}
if ( V_197 -> V_204 != V_205 ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_33 ,
V_199 , V_198 , V_197 -> V_204 , V_205 ) ;
V_201 ++ ;
}
if ( V_197 -> V_206 != V_207 &&
V_197 -> V_206 != V_208 &&
V_197 -> V_206 != V_209 ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_34 ,
V_199 , V_198 , V_197 -> V_206 ) ;
V_201 ++ ;
}
if ( V_198 != - 1 && V_198 != F_34 ( V_197 -> V_210 ) ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_35
L_36 ,
V_199 , V_197 , V_198 , F_34 ( V_197 -> V_210 ) ) ;
V_201 ++ ;
}
if ( ! V_201 && V_197 -> V_210 ) {
if ( V_197 -> V_211 &&
F_61 ( V_197 -> V_212 ) >=
F_61 ( V_197 -> V_211 ) ) {
if ( ! V_197 -> V_213 ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_37 ,
V_199 , ( int ) F_34 ( V_197 -> V_210 ) , V_197 ) ;
V_201 ++ ;
}
}
if ( V_197 -> V_214 &&
F_61 ( V_197 -> V_215 ) >=
F_61 ( V_197 -> V_214 ) ) {
if ( ! V_197 -> V_216 ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_38 ,
V_199 , ( int ) F_34 ( V_197 -> V_210 ) , V_197 ) ;
V_201 ++ ;
}
}
if ( V_197 -> V_217 &&
F_61 ( V_197 -> V_218 ) >=
F_61 ( V_197 -> V_217 ) ) {
if ( ! V_197 -> V_219 ) {
if ( V_170 & V_196 )
F_116 ( V_19 ,
L_39 ,
V_199 , ( int ) F_34 ( V_197 -> V_210 ) , V_197 ) ;
V_201 ++ ;
}
}
}
if ( ! V_201 || ! ( V_170 & V_220 ) )
return V_201 ;
if ( V_170 & V_196 )
F_122 ( V_19 , L_40 , V_198 ) ;
ASSERT ( V_198 != - 1 ) ;
ASSERT ( V_170 & V_220 ) ;
memset ( V_200 , 0 , sizeof( T_18 ) ) ;
V_200 -> V_221 . V_202 = F_123 ( V_203 ) ;
V_200 -> V_221 . V_204 = V_205 ;
V_200 -> V_221 . V_206 = type ;
V_200 -> V_221 . V_210 = F_69 ( V_198 ) ;
return V_201 ;
}
STATIC void
F_124 (
T_5 * V_19 ,
T_1 * log ,
T_12 * V_129 ,
T_2 * V_9 ,
T_14 * V_151 )
{
T_7 type ;
F_125 ( log , V_151 ) ;
if ( V_19 -> V_222 == 0 ) {
return;
}
type = 0 ;
if ( V_151 -> V_153 & V_191 )
type |= V_207 ;
if ( V_151 -> V_153 & V_192 )
type |= V_208 ;
if ( V_151 -> V_153 & V_193 )
type |= V_209 ;
if ( log -> V_223 & type )
return;
F_118 ( V_19 , V_129 , V_9 , V_151 ) ;
}
STATIC int
F_126 (
T_1 * log ,
T_12 * V_129 )
{
T_14 * V_151 = V_129 -> V_139 [ 0 ] . V_141 ;
T_5 * V_19 = log -> V_4 ;
T_2 * V_9 ;
int error ;
T_7 V_224 ;
if ( F_107 ( log , V_151 -> V_163 ,
V_151 -> V_166 , V_151 -> V_153 ) ) {
F_127 ( log , V_151 ) ;
return 0 ;
}
F_128 ( log , V_151 ) ;
V_224 = V_225 ;
if ( ! ( V_151 -> V_153 & V_226 ) )
V_224 |= V_227 ;
V_9 = F_129 ( V_19 -> V_228 , V_151 -> V_163 , V_151 -> V_166 ,
V_224 ) ;
if ( F_130 ( V_9 ) ) {
F_22 ( L_41 , V_19 ,
V_9 , V_151 -> V_163 ) ;
error = F_42 ( V_9 ) ;
F_131 ( V_9 ) ;
return error ;
}
error = 0 ;
if ( V_151 -> V_153 & V_226 ) {
error = F_110 ( V_19 , V_129 , V_9 , V_151 ) ;
} else if ( V_151 -> V_153 &
( V_191 | V_192 | V_193 ) ) {
F_124 ( V_19 , log , V_129 , V_9 , V_151 ) ;
} else {
F_118 ( V_19 , V_129 , V_9 , V_151 ) ;
}
if ( error )
return F_37 ( error ) ;
if ( V_229 ==
F_121 ( * ( ( V_230 * ) F_117 ( V_9 , 0 ) ) ) &&
( F_112 ( V_9 ) != F_132 ( log -> V_4 -> V_21 . V_231 ,
( V_232 ) F_133 ( log -> V_4 ) ) ) ) {
F_134 ( V_9 ) ;
error = F_31 ( V_19 , V_9 ) ;
} else {
ASSERT ( V_9 -> V_29 -> V_30 == V_19 ) ;
F_135 ( V_9 , F_41 ) ;
F_136 ( V_19 , V_9 ) ;
}
return ( error ) ;
}
STATIC int
F_137 (
T_1 * log ,
T_12 * V_129 )
{
T_13 * V_143 ;
T_5 * V_19 = log -> V_4 ;
T_2 * V_9 ;
V_185 * V_233 ;
int V_132 ;
T_3 V_234 ;
T_3 V_235 ;
int error ;
int V_236 ;
T_7 V_237 ;
T_19 * V_238 ;
int V_239 = 0 ;
if ( V_129 -> V_139 [ 0 ] . V_142 == sizeof( T_13 ) ) {
V_143 = V_129 -> V_139 [ 0 ] . V_141 ;
} else {
V_143 = F_90 ( sizeof( T_13 ) , V_124 ) ;
V_239 = 1 ;
error = F_138 ( & V_129 -> V_139 [ 0 ] , V_143 ) ;
if ( error )
goto error;
}
if ( F_107 ( log , V_143 -> V_240 ,
V_143 -> V_241 , 0 ) ) {
error = 0 ;
F_139 ( log , V_143 ) ;
goto error;
}
F_140 ( log , V_143 ) ;
V_9 = F_129 ( V_19 -> V_228 , V_143 -> V_240 , V_143 -> V_241 ,
V_225 ) ;
if ( F_130 ( V_9 ) ) {
F_22 ( L_42 , V_19 ,
V_9 , V_143 -> V_240 ) ;
error = F_42 ( V_9 ) ;
F_131 ( V_9 ) ;
goto error;
}
error = 0 ;
ASSERT ( V_143 -> V_242 & V_243 ) ;
V_233 = ( V_185 * ) F_117 ( V_9 , V_143 -> V_244 ) ;
if ( F_36 ( F_121 ( V_233 -> V_245 ) != V_229 ) ) {
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_43 ,
V_5 , V_233 , V_9 , V_143 -> V_246 ) ;
F_4 ( L_44 ,
V_116 , V_19 ) ;
error = V_12 ;
goto error;
}
V_238 = V_129 -> V_139 [ 1 ] . V_141 ;
if ( F_36 ( V_238 -> V_245 != V_229 ) ) {
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_45 ,
V_5 , V_129 , V_143 -> V_246 ) ;
F_4 ( L_46 ,
V_116 , V_19 ) ;
error = V_12 ;
goto error;
}
if ( V_238 -> V_247 < F_121 ( V_233 -> V_247 ) ) {
if ( F_121 ( V_233 -> V_247 ) == V_248 &&
V_238 -> V_247 < ( V_248 >> 1 ) ) {
} else {
F_131 ( V_9 ) ;
F_141 ( log , V_143 ) ;
error = 0 ;
goto error;
}
}
V_238 -> V_247 = 0 ;
if ( F_36 ( ( V_238 -> V_249 & V_250 ) == V_251 ) ) {
if ( ( V_238 -> V_252 != V_253 ) &&
( V_238 -> V_252 != V_254 ) ) {
F_142 ( L_47 ,
V_116 , V_19 , V_238 ) ;
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_48
L_49 ,
V_5 , V_129 , V_233 , V_9 , V_143 -> V_246 ) ;
error = V_12 ;
goto error;
}
} else if ( F_36 ( ( V_238 -> V_249 & V_250 ) == V_255 ) ) {
if ( ( V_238 -> V_252 != V_253 ) &&
( V_238 -> V_252 != V_254 ) &&
( V_238 -> V_252 != V_256 ) ) {
F_142 ( L_50 ,
V_116 , V_19 , V_238 ) ;
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_51
L_49 ,
V_5 , V_129 , V_233 , V_9 , V_143 -> V_246 ) ;
error = V_12 ;
goto error;
}
}
if ( F_36 ( V_238 -> V_257 + V_238 -> V_258 > V_238 -> V_259 ) ) {
F_142 ( L_52 ,
V_116 , V_19 , V_238 ) ;
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_53
L_54 ,
V_5 , V_129 , V_233 , V_9 , V_143 -> V_246 ,
V_238 -> V_257 + V_238 -> V_258 ,
V_238 -> V_259 ) ;
error = V_12 ;
goto error;
}
if ( F_36 ( V_238 -> V_260 > V_19 -> V_21 . V_184 ) ) {
F_142 ( L_55 ,
V_116 , V_19 , V_238 ) ;
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_53
L_56 , V_5 ,
V_129 , V_233 , V_9 , V_143 -> V_246 , V_238 -> V_260 ) ;
error = V_12 ;
goto error;
}
if ( F_36 ( V_129 -> V_139 [ 1 ] . V_142 > sizeof( struct V_261 ) ) ) {
F_142 ( L_57 ,
V_116 , V_19 , V_238 ) ;
F_131 ( V_9 ) ;
F_116 ( V_19 ,
L_58 ,
V_5 , V_129 -> V_139 [ 1 ] . V_142 , V_129 ) ;
error = V_12 ;
goto error;
}
F_143 ( V_233 , V_129 -> V_139 [ 1 ] . V_141 ) ;
if ( V_129 -> V_139 [ 1 ] . V_142 > sizeof( struct V_261 ) ) {
memcpy ( ( T_3 ) V_233 + sizeof( struct V_261 ) ,
V_129 -> V_139 [ 1 ] . V_141 + sizeof( struct V_261 ) ,
V_129 -> V_139 [ 1 ] . V_142 - sizeof( struct V_261 ) ) ;
}
V_237 = V_143 -> V_242 ;
switch ( V_237 & ( V_262 | V_263 ) ) {
case V_262 :
F_144 ( V_233 , V_143 -> V_264 . V_265 ) ;
break;
case V_263 :
memcpy ( F_145 ( V_233 ) ,
& V_143 -> V_264 . V_266 ,
sizeof( V_102 ) ) ;
break;
}
if ( V_143 -> V_146 == 2 )
goto V_267;
V_132 = V_129 -> V_139 [ 2 ] . V_142 ;
V_234 = V_129 -> V_139 [ 2 ] . V_141 ;
ASSERT ( V_143 -> V_146 <= 4 ) ;
ASSERT ( ( V_143 -> V_146 == 3 ) || ( V_237 & V_268 ) ) ;
ASSERT ( ! ( V_237 & V_269 ) ||
( V_132 == V_143 -> V_270 ) ) ;
switch ( V_237 & V_269 ) {
case V_271 :
case V_272 :
memcpy ( F_145 ( V_233 ) , V_234 , V_132 ) ;
break;
case V_273 :
F_146 ( V_19 , (struct V_274 * ) V_234 , V_132 ,
( V_275 * ) F_145 ( V_233 ) ,
F_147 ( V_233 , V_19 ) ) ;
break;
default:
ASSERT ( ( V_237 & V_269 ) == 0 ) ;
break;
}
if ( V_143 -> V_242 & V_268 ) {
if ( V_143 -> V_242 & V_269 ) {
V_236 = 3 ;
} else {
V_236 = 2 ;
}
V_132 = V_129 -> V_139 [ V_236 ] . V_142 ;
V_234 = V_129 -> V_139 [ V_236 ] . V_141 ;
ASSERT ( V_132 == V_143 -> V_276 ) ;
switch ( V_143 -> V_242 & V_268 ) {
case V_277 :
case V_278 :
V_235 = F_148 ( V_233 ) ;
ASSERT ( V_132 <= F_149 ( V_233 , V_19 ) ) ;
memcpy ( V_235 , V_234 , V_132 ) ;
break;
case V_279 :
V_235 = F_148 ( V_233 ) ;
F_146 ( V_19 , (struct V_274 * ) V_234 ,
V_132 , ( V_275 * ) V_235 ,
F_149 ( V_233 , V_19 ) ) ;
break;
default:
F_3 ( log -> V_4 , L_59 , V_5 ) ;
ASSERT ( 0 ) ;
F_131 ( V_9 ) ;
error = V_54 ;
goto error;
}
}
V_267:
ASSERT ( V_9 -> V_29 -> V_30 == V_19 ) ;
F_135 ( V_9 , F_41 ) ;
F_136 ( V_19 , V_9 ) ;
error:
if ( V_239 )
F_109 ( V_143 ) ;
return F_37 ( error ) ;
}
STATIC int
F_150 (
T_1 * log ,
T_12 * V_129 )
{
T_20 * V_280 = V_129 -> V_139 [ 0 ] . V_141 ;
ASSERT ( V_280 ) ;
if ( V_280 -> V_281 & V_282 )
log -> V_223 |= V_207 ;
if ( V_280 -> V_281 & V_283 )
log -> V_223 |= V_208 ;
if ( V_280 -> V_281 & V_284 )
log -> V_223 |= V_209 ;
return ( 0 ) ;
}
STATIC int
F_151 (
T_1 * log ,
T_12 * V_129 )
{
T_5 * V_19 = log -> V_4 ;
T_2 * V_9 ;
struct V_285 * V_197 , * V_286 ;
int error ;
T_21 * V_287 ;
T_7 type ;
if ( V_19 -> V_222 == 0 )
return ( 0 ) ;
V_286 = V_129 -> V_139 [ 1 ] . V_141 ;
if ( V_286 == NULL ) {
F_116 ( log -> V_4 , L_60 , V_5 ) ;
return F_37 ( V_54 ) ;
}
if ( V_129 -> V_139 [ 1 ] . V_142 < sizeof( V_195 ) ) {
F_116 ( log -> V_4 , L_61 ,
V_129 -> V_139 [ 1 ] . V_142 , V_5 ) ;
return F_37 ( V_54 ) ;
}
type = V_286 -> V_206 & ( V_207 | V_208 | V_209 ) ;
ASSERT ( type ) ;
if ( log -> V_223 & type )
return ( 0 ) ;
V_287 = V_129 -> V_139 [ 0 ] . V_141 ;
ASSERT ( V_287 ) ;
error = F_120 ( V_19 , V_286 , V_287 -> V_288 , 0 , V_196 ,
L_62 ) ;
if ( error )
return F_37 ( V_54 ) ;
ASSERT ( V_287 -> V_289 == 1 ) ;
error = F_152 ( V_19 , V_19 -> V_228 ,
V_287 -> V_290 ,
F_153 ( V_19 , V_287 -> V_289 ) ,
0 , & V_9 ) ;
if ( error ) {
F_22 ( L_63 , V_19 ,
V_9 , V_287 -> V_290 ) ;
return error ;
}
ASSERT ( V_9 ) ;
V_197 = ( V_195 * ) F_117 ( V_9 , V_287 -> V_291 ) ;
error = F_120 ( V_19 , V_197 , V_287 -> V_288 , 0 , V_196 ,
L_64 ) ;
if ( error ) {
F_131 ( V_9 ) ;
return F_37 ( V_54 ) ;
}
memcpy ( V_197 , V_286 , V_129 -> V_139 [ 1 ] . V_142 ) ;
ASSERT ( V_287 -> V_292 == 2 ) ;
ASSERT ( V_9 -> V_29 -> V_30 == V_19 ) ;
F_135 ( V_9 , F_41 ) ;
F_136 ( V_19 , V_9 ) ;
return ( 0 ) ;
}
STATIC int
F_154 (
T_1 * log ,
T_12 * V_129 ,
T_9 V_123 )
{
int error ;
T_5 * V_19 = log -> V_4 ;
T_22 * V_293 ;
T_23 * V_294 ;
V_294 = V_129 -> V_139 [ 0 ] . V_141 ;
V_293 = F_155 ( V_19 , V_294 -> V_295 ) ;
if ( ( error = F_156 ( & ( V_129 -> V_139 [ 0 ] ) ,
& ( V_293 -> V_296 ) ) ) ) {
F_157 ( V_293 ) ;
return error ;
}
F_158 ( & V_293 -> V_297 , V_294 -> V_295 ) ;
F_159 ( & log -> V_298 -> V_299 ) ;
F_160 ( log -> V_298 , & V_293 -> V_300 , V_123 ) ;
return 0 ;
}
STATIC int
F_161 (
T_1 * log ,
T_12 * V_129 )
{
T_24 * V_301 ;
T_22 * V_293 = NULL ;
T_25 * V_302 ;
T_26 V_303 ;
struct V_304 V_305 ;
struct V_306 * V_307 = log -> V_298 ;
V_301 = V_129 -> V_139 [ 0 ] . V_141 ;
ASSERT ( ( V_129 -> V_139 [ 0 ] . V_142 == ( sizeof( V_308 ) +
( ( V_301 -> V_309 - 1 ) * sizeof( V_310 ) ) ) ) ||
( V_129 -> V_139 [ 0 ] . V_142 == ( sizeof( V_311 ) +
( ( V_301 -> V_309 - 1 ) * sizeof( V_312 ) ) ) ) ) ;
V_303 = V_301 -> V_313 ;
F_159 ( & V_307 -> V_299 ) ;
V_302 = F_162 ( V_307 , & V_305 , 0 ) ;
while ( V_302 != NULL ) {
if ( V_302 -> V_314 == V_159 ) {
V_293 = ( T_22 * ) V_302 ;
if ( V_293 -> V_296 . V_303 == V_303 ) {
F_163 ( V_307 , V_302 ) ;
F_157 ( V_293 ) ;
F_159 ( & V_307 -> V_299 ) ;
break;
}
}
V_302 = F_164 ( V_307 , & V_305 ) ;
}
F_165 ( V_307 , & V_305 ) ;
F_166 ( & V_307 -> V_299 ) ;
return 0 ;
}
STATIC void
F_167 (
struct V_315 * V_119 )
{
T_12 * V_129 , * V_121 ;
int V_41 ;
F_95 (item, n, &trans->r_itemq, ri_list) {
F_108 ( & V_129 -> V_130 ) ;
for ( V_41 = 0 ; V_41 < V_129 -> V_140 ; V_41 ++ )
F_109 ( V_129 -> V_139 [ V_41 ] . V_141 ) ;
F_109 ( V_129 -> V_139 ) ;
F_109 ( V_129 ) ;
}
F_109 ( V_119 ) ;
}
STATIC int
F_168 (
struct log * log ,
struct V_315 * V_119 ,
T_12 * V_129 )
{
F_169 ( log , V_119 , V_129 , V_316 ) ;
switch ( F_96 ( V_129 ) ) {
case V_152 :
return F_101 ( log , V_129 ) ;
case V_157 :
return F_150 ( log , V_129 ) ;
case V_155 :
case V_159 :
case V_158 :
case V_156 :
return 0 ;
default:
F_3 ( log -> V_4 , L_65 ,
V_5 , F_96 ( V_129 ) ) ;
ASSERT ( 0 ) ;
return F_37 ( V_54 ) ;
}
}
STATIC int
F_170 (
struct log * log ,
struct V_315 * V_119 ,
T_12 * V_129 )
{
F_169 ( log , V_119 , V_129 , V_317 ) ;
switch ( F_96 ( V_129 ) ) {
case V_152 :
return F_126 ( log , V_129 ) ;
case V_155 :
return F_137 ( log , V_129 ) ;
case V_159 :
return F_154 ( log , V_129 , V_119 -> V_125 ) ;
case V_158 :
return F_161 ( log , V_129 ) ;
case V_156 :
return F_151 ( log , V_129 ) ;
case V_157 :
return 0 ;
default:
F_3 ( log -> V_4 , L_65 ,
V_5 , F_96 ( V_129 ) ) ;
ASSERT ( 0 ) ;
return F_37 ( V_54 ) ;
}
}
STATIC int
F_171 (
struct log * log ,
struct V_315 * V_119 ,
int V_149 )
{
int error = 0 ;
T_12 * V_129 ;
F_172 ( & V_119 -> V_127 ) ;
error = F_92 ( log , V_119 , V_149 ) ;
if ( error )
return error ;
F_104 (item, &trans->r_itemq, ri_list) {
if ( V_149 == V_316 )
error = F_168 ( log , V_119 , V_129 ) ;
else
error = F_170 ( log , V_119 , V_129 ) ;
if ( error )
return error ;
}
F_167 ( V_119 ) ;
return 0 ;
}
STATIC int
F_173 (
struct log * log ,
T_10 * V_119 )
{
F_3 ( log -> V_4 , L_66 , V_5 ) ;
return 0 ;
}
STATIC int
F_174 (
T_1 * log ,
struct V_117 V_318 [] ,
T_6 * V_69 ,
T_3 V_131 ,
int V_149 )
{
T_3 V_319 ;
int V_320 ;
T_8 * V_321 ;
T_10 * V_119 ;
T_11 V_118 ;
int error ;
unsigned long V_322 ;
T_7 V_170 ;
V_319 = V_131 + F_34 ( V_69 -> V_57 ) ;
V_320 = F_34 ( V_69 -> V_90 ) ;
if ( F_35 ( log -> V_4 , V_69 ) )
return ( F_37 ( V_54 ) ) ;
while ( ( V_131 < V_319 ) && V_320 ) {
ASSERT ( V_131 + sizeof( T_8 ) <= V_319 ) ;
V_321 = ( T_8 * ) V_131 ;
V_131 += sizeof( T_8 ) ;
if ( V_321 -> V_323 != V_324 &&
V_321 -> V_323 != V_325 ) {
F_3 ( log -> V_4 , L_67 ,
V_5 , V_321 -> V_323 ) ;
ASSERT ( 0 ) ;
return ( F_37 ( V_54 ) ) ;
}
V_118 = F_34 ( V_321 -> V_326 ) ;
V_322 = F_175 ( V_118 ) ;
V_119 = F_75 ( & V_318 [ V_322 ] , V_118 ) ;
if ( V_119 == NULL ) {
if ( V_321 -> V_91 & V_327 )
F_77 ( & V_318 [ V_322 ] , V_118 ,
F_61 ( V_69 -> V_85 ) ) ;
} else {
if ( V_131 + F_34 ( V_321 -> V_328 ) > V_319 ) {
F_3 ( log -> V_4 , L_68 ,
V_5 , F_34 ( V_321 -> V_328 ) ) ;
F_176 ( 1 ) ;
return ( F_37 ( V_54 ) ) ;
}
V_170 = V_321 -> V_91 & ~ V_329 ;
if ( V_170 & V_330 )
V_170 &= ~ V_331 ;
switch ( V_170 ) {
case V_332 :
error = F_171 ( log ,
V_119 , V_149 ) ;
break;
case V_92 :
error = F_173 ( log , V_119 ) ;
break;
case V_330 :
error = F_84 ( log ,
V_119 , V_131 ,
F_34 ( V_321 -> V_328 ) ) ;
break;
case V_327 :
F_3 ( log -> V_4 , L_69 ,
V_5 ) ;
ASSERT ( 0 ) ;
error = F_37 ( V_54 ) ;
break;
case 0 :
case V_331 :
error = F_89 ( log , V_119 ,
V_131 , F_34 ( V_321 -> V_328 ) ) ;
break;
default:
F_3 ( log -> V_4 , L_70 ,
V_5 , V_170 ) ;
ASSERT ( 0 ) ;
error = F_37 ( V_54 ) ;
break;
}
if ( error )
return error ;
}
V_131 += F_34 ( V_321 -> V_328 ) ;
V_320 -- ;
}
return 0 ;
}
STATIC int
F_177 (
T_5 * V_19 ,
T_22 * V_293 )
{
T_27 * V_333 ;
T_28 * V_334 ;
int V_41 ;
int error = 0 ;
T_29 * V_335 ;
T_30 V_336 ;
ASSERT ( ! F_178 ( V_337 , & V_293 -> V_338 ) ) ;
for ( V_41 = 0 ; V_41 < V_293 -> V_296 . V_295 ; V_41 ++ ) {
V_335 = & ( V_293 -> V_296 . V_339 [ V_41 ] ) ;
V_336 = F_179 ( V_19 ,
F_180 ( V_19 , V_335 -> V_340 ) ) ;
if ( ( V_336 == 0 ) ||
( V_335 -> V_341 == 0 ) ||
( V_336 >= V_19 -> V_21 . V_342 ) ||
( V_335 -> V_341 >= V_19 -> V_21 . V_343 ) ) {
F_181 ( V_293 , V_293 -> V_296 . V_295 ) ;
return F_37 ( V_54 ) ;
}
}
V_334 = F_182 ( V_19 , 0 ) ;
error = F_183 ( V_334 , 0 , F_184 ( V_19 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_344;
V_333 = F_185 ( V_334 , V_293 , V_293 -> V_296 . V_295 ) ;
for ( V_41 = 0 ; V_41 < V_293 -> V_296 . V_295 ; V_41 ++ ) {
V_335 = & ( V_293 -> V_296 . V_339 [ V_41 ] ) ;
error = F_186 ( V_334 , V_335 -> V_340 , V_335 -> V_341 ) ;
if ( error )
goto V_344;
F_187 ( V_334 , V_333 , V_335 -> V_340 ,
V_335 -> V_341 ) ;
}
F_188 ( V_337 , & V_293 -> V_338 ) ;
error = F_189 ( V_334 , 0 ) ;
return error ;
V_344:
F_190 ( V_334 , V_345 ) ;
return error ;
}
STATIC int
F_191 (
T_1 * log )
{
T_25 * V_302 ;
T_22 * V_293 ;
int error = 0 ;
struct V_304 V_305 ;
struct V_306 * V_307 ;
V_307 = log -> V_298 ;
F_159 ( & V_307 -> V_299 ) ;
V_302 = F_162 ( V_307 , & V_305 , 0 ) ;
while ( V_302 != NULL ) {
if ( V_302 -> V_314 != V_159 ) {
#ifdef F_192
for (; V_302 ; V_302 = F_164 ( V_307 , & V_305 ) )
ASSERT ( V_302 -> V_314 != V_159 ) ;
#endif
break;
}
V_293 = ( T_22 * ) V_302 ;
if ( F_178 ( V_337 , & V_293 -> V_338 ) ) {
V_302 = F_164 ( V_307 , & V_305 ) ;
continue;
}
F_166 ( & V_307 -> V_299 ) ;
error = F_177 ( log -> V_4 , V_293 ) ;
F_159 ( & V_307 -> V_299 ) ;
if ( error )
goto V_47;
V_302 = F_164 ( V_307 , & V_305 ) ;
}
V_47:
F_165 ( V_307 , & V_305 ) ;
F_166 ( & V_307 -> V_299 ) ;
return error ;
}
STATIC void
F_193 (
T_5 * V_19 ,
T_31 V_346 ,
int V_160 )
{
T_28 * V_334 ;
T_32 * V_347 ;
T_2 * V_348 ;
int V_11 ;
int error ;
V_334 = F_182 ( V_19 , V_349 ) ;
error = F_183 ( V_334 , 0 , F_194 ( V_19 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_350;
error = F_195 ( V_19 , V_334 , V_346 , & V_348 ) ;
if ( error )
goto V_350;
V_347 = F_196 ( V_348 ) ;
V_347 -> V_351 [ V_160 ] = F_69 ( V_352 ) ;
V_11 = F_113 ( T_32 , V_351 ) +
( sizeof( T_16 ) * V_160 ) ;
F_197 ( V_334 , V_348 , V_11 ,
( V_11 + sizeof( T_16 ) - 1 ) ) ;
error = F_189 ( V_334 , 0 ) ;
if ( error )
goto V_353;
return;
V_350:
F_190 ( V_334 , V_345 ) ;
V_353:
F_3 ( V_19 , L_71 , V_5 , V_346 ) ;
return;
}
STATIC T_16
F_198 (
struct V_172 * V_19 ,
T_31 V_346 ,
T_16 V_354 ,
int V_160 )
{
struct V_28 * V_355 ;
struct V_356 * V_233 ;
struct V_357 * V_358 ;
T_33 V_359 ;
int error ;
V_359 = F_199 ( V_19 , V_346 , V_354 ) ;
error = F_200 ( V_19 , NULL , V_359 , 0 , 0 , & V_358 ) ;
if ( error )
goto V_360;
error = F_201 ( V_19 , NULL , V_358 , & V_233 , & V_355 , V_225 ) ;
if ( error )
goto V_361;
ASSERT ( V_358 -> V_362 . V_363 == 0 ) ;
ASSERT ( V_358 -> V_362 . V_249 != 0 ) ;
V_354 = F_34 ( V_233 -> V_186 ) ;
F_131 ( V_355 ) ;
V_358 -> V_362 . V_364 = 0 ;
F_202 ( V_358 ) ;
return V_354 ;
V_361:
F_202 ( V_358 ) ;
V_360:
F_193 ( V_19 , V_346 , V_160 ) ;
return V_352 ;
}
STATIC void
F_203 (
T_1 * log )
{
T_5 * V_19 ;
T_31 V_346 ;
T_32 * V_347 ;
T_2 * V_348 ;
T_16 V_354 ;
int V_160 ;
int error ;
T_7 V_365 ;
V_19 = log -> V_4 ;
V_365 = V_19 -> V_366 ;
V_19 -> V_366 = 0 ;
for ( V_346 = 0 ; V_346 < V_19 -> V_21 . V_367 ; V_346 ++ ) {
error = F_195 ( V_19 , NULL , V_346 , & V_348 ) ;
if ( error ) {
continue;
}
V_347 = F_196 ( V_348 ) ;
for ( V_160 = 0 ; V_160 < V_368 ; V_160 ++ ) {
V_354 = F_34 ( V_347 -> V_351 [ V_160 ] ) ;
while ( V_354 != V_352 ) {
F_131 ( V_348 ) ;
V_354 = F_198 ( V_19 ,
V_346 , V_354 , V_160 ) ;
error = F_195 ( V_19 , NULL , V_346 , & V_348 ) ;
ASSERT ( error == 0 ) ;
V_347 = F_196 ( V_348 ) ;
}
}
F_131 ( V_348 ) ;
}
V_19 -> V_366 = V_365 ;
}
STATIC void
F_204 (
T_1 * log ,
T_34 * V_369 ,
int V_370 )
{
int V_41 ;
V_77 * V_371 ;
T_7 V_372 = 0 ;
V_371 = ( V_77 * ) V_369 -> V_373 ;
for ( V_41 = 0 ; V_41 < ( V_370 >> 2 ) ; V_41 ++ ) {
V_372 ^= F_34 ( * V_371 ) ;
V_371 ++ ;
}
V_369 -> V_374 . V_375 = F_69 ( V_372 ) ;
}
void
F_205 (
T_1 * log ,
T_34 * V_369 ,
int V_376 )
{
int V_41 , V_42 , V_377 ;
int V_370 = V_369 -> V_378 + V_376 ;
V_77 V_379 ;
T_3 V_131 ;
F_204 ( log , V_369 , V_370 ) ;
V_379 = F_206 ( V_369 -> V_374 . V_85 ) ;
V_131 = V_369 -> V_373 ;
for ( V_41 = 0 ; V_41 < F_54 ( V_370 ) &&
V_41 < ( V_56 / V_48 ) ; V_41 ++ ) {
V_369 -> V_374 . V_380 [ V_41 ] = * ( V_77 * ) V_131 ;
* ( V_77 * ) V_131 = V_379 ;
V_131 += V_48 ;
}
if ( F_53 ( & log -> V_4 -> V_21 ) ) {
T_35 * V_381 = V_369 -> V_382 ;
for ( ; V_41 < F_54 ( V_370 ) ; V_41 ++ ) {
V_42 = V_41 / ( V_56 / V_48 ) ;
V_377 = V_41 % ( V_56 / V_48 ) ;
V_381 [ V_42 ] . V_383 . V_384 [ V_377 ] = * ( V_77 * ) V_131 ;
* ( V_77 * ) V_131 = V_379 ;
V_131 += V_48 ;
}
for ( V_41 = 1 ; V_41 < log -> V_385 ; V_41 ++ ) {
V_381 [ V_41 ] . V_383 . V_386 = V_379 ;
}
}
}
STATIC void
F_207 (
T_6 * V_69 ,
T_3 V_131 ,
T_1 * log )
{
int V_41 , V_42 , V_377 ;
for ( V_41 = 0 ; V_41 < F_54 ( F_34 ( V_69 -> V_57 ) ) &&
V_41 < ( V_56 / V_48 ) ; V_41 ++ ) {
* ( V_77 * ) V_131 = * ( V_77 * ) & V_69 -> V_380 [ V_41 ] ;
V_131 += V_48 ;
}
if ( F_53 ( & log -> V_4 -> V_21 ) ) {
T_35 * V_381 = ( T_35 * ) V_69 ;
for ( ; V_41 < F_54 ( F_34 ( V_69 -> V_57 ) ) ; V_41 ++ ) {
V_42 = V_41 / ( V_56 / V_48 ) ;
V_377 = V_41 % ( V_56 / V_48 ) ;
* ( V_77 * ) V_131 = V_381 [ V_42 ] . V_383 . V_384 [ V_377 ] ;
V_131 += V_48 ;
}
}
}
STATIC int
F_208 (
T_1 * log ,
T_6 * V_69 ,
T_4 V_169 )
{
int V_387 ;
if ( F_36 ( F_34 ( V_69 -> V_26 ) != V_27 ) ) {
F_4 ( L_72 ,
V_116 , log -> V_4 ) ;
return F_37 ( V_12 ) ;
}
if ( F_36 (
( ! V_69 -> V_88 ||
( F_34 ( V_69 -> V_88 ) & ( ~ V_388 ) ) ) ) ) {
F_3 ( log -> V_4 , L_73 ,
V_5 , F_34 ( V_69 -> V_88 ) ) ;
return F_37 ( V_54 ) ;
}
V_387 = F_34 ( V_69 -> V_57 ) ;
if ( F_36 ( V_387 <= 0 || V_387 > V_66 ) ) {
F_4 ( L_74 ,
V_116 , log -> V_4 ) ;
return F_37 ( V_12 ) ;
}
if ( F_36 ( V_169 > log -> V_2 || V_169 > V_66 ) ) {
F_4 ( L_75 ,
V_116 , log -> V_4 ) ;
return F_37 ( V_12 ) ;
}
return 0 ;
}
STATIC int
F_209 (
T_1 * log ,
T_4 V_59 ,
T_4 V_68 ,
int V_149 )
{
T_6 * V_69 ;
T_4 V_10 ;
T_3 V_11 ;
T_2 * V_389 , * V_390 ;
int error = 0 , V_55 ;
int V_391 , V_392 ;
int V_75 , V_393 , V_394 ;
struct V_117 V_318 [ V_395 ] ;
ASSERT ( V_59 != V_68 ) ;
if ( F_53 ( & log -> V_4 -> V_21 ) ) {
V_389 = F_2 ( log , 1 ) ;
if ( ! V_389 )
return V_45 ;
error = F_24 ( log , V_68 , 1 , V_389 , & V_11 ) ;
if ( error )
goto V_396;
V_69 = ( T_6 * ) V_11 ;
error = F_208 ( log , V_69 , V_68 ) ;
if ( error )
goto V_396;
V_55 = F_34 ( V_69 -> V_55 ) ;
if ( ( F_34 ( V_69 -> V_88 ) & V_89 ) &&
( V_55 > V_56 ) ) {
V_75 = V_55 / V_56 ;
if ( V_55 % V_56 )
V_75 ++ ;
F_8 ( V_389 ) ;
V_389 = F_2 ( log , V_75 ) ;
} else {
V_75 = 1 ;
}
} else {
ASSERT ( log -> V_7 == 1 ) ;
V_75 = 1 ;
V_389 = F_2 ( log , 1 ) ;
V_55 = V_397 ;
}
if ( ! V_389 )
return V_45 ;
V_390 = F_2 ( log , F_54 ( V_55 ) ) ;
if ( ! V_390 ) {
F_8 ( V_389 ) ;
return V_45 ;
}
memset ( V_318 , 0 , sizeof( V_318 ) ) ;
if ( V_68 <= V_59 ) {
for ( V_10 = V_68 ; V_10 < V_59 ; ) {
error = F_24 ( log , V_10 , V_75 , V_389 , & V_11 ) ;
if ( error )
goto V_398;
V_69 = ( T_6 * ) V_11 ;
error = F_208 ( log , V_69 , V_10 ) ;
if ( error )
goto V_398;
V_391 = ( int ) F_54 ( F_34 ( V_69 -> V_57 ) ) ;
error = F_24 ( log , V_10 + V_75 , V_391 , V_390 ,
& V_11 ) ;
if ( error )
goto V_398;
F_207 ( V_69 , V_11 , log ) ;
if ( ( error = F_174 ( log ,
V_318 , V_69 , V_11 , V_149 ) ) )
goto V_398;
V_10 += V_391 + V_75 ;
}
} else {
V_10 = V_68 ;
while ( V_10 < log -> V_2 ) {
V_11 = F_12 ( V_389 ) ;
V_393 = 0 ;
V_394 = 0 ;
if ( V_10 + V_75 <= log -> V_2 ) {
error = F_24 ( log , V_10 , V_75 , V_389 ,
& V_11 ) ;
if ( error )
goto V_398;
} else {
if ( V_10 != log -> V_2 ) {
ASSERT ( V_10 <= V_66 ) ;
V_393 = log -> V_2 - ( int ) V_10 ;
ASSERT ( V_393 > 0 ) ;
error = F_24 ( log , V_10 ,
V_393 , V_389 ,
& V_11 ) ;
if ( error )
goto V_398;
}
V_394 = V_75 - V_393 ;
error = F_25 ( log , 0 ,
V_394 , V_389 ,
V_11 + F_7 ( V_393 ) ) ;
if ( error )
goto V_398;
}
V_69 = ( T_6 * ) V_11 ;
error = F_208 ( log , V_69 ,
V_393 ? V_10 : 0 ) ;
if ( error )
goto V_398;
V_391 = ( int ) F_54 ( F_34 ( V_69 -> V_57 ) ) ;
V_10 += V_75 ;
if ( V_10 + V_391 <= log -> V_2 ) {
error = F_24 ( log , V_10 , V_391 , V_390 ,
& V_11 ) ;
if ( error )
goto V_398;
} else {
V_11 = F_12 ( V_390 ) ;
V_392 = 0 ;
if ( V_10 != log -> V_2 ) {
ASSERT ( ! V_394 ) ;
ASSERT ( V_10 <= V_66 ) ;
V_392 =
log -> V_2 - ( int ) V_10 ;
ASSERT ( V_392 > 0 ) ;
error = F_24 ( log , V_10 ,
V_392 , V_390 ,
& V_11 ) ;
if ( error )
goto V_398;
}
error = F_25 ( log , 0 ,
V_391 - V_392 , V_389 ,
V_11 + F_7 ( V_392 ) ) ;
if ( error )
goto V_398;
}
F_207 ( V_69 , V_11 , log ) ;
if ( ( error = F_174 ( log , V_318 ,
V_69 , V_11 , V_149 ) ) )
goto V_398;
V_10 += V_391 ;
}
ASSERT ( V_10 >= log -> V_2 ) ;
V_10 -= log -> V_2 ;
while ( V_10 < V_59 ) {
error = F_24 ( log , V_10 , V_75 , V_389 , & V_11 ) ;
if ( error )
goto V_398;
V_69 = ( T_6 * ) V_11 ;
error = F_208 ( log , V_69 , V_10 ) ;
if ( error )
goto V_398;
V_391 = ( int ) F_54 ( F_34 ( V_69 -> V_57 ) ) ;
error = F_24 ( log , V_10 + V_75 , V_391 , V_390 ,
& V_11 ) ;
if ( error )
goto V_398;
F_207 ( V_69 , V_11 , log ) ;
if ( ( error = F_174 ( log , V_318 ,
V_69 , V_11 , V_149 ) ) )
goto V_398;
V_10 += V_391 + V_75 ;
}
}
V_398:
F_8 ( V_390 ) ;
V_396:
F_8 ( V_389 ) ;
return error ;
}
STATIC int
F_210 (
T_1 * log ,
T_4 V_59 ,
T_4 V_68 )
{
int error , V_41 ;
ASSERT ( V_59 != V_68 ) ;
log -> V_171 = F_78 ( V_399 *
sizeof( struct V_128 ) ,
V_124 ) ;
for ( V_41 = 0 ; V_41 < V_399 ; V_41 ++ )
F_79 ( & log -> V_171 [ V_41 ] ) ;
error = F_209 ( log , V_59 , V_68 ,
V_316 ) ;
if ( error != 0 ) {
F_109 ( log -> V_171 ) ;
log -> V_171 = NULL ;
return error ;
}
error = F_209 ( log , V_59 , V_68 ,
V_317 ) ;
#ifdef F_192
if ( ! error ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_399 ; V_41 ++ )
ASSERT ( F_85 ( & log -> V_171 [ V_41 ] ) ) ;
}
#endif
F_109 ( log -> V_171 ) ;
log -> V_171 = NULL ;
return error ;
}
STATIC int
F_211 (
T_1 * log ,
T_4 V_59 ,
T_4 V_68 )
{
int error ;
T_2 * V_9 ;
T_36 * V_400 ;
error = F_210 ( log , V_59 , V_68 ) ;
if ( error ) {
return error ;
}
F_212 ( log -> V_4 -> V_228 ) ;
if ( F_213 ( log -> V_4 ) ) {
return ( V_54 ) ;
}
F_214 ( log -> V_4 ) ;
V_9 = F_215 ( log -> V_4 , 0 ) ;
F_216 ( V_9 ) ;
ASSERT ( ! ( F_217 ( V_9 ) ) ) ;
ASSERT ( ! ( F_218 ( V_9 ) ) ) ;
F_16 ( V_9 ) ;
F_219 ( V_9 ) ;
F_20 ( log -> V_4 , V_9 ) ;
error = F_21 ( V_9 ) ;
if ( error ) {
F_22 ( L_76 ,
log -> V_4 , V_9 , F_23 ( V_9 ) ) ;
ASSERT ( 0 ) ;
F_131 ( V_9 ) ;
return error ;
}
V_400 = & log -> V_4 -> V_21 ;
F_220 ( V_400 , F_221 ( V_9 ) ) ;
ASSERT ( V_400 -> V_401 == V_402 ) ;
ASSERT ( F_222 ( V_400 ) ) ;
F_131 ( V_9 ) ;
F_223 ( log -> V_4 ) ;
F_224 ( log ) ;
log -> V_403 &= ~ V_404 ;
return 0 ;
}
int
V_315 (
T_1 * log )
{
T_4 V_59 , V_68 ;
int error ;
if ( ( error = F_59 ( log , & V_59 , & V_68 ) ) )
return error ;
if ( V_68 != V_59 ) {
if ( ( error = F_225 ( log -> V_4 , L_77 ) ) ) {
return error ;
}
F_122 ( log -> V_4 , L_78 ,
log -> V_4 -> V_405 ? log -> V_4 -> V_405
: L_79 ) ;
error = F_211 ( log , V_59 , V_68 ) ;
log -> V_403 |= V_406 ;
}
return error ;
}
int
F_226 (
T_1 * log )
{
if ( log -> V_403 & V_406 ) {
int error ;
error = F_191 ( log ) ;
if ( error ) {
F_116 ( log -> V_4 , L_80 ) ;
return error ;
}
F_227 ( log -> V_4 , V_407 ) ;
F_203 ( log ) ;
F_224 ( log ) ;
F_122 ( log -> V_4 , L_81 ,
log -> V_4 -> V_405 ? log -> V_4 -> V_405
: L_79 ) ;
log -> V_403 &= ~ V_406 ;
} else {
F_228 ( log -> V_4 , L_82 ) ;
}
return 0 ;
}
void
F_224 (
T_1 * log )
{
T_5 * V_19 ;
T_37 * V_408 ;
T_2 * V_409 ;
T_2 * V_348 ;
T_31 V_346 ;
T_26 V_410 ;
T_26 V_411 ;
T_26 V_412 ;
int error ;
V_19 = log -> V_4 ;
V_410 = 0LL ;
V_411 = 0LL ;
V_412 = 0LL ;
for ( V_346 = 0 ; V_346 < V_19 -> V_21 . V_367 ; V_346 ++ ) {
error = F_229 ( V_19 , NULL , V_346 , 0 , & V_409 ) ;
if ( error ) {
F_116 ( V_19 , L_83 ,
V_5 , V_346 , error ) ;
} else {
V_408 = F_230 ( V_409 ) ;
V_410 += F_34 ( V_408 -> V_413 ) +
F_34 ( V_408 -> V_414 ) ;
F_131 ( V_409 ) ;
}
error = F_195 ( V_19 , NULL , V_346 , & V_348 ) ;
if ( error ) {
F_116 ( V_19 , L_84 ,
V_5 , V_346 , error ) ;
} else {
struct V_415 * V_347 = F_196 ( V_348 ) ;
V_411 += F_34 ( V_347 -> V_416 ) ;
V_412 += F_34 ( V_347 -> V_417 ) ;
F_131 ( V_348 ) ;
}
}
}
