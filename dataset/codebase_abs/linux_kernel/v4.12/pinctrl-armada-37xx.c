static inline void F_1 ( unsigned int * V_1 ,
unsigned int V_2 )
{
if ( V_2 >= V_3 ) {
V_2 -= V_3 ;
* V_1 += sizeof( V_4 ) ;
}
}
static int F_2 ( struct V_5 * V_6 ,
const char * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
if ( ! strcmp ( V_6 -> V_10 [ V_8 ] , V_7 ) )
return V_8 ;
return - V_11 ;
}
static struct V_5 * F_3 (
struct V_12 * V_13 , int V_14 , int * V_6 )
{
while ( * V_6 < V_13 -> V_15 ) {
struct V_5 * V_16 = & V_13 -> V_17 [ * V_6 ] ;
int V_18 ;
* V_6 = * V_6 + 1 ;
for ( V_18 = 0 ; V_18 < ( V_16 -> V_19 + V_16 -> V_20 ) ; V_18 ++ )
if ( V_16 -> V_21 [ V_18 ] == V_14 )
return V_16 ;
}
return NULL ;
}
static int F_4 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned long * V_25 )
{
return - V_11 ;
}
static int F_5 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned long * V_26 ,
unsigned int V_27 )
{
return - V_11 ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_15 ;
}
static const char * F_8 ( struct V_22 * V_23 ,
unsigned int V_16 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_17 [ V_16 ] . V_28 ;
}
static int F_9 ( struct V_22 * V_23 ,
unsigned int V_24 ,
const unsigned int * * V_21 ,
unsigned int * V_19 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
if ( V_24 >= V_13 -> V_15 )
return - V_29 ;
* V_21 = V_13 -> V_17 [ V_24 ] . V_21 ;
* V_19 = V_13 -> V_17 [ V_24 ] . V_19 +
V_13 -> V_17 [ V_24 ] . V_20 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_30 ;
}
static const char * F_11 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_10 [ V_24 ] . V_28 ;
}
static int F_12 ( struct V_22 * V_23 ,
unsigned int V_24 ,
const char * const * * V_17 ,
unsigned int * const V_31 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
* V_17 = V_13 -> V_10 [ V_24 ] . V_17 ;
* V_31 = V_13 -> V_10 [ V_24 ] . V_15 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
const char * V_28 ,
struct V_5 * V_6 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
unsigned int V_1 = V_32 ;
unsigned int V_33 = V_6 -> V_34 ;
int V_7 , V_35 ;
F_14 ( V_13 -> V_36 , L_1 ,
V_28 , V_6 -> V_28 ) ;
V_7 = F_2 ( V_6 , V_28 ) ;
if ( V_7 < 0 )
return V_7 ;
V_35 = V_6 -> V_35 [ V_7 ] ;
F_15 ( V_13 -> V_37 , V_1 , V_33 , V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
unsigned int V_24 ,
unsigned int V_16 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
struct V_5 * V_6 = & V_13 -> V_17 [ V_16 ] ;
const char * V_28 = V_13 -> V_10 [ V_24 ] . V_28 ;
return F_13 ( V_23 , V_28 , V_6 ) ;
}
static int F_17 ( struct V_38 * V_39 ,
unsigned int V_2 )
{
struct V_12 * V_13 = F_18 ( V_39 ) ;
unsigned int V_1 = V_40 ;
unsigned int V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_19 ( V_2 ) ;
return F_15 ( V_13 -> V_37 , V_1 , V_33 , 0 ) ;
}
static int F_20 ( struct V_38 * V_39 ,
unsigned int V_2 )
{
struct V_12 * V_13 = F_18 ( V_39 ) ;
unsigned int V_1 = V_40 ;
unsigned int V_35 , V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_19 ( V_2 ) ;
F_21 ( V_13 -> V_37 , V_1 , & V_35 ) ;
return ! ( V_35 & V_33 ) ;
}
static int F_22 ( struct V_38 * V_39 ,
unsigned int V_2 , int V_41 )
{
struct V_12 * V_13 = F_18 ( V_39 ) ;
unsigned int V_1 = V_40 ;
unsigned int V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_19 ( V_2 ) ;
return F_15 ( V_13 -> V_37 , V_1 , V_33 , V_33 ) ;
}
static int F_23 ( struct V_38 * V_39 , unsigned int V_2 )
{
struct V_12 * V_13 = F_18 ( V_39 ) ;
unsigned int V_1 = V_42 ;
unsigned int V_35 , V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_19 ( V_2 ) ;
F_21 ( V_13 -> V_37 , V_1 , & V_35 ) ;
return ( V_35 & V_33 ) != 0 ;
}
static void F_24 ( struct V_38 * V_39 , unsigned int V_2 ,
int V_41 )
{
struct V_12 * V_13 = F_18 ( V_39 ) ;
unsigned int V_1 = V_43 ;
unsigned int V_33 , V_35 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_19 ( V_2 ) ;
V_35 = V_41 ? V_33 : 0 ;
F_15 ( V_13 -> V_37 , V_1 , V_33 , V_35 ) ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_44 * V_45 ,
unsigned int V_2 , bool V_46 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
struct V_38 * V_39 = V_45 -> V_47 ;
F_14 ( V_13 -> V_36 , L_2 ,
V_2 , V_45 -> V_28 , V_2 , V_46 ? L_3 : L_4 ) ;
if ( V_46 )
F_17 ( V_39 , V_2 ) ;
else
F_22 ( V_39 , V_2 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_44 * V_45 ,
unsigned int V_2 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
struct V_5 * V_16 ;
int V_6 = 0 ;
F_14 ( V_13 -> V_36 , L_5 , V_2 ) ;
while ( ( V_16 = F_3 ( V_13 , V_2 , & V_6 ) ) )
F_13 ( V_23 , L_6 , V_16 ) ;
return 0 ;
}
static int F_27 ( struct V_48 * V_49 ,
struct V_12 * V_13 )
{
struct V_50 * V_51 ;
struct V_38 * V_47 ;
int V_52 = - V_53 ;
F_28 (info->dev->of_node, np) {
if ( F_29 ( V_51 , L_7 , NULL ) ) {
V_52 = 0 ;
break;
}
} ;
if ( V_52 )
return V_52 ;
V_13 -> V_38 = V_54 ;
V_47 = & V_13 -> V_38 ;
V_47 -> V_55 = V_13 -> V_56 -> V_57 ;
V_47 -> V_58 = & V_49 -> V_36 ;
V_47 -> V_59 = - 1 ;
V_47 -> V_60 = V_51 ;
V_47 -> V_61 = V_13 -> V_56 -> V_28 ;
V_52 = F_30 ( & V_49 -> V_36 , V_47 , V_13 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
static int F_31 ( struct V_62 * V_10 ,
int * V_63 , const char * V_28 )
{
int V_64 = 0 ;
if ( * V_63 <= 0 )
return - V_65 ;
while ( V_10 -> V_15 ) {
if ( strcmp ( V_10 -> V_28 , V_28 ) == 0 ) {
V_10 -> V_15 ++ ;
return - V_66 ;
}
V_10 ++ ;
V_64 ++ ;
}
V_10 -> V_28 = V_28 ;
V_10 -> V_15 = 1 ;
( * V_63 ) -- ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 )
{
int V_67 , V_68 = 0 , V_63 = V_13 -> V_56 -> V_57 ;
for ( V_67 = 0 ; V_67 < V_13 -> V_15 ; V_67 ++ ) {
struct V_5 * V_6 = & V_13 -> V_17 [ V_67 ] ;
int V_64 , V_18 , V_8 ;
V_6 -> V_21 = F_33 ( V_13 -> V_36 ,
( V_6 -> V_19 + V_6 -> V_20 ) *
sizeof( * V_6 -> V_21 ) , V_69 ) ;
if ( ! V_6 -> V_21 )
return - V_70 ;
for ( V_64 = 0 ; V_64 < V_6 -> V_19 ; V_64 ++ )
V_6 -> V_21 [ V_64 ] = V_6 -> V_71 + V_64 ;
for ( V_18 = 0 ; V_18 < V_6 -> V_20 ; V_18 ++ )
V_6 -> V_21 [ V_64 + V_18 ] = V_6 -> V_72 + V_18 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
int V_52 ;
V_52 = F_31 ( V_13 -> V_10 , & V_63 ,
V_6 -> V_10 [ V_8 ] ) ;
if ( V_52 == - V_65 )
F_34 ( V_13 -> V_36 ,
L_8 ,
V_13 -> V_56 -> V_57 ) ;
if ( V_52 < 0 )
continue;
V_68 ++ ;
}
}
V_13 -> V_30 = V_68 ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_62 * V_10 = V_13 -> V_10 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_13 -> V_30 ; V_67 ++ ) {
const char * V_28 = V_10 [ V_67 ] . V_28 ;
const char * * V_17 ;
int V_73 ;
V_10 [ V_67 ] . V_17 = F_33 ( V_13 -> V_36 , V_10 [ V_67 ] . V_15 *
sizeof( * ( V_10 [ V_67 ] . V_17 ) ) ,
V_69 ) ;
if ( ! V_10 [ V_67 ] . V_17 )
return - V_70 ;
V_17 = V_10 [ V_67 ] . V_17 ;
for ( V_73 = 0 ; V_73 < V_13 -> V_15 ; V_73 ++ ) {
struct V_5 * V_74 = & V_13 -> V_17 [ V_73 ] ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( strcmp ( V_74 -> V_10 [ V_8 ] , V_28 ) == 0 ) {
* V_17 = V_74 -> V_28 ;
V_17 ++ ;
}
}
}
}
return 0 ;
}
static int F_36 ( struct V_48 * V_49 ,
struct V_12 * V_13 )
{
const struct V_75 * V_76 = V_13 -> V_56 ;
struct V_77 * V_78 = & V_13 -> V_79 ;
struct V_80 * V_81 , * V_82 ;
int V_14 , V_52 ;
V_13 -> V_17 = V_76 -> V_17 ;
V_13 -> V_15 = V_76 -> V_15 ;
V_78 -> V_28 = L_9 ;
V_78 -> V_83 = V_84 ;
V_78 -> V_85 = & V_86 ;
V_78 -> V_87 = & V_88 ;
V_78 -> V_89 = & V_90 ;
V_81 = F_33 ( & V_49 -> V_36 , sizeof( * V_81 ) *
V_76 -> V_57 , V_69 ) ;
if ( ! V_81 )
return - V_70 ;
V_78 -> V_21 = V_81 ;
V_78 -> V_19 = V_76 -> V_57 ;
V_82 = V_81 ;
for ( V_14 = 0 ; V_14 < V_76 -> V_57 ; V_14 ++ ) {
V_82 -> V_91 = V_14 ;
V_82 -> V_28 = F_37 ( V_69 , L_10 ,
V_76 -> V_28 , V_14 ) ;
V_82 ++ ;
}
V_13 -> V_10 = F_33 ( & V_49 -> V_36 , V_76 -> V_57 *
sizeof( struct V_62 ) , V_69 ) ;
if ( ! V_13 -> V_10 )
return - V_70 ;
V_52 = F_32 ( V_13 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_35 ( V_13 ) ;
if ( V_52 )
return V_52 ;
V_13 -> V_92 = F_38 ( & V_49 -> V_36 , V_78 , V_13 ) ;
if ( F_39 ( V_13 -> V_92 ) ) {
F_34 ( & V_49 -> V_36 , L_11 ) ;
return F_40 ( V_13 -> V_92 ) ;
}
return 0 ;
}
static int T_1 F_41 ( struct V_48 * V_49 )
{
struct V_12 * V_13 ;
struct V_93 * V_36 = & V_49 -> V_36 ;
struct V_50 * V_51 = V_36 -> V_60 ;
struct V_37 * V_37 ;
int V_52 ;
V_13 = F_33 ( V_36 , sizeof( struct V_12 ) ,
V_69 ) ;
if ( ! V_13 )
return - V_70 ;
V_13 -> V_36 = V_36 ;
V_37 = F_42 ( V_51 ) ;
if ( F_39 ( V_37 ) ) {
F_34 ( & V_49 -> V_36 , L_12 ) ;
return F_40 ( V_37 ) ;
}
V_13 -> V_37 = V_37 ;
V_13 -> V_56 = F_43 ( V_36 ) ;
V_52 = F_36 ( V_49 , V_13 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_27 ( V_49 , V_13 ) ;
if ( V_52 )
return V_52 ;
F_44 ( V_49 , V_13 ) ;
return 0 ;
}
