static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_7 -> V_8 [ V_4 ] . V_3 == V_3 )
return & V_7 -> V_8 [ V_4 ] ;
else if ( ! V_7 -> V_8 [ V_4 ] . V_3 )
break;
}
if ( V_4 >= V_6 )
return F_2 ( - V_9 ) ;
V_5 = F_3 ( V_3 , & V_7 -> V_8 [ V_4 ] ) ;
if ( V_5 )
return F_2 ( V_5 ) ;
return & V_7 -> V_8 [ V_4 ] ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
void T_1 * V_10 ;
unsigned long V_11 ;
T_2 V_12 ;
V_8 = F_1 ( V_3 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
V_10 = V_7 -> V_13 + V_14 ;
if ( V_8 -> V_15 ) {
F_7 ( & V_7 -> V_16 , V_11 ) ;
V_12 = F_8 ( V_10 ) ;
F_9 ( V_12 | V_17 , V_10 ) ;
F_10 ( & V_7 -> V_16 , V_11 ) ;
F_11 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
void T_1 * V_10 = NULL ;
unsigned long V_11 ;
T_2 V_12 = 0 ;
V_8 = F_1 ( V_3 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
if ( V_8 -> V_18 ) {
F_7 ( & V_7 -> V_16 , V_11 ) ;
switch ( V_8 -> V_19 ) {
case 0 :
V_10 = V_7 -> V_13 + V_20 ;
V_12 = F_8 ( V_10 ) | V_21 ;
break;
case 1 :
V_10 = V_7 -> V_13 + V_20 ;
V_12 = F_8 ( V_10 ) | V_22 ;
break;
case 2 :
V_10 = V_7 -> V_13 + V_23 ;
V_12 = F_8 ( V_10 ) | V_24 ;
break;
case 3 :
V_10 = V_7 -> V_13 + V_25 ;
V_12 = F_8 ( V_10 ) | V_24 ;
break;
}
if ( V_10 && V_12 )
F_9 ( V_12 , V_10 ) ;
F_10 ( & V_7 -> V_16 , V_11 ) ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
unsigned long V_11 ;
T_2 V_10 ;
V_8 = F_1 ( V_3 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
if ( V_8 -> V_18 ) {
F_7 ( & V_7 -> V_16 , V_11 ) ;
V_10 = F_8 ( V_7 -> V_13 + V_8 -> V_19 * 4 ) ;
F_9 ( V_10 | V_26 ,
V_7 -> V_13 + V_8 -> V_19 * 4 ) ;
F_10 ( & V_7 -> V_16 , V_11 ) ;
}
return 0 ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_5 ;
struct V_33 * V_34 ;
if ( V_7 )
return - V_9 ;
V_32 = F_15 ( & V_28 -> V_3 , sizeof( * V_32 ) , V_35 ) ;
if ( ! V_32 )
return - V_36 ;
F_16 ( & V_32 -> V_16 ) ;
V_30 = F_17 ( V_28 , V_37 , 0 ) ;
V_32 -> V_13 = F_18 ( & V_28 -> V_3 , V_30 ) ;
if ( F_5 ( V_32 -> V_13 ) )
return F_6 ( V_32 -> V_13 ) ;
V_32 -> V_38 = F_19 ( & V_28 -> V_3 , NULL ) ;
if ( F_5 ( V_32 -> V_38 ) ) {
F_20 ( & V_28 -> V_3 ,
L_1 , F_6 ( V_32 -> V_38 ) ) ;
return F_6 ( V_32 -> V_38 ) ;
}
V_5 = F_21 ( V_32 -> V_38 ) ;
if ( V_5 ) {
F_20 ( & V_28 -> V_3 ,
L_2 , V_5 ) ;
return V_5 ;
}
V_34 = (struct V_33 * )
F_22 ( V_39 , & V_28 -> V_3 ) ;
V_32 -> V_40 = ( const struct V_41 * ) V_34 -> V_32 ;
V_7 = V_32 ;
V_5 = F_23 ( V_32 -> V_40 ) ;
if ( V_5 ) {
V_7 = NULL ;
F_24 ( V_32 -> V_38 ) ;
return V_5 ;
}
return 0 ;
}
static int F_25 ( struct V_27 * V_28 )
{
F_26 ( V_7 -> V_40 ) ;
F_24 ( V_7 -> V_38 ) ;
V_7 = NULL ;
return 0 ;
}
