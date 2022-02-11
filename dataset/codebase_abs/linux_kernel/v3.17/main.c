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
F_4 ( & V_4 -> V_14 -> V_4 , L_1 ,
F_5 ( V_4 -> V_12 ) ) ;
goto V_15;
}
V_7 = - V_16 ;
V_6 = F_6 ( V_4 ) ;
if ( ! V_6 )
goto V_15;
V_7 = F_7 ( V_6 , V_17 ) ;
if ( V_7 )
goto V_15;
V_2 -> V_18 = V_6 ;
F_8 ( & V_4 -> V_11 ) ;
return F_9 ( V_1 , V_2 ) ;
V_15:
F_8 ( & V_4 -> V_11 ) ;
F_10 ( V_6 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_18 ;
struct V_19 * V_20 ;
struct V_3 * V_4 ;
int V_21 = 0 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_22 ) {
V_21 = F_13 ( V_4 , V_2 ) ;
goto V_23;
}
if ( V_6 -> V_24 == V_25 ) {
V_6 -> V_24 = V_26 ;
F_14 ( V_4 , V_6 , L_2 ) ;
V_21 = F_15 ( V_6 ) ;
}
F_16 ( V_6 ) ;
F_14 ( V_4 , V_6 , L_3 ) ;
F_17 ( V_6 ) ;
V_20 = NULL ;
if ( V_6 -> V_27 ) {
V_20 = F_18 ( V_6 ) ;
if ( V_20 )
F_19 ( & V_20 -> V_28 ) ;
V_20 = V_6 -> V_27 ;
V_6 -> V_27 = NULL ;
}
V_2 -> V_18 = NULL ;
F_20 ( V_20 ) ;
F_10 ( V_6 ) ;
V_23:
F_8 ( & V_4 -> V_11 ) ;
return V_21 ;
}
static T_1 F_21 ( struct V_2 * V_2 , char T_2 * V_29 ,
T_3 V_30 , T_4 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_18 ;
struct V_19 * V_32 = NULL ;
struct V_19 * V_20 = NULL ;
struct V_3 * V_4 ;
int V_21 ;
int V_7 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_21 = - V_10 ;
goto V_23;
}
if ( V_30 == 0 ) {
V_21 = 0 ;
goto V_23;
}
if ( V_6 == & V_4 -> V_22 ) {
V_21 = F_22 ( V_4 , V_2 , V_29 , V_30 , V_31 ) ;
goto V_23;
}
if ( V_6 -> V_27 ) {
V_20 = V_6 -> V_27 ;
if ( V_20 -> V_33 > * V_31 )
goto V_34;
if ( V_20 -> V_33 > 0 && V_20 -> V_33 <= * V_31 ) {
V_21 = 0 ;
goto free;
}
if ( V_20 -> V_33 == 0 && * V_31 > 0 )
* V_31 = 0 ;
} else if ( * V_31 > 0 ) {
* V_31 = 0 ;
}
V_7 = F_23 ( V_6 , V_30 ) ;
if ( V_7 && V_7 != - V_35 ) {
F_4 ( & V_4 -> V_14 -> V_4 ,
L_4 , V_7 ) ;
V_21 = V_7 ;
goto V_23;
}
if ( V_36 != V_6 -> V_37 &&
! F_24 ( & V_6 -> V_38 ) ) {
if ( V_2 -> V_39 & V_40 ) {
V_21 = - V_41 ;
goto V_23;
}
F_8 ( & V_4 -> V_11 ) ;
if ( F_25 ( V_6 -> V_38 ,
V_36 == V_6 -> V_37 ||
F_26 ( V_6 ) ) ) {
if ( F_27 ( V_42 ) )
return - V_43 ;
return - V_44 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( F_26 ( V_6 ) ) {
V_21 = - V_35 ;
goto V_23;
}
}
V_20 = V_6 -> V_27 ;
if ( ! V_20 ) {
V_21 = - V_10 ;
goto V_23;
}
if ( V_6 -> V_37 != V_36 ) {
V_21 = 0 ;
goto V_23;
}
V_34:
F_4 ( & V_4 -> V_14 -> V_4 , L_5 ,
V_20 -> V_45 . V_46 , V_20 -> V_33 ) ;
if ( V_30 == 0 || V_29 == NULL || * V_31 > V_20 -> V_33 ) {
V_21 = - V_47 ;
goto free;
}
V_30 = F_28 ( T_3 , V_30 , V_20 -> V_33 - * V_31 ) ;
if ( F_29 ( V_29 , V_20 -> V_45 . V_48 + * V_31 , V_30 ) ) {
F_4 ( & V_4 -> V_14 -> V_4 , L_6 ) ;
V_21 = - V_49 ;
goto free;
}
V_21 = V_30 ;
* V_31 += V_30 ;
if ( ( unsigned long ) * V_31 < V_20 -> V_33 )
goto V_23;
free:
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
F_19 ( & V_32 -> V_28 ) ;
F_20 ( V_20 ) ;
V_6 -> V_37 = V_50 ;
V_6 -> V_27 = NULL ;
V_23:
F_4 ( & V_4 -> V_14 -> V_4 , L_7 , V_21 ) ;
F_8 ( & V_4 -> V_11 ) ;
return V_21 ;
}
static T_1 F_30 ( struct V_2 * V_2 , const char T_2 * V_29 ,
T_3 V_30 , T_4 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_18 ;
struct V_19 * V_51 = NULL ;
struct V_3 * V_4 ;
unsigned long V_52 = 0 ;
int V_21 ;
int V_53 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_21 = - V_10 ;
goto V_23;
}
V_53 = F_31 ( V_4 , V_6 -> V_54 ) ;
if ( V_53 < 0 ) {
V_21 = - V_55 ;
goto V_23;
}
if ( V_30 == 0 ) {
V_21 = 0 ;
goto V_23;
}
if ( V_30 > V_4 -> V_56 [ V_53 ] . V_57 . V_58 ) {
V_21 = - V_59 ;
goto V_23;
}
if ( V_6 -> V_24 != V_25 ) {
F_32 ( & V_4 -> V_14 -> V_4 , L_8 ,
V_6 -> V_60 , V_6 -> V_54 ) ;
V_21 = - V_10 ;
goto V_23;
}
if ( V_6 == & V_4 -> V_22 ) {
V_51 = F_33 ( V_4 , V_2 ) ;
if ( V_51 ) {
V_52 = V_51 -> V_61 +
F_34 ( V_62 ) ;
if ( F_35 ( V_63 , V_52 ) ||
V_6 -> V_37 == V_36 ) {
* V_31 = 0 ;
F_19 ( & V_51 -> V_28 ) ;
F_20 ( V_51 ) ;
V_51 = NULL ;
}
}
}
if ( V_6 -> V_37 == V_36 ) {
* V_31 = 0 ;
V_51 = F_18 ( V_6 ) ;
if ( V_51 ) {
F_19 ( & V_51 -> V_28 ) ;
F_20 ( V_51 ) ;
V_51 = NULL ;
V_6 -> V_37 = V_50 ;
V_6 -> V_27 = NULL ;
}
} else if ( V_6 -> V_37 == V_50 )
* V_31 = 0 ;
V_51 = F_36 ( V_6 , V_2 ) ;
if ( ! V_51 ) {
F_32 ( & V_4 -> V_14 -> V_4 , L_9 ) ;
V_21 = - V_16 ;
goto V_23;
}
V_21 = F_37 ( V_51 , V_30 ) ;
if ( V_21 )
goto V_23;
V_21 = F_38 ( V_51 -> V_64 . V_48 , V_29 , V_30 ) ;
if ( V_21 ) {
F_4 ( & V_4 -> V_14 -> V_4 , L_10 ) ;
V_21 = - V_49 ;
goto V_23;
}
if ( V_6 == & V_4 -> V_22 ) {
V_21 = F_39 ( V_4 , V_51 ) ;
if ( V_21 ) {
F_32 ( & V_4 -> V_14 -> V_4 ,
L_11 , V_21 ) ;
goto V_23;
}
F_8 ( & V_4 -> V_11 ) ;
return V_30 ;
}
V_21 = F_40 ( V_6 , V_51 , false ) ;
V_23:
F_8 ( & V_4 -> V_11 ) ;
if ( V_21 < 0 )
F_20 ( V_51 ) ;
return V_21 ;
}
static int F_41 ( struct V_2 * V_2 ,
struct V_65 * V_48 )
{
struct V_3 * V_4 ;
struct V_66 * V_67 ;
struct V_5 * V_6 ;
int V_68 ;
int V_21 ;
V_6 = V_2 -> V_18 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 ) {
V_21 = - V_10 ;
goto V_69;
}
if ( V_6 -> V_24 != V_70 &&
V_6 -> V_24 != V_71 ) {
V_21 = - V_35 ;
goto V_69;
}
V_68 = F_42 ( V_4 , & V_48 -> V_72 ) ;
if ( V_68 < 0 || V_4 -> V_56 [ V_68 ] . V_57 . V_73 ) {
F_4 ( & V_4 -> V_14 -> V_4 , L_12 ,
& V_48 -> V_72 ) ;
V_21 = - V_55 ;
goto V_69;
}
V_6 -> V_54 = V_4 -> V_56 [ V_68 ] . V_74 ;
F_4 ( & V_4 -> V_14 -> V_4 , L_13 ,
V_6 -> V_54 ) ;
F_4 ( & V_4 -> V_14 -> V_4 , L_14 ,
V_4 -> V_56 [ V_68 ] . V_57 . V_75 ) ;
F_4 ( & V_4 -> V_14 -> V_4 , L_15 ,
V_4 -> V_56 [ V_68 ] . V_57 . V_58 ) ;
if ( F_43 ( V_48 -> V_72 , V_76 ) == 0 ) {
F_4 ( & V_4 -> V_14 -> V_4 , L_16 ) ;
if ( V_4 -> V_22 . V_24 != V_25 ) {
V_21 = - V_10 ;
goto V_69;
}
F_17 ( V_6 ) ;
F_10 ( V_6 ) ;
V_6 = NULL ;
V_4 -> V_77 ++ ;
V_2 -> V_18 = & V_4 -> V_22 ;
V_67 = & V_48 -> V_78 ;
V_67 -> V_58 =
V_4 -> V_56 [ V_68 ] . V_57 . V_58 ;
V_67 -> V_75 =
V_4 -> V_56 [ V_68 ] . V_57 . V_75 ;
V_21 = V_4 -> V_22 . V_79 ;
goto V_69;
}
V_67 = & V_48 -> V_78 ;
V_67 -> V_58 = V_4 -> V_56 [ V_68 ] . V_57 . V_58 ;
V_67 -> V_75 = V_4 -> V_56 [ V_68 ] . V_57 . V_75 ;
F_4 ( & V_4 -> V_14 -> V_4 , L_17 ) ;
V_21 = F_44 ( V_6 , V_2 ) ;
V_69:
return V_21 ;
}
static long F_45 ( struct V_2 * V_2 , unsigned int V_80 , unsigned long V_48 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_18 ;
struct V_65 * V_81 = NULL ;
int V_21 ;
if ( V_80 != V_82 )
return - V_83 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_4 ( & V_4 -> V_14 -> V_4 , L_18 , V_80 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_21 = - V_10 ;
goto V_23;
}
F_4 ( & V_4 -> V_14 -> V_4 , L_19 ) ;
V_81 = F_46 ( sizeof( struct V_65 ) ,
V_84 ) ;
if ( ! V_81 ) {
V_21 = - V_16 ;
goto V_23;
}
F_4 ( & V_4 -> V_14 -> V_4 , L_20 ) ;
if ( F_38 ( V_81 , ( char T_2 * ) V_48 ,
sizeof( struct V_65 ) ) ) {
F_4 ( & V_4 -> V_14 -> V_4 , L_10 ) ;
V_21 = - V_49 ;
goto V_23;
}
V_21 = F_41 ( V_2 , V_81 ) ;
if ( V_21 )
goto V_23;
F_4 ( & V_4 -> V_14 -> V_4 , L_21 ) ;
if ( F_29 ( ( char T_2 * ) V_48 , V_81 ,
sizeof( struct V_65 ) ) ) {
F_4 ( & V_4 -> V_14 -> V_4 , L_6 ) ;
V_21 = - V_49 ;
goto V_23;
}
V_23:
F_10 ( V_81 ) ;
F_8 ( & V_4 -> V_11 ) ;
return V_21 ;
}
static long F_47 ( struct V_2 * V_2 ,
unsigned int V_80 , unsigned long V_48 )
{
return F_45 ( V_2 , V_80 , ( unsigned long ) F_48 ( V_48 ) ) ;
}
static unsigned int F_49 ( struct V_2 * V_2 , T_5 * V_85 )
{
struct V_5 * V_6 = V_2 -> V_18 ;
struct V_3 * V_4 ;
unsigned int V_86 = 0 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return V_87 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_50 ( V_6 ) ) {
V_86 = V_87 ;
goto V_23;
}
F_8 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_22 )
return F_51 ( V_4 , V_2 , V_85 ) ;
F_52 ( V_2 , & V_6 -> V_88 , V_85 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_50 ( V_6 ) ) {
V_86 = V_87 ;
goto V_23;
}
V_86 |= ( V_89 | V_90 ) ;
V_23:
F_8 ( & V_4 -> V_11 ) ;
return V_86 ;
}
static int F_53 ( struct V_3 * V_4 )
{
int V_91 ;
F_3 ( & V_92 ) ;
V_91 = F_54 ( & V_93 , V_4 , 0 , V_94 , V_84 ) ;
if ( V_91 >= 0 )
V_4 -> V_95 = V_91 ;
else if ( V_91 == - V_96 )
F_32 ( & V_4 -> V_14 -> V_4 , L_22 ) ;
F_8 ( & V_92 ) ;
return V_91 ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_3 ( & V_92 ) ;
F_56 ( & V_93 , V_4 -> V_95 ) ;
F_8 ( & V_92 ) ;
}
int F_57 ( struct V_3 * V_4 , struct V_97 * V_98 )
{
struct V_97 * V_99 ;
int V_91 , V_100 ;
V_91 = F_53 ( V_4 ) ;
if ( V_91 < 0 )
return V_91 ;
V_100 = F_58 ( F_59 ( V_101 ) , V_4 -> V_95 ) ;
F_60 ( & V_4 -> V_9 , & V_102 ) ;
V_4 -> V_9 . V_103 = V_102 . V_103 ;
V_91 = F_61 ( & V_4 -> V_9 , V_100 , 1 ) ;
if ( V_91 ) {
F_32 ( V_98 , L_23 ,
F_59 ( V_101 ) , V_4 -> V_95 ) ;
goto V_104;
}
V_99 = F_62 ( V_105 , V_98 , V_100 ,
NULL , L_24 , V_4 -> V_95 ) ;
if ( F_63 ( V_99 ) ) {
F_32 ( V_98 , L_25 ,
F_59 ( V_101 ) , V_4 -> V_95 ) ;
V_91 = F_64 ( V_99 ) ;
goto V_106;
}
V_91 = F_65 ( V_4 , F_66 ( V_99 ) ) ;
if ( V_91 ) {
F_32 ( V_99 , L_26 , V_91 ) ;
goto V_107;
}
return 0 ;
V_107:
F_67 ( V_105 , V_100 ) ;
V_106:
F_68 ( & V_4 -> V_9 ) ;
V_104:
F_55 ( V_4 ) ;
return V_91 ;
}
void F_69 ( struct V_3 * V_4 )
{
int V_100 ;
V_100 = V_4 -> V_9 . V_4 ;
F_68 ( & V_4 -> V_9 ) ;
F_70 ( V_4 ) ;
F_67 ( V_105 , V_100 ) ;
F_55 ( V_4 ) ;
}
static int T_6 F_71 ( void )
{
int V_91 ;
V_105 = F_72 ( V_108 , L_27 ) ;
if ( F_63 ( V_105 ) ) {
F_73 ( L_28 ) ;
V_91 = F_64 ( V_105 ) ;
goto V_7;
}
V_91 = F_74 ( & V_101 , 0 , V_94 , L_27 ) ;
if ( V_91 < 0 ) {
F_73 ( L_29 ) ;
goto V_109;
}
V_91 = F_75 () ;
if ( V_91 < 0 ) {
F_73 ( L_30 ) ;
goto V_110;
}
return 0 ;
V_110:
F_76 ( V_101 , V_94 ) ;
V_109:
F_77 ( V_105 ) ;
V_7:
return V_91 ;
}
static void T_7 F_78 ( void )
{
F_76 ( V_101 , V_94 ) ;
F_77 ( V_105 ) ;
F_79 () ;
}
