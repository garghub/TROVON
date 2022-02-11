static
int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const char * V_5 , * V_6 ;
char V_7 [ V_8 ] ;
struct V_9 V_10 ;
unsigned V_11 ;
T_1 * V_12 = NULL ;
struct V_1 * V_13 ;
const char * V_14 ;
int V_15 = 0 ;
V_13 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_13 ) ;
snprintf ( V_7 , V_8 , L_1 ,
V_5 , V_16 ) ;
V_12 = fopen ( V_7 , L_2 ) ;
if ( ! V_12 )
return - 1 ;
V_15 = fread ( ( char * ) & V_10 , sizeof( V_10 ) , 1 , V_12 ) ;
if ( V_15 < 0 )
return - 1 ;
fclose ( V_12 ) ;
F_4 ( V_4 , & V_10 , V_17 ) ;
F_4 ( V_4 , & V_10 , V_18 ) ;
F_4 ( V_4 , & V_10 , V_19 ) ;
F_4 ( V_4 , & V_10 , V_20 ) ;
F_5 ( V_4 , & V_10 , V_21 ) ;
F_5 ( V_4 , & V_10 , V_22 ) ;
F_5 ( V_4 , & V_10 , V_23 ) ;
strncpy ( V_4 -> V_5 , V_5 , V_8 ) ;
V_4 -> V_14 = V_24 ;
V_14 = F_6 ( V_2 , L_3 ) ;
if ( V_14 ) {
for ( V_11 = 0 ; V_11 < F_7 ( V_25 ) ; V_11 ++ ) {
if ( ! strcmp ( V_25 [ V_11 ] . V_6 , V_14 ) ) {
V_4 -> V_14 = V_25 [ V_11 ] . V_14 ;
break;
}
}
}
V_4 -> V_26 = 0 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = 0 ;
V_6 = F_8 ( V_13 ) ;
strncpy ( V_4 -> V_29 , V_6 , V_30 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_4 )
{
const char * V_31 ;
V_31 = F_10 ( V_4 , L_4 ) ;
return V_31 != NULL && ! strcmp ( V_31 , V_32 ) ;
}
static int F_11 ( struct V_33 * V_34 )
{
int V_15 ;
V_34 -> V_35 = 0 ;
F_12 ( & V_34 -> V_36 ) ;
V_15 = F_13 ( V_34 ) ;
if ( V_15 )
F_14 ( L_5 V_37 L_6
V_32 L_7 ) ;
return V_15 ;
}
