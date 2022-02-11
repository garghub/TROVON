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
unsigned int V_6 = V_2 -> V_6 ;
V_2 -> V_4 = V_12 * V_6 / V_14 ;
if ( V_2 -> V_16 )
F_8 ( & V_2 -> V_8 ) ;
else
F_1 ( V_2 ) ;
}
static inline T_1 F_9 ( int V_17 )
{
return sizeof( struct V_18 ) +
( sizeof( struct V_1 ) * V_17 ) ;
}
static struct V_18 * F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_24 ;
struct V_21 * V_25 ;
struct V_18 * V_26 ;
int V_27 , V_28 ;
V_27 = F_11 ( V_22 ) ;
if ( ! V_27 )
return NULL ;
V_26 = F_12 ( & V_20 -> V_23 , F_9 ( V_27 ) ,
V_29 ) ;
if ( ! V_26 )
return NULL ;
F_13 (node, child) {
struct V_1 * V_2 = & V_26 -> V_30 [ V_26 -> V_17 ] ;
V_2 -> V_13 . V_31 = F_14 ( V_25 , L_1 ,
NULL ) ? : V_25 -> V_31 ;
V_2 -> V_5 = F_15 ( & V_20 -> V_23 , V_25 , NULL ) ;
if ( F_16 ( V_2 -> V_5 ) ) {
F_17 ( & V_20 -> V_23 , L_2 ,
V_2 -> V_13 . V_31 ) ;
goto V_32;
}
V_2 -> V_6 = F_18 ( V_2 -> V_5 ) ;
V_2 -> V_13 . V_33 = F_14 ( V_25 ,
L_3 , NULL ) ;
F_19 ( V_25 , L_4 ,
& V_2 -> V_13 . V_15 ) ;
V_2 -> V_13 . V_34 = F_7 ;
V_2 -> V_13 . V_12 = V_35 ;
V_2 -> V_13 . V_36 |= V_37 ;
V_2 -> V_16 = F_20 ( V_2 -> V_5 ) ;
if ( V_2 -> V_16 )
F_21 ( & V_2 -> V_8 , F_5 ) ;
V_28 = F_22 ( & V_20 -> V_23 , & V_2 -> V_13 ) ;
if ( V_28 < 0 ) {
F_17 ( & V_20 -> V_23 , L_5 ,
V_2 -> V_13 . V_31 ) ;
F_23 ( V_25 ) ;
goto V_32;
}
V_26 -> V_17 ++ ;
}
return V_26 ;
V_32:
while ( V_26 -> V_17 -- )
F_24 ( & V_26 -> V_30 [ V_26 -> V_17 ] . V_13 ) ;
return NULL ;
}
static int F_25 ( struct V_19 * V_20 )
{
struct V_38 * V_39 = F_26 ( & V_20 -> V_23 ) ;
struct V_18 * V_26 ;
int V_40 , V_28 = 0 ;
if ( V_39 && V_39 -> V_17 ) {
V_26 = F_12 ( & V_20 -> V_23 ,
F_9 ( V_39 -> V_17 ) ,
V_29 ) ;
if ( ! V_26 )
return - V_41 ;
for ( V_40 = 0 ; V_40 < V_39 -> V_17 ; V_40 ++ ) {
struct V_42 * V_43 = & V_39 -> V_30 [ V_40 ] ;
struct V_1 * V_2 = & V_26 -> V_30 [ V_40 ] ;
V_2 -> V_5 = F_27 ( & V_20 -> V_23 , V_43 -> V_31 ) ;
if ( F_16 ( V_2 -> V_5 ) ) {
V_28 = F_28 ( V_2 -> V_5 ) ;
F_17 ( & V_20 -> V_23 ,
L_2 ,
V_43 -> V_31 ) ;
goto V_32;
}
V_2 -> V_13 . V_31 = V_43 -> V_31 ;
V_2 -> V_13 . V_33 = V_43 -> V_33 ;
V_2 -> V_44 = V_43 -> V_44 ;
V_2 -> V_6 = V_43 -> V_45 ;
V_2 -> V_13 . V_34 = F_7 ;
V_2 -> V_13 . V_12 = V_35 ;
V_2 -> V_13 . V_15 = V_43 -> V_15 ;
V_2 -> V_13 . V_36 |= V_37 ;
V_2 -> V_16 = F_20 ( V_2 -> V_5 ) ;
if ( V_2 -> V_16 )
F_21 ( & V_2 -> V_8 , F_5 ) ;
V_28 = F_22 ( & V_20 -> V_23 , & V_2 -> V_13 ) ;
if ( V_28 < 0 )
goto V_32;
}
V_26 -> V_17 = V_39 -> V_17 ;
} else {
V_26 = F_10 ( V_20 ) ;
if ( ! V_26 )
return - V_46 ;
}
F_29 ( V_20 , V_26 ) ;
return 0 ;
V_32:
while ( V_40 -- )
F_24 ( & V_26 -> V_30 [ V_40 ] . V_13 ) ;
return V_28 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_18 * V_26 = F_31 ( V_20 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_26 -> V_17 ; V_40 ++ ) {
F_24 ( & V_26 -> V_30 [ V_40 ] . V_13 ) ;
if ( V_26 -> V_30 [ V_40 ] . V_16 )
F_32 ( & V_26 -> V_30 [ V_40 ] . V_8 ) ;
}
return 0 ;
}
