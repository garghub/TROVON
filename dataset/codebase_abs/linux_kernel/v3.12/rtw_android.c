int F_1 ( char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( 0 == F_2 ( V_1 , V_4 [ V_2 ] ,
strlen ( V_4 [ V_2 ] ) ) )
break;
return V_2 ;
}
static int F_3 ( struct V_5 * V_6 , char * V_7 ,
int V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) F_4 ( V_6 ) ;
struct V_11 * V_12 = & ( V_10 -> V_13 ) ;
struct V_14 * V_15 = & V_12 -> V_16 ;
int V_17 = 0 ;
if ( F_5 ( V_12 , V_18 ) ) {
V_17 += snprintf ( & V_7 [ V_17 ] , V_8 ,
L_1 ,
V_15 -> V_19 . V_20 . V_20 ,
V_10 -> V_21 . V_22 ) ;
}
return V_17 ;
}
static int F_6 ( struct V_5 * V_6 , char * V_7 ,
int V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) F_4 ( V_6 ) ;
int V_17 ;
T_1 V_23 ;
V_23 = F_7 ( V_10 ) / 10 ;
V_17 = snprintf ( V_7 , V_8 , L_2 ,
V_23 ) ;
return V_17 ;
}
static int F_8 ( struct V_5 * V_6 , char * V_7 ,
int V_8 )
{
int V_17 ;
V_17 = snprintf ( V_7 , V_8 , L_3 ,
V_6 -> V_24 ) ;
return V_17 ;
}
static int F_9 ( struct V_5 * V_6 , char * V_7 ,
int V_8 )
{
struct V_9 * V_9 = (struct V_9 * ) F_4 ( V_6 ) ;
char * V_25 = V_7 + strlen ( V_4 [ V_26 ] ) + 1 ;
int V_27 ;
V_27 = F_10 ( V_9 , V_25 ) ;
return ( V_27 == V_28 ) ? 0 : - 1 ;
}
static int F_11 ( struct V_5 * V_6 , char * V_7 ,
int V_8 )
{
memcpy ( V_7 , V_6 -> V_24 , V_29 ) ;
return V_29 ;
}
static int F_12 ( struct V_5 * V_6 , char * V_7 ,
int V_8 )
{
return 0 ;
}
int F_13 ( struct V_5 * V_6 , struct V_30 * V_31 , int V_32 )
{
int V_27 = 0 ;
char * V_7 = NULL ;
int V_2 ;
int V_17 = 0 ;
struct V_33 V_34 ;
F_14 () ;
if ( ! V_31 -> V_35 ) {
V_27 = - V_36 ;
goto exit;
}
if ( F_15 ( & V_34 , V_31 -> V_35 ,
sizeof( struct V_33 ) ) ) {
V_27 = - V_37 ;
goto exit;
}
V_7 = F_16 ( V_34 . V_8 , V_38 ) ;
if ( ! V_7 ) {
F_17 ( L_4 , V_39 ) ;
V_27 = - V_40 ;
goto exit;
}
if ( ! F_18 ( V_41 , V_34 . V_42 , V_34 . V_8 ) ) {
F_17 ( L_5 , V_39 ) ;
V_27 = - V_37 ;
goto exit;
}
if ( F_15 ( V_7 , ( char V_43 * ) V_34 . V_42 ,
V_34 . V_8 ) ) {
V_27 = - V_37 ;
goto exit;
}
F_17 ( L_6 ,
V_39 , V_7 , V_31 -> V_44 ) ;
V_2 = F_1 ( V_7 ) ;
switch ( V_2 ) {
case V_45 :
goto V_46;
case V_47 :
goto V_46;
}
if ( ! V_48 ) {
F_17 ( L_7 ,
V_39 , V_7 , V_31 -> V_44 ) ;
V_27 = 0 ;
goto exit;
}
switch ( V_2 ) {
case V_49 :
break;
case V_50 :
break;
case V_51 :
break;
case V_52 :
V_17 = F_3 ( V_6 , V_7 ,
V_34 . V_8 ) ;
break;
case V_53 :
V_17 = F_6 ( V_6 , V_7 ,
V_34 . V_8 ) ;
break;
case V_54 :
V_17 = F_8 ( V_6 , V_7 ,
V_34 . V_8 ) ;
break;
case V_55 :
V_17 = F_12 ( V_6 , V_7 ,
V_34 . V_8 ) ;
break;
case V_56 :
break;
case V_57 :
break;
case V_58 :
break;
case V_59 :
break;
case V_60 :
break;
case V_61 :
break;
case V_62 :
break;
case V_63 :
break;
case V_64 :
break;
case V_65 :
break;
case V_26 :
V_17 = F_9 ( V_6 , V_7 ,
V_34 . V_8 ) ;
break;
case V_66 :
V_17 = F_11 ( V_6 , V_7 ,
V_34 . V_8 ) ;
break;
case V_67 :
break;
case V_68 :
break;
case V_69 :
break;
default:
F_17 ( L_8 , V_7 ) ;
snprintf ( V_7 , 3 , L_9 ) ;
V_17 = strlen ( L_9 ) ;
}
V_46:
if ( V_17 >= 0 ) {
if ( ( V_17 == 0 ) && ( V_34 . V_8 > 0 ) )
V_7 [ 0 ] = '\0' ;
if ( V_17 >= V_34 . V_8 ) {
F_17 ( L_10 , V_39 ,
V_17 ) ;
V_17 = V_34 . V_8 ;
} else {
V_17 ++ ;
}
V_34 . V_70 = V_17 ;
if ( F_19 ( ( char V_43 * ) V_34 . V_42 , V_7 ,
V_17 ) ) {
F_17 ( L_11 ,
V_39 ) ;
V_27 = - V_37 ;
}
} else {
V_27 = V_17 ;
}
exit:
F_20 () ;
F_21 ( V_7 ) ;
return V_27 ;
}
