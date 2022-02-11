static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( F_3 ( V_2 -> V_3 , true ) ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_4 ( V_2 -> V_3 , (struct V_4 * ) V_5 ) ;
F_5 ( V_2 ) ;
}
}
void F_6 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 , struct V_1 , V_7 ) ;
F_1 ( V_2 ) ;
}
struct V_1 * F_8 ( struct V_4 * V_3 , T_1 V_8 )
{
struct V_1 * V_9 ;
V_9 = F_9 ( sizeof( struct V_1 ) , V_8 ) ;
if ( V_9 ) {
F_10 ( & V_9 -> V_7 ) ;
F_11 ( V_9 -> V_3 , F_12 ( V_3 ) ) ;
}
return V_9 ;
}
void F_13 ( struct V_4 * V_10 , struct V_4 * V_9 )
{
struct V_4 * V_11 ;
F_14 ( ! V_10 ) ;
F_14 ( ! V_9 ) ;
F_14 ( ! F_15 ( & F_16 ( V_10 ) -> V_12 ) ) ;
V_11 = F_3 ( V_10 -> V_2 -> V_3 ,
& F_17 ( V_10 ) -> V_12 ) ;
F_11 ( V_10 -> V_2 -> V_3 , F_12 ( V_9 ) ) ;
V_10 -> V_13 |= V_14 ;
F_2 ( V_11 ) ;
}
static void F_18 ( struct V_4 * V_15 , struct V_4 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
V_9 -> V_2 = F_19 ( V_15 -> V_2 ) ;
F_13 ( V_15 , V_9 ) ;
F_20 ( V_2 ) ;
}
static int F_21 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
int V_19 ;
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
F_14 ( ! V_17 -> V_20 . V_21 ) ;
F_14 ( ! V_18 -> V_20 . V_21 ) ;
if ( V_17 == V_18 )
return 0 ;
V_19 = V_17 -> V_22 - V_18 -> V_22 ;
if ( V_19 )
return V_19 ;
return strcmp ( V_17 -> V_20 . V_21 , V_18 -> V_20 . V_21 ) ;
}
static int F_22 ( struct V_23 * V_17 , struct V_23 * V_18 )
{
int V_19 ;
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
F_14 ( ! V_17 -> V_24 ) ;
F_14 ( ! V_18 -> V_24 ) ;
F_14 ( ! V_17 -> V_20 . V_21 ) ;
F_14 ( ! V_18 -> V_20 . V_21 ) ;
if ( V_17 == V_18 || V_17 -> V_20 . V_21 == V_18 -> V_20 . V_21 )
return 0 ;
V_19 = F_21 ( V_17 -> V_24 , V_18 -> V_24 ) ;
if ( V_19 )
return V_19 ;
return strcmp ( V_17 -> V_20 . V_21 , V_18 -> V_20 . V_21 ) ;
}
static int F_23 ( struct V_23 * * V_17 , int V_25 , struct V_23 * * V_18 , int V_26 )
{
int V_27 ;
F_14 ( ! V_17 ) ;
F_14 ( ! * V_17 ) ;
F_14 ( ! V_18 ) ;
F_14 ( ! * V_18 ) ;
F_14 ( V_25 <= 0 ) ;
F_14 ( V_26 <= 0 ) ;
for ( V_27 = 0 ; V_27 < V_25 && V_27 < V_26 ; V_27 ++ ) {
int V_19 = F_22 ( V_17 [ V_27 ] , V_18 [ V_27 ] ) ;
if ( V_19 != 0 )
return V_19 ;
}
return V_25 - V_26 ;
}
static bool F_24 ( struct V_23 * * V_28 , int V_29 )
{
int V_27 ;
F_14 ( ! V_28 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( F_25 ( V_28 [ V_27 ] ) )
return true ;
}
return false ;
}
static bool F_26 ( struct V_23 * * V_28 , int V_29 )
{
int V_27 ;
F_14 ( ! V_28 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ! F_27 ( V_28 [ V_27 ] ) )
return false ;
}
return true ;
}
static int F_28 ( const void * V_17 , const void * V_18 )
{
return F_22 ( * (struct V_23 * * ) V_17 , * (struct V_23 * * ) V_18 ) ;
}
static inline int F_29 ( struct V_23 * * V_28 , int V_29 )
{
int V_27 , V_30 , V_31 = 0 ;
F_14 ( V_29 < 1 ) ;
F_14 ( ! V_28 ) ;
V_30 = 0 ;
for ( V_27 = 1 ; V_27 < V_29 ; V_27 ++ ) {
int V_19 = F_22 ( V_28 [ V_30 ] , V_28 [ V_27 ] ) ;
F_14 ( V_19 > 0 , L_1 ) ;
if ( V_19 == 0 ) {
F_30 ( V_28 [ V_27 ] ) ;
V_31 ++ ;
continue;
}
V_30 ++ ;
if ( V_31 )
V_28 [ V_30 ] = V_28 [ V_27 ] ;
}
F_14 ( V_31 < 0 ) ;
return V_31 ;
}
int F_31 ( struct V_23 * * V_28 , int V_29 , int V_13 )
{
int V_27 , V_31 = 0 ;
F_14 ( V_29 < 1 ) ;
F_14 ( ! V_28 ) ;
if ( V_29 > 8 ) {
F_32 ( V_28 , V_29 , sizeof( struct V_23 * ) , F_28 , NULL ) ;
V_31 = F_29 ( V_28 , V_29 ) ;
goto V_32;
}
for ( V_27 = 1 ; V_27 < V_29 ; V_27 ++ ) {
struct V_23 * V_11 = V_28 [ V_27 ] ;
int V_30 , V_33 ;
for ( V_30 = V_27 - 1 - V_31 ; V_30 >= 0 ; V_30 -- ) {
int V_19 = F_22 ( V_28 [ V_30 ] , V_11 ) ;
if ( V_19 == 0 ) {
F_30 ( V_11 ) ;
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
F_14 ( V_31 < 0 ) ;
V_32:
if ( V_13 & V_35 )
V_28 [ V_29 - V_31 ] = NULL ;
return V_31 ;
}
static void F_33 ( struct V_4 * V_3 )
{
struct V_4 * V_11 ;
F_14 ( ! V_3 ) ;
if ( ! F_34 ( V_3 ) ) {
struct V_23 * V_36 ;
struct V_37 V_27 ;
F_35 ( V_3 -> V_21 ) ;
F_36 (i, label, profile) {
F_30 ( V_36 ) ;
V_3 -> V_28 [ V_27 . V_27 ] = (struct V_23 * )
( V_38 + ( long ) V_27 . V_27 ) ;
}
}
if ( F_3 ( V_3 -> V_2 -> V_3 , true ) == V_3 )
F_11 ( V_3 -> V_2 -> V_3 , NULL ) ;
F_37 ( V_3 -> V_39 ) ;
V_11 = F_3 ( V_3 -> V_2 -> V_3 , true ) ;
if ( V_11 == V_3 )
F_11 ( V_3 -> V_2 -> V_3 , NULL ) ;
F_20 ( V_3 -> V_2 ) ;
V_3 -> V_2 = (struct V_1 * ) V_5 + 1 ;
}
void F_38 ( struct V_4 * V_3 )
{
if ( ! V_3 )
return;
F_33 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static void F_39 ( struct V_4 * V_3 )
{
if ( V_3 -> V_13 & V_40 )
F_40 ( F_17 ( V_3 ) ) ;
else if ( F_34 ( V_3 ) )
F_41 ( F_42 ( V_3 ) ) ;
else
F_38 ( V_3 ) ;
}
static void F_43 ( struct V_41 * V_42 )
{
struct V_4 * V_3 = F_7 ( V_42 , struct V_4 , V_43 ) ;
if ( V_3 -> V_13 & V_44 )
( void ) F_44 ( V_3 ) ;
F_39 ( V_3 ) ;
}
void F_45 ( struct V_6 * V_6 )
{
struct V_4 * V_3 = F_7 ( V_6 , struct V_4 , V_7 ) ;
struct V_16 * V_24 = F_17 ( V_3 ) ;
if ( ! V_24 ) {
F_39 ( V_3 ) ;
return;
}
F_14 ( F_34 ( V_3 ) &&
F_46 ( & V_3 -> V_28 [ 0 ] -> V_20 . V_45 ) ) ;
F_14 ( F_34 ( V_3 ) &&
F_46 ( & V_3 -> V_28 [ 0 ] -> V_20 . V_46 ) ) ;
F_47 ( & V_3 -> V_43 , F_43 ) ;
}
static void F_48 ( struct V_4 * V_3 , struct V_4 * V_9 )
{
if ( V_3 != V_9 )
F_38 ( V_9 ) ;
else
F_2 ( V_9 ) ;
}
bool F_49 ( struct V_4 * V_3 , int V_47 )
{
F_14 ( ! V_3 ) ;
F_14 ( V_47 < 1 ) ;
V_3 -> V_39 = F_50 () ;
if ( V_3 -> V_39 == V_48 )
return false ;
V_3 -> V_47 = V_47 ;
V_3 -> V_28 [ V_47 ] = NULL ;
F_10 ( & V_3 -> V_7 ) ;
F_51 ( & V_3 -> V_49 ) ;
return true ;
}
struct V_4 * F_52 ( int V_47 , struct V_1 * V_2 , T_1 V_8 )
{
struct V_4 * V_9 ;
F_14 ( V_47 < 1 ) ;
V_9 = F_9 ( sizeof( * V_9 ) + sizeof( struct V_23 * ) * ( V_47 + 1 ) ,
V_8 ) ;
F_53 ( L_2 , V_50 , V_9 ) ;
if ( ! V_9 )
goto V_51;
if ( ! F_49 ( V_9 , V_47 ) )
goto V_51;
if ( ! V_2 ) {
V_2 = F_8 ( V_9 , V_8 ) ;
if ( ! V_2 )
goto V_51;
} else
F_19 ( V_2 ) ;
V_9 -> V_2 = V_2 ;
return V_9 ;
V_51:
F_5 ( V_9 ) ;
return NULL ;
}
static int F_54 ( struct V_4 * V_17 , struct V_4 * V_18 )
{
F_14 ( ! V_18 ) ;
if ( V_17 == V_18 )
return 0 ;
return F_23 ( V_17 -> V_28 , V_17 -> V_47 , V_18 -> V_28 , V_18 -> V_47 ) ;
}
int F_55 ( struct V_4 * V_3 , int V_27 )
{
F_14 ( ! V_3 ) ;
F_14 ( V_27 < 0 ) ;
for (; V_27 < V_3 -> V_47 ; V_27 ++ ) {
if ( ! F_27 ( V_3 -> V_28 [ V_27 ] ) )
return V_27 ;
}
return V_27 ;
}
struct V_23 * F_56 ( struct V_37 * V_52 ,
struct V_4 * V_53 ,
struct V_4 * V_54 )
{
F_14 ( ! V_53 ) ;
F_14 ( ! V_52 ) ;
F_14 ( V_52 -> V_27 < 0 ) ;
F_14 ( V_52 -> V_27 > V_53 -> V_47 ) ;
F_14 ( ! V_54 ) ;
F_14 ( V_52 -> V_33 < 0 ) ;
F_14 ( V_52 -> V_33 > V_54 -> V_47 ) ;
while ( V_52 -> V_33 < V_54 -> V_47 && V_52 -> V_27 < V_53 -> V_47 ) {
int V_19 = F_22 ( V_54 -> V_28 [ V_52 -> V_33 ] , V_53 -> V_28 [ V_52 -> V_27 ] ) ;
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
bool F_57 ( struct V_4 * V_53 , struct V_4 * V_54 )
{
struct V_37 V_27 = { } ;
F_14 ( ! V_53 ) ;
F_14 ( ! V_54 ) ;
if ( V_54 == V_53 )
return true ;
return F_56 ( & V_27 , V_53 , V_54 ) == NULL ;
}
static bool F_58 ( struct V_4 * V_3 , struct V_4 * V_9 )
{
struct V_55 * V_56 = F_16 ( V_3 ) ;
F_14 ( ! V_56 ) ;
F_14 ( ! V_3 ) ;
F_14 ( ! F_15 ( & V_56 -> V_12 ) ) ;
if ( V_9 )
F_13 ( V_3 , V_9 ) ;
if ( ! F_59 ( V_3 ) )
F_60 ( V_3 ) ;
if ( V_3 -> V_13 & V_44 ) {
F_61 ( & V_3 -> V_49 , & V_56 -> V_57 ) ;
V_3 -> V_13 &= ~ V_44 ;
return true ;
}
return false ;
}
static bool F_62 ( struct V_4 * V_15 , struct V_4 * V_9 )
{
struct V_55 * V_56 = F_16 ( V_15 ) ;
F_14 ( ! V_56 ) ;
F_14 ( ! V_15 ) ;
F_14 ( ! V_9 ) ;
F_14 ( ! F_15 ( & V_56 -> V_12 ) ) ;
F_14 ( V_9 -> V_13 & V_44 ) ;
if ( ! F_59 ( V_15 ) )
F_60 ( V_15 ) ;
if ( V_15 -> V_13 & V_44 ) {
F_63 ( & V_15 -> V_49 , & V_9 -> V_49 , & V_56 -> V_57 ) ;
V_15 -> V_13 &= ~ V_44 ;
V_9 -> V_13 |= V_44 ;
return true ;
}
return false ;
}
static struct V_4 * F_64 ( struct V_55 * V_56 ,
struct V_4 * V_3 , bool V_58 )
{
struct V_59 * * V_9 , * V_60 = NULL ;
F_14 ( ! V_56 ) ;
F_14 ( ! V_3 ) ;
F_14 ( F_16 ( V_3 ) != V_56 ) ;
F_14 ( ! F_15 ( & V_56 -> V_12 ) ) ;
F_14 ( V_3 -> V_13 & V_44 ) ;
V_9 = & V_56 -> V_57 . V_59 ;
while ( * V_9 ) {
struct V_4 * V_61 = F_65 ( * V_9 , struct V_4 , V_49 ) ;
int V_62 = F_54 ( V_3 , V_61 ) ;
V_60 = * V_9 ;
if ( V_62 == 0 ) {
if ( ! V_58 && ! F_59 ( V_61 ) ) {
if ( F_66 ( V_61 ) )
return V_61 ;
} else
F_18 ( V_61 , V_3 ) ;
F_14 ( ! F_62 ( V_61 , V_3 ) ) ;
return F_12 ( V_3 ) ;
} else if ( V_62 < 0 )
V_9 = & ( ( * V_9 ) -> V_63 ) ;
else
V_9 = & ( ( * V_9 ) -> V_64 ) ;
}
F_67 ( & V_3 -> V_49 , V_60 , V_9 ) ;
F_68 ( & V_3 -> V_49 , & V_56 -> V_57 ) ;
V_3 -> V_13 |= V_44 ;
return F_12 ( V_3 ) ;
}
static struct V_4 * F_69 ( struct V_23 * * V_28 , int V_29 )
{
struct V_59 * V_49 ;
F_14 ( ! V_28 ) ;
F_14 ( ! * V_28 ) ;
F_14 ( V_29 <= 0 ) ;
V_49 = F_70 ( V_28 , V_29 ) -> V_57 . V_59 ;
while ( V_49 ) {
struct V_4 * V_61 = F_65 ( V_49 , struct V_4 , V_49 ) ;
int V_62 = F_23 ( V_61 -> V_28 , V_61 -> V_47 , V_28 , V_29 ) ;
if ( V_62 > 0 )
V_49 = V_49 -> V_63 ;
else if ( V_62 < 0 )
V_49 = V_49 -> V_64 ;
else
return F_66 ( V_61 ) ;
}
return NULL ;
}
static struct V_4 * F_71 ( struct V_4 * V_3 )
{
F_14 ( ! V_3 ) ;
return F_69 ( V_3 -> V_28 , V_3 -> V_47 ) ;
}
bool F_44 ( struct V_4 * V_3 )
{
struct V_55 * V_56 = F_16 ( V_3 ) ;
unsigned long V_13 ;
bool V_19 ;
F_14 ( ! V_56 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
V_19 = F_58 ( V_3 , F_73 ( F_17 ( V_3 ) ) ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
return V_19 ;
}
bool F_75 ( struct V_4 * V_15 , struct V_4 * V_9 )
{
unsigned long V_13 ;
bool V_19 ;
if ( F_76 ( V_15 , V_9 ) && F_17 ( V_15 ) == F_17 ( V_9 ) ) {
F_72 ( & F_16 ( V_15 ) -> V_12 , V_13 ) ;
if ( V_15 -> V_2 != V_9 -> V_2 )
F_18 ( V_15 , V_9 ) ;
else
F_13 ( V_15 , V_9 ) ;
V_19 = F_62 ( V_15 , V_9 ) ;
F_74 ( & F_16 ( V_15 ) -> V_12 , V_13 ) ;
} else {
struct V_4 * V_65 ;
struct V_55 * V_56 = F_16 ( V_15 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
V_19 = F_58 ( V_15 , V_9 ) ;
if ( F_17 ( V_15 ) != F_17 ( V_9 ) ) {
F_74 ( & V_56 -> V_12 , V_13 ) ;
V_56 = F_16 ( V_9 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
}
V_65 = F_64 ( V_56 , V_9 , true ) ;
V_19 = ( V_65 == V_9 ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
F_2 ( V_65 ) ;
}
return V_19 ;
}
static struct V_4 * F_77 ( struct V_23 * * V_28 , int V_29 )
{
struct V_55 * V_56 ;
struct V_4 * V_3 ;
unsigned long V_13 ;
F_14 ( ! V_28 ) ;
F_14 ( ! * V_28 ) ;
F_14 ( V_29 <= 0 ) ;
V_56 = F_70 ( V_28 , V_29 ) ;
F_78 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_69 ( V_28 , V_29 ) ;
F_79 ( & V_56 -> V_12 , V_13 ) ;
return V_3 ;
}
static struct V_4 * F_80 ( struct V_23 * * V_28 ,
int V_66 , T_1 V_8 )
{
struct V_4 * V_3 = NULL ;
struct V_55 * V_56 ;
unsigned long V_13 ;
struct V_4 * V_9 ;
int V_27 ;
F_14 ( ! V_28 ) ;
if ( V_66 == 1 )
return F_12 ( & V_28 [ 0 ] -> V_3 ) ;
V_56 = F_16 ( & V_28 [ V_66 - 1 ] -> V_3 ) ;
V_9 = F_52 ( V_66 , NULL , V_8 ) ;
if ( ! V_9 )
return NULL ;
for ( V_27 = 0 ; V_27 < V_66 ; V_27 ++ )
V_9 -> V_28 [ V_27 ] = F_81 ( V_28 [ V_27 ] ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_64 ( V_56 , V_9 , false ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
F_48 ( V_3 , V_9 ) ;
return V_3 ;
}
struct V_4 * F_82 ( struct V_23 * * V_28 , int V_66 ,
T_1 V_8 )
{
struct V_4 * V_3 = F_77 ( V_28 , V_66 ) ;
if ( V_3 )
return V_3 ;
return F_80 ( V_28 , V_66 , V_8 ) ;
}
struct V_4 * F_83 ( struct V_4 * V_3 )
{
F_14 ( ! V_3 ) ;
return F_77 ( V_3 -> V_28 , V_3 -> V_47 ) ;
}
struct V_4 * F_84 ( struct V_55 * V_56 , struct V_4 * V_3 )
{
struct V_4 * V_65 ;
unsigned long V_13 ;
F_14 ( ! V_56 ) ;
F_14 ( ! V_3 ) ;
if ( ! F_59 ( V_3 ) ) {
F_78 ( & V_56 -> V_12 , V_13 ) ;
V_65 = F_71 ( V_3 ) ;
F_79 ( & V_56 -> V_12 , V_13 ) ;
if ( V_65 )
return V_65 ;
}
F_72 ( & V_56 -> V_12 , V_13 ) ;
V_65 = F_64 ( V_56 , V_3 , false ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
return V_65 ;
}
struct V_23 * F_85 ( struct V_37 * V_52 ,
struct V_4 * V_17 ,
struct V_4 * V_18 )
{
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
F_14 ( ! V_52 ) ;
F_14 ( V_52 -> V_27 < 0 ) ;
F_14 ( V_52 -> V_27 > V_17 -> V_47 ) ;
F_14 ( V_52 -> V_33 < 0 ) ;
F_14 ( V_52 -> V_33 > V_18 -> V_47 ) ;
if ( V_52 -> V_27 < V_17 -> V_47 ) {
if ( V_52 -> V_33 < V_18 -> V_47 ) {
int V_19 = F_22 ( V_17 -> V_28 [ V_52 -> V_27 ] , V_18 -> V_28 [ V_52 -> V_33 ] ) ;
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
static int F_86 ( struct V_4 * V_17 , struct V_4 * V_18 ,
struct V_4 * V_67 )
{
struct V_23 * V_68 = NULL ;
struct V_37 V_27 = { } ;
int V_69 ;
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
F_14 ( ! V_67 ) ;
for ( V_69 = 0 ;
V_69 < V_67 -> V_47 && ( V_68 = F_85 ( & V_27 , V_17 , V_18 ) ) ;
V_69 ++ ) {
int V_19 = F_22 ( V_68 , V_67 -> V_28 [ V_69 ] ) ;
if ( V_19 != 0 )
return V_19 ;
}
if ( V_68 )
return 1 ;
else if ( V_69 < V_67 -> V_47 )
return - 1 ;
return 0 ;
}
static struct V_4 * F_87 ( struct V_4 * V_9 ,
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
F_14 ( ! V_17 ) ;
F_14 ( V_17 -> V_47 < 0 ) ;
F_14 ( ! V_18 ) ;
F_14 ( V_18 -> V_47 < 0 ) ;
F_14 ( ! V_9 ) ;
F_14 ( V_9 -> V_47 < V_17 -> V_47 + V_18 -> V_47 ) ;
F_88 (i, a, b, next) {
F_14 ( ! V_70 ) ;
if ( F_25 ( V_70 ) ) {
V_9 -> V_28 [ V_69 ] = F_89 ( V_70 ) ;
F_14 ( ! V_9 -> V_28 [ V_69 ] -> V_3 . V_2 ) ;
F_14 ( ! V_9 -> V_28 [ V_69 ] -> V_3 . V_2 -> V_3 ) ;
if ( V_70 -> V_3 . V_2 != V_9 -> V_28 [ V_69 ] -> V_3 . V_2 )
V_71 ++ ;
V_69 ++ ;
V_72 = true ;
} else
V_9 -> V_28 [ V_69 ++ ] = F_81 ( V_70 ) ;
}
V_9 -> V_47 = V_69 ;
V_9 -> V_28 [ V_69 ] = NULL ;
if ( V_71 ) {
V_9 -> V_47 -= F_31 ( & V_9 -> V_28 [ 0 ] , V_9 -> V_47 ,
V_35 ) ;
if ( V_9 -> V_47 == 1 ) {
V_3 = F_12 ( & V_9 -> V_28 [ 0 ] -> V_3 ) ;
return V_3 ;
}
} else if ( ! V_72 ) {
if ( V_69 == V_17 -> V_47 )
return F_12 ( V_17 ) ;
else if ( V_69 == V_18 -> V_47 )
return F_12 ( V_18 ) ;
}
if ( F_26 ( V_9 -> V_28 , V_9 -> V_47 ) )
V_9 -> V_13 |= V_73 ;
V_56 = F_16 ( V_9 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_64 ( F_16 ( V_9 ) , V_9 , false ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
return V_3 ;
}
static struct V_55 * F_90 ( struct V_4 * V_17 ,
struct V_4 * V_18 )
{
struct V_16 * V_74 = F_17 ( V_17 ) ;
struct V_16 * V_75 = F_17 ( V_18 ) ;
if ( F_21 ( V_74 , V_75 ) <= 0 )
return & V_74 -> V_76 ;
return & V_75 -> V_76 ;
}
static struct V_4 * F_91 ( struct V_55 * V_56 ,
struct V_4 * V_17 ,
struct V_4 * V_18 )
{
struct V_59 * V_49 ;
F_14 ( ! V_56 ) ;
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
if ( V_17 == V_18 )
return F_71 ( V_17 ) ;
V_49 = V_56 -> V_57 . V_59 ;
while ( V_49 ) {
struct V_4 * V_61 = F_7 ( V_49 , struct V_4 ,
V_49 ) ;
int V_62 = F_86 ( V_17 , V_18 , V_61 ) ;
if ( V_62 < 0 )
V_49 = V_49 -> V_63 ;
else if ( V_62 > 0 )
V_49 = V_49 -> V_64 ;
else
return F_66 ( V_61 ) ;
}
return NULL ;
}
struct V_4 * F_92 ( struct V_4 * V_17 , struct V_4 * V_18 )
{
struct V_55 * V_56 ;
struct V_4 * V_3 , * V_77 = NULL , * V_78 = NULL ;
unsigned long V_13 ;
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
if ( F_59 ( V_17 ) )
V_17 = V_77 = F_93 ( V_17 ) ;
if ( F_59 ( V_18 ) )
V_18 = V_78 = F_93 ( V_18 ) ;
V_56 = F_90 ( V_17 , V_18 ) ;
F_78 ( & V_56 -> V_12 , V_13 ) ;
V_3 = F_91 ( V_56 , V_17 , V_18 ) ;
F_79 ( & V_56 -> V_12 , V_13 ) ;
F_2 ( V_77 ) ;
F_2 ( V_78 ) ;
return V_3 ;
}
struct V_4 * F_94 ( struct V_4 * V_17 , struct V_4 * V_18 ,
T_1 V_8 )
{
struct V_4 * V_3 = NULL ;
F_14 ( ! V_17 ) ;
F_14 ( ! V_18 ) ;
if ( V_17 == V_18 )
return F_93 ( V_17 ) ;
if ( ! V_3 ) {
struct V_4 * V_9 ;
V_17 = F_93 ( V_17 ) ;
V_18 = F_93 ( V_18 ) ;
V_9 = F_52 ( V_17 -> V_47 + V_18 -> V_47 , NULL , V_8 ) ;
if ( ! V_9 )
goto V_32;
V_3 = F_87 ( V_9 , V_17 , V_18 ) ;
F_48 ( V_3 , V_9 ) ;
V_32:
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
}
return V_3 ;
}
static inline bool F_95 ( struct V_23 * V_36 ,
struct V_4 * V_3 )
{
return F_96 ( V_36 -> V_24 , F_17 ( V_3 ) , true ) ;
}
static inline unsigned int F_97 ( struct V_23 * V_36 ,
struct V_23 * V_79 ,
unsigned int V_80 )
{
const char * V_81 ;
if ( V_36 -> V_24 == V_79 -> V_24 )
return F_98 ( V_36 -> V_82 . V_83 , V_80 , V_79 -> V_20 . V_21 ) ;
V_81 = F_99 ( V_36 -> V_24 , V_79 -> V_24 , true ) ;
V_80 = F_100 ( V_36 -> V_82 . V_83 , V_80 , L_3 , 1 ) ;
V_80 = F_98 ( V_36 -> V_82 . V_83 , V_80 , V_81 ) ;
V_80 = F_100 ( V_36 -> V_82 . V_83 , V_80 , L_3 , 1 ) ;
return F_98 ( V_36 -> V_82 . V_83 , V_80 , V_79 -> V_20 . V_21 ) ;
}
static int F_101 ( struct V_23 * V_36 ,
struct V_4 * V_3 ,
unsigned int V_80 , bool V_84 , T_2 V_85 ,
struct V_86 * V_87 )
{
struct V_23 * V_79 ;
struct V_37 V_27 ;
F_36 (i, label, tp) {
if ( ! F_96 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_97 ( V_36 , V_79 , V_80 ) ;
if ( ! V_80 )
goto V_51;
goto V_70;
}
* V_87 = V_88 ;
return 0 ;
V_70:
F_102 (i, label, tp) {
if ( ! F_96 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_98 ( V_36 -> V_82 . V_83 , V_80 , L_4 ) ;
V_80 = F_97 ( V_36 , V_79 , V_80 ) ;
if ( ! V_80 )
goto V_51;
}
F_103 ( V_36 -> V_82 . V_83 , V_80 , V_87 ) ;
F_104 ( V_36 , V_87 ) ;
if ( ( V_87 -> V_89 & V_85 ) != V_85 )
return - V_90 ;
return 0 ;
V_51:
* V_87 = V_91 ;
return V_80 ;
}
static int F_105 ( struct V_23 * V_36 ,
struct V_4 * V_3 , unsigned int V_92 ,
bool V_84 , T_2 V_85 ,
struct V_86 * V_87 )
{
struct V_23 * V_79 ;
struct V_37 V_27 ;
struct V_86 V_11 ;
unsigned int V_80 = 0 ;
F_36 (i, label, tp) {
if ( ! F_96 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_97 ( V_36 , V_79 , V_92 ) ;
if ( ! V_80 )
goto V_51;
goto V_70;
}
return 0 ;
V_70:
F_103 ( V_36 -> V_82 . V_83 , V_80 , & V_11 ) ;
F_104 ( V_36 , & V_11 ) ;
F_106 ( V_87 , & V_11 ) ;
F_102 (i, label, tp) {
if ( ! F_96 ( V_36 -> V_24 , V_79 -> V_24 , V_84 ) )
continue;
V_80 = F_97 ( V_36 , V_79 , V_92 ) ;
if ( ! V_80 )
goto V_51;
F_103 ( V_36 -> V_82 . V_83 , V_80 , & V_11 ) ;
F_104 ( V_36 , & V_11 ) ;
F_106 ( V_87 , & V_11 ) ;
}
if ( ( V_87 -> V_89 & V_85 ) != V_85 )
return - V_90 ;
return 0 ;
V_51:
* V_87 = V_91 ;
return - V_90 ;
}
int F_107 ( struct V_23 * V_36 , struct V_4 * V_3 ,
unsigned int V_80 , bool V_84 , T_2 V_85 ,
struct V_86 * V_87 )
{
int error = F_101 ( V_36 , V_3 , V_80 , V_84 , V_85 ,
V_87 ) ;
if ( ! error )
return error ;
* V_87 = V_88 ;
return F_105 ( V_36 , V_3 , V_80 , V_84 , V_85 ,
V_87 ) ;
}
bool F_108 ( struct V_16 * V_24 , struct V_4 * V_3 , T_1 V_8 )
{
struct V_55 * V_56 ;
unsigned long V_13 ;
char T_3 * V_93 ;
bool V_19 = false ;
F_14 ( ! V_24 ) ;
F_14 ( ! V_3 ) ;
if ( V_3 -> V_21 || F_17 ( V_3 ) != V_24 )
return V_19 ;
if ( F_109 ( & V_93 , V_24 , V_3 , V_94 , V_8 ) == - 1 )
return V_19 ;
V_56 = F_16 ( V_3 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
if ( ! V_3 -> V_21 && V_3 -> V_13 & V_44 ) {
V_3 -> V_21 = V_93 ;
V_19 = true ;
} else
F_35 ( V_93 ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
return V_19 ;
}
static inline bool F_110 ( struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 )
{
if ( V_3 -> V_21 && ( ! V_24 || F_17 ( V_3 ) == V_24 ) &&
! ( V_13 & ~ V_95 ) )
return true ;
return false ;
}
static int F_111 ( char * V_96 , T_4 V_47 , struct V_16 * V_97 ,
struct V_23 * V_36 , int V_13 ,
struct V_16 * * V_98 )
{
const char * V_81 = NULL ;
F_14 ( ! V_96 && V_47 != 0 ) ;
F_14 ( ! V_36 ) ;
if ( ! V_97 )
V_97 = F_112 ( V_36 ) ;
if ( V_97 != V_36 -> V_24 &&
( ! V_98 || ( * V_98 != V_36 -> V_24 ) ) ) {
if ( V_98 )
* V_98 = V_36 -> V_24 ;
V_81 = F_99 ( V_97 , V_36 -> V_24 ,
V_13 & V_99 ) ;
if ( V_81 == V_100 ) {
if ( V_13 & V_101 )
return snprintf ( V_96 , V_47 , L_5 , L_6 ) ;
return snprintf ( V_96 , V_47 , L_5 , V_81 ) ;
}
}
if ( ( V_13 & V_95 ) && V_36 != V_36 -> V_24 -> V_102 ) {
const char * V_103 = V_104 [ V_36 -> V_105 ] ;
if ( V_81 )
return snprintf ( V_96 , V_47 , L_7 , V_81 ,
V_36 -> V_20 . V_21 , V_103 ) ;
return snprintf ( V_96 , V_47 , L_8 , V_36 -> V_20 . V_21 ,
V_103 ) ;
}
if ( V_81 )
return snprintf ( V_96 , V_47 , L_9 , V_81 ,
V_36 -> V_20 . V_21 ) ;
return snprintf ( V_96 , V_47 , L_5 , V_36 -> V_20 . V_21 ) ;
}
static const char * F_113 ( struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 )
{
struct V_23 * V_36 ;
struct V_37 V_27 ;
int V_105 = - 1 , V_7 = 0 ;
F_36 (i, label, profile) {
if ( F_96 ( V_24 , V_36 -> V_24 , V_13 & V_99 ) ) {
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
static inline bool F_114 ( struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 )
{
if ( ( V_13 & V_95 ) ) {
struct V_23 * V_36 ;
struct V_37 V_27 ;
F_36 (i, label, profile) {
if ( F_96 ( V_24 , V_36 -> V_24 ,
V_13 & V_99 ) &&
V_36 != V_36 -> V_24 -> V_102 )
return true ;
}
return false ;
}
return false ;
}
int F_115 ( char * V_96 , T_4 V_47 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 )
{
struct V_23 * V_36 ;
struct V_16 * V_98 = NULL ;
struct V_37 V_27 ;
int V_7 = 0 , V_107 = 0 ;
T_4 V_66 ;
F_14 ( ! V_96 && V_47 != 0 ) ;
F_14 ( ! V_3 ) ;
if ( V_13 & V_108 ) {
V_24 = V_109 ;
V_66 = snprintf ( V_96 , V_47 , L_12 ) ;
F_116 ( V_107 , V_66 , V_47 , V_96 ) ;
} else if ( ! V_24 ) {
V_24 = F_17 ( V_3 ) ;
}
F_36 (i, label, profile) {
if ( F_96 ( V_24 , V_36 -> V_24 , V_13 & V_99 ) ) {
if ( V_7 > 0 ) {
V_66 = snprintf ( V_96 , V_47 , L_4 ) ;
F_116 ( V_107 , V_66 , V_47 , V_96 ) ;
}
V_66 = F_111 ( V_96 , V_47 , V_24 , V_36 ,
V_13 & V_99 ,
& V_98 ) ;
F_116 ( V_107 , V_66 , V_47 , V_96 ) ;
V_7 ++ ;
}
}
if ( V_7 == 0 ) {
if ( V_13 & V_101 )
return snprintf ( V_96 , V_47 , L_5 , L_6 ) ;
return snprintf ( V_96 , V_47 , L_5 , V_100 ) ;
}
if ( F_114 ( V_24 , V_3 , V_13 ) ) {
V_66 = snprintf ( V_96 , V_47 , L_13 ,
F_113 ( V_24 , V_3 , V_13 ) ) ;
F_116 ( V_107 , V_66 , V_47 , V_96 ) ;
}
return V_107 ;
}
int F_117 ( char * * V_110 , struct V_16 * V_24 , struct V_4 * V_3 ,
int V_13 , T_1 V_8 )
{
int V_47 ;
F_14 ( ! V_110 ) ;
F_14 ( ! V_3 ) ;
V_47 = F_115 ( NULL , 0 , V_24 , V_3 , V_13 ) ;
if ( V_47 < 0 )
return V_47 ;
* V_110 = F_118 ( V_47 + 1 , V_8 ) ;
if ( ! * V_110 )
return - V_111 ;
return F_115 ( * V_110 , V_47 + 1 , V_24 , V_3 , V_13 ) ;
}
int F_109 ( char T_3 * * V_110 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 , T_1 V_8 )
{
int V_47 ;
F_14 ( ! V_110 ) ;
F_14 ( ! V_3 ) ;
V_47 = F_115 ( NULL , 0 , V_24 , V_3 , V_13 ) ;
if ( V_47 < 0 )
return V_47 ;
* V_110 = F_119 ( V_47 + 1 , V_8 ) ;
if ( ! * V_110 )
return - V_111 ;
return F_115 ( * V_110 , V_47 + 1 , V_24 , V_3 , V_13 ) ;
}
void F_120 ( struct V_112 * V_113 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 , T_1 V_8 )
{
const char * V_96 ;
char * V_93 = NULL ;
int V_66 ;
F_14 ( ! V_113 ) ;
F_14 ( ! V_3 ) ;
if ( ! F_110 ( V_24 , V_3 , V_13 ) ||
F_114 ( V_24 , V_3 , V_13 ) ) {
V_66 = F_117 ( & V_93 , V_24 , V_3 , V_13 , V_8 ) ;
if ( V_66 == - 1 ) {
F_53 ( L_14 ) ;
return;
}
V_96 = V_93 ;
} else {
V_96 = ( char * ) V_3 -> V_21 ;
V_66 = strlen ( V_96 ) ;
}
if ( F_121 ( V_96 , V_66 ) )
F_122 ( V_113 , V_96 , V_66 ) ;
else
F_123 ( V_113 , V_96 , V_66 ) ;
F_5 ( V_93 ) ;
}
void F_124 ( struct V_114 * V_115 , struct V_16 * V_24 ,
struct V_4 * V_3 , int V_13 , T_1 V_8 )
{
F_14 ( ! V_115 ) ;
F_14 ( ! V_3 ) ;
if ( ! F_110 ( V_24 , V_3 , V_13 ) ) {
char * V_96 ;
int V_66 ;
V_66 = F_117 ( & V_96 , V_24 , V_3 , V_13 , V_8 ) ;
if ( V_66 == - 1 ) {
F_53 ( L_14 ) ;
return;
}
F_125 ( V_115 , L_5 , V_96 ) ;
F_5 ( V_96 ) ;
} else if ( F_114 ( V_24 , V_3 , V_13 ) )
F_125 ( V_115 , L_8 , V_3 -> V_21 ,
F_113 ( V_24 , V_3 , V_13 ) ) ;
else
F_125 ( V_115 , L_5 , V_3 -> V_21 ) ;
}
void F_126 ( struct V_16 * V_24 , struct V_4 * V_3 , int V_13 ,
T_1 V_8 )
{
F_14 ( ! V_3 ) ;
if ( ! F_110 ( V_24 , V_3 , V_13 ) ) {
char * V_96 ;
int V_66 ;
V_66 = F_117 ( & V_96 , V_24 , V_3 , V_13 , V_8 ) ;
if ( V_66 == - 1 ) {
F_53 ( L_14 ) ;
return;
}
F_127 ( L_5 , V_96 ) ;
F_5 ( V_96 ) ;
} else if ( F_114 ( V_24 , V_3 , V_13 ) )
F_127 ( L_8 , V_3 -> V_21 ,
F_113 ( V_24 , V_3 , V_13 ) ) ;
else
F_127 ( L_5 , V_3 -> V_21 ) ;
}
void F_128 ( struct V_112 * V_113 , struct V_4 * V_3 , T_1 V_8 )
{
struct V_16 * V_24 = F_129 () ;
F_120 ( V_113 , V_24 , V_3 , V_99 , V_8 ) ;
F_130 ( V_24 ) ;
}
void F_131 ( struct V_114 * V_115 , struct V_4 * V_3 , T_1 V_8 )
{
struct V_16 * V_24 = F_129 () ;
F_124 ( V_115 , V_24 , V_3 , V_99 , V_8 ) ;
F_130 ( V_24 ) ;
}
void F_132 ( struct V_4 * V_3 , T_1 V_8 )
{
struct V_16 * V_24 = F_129 () ;
F_126 ( V_24 , V_3 , V_99 , V_8 ) ;
F_130 ( V_24 ) ;
}
static int F_133 ( const char * V_96 )
{
const char * V_116 ;
int V_7 = 1 ;
F_14 ( ! V_96 ) ;
for ( V_116 = strstr ( V_96 , L_4 ) ; V_116 ; V_116 = strstr ( V_96 , L_4 ) ) {
V_7 ++ ;
V_96 = V_116 + 3 ;
}
return V_7 ;
}
static struct V_23 * F_134 ( struct V_4 * V_20 ,
struct V_4 * V_117 ,
const char * V_96 , T_4 V_29 )
{
const char * V_118 = F_135 ( V_96 , V_29 ) ;
if ( V_118 && * V_118 == ':' )
return F_136 ( V_20 , V_96 , V_29 ) ;
return F_136 ( V_117 , V_96 , V_29 ) ;
}
struct V_4 * F_137 ( struct V_4 * V_20 , const char * V_96 ,
T_1 V_8 , bool V_119 , bool V_120 )
{
F_138 ( V_36 , V_28 ) ;
struct V_4 * V_3 , * V_121 = V_20 ;
int V_27 , V_66 , V_122 = 0 , error ;
char * V_116 ;
F_14 ( ! V_20 ) ;
F_14 ( ! V_96 ) ;
V_96 = F_139 ( V_96 ) ;
V_66 = F_133 ( V_96 ) ;
if ( * V_96 == '&' || V_120 ) {
V_122 = V_20 -> V_47 ;
V_66 += V_122 ;
if ( * V_96 == '&' )
V_96 ++ ;
}
if ( * V_96 == '=' )
V_20 = & V_109 -> V_102 -> V_3 ;
error = F_140 ( V_36 , V_28 , V_66 , V_8 ) ;
if ( error )
return F_141 ( error ) ;
for ( V_27 = 0 ; V_27 < V_122 ; V_27 ++ )
V_28 [ V_27 ] = F_81 ( V_20 -> V_28 [ V_27 ] ) ;
for ( V_116 = strstr ( V_96 , L_4 ) , V_27 = V_122 ; V_116 && V_27 < V_66 ; V_27 ++ ) {
V_28 [ V_27 ] = F_134 ( V_20 , V_121 , V_96 , V_116 - V_96 ) ;
if ( ! V_28 [ V_27 ] )
goto V_51;
if ( V_28 [ V_27 ] -> V_24 != F_17 ( V_121 ) )
V_121 = & V_28 [ V_27 ] -> V_3 ;
V_96 = V_116 + 3 ;
V_116 = strstr ( V_96 , L_4 ) ;
}
if ( V_27 < V_66 ) {
V_28 [ V_27 ] = F_134 ( V_20 , V_121 , V_96 , strlen ( V_96 ) ) ;
if ( ! V_28 [ V_27 ] )
goto V_51;
}
if ( V_66 == 1 )
return & V_28 [ 0 ] -> V_3 ;
V_66 -= F_31 ( V_28 , V_66 , V_35 ) ;
if ( V_66 == 1 ) {
V_3 = F_12 ( & V_28 [ 0 ] -> V_3 ) ;
goto V_32;
}
if ( V_119 )
V_3 = F_82 ( V_28 , V_66 , V_8 ) ;
else
V_3 = F_77 ( V_28 , V_66 ) ;
if ( ! V_3 )
goto V_51;
V_32:
F_142 ( V_36 , V_28 , V_66 ) ;
return V_3 ;
V_51:
V_3 = F_141 ( - V_123 ) ;
goto V_32;
}
void F_143 ( struct V_55 * V_56 )
{
struct V_59 * V_49 ;
unsigned long V_13 ;
F_14 ( ! V_56 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
for ( V_49 = F_144 ( & V_56 -> V_57 ) ; V_49 ; V_49 = F_144 ( & V_56 -> V_57 ) ) {
struct V_4 * V_61 = F_65 ( V_49 , struct V_4 , V_49 ) ;
if ( F_17 ( V_61 ) != V_109 )
F_58 ( V_61 ,
F_73 ( F_17 ( V_61 ) -> V_60 ) ) ;
else
F_58 ( V_61 , NULL ) ;
}
F_74 ( & V_56 -> V_12 , V_13 ) ;
}
void F_145 ( struct V_55 * V_56 )
{
F_14 ( ! V_56 ) ;
F_146 ( & V_56 -> V_12 ) ;
V_56 -> V_57 = V_124 ;
}
static struct V_4 * F_147 ( struct V_55 * V_56 )
{
struct V_4 * V_3 ;
struct V_59 * V_49 ;
unsigned long V_13 ;
F_14 ( ! V_56 ) ;
F_78 ( & V_56 -> V_12 , V_13 ) ;
F_148 (ls, node) {
V_3 = F_65 ( V_49 , struct V_4 , V_49 ) ;
if ( ( F_59 ( V_3 ) ||
F_24 ( V_3 -> V_28 , V_3 -> V_47 ) ) &&
F_66 ( V_3 ) )
goto V_32;
}
V_3 = NULL ;
V_32:
F_79 ( & V_56 -> V_12 , V_13 ) ;
return V_3 ;
}
static struct V_4 * F_149 ( struct V_4 * V_3 )
{
struct V_4 * V_9 , * V_11 ;
struct V_55 * V_56 ;
unsigned long V_13 ;
int V_27 , V_71 = 0 ;
F_14 ( ! V_3 ) ;
F_14 ( ! F_150 ( & F_17 ( V_3 ) -> V_12 ) ) ;
V_9 = F_52 ( V_3 -> V_47 , V_3 -> V_2 , V_125 ) ;
if ( ! V_9 )
return NULL ;
V_56 = F_16 ( V_3 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_47 ; V_27 ++ ) {
F_14 ( ! V_3 -> V_28 [ V_27 ] ) ;
V_9 -> V_28 [ V_27 ] = F_89 ( V_3 -> V_28 [ V_27 ] ) ;
F_14 ( ! V_9 -> V_28 [ V_27 ] ) ;
F_14 ( ! V_9 -> V_28 [ V_27 ] -> V_3 . V_2 ) ;
F_14 ( ! V_9 -> V_28 [ V_27 ] -> V_3 . V_2 -> V_3 ) ;
if ( V_9 -> V_28 [ V_27 ] -> V_3 . V_2 != V_3 -> V_28 [ V_27 ] -> V_3 . V_2 )
V_71 ++ ;
}
if ( V_71 ) {
V_9 -> V_47 -= F_31 ( & V_9 -> V_28 [ 0 ] , V_9 -> V_47 ,
V_35 ) ;
if ( V_9 -> V_47 == 1 ) {
V_11 = F_12 ( & V_9 -> V_28 [ 0 ] -> V_3 ) ;
F_14 ( V_11 == V_3 ) ;
goto remove;
}
if ( F_16 ( V_3 ) != F_16 ( V_9 ) ) {
F_74 ( & V_56 -> V_12 , V_13 ) ;
V_11 = F_84 ( F_16 ( V_9 ) , V_9 ) ;
F_72 ( & V_56 -> V_12 , V_13 ) ;
goto remove;
}
} else
F_14 ( F_17 ( V_3 ) != F_17 ( V_9 ) ) ;
V_11 = F_64 ( F_16 ( V_3 ) , V_9 , true ) ;
remove:
F_58 ( V_3 , V_11 ) ;
F_74 ( & V_56 -> V_12 , V_13 ) ;
F_48 ( V_11 , V_9 ) ;
return V_11 ;
}
static void F_151 ( struct V_16 * V_24 )
{
struct V_4 * V_3 ;
F_14 ( ! V_24 ) ;
F_14 ( ! F_150 ( & V_24 -> V_12 ) ) ;
do {
V_3 = F_147 ( & V_24 -> V_76 ) ;
if ( V_3 ) {
struct V_4 * V_65 = F_149 ( V_3 ) ;
F_2 ( V_65 ) ;
F_2 ( V_3 ) ;
}
} while ( V_3 );
}
void F_152 ( struct V_16 * V_24 )
{
struct V_16 * V_126 ;
F_14 ( ! V_24 ) ;
F_14 ( ! F_150 ( & V_24 -> V_12 ) ) ;
F_151 ( V_24 ) ;
F_153 (child, &ns->sub_ns, base.list) {
F_154 ( & V_126 -> V_12 ) ;
F_152 ( V_126 ) ;
F_155 ( & V_126 -> V_12 ) ;
}
}
