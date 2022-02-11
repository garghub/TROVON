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
T_2 * V_38 = & V_5 -> V_37 -> V_39 ;
struct V_40 * V_41 = V_38 -> V_42 ;
ASSERT ( ( ( V_38 -> V_43 & V_44 ) == 0 ) ||
F_16 ( V_5 -> V_16 ) ) ;
if ( V_38 -> V_43 & V_44 ) {
F_17 ( & V_41 -> V_45 ) ;
if ( V_38 -> V_43 & V_44 )
F_18 ( V_41 , V_38 ) ;
else
F_19 ( & V_41 -> V_45 ) ;
}
F_20 ( V_5 ) ;
V_5 -> V_37 = NULL ;
}
ASSERT ( F_6 ( & V_5 -> V_9 ) == 0 ) ;
ASSERT ( ! F_7 ( & V_5 -> V_10 ) ) ;
ASSERT ( ! F_8 ( V_5 ) ) ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 = V_46 ;
V_5 -> V_11 = 0 ;
F_19 ( & V_5 -> V_10 ) ;
F_21 ( & F_4 ( V_5 ) -> V_29 , F_11 ) ;
}
static int
F_22 (
struct V_47 * V_48 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_49 ,
int V_50 ) __releases( T_3 )
{
struct V_28 * V_28 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_16 ;
int error ;
F_17 ( & V_5 -> V_10 ) ;
if ( V_5 -> V_11 != V_4 ) {
F_23 ( V_5 ) ;
F_24 ( V_51 ) ;
error = V_52 ;
goto V_53;
}
if ( V_5 -> V_22 & ( V_54 | V_46 ) ) {
F_23 ( V_5 ) ;
F_24 ( V_51 ) ;
error = V_52 ;
goto V_53;
}
if ( V_5 -> V_24 . V_30 == 0 && ! ( V_49 & V_55 ) ) {
error = V_56 ;
goto V_53;
}
if ( V_5 -> V_22 & V_57 ) {
F_25 ( V_5 ) ;
V_5 -> V_22 |= V_46 ;
F_19 ( & V_5 -> V_10 ) ;
F_26 () ;
error = - F_3 ( V_3 -> V_8 , V_28 ) ;
if ( error ) {
F_27 () ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 &= ~ ( V_54 | V_46 ) ;
ASSERT ( V_5 -> V_22 & V_57 ) ;
F_28 ( V_5 ) ;
goto V_53;
}
F_17 ( & V_48 -> V_58 ) ;
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_22 &= ~ V_59 ;
V_5 -> V_22 |= V_54 ;
F_29 ( V_3 , V_48 , V_5 ) ;
V_28 -> V_60 = V_61 ;
ASSERT ( ! F_30 ( & V_5 -> V_12 . V_14 ) ) ;
F_9 ( & V_5 -> V_12 , V_13 , L_1 , V_5 -> V_11 ) ;
F_10 ( & V_5 -> V_12 . V_14 ,
& V_15 , L_2 ) ;
F_19 ( & V_5 -> V_10 ) ;
F_19 ( & V_48 -> V_58 ) ;
} else {
if ( ! F_31 ( V_28 ) ) {
F_23 ( V_5 ) ;
error = V_52 ;
goto V_53;
}
F_19 ( & V_5 -> V_10 ) ;
F_26 () ;
F_32 ( V_5 ) ;
}
if ( V_50 != 0 )
F_33 ( V_5 , V_50 ) ;
F_34 ( V_5 , V_62 | V_63 ) ;
F_24 ( V_64 ) ;
return 0 ;
V_53:
F_19 ( & V_5 -> V_10 ) ;
F_26 () ;
return error ;
}
static int
F_35 (
struct V_2 * V_3 ,
struct V_47 * V_48 ,
T_4 * V_65 ,
T_1 V_4 ,
struct V_1 * * V_66 ,
int V_49 ,
int V_50 )
{
struct V_1 * V_5 ;
int error ;
T_5 V_67 = F_36 ( V_3 , V_4 ) ;
int V_68 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return V_69 ;
error = F_37 ( V_3 , V_65 , V_5 , V_49 ) ;
if ( error )
goto V_70;
F_38 ( V_5 ) ;
if ( ( V_5 -> V_24 . V_30 == 0 ) && ! ( V_49 & V_55 ) ) {
error = V_56 ;
goto V_70;
}
if ( F_39 ( V_71 ) ) {
error = V_52 ;
goto V_70;
}
if ( V_50 ) {
if ( ! F_40 ( V_5 , V_50 ) )
F_41 () ;
}
V_68 = V_54 ;
if ( V_49 & V_72 )
V_68 |= V_63 ;
V_5 -> V_73 = V_5 -> V_74 = NULL ;
F_42 ( V_5 , V_68 ) ;
F_17 ( & V_48 -> V_58 ) ;
error = F_43 ( & V_48 -> V_75 , V_67 , V_5 ) ;
if ( F_44 ( error ) ) {
F_45 ( error != - V_76 ) ;
F_24 ( V_77 ) ;
error = V_52 ;
goto V_78;
}
F_19 ( & V_48 -> V_58 ) ;
F_46 () ;
* V_66 = V_5 ;
return 0 ;
V_78:
F_19 ( & V_48 -> V_58 ) ;
F_46 () ;
if ( V_50 )
F_47 ( V_5 , V_50 ) ;
V_70:
F_48 ( F_4 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return error ;
}
int
F_49 (
T_6 * V_3 ,
T_4 * V_65 ,
T_1 V_4 ,
T_7 V_49 ,
T_7 V_50 ,
T_8 * * V_66 )
{
T_8 * V_5 ;
int error ;
T_9 * V_48 ;
T_5 V_67 ;
ASSERT ( ( V_50 & ( V_79 | V_80 ) ) == 0 ) ;
if ( ! V_4 || F_50 ( V_3 , V_4 ) >= V_3 -> V_81 . V_82 )
return V_83 ;
V_48 = F_51 ( V_3 , F_50 ( V_3 , V_4 ) ) ;
V_67 = F_36 ( V_3 , V_4 ) ;
V_84:
error = 0 ;
F_27 () ;
V_5 = F_52 ( & V_48 -> V_75 , V_67 ) ;
if ( V_5 ) {
error = F_22 ( V_48 , V_5 , V_4 , V_49 , V_50 ) ;
if ( error )
goto V_85;
} else {
F_26 () ;
F_24 ( V_86 ) ;
error = F_35 ( V_3 , V_48 , V_65 , V_4 , & V_5 ,
V_49 , V_50 ) ;
if ( error )
goto V_85;
}
F_53 ( V_48 ) ;
* V_66 = V_5 ;
if ( F_54 ( V_5 , V_54 ) && V_5 -> V_24 . V_30 != 0 )
F_55 ( V_5 ) ;
return 0 ;
V_85:
if ( error == V_52 ) {
F_56 ( 1 ) ;
goto V_84;
}
F_53 ( V_48 ) ;
return error ;
}
T_7
F_57 (
T_8 * V_5 )
{
T_7 V_87 ;
if ( ( V_5 -> V_24 . V_88 == V_89 ) &&
( ( V_5 -> V_20 . V_90 & V_91 ) == 0 ) ) {
V_87 = V_92 ;
} else {
V_87 = V_93 ;
}
F_33 ( V_5 , V_87 ) ;
return V_87 ;
}
void
F_58 (
T_8 * V_5 ,
unsigned int V_87 )
{
F_47 ( V_5 , V_87 ) ;
}
void
F_33 (
T_8 * V_5 ,
T_7 V_50 )
{
ASSERT ( ( V_50 & ( V_80 | V_79 ) ) !=
( V_80 | V_79 ) ) ;
ASSERT ( ( V_50 & ( V_93 | V_92 ) ) !=
( V_93 | V_92 ) ) ;
ASSERT ( ( V_50 & ~ ( V_94 | V_95 ) ) == 0 ) ;
if ( V_50 & V_79 )
F_59 ( & V_5 -> V_12 , F_60 ( V_50 ) ) ;
else if ( V_50 & V_80 )
F_61 ( & V_5 -> V_12 , F_60 ( V_50 ) ) ;
if ( V_50 & V_92 )
F_59 ( & V_5 -> V_96 , F_62 ( V_50 ) ) ;
else if ( V_50 & V_93 )
F_61 ( & V_5 -> V_96 , F_62 ( V_50 ) ) ;
F_63 ( V_5 , V_50 , V_97 ) ;
}
int
F_40 (
T_8 * V_5 ,
T_7 V_50 )
{
ASSERT ( ( V_50 & ( V_80 | V_79 ) ) !=
( V_80 | V_79 ) ) ;
ASSERT ( ( V_50 & ( V_93 | V_92 ) ) !=
( V_93 | V_92 ) ) ;
ASSERT ( ( V_50 & ~ ( V_94 | V_95 ) ) == 0 ) ;
if ( V_50 & V_79 ) {
if ( ! F_64 ( & V_5 -> V_12 ) )
goto V_98;
} else if ( V_50 & V_80 ) {
if ( ! F_65 ( & V_5 -> V_12 ) )
goto V_98;
}
if ( V_50 & V_92 ) {
if ( ! F_64 ( & V_5 -> V_96 ) )
goto V_99;
} else if ( V_50 & V_93 ) {
if ( ! F_65 ( & V_5 -> V_96 ) )
goto V_99;
}
F_66 ( V_5 , V_50 , V_97 ) ;
return 1 ;
V_99:
if ( V_50 & V_79 )
F_67 ( & V_5 -> V_12 ) ;
else if ( V_50 & V_80 )
F_68 ( & V_5 -> V_12 ) ;
V_98:
return 0 ;
}
void
F_47 (
T_8 * V_5 ,
T_7 V_50 )
{
ASSERT ( ( V_50 & ( V_80 | V_79 ) ) !=
( V_80 | V_79 ) ) ;
ASSERT ( ( V_50 & ( V_93 | V_92 ) ) !=
( V_93 | V_92 ) ) ;
ASSERT ( ( V_50 & ~ ( V_94 | V_95 ) ) == 0 ) ;
ASSERT ( V_50 != 0 ) ;
if ( V_50 & V_79 )
F_67 ( & V_5 -> V_12 ) ;
else if ( V_50 & V_80 )
F_68 ( & V_5 -> V_12 ) ;
if ( V_50 & V_92 )
F_67 ( & V_5 -> V_96 ) ;
else if ( V_50 & V_93 )
F_68 ( & V_5 -> V_96 ) ;
F_69 ( V_5 , V_50 , V_97 ) ;
}
void
F_70 (
T_8 * V_5 ,
T_7 V_50 )
{
ASSERT ( V_50 & ( V_79 | V_92 ) ) ;
ASSERT ( ( V_50 & ~ ( V_79 | V_92 ) ) == 0 ) ;
if ( V_50 & V_92 )
F_71 ( & V_5 -> V_96 ) ;
if ( V_50 & V_79 )
F_71 ( & V_5 -> V_12 ) ;
F_72 ( V_5 , V_50 , V_97 ) ;
}
int
F_73 (
T_8 * V_5 ,
T_7 V_50 )
{
if ( V_50 & ( V_92 | V_93 ) ) {
if ( ! ( V_50 & V_93 ) )
return ! ! V_5 -> V_96 . V_100 ;
return F_30 ( & V_5 -> V_96 . V_14 ) ;
}
if ( V_50 & ( V_79 | V_80 ) ) {
if ( ! ( V_50 & V_80 ) )
return ! ! V_5 -> V_12 . V_100 ;
return F_30 ( & V_5 -> V_12 . V_14 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
void
F_74 (
struct V_1 * V_5 )
{
T_10 * V_101 = F_75 ( & V_5 -> V_22 , V_102 ) ;
F_76 ( V_103 , & V_5 -> V_22 , V_102 ) ;
do {
F_77 ( V_101 , & V_103 . V_103 , V_104 ) ;
if ( F_8 ( V_5 ) )
F_78 () ;
} while ( ! F_79 ( V_5 ) );
F_80 ( V_101 , & V_103 . V_103 ) ;
}
