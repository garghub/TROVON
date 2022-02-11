static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_1 ) ) ;
T_1 V_7 = - V_8 ;
char * V_9 ;
if ( V_3 > V_10 )
return - V_11 ;
if ( ! V_6 -> V_12 -> V_13 )
return - V_14 ;
V_9 = ( char * ) F_4 ( V_15 ) ;
if ( V_9 ) {
V_7 = - V_16 ;
if ( F_5 ( V_9 , V_2 , V_3 ) )
goto V_17;
V_7 = V_6 -> V_12 -> V_13 ( V_6 , V_9 , V_3 ) ;
}
V_17:
F_6 ( ( unsigned long ) V_9 ) ;
return V_7 ;
}
static int F_7 ( struct V_18 * V_19 , void * V_20 )
{
struct V_5 * V_6 = V_19 -> V_21 ;
return V_6 -> V_12 -> V_22 ( V_19 , V_6 ) ;
}
static int F_8 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
return F_9 ( V_1 , F_7 , F_2 ( V_23 ) ,
4 * V_24 ) ;
}
void F_10 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_22 )
return;
F_11 ( & V_27 ) ;
if ( ! V_26 -> V_28 ++ ) {
V_26 -> V_29 = F_12 ( V_26 -> V_30 , V_31 ) ;
if ( ! V_26 -> V_29 )
F_13 ( V_32 L_1 ,
V_33 , V_26 -> V_30 ) ;
}
F_14 ( & V_27 ) ;
}
void F_15 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_22 )
return;
F_11 ( & V_27 ) ;
if ( ! -- V_26 -> V_28 && V_26 -> V_29 ) {
F_16 ( V_26 -> V_30 , V_31 ) ;
V_26 -> V_29 = NULL ;
}
F_14 ( & V_27 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = V_6 -> V_12 ;
struct V_34 * V_35 ;
char V_36 [ 10 ] ;
if ( ! V_26 -> V_29 )
return;
sprintf ( V_36 , L_2 , V_6 -> V_37 ) ;
V_35 = F_18 ( V_36 , V_38 | V_39 ,
V_26 -> V_29 , & V_40 , V_6 ) ;
if ( ! V_35 )
F_13 ( V_32 L_3
L_4 , V_33 , V_6 -> V_37 ,
V_26 -> V_30 ) ;
}
void F_19 ( struct V_5 * V_6 )
{
char V_36 [ 10 ] ;
if ( ! V_6 -> V_12 -> V_29 )
return;
sprintf ( V_36 , L_2 , V_6 -> V_37 ) ;
F_16 ( V_36 , V_6 -> V_12 -> V_29 ) ;
}
static int F_20 ( struct V_41 * V_42 , void * V_43 )
{
struct V_44 * V_45 ;
struct V_18 * V_46 = V_43 ;
int V_47 ;
if ( ! F_21 ( V_42 ) )
goto V_17;
V_45 = F_22 ( V_42 ) ;
F_23 ( V_46 ,
L_5 ,
V_45 -> V_48 -> V_37 , V_45 -> V_49 , V_45 -> V_50 , V_45 -> V_51 ) ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
if ( V_45 -> V_52 [ V_47 ] >= 0x20 )
F_24 ( V_46 , V_45 -> V_52 [ V_47 ] ) ;
else
F_24 ( V_46 , ' ' ) ;
}
F_25 ( V_46 , L_6 ) ;
for ( V_47 = 0 ; V_47 < 16 ; V_47 ++ ) {
if ( V_45 -> V_53 [ V_47 ] >= 0x20 )
F_24 ( V_46 , V_45 -> V_53 [ V_47 ] ) ;
else
F_24 ( V_46 , ' ' ) ;
}
F_25 ( V_46 , L_7 ) ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
if ( V_45 -> V_54 [ V_47 ] >= 0x20 )
F_24 ( V_46 , V_45 -> V_54 [ V_47 ] ) ;
else
F_24 ( V_46 , ' ' ) ;
}
F_24 ( V_46 , '\n' ) ;
F_23 ( V_46 , L_8 , F_26 ( V_45 -> type ) ) ;
F_23 ( V_46 , L_9 ,
V_45 -> V_55 - ( V_45 -> V_55 > 1 ) ) ;
if ( V_45 -> V_55 == 2 )
F_25 ( V_46 , L_10 ) ;
else
F_24 ( V_46 , '\n' ) ;
V_17:
return 0 ;
}
static int F_27 ( T_5 V_48 , T_5 V_49 , T_5 V_50 , T_5 V_51 )
{
struct V_5 * V_6 ;
int error = - V_56 ;
V_6 = F_28 ( V_48 ) ;
if ( ! V_6 )
return error ;
if ( V_6 -> V_57 -> V_58 )
error = V_6 -> V_57 -> V_58 ( V_6 , V_49 , V_50 , V_51 ) ;
else
error = F_29 ( V_6 , V_49 , V_50 , V_51 ,
V_59 ) ;
F_30 ( V_6 ) ;
return error ;
}
static int F_31 ( T_5 V_48 , T_5 V_49 , T_5 V_50 , T_5 V_51 )
{
struct V_44 * V_45 ;
struct V_5 * V_6 ;
int error = - V_56 ;
V_6 = F_28 ( V_48 ) ;
if ( ! V_6 )
return error ;
V_45 = F_32 ( V_6 , V_49 , V_50 , V_51 ) ;
if ( V_45 ) {
F_33 ( V_45 ) ;
F_34 ( V_45 ) ;
error = 0 ;
}
F_30 ( V_6 ) ;
return error ;
}
static T_1 F_35 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_60 , T_4 * V_4 )
{
int V_48 , V_49 , V_50 , V_51 ;
char * V_61 , * V_35 ;
int V_62 ;
if ( ! V_2 || V_60 > V_24 )
return - V_14 ;
V_61 = ( char * ) F_4 ( V_15 ) ;
if ( ! V_61 )
return - V_8 ;
V_62 = - V_16 ;
if ( F_5 ( V_61 , V_2 , V_60 ) )
goto V_17;
V_62 = - V_14 ;
if ( V_60 < V_24 )
V_61 [ V_60 ] = '\0' ;
else if ( V_61 [ V_24 - 1 ] )
goto V_17;
if ( ! strncmp ( L_11 , V_61 , 22 ) ) {
V_35 = V_61 + 23 ;
V_48 = F_36 ( V_35 , & V_35 , 0 ) ;
V_49 = F_36 ( V_35 + 1 , & V_35 , 0 ) ;
V_50 = F_36 ( V_35 + 1 , & V_35 , 0 ) ;
V_51 = F_36 ( V_35 + 1 , & V_35 , 0 ) ;
V_62 = F_27 ( V_48 , V_49 , V_50 , V_51 ) ;
} else if ( ! strncmp ( L_12 , V_61 , 25 ) ) {
V_35 = V_61 + 26 ;
V_48 = F_36 ( V_35 , & V_35 , 0 ) ;
V_49 = F_36 ( V_35 + 1 , & V_35 , 0 ) ;
V_50 = F_36 ( V_35 + 1 , & V_35 , 0 ) ;
V_51 = F_36 ( V_35 + 1 , & V_35 , 0 ) ;
V_62 = F_31 ( V_48 , V_49 , V_50 , V_51 ) ;
}
if ( ! V_62 )
V_62 = V_60 ;
V_17:
F_6 ( ( unsigned long ) V_61 ) ;
return V_62 ;
}
static int F_37 ( struct V_41 * V_42 , void * V_43 )
{
return 1 ;
}
static inline struct V_41 * F_38 ( struct V_41 * V_63 )
{
struct V_41 * V_64 = F_39 ( & V_65 , V_63 , NULL ,
F_37 ) ;
F_40 ( V_63 ) ;
return V_64 ;
}
static void * F_41 ( struct V_18 * V_66 , T_4 * V_67 )
{
struct V_41 * V_42 = NULL ;
T_4 V_68 = * V_67 ;
while ( ( V_42 = F_38 ( V_42 ) ) ) {
if ( ! V_68 -- )
break;
V_66 -> V_21 ++ ;
}
return V_42 ;
}
static void * F_42 ( struct V_18 * V_66 , void * V_20 , T_4 * V_67 )
{
( * V_67 ) ++ ;
V_66 -> V_21 ++ ;
return F_38 ( V_20 ) ;
}
static void F_43 ( struct V_18 * V_66 , void * V_20 )
{
F_40 ( V_20 ) ;
}
static int F_44 ( struct V_18 * V_66 , void * V_42 )
{
if ( ! V_66 -> V_21 )
F_25 ( V_66 , L_13 ) ;
return F_20 ( V_42 , V_66 ) ;
}
static int F_45 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
return F_46 ( V_1 , & V_69 ) ;
}
int T_6 F_47 ( void )
{
struct V_34 * V_70 ;
V_31 = F_12 ( L_14 , NULL ) ;
if ( ! V_31 )
goto V_71;
V_70 = F_48 ( L_15 , 0 , NULL , & V_72 ) ;
if ( ! V_70 )
goto V_73;
return 0 ;
V_73:
F_16 ( L_14 , NULL ) ;
V_71:
return - V_8 ;
}
void F_49 ( void )
{
F_16 ( L_15 , NULL ) ;
F_16 ( L_14 , NULL ) ;
}
