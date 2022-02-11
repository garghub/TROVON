int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 = F_3 ( V_3 , V_5 -> V_7 ) ;
if ( ! V_5 -> V_6 )
return - V_8 ;
F_4 ( V_5 ) ;
return 0 ;
}
static T_1 F_5 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_13 ;
T_3 * V_14 ;
int V_15 ;
T_4 V_16 ;
unsigned long V_17 = F_6 ( V_5 -> V_6 -> V_18 ,
V_19 ) ;
if ( V_5 -> V_7 -> V_20 != 8 )
V_16 = V_17 * 2 ;
else
V_16 = V_17 ;
if ( V_2 -> V_21 ) {
V_16 += sizeof( T_2 ) ;
if ( V_16 % sizeof( T_2 ) )
V_16 += sizeof( T_2 ) - ( V_16 % sizeof( T_2 ) ) ;
}
if ( V_17 == 0 )
return V_22 ;
V_14 = F_7 ( V_16 , V_23 ) ;
if ( V_14 == NULL )
return - V_24 ;
if ( V_5 -> V_7 -> V_20 != 8 )
V_15 = F_8 ( V_5 -> V_25 , V_14 , V_17 * 2 ) ;
else
V_15 = F_8 ( V_5 -> V_25 , V_14 , V_17 ) ;
if ( V_15 < 0 )
goto V_26;
V_13 = F_9 () ;
if ( V_2 -> V_21 )
memcpy ( V_14 + V_16 - sizeof( T_2 ) , & V_13 , sizeof( V_13 ) ) ;
F_10 ( V_2 -> V_27 , V_14 , V_13 ) ;
V_26:
F_11 ( V_2 -> V_28 ) ;
F_12 ( V_14 ) ;
return V_22 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_29 = 0 ;
V_2 -> V_27 = F_14 ( V_2 ) ;
if ( ! V_2 -> V_27 ) {
V_29 = - V_24 ;
goto V_30;
}
V_2 -> V_31 = F_15 ( NULL ,
& F_5 ,
V_32 ,
V_2 ,
L_1 ,
V_5 -> V_25 -> V_33 ,
V_2 -> V_34 ) ;
if ( V_2 -> V_31 == NULL ) {
V_29 = - V_24 ;
goto V_35;
}
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 |= V_39 ;
return 0 ;
V_35:
F_16 ( V_2 -> V_27 ) ;
V_30:
return V_29 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_31 ) ;
F_16 ( V_2 -> V_27 ) ;
}
