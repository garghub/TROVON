static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
int V_4 , int V_5 )
{
int V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_10 -> V_9 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 = F_2 ( V_9 , V_4 + V_6 , & V_3 [ V_6 ] ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_1 ) ;
return V_7 ;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
int V_4 , int V_5 )
{
int V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_10 -> V_9 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 = F_5 ( V_9 , V_4 + V_6 , V_3 [ V_6 ] ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
return V_7 ;
}
}
return 0 ;
}
static int F_6 ( struct V_8 * V_11 , struct V_12 * V_13 )
{
int V_7 , V_6 ;
unsigned long V_14 , V_15 ;
T_1 V_16 [ V_17 ] , V_18 = 0 , V_19 = 0 , V_20 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_8 ( V_13 , & V_14 ) ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
V_16 [ V_6 ] = V_14 & 0xFF ;
V_14 >>= 8 ;
}
F_9 ( V_11 , L_3 , V_14 ) ;
F_10 ( & V_2 -> V_21 , V_15 ) ;
V_20 = V_2 -> V_20 ;
if ( V_20 & V_22 ) {
V_19 = 1 ;
V_20 &= ~ V_22 ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 ,
1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_4
L_5 ) ;
goto V_24;
}
V_2 -> V_20 = V_20 ;
} else
F_11 ( & V_2 -> V_21 , V_15 ) ;
V_18 = 0 ;
V_7 = F_4 ( V_2 , & V_18 , V_2 -> V_25 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_6 ) ;
goto V_24;
}
V_7 = F_4 ( V_2 , V_16 + 1 ,
V_2 -> V_25 + 1 , 3 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_6 ) ;
goto V_24;
}
V_7 = F_4 ( V_2 , V_16 , V_2 -> V_25 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_6 ) ;
goto V_24;
}
if ( V_19 ) {
V_20 |= V_22 ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 ,
1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_4
L_5 ) ;
goto V_24;
}
V_2 -> V_20 = V_20 ;
}
V_24:
if ( V_19 )
F_11 ( & V_2 -> V_21 , V_15 ) ;
return V_7 ;
}
static int F_12 ( struct V_8 * V_11 , struct V_12 * V_13 )
{
int V_7 ;
T_1 V_16 [ V_17 ] , V_18 ;
unsigned long V_14 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
V_7 = F_1 ( V_2 , V_16 , V_2 -> V_26 ,
V_17 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_7 ) ;
return V_7 ;
}
V_7 = F_1 ( V_2 , & V_18 , V_2 -> V_26 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_7 ) ;
return V_7 ;
}
if ( F_13 ( V_18 < V_16 [ 0 ] ) ) {
V_7 = F_1 ( V_2 , V_16 ,
V_2 -> V_26 , V_17 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_7 ) ;
return V_7 ;
}
}
V_14 = V_16 [ 0 ] | ( V_16 [ 1 ] << 8 ) | ( V_16 [ 2 ] << 16 ) | ( V_16 [ 3 ] << 24 ) ;
F_14 ( V_14 , V_13 ) ;
V_7 = F_15 ( V_13 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_8 ) ;
return V_7 ;
}
F_9 ( V_11 , L_9 ,
V_14 , V_13 -> V_27 , V_13 -> V_28 , V_13 -> V_29 ,
V_13 -> V_30 , V_13 -> V_31 , V_13 -> V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_11 , struct V_33 * V_34 )
{
int V_7 , V_6 ;
T_1 V_16 [ V_17 ] , V_20 ;
unsigned long V_14 , V_15 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_8 ( & V_34 -> time , & V_14 ) ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
V_16 [ V_6 ] = V_14 & 0xFF ;
V_14 >>= 8 ;
}
F_10 ( & V_2 -> V_21 , V_15 ) ;
V_7 = F_4 ( V_2 , V_16 , V_2 -> V_35 ,
V_17 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_10 ) ;
goto V_24;
}
V_20 = V_2 -> V_20 ;
V_20 = V_34 -> V_36 ? ( V_20 | V_22 ) :
( V_20 & ~ V_22 ) ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_11 ) ;
goto V_24;
}
V_2 -> V_20 = V_20 ;
F_9 ( V_11 , L_12 ,
V_34 -> time . V_27 , V_34 -> time . V_28 ,
V_34 -> time . V_29 , V_34 -> time . V_30 ,
V_34 -> time . V_31 , V_34 -> time . V_32 ) ;
V_24:
F_11 ( & V_2 -> V_21 , V_15 ) ;
return V_7 ;
}
static int F_17 ( struct V_8 * V_11 , struct V_33 * V_34 )
{
int V_7 ;
T_1 V_16 [ V_17 ] ;
unsigned long V_14 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
V_7 = F_1 ( V_2 , V_16 , V_2 -> V_35 ,
V_17 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_13 ) ;
return V_7 ;
}
V_14 = V_16 [ 0 ] | ( V_16 [ 1 ] << 8 ) | ( V_16 [ 2 ] << 16 ) | ( V_16 [ 3 ] << 24 ) ;
F_14 ( V_14 , & V_34 -> time ) ;
V_7 = F_15 ( & V_34 -> time ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_14 ) ;
return V_7 ;
}
F_9 ( V_11 , L_15 ,
V_34 -> time . V_27 , V_34 -> time . V_28 ,
V_34 -> time . V_29 , V_34 -> time . V_30 ,
V_34 -> time . V_31 , V_34 -> time . V_32 ) ;
return 0 ;
}
static int F_18 ( struct V_8 * V_11 , unsigned int V_37 )
{
int V_7 ;
unsigned long V_15 ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
T_1 V_20 ;
F_10 ( & V_2 -> V_21 , V_15 ) ;
V_20 = V_2 -> V_20 ;
V_20 = ( V_37 ) ? ( V_20 | V_22 ) :
( V_20 & ~ V_22 ) ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_11 , L_11 ) ;
goto V_24;
}
V_2 -> V_20 = V_20 ;
V_24:
F_11 ( & V_2 -> V_21 , V_15 ) ;
return V_7 ;
}
static T_2 F_19 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
T_1 V_20 ;
int V_7 ;
unsigned long V_15 ;
F_20 ( V_2 -> V_40 , 1 , V_41 | V_42 ) ;
F_10 ( & V_2 -> V_21 , V_15 ) ;
V_20 = V_2 -> V_20 ;
V_20 &= ~ V_22 ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 , 1 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_2 -> V_21 , V_15 ) ;
F_3 ( V_2 -> V_10 , L_4
L_5 ) ;
goto V_43;
}
V_2 -> V_20 = V_20 ;
F_11 ( & V_2 -> V_21 , V_15 ) ;
V_7 = F_1 ( V_2 , & V_20 , V_2 -> V_23 +
V_44 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_16
L_5 ) ;
goto V_43;
}
V_20 &= ~ V_45 ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 +
V_44 , 1 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_10 , L_17
L_18 ) ;
V_43:
return V_46 ;
}
static int F_21 ( struct V_47 * V_48 )
{
int V_7 ;
T_1 V_20 ;
bool V_49 = false ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
const struct V_52 * V_53 =
F_22 ( & V_48 -> V_11 ) ;
if ( V_53 != NULL )
V_49 = V_53 -> V_49 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_54 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_48 -> V_11 , L_19 ) ;
return - V_55 ;
}
F_24 ( & V_2 -> V_21 ) ;
V_2 -> V_56 = F_25 ( V_48 , 0 ) ;
if ( V_2 -> V_56 < 0 ) {
F_3 ( & V_48 -> V_11 , L_20 ) ;
V_7 = - V_57 ;
goto V_58;
}
V_51 = F_26 ( V_48 , V_59 ,
L_21 ) ;
if ( ! ( V_51 && V_51 -> V_60 ) ) {
F_3 ( & V_48 -> V_11 , L_22 ) ;
V_7 = - V_57 ;
goto V_58;
}
V_2 -> V_23 = V_51 -> V_60 ;
V_2 -> V_25 = V_2 -> V_23 + V_61 ;
V_2 -> V_26 = V_2 -> V_23 + V_62 ;
V_2 -> V_35 = V_2 -> V_23 + V_63 ;
V_2 -> V_10 = & V_48 -> V_11 ;
V_7 = F_1 ( V_2 , & V_20 , V_2 -> V_23 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_48 -> V_11 , L_23 ) ;
goto V_58;
}
if ( ! ( V_20 & V_64 ) ) {
V_20 |= V_64 ;
V_7 = F_4 ( V_2 , & V_20 , V_2 -> V_23 ,
1 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_48 -> V_11 , L_4
L_5 ) ;
goto V_58;
}
}
V_2 -> V_20 = V_20 ;
if ( V_49 == true )
V_65 . V_66 = F_6 ;
F_27 ( V_48 , V_2 ) ;
V_2 -> V_40 = F_28 ( L_24 , & V_48 -> V_11 ,
& V_65 , V_67 ) ;
if ( F_29 ( V_2 -> V_40 ) ) {
F_3 ( & V_48 -> V_11 , L_25 ,
V_68 , F_30 ( V_2 -> V_40 ) ) ;
V_7 = F_30 ( V_2 -> V_40 ) ;
goto V_58;
}
V_7 = F_31 ( V_2 -> V_56 ,
F_19 , V_69 ,
L_26 , V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_48 -> V_11 , L_27 , V_7 ) ;
goto V_70;
}
F_32 ( & V_48 -> V_11 , 1 ) ;
F_9 ( & V_48 -> V_11 , L_28 ) ;
return 0 ;
V_70:
F_33 ( V_2 -> V_40 ) ;
V_58:
F_27 ( V_48 , NULL ) ;
F_34 ( V_2 ) ;
return V_7 ;
}
static int F_35 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_36 ( V_48 ) ;
F_32 ( & V_48 -> V_11 , 0 ) ;
F_37 ( V_2 -> V_56 , V_2 ) ;
F_33 ( V_2 -> V_40 ) ;
F_27 ( V_48 , NULL ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_8 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( F_39 ( V_11 ) )
F_40 ( V_2 -> V_56 ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
if ( F_39 ( V_11 ) )
F_42 ( V_2 -> V_56 ) ;
return 0 ;
}
