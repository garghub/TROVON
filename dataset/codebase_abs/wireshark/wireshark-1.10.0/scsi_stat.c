static char *
F_1 ( T_1 * V_1 )
{
char * V_2 ;
char * V_3 ;
V_2 = F_2 ( & V_4 ) ;
V_3 = F_3 ( L_1 ,
V_1 -> V_5 , V_2 ) ;
F_4 ( V_2 ) ;
return V_3 ;
}
static void
F_5 ( T_1 * V_1 )
{
char * V_3 ;
V_3 = F_1 ( V_1 ) ;
F_6 ( F_7 ( V_1 -> V_6 ) , V_3 ) ;
F_4 ( V_3 ) ;
}
static void
F_8 ( void * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 ;
F_9 ( & V_1 -> V_8 ) ;
F_5 ( V_1 ) ;
}
static int
F_10 ( void * V_7 , T_2 * V_9 , T_3 * T_4 V_10 , const void * V_11 )
{
T_1 * V_1 = ( T_1 * ) V_7 ;
const T_5 * V_12 = ( const T_5 * ) V_11 ;
if( V_12 -> type != V_13 ) {
return 0 ;
}
if( ( ! V_12 -> V_14 ) || ( ( V_12 -> V_14 -> V_15 & V_16 ) != V_1 -> V_15 ) ) {
return 0 ;
}
if( ( ! V_12 -> V_17 ) || ( V_12 -> V_17 -> V_18 > 255 ) ) {
return 0 ;
}
F_11 ( & V_1 -> V_8 , V_12 -> V_17 -> V_18 , & V_12 -> V_17 -> V_19 , V_9 ) ;
return 1 ;
}
static void
F_12 ( void * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 ;
F_13 ( & V_1 -> V_8 ) ;
}
static void
F_14 ( T_6 * V_6 V_10 , T_7 V_20 )
{
T_1 * V_1 = ( T_1 * ) V_20 ;
F_15 ( V_1 ) ;
F_16 ( & V_1 -> V_8 ) ;
F_4 ( V_1 ) ;
}
static void
F_17 ( const char * V_21 , void * T_8 V_10 )
{
T_1 * V_1 ;
T_9 V_22 ;
char * V_23 ;
char * V_24 ;
T_10 * V_25 ;
T_10 * V_26 ;
T_10 * V_27 ;
T_10 * V_28 ;
T_10 * V_29 ;
int V_30 , V_31 ;
const char * V_32 = NULL ;
T_11 * V_33 ;
const char * V_34 = NULL ;
V_31 = 0 ;
if( sscanf ( V_21 , L_2 , & V_30 , & V_31 ) == 1 ) {
if( V_31 ) {
V_32 = V_21 + V_31 ;
} else {
V_32 = NULL ;
}
} else {
fprintf ( V_35 , L_3 ) ;
exit ( 1 ) ;
}
V_36 = V_30 ;
V_1 = ( T_1 * ) F_18 ( sizeof( T_1 ) ) ;
V_1 -> V_15 = V_30 ;
switch( V_30 ) {
case V_37 :
V_1 -> V_5 = L_4 ;
V_1 -> V_38 = V_39 ;
V_34 = L_5 ;
break;
case V_40 :
V_1 -> V_5 = L_6 ;
V_1 -> V_38 = V_41 ;
V_34 = L_7 ;
break;
case V_42 :
V_1 -> V_5 = L_8 ;
V_1 -> V_38 = V_43 ;
V_34 = L_9 ;
break;
case V_44 :
V_1 -> V_5 = L_10 ;
V_1 -> V_38 = V_45 ;
V_34 = L_11 ;
break;
case V_46 :
V_1 -> V_5 = L_12 ;
V_1 -> V_38 = V_47 ;
V_34 = L_13 ;
break;
}
V_1 -> V_6 = F_19 ( L_14 ) ;
F_20 ( F_7 ( V_1 -> V_6 ) , TRUE ) ;
F_21 ( F_7 ( V_1 -> V_6 ) , 550 , 400 ) ;
F_5 ( V_1 ) ;
V_25 = F_22 ( V_48 , 3 , FALSE ) ;
F_23 ( F_24 ( V_1 -> V_6 ) , V_25 ) ;
F_25 ( F_24 ( V_25 ) , 12 ) ;
V_23 = F_1 ( V_1 ) ;
V_26 = F_26 ( V_23 ) ;
F_4 ( V_23 ) ;
F_27 ( F_28 ( V_25 ) , V_26 , FALSE , FALSE , 0 ) ;
V_24 = F_3 ( L_15 , V_32 ? V_32 : L_16 ) ;
V_27 = F_26 ( V_24 ) ;
F_4 ( V_24 ) ;
F_29 ( F_30 ( V_27 ) , TRUE ) ;
F_27 ( F_28 ( V_25 ) , V_27 , FALSE , FALSE , 0 ) ;
F_31 ( V_1 -> V_6 ) ;
F_32 ( & V_1 -> V_8 , 256 , V_25 , V_34 ) ;
for( V_22 = 0 ; V_22 < 256 ; V_22 ++ ) {
F_33 ( & V_1 -> V_8 , V_22 , F_34 ( V_22 , V_1 -> V_38 , L_17 ) ) ;
}
V_33 = F_35 ( L_18 , V_1 , V_32 , 0 , F_8 , F_10 , F_12 ) ;
if( V_33 ) {
F_36 ( V_49 , V_50 , L_19 , V_33 -> V_51 ) ;
F_37 ( V_33 , TRUE ) ;
F_16 ( & V_1 -> V_8 ) ;
F_4 ( V_1 ) ;
return;
}
V_28 = F_38 ( V_52 , NULL ) ;
F_39 ( F_28 ( V_25 ) , V_28 , FALSE , FALSE , 0 ) ;
V_29 = ( T_10 * ) F_40 ( F_41 ( V_28 ) , V_52 ) ;
F_42 ( V_1 -> V_6 , V_29 , V_53 ) ;
F_43 ( V_1 -> V_6 , L_20 , F_44 ( V_54 ) , NULL ) ;
F_43 ( V_1 -> V_6 , L_21 , F_44 ( F_14 ) , V_1 ) ;
F_31 ( V_1 -> V_6 ) ;
F_45 ( V_1 -> V_6 ) ;
F_46 ( & V_4 ) ;
F_47 ( F_48 ( V_1 -> V_6 ) ) ;
}
void
F_49 ( void )
{
F_50 ( & V_55 , L_22 ,
V_56 ) ;
}
void F_51 ( T_12 * V_57 , T_7 T_13 V_10 )
{
F_52 ( V_57 , & V_55 ) ;
}
