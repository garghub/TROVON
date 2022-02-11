int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_6 )
{
int V_7 ;
unsigned int V_8 ;
switch ( V_6 ) {
case V_9 :
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
case V_10 :
V_8 = V_3 ^ V_11 ;
V_7 = F_4 ( V_2 -> V_5 , V_12 ,
V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
case V_13 :
V_8 = V_3 ^ V_11 ;
V_7 = F_4 ( V_2 -> V_5 , V_12 ,
V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_5 , V_12 ,
V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
default:
return - V_14 ;
}
}
int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 , unsigned int V_4 , unsigned int V_6 )
{
int V_7 ;
unsigned int V_16 ;
V_7 = F_1 ( V_2 , V_3 , & V_16 ) ;
if ( V_7 ) {
F_6 ( V_2 -> V_17 , L_1 , V_3 ) ;
return V_7 ;
}
V_16 &= ~ V_15 ;
V_16 |= V_4 & V_15 ;
V_7 = F_3 ( V_2 , V_3 , V_16 , V_6 ) ;
if ( V_7 )
F_6 ( V_2 -> V_17 , L_2 , V_3 ) ;
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 , unsigned int V_4 , unsigned int V_6 )
{
return F_5 ( V_2 , V_3 , V_15 , V_4 , V_6 ) ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 , unsigned int V_6 )
{
return F_5 ( V_2 , V_3 , V_15 , 0 , V_6 ) ;
}
static int T_1 F_9 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 = V_19 -> V_17 . V_24 ;
int V_25 , V_7 ;
unsigned int V_26 ;
V_2 = F_10 ( & V_19 -> V_17 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_5 = F_11 ( V_19 , & V_29 ) ;
if ( F_12 ( V_2 -> V_5 ) ) {
V_7 = F_13 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_17 , L_3 ,
V_7 ) ;
return V_7 ;
}
F_14 ( V_19 , V_2 ) ;
V_2 -> V_17 = & V_19 -> V_17 ;
V_7 = F_1 ( V_2 , V_30 , & V_26 ) ;
if ( V_7 < 0 ) {
F_6 ( V_2 -> V_17 , L_4
L_5 , V_7 ) ;
goto V_31;
}
F_15 ( V_2 -> V_17 , L_6 ,
( V_26 & V_32 ) >> 4 ,
V_26 & V_33 ) ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ ) {
struct V_35 * V_36 ;
V_36 = F_16 ( L_7 , V_25 ) ;
if ( ! V_36 ) {
F_6 ( V_2 -> V_17 , L_8 , V_25 ) ;
continue;
}
V_36 -> V_17 . V_37 = V_2 -> V_17 ;
F_17 ( V_36 , & V_23 -> V_38 [ V_25 ] ,
sizeof( V_23 -> V_38 [ V_25 ] ) ) ;
V_2 -> V_39 [ V_25 ] = V_36 ;
F_18 ( V_36 ) ;
}
return 0 ;
V_31:
F_19 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int T_2 F_20 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ )
F_22 ( V_2 -> V_39 [ V_25 ] ) ;
F_19 ( V_2 -> V_5 ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_40 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_40 ) ;
}
