static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = 1 , V_5 = 0 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_13 ;
V_8 = F_3 ( V_11 -> V_8 ) ;
if ( V_13 -> V_14 != V_15 )
V_4 = F_4 ( V_13 -> V_16 , V_13 -> V_14 , V_8 ) ;
if ( V_13 -> V_17 != V_15 )
V_5 = F_4 ( V_13 -> V_18 , V_13 -> V_17 , V_8 ) ;
if ( V_13 -> V_19 != V_15 )
V_7 = F_4 ( V_13 -> V_20 , V_13 -> V_19 , V_8 ) ;
if ( V_13 -> V_21 != V_15 )
V_6 = F_4 ( V_13 -> V_22 , V_13 -> V_21 , V_8 ) ;
if ( V_11 -> V_23 ) {
struct V_24 V_25 = {
. V_3 = V_3 ,
. V_4 = V_4 ,
. V_5 = V_5 ,
. V_7 = V_7 ,
. V_6 = V_6 ,
} ;
if ( V_11 -> V_26 )
V_25 . V_27 =
( V_8 >> V_11 -> V_26 -> V_28 ) &
V_11 -> V_26 -> V_29 ;
V_11 -> V_23 ( & V_25 ) ;
return V_25 . V_9 ;
}
V_9 = ( V_3 * ( V_4 + V_13 -> V_30 ) * ( V_5 + 1 ) >> V_6 ) / ( V_7 + 1 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_1 * V_33 , * V_34 = NULL ;
int V_35 , V_36 ;
unsigned long V_3 , V_37 = 0 , V_38 , V_39 = 0 ;
V_36 = F_6 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
struct V_24 V_25 = {
. V_9 = V_32 -> V_9 ,
. V_27 = V_35 ,
} ;
V_33 = F_7 ( V_2 , V_35 ) ;
if ( ! V_33 )
continue;
if ( F_8 ( V_2 ) & V_40 )
V_3 = F_9 ( V_33 , V_32 -> V_9 ) ;
else
V_3 = F_10 ( V_33 ) ;
V_25 . V_3 = V_3 ;
V_11 -> V_41 ( & V_25 ) ;
V_38 = V_25 . V_9 ;
if ( V_38 <= V_32 -> V_9 && V_38 > V_39 ) {
V_34 = V_33 ;
V_37 = V_3 ;
V_39 = V_38 ;
}
}
if ( ! V_34 )
return - V_42 ;
V_32 -> V_43 = V_34 ;
V_32 -> V_44 = V_37 ;
V_32 -> V_9 = V_39 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_24 V_32 = {
. V_9 = V_9 ,
. V_3 = V_3 ,
} ;
T_2 V_8 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_45 = 0 ;
V_11 -> V_41 ( & V_32 ) ;
if ( V_11 -> V_46 )
F_12 ( V_11 -> V_46 , V_45 ) ;
V_8 = F_3 ( V_11 -> V_8 ) ;
V_8 = F_13 ( V_13 -> V_16 , V_13 -> V_14 , V_8 , V_32 . V_4 ) ;
V_8 = F_13 ( V_13 -> V_18 , V_13 -> V_17 , V_8 , V_32 . V_5 ) ;
V_8 = F_13 ( V_13 -> V_20 , V_13 -> V_19 , V_8 , V_32 . V_7 ) ;
V_8 = F_13 ( V_13 -> V_22 , V_13 -> V_21 , V_8 , V_32 . V_6 ) ;
F_14 ( V_8 , V_11 -> V_8 ) ;
F_15 ( ( V_9 >> 20 ) * 500 / 2 ) ;
if ( V_11 -> V_46 )
F_16 ( V_11 -> V_46 , V_45 ) ;
return 0 ;
}
struct V_47 * F_17 ( struct V_48 * V_49 ,
const struct V_50 * V_51 ,
T_3 * V_46 ,
void T_4 * V_8 )
{
struct V_47 * V_47 ;
struct V_10 * V_11 ;
struct V_52 * V_53 = NULL ;
struct V_54 * V_26 = NULL ;
struct V_1 * V_55 = NULL ;
struct V_1 * V_56 = NULL ;
const char * V_57 = V_49 -> V_58 ;
const char * V_59 [ V_60 ] ;
int V_61 , V_35 = 0 ;
V_35 = F_18 ( V_49 , V_59 , V_60 ) ;
if ( V_51 -> V_58 )
V_57 = V_51 -> V_58 ;
else
F_19 ( V_49 , L_1 , & V_57 ) ;
V_11 = F_20 ( sizeof( struct V_10 ) , V_62 ) ;
if ( ! V_11 )
goto V_63;
V_11 -> V_8 = V_8 ;
V_11 -> V_13 = V_51 -> V_64 ;
V_11 -> V_41 = V_51 -> V_65 ;
V_11 -> V_23 = V_51 -> V_23 ;
V_11 -> V_46 = V_46 ;
if ( V_51 -> V_66 ) {
V_53 = F_20 ( sizeof( struct V_52 ) , V_62 ) ;
if ( ! V_53 )
goto V_67;
V_11 -> V_53 = V_53 ;
V_53 -> V_8 = V_8 ;
V_53 -> V_68 = V_51 -> V_66 ;
V_53 -> V_46 = V_11 -> V_46 ;
V_55 = & V_53 -> V_2 ;
}
if ( V_51 -> V_26 ) {
V_26 = F_20 ( sizeof( struct V_54 ) , V_62 ) ;
if ( ! V_26 )
goto V_69;
V_11 -> V_26 = V_26 ;
V_26 -> V_8 = V_8 ;
V_26 -> V_28 = V_51 -> V_26 ;
V_26 -> V_29 = V_51 -> V_70 ;
V_26 -> V_46 = V_11 -> V_46 ;
V_56 = & V_26 -> V_2 ;
}
V_47 = F_21 ( NULL , V_57 ,
V_59 , V_35 ,
V_56 , & V_71 ,
& V_11 -> V_2 , & V_72 ,
V_55 , & V_73 , 0 ) ;
if ( F_22 ( V_47 ) )
goto V_74;
V_61 = F_23 ( V_49 , V_75 , V_47 ) ;
if ( V_61 )
goto V_76;
return V_47 ;
V_76:
F_24 ( V_47 ) ;
V_74:
F_25 ( V_26 ) ;
V_69:
F_25 ( V_53 ) ;
V_67:
F_25 ( V_11 ) ;
V_63:
return NULL ;
}
void F_26 ( struct V_48 * V_49 , struct V_47 * V_47 )
{
struct V_1 * V_2 = F_27 ( V_47 ) ;
struct V_10 * V_11 ;
const char * V_58 ;
if ( ! V_2 )
return;
V_11 = F_2 ( V_2 ) ;
V_58 = F_28 ( V_2 ) ;
F_29 ( V_49 ) ;
F_24 ( V_47 ) ;
F_25 ( V_11 -> V_26 ) ;
F_25 ( V_11 -> V_53 ) ;
F_25 ( V_11 ) ;
}
