int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ,
V_3 -> V_4 ) ;
}
unsigned int F_3 ( unsigned int V_5 )
{
return F_4 ( V_3 -> V_6 ) / 1000 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned int V_8 )
{
unsigned int V_9 , V_10 ;
unsigned int V_11 , V_12 = 0 ;
int V_13 = 0 ;
struct V_14 * V_4 = V_3 -> V_4 ;
unsigned int * V_15 = V_3 -> V_15 ;
unsigned int V_16 = V_3 -> V_16 ;
F_6 ( & V_17 ) ;
V_18 . V_19 = V_2 -> V_20 ;
if ( V_21 && V_7 != V_22 ) {
V_13 = - V_23 ;
goto V_24;
}
if ( F_7 ( V_2 , V_4 ,
V_18 . V_19 , V_8 , & V_10 ) ) {
V_13 = - V_25 ;
goto V_24;
}
if ( F_7 ( V_2 , V_4 ,
V_7 , V_8 , & V_9 ) ) {
V_13 = - V_25 ;
goto V_24;
}
V_18 . V_26 = V_4 [ V_9 ] . V_27 ;
V_18 . V_5 = V_2 -> V_5 ;
if ( V_3 -> V_28 != NULL ) {
if ( V_3 -> V_28 ( V_10 , V_9 ) &&
( V_4 [ V_9 ] . V_27 < V_16 ) &&
( V_4 [ V_10 ] . V_27 < V_16 ) )
V_12 = V_15 [ V_3 -> V_29 ] ;
}
V_11 = V_15 [ V_9 ] ;
F_8 ( & V_18 , V_30 ) ;
if ( ( V_18 . V_26 > V_18 . V_19 ) && ! V_12 ) {
F_9 ( V_31 , V_11 ,
V_11 ) ;
}
if ( V_12 )
F_9 ( V_31 , V_12 ,
V_12 ) ;
if ( V_18 . V_26 != V_18 . V_19 )
V_3 -> V_32 ( V_10 , V_9 ) ;
F_8 ( & V_18 , V_33 ) ;
if ( ( V_18 . V_26 < V_18 . V_19 ) ||
( ( V_18 . V_26 > V_18 . V_19 ) && V_12 ) ) {
F_9 ( V_31 , V_11 ,
V_11 ) ;
}
V_24:
F_10 ( & V_17 ) ;
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_13 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
struct V_1 * V_2 = F_14 ( 0 ) ;
static unsigned int V_38 ;
unsigned int V_39 ;
F_6 ( & V_17 ) ;
switch ( V_36 ) {
case V_40 :
if ( V_21 )
goto V_24;
V_21 = true ;
if ( V_22 ) {
V_38 = F_3 ( 0 ) ;
F_10 ( & V_17 ) ;
F_5 ( V_2 , V_22 ,
V_41 ) ;
F_6 ( & V_17 ) ;
}
break;
case V_42 :
if ( V_38 ) {
V_39 = V_22 ;
V_22 = V_38 ;
F_10 ( & V_17 ) ;
F_5 ( V_2 , V_22 ,
V_41 ) ;
F_6 ( & V_17 ) ;
V_22 = V_39 ;
}
V_21 = false ;
break;
}
V_24:
F_10 ( & V_17 ) ;
return V_43 ;
}
static int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_20 = V_2 -> V_44 = V_2 -> V_45 = F_3 ( V_2 -> V_5 ) ;
F_16 ( V_3 -> V_4 , V_2 -> V_5 ) ;
V_2 -> V_46 . V_47 = 100000 ;
if ( F_17 () == 1 ) {
F_18 ( V_2 -> V_48 , V_49 ) ;
F_18 ( V_2 -> V_50 , V_51 ) ;
} else {
F_19 ( V_2 -> V_50 ) ;
}
return F_20 ( V_2 , V_3 -> V_4 ) ;
}
static int T_1 F_21 ( void )
{
int V_13 = - V_25 ;
V_3 = F_22 ( sizeof( struct V_52 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
if ( F_23 () )
V_13 = F_24 ( V_3 ) ;
else
F_25 ( L_1 , V_55 ) ;
if ( V_13 )
goto V_56;
if ( V_3 -> V_32 == NULL ) {
F_25 ( L_2 , V_55 ) ;
goto V_56;
}
V_31 = F_26 ( NULL , L_3 ) ;
if ( F_27 ( V_31 ) ) {
F_25 ( L_4 , V_55 ) ;
goto V_56;
}
F_28 ( & V_57 ) ;
if ( F_29 ( & V_58 ) ) {
F_25 ( L_5 , V_55 ) ;
goto V_59;
}
return 0 ;
V_59:
F_30 ( & V_57 ) ;
if ( ! F_27 ( V_31 ) )
F_31 ( V_31 ) ;
V_56:
F_32 ( V_3 ) ;
F_33 ( L_6 , V_55 ) ;
return - V_25 ;
}
