static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
unsigned long V_5 ;
T_1 V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
F_2 ( V_5 ) ;
if ( V_4 & V_10 ) {
V_6 = F_3 ( V_11 , V_12 , V_13 ) ;
V_6 . V_14 = ( V_4 & V_15 ) ? 0 : 1 ;
#if ! V_16
if ( V_4 & V_17 ) {
V_8 -> V_18 = ( void V_19 * ) F_4 ( V_11 ,
V_12 , V_20 ) ;
} else if ( V_4 & V_21 ) {
V_8 -> V_18 = ( void V_19 * ) F_4 ( V_11 ,
V_12 , V_22 ) ;
} else {
V_8 -> V_18 = ( void V_19 * ) F_4 ( V_11 ,
V_12 , V_23 ) ;
}
#else
V_6 . V_24 = ( V_4 & V_21 ) ? 1 : 0 ;
V_6 . V_25 = ( V_4 & V_17 ) ? 1 : 0 ;
#endif
F_5 ( V_11 , V_12 , V_13 , V_6 ) ;
}
if ( V_3 != V_26 )
F_6 ( V_3 , V_8 -> V_18 ) ;
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_2 V_27 = F_3 ( V_11 , V_12 , V_28 ) ;
return V_27 . V_29 ;
}
struct V_1 * T_3 F_9 ( void )
{
void V_19 * V_30 ;
void V_19 * V_31 ;
struct V_32 * V_33 ;
struct V_7 * V_8 ;
int V_34 = 0 ;
T_4 V_35 = {
. V_14 = V_36 ,
#if V_16
. V_25 = V_36 ,
. V_24 = V_36
#endif
} ;
T_5 V_37 = {
. V_14 = V_36 ,
#if V_16
. V_25 = V_36 ,
. V_24 = V_36
#endif
} ;
T_1 V_6 = { . V_14 = 1 } ;
F_10 ( V_38 ) ;
F_5 ( V_11 , V_12 , V_39 , V_35 ) ;
F_5 ( V_11 , V_12 , V_13 , V_6 ) ;
F_5 ( V_11 , V_12 , V_40 , V_37 ) ;
V_33 = F_11 ( sizeof( struct V_32 ) , V_41 ) ;
if ( ! V_33 ) {
F_12 ( V_42 L_1
L_2 ) ;
V_34 = - V_43 ;
return NULL ;
}
V_30 = V_31 = ( void V_19 * ) F_4 ( V_11 , V_12 ,
V_23 ) ;
V_8 = & V_33 -> V_44 ;
V_45 = & V_33 -> V_46 ;
V_45 -> V_9 = V_8 ;
V_8 -> V_47 = V_30 ;
V_8 -> V_18 = V_31 ;
V_8 -> V_48 = F_1 ;
V_8 -> V_49 = F_8 ;
V_8 -> V_50 = 20 ;
V_8 -> V_51 . V_52 = V_53 ;
if ( F_13 ( V_45 , 1 ) ) {
V_34 = - V_54 ;
goto V_55;
}
return V_45 ;
V_55:
F_14 ( V_33 ) ;
return NULL ;
}
