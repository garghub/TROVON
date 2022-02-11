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
V_14 = F_10 ( V_13 , F_11 ( V_4 , V_7 ) ,
F_12 ( F_13 ( V_2 -> V_20 ) ,
F_14 ( V_7 + 1 ) ) ) ;
if ( V_14 == NULL )
goto V_21;
V_6 -> V_8 [ V_7 ] = V_14 ;
V_14 -> V_22 |= V_23 | V_24 ;
}
V_2 -> V_22 |= V_25 ;
return 0 ;
V_21:
F_1 ( V_2 ) ;
return - V_19 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_14 , * V_26 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] ;
V_26 = F_16 ( V_14 -> V_13 , V_14 ) ;
if ( V_26 )
F_4 ( V_26 ) ;
#ifdef F_17
if ( V_7 < V_4 -> V_27 )
F_18 ( V_14 ) ;
#endif
}
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
static int F_19 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_14 ;
unsigned int V_7 ;
V_2 -> V_30 . V_31 = 0 ;
memset ( & V_2 -> V_32 , 0 , sizeof( V_2 -> V_32 ) ) ;
memset ( & V_2 -> V_33 , 0 , sizeof( V_2 -> V_33 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_14 = F_9 ( V_4 , V_7 ) -> V_34 ;
F_20 ( F_21 ( V_14 ) ) ;
V_2 -> V_30 . V_31 += V_14 -> V_30 . V_31 ;
V_2 -> V_32 . V_35 += V_14 -> V_32 . V_35 ;
V_2 -> V_32 . V_36 += V_14 -> V_32 . V_36 ;
V_2 -> V_33 . V_37 += V_14 -> V_33 . V_37 ;
V_2 -> V_33 . V_38 += V_14 -> V_33 . V_38 ;
V_2 -> V_33 . V_39 += V_14 -> V_33 . V_39 ;
V_2 -> V_33 . V_40 += V_14 -> V_33 . V_40 ;
F_22 ( F_21 ( V_14 ) ) ;
}
return 0 ;
}
static struct V_12 * F_23 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_41 - 1 ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_9 ( V_4 , V_7 ) ;
}
static struct V_12 * F_24 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
unsigned int V_7 = F_14 ( V_43 -> V_44 ) ;
struct V_12 * V_13 = F_23 ( V_2 , V_7 ) ;
if ( ! V_13 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( V_4 , 0 ) ;
}
return V_13 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_41 , struct V_1 * V_45 ,
struct V_1 * * V_26 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_41 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_22 & V_46 )
F_26 ( V_4 ) ;
* V_26 = F_16 ( V_13 , V_45 ) ;
if ( V_45 )
V_45 -> V_22 |= V_23 | V_24 ;
if ( V_4 -> V_22 & V_46 )
F_27 ( V_4 ) ;
return 0 ;
}
static struct V_1 * F_28 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_41 ) ;
return V_13 -> V_34 ;
}
static unsigned long F_29 ( struct V_1 * V_2 , T_1 V_47 )
{
unsigned int V_7 = F_14 ( V_47 ) ;
if ( ! F_23 ( V_2 , V_7 ) )
return 0 ;
return V_7 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned long V_41 )
{
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_41 ,
struct V_28 * V_29 , struct V_42 * V_43 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_41 ) ;
V_43 -> V_44 = V_16 ;
V_43 -> V_48 |= F_14 ( V_41 ) ;
V_43 -> V_49 = V_13 -> V_34 -> V_20 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned long V_41 ,
struct V_50 * V_51 )
{
struct V_12 * V_13 = F_23 ( V_2 , V_41 ) ;
V_2 = V_13 -> V_34 ;
if ( F_33 ( & V_2 -> V_52 , V_51 , NULL , & V_2 -> V_32 ) < 0 ||
F_34 ( V_51 , NULL , & V_2 -> V_33 , V_2 -> V_30 . V_31 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_53 * V_54 )
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
