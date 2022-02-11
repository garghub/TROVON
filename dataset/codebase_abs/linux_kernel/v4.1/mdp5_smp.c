static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static inline T_1 F_4 ( enum V_9 V_10 , int V_11 )
{
#define F_5 0
if ( F_6 ( V_11 >= F_7 ( V_10 ) ) )
return F_5 ;
return V_12 -> V_3 . V_13 [ V_10 ] + V_11 ;
}
static int F_8 ( struct V_2 * V_3 ,
T_1 V_14 , int V_15 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_16 * V_17 ;
struct V_18 * V_19 = & V_3 -> V_20 [ V_14 ] ;
int V_21 , V_22 , V_23 , V_24 , V_25 = V_3 -> V_26 ;
int V_27 ;
unsigned long V_28 ;
V_17 = F_9 ( V_1 -> V_29 ) ;
V_27 = V_17 -> V_3 . V_27 [ V_14 ] ;
F_10 ( & V_3 -> V_30 , V_28 ) ;
if ( V_27 ) {
V_15 = F_11 ( 0 , V_15 - V_27 ) ;
F_12 ( L_1 , V_15 , V_27 ) ;
}
V_23 = V_25 - F_13 ( V_3 -> V_31 , V_25 ) ;
if ( V_15 > V_23 ) {
F_14 ( V_1 -> V_6 -> V_6 , L_2 ,
V_15 , V_23 ) ;
V_22 = - V_32 ;
goto V_33;
}
V_24 = F_13 ( V_19 -> V_34 , V_25 ) ;
if ( V_15 > V_24 ) {
for ( V_21 = V_24 ; V_21 < V_15 ; V_21 ++ ) {
int V_35 = F_15 ( V_3 -> V_31 , V_25 ) ;
F_16 ( V_35 , V_19 -> V_34 ) ;
F_16 ( V_35 , V_3 -> V_31 ) ;
}
} else {
for ( V_21 = V_24 ; V_21 > V_15 ; V_21 -- ) {
int V_35 = F_17 ( V_19 -> V_34 , V_25 ) ;
F_18 ( V_35 , V_19 -> V_34 ) ;
}
}
V_33:
F_19 ( & V_3 -> V_30 , V_28 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 ,
enum V_9 V_10 , int V_15 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_36 = V_3 -> V_37 / ( 128 / V_38 ) ;
T_1 V_39 ;
V_39 = ( V_15 * V_36 ) / 4 ;
F_21 ( V_1 , F_22 ( V_10 ) , V_39 * 1 ) ;
F_21 ( V_1 , F_23 ( V_10 ) , V_39 * 2 ) ;
F_21 ( V_1 , F_24 ( V_10 ) , V_39 * 3 ) ;
}
int F_25 ( struct V_2 * V_3 , enum V_9 V_10 , T_1 V_40 , T_1 V_41 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_42 * V_6 = V_1 -> V_6 ;
int V_43 = F_26 ( V_1 -> V_29 ) ;
int V_21 , V_44 , V_45 , V_46 , V_15 , V_22 ;
V_45 = F_27 ( V_40 ) ;
V_44 = F_28 ( V_40 ) ;
V_46 = 2 ;
for ( V_21 = 0 , V_15 = 0 ; V_21 < V_45 ; V_21 ++ ) {
int V_47 , V_48 , V_49 ;
V_49 = F_29 ( V_40 , V_21 ) ;
V_48 = V_41 * V_49 / ( V_21 ? V_44 : 1 ) ;
V_47 = F_30 ( V_48 * V_46 , V_3 -> V_37 ) ;
if ( V_43 == 0 )
V_47 = F_31 ( V_47 ) ;
F_12 ( L_3 , F_32 ( V_10 ) , V_21 , V_47 ) ;
V_22 = F_8 ( V_3 , F_4 ( V_10 , V_21 ) , V_47 ) ;
if ( V_22 ) {
F_14 ( V_6 -> V_6 , L_4 ,
V_47 , V_22 ) ;
return V_22 ;
}
V_15 += V_47 ;
}
F_20 ( V_3 , V_10 , V_15 ) ;
return 0 ;
}
void F_33 ( struct V_2 * V_3 , enum V_9 V_10 )
{
int V_21 , V_15 ;
for ( V_21 = 0 , V_15 = 0 ; V_21 < F_7 ( V_10 ) ; V_21 ++ )
F_8 ( V_3 , F_4 ( V_10 , V_21 ) , 0 ) ;
F_20 ( V_3 , V_10 , 0 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
T_1 V_14 , T_2 * V_50 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_25 = V_3 -> V_26 ;
T_1 V_35 , V_39 ;
F_35 (blk, *assigned, cnt) {
int V_51 = V_35 / 3 ;
int V_52 = V_35 % 3 ;
V_39 = F_36 ( V_1 , F_37 ( 0 , V_51 ) ) ;
switch ( V_52 ) {
case 0 :
V_39 &= ~ V_53 ;
V_39 |= F_38 ( V_14 ) ;
break;
case 1 :
V_39 &= ~ V_54 ;
V_39 |= F_39 ( V_14 ) ;
break;
case 2 :
V_39 &= ~ V_55 ;
V_39 |= F_40 ( V_14 ) ;
break;
}
F_21 ( V_1 , F_37 ( 0 , V_51 ) , V_39 ) ;
F_21 ( V_1 , F_41 ( 0 , V_51 ) , V_39 ) ;
}
}
void F_42 ( struct V_2 * V_3 , enum V_9 V_10 )
{
int V_25 = V_3 -> V_26 ;
T_2 V_50 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_7 ( V_10 ) ; V_21 ++ ) {
T_1 V_14 = F_4 ( V_10 , V_21 ) ;
struct V_18 * V_19 = & V_3 -> V_20 [ V_14 ] ;
F_43 ( V_50 , V_19 -> V_56 , V_19 -> V_34 , V_25 ) ;
F_34 ( V_3 , V_14 , & V_50 ) ;
}
}
void F_44 ( struct V_2 * V_3 , enum V_9 V_10 )
{
int V_25 = V_3 -> V_26 ;
T_2 V_57 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_7 ( V_10 ) ; V_21 ++ ) {
T_1 V_14 = F_4 ( V_10 , V_21 ) ;
struct V_18 * V_19 = & V_3 -> V_20 [ V_14 ] ;
if ( F_45 ( V_57 , V_19 -> V_56 , V_19 -> V_34 , V_25 ) ) {
unsigned long V_28 ;
F_10 ( & V_3 -> V_30 , V_28 ) ;
F_45 ( V_3 -> V_31 , V_3 -> V_31 , V_57 , V_25 ) ;
F_19 ( & V_3 -> V_30 , V_28 ) ;
F_34 ( V_3 , F_5 , & V_57 ) ;
}
F_46 ( V_19 -> V_56 , V_19 -> V_34 , V_25 ) ;
}
}
void F_47 ( struct V_2 * V_3 )
{
F_48 ( V_3 ) ;
}
struct V_2 * F_49 ( struct V_42 * V_6 , const struct V_58 * V_29 )
{
struct V_2 * V_3 = NULL ;
int V_22 ;
V_3 = F_50 ( sizeof( * V_3 ) , V_59 ) ;
if ( F_51 ( ! V_3 ) ) {
V_22 = - V_60 ;
goto V_33;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_26 = V_29 -> V_61 ;
V_3 -> V_37 = V_29 -> V_62 ;
F_46 ( V_3 -> V_31 , V_29 -> V_63 , V_3 -> V_26 ) ;
F_52 ( & V_3 -> V_30 ) ;
return V_3 ;
V_33:
if ( V_3 )
F_47 ( V_3 ) ;
return F_53 ( V_22 ) ;
}
