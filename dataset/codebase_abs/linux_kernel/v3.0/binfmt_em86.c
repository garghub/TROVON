static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_5 , * V_6 , * V_7 ;
struct V_8 * V_8 ;
int V_9 ;
struct V_10 V_11 ;
V_11 = * ( (struct V_10 * ) V_2 -> V_12 ) ;
if ( memcmp ( V_11 . V_13 , V_14 , V_15 ) != 0 )
return - V_16 ;
if ( ( V_11 . V_17 != V_18 && V_11 . V_17 != V_19 ) ||
( ! ( ( V_11 . V_20 == V_21 ) || ( V_11 . V_20 == V_22 ) ) ) ||
( ! V_2 -> V_8 -> V_23 || ! V_2 -> V_8 -> V_23 -> V_24 ) ) {
return - V_16 ;
}
V_2 -> V_25 ++ ;
F_2 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_5 = V_26 ;
V_6 = V_27 ;
V_7 = NULL ;
F_4 ( V_2 ) ;
V_9 = F_5 ( 1 , & V_2 -> V_28 , V_2 ) ;
if ( V_9 < 0 ) return V_9 ;
V_2 -> V_29 ++ ;
if ( V_7 ) {
V_9 = F_5 ( 1 , & V_7 , V_2 ) ;
if ( V_9 < 0 ) return V_9 ;
V_2 -> V_29 ++ ;
}
V_9 = F_5 ( 1 , & V_6 , V_2 ) ;
if ( V_9 < 0 ) return V_9 ;
V_2 -> V_29 ++ ;
V_8 = F_6 ( V_5 ) ;
if ( F_7 ( V_8 ) )
return F_8 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_10 ( V_2 , V_4 ) ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_30 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_30 ) ;
}
