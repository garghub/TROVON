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
F_14 ( L_3 ) ;
F_15 ( L_4
L_5 , V_23 , V_34 , V_35 , V_38 , V_37 ) ;
F_16 ( V_15 ) ;
F_17 ( V_15 ) ;
F_18 () ;
return V_39 ;
}
static int F_19 ( struct V_14 * V_15 , int * V_23 )
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
static int F_20 ( struct V_14 * V_15 )
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
V_39 = F_21 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
}
V_37 = ! V_15 -> V_42 ;
V_38 = 0 ;
if ( ! V_37 && V_34 + V_15 -> V_43 <= V_15 -> V_32 ) {
V_37 = 1 ;
F_22 ( V_15 , V_57 + V_34 , V_15 -> V_59 ) ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
}
if ( V_34 + V_15 -> V_46 <= V_15 -> V_32 ) {
V_38 = 1 ;
F_23 ( V_15 , V_57 + V_34 , V_15 -> V_60 ) ;
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
V_39 = F_24 ( V_15 , V_23 , V_57 + V_55 , V_55 ,
V_36 , V_61 ) ;
if ( V_39 )
return V_39 ;
}
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_19 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = V_55 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
V_39 = F_21 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
if ( ! V_37 ) {
V_37 = 1 ;
F_22 ( V_15 , V_57 + V_34 , V_15 -> V_59 ) ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
continue;
}
if ( ! V_38 ) {
V_38 = 1 ;
F_23 ( V_15 , V_57 + V_34 , V_15 -> V_60 ) ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
continue;
}
break;
}
if ( V_7 -> V_11 )
F_25 ( V_15 , V_57 + V_34 ,
(struct V_2 * ) V_7 ) ;
else
F_26 ( V_15 , V_57 + V_34 ,
(struct V_62 * ) V_7 ) ;
F_27 ( V_9 , & V_7 -> V_10 ) ;
F_28 () ;
F_27 ( V_20 , & V_7 -> V_10 ) ;
F_29 () ;
V_34 += V_35 ;
F_12 ( V_15 , 1 , V_35 ) ;
V_7 = V_7 -> V_16 ;
} while ( V_7 && V_7 != V_15 -> V_19 );
if ( ! V_37 ) {
if ( V_34 + V_15 -> V_43 > V_15 -> V_32 ) {
V_56 = V_34 - V_55 ;
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_24 ( V_15 , V_23 , V_57 + V_55 , V_55 , V_36 ,
V_61 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_19 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = V_55 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
V_39 = F_21 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
}
V_37 = 1 ;
F_22 ( V_15 , V_57 + V_34 , V_15 -> V_59 ) ;
V_34 += V_15 -> V_43 ;
F_12 ( V_15 , 1 , V_15 -> V_43 ) ;
}
if ( ! V_38 ) {
if ( V_34 + V_15 -> V_46 > V_15 -> V_32 ) {
V_56 = V_34 - V_55 ;
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_24 ( V_15 , V_23 , V_57 + V_55 , V_55 , V_36 ,
V_61 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_15 , 2 , V_15 -> V_32 - V_34 ) ;
V_39 = F_19 ( V_15 , & V_23 ) ;
if ( V_39 )
goto V_52;
V_34 = V_55 = 0 ;
F_2 ( V_23 >= V_15 -> V_26 &&
V_23 <= V_15 -> V_27 ) ;
V_39 = F_21 ( V_15 , V_23 ) ;
if ( V_39 )
return V_39 ;
}
V_38 = 1 ;
F_23 ( V_15 , V_57 + V_34 , V_15 -> V_60 ) ;
V_34 += V_15 -> V_46 ;
F_12 ( V_15 , 1 , V_15 -> V_46 ) ;
}
V_56 = V_34 - V_55 ;
V_36 = F_13 ( V_56 , V_15 -> V_51 ) ;
memset ( V_57 + V_34 , 0xff , V_36 - V_56 ) ;
V_39 = F_24 ( V_15 , V_23 , V_57 + V_55 , V_55 , V_36 , V_61 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_15 , 4 , V_36 - V_56 ) ;
V_39 = F_12 ( V_15 , 3 , F_13 ( V_34 , V_15 -> V_51 ) ) ;
if ( V_39 )
return V_39 ;
V_15 -> V_40 = V_23 ;
V_15 -> V_41 = F_13 ( V_34 , V_15 -> V_51 ) ;
F_8 ( L_6 , V_15 -> V_53 , V_15 -> V_54 ) ;
F_8 ( L_7 , V_15 -> V_40 , V_15 -> V_41 ) ;
F_8 ( L_8 , V_15 -> V_47 , V_15 -> V_48 ) ;
if ( V_15 -> V_42 )
F_8 ( L_9 , V_15 -> V_44 , V_15 -> V_45 ) ;
return 0 ;
V_52:
F_14 ( L_10 ) ;
F_15 ( L_11
L_12 , V_23 , V_34 , V_35 , V_38 , V_37 ) ;
F_16 ( V_15 ) ;
F_17 ( V_15 ) ;
F_18 () ;
return V_39 ;
}
static struct V_62 * F_30 ( struct V_14 * V_15 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = V_63 -> V_12 ;
for ( V_13 = V_63 -> V_13 + 1 ; V_13 < V_6 ; V_13 ++ ) {
if ( V_3 -> V_8 [ V_13 ] . V_23 )
return F_31 ( V_15 , V_3 , V_13 ) ;
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
V_3 = F_32 ( V_15 , V_3 , V_13 ) ;
if ( F_33 ( V_3 ) )
return ( void * ) V_3 ;
while ( V_3 -> V_11 > 1 ) {
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
if ( V_3 -> V_8 [ V_13 ] . V_23 )
break;
}
if ( V_13 >= V_6 ) {
V_13 = 0 ;
}
V_3 = F_32 ( V_15 , V_3 , V_13 ) ;
if ( F_33 ( V_3 ) )
return ( void * ) V_3 ;
}
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ )
if ( V_3 -> V_8 [ V_13 ] . V_23 )
break;
if ( V_13 >= V_6 )
V_13 = 0 ;
return F_31 ( V_15 , V_3 , V_13 ) ;
}
static struct V_62 * F_34 ( struct V_14 * V_15 , int V_4 )
{
int V_39 , V_64 , V_13 , V_65 ;
struct V_2 * V_3 ;
if ( ! V_15 -> V_18 ) {
V_39 = F_35 ( V_15 , NULL , 0 ) ;
if ( V_39 )
return F_36 ( V_39 ) ;
}
V_4 <<= V_66 ;
V_3 = V_15 -> V_18 ;
V_65 = V_15 -> V_67 * V_66 ;
for ( V_64 = 1 ; V_64 < V_15 -> V_67 ; V_64 ++ ) {
V_13 = ( ( V_4 >> V_65 ) & ( V_6 - 1 ) ) ;
V_65 -= V_66 ;
V_3 = F_32 ( V_15 , V_3 , V_13 ) ;
if ( F_33 ( V_3 ) )
return F_37 ( V_3 ) ;
}
V_13 = ( ( V_4 >> V_65 ) & ( V_6 - 1 ) ) ;
return F_31 ( V_15 , V_3 , V_13 ) ;
}
static void F_38 ( struct V_14 * V_15 , struct V_62 * V_63 )
{
F_39 ( V_15 , V_63 -> V_12 -> V_8 [ V_63 -> V_13 ] . V_23 ,
V_15 -> V_50 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_62 * V_63 )
{
if ( ! F_41 ( V_9 , & V_63 -> V_10 ) ) {
struct V_2 * V_3 ;
V_15 -> V_22 += 1 ;
F_38 ( V_15 , V_63 ) ;
V_3 = V_63 -> V_12 ;
while ( V_3 ) {
if ( ! F_41 ( V_9 , & V_3 -> V_10 ) ) {
V_15 -> V_21 += 1 ;
F_42 ( V_15 , V_3 ) ;
V_3 = V_3 -> V_12 ;
} else
break;
}
}
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_62 * V_63 ;
V_63 = F_34 ( V_15 , 0 ) ;
if ( F_33 ( V_63 ) )
return F_44 ( V_63 ) ;
while ( V_63 ) {
F_40 ( V_15 , V_63 ) ;
V_63 = F_30 ( V_15 , V_63 ) ;
if ( F_33 ( V_63 ) )
return F_44 ( V_63 ) ;
}
return 0 ;
}
static int F_45 ( struct V_14 * V_15 )
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
if ( free <= V_15 -> V_68 * 2 )
return 1 ;
return 0 ;
}
static void F_46 ( struct V_14 * V_15 )
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
F_8 ( L_13 , V_4 + V_15 -> V_26 ) ;
}
}
}
static int F_47 ( struct V_14 * V_15 )
{
int V_4 , V_39 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ )
if ( V_15 -> V_25 [ V_4 ] . V_30 ) {
V_39 = F_21 ( V_15 , V_4 + V_15 -> V_26 ) ;
if ( V_39 )
return V_39 ;
V_15 -> V_25 [ V_4 ] . V_30 = 0 ;
F_8 ( L_13 , V_4 + V_15 -> V_26 ) ;
}
return 0 ;
}
static void F_48 ( struct V_14 * V_15 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
int V_4 , V_17 = 0 ;
F_2 ( V_15 -> V_42 ) ;
if ( ! ( V_15 -> V_73 & V_74 ) ) {
V_15 -> V_73 |= V_74 ;
F_39 ( V_15 , V_15 -> V_44 , V_15 -> V_43 ) ;
}
if ( F_49 ( V_15 ) )
return;
F_50 (lprops, &c->empty_list, list) {
V_15 -> V_59 [ V_17 ++ ] = V_70 -> V_23 ;
if ( V_17 >= V_15 -> V_75 )
return;
}
F_50 (lprops, &c->freeable_list, list) {
V_15 -> V_59 [ V_17 ++ ] = V_70 -> V_23 ;
if ( V_17 >= V_15 -> V_75 )
return;
}
F_50 (lprops, &c->frdi_idx_list, list) {
V_15 -> V_59 [ V_17 ++ ] = V_70 -> V_23 ;
if ( V_17 >= V_15 -> V_75 )
return;
}
V_72 = & V_15 -> V_76 [ V_77 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_72 -> V_17 ; V_4 ++ ) {
V_15 -> V_59 [ V_17 ++ ] = V_72 -> V_78 [ V_4 ] -> V_23 ;
if ( V_17 >= V_15 -> V_75 )
return;
}
V_72 = & V_15 -> V_76 [ V_79 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_72 -> V_17 ; V_4 ++ ) {
V_15 -> V_59 [ V_17 ++ ] = V_72 -> V_78 [ V_4 ] -> V_23 ;
if ( V_17 >= V_15 -> V_75 )
return;
}
V_72 = & V_15 -> V_76 [ V_80 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_72 -> V_17 ; V_4 ++ ) {
V_15 -> V_59 [ V_17 ++ ] = V_72 -> V_78 [ V_4 ] -> V_23 ;
if ( V_17 >= V_15 -> V_75 )
return;
}
while ( V_17 < V_15 -> V_75 )
V_15 -> V_59 [ V_17 ++ ] = V_15 -> V_81 ;
}
static struct V_2 * F_51 ( struct V_14 * V_15 , int V_4 )
{
int V_39 , V_13 ;
struct V_2 * V_3 ;
if ( ! V_15 -> V_18 ) {
V_39 = F_35 ( V_15 , NULL , 0 ) ;
if ( V_39 )
return F_36 ( V_39 ) ;
}
V_3 = V_15 -> V_18 ;
while ( 1 ) {
V_13 = V_4 & ( V_6 - 1 ) ;
V_4 >>= V_66 ;
if ( ! V_4 )
break;
V_3 = F_32 ( V_15 , V_3 , V_13 ) ;
if ( F_33 ( V_3 ) )
return V_3 ;
}
return V_3 ;
}
static int F_52 ( struct V_14 * V_15 , int V_82 , int V_23 ,
int V_34 )
{
struct V_2 * V_3 ;
V_3 = F_51 ( V_15 , V_82 ) ;
if ( F_33 ( V_3 ) )
return F_44 ( V_3 ) ;
if ( V_3 -> V_12 ) {
struct V_83 * V_84 ;
V_84 = & V_3 -> V_12 -> V_8 [ V_3 -> V_13 ] ;
if ( V_84 -> V_23 != V_23 || V_84 -> V_34 != V_34 )
return 0 ;
} else if ( V_15 -> V_53 != V_23 || V_15 -> V_54 != V_34 )
return 0 ;
if ( ! F_41 ( V_9 , & V_3 -> V_10 ) ) {
V_15 -> V_21 += 1 ;
F_42 ( V_15 , V_3 ) ;
V_3 = V_3 -> V_12 ;
while ( V_3 ) {
if ( ! F_41 ( V_9 , & V_3 -> V_10 ) ) {
V_15 -> V_21 += 1 ;
F_42 ( V_15 , V_3 ) ;
V_3 = V_3 -> V_12 ;
} else
break;
}
}
return 0 ;
}
static int F_53 ( struct V_14 * V_15 , int V_82 , int V_23 ,
int V_34 )
{
struct V_62 * V_63 ;
struct V_83 * V_84 ;
V_63 = F_34 ( V_15 , V_82 ) ;
if ( F_33 ( V_63 ) )
return F_44 ( V_63 ) ;
V_84 = & V_63 -> V_12 -> V_8 [ V_63 -> V_13 ] ;
if ( V_84 -> V_23 != V_23 || V_84 -> V_34 != V_34 )
return 0 ;
F_40 ( V_15 , V_63 ) ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_47 || V_34 != V_15 -> V_48 )
return 0 ;
if ( ! ( V_15 -> V_73 & V_85 ) ) {
V_15 -> V_73 |= V_85 ;
F_39 ( V_15 , V_15 -> V_47 , V_15 -> V_46 ) ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_44 || V_34 != V_15 -> V_45 )
return 0 ;
if ( ! ( V_15 -> V_73 & V_74 ) ) {
V_15 -> V_73 |= V_74 ;
F_39 ( V_15 , V_15 -> V_44 , V_15 -> V_43 ) ;
}
return 0 ;
}
static int F_56 ( struct V_14 * V_15 , int V_86 , int V_82 ,
int V_23 , int V_34 )
{
switch ( V_86 ) {
case V_87 :
return F_52 ( V_15 , V_82 , V_23 , V_34 ) ;
case V_88 :
return F_53 ( V_15 , V_82 , V_23 , V_34 ) ;
case V_89 :
return F_54 ( V_15 , V_23 , V_34 ) ;
case V_90 :
return F_55 ( V_15 , V_23 , V_34 ) ;
}
return - V_91 ;
}
static int F_57 ( const struct V_14 * V_15 , int V_86 )
{
switch ( V_86 ) {
case V_87 :
return V_15 -> V_49 ;
case V_88 :
return V_15 -> V_50 ;
case V_89 :
return V_15 -> V_46 ;
case V_90 :
return V_15 -> V_43 ;
}
return 0 ;
}
static int F_58 ( const struct V_14 * V_15 , T_1 * V_57 , int V_35 )
{
int V_34 , V_92 ;
if ( V_15 -> V_51 == 1 )
return 0 ;
V_34 = V_15 -> V_32 - V_35 ;
V_92 = F_13 ( V_34 , V_15 -> V_51 ) - V_34 ;
return V_92 ;
}
static int F_59 ( const struct V_14 * V_15 , T_1 * V_57 ,
int * V_82 )
{
T_1 * V_93 = V_57 + V_94 ;
int V_95 = 0 , V_86 ;
V_86 = F_60 ( & V_93 , & V_95 , V_96 ) ;
* V_82 = F_60 ( & V_93 , & V_95 , V_15 -> V_97 ) ;
return V_86 ;
}
static int F_61 ( const struct V_14 * V_15 , T_1 * V_57 , int V_35 )
{
T_1 * V_93 = V_57 + V_94 ;
int V_95 = 0 , V_86 , V_98 ;
T_2 V_99 , V_100 ;
if ( V_35 < V_94 + ( V_96 + 7 ) / 8 )
return 0 ;
V_86 = F_60 ( & V_93 , & V_95 , V_96 ) ;
if ( V_86 == V_101 )
return 0 ;
V_98 = F_57 ( V_15 , V_86 ) ;
if ( ! V_98 || V_98 > V_35 )
return 0 ;
V_95 = 0 ;
V_93 = V_57 ;
V_99 = F_60 ( & V_93 , & V_95 , V_102 ) ;
V_100 = F_62 ( - 1 , V_57 + V_94 ,
V_98 - V_94 ) ;
if ( V_99 != V_100 )
return 0 ;
return 1 ;
}
static int F_63 ( struct V_14 * V_15 , int V_23 )
{
int V_39 , V_35 = V_15 -> V_32 , V_86 , V_82 , V_98 , V_34 ;
void * V_57 = V_15 -> V_58 ;
F_8 ( L_13 , V_23 ) ;
V_39 = F_64 ( V_15 , V_23 , V_57 , 0 , V_15 -> V_32 , 1 ) ;
if ( V_39 )
return V_39 ;
while ( 1 ) {
if ( ! F_61 ( V_15 , V_57 , V_35 ) ) {
int V_92 ;
V_92 = F_58 ( V_15 , V_57 , V_35 ) ;
if ( V_92 ) {
V_57 += V_92 ;
V_35 -= V_92 ;
continue;
}
return 0 ;
}
V_86 = F_59 ( V_15 , V_57 , & V_82 ) ;
V_98 = F_57 ( V_15 , V_86 ) ;
V_34 = V_15 -> V_32 - V_35 ;
F_2 ( V_98 != 0 ) ;
F_65 ( & V_15 -> V_103 ) ;
V_39 = F_56 ( V_15 , V_86 , V_82 , V_23 , V_34 ) ;
F_66 ( & V_15 -> V_103 ) ;
if ( V_39 )
return V_39 ;
V_57 += V_98 ;
V_35 -= V_98 ;
}
return 0 ;
}
static int F_67 ( struct V_14 * V_15 )
{
int V_4 , V_23 = - 1 , V_24 = 0 ;
F_65 ( & V_15 -> V_103 ) ;
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
F_66 ( & V_15 -> V_103 ) ;
if ( V_23 == - 1 )
return - V_33 ;
return F_63 ( V_15 , V_23 ) ;
}
int F_68 ( struct V_14 * V_15 )
{
int V_39 , V_17 ;
F_8 ( L_14 ) ;
F_65 ( & V_15 -> V_103 ) ;
V_39 = F_69 ( V_15 ) ;
if ( V_39 )
goto V_104;
V_39 = F_70 ( V_15 ) ;
if ( V_39 )
goto V_104;
if ( V_15 -> V_105 ) {
V_15 -> V_105 = 0 ;
while ( F_45 ( V_15 ) ) {
F_66 ( & V_15 -> V_103 ) ;
V_39 = F_67 ( V_15 ) ;
if ( V_39 )
return V_39 ;
F_65 ( & V_15 -> V_103 ) ;
}
}
F_46 ( V_15 ) ;
if ( ! V_15 -> V_22 ) {
F_7 ( L_15 ) ;
V_39 = 0 ;
goto V_104;
}
if ( ! V_15 -> V_42 && F_45 ( V_15 ) ) {
V_39 = F_43 ( V_15 ) ;
if ( V_39 )
goto V_104;
F_46 ( V_15 ) ;
}
if ( V_15 -> V_42 )
F_48 ( V_15 ) ;
V_17 = F_5 ( V_15 ) ;
F_2 ( V_17 != 0 ) ;
V_39 = F_11 ( V_15 ) ;
if ( V_39 )
goto V_104;
memcpy ( V_15 -> V_60 , V_15 -> V_25 ,
sizeof( struct V_106 ) * V_15 -> V_29 ) ;
V_15 -> V_73 &= ~ ( V_85 | V_74 ) ;
V_104:
F_66 ( & V_15 -> V_103 ) ;
return V_39 ;
}
static void F_71 ( struct V_14 * V_15 )
{
struct V_1 * V_7 , * V_16 ;
V_16 = V_15 -> V_19 ;
if ( ! V_16 )
return;
do {
V_7 = V_16 ;
V_16 = V_7 -> V_16 ;
if ( F_3 ( V_107 , & V_7 -> V_10 ) )
F_72 ( V_7 ) ;
else
V_7 -> V_16 = NULL ;
} while ( V_16 != V_15 -> V_19 );
V_15 -> V_19 = NULL ;
}
int F_73 ( struct V_14 * V_15 )
{
int V_39 ;
F_8 ( L_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
V_39 = F_20 ( V_15 ) ;
if ( V_39 )
return V_39 ;
F_65 ( & V_15 -> V_103 ) ;
F_71 ( V_15 ) ;
F_66 ( & V_15 -> V_103 ) ;
return 0 ;
}
int F_74 ( struct V_14 * V_15 )
{
int V_39 ;
F_65 ( & V_15 -> V_103 ) ;
V_39 = F_47 ( V_15 ) ;
if ( V_39 )
goto V_104;
if ( V_15 -> V_42 )
while ( F_45 ( V_15 ) ) {
F_66 ( & V_15 -> V_103 ) ;
V_39 = F_67 ( V_15 ) ;
if ( V_39 )
return V_39 ;
F_65 ( & V_15 -> V_103 ) ;
}
V_104:
F_66 ( & V_15 -> V_103 ) ;
return V_39 ;
}
static struct V_2 * F_75 ( struct V_14 * V_15 , int * V_108 )
{
struct V_2 * V_3 ;
int V_64 , V_4 , V_109 ;
V_3 = V_15 -> V_18 ;
* V_108 = 0 ;
if ( ! V_3 )
return NULL ;
for ( V_64 = 1 ; V_64 < V_15 -> V_67 ; V_64 ++ ) {
V_109 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_3 -> V_8 [ V_4 ] . V_3 ) {
V_109 = 1 ;
V_3 = V_3 -> V_8 [ V_4 ] . V_3 ;
* V_108 = V_64 ;
break;
}
}
if ( ! V_109 )
break;
}
return V_3 ;
}
static struct V_2 * F_76 ( struct V_14 * V_15 ,
struct V_2 * V_3 , int * V_108 )
{
struct V_2 * V_12 ;
int V_13 , V_64 , V_4 , V_109 ;
V_12 = V_3 -> V_12 ;
if ( ! V_12 )
return NULL ;
if ( V_3 -> V_13 == V_6 - 1 ) {
* V_108 -= 1 ;
return V_12 ;
}
for ( V_13 = V_3 -> V_13 + 1 ; V_13 < V_6 ; V_13 ++ ) {
V_3 = V_12 -> V_8 [ V_13 ] . V_3 ;
if ( V_3 )
break;
}
if ( ! V_3 ) {
* V_108 -= 1 ;
return V_12 ;
}
for ( V_64 = * V_108 + 1 ; V_64 < V_15 -> V_67 ; V_64 ++ ) {
V_109 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_3 -> V_8 [ V_4 ] . V_3 ) {
V_109 = 1 ;
V_3 = V_3 -> V_8 [ V_4 ] . V_3 ;
* V_108 = V_64 ;
break;
}
}
if ( ! V_109 )
break;
}
return V_3 ;
}
void F_77 ( struct V_14 * V_15 , int V_110 )
{
struct V_2 * V_3 ;
int V_4 , V_108 ;
F_71 ( V_15 ) ;
F_78 ( V_15 -> V_60 ) ;
V_15 -> V_60 = NULL ;
F_78 ( V_15 -> V_58 ) ;
V_15 -> V_58 = NULL ;
F_72 ( V_15 -> V_59 ) ;
V_15 -> V_59 = NULL ;
if ( V_110 )
return;
V_3 = F_75 ( V_15 , & V_108 ) ;
while ( V_3 ) {
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_72 ( V_3 -> V_8 [ V_4 ] . V_3 ) ;
V_3 = F_76 ( V_15 , V_3 , & V_108 ) ;
}
for ( V_4 = 0 ; V_4 < V_111 ; V_4 ++ )
F_72 ( V_15 -> V_76 [ V_4 ] . V_78 ) ;
F_72 ( V_15 -> V_112 . V_78 ) ;
F_72 ( V_15 -> V_18 ) ;
F_78 ( V_15 -> V_25 ) ;
F_72 ( V_15 -> V_113 ) ;
}
static int F_79 ( T_1 * V_57 , int V_35 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ )
if ( V_57 [ V_4 ] != 0xff )
return 0 ;
return 1 ;
}
static int F_80 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
struct V_2 * V_3 ;
int V_108 ;
V_3 = F_75 ( V_15 , & V_108 ) ;
for (; V_3 ; V_3 = F_76 ( V_15 , V_3 , & V_108 ) ) {
struct V_83 * V_84 ;
F_81 () ;
if ( V_3 -> V_12 ) {
V_84 = & V_3 -> V_12 -> V_8 [ V_3 -> V_13 ] ;
if ( V_84 -> V_23 != V_23 || V_84 -> V_34 != V_34 )
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
static int F_82 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
int V_4 , V_17 ;
V_17 = F_83 ( V_15 -> V_114 , V_6 ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
struct V_62 * V_63 ;
struct V_83 * V_84 ;
F_81 () ;
V_63 = F_34 ( V_15 , V_4 ) ;
if ( F_33 ( V_63 ) )
return F_44 ( V_63 ) ;
V_84 = & V_63 -> V_12 -> V_8 [ V_63 -> V_13 ] ;
if ( V_84 -> V_23 != V_23 || V_84 -> V_34 != V_34 )
continue;
if ( F_3 ( V_9 , & V_63 -> V_10 ) )
return 1 ;
return 0 ;
}
return 1 ;
}
static int F_84 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_47 || V_34 != V_15 -> V_48 )
return 1 ;
return ( V_15 -> V_73 & V_85 ) != 0 ;
}
static int F_85 ( struct V_14 * V_15 , int V_23 , int V_34 )
{
if ( V_23 != V_15 -> V_44 || V_34 != V_15 -> V_45 )
return 1 ;
return ( V_15 -> V_73 & V_74 ) != 0 ;
}
static int F_86 ( struct V_14 * V_15 , int V_86 , int V_23 ,
int V_34 )
{
switch ( V_86 ) {
case V_87 :
return F_80 ( V_15 , V_23 , V_34 ) ;
case V_88 :
return F_82 ( V_15 , V_23 , V_34 ) ;
case V_89 :
return F_84 ( V_15 , V_23 , V_34 ) ;
case V_90 :
return F_85 ( V_15 , V_23 , V_34 ) ;
}
return 1 ;
}
static int F_87 ( struct V_14 * V_15 , int V_23 )
{
int V_39 , V_35 = V_15 -> V_32 , V_24 = 0 , V_86 , V_82 , V_98 ;
int V_115 ;
void * V_57 , * V_116 ;
if ( ! F_88 ( V_15 ) )
return 0 ;
V_57 = V_116 = F_89 ( V_15 -> V_32 , V_117 , V_118 ) ;
if ( ! V_57 ) {
F_14 ( L_16 ) ;
return 0 ;
}
F_8 ( L_13 , V_23 ) ;
V_39 = F_64 ( V_15 , V_23 , V_57 , 0 , V_15 -> V_32 , 1 ) ;
if ( V_39 )
goto V_104;
while ( 1 ) {
if ( ! F_61 ( V_15 , V_116 , V_35 ) ) {
int V_4 , V_92 ;
V_92 = F_58 ( V_15 , V_116 , V_35 ) ;
if ( V_92 ) {
V_116 += V_92 ;
V_35 -= V_92 ;
V_24 += V_92 ;
continue;
}
if ( ! F_79 ( V_116 , V_35 ) ) {
F_90 ( L_17 ,
V_23 , V_15 -> V_32 - V_35 ) ;
V_39 = - V_91 ;
}
V_4 = V_23 - V_15 -> V_26 ;
if ( V_35 != V_15 -> V_25 [ V_4 ] . free ) {
F_90 ( L_18
L_19 ,
V_23 , V_35 , V_15 -> V_25 [ V_4 ] . free ) ;
V_39 = - V_91 ;
}
if ( V_24 != V_15 -> V_25 [ V_4 ] . V_24 ) {
F_90 ( L_20
L_21 ,
V_23 , V_24 , V_15 -> V_25 [ V_4 ] . V_24 ) ;
V_39 = - V_91 ;
}
goto V_104;
}
V_86 = F_59 ( V_15 , V_116 , & V_82 ) ;
V_98 = F_57 ( V_15 , V_86 ) ;
V_115 = F_86 ( V_15 , V_86 , V_23 , V_15 -> V_32 - V_35 ) ;
if ( V_115 == 1 )
V_24 += V_98 ;
V_116 += V_98 ;
V_35 -= V_98 ;
}
V_39 = 0 ;
V_104:
F_78 ( V_57 ) ;
return V_39 ;
}
int F_70 ( struct V_14 * V_15 )
{
int V_23 , V_39 , V_4 , V_17 ;
if ( ! F_88 ( V_15 ) )
return 0 ;
V_17 = F_83 ( V_15 -> V_114 , V_6 ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
struct V_62 * V_63 ;
V_63 = F_34 ( V_15 , V_4 ) ;
if ( F_33 ( V_63 ) )
return F_44 ( V_63 ) ;
F_81 () ;
}
V_39 = F_91 ( V_15 , (struct V_1 * ) V_15 -> V_18 , 0 , 0 ) ;
if ( V_39 )
return V_39 ;
for ( V_23 = V_15 -> V_26 ; V_23 <= V_15 -> V_27 ; V_23 ++ ) {
V_39 = F_87 ( V_15 , V_23 ) ;
if ( V_39 ) {
F_15 ( L_22 , V_23 ) ;
return V_39 ;
}
}
F_8 ( L_23 ) ;
return 0 ;
}
int F_69 ( struct V_14 * V_15 )
{
long long free = 0 ;
int V_4 ;
if ( ! F_88 ( V_15 ) )
return 0 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ ) {
if ( V_15 -> V_25 [ V_4 ] . V_30 || V_15 -> V_25 [ V_4 ] . V_31 )
continue;
if ( V_4 + V_15 -> V_26 == V_15 -> V_40 )
free += V_15 -> V_32 - V_15 -> V_41 ;
else if ( V_15 -> V_25 [ V_4 ] . free == V_15 -> V_32 )
free += V_15 -> V_32 ;
}
if ( free < V_15 -> V_68 ) {
F_15 ( L_24 ,
free , V_15 -> V_68 ) ;
F_16 ( V_15 ) ;
F_17 ( V_15 ) ;
F_18 () ;
return - V_91 ;
}
return 0 ;
}
int F_12 ( struct V_14 * V_15 , int V_119 , int V_35 )
{
struct V_120 * V_121 = V_15 -> V_122 ;
long long V_123 , V_68 ;
int V_39 = 0 ;
if ( ! F_88 ( V_15 ) )
return 0 ;
switch ( V_119 ) {
case 0 :
V_121 -> V_123 = 0 ;
V_121 -> V_124 = 0 ;
V_121 -> V_125 = 0 ;
V_121 -> V_126 = 0 ;
if ( V_15 -> V_22 > V_15 -> V_127 ) {
F_15 ( L_25 ,
V_15 -> V_22 , V_15 -> V_127 ) ;
V_39 = - V_91 ;
}
if ( V_15 -> V_21 > V_15 -> V_128 ) {
F_15 ( L_26 ,
V_15 -> V_21 , V_15 -> V_128 ) ;
V_39 = - V_91 ;
}
return V_39 ;
case 1 :
V_121 -> V_123 += V_35 ;
return 0 ;
case 2 :
V_121 -> V_123 += V_35 ;
V_121 -> V_126 += V_35 ;
V_121 -> V_125 += 1 ;
return 0 ;
case 3 :
V_123 = V_15 -> V_32 ;
V_123 *= V_121 -> V_125 ;
V_123 += V_35 - V_15 -> V_41 ;
if ( V_121 -> V_123 != V_123 ) {
F_15 ( L_27 ,
V_121 -> V_123 , V_123 ) ;
V_39 = - V_91 ;
}
if ( V_121 -> V_123 > V_15 -> V_68 ) {
F_15 ( L_28 ,
V_121 -> V_123 , V_15 -> V_68 ) ;
V_39 = - V_91 ;
}
if ( V_121 -> V_124 && V_121 -> V_123 != V_121 -> V_124 ) {
F_15 ( L_29 ,
V_121 -> V_123 , V_121 -> V_124 ) ;
V_39 = - V_91 ;
}
if ( V_121 -> V_124 && V_121 -> V_129 != V_35 ) {
F_15 ( L_30 ,
V_121 -> V_129 , V_35 ) ;
V_39 = - V_91 ;
}
V_68 = ( long long ) V_15 -> V_127 * V_15 -> V_50 ;
V_68 += ( long long ) V_15 -> V_128 * V_15 -> V_49 ;
V_68 += V_15 -> V_46 ;
if ( V_15 -> V_42 )
V_68 += V_15 -> V_43 ;
if ( V_121 -> V_123 - V_121 -> V_126 > V_68 ) {
F_15 ( L_31 ,
V_121 -> V_123 , V_121 -> V_126 , V_68 ) ;
V_39 = - V_91 ;
}
if ( V_39 ) {
F_16 ( V_15 ) ;
F_17 ( V_15 ) ;
F_18 () ;
}
V_121 -> V_124 = V_121 -> V_123 ;
V_121 -> V_123 = 0 ;
V_121 -> V_126 = 0 ;
V_121 -> V_125 = 0 ;
V_121 -> V_129 = V_35 ;
return V_39 ;
case 4 :
V_121 -> V_123 += V_35 ;
V_121 -> V_126 += V_35 ;
return 0 ;
default:
return - V_91 ;
}
}
static void F_92 ( const struct V_14 * V_15 , int V_23 )
{
int V_39 , V_35 = V_15 -> V_32 , V_86 , V_82 , V_98 , V_34 ;
void * V_57 , * V_116 ;
F_93 ( V_130 L_32 ,
V_131 -> V_132 , V_23 ) ;
V_57 = V_116 = F_89 ( V_15 -> V_32 , V_117 , V_118 ) ;
if ( ! V_57 ) {
F_14 ( L_33 ) ;
return;
}
V_39 = F_64 ( V_15 , V_23 , V_57 , 0 , V_15 -> V_32 , 1 ) ;
if ( V_39 )
goto V_104;
while ( 1 ) {
V_34 = V_15 -> V_32 - V_35 ;
if ( ! F_61 ( V_15 , V_116 , V_35 ) ) {
int V_92 ;
V_92 = F_58 ( V_15 , V_116 , V_35 ) ;
if ( V_92 ) {
F_93 ( V_130 L_34 ,
V_23 , V_34 , V_92 ) ;
V_116 += V_92 ;
V_35 -= V_92 ;
continue;
}
if ( V_35 )
F_93 ( V_130 L_35 ,
V_23 , V_34 , V_35 ) ;
break;
}
V_86 = F_59 ( V_15 , V_116 , & V_82 ) ;
switch ( V_86 ) {
case V_88 :
{
V_98 = V_15 -> V_50 ;
if ( V_15 -> V_42 )
F_93 ( V_130 L_36 ,
V_23 , V_34 , V_82 ) ;
else
F_93 ( V_130 L_37 ,
V_23 , V_34 ) ;
break;
}
case V_87 :
{
int V_4 ;
struct V_2 V_3 ;
V_98 = V_15 -> V_49 ;
if ( V_15 -> V_42 )
F_93 ( V_130 L_38 ,
V_23 , V_34 , V_82 ) ;
else
F_93 ( V_130 L_39 ,
V_23 , V_34 ) ;
V_39 = F_94 ( V_15 , V_116 , & V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
F_93 ( V_133 L_40 , V_3 . V_8 [ V_4 ] . V_23 ,
V_3 . V_8 [ V_4 ] . V_34 ) ;
if ( V_4 != V_6 - 1 )
F_93 ( V_133 L_41 ) ;
}
F_93 ( V_133 L_42 ) ;
break;
}
case V_89 :
V_98 = V_15 -> V_46 ;
F_93 ( V_130 L_43 ,
V_23 , V_34 ) ;
break;
case V_90 :
V_98 = V_15 -> V_43 ;
F_93 ( V_130 L_44 , V_23 , V_34 ) ;
break;
default:
F_14 ( L_45 , V_86 ) ;
goto V_104;
}
V_116 += V_98 ;
V_35 -= V_98 ;
}
F_93 ( V_130 L_46 ,
V_131 -> V_132 , V_23 ) ;
V_104:
F_78 ( V_57 ) ;
return;
}
void F_17 ( const struct V_14 * V_15 )
{
int V_4 ;
F_93 ( V_130 L_47 ,
V_131 -> V_132 ) ;
for ( V_4 = 0 ; V_4 < V_15 -> V_29 ; V_4 ++ )
F_92 ( V_15 , V_4 + V_15 -> V_26 ) ;
F_93 ( V_130 L_48 ,
V_131 -> V_132 ) ;
}
static int F_49 ( struct V_14 * V_15 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
int V_4 ;
if ( ! F_95 ( V_15 ) )
return 0 ;
if ( F_96 () & 3 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_75 ; V_4 ++ )
V_15 -> V_59 [ V_4 ] = V_15 -> V_81 ;
F_50 (lprops, &c->empty_list, list)
V_15 -> V_59 [ F_96 () % V_15 -> V_75 ] = V_70 -> V_23 ;
F_50 (lprops, &c->freeable_list, list)
V_15 -> V_59 [ F_96 () % V_15 -> V_75 ] = V_70 -> V_23 ;
F_50 (lprops, &c->frdi_idx_list, list)
V_15 -> V_59 [ F_96 () % V_15 -> V_75 ] = V_70 -> V_23 ;
V_72 = & V_15 -> V_76 [ V_77 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_72 -> V_17 ; V_4 ++ )
V_15 -> V_59 [ F_96 () % V_15 -> V_75 ] = V_72 -> V_78 [ V_4 ] -> V_23 ;
V_72 = & V_15 -> V_76 [ V_79 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_72 -> V_17 ; V_4 ++ )
V_15 -> V_59 [ F_96 () % V_15 -> V_75 ] = V_72 -> V_78 [ V_4 ] -> V_23 ;
V_72 = & V_15 -> V_76 [ V_80 - 1 ] ;
for ( V_4 = 0 ; V_4 < V_72 -> V_17 ; V_4 ++ )
V_15 -> V_59 [ F_96 () % V_15 -> V_75 ] = V_72 -> V_78 [ V_4 ] -> V_23 ;
return 1 ;
}
