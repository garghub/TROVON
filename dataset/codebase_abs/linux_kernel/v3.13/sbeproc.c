void F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 ) {
char V_3 [ 7 + V_4 + 1 ] ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_1 -> V_5 ) ;
F_2 ( L_2 , V_1 -> V_2 ) ;
F_2 ( V_3 , NULL ) ;
V_1 -> V_2 = NULL ;
}
}
static void F_3 ( T_1 * V_1 , struct V_6 * V_7 )
{
T_2 * V_8 = & V_9 [ V_1 -> V_10 ] ;
T_3 * V_11 = NULL ;
switch ( V_8 -> V_12 )
{
case V_13 :
V_11 = ( T_3 * ) V_8 -> V_14 . V_15 . V_16 ;
break;
case V_17 :
V_11 = ( T_3 * ) V_8 -> V_14 . V_18 . V_16 ;
break;
}
F_4 ( V_1 , V_7 , V_11 ) ;
F_5 ( L_3 ,
V_7 -> V_19 , V_7 -> V_19 ,
V_7 -> V_20 , V_7 -> V_20 ) ;
}
static int F_6 ( struct V_21 * V_22 , void * V_23 )
{
T_1 * V_1 = V_22 -> V_24 ;
char * V_25 ;
struct V_6 * V_7 ;
if ( ! ( V_7 = F_7 ( sizeof( struct V_6 ) ) ) )
return - V_26 ;
F_5 ( L_4 ) ;
F_3 ( V_1 , V_7 ) ;
F_8 ( V_22 , L_5 ) ;
switch ( V_7 -> V_27 ) {
case F_9 ( V_28 , V_29 ) :
F_8 ( V_22 , L_6 ) ;
break;
case F_9 ( V_28 , V_30 ) :
F_8 ( V_22 , L_7 ) ;
break;
case F_9 ( V_28 , V_31 ) :
F_8 ( V_22 , L_8 ) ;
break;
case F_9 ( V_28 , V_32 ) :
F_8 ( V_22 , L_9 ) ;
break;
case F_9 ( V_28 , V_33 ) :
case F_9 ( V_28 , V_34 ) :
F_8 ( V_22 , L_10 ) ;
break;
case F_9 ( V_28 , V_35 ) :
case F_9 ( V_28 , V_36 ) :
F_8 ( V_22 , L_11 ) ;
break;
case F_9 ( V_28 , V_37 ) :
case F_9 ( V_28 , V_38 ) :
F_8 ( V_22 , L_12 ) ;
break;
case F_9 ( V_28 , V_39 ) :
F_8 ( V_22 , L_13 ) ;
break;
case F_9 ( V_28 , V_40 ) :
F_8 ( V_22 , L_14 ) ;
break;
case F_9 ( V_28 , V_41 ) :
F_8 ( V_22 , L_15 ) ;
break;
default:
F_8 ( V_22 , L_16 ) ;
break;
}
F_10 ( V_22 , L_17 , V_7 -> V_27 ) ;
F_10 ( V_22 , L_18 , V_7 -> V_10 ) ;
F_10 ( V_22 , L_19 , V_1 -> V_42 ) ;
F_10 ( V_22 , L_20 , V_7 -> V_43 ) ;
F_10 ( V_22 , L_21 , V_7 -> V_44 ) ;
F_10 ( V_22 , L_22 , V_1 -> V_45 ) ;
F_10 ( V_22 , L_23 , V_7 -> V_46 ) ;
#if 1
F_10 ( V_22 , L_24 ,
V_7 -> V_19 , V_7 -> V_20 ) ;
#else
F_10 ( V_22 , L_25 ,
V_7 -> V_19 , V_7 -> V_20 ) ;
#endif
switch ( V_7 -> V_47 ) {
case V_48 :
V_25 = L_26 ;
break;
case V_49 :
V_25 = L_27 ;
break;
default:
V_25 = L_28 ;
break;
}
F_10 ( V_22 , L_29 , V_25 ) ;
F_10 ( V_22 , L_30 , V_1 -> V_50 ) ;
#ifdef F_11
{
extern int V_51 ;
#if 0
extern int max_chans_used;
extern int cxt1e1_max_mtu;
#endif
extern int V_52 , V_53 ;
F_10 ( V_22 , L_31 , V_51 ) ;
#if 0
seq_printf(m, "\nmax_chans_used: %d\n", max_chans_used);
seq_printf(m, "cxt1e1_max_mtu: %d\n", cxt1e1_max_mtu);
#endif
F_10 ( V_22 , L_32 , V_52 ) ;
F_10 ( V_22 , L_33 , V_53 ) ;
}
#endif
F_12 ( V_7 ) ;
F_5 ( L_34 ) ;
return 0 ;
}
static int F_13 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_14 ( V_55 , F_6 , F_15 ( V_54 ) ) ;
}
int T_4 F_16 ( T_1 * V_1 )
{
char V_3 [ 7 + V_4 + 1 ] ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_1 -> V_5 ) ;
V_1 -> V_2 = F_17 ( V_3 , NULL ) ;
if ( ! V_1 -> V_2 ) {
F_18 ( L_35 , V_1 -> V_5 ) ;
goto V_56;
}
if ( ! F_19 ( L_2 , V_57 | V_58 , V_1 -> V_2 ,
& V_59 , V_1 ) ) {
F_18 ( L_36 , V_1 -> V_5 ) ;
goto V_56;
}
return 0 ;
V_56:
F_1 ( V_1 ) ;
return 1 ;
}
