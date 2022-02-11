void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 ( & V_2 -> V_6 . V_7 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
V_4 = V_2 -> V_9 [ V_5 ] ;
if ( V_4 != NULL )
F_3 ( V_4 ) ;
}
F_4 ( V_2 -> V_10 ) ;
F_4 ( V_2 ) ;
}
struct V_1 *
F_5 ( struct V_11 * V_12 , struct V_13 * V_14 ,
T_1 V_15 )
{
int V_5 ;
T_2 V_16 , V_17 ;
T_3 * V_18 ;
T_4 * V_19 ;
T_3 * V_10 ;
T_3 V_20 ;
struct V_1 * V_2 = NULL ;
struct V_21 V_22 ;
struct V_23 V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
struct V_29 * V_30 ;
V_26 = F_6 ( V_15 ) ;
if ( ! V_26 )
goto V_31;
F_7 ( & V_22 , & V_24 , V_14 -> V_32 , V_14 -> V_33 ) ;
F_8 ( & V_22 , F_9 ( V_26 ) , V_34 ) ;
V_19 = F_10 ( & V_22 , 4 ) ;
if ( F_11 ( ! V_19 ) )
goto V_35;
V_16 = F_12 ( V_19 ) ;
F_13 ( L_1 , V_36 , V_16 ) ;
if ( V_16 > V_37 ) {
F_14 ( V_38 L_2
L_3 , V_36 ,
V_16 , V_37 ) ;
goto V_35;
}
V_10 = F_15 ( V_16 , sizeof( T_3 ) , V_15 ) ;
if ( ! V_10 )
goto V_35;
V_19 = F_10 ( & V_22 , V_16 << 2 ) ;
if ( F_11 ( ! V_19 ) )
goto V_39;
V_18 = & V_10 [ 0 ] ;
V_20 = 0 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ ) {
* V_18 = F_12 ( V_19 ++ ) ;
V_20 = F_16 ( V_20 , * V_18 ) ;
V_18 ++ ;
}
V_19 = F_10 ( & V_22 , 4 ) ;
if ( F_11 ( ! V_19 ) )
goto V_39;
V_17 = F_12 ( V_19 ) ;
F_13 ( L_4 , V_36 , V_17 ) ;
if ( V_17 > V_40 ) {
F_14 ( V_38 L_5
L_3 , V_36 ,
V_17 , V_40 ) ;
goto V_39;
}
if ( V_20 >= V_17 ) {
F_14 ( V_38 L_6 ,
V_36 , V_20 , V_17 ) ;
goto V_39;
}
V_2 = F_17 ( sizeof( * V_2 ) +
( sizeof( struct V_3 * ) * ( V_17 - 1 ) ) ,
V_15 ) ;
if ( ! V_2 )
goto V_39;
V_2 -> V_41 = V_16 ;
V_2 -> V_10 = V_10 ;
V_10 = NULL ;
V_2 -> V_8 = V_17 ;
F_18 ( & V_2 -> V_6 , V_12 , & V_14 -> V_42 ) ;
F_19 ( & V_28 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
int V_43 ;
T_2 V_44 ;
V_19 = F_10 ( & V_22 , 4 ) ;
if ( F_11 ( ! V_19 ) )
goto V_45;
V_44 = F_12 ( V_19 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_30 = F_20 ( V_12 -> V_46 -> V_47 ,
& V_22 , V_15 ) ;
if ( V_30 )
F_21 ( & V_30 -> V_48 , & V_28 ) ;
}
if ( F_22 ( & V_28 ) ) {
F_13 ( L_7 ,
V_36 ) ;
goto V_45;
}
V_2 -> V_9 [ V_5 ] = F_23 ( & V_28 , V_15 ) ;
if ( ! V_2 -> V_9 [ V_5 ] )
goto V_49;
while ( ! F_22 ( & V_28 ) ) {
V_30 = F_24 ( & V_28 ,
struct V_29 ,
V_48 ) ;
F_25 ( & V_30 -> V_48 ) ;
F_4 ( V_30 -> V_50 ) ;
F_4 ( V_30 ) ;
}
}
F_26 ( V_26 ) ;
return V_2 ;
V_49:
while ( ! F_22 ( & V_28 ) ) {
V_30 = F_24 ( & V_28 , struct V_29 ,
V_48 ) ;
F_25 ( & V_30 -> V_48 ) ;
F_4 ( V_30 -> V_50 ) ;
F_4 ( V_30 ) ;
}
V_45:
F_1 ( V_2 ) ;
goto V_35;
V_39:
F_4 ( V_10 ) ;
V_35:
F_26 ( V_26 ) ;
V_31:
F_13 ( L_8 , V_36 ) ;
return NULL ;
}
void
F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_6 ) ;
}
T_2
F_29 ( struct V_51 * V_52 , T_5 V_53 )
{
struct V_54 * V_55 = F_30 ( V_52 ) ;
T_6 V_56 ;
V_56 = V_53 - V_55 -> V_57 ;
F_31 ( V_56 , V_55 -> V_58 ) ;
V_56 += V_55 -> V_59 ;
return F_31 ( V_56 , V_55 -> V_2 -> V_41 ) ;
}
T_2
F_32 ( struct V_51 * V_52 , T_2 V_43 )
{
return F_30 ( V_52 ) -> V_2 -> V_10 [ V_43 ] ;
}
struct V_60 *
F_33 ( struct V_51 * V_52 , T_2 V_43 )
{
struct V_54 * V_55 = F_30 ( V_52 ) ;
T_2 V_5 ;
if ( V_55 -> V_61 == V_62 ) {
if ( V_55 -> V_63 == 1 )
V_5 = 0 ;
else if ( V_55 -> V_63 == 0 )
return NULL ;
else
V_5 = F_32 ( V_52 , V_43 ) ;
} else
V_5 = V_43 ;
return V_55 -> V_64 [ V_5 ] ;
}
struct V_3 *
F_34 ( struct V_51 * V_52 , T_2 V_65 )
{
struct V_1 * V_2 = F_30 ( V_52 ) -> V_2 ;
struct V_3 * V_4 = V_2 -> V_9 [ V_65 ] ;
struct V_66 * V_67 = F_35 ( V_52 ) ;
struct V_3 * V_68 = V_4 ;
struct V_11 * V_69 = F_36 ( V_52 -> V_70 -> V_71 ) ;
if ( V_4 == NULL ) {
F_14 ( V_72 L_9 ,
V_36 , V_65 ) ;
F_37 ( V_67 ) ;
goto V_73;
}
F_38 () ;
if ( V_4 -> V_74 )
goto V_75;
F_39 ( V_69 , V_4 , V_67 , V_76 ,
V_77 , 4 ,
V_69 -> V_46 -> V_78 ,
V_69 -> V_46 -> V_79 -> V_80 -> V_81 ) ;
V_75:
if ( F_40 ( V_67 ) )
V_68 = NULL ;
V_73:
return V_68 ;
}
