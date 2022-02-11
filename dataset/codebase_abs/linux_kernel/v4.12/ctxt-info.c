static int F_1 ( const struct V_1 * V_2 ,
int V_3 )
{
int V_4 = 0 ;
while ( V_3 < V_2 -> V_5 &&
V_2 -> V_6 [ V_3 ] . V_7 != V_8 &&
V_2 -> V_6 [ V_3 ] . V_7 != V_9 ) {
V_3 ++ ;
V_4 ++ ;
}
return V_4 ;
}
static int F_2 ( struct V_10 * V_11 ,
const struct V_12 * V_6 ,
struct V_13 * V_14 )
{
V_14 -> V_15 = F_3 ( V_11 -> V_16 , V_6 -> V_17 ,
& V_14 -> V_18 ,
V_19 ) ;
if ( ! V_14 -> V_15 )
return - V_20 ;
V_14 -> V_21 = V_6 -> V_17 ;
memcpy ( V_14 -> V_15 , V_6 -> V_22 , V_6 -> V_17 ) ;
return 0 ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = F_5 ( V_11 ) ;
struct V_25 * V_14 = & V_24 -> V_26 ;
int V_4 ;
if ( ! V_14 -> V_2 ) {
F_6 ( V_14 -> V_27 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_14 -> V_27 ; V_4 ++ )
F_7 ( V_11 -> V_16 , V_14 -> V_2 [ V_4 ] . V_21 ,
V_14 -> V_2 [ V_4 ] . V_15 , V_14 -> V_2 [ V_4 ] . V_18 ) ;
F_8 ( V_14 -> V_2 ) ;
V_14 -> V_27 = 0 ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = F_5 ( V_11 ) ;
struct V_25 * V_14 = & V_24 -> V_26 ;
int V_4 ;
if ( ! V_14 -> V_28 ) {
F_6 ( V_14 -> V_29 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_14 -> V_29 ; V_4 ++ )
F_7 ( V_11 -> V_16 , V_14 -> V_28 [ V_4 ] . V_21 ,
V_14 -> V_28 [ V_4 ] . V_15 ,
V_14 -> V_28 [ V_4 ] . V_18 ) ;
F_8 ( V_14 -> V_28 ) ;
V_14 -> V_29 = 0 ;
}
static int F_10 ( struct V_10 * V_11 ,
const struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_23 * V_24 = F_5 ( V_11 ) ;
struct V_25 * V_14 = & V_24 -> V_26 ;
struct V_32 * V_33 = & V_31 -> V_14 ;
int V_4 , V_34 , V_35 , V_36 , V_29 ;
V_35 = F_1 ( V_2 , 0 ) ;
V_36 = F_1 ( V_2 , V_35 + 1 ) ;
V_29 = F_1 ( V_2 , V_35 + V_36 + 2 ) ;
V_14 -> V_2 = F_11 ( V_36 + V_35 , sizeof( * V_14 -> V_2 ) , V_19 ) ;
if ( ! V_14 -> V_2 )
return - V_20 ;
V_14 -> V_28 = F_11 ( V_29 , sizeof( * V_14 -> V_28 ) , V_19 ) ;
if ( ! V_14 -> V_28 )
return - V_20 ;
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ ) {
V_34 = F_2 ( V_11 , & V_2 -> V_6 [ V_4 ] ,
& V_14 -> V_2 [ V_14 -> V_27 ] ) ;
if ( V_34 )
return V_34 ;
V_33 -> V_37 [ V_4 ] =
F_12 ( V_14 -> V_2 [ V_14 -> V_27 ] . V_18 ) ;
V_14 -> V_27 ++ ;
}
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
V_34 = F_2 ( V_11 ,
& V_2 -> V_6 [ V_14 -> V_27 + 1 ] ,
& V_14 -> V_2 [ V_14 -> V_27 ] ) ;
if ( V_34 )
return V_34 ;
V_33 -> V_38 [ V_4 ] =
F_12 ( V_14 -> V_2 [ V_14 -> V_27 ] . V_18 ) ;
V_14 -> V_27 ++ ;
}
for ( V_4 = 0 ; V_4 < V_29 ; V_4 ++ ) {
int V_39 = V_14 -> V_27 + V_4 + 2 ;
V_34 = F_2 ( V_11 , & V_2 -> V_6 [ V_39 ] ,
& V_14 -> V_28 [ V_4 ] ) ;
if ( V_34 )
return V_34 ;
V_33 -> V_40 [ V_4 ] =
F_12 ( V_14 -> V_28 [ V_4 ] . V_18 ) ;
V_14 -> V_29 ++ ;
}
return 0 ;
}
int F_13 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_23 * V_24 = F_5 ( V_11 ) ;
struct V_30 * V_31 ;
struct V_41 * V_42 ;
T_1 V_43 = 0 ;
int V_34 ;
V_31 = F_3 ( V_11 -> V_16 , sizeof( * V_31 ) ,
& V_24 -> V_44 ,
V_19 ) ;
if ( ! V_31 )
return - V_20 ;
V_31 -> V_45 . V_45 = 0 ;
V_31 -> V_45 . V_46 =
F_14 ( ( V_47 ) F_15 ( V_11 , V_48 ) ) ;
V_31 -> V_45 . V_21 = F_14 ( sizeof( * V_31 ) / 4 ) ;
F_16 ( F_17 ( V_49 ) > 0xF ) ;
V_43 = V_50 |
V_51 |
F_17 ( V_49 ) <<
V_52 ;
V_31 -> V_53 . V_43 = F_18 ( V_43 ) ;
V_42 = & V_31 -> V_54 ;
V_42 -> V_55 = F_12 ( V_24 -> V_56 -> V_57 ) ;
V_42 -> V_58 = F_12 ( V_24 -> V_56 -> V_59 ) ;
V_42 -> V_60 = F_12 ( V_24 -> V_56 -> V_61 ) ;
V_31 -> V_62 . V_63 =
F_12 ( V_24 -> V_64 [ V_24 -> V_65 ] -> V_66 ) ;
V_31 -> V_62 . V_67 =
F_19 ( V_68 ) ;
V_34 = F_10 ( V_11 , V_2 , V_31 ) ;
if ( V_34 ) {
F_7 ( V_11 -> V_16 , sizeof( * V_24 -> V_31 ) ,
V_31 , V_24 -> V_44 ) ;
return V_34 ;
}
V_24 -> V_31 = V_31 ;
F_20 ( V_11 ) ;
if ( V_11 -> V_69 )
F_21 ( V_11 ) ;
F_22 ( V_11 , V_70 , V_24 -> V_44 ) ;
F_23 ( V_11 , V_71 , 1 ) ;
return 0 ;
}
void F_24 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = F_5 ( V_11 ) ;
if ( ! V_24 -> V_31 )
return;
F_7 ( V_11 -> V_16 , sizeof( * V_24 -> V_31 ) ,
V_24 -> V_31 ,
V_24 -> V_44 ) ;
V_24 -> V_44 = 0 ;
V_24 -> V_31 = NULL ;
F_4 ( V_11 ) ;
}
