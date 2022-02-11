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
static struct V_9 *
F_6 ( struct V_1 * V_7 , struct V_10 * V_11 , int V_12 )
{
return F_7 ( V_7 , V_11 , V_12 , V_13 ) ;
}
static struct V_9 *
F_8 ( struct V_1 * V_7 , struct V_10 * V_11 , int V_12 , T_1 V_14 )
{
struct V_15 * V_16 ;
unsigned int V_17 = 0 ;
unsigned int V_18 ;
F_2 ( L_3 ,
F_9 ( & V_19 , V_11 -> V_20 ) ,
F_10 ( & V_19 , V_11 -> V_21 ) ) ;
if ( ! ( V_16 = F_11 ( sizeof( * V_16 ) , V_14 ) ) )
return F_12 ( - V_22 ) ;
F_13 ( & V_16 -> V_23 , V_11 , V_7 , & V_24 ) ;
V_16 -> V_23 . V_25 = 1UL << V_26 ;
if ( V_11 -> V_27 != NULL )
V_17 = V_11 -> V_27 -> V_28 ;
if ( V_17 > V_29 )
V_17 = V_29 ;
V_16 -> V_30 = V_11 -> V_21 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
V_16 -> V_31 [ V_18 ] = F_14 ( V_11 -> V_27 , V_18 ) ;
if ( V_18 < V_29 )
V_16 -> V_31 [ V_18 ] = V_32 ;
return & V_16 -> V_23 ;
}
static void
F_15 ( struct V_15 * V_15 )
{
F_2 ( L_4 , V_15 ) ;
F_16 ( V_15 ) ;
}
static void
F_17 ( struct V_33 * V_34 )
{
struct V_15 * V_15 = F_18 ( V_34 , struct V_15 , V_23 . V_35 ) ;
F_15 ( V_15 ) ;
}
static void
F_19 ( struct V_9 * V_16 )
{
F_20 ( & V_16 -> V_35 , F_17 ) ;
}
static int
F_21 ( struct V_10 * V_11 , struct V_9 * V_36 , int V_12 )
{
struct V_15 * V_16 = F_18 ( V_36 , struct V_15 , V_23 ) ;
unsigned int V_17 = 0 ;
unsigned int V_18 ;
if ( ! F_22 ( V_16 -> V_37 , V_11 -> V_20 ) || ! F_23 ( V_16 -> V_30 , V_11 -> V_21 ) )
return 0 ;
if ( V_11 -> V_27 != NULL )
V_17 = V_11 -> V_27 -> V_28 ;
if ( V_17 > V_29 )
V_17 = V_29 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
if ( ! F_23 ( V_16 -> V_31 [ V_18 ] , F_14 ( V_11 -> V_27 , V_18 ) ) )
return 0 ;
if ( V_17 < V_29 && F_24 ( V_16 -> V_31 [ V_17 ] ) )
return 0 ;
return 1 ;
}
static T_2 *
F_25 ( struct V_38 * V_39 , T_2 * V_40 )
{
struct V_3 * V_4 = V_39 -> V_41 ;
struct V_15 * V_16 = F_18 ( V_39 -> V_42 -> V_43 , struct V_15 , V_23 ) ;
T_2 * V_44 , * V_45 ;
int V_18 ;
* V_40 ++ = F_26 ( V_46 ) ;
V_44 = V_40 ++ ;
* V_40 ++ = F_26 ( V_47 / V_48 ) ;
V_40 = F_27 ( V_40 , V_4 -> V_49 , V_4 -> V_50 ) ;
* V_40 ++ = F_26 ( ( V_51 ) F_9 ( & V_19 , V_16 -> V_37 ) ) ;
* V_40 ++ = F_26 ( ( V_51 ) F_10 ( & V_19 , V_16 -> V_30 ) ) ;
V_45 = V_40 ++ ;
for ( V_18 = 0 ; V_18 < 16 && F_24 ( V_16 -> V_31 [ V_18 ] ) ; V_18 ++ )
* V_40 ++ = F_26 ( ( V_51 ) F_10 ( & V_19 , V_16 -> V_31 [ V_18 ] ) ) ;
* V_45 = F_26 ( V_40 - V_45 - 1 ) ;
* V_44 = F_26 ( ( V_40 - V_44 - 1 ) << 2 ) ;
* V_40 ++ = F_26 ( V_52 ) ;
* V_40 ++ = F_26 ( 0 ) ;
return V_40 ;
}
static int
F_28 ( struct V_38 * V_39 )
{
F_29 ( V_26 , & V_39 -> V_42 -> V_43 -> V_25 ) ;
return 0 ;
}
static T_2 *
F_30 ( struct V_38 * V_39 , T_2 * V_40 )
{
T_3 V_53 ;
V_51 V_54 ;
V_53 = F_31 ( * V_40 ++ ) ;
if ( V_53 != V_52 &&
V_53 != V_46 &&
V_53 != V_55 ) {
F_32 ( L_5 , V_53 ) ;
return F_12 ( - V_56 ) ;
}
V_54 = F_31 ( * V_40 ++ ) ;
if ( V_54 > V_57 ) {
F_32 ( L_6 , V_54 ) ;
return F_12 ( - V_56 ) ;
}
V_39 -> V_42 -> V_43 -> V_58 -> V_59 = ( V_54 >> 2 ) + 2 ;
V_40 += ( V_54 >> 2 ) ;
return V_40 ;
}
int T_4 F_33 ( void )
{
return F_34 ( & V_5 ) ;
}
void F_35 ( void )
{
F_36 ( & V_5 ) ;
}
