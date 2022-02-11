static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> type ;
int V_4 ;
if ( V_3 >= V_5 )
return 0 ;
V_4 = V_6 [ V_3 ] ;
if ( V_3 == V_7 ) {
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_2 ;
V_4 = sizeof( * V_9 ) + V_9 -> V_10 *
sizeof( struct V_11 ) ;
} else if ( V_3 == V_12 ) {
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_2 ;
V_4 = sizeof( * V_14 ) + V_14 -> V_10 *
sizeof( struct V_11 ) ;
}
F_2 ( V_4 == - 1 ) ;
return V_4 ;
}
int F_3 ( T_2 V_15 , void * V_16 )
{
struct V_1 * V_2 ;
int V_17 , V_18 , V_4 ;
if ( V_19 || ! V_20 )
return - V_21 ;
V_2 = (struct V_1 * ) ( V_20 + 1 ) ;
for ( V_17 = 0 ; V_17 < V_20 -> V_22 ; V_17 ++ ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
F_4 (FW_WARN HEST_PFX
L_1
L_2 ,
hest_hdr->type, hest_hdr->source_id) ;
return - V_21 ;
}
if ( ( void * ) V_2 + V_4 >
( void * ) V_20 + V_20 -> V_23 . V_24 ) {
F_4 (FW_BUG HEST_PFX
L_3 ,
hest_hdr->source_id) ;
return - V_21 ;
}
V_18 = V_15 ( V_2 , V_16 ) ;
if ( V_18 )
return V_18 ;
V_2 = ( void * ) V_2 + V_4 ;
}
return 0 ;
}
static int T_3 F_5 ( struct V_1 * V_2 , void * V_16 )
{
if ( V_2 -> type != V_7 )
return 0 ;
if ( ! V_25 )
return ! F_6 ( V_2 , V_16 ) ;
return 0 ;
}
static int T_3 F_7 ( struct V_1 * V_2 , void * V_16 )
{
int * V_26 = V_16 ;
if ( V_2 -> type == V_27 ||
V_2 -> type == V_28 )
( * V_26 ) ++ ;
return 0 ;
}
static int T_3 F_8 ( struct V_1 * V_2 , void * V_16 )
{
struct V_29 * V_30 ;
struct V_31 * V_31 = V_16 ;
int V_18 , V_17 ;
if ( V_2 -> type != V_27 &&
V_2 -> type != V_28 )
return 0 ;
if ( ! ( (struct V_32 * ) V_2 ) -> V_33 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_31 -> V_26 ; V_17 ++ ) {
struct V_1 * V_34 ;
V_30 = V_31 -> V_35 [ V_17 ] ;
V_34 = * (struct V_1 * * ) V_30 -> V_36 . V_37 ;
if ( V_34 -> V_38 == V_2 -> V_38 ) {
F_4 (FW_WARN HEST_PFX L_4 ,
hdr->source_id) ;
return - V_39 ;
}
}
V_30 = F_9 ( L_5 , V_2 -> V_38 ) ;
if ( ! V_30 )
return - V_40 ;
V_18 = F_10 ( V_30 , & V_2 , sizeof( void * ) ) ;
if ( V_18 )
goto V_41;
V_18 = F_11 ( V_30 ) ;
if ( V_18 )
goto V_41;
V_31 -> V_35 [ V_31 -> V_26 ++ ] = V_30 ;
return 0 ;
V_41:
F_12 ( V_30 ) ;
return V_18 ;
}
static int T_3 F_13 ( unsigned int V_42 )
{
int V_18 , V_17 ;
struct V_31 V_31 ;
V_31 . V_26 = 0 ;
V_31 . V_35 = F_14 ( sizeof( void * ) * V_42 , V_43 ) ;
if ( ! V_31 . V_35 )
return - V_40 ;
V_18 = F_3 ( F_8 , & V_31 ) ;
if ( V_18 )
goto V_41;
V_44:
F_15 ( V_31 . V_35 ) ;
return V_18 ;
V_41:
for ( V_17 = 0 ; V_17 < V_31 . V_26 ; V_17 ++ )
F_16 ( V_31 . V_35 [ V_17 ] ) ;
goto V_44;
}
static int T_3 F_17 ( char * V_45 )
{
V_19 = V_46 ;
return 0 ;
}
void T_3 F_18 ( void )
{
T_4 V_47 ;
int V_18 = - V_48 ;
unsigned int V_42 = 0 ;
if ( V_19 ) {
F_19 ( V_49 L_6 ) ;
return;
}
V_47 = F_20 ( V_50 , 0 ,
(struct V_51 * * ) & V_20 ) ;
if ( V_47 == V_52 ) {
V_19 = V_53 ;
return;
} else if ( F_21 ( V_47 ) ) {
const char * V_54 = F_22 ( V_47 ) ;
F_23 ( V_49 L_7 , V_54 ) ;
V_18 = - V_21 ;
goto V_41;
}
V_18 = F_3 ( F_5 , NULL ) ;
if ( V_18 )
goto V_41;
if ( ! V_55 ) {
V_18 = F_3 ( F_7 , & V_42 ) ;
if ( V_18 )
goto V_41;
V_18 = F_13 ( V_42 ) ;
if ( V_18 )
goto V_41;
}
F_19 ( V_49 L_8 ) ;
return;
V_41:
V_19 = V_46 ;
}
