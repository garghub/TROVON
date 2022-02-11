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
if ( F_16 ( log -> V_7 ) )
return F_17 ( V_20 ) ;
F_18 ( V_6 ) ;
error = F_19 ( V_6 ) ;
if ( error )
F_20 ( V_6 , V_8 ) ;
return error ;
}
STATIC int
F_21 (
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
F_22 (
struct V_1 * log ,
T_3 V_12 ,
int V_4 ,
struct V_5 * V_6 ,
T_2 V_13 )
{
T_2 V_21 = V_6 -> V_15 ;
int V_22 = F_11 ( V_6 -> V_14 ) ;
int error , V_23 ;
error = F_23 ( V_6 , V_13 , F_11 ( V_4 ) ) ;
if ( error )
return error ;
error = F_12 ( log , V_12 , V_4 , V_6 ) ;
V_23 = F_23 ( V_6 , V_21 , V_22 ) ;
if ( error )
return error ;
return V_23 ;
}
STATIC int
F_24 (
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
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
V_6 -> V_18 = V_4 ;
V_6 -> V_19 = 0 ;
error = F_28 ( V_6 ) ;
if ( error )
F_20 ( V_6 , V_8 ) ;
F_29 ( V_6 ) ;
return error ;
}
STATIC void
F_30 (
T_4 * V_24 ,
T_5 * V_25 )
{
F_31 ( V_24 , L_2 ,
V_8 , & V_24 -> V_26 . V_27 , V_28 ) ;
F_31 ( V_24 , L_3 ,
& V_25 -> V_29 , F_32 ( V_25 -> V_30 ) ) ;
}
STATIC int
F_33 (
T_4 * V_24 ,
T_5 * V_25 )
{
ASSERT ( V_25 -> V_31 == F_34 ( V_32 ) ) ;
if ( F_35 ( V_25 -> V_30 != F_34 ( V_28 ) ) ) {
F_3 ( V_24 ,
L_4 ) ;
F_30 ( V_24 , V_25 ) ;
F_4 ( L_5 ,
V_9 , V_24 ) ;
return F_17 ( V_16 ) ;
} else if ( F_35 ( ! F_36 ( & V_24 -> V_26 . V_27 , & V_25 -> V_29 ) ) ) {
F_3 ( V_24 ,
L_6 ) ;
F_30 ( V_24 , V_25 ) ;
F_4 ( L_7 ,
V_9 , V_24 ) ;
return F_17 ( V_16 ) ;
}
return 0 ;
}
STATIC int
F_37 (
T_4 * V_24 ,
T_5 * V_25 )
{
ASSERT ( V_25 -> V_31 == F_34 ( V_32 ) ) ;
if ( F_38 ( & V_25 -> V_29 ) ) {
F_3 ( V_24 , L_8 ) ;
} else if ( F_35 ( ! F_36 ( & V_24 -> V_26 . V_27 , & V_25 -> V_29 ) ) ) {
F_3 ( V_24 , L_9 ) ;
F_30 ( V_24 , V_25 ) ;
F_4 ( L_10 ,
V_9 , V_24 ) ;
return F_17 ( V_16 ) ;
}
return 0 ;
}
STATIC void
F_39 (
struct V_5 * V_6 )
{
if ( V_6 -> V_19 ) {
F_20 ( V_6 , V_8 ) ;
F_40 ( V_6 -> V_33 -> V_34 ,
V_35 ) ;
}
V_6 -> V_36 = NULL ;
F_41 ( V_6 , 0 ) ;
}
STATIC int
F_42 (
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
V_40 = F_43 ( V_37 , V_41 ) ;
while ( V_40 != V_37 && V_40 != V_41 ) {
error = F_21 ( log , V_40 , 1 , V_6 , & V_13 ) ;
if ( error )
return error ;
V_42 = F_44 ( V_13 ) ;
if ( V_42 == V_39 )
V_41 = V_40 ;
else
V_37 = V_40 ;
V_40 = F_43 ( V_37 , V_41 ) ;
}
ASSERT ( ( V_40 == V_37 && V_40 + 1 == V_41 ) ||
( V_40 == V_41 && V_40 - 1 == V_37 ) ) ;
* V_38 = V_41 ;
return 0 ;
}
STATIC int
F_45 (
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
V_48 = 1 << F_46 ( V_4 ) ;
while ( V_48 > log -> V_3 )
V_48 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_48 ) ) ) {
V_48 >>= 1 ;
if ( V_48 < log -> V_10 )
return V_50 ;
}
for ( V_46 = V_43 ; V_46 < V_43 + V_4 ; V_46 += V_48 ) {
int V_51 ;
V_51 = F_47 ( V_48 , ( V_43 + V_4 - V_46 ) ) ;
error = F_21 ( log , V_46 , V_51 , V_6 , & V_49 ) ;
if ( error )
goto V_52;
for ( V_47 = 0 ; V_47 < V_51 ; V_47 ++ ) {
V_39 = F_44 ( V_49 ) ;
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
F_48 (
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
return V_50 ;
V_55 = 1 ;
} else {
error = F_21 ( log , V_43 , V_56 , V_6 , & V_13 ) ;
if ( error )
goto V_52;
V_13 += ( ( V_56 - 1 ) << V_58 ) ;
}
for ( V_46 = ( * V_38 ) - 1 ; V_46 >= 0 ; V_46 -- ) {
if ( V_46 < V_43 ) {
F_3 ( log -> V_7 ,
L_11 ) ;
ASSERT ( 0 ) ;
error = F_17 ( V_20 ) ;
goto V_52;
}
if ( V_55 ) {
error = F_21 ( log , V_46 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_52;
}
V_25 = ( T_5 * ) V_13 ;
if ( V_25 -> V_31 == F_34 ( V_32 ) )
break;
if ( ! V_55 )
V_13 -= V_53 ;
}
if ( V_46 == - 1 ) {
error = - 1 ;
goto V_52;
}
if ( ( error = F_37 ( log -> V_7 , V_25 ) ) )
goto V_52;
if ( F_49 ( & log -> V_7 -> V_26 ) ) {
T_6 V_59 = F_32 ( V_25 -> V_59 ) ;
V_57 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_57 ++ ;
} else {
V_57 = 1 ;
}
if ( * V_38 - V_46 + V_54 !=
F_50 ( F_32 ( V_25 -> V_61 ) ) + V_57 )
* V_38 = V_46 ;
V_52:
F_8 ( V_6 ) ;
return error ;
}
STATIC int
F_51 (
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
if ( ( error = F_52 ( log , & V_37 ) ) == - 1 ) {
* V_62 = V_37 ;
if ( ! V_37 ) {
F_3 ( log -> V_7 , L_12 ) ;
}
return 0 ;
} else if ( error ) {
F_3 ( log -> V_7 , L_13 ) ;
return error ;
}
V_37 = 0 ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return V_50 ;
error = F_21 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_65 = F_44 ( V_13 ) ;
V_38 = V_63 = V_68 - 1 ;
error = F_21 ( log , V_38 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_66 = F_44 ( V_13 ) ;
ASSERT ( V_66 != 0 ) ;
if ( V_65 == V_66 ) {
V_63 = V_68 ;
V_67 = V_66 - 1 ;
} else {
V_67 = V_66 ;
if ( ( error = F_42 ( log , V_6 , V_37 ,
& V_63 , V_66 ) ) )
goto V_69;
}
V_64 = F_53 ( log ) ;
if ( V_63 >= V_64 ) {
V_43 = V_63 - V_64 ;
if ( ( error = F_45 ( log ,
V_43 , V_64 ,
V_67 , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 )
V_63 = V_45 ;
} else {
ASSERT ( V_63 <= V_70 &&
( T_3 ) V_64 >= V_63 ) ;
V_43 = V_68 - ( V_64 - V_63 ) ;
if ( ( error = F_45 ( log , V_43 ,
V_64 - ( int ) V_63 ,
( V_67 - 1 ) , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 ) {
V_63 = V_45 ;
goto V_71;
}
V_43 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_45 ( log ,
V_43 , ( int ) V_63 ,
V_67 , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 )
V_63 = V_45 ;
}
V_71:
V_64 = F_54 ( log ) ;
if ( V_63 >= V_64 ) {
V_43 = V_63 - V_64 ;
if ( ( error = F_48 ( log , V_43 ,
& V_63 , 0 ) ) == - 1 ) {
error = F_17 ( V_20 ) ;
goto V_69;
} else if ( error )
goto V_69;
} else {
V_43 = 0 ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_48 ( log , V_43 ,
& V_63 , 0 ) ) == - 1 ) {
V_43 = V_68 - ( V_64 - V_63 ) ;
V_45 = V_68 ;
ASSERT ( V_43 <= V_70 &&
( T_3 ) V_68 - V_43 >= 0 ) ;
ASSERT ( V_63 <= V_70 ) ;
if ( ( error = F_48 ( log ,
V_43 , & V_45 ,
( int ) V_63 ) ) == - 1 ) {
error = F_17 ( V_20 ) ;
goto V_69;
} else if ( error )
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
F_55 (
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
if ( ( error = F_51 ( log , V_63 ) ) )
return error ;
V_6 = F_2 ( log , 1 ) ;
if ( ! V_6 )
return V_50 ;
if ( * V_63 == 0 ) {
error = F_21 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( F_44 ( V_13 ) == 0 ) {
* V_72 = 0 ;
goto V_80;
}
}
ASSERT ( * V_63 < V_70 ) ;
for ( V_46 = ( int ) ( * V_63 ) - 1 ; V_46 >= 0 ; V_46 -- ) {
error = F_21 ( log , V_46 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( * ( V_81 * ) V_13 == F_34 ( V_32 ) ) {
V_75 = 1 ;
break;
}
}
if ( ! V_75 ) {
for ( V_46 = log -> V_3 - 1 ; V_46 >= ( int ) ( * V_63 ) ; V_46 -- ) {
error = F_21 ( log , V_46 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
if ( * ( V_81 * ) V_13 ==
F_34 ( V_32 ) ) {
V_75 = 2 ;
break;
}
}
}
if ( ! V_75 ) {
F_3 ( log -> V_7 , L_15 , V_8 ) ;
F_8 ( V_6 ) ;
ASSERT ( 0 ) ;
return F_17 ( V_20 ) ;
}
V_73 = ( T_5 * ) V_13 ;
* V_72 = F_56 ( F_57 ( V_73 -> V_82 ) ) ;
log -> V_83 = V_46 ;
log -> V_84 = ( int ) * V_63 ;
log -> V_85 = F_32 ( V_73 -> V_86 ) ;
if ( V_75 == 2 )
log -> V_85 ++ ;
F_58 ( & log -> V_87 , F_57 ( V_73 -> V_82 ) ) ;
F_58 ( & log -> V_88 , F_57 ( V_73 -> V_89 ) ) ;
F_59 ( & log -> V_90 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
F_59 ( & log -> V_92 . V_91 , log -> V_85 ,
F_11 ( log -> V_84 ) ) ;
if ( F_49 ( & log -> V_7 -> V_26 ) ) {
int V_59 = F_32 ( V_73 -> V_59 ) ;
int V_93 = F_32 ( V_73 -> V_93 ) ;
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
F_50 ( F_32 ( V_73 -> V_61 ) ) ) % log -> V_3 ;
V_78 = F_60 ( & log -> V_87 ) ;
if ( * V_63 == V_77 &&
F_32 ( V_73 -> V_95 ) == 1 ) {
V_76 = ( V_46 + V_79 ) % log -> V_3 ;
error = F_21 ( log , V_76 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_80;
V_74 = ( T_7 * ) V_13 ;
if ( V_74 -> V_96 & V_97 ) {
F_61 ( & log -> V_87 ,
log -> V_85 , V_77 ) ;
F_61 ( & log -> V_88 ,
log -> V_85 , V_77 ) ;
* V_72 = V_77 ;
log -> V_7 -> V_98 |= V_99 ;
}
}
if ( ! F_62 ( log -> V_7 -> V_11 ) )
error = F_63 ( log , V_78 ) ;
V_80:
F_8 ( V_6 ) ;
if ( error )
F_3 ( log -> V_7 , L_16 ) ;
return error ;
}
STATIC int
F_52 (
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
return V_50 ;
error = F_21 ( log , 0 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_100 = F_44 ( V_13 ) ;
if ( V_100 == 0 ) {
* V_12 = 0 ;
F_8 ( V_6 ) ;
return - 1 ;
}
error = F_21 ( log , V_68 - 1 , 1 , V_6 , & V_13 ) ;
if ( error )
goto V_69;
V_101 = F_44 ( V_13 ) ;
if ( V_101 != 0 ) {
F_8 ( V_6 ) ;
return 0 ;
} else if ( V_100 != 1 ) {
F_3 ( log -> V_7 ,
L_17 ) ;
error = F_17 ( V_102 ) ;
goto V_69;
}
V_38 = V_68 - 1 ;
if ( ( error = F_42 ( log , V_6 , 0 , & V_38 , 0 ) ) )
goto V_69;
V_64 = F_53 ( log ) ;
ASSERT ( V_64 <= V_70 ) ;
if ( V_38 < V_64 )
V_64 = V_38 ;
V_43 = V_38 - V_64 ;
if ( ( error = F_45 ( log , V_43 ,
( int ) V_64 , 0 , & V_45 ) ) )
goto V_69;
if ( V_45 != - 1 )
V_38 = V_45 ;
if ( ( error = F_48 ( log , V_43 ,
& V_38 , 0 ) ) == - 1 ) {
error = F_17 ( V_20 ) ;
goto V_69;
} else if ( error )
goto V_69;
* V_12 = V_38 ;
V_69:
F_8 ( V_6 ) ;
if ( error )
return error ;
return - 1 ;
}
STATIC void
F_64 (
struct V_1 * log ,
T_2 V_49 ,
int V_39 ,
int V_103 ,
int V_104 ,
int V_105 )
{
T_5 * V_106 = ( T_5 * ) V_49 ;
memset ( V_49 , 0 , V_53 ) ;
V_106 -> V_31 = F_34 ( V_32 ) ;
V_106 -> V_86 = F_34 ( V_39 ) ;
V_106 -> V_93 = F_34 (
F_49 ( & log -> V_7 -> V_26 ) ? 2 : 1 ) ;
V_106 -> V_89 = F_65 ( F_66 ( V_39 , V_103 ) ) ;
V_106 -> V_82 = F_65 ( F_66 ( V_104 , V_105 ) ) ;
V_106 -> V_30 = F_34 ( V_28 ) ;
memcpy ( & V_106 -> V_29 , & log -> V_7 -> V_26 . V_27 , sizeof( V_107 ) ) ;
}
STATIC int
F_67 (
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
V_48 = 1 << F_46 ( V_109 ) ;
while ( V_48 > log -> V_3 )
V_48 >>= 1 ;
while ( ! ( V_6 = F_2 ( log , V_48 ) ) ) {
V_48 >>= 1 ;
if ( V_48 < V_112 )
return V_50 ;
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
V_51 = F_47 ( V_48 , V_113 - V_108 ) ;
V_115 = V_51 - V_47 ;
V_111 = F_13 ( V_113 , V_112 ) ;
if ( V_47 == 0 && ( V_108 + V_115 > V_111 ) ) {
V_13 = V_6 -> V_15 + F_11 ( V_111 - V_108 ) ;
error = F_22 ( log , V_111 , V_112 ,
V_6 , V_13 ) ;
if ( error )
break;
}
V_13 = F_10 ( log , V_108 , V_115 , V_6 ) ;
for (; V_47 < V_115 ; V_47 ++ ) {
F_64 ( log , V_13 , V_39 , V_46 + V_47 ,
V_104 , V_105 ) ;
V_13 += V_53 ;
}
error = F_24 ( log , V_108 , V_115 , V_6 ) ;
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
F_63 (
struct V_1 * log ,
T_8 V_78 )
{
int V_104 , V_116 ;
int V_105 , V_117 ;
int V_118 , V_119 ;
int V_120 ;
int error ;
V_104 = F_68 ( V_78 ) ;
V_105 = F_56 ( V_78 ) ;
V_116 = log -> V_85 ;
V_117 = log -> V_84 ;
if ( V_116 == V_104 ) {
if ( F_35 ( V_117 < V_105 || V_117 >= log -> V_3 ) ) {
F_4 ( L_18 ,
V_121 , log -> V_7 ) ;
return F_17 ( V_16 ) ;
}
V_118 = V_105 + ( log -> V_3 - V_117 ) ;
} else {
if ( F_35 ( V_117 >= V_105 || V_116 != ( V_104 + 1 ) ) ) {
F_4 ( L_19 ,
V_121 , log -> V_7 ) ;
return F_17 ( V_16 ) ;
}
V_118 = V_105 - V_117 ;
}
if ( V_118 <= 0 ) {
ASSERT ( V_118 == 0 ) ;
return 0 ;
}
V_119 = F_53 ( log ) ;
V_119 = F_69 ( V_119 , V_118 ) ;
if ( ( V_117 + V_119 ) <= log -> V_3 ) {
error = F_67 ( log , ( V_116 - 1 ) ,
V_117 , V_119 , V_104 ,
V_105 ) ;
if ( error )
return error ;
} else {
V_120 = log -> V_3 - V_117 ;
error = F_67 ( log , ( V_116 - 1 ) ,
V_117 , V_120 , V_104 ,
V_105 ) ;
if ( error )
return error ;
V_120 = V_119 - ( log -> V_3 - V_117 ) ;
error = F_67 ( log , V_116 , 0 , V_120 ,
V_104 , V_105 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC T_9 *
F_70 (
struct V_122 * V_25 ,
T_10 V_123 )
{
T_9 * V_124 ;
F_71 (trans, head, r_list) {
if ( V_124 -> V_125 == V_123 )
return V_124 ;
}
return NULL ;
}
STATIC void
F_72 (
struct V_122 * V_25 ,
T_10 V_123 ,
T_8 V_126 )
{
T_9 * V_124 ;
V_124 = F_73 ( sizeof( T_9 ) , V_127 ) ;
V_124 -> V_125 = V_123 ;
V_124 -> V_128 = V_126 ;
F_74 ( & V_124 -> V_129 ) ;
F_75 ( & V_124 -> V_130 ) ;
F_76 ( & V_124 -> V_130 , V_25 ) ;
}
STATIC void
F_77 (
struct V_131 * V_25 )
{
T_11 * V_132 ;
V_132 = F_73 ( sizeof( T_11 ) , V_127 ) ;
F_74 ( & V_132 -> V_133 ) ;
F_78 ( & V_132 -> V_133 , V_25 ) ;
}
STATIC int
F_79 (
struct V_1 * log ,
struct V_134 * V_124 ,
T_2 V_135 ,
int V_136 )
{
T_11 * V_132 ;
T_2 V_137 , V_138 ;
int V_139 ;
if ( F_80 ( & V_124 -> V_129 ) ) {
F_77 ( & V_124 -> V_129 ) ;
V_137 = ( T_2 ) & V_124 -> V_140 +
sizeof( V_141 ) - V_136 ;
memcpy ( V_137 , V_135 , V_136 ) ;
return 0 ;
}
V_132 = F_81 ( V_124 -> V_129 . V_142 , T_11 , V_133 ) ;
V_138 = V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_145 ;
V_139 = V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_146 ;
V_137 = F_82 ( V_138 , V_136 + V_139 , V_139 , V_127 ) ;
memcpy ( & V_137 [ V_139 ] , V_135 , V_136 ) ;
V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_146 += V_136 ;
V_132 -> V_143 [ V_132 -> V_144 - 1 ] . V_145 = V_137 ;
F_83 ( log , V_124 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_84 (
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
if ( F_80 ( & V_124 -> V_129 ) ) {
if ( * ( T_6 * ) V_135 != V_148 ) {
F_3 ( log -> V_7 , L_20 ,
V_8 ) ;
ASSERT ( 0 ) ;
return F_17 ( V_20 ) ;
}
if ( V_136 == sizeof( V_141 ) )
F_77 ( & V_124 -> V_129 ) ;
memcpy ( & V_124 -> V_140 , V_135 , V_136 ) ;
return 0 ;
}
V_137 = F_85 ( V_136 , V_127 ) ;
memcpy ( V_137 , V_135 , V_136 ) ;
V_147 = ( T_12 * ) V_137 ;
V_132 = F_81 ( V_124 -> V_129 . V_142 , T_11 , V_133 ) ;
if ( V_132 -> V_149 != 0 &&
V_132 -> V_149 == V_132 -> V_144 ) {
F_77 ( & V_124 -> V_129 ) ;
V_132 = F_81 ( V_124 -> V_129 . V_142 ,
T_11 , V_133 ) ;
}
if ( V_132 -> V_149 == 0 ) {
if ( V_147 -> V_150 == 0 ||
V_147 -> V_150 > V_151 ) {
F_3 ( log -> V_7 ,
L_21 ,
V_147 -> V_150 ) ;
ASSERT ( 0 ) ;
F_86 ( V_137 ) ;
return F_17 ( V_20 ) ;
}
V_132 -> V_149 = V_147 -> V_150 ;
V_132 -> V_143 =
F_73 ( V_132 -> V_149 * sizeof( V_152 ) ,
V_127 ) ;
}
ASSERT ( V_132 -> V_149 > V_132 -> V_144 ) ;
V_132 -> V_143 [ V_132 -> V_144 ] . V_145 = V_137 ;
V_132 -> V_143 [ V_132 -> V_144 ] . V_146 = V_136 ;
V_132 -> V_144 ++ ;
F_87 ( log , V_124 , V_132 , 0 ) ;
return 0 ;
}
STATIC int
F_88 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
T_11 * V_132 , * V_154 ;
F_89 ( V_155 ) ;
F_89 ( V_156 ) ;
F_89 ( V_157 ) ;
F_89 ( V_158 ) ;
F_89 ( V_159 ) ;
F_90 ( & V_124 -> V_129 , & V_155 ) ;
F_91 (item, n, &sort_list, ri_list) {
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
switch ( F_92 ( V_132 ) ) {
case V_161 :
F_93 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_162 :
if ( V_160 -> V_163 & V_164 ) {
F_94 ( log ,
V_124 , V_132 , V_153 ) ;
F_95 ( & V_132 -> V_133 , & V_156 ) ;
break;
}
if ( V_160 -> V_163 & V_165 ) {
F_95 ( & V_132 -> V_133 , & V_158 ) ;
break;
}
F_93 ( & V_132 -> V_133 , & V_157 ) ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
F_96 ( log ,
V_124 , V_132 , V_153 ) ;
F_93 ( & V_132 -> V_133 , & V_159 ) ;
break;
default:
F_3 ( log -> V_7 ,
L_22 ,
V_8 ) ;
ASSERT ( 0 ) ;
return F_17 ( V_20 ) ;
}
}
ASSERT ( F_80 ( & V_155 ) ) ;
if ( ! F_80 ( & V_157 ) )
F_97 ( & V_157 , & V_124 -> V_129 ) ;
if ( ! F_80 ( & V_159 ) )
F_98 ( & V_159 , & V_124 -> V_129 ) ;
if ( ! F_80 ( & V_158 ) )
F_98 ( & V_158 , & V_124 -> V_129 ) ;
if ( ! F_80 ( & V_156 ) )
F_98 ( & V_156 , & V_124 -> V_129 ) ;
return 0 ;
}
STATIC int
F_99 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_131 * V_172 ;
struct V_173 * V_174 ;
if ( ! ( V_160 -> V_163 & V_164 ) ) {
F_100 ( log , V_160 ) ;
return 0 ;
}
V_172 = F_101 ( log , V_160 -> V_175 ) ;
F_102 (bcp, bucket, bc_list) {
if ( V_174 -> V_176 == V_160 -> V_175 &&
V_174 -> V_177 == V_160 -> V_178 ) {
V_174 -> V_179 ++ ;
F_103 ( log , V_160 ) ;
return 0 ;
}
}
V_174 = F_85 ( sizeof( struct V_173 ) , V_127 ) ;
V_174 -> V_176 = V_160 -> V_175 ;
V_174 -> V_177 = V_160 -> V_178 ;
V_174 -> V_179 = 1 ;
F_78 ( & V_174 -> V_180 , V_172 ) ;
F_104 ( log , V_160 ) ;
return 0 ;
}
STATIC struct V_173 *
F_105 (
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
V_172 = F_101 ( log , V_181 ) ;
F_102 (bcp, bucket, bc_list) {
if ( V_174 -> V_176 == V_181 && V_174 -> V_177 == V_136 )
return V_174 ;
}
ASSERT ( ! ( V_182 & V_164 ) ) ;
return NULL ;
}
STATIC int
F_106 (
struct V_1 * log ,
T_3 V_181 ,
T_6 V_136 ,
T_14 V_182 )
{
struct V_173 * V_174 ;
V_174 = F_105 ( log , V_181 , V_136 , V_182 ) ;
if ( ! V_174 )
return 0 ;
if ( V_182 & V_164 ) {
if ( -- V_174 -> V_179 == 0 ) {
F_107 ( & V_174 -> V_180 ) ;
F_86 ( V_174 ) ;
}
}
return 1 ;
}
STATIC int
F_108 (
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
F_109 ( V_24 -> V_194 , V_160 ) ;
if ( F_110 ( & V_24 -> V_26 ) )
V_6 -> V_195 = & V_196 ;
V_191 = F_11 ( V_6 -> V_18 ) >> V_24 -> V_26 . V_197 ;
for ( V_46 = 0 ; V_46 < V_191 ; V_46 ++ ) {
V_190 = ( V_46 * V_24 -> V_26 . V_198 ) +
F_111 ( V_199 , V_200 ) ;
while ( V_190 >=
( V_188 + V_189 ) ) {
V_186 += V_187 ;
V_186 = F_112 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
return 0 ;
V_187 = F_113 ( V_160 -> V_201 ,
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
if ( F_35 ( * V_192 == 0 ) ) {
F_114 ( V_24 ,
L_23
L_24 ,
V_132 , V_6 ) ;
F_4 ( L_25 ,
V_121 , V_24 ) ;
return F_17 ( V_16 ) ;
}
V_193 = ( T_15 * ) F_115 ( V_6 ,
V_190 ) ;
* V_193 = * V_192 ;
F_116 ( V_24 , (struct V_205 * )
F_115 ( V_6 , V_46 * V_24 -> V_26 . V_198 ) ) ;
}
return 0 ;
}
static T_8
F_117 (
struct V_184 * V_24 ,
struct V_5 * V_6 )
{
T_16 V_206 ;
T_17 V_207 ;
T_17 V_208 ;
void * V_209 = V_6 -> V_15 ;
V_107 * V_210 ;
T_8 V_126 = - 1 ;
if ( ! F_110 ( & V_24 -> V_26 ) )
goto V_211;
V_206 = F_32 ( * ( V_81 * ) V_209 ) ;
switch ( V_206 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 : {
struct V_218 * V_219 = V_209 ;
V_126 = F_57 ( V_219 -> V_220 . V_221 . V_222 ) ;
V_210 = & V_219 -> V_220 . V_221 . V_223 ;
break;
}
case V_224 :
case V_225 : {
struct V_218 * V_219 = V_209 ;
V_126 = F_57 ( V_219 -> V_220 . V_226 . V_222 ) ;
V_210 = & V_219 -> V_220 . V_226 . V_223 ;
break;
}
case V_227 :
V_126 = F_57 ( ( (struct V_228 * ) V_209 ) -> V_229 ) ;
V_210 = & ( (struct V_228 * ) V_209 ) -> V_230 ;
break;
case V_231 :
V_126 = F_57 ( ( (struct V_232 * ) V_209 ) -> V_233 ) ;
V_210 = & ( (struct V_232 * ) V_209 ) -> V_234 ;
break;
case V_235 :
V_126 = F_57 ( ( (struct V_236 * ) V_209 ) -> V_237 ) ;
V_210 = & ( (struct V_236 * ) V_209 ) -> V_238 ;
break;
case V_239 :
V_126 = F_57 ( ( (struct V_240 * ) V_209 ) -> V_241 ) ;
V_210 = & ( (struct V_240 * ) V_209 ) -> V_242 ;
break;
case V_243 :
case V_244 :
case V_245 :
V_126 = F_57 ( ( (struct V_246 * ) V_209 ) -> V_126 ) ;
V_210 = & ( (struct V_246 * ) V_209 ) -> V_210 ;
break;
case V_247 :
V_126 = F_57 ( ( (struct V_248 * ) V_209 ) -> V_249 ) ;
V_210 = & ( (struct V_248 * ) V_209 ) -> V_250 ;
break;
case V_251 :
V_126 = F_57 ( ( (struct V_252 * ) V_209 ) -> V_253 ) ;
V_210 = & ( (struct V_252 * ) V_209 ) -> V_27 ;
break;
default:
break;
}
if ( V_126 != ( T_8 ) - 1 ) {
if ( ! F_36 ( & V_24 -> V_26 . V_27 , V_210 ) )
goto V_211;
return V_126 ;
}
V_208 = F_118 ( ( (struct V_254 * ) V_209 ) -> V_255 ) ;
switch ( V_208 ) {
case V_256 :
case V_257 :
case V_258 :
V_126 = F_57 ( ( (struct V_259 * ) V_209 ) -> V_126 ) ;
V_210 = & ( (struct V_259 * ) V_209 ) -> V_210 ;
break;
default:
break;
}
if ( V_126 != ( T_8 ) - 1 ) {
if ( ! F_36 ( & V_24 -> V_26 . V_27 , V_210 ) )
goto V_211;
return V_126 ;
}
V_207 = F_118 ( * ( V_260 * ) V_209 ) ;
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
F_119 (
struct V_184 * V_24 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
struct V_254 * V_263 = V_6 -> V_15 ;
T_16 V_206 ;
T_17 V_207 ;
T_17 V_208 ;
V_206 = F_32 ( * ( V_81 * ) V_6 -> V_15 ) ;
V_207 = F_118 ( * ( V_260 * ) V_6 -> V_15 ) ;
V_208 = F_118 ( V_263 -> V_255 ) ;
switch ( F_120 ( V_160 ) ) {
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
F_3 ( V_24 , L_26 ) ;
ASSERT ( 0 ) ;
break;
}
break;
case V_268 :
if ( V_206 != V_227 ) {
F_3 ( V_24 , L_27 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_269 ;
break;
case V_270 :
if ( ! F_110 ( & V_24 -> V_26 ) )
break;
if ( V_206 != V_231 ) {
F_3 ( V_24 , L_28 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_271 ;
break;
case V_272 :
if ( V_206 != V_235 ) {
F_3 ( V_24 , L_29 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_273 ;
break;
case V_274 :
case V_275 :
case V_276 :
#ifdef F_121
if ( V_207 != V_261 ) {
F_3 ( V_24 , L_30 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_277 ;
#else
F_114 ( V_24 ,
L_31 ) ;
ASSERT ( 0 ) ;
#endif
break;
case V_278 :
if ( V_207 != V_262 ) {
F_3 ( V_24 , L_32 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_196 ;
break;
case V_279 :
if ( V_206 != V_239 ) {
F_3 ( V_24 , L_33 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_280 ;
break;
case V_281 :
if ( V_206 != V_282 &&
V_206 != V_243 ) {
F_3 ( V_24 , L_34 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_283 ;
break;
case V_284 :
if ( V_206 != V_285 &&
V_206 != V_244 ) {
F_3 ( V_24 , L_35 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_286 ;
break;
case V_287 :
if ( V_206 != V_288 &&
V_206 != V_245 ) {
F_3 ( V_24 , L_36 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_289 ;
break;
case V_290 :
if ( V_208 != V_291 &&
V_208 != V_256 ) {
F_3 ( V_24 , L_37 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_292 ;
break;
case V_293 :
if ( V_208 != V_294 &&
V_208 != V_257 ) {
F_3 ( V_24 , L_38 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_295 ;
break;
case V_296 :
if ( V_208 != V_297 &&
V_208 != V_258 ) {
F_3 ( V_24 , L_39 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_298 ;
break;
case V_299 :
if ( V_208 != V_300 &&
V_208 != V_301 ) {
F_3 ( V_24 , L_40 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_302 ;
break;
case V_303 :
if ( ! F_110 ( & V_24 -> V_26 ) )
break;
if ( V_206 != V_247 ) {
F_3 ( V_24 , L_41 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_304 ;
break;
case V_305 :
if ( V_206 != V_251 ) {
F_3 ( V_24 , L_42 ) ;
ASSERT ( 0 ) ;
break;
}
V_6 -> V_195 = & V_306 ;
break;
default:
F_3 ( V_24 , L_43 ,
F_120 ( V_160 ) ) ;
break;
}
}
STATIC void
F_122 (
struct V_184 * V_24 ,
T_11 * V_132 ,
struct V_5 * V_6 ,
T_13 * V_160 )
{
int V_46 ;
int V_186 ;
int V_187 ;
int error ;
F_123 ( V_24 -> V_194 , V_160 ) ;
V_186 = 0 ;
V_46 = 1 ;
while ( 1 ) {
V_186 = F_112 ( V_160 -> V_201 ,
V_160 -> V_202 , V_186 ) ;
if ( V_186 == - 1 )
break;
V_187 = F_113 ( V_160 -> V_201 ,
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
( V_307 | V_308 | V_309 ) ) {
if ( V_132 -> V_143 [ V_46 ] . V_145 == NULL ) {
F_114 ( V_24 ,
L_44 , V_8 ) ;
goto V_310;
}
if ( V_132 -> V_143 [ V_46 ] . V_146 < sizeof( V_311 ) ) {
F_114 ( V_24 ,
L_45 ,
V_132 -> V_143 [ V_46 ] . V_146 , V_8 ) ;
goto V_310;
}
error = F_124 ( V_24 , V_132 -> V_143 [ V_46 ] . V_145 ,
- 1 , 0 , V_312 ,
L_46 ) ;
if ( error )
goto V_310;
}
memcpy ( F_115 ( V_6 ,
( T_6 ) V_186 << V_203 ) ,
V_132 -> V_143 [ V_46 ] . V_145 ,
V_187 << V_203 ) ;
V_310:
V_46 ++ ;
V_186 += V_187 ;
}
ASSERT ( V_46 == V_132 -> V_149 ) ;
if ( F_110 ( & V_24 -> V_26 ) )
F_119 ( V_24 , V_6 , V_160 ) ;
}
STATIC void
F_125 (
struct V_184 * V_24 ,
struct V_1 * log ,
struct V_171 * V_132 ,
struct V_5 * V_6 ,
struct V_313 * V_160 )
{
T_6 type ;
F_126 ( log , V_160 ) ;
if ( V_24 -> V_314 == 0 ) {
return;
}
type = 0 ;
if ( V_160 -> V_163 & V_307 )
type |= V_315 ;
if ( V_160 -> V_163 & V_308 )
type |= V_316 ;
if ( V_160 -> V_163 & V_309 )
type |= V_317 ;
if ( log -> V_318 & type )
return;
F_122 ( V_24 , V_132 , V_6 , V_160 ) ;
}
STATIC int
F_127 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_319 )
{
T_13 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
T_4 * V_24 = log -> V_7 ;
T_1 * V_6 ;
int error ;
T_6 V_320 ;
T_8 V_126 ;
if ( F_106 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
F_128 ( log , V_160 ) ;
return 0 ;
}
F_129 ( log , V_160 ) ;
V_320 = 0 ;
if ( V_160 -> V_163 & V_165 )
V_320 |= V_321 ;
V_6 = F_130 ( V_24 -> V_322 , V_160 -> V_175 , V_160 -> V_178 ,
V_320 , NULL ) ;
if ( ! V_6 )
return F_17 ( V_50 ) ;
error = V_6 -> V_19 ;
if ( error ) {
F_20 ( V_6 , L_47 ) ;
goto V_323;
}
V_126 = F_117 ( V_24 , V_6 ) ;
if ( V_126 && V_126 != - 1 && F_131 ( V_126 , V_319 ) >= 0 )
goto V_323;
if ( V_160 -> V_163 & V_165 ) {
error = F_108 ( V_24 , V_132 , V_6 , V_160 ) ;
} else if ( V_160 -> V_163 &
( V_307 | V_308 | V_309 ) ) {
F_125 ( V_24 , log , V_132 , V_6 , V_160 ) ;
} else {
F_122 ( V_24 , V_132 , V_6 , V_160 ) ;
}
if ( error )
goto V_323;
if ( V_262 ==
F_118 ( * ( ( V_260 * ) F_115 ( V_6 , 0 ) ) ) &&
( F_11 ( V_6 -> V_18 ) != F_132 ( log -> V_7 -> V_26 . V_324 ,
( T_16 ) F_133 ( log -> V_7 ) ) ) ) {
F_134 ( V_6 ) ;
error = F_28 ( V_6 ) ;
} else {
ASSERT ( V_6 -> V_33 -> V_34 == V_24 ) ;
V_6 -> V_36 = F_39 ;
F_135 ( V_6 , V_157 ) ;
}
V_323:
F_29 ( V_6 ) ;
return error ;
}
STATIC int
F_136 (
struct V_184 * V_24 ,
struct V_205 * V_325 ,
struct V_326 * V_147 ,
struct V_131 * V_157 )
{
struct V_327 * V_328 ;
int error ;
ASSERT ( V_147 -> V_329 & ( V_330 | V_331 ) ) ;
V_328 = F_137 ( V_24 , V_147 -> V_332 ) ;
if ( ! V_328 )
return V_50 ;
F_138 ( & V_328 -> V_333 , V_325 ) ;
ASSERT ( V_328 -> V_333 . V_334 >= 3 ) ;
error = F_139 ( V_328 , V_325 ) ;
if ( error )
goto V_335;
if ( V_147 -> V_329 & V_330 ) {
ASSERT ( V_147 -> V_329 & V_336 ) ;
error = F_140 ( NULL , V_328 , V_337 ,
V_328 -> V_338 , V_157 ) ;
if ( error )
goto V_335;
}
if ( V_147 -> V_329 & V_331 ) {
ASSERT ( V_147 -> V_329 & V_339 ) ;
error = F_140 ( NULL , V_328 , V_340 ,
V_328 -> V_338 , V_157 ) ;
if ( error )
goto V_335;
}
V_335:
F_141 ( V_328 ) ;
return error ;
}
STATIC int
F_142 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_319 )
{
T_12 * V_147 ;
T_4 * V_24 = log -> V_7 ;
T_1 * V_6 ;
V_199 * V_325 ;
int V_136 ;
T_2 V_341 ;
T_2 V_342 ;
int error ;
int V_343 ;
T_6 V_344 ;
T_18 * V_345 ;
T_6 V_346 ;
int V_347 = 0 ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( T_12 ) ) {
V_147 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_147 = F_85 ( sizeof( T_12 ) , V_127 ) ;
V_347 = 1 ;
error = F_143 ( & V_132 -> V_143 [ 0 ] , V_147 ) ;
if ( error )
goto error;
}
if ( F_106 ( log , V_147 -> V_348 ,
V_147 -> V_349 , 0 ) ) {
error = 0 ;
F_144 ( log , V_147 ) ;
goto error;
}
F_145 ( log , V_147 ) ;
V_6 = F_130 ( V_24 -> V_322 , V_147 -> V_348 , V_147 -> V_349 , 0 ,
& V_196 ) ;
if ( ! V_6 ) {
error = V_50 ;
goto error;
}
error = V_6 -> V_19 ;
if ( error ) {
F_20 ( V_6 , L_48 ) ;
goto V_323;
}
ASSERT ( V_147 -> V_329 & V_350 ) ;
V_325 = ( V_199 * ) F_115 ( V_6 , V_147 -> V_351 ) ;
if ( F_35 ( V_325 -> V_352 != F_146 ( V_262 ) ) ) {
F_114 ( V_24 ,
L_49 ,
V_8 , V_325 , V_6 , V_147 -> V_332 ) ;
F_4 ( L_50 ,
V_121 , V_24 ) ;
error = V_16 ;
goto V_323;
}
V_345 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( F_35 ( V_345 -> V_352 != V_262 ) ) {
F_114 ( V_24 ,
L_51 ,
V_8 , V_132 , V_147 -> V_332 ) ;
F_4 ( L_52 ,
V_121 , V_24 ) ;
error = V_16 ;
goto V_323;
}
if ( V_325 -> V_334 >= 3 ) {
T_8 V_126 = F_57 ( V_325 -> V_353 ) ;
if ( V_126 && V_126 != - 1 && F_131 ( V_126 , V_319 ) >= 0 ) {
F_147 ( log , V_147 ) ;
error = 0 ;
goto V_354;
}
}
if ( ! F_110 ( & V_24 -> V_26 ) &&
V_345 -> V_355 < F_118 ( V_325 -> V_355 ) ) {
if ( F_118 ( V_325 -> V_355 ) == V_356 &&
V_345 -> V_355 < ( V_356 >> 1 ) ) {
} else {
F_147 ( log , V_147 ) ;
error = 0 ;
goto V_323;
}
}
V_345 -> V_355 = 0 ;
if ( F_35 ( F_148 ( V_345 -> V_357 ) ) ) {
if ( ( V_345 -> V_358 != V_359 ) &&
( V_345 -> V_358 != V_360 ) ) {
F_149 ( L_53 ,
V_121 , V_24 , V_345 ) ;
F_114 ( V_24 ,
L_54
L_55 ,
V_8 , V_132 , V_325 , V_6 , V_147 -> V_332 ) ;
error = V_16 ;
goto V_323;
}
} else if ( F_35 ( F_150 ( V_345 -> V_357 ) ) ) {
if ( ( V_345 -> V_358 != V_359 ) &&
( V_345 -> V_358 != V_360 ) &&
( V_345 -> V_358 != V_361 ) ) {
F_149 ( L_56 ,
V_121 , V_24 , V_345 ) ;
F_114 ( V_24 ,
L_57
L_55 ,
V_8 , V_132 , V_325 , V_6 , V_147 -> V_332 ) ;
error = V_16 ;
goto V_323;
}
}
if ( F_35 ( V_345 -> V_362 + V_345 -> V_363 > V_345 -> V_364 ) ) {
F_149 ( L_58 ,
V_121 , V_24 , V_345 ) ;
F_114 ( V_24 ,
L_59
L_60 ,
V_8 , V_132 , V_325 , V_6 , V_147 -> V_332 ,
V_345 -> V_362 + V_345 -> V_363 ,
V_345 -> V_364 ) ;
error = V_16 ;
goto V_323;
}
if ( F_35 ( V_345 -> V_365 > V_24 -> V_26 . V_198 ) ) {
F_149 ( L_61 ,
V_121 , V_24 , V_345 ) ;
F_114 ( V_24 ,
L_59
L_62 , V_8 ,
V_132 , V_325 , V_6 , V_147 -> V_332 , V_345 -> V_365 ) ;
error = V_16 ;
goto V_323;
}
V_346 = F_151 ( V_345 -> V_334 ) ;
if ( F_35 ( V_132 -> V_143 [ 1 ] . V_146 > V_346 ) ) {
F_149 ( L_63 ,
V_121 , V_24 , V_345 ) ;
F_114 ( V_24 ,
L_64 ,
V_8 , V_132 -> V_143 [ 1 ] . V_146 , V_132 ) ;
error = V_16 ;
goto V_323;
}
F_152 ( V_325 , V_345 ) ;
if ( V_132 -> V_143 [ 1 ] . V_146 > V_346 ) {
memcpy ( ( char * ) V_325 + V_346 ,
V_132 -> V_143 [ 1 ] . V_145 + V_346 ,
V_132 -> V_143 [ 1 ] . V_146 - V_346 ) ;
}
V_344 = V_147 -> V_329 ;
switch ( V_344 & ( V_366 | V_367 ) ) {
case V_366 :
F_153 ( V_325 , V_147 -> V_368 . V_369 ) ;
break;
case V_367 :
memcpy ( F_154 ( V_325 ) ,
& V_147 -> V_368 . V_370 ,
sizeof( V_107 ) ) ;
break;
}
if ( V_147 -> V_150 == 2 )
goto V_354;
V_136 = V_132 -> V_143 [ 2 ] . V_146 ;
V_341 = V_132 -> V_143 [ 2 ] . V_145 ;
ASSERT ( V_147 -> V_150 <= 4 ) ;
ASSERT ( ( V_147 -> V_150 == 3 ) || ( V_344 & V_371 ) ) ;
ASSERT ( ! ( V_344 & V_372 ) ||
( V_136 == V_147 -> V_373 ) ) ;
switch ( V_344 & V_372 ) {
case V_374 :
case V_375 :
memcpy ( F_154 ( V_325 ) , V_341 , V_136 ) ;
break;
case V_336 :
F_155 ( V_24 , (struct V_218 * ) V_341 , V_136 ,
( V_376 * ) F_154 ( V_325 ) ,
F_156 ( V_325 , V_24 ) ) ;
break;
default:
ASSERT ( ( V_344 & V_372 ) == 0 ) ;
break;
}
if ( V_147 -> V_329 & V_371 ) {
if ( V_147 -> V_329 & V_372 ) {
V_343 = 3 ;
} else {
V_343 = 2 ;
}
V_136 = V_132 -> V_143 [ V_343 ] . V_146 ;
V_341 = V_132 -> V_143 [ V_343 ] . V_145 ;
ASSERT ( V_136 == V_147 -> V_377 ) ;
switch ( V_147 -> V_329 & V_371 ) {
case V_378 :
case V_379 :
V_342 = F_157 ( V_325 ) ;
ASSERT ( V_136 <= F_158 ( V_325 , V_24 ) ) ;
memcpy ( V_342 , V_341 , V_136 ) ;
break;
case V_339 :
V_342 = F_157 ( V_325 ) ;
F_155 ( V_24 , (struct V_218 * ) V_341 ,
V_136 , ( V_376 * ) V_342 ,
F_158 ( V_325 , V_24 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_65 , V_8 ) ;
ASSERT ( 0 ) ;
error = V_20 ;
goto V_323;
}
}
V_354:
if ( V_147 -> V_329 & ( V_330 | V_331 ) )
error = F_136 ( V_24 , V_325 , V_147 ,
V_157 ) ;
F_116 ( log -> V_7 , V_325 ) ;
ASSERT ( V_6 -> V_33 -> V_34 == V_24 ) ;
V_6 -> V_36 = F_39 ;
F_135 ( V_6 , V_157 ) ;
V_323:
F_29 ( V_6 ) ;
error:
if ( V_347 )
F_86 ( V_147 ) ;
return F_17 ( error ) ;
}
STATIC int
F_159 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_19 * V_380 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_380 ) ;
if ( V_380 -> V_381 & V_382 )
log -> V_318 |= V_315 ;
if ( V_380 -> V_381 & V_383 )
log -> V_318 |= V_316 ;
if ( V_380 -> V_381 & V_384 )
log -> V_318 |= V_317 ;
return ( 0 ) ;
}
STATIC int
F_160 (
struct V_1 * log ,
struct V_131 * V_157 ,
struct V_171 * V_132 ,
T_8 V_319 )
{
T_4 * V_24 = log -> V_7 ;
T_1 * V_6 ;
struct V_385 * V_386 , * V_387 ;
int error ;
T_20 * V_388 ;
T_6 type ;
if ( V_24 -> V_314 == 0 )
return ( 0 ) ;
V_387 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_387 == NULL ) {
F_114 ( log -> V_7 , L_66 , V_8 ) ;
return F_17 ( V_20 ) ;
}
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( V_311 ) ) {
F_114 ( log -> V_7 , L_67 ,
V_132 -> V_143 [ 1 ] . V_146 , V_8 ) ;
return F_17 ( V_20 ) ;
}
type = V_387 -> V_389 & ( V_315 | V_316 | V_317 ) ;
ASSERT ( type ) ;
if ( log -> V_318 & type )
return ( 0 ) ;
V_388 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_388 ) ;
error = F_124 ( V_24 , V_387 , V_388 -> V_390 , 0 , V_312 ,
L_68 ) ;
if ( error )
return F_17 ( V_20 ) ;
ASSERT ( V_388 -> V_391 == 1 ) ;
error = F_161 ( V_24 , NULL , V_24 -> V_322 , V_388 -> V_392 ,
F_162 ( V_24 , V_388 -> V_391 ) , 0 , & V_6 ,
NULL ) ;
if ( error )
return error ;
ASSERT ( V_6 ) ;
V_386 = ( V_311 * ) F_115 ( V_6 , V_388 -> V_393 ) ;
error = F_124 ( V_24 , V_386 , V_388 -> V_390 , 0 , V_312 ,
L_69 ) ;
if ( error ) {
F_29 ( V_6 ) ;
return F_17 ( V_20 ) ;
}
if ( F_110 ( & V_24 -> V_26 ) ) {
struct V_394 * V_395 = (struct V_394 * ) V_386 ;
T_8 V_126 = F_57 ( V_395 -> V_396 ) ;
if ( V_126 && V_126 != - 1 && F_131 ( V_126 , V_319 ) >= 0 ) {
goto V_323;
}
}
memcpy ( V_386 , V_387 , V_132 -> V_143 [ 1 ] . V_146 ) ;
if ( F_110 ( & V_24 -> V_26 ) ) {
F_163 ( ( char * ) V_386 , sizeof( struct V_394 ) ,
V_397 ) ;
}
ASSERT ( V_388 -> V_398 == 2 ) ;
ASSERT ( V_6 -> V_33 -> V_34 == V_24 ) ;
V_6 -> V_36 = F_39 ;
F_135 ( V_6 , V_157 ) ;
V_323:
F_29 ( V_6 ) ;
return 0 ;
}
STATIC int
F_164 (
struct V_1 * log ,
struct V_171 * V_132 ,
T_8 V_126 )
{
int error ;
T_4 * V_24 = log -> V_7 ;
T_21 * V_399 ;
T_22 * V_400 ;
V_400 = V_132 -> V_143 [ 0 ] . V_145 ;
V_399 = F_165 ( V_24 , V_400 -> V_401 ) ;
if ( ( error = F_166 ( & ( V_132 -> V_143 [ 0 ] ) ,
& ( V_399 -> V_402 ) ) ) ) {
F_167 ( V_399 ) ;
return error ;
}
F_168 ( & V_399 -> V_403 , V_400 -> V_401 ) ;
F_169 ( & log -> V_404 -> V_405 ) ;
F_170 ( log -> V_404 , & V_399 -> V_406 , V_126 ) ;
return 0 ;
}
STATIC int
F_171 (
struct V_1 * log ,
struct V_171 * V_132 )
{
T_23 * V_407 ;
T_21 * V_399 = NULL ;
T_24 * V_408 ;
T_25 V_409 ;
struct V_410 V_411 ;
struct V_412 * V_413 = log -> V_404 ;
V_407 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( ( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_414 ) +
( ( V_407 -> V_415 - 1 ) * sizeof( V_416 ) ) ) ) ||
( V_132 -> V_143 [ 0 ] . V_146 == ( sizeof( V_417 ) +
( ( V_407 -> V_415 - 1 ) * sizeof( V_418 ) ) ) ) ) ;
V_409 = V_407 -> V_419 ;
F_169 ( & V_413 -> V_405 ) ;
V_408 = F_172 ( V_413 , & V_411 , 0 ) ;
while ( V_408 != NULL ) {
if ( V_408 -> V_420 == V_170 ) {
V_399 = ( T_21 * ) V_408 ;
if ( V_399 -> V_402 . V_409 == V_409 ) {
F_173 ( V_413 , V_408 ,
V_421 ) ;
F_167 ( V_399 ) ;
F_169 ( & V_413 -> V_405 ) ;
break;
}
}
V_408 = F_174 ( V_413 , & V_411 ) ;
}
F_175 ( V_413 , & V_411 ) ;
F_176 ( & V_413 -> V_405 ) ;
return 0 ;
}
STATIC int
F_177 (
struct V_1 * log ,
struct V_131 * V_157 ,
T_11 * V_132 )
{
struct V_184 * V_24 = log -> V_7 ;
struct V_422 * V_423 ;
T_26 V_424 ;
T_27 V_425 ;
unsigned int V_426 ;
unsigned int V_346 ;
T_27 V_427 ;
V_423 = (struct V_422 * ) V_132 -> V_143 [ 0 ] . V_145 ;
if ( V_423 -> V_428 != V_161 ) {
F_3 ( log -> V_7 , L_70 ) ;
return V_102 ;
}
if ( V_423 -> V_429 != 1 ) {
F_3 ( log -> V_7 , L_71 ) ;
return V_102 ;
}
V_424 = F_32 ( V_423 -> V_430 ) ;
if ( V_424 >= V_24 -> V_26 . V_431 ) {
F_3 ( log -> V_7 , L_72 ) ;
return V_102 ;
}
V_425 = F_32 ( V_423 -> V_432 ) ;
if ( ! V_425 || V_425 == V_433 || V_425 >= V_24 -> V_26 . V_434 ) {
F_3 ( log -> V_7 , L_73 ) ;
return V_102 ;
}
V_346 = F_32 ( V_423 -> V_435 ) ;
if ( V_346 != V_24 -> V_26 . V_198 ) {
F_3 ( log -> V_7 , L_74 ) ;
return V_102 ;
}
V_426 = F_32 ( V_423 -> V_436 ) ;
if ( ! V_426 ) {
F_3 ( log -> V_7 , L_75 ) ;
return V_102 ;
}
V_427 = F_32 ( V_423 -> V_437 ) ;
if ( ! V_427 || V_427 >= V_24 -> V_26 . V_434 ) {
F_3 ( log -> V_7 , L_76 ) ;
return V_102 ;
}
ASSERT ( V_426 == F_178 ( V_24 ) ) ;
ASSERT ( V_427 == F_179 ( V_24 ) ) ;
if ( V_426 != F_178 ( V_24 ) ||
V_427 != F_179 ( V_24 ) ) {
F_3 ( log -> V_7 , L_77 ) ;
return V_102 ;
}
if ( F_106 ( log ,
F_180 ( V_24 , V_424 , V_425 ) , V_427 , 0 ) )
return 0 ;
F_181 ( V_24 , NULL , V_157 , V_424 , V_425 , V_427 ,
F_32 ( V_423 -> V_438 ) ) ;
return 0 ;
}
STATIC void
F_182 (
struct V_134 * V_124 )
{
T_11 * V_132 , * V_154 ;
int V_46 ;
F_91 (item, n, &trans->r_itemq, ri_list) {
F_107 ( & V_132 -> V_133 ) ;
for ( V_46 = 0 ; V_46 < V_132 -> V_144 ; V_46 ++ )
F_86 ( V_132 -> V_143 [ V_46 ] . V_145 ) ;
F_86 ( V_132 -> V_143 ) ;
F_86 ( V_132 ) ;
}
F_86 ( V_124 ) ;
}
STATIC void
F_183 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_313 * V_160 = V_132 -> V_143 [ 0 ] . V_145 ;
struct V_184 * V_24 = log -> V_7 ;
if ( F_105 ( log , V_160 -> V_175 ,
V_160 -> V_178 , V_160 -> V_163 ) ) {
return;
}
F_184 ( V_24 -> V_322 , V_160 -> V_175 ,
V_160 -> V_178 , NULL ) ;
}
STATIC void
F_185 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_326 V_439 ;
struct V_326 * V_440 ;
struct V_184 * V_24 = log -> V_7 ;
int error ;
if ( V_132 -> V_143 [ 0 ] . V_146 == sizeof( struct V_326 ) ) {
V_440 = V_132 -> V_143 [ 0 ] . V_145 ;
} else {
V_440 = & V_439 ;
memset ( V_440 , 0 , sizeof( * V_440 ) ) ;
error = F_143 ( & V_132 -> V_143 [ 0 ] , V_440 ) ;
if ( error )
return;
}
if ( F_105 ( log , V_440 -> V_348 , V_440 -> V_349 , 0 ) )
return;
F_184 ( V_24 -> V_322 , V_440 -> V_348 ,
V_440 -> V_349 , & V_441 ) ;
}
STATIC void
F_186 (
struct V_1 * log ,
struct V_171 * V_132 )
{
struct V_184 * V_24 = log -> V_7 ;
struct V_385 * V_387 ;
struct V_442 * V_388 ;
T_6 type ;
if ( V_24 -> V_314 == 0 )
return;
V_387 = V_132 -> V_143 [ 1 ] . V_145 ;
if ( V_387 == NULL )
return;
if ( V_132 -> V_143 [ 1 ] . V_146 < sizeof( struct V_385 ) )
return;
type = V_387 -> V_389 & ( V_315 | V_316 | V_317 ) ;
ASSERT ( type ) ;
if ( log -> V_318 & type )
return;
V_388 = V_132 -> V_143 [ 0 ] . V_145 ;
ASSERT ( V_388 ) ;
ASSERT ( V_388 -> V_391 == 1 ) ;
F_184 ( V_24 -> V_322 , V_388 -> V_392 ,
F_162 ( V_24 , V_388 -> V_391 ) , NULL ) ;
}
STATIC void
F_187 (
struct V_1 * log ,
struct V_171 * V_132 )
{
switch ( F_92 ( V_132 ) ) {
case V_162 :
F_183 ( log , V_132 ) ;
break;
case V_166 :
F_185 ( log , V_132 ) ;
break;
case V_167 :
F_186 ( log , V_132 ) ;
break;
case V_170 :
case V_169 :
case V_168 :
default:
break;
}
}
STATIC int
F_188 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_171 * V_132 )
{
F_189 ( log , V_124 , V_132 , V_443 ) ;
switch ( F_92 ( V_132 ) ) {
case V_162 :
return F_99 ( log , V_132 ) ;
case V_168 :
return F_159 ( log , V_132 ) ;
case V_166 :
case V_170 :
case V_169 :
case V_167 :
case V_161 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_92 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_17 ( V_20 ) ;
}
}
STATIC int
F_190 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_171 * V_132 )
{
F_189 ( log , V_124 , V_132 , V_444 ) ;
switch ( F_92 ( V_132 ) ) {
case V_162 :
return F_127 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_166 :
return F_142 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_170 :
return F_164 ( log , V_132 , V_124 -> V_128 ) ;
case V_169 :
return F_171 ( log , V_132 ) ;
case V_167 :
return F_160 ( log , V_157 , V_132 ,
V_124 -> V_128 ) ;
case V_161 :
return F_177 ( log , V_157 , V_132 ) ;
case V_168 :
return 0 ;
default:
F_3 ( log -> V_7 , L_78 ,
V_8 , F_92 ( V_132 ) ) ;
ASSERT ( 0 ) ;
return F_17 ( V_20 ) ;
}
}
STATIC int
F_191 (
struct V_1 * log ,
struct V_134 * V_124 ,
struct V_131 * V_157 ,
struct V_131 * V_445 )
{
struct V_171 * V_132 ;
int error = 0 ;
F_102 (item, item_list, ri_list) {
error = F_190 ( log , V_124 ,
V_157 , V_132 ) ;
if ( error )
return error ;
}
return error ;
}
STATIC int
F_192 (
struct V_1 * log ,
struct V_134 * V_124 ,
int V_153 )
{
int error = 0 ;
int V_23 ;
int V_446 = 0 ;
struct V_171 * V_132 ;
struct V_171 * V_310 ;
F_89 ( V_157 ) ;
F_89 ( V_447 ) ;
F_89 ( V_448 ) ;
#define F_193 100
F_194 ( & V_124 -> V_130 ) ;
error = F_88 ( log , V_124 , V_153 ) ;
if ( error )
return error ;
F_91 (item, next, &trans->r_itemq, ri_list) {
switch ( V_153 ) {
case V_443 :
error = F_188 ( log , V_124 , V_132 ) ;
break;
case V_444 :
F_187 ( log , V_132 ) ;
F_93 ( & V_132 -> V_133 , & V_447 ) ;
V_446 ++ ;
if ( V_446 >= F_193 ) {
error = F_191 ( log , V_124 ,
& V_157 , & V_447 ) ;
F_195 ( & V_447 , & V_448 ) ;
V_446 = 0 ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( error )
goto V_52;
}
V_52:
if ( ! F_80 ( & V_447 ) ) {
if ( ! error )
error = F_191 ( log , V_124 ,
& V_157 , & V_447 ) ;
F_195 ( & V_447 , & V_448 ) ;
}
if ( ! F_80 ( & V_448 ) )
F_90 ( & V_448 , & V_124 -> V_129 ) ;
F_182 ( V_124 ) ;
V_23 = F_196 ( & V_157 ) ;
return error ? error : V_23 ;
}
STATIC int
F_197 (
struct V_1 * log ,
struct V_134 * V_124 )
{
F_3 ( log -> V_7 , L_79 , V_8 ) ;
return 0 ;
}
STATIC int
F_198 (
struct V_1 * log ,
struct V_122 V_449 [] ,
struct V_450 * V_73 ,
T_2 V_135 ,
int V_153 )
{
T_2 V_451 ;
int V_452 ;
T_7 * V_453 ;
T_9 * V_124 ;
T_10 V_123 ;
int error ;
unsigned long V_454 ;
T_6 V_182 ;
V_451 = V_135 + F_32 ( V_73 -> V_61 ) ;
V_452 = F_32 ( V_73 -> V_95 ) ;
if ( F_33 ( log -> V_7 , V_73 ) )
return ( F_17 ( V_20 ) ) ;
while ( ( V_135 < V_451 ) && V_452 ) {
ASSERT ( V_135 + sizeof( T_7 ) <= V_451 ) ;
V_453 = ( T_7 * ) V_135 ;
V_135 += sizeof( T_7 ) ;
if ( V_453 -> V_455 != V_456 &&
V_453 -> V_455 != V_457 ) {
F_3 ( log -> V_7 , L_80 ,
V_8 , V_453 -> V_455 ) ;
ASSERT ( 0 ) ;
return ( F_17 ( V_20 ) ) ;
}
V_123 = F_32 ( V_453 -> V_458 ) ;
V_454 = F_199 ( V_123 ) ;
V_124 = F_70 ( & V_449 [ V_454 ] , V_123 ) ;
if ( V_124 == NULL ) {
if ( V_453 -> V_96 & V_459 )
F_72 ( & V_449 [ V_454 ] , V_123 ,
F_57 ( V_73 -> V_89 ) ) ;
} else {
if ( V_135 + F_32 ( V_453 -> V_460 ) > V_451 ) {
F_3 ( log -> V_7 , L_81 ,
V_8 , F_32 ( V_453 -> V_460 ) ) ;
F_200 ( 1 ) ;
return ( F_17 ( V_20 ) ) ;
}
V_182 = V_453 -> V_96 & ~ V_461 ;
if ( V_182 & V_462 )
V_182 &= ~ V_463 ;
switch ( V_182 ) {
case V_464 :
error = F_192 ( log ,
V_124 , V_153 ) ;
break;
case V_97 :
error = F_197 ( log , V_124 ) ;
break;
case V_462 :
error = F_79 ( log ,
V_124 , V_135 ,
F_32 ( V_453 -> V_460 ) ) ;
break;
case V_459 :
F_3 ( log -> V_7 , L_82 ,
V_8 ) ;
ASSERT ( 0 ) ;
error = F_17 ( V_20 ) ;
break;
case 0 :
case V_463 :
error = F_84 ( log , V_124 ,
V_135 , F_32 ( V_453 -> V_460 ) ) ;
break;
default:
F_3 ( log -> V_7 , L_83 ,
V_8 , V_182 ) ;
ASSERT ( 0 ) ;
error = F_17 ( V_20 ) ;
break;
}
if ( error )
return error ;
}
V_135 += F_32 ( V_453 -> V_460 ) ;
V_452 -- ;
}
return 0 ;
}
STATIC int
F_201 (
T_4 * V_24 ,
T_21 * V_399 )
{
T_28 * V_465 ;
T_29 * V_466 ;
int V_46 ;
int error = 0 ;
T_30 * V_467 ;
T_31 V_468 ;
ASSERT ( ! F_202 ( V_469 , & V_399 -> V_470 ) ) ;
for ( V_46 = 0 ; V_46 < V_399 -> V_402 . V_401 ; V_46 ++ ) {
V_467 = & ( V_399 -> V_402 . V_471 [ V_46 ] ) ;
V_468 = F_203 ( V_24 ,
F_204 ( V_24 , V_467 -> V_472 ) ) ;
if ( ( V_468 == 0 ) ||
( V_467 -> V_473 == 0 ) ||
( V_468 >= V_24 -> V_26 . V_474 ) ||
( V_467 -> V_473 >= V_24 -> V_26 . V_434 ) ) {
F_205 ( V_469 , & V_399 -> V_470 ) ;
F_206 ( V_399 , V_399 -> V_402 . V_401 ) ;
return F_17 ( V_20 ) ;
}
}
V_466 = F_207 ( V_24 , 0 ) ;
error = F_208 ( V_466 , & F_209 ( V_24 ) -> V_475 , 0 , 0 ) ;
if ( error )
goto V_476;
V_465 = F_210 ( V_466 , V_399 , V_399 -> V_402 . V_401 ) ;
for ( V_46 = 0 ; V_46 < V_399 -> V_402 . V_401 ; V_46 ++ ) {
V_467 = & ( V_399 -> V_402 . V_471 [ V_46 ] ) ;
error = F_211 ( V_466 , V_467 -> V_472 , V_467 -> V_473 ) ;
if ( error )
goto V_476;
F_212 ( V_466 , V_465 , V_467 -> V_472 ,
V_467 -> V_473 ) ;
}
F_205 ( V_469 , & V_399 -> V_470 ) ;
error = F_213 ( V_466 , 0 ) ;
return error ;
V_476:
F_214 ( V_466 , V_477 ) ;
return error ;
}
STATIC int
F_215 (
struct V_1 * log )
{
T_24 * V_408 ;
T_21 * V_399 ;
int error = 0 ;
struct V_410 V_411 ;
struct V_412 * V_413 ;
V_413 = log -> V_404 ;
F_169 ( & V_413 -> V_405 ) ;
V_408 = F_172 ( V_413 , & V_411 , 0 ) ;
while ( V_408 != NULL ) {
if ( V_408 -> V_420 != V_170 ) {
#ifdef F_216
for (; V_408 ; V_408 = F_174 ( V_413 , & V_411 ) )
ASSERT ( V_408 -> V_420 != V_170 ) ;
#endif
break;
}
V_399 = ( T_21 * ) V_408 ;
if ( F_202 ( V_469 , & V_399 -> V_470 ) ) {
V_408 = F_174 ( V_413 , & V_411 ) ;
continue;
}
F_176 ( & V_413 -> V_405 ) ;
error = F_201 ( log -> V_7 , V_399 ) ;
F_169 ( & V_413 -> V_405 ) ;
if ( error )
goto V_52;
V_408 = F_174 ( V_413 , & V_411 ) ;
}
V_52:
F_175 ( V_413 , & V_411 ) ;
F_176 ( & V_413 -> V_405 ) ;
return error ;
}
STATIC void
F_217 (
T_4 * V_24 ,
T_26 V_424 ,
int V_172 )
{
T_29 * V_466 ;
T_32 * V_478 ;
T_1 * V_479 ;
int V_13 ;
int error ;
V_466 = F_207 ( V_24 , V_480 ) ;
error = F_208 ( V_466 , & F_209 ( V_24 ) -> V_481 , 0 , 0 ) ;
if ( error )
goto V_482;
error = F_218 ( V_24 , V_466 , V_424 , & V_479 ) ;
if ( error )
goto V_482;
V_478 = F_219 ( V_479 ) ;
V_478 -> V_483 [ V_172 ] = F_34 ( V_484 ) ;
V_13 = F_111 ( T_32 , V_483 ) +
( sizeof( T_15 ) * V_172 ) ;
F_220 ( V_466 , V_479 , V_13 ,
( V_13 + sizeof( T_15 ) - 1 ) ) ;
error = F_213 ( V_466 , 0 ) ;
if ( error )
goto V_485;
return;
V_482:
F_214 ( V_466 , V_477 ) ;
V_485:
F_3 ( V_24 , L_84 , V_8 , V_424 ) ;
return;
}
STATIC T_15
F_221 (
struct V_184 * V_24 ,
T_26 V_424 ,
T_15 V_486 ,
int V_172 )
{
struct V_5 * V_487 ;
struct V_205 * V_325 ;
struct V_327 * V_328 ;
T_33 V_488 ;
int error ;
V_488 = F_222 ( V_24 , V_424 , V_486 ) ;
error = F_223 ( V_24 , NULL , V_488 , 0 , 0 , & V_328 ) ;
if ( error )
goto V_489;
error = F_224 ( V_24 , NULL , & V_328 -> V_490 , & V_325 , & V_487 , 0 , 0 ) ;
if ( error )
goto V_491;
ASSERT ( V_328 -> V_333 . V_492 == 0 ) ;
ASSERT ( V_328 -> V_333 . V_357 != 0 ) ;
V_486 = F_32 ( V_325 -> V_200 ) ;
F_29 ( V_487 ) ;
V_328 -> V_333 . V_493 = 0 ;
F_225 ( V_328 ) ;
return V_486 ;
V_491:
F_225 ( V_328 ) ;
V_489:
F_217 ( V_24 , V_424 , V_172 ) ;
return V_484 ;
}
STATIC void
F_226 (
struct V_1 * log )
{
T_4 * V_24 ;
T_26 V_424 ;
T_32 * V_478 ;
T_1 * V_479 ;
T_15 V_486 ;
int V_172 ;
int error ;
T_6 V_494 ;
V_24 = log -> V_7 ;
V_494 = V_24 -> V_495 ;
V_24 -> V_495 = 0 ;
for ( V_424 = 0 ; V_424 < V_24 -> V_26 . V_431 ; V_424 ++ ) {
error = F_218 ( V_24 , NULL , V_424 , & V_479 ) ;
if ( error ) {
continue;
}
V_478 = F_219 ( V_479 ) ;
F_7 ( V_479 ) ;
for ( V_172 = 0 ; V_172 < V_496 ; V_172 ++ ) {
V_486 = F_32 ( V_478 -> V_483 [ V_172 ] ) ;
while ( V_486 != V_484 ) {
V_486 = F_221 ( V_24 ,
V_424 , V_486 , V_172 ) ;
}
}
F_227 ( V_479 ) ;
}
V_24 -> V_495 = V_494 ;
}
STATIC int
F_228 (
struct V_450 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
T_34 V_497 ;
V_497 = F_229 ( log , V_73 , V_135 , F_32 ( V_73 -> V_61 ) ) ;
if ( V_497 != V_73 -> V_498 ) {
if ( V_73 -> V_498 || F_110 ( & log -> V_7 -> V_26 ) ) {
F_114 ( log -> V_7 ,
L_85 ,
F_230 ( V_73 -> V_498 ) ,
F_230 ( V_497 ) ) ;
F_231 ( V_135 , 32 ) ;
}
if ( F_110 ( & log -> V_7 -> V_26 ) )
return V_16 ;
}
return 0 ;
}
STATIC int
F_232 (
struct V_450 * V_73 ,
T_2 V_135 ,
struct V_1 * log )
{
int V_46 , V_47 , V_499 ;
int error ;
error = F_228 ( V_73 , V_135 , log ) ;
if ( error )
return error ;
for ( V_46 = 0 ; V_46 < F_50 ( F_32 ( V_73 -> V_61 ) ) &&
V_46 < ( V_60 / V_53 ) ; V_46 ++ ) {
* ( V_81 * ) V_135 = * ( V_81 * ) & V_73 -> V_500 [ V_46 ] ;
V_135 += V_53 ;
}
if ( F_49 ( & log -> V_7 -> V_26 ) ) {
T_35 * V_501 = ( T_35 * ) V_73 ;
for ( ; V_46 < F_50 ( F_32 ( V_73 -> V_61 ) ) ; V_46 ++ ) {
V_47 = V_46 / ( V_60 / V_53 ) ;
V_499 = V_46 % ( V_60 / V_53 ) ;
* ( V_81 * ) V_135 = V_501 [ V_47 ] . V_502 . V_503 [ V_499 ] ;
V_135 += V_53 ;
}
}
return 0 ;
}
STATIC int
F_233 (
struct V_1 * log ,
struct V_450 * V_73 ,
T_3 V_181 )
{
int V_504 ;
if ( F_35 ( V_73 -> V_31 != F_34 ( V_32 ) ) ) {
F_4 ( L_86 ,
V_121 , log -> V_7 ) ;
return F_17 ( V_16 ) ;
}
if ( F_35 (
( ! V_73 -> V_93 ||
( F_32 ( V_73 -> V_93 ) & ( ~ V_505 ) ) ) ) ) {
F_3 ( log -> V_7 , L_87 ,
V_8 , F_32 ( V_73 -> V_93 ) ) ;
return F_17 ( V_20 ) ;
}
V_504 = F_32 ( V_73 -> V_61 ) ;
if ( F_35 ( V_504 <= 0 || V_504 > V_70 ) ) {
F_4 ( L_88 ,
V_121 , log -> V_7 ) ;
return F_17 ( V_16 ) ;
}
if ( F_35 ( V_181 > log -> V_3 || V_181 > V_70 ) ) {
F_4 ( L_89 ,
V_121 , log -> V_7 ) ;
return F_17 ( V_16 ) ;
}
return 0 ;
}
STATIC int
F_234 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 ,
int V_153 )
{
T_5 * V_73 ;
T_3 V_12 ;
T_2 V_13 ;
T_1 * V_506 , * V_507 ;
int error = 0 , V_59 ;
int V_508 , V_509 ;
int V_79 , V_510 , V_511 ;
struct V_122 V_449 [ V_512 ] ;
ASSERT ( V_63 != V_72 ) ;
if ( F_49 ( & log -> V_7 -> V_26 ) ) {
V_506 = F_2 ( log , 1 ) ;
if ( ! V_506 )
return V_50 ;
error = F_21 ( log , V_72 , 1 , V_506 , & V_13 ) ;
if ( error )
goto V_513;
V_73 = ( T_5 * ) V_13 ;
error = F_233 ( log , V_73 , V_72 ) ;
if ( error )
goto V_513;
V_59 = F_32 ( V_73 -> V_59 ) ;
if ( ( F_32 ( V_73 -> V_93 ) & V_94 ) &&
( V_59 > V_60 ) ) {
V_79 = V_59 / V_60 ;
if ( V_59 % V_60 )
V_79 ++ ;
F_8 ( V_506 ) ;
V_506 = F_2 ( log , V_79 ) ;
} else {
V_79 = 1 ;
}
} else {
ASSERT ( log -> V_10 == 1 ) ;
V_79 = 1 ;
V_506 = F_2 ( log , 1 ) ;
V_59 = V_514 ;
}
if ( ! V_506 )
return V_50 ;
V_507 = F_2 ( log , F_50 ( V_59 ) ) ;
if ( ! V_507 ) {
F_8 ( V_506 ) ;
return V_50 ;
}
memset ( V_449 , 0 , sizeof( V_449 ) ) ;
if ( V_72 <= V_63 ) {
for ( V_12 = V_72 ; V_12 < V_63 ; ) {
error = F_21 ( log , V_12 , V_79 , V_506 , & V_13 ) ;
if ( error )
goto V_515;
V_73 = ( T_5 * ) V_13 ;
error = F_233 ( log , V_73 , V_12 ) ;
if ( error )
goto V_515;
V_508 = ( int ) F_50 ( F_32 ( V_73 -> V_61 ) ) ;
error = F_21 ( log , V_12 + V_79 , V_508 , V_507 ,
& V_13 ) ;
if ( error )
goto V_515;
error = F_232 ( V_73 , V_13 , log ) ;
if ( error )
goto V_515;
error = F_198 ( log ,
V_449 , V_73 , V_13 , V_153 ) ;
if ( error )
goto V_515;
V_12 += V_508 + V_79 ;
}
} else {
V_12 = V_72 ;
while ( V_12 < log -> V_3 ) {
V_13 = V_506 -> V_15 ;
V_510 = 0 ;
V_511 = 0 ;
if ( V_12 + V_79 <= log -> V_3 ) {
error = F_21 ( log , V_12 , V_79 , V_506 ,
& V_13 ) ;
if ( error )
goto V_515;
} else {
if ( V_12 != log -> V_3 ) {
ASSERT ( V_12 <= V_70 ) ;
V_510 = log -> V_3 - ( int ) V_12 ;
ASSERT ( V_510 > 0 ) ;
error = F_21 ( log , V_12 ,
V_510 , V_506 ,
& V_13 ) ;
if ( error )
goto V_515;
}
V_511 = V_79 - V_510 ;
error = F_22 ( log , 0 ,
V_511 , V_506 ,
V_13 + F_11 ( V_510 ) ) ;
if ( error )
goto V_515;
}
V_73 = ( T_5 * ) V_13 ;
error = F_233 ( log , V_73 ,
V_510 ? V_12 : 0 ) ;
if ( error )
goto V_515;
V_508 = ( int ) F_50 ( F_32 ( V_73 -> V_61 ) ) ;
V_12 += V_79 ;
if ( V_12 + V_508 <= log -> V_3 ) {
error = F_21 ( log , V_12 , V_508 , V_507 ,
& V_13 ) ;
if ( error )
goto V_515;
} else {
V_13 = V_507 -> V_15 ;
V_509 = 0 ;
if ( V_12 != log -> V_3 ) {
ASSERT ( ! V_511 ) ;
ASSERT ( V_12 <= V_70 ) ;
V_509 =
log -> V_3 - ( int ) V_12 ;
ASSERT ( V_509 > 0 ) ;
error = F_21 ( log , V_12 ,
V_509 , V_507 ,
& V_13 ) ;
if ( error )
goto V_515;
}
error = F_22 ( log , 0 ,
V_508 - V_509 , V_507 ,
V_13 + F_11 ( V_509 ) ) ;
if ( error )
goto V_515;
}
error = F_232 ( V_73 , V_13 , log ) ;
if ( error )
goto V_515;
error = F_198 ( log , V_449 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_515;
V_12 += V_508 ;
}
ASSERT ( V_12 >= log -> V_3 ) ;
V_12 -= log -> V_3 ;
while ( V_12 < V_63 ) {
error = F_21 ( log , V_12 , V_79 , V_506 , & V_13 ) ;
if ( error )
goto V_515;
V_73 = ( T_5 * ) V_13 ;
error = F_233 ( log , V_73 , V_12 ) ;
if ( error )
goto V_515;
V_508 = ( int ) F_50 ( F_32 ( V_73 -> V_61 ) ) ;
error = F_21 ( log , V_12 + V_79 , V_508 , V_507 ,
& V_13 ) ;
if ( error )
goto V_515;
error = F_232 ( V_73 , V_13 , log ) ;
if ( error )
goto V_515;
error = F_198 ( log , V_449 ,
V_73 , V_13 , V_153 ) ;
if ( error )
goto V_515;
V_12 += V_508 + V_79 ;
}
}
V_515:
F_8 ( V_507 ) ;
V_513:
F_8 ( V_506 ) ;
return error ;
}
STATIC int
F_235 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error , V_46 ;
ASSERT ( V_63 != V_72 ) ;
log -> V_183 = F_73 ( V_516 *
sizeof( struct V_131 ) ,
V_127 ) ;
for ( V_46 = 0 ; V_46 < V_516 ; V_46 ++ )
F_74 ( & log -> V_183 [ V_46 ] ) ;
error = F_234 ( log , V_63 , V_72 ,
V_443 ) ;
if ( error != 0 ) {
F_86 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
error = F_234 ( log , V_63 , V_72 ,
V_444 ) ;
#ifdef F_216
if ( ! error ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_516 ; V_46 ++ )
ASSERT ( F_80 ( & log -> V_183 [ V_46 ] ) ) ;
}
#endif
F_86 ( log -> V_183 ) ;
log -> V_183 = NULL ;
return error ;
}
STATIC int
F_236 (
struct V_1 * log ,
T_3 V_63 ,
T_3 V_72 )
{
int error ;
T_1 * V_6 ;
T_36 * V_517 ;
error = F_235 ( log , V_63 , V_72 ) ;
if ( error )
return error ;
if ( F_16 ( log -> V_7 ) ) {
return ( V_20 ) ;
}
F_237 ( log -> V_7 ) ;
V_6 = F_238 ( log -> V_7 , 0 ) ;
F_239 ( V_6 ) ;
ASSERT ( ! ( F_240 ( V_6 ) ) ) ;
F_15 ( V_6 ) ;
F_241 ( V_6 ) ;
V_6 -> V_195 = & V_306 ;
if ( F_16 ( log -> V_7 ) ) {
F_29 ( V_6 ) ;
return F_17 ( V_20 ) ;
}
F_18 ( V_6 ) ;
error = F_19 ( V_6 ) ;
if ( error ) {
F_20 ( V_6 , V_8 ) ;
ASSERT ( 0 ) ;
F_29 ( V_6 ) ;
return error ;
}
V_517 = & log -> V_7 -> V_26 ;
F_242 ( V_517 , F_243 ( V_6 ) ) ;
ASSERT ( V_517 -> V_518 == V_251 ) ;
ASSERT ( F_244 ( V_517 ) ) ;
F_29 ( V_6 ) ;
F_245 ( log -> V_7 ) ;
F_246 ( log ) ;
log -> V_519 &= ~ V_520 ;
return 0 ;
}
int
V_134 (
struct V_1 * log )
{
T_3 V_63 , V_72 ;
int error ;
if ( ( error = F_55 ( log , & V_63 , & V_72 ) ) )
return error ;
if ( V_72 != V_63 ) {
if ( ( error = F_247 ( log -> V_7 , L_90 ) ) ) {
return error ;
}
if ( F_248 ( & log -> V_7 -> V_26 ) == V_521 &&
F_249 ( & log -> V_7 -> V_26 ,
V_522 ) ) {
F_3 ( log -> V_7 ,
L_91
L_92
L_93 ,
( log -> V_7 -> V_26 . V_523 &
V_522 ) ) ;
return V_102 ;
}
F_250 ( log -> V_7 , L_94 ,
log -> V_7 -> V_524 ? log -> V_7 -> V_524
: L_95 ) ;
error = F_236 ( log , V_63 , V_72 ) ;
log -> V_519 |= V_525 ;
}
return error ;
}
int
F_251 (
struct V_1 * log )
{
if ( log -> V_519 & V_525 ) {
int error ;
error = F_215 ( log ) ;
if ( error ) {
F_114 ( log -> V_7 , L_96 ) ;
return error ;
}
F_252 ( log -> V_7 , V_526 ) ;
F_226 ( log ) ;
F_246 ( log ) ;
F_250 ( log -> V_7 , L_97 ,
log -> V_7 -> V_524 ? log -> V_7 -> V_524
: L_95 ) ;
log -> V_519 &= ~ V_525 ;
} else {
F_253 ( log -> V_7 , L_98 ) ;
}
return 0 ;
}
void
F_246 (
struct V_1 * log )
{
T_4 * V_24 ;
T_37 * V_527 ;
T_1 * V_528 ;
T_1 * V_479 ;
T_26 V_424 ;
T_25 V_529 ;
T_25 V_530 ;
T_25 V_531 ;
int error ;
V_24 = log -> V_7 ;
V_529 = 0LL ;
V_530 = 0LL ;
V_531 = 0LL ;
for ( V_424 = 0 ; V_424 < V_24 -> V_26 . V_431 ; V_424 ++ ) {
error = F_254 ( V_24 , NULL , V_424 , 0 , & V_528 ) ;
if ( error ) {
F_114 ( V_24 , L_99 ,
V_8 , V_424 , error ) ;
} else {
V_527 = F_255 ( V_528 ) ;
V_529 += F_32 ( V_527 -> V_532 ) +
F_32 ( V_527 -> V_533 ) ;
F_29 ( V_528 ) ;
}
error = F_218 ( V_24 , NULL , V_424 , & V_479 ) ;
if ( error ) {
F_114 ( V_24 , L_100 ,
V_8 , V_424 , error ) ;
} else {
struct V_236 * V_478 = F_219 ( V_479 ) ;
V_530 += F_32 ( V_478 -> V_534 ) ;
V_531 += F_32 ( V_478 -> V_535 ) ;
F_29 ( V_479 ) ;
}
}
}
