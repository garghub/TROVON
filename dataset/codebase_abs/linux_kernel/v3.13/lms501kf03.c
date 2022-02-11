static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 [ 1 ] ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 2 ,
. V_11 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 << 8 ) | V_4 ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
return F_4 ( V_2 -> V_12 , & V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char V_13 ,
unsigned char V_14 )
{
return F_1 ( V_2 , V_13 , V_14 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
const unsigned char * V_15 ,
unsigned int V_10 )
{
int V_16 = 0 , V_17 = 0 ;
while ( V_17 < V_10 ) {
if ( V_17 == 0 )
V_16 = F_5 ( V_2 , V_18 , V_15 [ V_17 ] ) ;
else
V_16 = F_5 ( V_2 , V_19 , V_15 [ V_17 ] ) ;
if ( V_16 )
break;
V_17 += 1 ;
}
return V_16 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_16 , V_17 ;
static const unsigned char * V_20 [] = {
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
} ;
static const unsigned int V_33 [] = {
F_8 ( V_21 ) ,
F_8 ( V_22 ) ,
F_8 ( V_23 ) ,
F_8 ( V_24 ) ,
F_8 ( V_25 ) ,
F_8 ( V_26 ) ,
F_8 ( V_27 ) ,
F_8 ( V_28 ) ,
F_8 ( V_29 ) ,
F_8 ( V_30 ) ,
F_8 ( V_31 ) ,
F_8 ( V_32 ) ,
} ;
for ( V_17 = 0 ; V_17 < F_8 ( V_20 ) ; V_17 ++ ) {
V_16 = F_6 ( V_2 , V_20 [ V_17 ] ,
V_33 [ V_17 ] ) ;
if ( V_16 )
break;
}
F_9 ( 120 ) ;
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_34 ,
F_8 ( V_34 ) ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_35 ,
F_8 ( V_35 ) ) ;
}
static int F_12 ( int V_36 )
{
return ( V_36 ) <= V_37 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
struct V_38 * V_39 ;
V_39 = V_2 -> V_40 ;
if ( ! V_39 -> V_41 ) {
F_14 ( V_2 -> V_42 , L_1 ) ;
return - V_43 ;
} else {
V_39 -> V_41 ( V_2 -> V_44 , 1 ) ;
F_9 ( V_39 -> V_45 ) ;
}
if ( ! V_39 -> V_46 ) {
F_14 ( V_2 -> V_42 , L_2 ) ;
return - V_43 ;
} else {
V_39 -> V_46 ( V_2 -> V_44 ) ;
F_9 ( V_39 -> V_47 ) ;
}
V_16 = F_7 ( V_2 ) ;
if ( V_16 ) {
F_14 ( V_2 -> V_42 , L_3 ) ;
return V_16 ;
}
V_16 = F_10 ( V_2 ) ;
if ( V_16 ) {
F_14 ( V_2 -> V_42 , L_4 ) ;
return V_16 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
struct V_38 * V_39 ;
V_39 = V_2 -> V_40 ;
V_16 = F_11 ( V_2 ) ;
if ( V_16 ) {
F_14 ( V_2 -> V_42 , L_5 ) ;
return - V_48 ;
}
F_9 ( V_39 -> V_49 ) ;
V_39 -> V_41 ( V_2 -> V_44 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_36 )
{
int V_16 = 0 ;
if ( F_12 ( V_36 ) &&
! F_12 ( V_2 -> V_36 ) )
V_16 = F_13 ( V_2 ) ;
else if ( ! F_12 ( V_36 ) &&
F_12 ( V_2 -> V_36 ) )
V_16 = F_15 ( V_2 ) ;
if ( ! V_16 )
V_2 -> V_36 = V_36 ;
return V_16 ;
}
static int F_17 ( struct V_50 * V_44 )
{
struct V_1 * V_2 = F_18 ( V_44 ) ;
return V_2 -> V_36 ;
}
static int F_19 ( struct V_50 * V_44 , int V_36 )
{
struct V_1 * V_2 = F_18 ( V_44 ) ;
if ( V_36 != V_51 && V_36 != V_52 &&
V_36 != V_37 ) {
F_14 ( V_2 -> V_42 , L_6 ) ;
return - V_43 ;
}
return F_16 ( V_2 , V_36 ) ;
}
static int F_20 ( struct V_53 * V_12 )
{
struct V_1 * V_2 = NULL ;
struct V_50 * V_44 = NULL ;
int V_16 = 0 ;
V_2 = F_21 ( & V_12 -> V_42 , sizeof( struct V_1 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_12 -> V_56 = 9 ;
V_16 = F_22 ( V_12 ) ;
if ( V_16 < 0 ) {
F_14 ( & V_12 -> V_42 , L_7 ) ;
return V_16 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_42 = & V_12 -> V_42 ;
V_2 -> V_40 = F_23 ( & V_12 -> V_42 ) ;
if ( ! V_2 -> V_40 ) {
F_14 ( & V_12 -> V_42 , L_8 ) ;
return - V_43 ;
}
V_44 = F_24 ( & V_12 -> V_42 , L_9 , & V_12 -> V_42 , V_2 ,
& V_57 ) ;
if ( F_25 ( V_44 ) )
return F_26 ( V_44 ) ;
V_2 -> V_44 = V_44 ;
if ( ! V_2 -> V_40 -> V_58 ) {
V_2 -> V_36 = V_52 ;
F_16 ( V_2 , V_51 ) ;
} else {
V_2 -> V_36 = V_51 ;
}
F_27 ( V_12 , V_2 ) ;
F_28 ( & V_12 -> V_42 , L_10 ) ;
return 0 ;
}
static int F_29 ( struct V_53 * V_12 )
{
struct V_1 * V_2 = F_30 ( V_12 ) ;
F_16 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 ) ;
F_33 ( V_42 , L_11 , V_2 -> V_36 ) ;
return F_16 ( V_2 , V_52 ) ;
}
static int F_34 ( struct V_59 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 ) ;
V_2 -> V_36 = V_52 ;
return F_16 ( V_2 , V_51 ) ;
}
static void F_35 ( struct V_53 * V_12 )
{
struct V_1 * V_2 = F_30 ( V_12 ) ;
F_16 ( V_2 , V_52 ) ;
}
