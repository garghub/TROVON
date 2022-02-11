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
static int T_1 F_8 ( const struct V_21 * V_22 ,
struct V_3 * V_4 , struct V_23 * V_24 ,
int (* F_9)( unsigned , int , unsigned long * , unsigned long * ) )
{
int V_25 , V_26 ;
V_4 -> V_7 = - 1 ;
if ( ! F_10 ( V_22 -> V_7 ) ) {
F_11 ( V_27 L_1 ,
V_22 -> V_7 , V_22 -> V_28 ) ;
return 0 ;
}
V_25 = F_12 ( V_22 -> V_7 , V_22 -> V_28 ) ;
if ( V_25 < 0 )
return V_25 ;
V_4 -> V_13 . V_28 = V_22 -> V_28 ;
V_4 -> V_13 . V_29 = V_22 -> V_29 ;
V_4 -> V_7 = V_22 -> V_7 ;
V_4 -> V_17 = F_13 ( V_22 -> V_7 ) ;
V_4 -> V_16 = V_22 -> V_16 ;
V_4 -> V_5 = 0 ;
if ( F_9 ) {
V_4 -> V_6 = F_9 ;
V_4 -> V_13 . F_9 = F_7 ;
}
V_4 -> V_13 . V_30 = F_4 ;
if ( V_22 -> V_31 == V_32 )
V_26 = ! ! F_14 ( V_4 -> V_7 ) ^ V_4 -> V_16 ;
else
V_26 = ( V_22 -> V_31 == V_33 ) ;
V_4 -> V_13 . V_34 = V_26 ? V_35 : V_15 ;
if ( ! V_22 -> V_36 )
V_4 -> V_13 . V_37 |= V_38 ;
V_25 = F_15 ( V_4 -> V_7 , V_4 -> V_16 ^ V_26 ) ;
if ( V_25 < 0 )
goto V_39;
F_16 ( & V_4 -> V_2 , F_1 ) ;
V_25 = F_17 ( V_24 , & V_4 -> V_13 ) ;
if ( V_25 < 0 )
goto V_39;
return 0 ;
V_39:
F_18 ( V_4 -> V_7 ) ;
return V_25 ;
}
static void F_19 ( struct V_3 * V_40 )
{
if ( ! F_10 ( V_40 -> V_7 ) )
return;
F_20 ( & V_40 -> V_13 ) ;
F_21 ( & V_40 -> V_2 ) ;
F_18 ( V_40 -> V_7 ) ;
}
static inline int F_22 ( int V_41 )
{
return sizeof( struct V_42 ) +
( sizeof( struct V_3 ) * V_41 ) ;
}
static struct V_42 * T_1 F_23 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_47 . V_48 , * V_49 ;
struct V_42 * V_50 ;
int V_51 , V_25 ;
V_51 = F_24 ( V_46 ) ;
if ( ! V_51 )
return NULL ;
V_50 = F_25 ( & V_44 -> V_47 , F_22 ( V_51 ) ,
V_52 ) ;
if ( ! V_50 )
return NULL ;
F_26 (np, child) {
struct V_21 V_40 = {} ;
enum V_53 V_37 ;
const char * V_26 ;
V_40 . V_7 = F_27 ( V_49 , 0 , & V_37 ) ;
V_40 . V_16 = V_37 & V_54 ;
V_40 . V_28 = F_28 ( V_49 , L_2 , NULL ) ? : V_49 -> V_28 ;
V_40 . V_29 =
F_28 ( V_49 , L_3 , NULL ) ;
V_26 = F_28 ( V_49 , L_4 , NULL ) ;
if ( V_26 ) {
if ( ! strcmp ( V_26 , L_5 ) )
V_40 . V_31 = V_32 ;
else if ( ! strcmp ( V_26 , L_6 ) )
V_40 . V_31 = V_33 ;
else
V_40 . V_31 = V_55 ;
}
V_25 = F_8 ( & V_40 , & V_50 -> V_56 [ V_50 -> V_41 ++ ] ,
& V_44 -> V_47 , NULL ) ;
if ( V_25 < 0 ) {
F_29 ( V_49 ) ;
goto V_39;
}
}
return V_50 ;
V_39:
for ( V_51 = V_50 -> V_41 - 2 ; V_51 >= 0 ; V_51 -- )
F_19 ( & V_50 -> V_56 [ V_51 ] ) ;
return NULL ;
}
static struct V_42 * T_1 F_23 ( struct V_43 * V_44 )
{
return NULL ;
}
static int T_1 F_30 ( struct V_43 * V_44 )
{
struct V_57 * V_58 = V_44 -> V_47 . V_59 ;
struct V_42 * V_50 ;
struct V_60 * V_60 ;
int V_61 , V_25 = 0 ;
V_60 = F_31 ( & V_44 -> V_47 ) ;
if ( F_32 ( V_60 ) )
F_33 ( & V_44 -> V_47 ,
L_7 ) ;
if ( V_58 && V_58 -> V_41 ) {
V_50 = F_25 ( & V_44 -> V_47 ,
F_22 ( V_58 -> V_41 ) ,
V_52 ) ;
if ( ! V_50 )
return - V_62 ;
V_50 -> V_41 = V_58 -> V_41 ;
for ( V_61 = 0 ; V_61 < V_50 -> V_41 ; V_61 ++ ) {
V_25 = F_8 ( & V_58 -> V_56 [ V_61 ] ,
& V_50 -> V_56 [ V_61 ] ,
& V_44 -> V_47 , V_58 -> F_7 ) ;
if ( V_25 < 0 ) {
for ( V_61 = V_61 - 1 ; V_61 >= 0 ; V_61 -- )
F_19 ( & V_50 -> V_56 [ V_61 ] ) ;
return V_25 ;
}
}
} else {
V_50 = F_23 ( V_44 ) ;
if ( ! V_50 )
return - V_63 ;
}
F_34 ( V_44 , V_50 ) ;
return 0 ;
}
static int T_2 F_35 ( struct V_43 * V_44 )
{
struct V_42 * V_50 = F_36 ( V_44 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_50 -> V_41 ; V_61 ++ )
F_19 ( & V_50 -> V_56 [ V_61 ] ) ;
F_34 ( V_44 , NULL ) ;
return 0 ;
}
