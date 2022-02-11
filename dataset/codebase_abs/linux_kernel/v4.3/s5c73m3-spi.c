static int F_1 ( struct V_1 * V_2 , void * V_3 , const int V_4 ,
enum V_5 V_6 )
{
struct V_7 V_8 ;
int V_9 ;
struct V_10 V_11 = {
. V_4 = V_4 ,
} ;
if ( V_6 == V_12 )
V_11 . V_13 = V_3 ;
else
V_11 . V_14 = V_3 ;
if ( V_2 == NULL ) {
F_2 ( L_1 ) ;
return - V_15 ;
}
F_3 ( & V_8 ) ;
F_4 ( & V_11 , & V_8 ) ;
V_9 = F_5 ( V_2 , & V_8 ) ;
if ( V_9 < 0 )
F_6 ( & V_2 -> V_16 , L_2 , V_17 , V_9 ) ;
return V_9 ;
}
int F_7 ( struct V_18 * V_19 , const void * V_3 ,
const unsigned int V_4 , const unsigned int V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_21 = V_4 / V_20 ;
T_1 V_22 = V_4 % V_20 ;
unsigned int V_23 , V_24 = 0 ;
T_2 V_25 [ 32 ] ;
int V_9 = 0 ;
memset ( V_25 , 0 , sizeof( V_25 ) ) ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
V_9 = F_1 ( V_2 , ( void * ) V_3 + V_24 , V_20 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_24 += V_20 ;
}
if ( V_22 > 0 ) {
V_9 = F_1 ( V_2 , ( void * ) V_3 + V_24 , V_22 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return F_1 ( V_2 , V_25 , sizeof( V_25 ) , V_12 ) ;
}
int F_8 ( struct V_18 * V_19 , void * V_3 ,
const unsigned int V_4 , const unsigned int V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_21 = V_4 / V_20 ;
T_1 V_22 = V_4 % V_20 ;
unsigned int V_23 , V_24 = 0 ;
int V_9 = 0 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
V_9 = F_1 ( V_2 , V_3 + V_24 , V_20 , V_26 ) ;
if ( V_9 < 0 )
return V_9 ;
V_24 += V_20 ;
}
if ( V_22 > 0 )
return F_1 ( V_2 , V_3 + V_24 , V_22 , V_26 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_27 )
{
int V_9 ;
struct V_18 * V_19 = F_10 ( V_27 -> V_16 . V_28 , struct V_18 ,
V_29 . V_28 ) ;
V_27 -> V_30 = 32 ;
V_9 = F_11 ( V_27 ) ;
if ( V_9 < 0 ) {
F_6 ( & V_27 -> V_16 , L_3 ) ;
return V_9 ;
}
F_12 ( & V_19 -> V_31 ) ;
V_19 -> V_2 = V_27 ;
F_13 ( & V_19 -> V_31 ) ;
F_14 ( & V_19 -> V_32 , L_4 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_27 )
{
return 0 ;
}
int F_16 ( struct V_18 * V_19 )
{
struct V_33 * V_29 = & V_19 -> V_29 ;
V_29 -> remove = F_15 ;
V_29 -> V_34 = F_9 ;
V_29 -> V_28 . V_35 = V_36 ;
V_29 -> V_28 . V_37 = V_38 ;
V_29 -> V_28 . V_39 = V_40 ;
return F_17 ( V_29 ) ;
}
void F_18 ( struct V_18 * V_19 )
{
F_19 ( & V_19 -> V_29 ) ;
}
