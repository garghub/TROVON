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
ASSERT ( ! F_8 ( V_5 ) ) ;
ASSERT ( V_5 -> V_11 == 0 ) ;
F_9 ( & V_5 -> V_12 , V_13 , L_1 , V_5 -> V_11 ) ;
F_10 ( & V_5 -> V_12 . V_14 ,
& V_15 , L_2 ) ;
V_5 -> V_11 = V_4 ;
V_5 -> V_16 = V_3 ;
memset ( & V_5 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
V_5 -> V_19 = NULL ;
memset ( & V_5 -> V_20 , 0 , sizeof( V_21 ) ) ;
V_5 -> V_22 = 0 ;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 0 ;
memset ( & V_5 -> V_25 , 0 , sizeof( V_26 ) ) ;
return V_5 ;
}
STATIC void
F_11 (
struct V_27 * V_28 )
{
struct V_29 * V_29 = F_12 ( V_28 , struct V_29 , V_30 ) ;
struct V_1 * V_5 = F_13 ( V_29 ) ;
F_5 ( V_6 , V_5 ) ;
}
void
F_14 (
struct V_1 * V_5 )
{
switch ( V_5 -> V_25 . V_31 & V_32 ) {
case V_33 :
case V_34 :
case V_35 :
F_15 ( V_5 , V_36 ) ;
break;
}
if ( V_5 -> V_19 )
F_15 ( V_5 , V_37 ) ;
if ( V_5 -> V_38 ) {
T_2 * V_39 = & V_5 -> V_38 -> V_40 ;
struct V_41 * V_42 = V_39 -> V_43 ;
ASSERT ( ( ( V_39 -> V_44 & V_45 ) == 0 ) ||
F_16 ( V_5 -> V_16 ) ) ;
if ( V_39 -> V_44 & V_45 ) {
F_17 ( & V_42 -> V_46 ) ;
if ( V_39 -> V_44 & V_45 )
F_18 ( V_42 , V_39 ) ;
else
F_19 ( & V_42 -> V_46 ) ;
}
F_20 ( V_5 ) ;
V_5 -> V_38 = NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_10 ) ) ;
ASSERT ( ! F_8 ( V_5 ) ) ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 = V_47 ;
V_5 -> V_11 = 0 ;
F_19 ( & V_5 -> V_10 ) ;
F_21 ( & F_4 ( V_5 ) -> V_30 , F_11 ) ;
}
static int
F_22 (
struct V_48 * V_49 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_50 ,
int V_51 ) __releases( T_3 )
{
struct V_29 * V_29 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_16 ;
int error ;
F_17 ( & V_5 -> V_10 ) ;
if ( V_5 -> V_11 != V_4 ) {
F_23 ( V_5 ) ;
F_24 ( V_52 ) ;
error = V_53 ;
goto V_54;
}
if ( V_5 -> V_22 & ( V_55 | V_47 ) ) {
F_23 ( V_5 ) ;
F_24 ( V_52 ) ;
error = V_53 ;
goto V_54;
}
if ( V_5 -> V_25 . V_31 == 0 && ! ( V_50 & V_56 ) ) {
error = V_57 ;
goto V_54;
}
if ( V_5 -> V_22 & V_58 ) {
F_25 ( V_5 ) ;
V_5 -> V_22 |= V_47 ;
F_19 ( & V_5 -> V_10 ) ;
F_26 () ;
error = - F_3 ( V_3 -> V_8 , V_29 ) ;
if ( error ) {
F_27 () ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 &= ~ ( V_55 | V_47 ) ;
ASSERT ( V_5 -> V_22 & V_58 ) ;
F_28 ( V_5 ) ;
goto V_54;
}
F_17 ( & V_49 -> V_59 ) ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 &= ~ V_60 ;
V_5 -> V_22 |= V_55 ;
F_29 ( V_3 , V_49 , V_5 ) ;
V_29 -> V_61 = V_62 ;
ASSERT ( ! F_30 ( & V_5 -> V_12 . V_14 ) ) ;
F_9 ( & V_5 -> V_12 , V_13 , L_1 , V_5 -> V_11 ) ;
F_10 ( & V_5 -> V_12 . V_14 ,
& V_15 , L_2 ) ;
F_19 ( & V_5 -> V_10 ) ;
F_19 ( & V_49 -> V_59 ) ;
} else {
if ( ! F_31 ( V_29 ) ) {
F_23 ( V_5 ) ;
error = V_53 ;
goto V_54;
}
F_19 ( & V_5 -> V_10 ) ;
F_26 () ;
F_32 ( V_5 ) ;
}
if ( V_51 != 0 )
F_33 ( V_5 , V_51 ) ;
F_34 ( V_5 , V_63 ) ;
F_24 ( V_64 ) ;
return 0 ;
V_54:
F_19 ( & V_5 -> V_10 ) ;
F_26 () ;
return error ;
}
static int
F_35 (
struct V_2 * V_3 ,
struct V_48 * V_49 ,
T_4 * V_65 ,
T_1 V_4 ,
struct V_1 * * V_66 ,
int V_50 ,
int V_51 )
{
struct V_1 * V_5 ;
int error ;
T_5 V_67 = F_36 ( V_3 , V_4 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return V_68 ;
error = F_37 ( V_3 , V_65 , V_5 , V_50 ) ;
if ( error )
goto V_69;
F_38 ( V_5 ) ;
if ( ( V_5 -> V_25 . V_31 == 0 ) && ! ( V_50 & V_56 ) ) {
error = V_57 ;
goto V_69;
}
if ( F_39 ( V_70 ) ) {
error = V_53 ;
goto V_69;
}
if ( V_51 ) {
if ( ! F_40 ( V_5 , V_51 ) )
F_41 () ;
}
F_17 ( & V_49 -> V_59 ) ;
error = F_42 ( & V_49 -> V_71 , V_67 , V_5 ) ;
if ( F_43 ( error ) ) {
F_44 ( error != - V_72 ) ;
F_24 ( V_73 ) ;
error = V_53 ;
goto V_74;
}
V_5 -> V_75 = V_5 -> V_76 = NULL ;
F_45 ( V_5 , V_55 ) ;
F_19 ( & V_49 -> V_59 ) ;
F_46 () ;
* V_66 = V_5 ;
return 0 ;
V_74:
F_19 ( & V_49 -> V_59 ) ;
F_46 () ;
if ( V_51 )
F_47 ( V_5 , V_51 ) ;
V_69:
F_48 ( F_4 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return error ;
}
int
F_49 (
T_6 * V_3 ,
T_4 * V_65 ,
T_1 V_4 ,
T_7 V_50 ,
T_7 V_51 ,
T_8 * * V_66 )
{
T_8 * V_5 ;
int error ;
T_9 * V_49 ;
T_5 V_67 ;
if ( ! V_4 || F_50 ( V_3 , V_4 ) >= V_3 -> V_77 . V_78 )
return V_79 ;
V_49 = F_51 ( V_3 , F_50 ( V_3 , V_4 ) ) ;
V_67 = F_36 ( V_3 , V_4 ) ;
V_80:
error = 0 ;
F_27 () ;
V_5 = F_52 ( & V_49 -> V_71 , V_67 ) ;
if ( V_5 ) {
error = F_22 ( V_49 , V_5 , V_4 , V_50 , V_51 ) ;
if ( error )
goto V_81;
} else {
F_26 () ;
F_24 ( V_82 ) ;
error = F_35 ( V_3 , V_49 , V_65 , V_4 , & V_5 ,
V_50 , V_51 ) ;
if ( error )
goto V_81;
}
F_53 ( V_49 ) ;
* V_66 = V_5 ;
if ( F_54 ( V_5 , V_55 ) && V_5 -> V_25 . V_31 != 0 )
F_55 ( V_5 ) ;
return 0 ;
V_81:
if ( error == V_53 ) {
F_56 ( 1 ) ;
goto V_80;
}
F_53 ( V_49 ) ;
return error ;
}
T_7
F_57 (
T_8 * V_5 )
{
T_7 V_83 ;
if ( ( V_5 -> V_25 . V_84 == V_85 ) &&
( ( V_5 -> V_20 . V_86 & V_87 ) == 0 ) ) {
V_83 = V_88 ;
} else {
V_83 = V_89 ;
}
F_33 ( V_5 , V_83 ) ;
return V_83 ;
}
void
F_58 (
T_8 * V_5 ,
unsigned int V_83 )
{
F_47 ( V_5 , V_83 ) ;
}
void
F_33 (
T_8 * V_5 ,
T_7 V_51 )
{
ASSERT ( ( V_51 & ( V_90 | V_91 ) ) !=
( V_90 | V_91 ) ) ;
ASSERT ( ( V_51 & ( V_89 | V_88 ) ) !=
( V_89 | V_88 ) ) ;
ASSERT ( ( V_51 & ~ ( V_92 | V_93 ) ) == 0 ) ;
if ( V_51 & V_91 )
F_59 ( & V_5 -> V_12 , F_60 ( V_51 ) ) ;
else if ( V_51 & V_90 )
F_61 ( & V_5 -> V_12 , F_60 ( V_51 ) ) ;
if ( V_51 & V_88 )
F_59 ( & V_5 -> V_94 , F_62 ( V_51 ) ) ;
else if ( V_51 & V_89 )
F_61 ( & V_5 -> V_94 , F_62 ( V_51 ) ) ;
F_63 ( V_5 , V_51 , V_95 ) ;
}
int
F_40 (
T_8 * V_5 ,
T_7 V_51 )
{
ASSERT ( ( V_51 & ( V_90 | V_91 ) ) !=
( V_90 | V_91 ) ) ;
ASSERT ( ( V_51 & ( V_89 | V_88 ) ) !=
( V_89 | V_88 ) ) ;
ASSERT ( ( V_51 & ~ ( V_92 | V_93 ) ) == 0 ) ;
if ( V_51 & V_91 ) {
if ( ! F_64 ( & V_5 -> V_12 ) )
goto V_96;
} else if ( V_51 & V_90 ) {
if ( ! F_65 ( & V_5 -> V_12 ) )
goto V_96;
}
if ( V_51 & V_88 ) {
if ( ! F_64 ( & V_5 -> V_94 ) )
goto V_97;
} else if ( V_51 & V_89 ) {
if ( ! F_65 ( & V_5 -> V_94 ) )
goto V_97;
}
F_66 ( V_5 , V_51 , V_95 ) ;
return 1 ;
V_97:
if ( V_51 & V_91 )
F_67 ( & V_5 -> V_12 ) ;
else if ( V_51 & V_90 )
F_68 ( & V_5 -> V_12 ) ;
V_96:
return 0 ;
}
void
F_47 (
T_8 * V_5 ,
T_7 V_51 )
{
ASSERT ( ( V_51 & ( V_90 | V_91 ) ) !=
( V_90 | V_91 ) ) ;
ASSERT ( ( V_51 & ( V_89 | V_88 ) ) !=
( V_89 | V_88 ) ) ;
ASSERT ( ( V_51 & ~ ( V_92 | V_98 |
V_93 ) ) == 0 ) ;
ASSERT ( V_51 != 0 ) ;
if ( V_51 & V_91 )
F_67 ( & V_5 -> V_12 ) ;
else if ( V_51 & V_90 )
F_68 ( & V_5 -> V_12 ) ;
if ( V_51 & V_88 )
F_67 ( & V_5 -> V_94 ) ;
else if ( V_51 & V_89 )
F_68 ( & V_5 -> V_94 ) ;
if ( ( V_51 & ( V_89 | V_88 ) ) &&
! ( V_51 & V_98 ) && V_5 -> V_38 ) {
F_69 ( V_5 -> V_38 -> V_40 . V_43 ,
( T_2 * ) ( V_5 -> V_38 ) ) ;
}
F_70 ( V_5 , V_51 , V_95 ) ;
}
void
F_71 (
T_8 * V_5 ,
T_7 V_51 )
{
ASSERT ( V_51 & ( V_91 | V_88 ) ) ;
ASSERT ( ( V_51 & ~ ( V_91 | V_88 ) ) == 0 ) ;
if ( V_51 & V_88 )
F_72 ( & V_5 -> V_94 ) ;
if ( V_51 & V_91 )
F_72 ( & V_5 -> V_12 ) ;
F_73 ( V_5 , V_51 , V_95 ) ;
}
int
F_74 (
T_8 * V_5 ,
T_7 V_51 )
{
if ( V_51 & ( V_88 | V_89 ) ) {
if ( ! ( V_51 & V_89 ) )
return ! ! V_5 -> V_94 . V_99 ;
return F_30 ( & V_5 -> V_94 . V_14 ) ;
}
if ( V_51 & ( V_91 | V_90 ) ) {
if ( ! ( V_51 & V_90 ) )
return ! ! V_5 -> V_12 . V_99 ;
return F_30 ( & V_5 -> V_12 . V_14 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
void
F_75 (
struct V_1 * V_5 )
{
T_10 * V_100 = F_76 ( & V_5 -> V_22 , V_101 ) ;
F_77 ( V_102 , & V_5 -> V_22 , V_101 ) ;
do {
F_78 ( V_100 , & V_102 . V_102 , V_103 ) ;
if ( F_8 ( V_5 ) )
F_79 () ;
} while ( ! F_80 ( V_5 ) );
F_81 ( V_100 , & V_102 . V_102 ) ;
}
