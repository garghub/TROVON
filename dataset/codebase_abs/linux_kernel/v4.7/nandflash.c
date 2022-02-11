static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
unsigned long V_5 ;
T_1 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( V_5 ) ;
if ( V_4 & V_9 ) {
V_6 = F_4 ( V_10 , V_11 , V_12 ) ;
V_6 . V_13 = ( V_4 & V_14 ) ? 0 : 1 ;
#if ! V_15
if ( V_4 & V_16 ) {
V_8 -> V_17 = ( void V_18 * ) F_5 ( V_10 ,
V_11 , V_19 ) ;
} else if ( V_4 & V_20 ) {
V_8 -> V_17 = ( void V_18 * ) F_5 ( V_10 ,
V_11 , V_21 ) ;
} else {
V_8 -> V_17 = ( void V_18 * ) F_5 ( V_10 ,
V_11 , V_22 ) ;
}
#else
V_6 . V_23 = ( V_4 & V_20 ) ? 1 : 0 ;
V_6 . V_24 = ( V_4 & V_16 ) ? 1 : 0 ;
#endif
F_6 ( V_10 , V_11 , V_12 , V_6 ) ;
}
if ( V_3 != V_25 )
F_7 ( V_3 , V_8 -> V_17 ) ;
F_8 ( V_5 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_26 = F_4 ( V_10 , V_11 , V_27 ) ;
return V_26 . V_28 ;
}
struct V_1 * T_3 F_10 ( void )
{
void V_18 * V_29 ;
void V_18 * V_30 ;
struct V_31 * V_32 ;
struct V_7 * V_8 ;
int V_33 = 0 ;
T_4 V_34 = {
. V_13 = V_35 ,
#if V_15
. V_24 = V_35 ,
. V_23 = V_35
#endif
} ;
T_5 V_36 = {
. V_13 = V_35 ,
#if V_15
. V_24 = V_35 ,
. V_23 = V_35
#endif
} ;
T_1 V_6 = { . V_13 = 1 } ;
F_11 ( V_37 ) ;
F_6 ( V_10 , V_11 , V_38 , V_34 ) ;
F_6 ( V_10 , V_11 , V_12 , V_6 ) ;
F_6 ( V_10 , V_11 , V_39 , V_36 ) ;
V_32 = F_12 ( sizeof( struct V_31 ) , V_40 ) ;
if ( ! V_32 ) {
F_13 ( V_41 L_1
L_2 ) ;
V_33 = - V_42 ;
return NULL ;
}
V_29 = V_30 = ( void V_18 * ) F_5 ( V_10 , V_11 ,
V_22 ) ;
V_8 = & V_32 -> V_43 ;
V_44 = F_14 ( V_8 ) ;
V_8 -> V_45 = V_29 ;
V_8 -> V_17 = V_30 ;
V_8 -> V_46 = F_1 ;
V_8 -> V_47 = F_9 ;
V_8 -> V_48 = 20 ;
V_8 -> V_49 . V_50 = V_51 ;
V_8 -> V_49 . V_52 = V_53 ;
if ( F_15 ( V_44 , 1 ) ) {
V_33 = - V_54 ;
goto V_55;
}
return V_44 ;
V_55:
F_16 ( V_32 ) ;
return NULL ;
}
