int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_1 type , char * V_8 ,
char * V_9 , char * V_10 , T_1 V_11 )
{
int V_12 ;
int V_13 = strlen ( V_7 ) ;
int V_14 = strlen ( V_8 ) ;
int V_15 = strlen ( V_9 ) ;
int V_16 = strlen ( V_10 ) ;
void * V_17 , * V_18 ;
struct V_19 * V_20 ;
struct V_21 V_22 ;
int V_23 ;
V_12 = V_13 + sizeof( V_24 ) +
V_14 + sizeof( V_24 ) +
V_15 + sizeof( V_24 ) +
V_16 + sizeof( V_24 ) +
sizeof( struct V_25 ) +
sizeof( T_1 ) + sizeof( T_1 ) +
V_26 ;
if ( V_12 > V_27 )
return - V_28 ;
V_20 = F_2 ( V_29 ) ;
if ( ! V_20 )
return - V_30 ;
V_17 = F_3 ( V_20 ) ;
V_18 = V_17 + V_12 ;
F_4 ( & V_17 , 1 , 1 ,
V_12 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_6 ( & V_17 , type ) ;
F_5 ( & V_17 , V_18 , V_8 , V_14 ) ;
F_5 ( & V_17 , V_18 , V_9 , V_15 ) ;
F_5 ( & V_17 , V_18 , V_10 , V_16 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_7 ( V_17 , & V_22 ) ;
V_17 += sizeof( struct V_25 ) ;
F_6 ( & V_17 , V_11 ) ;
F_8 ( L_1 ,
V_31 , V_7 , type , V_8 , V_9 , V_10 , V_11 ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_2 ,
V_32 , V_20 ,
V_12 , NULL , NULL ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
F_10 ( V_20 ) ;
return V_23 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , char * V_8 )
{
int V_33 ;
int V_13 = strlen ( V_7 ) ;
int V_14 = strlen ( V_8 ) ;
void * V_17 , * V_18 ;
struct V_19 * V_34 ;
int V_23 ;
V_33 = V_13 + sizeof( V_24 ) +
V_14 + sizeof( V_24 ) +
V_26 ;
if ( V_33 > V_27 )
return - V_28 ;
V_34 = F_2 ( V_29 ) ;
if ( ! V_34 )
return - V_30 ;
V_17 = F_3 ( V_34 ) ;
V_18 = V_17 + V_33 ;
F_4 ( & V_17 , 1 , 1 ,
V_33 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_5 ( & V_17 , V_18 , V_8 , V_14 ) ;
F_8 ( L_4 , V_31 , V_7 , V_8 ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_5 ,
V_32 , V_34 ,
V_33 , NULL , NULL ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
F_10 ( V_34 ) ;
return V_23 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , char * V_8 ,
struct V_35 * V_36 )
{
int V_37 ;
int V_13 = strlen ( V_7 ) ;
int V_14 = strlen ( V_8 ) ;
struct V_19 * V_38 ;
void * V_17 , * V_18 ;
int V_23 ;
V_37 = V_13 + sizeof( V_24 ) +
V_14 + sizeof( V_24 ) +
sizeof( T_1 ) + sizeof( V_39 ) +
V_26 ;
if ( V_37 > V_27 )
return - V_28 ;
V_38 = F_2 ( V_29 ) ;
if ( ! V_38 )
return - V_30 ;
V_17 = F_3 ( V_38 ) ;
V_18 = V_17 + V_37 ;
F_4 ( & V_17 , 1 , 1 ,
V_37 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_13 ( & V_17 , V_36 , sizeof( * V_36 ) ) ;
F_5 ( & V_17 , V_18 , V_8 , V_14 ) ;
F_8 ( L_6 , V_31 , V_7 ,
V_8 , F_14 ( * V_36 ) ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_7 ,
V_32 , V_38 ,
V_37 , NULL , NULL ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
F_10 ( V_38 ) ;
return V_23 ;
}
void F_15 ( struct V_40 * V_41 , T_2 V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
F_16 ( V_41 [ V_43 ] . V_44 . V_8 ) ;
F_16 ( V_41 ) ;
}
static int F_17 ( void * * V_17 , void * V_18 , struct V_40 * V_36 )
{
T_1 V_45 ;
T_2 V_46 ;
char * V_47 ;
int V_23 ;
V_23 = F_18 ( V_17 , V_18 , 1 , L_8 , & V_45 , & V_46 ) ;
if ( V_23 )
return V_23 ;
F_19 ( V_17 , & V_36 -> V_44 . V_48 , sizeof( V_36 -> V_44 . V_48 ) ) ;
V_47 = F_20 ( V_17 , V_18 , NULL , V_29 ) ;
if ( F_21 ( V_47 ) )
return F_22 ( V_47 ) ;
V_36 -> V_44 . V_8 = V_47 ;
V_23 = F_18 ( V_17 , V_18 , 1 , L_9 , & V_45 , & V_46 ) ;
if ( V_23 )
return V_23 ;
* V_17 += sizeof( struct V_25 ) ;
F_19 ( V_17 , & V_36 -> V_49 . V_50 , sizeof( V_36 -> V_49 . V_50 ) ) ;
F_23 ( & V_36 -> V_49 . V_50 ) ;
V_46 = F_24 ( V_17 ) ;
* V_17 += V_46 ;
F_8 ( L_10 , V_31 ,
F_14 ( V_36 -> V_44 . V_48 ) , V_36 -> V_44 . V_8 ,
F_25 ( & V_36 -> V_49 . V_50 . V_51 ) ) ;
return 0 ;
}
static int F_26 ( void * * V_17 , void * V_18 , T_1 * type , char * * V_9 ,
struct V_40 * * V_41 , T_2 * V_42 )
{
T_1 V_45 ;
T_2 V_52 ;
char * V_47 ;
int V_43 ;
int V_23 ;
V_23 = F_18 ( V_17 , V_18 , 1 , L_11 ,
& V_45 , & V_52 ) ;
if ( V_23 )
return V_23 ;
* V_42 = F_24 ( V_17 ) ;
* V_41 = F_27 ( * V_42 , sizeof( * * V_41 ) , V_29 ) ;
if ( ! * V_41 )
return - V_30 ;
for ( V_43 = 0 ; V_43 < * V_42 ; V_43 ++ ) {
V_23 = F_17 ( V_17 , V_18 , * V_41 + V_43 ) ;
if ( V_23 )
goto V_53;
}
* type = F_28 ( V_17 ) ;
V_47 = F_20 ( V_17 , V_18 , NULL , V_29 ) ;
if ( F_21 ( V_47 ) ) {
V_23 = F_22 ( V_47 ) ;
goto V_53;
}
* V_9 = V_47 ;
return 0 ;
V_53:
F_15 ( * V_41 , * V_42 ) ;
return V_23 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_1 * type , char * * V_9 ,
struct V_40 * * V_41 , T_2 * V_42 )
{
int V_54 ;
int V_13 = strlen ( V_7 ) ;
struct V_19 * V_55 , * V_56 ;
T_3 V_57 = V_27 ;
void * V_17 , * V_18 ;
int V_23 ;
V_54 = V_13 + sizeof( V_24 ) +
V_26 ;
if ( V_54 > V_27 )
return - V_28 ;
V_55 = F_2 ( V_29 ) ;
if ( ! V_55 )
return - V_30 ;
V_56 = F_2 ( V_29 ) ;
if ( ! V_56 ) {
F_10 ( V_55 ) ;
return - V_30 ;
}
V_17 = F_3 ( V_55 ) ;
V_18 = V_17 + V_54 ;
F_4 ( & V_17 , 1 , 1 ,
V_54 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_8 ( L_12 , V_31 , V_7 ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_13 ,
V_58 , V_55 ,
V_54 , V_56 , & V_57 ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
if ( V_23 >= 0 ) {
V_17 = F_3 ( V_56 ) ;
V_18 = V_17 + V_57 ;
V_23 = F_26 ( & V_17 , V_18 , type , V_9 , V_41 , V_42 ) ;
}
F_10 ( V_55 ) ;
F_10 ( V_56 ) ;
return V_23 ;
}
