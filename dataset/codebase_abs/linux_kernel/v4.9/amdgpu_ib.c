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
T_2 V_27 = 0 , V_28 ;
unsigned V_29 ;
int V_8 = 0 ;
if ( V_18 == 0 )
return - V_30 ;
if ( V_22 ) {
V_4 = V_22 -> V_4 ;
V_26 = V_22 -> V_26 ;
} else {
V_4 = NULL ;
V_26 = 0 ;
}
if ( ! V_17 -> V_31 ) {
F_3 ( V_2 -> V_11 , L_2 , V_17 -> V_32 ) ;
return - V_30 ;
}
if ( V_4 && ! V_22 -> V_33 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return - V_30 ;
}
V_28 = F_9 ( V_17 ) +
V_18 * F_10 ( V_17 ) ;
V_8 = F_11 ( V_17 , V_28 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_17 -> type == V_34 && V_17 -> V_35 -> V_36 )
V_25 = F_12 ( V_17 ) ;
if ( V_4 ) {
V_8 = F_13 ( V_17 , V_22 ) ;
if ( V_8 ) {
F_14 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_35 -> V_37 )
F_15 ( V_17 ) ;
* V_17 -> V_38 = 1 ;
V_23 = V_17 -> V_39 == V_26 ;
V_24 = V_17 -> V_39 != V_26 ;
if ( V_22 && V_17 -> V_35 -> V_40 ) {
if ( V_24 )
V_27 |= V_41 ;
V_27 |= V_22 -> V_42 ;
F_16 ( V_17 , V_27 ) ;
}
for ( V_29 = 0 ; V_29 < V_18 ; ++ V_29 ) {
V_7 = & V_19 [ V_29 ] ;
if ( ( V_7 -> V_43 & V_44 ) &&
V_23 &&
! ( V_27 & V_45 ) )
continue;
F_17 ( V_17 , V_7 , V_22 ? V_22 -> V_33 : 0 ,
V_24 ) ;
V_24 = false ;
}
if ( V_17 -> V_35 -> V_46 )
F_18 ( V_17 ) ;
V_8 = F_19 ( V_17 , V_15 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_22 && V_22 -> V_33 )
F_20 ( V_2 , V_22 -> V_33 ) ;
F_14 ( V_17 ) ;
return V_8 ;
}
if ( V_22 && V_22 -> V_47 ) {
F_21 ( V_17 , V_22 -> V_47 , V_22 -> V_48 ,
V_49 ) ;
}
if ( V_25 != ~ 0 && V_17 -> V_35 -> V_50 )
F_22 ( V_17 , V_25 ) ;
V_17 -> V_39 = V_26 ;
if ( V_17 -> V_35 -> V_51 )
F_23 ( V_17 ) ;
F_24 ( V_17 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_52 ) {
return 0 ;
}
V_8 = F_26 ( V_2 , & V_2 -> V_9 ,
V_53 * 64 * 1024 ,
V_54 ,
V_55 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_27 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_52 = true ;
if ( F_28 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 ) {
F_30 ( V_2 , & V_2 -> V_9 ) ;
F_31 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_52 = false ;
}
}
int F_32 ( struct V_1 * V_2 )
{
unsigned V_29 ;
int V_8 , V_56 = 0 ;
for ( V_29 = 0 ; V_29 < V_57 ; ++ V_29 ) {
struct V_16 * V_17 = V_2 -> V_58 [ V_29 ] ;
if ( ! V_17 || ! V_17 -> V_31 )
continue;
V_8 = F_33 ( V_17 , V_59 ) ;
if ( V_8 ) {
V_17 -> V_31 = false ;
if ( V_17 == & V_2 -> V_60 . V_61 [ 0 ] ) {
F_34 ( L_7 , V_8 ) ;
V_2 -> V_62 = false ;
return V_8 ;
} else {
F_34 ( L_8 , V_29 , V_8 ) ;
V_56 = V_8 ;
}
}
}
return V_56 ;
}
static int F_35 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_11 = V_67 -> V_70 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_71 ;
F_36 ( & V_2 -> V_9 , V_64 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
#if F_37 ( V_72 )
return F_38 ( V_2 , V_73 , 1 ) ;
#else
return 0 ;
#endif
}
