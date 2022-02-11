static int T_1 F_1 ( int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_3 -> V_1 = F_2 ( V_5 , V_7 -> V_11 [ 0 ] . V_7 , NULL ) ;
if ( V_3 -> V_1 == NULL )
return - V_12 ;
V_3 -> V_13 = F_2 ( V_5 , V_7 -> V_11 [ 1 ] . V_7 , NULL ) ;
if ( V_3 -> V_13 == NULL ) {
V_14 [ V_1 ] = - 1 ;
F_3 (KERN_WARNING PFX L_1 ) ;
}
V_9 = V_3 -> V_1 ;
V_10 = F_4 ( V_9 ) ;
if ( V_10 < 0 ) {
F_5 (KERN_ERR PFX L_2 ) ;
return - V_12 ;
}
V_15 [ V_1 ] = F_6 ( V_9 , 2 ) ;
V_16 [ V_1 ] = F_6 ( V_9 , 1 ) ;
V_17 [ V_1 ] = F_7 ( V_9 , 0 ) ;
V_18 [ V_1 ] = F_7 ( V_9 , 1 ) ;
V_19 [ V_1 ] = F_8 ( V_9 , 0 ) ;
if ( V_3 -> V_13 == NULL )
return 0 ;
V_9 = V_3 -> V_13 ;
V_10 = F_4 ( V_9 ) ;
if ( V_10 < 0 ) {
F_5 (KERN_ERR PFX L_3 ) ;
V_14 [ V_1 ] = - 1 ;
V_3 -> V_13 = NULL ;
} else {
V_14 [ V_1 ] = F_6 ( V_9 , 0 ) ;
V_20 [ V_1 ] = F_8 ( V_9 , 0 ) ;
}
return 0 ;
}
static int T_1 F_9 ( int V_1 , struct V_4 * V_21 ,
const struct V_6 * V_22 )
{
int error ;
struct V_23 * V_5 ;
struct V_2 * V_3 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
error = F_10 ( V_30 [ V_1 ] , V_7 [ V_1 ] , V_31 ,
sizeof( struct V_2 ) , & V_5 ) ;
if ( error < 0 )
return error ;
V_3 = V_5 -> V_32 ;
if ( ( error = F_1 ( V_1 , V_3 , V_21 , V_22 ) ) ) {
F_11 ( V_5 ) ;
return error ;
}
F_12 ( V_5 , & V_21 -> V_5 -> V_1 ) ;
if ( ( error = F_13 ( V_5 , V_15 [ V_1 ] ,
V_19 [ V_1 ] ,
V_17 [ V_1 ] ,
V_18 [ V_1 ] ,
& V_25 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
if ( V_33 [ V_1 ] >= 5000 && V_33 [ V_1 ] <= 100000 )
V_25 -> V_34 = V_33 [ V_1 ] ;
strcpy ( V_5 -> V_35 , L_4 ) ;
strcpy ( V_5 -> V_36 , L_5 ) ;
sprintf ( V_5 -> V_37 , L_6 ,
V_5 -> V_36 , V_25 -> V_15 , V_19 [ V_1 ] , V_17 [ V_1 ] , V_18 [ V_1 ] ) ;
if ( ( error = F_14 ( V_25 , 0 , NULL ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
if ( ( error = F_15 ( V_25 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
error = F_16 ( V_25 , 0 , & V_29 ) ;
if ( error < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
if ( V_14 [ V_1 ] > 0 ) {
if ( F_17 ( V_5 , 0 , V_38 ,
V_14 [ V_1 ] , 0 , V_20 [ V_1 ] , V_39 ,
NULL ) < 0 )
F_5 (KERN_ERR PFX L_7 , mpu_port[dev]) ;
}
if ( V_16 [ V_1 ] > 0 ) {
if ( F_18 ( V_5 ,
V_16 [ V_1 ] , V_16 [ V_1 ] + 2 ,
V_40 , 0 , & V_27 ) < 0 ) {
F_5 (KERN_ERR PFX L_8 , fm_port[dev], fm_port[dev] + 2 ) ;
} else {
error = F_19 ( V_27 , 0 , 1 , NULL ) ;
if ( error < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
}
}
if ( ( error = F_20 ( V_5 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
F_21 ( V_21 , V_5 ) ;
return 0 ;
}
static int T_1 F_22 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
static int V_1 ;
int V_41 ;
for ( ; V_1 < V_42 ; V_1 ++ ) {
if ( ! V_43 [ V_1 ] )
continue;
V_41 = F_9 ( V_1 , V_5 , V_7 ) ;
if ( V_41 < 0 )
return V_41 ;
V_1 ++ ;
V_44 ++ ;
return 0 ;
}
return - V_45 ;
}
static void T_2 F_23 ( struct V_4 * V_21 )
{
F_11 ( F_24 ( V_21 ) ) ;
F_21 ( V_21 , NULL ) ;
}
static int T_3 F_25 ( void )
{
int V_10 ;
V_10 = F_26 ( & V_46 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_44 ) {
F_27 ( & V_46 ) ;
#ifdef F_28
F_5 ( V_47 L_9 ) ;
#endif
return - V_45 ;
}
return 0 ;
}
static void T_4 F_29 ( void )
{
F_27 ( & V_46 ) ;
}
