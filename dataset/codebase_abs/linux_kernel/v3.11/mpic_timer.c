static void F_1 ( struct V_1 * V_2 ,
const T_1 V_3 , struct V_4 * time )
{
T_1 V_5 ;
time -> V_6 = ( V_7 ) F_2 ( V_3 , V_2 -> V_8 ) ;
V_5 = ( T_1 ) time -> V_6 * ( T_1 ) V_2 -> V_8 ;
time -> V_9 = ( V_10 )
F_2 ( ( V_3 - V_5 ) * 1000000 , V_2 -> V_8 ) ;
return;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_4 * time , T_1 * V_3 )
{
T_1 V_11 ;
T_1 V_12 = 0 ;
T_1 V_5 ;
T_1 V_13 ;
T_1 V_14 ;
V_11 = F_2 ( V_15 , V_2 -> V_8 ) ;
if ( time -> V_6 > V_11 ||
( time -> V_6 == V_11 && time -> V_9 > 0 ) )
return - V_16 ;
V_5 = ( T_1 ) time -> V_6 * ( T_1 ) V_2 -> V_8 ;
V_12 += V_5 ;
V_13 = time -> V_9 / 1000 ;
V_13 = F_2 ( ( T_1 ) V_13 * ( T_1 ) V_2 -> V_8 , 1000 ) ;
V_12 += V_13 ;
V_14 = time -> V_9 % 1000 ;
V_14 = F_2 ( ( T_1 ) V_14 * ( T_1 ) V_2 -> V_8 , 1000000 ) ;
V_12 += V_14 ;
* V_3 = V_12 ;
return 0 ;
}
static struct V_17 * F_4 (
struct V_1 * V_2 )
{
struct V_18 * V_19 ;
unsigned int V_20 ;
unsigned int V_21 = F_5 ( V_22 ) ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned long V_25 ;
V_19 = V_22 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
F_6 ( & V_2 -> V_26 , V_25 ) ;
V_20 = V_19 -> V_27 & V_2 -> V_28 ;
if ( V_20 == V_19 -> V_27 ) {
V_23 = V_19 -> V_29 ;
V_2 -> V_30 [ V_23 ] . V_31 = V_19 ;
V_2 -> V_28 &= ~ V_19 -> V_27 ;
F_7 ( & V_2 -> V_26 , V_25 ) ;
return & V_2 -> V_30 [ V_23 ] ;
}
F_7 ( & V_2 -> V_26 , V_25 ) ;
V_19 ++ ;
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_23 )
{
struct V_18 * V_19 ;
T_2 V_32 ;
T_2 V_33 ;
T_2 V_34 ;
V_19 = V_2 -> V_30 [ V_23 ] . V_31 ;
if ( ! V_19 )
return - V_16 ;
V_32 = V_19 -> V_35 |
( V_19 -> V_35 << V_36 ) ;
F_9 ( V_2 -> V_37 , V_32 ) ;
V_33 = F_10 ( V_3 , V_38 , & V_34 ) ;
F_11 ( & V_2 -> V_39 [ V_23 ] . V_40 , 0 ) ;
F_11 ( & V_2 -> V_39 [ V_23 ] . V_41 , V_33 | V_42 ) ;
F_11 ( & V_2 -> V_39 [ V_23 - 1 ] . V_40 , 0 ) ;
F_11 ( & V_2 -> V_39 [ V_23 - 1 ] . V_41 , V_34 ) ;
return 0 ;
}
static struct V_17 * F_12 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_17 * V_43 ;
const T_1 V_44 = ( T_1 ) V_45 * ( T_1 ) V_38 ;
int V_46 ;
if ( V_3 > V_44 )
return NULL ;
V_43 = F_4 ( V_2 ) ;
if ( ! V_43 )
return NULL ;
V_46 = F_8 ( V_2 , V_3 , V_43 -> V_23 ) ;
if ( V_46 < 0 )
return NULL ;
return V_43 ;
}
static struct V_17 * F_13 ( const struct V_4 * time )
{
struct V_1 * V_2 ;
struct V_17 * V_30 ;
T_1 V_3 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned long V_25 ;
int V_46 ;
F_14 (priv, &timer_group_list, node) {
V_46 = F_3 ( V_2 , time , & V_3 ) ;
if ( V_46 < 0 )
return NULL ;
if ( V_3 > V_45 ) {
if ( ! ( V_2 -> V_25 & V_47 ) )
return NULL ;
V_30 = F_12 ( V_2 , V_3 ) ;
if ( ! V_30 )
continue;
return V_30 ;
}
for ( V_24 = 0 ; V_24 < V_48 ; V_24 ++ ) {
V_23 = V_48 - 1 - V_24 ;
F_6 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> V_28 & ( 1 << V_24 ) ) {
V_2 -> V_28 &= ~ ( 1 << V_24 ) ;
F_11 ( & V_2 -> V_39 [ V_23 ] . V_41 ,
V_3 | V_42 ) ;
F_11 ( & V_2 -> V_39 [ V_23 ] . V_40 , 0 ) ;
V_2 -> V_30 [ V_23 ] . V_31 = NULL ;
F_7 ( & V_2 -> V_26 , V_25 ) ;
return & V_2 -> V_30 [ V_23 ] ;
}
F_7 ( & V_2 -> V_26 , V_25 ) ;
}
}
return NULL ;
}
void F_15 ( struct V_17 * V_49 )
{
struct V_1 * V_2 = F_16 ( V_49 ,
struct V_1 , V_30 [ V_49 -> V_23 ] ) ;
F_17 ( & V_2 -> V_39 [ V_49 -> V_23 ] . V_41 , V_42 ) ;
}
void F_18 ( struct V_17 * V_49 )
{
struct V_1 * V_2 = F_16 ( V_49 ,
struct V_1 , V_30 [ V_49 -> V_23 ] ) ;
struct V_18 * V_19 ;
F_9 ( & V_2 -> V_39 [ V_49 -> V_23 ] . V_41 , V_42 ) ;
V_19 = V_2 -> V_30 [ V_49 -> V_23 ] . V_31 ;
if ( V_19 ) {
F_11 ( & V_2 -> V_39 [ V_49 -> V_23 ] . V_40 , 0 ) ;
F_11 ( & V_2 -> V_39 [ V_49 -> V_23 - 1 ] . V_40 , 0 ) ;
} else {
F_11 ( & V_2 -> V_39 [ V_49 -> V_23 ] . V_40 , 0 ) ;
}
}
void F_19 ( struct V_17 * V_49 , struct V_4 * time )
{
struct V_1 * V_2 = F_16 ( V_49 ,
struct V_1 , V_30 [ V_49 -> V_23 ] ) ;
struct V_18 * V_19 ;
T_1 V_3 ;
T_2 V_33 ;
V_19 = V_2 -> V_30 [ V_49 -> V_23 ] . V_31 ;
if ( V_19 ) {
V_33 = F_20 ( & V_2 -> V_39 [ V_49 -> V_23 ] . V_40 ) ;
V_3 = ( ( T_1 ) V_33 & V_50 ) * ( T_1 ) V_38 ;
V_33 = F_20 ( & V_2 -> V_39 [ V_49 -> V_23 - 1 ] . V_40 ) ;
V_3 += V_33 ;
} else {
V_3 = F_20 ( & V_2 -> V_39 [ V_49 -> V_23 ] . V_40 ) ;
}
F_1 ( V_2 , V_3 , time ) ;
}
void F_21 ( struct V_17 * V_49 )
{
struct V_1 * V_2 = F_16 ( V_49 ,
struct V_1 , V_30 [ V_49 -> V_23 ] ) ;
struct V_18 * V_19 ;
unsigned long V_25 ;
F_18 ( V_49 ) ;
V_19 = V_2 -> V_30 [ V_49 -> V_23 ] . V_31 ;
F_22 ( V_2 -> V_30 [ V_49 -> V_23 ] . V_51 , V_2 -> V_30 [ V_49 -> V_23 ] . V_52 ) ;
F_6 ( & V_2 -> V_26 , V_25 ) ;
if ( V_19 ) {
T_2 V_32 ;
V_32 = V_19 -> V_35 | ( V_19 -> V_35 <<
V_36 ) ;
F_17 ( V_2 -> V_37 , V_32 ) ;
V_2 -> V_28 |= V_19 -> V_27 ;
V_2 -> V_30 [ V_49 -> V_23 ] . V_31 = NULL ;
} else {
V_2 -> V_28 |= F_23 ( V_49 -> V_23 ) ;
}
F_7 ( & V_2 -> V_26 , V_25 ) ;
}
struct V_17 * F_24 ( T_3 V_53 , void * V_52 ,
const struct V_4 * time )
{
struct V_17 * V_43 ;
int V_46 ;
if ( F_25 ( & V_54 ) )
return NULL ;
if ( ! ( time -> V_6 + time -> V_9 ) ||
time -> V_6 < 0 || time -> V_9 < 0 )
return NULL ;
if ( time -> V_9 > V_55 )
return NULL ;
V_43 = F_13 ( time ) ;
if ( ! V_43 )
return NULL ;
V_46 = F_26 ( V_43 -> V_51 , V_53 ,
V_56 , L_1 , V_52 ) ;
if ( V_46 ) {
F_21 ( V_43 ) ;
return NULL ;
}
V_43 -> V_52 = V_52 ;
return V_43 ;
}
static int F_27 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
T_2 div ;
if ( V_2 -> V_25 & V_47 ) {
struct V_57 * V_59 ;
V_59 = F_28 ( NULL , NULL , L_2 ) ;
if ( V_59 ) {
F_29 ( V_59 , L_3 ,
& V_2 -> V_8 ) ;
F_30 ( V_59 ) ;
}
}
if ( V_2 -> V_8 <= 0 )
return - V_16 ;
if ( V_2 -> V_25 & V_47 ) {
div = ( 1 << ( V_60 >> 8 ) ) * 8 ;
V_2 -> V_8 /= div ;
}
return 0 ;
}
static int F_31 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
const T_2 V_61 [] = { 0 , V_48 } ;
const T_2 * V_62 ;
T_2 V_63 ;
T_2 V_64 ;
unsigned int V_24 ;
unsigned int V_65 ;
unsigned int V_66 = 0 ;
unsigned int V_51 ;
int V_67 ;
V_62 = F_32 ( V_58 , L_4 , & V_67 ) ;
if ( V_62 && V_67 % ( 2 * sizeof( T_2 ) ) != 0 ) {
F_33 ( L_5 ,
V_58 -> V_68 ) ;
return - V_16 ;
}
if ( ! V_62 ) {
V_62 = V_61 ;
V_67 = sizeof( V_61 ) ;
}
V_67 /= 2 * sizeof( T_2 ) ;
for ( V_24 = 0 ; V_24 < V_67 ; V_24 ++ ) {
V_63 = V_62 [ V_24 * 2 ] ;
V_64 = V_62 [ V_24 * 2 + 1 ] ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
V_51 = F_34 ( V_58 , V_66 ) ;
if ( ! V_51 ) {
F_33 ( L_6 ,
V_58 -> V_68 ) ;
return - V_16 ;
}
V_2 -> V_28 |= F_23 ( ( V_63 + V_65 ) ) ;
V_2 -> V_30 [ V_63 + V_65 ] . V_51 = V_51 ;
V_2 -> V_30 [ V_63 + V_65 ] . V_23 = V_63 + V_65 ;
V_66 ++ ;
}
}
return 0 ;
}
static void F_35 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
unsigned int V_24 = 0 ;
int V_46 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_2 ) {
F_33 ( L_7 ,
V_58 -> V_68 ) ;
return;
}
if ( F_37 ( V_58 , L_8 ) )
V_2 -> V_25 |= V_47 ;
V_2 -> V_39 = F_38 ( V_58 , V_24 ++ ) ;
if ( ! V_2 -> V_39 ) {
F_33 ( L_9 ,
V_58 -> V_68 ) ;
goto V_70;
}
if ( V_2 -> V_25 & V_47 ) {
V_2 -> V_37 = F_38 ( V_58 , V_24 ++ ) ;
if ( ! V_2 -> V_37 ) {
F_33 ( L_10 ,
V_58 -> V_68 ) ;
goto V_70;
}
}
V_46 = F_27 ( V_58 , V_2 ) ;
if ( V_46 < 0 ) {
F_33 ( L_11 , V_58 -> V_68 ) ;
goto V_70;
}
V_46 = F_31 ( V_58 , V_2 ) ;
if ( V_46 < 0 ) {
F_33 ( L_12 , V_58 -> V_68 ) ;
goto V_70;
}
F_39 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_25 & V_47 )
F_9 ( V_2 -> V_37 , V_60 ) ;
F_40 ( & V_2 -> V_71 , & V_54 ) ;
return;
V_70:
if ( V_2 -> V_39 )
F_41 ( V_2 -> V_39 ) ;
if ( V_2 -> V_37 )
F_41 ( V_2 -> V_37 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( void )
{
struct V_1 * V_2 ;
F_14 (priv, &timer_group_list, node) {
if ( V_2 -> V_25 & V_47 )
F_9 ( V_2 -> V_37 , V_60 ) ;
}
}
static int T_4 F_44 ( void )
{
struct V_57 * V_58 = NULL ;
F_45 (np, mpic_timer_ids)
F_35 ( V_58 ) ;
F_46 ( & V_72 ) ;
if ( F_25 ( & V_54 ) )
return - V_73 ;
return 0 ;
}
