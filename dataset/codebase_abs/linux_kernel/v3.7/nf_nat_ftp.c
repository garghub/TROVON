static int F_1 ( struct V_1 * V_2 , enum V_3 type ,
char * V_4 , T_1 V_5 ,
union V_6 * V_7 , T_2 V_8 )
{
switch ( type ) {
case V_9 :
case V_10 :
return snprintf ( V_4 , V_5 , L_1 ,
( ( unsigned char * ) & V_7 -> V_11 ) [ 0 ] ,
( ( unsigned char * ) & V_7 -> V_11 ) [ 1 ] ,
( ( unsigned char * ) & V_7 -> V_11 ) [ 2 ] ,
( ( unsigned char * ) & V_7 -> V_11 ) [ 3 ] ,
V_8 >> 8 ,
V_8 & 0xFF ) ;
case V_12 :
if ( F_2 ( V_2 ) == V_13 )
return snprintf ( V_4 , V_5 , L_2 ,
& V_7 -> V_11 , V_8 ) ;
else
return snprintf ( V_4 , V_5 , L_3 ,
& V_7 -> V_14 , V_8 ) ;
case V_15 :
return snprintf ( V_4 , V_5 , L_4 , V_8 ) ;
}
return 0 ;
}
static unsigned int F_3 ( struct V_16 * V_17 ,
enum V_18 V_19 ,
enum V_3 type ,
unsigned int V_20 ,
unsigned int V_21 ,
unsigned int V_22 ,
struct V_23 * exp )
{
union V_6 V_24 ;
T_3 V_8 ;
int V_25 = F_4 ( V_19 ) ;
struct V_1 * V_2 = exp -> V_26 ;
char V_4 [ sizeof( L_5 ) + V_27 ] ;
unsigned int V_5 ;
F_5 ( L_6 , type , V_21 , V_22 ) ;
V_24 = V_2 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_31 ;
exp -> V_32 . V_33 . V_8 = exp -> V_29 . V_30 . V_34 . V_33 . V_8 ;
exp -> V_25 = ! V_25 ;
exp -> V_35 = V_36 ;
for ( V_8 = F_6 ( exp -> V_32 . V_33 . V_8 ) ; V_8 != 0 ; V_8 ++ ) {
int V_37 ;
exp -> V_29 . V_30 . V_34 . V_33 . V_8 = F_7 ( V_8 ) ;
V_37 = F_8 ( exp ) ;
if ( V_37 == 0 )
break;
else if ( V_37 != - V_38 ) {
V_8 = 0 ;
break;
}
}
if ( V_8 == 0 )
return V_39 ;
V_5 = F_1 ( V_2 , type , V_4 , sizeof( V_4 ) ,
& V_24 , V_8 ) ;
if ( ! V_5 )
goto V_40;
F_5 ( L_7 ) ;
if ( ! F_9 ( V_17 , V_2 , V_19 , V_20 , V_21 ,
V_22 , V_4 , V_5 ) )
goto V_40;
return V_41 ;
V_40:
F_10 ( exp ) ;
return V_39 ;
}
static void T_4 F_11 ( void )
{
F_12 ( V_42 , NULL ) ;
F_13 () ;
}
static int T_5 F_14 ( void )
{
F_15 ( V_42 != NULL ) ;
F_12 ( V_42 , F_3 ) ;
return 0 ;
}
static int F_16 ( const char * V_43 , struct V_44 * V_45 )
{
F_17 (KERN_INFO KBUILD_MODNAME
L_8 ) ;
return 0 ;
}
