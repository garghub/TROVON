static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( V_4 -> V_5 ) {
V_4 -> V_6 ( V_4 -> V_7 ,
V_4 -> V_8 , NULL , NULL ) ;
V_4 -> V_5 = 0 ;
} else
F_3 ( V_4 -> V_7 , V_4 -> V_8 ) ;
}
static void F_4 ( struct V_9 * V_10 ,
enum V_11 V_12 )
{
struct V_3 * V_4 =
F_2 ( V_10 , struct V_3 , V_13 ) ;
int V_14 ;
if ( V_12 == V_15 )
V_14 = 0 ;
else
V_14 = 1 ;
if ( V_4 -> V_16 ) {
V_4 -> V_8 = V_14 ;
F_5 ( & V_4 -> V_2 ) ;
} else {
if ( V_4 -> V_5 ) {
V_4 -> V_6 ( V_4 -> V_7 , V_14 ,
NULL , NULL ) ;
V_4 -> V_5 = 0 ;
} else
F_6 ( V_4 -> V_7 , V_14 ) ;
}
}
static int F_7 ( struct V_9 * V_10 ,
unsigned long * V_17 , unsigned long * V_18 )
{
struct V_3 * V_4 =
F_2 ( V_10 , struct V_3 , V_13 ) ;
V_4 -> V_5 = 1 ;
return V_4 -> V_6 ( V_4 -> V_7 , V_19 ,
V_17 , V_18 ) ;
}
static int F_8 ( const struct V_20 * V_21 ,
struct V_3 * V_4 , struct V_22 * V_23 ,
int (* F_9)( struct V_24 * , int , unsigned long * ,
unsigned long * ) )
{
int V_25 , V_26 ;
V_4 -> V_7 = V_21 -> V_7 ;
if ( ! V_4 -> V_7 ) {
unsigned long V_27 = 0 ;
if ( ! F_10 ( V_21 -> V_28 ) ) {
F_11 ( V_23 , L_1 ,
V_21 -> V_28 , V_21 -> V_29 ) ;
return 0 ;
}
if ( V_21 -> V_30 )
V_27 |= V_31 ;
V_25 = F_12 ( V_23 , V_21 -> V_28 , V_27 ,
V_21 -> V_29 ) ;
if ( V_25 < 0 )
return V_25 ;
V_4 -> V_7 = F_13 ( V_21 -> V_28 ) ;
if ( F_14 ( V_4 -> V_7 ) )
return F_15 ( V_4 -> V_7 ) ;
}
V_4 -> V_13 . V_29 = V_21 -> V_29 ;
V_4 -> V_13 . V_32 = V_21 -> V_32 ;
V_4 -> V_16 = F_16 ( V_4 -> V_7 ) ;
V_4 -> V_5 = 0 ;
if ( F_9 ) {
V_4 -> V_6 = F_9 ;
V_4 -> V_13 . F_9 = F_7 ;
}
V_4 -> V_13 . V_33 = F_4 ;
if ( V_21 -> V_34 == V_35 )
V_26 = ! ! F_17 ( V_4 -> V_7 ) ;
else
V_26 = ( V_21 -> V_34 == V_36 ) ;
V_4 -> V_13 . V_37 = V_26 ? V_38 : V_15 ;
if ( ! V_21 -> V_39 )
V_4 -> V_13 . V_27 |= V_40 ;
V_25 = F_18 ( V_4 -> V_7 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
F_19 ( & V_4 -> V_2 , F_1 ) ;
return F_20 ( V_23 , & V_4 -> V_13 ) ;
}
static void F_21 ( struct V_3 * V_41 )
{
F_22 ( & V_41 -> V_13 ) ;
F_23 ( & V_41 -> V_2 ) ;
}
static inline int F_24 ( int V_42 )
{
return sizeof( struct V_43 ) +
( sizeof( struct V_3 ) * V_42 ) ;
}
static struct V_43 * F_25 ( struct V_44 * V_45 )
{
struct V_22 * V_46 = & V_45 -> V_46 ;
struct V_47 * V_48 ;
struct V_43 * V_49 ;
int V_50 , V_25 ;
struct V_51 * V_52 ;
V_50 = F_26 ( V_46 ) ;
if ( ! V_50 )
return F_27 ( - V_53 ) ;
V_49 = F_28 ( V_46 , F_24 ( V_50 ) , V_54 ) ;
if ( ! V_49 )
return F_27 ( - V_55 ) ;
F_29 (dev, child) {
struct V_20 V_41 = {} ;
const char * V_26 = NULL ;
V_41 . V_7 = F_30 ( V_46 , NULL , V_48 ) ;
if ( F_14 ( V_41 . V_7 ) ) {
F_31 ( V_48 ) ;
V_25 = F_15 ( V_41 . V_7 ) ;
goto V_56;
}
V_52 = F_32 ( V_48 ) ;
if ( F_33 ( V_48 , L_2 ) ) {
F_34 ( V_48 , L_2 , & V_41 . V_29 ) ;
} else {
if ( F_35 ( V_57 ) && ! V_41 . V_29 && V_52 )
V_41 . V_29 = V_52 -> V_29 ;
if ( ! V_41 . V_29 ) {
V_25 = - V_58 ;
goto V_56;
}
}
F_34 ( V_48 , L_3 ,
& V_41 . V_32 ) ;
if ( ! F_34 ( V_48 , L_4 ,
& V_26 ) ) {
if ( ! strcmp ( V_26 , L_5 ) )
V_41 . V_34 = V_35 ;
else if ( ! strcmp ( V_26 , L_6 ) )
V_41 . V_34 = V_36 ;
else
V_41 . V_34 = V_59 ;
}
if ( F_33 ( V_48 , L_7 ) )
V_41 . V_39 = 1 ;
V_25 = F_8 ( & V_41 , & V_49 -> V_60 [ V_49 -> V_42 ] ,
V_46 , NULL ) ;
if ( V_25 < 0 ) {
F_31 ( V_48 ) ;
goto V_56;
}
V_49 -> V_42 ++ ;
}
return V_49 ;
V_56:
for ( V_50 = V_49 -> V_42 - 1 ; V_50 >= 0 ; V_50 -- )
F_21 ( & V_49 -> V_60 [ V_50 ] ) ;
return F_27 ( V_25 ) ;
}
static int F_36 ( struct V_44 * V_45 )
{
struct V_61 * V_62 = F_37 ( & V_45 -> V_46 ) ;
struct V_43 * V_49 ;
int V_63 , V_25 = 0 ;
if ( V_62 && V_62 -> V_42 ) {
V_49 = F_28 ( & V_45 -> V_46 ,
F_24 ( V_62 -> V_42 ) ,
V_54 ) ;
if ( ! V_49 )
return - V_55 ;
V_49 -> V_42 = V_62 -> V_42 ;
for ( V_63 = 0 ; V_63 < V_49 -> V_42 ; V_63 ++ ) {
V_25 = F_8 ( & V_62 -> V_60 [ V_63 ] ,
& V_49 -> V_60 [ V_63 ] ,
& V_45 -> V_46 , V_62 -> F_7 ) ;
if ( V_25 < 0 ) {
for ( V_63 = V_63 - 1 ; V_63 >= 0 ; V_63 -- )
F_21 ( & V_49 -> V_60 [ V_63 ] ) ;
return V_25 ;
}
}
} else {
V_49 = F_25 ( V_45 ) ;
if ( F_14 ( V_49 ) )
return F_15 ( V_49 ) ;
}
F_38 ( V_45 , V_49 ) ;
return 0 ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_43 * V_49 = F_40 ( V_45 ) ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_49 -> V_42 ; V_63 ++ )
F_21 ( & V_49 -> V_60 [ V_63 ] ) ;
return 0 ;
}
static void F_41 ( struct V_44 * V_45 )
{
struct V_43 * V_49 = F_40 ( V_45 ) ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_49 -> V_42 ; V_63 ++ ) {
struct V_3 * V_41 = & V_49 -> V_60 [ V_63 ] ;
F_4 ( & V_41 -> V_13 , V_15 ) ;
}
}
