static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_3 = F_3 ( V_2 ) ) ) {
F_4 ( V_8 L_1 ) ;
return - V_9 ;
}
V_5 = F_5 ( V_3 , 0 ,
V_10 | V_11 ) ;
if ( F_6 ( V_5 ) ) {
F_4 ( V_8
L_2 ,
V_3 , F_7 ( V_5 ) ) ;
return F_7 ( V_5 ) ;
}
F_4 ( V_12 L_3 ,
F_8 ( V_5 ) ) ;
F_9 (
V_5 ,
F_10 ( (struct V_4 * ) V_2 ) ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_5 ) {
F_12 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
}
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_13 ,
unsigned int V_14 )
{
int V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 () ;
F_15 () ;
F_16 () ;
V_15 = F_17 ( V_13 , V_14 * 8 , & V_7 -> V_16 ) ;
V_15 += F_18 ( V_13 , V_14 * 8 , & V_7 -> V_17 ) ;
F_19 () ;
F_20 () ;
F_21 () ;
V_15 += F_22 ( V_7 -> V_5 , V_13 , V_14 ) ;
return V_15 ;
}
static int F_23 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
int V_15 ;
struct V_24 V_25 ;
struct V_6 * V_7 =
F_2 ( F_24 ( V_19 -> V_2 ) ) ;
if ( F_25 () ) {
F_26 ( V_26 , V_7 -> V_5 ) ;
F_27 ( V_26 , V_7 -> V_5 ) ;
F_28 ( V_26 , V_19 -> V_27 , NULL , NULL ) ;
F_29 ( V_26 , V_22 , V_21 , V_23 , V_19 -> V_28 ) ;
V_15 = F_30 ( V_26 ) ;
F_31 ( V_26 ) ;
} else {
F_14 () ;
F_15 () ;
F_16 () ;
F_32 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_15 = F_33 ( V_19 , & V_25 ) ;
while ( ( V_23 = V_25 . V_23 ) ) {
F_34 ( V_25 . V_22 . V_29 . V_30 ,
V_25 . V_21 . V_29 . V_30 ,
V_23 & V_31 ,
& V_7 -> V_16 , V_25 . V_32 , 1 ) ;
V_23 &= V_33 - 1 ;
V_15 = F_35 ( V_19 , & V_25 , V_23 ) ;
}
F_19 () ;
F_20 () ;
F_21 () ;
}
return V_15 ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_20 * V_22 , unsigned int V_23 )
{
int V_15 ;
struct V_24 V_25 ;
struct V_6 * V_7 =
F_2 ( F_24 ( V_19 -> V_2 ) ) ;
if ( F_25 () ) {
F_26 ( V_26 , V_7 -> V_5 ) ;
F_27 ( V_26 , V_7 -> V_5 ) ;
F_28 ( V_26 , V_19 -> V_27 , NULL , NULL ) ;
F_29 ( V_26 , V_22 , V_21 , V_23 , V_19 -> V_28 ) ;
V_15 = F_37 ( V_26 ) ;
F_31 ( V_26 ) ;
} else {
F_14 () ;
F_15 () ;
F_16 () ;
F_32 ( & V_25 , V_21 , V_22 , V_23 ) ;
V_15 = F_33 ( V_19 , & V_25 ) ;
while ( ( V_23 = V_25 . V_23 ) ) {
F_34 ( V_25 . V_22 . V_29 . V_30 ,
V_25 . V_21 . V_29 . V_30 ,
V_23 & V_31 ,
& V_7 -> V_17 , V_25 . V_32 , 0 ) ;
V_23 &= V_33 - 1 ;
V_15 = F_35 ( V_19 , & V_25 , V_23 ) ;
}
F_19 () ;
F_20 () ;
F_21 () ;
}
return V_15 ;
}
