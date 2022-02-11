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
default:
F_3 ( & V_2 -> V_23 ,
L_1 , V_3 ) ;
break;
}
V_7 = V_5 -> V_7 ;
if ( V_9 == V_8 )
return;
if ( V_10 )
F_4 ( & V_2 -> V_23 , 0 ) ;
if ( V_5 -> V_24 )
return;
F_5 ( V_7 , V_8 , V_10 ? 1 : 0 ) ;
F_6 ( V_7 ) ;
}
static int F_7 ( struct V_2 * V_23 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_24 = true ;
return 0 ;
}
static int F_9 ( struct V_2 * V_23 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_24 = false ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
const char * V_25 = F_11 ( V_2 ) ;
char * V_26 ;
int error ;
if ( strncmp ( F_12 ( V_2 ) , V_27 ,
strlen ( V_27 ) ) )
return - V_28 ;
V_5 = F_13 ( sizeof( struct V_4 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_2 -> V_31 = V_5 ;
V_5 -> V_7 = V_7 = F_14 () ;
if ( ! V_7 ) {
error = - V_30 ;
goto V_32;
}
V_26 = F_15 ( V_2 ) ;
strcpy ( V_26 , V_33 ) ;
snprintf ( V_5 -> V_34 , sizeof( V_5 -> V_34 ) , L_2 , V_25 ) ;
V_7 -> V_26 = V_26 ;
V_7 -> V_34 = V_5 -> V_34 ;
V_7 -> V_35 . V_36 = V_37 ;
V_7 -> V_23 . V_38 = & V_2 -> V_23 ;
F_16 ( V_7 , V_39 , V_13 ) ;
F_16 ( V_7 , V_39 , V_16 ) ;
F_16 ( V_7 , V_39 , V_19 ) ;
F_16 ( V_7 , V_39 , V_22 ) ;
error = F_17 ( V_7 ) ;
if ( error )
goto V_40;
F_18 ( & V_2 -> V_23 ,
L_3 , V_26 , F_12 ( V_2 ) ) ;
return 0 ;
V_40:
F_19 ( V_7 ) ;
V_32:
F_20 ( V_5 ) ;
return error ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_22 ( V_5 -> V_7 ) ;
F_20 ( V_5 ) ;
return 0 ;
}
