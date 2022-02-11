static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
unsigned long V_6 )
{
const struct V_7 * V_8 = & V_9 ;
void * V_10 ;
if ( V_6 & V_11 )
return V_8 -> V_12 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_10 = F_2 ( V_3 , V_4 ) ;
F_3 ( V_10 == NULL ) ;
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_13 , T_2 V_14 ,
unsigned long V_6 )
{
const struct V_7 * V_8 = & V_9 ;
if ( V_6 & V_11 ) {
V_8 -> free ( V_2 , V_3 , V_13 , V_14 , V_6 ) ;
} else {
int V_10 = F_5 ( F_6 ( V_3 ) ,
V_13 ) ;
F_3 ( V_10 == 0 ) ;
}
return;
}
static int F_7 ( struct V_1 * V_2 , struct V_15 * V_16 ,
void * V_13 , T_2 V_14 , T_1 V_3 ,
unsigned long V_6 )
{
int V_10 ;
if ( F_8 ( V_16 , V_13 , V_3 , & V_10 ) )
return V_10 ;
return F_9 ( V_2 , V_16 , V_13 , V_14 , V_3 ) ;
}
static void F_10 ( T_4 V_17 , T_1 V_3 ,
enum V_18 V_19 )
{
F_11 ( F_12 ( V_17 ) , V_3 , V_19 ) ;
if ( V_19 == V_20 )
F_13 ( V_17 , V_17 + V_3 ) ;
else
F_14 ( V_17 , V_17 + V_3 ) ;
}
static void F_15 ( T_4 V_17 , T_1 V_3 ,
enum V_18 V_19 )
{
if ( V_19 != V_21 ) {
F_13 ( V_17 , V_17 + V_3 ) ;
F_16 ( F_12 ( V_17 ) , V_3 , V_19 ) ;
}
}
static T_2 F_17 ( struct V_1 * V_2 , struct V_22 * V_22 ,
unsigned long V_23 , T_1 V_3 ,
enum V_18 V_19 ,
unsigned long V_6 )
{
T_2 V_24 = F_18 ( V_22 ) + V_23 ;
F_10 ( V_24 , V_3 , V_19 ) ;
return V_24 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_24 ,
T_1 V_3 , enum V_18 V_19 ,
unsigned long V_6 )
{
F_15 ( V_24 , V_3 , V_19 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , enum V_18 V_19 ,
unsigned long V_6 )
{
int V_28 ;
struct V_25 * V_29 ;
F_21 (sgl, sg, nents, i) {
F_22 ( V_29 ) = F_23 ( V_29 ) ;
F_24 ( V_29 ) = V_29 -> V_30 ;
F_10 ( F_22 ( V_29 ) , F_24 ( V_29 ) , V_19 ) ;
}
return V_27 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , enum V_18 V_19 ,
unsigned long V_6 )
{
struct V_25 * V_29 ;
int V_28 ;
F_21 (sgl, sg, nents, i)
F_15 ( F_22 ( V_29 ) , F_24 ( V_29 ) , V_19 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_2 V_24 , T_1 V_3 , enum V_18 V_19 )
{
F_10 ( V_24 , V_3 , V_19 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
T_2 V_24 , T_1 V_3 , enum V_18 V_19 )
{
F_10 ( V_24 , V_3 , V_19 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , enum V_18 V_19 )
{
struct V_25 * V_29 ;
int V_28 ;
F_21 (sgl, sg, nents, i)
F_10 ( F_22 ( V_29 ) , F_24 ( V_29 ) , V_19 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , enum V_18 V_19 )
{
struct V_25 * V_29 ;
int V_28 ;
F_21 (sgl, sg, nents, i)
F_15 ( F_22 ( V_29 ) , F_24 ( V_29 ) , V_19 ) ;
}
static const struct V_7 * F_30 ( bool V_31 )
{
return V_31 ? & V_9 : & V_32 ;
}
void F_31 ( struct V_1 * V_2 , T_5 V_33 , T_5 V_3 ,
const struct V_34 * V_35 , bool V_31 )
{
const struct V_7 * V_36 ;
if ( F_32 ( V_37 ) ) {
V_2 -> V_38 . V_39 = ( V_40 ) ? V_31 : true ;
} else {
V_2 -> V_38 . V_39 = ( F_33 () & V_41 ) ? V_31 : true ;
}
V_36 = F_30 ( V_2 -> V_38 . V_39 ) ;
F_34 ( V_2 , V_36 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
}
static int T_6 F_36 ( void )
{
F_37 ( V_42 ) ;
return 0 ;
}
