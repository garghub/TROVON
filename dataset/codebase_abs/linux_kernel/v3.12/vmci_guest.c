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
static bool F_14 ( struct V_31 * V_32 )
{
bool V_14 ;
struct V_33 * V_34 ;
T_1 V_35 = sizeof( struct V_36 ) +
V_37 * sizeof( T_1 ) ;
struct V_4 * V_38 ;
V_38 = F_15 ( V_35 , V_39 ) ;
if ( ! V_38 ) {
F_16 ( & V_32 -> V_40 , L_4 , V_41 ) ;
return false ;
}
V_38 -> V_6 = F_4 ( V_7 ,
V_42 ) ;
V_38 -> V_9 = V_10 ;
V_38 -> V_11 = V_35 - V_43 ;
V_34 = (struct V_33 * ) F_17 ( V_38 ) ;
V_34 -> V_44 = V_37 ;
V_34 -> V_45 [ 0 ] = V_8 ;
V_14 = F_5 ( V_38 ) == 0x01 ;
F_18 ( V_38 ) ;
F_19 ( & V_32 -> V_40 , L_5 ,
V_41 , V_14 ? L_6 : L_7 ) ;
return V_14 ;
}
static void F_20 ( unsigned long V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
T_2 * V_49 = V_48 -> V_50 ;
struct V_4 * V_12 ;
T_3 V_51 = V_52 ;
T_3 V_53 = V_54 ;
T_3 V_55 ;
F_21 ( V_52 < V_54 ) ;
F_22 ( V_48 -> V_18 + V_56 ,
V_48 -> V_50 , V_53 ) ;
V_12 = (struct V_4 * ) V_49 ;
V_55 = V_53 ;
while ( V_12 -> V_6 . V_57 != V_3 ||
V_55 > V_54 ) {
unsigned V_58 ;
if ( V_12 -> V_6 . V_57 == V_3 ) {
V_12 = (struct V_4 * ) F_23 (
( V_59 ) V_12 + 1 , V_54 ) ;
V_55 =
( T_3 ) ( V_49 +
V_53 -
( T_2 * ) V_12 ) ;
continue;
}
V_58 = F_24 ( V_12 ) ;
if ( V_58 <= V_51 ) {
int V_14 ;
if ( V_58 > V_55 ) {
if ( V_55 !=
V_53 ) {
memmove ( V_49 , V_49 +
V_53 -
V_55 ,
V_55 ) ;
V_12 = (struct V_4 * )
V_49 ;
}
if ( V_53 !=
V_51 )
V_53 =
V_51 ;
F_22 ( V_48 -> V_18 +
V_56 ,
V_48 -> V_50 +
V_55 ,
V_53 -
V_55 ) ;
}
if ( V_12 -> V_9 . V_60 == V_7 &&
V_12 -> V_6 . V_57 == V_61 ) {
V_14 = F_25 ( V_12 ) ;
} else {
V_14 = F_26 ( V_12 ) ;
}
if ( V_14 < V_62 )
F_19 ( V_48 -> V_40 ,
L_8 ,
V_12 -> V_6 . V_57 , V_14 ) ;
V_12 = (struct V_4 * ) ( ( T_2 * ) V_12 +
V_58 ) ;
} else {
T_3 V_63 ;
F_19 ( V_48 -> V_40 ,
L_9 ,
V_58 ) ;
V_63 = V_58 - V_55 ;
if ( V_53 != V_51 )
V_53 = V_51 ;
for (; ; ) {
F_22 ( V_48 -> V_18 +
V_56 ,
V_48 -> V_50 ,
V_53 ) ;
if ( V_63 <= V_53 )
break;
V_63 -= V_53 ;
}
V_12 = (struct V_4 * ) ( V_49 +
V_63 ) ;
}
V_55 =
( T_3 ) ( V_49 + V_53 -
( T_2 * ) V_12 ) ;
if ( V_55 < V_43 ) {
F_22 ( V_48 -> V_18 + V_56 ,
V_48 -> V_50 ,
V_53 ) ;
V_12 = (struct V_4 * ) V_49 ;
V_55 = V_53 ;
}
}
}
static void F_27 ( unsigned long V_46 )
{
struct V_47 * V_40 = (struct V_47 * ) V_46 ;
if ( ! V_40 -> V_64 ) {
F_19 ( V_40 -> V_40 , L_10 , V_41 ) ;
return;
}
F_28 ( V_40 -> V_64 ) ;
}
static int F_29 ( struct V_31 * V_32 ,
struct V_47 * V_48 )
{
int V_65 ;
int V_14 ;
for ( V_65 = 0 ; V_65 < V_66 ; ++ V_65 ) {
V_48 -> V_67 [ V_65 ] . V_68 = V_65 ;
V_48 -> V_67 [ V_65 ] . V_69 = V_65 ;
}
V_14 = F_30 ( V_32 , V_48 -> V_67 , V_66 ) ;
if ( V_14 == 0 )
V_48 -> V_70 = true ;
else if ( V_14 > 0 )
V_14 = F_30 ( V_32 , V_48 -> V_67 , 1 ) ;
return V_14 ;
}
static T_4 F_31 ( int V_71 , void * V_72 )
{
struct V_47 * V_40 = V_72 ;
if ( V_40 -> V_73 == V_74 && V_40 -> V_70 ) {
F_32 ( & V_40 -> V_75 ) ;
} else {
unsigned int V_76 ;
V_76 = F_9 ( V_40 -> V_18 + V_77 ) ;
if ( V_76 == 0 || V_76 == ~ 0 )
return V_78 ;
if ( V_76 & V_79 ) {
F_32 ( & V_40 -> V_75 ) ;
V_76 &= ~ V_79 ;
}
if ( V_76 & V_80 ) {
F_32 ( & V_40 -> V_81 ) ;
V_76 &= ~ V_80 ;
}
if ( V_76 != 0 )
F_33 ( V_40 -> V_40 ,
L_11 ,
V_76 ) ;
}
return V_82 ;
}
static T_4 F_34 ( int V_71 , void * V_72 )
{
struct V_47 * V_40 = V_72 ;
F_32 ( & V_40 -> V_81 ) ;
return V_82 ;
}
static int F_35 ( struct V_31 * V_32 ,
const struct V_83 * V_84 )
{
struct V_47 * V_48 ;
void T_5 * V_18 ;
unsigned int V_85 ;
unsigned long V_86 ;
int V_87 ;
int error ;
F_19 ( & V_32 -> V_40 , L_12 ) ;
error = F_36 ( V_32 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 ,
L_13 , error ) ;
return error ;
}
error = F_37 ( V_32 , 1 << 0 , V_88 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 , L_14 ) ;
return error ;
}
V_18 = F_38 ( V_32 ) [ 0 ] ;
F_39 ( & V_32 -> V_40 , L_15 ,
( unsigned long ) V_18 , V_32 -> V_71 ) ;
V_48 = F_40 ( & V_32 -> V_40 , sizeof( * V_48 ) , V_39 ) ;
if ( ! V_48 ) {
F_16 ( & V_32 -> V_40 ,
L_16 ) ;
return - V_89 ;
}
V_48 -> V_40 = & V_32 -> V_40 ;
V_48 -> V_73 = V_90 ;
V_48 -> V_70 = false ;
V_48 -> V_18 = V_18 ;
F_41 ( & V_48 -> V_75 ,
F_20 , ( unsigned long ) V_48 ) ;
F_41 ( & V_48 -> V_81 ,
F_27 , ( unsigned long ) V_48 ) ;
V_48 -> V_50 = F_42 ( V_52 ) ;
if ( ! V_48 -> V_50 ) {
F_16 ( & V_32 -> V_40 ,
L_17 ) ;
return - V_89 ;
}
F_43 ( V_32 ) ;
V_85 = F_9 ( V_48 -> V_18 + V_91 ) ;
if ( ! ( V_85 & V_92 ) ) {
F_16 ( & V_32 -> V_40 , L_18 ) ;
error = - V_93 ;
goto V_94;
}
if ( V_85 & V_95 ) {
V_48 -> V_64 = F_44 (
& V_32 -> V_40 , V_54 , & V_48 -> V_96 ,
V_39 ) ;
if ( ! V_48 -> V_64 ) {
F_33 ( & V_32 -> V_40 ,
L_19 ) ;
} else {
memset ( V_48 -> V_64 , 0 , V_54 ) ;
V_85 |= V_95 ;
}
}
F_39 ( & V_32 -> V_40 , L_20 , V_85 ) ;
F_45 ( V_85 , V_48 -> V_18 + V_91 ) ;
F_46 ( & V_16 ) ;
V_17 = V_48 ;
V_97 = V_32 ;
F_47 ( & V_16 ) ;
if ( V_85 & V_95 ) {
unsigned long V_98 =
V_48 -> V_96 >> V_99 ;
if ( ! F_48 ( V_98 ) ) {
F_33 ( & V_32 -> V_40 ,
L_21 ,
( T_1 ) V_98 ) ;
goto V_100;
}
}
if ( ! F_14 ( V_32 ) )
goto V_101;
V_87 = F_49 ( V_102 ,
F_11 , NULL ,
& V_28 ) ;
if ( V_87 < V_62 )
F_33 ( & V_32 -> V_40 ,
L_22 ,
V_102 , V_87 ) ;
if ( ! V_103 && ! F_29 ( V_32 , V_48 ) ) {
V_48 -> V_73 = V_74 ;
V_48 -> V_71 = V_48 -> V_67 [ 0 ] . V_69 ;
} else if ( ! V_104 && ! F_50 ( V_32 ) ) {
V_48 -> V_73 = V_105 ;
V_48 -> V_71 = V_32 -> V_71 ;
} else {
V_48 -> V_73 = V_90 ;
V_48 -> V_71 = V_32 -> V_71 ;
}
error = F_51 ( V_48 -> V_71 , F_31 , V_106 ,
V_88 , V_48 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 , L_23 ,
V_48 -> V_71 , error ) ;
goto V_107;
}
if ( V_48 -> V_70 ) {
error = F_51 ( V_48 -> V_67 [ 1 ] . V_69 ,
F_34 , 0 , V_88 ,
V_48 ) ;
if ( error ) {
F_16 ( & V_32 -> V_40 ,
L_24 ,
V_48 -> V_67 [ 1 ] . V_69 , error ) ;
goto V_108;
}
}
F_19 ( & V_32 -> V_40 , L_25 ) ;
F_52 ( & V_1 ) ;
V_86 = V_109 ;
if ( V_85 & V_95 )
V_86 |= V_110 ;
F_45 ( V_86 , V_48 -> V_18 + V_111 ) ;
F_45 ( V_112 ,
V_48 -> V_18 + V_113 ) ;
F_53 ( V_32 , V_48 ) ;
return 0 ;
V_108:
F_54 ( V_48 -> V_71 , & V_48 ) ;
F_55 ( & V_48 -> V_75 ) ;
F_55 ( & V_48 -> V_81 ) ;
V_107:
if ( V_48 -> V_73 == V_74 )
F_56 ( V_32 ) ;
else if ( V_48 -> V_73 == V_105 )
F_57 ( V_32 ) ;
V_87 = F_58 ( V_28 ) ;
if ( V_87 < V_62 )
F_33 ( & V_32 -> V_40 ,
L_26 ,
V_102 , V_28 , V_87 ) ;
V_101:
if ( V_48 -> V_64 ) {
F_45 ( V_114 ,
V_48 -> V_18 + V_113 ) ;
F_59 ( & V_32 -> V_40 , V_54 ,
V_48 -> V_64 ,
V_48 -> V_96 ) ;
}
V_100:
F_46 ( & V_16 ) ;
V_97 = NULL ;
V_17 = NULL ;
F_47 ( & V_16 ) ;
V_94:
F_60 ( V_48 -> V_50 ) ;
return error ;
}
static void F_61 ( struct V_31 * V_32 )
{
struct V_47 * V_48 = F_62 ( V_32 ) ;
int V_87 ;
F_19 ( & V_32 -> V_40 , L_27 ) ;
F_63 ( & V_1 ) ;
F_64 () ;
V_87 = F_58 ( V_28 ) ;
if ( V_87 < V_62 )
F_33 ( & V_32 -> V_40 ,
L_26 ,
V_102 , V_28 , V_87 ) ;
F_46 ( & V_16 ) ;
V_17 = NULL ;
V_97 = NULL ;
F_47 ( & V_16 ) ;
F_19 ( & V_32 -> V_40 , L_28 ) ;
F_45 ( V_114 , V_48 -> V_18 + V_113 ) ;
F_54 ( V_48 -> V_71 , V_48 ) ;
if ( V_48 -> V_73 == V_74 ) {
if ( V_48 -> V_70 )
F_54 ( V_48 -> V_67 [ 1 ] . V_69 , V_48 ) ;
F_56 ( V_32 ) ;
} else if ( V_48 -> V_73 == V_105 ) {
F_57 ( V_32 ) ;
}
F_55 ( & V_48 -> V_75 ) ;
F_55 ( & V_48 -> V_81 ) ;
if ( V_48 -> V_64 ) {
F_59 ( & V_32 -> V_40 , V_54 ,
V_48 -> V_64 ,
V_48 -> V_96 ) ;
}
F_60 ( V_48 -> V_50 ) ;
}
int T_6 F_65 ( void )
{
return F_66 ( & V_115 ) ;
}
void T_7 F_67 ( void )
{
F_68 ( & V_115 ) ;
}
