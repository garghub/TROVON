static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = V_4 - V_2 -> V_5 ;
V_3 = F_2 () % V_3 ;
V_3 += V_2 -> V_5 ;
return V_3 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_4 () >> V_2 -> V_6 ;
}
static struct V_7 * F_5 ( struct V_1
* V_2 )
{
struct V_7 * V_8 ;
int V_3 ;
F_6 () ;
if ( F_7 () == V_2 -> V_9 )
V_3 = F_3 ( V_2 ) ;
else
V_3 = F_1 ( V_2 ) ;
V_8 = F_8 ( V_2 , V_3 ) ;
F_9 ( V_8 ) ;
return V_8 ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_11 ( V_8 ) ;
F_12 () ;
}
void F_13 ( struct V_10 * V_11 , unsigned long V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_7 * V_8 ;
unsigned long V_16 ;
int V_17 , V_18 , V_19 , V_20 , V_21 ;
V_19 = V_22 ;
V_18 = ( 1UL << V_19 ) ;
V_17 = F_14 ( V_19 ) ;
V_16 = F_15 ( ( ( V_13 + V_18 - 1 ) >> V_19 ) , V_23 ) ;
F_16 ( V_24 ) ;
F_17 ( V_25 , L_1 , V_11 ,
V_12 , V_13 , V_11 -> V_26 [ 0 ] ) ;
F_18 ( & V_11 -> V_27 ) ;
F_19 (gid, gms->ms_asidmap) {
F_16 ( V_28 ) ;
V_2 = F_20 ( V_20 ) ;
V_15 = V_11 -> V_29 + V_20 ;
V_21 = V_15 -> V_30 ;
if ( V_15 -> V_31 && V_21 ) {
F_16 ( V_32 ) ;
V_21 = F_21 ( V_21 , V_12 ) ;
F_17 ( V_25 ,
L_2 ,
V_20 , V_21 , V_12 , V_17 , V_16 , V_15 -> V_31 ) ;
V_8 = F_5 ( V_2 ) ;
F_22 ( V_8 , V_12 , ~ 0 , V_21 , V_17 , 0 ,
V_16 - 1 , V_15 -> V_31 ) ;
F_10 ( V_8 ) ;
} else {
F_16 ( V_33 ) ;
V_15 -> V_30 = 0 ;
F_23 ( V_2 -> V_34 , V_11 -> V_26 ) ;
F_17 ( V_25 ,
L_3 ,
V_20 , V_21 , V_15 -> V_31 ,
V_11 -> V_26 [ 0 ] ) ;
}
}
F_24 ( & V_11 -> V_27 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_17 ( V_25 , L_4 , V_2 -> V_34 ) ;
V_8 = F_5 ( V_2 ) ;
F_22 ( V_8 , 0 , ~ 0 , 0 , 1 , 1 , V_23 - 1 , 0xffff ) ;
F_10 ( V_8 ) ;
}
static void F_26 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
unsigned long V_12 , unsigned long V_39 )
{
struct V_10 * V_11 = F_27 ( V_36 , struct V_10 ,
V_40 ) ;
F_16 ( V_41 ) ;
F_28 ( & V_11 -> V_42 ) ;
F_17 ( V_25 , L_5 , V_11 ,
V_12 , V_39 , F_29 ( & V_11 -> V_42 ) ) ;
F_13 ( V_11 , V_12 , V_39 - V_12 ) ;
}
static void F_30 ( struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned long V_12 ,
unsigned long V_39 )
{
struct V_10 * V_11 = F_27 ( V_36 , struct V_10 ,
V_40 ) ;
( void ) F_31 ( & V_11 -> V_42 ) ;
F_32 ( & V_11 -> V_43 ) ;
F_17 ( V_25 , L_6 , V_11 , V_12 , V_39 ) ;
}
static void F_33 ( struct V_35 * V_36 , struct V_37 * V_38 ,
unsigned long V_44 )
{
struct V_10 * V_11 = F_27 ( V_36 , struct V_10 ,
V_40 ) ;
F_16 ( V_45 ) ;
F_13 ( V_11 , V_44 , V_46 ) ;
F_17 ( V_25 , L_7 , V_11 , V_44 ) ;
}
static void F_34 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_10 * V_11 = F_27 ( V_36 , struct V_10 ,
V_40 ) ;
V_11 -> V_47 = 1 ;
F_17 ( V_25 , L_8 , V_11 ) ;
}
static struct V_35 * F_35 ( struct V_37 * V_38 ,
const struct V_48 * V_49 )
{
struct V_35 * V_36 , * V_50 = NULL ;
struct V_51 * V_3 ;
if ( V_38 -> V_52 ) {
F_36 () ;
F_37 (mn, n, &mm->mmu_notifier_mm->list,
hlist)
if ( V_36 -> V_49 == V_49 ) {
V_50 = V_36 ;
break;
}
F_38 () ;
}
return V_50 ;
}
struct V_10 * F_39 ( void )
{
struct V_10 * V_11 ;
struct V_35 * V_36 ;
int V_53 ;
V_36 = F_35 ( V_54 -> V_38 , & V_55 ) ;
if ( V_36 ) {
V_11 = F_27 ( V_36 , struct V_10 , V_40 ) ;
F_28 ( & V_11 -> V_56 ) ;
} else {
V_11 = F_40 ( sizeof( * V_11 ) , V_57 ) ;
if ( V_11 ) {
F_16 ( V_58 ) ;
F_41 ( & V_11 -> V_27 ) ;
V_11 -> V_40 . V_49 = & V_55 ;
F_42 ( & V_11 -> V_56 , 1 ) ;
F_43 ( & V_11 -> V_43 ) ;
V_53 = F_44 ( & V_11 -> V_40 , V_54 -> V_38 ) ;
if ( V_53 )
goto error;
}
}
F_17 ( V_25 , L_9 , V_11 ,
F_29 ( & V_11 -> V_56 ) ) ;
return V_11 ;
error:
F_45 ( V_11 ) ;
return F_46 ( V_53 ) ;
}
void F_47 ( struct V_10 * V_11 )
{
F_17 ( V_25 , L_10 , V_11 ,
F_29 ( & V_11 -> V_56 ) , V_11 -> V_47 ) ;
if ( F_48 ( & V_11 -> V_56 ) == 0 ) {
if ( ! V_11 -> V_47 )
F_49 ( & V_11 -> V_40 , V_54 -> V_38 ) ;
F_45 ( V_11 ) ;
F_16 ( V_59 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
int V_60 , V_61 = 0 , V_3 ;
V_60 = F_51 ( V_2 -> V_9 ) ;
if ( V_60 ) {
V_3 = 1 << F_52 ( V_60 - 1 ) ;
V_61 = F_53 ( 0 , F_52 ( V_3 - 1 ) - F_52 ( V_62 - 1 ) ) ;
}
V_2 -> V_6 = V_61 ;
V_2 -> V_5 = ( V_60 + ( 1 << V_61 ) - 1 ) >> V_61 ;
}
