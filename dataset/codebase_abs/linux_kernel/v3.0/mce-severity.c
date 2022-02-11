static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return ( V_2 -> V_5 && ( V_2 -> V_6 & 3 ) == 3 ) ? V_7 : V_8 ;
return V_8 ;
}
int F_2 ( struct V_1 * V_9 , int V_10 , char * * V_11 )
{
enum V_12 V_13 = F_1 ( V_9 ) ;
struct V_14 * V_15 ;
for ( V_15 = V_16 ; ; V_15 ++ ) {
if ( ( V_9 -> V_17 & V_15 -> V_18 ) != V_15 -> V_19 )
continue;
if ( ( V_9 -> V_3 & V_15 -> V_20 ) != V_15 -> V_21 )
continue;
if ( V_15 -> V_22 == V_23 && ! V_24 )
continue;
if ( V_15 -> V_22 == V_25 && V_24 )
continue;
if ( V_15 -> V_12 && V_13 != V_15 -> V_12 )
continue;
if ( V_11 )
* V_11 = V_15 -> V_11 ;
V_15 -> V_26 = 1 ;
if ( V_15 -> V_27 >= V_28 && V_13 == V_8 ) {
if ( V_29 || V_10 < 1 )
return V_30 ;
}
return V_15 -> V_27 ;
}
}
static void * F_3 ( struct V_31 * V_32 , T_1 * V_33 )
{
if ( * V_33 >= F_4 ( V_16 ) )
return NULL ;
return & V_16 [ * V_33 ] ;
}
static void * F_5 ( struct V_31 * V_32 , void * V_34 , T_1 * V_33 )
{
if ( ++ ( * V_33 ) >= F_4 ( V_16 ) )
return NULL ;
return & V_16 [ * V_33 ] ;
}
static void F_6 ( struct V_31 * V_32 , void * V_34 )
{
}
static int F_7 ( struct V_31 * V_32 , void * V_34 )
{
struct V_14 * V_22 = V_34 ;
F_8 ( V_32 , L_1 , V_22 -> V_26 , V_22 -> V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_10 ( V_36 , & V_37 ) ;
}
static T_2 F_11 ( struct V_36 * V_36 ,
const char T_3 * V_38 ,
T_4 V_39 , T_1 * V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_4 ( V_16 ) ; V_41 ++ )
V_16 [ V_41 ] . V_26 = 0 ;
return V_39 ;
}
static int T_5 F_12 ( void )
{
struct V_42 * V_43 = NULL , * V_44 = NULL ;
V_43 = F_13 () ;
if ( V_43 == NULL )
goto V_45;
V_44 = F_14 ( L_2 ,
0444 , V_43 , NULL ,
& V_46 ) ;
if ( V_44 == NULL )
goto V_45;
return 0 ;
V_45:
return - V_47 ;
}
