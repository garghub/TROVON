static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 . V_4 ) ;
T_1 V_6 = F_2 ( V_2 -> V_5 . V_6 ) ;
if ( V_3 < 0 ) {
V_3 = - V_3 ;
F_3 ( V_3 > V_4 ) ;
F_3 ( ( void * ) F_4 ( V_2 , V_3 ) >= F_5 ( V_2 , V_3 ) ) ;
memmove ( F_4 ( V_2 , 0 ) ,
F_4 ( V_2 , V_3 ) ,
( V_4 - V_3 ) * sizeof( V_7 ) ) ;
memmove ( F_5 ( V_2 , 0 ) ,
F_5 ( V_2 , V_3 ) ,
( V_4 - V_3 ) * V_6 ) ;
} else {
F_3 ( V_4 + V_3 > F_2 ( V_2 -> V_5 . V_8 ) ) ;
memmove ( F_4 ( V_2 , V_3 ) ,
F_4 ( V_2 , 0 ) ,
V_4 * sizeof( V_7 ) ) ;
memmove ( F_5 ( V_2 , V_3 ) ,
F_5 ( V_2 , 0 ) ,
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
memcpy ( F_5 ( V_9 , V_11 ) ,
F_5 ( V_10 , 0 ) ,
V_3 * V_6 ) ;
} else {
F_3 ( V_3 > F_2 ( V_10 -> V_5 . V_8 ) ) ;
memcpy ( F_4 ( V_10 , 0 ) ,
F_4 ( V_9 , V_11 - V_3 ) ,
V_3 * sizeof( V_7 ) ) ;
memcpy ( F_5 ( V_10 , 0 ) ,
F_5 ( V_9 , V_11 - V_3 ) ,
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
memmove ( F_5 ( V_2 , V_12 ) ,
F_5 ( V_2 , V_12 + 1 ) ,
V_13 * V_6 ) ;
}
V_2 -> V_5 . V_4 = F_8 ( V_4 - 1 ) ;
}
static unsigned F_9 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 . V_8 ) / 3 ;
}
static int F_10 ( struct V_14 * V_15 , struct V_1 * V_16 ,
unsigned V_12 , struct V_17 * V_18 )
{
int V_19 , V_20 ;
T_2 V_21 ;
V_18 -> V_12 = V_12 ;
V_21 = F_11 ( V_16 , V_12 ) ;
V_19 = F_12 ( V_15 -> V_22 , V_21 , & V_23 ,
& V_18 -> V_24 , & V_20 ) ;
if ( V_19 )
return V_19 ;
V_18 -> V_2 = F_13 ( V_18 -> V_24 ) ;
if ( V_20 )
F_14 ( V_15 -> V_22 , V_18 -> V_2 , & V_25 ) ;
* ( ( V_7 * ) F_5 ( V_16 , V_12 ) ) =
F_15 ( F_16 ( V_18 -> V_24 ) ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , struct V_17 * V_26 )
{
return F_18 ( V_15 -> V_22 , V_26 -> V_24 ) ;
}
static void V_3 ( struct V_1 * V_9 , struct V_1 * V_10 , int V_27 )
{
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_28 = F_2 ( V_10 -> V_5 . V_4 ) ;
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
T_1 V_29 = F_2 ( V_10 -> V_5 . V_8 ) ;
F_3 ( V_8 != V_29 ) ;
F_3 ( V_11 - V_27 > V_8 ) ;
F_3 ( V_28 + V_27 > V_8 ) ;
if ( ! V_27 )
return;
if ( V_27 > 0 ) {
F_1 ( V_10 , V_27 ) ;
F_6 ( V_9 , V_10 , V_27 ) ;
} else {
F_6 ( V_9 , V_10 , V_27 ) ;
F_1 ( V_10 , V_27 ) ;
}
V_9 -> V_5 . V_4 = F_8 ( V_11 - V_27 ) ;
V_10 -> V_5 . V_4 = F_8 ( V_28 + V_27 ) ;
}
static void F_19 ( struct V_14 * V_15 , struct V_1 * V_16 ,
struct V_17 * V_30 , struct V_17 * V_19 )
{
struct V_1 * V_9 = V_30 -> V_2 ;
struct V_1 * V_10 = V_19 -> V_2 ;
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_28 = F_2 ( V_10 -> V_5 . V_4 ) ;
unsigned V_31 = 2 * F_9 ( V_9 ) + 1 ;
if ( V_11 + V_28 < V_31 ) {
F_6 ( V_9 , V_10 , - V_28 ) ;
V_9 -> V_5 . V_4 = F_8 ( V_11 + V_28 ) ;
F_7 ( V_16 , V_19 -> V_12 ) ;
F_20 ( V_15 -> V_22 , F_16 ( V_19 -> V_24 ) ) ;
} else {
unsigned V_32 = ( V_11 + V_28 ) / 2 ;
V_3 ( V_9 , V_10 , V_11 - V_32 ) ;
* F_4 ( V_16 , V_19 -> V_12 ) = V_10 -> V_33 [ 0 ] ;
}
}
static int F_21 ( struct V_34 * V_35 , struct V_14 * V_15 ,
unsigned V_36 )
{
int V_19 ;
struct V_1 * V_16 ;
struct V_17 V_9 , V_10 ;
V_16 = F_13 ( F_22 ( V_35 ) ) ;
V_19 = F_10 ( V_15 , V_16 , V_36 , & V_9 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( V_15 , V_16 , V_36 + 1 , & V_10 ) ;
if ( V_19 ) {
F_17 ( V_15 , & V_9 ) ;
return V_19 ;
}
F_19 ( V_15 , V_16 , & V_9 , & V_10 ) ;
V_19 = F_17 ( V_15 , & V_9 ) ;
if ( V_19 ) {
F_17 ( V_15 , & V_10 ) ;
return V_19 ;
}
return F_17 ( V_15 , & V_10 ) ;
}
static void F_23 ( struct V_14 * V_15 , struct V_1 * V_16 ,
struct V_17 * V_30 , struct V_17 * V_26 , struct V_17 * V_19 ,
struct V_1 * V_9 , struct V_1 * V_37 , struct V_1 * V_10 ,
T_1 V_11 , T_1 V_38 , T_1 V_28 )
{
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
unsigned V_3 = F_24 ( V_8 - V_11 , V_38 ) ;
F_3 ( V_11 + V_3 > V_8 ) ;
F_6 ( V_9 , V_37 , - V_3 ) ;
V_9 -> V_5 . V_4 = F_8 ( V_11 + V_3 ) ;
if ( V_3 != V_38 ) {
V_3 = V_38 - V_3 ;
F_3 ( ( V_28 + V_3 ) > V_8 ) ;
F_1 ( V_10 , V_3 ) ;
F_6 ( V_37 , V_10 , V_3 ) ;
V_10 -> V_5 . V_4 = F_8 ( V_28 + V_3 ) ;
}
* F_4 ( V_16 , V_19 -> V_12 ) = V_10 -> V_33 [ 0 ] ;
F_7 ( V_16 , V_26 -> V_12 ) ;
V_19 -> V_12 -- ;
F_20 ( V_15 -> V_22 , F_16 ( V_26 -> V_24 ) ) ;
F_19 ( V_15 , V_16 , V_30 , V_19 ) ;
}
static void F_25 ( struct V_14 * V_15 , struct V_1 * V_16 ,
struct V_17 * V_30 , struct V_17 * V_26 , struct V_17 * V_19 ,
struct V_1 * V_9 , struct V_1 * V_37 , struct V_1 * V_10 ,
T_1 V_11 , T_1 V_38 , T_1 V_28 )
{
int V_35 ;
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
unsigned V_39 = ( V_11 + V_38 + V_28 ) / 3 ;
F_3 ( V_39 > V_8 ) ;
if ( V_11 < V_28 ) {
V_35 = V_11 - V_39 ;
if ( V_35 < 0 && V_38 < - V_35 ) {
V_3 ( V_9 , V_37 , V_38 ) ;
V_35 = V_38 - V_39 ;
V_3 ( V_9 , V_10 , V_35 ) ;
V_28 += V_35 ;
} else
V_3 ( V_9 , V_37 , V_35 ) ;
V_3 ( V_37 , V_10 , V_39 - V_28 ) ;
} else {
V_35 = V_39 - V_28 ;
if ( V_35 > 0 && V_38 < V_35 ) {
V_3 ( V_37 , V_10 , V_38 ) ;
V_35 = V_39 - V_38 ;
V_3 ( V_9 , V_10 , V_35 ) ;
V_11 -= V_35 ;
} else
V_3 ( V_37 , V_10 , V_35 ) ;
V_3 ( V_9 , V_37 , V_11 - V_39 ) ;
}
* F_4 ( V_16 , V_26 -> V_12 ) = V_37 -> V_33 [ 0 ] ;
* F_4 ( V_16 , V_19 -> V_12 ) = V_10 -> V_33 [ 0 ] ;
}
static void F_26 ( struct V_14 * V_15 , struct V_1 * V_16 ,
struct V_17 * V_30 , struct V_17 * V_26 , struct V_17 * V_19 )
{
struct V_1 * V_9 = V_30 -> V_2 ;
struct V_1 * V_37 = V_26 -> V_2 ;
struct V_1 * V_10 = V_19 -> V_2 ;
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_38 = F_2 ( V_37 -> V_5 . V_4 ) ;
T_1 V_28 = F_2 ( V_10 -> V_5 . V_4 ) ;
unsigned V_31 = F_9 ( V_9 ) * 4 + 1 ;
F_3 ( V_9 -> V_5 . V_8 != V_37 -> V_5 . V_8 ) ;
F_3 ( V_37 -> V_5 . V_8 != V_10 -> V_5 . V_8 ) ;
if ( ( V_11 + V_38 + V_28 ) < V_31 )
F_23 ( V_15 , V_16 , V_30 , V_26 , V_19 , V_9 , V_37 , V_10 ,
V_11 , V_38 , V_28 ) ;
else
F_25 ( V_15 , V_16 , V_30 , V_26 , V_19 , V_9 , V_37 , V_10 ,
V_11 , V_38 , V_28 ) ;
}
static int F_27 ( struct V_34 * V_35 , struct V_14 * V_15 ,
unsigned V_36 )
{
int V_19 ;
struct V_1 * V_16 = F_13 ( F_22 ( V_35 ) ) ;
struct V_17 V_9 , V_37 , V_10 ;
V_19 = F_10 ( V_15 , V_16 , V_36 , & V_9 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( V_15 , V_16 , V_36 + 1 , & V_37 ) ;
if ( V_19 ) {
F_17 ( V_15 , & V_9 ) ;
return V_19 ;
}
V_19 = F_10 ( V_15 , V_16 , V_36 + 2 , & V_10 ) ;
if ( V_19 ) {
F_17 ( V_15 , & V_9 ) ;
F_17 ( V_15 , & V_37 ) ;
return V_19 ;
}
F_26 ( V_15 , V_16 , & V_9 , & V_37 , & V_10 ) ;
V_19 = F_17 ( V_15 , & V_9 ) ;
if ( V_19 ) {
F_17 ( V_15 , & V_37 ) ;
F_17 ( V_15 , & V_10 ) ;
return V_19 ;
}
V_19 = F_17 ( V_15 , & V_37 ) ;
if ( V_19 ) {
F_17 ( V_15 , & V_10 ) ;
return V_19 ;
}
V_19 = F_17 ( V_15 , & V_10 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_28 ( struct V_40 * V_22 ,
T_2 V_41 , T_1 * V_18 )
{
int V_19 ;
struct V_42 * V_24 ;
struct V_1 * V_2 ;
V_19 = F_29 ( V_22 , V_41 , & V_23 , & V_24 ) ;
if ( V_19 )
return V_19 ;
V_2 = F_13 ( V_24 ) ;
* V_18 = F_2 ( V_2 -> V_5 . V_4 ) ;
return F_18 ( V_22 , V_24 ) ;
}
static int F_30 ( struct V_34 * V_35 ,
struct V_14 * V_15 , T_3 V_43 )
{
int V_44 , V_19 , V_45 , V_46 ;
T_1 V_47 ;
struct V_1 * V_2 ;
V_2 = F_13 ( F_22 ( V_35 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_4 ) == 1 ) {
struct V_42 * V_17 ;
T_2 V_41 = F_11 ( V_2 , 0 ) ;
V_19 = F_29 ( V_15 -> V_22 , V_41 , & V_23 , & V_17 ) ;
if ( V_19 )
return V_19 ;
memcpy ( V_2 , F_13 ( V_17 ) ,
F_31 ( F_32 ( V_15 -> V_22 ) ) ) ;
V_19 = F_18 ( V_15 -> V_22 , V_17 ) ;
if ( V_19 )
return V_19 ;
F_20 ( V_15 -> V_22 , F_16 ( V_17 ) ) ;
return 0 ;
}
V_44 = F_33 ( V_2 , V_43 ) ;
if ( V_44 < 0 )
return - V_48 ;
V_19 = F_28 ( V_15 -> V_22 , F_11 ( V_2 , V_44 ) , & V_47 ) ;
if ( V_19 )
return V_19 ;
V_45 = V_44 > 0 ;
V_46 = V_44 < ( F_2 ( V_2 -> V_5 . V_4 ) - 1 ) ;
if ( ! V_45 )
V_19 = F_21 ( V_35 , V_15 , V_44 ) ;
else if ( ! V_46 )
V_19 = F_21 ( V_35 , V_15 , V_44 - 1 ) ;
else
V_19 = F_27 ( V_35 , V_15 , V_44 - 1 ) ;
return V_19 ;
}
static int F_34 ( struct V_1 * V_2 , T_3 V_43 , unsigned * V_12 )
{
int V_44 = F_33 ( V_2 , V_43 ) ;
if ( ( V_44 < 0 ) ||
( V_44 >= F_2 ( V_2 -> V_5 . V_4 ) ) ||
( F_35 ( V_2 -> V_33 [ V_44 ] ) != V_43 ) )
return - V_48 ;
* V_12 = V_44 ;
return 0 ;
}
static int F_36 ( struct V_34 * V_35 , struct V_14 * V_15 ,
struct V_49 * V_50 , T_2 V_21 ,
T_3 V_43 , unsigned * V_12 )
{
int V_44 = * V_12 , V_19 ;
struct V_1 * V_2 ;
for (; ; ) {
V_19 = F_37 ( V_35 , V_21 , V_50 ) ;
if ( V_19 < 0 )
break;
if ( F_38 ( V_35 ) ) {
V_7 V_51 = F_15 ( F_16 ( F_22 ( V_35 ) ) ) ;
memcpy ( F_5 ( F_13 ( F_39 ( V_35 ) ) , V_44 ) ,
& V_51 , sizeof( V_7 ) ) ;
}
V_2 = F_13 ( F_22 ( V_35 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_52 ) & V_53 )
return F_34 ( V_2 , V_43 , V_12 ) ;
V_19 = F_30 ( V_35 , V_15 , V_43 ) ;
if ( V_19 )
break;
V_2 = F_13 ( F_22 ( V_35 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_52 ) & V_53 )
return F_34 ( V_2 , V_43 , V_12 ) ;
V_44 = F_33 ( V_2 , V_43 ) ;
V_21 = F_11 ( V_2 , V_44 ) ;
}
return V_19 ;
}
int F_40 ( struct V_14 * V_15 , T_2 V_21 ,
T_3 * V_33 , T_2 * V_54 )
{
unsigned V_55 , V_56 = V_15 -> V_57 - 1 ;
int V_12 = 0 , V_19 = 0 ;
struct V_34 V_58 ;
struct V_1 * V_2 ;
F_41 ( & V_58 , V_15 ) ;
for ( V_55 = 0 ; V_55 < V_15 -> V_57 ; V_55 ++ ) {
V_19 = F_36 ( & V_58 , V_15 ,
( V_55 == V_56 ?
& V_15 -> V_59 : & V_25 ) ,
V_21 , V_33 [ V_55 ] , ( unsigned * ) & V_12 ) ;
if ( V_19 < 0 )
break;
V_2 = F_13 ( F_22 ( & V_58 ) ) ;
if ( V_55 != V_56 ) {
V_21 = F_11 ( V_2 , V_12 ) ;
continue;
}
F_3 ( V_12 < 0 || V_12 >= F_2 ( V_2 -> V_5 . V_4 ) ) ;
if ( V_15 -> V_59 . V_60 )
V_15 -> V_59 . V_60 ( V_15 -> V_59 . V_61 ,
F_5 ( V_2 , V_12 ) ) ;
F_7 ( V_2 , V_12 ) ;
}
* V_54 = F_42 ( & V_58 ) ;
F_43 ( & V_58 ) ;
return V_19 ;
}
