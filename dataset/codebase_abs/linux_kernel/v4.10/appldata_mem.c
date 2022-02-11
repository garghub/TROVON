static void F_1 ( void * V_1 )
{
static struct V_2 V_3 ;
unsigned long V_4 [ V_5 ] ;
struct V_6 * V_7 ;
V_7 = V_1 ;
V_7 -> V_8 ++ ;
F_2 ( V_4 ) ;
V_7 -> V_9 = V_4 [ V_10 ] >> 1 ;
V_7 -> V_11 = V_4 [ V_12 ] >> 1 ;
V_7 -> V_13 = V_4 [ V_14 ] ;
V_7 -> V_15 = V_4 [ V_16 ] ;
V_7 -> V_17 = V_4 [ V_18 ] ;
V_7 -> V_17 += V_4 [ V_19 ] ;
V_7 -> V_20 = V_4 [ V_21 ] ;
V_7 -> V_22 = V_4 [ V_23 ] ;
F_3 ( & V_3 ) ;
V_7 -> V_24 = V_3 . V_24 ;
V_7 -> V_25 = F_4 ( V_3 . V_25 ) ;
V_7 -> V_26 = F_4 ( V_3 . V_26 ) ;
V_7 -> V_27 = F_4 ( V_3 . V_27 ) ;
V_7 -> V_28 = F_4 ( V_3 . V_28 ) ;
V_7 -> V_29 = F_4 ( V_3 . V_29 ) ;
V_7 -> V_30 = F_4 ( F_5 ( V_31 )
- V_3 . V_29 ) ;
F_6 ( & V_3 ) ;
V_7 -> V_32 = F_4 ( V_3 . V_32 ) ;
V_7 -> V_33 = F_4 ( V_3 . V_33 ) ;
V_7 -> V_34 = F_7 () ;
V_7 -> V_35 ++ ;
}
static int T_1 F_8 ( void )
{
int V_36 ;
V_37 . V_1 = F_9 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_37 . V_1 )
return - V_39 ;
V_36 = F_10 ( & V_37 ) ;
if ( V_36 )
F_11 ( V_37 . V_1 ) ;
return V_36 ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_37 ) ;
F_11 ( V_37 . V_1 ) ;
}
