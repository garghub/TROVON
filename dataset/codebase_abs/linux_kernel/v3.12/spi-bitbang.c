static unsigned F_1 (
struct V_1 * V_2 ,
T_1 (* F_2)( struct V_1 * V_2 ,
unsigned V_3 ,
T_1 V_4 , T_2 V_5 ) ,
unsigned V_6 ,
struct V_7 * V_8
) {
unsigned V_5 = V_8 -> V_9 ;
unsigned V_10 = V_8 -> V_11 ;
const T_2 * V_12 = V_8 -> V_13 ;
T_2 * V_14 = V_8 -> V_15 ;
while ( F_3 ( V_10 > 0 ) ) {
T_2 V_4 = 0 ;
if ( V_12 )
V_4 = * V_12 ++ ;
V_4 = F_2 ( V_2 , V_6 , V_4 , V_5 ) ;
if ( V_14 )
* V_14 ++ = V_4 ;
V_10 -= 1 ;
}
return V_8 -> V_11 - V_10 ;
}
static unsigned F_4 (
struct V_1 * V_2 ,
T_1 (* F_2)( struct V_1 * V_2 ,
unsigned V_3 ,
T_1 V_4 , T_2 V_5 ) ,
unsigned V_6 ,
struct V_7 * V_8
) {
unsigned V_5 = V_8 -> V_9 ;
unsigned V_10 = V_8 -> V_11 ;
const T_3 * V_12 = V_8 -> V_13 ;
T_3 * V_14 = V_8 -> V_15 ;
while ( F_3 ( V_10 > 1 ) ) {
T_3 V_4 = 0 ;
if ( V_12 )
V_4 = * V_12 ++ ;
V_4 = F_2 ( V_2 , V_6 , V_4 , V_5 ) ;
if ( V_14 )
* V_14 ++ = V_4 ;
V_10 -= 2 ;
}
return V_8 -> V_11 - V_10 ;
}
static unsigned F_5 (
struct V_1 * V_2 ,
T_1 (* F_2)( struct V_1 * V_2 ,
unsigned V_3 ,
T_1 V_4 , T_2 V_5 ) ,
unsigned V_6 ,
struct V_7 * V_8
) {
unsigned V_5 = V_8 -> V_9 ;
unsigned V_10 = V_8 -> V_11 ;
const T_1 * V_12 = V_8 -> V_13 ;
T_1 * V_14 = V_8 -> V_15 ;
while ( F_3 ( V_10 > 3 ) ) {
T_1 V_4 = 0 ;
if ( V_12 )
V_4 = * V_12 ++ ;
V_4 = F_2 ( V_2 , V_6 , V_4 , V_5 ) ;
if ( V_14 )
* V_14 ++ = V_4 ;
V_10 -= 4 ;
}
return V_8 -> V_11 - V_10 ;
}
int F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
T_2 V_9 ;
T_1 V_19 ;
if ( V_8 ) {
V_9 = V_8 -> V_9 ;
V_19 = V_8 -> V_20 ;
} else {
V_9 = 0 ;
V_19 = 0 ;
}
if ( ! V_9 )
V_9 = V_2 -> V_9 ;
if ( V_9 <= 8 )
V_17 -> V_21 = F_1 ;
else if ( V_9 <= 16 )
V_17 -> V_21 = F_4 ;
else if ( V_9 <= 32 )
V_17 -> V_21 = F_5 ;
else
return - V_22 ;
if ( ! V_19 )
V_19 = V_2 -> V_23 ;
if ( V_19 ) {
V_17 -> V_3 = ( 1000000000 / 2 ) / V_19 ;
if ( V_17 -> V_3 > ( V_24 * 1000 * 1000 ) )
return - V_22 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_25 * V_26 ;
int V_27 ;
unsigned long V_28 ;
V_26 = F_8 ( V_2 -> V_29 ) ;
if ( ! V_17 ) {
V_17 = F_9 ( sizeof *V_17 , V_30 ) ;
if ( ! V_17 )
return - V_31 ;
V_2 -> V_18 = V_17 ;
}
V_17 -> F_2 = V_26 -> F_2 [ V_2 -> V_32 & ( V_33 | V_34 ) ] ;
if ( ! V_17 -> F_2 )
return - V_22 ;
V_27 = V_26 -> V_35 ( V_2 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
F_10 ( & V_2 -> V_36 , L_1 , V_37 , 2 * V_17 -> V_3 ) ;
F_11 ( & V_26 -> V_38 , V_28 ) ;
if ( ! V_26 -> V_39 ) {
V_26 -> V_40 ( V_2 , V_41 ) ;
F_12 ( V_17 -> V_3 ) ;
}
F_13 ( & V_26 -> V_38 , V_28 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_18 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned V_3 = V_17 -> V_3 ;
return V_17 -> V_21 ( V_2 , V_17 -> F_2 , V_3 , V_8 ) ;
}
static int F_17 ( struct V_42 * V_2 )
{
struct V_25 * V_26 ;
unsigned long V_28 ;
V_26 = F_8 ( V_2 ) ;
F_11 ( & V_26 -> V_38 , V_28 ) ;
V_26 -> V_39 = 1 ;
F_13 ( & V_26 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_18 ( struct V_42 * V_29 ,
struct V_43 * V_44 )
{
struct V_25 * V_26 ;
unsigned V_3 ;
struct V_7 * V_8 = NULL ;
unsigned V_45 ;
int V_46 ;
int V_47 = - 1 ;
struct V_1 * V_2 = V_44 -> V_2 ;
V_26 = F_8 ( V_29 ) ;
V_3 = 100 ;
V_45 = 1 ;
V_46 = 0 ;
F_19 (t, &m->transfers, transfer_list) {
if ( V_8 -> V_20 || V_8 -> V_9 )
V_47 = 1 ;
if ( V_47 != 0 ) {
V_46 = V_26 -> V_35 ( V_2 , V_8 ) ;
if ( V_46 < 0 )
break;
if ( V_47 == - 1 )
V_47 = 0 ;
}
if ( V_45 ) {
V_26 -> V_40 ( V_2 , V_48 ) ;
F_12 ( V_3 ) ;
}
V_45 = V_8 -> V_45 ;
if ( ! V_8 -> V_13 && ! V_8 -> V_15 && V_8 -> V_11 ) {
V_46 = - V_22 ;
break;
}
if ( V_8 -> V_11 ) {
if ( ! V_44 -> V_49 )
V_8 -> V_50 = V_8 -> V_51 = 0 ;
V_46 = V_26 -> V_21 ( V_2 , V_8 ) ;
}
if ( V_46 > 0 )
V_44 -> V_52 += V_46 ;
if ( V_46 != V_8 -> V_11 ) {
if ( V_46 >= 0 )
V_46 = - V_53 ;
break;
}
V_46 = 0 ;
if ( V_8 -> V_54 )
F_20 ( V_8 -> V_54 ) ;
if ( V_45 && ! F_21 ( & V_8 -> V_55 , & V_44 -> V_56 ) ) {
F_12 ( V_3 ) ;
V_26 -> V_40 ( V_2 , V_41 ) ;
F_12 ( V_3 ) ;
}
}
V_44 -> V_46 = V_46 ;
if ( ! ( V_46 == 0 && V_45 ) ) {
F_12 ( V_3 ) ;
V_26 -> V_40 ( V_2 , V_41 ) ;
F_12 ( V_3 ) ;
}
F_22 ( V_29 ) ;
return V_46 ;
}
static int F_23 ( struct V_42 * V_2 )
{
struct V_25 * V_26 ;
unsigned long V_28 ;
V_26 = F_8 ( V_2 ) ;
F_11 ( & V_26 -> V_38 , V_28 ) ;
V_26 -> V_39 = 0 ;
F_13 ( & V_26 -> V_38 , V_28 ) ;
return 0 ;
}
int F_24 ( struct V_25 * V_26 )
{
struct V_42 * V_29 = V_26 -> V_29 ;
if ( ! V_29 || ! V_26 -> V_40 )
return - V_22 ;
F_25 ( & V_26 -> V_38 ) ;
if ( ! V_29 -> V_57 )
V_29 -> V_57 = V_33 | V_34 | V_26 -> V_28 ;
if ( V_29 -> V_58 || V_29 -> V_59 )
return - V_22 ;
V_29 -> V_60 = F_17 ;
V_29 -> V_61 = F_23 ;
V_29 -> V_59 = F_18 ;
if ( ! V_26 -> V_21 ) {
V_26 -> V_62 = 0 ;
V_26 -> V_21 = F_16 ;
if ( ! V_29 -> V_63 ) {
if ( ! V_26 -> V_35 )
V_26 -> V_35 =
F_6 ;
V_29 -> V_63 = F_7 ;
V_29 -> V_64 = F_14 ;
}
}
return F_26 ( V_29 ) ;
}
int F_27 ( struct V_25 * V_26 )
{
F_28 ( V_26 -> V_29 ) ;
return 0 ;
}
