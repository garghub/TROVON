static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_8 + V_9 ) ;
return V_6 -> V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_11 = V_7 [ 0 ] ;
unsigned int V_12 = V_7 [ 1 ] ;
V_4 -> V_13 = F_2 ( V_2 -> V_8 + V_14 ) ;
if ( V_11 ) {
V_4 -> V_13 &= ~ V_11 ;
V_4 -> V_13 |= ( V_12 & V_11 ) ;
F_4 ( V_4 -> V_13 , V_2 -> V_8 + V_14 ) ;
}
V_7 [ 1 ] = V_4 -> V_13 ;
return V_6 -> V_10 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_18 ;
switch ( V_7 [ 0 ] ) {
case V_19 :
V_16 -> V_20 = V_21 ;
V_18 = V_7 [ 1 ] & V_4 -> V_22 ;
F_4 ( V_18 , V_16 -> V_23 + V_24 ) ;
F_6 ( V_2 -> V_25 , L_1 ,
20 * V_18 + 20 ) ;
break;
case V_26 :
V_16 -> V_20 = 0 ;
break;
default:
return - V_27 ;
}
F_4 ( V_16 -> V_20 , V_16 -> V_23 + V_28 ) ;
return V_6 -> V_10 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_29 ;
if ( V_16 -> V_20 == 0 ) {
F_8 ( V_2 -> V_25 , L_2 ) ;
return - V_27 ;
}
for ( V_29 = 0 ; V_29 < V_6 -> V_10 ; V_29 ++ ) {
F_4 ( V_16 -> V_20 | V_30 ,
V_16 -> V_23 + V_28 ) ;
}
return V_6 -> V_10 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_10 ; V_29 ++ )
V_7 [ V_29 ] = F_2 ( V_16 -> V_23 + V_31 ) ;
return V_6 -> V_10 ;
}
static int F_10 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_11 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_33 -> V_34 )
return 0 ;
F_4 ( 0x0 , V_2 -> V_8 + V_14 ) ;
F_4 ( 0x0 , V_16 -> V_23 + V_28 ) ;
F_4 ( 0x0 , V_16 -> V_23 + V_24 ) ;
return 0 ;
}
static const void * F_12 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
const struct V_32 * V_33 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_37 -> V_38 ; V_29 ++ ) {
V_33 = & V_39 [ V_29 ] ;
if ( V_33 -> V_40 == V_36 -> V_40 )
return V_33 ;
}
return NULL ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned long V_41 )
{
struct V_35 * V_36 = F_14 ( V_2 ) ;
const struct V_32 * V_33 ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_42 ;
V_33 = F_12 ( V_2 , V_36 ) ;
if ( ! V_33 )
return - V_43 ;
V_2 -> V_44 = V_33 ;
V_2 -> V_45 = V_33 -> V_46 ;
V_16 = F_15 ( sizeof( * V_16 ) , V_47 ) ;
if ( ! V_16 )
return - V_48 ;
V_2 -> V_17 = V_16 ;
V_42 = F_16 ( V_36 , V_2 -> V_45 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_8 = F_17 ( V_36 , 1 ) ;
V_16 -> V_23 = F_17 ( V_36 , 2 ) ;
V_42 = F_18 ( V_2 , 3 ) ;
if ( V_42 )
return V_42 ;
V_4 = & V_2 -> V_49 [ 0 ] ;
if ( V_33 -> V_50 ) {
V_4 -> type = V_51 ;
V_4 -> V_52 = V_53 ;
V_4 -> V_54 = V_33 -> V_50 ;
V_4 -> V_22 = 1 ;
V_4 -> V_55 = & V_56 ;
V_4 -> V_57 = F_1 ;
} else {
V_4 -> type = V_58 ;
}
V_4 = & V_2 -> V_49 [ 1 ] ;
if ( V_33 -> V_59 ) {
V_4 -> type = V_60 ;
V_4 -> V_52 = V_61 ;
V_4 -> V_54 = V_33 -> V_59 ;
V_4 -> V_22 = 1 ;
V_4 -> V_55 = & V_56 ;
V_4 -> V_57 = F_3 ;
} else {
V_4 -> type = V_58 ;
}
V_4 = & V_2 -> V_49 [ 2 ] ;
if ( V_33 -> V_34 ) {
V_4 -> type = V_62 ;
V_4 -> V_52 = V_61 ;
V_4 -> V_54 = 1 ;
V_4 -> V_22 = 0xff ;
V_4 -> V_63 = F_7 ;
V_4 -> V_64 = F_9 ;
V_4 -> V_65 = F_5 ;
} else {
V_4 -> type = V_58 ;
}
F_10 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_14 ( V_2 ) ;
if ( V_2 -> V_8 ) {
F_10 ( V_2 ) ;
F_20 ( V_36 ) ;
}
}
static int F_21 ( struct V_35 * V_2 ,
const struct V_66 * V_67 )
{
return F_22 ( V_2 , & V_68 ) ;
}
static void F_23 ( struct V_35 * V_2 )
{
F_24 ( V_2 ) ;
}
