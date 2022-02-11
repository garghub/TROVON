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
V_14 -> V_23 |= V_24 ;
}
V_2 -> V_23 |= V_25 ;
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
static int F_16 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_14 ;
unsigned int V_7 ;
V_2 -> V_28 . V_29 = 0 ;
memset ( & V_2 -> V_30 , 0 , sizeof( V_2 -> V_30 ) ) ;
memset ( & V_2 -> V_31 , 0 , sizeof( V_2 -> V_31 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = F_9 ( V_4 , V_7 ) -> V_32 ;
F_17 ( F_18 ( V_14 ) ) ;
V_2 -> V_28 . V_29 += V_14 -> V_28 . V_29 ;
V_2 -> V_30 . V_33 += V_14 -> V_30 . V_33 ;
V_2 -> V_30 . V_34 += V_14 -> V_30 . V_34 ;
V_2 -> V_31 . V_29 += V_14 -> V_31 . V_29 ;
V_2 -> V_31 . V_35 += V_14 -> V_31 . V_35 ;
V_2 -> V_31 . V_36 += V_14 -> V_31 . V_36 ;
V_2 -> V_31 . V_37 += V_14 -> V_31 . V_37 ;
V_2 -> V_31 . V_38 += V_14 -> V_31 . V_38 ;
F_19 ( F_18 ( V_14 ) ) ;
}
return 0 ;
}
static struct V_12 * F_20 ( struct V_1 * V_2 , unsigned long V_39 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_39 - 1 ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_9 ( V_4 , V_7 ) ;
}
static struct V_12 * F_21 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
unsigned int V_7 = F_13 ( V_41 -> V_42 ) ;
struct V_12 * V_13 = F_20 ( V_2 , V_7 ) ;
if ( ! V_13 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( V_4 , 0 ) ;
}
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_39 , struct V_1 * V_43 ,
struct V_1 * * V_44 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_23 & V_45 )
F_23 ( V_4 ) ;
* V_44 = F_15 ( V_13 , V_43 ) ;
if ( V_43 )
V_43 -> V_23 |= V_24 ;
if ( V_4 -> V_23 & V_45 )
F_24 ( V_4 ) ;
return 0 ;
}
static struct V_1 * F_25 ( struct V_1 * V_2 , unsigned long V_39 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_39 ) ;
return V_13 -> V_32 ;
}
static unsigned long F_26 ( struct V_1 * V_2 , T_1 V_46 )
{
unsigned int V_7 = F_13 ( V_46 ) ;
if ( ! F_20 ( V_2 , V_7 ) )
return 0 ;
return V_7 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned long V_39 )
{
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_39 ,
struct V_26 * V_27 , struct V_40 * V_41 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_39 ) ;
V_41 -> V_42 = V_16 ;
V_41 -> V_47 |= F_13 ( V_39 ) ;
V_41 -> V_48 = V_13 -> V_32 -> V_21 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_39 ,
struct V_49 * V_50 )
{
struct V_12 * V_13 = F_20 ( V_2 , V_39 ) ;
V_2 = V_13 -> V_32 ;
V_2 -> V_31 . V_29 = V_2 -> V_28 . V_29 ;
if ( F_30 ( V_50 , & V_2 -> V_30 ) < 0 ||
F_31 ( V_50 , & V_2 -> V_31 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 ;
if ( V_52 -> V_53 )
return;
V_52 -> V_54 = V_52 -> V_55 ;
for ( V_7 = V_52 -> V_55 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
if ( V_52 -> V_56 ( V_2 , V_7 + 1 , V_52 ) < 0 ) {
V_52 -> V_53 = 1 ;
break;
}
V_52 -> V_54 ++ ;
}
}
