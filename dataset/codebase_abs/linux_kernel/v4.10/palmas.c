int F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 , int V_4 , bool V_5 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
int V_8 = 0 ;
int V_9 = 0 ;
int V_10 , V_11 ;
if ( ! ( V_4 & V_12 ) )
return 0 ;
if ( V_3 >= V_13 )
return 0 ;
if ( V_4 & V_14 ) {
V_9 = V_15 ;
V_8 = 0 ;
} else if ( V_4 & V_16 ) {
V_9 = V_17 ;
V_8 = 1 ;
} else if ( V_4 & V_18 ) {
V_9 = V_19 ;
V_8 = 2 ;
}
V_10 = V_7 -> V_20 [ V_3 ] . V_10 ;
V_9 += V_7 -> V_20 [ V_3 ] . V_21 ;
if ( V_5 )
V_11 = F_2 ( V_1 , V_22 ,
V_9 , F_3 ( V_10 ) , F_3 ( V_10 ) ) ;
else
V_11 = F_2 ( V_1 , V_22 ,
V_9 , F_3 ( V_10 ) , 0 ) ;
if ( V_11 < 0 ) {
F_4 ( V_1 -> V_23 , L_1 ,
V_9 , V_11 ) ;
return V_11 ;
}
V_11 = F_2 ( V_1 , V_24 ,
V_25 , F_3 ( V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_4 ( V_1 -> V_23 , L_2 ,
V_11 ) ;
return V_11 ;
}
return V_11 ;
}
static int F_5 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_30 = F_6 ( V_27 -> V_31 ) ;
if ( ! V_30 ) {
F_4 ( & V_27 -> V_23 , L_3 , V_27 -> V_31 ) ;
return - V_32 ;
}
V_29 -> V_33 = F_7 ( V_30 ) ;
F_8 ( & V_27 -> V_23 , L_4 , V_29 -> V_33 ) ;
return 0 ;
}
static void F_9 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_34 * V_35 = V_27 -> V_23 . V_36 ;
int V_11 ;
T_1 V_37 ;
V_11 = F_10 ( V_35 , L_5 , & V_37 ) ;
if ( ! V_11 ) {
V_29 -> V_38 = 1 ;
V_29 -> V_39 = V_37 ;
}
V_11 = F_10 ( V_35 , L_6 , & V_37 ) ;
if ( ! V_11 ) {
V_29 -> V_38 = 1 ;
V_29 -> V_40 = V_37 ;
}
V_11 = F_10 ( V_35 , L_7 , & V_37 ) ;
if ( ! V_11 )
V_29 -> V_41 = V_37 ;
else
V_29 -> V_41 = V_42 |
V_43 |
V_44 ;
if ( V_27 -> V_31 )
F_5 ( V_27 , V_29 ) ;
V_29 -> V_45 = F_11 ( V_35 ,
L_8 ) ;
}
static void F_12 ( void )
{
unsigned int V_46 ;
int V_11 , V_47 ;
V_47 = F_13 ( V_24 ) ;
V_46 = F_14 ( V_24 , V_48 ) ;
V_11 = F_15 (
V_49 -> V_50 [ V_47 ] ,
V_46 ,
V_51 ,
0 ) ;
if ( V_11 )
F_16 ( L_9 ,
V_52 , V_11 ) ;
}
static int F_17 ( struct V_26 * V_27 ,
const struct V_53 * V_3 )
{
struct V_1 * V_1 ;
struct V_28 * V_29 ;
struct V_54 * V_55 ;
struct V_34 * V_35 = V_27 -> V_23 . V_36 ;
int V_11 = 0 , V_56 ;
unsigned int V_57 , V_46 ;
int V_47 ;
const struct V_58 * V_59 ;
V_29 = F_18 ( & V_27 -> V_23 ) ;
if ( V_35 && ! V_29 ) {
V_29 = F_19 ( & V_27 -> V_23 , sizeof( * V_29 ) , V_60 ) ;
if ( ! V_29 )
return - V_61 ;
F_9 ( V_27 , V_29 ) ;
}
if ( ! V_29 )
return - V_32 ;
V_1 = F_19 ( & V_27 -> V_23 , sizeof( struct V_1 ) , V_60 ) ;
if ( V_1 == NULL )
return - V_61 ;
F_20 ( V_27 , V_1 ) ;
V_1 -> V_23 = & V_27 -> V_23 ;
V_1 -> V_31 = V_27 -> V_31 ;
V_59 = F_21 ( V_62 , & V_27 -> V_23 ) ;
if ( ! V_59 )
return - V_63 ;
V_55 = (struct V_54 * ) V_59 -> V_64 ;
V_1 -> V_65 = * V_55 -> V_65 ;
for ( V_56 = 0 ; V_56 < V_66 ; V_56 ++ ) {
if ( V_56 == 0 )
V_1 -> V_67 [ V_56 ] = V_27 ;
else {
V_1 -> V_67 [ V_56 ] =
F_22 ( V_27 -> V_68 ,
V_27 -> V_46 + V_56 ) ;
if ( ! V_1 -> V_67 [ V_56 ] ) {
F_4 ( V_1 -> V_23 ,
L_10 , V_56 ) ;
V_11 = - V_61 ;
goto V_69;
}
V_1 -> V_67 [ V_56 ] -> V_23 . V_36 = F_23 ( V_35 ) ;
}
V_1 -> V_50 [ V_56 ] = F_24 ( V_1 -> V_67 [ V_56 ] ,
& V_70 [ V_56 ] ) ;
if ( F_25 ( V_1 -> V_50 [ V_56 ] ) ) {
V_11 = F_26 ( V_1 -> V_50 [ V_56 ] ) ;
F_4 ( V_1 -> V_23 ,
L_11 ,
V_56 , V_11 ) ;
goto V_69;
}
}
if ( ! V_1 -> V_31 ) {
F_27 ( V_1 -> V_23 , L_12 ) ;
goto V_71;
}
if ( V_29 -> V_33 & V_72 )
V_57 = V_73 ;
else
V_57 = 0 ;
V_11 = F_2 ( V_1 , V_74 ,
V_75 , V_73 ,
V_57 ) ;
if ( V_11 < 0 ) {
F_4 ( V_1 -> V_23 , L_13 , V_11 ) ;
goto V_69;
}
V_47 = F_13 ( V_76 ) ;
V_46 = F_14 ( V_76 , V_77 ) ;
V_57 = V_78 ;
F_28 ( V_1 -> V_50 [ V_47 ] , V_46 , V_57 ) ;
V_11 = F_29 ( V_1 -> V_50 [ V_47 ] , V_1 -> V_31 ,
V_79 | V_29 -> V_33 , 0 ,
V_55 -> V_80 , & V_1 -> V_30 ) ;
if ( V_11 < 0 )
goto V_69;
V_71:
V_47 = F_13 ( V_74 ) ;
V_46 = F_14 ( V_74 ,
V_81 ) ;
if ( V_29 -> V_38 ) {
V_57 = V_29 -> V_39 ;
V_11 = F_28 ( V_1 -> V_50 [ V_47 ] , V_46 , V_57 ) ;
if ( V_11 )
goto V_82;
} else {
V_11 = F_30 ( V_1 -> V_50 [ V_47 ] , V_46 , & V_57 ) ;
if ( V_11 )
goto V_82;
}
if ( ! ( V_57 & V_83 ) )
V_1 -> V_84 |= V_85 ;
if ( ! ( V_57 & V_86 ) )
V_1 -> V_84 |= V_87 ;
else if ( ( V_57 & V_86 ) ==
( 2 << V_88 ) )
V_1 -> V_89 |= V_90 ;
else if ( ( V_57 & V_86 ) ==
( 3 << V_88 ) )
V_1 -> V_91 |= V_92 ;
if ( ! ( V_57 & V_93 ) )
V_1 -> V_84 |= V_94 ;
else if ( ( V_57 & V_93 ) ==
( 2 << V_95 ) )
V_1 -> V_89 |= V_96 ;
else if ( ( V_57 & V_93 ) ==
( 3 << V_95 ) )
V_1 -> V_91 |= V_97 ;
if ( ! ( V_57 & V_98 ) )
V_1 -> V_84 |= V_99 ;
V_46 = F_14 ( V_74 ,
V_100 ) ;
if ( V_29 -> V_38 ) {
V_57 = V_29 -> V_40 ;
V_11 = F_28 ( V_1 -> V_50 [ V_47 ] , V_46 , V_57 ) ;
if ( V_11 )
goto V_82;
} else {
V_11 = F_30 ( V_1 -> V_50 [ V_47 ] , V_46 , & V_57 ) ;
if ( V_11 )
goto V_82;
}
if ( ! ( V_57 & V_101 ) )
V_1 -> V_84 |= V_102 ;
if ( ! ( V_57 & V_103 ) )
V_1 -> V_84 |= V_104 ;
if ( ! ( V_57 & V_105 ) )
V_1 -> V_84 |= V_106 ;
if ( ! ( V_57 & V_107 ) )
V_1 -> V_84 |= V_108 ;
F_8 ( V_1 -> V_23 , L_14 ,
V_1 -> V_84 , V_1 -> V_91 ,
V_1 -> V_89 ) ;
V_57 = V_29 -> V_41 ;
V_47 = F_13 ( V_24 ) ;
V_46 = F_14 ( V_24 , V_25 ) ;
V_11 = F_28 ( V_1 -> V_50 [ V_47 ] , V_46 , V_57 ) ;
if ( V_11 )
goto V_82;
if ( V_35 ) {
V_11 = F_31 ( V_35 , NULL , NULL , & V_27 -> V_23 ) ;
if ( V_11 < 0 ) {
goto V_82;
} else if ( V_29 -> V_45 && ! V_109 ) {
V_49 = V_1 ;
V_109 = F_12 ;
}
}
return V_11 ;
V_82:
F_32 ( V_1 -> V_31 , V_1 -> V_30 ) ;
V_69:
for ( V_56 = 1 ; V_56 < V_66 ; V_56 ++ ) {
if ( V_1 -> V_67 [ V_56 ] )
F_33 ( V_1 -> V_67 [ V_56 ] ) ;
}
return V_11 ;
}
static int F_34 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_35 ( V_27 ) ;
int V_56 ;
F_32 ( V_1 -> V_31 , V_1 -> V_30 ) ;
for ( V_56 = 1 ; V_56 < V_66 ; V_56 ++ ) {
if ( V_1 -> V_67 [ V_56 ] )
F_33 ( V_1 -> V_67 [ V_56 ] ) ;
}
if ( V_1 == V_49 ) {
V_109 = NULL ;
V_49 = NULL ;
}
return 0 ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_110 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_110 ) ;
}
