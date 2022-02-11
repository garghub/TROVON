static int F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 & 3 ) == 3 ) ? V_4 : V_5 ;
}
static int F_2 ( struct V_1 * V_2 , int V_6 , char * * V_7 , bool V_8 )
{
enum V_9 V_10 = F_1 ( V_2 ) ;
if ( V_2 -> V_11 & V_12 )
return V_13 ;
if ( V_2 -> V_11 & V_14 ) {
if ( V_15 . V_16 ) {
if ( ! ( V_2 -> V_17 & V_18 ) && ( V_10 == V_5 ) )
return V_13 ;
return V_19 ;
} else {
if ( V_2 -> V_11 & V_20 )
return V_13 ;
}
return V_21 ;
}
if ( V_2 -> V_11 & V_22 )
return V_23 ;
return V_24 ;
}
static int F_3 ( struct V_1 * V_2 , int V_6 , char * * V_7 , bool V_8 )
{
enum V_25 V_26 = ( V_8 ? V_27 : V_28 ) ;
enum V_9 V_10 = F_1 ( V_2 ) ;
struct V_29 * V_30 ;
for ( V_30 = V_31 ; ; V_30 ++ ) {
if ( ( V_2 -> V_11 & V_30 -> V_32 ) != V_30 -> V_33 )
continue;
if ( ( V_2 -> V_17 & V_30 -> V_34 ) != V_30 -> V_35 )
continue;
if ( V_30 -> V_36 == V_37 && ! V_38 . V_36 )
continue;
if ( V_30 -> V_36 == V_39 && V_38 . V_36 )
continue;
if ( V_30 -> V_9 && V_10 != V_30 -> V_9 )
continue;
if ( V_30 -> V_26 && V_26 != V_30 -> V_26 )
continue;
if ( V_7 )
* V_7 = V_30 -> V_7 ;
V_30 -> V_40 = 1 ;
if ( V_30 -> V_41 >= V_21 && V_10 == V_5 ) {
if ( V_42 || V_6 < 1 )
return V_13 ;
}
return V_30 -> V_41 ;
}
}
void T_1 F_4 ( void )
{
if ( V_43 . V_44 == V_45 )
V_46 = F_2 ;
}
static void * F_5 ( struct V_47 * V_48 , T_2 * V_49 )
{
if ( * V_49 >= F_6 ( V_31 ) )
return NULL ;
return & V_31 [ * V_49 ] ;
}
static void * F_7 ( struct V_47 * V_48 , void * V_50 , T_2 * V_49 )
{
if ( ++ ( * V_49 ) >= F_6 ( V_31 ) )
return NULL ;
return & V_31 [ * V_49 ] ;
}
static void F_8 ( struct V_47 * V_48 , void * V_50 )
{
}
static int F_9 ( struct V_47 * V_48 , void * V_50 )
{
struct V_29 * V_36 = V_50 ;
F_10 ( V_48 , L_1 , V_36 -> V_40 , V_36 -> V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_12 ( V_52 , & V_53 ) ;
}
static T_3 F_13 ( struct V_52 * V_52 ,
const char T_4 * V_54 ,
T_5 V_55 , T_2 * V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_6 ( V_31 ) ; V_57 ++ )
V_31 [ V_57 ] . V_40 = 0 ;
return V_55 ;
}
static int T_1 F_14 ( void )
{
struct V_58 * V_59 , * V_60 ;
V_59 = F_15 () ;
if ( ! V_59 )
goto V_61;
V_60 = F_16 ( L_2 , 0444 , V_59 , NULL ,
& V_62 ) ;
if ( ! V_60 )
goto V_61;
return 0 ;
V_61:
return - V_63 ;
}
