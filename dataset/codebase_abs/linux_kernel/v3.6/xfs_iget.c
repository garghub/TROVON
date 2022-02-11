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
V_5 -> V_11 = V_4 ;
V_5 -> V_14 = V_3 ;
memset ( & V_5 -> V_15 , 0 , sizeof( struct V_16 ) ) ;
V_5 -> V_17 = NULL ;
memset ( & V_5 -> V_18 , 0 , sizeof( V_19 ) ) ;
V_5 -> V_20 = 0 ;
V_5 -> V_21 = 0 ;
memset ( & V_5 -> V_22 , 0 , sizeof( V_23 ) ) ;
return V_5 ;
}
STATIC void
F_10 (
struct V_24 * V_25 )
{
struct V_26 * V_26 = F_11 ( V_25 , struct V_26 , V_27 ) ;
struct V_1 * V_5 = F_12 ( V_26 ) ;
F_5 ( V_6 , V_5 ) ;
}
void
F_13 (
struct V_1 * V_5 )
{
switch ( V_5 -> V_22 . V_28 & V_29 ) {
case V_30 :
case V_31 :
case V_32 :
F_14 ( V_5 , V_33 ) ;
break;
}
if ( V_5 -> V_17 )
F_14 ( V_5 , V_34 ) ;
if ( V_5 -> V_35 ) {
ASSERT ( ! ( V_5 -> V_35 -> V_36 . V_37 & V_38 ) ) ;
F_15 ( V_5 ) ;
V_5 -> V_35 = NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_10 ) ) ;
ASSERT ( ! F_8 ( V_5 ) ) ;
F_16 ( & V_5 -> V_10 ) ;
V_5 -> V_20 = V_39 ;
V_5 -> V_11 = 0 ;
F_17 ( & V_5 -> V_10 ) ;
F_18 ( & F_4 ( V_5 ) -> V_27 , F_10 ) ;
}
static int
F_19 (
struct V_40 * V_41 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_42 ,
int V_43 ) __releases( T_2 )
{
struct V_26 * V_26 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_14 ;
int error ;
F_16 ( & V_5 -> V_10 ) ;
if ( V_5 -> V_11 != V_4 ) {
F_20 ( V_5 ) ;
F_21 ( V_44 ) ;
error = V_45 ;
goto V_46;
}
if ( V_5 -> V_20 & ( V_47 | V_39 ) ) {
F_20 ( V_5 ) ;
F_21 ( V_44 ) ;
error = V_45 ;
goto V_46;
}
if ( V_5 -> V_22 . V_28 == 0 && ! ( V_42 & V_48 ) ) {
error = V_49 ;
goto V_46;
}
if ( V_5 -> V_20 & V_50 ) {
F_22 ( V_5 ) ;
V_5 -> V_20 |= V_39 ;
F_17 ( & V_5 -> V_10 ) ;
F_23 () ;
error = - F_3 ( V_3 -> V_8 , V_26 ) ;
if ( error ) {
F_24 () ;
F_16 ( & V_5 -> V_10 ) ;
V_5 -> V_20 &= ~ ( V_47 | V_39 ) ;
ASSERT ( V_5 -> V_20 & V_50 ) ;
F_25 ( V_5 ) ;
goto V_46;
}
F_16 ( & V_41 -> V_51 ) ;
F_16 ( & V_5 -> V_10 ) ;
V_5 -> V_20 &= ~ V_52 ;
V_5 -> V_20 |= V_47 ;
F_26 ( V_3 , V_41 , V_5 ) ;
V_26 -> V_53 = V_54 ;
ASSERT ( ! F_27 ( & V_5 -> V_12 . V_55 ) ) ;
F_9 ( & V_5 -> V_12 , V_13 , L_1 , V_5 -> V_11 ) ;
F_17 ( & V_5 -> V_10 ) ;
F_17 ( & V_41 -> V_51 ) ;
} else {
if ( ! F_28 ( V_26 ) ) {
F_20 ( V_5 ) ;
error = V_45 ;
goto V_46;
}
F_17 ( & V_5 -> V_10 ) ;
F_23 () ;
F_29 ( V_5 ) ;
}
if ( V_43 != 0 )
F_30 ( V_5 , V_43 ) ;
F_31 ( V_5 , V_56 | V_57 ) ;
F_21 ( V_58 ) ;
return 0 ;
V_46:
F_17 ( & V_5 -> V_10 ) ;
F_23 () ;
return error ;
}
static int
F_32 (
struct V_2 * V_3 ,
struct V_40 * V_41 ,
T_3 * V_59 ,
T_1 V_4 ,
struct V_1 * * V_60 ,
int V_42 ,
int V_43 )
{
struct V_1 * V_5 ;
int error ;
T_4 V_61 = F_33 ( V_3 , V_4 ) ;
int V_62 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return V_63 ;
error = F_34 ( V_3 , V_59 , V_5 , V_42 ) ;
if ( error )
goto V_64;
F_35 ( V_5 ) ;
if ( ( V_5 -> V_22 . V_28 == 0 ) && ! ( V_42 & V_48 ) ) {
error = V_49 ;
goto V_64;
}
if ( F_36 ( V_65 ) ) {
error = V_45 ;
goto V_64;
}
if ( V_43 ) {
if ( ! F_37 ( V_5 , V_43 ) )
F_38 () ;
}
V_62 = V_47 ;
if ( V_42 & V_66 )
V_62 |= V_57 ;
V_5 -> V_67 = V_5 -> V_68 = NULL ;
F_39 ( V_5 , V_62 ) ;
F_16 ( & V_41 -> V_51 ) ;
error = F_40 ( & V_41 -> V_69 , V_61 , V_5 ) ;
if ( F_41 ( error ) ) {
F_42 ( error != - V_70 ) ;
F_21 ( V_71 ) ;
error = V_45 ;
goto V_72;
}
F_17 ( & V_41 -> V_51 ) ;
F_43 () ;
* V_60 = V_5 ;
return 0 ;
V_72:
F_17 ( & V_41 -> V_51 ) ;
F_43 () ;
if ( V_43 )
F_44 ( V_5 , V_43 ) ;
V_64:
F_45 ( F_4 ( V_5 ) ) ;
F_13 ( V_5 ) ;
return error ;
}
int
F_46 (
T_5 * V_3 ,
T_3 * V_59 ,
T_1 V_4 ,
T_6 V_42 ,
T_6 V_43 ,
T_7 * * V_60 )
{
T_7 * V_5 ;
int error ;
T_8 * V_41 ;
T_4 V_61 ;
ASSERT ( ( V_43 & ( V_73 | V_74 ) ) == 0 ) ;
if ( ! V_4 || F_47 ( V_3 , V_4 ) >= V_3 -> V_75 . V_76 )
return V_77 ;
V_41 = F_48 ( V_3 , F_47 ( V_3 , V_4 ) ) ;
V_61 = F_33 ( V_3 , V_4 ) ;
V_78:
error = 0 ;
F_24 () ;
V_5 = F_49 ( & V_41 -> V_69 , V_61 ) ;
if ( V_5 ) {
error = F_19 ( V_41 , V_5 , V_4 , V_42 , V_43 ) ;
if ( error )
goto V_79;
} else {
F_23 () ;
F_21 ( V_80 ) ;
error = F_32 ( V_3 , V_41 , V_59 , V_4 , & V_5 ,
V_42 , V_43 ) ;
if ( error )
goto V_79;
}
F_50 ( V_41 ) ;
* V_60 = V_5 ;
if ( F_51 ( V_5 , V_47 ) && V_5 -> V_22 . V_28 != 0 )
F_52 ( V_5 ) ;
return 0 ;
V_79:
if ( error == V_45 ) {
F_53 ( 1 ) ;
goto V_78;
}
F_50 ( V_41 ) ;
return error ;
}
T_6
F_54 (
T_7 * V_5 )
{
T_6 V_81 ;
if ( ( V_5 -> V_22 . V_82 == V_83 ) &&
( ( V_5 -> V_18 . V_84 & V_85 ) == 0 ) ) {
V_81 = V_86 ;
} else {
V_81 = V_87 ;
}
F_30 ( V_5 , V_81 ) ;
return V_81 ;
}
void
F_55 (
T_7 * V_5 ,
unsigned int V_81 )
{
F_44 ( V_5 , V_81 ) ;
}
void
F_30 (
T_7 * V_5 ,
T_6 V_43 )
{
ASSERT ( ( V_43 & ( V_74 | V_73 ) ) !=
( V_74 | V_73 ) ) ;
ASSERT ( ( V_43 & ( V_87 | V_86 ) ) !=
( V_87 | V_86 ) ) ;
ASSERT ( ( V_43 & ~ ( V_88 | V_89 ) ) == 0 ) ;
if ( V_43 & V_73 )
F_56 ( & V_5 -> V_12 , F_57 ( V_43 ) ) ;
else if ( V_43 & V_74 )
F_58 ( & V_5 -> V_12 , F_57 ( V_43 ) ) ;
if ( V_43 & V_86 )
F_56 ( & V_5 -> V_90 , F_59 ( V_43 ) ) ;
else if ( V_43 & V_87 )
F_58 ( & V_5 -> V_90 , F_59 ( V_43 ) ) ;
F_60 ( V_5 , V_43 , V_91 ) ;
}
int
F_37 (
T_7 * V_5 ,
T_6 V_43 )
{
ASSERT ( ( V_43 & ( V_74 | V_73 ) ) !=
( V_74 | V_73 ) ) ;
ASSERT ( ( V_43 & ( V_87 | V_86 ) ) !=
( V_87 | V_86 ) ) ;
ASSERT ( ( V_43 & ~ ( V_88 | V_89 ) ) == 0 ) ;
if ( V_43 & V_73 ) {
if ( ! F_61 ( & V_5 -> V_12 ) )
goto V_92;
} else if ( V_43 & V_74 ) {
if ( ! F_62 ( & V_5 -> V_12 ) )
goto V_92;
}
if ( V_43 & V_86 ) {
if ( ! F_61 ( & V_5 -> V_90 ) )
goto V_93;
} else if ( V_43 & V_87 ) {
if ( ! F_62 ( & V_5 -> V_90 ) )
goto V_93;
}
F_63 ( V_5 , V_43 , V_91 ) ;
return 1 ;
V_93:
if ( V_43 & V_73 )
F_64 ( & V_5 -> V_12 ) ;
else if ( V_43 & V_74 )
F_65 ( & V_5 -> V_12 ) ;
V_92:
return 0 ;
}
void
F_44 (
T_7 * V_5 ,
T_6 V_43 )
{
ASSERT ( ( V_43 & ( V_74 | V_73 ) ) !=
( V_74 | V_73 ) ) ;
ASSERT ( ( V_43 & ( V_87 | V_86 ) ) !=
( V_87 | V_86 ) ) ;
ASSERT ( ( V_43 & ~ ( V_88 | V_89 ) ) == 0 ) ;
ASSERT ( V_43 != 0 ) ;
if ( V_43 & V_73 )
F_64 ( & V_5 -> V_12 ) ;
else if ( V_43 & V_74 )
F_65 ( & V_5 -> V_12 ) ;
if ( V_43 & V_86 )
F_64 ( & V_5 -> V_90 ) ;
else if ( V_43 & V_87 )
F_65 ( & V_5 -> V_90 ) ;
F_66 ( V_5 , V_43 , V_91 ) ;
}
void
F_67 (
T_7 * V_5 ,
T_6 V_43 )
{
ASSERT ( V_43 & ( V_73 | V_86 ) ) ;
ASSERT ( ( V_43 & ~ ( V_73 | V_86 ) ) == 0 ) ;
if ( V_43 & V_86 )
F_68 ( & V_5 -> V_90 ) ;
if ( V_43 & V_73 )
F_68 ( & V_5 -> V_12 ) ;
F_69 ( V_5 , V_43 , V_91 ) ;
}
int
F_70 (
T_7 * V_5 ,
T_6 V_43 )
{
if ( V_43 & ( V_86 | V_87 ) ) {
if ( ! ( V_43 & V_87 ) )
return ! ! V_5 -> V_90 . V_94 ;
return F_27 ( & V_5 -> V_90 . V_55 ) ;
}
if ( V_43 & ( V_73 | V_74 ) ) {
if ( ! ( V_43 & V_74 ) )
return ! ! V_5 -> V_12 . V_94 ;
return F_27 ( & V_5 -> V_12 . V_55 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
void
F_71 (
struct V_1 * V_5 )
{
T_9 * V_95 = F_72 ( & V_5 -> V_20 , V_96 ) ;
F_73 ( V_97 , & V_5 -> V_20 , V_96 ) ;
do {
F_74 ( V_95 , & V_97 . V_97 , V_98 ) ;
if ( F_8 ( V_5 ) )
F_75 () ;
} while ( ! F_76 ( V_5 ) );
F_77 ( V_95 , & V_97 . V_97 ) ;
}
