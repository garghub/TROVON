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
struct V_6 * V_19 , struct V_20 * V_21 ,
struct V_14 * * V_15 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_6 * V_7 = & V_19 [ 0 ] ;
bool V_22 , V_23 ;
unsigned V_24 = ~ 0 ;
struct V_3 * V_4 ;
T_1 V_25 ;
T_2 V_26 = 0 , V_27 ;
unsigned V_28 ;
int V_8 = 0 ;
if ( V_18 == 0 )
return - V_29 ;
if ( V_21 ) {
V_4 = V_21 -> V_4 ;
V_25 = V_21 -> V_25 ;
} else {
V_4 = NULL ;
V_25 = 0 ;
}
if ( ! V_17 -> V_30 ) {
F_3 ( V_2 -> V_11 , L_2 , V_17 -> V_31 ) ;
return - V_29 ;
}
if ( V_4 && ! V_21 -> V_32 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return - V_29 ;
}
V_27 = V_17 -> V_33 -> V_34 + V_18 *
V_17 -> V_33 -> V_35 ;
V_8 = F_9 ( V_17 , V_27 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_17 -> V_33 -> V_36 )
V_24 = F_10 ( V_17 ) ;
if ( V_4 ) {
V_8 = F_11 ( V_17 , V_21 ) ;
if ( V_8 ) {
F_12 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_33 -> V_37 )
F_13 ( V_17 ) ;
V_22 = V_17 -> V_38 == V_25 ;
V_23 = V_17 -> V_38 != V_25 ;
if ( V_21 && V_17 -> V_33 -> V_39 ) {
if ( V_23 )
V_26 |= V_40 ;
V_26 |= V_21 -> V_41 ;
if ( V_4 )
V_26 |= V_42 ;
F_14 ( V_17 , V_26 ) ;
}
for ( V_28 = 0 ; V_28 < V_18 ; ++ V_28 ) {
V_7 = & V_19 [ V_28 ] ;
if ( ( V_7 -> V_43 & V_44 ) &&
V_22 &&
! ( V_26 & V_45 ) &&
! F_15 ( V_2 ) )
continue;
F_16 ( V_17 , V_7 , V_21 ? V_21 -> V_32 : 0 ,
V_23 ) ;
V_23 = false ;
}
if ( V_17 -> V_33 -> V_46 )
F_17 ( V_17 ) ;
V_8 = F_18 ( V_17 , V_15 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_21 && V_21 -> V_32 )
F_19 ( V_2 , V_21 -> V_32 ) ;
F_12 ( V_17 ) ;
return V_8 ;
}
if ( V_21 && V_21 -> V_47 ) {
F_20 ( V_17 , V_21 -> V_47 , V_21 -> V_48 ,
V_49 ) ;
}
if ( V_24 != ~ 0 && V_17 -> V_33 -> V_50 )
F_21 ( V_17 , V_24 ) ;
V_17 -> V_38 = V_25 ;
if ( V_4 && V_17 -> V_33 -> V_51 )
F_22 ( V_17 ) ;
F_23 ( V_17 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_52 ) {
return 0 ;
}
V_8 = F_25 ( V_2 , & V_2 -> V_9 ,
V_53 * 64 * 1024 ,
V_54 ,
V_55 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_26 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_52 = true ;
if ( F_27 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 ) {
F_29 ( V_2 , & V_2 -> V_9 ) ;
F_30 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_52 = false ;
}
}
int F_31 ( struct V_1 * V_2 )
{
unsigned V_28 ;
int V_8 , V_56 = 0 ;
for ( V_28 = 0 ; V_28 < V_57 ; ++ V_28 ) {
struct V_16 * V_17 = V_2 -> V_58 [ V_28 ] ;
if ( ! V_17 || ! V_17 -> V_30 )
continue;
V_8 = F_32 ( V_17 , V_59 ) ;
if ( V_8 ) {
V_17 -> V_30 = false ;
if ( V_17 == & V_2 -> V_60 . V_61 [ 0 ] ) {
F_33 ( L_7 , V_8 ) ;
V_2 -> V_62 = false ;
return V_8 ;
} else {
F_33 ( L_8 , V_28 , V_8 ) ;
V_56 = V_8 ;
}
}
}
return V_56 ;
}
static int F_34 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_11 = V_67 -> V_70 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_71 ;
F_35 ( & V_2 -> V_9 , V_64 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
#if F_36 ( V_72 )
return F_37 ( V_2 , V_73 , 1 ) ;
#else
return 0 ;
#endif
}
