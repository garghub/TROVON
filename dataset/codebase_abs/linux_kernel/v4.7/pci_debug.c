static void F_1 ( struct V_1 * V_2 , char * V_3 [] , int V_4 ,
T_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ , V_5 ++ )
F_2 ( V_2 , L_1 , V_3 [ V_6 ] , * V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 * V_10 = & V_8 -> V_11 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_12 ) ; V_6 ++ , V_10 ++ )
F_2 ( V_2 , L_1 , V_12 [ V_6 ] ,
F_5 ( V_10 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_13 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! V_8 )
return 0 ;
F_7 ( & V_8 -> V_14 ) ;
if ( ! V_8 -> V_15 ) {
F_8 ( & V_8 -> V_14 ) ;
F_9 ( V_2 , L_2 ) ;
return 0 ;
}
F_2 ( V_2 , L_3 , V_8 -> V_15 ) ;
F_2 ( V_2 , L_4 , V_8 -> V_16 ) ;
F_2 ( V_2 , L_5 , V_8 -> V_15 -> V_17 ) ;
F_2 ( V_2 , L_6 , V_8 -> V_15 -> V_18 ) ;
F_1 ( V_2 , V_19 , F_4 ( V_19 ) ,
& V_8 -> V_15 -> V_20 ) ;
switch ( V_8 -> V_15 -> V_21 ) {
case 0 :
if ( ! ( V_8 -> V_15 -> V_22 & V_23 ) )
break;
F_1 ( V_2 , V_24 , F_4 ( V_24 ) ,
& V_8 -> V_15 -> V_25 . V_26 ) ;
break;
case 1 :
F_1 ( V_2 , V_27 , F_4 ( V_27 ) ,
& V_8 -> V_15 -> V_28 . V_29 ) ;
break;
case 2 :
F_1 ( V_2 , V_30 , F_4 ( V_30 ) ,
& V_8 -> V_15 -> V_31 . V_32 ) ;
break;
default:
F_9 ( V_2 , L_7 ) ;
}
F_3 ( V_2 ) ;
F_8 ( & V_8 -> V_14 ) ;
return 0 ;
}
static T_3 F_10 ( struct V_33 * V_33 , const char T_4 * V_34 ,
T_5 V_35 , T_6 * V_36 )
{
struct V_7 * V_8 = ( (struct V_1 * ) V_33 -> V_37 ) -> V_9 ;
unsigned long V_38 ;
int V_39 ;
if ( ! V_8 )
return 0 ;
V_39 = F_11 ( V_34 , V_35 , 10 , & V_38 ) ;
if ( V_39 )
return V_39 ;
F_7 ( & V_8 -> V_14 ) ;
switch ( V_38 ) {
case 0 :
V_39 = F_12 ( V_8 ) ;
break;
case 1 :
V_39 = F_13 ( V_8 ) ;
break;
}
F_8 ( & V_8 -> V_14 ) ;
return V_39 ? V_39 : V_35 ;
}
static int F_14 ( struct V_40 * V_40 , struct V_33 * V_41 )
{
return F_15 ( V_41 , F_6 ,
F_16 ( V_41 ) -> V_42 ) ;
}
void F_17 ( struct V_7 * V_8 , const char * V_3 )
{
V_8 -> V_43 = F_18 ( V_3 , V_44 ) ;
if ( F_19 ( V_8 -> V_43 ) )
V_8 -> V_43 = NULL ;
V_8 -> V_45 = F_20 ( L_8 ,
V_46 | V_47 | V_48 ,
V_8 -> V_43 , V_8 ,
& V_49 ) ;
if ( F_19 ( V_8 -> V_45 ) )
V_8 -> V_45 = NULL ;
}
void F_21 ( struct V_7 * V_8 )
{
F_22 ( V_8 -> V_45 ) ;
F_22 ( V_8 -> V_43 ) ;
}
int T_7 F_23 ( void )
{
V_50 = F_24 ( L_9 , 8 , 1 , 8 * sizeof( long ) ) ;
if ( ! V_50 )
return - V_51 ;
F_25 ( V_50 , & V_52 ) ;
F_26 ( V_50 , 3 ) ;
V_53 = F_24 ( L_10 , 2 , 1 , 16 ) ;
if ( ! V_53 )
return - V_51 ;
F_25 ( V_53 , & V_54 ) ;
F_26 ( V_53 , 6 ) ;
V_44 = F_18 ( L_11 , NULL ) ;
return 0 ;
}
void F_27 ( void )
{
F_28 ( V_50 ) ;
F_28 ( V_53 ) ;
F_22 ( V_44 ) ;
}
