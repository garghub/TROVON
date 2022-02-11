static int F_1 ( enum V_1 type ,
char * V_2 , T_1 V_3 ,
T_2 V_4 , T_3 V_5 )
{
switch ( type ) {
case V_6 :
case V_7 :
return snprintf ( V_2 , V_3 , L_1 ,
( ( unsigned char * ) & V_4 ) [ 0 ] ,
( ( unsigned char * ) & V_4 ) [ 1 ] ,
( ( unsigned char * ) & V_4 ) [ 2 ] ,
( ( unsigned char * ) & V_4 ) [ 3 ] ,
V_5 >> 8 ,
V_5 & 0xFF ) ;
case V_8 :
return snprintf ( V_2 , V_3 , L_2 , & V_4 , V_5 ) ;
case V_9 :
return snprintf ( V_2 , V_3 , L_3 , V_5 ) ;
}
return 0 ;
}
static unsigned int F_2 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
enum V_1 type ,
unsigned int V_14 ,
unsigned int V_15 ,
struct V_16 * exp )
{
T_2 V_17 ;
T_4 V_5 ;
int V_18 = F_3 ( V_13 ) ;
struct V_19 * V_20 = exp -> V_21 ;
char V_2 [ sizeof( L_4 ) ] ;
unsigned int V_3 ;
F_4 ( L_5 , type , V_14 , V_15 ) ;
V_17 = V_20 -> V_22 [ ! V_18 ] . V_23 . V_24 . V_25 . V_26 ;
exp -> V_27 . V_28 . V_5 = exp -> V_23 . V_24 . V_29 . V_28 . V_5 ;
exp -> V_18 = ! V_18 ;
exp -> V_30 = V_31 ;
for ( V_5 = F_5 ( exp -> V_27 . V_28 . V_5 ) ; V_5 != 0 ; V_5 ++ ) {
int V_32 ;
exp -> V_23 . V_24 . V_29 . V_28 . V_5 = F_6 ( V_5 ) ;
V_32 = F_7 ( exp ) ;
if ( V_32 == 0 )
break;
else if ( V_32 != - V_33 ) {
V_5 = 0 ;
break;
}
}
if ( V_5 == 0 )
return V_34 ;
V_3 = F_1 ( type , V_2 , sizeof( V_2 ) , V_17 , V_5 ) ;
if ( ! V_3 )
goto V_35;
F_4 ( L_6 ) ;
if ( ! F_8 ( V_11 , V_20 , V_13 , V_14 ,
V_15 , V_2 , V_3 ) )
goto V_35;
return V_36 ;
V_35:
F_9 ( exp ) ;
return V_34 ;
}
static void T_5 F_10 ( void )
{
F_11 ( V_37 , NULL ) ;
F_12 () ;
}
static int T_6 F_13 ( void )
{
F_14 ( V_37 != NULL ) ;
F_11 ( V_37 , F_2 ) ;
return 0 ;
}
static int F_15 ( const char * V_38 , struct V_39 * V_40 )
{
F_16 (KERN_INFO KBUILD_MODNAME
L_7 ) ;
return 0 ;
}
