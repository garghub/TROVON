static int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_1 == V_4 [ V_2 ] )
return V_2 ;
F_2 () ;
return - 1 ;
}
static unsigned int F_3 ( int V_1 )
{
return V_5 << V_1 ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_1 )
{
bool V_11 = F_5 ( V_10 ) ;
struct V_12 * V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
struct V_6 * V_6 ;
if ( ! V_11 ) {
V_6 = F_6 ( V_13 ) ;
} else {
T_1 V_15 = V_16 ;
if ( V_1 > 4 )
V_15 = V_17 ;
V_6 = F_7 ( V_15 , V_1 ) ;
if ( ! V_6 )
return NULL ;
F_8 ( NULL , V_6 , V_5 << V_1 ,
V_18 ) ;
}
if ( ! V_6 )
return NULL ;
return V_6 ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_6 * V_6 ,
unsigned int V_1 )
{
bool V_11 = F_5 ( V_10 ) ;
if ( ! V_11 ) {
struct V_12 * V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
F_10 ( V_13 , V_6 ) ;
} else {
F_11 ( V_6 , V_1 ) ;
}
}
static struct V_19 * F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_20 ,
unsigned int V_21 )
{
struct V_6 * V_6 ;
struct V_19 * V_22 ;
int V_2 ;
V_22 = F_13 ( sizeof( struct V_19 ) , V_23 ) ;
if ( ! V_22 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_20 < F_3 ( V_4 [ V_2 ] ) )
continue;
if ( V_21 < V_4 [ V_2 ] )
continue;
V_6 = F_4 ( V_8 , V_10 , V_4 [ V_2 ] ) ;
if ( ! V_6 )
continue;
V_22 -> V_6 = V_6 ;
V_22 -> V_1 = V_4 [ V_2 ] ;
F_14 ( & V_22 -> V_24 ) ;
return V_22 ;
}
F_15 ( V_22 ) ;
return NULL ;
}
static int F_16 ( struct V_25 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_20 , unsigned long V_26 ,
unsigned long V_27 )
{
struct V_7 * V_28 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_33 ;
struct V_34 V_35 ;
struct V_19 * V_22 , * V_36 ;
int V_2 = 0 ;
unsigned long V_37 = F_18 ( V_20 ) ;
unsigned int V_21 = V_4 [ 0 ] ;
if ( V_26 > V_5 )
return - V_38 ;
if ( V_20 / V_5 > V_39 / 2 )
return - V_40 ;
F_14 ( & V_35 ) ;
while ( V_37 > 0 ) {
V_22 = F_12 ( V_28 , V_10 , V_37 ,
V_21 ) ;
if ( ! V_22 )
goto V_41;
F_19 ( & V_22 -> V_24 , & V_35 ) ;
V_37 -= ( 1 << V_22 -> V_1 ) * V_5 ;
V_21 = V_22 -> V_1 ;
V_2 ++ ;
}
V_30 = F_20 ( sizeof( struct V_29 ) , V_23 ) ;
if ( ! V_30 )
goto V_41;
V_33 = F_21 ( V_30 , V_2 , V_23 ) ;
if ( V_33 )
goto V_42;
V_32 = V_30 -> V_43 ;
F_22 (info, tmp_info, &pages, list) {
struct V_6 * V_6 = V_22 -> V_6 ;
F_23 ( V_32 , V_6 , ( 1 << V_22 -> V_1 ) * V_5 , 0 ) ;
V_32 = F_24 ( V_32 ) ;
F_25 ( & V_22 -> V_24 ) ;
F_15 ( V_22 ) ;
}
V_10 -> V_44 = V_30 ;
return 0 ;
V_42:
F_15 ( V_30 ) ;
V_41:
F_22 (info, tmp_info, &pages, list) {
F_9 ( V_28 , V_10 , V_22 -> V_6 , V_22 -> V_1 ) ;
F_15 ( V_22 ) ;
}
return - V_40 ;
}
static void F_26 ( struct V_9 * V_10 )
{
struct V_25 * V_8 = V_10 -> V_8 ;
struct V_7 * V_28 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_29 * V_30 = V_10 -> V_29 ;
bool V_11 = F_5 ( V_10 ) ;
struct V_31 * V_32 ;
F_27 ( V_35 ) ;
int V_2 ;
if ( ! V_11 )
F_28 ( V_10 ) ;
F_29 (table->sgl, sg, table->nents, i)
F_9 ( V_28 , V_10 , F_30 ( V_32 ) ,
F_31 ( V_32 -> V_45 ) ) ;
F_32 ( V_30 ) ;
F_15 ( V_30 ) ;
}
static struct V_29 * F_33 ( struct V_25 * V_8 ,
struct V_9 * V_10 )
{
return V_10 -> V_44 ;
}
static void F_34 ( struct V_25 * V_8 ,
struct V_9 * V_10 )
{
return;
}
static unsigned long F_35 ( struct V_46 * V_46 ,
struct V_47 * V_48 )
{
struct V_25 * V_8 = F_17 ( V_46 , struct V_25 ,
V_46 ) ;
struct V_7 * V_28 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_49 = 0 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_28 -> V_14 [ V_2 ] ;
V_49 += F_36 ( V_13 , V_48 -> V_50 , 0 ) ;
}
V_49 += F_37 ( V_8 ) / V_5 ;
return V_49 ;
}
static unsigned long F_38 ( struct V_46 * V_46 ,
struct V_47 * V_48 )
{
struct V_25 * V_8 = F_17 ( V_46 , struct V_25 ,
V_46 ) ;
struct V_7 * V_28 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_51 = 0 ;
int V_2 ;
if ( V_48 -> V_52 == 0 )
goto V_53;
V_51 += F_39 ( V_8 , V_48 -> V_52 * V_5 ) /
V_5 ;
if ( V_51 >= V_48 -> V_52 )
goto V_53;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_28 -> V_14 [ V_2 ] ;
V_51 += F_36 ( V_13 , V_48 -> V_50 ,
V_48 -> V_52 ) ;
if ( V_51 >= V_48 -> V_52 )
break;
}
V_53:
return V_51 ;
}
static int F_40 ( struct V_25 * V_8 , struct V_54 * V_55 ,
void * V_56 )
{
struct V_7 * V_28 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_28 -> V_14 [ V_2 ] ;
F_41 ( V_55 , L_1 ,
V_13 -> V_57 , V_13 -> V_1 ,
( 1 << V_13 -> V_1 ) * V_5 * V_13 -> V_57 ) ;
F_41 ( V_55 , L_2 ,
V_13 -> V_58 , V_13 -> V_1 ,
( 1 << V_13 -> V_1 ) * V_5 * V_13 -> V_58 ) ;
}
return 0 ;
}
struct V_25 * F_42 ( struct V_59 * V_56 )
{
struct V_7 * V_8 ;
int V_2 ;
V_8 = F_20 ( sizeof( struct V_7 ) , V_23 ) ;
if ( ! V_8 )
return F_43 ( - V_40 ) ;
V_8 -> V_8 . V_60 = & V_61 ;
V_8 -> V_8 . type = V_62 ;
V_8 -> V_8 . V_27 = V_63 ;
V_8 -> V_14 = F_20 ( sizeof( struct V_12 * ) * V_3 ,
V_23 ) ;
if ( ! V_8 -> V_14 )
goto V_64;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 ;
T_1 V_15 = V_16 ;
if ( V_4 [ V_2 ] > 4 )
V_15 = V_17 ;
V_13 = F_44 ( V_15 , V_4 [ V_2 ] ) ;
if ( ! V_13 )
goto V_65;
V_8 -> V_14 [ V_2 ] = V_13 ;
}
V_8 -> V_8 . V_46 . V_66 = F_38 ;
V_8 -> V_8 . V_46 . V_67 = F_35 ;
V_8 -> V_8 . V_46 . V_68 = V_69 ;
V_8 -> V_8 . V_46 . V_70 = 0 ;
F_45 ( & V_8 -> V_8 . V_46 ) ;
V_8 -> V_8 . V_71 = F_40 ;
return & V_8 -> V_8 ;
V_65:
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_8 -> V_14 [ V_2 ] )
F_46 ( V_8 -> V_14 [ V_2 ] ) ;
F_15 ( V_8 -> V_14 ) ;
V_64:
F_15 ( V_8 ) ;
return F_43 ( - V_40 ) ;
}
void F_47 ( struct V_25 * V_8 )
{
struct V_7 * V_28 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_46 ( V_28 -> V_14 [ V_2 ] ) ;
F_15 ( V_28 -> V_14 ) ;
F_15 ( V_28 ) ;
}
static int F_48 ( struct V_25 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_72 ,
unsigned long V_26 ,
unsigned long V_27 )
{
int V_1 = F_31 ( V_72 ) ;
struct V_6 * V_6 ;
struct V_29 * V_30 ;
unsigned long V_2 ;
int V_33 ;
if ( V_26 > ( V_5 << V_1 ) )
return - V_38 ;
V_6 = F_7 ( V_16 , V_1 ) ;
if ( ! V_6 )
return - V_40 ;
F_49 ( V_6 , V_1 ) ;
V_72 = F_18 ( V_72 ) ;
for ( V_2 = V_72 >> V_73 ; V_2 < ( 1 << V_1 ) ; V_2 ++ )
F_50 ( V_6 + V_2 ) ;
V_30 = F_20 ( sizeof( struct V_29 ) , V_23 ) ;
if ( ! V_30 ) {
V_33 = - V_40 ;
goto V_74;
}
V_33 = F_21 ( V_30 , 1 , V_23 ) ;
if ( V_33 )
goto V_74;
F_23 ( V_30 -> V_43 , V_6 , V_72 , 0 ) ;
V_10 -> V_44 = V_30 ;
F_8 ( NULL , V_6 , V_72 , V_18 ) ;
return 0 ;
V_74:
for ( V_2 = 0 ; V_2 < V_72 > > V_73 ; V_2 ++ )
F_50 ( V_6 + V_2 ) ;
F_15 ( V_30 ) ;
return V_33 ;
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_29 * V_30 = V_10 -> V_44 ;
struct V_6 * V_6 = F_30 ( V_30 -> V_43 ) ;
unsigned long V_35 = F_18 ( V_10 -> V_20 ) >> V_73 ;
unsigned long V_2 ;
for ( V_2 = 0 ; V_2 < V_35 ; V_2 ++ )
F_50 ( V_6 + V_2 ) ;
F_32 ( V_30 ) ;
F_15 ( V_30 ) ;
}
static int F_52 ( struct V_25 * V_8 ,
struct V_9 * V_10 ,
T_2 * V_75 , T_3 * V_72 )
{
struct V_29 * V_30 = V_10 -> V_44 ;
struct V_6 * V_6 = F_30 ( V_30 -> V_43 ) ;
* V_75 = F_53 ( V_6 ) ;
* V_72 = V_10 -> V_20 ;
return 0 ;
}
static struct V_29 * F_54 ( struct V_25 * V_8 ,
struct V_9 * V_10 )
{
return V_10 -> V_44 ;
}
static void F_55 ( struct V_25 * V_8 ,
struct V_9 * V_10 )
{
}
struct V_25 * F_56 ( struct V_59 * V_56 )
{
struct V_25 * V_8 ;
V_8 = F_20 ( sizeof( struct V_25 ) , V_23 ) ;
if ( ! V_8 )
return F_43 ( - V_40 ) ;
V_8 -> V_60 = & V_76 ;
V_8 -> type = V_77 ;
return V_8 ;
}
void F_57 ( struct V_25 * V_8 )
{
F_15 ( V_8 ) ;
}
