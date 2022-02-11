T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
void F_4 ( T_1 V_3 , T_2 V_1 , T_3 V_2 )
{
F_5 ( V_3 , F_3 ( V_1 , V_2 ) ) ;
}
T_1 F_6 ( T_1 V_4 , T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_1 , V_2 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_4 ( V_6 , V_1 , V_2 ) ;
return V_6 ;
}
T_1 F_7 ( T_4 V_7 )
{
struct V_8 * V_9 = & V_8 [ V_7 ] ;
T_1 V_10 ;
V_10 = F_8 ( V_11 ,
V_12 ,
V_9 -> V_13 ) ;
return V_10 & V_9 -> V_14 ;
}
void F_9 ( T_4 V_7 )
{
struct V_8 * V_9 = & V_8 [ V_7 ] ;
F_10 ( V_9 -> V_14 ,
V_11 ,
V_12 ,
V_9 -> V_13 ) ;
}
T_1 F_11 ( T_4 V_15 )
{
return F_8 ( V_11 ,
V_16 , V_15 ) ;
}
void F_12 ( T_1 V_3 , T_4 V_15 )
{
F_10 ( V_3 , V_11 ,
V_16 , V_15 ) ;
}
T_1 F_13 ( T_1 V_4 , T_1 V_5 , T_4 V_15 )
{
return F_14 ( V_4 , V_5 ,
V_11 ,
V_16 ,
V_15 ) ;
}
static inline T_1 F_15 ( T_3 V_17 , T_3 V_18 )
{
T_1 V_4 , V_19 ;
V_4 = F_1 ( V_12 ,
V_17 ) ;
V_19 = F_1 ( V_12 , V_18 ) ;
return V_4 & V_19 ;
}
void F_16 ( unsigned long * V_20 )
{
V_20 [ 0 ] = F_15 ( V_21 ,
V_22 ) ;
V_20 [ 1 ] = F_15 ( V_23 ,
V_24 ) ;
}
void F_17 ( void )
{
F_1 ( V_12 ,
V_25 ) ;
}
void F_18 ( T_1 * V_26 )
{
V_26 [ 0 ] =
F_1 ( V_12 ,
V_22 ) ;
V_26 [ 1 ] =
F_1 ( V_12 ,
V_24 ) ;
F_4 ( 0 , V_12 ,
V_21 ) ;
F_4 ( 0 , V_12 ,
V_23 ) ;
F_1 ( V_12 ,
V_25 ) ;
}
void F_19 ( T_1 * V_26 )
{
F_4 ( V_26 [ 0 ] , V_12 ,
V_21 ) ;
F_4 ( V_26 [ 1 ] , V_12 ,
V_23 ) ;
}
static int T_5 F_20 ( void )
{
if ( F_21 () )
return F_22 ( & V_27 ) ;
return 0 ;
}
