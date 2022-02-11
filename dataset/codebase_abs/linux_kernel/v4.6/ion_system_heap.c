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
struct V_12 * V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
struct V_6 * V_6 ;
if ( ! V_11 ) {
V_6 = F_6 ( V_13 ) ;
} else {
T_1 V_15 = V_16 ;
if ( V_1 > 4 )
V_15 = V_17 ;
V_6 = F_7 ( V_15 | V_18 , V_1 ) ;
if ( ! V_6 )
return NULL ;
F_8 ( NULL , V_6 , V_5 << V_1 ,
V_19 ) ;
}
return V_6 ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_6 * V_6 )
{
unsigned int V_1 = F_10 ( V_6 ) ;
bool V_11 = F_5 ( V_10 ) ;
if ( ! V_11 && ! ( V_10 -> V_20 & V_21 ) ) {
struct V_12 * V_13 = V_8 -> V_14 [ F_1 ( V_1 ) ] ;
F_11 ( V_13 , V_6 ) ;
} else {
F_12 ( V_6 , V_1 ) ;
}
}
static struct V_6 * F_13 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_22 ,
unsigned int V_23 )
{
struct V_6 * V_6 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_22 < F_3 ( V_4 [ V_2 ] ) )
continue;
if ( V_23 < V_4 [ V_2 ] )
continue;
V_6 = F_4 ( V_8 , V_10 , V_4 [ V_2 ] ) ;
if ( ! V_6 )
continue;
return V_6 ;
}
return NULL ;
}
static int F_14 ( struct V_24 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_22 , unsigned long V_25 ,
unsigned long V_26 )
{
struct V_7 * V_27 = F_15 ( V_8 ,
struct V_7 ,
V_8 ) ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_33 ;
struct V_6 * V_6 , * V_34 ;
int V_2 = 0 ;
unsigned long V_35 = F_16 ( V_22 ) ;
unsigned int V_23 = V_4 [ 0 ] ;
if ( V_25 > V_5 )
return - V_36 ;
if ( V_22 / V_5 > V_37 / 2 )
return - V_38 ;
F_17 ( & V_33 ) ;
while ( V_35 > 0 ) {
V_6 = F_13 ( V_27 , V_10 , V_35 ,
V_23 ) ;
if ( ! V_6 )
goto V_39;
F_18 ( & V_6 -> V_40 , & V_33 ) ;
V_35 -= V_5 << F_10 ( V_6 ) ;
V_23 = F_10 ( V_6 ) ;
V_2 ++ ;
}
V_29 = F_19 ( sizeof( struct V_28 ) , V_41 ) ;
if ( ! V_29 )
goto V_39;
if ( F_20 ( V_29 , V_2 , V_41 ) )
goto V_42;
V_31 = V_29 -> V_43 ;
F_21 (page, tmp_page, &pages, lru) {
F_22 ( V_31 , V_6 , V_5 << F_10 ( V_6 ) , 0 ) ;
V_31 = F_23 ( V_31 ) ;
F_24 ( & V_6 -> V_40 ) ;
}
V_10 -> V_44 = V_29 ;
return 0 ;
V_42:
F_25 ( V_29 ) ;
V_39:
F_21 (page, tmp_page, &pages, lru)
F_9 ( V_27 , V_10 , V_6 ) ;
return - V_38 ;
}
static void F_26 ( struct V_9 * V_10 )
{
struct V_7 * V_27 = F_15 ( V_10 -> V_8 ,
struct V_7 ,
V_8 ) ;
struct V_28 * V_29 = V_10 -> V_28 ;
bool V_11 = F_5 ( V_10 ) ;
struct V_30 * V_31 ;
int V_2 ;
if ( ! V_11 && ! ( V_10 -> V_20 & V_21 ) )
F_27 ( V_10 ) ;
F_28 (table->sgl, sg, table->nents, i)
F_9 ( V_27 , V_10 , F_29 ( V_31 ) ) ;
F_30 ( V_29 ) ;
F_25 ( V_29 ) ;
}
static struct V_28 * F_31 ( struct V_24 * V_8 ,
struct V_9 * V_10 )
{
return V_10 -> V_44 ;
}
static void F_32 ( struct V_24 * V_8 ,
struct V_9 * V_10 )
{
}
static int F_33 ( struct V_24 * V_8 , T_1 V_45 ,
int V_46 )
{
struct V_7 * V_27 ;
int V_47 = 0 ;
int V_2 , V_48 ;
int V_49 = 0 ;
V_27 = F_15 ( V_8 , struct V_7 , V_8 ) ;
if ( ! V_46 )
V_49 = 1 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_27 -> V_14 [ V_2 ] ;
V_48 = F_34 ( V_13 , V_45 , V_46 ) ;
V_47 += V_48 ;
if ( ! V_49 ) {
V_46 -= V_48 ;
if ( V_46 <= 0 )
break;
}
}
return V_47 ;
}
static int F_35 ( struct V_24 * V_8 , struct V_50 * V_51 ,
void * V_52 )
{
struct V_7 * V_27 = F_15 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 = V_27 -> V_14 [ V_2 ] ;
F_36 ( V_51 , L_1 ,
V_13 -> V_53 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_53 ) ;
F_36 ( V_51 , L_2 ,
V_13 -> V_54 , V_13 -> V_1 ,
( V_5 << V_13 -> V_1 ) * V_13 -> V_54 ) ;
}
return 0 ;
}
struct V_24 * F_37 ( struct V_55 * V_52 )
{
struct V_7 * V_8 ;
int V_2 ;
V_8 = F_38 ( sizeof( struct V_7 ) +
sizeof( struct V_12 * ) * V_3 ,
V_41 ) ;
if ( ! V_8 )
return F_39 ( - V_38 ) ;
V_8 -> V_8 . V_56 = & V_57 ;
V_8 -> V_8 . type = V_58 ;
V_8 -> V_8 . V_26 = V_59 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
struct V_12 * V_13 ;
T_1 V_15 = V_16 ;
if ( V_4 [ V_2 ] > 4 )
V_15 = V_17 ;
V_13 = F_40 ( V_15 , V_4 [ V_2 ] ) ;
if ( ! V_13 )
goto V_60;
V_8 -> V_14 [ V_2 ] = V_13 ;
}
V_8 -> V_8 . V_61 = F_35 ;
return & V_8 -> V_8 ;
V_60:
while ( V_2 -- )
F_41 ( V_8 -> V_14 [ V_2 ] ) ;
F_25 ( V_8 ) ;
return F_39 ( - V_38 ) ;
}
void F_42 ( struct V_24 * V_8 )
{
struct V_7 * V_27 = F_15 ( V_8 ,
struct V_7 ,
V_8 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_41 ( V_27 -> V_14 [ V_2 ] ) ;
F_25 ( V_27 ) ;
}
static int F_43 ( struct V_24 * V_8 ,
struct V_9 * V_10 ,
unsigned long V_62 ,
unsigned long V_25 ,
unsigned long V_26 )
{
int V_1 = F_44 ( V_62 ) ;
struct V_6 * V_6 ;
struct V_28 * V_29 ;
unsigned long V_2 ;
int V_63 ;
if ( V_25 > ( V_5 << V_1 ) )
return - V_36 ;
V_6 = F_7 ( V_16 , V_1 ) ;
if ( ! V_6 )
return - V_38 ;
F_45 ( V_6 , V_1 ) ;
V_62 = F_16 ( V_62 ) ;
for ( V_2 = V_62 >> V_64 ; V_2 < ( 1 << V_1 ) ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
V_29 = F_19 ( sizeof( struct V_28 ) , V_41 ) ;
if ( ! V_29 ) {
V_63 = - V_38 ;
goto V_39;
}
V_63 = F_20 ( V_29 , 1 , V_41 ) ;
if ( V_63 )
goto V_42;
F_22 ( V_29 -> V_43 , V_6 , V_62 , 0 ) ;
V_10 -> V_44 = V_29 ;
F_8 ( NULL , V_6 , V_62 , V_19 ) ;
return 0 ;
V_42:
F_25 ( V_29 ) ;
V_39:
for ( V_2 = 0 ; V_2 < V_62 > > V_64 ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
return V_63 ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_28 * V_29 = V_10 -> V_44 ;
struct V_6 * V_6 = F_29 ( V_29 -> V_43 ) ;
unsigned long V_33 = F_16 ( V_10 -> V_22 ) >> V_64 ;
unsigned long V_2 ;
for ( V_2 = 0 ; V_2 < V_33 ; V_2 ++ )
F_46 ( V_6 + V_2 ) ;
F_30 ( V_29 ) ;
F_25 ( V_29 ) ;
}
static int F_48 ( struct V_24 * V_8 ,
struct V_9 * V_10 ,
T_2 * V_65 , T_3 * V_62 )
{
struct V_28 * V_29 = V_10 -> V_44 ;
struct V_6 * V_6 = F_29 ( V_29 -> V_43 ) ;
* V_65 = F_49 ( V_6 ) ;
* V_62 = V_10 -> V_22 ;
return 0 ;
}
static struct V_28 * F_50 ( struct V_24 * V_8 ,
struct V_9 * V_10 )
{
return V_10 -> V_44 ;
}
static void F_51 ( struct V_24 * V_8 ,
struct V_9 * V_10 )
{
}
struct V_24 * F_52 ( struct V_55 * V_52 )
{
struct V_24 * V_8 ;
V_8 = F_38 ( sizeof( struct V_24 ) , V_41 ) ;
if ( ! V_8 )
return F_39 ( - V_38 ) ;
V_8 -> V_56 = & V_66 ;
V_8 -> type = V_67 ;
return V_8 ;
}
void F_53 ( struct V_24 * V_8 )
{
F_25 ( V_8 ) ;
}
