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
if ( V_19 )
return - V_20 ;
V_2 = (struct V_1 * ) ( V_21 + 1 ) ;
for ( V_17 = 0 ; V_17 < V_21 -> V_22 ; V_17 ++ ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
F_4 (FW_WARN HEST_PFX
L_1
L_2 ,
hest_hdr->type, hest_hdr->source_id) ;
return - V_20 ;
}
if ( ( void * ) V_2 + V_4 >
( void * ) V_21 + V_21 -> V_23 . V_24 ) {
F_4 (FW_BUG HEST_PFX
L_3 ,
hest_hdr->source_id) ;
return - V_20 ;
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
int * V_25 = V_16 ;
if ( V_2 -> type == V_26 )
( * V_25 ) ++ ;
return 0 ;
}
static int T_3 F_6 ( struct V_1 * V_2 , void * V_16 )
{
struct V_27 * V_28 ;
struct V_29 * V_29 = V_16 ;
int V_18 , V_17 ;
if ( V_2 -> type != V_26 )
return 0 ;
if ( ! ( (struct V_30 * ) V_2 ) -> V_31 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_29 -> V_25 ; V_17 ++ ) {
struct V_1 * V_32 ;
V_28 = V_29 -> V_33 [ V_17 ] ;
V_32 = * (struct V_1 * * ) V_28 -> V_34 . V_35 ;
if ( V_32 -> V_36 == V_2 -> V_36 ) {
F_4 (FW_WARN HEST_PFX L_4 ,
hdr->source_id) ;
return - V_37 ;
}
}
V_28 = F_7 ( L_5 , V_2 -> V_36 ) ;
if ( ! V_28 )
return - V_38 ;
V_18 = F_8 ( V_28 , & V_2 , sizeof( void * ) ) ;
if ( V_18 )
goto V_39;
V_18 = F_9 ( V_28 ) ;
if ( V_18 )
goto V_39;
V_29 -> V_33 [ V_29 -> V_25 ++ ] = V_28 ;
return 0 ;
V_39:
F_10 ( V_28 ) ;
return V_18 ;
}
static int T_3 F_11 ( unsigned int V_40 )
{
int V_18 , V_17 ;
struct V_29 V_29 ;
V_29 . V_25 = 0 ;
V_29 . V_33 = F_12 ( sizeof( void * ) * V_40 , V_41 ) ;
if ( ! V_29 . V_33 )
return - V_38 ;
V_18 = F_3 ( F_6 , & V_29 ) ;
if ( V_18 )
goto V_39;
V_42:
F_13 ( V_29 . V_33 ) ;
return V_18 ;
V_39:
for ( V_17 = 0 ; V_17 < V_29 . V_25 ; V_17 ++ )
F_14 ( V_29 . V_33 [ V_17 ] ) ;
goto V_42;
}
static int T_3 F_15 ( char * V_43 )
{
V_19 = 1 ;
return 0 ;
}
void T_3 F_16 ( void )
{
T_4 V_44 ;
int V_18 = - V_45 ;
unsigned int V_40 = 0 ;
if ( V_19 ) {
F_17 ( V_46 L_6 ) ;
return;
}
if ( V_47 )
goto V_39;
V_44 = F_18 ( V_48 , 0 ,
(struct V_49 * * ) & V_21 ) ;
if ( V_44 == V_50 ) {
F_17 ( V_46 L_7 ) ;
goto V_39;
} else if ( F_19 ( V_44 ) ) {
const char * V_51 = F_20 ( V_44 ) ;
F_21 ( V_46 L_8 , V_51 ) ;
V_18 = - V_20 ;
goto V_39;
}
V_18 = F_3 ( F_5 , & V_40 ) ;
if ( V_18 )
goto V_39;
V_18 = F_11 ( V_40 ) ;
if ( ! V_18 ) {
F_17 ( V_46 L_9 ) ;
return;
}
V_39:
V_19 = 1 ;
}
