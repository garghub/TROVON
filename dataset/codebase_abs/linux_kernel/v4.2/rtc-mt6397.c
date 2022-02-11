static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
int V_6 ;
T_1 V_7 ;
V_6 = F_2 ( V_2 -> V_8 , V_2 -> V_9 + V_10 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
while ( 1 ) {
V_6 = F_3 ( V_2 -> V_8 , V_2 -> V_9 + V_11 ,
& V_7 ) ;
if ( V_6 < 0 )
break;
if ( ! ( V_7 & V_12 ) )
break;
if ( F_4 ( V_4 , V_3 ) ) {
V_6 = - V_13 ;
break;
}
F_5 () ;
}
return V_6 ;
}
static T_2 F_6 ( int V_14 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_15 , V_16 ;
int V_6 ;
V_6 = F_3 ( V_2 -> V_8 , V_2 -> V_9 + V_17 , & V_15 ) ;
if ( ( V_6 >= 0 ) && ( V_15 & V_18 ) ) {
F_7 ( V_2 -> V_19 , 1 , V_20 | V_21 ) ;
V_16 = V_15 & ~ V_22 ;
F_8 ( & V_2 -> V_23 ) ;
if ( F_2 ( V_2 -> V_8 , V_2 -> V_9 + V_24 ,
V_16 ) < 0 )
F_1 ( V_2 ) ;
F_9 ( & V_2 -> V_23 ) ;
return V_25 ;
}
return V_26 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int * V_29 )
{
int V_6 ;
T_3 V_7 [ V_30 ] ;
F_8 ( & V_2 -> V_23 ) ;
V_6 = F_11 ( V_2 -> V_8 , V_2 -> V_9 + V_31 ,
V_7 , V_30 ) ;
if ( V_6 < 0 )
goto exit;
V_28 -> V_32 = V_7 [ V_33 ] ;
V_28 -> V_34 = V_7 [ V_35 ] ;
V_28 -> V_36 = V_7 [ V_37 ] ;
V_28 -> V_38 = V_7 [ V_39 ] ;
V_28 -> V_40 = V_7 [ V_41 ] ;
V_28 -> V_42 = V_7 [ V_43 ] ;
V_6 = F_3 ( V_2 -> V_8 , V_2 -> V_9 + V_31 , V_29 ) ;
exit:
F_9 ( & V_2 -> V_23 ) ;
return V_6 ;
}
static int F_12 ( struct V_44 * V_45 , struct V_27 * V_28 )
{
T_4 time ;
struct V_1 * V_2 = F_13 ( V_45 ) ;
int V_46 , V_29 , V_6 ;
do {
V_6 = F_10 ( V_2 , V_28 , & V_29 ) ;
if ( V_6 < 0 )
goto exit;
} while ( V_29 < V_28 -> V_32 );
V_28 -> V_42 += V_47 ;
V_28 -> V_40 -- ;
time = F_14 ( V_28 ) ;
V_46 = F_15 ( time , 86400 ) ;
V_28 -> V_48 = ( V_46 + 4 ) % 7 ;
exit:
return V_6 ;
}
static int F_16 ( struct V_44 * V_45 , struct V_27 * V_28 )
{
struct V_1 * V_2 = F_13 ( V_45 ) ;
int V_6 ;
T_3 V_7 [ V_30 ] ;
V_28 -> V_42 -= V_47 ;
V_28 -> V_40 ++ ;
V_7 [ V_33 ] = V_28 -> V_32 ;
V_7 [ V_35 ] = V_28 -> V_34 ;
V_7 [ V_37 ] = V_28 -> V_36 ;
V_7 [ V_39 ] = V_28 -> V_38 ;
V_7 [ V_41 ] = V_28 -> V_40 ;
V_7 [ V_43 ] = V_28 -> V_42 ;
F_8 ( & V_2 -> V_23 ) ;
V_6 = F_17 ( V_2 -> V_8 , V_2 -> V_9 + V_31 ,
V_7 , V_30 ) ;
if ( V_6 < 0 )
goto exit;
V_6 = F_1 ( V_2 ) ;
exit:
F_9 ( & V_2 -> V_23 ) ;
return V_6 ;
}
static int F_18 ( struct V_44 * V_45 , struct V_49 * V_50 )
{
struct V_27 * V_28 = & V_50 -> time ;
struct V_1 * V_2 = F_13 ( V_45 ) ;
T_1 V_16 , V_51 ;
int V_6 ;
T_3 V_7 [ V_30 ] ;
F_8 ( & V_2 -> V_23 ) ;
V_6 = F_3 ( V_2 -> V_8 , V_2 -> V_9 + V_24 , & V_16 ) ;
if ( V_6 < 0 )
goto V_52;
V_6 = F_3 ( V_2 -> V_8 , V_2 -> V_9 + V_53 , & V_51 ) ;
if ( V_6 < 0 )
goto V_52;
V_6 = F_11 ( V_2 -> V_8 , V_2 -> V_9 + V_54 ,
V_7 , V_30 ) ;
if ( V_6 < 0 )
goto V_52;
V_50 -> V_55 = ! ! ( V_16 & V_22 ) ;
V_50 -> V_56 = ! ! ( V_51 & V_57 ) ;
F_9 ( & V_2 -> V_23 ) ;
V_28 -> V_32 = V_7 [ V_33 ] ;
V_28 -> V_34 = V_7 [ V_35 ] ;
V_28 -> V_36 = V_7 [ V_37 ] ;
V_28 -> V_38 = V_7 [ V_39 ] ;
V_28 -> V_40 = V_7 [ V_41 ] ;
V_28 -> V_42 = V_7 [ V_43 ] ;
V_28 -> V_42 += V_47 ;
V_28 -> V_40 -- ;
return 0 ;
V_52:
F_9 ( & V_2 -> V_23 ) ;
return V_6 ;
}
static int F_19 ( struct V_44 * V_45 , struct V_49 * V_50 )
{
struct V_27 * V_28 = & V_50 -> time ;
struct V_1 * V_2 = F_13 ( V_45 ) ;
int V_6 ;
T_3 V_7 [ V_30 ] ;
V_28 -> V_42 -= V_47 ;
V_28 -> V_40 ++ ;
V_7 [ V_33 ] = V_28 -> V_32 ;
V_7 [ V_35 ] = V_28 -> V_34 ;
V_7 [ V_37 ] = V_28 -> V_36 ;
V_7 [ V_39 ] = V_28 -> V_38 ;
V_7 [ V_41 ] = V_28 -> V_40 ;
V_7 [ V_43 ] = V_28 -> V_42 ;
F_8 ( & V_2 -> V_23 ) ;
if ( V_50 -> V_55 ) {
V_6 = F_17 ( V_2 -> V_8 ,
V_2 -> V_9 + V_54 ,
V_7 , V_30 ) ;
if ( V_6 < 0 )
goto exit;
V_6 = F_2 ( V_2 -> V_8 , V_2 -> V_9 + V_58 ,
V_59 ) ;
if ( V_6 < 0 )
goto exit;
V_6 = F_20 ( V_2 -> V_8 ,
V_2 -> V_9 + V_24 ,
V_60 ,
V_60 ) ;
if ( V_6 < 0 )
goto exit;
} else {
V_6 = F_20 ( V_2 -> V_8 ,
V_2 -> V_9 + V_24 ,
V_60 , 0 ) ;
if ( V_6 < 0 )
goto exit;
}
V_6 = F_1 ( V_2 ) ;
exit:
F_9 ( & V_2 -> V_23 ) ;
return V_6 ;
}
static int F_21 ( struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_65 * V_65 = F_13 ( V_62 -> V_45 . V_66 ) ;
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_22 ( & V_62 -> V_45 , sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_64 = F_23 ( V_62 , V_69 , 0 ) ;
V_2 -> V_9 = V_64 -> V_70 ;
V_64 = F_23 ( V_62 , V_71 , 0 ) ;
V_2 -> V_14 = F_24 ( V_65 -> V_72 , V_64 -> V_70 ) ;
if ( V_2 -> V_14 <= 0 )
return - V_73 ;
V_2 -> V_8 = V_65 -> V_8 ;
V_2 -> V_45 = & V_62 -> V_45 ;
F_25 ( & V_2 -> V_23 ) ;
F_26 ( V_62 , V_2 ) ;
V_6 = F_27 ( V_2 -> V_14 , NULL ,
F_6 ,
V_74 | V_75 ,
L_1 , V_2 ) ;
if ( V_6 ) {
F_28 ( & V_62 -> V_45 , L_2 ,
V_2 -> V_14 , V_6 ) ;
goto V_76;
}
F_29 ( & V_62 -> V_45 , 1 ) ;
V_2 -> V_19 = F_30 ( L_1 , & V_62 -> V_45 ,
& V_77 , V_78 ) ;
if ( F_31 ( V_2 -> V_19 ) ) {
F_28 ( & V_62 -> V_45 , L_3 ) ;
V_6 = F_32 ( V_2 -> V_19 ) ;
goto V_79;
}
return 0 ;
V_79:
F_33 ( V_2 -> V_14 , V_2 -> V_19 ) ;
V_76:
F_34 ( V_2 -> V_14 ) ;
return V_6 ;
}
static int F_35 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_36 ( V_62 ) ;
F_37 ( V_2 -> V_19 ) ;
F_33 ( V_2 -> V_14 , V_2 -> V_19 ) ;
F_34 ( V_2 -> V_14 ) ;
return 0 ;
}
