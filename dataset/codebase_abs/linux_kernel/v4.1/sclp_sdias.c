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
F_9 ( V_14 ) ;
continue;
}
F_10 ( & V_8 ) ;
if ( V_9 -> V_15 == V_16 ) {
F_4 ( L_5 ) ;
continue;
}
if ( ! ( V_17 . V_2 . V_18 . V_19 & 0x80 ) ) {
F_4 ( L_6 ,
V_17 . V_2 . V_18 . V_19 ) ;
continue;
}
if ( ! V_20 . V_21 ) {
memcpy ( & V_3 , & V_17 . V_2 , sizeof( V_3 ) ) ;
F_4 ( L_7 ) ;
return 0 ;
}
F_10 ( & V_4 ) ;
F_4 ( L_8 ) ;
return 0 ;
}
return - V_22 ;
}
int F_11 ( void )
{
struct V_5 V_6 ;
int V_11 ;
F_12 ( & V_23 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_17 . V_18 . V_24 = sizeof( V_17 ) ;
V_17 . V_2 . V_18 . V_24 = sizeof( struct V_3 ) ;
V_17 . V_2 . V_18 . type = V_25 ;
V_17 . V_2 . V_26 = V_27 ;
V_17 . V_2 . V_28 = V_29 ;
V_17 . V_2 . V_30 = 4712 ;
V_17 . V_2 . V_31 = 1 ;
V_6 . V_17 = & V_17 ;
V_6 . V_32 = V_33 ;
V_6 . V_15 = V_34 ;
V_6 . V_35 = F_5 ;
V_11 = F_6 ( & V_6 ) ;
if ( V_11 ) {
F_13 ( L_9 ) ;
goto V_36;
}
if ( V_17 . V_18 . V_37 != 0x0020 ) {
F_4 ( L_10 , V_17 . V_18 . V_37 ) ;
V_11 = - V_22 ;
goto V_36;
}
switch ( V_3 . V_38 ) {
case 0 :
V_11 = V_3 . V_39 ;
break;
default:
F_13 ( L_11 , V_3 . V_38 ) ;
V_11 = - V_22 ;
goto V_36;
}
F_4 ( L_12 , V_11 ) ;
V_36:
F_14 ( & V_23 ) ;
return V_11 ;
}
int F_15 ( void * V_40 , int V_41 , int V_42 )
{
struct V_5 V_6 ;
int V_11 ;
F_12 ( & V_23 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_17 . V_18 . V_24 = sizeof( V_17 ) ;
V_17 . V_2 . V_18 . V_24 = sizeof( struct V_3 ) ;
V_17 . V_2 . V_18 . type = V_25 ;
V_17 . V_2 . V_18 . V_19 = 0 ;
V_17 . V_2 . V_26 = V_43 ;
V_17 . V_2 . V_28 = V_29 ;
V_17 . V_2 . V_30 = 4712 ;
V_17 . V_2 . V_44 = V_45 ;
V_17 . V_2 . V_38 = 0 ;
V_17 . V_2 . V_39 = V_42 ;
V_17 . V_2 . V_46 = ( unsigned long ) V_40 ;
V_17 . V_2 . V_47 = V_41 ;
V_17 . V_2 . V_48 = 0 ;
V_17 . V_2 . V_31 = 1 ;
V_6 . V_17 = & V_17 ;
V_6 . V_32 = V_33 ;
V_6 . V_15 = V_34 ;
V_6 . V_35 = F_5 ;
V_11 = F_6 ( & V_6 ) ;
if ( V_11 ) {
F_13 ( L_13 , V_11 ) ;
goto V_36;
}
if ( V_17 . V_18 . V_37 != 0x0020 ) {
F_4 ( L_14 , V_17 . V_18 . V_37 ) ;
V_11 = - V_22 ;
goto V_36;
}
switch ( V_3 . V_38 ) {
case V_49 :
F_4 ( L_15 ) ;
break;
case V_50 :
F_4 ( L_16 , V_3 . V_39 ) ;
break;
case V_51 :
F_4 ( L_17 ) ;
default:
F_13 ( L_18 ,
V_3 . V_38 ) ;
V_11 = - V_22 ;
}
V_36:
F_14 ( & V_23 ) ;
return V_11 ;
}
static int T_1 F_16 ( void )
{
int V_11 ;
V_11 = F_17 ( & V_20 ) ;
if ( V_11 )
return V_11 ;
if ( F_11 () == 0 ) {
F_18 ( & V_20 ) ;
return - V_52 ;
}
return 0 ;
}
static int T_1 F_19 ( void )
{
F_4 ( L_19 ) ;
V_20 . V_53 = 0 ;
V_20 . V_21 = NULL ;
return F_16 () ;
}
static int T_1 F_20 ( void )
{
F_4 ( L_20 ) ;
V_20 . V_53 = V_54 ;
V_20 . V_21 = F_1 ;
return F_16 () ;
}
int T_1 F_21 ( void )
{
if ( V_55 . type != V_56 )
return 0 ;
V_57 = F_22 ( L_21 , 4 , 1 , 4 * sizeof( long ) ) ;
F_23 ( V_57 , & V_58 ) ;
F_24 ( V_57 , 6 ) ;
if ( F_19 () == 0 )
goto V_36;
if ( F_20 () == 0 )
goto V_36;
F_4 ( L_22 ) ;
return - V_52 ;
V_36:
F_4 ( L_23 ) ;
return 0 ;
}
void T_2 F_25 ( void )
{
F_26 ( V_57 ) ;
F_18 ( & V_20 ) ;
}
