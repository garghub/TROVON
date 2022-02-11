int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 ,
T_2 * V_6 ,
T_3 * V_7 ,
bool V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int error ;
error = F_2 ( V_2 , NULL , V_3 , 0 , & V_10 ) ;
if ( error )
return error ;
V_12 = F_3 ( V_2 , NULL , V_10 , V_3 , NULL ) ;
error = F_4 ( V_12 , V_4 , V_5 , V_6 , V_7 ,
V_8 ) ;
F_5 ( V_12 , error ? V_13 : V_14 ) ;
F_6 ( V_10 ) ;
return error ;
}
int
F_7 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
bool * V_19 ,
bool * V_20 )
{
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
int error = 0 ;
if ( ! F_8 ( V_16 ) || ! F_9 ( V_18 ) ) {
* V_19 = false ;
return 0 ;
}
F_10 ( V_16 , V_18 ) ;
V_3 = F_11 ( V_16 -> V_21 , V_18 -> V_22 ) ;
V_4 = F_12 ( V_16 -> V_21 , V_18 -> V_22 ) ;
V_5 = V_18 -> V_23 ;
error = F_1 ( V_16 -> V_21 , V_3 , V_4 ,
V_5 , & V_6 , & V_7 , true ) ;
if ( error )
return error ;
* V_19 = * V_20 = false ;
if ( V_6 == V_24 ) {
return 0 ;
} else if ( V_6 == V_4 ) {
V_18 -> V_23 = V_7 ;
* V_19 = true ;
if ( V_7 != V_5 )
* V_20 = true ;
return 0 ;
} else {
V_18 -> V_23 = V_6 - V_4 ;
* V_20 = true ;
return 0 ;
}
}
int
F_13 (
struct V_15 * V_16 ,
struct V_17 * V_25 ,
bool * V_19 )
{
struct V_26 * V_27 = F_14 ( V_16 , V_28 ) ;
struct V_17 V_29 ;
int error = 0 ;
bool V_30 = false , V_20 ;
T_4 V_31 ;
if ( ! F_15 ( V_16 , V_27 , V_25 -> V_32 , & V_31 , & V_29 ) )
V_30 = true ;
if ( ! V_30 && V_29 . V_32 <= V_25 -> V_32 ) {
F_16 ( V_16 , V_25 ) ;
F_17 ( V_25 , V_29 . V_32 , V_29 . V_23 ) ;
* V_19 = true ;
return 0 ;
}
error = F_7 ( V_16 , V_25 , V_19 , & V_20 ) ;
if ( error )
return error ;
if ( ! * V_19 )
return 0 ;
error = F_18 ( V_16 , 0 ) ;
if ( error )
return error ;
error = F_19 ( V_16 , V_28 , V_25 -> V_32 ,
V_25 -> V_23 , 0 , & V_29 , & V_31 , V_30 ) ;
if ( error == - V_33 || error == - V_34 )
F_20 ( V_16 , V_25 ) ;
if ( error )
return error ;
F_21 ( V_16 , & V_29 ) ;
return 0 ;
}
STATIC int
F_22 (
struct V_15 * V_16 ,
struct V_17 * V_25 ,
T_5 V_35 ,
T_6 V_36 ,
struct V_37 * V_38 )
{
T_7 V_39 ;
int V_40 = 1 ;
if ( V_25 -> V_41 == V_42 )
return 0 ;
F_17 ( V_25 , V_35 , V_36 ) ;
F_23 ( V_16 , V_25 ) ;
if ( V_25 -> V_23 == 0 )
return 0 ;
return F_24 ( NULL , V_16 , V_25 -> V_32 , V_25 -> V_23 ,
V_43 | V_44 , & V_39 ,
0 , V_25 , & V_40 , V_38 ) ;
}
int
F_25 (
struct V_15 * V_16 ,
T_8 V_45 ,
T_8 V_46 )
{
struct V_17 V_29 ;
struct V_37 V_38 ;
struct V_1 * V_2 = V_16 -> V_21 ;
struct V_26 * V_27 = F_14 ( V_16 , V_28 ) ;
T_5 V_35 = F_26 ( V_2 , V_45 ) ;
T_5 V_47 = F_27 ( V_2 , V_45 + V_46 ) ;
T_4 V_31 ;
bool V_48 ;
int error = 0 ;
F_28 ( V_16 , V_49 ) ;
for ( V_48 = F_15 ( V_16 , V_27 , V_35 , & V_31 , & V_29 ) ;
V_48 && V_29 . V_32 < V_47 ;
V_48 = F_29 ( V_27 , ++ V_31 , & V_29 ) ) {
error = F_22 ( V_16 , & V_29 , V_35 ,
V_47 - V_35 , & V_38 ) ;
if ( error )
break;
}
F_30 ( V_16 , V_49 ) ;
return error ;
}
int
F_31 (
struct V_15 * V_16 ,
struct V_17 * V_25 ,
bool * V_19 ,
T_9 * V_50 )
{
struct V_1 * V_2 = V_16 -> V_21 ;
T_5 V_35 = V_25 -> V_32 ;
T_6 V_36 = V_25 -> V_23 ;
struct V_17 V_29 ;
struct V_37 V_38 ;
struct V_51 * V_52 = NULL ;
T_7 V_39 ;
int V_40 , error = 0 ;
bool V_20 ;
T_6 V_53 ;
T_3 V_54 = 0 ;
T_4 V_31 ;
V_55:
ASSERT ( F_8 ( V_16 ) ) ;
ASSERT ( F_32 ( V_16 , V_49 | V_56 ) ) ;
if ( F_15 ( V_16 , V_16 -> V_57 , V_35 , & V_31 , & V_29 ) &&
V_29 . V_32 <= V_35 ) {
* V_19 = true ;
if ( ! F_33 ( V_29 . V_22 ) ) {
F_17 ( & V_29 , V_35 , V_36 ) ;
* V_25 = V_29 ;
goto V_58;
}
F_17 ( V_25 , V_29 . V_32 , V_29 . V_23 ) ;
} else {
error = F_7 ( V_16 , V_25 , V_19 , & V_20 ) ;
if ( error || ! * V_19 )
goto V_59;
}
if ( ! V_52 ) {
V_53 = F_34 ( V_25 -> V_32 ,
V_25 -> V_23 , F_35 ( V_16 ) ) ;
V_54 = F_36 ( V_2 , V_53 ) ;
F_30 ( V_16 , * V_50 ) ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_60 , V_54 , 0 , 0 , & V_52 ) ;
* V_50 = V_49 ;
F_28 ( V_16 , * V_50 ) ;
if ( error )
return error ;
error = F_18 ( V_16 , 0 ) ;
if ( error )
goto V_59;
goto V_55;
}
error = F_39 ( V_52 , V_16 , V_54 , 0 ,
V_61 ) ;
if ( error )
goto V_59;
F_40 ( V_52 , V_16 , 0 ) ;
F_41 ( & V_38 , & V_39 ) ;
V_40 = 1 ;
error = F_24 ( V_52 , V_16 , V_25 -> V_32 , V_25 -> V_23 ,
V_43 | V_62 , & V_39 ,
V_54 , V_25 , & V_40 , & V_38 ) ;
if ( error )
goto V_63;
error = F_42 ( & V_52 , & V_38 , NULL ) ;
if ( error )
goto V_63;
error = F_43 ( V_52 ) ;
if ( error )
return error ;
V_58:
return F_22 ( V_16 , V_25 , V_35 , V_36 ,
& V_38 ) ;
V_63:
F_44 ( & V_38 ) ;
F_45 ( V_52 , V_16 , ( long ) V_54 , 0 ,
V_61 ) ;
V_59:
if ( V_52 )
F_46 ( V_52 ) ;
return error ;
}
bool
F_47 (
struct V_15 * V_16 ,
T_8 V_45 ,
struct V_17 * V_25 )
{
struct V_26 * V_27 = F_14 ( V_16 , V_28 ) ;
T_5 V_35 ;
struct V_17 V_29 ;
T_4 V_31 ;
ASSERT ( F_32 ( V_16 , V_49 | V_56 ) ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_35 = F_26 ( V_16 -> V_21 , V_45 ) ;
if ( ! F_15 ( V_16 , V_27 , V_35 , & V_31 , & V_29 ) )
return false ;
if ( V_29 . V_32 > V_35 )
return false ;
F_48 ( V_16 , V_45 , 1 , V_64 ,
& V_29 ) ;
* V_25 = V_29 ;
return true ;
}
void
F_49 (
struct V_15 * V_16 ,
T_5 V_35 ,
struct V_17 * V_25 )
{
struct V_26 * V_27 = F_14 ( V_16 , V_28 ) ;
struct V_17 V_29 ;
T_4 V_31 ;
if ( ! F_8 ( V_16 ) )
return;
if ( ! F_15 ( V_16 , V_27 , V_35 , & V_31 , & V_29 ) )
return;
if ( V_29 . V_32 < V_35 ) {
if ( ! F_29 ( V_27 , V_31 + 1 , & V_29 ) )
return;
}
if ( V_29 . V_32 >= V_25 -> V_32 + V_25 -> V_23 )
return;
V_25 -> V_23 = V_29 . V_32 - V_25 -> V_32 ;
F_50 ( V_16 , V_25 ) ;
}
int
F_51 (
struct V_15 * V_16 ,
struct V_51 * * V_65 ,
T_5 V_35 ,
T_5 V_47 ,
bool V_66 )
{
struct V_26 * V_27 = F_14 ( V_16 , V_28 ) ;
struct V_17 V_29 , V_67 ;
T_4 V_31 ;
T_7 V_68 ;
struct V_37 V_38 ;
int error = 0 ;
if ( ! F_8 ( V_16 ) )
return 0 ;
if ( ! F_15 ( V_16 , V_27 , V_35 , & V_31 , & V_29 ) )
return 0 ;
while ( V_29 . V_32 < V_47 ) {
V_67 = V_29 ;
F_17 ( & V_67 , V_35 , V_47 - V_35 ) ;
F_52 ( V_16 , & V_67 ) ;
if ( F_33 ( V_67 . V_22 ) ) {
error = F_53 ( V_16 , V_28 ,
& V_31 , & V_29 , & V_67 ) ;
if ( error )
break;
} else if ( V_67 . V_41 == V_69 || V_66 ) {
F_40 ( * V_65 , V_16 , 0 ) ;
F_41 ( & V_38 , & V_68 ) ;
error = F_54 ( V_16 -> V_21 ,
& V_38 , V_67 . V_22 ,
V_67 . V_23 ) ;
if ( error )
break;
F_55 ( V_16 -> V_21 , & V_38 ,
V_67 . V_22 , V_67 . V_23 ,
NULL ) ;
F_56 ( * V_65 , V_16 , V_70 ,
- ( long ) V_67 . V_23 ) ;
error = F_42 ( V_65 , & V_38 , V_16 ) ;
if ( error ) {
F_44 ( & V_38 ) ;
break;
}
F_57 ( V_16 , & V_31 , & V_29 , & V_67 ) ;
}
if ( ! F_29 ( V_27 , ++ V_31 , & V_29 ) )
break;
}
if ( ! V_27 -> V_71 )
F_58 ( V_16 ) ;
return error ;
}
int
F_59 (
struct V_15 * V_16 ,
T_8 V_45 ,
T_8 V_46 ,
bool V_66 )
{
struct V_51 * V_52 ;
T_5 V_35 ;
T_5 V_47 ;
int error ;
F_60 ( V_16 , V_45 , V_46 ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_35 = F_26 ( V_16 -> V_21 , V_45 ) ;
if ( V_46 == V_72 )
V_47 = V_72 ;
else
V_47 = F_27 ( V_16 -> V_21 , V_45 + V_46 ) ;
error = F_37 ( V_16 -> V_21 , & F_38 ( V_16 -> V_21 ) -> V_60 ,
0 , 0 , 0 , & V_52 ) ;
if ( error )
goto V_59;
F_28 ( V_16 , V_49 ) ;
F_40 ( V_52 , V_16 , 0 ) ;
error = F_51 ( V_16 , & V_52 , V_35 , V_47 ,
V_66 ) ;
if ( error )
goto V_73;
error = F_43 ( V_52 ) ;
F_30 ( V_16 , V_49 ) ;
return error ;
V_73:
F_46 ( V_52 ) ;
F_30 ( V_16 , V_49 ) ;
V_59:
F_61 ( V_16 , error , V_74 ) ;
return error ;
}
int
F_62 (
struct V_15 * V_16 ,
T_8 V_45 ,
T_8 V_46 )
{
struct V_26 * V_27 = F_14 ( V_16 , V_28 ) ;
struct V_17 V_29 , V_67 ;
struct V_51 * V_52 ;
T_5 V_35 ;
T_5 V_47 ;
T_7 V_68 ;
struct V_37 V_38 ;
int error ;
unsigned int V_54 ;
T_6 V_75 ;
T_4 V_31 ;
F_63 ( V_16 , V_45 , V_46 ) ;
if ( V_27 -> V_71 == 0 )
return 0 ;
V_35 = F_26 ( V_16 -> V_21 , V_45 ) ;
V_47 = F_27 ( V_16 -> V_21 , V_45 + V_46 ) ;
F_64 ( V_76 > V_77 ) ;
if ( V_47 - V_35 > V_77 ) {
error = - V_78 ;
F_65 ( V_16 -> V_21 , V_79 ) ;
ASSERT ( 0 ) ;
goto V_59;
}
V_54 = F_66 ( V_16 -> V_21 ,
( unsigned int ) ( V_47 - V_35 ) ,
V_80 ) ;
error = F_37 ( V_16 -> V_21 , & F_38 ( V_16 -> V_21 ) -> V_60 ,
V_54 , 0 , 0 , & V_52 ) ;
if ( error )
goto V_59;
F_28 ( V_16 , V_49 ) ;
F_40 ( V_52 , V_16 , 0 ) ;
if ( ! F_15 ( V_16 , V_27 , V_47 - 1 , & V_31 , & V_29 ) ||
V_29 . V_32 > V_47 ) {
ASSERT ( V_31 > 0 ) ;
F_29 ( V_27 , -- V_31 , & V_29 ) ;
}
while ( V_29 . V_32 + V_29 . V_23 > V_35 ) {
V_67 = V_29 ;
F_17 ( & V_67 , V_35 , V_47 - V_35 ) ;
if ( ! V_67 . V_23 ) {
V_31 -- ;
goto V_81;
}
ASSERT ( ! F_33 ( V_29 . V_22 ) ) ;
if ( V_29 . V_41 == V_69 ) {
V_31 -- ;
goto V_81;
}
F_41 ( & V_38 , & V_68 ) ;
V_75 = V_67 . V_23 ;
error = F_67 ( V_52 , V_16 , V_67 . V_32 , & V_75 , 0 , 1 ,
& V_68 , & V_38 ) ;
if ( error )
goto V_82;
if ( V_75 ) {
F_17 ( & V_67 , V_67 . V_32 + V_75 ,
V_67 . V_23 - V_75 ) ;
}
F_68 ( V_16 , & V_67 ) ;
error = F_54 ( V_52 -> V_83 , & V_38 ,
V_67 . V_22 , V_67 . V_23 ) ;
if ( error )
goto V_82;
error = F_69 ( V_52 -> V_83 , & V_38 , V_16 , & V_67 ) ;
if ( error )
goto V_82;
F_57 ( V_16 , & V_31 , & V_29 , & V_67 ) ;
error = F_42 ( & V_52 , & V_38 , V_16 ) ;
if ( error )
goto V_82;
V_81:
if ( ! F_29 ( V_27 , V_31 , & V_29 ) )
break;
}
error = F_43 ( V_52 ) ;
F_30 ( V_16 , V_49 ) ;
if ( error )
goto V_59;
return 0 ;
V_82:
F_44 ( & V_38 ) ;
F_46 ( V_52 ) ;
F_30 ( V_16 , V_49 ) ;
V_59:
F_70 ( V_16 , error , V_74 ) ;
return error ;
}
int
F_71 (
struct V_1 * V_2 )
{
T_1 V_3 ;
int error = 0 ;
if ( ! F_72 ( & V_2 -> V_84 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_84 . V_85 ; V_3 ++ ) {
error = F_73 ( V_2 , V_3 ) ;
if ( error )
break;
}
return error ;
}
STATIC int
F_74 (
struct V_15 * V_86 ,
struct V_15 * V_87 )
{
struct V_1 * V_2 = V_86 -> V_21 ;
int error ;
struct V_51 * V_52 ;
if ( F_8 ( V_86 ) && F_8 ( V_87 ) )
return 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_88 , 0 , 0 , 0 , & V_52 ) ;
if ( error )
goto V_89;
if ( V_86 -> V_90 == V_87 -> V_90 )
F_28 ( V_86 , V_49 ) ;
else
F_75 ( V_86 , V_87 , V_49 ) ;
if ( ! F_8 ( V_86 ) ) {
F_76 ( V_86 ) ;
F_40 ( V_52 , V_86 , V_49 ) ;
V_86 -> V_91 . V_92 |= V_93 ;
F_77 ( V_52 , V_86 , V_94 ) ;
F_78 ( V_86 ) ;
} else
F_30 ( V_86 , V_49 ) ;
if ( V_86 -> V_90 == V_87 -> V_90 )
goto V_95;
if ( ! F_8 ( V_87 ) ) {
F_76 ( V_87 ) ;
F_40 ( V_52 , V_87 , V_49 ) ;
V_87 -> V_91 . V_92 |= V_93 ;
F_77 ( V_52 , V_87 , V_94 ) ;
F_78 ( V_87 ) ;
} else
F_30 ( V_87 , V_49 ) ;
V_95:
error = F_43 ( V_52 ) ;
if ( error )
goto V_89;
return error ;
V_89:
F_79 ( V_87 , error , V_74 ) ;
return error ;
}
STATIC int
F_80 (
struct V_15 * V_87 ,
T_8 V_96 ,
T_3 V_97 ,
bool V_98 )
{
struct V_1 * V_2 = V_87 -> V_21 ;
struct V_51 * V_52 ;
int error ;
if ( V_98 && V_96 <= F_81 ( F_82 ( V_87 ) ) && V_97 == 0 )
return 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_88 , 0 , 0 , 0 , & V_52 ) ;
if ( error )
goto V_89;
F_28 ( V_87 , V_49 ) ;
F_40 ( V_52 , V_87 , V_49 ) ;
if ( V_96 > F_81 ( F_82 ( V_87 ) ) ) {
F_83 ( V_87 , V_96 ) ;
F_84 ( F_82 ( V_87 ) , V_96 ) ;
V_87 -> V_91 . V_99 = V_96 ;
}
if ( V_97 ) {
V_87 -> V_91 . V_100 = V_97 ;
V_87 -> V_91 . V_92 |= V_101 ;
}
if ( ! V_98 ) {
F_85 ( V_52 , V_87 ,
V_102 | V_103 ) ;
}
F_77 ( V_52 , V_87 , V_94 ) ;
error = F_43 ( V_52 ) ;
if ( error )
goto V_89;
return error ;
V_89:
F_86 ( V_87 , error , V_74 ) ;
return error ;
}
static int
F_87 (
struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_104 * V_105 ;
int error = 0 ;
if ( ! F_88 ( & V_2 -> V_84 ) )
return 0 ;
V_105 = F_89 ( V_2 , V_3 ) ;
if ( F_90 ( V_105 , V_106 ) ||
F_90 ( V_105 , V_107 ) )
error = - V_33 ;
F_91 ( V_105 ) ;
return error ;
}
STATIC int
F_92 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_5 V_108 ,
T_8 V_109 )
{
struct V_1 * V_2 = V_16 -> V_21 ;
bool V_110 = F_9 ( V_18 ) ;
struct V_51 * V_52 ;
T_7 V_68 ;
unsigned int V_54 ;
struct V_37 V_38 ;
struct V_17 V_111 ;
T_6 V_75 ;
T_6 V_112 ;
T_8 V_96 ;
int error ;
V_112 = V_18 -> V_32 + V_18 -> V_23 - V_108 ;
F_93 ( V_16 , V_108 , V_112 ) ;
if ( V_110 ) {
error = F_87 ( V_2 ,
F_11 ( V_2 , V_18 -> V_22 ) ) ;
if ( error )
goto V_59;
}
V_54 = F_94 ( V_16 -> V_21 , V_80 ) ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_60 , V_54 , 0 , 0 , & V_52 ) ;
if ( error )
goto V_59;
F_28 ( V_16 , V_49 ) ;
F_40 ( V_52 , V_16 , 0 ) ;
if ( V_110 ) {
error = F_39 ( V_52 , V_16 ,
V_18 -> V_23 , 0 , V_61 ) ;
if ( error )
goto V_73;
}
F_95 ( V_16 , V_18 -> V_32 ,
V_18 -> V_23 , V_18 -> V_22 ) ;
V_75 = V_112 ;
while ( V_75 ) {
F_41 ( & V_38 , & V_68 ) ;
error = F_67 ( V_52 , V_16 , V_108 , & V_75 , 0 , 1 ,
& V_68 , & V_38 ) ;
if ( error )
goto V_82;
V_111 . V_22 = V_18 -> V_22 + V_75 ;
V_111 . V_32 = V_18 -> V_32 + V_75 ;
V_111 . V_23 = V_112 - V_75 ;
V_112 = V_75 ;
if ( ! V_110 || V_111 . V_23 == 0 )
goto V_81;
F_95 ( V_16 , V_111 . V_32 ,
V_111 . V_23 , V_111 . V_22 ) ;
error = F_96 ( V_2 , & V_38 , & V_111 ) ;
if ( error )
goto V_82;
error = F_69 ( V_2 , & V_38 , V_16 , & V_111 ) ;
if ( error )
goto V_82;
F_56 ( V_52 , V_16 , V_70 ,
V_111 . V_23 ) ;
V_96 = F_97 ( V_2 ,
V_111 . V_32 + V_111 . V_23 ) ;
V_96 = F_98 ( T_8 , V_96 , V_109 ) ;
if ( V_96 > F_81 ( F_82 ( V_16 ) ) ) {
F_83 ( V_16 , V_96 ) ;
F_84 ( F_82 ( V_16 ) , V_96 ) ;
V_16 -> V_91 . V_99 = V_96 ;
F_77 ( V_52 , V_16 , V_94 ) ;
}
V_81:
error = F_42 ( & V_52 , & V_38 , V_16 ) ;
if ( error )
goto V_82;
}
error = F_43 ( V_52 ) ;
F_30 ( V_16 , V_49 ) ;
if ( error )
goto V_59;
return 0 ;
V_82:
F_44 ( & V_38 ) ;
V_73:
F_46 ( V_52 ) ;
F_30 ( V_16 , V_49 ) ;
V_59:
F_99 ( V_16 , error , V_74 ) ;
return error ;
}
STATIC int
F_100 (
struct V_15 * V_86 ,
T_5 V_113 ,
struct V_15 * V_87 ,
T_5 V_108 ,
T_6 V_114 ,
T_8 V_109 )
{
struct V_17 V_25 ;
int V_40 ;
int error = 0 ;
T_6 V_115 ;
while ( V_114 ) {
F_101 ( V_86 , V_113 , V_114 ,
V_87 , V_108 ) ;
V_40 = 1 ;
F_28 ( V_86 , V_49 ) ;
error = F_102 ( V_86 , V_113 , V_114 , & V_25 , & V_40 , 0 ) ;
F_30 ( V_86 , V_49 ) ;
if ( error )
goto V_116;
ASSERT ( V_40 == 1 ) ;
F_103 ( V_86 , V_113 , V_114 , V_64 ,
& V_25 ) ;
V_115 = V_25 . V_32 + V_25 . V_23 - V_113 ;
V_25 . V_32 += V_108 - V_113 ;
error = F_92 ( V_87 , & V_25 , V_108 ,
V_109 ) ;
if ( error )
goto V_116;
if ( F_104 ( V_117 ) ) {
error = - V_118 ;
goto V_116;
}
V_113 += V_115 ;
V_108 += V_115 ;
V_114 -= V_115 ;
}
return 0 ;
V_116:
F_105 ( V_87 , error , V_74 ) ;
return error ;
}
int
F_106 (
struct V_119 * V_120 ,
T_10 V_121 ,
struct V_119 * V_122 ,
T_10 V_123 ,
T_11 V_114 ,
bool V_98 )
{
struct V_124 * V_125 = F_107 ( V_120 ) ;
struct V_15 * V_86 = F_108 ( V_125 ) ;
struct V_124 * V_126 = F_107 ( V_122 ) ;
struct V_15 * V_87 = F_108 ( V_126 ) ;
struct V_1 * V_2 = V_86 -> V_21 ;
bool V_127 = ( V_125 == V_126 ) ;
T_5 V_128 , V_129 ;
T_6 V_130 ;
T_3 V_97 ;
T_12 V_131 ;
if ( ! F_72 ( & V_2 -> V_84 ) )
return - V_132 ;
if ( F_109 ( V_2 ) )
return - V_133 ;
F_110 ( V_125 , V_126 ) ;
if ( V_127 )
F_28 ( V_86 , V_134 ) ;
else
F_75 ( V_86 , V_87 , V_134 ) ;
V_131 = - V_135 ;
if ( F_111 ( V_86 ) || F_111 ( V_87 ) )
goto V_136;
if ( F_112 ( V_125 ) || F_112 ( V_126 ) )
goto V_136;
V_131 = F_113 ( V_125 , V_121 , V_126 , V_123 ,
& V_114 , V_98 ) ;
if ( V_131 <= 0 )
goto V_136;
F_114 ( V_86 , V_121 , V_114 , V_87 , V_123 ) ;
V_131 = F_74 ( V_86 , V_87 ) ;
if ( V_131 )
goto V_136;
V_129 = F_26 ( V_2 , V_123 ) ;
V_128 = F_26 ( V_2 , V_121 ) ;
V_130 = F_27 ( V_2 , V_114 ) ;
V_131 = F_100 ( V_86 , V_128 , V_87 , V_129 , V_130 ,
V_123 + V_114 ) ;
if ( V_131 )
goto V_136;
F_115 ( & V_126 -> V_137 , V_123 ,
F_116 ( V_123 + V_114 ) - 1 ) ;
V_97 = 0 ;
if ( V_121 == 0 && V_114 == F_81 ( V_125 ) &&
( V_86 -> V_91 . V_92 & V_101 ) &&
V_123 == 0 && V_114 >= F_81 ( V_126 ) &&
! ( V_87 -> V_91 . V_92 & V_101 ) )
V_97 = V_86 -> V_91 . V_100 ;
V_131 = F_80 ( V_87 , V_123 + V_114 , V_97 ,
V_98 ) ;
V_136:
F_30 ( V_86 , V_134 ) ;
if ( ! V_127 )
F_30 ( V_87 , V_134 ) ;
F_117 ( V_125 , V_126 ) ;
if ( V_131 )
F_118 ( V_87 , V_131 , V_74 ) ;
return V_131 ;
}
STATIC int
F_119 (
struct V_15 * V_16 ,
T_5 V_6 ,
T_6 V_138 ,
T_8 V_139 )
{
struct V_1 * V_2 = V_16 -> V_21 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_140 ;
T_3 V_75 ;
T_8 V_141 ;
T_8 V_7 ;
struct V_17 V_142 [ 2 ] ;
int V_143 ;
int error = 0 ;
while ( V_138 - V_6 > 0 ) {
V_143 = 1 ;
error = F_102 ( V_16 , V_6 , V_138 - V_6 , V_142 , & V_143 , 0 ) ;
if ( error )
goto V_59;
if ( V_143 == 0 )
break;
if ( ! F_9 ( & V_142 [ 0 ] ) )
goto V_144;
V_142 [ 1 ] = V_142 [ 0 ] ;
while ( V_142 [ 1 ] . V_23 ) {
V_3 = F_11 ( V_2 , V_142 [ 1 ] . V_22 ) ;
V_4 = F_12 ( V_2 , V_142 [ 1 ] . V_22 ) ;
V_5 = V_142 [ 1 ] . V_23 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_140 , & V_75 , true ) ;
if ( error )
goto V_59;
if ( V_140 == V_24 )
break;
F_30 ( V_16 , V_49 ) ;
V_141 = F_97 ( V_2 , V_142 [ 1 ] . V_32 +
( V_140 - V_4 ) ) ;
V_7 = F_97 ( V_2 , V_75 ) ;
if ( V_141 + V_7 > V_139 )
V_7 = V_139 - V_141 ;
error = F_120 ( F_82 ( V_16 ) , V_141 , V_7 ,
& V_145 ) ;
F_28 ( V_16 , V_49 ) ;
if ( error )
goto V_59;
V_142 [ 1 ] . V_23 -= ( V_140 - V_4 + V_75 ) ;
V_142 [ 1 ] . V_32 += ( V_140 - V_4 + V_75 ) ;
V_142 [ 1 ] . V_22 += ( V_140 - V_4 + V_75 ) ;
}
V_144:
V_6 = V_142 [ 0 ] . V_32 + V_142 [ 0 ] . V_23 ;
}
V_59:
return error ;
}
int
F_121 (
struct V_15 * V_16 ,
struct V_51 * * V_65 )
{
struct V_1 * V_2 = V_16 -> V_21 ;
T_5 V_6 ;
T_6 V_138 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_140 ;
T_3 V_75 ;
struct V_17 V_142 ;
int V_143 ;
int error = 0 ;
ASSERT ( F_8 ( V_16 ) ) ;
V_6 = 0 ;
V_138 = F_27 ( V_2 , F_81 ( F_82 ( V_16 ) ) ) ;
while ( V_138 - V_6 > 0 ) {
V_143 = 1 ;
error = F_102 ( V_16 , V_6 , V_138 - V_6 , & V_142 , & V_143 , 0 ) ;
if ( error )
return error ;
if ( V_143 == 0 )
break;
if ( ! F_9 ( & V_142 ) )
goto V_144;
V_3 = F_11 ( V_2 , V_142 . V_22 ) ;
V_4 = F_12 ( V_2 , V_142 . V_22 ) ;
V_5 = V_142 . V_23 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_140 , & V_75 , false ) ;
if ( error )
return error ;
if ( V_140 != V_24 )
return 0 ;
V_144:
V_6 = V_142 . V_32 + V_142 . V_23 ;
}
error = F_51 ( V_16 , V_65 , 0 , V_72 , true ) ;
if ( error )
return error ;
F_122 ( V_16 ) ;
V_16 -> V_91 . V_92 &= ~ V_93 ;
F_58 ( V_16 ) ;
F_40 ( * V_65 , V_16 , 0 ) ;
F_77 ( * V_65 , V_16 , V_94 ) ;
return error ;
}
STATIC int
F_123 (
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_21 ;
struct V_51 * V_52 ;
int error = 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_60 , 0 , 0 , 0 , & V_52 ) ;
if ( error )
return error ;
F_28 ( V_16 , V_49 ) ;
F_40 ( V_52 , V_16 , 0 ) ;
error = F_121 ( V_16 , & V_52 ) ;
if ( error )
goto V_146;
error = F_43 ( V_52 ) ;
if ( error )
goto V_59;
F_30 ( V_16 , V_49 ) ;
return 0 ;
V_146:
F_46 ( V_52 ) ;
V_59:
F_30 ( V_16 , V_49 ) ;
return error ;
}
int
F_124 (
struct V_15 * V_16 ,
T_8 V_45 ,
T_8 V_114 )
{
struct V_1 * V_2 = V_16 -> V_21 ;
T_5 V_6 ;
T_6 V_138 ;
T_8 V_139 ;
int error ;
if ( ! F_8 ( V_16 ) )
return 0 ;
F_125 ( V_16 , V_45 , V_114 ) ;
F_126 ( F_82 ( V_16 ) ) ;
F_28 ( V_16 , V_49 ) ;
V_6 = F_26 ( V_2 , V_45 ) ;
V_139 = F_81 ( F_82 ( V_16 ) ) ;
V_138 = F_27 ( V_2 , V_45 + V_114 ) ;
error = F_119 ( V_16 , V_6 , V_138 , V_139 ) ;
if ( error )
goto V_136;
F_30 ( V_16 , V_49 ) ;
error = F_127 ( F_82 ( V_16 ) -> V_147 ) ;
if ( error )
goto V_59;
error = F_123 ( V_16 ) ;
if ( error )
goto V_59;
return 0 ;
V_136:
F_30 ( V_16 , V_49 ) ;
V_59:
F_128 ( V_16 , error , V_74 ) ;
return error ;
}
