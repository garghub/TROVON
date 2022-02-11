static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_6 ;
return 0 ;
}
static void F_2 ( int V_5 )
{
F_3 ( V_7 -> V_8 [ 0 ] , V_5 & 1 ) ;
F_3 ( V_7 -> V_8 [ 1 ] , V_5 >> 1 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 . integer . V_5 [ 0 ] ;
V_6 = V_5 ;
if ( ! V_9 )
F_2 ( V_5 ) ;
return 0 ;
}
static void F_5 ( int V_10 )
{
F_6 ( L_1 , V_11 , V_10 ) ;
V_9 = V_10 ;
F_7 ( V_7 -> V_12 , V_10 ) ;
if ( V_10 && V_7 -> V_8 [ 0 ] > 0 )
F_2 ( V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_9 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_5 ( V_4 -> V_5 . integer . V_5 [ 0 ] ) ;
return 0 ;
}
void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_7 -> V_12 > 0 ) {
F_6 ( L_2 , V_11 ) ;
F_11 ( V_16 , V_17 ,
F_12 ( V_17 ) ) ;
}
if ( V_7 -> V_8 [ 0 ] > 0 ) {
F_6 ( L_3 , V_11 ) ;
F_11 ( V_16 , V_18 ,
F_12 ( V_18 ) ) ;
}
}
static int F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = V_20 -> V_23 ;
struct V_24 * V_25 = V_14 -> V_25 ;
struct V_24 * V_26 = V_14 -> V_26 ;
int V_27 ;
V_27 = F_14 ( V_25 , 0 ,
V_28 , V_29 ) ;
if ( V_27 ) {
F_15 ( L_4 , V_11 ) ;
return V_27 ;
}
if ( V_7 -> V_30 ) {
V_27 = F_14 ( V_26 , V_31 ,
0 , V_32 ) ;
if ( V_27 ) {
F_15 ( L_5 ,
V_11 ) ;
return V_27 ;
}
}
if ( V_7 -> V_33 ) {
int V_34 ;
V_34 = F_16 ( V_35 ) / V_28 ;
V_34 -- ;
V_27 = F_17 ( V_26 , V_36 ,
V_34 ) ;
}
return 0 ;
}
static int F_18 ( struct V_37 * V_38 )
{
if ( V_38 -> V_39 )
V_38 -> V_39 () ;
return 0 ;
}
static int F_19 ( struct V_40 * V_41 ,
struct V_37 * V_38 )
{
int V_27 ;
if ( V_7 -> V_8 [ 0 ] > 0 ) {
V_27 = F_20 ( V_38 -> V_8 [ 0 ] , L_6 ) ;
if ( V_27 ) {
F_21 ( V_41 , L_7 ) ;
return V_27 ;
}
V_27 = F_20 ( V_38 -> V_8 [ 1 ] , L_8 ) ;
if ( V_27 ) {
F_21 ( V_41 , L_9 ) ;
F_22 ( V_7 -> V_8 [ 0 ] ) ;
return V_27 ;
}
F_23 ( V_38 -> V_8 [ 0 ] , 0 ) ;
F_23 ( V_38 -> V_8 [ 1 ] , 0 ) ;
}
if ( V_7 -> V_12 > 0 ) {
V_27 = F_20 ( V_38 -> V_12 , L_10 ) ;
if ( V_27 ) {
F_21 ( V_41 , L_11 ,
V_38 -> V_12 , V_27 ) ;
goto V_42;
}
F_5 ( 0 ) ;
}
return 0 ;
V_42:
if ( V_38 -> V_8 [ 0 ] > 0 ) {
F_22 ( V_38 -> V_8 [ 0 ] ) ;
F_22 ( V_38 -> V_8 [ 1 ] ) ;
}
return V_27 ;
}
static void F_24 ( struct V_37 * V_38 )
{
if ( V_38 -> V_8 [ 0 ] > 0 ) {
F_22 ( V_38 -> V_8 [ 0 ] ) ;
F_22 ( V_38 -> V_8 [ 1 ] ) ;
}
if ( V_38 -> V_12 > 0 )
F_22 ( V_38 -> V_12 ) ;
}
static int F_25 ( struct V_40 * V_41 )
{
F_18 ( V_7 ) ;
return 0 ;
}
int F_26 ( struct V_43 * V_44 ,
struct V_15 * V_16 )
{
struct V_43 * V_45 ;
int V_27 ;
V_16 -> V_46 -> V_47 = & V_48 ;
V_16 -> V_46 -> V_49 = V_50 | V_51 |
V_52 ;
V_7 = V_44 -> V_41 . V_53 ;
if ( ! V_7 ) {
F_21 ( & V_44 -> V_41 , L_12 ) ;
return - V_54 ;
}
F_18 ( V_7 ) ;
V_35 = F_27 ( & V_44 -> V_41 , L_13 ) ;
if ( F_28 ( V_35 ) ) {
F_21 ( & V_44 -> V_41 , L_14 ) ;
return - V_54 ;
}
F_29 ( & V_44 -> V_41 , L_15 , F_16 ( V_35 ) ) ;
V_27 = F_19 ( & V_44 -> V_41 , V_7 ) ;
if ( V_27 )
goto V_55;
V_45 = F_30 ( L_16 , - 1 ) ;
if ( ! V_45 ) {
F_21 ( & V_44 -> V_41 , L_17 ) ;
V_27 = - V_56 ;
goto V_57;
}
F_31 ( V_45 , V_16 ) ;
V_27 = F_32 ( V_45 ) ;
if ( V_27 ) {
F_21 ( & V_44 -> V_41 , L_18 ) ;
goto V_58;
}
F_31 ( V_44 , V_45 ) ;
return 0 ;
V_58:
F_33 ( V_45 ) ;
V_57:
F_24 ( V_7 ) ;
V_55:
F_34 ( V_35 ) ;
return V_27 ;
}
int F_35 ( struct V_43 * V_44 )
{
struct V_43 * V_45 = F_36 ( V_44 ) ;
F_37 ( V_45 ) ;
F_24 ( V_7 ) ;
F_34 ( V_35 ) ;
return 0 ;
}
