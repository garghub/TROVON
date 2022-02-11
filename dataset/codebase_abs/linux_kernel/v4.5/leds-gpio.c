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
unsigned long V_24 = 0 ;
if ( ! F_9 ( V_18 -> V_25 ) ) {
F_10 ( V_20 , L_1 ,
V_18 -> V_25 , V_18 -> V_26 ) ;
return 0 ;
}
if ( V_18 -> V_27 )
V_24 |= V_28 ;
V_22 = F_11 ( V_20 , V_18 -> V_25 , V_24 ,
V_18 -> V_26 ) ;
if ( V_22 < 0 )
return V_22 ;
V_6 -> V_12 = F_12 ( V_18 -> V_25 ) ;
if ( F_13 ( V_6 -> V_12 ) )
return F_14 ( V_6 -> V_12 ) ;
}
V_6 -> V_7 . V_26 = V_18 -> V_26 ;
V_6 -> V_7 . V_29 = V_18 -> V_29 ;
V_6 -> V_13 = F_15 ( V_6 -> V_12 ) ;
if ( ! V_6 -> V_13 )
V_6 -> V_7 . V_30 = F_1 ;
else
V_6 -> V_7 . V_31 = F_5 ;
V_6 -> V_10 = 0 ;
if ( F_8 ) {
V_6 -> V_11 = F_8 ;
V_6 -> V_7 . F_8 = F_6 ;
}
if ( V_18 -> V_32 == V_33 )
V_23 = ! ! F_16 ( V_6 -> V_12 ) ;
else
V_23 = ( V_18 -> V_32 == V_34 ) ;
V_6 -> V_7 . V_35 = V_23 ? V_36 : V_9 ;
if ( ! V_18 -> V_37 )
V_6 -> V_7 . V_24 |= V_38 ;
V_22 = F_17 ( V_6 -> V_12 , V_23 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_18 ( V_20 , & V_6 -> V_7 ) ;
}
static inline int F_19 ( int V_39 )
{
return sizeof( struct V_40 ) +
( sizeof( struct V_5 ) * V_39 ) ;
}
static struct V_40 * F_20 ( struct V_41 * V_42 )
{
struct V_19 * V_43 = & V_42 -> V_43 ;
struct V_44 * V_45 ;
struct V_40 * V_46 ;
int V_47 , V_22 ;
struct V_48 * V_49 ;
V_47 = F_21 ( V_43 ) ;
if ( ! V_47 )
return F_22 ( - V_50 ) ;
V_46 = F_23 ( V_43 , F_19 ( V_47 ) , V_51 ) ;
if ( ! V_46 )
return F_22 ( - V_52 ) ;
F_24 (dev, child) {
struct V_17 V_53 = {} ;
const char * V_23 = NULL ;
V_53 . V_12 = F_25 ( V_43 , NULL , V_45 ) ;
if ( F_13 ( V_53 . V_12 ) ) {
F_26 ( V_45 ) ;
V_22 = F_14 ( V_53 . V_12 ) ;
goto V_54;
}
V_49 = F_27 ( V_45 ) ;
if ( F_28 ( V_45 , L_2 ) ) {
F_29 ( V_45 , L_2 , & V_53 . V_26 ) ;
} else {
if ( F_30 ( V_55 ) && ! V_53 . V_26 && V_49 )
V_53 . V_26 = V_49 -> V_26 ;
if ( ! V_53 . V_26 ) {
V_22 = - V_56 ;
goto V_54;
}
}
F_29 ( V_45 , L_3 ,
& V_53 . V_29 ) ;
if ( ! F_29 ( V_45 , L_4 ,
& V_23 ) ) {
if ( ! strcmp ( V_23 , L_5 ) )
V_53 . V_32 = V_33 ;
else if ( ! strcmp ( V_23 , L_6 ) )
V_53 . V_32 = V_34 ;
else
V_53 . V_32 = V_57 ;
}
if ( F_28 ( V_45 , L_7 ) )
V_53 . V_37 = 1 ;
V_22 = F_7 ( & V_53 , & V_46 -> V_58 [ V_46 -> V_39 ] ,
V_43 , NULL ) ;
if ( V_22 < 0 ) {
F_26 ( V_45 ) ;
goto V_54;
}
V_46 -> V_39 ++ ;
}
return V_46 ;
V_54:
for ( V_47 = V_46 -> V_39 - 1 ; V_47 >= 0 ; V_47 -- )
F_31 ( & V_46 -> V_58 [ V_47 ] . V_7 ) ;
return F_22 ( V_22 ) ;
}
static int F_32 ( struct V_41 * V_42 )
{
struct V_59 * V_60 = F_33 ( & V_42 -> V_43 ) ;
struct V_40 * V_46 ;
int V_61 , V_22 = 0 ;
if ( V_60 && V_60 -> V_39 ) {
V_46 = F_23 ( & V_42 -> V_43 ,
F_19 ( V_60 -> V_39 ) ,
V_51 ) ;
if ( ! V_46 )
return - V_52 ;
V_46 -> V_39 = V_60 -> V_39 ;
for ( V_61 = 0 ; V_61 < V_46 -> V_39 ; V_61 ++ ) {
V_22 = F_7 ( & V_60 -> V_58 [ V_61 ] ,
& V_46 -> V_58 [ V_61 ] ,
& V_42 -> V_43 , V_60 -> F_6 ) ;
if ( V_22 < 0 ) {
for ( V_61 = V_61 - 1 ; V_61 >= 0 ; V_61 -- )
F_31 (
& V_46 -> V_58 [ V_61 ] . V_7 ) ;
return V_22 ;
}
}
} else {
V_46 = F_20 ( V_42 ) ;
if ( F_13 ( V_46 ) )
return F_14 ( V_46 ) ;
}
F_34 ( V_42 , V_46 ) ;
return 0 ;
}
static int F_35 ( struct V_41 * V_42 )
{
struct V_40 * V_46 = F_36 ( V_42 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_46 -> V_39 ; V_61 ++ )
F_31 ( & V_46 -> V_58 [ V_61 ] . V_7 ) ;
return 0 ;
}
static void F_37 ( struct V_41 * V_42 )
{
struct V_40 * V_46 = F_36 ( V_42 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_46 -> V_39 ; V_61 ++ ) {
struct V_5 * V_53 = & V_46 -> V_58 [ V_61 ] ;
F_1 ( & V_53 -> V_7 , V_9 ) ;
}
}
