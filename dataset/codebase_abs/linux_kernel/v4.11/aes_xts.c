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
V_15 = F_14 ( V_2 , V_13 , V_14 ) ;
if ( V_15 )
return V_15 ;
F_15 () ;
F_16 () ;
F_17 () ;
V_15 = F_18 ( V_13 + V_14 / 2 , ( V_14 / 2 ) * 8 , & V_7 -> V_16 ) ;
V_15 += F_18 ( V_13 , ( V_14 / 2 ) * 8 , & V_7 -> V_17 ) ;
V_15 += F_19 ( V_13 , ( V_14 / 2 ) * 8 , & V_7 -> V_18 ) ;
F_20 () ;
F_21 () ;
F_22 () ;
V_15 += F_23 ( V_7 -> V_5 , V_13 , V_14 ) ;
return V_15 ;
}
static int F_24 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 ,
unsigned int V_24 , int V_25 )
{
int V_15 ;
T_1 V_26 [ V_27 ] ;
T_1 * V_28 ;
struct V_29 V_30 ;
struct V_6 * V_7 =
F_2 ( F_25 ( V_20 -> V_2 ) ) ;
if ( F_26 () ) {
F_27 ( V_31 , V_7 -> V_5 ) ;
F_28 ( V_31 , V_7 -> V_5 ) ;
F_29 ( V_31 , V_20 -> V_32 , NULL , NULL ) ;
F_30 ( V_31 , V_23 , V_22 , V_24 , V_20 -> V_33 ) ;
V_15 = V_25 ? F_31 ( V_31 ) : F_32 ( V_31 ) ;
F_33 ( V_31 ) ;
} else {
F_15 () ;
F_16 () ;
F_17 () ;
F_34 ( & V_30 , V_22 , V_23 , V_24 ) ;
V_15 = F_35 ( V_20 , & V_30 ) ;
V_28 = V_30 . V_28 ;
memset ( V_26 , 0 , V_27 ) ;
F_36 ( V_28 , V_26 , & V_7 -> V_16 ) ;
while ( ( V_24 = V_30 . V_24 ) ) {
if ( V_25 )
F_37 ( V_30 . V_23 . V_34 . V_35 , V_30 . V_22 . V_34 . V_35 ,
V_24 & V_36 , & V_7 -> V_17 , NULL , V_26 ) ;
else
F_38 ( V_30 . V_23 . V_34 . V_35 , V_30 . V_22 . V_34 . V_35 ,
V_24 & V_36 , & V_7 -> V_18 , NULL , V_26 ) ;
V_24 &= V_27 - 1 ;
V_15 = F_39 ( V_20 , & V_30 , V_24 ) ;
}
F_20 () ;
F_21 () ;
F_22 () ;
}
return V_15 ;
}
static int F_40 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 , unsigned int V_24 )
{
return F_24 ( V_20 , V_22 , V_23 , V_24 , 1 ) ;
}
static int F_41 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_21 * V_23 , unsigned int V_24 )
{
return F_24 ( V_20 , V_22 , V_23 , V_24 , 0 ) ;
}
