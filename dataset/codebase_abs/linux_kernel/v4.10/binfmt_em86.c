static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 , * V_4 ;
char * V_5 ;
struct V_6 * V_6 ;
int V_7 ;
struct V_8 V_9 ;
V_9 = * ( (struct V_8 * ) V_2 -> V_10 ) ;
if ( memcmp ( V_9 . V_11 , V_12 , V_13 ) != 0 )
return - V_14 ;
if ( ( V_9 . V_15 != V_16 && V_9 . V_15 != V_17 ) ||
( ! ( ( V_9 . V_18 == V_19 ) || ( V_9 . V_18 == V_20 ) ) ) ||
! V_2 -> V_6 -> V_21 -> V_22 ) {
return - V_14 ;
}
if ( V_2 -> V_23 & V_24 )
return - V_25 ;
F_2 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_5 = V_26 ;
V_3 = V_27 ;
V_4 = NULL ;
F_4 ( V_2 ) ;
V_7 = F_5 ( 1 , & V_2 -> V_28 , V_2 ) ;
if ( V_7 < 0 ) return V_7 ;
V_2 -> V_29 ++ ;
if ( V_4 ) {
V_7 = F_5 ( 1 , & V_4 , V_2 ) ;
if ( V_7 < 0 ) return V_7 ;
V_2 -> V_29 ++ ;
}
V_7 = F_5 ( 1 , & V_3 , V_2 ) ;
if ( V_7 < 0 ) return V_7 ;
V_2 -> V_29 ++ ;
V_6 = F_6 ( V_5 ) ;
if ( F_7 ( V_6 ) )
return F_8 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_10 ( V_2 ) ;
}
static int T_1 F_11 ( void )
{
F_12 ( & V_30 ) ;
return 0 ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_30 ) ;
}
