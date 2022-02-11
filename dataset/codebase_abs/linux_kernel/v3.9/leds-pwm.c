static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
unsigned int V_8 = V_6 -> V_7 . V_9 ;
unsigned int V_10 = V_6 -> V_10 ;
if ( V_4 == 0 ) {
F_3 ( V_6 -> V_11 , 0 , V_10 ) ;
F_4 ( V_6 -> V_11 ) ;
} else {
F_3 ( V_6 -> V_11 , V_4 * V_10 / V_8 , V_10 ) ;
F_5 ( V_6 -> V_11 ) ;
}
}
static inline T_1 F_6 ( int V_12 )
{
return sizeof( struct V_13 ) +
( sizeof( struct V_5 ) * V_12 ) ;
}
static struct V_13 * F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
struct V_16 * V_20 ;
struct V_13 * V_21 ;
int V_22 , V_23 ;
V_22 = F_8 ( V_17 ) ;
if ( ! V_22 )
return NULL ;
V_21 = F_9 ( & V_15 -> V_18 , F_6 ( V_22 ) ,
V_24 ) ;
if ( ! V_21 )
return NULL ;
F_10 (node, child) {
struct V_5 * V_6 = & V_21 -> V_25 [ V_21 -> V_12 ] ;
V_6 -> V_7 . V_26 = F_11 ( V_20 , L_1 ,
NULL ) ? : V_20 -> V_26 ;
V_6 -> V_11 = F_12 ( & V_15 -> V_18 , V_20 , NULL ) ;
if ( F_13 ( V_6 -> V_11 ) ) {
F_14 ( & V_15 -> V_18 , L_2 ,
V_6 -> V_7 . V_26 ) ;
goto V_27;
}
V_6 -> V_10 = F_15 ( V_6 -> V_11 ) ;
V_6 -> V_7 . V_28 = F_11 ( V_20 ,
L_3 , NULL ) ;
F_16 ( V_20 , L_4 ,
& V_6 -> V_7 . V_9 ) ;
V_6 -> V_7 . V_29 = F_1 ;
V_6 -> V_7 . V_4 = V_30 ;
V_6 -> V_7 . V_31 |= V_32 ;
V_23 = F_17 ( & V_15 -> V_18 , & V_6 -> V_7 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_15 -> V_18 , L_5 ,
V_6 -> V_7 . V_26 ) ;
F_18 ( V_20 ) ;
goto V_27;
}
V_21 -> V_12 ++ ;
}
return V_21 ;
V_27:
while ( V_21 -> V_12 -- )
F_19 ( & V_21 -> V_25 [ V_21 -> V_12 ] . V_7 ) ;
return NULL ;
}
static int F_20 ( struct V_14 * V_15 )
{
struct V_33 * V_34 = V_15 -> V_18 . V_35 ;
struct V_13 * V_21 ;
int V_36 , V_23 = 0 ;
if ( V_34 && V_34 -> V_12 ) {
V_21 = F_9 ( & V_15 -> V_18 ,
F_6 ( V_34 -> V_12 ) ,
V_24 ) ;
if ( ! V_21 )
return - V_37 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_12 ; V_36 ++ ) {
struct V_38 * V_39 = & V_34 -> V_25 [ V_36 ] ;
struct V_5 * V_6 = & V_21 -> V_25 [ V_36 ] ;
V_6 -> V_11 = F_21 ( & V_15 -> V_18 , V_39 -> V_26 ) ;
if ( F_13 ( V_6 -> V_11 ) ) {
V_23 = F_22 ( V_6 -> V_11 ) ;
F_14 ( & V_15 -> V_18 ,
L_2 ,
V_39 -> V_26 ) ;
goto V_27;
}
V_6 -> V_7 . V_26 = V_39 -> V_26 ;
V_6 -> V_7 . V_28 = V_39 -> V_28 ;
V_6 -> V_40 = V_39 -> V_40 ;
V_6 -> V_10 = V_39 -> V_41 ;
V_6 -> V_7 . V_29 = F_1 ;
V_6 -> V_7 . V_4 = V_30 ;
V_6 -> V_7 . V_9 = V_39 -> V_9 ;
V_6 -> V_7 . V_31 |= V_32 ;
V_23 = F_17 ( & V_15 -> V_18 , & V_6 -> V_7 ) ;
if ( V_23 < 0 )
goto V_27;
}
V_21 -> V_12 = V_34 -> V_12 ;
} else {
V_21 = F_7 ( V_15 ) ;
if ( ! V_21 )
return - V_42 ;
}
F_23 ( V_15 , V_21 ) ;
return 0 ;
V_27:
while ( V_36 -- )
F_19 ( & V_21 -> V_25 [ V_36 ] . V_7 ) ;
return V_23 ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_13 * V_21 = F_25 ( V_15 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_12 ; V_36 ++ )
F_19 ( & V_21 -> V_25 [ V_36 ] . V_7 ) ;
return 0 ;
}
