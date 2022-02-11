static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
T_2 V_9 ;
int V_10 ;
V_10 = V_7 -> V_11 ( V_7 , V_3 , V_4 , & V_9 , V_5 ) ;
F_3 ( V_10 == - V_12 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 != V_4 )
return - V_13 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_14 -> V_8 ;
T_2 V_9 ;
T_1 V_15 , V_16 ;
int V_10 ;
if ( V_14 -> V_17 & V_18 )
return - V_19 ;
F_3 ( ( V_3 >= V_7 -> V_20 ) || ( V_4 > V_7 -> V_20 - V_3 ) ) ;
F_3 ( V_3 != ( V_3 >> V_14 -> V_21 ) << V_14 -> V_21 ) ;
F_3 ( V_4 > V_22 ) ;
V_15 = V_3 & V_23 ;
V_16 = F_5 ( V_3 + V_4 ) - 1 ;
V_10 = V_7 -> V_24 ( V_7 , V_3 , V_4 , & V_9 , V_5 ) ;
if ( V_10 || ( V_9 != V_4 ) )
return - V_13 ;
return 0 ;
}
static void F_6 ( struct V_25 * V_26 )
{
F_7 ( (struct V_27 * ) V_26 -> V_28 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_14 -> V_31 -> V_32 ;
struct V_33 * V_33 ;
T_3 V_34 = V_3 >> V_35 ;
for ( V_34 = V_3 >> V_35 ; V_34 < ( V_3 + V_4 ) > > V_35 ; V_34 ++ ) {
V_33 = F_9 ( V_30 , V_34 ) ;
if ( ! V_33 )
continue;
memset ( F_10 ( V_33 ) , 0xFF , V_36 ) ;
F_11 ( V_33 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
int V_37 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
struct V_25 V_26 ;
F_13 ( F_7 ) ;
int V_10 ;
F_3 ( V_4 % V_7 -> V_38 ) ;
if ( F_2 ( V_2 ) -> V_17 & V_18 )
return - V_19 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_7 = V_7 ;
V_26 . V_39 = V_3 ;
V_26 . V_4 = V_4 ;
V_26 . V_40 = F_6 ;
V_26 . V_28 = ( long ) & F_7 ;
V_10 = V_7 -> V_41 ( V_7 , & V_26 ) ;
if ( V_10 )
return - V_13 ;
F_14 ( & F_7 ) ;
if ( V_26 . V_42 != V_43 )
return - V_13 ;
return F_8 ( V_2 , V_3 , V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_8 ;
if ( V_7 -> V_44 )
V_7 -> V_44 ( V_7 ) ;
}
static int F_16 ( void * V_45 , struct V_33 * V_33 )
{
struct V_1 * V_2 = V_45 ;
int V_46 ;
V_46 = F_1 ( V_2 , V_33 -> V_34 << V_35 , V_36 ,
F_10 ( V_33 ) ) ;
if ( V_46 == - V_47 || V_46 == - V_48 ) {
V_46 = 0 ;
}
if ( V_46 ) {
F_17 ( V_33 ) ;
F_18 ( V_33 ) ;
} else {
F_19 ( V_33 ) ;
F_20 ( V_33 ) ;
}
F_21 ( V_33 ) ;
return V_46 ;
}
static struct V_33 * F_22 ( struct V_1 * V_2 , T_4 * V_3 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_14 -> V_31 -> V_32 ;
T_5 * V_49 = F_16 ;
struct V_6 * V_7 = V_14 -> V_8 ;
if ( ! V_7 -> V_50 )
return NULL ;
* V_3 = 0 ;
while ( V_7 -> V_50 ( V_7 , * V_3 ) ) {
* V_3 += V_7 -> V_38 ;
if ( * V_3 >= V_7 -> V_20 )
return NULL ;
}
F_3 ( * V_3 & ~ V_51 ) ;
return F_23 ( V_30 , * V_3 >> V_35 , V_49 , V_2 ) ;
}
static struct V_33 * F_24 ( struct V_1 * V_2 , T_4 * V_3 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_14 -> V_31 -> V_32 ;
T_5 * V_49 = F_16 ;
struct V_6 * V_7 = V_14 -> V_8 ;
if ( ! V_7 -> V_50 )
return NULL ;
* V_3 = V_7 -> V_20 - V_7 -> V_38 ;
while ( V_7 -> V_50 ( V_7 , * V_3 ) ) {
* V_3 -= V_7 -> V_38 ;
if ( * V_3 <= 0 )
return NULL ;
}
* V_3 = * V_3 + V_7 -> V_38 - 0x1000 ;
F_3 ( * V_3 & ~ V_51 ) ;
return F_23 ( V_30 , * V_3 >> V_35 , V_49 , V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_4 V_3 , T_3 V_34 ,
T_2 V_52 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_14 -> V_31 -> V_32 ;
struct V_33 * V_33 ;
int V_53 , V_46 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_33 = F_26 ( V_30 , V_34 + V_53 ) ;
F_3 ( ! V_33 ) ;
V_46 = F_4 ( V_2 , V_33 -> V_34 << V_35 , V_36 ,
F_10 ( V_33 ) ) ;
F_21 ( V_33 ) ;
F_11 ( V_33 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , T_4 V_3 , T_2 V_4 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
int V_54 ;
if ( V_14 -> V_17 & V_18 )
return;
if ( V_4 == 0 ) {
return;
}
V_54 = V_3 & ( V_36 - 1 ) ;
if ( V_54 ) {
V_3 -= V_54 ;
V_4 += V_54 ;
}
V_4 = F_28 ( V_4 ) ;
F_25 ( V_2 , V_3 , V_3 >> V_35 , V_4 >> V_35 ) ;
}
static void F_29 ( struct F_2 * V_55 )
{
F_30 ( V_55 -> V_8 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_4 V_3 )
{
struct F_2 * V_14 = F_2 ( V_2 ) ;
void * V_5 ;
int V_46 ;
V_5 = F_32 ( V_14 -> V_56 , V_57 ) ;
if ( ! V_5 )
return - V_58 ;
V_46 = F_1 ( V_2 , V_3 , V_14 -> V_56 , V_5 ) ;
if ( V_46 )
goto V_59;
if ( F_33 ( V_5 , 0xff , V_14 -> V_56 ) )
V_46 = - V_13 ;
F_34 ( V_5 ) ;
V_59:
return V_46 ;
}
int F_35 ( struct F_2 * V_55 , int V_60 )
{
struct V_6 * V_7 = F_36 ( NULL , V_60 ) ;
if ( F_37 ( V_7 ) )
return F_38 ( V_7 ) ;
V_55 -> V_61 = NULL ;
V_55 -> V_8 = V_7 ;
V_55 -> V_62 = & V_63 ;
return 0 ;
}
