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
if ( V_11 )
F_7 ( NULL , V_6 , V_5 << V_1 ,
V_16 ) ;
return V_6 ;
}
static void F_8 ( struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_6 * V_6 )
{
struct V_12 * V_13 ;
unsigned int V_1 = F_9 ( V_6 ) ;
bool V_11 = F_5 ( V_10 ) ;
if ( V_10 -> V_17 & V_18 ) {
F_10 ( V_6 , V_1 ) ;
return;
}
if ( ! V_11 )
V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
else
V_13 = V_8 -> V_15 [ F_1 ( V_1 ) ] ;
F_11 ( V_13 , V_6 ) ;
}
static struct V_6 * F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_19 ,
unsigned int V_20 )
{
struct V_6 * V_6 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_19 < F_3 ( V_4 [ V_2 ] ) )
continue;
if ( V_20 < V_4 [ V_2 ] )
continue;
V_6 = F_4 ( V_8 , V_10 , V_4 [ V_2 ] ) ;
if ( ! V_6 )
continue;
return V_6 ;
}
return NULL ;
}
static int F_13 ( struct V_21 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_19 , unsigned long V_22 ,
unsigned long V_23 )
{
struct V_7 * V_24 = F_14 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 V_30 ;
struct V_6 * V_6 , * V_31 ;
int V_2 = 0 ;
unsigned long V_32 = F_15 ( V_19 ) ;
unsigned int V_20 = V_4 [ 0 ] ;
if ( V_22 > V_5 )
return - V_33 ;
if ( V_19 / V_5 > V_34 / 2 )
return - V_35 ;
F_16 ( & V_30 ) ;
while ( V_32 > 0 ) {
V_6 = F_12 ( V_24 , V_10 , V_32 ,
V_20 ) ;
if ( ! V_6 )
goto V_36;
F_17 ( & V_6 -> V_37 , & V_30 ) ;
V_32 -= V_5 << F_9 ( V_6 ) ;
V_20 = F_9 ( V_6 ) ;
V_2 ++ ;
}
V_26 = F_18 ( sizeof( struct V_25 ) , V_38 ) ;
if ( ! V_26 )
goto V_36;
if ( F_19 ( V_26 , V_2 , V_38 ) )
goto V_39;
V_28 = V_26 -> V_40 ;
F_20 (page, tmp_page, &pages, lru) {
F_21 ( V_28 , V_6 , V_5 << F_9 ( V_6 ) , 0 ) ;
V_28 = F_22 ( V_28 ) ;
F_23 ( & V_6 -> V_37 ) ;
}
V_10 -> V_25 = V_26 ;
return 0 ;
V_39:
F_24 ( V_26 ) ;
V_36:
F_20 (page, tmp_page, &pages, lru)
F_8 ( V_24 , V_10 , V_6 ) ;
return - V_35 ;
}
static void F_25 ( struct V_9 * V_10 )
{
struct V_7 * V_24 = F_14 ( V_10 -> V_8 ,
struct V_7 ,
V_8 ) ;
struct V_25 * V_26 = V_10 -> V_25 ;
struct V_27 * V_28 ;
int V_2 ;
if ( ! ( V_10 -> V_17 & V_18 ) )
F_26 ( V_10 ) ;
F_27 (table->sgl, sg, table->nents, i)
F_8 ( V_24 , V_10 , F_28 ( V_28 ) ) ;
F_29 ( V_26 ) ;
F_24 ( V_26 ) ;
}
static int F_30 ( struct V_21 * V_8 , T_1 V_41 ,
int V_42 )
{
struct V_12 * V_43 ;
struct V_12 * V_44 ;
struct V_7 * V_24 ;
int V_45 = 0 ;
int V_2 , V_46 ;
int V_47 = 0 ;
V_24 = F_14 ( V_8 , struct V_7 , V_8 ) ;
if ( ! V_42 )
V_47 = 1 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_43 = V_24 -> V_14 [ V_2 ] ;
V_44 = V_24 -> V_15 [ V_2 ] ;
if ( V_47 ) {
V_45 += F_31 ( V_43 ,
V_41 ,
V_42 ) ;
V_45 += F_31 ( V_44 ,
V_41 ,
V_42 ) ;
} else {
V_46 = F_31 ( V_43 ,
V_41 ,
V_42 ) ;
V_42 -= V_46 ;
V_45 += V_46 ;
if ( V_42 <= 0 )
break;
V_46 = F_31 ( V_44 ,
V_41 ,
V_42 ) ;
V_42 -= V_46 ;
V_45 += V_46 ;
if ( V_42 <= 0 )
break;
}
}
return V_45 ;
}
static int F_32 ( struct V_21 * V_8 , struct V_48 * V_49 ,
void * V_50 )
{
struct V_7 * V_24 = F_14 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
struct V_12 * V_13 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_13 = V_24 -> V_14 [ V_2 ] ;
F_33 ( V_49 , L_1 ,
V_13 -> V_51 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_51 ) ;
F_33 ( V_49 , L_2 ,
V_13 -> V_52 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_52 ) ;
}
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_13 = V_24 -> V_15 [ V_2 ] ;
F_33 ( V_49 , L_3 ,
V_13 -> V_51 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_51 ) ;
F_33 ( V_49 , L_4 ,
V_13 -> V_52 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_52 ) ;
}
return 0 ;
}
static void F_34 ( struct V_12 * * V_53 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_53 [ V_2 ] )
F_35 ( V_53 [ V_2 ] ) ;
}
static int F_36 ( struct V_12 * * V_53 ,
bool V_11 )
{
int V_2 ;
T_1 V_54 = V_55 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 ;
if ( V_4 [ V_2 ] > 4 )
V_54 = V_56 ;
V_13 = F_37 ( V_54 , V_4 [ V_2 ] , V_11 ) ;
if ( ! V_13 )
goto V_57;
V_53 [ V_2 ] = V_13 ;
}
return 0 ;
V_57:
F_34 ( V_53 ) ;
return - V_35 ;
}
struct V_21 * F_38 ( struct V_58 * V_50 )
{
struct V_7 * V_8 ;
V_8 = F_39 ( sizeof( * V_8 ) , V_38 ) ;
if ( ! V_8 )
return F_40 ( - V_35 ) ;
V_8 -> V_8 . V_59 = & V_60 ;
V_8 -> V_8 . type = V_61 ;
V_8 -> V_8 . V_23 = V_62 ;
if ( F_36 ( V_8 -> V_14 , false ) )
goto V_63;
if ( F_36 ( V_8 -> V_15 , true ) )
goto V_64;
V_8 -> V_8 . V_65 = F_32 ;
return & V_8 -> V_8 ;
V_64:
F_34 ( V_8 -> V_14 ) ;
V_63:
F_24 ( V_8 ) ;
return F_40 ( - V_35 ) ;
}
void F_41 ( struct V_21 * V_8 )
{
struct V_7 * V_24 = F_14 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
F_35 ( V_24 -> V_14 [ V_2 ] ) ;
F_35 ( V_24 -> V_15 [ V_2 ] ) ;
}
F_24 ( V_24 ) ;
}
static int F_42 ( struct V_21 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_66 ,
unsigned long V_22 ,
unsigned long V_23 )
{
int V_1 = F_43 ( V_66 ) ;
struct V_6 * V_6 ;
struct V_25 * V_26 ;
unsigned long V_2 ;
int V_67 ;
if ( V_22 > ( V_5 << V_1 ) )
return - V_33 ;
V_6 = F_44 ( V_55 , V_1 ) ;
if ( ! V_6 )
return - V_35 ;
F_45 ( V_6 , V_1 ) ;
V_66 = F_15 ( V_66 ) ;
for ( V_2 = V_66 >> V_68 ; V_2 < ( 1 << V_1 ) ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
V_26 = F_18 ( sizeof( struct V_25 ) , V_38 ) ;
if ( ! V_26 ) {
V_67 = - V_35 ;
goto V_36;
}
V_67 = F_19 ( V_26 , 1 , V_38 ) ;
if ( V_67 )
goto V_39;
F_21 ( V_26 -> V_40 , V_6 , V_66 , 0 ) ;
V_10 -> V_25 = V_26 ;
F_7 ( NULL , V_6 , V_66 , V_16 ) ;
return 0 ;
V_39:
F_24 ( V_26 ) ;
V_36:
for ( V_2 = 0 ; V_2 < V_66 > > V_68 ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
return V_67 ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_25 * V_26 = V_10 -> V_25 ;
struct V_6 * V_6 = F_28 ( V_26 -> V_40 ) ;
unsigned long V_30 = F_15 ( V_10 -> V_19 ) >> V_68 ;
unsigned long V_2 ;
for ( V_2 = 0 ; V_2 < V_30 ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
F_29 ( V_26 ) ;
F_24 ( V_26 ) ;
}
struct V_21 * F_48 ( struct V_58 * V_50 )
{
struct V_21 * V_8 ;
V_8 = F_39 ( sizeof( struct V_21 ) , V_38 ) ;
if ( ! V_8 )
return F_40 ( - V_35 ) ;
V_8 -> V_59 = & V_69 ;
V_8 -> type = V_70 ;
return V_8 ;
}
void F_49 ( struct V_21 * V_8 )
{
F_24 ( V_8 ) ;
}
