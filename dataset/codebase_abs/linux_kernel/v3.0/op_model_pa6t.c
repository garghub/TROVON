static inline T_1 F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case 0 :
return F_2 ( V_2 ) ;
case 1 :
return F_2 ( V_3 ) ;
case 2 :
return F_2 ( V_4 ) ;
case 3 :
return F_2 ( V_5 ) ;
case 4 :
return F_2 ( V_6 ) ;
case 5 :
return F_2 ( V_7 ) ;
default:
F_3 ( V_8 L_1 , V_1 ) ;
return 0 ;
}
}
static inline void F_4 ( unsigned int V_1 , T_1 V_9 )
{
switch ( V_1 ) {
case 0 :
F_5 ( V_2 , V_9 ) ;
break;
case 1 :
F_5 ( V_3 , V_9 ) ;
break;
case 2 :
F_5 ( V_4 , V_9 ) ;
break;
case 3 :
F_5 ( V_5 , V_9 ) ;
break;
case 4 :
F_5 ( V_6 , V_9 ) ;
break;
case 5 :
F_5 ( V_7 , V_9 ) ;
break;
default:
F_3 ( V_8 L_2 , V_1 ) ;
break;
}
}
static int F_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
int V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ )
if ( ! V_11 [ V_15 ] . V_18 ) {
V_13 -> V_19 &= ~ ( 0x1UL << V_15 ) ;
V_13 -> V_19 &= ~ ( 0x1UL << ( V_15 + 12 ) ) ;
F_7 ( L_3 , V_15 ) ;
}
if ( V_13 -> V_20 )
V_13 -> V_19 |= V_21 | V_22 ;
else
V_13 -> V_19 &= ~ ( V_21 | V_22 ) ;
if ( V_13 -> V_23 )
V_13 -> V_19 |= V_24 ;
else
V_13 -> V_19 &= ~ V_24 ;
V_25 = V_13 -> V_19 ;
V_26 = V_13 -> V_27 ;
F_7 ( L_4 , V_13 -> V_19 ) ;
F_7 ( L_5 , V_13 -> V_27 ) ;
for ( V_15 = 0 ; V_15 < V_16 -> V_17 ; V_15 ++ ) {
V_28 [ V_15 ] = ( 0x1UL << 39 ) - V_11 [ V_15 ] . V_29 ;
F_7 ( L_6 ,
V_15 , V_28 [ V_15 ] ) ;
}
return 0 ;
}
static int F_8 ( struct V_10 * V_11 )
{
T_1 V_19 = V_25 ;
T_1 V_27 = V_26 ;
V_19 &= ~ ( 0x3FUL ) ;
F_5 ( V_30 , V_19 ) ;
F_5 ( V_31 , V_27 ) ;
F_7 ( L_7 , F_9 () ,
F_2 ( V_30 ) ) ;
F_7 ( L_8 , F_9 () ,
F_2 ( V_31 ) ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 )
{
int V_1 ;
T_1 V_19 = V_25 | V_32 ;
for ( V_1 = 0 ; V_1 < V_16 -> V_17 ; V_1 ++ )
if ( V_11 [ V_1 ] . V_18 )
F_4 ( V_1 , V_28 [ V_1 ] ) ;
else
F_4 ( V_1 , 0UL ) ;
F_5 ( V_30 , V_19 ) ;
V_33 = 1 ;
F_7 ( L_9 , F_9 () , V_19 ) ;
return 0 ;
}
static void F_11 ( void )
{
T_1 V_19 ;
V_19 = F_2 ( V_30 ) ;
V_19 |= V_34 ;
F_5 ( V_30 , V_19 ) ;
V_33 = 0 ;
F_7 ( L_10 , F_9 () , V_19 ) ;
}
static void F_12 ( struct V_35 * V_36 ,
struct V_10 * V_11 )
{
unsigned long V_37 = F_2 ( V_38 ) ;
int V_39 = F_13 ( V_37 ) ;
T_1 V_9 ;
int V_1 ;
T_1 V_19 ;
V_19 = F_2 ( V_30 ) ;
F_5 ( V_30 , V_19 | V_32 ) ;
for ( V_1 = 0 ; V_1 < V_16 -> V_17 ; V_1 ++ ) {
V_9 = F_1 ( V_1 ) ;
if ( V_9 & ( 0x1UL << 39 ) ) {
if ( V_33 && V_11 [ V_1 ] . V_18 ) {
if ( V_19 & V_40 )
F_14 ( V_37 , V_36 , V_1 , V_39 ) ;
F_4 ( V_1 , V_28 [ V_1 ] ) ;
} else {
F_4 ( V_1 , 0UL ) ;
}
}
}
V_19 = V_25 | V_32 ;
F_5 ( V_30 , V_19 ) ;
}
