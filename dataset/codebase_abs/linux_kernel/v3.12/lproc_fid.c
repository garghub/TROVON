static int
F_1 ( const char * V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
struct V_3 V_5 ;
int V_6 ;
F_2 ( V_4 != NULL ) ;
V_6 = sscanf ( V_1 , L_1 ,
( long long unsigned * ) & V_5 . V_7 ,
( long long unsigned * ) & V_5 . V_8 ) ;
if ( V_6 != 2 || ! F_3 ( & V_5 ) || F_4 ( & V_5 ) )
return - V_9 ;
* V_4 = V_5 ;
return 0 ;
}
static T_1
F_5 ( struct V_10 * V_10 , const char * V_1 ,
T_2 V_2 , T_3 * V_11 )
{
struct V_12 * V_13 = ( (struct V_14 * ) V_10 -> V_15 ) -> V_16 ;
int V_6 ;
F_2 ( V_13 != NULL ) ;
F_6 ( & V_13 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_2 , & V_13 -> V_18 ) ;
if ( V_6 == 0 ) {
F_7 ( V_19 , L_2 V_20 L_3 ,
V_13 -> V_21 , F_8 ( & V_13 -> V_18 ) ) ;
}
F_9 ( & V_13 -> V_17 ) ;
return V_2 ;
}
static int
F_10 ( struct V_14 * V_22 , void * V_23 )
{
struct V_12 * V_13 = (struct V_12 * ) V_22 -> V_16 ;
int V_6 ;
F_2 ( V_13 != NULL ) ;
F_6 ( & V_13 -> V_17 ) ;
V_6 = F_11 ( V_22 , L_4 V_24 L_5 V_24 L_6 , F_8 ( & V_13 -> V_18 ) ) ;
F_9 ( & V_13 -> V_17 ) ;
return V_6 ;
}
static T_1
F_12 ( struct V_10 * V_10 , const char * V_1 ,
T_2 V_2 , T_3 * V_11 )
{
struct V_12 * V_13 = ( (struct V_14 * ) V_10 -> V_15 ) -> V_16 ;
T_4 V_25 ;
int V_6 , V_26 ;
F_2 ( V_13 != NULL ) ;
V_6 = F_13 ( V_1 , V_2 , & V_26 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_27 == V_28 )
V_25 = V_29 ;
else
V_25 = V_30 ;
if ( V_26 <= V_25 && V_26 > 0 ) {
V_13 -> V_31 = V_26 ;
if ( V_6 == 0 ) {
F_7 ( V_19 , L_7 V_32 L_3 ,
V_13 -> V_21 , V_13 -> V_31 ) ;
}
}
F_9 ( & V_13 -> V_17 ) ;
return V_2 ;
}
static int
F_14 ( struct V_14 * V_22 , void * V_23 )
{
struct V_12 * V_13 = (struct V_12 * ) V_22 -> V_16 ;
int V_6 ;
F_2 ( V_13 != NULL ) ;
F_6 ( & V_13 -> V_17 ) ;
V_6 = F_11 ( V_22 , V_32 L_3 , V_13 -> V_31 ) ;
F_9 ( & V_13 -> V_17 ) ;
return V_6 ;
}
static int
F_15 ( struct V_14 * V_22 , void * V_23 )
{
struct V_12 * V_13 = (struct V_12 * ) V_22 -> V_16 ;
int V_6 ;
F_2 ( V_13 != NULL ) ;
F_6 ( & V_13 -> V_17 ) ;
V_6 = F_11 ( V_22 , V_33 L_3 , F_16 ( & V_13 -> V_34 ) ) ;
F_9 ( & V_13 -> V_17 ) ;
return V_6 ;
}
static int
F_17 ( struct V_14 * V_22 , void * V_23 )
{
struct V_12 * V_13 = (struct V_12 * ) V_22 -> V_16 ;
struct V_35 * V_36 ;
int V_6 ;
F_2 ( V_13 != NULL ) ;
if ( V_13 -> V_37 != NULL ) {
V_36 = & V_13 -> V_37 -> V_38 -> V_39 . V_36 ;
V_6 = F_11 ( V_22 , L_8 , V_36 -> V_40 . V_41 ) ;
} else {
V_6 = F_11 ( V_22 , L_8 , V_13 -> V_42 -> V_43 ) ;
}
return V_6 ;
}
