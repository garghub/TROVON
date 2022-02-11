static bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return ! ( V_2 -> V_3 & V_5 ) ;
return ! ! ( V_2 -> V_3 & V_5 ) ;
}
struct V_1 * F_2 ( struct V_6 * V_7 , int V_3 ,
const char * V_8 , int V_9 )
{
struct V_1 * V_2 = NULL ;
int V_10 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_7 ;
if ( V_9 ) {
V_2 -> V_12 = F_4 ( V_9 , sizeof( V_13 ) ,
V_11 ) ;
if ( ! V_2 -> V_12 )
goto V_14;
}
V_10 = F_5 ( V_7 , & V_2 -> V_15 , V_16 ) ;
if ( V_10 )
goto V_14;
V_2 -> V_3 = V_3 ;
V_2 -> V_9 = V_9 ;
F_6 ( & V_2 -> V_17 ) ;
if ( V_8 ) {
strncpy ( V_2 -> V_8 , V_8 , V_18 ) ;
V_2 -> V_8 [ V_18 - 1 ] = '\0' ;
}
F_7 ( & V_2 -> V_19 , & V_7 -> V_20 . V_21 ) ;
F_8 ( ! F_1 ( V_2 ) ) ;
return V_2 ;
V_14:
F_9 ( V_2 -> V_12 ) ;
F_9 ( V_2 ) ;
return NULL ;
}
struct V_1 * F_10 ( struct V_6 * V_7 , int V_3 ,
const char * V_8 ,
const struct V_22 * V_23 ,
int V_9 )
{
struct V_1 * V_2 ;
int V_24 , V_10 ;
V_3 |= V_25 ;
V_2 = F_2 ( V_7 , V_3 , V_8 , V_9 ) ;
if ( ! V_2 )
return NULL ;
for ( V_24 = 0 ; V_24 < V_9 ; V_24 ++ ) {
V_10 = F_11 ( V_2 , V_24 ,
V_23 [ V_24 ] . type ,
V_23 [ V_24 ] . V_8 ) ;
if ( V_10 ) {
F_12 ( V_7 , V_2 ) ;
return NULL ;
}
}
return V_2 ;
}
struct V_1 * F_13 ( struct V_6 * V_7 ,
int V_3 , const char * V_8 ,
const struct V_22 * V_23 ,
int V_26 ,
V_13 V_27 )
{
struct V_1 * V_2 ;
int V_24 , V_10 , V_28 = 0 ;
int V_9 = F_14 ( V_27 ) ;
V_3 |= V_29 ;
V_2 = F_2 ( V_7 , V_3 , V_8 , V_9 ) ;
if ( ! V_2 )
return NULL ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
if ( ! ( V_27 & ( 1ULL << V_23 [ V_24 ] . type ) ) )
continue;
if ( F_8 ( V_28 >= V_9 ) ) {
F_12 ( V_7 , V_2 ) ;
return NULL ;
}
V_10 = F_11 ( V_2 , V_28 ++ ,
V_23 [ V_24 ] . type ,
V_23 [ V_24 ] . V_8 ) ;
if ( V_10 ) {
F_12 ( V_7 , V_2 ) ;
return NULL ;
}
}
return V_2 ;
}
static struct V_1 * F_15 ( struct V_6 * V_7 ,
int V_3 , const char * V_8 ,
V_13 V_30 , V_13 V_31 )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_7 , V_3 , V_8 , 2 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_12 [ 0 ] = V_30 ;
V_2 -> V_12 [ 1 ] = V_31 ;
return V_2 ;
}
struct V_1 * F_16 ( struct V_6 * V_7 , int V_3 ,
const char * V_8 ,
V_13 V_30 , V_13 V_31 )
{
return F_15 ( V_7 , V_32 | V_3 ,
V_8 , V_30 , V_31 ) ;
}
struct V_1 * F_17 ( struct V_6 * V_7 ,
int V_3 , const char * V_8 ,
T_1 V_30 , T_1 V_31 )
{
return F_15 ( V_7 , V_33 | V_3 ,
V_8 , F_18 ( V_30 ) , F_18 ( V_31 ) ) ;
}
struct V_1 * F_19 ( struct V_6 * V_7 ,
int V_3 , const char * V_8 ,
T_2 type )
{
struct V_1 * V_2 ;
V_3 |= V_34 ;
if ( F_8 ( ! ( V_3 & V_35 ) ) )
return NULL ;
V_2 = F_2 ( V_7 , V_3 , V_8 , 1 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_12 [ 0 ] = type ;
return V_2 ;
}
struct V_1 * F_20 ( struct V_6 * V_7 , int V_3 ,
const char * V_8 )
{
return F_16 ( V_7 , V_3 , V_8 , 0 , 1 ) ;
}
int F_11 ( struct V_1 * V_2 , int V_28 ,
V_13 V_36 , const char * V_8 )
{
struct V_37 * V_38 ;
if ( ! ( F_21 ( V_2 , V_25 ) ||
F_21 ( V_2 , V_29 ) ) )
return - V_39 ;
if ( F_21 ( V_2 , V_29 ) &&
( V_36 > 63 ) )
return - V_39 ;
if ( ! F_22 ( & V_2 -> V_17 ) ) {
F_23 (prop_enum, &property->enum_list, head) {
if ( V_38 -> V_36 == V_36 ) {
strncpy ( V_38 -> V_8 , V_8 , V_18 ) ;
V_38 -> V_8 [ V_18 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_38 = F_3 ( sizeof( struct V_37 ) , V_11 ) ;
if ( ! V_38 )
return - V_40 ;
strncpy ( V_38 -> V_8 , V_8 , V_18 ) ;
V_38 -> V_8 [ V_18 - 1 ] = '\0' ;
V_38 -> V_36 = V_36 ;
V_2 -> V_12 [ V_28 ] = V_36 ;
F_7 ( & V_38 -> V_19 , & V_2 -> V_17 ) ;
return 0 ;
}
void F_12 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_37 * V_38 , * V_41 ;
F_24 (prop_enum, pt, &property->enum_list, head) {
F_25 ( & V_38 -> V_19 ) ;
F_9 ( V_38 ) ;
}
if ( V_2 -> V_9 )
F_9 ( V_2 -> V_12 ) ;
F_26 ( V_7 , & V_2 -> V_15 ) ;
F_25 ( & V_2 -> V_19 ) ;
F_9 ( V_2 ) ;
}
int F_27 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_45 * V_46 = V_42 ;
struct V_1 * V_2 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_24 , V_49 ;
struct V_37 * V_38 ;
struct V_50 T_3 * V_51 ;
V_13 T_3 * V_52 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_2 = F_29 ( V_7 , V_46 -> V_54 ) ;
if ( ! V_2 )
return - V_55 ;
strncpy ( V_46 -> V_8 , V_2 -> V_8 , V_18 ) ;
V_46 -> V_8 [ V_18 - 1 ] = 0 ;
V_46 -> V_3 = V_2 -> V_3 ;
V_48 = V_2 -> V_9 ;
V_52 = F_30 ( V_46 -> V_52 ) ;
for ( V_24 = 0 ; V_24 < V_48 ; V_24 ++ ) {
if ( V_24 < V_46 -> V_56 &&
F_31 ( V_2 -> V_12 [ V_24 ] , V_52 + V_24 ) ) {
return - V_57 ;
}
}
V_46 -> V_56 = V_48 ;
V_49 = 0 ;
V_51 = F_30 ( V_46 -> V_58 ) ;
if ( F_21 ( V_2 , V_25 ) ||
F_21 ( V_2 , V_29 ) ) {
F_23 (prop_enum, &property->enum_list, head) {
V_47 ++ ;
if ( V_46 -> V_59 < V_47 )
continue;
if ( F_32 ( & V_51 [ V_49 ] . V_36 ,
& V_38 -> V_36 , sizeof( V_13 ) ) )
return - V_57 ;
if ( F_32 ( & V_51 [ V_49 ] . V_8 ,
& V_38 -> V_8 , V_18 ) )
return - V_57 ;
V_49 ++ ;
}
V_46 -> V_59 = V_47 ;
}
if ( F_21 ( V_2 , V_60 ) )
V_46 -> V_59 = 0 ;
return 0 ;
}
static void F_33 ( struct V_61 * V_61 )
{
struct V_62 * V_63 =
F_34 ( V_61 , struct V_62 , V_15 . V_64 ) ;
F_35 ( & V_63 -> V_7 -> V_20 . V_65 ) ;
F_25 ( & V_63 -> V_66 ) ;
F_36 ( & V_63 -> V_7 -> V_20 . V_65 ) ;
F_26 ( V_63 -> V_7 , & V_63 -> V_15 ) ;
F_9 ( V_63 ) ;
}
struct V_62 *
F_37 ( struct V_6 * V_7 , T_4 V_67 ,
const void * V_42 )
{
struct V_62 * V_63 ;
int V_10 ;
if ( ! V_67 || V_67 > V_68 - sizeof( struct V_62 ) )
return F_38 ( - V_39 ) ;
V_63 = F_3 ( sizeof( struct V_62 ) + V_67 , V_11 ) ;
if ( ! V_63 )
return F_38 ( - V_40 ) ;
F_6 ( & V_63 -> V_69 ) ;
V_63 -> V_67 = V_67 ;
V_63 -> V_7 = V_7 ;
if ( V_42 )
memcpy ( V_63 -> V_42 , V_42 , V_67 ) ;
V_10 = F_39 ( V_7 , & V_63 -> V_15 , V_70 ,
true , F_33 ) ;
if ( V_10 ) {
F_9 ( V_63 ) ;
return F_38 ( - V_39 ) ;
}
F_35 ( & V_7 -> V_20 . V_65 ) ;
F_7 ( & V_63 -> V_66 ,
& V_7 -> V_20 . V_71 ) ;
F_36 ( & V_7 -> V_20 . V_65 ) ;
return V_63 ;
}
void F_40 ( struct V_62 * V_63 )
{
if ( ! V_63 )
return;
F_41 ( & V_63 -> V_15 ) ;
}
void F_42 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
struct V_62 * V_63 , * V_72 ;
F_24 (blob, bt, &file_priv->blobs, head_file) {
F_43 ( & V_63 -> V_69 ) ;
F_40 ( V_63 ) ;
}
}
struct V_62 * F_44 ( struct V_62 * V_63 )
{
F_45 ( & V_63 -> V_15 ) ;
return V_63 ;
}
struct V_62 * F_46 ( struct V_6 * V_7 ,
T_2 V_73 )
{
struct V_74 * V_75 ;
struct V_62 * V_63 = NULL ;
V_75 = F_47 ( V_7 , V_73 , V_70 ) ;
if ( V_75 )
V_63 = F_48 ( V_75 ) ;
return V_63 ;
}
int F_49 ( struct V_6 * V_7 ,
struct V_62 * * V_76 ,
T_4 V_67 ,
const void * V_42 ,
struct V_74 * V_77 ,
struct V_1 * V_78 )
{
struct V_62 * V_79 = NULL ;
struct V_62 * V_80 = NULL ;
int V_10 ;
F_8 ( V_76 == NULL ) ;
V_80 = * V_76 ;
if ( V_67 && V_42 ) {
V_79 = F_37 ( V_7 , V_67 , V_42 ) ;
if ( F_50 ( V_79 ) )
return F_51 ( V_79 ) ;
}
if ( V_77 ) {
V_10 = F_52 ( V_77 ,
V_78 ,
V_79 ?
V_79 -> V_15 . V_73 : 0 ) ;
if ( V_10 != 0 )
goto V_81;
}
F_40 ( V_80 ) ;
* V_76 = V_79 ;
return 0 ;
V_81:
F_40 ( V_79 ) ;
return V_10 ;
}
int F_53 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_82 * V_46 = V_42 ;
struct V_62 * V_63 ;
int V_10 = 0 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_63 = F_46 ( V_7 , V_46 -> V_83 ) ;
if ( ! V_63 )
return - V_55 ;
if ( V_46 -> V_67 == V_63 -> V_67 ) {
if ( F_32 ( F_30 ( V_46 -> V_42 ) ,
V_63 -> V_42 ,
V_63 -> V_67 ) ) {
V_10 = - V_57 ;
goto V_84;
}
}
V_46 -> V_67 = V_63 -> V_67 ;
V_84:
F_40 ( V_63 ) ;
return V_10 ;
}
int F_54 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_85 * V_46 = V_42 ;
struct V_62 * V_63 ;
int V_10 = 0 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_63 = F_37 ( V_7 , V_46 -> V_67 , NULL ) ;
if ( F_50 ( V_63 ) )
return F_51 ( V_63 ) ;
if ( F_55 ( V_63 -> V_42 ,
F_30 ( V_46 -> V_42 ) ,
V_46 -> V_67 ) ) {
V_10 = - V_57 ;
goto V_86;
}
F_35 ( & V_7 -> V_20 . V_65 ) ;
V_46 -> V_83 = V_63 -> V_15 . V_73 ;
F_7 ( & V_63 -> V_69 , & V_44 -> V_87 ) ;
F_36 ( & V_7 -> V_20 . V_65 ) ;
return 0 ;
V_86:
F_40 ( V_63 ) ;
return V_10 ;
}
int F_56 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_88 * V_46 = V_42 ;
struct V_62 * V_63 = NULL , * V_72 ;
bool V_89 = false ;
int V_10 = 0 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_63 = F_46 ( V_7 , V_46 -> V_83 ) ;
if ( ! V_63 )
return - V_55 ;
F_35 ( & V_7 -> V_20 . V_65 ) ;
F_23 (bt, &file_priv->blobs, head_file) {
if ( V_72 == V_63 ) {
V_89 = true ;
break;
}
}
if ( ! V_89 ) {
V_10 = - V_90 ;
goto V_91;
}
F_43 ( & V_63 -> V_69 ) ;
F_36 ( & V_7 -> V_20 . V_65 ) ;
F_40 ( V_63 ) ;
F_40 ( V_63 ) ;
return 0 ;
V_91:
F_36 ( & V_7 -> V_20 . V_65 ) ;
F_40 ( V_63 ) ;
return V_10 ;
}
bool F_57 ( struct V_1 * V_2 ,
V_13 V_36 , struct V_74 * * V_92 )
{
int V_24 ;
if ( V_2 -> V_3 & V_93 )
return false ;
* V_92 = NULL ;
if ( F_21 ( V_2 , V_32 ) ) {
if ( V_36 < V_2 -> V_12 [ 0 ] || V_36 > V_2 -> V_12 [ 1 ] )
return false ;
return true ;
} else if ( F_21 ( V_2 , V_33 ) ) {
T_1 V_94 = F_58 ( V_36 ) ;
if ( V_94 < F_58 ( V_2 -> V_12 [ 0 ] ) ||
V_94 > F_58 ( V_2 -> V_12 [ 1 ] ) )
return false ;
return true ;
} else if ( F_21 ( V_2 , V_29 ) ) {
V_13 V_95 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_9 ; V_24 ++ )
V_95 |= ( 1ULL << V_2 -> V_12 [ V_24 ] ) ;
return ! ( V_36 & ~ V_95 ) ;
} else if ( F_21 ( V_2 , V_60 ) ) {
struct V_62 * V_63 ;
if ( V_36 == 0 )
return true ;
V_63 = F_46 ( V_2 -> V_7 , V_36 ) ;
if ( V_63 ) {
* V_92 = & V_63 -> V_15 ;
return true ;
} else {
return false ;
}
} else if ( F_21 ( V_2 , V_34 ) ) {
if ( V_36 == 0 )
return true ;
* V_92 = F_47 ( V_2 -> V_7 , V_36 ,
V_2 -> V_12 [ 0 ] ) ;
return * V_92 != NULL ;
}
for ( V_24 = 0 ; V_24 < V_2 -> V_9 ; V_24 ++ )
if ( V_2 -> V_12 [ V_24 ] == V_36 )
return true ;
return false ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_74 * V_92 )
{
if ( ! V_92 )
return;
if ( F_21 ( V_2 , V_34 ) ) {
F_41 ( V_92 ) ;
} else if ( F_21 ( V_2 , V_60 ) )
F_40 ( F_48 ( V_92 ) ) ;
}
