static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
if ( ! V_4 -> V_13 )
return - V_14 ;
V_7 = F_2 ( V_4 -> V_13 , struct V_6 , V_11 ) ;
V_11 = F_3 ( V_7 ) ;
if ( ! V_11 )
return - V_14 ;
F_4 ( & V_11 -> V_15 ) ;
V_9 = NULL ;
V_12 = - V_14 ;
if ( V_11 -> V_16 != V_17 ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_1 ,
F_6 ( V_11 -> V_16 ) ) ;
goto V_18;
}
V_12 = - V_19 ;
V_9 = F_7 ( V_11 ) ;
if ( ! V_9 )
goto V_18;
V_12 = F_8 ( V_9 , V_20 ) ;
if ( V_12 )
goto V_18;
V_2 -> V_5 = V_9 ;
F_9 ( & V_11 -> V_15 ) ;
return F_10 ( V_1 , V_2 ) ;
V_18:
F_9 ( & V_11 -> V_15 ) ;
F_11 ( V_9 ) ;
return V_12 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
int V_23 = 0 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_15 ) ;
if ( V_9 == & V_11 -> V_24 ) {
V_23 = F_14 ( V_11 , V_2 ) ;
goto V_25;
}
if ( V_9 -> V_26 == V_27 ) {
V_9 -> V_26 = V_28 ;
F_5 ( & V_11 -> V_7 -> V_11 ,
L_2
L_3 ,
V_9 -> V_29 ,
V_9 -> V_30 ) ;
V_23 = F_15 ( V_9 ) ;
}
F_16 ( V_9 ) ;
F_5 ( & V_11 -> V_7 -> V_11 , L_4 ,
V_9 -> V_29 ,
V_9 -> V_30 ) ;
F_17 ( V_9 ) ;
V_22 = NULL ;
if ( V_9 -> V_31 ) {
V_22 = F_18 ( V_9 ) ;
if ( V_22 )
F_19 ( & V_22 -> V_32 ) ;
V_22 = V_9 -> V_31 ;
V_9 -> V_31 = NULL ;
}
V_2 -> V_5 = NULL ;
F_20 ( V_22 ) ;
F_11 ( V_9 ) ;
V_25:
F_9 ( & V_11 -> V_15 ) ;
return V_23 ;
}
static T_1 F_21 ( struct V_2 * V_2 , char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_21 * V_36 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_10 * V_11 ;
int V_23 ;
int V_12 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_25;
}
if ( V_34 == 0 ) {
V_23 = 0 ;
goto V_25;
}
if ( V_9 == & V_11 -> V_24 ) {
V_23 = F_22 ( V_11 , V_2 , V_33 , V_34 , V_35 ) ;
goto V_25;
}
if ( V_9 -> V_31 ) {
V_22 = V_9 -> V_31 ;
if ( V_22 -> V_37 > * V_35 )
goto V_38;
if ( V_22 -> V_37 > 0 && V_22 -> V_37 <= * V_35 ) {
V_23 = 0 ;
goto free;
}
if ( V_22 -> V_37 == 0 && * V_35 > 0 )
* V_35 = 0 ;
} else if ( * V_35 > 0 ) {
* V_35 = 0 ;
}
V_12 = F_23 ( V_9 , V_34 ) ;
if ( V_12 && V_12 != - V_39 ) {
F_5 ( & V_11 -> V_7 -> V_11 ,
L_5 , V_12 ) ;
V_23 = V_12 ;
goto V_25;
}
if ( V_40 != V_9 -> V_41 &&
! F_24 ( & V_9 -> V_42 ) ) {
if ( V_2 -> V_43 & V_44 ) {
V_23 = - V_45 ;
goto V_25;
}
F_9 ( & V_11 -> V_15 ) ;
if ( F_25 ( V_9 -> V_42 ,
V_40 == V_9 -> V_41 ||
F_26 ( V_9 ) ) ) {
if ( F_27 ( V_46 ) )
return - V_47 ;
return - V_48 ;
}
F_4 ( & V_11 -> V_15 ) ;
if ( F_26 ( V_9 ) ) {
V_23 = - V_39 ;
goto V_25;
}
}
V_22 = V_9 -> V_31 ;
if ( ! V_22 ) {
V_23 = - V_14 ;
goto V_25;
}
if ( V_9 -> V_41 != V_40 ) {
V_23 = 0 ;
goto V_25;
}
V_38:
F_5 ( & V_11 -> V_7 -> V_11 , L_6 ,
V_22 -> V_49 . V_50 , V_22 -> V_37 ) ;
if ( V_34 == 0 || V_33 == NULL || * V_35 > V_22 -> V_37 ) {
V_23 = - V_51 ;
goto free;
}
V_34 = F_28 ( T_3 , V_34 , V_22 -> V_37 - * V_35 ) ;
if ( F_29 ( V_33 , V_22 -> V_49 . V_52 + * V_35 , V_34 ) ) {
V_23 = - V_53 ;
goto free;
}
V_23 = V_34 ;
* V_35 += V_34 ;
if ( ( unsigned long ) * V_35 < V_22 -> V_37 )
goto V_25;
free:
V_36 = F_18 ( V_9 ) ;
if ( V_36 )
F_19 ( & V_36 -> V_32 ) ;
F_20 ( V_22 ) ;
V_9 -> V_41 = V_54 ;
V_9 -> V_31 = NULL ;
V_25:
F_5 ( & V_11 -> V_7 -> V_11 , L_7 , V_23 ) ;
F_9 ( & V_11 -> V_15 ) ;
return V_23 ;
}
static T_1 F_30 ( struct V_2 * V_2 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_21 * V_55 = NULL ;
struct V_10 * V_11 ;
unsigned long V_56 = 0 ;
int V_23 ;
int V_57 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_25;
}
V_57 = F_31 ( V_11 , V_9 -> V_30 ) ;
if ( V_57 < 0 ) {
V_23 = - V_14 ;
goto V_25;
}
if ( V_34 == 0 ) {
V_23 = 0 ;
goto V_25;
}
if ( V_34 > V_11 -> V_58 [ V_57 ] . V_59 . V_60 ) {
V_23 = - V_61 ;
goto V_25;
}
if ( V_9 -> V_26 != V_27 ) {
F_32 ( & V_11 -> V_7 -> V_11 , L_8 ,
V_9 -> V_29 , V_9 -> V_30 ) ;
V_23 = - V_14 ;
goto V_25;
}
if ( V_9 == & V_11 -> V_24 ) {
V_55 = F_33 ( V_11 , V_2 ) ;
if ( V_55 ) {
V_56 = V_55 -> V_62 +
F_34 ( V_63 ) ;
if ( F_35 ( V_64 , V_56 ) ||
V_9 -> V_41 == V_40 ) {
* V_35 = 0 ;
F_19 ( & V_55 -> V_32 ) ;
F_20 ( V_55 ) ;
V_55 = NULL ;
}
}
}
if ( V_9 -> V_41 == V_40 ) {
* V_35 = 0 ;
V_55 = F_18 ( V_9 ) ;
if ( V_55 ) {
F_19 ( & V_55 -> V_32 ) ;
F_20 ( V_55 ) ;
V_55 = NULL ;
V_9 -> V_41 = V_54 ;
V_9 -> V_31 = NULL ;
}
} else if ( V_9 -> V_41 == V_54 )
* V_35 = 0 ;
V_55 = F_36 ( V_9 , V_2 ) ;
if ( ! V_55 ) {
F_32 ( & V_11 -> V_7 -> V_11 , L_9 ) ;
V_23 = - V_19 ;
goto V_25;
}
V_23 = F_37 ( V_55 , V_34 ) ;
if ( V_23 )
goto V_25;
V_23 = F_38 ( V_55 -> V_65 . V_52 , V_33 , V_34 ) ;
if ( V_23 ) {
F_32 ( & V_11 -> V_7 -> V_11 , L_10 ) ;
V_23 = - V_53 ;
goto V_25;
}
if ( V_9 == & V_11 -> V_24 ) {
V_23 = F_39 ( V_11 , V_55 ) ;
if ( V_23 ) {
F_32 ( & V_11 -> V_7 -> V_11 ,
L_11 , V_23 ) ;
goto V_25;
}
F_9 ( & V_11 -> V_15 ) ;
return V_34 ;
}
V_23 = F_40 ( V_9 , V_55 , false ) ;
V_25:
F_9 ( & V_11 -> V_15 ) ;
if ( V_23 < 0 )
F_20 ( V_55 ) ;
return V_23 ;
}
static int F_41 ( struct V_2 * V_2 ,
struct V_66 * V_52 )
{
struct V_10 * V_11 ;
struct V_67 * V_68 ;
struct V_8 * V_9 ;
int V_69 ;
int V_23 ;
V_9 = V_2 -> V_5 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_70;
}
if ( V_9 -> V_26 != V_71 &&
V_9 -> V_26 != V_72 ) {
V_23 = - V_39 ;
goto V_70;
}
V_69 = F_42 ( V_11 , & V_52 -> V_73 ) ;
if ( V_69 < 0 || V_11 -> V_58 [ V_69 ] . V_59 . V_74 ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_12 ,
& V_52 -> V_73 ) ;
V_23 = - V_14 ;
goto V_70;
}
V_9 -> V_30 = V_11 -> V_58 [ V_69 ] . V_75 ;
V_9 -> V_26 = V_76 ;
F_5 ( & V_11 -> V_7 -> V_11 , L_13 ,
V_9 -> V_30 ) ;
F_5 ( & V_11 -> V_7 -> V_11 , L_14 ,
V_11 -> V_58 [ V_69 ] . V_59 . V_77 ) ;
F_5 ( & V_11 -> V_7 -> V_11 , L_15 ,
V_11 -> V_58 [ V_69 ] . V_59 . V_60 ) ;
if ( F_43 ( V_52 -> V_73 , V_78 ) == 0 ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_16 ) ;
if ( V_11 -> V_24 . V_26 != V_27 ) {
V_23 = - V_14 ;
goto V_70;
}
F_17 ( V_9 ) ;
F_11 ( V_9 ) ;
V_9 = NULL ;
V_11 -> V_79 ++ ;
V_2 -> V_5 = & V_11 -> V_24 ;
V_68 = & V_52 -> V_80 ;
V_68 -> V_60 =
V_11 -> V_58 [ V_69 ] . V_59 . V_60 ;
V_68 -> V_77 =
V_11 -> V_58 [ V_69 ] . V_59 . V_77 ;
V_23 = V_11 -> V_24 . V_81 ;
goto V_70;
}
V_68 = & V_52 -> V_80 ;
V_68 -> V_60 = V_11 -> V_58 [ V_69 ] . V_59 . V_60 ;
V_68 -> V_77 = V_11 -> V_58 [ V_69 ] . V_59 . V_77 ;
F_5 ( & V_11 -> V_7 -> V_11 , L_17 ) ;
V_23 = F_44 ( V_9 , V_2 ) ;
V_70:
return V_23 ;
}
static long F_45 ( struct V_2 * V_2 , unsigned int V_82 , unsigned long V_52 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_66 * V_83 = NULL ;
int V_23 ;
if ( V_82 != V_84 )
return - V_85 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
F_5 ( & V_11 -> V_7 -> V_11 , L_18 , V_82 ) ;
F_4 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_25;
}
F_5 ( & V_11 -> V_7 -> V_11 , L_19 ) ;
V_83 = F_46 ( sizeof( struct V_66 ) ,
V_86 ) ;
if ( ! V_83 ) {
V_23 = - V_19 ;
goto V_25;
}
F_5 ( & V_11 -> V_7 -> V_11 , L_20 ) ;
if ( F_38 ( V_83 , ( char T_2 * ) V_52 ,
sizeof( struct V_66 ) ) ) {
F_32 ( & V_11 -> V_7 -> V_11 , L_10 ) ;
V_23 = - V_53 ;
goto V_25;
}
V_23 = F_41 ( V_2 , V_83 ) ;
if ( V_23 )
goto V_25;
F_5 ( & V_11 -> V_7 -> V_11 , L_21 ) ;
if ( F_29 ( ( char T_2 * ) V_52 , V_83 ,
sizeof( struct V_66 ) ) ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_22 ) ;
V_23 = - V_53 ;
goto V_25;
}
V_25:
F_11 ( V_83 ) ;
F_9 ( & V_11 -> V_15 ) ;
return V_23 ;
}
static long F_47 ( struct V_2 * V_2 ,
unsigned int V_82 , unsigned long V_52 )
{
return F_45 ( V_2 , V_82 , ( unsigned long ) F_48 ( V_52 ) ) ;
}
static unsigned int F_49 ( struct V_2 * V_2 , T_5 * V_87 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_10 * V_11 ;
unsigned int V_88 = 0 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return V_89 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_15 ) ;
if ( ! F_50 ( V_9 ) ) {
V_88 = V_89 ;
goto V_25;
}
F_9 ( & V_11 -> V_15 ) ;
if ( V_9 == & V_11 -> V_24 )
return F_51 ( V_11 , V_2 , V_87 ) ;
F_52 ( V_2 , & V_9 -> V_90 , V_87 ) ;
F_4 ( & V_11 -> V_15 ) ;
if ( ! F_50 ( V_9 ) ) {
V_88 = V_89 ;
goto V_25;
}
if ( V_91 == V_9 -> V_92 )
V_88 |= ( V_93 | V_94 ) ;
V_25:
F_9 ( & V_11 -> V_15 ) ;
return V_88 ;
}
int F_53 ( struct V_10 * V_11 )
{
int V_95 ;
V_96 . V_13 = & V_11 -> V_7 -> V_11 ;
V_95 = F_54 ( & V_96 ) ;
if ( V_95 )
return V_95 ;
if ( F_55 ( V_11 , V_96 . V_97 ) )
F_32 ( & V_11 -> V_7 -> V_11 , L_23 ) ;
return 0 ;
}
void F_56 ( struct V_10 * V_11 )
{
F_57 ( V_11 ) ;
F_58 ( & V_96 ) ;
V_96 . V_13 = NULL ;
}
static int T_6 F_59 ( void )
{
return F_60 () ;
}
static void T_7 F_61 ( void )
{
F_62 () ;
}
