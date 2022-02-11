static inline void F_1 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , const T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_10 ;
T_1 V_11 ;
T_1 V_12 ;
F_7 ( V_9 , V_7 ) ;
V_2 = F_8 ( V_7 ) ;
while ( ( V_10 = F_3 ( V_2 , V_13 ) ) != 0 ) {
F_9 (bit, &status, msi->num_of_vectors) {
F_4 ( V_2 -> V_14 + ( V_11 * sizeof( T_1 ) ) ) ;
V_12 = F_10 ( V_2 -> V_15 , V_11 ) ;
if ( V_12 )
F_11 ( V_12 ) ;
else
F_12 ( & V_2 -> V_16 -> V_17 , L_1 ) ;
}
}
F_13 ( V_9 , V_7 ) ;
}
static void F_14 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_2 V_22 = V_2 -> V_23 + ( V_19 -> V_24 * sizeof( T_1 ) ) ;
V_21 -> V_25 = F_16 ( V_22 ) ;
V_21 -> V_26 = F_17 ( V_22 ) ;
V_21 -> V_19 = V_19 -> V_24 ;
F_18 ( & V_2 -> V_16 -> V_17 , L_2 ,
( int ) V_19 -> V_24 , V_21 -> V_26 , V_21 -> V_25 ) ;
}
static int F_19 ( struct V_18 * V_18 ,
const struct V_27 * V_28 , bool V_29 )
{
return - V_30 ;
}
static int F_20 ( struct V_31 * V_32 , unsigned int V_12 ,
unsigned int V_33 , void * args )
{
struct V_1 * V_2 = V_32 -> V_34 ;
unsigned long V_11 ;
T_1 V_28 ;
F_21 ( V_33 != 1 ) ;
F_22 ( & V_2 -> V_35 ) ;
V_11 = F_23 ( V_2 -> V_36 , V_2 -> V_37 ) ;
if ( V_11 >= V_2 -> V_37 ) {
F_24 ( & V_2 -> V_35 ) ;
return - V_38 ;
}
F_25 ( V_11 , V_2 -> V_36 ) ;
F_24 ( & V_2 -> V_35 ) ;
F_26 ( V_32 , V_12 , V_11 , & V_39 ,
V_32 -> V_34 , V_40 ,
NULL , NULL ) ;
V_28 = F_3 ( V_2 , V_41 ) ;
V_28 |= 1 << V_11 ;
F_1 ( V_2 , V_28 , V_41 ) ;
return 0 ;
}
static void F_27 ( struct V_31 * V_32 ,
unsigned int V_12 , unsigned int V_33 )
{
struct V_18 * V_42 = F_28 ( V_32 , V_12 ) ;
struct V_1 * V_2 = F_15 ( V_42 ) ;
T_1 V_28 ;
F_22 ( & V_2 -> V_35 ) ;
if ( ! F_29 ( V_42 -> V_24 , V_2 -> V_36 ) ) {
F_12 ( & V_2 -> V_16 -> V_17 , L_3 ,
V_42 -> V_24 ) ;
} else {
F_30 ( V_42 -> V_24 , V_2 -> V_36 ) ;
V_28 = F_3 ( V_2 , V_41 ) ;
V_28 &= ~ ( 1 << V_42 -> V_24 ) ;
F_1 ( V_2 , V_28 , V_41 ) ;
}
F_24 ( & V_2 -> V_35 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = F_32 ( V_2 -> V_16 -> V_17 . V_45 ) ;
V_2 -> V_15 = F_33 ( NULL , V_2 -> V_37 ,
& V_46 , V_2 ) ;
if ( ! V_2 -> V_15 ) {
F_12 ( & V_2 -> V_16 -> V_17 , L_4 ) ;
return - V_47 ;
}
V_2 -> V_48 = F_34 ( V_44 ,
& V_49 , V_2 -> V_15 ) ;
if ( ! V_2 -> V_48 ) {
F_12 ( & V_2 -> V_16 -> V_17 , L_5 ) ;
F_35 ( V_2 -> V_15 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_48 ) ;
F_35 ( V_2 -> V_15 ) ;
}
static int F_37 ( struct V_50 * V_16 )
{
struct V_1 * V_2 = F_38 ( V_16 ) ;
F_1 ( V_2 , 0 , V_41 ) ;
F_39 ( V_2 -> V_51 , NULL ) ;
F_40 ( V_2 -> V_51 , NULL ) ;
F_36 ( V_2 ) ;
F_41 ( V_16 , NULL ) ;
return 0 ;
}
static int F_42 ( struct V_50 * V_16 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 = V_16 -> V_17 . V_45 ;
struct V_54 * V_55 ;
int V_56 ;
V_2 = F_43 ( & V_16 -> V_17 , sizeof( struct V_1 ) ,
V_57 ) ;
if ( ! V_2 )
return - V_47 ;
F_44 ( & V_2 -> V_35 ) ;
V_2 -> V_16 = V_16 ;
V_55 = F_45 ( V_16 , V_58 , L_6 ) ;
V_2 -> V_5 = F_46 ( & V_16 -> V_17 , V_55 ) ;
if ( F_47 ( V_2 -> V_5 ) ) {
F_12 ( & V_16 -> V_17 , L_7 ) ;
return F_48 ( V_2 -> V_5 ) ;
}
V_55 = F_45 ( V_16 , V_58 ,
L_8 ) ;
V_2 -> V_14 = F_46 ( & V_16 -> V_17 , V_55 ) ;
if ( F_47 ( V_2 -> V_14 ) ) {
F_12 ( & V_16 -> V_17 , L_9 ) ;
return F_48 ( V_2 -> V_14 ) ;
}
V_2 -> V_23 = V_55 -> V_59 ;
if ( F_49 ( V_53 , L_10 , & V_2 -> V_37 ) ) {
F_12 ( & V_16 -> V_17 , L_11 ) ;
return - V_30 ;
}
V_56 = F_31 ( V_2 ) ;
if ( V_56 )
return V_56 ;
V_2 -> V_51 = F_50 ( V_16 , 0 ) ;
if ( V_2 -> V_51 < 0 ) {
F_12 ( & V_16 -> V_17 , L_12 , V_2 -> V_51 ) ;
V_56 = V_2 -> V_51 ;
goto V_60;
}
F_51 ( V_2 -> V_51 , F_5 , V_2 ) ;
F_41 ( V_16 , V_2 ) ;
return 0 ;
V_60:
F_37 ( V_16 ) ;
return V_56 ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_61 ) ;
}
