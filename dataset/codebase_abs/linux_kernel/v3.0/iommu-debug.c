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
char * V_8 , * V_6 ;
T_1 V_12 ;
V_6 = F_5 ( V_3 , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = V_6 ;
F_6 ( & V_15 ) ;
V_12 = F_7 ( V_10 , V_8 , V_3 ) ;
V_12 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_12 ) ;
F_8 ( & V_15 ) ;
F_9 ( V_6 ) ;
return V_12 ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
char * V_8 , * V_6 ;
T_1 V_12 , V_16 ;
V_6 = F_5 ( V_3 , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = V_6 ;
F_6 ( & V_15 ) ;
V_8 += sprintf ( V_8 , L_2 , L_3 , L_4 ) ;
V_8 += sprintf ( V_8 , L_5 ) ;
V_16 = V_3 - ( V_8 - V_6 ) ;
V_8 += F_11 ( V_10 , V_8 , V_16 ) ;
V_12 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
F_8 ( & V_15 ) ;
F_9 ( V_6 ) ;
return V_12 ;
}
static T_1 F_12 ( struct V_1 * V_1 ,
const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_17 V_18 ;
struct V_19 V_20 ;
int V_21 ;
struct V_9 * V_10 = V_1 -> V_11 ;
char V_6 [ V_7 ] , * V_8 = V_6 ;
V_3 = F_13 ( V_3 , sizeof( V_6 ) ) ;
F_6 ( & V_15 ) ;
if ( F_14 ( V_8 , V_2 , V_3 ) ) {
F_8 ( & V_15 ) ;
return - V_22 ;
}
sscanf ( V_8 , L_6 , & V_20 . V_23 , & V_20 . V_24 ) ;
if ( ! V_20 . V_23 || ! V_20 . V_24 ) {
F_8 ( & V_15 ) ;
return - V_25 ;
}
F_15 ( & V_20 , & V_18 ) ;
V_21 = F_16 ( V_10 , & V_18 ) ;
if ( V_21 )
F_17 ( V_10 -> V_26 , L_7 , V_27 ) ;
F_8 ( & V_15 ) ;
return V_3 ;
}
static T_1 F_18 ( struct V_9 * V_10 , char * V_6 , T_1 V_28 )
{
int V_29 ;
T_5 * V_30 ;
char * V_8 = V_6 ;
F_19 ( & V_10 -> V_31 ) ;
V_30 = F_20 ( V_10 , 0 ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ , V_30 ++ ) {
int V_33 , V_21 ;
T_5 * V_34 ;
T_5 V_35 ;
if ( ! * V_30 )
continue;
if ( ! ( * V_30 & V_36 ) ) {
V_35 = V_29 << V_37 ;
V_21 = F_21 ( 1 , V_35 , * V_30 ) ;
if ( V_21 )
goto V_38;
continue;
}
V_34 = F_22 ( V_30 , 0 ) ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ , V_34 ++ ) {
if ( ! * V_34 )
continue;
V_35 = ( V_29 << V_37 ) + ( V_33 << V_40 ) ;
V_21 = F_21 ( 2 , V_35 , * V_30 ) ;
if ( V_21 )
goto V_38;
}
}
V_38:
F_23 ( & V_10 -> V_31 ) ;
return V_8 - V_6 ;
}
static T_1 F_24 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
char * V_8 , * V_6 ;
T_3 V_12 ;
V_6 = ( char * ) F_25 ( V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = V_6 ;
V_8 += sprintf ( V_8 , L_8 , L_9 , L_10 ) ;
V_8 += sprintf ( V_8 , L_5 ) ;
F_6 ( & V_15 ) ;
V_12 = V_41 - ( V_8 - V_6 ) ;
V_8 += F_18 ( V_10 , V_8 , V_12 ) ;
V_12 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
F_8 ( & V_15 ) ;
F_26 ( ( unsigned long ) V_6 ) ;
return V_12 ;
}
static T_1 F_27 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
char * V_8 , * V_6 ;
struct V_42 * V_43 ;
int V_44 ( V_29 ) ;
T_1 V_12 ;
V_6 = ( char * ) F_25 ( V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = V_6 ;
V_8 += sprintf ( V_8 , L_11 ,
L_12 , L_13 , L_14 , L_15 , L_16 ) ;
V_8 += sprintf ( V_8 , L_17 ) ;
F_6 ( & V_15 ) ;
F_28 (tmp, &obj->mmap, list) {
T_3 V_28 ;
const char * V_45 = L_18 ;
const int V_46 = 39 ;
V_28 = V_43 -> V_47 - V_43 -> V_48 ;
V_8 += snprintf ( V_8 , V_46 , V_45 ,
V_29 , V_43 -> V_48 , V_43 -> V_47 , V_28 , V_43 -> V_49 ) ;
if ( V_41 - ( V_8 - V_6 ) < V_46 )
break;
V_29 ++ ;
}
V_12 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
F_8 ( & V_15 ) ;
F_26 ( ( unsigned long ) V_6 ) ;
return V_12 ;
}
static T_1 F_29 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
char * V_8 , * V_6 ;
struct V_42 * V_50 ;
T_1 V_12 ;
V_3 = F_30 ( T_1 , V_3 , V_41 ) ;
V_6 = ( char * ) F_25 ( V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = V_6 ;
F_6 ( & V_15 ) ;
V_50 = F_31 ( V_10 , ( T_5 ) V_4 ) ;
if ( F_32 ( V_50 ) ) {
V_12 = - V_25 ;
goto V_51;
}
memcpy ( V_8 , V_50 -> V_52 , V_3 ) ;
V_8 += V_3 ;
V_12 = F_3 ( V_2 , V_3 , V_4 , V_6 , V_8 - V_6 ) ;
V_51:
F_8 ( & V_15 ) ;
F_26 ( ( unsigned long ) V_6 ) ;
return V_12 ;
}
static T_1 F_33 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_42 * V_50 ;
char * V_8 , * V_6 ;
V_3 = F_30 ( T_3 , V_3 , V_41 ) ;
V_6 = ( char * ) F_25 ( V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = V_6 ;
F_6 ( & V_15 ) ;
if ( F_14 ( V_8 , V_2 , V_3 ) ) {
V_3 = - V_22 ;
goto V_51;
}
V_50 = F_31 ( V_10 , ( T_5 ) V_4 ) ;
if ( F_32 ( V_50 ) ) {
V_3 = - V_25 ;
goto V_51;
}
memcpy ( V_50 -> V_52 , V_8 , V_3 ) ;
V_51:
F_8 ( & V_15 ) ;
F_26 ( ( unsigned long ) V_6 ) ;
return V_3 ;
}
static int F_34 ( struct V_53 * V_53 , struct V_1 * V_1 )
{
V_1 -> V_11 = V_53 -> V_54 ;
return 0 ;
}
static int F_35 ( struct V_55 * V_26 , void * V_56 )
{
struct V_57 * V_58 = F_36 ( V_26 ) ;
struct V_9 * V_10 = F_37 ( V_58 ) ;
struct V_59 * V_60 , * V_61 ;
if ( ! V_10 || ! V_10 -> V_26 )
return - V_25 ;
V_60 = F_38 ( V_10 -> V_62 , V_63 ) ;
if ( ! V_60 )
return - V_14 ;
V_61 = V_60 ;
V_60 = F_39 ( L_19 , 400 , V_61 ,
( V_64 * ) & V_10 -> V_65 ) ;
if ( ! V_60 )
return - V_14 ;
F_40 ( V_5 ) ;
F_40 ( V_66 ) ;
F_40 ( V_67 ) ;
F_41 ( V_68 ) ;
F_40 ( V_69 ) ;
F_41 ( V_70 ) ;
return 0 ;
}
static int T_6 F_42 ( void )
{
struct V_59 * V_60 ;
int V_21 ;
V_60 = F_38 ( L_20 , NULL ) ;
if ( ! V_60 )
return - V_14 ;
V_63 = V_60 ;
V_21 = F_43 ( V_60 , F_35 ) ;
if ( V_21 )
goto V_51;
return 0 ;
V_51:
F_44 ( V_63 ) ;
return V_21 ;
}
static void T_7 F_45 ( void )
{
F_44 ( V_63 ) ;
}
