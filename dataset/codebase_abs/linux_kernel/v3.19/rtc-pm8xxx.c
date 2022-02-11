static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
unsigned long V_7 , V_8 ;
T_1 V_9 [ V_10 ] , V_11 = 0 ;
unsigned int V_12 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_17 )
return - V_18 ;
F_3 ( V_4 , & V_7 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_9 [ V_6 ] = V_7 & 0xFF ;
V_7 >>= 8 ;
}
F_4 ( V_2 , L_1 , V_7 ) ;
F_5 ( & V_14 -> V_19 , V_8 ) ;
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_21 , & V_12 ) ;
if ( V_5 )
goto V_22;
if ( V_12 & V_16 -> V_23 ) {
V_11 = 1 ;
V_12 &= ~ V_16 -> V_23 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_21 , V_12 ) ;
if ( V_5 ) {
F_8 ( V_2 , L_2 ) ;
goto V_22;
}
}
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_24 , 0 ) ;
if ( V_5 ) {
F_8 ( V_2 , L_3 ) ;
goto V_22;
}
V_5 = F_9 ( V_14 -> V_20 , V_16 -> V_24 + 1 ,
& V_9 [ 1 ] , sizeof( V_9 ) - 1 ) ;
if ( V_5 ) {
F_8 ( V_2 , L_3 ) ;
goto V_22;
}
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_24 , V_9 [ 0 ] ) ;
if ( V_5 ) {
F_8 ( V_2 , L_3 ) ;
goto V_22;
}
if ( V_11 ) {
V_12 |= V_16 -> V_23 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_21 , V_12 ) ;
if ( V_5 ) {
F_8 ( V_2 , L_2 ) ;
goto V_22;
}
}
V_22:
F_10 ( & V_14 -> V_19 , V_8 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
T_1 V_9 [ V_10 ] ;
unsigned long V_7 ;
unsigned int V_25 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = V_14 -> V_16 ;
V_5 = F_12 ( V_14 -> V_20 , V_16 -> V_26 , V_9 , sizeof( V_9 ) ) ;
if ( V_5 ) {
F_8 ( V_2 , L_4 ) ;
return V_5 ;
}
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_26 , & V_25 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 , L_4 ) ;
return V_5 ;
}
if ( F_13 ( V_25 < V_9 [ 0 ] ) ) {
V_5 = F_12 ( V_14 -> V_20 , V_16 -> V_26 ,
V_9 , sizeof( V_9 ) ) ;
if ( V_5 ) {
F_8 ( V_2 , L_4 ) ;
return V_5 ;
}
}
V_7 = V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] << 16 ) | ( V_9 [ 3 ] << 24 ) ;
F_14 ( V_7 , V_4 ) ;
V_5 = F_15 ( V_4 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 , L_5 ) ;
return V_5 ;
}
F_4 ( V_2 , L_6 ,
V_7 , V_4 -> V_27 , V_4 -> V_28 , V_4 -> V_29 ,
V_4 -> V_30 , V_4 -> V_31 , V_4 -> V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
int V_5 , V_6 ;
T_1 V_9 [ V_10 ] ;
unsigned int V_12 ;
unsigned long V_7 , V_8 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = V_14 -> V_16 ;
F_3 ( & V_34 -> time , & V_7 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_9 [ V_6 ] = V_7 & 0xFF ;
V_7 >>= 8 ;
}
F_5 ( & V_14 -> V_19 , V_8 ) ;
V_5 = F_9 ( V_14 -> V_20 , V_16 -> V_35 , V_9 ,
sizeof( V_9 ) ) ;
if ( V_5 ) {
F_8 ( V_2 , L_7 ) ;
goto V_22;
}
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_36 , & V_12 ) ;
if ( V_5 )
goto V_22;
if ( V_34 -> V_37 )
V_12 |= V_16 -> V_23 ;
else
V_12 &= ~ V_16 -> V_23 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_36 , V_12 ) ;
if ( V_5 ) {
F_8 ( V_2 , L_8 ) ;
goto V_22;
}
F_4 ( V_2 , L_9 ,
V_34 -> time . V_27 , V_34 -> time . V_28 ,
V_34 -> time . V_29 , V_34 -> time . V_30 ,
V_34 -> time . V_31 , V_34 -> time . V_32 ) ;
V_22:
F_10 ( & V_14 -> V_19 , V_8 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
int V_5 ;
T_1 V_9 [ V_10 ] ;
unsigned long V_7 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = V_14 -> V_16 ;
V_5 = F_12 ( V_14 -> V_20 , V_16 -> V_35 , V_9 ,
sizeof( V_9 ) ) ;
if ( V_5 ) {
F_8 ( V_2 , L_10 ) ;
return V_5 ;
}
V_7 = V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] << 16 ) | ( V_9 [ 3 ] << 24 ) ;
F_14 ( V_7 , & V_34 -> time ) ;
V_5 = F_15 ( & V_34 -> time ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 , L_11 ) ;
return V_5 ;
}
F_4 ( V_2 , L_12 ,
V_34 -> time . V_27 , V_34 -> time . V_28 ,
V_34 -> time . V_29 , V_34 -> time . V_30 ,
V_34 -> time . V_31 , V_34 -> time . V_32 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_38 )
{
int V_5 ;
unsigned long V_8 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = V_14 -> V_16 ;
unsigned int V_12 ;
F_5 ( & V_14 -> V_19 , V_8 ) ;
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_36 , & V_12 ) ;
if ( V_5 )
goto V_22;
if ( V_38 )
V_12 |= V_16 -> V_23 ;
else
V_12 &= ~ V_16 -> V_23 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_36 , V_12 ) ;
if ( V_5 ) {
F_8 ( V_2 , L_2 ) ;
goto V_22;
}
V_22:
F_10 ( & V_14 -> V_19 , V_8 ) ;
return V_5 ;
}
static T_2 F_19 ( int V_39 , void * V_40 )
{
struct V_13 * V_14 = V_40 ;
const struct V_15 * V_16 = V_14 -> V_16 ;
unsigned int V_12 ;
int V_5 ;
unsigned long V_8 ;
F_20 ( V_14 -> V_41 , 1 , V_42 | V_43 ) ;
F_5 ( & V_14 -> V_19 , V_8 ) ;
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_36 , & V_12 ) ;
if ( V_5 ) {
F_10 ( & V_14 -> V_19 , V_8 ) ;
goto V_44;
}
V_12 &= ~ V_16 -> V_23 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_36 , V_12 ) ;
if ( V_5 ) {
F_10 ( & V_14 -> V_19 , V_8 ) ;
F_8 ( V_14 -> V_45 ,
L_13 ) ;
goto V_44;
}
F_10 ( & V_14 -> V_19 , V_8 ) ;
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_46 , & V_12 ) ;
if ( V_5 ) {
F_8 ( V_14 -> V_45 ,
L_14 ) ;
goto V_44;
}
V_12 |= V_47 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_46 , V_12 ) ;
if ( V_5 )
F_8 ( V_14 -> V_45 ,
L_15 ) ;
V_44:
return V_48 ;
}
static int F_21 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 = V_14 -> V_16 ;
unsigned int V_12 ;
int V_5 ;
V_5 = F_6 ( V_14 -> V_20 , V_16 -> V_21 , & V_12 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_12 & V_49 ) ) {
V_12 |= V_49 ;
V_5 = F_7 ( V_14 -> V_20 , V_16 -> V_21 , V_12 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_22 ( struct V_50 * V_51 )
{
int V_5 ;
struct V_13 * V_14 ;
const struct V_52 * V_53 ;
V_53 = F_23 ( V_54 , V_51 -> V_2 . V_55 ) ;
if ( ! V_53 )
return - V_56 ;
V_14 = F_24 ( & V_51 -> V_2 , sizeof( * V_14 ) , V_57 ) ;
if ( V_14 == NULL )
return - V_58 ;
F_25 ( & V_14 -> V_19 ) ;
V_14 -> V_20 = F_26 ( V_51 -> V_2 . V_59 , NULL ) ;
if ( ! V_14 -> V_20 ) {
F_8 ( & V_51 -> V_2 , L_16 ) ;
return - V_56 ;
}
V_14 -> V_60 = F_27 ( V_51 , 0 ) ;
if ( V_14 -> V_60 < 0 ) {
F_8 ( & V_51 -> V_2 , L_17 ) ;
return - V_56 ;
}
V_14 -> V_17 = F_28 ( V_51 -> V_2 . V_55 ,
L_18 ) ;
V_14 -> V_16 = V_53 -> V_61 ;
V_14 -> V_45 = & V_51 -> V_2 ;
V_5 = F_21 ( V_14 ) ;
if ( V_5 )
return V_5 ;
F_29 ( V_51 , V_14 ) ;
F_30 ( & V_51 -> V_2 , 1 ) ;
V_14 -> V_41 = F_31 ( & V_51 -> V_2 , L_19 ,
& V_62 , V_63 ) ;
if ( F_32 ( V_14 -> V_41 ) ) {
F_8 ( & V_51 -> V_2 , L_20 ,
V_64 , F_33 ( V_14 -> V_41 ) ) ;
return F_33 ( V_14 -> V_41 ) ;
}
V_5 = F_34 ( & V_51 -> V_2 , V_14 -> V_60 ,
F_19 ,
V_65 ,
L_21 , V_14 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_51 -> V_2 , L_22 , V_5 ) ;
return V_5 ;
}
F_4 ( & V_51 -> V_2 , L_23 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_36 ( V_2 ) )
F_37 ( V_14 -> V_60 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_36 ( V_2 ) )
F_39 ( V_14 -> V_60 ) ;
return 0 ;
}
