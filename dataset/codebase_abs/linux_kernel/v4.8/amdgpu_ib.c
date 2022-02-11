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
return 0 ;
}
void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_14 * V_15 )
{
F_7 ( V_2 , & V_7 -> V_10 , V_15 ) ;
}
int F_8 ( struct V_16 * V_17 , unsigned V_18 ,
struct V_6 * V_19 , struct V_14 * V_20 ,
struct V_21 * V_22 , struct V_14 * * V_15 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_6 * V_7 = & V_19 [ 0 ] ;
bool V_23 , V_24 ;
unsigned V_25 = ~ 0 ;
struct V_3 * V_4 ;
T_1 V_26 ;
unsigned V_27 ;
int V_8 = 0 ;
if ( V_18 == 0 )
return - V_28 ;
if ( V_22 ) {
V_4 = V_22 -> V_4 ;
V_26 = V_22 -> V_26 ;
} else {
V_4 = NULL ;
V_26 = 0 ;
}
if ( ! V_17 -> V_29 ) {
F_3 ( V_2 -> V_11 , L_2 ) ;
return - V_28 ;
}
if ( V_4 && ! V_22 -> V_30 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return - V_28 ;
}
V_8 = F_9 ( V_17 , 256 * V_18 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_17 -> type == V_31 && V_17 -> V_32 -> V_33 )
V_25 = F_10 ( V_17 ) ;
if ( V_4 ) {
V_8 = F_11 ( V_17 , V_22 ) ;
if ( V_8 ) {
F_12 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_32 -> V_34 )
F_13 ( V_17 ) ;
* V_17 -> V_35 = 1 ;
V_23 = V_17 -> V_36 == V_26 ;
V_24 = V_17 -> V_36 != V_26 ;
for ( V_27 = 0 ; V_27 < V_18 ; ++ V_27 ) {
V_7 = & V_19 [ V_27 ] ;
if ( ( V_7 -> V_37 & V_38 ) && V_23 )
continue;
F_14 ( V_17 , V_7 , V_22 ? V_22 -> V_30 : 0 ,
V_24 ) ;
V_24 = false ;
}
if ( V_17 -> V_32 -> V_39 )
F_15 ( V_17 ) ;
V_8 = F_16 ( V_17 , V_15 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_22 && V_22 -> V_30 )
F_17 ( V_2 , V_22 -> V_30 ) ;
F_12 ( V_17 ) ;
return V_8 ;
}
if ( V_22 && V_22 -> V_40 ) {
F_18 ( V_17 , V_22 -> V_40 , V_22 -> V_41 ,
V_42 ) ;
}
if ( V_25 != ~ 0 && V_17 -> V_32 -> V_43 )
F_19 ( V_17 , V_25 ) ;
V_17 -> V_36 = V_26 ;
F_20 ( V_17 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_44 ) {
return 0 ;
}
V_8 = F_22 ( V_2 , & V_2 -> V_9 ,
V_45 * 64 * 1024 ,
V_46 ,
V_47 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_23 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_44 = true ;
if ( F_24 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 ) {
F_26 ( V_2 , & V_2 -> V_9 ) ;
F_27 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_44 = false ;
}
}
int F_28 ( struct V_1 * V_2 )
{
unsigned V_27 ;
int V_8 , V_48 = 0 ;
for ( V_27 = 0 ; V_27 < V_49 ; ++ V_27 ) {
struct V_16 * V_17 = V_2 -> V_50 [ V_27 ] ;
if ( ! V_17 || ! V_17 -> V_29 )
continue;
V_8 = F_29 ( V_17 , V_51 ) ;
if ( V_8 ) {
V_17 -> V_29 = false ;
if ( V_17 == & V_2 -> V_52 . V_53 [ 0 ] ) {
F_30 ( L_7 , V_8 ) ;
V_2 -> V_54 = false ;
return V_8 ;
} else {
F_30 ( L_8 , V_27 , V_8 ) ;
V_48 = V_8 ;
}
}
}
return V_48 ;
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
