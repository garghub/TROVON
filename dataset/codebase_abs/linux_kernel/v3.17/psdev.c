static unsigned int F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 -> V_5 ;
unsigned int V_6 = V_7 | V_8 ;
F_2 ( V_1 , & V_4 -> V_9 , V_2 ) ;
F_3 ( & V_4 -> V_10 ) ;
if ( ! F_4 ( & V_4 -> V_11 ) )
V_6 |= V_12 | V_13 ;
F_5 ( & V_4 -> V_10 ) ;
return V_6 ;
}
static long F_6 ( struct V_1 * V_14 , unsigned int V_15 , unsigned long V_16 )
{
unsigned int V_17 ;
switch( V_15 ) {
case V_18 :
V_17 = V_19 ;
return F_7 ( V_17 , ( int V_20 * ) V_16 ) ;
default:
return - V_21 ;
}
return 0 ;
}
static T_2 F_8 ( struct V_1 * V_1 , const char V_20 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 -> V_5 ;
struct V_25 * V_26 = NULL ;
struct V_25 * V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 ;
T_2 V_32 = 0 , V_33 = 0 ;
int error ;
if ( F_9 ( & V_31 , V_22 , 2 * sizeof( V_34 ) ) )
return - V_35 ;
if ( F_10 ( V_31 . V_36 ) ) {
union V_37 * V_38 ;
int V_39 = sizeof( * V_38 ) ;
if ( V_23 < sizeof( struct V_40 ) ) {
F_11 ( L_1 ,
V_31 . V_36 , V_31 . V_41 ) ;
V_33 = V_23 ;
goto V_42;
}
if ( V_23 > V_39 ) {
F_11 ( L_2 ,
V_31 . V_36 , V_31 . V_41 ) ;
V_23 = V_39 ;
}
F_12 ( V_38 , union V_37 * , V_23 ) ;
if ( F_9 ( V_38 , V_22 , V_23 ) ) {
F_13 ( V_38 , V_23 ) ;
V_32 = - V_35 ;
goto V_42;
}
error = F_14 ( V_4 , V_31 . V_36 , V_38 ) ;
F_13 ( V_38 , V_23 ) ;
if ( error ) {
F_11 ( L_3 ,
V_43 , error ) ;
V_32 = error ;
goto V_42;
}
V_33 = V_23 ;
goto V_42;
}
F_3 ( & V_4 -> V_10 ) ;
F_15 (lh, &vcp->vc_processing) {
V_27 = F_16 ( V_29 , struct V_25 , V_44 ) ;
if ( V_27 -> V_45 == V_31 . V_41 ) {
V_26 = V_27 ;
F_17 ( & V_26 -> V_44 ) ;
break;
}
}
F_5 ( & V_4 -> V_10 ) ;
if ( ! V_26 ) {
F_11 ( L_4 ,
V_43 , V_31 . V_36 , V_31 . V_41 ) ;
V_32 = - V_46 ;
goto V_42;
}
if ( V_26 -> V_47 < V_23 ) {
F_11 ( L_5 ,
V_43 , V_26 -> V_47 , ( long ) V_23 ,
V_31 . V_36 , V_31 . V_41 ) ;
V_23 = V_26 -> V_47 ;
}
if ( F_9 ( V_26 -> V_48 , V_22 , V_23 ) ) {
V_26 -> V_49 |= V_50 ;
F_18 ( & V_26 -> V_51 ) ;
V_32 = - V_35 ;
goto V_42;
}
V_26 -> V_47 = V_23 ;
V_26 -> V_49 |= V_52 ;
V_33 = V_23 ;
if ( V_26 -> V_53 == V_54 ) {
struct V_55 * V_56 =
(struct V_55 * ) V_26 -> V_48 ;
if ( ! V_56 -> V_57 . V_58 )
V_56 -> V_59 = F_19 ( V_56 -> V_60 ) ;
}
F_18 ( & V_26 -> V_51 ) ;
V_42:
return ( V_33 ? V_33 : V_32 ) ;
}
static T_2 F_20 ( struct V_1 * V_1 , char V_20 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
F_21 ( V_2 , V_61 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_1 -> V_5 ;
struct V_25 * V_26 ;
T_2 V_32 = 0 , V_33 = 0 ;
if ( V_23 == 0 )
return 0 ;
F_3 ( & V_4 -> V_10 ) ;
F_22 ( & V_4 -> V_9 , & V_2 ) ;
F_23 ( V_62 ) ;
while ( F_4 ( & V_4 -> V_11 ) ) {
if ( V_1 -> V_63 & V_64 ) {
V_32 = - V_65 ;
break;
}
if ( F_24 ( V_61 ) ) {
V_32 = - V_66 ;
break;
}
F_5 ( & V_4 -> V_10 ) ;
F_25 () ;
F_3 ( & V_4 -> V_10 ) ;
}
F_23 ( V_67 ) ;
F_26 ( & V_4 -> V_9 , & V_2 ) ;
if ( V_32 )
goto V_42;
V_26 = F_16 ( V_4 -> V_11 . V_68 , struct V_25 , V_44 ) ;
F_17 ( & V_26 -> V_44 ) ;
V_33 = V_26 -> V_69 ;
if ( V_23 < V_26 -> V_69 ) {
F_11 ( L_6 ,
V_43 , ( long ) V_23 , V_26 -> V_69 ) ;
V_33 = V_23 ;
}
if ( F_27 ( V_22 , V_26 -> V_48 , V_33 ) )
V_32 = - V_35 ;
if ( ! ( V_26 -> V_49 & V_70 ) ) {
V_26 -> V_49 |= V_71 ;
F_28 ( & ( V_26 -> V_44 ) , & V_4 -> V_72 ) ;
goto V_42;
}
F_13 ( V_26 -> V_48 , sizeof( struct V_30 ) ) ;
F_29 ( V_26 ) ;
V_42:
F_5 ( & V_4 -> V_10 ) ;
return ( V_33 ? V_33 : V_32 ) ;
}
static int F_30 ( struct V_73 * V_73 , struct V_1 * V_1 )
{
struct V_3 * V_4 ;
int V_74 , V_75 ;
if ( F_31 ( V_61 ) != & V_76 )
return - V_77 ;
if ( F_32 () != & V_78 )
return - V_77 ;
V_74 = F_33 ( V_73 ) ;
if ( V_74 < 0 || V_74 >= V_79 )
return - V_80 ;
V_75 = - V_81 ;
V_4 = & V_82 [ V_74 ] ;
F_3 ( & V_4 -> V_10 ) ;
if ( ! V_4 -> V_83 ) {
V_4 -> V_83 ++ ;
F_34 ( & V_4 -> V_11 ) ;
F_34 ( & V_4 -> V_72 ) ;
F_35 ( & V_4 -> V_9 ) ;
V_4 -> V_84 = NULL ;
V_4 -> V_85 = 0 ;
V_1 -> V_5 = V_4 ;
V_75 = 0 ;
}
F_5 ( & V_4 -> V_10 ) ;
return V_75 ;
}
static int F_36 ( struct V_73 * V_73 , struct V_1 * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 -> V_5 ;
struct V_25 * V_26 , * V_27 ;
if ( ! V_4 || ! V_4 -> V_83 ) {
F_11 ( L_7 , V_43 ) ;
return - 1 ;
}
F_3 ( & V_4 -> V_10 ) ;
F_37 (req, tmp, &vcp->vc_pending, uc_chain) {
F_17 ( & V_26 -> V_44 ) ;
if ( V_26 -> V_49 & V_70 ) {
F_13 ( V_26 -> V_48 , sizeof( struct V_30 ) ) ;
F_29 ( V_26 ) ;
continue;
}
V_26 -> V_49 |= V_50 ;
F_18 ( & V_26 -> V_51 ) ;
}
F_37 (req, tmp, &vcp->vc_processing, uc_chain) {
F_17 ( & V_26 -> V_44 ) ;
V_26 -> V_49 |= V_50 ;
F_18 ( & V_26 -> V_51 ) ;
}
V_1 -> V_5 = NULL ;
V_4 -> V_83 -- ;
F_5 ( & V_4 -> V_10 ) ;
return 0 ;
}
static int F_38 ( void )
{
int V_86 , V_75 = 0 ;
if ( F_39 ( V_87 , L_8 , & V_88 ) ) {
F_40 ( L_9 ,
V_43 , V_87 ) ;
return - V_89 ;
}
V_90 = F_41 ( V_91 , L_8 ) ;
if ( F_42 ( V_90 ) ) {
V_75 = F_43 ( V_90 ) ;
goto V_92;
}
for ( V_86 = 0 ; V_86 < V_79 ; V_86 ++ ) {
F_44 ( & ( & V_82 [ V_86 ] ) -> V_10 ) ;
F_45 ( V_90 , NULL ,
F_46 ( V_87 , V_86 ) , NULL , L_10 , V_86 ) ;
}
F_47 () ;
goto V_42;
V_92:
F_48 ( V_87 , L_8 ) ;
V_42:
return V_75 ;
}
static int T_5 F_49 ( void )
{
int V_93 ;
int V_86 ;
V_93 = F_50 () ;
if ( V_93 )
goto V_94;
V_93 = F_38 () ;
if ( V_93 ) {
F_11 ( L_11 , V_93 ) ;
goto V_95;
}
V_93 = F_51 ( & V_96 ) ;
if ( V_93 ) {
F_11 ( L_12 ) ;
goto V_42;
}
return 0 ;
V_42:
for ( V_86 = 0 ; V_86 < V_79 ; V_86 ++ )
F_52 ( V_90 , F_46 ( V_87 , V_86 ) ) ;
F_53 ( V_90 ) ;
F_48 ( V_87 , L_8 ) ;
F_54 () ;
V_95:
F_55 () ;
V_94:
return V_93 ;
}
static void T_6 F_56 ( void )
{
int V_75 , V_86 ;
V_75 = F_57 ( & V_96 ) ;
if ( V_75 != 0 )
F_11 ( L_13 ) ;
for ( V_86 = 0 ; V_86 < V_79 ; V_86 ++ )
F_52 ( V_90 , F_46 ( V_87 , V_86 ) ) ;
F_53 ( V_90 ) ;
F_48 ( V_87 , L_8 ) ;
F_54 () ;
F_55 () ;
}
