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
static int F_13 ( struct V_9 * V_9 , struct V_10 * V_22 )
{
struct V_4 * V_5 = V_9 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_23 * V_24 = NULL ;
T_3 V_25 ;
int V_26 ;
if ( V_7 -> V_20 )
return - V_21 ;
V_26 = V_5 -> V_27 -> V_28 ( V_5 , V_7 -> V_8 , & V_25 ) ;
if ( V_26 )
return V_26 ;
if ( F_14 ( V_25 > V_29 ) ) {
V_26 = - V_30 ;
goto V_31;
}
if ( F_14 ( V_25 == 0 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_24 = F_15 ( V_32 , sizeof( * V_24 ) , V_33 ) ;
if ( ! V_24 ) {
V_26 = - V_34 ;
goto V_31;
}
F_10 ( & V_7 -> V_19 ) ;
V_7 -> V_24 = V_24 ;
V_7 -> V_25 = V_25 ;
V_7 -> V_20 = true ;
F_11 ( & V_7 -> V_19 ) ;
return 0 ;
V_31:
V_5 -> V_27 -> V_28 ( V_5 , NULL , & V_25 ) ;
return V_26 ;
}
static int F_16 ( struct V_9 * V_9 , struct V_10 * V_22 )
{
struct V_4 * V_5 = V_22 -> V_35 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
T_3 V_25 ;
F_10 ( & V_7 -> V_19 ) ;
F_12 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
V_7 -> V_36 = 0 ;
V_7 -> V_37 = 0 ;
V_7 -> V_25 = 0 ;
V_7 -> V_20 = false ;
F_11 ( & V_7 -> V_19 ) ;
V_5 -> V_27 -> V_28 ( V_5 , NULL , & V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_16 * V_7 )
{
F_18 ( & V_7 -> V_19 ) ;
return F_19 ( V_7 -> V_36 , V_7 -> V_37 , V_32 ) ;
}
static T_1 F_20 ( struct V_10 * V_22 , char T_2 * V_38 ,
T_3 V_39 , T_4 * V_40 )
{
struct V_4 * V_5 = V_22 -> V_35 -> V_11 ;
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_23 * V_41 ;
char V_42 [ V_43 ] ;
int V_26 , V_44 ;
F_10 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_8 ) {
F_11 ( & V_7 -> V_19 ) ;
return 0 ;
}
while ( F_17 ( V_7 ) == 0 ) {
if ( V_22 -> V_45 & V_46 ) {
F_11 ( & V_7 -> V_19 ) ;
return - V_47 ;
}
V_26 = F_21 ( V_7 -> V_48 ,
F_17 ( V_7 ) ,
V_7 -> V_19 ) ;
if ( V_26 ) {
F_11 ( & V_7 -> V_19 ) ;
return V_26 ;
}
}
V_41 = & V_7 -> V_24 [ V_7 -> V_37 ] ;
if ( V_39 < F_22 ( V_7 -> V_25 ) ) {
F_11 ( & V_7 -> V_19 ) ;
return - V_30 ;
}
F_23 ( V_32 ) ;
V_7 -> V_37 = ( V_7 -> V_37 + 1 ) & ( V_32 - 1 ) ;
F_11 ( & V_7 -> V_19 ) ;
if ( V_41 -> V_49 )
sprintf ( V_42 , L_3 , V_41 -> V_50 ) ;
else
sprintf ( V_42 , L_4 ) ;
for ( V_44 = 0 ; V_44 < V_7 -> V_25 ; V_44 ++ )
sprintf ( V_42 + 10 + V_44 * 11 , L_5 , V_41 -> V_51 [ V_44 ] ) ;
sprintf ( V_42 + 10 + V_7 -> V_25 * 11 , L_6 ) ;
if ( F_24 ( V_38 , V_42 , F_22 ( V_7 -> V_25 ) ) )
return - V_52 ;
return F_22 ( V_7 -> V_25 ) ;
}
int F_25 ( struct V_4 * V_5 )
{
struct V_53 * V_54 , * V_55 ;
if ( ! V_5 -> V_27 -> V_28 )
return 0 ;
V_54 = F_26 ( L_7 , V_5 -> V_56 ) ;
if ( ! V_54 )
return - V_34 ;
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
return - V_34 ;
}
int F_29 ( struct V_4 * V_5 , bool V_60 ,
T_5 V_50 , T_5 * V_51 )
{
struct V_16 * V_7 = & V_5 -> V_7 ;
struct V_23 * V_41 ;
int V_36 , V_37 ;
F_18 ( & V_7 -> V_19 ) ;
if ( ! V_7 -> V_20 )
return - V_30 ;
V_36 = V_7 -> V_36 ;
V_37 = V_7 -> V_37 ;
if ( F_30 ( V_36 , V_37 , V_32 ) < 1 ) {
F_31 ( L_10 ) ;
return - V_61 ;
}
V_41 = & V_7 -> V_24 [ V_36 ] ;
V_41 -> V_50 = V_50 ;
V_41 -> V_49 = V_60 ;
memcpy ( & V_41 -> V_51 , V_51 , sizeof( * V_51 ) * V_7 -> V_25 ) ;
V_36 = ( V_36 + 1 ) & ( V_32 - 1 ) ;
V_7 -> V_36 = V_36 ;
return 0 ;
}
