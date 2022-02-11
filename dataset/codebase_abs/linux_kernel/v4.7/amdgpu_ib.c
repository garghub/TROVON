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
struct V_14 * V_26 ;
T_1 V_27 ;
unsigned V_28 ;
int V_8 = 0 ;
if ( V_18 == 0 )
return - V_29 ;
if ( V_22 ) {
V_4 = V_22 -> V_4 ;
V_27 = V_22 -> V_27 ;
} else {
V_4 = NULL ;
V_27 = 0 ;
}
if ( ! V_17 -> V_30 ) {
F_3 ( V_2 -> V_11 , L_2 ) ;
return - V_29 ;
}
if ( V_4 && ! V_22 -> V_31 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return - V_29 ;
}
V_8 = F_9 ( V_17 , 256 * V_18 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_17 -> type == V_32 && V_17 -> V_33 -> V_34 )
V_25 = F_10 ( V_17 ) ;
if ( V_4 ) {
V_8 = F_11 ( V_17 , V_22 -> V_31 , V_22 -> V_35 ,
V_22 -> V_36 , V_22 -> V_37 ,
V_22 -> V_38 , V_22 -> V_39 ,
V_22 -> V_40 , V_22 -> V_41 ) ;
if ( V_8 ) {
F_12 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_33 -> V_42 )
F_13 ( V_17 ) ;
* V_17 -> V_43 = 1 ;
V_23 = V_17 -> V_44 == V_27 ;
V_24 = V_17 -> V_44 != V_27 ;
for ( V_28 = 0 ; V_28 < V_18 ; ++ V_28 ) {
V_7 = & V_19 [ V_28 ] ;
if ( ( V_7 -> V_45 & V_46 ) && V_23 )
continue;
F_14 ( V_17 , V_7 , V_22 ? V_22 -> V_31 : 0 ,
V_24 ) ;
V_24 = false ;
}
if ( V_17 -> V_33 -> V_47 )
F_15 ( V_17 ) ;
V_8 = F_16 ( V_17 , & V_26 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_22 && V_22 -> V_31 )
F_17 ( V_2 , V_22 -> V_31 ) ;
F_12 ( V_17 ) ;
return V_8 ;
}
if ( V_22 && V_22 -> V_48 ) {
T_1 V_49 = F_18 ( V_22 -> V_48 ) ;
V_49 += V_22 -> V_50 ;
F_19 ( V_17 , V_49 , V_22 -> V_51 ,
V_52 ) ;
}
if ( V_15 )
* V_15 = F_20 ( V_26 ) ;
if ( V_25 != ~ 0 && V_17 -> V_33 -> V_53 )
F_21 ( V_17 , V_25 ) ;
V_17 -> V_44 = V_27 ;
F_22 ( V_17 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_54 ) {
return 0 ;
}
V_8 = F_24 ( V_2 , & V_2 -> V_9 ,
V_55 * 64 * 1024 ,
V_56 ,
V_57 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_25 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_54 = true ;
if ( F_26 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_54 ) {
F_28 ( V_2 , & V_2 -> V_9 ) ;
F_29 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_54 = false ;
}
}
int F_30 ( struct V_1 * V_2 )
{
unsigned V_28 ;
int V_8 ;
for ( V_28 = 0 ; V_28 < V_58 ; ++ V_28 ) {
struct V_16 * V_17 = V_2 -> V_59 [ V_28 ] ;
if ( ! V_17 || ! V_17 -> V_30 )
continue;
V_8 = F_31 ( V_17 ) ;
if ( V_8 ) {
V_17 -> V_30 = false ;
if ( V_17 == & V_2 -> V_60 . V_61 [ 0 ] ) {
F_32 ( L_7 , V_8 ) ;
V_2 -> V_62 = false ;
return V_8 ;
} else {
F_32 ( L_8 , V_28 , V_8 ) ;
}
}
}
return 0 ;
}
static int F_33 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_11 = V_67 -> V_70 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_71 ;
F_34 ( & V_2 -> V_9 , V_64 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
#if F_35 ( V_72 )
return F_36 ( V_2 , V_73 , 1 ) ;
#else
return 0 ;
#endif
}
