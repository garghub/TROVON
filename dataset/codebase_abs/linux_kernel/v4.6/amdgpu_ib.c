int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned V_5 , struct V_6 * V_7 )
{
int V_8 ;
if ( V_5 ) {
V_8 = F_2 ( & V_2 -> V_9 ,
& V_7 -> V_10 , V_5 , 256 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_1 , V_8 ) ;
return V_8 ;
}
V_7 -> V_12 = F_4 ( V_7 -> V_10 ) ;
if ( ! V_4 )
V_7 -> V_13 = F_5 ( V_7 -> V_10 ) ;
}
V_7 -> V_4 = V_4 ;
V_7 -> V_14 = 0 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 , struct V_15 * V_16 )
{
F_7 ( V_2 , & V_7 -> V_10 , V_16 ) ;
}
int F_8 ( struct V_17 * V_18 , unsigned V_19 ,
struct V_6 * V_20 , struct V_15 * V_21 ,
struct V_15 * * V_16 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_6 * V_7 = & V_20 [ 0 ] ;
struct V_22 * V_23 , * V_24 ;
struct V_3 * V_4 ;
struct V_15 * V_25 ;
unsigned V_26 ;
int V_8 = 0 ;
if ( V_19 == 0 )
return - V_27 ;
V_23 = V_20 -> V_23 ;
V_4 = V_20 -> V_4 ;
if ( ! V_18 -> V_28 ) {
F_3 ( V_2 -> V_11 , L_2 ) ;
return - V_27 ;
}
if ( V_4 && ! V_20 -> V_14 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return - V_27 ;
}
V_8 = F_9 ( V_18 , 256 * V_19 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_4 ) {
F_10 ( V_18 , V_7 -> V_14 , V_7 -> V_29 ,
V_7 -> V_30 , V_7 -> V_31 ,
V_7 -> V_32 , V_7 -> V_33 ,
V_7 -> V_34 , V_7 -> V_35 ) ;
if ( V_18 -> V_36 -> V_37 )
F_11 ( V_18 ) ;
}
V_24 = V_18 -> V_38 ;
for ( V_26 = 0 ; V_26 < V_19 ; ++ V_26 ) {
V_7 = & V_20 [ V_26 ] ;
if ( V_7 -> V_23 != V_23 || V_7 -> V_4 != V_4 ) {
V_18 -> V_38 = V_24 ;
if ( V_7 -> V_14 )
F_12 ( V_2 , V_7 -> V_14 ) ;
F_13 ( V_18 ) ;
return - V_27 ;
}
F_14 ( V_18 , V_7 ) ;
V_18 -> V_38 = V_23 ;
}
if ( V_4 ) {
if ( V_18 -> V_36 -> V_39 )
F_15 ( V_18 ) ;
}
V_8 = F_16 ( V_18 , & V_25 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
V_18 -> V_38 = V_24 ;
if ( V_7 -> V_14 )
F_12 ( V_2 , V_7 -> V_14 ) ;
F_13 ( V_18 ) ;
return V_8 ;
}
if ( V_7 -> V_40 ) {
T_1 V_41 = F_17 ( V_7 -> V_40 -> V_42 ) ;
V_41 += V_7 -> V_40 -> V_43 ;
F_18 ( V_18 , V_41 , V_7 -> V_44 ,
V_45 ) ;
}
if ( V_16 )
* V_16 = F_19 ( V_25 ) ;
F_20 ( V_18 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_46 ) {
return 0 ;
}
V_8 = F_22 ( V_2 , & V_2 -> V_9 ,
V_47 * 64 * 1024 ,
V_48 ,
V_49 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_23 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_46 = true ;
if ( F_24 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_26 ( V_2 , & V_2 -> V_9 ) ;
F_27 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_46 = false ;
}
}
int F_28 ( struct V_1 * V_2 )
{
unsigned V_26 ;
int V_8 ;
for ( V_26 = 0 ; V_26 < V_50 ; ++ V_26 ) {
struct V_17 * V_18 = V_2 -> V_51 [ V_26 ] ;
if ( ! V_18 || ! V_18 -> V_28 )
continue;
V_8 = F_29 ( V_18 ) ;
if ( V_8 ) {
V_18 -> V_28 = false ;
if ( V_18 == & V_2 -> V_52 . V_53 [ 0 ] ) {
F_30 ( L_7 , V_8 ) ;
V_2 -> V_54 = false ;
return V_8 ;
} else {
F_30 ( L_8 , V_26 , V_8 ) ;
}
}
}
return 0 ;
}
static int F_31 ( struct V_55 * V_56 , void * V_57 )
{
struct V_58 * V_59 = (struct V_58 * ) V_56 -> V_60 ;
struct V_61 * V_11 = V_59 -> V_62 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_63 ;
F_32 ( & V_2 -> V_9 , V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
#if F_33 ( V_64 )
return F_34 ( V_2 , V_65 , 1 ) ;
#else
return 0 ;
#endif
}
