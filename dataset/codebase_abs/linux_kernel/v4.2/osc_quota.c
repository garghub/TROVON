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
for ( type = 0 ; type < V_9 ; type ++ ) {
struct V_1 * V_3 ;
V_3 = F_4 ( V_7 -> V_10 [ type ] , & V_8 [ type ] ) ;
if ( V_3 ) {
F_5 ( V_11 , L_1 ,
type == V_12 ? L_2 : L_3 , V_8 [ type ] ) ;
return V_13 ;
}
}
return V_14 ;
}
int F_6 ( struct V_6 * V_7 , const unsigned int V_8 [] ,
T_1 V_15 , T_1 V_16 )
{
int type ;
int V_17 = 0 ;
if ( ( V_15 & ( V_18 | V_19 ) ) == 0 )
return 0 ;
for ( type = 0 ; type < V_9 ; type ++ ) {
struct V_1 * V_3 ;
if ( ( V_15 & F_7 ( type ) ) == 0 )
continue;
V_3 = F_4 ( V_7 -> V_10 [ type ] , & V_8 [ type ] ) ;
if ( ( V_16 & F_8 ( type ) ) != 0 ) {
if ( V_3 != NULL )
continue;
V_3 = F_1 ( V_8 [ type ] ) ;
if ( V_3 == NULL ) {
V_17 = - V_20 ;
break;
}
V_17 = F_9 ( V_7 -> V_10 [ type ] ,
& V_8 [ type ] , & V_3 -> V_21 ) ;
if ( V_17 == - V_22 ) {
V_17 = 0 ;
F_10 ( V_3 , V_4 ) ;
}
F_5 ( V_11 , L_4 ,
V_7 -> V_23 -> V_24 -> V_25 ,
type == V_12 ? L_2 : L_5 ,
V_8 [ type ] , V_17 ) ;
} else {
if ( V_3 == NULL )
continue;
V_3 = F_11 ( V_7 -> V_10 [ type ] ,
& V_8 [ type ] ) ;
if ( V_3 )
F_10 ( V_3 , V_4 ) ;
F_5 ( V_11 , L_6 ,
V_7 -> V_23 -> V_24 -> V_25 ,
type == V_12 ? L_2 : L_5 ,
V_8 [ type ] , V_3 ) ;
}
}
return V_17 ;
}
static unsigned
F_12 ( struct V_26 * V_27 , const void * V_28 , unsigned V_29 )
{
return F_13 ( * ( ( V_30 * ) V_28 ) , V_29 ) ;
}
static int
F_14 ( const void * V_28 , struct V_31 * V_32 )
{
struct V_1 * V_3 ;
T_1 V_33 ;
F_15 ( V_28 != NULL ) ;
V_33 = * ( ( T_1 * ) V_28 ) ;
V_3 = F_16 ( V_32 , struct V_1 , V_21 ) ;
return V_33 == V_3 -> V_5 ;
}
static void *
F_17 ( struct V_31 * V_32 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( V_32 , struct V_1 , V_21 ) ;
return & V_3 -> V_5 ;
}
static void *
F_18 ( struct V_31 * V_32 )
{
return F_16 ( V_32 , struct V_1 , V_21 ) ;
}
static void
F_19 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
}
static void
F_20 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
}
static void
F_21 ( struct V_26 * V_27 , struct V_31 * V_32 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( V_32 , struct V_1 , V_21 ) ;
F_10 ( V_3 , V_4 ) ;
}
int F_22 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = & V_35 -> V_36 . V_7 ;
int V_37 , type ;
for ( type = 0 ; type < V_9 ; type ++ ) {
V_7 -> V_10 [ type ] = F_23 ( L_7 ,
V_38 ,
V_39 ,
V_40 ,
0 ,
V_41 ,
V_42 ,
& V_43 ,
V_44 ) ;
if ( V_7 -> V_10 [ type ] == NULL )
break;
}
if ( type == V_9 )
return 0 ;
for ( V_37 = 0 ; V_37 < type ; V_37 ++ )
F_24 ( V_7 -> V_10 [ V_37 ] ) ;
return - V_20 ;
}
int F_25 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = & V_35 -> V_36 . V_7 ;
int type ;
for ( type = 0 ; type < V_9 ; type ++ )
F_24 ( V_7 -> V_10 [ type ] ) ;
return 0 ;
}
int F_26 ( struct V_34 * V_45 , struct V_46 * exp ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_47 * V_51 ;
int V_17 ;
V_50 = F_27 ( F_28 ( exp ) ,
& V_52 , V_53 ,
V_54 ) ;
if ( V_50 == NULL )
return - V_20 ;
V_51 = F_29 ( & V_50 -> V_55 , & V_56 ) ;
* V_51 = * V_48 ;
F_30 ( V_50 ) ;
F_31 ( V_50 ) ;
V_50 -> V_57 = 1 ;
V_17 = F_32 ( V_50 ) ;
if ( V_17 )
F_33 ( L_8 , V_17 ) ;
if ( V_50 -> V_58 ) {
V_51 = F_34 ( & V_50 -> V_55 , & V_56 ) ;
if ( V_51 ) {
* V_48 = * V_51 ;
} else if ( ! V_17 ) {
F_33 ( L_9 ) ;
V_17 = - V_59 ;
}
} else if ( ! V_17 ) {
F_33 ( L_9 ) ;
V_17 = - V_59 ;
}
F_35 ( V_50 ) ;
return V_17 ;
}
int F_36 ( struct V_34 * V_45 , struct V_46 * exp ,
struct V_47 * V_48 )
{
struct V_6 * V_7 = & exp -> V_60 -> V_36 . V_7 ;
struct V_49 * V_50 ;
struct V_47 * V_61 ;
int V_17 ;
V_50 = F_27 ( F_28 ( exp ) ,
& V_62 , V_53 ,
V_63 ) ;
if ( V_50 == NULL )
return - V_20 ;
V_61 = F_29 ( & V_50 -> V_55 , & V_56 ) ;
* V_61 = * V_48 ;
F_30 ( V_50 ) ;
V_7 -> V_64 = - V_65 ;
V_17 = F_32 ( V_50 ) ;
if ( V_17 )
V_7 -> V_64 = V_17 ;
F_35 ( V_50 ) ;
return V_17 ;
}
int F_37 ( struct V_46 * exp , struct V_66 * V_67 )
{
struct V_6 * V_7 = & exp -> V_60 -> V_36 . V_7 ;
int V_17 ;
V_67 -> V_68 = V_7 -> V_69 ;
memcpy ( V_67 -> V_70 , V_71 , strlen ( V_71 ) ) ;
V_17 = V_7 -> V_64 ;
if ( V_17 == V_72 )
V_17 = - V_73 ;
return V_17 ;
}
