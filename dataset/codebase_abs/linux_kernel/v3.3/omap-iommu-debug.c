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
static T_1 F_28 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_10 ) ;
char * V_8 , * V_6 ;
struct V_43 * V_44 ;
int V_45 ( V_30 ) ;
T_1 V_14 ;
V_6 = ( char * ) F_26 ( V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_8 = V_6 ;
V_8 += sprintf ( V_8 , L_11 ,
L_12 , L_13 , L_14 , L_15 , L_16 ) ;
V_8 += sprintf ( V_8 , L_17 ) ;
F_7 ( & V_17 ) ;
F_29 (tmp, &obj->mmap, list) {
T_3 V_29 ;
const char * V_46 = L_18 ;
const int V_47 = 39 ;
V_29 = V_44 -> V_48 - V_44 -> V_49 ;
V_8 += snprintf ( V_8 , V_47 , V_46 ,
V_30 , V_44 -> V_49 , V_44 -> V_48 , V_29 , V_44 -> V_50 ) ;
if ( V_42 - ( V_8 - V_6 ) < V_47 )
break;
V_30 ++ ;
}
V_14 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
F_9 ( & V_17 ) ;
F_27 ( ( unsigned long ) V_6 ) ;
return V_14 ;
}
static T_1 F_30 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
char * V_8 , * V_6 ;
struct V_43 * V_51 ;
T_1 V_14 ;
V_3 = F_31 ( T_1 , V_3 , V_42 ) ;
V_6 = ( char * ) F_26 ( V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_8 = V_6 ;
F_7 ( & V_17 ) ;
V_51 = F_32 ( V_10 , ( T_5 ) V_4 ) ;
if ( ! V_51 ) {
V_14 = - V_27 ;
goto V_52;
}
memcpy ( V_8 , V_51 -> V_53 , V_3 ) ;
V_8 += V_3 ;
V_14 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
V_52:
F_9 ( & V_17 ) ;
F_27 ( ( unsigned long ) V_6 ) ;
return V_14 ;
}
static T_1 F_33 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_43 * V_51 ;
char * V_8 , * V_6 ;
V_3 = F_31 ( T_3 , V_3 , V_42 ) ;
V_6 = ( char * ) F_26 ( V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_8 = V_6 ;
F_7 ( & V_17 ) ;
if ( F_15 ( V_8 , V_2 , V_3 ) ) {
V_3 = - V_24 ;
goto V_52;
}
V_51 = F_32 ( V_10 , ( T_5 ) V_4 ) ;
if ( ! V_51 ) {
V_3 = - V_27 ;
goto V_52;
}
memcpy ( V_51 -> V_53 , V_8 , V_3 ) ;
V_52:
F_9 ( & V_17 ) ;
F_27 ( ( unsigned long ) V_6 ) ;
return V_3 ;
}
static int F_34 ( struct V_54 * V_54 , struct V_1 * V_1 )
{
V_1 -> V_11 = V_54 -> V_55 ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 , void * V_56 )
{
struct V_57 * V_58 = F_36 ( V_10 ) ;
struct V_12 * V_13 = F_37 ( V_58 ) ;
struct V_59 * V_60 ;
struct V_61 * V_62 , * V_63 ;
if ( ! V_13 || ! V_13 -> V_10 )
return - V_27 ;
V_60 = F_38 ( sizeof( * V_60 ) , V_15 ) ;
if ( ! V_60 )
return - V_16 ;
V_60 -> V_64 = V_13 ;
V_10 -> V_65 . V_66 = V_60 ;
V_62 = F_39 ( V_13 -> V_67 , V_68 ) ;
if ( ! V_62 )
goto V_69;
V_63 = V_62 ;
V_62 = F_40 ( L_19 , 400 , V_63 ,
( V_70 * ) & V_13 -> V_71 ) ;
if ( ! V_62 )
goto V_69;
F_41 ( V_5 ) ;
F_41 ( V_72 ) ;
F_41 ( V_73 ) ;
F_42 ( V_74 ) ;
F_41 ( V_75 ) ;
F_42 ( V_76 ) ;
return 0 ;
V_69:
F_10 ( V_60 ) ;
return - V_16 ;
}
static int F_43 ( struct V_9 * V_10 , void * V_56 )
{
if ( ! V_10 -> V_65 . V_66 )
return 0 ;
F_10 ( V_10 -> V_65 . V_66 ) ;
V_10 -> V_65 . V_66 = NULL ;
return 0 ;
}
static int T_6 F_44 ( void )
{
struct V_61 * V_62 ;
int V_23 ;
V_62 = F_39 ( L_20 , NULL ) ;
if ( ! V_62 )
return - V_16 ;
V_68 = V_62 ;
V_23 = F_45 ( V_62 , F_35 ) ;
if ( V_23 )
goto V_52;
return 0 ;
V_52:
F_46 ( V_68 ) ;
return V_23 ;
}
static void T_7 F_47 ( void )
{
F_46 ( V_68 ) ;
F_45 ( NULL , F_43 ) ;
}
