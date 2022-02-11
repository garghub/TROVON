static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_8 = V_9 ;
bool V_10 = false ;
switch ( V_3 ) {
case V_11 :
V_10 = true ;
case V_12 :
V_8 = V_13 ;
break;
case V_14 :
V_10 = true ;
case V_15 :
V_8 = V_16 ;
break;
case V_17 :
V_10 = true ;
case V_18 :
V_8 = V_19 ;
break;
case V_20 :
V_10 = true ;
case V_21 :
V_8 = V_22 ;
break;
case V_23 :
F_3 ( & V_2 -> V_24 , L_1 ) ;
break;
default:
F_4 ( & V_2 -> V_24 ,
L_2 , V_3 ) ;
break;
}
V_7 = V_5 -> V_7 ;
if ( V_8 == V_9 )
return;
if ( V_10 )
F_5 ( & V_2 -> V_24 , 0 ) ;
if ( V_5 -> V_25 )
return;
F_6 ( V_7 , V_8 , V_10 ? 1 : 0 ) ;
F_7 ( V_7 ) ;
}
static int F_8 ( struct V_2 * V_24 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_25 = true ;
return 0 ;
}
static int F_10 ( struct V_2 * V_24 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_25 = false ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
const char * V_26 = F_12 ( V_2 ) ;
char * V_27 ;
int error ;
if ( strncmp ( F_13 ( V_2 ) , V_28 ,
strlen ( V_28 ) ) )
return - V_29 ;
V_5 = F_14 ( sizeof( struct V_4 ) , V_30 ) ;
if ( ! V_5 )
return - V_31 ;
V_2 -> V_32 = V_5 ;
V_5 -> V_7 = V_7 = F_15 () ;
if ( ! V_7 ) {
error = - V_31 ;
goto V_33;
}
V_27 = F_16 ( V_2 ) ;
strcpy ( V_27 , V_34 ) ;
snprintf ( V_5 -> V_35 , sizeof( V_5 -> V_35 ) , L_3 , V_26 ) ;
V_7 -> V_27 = V_27 ;
V_7 -> V_35 = V_5 -> V_35 ;
V_7 -> V_36 . V_37 = V_38 ;
V_7 -> V_24 . V_39 = & V_2 -> V_24 ;
F_17 ( V_7 , V_40 , V_13 ) ;
F_17 ( V_7 , V_40 , V_16 ) ;
F_17 ( V_7 , V_40 , V_19 ) ;
F_17 ( V_7 , V_40 , V_22 ) ;
error = F_18 ( V_7 ) ;
if ( error )
goto V_41;
F_19 ( & V_2 -> V_24 ,
L_4 , V_27 , F_13 ( V_2 ) ) ;
return 0 ;
V_41:
F_20 ( V_7 ) ;
V_33:
F_21 ( V_5 ) ;
return error ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_23 ( V_5 -> V_7 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
