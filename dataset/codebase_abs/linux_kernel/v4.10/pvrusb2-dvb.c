static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( V_9 , L_1 ) ;
F_3 () ;
V_8 = V_2 -> V_10 . V_8 -> V_8 ;
for (; ; ) {
if ( F_4 () ) break;
F_5 () ;
V_6 = F_6 ( V_8 ) ;
if ( V_6 != NULL ) {
V_4 = F_7 ( V_6 ) ;
if ( V_4 ) {
F_8 (
& V_2 -> V_11 ,
V_2 -> V_12 [
F_9 ( V_6 ) ] ,
V_4 ) ;
} else {
V_3 = F_10 ( V_6 ) ;
if ( V_3 < 0 ) break;
}
V_3 = F_11 ( V_6 ) ;
if ( V_3 < 0 ) break;
continue;
}
V_3 = F_12 (
V_2 -> V_13 ,
( F_13 ( V_8 ) > 0 ) ||
F_4 () ) ;
if ( V_3 < 0 ) break;
}
F_2 ( V_9 , L_2 ) ;
return 0 ;
}
static int F_14 ( void * V_14 )
{
int V_15 = F_1 ( V_14 ) ;
while ( ! F_4 () ) {
F_15 ( V_16 ) ;
F_16 () ;
}
return V_15 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned int V_17 ;
struct V_7 * V_8 ;
if ( V_2 -> V_18 ) {
F_20 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
if ( V_2 -> V_10 . V_8 ) {
V_8 = V_2 -> V_10 . V_8 -> V_8 ;
} else {
V_8 = NULL ;
}
if ( V_8 ) {
F_21 ( V_2 -> V_10 . V_19 , 0 ) ;
F_22 ( V_8 , NULL , NULL ) ;
F_23 ( V_8 ) ;
F_24 ( V_8 , 0 ) ;
F_25 ( & V_2 -> V_10 , NULL ) ;
}
if ( V_2 -> V_20 ) {
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
if ( ! ( V_2 -> V_12 [ V_17 ] ) ) continue;
F_26 ( V_2 -> V_12 [ V_17 ] ) ;
V_2 -> V_12 [ V_17 ] = NULL ;
}
V_2 -> V_20 = 0 ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_10 . V_24 ;
unsigned int V_17 ;
int V_3 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
if ( V_2 -> V_20 ) return - V_25 ;
V_3 = F_25 ( & V_2 -> V_10 , & V_23 -> V_26 ) ;
if ( V_3 < 0 ) return V_3 ;
V_8 = V_2 -> V_10 . V_8 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_2 -> V_12 [ V_17 ] = F_28 ( V_27 ,
V_28 ) ;
if ( ! ( V_2 -> V_12 [ V_17 ] ) ) return - V_29 ;
}
F_22 ( V_23 -> V_26 . V_8 ,
( V_30 ) F_17 , V_2 ) ;
V_3 = F_24 ( V_8 , V_21 ) ;
if ( V_3 < 0 ) return V_3 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_6 = F_29 ( V_8 , V_17 ) ;
F_30 ( V_6 ,
V_2 -> V_12 [ V_17 ] ,
V_27 ) ;
}
V_3 = F_21 ( V_2 -> V_10 . V_19 , 1 ) ;
if ( V_3 < 0 ) return V_3 ;
while ( ( V_6 = F_31 ( V_8 ) ) != NULL ) {
V_3 = F_11 ( V_6 ) ;
if ( V_3 < 0 ) return V_3 ;
}
V_2 -> V_18 = F_32 ( F_14 , V_2 , L_3 ) ;
if ( F_33 ( V_2 -> V_18 ) ) {
V_3 = F_34 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
return V_3 ;
}
V_2 -> V_20 = ! 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_3 = F_27 ( V_2 ) ;
if ( V_3 < 0 ) F_19 ( V_2 ) ;
return V_3 ;
}
static int F_36 ( struct V_31 * V_32 , int V_33 )
{
struct V_1 * V_2 = V_32 -> V_11 -> V_34 ;
int V_3 = 0 ;
if ( V_2 == NULL ) return - V_35 ;
F_37 ( & V_2 -> V_36 ) ;
do {
if ( V_33 ) {
if ( ! V_2 -> V_37 ) {
F_2 ( V_9 ,
L_4 ) ;
V_3 = F_35 ( V_2 ) ;
if ( V_3 < 0 ) break;
}
( V_2 -> V_37 ) ++ ;
} else if ( V_2 -> V_37 > 0 ) {
( V_2 -> V_37 ) -- ;
if ( ! V_2 -> V_37 ) {
F_2 ( V_9 ,
L_5 ) ;
F_19 ( V_2 ) ;
}
}
} while ( 0 );
F_38 ( & V_2 -> V_36 ) ;
return V_3 ;
}
static int F_39 ( struct V_31 * V_32 )
{
F_2 ( V_9 , L_6 , V_32 -> V_38 ) ;
return F_36 ( V_32 , 1 ) ;
}
static int F_40 ( struct V_31 * V_32 )
{
F_2 ( V_9 , L_7 , V_32 -> V_38 ) ;
return F_36 ( V_32 , 0 ) ;
}
static int F_41 ( struct V_39 * V_40 , int V_41 )
{
struct V_1 * V_2 = V_40 -> V_42 -> V_34 ;
return F_42 (
& V_2 -> V_10 ,
( V_41 ? ( 1 << V_43 ) : 0 ) ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_44 ( & V_2 -> V_44 , L_3 ,
V_45 ,
& V_2 -> V_10 . V_19 -> V_46 -> V_47 ,
V_48 ) ;
if ( V_3 < 0 ) {
F_2 ( V_49 ,
L_8 , V_3 ) ;
goto V_50;
}
V_2 -> V_44 . V_34 = V_2 ;
V_2 -> V_11 . V_51 . V_52 = V_53 |
V_54 |
V_55 ;
V_2 -> V_11 . V_34 = V_2 ;
V_2 -> V_11 . V_56 = 256 ;
V_2 -> V_11 . V_57 = 256 ;
V_2 -> V_11 . V_58 = F_39 ;
V_2 -> V_11 . V_59 = F_40 ;
V_2 -> V_11 . V_60 = NULL ;
V_3 = F_45 ( & V_2 -> V_11 ) ;
if ( V_3 < 0 ) {
F_2 ( V_49 ,
L_9 , V_3 ) ;
goto V_61;
}
V_2 -> V_62 . V_56 = V_2 -> V_11 . V_56 ;
V_2 -> V_62 . V_11 = & V_2 -> V_11 . V_51 ;
V_2 -> V_62 . V_52 = 0 ;
V_3 = F_46 ( & V_2 -> V_62 , & V_2 -> V_44 ) ;
if ( V_3 < 0 ) {
F_2 ( V_49 ,
L_10 , V_3 ) ;
goto V_63;
}
F_47 ( & V_2 -> V_44 , & V_2 -> V_64 , & V_2 -> V_11 . V_51 ) ;
return 0 ;
V_63:
F_48 ( & V_2 -> V_11 ) ;
V_61:
F_49 ( & V_2 -> V_44 ) ;
V_50:
return V_3 ;
}
static int F_50 ( struct V_1 * V_2 )
{
F_2 ( V_65 , L_11 ) ;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_11 . V_51 . V_66 ( & V_2 -> V_11 . V_51 ) ;
F_52 ( & V_2 -> V_62 ) ;
F_48 ( & V_2 -> V_11 ) ;
F_49 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_67 * V_19 = V_2 -> V_10 . V_19 ;
const struct V_68 * V_69 = V_19 -> V_70 -> V_69 ;
int V_3 = 0 ;
if ( V_69 == NULL ) {
F_2 ( V_49 , L_12 ) ;
return - V_71 ;
}
V_3 = F_42 (
& V_2 -> V_10 ,
( 1 << V_43 ) ) ;
if ( V_3 ) {
F_2 ( V_49 ,
L_13 ,
V_3 ) ;
return V_3 ;
}
if ( V_69 -> V_72 == NULL ) {
F_2 ( V_49 ,
L_14 ) ;
V_3 = - V_71 ;
goto V_73;
}
if ( ( V_69 -> V_72 ( V_2 ) == 0 ) && ( V_2 -> V_40 ) ) {
if ( F_54 ( & V_2 -> V_44 , V_2 -> V_40 ) ) {
F_2 ( V_49 ,
L_15 ) ;
F_55 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
V_3 = - V_35 ;
goto V_73;
}
if ( V_69 -> V_74 )
V_69 -> V_74 ( V_2 ) ;
if ( V_2 -> V_40 -> V_75 . V_76 . V_77 )
V_2 -> V_40 -> V_75 . V_76 . V_77 ( V_2 -> V_40 ) ;
V_2 -> V_40 -> V_75 . V_78 = F_41 ;
} else {
F_2 ( V_49 ,
L_16 ) ;
V_3 = - V_35 ;
return V_3 ;
}
V_73:
F_42 ( & V_2 -> V_10 , 0 ) ;
return V_3 ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 != NULL ) {
F_57 ( V_2 -> V_40 ) ;
F_55 ( V_2 -> V_40 ) ;
}
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_56 ( V_2 ) ;
F_50 ( V_2 ) ;
F_59 ( & V_2 -> V_10 ) ;
F_26 ( V_2 ) ;
}
static void F_60 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( V_80 , struct V_1 , V_10 ) ;
if ( ! V_2 -> V_10 . V_24 -> V_81 ) return;
F_58 ( V_2 ) ;
}
struct V_1 * F_62 ( struct V_22 * V_23 )
{
int V_3 = 0 ;
struct V_1 * V_2 ;
if ( ! V_23 -> V_19 -> V_70 -> V_69 ) {
return NULL ;
}
V_2 = F_63 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) return V_2 ;
F_64 ( & V_2 -> V_10 , V_23 ) ;
V_2 -> V_10 . V_82 = F_60 ;
F_65 ( & V_2 -> V_13 ) ;
F_66 ( & V_2 -> V_36 ) ;
V_3 = F_43 ( V_2 ) ;
if ( V_3 < 0 ) goto V_83;
V_3 = F_53 ( V_2 ) ;
if ( V_3 < 0 ) goto V_84;
return V_2 ;
V_84:
F_50 ( V_2 ) ;
V_83:
F_59 ( & V_2 -> V_10 ) ;
return NULL ;
}
