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
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
V_14 -> V_29 [ V_16 ] = F_12 ( V_11 -> V_25 , V_16 ) ;
if ( V_16 < V_27 )
V_14 -> V_29 [ V_16 ] = V_30 ;
return & V_14 -> V_21 ;
}
static void
F_13 ( struct V_13 * V_13 )
{
F_2 ( L_4 , V_13 ) ;
F_14 ( V_13 ) ;
}
static void
F_15 ( struct V_31 * V_32 )
{
struct V_13 * V_13 = F_16 ( V_32 , struct V_13 , V_21 . V_33 ) ;
F_13 ( V_13 ) ;
}
static void
F_17 ( struct V_9 * V_14 )
{
F_18 ( & V_14 -> V_33 , F_15 ) ;
}
static int
F_19 ( struct V_10 * V_11 , struct V_9 * V_34 , int V_12 )
{
struct V_13 * V_14 = F_16 ( V_34 , struct V_13 , V_21 ) ;
unsigned int V_15 = 0 ;
unsigned int V_16 ;
if ( V_14 -> V_35 != V_11 -> V_17 || V_14 -> V_28 != V_11 -> V_18 )
return 0 ;
if ( V_11 -> V_25 != NULL )
V_15 = V_11 -> V_25 -> V_26 ;
if ( V_15 > V_27 )
V_15 = V_27 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
if ( V_14 -> V_29 [ V_16 ] != F_12 ( V_11 -> V_25 , V_16 ) )
return 0 ;
if ( V_15 < V_27 &&
V_14 -> V_29 [ V_15 ] != V_30 )
return 0 ;
return 1 ;
}
static T_2 *
F_20 ( struct V_36 * V_37 , T_2 * V_38 )
{
struct V_2 * V_3 = V_37 -> V_39 ;
struct V_13 * V_14 = F_16 ( V_37 -> V_40 -> V_41 , struct V_13 , V_21 ) ;
T_2 * V_42 , * V_43 ;
int V_16 ;
* V_38 ++ = F_21 ( V_44 ) ;
V_42 = V_38 ++ ;
* V_38 ++ = F_21 ( V_45 / V_46 ) ;
V_38 = F_22 ( V_38 , V_3 -> V_47 , V_3 -> V_48 ) ;
* V_38 ++ = F_21 ( ( V_49 ) V_14 -> V_35 ) ;
* V_38 ++ = F_21 ( ( V_49 ) V_14 -> V_28 ) ;
V_43 = V_38 ++ ;
for ( V_16 = 0 ; V_16 < 16 && V_14 -> V_29 [ V_16 ] != ( V_50 ) V_30 ; V_16 ++ )
* V_38 ++ = F_21 ( ( V_49 ) V_14 -> V_29 [ V_16 ] ) ;
* V_43 = F_21 ( V_38 - V_43 - 1 ) ;
* V_42 = F_21 ( ( V_38 - V_42 - 1 ) << 2 ) ;
* V_38 ++ = F_21 ( V_51 ) ;
* V_38 ++ = F_21 ( 0 ) ;
return V_38 ;
}
static int
F_23 ( struct V_36 * V_37 )
{
F_24 ( V_24 , & V_37 -> V_40 -> V_41 -> V_23 ) ;
return 0 ;
}
static T_2 *
F_25 ( struct V_36 * V_37 , T_2 * V_38 )
{
T_1 V_4 ;
V_49 V_52 ;
V_4 = F_26 ( * V_38 ++ ) ;
if ( V_4 != V_51 &&
V_4 != V_44 &&
V_4 != V_53 ) {
F_27 ( L_5 , V_4 ) ;
return NULL ;
}
V_52 = F_26 ( * V_38 ++ ) ;
if ( V_52 > V_54 ) {
F_27 ( L_6 , V_52 ) ;
return NULL ;
}
V_37 -> V_40 -> V_41 -> V_55 -> V_56 = ( V_52 >> 2 ) + 2 ;
V_38 += ( V_52 >> 2 ) ;
return V_38 ;
}
int T_3 F_28 ( void )
{
return F_29 ( & V_5 ) ;
}
void F_30 ( void )
{
F_31 ( & V_5 ) ;
}
