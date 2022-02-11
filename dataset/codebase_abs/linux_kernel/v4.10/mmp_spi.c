static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 100000 , V_5 , V_6 = 0 ;
T_1 V_7 ;
void * V_8 =
* ( void * * ) F_2 ( V_2 -> V_9 ) ;
F_3 ( ~ V_10 , V_8 + V_11 ) ;
switch ( V_2 -> V_12 ) {
case 8 :
F_3 ( ( V_13 ) V_3 , V_8 + V_14 ) ;
break;
case 16 :
F_3 ( ( V_15 ) V_3 , V_8 + V_14 ) ;
break;
case 32 :
F_3 ( ( T_1 ) V_3 , V_8 + V_14 ) ;
break;
default:
F_4 ( & V_2 -> V_16 , L_1 ) ;
}
V_7 = F_5 ( V_8 + V_17 ) ;
V_7 &= ~ V_18 ;
V_7 |= F_6 ( 1 ) ;
F_7 ( V_7 , V_8 + V_17 ) ;
V_5 = F_5 ( V_8 + V_11 ) ;
while ( ! ( V_5 & V_19 ) ) {
F_8 ( 100 ) ;
V_5 = F_5 ( V_8 + V_11 ) ;
if ( ! -- V_4 ) {
V_6 = - V_20 ;
F_4 ( & V_2 -> V_16 , L_2 ) ;
break;
}
}
V_7 = F_5 ( V_8 + V_17 ) ;
V_7 &= ~ V_18 ;
V_7 |= F_6 ( 0 ) ;
F_3 ( V_7 , V_8 + V_17 ) ;
F_3 ( ~ V_10 , V_8 + V_11 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 )
{
void * V_8 =
* ( void * * ) F_2 ( V_2 -> V_9 ) ;
T_1 V_7 ;
V_7 = F_10 ( 16 ) |
F_11 ( V_2 -> V_12 ) |
F_12 ( 1 ) | F_13 ( 1 ) |
F_14 ( 1 ) ;
F_7 ( V_7 , V_8 + V_17 ) ;
V_7 = F_5 ( V_8 + V_21 ) ;
if ( ( V_7 & V_22 ) != V_23 )
F_3 ( V_23 |
( V_7 & ~ V_22 ) ,
V_8 + V_21 ) ;
F_8 ( 20 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
F_16 (t, &m->transfers, transfer_list) {
switch ( V_2 -> V_12 ) {
case 8 :
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ )
F_1 ( V_2 , ( ( V_13 * ) V_27 -> V_30 ) [ V_28 ] ) ;
break;
case 16 :
for ( V_28 = 0 ; V_28 < V_27 -> V_29 / 2 ; V_28 ++ )
F_1 ( V_2 , ( ( V_15 * ) V_27 -> V_30 ) [ V_28 ] ) ;
break;
case 32 :
for ( V_28 = 0 ; V_28 < V_27 -> V_29 / 4 ; V_28 ++ )
F_1 ( V_2 , ( ( T_1 * ) V_27 -> V_30 ) [ V_28 ] ) ;
break;
default:
F_4 ( & V_2 -> V_16 , L_1 ) ;
}
}
V_25 -> V_31 = 0 ;
if ( V_25 -> V_32 )
V_25 -> V_32 ( V_25 -> V_33 ) ;
return 0 ;
}
int F_17 ( struct V_34 * V_35 )
{
struct V_36 * V_9 ;
void * * V_37 ;
int V_38 ;
V_9 = F_18 ( V_35 -> V_16 , sizeof( void * ) ) ;
if ( ! V_9 ) {
F_4 ( V_35 -> V_16 , L_3 ) ;
return - V_39 ;
}
V_37 = F_2 ( V_9 ) ;
* V_37 = V_35 -> V_8 ;
V_9 -> V_40 = 5 ;
V_9 -> V_41 = 1 ;
V_9 -> V_42 = F_9 ;
V_9 -> V_43 = F_15 ;
V_38 = F_19 ( V_9 ) ;
if ( V_38 < 0 ) {
F_4 ( V_35 -> V_16 , L_4 ) ;
F_20 ( V_9 ) ;
return V_38 ;
}
F_21 ( & V_9 -> V_16 , L_5 ) ;
return 0 ;
}
