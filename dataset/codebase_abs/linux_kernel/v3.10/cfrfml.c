static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_4 -> V_2 ) ;
if ( V_6 -> V_7 )
F_4 ( V_6 -> V_7 ) ;
F_5 ( V_4 ) ;
}
struct V_1 * F_6 ( T_1 V_8 , struct V_9 * V_9 ,
int V_10 )
{
int V_11 ;
struct V_5 * V_12 = F_7 ( sizeof( struct V_5 ) , V_13 ) ;
if ( ! V_12 )
return NULL ;
F_8 ( & V_12 -> V_14 , V_8 , V_9 , false ) ;
V_12 -> V_14 . V_15 = F_1 ;
V_12 -> V_14 . V_2 . V_16 = V_17 ;
V_12 -> V_14 . V_2 . V_18 = V_19 ;
V_11 = ( V_10 - V_20 - 6 ) / 16 ;
V_11 *= 16 ;
V_12 -> V_21 = V_11 ;
F_9 ( & V_12 -> V_22 ) ;
snprintf ( V_12 -> V_14 . V_2 . V_23 , V_24 ,
L_1 , V_8 ) ;
return & V_12 -> V_14 . V_2 ;
}
static struct V_25 * F_10 ( struct V_5 * V_6 , char * V_26 ,
struct V_25 * V_27 , int * V_28 )
{
struct V_25 * V_29 ;
* V_28 = - V_30 ;
if ( F_11 ( V_27 , V_26 , 6 ) < 0 )
return NULL ;
if ( memcmp ( V_26 , V_6 -> V_26 , 6 ) != 0 )
return NULL ;
V_29 = F_12 ( V_6 -> V_7 , V_27 ,
V_6 -> V_31 + V_20 ) ;
* V_28 = - V_32 ;
if ( V_29 == NULL )
return NULL ;
* V_28 = 0 ;
return V_29 ;
}
static int V_17 ( struct V_1 * V_33 , struct V_25 * V_27 )
{
T_1 V_11 ;
bool V_34 ;
int V_28 ;
T_1 V_26 [ 6 ] ;
struct V_5 * V_6 ;
struct V_25 * V_29 = NULL ;
F_13 ( V_33 -> V_35 != NULL ) ;
F_13 ( V_33 -> V_16 != NULL ) ;
V_6 = F_3 ( V_33 ) ;
F_14 ( & V_6 -> V_22 ) ;
V_28 = - V_30 ;
if ( F_11 ( V_27 , & V_11 , 1 ) < 0 )
goto V_36;
V_34 = V_11 & V_37 ;
if ( V_34 ) {
if ( V_6 -> V_7 == NULL ) {
if ( F_15 ( V_27 , V_6 -> V_26 , 6 ) < 0 )
goto V_36;
V_6 -> V_31 = F_16 ( V_6 -> V_26 + 4 ) ;
if ( F_17 ( V_27 ) )
goto V_36;
V_6 -> V_7 = V_27 ;
V_27 = NULL ;
} else {
V_29 = F_10 ( V_6 , V_26 , V_27 , & V_28 ) ;
if ( V_29 == NULL )
goto V_36;
if ( F_17 ( V_29 ) )
goto V_36;
V_6 -> V_7 = V_29 ;
if ( F_17 ( V_29 ) )
goto V_36;
}
V_28 = 0 ;
goto V_36;
}
if ( V_6 -> V_7 ) {
V_29 = F_10 ( V_6 , V_26 , V_27 , & V_28 ) ;
if ( V_29 == NULL )
goto V_36;
if ( F_17 ( V_29 ) )
goto V_36;
V_6 -> V_7 = NULL ;
V_27 = V_29 ;
V_29 = NULL ;
V_28 = V_30 ;
if ( V_6 -> V_31 != F_18 ( V_27 ) - V_20 + 1 )
goto V_36;
}
V_28 = V_6 -> V_14 . V_2 . V_35 -> V_16 ( V_6 -> V_14 . V_2 . V_35 , V_27 ) ;
V_36:
if ( V_28 != 0 ) {
if ( V_29 )
F_4 ( V_29 ) ;
if ( V_27 )
F_4 ( V_27 ) ;
if ( V_6 -> V_7 )
F_4 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
F_19 ( L_2 , V_28 ) ;
V_33 -> V_35 -> V_38 ( V_33 -> V_35 , V_39 ,
V_6 -> V_14 . V_9 . V_40 ) ;
}
F_20 ( & V_6 -> V_22 ) ;
if ( F_21 ( V_28 == - V_41 ) )
V_28 = - V_42 ;
return V_28 ;
}
static int F_22 ( struct V_5 * V_6 , struct V_25 * V_27 )
{
F_13 ( F_18 ( V_27 ) < V_6 -> V_21 + V_20 ) ;
F_23 ( V_27 ) -> V_8 = V_6 -> V_14 . V_2 . V_40 ;
F_23 ( V_27 ) -> V_43 = V_20 ;
F_23 ( V_27 ) -> V_9 = & V_6 -> V_14 . V_9 ;
return V_6 -> V_14 . V_2 . V_44 -> V_18 ( V_6 -> V_14 . V_2 . V_44 , V_27 ) ;
}
static int V_19 ( struct V_1 * V_33 , struct V_25 * V_27 )
{
int V_28 ;
T_1 V_45 ;
T_1 V_46 [ 6 ] ;
struct V_25 * V_47 = NULL ;
struct V_25 * V_48 = V_27 ;
struct V_5 * V_6 = F_3 ( V_33 ) ;
F_13 ( V_33 -> V_44 != NULL ) ;
F_13 ( V_33 -> V_44 -> V_18 != NULL ) ;
if ( ! F_24 ( & V_6 -> V_14 , & V_28 ) )
goto V_36;
V_28 = - V_30 ;
if ( F_18 ( V_27 ) <= V_20 - 1 )
goto V_36;
V_28 = 0 ;
if ( F_18 ( V_27 ) > V_6 -> V_21 + V_20 )
V_28 = F_15 ( V_27 , V_46 , 6 ) ;
if ( V_28 < 0 )
goto V_36;
while ( F_18 ( V_48 ) > V_6 -> V_21 + V_20 ) {
V_45 = 1 ;
V_28 = - V_30 ;
if ( F_25 ( V_48 , & V_45 , 1 ) < 0 )
goto V_36;
V_47 = F_26 ( V_48 , V_6 -> V_21 ) ;
if ( V_47 == NULL )
goto V_36;
V_28 = F_22 ( V_6 , V_48 ) ;
if ( V_28 != 0 ) {
V_48 = NULL ;
goto V_36;
}
V_48 = V_47 ;
V_47 = NULL ;
V_28 = - V_32 ;
if ( V_48 == NULL )
goto V_36;
V_28 = - V_30 ;
if ( F_25 ( V_48 , V_46 , 6 ) < 0 )
goto V_36;
}
V_45 = 0 ;
V_28 = - V_30 ;
if ( F_25 ( V_48 , & V_45 , 1 ) < 0 )
goto V_36;
V_28 = F_22 ( V_6 , V_48 ) ;
V_48 = NULL ;
V_36:
if ( V_28 != 0 ) {
F_19 ( L_2 , V_28 ) ;
V_33 -> V_35 -> V_38 ( V_33 -> V_35 , V_39 ,
V_6 -> V_14 . V_9 . V_40 ) ;
if ( V_47 )
F_4 ( V_47 ) ;
if ( V_48 )
F_4 ( V_48 ) ;
}
return V_28 ;
}
