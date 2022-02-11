static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_5 = F_4 ( V_3 , 0 ,
V_8 | V_9 ) ;
if ( F_5 ( V_5 ) ) {
F_6 ( V_10
L_1 ,
V_3 , F_7 ( V_5 ) ) ;
return F_7 ( V_5 ) ;
}
F_6 ( V_11 L_2 ,
F_8 ( V_5 ) ) ;
F_9 (
V_5 ,
F_10 ( (struct V_4 * ) V_2 ) ) ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_5 ) {
F_12 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
}
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_12 ,
unsigned int V_13 )
{
int V_14 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
F_14 () ;
F_15 () ;
F_16 () ;
V_14 = F_17 ( V_12 , V_13 * 8 , & V_7 -> V_15 ) ;
V_14 += F_18 ( V_12 , V_13 * 8 , & V_7 -> V_16 ) ;
F_19 () ;
F_20 () ;
F_21 () ;
V_14 += F_22 ( V_7 -> V_5 , V_12 , V_13 ) ;
return V_14 ;
}
static int F_23 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_19 * V_21 , unsigned int V_22 )
{
int V_14 ;
struct V_23 V_24 ;
struct V_6 * V_7 =
F_3 ( F_24 ( V_18 -> V_2 ) ) ;
if ( F_25 () ) {
F_26 ( V_25 , V_7 -> V_5 ) ;
F_27 ( V_25 , V_7 -> V_5 ) ;
F_28 ( V_25 , V_18 -> V_26 , NULL , NULL ) ;
F_29 ( V_25 , V_21 , V_20 , V_22 , V_18 -> V_27 ) ;
V_14 = F_30 ( V_25 ) ;
F_31 ( V_25 ) ;
} else {
F_14 () ;
F_15 () ;
F_16 () ;
F_32 ( & V_24 , V_20 , V_21 , V_22 ) ;
V_14 = F_33 ( V_18 , & V_24 ) ;
while ( ( V_22 = V_24 . V_22 ) ) {
F_34 ( V_24 . V_21 . V_28 . V_29 ,
V_24 . V_20 . V_28 . V_29 ,
V_22 & V_30 ,
& V_7 -> V_15 , V_24 . V_31 , 1 ) ;
V_22 &= V_32 - 1 ;
V_14 = F_35 ( V_18 , & V_24 , V_22 ) ;
}
F_19 () ;
F_20 () ;
F_21 () ;
}
return V_14 ;
}
static int F_36 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_19 * V_21 , unsigned int V_22 )
{
int V_14 ;
struct V_23 V_24 ;
struct V_6 * V_7 =
F_3 ( F_24 ( V_18 -> V_2 ) ) ;
if ( F_25 () ) {
F_26 ( V_25 , V_7 -> V_5 ) ;
F_27 ( V_25 , V_7 -> V_5 ) ;
F_28 ( V_25 , V_18 -> V_26 , NULL , NULL ) ;
F_29 ( V_25 , V_21 , V_20 , V_22 , V_18 -> V_27 ) ;
V_14 = F_37 ( V_25 ) ;
F_31 ( V_25 ) ;
} else {
F_14 () ;
F_15 () ;
F_16 () ;
F_32 ( & V_24 , V_20 , V_21 , V_22 ) ;
V_14 = F_33 ( V_18 , & V_24 ) ;
while ( ( V_22 = V_24 . V_22 ) ) {
F_34 ( V_24 . V_21 . V_28 . V_29 ,
V_24 . V_20 . V_28 . V_29 ,
V_22 & V_30 ,
& V_7 -> V_16 , V_24 . V_31 , 0 ) ;
V_22 &= V_32 - 1 ;
V_14 = F_35 ( V_18 , & V_24 , V_22 ) ;
}
F_19 () ;
F_20 () ;
F_21 () ;
}
return V_14 ;
}
