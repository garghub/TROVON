static int F_1 ( int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_3 -> V_1 = F_2 ( V_5 , V_7 -> V_11 [ 0 ] . V_7 , NULL ) ;
if ( V_3 -> V_1 == NULL )
return - V_12 ;
V_3 -> V_13 = F_2 ( V_5 , V_7 -> V_11 [ 1 ] . V_7 , V_3 -> V_1 ) ;
V_3 -> V_14 = F_2 ( V_5 , V_7 -> V_11 [ 2 ] . V_7 , V_3 -> V_1 ) ;
V_9 = V_3 -> V_1 ;
V_10 = F_3 ( V_9 ) ;
if ( V_10 < 0 ) {
F_4 (KERN_ERR PFX L_1 ) ;
return V_10 ;
}
V_15 [ V_1 ] = F_5 ( V_9 , 0 ) ;
if ( V_7 -> V_16 == V_17 )
V_18 [ V_1 ] = F_6 ( V_9 , 0 ) ;
else {
V_18 [ V_1 ] = F_6 ( V_9 , 1 ) ;
V_19 [ V_1 ] = F_6 ( V_9 , 0 ) ;
}
V_20 [ V_1 ] = F_7 ( V_9 , 0 ) ;
V_9 = V_3 -> V_13 ;
if ( V_9 != NULL ) {
V_10 = F_3 ( V_9 ) ;
if ( V_10 < 0 )
goto V_21;
V_22 [ V_1 ] = F_5 ( V_9 , 0 ) ;
V_23 [ V_1 ] = F_7 ( V_9 , 0 ) ;
} else {
V_21:
if ( V_9 ) {
F_8 ( V_9 ) ;
F_4 (KERN_ERR PFX L_2 ) ;
}
V_3 -> V_13 = NULL ;
V_22 [ V_1 ] = - 1 ;
}
V_9 = V_3 -> V_14 ;
if ( V_9 != NULL ) {
V_10 = F_3 ( V_9 ) ;
if ( V_10 < 0 )
goto V_24;
V_25 [ V_1 ] = F_5 ( V_9 , 0 ) ;
} else {
V_24:
if ( V_9 ) {
F_8 ( V_9 ) ;
F_4 (KERN_ERR PFX L_3 ) ;
}
V_3 -> V_14 = NULL ;
V_25 [ V_1 ] = - 1 ;
}
return 0 ;
}
static int F_9 ( int V_1 ,
struct V_4 * V_26 ,
const struct V_6 * V_27 )
{
int error ;
struct V_28 * V_29 ;
struct V_30 * V_5 ;
struct V_2 * V_3 ;
struct V_31 * V_32 ;
error = F_10 ( & V_26 -> V_5 -> V_1 ,
V_33 [ V_1 ] , V_7 [ V_1 ] , V_34 ,
sizeof( struct V_2 ) , & V_5 ) ;
if ( error < 0 )
return error ;
V_3 = V_5 -> V_35 ;
if ( ( error = F_1 ( V_1 , V_3 , V_26 , V_27 ) ) ) {
F_11 ( V_5 ) ;
return error ;
}
if ( V_27 -> V_16 == V_17 )
V_19 [ V_1 ] = - 1 ;
error = F_12 ( V_5 , V_15 [ V_1 ] , V_20 [ V_1 ] ,
V_36 ,
V_18 [ V_1 ] , V_19 [ V_1 ] ,
V_27 -> V_16 ,
& V_29 ) ;
if ( error < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
V_3 -> V_29 = V_29 ;
if ( V_27 -> V_16 == V_17 ) {
strcpy ( V_5 -> V_37 , L_4 ) ;
strcpy ( V_5 -> V_38 , L_5 ) ;
sprintf ( V_5 -> V_39 , L_6 ,
V_5 -> V_38 , V_29 -> V_40 , V_29 -> V_15 ,
V_20 [ V_1 ] , V_18 [ V_1 ] ) ;
} else {
strcpy ( V_5 -> V_37 , L_7 ) ;
strcpy ( V_5 -> V_38 , L_8 ) ;
sprintf ( V_5 -> V_39 , L_9 ,
V_5 -> V_38 , V_29 -> V_40 , V_29 -> V_15 ,
V_20 [ V_1 ] , V_18 [ V_1 ] , V_19 [ V_1 ] ) ;
}
if ( ( error = F_13 ( V_29 , 0 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
if ( ( error = F_14 ( V_29 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
if ( V_22 [ V_1 ] > 0 && V_22 [ V_1 ] != V_41 ) {
int V_42 = V_43 ;
if ( V_23 [ V_1 ] == V_44 )
V_23 [ V_1 ] = - 1 ;
if ( V_27 -> V_16 == V_17 )
V_42 = V_45 ;
if ( F_15 ( V_5 , 0 ,
V_42 ,
V_22 [ V_1 ] , 0 ,
V_23 [ V_1 ] ,
NULL ) < 0 )
F_4 (KERN_ERR PFX L_10 , mpu_port[dev]) ;
}
if ( V_25 [ V_1 ] > 0 && V_25 [ V_1 ] != V_41 ) {
if ( F_16 ( V_5 ,
V_25 [ V_1 ] , V_25 [ V_1 ] + 2 ,
V_46 , 0 , & V_32 ) < 0 ) {
F_4 (KERN_ERR PFX L_11 ,
fm_port[dev], fm_port[dev] + 2 ) ;
} else {
if ( ( error = F_17 ( V_32 , 0 , 1 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
if ( ( error = F_18 ( V_32 , 0 , 1 , NULL ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
}
}
if ( ( error = F_19 ( V_5 ) ) < 0 ) {
F_11 ( V_5 ) ;
return error ;
}
F_20 ( V_26 , V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
static int V_1 ;
int V_47 ;
for ( ; V_1 < V_48 ; V_1 ++ ) {
if ( ! V_49 [ V_1 ] )
continue;
V_47 = F_9 ( V_1 , V_5 , V_7 ) ;
if ( V_47 < 0 )
return V_47 ;
V_1 ++ ;
V_50 ++ ;
return 0 ;
}
return - V_12 ;
}
static void F_22 ( struct V_4 * V_26 )
{
F_11 ( F_23 ( V_26 ) ) ;
F_20 ( V_26 , NULL ) ;
}
static int F_24 ( struct V_4 * V_26 , T_1 V_51 )
{
struct V_30 * V_5 = F_23 ( V_26 ) ;
struct V_2 * V_3 = V_5 -> V_35 ;
struct V_28 * V_29 = V_3 -> V_29 ;
F_25 ( V_5 , V_52 ) ;
F_26 ( V_29 -> V_53 ) ;
F_27 ( V_29 ) ;
return 0 ;
}
static int F_28 ( struct V_4 * V_26 )
{
struct V_30 * V_5 = F_23 ( V_26 ) ;
struct V_2 * V_3 = V_5 -> V_35 ;
struct V_28 * V_29 = V_3 -> V_29 ;
F_29 ( V_29 ) ;
F_30 ( V_29 ) ;
F_25 ( V_5 , V_54 ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
int V_10 ;
V_10 = F_32 ( & V_55 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_50 ) {
F_33 ( & V_55 ) ;
#ifdef F_34
F_4 ( V_56 L_12 ) ;
#endif
return - V_12 ;
}
return 0 ;
}
static void T_3 F_35 ( void )
{
F_33 ( & V_55 ) ;
}
