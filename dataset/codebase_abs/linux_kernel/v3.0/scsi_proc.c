static int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
int V_9 ;
V_9 = V_8 -> V_10 -> V_11 ( V_8 , V_1 , V_2 , V_3 , V_4 , 0 ) ;
* V_5 = ( V_9 < V_4 ) ;
return V_9 ;
}
static int F_2 ( struct V_12 * V_12 , const char T_2 * V_13 ,
unsigned long V_14 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
T_3 V_15 = - V_16 ;
char * V_17 ;
char * V_2 ;
if ( V_14 > V_18 )
return - V_19 ;
V_17 = ( char * ) F_3 ( V_20 ) ;
if ( V_17 ) {
V_15 = - V_21 ;
if ( F_4 ( V_17 , V_13 , V_14 ) )
goto V_22;
V_15 = V_8 -> V_10 -> V_11 ( V_8 , V_17 , & V_2 , 0 , V_14 , 1 ) ;
}
V_22:
F_5 ( ( unsigned long ) V_17 ) ;
return V_15 ;
}
void F_6 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_11 )
return;
F_7 ( & V_25 ) ;
if ( ! V_24 -> V_26 ++ ) {
V_24 -> V_27 = F_8 ( V_24 -> V_28 , V_29 ) ;
if ( ! V_24 -> V_27 )
F_9 ( V_30 L_1 ,
V_31 , V_24 -> V_28 ) ;
}
F_10 ( & V_25 ) ;
}
void F_11 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_11 )
return;
F_7 ( & V_25 ) ;
if ( ! -- V_24 -> V_26 && V_24 -> V_27 ) {
F_12 ( V_24 -> V_28 , V_29 ) ;
V_24 -> V_27 = NULL ;
}
F_10 ( & V_25 ) ;
}
void F_13 ( struct V_7 * V_8 )
{
struct V_23 * V_24 = V_8 -> V_10 ;
struct V_32 * V_33 ;
char V_34 [ 10 ] ;
if ( ! V_24 -> V_27 )
return;
sprintf ( V_34 , L_2 , V_8 -> V_35 ) ;
V_33 = F_14 ( V_34 , V_36 | V_37 | V_38 ,
V_24 -> V_27 , F_1 , V_8 ) ;
if ( ! V_33 ) {
F_9 ( V_30 L_3
L_4 , V_31 , V_8 -> V_35 ,
V_24 -> V_28 ) ;
return;
}
V_33 -> V_39 = F_2 ;
}
void F_15 ( struct V_7 * V_8 )
{
char V_34 [ 10 ] ;
if ( ! V_8 -> V_10 -> V_27 )
return;
sprintf ( V_34 , L_2 , V_8 -> V_35 ) ;
F_12 ( V_34 , V_8 -> V_10 -> V_27 ) ;
}
static int F_16 ( struct V_40 * V_41 , void * V_6 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 = V_6 ;
int V_46 ;
if ( ! F_17 ( V_41 ) )
goto V_22;
V_43 = F_18 ( V_41 ) ;
F_19 ( V_45 ,
L_5 ,
V_43 -> V_47 -> V_35 , V_43 -> V_48 , V_43 -> V_49 , V_43 -> V_50 ) ;
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ ) {
if ( V_43 -> V_51 [ V_46 ] >= 0x20 )
F_19 ( V_45 , L_6 , V_43 -> V_51 [ V_46 ] ) ;
else
F_19 ( V_45 , L_7 ) ;
}
F_19 ( V_45 , L_8 ) ;
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
if ( V_43 -> V_52 [ V_46 ] >= 0x20 )
F_19 ( V_45 , L_6 , V_43 -> V_52 [ V_46 ] ) ;
else
F_19 ( V_45 , L_7 ) ;
}
F_19 ( V_45 , L_9 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
if ( V_43 -> V_53 [ V_46 ] >= 0x20 )
F_19 ( V_45 , L_6 , V_43 -> V_53 [ V_46 ] ) ;
else
F_19 ( V_45 , L_7 ) ;
}
F_19 ( V_45 , L_10 ) ;
F_19 ( V_45 , L_11 , F_20 ( V_43 -> type ) ) ;
F_19 ( V_45 , L_12 ,
V_43 -> V_54 - ( V_43 -> V_54 > 1 ) ) ;
if ( V_43 -> V_54 == 2 )
F_19 ( V_45 , L_13 ) ;
else
F_19 ( V_45 , L_10 ) ;
V_22:
return 0 ;
}
static int F_21 ( T_4 V_47 , T_4 V_48 , T_4 V_49 , T_4 V_50 )
{
struct V_7 * V_8 ;
int error = - V_55 ;
V_8 = F_22 ( V_47 ) ;
if ( ! V_8 )
return error ;
if ( V_8 -> V_56 -> V_57 )
error = V_8 -> V_56 -> V_57 ( V_8 , V_48 , V_49 , V_50 ) ;
else
error = F_23 ( V_8 , V_48 , V_49 , V_50 , 1 ) ;
F_24 ( V_8 ) ;
return error ;
}
static int F_25 ( T_4 V_47 , T_4 V_48 , T_4 V_49 , T_4 V_50 )
{
struct V_42 * V_43 ;
struct V_7 * V_8 ;
int error = - V_55 ;
V_8 = F_22 ( V_47 ) ;
if ( ! V_8 )
return error ;
V_43 = F_26 ( V_8 , V_48 , V_49 , V_50 ) ;
if ( V_43 ) {
F_27 ( V_43 ) ;
F_28 ( V_43 ) ;
error = 0 ;
}
F_24 ( V_8 ) ;
return error ;
}
static T_3 F_29 ( struct V_12 * V_12 , const char T_2 * V_13 ,
T_5 V_4 , T_6 * V_58 )
{
int V_47 , V_48 , V_49 , V_50 ;
char * V_1 , * V_33 ;
int V_59 ;
if ( ! V_13 || V_4 > V_60 )
return - V_61 ;
V_1 = ( char * ) F_3 ( V_20 ) ;
if ( ! V_1 )
return - V_16 ;
V_59 = - V_21 ;
if ( F_4 ( V_1 , V_13 , V_4 ) )
goto V_22;
V_59 = - V_61 ;
if ( V_4 < V_60 )
V_1 [ V_4 ] = '\0' ;
else if ( V_1 [ V_60 - 1 ] )
goto V_22;
if ( ! strncmp ( L_14 , V_1 , 22 ) ) {
V_33 = V_1 + 23 ;
V_47 = F_30 ( V_33 , & V_33 , 0 ) ;
V_48 = F_30 ( V_33 + 1 , & V_33 , 0 ) ;
V_49 = F_30 ( V_33 + 1 , & V_33 , 0 ) ;
V_50 = F_30 ( V_33 + 1 , & V_33 , 0 ) ;
V_59 = F_21 ( V_47 , V_48 , V_49 , V_50 ) ;
} else if ( ! strncmp ( L_15 , V_1 , 25 ) ) {
V_33 = V_1 + 26 ;
V_47 = F_30 ( V_33 , & V_33 , 0 ) ;
V_48 = F_30 ( V_33 + 1 , & V_33 , 0 ) ;
V_49 = F_30 ( V_33 + 1 , & V_33 , 0 ) ;
V_50 = F_30 ( V_33 + 1 , & V_33 , 0 ) ;
V_59 = F_25 ( V_47 , V_48 , V_49 , V_50 ) ;
}
if ( ! V_59 )
V_59 = V_4 ;
V_22:
F_5 ( ( unsigned long ) V_1 ) ;
return V_59 ;
}
static int F_31 ( struct V_40 * V_41 , void * V_6 )
{
return 1 ;
}
static inline struct V_40 * F_32 ( struct V_40 * V_2 )
{
struct V_40 * V_62 = F_33 ( & V_63 , V_2 , NULL ,
F_31 ) ;
F_34 ( V_2 ) ;
return V_62 ;
}
static void * F_35 ( struct V_44 * V_64 , T_6 * V_65 )
{
struct V_40 * V_41 = NULL ;
T_6 V_9 = * V_65 ;
while ( ( V_41 = F_32 ( V_41 ) ) ) {
if ( ! V_9 -- )
break;
V_64 -> V_66 ++ ;
}
return V_41 ;
}
static void * F_36 ( struct V_44 * V_64 , void * V_67 , T_6 * V_65 )
{
( * V_65 ) ++ ;
V_64 -> V_66 ++ ;
return F_32 ( V_67 ) ;
}
static void F_37 ( struct V_44 * V_64 , void * V_67 )
{
F_34 ( V_67 ) ;
}
static int F_38 ( struct V_44 * V_64 , void * V_41 )
{
if ( ! V_64 -> V_66 )
F_39 ( V_64 , L_16 ) ;
return F_16 ( V_41 , V_64 ) ;
}
static int F_40 ( struct V_68 * V_68 , struct V_12 * V_12 )
{
return F_41 ( V_12 , & V_69 ) ;
}
int T_7 F_42 ( void )
{
struct V_32 * V_70 ;
V_29 = F_8 ( L_17 , NULL ) ;
if ( ! V_29 )
goto V_71;
V_70 = F_43 ( L_18 , 0 , NULL , & V_72 ) ;
if ( ! V_70 )
goto V_73;
return 0 ;
V_73:
F_12 ( L_17 , NULL ) ;
V_71:
return - V_16 ;
}
void F_44 ( void )
{
F_12 ( L_18 , NULL ) ;
F_12 ( L_17 , NULL ) ;
}
