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
struct V_8 * V_9 )
{
T_2 V_10 , V_11 ;
T_1 V_5 ;
int V_4 ;
V_4 = F_2 ( V_2 , V_12 , V_13 ,
& V_5 , ( void * ) V_9 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_4 ( V_9 , & V_11 , & V_10 ) ;
if ( V_4 )
F_5 ( L_3 ,
V_11 , V_10 ) ;
if ( ! V_9 -> V_14 )
V_9 -> V_14 = V_15 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , const char * V_16 ,
T_3 V_17 , struct V_18 * V_3 )
{
int V_4 ;
T_1 V_5 ;
T_2 V_19 ;
V_4 = F_2 ( V_2 , V_17 , sizeof( * V_3 ) , & V_5 , ( void * ) V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_5 != sizeof( * V_3 ) )
return - V_20 ;
V_19 = F_7 ( V_21 , ( V_22 * ) V_3 ,
F_8 ( struct V_18 , V_23 ) ) ;
if ( V_19 == V_3 -> V_23 ) {
F_9 ( V_3 -> V_24 ) ;
F_9 ( V_3 -> V_25 ) ;
F_10 ( L_4 ,
V_16 , V_17 , V_3 -> V_25 , V_3 -> V_24 ) ;
return 0 ;
}
F_5 ( L_5 ,
V_16 , V_17 , V_3 -> V_23 , V_19 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_26 * * V_27 , struct V_8 * V_9 )
{
int V_28 = 3 , V_29 = 0 ;
struct V_18 * V_3 = NULL ;
struct V_26 * V_30 ;
int V_4 ;
unsigned int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 , V_36 , V_37 ;
unsigned int V_38 , V_39 ;
unsigned int V_40 ;
int V_41 ;
bool V_42 = false ;
V_40 = F_12 ( V_43 , V_2 -> V_44 ,
V_45 ) ;
V_38 = V_40 ;
V_39 = V_9 -> V_14 * V_46 ;
V_39 = F_13 ( V_39 , V_40 ) ;
V_3 = F_14 ( sizeof( struct V_18 ) ) ;
if ( ! V_3 )
return - V_47 ;
V_4 = F_6 ( V_2 , L_6 , V_38 , V_3 ) ;
if ( ! V_4 ) {
F_9 ( V_3 -> V_48 ) ;
if ( F_15 ( V_3 -> V_48 , 10 , & V_31 ) ||
V_31 < V_49 ) {
F_16 ( L_7 ,
( int ) sizeof( V_3 -> V_48 ) ,
V_3 -> V_48 ) ;
goto V_50;
}
F_9 ( V_3 -> V_51 ) ;
if ( F_15 ( V_3 -> V_51 , 10 , & V_32 ) ||
V_32 < V_49 ) {
F_16 ( L_8 ,
( int ) sizeof( V_3 -> V_51 ) ,
V_3 -> V_51 ) ;
goto V_50;
}
F_9 ( V_3 -> V_52 ) ;
if ( F_15 ( V_3 -> V_52 , 10 , & V_35 ) ) {
F_16 ( L_9 ,
( int ) sizeof( V_3 -> V_52 ) ,
V_3 -> V_52 ) ;
goto V_50;
}
F_9 ( V_3 -> V_53 ) ;
if ( F_15 ( V_3 -> V_53 , 10 , & V_37 ) ) {
F_16 ( L_10 ,
( int ) sizeof( V_3 -> V_53 ) ,
V_3 -> V_53 ) ;
goto V_50;
}
V_32 = V_32 - V_49 ;
V_31 = V_31 - V_49 ;
V_33 = F_13 ( V_37 , V_2 -> V_44 ) + V_38 ;
if ( V_31 < V_32 ) {
V_34 = V_32 - V_31 ;
V_42 = true ;
} else {
V_31 = V_32 + V_35 ;
V_34 = V_33 - V_31 ;
}
} else if ( V_4 > 0 ) {
V_50:
V_35 = 0 ;
V_34 = 0 ;
V_31 = 0 ;
V_33 = V_38 ;
} else {
goto V_54;
}
V_36 = V_2 -> V_55 - V_33 - V_39 ;
if ( V_34 > 0 )
V_28 ++ ;
if ( V_35 > 0 )
V_28 ++ ;
V_30 = F_17 ( sizeof( * V_30 ) * V_28 + 10 * V_28 , V_56 ) ;
if ( ! V_30 ) {
V_4 = - V_47 ;
goto V_54;
}
V_30 [ V_29 ] . V_16 = L_11 ;
V_30 [ V_29 ] . V_57 = 0 ;
V_30 [ V_29 ] . V_55 = V_38 ;
V_29 ++ ;
if ( V_35 > 0 ) {
int V_58 = V_29 ;
if ( V_34 > 0 && V_42 )
V_58 ++ ;
V_30 [ V_58 ] . V_16 = L_12 ;
V_30 [ V_58 ] . V_57 = V_32 ;
V_30 [ V_58 ] . V_55 = V_35 ;
V_29 ++ ;
}
if ( V_34 > 0 ) {
int V_59 = V_29 ;
if ( V_35 > 0 && V_42 )
V_59 -- ;
V_30 [ V_59 ] . V_16 = L_6 ;
V_30 [ V_59 ] . V_57 = V_31 ;
V_30 [ V_59 ] . V_55 = V_34 ;
if ( V_36 > 0 && ! V_42 )
V_30 [ V_59 ] . V_55 += V_36 ;
V_29 ++ ;
}
V_30 [ V_29 ] . V_16 = L_13 ;
V_30 [ V_29 ] . V_57 = V_2 -> V_55 - V_39 ;
V_30 [ V_29 ] . V_55 = V_39 ;
V_29 ++ ;
V_30 [ V_29 ] . V_16 = L_14 ;
V_30 [ V_29 ] . V_57 = V_38 ;
V_30 [ V_29 ] . V_55 = V_2 -> V_55 - V_38 - V_39 ;
for ( V_41 = 0 ; V_41 < V_28 ; V_41 ++ )
F_10 ( L_15 , V_41 ,
V_30 [ V_41 ] . V_16 , V_30 [ V_41 ] . V_57 , V_30 [ V_41 ] . V_55 ) ;
F_10 ( L_16 , V_33 ,
V_36 ) ;
* V_27 = V_30 ;
V_4 = 0 ;
V_54:
F_18 ( V_3 ) ;
if ( V_4 )
return V_4 ;
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_26 * * V_27 ,
struct V_60 * V_61 )
{
struct V_8 * V_9 = NULL ;
int V_4 ;
if ( F_1 ( V_2 ) )
return - V_62 ;
V_9 = F_20 ( sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_47 ;
V_4 = F_3 ( V_2 , V_9 ) ;
if ( V_4 )
goto V_54;
if ( ! F_21 ( V_2 ) )
V_4 = F_11 ( V_2 , V_27 , V_9 ) ;
else
V_4 = - V_62 ;
V_54:
F_18 ( V_9 ) ;
return V_4 ;
}
