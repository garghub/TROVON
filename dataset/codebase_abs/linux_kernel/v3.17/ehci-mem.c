static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_4 -> V_6 = V_5 ;
V_4 -> V_7 = F_2 ( V_2 , V_8 ) ;
V_4 -> V_9 = F_3 ( V_2 ) ;
V_4 -> V_10 = F_3 ( V_2 ) ;
F_4 ( & V_4 -> V_11 ) ;
}
static struct V_3 * F_5 ( struct V_1 * V_2 , T_2 V_12 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
V_4 = F_6 ( V_2 -> V_13 , V_12 , & V_5 ) ;
if ( V_4 != NULL ) {
F_1 ( V_2 , V_4 , V_5 ) ;
}
return V_4 ;
}
static inline void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_8 ( V_2 -> V_13 , V_4 , V_4 -> V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
if ( ! F_10 ( & V_15 -> V_11 ) || V_15 -> V_16 . V_17 ) {
F_11 ( V_2 , L_1 ) ;
F_12 () ;
}
if ( V_15 -> V_18 )
F_7 ( V_2 , V_15 -> V_18 ) ;
F_8 ( V_2 -> V_19 , V_15 -> V_20 , V_15 -> V_21 ) ;
F_13 ( V_15 ) ;
}
static struct V_14 * F_14 ( struct V_1 * V_2 , T_2 V_12 )
{
struct V_14 * V_15 ;
T_1 V_5 ;
V_15 = F_15 ( sizeof *V_15 , V_22 ) ;
if ( ! V_15 )
goto V_23;
V_15 -> V_20 = (struct V_24 * )
F_6 ( V_2 -> V_19 , V_12 , & V_5 ) ;
if ( ! V_15 -> V_20 )
goto V_25;
memset ( V_15 -> V_20 , 0 , sizeof * V_15 -> V_20 ) ;
V_15 -> V_21 = V_5 ;
F_4 ( & V_15 -> V_11 ) ;
F_4 ( & V_15 -> V_26 ) ;
V_15 -> V_18 = F_5 ( V_2 , V_12 ) ;
if ( V_15 -> V_18 == NULL ) {
F_11 ( V_2 , L_2 ) ;
goto V_27;
}
V_23:
return V_15 ;
V_27:
F_8 ( V_2 -> V_19 , V_15 -> V_20 , V_15 -> V_21 ) ;
V_25:
F_13 ( V_15 ) ;
return NULL ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 )
F_9 ( V_2 , V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
if ( V_2 -> V_18 )
F_9 ( V_2 , V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
if ( V_2 -> V_13 )
F_17 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
if ( V_2 -> V_19 ) {
F_17 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
}
if ( V_2 -> V_29 )
F_17 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
if ( V_2 -> V_30 )
F_17 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
if ( V_2 -> V_31 )
F_18 ( F_19 ( V_2 ) -> V_32 . V_33 ,
V_2 -> V_34 * sizeof ( V_35 ) ,
V_2 -> V_31 , V_2 -> V_36 ) ;
V_2 -> V_31 = NULL ;
F_13 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_12 )
{
int V_38 ;
V_2 -> V_13 = F_21 ( L_3 ,
F_19 ( V_2 ) -> V_32 . V_33 ,
sizeof ( struct V_3 ) ,
32 ,
4096 ) ;
if ( ! V_2 -> V_13 ) {
goto V_25;
}
V_2 -> V_19 = F_21 ( L_4 ,
F_19 ( V_2 ) -> V_32 . V_33 ,
sizeof( struct V_24 ) ,
32 ,
4096 ) ;
if ( ! V_2 -> V_19 ) {
goto V_25;
}
V_2 -> V_28 = F_14 ( V_2 , V_12 ) ;
if ( ! V_2 -> V_28 ) {
goto V_25;
}
V_2 -> V_29 = F_21 ( L_5 ,
F_19 ( V_2 ) -> V_32 . V_33 ,
sizeof ( struct V_39 ) ,
32 ,
4096 ) ;
if ( ! V_2 -> V_29 ) {
goto V_25;
}
V_2 -> V_30 = F_21 ( L_6 ,
F_19 ( V_2 ) -> V_32 . V_33 ,
sizeof ( struct V_40 ) ,
32 ,
4096 ) ;
if ( ! V_2 -> V_30 ) {
goto V_25;
}
V_2 -> V_31 = ( V_41 * )
F_22 ( F_19 ( V_2 ) -> V_32 . V_33 ,
V_2 -> V_34 * sizeof( V_41 ) ,
& V_2 -> V_36 , V_12 ) ;
if ( V_2 -> V_31 == NULL ) {
goto V_25;
}
if ( V_2 -> V_42 ) {
struct V_24 * V_20 ;
V_2 -> V_18 = F_14 ( V_2 , V_12 ) ;
if ( ! V_2 -> V_18 )
goto V_25;
V_20 = V_2 -> V_18 -> V_20 ;
V_20 -> V_9 = F_3 ( V_2 ) ;
V_20 -> V_43 = F_3 ( V_2 ) ;
V_20 -> V_10 = F_3 ( V_2 ) ;
V_2 -> V_18 -> V_20 = V_20 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_34 ; V_38 ++ )
V_2 -> V_31 [ V_38 ] = F_2 ( V_2 ,
V_2 -> V_18 -> V_21 ) ;
} else {
for ( V_38 = 0 ; V_38 < V_2 -> V_34 ; V_38 ++ )
V_2 -> V_31 [ V_38 ] = F_3 ( V_2 ) ;
}
V_2 -> V_37 = F_23 ( V_2 -> V_34 , sizeof( void * ) , V_12 ) ;
if ( V_2 -> V_37 != NULL )
return 0 ;
V_25:
F_11 ( V_2 , L_7 ) ;
F_16 ( V_2 ) ;
return - V_44 ;
}
