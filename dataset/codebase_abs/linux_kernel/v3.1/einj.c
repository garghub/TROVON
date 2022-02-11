static inline void F_1 ( T_1 V_1 , volatile void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_1 >> 32 , V_2 + 4 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_5 , F_5 ( V_5 ) ,
F_6 ( V_6 ) , V_6 -> V_7 ) ;
}
static int F_7 ( T_3 * type )
{
struct V_3 V_4 ;
int V_8 ;
F_3 ( & V_4 ) ;
V_8 = F_8 ( & V_4 , V_9 ) ;
if ( V_8 )
return V_8 ;
* type = F_9 ( & V_4 ) ;
return 0 ;
}
static int F_10 ( T_3 * type )
{
int V_8 ;
F_11 ( & V_10 ) ;
V_8 = F_7 ( type ) ;
F_12 ( & V_10 ) ;
return V_8 ;
}
static int F_13 ( T_4 * V_11 )
{
if ( ( V_12 ) * V_11 < V_13 ) {
F_14 (FW_WARN EINJ_PFX
L_1 ) ;
return 1 ;
}
* V_11 -= V_13 ;
F_15 ( V_13 ) ;
F_16 () ;
return 0 ;
}
static T_4 F_17 ( void )
{
int V_14 ;
T_4 V_15 = 0 ;
struct V_16 * V_17 ;
V_17 = F_6 ( V_6 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_7 ; V_14 ++ ) {
if ( V_17 -> V_18 == V_19 &&
V_17 -> V_20 == V_21 &&
V_17 -> V_22 . V_23 ==
V_24 )
memcpy ( & V_15 , & V_17 -> V_22 . V_25 ,
sizeof( V_15 ) ) ;
V_17 ++ ;
}
return V_15 ;
}
static int F_18 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 != sizeof( struct V_26 ) )
return - V_29 ;
if ( V_27 -> V_30 > V_31 ||
V_27 -> V_30 <= V_27 -> V_28 )
return - V_29 ;
if ( V_27 -> V_32 !=
( V_27 -> V_30 - V_27 -> V_28 ) /
sizeof( struct V_33 ) )
return - V_29 ;
return 0 ;
}
static int F_19 ( T_4 V_34 )
{
struct V_26 * V_27 = NULL ;
struct V_3 V_35 ;
struct V_36 V_37 ;
struct V_16 * V_38 ;
struct V_39 * V_40 ;
T_3 V_30 ;
int V_8 = - V_41 ;
V_40 = F_20 ( V_34 , sizeof( * V_27 ) ,
L_2 ) ;
if ( ! V_40 ) {
F_21 ( V_42
L_3 ,
( unsigned long long ) V_34 ,
( unsigned long long ) V_34 + sizeof( * V_27 ) ) ;
goto V_43;
}
V_27 = F_22 ( V_34 , sizeof( * V_27 ) ) ;
if ( ! V_27 ) {
F_21 ( V_42 L_4 ) ;
goto V_44;
}
V_8 = F_18 ( V_27 ) ;
if ( V_8 ) {
F_14 (FW_BUG EINJ_PFX
L_5 ) ;
goto V_44;
}
V_8 = - V_41 ;
V_30 = V_27 -> V_30 ;
V_40 = F_20 ( V_34 + sizeof( * V_27 ) ,
V_30 - sizeof( * V_27 ) ,
L_2 ) ;
if ( ! V_40 ) {
F_21 ( V_42
L_6 ,
( unsigned long long ) V_34 + sizeof( * V_27 ) ,
( unsigned long long ) V_34 + V_30 ) ;
goto V_44;
}
F_23 ( V_27 ) ;
V_27 = F_22 ( V_34 , V_30 ) ;
if ( ! V_27 ) {
F_21 ( V_42 L_4 ) ;
goto V_45;
}
V_38 = (struct V_16 * )
( ( char * ) V_27 + sizeof( struct V_26 ) ) ;
F_24 ( & V_37 ) ;
F_4 ( & V_35 , V_5 ,
F_5 ( V_5 ) ,
V_38 , V_27 -> V_32 ) ;
V_8 = F_25 ( & V_35 , & V_37 ) ;
if ( V_8 )
goto V_46;
V_8 = F_26 ( & V_37 , & V_47 ) ;
if ( V_8 )
goto V_46;
V_8 = F_27 ( & V_37 , L_7 ) ;
if ( V_8 )
goto V_46;
V_8 = F_28 ( & V_35 ) ;
if ( V_8 )
goto V_48;
V_8 = F_8 ( & V_35 , V_49 ) ;
F_29 ( & V_35 ) ;
V_48:
F_30 ( & V_37 ) ;
V_46:
F_31 ( & V_37 ) ;
V_45:
F_32 ( V_34 + sizeof( * V_27 ) ,
V_30 - sizeof( * V_27 ) ) ;
V_44:
F_32 ( V_34 , sizeof( * V_27 ) ) ;
V_43:
if ( V_27 )
F_23 ( V_27 ) ;
return V_8 ;
}
static int F_33 ( T_3 type , T_4 V_50 , T_4 V_51 )
{
struct V_3 V_4 ;
T_4 V_1 , V_34 , V_52 = V_53 ;
int V_8 ;
F_3 ( & V_4 ) ;
V_8 = F_34 ( & V_4 , V_54 ) ;
if ( V_8 )
return V_8 ;
F_35 ( & V_4 , type ) ;
V_8 = F_8 ( & V_4 , V_19 ) ;
if ( V_8 )
return V_8 ;
if ( V_55 ) {
F_1 ( V_50 , & V_55 -> V_50 ) ;
F_1 ( V_51 , & V_55 -> V_51 ) ;
}
V_8 = F_8 ( & V_4 , V_56 ) ;
if ( V_8 )
return V_8 ;
for (; ; ) {
V_8 = F_8 ( & V_4 , V_57 ) ;
if ( V_8 )
return V_8 ;
V_1 = F_9 ( & V_4 ) ;
if ( ! ( V_1 & V_58 ) )
break;
if ( F_13 ( & V_52 ) )
return - V_41 ;
}
V_8 = F_8 ( & V_4 , V_59 ) ;
if ( V_8 )
return V_8 ;
V_1 = F_9 ( & V_4 ) ;
if ( V_1 != V_60 )
return - V_61 ;
V_8 = F_8 ( & V_4 , V_62 ) ;
if ( V_8 )
return V_8 ;
V_34 = F_9 ( & V_4 ) ;
V_8 = F_19 ( V_34 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_34 ( & V_4 , V_63 ) ;
return V_8 ;
}
static int F_36 ( T_3 type , T_4 V_50 , T_4 V_51 )
{
int V_8 ;
F_11 ( & V_10 ) ;
V_8 = F_33 ( type , V_50 , V_51 ) ;
F_12 ( & V_10 ) ;
return V_8 ;
}
static int F_37 ( struct V_64 * V_65 , void * V_66 )
{
int V_8 ;
T_3 V_67 = 0 ;
V_8 = F_10 ( & V_67 ) ;
if ( V_8 )
return V_8 ;
if ( V_67 & 0x0001 )
F_38 ( V_65 , L_8 ) ;
if ( V_67 & 0x0002 )
F_38 ( V_65 , L_9 ) ;
if ( V_67 & 0x0004 )
F_38 ( V_65 , L_10 ) ;
if ( V_67 & 0x0008 )
F_38 ( V_65 , L_11 ) ;
if ( V_67 & 0x0010 )
F_38 ( V_65 , L_12 ) ;
if ( V_67 & 0x0020 )
F_38 ( V_65 , L_13 ) ;
if ( V_67 & 0x0040 )
F_38 ( V_65 , L_14 ) ;
if ( V_67 & 0x0080 )
F_38 ( V_65 , L_15 ) ;
if ( V_67 & 0x0100 )
F_38 ( V_65 , L_16 ) ;
if ( V_67 & 0x0200 )
F_38 ( V_65 , L_17 ) ;
if ( V_67 & 0x0400 )
F_38 ( V_65 , L_18 ) ;
if ( V_67 & 0x0800 )
F_38 ( V_65 , L_19 ) ;
return 0 ;
}
static int F_39 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_40 ( V_69 , F_37 , NULL ) ;
}
static int F_41 ( void * V_70 , T_4 * V_1 )
{
* V_1 = V_71 ;
return 0 ;
}
static int F_42 ( void * V_70 , T_4 V_1 )
{
int V_8 ;
T_3 V_67 = 0 ;
if ( V_1 & ( V_1 - 1 ) )
return - V_29 ;
V_8 = F_10 ( & V_67 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_1 & V_67 ) )
return - V_29 ;
V_71 = V_1 ;
return 0 ;
}
static int F_43 ( void * V_70 , T_4 V_1 )
{
if ( ! V_71 )
return - V_29 ;
return F_36 ( V_71 , V_72 , V_73 ) ;
}
static int F_44 ( struct V_74 * V_6 )
{
if ( ( V_6 -> V_75 !=
( sizeof( struct V_74 ) - sizeof( V_6 -> V_76 ) ) )
&& ( V_6 -> V_75 != sizeof( struct V_74 ) ) )
return - V_29 ;
if ( V_6 -> V_76 . V_77 < sizeof( struct V_74 ) )
return - V_29 ;
if ( V_6 -> V_7 !=
( V_6 -> V_76 . V_77 - sizeof( struct V_74 ) ) /
sizeof( struct V_33 ) )
return - V_29 ;
return 0 ;
}
static int T_5 F_45 ( void )
{
int V_8 ;
T_4 V_78 ;
T_6 V_79 ;
struct V_80 * V_81 ;
struct V_3 V_4 ;
if ( V_82 )
return - V_83 ;
V_79 = F_46 ( V_84 , 0 ,
(struct V_85 * * ) & V_6 ) ;
if ( V_79 == V_86 ) {
F_47 ( V_42 L_20 ) ;
return - V_83 ;
} else if ( F_48 ( V_79 ) ) {
const char * V_87 = F_49 ( V_79 ) ;
F_21 ( V_42 L_21 , V_87 ) ;
return - V_29 ;
}
V_8 = F_44 ( V_6 ) ;
if ( V_8 ) {
F_14 (FW_BUG EINJ_PFX L_22 ) ;
return - V_29 ;
}
V_8 = - V_88 ;
V_89 = F_50 ( L_23 , F_51 () ) ;
if ( ! V_89 )
goto V_90;
V_81 = F_52 ( L_24 , V_91 ,
V_89 , NULL ,
& V_92 ) ;
if ( ! V_81 )
goto V_90;
V_81 = F_52 ( L_25 , V_91 | V_93 ,
V_89 , NULL , & V_94 ) ;
if ( ! V_81 )
goto V_90;
V_81 = F_52 ( L_26 , V_93 ,
V_89 , NULL , & V_95 ) ;
if ( ! V_81 )
goto V_90;
F_24 ( & V_47 ) ;
F_3 ( & V_4 ) ;
V_8 = F_25 ( & V_4 , & V_47 ) ;
if ( V_8 )
goto V_96;
V_8 = F_27 ( & V_47 , L_27 ) ;
if ( V_8 )
goto V_96;
V_8 = F_28 ( & V_4 ) ;
if ( V_8 )
goto V_97;
if ( V_98 ) {
V_78 = F_17 () ;
if ( V_78 ) {
V_55 = F_53 ( V_78 , sizeof( * V_55 ) ) ;
V_8 = - V_88 ;
if ( ! V_55 )
goto V_99;
V_81 = F_54 ( L_28 , V_91 | V_93 ,
V_89 , & V_72 ) ;
if ( ! V_81 )
goto V_99;
V_81 = F_54 ( L_29 , V_91 | V_93 ,
V_89 , & V_73 ) ;
if ( ! V_81 )
goto V_99;
} else
F_55 ( V_42 L_30 ) ;
}
F_47 ( V_42 L_31 ) ;
return 0 ;
V_99:
if ( V_55 )
F_23 ( V_55 ) ;
F_29 ( & V_4 ) ;
V_97:
F_30 ( & V_47 ) ;
V_96:
F_31 ( & V_47 ) ;
V_90:
F_56 ( V_89 ) ;
return V_8 ;
}
static void T_7 F_57 ( void )
{
struct V_3 V_4 ;
if ( V_55 )
F_23 ( V_55 ) ;
F_3 ( & V_4 ) ;
F_29 ( & V_4 ) ;
F_30 ( & V_47 ) ;
F_31 ( & V_47 ) ;
F_56 ( V_89 ) ;
}
