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
static int
F_23 (
struct V_15 * V_16 ,
T_5 * V_37 ,
T_5 V_38 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_17 V_27 ;
struct V_39 V_40 ;
struct V_41 * V_42 ;
T_6 V_43 ;
int V_44 = 1 , error ;
bool V_19 ;
F_24 ( & V_40 , & V_43 ) ;
error = F_25 ( V_2 , & F_26 ( V_2 ) -> V_45 , 0 , 0 ,
V_46 , & V_42 ) ;
if ( error )
return error ;
F_27 ( V_16 , V_47 ) ;
V_44 = 1 ;
error = F_28 ( V_16 , * V_37 , V_38 - * V_37 ,
& V_27 , & V_44 , 0 ) ;
if ( error )
goto V_48;
ASSERT ( V_44 == 1 ) ;
error = F_14 ( V_16 , & V_27 , & V_19 ) ;
if ( error )
goto V_49;
if ( ! V_19 ) {
* V_37 = V_27 . V_34 + V_27 . V_25 ;
goto V_49;
}
F_29 ( V_42 , V_16 , 0 ) ;
error = F_30 ( V_42 , V_16 , V_27 . V_34 , V_27 . V_25 ,
V_50 , & V_43 ,
F_31 ( V_2 , V_51 ) ,
& V_27 , & V_44 , & V_40 ) ;
if ( error )
goto V_49;
error = F_32 ( & V_42 , & V_40 , NULL ) ;
if ( error )
goto V_49;
error = F_33 ( V_42 ) ;
* V_37 = V_27 . V_34 + V_27 . V_25 ;
V_48:
F_34 ( V_16 , V_47 ) ;
return error ;
V_49:
F_35 ( & V_40 ) ;
F_36 ( V_42 ) ;
goto V_48;
}
int
F_37 (
struct V_15 * V_16 ,
T_7 V_52 ,
T_7 V_53 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_5 V_37 = F_38 ( V_2 , V_52 ) ;
T_5 V_38 = F_39 ( V_2 , V_52 + V_53 ) ;
int error ;
ASSERT ( F_8 ( V_16 ) ) ;
F_40 ( V_16 , V_52 , V_53 ) ;
error = F_41 ( V_16 , 0 ) ;
if ( error )
return error ;
while ( V_37 < V_38 ) {
error = F_23 ( V_16 , & V_37 , V_38 ) ;
if ( error ) {
F_42 ( V_16 , error ,
V_54 ) ;
break;
}
}
return error ;
}
bool
F_43 (
struct V_15 * V_16 ,
T_7 V_52 ,
struct V_17 * V_27 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
T_5 V_37 ;
struct V_17 V_31 ;
T_4 V_33 ;
ASSERT ( F_44 ( V_16 , V_47 | V_55 ) ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_37 = F_38 ( V_16 -> V_24 , V_52 ) ;
if ( ! F_16 ( V_16 , V_29 , V_37 , & V_33 , & V_31 ) )
return false ;
if ( V_31 . V_34 > V_37 )
return false ;
F_45 ( V_16 , V_52 , 1 , V_56 ,
& V_31 ) ;
* V_27 = V_31 ;
return true ;
}
void
F_46 (
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
if ( ! F_47 ( V_29 , V_33 + 1 , & V_31 ) )
return;
}
if ( V_31 . V_34 >= V_27 -> V_34 + V_27 -> V_25 )
return;
V_27 -> V_25 = V_31 . V_34 - V_27 -> V_34 ;
F_48 ( V_16 , V_27 ) ;
}
int
F_49 (
struct V_15 * V_16 ,
struct V_41 * * V_57 ,
T_5 V_37 ,
T_5 V_38 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
struct V_17 V_31 , V_58 ;
T_4 V_33 ;
T_6 V_59 ;
struct V_39 V_40 ;
int error = 0 ;
if ( ! F_8 ( V_16 ) )
return 0 ;
if ( ! F_16 ( V_16 , V_29 , V_37 , & V_33 , & V_31 ) )
return 0 ;
while ( V_31 . V_34 < V_38 ) {
V_58 = V_31 ;
F_18 ( & V_58 , V_37 , V_38 - V_37 ) ;
F_50 ( V_16 , & V_58 ) ;
if ( F_10 ( V_58 . V_21 ) ) {
error = F_51 ( V_16 , V_30 ,
& V_33 , & V_31 , & V_58 ) ;
if ( error )
break;
} else {
F_29 ( * V_57 , V_16 , 0 ) ;
F_24 ( & V_40 , & V_59 ) ;
error = F_52 ( V_16 -> V_24 ,
& V_40 , V_58 . V_21 ,
V_58 . V_25 ) ;
if ( error )
break;
F_53 ( V_16 -> V_24 , & V_40 ,
V_58 . V_21 , V_58 . V_25 ,
NULL ) ;
F_54 ( * V_57 , V_16 , V_60 ,
- ( long ) V_58 . V_25 ) ;
error = F_32 ( V_57 , & V_40 , V_16 ) ;
if ( error ) {
F_35 ( & V_40 ) ;
break;
}
F_55 ( V_16 , & V_33 , & V_31 , & V_58 ) ;
}
if ( ! F_47 ( V_29 , ++ V_33 , & V_31 ) )
break;
}
if ( ! V_29 -> V_61 )
F_56 ( V_16 ) ;
return error ;
}
int
F_57 (
struct V_15 * V_16 ,
T_7 V_52 ,
T_7 V_53 )
{
struct V_41 * V_42 ;
T_5 V_37 ;
T_5 V_38 ;
int error ;
F_58 ( V_16 , V_52 , V_53 ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_37 = F_38 ( V_16 -> V_24 , V_52 ) ;
if ( V_53 == V_62 )
V_38 = V_62 ;
else
V_38 = F_39 ( V_16 -> V_24 , V_52 + V_53 ) ;
error = F_25 ( V_16 -> V_24 , & F_26 ( V_16 -> V_24 ) -> V_45 ,
0 , 0 , 0 , & V_42 ) ;
if ( error )
goto V_63;
F_27 ( V_16 , V_47 ) ;
F_29 ( V_42 , V_16 , 0 ) ;
error = F_49 ( V_16 , & V_42 , V_37 , V_38 ) ;
if ( error )
goto V_64;
error = F_33 ( V_42 ) ;
F_34 ( V_16 , V_47 ) ;
return error ;
V_64:
F_36 ( V_42 ) ;
F_34 ( V_16 , V_47 ) ;
V_63:
F_59 ( V_16 , error , V_54 ) ;
return error ;
}
int
F_60 (
struct V_15 * V_16 ,
T_7 V_52 ,
T_7 V_53 )
{
struct V_28 * V_29 = F_15 ( V_16 , V_30 ) ;
struct V_17 V_31 , V_58 ;
struct V_41 * V_42 ;
T_5 V_37 ;
T_5 V_38 ;
T_6 V_59 ;
struct V_39 V_40 ;
int error ;
unsigned int V_65 ;
T_8 V_66 ;
T_4 V_33 ;
F_61 ( V_16 , V_52 , V_53 ) ;
if ( V_29 -> V_61 == 0 )
return 0 ;
V_37 = F_38 ( V_16 -> V_24 , V_52 ) ;
V_38 = F_39 ( V_16 -> V_24 , V_52 + V_53 ) ;
V_65 = F_31 ( V_16 -> V_24 , V_51 ) ;
error = F_25 ( V_16 -> V_24 , & F_26 ( V_16 -> V_24 ) -> V_45 ,
V_65 , 0 , 0 , & V_42 ) ;
if ( error )
goto V_63;
F_27 ( V_16 , V_47 ) ;
F_29 ( V_42 , V_16 , 0 ) ;
if ( ! F_16 ( V_16 , V_29 , V_38 - 1 , & V_33 , & V_31 ) ||
V_31 . V_34 > V_38 ) {
ASSERT ( V_33 > 0 ) ;
F_47 ( V_29 , -- V_33 , & V_31 ) ;
}
while ( V_31 . V_34 + V_31 . V_25 > V_37 ) {
V_58 = V_31 ;
F_18 ( & V_58 , V_37 , V_38 - V_37 ) ;
if ( ! V_58 . V_25 ) {
V_33 -- ;
goto V_67;
}
ASSERT ( ! F_10 ( V_31 . V_21 ) ) ;
F_24 ( & V_40 , & V_59 ) ;
V_66 = V_58 . V_25 ;
error = F_62 ( V_42 , V_16 , V_58 . V_34 , & V_66 , 0 , 1 ,
& V_59 , & V_40 ) ;
if ( error )
goto V_68;
if ( V_66 ) {
F_18 ( & V_58 , V_58 . V_34 + V_66 ,
V_58 . V_25 - V_66 ) ;
}
F_63 ( V_16 , & V_58 ) ;
error = F_52 ( V_42 -> V_69 , & V_40 ,
V_58 . V_21 , V_58 . V_25 ) ;
if ( error )
goto V_68;
error = F_64 ( V_42 -> V_69 , & V_40 , V_16 , & V_58 ) ;
if ( error )
goto V_68;
F_55 ( V_16 , & V_33 , & V_31 , & V_58 ) ;
error = F_32 ( & V_42 , & V_40 , V_16 ) ;
if ( error )
goto V_68;
V_67:
if ( ! F_47 ( V_29 , V_33 , & V_31 ) )
break;
}
error = F_33 ( V_42 ) ;
F_34 ( V_16 , V_47 ) ;
if ( error )
goto V_63;
return 0 ;
V_68:
F_35 ( & V_40 ) ;
F_36 ( V_42 ) ;
F_34 ( V_16 , V_47 ) ;
V_63:
F_65 ( V_16 , error , V_54 ) ;
return error ;
}
int
F_66 (
struct V_1 * V_2 )
{
T_1 V_3 ;
int error = 0 ;
if ( ! F_67 ( & V_2 -> V_70 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_70 . V_71 ; V_3 ++ ) {
error = F_68 ( V_2 , V_3 ) ;
if ( error )
break;
}
return error ;
}
STATIC int
F_69 (
struct V_15 * V_72 ,
struct V_15 * V_73 )
{
struct V_1 * V_2 = V_72 -> V_24 ;
int error ;
struct V_41 * V_42 ;
if ( F_8 ( V_72 ) && F_8 ( V_73 ) )
return 0 ;
error = F_25 ( V_2 , & F_26 ( V_2 ) -> V_74 , 0 , 0 , 0 , & V_42 ) ;
if ( error )
goto V_75;
if ( V_72 -> V_76 == V_73 -> V_76 )
F_27 ( V_72 , V_47 ) ;
else
F_70 ( V_72 , V_73 , V_47 ) ;
if ( ! F_8 ( V_72 ) ) {
F_71 ( V_72 ) ;
F_29 ( V_42 , V_72 , V_47 ) ;
V_72 -> V_77 . V_78 |= V_79 ;
F_72 ( V_42 , V_72 , V_80 ) ;
F_73 ( V_72 ) ;
} else
F_34 ( V_72 , V_47 ) ;
if ( V_72 -> V_76 == V_73 -> V_76 )
goto V_81;
if ( ! F_8 ( V_73 ) ) {
F_71 ( V_73 ) ;
F_29 ( V_42 , V_73 , V_47 ) ;
V_73 -> V_77 . V_78 |= V_79 ;
F_72 ( V_42 , V_73 , V_80 ) ;
F_73 ( V_73 ) ;
} else
F_34 ( V_73 , V_47 ) ;
V_81:
error = F_33 ( V_42 ) ;
if ( error )
goto V_75;
return error ;
V_75:
F_74 ( V_73 , error , V_54 ) ;
return error ;
}
STATIC int
F_75 (
struct V_15 * V_73 ,
T_7 V_82 ,
T_3 V_83 )
{
struct V_1 * V_2 = V_73 -> V_24 ;
struct V_41 * V_42 ;
int error ;
if ( V_82 <= F_76 ( F_77 ( V_73 ) ) && V_83 == 0 )
return 0 ;
error = F_25 ( V_2 , & F_26 ( V_2 ) -> V_74 , 0 , 0 , 0 , & V_42 ) ;
if ( error )
goto V_75;
F_27 ( V_73 , V_47 ) ;
F_29 ( V_42 , V_73 , V_47 ) ;
if ( V_82 > F_76 ( F_77 ( V_73 ) ) ) {
F_78 ( V_73 , V_82 ) ;
F_79 ( F_77 ( V_73 ) , V_82 ) ;
V_73 -> V_77 . V_84 = V_82 ;
}
if ( V_83 ) {
V_73 -> V_77 . V_85 = V_83 ;
V_73 -> V_77 . V_78 |= V_86 ;
}
F_72 ( V_42 , V_73 , V_80 ) ;
error = F_33 ( V_42 ) ;
if ( error )
goto V_75;
return error ;
V_75:
F_80 ( V_73 , error , V_54 ) ;
return error ;
}
static int
F_81 (
struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_87 * V_88 ;
int error = 0 ;
if ( ! F_82 ( & V_2 -> V_70 ) )
return 0 ;
V_88 = F_83 ( V_2 , V_3 ) ;
if ( F_84 ( V_88 , V_89 ) ||
F_84 ( V_88 , V_90 ) )
error = - V_35 ;
F_85 ( V_88 ) ;
return error ;
}
STATIC int
F_86 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_5 V_91 ,
T_7 V_92 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_41 * V_42 ;
T_6 V_59 ;
unsigned int V_65 ;
struct V_39 V_40 ;
struct V_17 V_93 ;
bool V_94 ;
T_8 V_66 ;
T_8 V_95 ;
T_7 V_82 ;
int error ;
V_95 = V_18 -> V_34 + V_18 -> V_25 - V_91 ;
F_87 ( V_16 , V_91 , V_95 ) ;
V_94 = ( V_18 -> V_21 != V_22 &&
V_18 -> V_21 != V_23 &&
! F_9 ( V_18 ) ) ;
if ( V_94 ) {
error = F_81 ( V_2 ,
F_12 ( V_2 , V_18 -> V_21 ) ) ;
if ( error )
goto V_63;
}
V_65 = F_31 ( V_16 -> V_24 , V_51 ) ;
error = F_25 ( V_2 , & F_26 ( V_2 ) -> V_45 , V_65 , 0 , 0 , & V_42 ) ;
if ( error )
goto V_63;
F_27 ( V_16 , V_47 ) ;
F_29 ( V_42 , V_16 , 0 ) ;
if ( V_94 ) {
error = F_88 ( V_42 , V_16 ,
V_18 -> V_25 , 0 , V_96 ) ;
if ( error )
goto V_64;
}
F_89 ( V_16 , V_18 -> V_34 ,
V_18 -> V_25 , V_18 -> V_21 ) ;
V_66 = V_95 ;
while ( V_66 ) {
F_24 ( & V_40 , & V_59 ) ;
error = F_62 ( V_42 , V_16 , V_91 , & V_66 , 0 , 1 ,
& V_59 , & V_40 ) ;
if ( error )
goto V_68;
V_93 . V_21 = V_18 -> V_21 + V_66 ;
V_93 . V_34 = V_18 -> V_34 + V_66 ;
V_93 . V_25 = V_95 - V_66 ;
V_95 = V_66 ;
if ( ! V_94 || V_93 . V_25 == 0 )
goto V_67;
F_89 ( V_16 , V_93 . V_34 ,
V_93 . V_25 , V_93 . V_21 ) ;
error = F_90 ( V_2 , & V_40 , & V_93 ) ;
if ( error )
goto V_68;
error = F_64 ( V_2 , & V_40 , V_16 , & V_93 ) ;
if ( error )
goto V_68;
F_54 ( V_42 , V_16 , V_60 ,
V_93 . V_25 ) ;
V_82 = F_91 ( V_2 ,
V_93 . V_34 + V_93 . V_25 ) ;
V_82 = F_92 ( T_7 , V_82 , V_92 ) ;
if ( V_82 > F_76 ( F_77 ( V_16 ) ) ) {
F_78 ( V_16 , V_82 ) ;
F_79 ( F_77 ( V_16 ) , V_82 ) ;
V_16 -> V_77 . V_84 = V_82 ;
F_72 ( V_42 , V_16 , V_80 ) ;
}
V_67:
error = F_32 ( & V_42 , & V_40 , V_16 ) ;
if ( error )
goto V_68;
}
error = F_33 ( V_42 ) ;
F_34 ( V_16 , V_47 ) ;
if ( error )
goto V_63;
return 0 ;
V_68:
F_35 ( & V_40 ) ;
V_64:
F_36 ( V_42 ) ;
F_34 ( V_16 , V_47 ) ;
V_63:
F_93 ( V_16 , error , V_54 ) ;
return error ;
}
STATIC int
F_94 (
struct V_15 * V_72 ,
T_5 V_97 ,
struct V_15 * V_73 ,
T_5 V_91 ,
T_8 V_98 ,
T_7 V_92 )
{
struct V_17 V_27 ;
int V_44 ;
int error = 0 ;
T_8 V_99 ;
while ( V_98 ) {
F_95 ( V_72 , V_97 , V_98 ,
V_73 , V_91 ) ;
V_44 = 1 ;
F_27 ( V_72 , V_47 ) ;
error = F_28 ( V_72 , V_97 , V_98 , & V_27 , & V_44 , 0 ) ;
F_34 ( V_72 , V_47 ) ;
if ( error )
goto V_100;
ASSERT ( V_44 == 1 ) ;
F_96 ( V_72 , V_97 , V_98 , V_56 ,
& V_27 ) ;
V_99 = V_27 . V_34 + V_27 . V_25 - V_97 ;
V_27 . V_34 += V_91 - V_97 ;
error = F_86 ( V_73 , & V_27 , V_91 ,
V_92 ) ;
if ( error )
goto V_100;
if ( F_97 ( V_101 ) ) {
error = - V_102 ;
goto V_100;
}
V_97 += V_99 ;
V_91 += V_99 ;
V_98 -= V_99 ;
}
return 0 ;
V_100:
F_98 ( V_73 , error , V_54 ) ;
return error ;
}
int
F_99 (
struct V_103 * V_104 ,
T_9 V_105 ,
struct V_103 * V_106 ,
T_9 V_107 ,
T_10 V_98 ,
bool V_108 )
{
struct V_109 * V_110 = F_100 ( V_104 ) ;
struct V_15 * V_72 = F_101 ( V_110 ) ;
struct V_109 * V_111 = F_100 ( V_106 ) ;
struct V_15 * V_73 = F_101 ( V_111 ) ;
struct V_1 * V_2 = V_72 -> V_24 ;
bool V_112 = ( V_110 == V_111 ) ;
T_5 V_113 , V_114 ;
T_8 V_115 ;
T_3 V_83 ;
T_11 V_116 ;
if ( ! F_67 ( & V_2 -> V_70 ) )
return - V_117 ;
if ( F_102 ( V_2 ) )
return - V_118 ;
F_103 ( V_110 , V_111 ) ;
if ( V_112 )
F_27 ( V_72 , V_119 ) ;
else
F_70 ( V_72 , V_73 , V_119 ) ;
V_116 = - V_120 ;
if ( F_104 ( V_72 ) || F_104 ( V_73 ) )
goto V_48;
if ( F_105 ( V_110 ) || F_105 ( V_111 ) )
goto V_48;
V_116 = F_106 ( V_110 , V_105 , V_111 , V_107 ,
& V_98 , V_108 ) ;
if ( V_116 <= 0 )
goto V_48;
F_107 ( V_72 , V_105 , V_98 , V_73 , V_107 ) ;
V_116 = F_69 ( V_72 , V_73 ) ;
if ( V_116 )
goto V_48;
V_114 = F_38 ( V_2 , V_107 ) ;
V_113 = F_38 ( V_2 , V_105 ) ;
V_115 = F_39 ( V_2 , V_98 ) ;
V_116 = F_94 ( V_72 , V_113 , V_73 , V_114 , V_115 ,
V_107 + V_98 ) ;
if ( V_116 )
goto V_48;
F_108 ( & V_111 -> V_121 , V_107 ,
F_109 ( V_107 + V_98 ) - 1 ) ;
V_83 = 0 ;
if ( V_105 == 0 && V_98 == F_76 ( V_110 ) &&
( V_72 -> V_77 . V_78 & V_86 ) &&
V_107 == 0 && V_98 >= F_76 ( V_111 ) &&
! ( V_73 -> V_77 . V_78 & V_86 ) )
V_83 = V_72 -> V_77 . V_85 ;
V_116 = F_75 ( V_73 , V_107 + V_98 , V_83 ) ;
V_48:
F_34 ( V_72 , V_119 ) ;
if ( ! V_112 )
F_34 ( V_73 , V_119 ) ;
F_110 ( V_110 , V_111 ) ;
if ( V_116 )
F_111 ( V_73 , V_116 , V_54 ) ;
return V_116 ;
}
STATIC int
F_112 (
struct V_15 * V_16 ,
T_5 V_6 ,
T_8 V_122 ,
T_7 V_123 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_124 ;
T_3 V_66 ;
T_7 V_125 ;
T_7 V_7 ;
struct V_17 V_126 [ 2 ] ;
int V_127 ;
int error = 0 ;
while ( V_122 - V_6 > 0 ) {
V_127 = 1 ;
error = F_28 ( V_16 , V_6 , V_122 - V_6 , V_126 , & V_127 , 0 ) ;
if ( error )
goto V_63;
if ( V_127 == 0 )
break;
if ( V_126 [ 0 ] . V_21 == V_22 ||
V_126 [ 0 ] . V_21 == V_23 ||
F_9 ( & V_126 [ 0 ] ) )
goto V_128;
V_126 [ 1 ] = V_126 [ 0 ] ;
while ( V_126 [ 1 ] . V_25 ) {
V_3 = F_12 ( V_2 , V_126 [ 1 ] . V_21 ) ;
V_4 = F_13 ( V_2 , V_126 [ 1 ] . V_21 ) ;
V_5 = V_126 [ 1 ] . V_25 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_124 , & V_66 , true ) ;
if ( error )
goto V_63;
if ( V_124 == V_26 )
break;
F_34 ( V_16 , V_47 ) ;
V_125 = F_91 ( V_2 , V_126 [ 1 ] . V_34 +
( V_124 - V_4 ) ) ;
V_7 = F_91 ( V_2 , V_66 ) ;
if ( V_125 + V_7 > V_123 )
V_7 = V_123 - V_125 ;
error = F_113 ( F_77 ( V_16 ) , V_125 , V_7 ,
& V_129 ) ;
F_27 ( V_16 , V_47 ) ;
if ( error )
goto V_63;
V_126 [ 1 ] . V_25 -= ( V_124 - V_4 + V_66 ) ;
V_126 [ 1 ] . V_34 += ( V_124 - V_4 + V_66 ) ;
V_126 [ 1 ] . V_21 += ( V_124 - V_4 + V_66 ) ;
}
V_128:
V_6 = V_126 [ 0 ] . V_34 + V_126 [ 0 ] . V_25 ;
}
V_63:
return error ;
}
int
F_114 (
struct V_15 * V_16 ,
struct V_41 * * V_57 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_5 V_6 ;
T_8 V_122 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_124 ;
T_3 V_66 ;
struct V_17 V_126 ;
int V_127 ;
int error = 0 ;
ASSERT ( F_8 ( V_16 ) ) ;
V_6 = 0 ;
V_122 = F_39 ( V_2 , F_76 ( F_77 ( V_16 ) ) ) ;
while ( V_122 - V_6 > 0 ) {
V_127 = 1 ;
error = F_28 ( V_16 , V_6 , V_122 - V_6 , & V_126 , & V_127 , 0 ) ;
if ( error )
return error ;
if ( V_127 == 0 )
break;
if ( V_126 . V_21 == V_22 ||
V_126 . V_21 == V_23 ||
F_9 ( & V_126 ) )
goto V_128;
V_3 = F_12 ( V_2 , V_126 . V_21 ) ;
V_4 = F_13 ( V_2 , V_126 . V_21 ) ;
V_5 = V_126 . V_25 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_124 , & V_66 , false ) ;
if ( error )
return error ;
if ( V_124 != V_26 )
return 0 ;
V_128:
V_6 = V_126 . V_34 + V_126 . V_25 ;
}
error = F_49 ( V_16 , V_57 , 0 , V_62 ) ;
if ( error )
return error ;
F_115 ( V_16 ) ;
V_16 -> V_77 . V_78 &= ~ V_79 ;
F_56 ( V_16 ) ;
F_29 ( * V_57 , V_16 , 0 ) ;
F_72 ( * V_57 , V_16 , V_80 ) ;
return error ;
}
STATIC int
F_116 (
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_41 * V_42 ;
int error = 0 ;
error = F_25 ( V_2 , & F_26 ( V_2 ) -> V_45 , 0 , 0 , 0 , & V_42 ) ;
if ( error )
return error ;
F_27 ( V_16 , V_47 ) ;
F_29 ( V_42 , V_16 , 0 ) ;
error = F_114 ( V_16 , & V_42 ) ;
if ( error )
goto V_130;
error = F_33 ( V_42 ) ;
if ( error )
goto V_63;
F_34 ( V_16 , V_47 ) ;
return 0 ;
V_130:
F_36 ( V_42 ) ;
V_63:
F_34 ( V_16 , V_47 ) ;
return error ;
}
int
F_117 (
struct V_15 * V_16 ,
T_7 V_52 ,
T_7 V_98 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_5 V_6 ;
T_8 V_122 ;
T_7 V_123 ;
int error ;
if ( ! F_8 ( V_16 ) )
return 0 ;
F_118 ( V_16 , V_52 , V_98 ) ;
F_119 ( F_77 ( V_16 ) ) ;
F_27 ( V_16 , V_47 ) ;
V_6 = F_38 ( V_2 , V_52 ) ;
V_123 = F_76 ( F_77 ( V_16 ) ) ;
V_122 = F_39 ( V_2 , V_52 + V_98 ) ;
error = F_112 ( V_16 , V_6 , V_122 , V_123 ) ;
if ( error )
goto V_48;
F_34 ( V_16 , V_47 ) ;
error = F_120 ( F_77 ( V_16 ) -> V_131 ) ;
if ( error )
goto V_63;
error = F_116 ( V_16 ) ;
if ( error )
goto V_63;
return 0 ;
V_48:
F_34 ( V_16 , V_47 ) ;
V_63:
F_121 ( V_16 , error , V_54 ) ;
return error ;
}
