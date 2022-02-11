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
L_2 ,
( V_29 && F_28 ( V_19 ) ) ? L_3
: L_4 ) ;
V_22 = F_29 ( F_7 ( V_19 ) , NULL ) ;
V_23 = F_30 ( V_19 , V_22 ) ;
V_21 = F_31 ( F_16 ( F_17 ( V_24 ) ) ) ;
F_32 ( & V_21 , V_23 , V_30 ) ;
F_33 ( V_23 ) ;
}
static unsigned int F_34 ( void )
{
T_2 V_20 ;
unsigned int V_31 = 0 ;
T_1 V_19 ;
unsigned int V_32 ;
F_35 ( F_36 ( F_17 ( V_24 ) ) ) ;
V_20 = F_16 ( F_17 ( V_24 ) ) ;
if ( ! F_37 ( V_20 ) ) {
F_38 ( F_39 ( F_17 ( V_24 ) ) ) ;
F_35 ( F_36 ( F_17 ( V_24 ) ) ) ;
}
F_40 (cfun, i, var) {
T_1 type = F_7 ( V_19 ) ;
F_35 ( F_41 ( V_19 ) ) ;
if ( ! F_42 ( V_19 , V_33 ) )
continue;
if ( F_2 ( type ) != V_14 && F_2 ( type ) != V_15 )
continue;
if ( F_14 ( type ) ||
( V_29 && F_28 ( V_19 ) ) )
F_15 ( V_19 ) ;
}
return V_31 ;
}
T_5 int F_43 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
int V_32 ;
const char * const V_38 = V_35 -> V_39 ;
const int V_40 = V_35 -> V_40 ;
const struct V_41 * const V_42 = V_35 -> V_42 ;
bool V_43 = true ;
F_44 ( V_44 , L_5 , 1 , V_45 ) ;
if ( ! F_45 ( V_37 , & V_46 ) ) {
error ( F_46 ( L_6 ) ) ;
return 1 ;
}
if ( strncmp ( V_47 . V_2 , L_7 , 5 ) && ! strncmp ( V_47 . V_2 , L_8 , 6 ) ) {
F_26 ( V_48 , F_46 ( L_9 ) , V_38 , V_47 . V_2 ) ;
V_43 = false ;
}
for ( V_32 = 0 ; V_32 < V_40 ; ++ V_32 ) {
if ( ! strcmp ( V_42 [ V_32 ] . V_49 , L_10 ) ) {
V_43 = false ;
continue;
}
if ( ! strcmp ( V_42 [ V_32 ] . V_49 , L_11 ) ) {
V_28 = true ;
continue;
}
if ( ! strcmp ( V_42 [ V_32 ] . V_49 , L_12 ) ) {
V_29 = true ;
continue;
}
error ( F_46 ( L_13 ) , V_38 , V_42 [ V_32 ] . V_49 ) ;
}
F_47 ( V_38 , V_50 , NULL , & V_51 ) ;
if ( V_43 ) {
F_47 ( V_38 , V_52 , NULL , & V_53 ) ;
F_47 ( V_38 , V_54 , F_13 , NULL ) ;
}
F_47 ( V_38 , V_55 , F_3 , NULL ) ;
return 0 ;
}
