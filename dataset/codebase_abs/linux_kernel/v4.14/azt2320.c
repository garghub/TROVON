static int F_1 ( int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_3 -> V_1 = F_2 ( V_5 , V_7 -> V_11 [ 0 ] . V_7 , NULL ) ;
if ( V_3 -> V_1 == NULL )
return - V_12 ;
V_3 -> V_13 = F_2 ( V_5 , V_7 -> V_11 [ 1 ] . V_7 , NULL ) ;
V_9 = V_3 -> V_1 ;
V_10 = F_3 ( V_9 ) ;
if ( V_10 < 0 ) {
F_4 (KERN_ERR PFX L_1 ) ;
return V_10 ;
}
V_14 [ V_1 ] = F_5 ( V_9 , 0 ) ;
V_15 [ V_1 ] = F_5 ( V_9 , 1 ) ;
V_16 [ V_1 ] = F_5 ( V_9 , 2 ) ;
V_17 [ V_1 ] = F_6 ( V_9 , 0 ) ;
V_18 [ V_1 ] = F_6 ( V_9 , 1 ) ;
V_19 [ V_1 ] = F_7 ( V_9 , 0 ) ;
V_9 = V_3 -> V_13 ;
if ( V_9 != NULL ) {
V_10 = F_3 ( V_9 ) ;
if ( V_10 < 0 )
goto V_20;
V_21 [ V_1 ] = F_5 ( V_9 , 0 ) ;
V_22 [ V_1 ] = F_7 ( V_9 , 0 ) ;
} else {
V_20:
if ( V_9 ) {
F_8 ( V_9 ) ;
F_4 (KERN_ERR PFX L_2 ) ;
}
V_3 -> V_13 = NULL ;
V_21 [ V_1 ] = - 1 ;
}
return 0 ;
}
static int F_9 ( unsigned long V_14 , unsigned char V_23 )
{
int V_24 ;
unsigned long V_25 ;
V_25 = V_26 + V_27 / 10 ;
for ( V_24 = 50000 ; V_24 && F_10 ( V_25 , V_26 ) ; V_24 -- )
if ( ! ( F_11 ( V_14 + 0x0c ) & 0x80 ) ) {
F_12 ( V_23 , V_14 + 0x0c ) ;
return 0 ;
}
return - V_28 ;
}
static int F_13 ( unsigned long V_14 )
{
int error ;
if ( ( error = F_9 ( V_14 , 0x09 ) ) )
return error ;
if ( ( error = F_9 ( V_14 , 0x00 ) ) )
return error ;
F_14 ( 5 ) ;
return 0 ;
}
static int F_15 ( int V_1 ,
struct V_4 * V_29 ,
const struct V_6 * V_30 )
{
int error ;
struct V_31 * V_5 ;
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
error = F_16 ( & V_29 -> V_5 -> V_1 ,
V_36 [ V_1 ] , V_7 [ V_1 ] , V_37 ,
sizeof( struct V_2 ) , & V_5 ) ;
if ( error < 0 )
return error ;
V_3 = V_5 -> V_38 ;
if ( ( error = F_1 ( V_1 , V_3 , V_29 , V_30 ) ) ) {
F_17 ( V_5 ) ;
return error ;
}
if ( ( error = F_13 ( V_14 [ V_1 ] ) ) ) {
F_17 ( V_5 ) ;
return error ;
}
error = F_18 ( V_5 , V_16 [ V_1 ] , - 1 ,
V_19 [ V_1 ] ,
V_17 [ V_1 ] , V_18 [ V_1 ] ,
V_39 , 0 , & V_33 ) ;
if ( error < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
strcpy ( V_5 -> V_40 , L_3 ) ;
strcpy ( V_5 -> V_41 , L_4 ) ;
sprintf ( V_5 -> V_42 , L_5 ,
V_5 -> V_41 , V_33 -> V_14 , V_19 [ V_1 ] , V_17 [ V_1 ] , V_18 [ V_1 ] ) ;
error = F_19 ( V_33 , 0 ) ;
if ( error < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
error = F_20 ( V_33 ) ;
if ( error < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
error = F_21 ( V_33 , 0 ) ;
if ( error < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
if ( V_21 [ V_1 ] > 0 && V_21 [ V_1 ] != V_43 ) {
if ( F_22 ( V_5 , 0 , V_44 ,
V_21 [ V_1 ] , 0 ,
V_22 [ V_1 ] , NULL ) < 0 )
F_4 (KERN_ERR PFX L_6 , mpu_port[dev]) ;
}
if ( V_15 [ V_1 ] > 0 && V_15 [ V_1 ] != V_43 ) {
if ( F_23 ( V_5 ,
V_15 [ V_1 ] , V_15 [ V_1 ] + 2 ,
V_45 , 0 , & V_35 ) < 0 ) {
F_4 (KERN_ERR PFX L_7 ,
fm_port[dev], fm_port[dev] + 2 ) ;
} else {
if ( ( error = F_24 ( V_35 , 1 , 2 ) ) < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
if ( ( error = F_25 ( V_35 , 0 , 1 , NULL ) ) < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
}
}
if ( ( error = F_26 ( V_5 ) ) < 0 ) {
F_17 ( V_5 ) ;
return error ;
}
F_27 ( V_29 , V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
static int V_1 ;
int V_46 ;
for ( ; V_1 < V_47 ; V_1 ++ ) {
if ( ! V_48 [ V_1 ] )
continue;
V_46 = F_15 ( V_1 , V_5 , V_7 ) ;
if ( V_46 < 0 )
return V_46 ;
V_1 ++ ;
V_49 ++ ;
return 0 ;
}
return - V_12 ;
}
static void F_29 ( struct V_4 * V_29 )
{
F_17 ( F_30 ( V_29 ) ) ;
F_27 ( V_29 , NULL ) ;
}
static int F_31 ( struct V_4 * V_29 , T_1 V_50 )
{
struct V_31 * V_5 = F_30 ( V_29 ) ;
struct V_2 * V_3 = V_5 -> V_38 ;
struct V_32 * V_33 = V_3 -> V_33 ;
F_32 ( V_5 , V_51 ) ;
V_33 -> V_52 ( V_33 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_29 )
{
struct V_31 * V_5 = F_30 ( V_29 ) ;
struct V_2 * V_3 = V_5 -> V_38 ;
struct V_32 * V_33 = V_3 -> V_33 ;
V_33 -> V_53 ( V_33 ) ;
F_32 ( V_5 , V_54 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
int V_10 ;
V_10 = F_35 ( & V_55 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_49 ) {
F_36 ( & V_55 ) ;
#ifdef F_37
F_4 ( V_56 L_8 ) ;
#endif
return - V_12 ;
}
return 0 ;
}
static void T_3 F_38 ( void )
{
F_36 ( & V_55 ) ;
}
