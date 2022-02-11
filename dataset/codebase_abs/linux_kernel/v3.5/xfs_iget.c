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
memset ( & V_5 -> V_24 , 0 , sizeof( V_25 ) ) ;
return V_5 ;
}
STATIC void
F_11 (
struct V_26 * V_27 )
{
struct V_28 * V_28 = F_12 ( V_27 , struct V_28 , V_29 ) ;
struct V_1 * V_5 = F_13 ( V_28 ) ;
F_5 ( V_6 , V_5 ) ;
}
void
F_14 (
struct V_1 * V_5 )
{
switch ( V_5 -> V_24 . V_30 & V_31 ) {
case V_32 :
case V_33 :
case V_34 :
F_15 ( V_5 , V_35 ) ;
break;
}
if ( V_5 -> V_19 )
F_15 ( V_5 , V_36 ) ;
if ( V_5 -> V_37 ) {
ASSERT ( ! ( V_5 -> V_37 -> V_38 . V_39 & V_40 ) ) ;
F_16 ( V_5 ) ;
V_5 -> V_37 = NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_10 ) ) ;
ASSERT ( ! F_8 ( V_5 ) ) ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 = V_41 ;
V_5 -> V_11 = 0 ;
F_18 ( & V_5 -> V_10 ) ;
F_19 ( & F_4 ( V_5 ) -> V_29 , F_11 ) ;
}
static int
F_20 (
struct V_42 * V_43 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_44 ,
int V_45 ) __releases( T_2 )
{
struct V_28 * V_28 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_16 ;
int error ;
F_17 ( & V_5 -> V_10 ) ;
if ( V_5 -> V_11 != V_4 ) {
F_21 ( V_5 ) ;
F_22 ( V_46 ) ;
error = V_47 ;
goto V_48;
}
if ( V_5 -> V_22 & ( V_49 | V_41 ) ) {
F_21 ( V_5 ) ;
F_22 ( V_46 ) ;
error = V_47 ;
goto V_48;
}
if ( V_5 -> V_24 . V_30 == 0 && ! ( V_44 & V_50 ) ) {
error = V_51 ;
goto V_48;
}
if ( V_5 -> V_22 & V_52 ) {
F_23 ( V_5 ) ;
V_5 -> V_22 |= V_41 ;
F_18 ( & V_5 -> V_10 ) ;
F_24 () ;
error = - F_3 ( V_3 -> V_8 , V_28 ) ;
if ( error ) {
F_25 () ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 &= ~ ( V_49 | V_41 ) ;
ASSERT ( V_5 -> V_22 & V_52 ) ;
F_26 ( V_5 ) ;
goto V_48;
}
F_17 ( & V_43 -> V_53 ) ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 &= ~ V_54 ;
V_5 -> V_22 |= V_49 ;
F_27 ( V_3 , V_43 , V_5 ) ;
V_28 -> V_55 = V_56 ;
ASSERT ( ! F_28 ( & V_5 -> V_12 . V_14 ) ) ;
F_9 ( & V_5 -> V_12 , V_13 , L_1 , V_5 -> V_11 ) ;
F_10 ( & V_5 -> V_12 . V_14 ,
& V_15 , L_2 ) ;
F_18 ( & V_5 -> V_10 ) ;
F_18 ( & V_43 -> V_53 ) ;
} else {
if ( ! F_29 ( V_28 ) ) {
F_21 ( V_5 ) ;
error = V_47 ;
goto V_48;
}
F_18 ( & V_5 -> V_10 ) ;
F_24 () ;
F_30 ( V_5 ) ;
}
if ( V_45 != 0 )
F_31 ( V_5 , V_45 ) ;
F_32 ( V_5 , V_57 | V_58 ) ;
F_22 ( V_59 ) ;
return 0 ;
V_48:
F_18 ( & V_5 -> V_10 ) ;
F_24 () ;
return error ;
}
static int
F_33 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
T_3 * V_60 ,
T_1 V_4 ,
struct V_1 * * V_61 ,
int V_44 ,
int V_45 )
{
struct V_1 * V_5 ;
int error ;
T_4 V_62 = F_34 ( V_3 , V_4 ) ;
int V_63 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return V_64 ;
error = F_35 ( V_3 , V_60 , V_5 , V_44 ) ;
if ( error )
goto V_65;
F_36 ( V_5 ) ;
if ( ( V_5 -> V_24 . V_30 == 0 ) && ! ( V_44 & V_50 ) ) {
error = V_51 ;
goto V_65;
}
if ( F_37 ( V_66 ) ) {
error = V_47 ;
goto V_65;
}
if ( V_45 ) {
if ( ! F_38 ( V_5 , V_45 ) )
F_39 () ;
}
V_63 = V_49 ;
if ( V_44 & V_67 )
V_63 |= V_58 ;
V_5 -> V_68 = V_5 -> V_69 = NULL ;
F_40 ( V_5 , V_63 ) ;
F_17 ( & V_43 -> V_53 ) ;
error = F_41 ( & V_43 -> V_70 , V_62 , V_5 ) ;
if ( F_42 ( error ) ) {
F_43 ( error != - V_71 ) ;
F_22 ( V_72 ) ;
error = V_47 ;
goto V_73;
}
F_18 ( & V_43 -> V_53 ) ;
F_44 () ;
* V_61 = V_5 ;
return 0 ;
V_73:
F_18 ( & V_43 -> V_53 ) ;
F_44 () ;
if ( V_45 )
F_45 ( V_5 , V_45 ) ;
V_65:
F_46 ( F_4 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return error ;
}
int
F_47 (
T_5 * V_3 ,
T_3 * V_60 ,
T_1 V_4 ,
T_6 V_44 ,
T_6 V_45 ,
T_7 * * V_61 )
{
T_7 * V_5 ;
int error ;
T_8 * V_43 ;
T_4 V_62 ;
ASSERT ( ( V_45 & ( V_74 | V_75 ) ) == 0 ) ;
if ( ! V_4 || F_48 ( V_3 , V_4 ) >= V_3 -> V_76 . V_77 )
return V_78 ;
V_43 = F_49 ( V_3 , F_48 ( V_3 , V_4 ) ) ;
V_62 = F_34 ( V_3 , V_4 ) ;
V_79:
error = 0 ;
F_25 () ;
V_5 = F_50 ( & V_43 -> V_70 , V_62 ) ;
if ( V_5 ) {
error = F_20 ( V_43 , V_5 , V_4 , V_44 , V_45 ) ;
if ( error )
goto V_80;
} else {
F_24 () ;
F_22 ( V_81 ) ;
error = F_33 ( V_3 , V_43 , V_60 , V_4 , & V_5 ,
V_44 , V_45 ) ;
if ( error )
goto V_80;
}
F_51 ( V_43 ) ;
* V_61 = V_5 ;
if ( F_52 ( V_5 , V_49 ) && V_5 -> V_24 . V_30 != 0 )
F_53 ( V_5 ) ;
return 0 ;
V_80:
if ( error == V_47 ) {
F_54 ( 1 ) ;
goto V_79;
}
F_51 ( V_43 ) ;
return error ;
}
T_6
F_55 (
T_7 * V_5 )
{
T_6 V_82 ;
if ( ( V_5 -> V_24 . V_83 == V_84 ) &&
( ( V_5 -> V_20 . V_85 & V_86 ) == 0 ) ) {
V_82 = V_87 ;
} else {
V_82 = V_88 ;
}
F_31 ( V_5 , V_82 ) ;
return V_82 ;
}
void
F_56 (
T_7 * V_5 ,
unsigned int V_82 )
{
F_45 ( V_5 , V_82 ) ;
}
void
F_31 (
T_7 * V_5 ,
T_6 V_45 )
{
ASSERT ( ( V_45 & ( V_75 | V_74 ) ) !=
( V_75 | V_74 ) ) ;
ASSERT ( ( V_45 & ( V_88 | V_87 ) ) !=
( V_88 | V_87 ) ) ;
ASSERT ( ( V_45 & ~ ( V_89 | V_90 ) ) == 0 ) ;
if ( V_45 & V_74 )
F_57 ( & V_5 -> V_12 , F_58 ( V_45 ) ) ;
else if ( V_45 & V_75 )
F_59 ( & V_5 -> V_12 , F_58 ( V_45 ) ) ;
if ( V_45 & V_87 )
F_57 ( & V_5 -> V_91 , F_60 ( V_45 ) ) ;
else if ( V_45 & V_88 )
F_59 ( & V_5 -> V_91 , F_60 ( V_45 ) ) ;
F_61 ( V_5 , V_45 , V_92 ) ;
}
int
F_38 (
T_7 * V_5 ,
T_6 V_45 )
{
ASSERT ( ( V_45 & ( V_75 | V_74 ) ) !=
( V_75 | V_74 ) ) ;
ASSERT ( ( V_45 & ( V_88 | V_87 ) ) !=
( V_88 | V_87 ) ) ;
ASSERT ( ( V_45 & ~ ( V_89 | V_90 ) ) == 0 ) ;
if ( V_45 & V_74 ) {
if ( ! F_62 ( & V_5 -> V_12 ) )
goto V_93;
} else if ( V_45 & V_75 ) {
if ( ! F_63 ( & V_5 -> V_12 ) )
goto V_93;
}
if ( V_45 & V_87 ) {
if ( ! F_62 ( & V_5 -> V_91 ) )
goto V_94;
} else if ( V_45 & V_88 ) {
if ( ! F_63 ( & V_5 -> V_91 ) )
goto V_94;
}
F_64 ( V_5 , V_45 , V_92 ) ;
return 1 ;
V_94:
if ( V_45 & V_74 )
F_65 ( & V_5 -> V_12 ) ;
else if ( V_45 & V_75 )
F_66 ( & V_5 -> V_12 ) ;
V_93:
return 0 ;
}
void
F_45 (
T_7 * V_5 ,
T_6 V_45 )
{
ASSERT ( ( V_45 & ( V_75 | V_74 ) ) !=
( V_75 | V_74 ) ) ;
ASSERT ( ( V_45 & ( V_88 | V_87 ) ) !=
( V_88 | V_87 ) ) ;
ASSERT ( ( V_45 & ~ ( V_89 | V_90 ) ) == 0 ) ;
ASSERT ( V_45 != 0 ) ;
if ( V_45 & V_74 )
F_65 ( & V_5 -> V_12 ) ;
else if ( V_45 & V_75 )
F_66 ( & V_5 -> V_12 ) ;
if ( V_45 & V_87 )
F_65 ( & V_5 -> V_91 ) ;
else if ( V_45 & V_88 )
F_66 ( & V_5 -> V_91 ) ;
F_67 ( V_5 , V_45 , V_92 ) ;
}
void
F_68 (
T_7 * V_5 ,
T_6 V_45 )
{
ASSERT ( V_45 & ( V_74 | V_87 ) ) ;
ASSERT ( ( V_45 & ~ ( V_74 | V_87 ) ) == 0 ) ;
if ( V_45 & V_87 )
F_69 ( & V_5 -> V_91 ) ;
if ( V_45 & V_74 )
F_69 ( & V_5 -> V_12 ) ;
F_70 ( V_5 , V_45 , V_92 ) ;
}
int
F_71 (
T_7 * V_5 ,
T_6 V_45 )
{
if ( V_45 & ( V_87 | V_88 ) ) {
if ( ! ( V_45 & V_88 ) )
return ! ! V_5 -> V_91 . V_95 ;
return F_28 ( & V_5 -> V_91 . V_14 ) ;
}
if ( V_45 & ( V_74 | V_75 ) ) {
if ( ! ( V_45 & V_75 ) )
return ! ! V_5 -> V_12 . V_95 ;
return F_28 ( & V_5 -> V_12 . V_14 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
void
F_72 (
struct V_1 * V_5 )
{
T_9 * V_96 = F_73 ( & V_5 -> V_22 , V_97 ) ;
F_74 ( V_98 , & V_5 -> V_22 , V_97 ) ;
do {
F_75 ( V_96 , & V_98 . V_98 , V_99 ) ;
if ( F_8 ( V_5 ) )
F_76 () ;
} while ( ! F_77 ( V_5 ) );
F_78 ( V_96 , & V_98 . V_98 ) ;
}
