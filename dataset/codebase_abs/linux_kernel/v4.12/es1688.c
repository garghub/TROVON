static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] && ! F_2 ( V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_1 * V_2 , unsigned int V_3 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
static long V_10 [] = { 0x220 , 0x240 , 0x260 } ;
static int V_11 [] = { 5 , 9 , 10 , 7 , - 1 } ;
static int V_12 [] = { 1 , 3 , 0 , - 1 } ;
int V_13 , error ;
if ( V_14 [ V_3 ] == V_15 ) {
V_14 [ V_3 ] = F_4 ( V_11 ) ;
if ( V_14 [ V_3 ] < 0 ) {
F_5 ( V_2 , L_1 ) ;
return - V_16 ;
}
}
if ( V_17 [ V_3 ] == V_18 ) {
V_17 [ V_3 ] = F_6 ( V_12 ) ;
if ( V_17 [ V_3 ] < 0 ) {
F_5 ( V_2 , L_2 ) ;
return - V_16 ;
}
}
if ( V_19 [ V_3 ] != V_20 )
return F_7 ( V_6 , V_8 , V_19 [ V_3 ] , V_21 [ V_3 ] ,
V_14 [ V_3 ] , V_22 [ V_3 ] , V_17 [ V_3 ] , V_23 ) ;
V_13 = 0 ;
do {
V_19 [ V_3 ] = V_10 [ V_13 ] ;
error = F_7 ( V_6 , V_8 , V_19 [ V_3 ] , V_21 [ V_3 ] ,
V_14 [ V_3 ] , V_22 [ V_3 ] , V_17 [ V_3 ] , V_23 ) ;
} while ( error < 0 && ++ V_13 < F_8 ( V_10 ) );
return error ;
}
static int F_9 ( struct V_5 * V_6 , unsigned int V_3 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_24 * V_25 ;
int error ;
error = F_10 ( V_6 , V_8 , 0 ) ;
if ( error < 0 )
return error ;
error = F_11 ( V_6 , V_8 ) ;
if ( error < 0 )
return error ;
F_12 ( V_6 -> V_26 , L_3 , sizeof( V_6 -> V_26 ) ) ;
F_12 ( V_6 -> V_27 , V_8 -> V_28 -> V_29 , sizeof( V_6 -> V_27 ) ) ;
snprintf ( V_6 -> V_30 , sizeof( V_6 -> V_30 ) ,
L_4 , V_8 -> V_28 -> V_29 , V_8 -> V_19 ,
V_8 -> V_14 , V_8 -> V_17 ) ;
if ( V_31 [ V_3 ] == V_20 )
V_31 [ V_3 ] = V_19 [ V_3 ] ;
if ( V_31 [ V_3 ] > 0 ) {
if ( F_13 ( V_6 , V_31 [ V_3 ] , V_31 [ V_3 ] + 2 ,
V_32 , 0 , & V_25 ) < 0 )
F_14 ( V_6 -> V_2 ,
L_5 , V_31 [ V_3 ] ) ;
else {
error = F_15 ( V_25 , 0 , 1 , NULL ) ;
if ( error < 0 )
return error ;
}
}
if ( V_22 [ V_3 ] >= 0 && V_22 [ V_3 ] != V_15 &&
V_8 -> V_21 > 0 ) {
error = F_16 ( V_6 , 0 , V_33 ,
V_8 -> V_21 , 0 ,
V_22 [ V_3 ] , NULL ) ;
if ( error < 0 )
return error ;
}
return F_17 ( V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 ;
int error ;
error = F_19 ( V_2 , V_34 [ V_3 ] , V_35 [ V_3 ] , V_36 ,
sizeof( struct V_7 ) , & V_6 ) ;
if ( error < 0 )
return error ;
error = F_3 ( V_6 , V_2 , V_3 ) ;
if ( error < 0 )
goto V_37;
error = F_9 ( V_6 , V_3 ) ;
if ( error < 0 )
goto V_37;
F_20 ( V_2 , V_6 ) ;
return 0 ;
V_37:
F_21 ( V_6 ) ;
return error ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_21 ( F_23 ( V_2 ) ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , unsigned int V_3 ,
struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_42 * V_43 ;
int error ;
V_43 = F_25 ( V_39 , V_41 -> V_44 [ 0 ] . V_35 , NULL ) ;
if ( V_43 == NULL )
return - V_45 ;
error = F_26 ( V_43 ) ;
if ( error < 0 ) {
F_27 ( V_46 L_6 ) ;
return error ;
}
V_19 [ V_3 ] = F_28 ( V_43 , 0 ) ;
V_17 [ V_3 ] = F_29 ( V_43 , 0 ) ;
V_14 [ V_3 ] = F_30 ( V_43 , 0 ) ;
return F_7 ( V_6 , V_8 , V_19 [ V_3 ] , V_21 [ V_3 ] , V_14 [ V_3 ] ,
V_22 [ V_3 ] , V_17 [ V_3 ] , V_23 ) ;
}
static int F_31 ( struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
struct V_5 * V_6 ;
static unsigned int V_2 ;
int error ;
struct V_7 * V_8 ;
if ( V_47 )
return - V_16 ;
for ( ; V_2 < V_48 ; V_2 ++ ) {
if ( V_4 [ V_2 ] && V_49 [ V_2 ] )
break;
}
if ( V_2 == V_48 )
return - V_45 ;
error = F_19 ( & V_39 -> V_6 -> V_2 ,
V_34 [ V_2 ] , V_35 [ V_2 ] , V_36 ,
sizeof( struct V_7 ) , & V_6 ) ;
if ( error < 0 )
return error ;
V_8 = V_6 -> V_9 ;
error = F_24 ( V_6 , V_2 , V_39 , V_41 ) ;
if ( error < 0 ) {
F_21 ( V_6 ) ;
return error ;
}
error = F_9 ( V_6 , V_2 ) ;
if ( error < 0 )
return error ;
F_32 ( V_39 , V_6 ) ;
V_47 = 1 ;
return 0 ;
}
static void F_33 ( struct V_38 * V_39 )
{
F_21 ( F_34 ( V_39 ) ) ;
F_32 ( V_39 , NULL ) ;
V_47 = 0 ;
}
static int F_35 ( struct V_38 * V_39 ,
T_1 V_50 )
{
struct V_5 * V_6 = F_34 ( V_39 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_36 ( V_6 , V_51 ) ;
F_37 ( V_8 -> V_28 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_34 ( V_39 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_39 ( V_8 ) ;
F_36 ( V_6 , V_52 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
#ifdef F_41
F_42 ( & V_53 ) ;
if ( V_47 )
return 0 ;
F_43 ( & V_53 ) ;
#endif
return F_44 ( & V_54 , V_48 ) ;
}
static void T_3 F_45 ( void )
{
if ( ! V_47 ) {
F_46 ( & V_54 ) ;
return;
}
#ifdef F_41
F_43 ( & V_53 ) ;
#endif
}
