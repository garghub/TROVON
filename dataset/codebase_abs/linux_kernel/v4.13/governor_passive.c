static int F_1 ( struct V_1 * V_1 ,
unsigned long * V_2 )
{
struct V_3 * V_4
= (struct V_3 * ) V_1 -> V_5 ;
struct V_1 * V_6 = (struct V_1 * ) V_4 -> V_7 ;
unsigned long V_8 = V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 , V_14 = 0 ;
if ( V_4 -> V_15 ) {
V_14 = V_4 -> V_15 ( V_1 , V_2 ) ;
goto V_16;
}
if ( ! V_1 -> V_17 || ! V_1 -> V_17 -> V_18
|| V_1 -> V_17 -> V_19 <= 0 )
return - V_20 ;
V_11 = F_2 ( V_6 -> V_21 . V_7 , V_2 , 0 ) ;
if ( F_3 ( V_11 ) ) {
V_14 = F_4 ( V_11 ) ;
goto V_16;
}
F_5 ( V_11 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_17 -> V_19 ; V_12 ++ )
if ( V_6 -> V_17 -> V_18 [ V_12 ] == * V_2 )
break;
if ( V_12 == V_6 -> V_17 -> V_19 ) {
V_14 = - V_20 ;
goto V_16;
}
if ( V_12 < V_1 -> V_17 -> V_19 ) {
V_8 = V_1 -> V_17 -> V_18 [ V_12 ] ;
} else {
V_13 = V_1 -> V_17 -> V_19 ;
V_8 = V_1 -> V_17 -> V_18 [ V_13 - 1 ] ;
}
* V_2 = V_8 ;
V_16:
return V_14 ;
}
static int F_6 ( struct V_1 * V_1 , unsigned long V_2 )
{
int V_14 ;
if ( ! V_1 -> V_22 )
return - V_20 ;
F_7 ( & V_1 -> V_23 , V_24 ) ;
V_14 = V_1 -> V_22 -> V_15 ( V_1 , & V_2 ) ;
if ( V_14 < 0 )
goto V_16;
V_14 = V_1 -> V_17 -> V_25 ( V_1 -> V_21 . V_7 , & V_2 , 0 ) ;
if ( V_14 < 0 )
goto V_16;
if ( V_1 -> V_17 -> V_18
&& ( F_8 ( V_1 , V_2 ) ) )
F_9 ( & V_1 -> V_21 ,
L_1 ) ;
V_1 -> V_26 = V_2 ;
V_16:
F_10 ( & V_1 -> V_23 ) ;
return 0 ;
}
static int F_11 ( struct V_27 * V_28 ,
unsigned long V_29 , void * V_30 )
{
struct V_3 * V_5
= F_12 ( V_28 , struct V_3 , V_28 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_5 -> V_31 ;
struct V_1 * V_7 = (struct V_1 * ) V_5 -> V_7 ;
struct V_32 * V_33 = (struct V_32 * ) V_30 ;
unsigned long V_2 = V_33 -> V_34 ;
switch ( V_29 ) {
case V_35 :
if ( V_7 -> V_26 > V_2 )
F_6 ( V_1 , V_2 ) ;
break;
case V_36 :
if ( V_7 -> V_26 < V_2 )
F_6 ( V_1 , V_2 ) ;
break;
}
return V_37 ;
}
static int F_13 ( struct V_1 * V_1 ,
unsigned int V_29 , void * V_5 )
{
struct V_38 * V_21 = V_1 -> V_21 . V_7 ;
struct V_3 * V_4
= (struct V_3 * ) V_1 -> V_5 ;
struct V_1 * V_7 = (struct V_1 * ) V_4 -> V_7 ;
struct V_27 * V_28 = & V_4 -> V_28 ;
int V_14 = 0 ;
if ( ! V_7 )
return - V_39 ;
switch ( V_29 ) {
case V_40 :
if ( ! V_4 -> V_31 )
V_4 -> V_31 = V_1 ;
V_28 -> V_41 = F_11 ;
V_14 = F_14 ( V_21 , V_7 , V_28 ,
V_42 ) ;
break;
case V_43 :
F_15 ( V_21 , V_7 , V_28 ,
V_42 ) ;
break;
default:
break;
}
return V_14 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_44 ) ;
}
static void T_2 F_18 ( void )
{
int V_14 ;
V_14 = F_19 ( & V_44 ) ;
if ( V_14 )
F_20 ( L_2 , V_45 , V_14 ) ;
}
