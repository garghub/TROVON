int F_1 ( const long * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) -> V_6 ;
int V_7 = 0 , V_8 , V_9 ;
T_1 * V_10 ;
V_9 = F_3 ( V_1 , V_11 ) ;
if ( ! ( F_4 ( V_9 , V_3 -> V_12 -> V_13 ) ) ) {
V_8 = - V_14 ;
goto V_15;
}
V_10 = F_5 ( V_5 -> V_16 -> V_17 ( V_5 ) ,
V_18 ) ;
if ( V_10 == NULL ) {
V_8 = - V_19 ;
goto V_15;
}
V_8 = V_5 -> V_16 -> V_20 ( V_5 , V_10 ) ;
if ( V_8 )
goto V_21;
V_7 = F_6 ( V_1 , V_9 - 1 ) ;
if ( V_3 -> V_22 -> V_23 != 8 )
V_8 = ( ( int ) ( V_10 [ V_7 * 2 + 0 ] & 0x0F ) << 8 )
+ ( int ) ( V_10 [ V_7 * 2 + 1 ] ) ;
else
V_8 = V_10 [ V_7 ] ;
V_21:
F_7 ( V_10 ) ;
V_15:
return V_8 ;
}
static int F_8 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_9 ( V_25 ) ;
struct V_4 * V_5 = V_25 -> V_6 ;
T_2 V_26 = 0 ;
unsigned long V_27 ;
V_3 -> V_12 = F_10 ( V_5 -> V_28 ,
V_3 -> V_22 ) ;
if ( ! V_3 -> V_12 )
return - V_29 ;
F_11 ( V_3 ) ;
V_27 = F_6 ( V_3 -> V_12 -> V_13 ,
V_25 -> V_30 ) ;
if ( V_5 -> V_16 -> V_31 ) {
if ( V_5 -> V_32 )
V_26 += sizeof( V_33 ) ;
if ( V_3 -> V_22 -> V_23 != 8 )
V_26 += V_27 * 2 ;
else
V_26 += V_27 ;
if ( V_5 -> V_32 && ( V_26 % 8 ) )
V_26 += 8 - ( V_26 % 8 ) ;
V_5 -> V_16 -> V_31 ( V_5 , V_26 ) ;
}
return 0 ;
}
static T_3 F_12 ( int V_34 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_24 * V_25 = V_37 -> V_25 ;
struct V_2 * V_3 = F_9 ( V_25 ) ;
V_33 V_38 ;
T_4 * V_39 ;
int V_40 ;
T_2 V_26 ;
unsigned long V_27 = F_6 ( V_3 -> V_12 -> V_13 ,
V_11 ) ;
if ( V_3 -> V_22 -> V_23 != 8 )
V_26 = V_27 * 2 + sizeof( V_33 ) ;
else
V_26 = V_27 + sizeof( V_33 ) ;
if ( V_26 % sizeof( V_33 ) )
V_26 += sizeof( V_33 ) - ( V_26 % sizeof( V_33 ) ) ;
if ( V_27 == 0 )
return V_41 ;
V_39 = F_5 ( V_26 , V_18 ) ;
if ( V_39 == NULL )
return - V_19 ;
if ( V_3 -> V_22 -> V_23 != 8 )
V_40 = F_13 ( V_3 -> V_42 , V_39 , V_27 * 2 ) ;
else
V_40 = F_13 ( V_3 -> V_42 , V_39 , V_27 ) ;
if ( V_40 < 0 )
goto V_43;
V_38 = F_14 () ;
memcpy ( V_39 + V_26 - sizeof( V_33 ) , & V_38 , sizeof( V_38 ) ) ;
V_25 -> V_6 -> V_16 -> V_44 ( V_25 -> V_6 , V_39 , V_38 ) ;
V_43:
F_15 ( V_25 -> V_45 ) ;
F_7 ( V_39 ) ;
return V_41 ;
}
int F_16 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_9 ( V_25 ) ;
int V_8 = 0 ;
V_25 -> V_6 = F_17 ( V_25 ) ;
if ( ! V_25 -> V_6 ) {
V_8 = - V_19 ;
goto V_15;
}
V_25 -> V_46 = F_18 ( NULL ,
& F_12 ,
V_47 ,
V_25 ,
L_1 ,
V_3 -> V_42 -> V_48 ,
V_25 -> V_49 ) ;
if ( V_25 -> V_46 == NULL ) {
V_8 = - V_19 ;
goto V_50;
}
V_25 -> V_6 -> V_16 = & V_51 ;
V_25 -> V_6 -> V_52 = & V_53 ;
V_25 -> V_54 |= V_55 ;
return 0 ;
V_50:
F_19 ( V_25 -> V_6 ) ;
V_15:
return V_8 ;
}
void F_20 ( struct V_24 * V_25 )
{
F_21 ( V_25 -> V_46 ) ;
F_19 ( V_25 -> V_6 ) ;
}
