static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 . V_5 = V_3 -> V_6 ;
V_3 -> V_4 . V_7 =
F_2 ( V_3 ) ;
if ( ! V_3 -> V_4 . V_7 )
return - V_8 ;
return 0 ;
}
static int F_3 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 -> V_4 . V_7 )
F_4 ( V_3 -> V_4 . V_7 ) ;
return 0 ;
}
static int F_5 ( void * V_9 , int V_10 )
{
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
if ( ( V_10 < V_13 ) || ( V_10 > V_14 ) ) {
F_6 ( L_1 , V_10 ) ;
return - 1 ;
}
V_11 = F_7 ( V_9 , V_15 + V_10 ) ;
V_11 &= V_16 ;
if ( V_11 == 0x0 ) {
V_11 = F_7 ( V_9 , V_17 ) ;
V_11 = V_11 | ( 1 << V_10 ) ;
F_8 ( V_9 , V_17 , V_11 ) ;
F_8 ( V_9 , V_18 ,
0x500 + V_10 ) ;
V_12 = V_19 ;
while ( true ) {
V_11 = F_7 ( V_9 , V_15
+ V_10 ) ;
V_11 = V_11 & V_16 ;
if ( V_11 == V_20 )
break;
if ( -- V_12 == 0 ) {
F_6 ( L_2 ) ;
return - V_21 ;
}
F_9 ( 100 ) ;
}
V_11 = F_7 ( V_9 , V_17 ) ;
V_11 |= V_22 ;
F_8 ( V_9 , V_17 , V_11 ) ;
}
return 0 ;
}
static int F_10 ( void * V_9 , int V_10 )
{
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
if ( ( V_10 < V_13 ) || ( V_10 > V_14 ) ) {
F_6 ( L_3 ) ;
return - 1 ;
}
V_11 = F_7 ( V_9 , V_15 + V_10 ) ;
V_11 = V_11 & V_16 ;
if ( V_11 != 0x0 ) {
F_8 ( V_9 , V_18 ,
0x600 + V_10 ) ;
V_12 = V_19 ;
while ( true ) {
V_11 = F_7 ( V_9 , V_15
+ V_10 ) ;
V_11 = V_11 & V_16 ;
if ( V_11 == 0x0 )
break;
if ( -- V_12 == 0 ) {
F_6 ( L_2 ) ;
return - V_21 ;
}
F_9 ( 100 ) ;
}
V_11 = F_7 ( V_9 , V_17 ) ;
if ( V_10 == V_13 )
V_11 = V_11 & ( V_23 ) ;
else if ( V_10 == V_24 )
V_11 = V_11 & ( V_25 ) ;
F_8 ( V_9 , V_17 , V_11 ) ;
}
return 0 ;
}
static int F_11 ( struct V_26 * V_27 )
{
int V_28 , V_29 ;
struct V_30 * V_31 ;
V_31 = F_12 ( V_27 , struct V_30 , V_32 ) ;
if ( V_31 != NULL ) {
for ( V_28 = 4 ; V_28 >= 0 ; V_28 -- ) {
V_29 = F_5 ( V_31 -> V_9 , V_13 + V_28 ) ;
if ( V_29 )
F_6 ( L_4 , V_28 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_26 * V_27 )
{
int V_28 , V_29 ;
struct V_30 * V_31 ;
V_31 = F_12 ( V_27 , struct V_30 , V_32 ) ;
if ( V_31 != NULL ) {
for ( V_28 = 0 ; V_28 < 2 ; V_28 ++ ) {
V_29 = F_10 ( V_31 -> V_9 , V_13 + V_28 ) ;
if ( V_29 ) {
F_6 ( L_5 , V_28 ) ;
break;
}
}
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
V_29 = F_5 ( V_31 -> V_9 , V_33 + V_28 ) ;
if ( V_29 )
F_6 ( L_6 , V_28 ) ;
}
}
return 0 ;
}
static struct V_34 * F_14 ( const char * V_35 , int V_36 )
{
char V_37 [ 25 ] ;
struct V_34 * V_6 ;
snprintf ( V_37 , sizeof( V_37 ) ,
L_7 , V_35 , V_36 ) ;
V_6 = F_15 ( & V_38 , NULL , V_37 ) ;
F_16 ( V_6 , L_8 , V_37 ) ;
return V_6 ;
}
static int F_17 ( void * V_1 )
{
int V_36 , V_28 ;
T_2 V_39 ;
struct V_34 * V_6 ;
struct V_40 * V_41 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
const struct V_42 * V_43 =
F_18 ( V_3 , V_44 ) ;
if ( ! V_43 )
return - V_8 ;
V_36 = F_19 ( V_3 -> V_4 . V_7 ,
V_43 -> V_45 -> V_46 , V_43 -> V_45 -> V_47 ) ;
if ( V_36 == - V_48 )
return 0 ;
else if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_3 -> V_4 . V_7 , V_49 ,
0x5289 , 0 , & V_39 ) ;
if ( V_36 == - V_48 )
return 0 ;
else if ( V_36 )
return V_36 ;
if ( V_3 -> V_50 != V_51 ) {
V_3 -> V_4 . V_52 = F_21 ( sizeof( struct V_30 ) , V_53 ) ;
if ( V_3 -> V_4 . V_52 == NULL )
return - V_54 ;
V_3 -> V_4 . V_52 -> V_32 . V_55 = L_9 ;
V_3 -> V_4 . V_52 -> V_32 . V_56 = F_11 ;
V_3 -> V_4 . V_52 -> V_32 . V_57 = F_13 ;
V_3 -> V_4 . V_52 -> V_9 = V_3 -> V_4 . V_7 ;
F_22 ( & V_3 -> V_4 . V_52 -> V_32 , NULL , false ) ;
}
V_3 -> V_4 . V_58 = F_21 ( sizeof( struct V_59 ) * V_60 ,
V_53 ) ;
if ( V_3 -> V_4 . V_58 == NULL )
return - V_54 ;
V_3 -> V_4 . V_61 = F_21 ( sizeof( struct V_62 ) * 4 , V_53 ) ;
if ( V_3 -> V_4 . V_61 == NULL ) {
F_23 ( V_3 -> V_4 . V_58 ) ;
return - V_54 ;
}
V_41 = F_21 ( sizeof( struct V_40 ) * 2 , V_53 ) ;
if ( V_41 == NULL ) {
F_23 ( V_3 -> V_4 . V_61 ) ;
F_23 ( V_3 -> V_4 . V_58 ) ;
return - V_54 ;
}
switch ( V_3 -> V_50 ) {
case V_51 :
V_41 [ 0 ] . V_63 = V_64 |
V_65 ;
break;
default:
V_41 [ 0 ] . V_63 = V_64 ;
}
V_41 [ 0 ] . V_66 = V_67 ;
V_41 [ 0 ] . V_68 = V_69 ;
V_41 [ 0 ] . V_70 = V_71 ;
V_41 [ 0 ] . V_72 = V_73 ;
switch ( V_3 -> V_50 ) {
case V_51 :
V_41 [ 1 ] . V_63 = V_64 |
V_74 |
V_65 ;
break;
default:
V_41 [ 1 ] . V_63 = V_64 |
V_74 ;
}
V_41 [ 1 ] . V_66 = V_75 ;
V_41 [ 1 ] . V_68 = V_69 ;
V_41 [ 1 ] . V_70 = V_76 ;
V_41 [ 1 ] . V_72 = V_77 ;
V_3 -> V_4 . V_61 [ 0 ] . V_55 = L_10 ;
V_3 -> V_4 . V_61 [ 0 ] . V_78 = V_79 ;
V_3 -> V_4 . V_61 [ 0 ] . V_80 = V_39 ;
V_3 -> V_4 . V_61 [ 0 ] . V_81 = V_39 + V_82 ;
V_3 -> V_4 . V_61 [ 1 ] . V_55 = L_11 ;
V_3 -> V_4 . V_61 [ 1 ] . V_78 = V_79 ;
V_3 -> V_4 . V_61 [ 1 ] . V_80 = V_39 + V_83 ;
V_3 -> V_4 . V_61 [ 1 ] . V_81 = V_39 + V_84 ;
V_3 -> V_4 . V_61 [ 2 ] . V_55 = L_12 ;
V_3 -> V_4 . V_61 [ 2 ] . V_78 = V_79 ;
V_3 -> V_4 . V_61 [ 2 ] . V_80 = V_39 + V_85 ;
V_3 -> V_4 . V_61 [ 2 ] . V_81 = V_39 + V_86 ;
V_3 -> V_4 . V_61 [ 3 ] . V_55 = L_13 ;
V_3 -> V_4 . V_61 [ 3 ] . V_78 = V_87 ;
V_3 -> V_4 . V_61 [ 3 ] . V_80 = F_24 ( V_3 , 162 ) ;
V_3 -> V_4 . V_61 [ 3 ] . V_81 = V_3 -> V_4 . V_61 [ 3 ] . V_80 ;
V_3 -> V_4 . V_58 [ 0 ] . V_55 = L_14 ;
V_3 -> V_4 . V_58 [ 0 ] . V_88 = 4 ;
V_3 -> V_4 . V_58 [ 0 ] . V_89 = & V_3 -> V_4 . V_61 [ 0 ] ;
V_3 -> V_4 . V_58 [ 1 ] . V_55 = L_15 ;
V_3 -> V_4 . V_58 [ 1 ] . V_88 = 1 ;
V_3 -> V_4 . V_58 [ 1 ] . V_89 = & V_3 -> V_4 . V_61 [ 1 ] ;
V_3 -> V_4 . V_58 [ 1 ] . V_90 = & V_41 [ 0 ] ;
V_3 -> V_4 . V_58 [ 1 ] . V_91 = sizeof( struct V_40 ) ;
V_3 -> V_4 . V_58 [ 2 ] . V_55 = L_15 ;
V_3 -> V_4 . V_58 [ 2 ] . V_88 = 1 ;
V_3 -> V_4 . V_58 [ 2 ] . V_89 = & V_3 -> V_4 . V_61 [ 2 ] ;
V_3 -> V_4 . V_58 [ 2 ] . V_90 = & V_41 [ 1 ] ;
V_3 -> V_4 . V_58 [ 2 ] . V_91 = sizeof( struct V_40 ) ;
V_36 = F_25 ( V_3 -> V_4 . V_5 , V_3 -> V_4 . V_58 ,
V_60 ) ;
if ( V_36 )
return V_36 ;
if ( V_3 -> V_50 != V_51 ) {
for ( V_28 = 0 ; V_28 < V_60 ; V_28 ++ ) {
V_6 = F_14 ( V_3 -> V_4 . V_58 [ V_28 ] . V_55 , V_28 ) ;
V_36 = F_26 ( & V_3 -> V_4 . V_52 -> V_32 , V_6 ) ;
if ( V_36 ) {
F_27 ( V_6 , L_16 ) ;
return V_36 ;
}
}
}
return 0 ;
}
static int F_28 ( void * V_1 )
{
int V_28 , V_29 ;
struct V_34 * V_6 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( ! V_3 -> V_4 . V_58 )
return 0 ;
if ( V_3 -> V_4 . V_52 ) {
for ( V_28 = 0 ; V_28 < V_60 ; V_28 ++ ) {
V_6 = F_14 ( V_3 -> V_4 . V_58 [ V_28 ] . V_55 , V_28 ) ;
V_29 = F_29 ( & V_3 -> V_4 . V_52 -> V_32 , V_6 ) ;
if ( V_29 )
F_27 ( V_6 , L_17 ) ;
}
F_23 ( V_3 -> V_4 . V_52 ) ;
}
F_30 ( V_3 -> V_4 . V_5 ) ;
F_23 ( V_3 -> V_4 . V_61 ) ;
F_23 ( V_3 -> V_4 . V_58 ) ;
return 0 ;
}
static int F_31 ( void * V_1 )
{
return 0 ;
}
static int F_32 ( void * V_1 )
{
return 0 ;
}
static int F_33 ( void * V_1 )
{
return 0 ;
}
static bool F_34 ( void * V_1 )
{
return true ;
}
static int F_35 ( void * V_1 )
{
return 0 ;
}
static int F_36 ( void * V_1 )
{
return 0 ;
}
static int F_37 ( void * V_1 ,
enum V_92 V_93 )
{
return 0 ;
}
static int F_38 ( void * V_1 ,
enum V_94 V_93 )
{
return 0 ;
}
