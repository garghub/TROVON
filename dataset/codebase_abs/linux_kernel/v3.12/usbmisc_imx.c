static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
unsigned long V_4 ;
T_2 V_5 ;
if ( V_2 -> V_6 > 2 )
return - V_7 ;
V_3 = V_8 -> V_9 + V_10 ;
if ( V_2 -> V_11 ) {
F_2 ( & V_8 -> V_12 , V_4 ) ;
V_5 = F_3 ( V_3 ) ;
F_4 ( V_5 | V_13 , V_3 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
F_6 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
void T_1 * V_3 = NULL ;
unsigned long V_4 ;
T_2 V_5 = 0 ;
if ( V_2 -> V_6 > 3 )
return - V_7 ;
if ( V_2 -> V_14 ) {
F_2 ( & V_8 -> V_12 , V_4 ) ;
switch ( V_2 -> V_6 ) {
case 0 :
V_3 = V_8 -> V_9 + V_15 ;
V_5 = F_3 ( V_3 ) | V_16 ;
break;
case 1 :
V_3 = V_8 -> V_9 + V_15 ;
V_5 = F_3 ( V_3 ) | V_17 ;
break;
case 2 :
V_3 = V_8 -> V_9 + V_18 ;
V_5 = F_3 ( V_3 ) | V_19 ;
break;
case 3 :
V_3 = V_8 -> V_9 + V_20 ;
V_5 = F_3 ( V_3 ) | V_19 ;
break;
}
if ( V_3 && V_5 )
F_4 ( V_5 , V_3 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
T_2 V_3 ;
if ( V_2 -> V_6 > 3 )
return - V_7 ;
if ( V_2 -> V_14 ) {
F_2 ( & V_8 -> V_12 , V_4 ) ;
V_3 = F_3 ( V_8 -> V_9 + V_2 -> V_6 * 4 ) ;
F_4 ( V_3 | V_21 ,
V_8 -> V_9 + V_2 -> V_6 * 4 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
if ( ! V_8 )
return - V_22 ;
if ( ! V_8 -> V_23 -> V_24 )
return 0 ;
return V_8 -> V_23 -> V_24 ( V_2 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_8 )
return - V_22 ;
if ( ! V_8 -> V_23 -> V_25 )
return 0 ;
return V_8 -> V_23 -> V_25 ( V_2 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_2 ;
int V_31 ;
struct V_32 * V_33 ;
if ( V_8 )
return - V_34 ;
V_2 = F_12 ( & V_27 -> V_35 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
F_13 ( & V_2 -> V_12 ) ;
V_29 = F_14 ( V_27 , V_38 , 0 ) ;
V_2 -> V_9 = F_15 ( & V_27 -> V_35 , V_29 ) ;
if ( F_16 ( V_2 -> V_9 ) )
return F_17 ( V_2 -> V_9 ) ;
V_2 -> V_39 = F_18 ( & V_27 -> V_35 , NULL ) ;
if ( F_16 ( V_2 -> V_39 ) ) {
F_19 ( & V_27 -> V_35 ,
L_1 , F_17 ( V_2 -> V_39 ) ) ;
return F_17 ( V_2 -> V_39 ) ;
}
V_31 = F_20 ( V_2 -> V_39 ) ;
if ( V_31 ) {
F_19 ( & V_27 -> V_35 ,
L_2 , V_31 ) ;
return V_31 ;
}
V_33 = (struct V_32 * )
F_21 ( V_40 , & V_27 -> V_35 ) ;
V_2 -> V_23 = ( const struct V_41 * ) V_33 -> V_2 ;
V_8 = V_2 ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 )
{
F_23 ( V_8 -> V_39 ) ;
V_8 = NULL ;
return 0 ;
}
