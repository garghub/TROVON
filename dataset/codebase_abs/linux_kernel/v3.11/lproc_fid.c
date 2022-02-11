static int
F_1 ( const char * V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
struct V_3 V_5 ;
int V_6 ;
V_7 ;
F_2 ( V_4 != NULL ) ;
V_6 = sscanf ( V_1 , L_1 ,
( long long unsigned * ) & V_5 . V_8 ,
( long long unsigned * ) & V_5 . V_9 ) ;
if ( V_6 != 2 || ! F_3 ( & V_5 ) || F_4 ( & V_5 ) )
RETURN ( - V_10 ) ;
* V_4 = V_5 ;
RETURN ( 0 ) ;
}
static T_1
F_5 ( struct V_11 * V_11 , const char * V_1 ,
T_2 V_2 , T_3 * V_12 )
{
struct V_13 * V_14 = ( (struct V_15 * ) V_11 -> V_16 ) -> V_17 ;
int V_6 ;
V_7 ;
F_2 ( V_14 != NULL ) ;
F_6 ( & V_14 -> V_18 ) ;
V_6 = F_1 ( V_1 , V_2 , & V_14 -> V_19 ) ;
if ( V_6 == 0 ) {
F_7 ( V_20 , L_2 V_21 L_3 ,
V_14 -> V_22 , F_8 ( & V_14 -> V_19 ) ) ;
}
F_9 ( & V_14 -> V_18 ) ;
RETURN ( V_2 ) ;
}
static int
F_10 ( struct V_15 * V_23 , void * V_24 )
{
struct V_13 * V_14 = (struct V_13 * ) V_23 -> V_17 ;
int V_6 ;
V_7 ;
F_2 ( V_14 != NULL ) ;
F_6 ( & V_14 -> V_18 ) ;
V_6 = F_11 ( V_23 , L_4 V_25 L_5 V_25 L_6 , F_8 ( & V_14 -> V_19 ) ) ;
F_9 ( & V_14 -> V_18 ) ;
RETURN ( V_6 ) ;
}
static T_1
F_12 ( struct V_11 * V_11 , const char * V_1 ,
T_2 V_2 , T_3 * V_12 )
{
struct V_13 * V_14 = ( (struct V_15 * ) V_11 -> V_16 ) -> V_17 ;
T_4 V_26 ;
int V_6 , V_27 ;
V_7 ;
F_2 ( V_14 != NULL ) ;
V_6 = F_13 ( V_1 , V_2 , & V_27 ) ;
if ( V_6 )
RETURN ( V_6 ) ;
F_6 ( & V_14 -> V_18 ) ;
if ( V_14 -> V_28 == V_29 )
V_26 = V_30 ;
else
V_26 = V_31 ;
if ( V_27 <= V_26 && V_27 > 0 ) {
V_14 -> V_32 = V_27 ;
if ( V_6 == 0 ) {
F_7 ( V_20 , L_7 V_33 L_3 ,
V_14 -> V_22 , V_14 -> V_32 ) ;
}
}
F_9 ( & V_14 -> V_18 ) ;
RETURN ( V_2 ) ;
}
static int
F_14 ( struct V_15 * V_23 , void * V_24 )
{
struct V_13 * V_14 = (struct V_13 * ) V_23 -> V_17 ;
int V_6 ;
V_7 ;
F_2 ( V_14 != NULL ) ;
F_6 ( & V_14 -> V_18 ) ;
V_6 = F_11 ( V_23 , V_33 L_3 , V_14 -> V_32 ) ;
F_9 ( & V_14 -> V_18 ) ;
RETURN ( V_6 ) ;
}
static int
F_15 ( struct V_15 * V_23 , void * V_24 )
{
struct V_13 * V_14 = (struct V_13 * ) V_23 -> V_17 ;
int V_6 ;
V_7 ;
F_2 ( V_14 != NULL ) ;
F_6 ( & V_14 -> V_18 ) ;
V_6 = F_11 ( V_23 , V_34 L_3 , F_16 ( & V_14 -> V_35 ) ) ;
F_9 ( & V_14 -> V_18 ) ;
RETURN ( V_6 ) ;
}
static int
F_17 ( struct V_15 * V_23 , void * V_24 )
{
struct V_13 * V_14 = (struct V_13 * ) V_23 -> V_17 ;
struct V_36 * V_37 ;
int V_6 ;
V_7 ;
F_2 ( V_14 != NULL ) ;
if ( V_14 -> V_38 != NULL ) {
V_37 = & V_14 -> V_38 -> V_39 -> V_40 . V_37 ;
V_6 = F_11 ( V_23 , L_8 , V_37 -> V_41 . V_42 ) ;
} else {
V_6 = F_11 ( V_23 , L_8 , V_14 -> V_43 -> V_44 ) ;
}
RETURN ( V_6 ) ;
}
