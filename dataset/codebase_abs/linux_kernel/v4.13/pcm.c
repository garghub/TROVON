static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 255 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
V_11 -> V_7 . integer . V_7 [ 0 ] = V_13 -> V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_7 = V_11 -> V_7 . integer . V_7 [ 0 ] ;
int V_15 ;
if ( V_13 -> V_14 == V_7 )
return 0 ;
V_13 -> V_14 = V_7 ;
if ( V_7 > 0 ) {
V_15 = F_5 ( V_13 , V_16 , true ) ;
if ( V_15 < 0 ) {
V_13 -> V_14 = 0 ;
return V_15 ;
}
} else {
F_6 ( V_13 , V_16 ) ;
}
return 1 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 2000 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
V_11 -> V_7 . integer . V_7 [ 0 ] = V_13 -> V_17 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_7 = V_11 -> V_7 . integer . V_7 [ 0 ] ;
if ( V_13 -> V_17 == V_7 )
return 0 ;
V_13 -> V_17 = V_7 ;
return 1 ;
}
static void F_10 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_13 -> V_21 -> V_22 ; V_20 ++ ) {
if ( F_11 ( V_20 , & V_19 -> V_23 ) ) {
if ( ! F_12 ( V_20 , & V_19 -> V_24 ) )
F_13 ( V_19 -> V_25 [ V_20 ] ) ;
}
}
}
static void F_14 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
int V_26 = V_27 ;
int V_20 ;
int V_28 ;
do {
V_28 = 0 ;
for ( V_20 = 0 ; V_20 < V_13 -> V_21 -> V_22 ; V_20 ++ ) {
if ( F_11 ( V_20 , & V_19 -> V_23 ) )
V_28 ++ ;
}
if ( ! V_28 )
break;
F_15 ( V_29 ) ;
F_16 ( 1 ) ;
} while ( -- V_26 > 0 );
if ( V_28 )
F_17 ( V_13 -> V_21 -> V_30 ,
L_1 , V_28 ) ;
}
static inline struct V_18 *
F_18 ( struct V_12 * V_13 , int V_31 )
{
return ( V_31 == V_32 ) ?
& V_13 -> V_33 : & V_13 -> V_34 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_18 * V_35 , int V_31 , int type )
{
const int V_36 =
( V_31 == V_32 ) ?
V_13 -> V_37 :
V_13 -> V_38 ;
if ( ! F_12 ( type , & V_35 -> V_39 ) && ! V_35 -> V_40 ) {
V_35 -> V_40 = F_20 ( V_13 -> V_21 -> V_22 *
V_41 * V_36 , V_42 ) ;
if ( ! V_35 -> V_40 )
return - V_43 ;
}
return 0 ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_18 * V_35 , int type )
{
F_22 ( type , & V_35 -> V_39 ) ;
if ( ! V_35 -> V_39 ) {
F_14 ( V_13 , V_35 ) ;
F_23 ( V_35 -> V_40 ) ;
V_35 -> V_40 = NULL ;
}
}
static int F_24 ( struct V_12 * V_13 , int V_31 ,
int type )
{
unsigned long V_44 ;
struct V_18 * V_35 = F_18 ( V_13 , V_31 ) ;
int V_45 = 0 ;
F_25 ( & V_35 -> V_46 , V_44 ) ;
if ( ! F_12 ( type , & V_35 -> V_47 ) &&
! ( V_35 -> V_23 || V_35 -> V_24 ) ) {
V_35 -> V_6 = 0 ;
if ( V_31 == V_32 )
V_45 = F_26 ( V_13 ) ;
else
V_45 = F_27 ( V_13 ) ;
}
if ( V_45 < 0 )
F_22 ( type , & V_35 -> V_47 ) ;
F_28 ( & V_35 -> V_46 , V_44 ) ;
return V_45 ;
}
static void F_29 ( struct V_12 * V_13 , int V_31 ,
int type )
{
unsigned long V_44 ;
struct V_18 * V_35 = F_18 ( V_13 , V_31 ) ;
F_25 ( & V_35 -> V_46 , V_44 ) ;
F_22 ( type , & V_35 -> V_47 ) ;
if ( ! V_35 -> V_47 ) {
F_28 ( & V_35 -> V_46 , V_44 ) ;
F_10 ( V_13 , V_35 ) ;
F_25 ( & V_35 -> V_46 , V_44 ) ;
if ( V_31 == V_48 ) {
V_13 -> V_49 = NULL ;
V_13 -> V_50 = 0 ;
}
}
F_28 ( & V_35 -> V_46 , V_44 ) ;
}
int F_30 ( struct V_51 * V_52 , int V_53 )
{
struct V_12 * V_13 = F_31 ( V_52 ) ;
struct V_51 * V_54 ;
int V_15 ;
F_22 ( V_55 , & V_13 -> V_44 ) ;
F_32 (s, substream) {
if ( V_54 -> V_56 -> V_57 != V_52 -> V_56 -> V_57 )
continue;
switch ( V_53 ) {
case V_58 :
case V_59 :
if ( V_54 -> V_60 == V_48 &&
( V_13 -> V_21 -> V_61 -> V_62 &
V_63 ) ) {
V_15 = F_24 ( V_13 , V_32 ,
V_64 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_15 = F_24 ( V_13 , V_54 -> V_60 ,
V_65 ) ;
if ( V_15 < 0 )
return V_15 ;
break;
case V_66 :
case V_67 :
if ( V_54 -> V_60 == V_48 &&
( V_13 -> V_21 -> V_61 -> V_62 &
V_63 ) ) {
F_29 ( V_13 , V_32 ,
V_64 ) ;
}
F_29 ( V_13 , V_54 -> V_60 ,
V_65 ) ;
break;
case V_68 :
if ( V_54 -> V_60 != V_32 )
return - V_69 ;
F_33 ( V_70 , & V_13 -> V_44 ) ;
break;
case V_71 :
if ( V_54 -> V_60 != V_32 )
return - V_69 ;
F_22 ( V_70 , & V_13 -> V_44 ) ;
break;
default:
return - V_69 ;
}
}
return 0 ;
}
T_1 F_34 ( struct V_51 * V_52 )
{
struct V_12 * V_13 = F_31 ( V_52 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_52 -> V_60 ) ;
return V_35 -> V_72 ;
}
int F_5 ( struct V_12 * V_13 , int type , bool V_73 )
{
struct V_18 * V_35 ;
int V_45 = 0 , V_74 ;
F_35 ( & V_13 -> V_75 ) ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
V_35 = F_18 ( V_13 , V_74 ) ;
V_45 = F_19 ( V_13 , V_35 , V_74 , type ) ;
if ( V_45 < 0 )
goto error;
if ( ! V_35 -> V_47 )
F_14 ( V_13 , V_35 ) ;
}
if ( V_73 ) {
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
V_45 = F_24 ( V_13 , V_74 , type ) ;
if ( V_45 < 0 )
goto error;
}
}
error:
F_36 ( & V_13 -> V_75 ) ;
if ( V_45 < 0 )
F_6 ( V_13 , type ) ;
return V_45 ;
}
void F_6 ( struct V_12 * V_13 , int type )
{
struct V_18 * V_35 ;
int V_74 ;
F_35 ( & V_13 -> V_75 ) ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ )
F_29 ( V_13 , V_74 , type ) ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
V_35 = F_18 ( V_13 , V_74 ) ;
F_21 ( V_13 , V_35 , type ) ;
}
F_36 ( & V_13 -> V_75 ) ;
}
int F_37 ( struct V_51 * V_52 ,
struct V_76 * V_77 )
{
int V_45 ;
struct V_12 * V_13 = F_31 ( V_52 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_52 -> V_60 ) ;
F_35 ( & V_13 -> V_75 ) ;
V_45 = F_19 ( V_13 , V_35 , V_52 -> V_60 ,
V_65 ) ;
if ( V_45 < 0 )
goto error;
V_45 = F_38 ( V_52 ,
F_39 ( V_77 ) ) ;
if ( V_45 < 0 ) {
F_21 ( V_13 , V_35 , V_65 ) ;
goto error;
}
V_35 -> V_78 = F_40 ( V_77 ) ;
error:
F_36 ( & V_13 -> V_75 ) ;
return V_45 ;
}
int F_41 ( struct V_51 * V_52 )
{
struct V_12 * V_13 = F_31 ( V_52 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_52 -> V_60 ) ;
F_35 ( & V_13 -> V_75 ) ;
F_21 ( V_13 , V_35 , V_65 ) ;
F_36 ( & V_13 -> V_75 ) ;
return F_42 ( V_52 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 2 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 256 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_20 ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ )
V_11 -> V_7 . integer . V_7 [ V_20 ] = V_13 -> V_79 [ V_20 ] ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_20 , V_80 = 0 ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ )
if ( V_13 -> V_79 [ V_20 ] !=
V_11 -> V_7 . integer . V_7 [ V_20 ] ) {
V_13 -> V_79 [ V_20 ] =
V_11 -> V_7 . integer . V_7 [ V_20 ] ;
V_80 = 1 ;
}
return V_80 ;
}
static void F_46 ( struct V_18 * V_19 , int V_22 )
{
int V_20 ;
if ( V_19 -> V_25 == NULL )
return;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( V_19 -> V_25 [ V_20 ] ) {
F_47 ( V_19 -> V_25 [ V_20 ] ) ;
F_48 ( V_19 -> V_25 [ V_20 ] ) ;
}
}
F_23 ( V_19 -> V_25 ) ;
V_19 -> V_25 = NULL ;
}
static void F_49 ( struct V_81 * V_56 )
{
struct V_12 * V_13 = F_50 ( V_56 ) ;
F_46 ( & V_13 -> V_33 , V_13 -> V_21 -> V_22 ) ;
F_46 ( & V_13 -> V_34 , V_13 -> V_21 -> V_22 ) ;
F_23 ( V_13 ) ;
}
static int F_51 ( struct V_82 * V_21 , struct V_81 * * V_83 )
{
struct V_81 * V_56 ;
int V_15 ;
V_15 = F_52 ( V_21 -> V_57 , ( char * ) V_21 -> V_61 -> V_84 ,
0 , 1 , 1 , V_83 ) ;
if ( V_15 < 0 )
return V_15 ;
V_56 = * V_83 ;
strcpy ( V_56 -> V_84 , V_21 -> V_61 -> V_84 ) ;
F_53 ( V_56 , V_32 ,
& V_85 ) ;
F_53 ( V_56 , V_48 , & V_86 ) ;
F_54 ( V_56 , V_87 ,
F_55
( V_42 ) , 64 * 1024 ,
128 * 1024 ) ;
return 0 ;
}
void F_56 ( struct V_12 * V_13 )
{
F_10 ( V_13 , & V_13 -> V_33 ) ;
F_10 ( V_13 , & V_13 -> V_34 ) ;
F_14 ( V_13 , & V_13 -> V_33 ) ;
F_14 ( V_13 , & V_13 -> V_34 ) ;
}
int F_57 ( struct V_82 * V_21 ,
struct V_88 * V_61 )
{
int V_20 , V_15 ;
unsigned V_89 = V_21 -> V_61 -> V_90 ;
unsigned V_91 = V_21 -> V_61 -> V_92 ;
struct V_81 * V_56 ;
struct V_12 * V_13 ;
if ( ! ( V_21 -> V_61 -> V_62 & V_93 ) )
return 0 ;
V_15 = F_51 ( V_21 , & V_56 ) ;
if ( V_15 < 0 )
return V_15 ;
V_13 = F_58 ( sizeof( * V_13 ) , V_42 ) ;
if ( ! V_13 )
return - V_43 ;
F_59 ( & V_13 -> V_75 ) ;
V_13 -> V_56 = V_56 ;
V_13 -> V_61 = V_61 ;
V_13 -> V_79 [ 0 ] = V_13 -> V_79 [ 1 ] = 255 ;
V_13 -> V_94 = 255 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_38 =
F_60 ( V_21 -> V_95 ,
F_61 ( V_21 -> V_95 , V_89 ) , 0 ) ;
V_13 -> V_37 =
F_60 ( V_21 -> V_95 ,
F_62 ( V_21 -> V_95 , V_91 ) , 1 ) ;
F_63 ( & V_13 -> V_33 . V_46 ) ;
F_63 ( & V_13 -> V_34 . V_46 ) ;
V_13 -> V_17 = V_96 ;
V_21 -> V_13 = V_13 ;
V_56 -> V_97 = V_13 ;
V_56 -> V_98 = F_49 ;
V_15 = F_64 ( V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_65 ( V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_20 = 0 ; V_20 < F_66 ( V_99 ) ; V_20 ++ ) {
V_15 = F_67 ( V_21 -> V_57 ,
F_68 ( & V_99 [ V_20 ] , V_13 ) ) ;
if ( V_15 < 0 )
return V_15 ;
}
return 0 ;
}
int F_69 ( struct V_51 * V_52 )
{
struct V_12 * V_13 = F_31 ( V_52 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_52 -> V_60 ) ;
F_35 ( & V_13 -> V_75 ) ;
if ( ! V_35 -> V_47 )
F_14 ( V_13 , V_35 ) ;
if ( ! F_12 ( V_55 , & V_13 -> V_44 ) ) {
V_13 -> V_33 . V_6 = 0 ;
V_13 -> V_33 . V_100 = 0 ;
V_13 -> V_33 . V_72 = 0 ;
V_13 -> V_33 . V_101 = 0 ;
V_13 -> V_34 . V_6 = 0 ;
V_13 -> V_34 . V_72 = 0 ;
V_13 -> V_34 . V_101 = 0 ;
}
F_36 ( & V_13 -> V_75 ) ;
return 0 ;
}
