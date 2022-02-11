static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
int V_6 = 0 , V_7 ;
T_2 * V_8 , V_9 ;
T_1 * V_10 ;
V_6 = F_2 ( V_2 , L_1 ) ;
if ( V_6 <= 0 )
return - V_11 ;
V_8 = F_3 ( V_6 , sizeof( T_2 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
V_10 = F_3 ( V_6 , sizeof( T_1 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
if ( F_4 ( V_2 , L_1 , V_10 , V_6 ) )
goto error;
if ( F_5 ( V_2 , L_2 , V_8 ,
V_6 ) )
goto error;
V_4 -> V_14 = F_3 ( V_6 , sizeof( struct V_15 ) ,
V_12 ) ;
if ( ! V_4 -> V_14 )
goto error;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
V_4 -> V_14 [ V_7 ] . V_16 = V_10 [ V_7 ] ;
V_9 = V_8 [ V_7 ] + V_5 ;
V_4 -> V_14 [ V_7 ] . V_17 = F_6 ( V_9 ) ;
}
V_4 -> V_18 = true ;
F_7 ( V_8 ) ;
F_7 ( V_10 ) ;
return 0 ;
error:
F_7 ( V_4 -> V_14 ) ;
F_7 ( V_8 ) ;
F_7 ( V_10 ) ;
return - 1 ;
}
static int F_8 ( struct V_1 * V_19 , int V_20 , int V_21 )
{
int V_22 = 0 ;
struct V_3 * V_4 ;
T_1 V_5 ;
V_4 = F_9 ( sizeof( struct V_3 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_4 -> V_21 = V_21 ;
V_22 = F_10 ( V_19 , L_3 , & V_4 -> V_23 ) ;
if ( V_22 ) {
V_22 = - V_24 ;
goto V_25;
}
if ( ! F_10 ( V_19 , L_4 , & V_5 ) ) {
if ( F_1 ( V_19 , V_4 , V_5 ) ) {
V_22 = - V_24 ;
goto V_25;
}
}
V_22 = F_11 ( V_19 , V_4 , V_20 ) ;
if ( V_22 )
F_12 ( L_5 , V_4 -> V_26 . V_27 ) ;
return 0 ;
V_25:
F_7 ( V_4 ) ;
return V_22 ;
}
static void F_13 ( void )
{
int V_28 , V_29 ;
const struct V_30 * V_31 ;
F_14 () ;
F_15 (nid) {
V_31 = F_16 ( V_28 ) ;
V_29 = F_17 ( V_31 ) ;
F_18 ( V_32 ,
F_19 ( V_29 ) ) ;
}
F_20 () ;
}
static void F_21 ( void )
{
T_3 V_33 ;
int V_29 , V_34 ;
F_14 () ;
V_33 = F_22 () ;
F_23 (cpu, &cores_map) {
V_34 = F_18 ( V_35 ,
F_19 ( V_29 ) ) ;
if ( V_34 )
F_12 ( L_6 ,
V_36 , V_29 ) ;
}
F_20 () ;
}
static int F_24 ( struct V_37 * V_38 )
{
struct V_1 * V_39 = V_38 -> V_40 . V_41 ;
int V_42 = 0 , V_21 ;
T_1 type ;
if ( F_25 () ) {
F_13 () ;
F_21 () ;
return - V_11 ;
}
F_26 (imc_dev, NULL, IMC_DTB_UNIT_COMPAT) {
if ( F_10 ( V_39 , L_7 , & type ) ) {
F_27 ( L_8 ) ;
continue;
}
switch ( type ) {
case V_43 :
V_21 = V_44 ;
break;
case V_45 :
V_21 = V_46 ;
break;
case V_47 :
V_21 = V_48 ;
break;
default:
F_27 ( L_9 ) ;
V_21 = - 1 ;
break;
}
if ( ! F_8 ( V_39 , V_42 , V_21 ) )
V_42 ++ ;
}
return 0 ;
}
static void F_28 ( struct V_37 * V_38 )
{
F_13 () ;
F_21 () ;
}
