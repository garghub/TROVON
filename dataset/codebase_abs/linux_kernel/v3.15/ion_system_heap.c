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
if ( ! V_11 && ! ( V_10 -> V_19 & V_20 ) ) {
struct V_12 * V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
F_10 ( V_13 , V_6 ) ;
} else {
F_11 ( V_6 , V_1 ) ;
}
}
static struct V_21 * F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_22 ,
unsigned int V_23 )
{
struct V_6 * V_6 ;
struct V_21 * V_24 ;
int V_2 ;
V_24 = F_13 ( sizeof( struct V_21 ) , V_25 ) ;
if ( ! V_24 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_22 < F_3 ( V_4 [ V_2 ] ) )
continue;
if ( V_23 < V_4 [ V_2 ] )
continue;
V_6 = F_4 ( V_8 , V_10 , V_4 [ V_2 ] ) ;
if ( ! V_6 )
continue;
V_24 -> V_6 = V_6 ;
V_24 -> V_1 = V_4 [ V_2 ] ;
F_14 ( & V_24 -> V_26 ) ;
return V_24 ;
}
F_15 ( V_24 ) ;
return NULL ;
}
static int F_16 ( struct V_27 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_22 , unsigned long V_28 ,
unsigned long V_29 )
{
struct V_7 * V_30 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 ;
struct V_36 V_37 ;
struct V_21 * V_24 , * V_38 ;
int V_2 = 0 ;
unsigned long V_39 = F_18 ( V_22 ) ;
unsigned int V_23 = V_4 [ 0 ] ;
if ( V_28 > V_5 )
return - V_40 ;
if ( V_22 / V_5 > V_41 / 2 )
return - V_42 ;
F_14 ( & V_37 ) ;
while ( V_39 > 0 ) {
V_24 = F_12 ( V_30 , V_10 , V_39 ,
V_23 ) ;
if ( ! V_24 )
goto V_43;
F_19 ( & V_24 -> V_26 , & V_37 ) ;
V_39 -= ( 1 << V_24 -> V_1 ) * V_5 ;
V_23 = V_24 -> V_1 ;
V_2 ++ ;
}
V_32 = F_20 ( sizeof( struct V_31 ) , V_25 ) ;
if ( ! V_32 )
goto V_43;
V_35 = F_21 ( V_32 , V_2 , V_25 ) ;
if ( V_35 )
goto V_44;
V_34 = V_32 -> V_45 ;
F_22 (info, tmp_info, &pages, list) {
struct V_6 * V_6 = V_24 -> V_6 ;
F_23 ( V_34 , V_6 , ( 1 << V_24 -> V_1 ) * V_5 , 0 ) ;
V_34 = F_24 ( V_34 ) ;
F_25 ( & V_24 -> V_26 ) ;
F_15 ( V_24 ) ;
}
V_10 -> V_46 = V_32 ;
return 0 ;
V_44:
F_15 ( V_32 ) ;
V_43:
F_22 (info, tmp_info, &pages, list) {
F_9 ( V_30 , V_10 , V_24 -> V_6 , V_24 -> V_1 ) ;
F_15 ( V_24 ) ;
}
return - V_42 ;
}
static void F_26 ( struct V_9 * V_10 )
{
struct V_27 * V_8 = V_10 -> V_8 ;
struct V_7 * V_30 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_31 * V_32 = V_10 -> V_31 ;
bool V_11 = F_5 ( V_10 ) ;
struct V_33 * V_34 ;
F_27 ( V_37 ) ;
int V_2 ;
if ( ! V_11 && ! ( V_10 -> V_19 & V_20 ) )
F_28 ( V_10 ) ;
F_29 (table->sgl, sg, table->nents, i)
F_9 ( V_30 , V_10 , F_30 ( V_34 ) ,
F_31 ( V_34 -> V_47 ) ) ;
F_32 ( V_32 ) ;
F_15 ( V_32 ) ;
}
static struct V_31 * F_33 ( struct V_27 * V_8 ,
struct V_9 * V_10 )
{
return V_10 -> V_46 ;
}
static void F_34 ( struct V_27 * V_8 ,
struct V_9 * V_10 )
{
return;
}
static int F_35 ( struct V_27 * V_8 , T_1 V_48 ,
int V_49 )
{
struct V_7 * V_30 ;
int V_50 = 0 ;
int V_2 ;
V_30 = F_17 ( V_8 , struct V_7 , V_8 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_30 -> V_14 [ V_2 ] ;
V_50 += F_36 ( V_13 , V_48 , V_49 ) ;
}
return V_50 ;
}
static int F_37 ( struct V_27 * V_8 , struct V_51 * V_52 ,
void * V_53 )
{
struct V_7 * V_30 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_30 -> V_14 [ V_2 ] ;
F_38 ( V_52 , L_1 ,
V_13 -> V_54 , V_13 -> V_1 ,
( 1 << V_13 -> V_1 ) * V_5 * V_13 -> V_54 ) ;
F_38 ( V_52 , L_2 ,
V_13 -> V_55 , V_13 -> V_1 ,
( 1 << V_13 -> V_1 ) * V_5 * V_13 -> V_55 ) ;
}
return 0 ;
}
struct V_27 * F_39 ( struct V_56 * V_53 )
{
struct V_7 * V_8 ;
int V_2 ;
V_8 = F_20 ( sizeof( struct V_7 ) , V_25 ) ;
if ( ! V_8 )
return F_40 ( - V_42 ) ;
V_8 -> V_8 . V_57 = & V_58 ;
V_8 -> V_8 . type = V_59 ;
V_8 -> V_8 . V_29 = V_60 ;
V_8 -> V_14 = F_20 ( sizeof( struct V_12 * ) * V_3 ,
V_25 ) ;
if ( ! V_8 -> V_14 )
goto V_61;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 ;
T_1 V_15 = V_16 ;
if ( V_4 [ V_2 ] > 4 )
V_15 = V_17 ;
V_13 = F_41 ( V_15 , V_4 [ V_2 ] ) ;
if ( ! V_13 )
goto V_62;
V_8 -> V_14 [ V_2 ] = V_13 ;
}
V_8 -> V_8 . V_63 = F_37 ;
return & V_8 -> V_8 ;
V_62:
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_8 -> V_14 [ V_2 ] )
F_42 ( V_8 -> V_14 [ V_2 ] ) ;
F_15 ( V_8 -> V_14 ) ;
V_61:
F_15 ( V_8 ) ;
return F_40 ( - V_42 ) ;
}
void F_43 ( struct V_27 * V_8 )
{
struct V_7 * V_30 = F_17 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_42 ( V_30 -> V_14 [ V_2 ] ) ;
F_15 ( V_30 -> V_14 ) ;
F_15 ( V_30 ) ;
}
static int F_44 ( struct V_27 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_64 ,
unsigned long V_28 ,
unsigned long V_29 )
{
int V_1 = F_31 ( V_64 ) ;
struct V_6 * V_6 ;
struct V_31 * V_32 ;
unsigned long V_2 ;
int V_35 ;
if ( V_28 > ( V_5 << V_1 ) )
return - V_40 ;
V_6 = F_7 ( V_16 , V_1 ) ;
if ( ! V_6 )
return - V_42 ;
F_45 ( V_6 , V_1 ) ;
V_64 = F_18 ( V_64 ) ;
for ( V_2 = V_64 >> V_65 ; V_2 < ( 1 << V_1 ) ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
V_32 = F_20 ( sizeof( struct V_31 ) , V_25 ) ;
if ( ! V_32 ) {
V_35 = - V_42 ;
goto V_66;
}
V_35 = F_21 ( V_32 , 1 , V_25 ) ;
if ( V_35 )
goto V_66;
F_23 ( V_32 -> V_45 , V_6 , V_64 , 0 ) ;
V_10 -> V_46 = V_32 ;
F_8 ( NULL , V_6 , V_64 , V_18 ) ;
return 0 ;
V_66:
for ( V_2 = 0 ; V_2 < V_64 > > V_65 ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
F_15 ( V_32 ) ;
return V_35 ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_46 ;
struct V_6 * V_6 = F_30 ( V_32 -> V_45 ) ;
unsigned long V_37 = F_18 ( V_10 -> V_22 ) >> V_65 ;
unsigned long V_2 ;
for ( V_2 = 0 ; V_2 < V_37 ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
F_32 ( V_32 ) ;
F_15 ( V_32 ) ;
}
static int F_48 ( struct V_27 * V_8 ,
struct V_9 * V_10 ,
T_2 * V_67 , T_3 * V_64 )
{
struct V_31 * V_32 = V_10 -> V_46 ;
struct V_6 * V_6 = F_30 ( V_32 -> V_45 ) ;
* V_67 = F_49 ( V_6 ) ;
* V_64 = V_10 -> V_22 ;
return 0 ;
}
static struct V_31 * F_50 ( struct V_27 * V_8 ,
struct V_9 * V_10 )
{
return V_10 -> V_46 ;
}
static void F_51 ( struct V_27 * V_8 ,
struct V_9 * V_10 )
{
}
struct V_27 * F_52 ( struct V_56 * V_53 )
{
struct V_27 * V_8 ;
V_8 = F_20 ( sizeof( struct V_27 ) , V_25 ) ;
if ( ! V_8 )
return F_40 ( - V_42 ) ;
V_8 -> V_57 = & V_68 ;
V_8 -> type = V_69 ;
return V_8 ;
}
void F_53 ( struct V_27 * V_8 )
{
F_15 ( V_8 ) ;
}
