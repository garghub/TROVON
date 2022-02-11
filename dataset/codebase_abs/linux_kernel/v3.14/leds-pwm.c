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
V_2 -> V_4 = V_4 ;
if ( V_2 -> V_16 )
F_9 ( & V_2 -> V_8 ) ;
else
F_1 ( V_2 ) ;
}
static inline T_1 F_10 ( int V_17 )
{
return sizeof( struct V_18 ) +
( sizeof( struct V_1 ) * V_17 ) ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_18 * V_21 )
{
struct V_22 * V_23 ;
int V_24 ;
F_12 (pdev->dev.of_node, child) {
struct V_1 * V_2 = & V_21 -> V_25 [ V_21 -> V_17 ] ;
V_2 -> V_13 . V_26 = F_13 ( V_23 , L_1 ,
NULL ) ? : V_23 -> V_26 ;
V_2 -> V_5 = F_14 ( & V_20 -> V_27 , V_23 , NULL ) ;
if ( F_15 ( V_2 -> V_5 ) ) {
F_16 ( & V_20 -> V_27 , L_2 ,
V_2 -> V_13 . V_26 ) ;
V_24 = F_17 ( V_2 -> V_5 ) ;
goto V_28;
}
V_2 -> V_6 = F_18 ( V_2 -> V_5 ) ;
V_2 -> V_13 . V_29 = F_13 ( V_23 ,
L_3 , NULL ) ;
F_19 ( V_23 , L_4 ,
& V_2 -> V_13 . V_15 ) ;
V_2 -> V_13 . V_30 = F_7 ;
V_2 -> V_13 . V_12 = V_31 ;
V_2 -> V_13 . V_32 |= V_33 ;
V_2 -> V_16 = F_20 ( V_2 -> V_5 ) ;
if ( V_2 -> V_16 )
F_21 ( & V_2 -> V_8 , F_5 ) ;
V_24 = F_22 ( & V_20 -> V_27 , & V_2 -> V_13 ) ;
if ( V_24 < 0 ) {
F_16 ( & V_20 -> V_27 , L_5 ,
V_2 -> V_13 . V_26 ) ;
F_23 ( V_23 ) ;
goto V_28;
}
V_21 -> V_17 ++ ;
}
return 0 ;
V_28:
while ( V_21 -> V_17 -- )
F_24 ( & V_21 -> V_25 [ V_21 -> V_17 ] . V_13 ) ;
return V_24 ;
}
static int F_25 ( struct V_19 * V_20 )
{
struct V_34 * V_35 = F_26 ( & V_20 -> V_27 ) ;
struct V_18 * V_21 ;
int V_36 , V_37 ;
int V_24 = 0 ;
if ( V_35 )
V_36 = V_35 -> V_17 ;
else
V_36 = F_27 ( V_20 -> V_27 . V_38 ) ;
if ( ! V_36 )
return - V_39 ;
V_21 = F_28 ( & V_20 -> V_27 , F_10 ( V_36 ) ,
V_40 ) ;
if ( ! V_21 )
return - V_41 ;
if ( V_35 ) {
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
struct V_42 * V_43 = & V_35 -> V_25 [ V_37 ] ;
struct V_1 * V_2 = & V_21 -> V_25 [ V_37 ] ;
V_2 -> V_5 = F_29 ( & V_20 -> V_27 , V_43 -> V_26 ) ;
if ( F_15 ( V_2 -> V_5 ) ) {
V_24 = F_17 ( V_2 -> V_5 ) ;
F_16 ( & V_20 -> V_27 ,
L_2 ,
V_43 -> V_26 ) ;
goto V_28;
}
V_2 -> V_13 . V_26 = V_43 -> V_26 ;
V_2 -> V_13 . V_29 = V_43 -> V_29 ;
V_2 -> V_44 = V_43 -> V_44 ;
V_2 -> V_6 = V_43 -> V_45 ;
V_2 -> V_13 . V_30 = F_7 ;
V_2 -> V_13 . V_12 = V_31 ;
V_2 -> V_13 . V_15 = V_43 -> V_15 ;
V_2 -> V_13 . V_32 |= V_33 ;
V_2 -> V_16 = F_20 ( V_2 -> V_5 ) ;
if ( V_2 -> V_16 )
F_21 ( & V_2 -> V_8 , F_5 ) ;
V_24 = F_22 ( & V_20 -> V_27 , & V_2 -> V_13 ) ;
if ( V_24 < 0 )
goto V_28;
}
V_21 -> V_17 = V_36 ;
} else {
V_24 = F_11 ( V_20 , V_21 ) ;
if ( V_24 )
return V_24 ;
}
F_30 ( V_20 , V_21 ) ;
return 0 ;
V_28:
while ( V_37 -- )
F_24 ( & V_21 -> V_25 [ V_37 ] . V_13 ) ;
return V_24 ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_18 * V_21 = F_32 ( V_20 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_21 -> V_17 ; V_37 ++ ) {
F_24 ( & V_21 -> V_25 [ V_37 ] . V_13 ) ;
if ( V_21 -> V_25 [ V_37 ] . V_16 )
F_33 ( & V_21 -> V_25 [ V_37 ] . V_8 ) ;
}
return 0 ;
}
