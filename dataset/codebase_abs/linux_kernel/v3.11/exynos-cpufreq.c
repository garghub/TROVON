static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ,
V_3 -> V_4 ) ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
return F_4 ( V_3 -> V_6 ) / 1000 ;
}
static int F_5 ( unsigned int V_7 )
{
struct V_8 * V_4 = V_3 -> V_4 ;
int V_9 ;
for ( V_9 = 0 ;
V_4 [ V_9 ] . V_10 != V_11 ; V_9 ++ )
if ( V_4 [ V_9 ] . V_10 == V_7 )
break;
if ( V_4 [ V_9 ] . V_10 == V_11 )
return - V_12 ;
return V_9 ;
}
static int F_6 ( unsigned int V_13 )
{
struct V_8 * V_4 = V_3 -> V_4 ;
unsigned int * V_14 = V_3 -> V_14 ;
struct V_1 * V_2 = F_7 ( 0 ) ;
unsigned int V_15 , V_16 = 0 ;
unsigned int V_17 = V_3 -> V_17 ;
int V_9 , V_18 ;
int V_19 = 0 ;
V_20 . V_21 = V_2 -> V_22 ;
V_20 . V_23 = V_13 ;
if ( V_20 . V_23 == V_20 . V_21 )
goto V_24;
V_18 = F_5 ( V_20 . V_21 ) ;
if ( V_18 < 0 ) {
V_19 = V_18 ;
goto V_24;
}
V_9 = F_5 ( V_13 ) ;
if ( V_9 < 0 ) {
V_19 = V_9 ;
goto V_24;
}
if ( V_3 -> V_25 != NULL ) {
if ( V_3 -> V_25 ( V_18 , V_9 ) &&
( V_4 [ V_9 ] . V_10 < V_17 ) &&
( V_4 [ V_18 ] . V_10 < V_17 ) )
V_16 = V_14 [ V_3 -> V_26 ] ;
}
V_15 = V_14 [ V_9 ] ;
F_8 ( V_2 , & V_20 , V_27 ) ;
if ( ( V_20 . V_23 > V_20 . V_21 ) && ! V_16 ) {
V_19 = F_9 ( V_28 , V_15 , V_15 ) ;
if ( V_19 ) {
F_10 ( L_1 ,
V_29 , V_15 ) ;
V_20 . V_23 = V_20 . V_21 ;
goto V_30;
}
}
if ( V_16 ) {
V_19 = F_9 ( V_28 , V_16 ,
V_16 ) ;
if ( V_19 ) {
F_10 ( L_1 ,
V_29 , V_16 ) ;
V_20 . V_23 = V_20 . V_21 ;
goto V_30;
}
}
V_3 -> V_31 ( V_18 , V_9 ) ;
V_30:
F_8 ( V_2 , & V_20 , V_32 ) ;
if ( V_19 )
goto V_24;
if ( ( V_20 . V_23 < V_20 . V_21 ) ||
( ( V_20 . V_23 > V_20 . V_21 ) && V_16 ) ) {
F_9 ( V_28 , V_15 ,
V_15 ) ;
if ( V_19 ) {
F_10 ( L_1 ,
V_29 , V_15 ) ;
goto V_24;
}
}
V_24:
F_11 ( V_2 ) ;
return V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_13 ,
unsigned int V_33 )
{
struct V_8 * V_4 = V_3 -> V_4 ;
unsigned int V_9 ;
unsigned int V_34 ;
int V_19 = 0 ;
F_13 ( & V_35 ) ;
if ( V_36 )
goto V_24;
if ( F_14 ( V_2 , V_4 ,
V_13 , V_33 , & V_9 ) ) {
V_19 = - V_12 ;
goto V_24;
}
V_34 = V_4 [ V_9 ] . V_10 ;
V_19 = F_6 ( V_34 ) ;
V_24:
F_15 ( & V_35 ) ;
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_40 )
{
int V_19 ;
switch ( V_39 ) {
case V_41 :
F_13 ( & V_35 ) ;
V_36 = true ;
F_15 ( & V_35 ) ;
V_19 = F_6 ( V_42 ) ;
if ( V_19 < 0 )
return V_43 ;
break;
case V_44 :
F_13 ( & V_35 ) ;
V_36 = false ;
F_15 ( & V_35 ) ;
break;
}
return V_45 ;
}
static int F_19 ( struct V_1 * V_2 )
{
V_2 -> V_22 = V_2 -> V_46 = V_2 -> V_47 = F_3 ( V_2 -> V_5 ) ;
F_20 ( V_3 -> V_4 , V_2 -> V_5 ) ;
V_2 -> V_48 . V_49 = 100000 ;
F_21 ( V_2 -> V_50 ) ;
return F_22 ( V_2 , V_3 -> V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_5 ) ;
return 0 ;
}
static int T_1 F_25 ( void )
{
int V_19 = - V_12 ;
V_3 = F_26 ( sizeof( struct V_51 ) , V_52 ) ;
if ( ! V_3 )
return - V_53 ;
if ( F_27 () )
V_19 = F_28 ( V_3 ) ;
else if ( F_29 () || F_30 () )
V_19 = F_31 ( V_3 ) ;
else if ( F_32 () )
V_19 = F_33 ( V_3 ) ;
else
return 0 ;
if ( V_19 )
goto V_54;
if ( V_3 -> V_31 == NULL ) {
F_10 ( L_2 , V_29 ) ;
goto V_54;
}
V_28 = F_34 ( NULL , L_3 ) ;
if ( F_35 ( V_28 ) ) {
F_10 ( L_4 , V_29 ) ;
goto V_54;
}
V_42 = F_3 ( 0 ) ;
F_36 ( & V_55 ) ;
if ( F_37 ( & V_56 ) ) {
F_10 ( L_5 , V_29 ) ;
goto V_57;
}
return 0 ;
V_57:
F_38 ( & V_55 ) ;
F_39 ( V_28 ) ;
V_54:
F_40 ( V_3 ) ;
F_41 ( L_6 , V_29 ) ;
return - V_12 ;
}
