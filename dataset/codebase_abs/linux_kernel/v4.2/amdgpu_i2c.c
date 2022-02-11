static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_11 ;
F_3 ( & V_4 -> V_12 ) ;
if ( V_10 -> V_13 ) {
V_11 = F_4 ( V_10 -> V_14 ) ;
V_11 &= ~ ( 1 << 16 ) ;
F_5 ( V_10 -> V_14 , V_11 ) ;
}
V_11 = F_4 ( V_10 -> V_15 ) & ~ V_10 -> V_16 ;
F_5 ( V_10 -> V_15 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_17 ) & ~ V_10 -> V_18 ;
F_5 ( V_10 -> V_17 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_19 ) & ~ V_10 -> V_20 ;
F_5 ( V_10 -> V_19 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_21 ) & ~ V_10 -> V_22 ;
F_5 ( V_10 -> V_21 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_14 ) | V_10 -> V_23 ;
F_5 ( V_10 -> V_14 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_14 ) ;
V_11 = F_4 ( V_10 -> V_24 ) | V_10 -> V_25 ;
F_5 ( V_10 -> V_24 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_24 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_11 ;
V_11 = F_4 ( V_10 -> V_14 ) & ~ V_10 -> V_23 ;
F_5 ( V_10 -> V_14 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_14 ) ;
V_11 = F_4 ( V_10 -> V_24 ) & ~ V_10 -> V_25 ;
F_5 ( V_10 -> V_24 , V_11 ) ;
V_11 = F_4 ( V_10 -> V_24 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
static int F_8 ( void * V_26 )
{
struct V_3 * V_4 = V_26 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_27 ;
V_27 = F_4 ( V_10 -> V_28 ) ;
V_27 &= V_10 -> V_29 ;
return ( V_27 != 0 ) ;
}
static int F_9 ( void * V_26 )
{
struct V_3 * V_4 = V_26 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_27 ;
V_27 = F_4 ( V_10 -> V_30 ) ;
V_27 &= V_10 -> V_31 ;
return ( V_27 != 0 ) ;
}
static void F_10 ( void * V_26 , int clock )
{
struct V_3 * V_4 = V_26 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_27 ;
V_27 = F_4 ( V_10 -> V_19 ) & ~ V_10 -> V_20 ;
V_27 |= clock ? 0 : V_10 -> V_20 ;
F_5 ( V_10 -> V_19 , V_27 ) ;
}
static void F_11 ( void * V_26 , int V_32 )
{
struct V_3 * V_4 = V_26 ;
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_27 ;
V_27 = F_4 ( V_10 -> V_21 ) & ~ V_10 -> V_22 ;
V_27 |= V_32 ? 0 : V_10 -> V_22 ;
F_5 ( V_10 -> V_21 , V_27 ) ;
}
struct V_3 * F_12 ( struct V_33 * V_7 ,
struct V_9 * V_10 ,
const char * V_34 )
{
struct V_3 * V_4 ;
int V_35 ;
if ( V_10 -> V_36 && ( V_37 == 0 ) )
return NULL ;
V_4 = F_13 ( sizeof( struct V_3 ) , V_38 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_10 = * V_10 ;
V_4 -> V_39 . V_40 = V_41 ;
V_4 -> V_39 . V_42 = V_43 ;
V_4 -> V_39 . V_7 . V_44 = & V_7 -> V_45 -> V_7 ;
V_4 -> V_7 = V_7 ;
F_14 ( & V_4 -> V_39 , V_4 ) ;
F_15 ( & V_4 -> V_12 ) ;
if ( V_10 -> V_13 &&
V_37 ) {
snprintf ( V_4 -> V_39 . V_34 , sizeof( V_4 -> V_39 . V_34 ) ,
L_1 , V_34 ) ;
V_4 -> V_39 . V_46 = & V_47 ;
V_35 = F_16 ( & V_4 -> V_39 ) ;
if ( V_35 ) {
F_17 ( L_2 , V_34 ) ;
goto V_48;
}
} else {
snprintf ( V_4 -> V_39 . V_34 , sizeof( V_4 -> V_39 . V_34 ) ,
L_3 , V_34 ) ;
V_4 -> V_39 . V_49 = & V_4 -> V_50 ;
V_4 -> V_50 . V_51 = F_1 ;
V_4 -> V_50 . V_52 = F_6 ;
V_4 -> V_50 . V_53 = F_11 ;
V_4 -> V_50 . V_54 = F_10 ;
V_4 -> V_50 . V_55 = F_9 ;
V_4 -> V_50 . V_56 = F_8 ;
V_4 -> V_50 . V_57 = 10 ;
V_4 -> V_50 . V_58 = F_18 ( 2200 ) ;
V_4 -> V_50 . V_32 = V_4 ;
V_35 = F_19 ( & V_4 -> V_39 ) ;
if ( V_35 ) {
F_17 ( L_4 , V_34 ) ;
goto V_48;
}
}
return V_4 ;
V_48:
F_20 ( V_4 ) ;
return NULL ;
}
void F_21 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_22 ( & V_4 -> V_39 ) ;
F_20 ( V_4 ) ;
}
void F_23 ( struct V_5 * V_6 )
{
if ( V_37 )
F_24 ( L_5 ) ;
if ( V_6 -> V_59 )
F_25 ( V_6 ) ;
}
void F_26 ( struct V_5 * V_6 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( V_6 -> V_62 [ V_60 ] ) {
F_21 ( V_6 -> V_62 [ V_60 ] ) ;
V_6 -> V_62 [ V_60 ] = NULL ;
}
}
}
void F_27 ( struct V_5 * V_6 ,
struct V_9 * V_10 ,
const char * V_34 )
{
struct V_33 * V_7 = V_6 -> V_63 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( ! V_6 -> V_62 [ V_60 ] ) {
V_6 -> V_62 [ V_60 ] = F_12 ( V_7 , V_10 , V_34 ) ;
return;
}
}
}
struct V_3 *
F_28 ( struct V_5 * V_6 ,
struct V_9 * V_62 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( V_6 -> V_62 [ V_60 ] &&
( V_6 -> V_62 [ V_60 ] -> V_10 . V_64 == V_62 -> V_64 ) ) {
return V_6 -> V_62 [ V_60 ] ;
}
}
return NULL ;
}
static void F_29 ( struct V_3 * V_62 ,
T_2 V_65 ,
T_2 V_66 ,
T_2 * V_27 )
{
T_2 V_67 [ 2 ] ;
T_2 V_68 [ 2 ] ;
struct V_69 V_70 [] = {
{
. V_66 = V_65 ,
. V_71 = 0 ,
. V_72 = 1 ,
. V_73 = V_67 ,
} ,
{
. V_66 = V_65 ,
. V_71 = V_74 ,
. V_72 = 1 ,
. V_73 = V_68 ,
}
} ;
V_67 [ 0 ] = V_66 ;
V_67 [ 1 ] = 0 ;
if ( F_30 ( & V_62 -> V_39 , V_70 , 2 ) == 2 ) {
* V_27 = V_68 [ 0 ] ;
F_31 ( L_6 , * V_27 ) ;
} else {
F_31 ( L_7 ,
V_66 , * V_27 ) ;
}
}
static void F_32 ( struct V_3 * V_62 ,
T_2 V_65 ,
T_2 V_66 ,
T_2 V_27 )
{
T_3 V_67 [ 2 ] ;
struct V_69 V_75 = {
. V_66 = V_65 ,
. V_71 = 0 ,
. V_72 = 2 ,
. V_73 = V_67 ,
} ;
V_67 [ 0 ] = V_66 ;
V_67 [ 1 ] = V_27 ;
if ( F_30 ( & V_62 -> V_39 , & V_75 , 1 ) != 1 )
F_31 ( L_8 ,
V_66 , V_27 ) ;
}
void
F_33 ( struct V_76 * V_76 )
{
T_2 V_27 ;
if ( ! V_76 -> V_77 . V_78 )
return;
if ( ! V_76 -> V_79 )
return;
F_29 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x3 , & V_27 ) ;
V_27 &= ~ V_76 -> V_77 . V_81 ;
F_32 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x3 , V_27 ) ;
F_29 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x1 , & V_27 ) ;
V_27 &= ~ V_76 -> V_77 . V_81 ;
V_27 |= V_76 -> V_77 . V_82 ;
F_32 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x1 , V_27 ) ;
}
void
F_34 ( struct V_76 * V_76 )
{
T_2 V_27 ;
if ( ! V_76 -> V_77 . V_83 )
return;
if ( ! V_76 -> V_79 )
return;
F_29 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x3 , & V_27 ) ;
V_27 &= ~ V_76 -> V_77 . V_84 ;
F_32 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x3 , V_27 ) ;
F_29 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x1 , & V_27 ) ;
V_27 &= ~ V_76 -> V_77 . V_84 ;
V_27 |= V_76 -> V_77 . V_85 ;
F_32 ( V_76 -> V_79 ,
V_76 -> V_77 . V_80 ,
0x1 , V_27 ) ;
}
