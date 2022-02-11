static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 / 4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 / 4 ) ;
}
static int F_5 ( unsigned int V_6 , unsigned int V_7 ,
unsigned int V_8 , unsigned int V_9 ,
unsigned int V_10 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_6 >= V_12 -> V_13 . V_14 )
return 1 ;
V_7 >>= 8 ;
V_8 >>= 8 ;
V_9 >>= 8 ;
F_6 () ;
F_1 ( V_2 , V_15 , V_6 ) ;
F_1 ( V_2 , V_16 , 0x00 ) ;
F_7 () ;
F_1 ( V_2 , V_17 , V_7 ) ;
F_7 () ;
F_1 ( V_2 , V_17 , V_8 ) ;
F_7 () ;
F_1 ( V_2 , V_17 , V_9 ) ;
return 0 ;
}
static void T_2 F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_6 () ;
F_1 ( V_2 , V_15 , 0x00 ) ;
F_1 ( V_2 , V_16 , 0x03 ) ;
F_7 () ;
F_1 ( V_2 , V_18 , 0x00 ) ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_10 ( V_20 ) ;
T_3 V_23 , V_14 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_24 ;
V_12 = F_11 ( sizeof( struct V_1 ) , V_20 ) ;
if ( ! V_12 ) {
F_12 ( V_25 L_1 , F_13 ( V_20 ) ) ;
return - V_26 ;
}
V_2 = V_12 -> V_2 ;
F_14 ( V_20 , V_12 ) ;
if ( F_15 ( & V_12 -> V_13 , 256 , 0 ) < 0 ) {
F_12 ( V_25 L_2 ,
F_13 ( V_20 ) ) ;
V_24 = - V_26 ;
goto V_27;
}
V_12 -> V_28 = & V_29 ;
V_12 -> V_30 = V_31 ;
V_12 -> V_32 = V_33 ;
V_12 -> V_34 = V_35 ;
V_23 = V_22 -> V_36 . V_23 ;
V_14 = V_22 -> V_36 . V_37 - V_23 + 1 ;
if ( ! F_16 ( V_23 , V_14 , F_13 ( V_20 ) ) ) {
F_12 ( V_25 L_3 ,
F_13 ( V_20 ) ) ;
V_24 = - V_38 ;
goto V_39;
}
V_12 -> V_30 . V_40 = V_23 ;
V_2 -> V_41 = F_17 ( V_12 -> V_30 . V_40 , V_12 -> V_30 . V_42 ) ;
if ( ! V_2 -> V_41 ) {
F_12 ( V_25 L_4 , F_13 ( V_20 ) ) ;
V_24 = - V_26 ;
goto V_43;
}
V_2 -> V_5 = V_2 -> V_41 + V_44 ;
V_12 -> V_30 . V_45 = V_23 + V_46 ;
V_12 -> V_47 = F_17 ( V_12 -> V_30 . V_45 ,
V_12 -> V_30 . V_48 ) ;
if ( ! V_12 -> V_47 ) {
F_12 ( V_25 L_5 , F_13 ( V_20 ) ) ;
V_24 = - V_26 ;
goto V_49;
}
V_12 -> V_50 = V_12 -> V_30 . V_48 ;
F_8 ( V_12 ) ;
V_24 = F_18 ( V_12 ) ;
if ( V_24 < 0 ) {
F_12 ( V_25 L_6 ,
F_13 ( V_20 ) ) ;
goto V_51;
}
F_19 ( V_20 ) ;
F_20 ( L_7 ,
V_12 -> V_52 , V_12 -> V_30 . V_53 , F_13 ( V_20 ) ) ;
return 0 ;
V_51:
F_21 ( V_12 -> V_47 ) ;
V_49:
F_21 ( V_2 -> V_41 ) ;
V_43:
F_22 ( V_23 , V_14 ) ;
V_39:
F_23 ( & V_12 -> V_13 ) ;
V_27:
F_24 ( V_12 ) ;
return V_24 ;
}
static int T_4 F_25 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_10 ( V_20 ) ;
struct V_11 * V_12 = F_26 ( V_20 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
T_3 V_23 , V_14 ;
F_27 ( V_20 ) ;
F_28 ( V_12 ) ;
F_21 ( V_12 -> V_47 ) ;
F_21 ( V_2 -> V_41 ) ;
V_23 = V_22 -> V_36 . V_23 ;
V_14 = V_22 -> V_36 . V_37 - V_23 + 1 ;
F_22 ( V_23 , V_14 ) ;
F_23 ( & V_12 -> V_13 ) ;
F_24 ( V_12 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
#ifndef F_30
if ( F_31 ( L_8 , NULL ) )
return - V_54 ;
#endif
return F_32 ( & V_55 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_55 ) ;
}
