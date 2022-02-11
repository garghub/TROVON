static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned long V_14 = ( unsigned long ) V_4 -> V_15 ;
unsigned int V_16 = F_4 ( V_6 -> V_17 ) ;
unsigned int V_18 ;
int V_19 ;
int V_20 ;
V_18 = F_5 ( V_16 ) | F_6 ( V_16 ) | V_14 ;
F_7 ( 0 , V_2 -> V_9 + V_10 ) ;
for ( V_20 = 0 ; V_20 < V_6 -> V_21 ; ++ V_20 ) {
unsigned int V_22 = V_13 [ V_20 ] ;
V_19 = F_8 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_19 )
return V_19 ;
F_7 ( V_18 | F_9 ( V_22 ) ,
V_2 -> V_9 + V_23 ) ;
V_4 -> V_24 [ V_16 ] = V_22 ;
}
return V_6 -> V_21 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_28 ;
int V_19 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_9 = F_13 ( V_27 , 2 ) ;
V_28 = F_2 ( V_2 -> V_9 + V_29 ) ;
F_14 ( V_2 -> V_30 , L_1 ,
V_28 & V_31 ) ;
V_19 = F_15 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_32 [ 0 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 | V_37 ;
V_4 -> V_38 = 32 ;
V_4 -> V_39 = 0x3fff ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_42 = F_3 ;
V_4 -> V_15 = ( void * ) V_43 ;
V_19 = F_16 ( V_4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_32 [ 1 ] ;
V_4 -> type = V_44 ;
V_4 -> V_34 = V_35 | V_36 | V_45 ;
V_4 -> V_38 = 32 ;
V_4 -> V_39 = 0x3fff ;
V_4 -> V_42 = F_3 ;
V_4 -> V_15 = ( void * ) V_46 ;
V_19 = F_16 ( V_4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_32 [ 2 ] ;
V_4 -> type = V_44 ;
V_4 -> V_34 = V_35 | V_36 | V_45 ;
V_4 -> V_38 = 32 ;
V_4 -> V_39 = 0x3fff ;
V_4 -> V_42 = F_3 ;
V_4 -> V_15 = ( void * ) V_47 ;
return F_16 ( V_4 ) ;
}
static int F_17 ( struct V_26 * V_2 ,
const struct V_48 * V_49 )
{
return F_18 ( V_2 , & V_50 ,
V_49 -> V_51 ) ;
}
