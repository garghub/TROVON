static int F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 & 3 ) == 3 )
return V_4 ;
if ( F_2 ( V_2 -> V_5 ) && F_3 ( V_2 -> V_6 ) )
return V_7 ;
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 , int V_9 , char * * V_10 , bool V_11 )
{
enum V_12 V_13 = F_1 ( V_2 ) ;
if ( V_2 -> V_14 & V_15 )
return V_16 ;
if ( V_2 -> V_14 & V_17 ) {
if ( V_18 . V_19 ) {
if ( ! ( V_2 -> V_5 & V_20 ) && ( V_13 == V_8 ) )
return V_16 ;
return V_21 ;
} else {
if ( V_2 -> V_14 & V_22 )
return V_16 ;
}
return V_23 ;
}
if ( V_2 -> V_14 & V_24 )
return V_25 ;
return V_26 ;
}
static int F_5 ( struct V_1 * V_2 , int V_9 , char * * V_10 , bool V_11 )
{
enum V_27 V_28 = ( V_11 ? V_29 : V_30 ) ;
enum V_12 V_13 = F_1 ( V_2 ) ;
struct V_31 * V_32 ;
for ( V_32 = V_33 ; ; V_32 ++ ) {
if ( ( V_2 -> V_14 & V_32 -> V_34 ) != V_32 -> V_35 )
continue;
if ( ( V_2 -> V_5 & V_32 -> V_36 ) != V_32 -> V_37 )
continue;
if ( V_32 -> V_38 == V_39 && ! V_40 . V_38 )
continue;
if ( V_32 -> V_38 == V_41 && V_40 . V_38 )
continue;
if ( V_32 -> V_12 && V_13 != V_32 -> V_12 )
continue;
if ( V_32 -> V_28 && V_28 != V_32 -> V_28 )
continue;
if ( V_10 )
* V_10 = V_32 -> V_10 ;
V_32 -> V_42 = 1 ;
if ( V_32 -> V_43 >= V_23 && V_13 == V_8 ) {
if ( V_44 || V_9 < 1 )
return V_16 ;
}
return V_32 -> V_43 ;
}
}
void T_1 F_6 ( void )
{
if ( V_45 . V_46 == V_47 )
V_48 = F_4 ;
}
static void * F_7 ( struct V_49 * V_50 , T_2 * V_51 )
{
if ( * V_51 >= F_8 ( V_33 ) )
return NULL ;
return & V_33 [ * V_51 ] ;
}
static void * F_9 ( struct V_49 * V_50 , void * V_52 , T_2 * V_51 )
{
if ( ++ ( * V_51 ) >= F_8 ( V_33 ) )
return NULL ;
return & V_33 [ * V_51 ] ;
}
static void F_10 ( struct V_49 * V_50 , void * V_52 )
{
}
static int F_11 ( struct V_49 * V_50 , void * V_52 )
{
struct V_31 * V_38 = V_52 ;
F_12 ( V_50 , L_1 , V_38 -> V_42 , V_38 -> V_10 ) ;
return 0 ;
}
static int F_13 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_14 ( V_54 , & V_55 ) ;
}
static T_3 F_15 ( struct V_54 * V_54 ,
const char T_4 * V_56 ,
T_5 V_57 , T_2 * V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < F_8 ( V_33 ) ; V_59 ++ )
V_33 [ V_59 ] . V_42 = 0 ;
return V_57 ;
}
static int T_1 F_16 ( void )
{
struct V_60 * V_61 , * V_62 ;
V_61 = F_17 () ;
if ( ! V_61 )
goto V_63;
V_62 = F_18 ( L_2 , 0444 , V_61 , NULL ,
& V_64 ) ;
if ( ! V_62 )
goto V_63;
return 0 ;
V_63:
return - V_65 ;
}
