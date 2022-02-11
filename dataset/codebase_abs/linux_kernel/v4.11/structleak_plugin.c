static T_1 F_1 ( T_1 * V_1 , T_1 V_2 , T_1 args , int V_3 , bool * V_4 )
{
* V_4 = true ;
if ( F_2 ( * V_1 ) != V_5 )
return V_6 ;
* V_4 = false ;
return V_6 ;
}
static void F_3 ( void * V_7 , void * V_8 )
{
F_4 ( & V_9 ) ;
}
static T_1 F_5 ( T_1 V_10 )
{
return F_6 ( F_7 ( V_10 ) ) ;
}
static bool F_8 ( T_1 type )
{
T_1 V_10 ;
for ( V_10 = F_9 ( type ) ; V_10 ; V_10 = F_10 ( V_10 ) ) {
T_1 V_11 = F_5 ( V_10 ) ;
enum V_12 V_13 = F_2 ( V_11 ) ;
if ( V_13 == V_14 || V_13 == V_15 )
if ( F_8 ( V_11 ) )
return true ;
if ( F_11 ( L_1 , F_12 ( V_10 ) ) )
return true ;
}
return false ;
}
static void F_13 ( void * V_7 , void * V_8 )
{
T_1 type = ( T_1 ) V_7 ;
if ( type == V_6 || type == V_16 )
return;
#if V_17 >= 5000
if ( F_2 ( type ) == V_18 )
return;
#endif
if ( F_14 ( type ) )
return;
if ( F_8 ( type ) )
F_14 ( type ) = 1 ;
}
static void F_15 ( T_1 V_19 )
{
T_2 V_20 ;
T_3 V_21 ;
T_1 V_22 ;
T_4 V_23 ;
V_20 = F_16 ( F_17 ( V_24 ) ) ;
for ( V_21 = F_18 ( V_20 ) ; ! F_19 ( V_21 ) ; F_20 ( & V_21 ) ) {
T_4 V_25 = F_21 ( V_21 ) ;
T_1 V_26 ;
if ( ! F_22 ( V_25 ) )
continue;
V_26 = F_23 ( V_25 ) ;
#if V_17 >= 4007
if ( F_24 ( V_26 ) )
continue;
#endif
if ( F_25 ( V_25 ) != V_19 )
continue;
if ( F_2 ( V_26 ) == V_27 )
return;
}
if ( V_28 )
F_26 ( F_27 ( V_19 ) ,
L_2 ) ;
V_22 = F_28 ( F_7 ( V_19 ) , NULL ) ;
V_23 = F_29 ( V_19 , V_22 ) ;
V_21 = F_30 ( F_16 ( F_17 ( V_24 ) ) ) ;
F_31 ( & V_21 , V_23 , V_29 ) ;
F_32 ( V_23 ) ;
}
static unsigned int F_33 ( void )
{
T_2 V_20 ;
unsigned int V_30 = 0 ;
T_1 V_19 ;
unsigned int V_31 ;
F_34 ( F_35 ( F_17 ( V_24 ) ) ) ;
V_20 = F_16 ( F_17 ( V_24 ) ) ;
if ( ! F_36 ( V_20 ) ) {
F_37 ( F_38 ( F_17 ( V_24 ) ) ) ;
F_34 ( F_35 ( F_17 ( V_24 ) ) ) ;
}
F_39 (cfun, i, var) {
T_1 type = F_7 ( V_19 ) ;
F_34 ( F_40 ( V_19 ) ) ;
if ( ! F_41 ( V_19 , V_32 ) )
continue;
if ( F_2 ( type ) != V_14 && F_2 ( type ) != V_15 )
continue;
if ( F_14 ( type ) )
F_15 ( V_19 ) ;
}
return V_30 ;
}
T_5 int F_42 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
int V_31 ;
const char * const V_37 = V_34 -> V_38 ;
const int V_39 = V_34 -> V_39 ;
const struct V_40 * const V_41 = V_34 -> V_41 ;
bool V_42 = true ;
F_43 ( V_43 , L_3 , 1 , V_44 ) ;
if ( ! F_44 ( V_36 , & V_45 ) ) {
error ( F_45 ( L_4 ) ) ;
return 1 ;
}
if ( strncmp ( V_46 . V_2 , L_5 , 5 ) && ! strncmp ( V_46 . V_2 , L_6 , 6 ) ) {
F_26 ( V_47 , F_45 ( L_7 ) , V_37 , V_46 . V_2 ) ;
V_42 = false ;
}
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( ! strcmp ( V_41 [ V_31 ] . V_48 , L_8 ) ) {
V_42 = false ;
continue;
}
if ( ! strcmp ( V_41 [ V_31 ] . V_48 , L_9 ) ) {
V_28 = true ;
continue;
}
error ( F_45 ( L_10 ) , V_37 , V_41 [ V_31 ] . V_48 ) ;
}
F_46 ( V_37 , V_49 , NULL , & V_50 ) ;
if ( V_42 ) {
F_46 ( V_37 , V_51 , NULL , & V_52 ) ;
F_46 ( V_37 , V_53 , F_13 , NULL ) ;
}
F_46 ( V_37 , V_54 , F_3 , NULL ) ;
return 0 ;
}
