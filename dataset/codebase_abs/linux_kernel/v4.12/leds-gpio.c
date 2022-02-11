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
struct V_21 * V_22 , T_1 V_23 )
{
int V_24 , V_25 ;
V_7 -> V_12 = V_18 -> V_12 ;
if ( ! V_7 -> V_12 ) {
unsigned long V_26 = V_27 ;
if ( ! F_9 ( V_18 -> V_28 ) ) {
F_10 ( V_20 , L_1 ,
V_18 -> V_28 , V_18 -> V_29 ) ;
return 0 ;
}
if ( V_18 -> V_30 )
V_26 |= V_31 ;
V_24 = F_11 ( V_20 , V_18 -> V_28 , V_26 ,
V_18 -> V_29 ) ;
if ( V_24 < 0 )
return V_24 ;
V_7 -> V_12 = F_12 ( V_18 -> V_28 ) ;
if ( ! V_7 -> V_12 )
return - V_32 ;
}
V_7 -> V_4 . V_29 = V_18 -> V_29 ;
V_7 -> V_4 . V_33 = V_18 -> V_33 ;
V_7 -> V_13 = F_13 ( V_7 -> V_12 ) ;
if ( ! V_7 -> V_13 )
V_7 -> V_4 . V_34 = F_3 ;
else
V_7 -> V_4 . V_35 = F_6 ;
V_7 -> V_10 = 0 ;
if ( V_23 ) {
V_7 -> V_11 = V_23 ;
V_7 -> V_4 . V_23 = F_7 ;
}
if ( V_18 -> V_36 == V_37 ) {
V_25 = F_14 ( V_7 -> V_12 ) ;
if ( V_25 < 0 )
return V_25 ;
} else {
V_25 = ( V_18 -> V_36 == V_38 ) ;
}
V_7 -> V_4 . V_39 = V_25 ? V_40 : V_9 ;
if ( ! V_18 -> V_41 )
V_7 -> V_4 . V_26 |= V_42 ;
if ( V_18 -> V_43 )
V_7 -> V_4 . V_26 |= V_44 ;
V_24 = F_15 ( V_7 -> V_12 , V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_16 ( V_20 , V_22 , & V_7 -> V_4 ) ;
}
static inline int F_17 ( int V_45 )
{
return sizeof( struct V_46 ) +
( sizeof( struct V_1 ) * V_45 ) ;
}
static struct V_46 * F_18 ( struct V_47 * V_48 )
{
struct V_19 * V_49 = & V_48 -> V_49 ;
struct V_50 * V_51 ;
struct V_46 * V_52 ;
int V_53 , V_24 ;
V_53 = F_19 ( V_49 ) ;
if ( ! V_53 )
return F_20 ( - V_54 ) ;
V_52 = F_21 ( V_49 , F_17 ( V_53 ) , V_55 ) ;
if ( ! V_52 )
return F_20 ( - V_56 ) ;
F_22 (dev, child) {
struct V_1 * V_7 = & V_52 -> V_57 [ V_52 -> V_45 ] ;
struct V_17 V_58 = {} ;
const char * V_25 = NULL ;
struct V_21 * V_22 = F_23 ( V_51 ) ;
V_24 = F_24 ( V_51 , L_2 , & V_58 . V_29 ) ;
if ( V_24 && F_25 ( V_59 ) && V_22 )
V_58 . V_29 = V_22 -> V_29 ;
if ( ! V_58 . V_29 ) {
F_26 ( V_51 ) ;
return F_20 ( - V_32 ) ;
}
V_58 . V_12 = F_27 ( V_49 , NULL , V_51 ,
V_60 ,
V_58 . V_29 ) ;
if ( F_28 ( V_58 . V_12 ) ) {
F_26 ( V_51 ) ;
return F_29 ( V_58 . V_12 ) ;
}
F_24 ( V_51 , L_3 ,
& V_58 . V_33 ) ;
if ( ! F_24 ( V_51 , L_4 ,
& V_25 ) ) {
if ( ! strcmp ( V_25 , L_5 ) )
V_58 . V_36 = V_37 ;
else if ( ! strcmp ( V_25 , L_6 ) )
V_58 . V_36 = V_38 ;
else
V_58 . V_36 = V_61 ;
}
if ( F_30 ( V_51 , L_7 ) )
V_58 . V_41 = 1 ;
if ( F_30 ( V_51 , L_8 ) )
V_58 . V_43 = 1 ;
V_24 = F_8 ( & V_58 , V_7 , V_49 , V_22 , NULL ) ;
if ( V_24 < 0 ) {
F_26 ( V_51 ) ;
return F_20 ( V_24 ) ;
}
V_7 -> V_4 . V_49 -> V_62 = V_22 ;
V_52 -> V_45 ++ ;
}
return V_52 ;
}
static int F_31 ( struct V_47 * V_48 )
{
struct V_63 * V_64 = F_32 ( & V_48 -> V_49 ) ;
struct V_46 * V_52 ;
int V_65 , V_24 = 0 ;
if ( V_64 && V_64 -> V_45 ) {
V_52 = F_21 ( & V_48 -> V_49 ,
F_17 ( V_64 -> V_45 ) ,
V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_52 -> V_45 = V_64 -> V_45 ;
for ( V_65 = 0 ; V_65 < V_52 -> V_45 ; V_65 ++ ) {
V_24 = F_8 ( & V_64 -> V_57 [ V_65 ] , & V_52 -> V_57 [ V_65 ] ,
& V_48 -> V_49 , NULL ,
V_64 -> F_7 ) ;
if ( V_24 < 0 )
return V_24 ;
}
} else {
V_52 = F_18 ( V_48 ) ;
if ( F_28 ( V_52 ) )
return F_33 ( V_52 ) ;
}
F_34 ( V_48 , V_52 ) ;
return 0 ;
}
static void F_35 ( struct V_47 * V_48 )
{
struct V_46 * V_52 = F_36 ( V_48 ) ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_52 -> V_45 ; V_65 ++ ) {
struct V_1 * V_58 = & V_52 -> V_57 [ V_65 ] ;
F_3 ( & V_58 -> V_4 , V_9 ) ;
}
}
