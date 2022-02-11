static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 V_14 = {
. V_15 = 8 ,
. V_7 = 2 ,
. V_16 = 1 ,
. V_17 = V_11 -> V_18 ,
. V_19 = V_11 -> V_20 ,
} ;
struct V_21 V_22 ;
F_3 ( & V_11 -> V_23 ) ;
V_11 -> V_18 [ 0 ] = F_4 ( V_24 ) ;
V_11 -> V_18 [ 1 ] = 0 ;
F_5 ( & V_22 ) ;
F_6 ( & V_14 , & V_22 ) ;
V_6 = F_7 ( V_11 -> V_25 , & V_22 ) ;
if ( V_6 )
goto V_26;
switch ( V_11 -> V_20 [ 1 ] & V_27 ) {
case V_28 :
V_7 += sprintf ( V_5 , L_1 , V_29 ) ;
break;
case V_30 :
V_7 += sprintf ( V_5 , L_1 , V_31 ) ;
break;
case V_32 :
V_7 += sprintf ( V_5 , L_1 , V_33 ) ;
break;
case V_34 :
V_7 += sprintf ( V_5 , L_1 , V_35 ) ;
break;
}
V_26:
F_8 ( & V_11 -> V_23 ) ;
return V_6 ? V_6 : V_7 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_7 )
{
struct V_21 V_22 ;
int V_6 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_3 V_36 ;
struct V_13 V_37 [] = {
{
. V_15 = 8 ,
. V_7 = 2 ,
. V_16 = 1 ,
. V_17 = V_11 -> V_18 ,
. V_19 = V_11 -> V_20 ,
} , {
. V_15 = 8 ,
. V_7 = 2 ,
. V_16 = 1 ,
. V_17 = V_11 -> V_18 ,
} ,
} ;
if ( ! strncmp ( V_5 , V_29 ,
strlen ( V_5 ) < strlen ( V_29 )
? strlen ( V_5 ) : strlen ( V_29 ) ) )
V_36 = V_28 ;
else if ( ! strncmp ( V_5 , V_31 ,
strlen ( V_5 ) < strlen ( V_31 )
? strlen ( V_5 ) : strlen ( V_31 ) ) )
V_36 = V_30 ;
else if ( ! strncmp ( V_5 , V_33 ,
strlen ( V_5 ) < strlen ( V_33 )
? strlen ( V_5 ) : strlen ( V_33 ) ) )
V_36 = V_32 ;
else if ( ! strncmp ( V_5 , V_35 ,
strlen ( V_5 ) < strlen ( V_35 )
? strlen ( V_5 ) : strlen ( V_35 ) ) )
V_36 = V_34 ;
else
return - V_38 ;
F_3 ( & V_11 -> V_23 ) ;
V_11 -> V_18 [ 0 ] = F_4 ( V_24 ) ;
V_11 -> V_18 [ 1 ] = 0 ;
F_5 ( & V_22 ) ;
F_6 ( & V_37 [ 0 ] , & V_22 ) ;
V_6 = F_7 ( V_11 -> V_25 , & V_22 ) ;
if ( V_6 )
goto V_26;
V_11 -> V_18 [ 0 ] = F_10 ( V_24 ) ;
V_11 -> V_18 [ 1 ] = ( V_11 -> V_20 [ 1 ] & ~ V_27 ) | V_36 ;
F_5 ( & V_22 ) ;
F_6 ( & V_37 [ 1 ] , & V_22 ) ;
V_6 = F_7 ( V_11 -> V_25 , & V_22 ) ;
V_26:
F_8 ( & V_11 -> V_23 ) ;
return V_6 ? V_6 : V_7 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_21 V_22 ;
int V_6 ;
T_1 V_7 = 0 ;
T_4 V_36 ;
struct V_39 * V_40 = F_12 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 V_37 [] = {
{
. V_15 = 8 ,
. V_7 = 1 ,
. V_16 = 0 ,
. V_41 = 200 ,
. V_17 = V_11 -> V_18 ,
} , {
. V_15 = 8 ,
. V_7 = 2 ,
. V_16 = 1 ,
. V_19 = V_11 -> V_20 ,
} ,
} ;
F_3 ( & V_11 -> V_23 ) ;
V_11 -> V_18 [ 0 ] = F_4 ( V_40 -> V_42 ) ;
F_5 ( & V_22 ) ;
F_6 ( & V_37 [ 0 ] , & V_22 ) ;
F_6 ( & V_37 [ 1 ] , & V_22 ) ;
V_6 = F_7 ( V_11 -> V_25 , & V_22 ) ;
if ( V_6 )
goto V_26;
V_36 = ( ( ( T_4 ) ( V_11 -> V_20 [ 0 ] ) ) << 8 ) | ( V_11 -> V_20 [ 1 ] & 0xF0 ) ;
V_7 = sprintf ( V_5 , L_2 , V_36 ) ;
V_26:
F_8 ( & V_11 -> V_23 ) ;
return V_6 ? V_6 : V_7 ;
}
static int T_5 F_13 ( struct V_43 * V_44 )
{
int V_6 ;
struct V_13 V_37 [ 2 ] = {
{
. V_15 = 8 ,
. V_7 = 2 ,
. V_16 = 1 ,
} , {
. V_15 = 8 ,
. V_7 = 2 ,
. V_16 = 1 ,
} ,
} ;
struct V_21 V_22 ;
T_3 * V_45 ;
T_3 * V_18 = F_14 ( 2 , V_46 ) ;
if ( V_18 == NULL ) {
V_6 = - V_47 ;
goto V_26;
}
V_45 = F_14 ( 2 , V_46 ) ;
if ( V_45 == NULL ) {
V_6 = - V_47 ;
goto V_48;
}
V_18 [ 0 ] = 0x0d ;
V_18 [ 1 ] = 0x40 ;
V_45 [ 0 ] = 0x0c ;
V_45 [ 1 ] = 0x9b ;
V_37 [ 0 ] . V_17 = V_18 ;
V_37 [ 1 ] . V_17 = V_45 ;
F_5 ( & V_22 ) ;
F_6 ( & V_37 [ 0 ] , & V_22 ) ;
F_6 ( & V_37 [ 1 ] , & V_22 ) ;
V_6 = F_7 ( V_44 , & V_22 ) ;
F_15 ( V_45 ) ;
V_48:
F_15 ( V_18 ) ;
V_26:
return V_6 ;
}
static int T_5 F_16 ( struct V_43 * V_44 )
{
struct V_10 * V_11 ;
int V_6 = 0 ;
V_11 = F_17 ( sizeof( * V_11 ) , V_46 ) ;
if ( V_11 == NULL ) {
V_6 = - V_47 ;
goto V_26;
}
F_18 ( V_44 , V_11 ) ;
V_11 -> V_20 = F_14 ( sizeof( * V_11 -> V_20 ) * V_49 ,
V_46 ) ;
if ( V_11 -> V_20 == NULL ) {
V_6 = - V_47 ;
goto V_50;
}
V_11 -> V_18 = F_14 ( sizeof( * V_11 -> V_18 ) * V_51 ,
V_46 ) ;
if ( V_11 -> V_18 == NULL ) {
V_6 = - V_47 ;
goto V_52;
}
V_11 -> V_25 = V_44 ;
F_19 ( & V_11 -> V_23 ) ;
V_11 -> V_9 = F_20 ( 0 ) ;
if ( V_11 -> V_9 == NULL ) {
V_6 = - V_47 ;
goto V_48;
}
V_11 -> V_9 -> V_2 . V_53 = & V_44 -> V_2 ;
V_11 -> V_9 -> V_54 = & V_55 ;
V_11 -> V_9 -> V_12 = ( void * ) ( V_11 ) ;
V_11 -> V_9 -> V_56 = V_57 ;
V_6 = F_21 ( V_11 -> V_9 ) ;
if ( V_6 )
goto V_58;
V_44 -> V_59 = V_60 ;
F_22 ( V_44 ) ;
F_13 ( V_44 ) ;
return 0 ;
V_58:
F_23 ( V_11 -> V_9 ) ;
V_48:
F_15 ( V_11 -> V_18 ) ;
V_52:
F_15 ( V_11 -> V_20 ) ;
V_50:
F_15 ( V_11 ) ;
V_26:
return V_6 ;
}
static int T_6 F_24 ( struct V_43 * V_44 )
{
struct V_10 * V_11 = F_25 ( V_44 ) ;
F_26 ( V_11 -> V_9 ) ;
F_15 ( V_11 -> V_18 ) ;
F_15 ( V_11 -> V_20 ) ;
F_15 ( V_11 ) ;
return 0 ;
}
static T_7 int F_27 ( void )
{
return F_28 ( & V_61 ) ;
}
static T_8 void F_29 ( void )
{
F_30 ( & V_61 ) ;
}
