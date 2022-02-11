static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( ! strncmp ( V_3 -> V_4 , L_1 , 16 ) ) {
F_2 ( & V_3 -> V_5 , L_2 ,
V_6 . type , V_6 . V_7 ) ;
return F_3 ( V_3 , & V_6 ) ;
}
return NULL ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_7 ,
unsigned short V_8 , char V_9 , T_2 V_10 ,
int V_11 , union V_12 * V_13 )
{
struct V_14 * V_14 = V_3 -> V_15 ;
struct V_16 * V_17 = F_5 ( V_14 ) ;
char * V_18 ;
V_18 = V_17 -> V_19 ;
if ( V_7 != V_17 -> V_7 )
V_18 += sprintf ( V_18 , L_3 , V_7 ) ;
switch ( V_11 ) {
case V_20 :
if ( V_9 == V_21 )
sprintf ( V_18 , L_4 , V_10 ) ;
else
sprintf ( V_18 , L_5 ) ;
break;
case V_22 :
if ( V_9 == V_21 )
sprintf ( V_18 , L_6 , V_10 , V_13 -> V_23 ) ;
else
sprintf ( V_18 , L_7 , V_10 ) ;
break;
default:
F_6 ( & V_3 -> V_5 , L_8 , V_11 ) ;
return - V_24 ;
}
F_7 ( & V_3 -> V_5 , L_9 , V_17 -> V_19 ) ;
for ( V_18 = V_17 -> V_19 ; * V_18 ; V_18 ++ )
F_8 ( V_14 , * V_18 ) ;
V_17 -> V_7 = V_7 ;
V_17 -> V_25 = 0 ;
V_17 -> V_26 = V_27 ;
F_8 ( V_14 , V_9 == V_21 ? '>' : '<' ) ;
F_9 ( V_28 , V_17 -> V_26 == V_29 ,
F_10 ( 150 ) ) ;
if ( V_17 -> V_26 != V_29
|| V_17 -> V_25 != 5 ) {
F_11 ( & V_3 -> V_5 , L_10 ,
V_17 -> V_25 ) ;
return - V_30 ;
}
F_7 ( & V_3 -> V_5 , L_11 , V_17 -> V_19 ) ;
V_18 = V_17 -> V_19 + 1 ;
V_18 [ 3 ] = '\0' ;
if ( ! strcmp ( V_18 , L_12 ) )
return - V_31 ;
if ( V_9 == V_21 ) {
if ( ! strcmp ( V_18 , L_13 ) )
return 0 ;
} else {
if ( V_18 [ 0 ] == 'x' ) {
if ( F_12 ( V_18 + 1 , 16 , & V_13 -> V_23 ) )
return - V_32 ;
return 0 ;
}
}
return - V_30 ;
}
static T_3 F_13 ( struct V_2 * V_3 )
{
return V_33 | V_34 ;
}
static T_4 F_14 ( struct V_14 * V_14 , unsigned char V_13 ,
unsigned int V_8 )
{
struct V_16 * V_17 = F_5 ( V_14 ) ;
switch ( V_17 -> V_26 ) {
case V_35 :
V_17 -> V_19 [ V_17 -> V_25 ++ ] = V_13 ;
if ( V_13 == ':'
|| V_17 -> V_25 == V_36 - 1 ) {
V_17 -> V_19 [ V_17 -> V_25 ] = '\0' ;
V_17 -> V_26 = V_29 ;
F_15 ( & V_28 ) ;
}
break;
case V_37 :
V_17 -> V_26 = V_29 ;
F_15 ( & V_28 ) ;
break;
case V_27 :
V_17 -> V_19 [ V_17 -> V_25 ++ ] = V_13 ;
if ( V_13 == ']' ) {
V_17 -> V_19 [ V_17 -> V_25 ] = '\0' ;
V_17 -> V_26 = V_29 ;
F_15 ( & V_28 ) ;
}
break;
}
return V_38 ;
}
static char * F_16 ( char * V_19 )
{
char * V_39 , * V_40 ;
V_39 = strstr ( V_19 , L_14 ) ;
if ( ! V_39 )
return NULL ;
V_40 = strchr ( V_39 , '\r' ) ;
if ( ! V_40 )
return NULL ;
* V_40 = '\0' ;
return V_39 ;
}
static int F_17 ( struct V_14 * V_14 , struct V_41 * V_42 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 ;
char * V_4 ;
int V_43 ;
V_17 = F_18 ( sizeof( struct V_16 ) , V_44 ) ;
if ( ! V_17 ) {
V_43 = - V_45 ;
goto exit;
}
V_17 -> V_26 = V_35 ;
F_19 ( V_14 , V_17 ) ;
V_43 = F_20 ( V_14 , V_42 ) ;
if ( V_43 )
goto V_46;
V_3 = & V_17 -> V_3 ;
V_3 -> V_47 = V_48 ;
V_3 -> V_49 = & V_50 ;
V_3 -> V_15 = V_14 ;
V_3 -> V_5 . V_51 = & V_14 -> V_5 ;
F_8 ( V_14 , V_52 ) ;
F_9 ( V_28 , V_17 -> V_26 == V_29 ,
F_10 ( 2000 ) ) ;
if ( V_17 -> V_26 != V_29 ) {
V_43 = - V_31 ;
F_11 ( & V_14 -> V_5 , L_15
L_16 , V_17 -> V_26 , V_17 -> V_25 ) ;
goto V_53;
}
V_4 = F_16 ( V_17 -> V_19 ) ;
if ( ! V_4 ) {
V_43 = - V_31 ;
F_11 ( & V_14 -> V_5 , L_17 ) ;
goto V_53;
}
F_21 ( V_3 -> V_4 , V_4 , sizeof( V_3 -> V_4 ) ) ;
V_17 -> V_26 = V_37 ;
F_8 ( V_14 , V_54 ) ;
F_9 ( V_28 , V_17 -> V_26 == V_29 ,
F_10 ( 250 ) ) ;
if ( V_17 -> V_26 != V_29 ) {
V_43 = - V_31 ;
F_11 ( & V_14 -> V_5 , L_18
L_19 , V_17 -> V_26 ) ;
goto V_53;
}
V_43 = F_22 ( V_3 ) ;
if ( V_43 )
goto V_53;
F_2 ( & V_14 -> V_5 , L_20 ) ;
V_17 -> V_55 = F_1 ( V_3 ) ;
return 0 ;
V_53:
F_23 ( V_14 ) ;
V_46:
F_24 ( V_17 ) ;
exit:
return V_43 ;
}
static void F_25 ( struct V_14 * V_14 )
{
struct V_16 * V_17 = F_5 ( V_14 ) ;
if ( V_17 -> V_55 )
F_26 ( V_17 -> V_55 ) ;
F_27 ( & V_17 -> V_3 ) ;
F_23 ( V_14 ) ;
F_24 ( V_17 ) ;
F_2 ( & V_14 -> V_5 , L_21 ) ;
}
