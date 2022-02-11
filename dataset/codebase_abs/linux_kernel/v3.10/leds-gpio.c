static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( V_4 -> V_5 ) {
V_4 -> V_6 ( V_4 -> V_7 ,
V_4 -> V_8 ,
NULL , NULL ) ;
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
if ( V_4 -> V_16 )
V_14 = ! V_14 ;
if ( V_4 -> V_17 ) {
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
unsigned long * V_18 , unsigned long * V_19 )
{
struct V_3 * V_4 =
F_2 ( V_10 , struct V_3 , V_13 ) ;
V_4 -> V_5 = 1 ;
return V_4 -> V_6 ( V_4 -> V_7 , V_20 ,
V_18 , V_19 ) ;
}
static int F_8 ( const struct V_21 * V_22 ,
struct V_3 * V_4 , struct V_23 * V_24 ,
int (* F_9)( unsigned , int , unsigned long * , unsigned long * ) )
{
int V_25 , V_26 ;
V_4 -> V_7 = - 1 ;
if ( ! F_10 ( V_22 -> V_7 ) ) {
F_11 ( V_24 , L_1 ,
V_22 -> V_7 , V_22 -> V_27 ) ;
return 0 ;
}
V_25 = F_12 ( V_24 , V_22 -> V_7 , V_22 -> V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_4 -> V_13 . V_27 = V_22 -> V_27 ;
V_4 -> V_13 . V_28 = V_22 -> V_28 ;
V_4 -> V_7 = V_22 -> V_7 ;
V_4 -> V_17 = F_13 ( V_22 -> V_7 ) ;
V_4 -> V_16 = V_22 -> V_16 ;
V_4 -> V_5 = 0 ;
if ( F_9 ) {
V_4 -> V_6 = F_9 ;
V_4 -> V_13 . F_9 = F_7 ;
}
V_4 -> V_13 . V_29 = F_4 ;
if ( V_22 -> V_30 == V_31 )
V_26 = ! ! F_14 ( V_4 -> V_7 ) ^ V_4 -> V_16 ;
else
V_26 = ( V_22 -> V_30 == V_32 ) ;
V_4 -> V_13 . V_33 = V_26 ? V_34 : V_15 ;
if ( ! V_22 -> V_35 )
V_4 -> V_13 . V_36 |= V_37 ;
V_25 = F_15 ( V_4 -> V_7 , V_4 -> V_16 ^ V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
F_16 ( & V_4 -> V_2 , F_1 ) ;
V_25 = F_17 ( V_24 , & V_4 -> V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static void F_18 ( struct V_3 * V_38 )
{
if ( ! F_10 ( V_38 -> V_7 ) )
return;
F_19 ( & V_38 -> V_13 ) ;
F_20 ( & V_38 -> V_2 ) ;
}
static inline int F_21 ( int V_39 )
{
return sizeof( struct V_40 ) +
( sizeof( struct V_3 ) * V_39 ) ;
}
static struct V_40 * F_22 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 . V_46 , * V_47 ;
struct V_40 * V_48 ;
int V_49 , V_25 ;
V_49 = F_23 ( V_44 ) ;
if ( ! V_49 )
return F_24 ( - V_50 ) ;
F_25 (np, child)
if ( F_26 ( V_47 , 0 ) == - V_51 )
return F_24 ( - V_51 ) ;
V_48 = F_27 ( & V_42 -> V_45 , F_21 ( V_49 ) ,
V_52 ) ;
if ( ! V_48 )
return F_24 ( - V_53 ) ;
F_25 (np, child) {
struct V_21 V_38 = {} ;
enum V_54 V_36 ;
const char * V_26 ;
V_38 . V_7 = F_28 ( V_47 , 0 , & V_36 ) ;
V_38 . V_16 = V_36 & V_55 ;
V_38 . V_27 = F_29 ( V_47 , L_2 , NULL ) ? : V_47 -> V_27 ;
V_38 . V_28 =
F_29 ( V_47 , L_3 , NULL ) ;
V_26 = F_29 ( V_47 , L_4 , NULL ) ;
if ( V_26 ) {
if ( ! strcmp ( V_26 , L_5 ) )
V_38 . V_30 = V_31 ;
else if ( ! strcmp ( V_26 , L_6 ) )
V_38 . V_30 = V_32 ;
else
V_38 . V_30 = V_56 ;
}
V_25 = F_8 ( & V_38 , & V_48 -> V_57 [ V_48 -> V_39 ++ ] ,
& V_42 -> V_45 , NULL ) ;
if ( V_25 < 0 ) {
F_30 ( V_47 ) ;
goto V_58;
}
}
return V_48 ;
V_58:
for ( V_49 = V_48 -> V_39 - 2 ; V_49 >= 0 ; V_49 -- )
F_18 ( & V_48 -> V_57 [ V_49 ] ) ;
return F_24 ( - V_50 ) ;
}
static struct V_40 * F_22 ( struct V_41 * V_42 )
{
return F_24 ( - V_50 ) ;
}
static int F_31 ( struct V_41 * V_42 )
{
struct V_59 * V_60 = V_42 -> V_45 . V_61 ;
struct V_40 * V_48 ;
struct V_62 * V_62 ;
int V_63 , V_25 = 0 ;
V_62 = F_32 ( & V_42 -> V_45 ) ;
if ( F_33 ( V_62 ) )
F_34 ( & V_42 -> V_45 ,
L_7 ) ;
if ( V_60 && V_60 -> V_39 ) {
V_48 = F_27 ( & V_42 -> V_45 ,
F_21 ( V_60 -> V_39 ) ,
V_52 ) ;
if ( ! V_48 )
return - V_53 ;
V_48 -> V_39 = V_60 -> V_39 ;
for ( V_63 = 0 ; V_63 < V_48 -> V_39 ; V_63 ++ ) {
V_25 = F_8 ( & V_60 -> V_57 [ V_63 ] ,
& V_48 -> V_57 [ V_63 ] ,
& V_42 -> V_45 , V_60 -> F_7 ) ;
if ( V_25 < 0 ) {
for ( V_63 = V_63 - 1 ; V_63 >= 0 ; V_63 -- )
F_18 ( & V_48 -> V_57 [ V_63 ] ) ;
return V_25 ;
}
}
} else {
V_48 = F_22 ( V_42 ) ;
if ( F_33 ( V_48 ) )
return F_35 ( V_48 ) ;
}
F_36 ( V_42 , V_48 ) ;
return 0 ;
}
static int F_37 ( struct V_41 * V_42 )
{
struct V_40 * V_48 = F_38 ( V_42 ) ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_48 -> V_39 ; V_63 ++ )
F_18 ( & V_48 -> V_57 [ V_63 ] ) ;
F_36 ( V_42 , NULL ) ;
return 0 ;
}
