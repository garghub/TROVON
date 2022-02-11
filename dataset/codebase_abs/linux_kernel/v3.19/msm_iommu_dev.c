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
struct V_21 * V_12 ;
struct V_22 * V_23 ;
struct V_22 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 = F_40 ( & V_20 -> V_2 ) ;
void T_1 * V_29 ;
int V_30 , V_31 , V_32 ;
if ( V_20 -> V_33 == - 1 ) {
V_14 = V_20 ;
return 0 ;
}
V_26 = F_41 ( sizeof( * V_26 ) , V_34 ) ;
if ( ! V_26 ) {
V_30 = - V_35 ;
goto V_15;
}
if ( ! V_28 ) {
V_30 = - V_36 ;
goto V_15;
}
V_24 = F_42 ( NULL , L_3 ) ;
if ( F_43 ( V_24 ) ) {
V_30 = - V_36 ;
goto V_15;
}
V_30 = F_44 ( V_24 ) ;
if ( V_30 )
goto V_37;
V_23 = F_42 ( & V_20 -> V_2 , L_4 ) ;
if ( ! F_43 ( V_23 ) ) {
if ( F_45 ( V_23 ) == 0 )
F_46 ( V_23 , 1 ) ;
V_30 = F_44 ( V_23 ) ;
if ( V_30 ) {
F_47 ( V_23 ) ;
goto V_38;
}
} else
V_23 = NULL ;
V_12 = F_48 ( V_20 , V_39 , L_5 ) ;
V_29 = F_49 ( & V_20 -> V_2 , V_12 ) ;
if ( F_43 ( V_29 ) ) {
V_30 = F_50 ( V_29 ) ;
goto V_40;
}
V_31 = F_51 ( V_20 , L_6 ) ;
if ( V_31 < 0 ) {
V_30 = - V_36 ;
goto V_40;
}
F_6 ( V_29 , V_28 -> V_17 ) ;
F_52 ( V_29 , 0 , 1 ) ;
F_30 ( V_29 , 0 , 0 ) ;
F_53 ( V_29 , 0 , 1 ) ;
F_54 ( V_29 , 0 , 0 ) ;
V_32 = F_55 ( V_29 , 0 ) ;
F_53 ( V_29 , 0 , 0 ) ;
F_52 ( V_29 , 0 , 0 ) ;
if ( ! V_32 ) {
F_5 ( L_7 , V_28 -> V_9 ) ;
V_30 = - V_36 ;
goto V_40;
}
V_30 = F_56 ( V_31 , V_41 , 0 ,
L_8 , V_26 ) ;
if ( V_30 ) {
F_5 ( L_9 , V_31 , V_30 ) ;
goto V_40;
}
V_26 -> V_42 = V_24 ;
V_26 -> V_22 = V_23 ;
V_26 -> V_16 = V_29 ;
V_26 -> V_31 = V_31 ;
V_26 -> V_17 = V_28 -> V_17 ;
F_57 ( L_10 ,
V_28 -> V_9 , V_29 , V_31 , V_28 -> V_17 ) ;
F_58 ( V_20 , V_26 ) ;
F_59 ( V_23 ) ;
F_59 ( V_24 ) ;
return 0 ;
V_40:
if ( V_23 ) {
F_59 ( V_23 ) ;
F_47 ( V_23 ) ;
}
V_38:
F_60 ( V_24 ) ;
V_37:
F_47 ( V_24 ) ;
V_15:
F_61 ( V_26 ) ;
return V_30 ;
}
static int F_62 ( struct V_19 * V_20 )
{
struct V_25 * V_43 = NULL ;
V_43 = F_63 ( V_20 ) ;
if ( V_43 ) {
if ( V_43 -> V_22 ) {
F_64 ( V_43 -> V_22 ) ;
F_47 ( V_43 -> V_22 ) ;
}
F_64 ( V_43 -> V_42 ) ;
F_47 ( V_43 -> V_42 ) ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
F_61 ( V_43 ) ;
}
return 0 ;
}
static int F_65 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_40 ( & V_20 -> V_2 ) ;
struct V_25 * V_26 ;
struct V_44 * V_45 ;
int V_46 , V_30 ;
if ( ! V_7 || ! V_20 -> V_2 . V_47 )
return - V_10 ;
V_26 = F_66 ( V_20 -> V_2 . V_47 ) ;
if ( ! V_26 )
return - V_36 ;
V_45 = F_41 ( sizeof( * V_45 ) , V_34 ) ;
if ( ! V_45 )
return - V_35 ;
V_45 -> V_48 = V_7 -> V_48 ;
V_45 -> V_20 = V_20 ;
F_67 ( & V_45 -> V_49 ) ;
F_58 ( V_20 , V_45 ) ;
V_30 = F_44 ( V_26 -> V_42 ) ;
if ( V_30 )
goto V_15;
if ( V_26 -> V_22 ) {
V_30 = F_44 ( V_26 -> V_22 ) ;
if ( V_30 ) {
F_60 ( V_26 -> V_42 ) ;
goto V_15;
}
}
for ( V_46 = 0 ; V_46 < V_50 ; V_46 ++ ) {
int V_51 = V_7 -> V_52 [ V_46 ] ;
if ( V_51 == - 1 )
break;
F_68 ( V_26 -> V_16 , V_51 , 0 ) ;
F_69 ( V_26 -> V_16 , V_7 -> V_48 , 0 ) ;
F_70 ( V_26 -> V_16 , V_51 , 0 ) ;
F_71 ( V_26 -> V_16 , V_51 , V_7 -> V_48 ) ;
F_72 ( V_26 -> V_16 , V_7 -> V_48 , 0 ) ;
F_73 ( V_26 -> V_16 , V_7 -> V_48 , V_7 -> V_48 ) ;
F_74 ( V_26 -> V_16 , V_51 , 3 ) ;
}
F_59 ( V_26 -> V_22 ) ;
F_59 ( V_26 -> V_42 ) ;
F_75 ( & V_20 -> V_2 , L_11 , V_7 -> V_9 , V_7 -> V_48 ) ;
return 0 ;
V_15:
F_61 ( V_45 ) ;
return V_30 ;
}
static int F_76 ( struct V_19 * V_20 )
{
struct V_44 * V_43 = NULL ;
V_43 = F_63 ( V_20 ) ;
if ( V_43 ) {
memset ( V_43 , 0 , sizeof( struct V_44 ) ) ;
F_61 ( V_43 ) ;
}
return 0 ;
}
static int T_2 F_77 ( void )
{
int V_30 ;
V_30 = F_78 ( & V_53 ) ;
if ( V_30 != 0 ) {
F_5 ( L_12 ) ;
goto error;
}
V_30 = F_78 ( & V_54 ) ;
if ( V_30 != 0 ) {
F_79 ( & V_53 ) ;
F_5 ( L_13 ) ;
goto error;
}
error:
return V_30 ;
}
static void T_3 F_80 ( void )
{
F_79 ( & V_54 ) ;
F_79 ( & V_53 ) ;
}
