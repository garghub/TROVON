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
V_1 -> V_12 = F_10 ( V_3 , & V_5 -> V_11 , 0 ) -> V_13 ;
V_5 -> V_14 = F_11 () ;
F_12 ( V_1 , V_1 -> V_15 ) ;
}
void F_13 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_16 * V_17 , unsigned V_18 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
F_14 ( & V_5 -> V_11 , V_17 , V_18 ) ;
F_8 ( V_1 , V_3 ) ;
}
void F_15 ( struct V_19 * V_20 , int error , const char * V_21 )
{
if ( V_20 -> V_22 -> V_23 ) {
unsigned V_24 = F_16 ( & V_20 -> V_25 ) ;
while ( V_24 > V_20 -> V_22 -> V_23 ) {
unsigned V_26 ;
unsigned V_27 = V_24 ;
unsigned V_28 = V_24 - V_20 -> V_22 -> V_23 ;
V_24 = F_17 ( & V_20 -> V_25 , V_27 , V_28 ) ;
if ( V_24 == V_27 ) {
V_24 = V_28 ;
V_26 = F_18 ( & V_20 -> V_29 ) ;
do {
V_27 = V_26 ;
V_28 = ( ( V_30 ) V_26 * 127 ) / 128 ;
V_26 = F_17 ( & V_20 -> V_29 ,
V_27 , V_28 ) ;
} while ( V_27 != V_26 );
}
}
}
if ( error ) {
char V_31 [ V_32 ] ;
unsigned V_26 = F_19 ( 1 << V_33 ,
& V_20 -> V_29 ) ;
V_26 >>= V_33 ;
if ( V_26 < V_20 -> V_22 -> V_34 )
F_20 ( L_1 ,
F_21 ( V_20 -> V_13 , V_31 ) , V_21 ) ;
else
F_22 ( V_20 -> V_22 ,
L_2 ,
F_21 ( V_20 -> V_13 , V_31 ) , V_21 ) ;
}
}
void F_23 ( struct V_2 * V_3 , struct V_1 * V_1 ,
int error , const char * V_21 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
struct V_19 * V_20 = F_10 ( V_3 , & V_5 -> V_11 , 0 ) ;
unsigned V_35 = F_24 ( F_25 ( V_1 ) )
? V_3 -> V_36
: V_3 -> V_37 ;
if ( V_35 ) {
unsigned V_38 = F_11 () ;
int V_39 = V_38 - V_5 -> V_14 ;
int V_40 = F_18 ( & V_3 -> V_40 ) ;
if ( V_39 > ( int ) V_35 ) {
int V_41 = V_39 / 1024 ;
V_3 -> V_42 = V_38 ;
V_41 = F_26 ( V_41 , V_43 + V_40 ) ;
F_27 ( V_41 , & V_3 -> V_40 ) ;
} else if ( V_40 < 0 )
F_28 ( & V_3 -> V_40 ) ;
}
F_15 ( V_20 , error , V_21 ) ;
}
void F_29 ( struct V_2 * V_3 , struct V_1 * V_1 ,
int error , const char * V_21 )
{
struct V_44 * V_45 = V_1 -> V_15 ;
F_23 ( V_3 , V_1 , error , V_21 ) ;
F_30 ( V_1 ) ;
F_31 ( V_45 ) ;
}
