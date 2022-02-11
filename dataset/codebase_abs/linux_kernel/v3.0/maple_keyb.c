static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_5 ;
int V_6 , V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_6 = V_8 + 224 ;
V_7 = V_2 -> V_7 [ V_6 ] ;
F_2 ( V_4 , V_9 , V_10 , V_6 ) ;
F_3 ( V_4 , V_7 , ( V_2 -> V_11 [ 0 ] >> V_8 ) & 1 ) ;
}
for ( V_8 = 2 ; V_8 < 8 ; V_8 ++ ) {
V_5 = memchr ( V_2 -> V_11 + 2 , V_2 -> V_12 [ V_8 ] , 6 ) ;
V_6 = V_2 -> V_12 [ V_8 ] ;
if ( V_6 > 3 && V_5 == NULL ) {
V_7 = V_2 -> V_7 [ V_6 ] ;
if ( V_7 ) {
F_2 ( V_4 , V_9 , V_10 , V_6 ) ;
F_3 ( V_4 , V_7 , 0 ) ;
} else
F_4 ( & V_4 -> V_4 ,
L_1 ,
V_6 ) ;
}
V_5 = memchr ( V_2 -> V_12 + 2 , V_2 -> V_11 [ V_8 ] , 6 ) ;
V_6 = V_2 -> V_11 [ V_8 ] ;
if ( V_6 > 3 && V_5 ) {
V_7 = V_2 -> V_7 [ V_6 ] ;
if ( V_7 ) {
F_2 ( V_4 , V_9 , V_10 , V_6 ) ;
F_3 ( V_4 , V_7 , 1 ) ;
} else
F_4 ( & V_4 -> V_4 ,
L_2 ,
V_6 ) ;
}
}
F_5 ( V_4 ) ;
memcpy ( V_2 -> V_12 , V_2 -> V_11 , 8 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_4 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long * V_17 = ( unsigned long * ) ( V_14 -> V_18 -> V_17 ) ;
if ( F_8 ( F_9 ( & V_19 ) ) ) {
if ( V_17 [ 1 ] == V_16 -> V_20 ) {
memcpy ( V_2 -> V_11 , V_17 + 2 , 8 ) ;
F_1 ( V_2 ) ;
}
F_10 ( & V_19 ) ;
}
}
static int F_11 ( struct V_21 * V_4 )
{
struct V_15 * V_22 ;
struct V_23 * V_24 ;
int V_8 , error ;
struct V_1 * V_2 ;
struct V_3 * V_25 ;
V_22 = F_12 ( V_4 ) ;
V_24 = F_13 ( V_4 -> V_26 ) ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 ) {
error = - V_28 ;
goto V_29;
}
V_25 = F_15 () ;
if ( ! V_25 ) {
error = - V_28 ;
goto V_30;
}
V_2 -> V_4 = V_25 ;
memcpy ( V_2 -> V_7 , V_31 , sizeof( V_2 -> V_7 ) ) ;
V_25 -> V_32 = V_22 -> V_33 ;
V_25 -> V_34 [ 0 ] = F_16 ( V_35 ) | F_16 ( V_36 ) ;
V_25 -> V_7 = V_2 -> V_7 ;
V_25 -> V_37 = sizeof( unsigned short ) ;
V_25 -> V_38 = F_17 ( V_2 -> V_7 ) ;
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_4 . V_42 = & V_22 -> V_4 ;
for ( V_8 = 0 ; V_8 < V_43 ; V_8 ++ )
F_18 ( V_31 [ V_8 ] , V_25 -> V_44 ) ;
F_19 ( V_45 , V_25 -> V_44 ) ;
F_20 ( V_25 , V_9 , V_10 ) ;
F_21 ( V_25 , V_2 ) ;
error = F_22 ( V_25 ) ;
if ( error )
goto V_46;
F_23 ( V_22 , F_6 , V_47 / 50 ,
V_48 ) ;
V_22 -> V_26 = V_24 ;
F_24 ( V_22 , V_2 ) ;
return error ;
V_46:
F_24 ( V_22 , NULL ) ;
F_25 ( V_25 ) ;
V_30:
F_26 ( V_2 ) ;
V_29:
return error ;
}
static int F_27 ( struct V_21 * V_4 )
{
struct V_15 * V_22 = F_12 ( V_4 ) ;
struct V_1 * V_2 = F_7 ( V_22 ) ;
F_28 ( & V_19 ) ;
F_29 ( V_2 -> V_4 ) ;
F_26 ( V_2 ) ;
F_24 ( V_22 , NULL ) ;
F_10 ( & V_19 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_49 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_49 ) ;
}
