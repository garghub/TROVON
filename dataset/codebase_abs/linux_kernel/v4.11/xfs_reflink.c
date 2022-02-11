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
if ( ! F_8 ( V_16 ) ||
F_9 ( V_18 ) ||
V_18 -> V_21 == V_22 ||
V_18 -> V_21 == V_23 ||
F_10 ( V_18 -> V_21 ) ) {
* V_19 = false ;
return 0 ;
}
F_11 ( V_16 , V_18 ) ;
V_3 = F_12 ( V_16 -> V_24 , V_18 -> V_21 ) ;
V_4 = F_13 ( V_16 -> V_24 , V_18 -> V_21 ) ;
V_5 = V_18 -> V_25 ;
error = F_1 ( V_16 -> V_24 , V_3 , V_4 ,
V_5 , & V_6 , & V_7 , true ) ;
if ( error )
return error ;
* V_19 = * V_20 = false ;
if ( V_6 == V_26 ) {
return 0 ;
} else if ( V_6 == V_4 ) {
V_18 -> V_25 = V_7 ;
* V_19 = true ;
if ( V_7 != V_5 )
* V_20 = true ;
return 0 ;
} else {
V_18 -> V_25 = V_6 - V_4 ;
* V_20 = true ;
return 0 ;
}
}
int
F_14 (
struct V_15 * V_16 ,
struct V_17 * V_27 ,
bool * V_19 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
struct V_17 V_31 ;
int error = 0 ;
bool V_32 = false , V_20 ;
T_4 V_33 ;
if ( ! F_16 ( V_16 , V_29 , V_27 -> V_34 , & V_33 , & V_31 ) )
V_32 = true ;
if ( ! V_32 && V_31 . V_34 <= V_27 -> V_34 ) {
F_17 ( V_16 , V_27 ) ;
F_18 ( V_27 , V_31 . V_34 , V_31 . V_25 ) ;
* V_19 = true ;
return 0 ;
}
error = F_7 ( V_16 , V_27 , V_19 , & V_20 ) ;
if ( error )
return error ;
if ( ! * V_19 )
return 0 ;
error = F_19 ( V_16 , 0 ) ;
if ( error )
return error ;
error = F_20 ( V_16 , V_30 , V_27 -> V_34 ,
V_27 -> V_25 , 0 , & V_31 , & V_33 , V_32 ) ;
if ( error == - V_35 || error == - V_36 )
F_21 ( V_16 , V_27 ) ;
if ( error )
return error ;
F_22 ( V_16 , & V_31 ) ;
return 0 ;
}
STATIC int
F_23 (
struct V_15 * V_16 ,
struct V_17 * V_27 ,
T_5 V_37 ,
T_6 V_38 ,
struct V_39 * V_40 )
{
T_7 V_41 ;
int V_42 = 1 ;
if ( V_27 -> V_43 == V_44 )
return 0 ;
F_18 ( V_27 , V_37 , V_38 ) ;
F_24 ( V_16 , V_27 ) ;
if ( V_27 -> V_25 == 0 )
return 0 ;
return F_25 ( NULL , V_16 , V_27 -> V_34 , V_27 -> V_25 ,
V_45 | V_46 , & V_41 ,
0 , V_27 , & V_42 , V_40 ) ;
}
int
F_26 (
struct V_15 * V_16 ,
T_8 V_47 ,
T_8 V_48 )
{
struct V_17 V_31 ;
struct V_39 V_40 ;
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
T_5 V_37 = F_27 ( V_2 , V_47 ) ;
T_5 V_49 = F_28 ( V_2 , V_47 + V_48 ) ;
T_4 V_33 ;
bool V_50 ;
int error = 0 ;
F_29 ( V_16 , V_51 ) ;
for ( V_50 = F_16 ( V_16 , V_29 , V_37 , & V_33 , & V_31 ) ;
V_50 && V_31 . V_34 < V_49 ;
V_50 = F_30 ( V_29 , ++ V_33 , & V_31 ) ) {
error = F_23 ( V_16 , & V_31 , V_37 ,
V_49 - V_37 , & V_40 ) ;
if ( error )
break;
}
F_31 ( V_16 , V_51 ) ;
return error ;
}
int
F_32 (
struct V_15 * V_16 ,
struct V_17 * V_27 ,
bool * V_19 ,
T_9 * V_52 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_5 V_37 = V_27 -> V_34 ;
T_6 V_38 = V_27 -> V_25 ;
struct V_17 V_31 ;
struct V_39 V_40 ;
struct V_53 * V_54 = NULL ;
T_7 V_41 ;
int V_42 , error = 0 ;
bool V_20 ;
T_6 V_55 ;
T_3 V_56 = 0 ;
T_4 V_33 ;
V_57:
ASSERT ( F_8 ( V_16 ) ) ;
ASSERT ( F_33 ( V_16 , V_51 | V_58 ) ) ;
if ( F_16 ( V_16 , V_16 -> V_59 , V_37 , & V_33 , & V_31 ) &&
V_31 . V_34 <= V_37 ) {
* V_19 = true ;
if ( ! F_10 ( V_31 . V_21 ) ) {
F_18 ( & V_31 , V_37 , V_38 ) ;
* V_27 = V_31 ;
goto V_60;
}
F_18 ( V_27 , V_31 . V_34 , V_31 . V_25 ) ;
} else {
error = F_7 ( V_16 , V_27 , V_19 , & V_20 ) ;
if ( error || ! * V_19 )
goto V_61;
}
if ( ! V_54 ) {
V_55 = F_34 ( V_27 -> V_34 ,
V_27 -> V_25 , F_35 ( V_16 ) ) ;
V_56 = F_36 ( V_2 , V_55 ) ;
F_31 ( V_16 , * V_52 ) ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_62 , V_56 , 0 , 0 , & V_54 ) ;
* V_52 = V_51 ;
F_29 ( V_16 , * V_52 ) ;
if ( error )
return error ;
error = F_19 ( V_16 , 0 ) ;
if ( error )
goto V_61;
goto V_57;
}
error = F_39 ( V_54 , V_16 , V_56 , 0 ,
V_63 ) ;
if ( error )
goto V_61;
F_40 ( V_54 , V_16 , 0 ) ;
F_41 ( & V_40 , & V_41 ) ;
V_42 = 1 ;
error = F_25 ( V_54 , V_16 , V_27 -> V_34 , V_27 -> V_25 ,
V_45 | V_64 , & V_41 ,
V_56 , V_27 , & V_42 , & V_40 ) ;
if ( error )
goto V_65;
error = F_42 ( & V_54 , & V_40 , NULL ) ;
if ( error )
goto V_65;
error = F_43 ( V_54 ) ;
if ( error )
return error ;
V_60:
return F_23 ( V_16 , V_27 , V_37 , V_38 ,
& V_40 ) ;
V_65:
F_44 ( & V_40 ) ;
F_45 ( V_54 , V_16 , ( long ) V_56 , 0 ,
V_63 ) ;
V_61:
if ( V_54 )
F_46 ( V_54 ) ;
return error ;
}
bool
F_47 (
struct V_15 * V_16 ,
T_8 V_47 ,
struct V_17 * V_27 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
T_5 V_37 ;
struct V_17 V_31 ;
T_4 V_33 ;
ASSERT ( F_33 ( V_16 , V_51 | V_58 ) ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_37 = F_27 ( V_16 -> V_24 , V_47 ) ;
if ( ! F_16 ( V_16 , V_29 , V_37 , & V_33 , & V_31 ) )
return false ;
if ( V_31 . V_34 > V_37 )
return false ;
F_48 ( V_16 , V_47 , 1 , V_66 ,
& V_31 ) ;
* V_27 = V_31 ;
return true ;
}
void
F_49 (
struct V_15 * V_16 ,
T_5 V_37 ,
struct V_17 * V_27 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
struct V_17 V_31 ;
T_4 V_33 ;
if ( ! F_8 ( V_16 ) )
return;
if ( ! F_16 ( V_16 , V_29 , V_37 , & V_33 , & V_31 ) )
return;
if ( V_31 . V_34 < V_37 ) {
if ( ! F_30 ( V_29 , V_33 + 1 , & V_31 ) )
return;
}
if ( V_31 . V_34 >= V_27 -> V_34 + V_27 -> V_25 )
return;
V_27 -> V_25 = V_31 . V_34 - V_27 -> V_34 ;
F_50 ( V_16 , V_27 ) ;
}
int
F_51 (
struct V_15 * V_16 ,
struct V_53 * * V_67 ,
T_5 V_37 ,
T_5 V_49 ,
bool V_68 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
struct V_17 V_31 , V_69 ;
T_4 V_33 ;
T_7 V_70 ;
struct V_39 V_40 ;
int error = 0 ;
if ( ! F_8 ( V_16 ) )
return 0 ;
if ( ! F_16 ( V_16 , V_29 , V_37 , & V_33 , & V_31 ) )
return 0 ;
while ( V_31 . V_34 < V_49 ) {
V_69 = V_31 ;
F_18 ( & V_69 , V_37 , V_49 - V_37 ) ;
F_52 ( V_16 , & V_69 ) ;
if ( F_10 ( V_69 . V_21 ) ) {
error = F_53 ( V_16 , V_30 ,
& V_33 , & V_31 , & V_69 ) ;
if ( error )
break;
} else if ( V_69 . V_43 == V_71 || V_68 ) {
F_40 ( * V_67 , V_16 , 0 ) ;
F_41 ( & V_40 , & V_70 ) ;
error = F_54 ( V_16 -> V_24 ,
& V_40 , V_69 . V_21 ,
V_69 . V_25 ) ;
if ( error )
break;
F_55 ( V_16 -> V_24 , & V_40 ,
V_69 . V_21 , V_69 . V_25 ,
NULL ) ;
F_56 ( * V_67 , V_16 , V_72 ,
- ( long ) V_69 . V_25 ) ;
error = F_42 ( V_67 , & V_40 , V_16 ) ;
if ( error ) {
F_44 ( & V_40 ) ;
break;
}
F_57 ( V_16 , & V_33 , & V_31 , & V_69 ) ;
}
if ( ! F_30 ( V_29 , ++ V_33 , & V_31 ) )
break;
}
if ( ! V_29 -> V_73 )
F_58 ( V_16 ) ;
return error ;
}
int
F_59 (
struct V_15 * V_16 ,
T_8 V_47 ,
T_8 V_48 ,
bool V_68 )
{
struct V_53 * V_54 ;
T_5 V_37 ;
T_5 V_49 ;
int error ;
F_60 ( V_16 , V_47 , V_48 ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_37 = F_27 ( V_16 -> V_24 , V_47 ) ;
if ( V_48 == V_74 )
V_49 = V_74 ;
else
V_49 = F_28 ( V_16 -> V_24 , V_47 + V_48 ) ;
error = F_37 ( V_16 -> V_24 , & F_38 ( V_16 -> V_24 ) -> V_62 ,
0 , 0 , 0 , & V_54 ) ;
if ( error )
goto V_61;
F_29 ( V_16 , V_51 ) ;
F_40 ( V_54 , V_16 , 0 ) ;
error = F_51 ( V_16 , & V_54 , V_37 , V_49 ,
V_68 ) ;
if ( error )
goto V_75;
error = F_43 ( V_54 ) ;
F_31 ( V_16 , V_51 ) ;
return error ;
V_75:
F_46 ( V_54 ) ;
F_31 ( V_16 , V_51 ) ;
V_61:
F_61 ( V_16 , error , V_76 ) ;
return error ;
}
int
F_62 (
struct V_15 * V_16 ,
T_8 V_47 ,
T_8 V_48 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
struct V_17 V_31 , V_69 ;
struct V_53 * V_54 ;
T_5 V_37 ;
T_5 V_49 ;
T_7 V_70 ;
struct V_39 V_40 ;
int error ;
unsigned int V_56 ;
T_6 V_77 ;
T_4 V_33 ;
F_63 ( V_16 , V_47 , V_48 ) ;
if ( V_29 -> V_73 == 0 )
return 0 ;
V_37 = F_27 ( V_16 -> V_24 , V_47 ) ;
V_49 = F_28 ( V_16 -> V_24 , V_47 + V_48 ) ;
V_56 = F_64 ( V_16 -> V_24 , V_78 ) ;
error = F_37 ( V_16 -> V_24 , & F_38 ( V_16 -> V_24 ) -> V_62 ,
V_56 , 0 , 0 , & V_54 ) ;
if ( error )
goto V_61;
F_29 ( V_16 , V_51 ) ;
F_40 ( V_54 , V_16 , 0 ) ;
if ( ! F_16 ( V_16 , V_29 , V_49 - 1 , & V_33 , & V_31 ) ||
V_31 . V_34 > V_49 ) {
ASSERT ( V_33 > 0 ) ;
F_30 ( V_29 , -- V_33 , & V_31 ) ;
}
while ( V_31 . V_34 + V_31 . V_25 > V_37 ) {
V_69 = V_31 ;
F_18 ( & V_69 , V_37 , V_49 - V_37 ) ;
if ( ! V_69 . V_25 ) {
V_33 -- ;
goto V_79;
}
ASSERT ( ! F_10 ( V_31 . V_21 ) ) ;
if ( V_31 . V_43 == V_71 ) {
V_33 -- ;
goto V_79;
}
F_41 ( & V_40 , & V_70 ) ;
V_77 = V_69 . V_25 ;
error = F_65 ( V_54 , V_16 , V_69 . V_34 , & V_77 , 0 , 1 ,
& V_70 , & V_40 ) ;
if ( error )
goto V_80;
if ( V_77 ) {
F_18 ( & V_69 , V_69 . V_34 + V_77 ,
V_69 . V_25 - V_77 ) ;
}
F_66 ( V_16 , & V_69 ) ;
error = F_54 ( V_54 -> V_81 , & V_40 ,
V_69 . V_21 , V_69 . V_25 ) ;
if ( error )
goto V_80;
error = F_67 ( V_54 -> V_81 , & V_40 , V_16 , & V_69 ) ;
if ( error )
goto V_80;
F_57 ( V_16 , & V_33 , & V_31 , & V_69 ) ;
error = F_42 ( & V_54 , & V_40 , V_16 ) ;
if ( error )
goto V_80;
V_79:
if ( ! F_30 ( V_29 , V_33 , & V_31 ) )
break;
}
error = F_43 ( V_54 ) ;
F_31 ( V_16 , V_51 ) ;
if ( error )
goto V_61;
return 0 ;
V_80:
F_44 ( & V_40 ) ;
F_46 ( V_54 ) ;
F_31 ( V_16 , V_51 ) ;
V_61:
F_68 ( V_16 , error , V_76 ) ;
return error ;
}
int
F_69 (
struct V_1 * V_2 )
{
T_1 V_3 ;
int error = 0 ;
if ( ! F_70 ( & V_2 -> V_82 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_82 . V_83 ; V_3 ++ ) {
error = F_71 ( V_2 , V_3 ) ;
if ( error )
break;
}
return error ;
}
STATIC int
F_72 (
struct V_15 * V_84 ,
struct V_15 * V_85 )
{
struct V_1 * V_2 = V_84 -> V_24 ;
int error ;
struct V_53 * V_54 ;
if ( F_8 ( V_84 ) && F_8 ( V_85 ) )
return 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_86 , 0 , 0 , 0 , & V_54 ) ;
if ( error )
goto V_87;
if ( V_84 -> V_88 == V_85 -> V_88 )
F_29 ( V_84 , V_51 ) ;
else
F_73 ( V_84 , V_85 , V_51 ) ;
if ( ! F_8 ( V_84 ) ) {
F_74 ( V_84 ) ;
F_40 ( V_54 , V_84 , V_51 ) ;
V_84 -> V_89 . V_90 |= V_91 ;
F_75 ( V_54 , V_84 , V_92 ) ;
F_76 ( V_84 ) ;
} else
F_31 ( V_84 , V_51 ) ;
if ( V_84 -> V_88 == V_85 -> V_88 )
goto V_93;
if ( ! F_8 ( V_85 ) ) {
F_74 ( V_85 ) ;
F_40 ( V_54 , V_85 , V_51 ) ;
V_85 -> V_89 . V_90 |= V_91 ;
F_75 ( V_54 , V_85 , V_92 ) ;
F_76 ( V_85 ) ;
} else
F_31 ( V_85 , V_51 ) ;
V_93:
error = F_43 ( V_54 ) ;
if ( error )
goto V_87;
return error ;
V_87:
F_77 ( V_85 , error , V_76 ) ;
return error ;
}
STATIC int
F_78 (
struct V_15 * V_85 ,
T_8 V_94 ,
T_3 V_95 ,
bool V_96 )
{
struct V_1 * V_2 = V_85 -> V_24 ;
struct V_53 * V_54 ;
int error ;
if ( V_96 && V_94 <= F_79 ( F_80 ( V_85 ) ) && V_95 == 0 )
return 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_86 , 0 , 0 , 0 , & V_54 ) ;
if ( error )
goto V_87;
F_29 ( V_85 , V_51 ) ;
F_40 ( V_54 , V_85 , V_51 ) ;
if ( V_94 > F_79 ( F_80 ( V_85 ) ) ) {
F_81 ( V_85 , V_94 ) ;
F_82 ( F_80 ( V_85 ) , V_94 ) ;
V_85 -> V_89 . V_97 = V_94 ;
}
if ( V_95 ) {
V_85 -> V_89 . V_98 = V_95 ;
V_85 -> V_89 . V_90 |= V_99 ;
}
if ( ! V_96 ) {
F_83 ( V_54 , V_85 ,
V_100 | V_101 ) ;
}
F_75 ( V_54 , V_85 , V_92 ) ;
error = F_43 ( V_54 ) ;
if ( error )
goto V_87;
return error ;
V_87:
F_84 ( V_85 , error , V_76 ) ;
return error ;
}
static int
F_85 (
struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_102 * V_103 ;
int error = 0 ;
if ( ! F_86 ( & V_2 -> V_82 ) )
return 0 ;
V_103 = F_87 ( V_2 , V_3 ) ;
if ( F_88 ( V_103 , V_104 ) ||
F_88 ( V_103 , V_105 ) )
error = - V_35 ;
F_89 ( V_103 ) ;
return error ;
}
STATIC int
F_90 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_5 V_106 ,
T_8 V_107 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_53 * V_54 ;
T_7 V_70 ;
unsigned int V_56 ;
struct V_39 V_40 ;
struct V_17 V_108 ;
bool V_109 ;
T_6 V_77 ;
T_6 V_110 ;
T_8 V_94 ;
int error ;
V_110 = V_18 -> V_34 + V_18 -> V_25 - V_106 ;
F_91 ( V_16 , V_106 , V_110 ) ;
V_109 = ( V_18 -> V_21 != V_22 &&
V_18 -> V_21 != V_23 &&
! F_9 ( V_18 ) ) ;
if ( V_109 ) {
error = F_85 ( V_2 ,
F_12 ( V_2 , V_18 -> V_21 ) ) ;
if ( error )
goto V_61;
}
V_56 = F_64 ( V_16 -> V_24 , V_78 ) ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_62 , V_56 , 0 , 0 , & V_54 ) ;
if ( error )
goto V_61;
F_29 ( V_16 , V_51 ) ;
F_40 ( V_54 , V_16 , 0 ) ;
if ( V_109 ) {
error = F_39 ( V_54 , V_16 ,
V_18 -> V_25 , 0 , V_63 ) ;
if ( error )
goto V_75;
}
F_92 ( V_16 , V_18 -> V_34 ,
V_18 -> V_25 , V_18 -> V_21 ) ;
V_77 = V_110 ;
while ( V_77 ) {
F_41 ( & V_40 , & V_70 ) ;
error = F_65 ( V_54 , V_16 , V_106 , & V_77 , 0 , 1 ,
& V_70 , & V_40 ) ;
if ( error )
goto V_80;
V_108 . V_21 = V_18 -> V_21 + V_77 ;
V_108 . V_34 = V_18 -> V_34 + V_77 ;
V_108 . V_25 = V_110 - V_77 ;
V_110 = V_77 ;
if ( ! V_109 || V_108 . V_25 == 0 )
goto V_79;
F_92 ( V_16 , V_108 . V_34 ,
V_108 . V_25 , V_108 . V_21 ) ;
error = F_93 ( V_2 , & V_40 , & V_108 ) ;
if ( error )
goto V_80;
error = F_67 ( V_2 , & V_40 , V_16 , & V_108 ) ;
if ( error )
goto V_80;
F_56 ( V_54 , V_16 , V_72 ,
V_108 . V_25 ) ;
V_94 = F_94 ( V_2 ,
V_108 . V_34 + V_108 . V_25 ) ;
V_94 = F_95 ( T_8 , V_94 , V_107 ) ;
if ( V_94 > F_79 ( F_80 ( V_16 ) ) ) {
F_81 ( V_16 , V_94 ) ;
F_82 ( F_80 ( V_16 ) , V_94 ) ;
V_16 -> V_89 . V_97 = V_94 ;
F_75 ( V_54 , V_16 , V_92 ) ;
}
V_79:
error = F_42 ( & V_54 , & V_40 , V_16 ) ;
if ( error )
goto V_80;
}
error = F_43 ( V_54 ) ;
F_31 ( V_16 , V_51 ) ;
if ( error )
goto V_61;
return 0 ;
V_80:
F_44 ( & V_40 ) ;
V_75:
F_46 ( V_54 ) ;
F_31 ( V_16 , V_51 ) ;
V_61:
F_96 ( V_16 , error , V_76 ) ;
return error ;
}
STATIC int
F_97 (
struct V_15 * V_84 ,
T_5 V_111 ,
struct V_15 * V_85 ,
T_5 V_106 ,
T_6 V_112 ,
T_8 V_107 )
{
struct V_17 V_27 ;
int V_42 ;
int error = 0 ;
T_6 V_113 ;
while ( V_112 ) {
F_98 ( V_84 , V_111 , V_112 ,
V_85 , V_106 ) ;
V_42 = 1 ;
F_29 ( V_84 , V_51 ) ;
error = F_99 ( V_84 , V_111 , V_112 , & V_27 , & V_42 , 0 ) ;
F_31 ( V_84 , V_51 ) ;
if ( error )
goto V_114;
ASSERT ( V_42 == 1 ) ;
F_100 ( V_84 , V_111 , V_112 , V_66 ,
& V_27 ) ;
V_113 = V_27 . V_34 + V_27 . V_25 - V_111 ;
V_27 . V_34 += V_106 - V_111 ;
error = F_90 ( V_85 , & V_27 , V_106 ,
V_107 ) ;
if ( error )
goto V_114;
if ( F_101 ( V_115 ) ) {
error = - V_116 ;
goto V_114;
}
V_111 += V_113 ;
V_106 += V_113 ;
V_112 -= V_113 ;
}
return 0 ;
V_114:
F_102 ( V_85 , error , V_76 ) ;
return error ;
}
int
F_103 (
struct V_117 * V_118 ,
T_10 V_119 ,
struct V_117 * V_120 ,
T_10 V_121 ,
T_11 V_112 ,
bool V_96 )
{
struct V_122 * V_123 = F_104 ( V_118 ) ;
struct V_15 * V_84 = F_105 ( V_123 ) ;
struct V_122 * V_124 = F_104 ( V_120 ) ;
struct V_15 * V_85 = F_105 ( V_124 ) ;
struct V_1 * V_2 = V_84 -> V_24 ;
bool V_125 = ( V_123 == V_124 ) ;
T_5 V_126 , V_127 ;
T_6 V_128 ;
T_3 V_95 ;
T_12 V_129 ;
if ( ! F_70 ( & V_2 -> V_82 ) )
return - V_130 ;
if ( F_106 ( V_2 ) )
return - V_131 ;
F_107 ( V_123 , V_124 ) ;
if ( V_125 )
F_29 ( V_84 , V_132 ) ;
else
F_73 ( V_84 , V_85 , V_132 ) ;
V_129 = - V_133 ;
if ( F_108 ( V_84 ) || F_108 ( V_85 ) )
goto V_134;
if ( F_109 ( V_123 ) || F_109 ( V_124 ) )
goto V_134;
V_129 = F_110 ( V_123 , V_119 , V_124 , V_121 ,
& V_112 , V_96 ) ;
if ( V_129 <= 0 )
goto V_134;
F_111 ( V_84 , V_119 , V_112 , V_85 , V_121 ) ;
V_129 = F_72 ( V_84 , V_85 ) ;
if ( V_129 )
goto V_134;
V_127 = F_27 ( V_2 , V_121 ) ;
V_126 = F_27 ( V_2 , V_119 ) ;
V_128 = F_28 ( V_2 , V_112 ) ;
V_129 = F_97 ( V_84 , V_126 , V_85 , V_127 , V_128 ,
V_121 + V_112 ) ;
if ( V_129 )
goto V_134;
F_112 ( & V_124 -> V_135 , V_121 ,
F_113 ( V_121 + V_112 ) - 1 ) ;
V_95 = 0 ;
if ( V_119 == 0 && V_112 == F_79 ( V_123 ) &&
( V_84 -> V_89 . V_90 & V_99 ) &&
V_121 == 0 && V_112 >= F_79 ( V_124 ) &&
! ( V_85 -> V_89 . V_90 & V_99 ) )
V_95 = V_84 -> V_89 . V_98 ;
V_129 = F_78 ( V_85 , V_121 + V_112 , V_95 ,
V_96 ) ;
V_134:
F_31 ( V_84 , V_132 ) ;
if ( ! V_125 )
F_31 ( V_85 , V_132 ) ;
F_114 ( V_123 , V_124 ) ;
if ( V_129 )
F_115 ( V_85 , V_129 , V_76 ) ;
return V_129 ;
}
STATIC int
F_116 (
struct V_15 * V_16 ,
T_5 V_6 ,
T_6 V_136 ,
T_8 V_137 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_138 ;
T_3 V_77 ;
T_8 V_139 ;
T_8 V_7 ;
struct V_17 V_140 [ 2 ] ;
int V_141 ;
int error = 0 ;
while ( V_136 - V_6 > 0 ) {
V_141 = 1 ;
error = F_99 ( V_16 , V_6 , V_136 - V_6 , V_140 , & V_141 , 0 ) ;
if ( error )
goto V_61;
if ( V_141 == 0 )
break;
if ( V_140 [ 0 ] . V_21 == V_22 ||
V_140 [ 0 ] . V_21 == V_23 ||
F_9 ( & V_140 [ 0 ] ) )
goto V_142;
V_140 [ 1 ] = V_140 [ 0 ] ;
while ( V_140 [ 1 ] . V_25 ) {
V_3 = F_12 ( V_2 , V_140 [ 1 ] . V_21 ) ;
V_4 = F_13 ( V_2 , V_140 [ 1 ] . V_21 ) ;
V_5 = V_140 [ 1 ] . V_25 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_138 , & V_77 , true ) ;
if ( error )
goto V_61;
if ( V_138 == V_26 )
break;
F_31 ( V_16 , V_51 ) ;
V_139 = F_94 ( V_2 , V_140 [ 1 ] . V_34 +
( V_138 - V_4 ) ) ;
V_7 = F_94 ( V_2 , V_77 ) ;
if ( V_139 + V_7 > V_137 )
V_7 = V_137 - V_139 ;
error = F_117 ( F_80 ( V_16 ) , V_139 , V_7 ,
& V_143 ) ;
F_29 ( V_16 , V_51 ) ;
if ( error )
goto V_61;
V_140 [ 1 ] . V_25 -= ( V_138 - V_4 + V_77 ) ;
V_140 [ 1 ] . V_34 += ( V_138 - V_4 + V_77 ) ;
V_140 [ 1 ] . V_21 += ( V_138 - V_4 + V_77 ) ;
}
V_142:
V_6 = V_140 [ 0 ] . V_34 + V_140 [ 0 ] . V_25 ;
}
V_61:
return error ;
}
int
F_118 (
struct V_15 * V_16 ,
struct V_53 * * V_67 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_5 V_6 ;
T_6 V_136 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_138 ;
T_3 V_77 ;
struct V_17 V_140 ;
int V_141 ;
int error = 0 ;
ASSERT ( F_8 ( V_16 ) ) ;
V_6 = 0 ;
V_136 = F_28 ( V_2 , F_79 ( F_80 ( V_16 ) ) ) ;
while ( V_136 - V_6 > 0 ) {
V_141 = 1 ;
error = F_99 ( V_16 , V_6 , V_136 - V_6 , & V_140 , & V_141 , 0 ) ;
if ( error )
return error ;
if ( V_141 == 0 )
break;
if ( V_140 . V_21 == V_22 ||
V_140 . V_21 == V_23 ||
F_9 ( & V_140 ) )
goto V_142;
V_3 = F_12 ( V_2 , V_140 . V_21 ) ;
V_4 = F_13 ( V_2 , V_140 . V_21 ) ;
V_5 = V_140 . V_25 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_138 , & V_77 , false ) ;
if ( error )
return error ;
if ( V_138 != V_26 )
return 0 ;
V_142:
V_6 = V_140 . V_34 + V_140 . V_25 ;
}
error = F_51 ( V_16 , V_67 , 0 , V_74 , true ) ;
if ( error )
return error ;
F_119 ( V_16 ) ;
V_16 -> V_89 . V_90 &= ~ V_91 ;
F_58 ( V_16 ) ;
F_40 ( * V_67 , V_16 , 0 ) ;
F_75 ( * V_67 , V_16 , V_92 ) ;
return error ;
}
STATIC int
F_120 (
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_53 * V_54 ;
int error = 0 ;
error = F_37 ( V_2 , & F_38 ( V_2 ) -> V_62 , 0 , 0 , 0 , & V_54 ) ;
if ( error )
return error ;
F_29 ( V_16 , V_51 ) ;
F_40 ( V_54 , V_16 , 0 ) ;
error = F_118 ( V_16 , & V_54 ) ;
if ( error )
goto V_144;
error = F_43 ( V_54 ) ;
if ( error )
goto V_61;
F_31 ( V_16 , V_51 ) ;
return 0 ;
V_144:
F_46 ( V_54 ) ;
V_61:
F_31 ( V_16 , V_51 ) ;
return error ;
}
int
F_121 (
struct V_15 * V_16 ,
T_8 V_47 ,
T_8 V_112 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_5 V_6 ;
T_6 V_136 ;
T_8 V_137 ;
int error ;
if ( ! F_8 ( V_16 ) )
return 0 ;
F_122 ( V_16 , V_47 , V_112 ) ;
F_123 ( F_80 ( V_16 ) ) ;
F_29 ( V_16 , V_51 ) ;
V_6 = F_27 ( V_2 , V_47 ) ;
V_137 = F_79 ( F_80 ( V_16 ) ) ;
V_136 = F_28 ( V_2 , V_47 + V_112 ) ;
error = F_116 ( V_16 , V_6 , V_136 , V_137 ) ;
if ( error )
goto V_134;
F_31 ( V_16 , V_51 ) ;
error = F_124 ( F_80 ( V_16 ) -> V_145 ) ;
if ( error )
goto V_61;
error = F_120 ( V_16 ) ;
if ( error )
goto V_61;
return 0 ;
V_134:
F_31 ( V_16 , V_51 ) ;
V_61:
F_125 ( V_16 , error , V_76 ) ;
return error ;
}
