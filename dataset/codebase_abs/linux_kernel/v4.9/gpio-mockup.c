static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 [ V_3 ] . V_7 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 [ V_3 ] . V_7 = ! ! V_7 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_2 , V_3 , V_7 ) ;
V_5 -> V_6 [ V_3 ] . V_8 = V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 [ V_3 ] . V_8 = V_10 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 [ V_3 ] . V_8 ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_4 * V_5 ,
const char * V_13 , int V_14 , int V_15 )
{
int V_16 ;
V_5 -> V_2 . V_14 = V_14 ;
V_5 -> V_2 . V_15 = V_15 ;
V_5 -> V_2 . V_17 = V_13 ;
V_5 -> V_2 . V_18 = V_19 ;
V_5 -> V_2 . V_20 = V_12 ;
V_5 -> V_2 . V_21 = F_1 ;
V_5 -> V_2 . V_22 = F_3 ;
V_5 -> V_2 . V_23 = F_4 ;
V_5 -> V_2 . V_24 = F_5 ;
V_5 -> V_2 . V_25 = F_6 ;
V_5 -> V_6 = F_8 ( V_12 , sizeof( * V_5 -> V_6 ) * V_5 -> V_2 . V_15 ,
V_26 ) ;
if ( ! V_5 -> V_6 ) {
V_16 = - V_27 ;
goto V_28;
}
V_16 = F_9 ( V_12 , & V_5 -> V_2 , V_5 ) ;
if ( V_16 )
goto V_28;
F_10 ( V_12 , L_1 , V_14 , V_14 + V_15 ) ;
return 0 ;
V_28:
F_11 ( V_12 , L_2 , V_14 , V_14 + V_15 ) ;
return V_16 ;
}
static int F_12 ( struct V_29 * V_30 )
{
struct V_11 * V_12 = & V_30 -> V_12 ;
struct V_4 * V_5 ;
int V_16 ;
int V_31 ;
int V_14 ;
int V_15 ;
char V_32 [ sizeof( V_33 ) + 3 ] ;
if ( V_34 < 2 )
return - V_35 ;
V_5 = F_8 ( V_12 , sizeof( * V_5 ) * ( V_34 >> 1 ) ,
V_26 ) ;
if ( ! V_5 )
return - V_27 ;
F_13 ( V_30 , V_5 ) ;
for ( V_31 = 0 ; V_31 < V_34 > > 1 ; V_31 ++ ) {
V_14 = V_36 [ V_31 * 2 ] ;
if ( V_14 == - 1 )
V_15 = V_36 [ V_31 * 2 + 1 ] ;
else
V_15 = V_36 [ V_31 * 2 + 1 ] - V_14 ;
if ( V_15 >= 0 ) {
sprintf ( V_32 , L_3 , V_33 ,
V_37 + V_31 ) ;
V_16 = F_7 ( V_12 , & V_5 [ V_31 ] ,
V_32 , V_14 , V_15 ) ;
} else {
V_16 = - 1 ;
}
if ( V_16 ) {
if ( V_14 < 0 )
F_11 ( V_12 , L_4 ,
V_14 , V_15 ) ;
else
F_11 ( V_12 , L_4 ,
V_14 , V_14 + V_15 ) ;
return V_16 ;
}
}
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_28 ;
V_30 = F_15 ( V_33 , - 1 ) ;
if ( ! V_30 )
return - V_27 ;
V_28 = F_16 ( V_30 ) ;
if ( V_28 ) {
F_17 ( V_30 ) ;
return V_28 ;
}
V_28 = F_18 ( & V_38 ) ;
if ( V_28 ) {
F_19 ( V_30 ) ;
return V_28 ;
}
return 0 ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_38 ) ;
F_19 ( V_30 ) ;
}
