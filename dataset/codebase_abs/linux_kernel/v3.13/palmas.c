int F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 , int V_4 , bool V_5 )
{
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 ;
int V_9 ;
if ( ! ( V_4 & V_10 ) )
return 0 ;
if ( V_3 >= V_11 )
return 0 ;
if ( V_4 & V_12 ) {
V_7 = V_13 ;
V_6 = 0 ;
} else if ( V_4 & V_14 ) {
V_7 = V_15 ;
V_6 = 1 ;
} else if ( V_4 & V_16 ) {
V_7 = V_17 ;
V_6 = 2 ;
}
V_8 = V_18 [ V_3 ] . V_8 ;
V_7 += V_18 [ V_3 ] . V_19 ;
if ( V_5 )
V_9 = F_2 ( V_1 , V_20 ,
V_7 , F_3 ( V_8 ) , F_3 ( V_8 ) ) ;
else
V_9 = F_2 ( V_1 , V_20 ,
V_7 , F_3 ( V_8 ) , 0 ) ;
if ( V_9 < 0 ) {
F_4 ( V_1 -> V_21 , L_1 ,
V_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_2 ( V_1 , V_22 ,
V_23 , F_3 ( V_6 ) , 0 ) ;
if ( V_9 < 0 ) {
F_4 ( V_1 -> V_21 , L_2 ,
V_9 ) ;
return V_9 ;
}
return V_9 ;
}
static int F_5 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_28 = F_6 ( V_25 -> V_29 ) ;
if ( ! V_28 ) {
F_4 ( & V_25 -> V_21 , L_3 , V_25 -> V_29 ) ;
return - V_30 ;
}
V_27 -> V_31 = F_7 ( V_28 ) ;
F_8 ( & V_25 -> V_21 , L_4 , V_27 -> V_31 ) ;
return 0 ;
}
static void F_9 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_32 * V_33 = V_25 -> V_21 . V_34 ;
int V_9 ;
T_1 V_35 ;
V_9 = F_10 ( V_33 , L_5 , & V_35 ) ;
if ( ! V_9 ) {
V_27 -> V_36 = 1 ;
V_27 -> V_37 = V_35 ;
}
V_9 = F_10 ( V_33 , L_6 , & V_35 ) ;
if ( ! V_9 ) {
V_27 -> V_36 = 1 ;
V_27 -> V_38 = V_35 ;
}
V_9 = F_10 ( V_33 , L_7 , & V_35 ) ;
if ( ! V_9 )
V_27 -> V_39 = V_35 ;
else
V_27 -> V_39 = V_40 |
V_41 |
V_42 ;
if ( V_25 -> V_29 )
F_5 ( V_25 , V_27 ) ;
V_27 -> V_43 = F_11 ( V_33 ,
L_8 ) ;
}
static void F_12 ( void )
{
unsigned int V_44 ;
int V_9 , V_45 ;
if ( ! V_46 )
return;
V_45 = F_13 ( V_22 ) ;
V_44 = F_14 ( V_22 , V_47 ) ;
V_9 = F_15 (
V_46 -> V_48 [ V_45 ] ,
V_44 ,
V_49 ,
0 ) ;
if ( V_9 )
F_16 ( L_9 ,
V_50 , V_9 ) ;
}
static int F_17 ( struct V_24 * V_25 ,
const struct V_51 * V_3 )
{
struct V_1 * V_1 ;
struct V_26 * V_27 ;
struct V_32 * V_33 = V_25 -> V_21 . V_34 ;
int V_9 = 0 , V_52 ;
unsigned int V_53 , V_44 , * V_54 ;
int V_45 ;
const struct V_55 * V_56 ;
V_27 = F_18 ( & V_25 -> V_21 ) ;
if ( V_33 && ! V_27 ) {
V_27 = F_19 ( & V_25 -> V_21 , sizeof( * V_27 ) , V_57 ) ;
if ( ! V_27 )
return - V_58 ;
F_9 ( V_25 , V_27 ) ;
}
if ( ! V_27 )
return - V_30 ;
V_1 = F_19 ( & V_25 -> V_21 , sizeof( struct V_1 ) , V_57 ) ;
if ( V_1 == NULL )
return - V_58 ;
F_20 ( V_25 , V_1 ) ;
V_1 -> V_21 = & V_25 -> V_21 ;
V_1 -> V_29 = V_25 -> V_29 ;
V_56 = F_21 ( V_59 , & V_25 -> V_21 ) ;
if ( ! V_56 )
return - V_60 ;
V_54 = ( unsigned int * ) V_56 -> V_61 ;
V_1 -> V_54 = * V_54 ;
for ( V_52 = 0 ; V_52 < V_62 ; V_52 ++ ) {
if ( V_52 == 0 )
V_1 -> V_63 [ V_52 ] = V_25 ;
else {
V_1 -> V_63 [ V_52 ] =
F_22 ( V_25 -> V_64 ,
V_25 -> V_44 + V_52 ) ;
if ( ! V_1 -> V_63 [ V_52 ] ) {
F_4 ( V_1 -> V_21 ,
L_10 , V_52 ) ;
V_9 = - V_58 ;
goto V_65;
}
V_1 -> V_63 [ V_52 ] -> V_21 . V_34 = F_23 ( V_33 ) ;
}
V_1 -> V_48 [ V_52 ] = F_24 ( V_1 -> V_63 [ V_52 ] ,
& V_66 [ V_52 ] ) ;
if ( F_25 ( V_1 -> V_48 [ V_52 ] ) ) {
V_9 = F_26 ( V_1 -> V_48 [ V_52 ] ) ;
F_4 ( V_1 -> V_21 ,
L_11 ,
V_52 , V_9 ) ;
goto V_65;
}
}
if ( ! V_1 -> V_29 ) {
F_27 ( V_1 -> V_21 , L_12 ) ;
goto V_67;
}
if ( V_27 -> V_31 & V_68 )
V_53 = V_69 ;
else
V_53 = 0 ;
V_9 = F_2 ( V_1 , V_70 ,
V_71 , V_69 ,
V_53 ) ;
if ( V_9 < 0 ) {
F_4 ( V_1 -> V_21 , L_13 , V_9 ) ;
goto V_65;
}
V_45 = F_13 ( V_72 ) ;
V_44 = F_14 ( V_72 , V_73 ) ;
V_53 = V_74 ;
F_28 ( V_1 -> V_48 [ V_45 ] , V_44 , V_53 ) ;
V_9 = F_29 ( V_1 -> V_48 [ V_45 ] , V_1 -> V_29 ,
V_75 | V_27 -> V_31 , 0 , & V_76 ,
& V_1 -> V_28 ) ;
if ( V_9 < 0 )
goto V_65;
V_67:
V_45 = F_13 ( V_70 ) ;
V_44 = F_14 ( V_70 ,
V_77 ) ;
if ( V_27 -> V_36 ) {
V_53 = V_27 -> V_37 ;
V_9 = F_28 ( V_1 -> V_48 [ V_45 ] , V_44 , V_53 ) ;
if ( V_9 )
goto V_78;
} else {
V_9 = F_30 ( V_1 -> V_48 [ V_45 ] , V_44 , & V_53 ) ;
if ( V_9 )
goto V_78;
}
if ( ! ( V_53 & V_79 ) )
V_1 -> V_80 |= V_81 ;
if ( ! ( V_53 & V_82 ) )
V_1 -> V_80 |= V_83 ;
else if ( ( V_53 & V_82 ) ==
( 2 << V_84 ) )
V_1 -> V_85 |= V_86 ;
else if ( ( V_53 & V_82 ) ==
( 3 << V_84 ) )
V_1 -> V_87 |= V_88 ;
if ( ! ( V_53 & V_89 ) )
V_1 -> V_80 |= V_90 ;
else if ( ( V_53 & V_89 ) ==
( 2 << V_91 ) )
V_1 -> V_85 |= V_92 ;
else if ( ( V_53 & V_89 ) ==
( 3 << V_91 ) )
V_1 -> V_87 |= V_93 ;
if ( ! ( V_53 & V_94 ) )
V_1 -> V_80 |= V_95 ;
V_44 = F_14 ( V_70 ,
V_96 ) ;
if ( V_27 -> V_36 ) {
V_53 = V_27 -> V_38 ;
V_9 = F_28 ( V_1 -> V_48 [ V_45 ] , V_44 , V_53 ) ;
if ( V_9 )
goto V_78;
} else {
V_9 = F_30 ( V_1 -> V_48 [ V_45 ] , V_44 , & V_53 ) ;
if ( V_9 )
goto V_78;
}
if ( ! ( V_53 & V_97 ) )
V_1 -> V_80 |= V_98 ;
if ( ! ( V_53 & V_99 ) )
V_1 -> V_80 |= V_100 ;
if ( ! ( V_53 & V_101 ) )
V_1 -> V_80 |= V_102 ;
if ( ! ( V_53 & V_103 ) )
V_1 -> V_80 |= V_104 ;
F_8 ( V_1 -> V_21 , L_14 ,
V_1 -> V_80 , V_1 -> V_87 ,
V_1 -> V_85 ) ;
V_53 = V_27 -> V_39 ;
V_45 = F_13 ( V_22 ) ;
V_44 = F_14 ( V_22 , V_23 ) ;
V_9 = F_28 ( V_1 -> V_48 [ V_45 ] , V_44 , V_53 ) ;
if ( V_9 )
goto V_78;
if ( V_33 ) {
V_9 = F_31 ( V_33 , NULL , NULL , & V_25 -> V_21 ) ;
if ( V_9 < 0 ) {
goto V_78;
} else if ( V_27 -> V_43 && ! V_105 ) {
V_46 = V_1 ;
V_105 = F_12 ;
}
}
return V_9 ;
V_78:
F_32 ( V_1 -> V_29 , V_1 -> V_28 ) ;
V_65:
for ( V_52 = 1 ; V_52 < V_62 ; V_52 ++ ) {
if ( V_1 -> V_63 [ V_52 ] )
F_33 ( V_1 -> V_63 [ V_52 ] ) ;
}
return V_9 ;
}
static int F_34 ( struct V_24 * V_25 )
{
struct V_1 * V_1 = F_35 ( V_25 ) ;
int V_52 ;
F_32 ( V_1 -> V_29 , V_1 -> V_28 ) ;
for ( V_52 = 1 ; V_52 < V_62 ; V_52 ++ ) {
if ( V_1 -> V_63 [ V_52 ] )
F_33 ( V_1 -> V_63 [ V_52 ] ) ;
}
if ( V_1 == V_46 ) {
V_105 = NULL ;
V_46 = NULL ;
}
return 0 ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_106 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_106 ) ;
}
