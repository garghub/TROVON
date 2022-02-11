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
static int F_16 ( struct V_9 * V_9 , struct V_10 * V_25 )
{
struct V_4 * V_5 = V_9 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_26 * V_27 = NULL ;
T_3 V_28 ;
int V_29 ;
if ( V_7 -> V_20 )
return - V_21 ;
V_29 = V_5 -> V_30 -> V_31 ( V_5 , V_7 -> V_8 , & V_28 ) ;
if ( V_29 )
return V_29 ;
if ( F_17 ( V_28 > V_32 ) ) {
V_29 = - V_33 ;
goto V_34;
}
if ( F_17 ( V_28 == 0 ) ) {
V_29 = - V_33 ;
goto V_34;
}
V_27 = F_18 ( V_24 , sizeof( * V_27 ) , V_35 ) ;
if ( ! V_27 ) {
V_29 = - V_36 ;
goto V_34;
}
F_10 ( & V_7 -> V_19 ) ;
V_7 -> V_27 = V_27 ;
V_7 -> V_28 = V_28 ;
V_7 -> V_20 = true ;
V_29 = F_19 ( V_7 -> V_37 ,
F_13 ( V_7 ) ,
V_7 -> V_19 ) ;
F_11 ( & V_7 -> V_19 ) ;
F_17 ( V_29 ) ;
return 0 ;
V_34:
V_5 -> V_30 -> V_31 ( V_5 , NULL , & V_28 ) ;
return V_29 ;
}
static int F_20 ( struct V_9 * V_9 , struct V_10 * V_25 )
{
struct V_4 * V_5 = V_25 -> V_38 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
T_3 V_28 ;
F_10 ( & V_7 -> V_19 ) ;
F_12 ( V_7 -> V_27 ) ;
V_7 -> V_27 = NULL ;
V_7 -> V_22 = 0 ;
V_7 -> V_23 = 0 ;
V_7 -> V_28 = 0 ;
V_7 -> V_20 = false ;
F_11 ( & V_7 -> V_19 ) ;
V_5 -> V_30 -> V_31 ( V_5 , NULL , & V_28 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_10 * V_25 , char T_2 * V_39 ,
T_3 V_40 , T_4 * V_41 )
{
struct V_4 * V_5 = V_25 -> V_38 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_26 * V_42 ;
char V_43 [ V_44 ] ;
int V_29 , V_45 ;
F_10 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_8 ) {
F_11 ( & V_7 -> V_19 ) ;
return 0 ;
}
while ( F_13 ( V_7 ) == 0 ) {
if ( V_25 -> V_46 & V_47 ) {
F_11 ( & V_7 -> V_19 ) ;
return - V_48 ;
}
V_29 = F_19 ( V_7 -> V_37 ,
F_13 ( V_7 ) ,
V_7 -> V_19 ) ;
if ( V_29 ) {
F_11 ( & V_7 -> V_19 ) ;
return V_29 ;
}
}
V_42 = & V_7 -> V_27 [ V_7 -> V_23 ] ;
if ( V_40 < F_22 ( V_7 -> V_28 ) ) {
F_11 ( & V_7 -> V_19 ) ;
return - V_33 ;
}
F_23 ( V_24 ) ;
V_7 -> V_23 = ( V_7 -> V_23 + 1 ) & ( V_24 - 1 ) ;
F_11 ( & V_7 -> V_19 ) ;
if ( V_42 -> V_49 )
sprintf ( V_43 , L_3 , V_42 -> V_50 ) ;
else
sprintf ( V_43 , L_4 ) ;
for ( V_45 = 0 ; V_45 < V_7 -> V_28 ; V_45 ++ )
sprintf ( V_43 + 10 + V_45 * 11 , L_5 , V_42 -> V_51 [ V_45 ] ) ;
sprintf ( V_43 + 10 + V_7 -> V_28 * 11 , L_6 ) ;
if ( F_24 ( V_39 , V_43 , F_22 ( V_7 -> V_28 ) ) )
return - V_52 ;
return F_22 ( V_7 -> V_28 ) ;
}
int F_25 ( struct V_4 * V_5 )
{
struct V_53 * V_54 , * V_55 ;
if ( ! V_5 -> V_30 -> V_31 )
return 0 ;
V_54 = F_26 ( L_7 , V_5 -> V_56 ) ;
if ( ! V_54 )
return - V_36 ;
V_55 = F_27 ( L_8 , V_57 , V_54 , V_5 ,
& V_58 ) ;
if ( ! V_55 )
goto error;
V_55 = F_27 ( L_9 , V_57 , V_54 , V_5 ,
& V_59 ) ;
if ( ! V_55 )
goto error;
return 0 ;
error:
F_28 ( V_54 ) ;
return - V_36 ;
}
int F_29 ( struct V_4 * V_5 , bool V_60 ,
T_5 V_50 , T_5 * V_51 )
{
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_26 * V_42 ;
int V_22 , V_23 ;
F_30 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_20 ) {
F_31 ( & V_7 -> V_19 ) ;
return - V_33 ;
}
V_22 = V_7 -> V_22 ;
V_23 = V_7 -> V_23 ;
if ( F_32 ( V_22 , V_23 , V_24 ) < 1 ) {
F_31 ( & V_7 -> V_19 ) ;
F_33 ( L_10 ) ;
return - V_61 ;
}
V_42 = & V_7 -> V_27 [ V_22 ] ;
V_42 -> V_50 = V_50 ;
V_42 -> V_49 = V_60 ;
memcpy ( & V_42 -> V_51 , V_51 , sizeof( * V_51 ) * V_7 -> V_28 ) ;
V_22 = ( V_22 + 1 ) & ( V_24 - 1 ) ;
V_7 -> V_22 = V_22 ;
F_31 ( & V_7 -> V_19 ) ;
F_34 ( & V_7 -> V_37 ) ;
return 0 ;
}
