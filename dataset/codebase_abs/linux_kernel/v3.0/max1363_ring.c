int F_1 ( long V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) -> V_5 ;
int V_6 = 0 , V_7 ;
T_1 * V_8 ;
if ( ! ( V_3 -> V_9 -> V_10 & V_1 ) ) {
V_7 = - V_11 ;
goto V_12;
}
V_8 = F_3 ( V_5 -> V_13 -> V_14 ( V_5 ) ,
V_15 ) ;
if ( V_8 == NULL ) {
V_7 = - V_16 ;
goto V_12;
}
V_7 = V_5 -> V_13 -> V_17 ( V_5 , V_8 ) ;
if ( V_7 )
goto V_18;
V_1 >>= 1 ;
while ( V_1 ) {
if ( V_1 & V_3 -> V_9 -> V_10 )
V_6 ++ ;
V_1 >>= 1 ;
}
if ( V_3 -> V_19 -> V_20 != 8 )
V_7 = ( ( int ) ( V_8 [ V_6 * 2 + 0 ] & 0x0F ) << 8 )
+ ( int ) ( V_8 [ V_6 * 2 + 1 ] ) ;
else
V_7 = V_8 [ V_6 ] ;
V_18:
F_4 ( V_8 ) ;
V_12:
return V_7 ;
}
static int F_5 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_6 ( V_22 ) ;
struct V_4 * V_5 = V_22 -> V_5 ;
T_2 V_23 = 0 ;
unsigned long V_24 ;
V_3 -> V_9 = F_7 ( V_5 -> V_25 ,
V_3 -> V_19 ) ;
if ( ! V_3 -> V_9 )
return - V_26 ;
F_8 ( V_3 ) ;
V_24 = F_9 ( V_3 -> V_9 -> V_10 ) ;
if ( V_5 -> V_13 -> V_27 ) {
if ( V_5 -> V_28 )
V_23 += sizeof( V_29 ) ;
if ( V_3 -> V_19 -> V_20 != 8 )
V_23 += V_24 * 2 ;
else
V_23 += V_24 ;
if ( V_5 -> V_28 && ( V_23 % 8 ) )
V_23 += 8 - ( V_23 % 8 ) ;
V_5 -> V_13 -> V_27 ( V_5 , V_23 ) ;
}
return 0 ;
}
static T_3 F_10 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_21 * V_22 = V_33 -> V_34 ;
struct V_2 * V_3 = F_6 ( V_22 ) ;
V_29 V_35 ;
T_4 * V_36 ;
int V_37 ;
T_2 V_23 ;
unsigned long V_24 = F_9 ( V_3 -> V_9 -> V_10 ) ;
if ( V_3 -> V_19 -> V_20 != 8 )
V_23 = V_24 * 2 + sizeof( V_29 ) ;
else
V_23 = V_24 + sizeof( V_29 ) ;
if ( V_23 % sizeof( V_29 ) )
V_23 += sizeof( V_29 ) - ( V_23 % sizeof( V_29 ) ) ;
if ( V_24 == 0 )
return V_38 ;
V_36 = F_3 ( V_23 , V_15 ) ;
if ( V_36 == NULL )
return - V_16 ;
if ( V_3 -> V_19 -> V_20 != 8 )
V_37 = F_11 ( V_3 -> V_39 , V_36 , V_24 * 2 ) ;
else
V_37 = F_11 ( V_3 -> V_39 , V_36 , V_24 ) ;
if ( V_37 < 0 )
goto V_40;
V_35 = F_12 () ;
memcpy ( V_36 + V_23 - sizeof( V_29 ) , & V_35 , sizeof( V_35 ) ) ;
V_22 -> V_5 -> V_13 -> V_41 ( V_22 -> V_5 , V_36 , V_35 ) ;
V_40:
F_13 ( V_22 -> V_42 ) ;
F_4 ( V_36 ) ;
return V_38 ;
}
int F_14 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_6 ( V_22 ) ;
int V_7 = 0 ;
V_22 -> V_5 = F_15 ( V_22 ) ;
if ( ! V_22 -> V_5 ) {
V_7 = - V_16 ;
goto V_12;
}
V_22 -> V_43 = F_16 ( NULL ,
& F_10 ,
V_44 ,
V_22 ,
L_1 ,
V_3 -> V_39 -> V_45 ,
V_22 -> V_46 ) ;
if ( V_22 -> V_43 == NULL ) {
V_7 = - V_16 ;
goto V_47;
}
V_22 -> V_5 -> V_13 = & V_48 ;
V_22 -> V_5 -> V_49 = & V_50 ;
V_22 -> V_51 |= V_52 ;
return 0 ;
V_47:
F_17 ( V_22 -> V_5 ) ;
V_12:
return V_7 ;
}
void F_18 ( struct V_21 * V_22 )
{
if ( V_22 -> V_42 ) {
F_19 ( V_22 -> V_42 ) ;
F_20 ( V_22 -> V_42 ,
V_22 -> V_43 ) ;
}
F_21 ( V_22 -> V_43 ) ;
F_17 ( V_22 -> V_5 ) ;
}
