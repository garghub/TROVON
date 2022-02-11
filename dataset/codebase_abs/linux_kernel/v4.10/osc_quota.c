static inline struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_4 , V_5 ) ;
if ( V_3 )
V_3 -> V_6 = V_2 ;
return V_3 ;
}
int F_3 ( struct V_7 * V_8 , const unsigned int V_9 [] )
{
int type ;
for ( type = 0 ; type < V_10 ; type ++ ) {
struct V_1 * V_3 ;
V_3 = F_4 ( V_8 -> V_11 [ type ] , & V_9 [ type ] ) ;
if ( V_3 ) {
F_5 ( V_12 , L_1 ,
type == V_13 ? L_2 : L_3 , V_9 [ type ] ) ;
return V_14 ;
}
}
return V_15 ;
}
int F_6 ( struct V_7 * V_8 , const unsigned int V_9 [] ,
T_1 V_16 , T_1 V_17 )
{
int type ;
int V_18 = 0 ;
if ( ( V_16 & ( V_19 | V_20 ) ) == 0 )
return 0 ;
for ( type = 0 ; type < V_10 ; type ++ ) {
struct V_1 * V_3 ;
if ( ( V_16 & F_7 ( type ) ) == 0 )
continue;
V_3 = F_4 ( V_8 -> V_11 [ type ] , & V_9 [ type ] ) ;
if ( ( V_17 & F_8 ( type ) ) != 0 ) {
if ( V_3 )
continue;
V_3 = F_1 ( V_9 [ type ] ) ;
if ( ! V_3 ) {
V_18 = - V_21 ;
break;
}
V_18 = F_9 ( V_8 -> V_11 [ type ] ,
& V_9 [ type ] , & V_3 -> V_22 ) ;
if ( V_18 == - V_23 ) {
V_18 = 0 ;
F_10 ( V_4 , V_3 ) ;
}
F_5 ( V_12 , L_4 ,
F_11 ( V_8 ) ,
type == V_13 ? L_2 : L_5 ,
V_9 [ type ] , V_18 ) ;
} else {
if ( ! V_3 )
continue;
V_3 = F_12 ( V_8 -> V_11 [ type ] ,
& V_9 [ type ] ) ;
if ( V_3 )
F_10 ( V_4 , V_3 ) ;
F_5 ( V_12 , L_6 ,
F_11 ( V_8 ) ,
type == V_13 ? L_2 : L_5 ,
V_9 [ type ] , V_3 ) ;
}
}
return V_18 ;
}
static unsigned int
F_13 ( struct V_24 * V_25 , const void * V_26 , unsigned int V_27 )
{
return F_14 ( * ( ( V_28 * ) V_26 ) , V_27 ) ;
}
static int
F_15 ( const void * V_26 , struct V_29 * V_30 )
{
struct V_1 * V_3 ;
T_1 V_31 ;
F_16 ( V_26 ) ;
V_31 = * ( ( T_1 * ) V_26 ) ;
V_3 = F_17 ( V_30 , struct V_1 , V_22 ) ;
return V_31 == V_3 -> V_6 ;
}
static void *
F_18 ( struct V_29 * V_30 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( V_30 , struct V_1 , V_22 ) ;
return & V_3 -> V_6 ;
}
static void *
F_19 ( struct V_29 * V_30 )
{
return F_17 ( V_30 , struct V_1 , V_22 ) ;
}
static void
F_20 ( struct V_24 * V_25 , struct V_29 * V_30 )
{
}
static void
F_21 ( struct V_24 * V_25 , struct V_29 * V_30 )
{
}
static void
F_22 ( struct V_24 * V_25 , struct V_29 * V_30 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( V_30 , struct V_1 , V_22 ) ;
F_10 ( V_4 , V_3 ) ;
}
int F_23 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = & V_33 -> V_34 . V_8 ;
int V_35 , type ;
for ( type = 0 ; type < V_10 ; type ++ ) {
V_8 -> V_11 [ type ] = F_24 ( L_7 ,
V_36 ,
V_37 ,
V_38 ,
0 ,
V_39 ,
V_40 ,
& V_41 ,
V_42 ) ;
if ( ! V_8 -> V_11 [ type ] )
break;
}
if ( type == V_10 )
return 0 ;
for ( V_35 = 0 ; V_35 < type ; V_35 ++ )
F_25 ( V_8 -> V_11 [ V_35 ] ) ;
return - V_21 ;
}
int F_26 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = & V_33 -> V_34 . V_8 ;
int type ;
for ( type = 0 ; type < V_10 ; type ++ )
F_25 ( V_8 -> V_11 [ type ] ) ;
return 0 ;
}
int F_27 ( struct V_32 * V_43 , struct V_44 * exp ,
struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_45 * V_49 ;
int V_18 ;
V_48 = F_28 ( F_29 ( exp ) ,
& V_50 , V_51 ,
V_52 ) ;
if ( ! V_48 )
return - V_21 ;
V_49 = F_30 ( & V_48 -> V_53 , & V_54 ) ;
* V_49 = * V_46 ;
F_31 ( V_48 ) ;
F_32 ( V_48 ) ;
V_48 -> V_55 = 1 ;
V_18 = F_33 ( V_48 ) ;
if ( V_18 )
F_34 ( L_8 , V_18 ) ;
if ( V_48 -> V_56 ) {
V_49 = F_35 ( & V_48 -> V_53 , & V_54 ) ;
if ( V_49 ) {
* V_46 = * V_49 ;
} else if ( ! V_18 ) {
F_34 ( L_9 ) ;
V_18 = - V_57 ;
}
} else if ( ! V_18 ) {
F_34 ( L_9 ) ;
V_18 = - V_57 ;
}
F_36 ( V_48 ) ;
return V_18 ;
}
