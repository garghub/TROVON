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
T_1 V_27 = V_3 -> V_28 / ( 128 / V_29 ) ;
T_1 V_30 ;
V_30 = ( V_17 * V_27 ) / 4 ;
V_3 -> V_31 [ V_10 ] = V_30 * 1 ;
V_3 -> V_32 [ V_10 ] = V_30 * 2 ;
V_3 -> V_33 [ V_10 ] = V_30 * 3 ;
}
T_3 F_16 ( struct V_2 * V_3 ,
const struct V_34 * V_35 ,
T_1 V_36 , bool V_37 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_38 = F_17 ( V_1 -> V_39 ) ;
int V_20 , V_40 , V_41 , V_42 ;
T_1 V_43 = V_35 -> V_44 . V_45 ;
T_3 V_46 = 0 ;
V_41 = F_18 ( V_43 ) ;
V_40 = F_19 ( V_43 ) ;
V_42 = 2 ;
if ( ( V_38 > 0 ) && ( V_35 -> V_47 > V_48 ) ) {
V_43 = V_49 ;
V_41 = 2 ;
if ( V_37 && ( V_40 > 1 ) )
V_40 = 1 ;
}
for ( V_20 = 0 ; V_20 < V_41 ; V_20 ++ ) {
int V_50 , V_51 , V_52 ;
V_52 = F_20 ( V_43 , V_20 ) ;
V_51 = V_36 * V_52 / ( V_20 ? V_40 : 1 ) ;
V_50 = F_21 ( V_51 * V_42 , V_3 -> V_28 ) ;
if ( V_38 == 0 )
V_50 = F_22 ( V_50 ) ;
V_46 |= ( V_50 << ( 8 * V_20 ) ) ;
}
return V_46 ;
}
int F_23 ( struct V_2 * V_3 , struct V_14 * V_15 ,
enum V_9 V_10 , T_3 V_46 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_53 * V_6 = V_1 -> V_6 ;
int V_20 , V_54 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_10 ) ; V_20 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_20 ) ;
int V_50 = V_46 & 0xff ;
if ( ! V_50 )
continue;
F_11 ( L_3 , F_24 ( V_10 ) , V_20 , V_50 ) ;
V_54 = F_8 ( V_3 , V_15 , V_16 , V_50 ) ;
if ( V_54 ) {
F_12 ( V_6 -> V_6 , L_4 ,
V_50 , V_54 ) ;
return V_54 ;
}
V_46 >>= 8 ;
}
V_15 -> V_55 |= ( 1 << V_10 ) ;
return 0 ;
}
void F_25 ( struct V_2 * V_3 , struct V_14 * V_15 ,
enum V_9 V_10 )
{
int V_20 ;
int V_22 = V_3 -> V_23 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_10 ) ; V_20 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_20 ) ;
void * V_18 = V_15 -> V_19 [ V_16 ] ;
F_26 ( V_15 -> V_15 , V_15 -> V_15 , V_18 , V_22 ) ;
F_27 ( V_18 , V_22 ) ;
}
V_15 -> V_56 |= ( 1 << V_10 ) ;
}
static unsigned F_28 ( struct V_2 * V_3 ,
T_1 V_16 , T_4 * V_55 )
{
int V_22 = V_3 -> V_23 ;
unsigned V_17 = 0 ;
T_1 V_26 , V_30 ;
F_29 (blk, *assigned, cnt) {
int V_57 = V_26 / 3 ;
int V_58 = V_26 % 3 ;
V_30 = V_3 -> V_59 [ V_57 ] ;
switch ( V_58 ) {
case 0 :
V_30 &= ~ V_60 ;
V_30 |= F_30 ( V_16 ) ;
break;
case 1 :
V_30 &= ~ V_61 ;
V_30 |= F_31 ( V_16 ) ;
break;
case 2 :
V_30 &= ~ V_62 ;
V_30 |= F_32 ( V_16 ) ;
break;
}
V_3 -> V_59 [ V_57 ] = V_30 ;
V_3 -> V_63 [ V_57 ] = V_30 ;
V_17 ++ ;
}
return V_17 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_20 , V_64 ;
V_64 = V_3 -> V_23 / 3 + 1 ;
for ( V_20 = 0 ; V_20 < V_64 ; V_20 ++ ) {
F_34 ( V_1 , F_35 ( V_20 ) ,
V_3 -> V_59 [ V_20 ] ) ;
F_34 ( V_1 , F_36 ( V_20 ) ,
V_3 -> V_63 [ V_20 ] ) ;
}
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_65 ; V_20 ++ ) {
struct V_66 * V_67 = V_1 -> V_68 [ V_20 ] ;
enum V_9 V_10 = V_67 -> V_10 ;
F_34 ( V_1 , F_38 ( V_10 ) ,
V_3 -> V_31 [ V_10 ] ) ;
F_34 ( V_1 , F_39 ( V_10 ) ,
V_3 -> V_32 [ V_10 ] ) ;
F_34 ( V_1 , F_40 ( V_10 ) ,
V_3 -> V_33 [ V_10 ] ) ;
}
}
void F_41 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
enum V_9 V_10 ;
F_29 (pipe, &state->assigned, sizeof(state->assigned) * 8 ) {
unsigned V_20 , V_17 = 0 ;
for ( V_20 = 0 ; V_20 < F_7 ( V_10 ) ; V_20 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_20 ) ;
void * V_18 = V_15 -> V_19 [ V_16 ] ;
V_17 += F_28 ( V_3 , V_16 , V_18 ) ;
F_11 ( L_5 ,
F_24 ( V_10 ) , V_20 , V_17 ) ;
}
F_15 ( V_3 , V_10 , V_17 ) ;
}
F_33 ( V_3 ) ;
F_37 ( V_3 ) ;
V_15 -> V_55 = 0 ;
}
void F_42 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
enum V_9 V_10 ;
F_29 (pipe, &state->released, sizeof(state->released) * 8 ) {
F_11 ( L_6 , F_24 ( V_10 ) ) ;
F_15 ( V_3 , V_10 , 0 ) ;
}
F_37 ( V_3 ) ;
V_15 -> V_56 = 0 ;
}
void F_43 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_71 * V_72 ;
struct V_14 * V_15 ;
int V_73 = 0 , V_20 , V_74 ;
F_44 ( V_70 , L_7 ) ;
F_44 ( V_70 , L_8 ) ;
if ( F_45 () )
F_46 ( & V_1 -> V_75 , NULL ) ;
V_72 = & V_1 -> V_15 -> V_67 ;
V_15 = & V_1 -> V_15 -> V_3 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_65 ; V_20 ++ ) {
struct V_66 * V_67 = V_1 -> V_68 [ V_20 ] ;
struct V_76 * V_11 = V_72 -> V_77 [ V_67 -> V_57 ] ;
enum V_9 V_10 = V_67 -> V_10 ;
for ( V_74 = 0 ; V_74 < F_7 ( V_10 ) ; V_74 ++ ) {
T_1 V_16 = F_4 ( V_10 , V_74 ) ;
void * V_18 = V_15 -> V_19 [ V_16 ] ;
int V_78 = F_9 ( V_18 , V_3 -> V_23 ) ;
F_44 ( V_70 , L_9 ,
F_24 ( V_10 ) , V_74 , V_78 ,
V_11 ? V_11 -> V_79 : NULL ) ;
V_73 += V_78 ;
}
}
F_44 ( V_70 , L_10 , V_73 , V_3 -> V_23 ) ;
F_44 ( V_70 , L_11 , V_3 -> V_23 -
F_9 ( V_15 -> V_15 , V_3 -> V_23 ) ) ;
if ( F_45 () )
F_47 ( & V_1 -> V_75 ) ;
}
void F_48 ( struct V_2 * V_3 )
{
F_49 ( V_3 ) ;
}
struct V_2 * F_50 ( struct V_1 * V_1 , const struct V_80 * V_39 )
{
struct V_14 * V_15 = & V_1 -> V_15 -> V_3 ;
struct V_2 * V_3 = NULL ;
int V_54 ;
V_3 = F_51 ( sizeof( * V_3 ) , V_81 ) ;
if ( F_52 ( ! V_3 ) ) {
V_54 = - V_82 ;
goto V_83;
}
V_3 -> V_6 = V_1 -> V_6 ;
V_3 -> V_23 = V_39 -> V_84 ;
V_3 -> V_28 = V_39 -> V_85 ;
F_53 ( V_15 -> V_15 , V_39 -> V_86 , V_3 -> V_23 ) ;
memcpy ( V_3 -> V_24 , V_39 -> V_24 , sizeof( V_3 -> V_24 ) ) ;
return V_3 ;
V_83:
if ( V_3 )
F_48 ( V_3 ) ;
return F_54 ( V_54 ) ;
}
