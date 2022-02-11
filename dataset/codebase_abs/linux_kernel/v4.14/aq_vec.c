static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
struct V_6 * V_7 = NULL ;
int V_8 = 0 ;
int V_9 = 0 ;
unsigned int V_10 = 0U ;
unsigned int V_11 = 0U ;
bool V_12 = false ;
if ( ! V_5 ) {
V_9 = - V_13 ;
} else {
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
if ( V_5 -> V_15 -> V_16 ) {
V_9 = V_5 -> V_15 -> V_16 (
V_5 -> V_17 ,
& V_7 [ V_18 ] ) ;
if ( V_9 < 0 )
goto V_19;
}
if ( V_7 [ V_18 ] . V_20 !=
V_7 [ V_18 ] . V_21 ) {
F_3 ( & V_7 [ V_18 ] ) ;
F_4 ( & V_7 [ V_18 ] ) ;
V_12 = true ;
}
V_9 = V_5 -> V_15 -> V_22 ( V_5 -> V_17 ,
& V_7 [ V_23 ] ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_7 [ V_23 ] . V_20 !=
V_7 [ V_23 ] . V_21 ) {
V_9 = F_5 ( & V_7 [ V_23 ] ,
V_2 ,
& V_8 ,
V_3 - V_8 ) ;
if ( V_9 < 0 )
goto V_19;
V_11 = V_7 [ V_23 ] . V_24 ;
V_9 = F_6 ( & V_7 [ V_23 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_25 (
V_5 -> V_17 ,
& V_7 [ V_23 ] , V_11 ) ;
if ( V_9 < 0 )
goto V_19;
}
}
if ( V_12 )
V_8 = V_3 ;
if ( V_8 < V_3 ) {
F_7 ( V_2 , V_8 ) ;
V_5 -> V_15 -> V_26 ( V_5 -> V_17 ,
1U << V_5 -> V_27 . V_28 ) ;
}
}
V_19:
return V_8 ;
}
struct V_4 * F_8 ( struct V_29 * V_30 , unsigned int V_31 ,
struct V_32 * V_33 )
{
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
int V_9 = 0 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 ) {
V_9 = - V_35 ;
goto V_19;
}
V_5 -> V_30 = V_30 ;
V_5 -> V_27 . V_28 = V_31 ;
V_5 -> V_27 . V_36 =
V_31 + V_33 -> V_37 . V_38 ;
F_10 ( V_5 -> V_27 . V_36 ,
& V_5 -> V_27 . V_39 ) ;
V_5 -> V_14 = 0 ;
V_5 -> V_40 = 0 ;
F_11 ( F_12 ( V_30 ) , & V_5 -> V_2 ,
F_1 , V_41 ) ;
for ( V_10 = 0 ; V_10 < V_33 -> V_42 ; ++ V_10 ) {
unsigned int V_43 = F_13 ( V_5 -> V_44 ,
V_5 -> V_14 ,
V_5 -> V_27 . V_28 ) ;
V_7 = F_14 ( & V_5 -> V_7 [ V_10 ] [ V_18 ] , V_30 ,
V_43 , V_33 ) ;
if ( ! V_7 ) {
V_9 = - V_35 ;
goto V_19;
}
++ V_5 -> V_14 ;
F_15 ( V_30 , V_43 , V_7 ) ;
V_7 = F_16 ( & V_5 -> V_7 [ V_10 ] [ V_23 ] , V_30 ,
V_43 , V_33 ) ;
if ( ! V_7 ) {
V_9 = - V_35 ;
goto V_19;
}
++ V_5 -> V_40 ;
}
V_19:
if ( V_9 < 0 ) {
F_17 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
int F_18 ( struct V_4 * V_5 , struct V_15 * V_15 ,
struct V_45 * V_17 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
int V_9 = 0 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_17 = V_17 ;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
V_9 = F_19 ( & V_7 [ V_18 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_46 ( V_5 -> V_17 ,
& V_7 [ V_18 ] ,
& V_5 -> V_27 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_19 ( & V_7 [ V_23 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_47 ( V_5 -> V_17 ,
& V_7 [ V_23 ] ,
& V_5 -> V_27 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_6 ( & V_7 [ V_23 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_25 ( V_5 -> V_17 ,
& V_7 [ V_23 ] , 0U ) ;
if ( V_9 < 0 )
goto V_19;
}
V_19:
return V_9 ;
}
int F_20 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
int V_9 = 0 ;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
V_9 = V_5 -> V_15 -> V_48 ( V_5 -> V_17 ,
& V_7 [ V_18 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_49 ( V_5 -> V_17 ,
& V_7 [ V_23 ] ) ;
if ( V_9 < 0 )
goto V_19;
}
F_21 ( & V_5 -> V_2 ) ;
V_19:
return V_9 ;
}
void F_22 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
V_5 -> V_15 -> V_50 ( V_5 -> V_17 ,
& V_7 [ V_18 ] ) ;
V_5 -> V_15 -> V_51 ( V_5 -> V_17 ,
& V_7 [ V_23 ] ) ;
}
F_23 ( & V_5 -> V_2 ) ;
}
void F_24 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
if ( ! V_5 )
goto V_19;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
F_3 ( & V_7 [ V_18 ] ) ;
F_25 ( & V_7 [ V_23 ] ) ;
}
V_19: ;
}
void F_17 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
if ( ! V_5 )
goto V_19;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
F_26 ( & V_7 [ V_18 ] ) ;
F_26 ( & V_7 [ V_23 ] ) ;
}
F_27 ( & V_5 -> V_2 ) ;
F_28 ( V_5 ) ;
V_19: ;
}
T_1 F_29 ( int V_52 , void * V_53 )
{
struct V_4 * V_5 = V_53 ;
int V_9 = 0 ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_19;
}
F_30 ( & V_5 -> V_2 ) ;
V_19:
return V_9 >= 0 ? V_54 : V_55 ;
}
T_1 F_31 ( int V_52 , void * V_53 )
{
struct V_4 * V_5 = V_53 ;
T_2 V_56 = 0U ;
T_1 V_9 = 0 ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_19;
}
V_9 = V_5 -> V_15 -> V_57 ( V_5 -> V_17 , & V_56 ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_56 ) {
V_5 -> V_15 -> V_58 ( V_5 -> V_17 ,
1U << V_5 -> V_27 . V_28 ) ;
F_30 ( & V_5 -> V_2 ) ;
} else {
V_5 -> V_15 -> V_26 ( V_5 -> V_17 , 1U ) ;
V_9 = V_55 ;
}
V_19:
return V_9 >= 0 ? V_54 : V_55 ;
}
T_3 * F_32 ( struct V_4 * V_5 )
{
return & V_5 -> V_27 . V_39 ;
}
void F_33 ( struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_63 = 0U ;
for ( V_63 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_63 ; ++ V_63 , V_7 = V_5 -> V_7 [ V_63 ] ) {
struct V_61 * V_64 = & V_7 [ V_18 ] . V_65 . V_64 ;
struct V_59 * V_66 = & V_7 [ V_23 ] . V_65 . V_66 ;
V_60 -> V_67 += V_66 -> V_67 ;
V_60 -> V_68 += V_66 -> V_68 ;
V_60 -> V_69 += V_66 -> V_69 ;
V_60 -> V_70 += V_66 -> V_70 ;
V_60 -> V_71 += V_66 -> V_71 ;
V_62 -> V_67 += V_64 -> V_67 ;
V_62 -> V_68 += V_64 -> V_68 ;
V_62 -> V_69 += V_64 -> V_69 ;
V_62 -> V_72 += V_64 -> V_72 ;
}
}
int F_34 ( struct V_4 * V_5 , T_2 * V_73 , unsigned int * V_74 )
{
unsigned int V_75 = 0U ;
struct V_59 V_60 ;
struct V_61 V_62 ;
memset ( & V_60 , 0U , sizeof( struct V_59 ) ) ;
memset ( & V_62 , 0U , sizeof( struct V_61 ) ) ;
F_33 ( V_5 , & V_60 , & V_62 ) ;
V_73 [ V_75 ] += V_60 . V_67 ;
V_73 [ ++ V_75 ] += V_62 . V_67 ;
V_73 [ ++ V_75 ] += V_62 . V_72 ;
V_73 [ ++ V_75 ] += V_60 . V_70 ;
V_73 [ ++ V_75 ] += V_60 . V_71 ;
V_73 [ ++ V_75 ] += V_60 . V_69 ;
if ( V_74 )
* V_74 = ++ V_75 ;
return 0 ;
}
