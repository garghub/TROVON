static int F_1 ( T_1 V_1 )
{
long V_2 , V_3 ;
unsigned long V_4 [ V_5 ] ;
V_3 = F_2 ( V_6 , V_4 , V_7 ) ;
V_2 = V_4 [ 0 ] ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
return V_3 ;
} else if ( V_2 == V_8 ) {
return - V_9 ;
} else if ( V_2 != V_10 ) {
F_3 ( L_2 ,
V_2 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_4 ( void )
{
if ( F_5 ( & V_12 ) )
return F_6 ( & V_13 ) ;
return 0 ;
}
static int F_7 ( T_1 V_1 )
{
int V_3 = F_8 ( & V_13 ) ;
F_9 ( & V_12 , 0 ) ;
F_9 ( & V_13 . V_14 , 1 ) ;
return V_3 ;
}
static int F_10 ( void )
{
F_9 ( & V_12 , 1 ) ;
F_9 ( & V_13 . V_15 , 0 ) ;
F_9 ( & V_13 . V_14 , 0 ) ;
F_9 ( & V_13 . error , 0 ) ;
V_13 . V_16 = & V_17 ;
F_11 ( V_17 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 , T_3 V_23 )
{
int V_3 ;
if ( ! F_13 ( V_24 ) )
return - V_25 ;
V_7 = F_14 ( V_22 , NULL , 16 ) ;
do {
V_3 = F_1 ( V_26 ) ;
if ( V_3 == - V_9 )
F_15 ( 1 ) ;
} while ( V_3 == - V_9 );
if ( ! V_3 )
V_3 = F_16 ( V_26 ) ;
V_7 = 0 ;
if ( ! V_3 )
V_3 = V_23 ;
return V_3 ;
}
static int F_17 ( struct V_27 * V_28 )
{
int V_3 ;
if ( ( V_3 = F_18 ( & V_29 ) ) )
return V_3 ;
V_28 -> V_30 = 0 ;
V_28 -> V_31 = & V_29 ;
if ( ( V_3 = F_19 ( & V_29 , & V_32 ) ) )
goto V_33;
return 0 ;
V_33:
F_20 ( & V_29 ) ;
return V_3 ;
}
static int T_4 F_21 ( void )
{
int V_3 ;
if ( ! F_22 ( V_34 ) || ! F_23 ( V_35 ) )
return 0 ;
V_13 . V_36 = F_24 ( L_3 ) ;
if ( V_13 . V_36 == V_37 )
return 0 ;
if ( ( V_3 = F_17 ( & V_38 ) ) )
return V_3 ;
V_39 . V_40 = F_4 ;
F_25 ( & V_41 ) ;
return 0 ;
}
