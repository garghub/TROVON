static int F_1 ( struct V_1 * V_2 , int V_3 )
__releases( &self->lock
struct V_4 * F_2 ( struct V_5 * V_6 , unsigned int V_7 ,
struct V_8 * V_9 )
{
struct V_4 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
unsigned int V_13 = 0U ;
int V_14 = 0 ;
V_10 = F_3 ( sizeof( * V_10 ) , V_15 ) ;
if ( ! V_10 ) {
V_14 = - V_16 ;
goto V_17;
}
V_10 -> V_6 = V_6 ;
V_10 -> V_18 . V_19 = V_7 ;
V_10 -> V_18 . V_20 =
V_7 + V_9 -> V_21 . V_22 ;
F_4 ( V_10 -> V_18 . V_20 ,
& V_10 -> V_18 . V_23 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_25 = 0 ;
F_5 ( F_6 ( V_6 ) , & V_10 -> V_2 ,
F_1 , V_26 ) ;
for ( V_13 = 0 ; V_13 < V_9 -> V_27 ; ++ V_13 ) {
unsigned int V_28 = F_7 ( V_10 -> V_29 ,
V_10 -> V_24 ,
V_10 -> V_18 . V_19 ) ;
V_12 = F_8 ( & V_10 -> V_12 [ V_13 ] [ V_30 ] , V_6 ,
V_28 , V_9 ) ;
if ( ! V_12 ) {
V_14 = - V_16 ;
goto V_17;
}
++ V_10 -> V_24 ;
F_9 ( V_6 , V_28 , V_12 ) ;
V_12 = F_10 ( & V_10 -> V_12 [ V_13 ] [ V_31 ] , V_6 ,
V_28 , V_9 ) ;
if ( ! V_12 ) {
V_14 = - V_16 ;
goto V_17;
}
++ V_10 -> V_25 ;
}
V_17:
if ( V_14 < 0 ) {
F_11 ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
int F_12 ( struct V_4 * V_10 , struct V_32 * V_32 ,
struct V_33 * V_34 )
{
struct V_11 * V_12 = NULL ;
unsigned int V_13 = 0U ;
int V_14 = 0 ;
V_10 -> V_32 = V_32 ;
V_10 -> V_34 = V_34 ;
F_13 ( & V_10 -> V_35 . V_36 ) ;
for ( V_13 = 0U , V_12 = V_10 -> V_12 [ 0 ] ;
V_10 -> V_24 > V_13 ; ++ V_13 , V_12 = V_10 -> V_12 [ V_13 ] ) {
V_14 = F_14 ( & V_12 [ V_30 ] ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = V_10 -> V_32 -> V_37 ( V_10 -> V_34 ,
& V_12 [ V_30 ] ,
& V_10 -> V_18 ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = F_14 ( & V_12 [ V_31 ] ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = V_10 -> V_32 -> V_38 ( V_10 -> V_34 ,
& V_12 [ V_31 ] ,
& V_10 -> V_18 ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = F_15 ( & V_12 [ V_31 ] ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = V_10 -> V_32 -> V_39 ( V_10 -> V_34 ,
& V_12 [ V_31 ] , 0U ) ;
if ( V_14 < 0 )
goto V_17;
}
V_17:
return V_14 ;
}
int F_16 ( struct V_4 * V_10 )
{
struct V_11 * V_12 = NULL ;
unsigned int V_13 = 0U ;
int V_14 = 0 ;
for ( V_13 = 0U , V_12 = V_10 -> V_12 [ 0 ] ;
V_10 -> V_24 > V_13 ; ++ V_13 , V_12 = V_10 -> V_12 [ V_13 ] ) {
V_14 = V_10 -> V_32 -> V_40 ( V_10 -> V_34 ,
& V_12 [ V_30 ] ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = V_10 -> V_32 -> V_41 ( V_10 -> V_34 ,
& V_12 [ V_31 ] ) ;
if ( V_14 < 0 )
goto V_17;
}
F_17 ( & V_10 -> V_2 ) ;
V_17:
return V_14 ;
}
void F_18 ( struct V_4 * V_10 )
{
struct V_11 * V_12 = NULL ;
unsigned int V_13 = 0U ;
for ( V_13 = 0U , V_12 = V_10 -> V_12 [ 0 ] ;
V_10 -> V_24 > V_13 ; ++ V_13 , V_12 = V_10 -> V_12 [ V_13 ] ) {
V_10 -> V_32 -> V_42 ( V_10 -> V_34 ,
& V_12 [ V_30 ] ) ;
V_10 -> V_32 -> V_43 ( V_10 -> V_34 ,
& V_12 [ V_31 ] ) ;
}
F_19 ( & V_10 -> V_2 ) ;
}
void F_20 ( struct V_4 * V_10 )
{
struct V_11 * V_12 = NULL ;
unsigned int V_13 = 0U ;
if ( ! V_10 )
goto V_17;
for ( V_13 = 0U , V_12 = V_10 -> V_12 [ 0 ] ;
V_10 -> V_24 > V_13 ; ++ V_13 , V_12 = V_10 -> V_12 [ V_13 ] ) {
F_21 ( & V_12 [ V_30 ] ) ;
F_22 ( & V_12 [ V_31 ] ) ;
}
V_17: ;
}
void F_11 ( struct V_4 * V_10 )
{
struct V_11 * V_12 = NULL ;
unsigned int V_13 = 0U ;
if ( ! V_10 )
goto V_17;
for ( V_13 = 0U , V_12 = V_10 -> V_12 [ 0 ] ;
V_10 -> V_24 > V_13 ; ++ V_13 , V_12 = V_10 -> V_12 [ V_13 ] ) {
F_23 ( & V_12 [ V_30 ] ) ;
F_23 ( & V_12 [ V_31 ] ) ;
}
F_24 ( & V_10 -> V_2 ) ;
F_25 ( V_10 ) ;
V_17: ;
}
T_1 F_26 ( int V_44 , void * V_45 )
{
struct V_4 * V_10 = V_45 ;
int V_14 = 0 ;
if ( ! V_10 ) {
V_14 = - V_46 ;
goto V_17;
}
F_27 ( & V_10 -> V_2 ) ;
V_17:
return V_14 >= 0 ? V_47 : V_48 ;
}
T_1 F_28 ( int V_44 , void * V_45 )
{
struct V_4 * V_10 = V_45 ;
T_2 V_49 = 0U ;
T_1 V_14 = 0 ;
if ( ! V_10 ) {
V_14 = - V_46 ;
goto V_17;
}
V_14 = V_10 -> V_32 -> V_50 ( V_10 -> V_34 , & V_49 ) ;
if ( V_14 < 0 )
goto V_17;
if ( V_49 ) {
V_10 -> V_32 -> V_51 ( V_10 -> V_34 ,
1U << V_10 -> V_18 . V_19 ) ;
F_27 ( & V_10 -> V_2 ) ;
} else {
V_10 -> V_32 -> V_52 ( V_10 -> V_34 , 1U ) ;
V_14 = V_48 ;
}
V_17:
return V_14 >= 0 ? V_47 : V_48 ;
}
T_3 * F_29 ( struct V_4 * V_10 )
{
return & V_10 -> V_18 . V_23 ;
}
void F_30 ( struct V_4 * V_10 ,
struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 = NULL ;
unsigned int V_57 = 0U ;
for ( V_57 = 0U , V_12 = V_10 -> V_12 [ 0 ] ;
V_10 -> V_24 > V_57 ; ++ V_57 , V_12 = V_10 -> V_12 [ V_57 ] ) {
struct V_55 * V_58 = & V_12 [ V_30 ] . V_59 . V_58 ;
struct V_53 * V_60 = & V_12 [ V_31 ] . V_59 . V_60 ;
V_54 -> V_61 += V_60 -> V_61 ;
V_54 -> V_62 += V_60 -> V_62 ;
V_54 -> V_63 += V_60 -> V_63 ;
V_54 -> V_64 += V_60 -> V_64 ;
V_54 -> V_65 += V_60 -> V_65 ;
V_56 -> V_61 += V_58 -> V_61 ;
V_56 -> V_62 += V_58 -> V_62 ;
V_56 -> V_63 += V_58 -> V_63 ;
}
}
int F_31 ( struct V_4 * V_10 , T_2 * V_66 , unsigned int * V_67 )
{
unsigned int V_68 = 0U ;
struct V_53 V_54 ;
struct V_55 V_56 ;
memset ( & V_54 , 0U , sizeof( struct V_53 ) ) ;
memset ( & V_56 , 0U , sizeof( struct V_55 ) ) ;
F_30 ( V_10 , & V_54 , & V_56 ) ;
V_66 [ V_68 ] += V_54 . V_61 ;
V_66 [ ++ V_68 ] += V_56 . V_61 ;
V_66 [ ++ V_68 ] += V_54 . V_64 ;
V_66 [ ++ V_68 ] += V_54 . V_65 ;
V_66 [ ++ V_68 ] += V_54 . V_63 ;
if ( V_67 )
* V_67 = ++ V_68 ;
return 0 ;
}
