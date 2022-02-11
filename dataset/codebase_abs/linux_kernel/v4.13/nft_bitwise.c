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
T_1 V_15 ;
int V_25 ;
if ( V_21 [ V_26 ] == NULL ||
V_21 [ V_27 ] == NULL ||
V_21 [ V_28 ] == NULL ||
V_21 [ V_29 ] == NULL ||
V_21 [ V_30 ] == NULL )
return - V_31 ;
V_25 = F_5 ( V_21 [ V_28 ] , V_32 , & V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_11 = F_6 ( V_21 [ V_26 ] ) ;
V_25 = F_7 ( V_8 -> V_11 , V_8 -> V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_13 = F_6 ( V_21 [ V_27 ] ) ;
V_25 = F_8 ( V_19 , V_8 -> V_13 , NULL ,
V_33 , V_8 -> V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_9 ( NULL , & V_8 -> V_16 , sizeof( V_8 -> V_16 ) , & V_23 ,
V_21 [ V_29 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_23 . V_15 != V_8 -> V_15 ) {
V_25 = - V_31 ;
goto V_34;
}
V_25 = F_9 ( NULL , & V_8 -> V_17 , sizeof( V_8 -> V_17 ) , & V_24 ,
V_21 [ V_30 ] ) ;
if ( V_25 < 0 )
goto V_34;
if ( V_24 . V_15 != V_8 -> V_15 ) {
V_25 = - V_31 ;
goto V_35;
}
return 0 ;
V_35:
F_10 ( & V_8 -> V_17 , V_24 . type ) ;
V_34:
F_10 ( & V_8 -> V_16 , V_23 . type ) ;
return V_25 ;
}
static int F_11 ( struct V_36 * V_37 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_12 ( V_37 , V_26 , V_8 -> V_11 ) )
goto V_38;
if ( F_12 ( V_37 , V_27 , V_8 -> V_13 ) )
goto V_38;
if ( F_13 ( V_37 , V_28 , F_14 ( V_8 -> V_15 ) ) )
goto V_38;
if ( F_15 ( V_37 , V_29 , & V_8 -> V_16 ,
V_33 , V_8 -> V_15 ) < 0 )
goto V_38;
if ( F_15 ( V_37 , V_30 , & V_8 -> V_17 ,
V_33 , V_8 -> V_15 ) < 0 )
goto V_38;
return 0 ;
V_38:
return - 1 ;
}
