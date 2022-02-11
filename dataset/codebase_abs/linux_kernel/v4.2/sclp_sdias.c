static void F_1 ( struct V_1 * V_2 )
{
memcpy ( & V_3 , V_2 ,
F_2 (unsigned long, sizeof(sdias_evbuf), evbuf->length) ) ;
F_3 ( & V_4 ) ;
F_4 ( L_1 ) ;
}
static void F_5 ( struct V_5 * V_6 , void * V_7 )
{
F_3 ( & V_8 ) ;
F_4 ( L_2 ) ;
}
static int F_6 ( struct V_5 * V_9 )
{
int V_10 ;
int V_11 ;
for ( V_10 = V_12 ; V_10 ; V_10 -- ) {
F_4 ( L_3 ) ;
V_11 = F_7 ( V_9 ) ;
if ( V_11 ) {
F_8 ( V_13 ) ;
F_4 ( L_4 , V_11 ) ;
F_9 ( F_10 ( 500 ) ) ;
continue;
}
F_11 ( & V_8 ) ;
if ( V_9 -> V_14 == V_15 ) {
F_4 ( L_5 ) ;
continue;
}
if ( ! ( V_16 . V_2 . V_17 . V_18 & 0x80 ) ) {
F_4 ( L_6 ,
V_16 . V_2 . V_17 . V_18 ) ;
continue;
}
if ( ! V_19 . V_20 ) {
memcpy ( & V_3 , & V_16 . V_2 , sizeof( V_3 ) ) ;
F_4 ( L_7 ) ;
return 0 ;
}
F_11 ( & V_4 ) ;
F_4 ( L_8 ) ;
return 0 ;
}
return - V_21 ;
}
int F_12 ( void )
{
struct V_5 V_6 ;
int V_11 ;
F_13 ( & V_22 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_16 . V_17 . V_23 = sizeof( V_16 ) ;
V_16 . V_2 . V_17 . V_23 = sizeof( struct V_3 ) ;
V_16 . V_2 . V_17 . type = V_24 ;
V_16 . V_2 . V_25 = V_26 ;
V_16 . V_2 . V_27 = V_28 ;
V_16 . V_2 . V_29 = 4712 ;
V_16 . V_2 . V_30 = 1 ;
V_6 . V_16 = & V_16 ;
V_6 . V_31 = V_32 ;
V_6 . V_14 = V_33 ;
V_6 . V_34 = F_5 ;
V_11 = F_6 ( & V_6 ) ;
if ( V_11 ) {
F_14 ( L_9 ) ;
goto V_35;
}
if ( V_16 . V_17 . V_36 != 0x0020 ) {
F_4 ( L_10 , V_16 . V_17 . V_36 ) ;
V_11 = - V_21 ;
goto V_35;
}
switch ( V_3 . V_37 ) {
case 0 :
V_11 = V_3 . V_38 ;
break;
default:
F_14 ( L_11 , V_3 . V_37 ) ;
V_11 = - V_21 ;
goto V_35;
}
F_4 ( L_12 , V_11 ) ;
V_35:
F_15 ( & V_22 ) ;
return V_11 ;
}
int F_16 ( void * V_39 , int V_40 , int V_41 )
{
struct V_5 V_6 ;
int V_11 ;
F_13 ( & V_22 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_16 . V_17 . V_23 = sizeof( V_16 ) ;
V_16 . V_2 . V_17 . V_23 = sizeof( struct V_3 ) ;
V_16 . V_2 . V_17 . type = V_24 ;
V_16 . V_2 . V_17 . V_18 = 0 ;
V_16 . V_2 . V_25 = V_42 ;
V_16 . V_2 . V_27 = V_28 ;
V_16 . V_2 . V_29 = 4712 ;
V_16 . V_2 . V_43 = V_44 ;
V_16 . V_2 . V_37 = 0 ;
V_16 . V_2 . V_38 = V_41 ;
V_16 . V_2 . V_45 = ( unsigned long ) V_39 ;
V_16 . V_2 . V_46 = V_40 ;
V_16 . V_2 . V_47 = 0 ;
V_16 . V_2 . V_30 = 1 ;
V_6 . V_16 = & V_16 ;
V_6 . V_31 = V_32 ;
V_6 . V_14 = V_33 ;
V_6 . V_34 = F_5 ;
V_11 = F_6 ( & V_6 ) ;
if ( V_11 ) {
F_14 ( L_13 , V_11 ) ;
goto V_35;
}
if ( V_16 . V_17 . V_36 != 0x0020 ) {
F_4 ( L_14 , V_16 . V_17 . V_36 ) ;
V_11 = - V_21 ;
goto V_35;
}
switch ( V_3 . V_37 ) {
case V_48 :
F_4 ( L_15 ) ;
break;
case V_49 :
F_4 ( L_16 , V_3 . V_38 ) ;
break;
case V_50 :
F_4 ( L_17 ) ;
default:
F_14 ( L_18 ,
V_3 . V_37 ) ;
V_11 = - V_21 ;
}
V_35:
F_15 ( & V_22 ) ;
return V_11 ;
}
static int T_1 F_17 ( void )
{
int V_11 ;
V_11 = F_18 ( & V_19 ) ;
if ( V_11 )
return V_11 ;
if ( F_12 () == 0 ) {
F_19 ( & V_19 ) ;
return - V_51 ;
}
return 0 ;
}
static int T_1 F_20 ( void )
{
F_4 ( L_19 ) ;
V_19 . V_52 = 0 ;
V_19 . V_20 = NULL ;
return F_17 () ;
}
static int T_1 F_21 ( void )
{
F_4 ( L_20 ) ;
V_19 . V_52 = V_53 ;
V_19 . V_20 = F_1 ;
return F_17 () ;
}
int T_1 F_22 ( void )
{
if ( V_54 . type != V_55 )
return 0 ;
V_56 = F_23 ( L_21 , 4 , 1 , 4 * sizeof( long ) ) ;
F_24 ( V_56 , & V_57 ) ;
F_25 ( V_56 , 6 ) ;
if ( F_20 () == 0 )
goto V_35;
if ( F_21 () == 0 )
goto V_35;
F_4 ( L_22 ) ;
return - V_51 ;
V_35:
F_4 ( L_23 ) ;
return 0 ;
}
void T_2 F_26 ( void )
{
F_27 ( V_56 ) ;
F_19 ( & V_19 ) ;
}
