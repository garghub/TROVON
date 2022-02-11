static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
int V_8 ;
if ( V_4 == V_9 )
V_8 = 0 ;
else
V_8 = 1 ;
if ( V_6 -> V_10 ) {
V_6 -> V_11 ( V_6 -> V_12 , V_8 ,
NULL , NULL ) ;
V_6 -> V_10 = 0 ;
} else {
if ( V_6 -> V_13 )
F_3 ( V_6 -> V_12 , V_8 ) ;
else
F_4 ( V_6 -> V_12 , V_8 ) ;
}
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long * V_14 , unsigned long * V_15 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
V_6 -> V_10 = 1 ;
return V_6 -> V_11 ( V_6 -> V_12 , V_16 ,
V_14 , V_15 ) ;
}
static int F_7 ( const struct V_17 * V_18 ,
struct V_5 * V_6 , struct V_19 * V_20 ,
int (* F_8)( struct V_21 * , int , unsigned long * ,
unsigned long * ) )
{
int V_22 , V_23 ;
V_6 -> V_12 = V_18 -> V_12 ;
if ( ! V_6 -> V_12 ) {
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
V_6 -> V_12 = F_12 ( V_18 -> V_26 ) ;
if ( ! V_6 -> V_12 )
return - V_30 ;
}
V_6 -> V_7 . V_27 = V_18 -> V_27 ;
V_6 -> V_7 . V_31 = V_18 -> V_31 ;
V_6 -> V_13 = F_13 ( V_6 -> V_12 ) ;
if ( ! V_6 -> V_13 )
V_6 -> V_7 . V_32 = F_1 ;
else
V_6 -> V_7 . V_33 = F_5 ;
V_6 -> V_10 = 0 ;
if ( F_8 ) {
V_6 -> V_11 = F_8 ;
V_6 -> V_7 . F_8 = F_6 ;
}
if ( V_18 -> V_34 == V_35 )
V_23 = ! ! F_14 ( V_6 -> V_12 ) ;
else
V_23 = ( V_18 -> V_34 == V_36 ) ;
V_6 -> V_7 . V_37 = V_23 ? V_38 : V_9 ;
if ( ! V_18 -> V_39 )
V_6 -> V_7 . V_24 |= V_40 ;
if ( V_18 -> V_41 )
V_6 -> V_7 . V_24 |= V_42 ;
V_22 = F_15 ( V_6 -> V_12 , V_23 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_16 ( V_20 , & V_6 -> V_7 ) ;
}
static inline int F_17 ( int V_43 )
{
return sizeof( struct V_44 ) +
( sizeof( struct V_5 ) * V_43 ) ;
}
static struct V_44 * F_18 ( struct V_45 * V_46 )
{
struct V_19 * V_47 = & V_46 -> V_47 ;
struct V_48 * V_49 ;
struct V_44 * V_50 ;
int V_51 , V_22 ;
struct V_52 * V_53 ;
V_51 = F_19 ( V_47 ) ;
if ( ! V_51 )
return F_20 ( - V_54 ) ;
V_50 = F_21 ( V_47 , F_17 ( V_51 ) , V_55 ) ;
if ( ! V_50 )
return F_20 ( - V_56 ) ;
F_22 (dev, child) {
struct V_17 V_57 = {} ;
const char * V_23 = NULL ;
V_57 . V_12 = F_23 ( V_47 , NULL , V_49 ) ;
if ( F_24 ( V_57 . V_12 ) ) {
F_25 ( V_49 ) ;
V_22 = F_26 ( V_57 . V_12 ) ;
goto V_58;
}
V_53 = F_27 ( V_49 ) ;
if ( F_28 ( V_49 , L_2 ) ) {
F_29 ( V_49 , L_2 , & V_57 . V_27 ) ;
} else {
if ( F_30 ( V_59 ) && ! V_57 . V_27 && V_53 )
V_57 . V_27 = V_53 -> V_27 ;
if ( ! V_57 . V_27 ) {
V_22 = - V_30 ;
goto V_58;
}
}
F_29 ( V_49 , L_3 ,
& V_57 . V_31 ) ;
if ( ! F_29 ( V_49 , L_4 ,
& V_23 ) ) {
if ( ! strcmp ( V_23 , L_5 ) )
V_57 . V_34 = V_35 ;
else if ( ! strcmp ( V_23 , L_6 ) )
V_57 . V_34 = V_36 ;
else
V_57 . V_34 = V_60 ;
}
if ( F_28 ( V_49 , L_7 ) )
V_57 . V_39 = 1 ;
if ( F_28 ( V_49 , L_8 ) )
V_57 . V_41 = 1 ;
V_22 = F_7 ( & V_57 , & V_50 -> V_61 [ V_50 -> V_43 ] ,
V_47 , NULL ) ;
if ( V_22 < 0 ) {
F_25 ( V_49 ) ;
goto V_58;
}
V_50 -> V_43 ++ ;
}
return V_50 ;
V_58:
for ( V_51 = V_50 -> V_43 - 1 ; V_51 >= 0 ; V_51 -- )
F_31 ( & V_50 -> V_61 [ V_51 ] . V_7 ) ;
return F_20 ( V_22 ) ;
}
static int F_32 ( struct V_45 * V_46 )
{
struct V_62 * V_63 = F_33 ( & V_46 -> V_47 ) ;
struct V_44 * V_50 ;
int V_64 , V_22 = 0 ;
if ( V_63 && V_63 -> V_43 ) {
V_50 = F_21 ( & V_46 -> V_47 ,
F_17 ( V_63 -> V_43 ) ,
V_55 ) ;
if ( ! V_50 )
return - V_56 ;
V_50 -> V_43 = V_63 -> V_43 ;
for ( V_64 = 0 ; V_64 < V_50 -> V_43 ; V_64 ++ ) {
V_22 = F_7 ( & V_63 -> V_61 [ V_64 ] ,
& V_50 -> V_61 [ V_64 ] ,
& V_46 -> V_47 , V_63 -> F_6 ) ;
if ( V_22 < 0 ) {
for ( V_64 = V_64 - 1 ; V_64 >= 0 ; V_64 -- )
F_31 (
& V_50 -> V_61 [ V_64 ] . V_7 ) ;
return V_22 ;
}
}
} else {
V_50 = F_18 ( V_46 ) ;
if ( F_24 ( V_50 ) )
return F_26 ( V_50 ) ;
}
F_34 ( V_46 , V_50 ) ;
return 0 ;
}
static int F_35 ( struct V_45 * V_46 )
{
struct V_44 * V_50 = F_36 ( V_46 ) ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_50 -> V_43 ; V_64 ++ )
F_31 ( & V_50 -> V_61 [ V_64 ] . V_7 ) ;
return 0 ;
}
static void F_37 ( struct V_45 * V_46 )
{
struct V_44 * V_50 = F_36 ( V_46 ) ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_50 -> V_43 ; V_64 ++ ) {
struct V_5 * V_57 = & V_50 -> V_61 [ V_64 ] ;
F_1 ( & V_57 -> V_7 , V_9 ) ;
}
}
