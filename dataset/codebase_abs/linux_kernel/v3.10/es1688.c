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
struct V_26 * V_27 ;
int error ;
error = F_10 ( V_6 , V_8 , 0 , & V_27 ) ;
if ( error < 0 )
return error ;
error = F_11 ( V_6 , V_8 ) ;
if ( error < 0 )
return error ;
F_12 ( V_6 -> V_28 , L_3 , sizeof( V_6 -> V_28 ) ) ;
F_12 ( V_6 -> V_29 , V_27 -> V_30 , sizeof( V_6 -> V_29 ) ) ;
snprintf ( V_6 -> V_31 , sizeof( V_6 -> V_31 ) ,
L_4 , V_27 -> V_30 , V_8 -> V_19 ,
V_8 -> V_14 , V_8 -> V_17 ) ;
if ( V_32 [ V_3 ] == V_20 )
V_32 [ V_3 ] = V_19 [ V_3 ] ;
if ( V_32 [ V_3 ] > 0 ) {
if ( F_13 ( V_6 , V_32 [ V_3 ] , V_32 [ V_3 ] + 2 ,
V_33 , 0 , & V_25 ) < 0 )
F_14 ( V_6 -> V_2 ,
L_5 , V_32 [ V_3 ] ) ;
else {
error = F_15 ( V_25 , 0 , 1 , NULL ) ;
if ( error < 0 )
return error ;
}
}
if ( V_22 [ V_3 ] >= 0 && V_22 [ V_3 ] != V_15 &&
V_8 -> V_21 > 0 ) {
error = F_16 ( V_6 , 0 , V_34 ,
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
error = F_19 ( V_35 [ V_3 ] , V_36 [ V_3 ] , V_37 ,
sizeof( struct V_7 ) , & V_6 ) ;
if ( error < 0 )
return error ;
error = F_3 ( V_6 , V_2 , V_3 ) ;
if ( error < 0 )
goto V_38;
F_20 ( V_6 , V_2 ) ;
error = F_9 ( V_6 , V_3 ) ;
if ( error < 0 )
goto V_38;
F_21 ( V_2 , V_6 ) ;
return 0 ;
V_38:
F_22 ( V_6 ) ;
return error ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_22 ( F_24 ( V_2 ) ) ;
F_21 ( V_2 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , unsigned int V_3 ,
struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_43 * V_44 ;
int error ;
V_44 = F_26 ( V_40 , V_42 -> V_45 [ 0 ] . V_36 , NULL ) ;
if ( V_44 == NULL )
return - V_46 ;
error = F_27 ( V_44 ) ;
if ( error < 0 ) {
F_28 ( V_47 L_6 ) ;
return error ;
}
V_19 [ V_3 ] = F_29 ( V_44 , 0 ) ;
V_17 [ V_3 ] = F_30 ( V_44 , 0 ) ;
V_14 [ V_3 ] = F_31 ( V_44 , 0 ) ;
return F_7 ( V_6 , V_8 , V_19 [ V_3 ] , V_21 [ V_3 ] , V_14 [ V_3 ] ,
V_22 [ V_3 ] , V_17 [ V_3 ] , V_23 ) ;
}
static int F_32 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_5 * V_6 ;
static unsigned int V_2 ;
int error ;
struct V_7 * V_8 ;
if ( V_48 )
return - V_16 ;
for ( ; V_2 < V_49 ; V_2 ++ ) {
if ( V_4 [ V_2 ] && V_50 [ V_2 ] )
break;
}
if ( V_2 == V_49 )
return - V_46 ;
error = F_19 ( V_35 [ V_2 ] , V_36 [ V_2 ] , V_37 ,
sizeof( struct V_7 ) , & V_6 ) ;
if ( error < 0 )
return error ;
V_8 = V_6 -> V_9 ;
error = F_25 ( V_6 , V_2 , V_40 , V_42 ) ;
if ( error < 0 ) {
F_22 ( V_6 ) ;
return error ;
}
F_20 ( V_6 , & V_40 -> V_6 -> V_2 ) ;
error = F_9 ( V_6 , V_2 ) ;
if ( error < 0 )
return error ;
F_33 ( V_40 , V_6 ) ;
V_48 = 1 ;
return 0 ;
}
static void F_34 ( struct V_39 * V_40 )
{
F_22 ( F_35 ( V_40 ) ) ;
F_33 ( V_40 , NULL ) ;
V_48 = 0 ;
}
static int F_36 ( struct V_39 * V_40 ,
T_1 V_51 )
{
struct V_5 * V_6 = F_35 ( V_40 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_37 ( V_6 , V_52 ) ;
F_38 ( V_8 -> V_27 ) ;
return 0 ;
}
static int F_39 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_35 ( V_40 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_40 ( V_8 ) ;
F_37 ( V_6 , V_53 ) ;
return 0 ;
}
static int T_2 F_41 ( void )
{
#ifdef F_42
F_43 ( & V_54 ) ;
if ( V_48 )
return 0 ;
F_44 ( & V_54 ) ;
#endif
return F_45 ( & V_55 , V_49 ) ;
}
static void T_3 F_46 ( void )
{
if ( ! V_48 ) {
F_47 ( & V_55 ) ;
return;
}
#ifdef F_42
F_44 ( & V_54 ) ;
#endif
}
