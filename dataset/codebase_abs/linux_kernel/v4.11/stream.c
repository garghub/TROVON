int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_3 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_8 = V_2 -> V_9 . V_10 ;
V_5 -> V_11 = F_3 ( V_5 -> V_8 , sizeof( * V_5 -> V_11 ) , V_3 ) ;
if ( ! V_5 -> V_11 ) {
F_4 ( V_5 ) ;
return - V_7 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_5 -> V_11 [ V_6 ] . V_12 = V_13 ;
V_2 -> V_5 = V_5 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
F_4 ( V_5 -> V_11 ) ;
V_5 -> V_8 = V_2 -> V_9 . V_10 ;
V_5 -> V_11 = F_3 ( V_5 -> V_8 , sizeof( * V_5 -> V_11 ) , V_3 ) ;
if ( ! V_5 -> V_11 )
goto V_14;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_5 -> V_11 [ V_6 ] . V_12 = V_13 ;
V_5 -> V_15 = V_2 -> V_9 . V_16 ;
V_5 -> V_17 = F_3 ( V_5 -> V_15 , sizeof( * V_5 -> V_17 ) , V_3 ) ;
if ( ! V_5 -> V_17 ) {
F_4 ( V_5 -> V_11 ) ;
goto V_14;
}
return 0 ;
V_14:
V_2 -> V_5 = NULL ;
F_4 ( V_5 ) ;
return - V_7 ;
}
void F_6 ( struct V_4 * V_5 )
{
if ( F_7 ( ! V_5 ) )
return;
F_4 ( V_5 -> V_11 ) ;
F_4 ( V_5 -> V_17 ) ;
F_4 ( V_5 ) ;
}
void F_8 ( struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_5 -> V_11 [ V_6 ] . V_18 = 0 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ )
V_5 -> V_17 [ V_6 ] . V_18 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_21 * V_21 = F_10 ( V_2 -> V_22 . V_23 ) ;
int V_24 = 0 ;
V_24 = F_11 ( V_21 , V_2 , V_20 ) ;
if ( V_24 )
F_12 ( V_20 ) ;
return V_24 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_6 , V_27 , * V_28 ;
struct V_19 * V_20 ;
int V_24 = - V_29 ;
bool V_11 , V_17 ;
if ( ! V_2 -> V_30 . V_31 ||
! ( V_2 -> V_32 & V_33 ) ) {
V_24 = - V_34 ;
goto V_11;
}
if ( V_2 -> V_35 ) {
V_24 = - V_36 ;
goto V_11;
}
V_11 = V_26 -> V_37 & V_38 ;
V_17 = V_26 -> V_37 & V_39 ;
if ( ! V_11 && ! V_17 )
goto V_11;
V_27 = V_26 -> V_40 ;
V_28 = V_26 -> V_41 ;
if ( V_11 && V_27 )
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
if ( V_28 [ V_6 ] >= V_5 -> V_8 )
goto V_11;
if ( V_17 && V_27 )
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
if ( V_28 [ V_6 ] >= V_5 -> V_15 )
goto V_11;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
V_28 [ V_6 ] = F_14 ( V_28 [ V_6 ] ) ;
V_20 = F_15 ( V_2 , V_27 , V_28 , V_11 , V_17 ) ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
V_28 [ V_6 ] = F_16 ( V_28 [ V_6 ] ) ;
if ( ! V_20 ) {
V_24 = - V_7 ;
goto V_11;
}
if ( V_11 ) {
if ( V_27 )
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
V_5 -> V_11 [ V_28 [ V_6 ] ] . V_12 =
V_42 ;
else
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_5 -> V_11 [ V_6 ] . V_12 = V_42 ;
}
V_2 -> V_43 = V_20 ;
F_17 ( V_2 -> V_43 ) ;
V_24 = F_9 ( V_2 , V_20 ) ;
if ( V_24 ) {
F_18 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
if ( ! V_11 )
goto V_11;
if ( V_27 )
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
V_5 -> V_11 [ V_28 [ V_6 ] ] . V_12 =
V_13 ;
else
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_5 -> V_11 [ V_6 ] . V_12 = V_13 ;
goto V_11;
}
V_2 -> V_35 = V_11 + V_17 ;
V_11:
return V_24 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = NULL ;
int V_24 ;
T_2 V_6 ;
if ( ! V_2 -> V_30 . V_31 ||
! ( V_2 -> V_32 & V_44 ) )
return - V_34 ;
if ( V_2 -> V_35 )
return - V_36 ;
V_20 = F_20 ( V_2 ) ;
if ( ! V_20 )
return - V_7 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_5 -> V_8 ; V_6 ++ )
V_2 -> V_5 -> V_11 [ V_6 ] . V_12 = V_42 ;
V_2 -> V_43 = V_20 ;
F_17 ( V_2 -> V_43 ) ;
V_24 = F_9 ( V_2 , V_20 ) ;
if ( V_24 ) {
F_18 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
for ( V_6 = 0 ; V_6 < V_2 -> V_5 -> V_8 ; V_6 ++ )
V_2 -> V_5 -> V_11 [ V_6 ] . V_12 = V_13 ;
return V_24 ;
}
V_2 -> V_35 = 1 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_45 * V_26 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = NULL ;
int V_24 = - V_7 ;
T_3 V_8 , V_15 ;
T_2 V_11 , V_17 ;
if ( ! V_2 -> V_30 . V_31 ||
! ( V_2 -> V_32 & V_46 ) ) {
V_24 = - V_34 ;
goto V_11;
}
if ( V_2 -> V_35 ) {
V_24 = - V_36 ;
goto V_11;
}
V_11 = V_26 -> V_47 ;
V_17 = V_26 -> V_48 ;
V_8 = V_5 -> V_8 + V_11 ;
V_15 = V_5 -> V_15 + V_17 ;
if ( V_8 > V_49 || V_15 > V_49 ||
( ! V_11 && ! V_17 ) ) {
V_24 = - V_29 ;
goto V_11;
}
if ( V_11 ) {
struct V_50 * V_51 ;
V_51 = F_22 ( V_5 -> V_11 , V_8 * sizeof( * V_51 ) ,
V_52 ) ;
if ( ! V_51 )
goto V_11;
memset ( V_51 + V_5 -> V_8 , 0 , V_11 * sizeof( * V_51 ) ) ;
V_5 -> V_11 = V_51 ;
}
if ( V_17 ) {
struct V_53 * V_54 ;
V_54 = F_22 ( V_5 -> V_17 , V_15 * sizeof( * V_54 ) ,
V_52 ) ;
if ( ! V_54 )
goto V_11;
memset ( V_54 + V_5 -> V_15 , 0 , V_17 * sizeof( * V_54 ) ) ;
V_5 -> V_17 = V_54 ;
}
V_20 = F_23 ( V_2 , V_11 , V_17 ) ;
if ( ! V_20 )
goto V_11;
V_2 -> V_43 = V_20 ;
F_17 ( V_2 -> V_43 ) ;
V_24 = F_9 ( V_2 , V_20 ) ;
if ( V_24 ) {
F_18 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
goto V_11;
}
V_5 -> V_15 = V_15 ;
V_5 -> V_8 = V_8 ;
V_2 -> V_35 = ! ! V_11 + ! ! V_17 ;
V_11:
return V_24 ;
}
static T_4 * F_24 (
struct V_1 * V_2 , T_3 V_55 )
{
struct V_19 * V_20 = V_2 -> V_43 ;
struct V_56 * V_57 ;
union V_58 V_59 ;
if ( F_25 ( V_55 ) != V_2 -> V_60 || ! V_20 )
return NULL ;
V_57 = (struct V_56 * ) V_20 -> V_61 ;
F_26 (param, hdr, params) {
struct V_62 * V_63 = V_59 . V_64 ;
if ( V_63 -> V_65 == V_55 )
return V_59 . V_64 ;
}
return NULL ;
}
struct V_19 * F_27 (
struct V_1 * V_2 ,
union V_58 V_59 ,
struct V_66 * * V_67 )
{
struct V_68 * V_69 = V_59 . V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_6 , V_70 , V_71 = 0 , * V_72 = NULL ;
T_3 V_73 = V_74 ;
T_3 V_65 ;
V_65 = F_25 ( V_69 -> V_65 ) ;
if ( F_25 ( V_69 -> V_75 ) >
F_28 ( & V_2 -> V_30 . V_76 ) ) {
V_73 = V_77 ;
goto V_11;
}
if ( V_65 > V_2 -> V_78 ) {
V_73 = V_79 ;
goto V_11;
} else if ( V_65 == V_2 -> V_78 ) {
V_2 -> V_78 ++ ;
}
if ( ! ( V_2 -> V_32 & V_33 ) )
goto V_11;
if ( V_2 -> V_43 ) {
T_4 * V_80 ;
struct V_81 * V_82 ;
V_80 = F_24 (
V_2 , V_69 -> V_83 ) ;
if ( ! V_80 || V_80 -> type !=
V_84 ) {
V_73 = V_85 ;
goto V_11;
}
V_2 -> V_35 -- ;
V_2 -> V_60 ++ ;
if ( ! V_2 -> V_35 ) {
V_82 = V_2 -> V_43 -> V_86 ;
if ( F_29 ( & V_82 -> V_87 ) )
F_30 ( V_82 ) ;
F_18 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
}
V_71 = V_88 ;
}
V_70 = ( F_16 ( V_59 . V_89 -> V_90 ) - sizeof( * V_69 ) ) / 2 ;
if ( V_70 ) {
V_72 = V_69 -> V_91 ;
for ( V_6 = 0 ; V_6 < V_70 ; V_6 ++ ) {
if ( F_16 ( V_72 [ V_6 ] ) >= V_5 -> V_15 ) {
V_73 = V_92 ;
goto V_11;
}
}
for ( V_6 = 0 ; V_6 < V_70 ; V_6 ++ )
V_5 -> V_17 [ F_16 ( V_72 [ V_6 ] ) ] . V_18 = 0 ;
} else {
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ )
V_5 -> V_17 [ V_6 ] . V_18 = 0 ;
}
V_73 = V_93 ;
* V_67 = F_31 ( V_2 ,
V_71 | V_94 , V_70 , V_72 ,
V_95 ) ;
V_11:
return F_32 ( V_2 , V_73 , V_65 ) ;
}
struct V_19 * F_33 (
struct V_1 * V_2 ,
union V_58 V_59 ,
struct V_66 * * V_67 )
{
struct V_96 * V_97 = V_59 . V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_3 V_73 = V_74 ;
struct V_19 * V_20 = NULL ;
T_2 V_6 , V_70 , * V_72 ;
T_3 V_65 ;
V_65 = F_25 ( V_97 -> V_65 ) ;
if ( V_65 > V_2 -> V_78 ) {
V_73 = V_79 ;
goto V_11;
} else if ( V_65 == V_2 -> V_78 ) {
V_2 -> V_78 ++ ;
}
if ( ! ( V_2 -> V_32 & V_33 ) )
goto V_11;
if ( V_2 -> V_35 ) {
V_73 = V_85 ;
goto V_11;
}
V_70 = ( F_16 ( V_59 . V_89 -> V_90 ) - sizeof( * V_97 ) ) / 2 ;
V_72 = V_97 -> V_91 ;
for ( V_6 = 0 ; V_6 < V_70 ; V_6 ++ ) {
if ( F_16 ( V_72 [ V_6 ] ) >= V_5 -> V_8 ) {
V_73 = V_92 ;
goto V_11;
}
}
V_20 = F_15 ( V_2 , V_70 , V_72 , 1 , 0 ) ;
if ( ! V_20 )
goto V_11;
if ( V_70 )
for ( V_6 = 0 ; V_6 < V_70 ; V_6 ++ )
V_5 -> V_11 [ F_16 ( V_72 [ V_6 ] ) ] . V_12 =
V_42 ;
else
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_5 -> V_11 [ V_6 ] . V_12 = V_42 ;
V_2 -> V_43 = V_20 ;
V_2 -> V_35 = 1 ;
F_17 ( V_2 -> V_43 ) ;
* V_67 = F_31 ( V_2 ,
V_88 , V_70 , V_72 , V_95 ) ;
V_11:
if ( ! V_20 )
V_20 = F_32 ( V_2 , V_73 , V_65 ) ;
return V_20 ;
}
