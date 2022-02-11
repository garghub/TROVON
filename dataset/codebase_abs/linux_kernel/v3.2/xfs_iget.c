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
ASSERT ( ! F_7 ( & V_5 -> V_10 ) ) ;
ASSERT ( F_8 ( & V_5 -> V_11 ) ) ;
ASSERT ( V_5 -> V_12 == 0 ) ;
F_9 ( & V_5 -> V_13 , V_14 , L_1 , V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_13 . V_15 ,
& V_16 , L_2 ) ;
V_5 -> V_12 = V_4 ;
V_5 -> V_17 = V_3 ;
memset ( & V_5 -> V_18 , 0 , sizeof( struct V_19 ) ) ;
V_5 -> V_20 = NULL ;
memset ( & V_5 -> V_21 , 0 , sizeof( V_22 ) ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 0 ;
V_5 -> V_25 = 0 ;
memset ( & V_5 -> V_26 , 0 , sizeof( V_27 ) ) ;
V_5 -> V_28 = 0 ;
V_5 -> V_29 = 0 ;
return V_5 ;
}
STATIC void
F_11 (
struct V_30 * V_31 )
{
struct V_32 * V_32 = F_12 ( V_31 , struct V_32 , V_33 ) ;
struct V_1 * V_5 = F_13 ( V_32 ) ;
F_14 ( & V_32 -> V_34 ) ;
F_5 ( V_6 , V_5 ) ;
}
void
F_15 (
struct V_1 * V_5 )
{
switch ( V_5 -> V_26 . V_35 & V_36 ) {
case V_37 :
case V_38 :
case V_39 :
F_16 ( V_5 , V_40 ) ;
break;
}
if ( V_5 -> V_20 )
F_16 ( V_5 , V_41 ) ;
if ( V_5 -> V_42 ) {
T_2 * V_43 = & V_5 -> V_42 -> V_44 ;
struct V_45 * V_46 = V_43 -> V_47 ;
ASSERT ( ( ( V_43 -> V_48 & V_49 ) == 0 ) ||
F_17 ( V_5 -> V_17 ) ) ;
if ( V_43 -> V_48 & V_49 ) {
F_18 ( & V_46 -> V_50 ) ;
if ( V_43 -> V_48 & V_49 )
F_19 ( V_46 , V_43 ) ;
else
F_20 ( & V_46 -> V_50 ) ;
}
F_21 ( V_5 ) ;
V_5 -> V_42 = NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_10 ) ) ;
ASSERT ( F_8 ( & V_5 -> V_11 ) ) ;
F_18 ( & V_5 -> V_10 ) ;
V_5 -> V_23 = V_51 ;
V_5 -> V_12 = 0 ;
F_20 ( & V_5 -> V_10 ) ;
F_22 ( & F_4 ( V_5 ) -> V_33 , F_11 ) ;
}
static int
F_23 (
struct V_52 * V_53 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_54 ,
int V_55 ) __releases( T_3 )
{
struct V_32 * V_32 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_17 ;
int error ;
F_18 ( & V_5 -> V_10 ) ;
if ( V_5 -> V_12 != V_4 ) {
F_24 ( V_5 ) ;
F_25 ( V_56 ) ;
error = V_57 ;
goto V_58;
}
if ( V_5 -> V_23 & ( V_59 | V_51 ) ) {
F_24 ( V_5 ) ;
F_25 ( V_56 ) ;
error = V_57 ;
goto V_58;
}
if ( V_5 -> V_26 . V_35 == 0 && ! ( V_54 & V_60 ) ) {
error = V_61 ;
goto V_58;
}
if ( V_5 -> V_23 & V_62 ) {
F_26 ( V_5 ) ;
V_5 -> V_23 |= V_51 ;
F_20 ( & V_5 -> V_10 ) ;
F_27 () ;
error = - F_3 ( V_3 -> V_8 , V_32 ) ;
if ( error ) {
F_28 () ;
F_18 ( & V_5 -> V_10 ) ;
V_5 -> V_23 &= ~ ( V_59 | V_51 ) ;
ASSERT ( V_5 -> V_23 & V_62 ) ;
F_29 ( V_5 ) ;
goto V_58;
}
F_18 ( & V_53 -> V_63 ) ;
F_18 ( & V_5 -> V_10 ) ;
V_5 -> V_23 &= ~ V_64 ;
V_5 -> V_23 |= V_59 ;
F_30 ( V_3 , V_53 , V_5 ) ;
V_32 -> V_65 = V_66 ;
ASSERT ( ! F_31 ( & V_5 -> V_13 . V_15 ) ) ;
F_9 ( & V_5 -> V_13 , V_14 , L_1 , V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_13 . V_15 ,
& V_16 , L_2 ) ;
F_20 ( & V_5 -> V_10 ) ;
F_20 ( & V_53 -> V_63 ) ;
} else {
if ( ! F_32 ( V_32 ) ) {
F_24 ( V_5 ) ;
error = V_57 ;
goto V_58;
}
F_20 ( & V_5 -> V_10 ) ;
F_27 () ;
F_33 ( V_5 ) ;
}
if ( V_55 != 0 )
F_34 ( V_5 , V_55 ) ;
F_35 ( V_5 , V_67 ) ;
F_25 ( V_68 ) ;
return 0 ;
V_58:
F_20 ( & V_5 -> V_10 ) ;
F_27 () ;
return error ;
}
static int
F_36 (
struct V_2 * V_3 ,
struct V_52 * V_53 ,
T_4 * V_69 ,
T_1 V_4 ,
struct V_1 * * V_70 ,
int V_54 ,
int V_55 )
{
struct V_1 * V_5 ;
int error ;
T_5 V_71 = F_37 ( V_3 , V_4 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return V_72 ;
error = F_38 ( V_3 , V_69 , V_5 , V_54 ) ;
if ( error )
goto V_73;
F_39 ( V_5 ) ;
if ( ( V_5 -> V_26 . V_35 == 0 ) && ! ( V_54 & V_60 ) ) {
error = V_61 ;
goto V_73;
}
if ( F_40 ( V_74 ) ) {
error = V_57 ;
goto V_73;
}
if ( V_55 ) {
if ( ! F_41 ( V_5 , V_55 ) )
F_42 () ;
}
F_18 ( & V_53 -> V_63 ) ;
error = F_43 ( & V_53 -> V_75 , V_71 , V_5 ) ;
if ( F_44 ( error ) ) {
F_45 ( error != - V_76 ) ;
F_25 ( V_77 ) ;
error = V_57 ;
goto V_78;
}
V_5 -> V_79 = V_5 -> V_80 = NULL ;
F_46 ( V_5 , V_59 ) ;
F_20 ( & V_53 -> V_63 ) ;
F_47 () ;
* V_70 = V_5 ;
return 0 ;
V_78:
F_20 ( & V_53 -> V_63 ) ;
F_47 () ;
if ( V_55 )
F_48 ( V_5 , V_55 ) ;
V_73:
F_49 ( F_4 ( V_5 ) ) ;
F_15 ( V_5 ) ;
return error ;
}
int
F_50 (
T_6 * V_3 ,
T_4 * V_69 ,
T_1 V_4 ,
T_7 V_54 ,
T_7 V_55 ,
T_8 * * V_70 )
{
T_8 * V_5 ;
int error ;
T_9 * V_53 ;
T_5 V_71 ;
if ( ! V_4 || F_51 ( V_3 , V_4 ) >= V_3 -> V_81 . V_82 )
return V_83 ;
V_53 = F_52 ( V_3 , F_51 ( V_3 , V_4 ) ) ;
V_71 = F_37 ( V_3 , V_4 ) ;
V_84:
error = 0 ;
F_28 () ;
V_5 = F_53 ( & V_53 -> V_75 , V_71 ) ;
if ( V_5 ) {
error = F_23 ( V_53 , V_5 , V_4 , V_54 , V_55 ) ;
if ( error )
goto V_85;
} else {
F_27 () ;
F_25 ( V_86 ) ;
error = F_36 ( V_3 , V_53 , V_69 , V_4 , & V_5 ,
V_54 , V_55 ) ;
if ( error )
goto V_85;
}
F_54 ( V_53 ) ;
* V_70 = V_5 ;
ASSERT ( V_5 -> V_21 . V_87 ==
F_55 ( V_5 ) / sizeof( V_88 ) ) ;
if ( F_56 ( V_5 , V_59 ) && V_5 -> V_26 . V_35 != 0 )
F_57 ( V_5 ) ;
return 0 ;
V_85:
if ( error == V_57 ) {
F_58 ( 1 ) ;
goto V_84;
}
F_54 ( V_53 ) ;
return error ;
}
T_7
F_59 (
T_8 * V_5 )
{
T_7 V_89 ;
if ( ( V_5 -> V_26 . V_90 == V_91 ) &&
( ( V_5 -> V_21 . V_92 & V_93 ) == 0 ) ) {
V_89 = V_94 ;
} else {
V_89 = V_95 ;
}
F_34 ( V_5 , V_89 ) ;
return V_89 ;
}
void
F_60 (
T_8 * V_5 ,
unsigned int V_89 )
{
F_48 ( V_5 , V_89 ) ;
}
void
F_34 (
T_8 * V_5 ,
T_7 V_55 )
{
ASSERT ( ( V_55 & ( V_96 | V_97 ) ) !=
( V_96 | V_97 ) ) ;
ASSERT ( ( V_55 & ( V_95 | V_94 ) ) !=
( V_95 | V_94 ) ) ;
ASSERT ( ( V_55 & ~ ( V_98 | V_99 ) ) == 0 ) ;
if ( V_55 & V_97 )
F_61 ( & V_5 -> V_13 , F_62 ( V_55 ) ) ;
else if ( V_55 & V_96 )
F_63 ( & V_5 -> V_13 , F_62 ( V_55 ) ) ;
if ( V_55 & V_94 )
F_61 ( & V_5 -> V_100 , F_64 ( V_55 ) ) ;
else if ( V_55 & V_95 )
F_63 ( & V_5 -> V_100 , F_64 ( V_55 ) ) ;
F_65 ( V_5 , V_55 , V_101 ) ;
}
int
F_41 (
T_8 * V_5 ,
T_7 V_55 )
{
ASSERT ( ( V_55 & ( V_96 | V_97 ) ) !=
( V_96 | V_97 ) ) ;
ASSERT ( ( V_55 & ( V_95 | V_94 ) ) !=
( V_95 | V_94 ) ) ;
ASSERT ( ( V_55 & ~ ( V_98 | V_99 ) ) == 0 ) ;
if ( V_55 & V_97 ) {
if ( ! F_66 ( & V_5 -> V_13 ) )
goto V_102;
} else if ( V_55 & V_96 ) {
if ( ! F_67 ( & V_5 -> V_13 ) )
goto V_102;
}
if ( V_55 & V_94 ) {
if ( ! F_66 ( & V_5 -> V_100 ) )
goto V_103;
} else if ( V_55 & V_95 ) {
if ( ! F_67 ( & V_5 -> V_100 ) )
goto V_103;
}
F_68 ( V_5 , V_55 , V_101 ) ;
return 1 ;
V_103:
if ( V_55 & V_97 )
F_69 ( & V_5 -> V_13 ) ;
else if ( V_55 & V_96 )
F_70 ( & V_5 -> V_13 ) ;
V_102:
return 0 ;
}
void
F_48 (
T_8 * V_5 ,
T_7 V_55 )
{
ASSERT ( ( V_55 & ( V_96 | V_97 ) ) !=
( V_96 | V_97 ) ) ;
ASSERT ( ( V_55 & ( V_95 | V_94 ) ) !=
( V_95 | V_94 ) ) ;
ASSERT ( ( V_55 & ~ ( V_98 | V_104 |
V_99 ) ) == 0 ) ;
ASSERT ( V_55 != 0 ) ;
if ( V_55 & V_97 )
F_69 ( & V_5 -> V_13 ) ;
else if ( V_55 & V_96 )
F_70 ( & V_5 -> V_13 ) ;
if ( V_55 & V_94 )
F_69 ( & V_5 -> V_100 ) ;
else if ( V_55 & V_95 )
F_70 ( & V_5 -> V_100 ) ;
if ( ( V_55 & ( V_95 | V_94 ) ) &&
! ( V_55 & V_104 ) && V_5 -> V_42 ) {
F_71 ( V_5 -> V_42 -> V_44 . V_47 ,
( T_2 * ) ( V_5 -> V_42 ) ) ;
}
F_72 ( V_5 , V_55 , V_101 ) ;
}
void
F_73 (
T_8 * V_5 ,
T_7 V_55 )
{
ASSERT ( V_55 & ( V_97 | V_94 ) ) ;
ASSERT ( ( V_55 & ~ ( V_97 | V_94 ) ) == 0 ) ;
if ( V_55 & V_94 )
F_74 ( & V_5 -> V_100 ) ;
if ( V_55 & V_97 )
F_74 ( & V_5 -> V_13 ) ;
F_75 ( V_5 , V_55 , V_101 ) ;
}
int
F_76 (
T_8 * V_5 ,
T_7 V_55 )
{
if ( V_55 & ( V_94 | V_95 ) ) {
if ( ! ( V_55 & V_95 ) )
return ! ! V_5 -> V_100 . V_105 ;
return F_31 ( & V_5 -> V_100 . V_15 ) ;
}
if ( V_55 & ( V_97 | V_96 ) ) {
if ( ! ( V_55 & V_96 ) )
return ! ! V_5 -> V_13 . V_105 ;
return F_31 ( & V_5 -> V_13 . V_15 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
