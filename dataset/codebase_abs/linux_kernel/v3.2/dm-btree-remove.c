static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 . V_4 ) ;
T_1 V_6 = F_2 ( V_2 -> V_5 . V_6 ) ;
if ( V_3 < 0 ) {
V_3 = - V_3 ;
F_3 ( V_3 > V_4 ) ;
F_3 ( ( void * ) F_4 ( V_2 , V_3 ) >= F_5 ( V_2 , V_3 , V_6 ) ) ;
memmove ( F_4 ( V_2 , 0 ) ,
F_4 ( V_2 , V_3 ) ,
( V_4 - V_3 ) * sizeof( V_7 ) ) ;
memmove ( F_5 ( V_2 , 0 , V_6 ) ,
F_5 ( V_2 , V_3 , V_6 ) ,
( V_4 - V_3 ) * V_6 ) ;
} else {
F_3 ( V_4 + V_3 > F_2 ( V_2 -> V_5 . V_8 ) ) ;
memmove ( F_4 ( V_2 , V_3 ) ,
F_4 ( V_2 , 0 ) ,
V_4 * sizeof( V_7 ) ) ;
memmove ( F_5 ( V_2 , V_3 , V_6 ) ,
F_5 ( V_2 , 0 , V_6 ) ,
V_4 * V_6 ) ;
}
}
static void F_6 ( struct V_1 * V_9 , struct V_1 * V_10 , int V_3 )
{
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_6 = F_2 ( V_9 -> V_5 . V_6 ) ;
F_3 ( V_6 != F_2 ( V_10 -> V_5 . V_6 ) ) ;
if ( V_3 < 0 ) {
V_3 = - V_3 ;
F_3 ( V_11 + V_3 > F_2 ( V_9 -> V_5 . V_8 ) ) ;
memcpy ( F_4 ( V_9 , V_11 ) ,
F_4 ( V_10 , 0 ) ,
V_3 * sizeof( V_7 ) ) ;
memcpy ( F_5 ( V_9 , V_11 , V_6 ) ,
F_5 ( V_10 , 0 , V_6 ) ,
V_3 * V_6 ) ;
} else {
F_3 ( V_3 > F_2 ( V_10 -> V_5 . V_8 ) ) ;
memcpy ( F_4 ( V_10 , 0 ) ,
F_4 ( V_9 , V_11 - V_3 ) ,
V_3 * sizeof( V_7 ) ) ;
memcpy ( F_5 ( V_10 , 0 , V_6 ) ,
F_5 ( V_9 , V_11 - V_3 , V_6 ) ,
V_3 * V_6 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , unsigned V_12 )
{
unsigned V_4 = F_2 ( V_2 -> V_5 . V_4 ) ;
unsigned V_13 = V_4 - ( V_12 + 1 ) ;
T_1 V_6 = F_2 ( V_2 -> V_5 . V_6 ) ;
F_3 ( V_12 >= V_4 ) ;
if ( V_13 ) {
memmove ( F_4 ( V_2 , V_12 ) ,
F_4 ( V_2 , V_12 + 1 ) ,
V_13 * sizeof( V_7 ) ) ;
memmove ( F_5 ( V_2 , V_12 , V_6 ) ,
F_5 ( V_2 , V_12 + 1 , V_6 ) ,
V_13 * V_6 ) ;
}
V_2 -> V_5 . V_4 = F_8 ( V_4 - 1 ) ;
}
static unsigned F_9 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 . V_8 ) / 3 ;
}
static unsigned F_10 ( struct V_1 * V_2 )
{
return 2 * ( F_2 ( V_2 -> V_5 . V_8 ) / 3 ) + 1 ;
}
static int F_11 ( struct V_14 * V_15 , struct V_1 * V_16 ,
unsigned V_12 , struct V_17 * V_18 )
{
int V_19 , V_20 ;
T_2 V_21 ;
V_18 -> V_12 = V_12 ;
V_21 = F_12 ( V_16 , V_12 ) ;
V_19 = F_13 ( V_15 -> V_22 , V_21 , & V_23 ,
& V_18 -> V_24 , & V_20 ) ;
if ( V_19 )
return V_19 ;
V_18 -> V_2 = F_14 ( V_18 -> V_24 ) ;
if ( V_20 )
F_15 ( V_15 -> V_22 , V_18 -> V_2 , & V_25 ) ;
* ( ( V_7 * ) F_5 ( V_16 , V_12 , sizeof( V_7 ) ) ) =
F_16 ( F_17 ( V_18 -> V_24 ) ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 , struct V_17 * V_26 )
{
return F_19 ( V_15 -> V_22 , V_26 -> V_24 ) ;
}
static void V_3 ( struct V_1 * V_9 , struct V_1 * V_10 , int V_27 )
{
if ( ! V_27 )
return;
if ( V_27 > 0 ) {
F_1 ( V_10 , V_27 ) ;
F_6 ( V_9 , V_10 , V_27 ) ;
} else {
F_6 ( V_9 , V_10 , V_27 ) ;
F_1 ( V_10 , V_27 ) ;
}
V_9 -> V_5 . V_4 =
F_8 ( F_2 ( V_9 -> V_5 . V_4 ) - V_27 ) ;
F_3 ( F_2 ( V_9 -> V_5 . V_4 ) > F_2 ( V_9 -> V_5 . V_8 ) ) ;
V_10 -> V_5 . V_4 =
F_8 ( F_2 ( V_10 -> V_5 . V_4 ) + V_27 ) ;
F_3 ( F_2 ( V_10 -> V_5 . V_4 ) > F_2 ( V_10 -> V_5 . V_8 ) ) ;
}
static void F_20 ( struct V_14 * V_15 , struct V_1 * V_16 ,
struct V_17 * V_28 , struct V_17 * V_19 )
{
struct V_1 * V_9 = V_28 -> V_2 ;
struct V_1 * V_10 = V_19 -> V_2 ;
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_29 = F_2 ( V_10 -> V_5 . V_4 ) ;
if ( V_11 + V_29 <= F_10 ( V_9 ) ) {
F_6 ( V_9 , V_10 , - V_29 ) ;
V_9 -> V_5 . V_4 = F_8 ( V_11 + V_29 ) ;
F_7 ( V_16 , V_19 -> V_12 ) ;
F_21 ( V_15 -> V_22 , F_17 ( V_19 -> V_24 ) ) ;
} else {
unsigned V_30 = ( V_11 + V_29 ) / 2 ;
unsigned V_31 = V_11 - V_30 ;
F_3 ( F_2 ( V_9 -> V_5 . V_8 ) <= V_11 - V_31 ) ;
F_3 ( F_2 ( V_10 -> V_5 . V_8 ) <= V_29 + V_31 ) ;
V_3 ( V_9 , V_10 , V_11 - V_30 ) ;
* F_4 ( V_16 , V_19 -> V_12 ) = V_10 -> V_32 [ 0 ] ;
}
}
static int F_22 ( struct V_33 * V_34 , struct V_14 * V_15 ,
unsigned V_35 )
{
int V_19 ;
struct V_1 * V_16 ;
struct V_17 V_9 , V_10 ;
V_16 = F_14 ( F_23 ( V_34 ) ) ;
V_19 = F_11 ( V_15 , V_16 , V_35 , & V_9 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_11 ( V_15 , V_16 , V_35 + 1 , & V_10 ) ;
if ( V_19 ) {
F_18 ( V_15 , & V_9 ) ;
return V_19 ;
}
F_20 ( V_15 , V_16 , & V_9 , & V_10 ) ;
V_19 = F_18 ( V_15 , & V_9 ) ;
if ( V_19 ) {
F_18 ( V_15 , & V_10 ) ;
return V_19 ;
}
return F_18 ( V_15 , & V_10 ) ;
}
static void F_24 ( struct V_14 * V_15 , struct V_1 * V_16 ,
struct V_17 * V_28 , struct V_17 * V_26 , struct V_17 * V_19 )
{
struct V_1 * V_9 = V_28 -> V_2 ;
struct V_1 * V_36 = V_26 -> V_2 ;
struct V_1 * V_10 = V_19 -> V_2 ;
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_37 = F_2 ( V_36 -> V_5 . V_4 ) ;
T_1 V_29 = F_2 ( V_10 -> V_5 . V_4 ) ;
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
unsigned V_38 ;
F_3 ( V_9 -> V_5 . V_8 != V_36 -> V_5 . V_8 ) ;
F_3 ( V_36 -> V_5 . V_8 != V_10 -> V_5 . V_8 ) ;
if ( ( ( V_11 + V_37 + V_29 ) / 2 ) < F_10 ( V_36 ) ) {
unsigned V_3 = F_25 ( V_8 - V_11 , V_37 ) ;
F_3 ( V_11 + V_3 > V_8 ) ;
F_6 ( V_9 , V_36 , - V_3 ) ;
V_9 -> V_5 . V_4 = F_8 ( V_11 + V_3 ) ;
if ( V_3 != V_37 ) {
V_3 = V_37 - V_3 ;
F_3 ( ( V_29 + V_3 ) >= V_8 ) ;
F_1 ( V_10 , V_3 ) ;
F_6 ( V_36 , V_10 , V_3 ) ;
V_10 -> V_5 . V_4 = F_8 ( V_29 + V_3 ) ;
}
* F_4 ( V_16 , V_19 -> V_12 ) = V_10 -> V_32 [ 0 ] ;
F_7 ( V_16 , V_26 -> V_12 ) ;
V_19 -> V_12 -- ;
F_21 ( V_15 -> V_22 , F_17 ( V_26 -> V_24 ) ) ;
F_20 ( V_15 , V_16 , V_28 , V_19 ) ;
return;
}
V_38 = ( V_11 + V_37 + V_29 ) / 3 ;
F_3 ( V_38 > V_8 ) ;
V_3 ( V_9 , V_36 , V_11 - V_38 ) ;
V_3 ( V_36 , V_10 , V_38 - V_29 ) ;
* F_4 ( V_16 , V_26 -> V_12 ) = V_36 -> V_32 [ 0 ] ;
* F_4 ( V_16 , V_19 -> V_12 ) = V_10 -> V_32 [ 0 ] ;
}
static int F_26 ( struct V_33 * V_34 , struct V_14 * V_15 ,
unsigned V_35 )
{
int V_19 ;
struct V_1 * V_16 = F_14 ( F_23 ( V_34 ) ) ;
struct V_17 V_9 , V_36 , V_10 ;
V_19 = F_11 ( V_15 , V_16 , V_35 , & V_9 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_11 ( V_15 , V_16 , V_35 + 1 , & V_36 ) ;
if ( V_19 ) {
F_18 ( V_15 , & V_9 ) ;
return V_19 ;
}
V_19 = F_11 ( V_15 , V_16 , V_35 + 2 , & V_10 ) ;
if ( V_19 ) {
F_18 ( V_15 , & V_9 ) ;
F_18 ( V_15 , & V_36 ) ;
return V_19 ;
}
F_24 ( V_15 , V_16 , & V_9 , & V_36 , & V_10 ) ;
V_19 = F_18 ( V_15 , & V_9 ) ;
if ( V_19 ) {
F_18 ( V_15 , & V_36 ) ;
F_18 ( V_15 , & V_10 ) ;
return V_19 ;
}
V_19 = F_18 ( V_15 , & V_36 ) ;
if ( V_19 ) {
F_18 ( V_15 , & V_10 ) ;
return V_19 ;
}
V_19 = F_18 ( V_15 , & V_10 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_27 ( struct V_39 * V_22 ,
T_2 V_40 , T_1 * V_18 )
{
int V_19 ;
struct V_41 * V_24 ;
struct V_1 * V_2 ;
V_19 = F_28 ( V_22 , V_40 , & V_23 , & V_24 ) ;
if ( V_19 )
return V_19 ;
V_2 = F_14 ( V_24 ) ;
* V_18 = F_2 ( V_2 -> V_5 . V_4 ) ;
return F_19 ( V_22 , V_24 ) ;
}
static int F_29 ( struct V_33 * V_34 ,
struct V_14 * V_15 , T_3 V_42 )
{
int V_43 , V_19 , V_44 , V_45 ;
T_1 V_46 ;
struct V_1 * V_2 ;
V_2 = F_14 ( F_23 ( V_34 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_4 ) == 1 ) {
struct V_41 * V_17 ;
T_2 V_40 = F_12 ( V_2 , 0 ) ;
V_19 = F_28 ( V_15 -> V_22 , V_40 , & V_23 , & V_17 ) ;
if ( V_19 )
return V_19 ;
memcpy ( V_2 , F_14 ( V_17 ) ,
F_30 ( F_31 ( V_15 -> V_22 ) ) ) ;
V_19 = F_19 ( V_15 -> V_22 , V_17 ) ;
if ( V_19 )
return V_19 ;
F_21 ( V_15 -> V_22 , F_17 ( V_17 ) ) ;
return 0 ;
}
V_43 = F_32 ( V_2 , V_42 ) ;
if ( V_43 < 0 )
return - V_47 ;
V_19 = F_27 ( V_15 -> V_22 , F_12 ( V_2 , V_43 ) , & V_46 ) ;
if ( V_19 )
return V_19 ;
if ( V_46 > F_9 ( V_2 ) )
return 0 ;
V_44 = V_43 > 0 ;
V_45 = V_43 < ( F_2 ( V_2 -> V_5 . V_4 ) - 1 ) ;
if ( ! V_44 )
V_19 = F_22 ( V_34 , V_15 , V_43 ) ;
else if ( ! V_45 )
V_19 = F_22 ( V_34 , V_15 , V_43 - 1 ) ;
else
V_19 = F_26 ( V_34 , V_15 , V_43 - 1 ) ;
return V_19 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_42 , unsigned * V_12 )
{
int V_43 = F_32 ( V_2 , V_42 ) ;
if ( ( V_43 < 0 ) ||
( V_43 >= F_2 ( V_2 -> V_5 . V_4 ) ) ||
( F_34 ( V_2 -> V_32 [ V_43 ] ) != V_42 ) )
return - V_47 ;
* V_12 = V_43 ;
return 0 ;
}
static int F_35 ( struct V_33 * V_34 , struct V_14 * V_15 ,
struct V_48 * V_49 , T_2 V_21 ,
T_3 V_42 , unsigned * V_12 )
{
int V_43 = * V_12 , V_19 ;
struct V_1 * V_2 ;
for (; ; ) {
V_19 = F_36 ( V_34 , V_21 , V_49 ) ;
if ( V_19 < 0 )
break;
if ( F_37 ( V_34 ) ) {
V_7 V_50 = F_16 ( F_17 ( F_23 ( V_34 ) ) ) ;
memcpy ( F_5 ( F_14 ( F_38 ( V_34 ) ) , V_43 , sizeof( V_7 ) ) ,
& V_50 , sizeof( V_7 ) ) ;
}
V_2 = F_14 ( F_23 ( V_34 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_51 ) & V_52 )
return F_33 ( V_2 , V_42 , V_12 ) ;
V_19 = F_29 ( V_34 , V_15 , V_42 ) ;
if ( V_19 )
break;
V_2 = F_14 ( F_23 ( V_34 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_51 ) & V_52 )
return F_33 ( V_2 , V_42 , V_12 ) ;
V_43 = F_32 ( V_2 , V_42 ) ;
V_21 = F_12 ( V_2 , V_43 ) ;
}
return V_19 ;
}
int F_39 ( struct V_14 * V_15 , T_2 V_21 ,
T_3 * V_32 , T_2 * V_53 )
{
unsigned V_54 , V_55 = V_15 -> V_56 - 1 ;
int V_12 = 0 , V_19 = 0 ;
struct V_33 V_57 ;
struct V_1 * V_2 ;
F_40 ( & V_57 , V_15 ) ;
for ( V_54 = 0 ; V_54 < V_15 -> V_56 ; V_54 ++ ) {
V_19 = F_35 ( & V_57 , V_15 ,
( V_54 == V_55 ?
& V_15 -> V_58 : & V_25 ) ,
V_21 , V_32 [ V_54 ] , ( unsigned * ) & V_12 ) ;
if ( V_19 < 0 )
break;
V_2 = F_14 ( F_23 ( & V_57 ) ) ;
if ( V_54 != V_55 ) {
V_21 = F_12 ( V_2 , V_12 ) ;
continue;
}
F_3 ( V_12 < 0 || V_12 >= F_2 ( V_2 -> V_5 . V_4 ) ) ;
if ( V_15 -> V_58 . V_59 )
V_15 -> V_58 . V_59 ( V_15 -> V_58 . V_60 ,
F_5 ( V_2 , V_12 , V_15 -> V_58 . V_61 ) ) ;
F_7 ( V_2 , V_12 ) ;
}
* V_53 = F_41 ( & V_57 ) ;
F_42 ( & V_57 ) ;
return V_19 ;
}
