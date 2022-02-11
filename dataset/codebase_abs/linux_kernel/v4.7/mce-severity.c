static int F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 & 3 ) == 3 )
return V_4 ;
if ( F_2 ( V_2 -> V_5 ) && F_3 ( V_2 -> V_6 ) )
return V_7 ;
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 , int V_9 )
{
T_1 V_10 = F_5 ( V_2 -> V_11 ) ;
T_1 V_12 , V_13 ;
if ( ! V_14 . V_15 )
return V_16 ;
if ( F_6 ( V_10 , & V_12 , & V_13 ) )
return V_16 ;
if ( ( V_12 & V_17 ) &&
( V_2 -> V_18 & V_19 ) &&
( V_9 == V_8 ) )
return V_16 ;
return V_20 ;
}
static int F_7 ( struct V_1 * V_2 , int V_21 , char * * V_22 , bool V_23 )
{
enum V_24 V_25 = F_1 ( V_2 ) ;
if ( V_2 -> V_18 & V_26 )
return V_16 ;
if ( V_2 -> V_18 & V_27 ) {
if ( V_14 . V_28 ) {
if ( V_14 . V_29 )
return F_4 ( V_2 , V_25 ) ;
if ( ! ( V_2 -> V_5 & V_30 ) && ( V_25 == V_8 ) )
return V_16 ;
return V_20 ;
} else {
if ( V_2 -> V_18 & V_31 )
return V_16 ;
}
return V_32 ;
}
if ( V_2 -> V_18 & V_33 )
return V_34 ;
return V_35 ;
}
static int F_8 ( struct V_1 * V_2 , int V_21 , char * * V_22 , bool V_23 )
{
enum V_36 V_37 = ( V_23 ? V_38 : V_39 ) ;
enum V_24 V_25 = F_1 ( V_2 ) ;
struct V_40 * V_41 ;
for ( V_41 = V_42 ; ; V_41 ++ ) {
if ( ( V_2 -> V_18 & V_41 -> V_43 ) != V_41 -> V_44 )
continue;
if ( ( V_2 -> V_5 & V_41 -> V_45 ) != V_41 -> V_46 )
continue;
if ( V_41 -> V_47 == V_48 && ! V_49 . V_47 )
continue;
if ( V_41 -> V_47 == V_50 && V_49 . V_47 )
continue;
if ( V_41 -> V_24 && V_25 != V_41 -> V_24 )
continue;
if ( V_41 -> V_37 && V_37 != V_41 -> V_37 )
continue;
if ( V_22 )
* V_22 = V_41 -> V_22 ;
V_41 -> V_51 = 1 ;
if ( V_41 -> V_52 >= V_32 && V_25 == V_8 ) {
if ( V_53 || V_21 < 1 )
return V_16 ;
}
return V_41 -> V_52 ;
}
}
void T_2 F_9 ( void )
{
if ( V_54 . V_55 == V_56 )
V_57 = F_7 ;
}
static void * F_10 ( struct V_58 * V_59 , T_3 * V_60 )
{
if ( * V_60 >= F_11 ( V_42 ) )
return NULL ;
return & V_42 [ * V_60 ] ;
}
static void * F_12 ( struct V_58 * V_59 , void * V_61 , T_3 * V_60 )
{
if ( ++ ( * V_60 ) >= F_11 ( V_42 ) )
return NULL ;
return & V_42 [ * V_60 ] ;
}
static void F_13 ( struct V_58 * V_59 , void * V_61 )
{
}
static int F_14 ( struct V_58 * V_59 , void * V_61 )
{
struct V_40 * V_47 = V_61 ;
F_15 ( V_59 , L_1 , V_47 -> V_51 , V_47 -> V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
return F_17 ( V_63 , & V_64 ) ;
}
static T_4 F_18 ( struct V_63 * V_63 ,
const char T_5 * V_65 ,
T_6 V_66 , T_3 * V_67 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < F_11 ( V_42 ) ; V_68 ++ )
V_42 [ V_68 ] . V_51 = 0 ;
return V_66 ;
}
static int T_2 F_19 ( void )
{
struct V_69 * V_70 , * V_71 ;
V_70 = F_20 () ;
if ( ! V_70 )
goto V_72;
V_71 = F_21 ( L_2 , 0444 , V_70 , NULL ,
& V_73 ) ;
if ( ! V_71 )
goto V_72;
return 0 ;
V_72:
return - V_74 ;
}
