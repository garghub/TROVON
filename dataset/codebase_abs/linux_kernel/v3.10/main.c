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
int V_41 ;
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
if ( ( V_9 -> V_42 & V_43 ) == 0 ) {
V_41 = F_24 ( V_11 , & V_44 ) ;
if ( V_41 >= 0 ) {
struct V_45 * V_46 = & V_11 -> V_47 [ V_41 ] ;
if ( V_9 -> V_33 == V_46 -> V_48 ) {
V_27 = - V_49 ;
goto V_15;
}
}
} else {
V_9 -> V_42 &= ~ V_43 ;
}
if ( V_9 == & V_11 -> V_28 ) {
V_27 = F_25 ( V_11 , V_2 , V_37 , V_38 , V_39 ) ;
goto V_15;
}
if ( V_9 -> V_35 && V_9 -> V_35 -> V_50 > * V_39 ) {
V_26 = V_9 -> V_35 ;
goto V_51;
} else if ( V_9 -> V_35 && V_9 -> V_35 -> V_50 > 0 &&
V_9 -> V_35 -> V_50 <= * V_39 ) {
V_26 = V_9 -> V_35 ;
V_27 = 0 ;
goto free;
} else if ( ( ! V_9 -> V_35 || ! V_9 -> V_35 -> V_50 ) && * V_39 > 0 ) {
* V_39 = 0 ;
V_27 = 0 ;
goto V_15;
}
V_12 = F_26 ( V_9 , V_38 ) ;
if ( V_12 && V_12 != - V_52 ) {
F_6 ( & V_11 -> V_7 -> V_11 ,
L_6 , V_12 ) ;
V_27 = V_12 ;
goto V_15;
}
if ( V_53 != V_9 -> V_54 &&
! F_27 ( & V_9 -> V_55 ) ) {
if ( V_2 -> V_56 & V_57 ) {
V_27 = - V_58 ;
goto V_15;
}
F_10 ( & V_11 -> V_16 ) ;
if ( F_28 ( V_9 -> V_55 ,
( V_53 == V_9 -> V_54 ||
V_59 == V_9 -> V_29 ||
V_60 == V_9 -> V_29 ||
V_31 == V_9 -> V_29 ) ) ) {
if ( F_29 ( V_61 ) )
return - V_62 ;
return - V_63 ;
}
F_4 ( & V_11 -> V_16 ) ;
if ( V_59 == V_9 -> V_29 ||
V_60 == V_9 -> V_29 ||
V_31 == V_9 -> V_29 ) {
V_27 = - V_52 ;
goto V_15;
}
}
V_26 = V_9 -> V_35 ;
if ( ! V_26 ) {
V_27 = - V_13 ;
goto V_15;
}
if ( V_9 -> V_54 != V_53 ) {
V_27 = 0 ;
goto V_15;
}
V_51:
F_6 ( & V_11 -> V_7 -> V_11 , L_7 ,
V_26 -> V_64 . V_65 , V_26 -> V_50 ) ;
if ( V_38 == 0 || V_37 == NULL || * V_39 > V_26 -> V_50 ) {
V_27 = - V_66 ;
goto free;
}
V_38 = F_30 ( T_3 , V_38 , V_26 -> V_50 - * V_39 ) ;
if ( F_31 ( V_37 , V_26 -> V_64 . V_67 + * V_39 , V_38 ) ) {
V_27 = - V_68 ;
goto free;
}
V_27 = V_38 ;
* V_39 += V_38 ;
if ( ( unsigned long ) * V_39 < V_26 -> V_50 )
goto V_15;
free:
V_40 = F_20 ( V_9 ) ;
if ( V_40 )
F_21 ( & V_40 -> V_36 ) ;
F_22 ( V_26 ) ;
V_9 -> V_54 = V_69 ;
V_9 -> V_35 = NULL ;
V_15:
F_6 ( & V_11 -> V_7 -> V_11 , L_8 , V_27 ) ;
F_10 ( & V_11 -> V_16 ) ;
return V_27 ;
}
static T_1 F_32 ( struct V_2 * V_2 , const char T_2 * V_37 ,
T_3 V_38 , T_4 * V_39 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_25 * V_70 = NULL ;
struct V_10 * V_11 ;
unsigned long V_71 = 0 ;
int V_27 ;
int V_72 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_15;
}
V_72 = F_33 ( V_11 , V_9 -> V_33 ) ;
if ( V_72 < 0 ) {
V_27 = - V_13 ;
goto V_15;
}
if ( V_38 > V_11 -> V_47 [ V_72 ] . V_73 . V_74 || V_38 <= 0 ) {
V_27 = - V_66 ;
goto V_15;
}
if ( V_9 -> V_29 != V_30 ) {
F_8 ( & V_11 -> V_7 -> V_11 , L_9 ,
V_9 -> V_32 , V_9 -> V_33 ) ;
V_27 = - V_13 ;
goto V_15;
}
if ( V_9 == & V_11 -> V_28 ) {
V_70 = F_34 ( V_11 , V_2 ) ;
if ( V_70 ) {
V_71 = V_70 -> V_75 +
F_35 ( V_76 ) ;
if ( F_36 ( V_77 , V_71 ) ||
V_9 -> V_54 == V_53 ) {
* V_39 = 0 ;
F_21 ( & V_70 -> V_36 ) ;
F_22 ( V_70 ) ;
V_70 = NULL ;
}
}
}
if ( V_9 -> V_54 == V_53 ) {
* V_39 = 0 ;
V_70 = F_20 ( V_9 ) ;
if ( V_70 ) {
F_21 ( & V_70 -> V_36 ) ;
F_22 ( V_70 ) ;
V_70 = NULL ;
V_9 -> V_54 = V_69 ;
V_9 -> V_35 = NULL ;
}
} else if ( V_9 -> V_54 == V_69 )
* V_39 = 0 ;
V_70 = F_37 ( V_9 , V_2 ) ;
if ( ! V_70 ) {
F_8 ( & V_11 -> V_7 -> V_11 , L_10 ) ;
V_27 = - V_17 ;
goto V_15;
}
V_27 = F_38 ( V_70 , V_38 ) ;
if ( V_27 )
goto V_15;
V_27 = F_39 ( V_70 -> V_78 . V_67 , V_37 , V_38 ) ;
if ( V_27 )
goto V_15;
V_9 -> V_42 = 0 ;
if ( V_38 == 4 &&
( ( memcmp ( V_79 [ 0 ] ,
V_70 -> V_78 . V_67 , 4 ) == 0 ) ||
( memcmp ( V_79 [ 1 ] ,
V_70 -> V_78 . V_67 , 4 ) == 0 ) ||
( memcmp ( V_79 [ 2 ] ,
V_70 -> V_78 . V_67 , 4 ) == 0 ) ) )
V_9 -> V_42 |= V_43 ;
if ( V_9 == & V_11 -> V_28 ) {
V_27 = F_40 ( V_11 , V_70 ) ;
if ( V_27 ) {
F_8 ( & V_11 -> V_7 -> V_11 ,
L_11 , V_27 ) ;
goto V_15;
}
F_10 ( & V_11 -> V_16 ) ;
return V_38 ;
}
V_27 = F_41 ( V_9 , V_70 , false ) ;
V_15:
F_10 ( & V_11 -> V_16 ) ;
if ( V_27 < 0 )
F_22 ( V_70 ) ;
return V_27 ;
}
static int F_42 ( struct V_2 * V_2 ,
struct V_80 * V_67 )
{
struct V_10 * V_11 ;
struct V_81 * V_82 ;
struct V_8 * V_9 ;
int V_41 ;
int V_27 ;
V_9 = V_2 -> V_5 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_83;
}
if ( V_9 -> V_29 != V_59 &&
V_9 -> V_29 != V_60 ) {
V_27 = - V_52 ;
goto V_83;
}
V_41 = F_24 ( V_11 , & V_67 -> V_84 ) ;
if ( V_41 < 0 || V_11 -> V_47 [ V_41 ] . V_73 . V_85 ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_12 ,
& V_67 -> V_84 ) ;
V_27 = - V_13 ;
goto V_83;
}
V_9 -> V_33 = V_11 -> V_47 [ V_41 ] . V_48 ;
V_9 -> V_29 = V_86 ;
F_6 ( & V_11 -> V_7 -> V_11 , L_13 ,
V_9 -> V_33 ) ;
F_6 ( & V_11 -> V_7 -> V_11 , L_14 ,
V_11 -> V_47 [ V_41 ] . V_73 . V_87 ) ;
F_6 ( & V_11 -> V_7 -> V_11 , L_15 ,
V_11 -> V_47 [ V_41 ] . V_73 . V_74 ) ;
if ( F_43 ( V_67 -> V_84 , V_88 ) == 0 ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_16 ) ;
if ( V_11 -> V_28 . V_29 != V_30 ) {
V_27 = - V_13 ;
goto V_83;
}
F_18 ( V_9 -> V_32 , V_11 -> V_34 ) ;
F_19 ( V_9 ) ;
F_12 ( V_9 ) ;
V_9 = NULL ;
V_2 -> V_5 = & V_11 -> V_28 ;
V_82 = & V_67 -> V_89 ;
V_82 -> V_74 =
V_11 -> V_47 [ V_41 ] . V_73 . V_74 ;
V_82 -> V_87 =
V_11 -> V_47 [ V_41 ] . V_73 . V_87 ;
V_27 = V_11 -> V_28 . V_90 ;
goto V_83;
}
V_82 = & V_67 -> V_89 ;
V_82 -> V_74 = V_11 -> V_47 [ V_41 ] . V_73 . V_74 ;
V_82 -> V_87 = V_11 -> V_47 [ V_41 ] . V_73 . V_87 ;
F_6 ( & V_11 -> V_7 -> V_11 , L_17 ) ;
V_27 = F_44 ( V_9 , V_2 ) ;
V_83:
return V_27 ;
}
static long F_45 ( struct V_2 * V_2 , unsigned int V_91 , unsigned long V_67 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_80 * V_92 = NULL ;
int V_27 ;
if ( V_91 != V_93 )
return - V_94 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return - V_13 ;
V_11 = V_9 -> V_11 ;
F_6 ( & V_11 -> V_7 -> V_11 , L_18 , V_91 ) ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 ) {
V_27 = - V_13 ;
goto V_15;
}
F_6 ( & V_11 -> V_7 -> V_11 , L_19 ) ;
V_92 = F_46 ( sizeof( struct V_80 ) ,
V_95 ) ;
if ( ! V_92 ) {
V_27 = - V_17 ;
goto V_15;
}
F_6 ( & V_11 -> V_7 -> V_11 , L_20 ) ;
if ( F_39 ( V_92 , ( char T_2 * ) V_67 ,
sizeof( struct V_80 ) ) ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_21 ) ;
V_27 = - V_68 ;
goto V_15;
}
V_27 = F_42 ( V_2 , V_92 ) ;
if ( V_27 )
goto V_15;
F_6 ( & V_11 -> V_7 -> V_11 , L_22 ) ;
if ( F_31 ( ( char T_2 * ) V_67 , V_92 ,
sizeof( struct V_80 ) ) ) {
F_6 ( & V_11 -> V_7 -> V_11 , L_23 ) ;
V_27 = - V_68 ;
goto V_15;
}
V_15:
F_12 ( V_92 ) ;
F_10 ( & V_11 -> V_16 ) ;
return V_27 ;
}
static long F_47 ( struct V_2 * V_2 ,
unsigned int V_91 , unsigned long V_67 )
{
return F_45 ( V_2 , V_91 , ( unsigned long ) F_48 ( V_67 ) ) ;
}
static unsigned int F_49 ( struct V_2 * V_2 , T_5 * V_96 )
{
struct V_8 * V_9 = V_2 -> V_5 ;
struct V_10 * V_11 ;
unsigned int V_97 = 0 ;
if ( F_14 ( ! V_9 || ! V_9 -> V_11 ) )
return V_97 ;
V_11 = V_9 -> V_11 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_19 != V_20 )
goto V_15;
if ( V_9 == & V_11 -> V_28 ) {
V_97 = F_50 ( V_11 , V_2 , V_96 ) ;
goto V_15;
}
F_10 ( & V_11 -> V_16 ) ;
F_51 ( V_2 , & V_9 -> V_98 , V_96 ) ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_99 == V_9 -> V_100 )
V_97 |= ( V_101 | V_102 ) ;
V_15:
F_10 ( & V_11 -> V_16 ) ;
return V_97 ;
}
int F_52 ( struct V_10 * V_11 )
{
int V_103 ;
V_104 . V_14 = & V_11 -> V_7 -> V_11 ;
V_103 = F_53 ( & V_104 ) ;
if ( V_103 )
return V_103 ;
if ( F_54 ( V_11 , V_104 . V_105 ) )
F_8 ( & V_11 -> V_7 -> V_11 , L_24 ) ;
return 0 ;
}
void F_55 ( struct V_10 * V_11 )
{
F_56 ( V_11 ) ;
F_57 ( & V_104 ) ;
V_104 . V_14 = NULL ;
}
static int T_6 F_58 ( void )
{
return F_59 () ;
}
static void T_7 F_60 ( void )
{
F_61 () ;
}
