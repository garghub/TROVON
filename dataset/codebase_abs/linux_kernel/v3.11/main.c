static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
V_12 = - V_13 ;
if ( ! V_4 -> V_14 )
goto V_15;
V_7 = F_2 ( V_4 -> V_14 , struct V_6 , V_11 ) ;
V_11 = F_3 ( V_7 ) ;
if ( ! V_11 )
goto V_15;
F_4 ( & V_11 -> V_16 ) ;
V_12 = - V_17 ;
V_9 = F_5 ( V_11 ) ;
if ( ! V_9 )
goto V_18;
V_12 = - V_13 ;
if ( V_11 -> V_19 != V_20 ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_1 ,
F_7 ( V_11 -> V_19 ) ) ;
goto V_18;
}
V_12 = - V_21 ;
if ( V_11 -> V_22 >= V_23 ) {
F_8 ( & V_11 -> V_7 -> V_11 , L_2 ,
V_23 ) ;
goto V_18;
}
V_12 = F_9 ( V_9 , V_24 ) ;
if ( V_12 )
goto V_18;
V_2 -> V_5 = V_9 ;
F_10 ( & V_11 -> V_16 ) ;
return F_11 ( V_1 , V_2 ) ;
V_18:
F_10 ( & V_11 -> V_16 ) ;
F_12 ( V_9 ) ;
V_15:
return V_12 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_25 * V_26 ;
struct V_10 * V_11 ;
int V_27 = 0 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_9 == & V_11 -> V_28 ) {
V_27 = F_15 ( V_11 , V_2 ) ;
goto V_15;
}
if ( V_9 -> V_29 == V_30 ) {
V_9 -> V_29 = V_31 ;
F_6 ( & V_11 -> V_7 -> V_11 ,
L_3
L_4 ,
V_9 -> V_32 ,
V_9 -> V_33 ) ;
V_27 = F_16 ( V_9 ) ;
}
F_17 ( V_9 ) ;
F_6 ( & V_11 -> V_7 -> V_11 , L_5 ,
V_9 -> V_32 ,
V_9 -> V_33 ) ;
if ( V_11 -> V_22 > 0 ) {
F_18 ( V_9 -> V_32 , V_11 -> V_34 ) ;
V_11 -> V_22 -- ;
}
F_19 ( V_9 ) ;
V_26 = NULL ;
if ( V_9 -> V_35 ) {
V_26 = F_20 ( V_9 ) ;
if ( V_26 )
F_21 ( & V_26 -> V_36 ) ;
V_26 = V_9 -> V_35 ;
V_9 -> V_35 = NULL ;
}
V_2 -> V_5 = NULL ;
if ( V_26 ) {
F_22 ( V_26 ) ;
V_26 = NULL ;
}
F_12 ( V_9 ) ;
V_15:
F_10 ( & V_11 -> V_16 ) ;
return V_27 ;
}
static T_1 F_23 ( struct V_2 * V_2 , char T_2 * V_37 ,
T_3 V_38 , T_4 * V_39 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_25 * V_40 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_10 * V_11 ;
int V_27 ;
int V_12 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_15;
}
if ( V_9 == & V_11 -> V_28 ) {
V_27 = F_24 ( V_11 , V_2 , V_37 , V_38 , V_39 ) ;
goto V_15;
}
if ( V_9 -> V_35 ) {
V_26 = V_9 -> V_35 ;
if ( V_26 -> V_41 > * V_39 )
goto V_42;
if ( V_26 -> V_41 > 0 && V_26 -> V_41 <= * V_39 ) {
V_27 = 0 ;
goto free;
}
if ( V_26 -> V_41 == 0 && * V_39 > 0 )
* V_39 = 0 ;
} else if ( * V_39 > 0 ) {
* V_39 = 0 ;
}
V_12 = F_25 ( V_9 , V_38 ) ;
if ( V_12 && V_12 != - V_43 ) {
F_6 ( & V_11 -> V_7 -> V_11 ,
L_6 , V_12 ) ;
V_27 = V_12 ;
goto V_15;
}
if ( V_44 != V_9 -> V_45 &&
! F_26 ( & V_9 -> V_46 ) ) {
if ( V_2 -> V_47 & V_48 ) {
V_27 = - V_49 ;
goto V_15;
}
F_10 ( & V_11 -> V_16 ) ;
if ( F_27 ( V_9 -> V_46 ,
( V_44 == V_9 -> V_45 ||
V_50 == V_9 -> V_29 ||
V_51 == V_9 -> V_29 ||
V_31 == V_9 -> V_29 ) ) ) {
if ( F_28 ( V_52 ) )
return - V_53 ;
return - V_54 ;
}
F_4 ( & V_11 -> V_16 ) ;
if ( V_50 == V_9 -> V_29 ||
V_51 == V_9 -> V_29 ||
V_31 == V_9 -> V_29 ) {
V_27 = - V_43 ;
goto V_15;
}
}
V_26 = V_9 -> V_35 ;
if ( ! V_26 ) {
V_27 = - V_13 ;
goto V_15;
}
if ( V_9 -> V_45 != V_44 ) {
V_27 = 0 ;
goto V_15;
}
V_42:
F_6 ( & V_11 -> V_7 -> V_11 , L_7 ,
V_26 -> V_55 . V_56 , V_26 -> V_41 ) ;
if ( V_38 == 0 || V_37 == NULL || * V_39 > V_26 -> V_41 ) {
V_27 = - V_57 ;
goto free;
}
V_38 = F_29 ( T_3 , V_38 , V_26 -> V_41 - * V_39 ) ;
if ( F_30 ( V_37 , V_26 -> V_55 . V_58 + * V_39 , V_38 ) ) {
V_27 = - V_59 ;
goto free;
}
V_27 = V_38 ;
* V_39 += V_38 ;
if ( ( unsigned long ) * V_39 < V_26 -> V_41 )
goto V_15;
free:
V_40 = F_20 ( V_9 ) ;
if ( V_40 )
F_21 ( & V_40 -> V_36 ) ;
F_22 ( V_26 ) ;
V_9 -> V_45 = V_60 ;
V_9 -> V_35 = NULL ;
V_15:
F_6 ( & V_11 -> V_7 -> V_11 , L_8 , V_27 ) ;
F_10 ( & V_11 -> V_16 ) ;
return V_27 ;
}
static T_1 F_31 ( struct V_2 * V_2 , const char T_2 * V_37 ,
T_3 V_38 , T_4 * V_39 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_25 * V_61 = NULL ;
struct V_10 * V_11 ;
unsigned long V_62 = 0 ;
int V_27 ;
int V_63 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_15;
}
V_63 = F_32 ( V_11 , V_9 -> V_33 ) ;
if ( V_63 < 0 ) {
V_27 = - V_13 ;
goto V_15;
}
if ( V_38 > V_11 -> V_64 [ V_63 ] . V_65 . V_66 || V_38 <= 0 ) {
V_27 = - V_57 ;
goto V_15;
}
if ( V_9 -> V_29 != V_30 ) {
F_8 ( & V_11 -> V_7 -> V_11 , L_9 ,
V_9 -> V_32 , V_9 -> V_33 ) ;
V_27 = - V_13 ;
goto V_15;
}
if ( V_9 == & V_11 -> V_28 ) {
V_61 = F_33 ( V_11 , V_2 ) ;
if ( V_61 ) {
V_62 = V_61 -> V_67 +
F_34 ( V_68 ) ;
if ( F_35 ( V_69 , V_62 ) ||
V_9 -> V_45 == V_44 ) {
* V_39 = 0 ;
F_21 ( & V_61 -> V_36 ) ;
F_22 ( V_61 ) ;
V_61 = NULL ;
}
}
}
if ( V_9 -> V_45 == V_44 ) {
* V_39 = 0 ;
V_61 = F_20 ( V_9 ) ;
if ( V_61 ) {
F_21 ( & V_61 -> V_36 ) ;
F_22 ( V_61 ) ;
V_61 = NULL ;
V_9 -> V_45 = V_60 ;
V_9 -> V_35 = NULL ;
}
} else if ( V_9 -> V_45 == V_60 )
* V_39 = 0 ;
V_61 = F_36 ( V_9 , V_2 ) ;
if ( ! V_61 ) {
F_8 ( & V_11 -> V_7 -> V_11 , L_10 ) ;
V_27 = - V_17 ;
goto V_15;
}
V_27 = F_37 ( V_61 , V_38 ) ;
if ( V_27 )
goto V_15;
V_27 = F_38 ( V_61 -> V_70 . V_58 , V_37 , V_38 ) ;
if ( V_27 )
goto V_15;
if ( V_9 == & V_11 -> V_28 ) {
V_27 = F_39 ( V_11 , V_61 ) ;
if ( V_27 ) {
F_8 ( & V_11 -> V_7 -> V_11 ,
L_11 , V_27 ) ;
goto V_15;
}
F_10 ( & V_11 -> V_16 ) ;
return V_38 ;
}
V_27 = F_40 ( V_9 , V_61 , false ) ;
V_15:
F_10 ( & V_11 -> V_16 ) ;
if ( V_27 < 0 )
F_22 ( V_61 ) ;
return V_27 ;
}
static int F_41 ( struct V_2 * V_2 ,
struct V_71 * V_58 )
{
struct V_10 * V_11 ;
struct V_72 * V_73 ;
struct V_8 * V_9 ;
int V_74 ;
int V_27 ;
V_9 = V_2 -> V_5 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_75;
}
if ( V_9 -> V_29 != V_50 &&
V_9 -> V_29 != V_51 ) {
V_27 = - V_43 ;
goto V_75;
}
V_74 = F_42 ( V_11 , & V_58 -> V_76 ) ;
if ( V_74 < 0 || V_11 -> V_64 [ V_74 ] . V_65 . V_77 ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_12 ,
& V_58 -> V_76 ) ;
V_27 = - V_13 ;
goto V_75;
}
V_9 -> V_33 = V_11 -> V_64 [ V_74 ] . V_78 ;
V_9 -> V_29 = V_79 ;
F_6 ( & V_11 -> V_7 -> V_11 , L_13 ,
V_9 -> V_33 ) ;
F_6 ( & V_11 -> V_7 -> V_11 , L_14 ,
V_11 -> V_64 [ V_74 ] . V_65 . V_80 ) ;
F_6 ( & V_11 -> V_7 -> V_11 , L_15 ,
V_11 -> V_64 [ V_74 ] . V_65 . V_66 ) ;
if ( F_43 ( V_58 -> V_76 , V_81 ) == 0 ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_16 ) ;
if ( V_11 -> V_28 . V_29 != V_30 ) {
V_27 = - V_13 ;
goto V_75;
}
F_18 ( V_9 -> V_32 , V_11 -> V_34 ) ;
F_19 ( V_9 ) ;
F_12 ( V_9 ) ;
V_9 = NULL ;
V_2 -> V_5 = & V_11 -> V_28 ;
V_73 = & V_58 -> V_82 ;
V_73 -> V_66 =
V_11 -> V_64 [ V_74 ] . V_65 . V_66 ;
V_73 -> V_80 =
V_11 -> V_64 [ V_74 ] . V_65 . V_80 ;
V_27 = V_11 -> V_28 . V_83 ;
goto V_75;
}
V_73 = & V_58 -> V_82 ;
V_73 -> V_66 = V_11 -> V_64 [ V_74 ] . V_65 . V_66 ;
V_73 -> V_80 = V_11 -> V_64 [ V_74 ] . V_65 . V_80 ;
F_6 ( & V_11 -> V_7 -> V_11 , L_17 ) ;
V_27 = F_44 ( V_9 , V_2 ) ;
V_75:
return V_27 ;
}
static long F_45 ( struct V_2 * V_2 , unsigned int V_84 , unsigned long V_58 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_71 * V_85 = NULL ;
int V_27 ;
if ( V_84 != V_86 )
return - V_87 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
F_6 ( & V_11 -> V_7 -> V_11 , L_18 , V_84 ) ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_15;
}
F_6 ( & V_11 -> V_7 -> V_11 , L_19 ) ;
V_85 = F_46 ( sizeof( struct V_71 ) ,
V_88 ) ;
if ( ! V_85 ) {
V_27 = - V_17 ;
goto V_15;
}
F_6 ( & V_11 -> V_7 -> V_11 , L_20 ) ;
if ( F_38 ( V_85 , ( char T_2 * ) V_58 ,
sizeof( struct V_71 ) ) ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_21 ) ;
V_27 = - V_59 ;
goto V_15;
}
V_27 = F_41 ( V_2 , V_85 ) ;
if ( V_27 )
goto V_15;
F_6 ( & V_11 -> V_7 -> V_11 , L_22 ) ;
if ( F_30 ( ( char T_2 * ) V_58 , V_85 ,
sizeof( struct V_71 ) ) ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_23 ) ;
V_27 = - V_59 ;
goto V_15;
}
V_15:
F_12 ( V_85 ) ;
F_10 ( & V_11 -> V_16 ) ;
return V_27 ;
}
static long F_47 ( struct V_2 * V_2 ,
unsigned int V_84 , unsigned long V_58 )
{
return F_45 ( V_2 , V_84 , ( unsigned long ) F_48 ( V_58 ) ) ;
}
static unsigned int F_49 ( struct V_2 * V_2 , T_5 * V_89 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_10 * V_11 ;
unsigned int V_90 = 0 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return V_90 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 )
goto V_15;
if ( V_9 == & V_11 -> V_28 ) {
V_90 = F_50 ( V_11 , V_2 , V_89 ) ;
goto V_15;
}
F_10 ( & V_11 -> V_16 ) ;
F_51 ( V_2 , & V_9 -> V_91 , V_89 ) ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_92 == V_9 -> V_93 )
V_90 |= ( V_94 | V_95 ) ;
V_15:
F_10 ( & V_11 -> V_16 ) ;
return V_90 ;
}
int F_52 ( struct V_10 * V_11 )
{
int V_96 ;
V_97 . V_14 = & V_11 -> V_7 -> V_11 ;
V_96 = F_53 ( & V_97 ) ;
if ( V_96 )
return V_96 ;
if ( F_54 ( V_11 , V_97 . V_98 ) )
F_8 ( & V_11 -> V_7 -> V_11 , L_24 ) ;
return 0 ;
}
void F_55 ( struct V_10 * V_11 )
{
F_56 ( V_11 ) ;
F_57 ( & V_97 ) ;
V_97 . V_14 = NULL ;
}
static int T_6 F_58 ( void )
{
return F_59 () ;
}
static void T_7 F_60 ( void )
{
F_61 () ;
}
