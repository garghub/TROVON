static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 () ;
if ( ! V_5 )
return - V_6 ;
V_3 -> V_7 = V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_7 ;
return F_4 ( V_5 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_4 * V_5 = V_3 -> V_7 ;
return F_6 ( V_9 , V_5 ) ;
}
static unsigned int F_7 ( struct V_2 * V_3 , T_1 * V_10 )
{
struct V_4 * V_5 = V_3 -> V_7 ;
return F_8 ( V_3 , V_10 , V_5 ) ;
}
static int F_9 ( struct V_2 * V_3 , T_2 V_11 )
{
struct V_4 * V_12 = V_3 -> V_7 ;
F_10 ( & V_12 -> V_13 ) ;
if ( V_12 -> V_14 == V_11 )
F_11 ( V_12 ) ;
F_12 ( & V_12 -> V_13 ) ;
return 0 ;
}
static T_3 void F_13 ( int V_15 , const char * V_16 )
{
if ( V_15 < 0 && V_15 != - V_17 )
F_14 ( V_18 . V_19 . V_20 , L_1 , V_16 , V_15 ) ;
}
static long F_15 ( struct V_2 * V_3 , unsigned int V_21 , unsigned long V_22 )
{
struct V_4 * V_5 = V_3 -> V_7 ;
void T_4 * V_23 = ( void T_4 * ) V_22 ;
int V_15 = 0 ;
struct V_24 V_25 ;
bool V_26 = false ;
V_26 = ! ! ( V_3 -> V_27 & V_28 ) ;
switch ( V_21 ) {
case V_29 :
{
int V_30 ;
if ( F_16 ( & V_30 , V_23 , sizeof( V_30 ) ) )
return - V_31 ;
V_30 = F_17 ( V_5 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( F_18 ( V_23 , & V_30 , sizeof( V_30 ) ) )
return - V_31 ;
return 0 ;
}
case V_32 :
return F_19 ( V_5 , V_22 ) ;
case V_33 :
{
struct V_34 V_35 ;
struct V_4 * V_12 = (struct V_4 * ) V_5 ;
if ( F_16 ( & V_35 , V_23 , sizeof( V_35 ) ) )
return - V_31 ;
V_15 = F_20 ( V_5 , & V_35 . V_36 , V_26 ) ;
if ( V_15 < 0 )
return V_15 ;
V_35 . V_37 . V_38 = V_12 -> V_39 . V_38 ;
V_35 . V_37 . V_39 = V_12 -> V_39 . V_39 ;
if ( F_18 ( V_23 , & V_35 , sizeof( V_35 ) ) )
return - V_31 ;
return 0 ;
}
case V_40 :
{
struct V_41 V_25 ;
T_5 * V_12 = ( T_5 * ) & V_25 . V_42 ;
if ( F_16 ( & V_25 , V_23 , sizeof( V_25 ) ) )
return - V_31 ;
V_15 = F_21 ( V_5 , & V_25 . V_36 , V_12 , V_25 . V_43 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_18 ( V_23 , & V_25 , sizeof( V_25 ) ) ) {
F_4 ( * V_12 ) ;
return - V_31 ;
}
F_22 ( & V_18 . V_44 ) ;
F_23 ( & ( ( * V_12 ) -> V_45 ) , & V_18 . V_46 ) ;
F_23 ( & ( ( * V_12 ) -> V_47 ) , & V_5 -> V_48 ) ;
( * V_12 ) -> V_49 = V_5 ;
V_5 -> V_50 ++ ;
F_24 ( & V_18 . V_44 ) ;
return 0 ;
}
case V_51 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_4 * V_52 ;
struct V_4 * V_53 ;
struct V_4 * V_54 = NULL ;
struct V_4 * V_55 ;
struct V_56 * V_57 , * V_58 ;
if ( F_16 ( & V_52 , V_23 , sizeof( void * ) ) )
return - V_31 ;
F_22 ( & V_18 . V_44 ) ;
F_25 (pos, tmpq, &scif_info.uaccept) {
V_55 = F_26 ( V_57 ,
struct V_4 , V_45 ) ;
if ( V_55 == V_52 ) {
F_27 ( V_57 ) ;
V_54 = V_55 ;
break;
}
}
if ( ! V_54 ) {
F_24 ( & V_18 . V_44 ) ;
return - V_59 ;
}
V_53 = V_52 -> V_49 ;
F_25 (pos, tmpq, &lisep->li_accept) {
V_55 = F_26 ( V_57 ,
struct V_4 , V_47 ) ;
if ( V_55 == V_52 ) {
F_27 ( V_57 ) ;
V_53 -> V_50 -- ;
break;
}
}
F_24 ( & V_18 . V_44 ) ;
F_28 ( V_5 ) ;
F_29 ( V_5 ) ;
F_30 ( V_5 , ! V_60 ) ;
V_3 -> V_7 = V_52 ;
return 0 ;
}
case V_61 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
if ( F_16 ( & V_25 , V_23 ,
sizeof( struct V_24 ) ) ) {
V_15 = - V_31 ;
goto V_62;
}
V_15 = F_31 ( V_5 , ( void T_4 * ) V_25 . V_63 ,
V_25 . V_64 , V_25 . V_43 ) ;
if ( V_15 < 0 )
goto V_62;
if ( F_18 ( &
( (struct V_24 T_4 * ) V_23 ) -> V_65 ,
& V_15 , sizeof( V_15 ) ) ) {
V_15 = - V_31 ;
goto V_62;
}
V_15 = 0 ;
V_62:
F_13 ( V_15 , L_2 ) ;
return V_15 ;
}
case V_66 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
if ( F_16 ( & V_25 , V_23 ,
sizeof( struct V_24 ) ) ) {
V_15 = - V_31 ;
goto V_67;
}
V_15 = F_32 ( V_5 , ( void T_4 * ) V_25 . V_63 ,
V_25 . V_64 , V_25 . V_43 ) ;
if ( V_15 < 0 )
goto V_67;
if ( F_18 ( &
( (struct V_24 T_4 * ) V_23 ) -> V_65 ,
& V_15 , sizeof( V_15 ) ) ) {
V_15 = - V_31 ;
goto V_67;
}
V_15 = 0 ;
V_67:
F_13 ( V_15 , L_3 ) ;
return V_15 ;
}
case V_68 :
{
struct V_69 V_70 ;
int V_71 ;
T_6 * V_72 ;
void T_4 * V_73 , * V_74 ;
T_6 V_37 ;
if ( F_16 ( & V_70 , V_23 , sizeof( V_70 ) ) ) {
V_15 = - V_31 ;
goto V_75;
}
V_71 = F_33 ( int , V_18 . V_76 , V_70 . V_64 ) ;
V_72 = F_34 ( V_71 , sizeof( T_6 ) , V_77 ) ;
if ( V_71 && ! V_72 ) {
V_15 = - V_6 ;
goto V_75;
}
V_70 . V_64 = F_35 ( V_72 , V_71 , & V_37 ) ;
V_73 = ( void T_4 * ) V_70 . V_72 ;
if ( F_18 ( V_73 , V_72 , sizeof( T_6 ) * V_71 ) ) {
V_15 = - V_31 ;
goto V_78;
}
V_74 = ( void T_4 * ) V_70 . V_37 ;
if ( F_18 ( V_74 , & V_37 , sizeof( T_6 ) ) ) {
V_15 = - V_31 ;
goto V_78;
}
if ( F_18 ( V_23 , & V_70 , sizeof( V_70 ) ) ) {
V_15 = - V_31 ;
goto V_78;
}
V_78:
F_36 ( V_72 ) ;
V_75:
return V_15 ;
}
case V_79 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_80 V_81 ;
T_7 V_82 ;
if ( F_16 ( & V_81 , V_23 , sizeof( V_81 ) ) ) {
V_15 = - V_31 ;
goto V_83;
}
if ( V_81 . V_43 & V_84 ) {
V_15 = - V_85 ;
goto V_83;
}
V_82 = F_37 ( V_5 , ( void * ) V_81 . V_86 , V_81 . V_64 ,
V_81 . V_87 , V_81 . V_88 , V_81 . V_43 ) ;
if ( V_82 < 0 ) {
V_15 = ( int ) V_82 ;
goto V_83;
}
if ( F_18 ( & ( (struct V_80 T_4 * ) V_23 )
-> V_89 , & V_82 , sizeof( V_81 . V_89 ) ) ) {
V_15 = - V_31 ;
goto V_83;
}
V_15 = 0 ;
V_83:
F_13 ( V_15 , L_4 ) ;
return V_15 ;
}
case V_90 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_91 V_92 ;
if ( F_16 ( & V_92 , V_23 , sizeof( V_92 ) ) ) {
V_15 = - V_31 ;
goto V_93;
}
V_15 = F_38 ( V_5 , V_92 . V_87 , V_92 . V_64 ) ;
V_93:
F_13 ( V_15 , L_5 ) ;
return V_15 ;
}
case V_94 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_95 V_96 ;
if ( F_16 ( & V_96 , V_23 , sizeof( V_96 ) ) ) {
V_15 = - V_31 ;
goto V_97;
}
V_15 = F_39 ( V_5 , V_96 . V_98 , V_96 . V_64 , V_96 . V_99 ,
V_96 . V_43 ) ;
V_97:
F_13 ( V_15 , L_6 ) ;
return V_15 ;
}
case V_100 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_95 V_96 ;
if ( F_16 ( & V_96 , V_23 , sizeof( V_96 ) ) ) {
V_15 = - V_31 ;
goto V_101;
}
V_15 = F_40 ( V_5 , V_96 . V_98 , V_96 . V_64 , V_96 . V_99 ,
V_96 . V_43 ) ;
V_101:
F_13 ( V_15 , L_7 ) ;
return V_15 ;
}
case V_102 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_95 V_96 ;
if ( F_16 ( & V_96 , V_23 , sizeof( V_96 ) ) ) {
V_15 = - V_31 ;
goto V_103;
}
V_15 = F_41 ( V_5 , ( void V_104 * ) V_96 . V_86 , V_96 . V_64 ,
V_96 . V_99 , V_96 . V_43 ) ;
V_103:
F_13 ( V_15 , L_8 ) ;
return V_15 ;
}
case V_105 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_95 V_96 ;
if ( F_16 ( & V_96 , V_23 , sizeof( V_96 ) ) ) {
V_15 = - V_31 ;
goto V_106;
}
V_15 = F_42 ( V_5 , ( void V_104 * ) V_96 . V_86 , V_96 . V_64 ,
V_96 . V_99 , V_96 . V_43 ) ;
V_106:
F_13 ( V_15 , L_9 ) ;
return V_15 ;
}
case V_107 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_108 V_109 ;
int V_110 = 0 ;
if ( F_16 ( & V_109 , V_23 , sizeof( V_109 ) ) ) {
V_15 = - V_31 ;
goto V_111;
}
V_15 = F_43 ( V_5 , V_109 . V_43 , & V_110 ) ;
if ( V_15 )
goto V_111;
if ( F_18 ( ( void T_4 * ) V_109 . V_109 , & V_110 ,
sizeof( V_110 ) ) ) {
V_15 = - V_31 ;
goto V_111;
}
V_111:
F_13 ( V_15 , L_10 ) ;
return V_15 ;
}
case V_112 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
V_15 = F_44 ( V_5 , V_22 ) ;
F_13 ( V_15 , L_11 ) ;
return V_15 ;
}
case V_113 :
{
struct V_4 * V_5 = V_3 -> V_7 ;
struct V_114 signal ;
if ( F_16 ( & signal , V_23 , sizeof( signal ) ) ) {
V_15 = - V_31 ;
goto V_115;
}
V_15 = F_45 ( V_5 , signal . V_116 , signal . V_117 ,
signal . V_118 , signal . V_119 , signal . V_43 ) ;
V_115:
F_13 ( V_15 , L_12 ) ;
return V_15 ;
}
}
return - V_85 ;
}
