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
struct V_16 * V_17 = & V_3 -> V_18 [ V_14 ] ;
int V_19 , V_20 , V_21 , V_22 , V_23 = V_3 -> V_24 ;
int V_25 ;
unsigned long V_26 ;
V_25 = V_3 -> V_27 -> V_25 [ V_14 ] ;
F_9 ( & V_3 -> V_28 , V_26 ) ;
if ( V_25 ) {
V_15 = F_10 ( 0 , V_15 - V_25 ) ;
F_11 ( L_1 , V_15 , V_25 ) ;
}
V_21 = V_23 - F_12 ( V_3 -> V_29 , V_23 ) ;
if ( V_15 > V_21 ) {
F_13 ( V_1 -> V_6 -> V_6 , L_2 ,
V_15 , V_21 ) ;
V_20 = - V_30 ;
goto V_31;
}
V_22 = F_12 ( V_17 -> V_32 , V_23 ) ;
if ( V_15 > V_22 ) {
for ( V_19 = V_22 ; V_19 < V_15 ; V_19 ++ ) {
int V_33 = F_14 ( V_3 -> V_29 , V_23 ) ;
F_15 ( V_33 , V_17 -> V_32 ) ;
F_15 ( V_33 , V_3 -> V_29 ) ;
}
} else {
for ( V_19 = V_22 ; V_19 > V_15 ; V_19 -- ) {
int V_33 = F_16 ( V_17 -> V_32 , V_23 ) ;
F_17 ( V_33 , V_17 -> V_32 ) ;
if ( ! F_18 ( V_33 , V_17 -> V_34 ) )
F_17 ( V_33 , V_3 -> V_29 ) ;
}
}
V_31:
F_19 ( & V_3 -> V_28 , V_26 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 ,
enum V_9 V_10 , int V_15 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_35 = V_3 -> V_36 / ( 128 / V_37 ) ;
T_1 V_38 ;
V_38 = ( V_15 * V_35 ) / 4 ;
F_21 ( V_1 , F_22 ( V_10 ) , V_38 * 1 ) ;
F_21 ( V_1 , F_23 ( V_10 ) , V_38 * 2 ) ;
F_21 ( V_1 , F_24 ( V_10 ) , V_38 * 3 ) ;
}
int F_25 ( struct V_2 * V_3 , enum V_9 V_10 ,
const struct V_39 * V_40 , T_1 V_41 , bool V_42 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_43 * V_6 = V_1 -> V_6 ;
int V_44 = F_26 ( V_1 -> V_27 ) ;
int V_19 , V_45 , V_46 , V_47 , V_15 , V_20 ;
T_1 V_48 = V_40 -> V_49 . V_50 ;
V_46 = F_27 ( V_48 ) ;
V_45 = F_28 ( V_48 ) ;
V_47 = 2 ;
if ( ( V_44 > 0 ) && ( V_40 -> V_51 > V_52 ) ) {
V_48 = V_53 ;
V_46 = 2 ;
if ( V_42 && ( V_45 > 1 ) )
V_45 = 1 ;
}
for ( V_19 = 0 , V_15 = 0 ; V_19 < V_46 ; V_19 ++ ) {
int V_54 , V_55 , V_56 ;
V_56 = F_29 ( V_48 , V_19 ) ;
V_55 = V_41 * V_56 / ( V_19 ? V_45 : 1 ) ;
V_54 = F_30 ( V_55 * V_47 , V_3 -> V_36 ) ;
if ( V_44 == 0 )
V_54 = F_31 ( V_54 ) ;
F_11 ( L_3 , F_32 ( V_10 ) , V_19 , V_54 ) ;
V_20 = F_8 ( V_3 , F_4 ( V_10 , V_19 ) , V_54 ) ;
if ( V_20 ) {
F_13 ( V_6 -> V_6 , L_4 ,
V_54 , V_20 ) ;
return V_20 ;
}
V_15 += V_54 ;
}
F_20 ( V_3 , V_10 , V_15 ) ;
return 0 ;
}
void F_33 ( struct V_2 * V_3 , enum V_9 V_10 )
{
int V_19 ;
unsigned long V_26 ;
int V_23 = V_3 -> V_24 ;
for ( V_19 = 0 ; V_19 < F_7 ( V_10 ) ; V_19 ++ ) {
T_2 V_57 ;
T_1 V_14 = F_4 ( V_10 , V_19 ) ;
struct V_16 * V_17 = & V_3 -> V_18 [ V_14 ] ;
F_9 ( & V_3 -> V_28 , V_26 ) ;
F_34 ( V_57 , V_17 -> V_58 , V_17 -> V_34 , V_23 ) ;
F_35 ( V_3 , F_5 , & V_57 ) ;
F_36 ( V_3 -> V_29 , V_3 -> V_29 , V_17 -> V_32 , V_23 ) ;
F_36 ( V_3 -> V_29 , V_3 -> V_29 , V_57 , V_23 ) ;
F_37 ( V_17 -> V_32 , V_23 ) ;
F_37 ( V_17 -> V_34 , V_23 ) ;
F_37 ( V_17 -> V_58 , V_23 ) ;
F_19 ( & V_3 -> V_28 , V_26 ) ;
}
F_20 ( V_3 , V_10 , 0 ) ;
}
static void F_35 ( struct V_2 * V_3 ,
T_1 V_14 , T_2 * V_57 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_23 = V_3 -> V_24 ;
T_1 V_33 , V_38 ;
F_38 (blk, *assigned, cnt) {
int V_59 = V_33 / 3 ;
int V_60 = V_33 % 3 ;
V_38 = F_39 ( V_1 , F_40 ( 0 , V_59 ) ) ;
switch ( V_60 ) {
case 0 :
V_38 &= ~ V_61 ;
V_38 |= F_41 ( V_14 ) ;
break;
case 1 :
V_38 &= ~ V_62 ;
V_38 |= F_42 ( V_14 ) ;
break;
case 2 :
V_38 &= ~ V_63 ;
V_38 |= F_43 ( V_14 ) ;
break;
}
F_21 ( V_1 , F_40 ( 0 , V_59 ) , V_38 ) ;
F_21 ( V_1 , F_44 ( 0 , V_59 ) , V_38 ) ;
}
}
void F_45 ( struct V_2 * V_3 , enum V_9 V_10 )
{
int V_23 = V_3 -> V_24 ;
T_2 V_57 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_7 ( V_10 ) ; V_19 ++ ) {
T_1 V_14 = F_4 ( V_10 , V_19 ) ;
struct V_16 * V_17 = & V_3 -> V_18 [ V_14 ] ;
if ( ! F_46 ( V_17 -> V_58 , V_17 -> V_34 , V_23 ) )
continue;
F_47 ( V_17 -> V_34 , V_17 -> V_32 , V_23 ) ;
F_34 ( V_57 , V_17 -> V_58 , V_17 -> V_34 , V_23 ) ;
F_35 ( V_3 , V_14 , & V_57 ) ;
}
}
void F_48 ( struct V_2 * V_3 , enum V_9 V_10 )
{
int V_23 = V_3 -> V_24 ;
T_2 V_64 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_7 ( V_10 ) ; V_19 ++ ) {
T_1 V_14 = F_4 ( V_10 , V_19 ) ;
struct V_16 * V_17 = & V_3 -> V_18 [ V_14 ] ;
if ( F_36 ( V_64 , V_17 -> V_58 , V_17 -> V_34 , V_23 ) ) {
unsigned long V_26 ;
F_9 ( & V_3 -> V_28 , V_26 ) ;
F_36 ( V_3 -> V_29 , V_3 -> V_29 , V_64 , V_23 ) ;
F_19 ( & V_3 -> V_28 , V_26 ) ;
F_35 ( V_3 , F_5 , & V_64 ) ;
}
F_47 ( V_17 -> V_58 , V_17 -> V_34 , V_23 ) ;
}
}
void F_49 ( struct V_2 * V_3 )
{
F_50 ( V_3 ) ;
}
struct V_2 * F_51 ( struct V_43 * V_6 , const struct V_65 * V_27 )
{
struct V_2 * V_3 = NULL ;
int V_20 ;
V_3 = F_52 ( sizeof( * V_3 ) , V_66 ) ;
if ( F_53 ( ! V_3 ) ) {
V_20 = - V_67 ;
goto V_31;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_24 = V_27 -> V_68 ;
V_3 -> V_36 = V_27 -> V_69 ;
F_47 ( V_3 -> V_29 , V_27 -> V_70 , V_3 -> V_24 ) ;
F_54 ( & V_3 -> V_28 ) ;
return V_3 ;
V_31:
if ( V_3 )
F_49 ( V_3 ) ;
return F_55 ( V_20 ) ;
}
