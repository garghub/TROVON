static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 * V_7 ;
int V_8 ;
if ( ! V_5 )
return 0 ;
if ( ! V_5 -> V_9 )
return F_2 ( V_2 , L_1 ) ;
F_2 ( V_2 , L_2 , V_5 -> V_9 ) ;
F_2 ( V_2 , L_3 , V_5 -> V_10 ) ;
F_2 ( V_2 , L_4 , V_5 -> V_9 -> V_11 ) ;
F_2 ( V_2 , L_5 , V_5 -> V_9 -> V_12 ) ;
V_7 = ( T_1 * ) & V_5 -> V_9 -> V_13 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_2 ( V_2 , L_6 ,
V_14 [ V_8 ] , * ( V_7 + V_8 ) ) ;
if ( V_5 -> V_9 -> V_15 )
for ( V_8 = 4 ; V_8 < 6 ; V_8 ++ )
F_2 ( V_2 , L_6 ,
V_14 [ V_8 ] , * ( V_7 + V_8 ) ) ;
for ( V_8 = 6 ; V_8 < F_3 ( V_14 ) ; V_8 ++ )
F_2 ( V_2 , L_6 ,
V_14 [ V_8 ] ,
F_4 ( ( V_16 * ) ( V_7 + V_8 ) ) ) ;
return 0 ;
}
static T_2 F_5 ( struct V_17 * V_17 , const char T_3 * V_18 ,
T_4 V_19 , T_5 * V_20 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_17 -> V_21 ) -> V_6 ;
unsigned long V_22 ;
int V_23 ;
if ( ! V_5 )
return 0 ;
V_23 = F_6 ( V_18 , V_19 , 10 , & V_22 ) ;
if ( V_23 )
return V_23 ;
switch ( V_22 ) {
case 0 :
V_23 = F_7 ( V_5 ) ;
if ( V_23 )
return V_23 ;
break;
case 1 :
V_23 = F_8 ( V_5 ) ;
if ( V_23 )
return V_23 ;
break;
}
return V_19 ;
}
static int F_9 ( struct V_24 * V_24 , struct V_17 * V_25 )
{
return F_10 ( V_25 , F_1 ,
F_11 ( V_25 ) -> V_26 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
V_5 -> V_27 = F_13 ( F_14 ( & V_5 -> V_28 -> V_29 ) ,
V_30 ) ;
if ( F_15 ( V_5 -> V_27 ) )
V_5 -> V_27 = NULL ;
V_5 -> V_31 = F_16 ( L_7 ,
V_32 | V_33 | V_34 ,
V_5 -> V_27 , V_5 ,
& V_35 ) ;
if ( F_15 ( V_5 -> V_31 ) )
V_5 -> V_31 = NULL ;
}
void F_17 ( struct V_4 * V_5 )
{
F_18 ( V_5 -> V_31 ) ;
F_18 ( V_5 -> V_27 ) ;
}
int T_6 F_19 ( void )
{
V_36 = F_20 ( L_8 , 8 , 1 , 8 * sizeof( long ) ) ;
if ( ! V_36 )
return - V_37 ;
F_21 ( V_36 , & V_38 ) ;
F_22 ( V_36 , 3 ) ;
V_39 = F_20 ( L_9 , 2 , 1 , 16 ) ;
if ( ! V_39 )
return - V_37 ;
F_21 ( V_39 , & V_40 ) ;
F_22 ( V_39 , 6 ) ;
V_30 = F_13 ( L_10 , NULL ) ;
return 0 ;
}
void F_23 ( void )
{
F_24 ( V_36 ) ;
F_24 ( V_39 ) ;
F_18 ( V_30 ) ;
}
