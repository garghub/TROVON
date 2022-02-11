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
T_1 V_2 = V_3 -> V_5 ;
F_5 ( V_2 == V_8 [ type ] ,
L_1 ,
V_2 , V_8 [ type ] ) ;
F_6 ( V_11 , L_2 ,
type == V_12 ? L_3 : L_4 , V_8 [ type ] ) ;
return V_13 ;
}
}
return V_14 ;
}
int F_7 ( struct V_6 * V_7 , const unsigned int V_8 [] ,
T_2 V_15 , T_2 V_16 )
{
int type ;
int V_17 = 0 ;
if ( ( V_15 & ( V_18 | V_19 ) ) == 0 )
return 0 ;
for ( type = 0 ; type < V_9 ; type ++ ) {
struct V_1 * V_3 ;
if ( ( V_15 & F_8 ( type ) ) == 0 )
continue;
V_3 = F_4 ( V_7 -> V_10 [ type ] , & V_8 [ type ] ) ;
if ( ( V_16 & F_9 ( type ) ) != 0 ) {
if ( V_3 != NULL )
continue;
V_3 = F_1 ( V_8 [ type ] ) ;
if ( V_3 == NULL ) {
V_17 = - V_20 ;
break;
}
V_17 = F_10 ( V_7 -> V_10 [ type ] ,
& V_8 [ type ] , & V_3 -> V_21 ) ;
if ( V_17 == - V_22 ) {
V_17 = 0 ;
F_11 ( V_3 , V_4 ) ;
}
F_6 ( V_11 , L_5 ,
V_7 -> V_23 -> V_24 -> V_25 ,
type == V_12 ? L_3 : L_6 ,
V_8 [ type ] , V_17 ) ;
} else {
if ( V_3 == NULL )
continue;
V_3 = F_12 ( V_7 -> V_10 [ type ] ,
& V_8 [ type ] ) ;
if ( V_3 )
F_11 ( V_3 , V_4 ) ;
F_6 ( V_11 , L_7 ,
V_7 -> V_23 -> V_24 -> V_25 ,
type == V_12 ? L_3 : L_6 ,
V_8 [ type ] , V_3 ) ;
}
}
return V_17 ;
}
static unsigned
F_13 ( T_3 * V_26 , const void * V_27 , unsigned V_28 )
{
return F_14 ( * ( ( V_29 * ) V_27 ) , V_28 ) ;
}
static int
F_15 ( const void * V_27 , struct V_30 * V_31 )
{
struct V_1 * V_3 ;
T_1 V_32 ;
F_16 ( V_27 != NULL ) ;
V_32 = * ( ( T_1 * ) V_27 ) ;
V_3 = F_17 ( V_31 , struct V_1 , V_21 ) ;
return V_32 == V_3 -> V_5 ;
}
static void *
F_18 ( struct V_30 * V_31 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( V_31 , struct V_1 , V_21 ) ;
return & V_3 -> V_5 ;
}
static void *
F_19 ( struct V_30 * V_31 )
{
return F_17 ( V_31 , struct V_1 , V_21 ) ;
}
static void
F_20 ( T_3 * V_26 , struct V_30 * V_31 )
{
}
static void
F_21 ( T_3 * V_26 , struct V_30 * V_31 )
{
}
static void
F_22 ( T_3 * V_26 , struct V_30 * V_31 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( V_31 , struct V_1 , V_21 ) ;
F_11 ( V_3 , V_4 ) ;
}
int F_23 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = & V_34 -> V_35 . V_7 ;
int V_36 , type ;
for ( type = 0 ; type < V_9 ; type ++ ) {
V_7 -> V_10 [ type ] = F_24 ( L_8 ,
V_37 ,
V_38 ,
V_39 ,
0 ,
V_40 ,
V_41 ,
& V_42 ,
V_43 ) ;
if ( V_7 -> V_10 [ type ] == NULL )
break;
}
if ( type == V_9 )
return 0 ;
for ( V_36 = 0 ; V_36 < type ; V_36 ++ )
F_25 ( V_7 -> V_10 [ V_36 ] ) ;
return - V_20 ;
}
int F_26 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = & V_34 -> V_35 . V_7 ;
int type ;
for ( type = 0 ; type < V_9 ; type ++ )
F_25 ( V_7 -> V_10 [ type ] ) ;
return 0 ;
}
int F_27 ( struct V_33 * V_44 , struct V_45 * exp ,
struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_46 * V_50 ;
int V_17 ;
V_49 = F_28 ( F_29 ( exp ) ,
& V_51 , V_52 ,
V_53 ) ;
if ( V_49 == NULL )
return - V_20 ;
V_50 = F_30 ( & V_49 -> V_54 , & V_55 ) ;
* V_50 = * V_47 ;
F_31 ( V_49 ) ;
F_32 ( V_49 ) ;
V_49 -> V_56 = 1 ;
V_17 = F_33 ( V_49 ) ;
if ( V_17 )
F_34 ( L_9 , V_17 ) ;
if ( V_49 -> V_57 &&
( V_50 = F_35 ( & V_49 -> V_54 , & V_55 ) ) ) {
* V_47 = * V_50 ;
} else if ( ! V_17 ) {
F_34 ( L_10 ) ;
V_17 = - V_58 ;
}
F_36 ( V_49 ) ;
return V_17 ;
}
int F_37 ( struct V_33 * V_44 , struct V_45 * exp ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = & exp -> V_59 -> V_35 . V_7 ;
struct V_48 * V_49 ;
struct V_46 * V_60 ;
int V_17 ;
V_49 = F_28 ( F_29 ( exp ) ,
& V_61 , V_52 ,
V_62 ) ;
if ( V_49 == NULL )
return - V_20 ;
V_60 = F_30 ( & V_49 -> V_54 , & V_55 ) ;
* V_60 = * V_47 ;
F_31 ( V_49 ) ;
V_7 -> V_63 = - V_64 ;
V_17 = F_33 ( V_49 ) ;
if ( V_17 )
V_7 -> V_63 = V_17 ;
F_36 ( V_49 ) ;
return V_17 ;
}
int F_38 ( struct V_45 * exp , struct V_65 * V_66 )
{
struct V_6 * V_7 = & exp -> V_59 -> V_35 . V_7 ;
int V_17 ;
V_66 -> V_67 = V_7 -> V_68 ;
memcpy ( V_66 -> V_69 , V_70 , strlen ( V_70 ) ) ;
V_17 = V_7 -> V_63 ;
if ( V_17 == V_71 )
V_17 = - V_72 ;
return V_17 ;
}
