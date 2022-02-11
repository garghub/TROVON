static int F_1 ( struct V_1 * V_2 ,
struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = F_2 ( V_11 , V_4 , V_5 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = F_4 ( V_11 , V_4 , V_5 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned short V_17 ,
char V_18 , T_2 V_19 ,
int V_20 , union V_21 * V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = V_11 -> V_23 -> V_24 ( V_11 , V_16 , V_17 ,
V_18 , V_19 , V_20 , V_22 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned short V_17 ,
char V_18 , T_2 V_19 ,
int V_20 , union V_21 * V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = F_7 ( V_11 , V_16 , V_17 ,
V_18 , V_19 , V_20 , V_22 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static T_3 F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
return V_11 -> V_23 -> V_25 ( V_11 ) ;
}
static unsigned int F_9 ( struct V_1 * V_11 )
{
unsigned int V_26 = 0 ;
do {
V_26 |= V_11 -> V_26 ;
V_11 = F_10 ( V_11 ) ;
} while ( V_11 );
return V_26 ;
}
static void F_11 ( struct V_1 * V_27 , unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
F_12 ( & V_11 -> V_28 ) ;
if ( ! ( V_17 & V_29 ) )
return;
F_13 ( V_11 , V_17 ) ;
}
static int F_14 ( struct V_1 * V_27 , unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
if ( ! F_15 ( & V_11 -> V_28 ) )
return 0 ;
if ( ! ( V_17 & V_29 ) )
return 1 ;
if ( V_11 -> V_30 ( V_11 , V_17 ) )
return 1 ;
F_16 ( & V_11 -> V_28 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_27 , unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
if ( V_17 & V_29 )
F_18 ( V_11 , V_17 ) ;
F_16 ( & V_11 -> V_28 ) ;
}
static void F_19 ( struct V_1 * V_27 ,
unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
F_12 ( & V_11 -> V_28 ) ;
F_13 ( V_11 , V_17 ) ;
}
static int F_20 ( struct V_1 * V_27 ,
unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
if ( ! F_15 ( & V_11 -> V_28 ) )
return 0 ;
if ( V_11 -> V_30 ( V_11 , V_17 ) )
return 1 ;
F_16 ( & V_11 -> V_28 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_27 ,
unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
F_18 ( V_11 , V_17 ) ;
F_16 ( & V_11 -> V_28 ) ;
}
struct V_1 * F_22 ( struct V_31 * V_32 )
{
struct V_31 * V_33 ;
struct V_1 * V_34 ;
for ( V_33 = V_32 ; V_33 ; V_33 = V_33 -> V_11 ) {
if ( V_33 -> type == & V_35 )
break;
}
if ( ! V_33 )
return NULL ;
V_34 = F_23 ( V_33 ) ;
while ( F_10 ( V_34 ) )
V_34 = F_10 ( V_34 ) ;
return V_34 ;
}
struct V_9 * F_24 ( struct V_1 * V_11 ,
struct V_31 * V_32 , int V_36 ,
int V_37 , T_3 V_17 ,
int (* V_13)( struct V_9 * , T_3 ) ,
int (* V_15)( struct V_9 * , T_3 ) )
{
struct V_9 * V_10 ;
V_10 = F_25 ( V_32 , sizeof( * V_10 )
+ V_36 * sizeof( V_10 -> V_27 [ 0 ] )
+ V_37 , V_38 ) ;
if ( ! V_10 )
return NULL ;
if ( V_37 )
V_10 -> V_7 = & V_10 -> V_27 [ V_36 ] ;
V_10 -> V_11 = V_11 ;
V_10 -> V_32 = V_32 ;
if ( V_17 & V_39 )
V_10 -> V_40 = true ;
V_10 -> V_13 = V_13 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_36 = V_36 ;
return V_10 ;
}
int F_26 ( struct V_9 * V_10 ,
T_3 V_41 , T_3 V_14 ,
unsigned int V_26 )
{
struct V_1 * V_11 = V_10 -> V_11 ;
struct V_6 * V_7 ;
char V_42 [ 20 ] ;
int V_12 ;
if ( V_10 -> V_43 >= V_10 -> V_36 ) {
F_27 ( V_10 -> V_32 , L_1 ) ;
return - V_44 ;
}
V_7 = F_28 ( sizeof( * V_7 ) , V_38 ) ;
if ( ! V_7 )
return - V_45 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_14 = V_14 ;
if ( V_11 -> V_23 -> V_46 ) {
if ( V_10 -> V_40 )
V_7 -> V_23 . V_46 = F_3 ;
else
V_7 -> V_23 . V_46 = F_1 ;
}
if ( V_11 -> V_23 -> V_24 ) {
if ( V_10 -> V_40 )
V_7 -> V_23 . V_24 = F_6 ;
else
V_7 -> V_23 . V_24 = F_5 ;
}
V_7 -> V_23 . V_25 = F_8 ;
snprintf ( V_7 -> V_2 . V_47 , sizeof( V_7 -> V_2 . V_47 ) ,
L_2 , F_29 ( V_11 ) , V_14 ) ;
V_7 -> V_2 . V_48 = V_49 ;
V_7 -> V_2 . V_23 = & V_7 -> V_23 ;
V_7 -> V_2 . V_8 = V_7 ;
V_7 -> V_2 . V_32 . V_11 = & V_11 -> V_32 ;
V_7 -> V_2 . V_50 = V_11 -> V_50 ;
V_7 -> V_2 . V_51 = V_11 -> V_51 ;
V_7 -> V_2 . V_52 = V_11 -> V_52 ;
if ( V_10 -> V_40 ) {
V_7 -> V_2 . V_53 = F_11 ;
V_7 -> V_2 . V_30 = F_14 ;
V_7 -> V_2 . V_54 = F_17 ;
} else {
V_7 -> V_2 . V_53 = F_19 ;
V_7 -> V_2 . V_30 = F_20 ;
V_7 -> V_2 . V_54 = F_21 ;
}
if ( F_9 ( V_11 ) & V_26 )
F_27 ( & V_11 -> V_32 ,
L_3 ,
V_14 ) ;
else
V_7 -> V_2 . V_26 = V_26 ;
if ( V_10 -> V_32 -> V_55 ) {
struct V_56 * V_57 ;
T_3 V_58 ;
F_30 (muxc->dev->of_node, child) {
V_12 = F_31 ( V_57 , L_4 , & V_58 ) ;
if ( V_12 )
continue;
if ( V_14 == V_58 ) {
V_7 -> V_2 . V_32 . V_55 = V_57 ;
break;
}
}
}
if ( F_32 ( V_10 -> V_32 ) )
F_33 ( & V_7 -> V_2 . V_32 ,
F_34 ( V_10 -> V_32 ) ,
V_14 ) ;
if ( V_41 ) {
V_7 -> V_2 . V_59 = V_41 ;
V_12 = F_35 ( & V_7 -> V_2 ) ;
} else {
V_12 = F_36 ( & V_7 -> V_2 ) ;
}
if ( V_12 < 0 ) {
F_27 ( & V_11 -> V_32 ,
L_5 ,
V_12 ) ;
F_37 ( V_7 ) ;
return V_12 ;
}
F_38 ( F_39 ( & V_7 -> V_2 . V_32 . V_60 , & V_10 -> V_32 -> V_60 ,
L_6 ) ,
L_7 ) ;
snprintf ( V_42 , sizeof( V_42 ) , L_8 , V_14 ) ;
F_38 ( F_39 ( & V_10 -> V_32 -> V_60 , & V_7 -> V_2 . V_32 . V_60 ,
V_42 ) ,
L_9 , V_14 ) ;
F_40 ( & V_11 -> V_32 , L_10 ,
F_29 ( & V_7 -> V_2 ) ) ;
V_10 -> V_27 [ V_10 -> V_43 ++ ] = & V_7 -> V_2 ;
return 0 ;
}
void F_41 ( struct V_9 * V_10 )
{
char V_42 [ 20 ] ;
while ( V_10 -> V_43 ) {
struct V_1 * V_2 = V_10 -> V_27 [ -- V_10 -> V_43 ] ;
struct V_6 * V_7 = V_2 -> V_8 ;
V_10 -> V_27 [ V_10 -> V_43 ] = NULL ;
snprintf ( V_42 , sizeof( V_42 ) ,
L_8 , V_7 -> V_14 ) ;
F_42 ( & V_10 -> V_32 -> V_60 , V_42 ) ;
F_42 ( & V_7 -> V_2 . V_32 . V_60 , L_6 ) ;
F_43 ( V_2 ) ;
F_37 ( V_7 ) ;
}
}
