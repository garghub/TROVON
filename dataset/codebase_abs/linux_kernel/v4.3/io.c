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
V_1 -> V_8 |= V_9 << V_10 ;
V_1 -> V_11 = F_7 ( V_3 ) ;
V_1 -> V_12 = V_1 -> V_13 ;
return V_1 ;
}
void F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
V_1 -> V_14 . V_15 = F_9 ( & V_5 -> V_16 , 0 ) ;
V_1 -> V_17 = F_10 ( V_3 , & V_5 -> V_16 , 0 ) -> V_18 ;
V_5 -> V_19 = F_11 () ;
F_12 ( V_1 , V_1 -> V_20 ) ;
}
void F_13 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_21 * V_22 , unsigned V_23 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
F_14 ( & V_5 -> V_16 , V_22 , V_23 ) ;
F_8 ( V_1 , V_3 ) ;
}
void F_15 ( struct V_24 * V_25 , int error , const char * V_26 )
{
if ( V_25 -> V_27 -> V_28 ) {
unsigned V_29 = F_16 ( & V_25 -> V_30 ) ;
while ( V_29 > V_25 -> V_27 -> V_28 ) {
unsigned V_31 ;
unsigned V_32 = V_29 ;
unsigned V_33 = V_29 - V_25 -> V_27 -> V_28 ;
V_29 = F_17 ( & V_25 -> V_30 , V_32 , V_33 ) ;
if ( V_29 == V_32 ) {
V_29 = V_33 ;
V_31 = F_18 ( & V_25 -> V_34 ) ;
do {
V_32 = V_31 ;
V_33 = ( ( V_35 ) V_31 * 127 ) / 128 ;
V_31 = F_17 ( & V_25 -> V_34 ,
V_32 , V_33 ) ;
} while ( V_32 != V_31 );
}
}
}
if ( error ) {
char V_36 [ V_37 ] ;
unsigned V_31 = F_19 ( 1 << V_38 ,
& V_25 -> V_34 ) ;
V_31 >>= V_38 ;
if ( V_31 < V_25 -> V_27 -> V_39 )
F_20 ( L_1 ,
F_21 ( V_25 -> V_18 , V_36 ) , V_26 ) ;
else
F_22 ( V_25 -> V_27 ,
L_2 ,
F_21 ( V_25 -> V_18 , V_36 ) , V_26 ) ;
}
}
void F_23 ( struct V_2 * V_3 , struct V_1 * V_1 ,
int error , const char * V_26 )
{
struct V_4 * V_5 = F_2 ( V_1 , struct V_4 , V_1 ) ;
struct V_24 * V_25 = F_10 ( V_3 , & V_5 -> V_16 , 0 ) ;
unsigned V_40 = V_1 -> V_41 & V_42
? V_3 -> V_43
: V_3 -> V_44 ;
if ( V_40 ) {
unsigned V_45 = F_11 () ;
int V_46 = V_45 - V_5 -> V_19 ;
int V_47 = F_18 ( & V_3 -> V_47 ) ;
if ( V_46 > ( int ) V_40 ) {
int V_48 = V_46 / 1024 ;
V_3 -> V_49 = V_45 ;
V_48 = F_24 ( V_48 , V_50 + V_47 ) ;
F_25 ( V_48 , & V_3 -> V_47 ) ;
} else if ( V_47 < 0 )
F_26 ( & V_3 -> V_47 ) ;
}
F_15 ( V_25 , error , V_26 ) ;
}
void F_27 ( struct V_2 * V_3 , struct V_1 * V_1 ,
int error , const char * V_26 )
{
struct V_51 * V_52 = V_1 -> V_20 ;
F_23 ( V_3 , V_1 , error , V_26 ) ;
F_28 ( V_1 ) ;
F_29 ( V_52 ) ;
}
