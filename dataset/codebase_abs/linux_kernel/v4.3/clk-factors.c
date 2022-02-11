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
static int F_6 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_1 * V_27 , * V_28 = NULL ;
int V_29 , V_30 ;
unsigned long V_3 , V_31 = 0 , V_32 , V_33 = 0 ;
V_30 = F_7 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_27 = F_8 ( V_2 , V_29 ) ;
if ( ! V_27 )
continue;
if ( F_9 ( V_2 ) & V_34 )
V_3 = F_10 ( V_27 , V_26 -> V_9 ) ;
else
V_3 = F_11 ( V_27 ) ;
V_32 = F_5 ( V_2 , V_26 -> V_9 ,
& V_3 ) ;
if ( V_32 <= V_26 -> V_9 && V_32 > V_33 ) {
V_28 = V_27 ;
V_31 = V_3 ;
V_33 = V_32 ;
}
}
if ( ! V_28 )
return - V_35 ;
V_26 -> V_36 = V_28 ;
V_26 -> V_37 = V_31 ;
V_26 -> V_9 = V_33 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
T_1 V_4 = 0 , V_5 = 0 , V_7 = 0 , V_6 = 0 ;
T_2 V_8 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_38 = 0 ;
V_11 -> V_24 ( ( T_2 * ) & V_9 , ( T_2 ) V_3 , & V_4 , & V_5 , & V_7 , & V_6 ) ;
if ( V_11 -> V_39 )
F_13 ( V_11 -> V_39 , V_38 ) ;
V_8 = F_3 ( V_11 -> V_8 ) ;
V_8 = F_14 ( V_13 -> V_16 , V_13 -> V_14 , V_8 , V_4 ) ;
V_8 = F_14 ( V_13 -> V_18 , V_13 -> V_17 , V_8 , V_5 ) ;
V_8 = F_14 ( V_13 -> V_20 , V_13 -> V_19 , V_8 , V_7 ) ;
V_8 = F_14 ( V_13 -> V_22 , V_13 -> V_21 , V_8 , V_6 ) ;
F_15 ( V_8 , V_11 -> V_8 ) ;
F_16 ( ( V_9 >> 20 ) * 500 / 2 ) ;
if ( V_11 -> V_39 )
F_17 ( V_11 -> V_39 , V_38 ) ;
return 0 ;
}
struct V_40 * F_18 ( struct V_41 * V_42 ,
const struct V_43 * V_44 ,
T_3 * V_39 ,
void T_4 * V_8 )
{
struct V_40 * V_40 ;
struct V_10 * V_11 ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 = NULL ;
struct V_1 * V_49 = NULL ;
struct V_1 * V_50 = NULL ;
const char * V_51 = V_42 -> V_52 ;
const char * V_53 [ V_54 ] ;
int V_29 = 0 ;
V_29 = F_19 ( V_42 , V_53 , V_54 ) ;
if ( V_44 -> V_52 )
V_51 = V_44 -> V_52 ;
else
F_20 ( V_42 , L_1 , & V_51 ) ;
V_11 = F_21 ( sizeof( struct V_10 ) , V_55 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_8 = V_8 ;
V_11 -> V_13 = V_44 -> V_56 ;
V_11 -> V_24 = V_44 -> V_57 ;
V_11 -> V_39 = V_39 ;
if ( V_44 -> V_58 ) {
V_46 = F_21 ( sizeof( struct V_45 ) , V_55 ) ;
if ( ! V_46 ) {
F_22 ( V_11 ) ;
return NULL ;
}
V_46 -> V_8 = V_8 ;
V_46 -> V_59 = V_44 -> V_58 ;
V_46 -> V_39 = V_11 -> V_39 ;
V_49 = & V_46 -> V_2 ;
}
if ( V_44 -> V_48 ) {
V_48 = F_21 ( sizeof( struct V_47 ) , V_55 ) ;
if ( ! V_48 ) {
F_22 ( V_11 ) ;
F_22 ( V_46 ) ;
return NULL ;
}
V_48 -> V_8 = V_8 ;
V_48 -> V_60 = V_44 -> V_48 ;
V_48 -> V_61 = V_44 -> V_62 ;
V_48 -> V_39 = V_11 -> V_39 ;
V_50 = & V_48 -> V_2 ;
}
V_40 = F_23 ( NULL , V_51 ,
V_53 , V_29 ,
V_50 , & V_63 ,
& V_11 -> V_2 , & V_64 ,
V_49 , & V_65 , 0 ) ;
if ( ! F_24 ( V_40 ) ) {
F_25 ( V_42 , V_66 , V_40 ) ;
F_26 ( V_40 , V_51 , NULL ) ;
}
return V_40 ;
}
