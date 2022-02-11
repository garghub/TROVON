int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
T_1 V_5 )
{
enum V_6 V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( V_5 == 0 )
return 0 ;
F_3 ( V_12 , & V_2 -> V_13 ) ;
V_9 = F_4 ( V_2 ) ;
V_11 = & V_9 -> V_14 [ V_7 ] ;
V_11 -> V_15 = V_5 ;
V_11 -> V_16 = V_5 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , enum V_3 V_4 ,
T_2 V_14 , T_1 V_5 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
enum V_6 V_7 = F_2 ( V_4 ) ;
struct V_10 * V_11 ;
if ( V_5 == 0 )
return 0 ;
if ( F_6 ( ! V_9 ) ) {
F_7 ( 1 , L_1 ) ;
return 0 ;
}
F_3 ( V_12 , & V_2 -> V_13 ) ;
F_8 ( & V_2 -> V_17 ) ;
V_11 = & V_9 -> V_14 [ V_7 ] ;
if ( V_11 -> V_15 == V_11 -> V_16 ||
F_9 ( V_11 -> V_18 , F_10 ( V_14 ) ) ) {
V_11 -> V_18 = F_10 ( V_14 ) ;
V_11 -> V_15 = V_11 -> V_16 ;
V_11 -> V_16 += V_5 ;
}
F_11 ( & V_2 -> V_17 ) ;
return 0 ;
}
void F_12 ( struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_3 V_4 ,
T_1 V_5 )
{
const struct V_21 * V_22 ;
if ( F_13 ( V_2 ) != V_23 )
return;
V_22 = (struct V_21 * ) ( F_14 ( V_20 ) + F_15 ( V_20 ) ) ;
F_5 ( V_2 , V_4 , V_22 -> V_14 , V_5 ) ;
}
static void F_16 ( struct V_19 * V_20 ,
struct V_21 * V_24 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_10 * V_14 )
{
while ( V_25 < V_26 ) {
struct V_27 * V_28 ;
T_2 V_29 , V_30 ;
V_28 = ( void * ) V_20 -> V_31 + V_25 ;
if ( F_17 ( F_10 ( V_28 -> V_32 ) - V_14 -> V_15 ,
V_14 -> V_18 ) )
V_29 = F_18 ( F_10 ( V_28 -> V_32 ) -
V_14 -> V_16 ) ;
else
V_29 = F_18 ( F_10 ( V_28 -> V_32 ) -
V_14 -> V_15 ) ;
if ( F_17 ( F_10 ( V_28 -> V_33 ) - V_14 -> V_15 ,
V_14 -> V_18 ) )
V_30 = F_18 ( F_10 ( V_28 -> V_33 ) -
V_14 -> V_16 ) ;
else
V_30 = F_18 ( F_10 ( V_28 -> V_33 ) -
V_14 -> V_15 ) ;
F_19 ( L_2 ,
F_10 ( V_28 -> V_32 ) , F_10 ( V_29 ) ,
F_10 ( V_28 -> V_33 ) , F_10 ( V_30 ) ) ;
F_20 ( & V_24 -> V_34 , V_20 ,
V_28 -> V_32 , V_29 , false ) ;
F_20 ( & V_24 -> V_34 , V_20 ,
V_28 -> V_33 , V_30 , false ) ;
V_28 -> V_32 = V_29 ;
V_28 -> V_33 = V_30 ;
V_25 += sizeof( * V_28 ) ;
}
}
static unsigned int F_21 ( struct V_19 * V_20 ,
unsigned int V_35 ,
struct V_21 * V_24 ,
struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned int V_7 , V_36 , V_37 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_36 = V_35 + sizeof( struct V_21 ) ;
V_37 = V_35 + V_24 -> V_38 * 4 ;
if ( ! F_22 ( V_20 , V_37 ) )
return 0 ;
V_7 = F_2 ( V_4 ) ;
while ( V_36 < V_37 ) {
unsigned char * V_39 = V_20 -> V_31 + V_36 ;
switch ( V_39 [ 0 ] ) {
case V_40 :
return 1 ;
case V_41 :
V_36 ++ ;
continue;
default:
if ( V_36 + 1 == V_37 ||
V_36 + V_39 [ 1 ] > V_37 ||
V_39 [ 1 ] < 2 )
return 0 ;
if ( V_39 [ 0 ] == V_42 &&
V_39 [ 1 ] >= 2 + V_43 &&
( ( V_39 [ 1 ] - 2 ) % V_43 ) == 0 )
F_16 ( V_20 , V_24 , V_36 + 2 ,
V_36 + V_39 [ 1 ] ,
& V_9 -> V_14 [ ! V_7 ] ) ;
V_36 += V_39 [ 1 ] ;
}
}
return 1 ;
}
int F_23 ( struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_3 V_4 ,
unsigned int V_35 )
{
enum V_6 V_7 = F_2 ( V_4 ) ;
struct V_21 * V_24 ;
T_2 V_44 , V_45 ;
T_1 V_46 , V_47 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
struct V_10 * V_11 , * V_48 ;
int V_49 = 1 ;
V_11 = & V_9 -> V_14 [ V_7 ] ;
V_48 = & V_9 -> V_14 [ ! V_7 ] ;
if ( ! F_22 ( V_20 , V_35 + sizeof( * V_24 ) ) )
return 0 ;
V_24 = ( void * ) V_20 -> V_31 + V_35 ;
F_8 ( & V_2 -> V_17 ) ;
if ( F_17 ( F_10 ( V_24 -> V_14 ) , V_11 -> V_18 ) )
V_46 = V_11 -> V_16 ;
else
V_46 = V_11 -> V_15 ;
V_44 = F_18 ( F_10 ( V_24 -> V_14 ) + V_46 ) ;
F_20 ( & V_24 -> V_34 , V_20 , V_24 -> V_14 , V_44 , false ) ;
F_19 ( L_3 ,
F_10 ( V_24 -> V_14 ) , F_10 ( V_44 ) ) ;
V_24 -> V_14 = V_44 ;
if ( ! V_24 -> V_50 )
goto V_51;
if ( F_17 ( F_10 ( V_24 -> V_52 ) - V_48 -> V_15 ,
V_48 -> V_18 ) )
V_47 = V_48 -> V_16 ;
else
V_47 = V_48 -> V_15 ;
V_45 = F_18 ( F_10 ( V_24 -> V_52 ) - V_47 ) ;
F_20 ( & V_24 -> V_34 , V_20 , V_24 -> V_52 , V_45 ,
false ) ;
F_19 ( L_4 ,
F_10 ( V_24 -> V_14 ) , F_10 ( V_44 ) , F_10 ( V_24 -> V_52 ) ,
F_10 ( V_45 ) ) ;
V_24 -> V_52 = V_45 ;
V_49 = F_21 ( V_20 , V_35 , V_24 , V_2 , V_4 ) ;
V_51:
F_11 ( & V_2 -> V_17 ) ;
return V_49 ;
}
T_1 F_24 ( const struct V_1 * V_2 ,
enum V_6 V_7 ,
T_3 V_14 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
struct V_10 * V_11 ;
if ( ! V_9 )
return 0 ;
V_11 = & V_9 -> V_14 [ V_7 ] ;
return F_17 ( V_14 , V_11 -> V_18 ) ?
V_11 -> V_16 : V_11 -> V_15 ;
}
int F_25 ( void )
{
return F_26 ( & V_53 ) ;
}
void F_27 ( void )
{
F_28 ( & V_53 ) ;
}
