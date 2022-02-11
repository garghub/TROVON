int F_1 ( void )
{
int V_1 = - V_2 ;
V_3 = F_2 ( L_1 , NULL ) ;
if ( ! V_3 ) {
F_3 ( L_2 , V_4 ) ;
goto V_5;
}
V_6 = F_4 ( V_7 ,
0444 ,
V_3 ,
V_8 ,
& V_9 ) ;
if ( ! V_6 ) {
F_3 ( L_3 , V_4 ) ;
goto V_5;
}
V_10 = 0 ;
V_1 = 0 ;
V_5:
return V_1 ;
}
void F_5 ( void )
{
F_6 ( V_3 ) ;
}
static int F_7 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
int V_1 = - V_13 ;
int V_14 ;
F_8 ( V_15 ,
L_4 ) ;
if ( V_10 )
goto V_5;
V_14 = F_9 ( V_12 , & V_16 ) ;
if ( V_14 )
goto V_5;
( (struct V_17 * ) ( V_12 -> V_18 ) ) -> V_19 = V_11 -> V_20 ;
V_1 = 0 ;
V_5:
F_8 ( V_15 ,
L_5 ,
V_1 ) ;
return V_1 ;
}
static void * F_10 ( struct V_17 * V_21 , T_1 * V_22 )
{
void * V_23 = NULL ;
F_8 ( V_15 , L_6 ) ;
if ( * V_22 == 0 )
V_23 = V_21 -> V_19 ;
return V_23 ;
}
static void * F_11 ( struct V_17 * V_21 , void * V_24 , T_1 * V_22 )
{
F_8 ( V_15 , L_7 ) ;
return NULL ;
}
static void F_12 ( struct V_17 * V_21 , void * V_25 )
{
F_8 ( V_15 , L_8 ) ;
}
static int F_13 ( struct V_17 * V_21 , void * V_24 )
{
F_8 ( V_15 , L_9 ) ;
F_14 ( V_21 , V_24 ) ;
return 0 ;
}
int F_15 ( void )
{
int V_1 = - V_2 ;
struct V_26 * V_14 ;
char * V_27 = NULL ;
F_8 ( V_15 , L_10 , V_4 ) ;
V_27 = F_16 ( V_28 , V_29 ) ;
if ( ! V_27 )
goto V_5;
if ( strlen ( V_30 ) + 1 < V_28 ) {
strcpy ( V_27 , V_30 ) ;
strcat ( V_27 , L_11 ) ;
} else {
strcpy ( V_27 , L_12 ) ;
F_3 ( L_13 , V_4 ) ;
}
V_14 = F_4 ( V_31 ,
0444 ,
V_3 ,
V_27 ,
& V_32 ) ;
if ( ! V_14 ) {
F_3 ( L_14 ,
V_4 ,
V_31 ) ;
goto V_5;
}
V_1 = 0 ;
V_5:
F_8 ( V_15 , L_15 , V_4 , V_1 ) ;
return V_1 ;
}
int F_17 ( void )
{
int V_1 = - V_2 ;
char * V_33 = NULL ;
F_8 ( V_15 , L_10 , V_4 ) ;
V_33 = F_16 ( V_28 , V_29 ) ;
if ( ! V_33 )
goto V_5;
if ( strlen ( V_34 ) + 1 < V_28 ) {
strcpy ( V_33 , V_34 ) ;
strcat ( V_33 , L_11 ) ;
} else {
strcpy ( V_33 , L_12 ) ;
F_3 ( L_16 , V_4 ) ;
}
V_35 = F_4 ( V_36 ,
0444 ,
V_3 ,
V_33 ,
& V_32 ) ;
if ( ! V_35 ) {
F_3 ( L_17 ,
V_4 ,
V_36 ) ;
goto V_5;
}
V_1 = 0 ;
V_5:
F_8 ( V_15 , L_15 , V_4 , V_1 ) ;
return V_1 ;
}
int F_18 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
int V_1 = - V_13 ;
F_8 ( V_15 ,
L_18 ,
V_4 ,
V_10 ) ;
if ( V_10 )
goto V_5;
V_1 = 0 ;
F_19 ( & V_37 ) ;
V_12 -> V_18 = V_11 -> V_20 ;
F_20 ( & V_37 ) ;
V_5:
F_8 ( V_15 ,
L_19 ,
V_1 ) ;
return V_1 ;
}
static T_2 F_21 ( struct V_12 * V_12 ,
char T_3 * V_38 ,
T_4 V_39 ,
T_1 * V_40 )
{
char * V_41 ;
int V_42 ;
T_2 V_43 = - V_2 ;
F_8 ( V_15 , L_20 ) ;
V_41 = F_22 ( V_28 , V_29 ) ;
if ( ! V_41 )
goto V_5;
F_19 ( & V_37 ) ;
V_42 = sprintf ( V_41 , L_21 , ( char * ) V_12 -> V_18 ) ;
F_20 ( & V_37 ) ;
V_43 = F_23 ( V_38 , V_39 , V_40 , V_41 , V_42 ) ;
F_24 ( V_41 ) ;
V_5:
F_8 ( V_15 ,
L_22 ,
V_43 ) ;
return V_43 ;
}
static T_2 F_25 ( struct V_12 * V_12 ,
const char T_3 * V_38 ,
T_4 V_39 ,
T_1 * V_40 )
{
char * V_41 ;
int V_1 = - V_44 ;
T_4 V_45 = 0 ;
char * V_46 ;
struct V_47 * V_48 = NULL ;
struct V_49 V_50 = { NULL , 0 , 0 } ;
F_8 ( V_15 ,
L_23 ,
V_12 -> V_51 . V_26 -> V_52 . V_53 ) ;
if ( V_39 > V_28 + 1 ) {
V_45 = V_39 ;
V_39 = V_28 + 1 ;
}
V_41 = F_16 ( V_28 , V_29 ) ;
if ( ! V_41 )
goto V_5;
if ( F_26 ( V_41 , V_38 , V_39 - 1 ) ) {
F_8 ( V_15 ,
L_24 ,
V_4 ) ;
goto V_5;
}
if ( ! strcmp ( V_12 -> V_51 . V_26 -> V_52 . V_53 ,
V_31 ) ) {
F_27 ( V_41 , & V_54 , 0 ) ;
F_28 ( & V_54 , 0 ) ;
V_46 = V_30 ;
F_8 ( V_15 ,
L_25 ,
V_30 ) ;
} else {
if ( F_29 () ) {
F_3 ( L_26 ,
V_4 ,
F_29 () ) ;
goto V_5;
}
F_27 ( V_41 , & V_50 , 1 ) ;
F_28 ( & V_50 , 1 ) ;
V_46 = V_34 ;
V_48 = F_30 ( V_55 ) ;
if ( ! V_48 ) {
F_3 ( L_27 , V_4 ) ;
goto V_5;
}
V_48 -> V_56 . V_57 . V_58 . V_59 =
V_60 ;
V_48 -> V_56 . V_57 . V_58 . type = V_61 ;
memset ( V_48 -> V_56 . V_57 . V_58 . V_62 ,
0 ,
V_28 ) ;
sprintf ( V_48 -> V_56 . V_57 . V_58 . V_62 ,
L_28 ,
V_50 . V_63 ,
V_50 . V_64 ) ;
V_1 = F_31 ( V_48 ,
L_29 ,
V_65 ) ;
if ( V_1 )
F_8 ( V_15 ,
L_30 ,
V_4 ,
V_1 ) ;
F_32 ( V_48 ) ;
}
F_19 ( & V_37 ) ;
memset ( V_12 -> V_66 -> V_20 , 0 , V_28 ) ;
sprintf ( ( char * ) V_12 -> V_66 -> V_20 , L_31 , V_46 ) ;
F_20 ( & V_37 ) ;
* V_40 += V_39 ;
if ( V_45 )
V_1 = V_45 ;
else
V_1 = V_39 ;
V_5:
F_8 ( V_15 ,
L_32 ,
V_1 ) ;
F_24 ( V_41 ) ;
return V_1 ;
}
