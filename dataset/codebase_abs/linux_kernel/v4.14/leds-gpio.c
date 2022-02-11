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
if ( V_18 -> V_45 )
V_7 -> V_4 . V_26 |= V_46 ;
V_24 = F_15 ( V_7 -> V_12 , V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_16 ( V_20 , V_22 , & V_7 -> V_4 ) ;
}
static inline int F_17 ( int V_47 )
{
return sizeof( struct V_48 ) +
( sizeof( struct V_1 ) * V_47 ) ;
}
static struct V_48 * F_18 ( struct V_49 * V_50 )
{
struct V_19 * V_51 = & V_50 -> V_51 ;
struct V_52 * V_53 ;
struct V_48 * V_54 ;
int V_55 , V_24 ;
V_55 = F_19 ( V_51 ) ;
if ( ! V_55 )
return F_20 ( - V_56 ) ;
V_54 = F_21 ( V_51 , F_17 ( V_55 ) , V_57 ) ;
if ( ! V_54 )
return F_20 ( - V_58 ) ;
F_22 (dev, child) {
struct V_1 * V_7 = & V_54 -> V_59 [ V_54 -> V_47 ] ;
struct V_17 V_60 = {} ;
const char * V_25 = NULL ;
struct V_21 * V_22 = F_23 ( V_53 ) ;
V_24 = F_24 ( V_53 , L_2 , & V_60 . V_29 ) ;
if ( V_24 && F_25 ( V_61 ) && V_22 )
V_60 . V_29 = V_22 -> V_29 ;
if ( ! V_60 . V_29 ) {
F_26 ( V_53 ) ;
return F_20 ( - V_32 ) ;
}
V_60 . V_12 = F_27 ( V_51 , NULL , V_53 ,
V_62 ,
V_60 . V_29 ) ;
if ( F_28 ( V_60 . V_12 ) ) {
F_26 ( V_53 ) ;
return F_29 ( V_60 . V_12 ) ;
}
F_24 ( V_53 , L_3 ,
& V_60 . V_33 ) ;
if ( ! F_24 ( V_53 , L_4 ,
& V_25 ) ) {
if ( ! strcmp ( V_25 , L_5 ) )
V_60 . V_36 = V_37 ;
else if ( ! strcmp ( V_25 , L_6 ) )
V_60 . V_36 = V_38 ;
else
V_60 . V_36 = V_63 ;
}
if ( F_30 ( V_53 , L_7 ) )
V_60 . V_41 = 1 ;
if ( F_30 ( V_53 , L_8 ) )
V_60 . V_45 = 1 ;
if ( F_30 ( V_53 , L_9 ) )
V_60 . V_43 = 1 ;
V_24 = F_8 ( & V_60 , V_7 , V_51 , V_22 , NULL ) ;
if ( V_24 < 0 ) {
F_26 ( V_53 ) ;
return F_20 ( V_24 ) ;
}
V_7 -> V_4 . V_51 -> V_64 = V_22 ;
V_54 -> V_47 ++ ;
}
return V_54 ;
}
static int F_31 ( struct V_49 * V_50 )
{
struct V_65 * V_66 = F_32 ( & V_50 -> V_51 ) ;
struct V_48 * V_54 ;
int V_67 , V_24 = 0 ;
if ( V_66 && V_66 -> V_47 ) {
V_54 = F_21 ( & V_50 -> V_51 ,
F_17 ( V_66 -> V_47 ) ,
V_57 ) ;
if ( ! V_54 )
return - V_58 ;
V_54 -> V_47 = V_66 -> V_47 ;
for ( V_67 = 0 ; V_67 < V_54 -> V_47 ; V_67 ++ ) {
V_24 = F_8 ( & V_66 -> V_59 [ V_67 ] , & V_54 -> V_59 [ V_67 ] ,
& V_50 -> V_51 , NULL ,
V_66 -> F_7 ) ;
if ( V_24 < 0 )
return V_24 ;
}
} else {
V_54 = F_18 ( V_50 ) ;
if ( F_28 ( V_54 ) )
return F_33 ( V_54 ) ;
}
F_34 ( V_50 , V_54 ) ;
return 0 ;
}
static void F_35 ( struct V_49 * V_50 )
{
struct V_48 * V_54 = F_36 ( V_50 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_54 -> V_47 ; V_67 ++ ) {
struct V_1 * V_60 = & V_54 -> V_59 [ V_67 ] ;
if ( ! ( V_60 -> V_4 . V_26 & V_46 ) )
F_3 ( & V_60 -> V_4 , V_9 ) ;
}
}
