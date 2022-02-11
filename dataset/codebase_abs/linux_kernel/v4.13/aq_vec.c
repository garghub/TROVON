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
if ( F_4 ( & V_7 [ V_18 ] ) >
V_22 ) {
F_5 ( V_5 -> V_23 ,
V_7 [ V_18 ] . V_24 ) ;
}
V_12 = true ;
}
V_9 = V_5 -> V_15 -> V_25 ( V_5 -> V_17 ,
& V_7 [ V_26 ] ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_7 [ V_26 ] . V_20 !=
V_7 [ V_26 ] . V_21 ) {
V_9 = F_6 ( & V_7 [ V_26 ] ,
& V_8 ,
V_3 - V_8 ) ;
if ( V_9 < 0 )
goto V_19;
V_11 = V_7 [ V_26 ] . V_27 ;
V_9 = F_7 ( & V_7 [ V_26 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_28 (
V_5 -> V_17 ,
& V_7 [ V_26 ] , V_11 ) ;
if ( V_9 < 0 )
goto V_19;
}
}
if ( V_12 )
V_8 = V_3 ;
if ( V_8 < V_3 ) {
F_8 ( V_2 , V_8 ) ;
V_5 -> V_15 -> V_29 ( V_5 -> V_17 ,
1U << V_5 -> V_30 . V_31 ) ;
}
}
V_19:
return V_8 ;
}
struct V_4 * F_9 ( struct V_32 * V_23 , unsigned int V_24 ,
struct V_33 * V_34 )
{
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
int V_9 = 0 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 ) {
V_9 = - V_36 ;
goto V_19;
}
V_5 -> V_23 = V_23 ;
V_5 -> V_30 . V_31 = V_24 ;
V_5 -> V_30 . V_37 =
V_24 + V_34 -> V_38 . V_39 ;
F_11 ( V_5 -> V_30 . V_37 ,
& V_5 -> V_30 . V_40 ) ;
V_5 -> V_14 = 0 ;
V_5 -> V_41 = 0 ;
F_12 ( F_13 ( V_23 ) , & V_5 -> V_2 ,
F_1 , V_42 ) ;
for ( V_10 = 0 ; V_10 < V_34 -> V_43 ; ++ V_10 ) {
unsigned int V_44 = F_14 ( V_5 -> V_45 ,
V_5 -> V_14 ,
V_5 -> V_30 . V_31 ) ;
V_7 = F_15 ( & V_5 -> V_7 [ V_10 ] [ V_18 ] , V_23 ,
V_44 , V_34 ) ;
if ( ! V_7 ) {
V_9 = - V_36 ;
goto V_19;
}
++ V_5 -> V_14 ;
F_16 ( V_23 , V_44 , V_7 ) ;
V_7 = F_17 ( & V_5 -> V_7 [ V_10 ] [ V_26 ] , V_23 ,
V_44 , V_34 ) ;
if ( ! V_7 ) {
V_9 = - V_36 ;
goto V_19;
}
++ V_5 -> V_41 ;
}
V_19:
if ( V_9 < 0 ) {
F_18 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
int F_19 ( struct V_4 * V_5 , struct V_15 * V_15 ,
struct V_46 * V_17 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
int V_9 = 0 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_17 = V_17 ;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
V_9 = F_20 ( & V_7 [ V_18 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_47 ( V_5 -> V_17 ,
& V_7 [ V_18 ] ,
& V_5 -> V_30 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_20 ( & V_7 [ V_26 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_48 ( V_5 -> V_17 ,
& V_7 [ V_26 ] ,
& V_5 -> V_30 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_7 ( & V_7 [ V_26 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_28 ( V_5 -> V_17 ,
& V_7 [ V_26 ] , 0U ) ;
if ( V_9 < 0 )
goto V_19;
}
V_19:
return V_9 ;
}
int F_21 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
int V_9 = 0 ;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
V_9 = V_5 -> V_15 -> V_49 ( V_5 -> V_17 ,
& V_7 [ V_18 ] ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = V_5 -> V_15 -> V_50 ( V_5 -> V_17 ,
& V_7 [ V_26 ] ) ;
if ( V_9 < 0 )
goto V_19;
}
F_22 ( & V_5 -> V_2 ) ;
V_19:
return V_9 ;
}
void F_23 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
V_5 -> V_15 -> V_51 ( V_5 -> V_17 ,
& V_7 [ V_18 ] ) ;
V_5 -> V_15 -> V_52 ( V_5 -> V_17 ,
& V_7 [ V_26 ] ) ;
}
F_24 ( & V_5 -> V_2 ) ;
}
void F_25 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
if ( ! V_5 )
goto V_19;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
F_3 ( & V_7 [ V_18 ] ) ;
F_26 ( & V_7 [ V_26 ] ) ;
}
V_19: ;
}
void F_18 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 = 0U ;
if ( ! V_5 )
goto V_19;
for ( V_10 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_10 ; ++ V_10 , V_7 = V_5 -> V_7 [ V_10 ] ) {
F_27 ( & V_7 [ V_18 ] ) ;
F_27 ( & V_7 [ V_26 ] ) ;
}
F_28 ( & V_5 -> V_2 ) ;
F_29 ( V_5 ) ;
V_19: ;
}
T_1 F_30 ( int V_53 , void * V_54 )
{
struct V_4 * V_5 = V_54 ;
int V_9 = 0 ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_19;
}
F_31 ( & V_5 -> V_2 ) ;
V_19:
return V_9 >= 0 ? V_55 : V_56 ;
}
T_1 F_32 ( int V_53 , void * V_54 )
{
struct V_4 * V_5 = V_54 ;
T_2 V_57 = 0U ;
T_1 V_9 = 0 ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_19;
}
V_9 = V_5 -> V_15 -> V_58 ( V_5 -> V_17 , & V_57 ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_57 ) {
V_5 -> V_15 -> V_59 ( V_5 -> V_17 ,
1U << V_5 -> V_30 . V_31 ) ;
F_31 ( & V_5 -> V_2 ) ;
} else {
V_5 -> V_15 -> V_29 ( V_5 -> V_17 , 1U ) ;
V_9 = V_56 ;
}
V_19:
return V_9 >= 0 ? V_55 : V_56 ;
}
T_3 * F_33 ( struct V_4 * V_5 )
{
return & V_5 -> V_30 . V_40 ;
}
void F_34 ( struct V_4 * V_5 ,
struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_64 = 0U ;
for ( V_64 = 0U , V_7 = V_5 -> V_7 [ 0 ] ;
V_5 -> V_14 > V_64 ; ++ V_64 , V_7 = V_5 -> V_7 [ V_64 ] ) {
struct V_62 * V_65 = & V_7 [ V_18 ] . V_66 . V_65 ;
struct V_60 * V_67 = & V_7 [ V_26 ] . V_66 . V_67 ;
V_61 -> V_68 += V_67 -> V_68 ;
V_61 -> V_69 += V_67 -> V_69 ;
V_61 -> V_70 += V_67 -> V_70 ;
V_61 -> V_71 += V_67 -> V_71 ;
V_61 -> V_72 += V_67 -> V_72 ;
V_63 -> V_68 += V_65 -> V_68 ;
V_63 -> V_69 += V_65 -> V_69 ;
V_63 -> V_70 += V_65 -> V_70 ;
}
}
int F_35 ( struct V_4 * V_5 , T_2 * V_73 , unsigned int * V_74 )
{
unsigned int V_75 = 0U ;
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0U , sizeof( struct V_60 ) ) ;
memset ( & V_63 , 0U , sizeof( struct V_62 ) ) ;
F_34 ( V_5 , & V_61 , & V_63 ) ;
V_73 [ V_75 ] += V_61 . V_68 ;
V_73 [ ++ V_75 ] += V_63 . V_68 ;
V_73 [ ++ V_75 ] += V_61 . V_71 ;
V_73 [ ++ V_75 ] += V_61 . V_72 ;
V_73 [ ++ V_75 ] += V_61 . V_70 ;
if ( V_74 )
* V_74 = ++ V_75 ;
return 0 ;
}
