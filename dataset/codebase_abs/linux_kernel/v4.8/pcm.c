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
V_15 = F_5 ( V_13 , V_16 ) ;
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
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( F_11 ( V_20 , & V_19 -> V_22 ) ) {
if ( ! F_12 ( V_20 , & V_19 -> V_23 ) )
F_13 ( V_19 -> V_24 [ V_20 ] ) ;
}
}
}
static void F_14 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
int V_25 = V_26 ;
int V_20 ;
int V_27 ;
do {
V_27 = 0 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( F_11 ( V_20 , & V_19 -> V_22 ) )
V_27 ++ ;
}
if ( ! V_27 )
break;
F_15 ( V_28 ) ;
F_16 ( 1 ) ;
} while ( -- V_25 > 0 );
if ( V_27 )
F_17 ( V_13 -> V_29 -> V_30 ,
L_1 , V_27 ) ;
}
static inline struct V_18 *
F_18 ( struct V_12 * V_13 , int V_31 )
{
return ( V_31 == V_32 ) ?
& V_13 -> V_33 : & V_13 -> V_34 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_18 * V_35 , int type )
{
if ( ! F_12 ( type , & V_35 -> V_36 ) && ! V_35 -> V_37 ) {
V_35 -> V_37 = F_20 ( V_21 * V_38 *
V_13 -> V_39 , V_40 ) ;
if ( ! V_35 -> V_37 )
return - V_41 ;
}
return 0 ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_18 * V_35 , int type )
{
F_22 ( type , & V_35 -> V_36 ) ;
if ( ! V_35 -> V_36 ) {
F_14 ( V_13 , V_35 ) ;
F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
}
}
static int F_24 ( struct V_12 * V_13 , int V_31 ,
int type )
{
unsigned long V_42 ;
struct V_18 * V_35 = F_18 ( V_13 , V_31 ) ;
int V_43 = 0 ;
F_25 ( & V_35 -> V_44 , V_42 ) ;
if ( ! F_12 ( type , & V_35 -> V_45 ) &&
! ( V_35 -> V_22 || V_35 -> V_23 ) ) {
V_35 -> V_6 = 0 ;
if ( V_31 == V_32 )
V_43 = F_26 ( V_13 ) ;
else
V_43 = F_27 ( V_13 ) ;
}
if ( V_43 < 0 )
F_22 ( type , & V_35 -> V_45 ) ;
F_28 ( & V_35 -> V_44 , V_42 ) ;
return V_43 ;
}
static void F_29 ( struct V_12 * V_13 , int V_31 ,
int type )
{
unsigned long V_42 ;
struct V_18 * V_35 = F_18 ( V_13 , V_31 ) ;
F_25 ( & V_35 -> V_44 , V_42 ) ;
F_22 ( type , & V_35 -> V_45 ) ;
if ( ! V_35 -> V_45 ) {
F_28 ( & V_35 -> V_44 , V_42 ) ;
F_10 ( V_13 , V_35 ) ;
F_25 ( & V_35 -> V_44 , V_42 ) ;
if ( V_31 == V_46 ) {
V_13 -> V_47 = NULL ;
V_13 -> V_48 = 0 ;
}
}
F_28 ( & V_35 -> V_44 , V_42 ) ;
}
int F_30 ( struct V_49 * V_50 , int V_51 )
{
struct V_12 * V_13 = F_31 ( V_50 ) ;
struct V_49 * V_52 ;
int V_15 ;
F_22 ( V_53 , & V_13 -> V_42 ) ;
F_32 (s, substream) {
if ( V_52 -> V_54 -> V_55 != V_50 -> V_54 -> V_55 )
continue;
switch ( V_51 ) {
case V_56 :
case V_57 :
V_15 = F_24 ( V_13 , V_52 -> V_58 ,
V_59 ) ;
if ( V_15 < 0 )
return V_15 ;
break;
case V_60 :
case V_61 :
F_29 ( V_13 , V_52 -> V_58 ,
V_59 ) ;
break;
case V_62 :
if ( V_52 -> V_58 != V_32 )
return - V_63 ;
F_33 ( V_64 , & V_13 -> V_42 ) ;
break;
case V_65 :
if ( V_52 -> V_58 != V_32 )
return - V_63 ;
F_22 ( V_64 , & V_13 -> V_42 ) ;
break;
default:
return - V_63 ;
}
}
return 0 ;
}
T_1 F_34 ( struct V_49 * V_50 )
{
struct V_12 * V_13 = F_31 ( V_50 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_50 -> V_58 ) ;
return V_35 -> V_66 ;
}
int F_5 ( struct V_12 * V_13 , int type )
{
struct V_18 * V_35 ;
int V_43 = 0 , V_67 ;
F_35 ( & V_13 -> V_68 ) ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
V_35 = F_18 ( V_13 , V_67 ) ;
V_43 = F_19 ( V_13 , V_35 , type ) ;
if ( V_43 < 0 )
goto error;
if ( ! V_35 -> V_45 )
F_14 ( V_13 , V_35 ) ;
}
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
V_43 = F_24 ( V_13 , V_67 , type ) ;
if ( V_43 < 0 )
goto error;
}
error:
F_36 ( & V_13 -> V_68 ) ;
if ( V_43 < 0 )
F_6 ( V_13 , type ) ;
return V_43 ;
}
void F_6 ( struct V_12 * V_13 , int type )
{
struct V_18 * V_35 ;
int V_67 ;
F_35 ( & V_13 -> V_68 ) ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ )
F_29 ( V_13 , V_67 , type ) ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
V_35 = F_18 ( V_13 , V_67 ) ;
F_21 ( V_13 , V_35 , type ) ;
}
F_36 ( & V_13 -> V_68 ) ;
}
int F_37 ( struct V_49 * V_50 ,
struct V_69 * V_70 )
{
int V_43 ;
struct V_12 * V_13 = F_31 ( V_50 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_50 -> V_58 ) ;
F_35 ( & V_13 -> V_68 ) ;
V_43 = F_19 ( V_13 , V_35 , V_59 ) ;
if ( V_43 < 0 )
goto error;
V_43 = F_38 ( V_50 ,
F_39 ( V_70 ) ) ;
if ( V_43 < 0 ) {
F_21 ( V_13 , V_35 , V_59 ) ;
goto error;
}
V_35 -> V_71 = F_40 ( V_70 ) ;
error:
F_36 ( & V_13 -> V_68 ) ;
return V_43 ;
}
int F_41 ( struct V_49 * V_50 )
{
struct V_12 * V_13 = F_31 ( V_50 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_50 -> V_58 ) ;
F_35 ( & V_13 -> V_68 ) ;
F_21 ( V_13 , V_35 , V_59 ) ;
F_36 ( & V_13 -> V_68 ) ;
return F_42 ( V_50 ) ;
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
V_11 -> V_7 . integer . V_7 [ V_20 ] = V_13 -> V_72 [ V_20 ] ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_20 , V_73 = 0 ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ )
if ( V_13 -> V_72 [ V_20 ] !=
V_11 -> V_7 . integer . V_7 [ V_20 ] ) {
V_13 -> V_72 [ V_20 ] =
V_11 -> V_7 . integer . V_7 [ V_20 ] ;
V_73 = 1 ;
}
return V_73 ;
}
static void F_46 ( struct V_18 * V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_19 -> V_24 [ V_20 ] ) {
F_47 ( V_19 -> V_24 [ V_20 ] ) ;
F_48 ( V_19 -> V_24 [ V_20 ] ) ;
}
}
}
static void F_49 ( struct V_74 * V_54 )
{
struct V_12 * V_13 = F_50 ( V_54 ) ;
F_46 ( & V_13 -> V_33 ) ;
F_46 ( & V_13 -> V_34 ) ;
F_23 ( V_13 ) ;
}
static int F_51 ( struct V_75 * V_29 , struct V_74 * * V_76 )
{
struct V_74 * V_54 ;
int V_15 ;
V_15 = F_52 ( V_29 -> V_55 , ( char * ) V_29 -> V_77 -> V_78 ,
0 , 1 , 1 , V_76 ) ;
if ( V_15 < 0 )
return V_15 ;
V_54 = * V_76 ;
strcpy ( V_54 -> V_78 , V_29 -> V_77 -> V_78 ) ;
F_53 ( V_54 , V_32 ,
& V_79 ) ;
F_53 ( V_54 , V_46 , & V_80 ) ;
F_54 ( V_54 , V_81 ,
F_55
( V_40 ) , 64 * 1024 ,
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
int F_57 ( struct V_75 * V_29 ,
struct V_82 * V_77 )
{
int V_20 , V_15 ;
unsigned V_83 = V_29 -> V_77 -> V_84 ;
unsigned V_85 = V_29 -> V_77 -> V_86 ;
struct V_74 * V_54 ;
struct V_12 * V_13 ;
if ( ! ( V_29 -> V_77 -> V_87 & V_88 ) )
return 0 ;
V_15 = F_51 ( V_29 , & V_54 ) ;
if ( V_15 < 0 )
return V_15 ;
V_13 = F_58 ( sizeof( * V_13 ) , V_40 ) ;
if ( ! V_13 )
return - V_41 ;
F_59 ( & V_13 -> V_68 ) ;
V_13 -> V_54 = V_54 ;
V_13 -> V_77 = V_77 ;
V_13 -> V_72 [ 0 ] = V_13 -> V_72 [ 1 ] = 255 ;
V_13 -> V_89 = 255 ;
V_13 -> V_29 = V_29 ;
V_13 -> V_39 = V_8 (
F_60 ( V_29 -> V_90 ,
F_61 ( V_29 -> V_90 , V_83 ) , 0 ) ,
F_60 ( V_29 -> V_90 ,
F_62 ( V_29 -> V_90 , V_85 ) , 1 ) ) ;
F_63 ( & V_13 -> V_33 . V_44 ) ;
F_63 ( & V_13 -> V_34 . V_44 ) ;
V_13 -> V_17 = V_91 ;
V_29 -> V_13 = V_13 ;
V_54 -> V_92 = V_13 ;
V_54 -> V_93 = F_49 ;
V_15 = F_64 ( V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_65 ( V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_20 = 0 ; V_20 < F_66 ( V_94 ) ; V_20 ++ ) {
V_15 = F_67 ( V_29 -> V_55 ,
F_68 ( & V_94 [ V_20 ] , V_13 ) ) ;
if ( V_15 < 0 )
return V_15 ;
}
return 0 ;
}
int F_69 ( struct V_49 * V_50 )
{
struct V_12 * V_13 = F_31 ( V_50 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_50 -> V_58 ) ;
F_35 ( & V_13 -> V_68 ) ;
if ( ! V_35 -> V_45 )
F_14 ( V_13 , V_35 ) ;
if ( ! F_12 ( V_53 , & V_13 -> V_42 ) ) {
V_13 -> V_33 . V_6 = 0 ;
V_13 -> V_33 . V_95 = 0 ;
V_13 -> V_33 . V_66 = 0 ;
V_13 -> V_33 . V_96 = 0 ;
V_13 -> V_34 . V_6 = 0 ;
V_13 -> V_34 . V_66 = 0 ;
V_13 -> V_34 . V_96 = 0 ;
}
F_36 ( & V_13 -> V_68 ) ;
return 0 ;
}
