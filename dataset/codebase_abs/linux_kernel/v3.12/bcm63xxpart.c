static int F_1 ( struct V_1 * V_2 )
{
char V_3 [ 9 ] ;
int V_4 ;
T_1 V_5 ;
V_4 = F_2 ( V_2 , V_6 , 5 , & V_5 ,
( void * ) V_3 ) ;
V_3 [ V_5 ] = 0 ;
if ( V_4 )
return V_4 ;
if ( strncmp ( L_1 , V_3 , 5 ) == 0 )
return 0 ;
V_4 = F_2 ( V_2 , V_7 , 8 , & V_5 ,
( void * ) V_3 ) ;
V_3 [ V_5 ] = 0 ;
return strncmp ( L_2 , V_3 , 8 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_8 * * V_9 ,
struct V_10 * V_11 )
{
int V_12 = 3 , V_13 = 0 ;
struct V_14 * V_3 ;
struct V_8 * V_15 ;
int V_4 ;
T_1 V_5 ;
unsigned int V_16 , V_17 , V_18 ;
unsigned int V_19 , V_20 , V_21 , V_22 ;
unsigned int V_23 , V_24 ;
unsigned int V_25 ;
int V_26 ;
T_2 V_27 ;
bool V_28 = false ;
if ( F_1 ( V_2 ) )
return - V_29 ;
V_25 = F_4 ( V_30 , V_2 -> V_31 ,
V_32 ) ;
V_23 = V_25 ;
V_24 = F_5 () * V_33 ;
V_24 = F_6 ( V_24 , V_25 ) ;
V_3 = F_7 ( sizeof( struct V_14 ) ) ;
if ( ! V_3 )
return - V_34 ;
V_4 = F_2 ( V_2 , V_23 , sizeof( struct V_14 ) , & V_5 ,
( void * ) V_3 ) ;
if ( V_5 != sizeof( struct V_14 ) ) {
F_8 ( V_3 ) ;
return - V_35 ;
}
V_27 = F_9 ( V_36 , ( V_37 * ) V_3 ,
F_10 ( struct V_14 , V_38 ) ) ;
if ( V_27 == V_3 -> V_38 ) {
char * V_39 = & ( V_3 -> V_40 [ 0 ] ) ;
char * V_41 = & ( V_3 -> V_42 [ 0 ] ) ;
sscanf ( V_3 -> V_43 , L_3 , & V_16 ) ;
sscanf ( V_3 -> V_44 , L_3 , & V_17 ) ;
sscanf ( V_3 -> V_45 , L_3 , & V_20 ) ;
sscanf ( V_3 -> V_46 , L_3 , & V_22 ) ;
F_11 ( L_4 ,
V_41 , V_39 ) ;
V_17 = V_17 - V_47 ;
V_16 = V_16 - V_47 ;
V_18 = F_6 ( V_22 , V_2 -> V_31 ) + V_23 ;
if ( V_16 < V_17 ) {
V_19 = V_17 - V_16 ;
V_28 = true ;
} else {
V_16 = V_17 + V_20 ;
V_19 = V_18 - V_16 ;
}
} else {
F_12 ( L_5 ,
V_3 -> V_38 , V_27 ) ;
V_20 = 0 ;
V_19 = 0 ;
V_16 = 0 ;
V_18 = V_23 ;
}
V_21 = V_2 -> V_48 - V_18 - V_24 ;
if ( V_19 > 0 )
V_12 ++ ;
if ( V_20 > 0 )
V_12 ++ ;
V_15 = F_13 ( sizeof( * V_15 ) * V_12 + 10 * V_12 , V_49 ) ;
if ( ! V_15 ) {
F_8 ( V_3 ) ;
return - V_34 ;
}
V_15 [ V_13 ] . V_50 = L_6 ;
V_15 [ V_13 ] . V_51 = 0 ;
V_15 [ V_13 ] . V_48 = V_23 ;
V_13 ++ ;
if ( V_20 > 0 ) {
int V_52 = V_13 ;
if ( V_19 > 0 && V_28 )
V_52 ++ ;
V_15 [ V_52 ] . V_50 = L_7 ;
V_15 [ V_52 ] . V_51 = V_17 ;
V_15 [ V_52 ] . V_48 = V_20 ;
V_13 ++ ;
}
if ( V_19 > 0 ) {
int V_53 = V_13 ;
if ( V_20 > 0 && V_28 )
V_53 -- ;
V_15 [ V_53 ] . V_50 = L_8 ;
V_15 [ V_53 ] . V_51 = V_16 ;
V_15 [ V_53 ] . V_48 = V_19 ;
if ( V_21 > 0 && ! V_28 )
V_15 [ V_53 ] . V_48 += V_21 ;
V_13 ++ ;
}
V_15 [ V_13 ] . V_50 = L_9 ;
V_15 [ V_13 ] . V_51 = V_2 -> V_48 - V_24 ;
V_15 [ V_13 ] . V_48 = V_24 ;
V_13 ++ ;
V_15 [ V_13 ] . V_50 = L_10 ;
V_15 [ V_13 ] . V_51 = V_23 ;
V_15 [ V_13 ] . V_48 = V_2 -> V_48 - V_23 - V_24 ;
for ( V_26 = 0 ; V_26 < V_12 ; V_26 ++ )
F_11 ( L_11 , V_26 ,
V_15 [ V_26 ] . V_50 , V_15 [ V_26 ] . V_51 , V_15 [ V_26 ] . V_48 ) ;
F_11 ( L_12 , V_18 ,
V_21 ) ;
* V_9 = V_15 ;
F_8 ( V_3 ) ;
return V_12 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_54 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_54 ) ;
}
