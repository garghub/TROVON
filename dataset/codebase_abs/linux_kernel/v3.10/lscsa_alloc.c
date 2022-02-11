static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned char * V_5 ;
V_4 = F_2 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 )
return - V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_5 = V_4 -> V_7 ; V_5 < V_4 -> V_7 + V_8 ; V_5 += V_9 )
F_3 ( F_4 ( V_5 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned char * V_5 ;
if ( V_2 -> V_4 == NULL )
return;
for ( V_5 = V_2 -> V_4 -> V_7 ; V_5 < V_2 -> V_4 -> V_7 + V_8 ; V_5 += V_9 )
F_6 ( F_4 ( V_5 ) ) ;
F_7 ( V_2 -> V_4 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_10 * * V_11 ;
unsigned char * V_5 ;
int V_12 , V_13 , V_14 ;
if ( ! F_9 () )
goto V_15;
V_2 -> V_16 = 1 ;
F_10 ( L_1 ,
V_2 ) ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
V_2 -> V_18 [ V_12 ] = F_11 ( V_19 ,
V_20 ) ;
if ( V_2 -> V_18 [ V_12 ] == NULL )
goto V_15;
}
F_10 ( L_2 ) ;
V_14 = V_21 * V_17 ;
V_11 = F_12 ( sizeof( struct V_10 * ) * V_14 , V_19 ) ;
if ( V_11 == NULL )
goto V_15;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
for ( V_13 = 0 ; V_13 < V_21 ; V_13 ++ )
V_11 [ V_12 * V_21 + V_13 ] =
V_2 -> V_18 [ V_12 ] + V_13 ;
V_2 -> V_4 = F_13 ( V_11 , V_14 , V_22 , V_23 ) ;
F_14 ( V_11 ) ;
if ( V_2 -> V_4 == NULL )
goto V_15;
memset ( V_2 -> V_4 , 0 , sizeof( struct V_3 ) ) ;
for ( V_5 = V_2 -> V_4 -> V_7 ; V_5 < V_2 -> V_4 -> V_7 + V_8 ; V_5 += V_9 )
F_3 ( F_4 ( V_5 ) ) ;
F_10 ( L_3 ) ;
return 0 ;
V_15:
F_10 ( L_4 ) ;
F_15 ( V_2 ) ;
return F_1 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
unsigned char * V_5 ;
int V_12 ;
if ( ! V_2 -> V_16 ) {
F_5 ( V_2 ) ;
return;
}
V_2 -> V_16 = 0 ;
if ( V_2 -> V_4 == NULL )
goto V_24;
for ( V_5 = V_2 -> V_4 -> V_7 ; V_5 < V_2 -> V_4 -> V_7 + V_8 ; V_5 += V_9 )
F_6 ( F_4 ( V_5 ) ) ;
F_16 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_24:
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
if ( V_2 -> V_18 [ V_12 ] )
F_17 ( V_2 -> V_18 [ V_12 ] , V_20 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
