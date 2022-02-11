static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
#ifndef F_3
F_4 ( V_2 ) ;
F_5 ( V_4 -> V_5 ) ;
F_6 ( V_2 ) ;
#endif
}
int F_7 ( T_1 * V_6 )
{
struct V_1 * V_2 = V_7 -> V_8 ;
int V_9 ;
T_2 V_10 ;
F_6 ( V_2 ) ;
V_2 -> V_11 = V_6 -> V_12 ;
if ( V_6 -> V_13 ) {
if ( V_6 -> V_14 ) {
F_8 ( V_2 , V_6 -> V_10 , V_6 -> V_15 , & V_9 ) ;
V_10 = F_9 ( V_2 , V_6 -> V_15 , & V_9 ) ;
V_6 -> V_10 = V_10 ;
} else {
F_8 ( V_2 , V_6 -> V_10 , V_6 -> V_15 , & V_9 ) ;
}
} else {
V_10 = F_9 ( V_2 , V_6 -> V_15 , & V_9 ) ;
V_6 -> V_10 = V_10 ;
}
F_4 ( V_2 ) ;
if ( V_9 < 0 ) {
F_10 ( L_1 , V_9 ) ;
return 0 ;
}
return 1 ;
}
int F_11 ( T_3 * V_6 )
{
struct V_1 * V_2 = V_7 -> V_8 ;
int V_16 , V_9 ;
F_6 ( V_2 ) ;
V_2 -> V_11 = V_6 -> V_12 ;
V_2 -> V_17 = V_6 -> V_18 ;
if ( V_6 -> V_19 )
V_16 = V_6 -> V_20 * V_6 -> V_18 ;
else
V_16 = V_6 -> V_20 ;
if ( V_6 -> V_13 ) {
V_9 = F_12 ( V_2 , V_6 -> V_15 , ( void * ) V_6 -> V_21 , V_16 ) ;
} else {
V_9 = F_13 ( V_2 , ( void * ) V_6 -> V_21 , V_6 -> V_15 , V_16 ) ;
}
F_4 ( V_2 ) ;
if ( V_9 < 0 ) {
F_10 ( L_2 , V_9 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
F_15 ( V_24 , L_3 ) ;
V_4 = F_16 ( sizeof( struct V_3 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
F_15 ( V_24 , L_4 ) ;
V_27 = V_2 ;
if ( F_17 ( & V_5 ) ) {
F_10 ( L_5 ) ;
F_18 ( V_4 ) ;
return - 1 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_5 ;
F_19 ( V_2 , V_4 ) ;
F_20 ( L_6 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_22 () ;
F_18 ( V_4 ) ;
}
int F_23 ( void )
{
int V_9 = 0 ;
#ifndef F_3
F_6 ( V_27 ) ;
V_9 = F_24 ( V_27 , F_1 ) ;
F_4 ( V_27 ) ;
if ( V_9 < 0 ) {
F_10 ( L_7 , V_9 ) ;
V_9 = - V_28 ;
}
#endif
return V_9 ;
}
void F_25 ( void )
{
#ifndef F_3
int V_9 ;
F_15 ( V_24 , L_8 ) ;
F_6 ( V_27 ) ;
V_9 = F_26 ( V_27 ) ;
if ( V_9 < 0 ) {
F_10 ( L_9 , V_9 ) ;
}
F_4 ( V_27 ) ;
F_15 ( V_24 , L_10 ) ;
#endif
}
static int F_27 ( int V_29 )
{
struct V_30 V_31 ;
F_6 ( V_27 ) ;
memcpy ( ( void * ) & V_31 , ( void * ) & V_27 -> V_32 -> V_33 -> V_31 , sizeof( struct V_30 ) ) ;
V_27 -> V_32 -> V_33 -> V_31 . clock = V_29 ;
V_31 . clock = V_29 ;
V_27 -> V_32 -> V_33 -> V_34 -> V_35 ( V_27 -> V_32 -> V_33 , & V_31 ) ;
F_4 ( V_27 ) ;
F_28 ( V_24 , L_11 , V_29 ) ;
return 1 ;
}
static int F_29 ( void )
{
return V_27 -> V_32 -> V_33 -> V_31 . clock ;
}
int F_30 ( void * V_36 )
{
V_37 = F_29 () ;
return 1 ;
}
void F_31 ( void * V_36 )
{
F_32 ( & V_38 ) ;
}
int F_33 ( void )
{
return F_27 ( V_39 ) ;
}
int F_34 ( void )
{
return F_27 ( V_37 ) ;
}
