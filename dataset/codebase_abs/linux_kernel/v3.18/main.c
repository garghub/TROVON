static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_1 -> V_8 , struct V_3 , V_9 ) ;
if ( ! V_4 )
return - V_10 ;
F_3 ( & V_4 -> V_11 ) ;
V_6 = NULL ;
V_7 = - V_10 ;
if ( V_4 -> V_12 != V_13 ) {
F_4 ( V_4 -> V_4 , L_1 ,
F_5 ( V_4 -> V_12 ) ) ;
goto V_14;
}
V_7 = - V_15 ;
V_6 = F_6 ( V_4 ) ;
if ( ! V_6 )
goto V_14;
V_7 = F_7 ( V_6 , V_16 ) ;
if ( V_7 )
goto V_14;
V_2 -> V_17 = V_6 ;
F_8 ( & V_4 -> V_11 ) ;
return F_9 ( V_1 , V_2 ) ;
V_14:
F_8 ( & V_4 -> V_11 ) ;
F_10 ( V_6 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_21 ) {
V_20 = F_13 ( V_4 , V_2 ) ;
goto V_22;
}
if ( V_6 -> V_23 == V_24 ) {
V_6 -> V_23 = V_25 ;
F_14 ( V_4 , V_6 , L_2 ) ;
V_20 = F_15 ( V_6 ) ;
}
F_16 ( V_6 ) ;
F_14 ( V_4 , V_6 , L_3 ) ;
F_17 ( V_6 ) ;
V_19 = NULL ;
if ( V_6 -> V_26 ) {
V_19 = F_18 ( V_6 ) ;
if ( V_19 )
F_19 ( & V_19 -> V_27 ) ;
V_19 = V_6 -> V_26 ;
V_6 -> V_26 = NULL ;
}
V_2 -> V_17 = NULL ;
F_20 ( V_19 ) ;
F_10 ( V_6 ) ;
V_22:
F_8 ( & V_4 -> V_11 ) ;
return V_20 ;
}
static T_1 F_21 ( struct V_2 * V_2 , char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
struct V_18 * V_31 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_3 * V_4 ;
int V_20 ;
int V_7 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_20 = - V_10 ;
goto V_22;
}
if ( V_29 == 0 ) {
V_20 = 0 ;
goto V_22;
}
if ( V_6 == & V_4 -> V_21 ) {
V_20 = F_22 ( V_4 , V_2 , V_28 , V_29 , V_30 ) ;
goto V_22;
}
if ( V_6 -> V_26 ) {
V_19 = V_6 -> V_26 ;
if ( V_19 -> V_32 > * V_30 )
goto V_33;
if ( V_19 -> V_32 > 0 && V_19 -> V_32 <= * V_30 ) {
V_20 = 0 ;
goto free;
}
if ( V_19 -> V_32 == 0 && * V_30 > 0 )
* V_30 = 0 ;
} else if ( * V_30 > 0 ) {
* V_30 = 0 ;
}
V_7 = F_23 ( V_6 , V_29 ) ;
if ( V_7 && V_7 != - V_34 ) {
F_4 ( V_4 -> V_4 ,
L_4 , V_7 ) ;
V_20 = V_7 ;
goto V_22;
}
if ( V_35 != V_6 -> V_36 &&
! F_24 ( & V_6 -> V_37 ) ) {
if ( V_2 -> V_38 & V_39 ) {
V_20 = - V_40 ;
goto V_22;
}
F_8 ( & V_4 -> V_11 ) ;
if ( F_25 ( V_6 -> V_37 ,
V_35 == V_6 -> V_36 ||
F_26 ( V_6 ) ) ) {
if ( F_27 ( V_41 ) )
return - V_42 ;
return - V_43 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( F_26 ( V_6 ) ) {
V_20 = - V_34 ;
goto V_22;
}
}
V_19 = V_6 -> V_26 ;
if ( ! V_19 ) {
V_20 = - V_10 ;
goto V_22;
}
if ( V_6 -> V_36 != V_35 ) {
V_20 = 0 ;
goto V_22;
}
V_33:
F_4 ( V_4 -> V_4 , L_5 ,
V_19 -> V_44 . V_45 , V_19 -> V_32 ) ;
if ( V_29 == 0 || V_28 == NULL || * V_30 > V_19 -> V_32 ) {
V_20 = - V_46 ;
goto free;
}
V_29 = F_28 ( T_3 , V_29 , V_19 -> V_32 - * V_30 ) ;
if ( F_29 ( V_28 , V_19 -> V_44 . V_47 + * V_30 , V_29 ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_20 = - V_48 ;
goto free;
}
V_20 = V_29 ;
* V_30 += V_29 ;
if ( ( unsigned long ) * V_30 < V_19 -> V_32 )
goto V_22;
free:
V_31 = F_18 ( V_6 ) ;
if ( V_31 )
F_19 ( & V_31 -> V_27 ) ;
F_20 ( V_19 ) ;
V_6 -> V_36 = V_49 ;
V_6 -> V_26 = NULL ;
V_22:
F_4 ( V_4 -> V_4 , L_7 , V_20 ) ;
F_8 ( & V_4 -> V_11 ) ;
return V_20 ;
}
static T_1 F_30 ( struct V_2 * V_2 , const char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
struct V_50 * V_51 ;
struct V_18 * V_52 = NULL ;
struct V_3 * V_4 ;
unsigned long V_53 = 0 ;
int V_20 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_20 = - V_10 ;
goto V_22;
}
V_51 = F_31 ( V_4 , & V_6 -> V_54 , V_6 -> V_55 ) ;
if ( ! V_51 ) {
V_20 = - V_56 ;
goto V_22;
}
if ( V_29 == 0 ) {
V_20 = 0 ;
goto V_22;
}
if ( V_29 > V_51 -> V_57 . V_58 ) {
V_20 = - V_59 ;
goto V_22;
}
if ( V_6 -> V_23 != V_24 ) {
F_32 ( V_4 -> V_4 , L_8 ,
V_6 -> V_60 , V_6 -> V_55 ) ;
V_20 = - V_10 ;
goto V_22;
}
if ( V_6 == & V_4 -> V_21 ) {
V_52 = F_33 ( V_4 , V_2 ) ;
if ( V_52 ) {
V_53 = V_52 -> V_61 +
F_34 ( V_62 ) ;
if ( F_35 ( V_63 , V_53 ) ||
V_6 -> V_36 == V_35 ) {
* V_30 = 0 ;
F_19 ( & V_52 -> V_27 ) ;
F_20 ( V_52 ) ;
V_52 = NULL ;
}
}
}
if ( V_6 -> V_36 == V_35 ) {
* V_30 = 0 ;
V_52 = F_18 ( V_6 ) ;
if ( V_52 ) {
F_19 ( & V_52 -> V_27 ) ;
F_20 ( V_52 ) ;
V_52 = NULL ;
V_6 -> V_36 = V_49 ;
V_6 -> V_26 = NULL ;
}
} else if ( V_6 -> V_36 == V_49 )
* V_30 = 0 ;
V_52 = F_36 ( V_6 , V_2 ) ;
if ( ! V_52 ) {
V_20 = - V_15 ;
goto V_22;
}
V_20 = F_37 ( V_52 , V_29 ) ;
if ( V_20 )
goto V_22;
V_20 = F_38 ( V_52 -> V_64 . V_47 , V_28 , V_29 ) ;
if ( V_20 ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_20 = - V_48 ;
goto V_22;
}
if ( V_6 == & V_4 -> V_21 ) {
V_20 = F_39 ( V_4 , V_52 ) ;
if ( V_20 ) {
F_32 ( V_4 -> V_4 ,
L_10 , V_20 ) ;
goto V_22;
}
F_8 ( & V_4 -> V_11 ) ;
return V_29 ;
}
V_20 = F_40 ( V_6 , V_52 , false ) ;
V_22:
F_8 ( & V_4 -> V_11 ) ;
if ( V_20 < 0 )
F_20 ( V_52 ) ;
return V_20 ;
}
static int F_41 ( struct V_2 * V_2 ,
struct V_65 * V_47 )
{
struct V_3 * V_4 ;
struct V_66 * V_67 ;
struct V_50 * V_51 ;
struct V_5 * V_6 ;
int V_20 ;
V_6 = V_2 -> V_17 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 ) {
V_20 = - V_10 ;
goto V_68;
}
if ( V_6 -> V_23 != V_69 &&
V_6 -> V_23 != V_70 ) {
V_20 = - V_34 ;
goto V_68;
}
V_51 = F_42 ( V_4 , & V_47 -> V_71 ) ;
if ( ! V_51 || V_51 -> V_57 . V_72 ) {
F_4 ( V_4 -> V_4 , L_11 ,
& V_47 -> V_71 ) ;
V_20 = - V_56 ;
goto V_68;
}
V_6 -> V_55 = V_51 -> V_73 ;
V_6 -> V_54 = V_51 -> V_57 . V_74 ;
F_4 ( V_4 -> V_4 , L_12 ,
V_6 -> V_55 ) ;
F_4 ( V_4 -> V_4 , L_13 ,
V_51 -> V_57 . V_75 ) ;
F_4 ( V_4 -> V_4 , L_14 ,
V_51 -> V_57 . V_58 ) ;
if ( F_43 ( V_47 -> V_71 , V_76 ) == 0 ) {
F_4 ( V_4 -> V_4 , L_15 ) ;
if ( V_4 -> V_21 . V_23 != V_24 ) {
V_20 = - V_10 ;
goto V_68;
}
F_17 ( V_6 ) ;
F_10 ( V_6 ) ;
V_6 = NULL ;
V_4 -> V_77 ++ ;
V_2 -> V_17 = & V_4 -> V_21 ;
V_67 = & V_47 -> V_78 ;
V_67 -> V_58 = V_51 -> V_57 . V_58 ;
V_67 -> V_75 = V_51 -> V_57 . V_75 ;
V_20 = V_4 -> V_21 . V_79 ;
goto V_68;
}
V_67 = & V_47 -> V_78 ;
V_67 -> V_58 = V_51 -> V_57 . V_58 ;
V_67 -> V_75 = V_51 -> V_57 . V_75 ;
F_4 ( V_4 -> V_4 , L_16 ) ;
V_20 = F_44 ( V_6 , V_2 ) ;
V_68:
return V_20 ;
}
static long F_45 ( struct V_2 * V_2 , unsigned int V_80 , unsigned long V_47 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_17 ;
struct V_65 V_81 ;
int V_20 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_4 ( V_4 -> V_4 , L_17 , V_80 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_20 = - V_10 ;
goto V_22;
}
switch ( V_80 ) {
case V_82 :
F_4 ( V_4 -> V_4 , L_18 ) ;
if ( F_38 ( & V_81 , ( char T_2 * ) V_47 ,
sizeof( struct V_65 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_20 = - V_48 ;
goto V_22;
}
V_20 = F_41 ( V_2 , & V_81 ) ;
if ( V_20 )
goto V_22;
if ( F_29 ( ( char T_2 * ) V_47 , & V_81 ,
sizeof( struct V_65 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_20 = - V_48 ;
goto V_22;
}
break;
default:
F_32 ( V_4 -> V_4 , L_19 , V_80 ) ;
V_20 = - V_83 ;
}
V_22:
F_8 ( & V_4 -> V_11 ) ;
return V_20 ;
}
static long F_46 ( struct V_2 * V_2 ,
unsigned int V_80 , unsigned long V_47 )
{
return F_45 ( V_2 , V_80 , ( unsigned long ) F_47 ( V_47 ) ) ;
}
static unsigned int F_48 ( struct V_2 * V_2 , T_5 * V_84 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
struct V_3 * V_4 ;
unsigned int V_85 = 0 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return V_86 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_49 ( V_6 ) ) {
V_85 = V_86 ;
goto V_22;
}
F_8 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_21 )
return F_50 ( V_4 , V_2 , V_84 ) ;
F_51 ( V_2 , & V_6 -> V_87 , V_84 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_49 ( V_6 ) ) {
V_85 = V_86 ;
goto V_22;
}
V_85 |= ( V_88 | V_89 ) ;
V_22:
F_8 ( & V_4 -> V_11 ) ;
return V_85 ;
}
static int F_52 ( struct V_3 * V_4 )
{
int V_90 ;
F_3 ( & V_91 ) ;
V_90 = F_53 ( & V_92 , V_4 , 0 , V_93 , V_94 ) ;
if ( V_90 >= 0 )
V_4 -> V_95 = V_90 ;
else if ( V_90 == - V_96 )
F_32 ( V_4 -> V_4 , L_20 ) ;
F_8 ( & V_91 ) ;
return V_90 ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_3 ( & V_91 ) ;
F_55 ( & V_92 , V_4 -> V_95 ) ;
F_8 ( & V_91 ) ;
}
int F_56 ( struct V_3 * V_4 , struct V_97 * V_98 )
{
struct V_97 * V_99 ;
int V_90 , V_100 ;
V_90 = F_52 ( V_4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_100 = F_57 ( F_58 ( V_101 ) , V_4 -> V_95 ) ;
F_59 ( & V_4 -> V_9 , & V_102 ) ;
V_4 -> V_9 . V_103 = V_102 . V_103 ;
V_90 = F_60 ( & V_4 -> V_9 , V_100 , 1 ) ;
if ( V_90 ) {
F_32 ( V_98 , L_21 ,
F_58 ( V_101 ) , V_4 -> V_95 ) ;
goto V_104;
}
V_99 = F_61 ( V_105 , V_98 , V_100 ,
NULL , L_22 , V_4 -> V_95 ) ;
if ( F_62 ( V_99 ) ) {
F_32 ( V_98 , L_23 ,
F_58 ( V_101 ) , V_4 -> V_95 ) ;
V_90 = F_63 ( V_99 ) ;
goto V_106;
}
V_90 = F_64 ( V_4 , F_65 ( V_99 ) ) ;
if ( V_90 ) {
F_32 ( V_99 , L_24 , V_90 ) ;
goto V_107;
}
return 0 ;
V_107:
F_66 ( V_105 , V_100 ) ;
V_106:
F_67 ( & V_4 -> V_9 ) ;
V_104:
F_54 ( V_4 ) ;
return V_90 ;
}
void F_68 ( struct V_3 * V_4 )
{
int V_100 ;
V_100 = V_4 -> V_9 . V_4 ;
F_67 ( & V_4 -> V_9 ) ;
F_69 ( V_4 ) ;
F_66 ( V_105 , V_100 ) ;
F_54 ( V_4 ) ;
}
static int T_6 F_70 ( void )
{
int V_90 ;
V_105 = F_71 ( V_108 , L_25 ) ;
if ( F_62 ( V_105 ) ) {
F_72 ( L_26 ) ;
V_90 = F_63 ( V_105 ) ;
goto V_7;
}
V_90 = F_73 ( & V_101 , 0 , V_93 , L_25 ) ;
if ( V_90 < 0 ) {
F_72 ( L_27 ) ;
goto V_109;
}
V_90 = F_74 () ;
if ( V_90 < 0 ) {
F_72 ( L_28 ) ;
goto V_110;
}
return 0 ;
V_110:
F_75 ( V_101 , V_93 ) ;
V_109:
F_76 ( V_105 ) ;
V_7:
return V_90 ;
}
static void T_7 F_77 ( void )
{
F_75 ( V_101 , V_93 ) ;
F_76 ( V_105 ) ;
F_78 () ;
}
