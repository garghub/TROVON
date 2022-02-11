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
struct V_14 * V_15 ,
T_1 V_16 , int V_17 )
{
void * V_18 = V_15 -> V_19 [ V_16 ] ;
int V_20 , V_21 , V_22 = V_3 -> V_23 ;
T_2 V_24 ;
F_6 ( F_9 ( V_18 , V_22 ) > 0 ) ;
V_24 = V_3 -> V_24 [ V_16 ] ;
if ( V_24 ) {
V_17 = F_10 ( 0 , V_17 - V_24 ) ;
F_11 ( L_1 , V_17 , V_24 ) ;
}
V_21 = V_22 - F_9 ( V_15 -> V_15 , V_22 ) ;
if ( V_17 > V_21 ) {
F_12 ( V_3 -> V_6 -> V_6 , L_2 ,
V_17 , V_21 ) ;
return - V_25 ;
}
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ ) {
int V_26 = F_13 ( V_15 -> V_15 , V_22 ) ;
F_14 ( V_26 , V_18 ) ;
F_14 ( V_26 , V_15 -> V_15 ) ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_3 ,
enum V_9 V_10 , int V_17 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_27 = V_3 -> V_28 / ( 128 / V_29 ) ;
T_1 V_30 ;
V_30 = ( V_17 * V_27 ) / 4 ;
F_16 ( V_1 , F_17 ( V_10 ) , V_30 * 1 ) ;
F_16 ( V_1 , F_18 ( V_10 ) , V_30 * 2 ) ;
F_16 ( V_1 , F_19 ( V_10 ) , V_30 * 3 ) ;
}
T_3 F_20 ( struct V_2 * V_3 ,
const struct V_31 * V_32 ,
T_1 V_33 , bool V_34 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_35 = F_21 ( V_1 -> V_36 ) ;
int V_20 , V_37 , V_38 , V_39 ;
T_1 V_40 = V_32 -> V_41 . V_42 ;
T_3 V_43 = 0 ;
V_38 = F_22 ( V_40 ) ;
V_37 = F_23 ( V_40 ) ;
V_39 = 2 ;
if ( ( V_35 > 0 ) && ( V_32 -> V_44 > V_45 ) ) {
V_40 = V_46 ;
V_38 = 2 ;
if ( V_34 && ( V_37 > 1 ) )
V_37 = 1 ;
}
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
int V_47 , V_48 , V_49 ;
V_49 = F_24 ( V_40 , V_20 ) ;
V_48 = V_33 * V_49 / ( V_20 ? V_37 : 1 ) ;
V_47 = F_25 ( V_48 * V_39 , V_3 -> V_28 ) ;
if ( V_35 == 0 )
V_47 = F_26 ( V_47 ) ;
V_43 |= ( V_47 << ( 8 * V_20 ) ) ;
}
return V_43 ;
}
int F_27 ( struct V_2 * V_3 , struct V_14 * V_15 ,
enum V_9 V_10 , T_3 V_43 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_6 = V_1 -> V_6 ;
int V_20 , V_51 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_10 ) ; V_20 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_20 ) ;
int V_47 = V_43 & 0xff ;
if ( ! V_47 )
continue;
F_11 ( L_3 , F_28 ( V_10 ) , V_20 , V_47 ) ;
V_51 = F_8 ( V_3 , V_15 , V_16 , V_47 ) ;
if ( V_51 ) {
F_12 ( V_6 -> V_6 , L_4 ,
V_47 , V_51 ) ;
return V_51 ;
}
V_43 >>= 8 ;
}
V_15 -> V_52 |= ( 1 << V_10 ) ;
return 0 ;
}
void F_29 ( struct V_2 * V_3 , struct V_14 * V_15 ,
enum V_9 V_10 )
{
int V_20 ;
int V_22 = V_3 -> V_23 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_10 ) ; V_20 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_20 ) ;
void * V_18 = V_15 -> V_19 [ V_16 ] ;
F_30 ( V_15 -> V_15 , V_15 -> V_15 , V_18 , V_22 ) ;
F_31 ( V_18 , V_22 ) ;
}
V_15 -> V_53 |= ( 1 << V_10 ) ;
}
static unsigned F_32 ( struct V_2 * V_3 ,
T_1 V_16 , T_4 * V_52 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_22 = V_3 -> V_23 ;
unsigned V_17 = 0 ;
T_1 V_26 , V_30 ;
F_33 (blk, *assigned, cnt) {
int V_54 = V_26 / 3 ;
int V_55 = V_26 % 3 ;
V_30 = F_34 ( V_1 , F_35 ( V_54 ) ) ;
switch ( V_55 ) {
case 0 :
V_30 &= ~ V_56 ;
V_30 |= F_36 ( V_16 ) ;
break;
case 1 :
V_30 &= ~ V_57 ;
V_30 |= F_37 ( V_16 ) ;
break;
case 2 :
V_30 &= ~ V_58 ;
V_30 |= F_38 ( V_16 ) ;
break;
}
F_16 ( V_1 , F_35 ( V_54 ) , V_30 ) ;
F_16 ( V_1 , F_39 ( V_54 ) , V_30 ) ;
V_17 ++ ;
}
return V_17 ;
}
void F_40 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
enum V_9 V_10 ;
F_33 (pipe, &state->assigned, sizeof(state->assigned) * 8 ) {
unsigned V_20 , V_17 = 0 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_10 ) ; V_20 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_20 ) ;
void * V_18 = V_15 -> V_19 [ V_16 ] ;
V_17 += F_32 ( V_3 , V_16 , V_18 ) ;
F_11 ( L_5 ,
F_28 ( V_10 ) , V_20 , V_17 ) ;
}
F_15 ( V_3 , V_10 , V_17 ) ;
}
V_15 -> V_52 = 0 ;
}
void F_41 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
enum V_9 V_10 ;
F_33 (pipe, &state->released, sizeof(state->released) * 8 ) {
F_11 ( L_6 , F_28 ( V_10 ) ) ;
F_15 ( V_3 , V_10 , 0 ) ;
}
V_15 -> V_53 = 0 ;
}
void F_42 ( struct V_2 * V_3 , struct V_59 * V_60 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_61 * V_62 ;
struct V_14 * V_15 ;
int V_63 = 0 , V_20 , V_64 ;
F_43 ( V_60 , L_7 ) ;
F_43 ( V_60 , L_8 ) ;
if ( F_44 () )
F_45 ( & V_1 -> V_65 , NULL ) ;
V_62 = & V_1 -> V_15 -> V_66 ;
V_15 = & V_1 -> V_15 -> V_3 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_67 ; V_20 ++ ) {
struct V_68 * V_66 = V_1 -> V_69 [ V_20 ] ;
struct V_70 * V_11 = V_62 -> V_71 [ V_66 -> V_54 ] ;
enum V_9 V_10 = V_66 -> V_10 ;
for ( V_64 = 0 ; V_64 < F_7 ( V_10 ) ; V_64 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_64 ) ;
void * V_18 = V_15 -> V_19 [ V_16 ] ;
int V_72 = F_9 ( V_18 , V_3 -> V_23 ) ;
F_43 ( V_60 , L_9 ,
F_28 ( V_10 ) , V_64 , V_72 ,
V_11 ? V_11 -> V_73 : NULL ) ;
V_63 += V_72 ;
}
}
F_43 ( V_60 , L_10 , V_63 , V_3 -> V_23 ) ;
F_43 ( V_60 , L_11 , V_3 -> V_23 -
F_9 ( V_15 -> V_15 , V_3 -> V_23 ) ) ;
if ( F_44 () )
F_46 ( & V_1 -> V_65 ) ;
}
void F_47 ( struct V_2 * V_3 )
{
F_48 ( V_3 ) ;
}
struct V_2 * F_49 ( struct V_1 * V_1 , const struct V_74 * V_36 )
{
struct V_14 * V_15 = & V_1 -> V_15 -> V_3 ;
struct V_2 * V_3 = NULL ;
int V_51 ;
V_3 = F_50 ( sizeof( * V_3 ) , V_75 ) ;
if ( F_51 ( ! V_3 ) ) {
V_51 = - V_76 ;
goto V_77;
}
V_3 -> V_6 = V_1 -> V_6 ;
V_3 -> V_23 = V_36 -> V_78 ;
V_3 -> V_28 = V_36 -> V_79 ;
F_52 ( V_15 -> V_15 , V_36 -> V_80 , V_3 -> V_23 ) ;
memcpy ( V_3 -> V_24 , V_36 -> V_24 , sizeof( V_3 -> V_24 ) ) ;
return V_3 ;
V_77:
if ( V_3 )
F_47 ( V_3 ) ;
return F_53 ( V_51 ) ;
}
