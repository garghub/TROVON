static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const T_1 * V_9 = & V_4 -> V_10 [ V_8 -> V_11 ] ;
T_1 * V_12 = & V_4 -> V_10 [ V_8 -> V_13 ] ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_8 -> V_15 , 4 ) ; V_14 ++ )
V_12 [ V_14 ] = ( V_9 [ V_14 ] & V_8 -> V_16 . V_10 [ V_14 ] ) ^ V_8 -> V_17 . V_10 [ V_14 ] ;
}
static int F_4 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const struct V_20 * const V_21 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_22 V_23 , V_24 ;
int V_25 ;
if ( V_21 [ V_26 ] == NULL ||
V_21 [ V_27 ] == NULL ||
V_21 [ V_28 ] == NULL ||
V_21 [ V_29 ] == NULL ||
V_21 [ V_30 ] == NULL )
return - V_31 ;
V_8 -> V_15 = F_5 ( F_6 ( V_21 [ V_28 ] ) ) ;
V_8 -> V_11 = F_7 ( V_21 [ V_26 ] ) ;
V_25 = F_8 ( V_8 -> V_11 , V_8 -> V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_13 = F_7 ( V_21 [ V_27 ] ) ;
V_25 = F_9 ( V_19 , V_8 -> V_13 , NULL ,
V_32 , V_8 -> V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( NULL , & V_8 -> V_16 , sizeof( V_8 -> V_16 ) , & V_23 ,
V_21 [ V_29 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_23 . V_15 != V_8 -> V_15 )
return - V_31 ;
V_25 = F_10 ( NULL , & V_8 -> V_17 , sizeof( V_8 -> V_17 ) , & V_24 ,
V_21 [ V_30 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_24 . V_15 != V_8 -> V_15 )
return - V_31 ;
return 0 ;
}
static int F_11 ( struct V_33 * V_34 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_12 ( V_34 , V_26 , V_8 -> V_11 ) )
goto V_35;
if ( F_12 ( V_34 , V_27 , V_8 -> V_13 ) )
goto V_35;
if ( F_13 ( V_34 , V_28 , F_14 ( V_8 -> V_15 ) ) )
goto V_35;
if ( F_15 ( V_34 , V_29 , & V_8 -> V_16 ,
V_32 , V_8 -> V_15 ) < 0 )
goto V_35;
if ( F_15 ( V_34 , V_30 , & V_8 -> V_17 ,
V_32 , V_8 -> V_15 ) < 0 )
goto V_35;
return 0 ;
V_35:
return - 1 ;
}
int T_2 F_16 ( void )
{
return F_17 ( & V_36 ) ;
}
void F_18 ( void )
{
F_19 ( & V_36 ) ;
}
