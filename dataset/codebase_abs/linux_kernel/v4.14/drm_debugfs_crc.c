static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_2 , L_1 , V_5 -> V_7 . V_8 ) ;
return 0 ;
}
static int F_3 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_4 * V_5 = V_9 -> V_11 ;
return F_4 ( V_10 , F_1 , V_5 ) ;
}
static T_1 F_5 ( struct V_10 * V_10 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_1 * V_2 = V_10 -> V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
char * V_8 ;
if ( V_13 == 0 )
return 0 ;
if ( V_13 > V_17 - 1 ) {
F_6 ( L_2 ,
V_17 ) ;
return - V_18 ;
}
V_8 = F_7 ( V_12 , V_13 ) ;
if ( F_8 ( V_8 ) )
return F_9 ( V_8 ) ;
if ( V_8 [ V_13 ] == '\n' )
V_8 [ V_13 ] = '\0' ;
F_10 ( & V_7 -> V_19 ) ;
if ( V_7 -> V_20 ) {
F_11 ( & V_7 -> V_19 ) ;
F_12 ( V_8 ) ;
return - V_21 ;
}
F_12 ( V_7 -> V_8 ) ;
V_7 -> V_8 = V_8 ;
F_11 ( & V_7 -> V_19 ) ;
* V_14 += V_13 ;
return V_13 ;
}
static int F_13 ( struct V_16 * V_7 )
{
F_14 ( & V_7 -> V_19 ) ;
return F_15 ( V_7 -> V_22 , V_7 -> V_23 , V_24 ) ;
}
static void F_16 ( struct V_16 * V_7 )
{
F_12 ( V_7 -> V_25 ) ;
V_7 -> V_25 = NULL ;
V_7 -> V_22 = 0 ;
V_7 -> V_23 = 0 ;
V_7 -> V_26 = 0 ;
V_7 -> V_20 = false ;
}
static int F_17 ( struct V_9 * V_9 , struct V_10 * V_27 )
{
struct V_4 * V_5 = V_9 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_28 * V_25 = NULL ;
T_3 V_26 ;
int V_29 = 0 ;
if ( F_18 ( V_5 -> V_30 ) ) {
V_29 = F_19 ( & V_5 -> V_31 , NULL ) ;
if ( V_29 )
return V_29 ;
if ( ! V_5 -> V_32 -> V_33 )
V_29 = - V_34 ;
F_20 ( & V_5 -> V_31 ) ;
if ( V_29 )
return V_29 ;
}
F_10 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_20 )
V_7 -> V_20 = true ;
else
V_29 = - V_21 ;
F_11 ( & V_7 -> V_19 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_5 -> V_35 -> V_36 ( V_5 , V_7 -> V_8 , & V_26 ) ;
if ( V_29 )
goto V_37;
if ( F_21 ( V_26 > V_38 ) ) {
V_29 = - V_39 ;
goto V_40;
}
if ( F_21 ( V_26 == 0 ) ) {
V_29 = - V_39 ;
goto V_40;
}
V_25 = F_22 ( V_24 , sizeof( * V_25 ) , V_41 ) ;
if ( ! V_25 ) {
V_29 = - V_42 ;
goto V_40;
}
F_10 ( & V_7 -> V_19 ) ;
V_7 -> V_25 = V_25 ;
V_7 -> V_26 = V_26 ;
V_29 = F_23 ( V_7 -> V_43 ,
F_13 ( V_7 ) ,
V_7 -> V_19 ) ;
F_11 ( & V_7 -> V_19 ) ;
if ( V_29 )
goto V_40;
return 0 ;
V_40:
V_5 -> V_35 -> V_36 ( V_5 , NULL , & V_26 ) ;
V_37:
F_10 ( & V_7 -> V_19 ) ;
F_16 ( V_7 ) ;
F_11 ( & V_7 -> V_19 ) ;
return V_29 ;
}
static int F_24 ( struct V_9 * V_9 , struct V_10 * V_27 )
{
struct V_4 * V_5 = V_27 -> V_44 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
T_3 V_26 ;
V_5 -> V_35 -> V_36 ( V_5 , NULL , & V_26 ) ;
F_10 ( & V_7 -> V_19 ) ;
F_16 ( V_7 ) ;
F_11 ( & V_7 -> V_19 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_10 * V_27 , char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_4 * V_5 = V_27 -> V_44 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_28 * V_48 ;
char V_49 [ V_50 ] ;
int V_29 , V_51 ;
F_10 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_8 ) {
F_11 ( & V_7 -> V_19 ) ;
return 0 ;
}
while ( F_13 ( V_7 ) == 0 ) {
if ( V_27 -> V_52 & V_53 ) {
F_11 ( & V_7 -> V_19 ) ;
return - V_54 ;
}
V_29 = F_23 ( V_7 -> V_43 ,
F_13 ( V_7 ) ,
V_7 -> V_19 ) ;
if ( V_29 ) {
F_11 ( & V_7 -> V_19 ) ;
return V_29 ;
}
}
V_48 = & V_7 -> V_25 [ V_7 -> V_23 ] ;
if ( V_46 < F_26 ( V_7 -> V_26 ) ) {
F_11 ( & V_7 -> V_19 ) ;
return - V_39 ;
}
F_27 ( V_24 ) ;
V_7 -> V_23 = ( V_7 -> V_23 + 1 ) & ( V_24 - 1 ) ;
F_11 ( & V_7 -> V_19 ) ;
if ( V_48 -> V_55 )
sprintf ( V_49 , L_3 , V_48 -> V_56 ) ;
else
sprintf ( V_49 , L_4 ) ;
for ( V_51 = 0 ; V_51 < V_7 -> V_26 ; V_51 ++ )
sprintf ( V_49 + 10 + V_51 * 11 , L_5 , V_48 -> V_57 [ V_51 ] ) ;
sprintf ( V_49 + 10 + V_7 -> V_26 * 11 , L_6 ) ;
if ( F_28 ( V_45 , V_49 , F_26 ( V_7 -> V_26 ) ) )
return - V_58 ;
return F_26 ( V_7 -> V_26 ) ;
}
int F_29 ( struct V_4 * V_5 )
{
struct V_59 * V_60 , * V_61 ;
if ( ! V_5 -> V_35 -> V_36 )
return 0 ;
V_60 = F_30 ( L_7 , V_5 -> V_62 ) ;
if ( ! V_60 )
return - V_42 ;
V_61 = F_31 ( L_8 , V_63 , V_60 , V_5 ,
& V_64 ) ;
if ( ! V_61 )
goto error;
V_61 = F_31 ( L_9 , V_63 , V_60 , V_5 ,
& V_65 ) ;
if ( ! V_61 )
goto error;
return 0 ;
error:
F_32 ( V_60 ) ;
return - V_42 ;
}
int F_33 ( struct V_4 * V_5 , bool V_66 ,
T_5 V_56 , T_5 * V_57 )
{
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_28 * V_48 ;
int V_22 , V_23 ;
F_34 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_25 ) {
F_35 ( & V_7 -> V_19 ) ;
return - V_39 ;
}
V_22 = V_7 -> V_22 ;
V_23 = V_7 -> V_23 ;
if ( F_36 ( V_22 , V_23 , V_24 ) < 1 ) {
F_35 ( & V_7 -> V_19 ) ;
F_37 ( L_10 ) ;
return - V_67 ;
}
V_48 = & V_7 -> V_25 [ V_22 ] ;
V_48 -> V_56 = V_56 ;
V_48 -> V_55 = V_66 ;
memcpy ( & V_48 -> V_57 , V_57 , sizeof( * V_57 ) * V_7 -> V_26 ) ;
V_22 = ( V_22 + 1 ) & ( V_24 - 1 ) ;
V_7 -> V_22 = V_22 ;
F_35 ( & V_7 -> V_19 ) ;
F_38 ( & V_7 -> V_43 ) ;
return 0 ;
}
