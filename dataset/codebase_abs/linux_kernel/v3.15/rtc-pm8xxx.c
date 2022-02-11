static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
unsigned long V_7 , V_8 ;
T_1 V_9 [ V_10 ] , V_11 = 0 , V_12 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( ! V_14 -> V_15 )
return - V_16 ;
F_3 ( V_4 , & V_7 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_9 [ V_6 ] = V_7 & 0xFF ;
V_7 >>= 8 ;
}
F_4 ( V_2 , L_1 , V_7 ) ;
F_5 ( & V_14 -> V_17 , V_8 ) ;
V_12 = V_14 -> V_12 ;
if ( V_12 & V_18 ) {
V_11 = 1 ;
V_12 &= ~ V_18 ;
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_20 , V_12 ) ;
if ( V_5 ) {
F_7 ( V_2 , L_2 ) ;
goto V_21;
}
V_14 -> V_12 = V_12 ;
} else {
F_8 ( & V_14 -> V_17 , V_8 ) ;
}
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_22 , 0 ) ;
if ( V_5 ) {
F_7 ( V_2 , L_3 ) ;
goto V_21;
}
V_5 = F_9 ( V_14 -> V_19 , V_14 -> V_22 + 1 ,
& V_9 [ 1 ] , sizeof( V_9 ) - 1 ) ;
if ( V_5 ) {
F_7 ( V_2 , L_3 ) ;
goto V_21;
}
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_22 , V_9 [ 0 ] ) ;
if ( V_5 ) {
F_7 ( V_2 , L_3 ) ;
goto V_21;
}
if ( V_11 ) {
V_12 |= V_18 ;
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_20 , V_12 ) ;
if ( V_5 ) {
F_7 ( V_2 , L_2 ) ;
goto V_21;
}
V_14 -> V_12 = V_12 ;
}
V_21:
if ( V_11 )
F_8 ( & V_14 -> V_17 , V_8 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
T_1 V_9 [ V_10 ] ;
unsigned long V_7 ;
unsigned int V_23 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
V_5 = F_11 ( V_14 -> V_19 , V_14 -> V_24 ,
V_9 , sizeof( V_9 ) ) ;
if ( V_5 ) {
F_7 ( V_2 , L_4 ) ;
return V_5 ;
}
V_5 = F_12 ( V_14 -> V_19 , V_14 -> V_24 , & V_23 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 , L_4 ) ;
return V_5 ;
}
if ( F_13 ( V_23 < V_9 [ 0 ] ) ) {
V_5 = F_11 ( V_14 -> V_19 , V_14 -> V_24 ,
V_9 , sizeof( V_9 ) ) ;
if ( V_5 ) {
F_7 ( V_2 , L_4 ) ;
return V_5 ;
}
}
V_7 = V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] << 16 ) | ( V_9 [ 3 ] << 24 ) ;
F_14 ( V_7 , V_4 ) ;
V_5 = F_15 ( V_4 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 , L_5 ) ;
return V_5 ;
}
F_4 ( V_2 , L_6 ,
V_7 , V_4 -> V_25 , V_4 -> V_26 , V_4 -> V_27 ,
V_4 -> V_28 , V_4 -> V_29 , V_4 -> V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_5 , V_6 ;
T_1 V_9 [ V_10 ] , V_12 ;
unsigned long V_7 , V_8 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
F_3 ( & V_32 -> time , & V_7 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_9 [ V_6 ] = V_7 & 0xFF ;
V_7 >>= 8 ;
}
F_5 ( & V_14 -> V_17 , V_8 ) ;
V_5 = F_9 ( V_14 -> V_19 , V_14 -> V_33 , V_9 ,
sizeof( V_9 ) ) ;
if ( V_5 ) {
F_7 ( V_2 , L_7 ) ;
goto V_21;
}
V_12 = V_14 -> V_12 ;
if ( V_32 -> V_34 )
V_12 |= V_18 ;
else
V_12 &= ~ V_18 ;
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_20 , V_12 ) ;
if ( V_5 ) {
F_7 ( V_2 , L_2 ) ;
goto V_21;
}
V_14 -> V_12 = V_12 ;
F_4 ( V_2 , L_8 ,
V_32 -> time . V_25 , V_32 -> time . V_26 ,
V_32 -> time . V_27 , V_32 -> time . V_28 ,
V_32 -> time . V_29 , V_32 -> time . V_30 ) ;
V_21:
F_8 ( & V_14 -> V_17 , V_8 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_5 ;
T_1 V_9 [ V_10 ] ;
unsigned long V_7 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
V_5 = F_11 ( V_14 -> V_19 , V_14 -> V_33 , V_9 ,
sizeof( V_9 ) ) ;
if ( V_5 ) {
F_7 ( V_2 , L_9 ) ;
return V_5 ;
}
V_7 = V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] << 16 ) | ( V_9 [ 3 ] << 24 ) ;
F_14 ( V_7 , & V_32 -> time ) ;
V_5 = F_15 ( & V_32 -> time ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 , L_10 ) ;
return V_5 ;
}
F_4 ( V_2 , L_11 ,
V_32 -> time . V_25 , V_32 -> time . V_26 ,
V_32 -> time . V_27 , V_32 -> time . V_28 ,
V_32 -> time . V_29 , V_32 -> time . V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_35 )
{
int V_5 ;
unsigned long V_8 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
T_1 V_12 ;
F_5 ( & V_14 -> V_17 , V_8 ) ;
V_12 = V_14 -> V_12 ;
if ( V_35 )
V_12 |= V_18 ;
else
V_12 &= ~ V_18 ;
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_20 , V_12 ) ;
if ( V_5 ) {
F_7 ( V_2 , L_2 ) ;
goto V_21;
}
V_14 -> V_12 = V_12 ;
V_21:
F_8 ( & V_14 -> V_17 , V_8 ) ;
return V_5 ;
}
static T_2 F_19 ( int V_36 , void * V_37 )
{
struct V_13 * V_14 = V_37 ;
unsigned int V_12 ;
int V_5 ;
unsigned long V_8 ;
F_20 ( V_14 -> V_38 , 1 , V_39 | V_40 ) ;
F_5 ( & V_14 -> V_17 , V_8 ) ;
V_12 = V_14 -> V_12 ;
V_12 &= ~ V_18 ;
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_20 , V_12 ) ;
if ( V_5 ) {
F_8 ( & V_14 -> V_17 , V_8 ) ;
F_7 ( V_14 -> V_41 ,
L_2 ) ;
goto V_42;
}
V_14 -> V_12 = V_12 ;
F_8 ( & V_14 -> V_17 , V_8 ) ;
V_5 = F_12 ( V_14 -> V_19 ,
V_14 -> V_20 + V_43 ,
& V_12 ) ;
if ( V_5 ) {
F_7 ( V_14 -> V_41 ,
L_12 ) ;
goto V_42;
}
V_12 &= ~ V_44 ;
V_5 = F_6 ( V_14 -> V_19 ,
V_14 -> V_20 + V_43 ,
V_12 ) ;
if ( V_5 )
F_7 ( V_14 -> V_41 ,
L_13 ) ;
V_42:
return V_45 ;
}
static int F_21 ( struct V_46 * V_47 )
{
int V_5 ;
unsigned int V_12 ;
struct V_13 * V_14 ;
const struct V_48 * V_49 ;
V_49 = F_22 ( V_50 , V_47 -> V_2 . V_51 ) ;
if ( ! V_49 )
return - V_52 ;
V_14 = F_23 ( & V_47 -> V_2 , sizeof( * V_14 ) , V_53 ) ;
if ( V_14 == NULL )
return - V_54 ;
F_24 ( & V_14 -> V_17 ) ;
V_14 -> V_19 = F_25 ( V_47 -> V_2 . V_55 , NULL ) ;
if ( ! V_14 -> V_19 ) {
F_7 ( & V_47 -> V_2 , L_14 ) ;
return - V_52 ;
}
V_14 -> V_56 = F_26 ( V_47 , 0 ) ;
if ( V_14 -> V_56 < 0 ) {
F_7 ( & V_47 -> V_2 , L_15 ) ;
return - V_52 ;
}
V_14 -> V_15 = F_27 ( V_47 -> V_2 . V_51 ,
L_16 ) ;
V_14 -> V_20 = ( long ) V_49 -> V_57 ;
V_14 -> V_22 = V_14 -> V_20 + V_58 ;
V_14 -> V_24 = V_14 -> V_20 + V_59 ;
V_14 -> V_33 = V_14 -> V_20 + V_60 ;
V_14 -> V_41 = & V_47 -> V_2 ;
V_5 = F_12 ( V_14 -> V_19 , V_14 -> V_20 , & V_12 ) ;
if ( V_5 ) {
F_7 ( & V_47 -> V_2 , L_17 ) ;
return V_5 ;
}
if ( ! ( V_12 & V_61 ) ) {
V_12 |= V_61 ;
V_5 = F_6 ( V_14 -> V_19 , V_14 -> V_20 , V_12 ) ;
if ( V_5 ) {
F_7 ( & V_47 -> V_2 ,
L_2 ) ;
return V_5 ;
}
}
V_14 -> V_12 = V_12 ;
F_28 ( V_47 , V_14 ) ;
F_29 ( & V_47 -> V_2 , 1 ) ;
V_14 -> V_38 = F_30 ( & V_47 -> V_2 , L_18 ,
& V_62 , V_63 ) ;
if ( F_31 ( V_14 -> V_38 ) ) {
F_7 ( & V_47 -> V_2 , L_19 ,
V_64 , F_32 ( V_14 -> V_38 ) ) ;
return F_32 ( V_14 -> V_38 ) ;
}
V_5 = F_33 ( & V_47 -> V_2 , V_14 -> V_56 ,
F_19 ,
V_65 ,
L_20 , V_14 ) ;
if ( V_5 < 0 ) {
F_7 ( & V_47 -> V_2 , L_21 , V_5 ) ;
return V_5 ;
}
F_4 ( & V_47 -> V_2 , L_22 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_35 ( V_2 ) )
F_36 ( V_14 -> V_56 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_35 ( V_2 ) )
F_38 ( V_14 -> V_56 ) ;
return 0 ;
}
