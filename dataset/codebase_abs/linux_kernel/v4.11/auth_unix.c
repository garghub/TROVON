static struct V_1 *
F_1 ( struct V_2 * args , struct V_3 * V_4 )
{
F_2 ( L_1 ,
V_4 ) ;
F_3 ( & V_5 . V_6 ) ;
return & V_5 ;
}
static void
F_4 ( struct V_1 * V_7 )
{
F_2 ( L_2 , V_7 ) ;
F_5 ( V_7 -> V_8 ) ;
}
static int
F_6 ( struct V_9 * V_10 , unsigned int V_11 )
{
return F_7 ( F_8 ( & V_12 , V_10 -> V_13 ) |
( ( V_14 ) F_9 ( & V_12 , V_10 -> V_15 ) <<
( sizeof( V_16 ) * 8 ) ) , V_11 ) ;
}
static struct V_17 *
F_10 ( struct V_1 * V_7 , struct V_9 * V_10 , int V_18 )
{
return F_11 ( V_7 , V_10 , V_18 , V_19 ) ;
}
static struct V_17 *
F_12 ( struct V_1 * V_7 , struct V_9 * V_10 , int V_18 , T_1 V_20 )
{
struct V_21 * V_22 ;
unsigned int V_23 = 0 ;
unsigned int V_24 ;
F_2 ( L_3 ,
F_9 ( & V_12 , V_10 -> V_15 ) ,
F_8 ( & V_12 , V_10 -> V_13 ) ) ;
if ( ! ( V_22 = F_13 ( sizeof( * V_22 ) , V_20 ) ) )
return F_14 ( - V_25 ) ;
F_15 ( & V_22 -> V_26 , V_10 , V_7 , & V_27 ) ;
V_22 -> V_26 . V_28 = 1UL << V_29 ;
if ( V_10 -> V_30 != NULL )
V_23 = V_10 -> V_30 -> V_31 ;
if ( V_23 > V_32 )
V_23 = V_32 ;
V_22 -> V_33 = V_10 -> V_13 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ )
V_22 -> V_34 [ V_24 ] = V_10 -> V_30 -> V_13 [ V_24 ] ;
if ( V_24 < V_32 )
V_22 -> V_34 [ V_24 ] = V_35 ;
return & V_22 -> V_26 ;
}
static void
F_16 ( struct V_21 * V_21 )
{
F_2 ( L_4 , V_21 ) ;
F_17 ( V_21 ) ;
}
static void
F_18 ( struct V_36 * V_37 )
{
struct V_21 * V_21 = F_19 ( V_37 , struct V_21 , V_26 . V_38 ) ;
F_16 ( V_21 ) ;
}
static void
F_20 ( struct V_17 * V_22 )
{
F_21 ( & V_22 -> V_38 , F_18 ) ;
}
static int
F_22 ( struct V_9 * V_10 , struct V_17 * V_39 , int V_18 )
{
struct V_21 * V_22 = F_19 ( V_39 , struct V_21 , V_26 ) ;
unsigned int V_23 = 0 ;
unsigned int V_24 ;
if ( ! F_23 ( V_22 -> V_40 , V_10 -> V_15 ) || ! F_24 ( V_22 -> V_33 , V_10 -> V_13 ) )
return 0 ;
if ( V_10 -> V_30 != NULL )
V_23 = V_10 -> V_30 -> V_31 ;
if ( V_23 > V_32 )
V_23 = V_32 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ )
if ( ! F_24 ( V_22 -> V_34 [ V_24 ] , V_10 -> V_30 -> V_13 [ V_24 ] ) )
return 0 ;
if ( V_23 < V_32 && F_25 ( V_22 -> V_34 [ V_23 ] ) )
return 0 ;
return 1 ;
}
static T_2 *
F_26 ( struct V_41 * V_42 , T_2 * V_43 )
{
struct V_3 * V_4 = V_42 -> V_44 ;
struct V_21 * V_22 = F_19 ( V_42 -> V_45 -> V_46 , struct V_21 , V_26 ) ;
T_2 * V_47 , * V_48 ;
int V_24 ;
* V_43 ++ = F_27 ( V_49 ) ;
V_47 = V_43 ++ ;
* V_43 ++ = F_27 ( V_50 / V_51 ) ;
V_43 = F_28 ( V_43 , V_4 -> V_52 , V_4 -> V_53 ) ;
* V_43 ++ = F_27 ( ( V_54 ) F_9 ( & V_12 , V_22 -> V_40 ) ) ;
* V_43 ++ = F_27 ( ( V_54 ) F_8 ( & V_12 , V_22 -> V_33 ) ) ;
V_48 = V_43 ++ ;
for ( V_24 = 0 ; V_24 < V_32 && F_25 ( V_22 -> V_34 [ V_24 ] ) ; V_24 ++ )
* V_43 ++ = F_27 ( ( V_54 ) F_8 ( & V_12 , V_22 -> V_34 [ V_24 ] ) ) ;
* V_48 = F_27 ( V_43 - V_48 - 1 ) ;
* V_47 = F_27 ( ( V_43 - V_47 - 1 ) << 2 ) ;
* V_43 ++ = F_27 ( V_55 ) ;
* V_43 ++ = F_27 ( 0 ) ;
return V_43 ;
}
static int
F_29 ( struct V_41 * V_42 )
{
F_30 ( V_29 , & V_42 -> V_45 -> V_46 -> V_28 ) ;
return 0 ;
}
static T_2 *
F_31 ( struct V_41 * V_42 , T_2 * V_43 )
{
T_3 V_56 ;
V_54 V_57 ;
V_56 = F_32 ( * V_43 ++ ) ;
if ( V_56 != V_55 &&
V_56 != V_49 &&
V_56 != V_58 ) {
F_33 ( L_5 , V_56 ) ;
return F_14 ( - V_59 ) ;
}
V_57 = F_32 ( * V_43 ++ ) ;
if ( V_57 > V_60 ) {
F_33 ( L_6 , V_57 ) ;
return F_14 ( - V_59 ) ;
}
V_42 -> V_45 -> V_46 -> V_61 -> V_62 = ( V_57 >> 2 ) + 2 ;
V_43 += ( V_57 >> 2 ) ;
return V_43 ;
}
int T_4 F_34 ( void )
{
return F_35 ( & V_5 ) ;
}
void F_36 ( void )
{
F_37 ( & V_5 ) ;
}
