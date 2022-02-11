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
static int F_13 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = & V_3 [ V_20 -> V_21 ] ;
F_14 ( & V_22 . V_23 ) ;
V_22 . V_24 ++ ;
V_22 . V_25 = F_15 ( V_26 , V_20 -> V_21 , V_22 . V_25 ) ;
F_16 ( & V_22 . V_23 ) ;
F_17 ( V_4 -> V_20 , V_20 ) ;
return 0 ;
}
static void F_18 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = & V_3 [ V_20 -> V_21 ] ;
V_20 = F_19 ( V_4 -> V_20 ) ;
if ( V_20 )
F_20 ( V_4 -> V_20 , NULL ) ;
F_21 () ;
F_14 ( & V_22 . V_23 ) ;
V_22 . V_24 -- ;
F_16 ( & V_22 . V_23 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_27 . V_2 ) ;
struct V_13 * V_14 = V_4 -> V_14 ;
T_2 V_28 = 0 ;
int V_29 ;
if ( F_23 () ) {
struct V_30 * V_31 = V_14 -> V_32 ;
V_28 = V_31 -> V_33 ;
V_4 -> V_34 = V_31 -> V_35 ;
} else {
struct V_30 T_3 * V_31 = V_14 -> V_36 ;
V_28 = F_24 ( & V_31 -> V_37 ) ;
V_4 -> V_34 = F_25 ( & V_31 -> V_38 ) ;
}
if ( V_28 ) {
V_29 = F_26 ( V_28 , V_4 ) ;
if ( V_29 )
F_27 ( & V_4 -> V_14 -> V_39 ,
L_2 , V_29 ) ;
} else {
F_28 ( & V_4 -> V_27 ,
F_29 ( 1000 ) ) ;
}
}
static int F_30 ( struct V_13 * V_14 )
{
int V_40 ;
T_4 V_41 ;
if ( V_14 -> V_42 ) {
struct V_30 T_3 * V_31 = V_14 -> V_36 ;
V_41 = F_25 ( & V_31 -> V_43 ) ;
} else {
struct V_30 * V_31 = V_14 -> V_32 ;
V_41 = V_31 -> V_43 ;
}
V_3 = F_31 ( V_41 , sizeof( * V_3 ) , V_44 ) ;
if ( ! V_3 )
return - V_10 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
struct V_3 * V_4 = & V_3 [ V_40 ] ;
V_4 -> V_9 = V_40 ;
V_4 -> exit = V_45 ;
F_32 ( & V_4 -> V_46 ) ;
F_33 ( & V_4 -> V_47 ) ;
F_8 ( & V_4 -> V_48 , V_49 ) ;
F_34 ( & V_4 -> V_50 ,
V_51 ) ;
F_34 ( & V_4 -> V_27 ,
F_22 ) ;
F_35 ( & V_4 -> V_52 ) ;
F_20 ( V_4 -> V_20 , NULL ) ;
}
return 0 ;
}
static void F_36 ( void )
{
F_37 ( V_3 ) ;
}
static int F_38 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
int V_53 ;
F_39 ( & V_14 -> V_39 , V_14 ) ;
if ( 1 == F_40 ( 1 , & V_54 ) ) {
struct V_3 * V_55 ;
V_53 = F_30 ( V_14 ) ;
if ( V_53 )
goto exit;
V_4 = & V_3 [ V_14 -> V_21 ] ;
V_4 -> V_14 = V_14 ;
V_55 = & V_3 [ V_14 -> V_42 ] ;
V_55 -> V_14 = V_14 ;
V_53 = F_41 ( V_55 ) ;
if ( V_53 )
goto V_56;
} else {
V_4 = & V_3 [ V_14 -> V_21 ] ;
V_4 -> V_14 = V_14 ;
}
V_53 = F_6 ( V_4 ) ;
if ( V_53 )
goto V_57;
V_53 = F_42 ( V_4 ) ;
if ( V_53 )
goto V_58;
V_4 -> V_17 = V_14 -> V_15 -> V_59 ( V_14 ) ;
V_4 -> V_60 = V_14 -> V_15 -> V_61 ( V_14 , F_11 ,
L_3 , V_4 ,
V_4 -> V_17 ) ;
if ( F_43 ( V_4 -> V_60 ) ) {
V_53 = F_44 ( V_4 -> V_60 ) ;
goto V_62;
}
if ( F_23 () ) {
struct V_30 * V_31 = V_14 -> V_32 ;
V_31 -> V_38 = V_4 -> V_17 ;
V_31 -> V_37 = V_4 -> V_63 ;
} else {
struct V_30 T_3 * V_31 = V_14 -> V_36 ;
F_45 ( V_4 -> V_17 , & V_31 -> V_35 ) ;
F_46 ( V_4 -> V_63 , & V_31 -> V_33 ) ;
}
F_28 ( & V_4 -> V_27 ,
F_29 ( 1000 ) ) ;
return V_53 ;
V_62:
F_47 ( V_4 ) ;
V_58:
F_9 ( V_4 ) ;
V_57:
if ( F_48 ( & V_54 ) )
F_49 ( & V_3 [ V_14 -> V_42 ] ) ;
V_56:
F_36 () ;
exit:
return V_53 ;
}
void F_50 ( struct V_3 * V_4 )
{
struct V_3 * V_39 ;
int V_40 ;
for ( V_40 = V_22 . V_25 ; V_40 >= 0 ; V_40 -- ) {
V_39 = & V_3 [ V_40 ] ;
if ( F_3 ( V_39 ) )
continue;
F_51 ( V_40 ) ;
}
}
static void F_52 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = & V_3 [ V_14 -> V_21 ] ;
if ( F_23 () ) {
struct V_30 * V_31 = V_14 -> V_32 ;
V_31 -> V_38 = - 1 ;
V_31 -> V_37 = 0x0 ;
} else {
struct V_30 T_3 * V_31 = V_14 -> V_36 ;
F_45 ( - 1 , & V_31 -> V_35 ) ;
F_46 ( 0x0 , & V_31 -> V_33 ) ;
}
if ( F_23 () ) {
F_53 ( V_4 -> V_9 , true ) ;
} else {
V_22 . V_64 = true ;
F_50 ( V_4 ) ;
}
if ( F_48 ( & V_54 ) )
F_49 ( & V_3 [ V_14 -> V_42 ] ) ;
if ( V_4 -> V_60 ) {
V_14 -> V_15 -> V_65 ( V_14 , V_4 -> V_60 , V_4 ) ;
V_4 -> V_60 = NULL ;
}
F_9 ( V_4 ) ;
F_54 ( & V_4 -> V_27 ) ;
F_47 ( V_4 ) ;
V_4 -> V_34 = - 1 ;
V_4 -> V_14 = NULL ;
}
static int F_55 ( void )
{
F_56 ( & V_22 . V_66 ) ;
F_56 ( & V_22 . V_67 ) ;
F_56 ( & V_22 . V_68 ) ;
F_33 ( & V_22 . V_23 ) ;
F_33 ( & V_22 . V_69 ) ;
F_35 ( & V_22 . V_70 ) ;
F_35 ( & V_22 . V_71 ) ;
F_35 ( & V_22 . V_72 ) ;
F_35 ( & V_22 . V_73 ) ;
F_35 ( & V_22 . V_74 ) ;
F_35 ( & V_22 . V_75 ) ;
F_32 ( & V_22 . V_76 ) ;
V_22 . V_77 = 0 ;
V_22 . V_78 = 1 ;
F_8 ( & V_22 . V_79 , V_80 ) ;
F_8 ( & V_22 . V_81 , V_82 ) ;
F_57 ( & V_83 ) ;
return 0 ;
}
static void F_58 ( void )
{
F_59 ( & V_83 ) ;
F_36 () ;
}
static int T_5 F_60 ( void )
{
struct V_84 * V_85 = & V_22 . V_85 ;
int V_53 ;
F_55 () ;
V_53 = F_61 () ;
if ( V_53 )
goto exit;
V_53 = F_62 ( & V_86 ) ;
if ( V_53 )
goto V_87;
V_53 = F_63 ( & V_88 ) ;
if ( V_53 )
goto V_89;
V_53 = F_64 ( V_85 ) ;
if ( V_53 )
goto V_90;
F_65 () ;
return 0 ;
V_90:
F_66 ( & V_88 ) ;
V_89:
F_67 ( & V_86 ) ;
V_87:
F_68 () ;
exit:
F_58 () ;
return V_53 ;
}
static void T_6 F_69 ( void )
{
F_70 () ;
F_71 ( & V_22 . V_85 ) ;
F_66 ( & V_88 ) ;
F_67 ( & V_86 ) ;
F_68 () ;
F_58 () ;
}
