struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_6 ;
struct V_7 * V_8 , * V_9 ;
struct V_1 * V_10 ;
int V_11 ;
if ( ! V_3 ) {
F_2 ( 1 , V_12 L_1 ) ;
return NULL ;
}
F_2 ( 2 ,
L_2 ,
V_3 -> V_13 , V_3 -> V_14 , V_3 -> V_15 ) ;
if ( ! V_5 ) {
F_2 ( 1 ,
V_12
L_3 ) ;
return NULL ;
}
while ( V_5 ) {
if ( ( V_3 -> V_14 & V_5 -> V_10 -> V_14 ) == V_3 -> V_14 ) {
F_2 ( 4 , L_4 ,
V_5 -> V_10 -> V_13 ) ;
if ( ! F_3 ( V_5 -> V_10 -> V_16 ) )
return NULL ;
V_10 = F_4 ( V_5 -> V_10 , sizeof( struct V_1 ) ,
V_17 ) ;
if ( ! V_10 ) {
F_2 ( 1 ,
V_12
L_5 ) ;
goto V_18;
}
V_11 = strlen ( V_10 -> V_13 ) ;
snprintf ( V_10 -> V_13 + V_11 , sizeof( V_10 -> V_13 ) - V_11 ,
L_6 , V_5 -> V_19 ) ;
V_10 -> V_20 = V_3 ;
V_11 = V_10 -> V_21 ( V_10 ) ;
if ( V_11 == 0 ) {
F_2 ( 3 , L_7 ,
V_10 -> V_13 ) ;
V_9 = F_5 ( sizeof( struct V_7 ) , V_17 ) ;
if ( ! V_9 ) {
F_2 ( 1 ,
V_12
L_8 ) ;
goto V_22;
}
V_9 -> V_10 = V_10 ;
V_8 = V_5 -> V_23 ;
if ( ! V_8 ) {
V_5 -> V_23 = V_9 ;
F_2 ( 4 ,
L_9 ) ;
} else {
while ( V_8 -> V_24 )
V_8 = V_8 -> V_24 ;
V_8 -> V_24 = V_9 ;
F_2 ( 4 ,
L_10 ,
V_5 -> V_10 -> V_13 ) ;
}
V_5 -> V_19 += 1 ;
return V_10 ;
} else {
F_6 ( V_10 ) ;
}
}
V_5 = V_5 -> V_24 ;
}
F_2 ( 1 , V_12 L_11 ) ;
return NULL ;
V_18:
F_7 ( V_5 -> V_10 -> V_16 ) ;
V_22:
F_6 ( V_10 ) ;
return NULL ;
}
int
F_8 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = V_6 ;
struct V_7 * V_8 , * V_25 ;
int V_11 ;
if ( ! V_10 ) {
F_2 ( 1 , V_12 L_12 ) ;
return - V_26 ;
}
F_2 ( 2 ,
L_13 ,
V_10 -> V_13 , V_10 -> type , V_10 -> V_14 , V_10 -> V_15 ) ;
if ( ! V_5 ) {
F_2 ( 1 ,
V_12 L_14 ) ;
return - V_27 ;
}
while ( V_5 ) {
V_8 = V_5 -> V_23 ;
V_25 = NULL ;
while ( V_8 ) {
if ( V_10 == V_8 -> V_10 ) {
V_11 = V_8 -> V_10 -> V_28 ( V_8 -> V_10 ) ;
if ( V_11 >= 0 ) {
F_2 ( 3 ,
L_15 ,
V_8 -> V_10 -> V_13 ) ;
V_8 -> V_10 -> V_20 = NULL ;
} else {
F_2 ( 1 ,
V_12
L_15 ,
V_8 -> V_10 -> V_13 ) ;
V_8 -> V_10 -> V_20 = NULL ;
}
if ( V_25 == NULL ) {
V_5 -> V_23 = V_8 -> V_24 ;
F_2 ( 4 ,
L_16 ) ;
} else {
V_25 -> V_24 = V_8 -> V_24 ;
F_2 ( 4 ,
L_17 ) ;
}
F_7 ( V_8 -> V_10 -> V_16 ) ;
F_6 ( V_8 -> V_10 ) ;
F_6 ( V_8 ) ;
V_5 -> V_19 -= 1 ;
return 0 ;
}
V_25 = V_8 ;
V_8 = V_8 -> V_24 ;
}
V_5 = V_5 -> V_24 ;
}
F_2 ( 1 , V_12 L_18 ) ;
return - V_26 ;
}
int
F_9 ( const struct V_1 * V_10 )
{
struct V_4 * V_9 , * V_5 = V_6 ;
if ( ! V_10 ) {
F_2 ( 1 , V_12 L_19 ) ;
return - V_26 ;
}
F_2 ( 2 ,
L_20 ,
V_10 -> V_13 , V_10 -> type , V_10 -> V_14 , V_10 -> V_15 ) ;
V_9 = F_5 ( sizeof( struct V_4 ) , V_17 ) ;
if ( ! V_9 ) {
F_2 ( 1 , V_12 L_21 ) ;
return - V_29 ;
}
V_9 -> V_10 = V_10 ;
if ( ! V_5 ) {
V_6 = V_9 ;
F_2 ( 4 , L_22 ) ;
} else {
while ( V_5 -> V_24 )
V_5 = V_5 -> V_24 ;
V_5 -> V_24 = V_9 ;
F_2 ( 4 , L_23 ,
V_5 -> V_10 -> V_13 ) ;
}
return 0 ;
}
int
F_10 ( const struct V_1 * V_10 )
{
struct V_4 * V_25 = NULL , * V_5 = V_6 ;
if ( ! V_10 ) {
F_2 ( 1 , V_12 L_24 ) ;
return - V_26 ;
}
F_2 ( 2 ,
L_25 ,
V_10 -> V_13 , V_10 -> type , V_10 -> V_14 , V_10 -> V_15 ) ;
if ( ! V_5 ) {
F_2 ( 1 ,
V_12
L_26 ) ;
return - V_27 ;
}
while ( V_5 ) {
if ( V_10 == V_5 -> V_10 ) {
if ( V_5 -> V_19 ) {
F_2 ( 1 ,
V_12
L_27 ,
V_5 -> V_10 -> V_13 ) ;
return - V_30 ;
}
F_2 ( 3 , L_28 ,
V_5 -> V_10 -> V_13 ) ;
if ( V_25 == NULL ) {
V_6 = V_5 -> V_24 ;
F_2 ( 4 ,
L_29 ) ;
} else {
V_25 -> V_24 = V_5 -> V_24 ;
F_2 ( 4 ,
L_30 ) ;
}
F_6 ( V_5 ) ;
return 0 ;
}
V_25 = V_5 ;
V_5 = V_5 -> V_24 ;
}
F_2 ( 1 ,
V_12
L_31 ) ;
return - V_26 ;
}
static int F_11 ( struct V_31 * V_32 , void * V_33 )
{
struct V_4 * V_5 = V_6 ;
struct V_7 * V_8 ;
F_12 ( V_32 , L_32 ) ;
F_12 ( V_32 , L_33 ) ;
V_5 = V_6 ;
while ( V_5 ) {
F_12 ( V_32 , L_34 ,
V_5 -> V_10 -> V_13 , V_5 -> V_10 -> type ,
V_5 -> V_10 -> V_14 , V_5 -> V_10 -> V_15 ) ;
V_8 = V_5 -> V_23 ;
while ( V_8 ) {
F_12 ( V_32 , L_35 ,
V_8 -> V_10 -> V_20 -> V_13 ,
V_8 -> V_10 -> V_20 -> type ,
V_8 -> V_10 -> V_20 -> V_14 ,
V_8 -> V_10 -> V_20 -> V_15 ,
V_8 -> V_10 -> V_13 ) ;
V_8 = V_8 -> V_24 ;
}
V_5 = V_5 -> V_24 ;
}
return 0 ;
}
static int F_13 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_14 ( V_35 , F_11 , NULL ) ;
}
static int T_1
F_15 ( void )
{
#ifdef F_16
static struct V_36 * V_37 ;
#endif
F_17 ( V_38 L_36 ,
V_39 ) ;
#ifdef F_16
V_37 = F_18 ( L_37 , 0 , NULL , & V_40 ) ;
if ( ! V_37 ) {
F_2 ( 1 , V_12 L_38 ) ;
}
#endif
return 0 ;
}
static void T_2
F_19 ( void )
{
#ifdef F_16
F_20 ( L_37 , NULL ) ;
#endif
}
