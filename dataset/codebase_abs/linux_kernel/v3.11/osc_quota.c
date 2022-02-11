static inline struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 ( V_3 , V_4 ) ;
if ( V_3 != NULL )
V_3 -> V_5 = V_2 ;
return V_3 ;
}
int F_3 ( struct V_6 * V_7 , const unsigned int V_8 [] )
{
int type ;
V_9 ;
for ( type = 0 ; type < V_10 ; type ++ ) {
struct V_1 * V_3 ;
V_3 = F_4 ( V_7 -> V_11 [ type ] , & V_8 [ type ] ) ;
if ( V_3 ) {
T_1 V_2 = V_3 -> V_5 ;
F_5 ( V_2 == V_8 [ type ] ,
L_1 ,
V_2 , V_8 [ type ] ) ;
F_6 ( V_12 , L_2 ,
type == V_13 ? L_3 : L_4 , V_8 [ type ] ) ;
RETURN ( V_14 ) ;
}
}
RETURN ( V_15 ) ;
}
int F_7 ( struct V_6 * V_7 , const unsigned int V_8 [] ,
T_2 V_16 , T_2 V_17 )
{
int type ;
int V_18 = 0 ;
V_9 ;
if ( ( V_16 & ( V_19 | V_20 ) ) == 0 )
RETURN ( 0 ) ;
for ( type = 0 ; type < V_10 ; type ++ ) {
struct V_1 * V_3 ;
if ( ( V_16 & F_8 ( type ) ) == 0 )
continue;
V_3 = F_4 ( V_7 -> V_11 [ type ] , & V_8 [ type ] ) ;
if ( ( V_17 & F_9 ( type ) ) != 0 ) {
if ( V_3 != NULL )
continue;
V_3 = F_1 ( V_8 [ type ] ) ;
if ( V_3 == NULL ) {
V_18 = - V_21 ;
break;
}
V_18 = F_10 ( V_7 -> V_11 [ type ] ,
& V_8 [ type ] , & V_3 -> V_22 ) ;
if ( V_18 == - V_23 ) {
V_18 = 0 ;
F_11 ( V_3 , V_4 ) ;
}
F_6 ( V_12 , L_5 ,
V_7 -> V_24 -> V_25 -> V_26 ,
type == V_13 ? L_3 : L_6 ,
V_8 [ type ] , V_18 ) ;
} else {
if ( V_3 == NULL )
continue;
V_3 = F_12 ( V_7 -> V_11 [ type ] ,
& V_8 [ type ] ) ;
if ( V_3 )
F_11 ( V_3 , V_4 ) ;
F_6 ( V_12 , L_7 ,
V_7 -> V_24 -> V_25 -> V_26 ,
type == V_13 ? L_3 : L_6 ,
V_8 [ type ] , V_3 ) ;
}
}
RETURN ( V_18 ) ;
}
static unsigned
F_13 ( T_3 * V_27 , const void * V_28 , unsigned V_29 )
{
return F_14 ( * ( ( V_30 * ) V_28 ) , V_29 ) ;
}
static int
F_15 ( const void * V_28 , struct V_31 * V_32 )
{
struct V_1 * V_3 ;
T_1 V_33 ;
F_16 ( V_28 != NULL ) ;
V_33 = * ( ( T_1 * ) V_28 ) ;
V_3 = F_17 ( V_32 , struct V_1 , V_22 ) ;
return V_33 == V_3 -> V_5 ;
}
static void *
F_18 ( struct V_31 * V_32 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( V_32 , struct V_1 , V_22 ) ;
return & V_3 -> V_5 ;
}
static void *
F_19 ( struct V_31 * V_32 )
{
return F_17 ( V_32 , struct V_1 , V_22 ) ;
}
static void
F_20 ( T_3 * V_27 , struct V_31 * V_32 )
{
}
static void
F_21 ( T_3 * V_27 , struct V_31 * V_32 )
{
}
static void
F_22 ( T_3 * V_27 , struct V_31 * V_32 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( V_32 , struct V_1 , V_22 ) ;
F_11 ( V_3 , V_4 ) ;
}
int F_23 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = & V_35 -> V_36 . V_7 ;
int V_37 , type ;
V_9 ;
for ( type = 0 ; type < V_10 ; type ++ ) {
V_7 -> V_11 [ type ] = F_24 ( L_8 ,
V_38 ,
V_39 ,
V_40 ,
0 ,
V_41 ,
V_42 ,
& V_43 ,
V_44 ) ;
if ( V_7 -> V_11 [ type ] == NULL )
break;
}
if ( type == V_10 )
RETURN ( 0 ) ;
for ( V_37 = 0 ; V_37 < type ; V_37 ++ )
F_25 ( V_7 -> V_11 [ V_37 ] ) ;
RETURN ( - V_21 ) ;
}
int F_26 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = & V_35 -> V_36 . V_7 ;
int type ;
V_9 ;
for ( type = 0 ; type < V_10 ; type ++ )
F_25 ( V_7 -> V_11 [ type ] ) ;
RETURN ( 0 ) ;
}
int F_27 ( struct V_34 * V_45 , struct V_46 * exp ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_47 * V_51 ;
int V_18 ;
V_9 ;
V_50 = F_28 ( F_29 ( exp ) ,
& V_52 , V_53 ,
V_54 ) ;
if ( V_50 == NULL )
RETURN ( - V_21 ) ;
V_51 = F_30 ( & V_50 -> V_55 , & V_56 ) ;
* V_51 = * V_48 ;
F_31 ( V_50 ) ;
F_32 ( V_50 ) ;
V_50 -> V_57 = 1 ;
V_18 = F_33 ( V_50 ) ;
if ( V_18 )
F_34 ( L_9 , V_18 ) ;
if ( V_50 -> V_58 &&
( V_51 = F_35 ( & V_50 -> V_55 , & V_56 ) ) ) {
* V_48 = * V_51 ;
} else if ( ! V_18 ) {
F_34 ( L_10 ) ;
V_18 = - V_59 ;
}
F_36 ( V_50 ) ;
RETURN ( V_18 ) ;
}
int F_37 ( struct V_34 * V_45 , struct V_46 * exp ,
struct V_47 * V_48 )
{
struct V_6 * V_7 = & exp -> V_60 -> V_36 . V_7 ;
struct V_49 * V_50 ;
struct V_47 * V_61 ;
int V_18 ;
V_9 ;
V_50 = F_28 ( F_29 ( exp ) ,
& V_62 , V_53 ,
V_63 ) ;
if ( V_50 == NULL )
RETURN ( - V_21 ) ;
V_61 = F_30 ( & V_50 -> V_55 , & V_56 ) ;
* V_61 = * V_48 ;
F_31 ( V_50 ) ;
V_7 -> V_64 = - V_65 ;
V_18 = F_33 ( V_50 ) ;
if ( V_18 )
V_7 -> V_64 = V_18 ;
F_36 ( V_50 ) ;
RETURN ( V_18 ) ;
}
int F_38 ( struct V_46 * exp , struct V_66 * V_67 )
{
struct V_6 * V_7 = & exp -> V_60 -> V_36 . V_7 ;
int V_18 ;
V_9 ;
V_67 -> V_68 = V_7 -> V_69 ;
memcpy ( V_67 -> V_70 , V_71 , strlen ( V_71 ) ) ;
V_18 = V_7 -> V_64 ;
if ( V_18 == V_72 )
V_18 = - V_73 ;
RETURN ( V_18 ) ;
}
