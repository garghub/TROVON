static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 , V_3 , V_2 -> V_6 ) ;
if ( V_3 == 0 )
F_3 ( V_2 -> V_5 ) ;
else
F_4 ( V_2 -> V_5 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_6 ( V_8 , struct V_1 , V_8 ) ;
F_1 ( V_2 ) ;
}
static void F_7 ( struct V_9 * V_10 ,
enum V_11 V_12 )
{
struct V_1 * V_2 =
F_6 ( V_10 , struct V_1 , V_13 ) ;
unsigned int V_14 = V_2 -> V_13 . V_15 ;
unsigned long long V_4 = V_2 -> V_6 ;
V_4 *= V_12 ;
F_8 ( V_4 , V_14 ) ;
if ( V_2 -> V_16 )
V_4 = V_2 -> V_6 - V_4 ;
V_2 -> V_4 = V_4 ;
if ( V_2 -> V_17 )
F_9 ( & V_2 -> V_8 ) ;
else
F_1 ( V_2 ) ;
}
static inline T_1 F_10 ( int V_18 )
{
return sizeof( struct V_19 ) +
( sizeof( struct V_1 ) * V_18 ) ;
}
static void F_11 ( struct V_19 * V_20 )
{
while ( V_20 -> V_18 -- ) {
F_12 ( & V_20 -> V_21 [ V_20 -> V_18 ] . V_13 ) ;
if ( V_20 -> V_21 [ V_20 -> V_18 ] . V_17 )
F_13 ( & V_20 -> V_21 [ V_20 -> V_18 ] . V_8 ) ;
}
}
static int F_14 ( struct V_22 * V_23 , struct V_19 * V_20 ,
struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_1 * V_28 = & V_20 -> V_21 [ V_20 -> V_18 ] ;
int V_29 ;
V_28 -> V_16 = V_25 -> V_16 ;
V_28 -> V_13 . V_30 = V_25 -> V_30 ;
V_28 -> V_13 . V_31 = V_25 -> V_31 ;
V_28 -> V_13 . V_32 = F_7 ;
V_28 -> V_13 . V_12 = V_33 ;
V_28 -> V_13 . V_15 = V_25 -> V_15 ;
V_28 -> V_13 . V_34 = V_35 ;
if ( V_27 )
V_28 -> V_5 = F_15 ( V_23 , V_27 , NULL ) ;
else
V_28 -> V_5 = F_16 ( V_23 , V_25 -> V_30 ) ;
if ( F_17 ( V_28 -> V_5 ) ) {
V_29 = F_18 ( V_28 -> V_5 ) ;
F_19 ( V_23 , L_1 ,
V_25 -> V_30 , V_29 ) ;
return V_29 ;
}
V_28 -> V_17 = F_20 ( V_28 -> V_5 ) ;
if ( V_28 -> V_17 )
F_21 ( & V_28 -> V_8 , F_5 ) ;
V_28 -> V_6 = F_22 ( V_28 -> V_5 ) ;
if ( ! V_28 -> V_6 && ( V_25 -> V_36 > 0 ) )
V_28 -> V_6 = V_25 -> V_36 ;
V_29 = F_23 ( V_23 , & V_28 -> V_13 ) ;
if ( V_29 == 0 ) {
V_20 -> V_18 ++ ;
} else {
F_19 ( V_23 , L_2 ,
V_25 -> V_30 , V_29 ) ;
}
return V_29 ;
}
static int F_24 ( struct V_22 * V_23 , struct V_19 * V_20 )
{
struct V_26 * V_27 ;
struct V_24 V_25 ;
int V_29 = 0 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_25 (dev->of_node, child) {
V_25 . V_30 = F_26 ( V_27 , L_3 , NULL ) ? :
V_27 -> V_30 ;
V_25 . V_31 = F_26 ( V_27 ,
L_4 , NULL ) ;
V_25 . V_16 = F_27 ( V_27 , L_5 ) ;
F_28 ( V_27 , L_6 ,
& V_25 . V_15 ) ;
V_29 = F_14 ( V_23 , V_20 , & V_25 , V_27 ) ;
if ( V_29 ) {
F_29 ( V_27 ) ;
break;
}
}
return V_29 ;
}
static int F_30 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_31 ( & V_38 -> V_23 ) ;
struct V_19 * V_20 ;
int V_41 , V_42 ;
int V_29 = 0 ;
if ( V_40 )
V_41 = V_40 -> V_18 ;
else
V_41 = F_32 ( V_38 -> V_23 . V_43 ) ;
if ( ! V_41 )
return - V_44 ;
V_20 = F_33 ( & V_38 -> V_23 , F_10 ( V_41 ) ,
V_45 ) ;
if ( ! V_20 )
return - V_46 ;
if ( V_40 ) {
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
V_29 = F_14 ( & V_38 -> V_23 , V_20 , & V_40 -> V_21 [ V_42 ] ,
NULL ) ;
if ( V_29 )
break;
}
} else {
V_29 = F_24 ( & V_38 -> V_23 , V_20 ) ;
}
if ( V_29 ) {
F_11 ( V_20 ) ;
return V_29 ;
}
F_34 ( V_38 , V_20 ) ;
return 0 ;
}
static int F_35 ( struct V_37 * V_38 )
{
struct V_19 * V_20 = F_36 ( V_38 ) ;
F_11 ( V_20 ) ;
return 0 ;
}
