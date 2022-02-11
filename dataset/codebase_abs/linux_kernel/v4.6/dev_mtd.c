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
memset ( F_12 ( V_31 ) , 0xFF , V_21 ) ;
F_13 ( V_31 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
int V_34 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
struct V_23 V_24 ;
F_15 ( F_9 ) ;
int V_10 ;
F_4 ( V_4 % V_7 -> V_35 ) ;
if ( F_2 ( V_2 ) -> V_16 & V_17 )
return - V_18 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_7 = V_7 ;
V_24 . V_36 = V_3 ;
V_24 . V_4 = V_4 ;
V_24 . V_37 = F_8 ;
V_24 . V_26 = ( long ) & F_9 ;
V_10 = F_16 ( V_7 , & V_24 ) ;
if ( V_10 )
return - V_12 ;
F_17 ( & F_9 ) ;
if ( V_24 . V_38 != V_39 )
return - V_12 ;
return F_10 ( V_2 , V_3 , V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
F_19 ( V_7 ) ;
}
static int F_20 ( void * V_40 , struct V_31 * V_31 )
{
struct V_1 * V_2 = V_40 ;
int V_41 ;
V_41 = F_1 ( V_2 , V_31 -> V_32 << V_33 , V_21 ,
F_12 ( V_31 ) ) ;
if ( V_41 == - V_42 || V_41 == - V_43 ) {
V_41 = 0 ;
}
if ( V_41 ) {
F_21 ( V_31 ) ;
F_22 ( V_31 ) ;
} else {
F_23 ( V_31 ) ;
F_24 ( V_31 ) ;
}
F_25 ( V_31 ) ;
return V_41 ;
}
static struct V_31 * F_26 ( struct V_1 * V_2 , T_4 * V_3 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
T_5 * V_44 = F_20 ;
struct V_6 * V_7 = V_13 -> V_8 ;
* V_3 = 0 ;
while ( F_27 ( V_7 , * V_3 ) ) {
* V_3 += V_7 -> V_35 ;
if ( * V_3 >= V_7 -> V_19 )
return NULL ;
}
F_4 ( * V_3 & ~ V_22 ) ;
return F_28 ( V_28 , * V_3 >> V_33 , V_44 , V_2 ) ;
}
static struct V_31 * F_29 ( struct V_1 * V_2 , T_4 * V_3 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
T_5 * V_44 = F_20 ;
struct V_6 * V_7 = V_13 -> V_8 ;
* V_3 = V_7 -> V_19 - V_7 -> V_35 ;
while ( F_27 ( V_7 , * V_3 ) ) {
* V_3 -= V_7 -> V_35 ;
if ( * V_3 <= 0 )
return NULL ;
}
* V_3 = * V_3 + V_7 -> V_35 - 0x1000 ;
F_4 ( * V_3 & ~ V_22 ) ;
return F_28 ( V_28 , * V_3 >> V_33 , V_44 , V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_3 , T_3 V_32 ,
T_2 V_45 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 ;
struct V_31 * V_31 ;
int V_46 , V_41 ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
V_31 = F_31 ( V_28 , V_32 + V_46 ) ;
F_4 ( ! V_31 ) ;
V_41 = F_5 ( V_2 , V_31 -> V_32 << V_33 , V_21 ,
F_12 ( V_31 ) ) ;
F_25 ( V_31 ) ;
F_13 ( V_31 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , T_4 V_3 , T_2 V_4 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
int V_47 ;
if ( V_13 -> V_16 & V_17 )
return;
if ( V_4 == 0 ) {
return;
}
V_47 = V_3 & ( V_21 - 1 ) ;
if ( V_47 ) {
V_3 -= V_47 ;
V_4 += V_47 ;
}
V_4 = F_6 ( V_4 ) ;
F_30 ( V_2 , V_3 , V_3 >> V_33 , V_4 >> V_33 ) ;
}
static void F_33 ( struct F_2 * V_48 )
{
F_34 ( V_48 -> V_8 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_4 V_3 )
{
struct F_2 * V_13 = F_2 ( V_2 ) ;
void * V_5 ;
int V_41 ;
V_5 = F_36 ( V_13 -> V_49 , V_50 ) ;
if ( ! V_5 )
return - V_51 ;
V_41 = F_1 ( V_2 , V_3 , V_13 -> V_49 , V_5 ) ;
if ( V_41 )
goto V_52;
if ( F_37 ( V_5 , 0xff , V_13 -> V_49 ) )
V_41 = - V_12 ;
F_38 ( V_5 ) ;
V_52:
return V_41 ;
}
int F_39 ( struct F_2 * V_48 , int V_53 )
{
struct V_6 * V_7 = F_40 ( NULL , V_53 ) ;
if ( F_41 ( V_7 ) )
return F_42 ( V_7 ) ;
V_48 -> V_54 = NULL ;
V_48 -> V_8 = V_7 ;
V_48 -> V_55 = & V_56 ;
return 0 ;
}
