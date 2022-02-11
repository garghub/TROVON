static inline void F_1 ( void )
{
F_2 ( 30 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_8 ;
V_3 |= V_9 ;
V_8 = F_5 ( V_7 , & V_3 , 1 , V_4 , V_5 ) ;
F_1 () ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_10 , T_2 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_8 ;
V_10 [ 0 ] |= V_11 ;
V_8 = F_7 ( V_7 , V_10 , V_5 ) ;
F_1 () ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
T_1 V_10 [ 2 ] ;
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = V_12 ;
return F_6 ( V_2 , V_10 , sizeof( V_10 ) ) ;
}
static T_3 F_9 ( struct V_1 * V_2 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 ;
T_1 V_4 [ 1 ] ;
unsigned long V_3 ;
int V_8 ;
V_17 = F_10 ( V_14 , struct V_16 , V_14 ) ;
V_8 = F_11 ( V_17 -> V_18 , 16 , & V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_3 , V_4 , 1 ) ;
if ( V_8 < 0 )
return - V_19 ;
return sprintf ( V_15 , L_1 , V_4 [ 0 ] ) ;
}
static T_3 F_12 ( struct V_1 * V_2 , struct V_13 * V_14 ,
const char * V_15 , T_2 V_20 )
{
struct V_16 * V_17 ;
unsigned long V_3 ;
unsigned long V_12 ;
int V_8 ;
V_17 = F_10 ( V_14 , struct V_16 , V_14 ) ;
V_8 = F_11 ( V_17 -> V_18 , 16 , & V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_15 , 10 , & V_12 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_8 ( V_2 , V_3 , V_12 ) ;
if ( V_8 < 0 )
return - V_19 ;
return V_20 ;
}
static int F_13 ( struct V_1 * V_2 , long * V_21 )
{
int V_8 ;
T_4 V_3 ;
V_8 = F_3 ( V_2 , V_22 , & V_3 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_3 & V_23 )
V_3 <<= 1 ;
else
V_3 = F_14 ( V_3 , V_24 ) ;
* V_21 = ( ( long ) V_3 ) * V_25 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , long V_21 )
{
T_4 V_3 ;
if ( V_21 > V_25 * 127 )
V_3 = 127 ;
else if ( V_21 < V_25 * - 128 )
V_3 = - 128 ;
else
V_3 = ( T_4 ) ( ( V_21 + ( V_25 >> 1 ) ) / V_25 ) ;
if ( V_3 & 1 && V_3 <= 63 && V_3 >= - 64 ) {
V_3 &= ~ V_23 ;
} else {
V_3 >>= 1 ;
V_3 |= V_23 ;
}
return F_8 ( V_2 , V_22 , V_3 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
T_1 V_4 [ 7 ] ;
int V_8 ;
V_8 = F_3 ( V_2 , V_28 , V_4 , sizeof( V_4 ) ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_4 [ 0 ] & V_29 ) {
F_17 ( V_2 , L_2 ) ;
return - V_30 ;
}
V_27 -> V_31 = F_18 ( V_4 [ 0 ] & 0x7F ) ;
V_27 -> V_32 = F_18 ( V_4 [ 1 ] & 0x7F ) ;
V_27 -> V_33 = F_18 ( V_4 [ 2 ] & 0x3F ) ;
V_27 -> V_34 = F_18 ( V_4 [ 3 ] & 0x3F ) ;
V_27 -> V_35 = V_4 [ 4 ] & 0x07 ;
V_27 -> V_36 = F_18 ( V_4 [ 5 ] & 0x1F ) - 1 ;
V_27 -> V_37 = F_18 ( V_4 [ 6 ] ) ;
if ( V_27 -> V_37 < 70 )
V_27 -> V_37 += 100 ;
F_19 ( V_2 , L_3
L_4 ,
V_38 ,
V_27 -> V_31 , V_27 -> V_32 , V_27 -> V_33 ,
V_27 -> V_34 , V_27 -> V_36 , V_27 -> V_37 , V_27 -> V_35 ) ;
return F_20 ( V_27 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
T_1 V_10 [ 8 ] ;
int V_8 ;
F_19 ( V_2 , L_3
L_4 ,
V_38 ,
V_27 -> V_31 , V_27 -> V_32 , V_27 -> V_33 ,
V_27 -> V_34 , V_27 -> V_36 , V_27 -> V_37 , V_27 -> V_35 ) ;
V_8 = F_8 ( V_2 , V_39 , V_40 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 [ 0 ] = V_28 ;
V_10 [ 1 ] = F_22 ( V_27 -> V_31 & 0x7F ) ;
V_10 [ 2 ] = F_22 ( V_27 -> V_32 & 0x7F ) ;
V_10 [ 3 ] = F_22 ( V_27 -> V_33 & 0x3F ) ;
V_10 [ 4 ] = F_22 ( V_27 -> V_34 & 0x3F ) ;
V_10 [ 5 ] = V_27 -> V_35 & 0x07 ;
V_10 [ 6 ] = F_22 ( ( V_27 -> V_36 + 1 ) & 0x1F ) ;
V_10 [ 7 ] = F_22 ( V_27 -> V_37 < 100 ? V_27 -> V_37 : V_27 -> V_37 - 100 ) ;
V_8 = F_6 ( V_2 , V_10 , sizeof( V_10 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_2 , V_39 , V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_4 [ 2 ] ;
V_8 = F_8 ( V_2 , V_39 , V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
F_19 ( V_2 , L_5 ) ;
V_8 = F_8 ( V_2 , V_39 , V_40 ) ;
if ( V_8 < 0 )
return V_8 ;
F_19 ( V_2 , L_6 ) ;
V_8 = F_3 ( V_2 , V_39 , V_4 , sizeof( V_4 ) ) ;
if ( V_8 < 0 )
return V_8 ;
F_19 ( V_2 , L_7 ,
V_4 [ 0 ] , V_4 [ 1 ] ) ;
if ( ! ( V_4 [ 0 ] & V_40 ) )
return - V_43 ;
V_8 = F_8 ( V_2 , V_39 , V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_44 * V_45 ;
struct V_26 V_27 ;
struct V_46 * V_47 ;
int V_8 , V_48 ;
V_47 = F_25 ( & V_7 -> V_2 , sizeof( struct V_46 ) ,
V_49 ) ;
if ( ! V_47 )
return - V_50 ;
V_7 -> V_2 . V_51 = V_47 ;
V_8 = F_16 ( & V_7 -> V_2 , & V_27 ) ;
if ( V_8 < 0 ) {
V_8 = F_23 ( & V_7 -> V_2 ) ;
if ( V_8 < 0 ) {
F_26 ( & V_7 -> V_2 , L_8 ) ;
goto V_52;
}
}
F_17 ( & V_7 -> V_2 , L_9 ,
( V_7 -> V_53 + 500 ) / 1000 ) ;
V_45 = F_27 ( & V_7 -> V_2 , V_54 . V_55 . V_18 ,
& V_56 , V_57 ) ;
if ( F_28 ( V_45 ) ) {
F_26 ( & V_7 -> V_2 , L_10 ) ;
V_8 = F_29 ( V_45 ) ;
goto V_52;
}
V_47 -> V_45 = V_45 ;
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ ) {
F_30 ( & V_47 -> V_58 [ V_48 ] . V_14 . V_14 ) ;
sprintf ( V_47 -> V_58 [ V_48 ] . V_18 , L_11 , V_48 ) ;
V_47 -> V_58 [ V_48 ] . V_14 . V_14 . V_59 = V_60 | V_61 ;
V_47 -> V_58 [ V_48 ] . V_14 . V_14 . V_18 = V_47 -> V_58 [ V_48 ] . V_18 ;
V_47 -> V_58 [ V_48 ] . V_14 . V_62 = F_9 ;
V_47 -> V_58 [ V_48 ] . V_14 . V_63 = F_12 ;
V_8 = F_31 ( & V_7 -> V_2 , & V_47 -> V_58 [ V_48 ] . V_14 ) ;
if ( V_8 ) {
F_26 ( & V_7 -> V_2 , L_12 ,
V_47 -> V_58 [ V_48 ] . V_18 ) ;
goto V_64;
}
}
return 0 ;
V_64:
for ( V_48 -- ; V_48 >= 0 ; V_48 -- )
F_32 ( & V_7 -> V_2 , & V_47 -> V_58 [ V_48 ] . V_14 ) ;
V_52:
V_7 -> V_2 . V_51 = NULL ;
return V_8 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = F_34 ( & V_7 -> V_2 ) ;
int V_48 ;
if ( V_47 ) {
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
if ( V_47 -> V_58 [ V_48 ] . V_18 [ 0 ] )
F_32 ( & V_7 -> V_2 ,
& V_47 -> V_58 [ V_48 ] . V_14 ) ;
}
return 0 ;
}
