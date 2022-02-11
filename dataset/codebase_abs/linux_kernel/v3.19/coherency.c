int F_1 ( void )
{
if ( ! V_1 ) {
F_2 ( L_1 ) ;
F_2 ( L_2 ) ;
return 1 ;
}
F_3 () ;
return F_4 () ;
}
static inline void F_5 ( void )
{
F_6 ( 0x1 , V_2 + V_3 ) ;
while ( F_7 ( V_2 + V_3 ) & 0x1 ) ;
}
static T_1 F_8 ( struct V_4 * V_5 , struct V_6 * V_6 ,
unsigned long V_7 , T_2 V_8 ,
enum V_9 V_10 ,
struct V_11 * V_12 )
{
if ( V_10 != V_13 )
F_5 () ;
return F_9 ( V_5 , F_10 ( V_6 ) ) + V_7 ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_14 ,
T_2 V_8 , enum V_9 V_10 ,
struct V_11 * V_12 )
{
if ( V_10 != V_13 )
F_5 () ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_14 ,
T_2 V_8 , enum V_9 V_10 )
{
if ( V_10 != V_13 )
F_5 () ;
}
static int F_13 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
struct V_4 * V_5 = V_18 ;
if ( V_17 != V_19 )
return V_20 ;
F_14 ( V_5 , & V_21 ) ;
return V_22 ;
}
static void T_3 F_15 ( struct V_23 * V_24 )
{
struct V_25 V_26 ;
F_16 ( V_24 , 0 , & V_26 ) ;
V_27 = V_26 . V_28 ;
F_17 ( & V_27 ) ;
V_1 = F_18 ( V_24 , 0 ) ;
V_2 = F_18 ( V_24 , 1 ) ;
F_1 () ;
}
static void T_4 *
F_19 ( T_5 V_29 , T_2 V_8 ,
unsigned int V_30 , void * V_31 )
{
struct V_25 V_32 ;
F_20 ( & V_32 ) ;
if ( V_32 . V_28 <= V_29 && ( V_29 + V_8 ) <= V_32 . V_33 )
V_30 = V_34 ;
return F_21 ( V_29 , V_8 , V_30 , V_31 ) ;
}
static void T_3 F_22 ( struct V_23 * V_24 )
{
struct V_23 * V_35 ;
V_2 = F_18 ( V_24 , 0 ) ;
V_36 = F_19 ;
if ( ! F_23 () )
return;
F_24 (cache_dn, NULL, L_3 ) {
struct V_37 * V_38 ;
V_38 = F_25 ( sizeof( * V_38 ) , V_39 ) ;
V_38 -> V_40 = F_26 ( L_4 , V_39 ) ;
F_27 ( V_35 , V_38 ) ;
}
}
static int F_28 ( void )
{
struct V_23 * V_24 ;
const struct V_41 * V_42 ;
int type ;
if ( ! F_29 () )
return V_43 ;
V_24 = F_30 ( NULL , V_44 , & V_42 ) ;
if ( ! V_24 )
return V_43 ;
type = ( int ) V_42 -> V_45 ;
F_31 ( V_24 ) ;
return type ;
}
int F_23 ( void )
{
return false ;
}
int T_3 F_32 ( void )
{
int type = F_28 () ;
struct V_23 * V_24 ;
V_24 = F_33 ( NULL , V_44 ) ;
if ( type == V_46 )
F_15 ( V_24 ) ;
else if ( type == V_47 ||
type == V_48 )
F_22 ( V_24 ) ;
F_31 ( V_24 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
if ( F_23 () )
F_35 ( & V_49 ,
& V_50 ) ;
return 0 ;
}
static int T_3 F_36 ( void )
{
if ( F_23 () )
F_35 ( & V_51 ,
& V_52 ) ;
return 0 ;
}
