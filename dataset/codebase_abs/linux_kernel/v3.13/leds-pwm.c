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
static int F_10 ( struct V_19 * V_20 ,
struct V_18 * V_21 )
{
struct V_22 * V_23 = V_20 -> V_24 . V_25 ;
struct V_22 * V_26 ;
int V_27 ;
F_11 (node, child) {
struct V_1 * V_2 = & V_21 -> V_28 [ V_21 -> V_17 ] ;
V_2 -> V_13 . V_29 = F_12 ( V_26 , L_1 ,
NULL ) ? : V_26 -> V_29 ;
V_2 -> V_5 = F_13 ( & V_20 -> V_24 , V_26 , NULL ) ;
if ( F_14 ( V_2 -> V_5 ) ) {
F_15 ( & V_20 -> V_24 , L_2 ,
V_2 -> V_13 . V_29 ) ;
V_27 = F_16 ( V_2 -> V_5 ) ;
goto V_30;
}
V_2 -> V_6 = F_17 ( V_2 -> V_5 ) ;
V_2 -> V_13 . V_31 = F_12 ( V_26 ,
L_3 , NULL ) ;
F_18 ( V_26 , L_4 ,
& V_2 -> V_13 . V_15 ) ;
V_2 -> V_13 . V_32 = F_7 ;
V_2 -> V_13 . V_12 = V_33 ;
V_2 -> V_13 . V_34 |= V_35 ;
V_2 -> V_16 = F_19 ( V_2 -> V_5 ) ;
if ( V_2 -> V_16 )
F_20 ( & V_2 -> V_8 , F_5 ) ;
V_27 = F_21 ( & V_20 -> V_24 , & V_2 -> V_13 ) ;
if ( V_27 < 0 ) {
F_15 ( & V_20 -> V_24 , L_5 ,
V_2 -> V_13 . V_29 ) ;
F_22 ( V_26 ) ;
goto V_30;
}
V_21 -> V_17 ++ ;
}
return 0 ;
V_30:
while ( V_21 -> V_17 -- )
F_23 ( & V_21 -> V_28 [ V_21 -> V_17 ] . V_13 ) ;
return V_27 ;
}
static int F_24 ( struct V_19 * V_20 )
{
struct V_36 * V_37 = F_25 ( & V_20 -> V_24 ) ;
struct V_18 * V_21 ;
int V_38 , V_39 ;
int V_27 = 0 ;
if ( V_37 )
V_38 = V_37 -> V_17 ;
else
V_38 = F_26 ( V_20 -> V_24 . V_25 ) ;
if ( ! V_38 )
return - V_40 ;
V_21 = F_27 ( & V_20 -> V_24 , F_9 ( V_38 ) ,
V_41 ) ;
if ( ! V_21 )
return - V_42 ;
if ( V_37 ) {
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
struct V_43 * V_44 = & V_37 -> V_28 [ V_39 ] ;
struct V_1 * V_2 = & V_21 -> V_28 [ V_39 ] ;
V_2 -> V_5 = F_28 ( & V_20 -> V_24 , V_44 -> V_29 ) ;
if ( F_14 ( V_2 -> V_5 ) ) {
V_27 = F_16 ( V_2 -> V_5 ) ;
F_15 ( & V_20 -> V_24 ,
L_2 ,
V_44 -> V_29 ) ;
goto V_30;
}
V_2 -> V_13 . V_29 = V_44 -> V_29 ;
V_2 -> V_13 . V_31 = V_44 -> V_31 ;
V_2 -> V_45 = V_44 -> V_45 ;
V_2 -> V_6 = V_44 -> V_46 ;
V_2 -> V_13 . V_32 = F_7 ;
V_2 -> V_13 . V_12 = V_33 ;
V_2 -> V_13 . V_15 = V_44 -> V_15 ;
V_2 -> V_13 . V_34 |= V_35 ;
V_2 -> V_16 = F_19 ( V_2 -> V_5 ) ;
if ( V_2 -> V_16 )
F_20 ( & V_2 -> V_8 , F_5 ) ;
V_27 = F_21 ( & V_20 -> V_24 , & V_2 -> V_13 ) ;
if ( V_27 < 0 )
goto V_30;
}
V_21 -> V_17 = V_38 ;
} else {
V_27 = F_10 ( V_20 , V_21 ) ;
if ( V_27 )
return V_27 ;
}
F_29 ( V_20 , V_21 ) ;
return 0 ;
V_30:
while ( V_39 -- )
F_23 ( & V_21 -> V_28 [ V_39 ] . V_13 ) ;
return V_27 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_18 * V_21 = F_31 ( V_20 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_21 -> V_17 ; V_39 ++ ) {
F_23 ( & V_21 -> V_28 [ V_39 ] . V_13 ) ;
if ( V_21 -> V_28 [ V_39 ] . V_16 )
F_32 ( & V_21 -> V_28 [ V_39 ] . V_8 ) ;
}
return 0 ;
}
