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
F_20 ( V_5 , V_7 ) ;
return error ;
}
STATIC int
F_21 (
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
F_22 (
T_1 * log ,
T_4 V_11 ,
int V_3 ,
T_2 * V_5 ,
T_3 V_12 )
{
T_3 V_16 = V_5 -> V_13 ;
int V_17 = V_5 -> V_18 ;
int error , V_19 ;
error = F_23 ( V_5 , V_12 , F_7 ( V_3 ) ) ;
if ( error )
return error ;
error = F_13 ( log , V_11 , V_3 , V_5 ) ;
V_19 = F_23 ( V_5 , V_16 , V_17 ) ;
if ( error )
return error ;
return V_19 ;
}
STATIC int
F_24 (
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
F_25 ( V_5 ) ;
F_26 ( V_5 ) ;
F_27 ( V_5 ) ;
F_17 ( V_5 , F_7 ( V_3 ) ) ;
error = F_28 ( V_5 ) ;
if ( error )
F_20 ( V_5 , V_7 ) ;
F_29 ( V_5 ) ;
return error ;
}
STATIC void
F_30 (
T_5 * V_20 ,
T_6 * V_21 )
{
F_31 ( V_20 , L_2 ,
V_7 , & V_20 -> V_22 . V_23 , V_24 ) ;
F_31 ( V_20 , L_3 ,
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
L_4 ) ;
F_30 ( V_20 , V_21 ) ;
F_4 ( L_5 ,
V_8 , V_20 ) ;
return F_36 ( V_14 ) ;
} else if ( F_35 ( ! F_37 ( & V_20 -> V_22 . V_23 , & V_21 -> V_25 ) ) ) {
F_3 ( V_20 ,
L_6 ) ;
F_30 ( V_20 , V_21 ) ;
F_4 ( L_7 ,
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
F_3 ( V_20 , L_8 ) ;
} else if ( F_35 ( ! F_37 ( & V_20 -> V_22 . V_23 , & V_21 -> V_25 ) ) ) {
F_3 ( V_20 , L_9 ) ;
F_30 ( V_20 , V_21 ) ;
F_4 ( L_10 ,
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
F_20 ( V_5 , V_7 ) ;
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
error = F_21 ( log , V_37 , 1 , V_5 , & V_12 ) ;
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
error = F_21 ( log , V_43 , V_48 , V_5 , & V_46 ) ;
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
error = F_21 ( log , V_40 , V_53 , V_5 , & V_12 ) ;
if ( error )
goto V_49;
V_12 += ( ( V_53 - 1 ) << V_55 ) ;
}
for ( V_43 = ( * V_35 ) - 1 ; V_43 >= 0 ; V_43 -- ) {
if ( V_43 < V_40 ) {
F_3 ( log -> V_6 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = F_36 ( V_56 ) ;
goto V_49;
}
if ( V_52 ) {
error = F_21 ( log , V_43 , 1 , V_5 , & V_12 ) ;
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
F_3 ( log -> V_6 , L_12 ) ;
}
return 0 ;
} else if ( error ) {
F_3 ( log -> V_6 , L_13 ) ;
return error ;
}
V_34 = 0 ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_47 ;
error = F_21 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_63 = F_45 ( V_12 ) ;
V_35 = V_61 = V_66 - 1 ;
error = F_21 ( log , V_35 , 1 , V_5 , & V_12 ) ;
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
F_3 ( log -> V_6 , L_14 ) ;
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
error = F_21 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
if ( F_45 ( V_12 ) == 0 ) {
* V_70 = 0 ;
goto V_78;
}
}
ASSERT ( * V_61 < V_68 ) ;
for ( V_43 = ( int ) ( * V_61 ) - 1 ; V_43 >= 0 ; V_43 -- ) {
error = F_21 ( log , V_43 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
if ( * ( V_79 * ) V_12 == F_34 ( V_28 ) ) {
V_73 = 1 ;
break;
}
}
if ( ! V_73 ) {
for ( V_43 = log -> V_2 - 1 ; V_43 >= ( int ) ( * V_61 ) ; V_43 -- ) {
error = F_21 ( log , V_43 , 1 , V_5 , & V_12 ) ;
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
F_3 ( log -> V_6 , L_15 , V_7 ) ;
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
F_60 ( & log -> V_88 . V_89 , log -> V_83 ,
F_7 ( log -> V_82 ) ) ;
F_60 ( & log -> V_90 . V_89 , log -> V_83 ,
F_7 ( log -> V_82 ) ) ;
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
int V_57 = F_32 ( V_71 -> V_57 ) ;
int V_91 = F_32 ( V_71 -> V_91 ) ;
if ( ( V_91 & V_92 ) &&
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
F_32 ( V_71 -> V_93 ) == 1 ) {
V_74 = ( V_43 + V_77 ) % log -> V_2 ;
error = F_21 ( log , V_74 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_78;
V_72 = ( T_8 * ) V_12 ;
if ( V_72 -> V_94 & V_95 ) {
F_62 ( & log -> V_85 ,
log -> V_83 , V_75 ) ;
F_62 ( & log -> V_86 ,
log -> V_83 , V_75 ) ;
* V_70 = V_75 ;
log -> V_6 -> V_96 |= V_97 ;
}
}
if ( ! F_63 ( log -> V_6 -> V_10 ) )
error = F_64 ( log , V_76 ) ;
V_78:
F_9 ( V_5 ) ;
if ( error )
F_3 ( log -> V_6 , L_16 ) ;
return error ;
}
STATIC int
F_53 (
T_1 * log ,
T_4 * V_11 )
{
T_2 * V_5 ;
T_3 V_12 ;
T_7 V_98 , V_99 ;
T_4 V_42 , V_35 , V_40 ;
T_4 V_62 ;
int error , V_66 = log -> V_2 ;
* V_11 = 0 ;
V_5 = F_2 ( log , 1 ) ;
if ( ! V_5 )
return V_47 ;
error = F_21 ( log , 0 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_98 = F_45 ( V_12 ) ;
if ( V_98 == 0 ) {
* V_11 = 0 ;
F_9 ( V_5 ) ;
return - 1 ;
}
error = F_21 ( log , V_66 - 1 , 1 , V_5 , & V_12 ) ;
if ( error )
goto V_67;
V_99 = F_45 ( V_12 ) ;
if ( V_99 != 0 ) {
F_9 ( V_5 ) ;
return 0 ;
} else if ( V_98 != 1 ) {
F_3 ( log -> V_6 ,
L_17 ) ;
return F_36 ( V_100 ) ;
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
int V_101 ,
int V_102 ,
int V_103 )
{
T_6 * V_104 = ( T_6 * ) V_46 ;
memset ( V_46 , 0 , V_50 ) ;
V_104 -> V_27 = F_34 ( V_28 ) ;
V_104 -> V_84 = F_34 ( V_36 ) ;
V_104 -> V_91 = F_34 (
F_50 ( & log -> V_6 -> V_22 ) ? 2 : 1 ) ;
V_104 -> V_87 = F_66 ( F_67 ( V_36 , V_101 ) ) ;
V_104 -> V_80 = F_66 ( F_67 ( V_102 , V_103 ) ) ;
V_104 -> V_26 = F_34 ( V_24 ) ;
memcpy ( & V_104 -> V_25 , & log -> V_6 -> V_22 . V_23 , sizeof( V_105 ) ) ;
}
STATIC int
F_68 (
T_1 * log ,
int V_36 ,
int V_106 ,
int V_107 ,
int V_102 ,
int V_103 )
{
T_3 V_12 ;
T_2 * V_5 ;
int V_108 , V_109 ;
int V_110 = log -> V_9 ;
int V_111 = V_106 + V_107 ;
int V_45 ;
int error = 0 ;
int V_43 , V_44 = 0 ;
V_45 = 1 << F_47 ( V_107 ) ;
while ( ! ( V_5 = F_2 ( log , V_45 ) ) ) {
V_45 >>= 1 ;
if ( V_45 < V_110 )
return V_47 ;
}
V_108 = F_14 ( V_106 , V_110 ) ;
if ( V_108 != V_106 ) {
error = F_13 ( log , V_106 , 1 , V_5 ) ;
if ( error )
goto V_112;
V_44 = V_106 - V_108 ;
}
for ( V_43 = V_106 ; V_43 < V_111 ; V_43 += V_45 ) {
int V_48 , V_113 ;
V_48 = F_48 ( V_45 , V_111 - V_106 ) ;
V_113 = V_48 - V_44 ;
V_109 = F_14 ( V_111 , V_110 ) ;
if ( V_44 == 0 && ( V_106 + V_113 > V_109 ) ) {
V_12 = V_5 -> V_13 + F_7 ( V_109 - V_106 ) ;
error = F_22 ( log , V_109 , V_110 ,
V_5 , V_12 ) ;
if ( error )
break;
}
V_12 = F_11 ( log , V_106 , V_113 , V_5 ) ;
for (; V_44 < V_113 ; V_44 ++ ) {
F_65 ( log , V_12 , V_36 , V_43 + V_44 ,
V_102 , V_103 ) ;
V_12 += V_50 ;
}
error = F_24 ( log , V_106 , V_113 , V_5 ) ;
if ( error )
break;
V_106 += V_113 ;
V_44 = 0 ;
}
V_112:
F_9 ( V_5 ) ;
return error ;
}
STATIC int
F_64 (
T_1 * log ,
T_9 V_76 )
{
int V_102 , V_114 ;
int V_103 , V_115 ;
int V_116 , V_117 ;
int V_118 ;
int error ;
V_102 = F_69 ( V_76 ) ;
V_103 = F_57 ( V_76 ) ;
V_114 = log -> V_83 ;
V_115 = log -> V_82 ;
if ( V_114 == V_102 ) {
if ( F_35 ( V_115 < V_103 || V_115 >= log -> V_2 ) ) {
F_4 ( L_18 ,
V_119 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
V_116 = V_103 + ( log -> V_2 - V_115 ) ;
} else {
if ( F_35 ( V_115 >= V_103 || V_114 != ( V_102 + 1 ) ) ) {
F_4 ( L_19 ,
V_119 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
V_116 = V_103 - V_115 ;
}
if ( V_116 <= 0 ) {
ASSERT ( V_116 == 0 ) ;
return 0 ;
}
V_117 = F_54 ( log ) ;
V_117 = F_70 ( V_117 , V_116 ) ;
if ( ( V_115 + V_117 ) <= log -> V_2 ) {
error = F_68 ( log , ( V_114 - 1 ) ,
V_115 , V_117 , V_102 ,
V_103 ) ;
if ( error )
return error ;
} else {
V_118 = log -> V_2 - V_115 ;
error = F_68 ( log , ( V_114 - 1 ) ,
V_115 , V_118 , V_102 ,
V_103 ) ;
if ( error )
return error ;
V_118 = V_117 - ( log -> V_2 - V_115 ) ;
error = F_68 ( log , V_114 , 0 , V_118 ,
V_102 , V_103 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC T_10 *
F_71 (
struct V_120 * V_21 ,
T_11 V_121 )
{
T_10 * V_122 ;
struct V_123 * V_124 ;
F_72 (trans, n, head, r_list) {
if ( V_122 -> V_125 == V_121 )
return V_122 ;
}
return NULL ;
}
STATIC void
F_73 (
struct V_120 * V_21 ,
T_11 V_121 ,
T_9 V_126 )
{
T_10 * V_122 ;
V_122 = F_74 ( sizeof( T_10 ) , V_127 ) ;
V_122 -> V_125 = V_121 ;
V_122 -> V_128 = V_126 ;
F_75 ( & V_122 -> V_129 ) ;
F_76 ( & V_122 -> V_130 ) ;
F_77 ( & V_122 -> V_130 , V_21 ) ;
}
STATIC void
F_78 (
struct V_131 * V_21 )
{
T_12 * V_132 ;
V_132 = F_74 ( sizeof( T_12 ) , V_127 ) ;
F_75 ( & V_132 -> V_133 ) ;
F_79 ( & V_132 -> V_133 , V_21 ) ;
}
STATIC int
F_80 (
struct log * log ,
T_10 * V_122 ,
T_3 V_134 ,
int V_135 )
{
T_12 * V_132 ;
T_3 V_136 , V_137 ;
int V_138 ;
if ( F_81 ( & V_122 -> V_129 ) ) {
F_78 ( & V_122 -> V_129 ) ;
V_136 = ( T_3 ) & V_122 -> V_139 +
sizeof( V_140 ) - V_135 ;
memcpy ( V_136 , V_134 , V_135 ) ;
return 0 ;
}
V_132 = F_82 ( V_122 -> V_129 . V_141 , T_12 , V_133 ) ;
V_137 = V_132 -> V_142 [ V_132 -> V_143 - 1 ] . V_144 ;
V_138 = V_132 -> V_142 [ V_132 -> V_143 - 1 ] . V_145 ;
V_136 = F_83 ( V_137 , V_135 + V_138 , V_138 , V_127 ) ;
memcpy ( & V_136 [ V_138 ] , V_134 , V_135 ) ;
V_132 -> V_142 [ V_132 -> V_143 - 1 ] . V_145 += V_135 ;
V_132 -> V_142 [ V_132 -> V_143 - 1 ] . V_144 = V_136 ;
F_84 ( log , V_122 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_85 (
struct log * log ,
T_10 * V_122 ,
T_3 V_134 ,
int V_135 )
{
T_13 * V_146 ;
T_12 * V_132 ;
T_3 V_136 ;
if ( ! V_135 )
return 0 ;
if ( F_81 ( & V_122 -> V_129 ) ) {
if ( * ( T_7 * ) V_134 != V_147 ) {
F_3 ( log -> V_6 , L_20 ,
V_7 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
if ( V_135 == sizeof( V_140 ) )
F_78 ( & V_122 -> V_129 ) ;
memcpy ( & V_122 -> V_139 , V_134 , V_135 ) ;
return 0 ;
}
V_136 = F_86 ( V_135 , V_127 ) ;
memcpy ( V_136 , V_134 , V_135 ) ;
V_146 = ( T_13 * ) V_136 ;
V_132 = F_82 ( V_122 -> V_129 . V_141 , T_12 , V_133 ) ;
if ( V_132 -> V_148 != 0 &&
V_132 -> V_148 == V_132 -> V_143 ) {
F_78 ( & V_122 -> V_129 ) ;
V_132 = F_82 ( V_122 -> V_129 . V_141 ,
T_12 , V_133 ) ;
}
if ( V_132 -> V_148 == 0 ) {
if ( V_146 -> V_149 == 0 ||
V_146 -> V_149 > V_150 ) {
F_3 ( log -> V_6 ,
L_21 ,
V_146 -> V_149 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
V_132 -> V_148 = V_146 -> V_149 ;
V_132 -> V_142 =
F_74 ( V_132 -> V_148 * sizeof( V_151 ) ,
V_127 ) ;
}
ASSERT ( V_132 -> V_148 > V_132 -> V_143 ) ;
V_132 -> V_142 [ V_132 -> V_143 ] . V_144 = V_136 ;
V_132 -> V_142 [ V_132 -> V_143 ] . V_145 = V_135 ;
V_132 -> V_143 ++ ;
F_87 ( log , V_122 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_88 (
struct log * log ,
T_10 * V_122 ,
int V_152 )
{
T_12 * V_132 , * V_124 ;
F_89 ( V_153 ) ;
F_90 ( & V_122 -> V_129 , & V_153 ) ;
F_91 (item, n, &sort_list, ri_list) {
T_14 * V_154 = V_132 -> V_142 [ 0 ] . V_144 ;
switch ( F_92 ( V_132 ) ) {
case V_155 :
if ( ! ( V_154 -> V_156 & V_157 ) ) {
F_93 ( log ,
V_122 , V_132 , V_152 ) ;
F_94 ( & V_132 -> V_133 , & V_122 -> V_129 ) ;
break;
}
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
F_95 ( log ,
V_122 , V_132 , V_152 ) ;
F_96 ( & V_132 -> V_133 , & V_122 -> V_129 ) ;
break;
default:
F_3 ( log -> V_6 ,
L_22 ,
V_7 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
}
ASSERT ( F_81 ( & V_153 ) ) ;
return 0 ;
}
STATIC int
F_97 (
struct log * log ,
T_12 * V_132 )
{
T_14 * V_154 = V_132 -> V_142 [ 0 ] . V_144 ;
struct V_131 * V_163 ;
struct V_164 * V_165 ;
if ( ! ( V_154 -> V_156 & V_157 ) ) {
F_98 ( log , V_154 ) ;
return 0 ;
}
V_163 = F_99 ( log , V_154 -> V_166 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_165 -> V_167 == V_154 -> V_166 &&
V_165 -> V_168 == V_154 -> V_169 ) {
V_165 -> V_170 ++ ;
F_101 ( log , V_154 ) ;
return 0 ;
}
}
V_165 = F_86 ( sizeof( struct V_164 ) , V_127 ) ;
V_165 -> V_167 = V_154 -> V_166 ;
V_165 -> V_168 = V_154 -> V_169 ;
V_165 -> V_170 = 1 ;
F_79 ( & V_165 -> V_171 , V_163 ) ;
F_102 ( log , V_154 ) ;
return 0 ;
}
STATIC int
F_103 (
struct log * log ,
T_4 V_172 ,
T_7 V_135 ,
T_15 V_173 )
{
struct V_131 * V_163 ;
struct V_164 * V_165 ;
if ( log -> V_174 == NULL ) {
ASSERT ( ! ( V_173 & V_157 ) ) ;
return 0 ;
}
V_163 = F_99 ( log , V_172 ) ;
F_100 (bcp, bucket, bc_list) {
if ( V_165 -> V_167 == V_172 && V_165 -> V_168 == V_135 )
goto V_73;
}
ASSERT ( ! ( V_173 & V_157 ) ) ;
return 0 ;
V_73:
if ( V_173 & V_157 ) {
if ( -- V_165 -> V_170 == 0 ) {
F_104 ( & V_165 -> V_171 ) ;
F_105 ( V_165 ) ;
}
}
return 1 ;
}
STATIC int
F_106 (
struct V_175 * V_20 ,
T_12 * V_132 ,
struct V_4 * V_5 ,
T_14 * V_154 )
{
int V_43 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 = 0 ;
int V_180 = 0 ;
int V_181 ;
int V_182 ;
T_16 * V_183 ;
T_16 * V_184 ;
F_107 ( V_20 -> V_185 , V_154 ) ;
V_182 = F_108 ( V_5 ) >> V_20 -> V_22 . V_186 ;
for ( V_43 = 0 ; V_43 < V_182 ; V_43 ++ ) {
V_181 = ( V_43 * V_20 -> V_22 . V_187 ) +
F_109 ( V_188 , V_189 ) ;
while ( V_181 >=
( V_179 + V_180 ) ) {
V_177 += V_178 ;
V_177 = F_110 ( V_154 -> V_190 ,
V_154 -> V_191 , V_177 ) ;
if ( V_177 == - 1 )
return 0 ;
V_178 = F_111 ( V_154 -> V_190 ,
V_154 -> V_191 , V_177 ) ;
ASSERT ( V_178 > 0 ) ;
V_179 = V_177 << V_192 ;
V_180 = V_178 << V_192 ;
V_176 ++ ;
}
if ( V_181 < V_179 )
continue;
ASSERT ( V_132 -> V_142 [ V_176 ] . V_144 != NULL ) ;
ASSERT ( ( V_132 -> V_142 [ V_176 ] . V_145 % V_193 ) == 0 ) ;
ASSERT ( ( V_179 + V_180 ) <= F_108 ( V_5 ) ) ;
V_183 = V_132 -> V_142 [ V_176 ] . V_144 +
V_181 - V_179 ;
if ( F_35 ( * V_183 == 0 ) ) {
F_112 ( V_20 ,
L_23
L_24 ,
V_132 , V_5 ) ;
F_4 ( L_25 ,
V_119 , V_20 ) ;
return F_36 ( V_14 ) ;
}
V_184 = ( T_16 * ) F_113 ( V_5 ,
V_181 ) ;
* V_184 = * V_183 ;
}
return 0 ;
}
STATIC void
F_114 (
struct V_175 * V_20 ,
T_12 * V_132 ,
struct V_4 * V_5 ,
T_14 * V_154 )
{
int V_43 ;
int V_177 ;
int V_178 ;
int error ;
F_115 ( V_20 -> V_185 , V_154 ) ;
V_177 = 0 ;
V_43 = 1 ;
while ( 1 ) {
V_177 = F_110 ( V_154 -> V_190 ,
V_154 -> V_191 , V_177 ) ;
if ( V_177 == - 1 )
break;
V_178 = F_111 ( V_154 -> V_190 ,
V_154 -> V_191 , V_177 ) ;
ASSERT ( V_178 > 0 ) ;
ASSERT ( V_132 -> V_142 [ V_43 ] . V_144 != NULL ) ;
ASSERT ( V_132 -> V_142 [ V_43 ] . V_145 % V_193 == 0 ) ;
ASSERT ( F_108 ( V_5 ) >=
( ( T_7 ) V_177 << V_192 ) + ( V_178 << V_192 ) ) ;
error = 0 ;
if ( V_154 -> V_156 &
( V_194 | V_195 | V_196 ) ) {
if ( V_132 -> V_142 [ V_43 ] . V_144 == NULL ) {
F_112 ( V_20 ,
L_26 , V_7 ) ;
goto V_197;
}
if ( V_132 -> V_142 [ V_43 ] . V_145 < sizeof( V_198 ) ) {
F_112 ( V_20 ,
L_27 ,
V_132 -> V_142 [ V_43 ] . V_145 , V_7 ) ;
goto V_197;
}
error = F_116 ( V_20 , V_132 -> V_142 [ V_43 ] . V_144 ,
- 1 , 0 , V_199 ,
L_28 ) ;
if ( error )
goto V_197;
}
memcpy ( F_113 ( V_5 ,
( T_7 ) V_177 << V_192 ) ,
V_132 -> V_142 [ V_43 ] . V_144 ,
V_178 << V_192 ) ;
V_197:
V_43 ++ ;
V_177 += V_178 ;
}
ASSERT ( V_43 == V_132 -> V_148 ) ;
}
int
F_116 (
struct V_175 * V_20 ,
V_198 * V_200 ,
T_17 V_201 ,
T_7 type ,
T_7 V_173 ,
char * V_202 )
{
T_18 * V_203 = ( T_18 * ) V_200 ;
int V_204 = 0 ;
if ( V_200 -> V_205 != F_117 ( V_206 ) ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_29 ,
V_202 , V_201 , F_118 ( V_200 -> V_205 ) , V_206 ) ;
V_204 ++ ;
}
if ( V_200 -> V_207 != V_208 ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_30 ,
V_202 , V_201 , V_200 -> V_207 , V_208 ) ;
V_204 ++ ;
}
if ( V_200 -> V_209 != V_210 &&
V_200 -> V_209 != V_211 &&
V_200 -> V_209 != V_212 ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_31 ,
V_202 , V_201 , V_200 -> V_209 ) ;
V_204 ++ ;
}
if ( V_201 != - 1 && V_201 != F_32 ( V_200 -> V_213 ) ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_32
L_33 ,
V_202 , V_200 , V_201 , F_32 ( V_200 -> V_213 ) ) ;
V_204 ++ ;
}
if ( ! V_204 && V_200 -> V_213 ) {
if ( V_200 -> V_214 &&
F_58 ( V_200 -> V_215 ) >
F_58 ( V_200 -> V_214 ) ) {
if ( ! V_200 -> V_216 ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_34 ,
V_202 , ( int ) F_32 ( V_200 -> V_213 ) , V_200 ) ;
V_204 ++ ;
}
}
if ( V_200 -> V_217 &&
F_58 ( V_200 -> V_218 ) >
F_58 ( V_200 -> V_217 ) ) {
if ( ! V_200 -> V_219 ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_35 ,
V_202 , ( int ) F_32 ( V_200 -> V_213 ) , V_200 ) ;
V_204 ++ ;
}
}
if ( V_200 -> V_220 &&
F_58 ( V_200 -> V_221 ) >
F_58 ( V_200 -> V_220 ) ) {
if ( ! V_200 -> V_222 ) {
if ( V_173 & V_199 )
F_112 ( V_20 ,
L_36 ,
V_202 , ( int ) F_32 ( V_200 -> V_213 ) , V_200 ) ;
V_204 ++ ;
}
}
}
if ( ! V_204 || ! ( V_173 & V_223 ) )
return V_204 ;
if ( V_173 & V_199 )
F_119 ( V_20 , L_37 , V_201 ) ;
ASSERT ( V_201 != - 1 ) ;
ASSERT ( V_173 & V_223 ) ;
memset ( V_203 , 0 , sizeof( T_18 ) ) ;
V_203 -> V_224 . V_205 = F_117 ( V_206 ) ;
V_203 -> V_224 . V_207 = V_208 ;
V_203 -> V_224 . V_209 = type ;
V_203 -> V_224 . V_213 = F_34 ( V_201 ) ;
return V_204 ;
}
STATIC void
F_120 (
T_5 * V_20 ,
T_1 * log ,
T_12 * V_132 ,
T_2 * V_5 ,
T_14 * V_154 )
{
T_7 type ;
F_121 ( log , V_154 ) ;
if ( V_20 -> V_225 == 0 ) {
return;
}
type = 0 ;
if ( V_154 -> V_156 & V_194 )
type |= V_210 ;
if ( V_154 -> V_156 & V_195 )
type |= V_211 ;
if ( V_154 -> V_156 & V_196 )
type |= V_212 ;
if ( log -> V_226 & type )
return;
F_114 ( V_20 , V_132 , V_5 , V_154 ) ;
}
STATIC int
F_122 (
T_1 * log ,
T_12 * V_132 )
{
T_14 * V_154 = V_132 -> V_142 [ 0 ] . V_144 ;
T_5 * V_20 = log -> V_6 ;
T_2 * V_5 ;
int error ;
T_7 V_227 ;
if ( F_103 ( log , V_154 -> V_166 ,
V_154 -> V_169 , V_154 -> V_156 ) ) {
F_123 ( log , V_154 ) ;
return 0 ;
}
F_124 ( log , V_154 ) ;
V_227 = V_228 ;
if ( ! ( V_154 -> V_156 & V_229 ) )
V_227 |= V_230 ;
V_5 = F_125 ( V_20 -> V_231 , V_154 -> V_166 , V_154 -> V_169 ,
V_227 ) ;
if ( ! V_5 )
return F_36 ( V_47 ) ;
error = V_5 -> V_29 ;
if ( error ) {
F_20 ( V_5 , L_38 ) ;
F_29 ( V_5 ) ;
return error ;
}
if ( V_154 -> V_156 & V_229 ) {
error = F_106 ( V_20 , V_132 , V_5 , V_154 ) ;
} else if ( V_154 -> V_156 &
( V_194 | V_195 | V_196 ) ) {
F_120 ( V_20 , log , V_132 , V_5 , V_154 ) ;
} else {
F_114 ( V_20 , V_132 , V_5 , V_154 ) ;
}
if ( error )
return F_36 ( error ) ;
if ( V_232 ==
F_118 ( * ( ( V_233 * ) F_113 ( V_5 , 0 ) ) ) &&
( F_108 ( V_5 ) != F_126 ( log -> V_6 -> V_22 . V_234 ,
( V_235 ) F_127 ( log -> V_6 ) ) ) ) {
F_128 ( V_5 ) ;
error = F_28 ( V_5 ) ;
} else {
ASSERT ( V_5 -> V_30 -> V_31 == V_20 ) ;
V_5 -> V_33 = F_40 ;
F_129 ( V_5 ) ;
}
F_29 ( V_5 ) ;
return error ;
}
STATIC int
F_130 (
T_1 * log ,
T_12 * V_132 )
{
T_13 * V_146 ;
T_5 * V_20 = log -> V_6 ;
T_2 * V_5 ;
V_188 * V_236 ;
int V_135 ;
T_3 V_237 ;
T_3 V_238 ;
int error ;
int V_239 ;
T_7 V_240 ;
T_19 * V_241 ;
int V_242 = 0 ;
if ( V_132 -> V_142 [ 0 ] . V_145 == sizeof( T_13 ) ) {
V_146 = V_132 -> V_142 [ 0 ] . V_144 ;
} else {
V_146 = F_86 ( sizeof( T_13 ) , V_127 ) ;
V_242 = 1 ;
error = F_131 ( & V_132 -> V_142 [ 0 ] , V_146 ) ;
if ( error )
goto error;
}
if ( F_103 ( log , V_146 -> V_243 ,
V_146 -> V_244 , 0 ) ) {
error = 0 ;
F_132 ( log , V_146 ) ;
goto error;
}
F_133 ( log , V_146 ) ;
V_5 = F_125 ( V_20 -> V_231 , V_146 -> V_243 , V_146 -> V_244 ,
V_228 ) ;
if ( ! V_5 ) {
error = V_47 ;
goto error;
}
error = V_5 -> V_29 ;
if ( error ) {
F_20 ( V_5 , L_39 ) ;
F_29 ( V_5 ) ;
goto error;
}
ASSERT ( V_146 -> V_245 & V_246 ) ;
V_236 = ( V_188 * ) F_113 ( V_5 , V_146 -> V_247 ) ;
if ( F_35 ( V_236 -> V_248 != F_117 ( V_232 ) ) ) {
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_40 ,
V_7 , V_236 , V_5 , V_146 -> V_249 ) ;
F_4 ( L_41 ,
V_119 , V_20 ) ;
error = V_14 ;
goto error;
}
V_241 = V_132 -> V_142 [ 1 ] . V_144 ;
if ( F_35 ( V_241 -> V_248 != V_232 ) ) {
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_42 ,
V_7 , V_132 , V_146 -> V_249 ) ;
F_4 ( L_43 ,
V_119 , V_20 ) ;
error = V_14 ;
goto error;
}
if ( V_241 -> V_250 < F_118 ( V_236 -> V_250 ) ) {
if ( F_118 ( V_236 -> V_250 ) == V_251 &&
V_241 -> V_250 < ( V_251 >> 1 ) ) {
} else {
F_29 ( V_5 ) ;
F_134 ( log , V_146 ) ;
error = 0 ;
goto error;
}
}
V_241 -> V_250 = 0 ;
if ( F_35 ( F_135 ( V_241 -> V_252 ) ) ) {
if ( ( V_241 -> V_253 != V_254 ) &&
( V_241 -> V_253 != V_255 ) ) {
F_136 ( L_44 ,
V_119 , V_20 , V_241 ) ;
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_45
L_46 ,
V_7 , V_132 , V_236 , V_5 , V_146 -> V_249 ) ;
error = V_14 ;
goto error;
}
} else if ( F_35 ( F_137 ( V_241 -> V_252 ) ) ) {
if ( ( V_241 -> V_253 != V_254 ) &&
( V_241 -> V_253 != V_255 ) &&
( V_241 -> V_253 != V_256 ) ) {
F_136 ( L_47 ,
V_119 , V_20 , V_241 ) ;
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_48
L_46 ,
V_7 , V_132 , V_236 , V_5 , V_146 -> V_249 ) ;
error = V_14 ;
goto error;
}
}
if ( F_35 ( V_241 -> V_257 + V_241 -> V_258 > V_241 -> V_259 ) ) {
F_136 ( L_49 ,
V_119 , V_20 , V_241 ) ;
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_50
L_51 ,
V_7 , V_132 , V_236 , V_5 , V_146 -> V_249 ,
V_241 -> V_257 + V_241 -> V_258 ,
V_241 -> V_259 ) ;
error = V_14 ;
goto error;
}
if ( F_35 ( V_241 -> V_260 > V_20 -> V_22 . V_187 ) ) {
F_136 ( L_52 ,
V_119 , V_20 , V_241 ) ;
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_50
L_53 , V_7 ,
V_132 , V_236 , V_5 , V_146 -> V_249 , V_241 -> V_260 ) ;
error = V_14 ;
goto error;
}
if ( F_35 ( V_132 -> V_142 [ 1 ] . V_145 > sizeof( struct V_261 ) ) ) {
F_136 ( L_54 ,
V_119 , V_20 , V_241 ) ;
F_29 ( V_5 ) ;
F_112 ( V_20 ,
L_55 ,
V_7 , V_132 -> V_142 [ 1 ] . V_145 , V_132 ) ;
error = V_14 ;
goto error;
}
F_138 ( V_236 , V_132 -> V_142 [ 1 ] . V_144 ) ;
if ( V_132 -> V_142 [ 1 ] . V_145 > sizeof( struct V_261 ) ) {
memcpy ( ( T_3 ) V_236 + sizeof( struct V_261 ) ,
V_132 -> V_142 [ 1 ] . V_144 + sizeof( struct V_261 ) ,
V_132 -> V_142 [ 1 ] . V_145 - sizeof( struct V_261 ) ) ;
}
V_240 = V_146 -> V_245 ;
switch ( V_240 & ( V_262 | V_263 ) ) {
case V_262 :
F_139 ( V_236 , V_146 -> V_264 . V_265 ) ;
break;
case V_263 :
memcpy ( F_140 ( V_236 ) ,
& V_146 -> V_264 . V_266 ,
sizeof( V_105 ) ) ;
break;
}
if ( V_146 -> V_149 == 2 )
goto V_267;
V_135 = V_132 -> V_142 [ 2 ] . V_145 ;
V_237 = V_132 -> V_142 [ 2 ] . V_144 ;
ASSERT ( V_146 -> V_149 <= 4 ) ;
ASSERT ( ( V_146 -> V_149 == 3 ) || ( V_240 & V_268 ) ) ;
ASSERT ( ! ( V_240 & V_269 ) ||
( V_135 == V_146 -> V_270 ) ) ;
switch ( V_240 & V_269 ) {
case V_271 :
case V_272 :
memcpy ( F_140 ( V_236 ) , V_237 , V_135 ) ;
break;
case V_273 :
F_141 ( V_20 , (struct V_274 * ) V_237 , V_135 ,
( V_275 * ) F_140 ( V_236 ) ,
F_142 ( V_236 , V_20 ) ) ;
break;
default:
ASSERT ( ( V_240 & V_269 ) == 0 ) ;
break;
}
if ( V_146 -> V_245 & V_268 ) {
if ( V_146 -> V_245 & V_269 ) {
V_239 = 3 ;
} else {
V_239 = 2 ;
}
V_135 = V_132 -> V_142 [ V_239 ] . V_145 ;
V_237 = V_132 -> V_142 [ V_239 ] . V_144 ;
ASSERT ( V_135 == V_146 -> V_276 ) ;
switch ( V_146 -> V_245 & V_268 ) {
case V_277 :
case V_278 :
V_238 = F_143 ( V_236 ) ;
ASSERT ( V_135 <= F_144 ( V_236 , V_20 ) ) ;
memcpy ( V_238 , V_237 , V_135 ) ;
break;
case V_279 :
V_238 = F_143 ( V_236 ) ;
F_141 ( V_20 , (struct V_274 * ) V_237 ,
V_135 , ( V_275 * ) V_238 ,
F_144 ( V_236 , V_20 ) ) ;
break;
default:
F_3 ( log -> V_6 , L_56 , V_7 ) ;
ASSERT ( 0 ) ;
F_29 ( V_5 ) ;
error = V_56 ;
goto error;
}
}
V_267:
ASSERT ( V_5 -> V_30 -> V_31 == V_20 ) ;
V_5 -> V_33 = F_40 ;
F_129 ( V_5 ) ;
F_29 ( V_5 ) ;
error:
if ( V_242 )
F_105 ( V_146 ) ;
return F_36 ( error ) ;
}
STATIC int
F_145 (
T_1 * log ,
T_12 * V_132 )
{
T_20 * V_280 = V_132 -> V_142 [ 0 ] . V_144 ;
ASSERT ( V_280 ) ;
if ( V_280 -> V_281 & V_282 )
log -> V_226 |= V_210 ;
if ( V_280 -> V_281 & V_283 )
log -> V_226 |= V_211 ;
if ( V_280 -> V_281 & V_284 )
log -> V_226 |= V_212 ;
return ( 0 ) ;
}
STATIC int
F_146 (
T_1 * log ,
T_12 * V_132 )
{
T_5 * V_20 = log -> V_6 ;
T_2 * V_5 ;
struct V_285 * V_200 , * V_286 ;
int error ;
T_21 * V_287 ;
T_7 type ;
if ( V_20 -> V_225 == 0 )
return ( 0 ) ;
V_286 = V_132 -> V_142 [ 1 ] . V_144 ;
if ( V_286 == NULL ) {
F_112 ( log -> V_6 , L_57 , V_7 ) ;
return F_36 ( V_56 ) ;
}
if ( V_132 -> V_142 [ 1 ] . V_145 < sizeof( V_198 ) ) {
F_112 ( log -> V_6 , L_58 ,
V_132 -> V_142 [ 1 ] . V_145 , V_7 ) ;
return F_36 ( V_56 ) ;
}
type = V_286 -> V_209 & ( V_210 | V_211 | V_212 ) ;
ASSERT ( type ) ;
if ( log -> V_226 & type )
return ( 0 ) ;
V_287 = V_132 -> V_142 [ 0 ] . V_144 ;
ASSERT ( V_287 ) ;
error = F_116 ( V_20 , V_286 , V_287 -> V_288 , 0 , V_199 ,
L_59 ) ;
if ( error )
return F_36 ( V_56 ) ;
ASSERT ( V_287 -> V_289 == 1 ) ;
error = F_147 ( V_20 , V_20 -> V_231 ,
V_287 -> V_290 ,
F_148 ( V_20 , V_287 -> V_289 ) ,
0 , & V_5 ) ;
if ( error ) {
F_20 ( V_5 , L_60 ) ;
return error ;
}
ASSERT ( V_5 ) ;
V_200 = ( V_198 * ) F_113 ( V_5 , V_287 -> V_291 ) ;
error = F_116 ( V_20 , V_200 , V_287 -> V_288 , 0 , V_199 ,
L_61 ) ;
if ( error ) {
F_29 ( V_5 ) ;
return F_36 ( V_56 ) ;
}
memcpy ( V_200 , V_286 , V_132 -> V_142 [ 1 ] . V_145 ) ;
ASSERT ( V_287 -> V_292 == 2 ) ;
ASSERT ( V_5 -> V_30 -> V_31 == V_20 ) ;
V_5 -> V_33 = F_40 ;
F_129 ( V_5 ) ;
F_29 ( V_5 ) ;
return ( 0 ) ;
}
STATIC int
F_149 (
T_1 * log ,
T_12 * V_132 ,
T_9 V_126 )
{
int error ;
T_5 * V_20 = log -> V_6 ;
T_22 * V_293 ;
T_23 * V_294 ;
V_294 = V_132 -> V_142 [ 0 ] . V_144 ;
V_293 = F_150 ( V_20 , V_294 -> V_295 ) ;
if ( ( error = F_151 ( & ( V_132 -> V_142 [ 0 ] ) ,
& ( V_293 -> V_296 ) ) ) ) {
F_152 ( V_293 ) ;
return error ;
}
F_153 ( & V_293 -> V_297 , V_294 -> V_295 ) ;
F_154 ( & log -> V_298 -> V_299 ) ;
F_155 ( log -> V_298 , & V_293 -> V_300 , V_126 ) ;
return 0 ;
}
STATIC int
F_156 (
T_1 * log ,
T_12 * V_132 )
{
T_24 * V_301 ;
T_22 * V_293 = NULL ;
T_25 * V_302 ;
T_26 V_303 ;
struct V_304 V_305 ;
struct V_306 * V_307 = log -> V_298 ;
V_301 = V_132 -> V_142 [ 0 ] . V_144 ;
ASSERT ( ( V_132 -> V_142 [ 0 ] . V_145 == ( sizeof( V_308 ) +
( ( V_301 -> V_309 - 1 ) * sizeof( V_310 ) ) ) ) ||
( V_132 -> V_142 [ 0 ] . V_145 == ( sizeof( V_311 ) +
( ( V_301 -> V_309 - 1 ) * sizeof( V_312 ) ) ) ) ) ;
V_303 = V_301 -> V_313 ;
F_154 ( & V_307 -> V_299 ) ;
V_302 = F_157 ( V_307 , & V_305 , 0 ) ;
while ( V_302 != NULL ) {
if ( V_302 -> V_314 == V_162 ) {
V_293 = ( T_22 * ) V_302 ;
if ( V_293 -> V_296 . V_303 == V_303 ) {
F_158 ( V_307 , V_302 ) ;
F_152 ( V_293 ) ;
F_154 ( & V_307 -> V_299 ) ;
break;
}
}
V_302 = F_159 ( V_307 , & V_305 ) ;
}
F_160 ( V_307 , & V_305 ) ;
F_161 ( & V_307 -> V_299 ) ;
return 0 ;
}
STATIC void
F_162 (
struct V_315 * V_122 )
{
T_12 * V_132 , * V_124 ;
int V_43 ;
F_91 (item, n, &trans->r_itemq, ri_list) {
F_104 ( & V_132 -> V_133 ) ;
for ( V_43 = 0 ; V_43 < V_132 -> V_143 ; V_43 ++ )
F_105 ( V_132 -> V_142 [ V_43 ] . V_144 ) ;
F_105 ( V_132 -> V_142 ) ;
F_105 ( V_132 ) ;
}
F_105 ( V_122 ) ;
}
STATIC int
F_163 (
struct log * log ,
struct V_315 * V_122 ,
T_12 * V_132 )
{
F_164 ( log , V_122 , V_132 , V_316 ) ;
switch ( F_92 ( V_132 ) ) {
case V_155 :
return F_97 ( log , V_132 ) ;
case V_160 :
return F_145 ( log , V_132 ) ;
case V_158 :
case V_162 :
case V_161 :
case V_159 :
return 0 ;
default:
F_3 ( log -> V_6 , L_62 ,
V_7 , F_92 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
}
STATIC int
F_165 (
struct log * log ,
struct V_315 * V_122 ,
T_12 * V_132 )
{
F_164 ( log , V_122 , V_132 , V_317 ) ;
switch ( F_92 ( V_132 ) ) {
case V_155 :
return F_122 ( log , V_132 ) ;
case V_158 :
return F_130 ( log , V_132 ) ;
case V_162 :
return F_149 ( log , V_132 , V_122 -> V_128 ) ;
case V_161 :
return F_156 ( log , V_132 ) ;
case V_159 :
return F_146 ( log , V_132 ) ;
case V_160 :
return 0 ;
default:
F_3 ( log -> V_6 , L_62 ,
V_7 , F_92 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_36 ( V_56 ) ;
}
}
STATIC int
F_166 (
struct log * log ,
struct V_315 * V_122 ,
int V_152 )
{
int error = 0 ;
T_12 * V_132 ;
F_167 ( & V_122 -> V_130 ) ;
error = F_88 ( log , V_122 , V_152 ) ;
if ( error )
return error ;
F_100 (item, &trans->r_itemq, ri_list) {
if ( V_152 == V_316 )
error = F_163 ( log , V_122 , V_132 ) ;
else
error = F_165 ( log , V_122 , V_132 ) ;
if ( error )
return error ;
}
F_162 ( V_122 ) ;
return 0 ;
}
STATIC int
F_168 (
struct log * log ,
T_10 * V_122 )
{
F_3 ( log -> V_6 , L_63 , V_7 ) ;
return 0 ;
}
STATIC int
F_169 (
T_1 * log ,
struct V_120 V_318 [] ,
T_6 * V_71 ,
T_3 V_134 ,
int V_152 )
{
T_3 V_319 ;
int V_320 ;
T_8 * V_321 ;
T_10 * V_122 ;
T_11 V_121 ;
int error ;
unsigned long V_322 ;
T_7 V_173 ;
V_319 = V_134 + F_32 ( V_71 -> V_59 ) ;
V_320 = F_32 ( V_71 -> V_93 ) ;
if ( F_33 ( log -> V_6 , V_71 ) )
return ( F_36 ( V_56 ) ) ;
while ( ( V_134 < V_319 ) && V_320 ) {
ASSERT ( V_134 + sizeof( T_8 ) <= V_319 ) ;
V_321 = ( T_8 * ) V_134 ;
V_134 += sizeof( T_8 ) ;
if ( V_321 -> V_323 != V_324 &&
V_321 -> V_323 != V_325 ) {
F_3 ( log -> V_6 , L_64 ,
V_7 , V_321 -> V_323 ) ;
ASSERT ( 0 ) ;
return ( F_36 ( V_56 ) ) ;
}
V_121 = F_32 ( V_321 -> V_326 ) ;
V_322 = F_170 ( V_121 ) ;
V_122 = F_71 ( & V_318 [ V_322 ] , V_121 ) ;
if ( V_122 == NULL ) {
if ( V_321 -> V_94 & V_327 )
F_73 ( & V_318 [ V_322 ] , V_121 ,
F_58 ( V_71 -> V_87 ) ) ;
} else {
if ( V_134 + F_32 ( V_321 -> V_328 ) > V_319 ) {
F_3 ( log -> V_6 , L_65 ,
V_7 , F_32 ( V_321 -> V_328 ) ) ;
F_171 ( 1 ) ;
return ( F_36 ( V_56 ) ) ;
}
V_173 = V_321 -> V_94 & ~ V_329 ;
if ( V_173 & V_330 )
V_173 &= ~ V_331 ;
switch ( V_173 ) {
case V_332 :
error = F_166 ( log ,
V_122 , V_152 ) ;
break;
case V_95 :
error = F_168 ( log , V_122 ) ;
break;
case V_330 :
error = F_80 ( log ,
V_122 , V_134 ,
F_32 ( V_321 -> V_328 ) ) ;
break;
case V_327 :
F_3 ( log -> V_6 , L_66 ,
V_7 ) ;
ASSERT ( 0 ) ;
error = F_36 ( V_56 ) ;
break;
case 0 :
case V_331 :
error = F_85 ( log , V_122 ,
V_134 , F_32 ( V_321 -> V_328 ) ) ;
break;
default:
F_3 ( log -> V_6 , L_67 ,
V_7 , V_173 ) ;
ASSERT ( 0 ) ;
error = F_36 ( V_56 ) ;
break;
}
if ( error )
return error ;
}
V_134 += F_32 ( V_321 -> V_328 ) ;
V_320 -- ;
}
return 0 ;
}
STATIC int
F_172 (
T_5 * V_20 ,
T_22 * V_293 )
{
T_27 * V_333 ;
T_28 * V_334 ;
int V_43 ;
int error = 0 ;
T_29 * V_335 ;
T_30 V_336 ;
ASSERT ( ! F_173 ( V_337 , & V_293 -> V_338 ) ) ;
for ( V_43 = 0 ; V_43 < V_293 -> V_296 . V_295 ; V_43 ++ ) {
V_335 = & ( V_293 -> V_296 . V_339 [ V_43 ] ) ;
V_336 = F_174 ( V_20 ,
F_175 ( V_20 , V_335 -> V_340 ) ) ;
if ( ( V_336 == 0 ) ||
( V_335 -> V_341 == 0 ) ||
( V_336 >= V_20 -> V_22 . V_342 ) ||
( V_335 -> V_341 >= V_20 -> V_22 . V_343 ) ) {
F_176 ( V_293 , V_293 -> V_296 . V_295 ) ;
return F_36 ( V_56 ) ;
}
}
V_334 = F_177 ( V_20 , 0 ) ;
error = F_178 ( V_334 , 0 , F_179 ( V_20 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_344;
V_333 = F_180 ( V_334 , V_293 , V_293 -> V_296 . V_295 ) ;
for ( V_43 = 0 ; V_43 < V_293 -> V_296 . V_295 ; V_43 ++ ) {
V_335 = & ( V_293 -> V_296 . V_339 [ V_43 ] ) ;
error = F_181 ( V_334 , V_335 -> V_340 , V_335 -> V_341 ) ;
if ( error )
goto V_344;
F_182 ( V_334 , V_333 , V_335 -> V_340 ,
V_335 -> V_341 ) ;
}
F_183 ( V_337 , & V_293 -> V_338 ) ;
error = F_184 ( V_334 , 0 ) ;
return error ;
V_344:
F_185 ( V_334 , V_345 ) ;
return error ;
}
STATIC int
F_186 (
T_1 * log )
{
T_25 * V_302 ;
T_22 * V_293 ;
int error = 0 ;
struct V_304 V_305 ;
struct V_306 * V_307 ;
V_307 = log -> V_298 ;
F_154 ( & V_307 -> V_299 ) ;
V_302 = F_157 ( V_307 , & V_305 , 0 ) ;
while ( V_302 != NULL ) {
if ( V_302 -> V_314 != V_162 ) {
#ifdef F_187
for (; V_302 ; V_302 = F_159 ( V_307 , & V_305 ) )
ASSERT ( V_302 -> V_314 != V_162 ) ;
#endif
break;
}
V_293 = ( T_22 * ) V_302 ;
if ( F_173 ( V_337 , & V_293 -> V_338 ) ) {
V_302 = F_159 ( V_307 , & V_305 ) ;
continue;
}
F_161 ( & V_307 -> V_299 ) ;
error = F_172 ( log -> V_6 , V_293 ) ;
F_154 ( & V_307 -> V_299 ) ;
if ( error )
goto V_49;
V_302 = F_159 ( V_307 , & V_305 ) ;
}
V_49:
F_160 ( V_307 , & V_305 ) ;
F_161 ( & V_307 -> V_299 ) ;
return error ;
}
STATIC void
F_188 (
T_5 * V_20 ,
T_31 V_346 ,
int V_163 )
{
T_28 * V_334 ;
T_32 * V_347 ;
T_2 * V_348 ;
int V_12 ;
int error ;
V_334 = F_177 ( V_20 , V_349 ) ;
error = F_178 ( V_334 , 0 , F_189 ( V_20 ) ,
0 , 0 , 0 ) ;
if ( error )
goto V_350;
error = F_190 ( V_20 , V_334 , V_346 , & V_348 ) ;
if ( error )
goto V_350;
V_347 = F_191 ( V_348 ) ;
V_347 -> V_351 [ V_163 ] = F_34 ( V_352 ) ;
V_12 = F_109 ( T_32 , V_351 ) +
( sizeof( T_16 ) * V_163 ) ;
F_192 ( V_334 , V_348 , V_12 ,
( V_12 + sizeof( T_16 ) - 1 ) ) ;
error = F_184 ( V_334 , 0 ) ;
if ( error )
goto V_353;
return;
V_350:
F_185 ( V_334 , V_345 ) ;
V_353:
F_3 ( V_20 , L_68 , V_7 , V_346 ) ;
return;
}
STATIC T_16
F_193 (
struct V_175 * V_20 ,
T_31 V_346 ,
T_16 V_354 ,
int V_163 )
{
struct V_4 * V_355 ;
struct V_356 * V_236 ;
struct V_357 * V_358 ;
T_33 V_359 ;
int error ;
V_359 = F_194 ( V_20 , V_346 , V_354 ) ;
error = F_195 ( V_20 , NULL , V_359 , 0 , 0 , & V_358 ) ;
if ( error )
goto V_360;
error = F_196 ( V_20 , NULL , V_358 , & V_236 , & V_355 , V_228 ) ;
if ( error )
goto V_361;
ASSERT ( V_358 -> V_362 . V_363 == 0 ) ;
ASSERT ( V_358 -> V_362 . V_252 != 0 ) ;
V_354 = F_32 ( V_236 -> V_189 ) ;
F_29 ( V_355 ) ;
V_358 -> V_362 . V_364 = 0 ;
F_197 ( V_358 ) ;
return V_354 ;
V_361:
F_197 ( V_358 ) ;
V_360:
F_188 ( V_20 , V_346 , V_163 ) ;
return V_352 ;
}
STATIC void
F_198 (
T_1 * log )
{
T_5 * V_20 ;
T_31 V_346 ;
T_32 * V_347 ;
T_2 * V_348 ;
T_16 V_354 ;
int V_163 ;
int error ;
T_7 V_365 ;
V_20 = log -> V_6 ;
V_365 = V_20 -> V_366 ;
V_20 -> V_366 = 0 ;
for ( V_346 = 0 ; V_346 < V_20 -> V_22 . V_367 ; V_346 ++ ) {
error = F_190 ( V_20 , NULL , V_346 , & V_348 ) ;
if ( error ) {
continue;
}
V_347 = F_191 ( V_348 ) ;
F_8 ( V_348 ) ;
for ( V_163 = 0 ; V_163 < V_368 ; V_163 ++ ) {
V_354 = F_32 ( V_347 -> V_351 [ V_163 ] ) ;
while ( V_354 != V_352 ) {
V_354 = F_193 ( V_20 ,
V_346 , V_354 , V_163 ) ;
}
}
F_199 ( V_348 ) ;
}
V_20 -> V_366 = V_365 ;
}
STATIC void
F_200 (
T_1 * log ,
T_34 * V_369 ,
int V_370 )
{
int V_43 ;
V_79 * V_371 ;
T_7 V_372 = 0 ;
V_371 = ( V_79 * ) V_369 -> V_373 ;
for ( V_43 = 0 ; V_43 < ( V_370 >> 2 ) ; V_43 ++ ) {
V_372 ^= F_32 ( * V_371 ) ;
V_371 ++ ;
}
V_369 -> V_374 . V_375 = F_34 ( V_372 ) ;
}
void
F_201 (
T_1 * log ,
T_34 * V_369 ,
int V_376 )
{
int V_43 , V_44 , V_377 ;
int V_370 = V_369 -> V_378 + V_376 ;
V_79 V_379 ;
T_3 V_134 ;
F_200 ( log , V_369 , V_370 ) ;
V_379 = F_202 ( V_369 -> V_374 . V_87 ) ;
V_134 = V_369 -> V_373 ;
for ( V_43 = 0 ; V_43 < F_51 ( V_370 ) &&
V_43 < ( V_58 / V_50 ) ; V_43 ++ ) {
V_369 -> V_374 . V_380 [ V_43 ] = * ( V_79 * ) V_134 ;
* ( V_79 * ) V_134 = V_379 ;
V_134 += V_50 ;
}
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
T_35 * V_381 = V_369 -> V_382 ;
for ( ; V_43 < F_51 ( V_370 ) ; V_43 ++ ) {
V_44 = V_43 / ( V_58 / V_50 ) ;
V_377 = V_43 % ( V_58 / V_50 ) ;
V_381 [ V_44 ] . V_383 . V_384 [ V_377 ] = * ( V_79 * ) V_134 ;
* ( V_79 * ) V_134 = V_379 ;
V_134 += V_50 ;
}
for ( V_43 = 1 ; V_43 < log -> V_385 ; V_43 ++ ) {
V_381 [ V_43 ] . V_383 . V_386 = V_379 ;
}
}
}
STATIC void
F_203 (
T_6 * V_71 ,
T_3 V_134 ,
T_1 * log )
{
int V_43 , V_44 , V_377 ;
for ( V_43 = 0 ; V_43 < F_51 ( F_32 ( V_71 -> V_59 ) ) &&
V_43 < ( V_58 / V_50 ) ; V_43 ++ ) {
* ( V_79 * ) V_134 = * ( V_79 * ) & V_71 -> V_380 [ V_43 ] ;
V_134 += V_50 ;
}
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
T_35 * V_381 = ( T_35 * ) V_71 ;
for ( ; V_43 < F_51 ( F_32 ( V_71 -> V_59 ) ) ; V_43 ++ ) {
V_44 = V_43 / ( V_58 / V_50 ) ;
V_377 = V_43 % ( V_58 / V_50 ) ;
* ( V_79 * ) V_134 = V_381 [ V_44 ] . V_383 . V_384 [ V_377 ] ;
V_134 += V_50 ;
}
}
}
STATIC int
F_204 (
T_1 * log ,
T_6 * V_71 ,
T_4 V_172 )
{
int V_387 ;
if ( F_35 ( V_71 -> V_27 != F_34 ( V_28 ) ) ) {
F_4 ( L_69 ,
V_119 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
if ( F_35 (
( ! V_71 -> V_91 ||
( F_32 ( V_71 -> V_91 ) & ( ~ V_388 ) ) ) ) ) {
F_3 ( log -> V_6 , L_70 ,
V_7 , F_32 ( V_71 -> V_91 ) ) ;
return F_36 ( V_56 ) ;
}
V_387 = F_32 ( V_71 -> V_59 ) ;
if ( F_35 ( V_387 <= 0 || V_387 > V_68 ) ) {
F_4 ( L_71 ,
V_119 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
if ( F_35 ( V_172 > log -> V_2 || V_172 > V_68 ) ) {
F_4 ( L_72 ,
V_119 , log -> V_6 ) ;
return F_36 ( V_14 ) ;
}
return 0 ;
}
STATIC int
F_205 (
T_1 * log ,
T_4 V_61 ,
T_4 V_70 ,
int V_152 )
{
T_6 * V_71 ;
T_4 V_11 ;
T_3 V_12 ;
T_2 * V_389 , * V_390 ;
int error = 0 , V_57 ;
int V_391 , V_392 ;
int V_77 , V_393 , V_394 ;
struct V_120 V_318 [ V_395 ] ;
ASSERT ( V_61 != V_70 ) ;
if ( F_50 ( & log -> V_6 -> V_22 ) ) {
V_389 = F_2 ( log , 1 ) ;
if ( ! V_389 )
return V_47 ;
error = F_21 ( log , V_70 , 1 , V_389 , & V_12 ) ;
if ( error )
goto V_396;
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 , V_70 ) ;
if ( error )
goto V_396;
V_57 = F_32 ( V_71 -> V_57 ) ;
if ( ( F_32 ( V_71 -> V_91 ) & V_92 ) &&
( V_57 > V_58 ) ) {
V_77 = V_57 / V_58 ;
if ( V_57 % V_58 )
V_77 ++ ;
F_9 ( V_389 ) ;
V_389 = F_2 ( log , V_77 ) ;
} else {
V_77 = 1 ;
}
} else {
ASSERT ( log -> V_9 == 1 ) ;
V_77 = 1 ;
V_389 = F_2 ( log , 1 ) ;
V_57 = V_397 ;
}
if ( ! V_389 )
return V_47 ;
V_390 = F_2 ( log , F_51 ( V_57 ) ) ;
if ( ! V_390 ) {
F_9 ( V_389 ) ;
return V_47 ;
}
memset ( V_318 , 0 , sizeof( V_318 ) ) ;
if ( V_70 <= V_61 ) {
for ( V_11 = V_70 ; V_11 < V_61 ; ) {
error = F_21 ( log , V_11 , V_77 , V_389 , & V_12 ) ;
if ( error )
goto V_398;
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 , V_11 ) ;
if ( error )
goto V_398;
V_391 = ( int ) F_51 ( F_32 ( V_71 -> V_59 ) ) ;
error = F_21 ( log , V_11 + V_77 , V_391 , V_390 ,
& V_12 ) ;
if ( error )
goto V_398;
F_203 ( V_71 , V_12 , log ) ;
if ( ( error = F_169 ( log ,
V_318 , V_71 , V_12 , V_152 ) ) )
goto V_398;
V_11 += V_391 + V_77 ;
}
} else {
V_11 = V_70 ;
while ( V_11 < log -> V_2 ) {
V_12 = V_389 -> V_13 ;
V_393 = 0 ;
V_394 = 0 ;
if ( V_11 + V_77 <= log -> V_2 ) {
error = F_21 ( log , V_11 , V_77 , V_389 ,
& V_12 ) ;
if ( error )
goto V_398;
} else {
if ( V_11 != log -> V_2 ) {
ASSERT ( V_11 <= V_68 ) ;
V_393 = log -> V_2 - ( int ) V_11 ;
ASSERT ( V_393 > 0 ) ;
error = F_21 ( log , V_11 ,
V_393 , V_389 ,
& V_12 ) ;
if ( error )
goto V_398;
}
V_394 = V_77 - V_393 ;
error = F_22 ( log , 0 ,
V_394 , V_389 ,
V_12 + F_7 ( V_393 ) ) ;
if ( error )
goto V_398;
}
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 ,
V_393 ? V_11 : 0 ) ;
if ( error )
goto V_398;
V_391 = ( int ) F_51 ( F_32 ( V_71 -> V_59 ) ) ;
V_11 += V_77 ;
if ( V_11 + V_391 <= log -> V_2 ) {
error = F_21 ( log , V_11 , V_391 , V_390 ,
& V_12 ) ;
if ( error )
goto V_398;
} else {
V_12 = V_390 -> V_13 ;
V_392 = 0 ;
if ( V_11 != log -> V_2 ) {
ASSERT ( ! V_394 ) ;
ASSERT ( V_11 <= V_68 ) ;
V_392 =
log -> V_2 - ( int ) V_11 ;
ASSERT ( V_392 > 0 ) ;
error = F_21 ( log , V_11 ,
V_392 , V_390 ,
& V_12 ) ;
if ( error )
goto V_398;
}
error = F_22 ( log , 0 ,
V_391 - V_392 , V_389 ,
V_12 + F_7 ( V_392 ) ) ;
if ( error )
goto V_398;
}
F_203 ( V_71 , V_12 , log ) ;
if ( ( error = F_169 ( log , V_318 ,
V_71 , V_12 , V_152 ) ) )
goto V_398;
V_11 += V_391 ;
}
ASSERT ( V_11 >= log -> V_2 ) ;
V_11 -= log -> V_2 ;
while ( V_11 < V_61 ) {
error = F_21 ( log , V_11 , V_77 , V_389 , & V_12 ) ;
if ( error )
goto V_398;
V_71 = ( T_6 * ) V_12 ;
error = F_204 ( log , V_71 , V_11 ) ;
if ( error )
goto V_398;
V_391 = ( int ) F_51 ( F_32 ( V_71 -> V_59 ) ) ;
error = F_21 ( log , V_11 + V_77 , V_391 , V_390 ,
& V_12 ) ;
if ( error )
goto V_398;
F_203 ( V_71 , V_12 , log ) ;
if ( ( error = F_169 ( log , V_318 ,
V_71 , V_12 , V_152 ) ) )
goto V_398;
V_11 += V_391 + V_77 ;
}
}
V_398:
F_9 ( V_390 ) ;
V_396:
F_9 ( V_389 ) ;
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
log -> V_174 = F_74 ( V_399 *
sizeof( struct V_131 ) ,
V_127 ) ;
for ( V_43 = 0 ; V_43 < V_399 ; V_43 ++ )
F_75 ( & log -> V_174 [ V_43 ] ) ;
error = F_205 ( log , V_61 , V_70 ,
V_316 ) ;
if ( error != 0 ) {
F_105 ( log -> V_174 ) ;
log -> V_174 = NULL ;
return error ;
}
error = F_205 ( log , V_61 , V_70 ,
V_317 ) ;
#ifdef F_187
if ( ! error ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_399 ; V_43 ++ )
ASSERT ( F_81 ( & log -> V_174 [ V_43 ] ) ) ;
}
#endif
F_105 ( log -> V_174 ) ;
log -> V_174 = NULL ;
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
T_36 * V_400 ;
error = F_206 ( log , V_61 , V_70 ) ;
if ( error ) {
return error ;
}
F_208 ( log -> V_6 -> V_231 , 1 ) ;
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
F_20 ( V_5 , V_7 ) ;
ASSERT ( 0 ) ;
F_29 ( V_5 ) ;
return error ;
}
V_400 = & log -> V_6 -> V_22 ;
F_216 ( log -> V_6 , F_217 ( V_5 ) ) ;
ASSERT ( V_400 -> V_401 == V_402 ) ;
ASSERT ( F_218 ( V_400 ) ) ;
F_29 ( V_5 ) ;
F_219 ( log -> V_6 ) ;
F_220 ( log ) ;
log -> V_403 &= ~ V_404 ;
return 0 ;
}
int
V_315 (
T_1 * log )
{
T_4 V_61 , V_70 ;
int error ;
if ( ( error = F_56 ( log , & V_61 , & V_70 ) ) )
return error ;
if ( V_70 != V_61 ) {
if ( ( error = F_221 ( log -> V_6 , L_73 ) ) ) {
return error ;
}
F_119 ( log -> V_6 , L_74 ,
log -> V_6 -> V_405 ? log -> V_6 -> V_405
: L_75 ) ;
error = F_207 ( log , V_61 , V_70 ) ;
log -> V_403 |= V_406 ;
}
return error ;
}
int
F_222 (
T_1 * log )
{
if ( log -> V_403 & V_406 ) {
int error ;
error = F_186 ( log ) ;
if ( error ) {
F_112 ( log -> V_6 , L_76 ) ;
return error ;
}
F_223 ( log -> V_6 , V_407 ) ;
F_198 ( log ) ;
F_220 ( log ) ;
F_119 ( log -> V_6 , L_77 ,
log -> V_6 -> V_405 ? log -> V_6 -> V_405
: L_75 ) ;
log -> V_403 &= ~ V_406 ;
} else {
F_224 ( log -> V_6 , L_78 ) ;
}
return 0 ;
}
void
F_220 (
T_1 * log )
{
T_5 * V_20 ;
T_37 * V_408 ;
T_2 * V_409 ;
T_2 * V_348 ;
T_31 V_346 ;
T_26 V_410 ;
T_26 V_411 ;
T_26 V_412 ;
int error ;
V_20 = log -> V_6 ;
V_410 = 0LL ;
V_411 = 0LL ;
V_412 = 0LL ;
for ( V_346 = 0 ; V_346 < V_20 -> V_22 . V_367 ; V_346 ++ ) {
error = F_225 ( V_20 , NULL , V_346 , 0 , & V_409 ) ;
if ( error ) {
F_112 ( V_20 , L_79 ,
V_7 , V_346 , error ) ;
} else {
V_408 = F_226 ( V_409 ) ;
V_410 += F_32 ( V_408 -> V_413 ) +
F_32 ( V_408 -> V_414 ) ;
F_29 ( V_409 ) ;
}
error = F_190 ( V_20 , NULL , V_346 , & V_348 ) ;
if ( error ) {
F_112 ( V_20 , L_80 ,
V_7 , V_346 , error ) ;
} else {
struct V_415 * V_347 = F_191 ( V_348 ) ;
V_411 += F_32 ( V_347 -> V_416 ) ;
V_412 += F_32 ( V_347 -> V_417 ) ;
F_29 ( V_348 ) ;
}
}
}
