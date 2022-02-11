int
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
T_2 V_6 ,
T_3 V_7 ,
T_2 * V_8 ,
T_3 * V_9 ,
bool V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int error ;
error = F_2 ( V_2 , V_4 , V_5 , 0 , & V_12 ) ;
if ( error )
return error ;
if ( ! V_12 )
return - V_15 ;
V_14 = F_3 ( V_2 , V_4 , V_12 , V_5 , NULL ) ;
error = F_4 ( V_14 , V_6 , V_7 , V_8 , V_9 ,
V_10 ) ;
F_5 ( V_14 , error ? V_16 : V_17 ) ;
F_6 ( V_4 , V_12 ) ;
return error ;
}
int
F_7 (
struct V_18 * V_19 ,
struct V_20 * V_21 ,
bool * V_22 ,
bool * V_23 )
{
T_1 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
T_2 V_8 ;
T_3 V_9 ;
int error = 0 ;
if ( ! F_8 ( V_19 ) || ! F_9 ( V_21 ) ) {
* V_22 = false ;
return 0 ;
}
F_10 ( V_19 , V_21 ) ;
V_5 = F_11 ( V_19 -> V_24 , V_21 -> V_25 ) ;
V_6 = F_12 ( V_19 -> V_24 , V_21 -> V_25 ) ;
V_7 = V_21 -> V_26 ;
error = F_1 ( V_19 -> V_24 , NULL , V_5 , V_6 ,
V_7 , & V_8 , & V_9 , true ) ;
if ( error )
return error ;
* V_22 = * V_23 = false ;
if ( V_8 == V_27 ) {
return 0 ;
} else if ( V_8 == V_6 ) {
V_21 -> V_26 = V_9 ;
* V_22 = true ;
if ( V_9 != V_7 )
* V_23 = true ;
return 0 ;
} else {
V_21 -> V_26 = V_8 - V_6 ;
* V_23 = true ;
return 0 ;
}
}
int
F_13 (
struct V_18 * V_19 ,
struct V_20 * V_28 ,
bool * V_22 )
{
struct V_29 * V_30 = F_14 ( V_19 , V_31 ) ;
struct V_20 V_32 ;
int error = 0 ;
bool V_33 = false , V_23 ;
T_4 V_34 ;
if ( ! F_15 ( V_19 , V_30 , V_28 -> V_35 , & V_34 , & V_32 ) )
V_33 = true ;
if ( ! V_33 && V_32 . V_35 <= V_28 -> V_35 ) {
F_16 ( V_19 , V_28 ) ;
F_17 ( V_28 , V_32 . V_35 , V_32 . V_26 ) ;
* V_22 = true ;
return 0 ;
}
error = F_7 ( V_19 , V_28 , V_22 , & V_23 ) ;
if ( error )
return error ;
if ( ! * V_22 )
return 0 ;
error = F_18 ( V_19 , 0 ) ;
if ( error )
return error ;
error = F_19 ( V_19 , V_31 , V_28 -> V_35 ,
V_28 -> V_26 , 0 , & V_32 , & V_34 , V_33 ) ;
if ( error == - V_36 || error == - V_37 )
F_20 ( V_19 , V_28 ) ;
if ( error )
return error ;
F_21 ( V_19 , & V_32 ) ;
return 0 ;
}
STATIC int
F_22 (
struct V_18 * V_19 ,
struct V_20 * V_28 ,
T_5 V_38 ,
T_6 V_39 ,
struct V_40 * V_41 )
{
T_7 V_42 = V_43 ;
int V_44 = 1 ;
if ( V_28 -> V_45 == V_46 )
return 0 ;
F_17 ( V_28 , V_38 , V_39 ) ;
F_23 ( V_19 , V_28 ) ;
if ( V_28 -> V_26 == 0 )
return 0 ;
return F_24 ( NULL , V_19 , V_28 -> V_35 , V_28 -> V_26 ,
V_47 | V_48 , & V_42 ,
0 , V_28 , & V_44 , V_41 ) ;
}
int
F_25 (
struct V_18 * V_19 ,
T_8 V_49 ,
T_8 V_50 )
{
struct V_20 V_32 ;
struct V_40 V_41 ;
struct V_1 * V_2 = V_19 -> V_24 ;
struct V_29 * V_30 = F_14 ( V_19 , V_31 ) ;
T_5 V_38 = F_26 ( V_2 , V_49 ) ;
T_5 V_51 = F_27 ( V_2 , V_49 + V_50 ) ;
T_4 V_34 ;
bool V_52 ;
int error = 0 ;
F_28 ( V_19 , V_53 ) ;
for ( V_52 = F_15 ( V_19 , V_30 , V_38 , & V_34 , & V_32 ) ;
V_52 && V_32 . V_35 < V_51 ;
V_52 = F_29 ( V_30 , ++ V_34 , & V_32 ) ) {
error = F_22 ( V_19 , & V_32 , V_38 ,
V_51 - V_38 , & V_41 ) ;
if ( error )
break;
}
F_30 ( V_19 , V_53 ) ;
return error ;
}
int
F_31 (
struct V_18 * V_19 ,
struct V_20 * V_28 ,
bool * V_22 ,
T_9 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_24 ;
T_5 V_38 = V_28 -> V_35 ;
T_6 V_39 = V_28 -> V_26 ;
struct V_20 V_32 ;
struct V_40 V_41 ;
struct V_3 * V_4 = NULL ;
T_7 V_42 ;
int V_44 , error = 0 ;
bool V_23 ;
T_6 V_55 ;
T_3 V_56 = 0 ;
T_4 V_34 ;
V_57:
ASSERT ( F_8 ( V_19 ) ) ;
ASSERT ( F_32 ( V_19 , V_53 | V_58 ) ) ;
if ( F_15 ( V_19 , V_19 -> V_59 , V_38 , & V_34 , & V_32 ) &&
V_32 . V_35 <= V_38 ) {
* V_22 = true ;
if ( ! F_33 ( V_32 . V_25 ) ) {
F_17 ( & V_32 , V_38 , V_39 ) ;
* V_28 = V_32 ;
goto V_60;
}
F_17 ( V_28 , V_32 . V_35 , V_32 . V_26 ) ;
} else {
error = F_7 ( V_19 , V_28 , V_22 , & V_23 ) ;
if ( error || ! * V_22 )
goto V_61;
}
if ( ! V_4 ) {
V_55 = F_34 ( V_28 -> V_35 ,
V_28 -> V_26 , F_35 ( V_19 ) ) ;
V_56 = F_36 ( V_2 , V_55 ) ;
F_30 ( V_19 , * V_54 ) ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_62 , V_56 , 0 , 0 , & V_4 ) ;
* V_54 = V_53 ;
F_28 ( V_19 , * V_54 ) ;
if ( error )
return error ;
error = F_18 ( V_19 , 0 ) ;
if ( error )
goto V_61;
goto V_57;
}
error = F_39 ( V_4 , V_19 , V_56 , 0 ,
V_63 ) ;
if ( error )
goto V_61;
F_40 ( V_4 , V_19 , 0 ) ;
F_41 ( & V_41 , & V_42 ) ;
V_44 = 1 ;
error = F_24 ( V_4 , V_19 , V_28 -> V_35 , V_28 -> V_26 ,
V_47 | V_64 , & V_42 ,
V_56 , V_28 , & V_44 , & V_41 ) ;
if ( error )
goto V_65;
error = F_42 ( & V_4 , & V_41 ) ;
if ( error )
goto V_65;
error = F_43 ( V_4 ) ;
if ( error )
return error ;
V_60:
return F_22 ( V_19 , V_28 , V_38 , V_39 ,
& V_41 ) ;
V_65:
F_44 ( & V_41 ) ;
F_45 ( V_4 , V_19 , ( long ) V_56 , 0 ,
V_63 ) ;
V_61:
if ( V_4 )
F_46 ( V_4 ) ;
return error ;
}
bool
F_47 (
struct V_18 * V_19 ,
T_8 V_49 ,
struct V_20 * V_28 )
{
struct V_29 * V_30 = F_14 ( V_19 , V_31 ) ;
T_5 V_38 ;
struct V_20 V_32 ;
T_4 V_34 ;
ASSERT ( F_32 ( V_19 , V_53 | V_58 ) ) ;
ASSERT ( F_8 ( V_19 ) ) ;
V_38 = F_26 ( V_19 -> V_24 , V_49 ) ;
if ( ! F_15 ( V_19 , V_30 , V_38 , & V_34 , & V_32 ) )
return false ;
if ( V_32 . V_35 > V_38 )
return false ;
F_48 ( V_19 , V_49 , 1 , V_66 ,
& V_32 ) ;
* V_28 = V_32 ;
return true ;
}
void
F_49 (
struct V_18 * V_19 ,
T_5 V_38 ,
struct V_20 * V_28 )
{
struct V_29 * V_30 = F_14 ( V_19 , V_31 ) ;
struct V_20 V_32 ;
T_4 V_34 ;
if ( ! F_8 ( V_19 ) )
return;
if ( ! F_15 ( V_19 , V_30 , V_38 , & V_34 , & V_32 ) )
return;
if ( V_32 . V_35 < V_38 ) {
if ( ! F_29 ( V_30 , V_34 + 1 , & V_32 ) )
return;
}
if ( V_32 . V_35 >= V_28 -> V_35 + V_28 -> V_26 )
return;
V_28 -> V_26 = V_32 . V_35 - V_28 -> V_35 ;
F_50 ( V_19 , V_28 ) ;
}
int
F_51 (
struct V_18 * V_19 ,
struct V_3 * * V_67 ,
T_5 V_38 ,
T_5 V_51 ,
bool V_68 )
{
struct V_29 * V_30 = F_14 ( V_19 , V_31 ) ;
struct V_20 V_32 , V_69 ;
T_4 V_34 ;
T_7 V_70 ;
struct V_40 V_41 ;
int error = 0 ;
if ( ! F_8 ( V_19 ) )
return 0 ;
if ( ! F_15 ( V_19 , V_30 , V_38 , & V_34 , & V_32 ) )
return 0 ;
while ( V_32 . V_35 < V_51 ) {
V_69 = V_32 ;
F_17 ( & V_69 , V_38 , V_51 - V_38 ) ;
F_52 ( V_19 , & V_69 ) ;
if ( F_33 ( V_69 . V_25 ) ) {
error = F_53 ( V_19 , V_31 ,
& V_34 , & V_32 , & V_69 ) ;
if ( error )
break;
} else if ( V_69 . V_45 == V_71 || V_68 ) {
F_40 ( * V_67 , V_19 , 0 ) ;
F_41 ( & V_41 , & V_70 ) ;
error = F_54 ( V_19 -> V_24 ,
& V_41 , V_69 . V_25 ,
V_69 . V_26 ) ;
if ( error )
break;
F_55 ( V_19 -> V_24 , & V_41 ,
V_69 . V_25 , V_69 . V_26 ,
NULL ) ;
F_56 ( * V_67 , V_19 , V_72 ,
- ( long ) V_69 . V_26 ) ;
F_57 ( & V_41 , V_19 ) ;
error = F_42 ( V_67 , & V_41 ) ;
if ( error ) {
F_44 ( & V_41 ) ;
break;
}
F_58 ( V_19 , & V_34 , & V_32 , & V_69 ) ;
}
if ( ! F_29 ( V_30 , ++ V_34 , & V_32 ) )
break;
}
if ( ! V_30 -> V_73 )
F_59 ( V_19 ) ;
return error ;
}
int
F_60 (
struct V_18 * V_19 ,
T_8 V_49 ,
T_8 V_50 ,
bool V_68 )
{
struct V_3 * V_4 ;
T_5 V_38 ;
T_5 V_51 ;
int error ;
F_61 ( V_19 , V_49 , V_50 ) ;
ASSERT ( F_8 ( V_19 ) ) ;
V_38 = F_26 ( V_19 -> V_24 , V_49 ) ;
if ( V_50 == V_74 )
V_51 = V_74 ;
else
V_51 = F_27 ( V_19 -> V_24 , V_49 + V_50 ) ;
error = F_37 ( V_19 -> V_24 , & F_38 ( V_19 -> V_24 ) -> V_62 ,
0 , 0 , 0 , & V_4 ) ;
if ( error )
goto V_61;
F_28 ( V_19 , V_53 ) ;
F_40 ( V_4 , V_19 , 0 ) ;
error = F_51 ( V_19 , & V_4 , V_38 , V_51 ,
V_68 ) ;
if ( error )
goto V_75;
error = F_43 ( V_4 ) ;
F_30 ( V_19 , V_53 ) ;
return error ;
V_75:
F_46 ( V_4 ) ;
F_30 ( V_19 , V_53 ) ;
V_61:
F_62 ( V_19 , error , V_76 ) ;
return error ;
}
int
F_63 (
struct V_18 * V_19 ,
T_8 V_49 ,
T_8 V_50 )
{
struct V_29 * V_30 = F_14 ( V_19 , V_31 ) ;
struct V_20 V_32 , V_69 ;
struct V_3 * V_4 ;
T_5 V_38 ;
T_5 V_51 ;
T_7 V_70 ;
struct V_40 V_41 ;
int error ;
unsigned int V_56 ;
T_6 V_77 ;
T_4 V_34 ;
F_64 ( V_19 , V_49 , V_50 ) ;
if ( V_30 -> V_73 == 0 )
return 0 ;
V_38 = F_26 ( V_19 -> V_24 , V_49 ) ;
V_51 = F_27 ( V_19 -> V_24 , V_49 + V_50 ) ;
F_65 ( V_78 > V_79 ) ;
if ( V_51 - V_38 > V_79 ) {
error = - V_80 ;
F_66 ( V_19 -> V_24 , V_81 ) ;
ASSERT ( 0 ) ;
goto V_61;
}
V_56 = F_67 ( V_19 -> V_24 ,
( unsigned int ) ( V_51 - V_38 ) ,
V_82 ) ;
error = F_37 ( V_19 -> V_24 , & F_38 ( V_19 -> V_24 ) -> V_62 ,
V_56 , 0 , 0 , & V_4 ) ;
if ( error )
goto V_61;
F_28 ( V_19 , V_53 ) ;
F_40 ( V_4 , V_19 , 0 ) ;
if ( ! F_15 ( V_19 , V_30 , V_51 - 1 , & V_34 , & V_32 ) ||
V_32 . V_35 > V_51 ) {
if ( V_34 <= 0 )
goto V_75;
F_29 ( V_30 , -- V_34 , & V_32 ) ;
}
while ( V_32 . V_35 + V_32 . V_26 > V_38 ) {
V_69 = V_32 ;
F_17 ( & V_69 , V_38 , V_51 - V_38 ) ;
if ( ! V_69 . V_26 ) {
V_34 -- ;
goto V_83;
}
ASSERT ( ! F_33 ( V_32 . V_25 ) ) ;
if ( V_32 . V_45 == V_71 ) {
V_34 -- ;
goto V_83;
}
F_41 ( & V_41 , & V_70 ) ;
V_77 = V_69 . V_26 ;
error = F_68 ( V_4 , V_19 , V_69 . V_35 , & V_77 , 0 , 1 ,
& V_70 , & V_41 ) ;
if ( error )
goto V_84;
if ( V_77 ) {
F_17 ( & V_69 , V_69 . V_35 + V_77 ,
V_69 . V_26 - V_77 ) ;
}
F_69 ( V_19 , & V_69 ) ;
error = F_54 ( V_4 -> V_85 , & V_41 ,
V_69 . V_25 , V_69 . V_26 ) ;
if ( error )
goto V_84;
error = F_70 ( V_4 -> V_85 , & V_41 , V_19 , & V_69 ) ;
if ( error )
goto V_84;
F_58 ( V_19 , & V_34 , & V_32 , & V_69 ) ;
F_57 ( & V_41 , V_19 ) ;
error = F_42 ( & V_4 , & V_41 ) ;
if ( error )
goto V_84;
V_83:
if ( ! F_29 ( V_30 , V_34 , & V_32 ) )
break;
}
error = F_43 ( V_4 ) ;
F_30 ( V_19 , V_53 ) ;
if ( error )
goto V_61;
return 0 ;
V_84:
F_44 ( & V_41 ) ;
V_75:
F_46 ( V_4 ) ;
F_30 ( V_19 , V_53 ) ;
V_61:
F_71 ( V_19 , error , V_76 ) ;
return error ;
}
int
F_72 (
struct V_1 * V_2 )
{
T_1 V_5 ;
int error = 0 ;
if ( ! F_73 ( & V_2 -> V_86 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_86 . V_87 ; V_5 ++ ) {
error = F_74 ( V_2 , V_5 ) ;
if ( error )
break;
}
return error ;
}
STATIC int
F_75 (
struct V_18 * V_88 ,
struct V_18 * V_89 )
{
struct V_1 * V_2 = V_88 -> V_24 ;
int error ;
struct V_3 * V_4 ;
if ( F_8 ( V_88 ) && F_8 ( V_89 ) )
return 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_90 , 0 , 0 , 0 , & V_4 ) ;
if ( error )
goto V_91;
if ( V_88 -> V_92 == V_89 -> V_92 )
F_28 ( V_88 , V_53 ) ;
else
F_76 ( V_88 , V_89 , V_53 ) ;
if ( ! F_8 ( V_88 ) ) {
F_77 ( V_88 ) ;
F_40 ( V_4 , V_88 , V_53 ) ;
V_88 -> V_93 . V_94 |= V_95 ;
F_78 ( V_4 , V_88 , V_96 ) ;
F_79 ( V_88 ) ;
} else
F_30 ( V_88 , V_53 ) ;
if ( V_88 -> V_92 == V_89 -> V_92 )
goto V_97;
if ( ! F_8 ( V_89 ) ) {
F_77 ( V_89 ) ;
F_40 ( V_4 , V_89 , V_53 ) ;
V_89 -> V_93 . V_94 |= V_95 ;
F_78 ( V_4 , V_89 , V_96 ) ;
F_79 ( V_89 ) ;
} else
F_30 ( V_89 , V_53 ) ;
V_97:
error = F_43 ( V_4 ) ;
if ( error )
goto V_91;
return error ;
V_91:
F_80 ( V_89 , error , V_76 ) ;
return error ;
}
STATIC int
F_81 (
struct V_18 * V_89 ,
T_8 V_98 ,
T_3 V_99 ,
bool V_100 )
{
struct V_1 * V_2 = V_89 -> V_24 ;
struct V_3 * V_4 ;
int error ;
if ( V_100 && V_98 <= F_82 ( F_83 ( V_89 ) ) && V_99 == 0 )
return 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_90 , 0 , 0 , 0 , & V_4 ) ;
if ( error )
goto V_91;
F_28 ( V_89 , V_53 ) ;
F_40 ( V_4 , V_89 , V_53 ) ;
if ( V_98 > F_82 ( F_83 ( V_89 ) ) ) {
F_84 ( V_89 , V_98 ) ;
F_85 ( F_83 ( V_89 ) , V_98 ) ;
V_89 -> V_93 . V_101 = V_98 ;
}
if ( V_99 ) {
V_89 -> V_93 . V_102 = V_99 ;
V_89 -> V_93 . V_94 |= V_103 ;
}
if ( ! V_100 ) {
F_86 ( V_4 , V_89 ,
V_104 | V_105 ) ;
}
F_78 ( V_4 , V_89 , V_96 ) ;
error = F_43 ( V_4 ) ;
if ( error )
goto V_91;
return error ;
V_91:
F_87 ( V_89 , error , V_76 ) ;
return error ;
}
static int
F_88 (
struct V_1 * V_2 ,
T_1 V_5 )
{
struct V_106 * V_107 ;
int error = 0 ;
if ( ! F_89 ( & V_2 -> V_86 ) )
return 0 ;
V_107 = F_90 ( V_2 , V_5 ) ;
if ( F_91 ( V_107 , V_108 ) ||
F_91 ( V_107 , V_109 ) )
error = - V_36 ;
F_92 ( V_107 ) ;
return error ;
}
STATIC int
F_93 (
struct V_18 * V_19 ,
struct V_20 * V_21 ,
T_5 V_110 ,
T_8 V_111 )
{
struct V_1 * V_2 = V_19 -> V_24 ;
bool V_112 = F_9 ( V_21 ) ;
struct V_3 * V_4 ;
T_7 V_70 ;
unsigned int V_56 ;
struct V_40 V_41 ;
struct V_20 V_113 ;
T_6 V_77 ;
T_6 V_114 ;
T_8 V_98 ;
int error ;
V_114 = V_21 -> V_35 + V_21 -> V_26 - V_110 ;
F_94 ( V_19 , V_110 , V_114 ) ;
if ( V_112 ) {
error = F_88 ( V_2 ,
F_11 ( V_2 , V_21 -> V_25 ) ) ;
if ( error )
goto V_61;
}
V_56 = F_95 ( V_19 -> V_24 , V_82 ) ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_62 , V_56 , 0 , 0 , & V_4 ) ;
if ( error )
goto V_61;
F_28 ( V_19 , V_53 ) ;
F_40 ( V_4 , V_19 , 0 ) ;
if ( V_112 ) {
error = F_39 ( V_4 , V_19 ,
V_21 -> V_26 , 0 , V_63 ) ;
if ( error )
goto V_75;
}
F_96 ( V_19 , V_21 -> V_35 ,
V_21 -> V_26 , V_21 -> V_25 ) ;
V_77 = V_114 ;
while ( V_77 ) {
F_41 ( & V_41 , & V_70 ) ;
error = F_68 ( V_4 , V_19 , V_110 , & V_77 , 0 , 1 ,
& V_70 , & V_41 ) ;
if ( error )
goto V_84;
V_113 . V_25 = V_21 -> V_25 + V_77 ;
V_113 . V_35 = V_21 -> V_35 + V_77 ;
V_113 . V_26 = V_114 - V_77 ;
V_114 = V_77 ;
if ( ! V_112 || V_113 . V_26 == 0 )
goto V_83;
F_96 ( V_19 , V_113 . V_35 ,
V_113 . V_26 , V_113 . V_25 ) ;
error = F_97 ( V_2 , & V_41 , & V_113 ) ;
if ( error )
goto V_84;
error = F_70 ( V_2 , & V_41 , V_19 , & V_113 ) ;
if ( error )
goto V_84;
F_56 ( V_4 , V_19 , V_72 ,
V_113 . V_26 ) ;
V_98 = F_98 ( V_2 ,
V_113 . V_35 + V_113 . V_26 ) ;
V_98 = F_99 ( T_8 , V_98 , V_111 ) ;
if ( V_98 > F_82 ( F_83 ( V_19 ) ) ) {
F_84 ( V_19 , V_98 ) ;
F_85 ( F_83 ( V_19 ) , V_98 ) ;
V_19 -> V_93 . V_101 = V_98 ;
F_78 ( V_4 , V_19 , V_96 ) ;
}
V_83:
F_57 ( & V_41 , V_19 ) ;
error = F_42 ( & V_4 , & V_41 ) ;
if ( error )
goto V_84;
}
error = F_43 ( V_4 ) ;
F_30 ( V_19 , V_53 ) ;
if ( error )
goto V_61;
return 0 ;
V_84:
F_44 ( & V_41 ) ;
V_75:
F_46 ( V_4 ) ;
F_30 ( V_19 , V_53 ) ;
V_61:
F_100 ( V_19 , error , V_76 ) ;
return error ;
}
STATIC int
F_101 (
struct V_18 * V_88 ,
T_5 V_115 ,
struct V_18 * V_89 ,
T_5 V_110 ,
T_6 V_116 ,
T_8 V_111 )
{
struct V_20 V_28 ;
int V_44 ;
int error = 0 ;
T_6 V_117 ;
while ( V_116 ) {
F_102 ( V_88 , V_115 , V_116 ,
V_89 , V_110 ) ;
V_44 = 1 ;
F_28 ( V_88 , V_53 ) ;
error = F_103 ( V_88 , V_115 , V_116 , & V_28 , & V_44 , 0 ) ;
F_30 ( V_88 , V_53 ) ;
if ( error )
goto V_118;
ASSERT ( V_44 == 1 ) ;
F_104 ( V_88 , V_115 , V_116 , V_66 ,
& V_28 ) ;
V_117 = V_28 . V_35 + V_28 . V_26 - V_115 ;
V_28 . V_35 += V_110 - V_115 ;
error = F_93 ( V_89 , & V_28 , V_110 ,
V_111 ) ;
if ( error )
goto V_118;
if ( F_105 ( V_119 ) ) {
error = - V_120 ;
goto V_118;
}
V_115 += V_117 ;
V_110 += V_117 ;
V_116 -= V_117 ;
}
return 0 ;
V_118:
F_106 ( V_89 , error , V_76 ) ;
return error ;
}
int
F_107 (
struct V_121 * V_122 ,
T_10 V_123 ,
struct V_121 * V_124 ,
T_10 V_125 ,
T_11 V_116 ,
bool V_100 )
{
struct V_126 * V_127 = F_108 ( V_122 ) ;
struct V_18 * V_88 = F_109 ( V_127 ) ;
struct V_126 * V_128 = F_108 ( V_124 ) ;
struct V_18 * V_89 = F_109 ( V_128 ) ;
struct V_1 * V_2 = V_88 -> V_24 ;
bool V_129 = ( V_127 == V_128 ) ;
T_5 V_130 , V_131 ;
T_6 V_132 ;
T_3 V_99 ;
T_12 V_133 ;
if ( ! F_73 ( & V_2 -> V_86 ) )
return - V_134 ;
if ( F_110 ( V_2 ) )
return - V_135 ;
F_111 ( V_127 , V_128 ) ;
if ( V_129 )
F_28 ( V_88 , V_136 ) ;
else
F_76 ( V_88 , V_89 , V_136 ) ;
V_133 = - V_137 ;
if ( F_112 ( V_88 ) || F_112 ( V_89 ) )
goto V_138;
if ( F_113 ( V_127 ) || F_113 ( V_128 ) )
goto V_138;
V_133 = F_114 ( V_127 , V_123 , V_128 , V_125 ,
& V_116 , V_100 ) ;
if ( V_133 <= 0 )
goto V_138;
F_115 ( V_88 , V_123 , V_116 , V_89 , V_125 ) ;
V_133 = F_75 ( V_88 , V_89 ) ;
if ( V_133 )
goto V_138;
V_131 = F_26 ( V_2 , V_125 ) ;
V_130 = F_26 ( V_2 , V_123 ) ;
V_132 = F_27 ( V_2 , V_116 ) ;
V_133 = F_101 ( V_88 , V_130 , V_89 , V_131 , V_132 ,
V_125 + V_116 ) ;
if ( V_133 )
goto V_138;
F_116 ( & V_128 -> V_139 , V_125 ,
F_117 ( V_125 + V_116 ) - 1 ) ;
V_99 = 0 ;
if ( V_123 == 0 && V_116 == F_82 ( V_127 ) &&
( V_88 -> V_93 . V_94 & V_103 ) &&
V_125 == 0 && V_116 >= F_82 ( V_128 ) &&
! ( V_89 -> V_93 . V_94 & V_103 ) )
V_99 = V_88 -> V_93 . V_102 ;
V_133 = F_81 ( V_89 , V_125 + V_116 , V_99 ,
V_100 ) ;
V_138:
F_30 ( V_88 , V_136 ) ;
if ( ! V_129 )
F_30 ( V_89 , V_136 ) ;
F_118 ( V_127 , V_128 ) ;
if ( V_133 )
F_119 ( V_89 , V_133 , V_76 ) ;
return V_133 ;
}
STATIC int
F_120 (
struct V_18 * V_19 ,
T_5 V_8 ,
T_6 V_140 ,
T_8 V_141 )
{
struct V_1 * V_2 = V_19 -> V_24 ;
T_1 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
T_2 V_142 ;
T_3 V_77 ;
T_8 V_143 ;
T_8 V_9 ;
struct V_20 V_144 [ 2 ] ;
int V_145 ;
int error = 0 ;
while ( V_140 - V_8 > 0 ) {
V_145 = 1 ;
error = F_103 ( V_19 , V_8 , V_140 - V_8 , V_144 , & V_145 , 0 ) ;
if ( error )
goto V_61;
if ( V_145 == 0 )
break;
if ( ! F_9 ( & V_144 [ 0 ] ) )
goto V_146;
V_144 [ 1 ] = V_144 [ 0 ] ;
while ( V_144 [ 1 ] . V_26 ) {
V_5 = F_11 ( V_2 , V_144 [ 1 ] . V_25 ) ;
V_6 = F_12 ( V_2 , V_144 [ 1 ] . V_25 ) ;
V_7 = V_144 [ 1 ] . V_26 ;
error = F_1 ( V_2 , NULL , V_5 , V_6 ,
V_7 , & V_142 , & V_77 , true ) ;
if ( error )
goto V_61;
if ( V_142 == V_27 )
break;
F_30 ( V_19 , V_53 ) ;
V_143 = F_98 ( V_2 , V_144 [ 1 ] . V_35 +
( V_142 - V_6 ) ) ;
V_9 = F_98 ( V_2 , V_77 ) ;
if ( V_143 + V_9 > V_141 )
V_9 = V_141 - V_143 ;
error = F_121 ( F_83 ( V_19 ) , V_143 , V_9 ,
& V_147 ) ;
F_28 ( V_19 , V_53 ) ;
if ( error )
goto V_61;
V_144 [ 1 ] . V_26 -= ( V_142 - V_6 + V_77 ) ;
V_144 [ 1 ] . V_35 += ( V_142 - V_6 + V_77 ) ;
V_144 [ 1 ] . V_25 += ( V_142 - V_6 + V_77 ) ;
}
V_146:
V_8 = V_144 [ 0 ] . V_35 + V_144 [ 0 ] . V_26 ;
}
V_61:
return error ;
}
int
F_122 (
struct V_3 * V_4 ,
struct V_18 * V_19 ,
bool * V_148 )
{
struct V_20 V_32 ;
struct V_1 * V_2 = V_19 -> V_24 ;
struct V_29 * V_30 ;
T_1 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
T_2 V_142 ;
T_3 V_77 ;
T_4 V_34 ;
bool V_52 ;
int error ;
V_30 = F_14 ( V_19 , V_82 ) ;
if ( ! ( V_30 -> V_149 & V_150 ) ) {
error = F_123 ( V_4 , V_19 , V_82 ) ;
if ( error )
return error ;
}
* V_148 = false ;
V_52 = F_15 ( V_19 , V_30 , 0 , & V_34 , & V_32 ) ;
while ( V_52 ) {
if ( F_33 ( V_32 . V_25 ) ||
V_32 . V_45 != V_46 )
goto V_146;
V_5 = F_11 ( V_2 , V_32 . V_25 ) ;
V_6 = F_12 ( V_2 , V_32 . V_25 ) ;
V_7 = V_32 . V_26 ;
error = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ,
& V_142 , & V_77 , false ) ;
if ( error )
return error ;
if ( V_142 != V_27 ) {
* V_148 = true ;
return 0 ;
}
V_146:
V_52 = F_29 ( V_30 , ++ V_34 , & V_32 ) ;
}
return 0 ;
}
int
F_124 (
struct V_18 * V_19 ,
struct V_3 * * V_67 )
{
bool V_151 ;
int error = 0 ;
ASSERT ( F_8 ( V_19 ) ) ;
error = F_122 ( * V_67 , V_19 , & V_151 ) ;
if ( error || V_151 )
return error ;
error = F_51 ( V_19 , V_67 , 0 , V_74 , true ) ;
if ( error )
return error ;
F_125 ( V_19 ) ;
V_19 -> V_93 . V_94 &= ~ V_95 ;
F_59 ( V_19 ) ;
F_40 ( * V_67 , V_19 , 0 ) ;
F_78 ( * V_67 , V_19 , V_96 ) ;
return error ;
}
STATIC int
F_126 (
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_24 ;
struct V_3 * V_4 ;
int error = 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_62 , 0 , 0 , 0 , & V_4 ) ;
if ( error )
return error ;
F_28 ( V_19 , V_53 ) ;
F_40 ( V_4 , V_19 , 0 ) ;
error = F_124 ( V_19 , & V_4 ) ;
if ( error )
goto V_152;
error = F_43 ( V_4 ) ;
if ( error )
goto V_61;
F_30 ( V_19 , V_53 ) ;
return 0 ;
V_152:
F_46 ( V_4 ) ;
V_61:
F_30 ( V_19 , V_53 ) ;
return error ;
}
int
F_127 (
struct V_18 * V_19 ,
T_8 V_49 ,
T_8 V_116 )
{
struct V_1 * V_2 = V_19 -> V_24 ;
T_5 V_8 ;
T_6 V_140 ;
T_8 V_141 ;
int error ;
if ( ! F_8 ( V_19 ) )
return 0 ;
F_128 ( V_19 , V_49 , V_116 ) ;
F_129 ( F_83 ( V_19 ) ) ;
F_28 ( V_19 , V_53 ) ;
V_8 = F_26 ( V_2 , V_49 ) ;
V_141 = F_82 ( F_83 ( V_19 ) ) ;
V_140 = F_27 ( V_2 , V_49 + V_116 ) ;
error = F_120 ( V_19 , V_8 , V_140 , V_141 ) ;
if ( error )
goto V_138;
F_30 ( V_19 , V_53 ) ;
error = F_130 ( F_83 ( V_19 ) -> V_153 ) ;
if ( error )
goto V_61;
error = F_126 ( V_19 ) ;
if ( error )
goto V_61;
return 0 ;
V_138:
F_30 ( V_19 , V_53 ) ;
V_61:
F_131 ( V_19 , error , V_76 ) ;
return error ;
}
