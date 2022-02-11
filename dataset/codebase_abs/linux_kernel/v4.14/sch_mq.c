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
if ( ! V_6 -> V_8 )
return - V_19 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_13 = F_9 ( V_4 , V_7 ) ;
V_14 = F_10 ( V_13 , F_11 ( V_4 , V_7 ) ,
F_12 ( F_13 ( V_2 -> V_20 ) ,
F_14 ( V_7 + 1 ) ) ) ;
if ( ! V_14 )
return - V_19 ;
V_6 -> V_8 [ V_7 ] = V_14 ;
V_14 -> V_21 |= V_22 | V_23 ;
}
V_2 -> V_21 |= V_24 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_14 , * V_25 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] ;
V_25 = F_16 ( V_14 -> V_13 , V_14 ) ;
if ( V_25 )
F_4 ( V_25 ) ;
#ifdef F_17
if ( V_7 < V_4 -> V_26 )
F_18 ( V_14 , false ) ;
#endif
}
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
static int F_19 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_14 ;
unsigned int V_7 ;
V_2 -> V_29 . V_30 = 0 ;
memset ( & V_2 -> V_31 , 0 , sizeof( V_2 -> V_31 ) ) ;
memset ( & V_2 -> V_32 , 0 , sizeof( V_2 -> V_32 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = F_9 ( V_4 , V_7 ) -> V_33 ;
F_20 ( F_21 ( V_14 ) ) ;
V_2 -> V_29 . V_30 += V_14 -> V_29 . V_30 ;
V_2 -> V_31 . V_34 += V_14 -> V_31 . V_34 ;
V_2 -> V_31 . V_35 += V_14 -> V_31 . V_35 ;
V_2 -> V_32 . V_36 += V_14 -> V_32 . V_36 ;
V_2 -> V_32 . V_37 += V_14 -> V_32 . V_37 ;
V_2 -> V_32 . V_38 += V_14 -> V_32 . V_38 ;
V_2 -> V_32 . V_39 += V_14 -> V_32 . V_39 ;
F_22 ( F_21 ( V_14 ) ) ;
}
return 0 ;
}
static struct V_12 * F_23 ( struct V_1 * V_2 , unsigned long V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_40 - 1 ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_9 ( V_4 , V_7 ) ;
}
static struct V_12 * F_24 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
unsigned int V_7 = F_14 ( V_42 -> V_43 ) ;
struct V_12 * V_13 = F_23 ( V_2 , V_7 ) ;
if ( ! V_13 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( V_4 , 0 ) ;
}
return V_13 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_40 , struct V_1 * V_44 ,
struct V_1 * * V_25 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_40 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_21 & V_45 )
F_26 ( V_4 ) ;
* V_25 = F_16 ( V_13 , V_44 ) ;
if ( V_44 )
V_44 -> V_21 |= V_22 | V_23 ;
if ( V_4 -> V_21 & V_45 )
F_27 ( V_4 ) ;
return 0 ;
}
static struct V_1 * F_28 ( struct V_1 * V_2 , unsigned long V_40 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_40 ) ;
return V_13 -> V_33 ;
}
static unsigned long F_29 ( struct V_1 * V_2 , T_1 V_46 )
{
unsigned int V_7 = F_14 ( V_46 ) ;
if ( ! F_23 ( V_2 , V_7 ) )
return 0 ;
return V_7 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned long V_40 ,
struct V_27 * V_28 , struct V_41 * V_42 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_40 ) ;
V_42 -> V_43 = V_16 ;
V_42 -> V_47 |= F_14 ( V_40 ) ;
V_42 -> V_48 = V_13 -> V_33 -> V_20 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_40 ,
struct V_49 * V_50 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_40 ) ;
V_2 = V_13 -> V_33 ;
if ( F_32 ( & V_2 -> V_51 , V_50 , NULL , & V_2 -> V_31 ) < 0 ||
F_33 ( V_50 , NULL , & V_2 -> V_32 , V_2 -> V_29 . V_30 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 ;
if ( V_53 -> V_54 )
return;
V_53 -> V_55 = V_53 -> V_56 ;
for ( V_7 = V_53 -> V_56 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
if ( V_53 -> V_57 ( V_2 , V_7 + 1 , V_53 ) < 0 ) {
V_53 -> V_54 = 1 ;
break;
}
V_53 -> V_55 ++ ;
}
}
