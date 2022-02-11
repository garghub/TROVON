static int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_1 == V_4 [ V_2 ] )
return V_2 ;
F_2 () ;
return - 1 ;
}
static inline unsigned int F_3 ( int V_1 )
{
return V_5 << V_1 ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_1 )
{
bool V_11 = F_5 ( V_10 ) ;
struct V_12 * V_13 ;
struct V_6 * V_6 ;
if ( ! V_11 )
V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
else
V_13 = V_8 -> V_15 [ F_1 ( V_1 ) ] ;
V_6 = F_6 ( V_13 ) ;
return V_6 ;
}
static void F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_6 * V_6 )
{
struct V_12 * V_13 ;
unsigned int V_1 = F_8 ( V_6 ) ;
bool V_11 = F_5 ( V_10 ) ;
if ( V_10 -> V_16 & V_17 ) {
F_9 ( V_6 , V_1 ) ;
return;
}
if ( ! V_11 )
V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
else
V_13 = V_8 -> V_15 [ F_1 ( V_1 ) ] ;
F_10 ( V_13 , V_6 ) ;
}
static struct V_6 * F_11 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_18 ,
unsigned int V_19 )
{
struct V_6 * V_6 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_18 < F_3 ( V_4 [ V_2 ] ) )
continue;
if ( V_19 < V_4 [ V_2 ] )
continue;
V_6 = F_4 ( V_8 , V_10 , V_4 [ V_2 ] ) ;
if ( ! V_6 )
continue;
return V_6 ;
}
return NULL ;
}
static int F_12 ( struct V_20 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_18 ,
unsigned long V_21 )
{
struct V_7 * V_22 = F_13 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
struct V_6 * V_6 , * V_29 ;
int V_2 = 0 ;
unsigned long V_30 = F_14 ( V_18 ) ;
unsigned int V_19 = V_4 [ 0 ] ;
if ( V_18 / V_5 > V_31 / 2 )
return - V_32 ;
F_15 ( & V_28 ) ;
while ( V_30 > 0 ) {
V_6 = F_11 ( V_22 , V_10 , V_30 ,
V_19 ) ;
if ( ! V_6 )
goto V_33;
F_16 ( & V_6 -> V_34 , & V_28 ) ;
V_30 -= V_5 << F_8 ( V_6 ) ;
V_19 = F_8 ( V_6 ) ;
V_2 ++ ;
}
V_24 = F_17 ( sizeof( * V_24 ) , V_35 ) ;
if ( ! V_24 )
goto V_33;
if ( F_18 ( V_24 , V_2 , V_35 ) )
goto V_36;
V_26 = V_24 -> V_37 ;
F_19 (page, tmp_page, &pages, lru) {
F_20 ( V_26 , V_6 , V_5 << F_8 ( V_6 ) , 0 ) ;
V_26 = F_21 ( V_26 ) ;
F_22 ( & V_6 -> V_34 ) ;
}
V_10 -> V_23 = V_24 ;
return 0 ;
V_36:
F_23 ( V_24 ) ;
V_33:
F_19 (page, tmp_page, &pages, lru)
F_7 ( V_22 , V_10 , V_6 ) ;
return - V_32 ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_7 * V_22 = F_13 ( V_10 -> V_8 ,
struct V_7 ,
V_8 ) ;
struct V_23 * V_24 = V_10 -> V_23 ;
struct V_25 * V_26 ;
int V_2 ;
if ( ! ( V_10 -> V_16 & V_17 ) )
F_25 ( V_10 ) ;
F_26 (table->sgl, sg, table->nents, i)
F_7 ( V_22 , V_10 , F_27 ( V_26 ) ) ;
F_28 ( V_24 ) ;
F_23 ( V_24 ) ;
}
static int F_29 ( struct V_20 * V_8 , T_1 V_38 ,
int V_39 )
{
struct V_12 * V_40 ;
struct V_12 * V_41 ;
struct V_7 * V_22 ;
int V_42 = 0 ;
int V_2 , V_43 ;
int V_44 = 0 ;
V_22 = F_13 ( V_8 , struct V_7 , V_8 ) ;
if ( ! V_39 )
V_44 = 1 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_40 = V_22 -> V_14 [ V_2 ] ;
V_41 = V_22 -> V_15 [ V_2 ] ;
if ( V_44 ) {
V_42 += F_30 ( V_40 ,
V_38 ,
V_39 ) ;
V_42 += F_30 ( V_41 ,
V_38 ,
V_39 ) ;
} else {
V_43 = F_30 ( V_40 ,
V_38 ,
V_39 ) ;
V_39 -= V_43 ;
V_42 += V_43 ;
if ( V_39 <= 0 )
break;
V_43 = F_30 ( V_41 ,
V_38 ,
V_39 ) ;
V_39 -= V_43 ;
V_42 += V_43 ;
if ( V_39 <= 0 )
break;
}
}
return V_42 ;
}
static int F_31 ( struct V_20 * V_8 , struct V_45 * V_46 ,
void * V_47 )
{
struct V_7 * V_22 = F_13 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
struct V_12 * V_13 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_13 = V_22 -> V_14 [ V_2 ] ;
F_32 ( V_46 , L_1 ,
V_13 -> V_48 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_48 ) ;
F_32 ( V_46 , L_2 ,
V_13 -> V_49 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_49 ) ;
}
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_13 = V_22 -> V_15 [ V_2 ] ;
F_32 ( V_46 , L_3 ,
V_13 -> V_48 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_48 ) ;
F_32 ( V_46 , L_4 ,
V_13 -> V_49 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_49 ) ;
}
return 0 ;
}
static void F_33 ( struct V_12 * * V_50 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_50 [ V_2 ] )
F_34 ( V_50 [ V_2 ] ) ;
}
static int F_35 ( struct V_12 * * V_50 ,
bool V_11 )
{
int V_2 ;
T_1 V_51 = V_52 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 ;
if ( V_4 [ V_2 ] > 4 )
V_51 = V_53 ;
V_13 = F_36 ( V_51 , V_4 [ V_2 ] , V_11 ) ;
if ( ! V_13 )
goto V_54;
V_50 [ V_2 ] = V_13 ;
}
return 0 ;
V_54:
F_33 ( V_50 ) ;
return - V_32 ;
}
static struct V_20 * F_37 ( void )
{
struct V_7 * V_8 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_35 ) ;
if ( ! V_8 )
return F_39 ( - V_32 ) ;
V_8 -> V_8 . V_55 = & V_56 ;
V_8 -> V_8 . type = V_57 ;
V_8 -> V_8 . V_21 = V_58 ;
if ( F_35 ( V_8 -> V_14 , false ) )
goto V_59;
if ( F_35 ( V_8 -> V_15 , true ) )
goto V_60;
V_8 -> V_8 . V_61 = F_31 ;
return & V_8 -> V_8 ;
V_60:
F_33 ( V_8 -> V_14 ) ;
V_59:
F_23 ( V_8 ) ;
return F_39 ( - V_32 ) ;
}
static int F_40 ( void )
{
struct V_20 * V_8 ;
V_8 = F_37 () ;
if ( F_41 ( V_8 ) )
return F_42 ( V_8 ) ;
V_8 -> V_62 = L_5 ;
F_43 ( V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_20 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_63 ,
unsigned long V_21 )
{
int V_1 = F_45 ( V_63 ) ;
struct V_6 * V_6 ;
struct V_23 * V_24 ;
unsigned long V_2 ;
int V_64 ;
V_6 = F_46 ( V_52 , V_1 ) ;
if ( ! V_6 )
return - V_32 ;
F_47 ( V_6 , V_1 ) ;
V_63 = F_14 ( V_63 ) ;
for ( V_2 = V_63 >> V_65 ; V_2 < ( 1 << V_1 ) ; V_2 ++ )
F_48 ( V_6 + V_2 ) ;
V_24 = F_17 ( sizeof( * V_24 ) , V_35 ) ;
if ( ! V_24 ) {
V_64 = - V_32 ;
goto V_33;
}
V_64 = F_18 ( V_24 , 1 , V_35 ) ;
if ( V_64 )
goto V_36;
F_20 ( V_24 -> V_37 , V_6 , V_63 , 0 ) ;
V_10 -> V_23 = V_24 ;
return 0 ;
V_36:
F_23 ( V_24 ) ;
V_33:
for ( V_2 = 0 ; V_2 < V_63 > > V_65 ; V_2 ++ )
F_48 ( V_6 + V_2 ) ;
return V_64 ;
}
static void F_49 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = V_10 -> V_23 ;
struct V_6 * V_6 = F_27 ( V_24 -> V_37 ) ;
unsigned long V_28 = F_14 ( V_10 -> V_18 ) >> V_65 ;
unsigned long V_2 ;
for ( V_2 = 0 ; V_2 < V_28 ; V_2 ++ )
F_48 ( V_6 + V_2 ) ;
F_28 ( V_24 ) ;
F_23 ( V_24 ) ;
}
static struct V_20 * F_50 ( void )
{
struct V_20 * V_8 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_35 ) ;
if ( ! V_8 )
return F_39 ( - V_32 ) ;
V_8 -> V_55 = & V_66 ;
V_8 -> type = V_67 ;
V_8 -> V_62 = L_6 ;
return V_8 ;
}
static int F_51 ( void )
{
struct V_20 * V_8 ;
V_8 = F_50 () ;
if ( F_41 ( V_8 ) )
return F_42 ( V_8 ) ;
F_43 ( V_8 ) ;
return 0 ;
}
