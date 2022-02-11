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
V_8 -> V_24 -> V_25 -> V_26 ,
type == V_13 ? L_2 : L_5 ,
V_9 [ type ] , V_18 ) ;
} else {
if ( ! V_3 )
continue;
V_3 = F_11 ( V_8 -> V_11 [ type ] ,
& V_9 [ type ] ) ;
if ( V_3 )
F_10 ( V_4 , V_3 ) ;
F_5 ( V_12 , L_6 ,
V_8 -> V_24 -> V_25 -> V_26 ,
type == V_13 ? L_2 : L_5 ,
V_9 [ type ] , V_3 ) ;
}
}
return V_18 ;
}
static unsigned
F_12 ( struct V_27 * V_28 , const void * V_29 , unsigned V_30 )
{
return F_13 ( * ( ( V_31 * ) V_29 ) , V_30 ) ;
}
static int
F_14 ( const void * V_29 , struct V_32 * V_33 )
{
struct V_1 * V_3 ;
T_1 V_34 ;
F_15 ( V_29 ) ;
V_34 = * ( ( T_1 * ) V_29 ) ;
V_3 = F_16 ( V_33 , struct V_1 , V_22 ) ;
return V_34 == V_3 -> V_6 ;
}
static void *
F_17 ( struct V_32 * V_33 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( V_33 , struct V_1 , V_22 ) ;
return & V_3 -> V_6 ;
}
static void *
F_18 ( struct V_32 * V_33 )
{
return F_16 ( V_33 , struct V_1 , V_22 ) ;
}
static void
F_19 ( struct V_27 * V_28 , struct V_32 * V_33 )
{
}
static void
F_20 ( struct V_27 * V_28 , struct V_32 * V_33 )
{
}
static void
F_21 ( struct V_27 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( V_33 , struct V_1 , V_22 ) ;
F_10 ( V_4 , V_3 ) ;
}
int F_22 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = & V_36 -> V_37 . V_8 ;
int V_38 , type ;
for ( type = 0 ; type < V_10 ; type ++ ) {
V_8 -> V_11 [ type ] = F_23 ( L_7 ,
V_39 ,
V_40 ,
V_41 ,
0 ,
V_42 ,
V_43 ,
& V_44 ,
V_45 ) ;
if ( ! V_8 -> V_11 [ type ] )
break;
}
if ( type == V_10 )
return 0 ;
for ( V_38 = 0 ; V_38 < type ; V_38 ++ )
F_24 ( V_8 -> V_11 [ V_38 ] ) ;
return - V_21 ;
}
int F_25 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = & V_36 -> V_37 . V_8 ;
int type ;
for ( type = 0 ; type < V_10 ; type ++ )
F_24 ( V_8 -> V_11 [ type ] ) ;
return 0 ;
}
int F_26 ( struct V_35 * V_46 , struct V_47 * exp ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_48 * V_52 ;
int V_18 ;
V_51 = F_27 ( F_28 ( exp ) ,
& V_53 , V_54 ,
V_55 ) ;
if ( ! V_51 )
return - V_21 ;
V_52 = F_29 ( & V_51 -> V_56 , & V_57 ) ;
* V_52 = * V_49 ;
F_30 ( V_51 ) ;
F_31 ( V_51 ) ;
V_51 -> V_58 = 1 ;
V_18 = F_32 ( V_51 ) ;
if ( V_18 )
F_33 ( L_8 , V_18 ) ;
if ( V_51 -> V_59 ) {
V_52 = F_34 ( & V_51 -> V_56 , & V_57 ) ;
if ( V_52 ) {
* V_49 = * V_52 ;
} else if ( ! V_18 ) {
F_33 ( L_9 ) ;
V_18 = - V_60 ;
}
} else if ( ! V_18 ) {
F_33 ( L_9 ) ;
V_18 = - V_60 ;
}
F_35 ( V_51 ) ;
return V_18 ;
}
int F_36 ( struct V_35 * V_46 , struct V_47 * exp ,
struct V_48 * V_49 )
{
struct V_7 * V_8 = & exp -> V_61 -> V_37 . V_8 ;
struct V_50 * V_51 ;
struct V_48 * V_62 ;
int V_18 ;
V_51 = F_27 ( F_28 ( exp ) ,
& V_63 , V_54 ,
V_64 ) ;
if ( ! V_51 )
return - V_21 ;
V_62 = F_29 ( & V_51 -> V_56 , & V_57 ) ;
* V_62 = * V_49 ;
F_30 ( V_51 ) ;
V_8 -> V_65 = - V_66 ;
V_18 = F_32 ( V_51 ) ;
if ( V_18 )
V_8 -> V_65 = V_18 ;
F_35 ( V_51 ) ;
return V_18 ;
}
int F_37 ( struct V_47 * exp , struct V_67 * V_68 )
{
struct V_7 * V_8 = & exp -> V_61 -> V_37 . V_8 ;
int V_18 ;
V_68 -> V_69 = V_8 -> V_70 ;
memcpy ( V_68 -> V_71 , V_72 , strlen ( V_72 ) ) ;
V_18 = V_8 -> V_65 ;
if ( V_18 == V_73 )
V_18 = - V_74 ;
return V_18 ;
}
