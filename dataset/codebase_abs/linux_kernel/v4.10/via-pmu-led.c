static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_5 != - 1 && ! V_6 )
F_3 ( & V_7 , NULL , 4 , 0xee , 4 , 0 , V_5 ) ;
V_5 = - 1 ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_5 ( struct V_8 * V_9 ,
enum V_10 V_11 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
switch ( V_11 ) {
case V_12 :
V_5 = 0 ;
break;
case V_13 :
V_5 = 1 ;
break;
default:
goto V_14;
break;
}
if ( V_7 . V_15 && ! V_6 )
F_3 ( & V_7 , NULL , 4 , 0xee , 4 , 0 , V_5 ) ;
V_14:
F_4 ( & V_4 , V_3 ) ;
}
static int T_1 F_6 ( void )
{
struct V_16 * V_17 ;
const char * V_18 ;
if ( F_7 () != V_19 )
return - V_20 ;
V_17 = F_8 ( L_1 ) ;
if ( V_17 == NULL )
return - V_20 ;
V_18 = F_9 ( V_17 , L_2 , NULL ) ;
if ( V_18 == NULL ) {
F_10 ( V_17 ) ;
return - V_20 ;
}
if ( strncmp ( V_18 , L_3 , strlen ( L_3 ) ) != 0 &&
strncmp ( V_18 , L_4 , strlen ( L_4 ) ) != 0 &&
strcmp ( V_18 , L_5 ) != 0 &&
strcmp ( V_18 , L_6 ) != 0 ) {
F_10 ( V_17 ) ;
return - V_20 ;
}
F_10 ( V_17 ) ;
F_11 ( & V_4 ) ;
V_7 . V_15 = 1 ;
V_7 . V_21 = F_1 ;
return F_12 ( NULL , & V_22 ) ;
}
