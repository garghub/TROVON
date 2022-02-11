static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_5 V_5 = F_2 () ;
char V_6 [ V_7 ] , * V_8 = V_6 ;
V_8 += sprintf ( V_8 , L_1 , ( V_5 >> 4 ) & 0xf , V_5 & 0xf ) ;
return F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
}
static T_1 F_4 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_10 ) ;
char * V_8 , * V_6 ;
T_1 V_14 ;
V_6 = F_6 ( V_3 , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_8 = V_6 ;
F_7 ( & V_17 ) ;
V_14 = F_8 ( V_13 , V_8 , V_3 ) ;
V_14 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_14 ) ;
F_9 ( & V_17 ) ;
F_10 ( V_6 ) ;
return V_14 ;
}
static T_1 F_11 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_10 ) ;
char * V_8 , * V_6 ;
T_1 V_14 , V_18 ;
V_6 = F_6 ( V_3 , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_8 = V_6 ;
F_7 ( & V_17 ) ;
V_8 += sprintf ( V_8 , L_2 , L_3 , L_4 ) ;
V_8 += sprintf ( V_8 , L_5 ) ;
V_18 = V_3 - ( V_8 - V_6 ) ;
V_8 += F_12 ( V_13 , V_8 , V_18 ) ;
V_14 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
F_9 ( & V_17 ) ;
F_10 ( V_6 ) ;
return V_14 ;
}
static T_1 F_13 ( struct V_1 * V_1 ,
const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_19 V_20 ;
struct V_21 V_22 ;
int V_23 ;
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_10 ) ;
char V_6 [ V_7 ] , * V_8 = V_6 ;
V_3 = F_14 ( V_3 , sizeof( V_6 ) ) ;
F_7 ( & V_17 ) ;
if ( F_15 ( V_8 , V_2 , V_3 ) ) {
F_9 ( & V_17 ) ;
return - V_24 ;
}
sscanf ( V_8 , L_6 , & V_22 . V_25 , & V_22 . V_26 ) ;
if ( ! V_22 . V_25 || ! V_22 . V_26 ) {
F_9 ( & V_17 ) ;
return - V_27 ;
}
F_16 ( & V_22 , & V_20 ) ;
V_23 = F_17 ( V_13 , & V_20 ) ;
if ( V_23 )
F_18 ( V_13 -> V_10 , L_7 , V_28 ) ;
F_9 ( & V_17 ) ;
return V_3 ;
}
static T_1 F_19 ( struct V_12 * V_13 , char * V_6 , T_1 V_29 )
{
int V_30 ;
T_5 * V_31 ;
char * V_8 = V_6 ;
F_20 ( & V_13 -> V_32 ) ;
V_31 = F_21 ( V_13 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ , V_31 ++ ) {
int V_34 , V_23 ;
T_5 * V_35 ;
T_5 V_36 ;
if ( ! * V_31 )
continue;
if ( ! ( * V_31 & V_37 ) ) {
V_36 = V_30 << V_38 ;
V_23 = F_22 ( 1 , V_36 , * V_31 ) ;
if ( V_23 )
goto V_39;
continue;
}
V_35 = F_23 ( V_31 , 0 ) ;
for ( V_34 = 0 ; V_34 < V_40 ; V_34 ++ , V_35 ++ ) {
if ( ! * V_35 )
continue;
V_36 = ( V_30 << V_38 ) + ( V_34 << V_41 ) ;
V_23 = F_22 ( 2 , V_36 , * V_31 ) ;
if ( V_23 )
goto V_39;
}
}
V_39:
F_24 ( & V_13 -> V_32 ) ;
return V_8 - V_6 ;
}
static T_1 F_25 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_10 ) ;
char * V_8 , * V_6 ;
T_3 V_14 ;
V_6 = ( char * ) F_26 ( V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_8 = V_6 ;
V_8 += sprintf ( V_8 , L_8 , L_9 , L_10 ) ;
V_8 += sprintf ( V_8 , L_5 ) ;
F_7 ( & V_17 ) ;
V_14 = V_42 - ( V_8 - V_6 ) ;
V_8 += F_19 ( V_13 , V_8 , V_14 ) ;
V_14 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
F_9 ( & V_17 ) ;
F_27 ( ( unsigned long ) V_6 ) ;
return V_14 ;
}
static int F_28 ( struct V_9 * V_10 , void * V_43 )
{
struct V_44 * V_45 = F_29 ( V_10 ) ;
struct V_12 * V_13 = F_30 ( V_45 ) ;
struct V_46 * V_47 ;
struct V_48 * V_49 , * V_50 ;
if ( ! V_13 || ! V_13 -> V_10 )
return - V_27 ;
V_47 = F_31 ( sizeof( * V_47 ) , V_15 ) ;
if ( ! V_47 )
return - V_16 ;
V_47 -> V_51 = V_13 ;
V_10 -> V_52 . V_53 = V_47 ;
V_49 = F_32 ( V_13 -> V_54 , V_55 ) ;
if ( ! V_49 )
goto V_56;
V_50 = V_49 ;
V_49 = F_33 ( L_11 , 400 , V_50 ,
( V_57 * ) & V_13 -> V_58 ) ;
if ( ! V_49 )
goto V_56;
F_34 ( V_5 ) ;
F_34 ( V_59 ) ;
F_34 ( V_60 ) ;
F_35 ( V_61 ) ;
return 0 ;
V_56:
F_10 ( V_47 ) ;
return - V_16 ;
}
static int F_36 ( struct V_9 * V_10 , void * V_43 )
{
if ( ! V_10 -> V_52 . V_53 )
return 0 ;
F_10 ( V_10 -> V_52 . V_53 ) ;
V_10 -> V_52 . V_53 = NULL ;
return 0 ;
}
static int T_6 F_37 ( void )
{
struct V_48 * V_49 ;
int V_23 ;
V_49 = F_32 ( L_12 , NULL ) ;
if ( ! V_49 )
return - V_16 ;
V_55 = V_49 ;
V_23 = F_38 ( V_49 , F_28 ) ;
if ( V_23 )
goto V_62;
return 0 ;
V_62:
F_39 ( V_55 ) ;
return V_23 ;
}
static void T_7 F_40 ( void )
{
F_39 ( V_55 ) ;
F_38 ( NULL , F_36 ) ;
}
