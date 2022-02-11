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
V_14 = F_10 ( V_13 , V_20 ,
F_11 ( F_12 ( V_2 -> V_21 ) ,
F_13 ( V_7 + 1 ) ) ) ;
if ( V_14 == NULL )
goto V_22;
V_6 -> V_8 [ V_7 ] = V_14 ;
V_14 -> V_23 |= V_24 | V_25 ;
}
V_2 -> V_23 |= V_26 ;
return 0 ;
V_22:
F_1 ( V_2 ) ;
return - V_19 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_14 , * V_27 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] ;
V_27 = F_15 ( V_14 -> V_13 , V_14 ) ;
if ( V_27 )
F_4 ( V_27 ) ;
#ifdef F_16
if ( V_7 < V_4 -> V_28 )
F_17 ( V_14 ) ;
#endif
}
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
static int F_18 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_14 ;
unsigned int V_7 ;
V_2 -> V_31 . V_32 = 0 ;
memset ( & V_2 -> V_33 , 0 , sizeof( V_2 -> V_33 ) ) ;
memset ( & V_2 -> V_34 , 0 , sizeof( V_2 -> V_34 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = F_9 ( V_4 , V_7 ) -> V_35 ;
F_19 ( F_20 ( V_14 ) ) ;
V_2 -> V_31 . V_32 += V_14 -> V_31 . V_32 ;
V_2 -> V_33 . V_36 += V_14 -> V_33 . V_36 ;
V_2 -> V_33 . V_37 += V_14 -> V_33 . V_37 ;
V_2 -> V_34 . V_38 += V_14 -> V_34 . V_38 ;
V_2 -> V_34 . V_39 += V_14 -> V_34 . V_39 ;
V_2 -> V_34 . V_40 += V_14 -> V_34 . V_40 ;
V_2 -> V_34 . V_41 += V_14 -> V_34 . V_41 ;
F_21 ( F_20 ( V_14 ) ) ;
}
return 0 ;
}
static struct V_12 * F_22 ( struct V_1 * V_2 , unsigned long V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_42 - 1 ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_9 ( V_4 , V_7 ) ;
}
static struct V_12 * F_23 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned int V_7 = F_13 ( V_44 -> V_45 ) ;
struct V_12 * V_13 = F_22 ( V_2 , V_7 ) ;
if ( ! V_13 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( V_4 , 0 ) ;
}
return V_13 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_42 , struct V_1 * V_46 ,
struct V_1 * * V_27 )
{
struct V_12 * V_13 = F_22 ( V_2 , V_42 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_23 & V_47 )
F_25 ( V_4 ) ;
* V_27 = F_15 ( V_13 , V_46 ) ;
if ( V_46 )
V_46 -> V_23 |= V_24 | V_25 ;
if ( V_4 -> V_23 & V_47 )
F_26 ( V_4 ) ;
return 0 ;
}
static struct V_1 * F_27 ( struct V_1 * V_2 , unsigned long V_42 )
{
struct V_12 * V_13 = F_22 ( V_2 , V_42 ) ;
return V_13 -> V_35 ;
}
static unsigned long F_28 ( struct V_1 * V_2 , T_1 V_48 )
{
unsigned int V_7 = F_13 ( V_48 ) ;
if ( ! F_22 ( V_2 , V_7 ) )
return 0 ;
return V_7 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned long V_42 )
{
}
static int F_30 ( struct V_1 * V_2 , unsigned long V_42 ,
struct V_29 * V_30 , struct V_43 * V_44 )
{
struct V_12 * V_13 = F_22 ( V_2 , V_42 ) ;
V_44 -> V_45 = V_16 ;
V_44 -> V_49 |= F_13 ( V_42 ) ;
V_44 -> V_50 = V_13 -> V_35 -> V_21 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_42 ,
struct V_51 * V_52 )
{
struct V_12 * V_13 = F_22 ( V_2 , V_42 ) ;
V_2 = V_13 -> V_35 ;
if ( F_32 ( V_52 , NULL , & V_2 -> V_33 ) < 0 ||
F_33 ( V_52 , NULL , & V_2 -> V_34 , V_2 -> V_31 . V_32 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 ;
if ( V_54 -> V_55 )
return;
V_54 -> V_56 = V_54 -> V_57 ;
for ( V_7 = V_54 -> V_57 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
if ( V_54 -> V_58 ( V_2 , V_7 + 1 , V_54 ) < 0 ) {
V_54 -> V_55 = 1 ;
break;
}
V_54 -> V_56 ++ ;
}
}
