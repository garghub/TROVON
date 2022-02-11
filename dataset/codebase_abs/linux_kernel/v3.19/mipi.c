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
struct V_6 * F_5 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_6 * V_11 ;
struct V_12 args ;
int V_13 ;
V_13 = F_6 ( V_9 , L_1 ,
L_2 , 0 ,
& args ) ;
if ( V_13 < 0 )
return F_7 ( V_13 ) ;
V_11 = F_8 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 ) {
V_13 = - V_15 ;
goto V_16;
}
V_11 -> V_17 = F_9 ( args . V_9 ) ;
if ( ! V_11 -> V_17 ) {
V_13 = - V_18 ;
goto free;
}
V_11 -> V_2 = F_10 ( V_11 -> V_17 ) ;
if ( ! V_11 -> V_2 ) {
V_13 = - V_19 ;
goto V_20;
}
F_11 ( args . V_9 ) ;
V_11 -> V_21 = args . args [ 0 ] ;
V_11 -> V_7 = V_7 ;
return V_11 ;
V_20:
F_12 ( V_11 -> V_17 ) ;
free:
F_13 ( V_11 ) ;
V_16:
F_11 ( args . V_9 ) ;
return F_7 ( V_13 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
F_12 ( V_7 -> V_17 ) ;
F_13 ( V_7 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_22 = V_23 + F_16 ( 250 ) ;
T_1 V_5 ;
while ( F_17 ( V_23 , V_22 ) ) {
V_5 = F_1 ( V_2 , V_24 ) ;
if ( ( V_5 & V_25 ) == 0 &&
( V_5 & V_26 ) != 0 )
return 0 ;
F_18 ( 10 , 50 ) ;
}
return - V_27 ;
}
int F_19 ( struct V_6 * V_7 )
{
const struct V_28 * V_29 = V_7 -> V_2 -> V_29 ;
unsigned int V_30 ;
T_1 V_5 ;
int V_13 ;
V_13 = F_20 ( V_7 -> V_2 -> V_31 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_7 -> V_2 -> V_32 ) ;
V_5 = F_1 ( V_7 -> V_2 , V_33 ) ;
V_5 &= ~ V_34 ;
V_5 |= V_35 ;
F_3 ( V_7 -> V_2 , V_5 , V_33 ) ;
F_3 ( V_7 -> V_2 , F_22 ( 2 ) ,
V_36 ) ;
V_5 = F_1 ( V_7 -> V_2 , V_37 ) ;
V_5 &= ~ V_38 ;
F_3 ( V_7 -> V_2 , V_5 , V_37 ) ;
for ( V_30 = 0 ; V_30 < V_29 -> V_39 ; V_30 ++ ) {
T_1 V_31 = 0 , V_40 = 0 ;
if ( V_7 -> V_21 & F_23 ( V_30 ) ) {
V_40 = V_41 |
F_24 ( 0 ) |
F_25 ( 4 ) |
F_26 ( 5 ) ;
V_31 = V_41 |
F_27 ( 0 ) |
F_28 ( 4 ) ;
}
F_3 ( V_7 -> V_2 , V_40 , V_29 -> V_21 [ V_30 ] . V_40 ) ;
if ( V_29 -> V_42 )
F_3 ( V_7 -> V_2 , V_31 , V_29 -> V_21 [ V_30 ] . V_31 ) ;
}
V_5 = F_1 ( V_7 -> V_2 , V_43 ) ;
V_5 |= V_44 ;
F_3 ( V_7 -> V_2 , V_5 , V_43 ) ;
V_13 = F_15 ( V_7 -> V_2 ) ;
F_29 ( & V_7 -> V_2 -> V_32 ) ;
F_30 ( V_7 -> V_2 -> V_31 ) ;
return V_13 ;
}
static int F_31 ( struct V_45 * V_17 )
{
const struct V_46 * V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
int V_13 ;
V_47 = F_32 ( V_50 , V_17 -> V_11 . V_10 ) ;
if ( ! V_47 )
return - V_18 ;
V_2 = F_33 ( & V_17 -> V_11 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
V_2 -> V_29 = V_47 -> V_40 ;
V_49 = F_34 ( V_17 , V_51 , 0 ) ;
V_2 -> V_4 = F_35 ( & V_17 -> V_11 , V_49 ) ;
if ( F_36 ( V_2 -> V_4 ) )
return F_37 ( V_2 -> V_4 ) ;
F_38 ( & V_2 -> V_32 ) ;
V_2 -> V_31 = F_39 ( & V_17 -> V_11 , NULL ) ;
if ( F_36 ( V_2 -> V_31 ) ) {
F_40 ( & V_17 -> V_11 , L_3 ) ;
return F_37 ( V_2 -> V_31 ) ;
}
V_13 = F_41 ( V_2 -> V_31 ) ;
if ( V_13 < 0 )
return V_13 ;
F_42 ( V_17 , V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_45 * V_17 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
F_44 ( V_2 -> V_31 ) ;
return 0 ;
}
