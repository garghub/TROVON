static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 * V_6 = & V_4 -> V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_2 ( V_9 ) ; V_8 ++ , V_6 ++ )
F_3 ( V_2 , L_1 , V_9 [ V_8 ] ,
F_4 ( V_6 ) ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 * V_11 ;
int V_8 ;
if ( ! V_4 )
return 0 ;
F_6 ( & V_4 -> V_12 ) ;
if ( ! V_4 -> V_13 ) {
F_7 ( & V_4 -> V_12 ) ;
F_8 ( V_2 , L_2 ) ;
return 0 ;
}
F_3 ( V_2 , L_3 , V_4 -> V_13 ) ;
F_3 ( V_2 , L_4 , V_4 -> V_14 ) ;
F_3 ( V_2 , L_5 , V_4 -> V_13 -> V_15 ) ;
F_3 ( V_2 , L_6 , V_4 -> V_13 -> V_16 ) ;
V_11 = ( T_2 * ) & V_4 -> V_13 -> V_17 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_3 ( V_2 , L_1 ,
V_18 [ V_8 ] , * ( V_11 + V_8 ) ) ;
if ( V_4 -> V_13 -> V_19 )
for ( V_8 = 4 ; V_8 < 6 ; V_8 ++ )
F_3 ( V_2 , L_1 ,
V_18 [ V_8 ] , * ( V_11 + V_8 ) ) ;
F_1 ( V_2 ) ;
F_7 ( & V_4 -> V_12 ) ;
return 0 ;
}
static T_3 F_9 ( struct V_20 * V_20 , const char T_4 * V_21 ,
T_5 V_22 , T_6 * V_23 )
{
struct V_3 * V_4 = ( (struct V_1 * ) V_20 -> V_24 ) -> V_5 ;
unsigned long V_25 ;
int V_26 ;
if ( ! V_4 )
return 0 ;
V_26 = F_10 ( V_21 , V_22 , 10 , & V_25 ) ;
if ( V_26 )
return V_26 ;
F_6 ( & V_4 -> V_12 ) ;
switch ( V_25 ) {
case 0 :
V_26 = F_11 ( V_4 ) ;
break;
case 1 :
V_26 = F_12 ( V_4 ) ;
break;
}
F_7 ( & V_4 -> V_12 ) ;
return V_26 ? V_26 : V_22 ;
}
static int F_13 ( struct V_27 * V_27 , struct V_20 * V_28 )
{
return F_14 ( V_28 , F_5 ,
F_15 ( V_28 ) -> V_29 ) ;
}
void F_16 ( struct V_3 * V_4 , const char * V_30 )
{
V_4 -> V_31 = F_17 ( V_30 , V_32 ) ;
if ( F_18 ( V_4 -> V_31 ) )
V_4 -> V_31 = NULL ;
V_4 -> V_33 = F_19 ( L_7 ,
V_34 | V_35 | V_36 ,
V_4 -> V_31 , V_4 ,
& V_37 ) ;
if ( F_18 ( V_4 -> V_33 ) )
V_4 -> V_33 = NULL ;
}
void F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 -> V_33 ) ;
F_21 ( V_4 -> V_31 ) ;
}
int T_7 F_22 ( void )
{
V_38 = F_23 ( L_8 , 8 , 1 , 8 * sizeof( long ) ) ;
if ( ! V_38 )
return - V_39 ;
F_24 ( V_38 , & V_40 ) ;
F_25 ( V_38 , 3 ) ;
V_41 = F_23 ( L_9 , 2 , 1 , 16 ) ;
if ( ! V_41 )
return - V_39 ;
F_24 ( V_41 , & V_42 ) ;
F_25 ( V_41 , 6 ) ;
V_32 = F_17 ( L_10 , NULL ) ;
return 0 ;
}
void F_26 ( void )
{
F_27 ( V_38 ) ;
F_27 ( V_41 ) ;
F_21 ( V_32 ) ;
}
