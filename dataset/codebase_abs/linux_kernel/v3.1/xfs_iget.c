STATIC struct V_1 *
F_1 (
struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_6 , V_7 ) ;
if ( ! V_5 )
return NULL ;
if ( F_3 ( V_3 -> V_8 , F_4 ( V_5 ) ) ) {
F_5 ( V_6 , V_5 ) ;
return NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( F_6 ( & V_5 -> V_10 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_11 ) ) ;
ASSERT ( F_8 ( & V_5 -> V_12 ) ) ;
ASSERT ( V_5 -> V_13 == 0 ) ;
F_9 ( & V_5 -> V_14 , V_15 , L_1 , V_5 -> V_13 ) ;
F_10 ( & V_5 -> V_14 . V_16 ,
& V_17 , L_2 ) ;
V_5 -> V_13 = V_4 ;
V_5 -> V_18 = V_3 ;
memset ( & V_5 -> V_19 , 0 , sizeof( struct V_20 ) ) ;
V_5 -> V_21 = NULL ;
memset ( & V_5 -> V_22 , 0 , sizeof( V_23 ) ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_25 = 0 ;
V_5 -> V_26 = 0 ;
memset ( & V_5 -> V_27 , 0 , sizeof( V_28 ) ) ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = 0 ;
return V_5 ;
}
STATIC void
F_11 (
struct V_31 * V_32 )
{
struct V_33 * V_33 = F_12 ( V_32 , struct V_33 , V_34 ) ;
struct V_1 * V_5 = F_13 ( V_33 ) ;
F_14 ( & V_33 -> V_35 ) ;
F_5 ( V_6 , V_5 ) ;
}
void
F_15 (
struct V_1 * V_5 )
{
switch ( V_5 -> V_27 . V_36 & V_37 ) {
case V_38 :
case V_39 :
case V_40 :
F_16 ( V_5 , V_41 ) ;
break;
}
if ( V_5 -> V_21 )
F_16 ( V_5 , V_42 ) ;
if ( V_5 -> V_43 ) {
T_2 * V_44 = & V_5 -> V_43 -> V_45 ;
struct V_46 * V_47 = V_44 -> V_48 ;
ASSERT ( ( ( V_44 -> V_49 & V_50 ) == 0 ) ||
F_17 ( V_5 -> V_18 ) ) ;
if ( V_44 -> V_49 & V_50 ) {
F_18 ( & V_47 -> V_51 ) ;
if ( V_44 -> V_49 & V_50 )
F_19 ( V_47 , V_44 ) ;
else
F_20 ( & V_47 -> V_51 ) ;
}
F_21 ( V_5 ) ;
V_5 -> V_43 = NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( F_6 ( & V_5 -> V_10 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_11 ) ) ;
ASSERT ( F_8 ( & V_5 -> V_12 ) ) ;
F_18 ( & V_5 -> V_11 ) ;
V_5 -> V_24 = V_52 ;
V_5 -> V_13 = 0 ;
F_20 ( & V_5 -> V_11 ) ;
F_22 ( & F_4 ( V_5 ) -> V_34 , F_11 ) ;
}
static int
F_23 (
struct V_53 * V_54 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_55 ,
int V_56 ) __releases( T_3 )
{
struct V_33 * V_33 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_18 ;
int error ;
F_18 ( & V_5 -> V_11 ) ;
if ( V_5 -> V_13 != V_4 ) {
F_24 ( V_5 ) ;
F_25 ( V_57 ) ;
error = V_58 ;
goto V_59;
}
if ( V_5 -> V_24 & ( V_60 | V_52 ) ) {
F_24 ( V_5 ) ;
F_25 ( V_57 ) ;
error = V_58 ;
goto V_59;
}
if ( V_5 -> V_27 . V_36 == 0 && ! ( V_55 & V_61 ) ) {
error = V_62 ;
goto V_59;
}
if ( V_5 -> V_24 & V_63 ) {
F_26 ( V_5 ) ;
V_5 -> V_24 |= V_52 ;
F_20 ( & V_5 -> V_11 ) ;
F_27 () ;
error = - F_3 ( V_3 -> V_8 , V_33 ) ;
if ( error ) {
F_28 () ;
F_18 ( & V_5 -> V_11 ) ;
V_5 -> V_24 &= ~ ( V_60 | V_52 ) ;
ASSERT ( V_5 -> V_24 & V_63 ) ;
F_29 ( V_5 ) ;
goto V_59;
}
F_18 ( & V_54 -> V_64 ) ;
F_18 ( & V_5 -> V_11 ) ;
V_5 -> V_24 &= ~ V_65 ;
V_5 -> V_24 |= V_60 ;
F_30 ( V_3 , V_54 , V_5 ) ;
V_33 -> V_66 = V_67 ;
ASSERT ( ! F_31 ( & V_5 -> V_14 . V_16 ) ) ;
F_9 ( & V_5 -> V_14 , V_15 , L_1 , V_5 -> V_13 ) ;
F_10 ( & V_5 -> V_14 . V_16 ,
& V_17 , L_2 ) ;
F_20 ( & V_5 -> V_11 ) ;
F_20 ( & V_54 -> V_64 ) ;
} else {
if ( ! F_32 ( V_33 ) ) {
F_24 ( V_5 ) ;
error = V_58 ;
goto V_59;
}
F_20 ( & V_5 -> V_11 ) ;
F_27 () ;
F_33 ( V_5 ) ;
}
if ( V_56 != 0 )
F_34 ( V_5 , V_56 ) ;
F_35 ( V_5 , V_68 ) ;
F_25 ( V_69 ) ;
return 0 ;
V_59:
F_20 ( & V_5 -> V_11 ) ;
F_27 () ;
return error ;
}
static int
F_36 (
struct V_2 * V_3 ,
struct V_53 * V_54 ,
T_4 * V_70 ,
T_1 V_4 ,
struct V_1 * * V_71 ,
int V_55 ,
int V_56 )
{
struct V_1 * V_5 ;
int error ;
T_5 V_72 = F_37 ( V_3 , V_4 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return V_73 ;
error = F_38 ( V_3 , V_70 , V_5 , V_55 ) ;
if ( error )
goto V_74;
F_39 ( V_5 ) ;
if ( ( V_5 -> V_27 . V_36 == 0 ) && ! ( V_55 & V_61 ) ) {
error = V_62 ;
goto V_74;
}
if ( F_40 ( V_75 ) ) {
error = V_58 ;
goto V_74;
}
if ( V_56 ) {
if ( ! F_41 ( V_5 , V_56 ) )
F_42 () ;
}
F_18 ( & V_54 -> V_64 ) ;
error = F_43 ( & V_54 -> V_76 , V_72 , V_5 ) ;
if ( F_44 ( error ) ) {
F_45 ( error != - V_77 ) ;
F_25 ( V_78 ) ;
error = V_58 ;
goto V_79;
}
V_5 -> V_80 = V_5 -> V_81 = NULL ;
F_46 ( V_5 , V_60 ) ;
F_20 ( & V_54 -> V_64 ) ;
F_47 () ;
* V_71 = V_5 ;
return 0 ;
V_79:
F_20 ( & V_54 -> V_64 ) ;
F_47 () ;
if ( V_56 )
F_48 ( V_5 , V_56 ) ;
V_74:
F_49 ( F_4 ( V_5 ) ) ;
F_15 ( V_5 ) ;
return error ;
}
int
F_50 (
T_6 * V_3 ,
T_4 * V_70 ,
T_1 V_4 ,
T_7 V_55 ,
T_7 V_56 ,
T_8 * * V_71 )
{
T_8 * V_5 ;
int error ;
T_9 * V_54 ;
T_5 V_72 ;
if ( ! V_4 || F_51 ( V_3 , V_4 ) >= V_3 -> V_82 . V_83 )
return V_84 ;
V_54 = F_52 ( V_3 , F_51 ( V_3 , V_4 ) ) ;
V_72 = F_37 ( V_3 , V_4 ) ;
V_85:
error = 0 ;
F_28 () ;
V_5 = F_53 ( & V_54 -> V_76 , V_72 ) ;
if ( V_5 ) {
error = F_23 ( V_54 , V_5 , V_4 , V_55 , V_56 ) ;
if ( error )
goto V_86;
} else {
F_27 () ;
F_25 ( V_87 ) ;
error = F_36 ( V_3 , V_54 , V_70 , V_4 , & V_5 ,
V_55 , V_56 ) ;
if ( error )
goto V_86;
}
F_54 ( V_54 ) ;
* V_71 = V_5 ;
ASSERT ( V_5 -> V_22 . V_88 ==
F_55 ( V_5 ) / sizeof( V_89 ) ) ;
if ( F_56 ( V_5 , V_60 ) && V_5 -> V_27 . V_36 != 0 )
F_57 ( V_5 ) ;
return 0 ;
V_86:
if ( error == V_58 ) {
F_58 ( 1 ) ;
goto V_85;
}
F_54 ( V_54 ) ;
return error ;
}
T_7
F_59 (
T_8 * V_5 )
{
T_7 V_90 ;
if ( ( V_5 -> V_27 . V_91 == V_92 ) &&
( ( V_5 -> V_22 . V_93 & V_94 ) == 0 ) ) {
V_90 = V_95 ;
} else {
V_90 = V_96 ;
}
F_34 ( V_5 , V_90 ) ;
return V_90 ;
}
void
F_60 (
T_8 * V_5 ,
unsigned int V_90 )
{
F_48 ( V_5 , V_90 ) ;
}
void
F_34 (
T_8 * V_5 ,
T_7 V_56 )
{
ASSERT ( ( V_56 & ( V_97 | V_98 ) ) !=
( V_97 | V_98 ) ) ;
ASSERT ( ( V_56 & ( V_96 | V_95 ) ) !=
( V_96 | V_95 ) ) ;
ASSERT ( ( V_56 & ~ ( V_99 | V_100 ) ) == 0 ) ;
if ( V_56 & V_98 )
F_61 ( & V_5 -> V_14 , F_62 ( V_56 ) ) ;
else if ( V_56 & V_97 )
F_63 ( & V_5 -> V_14 , F_62 ( V_56 ) ) ;
if ( V_56 & V_95 )
F_61 ( & V_5 -> V_101 , F_64 ( V_56 ) ) ;
else if ( V_56 & V_96 )
F_63 ( & V_5 -> V_101 , F_64 ( V_56 ) ) ;
F_65 ( V_5 , V_56 , V_102 ) ;
}
int
F_41 (
T_8 * V_5 ,
T_7 V_56 )
{
ASSERT ( ( V_56 & ( V_97 | V_98 ) ) !=
( V_97 | V_98 ) ) ;
ASSERT ( ( V_56 & ( V_96 | V_95 ) ) !=
( V_96 | V_95 ) ) ;
ASSERT ( ( V_56 & ~ ( V_99 | V_100 ) ) == 0 ) ;
if ( V_56 & V_98 ) {
if ( ! F_66 ( & V_5 -> V_14 ) )
goto V_103;
} else if ( V_56 & V_97 ) {
if ( ! F_67 ( & V_5 -> V_14 ) )
goto V_103;
}
if ( V_56 & V_95 ) {
if ( ! F_66 ( & V_5 -> V_101 ) )
goto V_104;
} else if ( V_56 & V_96 ) {
if ( ! F_67 ( & V_5 -> V_101 ) )
goto V_104;
}
F_68 ( V_5 , V_56 , V_102 ) ;
return 1 ;
V_104:
if ( V_56 & V_98 )
F_69 ( & V_5 -> V_14 ) ;
else if ( V_56 & V_97 )
F_70 ( & V_5 -> V_14 ) ;
V_103:
return 0 ;
}
void
F_48 (
T_8 * V_5 ,
T_7 V_56 )
{
ASSERT ( ( V_56 & ( V_97 | V_98 ) ) !=
( V_97 | V_98 ) ) ;
ASSERT ( ( V_56 & ( V_96 | V_95 ) ) !=
( V_96 | V_95 ) ) ;
ASSERT ( ( V_56 & ~ ( V_99 | V_105 |
V_100 ) ) == 0 ) ;
ASSERT ( V_56 != 0 ) ;
if ( V_56 & V_98 )
F_69 ( & V_5 -> V_14 ) ;
else if ( V_56 & V_97 )
F_70 ( & V_5 -> V_14 ) ;
if ( V_56 & V_95 )
F_69 ( & V_5 -> V_101 ) ;
else if ( V_56 & V_96 )
F_70 ( & V_5 -> V_101 ) ;
if ( ( V_56 & ( V_96 | V_95 ) ) &&
! ( V_56 & V_105 ) && V_5 -> V_43 ) {
F_71 ( V_5 -> V_43 -> V_45 . V_48 ,
( T_2 * ) ( V_5 -> V_43 ) ) ;
}
F_72 ( V_5 , V_56 , V_102 ) ;
}
void
F_73 (
T_8 * V_5 ,
T_7 V_56 )
{
ASSERT ( V_56 & ( V_98 | V_95 ) ) ;
ASSERT ( ( V_56 & ~ ( V_98 | V_95 ) ) == 0 ) ;
if ( V_56 & V_95 )
F_74 ( & V_5 -> V_101 ) ;
if ( V_56 & V_98 )
F_74 ( & V_5 -> V_14 ) ;
F_75 ( V_5 , V_56 , V_102 ) ;
}
int
F_76 (
T_8 * V_5 ,
T_7 V_56 )
{
if ( V_56 & ( V_95 | V_96 ) ) {
if ( ! ( V_56 & V_96 ) )
return ! ! V_5 -> V_101 . V_106 ;
return F_31 ( & V_5 -> V_101 . V_16 ) ;
}
if ( V_56 & ( V_98 | V_97 ) ) {
if ( ! ( V_56 & V_97 ) )
return ! ! V_5 -> V_14 . V_106 ;
return F_31 ( & V_5 -> V_14 . V_16 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
