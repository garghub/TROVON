static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( F_3 ( V_4 ) )
F_4 ( V_4 , V_4 -> V_6 ) ;
else
F_5 ( V_4 , V_4 -> V_6 ) ;
}
int F_6 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_7 ) {
snprintf ( V_4 -> V_8 , sizeof( V_4 -> V_8 ) ,
L_1 , V_4 -> V_9 ) ;
V_4 -> V_7 =
F_7 ( V_4 -> V_8 , 0 ) ;
if ( ! V_4 -> V_7 )
return - V_10 ;
F_8 ( & V_4 -> V_5 , F_1 ) ;
}
return 0 ;
}
void F_9 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 ) {
F_10 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
}
T_1 F_11 ( int V_11 , void * V_12 )
{
struct V_3 * V_4 = V_12 ;
struct V_13 * V_14 = V_4 -> V_14 ;
V_14 -> V_15 -> V_16 ( V_14 , V_4 -> V_17 ) ;
F_12 ( V_4 -> V_7 , & V_4 -> V_5 ) ;
return V_18 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_19 . V_2 ) ;
struct V_13 * V_14 = V_4 -> V_14 ;
T_2 V_20 = 0 ;
int V_21 ;
if ( F_14 () ) {
struct V_22 * V_23 = V_14 -> V_24 ;
V_20 = V_23 -> V_25 ;
V_4 -> V_26 = V_23 -> V_27 ;
} else {
struct V_22 T_3 * V_23 = V_14 -> V_28 ;
V_20 = F_15 ( & V_23 -> V_29 ) ;
V_4 -> V_26 = F_16 ( & V_23 -> V_30 ) ;
}
if ( V_20 ) {
V_21 = F_17 ( V_20 , V_4 ) ;
if ( V_21 )
F_18 ( & V_4 -> V_14 -> V_31 ,
L_2 , V_21 ) ;
} else {
F_19 ( & V_4 -> V_19 ,
F_20 ( 1000 ) ) ;
}
}
static int F_21 ( void )
{
#define F_22 129
int V_32 ;
T_4 V_33 = F_22 ;
V_3 = F_23 ( V_33 , sizeof( * V_3 ) , V_34 ) ;
if ( ! V_3 )
return - V_10 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
struct V_3 * V_4 = & V_3 [ V_32 ] ;
V_4 -> V_9 = V_32 ;
V_4 -> exit = V_35 ;
F_24 ( & V_4 -> V_36 ) ;
F_25 ( & V_4 -> V_37 ) ;
F_8 ( & V_4 -> V_38 , V_39 ) ;
F_26 ( & V_4 -> V_40 ,
V_41 ) ;
F_26 ( & V_4 -> V_19 ,
F_13 ) ;
F_27 ( & V_4 -> V_42 ) ;
F_28 ( V_4 -> V_43 , NULL ) ;
}
return 0 ;
}
static void F_29 ( void )
{
F_30 ( V_3 ) ;
}
static int F_31 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = & V_3 [ V_14 -> V_44 ] ;
int V_45 ;
F_32 ( & V_14 -> V_31 , V_14 ) ;
V_4 -> V_14 = V_14 ;
if ( 1 == F_33 ( 1 , & V_46 ) ) {
struct V_3 * V_47 = & V_3 [ V_14 -> V_48 ] ;
V_47 -> V_14 = V_14 ;
V_45 = F_34 ( V_47 ) ;
if ( V_45 )
goto exit;
}
V_45 = F_6 ( V_4 ) ;
if ( V_45 )
goto V_49;
V_45 = F_35 ( V_4 ) ;
if ( V_45 )
goto V_50;
V_4 -> V_17 = V_14 -> V_15 -> V_51 ( V_14 ) ;
V_4 -> V_52 = V_14 -> V_15 -> V_53 ( V_14 , F_11 ,
L_3 , V_4 ,
V_4 -> V_17 ) ;
if ( F_36 ( V_4 -> V_52 ) ) {
V_45 = F_37 ( V_4 -> V_52 ) ;
goto V_54;
}
if ( F_14 () ) {
struct V_22 * V_23 = V_14 -> V_24 ;
V_23 -> V_30 = V_4 -> V_17 ;
V_23 -> V_29 = V_4 -> V_55 ;
} else {
struct V_22 T_3 * V_23 = V_14 -> V_28 ;
F_38 ( V_4 -> V_17 , & V_23 -> V_27 ) ;
F_39 ( V_4 -> V_55 , & V_23 -> V_25 ) ;
}
F_19 ( & V_4 -> V_19 ,
F_20 ( 1000 ) ) ;
return V_45 ;
V_54:
F_40 ( V_4 ) ;
V_50:
F_9 ( V_4 ) ;
V_49:
if ( F_41 ( & V_46 ) )
F_42 ( & V_3 [ V_14 -> V_48 ] ) ;
exit:
return V_45 ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_3 * V_31 ;
int V_32 ;
for ( V_32 = V_56 . V_57 ; V_32 >= 0 ; V_32 -- ) {
V_31 = & V_3 [ V_32 ] ;
if ( F_3 ( V_31 ) )
continue;
F_44 ( V_32 ) ;
}
}
static void F_45 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = & V_3 [ V_14 -> V_44 ] ;
if ( F_14 () ) {
struct V_22 * V_23 = V_14 -> V_24 ;
V_23 -> V_30 = - 1 ;
V_23 -> V_29 = 0x0 ;
} else {
struct V_22 T_3 * V_23 = V_14 -> V_28 ;
F_38 ( - 1 , & V_23 -> V_27 ) ;
F_39 ( 0x0 , & V_23 -> V_25 ) ;
}
if ( F_14 () ) {
F_46 ( V_4 -> V_9 , true ) ;
} else {
V_56 . V_58 = true ;
F_43 ( V_4 ) ;
}
if ( F_41 ( & V_46 ) )
F_42 ( & V_3 [ V_14 -> V_48 ] ) ;
if ( V_4 -> V_52 ) {
V_14 -> V_15 -> V_59 ( V_14 , V_4 -> V_52 , V_4 ) ;
V_4 -> V_52 = NULL ;
}
F_9 ( V_4 ) ;
F_47 ( & V_4 -> V_19 ) ;
F_40 ( V_4 ) ;
V_4 -> V_26 = - 1 ;
V_4 -> V_14 = NULL ;
}
static int F_48 ( void )
{
int V_45 ;
F_25 ( & V_56 . V_60 ) ;
F_49 ( & V_56 . V_61 ) ;
F_49 ( & V_56 . V_62 ) ;
F_49 ( & V_56 . V_63 ) ;
F_25 ( & V_56 . V_64 ) ;
F_25 ( & V_56 . V_65 ) ;
F_25 ( & V_56 . V_66 ) ;
F_27 ( & V_56 . V_67 ) ;
F_27 ( & V_56 . V_68 ) ;
F_27 ( & V_56 . V_69 ) ;
F_27 ( & V_56 . V_70 ) ;
F_27 ( & V_56 . V_71 ) ;
F_27 ( & V_56 . V_72 ) ;
F_27 ( & V_56 . V_73 ) ;
F_27 ( & V_56 . V_74 ) ;
F_27 ( & V_56 . V_75 ) ;
F_27 ( & V_56 . V_76 ) ;
F_24 ( & V_56 . V_77 ) ;
V_56 . V_78 = V_79 ;
V_56 . V_80 = 0 ;
V_56 . V_81 = 1 ;
V_45 = F_21 () ;
if ( V_45 )
goto error;
V_82 = F_50 ( L_4 ,
V_83 ,
0 , V_84 , NULL ) ;
if ( ! V_82 ) {
V_45 = - V_10 ;
goto V_85;
}
F_8 ( & V_56 . V_86 , V_87 ) ;
F_8 ( & V_56 . V_88 , V_89 ) ;
F_8 ( & V_56 . V_90 , V_91 ) ;
F_51 ( & V_92 ) ;
return 0 ;
V_85:
F_29 () ;
error:
return V_45 ;
}
static void F_52 ( void )
{
F_53 ( & V_92 ) ;
F_54 ( V_82 ) ;
F_29 () ;
}
static int T_5 F_55 ( void )
{
struct V_93 * V_94 = & V_56 . V_94 ;
int V_45 ;
F_48 () ;
F_56 () ;
V_45 = F_57 () ;
if ( V_45 )
goto exit;
V_45 = F_58 ( & V_95 ) ;
if ( V_45 )
goto V_96;
V_45 = F_59 ( V_94 ) ;
if ( V_45 )
goto V_97;
F_60 () ;
return 0 ;
V_97:
F_61 ( & V_95 ) ;
V_96:
F_62 () ;
exit:
F_52 () ;
return V_45 ;
}
static void T_6 F_63 ( void )
{
F_64 () ;
F_65 ( & V_56 . V_94 ) ;
F_61 ( & V_95 ) ;
F_62 () ;
F_66 () ;
F_52 () ;
}
