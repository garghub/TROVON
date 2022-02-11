static int
F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 ;
struct V_1 V_9 ;
V_8 = V_4 ;
if ( V_2 -> V_10 . V_11 == V_12 ||
V_2 -> type == V_13 )
return 0 ;
V_9 = * V_2 ;
if ( V_8 -> V_14 )
V_9 . V_10 . V_15 = V_8 -> V_16 ;
else
V_9 . V_10 . V_15 = V_8 -> V_15 ;
V_9 . V_17 . V_11 = V_18 ;
return F_2 ( V_8 -> V_11 , & V_9 , V_5 , V_6 ) ;
}
static void
F_3 ( void * V_4 )
{
F_4 ( V_4 ) ;
}
static struct V_7 T_1 *
F_5 ( int V_19 , int type )
{
struct V_20 V_21 ;
struct V_22 V_23 ;
struct V_7 * V_24 ;
if ( ( V_24 = F_6 ( sizeof( * V_24 ) , V_25 ) ) == NULL )
return NULL ;
V_24 -> V_11 = V_26 ;
V_24 -> V_14 = V_14 ;
V_24 -> V_16 = 0 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_27 . V_11 = V_26 ;
if ( V_14 )
sprintf ( V_21 . V_28 , L_1 , V_19 ,
( type ? 'B' : 'A' ) ) ;
else
sprintf ( V_21 . V_28 , L_2 , V_19 ) ;
V_21 . V_29 = V_30 | V_31 ;
V_21 . V_29 |= V_32 | V_33 ;
if ( V_14 )
V_21 . V_29 |= V_34 ;
V_21 . type = V_35
| V_36
| V_37 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_38 = V_39 ;
V_23 . V_40 = F_1 ;
V_23 . V_41 = F_3 ;
V_23 . V_4 = V_24 ;
V_21 . V_42 = & V_23 ;
if ( F_7 ( V_26 , V_43 , & V_21 ) < 0 ) {
F_4 ( V_24 ) ;
return NULL ;
}
V_24 -> V_15 = V_21 . V_27 . V_15 ;
return V_24 ;
}
static int T_1
F_8 ( void )
{
struct V_7 * V_44 , * V_45 ;
int V_46 ;
if ( V_47 < 1 ) {
F_9 ( L_3 , V_47 ) ;
return - V_48 ;
}
V_26 = F_10 ( NULL , V_49 ,
L_4 ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
V_44 = F_5 ( V_46 , 0 ) ;
if ( V_44 == NULL ) {
F_11 ( V_26 ) ;
return - V_50 ;
}
if ( V_14 ) {
V_45 = F_5 ( V_46 , 1 ) ;
if ( V_45 == NULL ) {
F_11 ( V_26 ) ;
return - V_50 ;
}
V_44 -> V_16 = V_45 -> V_15 ;
V_45 -> V_16 = V_44 -> V_15 ;
}
}
return 0 ;
}
static void T_2
F_12 ( void )
{
if ( V_26 >= 0 )
F_11 ( V_26 ) ;
}
static int T_1 F_13 ( void )
{
int V_51 ;
F_14 () ;
V_51 = F_8 () ;
F_15 () ;
return V_51 ;
}
static void T_2 F_16 ( void )
{
F_12 () ;
}
