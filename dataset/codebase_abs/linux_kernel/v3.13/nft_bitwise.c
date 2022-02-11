static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_3 * V_10 = & V_4 [ V_9 -> V_11 ] ;
struct V_3 * V_12 = & V_4 [ V_9 -> V_13 ] ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_9 -> V_15 , 4 ) ; V_14 ++ ) {
V_12 -> V_4 [ V_14 ] = ( V_10 -> V_4 [ V_14 ] & V_9 -> V_16 . V_4 [ V_14 ] ) ^
V_9 -> V_17 . V_4 [ V_14 ] ;
}
}
static int F_4 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const struct V_20 * const V_21 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 V_23 , V_24 ;
int V_25 ;
if ( V_21 [ V_26 ] == NULL ||
V_21 [ V_27 ] == NULL ||
V_21 [ V_28 ] == NULL ||
V_21 [ V_29 ] == NULL ||
V_21 [ V_30 ] == NULL )
return - V_31 ;
V_9 -> V_11 = F_5 ( F_6 ( V_21 [ V_26 ] ) ) ;
V_25 = F_7 ( V_9 -> V_11 ) ;
if ( V_25 < 0 )
return V_25 ;
V_9 -> V_13 = F_5 ( F_6 ( V_21 [ V_27 ] ) ) ;
V_25 = F_8 ( V_9 -> V_13 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_9 ( V_19 , V_9 -> V_13 , NULL , V_32 ) ;
if ( V_25 < 0 )
return V_25 ;
V_9 -> V_15 = F_5 ( F_6 ( V_21 [ V_28 ] ) ) ;
V_25 = F_10 ( NULL , & V_9 -> V_16 , & V_23 , V_21 [ V_29 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_23 . V_15 != V_9 -> V_15 )
return - V_31 ;
V_25 = F_10 ( NULL , & V_9 -> V_17 , & V_24 , V_21 [ V_30 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_24 . V_15 != V_9 -> V_15 )
return - V_31 ;
return 0 ;
}
static int F_11 ( struct V_33 * V_34 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_12 ( V_34 , V_26 , F_13 ( V_9 -> V_11 ) ) )
goto V_35;
if ( F_12 ( V_34 , V_27 , F_13 ( V_9 -> V_13 ) ) )
goto V_35;
if ( F_12 ( V_34 , V_28 , F_13 ( V_9 -> V_15 ) ) )
goto V_35;
if ( F_14 ( V_34 , V_29 , & V_9 -> V_16 ,
V_32 , V_9 -> V_15 ) < 0 )
goto V_35;
if ( F_14 ( V_34 , V_30 , & V_9 -> V_17 ,
V_32 , V_9 -> V_15 ) < 0 )
goto V_35;
return 0 ;
V_35:
return - 1 ;
}
int T_1 F_15 ( void )
{
return F_16 ( & V_36 ) ;
}
void F_17 ( void )
{
F_18 ( & V_36 ) ;
}
