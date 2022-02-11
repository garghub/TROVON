static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_2 -> V_5 . V_6 , 16 , L_1 ) ) {
F_3 ( V_7 L_2 ) ;
F_4 ( V_2 ) ;
return - V_8 ;
}
if ( ! F_5 ( & V_2 -> V_5 , 0 , 0 , V_4 ) ) {
F_6 ( V_2 -> V_5 . V_6 , 16 ) ;
F_3 ( V_7 L_3 ) ;
F_4 ( V_2 ) ;
return - V_9 ;
}
if( ! F_7 ( & V_2 -> V_5 , V_10 ) ) {
F_3 ( V_7 L_4 ) ;
F_4 ( V_2 ) ;
return - V_9 ;
}
if( V_2 -> V_11 . V_6 > 0 ) {
V_2 -> V_12 = 1 ;
F_3 ( V_13 L_5 ) ;
if( ! F_8 ( & V_2 -> V_11 , V_10 ) )
V_2 -> V_12 = 0 ;
}
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 , 0 ) ;
if( V_2 -> V_12 )
F_11 ( & V_2 -> V_11 ) ;
F_4 ( V_2 ) ;
}
static int T_1 F_12 ( void )
{
struct V_3 V_4 = { 0 } ;
if( ( V_14 = F_13 ( sizeof( struct V_1 ) , V_15 ) ) == NULL ) {
F_3 ( V_7 L_6 ) ;
return - V_16 ;
}
V_14 -> V_5 . V_6 = V_17 ;
V_14 -> V_5 . V_18 = V_18 ;
V_14 -> V_5 . V_19 = V_19 ;
V_14 -> V_5 . V_20 = V_21 ;
V_14 -> V_5 . V_22 = type ;
V_14 -> V_11 . V_6 = V_23 ;
V_14 -> V_11 . V_18 = - 1 ;
V_14 -> V_11 . V_19 = - 1 ;
V_14 -> V_11 . V_20 = - 1 ;
V_4 . V_24 = V_24 ;
V_4 . V_25 = V_25 ;
V_4 . V_26 = V_26 ;
return F_1 ( V_14 , & V_4 ) ;
}
static void F_14 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 = - 1 ;
V_2 -> V_5 . V_18 = - 1 ;
V_2 -> V_5 . V_19 = - 1 ;
V_2 -> V_5 . V_20 = - 1 ;
V_2 -> V_11 . V_6 = - 1 ;
V_2 -> V_11 . V_18 = - 1 ;
V_2 -> V_11 . V_19 = - 1 ;
V_2 -> V_11 . V_20 = - 1 ;
if( ! strncmp ( L_7 , V_2 -> V_29 , 3 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 0 ) ;
V_2 -> V_5 . V_20 = F_17 ( V_28 , 1 ) ;
V_2 -> V_11 . V_6 = F_15 ( V_28 , 1 ) ;
return;
}
if( ! strncmp ( L_8 , V_2 -> V_29 , 3 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 0 ) ;
V_2 -> V_5 . V_20 = F_17 ( V_28 , 1 ) ;
return;
}
if( ! strncmp ( L_9 , V_2 -> V_29 , 3 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 0 ) ;
V_2 -> V_5 . V_20 = F_17 ( V_28 , 1 ) ;
V_2 -> V_11 . V_6 = F_15 ( V_28 , 2 ) ;
return;
}
if( ! strncmp ( L_10 , V_2 -> V_29 , 3 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 0 ) ;
V_2 -> V_5 . V_20 = F_17 ( V_28 , 1 ) ;
return;
}
if( ! strncmp ( L_11 , V_2 -> V_29 , 3 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 0 ) ;
return;
}
if( ! strncmp ( L_12 , V_2 -> V_29 , 3 ) ) {
if( ! strncmp ( L_13 , V_2 -> V_29 , 7 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 0 ) ;
} else {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 1 ) ;
V_2 -> V_5 . V_20 = F_17 ( V_28 , 0 ) ;
}
return;
}
if( ! strncmp ( L_14 , V_2 -> V_29 , 3 ) ) {
V_2 -> V_5 . V_6 = F_15 ( V_28 , 0 ) ;
V_2 -> V_5 . V_18 = F_16 ( V_28 , 0 ) ;
V_2 -> V_5 . V_19 = F_17 ( V_28 , 1 ) ;
V_2 -> V_5 . V_20 = F_17 ( V_28 , 0 ) ;
}
}
static int F_18 ( struct V_30 * V_31 , const struct V_32 * V_29 )
{
struct V_1 * V_2 ;
struct V_3 V_4 = { 0 } ;
struct V_27 * V_28 = F_19 ( V_31 , V_29 -> V_33 [ 0 ] . V_34 , NULL ) ;
if( ! V_28 ) {
return - V_8 ;
}
if( ( V_2 = F_13 ( sizeof( struct V_1 ) , V_15 ) ) == NULL ) {
F_3 ( V_7 L_6 ) ;
return - V_16 ;
}
F_3 ( V_13 L_15 \
L_16 , V_31 -> V_31 -> V_35 , V_29 -> V_34 ,
V_28 -> V_34 -> V_34 ) ;
V_2 -> V_29 = V_29 -> V_34 ;
V_2 -> V_36 = V_28 -> V_34 -> V_34 ;
F_14 ( V_28 , V_2 ) ;
F_3 ( V_13 L_17 \
L_18 , V_2 -> V_5 . V_6 , V_2 -> V_5 . V_18 ,
V_2 -> V_5 . V_19 , V_2 -> V_5 . V_20 ) ;
F_20 ( V_31 , V_2 ) ;
V_37 ++ ;
return F_1 ( V_2 , & V_4 ) ;
}
static void F_21 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_22 ( V_31 ) ;
if( ! V_2 )
return;
F_3 ( V_13 L_19 , V_2 -> V_29 ) ;
F_9 ( V_2 ) ;
}
static void F_23 ( void )
{
#ifdef F_24
if ( V_38 )
F_25 ( & V_39 ) ;
#endif
}
static int T_1 F_26 ( void )
{
int V_40 = 0 ;
int V_41 = 0 ;
F_3 ( V_13 L_20 ) ;
if( V_17 != - 1 && V_18 != - 1 && V_19 != - 1 ) {
F_3 ( V_13 L_21\
L_22 , V_17 , V_18 , V_19 , V_21 ) ;
V_40 = F_12 () ;
} else if( ( V_17 != - 1 || V_18 != - 1 || V_19 != - 1 ) ||
( ! V_42 && ( V_17 == - 1 && V_18 == - 1 && V_19 == - 1 ) ) )
F_3 ( V_7 L_23\
L_24 ) ;
#ifdef F_24
if( V_42 ) {
int V_43 = F_27 ( & V_39 ) ;
if ( ! V_43 )
V_38 = 1 ;
V_41 = V_37 ;
}
#endif
F_3 ( V_13 L_25 ) ;
if ( V_41 == 0 && V_40 <= 0 ) {
F_23 () ;
return - V_9 ;
}
return 0 ;
}
static void T_2 F_28 ( void )
{
F_3 ( V_13 L_26 ) ;
if ( V_14 ) {
F_3 ( V_13 L_27 ) ;
F_9 ( V_14 ) ;
}
F_23 () ;
F_29 ( V_44 ) ;
V_44 = NULL ;
}
