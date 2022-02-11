static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
static struct V_5 V_7 = {} ;
if ( ! V_6 ) {
#ifdef F_3
if ( V_4 -> V_8 )
V_6 = & V_7 ;
#endif
#ifdef F_4
if ( V_4 -> V_9 )
V_6 = & V_7 ;
#endif
}
if ( V_6 ) {
F_5 ( V_2 , L_1
L_2 ,
V_4 -> V_10 , V_6 -> V_11 , V_6 -> V_12 . V_12 ,
V_6 -> V_12 . V_13 & V_14
? '.' : ' ' ,
( ( V_15 ) V_6 -> V_12 . V_16 ) -
( ( V_6 -> V_12 . V_13 & V_17 ) ? 0x100 : 0 ) ,
V_6 -> V_12 . V_13 & V_18
? '.' : ' ' ,
( ( V_15 ) V_6 -> V_12 . V_19 ) -
( ( V_6 -> V_12 . V_13 & V_17 ) ? 0x100 : 0 ) ,
V_6 -> V_12 . V_13 & V_20
? '.' : ' ' ,
V_6 -> V_21 . V_22 , V_6 -> V_21 . V_23 ,
V_6 -> V_21 . V_24 , V_6 -> V_21 . V_25 ,
V_6 -> V_21 . V_26 , V_6 -> V_27 . V_28 ) ;
if ( V_6 != & V_7 )
V_6 -> V_12 . V_13 &= ~ V_29 ;
}
}
static int F_6 ( struct V_1 * V_2 , void * V_30 )
{
F_7 () ;
if ( V_30 == V_31 )
F_5 ( V_2 , L_3
L_4
L_5
L_6 ,
V_32 ) ;
else
F_1 ( V_2 , V_30 ) ;
return 0 ;
}
static void * F_8 ( struct V_1 * V_2 , T_1 * V_33 )
{
struct V_34 * V_34 = F_9 ( V_2 ) ;
T_1 V_35 ;
struct V_3 * V_4 ;
F_10 () ;
if ( ! * V_33 )
return V_31 ;
V_35 = 1 ;
F_11 (net, dev)
if ( V_35 ++ == * V_33 )
return V_4 ;
return NULL ;
}
static void * F_12 ( struct V_1 * V_2 , void * V_30 , T_1 * V_33 )
{
struct V_34 * V_34 = F_9 ( V_2 ) ;
++ * V_33 ;
return V_30 == V_31 ?
F_13 ( V_34 ) : F_14 ( V_30 ) ;
}
static void F_15 ( struct V_1 * V_2 , void * V_30 )
{
F_16 () ;
}
static int F_17 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
return F_18 ( V_36 , V_37 , & V_38 ,
sizeof( struct V_39 ) ) ;
}
int T_2 F_19 ( struct V_34 * V_34 )
{
if ( ! F_20 ( V_34 , L_7 , V_40 , & V_41 ) )
return - V_42 ;
return 0 ;
}
void T_3 F_21 ( struct V_34 * V_34 )
{
F_22 ( V_34 , L_7 ) ;
}
