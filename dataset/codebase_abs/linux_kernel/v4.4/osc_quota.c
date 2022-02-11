static inline struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_4 , V_5 | V_6 ) ;
if ( V_3 != NULL )
V_3 -> V_7 = V_2 ;
return V_3 ;
}
int F_3 ( struct V_8 * V_9 , const unsigned int V_10 [] )
{
int type ;
for ( type = 0 ; type < V_11 ; type ++ ) {
struct V_1 * V_3 ;
V_3 = F_4 ( V_9 -> V_12 [ type ] , & V_10 [ type ] ) ;
if ( V_3 ) {
F_5 ( V_13 , L_1 ,
type == V_14 ? L_2 : L_3 , V_10 [ type ] ) ;
return V_15 ;
}
}
return V_16 ;
}
int F_6 ( struct V_8 * V_9 , const unsigned int V_10 [] ,
T_1 V_17 , T_1 V_18 )
{
int type ;
int V_19 = 0 ;
if ( ( V_17 & ( V_20 | V_21 ) ) == 0 )
return 0 ;
for ( type = 0 ; type < V_11 ; type ++ ) {
struct V_1 * V_3 ;
if ( ( V_17 & F_7 ( type ) ) == 0 )
continue;
V_3 = F_4 ( V_9 -> V_12 [ type ] , & V_10 [ type ] ) ;
if ( ( V_18 & F_8 ( type ) ) != 0 ) {
if ( V_3 != NULL )
continue;
V_3 = F_1 ( V_10 [ type ] ) ;
if ( V_3 == NULL ) {
V_19 = - V_22 ;
break;
}
V_19 = F_9 ( V_9 -> V_12 [ type ] ,
& V_10 [ type ] , & V_3 -> V_23 ) ;
if ( V_19 == - V_24 ) {
V_19 = 0 ;
F_10 ( V_4 , V_3 ) ;
}
F_5 ( V_13 , L_4 ,
V_9 -> V_25 -> V_26 -> V_27 ,
type == V_14 ? L_2 : L_5 ,
V_10 [ type ] , V_19 ) ;
} else {
if ( V_3 == NULL )
continue;
V_3 = F_11 ( V_9 -> V_12 [ type ] ,
& V_10 [ type ] ) ;
if ( V_3 )
F_10 ( V_4 , V_3 ) ;
F_5 ( V_13 , L_6 ,
V_9 -> V_25 -> V_26 -> V_27 ,
type == V_14 ? L_2 : L_5 ,
V_10 [ type ] , V_3 ) ;
}
}
return V_19 ;
}
static unsigned
F_12 ( struct V_28 * V_29 , const void * V_30 , unsigned V_31 )
{
return F_13 ( * ( ( V_32 * ) V_30 ) , V_31 ) ;
}
static int
F_14 ( const void * V_30 , struct V_33 * V_34 )
{
struct V_1 * V_3 ;
T_1 V_35 ;
F_15 ( V_30 != NULL ) ;
V_35 = * ( ( T_1 * ) V_30 ) ;
V_3 = F_16 ( V_34 , struct V_1 , V_23 ) ;
return V_35 == V_3 -> V_7 ;
}
static void *
F_17 ( struct V_33 * V_34 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( V_34 , struct V_1 , V_23 ) ;
return & V_3 -> V_7 ;
}
static void *
F_18 ( struct V_33 * V_34 )
{
return F_16 ( V_34 , struct V_1 , V_23 ) ;
}
static void
F_19 ( struct V_28 * V_29 , struct V_33 * V_34 )
{
}
static void
F_20 ( struct V_28 * V_29 , struct V_33 * V_34 )
{
}
static void
F_21 ( struct V_28 * V_29 , struct V_33 * V_34 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( V_34 , struct V_1 , V_23 ) ;
F_10 ( V_4 , V_3 ) ;
}
int F_22 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = & V_37 -> V_38 . V_9 ;
int V_39 , type ;
for ( type = 0 ; type < V_11 ; type ++ ) {
V_9 -> V_12 [ type ] = F_23 ( L_7 ,
V_40 ,
V_41 ,
V_42 ,
0 ,
V_43 ,
V_44 ,
& V_45 ,
V_46 ) ;
if ( V_9 -> V_12 [ type ] == NULL )
break;
}
if ( type == V_11 )
return 0 ;
for ( V_39 = 0 ; V_39 < type ; V_39 ++ )
F_24 ( V_9 -> V_12 [ V_39 ] ) ;
return - V_22 ;
}
int F_25 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = & V_37 -> V_38 . V_9 ;
int type ;
for ( type = 0 ; type < V_11 ; type ++ )
F_24 ( V_9 -> V_12 [ type ] ) ;
return 0 ;
}
int F_26 ( struct V_36 * V_47 , struct V_48 * exp ,
struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_49 * V_53 ;
int V_19 ;
V_52 = F_27 ( F_28 ( exp ) ,
& V_54 , V_55 ,
V_56 ) ;
if ( V_52 == NULL )
return - V_22 ;
V_53 = F_29 ( & V_52 -> V_57 , & V_58 ) ;
* V_53 = * V_50 ;
F_30 ( V_52 ) ;
F_31 ( V_52 ) ;
V_52 -> V_59 = 1 ;
V_19 = F_32 ( V_52 ) ;
if ( V_19 )
F_33 ( L_8 , V_19 ) ;
if ( V_52 -> V_60 ) {
V_53 = F_34 ( & V_52 -> V_57 , & V_58 ) ;
if ( V_53 ) {
* V_50 = * V_53 ;
} else if ( ! V_19 ) {
F_33 ( L_9 ) ;
V_19 = - V_61 ;
}
} else if ( ! V_19 ) {
F_33 ( L_9 ) ;
V_19 = - V_61 ;
}
F_35 ( V_52 ) ;
return V_19 ;
}
int F_36 ( struct V_36 * V_47 , struct V_48 * exp ,
struct V_49 * V_50 )
{
struct V_8 * V_9 = & exp -> V_62 -> V_38 . V_9 ;
struct V_51 * V_52 ;
struct V_49 * V_63 ;
int V_19 ;
V_52 = F_27 ( F_28 ( exp ) ,
& V_64 , V_55 ,
V_65 ) ;
if ( V_52 == NULL )
return - V_22 ;
V_63 = F_29 ( & V_52 -> V_57 , & V_58 ) ;
* V_63 = * V_50 ;
F_30 ( V_52 ) ;
V_9 -> V_66 = - V_67 ;
V_19 = F_32 ( V_52 ) ;
if ( V_19 )
V_9 -> V_66 = V_19 ;
F_35 ( V_52 ) ;
return V_19 ;
}
int F_37 ( struct V_48 * exp , struct V_68 * V_69 )
{
struct V_8 * V_9 = & exp -> V_62 -> V_38 . V_9 ;
int V_19 ;
V_69 -> V_70 = V_9 -> V_71 ;
memcpy ( V_69 -> V_72 , V_73 , strlen ( V_73 ) ) ;
V_19 = V_9 -> V_66 ;
if ( V_19 == V_74 )
V_19 = - V_75 ;
return V_19 ;
}
