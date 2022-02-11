static int
F_1 ( void * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
struct V_7 V_8 ;
V_5 = V_1 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
if ( V_5 -> V_9 )
V_8 . V_10 . V_11 = V_5 -> V_12 ;
else
V_8 . V_10 . V_11 = V_5 -> V_11 ;
V_8 . V_13 . V_14 = V_15 ;
V_8 . type = V_16 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
V_8 . V_17 . V_18 . V_19 = V_6 ;
V_8 . V_17 . V_18 . V_20 = V_21 ;
F_2 ( V_5 -> V_14 , & V_8 , 0 , 0 ) ;
V_8 . V_17 . V_18 . V_20 = V_22 ;
F_2 ( V_5 -> V_14 , & V_8 , 0 , 0 ) ;
}
return 0 ;
}
static int
F_3 ( struct V_7 * V_8 , int V_23 , void * V_1 ,
int V_24 , int V_25 )
{
struct V_4 * V_5 ;
struct V_7 V_26 ;
V_5 = V_1 ;
if ( V_8 -> V_10 . V_14 == V_27 ||
V_8 -> type == V_28 )
return 0 ;
V_26 = * V_8 ;
if ( V_5 -> V_9 )
V_26 . V_10 . V_11 = V_5 -> V_12 ;
else
V_26 . V_10 . V_11 = V_5 -> V_11 ;
V_26 . V_13 . V_14 = V_15 ;
return F_2 ( V_5 -> V_14 , & V_26 , V_24 , V_25 ) ;
}
static void
F_4 ( void * V_1 )
{
F_5 ( V_1 ) ;
}
static struct V_4 T_1 *
F_6 ( int V_29 , int type )
{
struct V_30 V_31 ;
struct V_32 V_33 ;
struct V_4 * V_34 ;
if ( ( V_34 = F_7 ( sizeof( * V_34 ) , V_35 ) ) == NULL )
return NULL ;
V_34 -> V_14 = V_36 ;
V_34 -> V_9 = V_9 ;
V_34 -> V_12 = 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_37 . V_14 = V_36 ;
if ( V_9 )
sprintf ( V_31 . V_38 , L_1 , V_29 ,
( type ? 'B' : 'A' ) ) ;
else
sprintf ( V_31 . V_38 , L_2 , V_29 ) ;
V_31 . V_39 = V_40 | V_41 ;
V_31 . V_39 |= V_42 | V_43 ;
if ( V_9 )
V_31 . V_39 |= V_44 ;
V_31 . type = V_45
| V_46
| V_47 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_48 = V_49 ;
V_33 . V_50 = F_1 ;
V_33 . V_51 = F_3 ;
V_33 . V_52 = F_4 ;
V_33 . V_1 = V_34 ;
V_31 . V_53 = & V_33 ;
if ( F_8 ( V_36 , V_54 , & V_31 ) < 0 ) {
F_5 ( V_34 ) ;
return NULL ;
}
V_34 -> V_11 = V_31 . V_37 . V_11 ;
return V_34 ;
}
static int T_1
F_9 ( void )
{
struct V_4 * V_55 , * V_56 ;
int V_6 ;
if ( V_57 < 1 ) {
F_10 ( V_58 L_3 , V_57 ) ;
return - V_59 ;
}
V_36 = F_11 ( NULL , V_60 ,
L_4 ) ;
if ( V_36 < 0 )
return V_36 ;
for ( V_6 = 0 ; V_6 < V_57 ; V_6 ++ ) {
V_55 = F_6 ( V_6 , 0 ) ;
if ( V_55 == NULL ) {
F_12 ( V_36 ) ;
return - V_61 ;
}
if ( V_9 ) {
V_56 = F_6 ( V_6 , 1 ) ;
if ( V_56 == NULL ) {
F_12 ( V_36 ) ;
return - V_61 ;
}
V_55 -> V_12 = V_56 -> V_11 ;
V_56 -> V_12 = V_55 -> V_11 ;
}
}
return 0 ;
}
static void T_2
F_13 ( void )
{
if ( V_36 >= 0 )
F_12 ( V_36 ) ;
}
static int T_1 F_14 ( void )
{
int V_62 ;
F_15 () ;
V_62 = F_9 () ;
F_16 () ;
return V_62 ;
}
static void T_2 F_17 ( void )
{
F_13 () ;
}
