static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 V_13 = {
. V_14 = 8 ,
. V_7 = 2 ,
. V_15 = 1 ,
. V_16 = V_11 -> V_17 ,
. V_18 = V_11 -> V_19 ,
} ;
struct V_20 V_21 ;
F_4 ( & V_11 -> V_22 ) ;
V_11 -> V_17 [ 0 ] = F_5 ( V_23 ) ;
V_11 -> V_17 [ 1 ] = 0 ;
F_6 ( & V_21 ) ;
F_7 ( & V_13 , & V_21 ) ;
V_6 = F_8 ( V_11 -> V_24 , & V_21 ) ;
if ( V_6 )
goto V_25;
switch ( V_11 -> V_19 [ 1 ] & V_26 ) {
case V_27 :
V_7 += sprintf ( V_5 , L_1 , V_28 ) ;
break;
case V_29 :
V_7 += sprintf ( V_5 , L_1 , V_30 ) ;
break;
case V_31 :
V_7 += sprintf ( V_5 , L_1 , V_32 ) ;
break;
case V_33 :
V_7 += sprintf ( V_5 , L_1 , V_34 ) ;
break;
}
V_25:
F_9 ( & V_11 -> V_22 ) ;
return V_6 ? V_6 : V_7 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_7 )
{
struct V_20 V_21 ;
int V_6 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
T_3 V_35 ;
struct V_12 V_36 [] = {
{
. V_14 = 8 ,
. V_7 = 2 ,
. V_15 = 1 ,
. V_16 = V_11 -> V_17 ,
. V_18 = V_11 -> V_19 ,
} , {
. V_14 = 8 ,
. V_7 = 2 ,
. V_15 = 1 ,
. V_16 = V_11 -> V_17 ,
} ,
} ;
if ( ! strncmp ( V_5 , V_28 ,
strlen ( V_5 ) < strlen ( V_28 )
? strlen ( V_5 ) : strlen ( V_28 ) ) )
V_35 = V_27 ;
else if ( ! strncmp ( V_5 , V_30 ,
strlen ( V_5 ) < strlen ( V_30 )
? strlen ( V_5 ) : strlen ( V_30 ) ) )
V_35 = V_29 ;
else if ( ! strncmp ( V_5 , V_32 ,
strlen ( V_5 ) < strlen ( V_32 )
? strlen ( V_5 ) : strlen ( V_32 ) ) )
V_35 = V_31 ;
else if ( ! strncmp ( V_5 , V_34 ,
strlen ( V_5 ) < strlen ( V_34 )
? strlen ( V_5 ) : strlen ( V_34 ) ) )
V_35 = V_33 ;
else
return - V_37 ;
F_4 ( & V_11 -> V_22 ) ;
V_11 -> V_17 [ 0 ] = F_5 ( V_23 ) ;
V_11 -> V_17 [ 1 ] = 0 ;
F_6 ( & V_21 ) ;
F_7 ( & V_36 [ 0 ] , & V_21 ) ;
V_6 = F_8 ( V_11 -> V_24 , & V_21 ) ;
if ( V_6 )
goto V_25;
V_11 -> V_17 [ 0 ] = F_11 ( V_23 ) ;
V_11 -> V_17 [ 1 ] = ( V_11 -> V_19 [ 1 ] & ~ V_26 ) | V_35 ;
F_6 ( & V_21 ) ;
F_7 ( & V_36 [ 1 ] , & V_21 ) ;
V_6 = F_8 ( V_11 -> V_24 , & V_21 ) ;
V_25:
F_9 ( & V_11 -> V_22 ) ;
return V_6 ? V_6 : V_7 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_20 V_21 ;
int V_6 ;
T_1 V_7 = 0 ;
T_4 V_35 ;
struct V_38 * V_39 = F_13 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 V_36 [] = {
{
. V_14 = 8 ,
. V_7 = 1 ,
. V_15 = 0 ,
. V_40 = 200 ,
. V_16 = V_11 -> V_17 ,
} , {
. V_14 = 8 ,
. V_7 = 2 ,
. V_15 = 1 ,
. V_18 = V_11 -> V_19 ,
} ,
} ;
F_4 ( & V_11 -> V_22 ) ;
V_11 -> V_17 [ 0 ] = F_5 ( V_39 -> V_41 ) ;
F_6 ( & V_21 ) ;
F_7 ( & V_36 [ 0 ] , & V_21 ) ;
F_7 ( & V_36 [ 1 ] , & V_21 ) ;
V_6 = F_8 ( V_11 -> V_24 , & V_21 ) ;
if ( V_6 )
goto V_25;
V_35 = ( ( ( T_4 ) ( V_11 -> V_19 [ 0 ] ) ) << 8 ) | ( V_11 -> V_19 [ 1 ] & 0xF0 ) ;
V_7 = sprintf ( V_5 , L_2 , V_35 ) ;
V_25:
F_9 ( & V_11 -> V_22 ) ;
return V_6 ? V_6 : V_7 ;
}
static int T_5 F_14 ( struct V_10 * V_11 )
{
struct V_12 V_36 [ 2 ] = {
{
. V_14 = 8 ,
. V_7 = 2 ,
. V_15 = 1 ,
. V_16 = V_11 -> V_17 ,
} , {
. V_14 = 8 ,
. V_7 = 2 ,
. V_15 = 1 ,
. V_16 = V_11 -> V_17 + 2 ,
} ,
} ;
struct V_20 V_21 ;
V_11 -> V_17 [ 0 ] = 0x0d ;
V_11 -> V_17 [ 1 ] = 0x40 ;
V_11 -> V_17 [ 2 ] = 0x0c ;
V_11 -> V_17 [ 3 ] = 0x9b ;
F_6 ( & V_21 ) ;
F_7 ( & V_36 [ 0 ] , & V_21 ) ;
F_7 ( & V_36 [ 1 ] , & V_21 ) ;
return F_8 ( V_11 -> V_24 , & V_21 ) ;
}
static int T_5 F_15 ( struct V_42 * V_43 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_6 = 0 ;
V_9 = F_16 ( sizeof( * V_11 ) ) ;
if ( V_9 == NULL ) {
V_6 = - V_44 ;
goto V_25;
}
V_11 = F_3 ( V_9 ) ;
F_17 ( V_43 , V_9 ) ;
V_11 -> V_24 = V_43 ;
F_18 ( & V_11 -> V_22 ) ;
V_9 -> V_2 . V_45 = & V_43 -> V_2 ;
V_9 -> V_46 = & V_47 ;
V_9 -> V_48 = V_49 ;
V_6 = F_19 ( V_9 ) ;
if ( V_6 )
goto V_50;
V_43 -> V_51 = V_52 ;
F_20 ( V_43 ) ;
F_14 ( V_11 ) ;
return 0 ;
V_50:
F_21 ( V_9 ) ;
V_25:
return V_6 ;
}
static int T_6 F_22 ( struct V_42 * V_43 )
{
F_23 ( F_24 ( V_43 ) ) ;
return 0 ;
}
static T_7 int F_25 ( void )
{
return F_26 ( & V_53 ) ;
}
static T_8 void F_27 ( void )
{
F_28 ( & V_53 ) ;
}
