static inline void F_1 ( int V_1 )
{
F_2 ( V_2 [ V_1 ] . V_3 , V_1 ) ;
F_3 ( V_2 [ V_1 ] . V_4 , V_1 ) ;
F_4 ( V_2 [ V_1 ] . V_5 , V_1 ) ;
}
static T_1 F_5 ( T_2 V_6 , T_3 V_7 )
{
unsigned long V_8 = V_6 * V_7 ;
unsigned long V_9 = ( V_8 / V_10 ) +
( V_8 % V_10 != 0 ) ;
return V_9 * V_10 / V_7 ;
}
static inline T_1 F_6 ( T_2 V_11 , T_3 V_7 )
{
return ( V_12 - V_11 ) * V_13 *
V_7 ;
}
void F_7 ( void )
{
int V_14 ;
unsigned long V_15 = V_16 ;
for ( V_14 = F_8 ( V_15 ) ; V_14 ; V_14 = F_8 ( V_15 ) ) {
V_14 -- ;
V_15 &= ~ ( 1 << V_14 ) ;
F_1 ( V_14 ) ;
}
}
void F_9 ( T_2 * V_6 , T_2 * V_17 ,
T_3 V_7 )
{
* V_6 = F_10 ( * V_6 * V_7 , V_10 ) / V_7 ;
* V_17 = F_10 ( * V_17 , V_13 ) ;
}
T_1 F_11 ( T_2 V_6 , T_2 V_17 , T_3 V_7 )
{
unsigned long V_11 = F_5 ( V_6 ,
V_7 ) ;
if ( V_11 > V_12 )
return 0 ;
return ( V_6 * V_17 * V_7 ) + F_6 (
V_11 , V_7 ) ;
}
T_2 F_12 ( T_1 V_18 , T_2 V_6 , T_3 V_7 )
{
unsigned long V_11 = F_5 ( V_6 ,
V_7 ) ;
unsigned long V_17 ;
unsigned long V_19 ;
if ( V_11 > V_12 )
return 0 ;
V_19 = F_6 ( V_11 , V_7 ) ;
if ( V_18 < V_19 )
return 0 ;
V_17 = ( V_18 - V_19 ) / ( V_6 * V_7 ) ;
return F_13 (unsigned long, height, 2048 ) ;
}
void F_14 ( struct V_20 * V_20 , unsigned long V_21 ,
T_2 V_6 , T_2 V_17 ,
unsigned V_7 , bool V_22 )
{
unsigned V_23 ;
T_2 V_24 ;
T_2 V_25 ;
T_3 V_1 = V_20 -> V_26 ;
T_1 V_4 ;
T_1 V_3 ;
F_15 ( L_1 , V_1 , V_21 ,
V_6 , V_17 , V_7 , V_22 ) ;
if ( V_22 ) {
V_7 *= 2 ;
V_6 /= 2 ;
}
if ( V_7 == 4 )
V_23 = 2 ;
else if ( V_7 == 2 )
V_23 = 1 ;
else {
F_16 () ;
return;
}
V_24 = F_10 ( V_6 * V_7 , V_10 ) / V_7 ;
V_25 = F_10 ( V_17 , V_13 ) ;
F_15 ( L_2 , V_24 , V_25 , V_7 ) ;
V_4 = V_24 << V_27 ;
V_4 |= V_25 << V_28 ;
V_3 = V_23 << V_29 ;
V_3 |= V_30 << V_31 ;
V_3 |= V_32 << V_33 ;
V_2 [ V_1 ] . V_5 = V_21 ;
V_2 [ V_1 ] . V_4 = V_4 ;
V_2 [ V_1 ] . V_3 = V_3 ;
F_4 ( V_21 , V_1 ) ;
F_3 ( V_4 , V_1 ) ;
F_2 ( V_3 , V_1 ) ;
F_15 ( L_3 ,
V_24 - V_6 , V_25 - V_17 ) ;
V_20 -> V_34 = V_6 ;
V_20 -> V_35 = V_17 ;
V_20 -> V_36 = V_24 - V_6 ;
V_20 -> V_37 = V_25 - V_17 ;
V_20 -> V_7 = V_7 ;
V_20 -> V_22 = V_22 ;
}
int F_17 ( struct V_20 * V_20 , T_2 V_17 , T_3 V_38 )
{
unsigned long V_4 = V_17 * V_12 * V_20 -> V_7 ;
V_20 -> V_39 [ V_38 ] = F_18 ( V_20 -> V_21 [ V_38 ] , V_4 ) ;
if ( ! V_20 -> V_39 [ V_38 ] ) {
F_19 ( V_40 L_4 ) ;
return - V_41 ;
}
F_15 ( L_5 , V_38 , V_4 ,
V_20 -> V_39 [ V_38 ] ) ;
return 0 ;
}
void F_20 ( struct V_20 * V_20 )
{
int V_38 ;
int V_1 = V_20 -> V_26 ;
if ( V_1 == 0xff )
return;
F_15 ( L_6 , V_1 ) ;
F_21 ( & V_42 ) ;
F_22 ( ! ( V_16 & ( 1 << V_1 ) ) ) ;
F_23 ( V_1 , & V_16 ) ;
for ( V_38 = 0 ; V_38 < 4 ; ++ V_38 ) {
if ( V_20 -> V_21 [ V_38 ] ) {
F_24 ( V_20 -> V_21 [ V_38 ] , V_43 ) ;
V_20 -> V_21 [ V_38 ] = 0 ;
}
}
V_20 -> V_26 = 0xff ;
F_25 ( & V_42 ) ;
}
int F_26 ( struct V_20 * V_20 )
{
int V_38 ;
T_1 V_21 ;
T_3 V_1 ;
int V_44 ;
F_15 ( L_7 ) ;
F_21 ( & V_42 ) ;
for ( V_1 = 0 ; V_1 < V_45 ; ++ V_1 )
if ( ( V_16 & ( 1 << V_1 ) ) == 0 )
break;
if ( V_1 == V_45 ) {
F_27 ( L_8 ) ;
V_44 = - V_46 ;
goto V_47;
}
F_15 ( L_9 , V_1 ) ;
F_28 ( V_1 , & V_16 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_26 = V_1 ;
for ( V_38 = 0 ; V_38 < 4 ; ++ V_38 ) {
V_21 = F_29 ( V_1 , V_38 ) ;
if ( ! F_30 ( V_21 , V_43 , L_10 ) ) {
F_27 ( L_11
L_12 ,
V_1 , V_38 * 90 ) ;
F_20 ( V_20 ) ;
V_44 = - V_41 ;
goto V_47;
}
V_20 -> V_21 [ V_38 ] = V_21 ;
F_15 ( L_13 , V_1 , V_38 * 90 , V_20 -> V_21 [ V_38 ] ) ;
}
V_44 = 0 ;
V_47:
F_25 ( & V_42 ) ;
return V_44 ;
}
