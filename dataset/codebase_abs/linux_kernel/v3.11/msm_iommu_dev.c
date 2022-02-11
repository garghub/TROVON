static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_5 || ! V_7 || ! V_7 -> V_9 || ! V_5 -> V_9 )
return - V_10 ;
if ( ! strcmp ( V_5 -> V_9 , V_7 -> V_9 ) ) {
V_5 -> V_2 = V_2 ;
return 1 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_3 )
{
return F_3 ( V_2 , V_3 , F_1 ) ;
}
struct V_1 * F_4 ( const char * V_11 )
{
struct V_4 V_12 ;
int V_13 ;
if ( ! V_14 ) {
F_5 ( L_1 ) ;
goto V_15;
}
V_12 . V_9 = V_11 ;
V_13 = F_3 ( & V_14 -> V_2 , & V_12 , F_2 ) ;
if ( ! V_13 ) {
F_5 ( L_2 , V_11 ) ;
goto V_15;
}
return V_12 . V_2 ;
V_15:
return NULL ;
}
static void F_6 ( void T_1 * V_16 , int V_17 )
{
int V_18 ;
F_7 ( V_16 , 0 ) ;
F_8 ( V_16 , 0 ) ;
F_9 ( V_16 , 0 ) ;
F_10 ( V_16 , 0 ) ;
F_11 ( V_16 , 0 ) ;
F_12 ( V_16 , 0 ) ;
F_13 ( V_16 , 0 ) ;
F_14 ( V_16 , 0 ) ;
F_15 ( V_16 , 0 ) ;
F_16 ( V_16 , 0 ) ;
F_17 ( V_16 , 1 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
F_18 ( V_16 , V_18 , 0 ) ;
F_19 ( V_16 , V_18 , 0 ) ;
F_20 ( V_16 , V_18 , 0 ) ;
F_21 ( V_16 , V_18 , 0 ) ;
F_22 ( V_16 , V_18 , 0 ) ;
F_23 ( V_16 , V_18 , 0 ) ;
F_24 ( V_16 , V_18 , 0 ) ;
F_25 ( V_16 , V_18 , 0 ) ;
F_26 ( V_16 , V_18 , 0 ) ;
F_27 ( V_16 , V_18 , 0 ) ;
F_28 ( V_16 , V_18 , 0 ) ;
F_29 ( V_16 , V_18 , 0 ) ;
F_30 ( V_16 , V_18 , 0 ) ;
F_31 ( V_16 , V_18 , 0 ) ;
F_32 ( V_16 , V_18 , 0 ) ;
F_33 ( V_16 , V_18 , 0 ) ;
F_34 ( V_16 , V_18 , 0 ) ;
F_35 ( V_16 , V_18 , 0 ) ;
F_36 ( V_16 , V_18 , 0 ) ;
F_37 ( V_16 , V_18 , 0 ) ;
F_38 ( V_16 , V_18 , 0 ) ;
}
}
static int F_39 ( struct V_19 * V_20 )
{
struct V_21 * V_12 , * V_22 ;
struct V_23 * V_24 ;
struct V_23 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = V_20 -> V_2 . V_8 ;
void T_1 * V_30 ;
T_2 V_31 ;
int V_32 , V_33 , V_34 ;
if ( V_20 -> V_35 == - 1 ) {
V_14 = V_20 ;
return 0 ;
}
V_27 = F_40 ( sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 ) {
V_32 = - V_37 ;
goto V_15;
}
if ( ! V_29 ) {
V_32 = - V_38 ;
goto V_15;
}
V_25 = F_41 ( NULL , L_3 ) ;
if ( F_42 ( V_25 ) ) {
V_32 = - V_38 ;
goto V_15;
}
V_32 = F_43 ( V_25 ) ;
if ( V_32 )
goto V_39;
V_24 = F_41 ( & V_20 -> V_2 , L_4 ) ;
if ( ! F_42 ( V_24 ) ) {
if ( F_44 ( V_24 ) == 0 )
F_45 ( V_24 , 1 ) ;
V_32 = F_43 ( V_24 ) ;
if ( V_32 ) {
F_46 ( V_24 ) ;
goto V_40;
}
} else
V_24 = NULL ;
V_12 = F_47 ( V_20 , V_41 , L_5 ) ;
if ( ! V_12 ) {
V_32 = - V_38 ;
goto V_42;
}
V_31 = F_48 ( V_12 ) ;
V_22 = F_49 ( V_12 -> V_43 , V_31 , V_12 -> V_9 ) ;
if ( ! V_22 ) {
F_5 ( L_6 ,
( void * ) V_12 -> V_43 , V_31 ) ;
V_32 = - V_44 ;
goto V_42;
}
V_30 = F_50 ( V_22 -> V_43 , V_31 ) ;
if ( ! V_30 ) {
F_5 ( L_7 ,
( void * ) V_22 -> V_43 , V_31 ) ;
V_32 = - V_44 ;
goto V_45;
}
V_33 = F_51 ( V_20 , L_8 ) ;
if ( V_33 < 0 ) {
V_32 = - V_38 ;
goto V_46;
}
F_6 ( V_30 , V_29 -> V_17 ) ;
F_52 ( V_30 , 0 , 1 ) ;
F_30 ( V_30 , 0 , 0 ) ;
F_53 ( V_30 , 0 , 1 ) ;
F_54 ( V_30 , 0 , 0 ) ;
V_34 = F_55 ( V_30 , 0 ) ;
F_53 ( V_30 , 0 , 0 ) ;
F_52 ( V_30 , 0 , 0 ) ;
if ( ! V_34 ) {
F_5 ( L_9 , V_29 -> V_9 ) ;
V_32 = - V_38 ;
goto V_46;
}
V_32 = F_56 ( V_33 , V_47 , 0 ,
L_10 , V_27 ) ;
if ( V_32 ) {
F_5 ( L_11 , V_33 , V_32 ) ;
goto V_46;
}
V_27 -> V_48 = V_25 ;
V_27 -> V_23 = V_24 ;
V_27 -> V_16 = V_30 ;
V_27 -> V_33 = V_33 ;
V_27 -> V_17 = V_29 -> V_17 ;
F_57 ( L_12 ,
V_29 -> V_9 , V_30 , V_33 , V_29 -> V_17 ) ;
F_58 ( V_20 , V_27 ) ;
if ( V_24 )
F_59 ( V_24 ) ;
F_59 ( V_25 ) ;
return 0 ;
V_46:
F_60 ( V_30 ) ;
V_45:
F_61 ( V_12 -> V_43 , V_31 ) ;
V_42:
if ( V_24 ) {
F_59 ( V_24 ) ;
F_46 ( V_24 ) ;
}
V_40:
F_62 ( V_25 ) ;
V_39:
F_46 ( V_25 ) ;
V_15:
F_63 ( V_27 ) ;
return V_32 ;
}
static int F_64 ( struct V_19 * V_20 )
{
struct V_26 * V_49 = NULL ;
V_49 = F_65 ( V_20 ) ;
if ( V_49 ) {
if ( V_49 -> V_23 ) {
F_66 ( V_49 -> V_23 ) ;
F_46 ( V_49 -> V_23 ) ;
}
F_66 ( V_49 -> V_48 ) ;
F_46 ( V_49 -> V_48 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_63 ( V_49 ) ;
F_58 ( V_20 , NULL ) ;
}
return 0 ;
}
static int F_67 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = V_20 -> V_2 . V_8 ;
struct V_26 * V_27 ;
struct V_50 * V_51 ;
int V_52 , V_32 ;
if ( ! V_7 || ! V_20 -> V_2 . V_53 )
return - V_10 ;
V_27 = F_68 ( V_20 -> V_2 . V_53 ) ;
if ( ! V_27 )
return - V_38 ;
V_51 = F_40 ( sizeof( * V_51 ) , V_36 ) ;
if ( ! V_51 )
return - V_37 ;
V_51 -> V_54 = V_7 -> V_54 ;
V_51 -> V_20 = V_20 ;
F_69 ( & V_51 -> V_55 ) ;
F_58 ( V_20 , V_51 ) ;
V_32 = F_43 ( V_27 -> V_48 ) ;
if ( V_32 )
goto V_15;
if ( V_27 -> V_23 ) {
V_32 = F_43 ( V_27 -> V_23 ) ;
if ( V_32 ) {
F_62 ( V_27 -> V_48 ) ;
goto V_15;
}
}
for ( V_52 = 0 ; V_52 < V_56 ; V_52 ++ ) {
int V_57 = V_7 -> V_58 [ V_52 ] ;
if ( V_57 == - 1 )
break;
F_70 ( V_27 -> V_16 , V_57 , 0 ) ;
F_71 ( V_27 -> V_16 , V_7 -> V_54 , 0 ) ;
F_72 ( V_27 -> V_16 , V_57 , 0 ) ;
F_73 ( V_27 -> V_16 , V_57 , V_7 -> V_54 ) ;
F_74 ( V_27 -> V_16 , V_7 -> V_54 , 0 ) ;
F_75 ( V_27 -> V_16 , V_7 -> V_54 , V_7 -> V_54 ) ;
F_76 ( V_27 -> V_16 , V_57 , 3 ) ;
}
if ( V_27 -> V_23 )
F_59 ( V_27 -> V_23 ) ;
F_59 ( V_27 -> V_48 ) ;
F_77 ( & V_20 -> V_2 , L_13 , V_7 -> V_9 , V_7 -> V_54 ) ;
return 0 ;
V_15:
F_63 ( V_51 ) ;
return V_32 ;
}
static int F_78 ( struct V_19 * V_20 )
{
struct V_50 * V_49 = NULL ;
V_49 = F_65 ( V_20 ) ;
if ( V_49 ) {
memset ( V_49 , 0 , sizeof( struct V_50 ) ) ;
F_63 ( V_49 ) ;
F_58 ( V_20 , NULL ) ;
}
return 0 ;
}
static int T_3 F_79 ( void )
{
int V_32 ;
V_32 = F_80 ( & V_59 ) ;
if ( V_32 != 0 ) {
F_5 ( L_14 ) ;
goto error;
}
V_32 = F_80 ( & V_60 ) ;
if ( V_32 != 0 ) {
F_81 ( & V_59 ) ;
F_5 ( L_15 ) ;
goto error;
}
error:
return V_32 ;
}
static void T_4 F_82 ( void )
{
F_81 ( & V_60 ) ;
F_81 ( & V_59 ) ;
}
