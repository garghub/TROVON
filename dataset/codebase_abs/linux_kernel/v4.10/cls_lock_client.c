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
V_32 | V_33 ,
V_20 , V_12 , NULL , NULL ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
F_10 ( V_20 ) ;
return V_23 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , char * V_8 )
{
int V_34 ;
int V_13 = strlen ( V_7 ) ;
int V_14 = strlen ( V_8 ) ;
void * V_17 , * V_18 ;
struct V_19 * V_35 ;
int V_23 ;
V_34 = V_13 + sizeof( V_24 ) +
V_14 + sizeof( V_24 ) +
V_26 ;
if ( V_34 > V_27 )
return - V_28 ;
V_35 = F_2 ( V_29 ) ;
if ( ! V_35 )
return - V_30 ;
V_17 = F_3 ( V_35 ) ;
V_18 = V_17 + V_34 ;
F_4 ( & V_17 , 1 , 1 ,
V_34 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_5 ( & V_17 , V_18 , V_8 , V_14 ) ;
F_8 ( L_4 , V_31 , V_7 , V_8 ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_5 ,
V_32 | V_33 ,
V_35 , V_34 , NULL , NULL ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
F_10 ( V_35 ) ;
return V_23 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , char * V_8 ,
struct V_36 * V_37 )
{
int V_38 ;
int V_13 = strlen ( V_7 ) ;
int V_14 = strlen ( V_8 ) ;
struct V_19 * V_39 ;
void * V_17 , * V_18 ;
int V_23 ;
V_38 = V_13 + sizeof( V_24 ) +
V_14 + sizeof( V_24 ) +
sizeof( T_1 ) + sizeof( V_40 ) +
V_26 ;
if ( V_38 > V_27 )
return - V_28 ;
V_39 = F_2 ( V_29 ) ;
if ( ! V_39 )
return - V_30 ;
V_17 = F_3 ( V_39 ) ;
V_18 = V_17 + V_38 ;
F_4 ( & V_17 , 1 , 1 ,
V_38 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_13 ( & V_17 , V_37 , sizeof( * V_37 ) ) ;
F_5 ( & V_17 , V_18 , V_8 , V_14 ) ;
F_8 ( L_6 , V_31 , V_7 ,
V_8 , F_14 ( * V_37 ) ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_7 ,
V_32 | V_33 ,
V_39 , V_38 , NULL , NULL ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
F_10 ( V_39 ) ;
return V_23 ;
}
void F_15 ( struct V_41 * V_42 , T_2 V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ )
F_16 ( V_42 [ V_44 ] . V_45 . V_8 ) ;
F_16 ( V_42 ) ;
}
static int F_17 ( void * * V_17 , void * V_18 , struct V_41 * V_37 )
{
T_1 V_46 ;
T_2 V_47 ;
char * V_48 ;
int V_23 ;
V_23 = F_18 ( V_17 , V_18 , 1 , L_8 , & V_46 , & V_47 ) ;
if ( V_23 )
return V_23 ;
F_19 ( V_17 , & V_37 -> V_45 . V_49 , sizeof( V_37 -> V_45 . V_49 ) ) ;
V_48 = F_20 ( V_17 , V_18 , NULL , V_29 ) ;
if ( F_21 ( V_48 ) )
return F_22 ( V_48 ) ;
V_37 -> V_45 . V_8 = V_48 ;
V_23 = F_18 ( V_17 , V_18 , 1 , L_9 , & V_46 , & V_47 ) ;
if ( V_23 )
return V_23 ;
* V_17 += sizeof( struct V_25 ) ;
F_19 ( V_17 , & V_37 -> V_50 . V_51 , sizeof( V_37 -> V_50 . V_51 ) ) ;
F_23 ( & V_37 -> V_50 . V_51 ) ;
V_47 = F_24 ( V_17 ) ;
* V_17 += V_47 ;
F_8 ( L_10 , V_31 ,
F_14 ( V_37 -> V_45 . V_49 ) , V_37 -> V_45 . V_8 ,
F_25 ( & V_37 -> V_50 . V_51 . V_52 ) ) ;
return 0 ;
}
static int F_26 ( void * * V_17 , void * V_18 , T_1 * type , char * * V_9 ,
struct V_41 * * V_42 , T_2 * V_43 )
{
T_1 V_46 ;
T_2 V_53 ;
char * V_48 ;
int V_44 ;
int V_23 ;
V_23 = F_18 ( V_17 , V_18 , 1 , L_11 ,
& V_46 , & V_53 ) ;
if ( V_23 )
return V_23 ;
* V_43 = F_24 ( V_17 ) ;
* V_42 = F_27 ( * V_43 , sizeof( * * V_42 ) , V_29 ) ;
if ( ! * V_42 )
return - V_30 ;
for ( V_44 = 0 ; V_44 < * V_43 ; V_44 ++ ) {
V_23 = F_17 ( V_17 , V_18 , * V_42 + V_44 ) ;
if ( V_23 )
goto V_54;
}
* type = F_28 ( V_17 ) ;
V_48 = F_20 ( V_17 , V_18 , NULL , V_29 ) ;
if ( F_21 ( V_48 ) ) {
V_23 = F_22 ( V_48 ) ;
goto V_54;
}
* V_9 = V_48 ;
return 0 ;
V_54:
F_15 ( * V_42 , * V_43 ) ;
return V_23 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_1 * type , char * * V_9 ,
struct V_41 * * V_42 , T_2 * V_43 )
{
int V_55 ;
int V_13 = strlen ( V_7 ) ;
struct V_19 * V_56 , * V_57 ;
T_3 V_58 ;
void * V_17 , * V_18 ;
int V_23 ;
V_55 = V_13 + sizeof( V_24 ) +
V_26 ;
if ( V_55 > V_27 )
return - V_28 ;
V_56 = F_2 ( V_29 ) ;
if ( ! V_56 )
return - V_30 ;
V_57 = F_2 ( V_29 ) ;
if ( ! V_57 ) {
F_10 ( V_56 ) ;
return - V_30 ;
}
V_17 = F_3 ( V_56 ) ;
V_18 = V_17 + V_55 ;
F_4 ( & V_17 , 1 , 1 ,
V_55 - V_26 ) ;
F_5 ( & V_17 , V_18 , V_7 , V_13 ) ;
F_8 ( L_12 , V_31 , V_7 ) ;
V_23 = F_9 ( V_2 , V_4 , V_6 , L_2 , L_13 ,
V_59 , V_56 ,
V_55 , V_57 , & V_58 ) ;
F_8 ( L_3 , V_31 , V_23 ) ;
if ( V_23 >= 0 ) {
V_17 = F_3 ( V_57 ) ;
V_18 = V_17 + V_58 ;
V_23 = F_26 ( & V_17 , V_18 , type , V_9 , V_42 , V_43 ) ;
}
F_10 ( V_56 ) ;
F_10 ( V_57 ) ;
return V_23 ;
}
