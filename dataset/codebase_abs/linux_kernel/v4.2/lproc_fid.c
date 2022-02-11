static int
F_1 ( const char T_1 * V_1 , T_2 V_2 ,
struct V_3 * V_4 )
{
struct V_3 V_5 ;
int V_6 ;
char V_7 [ V_8 ] ;
F_2 ( V_4 != NULL ) ;
if ( V_2 >= sizeof( V_7 ) )
return - V_9 ;
if ( F_3 ( V_7 , V_1 , V_2 ) )
return - V_10 ;
V_7 [ V_2 ] = 0 ;
if ( V_2 == 5 && strcmp ( V_7 , L_1 ) == 0 ) {
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return V_2 ;
}
V_6 = sscanf ( V_7 , L_2 ,
( unsigned long long * ) & V_5 . V_11 ,
( unsigned long long * ) & V_5 . V_12 ) ;
if ( ! F_4 ( & V_5 ) || F_5 ( & V_5 ) ||
V_5 . V_11 < V_4 -> V_11 || V_5 . V_12 > V_4 -> V_12 )
return - V_9 ;
* V_4 = V_5 ;
return V_2 ;
}
static T_3
F_6 ( struct V_13 * V_13 ,
const char T_1 * V_1 ,
T_2 V_2 , T_4 * V_14 )
{
struct V_15 * V_16 ;
int V_6 ;
V_16 = ( (struct V_17 * ) V_13 -> V_18 ) -> V_19 ;
F_2 ( V_16 != NULL ) ;
F_7 ( & V_16 -> V_20 ) ;
V_6 = F_1 ( V_1 , V_2 , & V_16 -> V_21 ) ;
if ( V_6 == 0 ) {
F_8 ( V_22 , L_3 V_23 L_4 ,
V_16 -> V_24 , F_9 ( & V_16 -> V_21 ) ) ;
}
F_10 ( & V_16 -> V_20 ) ;
return V_2 ;
}
static int
F_11 ( struct V_17 * V_25 , void * V_26 )
{
struct V_15 * V_16 = (struct V_15 * ) V_25 -> V_19 ;
F_2 ( V_16 != NULL ) ;
F_7 ( & V_16 -> V_20 ) ;
F_12 ( V_25 , L_5 , F_9 ( & V_16 -> V_21 ) ) ;
F_10 ( & V_16 -> V_20 ) ;
return 0 ;
}
static T_3
F_13 ( struct V_13 * V_13 ,
const char T_1 * V_1 ,
T_2 V_2 , T_4 * V_14 )
{
struct V_15 * V_16 ;
T_5 V_27 ;
int V_6 , V_28 ;
V_16 = ( (struct V_17 * ) V_13 -> V_18 ) -> V_19 ;
F_2 ( V_16 != NULL ) ;
V_6 = F_14 ( V_1 , V_2 , & V_28 ) ;
if ( V_6 )
return V_6 ;
F_7 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_29 == V_30 )
V_27 = V_31 ;
else
V_27 = V_32 ;
if ( V_28 <= V_27 && V_28 > 0 ) {
V_16 -> V_33 = V_28 ;
F_8 ( V_22 , L_6 , V_16 -> V_24 ,
V_16 -> V_33 ) ;
}
F_10 ( & V_16 -> V_20 ) ;
return V_2 ;
}
static int
F_15 ( struct V_17 * V_25 , void * V_26 )
{
struct V_15 * V_16 = (struct V_15 * ) V_25 -> V_19 ;
F_2 ( V_16 != NULL ) ;
F_7 ( & V_16 -> V_20 ) ;
F_12 ( V_25 , L_7 , V_16 -> V_33 ) ;
F_10 ( & V_16 -> V_20 ) ;
return 0 ;
}
static int
F_16 ( struct V_17 * V_25 , void * V_26 )
{
struct V_15 * V_16 = (struct V_15 * ) V_25 -> V_19 ;
F_2 ( V_16 != NULL ) ;
F_7 ( & V_16 -> V_20 ) ;
F_12 ( V_25 , V_34 L_4 , F_17 ( & V_16 -> V_35 ) ) ;
F_10 ( & V_16 -> V_20 ) ;
return 0 ;
}
static int
F_18 ( struct V_17 * V_25 , void * V_26 )
{
struct V_15 * V_16 = (struct V_15 * ) V_25 -> V_19 ;
struct V_36 * V_37 ;
F_2 ( V_16 != NULL ) ;
if ( V_16 -> V_38 != NULL ) {
V_37 = & V_16 -> V_38 -> V_39 -> V_40 . V_37 ;
F_12 ( V_25 , L_8 , V_37 -> V_41 . V_42 ) ;
} else {
F_12 ( V_25 , L_8 , V_16 -> V_43 -> V_44 ) ;
}
return 0 ;
}
