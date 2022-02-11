static int F_1 ( struct V_1 * V_2 , int V_3 , const char * V_4 ,
struct V_5 * V_6 , int V_7 )
{
unsigned int V_8 ;
unsigned short V_9 ;
if ( V_7 == 0 )
return V_10 ;
F_2 ( V_2 , V_3 , & V_8 ) ;
V_9 = 0 ;
if ( ! ( V_8 & ( 1 << 31 ) ) )
F_3 ( & V_2 -> V_11 , L_1 ,
V_4 ) ;
else
V_9 = ( unsigned short ) V_8 ;
if ( V_9 == 0 ) {
F_3 ( & V_2 -> V_11 , L_2 , V_4 ) ;
return V_12 ;
}
V_6 -> V_13 = V_9 ;
V_6 -> V_14 = V_9 + V_7 - 1 ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
const char * V_4 , int V_7 , int V_17 ,
int V_18 , struct V_19 * V_20 )
{
struct V_5 * V_6 ;
int V_21 ;
V_6 = F_5 ( & V_2 -> V_11 , 2 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return - V_23 ;
V_21 = F_1 ( V_2 , V_3 , V_4 , V_6 , V_7 ) ;
if ( V_21 )
return V_21 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_4 = V_4 ;
V_20 -> V_24 = V_6 ;
V_20 -> V_25 = 1 ;
V_20 -> V_26 = true ;
V_20 -> V_18 = V_18 ;
if ( V_17 < 0 )
return 0 ;
V_6 ++ ;
V_6 -> V_13 = V_17 ;
V_6 -> V_14 = V_17 ;
V_6 -> V_15 = V_27 ;
V_20 -> V_25 ++ ;
return 0 ;
}
static int F_6 ( struct V_1 * V_11 , const struct V_28 * V_18 )
{
struct V_19 V_29 [ 3 ] ;
struct V_30 * V_31 = & V_32 [ V_18 -> V_33 ] ;
unsigned int V_34 = 0 ;
int V_21 ;
V_21 = F_4 ( V_11 , V_35 , L_3 ,
V_31 -> V_36 , - 1 ,
V_18 -> V_37 , & V_29 [ V_34 ] ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 == 0 )
V_34 ++ ;
V_21 = F_4 ( V_11 , V_38 , L_4 ,
V_31 -> V_39 , V_31 -> V_40 ,
V_18 -> V_37 , & V_29 [ V_34 ] ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 == 0 )
V_34 ++ ;
V_21 = F_4 ( V_11 , V_41 , L_5 ,
V_31 -> V_42 , - 1 ,
V_18 -> V_37 , & V_29 [ V_34 ] ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 == 0 )
V_34 ++ ;
if ( V_34 == 0 ) {
F_7 ( & V_11 -> V_11 , L_6 ) ;
return - V_43 ;
}
V_21 = F_8 ( & V_11 -> V_11 , 0 , V_29 , V_34 , NULL , 0 , NULL ) ;
if ( V_21 )
F_9 ( & V_11 -> V_11 ) ;
return V_21 ;
}
static void F_10 ( struct V_1 * V_11 )
{
F_9 ( & V_11 -> V_11 ) ;
}
