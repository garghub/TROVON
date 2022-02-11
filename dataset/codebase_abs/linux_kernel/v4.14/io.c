void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
F_3 ( V_5 , V_3 -> V_6 ) ;
}
struct V_1 * F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_5 ( V_3 -> V_6 , V_7 ) ;
struct V_1 * V_1 = & V_5 -> V_1 ;
F_6 ( V_1 , V_1 -> V_8 , F_7 ( V_3 ) ) ;
return V_1 ;
}
void F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
V_1 -> V_9 . V_10 = F_9 ( & V_5 -> V_11 , 0 ) ;
F_10 ( V_1 , F_11 ( V_3 , & V_5 -> V_11 , 0 ) -> V_12 ) ;
V_5 -> V_13 = F_12 () ;
F_13 ( V_1 , V_1 -> V_14 ) ;
}
void F_14 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_15 * V_16 , unsigned V_17 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
F_15 ( & V_5 -> V_11 , V_16 , V_17 ) ;
F_8 ( V_1 , V_3 ) ;
}
void F_16 ( struct V_18 * V_19 , T_1 error , const char * V_20 )
{
if ( V_19 -> V_21 -> V_22 ) {
unsigned V_23 = F_17 ( & V_19 -> V_24 ) ;
while ( V_23 > V_19 -> V_21 -> V_22 ) {
unsigned V_25 ;
unsigned V_26 = V_23 ;
unsigned V_27 = V_23 - V_19 -> V_21 -> V_22 ;
V_23 = F_18 ( & V_19 -> V_24 , V_26 , V_27 ) ;
if ( V_23 == V_26 ) {
V_23 = V_27 ;
V_25 = F_19 ( & V_19 -> V_28 ) ;
do {
V_26 = V_25 ;
V_27 = ( ( V_29 ) V_25 * 127 ) / 128 ;
V_25 = F_18 ( & V_19 -> V_28 ,
V_26 , V_27 ) ;
} while ( V_26 != V_25 );
}
}
}
if ( error ) {
char V_30 [ V_31 ] ;
unsigned V_25 = F_20 ( 1 << V_32 ,
& V_19 -> V_28 ) ;
V_25 >>= V_32 ;
if ( V_25 < V_19 -> V_21 -> V_33 )
F_21 ( L_1 ,
F_22 ( V_19 -> V_12 , V_30 ) , V_20 ) ;
else
F_23 ( V_19 -> V_21 ,
L_2 ,
F_22 ( V_19 -> V_12 , V_30 ) , V_20 ) ;
}
}
void F_24 ( struct V_2 * V_3 , struct V_1 * V_1 ,
T_1 error , const char * V_20 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
struct V_18 * V_19 = F_11 ( V_3 , & V_5 -> V_11 , 0 ) ;
unsigned V_34 = F_25 ( F_26 ( V_1 ) )
? V_3 -> V_35
: V_3 -> V_36 ;
if ( V_34 ) {
unsigned V_37 = F_12 () ;
int V_38 = V_37 - V_5 -> V_13 ;
int V_39 = F_19 ( & V_3 -> V_39 ) ;
if ( V_38 > ( int ) V_34 ) {
int V_40 = V_38 / 1024 ;
V_3 -> V_41 = V_37 ;
V_40 = F_27 ( V_40 , V_42 + V_39 ) ;
F_28 ( V_40 , & V_3 -> V_39 ) ;
} else if ( V_39 < 0 )
F_29 ( & V_3 -> V_39 ) ;
}
F_16 ( V_19 , error , V_20 ) ;
}
void F_30 ( struct V_2 * V_3 , struct V_1 * V_1 ,
T_1 error , const char * V_20 )
{
struct V_43 * V_44 = V_1 -> V_14 ;
F_24 ( V_3 , V_1 , error , V_20 ) ;
F_31 ( V_1 ) ;
F_32 ( V_44 ) ;
}
