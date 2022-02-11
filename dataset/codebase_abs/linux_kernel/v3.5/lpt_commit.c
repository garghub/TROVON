static struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( V_3 ) ;
while ( 1 ) {
int V_4 , V_5 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
struct V_1 * V_7 ;
V_7 = V_3 -> V_8 [ V_4 ] . V_7 ;
if ( V_7 &&
F_3 ( V_9 , & V_7 -> V_10 ) ) {
if ( V_7 -> V_11 == 0 )
return V_7 ;
V_3 = (struct V_2 * ) V_7 ;
V_5 = 1 ;
break;
}
}
if ( ! V_5 )
return (struct V_1 * ) V_3 ;
}
}
static struct V_1 * F_4 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
int V_4 ;
F_2 ( V_7 ) ;
V_3 = V_7 -> V_12 ;
if ( ! V_3 )
return NULL ;
for ( V_4 = V_7 -> V_13 + 1 ; V_4 < V_6 ; V_4 ++ ) {
V_7 = V_3 -> V_8 [ V_4 ] . V_7 ;
if ( V_7 && F_3 ( V_9 , & V_7 -> V_10 ) ) {
if ( V_7 -> V_11 == 0 )
return V_7 ;
return F_1 ( (struct V_2 * ) V_7 ) ;
}
}
return (struct V_1 * ) V_3 ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_1 * V_7 , * V_16 ;
int V_17 = 0 ;
if ( ! V_15 -> V_18 )
return 0 ;
if ( ! F_3 ( V_9 , & V_15 -> V_18 -> V_10 ) )
return 0 ;
V_15 -> V_19 = F_1 ( V_15 -> V_18 ) ;
V_7 = V_15 -> V_19 ;
if ( ! V_7 )
return 0 ;
V_17 += 1 ;
while ( 1 ) {
F_2 ( ! F_3 ( V_20 , & V_7 -> V_10 ) ) ;
F_6 ( V_20 , & V_7 -> V_10 ) ;
V_16 = F_4 ( V_7 ) ;
if ( ! V_16 ) {
V_7 -> V_16 = V_15 -> V_19 ;
break;
}
V_7 -> V_16 = V_16 ;
V_7 = V_16 ;
V_17 += 1 ;
}
F_7 ( L_1 , V_17 ) ;
F_8 ( L_1 , V_17 ) ;
F_2 ( V_17 == V_15 -> V_21 + V_15 -> V_22 ) ;
return V_17 ;
}
static void F_9 ( struct V_14 * V_15 , int V_23 , int free , int V_24 )
{
F_8 ( L_2 ,
V_23 , V_15 -> V_25 [ V_23 - V_15 -> V_26 ] . free ,
V_15 -> V_25 [ V_23 - V_15 -> V_26 ] . V_24 , free , V_24 ) ;
F_2 ( V_23 >= V_15 -> V_26 && V_23 <= V_15 -> V_27 ) ;
V_15 -> V_25 [ V_23 - V_15 -> V_26 ] . free = free ;
V_15 -> V_25 [ V_23 - V_15 -> V_26 ] . V_24 += V_24 ;
}
static int F_10 ( struct V_14 * V_15 , int * V_23 )
{
int V_4 , V_28 ;
V_28 = * V_23 - V_15 -> V_26 + 1 ;
for ( V_4 = V_28 ; V_4 < V_15 -> V_29 ; V_4 ++ ) {
if ( V_15 -> V_25 [ V_4 ] . V_30 || V_15 -> V_25 [ V_4 ] . V_31 )
continue;
if ( V_15 -> V_25 [ V_4 ] . free == V_15 -> V_32 ) {
V_15 -> V_25 [ V_4 ] . V_31 = 1 ;
* V_23 = V_4 + V_15 -> V_26 ;
return 0 ;
}
}
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ ) {
if ( V_15 -> V_25 [ V_4 ] . V_30 || V_15 -> V_25 [ V_4 ] . V_31 )
continue;
if ( V_15 -> V_25 [ V_4 ] . free == V_15 -> V_32 ) {
V_15 -> V_25 [ V_4 ] . V_31 = 1 ;
* V_23 = V_4 + V_15 -> V_26 ;
return 0 ;
}
}
return - V_33 ;
}
static int F_11 ( struct V_14 * V_15 )
{
int V_23 , V_34 , V_35 , V_36 , V_37 , V_38 , V_39 ;
struct V_1 * V_7 ;
V_39 = F_12 ( V_15 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
V_7 = V_15 -> V_19 ;
if ( ! V_7 )
return 0 ;
V_23 = V_15 -> V_40 ;
V_34 = V_15 -> V_41 ;
V_37 = ! V_15 -> V_42 ;
V_38 = 0 ;
if ( ! V_37 && V_34 + V_15 -> V_43 <= V_15 -> V_32 ) {
V_37 = 1 ;
V_15 -> V_44 = V_23 ;
V_15 -> V_45 = V_34 ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
}
if ( V_34 + V_15 -> V_46 <= V_15 -> V_32 ) {
V_38 = 1 ;
V_15 -> V_47 = V_23 ;
V_15 -> V_48 = V_34 ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
}
do {
if ( V_7 -> V_11 ) {
V_35 = V_15 -> V_49 ;
V_15 -> V_21 -= 1 ;
} else {
V_35 = V_15 -> V_50 ;
V_15 -> V_22 -= 1 ;
}
while ( V_34 + V_35 > V_15 -> V_32 ) {
V_36 = F_13 ( V_34 , V_15 -> V_51 ) ;
F_9 ( V_15 , V_23 , V_15 -> V_32 - V_36 , V_36 - V_34 ) ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_10 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
if ( ! V_37 ) {
V_37 = 1 ;
V_15 -> V_44 = V_23 ;
V_15 -> V_45 = V_34 ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
continue;
}
if ( ! V_38 ) {
V_38 = 1 ;
V_15 -> V_47 = V_23 ;
V_15 -> V_48 = V_34 ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
continue;
}
break;
}
if ( V_7 -> V_12 ) {
V_7 -> V_12 -> V_8 [ V_7 -> V_13 ] . V_23 = V_23 ;
V_7 -> V_12 -> V_8 [ V_7 -> V_13 ] . V_34 = V_34 ;
} else {
V_15 -> V_53 = V_23 ;
V_15 -> V_54 = V_34 ;
}
V_34 += V_35 ;
F_12 ( V_15 , 1 , V_35 ) ;
V_7 = V_7 -> V_16 ;
} while ( V_7 && V_7 != V_15 -> V_19 );
if ( ! V_37 ) {
if ( V_34 + V_15 -> V_43 > V_15 -> V_32 ) {
V_36 = F_13 ( V_34 , V_15 -> V_51 ) ;
F_9 ( V_15 , V_23 , V_15 -> V_32 - V_36 , V_36 - V_34 ) ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_10 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
}
V_37 = 1 ;
V_15 -> V_44 = V_23 ;
V_15 -> V_45 = V_34 ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
}
if ( ! V_38 ) {
if ( V_34 + V_15 -> V_46 > V_15 -> V_32 ) {
V_36 = F_13 ( V_34 , V_15 -> V_51 ) ;
F_9 ( V_15 , V_23 , V_15 -> V_32 - V_36 , V_36 - V_34 ) ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_10 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
}
V_38 = 1 ;
V_15 -> V_47 = V_23 ;
V_15 -> V_48 = V_34 ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
}
V_36 = F_13 ( V_34 , V_15 -> V_51 ) ;
F_9 ( V_15 , V_23 , V_15 -> V_32 - V_36 , V_36 - V_34 ) ;
F_12 ( V_15 , 4 , V_36 - V_34 ) ;
V_39 = F_12 ( V_15 , 3 , V_36 ) ;
if ( V_39 )
return V_39 ;
return 0 ;
V_52:
F_14 ( L_3
L_4 , V_23 , V_34 , V_35 , V_38 , V_37 ) ;
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_17 () ;
return V_39 ;
}
static int F_18 ( struct V_14 * V_15 , int * V_23 )
{
int V_4 , V_28 ;
V_28 = * V_23 - V_15 -> V_26 + 1 ;
for ( V_4 = V_28 ; V_4 < V_15 -> V_29 ; V_4 ++ )
if ( V_15 -> V_25 [ V_4 ] . V_31 ) {
V_15 -> V_25 [ V_4 ] . V_31 = 0 ;
* V_23 = V_4 + V_15 -> V_26 ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ )
if ( V_15 -> V_25 [ V_4 ] . V_31 ) {
V_15 -> V_25 [ V_4 ] . V_31 = 0 ;
* V_23 = V_4 + V_15 -> V_26 ;
return 0 ;
}
return - V_33 ;
}
static int F_19 ( struct V_14 * V_15 )
{
int V_23 , V_34 , V_35 , V_55 , V_39 , V_56 , V_36 , V_38 , V_37 ;
struct V_1 * V_7 ;
void * V_57 = V_15 -> V_58 ;
V_7 = V_15 -> V_19 ;
if ( ! V_7 )
return 0 ;
V_23 = V_15 -> V_40 ;
V_34 = V_15 -> V_41 ;
V_55 = V_34 ;
if ( V_34 == 0 ) {
V_39 = F_20 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
}
V_37 = ! V_15 -> V_42 ;
V_38 = 0 ;
if ( ! V_37 && V_34 + V_15 -> V_43 <= V_15 -> V_32 ) {
V_37 = 1 ;
F_21 ( V_15 , V_57 + V_34 , V_15 -> V_59 ) ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
}
if ( V_34 + V_15 -> V_46 <= V_15 -> V_32 ) {
V_38 = 1 ;
F_22 ( V_15 , V_57 + V_34 , V_15 -> V_60 ) ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
}
do {
if ( V_7 -> V_11 )
V_35 = V_15 -> V_49 ;
else
V_35 = V_15 -> V_50 ;
while ( V_34 + V_35 > V_15 -> V_32 ) {
V_56 = V_34 - V_55 ;
if ( V_56 ) {
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_23 ( V_15 , V_23 , V_57 + V_55 , V_55 ,
V_36 ) ;
if ( V_39 )
return V_39 ;
}
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_18 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = V_55 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
V_39 = F_20 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
if ( ! V_37 ) {
V_37 = 1 ;
F_21 ( V_15 , V_57 + V_34 , V_15 -> V_59 ) ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
continue;
}
if ( ! V_38 ) {
V_38 = 1 ;
F_22 ( V_15 , V_57 + V_34 , V_15 -> V_60 ) ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
continue;
}
break;
}
if ( V_7 -> V_11 )
F_24 ( V_15 , V_57 + V_34 ,
(struct V_2 * ) V_7 ) ;
else
F_25 ( V_15 , V_57 + V_34 ,
(struct V_61 * ) V_7 ) ;
F_26 ( V_9 , & V_7 -> V_10 ) ;
F_27 () ;
F_26 ( V_20 , & V_7 -> V_10 ) ;
F_28 () ;
V_34 += V_35 ;
F_12 ( V_15 , 1 , V_35 ) ;
V_7 = V_7 -> V_16 ;
} while ( V_7 && V_7 != V_15 -> V_19 );
if ( ! V_37 ) {
if ( V_34 + V_15 -> V_43 > V_15 -> V_32 ) {
V_56 = V_34 - V_55 ;
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_23 ( V_15 , V_23 , V_57 + V_55 , V_55 , V_36 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_18 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = V_55 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
V_39 = F_20 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
}
V_37 = 1 ;
F_21 ( V_15 , V_57 + V_34 , V_15 -> V_59 ) ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
}
if ( ! V_38 ) {
if ( V_34 + V_15 -> V_46 > V_15 -> V_32 ) {
V_56 = V_34 - V_55 ;
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_23 ( V_15 , V_23 , V_57 + V_55 , V_55 , V_36 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_18 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = V_55 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
V_39 = F_20 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
}
V_38 = 1 ;
F_22 ( V_15 , V_57 + V_34 , V_15 -> V_60 ) ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
}
V_56 = V_34 - V_55 ;
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_23 ( V_15 , V_23 , V_57 + V_55 , V_55 , V_36 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_15 , 4 , V_36 - V_56 ) ;
V_39 = F_12 ( V_15 , 3 , F_13 ( V_34 , V_15 -> V_51 ) ) ;
if ( V_39 )
return V_39 ;
V_15 -> V_40 = V_23 ;
V_15 -> V_41 = F_13 ( V_34 , V_15 -> V_51 ) ;
F_8 ( L_5 , V_15 -> V_53 , V_15 -> V_54 ) ;
F_8 ( L_6 , V_15 -> V_40 , V_15 -> V_41 ) ;
F_8 ( L_7 , V_15 -> V_47 , V_15 -> V_48 ) ;
if ( V_15 -> V_42 )
F_8 ( L_8 , V_15 -> V_44 , V_15 -> V_45 ) ;
return 0 ;
V_52:
F_14 ( L_9
L_10 , V_23 , V_34 , V_35 , V_38 , V_37 ) ;
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_17 () ;
return V_39 ;
}
static struct V_61 * F_29 ( struct V_14 * V_15 ,
struct V_61 * V_62 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = V_62 -> V_12 ;
for ( V_13 = V_62 -> V_13 + 1 ; V_13 < V_6 ; V_13 ++ ) {
if ( V_3 -> V_8 [ V_13 ] . V_23 )
return F_30 ( V_15 , V_3 , V_13 ) ;
}
do {
V_13 = V_3 -> V_13 + 1 ;
V_3 = V_3 -> V_12 ;
if ( ! V_3 )
return NULL ;
for (; V_13 < V_6 ; V_13 ++ ) {
if ( V_3 -> V_8 [ V_13 ] . V_23 )
break;
}
} while ( V_13 >= V_6 );
V_3 = F_31 ( V_15 , V_3 , V_13 ) ;
if ( F_32 ( V_3 ) )
return ( void * ) V_3 ;
while ( V_3 -> V_11 > 1 ) {
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
if ( V_3 -> V_8 [ V_13 ] . V_23 )
break;
}
if ( V_13 >= V_6 ) {
V_13 = 0 ;
}
V_3 = F_31 ( V_15 , V_3 , V_13 ) ;
if ( F_32 ( V_3 ) )
return ( void * ) V_3 ;
}
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ )
if ( V_3 -> V_8 [ V_13 ] . V_23 )
break;
if ( V_13 >= V_6 )
V_13 = 0 ;
return F_30 ( V_15 , V_3 , V_13 ) ;
}
static struct V_61 * F_33 ( struct V_14 * V_15 , int V_4 )
{
int V_39 , V_63 , V_13 , V_64 ;
struct V_2 * V_3 ;
if ( ! V_15 -> V_18 ) {
V_39 = F_34 ( V_15 , NULL , 0 ) ;
if ( V_39 )
return F_35 ( V_39 ) ;
}
V_4 <<= V_65 ;
V_3 = V_15 -> V_18 ;
V_64 = V_15 -> V_66 * V_65 ;
for ( V_63 = 1 ; V_63 < V_15 -> V_66 ; V_63 ++ ) {
V_13 = ( ( V_4 >> V_64 ) & ( V_6 - 1 ) ) ;
V_64 -= V_65 ;
V_3 = F_31 ( V_15 , V_3 , V_13 ) ;
if ( F_32 ( V_3 ) )
return F_36 ( V_3 ) ;
}
V_13 = ( ( V_4 >> V_64 ) & ( V_6 - 1 ) ) ;
return F_30 ( V_15 , V_3 , V_13 ) ;
}
static void F_37 ( struct V_14 * V_15 , struct V_61 * V_62 )
{
F_38 ( V_15 , V_62 -> V_12 -> V_8 [ V_62 -> V_13 ] . V_23 ,
V_15 -> V_50 ) ;
}
static void F_39 ( struct V_14 * V_15 , struct V_61 * V_62 )
{
if ( ! F_40 ( V_9 , & V_62 -> V_10 ) ) {
struct V_2 * V_3 ;
V_15 -> V_22 += 1 ;
F_37 ( V_15 , V_62 ) ;
V_3 = V_62 -> V_12 ;
while ( V_3 ) {
if ( ! F_40 ( V_9 , & V_3 -> V_10 ) ) {
V_15 -> V_21 += 1 ;
F_41 ( V_15 , V_3 ) ;
V_3 = V_3 -> V_12 ;
} else
break;
}
}
}
static int F_42 ( struct V_14 * V_15 )
{
struct V_61 * V_62 ;
V_62 = F_33 ( V_15 , 0 ) ;
if ( F_32 ( V_62 ) )
return F_43 ( V_62 ) ;
while ( V_62 ) {
F_39 ( V_15 , V_62 ) ;
V_62 = F_29 ( V_15 , V_62 ) ;
if ( F_32 ( V_62 ) )
return F_43 ( V_62 ) ;
}
return 0 ;
}
static int F_44 ( struct V_14 * V_15 )
{
long long free = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ ) {
if ( V_4 + V_15 -> V_26 == V_15 -> V_40 )
free += V_15 -> V_32 - V_15 -> V_41 ;
else if ( V_15 -> V_25 [ V_4 ] . free == V_15 -> V_32 )
free += V_15 -> V_32 ;
else if ( V_15 -> V_25 [ V_4 ] . free + V_15 -> V_25 [ V_4 ] . V_24 == V_15 -> V_32 )
free += V_15 -> V_32 ;
}
if ( free <= V_15 -> V_67 * 2 )
return 1 ;
return 0 ;
}
static void F_45 ( struct V_14 * V_15 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ ) {
if ( V_4 + V_15 -> V_26 == V_15 -> V_40 )
continue;
if ( V_15 -> V_25 [ V_4 ] . V_24 > 0 &&
V_15 -> V_25 [ V_4 ] . free + V_15 -> V_25 [ V_4 ] . V_24 == V_15 -> V_32 ) {
V_15 -> V_25 [ V_4 ] . V_30 = 1 ;
V_15 -> V_25 [ V_4 ] . free = V_15 -> V_32 ;
V_15 -> V_25 [ V_4 ] . V_24 = 0 ;
F_8 ( L_11 , V_4 + V_15 -> V_26 ) ;
}
}
}
static int F_46 ( struct V_14 * V_15 )
{
int V_4 , V_39 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ )
if ( V_15 -> V_25 [ V_4 ] . V_30 ) {
V_39 = F_20 ( V_15 , V_4 + V_15 -> V_26 ) ;
if ( V_39 )
return V_39 ;
V_15 -> V_25 [ V_4 ] . V_30 = 0 ;
F_8 ( L_11 , V_4 + V_15 -> V_26 ) ;
}
return 0 ;
}
static void F_47 ( struct V_14 * V_15 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_4 , V_17 = 0 ;
F_2 ( V_15 -> V_42 ) ;
if ( ! ( V_15 -> V_72 & V_73 ) ) {
V_15 -> V_72 |= V_73 ;
F_38 ( V_15 , V_15 -> V_44 , V_15 -> V_43 ) ;
}
if ( F_48 ( V_15 ) )
return;
F_49 (lprops, &c->empty_list, list) {
V_15 -> V_59 [ V_17 ++ ] = V_69 -> V_23 ;
if ( V_17 >= V_15 -> V_74 )
return;
}
F_49 (lprops, &c->freeable_list, list) {
V_15 -> V_59 [ V_17 ++ ] = V_69 -> V_23 ;
if ( V_17 >= V_15 -> V_74 )
return;
}
F_49 (lprops, &c->frdi_idx_list, list) {
V_15 -> V_59 [ V_17 ++ ] = V_69 -> V_23 ;
if ( V_17 >= V_15 -> V_74 )
return;
}
V_71 = & V_15 -> V_75 [ V_76 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_71 -> V_17 ; V_4 ++ ) {
V_15 -> V_59 [ V_17 ++ ] = V_71 -> V_77 [ V_4 ] -> V_23 ;
if ( V_17 >= V_15 -> V_74 )
return;
}
V_71 = & V_15 -> V_75 [ V_78 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_71 -> V_17 ; V_4 ++ ) {
V_15 -> V_59 [ V_17 ++ ] = V_71 -> V_77 [ V_4 ] -> V_23 ;
if ( V_17 >= V_15 -> V_74 )
return;
}
V_71 = & V_15 -> V_75 [ V_79 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_71 -> V_17 ; V_4 ++ ) {
V_15 -> V_59 [ V_17 ++ ] = V_71 -> V_77 [ V_4 ] -> V_23 ;
if ( V_17 >= V_15 -> V_74 )
return;
}
while ( V_17 < V_15 -> V_74 )
V_15 -> V_59 [ V_17 ++ ] = V_15 -> V_80 ;
}
static struct V_2 * F_50 ( struct V_14 * V_15 , int V_4 )
{
int V_39 , V_13 ;
struct V_2 * V_3 ;
if ( ! V_15 -> V_18 ) {
V_39 = F_34 ( V_15 , NULL , 0 ) ;
if ( V_39 )
return F_35 ( V_39 ) ;
}
V_3 = V_15 -> V_18 ;
while ( 1 ) {
V_13 = V_4 & ( V_6 - 1 ) ;
V_4 >>= V_65 ;
if ( ! V_4 )
break;
V_3 = F_31 ( V_15 , V_3 , V_13 ) ;
if ( F_32 ( V_3 ) )
return V_3 ;
}
return V_3 ;
}
static int F_51 ( struct V_14 * V_15 , int V_81 , int V_23 ,
int V_34 )
{
struct V_2 * V_3 ;
V_3 = F_50 ( V_15 , V_81 ) ;
if ( F_32 ( V_3 ) )
return F_43 ( V_3 ) ;
if ( V_3 -> V_12 ) {
struct V_82 * V_83 ;
V_83 = & V_3 -> V_12 -> V_8 [ V_3 -> V_13 ] ;
if ( V_83 -> V_23 != V_23 || V_83 -> V_34 != V_34 )
return 0 ;
} else if ( V_15 -> V_53 != V_23 || V_15 -> V_54 != V_34 )
return 0 ;
if ( ! F_40 ( V_9 , & V_3 -> V_10 ) ) {
V_15 -> V_21 += 1 ;
F_41 ( V_15 , V_3 ) ;
V_3 = V_3 -> V_12 ;
while ( V_3 ) {
if ( ! F_40 ( V_9 , & V_3 -> V_10 ) ) {
V_15 -> V_21 += 1 ;
F_41 ( V_15 , V_3 ) ;
V_3 = V_3 -> V_12 ;
} else
break;
}
}
return 0 ;
}
static int F_52 ( struct V_14 * V_15 , int V_81 , int V_23 ,
int V_34 )
{
struct V_61 * V_62 ;
struct V_82 * V_83 ;
V_62 = F_33 ( V_15 , V_81 ) ;
if ( F_32 ( V_62 ) )
return F_43 ( V_62 ) ;
V_83 = & V_62 -> V_12 -> V_8 [ V_62 -> V_13 ] ;
if ( V_83 -> V_23 != V_23 || V_83 -> V_34 != V_34 )
return 0 ;
F_39 ( V_15 , V_62 ) ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_47 || V_34 != V_15 -> V_48 )
return 0 ;
if ( ! ( V_15 -> V_72 & V_84 ) ) {
V_15 -> V_72 |= V_84 ;
F_38 ( V_15 , V_15 -> V_47 , V_15 -> V_46 ) ;
}
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_44 || V_34 != V_15 -> V_45 )
return 0 ;
if ( ! ( V_15 -> V_72 & V_73 ) ) {
V_15 -> V_72 |= V_73 ;
F_38 ( V_15 , V_15 -> V_44 , V_15 -> V_43 ) ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 , int V_85 , int V_81 ,
int V_23 , int V_34 )
{
switch ( V_85 ) {
case V_86 :
return F_51 ( V_15 , V_81 , V_23 , V_34 ) ;
case V_87 :
return F_52 ( V_15 , V_81 , V_23 , V_34 ) ;
case V_88 :
return F_53 ( V_15 , V_23 , V_34 ) ;
case V_89 :
return F_54 ( V_15 , V_23 , V_34 ) ;
}
return - V_90 ;
}
static int F_56 ( const struct V_14 * V_15 , int V_85 )
{
switch ( V_85 ) {
case V_86 :
return V_15 -> V_49 ;
case V_87 :
return V_15 -> V_50 ;
case V_88 :
return V_15 -> V_46 ;
case V_89 :
return V_15 -> V_43 ;
}
return 0 ;
}
static int F_57 ( const struct V_14 * V_15 , T_1 * V_57 , int V_35 )
{
int V_34 , V_91 ;
if ( V_15 -> V_51 == 1 )
return 0 ;
V_34 = V_15 -> V_32 - V_35 ;
V_91 = F_13 ( V_34 , V_15 -> V_51 ) - V_34 ;
return V_91 ;
}
static int F_58 ( const struct V_14 * V_15 , T_1 * V_57 ,
int * V_81 )
{
T_1 * V_92 = V_57 + V_93 ;
int V_94 = 0 , V_85 ;
V_85 = F_59 ( & V_92 , & V_94 , V_95 ) ;
* V_81 = F_59 ( & V_92 , & V_94 , V_15 -> V_96 ) ;
return V_85 ;
}
static int F_60 ( const struct V_14 * V_15 , T_1 * V_57 , int V_35 )
{
T_1 * V_92 = V_57 + V_93 ;
int V_94 = 0 , V_85 , V_97 ;
T_2 V_98 , V_99 ;
if ( V_35 < V_93 + ( V_95 + 7 ) / 8 )
return 0 ;
V_85 = F_59 ( & V_92 , & V_94 , V_95 ) ;
if ( V_85 == V_100 )
return 0 ;
V_97 = F_56 ( V_15 , V_85 ) ;
if ( ! V_97 || V_97 > V_35 )
return 0 ;
V_94 = 0 ;
V_92 = V_57 ;
V_98 = F_59 ( & V_92 , & V_94 , V_101 ) ;
V_99 = F_61 ( - 1 , V_57 + V_93 ,
V_97 - V_93 ) ;
if ( V_98 != V_99 )
return 0 ;
return 1 ;
}
static int F_62 ( struct V_14 * V_15 , int V_23 )
{
int V_39 , V_35 = V_15 -> V_32 , V_85 , V_81 , V_97 , V_34 ;
void * V_57 = V_15 -> V_58 ;
F_8 ( L_11 , V_23 ) ;
V_39 = F_63 ( V_15 , V_23 , V_57 , 0 , V_15 -> V_32 , 1 ) ;
if ( V_39 )
return V_39 ;
while ( 1 ) {
if ( ! F_60 ( V_15 , V_57 , V_35 ) ) {
int V_91 ;
V_91 = F_57 ( V_15 , V_57 , V_35 ) ;
if ( V_91 ) {
V_57 += V_91 ;
V_35 -= V_91 ;
continue;
}
return 0 ;
}
V_85 = F_58 ( V_15 , V_57 , & V_81 ) ;
V_97 = F_56 ( V_15 , V_85 ) ;
V_34 = V_15 -> V_32 - V_35 ;
F_2 ( V_97 != 0 ) ;
F_64 ( & V_15 -> V_102 ) ;
V_39 = F_55 ( V_15 , V_85 , V_81 , V_23 , V_34 ) ;
F_65 ( & V_15 -> V_102 ) ;
if ( V_39 )
return V_39 ;
V_57 += V_97 ;
V_35 -= V_97 ;
}
return 0 ;
}
static int F_66 ( struct V_14 * V_15 )
{
int V_4 , V_23 = - 1 , V_24 = 0 ;
F_64 ( & V_15 -> V_102 ) ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ ) {
F_2 ( ! V_15 -> V_25 [ V_4 ] . V_30 ) ;
if ( V_4 + V_15 -> V_26 == V_15 -> V_40 ||
V_15 -> V_25 [ V_4 ] . free + V_15 -> V_25 [ V_4 ] . V_24 == V_15 -> V_32 )
continue;
if ( V_15 -> V_25 [ V_4 ] . V_24 > V_24 ) {
V_24 = V_15 -> V_25 [ V_4 ] . V_24 ;
V_23 = V_4 + V_15 -> V_26 ;
}
}
F_65 ( & V_15 -> V_102 ) ;
if ( V_23 == - 1 )
return - V_33 ;
return F_62 ( V_15 , V_23 ) ;
}
int F_67 ( struct V_14 * V_15 )
{
int V_39 , V_17 ;
F_8 ( L_12 ) ;
F_64 ( & V_15 -> V_102 ) ;
V_39 = F_68 ( V_15 ) ;
if ( V_39 )
goto V_103;
V_39 = F_69 ( V_15 ) ;
if ( V_39 )
goto V_103;
if ( V_15 -> V_104 ) {
V_15 -> V_104 = 0 ;
while ( F_44 ( V_15 ) ) {
F_65 ( & V_15 -> V_102 ) ;
V_39 = F_66 ( V_15 ) ;
if ( V_39 )
return V_39 ;
F_64 ( & V_15 -> V_102 ) ;
}
}
F_45 ( V_15 ) ;
if ( ! V_15 -> V_22 ) {
F_7 ( L_13 ) ;
V_39 = 0 ;
goto V_103;
}
if ( ! V_15 -> V_42 && F_44 ( V_15 ) ) {
V_39 = F_42 ( V_15 ) ;
if ( V_39 )
goto V_103;
F_45 ( V_15 ) ;
}
if ( V_15 -> V_42 )
F_47 ( V_15 ) ;
V_17 = F_5 ( V_15 ) ;
F_2 ( V_17 != 0 ) ;
V_39 = F_11 ( V_15 ) ;
if ( V_39 )
goto V_103;
memcpy ( V_15 -> V_60 , V_15 -> V_25 ,
sizeof( struct V_105 ) * V_15 -> V_29 ) ;
V_15 -> V_72 &= ~ ( V_84 | V_73 ) ;
V_103:
F_65 ( & V_15 -> V_102 ) ;
return V_39 ;
}
static void F_70 ( struct V_14 * V_15 )
{
struct V_1 * V_7 , * V_16 ;
V_16 = V_15 -> V_19 ;
if ( ! V_16 )
return;
do {
V_7 = V_16 ;
V_16 = V_7 -> V_16 ;
if ( F_3 ( V_106 , & V_7 -> V_10 ) )
F_71 ( V_7 ) ;
else
V_7 -> V_16 = NULL ;
} while ( V_16 != V_15 -> V_19 );
V_15 -> V_19 = NULL ;
}
int F_72 ( struct V_14 * V_15 )
{
int V_39 ;
F_8 ( L_12 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
V_39 = F_19 ( V_15 ) ;
if ( V_39 )
return V_39 ;
F_64 ( & V_15 -> V_102 ) ;
F_70 ( V_15 ) ;
F_65 ( & V_15 -> V_102 ) ;
return 0 ;
}
int F_73 ( struct V_14 * V_15 )
{
int V_39 ;
F_64 ( & V_15 -> V_102 ) ;
V_39 = F_46 ( V_15 ) ;
if ( V_39 )
goto V_103;
if ( V_15 -> V_42 )
while ( F_44 ( V_15 ) ) {
F_65 ( & V_15 -> V_102 ) ;
V_39 = F_66 ( V_15 ) ;
if ( V_39 )
return V_39 ;
F_64 ( & V_15 -> V_102 ) ;
}
V_103:
F_65 ( & V_15 -> V_102 ) ;
return V_39 ;
}
static struct V_2 * F_74 ( struct V_14 * V_15 , int * V_107 )
{
struct V_2 * V_3 ;
int V_63 , V_4 , V_108 ;
V_3 = V_15 -> V_18 ;
* V_107 = 0 ;
if ( ! V_3 )
return NULL ;
for ( V_63 = 1 ; V_63 < V_15 -> V_66 ; V_63 ++ ) {
V_108 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_3 -> V_8 [ V_4 ] . V_3 ) {
V_108 = 1 ;
V_3 = V_3 -> V_8 [ V_4 ] . V_3 ;
* V_107 = V_63 ;
break;
}
}
if ( ! V_108 )
break;
}
return V_3 ;
}
static struct V_2 * F_75 ( struct V_14 * V_15 ,
struct V_2 * V_3 , int * V_107 )
{
struct V_2 * V_12 ;
int V_13 , V_63 , V_4 , V_108 ;
V_12 = V_3 -> V_12 ;
if ( ! V_12 )
return NULL ;
if ( V_3 -> V_13 == V_6 - 1 ) {
* V_107 -= 1 ;
return V_12 ;
}
for ( V_13 = V_3 -> V_13 + 1 ; V_13 < V_6 ; V_13 ++ ) {
V_3 = V_12 -> V_8 [ V_13 ] . V_3 ;
if ( V_3 )
break;
}
if ( ! V_3 ) {
* V_107 -= 1 ;
return V_12 ;
}
for ( V_63 = * V_107 + 1 ; V_63 < V_15 -> V_66 ; V_63 ++ ) {
V_108 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_3 -> V_8 [ V_4 ] . V_3 ) {
V_108 = 1 ;
V_3 = V_3 -> V_8 [ V_4 ] . V_3 ;
* V_107 = V_63 ;
break;
}
}
if ( ! V_108 )
break;
}
return V_3 ;
}
void F_76 ( struct V_14 * V_15 , int V_109 )
{
struct V_2 * V_3 ;
int V_4 , V_107 ;
F_70 ( V_15 ) ;
F_77 ( V_15 -> V_60 ) ;
V_15 -> V_60 = NULL ;
F_77 ( V_15 -> V_58 ) ;
V_15 -> V_58 = NULL ;
F_71 ( V_15 -> V_59 ) ;
V_15 -> V_59 = NULL ;
if ( V_109 )
return;
V_3 = F_74 ( V_15 , & V_107 ) ;
while ( V_3 ) {
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_71 ( V_3 -> V_8 [ V_4 ] . V_3 ) ;
V_3 = F_75 ( V_15 , V_3 , & V_107 ) ;
}
for ( V_4 = 0 ; V_4 < V_110 ; V_4 ++ )
F_71 ( V_15 -> V_75 [ V_4 ] . V_77 ) ;
F_71 ( V_15 -> V_111 . V_77 ) ;
F_71 ( V_15 -> V_18 ) ;
F_77 ( V_15 -> V_25 ) ;
F_71 ( V_15 -> V_112 ) ;
}
static int F_78 ( T_1 * V_57 , int V_35 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ )
if ( V_57 [ V_4 ] != 0xff )
return 0 ;
return 1 ;
}
static int F_79 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
struct V_2 * V_3 ;
int V_107 ;
V_3 = F_74 ( V_15 , & V_107 ) ;
for (; V_3 ; V_3 = F_75 ( V_15 , V_3 , & V_107 ) ) {
struct V_82 * V_83 ;
F_80 () ;
if ( V_3 -> V_12 ) {
V_83 = & V_3 -> V_12 -> V_8 [ V_3 -> V_13 ] ;
if ( V_83 -> V_23 != V_23 || V_83 -> V_34 != V_34 )
continue;
if ( F_3 ( V_9 , & V_3 -> V_10 ) )
return 1 ;
return 0 ;
} else {
if ( V_15 -> V_53 != V_23 || V_15 -> V_54 != V_34 )
continue;
if ( F_3 ( V_9 , & V_3 -> V_10 ) )
return 1 ;
return 0 ;
}
}
return 1 ;
}
static int F_81 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
int V_4 , V_17 ;
V_17 = F_82 ( V_15 -> V_113 , V_6 ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
struct V_61 * V_62 ;
struct V_82 * V_83 ;
F_80 () ;
V_62 = F_33 ( V_15 , V_4 ) ;
if ( F_32 ( V_62 ) )
return F_43 ( V_62 ) ;
V_83 = & V_62 -> V_12 -> V_8 [ V_62 -> V_13 ] ;
if ( V_83 -> V_23 != V_23 || V_83 -> V_34 != V_34 )
continue;
if ( F_3 ( V_9 , & V_62 -> V_10 ) )
return 1 ;
return 0 ;
}
return 1 ;
}
static int F_83 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_47 || V_34 != V_15 -> V_48 )
return 1 ;
return ( V_15 -> V_72 & V_84 ) != 0 ;
}
static int F_84 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_44 || V_34 != V_15 -> V_45 )
return 1 ;
return ( V_15 -> V_72 & V_73 ) != 0 ;
}
static int F_85 ( struct V_14 * V_15 , int V_85 , int V_23 ,
int V_34 )
{
switch ( V_85 ) {
case V_86 :
return F_79 ( V_15 , V_23 , V_34 ) ;
case V_87 :
return F_81 ( V_15 , V_23 , V_34 ) ;
case V_88 :
return F_83 ( V_15 , V_23 , V_34 ) ;
case V_89 :
return F_84 ( V_15 , V_23 , V_34 ) ;
}
return 1 ;
}
static int F_86 ( struct V_14 * V_15 , int V_23 )
{
int V_39 , V_35 = V_15 -> V_32 , V_24 = 0 , V_85 , V_81 , V_97 ;
int V_114 ;
void * V_57 , * V_115 ;
if ( ! F_87 ( V_15 ) )
return 0 ;
V_57 = V_115 = F_88 ( V_15 -> V_32 , V_116 , V_117 ) ;
if ( ! V_57 ) {
F_14 ( L_14 ) ;
return 0 ;
}
F_8 ( L_11 , V_23 ) ;
V_39 = F_63 ( V_15 , V_23 , V_57 , 0 , V_15 -> V_32 , 1 ) ;
if ( V_39 )
goto V_103;
while ( 1 ) {
if ( ! F_60 ( V_15 , V_115 , V_35 ) ) {
int V_4 , V_91 ;
V_91 = F_57 ( V_15 , V_115 , V_35 ) ;
if ( V_91 ) {
V_115 += V_91 ;
V_35 -= V_91 ;
V_24 += V_91 ;
continue;
}
if ( ! F_78 ( V_115 , V_35 ) ) {
F_89 ( L_15 ,
V_23 , V_15 -> V_32 - V_35 ) ;
V_39 = - V_90 ;
}
V_4 = V_23 - V_15 -> V_26 ;
if ( V_35 != V_15 -> V_25 [ V_4 ] . free ) {
F_89 ( L_16
L_17 ,
V_23 , V_35 , V_15 -> V_25 [ V_4 ] . free ) ;
V_39 = - V_90 ;
}
if ( V_24 != V_15 -> V_25 [ V_4 ] . V_24 ) {
F_89 ( L_18
L_19 ,
V_23 , V_24 , V_15 -> V_25 [ V_4 ] . V_24 ) ;
V_39 = - V_90 ;
}
goto V_103;
}
V_85 = F_58 ( V_15 , V_115 , & V_81 ) ;
V_97 = F_56 ( V_15 , V_85 ) ;
V_114 = F_85 ( V_15 , V_85 , V_23 , V_15 -> V_32 - V_35 ) ;
if ( V_114 == 1 )
V_24 += V_97 ;
V_115 += V_97 ;
V_35 -= V_97 ;
}
V_39 = 0 ;
V_103:
F_77 ( V_57 ) ;
return V_39 ;
}
int F_69 ( struct V_14 * V_15 )
{
int V_23 , V_39 , V_4 , V_17 ;
if ( ! F_87 ( V_15 ) )
return 0 ;
V_17 = F_82 ( V_15 -> V_113 , V_6 ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
struct V_61 * V_62 ;
V_62 = F_33 ( V_15 , V_4 ) ;
if ( F_32 ( V_62 ) )
return F_43 ( V_62 ) ;
F_80 () ;
}
V_39 = F_90 ( V_15 , (struct V_1 * ) V_15 -> V_18 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
for ( V_23 = V_15 -> V_26 ; V_23 <= V_15 -> V_27 ; V_23 ++ ) {
V_39 = F_86 ( V_15 , V_23 ) ;
if ( V_39 ) {
F_14 ( L_20 , V_23 ) ;
return V_39 ;
}
}
F_8 ( L_21 ) ;
return 0 ;
}
int F_68 ( struct V_14 * V_15 )
{
long long free = 0 ;
int V_4 ;
if ( ! F_87 ( V_15 ) )
return 0 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ ) {
if ( V_15 -> V_25 [ V_4 ] . V_30 || V_15 -> V_25 [ V_4 ] . V_31 )
continue;
if ( V_4 + V_15 -> V_26 == V_15 -> V_40 )
free += V_15 -> V_32 - V_15 -> V_41 ;
else if ( V_15 -> V_25 [ V_4 ] . free == V_15 -> V_32 )
free += V_15 -> V_32 ;
}
if ( free < V_15 -> V_67 ) {
F_14 ( L_22 ,
free , V_15 -> V_67 ) ;
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_17 () ;
return - V_90 ;
}
return 0 ;
}
int F_12 ( struct V_14 * V_15 , int V_118 , int V_35 )
{
struct V_119 * V_120 = V_15 -> V_121 ;
long long V_122 , V_67 ;
int V_39 = 0 ;
if ( ! F_87 ( V_15 ) )
return 0 ;
switch ( V_118 ) {
case 0 :
V_120 -> V_122 = 0 ;
V_120 -> V_123 = 0 ;
V_120 -> V_124 = 0 ;
V_120 -> V_125 = 0 ;
if ( V_15 -> V_22 > V_15 -> V_126 ) {
F_14 ( L_23 ,
V_15 -> V_22 , V_15 -> V_126 ) ;
V_39 = - V_90 ;
}
if ( V_15 -> V_21 > V_15 -> V_127 ) {
F_14 ( L_24 ,
V_15 -> V_21 , V_15 -> V_127 ) ;
V_39 = - V_90 ;
}
return V_39 ;
case 1 :
V_120 -> V_122 += V_35 ;
return 0 ;
case 2 :
V_120 -> V_122 += V_35 ;
V_120 -> V_125 += V_35 ;
V_120 -> V_124 += 1 ;
return 0 ;
case 3 :
V_122 = V_15 -> V_32 ;
V_122 *= V_120 -> V_124 ;
V_122 += V_35 - V_15 -> V_41 ;
if ( V_120 -> V_122 != V_122 ) {
F_14 ( L_25 ,
V_120 -> V_122 , V_122 ) ;
V_39 = - V_90 ;
}
if ( V_120 -> V_122 > V_15 -> V_67 ) {
F_14 ( L_26 ,
V_120 -> V_122 , V_15 -> V_67 ) ;
V_39 = - V_90 ;
}
if ( V_120 -> V_123 && V_120 -> V_122 != V_120 -> V_123 ) {
F_14 ( L_27 ,
V_120 -> V_122 , V_120 -> V_123 ) ;
V_39 = - V_90 ;
}
if ( V_120 -> V_123 && V_120 -> V_128 != V_35 ) {
F_14 ( L_28 ,
V_120 -> V_128 , V_35 ) ;
V_39 = - V_90 ;
}
V_67 = ( long long ) V_15 -> V_126 * V_15 -> V_50 ;
V_67 += ( long long ) V_15 -> V_127 * V_15 -> V_49 ;
V_67 += V_15 -> V_46 ;
if ( V_15 -> V_42 )
V_67 += V_15 -> V_43 ;
if ( V_120 -> V_122 - V_120 -> V_125 > V_67 ) {
F_14 ( L_29 ,
V_120 -> V_122 , V_120 -> V_125 , V_67 ) ;
V_39 = - V_90 ;
}
if ( V_39 ) {
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_17 () ;
}
V_120 -> V_123 = V_120 -> V_122 ;
V_120 -> V_122 = 0 ;
V_120 -> V_125 = 0 ;
V_120 -> V_124 = 0 ;
V_120 -> V_128 = V_35 ;
return V_39 ;
case 4 :
V_120 -> V_122 += V_35 ;
V_120 -> V_125 += V_35 ;
return 0 ;
default:
return - V_90 ;
}
}
static void F_91 ( const struct V_14 * V_15 , int V_23 )
{
int V_39 , V_35 = V_15 -> V_32 , V_85 , V_81 , V_97 , V_34 ;
void * V_57 , * V_115 ;
F_92 ( V_129 L_30 ,
V_130 -> V_131 , V_23 ) ;
V_57 = V_115 = F_88 ( V_15 -> V_32 , V_116 , V_117 ) ;
if ( ! V_57 ) {
F_14 ( L_31 ) ;
return;
}
V_39 = F_63 ( V_15 , V_23 , V_57 , 0 , V_15 -> V_32 , 1 ) ;
if ( V_39 )
goto V_103;
while ( 1 ) {
V_34 = V_15 -> V_32 - V_35 ;
if ( ! F_60 ( V_15 , V_115 , V_35 ) ) {
int V_91 ;
V_91 = F_57 ( V_15 , V_115 , V_35 ) ;
if ( V_91 ) {
F_92 ( V_129 L_32 ,
V_23 , V_34 , V_91 ) ;
V_115 += V_91 ;
V_35 -= V_91 ;
continue;
}
if ( V_35 )
F_92 ( V_129 L_33 ,
V_23 , V_34 , V_35 ) ;
break;
}
V_85 = F_58 ( V_15 , V_115 , & V_81 ) ;
switch ( V_85 ) {
case V_87 :
{
V_97 = V_15 -> V_50 ;
if ( V_15 -> V_42 )
F_92 ( V_129 L_34 ,
V_23 , V_34 , V_81 ) ;
else
F_92 ( V_129 L_35 ,
V_23 , V_34 ) ;
break;
}
case V_86 :
{
int V_4 ;
struct V_2 V_3 ;
V_97 = V_15 -> V_49 ;
if ( V_15 -> V_42 )
F_92 ( V_129 L_36 ,
V_23 , V_34 , V_81 ) ;
else
F_92 ( V_129 L_37 ,
V_23 , V_34 ) ;
V_39 = F_93 ( V_15 , V_115 , & V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
F_92 ( V_132 L_38 , V_3 . V_8 [ V_4 ] . V_23 ,
V_3 . V_8 [ V_4 ] . V_34 ) ;
if ( V_4 != V_6 - 1 )
F_92 ( V_132 L_39 ) ;
}
F_92 ( V_132 L_40 ) ;
break;
}
case V_88 :
V_97 = V_15 -> V_46 ;
F_92 ( V_129 L_41 ,
V_23 , V_34 ) ;
break;
case V_89 :
V_97 = V_15 -> V_43 ;
F_92 ( V_129 L_42 , V_23 , V_34 ) ;
break;
default:
F_14 ( L_43 , V_85 ) ;
goto V_103;
}
V_115 += V_97 ;
V_35 -= V_97 ;
}
F_92 ( V_129 L_44 ,
V_130 -> V_131 , V_23 ) ;
V_103:
F_77 ( V_57 ) ;
return;
}
void F_16 ( const struct V_14 * V_15 )
{
int V_4 ;
F_92 ( V_129 L_45 ,
V_130 -> V_131 ) ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ )
F_91 ( V_15 , V_4 + V_15 -> V_26 ) ;
F_92 ( V_129 L_46 ,
V_130 -> V_131 ) ;
}
static int F_48 ( struct V_14 * V_15 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_4 ;
if ( ! F_94 ( V_15 ) )
return 0 ;
if ( F_95 () & 3 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_74 ; V_4 ++ )
V_15 -> V_59 [ V_4 ] = V_15 -> V_80 ;
F_49 (lprops, &c->empty_list, list)
V_15 -> V_59 [ F_95 () % V_15 -> V_74 ] = V_69 -> V_23 ;
F_49 (lprops, &c->freeable_list, list)
V_15 -> V_59 [ F_95 () % V_15 -> V_74 ] = V_69 -> V_23 ;
F_49 (lprops, &c->frdi_idx_list, list)
V_15 -> V_59 [ F_95 () % V_15 -> V_74 ] = V_69 -> V_23 ;
V_71 = & V_15 -> V_75 [ V_76 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_71 -> V_17 ; V_4 ++ )
V_15 -> V_59 [ F_95 () % V_15 -> V_74 ] = V_71 -> V_77 [ V_4 ] -> V_23 ;
V_71 = & V_15 -> V_75 [ V_78 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_71 -> V_17 ; V_4 ++ )
V_15 -> V_59 [ F_95 () % V_15 -> V_74 ] = V_71 -> V_77 [ V_4 ] -> V_23 ;
V_71 = & V_15 -> V_75 [ V_79 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_71 -> V_17 ; V_4 ++ )
V_15 -> V_59 [ F_95 () % V_15 -> V_74 ] = V_71 -> V_77 [ V_4 ] -> V_23 ;
return 1 ;
}
