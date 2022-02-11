static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 ,
V_7 -> V_9 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 , struct V_6 ,
V_8 ) ;
unsigned int V_11 ;
V_7 -> V_12 -> V_13 . V_14 . V_15 ( V_7 -> V_12 ) ;
V_11 = V_7 -> V_9 -> V_16 ;
V_11 *= 1000 ;
return sprintf ( V_5 , L_2 , V_11 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 , struct V_6 ,
V_8 ) ;
unsigned int V_11 = V_7 -> V_9 -> V_17 ;
V_11 *= 1000 ;
return sprintf ( V_5 , L_2 , V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 , struct V_6 ,
V_8 ) ;
unsigned int V_11 = V_7 -> V_9 -> V_18 ;
V_11 *= 1000 ;
return sprintf ( V_5 , L_2 , V_11 ) ;
}
static int F_6 ( struct V_19 * V_20 ,
unsigned int V_21 , int type )
{
int V_22 ;
unsigned int V_23 ;
struct V_6 * V_7 ;
V_23 = V_20 -> V_24 -> V_25 ;
V_7 = & V_20 -> V_24 -> V_26 [ V_23 ] ;
switch ( type ) {
case V_27 :
V_7 -> V_8 . V_28 = F_1 ;
snprintf ( V_7 -> V_29 , sizeof( V_7 -> V_29 ) ,
L_3 , V_21 + 1 ) ;
break;
case V_30 :
V_7 -> V_8 . V_28 = F_3 ;
snprintf ( V_7 -> V_29 , sizeof( V_7 -> V_29 ) ,
L_4 , V_21 + 1 ) ;
break;
case V_31 :
V_7 -> V_8 . V_28 = F_4 ;
snprintf ( V_7 -> V_29 , sizeof( V_7 -> V_29 ) ,
L_5 , V_21 + 1 ) ;
break;
case V_32 :
V_7 -> V_8 . V_28 = F_5 ;
snprintf ( V_7 -> V_29 , sizeof( V_7 -> V_29 ) ,
L_6 , V_21 + 1 ) ;
break;
default:
V_22 = - V_33 ;
return V_22 ;
}
V_7 -> V_9 =
& V_20 -> V_12 . V_13 . V_34 . V_9 [ V_21 ] ;
V_7 -> V_12 = & V_20 -> V_12 ;
V_7 -> V_8 . V_35 = NULL ;
V_7 -> V_8 . V_4 . V_36 = V_37 ;
V_7 -> V_8 . V_4 . V_29 = V_7 -> V_29 ;
F_7 ( & V_7 -> V_8 . V_4 ) ;
V_20 -> V_24 -> V_38 [ V_23 ] = & V_7 -> V_8 . V_4 ;
++ V_20 -> V_24 -> V_25 ;
return 0 ;
}
static void F_8 ( struct V_19 * V_20 )
{
}
void F_9 ( struct V_19 * V_20 )
{
F_8 ( V_20 ) ;
}
int F_10 ( struct V_19 * V_20 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_1 * V_43 ;
unsigned int V_44 ;
int V_22 = 0 ;
if ( V_20 -> V_12 . V_13 . V_14 . V_45 == NULL )
goto exit;
V_22 = ( V_20 -> V_12 . V_13 . V_14 . V_45 ( & V_20 -> V_12 ) ) ;
if ( V_22 )
goto exit;
V_40 = F_11 ( & V_20 -> V_46 -> V_2 , sizeof( * V_40 ) ,
V_47 ) ;
if ( ! V_40 ) {
V_22 = - V_48 ;
goto exit;
}
V_20 -> V_24 = V_40 ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ ) {
if ( V_20 -> V_12 . V_13 . V_34 . V_9 [ V_44 ] . V_10 == 0 )
continue;
V_22 = F_6 ( V_20 , V_44 , V_31 ) ;
if ( V_22 )
goto exit;
V_22 = F_6 ( V_20 , V_44 , V_27 ) ;
if ( V_22 )
goto exit;
V_22 = F_6 ( V_20 , V_44 , V_30 ) ;
if ( V_22 )
goto exit;
V_22 = F_6 ( V_20 , V_44 , V_32 ) ;
if ( V_22 )
goto exit;
}
V_42 = F_12 ( & V_20 -> V_50 , & V_51 ) ;
if ( V_42 == NULL ) {
F_13 ( & V_20 -> V_46 -> V_2 ,
L_7 ) ;
V_22 = - V_52 ;
goto exit;
}
V_20 -> V_41 = V_42 ;
V_40 -> V_53 [ 0 ] = & V_40 -> V_54 ;
V_40 -> V_54 . V_38 = V_40 -> V_38 ;
V_43 = F_14 ( & V_20 -> V_46 -> V_2 ,
V_42 -> V_29 ,
V_40 ,
V_40 -> V_53 ) ;
if ( F_15 ( V_43 ) ) {
V_22 = F_16 ( V_43 ) ;
goto V_55;
}
goto exit;
V_55:
F_8 ( V_20 ) ;
exit:
return V_22 ;
}
