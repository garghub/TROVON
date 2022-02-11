static void F_1 ( struct V_1 * V_2 )
{
#ifndef F_2
F_3 ( V_2 ) ;
F_4 () ;
F_5 ( V_2 ) ;
#endif
}
int F_6 ( T_1 * V_3 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
int V_6 ;
T_2 V_7 ;
F_5 ( V_2 ) ;
V_2 -> V_8 = V_3 -> V_9 ;
if ( V_3 -> V_10 ) {
if ( V_3 -> V_11 ) {
F_7 ( V_2 , V_3 -> V_7 , V_3 -> V_12 , & V_6 ) ;
V_7 = F_8 ( V_2 , V_3 -> V_12 , & V_6 ) ;
V_3 -> V_7 = V_7 ;
} else {
F_7 ( V_2 , V_3 -> V_7 , V_3 -> V_12 , & V_6 ) ;
}
} else {
V_7 = F_8 ( V_2 , V_3 -> V_12 , & V_6 ) ;
V_3 -> V_7 = V_7 ;
}
F_3 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( L_1 , V_6 ) ;
return 0 ;
}
return 1 ;
}
int F_10 ( T_3 * V_3 )
{
struct V_1 * V_2 = V_4 -> V_5 ;
int V_13 , V_6 ;
F_5 ( V_2 ) ;
V_2 -> V_8 = V_3 -> V_9 ;
V_2 -> V_14 = V_3 -> V_15 ;
if ( V_3 -> V_16 )
V_13 = V_3 -> V_17 * V_3 -> V_15 ;
else
V_13 = V_3 -> V_17 ;
if ( V_3 -> V_10 ) {
V_6 = F_11 ( V_2 , V_3 -> V_12 , ( void * ) V_3 -> V_18 , V_13 ) ;
} else {
V_6 = F_12 ( V_2 , ( void * ) V_3 -> V_18 , V_3 -> V_12 , V_13 ) ;
}
F_3 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( L_2 , V_6 ) ;
return 0 ;
}
return 1 ;
}
static int F_13 ( struct V_1 * V_2 , const struct V_19 * V_20 )
{
F_14 ( V_21 , L_3 ) ;
#ifdef F_15
if ( V_22 != NULL ) {
V_22 = V_2 ;
V_23 = 1 ;
F_14 ( V_21 , L_4 ) ;
return 0 ;
}
#endif
F_14 ( V_21 , L_5 ) ;
V_22 = V_2 ;
if ( F_16 () ) {
F_9 ( L_6 ) ;
return - 1 ;
}
F_17 ( L_7 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
}
int F_19 ( void )
{
int V_6 = 0 ;
#ifndef F_2
F_5 ( V_22 ) ;
V_6 = F_20 ( V_22 , F_1 ) ;
F_3 ( V_22 ) ;
if ( V_6 < 0 ) {
F_9 ( L_8 , V_6 ) ;
V_6 = - V_24 ;
}
#endif
return V_6 ;
}
void F_21 ( void )
{
#ifndef F_2
int V_6 ;
F_14 ( V_21 , L_9 ) ;
F_5 ( V_22 ) ;
V_6 = F_22 ( V_22 ) ;
if ( V_6 < 0 ) {
F_9 ( L_10 , V_6 ) ;
}
F_3 ( V_22 ) ;
F_14 ( V_21 , L_11 ) ;
#endif
}
static int F_23 ( int V_25 )
{
struct V_26 V_27 ;
F_5 ( V_22 ) ;
memcpy ( ( void * ) & V_27 , ( void * ) & V_22 -> V_28 -> V_29 -> V_27 , sizeof( struct V_26 ) ) ;
V_22 -> V_28 -> V_29 -> V_27 . clock = V_25 ;
V_27 . clock = V_25 ;
V_22 -> V_28 -> V_29 -> V_30 -> V_31 ( V_22 -> V_28 -> V_29 , & V_27 ) ;
F_3 ( V_22 ) ;
F_24 ( V_21 , L_12 , V_25 ) ;
return 1 ;
}
static int F_25 ( void )
{
return V_22 -> V_28 -> V_29 -> V_27 . clock ;
}
int F_26 ( void * V_32 )
{
V_33 = F_25 () ;
return 1 ;
}
void F_27 ( void * V_32 )
{
F_28 ( & V_34 ) ;
}
int F_29 ( void )
{
return F_23 ( V_35 ) ;
}
int F_30 ( void )
{
return F_23 ( V_33 ) ;
}
