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
F_8 ( V_1 [ V_4 ] . V_7 , V_3 , V_8 ) ;
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
int F_9 ( char * V_3 )
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
static T_1 F_10 ( struct V_18 * V_19 , char * V_20 )
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
static T_1 F_11 ( struct V_18 * V_21 , const char * V_20 ,
T_2 V_22 )
{
int V_23 ;
char V_3 [ V_8 ] ;
if ( V_22 < 5 )
return - V_24 ;
V_23 = F_8 ( V_3 , V_20 + 4 , V_8 ) ;
if ( sizeof( V_3 ) <= V_23 )
return - V_24 ;
if ( ! strncmp ( V_20 , L_3 , 4 ) ) {
if ( F_7 ( V_3 ) < 0 )
return - V_25 ;
F_12 ( L_4 , V_3 ) ;
return V_22 ;
}
if ( ! strncmp ( V_20 , L_5 , 4 ) ) {
if ( F_9 ( V_3 ) < 0 )
return - V_26 ;
F_12 ( L_6 , V_3 ) ;
return V_22 ;
}
return - V_24 ;
}
static T_1 F_13 ( struct V_18 * V_21 , const char * V_20 ,
T_2 V_22 )
{
int V_11 ;
int V_23 ;
struct V_9 * V_10 ;
V_23 = F_14 ( V_20 , V_8 ) ;
if ( ! ( V_23 < V_8 ) )
return - V_24 ;
V_10 = F_4 ( V_20 ) ;
if ( ! V_10 )
return - V_26 ;
V_11 = F_15 ( & V_10 -> V_27 -> V_21 ) ;
if ( V_11 < 0 ) {
F_16 ( & V_10 -> V_27 -> V_21 , L_7 ) ;
return V_11 ;
}
return V_22 ;
}
static struct V_28 * F_17 ( struct V_29 * V_30 )
{
struct V_28 * V_31 , * V_32 ;
F_18 (priv, tmp, listhead, list) {
F_19 ( & V_31 -> V_33 ) ;
return V_31 ;
}
return NULL ;
}
static struct V_28 * F_20 ( struct V_34 * V_35 )
{
unsigned long V_36 ;
struct V_28 * V_31 ;
F_21 ( & V_35 -> V_37 , V_36 ) ;
V_31 = F_17 ( & V_35 -> V_38 ) ;
if ( V_31 )
goto V_39;
V_31 = F_17 ( & V_35 -> V_40 ) ;
if ( V_31 )
goto V_39;
V_31 = F_17 ( & V_35 -> V_41 ) ;
V_39:
F_22 ( & V_35 -> V_37 , V_36 ) ;
return V_31 ;
}
void F_23 ( struct V_34 * V_35 )
{
struct V_28 * V_31 ;
struct V_42 * V_42 ;
F_24 ( & V_35 -> V_27 -> V_21 , L_8 , V_35 ) ;
while ( ( V_31 = F_20 ( V_35 ) ) ) {
V_42 = V_31 -> V_42 ;
F_24 ( & V_35 -> V_27 -> V_21 , L_9 , V_42 ) ;
F_25 ( V_42 ) ;
F_26 ( V_43 , V_31 ) ;
F_27 ( V_42 -> V_44 ) ;
V_42 -> V_44 = NULL ;
F_27 ( V_42 -> V_45 ) ;
V_42 -> V_45 = NULL ;
F_28 ( V_42 ) ;
}
}
static int T_3 F_29 ( void )
{
int V_11 ;
F_1 () ;
V_43 = F_30 ( V_28 , V_46 ) ;
if ( ! V_43 ) {
F_31 ( L_10 ) ;
return - V_25 ;
}
V_11 = F_32 ( & V_47 , V_48 ) ;
if ( V_11 ) {
F_31 ( L_11 , V_11 ) ;
goto V_49;
}
V_11 = F_33 ( & V_47 . V_50 . V_51 ,
& V_52 ) ;
if ( V_11 ) {
F_31 ( L_12 ) ;
goto V_53;
}
V_11 = F_33 ( & V_47 . V_50 . V_51 ,
& V_54 ) ;
if ( V_11 ) {
F_31 ( L_12 ) ;
goto V_53;
}
F_34 ( V_55 L_13 V_56 L_2 ) ;
return V_11 ;
V_53:
F_35 ( & V_47 ) ;
V_49:
F_36 ( V_43 ) ;
return V_11 ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_47 . V_50 . V_51 ,
& V_52 ) ;
F_38 ( & V_47 . V_50 . V_51 ,
& V_54 ) ;
F_35 ( & V_47 ) ;
F_36 ( V_43 ) ;
}
