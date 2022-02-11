static int F_1 ( struct V_1 * V_1 , int V_2 , int V_3 )
{
struct V_4 V_5 = V_6 [ V_2 ] ;
int V_7 = 0 ;
int V_8 ;
T_1 V_9 = 0 , V_10 ;
if ( V_2 == V_11 )
return 0 ;
while ( V_7 < V_5 . V_12 ) {
V_7 = V_5 . V_13 [ V_9 ] ;
if ( V_7 >= V_3 )
break;
else if ( V_7 < V_3 )
V_9 ++ ;
}
if ( V_7 > V_5 . V_12 )
return - V_14 ;
V_10 = V_9 << 1 ;
V_8 = V_1 -> V_15 ( V_1 , V_5 . V_16 , 1 , & V_10 ) ;
return V_8 ;
}
static int F_2 ( struct V_1 * V_1 , int V_2 )
{
struct V_4 V_5 = V_6 [ V_2 ] ;
int V_8 ;
T_1 V_10 ;
if ( V_2 == V_11 )
return 0 ;
V_8 = V_1 -> V_17 ( V_1 , V_5 . V_16 , 1 , & V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 >>= 1 ;
return V_5 . V_13 [ V_10 ] ;
}
static T_2 F_3 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_1 * V_1 = F_4 ( V_19 -> V_23 ) ;
struct V_24 V_25 = V_21 -> V_21 ;
int V_2 , V_26 ;
if ( ! strcmp ( V_25 . V_27 , L_1 ) )
V_2 = V_28 ;
else if ( ! strcmp ( V_25 . V_27 , L_2 ) )
V_2 = V_29 ;
else
return - V_14 ;
V_26 = F_2 ( V_1 , V_2 ) ;
return sprintf ( V_22 , L_3 , V_26 ) ;
}
static T_3 int F_5 ( struct V_30 * V_31 )
{
struct V_1 * V_1 = F_4 ( V_31 -> V_19 . V_23 ) ;
struct V_32 * V_33 = F_6 ( V_1 -> V_19 ) ;
int V_8 ;
V_8 = F_1 ( V_1 , V_28 , V_33 -> V_34 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_31 -> V_19 , L_4 ) ;
return V_8 ;
}
V_8 = F_1 ( V_1 , V_29 , V_33 -> V_35 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_31 -> V_19 , L_5 ) ;
return V_8 ;
}
V_8 = F_8 ( & V_31 -> V_19 , & V_36 ) ;
if ( V_8 < 0 )
F_7 ( & V_31 -> V_19 , L_6 ) ;
V_8 = F_8 ( & V_31 -> V_19 , & V_37 ) ;
if ( V_8 < 0 )
F_7 ( & V_31 -> V_19 , L_7 ) ;
return V_8 ;
}
static T_4 int F_9 ( struct V_30 * V_31 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_31 -> V_19 . V_23 ) ;
F_10 ( & V_31 -> V_19 , & V_37 ) ;
F_10 ( & V_31 -> V_19 , & V_36 ) ;
return 0 ;
}
static int T_5 F_11 ( void )
{
return F_12 ( & V_38 ) ;
}
static void T_6 F_13 ( void )
{
F_14 ( & V_38 ) ;
}
