static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return ( V_2 -> V_5 && ( V_2 -> V_6 & 3 ) == 3 ) ? V_7 : V_8 ;
return V_8 ;
}
int F_2 ( struct V_1 * V_2 , int V_9 , char * * V_10 )
{
enum V_11 V_12 = F_1 ( V_2 ) ;
struct V_13 * V_14 ;
for ( V_14 = V_15 ; ; V_14 ++ ) {
if ( ( V_2 -> V_16 & V_14 -> V_17 ) != V_14 -> V_18 )
continue;
if ( ( V_2 -> V_3 & V_14 -> V_19 ) != V_14 -> V_20 )
continue;
if ( V_14 -> V_21 == V_22 && ! V_23 )
continue;
if ( V_14 -> V_21 == V_24 && V_23 )
continue;
if ( V_14 -> V_11 && V_12 != V_14 -> V_11 )
continue;
if ( V_10 )
* V_10 = V_14 -> V_10 ;
V_14 -> V_25 = 1 ;
if ( V_14 -> V_26 >= V_27 && V_12 == V_8 ) {
if ( V_28 || V_9 < 1 )
return V_29 ;
}
return V_14 -> V_26 ;
}
}
static void * F_3 ( struct V_30 * V_31 , T_1 * V_32 )
{
if ( * V_32 >= F_4 ( V_15 ) )
return NULL ;
return & V_15 [ * V_32 ] ;
}
static void * F_5 ( struct V_30 * V_31 , void * V_33 , T_1 * V_32 )
{
if ( ++ ( * V_32 ) >= F_4 ( V_15 ) )
return NULL ;
return & V_15 [ * V_32 ] ;
}
static void F_6 ( struct V_30 * V_31 , void * V_33 )
{
}
static int F_7 ( struct V_30 * V_31 , void * V_33 )
{
struct V_13 * V_21 = V_33 ;
F_8 ( V_31 , L_1 , V_21 -> V_25 , V_21 -> V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_10 ( V_35 , & V_36 ) ;
}
static T_2 F_11 ( struct V_35 * V_35 ,
const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_4 ( V_15 ) ; V_40 ++ )
V_15 [ V_40 ] . V_25 = 0 ;
return V_38 ;
}
static int T_5 F_12 ( void )
{
struct V_41 * V_42 , * V_43 ;
V_42 = F_13 () ;
if ( ! V_42 )
goto V_44;
V_43 = F_14 ( L_2 , 0444 , V_42 , NULL ,
& V_45 ) ;
if ( ! V_43 )
goto V_44;
return 0 ;
V_44:
return - V_46 ;
}
