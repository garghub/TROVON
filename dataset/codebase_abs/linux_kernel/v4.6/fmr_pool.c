static inline T_1 F_1 ( T_2 V_1 )
{
return F_2 ( ( T_1 ) V_1 , ( T_1 ) ( V_1 >> 32 ) , 0 ) &
( V_2 - 1 ) ;
}
static inline struct V_3 * F_3 ( struct V_4 * V_5 ,
T_2 * V_6 ,
int V_7 ,
T_2 V_8 )
{
struct V_9 * V_10 ;
struct V_3 * V_11 ;
if ( ! V_5 -> V_12 )
return NULL ;
V_10 = V_5 -> V_12 + F_1 ( * V_6 ) ;
F_4 (fmr, bucket, cache_node)
if ( V_8 == V_11 -> V_8 &&
V_7 == V_11 -> V_7 &&
! memcmp ( V_6 , V_11 -> V_6 ,
V_7 * sizeof *V_6 ) )
return V_11 ;
return NULL ;
}
static void F_5 ( struct V_4 * V_5 )
{
int V_13 ;
struct V_3 * V_11 ;
F_6 ( V_14 ) ;
F_6 ( V_15 ) ;
F_7 ( & V_5 -> V_16 ) ;
F_8 (fmr, &pool->dirty_list, list) {
F_9 ( & V_11 -> V_17 ) ;
V_11 -> V_18 = 0 ;
F_10 ( & V_11 -> V_11 -> V_19 , & V_15 ) ;
#ifdef F_11
if ( V_11 -> V_20 != 0 ) {
F_12 ( V_21 L_1 ,
V_11 , V_11 -> V_20 ) ;
}
#endif
}
F_13 ( & V_5 -> V_22 , & V_14 ) ;
V_5 -> V_23 = 0 ;
F_14 ( & V_5 -> V_16 ) ;
if ( F_15 ( & V_14 ) ) {
return;
}
V_13 = F_16 ( & V_15 ) ;
if ( V_13 )
F_12 ( V_21 L_2 , V_13 ) ;
F_7 ( & V_5 -> V_16 ) ;
F_17 ( & V_14 , & V_5 -> V_24 ) ;
F_14 ( & V_5 -> V_16 ) ;
}
static int F_18 ( void * V_25 )
{
struct V_4 * V_5 = V_25 ;
do {
if ( F_19 ( & V_5 -> V_26 ) - F_19 ( & V_5 -> V_27 ) < 0 ) {
F_5 ( V_5 ) ;
F_20 ( & V_5 -> V_26 ) ;
F_21 ( & V_5 -> V_28 ) ;
if ( V_5 -> V_29 )
V_5 -> V_29 ( V_5 , V_5 -> V_30 ) ;
}
F_22 ( V_31 ) ;
if ( F_19 ( & V_5 -> V_26 ) - F_19 ( & V_5 -> V_27 ) >= 0 &&
! F_23 () )
F_24 () ;
F_25 ( V_32 ) ;
} while ( ! F_23 () );
return 0 ;
}
struct V_4 * F_26 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 ;
struct V_4 * V_5 ;
int V_39 ;
int V_13 ;
int V_40 ;
if ( ! V_36 )
return F_27 ( - V_41 ) ;
V_38 = V_34 -> V_38 ;
if ( ! V_38 -> V_42 || ! V_38 -> V_43 ||
! V_38 -> V_44 || ! V_38 -> V_45 ) {
F_28 ( V_21 L_3 , V_38 -> V_46 ) ;
return F_27 ( - V_47 ) ;
}
if ( ! V_38 -> V_48 . V_49 )
V_40 = V_50 ;
else
V_40 = V_38 -> V_48 . V_49 ;
V_5 = F_29 ( sizeof *V_5 , V_51 ) ;
if ( ! V_5 )
return F_27 ( - V_52 ) ;
V_5 -> V_12 = NULL ;
V_5 -> V_29 = V_36 -> V_29 ;
V_5 -> V_30 = V_36 -> V_30 ;
F_30 ( & V_5 -> V_24 ) ;
F_30 ( & V_5 -> V_22 ) ;
if ( V_36 -> V_53 ) {
V_5 -> V_12 =
F_29 ( V_2 * sizeof * V_5 -> V_12 ,
V_51 ) ;
if ( ! V_5 -> V_12 ) {
F_12 ( V_21 L_4 ) ;
V_13 = - V_52 ;
goto V_54;
}
for ( V_39 = 0 ; V_39 < V_2 ; ++ V_39 )
F_31 ( V_5 -> V_12 + V_39 ) ;
}
V_5 -> V_55 = 0 ;
V_5 -> V_56 = V_36 -> V_57 ;
V_5 -> V_40 = V_40 ;
V_5 -> V_58 = V_36 -> V_58 ;
V_5 -> V_23 = 0 ;
F_32 ( & V_5 -> V_16 ) ;
F_33 ( & V_5 -> V_27 , 0 ) ;
F_33 ( & V_5 -> V_26 , 0 ) ;
F_34 ( & V_5 -> V_28 ) ;
V_5 -> V_59 = F_35 ( F_18 ,
V_5 ,
L_5 ,
V_38 -> V_46 ) ;
if ( F_36 ( V_5 -> V_59 ) ) {
F_12 ( V_21 L_6 ) ;
V_13 = F_37 ( V_5 -> V_59 ) ;
goto V_54;
}
{
struct V_3 * V_11 ;
struct V_60 V_61 = {
. V_56 = V_36 -> V_57 ,
. V_62 = V_5 -> V_40 ,
. V_63 = V_36 -> V_63
} ;
int V_64 = sizeof *V_11 ;
if ( V_5 -> V_12 )
V_64 += V_36 -> V_57 * sizeof ( T_2 ) ;
for ( V_39 = 0 ; V_39 < V_36 -> V_55 ; ++ V_39 ) {
V_11 = F_29 ( V_64 , V_51 ) ;
if ( ! V_11 )
goto V_65;
V_11 -> V_5 = V_5 ;
V_11 -> V_18 = 0 ;
V_11 -> V_20 = 0 ;
F_38 ( & V_11 -> V_17 ) ;
V_11 -> V_11 = F_39 ( V_34 , V_36 -> V_66 , & V_61 ) ;
if ( F_36 ( V_11 -> V_11 ) ) {
F_12 ( V_21 L_7 ,
V_39 ) ;
F_40 ( V_11 ) ;
goto V_65;
}
F_10 ( & V_11 -> V_19 , & V_5 -> V_24 ) ;
++ V_5 -> V_55 ;
}
}
return V_5 ;
V_54:
F_40 ( V_5 -> V_12 ) ;
F_40 ( V_5 ) ;
return F_27 ( V_13 ) ;
V_65:
F_41 ( V_5 ) ;
return F_27 ( - V_52 ) ;
}
void F_41 ( struct V_4 * V_5 )
{
struct V_3 * V_11 ;
struct V_3 * V_67 ;
F_6 ( V_15 ) ;
int V_39 ;
F_42 ( V_5 -> V_59 ) ;
F_5 ( V_5 ) ;
V_39 = 0 ;
F_43 (fmr, tmp, &pool->free_list, list) {
if ( V_11 -> V_18 ) {
F_30 ( & V_15 ) ;
F_10 ( & V_11 -> V_11 -> V_19 , & V_15 ) ;
F_16 ( & V_15 ) ;
}
F_44 ( V_11 -> V_11 ) ;
F_45 ( & V_11 -> V_19 ) ;
F_40 ( V_11 ) ;
++ V_39 ;
}
if ( V_39 < V_5 -> V_55 )
F_12 ( V_21 L_8 ,
V_5 -> V_55 - V_39 ) ;
F_40 ( V_5 -> V_12 ) ;
F_40 ( V_5 ) ;
}
int F_46 ( struct V_4 * V_5 )
{
int V_68 ;
struct V_3 * V_11 , * V_69 ;
F_7 ( & V_5 -> V_16 ) ;
F_43 (fmr, next, &pool->free_list, list) {
if ( V_11 -> V_18 > 0 )
F_47 ( & V_11 -> V_19 , & V_5 -> V_22 ) ;
}
F_14 ( & V_5 -> V_16 ) ;
V_68 = F_48 ( & V_5 -> V_27 ) ;
F_49 ( V_5 -> V_59 ) ;
if ( F_50 ( V_5 -> V_28 ,
F_19 ( & V_5 -> V_26 ) - V_68 >= 0 ) )
return - V_70 ;
return 0 ;
}
struct V_3 * F_51 ( struct V_4 * V_71 ,
T_2 * V_6 ,
int V_72 ,
T_2 V_8 )
{
struct V_4 * V_5 = V_71 ;
struct V_3 * V_11 ;
unsigned long V_73 ;
int V_74 ;
if ( V_72 < 1 || V_72 > V_5 -> V_56 )
return F_27 ( - V_41 ) ;
F_52 ( & V_5 -> V_16 , V_73 ) ;
V_11 = F_3 ( V_5 ,
V_6 ,
V_72 ,
V_8 ) ;
if ( V_11 ) {
++ V_11 -> V_20 ;
if ( V_11 -> V_20 == 1 ) {
F_45 ( & V_11 -> V_19 ) ;
}
F_53 ( & V_5 -> V_16 , V_73 ) ;
return V_11 ;
}
if ( F_15 ( & V_5 -> V_24 ) ) {
F_53 ( & V_5 -> V_16 , V_73 ) ;
return F_27 ( - V_75 ) ;
}
V_11 = F_54 ( V_5 -> V_24 . V_69 , struct V_3 , V_19 ) ;
F_45 ( & V_11 -> V_19 ) ;
F_9 ( & V_11 -> V_17 ) ;
F_53 ( & V_5 -> V_16 , V_73 ) ;
V_74 = F_55 ( V_11 -> V_11 , V_6 , V_72 ,
V_8 ) ;
if ( V_74 ) {
F_52 ( & V_5 -> V_16 , V_73 ) ;
F_56 ( & V_11 -> V_19 , & V_5 -> V_24 ) ;
F_53 ( & V_5 -> V_16 , V_73 ) ;
F_12 ( V_21 L_9 , V_74 ) ;
return F_27 ( V_74 ) ;
}
++ V_11 -> V_18 ;
V_11 -> V_20 = 1 ;
if ( V_5 -> V_12 ) {
V_11 -> V_8 = V_8 ;
V_11 -> V_7 = V_72 ;
memcpy ( V_11 -> V_6 , V_6 , V_72 * sizeof( * V_6 ) ) ;
F_52 ( & V_5 -> V_16 , V_73 ) ;
F_57 ( & V_11 -> V_17 ,
V_5 -> V_12 + F_1 ( V_11 -> V_6 [ 0 ] ) ) ;
F_53 ( & V_5 -> V_16 , V_73 ) ;
}
return V_11 ;
}
int F_58 ( struct V_3 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_73 ;
V_5 = V_11 -> V_5 ;
F_52 ( & V_5 -> V_16 , V_73 ) ;
-- V_11 -> V_20 ;
if ( ! V_11 -> V_20 ) {
if ( V_11 -> V_18 < V_5 -> V_40 ) {
F_10 ( & V_11 -> V_19 , & V_5 -> V_24 ) ;
} else {
F_10 ( & V_11 -> V_19 , & V_5 -> V_22 ) ;
if ( ++ V_5 -> V_23 >= V_5 -> V_58 ) {
F_20 ( & V_5 -> V_27 ) ;
F_49 ( V_5 -> V_59 ) ;
}
}
}
#ifdef F_11
if ( V_11 -> V_20 < 0 )
F_12 ( V_21 L_10 ,
V_11 , V_11 -> V_20 ) ;
#endif
F_53 ( & V_5 -> V_16 , V_73 ) ;
return 0 ;
}
