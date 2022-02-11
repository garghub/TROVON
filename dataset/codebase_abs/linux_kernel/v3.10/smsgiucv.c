static int F_1 ( struct V_1 * V_2 , T_1 V_3 [ 8 ] ,
T_1 V_4 [ 16 ] )
{
if ( strncmp ( V_3 , L_1 , 8 ) != 0 )
return - V_5 ;
return F_2 ( V_2 , & V_6 , L_2 , NULL ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned char * V_11 ;
unsigned char V_12 [ 9 ] ;
int V_13 , V_14 ;
V_11 = F_4 ( V_8 -> V_15 + 1 , V_16 | V_17 ) ;
if ( ! V_11 ) {
F_5 ( V_2 , V_8 ) ;
return;
}
V_13 = F_6 ( V_2 , V_8 , 0 , V_11 , V_8 -> V_15 , NULL ) ;
if ( V_13 == 0 ) {
V_11 [ V_8 -> V_15 ] = 0 ;
F_7 ( V_11 , V_8 -> V_15 ) ;
memcpy ( V_12 , V_11 , 8 ) ;
V_12 [ 8 ] = 0 ;
for ( V_14 = 7 ; V_14 >= 0 ; V_14 -- ) {
if ( V_12 [ V_14 ] != ' ' && V_12 [ V_14 ] != '\t' )
break;
V_12 [ V_14 ] = 0 ;
}
F_8 ( & V_18 ) ;
F_9 (cb, &smsg_list, list)
if ( strncmp ( V_11 + 8 , V_10 -> V_19 , V_10 -> V_20 ) == 0 ) {
V_10 -> V_21 ( V_12 , V_11 + 8 ) ;
break;
}
F_10 ( & V_18 ) ;
}
F_11 ( V_11 ) ;
}
int F_12 ( const char * V_19 ,
void (* V_21)( const char * V_22 , char * V_23 ) )
{
struct V_9 * V_10 ;
V_10 = F_4 ( sizeof( struct V_9 ) , V_24 ) ;
if ( ! V_10 )
return - V_25 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_20 = strlen ( V_19 ) ;
V_10 -> V_21 = V_21 ;
F_13 ( & V_18 ) ;
F_14 ( & V_10 -> V_26 , & V_27 ) ;
F_15 ( & V_18 ) ;
return 0 ;
}
void F_16 ( const char * V_19 ,
void (* V_21)( const char * V_22 ,
char * V_23 ) )
{
struct V_9 * V_10 , * V_28 ;
F_13 ( & V_18 ) ;
V_10 = NULL ;
F_9 (tmp, &smsg_list, list)
if ( V_28 -> V_21 == V_21 &&
strcmp ( V_28 -> V_19 , V_19 ) == 0 ) {
V_10 = V_28 ;
F_17 ( & V_10 -> V_26 ) ;
break;
}
F_15 ( & V_18 ) ;
F_11 ( V_10 ) ;
}
static int F_18 ( struct V_29 * V_30 )
{
#ifdef F_19
F_20 ( V_31 L_3 ) ;
#endif
if ( V_32 && V_33 ) {
F_21 ( V_32 , NULL ) ;
V_33 = 0 ;
}
return 0 ;
}
static int F_22 ( struct V_29 * V_30 )
{
int V_13 ;
#ifdef F_19
F_20 ( V_31 L_4 ) ;
#endif
if ( V_32 && ! V_33 ) {
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_34 = 255 ;
V_32 -> V_35 = 0 ;
V_13 = F_23 ( V_32 , & V_6 , L_1 ,
NULL , NULL , NULL ) ;
#ifdef F_19
if ( V_13 )
F_20 ( V_36
L_5 , V_13 ) ;
#endif
if ( ! V_13 )
V_33 = 1 ;
F_24 ( L_6 , NULL , 0 , NULL ) ;
}
return 0 ;
}
static void T_2 F_25 ( void )
{
F_24 ( L_6 , NULL , 0 , NULL ) ;
F_26 ( V_37 ) ;
F_27 ( & V_6 , 1 ) ;
F_28 ( & V_38 ) ;
}
static int T_3 F_29 ( void )
{
int V_13 ;
if ( ! V_39 ) {
V_13 = - V_40 ;
goto V_41;
}
V_13 = F_30 ( & V_38 ) ;
if ( V_13 != 0 )
goto V_41;
V_13 = F_31 ( & V_6 , 1 ) ;
if ( V_13 )
goto V_42;
V_32 = F_32 ( 255 , 0 , V_24 ) ;
if ( ! V_32 ) {
V_13 = - V_25 ;
goto V_43;
}
V_13 = F_23 ( V_32 , & V_6 , L_1 ,
NULL , NULL , NULL ) ;
if ( V_13 )
goto V_44;
else
V_33 = 1 ;
V_37 = F_33 ( sizeof( struct V_29 ) , V_24 ) ;
if ( ! V_37 ) {
V_13 = - V_25 ;
goto V_44;
}
F_34 ( V_37 , L_7 ) ;
V_37 -> V_45 = & V_46 ;
V_37 -> V_47 = V_48 ;
V_37 -> V_49 = ( void ( * ) ( struct V_29 * ) ) F_11 ;
V_37 -> V_50 = & V_38 ;
V_13 = F_35 ( V_37 ) ;
if ( V_13 )
goto V_51;
F_24 ( L_6 , NULL , 0 , NULL ) ;
return 0 ;
V_51:
F_36 ( V_37 ) ;
V_44:
F_37 ( V_32 ) ;
V_32 = NULL ;
V_43:
F_27 ( & V_6 , 1 ) ;
V_42:
F_28 ( & V_38 ) ;
V_41:
return V_13 ;
}
