int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_11 ;
for (; V_4 ; V_4 = V_4 -> V_12 ) {
struct V_13 * V_14 ;
T_1 V_12 ;
int V_15 ;
if ( ( unsigned ) V_4 -> V_16 > V_7 -> V_17 . V_18 ) {
* V_5 = V_4 ;
V_11 = - V_19 ;
goto V_20;
}
F_3 ( & V_7 -> V_17 . V_21 , V_10 ) ;
V_9 = V_7 -> V_17 . V_9 ;
V_12 = V_9 -> V_22 + 1 ;
if ( V_12 >= V_7 -> V_17 . V_23 )
V_12 = 0 ;
if ( V_12 == V_9 -> V_24 ) {
F_4 ( & V_7 -> V_17 . V_21 , V_10 ) ;
* V_5 = V_4 ;
V_11 = - V_25 ;
goto V_20;
}
V_14 = F_5 ( & V_7 -> V_17 , V_9 -> V_22 ) ;
V_14 -> V_26 = V_4 -> V_26 ;
V_14 -> V_16 = V_4 -> V_16 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_16 ; V_15 ++ )
V_14 -> V_27 [ V_15 ] = V_4 -> V_27 [ V_15 ] ;
F_6 () ;
V_9 -> V_22 = V_12 ;
F_4 ( & V_7 -> V_17 . V_21 , V_10 ) ;
}
V_11 = 0 ;
V_20:
return V_11 ;
}
struct V_1 * F_7 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = F_8 ( V_29 -> V_36 ) ;
struct V_6 * V_7 ;
T_1 V_37 ;
struct V_1 * V_11 ;
if ( V_31 -> V_38 != V_39 ) {
V_11 = F_9 ( - V_40 ) ;
goto V_41;
}
if ( V_31 -> V_42 . V_43 == 0 ) {
V_11 = F_9 ( - V_19 ) ;
goto V_41;
}
if ( ( V_31 -> V_42 . V_18 > V_44 ) ||
( V_31 -> V_42 . V_43 > V_45 ) ) {
V_11 = F_9 ( - V_19 ) ;
goto V_41;
}
V_7 = F_10 ( sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 ) {
V_11 = F_9 ( - V_25 ) ;
goto V_41;
}
V_7 -> V_17 . V_23 = V_31 -> V_42 . V_43 + 1 ;
V_7 -> V_17 . V_18 = V_31 -> V_42 . V_18 ;
V_37 = sizeof( struct V_47 ) * V_7 -> V_17 . V_18 +
sizeof( struct V_13 ) ;
V_7 -> V_17 . V_9 = F_11 ( sizeof( struct V_8 ) + V_7 -> V_17 . V_23 * V_37 ) ;
if ( ! V_7 -> V_17 . V_9 ) {
V_11 = F_9 ( - V_25 ) ;
goto V_48;
}
if ( V_33 && V_33 -> V_49 >= sizeof( V_50 ) ) {
int V_51 ;
T_1 V_52 = sizeof( struct V_8 ) + V_7 -> V_17 . V_23 * V_37 ;
V_7 -> V_53 =
F_12 ( V_35 , V_52 ,
V_29 -> V_54 -> V_55 ,
V_7 -> V_17 . V_9 ) ;
if ( ! V_7 -> V_53 ) {
V_11 = F_9 ( - V_25 ) ;
goto V_56;
}
V_51 = F_13 ( V_33 , & V_7 -> V_53 -> V_57 ,
sizeof( V_7 -> V_53 -> V_57 ) ) ;
if ( V_51 ) {
V_11 = F_9 ( V_51 ) ;
goto V_58;
}
} else
V_7 -> V_53 = NULL ;
F_14 ( & V_7 -> V_17 . V_21 ) ;
V_7 -> V_17 . V_9 -> V_22 = 0 ;
V_7 -> V_17 . V_9 -> V_24 = 0 ;
V_7 -> V_59 = V_31 -> V_42 . V_60 ;
F_15 ( & V_35 -> V_61 ) ;
if ( V_35 -> V_62 == V_63 ) {
F_16 ( & V_35 -> V_61 ) ;
V_11 = F_9 ( - V_25 ) ;
goto V_58;
}
V_35 -> V_62 ++ ;
F_16 ( & V_35 -> V_61 ) ;
if ( V_7 -> V_53 ) {
F_17 ( & V_35 -> V_64 ) ;
F_18 ( & V_7 -> V_53 -> V_65 , & V_35 -> V_65 ) ;
F_19 ( & V_35 -> V_64 ) ;
}
V_11 = & V_7 -> V_2 ;
goto V_41;
V_58:
F_20 ( V_7 -> V_53 ) ;
V_56:
F_21 ( V_7 -> V_17 . V_9 ) ;
V_48:
F_20 ( V_7 ) ;
V_41:
return V_11 ;
}
int F_22 ( struct V_1 * V_2 , struct V_66 * V_42 ,
enum V_67 V_68 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
int V_11 = 0 ;
if ( V_68 & V_69 ) {
struct V_8 * V_70 ;
struct V_13 * V_71 ;
T_1 V_37 , V_23 , V_72 , V_22 , V_24 ;
if ( ( V_42 -> V_43 > V_45 ) ||
( ( V_68 & V_73 ) ?
V_42 -> V_60 : V_7 -> V_59 ) > V_42 -> V_43 ) {
V_11 = - V_19 ;
goto V_20;
}
V_37 = sizeof( struct V_13 ) +
V_7 -> V_17 . V_18 * sizeof( struct V_47 ) ;
V_23 = V_42 -> V_43 + 1 ;
V_9 = F_11 ( sizeof( struct V_8 ) + V_23 * V_37 ) ;
if ( ! V_9 ) {
V_11 = - V_25 ;
goto V_20;
}
if ( V_33 && V_33 -> V_74 >= sizeof( V_50 ) ) {
V_50 V_75 ;
V_50 V_57 = 0 ;
V_11 = F_23 ( & V_75 , V_33 ,
sizeof( V_75 ) ) ;
if ( V_11 )
goto V_76;
V_33 -> V_77 =
( void V_78 * ) ( unsigned long ) V_75 ;
V_11 = F_13 ( V_33 , & V_57 ,
sizeof( V_57 ) ) ;
if ( V_11 )
goto V_76;
}
F_17 ( & V_7 -> V_17 . V_21 ) ;
V_70 = V_7 -> V_17 . V_9 ;
V_22 = V_70 -> V_22 ;
if ( V_22 >= V_7 -> V_17 . V_23 )
V_22 = 0 ;
V_24 = V_70 -> V_24 ;
if ( V_24 >= V_7 -> V_17 . V_23 )
V_24 = 0 ;
V_72 = V_22 ;
if ( V_72 < V_24 )
V_72 += V_7 -> V_17 . V_23 - V_24 ;
else
V_72 -= V_24 ;
if ( V_23 <= V_72 ) {
V_11 = - V_19 ;
goto V_79;
}
V_72 = 0 ;
V_71 = V_9 -> V_9 ;
while ( V_24 != V_22 ) {
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_5 ( & V_7 -> V_17 , V_24 ) ;
V_71 -> V_26 = V_14 -> V_26 ;
V_71 -> V_16 = V_14 -> V_16 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_16 ; V_15 ++ )
V_71 -> V_27 [ V_15 ] = V_14 -> V_27 [ V_15 ] ;
V_72 ++ ;
V_71 = (struct V_13 * ) ( ( char * ) V_71 + V_37 ) ;
if ( ++ V_24 >= V_7 -> V_17 . V_23 )
V_24 = 0 ;
}
V_7 -> V_17 . V_9 = V_9 ;
V_7 -> V_17 . V_23 = V_23 ;
V_9 -> V_22 = V_72 ;
V_9 -> V_24 = 0 ;
if ( V_68 & V_73 )
V_7 -> V_59 = V_42 -> V_60 ;
F_19 ( & V_7 -> V_17 . V_21 ) ;
F_21 ( V_70 ) ;
if ( V_7 -> V_53 ) {
struct V_80 * V_53 = V_7 -> V_53 ;
struct V_34 * V_35 = F_8 ( V_7 -> V_2 . V_36 ) ;
T_1 V_52 = sizeof( struct V_8 ) + V_23 * V_37 ;
F_24 ( V_35 , V_53 , V_52 , V_9 ) ;
if ( V_33 && V_33 -> V_74 >= sizeof( V_50 ) ) {
V_11 = F_13 ( V_33 , & V_53 -> V_57 ,
sizeof( V_53 -> V_57 ) ) ;
if ( V_11 )
goto V_20;
}
F_17 ( & V_35 -> V_64 ) ;
if ( F_25 ( & V_53 -> V_65 ) )
F_18 ( & V_53 -> V_65 ,
& V_35 -> V_65 ) ;
F_19 ( & V_35 -> V_64 ) ;
}
} else if ( V_68 & V_73 ) {
F_17 ( & V_7 -> V_17 . V_21 ) ;
if ( V_42 -> V_60 >= V_7 -> V_17 . V_23 )
V_11 = - V_19 ;
else
V_7 -> V_59 = V_42 -> V_60 ;
F_19 ( & V_7 -> V_17 . V_21 ) ;
}
goto V_20;
V_79:
F_19 ( & V_7 -> V_17 . V_21 ) ;
V_76:
F_21 ( V_9 ) ;
V_20:
return V_11 ;
}
int F_26 ( struct V_1 * V_2 , struct V_66 * V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_42 -> V_43 = V_7 -> V_17 . V_23 - 1 ;
V_42 -> V_18 = V_7 -> V_17 . V_18 ;
V_42 -> V_60 = V_7 -> V_59 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = F_8 ( V_2 -> V_36 ) ;
F_15 ( & V_35 -> V_61 ) ;
V_35 -> V_62 -- ;
F_16 ( & V_35 -> V_61 ) ;
if ( V_7 -> V_53 )
F_28 ( & V_7 -> V_53 -> V_81 , V_82 ) ;
else
F_21 ( V_7 -> V_17 . V_9 ) ;
F_20 ( V_7 ) ;
return 0 ;
}
