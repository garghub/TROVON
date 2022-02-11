static int F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 & 3 ) == 3 ) ? V_4 : V_5 ;
}
int F_2 ( struct V_1 * V_2 , int V_6 , char * * V_7 )
{
enum V_8 V_9 = F_1 ( V_2 ) ;
struct V_10 * V_11 ;
for ( V_11 = V_12 ; ; V_11 ++ ) {
if ( ( V_2 -> V_13 & V_11 -> V_14 ) != V_11 -> V_15 )
continue;
if ( ( V_2 -> V_16 & V_11 -> V_17 ) != V_11 -> V_18 )
continue;
if ( V_11 -> V_19 == V_20 && ! V_21 . V_19 )
continue;
if ( V_11 -> V_19 == V_22 && V_21 . V_19 )
continue;
if ( V_11 -> V_8 && V_9 != V_11 -> V_8 )
continue;
if ( V_7 )
* V_7 = V_11 -> V_7 ;
V_11 -> V_23 = 1 ;
if ( V_11 -> V_24 >= V_25 && V_9 == V_5 ) {
if ( V_26 || V_6 < 1 )
return V_27 ;
}
return V_11 -> V_24 ;
}
}
static void * F_3 ( struct V_28 * V_29 , T_1 * V_30 )
{
if ( * V_30 >= F_4 ( V_12 ) )
return NULL ;
return & V_12 [ * V_30 ] ;
}
static void * F_5 ( struct V_28 * V_29 , void * V_31 , T_1 * V_30 )
{
if ( ++ ( * V_30 ) >= F_4 ( V_12 ) )
return NULL ;
return & V_12 [ * V_30 ] ;
}
static void F_6 ( struct V_28 * V_29 , void * V_31 )
{
}
static int F_7 ( struct V_28 * V_29 , void * V_31 )
{
struct V_10 * V_19 = V_31 ;
F_8 ( V_29 , L_1 , V_19 -> V_23 , V_19 -> V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_10 ( V_33 , & V_34 ) ;
}
static T_2 F_11 ( struct V_33 * V_33 ,
const char T_3 * V_35 ,
T_4 V_36 , T_1 * V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_4 ( V_12 ) ; V_38 ++ )
V_12 [ V_38 ] . V_23 = 0 ;
return V_36 ;
}
static int T_5 F_12 ( void )
{
struct V_39 * V_40 , * V_41 ;
V_40 = F_13 () ;
if ( ! V_40 )
goto V_42;
V_41 = F_14 ( L_2 , 0444 , V_40 , NULL ,
& V_43 ) ;
if ( ! V_41 )
goto V_42;
return 0 ;
V_42:
return - V_44 ;
}
