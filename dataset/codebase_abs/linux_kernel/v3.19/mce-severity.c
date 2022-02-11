static int F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 & 3 ) == 3 ) ? V_4 : V_5 ;
}
int F_2 ( struct V_1 * V_2 , int V_6 , char * * V_7 , bool V_8 )
{
enum V_9 V_10 = ( V_8 ? V_11 : V_12 ) ;
enum V_13 V_14 = F_1 ( V_2 ) ;
struct V_15 * V_16 ;
for ( V_16 = V_17 ; ; V_16 ++ ) {
if ( ( V_2 -> V_18 & V_16 -> V_19 ) != V_16 -> V_20 )
continue;
if ( ( V_2 -> V_21 & V_16 -> V_22 ) != V_16 -> V_23 )
continue;
if ( V_16 -> V_24 == V_25 && ! V_26 . V_24 )
continue;
if ( V_16 -> V_24 == V_27 && V_26 . V_24 )
continue;
if ( V_16 -> V_13 && V_14 != V_16 -> V_13 )
continue;
if ( V_16 -> V_10 && V_10 != V_16 -> V_10 )
continue;
if ( V_7 )
* V_7 = V_16 -> V_7 ;
V_16 -> V_28 = 1 ;
if ( V_16 -> V_29 >= V_30 && V_14 == V_5 ) {
if ( V_31 || V_6 < 1 )
return V_32 ;
}
return V_16 -> V_29 ;
}
}
static void * F_3 ( struct V_33 * V_34 , T_1 * V_35 )
{
if ( * V_35 >= F_4 ( V_17 ) )
return NULL ;
return & V_17 [ * V_35 ] ;
}
static void * F_5 ( struct V_33 * V_34 , void * V_36 , T_1 * V_35 )
{
if ( ++ ( * V_35 ) >= F_4 ( V_17 ) )
return NULL ;
return & V_17 [ * V_35 ] ;
}
static void F_6 ( struct V_33 * V_34 , void * V_36 )
{
}
static int F_7 ( struct V_33 * V_34 , void * V_36 )
{
struct V_15 * V_24 = V_36 ;
F_8 ( V_34 , L_1 , V_24 -> V_28 , V_24 -> V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_37 * V_37 , struct V_38 * V_38 )
{
return F_10 ( V_38 , & V_39 ) ;
}
static T_2 F_11 ( struct V_38 * V_38 ,
const char T_3 * V_40 ,
T_4 V_41 , T_1 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_4 ( V_17 ) ; V_43 ++ )
V_17 [ V_43 ] . V_28 = 0 ;
return V_41 ;
}
static int T_5 F_12 ( void )
{
struct V_44 * V_45 , * V_46 ;
V_45 = F_13 () ;
if ( ! V_45 )
goto V_47;
V_46 = F_14 ( L_2 , 0444 , V_45 , NULL ,
& V_48 ) ;
if ( ! V_46 )
goto V_47;
return 0 ;
V_47:
return - V_49 ;
}
