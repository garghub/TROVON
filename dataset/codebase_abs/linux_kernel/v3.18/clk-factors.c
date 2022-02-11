static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = 1 , V_5 = 0 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
V_8 = F_3 ( V_11 -> V_8 ) ;
if ( V_13 -> V_14 != V_15 )
V_4 = F_4 ( V_13 -> V_16 , V_13 -> V_14 , V_8 ) ;
if ( V_13 -> V_17 != V_15 )
V_5 = F_4 ( V_13 -> V_18 , V_13 -> V_17 , V_8 ) ;
if ( V_13 -> V_19 != V_15 )
V_7 = F_4 ( V_13 -> V_20 , V_13 -> V_19 , V_8 ) ;
if ( V_13 -> V_21 != V_15 )
V_6 = F_4 ( V_13 -> V_22 , V_13 -> V_21 , V_8 ) ;
V_9 = ( V_3 * ( V_4 + V_13 -> V_23 ) * ( V_5 + 1 ) >> V_6 ) / ( V_7 + 1 ) ;
return V_9 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_3 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_24 ( ( T_2 * ) & V_9 , ( T_2 ) * V_3 ,
NULL , NULL , NULL , NULL ) ;
return V_9 ;
}
static long F_6 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_25 ,
struct V_26 * * V_27 )
{
struct V_26 * V_26 = V_2 -> V_26 , * V_28 , * V_29 = NULL ;
int V_30 , V_31 ;
unsigned long V_3 , V_32 = 0 , V_33 , V_34 = 0 ;
V_31 = F_7 ( V_26 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_28 = F_8 ( V_26 , V_30 ) ;
if ( ! V_28 )
continue;
if ( F_9 ( V_26 ) & V_35 )
V_3 = F_10 ( V_28 , V_9 ) ;
else
V_3 = F_11 ( V_28 ) ;
V_33 = F_5 ( V_2 , V_9 , & V_3 ) ;
if ( V_33 <= V_9 && V_33 > V_34 ) {
V_29 = V_28 ;
V_32 = V_3 ;
V_34 = V_33 ;
}
}
if ( V_29 )
* V_27 = V_29 ;
* V_25 = V_32 ;
return V_34 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
T_1 V_4 = 0 , V_5 = 0 , V_7 = 0 , V_6 = 0 ;
T_2 V_8 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_36 = 0 ;
V_11 -> V_24 ( ( T_2 * ) & V_9 , ( T_2 ) V_3 , & V_4 , & V_5 , & V_7 , & V_6 ) ;
if ( V_11 -> V_37 )
F_13 ( V_11 -> V_37 , V_36 ) ;
V_8 = F_3 ( V_11 -> V_8 ) ;
V_8 = F_14 ( V_13 -> V_16 , V_13 -> V_14 , V_8 , V_4 ) ;
V_8 = F_14 ( V_13 -> V_18 , V_13 -> V_17 , V_8 , V_5 ) ;
V_8 = F_14 ( V_13 -> V_20 , V_13 -> V_19 , V_8 , V_7 ) ;
V_8 = F_14 ( V_13 -> V_22 , V_13 -> V_21 , V_8 , V_6 ) ;
F_15 ( V_8 , V_11 -> V_8 ) ;
F_16 ( ( V_9 >> 20 ) * 500 / 2 ) ;
if ( V_11 -> V_37 )
F_17 ( V_11 -> V_37 , V_36 ) ;
return 0 ;
}
struct V_26 * T_3 F_18 ( struct V_38 * V_39 ,
const struct V_40 * V_41 ,
T_4 * V_37 )
{
struct V_26 * V_26 ;
struct V_10 * V_11 ;
struct V_42 * V_43 = NULL ;
struct V_44 * V_45 = NULL ;
struct V_1 * V_46 = NULL ;
struct V_1 * V_47 = NULL ;
const char * V_48 = V_39 -> V_49 ;
const char * V_50 [ V_51 ] ;
void T_5 * V_8 ;
int V_30 = 0 ;
V_8 = F_19 ( V_39 , 0 ) ;
while ( V_30 < V_51 &&
( V_50 [ V_30 ] = F_20 ( V_39 , V_30 ) ) != NULL )
V_30 ++ ;
if ( V_41 -> V_49 )
V_48 = V_41 -> V_49 ;
else
F_21 ( V_39 , L_1 , & V_48 ) ;
V_11 = F_22 ( sizeof( struct V_10 ) , V_52 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_8 = V_8 ;
V_11 -> V_13 = V_41 -> V_53 ;
V_11 -> V_24 = V_41 -> V_54 ;
V_11 -> V_37 = V_37 ;
if ( V_41 -> V_55 ) {
V_43 = F_22 ( sizeof( struct V_42 ) , V_52 ) ;
if ( ! V_43 ) {
F_23 ( V_11 ) ;
return NULL ;
}
V_43 -> V_8 = V_8 ;
V_43 -> V_56 = V_41 -> V_55 ;
V_43 -> V_37 = V_11 -> V_37 ;
V_46 = & V_43 -> V_2 ;
}
if ( V_41 -> V_45 ) {
V_45 = F_22 ( sizeof( struct V_44 ) , V_52 ) ;
if ( ! V_45 ) {
F_23 ( V_11 ) ;
F_23 ( V_43 ) ;
return NULL ;
}
V_45 -> V_8 = V_8 ;
V_45 -> V_57 = V_41 -> V_45 ;
V_45 -> V_58 = V_59 ;
V_45 -> V_37 = V_11 -> V_37 ;
V_47 = & V_45 -> V_2 ;
}
V_26 = F_24 ( NULL , V_48 ,
V_50 , V_30 ,
V_47 , & V_60 ,
& V_11 -> V_2 , & V_61 ,
V_46 , & V_62 , 0 ) ;
if ( ! F_25 ( V_26 ) ) {
F_26 ( V_39 , V_63 , V_26 ) ;
F_27 ( V_26 , V_48 , NULL ) ;
}
return V_26 ;
}
