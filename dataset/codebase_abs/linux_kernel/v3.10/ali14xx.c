static inline T_1 F_1 ( T_1 V_1 )
{
F_2 ( V_1 , V_2 ) ;
return F_3 ( V_3 ) ;
}
static void F_4 ( T_1 V_4 , T_1 V_1 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_3 ) ;
}
static void F_5 ( T_2 * V_5 , T_3 * V_6 )
{
int V_7 ;
int V_8 , V_9 ;
T_1 V_10 , V_11 , V_12 , V_13 ;
unsigned long V_14 ;
int V_15 = V_16 ? V_16 : 50 ;
const T_1 V_17 = V_6 -> V_18 - V_19 ;
struct V_20 * V_21 = F_6 ( V_19 + V_17 ) ;
V_8 = F_7 ( V_6 , V_17 ) ;
V_9 = V_21 -> V_22 ;
V_12 = V_10 = ( V_9 * V_15 + 999 ) / 1000 ;
V_13 = V_11 = ( V_8 * V_15 + 999 ) / 1000 - V_10 ;
if ( V_17 < 3 ) {
V_12 += 8 ;
V_13 += 8 ;
}
F_8 ( V_23 L_1 ,
V_6 -> V_24 , V_17 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ) ;
V_7 = ( V_6 -> V_5 -> V_25 << 1 ) + ( V_6 -> V_26 & 1 ) ;
F_9 ( & V_27 , V_14 ) ;
F_2 ( V_28 , V_29 ) ;
F_4 ( V_10 , V_30 [ V_7 ] . V_31 ) ;
F_4 ( V_11 , V_30 [ V_7 ] . V_32 ) ;
F_4 ( V_12 , V_30 [ V_7 ] . V_33 ) ;
F_4 ( V_13 , V_30 [ V_7 ] . V_34 ) ;
F_2 ( V_35 , V_29 ) ;
F_10 ( & V_27 , V_14 ) ;
}
static int T_4 F_11 ( void )
{
int V_36 ;
T_1 V_21 ;
unsigned long V_14 ;
F_12 ( V_14 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; ++ V_36 ) {
V_29 = V_38 [ V_36 ] ;
V_35 = F_3 ( V_29 ) ;
for ( V_28 = 0x30 ; V_28 <= 0x33 ; ++ V_28 ) {
F_2 ( V_28 , V_29 ) ;
if ( F_3 ( V_29 ) == V_28 ) {
V_2 = V_29 + 4 ;
V_3 = V_29 + 8 ;
V_21 = F_1 ( 0 ) & 0xf0 ;
F_2 ( V_35 , V_29 ) ;
F_13 ( V_14 ) ;
if ( V_21 != 0x50 )
return 0 ;
return 1 ;
}
}
F_2 ( V_35 , V_29 ) ;
}
F_13 ( V_14 ) ;
return 0 ;
}
static int T_4 F_14 ( void )
{
const T_5 * V_39 ;
T_1 V_21 ;
unsigned long V_14 ;
F_12 ( V_14 ) ;
F_2 ( V_28 , V_29 ) ;
for ( V_39 = V_40 ; V_39 -> V_1 != 0 ; ++ V_39 )
F_4 ( V_39 -> V_4 , V_39 -> V_1 ) ;
F_2 ( 0x01 , V_2 ) ;
V_21 = F_3 ( V_2 ) & 0x01 ;
F_2 ( V_35 , V_29 ) ;
F_13 ( V_14 ) ;
return V_21 ;
}
static int T_4 F_15 ( void )
{
F_8 ( V_23 L_2 ,
V_29 , V_28 ) ;
if ( ! F_14 () ) {
F_8 ( V_41 L_3 ) ;
return 1 ;
}
return F_16 ( & V_42 , 0 ) ;
}
static int T_4 F_17 ( void )
{
if ( V_43 == 0 )
goto V_44;
if ( F_11 () ) {
if ( F_15 () )
return - V_45 ;
return 0 ;
}
F_8 ( V_41 L_4 ) ;
V_44:
return - V_45 ;
}
