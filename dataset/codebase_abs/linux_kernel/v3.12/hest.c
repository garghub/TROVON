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
#ifdef F_6
int V_17 ;
struct V_8 * V_9 ;
struct V_11 * V_25 ;
if ( V_2 -> type != V_7 )
return 0 ;
V_9 = (struct V_8 * ) V_2 ;
if ( ! V_9 -> V_26 )
return 0 ;
if ( ! ( V_9 -> V_27 & V_28 ) || ! V_9 -> V_10 )
return 1 ;
F_7 ( V_29 L_4 ) ;
V_25 = (struct V_11 * ) ( V_9 + 1 ) ;
for ( V_17 = 0 ; V_17 < V_9 -> V_10 ; V_17 ++ , V_25 ++ )
F_8 ( V_25 -> V_30 ) ;
#endif
return 1 ;
}
static int T_3 F_9 ( struct V_1 * V_2 , void * V_16 )
{
int * V_31 = V_16 ;
if ( V_2 -> type == V_32 )
( * V_31 ) ++ ;
return 0 ;
}
static int T_3 F_10 ( struct V_1 * V_2 , void * V_16 )
{
struct V_33 * V_34 ;
struct V_35 * V_35 = V_16 ;
int V_18 , V_17 ;
if ( V_2 -> type != V_32 )
return 0 ;
if ( ! ( (struct V_36 * ) V_2 ) -> V_26 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_35 -> V_31 ; V_17 ++ ) {
struct V_1 * V_37 ;
V_34 = V_35 -> V_38 [ V_17 ] ;
V_37 = * (struct V_1 * * ) V_34 -> V_39 . V_40 ;
if ( V_37 -> V_41 == V_2 -> V_41 ) {
F_4 (FW_WARN HEST_PFX L_5 ,
hdr->source_id) ;
return - V_42 ;
}
}
V_34 = F_11 ( L_6 , V_2 -> V_41 ) ;
if ( ! V_34 )
return - V_43 ;
V_18 = F_12 ( V_34 , & V_2 , sizeof( void * ) ) ;
if ( V_18 )
goto V_44;
V_18 = F_13 ( V_34 ) ;
if ( V_18 )
goto V_44;
V_35 -> V_38 [ V_35 -> V_31 ++ ] = V_34 ;
return 0 ;
V_44:
F_14 ( V_34 ) ;
return V_18 ;
}
static int T_3 F_15 ( unsigned int V_45 )
{
int V_18 , V_17 ;
struct V_35 V_35 ;
V_35 . V_31 = 0 ;
V_35 . V_38 = F_16 ( sizeof( void * ) * V_45 , V_46 ) ;
if ( ! V_35 . V_38 )
return - V_43 ;
V_18 = F_3 ( F_10 , & V_35 ) ;
if ( V_18 )
goto V_44;
V_47:
F_17 ( V_35 . V_38 ) ;
return V_18 ;
V_44:
for ( V_17 = 0 ; V_17 < V_35 . V_31 ; V_17 ++ )
F_18 ( V_35 . V_38 [ V_17 ] ) ;
goto V_47;
}
static int T_3 F_19 ( char * V_48 )
{
V_19 = 1 ;
return 0 ;
}
void T_3 F_20 ( void )
{
T_4 V_49 ;
int V_18 = - V_50 ;
unsigned int V_45 = 0 ;
if ( V_19 ) {
F_7 ( V_29 L_7 ) ;
return;
}
V_49 = F_21 ( V_51 , 0 ,
(struct V_52 * * ) & V_20 ) ;
if ( V_49 == V_53 )
goto V_44;
else if ( F_22 ( V_49 ) ) {
const char * V_54 = F_23 ( V_49 ) ;
F_24 ( V_29 L_8 , V_54 ) ;
V_18 = - V_21 ;
goto V_44;
}
if ( ! V_55 )
F_3 ( F_5 , NULL ) ;
if ( ! V_56 ) {
V_18 = F_3 ( F_9 , & V_45 ) ;
if ( V_18 )
goto V_44;
V_18 = F_15 ( V_45 ) ;
if ( V_18 )
goto V_44;
}
F_7 ( V_29 L_9 ) ;
return;
V_44:
V_19 = 1 ;
}
