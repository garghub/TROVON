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
F_15 ( V_11 , V_9 , L_2 ) ;
V_23 = F_16 ( V_9 ) ;
}
F_17 ( V_9 ) ;
F_15 ( V_11 , V_9 , L_3 ) ;
F_18 ( V_9 ) ;
V_22 = NULL ;
if ( V_9 -> V_29 ) {
V_22 = F_19 ( V_9 ) ;
if ( V_22 )
F_20 ( & V_22 -> V_30 ) ;
V_22 = V_9 -> V_29 ;
V_9 -> V_29 = NULL ;
}
V_2 -> V_5 = NULL ;
F_21 ( V_22 ) ;
F_11 ( V_9 ) ;
V_25:
F_9 ( & V_11 -> V_15 ) ;
return V_23 ;
}
static T_1 F_22 ( struct V_2 * V_2 , char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_21 * V_34 = NULL ;
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
if ( V_32 == 0 ) {
V_23 = 0 ;
goto V_25;
}
if ( V_9 == & V_11 -> V_24 ) {
V_23 = F_23 ( V_11 , V_2 , V_31 , V_32 , V_33 ) ;
goto V_25;
}
if ( V_9 -> V_29 ) {
V_22 = V_9 -> V_29 ;
if ( V_22 -> V_35 > * V_33 )
goto V_36;
if ( V_22 -> V_35 > 0 && V_22 -> V_35 <= * V_33 ) {
V_23 = 0 ;
goto free;
}
if ( V_22 -> V_35 == 0 && * V_33 > 0 )
* V_33 = 0 ;
} else if ( * V_33 > 0 ) {
* V_33 = 0 ;
}
V_12 = F_24 ( V_9 , V_32 ) ;
if ( V_12 && V_12 != - V_37 ) {
F_5 ( & V_11 -> V_7 -> V_11 ,
L_4 , V_12 ) ;
V_23 = V_12 ;
goto V_25;
}
if ( V_38 != V_9 -> V_39 &&
! F_25 ( & V_9 -> V_40 ) ) {
if ( V_2 -> V_41 & V_42 ) {
V_23 = - V_43 ;
goto V_25;
}
F_9 ( & V_11 -> V_15 ) ;
if ( F_26 ( V_9 -> V_40 ,
V_38 == V_9 -> V_39 ||
F_27 ( V_9 ) ) ) {
if ( F_28 ( V_44 ) )
return - V_45 ;
return - V_46 ;
}
F_4 ( & V_11 -> V_15 ) ;
if ( F_27 ( V_9 ) ) {
V_23 = - V_37 ;
goto V_25;
}
}
V_22 = V_9 -> V_29 ;
if ( ! V_22 ) {
V_23 = - V_14 ;
goto V_25;
}
if ( V_9 -> V_39 != V_38 ) {
V_23 = 0 ;
goto V_25;
}
V_36:
F_5 ( & V_11 -> V_7 -> V_11 , L_5 ,
V_22 -> V_47 . V_48 , V_22 -> V_35 ) ;
if ( V_32 == 0 || V_31 == NULL || * V_33 > V_22 -> V_35 ) {
V_23 = - V_49 ;
goto free;
}
V_32 = F_29 ( T_3 , V_32 , V_22 -> V_35 - * V_33 ) ;
if ( F_30 ( V_31 , V_22 -> V_47 . V_50 + * V_33 , V_32 ) ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_6 ) ;
V_23 = - V_51 ;
goto free;
}
V_23 = V_32 ;
* V_33 += V_32 ;
if ( ( unsigned long ) * V_33 < V_22 -> V_35 )
goto V_25;
free:
V_34 = F_19 ( V_9 ) ;
if ( V_34 )
F_20 ( & V_34 -> V_30 ) ;
F_21 ( V_22 ) ;
V_9 -> V_39 = V_52 ;
V_9 -> V_29 = NULL ;
V_25:
F_5 ( & V_11 -> V_7 -> V_11 , L_7 , V_23 ) ;
F_9 ( & V_11 -> V_15 ) ;
return V_23 ;
}
static T_1 F_31 ( struct V_2 * V_2 , const char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_21 * V_53 = NULL ;
struct V_10 * V_11 ;
unsigned long V_54 = 0 ;
int V_23 ;
int V_55 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_25;
}
V_55 = F_32 ( V_11 , V_9 -> V_56 ) ;
if ( V_55 < 0 ) {
V_23 = - V_57 ;
goto V_25;
}
if ( V_32 == 0 ) {
V_23 = 0 ;
goto V_25;
}
if ( V_32 > V_11 -> V_58 [ V_55 ] . V_59 . V_60 ) {
V_23 = - V_61 ;
goto V_25;
}
if ( V_9 -> V_26 != V_27 ) {
F_33 ( & V_11 -> V_7 -> V_11 , L_8 ,
V_9 -> V_62 , V_9 -> V_56 ) ;
V_23 = - V_14 ;
goto V_25;
}
if ( V_9 == & V_11 -> V_24 ) {
V_53 = F_34 ( V_11 , V_2 ) ;
if ( V_53 ) {
V_54 = V_53 -> V_63 +
F_35 ( V_64 ) ;
if ( F_36 ( V_65 , V_54 ) ||
V_9 -> V_39 == V_38 ) {
* V_33 = 0 ;
F_20 ( & V_53 -> V_30 ) ;
F_21 ( V_53 ) ;
V_53 = NULL ;
}
}
}
if ( V_9 -> V_39 == V_38 ) {
* V_33 = 0 ;
V_53 = F_19 ( V_9 ) ;
if ( V_53 ) {
F_20 ( & V_53 -> V_30 ) ;
F_21 ( V_53 ) ;
V_53 = NULL ;
V_9 -> V_39 = V_52 ;
V_9 -> V_29 = NULL ;
}
} else if ( V_9 -> V_39 == V_52 )
* V_33 = 0 ;
V_53 = F_37 ( V_9 , V_2 ) ;
if ( ! V_53 ) {
F_33 ( & V_11 -> V_7 -> V_11 , L_9 ) ;
V_23 = - V_19 ;
goto V_25;
}
V_23 = F_38 ( V_53 , V_32 ) ;
if ( V_23 )
goto V_25;
V_23 = F_39 ( V_53 -> V_66 . V_50 , V_31 , V_32 ) ;
if ( V_23 ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_10 ) ;
V_23 = - V_51 ;
goto V_25;
}
if ( V_9 == & V_11 -> V_24 ) {
V_23 = F_40 ( V_11 , V_53 ) ;
if ( V_23 ) {
F_33 ( & V_11 -> V_7 -> V_11 ,
L_11 , V_23 ) ;
goto V_25;
}
F_9 ( & V_11 -> V_15 ) ;
return V_32 ;
}
V_23 = F_41 ( V_9 , V_53 , false ) ;
V_25:
F_9 ( & V_11 -> V_15 ) ;
if ( V_23 < 0 )
F_21 ( V_53 ) ;
return V_23 ;
}
static int F_42 ( struct V_2 * V_2 ,
struct V_67 * V_50 )
{
struct V_10 * V_11 ;
struct V_68 * V_69 ;
struct V_8 * V_9 ;
int V_70 ;
int V_23 ;
V_9 = V_2 -> V_5 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_71;
}
if ( V_9 -> V_26 != V_72 &&
V_9 -> V_26 != V_73 ) {
V_23 = - V_37 ;
goto V_71;
}
V_70 = F_43 ( V_11 , & V_50 -> V_74 ) ;
if ( V_70 < 0 || V_11 -> V_58 [ V_70 ] . V_59 . V_75 ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_12 ,
& V_50 -> V_74 ) ;
V_23 = - V_57 ;
goto V_71;
}
V_9 -> V_56 = V_11 -> V_58 [ V_70 ] . V_76 ;
V_9 -> V_26 = V_77 ;
F_5 ( & V_11 -> V_7 -> V_11 , L_13 ,
V_9 -> V_56 ) ;
F_5 ( & V_11 -> V_7 -> V_11 , L_14 ,
V_11 -> V_58 [ V_70 ] . V_59 . V_78 ) ;
F_5 ( & V_11 -> V_7 -> V_11 , L_15 ,
V_11 -> V_58 [ V_70 ] . V_59 . V_60 ) ;
if ( F_44 ( V_50 -> V_74 , V_79 ) == 0 ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_16 ) ;
if ( V_11 -> V_24 . V_26 != V_27 ) {
V_23 = - V_14 ;
goto V_71;
}
F_18 ( V_9 ) ;
F_11 ( V_9 ) ;
V_9 = NULL ;
V_11 -> V_80 ++ ;
V_2 -> V_5 = & V_11 -> V_24 ;
V_69 = & V_50 -> V_81 ;
V_69 -> V_60 =
V_11 -> V_58 [ V_70 ] . V_59 . V_60 ;
V_69 -> V_78 =
V_11 -> V_58 [ V_70 ] . V_59 . V_78 ;
V_23 = V_11 -> V_24 . V_82 ;
goto V_71;
}
V_69 = & V_50 -> V_81 ;
V_69 -> V_60 = V_11 -> V_58 [ V_70 ] . V_59 . V_60 ;
V_69 -> V_78 = V_11 -> V_58 [ V_70 ] . V_59 . V_78 ;
F_5 ( & V_11 -> V_7 -> V_11 , L_17 ) ;
V_23 = F_45 ( V_9 , V_2 ) ;
V_71:
return V_23 ;
}
static long F_46 ( struct V_2 * V_2 , unsigned int V_83 , unsigned long V_50 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_67 * V_84 = NULL ;
int V_23 ;
if ( V_83 != V_85 )
return - V_86 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_14 ;
V_11 = V_9 -> V_11 ;
F_5 ( & V_11 -> V_7 -> V_11 , L_18 , V_83 ) ;
F_4 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_16 != V_17 ) {
V_23 = - V_14 ;
goto V_25;
}
F_5 ( & V_11 -> V_7 -> V_11 , L_19 ) ;
V_84 = F_47 ( sizeof( struct V_67 ) ,
V_87 ) ;
if ( ! V_84 ) {
V_23 = - V_19 ;
goto V_25;
}
F_5 ( & V_11 -> V_7 -> V_11 , L_20 ) ;
if ( F_39 ( V_84 , ( char T_2 * ) V_50 ,
sizeof( struct V_67 ) ) ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_10 ) ;
V_23 = - V_51 ;
goto V_25;
}
V_23 = F_42 ( V_2 , V_84 ) ;
if ( V_23 )
goto V_25;
F_5 ( & V_11 -> V_7 -> V_11 , L_21 ) ;
if ( F_30 ( ( char T_2 * ) V_50 , V_84 ,
sizeof( struct V_67 ) ) ) {
F_5 ( & V_11 -> V_7 -> V_11 , L_6 ) ;
V_23 = - V_51 ;
goto V_25;
}
V_25:
F_11 ( V_84 ) ;
F_9 ( & V_11 -> V_15 ) ;
return V_23 ;
}
static long F_48 ( struct V_2 * V_2 ,
unsigned int V_83 , unsigned long V_50 )
{
return F_46 ( V_2 , V_83 , ( unsigned long ) F_49 ( V_50 ) ) ;
}
static unsigned int F_50 ( struct V_2 * V_2 , T_5 * V_88 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_10 * V_11 ;
unsigned int V_89 = 0 ;
if ( F_13 ( ! V_9 || ! V_9 -> V_11 ) )
return V_90 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_15 ) ;
if ( ! F_51 ( V_9 ) ) {
V_89 = V_90 ;
goto V_25;
}
F_9 ( & V_11 -> V_15 ) ;
if ( V_9 == & V_11 -> V_24 )
return F_52 ( V_11 , V_2 , V_88 ) ;
F_53 ( V_2 , & V_9 -> V_91 , V_88 ) ;
F_4 ( & V_11 -> V_15 ) ;
if ( ! F_51 ( V_9 ) ) {
V_89 = V_90 ;
goto V_25;
}
V_89 |= ( V_92 | V_93 ) ;
V_25:
F_9 ( & V_11 -> V_15 ) ;
return V_89 ;
}
int F_54 ( struct V_10 * V_11 )
{
int V_94 ;
V_95 . V_13 = & V_11 -> V_7 -> V_11 ;
V_94 = F_55 ( & V_95 ) ;
if ( V_94 )
return V_94 ;
if ( F_56 ( V_11 , V_95 . V_96 ) )
F_33 ( & V_11 -> V_7 -> V_11 , L_22 ) ;
return 0 ;
}
void F_57 ( struct V_10 * V_11 )
{
F_58 ( V_11 ) ;
F_59 ( & V_95 ) ;
V_95 . V_13 = NULL ;
}
static int T_6 F_60 ( void )
{
return F_61 () ;
}
static void T_7 F_62 ( void )
{
F_63 () ;
}
