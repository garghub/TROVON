static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
int V_5 = V_2 -> V_6 ;
int V_7 = ( V_3 - V_5 + V_2 -> V_8 ) % V_2 -> V_8 ;
return V_2 -> V_8 - V_7 - 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_8 * sizeof( struct V_10 ) ;
V_2 -> V_11 = F_3 ( V_9 , V_12 ) ;
if ( ! V_2 -> V_11 )
return - V_13 ;
V_2 -> V_14 = F_4 ( F_5 ( V_2 ) , V_2 -> V_11 ,
V_9 , V_15 ) ;
if ( F_6 ( F_5 ( V_2 ) , V_2 -> V_14 ) ) {
V_2 -> V_14 = 0 ;
F_7 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return - V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( F_5 ( V_2 ) , V_2 -> V_14 ,
V_2 -> V_8 * sizeof( V_2 -> V_11 [ 0 ] ) ,
V_15 ) ;
V_2 -> V_14 = 0 ;
F_7 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
static int F_10 ( struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 = & V_17 -> V_20 ;
struct V_1 * V_2 =
( V_18 == V_21 ) ? & V_20 -> V_22 . V_23 : & V_20 -> V_22 . V_24 ;
int V_25 ;
V_2 -> V_26 = V_18 ;
V_2 -> V_27 = V_17 ;
V_25 = F_2 ( V_2 ) ;
if ( V_25 ) {
F_11 ( & V_17 -> V_28 -> V_27 , L_1 ,
( V_18 == V_21 ) ? L_2 : L_3 , V_25 ) ;
return V_25 ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_4 = 0 ;
return 0 ;
}
void F_12 ( struct V_10 * V_11 ,
enum V_29 V_30 , bool V_31 )
{
memset ( ( void * ) V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_30 = F_13 ( V_30 ) ;
V_11 -> V_26 = F_13 ( V_32 | V_33 ) ;
if ( V_31 )
V_11 -> V_26 |= F_13 ( V_34 ) ;
else
V_11 -> V_26 &= F_13 ( ~ V_34 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_35 = V_2 -> V_14 ;
struct V_16 * V_17 = V_2 -> V_27 ;
struct V_19 * V_20 = & V_17 -> V_20 ;
if ( V_2 -> V_26 == V_21 ) {
F_15 ( V_20 , V_36 ,
( V_37 ) V_35 ) ;
F_15 ( V_20 , V_38 ,
( V_37 ) ( ( V_35 >> 31 ) >> 1 ) ) ;
F_15 ( V_20 , V_39 ,
( V_2 -> V_8 >> V_40 ) |
V_41 ) ;
F_15 ( V_20 , V_42 , 0 ) ;
F_15 ( V_20 , V_43 , 0 ) ;
} else {
F_15 ( V_20 , V_44 ,
( V_37 ) V_35 ) ;
F_15 ( V_20 , V_45 ,
( V_37 ) ( ( V_35 >> 31 ) >> 1 ) ) ;
F_15 ( V_20 , V_46 ,
( V_2 -> V_8 >> V_40 ) |
V_41 ) ;
F_15 ( V_20 , V_47 , 0 ) ;
F_15 ( V_20 , V_48 , 0 ) ;
}
}
static void F_16 ( struct V_19 * V_20 )
{
F_14 ( & V_20 -> V_22 . V_23 ) ;
F_14 ( & V_20 -> V_22 . V_24 ) ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_23 = & V_20 -> V_22 . V_23 ;
T_2 V_5 = V_23 -> V_6 ;
struct V_10 * V_11 ;
int V_49 = 0 ;
V_37 V_50 ;
V_11 = & V_23 -> V_11 [ V_5 ] ;
V_50 = F_18 ( V_20 , V_43 ) ;
while ( V_50 != V_5 ) {
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_5 ++ ;
if ( V_5 == V_23 -> V_8 )
V_5 = 0 ;
V_11 = & V_23 -> V_11 [ V_5 ] ;
V_49 ++ ;
}
V_23 -> V_6 = V_5 ;
return V_49 ;
}
static int F_19 ( struct V_19 * V_20 )
{
V_37 V_50 = F_18 ( V_20 , V_43 ) ;
return V_50 == V_20 -> V_22 . V_23 . V_4 ;
}
static bool F_20 ( T_2 V_30 )
{
T_2 V_51 [ 3 ] = { 0x0030 , 0x0031 , 0x0032 } ;
int V_52 ;
for ( V_52 = 0 ; V_52 < F_21 ( V_51 ) ; V_52 ++ ) {
if ( V_51 [ V_52 ] == V_30 )
return true ;
}
return false ;
}
int F_22 ( struct V_19 * V_20 , struct V_10 * V_11 , int V_53 )
{
struct V_16 * V_17 = (struct V_16 * ) V_20 -> V_54 ;
struct V_10 * V_55 ;
bool V_56 = false ;
V_37 V_57 = 0 ;
int V_58 = 0 ;
int V_59 = 0 ;
T_2 V_30 , V_60 ;
int V_5 ;
F_23 ( & V_20 -> V_22 . V_23 . V_61 ) ;
if ( V_53 > F_1 ( & V_20 -> V_22 . V_23 ) ) {
F_24 ( & V_20 -> V_22 . V_23 . V_61 ) ;
return - V_62 ;
}
V_5 = V_20 -> V_22 . V_23 . V_4 ;
V_30 = V_11 [ 0 ] . V_30 ;
while ( V_58 < V_53 ) {
V_55 = & V_20 -> V_22 . V_23 . V_11 [ V_20 -> V_22 . V_23 . V_4 ] ;
* V_55 = V_11 [ V_58 ] ;
( V_20 -> V_22 . V_23 . V_4 ) ++ ;
if ( V_20 -> V_22 . V_23 . V_4 == V_20 -> V_22 . V_23 . V_8 )
V_20 -> V_22 . V_23 . V_4 = 0 ;
V_58 ++ ;
}
F_15 ( V_20 , V_42 , V_20 -> V_22 . V_23 . V_4 ) ;
if ( F_25 ( V_11 -> V_26 ) ) {
do {
if ( F_19 ( V_20 ) )
break;
F_26 ( 1 ) ;
V_57 ++ ;
} while ( V_57 < V_20 -> V_22 . V_63 );
}
if ( F_19 ( V_20 ) ) {
V_56 = true ;
V_58 = 0 ;
while ( V_58 < V_53 ) {
V_55 = & V_20 -> V_22 . V_23 . V_11 [ V_5 ] ;
V_11 [ V_58 ] = * V_55 ;
F_27 ( L_4 ) ;
if ( F_28 ( ! F_20 ( V_30 ) ) )
V_60 = V_11 [ V_58 ] . V_59 ;
else
V_60 = V_11 [ 0 ] . V_59 ;
if ( (enum V_64 ) V_60 ==
V_65 )
V_59 = 0 ;
else
V_59 = - V_66 ;
V_20 -> V_22 . V_67 = (enum V_68 ) V_60 ;
V_5 ++ ;
V_58 ++ ;
if ( V_5 == V_20 -> V_22 . V_23 . V_8 )
V_5 = 0 ;
}
}
if ( ! V_56 )
V_59 = - V_69 ;
V_58 = F_17 ( V_20 ) ;
if ( V_58 != V_53 ) {
F_29 ( & V_17 -> V_28 -> V_27 ,
L_5 , V_58 , V_53 ) ;
}
F_24 ( & V_20 -> V_22 . V_23 . V_61 ) ;
return V_59 ;
}
enum V_68 F_30 ( struct V_19 * V_20 ,
V_37 * V_70 )
{
struct V_71 * V_72 ;
struct V_10 V_11 ;
int V_25 ;
F_12 ( & V_11 , V_73 , 1 ) ;
V_72 = (struct V_71 * ) V_11 . V_74 ;
V_25 = F_22 ( V_20 , & V_11 , 1 ) ;
if ( ! V_25 )
* V_70 = F_31 ( V_72 -> V_75 ) ;
return V_25 ;
}
int F_32 ( struct V_16 * V_17 )
{
V_37 V_70 ;
int V_25 ;
V_17 -> V_20 . V_22 . V_23 . V_8 = V_76 ;
V_17 -> V_20 . V_22 . V_24 . V_8 = V_76 ;
F_33 ( & V_17 -> V_20 . V_22 . V_23 . V_61 ) ;
F_33 ( & V_17 -> V_20 . V_22 . V_24 . V_61 ) ;
V_17 -> V_20 . V_22 . V_63 = V_77 ;
V_25 = F_10 ( V_17 , V_21 ) ;
if ( V_25 ) {
F_11 ( & V_17 -> V_28 -> V_27 ,
L_6 , V_25 ) ;
return V_25 ;
}
V_25 = F_10 ( V_17 , V_78 ) ;
if ( V_25 ) {
F_11 ( & V_17 -> V_28 -> V_27 ,
L_7 , V_25 ) ;
goto V_79;
}
F_16 ( & V_17 -> V_20 ) ;
V_25 = F_30 ( & V_17 -> V_20 , & V_70 ) ;
if ( V_25 ) {
F_11 ( & V_17 -> V_28 -> V_27 ,
L_8 , V_25 ) ;
return V_25 ;
}
V_17 -> V_80 = V_70 ;
F_34 ( & V_17 -> V_28 -> V_27 , L_9 , V_70 ) ;
return 0 ;
V_79:
F_8 ( & V_17 -> V_20 . V_22 . V_23 ) ;
return V_25 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_61 ) ;
F_8 ( V_2 ) ;
F_24 ( & V_2 -> V_61 ) ;
}
void F_36 ( struct V_19 * V_20 )
{
F_35 ( & V_20 -> V_22 . V_23 ) ;
F_35 ( & V_20 -> V_22 . V_24 ) ;
}
