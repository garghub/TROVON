static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 ,
T_4 * V_4 )
{
T_4 V_5 = * V_4 ;
T_4 V_6 = F_2 ( V_1 ) -> V_7 ;
unsigned int V_8 = ( V_9 ) V_1 -> V_10 & 3 ;
struct V_11 * V_12 = V_1 -> V_10 - V_8 ;
T_5 * V_13 ;
int V_14 ;
if ( V_5 < 0 )
return - V_15 ;
if ( V_5 >= V_6 )
return 0 ;
if ( V_3 > V_6 - V_5 )
V_3 = V_6 - V_5 ;
V_13 = F_3 ( V_3 ) ;
if ( ! V_13 )
return - V_16 ;
F_4 ( & V_12 -> V_17 ) ;
V_14 = F_5 ( V_12 , 0 , V_8 , V_5 , V_3 , V_13 , V_18 ) ;
F_6 ( & V_12 -> V_17 ) ;
if ( V_14 ) {
F_7 ( V_13 ) ;
return V_14 ;
}
V_14 = F_8 ( V_2 , V_13 , V_3 ) ;
F_7 ( V_13 ) ;
if ( V_14 )
return - V_19 ;
* V_4 = V_5 + V_3 ;
return V_3 ;
}
static void F_9 ( struct V_11 * V_12 , const char * V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
struct V_23 * V_24 ;
V_24 = F_10 ( V_20 , V_25 , V_12 -> V_26 ,
( void * ) V_12 + V_21 , & V_27 ) ;
if ( V_24 && V_24 -> V_28 )
V_24 -> V_28 -> V_7 = V_22 << 20 ;
}
void F_11 ( struct V_11 * V_12 ,
struct V_29 * V_30 ,
unsigned int V_31 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ )
F_10 ( V_30 [ V_32 ] . V_20 , V_30 [ V_32 ] . V_33 ,
V_12 -> V_26 ,
( void * ) V_12 + V_30 [ V_32 ] . V_13 ,
V_30 [ V_32 ] . V_34 ) ;
}
int F_12 ( struct V_11 * V_12 )
{
int V_32 ;
T_6 V_35 ;
static struct V_29 V_36 [] = {
{ L_1 , & V_37 , V_25 , 0 } ,
} ;
F_11 ( V_12 ,
V_36 ,
F_13 ( V_36 ) ) ;
V_32 = F_14 ( V_12 , V_38 ) ;
if ( V_32 & V_39 ) {
V_35 = F_14 ( V_12 , V_40 ) ;
F_9 ( V_12 , L_2 , V_41 , F_15 ( V_35 ) ) ;
}
if ( V_32 & V_42 ) {
V_35 = F_14 ( V_12 , V_43 ) ;
F_9 ( V_12 , L_3 , V_44 , F_16 ( V_35 ) ) ;
}
if ( F_17 ( V_12 -> V_45 . V_46 ) ) {
V_35 = F_14 ( V_12 , V_47 ) ;
if ( V_32 & V_48 )
F_9 ( V_12 , L_4 , V_49 ,
F_18 ( V_35 ) ) ;
} else {
if ( V_32 & V_50 ) {
V_35 = F_14 ( V_12 , V_51 ) ;
F_9 ( V_12 , L_5 , V_52 ,
F_19 ( V_35 ) ) ;
}
if ( V_32 & V_53 ) {
V_35 = F_14 ( V_12 , V_54 ) ;
F_9 ( V_12 , L_6 , V_55 ,
F_20 ( V_35 ) ) ;
}
}
return 0 ;
}
