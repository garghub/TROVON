static inline T_1 F_1 ( const char * V_1 , int V_2 )
{
return F_2 ( ( V_3 * ) & V_1 [ V_2 ] ) ;
}
static int F_3 ( struct V_4 * V_1 )
{
int V_5 ;
V_5 = F_4 ( & V_1 -> V_6 , sizeof( V_1 -> V_6 ) ) ;
if ( V_5 )
goto V_7;
V_1 -> V_8 ++ ;
V_5 = F_5 ( V_1 -> V_9 , & V_1 -> V_6 , V_1 -> V_8 ,
& V_1 -> V_10 , V_1 , 0 , 0 , 0 ) ;
if ( V_5 )
goto V_11;
return 0 ;
V_11:
F_6 ( V_1 -> V_12 , L_1 , V_5 ) ;
return V_5 ;
V_7:
F_6 ( V_1 -> V_12 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_7 ( struct V_4 * V_1 )
{
V_1 -> V_13 [ 0 ] = V_14 ;
V_1 -> V_10 . V_15 = 1 ;
F_3 ( V_1 ) ;
F_8 ( & V_1 -> V_16 ) ;
if ( V_1 -> V_17 || V_1 -> V_18 != 6 )
return - V_19 ;
V_1 -> V_20 = V_1 -> V_21 [ 0 ] ;
V_1 -> V_22 = V_1 -> V_21 [ 1 ] ;
F_9 ( V_1 -> V_12 ,
L_3 ,
V_1 -> V_20 ,
V_1 -> V_22 ,
F_1 ( V_1 -> V_21 , 2 ) ,
V_1 -> V_21 [ 4 ] ,
V_1 -> V_21 [ 5 ] ,
V_1 -> V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_1 )
{
V_1 -> V_13 [ 0 ] = V_24 ;
V_1 -> V_10 . V_15 = 1 ;
F_3 ( V_1 ) ;
F_8 ( & V_1 -> V_16 ) ;
if ( V_1 -> V_17 || V_1 -> V_18 != 1 )
return - V_19 ;
return V_1 -> V_21 [ 0 ] ;
}
static int F_11 ( struct V_4 * V_1 , int V_25 )
{
V_1 -> V_13 [ 0 ] = V_26 ;
V_1 -> V_13 [ 1 ] = V_25 ;
V_1 -> V_10 . V_15 = 2 ;
F_3 ( V_1 ) ;
F_8 ( & V_1 -> V_16 ) ;
if ( V_1 -> V_17 || V_1 -> V_18 < 1 )
return - V_19 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_1 , int V_25 )
{
V_1 -> V_13 [ 0 ] = V_27 ;
V_1 -> V_13 [ 1 ] = V_25 ;
V_1 -> V_10 . V_15 = 2 ;
F_3 ( V_1 ) ;
F_8 ( & V_1 -> V_16 ) ;
if ( V_1 -> V_17 || V_1 -> V_18 < 26 ) {
F_6 ( V_1 -> V_12 , L_4 ,
V_25 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_1 )
{
V_1 -> V_13 [ 0 ] = V_28 ;
V_1 -> V_10 . V_15 = 1 ;
F_3 ( V_1 ) ;
F_8 ( & V_1 -> V_16 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_1 )
{
int V_29 , V_5 ;
F_15 ( & V_1 -> V_30 ) ;
if ( F_16 ( V_31 , V_1 -> V_32 + V_33 ) &&
V_1 -> V_34 )
goto V_7;
for ( V_29 = 0 ; V_29 < V_1 -> V_35 ; V_29 ++ ) {
if ( ! V_1 -> V_36 [ V_29 ] . V_37 )
continue;
V_5 = F_12 ( V_1 , V_29 ) ;
if ( V_5 )
continue;
V_1 -> V_36 [ V_29 ] . V_38 [ 0 ] =
F_1 ( V_1 -> V_21 , 16 ) ;
V_1 -> V_36 [ V_29 ] . V_38 [ 1 ] =
F_1 ( V_1 -> V_21 , 18 ) ;
V_1 -> V_36 [ V_29 ] . V_38 [ 2 ] =
F_1 ( V_1 -> V_21 , 20 ) ;
}
V_1 -> V_32 = V_31 ;
V_1 -> V_34 = 1 ;
V_7:
F_17 ( & V_1 -> V_30 ) ;
}
static struct V_4 * F_18 ( int V_39 )
{
struct V_4 * V_40 , * V_41 ;
F_19 (p, next, &driver_data.bmc_data, list)
if ( V_40 -> V_23 == V_39 )
return V_40 ;
return NULL ;
}
static T_2 F_20 ( struct V_42 * V_43 , struct V_44 * V_45 ,
char * V_46 )
{
return sprintf ( V_46 , L_5 , V_47 ) ;
}
static T_2 F_21 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_48 * V_49 = F_22 ( V_45 ) ;
struct V_4 * V_1 = F_23 ( V_43 ) ;
int V_50 = V_1 -> V_36 [ V_49 -> V_51 ] . V_52 ;
F_14 ( V_1 ) ;
return sprintf ( V_46 , L_6 ,
V_1 -> V_36 [ V_49 -> V_51 ] . V_38 [ V_49 -> V_53 ] * V_50 ) ;
}
static T_2 F_24 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
const char * V_46 ,
T_3 V_54 )
{
struct V_4 * V_1 = F_23 ( V_43 ) ;
F_13 ( V_1 ) ;
return V_54 ;
}
static int F_25 ( const char * V_55 , int V_56 )
{
if ( V_56 < V_57 )
return 0 ;
if ( ! memcmp ( V_55 , V_58 , V_57 ) )
return 1 ;
return 0 ;
}
static int F_26 ( const char * V_55 , int V_56 )
{
if ( V_56 < V_57 )
return 0 ;
if ( ! memcmp ( V_55 , V_59 , V_57 ) )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_4 * V_1 ,
const char * V_55 , int V_56 )
{
int V_29 ;
if ( V_1 -> V_20 == 2 )
return 1000000 ;
for ( V_29 = V_57 ; V_29 < V_56 - 1 ; V_29 ++ )
if ( ! memcmp ( & V_55 [ V_29 ] , V_60 , V_61 ) )
return 1000000 ;
return 100000 ;
}
static int F_28 ( struct V_4 * V_1 , int type ,
int V_62 , int V_25 , int V_63 )
{
int V_5 ;
char * V_64 ;
V_64 = F_29 ( 32 , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
if ( type == V_67 )
sprintf ( V_64 , V_68 [ V_63 ] , L_7 , V_62 ) ;
else if ( type == V_69 )
sprintf ( V_64 , V_70 [ V_63 ] , L_8 , V_62 ) ;
F_30 ( & V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_71 . V_49 ) ;
V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_71 . V_49 . V_72 = V_64 ;
V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_71 . V_49 . V_73 = V_74 ;
V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_71 . V_75 = F_21 ;
V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_51 = V_25 ;
V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_53 = V_63 ;
V_5 = F_31 ( V_1 -> V_12 ,
& V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_71 ) ;
if ( V_5 ) {
V_1 -> V_36 [ V_25 ] . V_49 [ V_63 ] . V_71 . V_49 . V_72 = NULL ;
F_32 ( V_64 ) ;
return V_5 ;
}
return 0 ;
}
static int F_33 ( struct V_4 * V_1 )
{
int V_29 , V_76 , V_5 ;
int V_77 ;
int V_78 ;
int V_79 = 0 ;
int V_80 = 0 ;
V_5 = F_10 ( V_1 ) ;
if ( V_5 <= 0 )
return - V_19 ;
V_1 -> V_35 = V_5 ;
V_1 -> V_36 = F_34 ( V_1 -> V_35 * sizeof( * V_1 -> V_36 ) ,
V_65 ) ;
if ( ! V_1 -> V_36 )
return - V_66 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_35 ; V_29 ++ ) {
V_5 = F_11 ( V_1 , V_29 ) ;
if ( V_5 )
continue;
if ( F_25 ( V_1 -> V_21 , V_1 -> V_18 ) ) {
V_77 = V_69 ;
V_79 ++ ;
V_78 = V_79 ;
V_1 -> V_36 [ V_29 ] . V_52 =
F_27 ( V_1 ,
V_1 -> V_21 ,
V_1 -> V_18 ) ;
} else if ( F_26 ( V_1 -> V_21 ,
V_1 -> V_18 ) ) {
V_77 = V_67 ;
V_80 ++ ;
V_78 = V_80 ;
V_1 -> V_36 [ V_29 ] . V_52 = 1000 ;
} else
continue;
V_1 -> V_36 [ V_29 ] . V_37 = 1 ;
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
V_5 = F_28 ( V_1 , V_77 , V_78 ,
V_29 , V_76 ) ;
if ( V_5 )
goto V_82;
}
}
V_5 = F_31 ( V_1 -> V_12 ,
& V_83 . V_71 ) ;
if ( V_5 )
goto V_82;
V_5 = F_31 ( V_1 -> V_12 ,
& V_84 . V_71 ) ;
if ( V_5 )
goto V_82;
return 0 ;
V_82:
F_35 ( V_1 -> V_12 ,
& V_83 . V_71 ) ;
F_35 ( V_1 -> V_12 , & V_84 . V_71 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_35 ; V_29 ++ )
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
if ( ! V_1 -> V_36 [ V_29 ] . V_49 [ V_76 ] . V_71 . V_49 . V_72 )
continue;
F_35 ( V_1 -> V_12 ,
& V_1 -> V_36 [ V_29 ] . V_49 [ V_76 ] . V_71 ) ;
F_32 ( V_1 -> V_36 [ V_29 ] . V_49 [ V_76 ] . V_71 . V_49 . V_72 ) ;
}
F_32 ( V_1 -> V_36 ) ;
return V_5 ;
}
static void F_36 ( int V_39 , struct V_42 * V_43 )
{
struct V_4 * V_1 ;
int V_5 ;
V_1 = F_34 ( sizeof( * V_1 ) , V_65 ) ;
if ( ! V_1 ) {
F_6 ( V_43 , L_9 ) ;
return;
}
V_1 -> V_6 . V_85 = V_86 ;
V_1 -> V_6 . V_87 = V_88 ;
V_1 -> V_6 . V_1 [ 0 ] = 0 ;
V_1 -> V_23 = V_39 ;
V_1 -> V_12 = V_43 ;
V_5 = F_37 ( V_1 -> V_23 , & V_89 . V_90 ,
V_1 , & V_1 -> V_9 ) ;
if ( V_5 < 0 ) {
F_6 ( V_43 ,
L_10 ,
V_1 -> V_23 ) ;
goto V_7;
}
F_38 ( & V_1 -> V_30 ) ;
V_1 -> V_8 = 0 ;
F_39 ( & V_1 -> V_16 ) ;
V_1 -> V_10 . V_91 = V_92 ;
V_1 -> V_10 . V_93 = V_94 ;
V_1 -> V_10 . V_1 = V_1 -> V_13 ;
V_5 = F_7 ( V_1 ) ;
if ( V_5 )
goto V_95;
V_1 -> V_96 = F_40 ( V_1 -> V_12 ) ;
if ( F_41 ( V_1 -> V_96 ) ) {
F_6 ( V_1 -> V_12 ,
L_11 ,
V_1 -> V_23 ) ;
goto V_95;
}
F_42 ( V_43 , V_1 ) ;
F_43 ( & V_1 -> V_97 , & V_89 . V_98 ) ;
V_5 = F_33 ( V_1 ) ;
if ( V_5 ) {
F_6 ( V_1 -> V_12 , L_12 , V_5 ) ;
goto V_99;
}
return;
V_99:
F_44 ( V_1 -> V_96 ) ;
V_95:
F_45 ( V_1 -> V_9 ) ;
V_7:
F_32 ( V_1 ) ;
}
static void F_46 ( struct V_4 * V_1 )
{
int V_29 , V_76 ;
F_35 ( V_1 -> V_12 ,
& V_83 . V_71 ) ;
F_35 ( V_1 -> V_12 , & V_84 . V_71 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_35 ; V_29 ++ )
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
if ( ! V_1 -> V_36 [ V_29 ] . V_49 [ V_76 ] . V_71 . V_49 . V_72 )
continue;
F_35 ( V_1 -> V_12 ,
& V_1 -> V_36 [ V_29 ] . V_49 [ V_76 ] . V_71 ) ;
F_32 ( V_1 -> V_36 [ V_29 ] . V_49 [ V_76 ] . V_71 . V_49 . V_72 ) ;
}
F_47 ( & V_1 -> V_97 ) ;
F_42 ( V_1 -> V_12 , NULL ) ;
F_44 ( V_1 -> V_96 ) ;
F_45 ( V_1 -> V_9 ) ;
F_32 ( V_1 -> V_36 ) ;
F_32 ( V_1 ) ;
}
static void F_48 ( int V_39 )
{
struct V_4 * V_1 = F_18 ( V_39 ) ;
if ( ! V_1 )
return;
F_46 ( V_1 ) ;
}
static void F_49 ( struct V_100 * V_101 , void * V_102 )
{
struct V_4 * V_1 = (struct V_4 * ) V_102 ;
if ( V_101 -> V_103 != V_1 -> V_8 ) {
F_6 ( V_1 -> V_12 ,
L_13 ,
( int ) V_101 -> V_103 ,
( int ) V_1 -> V_8 ) ;
F_50 ( V_101 ) ;
return;
}
V_1 -> V_104 = V_101 -> V_105 ;
if ( V_101 -> V_101 . V_15 > 0 )
V_1 -> V_17 = V_101 -> V_101 . V_1 [ 0 ] ;
else
V_1 -> V_17 = V_106 ;
if ( V_101 -> V_101 . V_15 > 1 ) {
V_1 -> V_18 = V_101 -> V_101 . V_15 - 1 ;
memcpy ( V_1 -> V_21 , V_101 -> V_101 . V_1 + 1 , V_1 -> V_18 ) ;
} else
V_1 -> V_18 = 0 ;
F_50 ( V_101 ) ;
F_51 ( & V_1 -> V_16 ) ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_89 . V_107 ) ;
}
static void T_5 F_54 ( void )
{
struct V_4 * V_40 , * V_41 ;
F_55 ( & V_89 . V_107 ) ;
F_19 (p, next, &driver_data.bmc_data, list)
F_46 ( V_40 ) ;
}
