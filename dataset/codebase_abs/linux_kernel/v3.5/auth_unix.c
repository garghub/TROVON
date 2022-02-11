static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
F_2 ( L_1 ,
V_3 ) ;
F_3 ( & V_5 . V_6 ) ;
return & V_5 ;
}
static void
F_4 ( struct V_1 * V_7 )
{
F_2 ( L_2 , V_7 ) ;
F_5 ( V_7 -> V_8 ) ;
}
static struct V_9 *
F_6 ( struct V_1 * V_7 , struct V_10 * V_11 , int V_12 )
{
return F_7 ( V_7 , V_11 , V_12 ) ;
}
static struct V_9 *
F_8 ( struct V_1 * V_7 , struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 ;
unsigned int V_15 = 0 ;
unsigned int V_16 ;
F_2 ( L_3 ,
V_11 -> V_17 , V_11 -> V_18 ) ;
if ( ! ( V_14 = F_9 ( sizeof( * V_14 ) , V_19 ) ) )
return F_10 ( - V_20 ) ;
F_11 ( & V_14 -> V_21 , V_11 , V_7 , & V_22 ) ;
V_14 -> V_21 . V_23 = 1UL << V_24 ;
if ( V_11 -> V_25 != NULL )
V_15 = V_11 -> V_25 -> V_26 ;
if ( V_15 > V_27 )
V_15 = V_27 ;
V_14 -> V_28 = V_11 -> V_18 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
T_2 V_18 ;
V_18 = F_12 ( & V_29 , F_13 ( V_11 -> V_25 , V_16 ) ) ;
V_14 -> V_30 [ V_16 ] = V_18 ;
}
if ( V_16 < V_27 )
V_14 -> V_30 [ V_16 ] = V_31 ;
return & V_14 -> V_21 ;
}
static void
F_14 ( struct V_13 * V_13 )
{
F_2 ( L_4 , V_13 ) ;
F_15 ( V_13 ) ;
}
static void
F_16 ( struct V_32 * V_33 )
{
struct V_13 * V_13 = F_17 ( V_33 , struct V_13 , V_21 . V_34 ) ;
F_14 ( V_13 ) ;
}
static void
F_18 ( struct V_9 * V_14 )
{
F_19 ( & V_14 -> V_34 , F_16 ) ;
}
static int
F_20 ( struct V_10 * V_11 , struct V_9 * V_35 , int V_12 )
{
struct V_13 * V_14 = F_17 ( V_35 , struct V_13 , V_21 ) ;
unsigned int V_15 = 0 ;
unsigned int V_16 ;
if ( V_14 -> V_36 != V_11 -> V_17 || V_14 -> V_28 != V_11 -> V_18 )
return 0 ;
if ( V_11 -> V_25 != NULL )
V_15 = V_11 -> V_25 -> V_26 ;
if ( V_15 > V_27 )
V_15 = V_27 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
T_2 V_18 ;
V_18 = F_12 ( & V_29 , F_13 ( V_11 -> V_25 , V_16 ) ) ;
if ( V_14 -> V_30 [ V_16 ] != V_18 )
return 0 ;
}
if ( V_15 < V_27 &&
V_14 -> V_30 [ V_15 ] != V_31 )
return 0 ;
return 1 ;
}
static T_3 *
F_21 ( struct V_37 * V_38 , T_3 * V_39 )
{
struct V_2 * V_3 = V_38 -> V_40 ;
struct V_13 * V_14 = F_17 ( V_38 -> V_41 -> V_42 , struct V_13 , V_21 ) ;
T_3 * V_43 , * V_44 ;
int V_16 ;
* V_39 ++ = F_22 ( V_45 ) ;
V_43 = V_39 ++ ;
* V_39 ++ = F_22 ( V_46 / V_47 ) ;
V_39 = F_23 ( V_39 , V_3 -> V_48 , V_3 -> V_49 ) ;
* V_39 ++ = F_22 ( ( V_50 ) V_14 -> V_36 ) ;
* V_39 ++ = F_22 ( ( V_50 ) V_14 -> V_28 ) ;
V_44 = V_39 ++ ;
for ( V_16 = 0 ; V_16 < 16 && V_14 -> V_30 [ V_16 ] != ( T_2 ) V_31 ; V_16 ++ )
* V_39 ++ = F_22 ( ( V_50 ) V_14 -> V_30 [ V_16 ] ) ;
* V_44 = F_22 ( V_39 - V_44 - 1 ) ;
* V_43 = F_22 ( ( V_39 - V_43 - 1 ) << 2 ) ;
* V_39 ++ = F_22 ( V_51 ) ;
* V_39 ++ = F_22 ( 0 ) ;
return V_39 ;
}
static int
F_24 ( struct V_37 * V_38 )
{
F_25 ( V_24 , & V_38 -> V_41 -> V_42 -> V_23 ) ;
return 0 ;
}
static T_3 *
F_26 ( struct V_37 * V_38 , T_3 * V_39 )
{
T_1 V_4 ;
V_50 V_52 ;
V_4 = F_27 ( * V_39 ++ ) ;
if ( V_4 != V_51 &&
V_4 != V_45 &&
V_4 != V_53 ) {
F_28 ( L_5 , V_4 ) ;
return NULL ;
}
V_52 = F_27 ( * V_39 ++ ) ;
if ( V_52 > V_54 ) {
F_28 ( L_6 , V_52 ) ;
return NULL ;
}
V_38 -> V_41 -> V_42 -> V_55 -> V_56 = ( V_52 >> 2 ) + 2 ;
V_39 += ( V_52 >> 2 ) ;
return V_39 ;
}
int T_4 F_29 ( void )
{
return F_30 ( & V_5 ) ;
}
void F_31 ( void )
{
F_32 ( & V_5 ) ;
}
