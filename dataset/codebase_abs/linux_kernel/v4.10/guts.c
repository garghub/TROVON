static const struct V_1 * F_1 (
T_1 V_2 , const struct V_1 * V_3 )
{
while ( V_3 -> V_2 ) {
if ( V_3 -> V_2 == ( V_2 & V_3 -> V_4 ) )
return V_3 ;
V_3 ++ ;
} ;
return NULL ;
}
T_1 F_2 ( void )
{
T_1 V_2 = 0 ;
if ( ! V_5 || ! V_5 -> V_6 )
return V_2 ;
if ( V_5 -> V_7 )
V_2 = F_3 ( & V_5 -> V_6 -> V_2 ) ;
else
V_2 = F_4 ( & V_5 -> V_6 -> V_2 ) ;
return V_2 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 , * V_12 = V_9 -> V_13 . V_14 ;
struct V_15 * V_13 = & V_9 -> V_13 ;
struct V_16 * V_17 ;
const struct V_1 * V_18 ;
const char * V_19 ;
T_1 V_2 ;
V_5 = F_6 ( V_13 , sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return - V_21 ;
V_5 -> V_7 = F_7 ( V_12 , L_1 ) ;
V_17 = F_8 ( V_9 , V_22 , 0 ) ;
V_5 -> V_6 = F_9 ( V_13 , V_17 ) ;
if ( F_10 ( V_5 -> V_6 ) )
return F_11 ( V_5 -> V_6 ) ;
V_11 = F_12 ( L_2 ) ;
if ( F_13 ( V_11 , L_3 , & V_19 ) )
F_14 ( V_11 , L_4 , 0 , & V_19 ) ;
F_15 ( V_11 ) ;
if ( V_19 )
V_23 . V_19 = F_16 ( V_13 , V_19 , V_20 ) ;
V_2 = F_2 () ;
V_18 = F_1 ( V_2 , V_24 ) ;
if ( V_18 ) {
V_23 . V_25 = F_17 ( V_13 , V_20 ,
L_5 , V_18 -> V_26 ) ;
} else {
V_23 . V_25 = F_17 ( V_13 , V_20 , L_6 ) ;
}
V_23 . V_27 = F_17 ( V_13 , V_20 ,
L_7 , V_2 ) ;
V_23 . V_28 = F_17 ( V_13 , V_20 , L_8 ,
( V_2 >> 4 ) & 0xf , V_2 & 0xf ) ;
V_29 = F_18 ( & V_23 ) ;
if ( F_10 ( V_29 ) )
return F_11 ( V_29 ) ;
F_19 ( L_9 , V_23 . V_19 ) ;
F_19 ( L_10 , V_23 . V_25 ) ;
F_19 ( L_11 ,
V_23 . V_27 , V_23 . V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_8 * V_13 )
{
F_21 ( V_29 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_30 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_30 ) ;
}
