void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
F_3 ( V_5 , V_3 -> V_6 ) ;
}
struct V_1 * F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_5 ( V_3 -> V_6 , V_7 ) ;
struct V_1 * V_1 = & V_5 -> V_1 ;
F_6 ( V_1 ) ;
V_1 -> V_8 = F_7 ( V_3 ) ;
V_1 -> V_9 = V_1 -> V_10 ;
return V_1 ;
}
void F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
V_1 -> V_11 . V_12 = F_9 ( & V_5 -> V_13 , 0 ) ;
V_1 -> V_14 = F_10 ( V_3 , & V_5 -> V_13 , 0 ) -> V_15 ;
V_5 -> V_16 = F_11 () ;
F_12 ( V_1 , V_1 -> V_17 ) ;
}
void F_13 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_18 * V_19 , unsigned V_20 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
F_14 ( & V_5 -> V_13 , V_19 , V_20 ) ;
F_8 ( V_1 , V_3 ) ;
}
void F_15 ( struct V_21 * V_22 , int error , const char * V_23 )
{
if ( V_22 -> V_24 -> V_25 ) {
unsigned V_26 = F_16 ( & V_22 -> V_27 ) ;
while ( V_26 > V_22 -> V_24 -> V_25 ) {
unsigned V_28 ;
unsigned V_29 = V_26 ;
unsigned V_30 = V_26 - V_22 -> V_24 -> V_25 ;
V_26 = F_17 ( & V_22 -> V_27 , V_29 , V_30 ) ;
if ( V_26 == V_29 ) {
V_26 = V_30 ;
V_28 = F_18 ( & V_22 -> V_31 ) ;
do {
V_29 = V_28 ;
V_30 = ( ( V_32 ) V_28 * 127 ) / 128 ;
V_28 = F_17 ( & V_22 -> V_31 ,
V_29 , V_30 ) ;
} while ( V_29 != V_28 );
}
}
}
if ( error ) {
char V_33 [ V_34 ] ;
unsigned V_28 = F_19 ( 1 << V_35 ,
& V_22 -> V_31 ) ;
V_28 >>= V_35 ;
if ( V_28 < V_22 -> V_24 -> V_36 )
F_20 ( L_1 ,
F_21 ( V_22 -> V_15 , V_33 ) , V_23 ) ;
else
F_22 ( V_22 -> V_24 ,
L_2 ,
F_21 ( V_22 -> V_15 , V_33 ) , V_23 ) ;
}
}
void F_23 ( struct V_2 * V_3 , struct V_1 * V_1 ,
int error , const char * V_23 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
struct V_21 * V_22 = F_10 ( V_3 , & V_5 -> V_13 , 0 ) ;
unsigned V_37 = F_24 ( F_25 ( V_1 ) )
? V_3 -> V_38
: V_3 -> V_39 ;
if ( V_37 ) {
unsigned V_40 = F_11 () ;
int V_41 = V_40 - V_5 -> V_16 ;
int V_42 = F_18 ( & V_3 -> V_42 ) ;
if ( V_41 > ( int ) V_37 ) {
int V_43 = V_41 / 1024 ;
V_3 -> V_44 = V_40 ;
V_43 = F_26 ( V_43 , V_45 + V_42 ) ;
F_27 ( V_43 , & V_3 -> V_42 ) ;
} else if ( V_42 < 0 )
F_28 ( & V_3 -> V_42 ) ;
}
F_15 ( V_22 , error , V_23 ) ;
}
void F_29 ( struct V_2 * V_3 , struct V_1 * V_1 ,
int error , const char * V_23 )
{
struct V_46 * V_47 = V_1 -> V_17 ;
F_23 ( V_3 , V_1 , error , V_23 ) ;
F_30 ( V_1 ) ;
F_31 ( V_47 ) ;
}
