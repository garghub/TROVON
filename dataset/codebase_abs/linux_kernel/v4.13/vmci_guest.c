bool F_1 ( void )
{
return F_2 ( & V_1 ) != 0 ;
}
T_1 F_3 ( void )
{
if ( V_2 == V_3 ) {
struct V_4 V_5 ;
V_5 . V_6 =
F_4 ( V_7 ,
V_8 ) ;
V_5 . V_9 = V_10 ;
V_5 . V_11 = 0 ;
V_2 = F_5 ( & V_5 ) ;
}
return V_2 ;
}
int F_5 ( struct V_4 * V_12 )
{
unsigned long V_13 ;
int V_14 ;
if ( V_12 == NULL )
return V_15 ;
F_6 ( & V_16 , V_13 ) ;
if ( V_17 ) {
F_7 ( V_17 -> V_18 + V_19 ,
V_12 , F_8 ( V_12 ) ) ;
V_14 = F_9 ( V_17 -> V_18 + V_20 ) ;
} else {
V_14 = V_21 ;
}
F_10 ( & V_16 , V_13 ) ;
return V_14 ;
}
static void F_11 ( T_1 V_22 ,
const struct V_23 * V_24 ,
void * V_25 )
{
const struct V_26 * V_27 =
F_12 ( V_24 ) ;
if ( V_22 != V_28 ) {
F_13 ( L_1 , V_22 ) ;
return;
}
if ( ! V_24 || V_27 -> V_29 == V_3 ) {
F_13 ( L_2 ) ;
return;
}
F_13 ( L_3 ,
V_2 , V_27 -> V_29 , V_24 -> V_30 ) ;
V_2 = V_27 -> V_29 ;
}
static int F_14 ( struct V_31 * V_32 )
{
bool V_14 ;
struct V_33 * V_34 ;
T_1 V_35 = sizeof( struct V_36 ) +
V_37 * sizeof( T_1 ) ;
struct V_4 * V_38 ;
V_38 = F_15 ( V_35 , V_39 ) ;
if ( ! V_38 ) {
F_16 ( & V_32 -> V_40 , L_4 , V_41 ) ;
return - V_42 ;
}
V_38 -> V_6 = F_4 ( V_7 ,
V_43 ) ;
V_38 -> V_9 = V_10 ;
V_38 -> V_11 = V_35 - V_44 ;
V_34 = (struct V_33 * ) F_17 ( V_38 ) ;
V_34 -> V_45 = V_37 ;
V_34 -> V_46 [ 0 ] = V_8 ;
V_14 = F_5 ( V_38 ) == 0x01 ;
F_18 ( V_38 ) ;
F_19 ( & V_32 -> V_40 , L_5 ,
V_41 , V_14 ? L_6 : L_7 ) ;
return V_14 ? 0 : - V_47 ;
}
static void F_20 ( unsigned long V_48 )
{
struct V_49 * V_50 = (struct V_49 * ) V_48 ;
T_2 * V_51 = V_50 -> V_52 ;
struct V_4 * V_12 ;
T_3 V_53 = V_54 ;
T_3 V_55 = V_56 ;
T_3 V_57 ;
F_21 ( V_54 < V_56 ) ;
F_22 ( V_50 -> V_18 + V_58 ,
V_50 -> V_52 , V_55 ) ;
V_12 = (struct V_4 * ) V_51 ;
V_57 = V_55 ;
while ( V_12 -> V_6 . V_59 != V_3 ||
V_57 > V_56 ) {
unsigned V_60 ;
if ( V_12 -> V_6 . V_59 == V_3 ) {
V_12 = (struct V_4 * ) F_23 (
( V_61 ) V_12 + 1 , V_56 ) ;
V_57 =
( T_3 ) ( V_51 +
V_55 -
( T_2 * ) V_12 ) ;
continue;
}
V_60 = F_24 ( V_12 ) ;
if ( V_60 <= V_53 ) {
int V_14 ;
if ( V_60 > V_57 ) {
if ( V_57 !=
V_55 ) {
memmove ( V_51 , V_51 +
V_55 -
V_57 ,
V_57 ) ;
V_12 = (struct V_4 * )
V_51 ;
}
if ( V_55 !=
V_53 )
V_55 =
V_53 ;
F_22 ( V_50 -> V_18 +
V_58 ,
V_50 -> V_52 +
V_57 ,
V_55 -
V_57 ) ;
}
if ( V_12 -> V_9 . V_62 == V_7 &&
V_12 -> V_6 . V_59 == V_63 ) {
V_14 = F_25 ( V_12 ) ;
} else {
V_14 = F_26 ( V_12 ) ;
}
if ( V_14 < V_64 )
F_19 ( V_50 -> V_40 ,
L_8 ,
V_12 -> V_6 . V_59 , V_14 ) ;
V_12 = (struct V_4 * ) ( ( T_2 * ) V_12 +
V_60 ) ;
} else {
T_3 V_65 ;
F_19 ( V_50 -> V_40 ,
L_9 ,
V_60 ) ;
V_65 = V_60 - V_57 ;
if ( V_55 != V_53 )
V_55 = V_53 ;
for (; ; ) {
F_22 ( V_50 -> V_18 +
V_58 ,
V_50 -> V_52 ,
V_55 ) ;
if ( V_65 <= V_55 )
break;
V_65 -= V_55 ;
}
V_12 = (struct V_4 * ) ( V_51 +
V_65 ) ;
}
V_57 =
( T_3 ) ( V_51 + V_55 -
( T_2 * ) V_12 ) ;
if ( V_57 < V_44 ) {
F_22 ( V_50 -> V_18 + V_58 ,
V_50 -> V_52 ,
V_55 ) ;
V_12 = (struct V_4 * ) V_51 ;
V_57 = V_55 ;
}
}
}
static void F_27 ( unsigned long V_48 )
{
struct V_49 * V_40 = (struct V_49 * ) V_48 ;
if ( ! V_40 -> V_66 ) {
F_19 ( V_40 -> V_40 , L_10 , V_41 ) ;
return;
}
F_28 ( V_40 -> V_66 ) ;
}
static T_4 F_29 ( int V_67 , void * V_68 )
{
struct V_49 * V_40 = V_68 ;
if ( V_40 -> V_69 ) {
F_30 ( & V_40 -> V_70 ) ;
} else {
unsigned int V_71 ;
V_71 = F_9 ( V_40 -> V_18 + V_72 ) ;
if ( V_71 == 0 || V_71 == ~ 0 )
return V_73 ;
if ( V_71 & V_74 ) {
F_30 ( & V_40 -> V_70 ) ;
V_71 &= ~ V_74 ;
}
if ( V_71 & V_75 ) {
F_30 ( & V_40 -> V_76 ) ;
V_71 &= ~ V_75 ;
}
if ( V_71 != 0 )
F_31 ( V_40 -> V_40 ,
L_11 ,
V_71 ) ;
}
return V_77 ;
}
static T_4 F_32 ( int V_67 , void * V_68 )
{
struct V_49 * V_40 = V_68 ;
F_30 ( & V_40 -> V_76 ) ;
return V_77 ;
}
static int F_33 ( struct V_31 * V_32 ,
const struct V_78 * V_79 )
{
struct V_49 * V_50 ;
void T_5 * V_18 ;
unsigned int V_80 ;
unsigned long V_81 ;
int V_82 ;
int error ;
F_19 ( & V_32 -> V_40 , L_12 ) ;
error = F_34 ( V_32 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 ,
L_13 , error ) ;
return error ;
}
error = F_35 ( V_32 , 1 << 0 , V_83 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 , L_14 ) ;
return error ;
}
V_18 = F_36 ( V_32 ) [ 0 ] ;
F_37 ( & V_32 -> V_40 , L_15 ,
( unsigned long ) V_18 , V_32 -> V_67 ) ;
V_50 = F_38 ( & V_32 -> V_40 , sizeof( * V_50 ) , V_39 ) ;
if ( ! V_50 ) {
F_16 ( & V_32 -> V_40 ,
L_16 ) ;
return - V_42 ;
}
V_50 -> V_40 = & V_32 -> V_40 ;
V_50 -> V_69 = false ;
V_50 -> V_18 = V_18 ;
F_39 ( & V_50 -> V_70 ,
F_20 , ( unsigned long ) V_50 ) ;
F_39 ( & V_50 -> V_76 ,
F_27 , ( unsigned long ) V_50 ) ;
V_50 -> V_52 = F_40 ( V_54 ) ;
if ( ! V_50 -> V_52 ) {
F_16 ( & V_32 -> V_40 ,
L_17 ) ;
return - V_42 ;
}
F_41 ( V_32 ) ;
V_80 = F_9 ( V_50 -> V_18 + V_84 ) ;
if ( ! ( V_80 & V_85 ) ) {
F_16 ( & V_32 -> V_40 , L_18 ) ;
error = - V_47 ;
goto V_86;
}
if ( V_80 & V_87 ) {
V_50 -> V_66 = F_42 (
& V_32 -> V_40 , V_56 , & V_50 -> V_88 ,
V_39 ) ;
if ( ! V_50 -> V_66 ) {
F_31 ( & V_32 -> V_40 ,
L_19 ) ;
} else {
memset ( V_50 -> V_66 , 0 , V_56 ) ;
V_80 |= V_87 ;
}
}
F_37 ( & V_32 -> V_40 , L_20 , V_80 ) ;
F_43 ( V_80 , V_50 -> V_18 + V_84 ) ;
F_44 ( & V_16 ) ;
V_17 = V_50 ;
V_89 = V_32 ;
F_45 ( & V_16 ) ;
if ( V_80 & V_87 ) {
unsigned long V_90 =
V_50 -> V_88 >> V_91 ;
if ( ! F_46 ( V_90 ) ) {
F_31 ( & V_32 -> V_40 ,
L_21 ,
( T_1 ) V_90 ) ;
error = - V_47 ;
goto V_92;
}
}
error = F_14 ( V_32 ) ;
if ( error )
goto V_93;
V_82 = F_47 ( V_94 ,
F_11 , NULL ,
& V_28 ) ;
if ( V_82 < V_64 )
F_31 ( & V_32 -> V_40 ,
L_22 ,
V_94 , V_82 ) ;
error = F_48 ( V_32 , V_95 , V_95 ,
V_96 ) ;
if ( error < 0 ) {
error = F_48 ( V_32 , 1 , 1 ,
V_96 | V_97 | V_98 ) ;
if ( error < 0 )
goto V_93;
} else {
V_50 -> V_69 = true ;
}
error = F_49 ( F_50 ( V_32 , 0 ) , F_29 ,
V_99 , V_83 , V_50 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 , L_23 ,
F_50 ( V_32 , 0 ) , error ) ;
goto V_100;
}
if ( V_50 -> V_69 ) {
error = F_49 ( F_50 ( V_32 , 1 ) ,
F_32 , 0 , V_83 ,
V_50 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 ,
L_24 ,
F_50 ( V_32 , 1 ) , error ) ;
goto V_101;
}
}
F_19 ( & V_32 -> V_40 , L_25 ) ;
F_51 ( & V_1 ) ;
V_81 = V_102 ;
if ( V_80 & V_87 )
V_81 |= V_103 ;
F_43 ( V_81 , V_50 -> V_18 + V_104 ) ;
F_43 ( V_105 ,
V_50 -> V_18 + V_106 ) ;
F_52 ( V_32 , V_50 ) ;
return 0 ;
V_101:
F_53 ( F_50 ( V_32 , 0 ) , V_50 ) ;
F_54 ( & V_50 -> V_70 ) ;
F_54 ( & V_50 -> V_76 ) ;
V_100:
F_55 ( V_32 ) ;
V_82 = F_56 ( V_28 ) ;
if ( V_82 < V_64 )
F_31 ( & V_32 -> V_40 ,
L_26 ,
V_94 , V_28 , V_82 ) ;
V_93:
if ( V_50 -> V_66 ) {
F_43 ( V_107 ,
V_50 -> V_18 + V_106 ) ;
F_57 ( & V_32 -> V_40 , V_56 ,
V_50 -> V_66 ,
V_50 -> V_88 ) ;
}
V_92:
F_44 ( & V_16 ) ;
V_89 = NULL ;
V_17 = NULL ;
F_45 ( & V_16 ) ;
V_86:
F_58 ( V_50 -> V_52 ) ;
return error ;
}
static void F_59 ( struct V_31 * V_32 )
{
struct V_49 * V_50 = F_60 ( V_32 ) ;
int V_82 ;
F_19 ( & V_32 -> V_40 , L_27 ) ;
F_61 ( & V_1 ) ;
F_62 () ;
V_82 = F_56 ( V_28 ) ;
if ( V_82 < V_64 )
F_31 ( & V_32 -> V_40 ,
L_26 ,
V_94 , V_28 , V_82 ) ;
F_44 ( & V_16 ) ;
V_17 = NULL ;
V_89 = NULL ;
F_45 ( & V_16 ) ;
F_19 ( & V_32 -> V_40 , L_28 ) ;
F_43 ( V_107 , V_50 -> V_18 + V_106 ) ;
if ( V_50 -> V_69 )
F_53 ( F_50 ( V_32 , 1 ) , V_50 ) ;
F_53 ( F_50 ( V_32 , 0 ) , V_50 ) ;
F_55 ( V_32 ) ;
F_54 ( & V_50 -> V_70 ) ;
F_54 ( & V_50 -> V_76 ) ;
if ( V_50 -> V_66 ) {
F_57 ( & V_32 -> V_40 , V_56 ,
V_50 -> V_66 ,
V_50 -> V_88 ) ;
}
F_58 ( V_50 -> V_52 ) ;
}
int T_6 F_63 ( void )
{
return F_64 ( & V_108 ) ;
}
void T_7 F_65 ( void )
{
F_66 ( & V_108 ) ;
}
