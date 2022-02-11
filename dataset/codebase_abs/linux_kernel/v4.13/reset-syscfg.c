static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , int assert )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 ;
T_1 V_8 = V_5 -> V_9 ? ! assert : ! ! assert ;
int V_10 ;
if ( V_3 >= V_2 -> V_11 )
return - V_12 ;
V_7 = & V_5 -> V_13 [ V_3 ] ;
V_10 = F_3 ( V_7 -> V_14 , V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_7 -> V_15 ) {
unsigned long V_16 = V_17 + F_4 ( 1000 ) ;
T_1 V_18 ;
while ( true ) {
V_10 = F_5 ( V_7 -> V_15 , & V_18 ) ;
if ( V_10 )
return V_10 ;
if ( V_18 == V_8 )
break;
if ( F_6 ( V_17 , V_16 ) )
return - V_19 ;
F_7 () ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , true ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , false ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
int V_10 ;
V_10 = F_8 ( V_2 , V_3 ) ;
if ( V_10 )
return V_10 ;
return F_9 ( V_2 , V_3 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 ;
T_1 V_20 = 0 ;
int V_10 ;
if ( V_3 >= V_2 -> V_11 )
return - V_12 ;
V_7 = & V_5 -> V_13 [ V_3 ] ;
if ( V_7 -> V_15 )
V_10 = F_5 ( V_7 -> V_15 , & V_20 ) ;
else
V_10 = F_5 ( V_7 -> V_14 , & V_20 ) ;
if ( V_10 )
return V_10 ;
return V_5 -> V_9 ? ! V_20 : ! ! V_20 ;
}
static int F_12 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_4 * V_25 ;
int V_26 , V_10 ;
V_25 = F_13 ( V_22 , sizeof( * V_25 ) , V_27 ) ;
if ( ! V_25 )
return - V_28 ;
V_25 -> V_13 = F_14 ( V_22 , V_24 -> V_29 ,
sizeof( * V_25 -> V_13 ) , V_27 ) ;
if ( ! V_25 -> V_13 )
return - V_28 ;
V_25 -> V_5 . V_30 = & V_31 ,
V_25 -> V_5 . V_32 = V_22 -> V_32 ;
V_25 -> V_5 . V_11 = V_24 -> V_29 ;
V_25 -> V_9 = V_24 -> V_9 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
const char * V_37 = V_24 -> V_13 [ V_26 ] . V_37 ;
V_34 = F_15 ( V_37 ) ;
if ( F_16 ( V_34 ) )
return F_17 ( V_34 ) ;
V_36 = F_18 ( V_22 , V_34 , V_24 -> V_13 [ V_26 ] . V_14 ) ;
if ( F_16 ( V_36 ) )
return F_17 ( V_36 ) ;
V_25 -> V_13 [ V_26 ] . V_14 = V_36 ;
if ( ! V_24 -> V_38 )
continue;
V_36 = F_18 ( V_22 , V_34 , V_24 -> V_13 [ V_26 ] . V_15 ) ;
if ( F_16 ( V_36 ) )
return F_17 ( V_36 ) ;
V_25 -> V_13 [ V_26 ] . V_15 = V_36 ;
}
V_10 = F_19 ( & V_25 -> V_5 ) ;
if ( ! V_10 )
F_20 ( V_22 , L_1 ) ;
return V_10 ;
}
int F_21 ( struct V_39 * V_40 )
{
struct V_21 * V_22 = V_40 ? & V_40 -> V_22 : NULL ;
const struct V_41 * V_42 ;
if ( ! V_22 || ! V_22 -> V_43 )
return - V_44 ;
V_42 = F_22 ( V_22 -> V_43 -> V_45 , V_22 ) ;
if ( ! V_42 || ! V_42 -> V_24 )
return - V_12 ;
return F_12 ( V_22 , V_42 -> V_24 ) ;
}
