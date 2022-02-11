static int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_1 ( V_1 -> V_4 . V_5 , V_2 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_1 , unsigned int V_6 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_2 ( V_1 -> V_4 . V_5 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , unsigned int V_7 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_3 ( V_1 -> V_4 . V_5 , V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_8 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_4 ( V_1 -> V_4 . V_5 , V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_9 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_5 ( V_1 -> V_4 . V_5 , V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , unsigned int V_10 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_6 ( V_1 -> V_4 . V_5 , V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_11 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_7 ( V_1 -> V_4 . V_5 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , unsigned int V_12 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_8 ( V_1 -> V_4 . V_5 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , unsigned int V_13 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_9 ( V_1 -> V_4 . V_5 , V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned int V_14 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_10 ( V_1 -> V_4 . V_5 , V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , unsigned int V_15 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_11 ( V_1 -> V_4 . V_5 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , unsigned int V_16 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_12 ( V_1 -> V_4 . V_5 , V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , unsigned int V_17 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_13 ( V_1 -> V_4 . V_5 , V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_14 ( V_1 -> V_4 . V_5 , 1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_3 * V_3 ;
int V_18 ;
unsigned int V_19 = 0 ;
V_3 = V_1 -> V_4 . V_3 ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
if ( V_1 -> V_4 . V_22 > 1 ) {
V_19 = V_3 -> V_23 ( V_1 -> V_4 . V_5 ) & V_24 ;
}
V_3 -> F_15 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
if ( V_26 == V_1 -> V_27 )
return 0 ;
for ( V_18 = 1 ; V_18 < V_1 -> V_4 . V_22 ; V_18 ++ ) {
V_1 -> V_4 . V_20 -> V_28 ( & V_1 -> V_4 ) ;
V_3 -> V_29 ( V_1 -> V_4 . V_5 , V_19 ) ;
V_3 -> F_15 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
}
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_4 . V_3 ;
return V_3 -> F_16 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
V_30 [ V_1 -> V_27 ] ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_18 ( struct V_1 * V_1 )
{
return V_1 -> V_31 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_4 . V_3 ;
unsigned int V_32 , V_22 ;
V_3 -> F_1 ( V_1 -> V_4 . V_5 , V_33 ) ;
V_3 -> F_2 ( V_1 -> V_4 . V_5 , 1 ) ;
for ( V_32 = 0 , V_22 = V_1 -> V_4 . V_22 ; V_22 > 1 ; V_22 >>= 1 )
V_32 ++ ;
V_3 -> V_34 ( V_1 -> V_4 . V_5 , V_32 ) ;
V_3 -> F_3 ( V_1 -> V_4 . V_5 , V_35 ) ;
V_3 -> V_36 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_4 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_5 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_6 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_7 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> V_37 ( V_1 -> V_4 . V_5 , V_1 -> V_38 - 1 ) ;
V_3 -> F_9 ( V_1 -> V_4 . V_5 , 0x80 ) ;
V_3 -> F_11 ( V_1 -> V_4 . V_5 , 0x0 ) ;
V_3 -> F_12 ( V_1 -> V_4 . V_5 , 0x1000 ) ;
V_3 -> F_10 ( V_1 -> V_4 . V_5 , 0x80 ) ;
V_3 -> F_13 ( V_1 -> V_4 . V_5 , 0x1000000 ) ;
V_3 -> F_14 ( V_1 -> V_4 . V_5 , 1 ) ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
V_3 -> F_15 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
for ( V_22 = 1 ; V_22 < V_1 -> V_4 . V_22 ; V_22 ++ ) {
V_1 -> V_4 . V_20 -> V_28 ( & V_1 -> V_4 ) ;
V_3 -> F_13 ( V_1 -> V_4 . V_5 , 0x1000000 ) ;
V_3 -> F_15 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
}
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_4 . V_3 ;
V_3 -> F_1 ( V_1 -> V_4 . V_5 , V_33 ) ;
V_3 -> F_2 ( V_1 -> V_4 . V_5 , 1 ) ;
V_3 -> V_34 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_3 ( V_1 -> V_4 . V_5 , V_35 ) ;
V_3 -> V_36 ( V_1 -> V_4 . V_5 , 1 ) ;
V_3 -> F_4 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_5 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_6 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_7 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> V_37 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_9 ( V_1 -> V_4 . V_5 , 0x80 ) ;
V_3 -> F_11 ( V_1 -> V_4 . V_5 , 0x0 ) ;
V_3 -> F_12 ( V_1 -> V_4 . V_5 , 0x1000 ) ;
V_3 -> F_10 ( V_1 -> V_4 . V_5 , 0x80 ) ;
V_3 -> F_13 ( V_1 -> V_4 . V_5 , 0x1000000 ) ;
V_3 -> F_14 ( V_1 -> V_4 . V_5 , 1 ) ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
V_3 -> F_15 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_4 . V_3 ;
unsigned int V_32 , V_22 ;
unsigned int V_19 ;
V_3 -> F_1 ( V_1 -> V_4 . V_5 , V_33 ) ;
V_3 -> F_2 ( V_1 -> V_4 . V_5 , 0 ) ;
for ( V_32 = 0 , V_22 = V_1 -> V_4 . V_22 ; V_22 > 1 ; V_22 >>= 1 )
V_32 ++ ;
V_3 -> V_34 ( V_1 -> V_4 . V_5 , V_32 ) ;
V_3 -> F_3 ( V_1 -> V_4 . V_5 , V_39 ) ;
V_3 -> V_36 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_4 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_5 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_6 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_7 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> V_37 ( V_1 -> V_4 . V_5 , 0 ) ;
V_3 -> F_9 ( V_1 -> V_4 . V_5 , 0x80 ) ;
V_3 -> F_11 ( V_1 -> V_4 . V_5 , 0x0 ) ;
V_3 -> F_12 ( V_1 -> V_4 . V_5 , 0x1000 ) ;
V_3 -> F_10 ( V_1 -> V_4 . V_5 , 0x80 ) ;
V_3 -> F_13 ( V_1 -> V_4 . V_5 , 0x1000000 ) ;
V_3 -> F_14 ( V_1 -> V_4 . V_5 , 1 ) ;
V_19 = V_3 -> V_23 ( V_1 -> V_4 . V_5 ) ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_4 . V_22 ; V_22 ++ ) {
V_3 -> V_29 ( V_1 -> V_4 . V_5 , V_19 ) ;
V_3 -> F_15 ( V_3 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ,
V_1 -> V_4 . V_5 ) ;
V_1 -> V_4 . V_20 -> V_28 ( & V_1 -> V_4 ) ;
}
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_1 , T_1 V_40 ,
const struct V_41 * V_42 , struct V_43 * V_44 )
{
int V_45 ;
int V_18 , V_46 ;
struct V_1 * V_47 ;
V_46 = ( V_48 == V_42 -> V_27 ) ? V_42 -> V_38 : 1 ;
for ( V_18 = 0 , V_47 = V_1 ; V_18 < V_46 ; V_18 ++ , V_47 ++ ) {
V_45 = F_23 ( & V_47 -> V_4 , V_40 + V_18 , V_49 , V_42 -> V_22 , V_44 -> V_44 . V_3 ) ;
if ( V_45 )
goto V_50;
V_47 -> V_20 = & V_51 ;
V_47 -> V_38 = ( 0 == V_18 ) ? V_42 -> V_38 : 1 ;
V_47 -> V_27 = V_42 -> V_27 ;
V_30 [ V_42 -> V_27 ] ( V_47 ) ;
V_44 -> V_52 ( V_44 , V_47 ) ;
V_47 -> V_31 = V_47 + 1 ;
}
( -- V_47 ) -> V_31 = NULL ;
V_44 -> V_53 ( V_44 ) ;
return 0 ;
V_50:
for ( V_18 -- , V_47 -- ; V_18 >= 0 ; V_18 -- , V_47 -- ) {
V_44 -> V_54 ( V_44 , V_47 ) ;
F_24 ( & V_47 -> V_4 ) ;
}
V_44 -> V_53 ( V_44 ) ;
return V_45 ;
}
static int F_25 ( struct V_1 * V_1 , struct V_43 * V_44 )
{
int V_18 , V_46 ;
struct V_1 * V_47 ;
V_46 = ( V_48 == V_1 -> V_27 ) ? V_1 -> V_38 : 1 ;
for ( V_18 = 0 , V_47 = V_1 ; V_18 < V_46 ; V_18 ++ , V_47 ++ ) {
V_44 -> V_54 ( V_44 , V_47 ) ;
F_24 ( & V_47 -> V_4 ) ;
V_47 -> V_38 = 0 ;
V_47 -> V_20 = NULL ;
V_47 -> V_27 = V_55 ;
V_47 -> V_31 = NULL ;
}
V_44 -> V_53 ( V_44 ) ;
return 0 ;
}
static int
F_26 ( struct V_43 * V_44 , const struct V_41 * V_42 , struct V_1 * * V_56 )
{
unsigned int V_40 = V_57 ;
int V_45 ;
struct V_1 * V_1 ;
unsigned long V_58 ;
* V_56 = NULL ;
F_27 ( & V_44 -> V_59 , V_58 ) ;
if ( V_48 == V_42 -> V_27 )
V_45 = F_28 ( & V_44 -> V_44 , V_42 -> V_38 , & V_40 ) ;
else
V_45 = F_28 ( & V_44 -> V_44 , 1 , & V_40 ) ;
F_29 ( & V_44 -> V_59 , V_58 ) ;
if ( V_45 ) {
F_30 ( V_60 L_1 ) ;
return V_45 ;
}
if ( V_48 == V_42 -> V_27 )
V_1 = F_31 ( sizeof( * V_1 ) * V_42 -> V_38 , V_61 ) ;
else
V_1 = F_31 ( sizeof( * V_1 ) , V_61 ) ;
if ( ! V_1 ) {
V_45 = - V_62 ;
goto V_50;
}
V_45 = F_22 ( V_1 , V_40 , V_42 , V_44 ) ;
if ( V_45 )
goto V_63;
* V_56 = V_1 ;
return 0 ;
V_63:
F_32 ( V_1 ) ;
V_50:
F_27 ( & V_44 -> V_59 , V_58 ) ;
if ( V_48 == V_42 -> V_27 )
F_33 ( & V_44 -> V_44 , V_42 -> V_38 , V_40 ) ;
else
F_33 ( & V_44 -> V_44 , 1 , V_40 ) ;
F_29 ( & V_44 -> V_59 , V_58 ) ;
return V_45 ;
}
static int F_34 ( struct V_43 * V_44 , struct V_1 * V_1 )
{
unsigned long V_58 ;
F_27 ( & V_44 -> V_59 , V_58 ) ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
if ( V_48 == V_1 -> V_27 )
F_33 ( & V_44 -> V_44 , V_1 -> V_38 ,
V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ) ;
else
F_33 ( & V_44 -> V_44 , 1 , V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ) ;
F_29 ( & V_44 -> V_59 , V_58 ) ;
F_25 ( V_1 , V_44 ) ;
F_32 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_43 * V_44 , struct V_1 * V_1 )
{
struct V_3 * V_3 = V_44 -> V_44 . V_3 ;
int V_18 ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
for ( V_18 = 0 ; V_18 < V_1 -> V_4 . V_22 ; V_18 ++ ) {
V_3 -> V_64 ( V_44 -> V_44 . V_5 ,
V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ) ;
V_1 -> V_4 . V_20 -> V_28 ( & V_1 -> V_4 ) ;
}
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
return 0 ;
}
static int V_52 ( struct V_43 * V_44 , struct V_1 * V_1 )
{
struct V_3 * V_3 = V_44 -> V_44 . V_3 ;
int V_18 ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
for ( V_18 = 0 ; V_18 < V_1 -> V_4 . V_22 ; V_18 ++ ) {
V_3 -> V_65 ( V_44 -> V_44 . V_5 ,
V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ) ;
V_1 -> V_4 . V_20 -> V_28 ( & V_1 -> V_4 ) ;
}
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
return 0 ;
}
static int V_54 ( struct V_43 * V_44 , struct V_1 * V_1 )
{
struct V_3 * V_3 = V_44 -> V_44 . V_3 ;
int V_18 ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
for ( V_18 = 0 ; V_18 < V_1 -> V_4 . V_22 ; V_18 ++ ) {
V_3 -> V_66 ( V_44 -> V_44 . V_5 ,
V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ) ;
V_1 -> V_4 . V_20 -> V_28 ( & V_1 -> V_4 ) ;
}
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_3 * V_3 = V_44 -> V_44 . V_3 ;
V_3 -> F_36 ( V_3 , V_44 -> V_44 . V_5 ) ;
return 0 ;
}
int F_37 ( void * V_3 , struct V_43 * * V_67 )
{
int V_45 , V_18 ;
struct V_43 * V_43 ;
* V_67 = NULL ;
V_43 = F_31 ( sizeof( * V_43 ) , V_61 ) ;
if ( ! V_43 )
return - V_62 ;
V_45 = F_38 ( & V_43 -> V_44 , V_49 , V_57 , V_3 ) ;
if ( V_45 )
goto V_50;
F_39 ( & V_43 -> V_59 ) ;
V_24 = ( (struct V_3 * ) V_3 ) -> F_40 () ;
V_43 -> V_68 = F_26 ;
V_43 -> V_69 = F_34 ;
V_43 -> F_35 = F_35 ;
V_43 -> V_52 = V_52 ;
V_43 -> V_54 = V_54 ;
V_43 -> V_53 = F_36 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ )
( (struct V_3 * ) V_3 ) -> V_66 ( V_43 -> V_44 . V_5 , V_18 ) ;
( (struct V_3 * ) V_3 ) -> F_36 ( V_3 , V_43 -> V_44 . V_5 ) ;
* V_67 = V_43 ;
return 0 ;
V_50:
F_32 ( V_43 ) ;
return V_45 ;
}
int F_41 ( struct V_43 * V_43 )
{
F_42 ( & V_43 -> V_44 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
static int F_43 ( struct V_4 * V_4 )
{
V_4 -> V_70 = 0 ;
return V_4 -> V_40 = F_44 ( V_4 , struct V_71 , V_4 ) -> V_40 [ 0 ] ;
}
static int F_45 ( struct V_4 * V_4 )
{
V_4 -> V_70 ++ ;
return F_44 ( V_4 , struct V_71 , V_4 ) -> V_40 [ V_4 -> V_70 ] ;
}
static int F_46 ( const struct V_4 * V_4 )
{
return F_44 ( V_4 , struct V_71 , V_4 ) -> V_40 [ V_4 -> V_70 ] ;
}
static int F_47 ( struct V_71 * V_71 , struct V_1 * V_1 , struct V_4 * V_72 )
{
struct V_73 * V_74 ;
int V_18 ;
V_71 -> V_4 . V_20 -> V_21 ( & V_71 -> V_4 ) ;
V_1 -> V_4 . V_20 -> V_21 ( & V_1 -> V_4 ) ;
V_72 -> V_20 -> V_21 ( V_72 ) ;
for ( V_18 = 0 ; V_18 < V_71 -> V_4 . V_22 ; V_18 ++ ) {
V_74 = & V_71 -> V_75 [ V_18 ] ;
V_74 -> V_76 = V_72 -> V_20 -> V_77 ( V_72 ) ;
V_74 -> V_78 = V_1 -> V_4 . V_20 -> V_25 ( & V_1 -> V_4 ) ;
V_74 -> V_79 = V_71 -> V_4 . V_20 -> V_25 ( & V_71 -> V_4 ) ;
V_71 -> V_44 -> V_80 ( V_71 -> V_44 , V_74 ) ;
V_71 -> V_81 |= ( 0x1 << V_18 ) ;
V_71 -> V_4 . V_20 -> V_28 ( & V_71 -> V_4 ) ;
V_72 -> V_20 -> V_28 ( V_72 ) ;
}
V_71 -> V_4 . V_20 -> V_21 ( & V_71 -> V_4 ) ;
V_72 -> V_20 -> V_21 ( V_72 ) ;
return 0 ;
}
static int F_48 ( struct V_71 * V_71 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_71 -> V_4 . V_22 ; V_18 ++ ) {
if ( V_71 -> V_81 & ( 0x1 << V_18 ) ) {
V_71 -> V_44 -> V_82 ( V_71 -> V_44 ,
& V_71 -> V_75 [ V_18 ] ) ;
V_71 -> V_81 &= ~ ( 0x1 << V_18 ) ;
}
}
return 0 ;
}
static int F_49 ( struct V_71 * V_71 ,
const struct V_83 * V_42 ,
struct V_84 * V_44 )
{
int V_45 ;
V_45 = F_23 ( & V_71 -> V_4 , V_71 -> V_40 [ 0 ] ,
V_85 , V_42 -> V_22 , V_44 -> V_44 . V_3 ) ;
if ( V_45 )
return V_45 ;
V_71 -> V_75 = F_31 ( sizeof( struct V_73 ) * V_42 -> V_22 ,
V_61 ) ;
if ( ! V_71 -> V_75 ) {
V_45 = - V_62 ;
goto V_50;
}
V_71 -> V_4 . V_20 = & V_86 ;
V_71 -> V_20 = & V_87 ;
V_71 -> V_44 = V_44 ;
V_71 -> V_4 . V_20 -> V_21 ( & V_71 -> V_4 ) ;
return 0 ;
V_50:
F_24 ( & V_71 -> V_4 ) ;
return V_45 ;
}
static int F_50 ( struct V_71 * V_71 )
{
if ( NULL != V_71 -> V_75 ) {
F_32 ( V_71 -> V_75 ) ;
V_71 -> V_75 = NULL ;
}
V_71 -> V_20 = NULL ;
V_71 -> V_44 = NULL ;
F_24 ( & V_71 -> V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_84 * V_44 ,
const struct V_83 * V_42 ,
struct V_71 * * V_88 )
{
int V_45 , V_18 ;
unsigned int V_40 ;
struct V_71 * V_71 ;
unsigned long V_58 ;
* V_88 = NULL ;
V_71 = F_31 ( sizeof( * V_71 ) , V_61 ) ;
if ( ! V_71 )
return - V_62 ;
V_45 = 0 ;
F_27 ( & V_44 -> V_59 , V_58 ) ;
for ( V_18 = 0 ; V_18 < V_42 -> V_22 ; V_18 ++ ) {
V_45 = F_28 ( & V_44 -> V_44 , 1 , & V_40 ) ;
if ( V_45 )
break;
V_71 -> V_40 [ V_18 ] = V_40 ;
}
F_29 ( & V_44 -> V_59 , V_58 ) ;
if ( V_45 ) {
F_30 ( V_60 L_2 ) ;
goto V_50;
}
V_45 = F_49 ( V_71 , V_42 , V_44 ) ;
if ( V_45 )
goto V_50;
* V_88 = V_71 ;
return 0 ;
V_50:
F_27 ( & V_44 -> V_59 , V_58 ) ;
for ( V_18 -- ; V_18 >= 0 ; V_18 -- )
F_33 ( & V_44 -> V_44 , 1 , V_71 -> V_40 [ V_18 ] ) ;
F_29 ( & V_44 -> V_59 , V_58 ) ;
F_32 ( V_71 ) ;
return V_45 ;
}
static int F_52 ( struct V_84 * V_44 , struct V_71 * V_71 )
{
unsigned long V_58 ;
int V_18 ;
F_27 ( & V_44 -> V_59 , V_58 ) ;
for ( V_18 = 0 ; V_18 < V_71 -> V_4 . V_22 ; V_18 ++ )
F_33 ( & V_44 -> V_44 , 1 , V_71 -> V_40 [ V_18 ] ) ;
F_29 ( & V_44 -> V_59 , V_58 ) ;
F_50 ( V_71 ) ;
F_32 ( V_71 ) ;
return 0 ;
}
static int F_53 ( void * V_89 , struct V_73 * V_74 )
{
struct V_90 * V_44 = & ( (struct V_84 * ) V_89 ) -> V_44 ;
struct V_3 * V_3 = V_44 -> V_3 ;
V_3 -> V_91 ( V_44 -> V_5 , V_74 -> V_76 ) ;
V_3 -> V_92 ( V_44 -> V_5 , V_74 -> V_78 ) ;
V_3 -> V_93 ( V_44 -> V_5 , V_74 -> V_94 ) ;
V_3 -> V_95 ( V_44 -> V_5 , V_74 -> V_79 ) ;
V_3 -> V_96 ( V_44 -> V_3 , V_44 -> V_5 ) ;
return 0 ;
}
static int F_54 ( struct V_84 * V_44 , struct V_73 * V_74 )
{
unsigned long V_58 ;
int V_45 ;
F_27 ( & V_44 -> V_97 , V_58 ) ;
if ( ( 0 == V_74 -> V_79 ) && ( V_44 -> V_98 ) ) {
F_55 ( & V_44 -> V_75 ,
V_44 -> V_99 , F_53 , V_44 ) ;
V_44 -> V_98 = 0 ;
}
V_45 = F_56 ( & V_44 -> V_75 , V_74 , F_53 , V_44 ) ;
F_29 ( & V_44 -> V_97 , V_58 ) ;
return V_45 ;
}
static int F_57 ( struct V_84 * V_44 , struct V_73 * V_74 )
{
unsigned long V_58 ;
int V_45 ;
F_27 ( & V_44 -> V_97 , V_58 ) ;
V_45 = F_55 ( & V_44 -> V_75 , V_74 , F_53 , V_44 ) ;
if ( F_58 ( & V_44 -> V_75 ) ) {
F_56 ( & V_44 -> V_75 , V_44 -> V_99 ,
F_53 , V_44 ) ;
V_44 -> V_98 = 1 ;
}
F_29 ( & V_44 -> V_97 , V_58 ) ;
return V_45 ;
}
int F_59 ( void * V_3 , struct V_84 * * V_100 )
{
int V_45 ;
struct V_84 * V_84 ;
struct V_73 * V_74 ;
* V_100 = NULL ;
V_84 = F_31 ( sizeof( * V_84 ) , V_61 ) ;
if ( ! V_84 )
return - V_62 ;
V_45 = F_38 ( & V_84 -> V_44 , V_85 , V_101 , V_3 ) ;
if ( V_45 )
goto V_50;
F_39 ( & V_84 -> V_59 ) ;
F_39 ( & V_84 -> V_97 ) ;
F_60 ( & V_84 -> V_75 ) ;
V_74 = F_31 ( sizeof( * V_74 ) , V_61 ) ;
if ( ! V_74 ) {
V_45 = - V_62 ;
goto V_63;
}
V_74 -> V_76 = V_74 -> V_79 = V_74 -> V_94 = V_74 -> V_78 = 0 ;
F_61 ( & V_74 -> V_102 , & V_84 -> V_75 ) ;
V_84 -> V_99 = V_74 ;
V_84 -> V_98 = 1 ;
V_84 -> V_103 = F_51 ;
V_84 -> V_104 = F_52 ;
V_84 -> V_80 = F_54 ;
V_84 -> V_82 = F_57 ;
* V_100 = V_84 ;
return 0 ;
V_63:
F_42 ( & V_84 -> V_44 ) ;
V_50:
F_32 ( V_84 ) ;
return V_45 ;
}
int F_62 ( struct V_84 * V_84 )
{
unsigned long V_58 ;
F_27 ( & V_84 -> V_97 , V_58 ) ;
F_63 ( & V_84 -> V_75 ) ;
F_29 ( & V_84 -> V_97 , V_58 ) ;
F_42 ( & V_84 -> V_44 ) ;
F_32 ( V_84 ) ;
return 0 ;
}
