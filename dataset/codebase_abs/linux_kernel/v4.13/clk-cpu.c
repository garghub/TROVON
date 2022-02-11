static const struct V_1 * F_1 (
struct V_2 * V_3 , unsigned long V_4 )
{
const struct V_1 * V_5 =
V_3 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( V_4 == V_5 [ V_6 ] . V_8 )
return & V_5 [ V_6 ] ;
}
return NULL ;
}
static unsigned long F_2 ( struct V_9 * V_10 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_10 ) ;
const struct V_12 * V_13 = V_3 -> V_13 ;
T_1 V_14 = F_4 ( V_3 -> V_15 + V_13 -> V_16 ) ;
V_14 >>= V_13 -> V_17 ;
V_14 &= V_13 -> V_18 ;
return V_11 / ( V_14 + 1 ) ;
}
static void F_5 ( struct V_2 * V_3 ,
const struct V_1 * V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_6 ( V_4 -> V_19 ) ; V_6 ++ ) {
const struct V_20 * V_21 = & V_4 -> V_19 [ V_6 ] ;
if ( ! V_21 -> V_22 )
continue;
F_7 ( L_1 ,
V_23 , V_21 -> V_22 , V_21 -> V_24 ) ;
F_8 ( V_21 -> V_24 , V_3 -> V_15 + V_21 -> V_22 ) ;
}
}
static int F_9 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
const struct V_12 * V_13 = V_3 -> V_13 ;
const struct V_1 * V_4 ;
unsigned long V_27 , V_28 ;
unsigned long V_29 ;
V_4 = F_1 ( V_3 , V_26 -> V_30 ) ;
if ( ! V_4 ) {
F_10 ( L_2 ,
V_23 , V_26 -> V_30 ) ;
return - V_31 ;
}
V_27 = F_11 ( V_3 -> V_32 ) ;
F_12 ( V_3 -> V_33 , V_29 ) ;
if ( V_27 > V_26 -> V_34 ) {
V_28 = F_13 ( V_27 , V_26 -> V_34 ) - 1 ;
if ( V_28 > V_13 -> V_18 ) {
F_14 ( L_3 ,
V_23 , V_28 , V_13 -> V_18 ) ;
V_28 = V_13 -> V_18 ;
}
F_7 ( L_4 ,
V_23 , V_28 , V_27 , V_26 -> V_34 ) ;
F_8 ( F_15 ( V_28 , V_13 -> V_18 ,
V_13 -> V_17 ) |
F_15 ( V_13 -> V_35 ,
V_13 -> V_36 ,
V_13 -> V_37 ) ,
V_3 -> V_15 + V_13 -> V_16 ) ;
} else {
F_8 ( F_15 ( V_13 -> V_35 ,
V_13 -> V_36 ,
V_13 -> V_37 ) ,
V_3 -> V_15 + V_13 -> V_16 ) ;
}
F_16 ( V_3 -> V_33 , V_29 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
const struct V_12 * V_13 = V_3 -> V_13 ;
const struct V_1 * V_4 ;
unsigned long V_29 ;
V_4 = F_1 ( V_3 , V_26 -> V_30 ) ;
if ( ! V_4 ) {
F_10 ( L_2 ,
V_23 , V_26 -> V_30 ) ;
return - V_31 ;
}
F_12 ( V_3 -> V_33 , V_29 ) ;
if ( V_26 -> V_34 < V_26 -> V_30 )
F_5 ( V_3 , V_4 ) ;
F_8 ( F_15 ( 0 , V_13 -> V_18 ,
V_13 -> V_17 ) |
F_15 ( V_13 -> V_38 ,
V_13 -> V_36 ,
V_13 -> V_37 ) ,
V_3 -> V_15 + V_13 -> V_16 ) ;
if ( V_26 -> V_34 > V_26 -> V_30 )
F_5 ( V_3 , V_4 ) ;
F_16 ( V_3 -> V_33 , V_29 ) ;
return 0 ;
}
static int F_18 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
struct V_25 * V_26 = V_42 ;
struct V_2 * V_3 = F_19 ( V_40 ) ;
int V_43 = 0 ;
F_7 ( L_5 ,
V_23 , V_41 , V_26 -> V_34 , V_26 -> V_30 ) ;
if ( V_41 == V_44 )
V_43 = F_9 ( V_3 , V_26 ) ;
else if ( V_41 == V_45 )
V_43 = F_17 ( V_3 , V_26 ) ;
return F_20 ( V_43 ) ;
}
struct V_46 * F_21 ( const char * V_47 ,
const char * const * V_48 , T_2 V_49 ,
const struct V_12 * V_13 ,
const struct V_1 * V_50 ,
int V_51 , void T_3 * V_15 , T_4 * V_33 )
{
struct V_2 * V_3 ;
struct V_52 V_53 ;
struct V_46 * V_46 , * V_54 ;
int V_43 ;
if ( V_49 < 2 ) {
F_10 ( L_6 , V_23 ) ;
return F_22 ( - V_31 ) ;
}
V_3 = F_23 ( sizeof( * V_3 ) , V_55 ) ;
if ( ! V_3 )
return F_22 ( - V_56 ) ;
V_53 . V_47 = V_47 ;
V_53 . V_48 = & V_48 [ V_13 -> V_38 ] ;
V_53 . V_49 = 1 ;
V_53 . V_57 = & V_58 ;
V_53 . V_29 = ( V_51 > 0 ) ? V_59 : 0 ;
V_53 . V_29 |= V_60 ;
V_53 . V_29 |= V_61 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_33 = V_33 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_62 . V_63 = F_18 ;
V_3 -> V_10 . V_53 = & V_53 ;
V_3 -> V_32 = F_24 ( V_48 [ V_13 -> V_35 ] ) ;
if ( ! V_3 -> V_32 ) {
F_10 ( L_7 ,
V_23 , V_13 -> V_35 ) ;
V_43 = - V_31 ;
goto V_64;
}
V_43 = F_25 ( V_3 -> V_32 ) ;
if ( V_43 ) {
F_10 ( L_8 ,
V_23 ) ;
goto V_64;
}
V_46 = F_24 ( V_48 [ V_13 -> V_38 ] ) ;
if ( ! V_46 ) {
F_10 ( L_9 ,
V_23 , V_13 -> V_38 ,
V_48 [ V_13 -> V_38 ] ) ;
V_43 = - V_31 ;
goto V_65;
}
V_43 = F_26 ( V_46 , & V_3 -> V_62 ) ;
if ( V_43 ) {
F_10 ( L_10 ,
V_23 , V_47 ) ;
goto V_65;
}
if ( V_51 > 0 ) {
V_3 -> V_7 = V_51 ;
V_3 -> V_5 = F_27 ( V_50 ,
sizeof( * V_50 ) * V_51 ,
V_55 ) ;
if ( ! V_3 -> V_5 ) {
F_10 ( L_11 ,
V_23 ) ;
V_43 = - V_56 ;
goto V_66;
}
}
V_54 = F_28 ( NULL , & V_3 -> V_10 ) ;
if ( F_29 ( V_54 ) ) {
F_10 ( L_12 , V_23 , V_47 ) ;
V_43 = F_30 ( V_54 ) ;
goto V_67;
}
return V_54 ;
V_67:
F_31 ( V_3 -> V_5 ) ;
V_66:
F_32 ( V_46 , & V_3 -> V_62 ) ;
V_65:
F_33 ( V_3 -> V_32 ) ;
V_64:
F_31 ( V_3 ) ;
return F_22 ( V_43 ) ;
}
