static int F_1 ( int V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( V_3 , V_5 -> V_9 [ 0 ] . V_5 , NULL ) ;
if ( V_7 == NULL )
return - V_10 ;
V_8 = F_3 ( V_7 ) ;
if ( V_8 < 0 ) {
F_4 (KERN_ERR PFX L_1 ) ;
return - V_10 ;
}
V_11 [ V_1 ] = F_5 ( V_7 , 2 ) ;
V_12 [ V_1 ] = F_5 ( V_7 , 1 ) ;
V_13 [ V_1 ] = F_6 ( V_7 , 0 ) ;
V_14 [ V_1 ] = F_6 ( V_7 , 1 ) ;
V_15 [ V_1 ] = F_7 ( V_7 , 0 ) ;
V_7 = F_2 ( V_3 , V_5 -> V_9 [ 1 ] . V_5 , NULL ) ;
if ( V_7 == NULL ) {
V_16 [ V_1 ] = - 1 ;
F_8 (KERN_WARNING PFX L_2 ) ;
return 0 ;
}
V_8 = F_3 ( V_7 ) ;
if ( V_8 < 0 ) {
F_4 (KERN_ERR PFX L_3 ) ;
V_16 [ V_1 ] = - 1 ;
} else {
V_16 [ V_1 ] = F_5 ( V_7 , 0 ) ;
V_17 [ V_1 ] = F_7 ( V_7 , 0 ) ;
}
return 0 ;
}
static int F_9 ( int V_1 , struct V_2 * V_18 ,
const struct V_4 * V_19 )
{
int error ;
struct V_20 * V_3 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
error = F_10 ( & V_18 -> V_3 -> V_1 ,
V_25 [ V_1 ] , V_5 [ V_1 ] , V_26 ,
sizeof( struct V_21 ) , & V_3 ) ;
if ( error < 0 )
return error ;
V_22 = V_3 -> V_27 ;
if ( ( error = F_1 ( V_1 , V_18 , V_19 ) ) ) {
F_11 ( V_3 ) ;
return error ;
}
if ( ( error = F_12 ( V_3 , V_11 [ V_1 ] ,
V_15 [ V_1 ] ,
V_13 [ V_1 ] ,
V_14 [ V_1 ] ,
V_22 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
if ( V_28 [ V_1 ] >= 5000 && V_28 [ V_1 ] <= 100000 )
V_22 -> V_29 = V_28 [ V_1 ] ;
strcpy ( V_3 -> V_30 , L_4 ) ;
strcpy ( V_3 -> V_31 , L_5 ) ;
sprintf ( V_3 -> V_32 , L_6 ,
V_3 -> V_31 , V_22 -> V_11 , V_15 [ V_1 ] , V_13 [ V_1 ] , V_14 [ V_1 ] ) ;
if ( ( error = F_13 ( V_22 , 0 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
if ( ( error = F_14 ( V_22 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
error = F_15 ( V_22 , 0 ) ;
if ( error < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
if ( V_16 [ V_1 ] > 0 ) {
if ( F_16 ( V_3 , 0 , V_33 ,
V_16 [ V_1 ] , 0 , V_17 [ V_1 ] ,
NULL ) < 0 )
F_4 (KERN_ERR PFX L_7 , mpu_port[dev]) ;
}
if ( V_12 [ V_1 ] > 0 ) {
if ( F_17 ( V_3 ,
V_12 [ V_1 ] , V_12 [ V_1 ] + 2 ,
V_34 , 0 , & V_24 ) < 0 ) {
F_4 (KERN_ERR PFX L_8 , fm_port[dev], fm_port[dev] + 2 ) ;
} else {
error = F_18 ( V_24 , 0 , 1 , NULL ) ;
if ( error < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
}
}
if ( ( error = F_19 ( V_3 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
F_20 ( V_18 , V_3 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
static int V_1 ;
int V_35 ;
for ( ; V_1 < V_36 ; V_1 ++ ) {
if ( ! V_37 [ V_1 ] )
continue;
V_35 = F_9 ( V_1 , V_3 , V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
V_1 ++ ;
V_38 ++ ;
return 0 ;
}
return - V_39 ;
}
static void F_22 ( struct V_2 * V_18 )
{
F_11 ( F_23 ( V_18 ) ) ;
F_20 ( V_18 , NULL ) ;
}
static int F_24 ( struct V_2 * V_18 ,
T_1 V_40 )
{
struct V_20 * V_3 = F_23 ( V_18 ) ;
F_25 ( V_3 , V_41 ) ;
F_26 ( V_3 -> V_27 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_18 )
{
struct V_20 * V_3 = F_23 ( V_18 ) ;
F_28 ( V_3 -> V_27 ) ;
F_25 ( V_3 , V_42 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
int V_8 ;
V_8 = F_30 ( & V_43 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_38 ) {
F_31 ( & V_43 ) ;
#ifdef F_32
F_4 ( V_44 L_9 ) ;
#endif
return - V_39 ;
}
return 0 ;
}
static void T_3 F_33 ( void )
{
F_31 ( & V_43 ) ;
}
