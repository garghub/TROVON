static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , unsigned long V_5 ,
unsigned int * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_9 ;
unsigned int V_10 ;
V_9 = V_11 / V_4 -> V_12 ;
V_9 *= V_8 -> V_13 + 1 ;
if ( V_5 % V_9 ) {
return - V_14 ;
} else {
V_10 = V_5 / V_9 - 1 ;
if ( V_10 > V_8 -> V_15 )
return - V_14 ;
}
* V_6 = V_10 ;
return 0 ;
}
static unsigned int F_4 ( struct V_2 * V_3 )
{
struct V_16 * V_17 ;
unsigned int V_18 = 0 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ ) {
V_17 = & V_3 -> V_21 [ V_19 ] ;
if ( F_5 ( V_22 , & V_17 -> V_23 ) ) {
if ( F_6 ( V_17 ) )
V_18 ++ ;
}
}
return V_18 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_16 * V_17 ,
int V_24 , int V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_16 * V_26 = V_4 -> V_26 ;
struct V_27 * V_28 = V_4 -> V_28 ;
unsigned int V_6 = 0 , V_29 ;
int V_30 ;
unsigned int V_18 ;
bool V_31 = false ;
V_18 = F_4 ( V_3 ) ;
if ( V_18 )
V_31 = ( V_25 == F_6 ( V_26 ) ) ;
if ( ! V_18 ||
( ( V_18 == 1 ) && ( V_17 -> V_32 == V_26 -> V_32 ) ) ||
( ( V_18 == 1 ) && ( V_17 -> V_32 != V_26 -> V_32 ) && V_31 ) ||
( ( V_18 > 1 ) && V_31 ) ) {
V_30 = F_8 ( V_4 -> V_33 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_31 ) {
V_30 = F_3 ( V_4 , V_25 , & V_6 ) ;
if ( V_30 )
goto V_34;
V_30 =
F_9 ( V_4 -> V_35 ,
V_6 & V_36 ) ;
if ( V_30 )
goto V_34;
V_30 =
F_9 ( V_4 -> V_37 ,
( V_6 & V_38 ) >> 4 ) ;
if ( V_30 )
goto V_34;
}
V_29 = V_8 -> V_13 * V_24 / V_25 ;
V_30 = F_10 ( V_4 -> V_39 , F_11 ( V_17 -> V_32 ) , V_29 ) ;
if ( V_30 )
goto V_34;
V_30 = F_9 ( V_4 -> V_40 , 0 ) ;
V_4 -> V_26 = V_17 ;
F_12 ( V_28 , L_1 ,
V_6 , V_25 , V_24 , V_29 ) ;
} else {
return - V_14 ;
}
V_34:
F_13 ( V_4 -> V_33 ) ;
return V_30 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
int V_30 = 0 ;
F_15 ( & V_4 -> V_41 ) ;
if ( ! V_4 -> V_42 ) {
V_30 = F_8 ( V_4 -> V_33 ) ;
if ( V_30 )
goto V_43;
V_30 = F_9 ( V_4 -> V_44 , 1 ) ;
if ( V_30 ) {
F_16 ( V_28 , L_2 ,
V_17 -> V_32 ) ;
goto V_43;
}
}
V_4 -> V_42 ++ ;
V_43:
F_17 ( & V_4 -> V_41 ) ;
return V_30 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_15 ( & V_4 -> V_41 ) ;
if ( -- V_4 -> V_42 ) {
F_17 ( & V_4 -> V_41 ) ;
return;
}
F_9 ( V_4 -> V_44 , 0 ) ;
F_13 ( V_4 -> V_33 ) ;
F_17 ( & V_4 -> V_41 ) ;
}
static int F_19 ( struct V_1 * V_4 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
const struct V_45 * V_46 ;
struct V_47 * V_48 = V_28 -> V_49 ;
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_50 ;
F_20 ( V_48 , L_3 , & V_50 ) ;
if ( V_50 )
V_8 -> V_50 = V_50 ;
V_46 = V_8 -> V_46 ;
V_4 -> V_35 = F_21 ( V_28 , V_4 -> V_39 ,
V_46 [ V_51 ] ) ;
if ( F_22 ( V_4 -> V_35 ) )
return F_23 ( V_4 -> V_35 ) ;
V_4 -> V_37 = F_21 ( V_28 , V_4 -> V_39 ,
V_46 [ V_52 ] ) ;
if ( F_22 ( V_4 -> V_37 ) )
return F_23 ( V_4 -> V_37 ) ;
V_4 -> V_44 = F_21 ( V_28 , V_4 -> V_39 ,
V_46 [ V_53 ] ) ;
if ( F_22 ( V_4 -> V_44 ) )
return F_23 ( V_4 -> V_44 ) ;
V_4 -> V_40 = F_21 ( V_28 , V_4 -> V_39 ,
V_46 [ V_54 ] ) ;
if ( F_22 ( V_4 -> V_40 ) )
return F_23 ( V_4 -> V_40 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 )
{
struct V_27 * V_28 = & V_56 -> V_28 ;
struct V_7 * V_8 ;
struct V_1 * V_4 ;
struct V_57 * V_58 ;
int V_30 ;
V_4 = F_25 ( V_28 , sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 )
return - V_60 ;
V_8 = F_25 ( V_28 , sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
V_58 = F_26 ( V_56 , V_61 , 0 ) ;
V_4 -> V_62 = F_27 ( V_28 , V_58 ) ;
if ( F_22 ( V_4 -> V_62 ) )
return F_23 ( V_4 -> V_62 ) ;
V_4 -> V_39 = F_28 ( V_28 , V_4 -> V_62 ,
& V_63 ) ;
if ( F_22 ( V_4 -> V_39 ) )
return F_23 ( V_4 -> V_39 ) ;
V_8 -> V_46 = & V_64 [ 0 ] ;
V_8 -> V_15 = 0xff ;
V_8 -> V_13 = 255 ;
V_8 -> V_50 = 1 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_42 = 0 ;
F_29 ( & V_4 -> V_41 ) ;
V_30 = F_19 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_4 -> V_33 = F_30 ( V_28 -> V_49 , L_4 ) ;
if ( F_22 ( V_4 -> V_33 ) ) {
F_16 ( V_28 , L_5 ) ;
return F_23 ( V_4 -> V_33 ) ;
}
V_4 -> V_12 = F_31 ( V_4 -> V_33 ) ;
if ( ! V_4 -> V_12 ) {
F_16 ( V_28 , L_6 ) ;
return - V_14 ;
}
V_30 = F_32 ( V_4 -> V_33 ) ;
if ( V_30 ) {
F_16 ( V_28 , L_7 ) ;
return V_30 ;
}
V_4 -> V_3 . V_28 = V_28 ;
V_4 -> V_3 . V_65 = & V_66 ;
V_4 -> V_3 . V_67 = - 1 ;
V_4 -> V_3 . V_20 = V_4 -> V_8 -> V_50 ;
V_4 -> V_3 . V_68 = true ;
V_30 = F_33 ( & V_4 -> V_3 ) ;
if ( V_30 < 0 ) {
F_34 ( V_4 -> V_33 ) ;
return V_30 ;
}
F_35 ( V_56 , V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_55 * V_56 )
{
struct V_1 * V_4 = F_37 ( V_56 ) ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_8 -> V_50 ; V_19 ++ )
F_38 ( & V_4 -> V_3 . V_21 [ V_19 ] ) ;
F_34 ( V_4 -> V_33 ) ;
return F_39 ( & V_4 -> V_3 ) ;
}
