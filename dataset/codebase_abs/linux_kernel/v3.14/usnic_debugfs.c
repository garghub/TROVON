static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
char V_6 [ 500 ] ;
int V_7 ;
if ( * V_5 > 0 )
return 0 ;
V_7 = F_2 ( V_6 , sizeof( V_6 ) ,
L_1
L_2 ,
V_8 , V_9 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
char * V_14 ;
char V_6 [ 512 ] ;
V_11 = V_2 -> V_15 ;
V_14 = V_6 ;
V_13 = V_4 ;
if ( * V_5 > 0 )
return 0 ;
F_5 ( & V_11 -> V_16 -> V_17 ) ;
V_12 = F_2 ( V_14 , V_13 ,
L_3 ,
V_11 -> V_16 -> V_18 ,
F_6 ( V_11 -> V_19 ) ) ;
F_7 ( V_12 , V_14 , V_13 ) ;
if ( V_11 -> V_19 == V_20 ) {
V_12 = F_2 ( V_14 , V_13 , L_4 ,
V_11 -> V_21 . V_22 ) ;
F_7 ( V_12 , V_14 , V_13 ) ;
} else if ( V_11 -> V_19 == V_23 ) {
V_12 = F_8 ( V_14 , V_13 ,
V_11 -> V_24 . V_25 ) ;
F_7 ( V_12 , V_14 , V_13 ) ;
V_12 = F_2 ( V_14 , V_13 , L_5 ) ;
F_7 ( V_12 , V_14 , V_13 ) ;
}
F_9 ( & V_11 -> V_16 -> V_17 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_6 , V_14 - V_6 ) ;
}
void F_10 ( void )
{
V_26 = F_11 ( V_27 , NULL ) ;
if ( F_12 ( V_26 ) ) {
F_13 ( L_6 ) ;
goto V_28;
}
V_29 = F_11 ( L_7 , V_26 ) ;
if ( F_14 ( V_29 ) ) {
F_13 ( L_8 ,
F_15 ( V_29 ) ) ;
goto V_30;
}
F_16 ( L_9 , V_31 , V_26 ,
NULL , & V_32 ) ;
return;
V_30:
F_17 ( V_26 ) ;
V_28:
V_26 = NULL ;
}
void F_18 ( void )
{
if ( ! V_26 )
return;
F_17 ( V_26 ) ;
V_26 = NULL ;
}
void F_19 ( struct V_10 * V_11 )
{
if ( F_14 ( V_29 ) )
return;
F_2 ( V_11 -> V_33 , sizeof( V_11 -> V_33 ) ,
L_10 , V_11 -> V_34 -> V_35 ) ;
V_11 -> V_36 = F_16 ( V_11 -> V_33 ,
V_31 ,
V_29 ,
V_11 ,
& V_37 ) ;
if ( F_14 ( V_11 -> V_36 ) ) {
F_13 ( L_11 ,
V_11 -> V_34 -> V_35 ) ;
}
}
void F_20 ( struct V_10 * V_11 )
{
if ( ! F_14 ( V_11 -> V_36 ) )
F_21 ( V_11 -> V_36 ) ;
}
