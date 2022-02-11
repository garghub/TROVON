static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( F_3 ( V_2 -> V_3 , true ) ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_3 = (struct V_4 * ) V_5 ;
F_4 ( V_2 ) ;
}
}
void F_5 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 , struct V_1 , V_7 ) ;
F_1 ( V_2 ) ;
}
struct V_1 * F_7 ( struct V_4 * V_3 , T_1 V_8 )
{
struct V_1 * V_9 ;
V_9 = F_8 ( sizeof( struct V_1 ) , V_8 ) ;
if ( V_9 ) {
F_9 ( & V_9 -> V_7 ) ;
F_10 ( V_9 -> V_3 , F_11 ( V_3 ) ) ;
}
return V_9 ;
}
void F_12 ( struct V_4 * V_10 , struct V_4 * V_9 )
{
struct V_4 * V_11 ;
F_13 ( ! V_10 ) ;
F_13 ( ! V_9 ) ;
F_13 ( ! F_14 ( & F_15 ( V_10 ) -> V_12 ) ) ;
V_11 = F_3 ( V_10 -> V_2 -> V_3 ,
& F_16 ( V_10 ) -> V_12 ) ;
F_10 ( V_10 -> V_2 -> V_3 , F_11 ( V_9 ) ) ;
V_10 -> V_13 |= V_14 ;
F_2 ( V_11 ) ;
}
static void F_17 ( struct V_4 * V_15 , struct V_4 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
V_9 -> V_2 = F_18 ( V_15 -> V_2 ) ;
F_12 ( V_15 , V_9 ) ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
int V_19 ;
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
F_13 ( ! V_17 -> V_20 . V_21 ) ;
F_13 ( ! V_18 -> V_20 . V_21 ) ;
if ( V_17 == V_18 )
return 0 ;
V_19 = V_17 -> V_22 - V_18 -> V_22 ;
if ( V_19 )
return V_19 ;
return strcmp ( V_17 -> V_20 . V_21 , V_18 -> V_20 . V_21 ) ;
}
static int F_21 ( struct V_23 * V_17 , struct V_23 * V_18 )
{
int V_19 ;
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
F_13 ( ! V_17 -> V_24 ) ;
F_13 ( ! V_18 -> V_24 ) ;
F_13 ( ! V_17 -> V_20 . V_21 ) ;
F_13 ( ! V_18 -> V_20 . V_21 ) ;
if ( V_17 == V_18 || V_17 -> V_20 . V_21 == V_18 -> V_20 . V_21 )
return 0 ;
V_19 = F_20 ( V_17 -> V_24 , V_18 -> V_24 ) ;
if ( V_19 )
return V_19 ;
return strcmp ( V_17 -> V_20 . V_21 , V_18 -> V_20 . V_21 ) ;
}
static int F_22 ( struct V_23 * * V_17 , int V_25 , struct V_23 * * V_18 , int V_26 )
{
int V_27 ;
F_13 ( ! V_17 ) ;
F_13 ( ! * V_17 ) ;
F_13 ( ! V_18 ) ;
F_13 ( ! * V_18 ) ;
F_13 ( V_25 <= 0 ) ;
F_13 ( V_26 <= 0 ) ;
for ( V_27 = 0 ; V_27 < V_25 && V_27 < V_26 ; V_27 ++ ) {
int V_19 = F_21 ( V_17 [ V_27 ] , V_18 [ V_27 ] ) ;
if ( V_19 != 0 )
return V_19 ;
}
return V_25 - V_26 ;
}
static bool F_23 ( struct V_23 * * V_28 , int V_29 )
{
int V_27 ;
F_13 ( ! V_28 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( F_24 ( V_28 [ V_27 ] ) )
return true ;
}
return false ;
}
static bool F_25 ( struct V_23 * * V_28 , int V_29 )
{
int V_27 ;
F_13 ( ! V_28 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ! F_26 ( V_28 [ V_27 ] ) )
return false ;
}
return true ;
}
static int F_27 ( const void * V_17 , const void * V_18 )
{
return F_21 ( * (struct V_23 * * ) V_17 , * (struct V_23 * * ) V_18 ) ;
}
static inline int F_28 ( struct V_23 * * V_28 , int V_29 )
{
int V_27 , V_30 , V_31 = 0 ;
F_13 ( V_29 < 1 ) ;
F_13 ( ! V_28 ) ;
V_30 = 0 ;
for ( V_27 = 1 ; V_27 < V_29 ; V_27 ++ ) {
int V_19 = F_21 ( V_28 [ V_30 ] , V_28 [ V_27 ] ) ;
F_13 ( V_19 > 0 , L_1 ) ;
if ( V_19 == 0 ) {
F_29 ( V_28 [ V_27 ] ) ;
V_31 ++ ;
continue;
}
V_30 ++ ;
if ( V_31 )
V_28 [ V_30 ] = V_28 [ V_27 ] ;
}
F_13 ( V_31 < 0 ) ;
return V_31 ;
}
int F_30 ( struct V_23 * * V_28 , int V_29 , int V_13 )
{
int V_27 , V_31 = 0 ;
F_13 ( V_29 < 1 ) ;
F_13 ( ! V_28 ) ;
if ( V_29 > 8 ) {
F_31 ( V_28 , V_29 , sizeof( struct V_23 * ) , F_27 , NULL ) ;
V_31 = F_28 ( V_28 , V_29 ) ;
goto V_32;
}
for ( V_27 = 1 ; V_27 < V_29 ; V_27 ++ ) {
struct V_23 * V_11 = V_28 [ V_27 ] ;
int V_30 , V_33 ;
for ( V_30 = V_27 - 1 - V_31 ; V_30 >= 0 ; V_30 -- ) {
int V_19 = F_21 ( V_28 [ V_30 ] , V_11 ) ;
if ( V_19 == 0 ) {
F_29 ( V_11 ) ;
V_31 ++ ;
goto V_34;
} else if ( V_19 < 0 )
break;
}
V_30 ++ ;
for ( V_33 = V_27 - V_31 ; V_33 > V_30 ; V_33 -- )
V_28 [ V_33 ] = V_28 [ V_33 - 1 ] ;
V_28 [ V_30 ] = V_11 ;
V_34:
;
}
F_13 ( V_31 < 0 ) ;
V_32:
if ( V_13 & V_35 )
V_28 [ V_29 - V_31 ] = NULL ;
return V_31 ;
}
static void F_32 ( struct V_4 * V_3 )
{
struct V_4 * V_11 ;
F_13 ( ! V_3 ) ;
if ( ! F_33 ( V_3 ) ) {
struct V_23 * V_36 ;
struct V_37 V_27 ;
F_34 ( V_3 -> V_21 ) ;
F_35 (i, label, profile) {
F_29 ( V_36 ) ;
V_3 -> V_28 [ V_27 . V_27 ] = (struct V_23 * )
( V_38 + ( long ) V_27 . V_27 ) ;
}
}
if ( F_3 ( V_3 -> V_2 -> V_3 , true ) == V_3 )
F_10 ( V_3 -> V_2 -> V_3 , NULL ) ;
F_36 ( V_3 -> V_39 ) ;
V_11 = F_3 ( V_3 -> V_2 -> V_3 , true ) ;
if ( V_11 == V_3 )
F_10 ( V_3 -> V_2 -> V_3 , NULL ) ;
F_19 ( V_3 -> V_2 ) ;
V_3 -> V_2 = (struct V_1 * ) V_5 + 1 ;
}
void F_37 ( struct V_4 * V_3 )
{
if ( ! V_3 )
return;
F_32 ( V_3 ) ;
F_4 ( V_3 ) ;
}
static void F_38 ( struct V_4 * V_3 )
{
if ( V_3 -> V_13 & V_40 )
F_39 ( F_16 ( V_3 ) ) ;
else if ( F_33 ( V_3 ) )
F_40 ( F_41 ( V_3 ) ) ;
else
F_37 ( V_3 ) ;
}
static void F_42 ( struct V_41 * V_42 )
{
struct V_4 * V_3 = F_6 ( V_42 , struct V_4 , V_43 ) ;
if ( V_3 -> V_13 & V_44 )
( void ) F_43 ( V_3 ) ;
F_38 ( V_3 ) ;
}
void F_44 ( struct V_6 * V_6 )
{
struct V_4 * V_3 = F_6 ( V_6 , struct V_4 , V_7 ) ;
struct V_16 * V_24 = F_16 ( V_3 ) ;
if ( ! V_24 ) {
F_38 ( V_3 ) ;
return;
}
F_13 ( F_33 ( V_3 ) &&
F_45 ( & V_3 -> V_28 [ 0 ] -> V_20 . V_45 ) ) ;
F_13 ( F_33 ( V_3 ) &&
F_45 ( & V_3 -> V_28 [ 0 ] -> V_20 . V_46 ) ) ;
F_46 ( & V_3 -> V_43 , F_42 ) ;
}
static void F_47 ( struct V_4 * V_3 , struct V_4 * V_9 )
{
if ( V_3 != V_9 )
F_37 ( V_9 ) ;
else
F_2 ( V_9 ) ;
}
bool F_48 ( struct V_4 * V_3 , int V_47 )
{
F_13 ( ! V_3 ) ;
F_13 ( V_47 < 1 ) ;
V_3 -> V_39 = F_49 () ;
if ( V_3 -> V_39 == V_48 )
return false ;
V_3 -> V_47 = V_47 ;
V_3 -> V_28 [ V_47 ] = NULL ;
F_9 ( & V_3 -> V_7 ) ;
F_50 ( & V_3 -> V_49 ) ;
return true ;
}
struct V_4 * F_51 ( int V_47 , struct V_1 * V_2 , T_1 V_8 )
{
struct V_4 * V_9 ;
F_13 ( V_47 < 1 ) ;
V_9 = F_8 ( sizeof( * V_9 ) + sizeof( struct V_23 * ) * ( V_47 + 1 ) ,
V_8 ) ;
F_52 ( L_2 , V_50 , V_9 ) ;
if ( ! V_9 )
goto V_51;
if ( ! F_48 ( V_9 , V_47 ) )
goto V_51;
if ( ! V_2 ) {
V_2 = F_7 ( V_9 , V_8 ) ;
if ( ! V_2 )
goto V_51;
} else
F_18 ( V_2 ) ;
V_9 -> V_2 = V_2 ;
return V_9 ;
V_51:
F_4 ( V_9 ) ;
return NULL ;
}
static int F_53 ( struct V_4 * V_17 , struct V_4 * V_18 )
{
F_13 ( ! V_18 ) ;
if ( V_17 == V_18 )
return 0 ;
return F_22 ( V_17 -> V_28 , V_17 -> V_47 , V_18 -> V_28 , V_18 -> V_47 ) ;
}
int F_54 ( struct V_4 * V_3 , int V_27 )
{
F_13 ( ! V_3 ) ;
F_13 ( V_27 < 0 ) ;
for (; V_27 < V_3 -> V_47 ; V_27 ++ ) {
if ( ! F_26 ( V_3 -> V_28 [ V_27 ] ) )
return V_27 ;
}
return V_27 ;
}
struct V_23 * F_55 ( struct V_37 * V_52 ,
struct V_4 * V_53 ,
struct V_4 * V_54 )
{
F_13 ( ! V_53 ) ;
F_13 ( ! V_52 ) ;
F_13 ( V_52 -> V_27 < 0 ) ;
F_13 ( V_52 -> V_27 > V_53 -> V_47 ) ;
F_13 ( ! V_54 ) ;
F_13 ( V_52 -> V_33 < 0 ) ;
F_13 ( V_52 -> V_33 > V_54 -> V_47 ) ;
while ( V_52 -> V_33 < V_54 -> V_47 && V_52 -> V_27 < V_53 -> V_47 ) {
int V_19 = F_21 ( V_54 -> V_28 [ V_52 -> V_33 ] , V_53 -> V_28 [ V_52 -> V_27 ] ) ;
if ( V_19 == 0 ) {
( V_52 -> V_33 ) ++ ;
( V_52 -> V_27 ) ++ ;
} else if ( V_19 > 0 )
( V_52 -> V_27 ) ++ ;
else
return V_54 -> V_28 [ ( V_52 -> V_33 ) ++ ] ;
}
if ( V_52 -> V_33 < V_54 -> V_47 )
return V_54 -> V_28 [ ( V_52 -> V_33 ) ++ ] ;
return NULL ;
}
bool F_56 ( struct V_4 * V_53 , struct V_4 * V_54 )
{
struct V_37 V_27 = { } ;
F_13 ( ! V_53 ) ;
F_13 ( ! V_54 ) ;
if ( V_54 == V_53 )
return true ;
return F_55 ( & V_27 , V_53 , V_54 ) == NULL ;
}
static bool F_57 ( struct V_4 * V_3 , struct V_4 * V_9 )
{
struct V_55 * V_56 = F_15 ( V_3 ) ;
F_13 ( ! V_56 ) ;
F_13 ( ! V_3 ) ;
F_13 ( ! F_14 ( & V_56 -> V_12 ) ) ;
if ( V_9 )
F_12 ( V_3 , V_9 ) ;
if ( ! F_58 ( V_3 ) )
F_59 ( V_3 ) ;
if ( V_3 -> V_13 & V_44 ) {
F_60 ( & V_3 -> V_49 , & V_56 -> V_57 ) ;
V_3 -> V_13 &= ~ V_44 ;
return true ;
}
return false ;
}
static bool F_61 ( struct V_4 * V_15 , struct V_4 * V_9 )
{
struct V_55 * V_56 = F_15 ( V_15 ) ;
F_13 ( ! V_56 ) ;
F_13 ( ! V_15 ) ;
F_13 ( ! V_9 ) ;
F_13 ( ! F_14 ( & V_56 -> V_12 ) ) ;
F_13 ( V_9 -> V_13 & V_44 ) ;
if ( ! F_58 ( V_15 ) )
F_59 ( V_15 ) ;
if ( V_15 -> V_13 & V_44 ) {
F_62 ( & V_15 -> V_49 , & V_9 -> V_49 , & V_56 -> V_57 ) ;
V_15 -> V_13 &= ~ V_44 ;
V_9 -> V_13 |= V_44 ;
return true ;
}
return false ;
}
static struct V_4 * F_63 ( struct V_55 * V_56 ,
struct V_4 * V_3 , bool V_58 )
{
struct V_59 * * V_9 , * V_60 = NULL ;
F_13 ( ! V_56 ) ;
F_13 ( ! V_3 ) ;
F_13 ( F_15 ( V_3 ) != V_56 ) ;
F_13 ( ! F_14 ( & V_56 -> V_12 ) ) ;
F_13 ( V_3 -> V_13 & V_44 ) ;
V_9 = & V_56 -> V_57 . V_59 ;
while ( * V_9 ) {
struct V_4 * V_61 = F_64 ( * V_9 , struct V_4 , V_49 ) ;
int V_62 = F_53 ( V_3 , V_61 ) ;
V_60 = * V_9 ;
if ( V_62 == 0 ) {
if ( ! V_58 && ! F_58 ( V_61 ) ) {
if ( F_65 ( V_61 ) )
return V_61 ;
} else
F_17 ( V_61 , V_3 ) ;
F_13 ( ! F_61 ( V_61 , V_3 ) ) ;
return F_11 ( V_3 ) ;
} else if ( V_62 < 0 )
V_9 = & ( ( * V_9 ) -> V_63 ) ;
else
V_9 = & ( ( * V_9 ) -> V_64 ) ;
}
F_66 ( & V_3 -> V_49 , V_60 , V_9 ) ;
F_67 ( & V_3 -> V_49 , & V_56 -> V_57 ) ;
V_3 -> V_13 |= V_44 ;
return F_11 ( V_3 ) ;
}
static struct V_4 * F_68 ( struct V_23 * * V_28 , int V_29 )
{
struct V_59 * V_49 ;
F_13 ( ! V_28 ) ;
F_13 ( ! * V_28 ) ;
F_13 ( V_29 <= 0 ) ;
V_49 = F_69 ( V_28 , V_29 ) -> V_57 . V_59 ;
while ( V_49 ) {
struct V_4 * V_61 = F_64 ( V_49 , struct V_4 , V_49 ) ;
int V_62 = F_22 ( V_61 -> V_28 , V_61 -> V_47 , V_28 , V_29 ) ;
if ( V_62 > 0 )
V_49 = V_49 -> V_63 ;
else if ( V_62 < 0 )
V_49 = V_49 -> V_64 ;
else
return F_65 ( V_61 ) ;
}
return NULL ;
}
static struct V_4 * F_70 ( struct V_4 * V_3 )
{
F_13 ( ! V_3 ) ;
return F_68 ( V_3 -> V_28 , V_3 -> V_47 ) ;
}
bool F_43 ( struct V_4 * V_3 )
{
struct V_55 * V_56 = F_15 ( V_3 ) ;
unsigned long V_13 ;
bool V_19 ;
F_13 ( ! V_56 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
V_19 = F_57 ( V_3 , F_72 ( F_16 ( V_3 ) ) ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
return V_19 ;
}
bool F_74 ( struct V_4 * V_15 , struct V_4 * V_9 )
{
unsigned long V_13 ;
bool V_19 ;
if ( F_75 ( V_15 , V_9 ) && F_16 ( V_15 ) == F_16 ( V_9 ) ) {
F_71 ( & F_15 ( V_15 ) -> V_12 , V_13 ) ;
if ( V_15 -> V_2 != V_9 -> V_2 )
F_17 ( V_15 , V_9 ) ;
else
F_12 ( V_15 , V_9 ) ;
V_19 = F_61 ( V_15 , V_9 ) ;
F_73 ( & F_15 ( V_15 ) -> V_12 , V_13 ) ;
} else {
struct V_4 * V_65 ;
struct V_55 * V_56 = F_15 ( V_15 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
V_19 = F_57 ( V_15 , V_9 ) ;
if ( F_16 ( V_15 ) != F_16 ( V_9 ) ) {
F_73 ( & V_56 -> V_12 , V_13 ) ;
V_56 = F_15 ( V_9 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
}
V_65 = F_63 ( V_56 , V_9 , true ) ;
V_19 = ( V_65 == V_9 ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
F_2 ( V_65 ) ;
}
return V_19 ;
}
static struct V_4 * F_76 ( struct V_23 * * V_28 , int V_29 )
{
struct V_55 * V_56 ;
struct V_4 * V_3 ;
unsigned long V_13 ;
F_13 ( ! V_28 ) ;
F_13 ( ! * V_28 ) ;
F_13 ( V_29 <= 0 ) ;
V_56 = F_69 ( V_28 , V_29 ) ;
F_77 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_68 ( V_28 , V_29 ) ;
F_78 ( & V_56 -> V_12 , V_13 ) ;
return V_3 ;
}
static struct V_4 * F_79 ( struct V_23 * * V_28 ,
int V_66 , T_1 V_8 )
{
struct V_4 * V_3 = NULL ;
struct V_55 * V_56 ;
unsigned long V_13 ;
struct V_4 * V_9 ;
int V_27 ;
F_13 ( ! V_28 ) ;
if ( V_66 == 1 )
return F_11 ( & V_28 [ 0 ] -> V_3 ) ;
V_56 = F_15 ( & V_28 [ V_66 - 1 ] -> V_3 ) ;
V_9 = F_51 ( V_66 , NULL , V_8 ) ;
if ( ! V_9 )
return NULL ;
for ( V_27 = 0 ; V_27 < V_66 ; V_27 ++ )
V_9 -> V_28 [ V_27 ] = F_80 ( V_28 [ V_27 ] ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_63 ( V_56 , V_9 , false ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
F_47 ( V_3 , V_9 ) ;
return V_3 ;
}
struct V_4 * F_81 ( struct V_23 * * V_28 , int V_66 ,
T_1 V_8 )
{
struct V_4 * V_3 = F_76 ( V_28 , V_66 ) ;
if ( V_3 )
return V_3 ;
return F_79 ( V_28 , V_66 , V_8 ) ;
}
struct V_4 * F_82 ( struct V_4 * V_3 )
{
F_13 ( ! V_3 ) ;
return F_76 ( V_3 -> V_28 , V_3 -> V_47 ) ;
}
struct V_4 * F_83 ( struct V_55 * V_56 , struct V_4 * V_3 )
{
struct V_4 * V_65 ;
unsigned long V_13 ;
F_13 ( ! V_56 ) ;
F_13 ( ! V_3 ) ;
if ( ! F_58 ( V_3 ) ) {
F_77 ( & V_56 -> V_12 , V_13 ) ;
V_65 = F_70 ( V_3 ) ;
F_78 ( & V_56 -> V_12 , V_13 ) ;
if ( V_65 )
return V_65 ;
}
F_71 ( & V_56 -> V_12 , V_13 ) ;
V_65 = F_63 ( V_56 , V_3 , false ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
return V_65 ;
}
struct V_23 * F_84 ( struct V_37 * V_52 ,
struct V_4 * V_17 ,
struct V_4 * V_18 )
{
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
F_13 ( ! V_52 ) ;
F_13 ( V_52 -> V_27 < 0 ) ;
F_13 ( V_52 -> V_27 > V_17 -> V_47 ) ;
F_13 ( V_52 -> V_33 < 0 ) ;
F_13 ( V_52 -> V_33 > V_18 -> V_47 ) ;
if ( V_52 -> V_27 < V_17 -> V_47 ) {
if ( V_52 -> V_33 < V_18 -> V_47 ) {
int V_19 = F_21 ( V_17 -> V_28 [ V_52 -> V_27 ] , V_18 -> V_28 [ V_52 -> V_33 ] ) ;
if ( V_19 > 0 )
return V_18 -> V_28 [ ( V_52 -> V_33 ) ++ ] ;
if ( V_19 == 0 )
( V_52 -> V_33 ) ++ ;
}
return V_17 -> V_28 [ ( V_52 -> V_27 ) ++ ] ;
}
if ( V_52 -> V_33 < V_18 -> V_47 )
return V_18 -> V_28 [ ( V_52 -> V_33 ) ++ ] ;
return NULL ;
}
static int F_85 ( struct V_4 * V_17 , struct V_4 * V_18 ,
struct V_4 * V_67 )
{
struct V_23 * V_68 = NULL ;
struct V_37 V_27 = { } ;
int V_69 ;
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
F_13 ( ! V_67 ) ;
for ( V_69 = 0 ;
V_69 < V_67 -> V_47 && ( V_68 = F_84 ( & V_27 , V_17 , V_18 ) ) ;
V_69 ++ ) {
int V_19 = F_21 ( V_68 , V_67 -> V_28 [ V_69 ] ) ;
if ( V_19 != 0 )
return V_19 ;
}
if ( V_68 )
return 1 ;
else if ( V_69 < V_67 -> V_47 )
return - 1 ;
return 0 ;
}
static struct V_4 * F_86 ( struct V_4 * V_9 ,
struct V_4 * V_17 ,
struct V_4 * V_18 )
{
struct V_4 * V_3 ;
struct V_55 * V_56 ;
struct V_23 * V_70 ;
struct V_37 V_27 ;
unsigned long V_13 ;
int V_69 = 0 , V_71 = 0 ;
bool V_72 = false ;
F_13 ( ! V_17 ) ;
F_13 ( V_17 -> V_47 < 0 ) ;
F_13 ( ! V_18 ) ;
F_13 ( V_18 -> V_47 < 0 ) ;
F_13 ( ! V_9 ) ;
F_13 ( V_9 -> V_47 < V_17 -> V_47 + V_18 -> V_47 ) ;
F_87 (i, a, b, next) {
F_13 ( ! V_70 ) ;
if ( F_24 ( V_70 ) ) {
V_9 -> V_28 [ V_69 ] = F_88 ( V_70 ) ;
F_13 ( ! V_9 -> V_28 [ V_69 ] -> V_3 . V_2 ) ;
F_13 ( ! V_9 -> V_28 [ V_69 ] -> V_3 . V_2 -> V_3 ) ;
if ( V_70 -> V_3 . V_2 != V_9 -> V_28 [ V_69 ] -> V_3 . V_2 )
V_71 ++ ;
V_69 ++ ;
V_72 = true ;
} else
V_9 -> V_28 [ V_69 ++ ] = F_80 ( V_70 ) ;
}
V_9 -> V_47 = V_69 ;
V_9 -> V_28 [ V_69 ] = NULL ;
if ( V_71 ) {
V_9 -> V_47 -= F_30 ( & V_9 -> V_28 [ 0 ] , V_9 -> V_47 ,
V_35 ) ;
if ( V_9 -> V_47 == 1 ) {
V_3 = F_11 ( & V_9 -> V_28 [ 0 ] -> V_3 ) ;
return V_3 ;
}
} else if ( ! V_72 ) {
if ( V_69 == V_17 -> V_47 )
return F_11 ( V_17 ) ;
else if ( V_69 == V_18 -> V_47 )
return F_11 ( V_18 ) ;
}
if ( F_25 ( V_9 -> V_28 , V_9 -> V_47 ) )
V_9 -> V_13 |= V_73 ;
V_56 = F_15 ( V_9 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_63 ( F_15 ( V_9 ) , V_9 , false ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
return V_3 ;
}
static struct V_55 * F_89 ( struct V_4 * V_17 ,
struct V_4 * V_18 )
{
struct V_16 * V_74 = F_16 ( V_17 ) ;
struct V_16 * V_75 = F_16 ( V_18 ) ;
if ( F_20 ( V_74 , V_75 ) <= 0 )
return & V_74 -> V_76 ;
return & V_75 -> V_76 ;
}
static struct V_4 * F_90 ( struct V_55 * V_56 ,
struct V_4 * V_17 ,
struct V_4 * V_18 )
{
struct V_59 * V_49 ;
F_13 ( ! V_56 ) ;
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
if ( V_17 == V_18 )
return F_70 ( V_17 ) ;
V_49 = V_56 -> V_57 . V_59 ;
while ( V_49 ) {
struct V_4 * V_61 = F_6 ( V_49 , struct V_4 ,
V_49 ) ;
int V_62 = F_85 ( V_17 , V_18 , V_61 ) ;
if ( V_62 < 0 )
V_49 = V_49 -> V_63 ;
else if ( V_62 > 0 )
V_49 = V_49 -> V_64 ;
else
return F_65 ( V_61 ) ;
}
return NULL ;
}
struct V_4 * F_91 ( struct V_4 * V_17 , struct V_4 * V_18 )
{
struct V_55 * V_56 ;
struct V_4 * V_3 , * V_77 = NULL , * V_78 = NULL ;
unsigned long V_13 ;
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
if ( F_58 ( V_17 ) )
V_17 = V_77 = F_92 ( V_17 ) ;
if ( F_58 ( V_18 ) )
V_18 = V_78 = F_92 ( V_18 ) ;
V_56 = F_89 ( V_17 , V_18 ) ;
F_77 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_90 ( V_56 , V_17 , V_18 ) ;
F_78 ( & V_56 -> V_12 , V_13 ) ;
F_2 ( V_77 ) ;
F_2 ( V_78 ) ;
return V_3 ;
}
struct V_4 * F_93 ( struct V_4 * V_17 , struct V_4 * V_18 ,
T_1 V_8 )
{
struct V_4 * V_3 = NULL ;
F_13 ( ! V_17 ) ;
F_13 ( ! V_18 ) ;
if ( V_17 == V_18 )
return F_92 ( V_17 ) ;
if ( ! V_3 ) {
struct V_4 * V_9 ;
V_17 = F_92 ( V_17 ) ;
V_18 = F_92 ( V_18 ) ;
V_9 = F_51 ( V_17 -> V_47 + V_18 -> V_47 , NULL , V_8 ) ;
if ( ! V_9 )
goto V_32;
V_3 = F_86 ( V_9 , V_17 , V_18 ) ;
F_47 ( V_3 , V_9 ) ;
V_32:
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
}
return V_3 ;
}
static inline bool F_94 ( struct V_23 * V_36 ,
struct V_4 * V_3 )
{
return F_95 ( V_36 -> V_24 , F_16 ( V_3 ) , true ) ;
}
static inline unsigned int F_96 ( struct V_23 * V_36 ,
struct V_23 * V_79 ,
unsigned int V_80 )
{
const char * V_81 ;
if ( V_36 -> V_24 == V_79 -> V_24 )
return F_97 ( V_36 -> V_82 . V_83 , V_80 , V_79 -> V_20 . V_21 ) ;
V_81 = F_98 ( V_36 -> V_24 , V_79 -> V_24 , true ) ;
V_80 = F_99 ( V_36 -> V_82 . V_83 , V_80 , L_3 , 1 ) ;
V_80 = F_97 ( V_36 -> V_82 . V_83 , V_80 , V_81 ) ;
V_80 = F_99 ( V_36 -> V_82 . V_83 , V_80 , L_3 , 1 ) ;
return F_97 ( V_36 -> V_82 . V_83 , V_80 , V_79 -> V_20 . V_21 ) ;
}
static int F_100 ( struct V_23 * V_36 ,
struct V_4 * V_3 ,
unsigned int V_80 , bool V_84 , T_2 V_85 ,
struct V_86 * V_87 )
{
struct V_23 * V_79 ;
struct V_37 V_27 ;
F_35 (i, label, tp) {
if ( ! F_95 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_96 ( V_36 , V_79 , V_80 ) ;
if ( ! V_80 )
goto V_51;
goto V_70;
}
* V_87 = V_88 ;
return 0 ;
V_70:
F_101 (i, label, tp) {
if ( ! F_95 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_97 ( V_36 -> V_82 . V_83 , V_80 , L_4 ) ;
V_80 = F_96 ( V_36 , V_79 , V_80 ) ;
if ( ! V_80 )
goto V_51;
}
F_102 ( V_36 -> V_82 . V_83 , V_80 , V_87 ) ;
F_103 ( V_36 , V_87 ) ;
if ( ( V_87 -> V_89 & V_85 ) != V_85 )
return - V_90 ;
return 0 ;
V_51:
* V_87 = V_91 ;
return V_80 ;
}
static int F_104 ( struct V_23 * V_36 ,
struct V_4 * V_3 , unsigned int V_92 ,
bool V_84 , T_2 V_85 ,
struct V_86 * V_87 )
{
struct V_23 * V_79 ;
struct V_37 V_27 ;
struct V_86 V_11 ;
unsigned int V_80 = 0 ;
F_35 (i, label, tp) {
if ( ! F_95 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_96 ( V_36 , V_79 , V_92 ) ;
if ( ! V_80 )
goto V_51;
goto V_70;
}
return 0 ;
V_70:
F_102 ( V_36 -> V_82 . V_83 , V_80 , & V_11 ) ;
F_103 ( V_36 , & V_11 ) ;
F_105 ( V_87 , & V_11 ) ;
F_101 (i, label, tp) {
if ( ! F_95 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_96 ( V_36 , V_79 , V_92 ) ;
if ( ! V_80 )
goto V_51;
F_102 ( V_36 -> V_82 . V_83 , V_80 , & V_11 ) ;
F_103 ( V_36 , & V_11 ) ;
F_105 ( V_87 , & V_11 ) ;
}
if ( ( V_87 -> V_89 & V_85 ) != V_85 )
return - V_90 ;
return 0 ;
V_51:
* V_87 = V_91 ;
return - V_90 ;
}
int F_106 ( struct V_23 * V_36 , struct V_4 * V_3 ,
unsigned int V_80 , bool V_84 , T_2 V_85 ,
struct V_86 * V_87 )
{
int error = F_100 ( V_36 , V_3 , V_80 , V_84 , V_85 ,
V_87 ) ;
if ( ! error )
return error ;
* V_87 = V_88 ;
return F_104 ( V_36 , V_3 , V_80 , V_84 , V_85 ,
V_87 ) ;
}
bool F_107 ( struct V_16 * V_24 , struct V_4 * V_3 , T_1 V_8 )
{
struct V_55 * V_56 ;
unsigned long V_13 ;
char T_3 * V_93 ;
bool V_19 = false ;
F_13 ( ! V_24 ) ;
F_13 ( ! V_3 ) ;
if ( V_3 -> V_21 || F_16 ( V_3 ) != V_24 )
return V_19 ;
if ( F_108 ( & V_93 , V_24 , V_3 , V_94 , V_8 ) == - 1 )
return V_19 ;
V_56 = F_15 ( V_3 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
if ( ! V_3 -> V_21 && V_3 -> V_13 & V_44 ) {
V_3 -> V_21 = V_93 ;
V_19 = true ;
} else
F_34 ( V_93 ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
return V_19 ;
}
static inline bool F_109 ( struct V_16 * V_24 , struct V_4 * V_3 )
{
if ( V_3 -> V_21 && F_16 ( V_3 ) == V_24 )
return true ;
return false ;
}
static int F_110 ( char * V_95 , T_4 V_47 , struct V_16 * V_96 ,
struct V_23 * V_36 , int V_13 ,
struct V_16 * * V_97 )
{
const char * V_81 = NULL ;
F_13 ( ! V_95 && V_47 != 0 ) ;
F_13 ( ! V_36 ) ;
if ( ! V_96 )
V_96 = F_111 ( V_36 ) ;
if ( V_96 != V_36 -> V_24 &&
( ! V_97 || ( V_97 && * V_97 != V_36 -> V_24 ) ) ) {
if ( V_97 )
* V_97 = V_36 -> V_24 ;
V_81 = F_98 ( V_96 , V_36 -> V_24 ,
V_13 & V_98 ) ;
if ( V_81 == V_99 ) {
if ( V_13 & V_100 )
return snprintf ( V_95 , V_47 , L_5 , L_6 ) ;
return snprintf ( V_95 , V_47 , L_5 , V_81 ) ;
}
}
if ( ( V_13 & V_101 ) && V_36 != V_36 -> V_24 -> V_102 ) {
const char * V_103 = V_104 [ V_36 -> V_105 ] ;
if ( V_81 )
return snprintf ( V_95 , V_47 , L_7 , V_81 ,
V_36 -> V_20 . V_21 , V_103 ) ;
return snprintf ( V_95 , V_47 , L_8 , V_36 -> V_20 . V_21 ,
V_103 ) ;
}
if ( V_81 )
return snprintf ( V_95 , V_47 , L_9 , V_81 ,
V_36 -> V_20 . V_21 ) ;
return snprintf ( V_95 , V_47 , L_5 , V_36 -> V_20 . V_21 ) ;
}
static const char * F_112 ( struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 )
{
struct V_23 * V_36 ;
struct V_37 V_27 ;
int V_105 = - 1 , V_7 = 0 ;
F_35 (i, label, profile) {
if ( F_95 ( V_24 , V_36 -> V_24 , V_13 & V_98 ) ) {
if ( V_36 -> V_105 == V_106 )
continue;
V_7 ++ ;
if ( V_105 == - 1 )
V_105 = V_36 -> V_105 ;
else if ( V_105 != V_36 -> V_105 )
return L_10 ;
}
}
if ( V_7 == 0 )
return L_11 ;
if ( V_105 == - 1 )
V_105 = V_106 ;
return V_104 [ V_105 ] ;
}
static inline bool F_113 ( struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 )
{
if ( ( V_13 & V_101 ) ) {
struct V_23 * V_36 ;
struct V_37 V_27 ;
F_35 (i, label, profile) {
if ( F_95 ( V_24 , V_36 -> V_24 ,
V_13 & V_98 ) &&
V_36 != V_36 -> V_24 -> V_102 )
return true ;
}
return false ;
}
return false ;
}
int F_114 ( char * V_95 , T_4 V_47 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 )
{
struct V_23 * V_36 ;
struct V_16 * V_97 = NULL ;
struct V_37 V_27 ;
int V_7 = 0 , V_107 = 0 ;
T_4 V_66 ;
F_13 ( ! V_95 && V_47 != 0 ) ;
F_13 ( ! V_3 ) ;
if ( ! V_24 )
V_24 = F_16 ( V_3 ) ;
F_35 (i, label, profile) {
if ( F_95 ( V_24 , V_36 -> V_24 , V_13 & V_98 ) ) {
if ( V_7 > 0 ) {
V_66 = snprintf ( V_95 , V_47 , L_4 ) ;
F_115 ( V_107 , V_66 , V_47 , V_95 ) ;
}
V_66 = F_110 ( V_95 , V_47 , V_24 , V_36 ,
V_13 & V_98 ,
& V_97 ) ;
F_115 ( V_107 , V_66 , V_47 , V_95 ) ;
V_7 ++ ;
}
}
if ( V_7 == 0 ) {
if ( V_13 & V_100 )
return snprintf ( V_95 , V_47 , L_5 , L_6 ) ;
return snprintf ( V_95 , V_47 , L_5 , V_99 ) ;
}
if ( F_113 ( V_24 , V_3 , V_13 ) ) {
V_66 = snprintf ( V_95 , V_47 , L_12 ,
F_112 ( V_24 , V_3 , V_13 ) ) ;
F_115 ( V_107 , V_66 , V_47 , V_95 ) ;
}
return V_107 ;
}
int F_116 ( char * * V_108 , struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 , T_1 V_8 )
{
int V_47 ;
F_13 ( ! V_108 ) ;
F_13 ( ! V_3 ) ;
V_47 = F_114 ( NULL , 0 , V_24 , V_3 , V_13 ) ;
if ( V_47 < 0 )
return V_47 ;
* V_108 = F_117 ( V_47 + 1 , V_8 ) ;
if ( ! * V_108 )
return - V_109 ;
return F_114 ( * V_108 , V_47 + 1 , V_24 , V_3 , V_13 ) ;
}
int F_108 ( char T_3 * * V_108 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 , T_1 V_8 )
{
int V_47 ;
F_13 ( ! V_108 ) ;
F_13 ( ! V_3 ) ;
V_47 = F_114 ( NULL , 0 , V_24 , V_3 , V_13 ) ;
if ( V_47 < 0 )
return V_47 ;
* V_108 = F_118 ( V_47 + 1 , V_8 ) ;
if ( ! * V_108 )
return - V_109 ;
return F_114 ( * V_108 , V_47 + 1 , V_24 , V_3 , V_13 ) ;
}
void F_119 ( struct V_110 * V_111 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 , T_1 V_8 )
{
const char * V_95 ;
char * V_93 = NULL ;
int V_66 ;
F_13 ( ! V_111 ) ;
F_13 ( ! V_3 ) ;
if ( ! V_24 )
V_24 = F_16 ( V_3 ) ;
if ( ! F_109 ( V_24 , V_3 ) || F_113 ( V_24 , V_3 , V_13 ) ) {
V_66 = F_116 ( & V_93 , V_24 , V_3 , V_13 , V_8 ) ;
if ( V_66 == - 1 ) {
F_52 ( L_13 ) ;
return;
}
V_95 = V_93 ;
} else {
V_95 = ( char * ) V_3 -> V_21 ;
V_66 = strlen ( V_95 ) ;
}
if ( F_120 ( V_95 , V_66 ) )
F_121 ( V_111 , V_95 , V_66 ) ;
else
F_122 ( V_111 , V_95 , V_66 ) ;
F_4 ( V_93 ) ;
}
void F_123 ( struct V_112 * V_113 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 , T_1 V_8 )
{
F_13 ( ! V_113 ) ;
F_13 ( ! V_3 ) ;
if ( ! V_24 )
V_24 = F_16 ( V_3 ) ;
if ( ! F_109 ( V_24 , V_3 ) ) {
char * V_95 ;
int V_66 ;
V_66 = F_116 ( & V_95 , V_24 , V_3 , V_13 , V_8 ) ;
if ( V_66 == - 1 ) {
F_52 ( L_13 ) ;
return;
}
F_124 ( V_113 , L_5 , V_95 ) ;
F_4 ( V_95 ) ;
} else if ( F_113 ( V_24 , V_3 , V_13 ) )
F_124 ( V_113 , L_8 , V_3 -> V_21 ,
F_112 ( V_24 , V_3 , V_13 ) ) ;
else
F_124 ( V_113 , L_5 , V_3 -> V_21 ) ;
}
void F_125 ( struct V_16 * V_24 , struct V_4 * V_3 , int V_13 ,
T_1 V_8 )
{
F_13 ( ! V_3 ) ;
if ( ! V_24 )
V_24 = F_16 ( V_3 ) ;
if ( ! F_109 ( V_24 , V_3 ) ) {
char * V_95 ;
int V_66 ;
V_66 = F_116 ( & V_95 , V_24 , V_3 , V_13 , V_8 ) ;
if ( V_66 == - 1 ) {
F_52 ( L_13 ) ;
return;
}
F_126 ( L_5 , V_95 ) ;
F_4 ( V_95 ) ;
} else if ( F_113 ( V_24 , V_3 , V_13 ) )
F_126 ( L_8 , V_3 -> V_21 ,
F_112 ( V_24 , V_3 , V_13 ) ) ;
else
F_126 ( L_5 , V_3 -> V_21 ) ;
}
void F_127 ( struct V_110 * V_111 , struct V_4 * V_3 , T_1 V_8 )
{
struct V_16 * V_24 = F_128 () ;
F_119 ( V_111 , V_24 , V_3 , V_98 , V_8 ) ;
F_129 ( V_24 ) ;
}
void F_130 ( struct V_112 * V_113 , struct V_4 * V_3 , T_1 V_8 )
{
struct V_16 * V_24 = F_128 () ;
F_123 ( V_113 , V_24 , V_3 , V_98 , V_8 ) ;
F_129 ( V_24 ) ;
}
void F_131 ( struct V_4 * V_3 , T_1 V_8 )
{
struct V_16 * V_24 = F_128 () ;
F_125 ( V_24 , V_3 , V_98 , V_8 ) ;
F_129 ( V_24 ) ;
}
static int F_132 ( const char * V_95 )
{
const char * V_114 ;
int V_7 = 1 ;
F_13 ( ! V_95 ) ;
for ( V_114 = strstr ( V_95 , L_4 ) ; V_114 ; V_114 = strstr ( V_95 , L_4 ) ) {
V_7 ++ ;
V_95 = V_114 + 3 ;
}
return V_7 ;
}
static struct V_23 * F_133 ( struct V_4 * V_20 ,
struct V_4 * V_115 ,
const char * V_95 , T_4 V_29 )
{
const char * V_116 = F_134 ( V_95 , V_29 ) ;
if ( V_116 && * V_116 == ':' )
return F_135 ( V_20 , V_95 , V_29 ) ;
return F_135 ( V_115 , V_95 , V_29 ) ;
}
struct V_4 * F_136 ( struct V_4 * V_20 , const char * V_95 ,
T_1 V_8 , bool V_117 , bool V_118 )
{
F_137 ( V_36 , V_28 ) ;
struct V_4 * V_3 , * V_119 = V_20 ;
int V_27 , V_66 , V_120 = 0 , error ;
char * V_114 ;
F_13 ( ! V_20 ) ;
F_13 ( ! V_95 ) ;
V_95 = F_138 ( V_95 ) ;
V_66 = F_132 ( V_95 ) ;
if ( * V_95 == '&' || V_118 ) {
V_120 = V_20 -> V_47 ;
V_66 += V_120 ;
if ( * V_95 == '&' )
V_95 ++ ;
}
error = F_139 ( V_36 , V_28 , V_66 , V_8 ) ;
if ( error )
return F_140 ( error ) ;
for ( V_27 = 0 ; V_27 < V_120 ; V_27 ++ )
V_28 [ V_27 ] = F_80 ( V_20 -> V_28 [ V_27 ] ) ;
for ( V_114 = strstr ( V_95 , L_4 ) , V_27 = V_120 ; V_114 && V_27 < V_66 ; V_27 ++ ) {
V_28 [ V_27 ] = F_133 ( V_20 , V_119 , V_95 , V_114 - V_95 ) ;
if ( ! V_28 [ V_27 ] )
goto V_51;
if ( V_28 [ V_27 ] -> V_24 != F_16 ( V_119 ) )
V_119 = & V_28 [ V_27 ] -> V_3 ;
V_95 = V_114 + 3 ;
V_114 = strstr ( V_95 , L_4 ) ;
}
if ( V_27 < V_66 ) {
V_28 [ V_27 ] = F_133 ( V_20 , V_119 , V_95 , strlen ( V_95 ) ) ;
if ( ! V_28 [ V_27 ] )
goto V_51;
}
if ( V_66 == 1 )
return & V_28 [ 0 ] -> V_3 ;
V_66 -= F_30 ( V_28 , V_66 , V_35 ) ;
if ( V_66 == 1 ) {
V_3 = F_11 ( & V_28 [ 0 ] -> V_3 ) ;
goto V_32;
}
if ( V_117 )
V_3 = F_81 ( V_28 , V_66 , V_8 ) ;
else
V_3 = F_76 ( V_28 , V_66 ) ;
if ( ! V_3 )
goto V_51;
V_32:
F_141 ( V_36 , V_28 , V_66 ) ;
return V_3 ;
V_51:
V_3 = F_140 ( - V_121 ) ;
goto V_32;
}
void F_142 ( struct V_55 * V_56 )
{
struct V_59 * V_49 ;
unsigned long V_13 ;
F_13 ( ! V_56 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
for ( V_49 = F_143 ( & V_56 -> V_57 ) ; V_49 ; V_49 = F_143 ( & V_56 -> V_57 ) ) {
struct V_4 * V_61 = F_64 ( V_49 , struct V_4 , V_49 ) ;
if ( F_16 ( V_61 ) != V_122 )
F_57 ( V_61 ,
F_72 ( F_16 ( V_61 ) -> V_60 ) ) ;
else
F_57 ( V_61 , NULL ) ;
}
F_73 ( & V_56 -> V_12 , V_13 ) ;
}
void F_144 ( struct V_55 * V_56 )
{
F_13 ( ! V_56 ) ;
F_145 ( & V_56 -> V_12 ) ;
V_56 -> V_57 = V_123 ;
}
static struct V_4 * F_146 ( struct V_55 * V_56 )
{
struct V_4 * V_3 ;
struct V_59 * V_49 ;
unsigned long V_13 ;
F_13 ( ! V_56 ) ;
F_77 ( & V_56 -> V_12 , V_13 ) ;
F_147 (ls, node) {
V_3 = F_64 ( V_49 , struct V_4 , V_49 ) ;
if ( ( F_58 ( V_3 ) ||
F_23 ( V_3 -> V_28 , V_3 -> V_47 ) ) &&
F_65 ( V_3 ) )
goto V_32;
}
V_3 = NULL ;
V_32:
F_78 ( & V_56 -> V_12 , V_13 ) ;
return V_3 ;
}
static struct V_4 * F_148 ( struct V_4 * V_3 )
{
struct V_4 * V_9 , * V_11 ;
struct V_55 * V_56 ;
unsigned long V_13 ;
int V_27 , V_71 = 0 ;
F_13 ( ! V_3 ) ;
F_13 ( ! F_149 ( & F_16 ( V_3 ) -> V_12 ) ) ;
V_9 = F_51 ( V_3 -> V_47 , V_3 -> V_2 , V_124 ) ;
if ( ! V_9 )
return NULL ;
V_56 = F_15 ( V_3 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_47 ; V_27 ++ ) {
F_13 ( ! V_3 -> V_28 [ V_27 ] ) ;
V_9 -> V_28 [ V_27 ] = F_88 ( V_3 -> V_28 [ V_27 ] ) ;
F_13 ( ! V_9 -> V_28 [ V_27 ] ) ;
F_13 ( ! V_9 -> V_28 [ V_27 ] -> V_3 . V_2 ) ;
F_13 ( ! V_9 -> V_28 [ V_27 ] -> V_3 . V_2 -> V_3 ) ;
if ( V_9 -> V_28 [ V_27 ] -> V_3 . V_2 != V_3 -> V_28 [ V_27 ] -> V_3 . V_2 )
V_71 ++ ;
}
if ( V_71 ) {
V_9 -> V_47 -= F_30 ( & V_9 -> V_28 [ 0 ] , V_9 -> V_47 ,
V_35 ) ;
if ( V_9 -> V_47 == 1 ) {
V_11 = F_11 ( & V_9 -> V_28 [ 0 ] -> V_3 ) ;
F_13 ( V_11 == V_3 ) ;
goto remove;
}
if ( F_15 ( V_3 ) != F_15 ( V_9 ) ) {
F_73 ( & V_56 -> V_12 , V_13 ) ;
V_11 = F_83 ( F_15 ( V_9 ) , V_9 ) ;
F_71 ( & V_56 -> V_12 , V_13 ) ;
goto remove;
}
} else
F_13 ( F_16 ( V_3 ) != F_16 ( V_9 ) ) ;
V_11 = F_63 ( F_15 ( V_3 ) , V_9 , true ) ;
remove:
F_57 ( V_3 , V_11 ) ;
F_73 ( & V_56 -> V_12 , V_13 ) ;
F_47 ( V_11 , V_9 ) ;
return V_11 ;
}
static void F_150 ( struct V_16 * V_24 )
{
struct V_4 * V_3 ;
F_13 ( ! V_24 ) ;
F_13 ( ! F_149 ( & V_24 -> V_12 ) ) ;
do {
V_3 = F_146 ( & V_24 -> V_76 ) ;
if ( V_3 ) {
struct V_4 * V_65 = F_148 ( V_3 ) ;
F_2 ( V_65 ) ;
F_2 ( V_3 ) ;
}
} while ( V_3 );
}
void F_151 ( struct V_16 * V_24 )
{
struct V_16 * V_125 ;
F_13 ( ! V_24 ) ;
F_13 ( ! F_149 ( & V_24 -> V_12 ) ) ;
F_150 ( V_24 ) ;
F_152 (child, &ns->sub_ns, base.list) {
F_153 ( & V_125 -> V_12 ) ;
F_151 ( V_125 ) ;
F_154 ( & V_125 -> V_12 ) ;
}
}
