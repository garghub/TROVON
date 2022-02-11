static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 =
F_2 ( & V_2 -> V_8 [ V_5 ] ) ;
T_1 V_9 ;
int V_10 = F_3 () ;
F_4 () ;
V_9 = F_5 ( V_11 ) ;
if ( V_9 != V_12 ) {
V_5 = V_4 -> V_13 ;
V_7 = F_2 ( & V_2 -> V_8 [ V_5 ] ) ;
}
if ( V_5 > 0 )
F_6 ( V_14 , & V_10 ) ;
if ( V_7 -> V_15 == V_12 )
F_7 () ;
F_8 ( V_16 , V_7 -> V_17 ) ;
F_9 ( V_16 , V_7 -> V_18 ) ;
if ( ( V_7 -> V_18 == V_19 ) &&
( V_7 -> V_17 == V_12 ) )
F_10 () ;
F_11 ( V_2 -> V_20 , V_7 -> V_15 ) ;
if ( F_12 ( V_21 ) == V_12 )
F_13 () ;
if ( F_14 () )
F_15 () ;
if ( V_5 > 0 )
F_6 ( V_22 , & V_10 ) ;
F_16 () ;
return V_5 ;
}
static inline void F_17 ( struct V_3 * V_4 ,
int V_23 , const char * V_24 )
{
struct V_25 * V_26 = & V_4 -> V_27 [ V_23 ] ;
V_26 -> V_28 = V_29 [ V_23 ] . V_28 ;
V_26 -> V_30 = V_29 [ V_23 ] . V_30 ;
V_26 -> V_31 = V_32 ;
V_26 -> V_33 = F_1 ;
sprintf ( V_26 -> V_34 , L_1 , V_23 + 1 ) ;
strncpy ( V_26 -> V_35 , V_24 , V_36 ) ;
}
static inline struct V_6 * F_18 (
struct V_1 * V_2 ,
int V_23 )
{
struct V_6 * V_7 = & V_37 [ V_23 ] ;
struct V_38 * V_39 = & V_2 -> V_8 [ V_23 ] ;
V_7 -> V_40 = V_29 [ V_23 ] . V_40 ;
F_19 ( V_39 , V_7 ) ;
return V_7 ;
}
int T_2 F_20 ( void )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_41 ;
unsigned int V_10 = 0 ;
V_16 = F_21 ( L_2 ) ;
V_21 = F_21 ( L_3 ) ;
V_11 = F_21 ( L_4 ) ;
if ( ( ! V_16 ) || ( ! V_21 ) || ( ! V_11 ) )
return - V_42 ;
V_4 -> V_13 = - 1 ;
V_2 = & F_22 ( V_43 , V_10 ) ;
V_2 -> V_20 = V_10 ;
F_17 ( V_4 , 0 , L_5 ) ;
V_4 -> V_13 = 0 ;
V_7 = F_18 ( V_2 , 0 ) ;
V_7 -> V_40 = 1 ;
V_7 -> V_15 = V_44 ;
V_7 -> V_18 = V_44 ;
V_7 -> V_17 = V_19 ;
F_17 ( V_4 , 1 , L_6 ) ;
V_7 = F_18 ( V_2 , 1 ) ;
V_7 -> V_15 = V_12 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_17 = V_19 ;
F_17 ( V_4 , 2 , L_7 ) ;
V_7 = F_18 ( V_2 , 2 ) ;
V_7 -> V_15 = V_12 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_17 = V_12 ;
V_4 -> V_45 = V_46 ;
F_23 ( & V_41 ) ;
V_2 -> V_45 = V_46 ;
if ( F_24 ( V_2 ) ) {
F_25 ( L_8 , V_47 ) ;
return - V_48 ;
}
return 0 ;
}
int T_2 F_20 ( void )
{
return 0 ;
}
