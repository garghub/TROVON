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
struct V_17 V_28 , V_29 ;
T_4 V_30 , V_31 ;
int V_32 = 0 , error = 0 ;
bool V_20 ;
T_5 V_33 ;
T_3 V_34 ;
F_15 ( V_16 , V_27 -> V_35 , V_36 , & V_32 , & V_33 ,
& V_28 , & V_29 ) ;
if ( ! V_32 && V_28 . V_35 <= V_27 -> V_35 ) {
F_16 ( V_16 , V_27 ) ;
F_17 ( V_27 , V_28 . V_35 , V_28 . V_25 ) ;
* V_19 = true ;
return 0 ;
}
error = F_7 ( V_16 , V_27 , V_19 , & V_20 ) ;
if ( error )
return error ;
if ( ! * V_19 )
return 0 ;
error = F_18 ( V_16 , 0 ) ;
if ( error )
return error ;
V_30 = V_31 = V_27 -> V_35 + V_27 -> V_25 ;
V_34 = F_19 ( V_16 , F_20 ( V_16 ) ) ;
if ( V_34 )
V_30 = F_21 ( V_30 , V_34 ) ;
V_37:
error = F_22 ( V_16 , V_36 , V_27 -> V_35 ,
V_30 - V_27 -> V_35 , & V_28 , & V_29 , & V_33 , V_32 ) ;
switch ( error ) {
case 0 :
break;
case - V_38 :
case - V_39 :
F_23 ( V_16 , V_27 ) ;
if ( V_30 != V_31 ) {
V_30 = V_31 ;
goto V_37;
}
default:
return error ;
}
if ( V_30 != V_31 )
F_24 ( V_16 ) ;
F_25 ( V_16 , & V_28 ) ;
return 0 ;
}
static int
F_26 (
struct V_15 * V_16 ,
T_4 * V_40 ,
T_4 V_30 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_17 V_27 ;
struct V_41 V_42 ;
struct V_43 * V_44 ;
T_6 V_45 ;
int V_46 = 1 , error ;
bool V_19 ;
F_27 ( & V_42 , & V_45 ) ;
error = F_28 ( V_2 , & F_29 ( V_2 ) -> V_47 , 0 , 0 ,
V_48 , & V_44 ) ;
if ( error )
return error ;
F_30 ( V_16 , V_49 ) ;
V_46 = 1 ;
error = F_31 ( V_16 , * V_40 , V_30 - * V_40 ,
& V_27 , & V_46 , 0 ) ;
if ( error )
goto V_50;
ASSERT ( V_46 == 1 ) ;
error = F_14 ( V_16 , & V_27 , & V_19 ) ;
if ( error )
goto V_51;
if ( ! V_19 ) {
* V_40 = V_27 . V_35 + V_27 . V_25 ;
goto V_51;
}
F_32 ( V_44 , V_16 , 0 ) ;
error = F_33 ( V_44 , V_16 , V_27 . V_35 , V_27 . V_25 ,
V_52 , & V_45 ,
F_34 ( V_2 , V_53 ) ,
& V_27 , & V_46 , & V_42 ) ;
if ( error )
goto V_51;
error = F_35 ( & V_44 , & V_42 , NULL ) ;
if ( error )
goto V_51;
error = F_36 ( V_44 ) ;
* V_40 = V_27 . V_35 + V_27 . V_25 ;
V_50:
F_37 ( V_16 , V_49 ) ;
return error ;
V_51:
F_38 ( & V_42 ) ;
F_39 ( V_44 ) ;
goto V_50;
}
int
F_40 (
struct V_15 * V_16 ,
T_7 V_54 ,
T_7 V_55 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_4 V_40 = F_41 ( V_2 , V_54 ) ;
T_4 V_30 = F_42 ( V_2 , V_54 + V_55 ) ;
int error ;
ASSERT ( F_8 ( V_16 ) ) ;
F_43 ( V_16 , V_54 , V_55 ) ;
error = F_44 ( V_16 , 0 ) ;
if ( error )
return error ;
while ( V_40 < V_30 ) {
error = F_26 ( V_16 , & V_40 , V_30 ) ;
if ( error ) {
F_45 ( V_16 , error ,
V_56 ) ;
break;
}
}
return error ;
}
bool
F_46 (
struct V_15 * V_16 ,
T_7 V_54 ,
struct V_17 * V_27 ,
bool * V_57 )
{
struct V_17 V_18 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_4 V_62 ;
T_5 V_33 ;
ASSERT ( F_47 ( V_16 , V_49 | V_63 ) ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_59 = F_48 ( V_16 , V_36 ) ;
V_62 = F_41 ( V_16 -> V_24 , V_54 ) ;
V_61 = F_49 ( V_59 , V_62 , & V_33 ) ;
if ( ! V_61 )
return false ;
F_50 ( V_61 , & V_18 ) ;
if ( V_62 >= V_18 . V_35 + V_18 . V_25 ||
V_62 < V_18 . V_35 )
return false ;
F_51 ( V_16 , V_54 , 1 , V_64 ,
& V_18 ) ;
* V_27 = V_18 ;
* V_57 = ! ! ( F_10 ( V_18 . V_21 ) ) ;
return true ;
}
int
F_52 (
struct V_15 * V_16 ,
T_4 V_40 ,
struct V_17 * V_27 )
{
struct V_17 V_18 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_5 V_33 ;
if ( ! F_8 ( V_16 ) )
return 0 ;
V_59 = F_48 ( V_16 , V_36 ) ;
V_61 = F_49 ( V_59 , V_40 , & V_33 ) ;
if ( ! V_61 )
return 0 ;
F_50 ( V_61 , & V_18 ) ;
if ( V_18 . V_35 < V_40 ) {
V_33 ++ ;
if ( V_33 >= V_59 -> V_65 / sizeof( V_66 ) )
return 0 ;
V_61 = F_53 ( V_59 , V_33 ) ;
F_50 ( V_61 , & V_18 ) ;
}
if ( V_18 . V_35 >= V_27 -> V_35 + V_27 -> V_25 )
return 0 ;
V_27 -> V_25 = V_18 . V_35 - V_27 -> V_35 ;
F_54 ( V_16 , V_27 ) ;
return 0 ;
}
int
F_55 (
struct V_15 * V_16 ,
struct V_43 * * V_67 ,
T_4 V_40 ,
T_4 V_30 )
{
struct V_58 * V_59 = F_48 ( V_16 , V_36 ) ;
struct V_17 V_28 , V_29 , V_68 ;
T_5 V_33 ;
T_6 V_69 ;
struct V_41 V_42 ;
int error = 0 , V_32 = 0 ;
if ( ! F_8 ( V_16 ) )
return 0 ;
F_15 ( V_16 , V_40 , V_36 , & V_32 , & V_33 ,
& V_28 , & V_29 ) ;
if ( V_32 )
return 0 ;
while ( V_28 . V_35 < V_30 ) {
V_68 = V_28 ;
F_17 ( & V_68 , V_40 , V_30 - V_40 ) ;
F_56 ( V_16 , & V_68 ) ;
if ( F_10 ( V_68 . V_21 ) ) {
error = F_57 ( V_16 , V_36 ,
& V_33 , & V_28 , & V_68 ) ;
if ( error )
break;
} else {
F_32 ( * V_67 , V_16 , 0 ) ;
F_27 ( & V_42 , & V_69 ) ;
error = F_58 ( V_16 -> V_24 ,
& V_42 , V_68 . V_21 ,
V_68 . V_25 ) ;
if ( error )
break;
F_59 ( V_16 -> V_24 , & V_42 ,
V_68 . V_21 , V_68 . V_25 ,
NULL ) ;
F_60 ( * V_67 , V_16 , V_70 ,
- ( long ) V_68 . V_25 ) ;
error = F_35 ( V_67 , & V_42 , V_16 ) ;
if ( error ) {
F_38 ( & V_42 ) ;
break;
}
F_61 ( V_16 , & V_33 , & V_28 , & V_68 ) ;
}
if ( ++ V_33 >= V_59 -> V_65 / sizeof( struct V_71 ) )
break;
F_50 ( F_53 ( V_59 , V_33 ) , & V_28 ) ;
}
if ( ! V_59 -> V_65 )
F_62 ( V_16 ) ;
return error ;
}
int
F_63 (
struct V_15 * V_16 ,
T_7 V_54 ,
T_7 V_55 )
{
struct V_43 * V_44 ;
T_4 V_40 ;
T_4 V_30 ;
int error ;
F_64 ( V_16 , V_54 , V_55 ) ;
ASSERT ( F_8 ( V_16 ) ) ;
V_40 = F_41 ( V_16 -> V_24 , V_54 ) ;
if ( V_55 == V_72 )
V_30 = V_72 ;
else
V_30 = F_42 ( V_16 -> V_24 , V_54 + V_55 ) ;
error = F_28 ( V_16 -> V_24 , & F_29 ( V_16 -> V_24 ) -> V_47 ,
0 , 0 , 0 , & V_44 ) ;
if ( error )
goto V_73;
F_30 ( V_16 , V_49 ) ;
F_32 ( V_44 , V_16 , 0 ) ;
error = F_55 ( V_16 , & V_44 , V_40 , V_30 ) ;
if ( error )
goto V_74;
error = F_36 ( V_44 ) ;
F_37 ( V_16 , V_49 ) ;
return error ;
V_74:
F_39 ( V_44 ) ;
F_37 ( V_16 , V_49 ) ;
V_73:
F_65 ( V_16 , error , V_56 ) ;
return error ;
}
int
F_66 (
struct V_15 * V_16 ,
T_7 V_54 ,
T_7 V_55 )
{
struct V_58 * V_59 = F_48 ( V_16 , V_36 ) ;
struct V_17 V_28 , V_29 , V_68 ;
struct V_43 * V_44 ;
T_4 V_40 ;
T_4 V_30 ;
T_6 V_69 ;
struct V_41 V_42 ;
int error , V_32 = 0 ;
unsigned int V_75 ;
T_8 V_76 ;
T_5 V_33 ;
F_67 ( V_16 , V_54 , V_55 ) ;
if ( V_59 -> V_65 == 0 )
return 0 ;
V_40 = F_41 ( V_16 -> V_24 , V_54 ) ;
V_30 = F_42 ( V_16 -> V_24 , V_54 + V_55 ) ;
V_75 = F_34 ( V_16 -> V_24 , V_53 ) ;
error = F_28 ( V_16 -> V_24 , & F_29 ( V_16 -> V_24 ) -> V_47 ,
V_75 , 0 , 0 , & V_44 ) ;
if ( error )
goto V_73;
F_30 ( V_16 , V_49 ) ;
F_32 ( V_44 , V_16 , 0 ) ;
F_15 ( V_16 , V_30 - 1 , V_36 , & V_32 , & V_33 ,
& V_28 , & V_29 ) ;
if ( V_32 || V_28 . V_35 > V_30 ) {
ASSERT ( V_33 > 0 ) ;
F_50 ( F_53 ( V_59 , -- V_33 ) , & V_28 ) ;
}
while ( V_28 . V_35 + V_28 . V_25 > V_40 ) {
V_68 = V_28 ;
F_17 ( & V_68 , V_40 , V_30 - V_40 ) ;
if ( ! V_68 . V_25 ) {
V_33 -- ;
goto V_77;
}
ASSERT ( ! F_10 ( V_28 . V_21 ) ) ;
F_27 ( & V_42 , & V_69 ) ;
V_76 = V_68 . V_25 ;
error = F_68 ( V_44 , V_16 , V_68 . V_35 , & V_76 , 0 , 1 ,
& V_69 , & V_42 ) ;
if ( error )
goto V_78;
if ( V_76 ) {
F_17 ( & V_68 , V_68 . V_35 + V_76 ,
V_68 . V_25 - V_76 ) ;
}
F_69 ( V_16 , & V_68 ) ;
error = F_58 ( V_44 -> V_79 , & V_42 ,
V_68 . V_21 , V_68 . V_25 ) ;
if ( error )
goto V_78;
error = F_70 ( V_44 -> V_79 , & V_42 , V_16 , & V_68 ) ;
if ( error )
goto V_78;
F_61 ( V_16 , & V_33 , & V_28 , & V_68 ) ;
error = F_35 ( & V_44 , & V_42 , V_16 ) ;
if ( error )
goto V_78;
V_77:
if ( V_33 < 0 )
break;
F_50 ( F_53 ( V_59 , V_33 ) , & V_28 ) ;
}
error = F_36 ( V_44 ) ;
F_37 ( V_16 , V_49 ) ;
if ( error )
goto V_73;
return 0 ;
V_78:
F_38 ( & V_42 ) ;
F_39 ( V_44 ) ;
F_37 ( V_16 , V_49 ) ;
V_73:
F_71 ( V_16 , error , V_56 ) ;
return error ;
}
int
F_72 (
struct V_1 * V_2 )
{
T_1 V_3 ;
int error = 0 ;
if ( ! F_73 ( & V_2 -> V_80 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_80 . V_81 ; V_3 ++ ) {
error = F_74 ( V_2 , V_3 ) ;
if ( error )
break;
}
return error ;
}
STATIC int
F_75 (
struct V_15 * V_82 ,
struct V_15 * V_83 )
{
struct V_1 * V_2 = V_82 -> V_24 ;
int error ;
struct V_43 * V_44 ;
if ( F_8 ( V_82 ) && F_8 ( V_83 ) )
return 0 ;
error = F_28 ( V_2 , & F_29 ( V_2 ) -> V_84 , 0 , 0 , 0 , & V_44 ) ;
if ( error )
goto V_85;
if ( V_82 -> V_86 == V_83 -> V_86 )
F_30 ( V_82 , V_49 ) ;
else
F_76 ( V_82 , V_83 , V_49 ) ;
if ( ! F_8 ( V_82 ) ) {
F_77 ( V_82 ) ;
F_32 ( V_44 , V_82 , V_49 ) ;
V_82 -> V_87 . V_88 |= V_89 ;
F_78 ( V_44 , V_82 , V_90 ) ;
F_79 ( V_82 ) ;
} else
F_37 ( V_82 , V_49 ) ;
if ( V_82 -> V_86 == V_83 -> V_86 )
goto V_91;
if ( ! F_8 ( V_83 ) ) {
F_77 ( V_83 ) ;
F_32 ( V_44 , V_83 , V_49 ) ;
V_83 -> V_87 . V_88 |= V_89 ;
F_78 ( V_44 , V_83 , V_90 ) ;
F_79 ( V_83 ) ;
} else
F_37 ( V_83 , V_49 ) ;
V_91:
error = F_36 ( V_44 ) ;
if ( error )
goto V_85;
return error ;
V_85:
F_80 ( V_83 , error , V_56 ) ;
return error ;
}
STATIC int
F_81 (
struct V_15 * V_83 ,
T_7 V_92 ,
T_3 V_93 )
{
struct V_1 * V_2 = V_83 -> V_24 ;
struct V_43 * V_44 ;
int error ;
if ( V_92 <= F_82 ( F_83 ( V_83 ) ) && V_93 == 0 )
return 0 ;
error = F_28 ( V_2 , & F_29 ( V_2 ) -> V_84 , 0 , 0 , 0 , & V_44 ) ;
if ( error )
goto V_85;
F_30 ( V_83 , V_49 ) ;
F_32 ( V_44 , V_83 , V_49 ) ;
if ( V_92 > F_82 ( F_83 ( V_83 ) ) ) {
F_84 ( V_83 , V_92 ) ;
F_85 ( F_83 ( V_83 ) , V_92 ) ;
V_83 -> V_87 . V_94 = V_92 ;
}
if ( V_93 ) {
V_83 -> V_87 . V_95 = V_93 ;
V_83 -> V_87 . V_88 |= V_96 ;
}
F_78 ( V_44 , V_83 , V_90 ) ;
error = F_36 ( V_44 ) ;
if ( error )
goto V_85;
return error ;
V_85:
F_86 ( V_83 , error , V_56 ) ;
return error ;
}
static int
F_87 (
struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_97 * V_98 ;
int error = 0 ;
if ( ! F_88 ( & V_2 -> V_80 ) )
return 0 ;
V_98 = F_89 ( V_2 , V_3 ) ;
if ( F_90 ( V_98 , V_99 ) ||
F_90 ( V_98 , V_100 ) )
error = - V_38 ;
F_91 ( V_98 ) ;
return error ;
}
STATIC int
F_92 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_4 V_101 ,
T_7 V_102 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_43 * V_44 ;
T_6 V_69 ;
unsigned int V_75 ;
struct V_41 V_42 ;
struct V_17 V_103 ;
bool V_104 ;
T_8 V_76 ;
T_8 V_105 ;
T_7 V_92 ;
int error ;
V_105 = V_18 -> V_35 + V_18 -> V_25 - V_101 ;
F_93 ( V_16 , V_101 , V_105 ) ;
V_104 = ( V_18 -> V_21 != V_22 &&
V_18 -> V_21 != V_23 &&
! F_9 ( V_18 ) ) ;
if ( V_104 ) {
error = F_87 ( V_2 ,
F_12 ( V_2 , V_18 -> V_21 ) ) ;
if ( error )
goto V_73;
}
V_75 = F_34 ( V_16 -> V_24 , V_53 ) ;
error = F_28 ( V_2 , & F_29 ( V_2 ) -> V_47 , V_75 , 0 , 0 , & V_44 ) ;
if ( error )
goto V_73;
F_30 ( V_16 , V_49 ) ;
F_32 ( V_44 , V_16 , 0 ) ;
if ( V_104 ) {
error = F_94 ( V_44 , V_16 ,
V_18 -> V_25 , 0 , V_106 ) ;
if ( error )
goto V_74;
}
F_95 ( V_16 , V_18 -> V_35 ,
V_18 -> V_25 , V_18 -> V_21 ) ;
V_76 = V_105 ;
while ( V_76 ) {
F_27 ( & V_42 , & V_69 ) ;
error = F_68 ( V_44 , V_16 , V_101 , & V_76 , 0 , 1 ,
& V_69 , & V_42 ) ;
if ( error )
goto V_78;
V_103 . V_21 = V_18 -> V_21 + V_76 ;
V_103 . V_35 = V_18 -> V_35 + V_76 ;
V_103 . V_25 = V_105 - V_76 ;
V_105 = V_76 ;
if ( ! V_104 || V_103 . V_25 == 0 )
goto V_77;
F_95 ( V_16 , V_103 . V_35 ,
V_103 . V_25 , V_103 . V_21 ) ;
error = F_96 ( V_2 , & V_42 , & V_103 ) ;
if ( error )
goto V_78;
error = F_70 ( V_2 , & V_42 , V_16 , & V_103 ) ;
if ( error )
goto V_78;
F_60 ( V_44 , V_16 , V_70 ,
V_103 . V_25 ) ;
V_92 = F_97 ( V_2 ,
V_103 . V_35 + V_103 . V_25 ) ;
V_92 = F_98 ( T_7 , V_92 , V_102 ) ;
if ( V_92 > F_82 ( F_83 ( V_16 ) ) ) {
F_84 ( V_16 , V_92 ) ;
F_85 ( F_83 ( V_16 ) , V_92 ) ;
V_16 -> V_87 . V_94 = V_92 ;
F_78 ( V_44 , V_16 , V_90 ) ;
}
V_77:
error = F_35 ( & V_44 , & V_42 , V_16 ) ;
if ( error )
goto V_78;
}
error = F_36 ( V_44 ) ;
F_37 ( V_16 , V_49 ) ;
if ( error )
goto V_73;
return 0 ;
V_78:
F_38 ( & V_42 ) ;
V_74:
F_39 ( V_44 ) ;
F_37 ( V_16 , V_49 ) ;
V_73:
F_99 ( V_16 , error , V_56 ) ;
return error ;
}
STATIC int
F_100 (
struct V_15 * V_82 ,
T_4 V_107 ,
struct V_15 * V_83 ,
T_4 V_101 ,
T_8 V_108 ,
T_7 V_102 )
{
struct V_17 V_27 ;
int V_46 ;
int error = 0 ;
T_8 V_109 ;
while ( V_108 ) {
F_101 ( V_82 , V_107 , V_108 ,
V_83 , V_101 ) ;
V_46 = 1 ;
F_30 ( V_82 , V_49 ) ;
error = F_31 ( V_82 , V_107 , V_108 , & V_27 , & V_46 , 0 ) ;
F_37 ( V_82 , V_49 ) ;
if ( error )
goto V_110;
ASSERT ( V_46 == 1 ) ;
F_102 ( V_82 , V_107 , V_108 , V_64 ,
& V_27 ) ;
V_109 = V_27 . V_35 + V_27 . V_25 - V_107 ;
V_27 . V_35 += V_101 - V_107 ;
error = F_92 ( V_83 , & V_27 , V_101 ,
V_102 ) ;
if ( error )
goto V_110;
if ( F_103 ( V_111 ) ) {
error = - V_112 ;
goto V_110;
}
V_107 += V_109 ;
V_101 += V_109 ;
V_108 -= V_109 ;
}
return 0 ;
V_110:
F_104 ( V_83 , error , V_56 ) ;
return error ;
}
static struct V_113 *
F_105 (
struct V_114 * V_114 ,
T_7 V_54 )
{
struct V_115 * V_116 ;
struct V_113 * V_113 ;
T_9 V_117 ;
V_117 = V_54 >> V_118 ;
V_116 = V_114 -> V_119 ;
V_113 = F_106 ( V_116 , V_117 , NULL ) ;
if ( F_107 ( V_113 ) )
return V_113 ;
if ( ! F_108 ( V_113 ) ) {
F_109 ( V_113 ) ;
return F_110 ( - V_120 ) ;
}
F_111 ( V_113 ) ;
return V_113 ;
}
static int
F_112 (
struct V_114 * V_82 ,
T_7 V_107 ,
struct V_114 * V_83 ,
T_7 V_101 ,
T_7 V_108 ,
bool * V_121 )
{
T_7 V_122 ;
T_7 V_123 ;
void * V_124 ;
void * V_125 ;
struct V_113 * V_126 ;
struct V_113 * V_127 ;
T_7 V_128 ;
bool V_129 ;
int error ;
error = - V_130 ;
V_129 = true ;
while ( V_108 ) {
V_122 = V_107 & ( V_131 - 1 ) ;
V_123 = V_101 & ( V_131 - 1 ) ;
V_128 = F_113 ( V_131 - V_122 ,
V_131 - V_123 ) ;
V_128 = F_113 ( V_128 , V_108 ) ;
ASSERT ( V_128 > 0 ) ;
F_114 ( F_115 ( V_82 ) , V_107 , V_128 ,
F_115 ( V_83 ) , V_101 ) ;
V_126 = F_105 ( V_82 , V_107 ) ;
if ( F_107 ( V_126 ) ) {
error = F_116 ( V_126 ) ;
goto V_85;
}
V_127 = F_105 ( V_83 , V_101 ) ;
if ( F_107 ( V_127 ) ) {
error = F_116 ( V_127 ) ;
F_117 ( V_126 ) ;
F_109 ( V_126 ) ;
goto V_85;
}
V_124 = F_118 ( V_126 ) ;
V_125 = F_118 ( V_127 ) ;
F_119 ( V_126 ) ;
F_119 ( V_127 ) ;
if ( memcmp ( V_124 + V_122 , V_125 + V_123 , V_128 ) )
V_129 = false ;
F_120 ( V_125 ) ;
F_120 ( V_124 ) ;
F_117 ( V_127 ) ;
F_117 ( V_126 ) ;
F_109 ( V_127 ) ;
F_109 ( V_126 ) ;
if ( ! V_129 )
break;
V_107 += V_128 ;
V_101 += V_128 ;
V_108 -= V_128 ;
}
* V_121 = V_129 ;
return 0 ;
V_85:
F_121 ( F_115 ( V_83 ) , error , V_56 ) ;
return error ;
}
int
F_122 (
struct V_132 * V_133 ,
T_10 V_134 ,
struct V_132 * V_135 ,
T_10 V_136 ,
T_11 V_108 ,
bool V_137 )
{
struct V_114 * V_138 = F_123 ( V_133 ) ;
struct V_15 * V_82 = F_115 ( V_138 ) ;
struct V_114 * V_139 = F_123 ( V_135 ) ;
struct V_15 * V_83 = F_115 ( V_139 ) ;
struct V_1 * V_2 = V_82 -> V_24 ;
T_10 V_140 = V_139 -> V_141 -> V_142 ;
bool V_143 = ( V_138 == V_139 ) ;
T_4 V_144 , V_145 ;
T_8 V_146 ;
T_3 V_93 ;
T_10 V_147 ;
T_12 V_148 ;
T_10 V_149 ;
if ( ! F_73 ( & V_2 -> V_80 ) )
return - V_150 ;
if ( F_124 ( V_2 ) )
return - V_120 ;
if ( V_143 ) {
F_30 ( V_82 , V_151 ) ;
F_30 ( V_82 , V_152 ) ;
} else {
F_76 ( V_82 , V_83 , V_151 ) ;
F_76 ( V_82 , V_83 , V_152 ) ;
}
V_148 = - V_153 ;
if ( F_125 ( V_139 ) )
goto V_50;
V_148 = - V_154 ;
if ( F_126 ( V_138 ) || F_126 ( V_139 ) )
goto V_50;
V_148 = - V_155 ;
if ( F_127 ( V_138 -> V_156 ) || F_127 ( V_139 -> V_156 ) )
goto V_50;
V_148 = - V_130 ;
if ( F_128 ( V_138 -> V_156 ) || F_128 ( V_139 -> V_156 ) )
goto V_50;
if ( ! F_129 ( V_138 -> V_156 ) || ! F_129 ( V_139 -> V_156 ) )
goto V_50;
if ( F_130 ( V_82 ) || F_130 ( V_83 ) )
goto V_50;
if ( F_131 ( V_138 ) || F_131 ( V_139 ) )
goto V_50;
V_147 = F_82 ( V_138 ) ;
if ( V_147 == 0 ) {
V_148 = 0 ;
goto V_50;
}
if ( V_108 == 0 )
V_108 = V_147 - V_134 ;
if ( V_134 + V_108 < V_134 || V_136 + V_108 < V_136 ||
V_134 + V_108 > V_147 )
goto V_50;
if ( V_137 ) {
T_10 V_157 ;
V_157 = F_82 ( V_139 ) ;
if ( V_136 >= V_157 || V_136 + V_108 > V_157 )
goto V_50;
}
if ( V_134 + V_108 == V_147 )
V_149 = F_132 ( V_147 , V_140 ) - V_134 ;
else
V_149 = V_108 ;
if ( ! F_133 ( V_134 , V_140 ) || ! F_133 ( V_134 + V_149 , V_140 ) ||
! F_133 ( V_136 , V_140 ) || ! F_133 ( V_136 + V_149 , V_140 ) )
goto V_50;
if ( V_143 ) {
if ( V_136 + V_149 > V_134 && V_136 < V_134 + V_149 )
goto V_50;
}
F_134 ( V_138 ) ;
if ( ! V_143 )
F_134 ( V_139 ) ;
V_148 = F_135 ( V_138 -> V_119 ,
V_134 , V_134 + V_108 - 1 ) ;
if ( V_148 )
goto V_50;
V_148 = F_135 ( V_139 -> V_119 ,
V_136 , V_136 + V_108 - 1 ) ;
if ( V_148 )
goto V_50;
F_136 ( V_82 , V_134 , V_108 , V_83 , V_136 ) ;
if ( V_137 ) {
bool V_121 = false ;
V_148 = F_112 ( V_138 , V_134 , V_139 , V_136 ,
V_108 , & V_121 ) ;
if ( V_148 )
goto V_50;
if ( ! V_121 ) {
V_148 = - V_158 ;
goto V_50;
}
}
V_148 = F_75 ( V_82 , V_83 ) ;
if ( V_148 )
goto V_50;
F_137 ( & V_139 -> V_159 , V_136 ,
F_138 ( V_136 + V_108 ) - 1 ) ;
V_145 = F_41 ( V_2 , V_136 ) ;
V_144 = F_41 ( V_2 , V_134 ) ;
V_146 = F_42 ( V_2 , V_108 ) ;
V_148 = F_100 ( V_82 , V_144 , V_83 , V_145 , V_146 ,
V_136 + V_108 ) ;
if ( V_148 )
goto V_50;
V_93 = 0 ;
if ( V_134 == 0 && V_108 == F_82 ( V_138 ) &&
( V_82 -> V_87 . V_88 & V_96 ) &&
V_136 == 0 && V_108 >= F_82 ( V_139 ) &&
! ( V_83 -> V_87 . V_88 & V_96 ) )
V_93 = V_82 -> V_87 . V_95 ;
V_148 = F_81 ( V_83 , V_136 + V_108 , V_93 ) ;
V_50:
F_37 ( V_82 , V_152 ) ;
F_37 ( V_82 , V_151 ) ;
if ( V_82 -> V_86 != V_83 -> V_86 ) {
F_37 ( V_83 , V_152 ) ;
F_37 ( V_83 , V_151 ) ;
}
if ( V_148 )
F_139 ( V_83 , V_148 , V_56 ) ;
return V_148 ;
}
STATIC int
F_140 (
struct V_15 * V_16 ,
T_4 V_6 ,
T_8 V_160 ,
T_7 V_147 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_161 ;
T_3 V_76 ;
T_7 V_162 ;
T_7 V_7 ;
struct V_17 V_163 [ 2 ] ;
int V_164 ;
int error = 0 ;
while ( V_160 - V_6 > 0 ) {
V_164 = 1 ;
error = F_31 ( V_16 , V_6 , V_160 - V_6 , V_163 , & V_164 , 0 ) ;
if ( error )
goto V_73;
if ( V_164 == 0 )
break;
if ( V_163 [ 0 ] . V_21 == V_22 ||
V_163 [ 0 ] . V_21 == V_23 ||
F_9 ( & V_163 [ 0 ] ) )
goto V_165;
V_163 [ 1 ] = V_163 [ 0 ] ;
while ( V_163 [ 1 ] . V_25 ) {
V_3 = F_12 ( V_2 , V_163 [ 1 ] . V_21 ) ;
V_4 = F_13 ( V_2 , V_163 [ 1 ] . V_21 ) ;
V_5 = V_163 [ 1 ] . V_25 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_161 , & V_76 , true ) ;
if ( error )
goto V_73;
if ( V_161 == V_26 )
break;
F_37 ( V_16 , V_49 ) ;
V_162 = F_97 ( V_2 , V_163 [ 1 ] . V_35 +
( V_161 - V_4 ) ) ;
V_7 = F_97 ( V_2 , V_76 ) ;
if ( V_162 + V_7 > V_147 )
V_7 = V_147 - V_162 ;
error = F_141 ( F_83 ( V_16 ) , V_162 , V_7 ,
& V_166 ) ;
F_30 ( V_16 , V_49 ) ;
if ( error )
goto V_73;
V_163 [ 1 ] . V_25 -= ( V_161 - V_4 + V_76 ) ;
V_163 [ 1 ] . V_35 += ( V_161 - V_4 + V_76 ) ;
V_163 [ 1 ] . V_21 += ( V_161 - V_4 + V_76 ) ;
}
V_165:
V_6 = V_163 [ 0 ] . V_35 + V_163 [ 0 ] . V_25 ;
}
V_73:
return error ;
}
int
F_142 (
struct V_15 * V_16 ,
struct V_43 * * V_67 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_4 V_6 ;
T_8 V_160 ;
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 ;
T_2 V_161 ;
T_3 V_76 ;
struct V_17 V_163 ;
int V_164 ;
int error = 0 ;
ASSERT ( F_8 ( V_16 ) ) ;
V_6 = 0 ;
V_160 = F_42 ( V_2 , F_82 ( F_83 ( V_16 ) ) ) ;
while ( V_160 - V_6 > 0 ) {
V_164 = 1 ;
error = F_31 ( V_16 , V_6 , V_160 - V_6 , & V_163 , & V_164 , 0 ) ;
if ( error )
return error ;
if ( V_164 == 0 )
break;
if ( V_163 . V_21 == V_22 ||
V_163 . V_21 == V_23 ||
F_9 ( & V_163 ) )
goto V_165;
V_3 = F_12 ( V_2 , V_163 . V_21 ) ;
V_4 = F_13 ( V_2 , V_163 . V_21 ) ;
V_5 = V_163 . V_25 ;
error = F_1 ( V_2 , V_3 , V_4 , V_5 ,
& V_161 , & V_76 , false ) ;
if ( error )
return error ;
if ( V_161 != V_26 )
return 0 ;
V_165:
V_6 = V_163 . V_35 + V_163 . V_25 ;
}
error = F_55 ( V_16 , V_67 , 0 , V_72 ) ;
if ( error )
return error ;
F_143 ( V_16 ) ;
V_16 -> V_87 . V_88 &= ~ V_89 ;
F_62 ( V_16 ) ;
F_32 ( * V_67 , V_16 , 0 ) ;
F_78 ( * V_67 , V_16 , V_90 ) ;
return error ;
}
STATIC int
F_144 (
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
struct V_43 * V_44 ;
int error = 0 ;
error = F_28 ( V_2 , & F_29 ( V_2 ) -> V_47 , 0 , 0 , 0 , & V_44 ) ;
if ( error )
return error ;
F_30 ( V_16 , V_49 ) ;
F_32 ( V_44 , V_16 , 0 ) ;
error = F_142 ( V_16 , & V_44 ) ;
if ( error )
goto V_167;
error = F_36 ( V_44 ) ;
if ( error )
goto V_73;
F_37 ( V_16 , V_49 ) ;
return 0 ;
V_167:
F_39 ( V_44 ) ;
V_73:
F_37 ( V_16 , V_49 ) ;
return error ;
}
int
F_145 (
struct V_15 * V_16 ,
T_7 V_54 ,
T_7 V_108 )
{
struct V_1 * V_2 = V_16 -> V_24 ;
T_4 V_6 ;
T_8 V_160 ;
T_7 V_147 ;
int error ;
if ( ! F_8 ( V_16 ) )
return 0 ;
F_146 ( V_16 , V_54 , V_108 ) ;
F_134 ( F_83 ( V_16 ) ) ;
F_30 ( V_16 , V_49 ) ;
V_6 = F_41 ( V_2 , V_54 ) ;
V_147 = F_82 ( F_83 ( V_16 ) ) ;
V_160 = F_42 ( V_2 , V_54 + V_108 ) ;
error = F_140 ( V_16 , V_6 , V_160 , V_147 ) ;
if ( error )
goto V_50;
F_37 ( V_16 , V_49 ) ;
error = F_147 ( F_83 ( V_16 ) -> V_119 ) ;
if ( error )
goto V_73;
error = F_144 ( V_16 ) ;
if ( error )
goto V_73;
return 0 ;
V_50:
F_37 ( V_16 , V_49 ) ;
V_73:
F_148 ( V_16 , error , V_56 ) ;
return error ;
}
bool
F_149 (
struct V_15 * V_16 )
{
struct V_17 V_18 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_5 V_33 ;
if ( ! F_8 ( V_16 ) )
return false ;
V_59 = F_48 ( V_16 , V_36 ) ;
V_61 = F_49 ( V_59 , 0 , & V_33 ) ;
while ( V_61 ) {
F_50 ( V_61 , & V_18 ) ;
if ( ! F_10 ( V_18 . V_21 ) )
return true ;
V_33 ++ ;
if ( V_33 >= V_59 -> V_65 / sizeof( V_66 ) )
break;
V_61 = F_53 ( V_59 , V_33 ) ;
}
return false ;
}
