static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 , V_7 , V_8 ;
unsigned long long V_9 ;
V_8 = F_3 ( V_5 -> V_10 . V_8 + 0x4 ) ;
V_6 = ( V_8 & V_11 ) >> V_12 ;
V_7 = ( V_8 & V_13 ) >> V_14 ;
V_9 = ( unsigned long long ) V_3 * ( V_6 + 1 ) ;
F_4 ( V_9 , ( 1 + V_7 ) ) ;
return ( unsigned long ) V_9 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_15 ;
V_15 = F_3 ( V_5 -> V_10 . V_8 ) ;
return ( V_15 >> V_16 ) &
V_17 ;
}
static struct V_18 T_3 * F_6 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
T_2 V_8 ;
struct T_3 * T_3 ;
struct V_4 * V_23 ;
const char * V_24 = V_20 -> V_25 ;
const char * V_26 [ V_27 ] ;
struct V_28 V_29 ;
struct V_19 * V_30 ;
int V_31 ;
int V_32 = 0 ;
F_7 ( V_20 , L_1 , & V_8 ) ;
V_23 = F_8 ( sizeof( * V_23 ) , V_33 ) ;
if ( F_9 ( ! V_23 ) )
return NULL ;
V_30 = F_10 ( NULL , NULL , L_2 ) ;
V_34 = F_11 ( V_30 , 0 ) ;
F_12 ( ! V_34 ) ;
V_23 -> V_10 . V_8 = V_34 + V_8 ;
F_13 ( V_20 , L_3 , & V_24 ) ;
V_29 . V_25 = V_24 ;
V_29 . V_22 = V_22 ;
V_29 . V_35 = 0 ;
while ( V_32 < V_27 && ( V_26 [ V_32 ] =
F_14 ( V_20 , V_32 ) ) != NULL )
V_32 ++ ;
V_29 . V_36 = V_32 ;
V_29 . V_37 = V_26 ;
V_23 -> V_10 . V_10 . V_29 = & V_29 ;
V_23 -> V_10 . V_38 = V_39 ;
V_40 . V_41 = V_42 . V_41 ;
V_40 . V_43 = V_42 . V_43 ;
T_3 = F_15 ( NULL , & V_23 -> V_10 . V_10 ) ;
if ( F_9 ( F_16 ( T_3 ) ) ) {
F_17 ( V_23 ) ;
return NULL ;
}
V_31 = F_18 ( V_20 , V_44 , T_3 ) ;
return T_3 ;
}
void V_18 F_19 ( struct V_19 * V_20 )
{
F_6 ( V_20 , & V_40 ) ;
}
