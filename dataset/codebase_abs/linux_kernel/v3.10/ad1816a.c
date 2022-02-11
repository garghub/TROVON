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
struct V_25 * V_26 ;
error = F_10 ( V_27 [ V_1 ] , V_5 [ V_1 ] , V_28 ,
sizeof( struct V_21 ) , & V_3 ) ;
if ( error < 0 )
return error ;
V_22 = V_3 -> V_29 ;
if ( ( error = F_1 ( V_1 , V_18 , V_19 ) ) ) {
F_11 ( V_3 ) ;
return error ;
}
F_12 ( V_3 , & V_18 -> V_3 -> V_1 ) ;
if ( ( error = F_13 ( V_3 , V_11 [ V_1 ] ,
V_15 [ V_1 ] ,
V_13 [ V_1 ] ,
V_14 [ V_1 ] ,
V_22 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
if ( V_30 [ V_1 ] >= 5000 && V_30 [ V_1 ] <= 100000 )
V_22 -> V_31 = V_30 [ V_1 ] ;
strcpy ( V_3 -> V_32 , L_4 ) ;
strcpy ( V_3 -> V_33 , L_5 ) ;
sprintf ( V_3 -> V_34 , L_6 ,
V_3 -> V_33 , V_22 -> V_11 , V_15 [ V_1 ] , V_13 [ V_1 ] , V_14 [ V_1 ] ) ;
if ( ( error = F_14 ( V_22 , 0 , NULL ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
if ( ( error = F_15 ( V_22 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
error = F_16 ( V_22 , 0 , & V_26 ) ;
if ( error < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
if ( V_16 [ V_1 ] > 0 ) {
if ( F_17 ( V_3 , 0 , V_35 ,
V_16 [ V_1 ] , 0 , V_17 [ V_1 ] ,
NULL ) < 0 )
F_4 (KERN_ERR PFX L_7 , mpu_port[dev]) ;
}
if ( V_12 [ V_1 ] > 0 ) {
if ( F_18 ( V_3 ,
V_12 [ V_1 ] , V_12 [ V_1 ] + 2 ,
V_36 , 0 , & V_24 ) < 0 ) {
F_4 (KERN_ERR PFX L_8 , fm_port[dev], fm_port[dev] + 2 ) ;
} else {
error = F_19 ( V_24 , 0 , 1 , NULL ) ;
if ( error < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
}
}
if ( ( error = F_20 ( V_3 ) ) < 0 ) {
F_11 ( V_3 ) ;
return error ;
}
F_21 ( V_18 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
static int V_1 ;
int V_37 ;
for ( ; V_1 < V_38 ; V_1 ++ ) {
if ( ! V_39 [ V_1 ] )
continue;
V_37 = F_9 ( V_1 , V_3 , V_5 ) ;
if ( V_37 < 0 )
return V_37 ;
V_1 ++ ;
V_40 ++ ;
return 0 ;
}
return - V_41 ;
}
static void F_23 ( struct V_2 * V_18 )
{
F_11 ( F_24 ( V_18 ) ) ;
F_21 ( V_18 , NULL ) ;
}
static int F_25 ( struct V_2 * V_18 ,
T_1 V_42 )
{
struct V_20 * V_3 = F_24 ( V_18 ) ;
F_26 ( V_3 , V_43 ) ;
F_27 ( V_3 -> V_29 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_18 )
{
struct V_20 * V_3 = F_24 ( V_18 ) ;
F_29 ( V_3 -> V_29 ) ;
F_26 ( V_3 , V_44 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
int V_8 ;
V_8 = F_31 ( & V_45 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_40 ) {
F_32 ( & V_45 ) ;
#ifdef F_33
F_4 ( V_46 L_9 ) ;
#endif
return - V_41 ;
}
return 0 ;
}
static void T_3 F_34 ( void )
{
F_32 ( & V_45 ) ;
}
