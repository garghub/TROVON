static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) == V_2 -> V_4 ;
}
static int F_3 ( struct V_5 * V_2 , struct V_6 * V_7 )
{
struct V_1 * V_8 = F_4 ( V_2 ) ;
unsigned long V_9 ;
unsigned long V_10 ;
F_5 ( V_9 ) ;
V_10 = F_6 ( V_11 ) ;
V_10 |= F_7 ( V_8 ) ;
F_8 ( V_10 , V_11 ) ;
F_9 ( V_9 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_2 , struct V_6 * V_7 )
{
struct V_1 * V_8 = F_4 ( V_2 ) ;
unsigned long V_9 ;
unsigned long V_10 ;
F_5 ( V_9 ) ;
V_10 = F_6 ( V_11 ) ;
V_10 &= ~ F_7 ( V_8 ) ;
F_8 ( V_10 , V_11 ) ;
F_9 ( V_9 ) ;
}
static unsigned long F_11 ( struct V_1 * V_8 , unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int div ;
V_13 = F_12 ( F_2 ( V_8 -> V_4 ) ) ;
F_13 ( V_8 , L_1 , V_13 ) ;
for ( div = 2 ; div <= 16 ; div *= 2 ) {
if ( ( V_13 / ( div << 16 ) ) < V_12 )
return V_13 / div ;
}
return V_13 / 16 ;
}
static int F_14 ( struct V_5 * V_2 , struct V_6 * V_7 ,
int V_14 , int V_15 )
{
struct V_1 * V_8 = F_4 ( V_2 ) ;
unsigned long V_16 ;
unsigned long V_17 ;
unsigned long V_18 ;
unsigned long V_9 ;
unsigned long V_10 ;
unsigned long V_19 ;
long V_20 ;
if ( V_15 > V_21 || V_14 > V_21 )
return - V_22 ;
if ( V_14 > V_15 )
return - V_23 ;
if ( V_15 == V_8 -> V_15 &&
V_14 == V_8 -> V_14 )
return 0 ;
V_20 = F_6 ( F_15 ( V_8 -> V_24 ) ) ;
V_19 = F_6 ( F_16 ( V_8 -> V_24 ) ) ;
V_18 = V_21 / V_15 ;
F_13 ( V_8 , L_2 ,
V_14 , V_15 , V_18 ) ;
if ( V_8 -> V_15 != V_15 ) {
if ( F_1 ( V_8 ) ) {
V_16 = F_11 ( V_8 , V_18 ) ;
F_17 ( V_8 -> V_4 , V_16 ) ;
} else
V_16 = F_12 ( V_8 -> V_3 ) ;
V_8 -> V_15 = V_15 ;
F_13 ( V_8 , L_3 , V_16 ) ;
V_17 = V_21 / V_16 ;
V_19 = V_15 / V_17 ;
} else
V_17 = V_21 / F_12 ( V_8 -> V_3 ) ;
V_20 = V_14 / V_17 ;
V_20 = V_19 - V_20 ;
if ( V_20 == V_19 )
V_20 -- ;
F_13 ( V_8 , L_4 , V_17 , V_20 , V_19 ) ;
if ( V_20 < 0 )
V_20 = 0 ;
F_5 ( V_9 ) ;
F_8 ( V_20 , F_15 ( V_8 -> V_24 ) ) ;
F_8 ( V_19 , F_16 ( V_8 -> V_24 ) ) ;
V_10 = F_6 ( V_11 ) ;
V_10 |= F_18 ( V_8 ) ;
V_10 |= F_19 ( V_8 ) ;
F_8 ( V_10 , V_11 ) ;
V_10 &= ~ F_18 ( V_8 ) ;
F_8 ( V_10 , V_11 ) ;
F_9 ( V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_1 * V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
unsigned int V_29 = V_26 -> V_29 ;
int V_30 ;
if ( V_29 == 4 ) {
F_21 ( V_28 , L_5 ) ;
return - V_31 ;
}
V_8 = F_22 ( & V_26 -> V_28 , sizeof( * V_8 ) , V_32 ) ;
if ( V_8 == NULL ) {
F_21 ( V_28 , L_6 ) ;
return - V_33 ;
}
V_8 -> V_34 = V_29 == 0 ? 0 : ( V_29 * 4 ) + 4 ;
V_8 -> V_2 . V_28 = & V_26 -> V_28 ;
V_8 -> V_2 . V_35 = & V_36 ;
V_8 -> V_2 . V_37 = - 1 ;
V_8 -> V_2 . V_38 = 1 ;
V_8 -> V_3 = F_23 ( V_28 , L_7 ) ;
if ( F_24 ( V_8 -> V_3 ) ) {
F_21 ( V_28 , L_8 ) ;
return F_25 ( V_8 -> V_3 ) ;
}
V_8 -> V_4 = F_23 ( V_28 , L_9 ) ;
if ( F_24 ( V_8 -> V_4 ) ) {
F_21 ( V_28 , L_10 ) ;
return F_25 ( V_8 -> V_4 ) ;
}
F_26 ( V_8 -> V_3 ) ;
F_26 ( V_8 -> V_4 ) ;
F_5 ( V_9 ) ;
V_10 = F_6 ( V_11 ) ;
V_10 |= F_27 ( V_8 ) ;
F_8 ( V_10 , V_11 ) ;
F_9 ( V_9 ) ;
V_30 = F_28 ( & V_8 -> V_2 ) ;
if ( V_30 < 0 ) {
F_21 ( V_28 , L_11 ) ;
goto V_39;
}
F_13 ( V_8 , L_12 ,
( F_6 ( V_11 ) >> V_8 -> V_34 ) & 0x0f ) ;
F_29 ( V_28 , L_13 ,
F_12 ( V_8 -> V_3 ) ,
F_12 ( V_8 -> V_4 ) ,
F_1 ( V_8 ) ? L_14 : L_15 , V_8 -> V_34 ) ;
F_30 ( V_26 , V_8 ) ;
return 0 ;
V_39:
F_31 ( V_8 -> V_4 ) ;
F_31 ( V_8 -> V_3 ) ;
return V_30 ;
}
static int T_1 F_32 ( struct V_25 * V_26 )
{
struct V_1 * V_8 = F_33 ( V_26 ) ;
int V_40 ;
V_40 = F_34 ( & V_8 -> V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
F_31 ( V_8 -> V_4 ) ;
F_31 ( V_8 -> V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_26 , T_2 V_41 )
{
struct V_1 * V_8 = F_33 ( V_26 ) ;
V_8 -> V_15 = 0 ;
V_8 -> V_14 = 0 ;
return 0 ;
}
static int F_36 ( struct V_25 * V_26 )
{
struct V_1 * V_8 = F_33 ( V_26 ) ;
unsigned long V_10 ;
V_10 = F_6 ( V_11 ) ;
V_10 |= F_27 ( V_8 ) ;
F_8 ( V_10 , V_11 ) ;
return 0 ;
}
static int T_3 F_37 ( void )
{
int V_30 ;
V_42 [ 0 ] = F_38 ( NULL , L_16 ) ;
V_42 [ 1 ] = F_38 ( NULL , L_17 ) ;
if ( F_24 ( V_42 [ 0 ] ) || F_24 ( V_42 [ 1 ] ) ) {
F_39 ( L_18 ) ;
return - V_23 ;
}
V_30 = F_40 ( & V_43 ) ;
if ( V_30 )
F_39 ( L_19 ) ;
return V_30 ;
}
