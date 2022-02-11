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
V_28 = V_17 -> V_34 -> V_35 + V_18 *
V_17 -> V_34 -> V_36 ;
V_8 = F_9 ( V_17 , V_28 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_17 -> V_34 -> V_37 )
V_25 = F_10 ( V_17 ) ;
if ( V_4 ) {
V_8 = F_11 ( V_17 , V_22 ) ;
if ( V_8 ) {
F_12 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_34 -> V_38 )
F_13 ( V_17 ) ;
* V_17 -> V_39 = 1 ;
V_23 = V_17 -> V_40 == V_26 ;
V_24 = V_17 -> V_40 != V_26 ;
if ( V_22 && V_17 -> V_34 -> V_41 ) {
if ( V_24 )
V_27 |= V_42 ;
V_27 |= V_22 -> V_43 ;
F_14 ( V_17 , V_27 ) ;
}
for ( V_29 = 0 ; V_29 < V_18 ; ++ V_29 ) {
V_7 = & V_19 [ V_29 ] ;
if ( ( V_7 -> V_44 & V_45 ) &&
V_23 &&
! ( V_27 & V_46 ) )
continue;
F_15 ( V_17 , V_7 , V_22 ? V_22 -> V_33 : 0 ,
V_24 ) ;
V_24 = false ;
}
if ( V_17 -> V_34 -> V_47 )
F_16 ( V_17 ) ;
V_8 = F_17 ( V_17 , V_15 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_22 && V_22 -> V_33 )
F_18 ( V_2 , V_22 -> V_33 ) ;
F_12 ( V_17 ) ;
return V_8 ;
}
if ( V_22 && V_22 -> V_48 ) {
F_19 ( V_17 , V_22 -> V_48 , V_22 -> V_49 ,
V_50 ) ;
}
if ( V_25 != ~ 0 && V_17 -> V_34 -> V_51 )
F_20 ( V_17 , V_25 ) ;
V_17 -> V_40 = V_26 ;
if ( V_17 -> V_34 -> V_52 )
F_21 ( V_17 ) ;
F_22 ( V_17 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_53 ) {
return 0 ;
}
V_8 = F_24 ( V_2 , & V_2 -> V_9 ,
V_54 * 64 * 1024 ,
V_55 ,
V_56 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_25 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_53 = true ;
if ( F_26 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 ) {
F_28 ( V_2 , & V_2 -> V_9 ) ;
F_29 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_53 = false ;
}
}
int F_30 ( struct V_1 * V_2 )
{
unsigned V_29 ;
int V_8 , V_57 = 0 ;
for ( V_29 = 0 ; V_29 < V_58 ; ++ V_29 ) {
struct V_16 * V_17 = V_2 -> V_59 [ V_29 ] ;
if ( ! V_17 || ! V_17 -> V_31 )
continue;
V_8 = F_31 ( V_17 , V_60 ) ;
if ( V_8 ) {
V_17 -> V_31 = false ;
if ( V_17 == & V_2 -> V_61 . V_62 [ 0 ] ) {
F_32 ( L_7 , V_8 ) ;
V_2 -> V_63 = false ;
return V_8 ;
} else {
F_32 ( L_8 , V_29 , V_8 ) ;
V_57 = V_8 ;
}
}
}
return V_57 ;
}
static int F_33 ( struct V_64 * V_65 , void * V_66 )
{
struct V_67 * V_68 = (struct V_67 * ) V_65 -> V_69 ;
struct V_70 * V_11 = V_68 -> V_71 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_72 ;
F_34 ( & V_2 -> V_9 , V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
#if F_35 ( V_73 )
return F_36 ( V_2 , V_74 , 1 ) ;
#else
return 0 ;
#endif
}
