static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_6 ( V_2 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_1 ( V_2 , V_8 ) ;
V_5 &= ~ V_9 ;
if ( V_2 -> V_10 -> V_11 )
V_5 |= V_12 ;
F_3 ( V_2 , V_5 , V_8 ) ;
V_5 = F_1 ( V_2 , V_13 ) ;
V_5 &= ~ V_14 ;
F_3 ( V_2 , V_5 , V_13 ) ;
F_7 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_6 ( V_2 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = F_1 ( V_2 , V_13 ) ;
V_5 |= V_14 ;
F_3 ( V_2 , V_5 , V_13 ) ;
V_5 = F_1 ( V_2 , V_8 ) ;
if ( V_2 -> V_10 -> V_11 )
V_5 &= ~ V_12 ;
V_5 |= V_9 ;
F_3 ( V_2 , V_5 , V_8 ) ;
return 0 ;
}
struct V_15 * F_9 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_15 * V_20 ;
struct V_21 args ;
int V_6 ;
V_6 = F_10 ( V_18 , L_1 ,
L_2 , 0 ,
& args ) ;
if ( V_6 < 0 )
return F_11 ( V_6 ) ;
V_20 = F_12 ( sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 ) {
V_6 = - V_23 ;
goto V_24;
}
V_20 -> V_25 = F_13 ( args . V_18 ) ;
if ( ! V_20 -> V_25 ) {
V_6 = - V_26 ;
goto free;
}
V_20 -> V_2 = F_14 ( V_20 -> V_25 ) ;
if ( ! V_20 -> V_2 ) {
V_6 = - V_27 ;
goto V_28;
}
F_15 ( args . V_18 ) ;
V_20 -> V_29 = args . args [ 0 ] ;
V_20 -> V_16 = V_16 ;
return V_20 ;
V_28:
F_16 ( V_20 -> V_25 ) ;
free:
F_17 ( V_20 ) ;
V_24:
F_15 ( args . V_18 ) ;
return F_11 ( V_6 ) ;
}
void F_18 ( struct V_15 * V_16 )
{
F_16 ( V_16 -> V_25 ) ;
F_17 ( V_16 ) ;
}
int F_19 ( struct V_15 * V_20 )
{
int V_6 = 0 ;
F_20 ( & V_20 -> V_2 -> V_30 ) ;
if ( V_20 -> V_2 -> V_31 ++ == 0 )
V_6 = F_5 ( V_20 -> V_2 ) ;
F_21 ( & V_20 -> V_2 -> V_30 ) ;
return V_6 ;
}
int F_22 ( struct V_15 * V_20 )
{
int V_6 = 0 ;
F_20 ( & V_20 -> V_2 -> V_30 ) ;
if ( -- V_20 -> V_2 -> V_31 == 0 )
V_6 = F_8 ( V_20 -> V_2 ) ;
F_21 ( & V_20 -> V_2 -> V_30 ) ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned long V_32 = V_33 + F_24 ( 250 ) ;
T_1 V_5 ;
while ( F_25 ( V_33 , V_32 ) ) {
V_5 = F_1 ( V_2 , V_34 ) ;
if ( ( V_5 & V_35 ) == 0 &&
( V_5 & V_36 ) != 0 )
return 0 ;
F_26 ( 10 , 50 ) ;
}
return - V_37 ;
}
int F_27 ( struct V_15 * V_16 )
{
const struct V_38 * V_10 = V_16 -> V_2 -> V_10 ;
unsigned int V_39 ;
T_1 V_5 ;
int V_6 ;
V_6 = F_6 ( V_16 -> V_2 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
F_20 ( & V_16 -> V_2 -> V_30 ) ;
V_5 = F_28 ( V_10 -> V_40 ) |
F_29 ( V_10 -> V_41 ) ;
F_3 ( V_16 -> V_2 , V_5 , V_42 ) ;
V_5 = F_1 ( V_16 -> V_2 , V_13 ) ;
V_5 &= ~ F_30 ( 0x7 ) ;
V_5 &= ~ F_31 ( 0x7 ) ;
V_5 |= F_30 ( V_10 -> V_43 ) ;
V_5 |= F_31 ( V_10 -> V_44 ) ;
F_3 ( V_16 -> V_2 , V_5 , V_13 ) ;
for ( V_39 = 0 ; V_39 < V_10 -> V_45 ; V_39 ++ ) {
T_1 V_7 = 0 , V_46 = 0 ;
if ( V_16 -> V_29 & F_32 ( V_39 ) ) {
V_46 = V_47 |
F_33 ( V_10 -> V_48 ) |
F_34 ( V_10 -> V_49 ) |
F_35 ( V_10 -> V_50 ) ;
V_7 = V_47 |
F_36 ( V_10 -> V_51 ) |
F_37 ( V_10 -> V_52 ) ;
}
F_3 ( V_16 -> V_2 , V_46 , V_10 -> V_29 [ V_39 ] . V_46 ) ;
if ( V_10 -> V_53 && V_10 -> V_29 [ V_39 ] . V_7 != 0 )
F_3 ( V_16 -> V_2 , V_7 , V_10 -> V_29 [ V_39 ] . V_7 ) ;
}
V_5 = F_1 ( V_16 -> V_2 , V_54 ) ;
V_5 &= ~ F_38 ( 0xf ) ;
V_5 &= ~ F_39 ( 0x3 ) ;
V_5 |= F_38 ( 0xa ) ;
V_5 |= F_39 ( 0x2 ) ;
if ( ! V_10 -> V_55 )
V_5 &= ~ V_56 ;
else
V_5 |= V_56 ;
F_3 ( V_16 -> V_2 , V_5 , V_54 ) ;
V_5 = F_1 ( V_16 -> V_2 , V_34 ) ;
F_3 ( V_16 -> V_2 , V_5 , V_34 ) ;
V_5 = F_1 ( V_16 -> V_2 , V_54 ) ;
V_5 |= V_57 ;
F_3 ( V_16 -> V_2 , V_5 , V_54 ) ;
V_6 = F_23 ( V_16 -> V_2 ) ;
F_21 ( & V_16 -> V_2 -> V_30 ) ;
F_7 ( V_16 -> V_2 -> V_7 ) ;
return V_6 ;
}
static int F_40 ( struct V_58 * V_25 )
{
const struct V_59 * V_60 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
int V_6 ;
V_60 = F_41 ( V_63 , V_25 -> V_20 . V_19 ) ;
if ( ! V_60 )
return - V_26 ;
V_2 = F_42 ( & V_25 -> V_20 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_2 -> V_10 = V_60 -> V_46 ;
V_2 -> V_20 = & V_25 -> V_20 ;
V_62 = F_43 ( V_25 , V_64 , 0 ) ;
V_2 -> V_4 = F_44 ( & V_25 -> V_20 , V_62 ) ;
if ( F_45 ( V_2 -> V_4 ) )
return F_46 ( V_2 -> V_4 ) ;
F_47 ( & V_2 -> V_30 ) ;
V_2 -> V_7 = F_48 ( & V_25 -> V_20 , NULL ) ;
if ( F_45 ( V_2 -> V_7 ) ) {
F_49 ( & V_25 -> V_20 , L_3 ) ;
return F_46 ( V_2 -> V_7 ) ;
}
V_6 = F_50 ( V_2 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
F_51 ( V_25 , V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_58 * V_25 )
{
struct V_1 * V_2 = F_14 ( V_25 ) ;
F_53 ( V_2 -> V_7 ) ;
return 0 ;
}
