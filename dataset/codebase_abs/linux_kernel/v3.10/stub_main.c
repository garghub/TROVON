static void F_1 ( void )
{
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
F_2 ( & V_2 ) ;
}
static int F_3 ( const char * V_3 )
{
int V_4 ;
int V_5 = - 1 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
if ( V_1 [ V_4 ] . V_7 [ 0 ] )
if ( ! strncmp ( V_1 [ V_4 ] . V_7 , V_3 , V_8 ) ) {
V_5 = V_4 ;
break;
}
return V_5 ;
}
struct V_9 * F_4 ( const char * V_3 )
{
int V_5 ;
struct V_9 * V_10 = NULL ;
F_5 ( & V_2 ) ;
V_5 = F_3 ( V_3 ) ;
if ( V_5 >= 0 )
V_10 = & ( V_1 [ V_5 ] ) ;
F_6 ( & V_2 ) ;
return V_10 ;
}
static int F_7 ( char * V_3 )
{
int V_4 ;
int V_11 = - 1 ;
F_5 ( & V_2 ) ;
if ( F_3 ( V_3 ) >= 0 ) {
V_11 = 0 ;
goto V_12;
}
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
if ( ! V_1 [ V_4 ] . V_7 [ 0 ] ) {
strncpy ( V_1 [ V_4 ] . V_7 , V_3 , V_8 ) ;
if ( ( V_1 [ V_4 ] . V_13 != V_14 ) &&
( V_1 [ V_4 ] . V_13 != V_15 ) )
V_1 [ V_4 ] . V_13 = V_16 ;
V_11 = 0 ;
break;
}
V_12:
F_6 ( & V_2 ) ;
return V_11 ;
}
int F_8 ( char * V_3 )
{
int V_5 ;
int V_11 = - 1 ;
F_5 ( & V_2 ) ;
V_5 = F_3 ( V_3 ) ;
if ( V_5 < 0 )
goto V_12;
V_11 = 0 ;
if ( V_1 [ V_5 ] . V_13 == V_17 )
memset ( V_1 [ V_5 ] . V_7 , 0 , V_8 ) ;
if ( ( V_1 [ V_5 ] . V_13 != V_17 ) &&
( V_1 [ V_5 ] . V_13 != V_16 ) )
V_1 [ V_5 ] . V_13 = V_15 ;
V_12:
F_6 ( & V_2 ) ;
return V_11 ;
}
static T_1 F_9 ( struct V_18 * V_19 , char * V_20 )
{
int V_4 ;
char * V_12 = V_20 ;
F_5 ( & V_2 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
if ( V_1 [ V_4 ] . V_7 [ 0 ] )
V_12 += sprintf ( V_12 , L_1 , V_1 [ V_4 ] . V_7 ) ;
F_6 ( & V_2 ) ;
V_12 += sprintf ( V_12 , L_2 ) ;
return V_12 - V_20 ;
}
static T_1 F_10 ( struct V_18 * V_21 , const char * V_20 ,
T_2 V_22 )
{
int V_23 ;
char V_3 [ V_8 ] ;
if ( V_22 < 5 )
return - V_24 ;
V_23 = F_11 ( V_20 + 4 , V_8 ) ;
if ( ! ( V_23 < V_8 ) )
return - V_24 ;
strncpy ( V_3 , V_20 + 4 , V_8 ) ;
if ( ! strncmp ( V_20 , L_3 , 4 ) ) {
if ( F_7 ( V_3 ) < 0 )
return - V_25 ;
F_12 ( L_4 , V_3 ) ;
return V_22 ;
}
if ( ! strncmp ( V_20 , L_5 , 4 ) ) {
if ( F_8 ( V_3 ) < 0 )
return - V_26 ;
F_12 ( L_6 , V_3 ) ;
return V_22 ;
}
return - V_24 ;
}
static struct V_27 * F_13 ( struct V_28 * V_29 )
{
struct V_27 * V_30 , * V_31 ;
F_14 (priv, tmp, listhead, list) {
F_15 ( & V_30 -> V_32 ) ;
return V_30 ;
}
return NULL ;
}
static struct V_27 * F_16 ( struct V_33 * V_34 )
{
unsigned long V_35 ;
struct V_27 * V_30 ;
F_17 ( & V_34 -> V_36 , V_35 ) ;
V_30 = F_13 ( & V_34 -> V_37 ) ;
if ( V_30 )
goto V_38;
V_30 = F_13 ( & V_34 -> V_39 ) ;
if ( V_30 )
goto V_38;
V_30 = F_13 ( & V_34 -> V_40 ) ;
V_38:
F_18 ( & V_34 -> V_36 , V_35 ) ;
return V_30 ;
}
void F_19 ( struct V_33 * V_34 )
{
struct V_27 * V_30 ;
struct V_41 * V_41 ;
F_20 ( & V_34 -> V_42 -> V_21 , L_7 , V_34 ) ;
while ( ( V_30 = F_16 ( V_34 ) ) ) {
V_41 = V_30 -> V_41 ;
F_20 ( & V_34 -> V_42 -> V_21 , L_8 , V_41 ) ;
F_21 ( V_41 ) ;
F_22 ( V_43 , V_30 ) ;
F_23 ( V_41 -> V_44 ) ;
F_23 ( V_41 -> V_45 ) ;
F_24 ( V_41 ) ;
}
}
static int T_3 F_25 ( void )
{
int V_11 ;
F_1 () ;
V_43 = F_26 ( V_27 , V_46 ) ;
if ( ! V_43 ) {
F_27 ( L_9 ) ;
return - V_25 ;
}
V_11 = F_28 ( & V_47 ) ;
if ( V_11 < 0 ) {
F_27 ( L_10 , V_11 ) ;
goto V_48;
}
V_11 = F_29 ( & V_47 . V_49 . V_50 ,
& V_51 ) ;
if ( V_11 < 0 ) {
F_27 ( L_11 ) ;
goto V_52;
}
F_30 ( V_53 L_12 V_54 L_2 ) ;
return V_11 ;
V_52:
F_31 ( & V_47 ) ;
V_48:
F_32 ( V_43 ) ;
return V_11 ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_47 . V_49 . V_50 ,
& V_51 ) ;
F_31 ( & V_47 ) ;
F_32 ( V_43 ) ;
}
