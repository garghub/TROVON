static int F_1 ( T_1 * V_1 ,
struct V_2 * V_3 ,
void * V_4 )
{
unsigned long V_5 ;
struct V_6 V_7 ;
unsigned V_8 ;
int V_9 ;
struct V_10 * V_11 ;
F_2 ( & V_12 ) ;
F_3 () ;
V_9 = F_4 () ;
V_11 = & V_13 [ V_9 ] . V_14 ;
do {
V_8 = F_5 ( V_11 ) ;
V_5 = F_6 ( V_15 ,
V_16 ,
V_17 ) ;
if ( V_5 != 0 ) {
F_7 ( L_1 , V_5 ) ;
F_8 ( & V_12 ) ;
F_9 () ;
return - V_18 ;
}
V_7 . V_19 = V_20 . V_21 ;
V_7 . V_22 = V_20 . V_23 ;
V_5 = F_10 ( V_11 , V_20 . V_24 ) ;
} while ( F_11 ( V_11 , V_8 ) );
F_9 () ;
V_3 -> V_25 = V_5 ;
V_3 -> V_26 = & V_27 ;
* V_1 = F_12 ( V_7 ) ;
F_8 ( & V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
return F_14 ( F_1 , NULL ,
NULL , V_31 ) ;
}
static int F_15 ( struct V_28 * V_29 , T_2 V_32 )
{
return - V_18 ;
}
static int F_16 ( struct V_28 * V_29 , T_3 V_33 )
{
return - V_18 ;
}
static int F_17 ( struct V_28 * V_29 ,
const struct V_6 * V_34 )
{
return - V_18 ;
}
static int F_18 ( struct V_28 * V_29 , struct V_6 * V_34 )
{
unsigned long V_5 ;
struct V_6 V_7 ;
F_2 ( & V_12 ) ;
V_5 = F_6 ( V_15 ,
V_16 ,
V_17 ) ;
if ( V_5 != 0 ) {
F_7 ( L_2 , V_5 ) ;
F_8 ( & V_12 ) ;
return - V_18 ;
}
V_7 . V_19 = V_20 . V_21 ;
V_7 . V_22 = V_20 . V_23 ;
F_8 ( & V_12 ) ;
memcpy ( V_34 , & V_7 , sizeof( struct V_6 ) ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_35 * V_36 , int V_37 )
{
return - V_18 ;
}
static void T_4 F_20 ( void )
{
F_21 ( V_38 . V_39 ) ;
}
static int T_5 F_22 ( void )
{
long V_5 ;
V_16 = F_23 ( & V_20 ) ;
V_13 = F_24 () ;
if ( ! V_13 )
return - V_40 ;
V_5 = F_6 ( V_15 , V_16 ,
V_17 ) ;
if ( V_5 == - V_41 || V_5 == - V_42 )
return - V_40 ;
V_38 . V_43 = V_44 ;
V_38 . V_39 = F_25 ( & V_38 . V_43 , NULL ) ;
return F_26 ( V_38 . V_39 ) ;
}
