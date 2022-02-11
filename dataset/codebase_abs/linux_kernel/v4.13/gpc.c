static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 , V_7 ;
T_1 V_8 ;
if ( V_5 -> V_9 & V_10 )
return - V_11 ;
F_4 ( V_5 -> V_12 , V_5 -> V_13 + V_14 , & V_8 ) ;
V_6 = V_8 & 0x3f ;
V_7 = ( V_8 >> 8 ) & 0x3f ;
F_5 ( V_5 -> V_12 , V_5 -> V_13 + V_15 ,
0x1 , 0x1 ) ;
V_8 = F_6 ( V_5 -> V_16 ) ;
F_5 ( V_5 -> V_12 , V_17 , V_8 , V_8 ) ;
F_7 ( F_8 ( V_6 + V_7 , V_5 -> V_18 ) ) ;
if ( V_5 -> V_19 )
F_9 ( V_5 -> V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_20 , V_21 , V_22 , V_23 ;
T_1 V_8 ;
if ( V_5 -> V_19 ) {
V_21 = F_11 ( V_5 -> V_19 ) ;
if ( V_21 ) {
F_12 ( L_1 ,
V_24 , V_21 ) ;
return V_21 ;
}
}
for ( V_20 = 0 ; V_20 < V_5 -> V_25 ; V_20 ++ )
F_13 ( V_5 -> V_26 [ V_20 ] ) ;
F_5 ( V_5 -> V_12 , V_5 -> V_13 + V_15 ,
0x1 , 0x1 ) ;
F_4 ( V_5 -> V_12 , V_5 -> V_13 + V_14 , & V_8 ) ;
V_22 = V_8 & 0x3f ;
V_23 = ( V_8 >> 8 ) & 0x3f ;
V_8 = F_6 ( V_5 -> V_16 + 1 ) ;
F_5 ( V_5 -> V_12 , V_17 , V_8 , V_8 ) ;
F_7 ( F_8 ( V_22 + V_23 , V_5 -> V_18 ) ) ;
for ( V_20 = 0 ; V_20 < V_5 -> V_25 ; V_20 ++ )
F_14 ( V_5 -> V_26 [ V_20 ] ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 , struct V_1 * V_29 )
{
int V_20 , V_21 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
struct V_26 * V_26 = F_16 ( V_28 -> V_30 , V_20 ) ;
if ( F_17 ( V_26 ) )
break;
if ( V_20 >= V_31 ) {
F_18 ( V_28 , L_2 , V_31 ) ;
V_21 = - V_32 ;
goto V_33;
}
V_29 -> V_26 [ V_20 ] = V_26 ;
}
V_29 -> V_25 = V_20 ;
return 0 ;
V_33:
while ( V_20 -- )
F_19 ( V_29 -> V_26 [ V_20 ] ) ;
return V_21 ;
}
static void F_20 ( struct V_1 * V_29 )
{
int V_20 ;
for ( V_20 = V_29 -> V_25 - 1 ; V_20 >= 0 ; V_20 -- )
F_19 ( V_29 -> V_26 [ V_20 ] ) ;
}
static int F_21 ( struct V_27 * V_28 , struct V_1 * V_29 )
{
V_29 -> V_19 = F_22 ( V_28 , L_3 ) ;
if ( F_17 ( V_29 -> V_19 ) ) {
if ( F_23 ( V_29 -> V_19 ) == - V_34 )
V_29 -> V_19 = NULL ;
else
return F_23 ( V_29 -> V_19 ) ;
}
return F_15 ( V_28 , V_29 ) ;
}
static int F_24 ( struct V_35 * V_36 )
{
struct V_1 * V_29 = V_36 -> V_28 . V_37 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
int V_21 ;
if ( V_28 -> V_30 ) {
V_21 = F_21 ( V_28 , V_29 ) ;
if ( V_21 )
return V_21 ;
}
if ( V_29 -> V_4 . V_38 )
V_29 -> V_4 . V_38 ( & V_29 -> V_4 ) ;
if ( F_25 ( V_39 ) ) {
F_26 ( & V_29 -> V_4 , NULL , false ) ;
V_21 = F_27 ( V_28 -> V_30 , & V_29 -> V_4 ) ;
if ( V_21 )
goto V_40;
}
F_28 ( V_28 , V_28 -> V_41 , V_42 ) ;
return 0 ;
V_40:
F_29 ( & V_29 -> V_4 ) ;
F_20 ( V_29 ) ;
return V_21 ;
}
static int F_30 ( struct V_35 * V_36 )
{
struct V_1 * V_29 = V_36 -> V_28 . V_37 ;
if ( F_25 ( V_39 ) ) {
F_31 ( V_36 -> V_28 . V_30 ) ;
F_29 ( & V_29 -> V_4 ) ;
F_20 ( V_29 ) ;
}
return 0 ;
}
static int F_32 ( struct V_27 * V_28 , struct V_12 * V_12 ,
unsigned int V_43 )
{
struct V_1 * V_29 ;
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < V_43 ; V_20 ++ ) {
V_29 = & V_44 [ V_20 ] ;
V_29 -> V_12 = V_12 ;
V_29 -> V_18 = 66 ;
if ( V_20 == 1 ) {
V_29 -> V_19 = F_33 ( V_28 , L_4 ) ;
if ( F_17 ( V_29 -> V_19 ) )
return F_23 ( V_29 -> V_19 ) ; ;
V_21 = F_15 ( V_28 , V_29 ) ;
if ( V_21 )
goto V_33;
V_29 -> V_4 . V_38 ( & V_29 -> V_4 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_43 ; V_20 ++ )
F_26 ( & V_44 [ V_20 ] . V_4 , NULL , false ) ;
if ( F_25 ( V_39 ) ) {
V_21 = F_34 ( V_28 -> V_30 ,
& V_45 ) ;
if ( V_21 )
goto V_40;
}
return 0 ;
V_40:
for ( V_20 = 0 ; V_20 < V_43 ; V_20 ++ )
F_29 ( & V_44 [ V_20 ] . V_4 ) ;
F_20 ( & V_44 [ V_46 ] ) ;
V_33:
return V_21 ;
}
static int F_35 ( struct V_35 * V_36 )
{
const struct V_47 * V_48 =
F_36 ( V_49 , & V_36 -> V_28 ) ;
const struct V_50 * V_51 = V_48 -> V_52 ;
struct V_53 * V_54 ;
struct V_12 * V_12 ;
struct V_55 * V_56 ;
void T_2 * V_4 ;
int V_21 ;
V_54 = F_37 ( V_36 -> V_28 . V_30 , L_5 ) ;
if ( ! F_38 ( V_36 -> V_28 . V_30 , L_6 ) &&
! V_54 )
return 0 ;
V_56 = F_39 ( V_36 , V_57 , 0 ) ;
V_4 = F_40 ( & V_36 -> V_28 , V_56 ) ;
if ( F_17 ( V_4 ) )
return F_23 ( V_4 ) ;
V_12 = F_41 ( & V_36 -> V_28 , NULL , V_4 ,
& V_58 ) ;
if ( F_17 ( V_12 ) ) {
V_21 = F_23 ( V_12 ) ;
F_18 ( & V_36 -> V_28 , L_7 ,
V_21 ) ;
return V_21 ;
}
if ( V_51 -> V_59 )
V_44 [ V_46 ] . V_9 |=
V_10 ;
if ( ! V_54 ) {
V_21 = F_32 ( & V_36 -> V_28 , V_12 ,
V_51 -> V_43 ) ;
if ( V_21 )
return V_21 ;
} else {
struct V_1 * V_29 ;
struct V_35 * V_60 ;
struct V_53 * V_61 ;
struct V_26 * V_62 ;
unsigned int V_18 ;
int V_63 ;
V_62 = F_42 ( & V_36 -> V_28 , L_8 ) ;
if ( F_17 ( V_62 ) )
return F_23 ( V_62 ) ;
V_18 = F_43 ( V_62 ) / 1000000 ;
F_44 (pgc_node, np) {
V_21 = F_45 ( V_61 , L_9 , & V_63 ) ;
if ( V_21 ) {
F_46 ( V_61 ) ;
return V_21 ;
}
if ( V_63 >= V_51 -> V_43 )
continue;
V_29 = & V_44 [ V_63 ] ;
V_29 -> V_12 = V_12 ;
V_29 -> V_18 = V_18 ;
V_60 = F_47 ( L_10 ,
V_63 ) ;
if ( ! V_60 ) {
F_46 ( V_61 ) ;
return - V_64 ;
}
V_60 -> V_28 . V_37 = V_29 ;
V_60 -> V_28 . V_41 = & V_36 -> V_28 ;
V_60 -> V_28 . V_30 = V_61 ;
V_21 = F_48 ( V_60 ) ;
if ( V_21 ) {
F_49 ( V_60 ) ;
F_46 ( V_61 ) ;
return V_21 ;
}
}
}
return 0 ;
}
static int F_50 ( struct V_35 * V_36 )
{
int V_21 ;
if ( ! F_37 ( V_36 -> V_28 . V_30 , L_5 ) ) {
F_31 ( V_36 -> V_28 . V_30 ) ;
V_21 = F_29 ( & V_44 [ V_46 ] . V_4 ) ;
if ( V_21 )
return V_21 ;
F_20 ( & V_44 [ V_46 ] ) ;
V_21 = F_29 ( & V_44 [ V_65 ] . V_4 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
