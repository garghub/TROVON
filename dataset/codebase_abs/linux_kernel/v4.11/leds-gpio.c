static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 ,
enum V_5 V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_8 ;
if ( V_6 == V_9 )
V_8 = 0 ;
else
V_8 = 1 ;
if ( V_7 -> V_10 ) {
V_7 -> V_11 ( V_7 -> V_12 , V_8 ,
NULL , NULL ) ;
V_7 -> V_10 = 0 ;
} else {
if ( V_7 -> V_13 )
F_4 ( V_7 -> V_12 , V_8 ) ;
else
F_5 ( V_7 -> V_12 , V_8 ) ;
}
}
static int F_6 ( struct V_2 * V_3 ,
enum V_5 V_6 )
{
F_3 ( V_3 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned long * V_14 , unsigned long * V_15 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_10 = 1 ;
return V_7 -> V_11 ( V_7 -> V_12 , V_16 ,
V_14 , V_15 ) ;
}
static int F_8 ( const struct V_17 * V_18 ,
struct V_1 * V_7 , struct V_19 * V_20 ,
T_1 V_21 )
{
int V_22 , V_23 ;
V_7 -> V_12 = V_18 -> V_12 ;
if ( ! V_7 -> V_12 ) {
unsigned long V_24 = V_25 ;
if ( ! F_9 ( V_18 -> V_26 ) ) {
F_10 ( V_20 , L_1 ,
V_18 -> V_26 , V_18 -> V_27 ) ;
return 0 ;
}
if ( V_18 -> V_28 )
V_24 |= V_29 ;
V_22 = F_11 ( V_20 , V_18 -> V_26 , V_24 ,
V_18 -> V_27 ) ;
if ( V_22 < 0 )
return V_22 ;
V_7 -> V_12 = F_12 ( V_18 -> V_26 ) ;
if ( ! V_7 -> V_12 )
return - V_30 ;
}
V_7 -> V_4 . V_27 = V_18 -> V_27 ;
V_7 -> V_4 . V_31 = V_18 -> V_31 ;
V_7 -> V_13 = F_13 ( V_7 -> V_12 ) ;
if ( ! V_7 -> V_13 )
V_7 -> V_4 . V_32 = F_3 ;
else
V_7 -> V_4 . V_33 = F_6 ;
V_7 -> V_10 = 0 ;
if ( V_21 ) {
V_7 -> V_11 = V_21 ;
V_7 -> V_4 . V_21 = F_7 ;
}
if ( V_18 -> V_34 == V_35 ) {
V_23 = F_14 ( V_7 -> V_12 ) ;
if ( V_23 < 0 )
return V_23 ;
} else {
V_23 = ( V_18 -> V_34 == V_36 ) ;
}
V_7 -> V_4 . V_37 = V_23 ? V_38 : V_9 ;
if ( ! V_18 -> V_39 )
V_7 -> V_4 . V_24 |= V_40 ;
if ( V_18 -> V_41 )
V_7 -> V_4 . V_24 |= V_42 ;
V_22 = F_15 ( V_7 -> V_12 , V_23 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_16 ( V_20 , & V_7 -> V_4 ) ;
}
static inline int F_17 ( int V_43 )
{
return sizeof( struct V_44 ) +
( sizeof( struct V_1 ) * V_43 ) ;
}
static struct V_44 * F_18 ( struct V_45 * V_46 )
{
struct V_19 * V_47 = & V_46 -> V_47 ;
struct V_48 * V_49 ;
struct V_44 * V_50 ;
int V_51 , V_22 ;
V_51 = F_19 ( V_47 ) ;
if ( ! V_51 )
return F_20 ( - V_52 ) ;
V_50 = F_21 ( V_47 , F_17 ( V_51 ) , V_53 ) ;
if ( ! V_50 )
return F_20 ( - V_54 ) ;
F_22 (dev, child) {
struct V_1 * V_7 = & V_50 -> V_55 [ V_50 -> V_43 ] ;
struct V_17 V_56 = {} ;
const char * V_23 = NULL ;
struct V_57 * V_58 = F_23 ( V_49 ) ;
V_22 = F_24 ( V_49 , L_2 , & V_56 . V_27 ) ;
if ( V_22 && F_25 ( V_59 ) && V_58 )
V_56 . V_27 = V_58 -> V_27 ;
if ( ! V_56 . V_27 ) {
F_26 ( V_49 ) ;
return F_20 ( - V_30 ) ;
}
V_56 . V_12 = F_27 ( V_47 , NULL , V_49 ,
V_60 ,
V_56 . V_27 ) ;
if ( F_28 ( V_56 . V_12 ) ) {
F_26 ( V_49 ) ;
return F_29 ( V_56 . V_12 ) ;
}
F_24 ( V_49 , L_3 ,
& V_56 . V_31 ) ;
if ( ! F_24 ( V_49 , L_4 ,
& V_23 ) ) {
if ( ! strcmp ( V_23 , L_5 ) )
V_56 . V_34 = V_35 ;
else if ( ! strcmp ( V_23 , L_6 ) )
V_56 . V_34 = V_36 ;
else
V_56 . V_34 = V_61 ;
}
if ( F_30 ( V_49 , L_7 ) )
V_56 . V_39 = 1 ;
if ( F_30 ( V_49 , L_8 ) )
V_56 . V_41 = 1 ;
V_22 = F_8 ( & V_56 , V_7 , V_47 , NULL ) ;
if ( V_22 < 0 ) {
F_26 ( V_49 ) ;
return F_20 ( V_22 ) ;
}
V_7 -> V_4 . V_47 -> V_62 = V_58 ;
V_50 -> V_43 ++ ;
}
return V_50 ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_63 * V_64 = F_32 ( & V_46 -> V_47 ) ;
struct V_44 * V_50 ;
int V_65 , V_22 = 0 ;
if ( V_64 && V_64 -> V_43 ) {
V_50 = F_21 ( & V_46 -> V_47 ,
F_17 ( V_64 -> V_43 ) ,
V_53 ) ;
if ( ! V_50 )
return - V_54 ;
V_50 -> V_43 = V_64 -> V_43 ;
for ( V_65 = 0 ; V_65 < V_50 -> V_43 ; V_65 ++ ) {
V_22 = F_8 ( & V_64 -> V_55 [ V_65 ] ,
& V_50 -> V_55 [ V_65 ] ,
& V_46 -> V_47 , V_64 -> F_7 ) ;
if ( V_22 < 0 )
return V_22 ;
}
} else {
V_50 = F_18 ( V_46 ) ;
if ( F_28 ( V_50 ) )
return F_33 ( V_50 ) ;
}
F_34 ( V_46 , V_50 ) ;
return 0 ;
}
static void F_35 ( struct V_45 * V_46 )
{
struct V_44 * V_50 = F_36 ( V_46 ) ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_50 -> V_43 ; V_65 ++ ) {
struct V_1 * V_56 = & V_50 -> V_55 [ V_65 ] ;
F_3 ( & V_56 -> V_4 , V_9 ) ;
}
}
