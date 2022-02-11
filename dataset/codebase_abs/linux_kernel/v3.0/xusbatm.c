static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_8 ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_11 -> V_12 . V_13 ; V_9 ++ )
if ( ( V_8 = V_3 -> V_11 -> V_14 [ V_9 ] ) && ( V_7 = F_2 ( V_8 , V_4 ) ) )
for ( V_10 = 0 ; V_10 < V_7 -> V_12 . V_15 ; V_10 ++ )
if ( V_7 -> V_16 [ V_10 ] . V_12 . V_17 == V_5 )
return V_8 ;
return NULL ;
}
static int F_3 ( struct V_18 * V_19 , struct V_2 * V_3 ,
struct V_1 * V_8 , int V_4 , int V_20 )
{
int V_21 = V_8 -> V_4 -> V_12 . V_22 ;
int V_23 ;
if ( V_20 && ( V_23 = F_4 ( & V_24 , V_8 , V_19 ) ) ) {
F_5 ( V_19 , L_1 , V_25 , V_21 , V_23 ) ;
return V_23 ;
}
if ( ( V_23 = F_6 ( V_3 , V_21 , V_4 ) ) ) {
F_5 ( V_19 , L_2 , V_25 , V_4 , V_21 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_8 , int V_26 )
{
if ( V_26 ) {
F_8 ( V_8 , NULL ) ;
F_9 ( & V_24 , V_8 ) ;
}
}
static int F_10 ( struct V_18 * V_19 ,
struct V_1 * V_8 , const struct V_27 * V_28 )
{
struct V_2 * V_3 = F_11 ( V_8 ) ;
int V_29 = V_28 - V_30 ;
int V_31 = V_32 [ V_29 ] ;
int V_33 = V_34 [ V_29 ] ;
struct V_1 * V_35 = F_1 ( V_3 , V_31 , V_36 [ V_29 ] ) ;
struct V_1 * V_37 = F_1 ( V_3 , V_33 , V_38 [ V_29 ] ) ;
int V_23 ;
F_12 ( V_19 , L_3
L_4 ,
V_25 , V_29 , V_39 [ V_29 ] , V_40 [ V_29 ] ,
V_36 [ V_29 ] , V_41 [ V_29 ] , V_31 ,
V_38 [ V_29 ] , V_42 [ V_29 ] , V_33 ) ;
if ( ! V_35 || ! V_37 ) {
if ( ! V_35 )
F_12 ( V_19 , L_5 ,
V_25 , V_36 [ V_29 ] , V_31 ) ;
if ( ! V_37 )
F_12 ( V_19 , L_5 ,
V_25 , V_38 [ V_29 ] , V_33 ) ;
return - V_43 ;
}
if ( ( V_35 != V_8 ) && ( V_37 != V_8 ) )
return - V_43 ;
if ( ( V_35 == V_37 ) && ( V_31 != V_33 ) ) {
F_5 ( V_19 , L_6 , V_25 ,
V_35 -> V_4 -> V_12 . V_22 , V_31 , V_33 ) ;
return - V_44 ;
}
F_12 ( V_19 , L_7 , V_25 ,
V_35 -> V_4 -> V_12 . V_22 ,
V_37 -> V_4 -> V_12 . V_22 ) ;
if ( ( V_23 = F_3 ( V_19 , V_3 , V_35 , V_31 , V_35 != V_8 ) ) )
return V_23 ;
if ( ( V_37 != V_35 ) && ( V_23 = F_3 ( V_19 , V_3 , V_37 , V_33 , V_37 != V_8 ) ) ) {
F_7 ( V_3 , V_35 , V_35 != V_8 ) ;
return V_23 ;
}
return 0 ;
}
static void F_13 ( struct V_18 * V_19 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = F_11 ( V_8 ) ;
int V_9 ;
F_12 ( V_19 , L_8 , V_25 ) ;
for ( V_9 = 0 ; V_9 < V_3 -> V_11 -> V_12 . V_13 ; V_9 ++ ) {
struct V_1 * V_45 = V_3 -> V_11 -> V_14 [ V_9 ] ;
if ( V_45 && ( F_14 ( V_45 ) == V_19 ) ) {
F_8 ( V_45 , NULL ) ;
F_9 ( & V_24 , V_45 ) ;
}
}
}
static int F_15 ( struct V_18 * V_19 ,
struct V_46 * V_46 )
{
F_16 ( V_19 , L_8 , V_25 ) ;
F_17 ( V_46 -> V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_8 ,
const struct V_27 * V_28 )
{
return F_19 ( V_8 , V_28 ,
V_48 + ( V_28 - V_30 ) ) ;
}
static int T_2 F_20 ( void )
{
int V_9 ;
F_21 ( L_9 ) ;
if ( ! V_49 ||
V_49 != V_50 ||
V_49 != V_51 ||
V_49 != V_52 ) {
F_22 ( V_53 L_10 ) ;
return - V_44 ;
}
for ( V_9 = 0 ; V_9 < V_49 ; V_9 ++ ) {
V_36 [ V_9 ] |= V_54 ;
V_38 [ V_9 ] &= V_55 ;
V_30 [ V_9 ] . V_56 = V_57 ;
V_30 [ V_9 ] . V_58 = V_39 [ V_9 ] ;
V_30 [ V_9 ] . V_59 = V_40 [ V_9 ] ;
V_48 [ V_9 ] . V_60 = V_61 ;
V_48 [ V_9 ] . V_62 = F_10 ;
V_48 [ V_9 ] . V_63 = F_13 ;
V_48 [ V_9 ] . V_64 = F_15 ;
V_48 [ V_9 ] . V_65 = V_36 [ V_9 ] ;
V_48 [ V_9 ] . V_66 = V_38 [ V_9 ] ;
V_48 [ V_9 ] . V_41 = V_41 [ V_9 ] ;
V_48 [ V_9 ] . V_42 = V_42 [ V_9 ] ;
}
return F_23 ( & V_24 ) ;
}
static void T_3 F_24 ( void )
{
F_21 ( L_11 ) ;
F_25 ( & V_24 ) ;
}
