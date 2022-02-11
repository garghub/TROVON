static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 =
F_2 ( & V_2 -> V_8 [ V_5 ] ) ;
struct V_9 V_10 , V_11 , V_12 ;
T_1 V_13 ;
int V_14 ;
int V_15 = F_3 () ;
F_4 ( & V_10 ) ;
F_5 () ;
F_6 () ;
V_13 = F_7 ( V_16 ) ;
if ( V_13 != V_17 ) {
V_5 = V_4 -> V_18 ;
V_7 = F_2 ( & V_2 -> V_8 [ V_5 ] ) ;
}
if ( V_5 > 0 )
F_8 ( V_19 , & V_15 ) ;
if ( V_7 -> V_20 == V_17 )
F_9 () ;
F_10 ( V_21 , V_7 -> V_22 ) ;
F_11 ( V_21 , V_7 -> V_23 ) ;
if ( ( V_7 -> V_23 == V_24 ) &&
( V_7 -> V_22 == V_17 ) )
F_12 () ;
F_13 ( V_2 -> V_25 , V_7 -> V_20 ) ;
if ( F_14 ( V_26 ) == V_17 )
F_15 () ;
if ( F_16 () )
F_17 () ;
if ( V_5 > 0 )
F_8 ( V_27 , & V_15 ) ;
F_4 ( & V_11 ) ;
V_12 = F_18 ( V_11 , V_10 ) ;
F_19 () ;
F_20 () ;
V_14 = V_12 . V_28 / V_29 + V_12 . V_30 * \
V_31 ;
V_2 -> V_32 = V_14 ;
return V_5 ;
}
static inline void F_21 ( struct V_3 * V_4 ,
int V_33 , const char * V_34 )
{
struct V_35 * V_36 = & V_4 -> V_37 [ V_33 ] ;
V_36 -> V_38 = V_39 [ V_33 ] . V_38 ;
V_36 -> V_40 = V_39 [ V_33 ] . V_40 ;
V_36 -> V_41 = V_42 ;
V_36 -> V_43 = F_1 ;
sprintf ( V_36 -> V_44 , L_1 , V_33 + 1 ) ;
strncpy ( V_36 -> V_45 , V_34 , V_46 ) ;
}
static inline struct V_6 * F_22 (
struct V_1 * V_2 ,
int V_33 )
{
struct V_6 * V_7 = & V_47 [ V_33 ] ;
struct V_48 * V_49 = & V_2 -> V_8 [ V_33 ] ;
V_7 -> V_50 = V_39 [ V_33 ] . V_50 ;
F_23 ( V_49 , V_7 ) ;
return V_7 ;
}
int T_2 F_24 ( void )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_51 ;
unsigned int V_15 = 0 ;
V_21 = F_25 ( L_2 ) ;
V_26 = F_25 ( L_3 ) ;
V_16 = F_25 ( L_4 ) ;
if ( ( ! V_21 ) || ( ! V_26 ) || ( ! V_16 ) )
return - V_52 ;
V_4 -> V_18 = - 1 ;
V_2 = & F_26 ( V_53 , V_15 ) ;
V_2 -> V_25 = V_15 ;
F_21 ( V_4 , 0 , L_5 ) ;
V_4 -> V_18 = 0 ;
V_7 = F_22 ( V_2 , 0 ) ;
V_7 -> V_50 = 1 ;
V_7 -> V_20 = V_54 ;
V_7 -> V_23 = V_54 ;
V_7 -> V_22 = V_24 ;
F_21 ( V_4 , 1 , L_6 ) ;
V_7 = F_22 ( V_2 , 1 ) ;
V_7 -> V_20 = V_17 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_22 = V_24 ;
F_21 ( V_4 , 2 , L_7 ) ;
V_7 = F_22 ( V_2 , 2 ) ;
V_7 -> V_20 = V_17 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_22 = V_17 ;
V_4 -> V_55 = V_56 ;
F_27 ( & V_51 ) ;
V_2 -> V_55 = V_56 ;
if ( F_28 ( V_2 ) ) {
F_29 ( L_8 , V_57 ) ;
return - V_58 ;
}
return 0 ;
}
int T_2 F_24 ( void )
{
return 0 ;
}
