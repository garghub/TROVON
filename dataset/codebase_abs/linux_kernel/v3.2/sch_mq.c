static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned int V_7 ;
if ( ! V_6 -> V_8 )
return;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 && V_6 -> V_8 [ V_7 ] ; V_7 ++ )
F_4 ( V_6 -> V_8 [ V_7 ] ) ;
F_5 ( V_6 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_12 * V_13 ;
struct V_1 * V_14 ;
unsigned int V_7 ;
if ( V_2 -> V_15 != V_16 )
return - V_17 ;
if ( ! F_7 ( V_4 ) )
return - V_17 ;
V_6 -> V_8 = F_8 ( V_4 -> V_9 , sizeof( V_6 -> V_8 [ 0 ] ) ,
V_18 ) ;
if ( V_6 -> V_8 == NULL )
return - V_19 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_13 = F_9 ( V_4 , V_7 ) ;
V_14 = F_10 ( V_13 , & V_20 ,
F_11 ( F_12 ( V_2 -> V_21 ) ,
F_13 ( V_7 + 1 ) ) ) ;
if ( V_14 == NULL )
goto V_22;
V_6 -> V_8 [ V_7 ] = V_14 ;
}
V_2 -> V_23 |= V_24 ;
return 0 ;
V_22:
F_1 ( V_2 ) ;
return - V_19 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_14 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] ;
V_14 = F_15 ( V_14 -> V_13 , V_14 ) ;
if ( V_14 )
F_4 ( V_14 ) ;
}
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
static int F_16 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_14 ;
unsigned int V_7 ;
V_2 -> V_27 . V_28 = 0 ;
memset ( & V_2 -> V_29 , 0 , sizeof( V_2 -> V_29 ) ) ;
memset ( & V_2 -> V_30 , 0 , sizeof( V_2 -> V_30 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = F_9 ( V_4 , V_7 ) -> V_31 ;
F_17 ( F_18 ( V_14 ) ) ;
V_2 -> V_27 . V_28 += V_14 -> V_27 . V_28 ;
V_2 -> V_29 . V_32 += V_14 -> V_29 . V_32 ;
V_2 -> V_29 . V_33 += V_14 -> V_29 . V_33 ;
V_2 -> V_30 . V_28 += V_14 -> V_30 . V_28 ;
V_2 -> V_30 . V_34 += V_14 -> V_30 . V_34 ;
V_2 -> V_30 . V_35 += V_14 -> V_30 . V_35 ;
V_2 -> V_30 . V_36 += V_14 -> V_30 . V_36 ;
V_2 -> V_30 . V_37 += V_14 -> V_30 . V_37 ;
F_19 ( F_18 ( V_14 ) ) ;
}
return 0 ;
}
static struct V_12 * F_20 ( struct V_1 * V_2 , unsigned long V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_38 - 1 ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_9 ( V_4 , V_7 ) ;
}
static struct V_12 * F_21 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
unsigned int V_7 = F_13 ( V_40 -> V_41 ) ;
struct V_12 * V_13 = F_20 ( V_2 , V_7 ) ;
if ( ! V_13 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( V_4 , 0 ) ;
}
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_38 , struct V_1 * V_42 ,
struct V_1 * * V_43 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_23 & V_44 )
F_23 ( V_4 ) ;
* V_43 = F_15 ( V_13 , V_42 ) ;
if ( V_4 -> V_23 & V_44 )
F_24 ( V_4 ) ;
return 0 ;
}
static struct V_1 * F_25 ( struct V_1 * V_2 , unsigned long V_38 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_38 ) ;
return V_13 -> V_31 ;
}
static unsigned long F_26 ( struct V_1 * V_2 , T_1 V_45 )
{
unsigned int V_7 = F_13 ( V_45 ) ;
if ( ! F_20 ( V_2 , V_7 ) )
return 0 ;
return V_7 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned long V_38 )
{
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_38 ,
struct V_25 * V_26 , struct V_39 * V_40 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_38 ) ;
V_40 -> V_41 = V_16 ;
V_40 -> V_46 |= F_13 ( V_38 ) ;
V_40 -> V_47 = V_13 -> V_31 -> V_21 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_38 ,
struct V_48 * V_49 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_38 ) ;
V_2 = V_13 -> V_31 ;
V_2 -> V_30 . V_28 = V_2 -> V_27 . V_28 ;
if ( F_30 ( V_49 , & V_2 -> V_29 ) < 0 ||
F_31 ( V_49 , & V_2 -> V_30 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 ;
if ( V_51 -> V_52 )
return;
V_51 -> V_53 = V_51 -> V_54 ;
for ( V_7 = V_51 -> V_54 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
if ( V_51 -> V_55 ( V_2 , V_7 + 1 , V_51 ) < 0 ) {
V_51 -> V_52 = 1 ;
break;
}
V_51 -> V_53 ++ ;
}
}
