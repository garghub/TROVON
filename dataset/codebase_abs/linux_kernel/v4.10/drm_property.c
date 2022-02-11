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
int V_10 = 0 , V_24 ;
int V_49 ;
struct V_37 * V_38 ;
struct V_50 T_3 * V_51 ;
V_13 T_3 * V_52 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
F_29 ( V_7 ) ;
V_2 = F_30 ( V_7 , V_46 -> V_54 ) ;
if ( ! V_2 ) {
V_10 = - V_55 ;
goto V_56;
}
if ( F_21 ( V_2 , V_25 ) ||
F_21 ( V_2 , V_29 ) ) {
F_23 (prop_enum, &property->enum_list, head)
V_47 ++ ;
}
V_48 = V_2 -> V_9 ;
strncpy ( V_46 -> V_8 , V_2 -> V_8 , V_18 ) ;
V_46 -> V_8 [ V_18 - 1 ] = 0 ;
V_46 -> V_3 = V_2 -> V_3 ;
if ( ( V_46 -> V_57 >= V_48 ) && V_48 ) {
V_52 = ( V_13 T_3 * ) ( unsigned long ) V_46 -> V_52 ;
for ( V_24 = 0 ; V_24 < V_48 ; V_24 ++ ) {
if ( F_31 ( V_52 + V_24 , & V_2 -> V_12 [ V_24 ] , sizeof( V_13 ) ) ) {
V_10 = - V_58 ;
goto V_56;
}
}
}
V_46 -> V_57 = V_48 ;
if ( F_21 ( V_2 , V_25 ) ||
F_21 ( V_2 , V_29 ) ) {
if ( ( V_46 -> V_59 >= V_47 ) && V_47 ) {
V_49 = 0 ;
V_51 = (struct V_50 T_3 * ) ( unsigned long ) V_46 -> V_60 ;
F_23 (prop_enum, &property->enum_list, head) {
if ( F_31 ( & V_51 [ V_49 ] . V_36 , & V_38 -> V_36 , sizeof( V_13 ) ) ) {
V_10 = - V_58 ;
goto V_56;
}
if ( F_31 ( & V_51 [ V_49 ] . V_8 ,
& V_38 -> V_8 , V_18 ) ) {
V_10 = - V_58 ;
goto V_56;
}
V_49 ++ ;
}
}
V_46 -> V_59 = V_47 ;
}
if ( F_21 ( V_2 , V_61 ) )
V_46 -> V_59 = 0 ;
V_56:
F_32 ( V_7 ) ;
return V_10 ;
}
static void F_33 ( struct V_62 * V_62 )
{
struct V_63 * V_64 =
F_34 ( V_62 , struct V_63 , V_15 . V_65 ) ;
F_35 ( & V_64 -> V_7 -> V_20 . V_66 ) ;
F_25 ( & V_64 -> V_67 ) ;
F_36 ( & V_64 -> V_7 -> V_20 . V_66 ) ;
F_26 ( V_64 -> V_7 , & V_64 -> V_15 ) ;
F_9 ( V_64 ) ;
}
struct V_63 *
F_37 ( struct V_6 * V_7 , T_4 V_68 ,
const void * V_42 )
{
struct V_63 * V_64 ;
int V_10 ;
if ( ! V_68 || V_68 > V_69 - sizeof( struct V_63 ) )
return F_38 ( - V_39 ) ;
V_64 = F_3 ( sizeof( struct V_63 ) + V_68 , V_11 ) ;
if ( ! V_64 )
return F_38 ( - V_40 ) ;
F_6 ( & V_64 -> V_70 ) ;
V_64 -> V_68 = V_68 ;
V_64 -> V_7 = V_7 ;
if ( V_42 )
memcpy ( V_64 -> V_42 , V_42 , V_68 ) ;
V_10 = F_39 ( V_7 , & V_64 -> V_15 , V_71 ,
true , F_33 ) ;
if ( V_10 ) {
F_9 ( V_64 ) ;
return F_38 ( - V_39 ) ;
}
F_35 ( & V_7 -> V_20 . V_66 ) ;
F_7 ( & V_64 -> V_67 ,
& V_7 -> V_20 . V_72 ) ;
F_36 ( & V_7 -> V_20 . V_66 ) ;
return V_64 ;
}
void F_40 ( struct V_63 * V_64 )
{
if ( ! V_64 )
return;
F_41 ( & V_64 -> V_15 ) ;
}
void F_42 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
struct V_63 * V_64 , * V_73 ;
F_24 (blob, bt, &file_priv->blobs, head_file) {
F_43 ( & V_64 -> V_70 ) ;
F_40 ( V_64 ) ;
}
}
struct V_63 * F_44 ( struct V_63 * V_64 )
{
F_45 ( & V_64 -> V_15 ) ;
return V_64 ;
}
struct V_63 * F_46 ( struct V_6 * V_7 ,
T_2 V_74 )
{
struct V_75 * V_76 ;
struct V_63 * V_64 = NULL ;
V_76 = F_47 ( V_7 , V_74 , V_71 ) ;
if ( V_76 )
V_64 = F_48 ( V_76 ) ;
return V_64 ;
}
int F_49 ( struct V_6 * V_7 ,
struct V_63 * * V_77 ,
T_4 V_68 ,
const void * V_42 ,
struct V_75 * V_78 ,
struct V_1 * V_79 )
{
struct V_63 * V_80 = NULL ;
struct V_63 * V_81 = NULL ;
int V_10 ;
F_8 ( V_77 == NULL ) ;
V_81 = * V_77 ;
if ( V_68 && V_42 ) {
V_80 = F_37 ( V_7 , V_68 , V_42 ) ;
if ( F_50 ( V_80 ) )
return F_51 ( V_80 ) ;
}
if ( V_78 ) {
V_10 = F_52 ( V_78 ,
V_79 ,
V_80 ?
V_80 -> V_15 . V_74 : 0 ) ;
if ( V_10 != 0 )
goto V_82;
}
F_40 ( V_81 ) ;
* V_77 = V_80 ;
return 0 ;
V_82:
F_40 ( V_80 ) ;
return V_10 ;
}
int F_53 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_83 * V_46 = V_42 ;
struct V_63 * V_64 ;
int V_10 = 0 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_64 = F_46 ( V_7 , V_46 -> V_84 ) ;
if ( ! V_64 )
return - V_55 ;
if ( V_46 -> V_68 == V_64 -> V_68 ) {
if ( F_31 ( F_54 ( V_46 -> V_42 ) ,
V_64 -> V_42 ,
V_64 -> V_68 ) ) {
V_10 = - V_58 ;
goto V_85;
}
}
V_46 -> V_68 = V_64 -> V_68 ;
V_85:
F_40 ( V_64 ) ;
return V_10 ;
}
int F_55 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_86 * V_46 = V_42 ;
struct V_63 * V_64 ;
int V_10 = 0 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_64 = F_37 ( V_7 , V_46 -> V_68 , NULL ) ;
if ( F_50 ( V_64 ) )
return F_51 ( V_64 ) ;
if ( F_56 ( V_64 -> V_42 ,
F_54 ( V_46 -> V_42 ) ,
V_46 -> V_68 ) ) {
V_10 = - V_58 ;
goto V_87;
}
F_35 ( & V_7 -> V_20 . V_66 ) ;
V_46 -> V_84 = V_64 -> V_15 . V_74 ;
F_7 ( & V_64 -> V_70 , & V_44 -> V_88 ) ;
F_36 ( & V_7 -> V_20 . V_66 ) ;
return 0 ;
V_87:
F_40 ( V_64 ) ;
return V_10 ;
}
int F_57 ( struct V_6 * V_7 ,
void * V_42 , struct V_43 * V_44 )
{
struct V_89 * V_46 = V_42 ;
struct V_63 * V_64 = NULL , * V_73 ;
bool V_90 = false ;
int V_10 = 0 ;
if ( ! F_28 ( V_7 , V_53 ) )
return - V_39 ;
V_64 = F_46 ( V_7 , V_46 -> V_84 ) ;
if ( ! V_64 )
return - V_55 ;
F_35 ( & V_7 -> V_20 . V_66 ) ;
F_23 (bt, &file_priv->blobs, head_file) {
if ( V_73 == V_64 ) {
V_90 = true ;
break;
}
}
if ( ! V_90 ) {
V_10 = - V_91 ;
goto V_92;
}
F_43 ( & V_64 -> V_70 ) ;
F_36 ( & V_7 -> V_20 . V_66 ) ;
F_40 ( V_64 ) ;
F_40 ( V_64 ) ;
return 0 ;
V_92:
F_36 ( & V_7 -> V_20 . V_66 ) ;
F_40 ( V_64 ) ;
return V_10 ;
}
bool F_58 ( struct V_1 * V_2 ,
V_13 V_36 , struct V_75 * * V_93 )
{
int V_24 ;
if ( V_2 -> V_3 & V_94 )
return false ;
* V_93 = NULL ;
if ( F_21 ( V_2 , V_32 ) ) {
if ( V_36 < V_2 -> V_12 [ 0 ] || V_36 > V_2 -> V_12 [ 1 ] )
return false ;
return true ;
} else if ( F_21 ( V_2 , V_33 ) ) {
T_1 V_95 = F_59 ( V_36 ) ;
if ( V_95 < F_59 ( V_2 -> V_12 [ 0 ] ) ||
V_95 > F_59 ( V_2 -> V_12 [ 1 ] ) )
return false ;
return true ;
} else if ( F_21 ( V_2 , V_29 ) ) {
V_13 V_96 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_9 ; V_24 ++ )
V_96 |= ( 1ULL << V_2 -> V_12 [ V_24 ] ) ;
return ! ( V_36 & ~ V_96 ) ;
} else if ( F_21 ( V_2 , V_61 ) ) {
struct V_63 * V_64 ;
if ( V_36 == 0 )
return true ;
V_64 = F_46 ( V_2 -> V_7 , V_36 ) ;
if ( V_64 ) {
* V_93 = & V_64 -> V_15 ;
return true ;
} else {
return false ;
}
} else if ( F_21 ( V_2 , V_34 ) ) {
if ( V_36 == 0 )
return true ;
* V_93 = F_47 ( V_2 -> V_7 , V_36 ,
V_2 -> V_12 [ 0 ] ) ;
return * V_93 != NULL ;
}
for ( V_24 = 0 ; V_24 < V_2 -> V_9 ; V_24 ++ )
if ( V_2 -> V_12 [ V_24 ] == V_36 )
return true ;
return false ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_75 * V_93 )
{
if ( ! V_93 )
return;
if ( F_21 ( V_2 , V_34 ) ) {
F_41 ( V_93 ) ;
} else if ( F_21 ( V_2 , V_61 ) )
F_40 ( F_48 ( V_93 ) ) ;
}
