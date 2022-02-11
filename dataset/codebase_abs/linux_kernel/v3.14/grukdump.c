static int F_1 ( void T_1 * * V_1 , void * V_2 )
{
if ( F_2 ( * V_1 , V_2 , V_3 ) )
return - 1 ;
* V_1 += V_3 ;
return 0 ;
}
static int F_3 ( void * V_4 ,
struct V_5 * V_6 ,
void T_1 * V_7 , int V_8 , int V_9 ,
int V_10 )
{
void * V_11 , * V_12 , * V_13 , * V_14 ;
int V_15 , V_16 ;
V_14 = V_4 + V_8 * V_17 ;
V_11 = V_14 + V_18 ;
V_12 = V_4 + V_19 ;
V_13 = V_4 + V_20 ;
F_4 (i, &cch->cbr_allocation_map, scr) {
if ( V_10 )
F_5 ( V_11 ) ;
if ( F_1 ( & V_7 , V_11 ) )
goto V_21;
if ( F_1 ( & V_7 , V_13 + V_15 * V_22 ) )
goto V_21;
if ( F_1 ( & V_7 , V_12 + V_15 * V_22 ) )
goto V_21;
V_11 += V_22 ;
}
if ( V_9 )
memcpy ( V_7 , V_14 + V_23 , V_9 * V_22 ) ;
return 0 ;
V_21:
return - V_24 ;
}
static int F_6 ( struct V_25 * V_26 ,
void T_1 * V_7 , void T_1 * V_27 )
{
struct V_28 * V_29 ;
int V_15 , V_30 , V_31 ;
V_31 = V_32 * V_33 ;
if ( V_31 > V_27 - V_7 )
V_30 = - V_34 ;
for ( V_15 = 0 ; V_15 < V_32 ; V_15 ++ ) {
V_29 = F_7 ( V_26 -> V_35 , V_15 ) ;
if ( F_1 ( & V_7 , V_29 ) )
goto V_21;
}
return V_32 * V_33 ;
V_21:
return - V_24 ;
}
static int F_8 ( struct V_25 * V_26 ,
void T_1 * V_7 , void T_1 * V_27 )
{
struct V_36 * V_37 ;
int V_15 , V_30 , V_31 ;
V_31 = V_38 * V_33 ;
if ( V_31 > V_27 - V_7 )
V_30 = - V_34 ;
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
V_37 = F_9 ( V_26 -> V_35 , V_15 ) ;
if ( F_1 ( & V_7 , V_37 ) )
goto V_21;
}
return V_38 * V_33 ;
V_21:
return - V_24 ;
}
static int F_10 ( struct V_25 * V_26 , int V_8 ,
void T_1 * V_7 , void T_1 * V_27 , char V_39 ,
char V_40 , char V_10 )
{
struct V_41 V_42 ;
struct V_41 T_1 * V_43 = V_7 ;
struct V_5 * V_6 , * V_44 ;
struct V_45 * V_46 ;
int V_47 , V_48 , V_49 = 0 , V_9 = 0 , V_31 = 0 , V_30 = 0 ;
void * V_4 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_4 = V_26 -> V_35 ;
V_6 = F_11 ( V_4 , V_8 ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_48 = F_12 ( V_6 ) ;
if ( V_48 )
break;
F_13 ( 1 ) ;
}
V_7 += sizeof( V_42 ) ;
V_44 = V_7 ;
if ( F_1 ( & V_7 , V_6 ) ) {
if ( V_48 )
F_14 ( V_6 ) ;
return - V_24 ;
}
if ( V_48 )
V_44 -> V_51 = 0 ;
V_31 = sizeof( V_42 ) + V_33 ;
if ( V_48 || ! V_40 ) {
V_46 = V_26 -> V_52 [ V_8 ] ;
if ( V_46 && V_46 -> V_53 ) {
V_42 . V_54 = V_46 -> V_55 ;
V_42 . V_56 = V_46 -> V_53 -> V_57 ;
}
if ( V_6 -> V_58 != V_59 ) {
V_49 = F_15 ( V_6 -> V_60 ) *
V_61 ;
V_9 = V_39 ? F_16 ( V_6 -> V_62 ) *
V_63 : 0 ;
}
V_31 += ( 3 * V_49 + V_9 ) * V_33 ;
if ( V_31 > V_27 - V_7 )
V_30 = - V_34 ;
else
V_30 = F_3 ( V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 ) ;
}
if ( V_48 )
F_14 ( V_6 ) ;
if ( V_30 )
return V_30 ;
V_42 . V_64 = V_65 ;
V_42 . V_66 = V_26 -> V_67 ;
V_42 . V_8 = V_8 ;
V_42 . V_49 = V_49 ;
V_42 . V_9 = V_9 ;
V_42 . V_48 = V_48 ;
if ( ! V_30 && F_2 ( ( void T_1 * ) V_43 , & V_42 , sizeof( V_42 ) ) )
V_30 = - V_24 ;
return V_30 ? V_30 : V_31 ;
}
int F_17 ( unsigned long V_68 )
{
struct V_25 * V_26 ;
struct V_69 V_70 ;
void T_1 * V_7 ;
void T_1 * V_27 ;
int V_8 , V_30 , V_71 = 0 ;
if ( F_18 ( & V_70 , ( void T_1 * ) V_68 , sizeof( V_70 ) ) )
return - V_24 ;
if ( V_70 . V_66 >= V_72 || V_70 . V_66 < 0 )
return - V_73 ;
V_26 = F_19 ( V_70 . V_66 ) ;
V_7 = V_70 . V_74 ;
V_27 = V_70 . V_74 + V_70 . V_75 ;
V_30 = F_6 ( V_26 , V_7 , V_27 ) ;
if ( V_30 < 0 )
goto V_21;
V_7 += V_30 ;
V_30 = F_8 ( V_26 , V_7 , V_27 ) ;
if ( V_30 < 0 )
goto V_21;
V_7 += V_30 ;
for ( V_8 = 0 ; V_8 < V_76 ; V_8 ++ ) {
if ( V_70 . V_8 == V_8 || V_70 . V_8 < 0 ) {
V_30 = F_10 ( V_26 , V_8 , V_7 , V_27 ,
V_70 . V_39 , V_70 . V_40 ,
V_70 . V_10 ) ;
if ( V_30 < 0 )
goto V_21;
V_7 += V_30 ;
V_71 ++ ;
}
}
if ( F_2 ( ( void T_1 * ) V_68 , & V_70 , sizeof( V_70 ) ) )
return - V_24 ;
return V_71 ;
V_21:
return V_30 ;
}
