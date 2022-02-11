static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
void * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
T_2 V_9 ;
int V_10 ;
V_10 = F_3 ( V_7 , V_3 , V_4 , & V_9 , V_5 ) ;
F_4 ( V_10 == - V_11 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 != V_4 )
return - V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
void * V_5 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_13 -> V_8 ;
T_2 V_9 ;
T_1 V_14 , V_15 ;
int V_10 ;
if ( V_13 -> V_16 & V_17 )
return - V_18 ;
F_4 ( ( V_3 >= V_7 -> V_19 ) || ( V_4 > V_7 -> V_19 - V_3 ) ) ;
F_4 ( V_3 != ( V_3 >> V_13 -> V_20 ) << V_13 -> V_20 ) ;
F_4 ( V_4 > V_21 ) ;
V_14 = V_3 & V_22 ;
V_15 = F_6 ( V_3 + V_4 ) - 1 ;
V_10 = F_7 ( V_7 , V_3 , V_4 , & V_9 , V_5 ) ;
if ( V_10 || ( V_9 != V_4 ) )
return - V_12 ;
return 0 ;
}
static void F_8 ( struct V_23 * V_24 )
{
F_9 ( (struct V_25 * ) V_24 -> V_26 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
struct V_31 * V_31 ;
T_3 V_32 = V_3 >> V_33 ;
for ( V_32 = V_3 >> V_33 ; V_32 < ( V_3 + V_4 ) > > V_33 ; V_32 ++ ) {
V_31 = F_11 ( V_28 , V_32 ) ;
if ( ! V_31 )
continue;
memset ( F_12 ( V_31 ) , 0xFF , V_34 ) ;
F_13 ( V_31 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
int V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
struct V_23 V_24 ;
F_15 ( F_9 ) ;
int V_10 ;
F_4 ( V_4 % V_7 -> V_36 ) ;
if ( F_2 ( V_2 ) -> V_16 & V_17 )
return - V_18 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_7 = V_7 ;
V_24 . V_37 = V_3 ;
V_24 . V_4 = V_4 ;
V_24 . V_38 = F_8 ;
V_24 . V_26 = ( long ) & F_9 ;
V_10 = F_16 ( V_7 , & V_24 ) ;
if ( V_10 )
return - V_12 ;
F_17 ( & F_9 ) ;
if ( V_24 . V_39 != V_40 )
return - V_12 ;
return F_10 ( V_2 , V_3 , V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
F_19 ( V_7 ) ;
}
static int F_20 ( void * V_41 , struct V_31 * V_31 )
{
struct V_1 * V_2 = V_41 ;
int V_42 ;
V_42 = F_1 ( V_2 , V_31 -> V_32 << V_33 , V_34 ,
F_12 ( V_31 ) ) ;
if ( V_42 == - V_43 || V_42 == - V_44 ) {
V_42 = 0 ;
}
if ( V_42 ) {
F_21 ( V_31 ) ;
F_22 ( V_31 ) ;
} else {
F_23 ( V_31 ) ;
F_24 ( V_31 ) ;
}
F_25 ( V_31 ) ;
return V_42 ;
}
static struct V_31 * F_26 ( struct V_1 * V_2 , T_4 * V_3 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
T_5 * V_45 = F_20 ;
struct V_6 * V_7 = V_13 -> V_8 ;
* V_3 = 0 ;
while ( F_27 ( V_7 , * V_3 ) ) {
* V_3 += V_7 -> V_36 ;
if ( * V_3 >= V_7 -> V_19 )
return NULL ;
}
F_4 ( * V_3 & ~ V_46 ) ;
return F_28 ( V_28 , * V_3 >> V_33 , V_45 , V_2 ) ;
}
static struct V_31 * F_29 ( struct V_1 * V_2 , T_4 * V_3 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
T_5 * V_45 = F_20 ;
struct V_6 * V_7 = V_13 -> V_8 ;
* V_3 = V_7 -> V_19 - V_7 -> V_36 ;
while ( F_27 ( V_7 , * V_3 ) ) {
* V_3 -= V_7 -> V_36 ;
if ( * V_3 <= 0 )
return NULL ;
}
* V_3 = * V_3 + V_7 -> V_36 - 0x1000 ;
F_4 ( * V_3 & ~ V_46 ) ;
return F_28 ( V_28 , * V_3 >> V_33 , V_45 , V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_3 , T_3 V_32 ,
T_2 V_47 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
struct V_31 * V_31 ;
int V_48 , V_42 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
V_31 = F_31 ( V_28 , V_32 + V_48 ) ;
F_4 ( ! V_31 ) ;
V_42 = F_5 ( V_2 , V_31 -> V_32 << V_33 , V_34 ,
F_12 ( V_31 ) ) ;
F_25 ( V_31 ) ;
F_13 ( V_31 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , T_4 V_3 , T_2 V_4 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
int V_49 ;
if ( V_13 -> V_16 & V_17 )
return;
if ( V_4 == 0 ) {
return;
}
V_49 = V_3 & ( V_34 - 1 ) ;
if ( V_49 ) {
V_3 -= V_49 ;
V_4 += V_49 ;
}
V_4 = F_33 ( V_4 ) ;
F_30 ( V_2 , V_3 , V_3 >> V_33 , V_4 >> V_33 ) ;
}
static void F_34 ( struct F_2 * V_50 )
{
F_35 ( V_50 -> V_8 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_4 V_3 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
void * V_5 ;
int V_42 ;
V_5 = F_37 ( V_13 -> V_51 , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
V_42 = F_1 ( V_2 , V_3 , V_13 -> V_51 , V_5 ) ;
if ( V_42 )
goto V_54;
if ( F_38 ( V_5 , 0xff , V_13 -> V_51 ) )
V_42 = - V_12 ;
F_39 ( V_5 ) ;
V_54:
return V_42 ;
}
int F_40 ( struct F_2 * V_50 , int V_55 )
{
struct V_6 * V_7 = F_41 ( NULL , V_55 ) ;
if ( F_42 ( V_7 ) )
return F_43 ( V_7 ) ;
V_50 -> V_56 = NULL ;
V_50 -> V_8 = V_7 ;
V_50 -> V_57 = & V_58 ;
return 0 ;
}
