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
F_6 ( V_13 , V_16 ) ;
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
if ( ! F_12 ( type , & V_35 -> V_45 ) ) {
if ( V_35 -> V_22 || V_35 -> V_23 ) {
V_43 = - V_46 ;
goto error;
}
V_35 -> V_6 = 0 ;
if ( V_31 == V_32 )
V_43 = F_26 ( V_13 ) ;
else
V_43 = F_27 ( V_13 ) ;
}
error:
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
F_10 ( V_13 , V_35 ) ;
if ( V_31 == V_47 ) {
V_13 -> V_48 = NULL ;
V_13 -> V_49 = 0 ;
}
}
F_28 ( & V_35 -> V_44 , V_42 ) ;
}
int F_30 ( struct V_50 * V_51 , int V_52 )
{
struct V_12 * V_13 = F_31 ( V_51 ) ;
struct V_50 * V_53 ;
int V_15 ;
F_22 ( V_54 , & V_13 -> V_42 ) ;
F_32 (s, substream) {
if ( V_53 -> V_55 -> V_56 != V_51 -> V_55 -> V_56 )
continue;
switch ( V_52 ) {
case V_57 :
case V_58 :
V_15 = F_24 ( V_13 , V_53 -> V_59 ,
V_60 ) ;
if ( V_15 < 0 )
return V_15 ;
break;
case V_61 :
case V_62 :
F_29 ( V_13 , V_53 -> V_59 ,
V_60 ) ;
break;
case V_63 :
if ( V_53 -> V_59 != V_32 )
return - V_64 ;
F_33 ( V_65 , & V_13 -> V_42 ) ;
break;
case V_66 :
if ( V_53 -> V_59 != V_32 )
return - V_64 ;
F_22 ( V_65 , & V_13 -> V_42 ) ;
break;
default:
return - V_64 ;
}
}
return 0 ;
}
T_1 F_34 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_31 ( V_51 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_51 -> V_59 ) ;
return V_35 -> V_67 ;
}
int F_5 ( struct V_12 * V_13 , int type )
{
struct V_18 * V_35 ;
int V_43 = 0 , V_68 ;
F_35 ( & V_13 -> V_69 ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_35 = F_18 ( V_13 , V_68 ) ;
V_43 = F_19 ( V_13 , V_35 , type ) ;
if ( V_43 < 0 )
goto error;
if ( ! V_35 -> V_45 )
F_14 ( V_13 , V_35 ) ;
}
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_43 = F_24 ( V_13 , V_68 , type ) ;
if ( V_43 < 0 )
goto error;
}
error:
F_36 ( & V_13 -> V_69 ) ;
if ( V_43 < 0 )
F_6 ( V_13 , type ) ;
return V_43 ;
}
void F_6 ( struct V_12 * V_13 , int type )
{
struct V_18 * V_35 ;
int V_68 ;
F_35 ( & V_13 -> V_69 ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ )
F_29 ( V_13 , V_68 , type ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_35 = F_18 ( V_13 , V_68 ) ;
F_21 ( V_13 , V_35 , type ) ;
}
F_36 ( & V_13 -> V_69 ) ;
}
int F_37 ( struct V_50 * V_51 ,
struct V_70 * V_71 )
{
int V_43 ;
struct V_12 * V_13 = F_31 ( V_51 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_51 -> V_59 ) ;
F_35 ( & V_13 -> V_69 ) ;
V_43 = F_19 ( V_13 , V_35 , V_60 ) ;
if ( V_43 < 0 )
goto error;
V_43 = F_38 ( V_51 ,
F_39 ( V_71 ) ) ;
if ( V_43 < 0 ) {
F_21 ( V_13 , V_35 , V_60 ) ;
goto error;
}
V_35 -> V_72 = F_40 ( V_71 ) ;
error:
F_36 ( & V_13 -> V_69 ) ;
return V_43 ;
}
int F_41 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_31 ( V_51 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_51 -> V_59 ) ;
F_35 ( & V_13 -> V_69 ) ;
F_21 ( V_13 , V_35 , V_60 ) ;
F_36 ( & V_13 -> V_69 ) ;
return F_42 ( V_51 ) ;
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
V_11 -> V_7 . integer . V_7 [ V_20 ] = V_13 -> V_73 [ V_20 ] ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_20 , V_74 = 0 ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ )
if ( V_13 -> V_73 [ V_20 ] !=
V_11 -> V_7 . integer . V_7 [ V_20 ] ) {
V_13 -> V_73 [ V_20 ] =
V_11 -> V_7 . integer . V_7 [ V_20 ] ;
V_74 = 1 ;
}
return V_74 ;
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
static void F_49 ( struct V_75 * V_55 )
{
struct V_12 * V_13 = F_50 ( V_55 ) ;
F_46 ( & V_13 -> V_33 ) ;
F_46 ( & V_13 -> V_34 ) ;
F_23 ( V_13 ) ;
}
static int F_51 ( struct V_76 * V_29 , struct V_75 * * V_77 )
{
struct V_75 * V_55 ;
int V_15 ;
V_15 = F_52 ( V_29 -> V_56 , ( char * ) V_29 -> V_78 -> V_79 ,
0 , 1 , 1 , V_77 ) ;
if ( V_15 < 0 )
return V_15 ;
V_55 = * V_77 ;
strcpy ( V_55 -> V_79 , V_29 -> V_78 -> V_79 ) ;
F_53 ( V_55 , V_32 ,
& V_80 ) ;
F_53 ( V_55 , V_47 , & V_81 ) ;
F_54 ( V_55 , V_82 ,
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
int F_57 ( struct V_76 * V_29 ,
struct V_83 * V_78 )
{
int V_20 , V_15 ;
unsigned V_84 = V_29 -> V_78 -> V_85 ;
unsigned V_86 = V_29 -> V_78 -> V_87 ;
struct V_75 * V_55 ;
struct V_12 * V_13 ;
if ( ! ( V_29 -> V_78 -> V_88 & V_89 ) )
return 0 ;
V_15 = F_51 ( V_29 , & V_55 ) ;
if ( V_15 < 0 )
return V_15 ;
V_13 = F_58 ( sizeof( * V_13 ) , V_40 ) ;
if ( ! V_13 )
return - V_41 ;
F_59 ( & V_13 -> V_69 ) ;
V_13 -> V_55 = V_55 ;
V_13 -> V_78 = V_78 ;
V_13 -> V_73 [ 0 ] = V_13 -> V_73 [ 1 ] = 255 ;
V_13 -> V_90 = 255 ;
V_13 -> V_29 = V_29 ;
V_13 -> V_39 = V_8 (
F_60 ( V_29 -> V_91 ,
F_61 ( V_29 -> V_91 , V_84 ) , 0 ) ,
F_60 ( V_29 -> V_91 ,
F_62 ( V_29 -> V_91 , V_86 ) , 1 ) ) ;
F_63 ( & V_13 -> V_33 . V_44 ) ;
F_63 ( & V_13 -> V_34 . V_44 ) ;
V_13 -> V_17 = V_92 ;
V_29 -> V_13 = V_13 ;
V_55 -> V_93 = V_13 ;
V_55 -> V_94 = F_49 ;
V_15 = F_64 ( V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_65 ( V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_20 = 0 ; V_20 < F_66 ( V_95 ) ; V_20 ++ ) {
V_15 = F_67 ( V_29 -> V_56 ,
F_68 ( & V_95 [ V_20 ] , V_13 ) ) ;
if ( V_15 < 0 )
return V_15 ;
}
return 0 ;
}
int F_69 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_31 ( V_51 ) ;
struct V_18 * V_35 = F_18 ( V_13 , V_51 -> V_59 ) ;
F_35 ( & V_13 -> V_69 ) ;
if ( ! V_35 -> V_45 )
F_14 ( V_13 , V_35 ) ;
if ( ! F_12 ( V_54 , & V_13 -> V_42 ) ) {
V_13 -> V_33 . V_6 = 0 ;
V_13 -> V_33 . V_96 = 0 ;
V_13 -> V_33 . V_67 = 0 ;
V_13 -> V_33 . V_97 = 0 ;
V_13 -> V_34 . V_6 = 0 ;
V_13 -> V_34 . V_67 = 0 ;
V_13 -> V_34 . V_97 = 0 ;
}
F_36 ( & V_13 -> V_69 ) ;
return 0 ;
}
