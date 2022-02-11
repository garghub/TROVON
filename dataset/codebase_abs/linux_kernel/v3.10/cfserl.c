struct V_1 * F_1 ( int V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 )
return NULL ;
F_3 ( F_4 ( struct V_4 , V_7 ) == 0 ) ;
V_5 -> V_7 . V_8 = V_9 ;
V_5 -> V_7 . V_10 = V_11 ;
V_5 -> V_7 . V_12 = V_13 ;
V_5 -> V_14 = V_3 ;
F_5 ( & V_5 -> V_15 ) ;
snprintf ( V_5 -> V_7 . V_16 , V_17 , L_1 ) ;
return & V_5 -> V_7 ;
}
static int V_9 ( struct V_1 * V_18 , struct V_19 * V_20 )
{
struct V_4 * V_21 = F_6 ( V_18 ) ;
T_1 V_22 ;
struct V_19 * V_23 = NULL ;
struct V_19 * V_24 = NULL ;
T_2 V_25 ;
T_1 V_26 ;
T_2 V_27 = V_28 ;
int V_29 ;
T_1 V_30 = 0 ;
F_3 ( V_20 != NULL ) ;
F_7 ( & V_21 -> V_15 ) ;
if ( V_21 -> V_31 != NULL ) {
V_21 -> V_31 =
F_8 ( V_21 -> V_31 , V_20 , V_30 ) ;
V_23 = V_21 -> V_31 ;
if ( V_23 == NULL ) {
F_9 ( & V_21 -> V_15 ) ;
return - V_32 ;
}
} else {
V_23 = V_20 ;
}
V_21 -> V_31 = NULL ;
do {
if ( V_21 -> V_14 ) {
F_10 ( V_23 , & V_25 , 1 ) ;
if ( V_25 != V_28 ) {
while ( F_11 ( V_23 )
&& V_25 != V_28 ) {
F_10 ( V_23 , & V_25 , 1 ) ;
}
if ( ! F_11 ( V_23 ) ) {
F_12 ( V_23 ) ;
V_21 -> V_31 = NULL ;
F_9 ( & V_21 -> V_15 ) ;
return - V_33 ;
}
}
}
V_22 = F_13 ( V_23 ) ;
if ( V_22 < 2 ) {
if ( V_21 -> V_14 )
F_14 ( V_23 , & V_27 , 1 ) ;
V_21 -> V_31 = V_23 ;
F_9 ( & V_21 -> V_15 ) ;
return 0 ;
}
F_15 ( V_23 , & V_26 , 2 ) ;
V_30 = F_16 ( V_26 ) + 2 ;
if ( V_30 < V_34
|| V_30 > V_35 ) {
if ( ! V_21 -> V_14 ) {
if ( V_23 != NULL )
F_12 ( V_23 ) ;
V_21 -> V_31 = NULL ;
V_30 = 0 ;
F_9 ( & V_21 -> V_15 ) ;
return - V_33 ;
}
continue;
}
if ( V_22 < V_30 ) {
if ( V_21 -> V_14 )
F_14 ( V_23 , & V_27 , 1 ) ;
V_21 -> V_31 = V_23 ;
F_9 ( & V_21 -> V_15 ) ;
return 0 ;
}
if ( V_22 > V_30 )
V_24 = F_17 ( V_23 , V_30 ) ;
else
V_24 = NULL ;
F_9 ( & V_21 -> V_15 ) ;
V_29 = V_21 -> V_7 . V_36 -> V_8 ( V_21 -> V_7 . V_36 , V_23 ) ;
F_7 ( & V_21 -> V_15 ) ;
if ( V_29 == - V_37 ) {
if ( V_21 -> V_14 ) {
if ( V_24 != NULL )
V_23 = F_8 ( V_23 , V_24 , 0 ) ;
continue;
} else {
F_12 ( V_23 ) ;
V_23 = NULL ;
}
}
V_23 = V_24 ;
} while ( V_23 != NULL );
F_9 ( & V_21 -> V_15 ) ;
return 0 ;
}
static int V_11 ( struct V_1 * V_7 , struct V_19 * V_20 )
{
struct V_4 * V_21 = F_6 ( V_7 ) ;
T_2 V_25 = V_28 ;
if ( V_21 -> V_14 )
F_14 ( V_20 , & V_25 , 1 ) ;
return V_7 -> V_38 -> V_10 ( V_7 -> V_38 , V_20 ) ;
}
static void V_13 ( struct V_1 * V_21 , enum V_39 V_40 ,
int V_41 )
{
V_21 -> V_36 -> V_12 ( V_21 -> V_36 , V_40 , V_41 ) ;
}
