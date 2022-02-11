int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_5 )
{
int V_6 = V_3 * sizeof( V_7 ) ;
int V_8 = - V_9 ;
if ( V_2 -> V_3 != V_3 ) {
F_2 ( V_2 ) ;
if ( ! V_3 )
return 0 ;
V_2 -> V_10 = F_3 ( V_6 , V_5 ) ;
if ( ! V_2 -> V_10 )
goto V_11;
V_2 -> V_12 = F_3 ( V_6 , V_5 ) ;
if ( ! V_2 -> V_12 )
goto V_11;
V_2 -> V_13 = F_3 ( V_6 , V_5 ) ;
if ( ! V_2 -> V_13 )
goto V_11;
if ( V_4 ) {
V_2 -> V_4 = F_3 ( V_6 , V_5 ) ;
if ( ! V_2 -> V_4 )
goto V_11;
} else {
V_2 -> V_4 = NULL ;
}
}
V_2 -> V_14 = 0 ;
V_2 -> V_3 = V_3 ;
V_8 = F_4 ( F_5 ( V_3 ) , V_2 ) ;
if ( V_8 )
goto V_11;
return 0 ;
V_11:
F_2 ( V_2 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_15 ) ;
}
void F_2 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_10 ) ;
F_7 ( V_2 -> V_12 ) ;
F_7 ( V_2 -> V_13 ) ;
F_7 ( V_2 -> V_4 ) ;
V_2 -> V_10 = V_2 -> V_12 = V_2 -> V_13 = V_2 -> V_4 = NULL ;
V_2 -> V_3 = 0 ;
}
int F_4 ( const struct V_1 * V_16 , struct V_1 * V_17 )
{
unsigned int V_18 = 0 , V_19 = 0 ;
T_2 V_6 ;
if ( V_17 -> V_14 > V_16 -> V_14 )
V_19 = V_17 -> V_14 - V_16 -> V_14 ;
else
V_18 = V_16 -> V_14 - V_17 -> V_14 ;
if ( V_19 >= V_16 -> V_3 || V_18 >= V_17 -> V_3 )
return - V_20 ;
V_6 = F_8 ( T_2 , V_17 -> V_3 - V_18 , V_16 -> V_3 - V_19 ) ;
if ( V_6 == 0 )
return - V_20 ;
V_6 *= sizeof( V_7 ) ;
memcpy ( V_17 -> V_10 + V_18 , V_16 -> V_10 + V_19 , V_6 ) ;
memcpy ( V_17 -> V_12 + V_18 , V_16 -> V_12 + V_19 , V_6 ) ;
memcpy ( V_17 -> V_13 + V_18 , V_16 -> V_13 + V_19 , V_6 ) ;
if ( V_16 -> V_4 && V_17 -> V_4 )
memcpy ( V_17 -> V_4 + V_18 , V_16 -> V_4 + V_19 , V_6 ) ;
return 0 ;
}
int F_9 ( const struct V_1 * V_16 , struct V_21 * V_17 )
{
unsigned int V_18 = 0 , V_19 = 0 ;
T_2 V_6 ;
if ( V_17 -> V_14 > V_16 -> V_14 )
V_19 = V_17 -> V_14 - V_16 -> V_14 ;
else
V_18 = V_16 -> V_14 - V_17 -> V_14 ;
if ( V_19 >= V_16 -> V_3 || V_18 >= V_17 -> V_3 )
return - V_20 ;
V_6 = F_8 ( T_2 , V_17 -> V_3 - V_18 , V_16 -> V_3 - V_19 ) ;
if ( V_6 == 0 )
return - V_20 ;
V_6 *= sizeof( V_7 ) ;
if ( F_10 ( V_17 -> V_10 + V_18 , V_16 -> V_10 + V_19 , V_6 ) )
return - V_22 ;
if ( F_10 ( V_17 -> V_12 + V_18 , V_16 -> V_12 + V_19 , V_6 ) )
return - V_22 ;
if ( F_10 ( V_17 -> V_13 + V_18 , V_16 -> V_13 + V_19 , V_6 ) )
return - V_22 ;
if ( V_16 -> V_4 && V_17 -> V_4 )
if ( F_10 ( V_17 -> V_4 + V_18 , V_16 -> V_4 + V_19 , V_6 ) )
return - V_22 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_25 , V_14 , V_26 = 0 ;
V_7 * V_10 , * V_12 , * V_13 , * V_4 ;
T_3 V_27 , V_28 , V_29 , V_30 = 0xffff ;
V_10 = V_2 -> V_10 ;
V_12 = V_2 -> V_12 ;
V_13 = V_2 -> V_13 ;
V_4 = V_2 -> V_4 ;
V_14 = V_2 -> V_14 ;
if ( V_14 < 0 || ( ! V_24 -> V_31 -> V_32 &&
! V_24 -> V_31 -> V_33 ) )
return - V_20 ;
if ( V_24 -> V_31 -> V_33 ) {
V_26 = V_24 -> V_31 -> V_33 ( V_2 , V_24 ) ;
} else {
for ( V_25 = 0 ; V_25 < V_2 -> V_3 ; V_25 ++ ) {
V_27 = * V_10 ++ ;
V_28 = * V_12 ++ ;
V_29 = * V_13 ++ ;
if ( V_4 )
V_30 = * V_4 ++ ;
if ( V_24 -> V_31 -> V_32 ( V_14 ++ ,
V_27 , V_28 , V_29 ,
V_30 , V_24 ) )
break;
}
}
if ( V_26 == 0 )
F_4 ( V_2 , & V_24 -> V_2 ) ;
return V_26 ;
}
int F_12 ( struct V_21 * V_2 , struct V_23 * V_24 )
{
int V_26 , V_6 = V_2 -> V_3 * sizeof( V_7 ) ;
struct V_1 V_34 ;
if ( V_6 < 0 || V_6 < V_2 -> V_3 )
return - V_35 ;
memset ( & V_34 , 0 , sizeof( struct V_1 ) ) ;
V_26 = F_1 ( & V_34 , V_2 -> V_3 , V_2 -> V_4 != NULL ,
V_36 ) ;
if ( V_26 )
return V_26 ;
if ( F_13 ( V_34 . V_10 , V_2 -> V_10 , V_6 ) ||
F_13 ( V_34 . V_12 , V_2 -> V_12 , V_6 ) ||
F_13 ( V_34 . V_13 , V_2 -> V_13 , V_6 ) ||
( V_2 -> V_4 && F_13 ( V_34 . V_4 , V_2 -> V_4 , V_6 ) ) ) {
V_26 = - V_22 ;
goto V_37;
}
V_34 . V_14 = V_2 -> V_14 ;
if ( ! F_14 ( V_24 ) ) {
V_26 = - V_38 ;
goto V_37;
}
V_26 = F_11 ( & V_34 , V_24 ) ;
F_15 ( V_24 ) ;
V_37:
F_2 ( & V_34 ) ;
return V_26 ;
}
const struct V_1 * F_5 ( int V_3 )
{
if ( V_3 <= 2 )
return & V_39 ;
if ( V_3 <= 4 )
return & V_40 ;
if ( V_3 <= 8 )
return & V_41 ;
return & V_42 ;
}
void F_16 ( void )
{
T_3 V_25 ;
for ( V_25 = 0 ; V_25 < F_17 ( V_43 ) ; V_25 ++ ) {
V_43 [ V_25 ] = ~ V_43 [ V_25 ] ;
V_44 [ V_25 ] = ~ V_44 [ V_25 ] ;
V_45 [ V_25 ] = ~ V_45 [ V_25 ] ;
}
for ( V_25 = 0 ; V_25 < F_17 ( V_46 ) ; V_25 ++ ) {
V_46 [ V_25 ] = ~ V_46 [ V_25 ] ;
V_47 [ V_25 ] = ~ V_47 [ V_25 ] ;
V_48 [ V_25 ] = ~ V_48 [ V_25 ] ;
}
for ( V_25 = 0 ; V_25 < F_17 ( V_49 ) ; V_25 ++ ) {
V_49 [ V_25 ] = ~ V_49 [ V_25 ] ;
V_50 [ V_25 ] = ~ V_50 [ V_25 ] ;
V_51 [ V_25 ] = ~ V_51 [ V_25 ] ;
}
for ( V_25 = 0 ; V_25 < F_17 ( V_52 ) ; V_25 ++ ) {
V_52 [ V_25 ] = ~ V_52 [ V_25 ] ;
V_53 [ V_25 ] = ~ V_53 [ V_25 ] ;
V_54 [ V_25 ] = ~ V_54 [ V_25 ] ;
}
}
