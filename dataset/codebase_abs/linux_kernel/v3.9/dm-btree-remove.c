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
static int F_10 ( struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_1 * V_18 ,
unsigned V_12 , struct V_19 * V_20 )
{
int V_21 , V_22 ;
T_2 V_23 ;
V_20 -> V_12 = V_12 ;
V_23 = F_11 ( V_18 , V_12 ) ;
V_21 = F_12 ( V_15 -> V_24 , V_23 , & V_25 ,
& V_20 -> V_26 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_20 -> V_2 = F_13 ( V_20 -> V_26 ) ;
if ( V_22 )
F_14 ( V_15 -> V_24 , V_20 -> V_2 , V_17 ) ;
* ( ( V_7 * ) F_5 ( V_18 , V_12 ) ) =
F_15 ( F_16 ( V_20 -> V_26 ) ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , struct V_19 * V_27 )
{
return F_18 ( V_15 -> V_24 , V_27 -> V_26 ) ;
}
static void V_3 ( struct V_1 * V_9 , struct V_1 * V_10 , int V_28 )
{
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_29 = F_2 ( V_10 -> V_5 . V_4 ) ;
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
T_1 V_30 = F_2 ( V_10 -> V_5 . V_8 ) ;
F_3 ( V_8 != V_30 ) ;
F_3 ( V_11 - V_28 > V_8 ) ;
F_3 ( V_29 + V_28 > V_8 ) ;
if ( ! V_28 )
return;
if ( V_28 > 0 ) {
F_1 ( V_10 , V_28 ) ;
F_6 ( V_9 , V_10 , V_28 ) ;
} else {
F_6 ( V_9 , V_10 , V_28 ) ;
F_1 ( V_10 , V_28 ) ;
}
V_9 -> V_5 . V_4 = F_8 ( V_11 - V_28 ) ;
V_10 -> V_5 . V_4 = F_8 ( V_29 + V_28 ) ;
}
static void F_19 ( struct V_14 * V_15 , struct V_1 * V_18 ,
struct V_19 * V_31 , struct V_19 * V_21 )
{
struct V_1 * V_9 = V_31 -> V_2 ;
struct V_1 * V_10 = V_21 -> V_2 ;
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_29 = F_2 ( V_10 -> V_5 . V_4 ) ;
unsigned V_32 = 2 * F_9 ( V_9 ) + 1 ;
if ( V_11 + V_29 < V_32 ) {
F_6 ( V_9 , V_10 , - V_29 ) ;
V_9 -> V_5 . V_4 = F_8 ( V_11 + V_29 ) ;
F_7 ( V_18 , V_21 -> V_12 ) ;
F_20 ( V_15 -> V_24 , F_16 ( V_21 -> V_26 ) ) ;
} else {
unsigned V_33 = ( V_11 + V_29 ) / 2 ;
V_3 ( V_9 , V_10 , V_11 - V_33 ) ;
* F_4 ( V_18 , V_21 -> V_12 ) = V_10 -> V_34 [ 0 ] ;
}
}
static int F_21 ( struct V_35 * V_36 , struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned V_37 )
{
int V_21 ;
struct V_1 * V_18 ;
struct V_19 V_9 , V_10 ;
V_18 = F_13 ( F_22 ( V_36 ) ) ;
V_21 = F_10 ( V_15 , V_17 , V_18 , V_37 , & V_9 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_15 , V_17 , V_18 , V_37 + 1 , & V_10 ) ;
if ( V_21 ) {
F_17 ( V_15 , & V_9 ) ;
return V_21 ;
}
F_19 ( V_15 , V_18 , & V_9 , & V_10 ) ;
V_21 = F_17 ( V_15 , & V_9 ) ;
if ( V_21 ) {
F_17 ( V_15 , & V_10 ) ;
return V_21 ;
}
return F_17 ( V_15 , & V_10 ) ;
}
static void F_23 ( struct V_14 * V_15 , struct V_1 * V_18 ,
struct V_19 * V_31 , struct V_19 * V_27 , struct V_19 * V_21 ,
struct V_1 * V_9 , struct V_1 * V_38 , struct V_1 * V_10 ,
T_1 V_11 , T_1 V_39 , T_1 V_29 )
{
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
unsigned V_3 = F_24 ( V_8 - V_11 , V_39 ) ;
F_3 ( V_11 + V_3 > V_8 ) ;
F_6 ( V_9 , V_38 , - V_3 ) ;
V_9 -> V_5 . V_4 = F_8 ( V_11 + V_3 ) ;
if ( V_3 != V_39 ) {
V_3 = V_39 - V_3 ;
F_3 ( ( V_29 + V_3 ) > V_8 ) ;
F_1 ( V_10 , V_3 ) ;
F_6 ( V_38 , V_10 , V_3 ) ;
V_10 -> V_5 . V_4 = F_8 ( V_29 + V_3 ) ;
}
* F_4 ( V_18 , V_21 -> V_12 ) = V_10 -> V_34 [ 0 ] ;
F_7 ( V_18 , V_27 -> V_12 ) ;
V_21 -> V_12 -- ;
F_20 ( V_15 -> V_24 , F_16 ( V_27 -> V_26 ) ) ;
F_19 ( V_15 , V_18 , V_31 , V_21 ) ;
}
static void F_25 ( struct V_14 * V_15 , struct V_1 * V_18 ,
struct V_19 * V_31 , struct V_19 * V_27 , struct V_19 * V_21 ,
struct V_1 * V_9 , struct V_1 * V_38 , struct V_1 * V_10 ,
T_1 V_11 , T_1 V_39 , T_1 V_29 )
{
int V_36 ;
T_1 V_8 = F_2 ( V_9 -> V_5 . V_8 ) ;
unsigned V_40 = ( V_11 + V_39 + V_29 ) / 3 ;
F_3 ( V_40 > V_8 ) ;
if ( V_11 < V_29 ) {
V_36 = V_11 - V_40 ;
if ( V_36 < 0 && V_39 < - V_36 ) {
V_3 ( V_9 , V_38 , V_39 ) ;
V_36 = V_39 - V_40 ;
V_3 ( V_9 , V_10 , V_36 ) ;
V_29 += V_36 ;
} else
V_3 ( V_9 , V_38 , V_36 ) ;
V_3 ( V_38 , V_10 , V_40 - V_29 ) ;
} else {
V_36 = V_40 - V_29 ;
if ( V_36 > 0 && V_39 < V_36 ) {
V_3 ( V_38 , V_10 , V_39 ) ;
V_36 = V_40 - V_39 ;
V_3 ( V_9 , V_10 , V_36 ) ;
V_11 -= V_36 ;
} else
V_3 ( V_38 , V_10 , V_36 ) ;
V_3 ( V_9 , V_38 , V_11 - V_40 ) ;
}
* F_4 ( V_18 , V_27 -> V_12 ) = V_38 -> V_34 [ 0 ] ;
* F_4 ( V_18 , V_21 -> V_12 ) = V_10 -> V_34 [ 0 ] ;
}
static void F_26 ( struct V_14 * V_15 , struct V_1 * V_18 ,
struct V_19 * V_31 , struct V_19 * V_27 , struct V_19 * V_21 )
{
struct V_1 * V_9 = V_31 -> V_2 ;
struct V_1 * V_38 = V_27 -> V_2 ;
struct V_1 * V_10 = V_21 -> V_2 ;
T_1 V_11 = F_2 ( V_9 -> V_5 . V_4 ) ;
T_1 V_39 = F_2 ( V_38 -> V_5 . V_4 ) ;
T_1 V_29 = F_2 ( V_10 -> V_5 . V_4 ) ;
unsigned V_32 = F_9 ( V_9 ) * 4 + 1 ;
F_3 ( V_9 -> V_5 . V_8 != V_38 -> V_5 . V_8 ) ;
F_3 ( V_38 -> V_5 . V_8 != V_10 -> V_5 . V_8 ) ;
if ( ( V_11 + V_39 + V_29 ) < V_32 )
F_23 ( V_15 , V_18 , V_31 , V_27 , V_21 , V_9 , V_38 , V_10 ,
V_11 , V_39 , V_29 ) ;
else
F_25 ( V_15 , V_18 , V_31 , V_27 , V_21 , V_9 , V_38 , V_10 ,
V_11 , V_39 , V_29 ) ;
}
static int F_27 ( struct V_35 * V_36 , struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned V_37 )
{
int V_21 ;
struct V_1 * V_18 = F_13 ( F_22 ( V_36 ) ) ;
struct V_19 V_9 , V_38 , V_10 ;
V_21 = F_10 ( V_15 , V_17 , V_18 , V_37 , & V_9 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_15 , V_17 , V_18 , V_37 + 1 , & V_38 ) ;
if ( V_21 ) {
F_17 ( V_15 , & V_9 ) ;
return V_21 ;
}
V_21 = F_10 ( V_15 , V_17 , V_18 , V_37 + 2 , & V_10 ) ;
if ( V_21 ) {
F_17 ( V_15 , & V_9 ) ;
F_17 ( V_15 , & V_38 ) ;
return V_21 ;
}
F_26 ( V_15 , V_18 , & V_9 , & V_38 , & V_10 ) ;
V_21 = F_17 ( V_15 , & V_9 ) ;
if ( V_21 ) {
F_17 ( V_15 , & V_38 ) ;
F_17 ( V_15 , & V_10 ) ;
return V_21 ;
}
V_21 = F_17 ( V_15 , & V_38 ) ;
if ( V_21 ) {
F_17 ( V_15 , & V_10 ) ;
return V_21 ;
}
V_21 = F_17 ( V_15 , & V_10 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_28 ( struct V_41 * V_24 ,
T_2 V_42 , T_1 * V_20 )
{
int V_21 ;
struct V_43 * V_26 ;
struct V_1 * V_2 ;
V_21 = F_29 ( V_24 , V_42 , & V_25 , & V_26 ) ;
if ( V_21 )
return V_21 ;
V_2 = F_13 ( V_26 ) ;
* V_20 = F_2 ( V_2 -> V_5 . V_4 ) ;
return F_18 ( V_24 , V_26 ) ;
}
static int F_30 ( struct V_35 * V_36 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , T_3 V_44 )
{
int V_45 , V_21 , V_46 , V_47 ;
T_1 V_48 ;
struct V_1 * V_2 ;
V_2 = F_13 ( F_22 ( V_36 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_4 ) == 1 ) {
struct V_43 * V_19 ;
T_2 V_42 = F_11 ( V_2 , 0 ) ;
V_21 = F_29 ( V_15 -> V_24 , V_42 , & V_25 , & V_19 ) ;
if ( V_21 )
return V_21 ;
memcpy ( V_2 , F_13 ( V_19 ) ,
F_31 ( F_32 ( V_15 -> V_24 ) ) ) ;
V_21 = F_18 ( V_15 -> V_24 , V_19 ) ;
if ( V_21 )
return V_21 ;
F_20 ( V_15 -> V_24 , F_16 ( V_19 ) ) ;
return 0 ;
}
V_45 = F_33 ( V_2 , V_44 ) ;
if ( V_45 < 0 )
return - V_49 ;
V_21 = F_28 ( V_15 -> V_24 , F_11 ( V_2 , V_45 ) , & V_48 ) ;
if ( V_21 )
return V_21 ;
V_46 = V_45 > 0 ;
V_47 = V_45 < ( F_2 ( V_2 -> V_5 . V_4 ) - 1 ) ;
if ( ! V_46 )
V_21 = F_21 ( V_36 , V_15 , V_17 , V_45 ) ;
else if ( ! V_47 )
V_21 = F_21 ( V_36 , V_15 , V_17 , V_45 - 1 ) ;
else
V_21 = F_27 ( V_36 , V_15 , V_17 , V_45 - 1 ) ;
return V_21 ;
}
static int F_34 ( struct V_1 * V_2 , T_3 V_44 , unsigned * V_12 )
{
int V_45 = F_33 ( V_2 , V_44 ) ;
if ( ( V_45 < 0 ) ||
( V_45 >= F_2 ( V_2 -> V_5 . V_4 ) ) ||
( F_35 ( V_2 -> V_34 [ V_45 ] ) != V_44 ) )
return - V_49 ;
* V_12 = V_45 ;
return 0 ;
}
static int F_36 ( struct V_35 * V_36 , struct V_14 * V_15 ,
struct V_16 * V_17 , T_2 V_23 ,
T_3 V_44 , unsigned * V_12 )
{
int V_45 = * V_12 , V_21 ;
struct V_1 * V_2 ;
for (; ; ) {
V_21 = F_37 ( V_36 , V_23 , V_17 ) ;
if ( V_21 < 0 )
break;
if ( F_38 ( V_36 ) ) {
V_7 V_50 = F_15 ( F_16 ( F_22 ( V_36 ) ) ) ;
memcpy ( F_5 ( F_13 ( F_39 ( V_36 ) ) , V_45 ) ,
& V_50 , sizeof( V_7 ) ) ;
}
V_2 = F_13 ( F_22 ( V_36 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_51 ) & V_52 )
return F_34 ( V_2 , V_44 , V_12 ) ;
V_21 = F_30 ( V_36 , V_15 , V_17 , V_44 ) ;
if ( V_21 )
break;
V_2 = F_13 ( F_22 ( V_36 ) ) ;
if ( F_2 ( V_2 -> V_5 . V_51 ) & V_52 )
return F_34 ( V_2 , V_44 , V_12 ) ;
V_45 = F_33 ( V_2 , V_44 ) ;
V_23 = F_11 ( V_2 , V_45 ) ;
}
return V_21 ;
}
int F_40 ( struct V_14 * V_15 , T_2 V_23 ,
T_3 * V_34 , T_2 * V_53 )
{
unsigned V_54 , V_55 = V_15 -> V_56 - 1 ;
int V_12 = 0 , V_21 = 0 ;
struct V_35 V_57 ;
struct V_1 * V_2 ;
F_41 ( & V_57 , V_15 ) ;
for ( V_54 = 0 ; V_54 < V_15 -> V_56 ; V_54 ++ ) {
V_21 = F_36 ( & V_57 , V_15 ,
( V_54 == V_55 ?
& V_15 -> V_58 : & V_59 ) ,
V_23 , V_34 [ V_54 ] , ( unsigned * ) & V_12 ) ;
if ( V_21 < 0 )
break;
V_2 = F_13 ( F_22 ( & V_57 ) ) ;
if ( V_54 != V_55 ) {
V_23 = F_11 ( V_2 , V_12 ) ;
continue;
}
F_3 ( V_12 < 0 || V_12 >= F_2 ( V_2 -> V_5 . V_4 ) ) ;
if ( V_15 -> V_58 . V_60 )
V_15 -> V_58 . V_60 ( V_15 -> V_58 . V_61 ,
F_5 ( V_2 , V_12 ) ) ;
F_7 ( V_2 , V_12 ) ;
}
* V_53 = F_42 ( & V_57 ) ;
F_43 ( & V_57 ) ;
return V_21 ;
}
