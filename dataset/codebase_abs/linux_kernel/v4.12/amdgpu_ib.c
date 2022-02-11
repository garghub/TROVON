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
if ( V_17 -> V_33 -> V_36 && V_21 && V_21 -> V_37 )
F_10 ( V_17 ) ;
if ( V_4 ) {
V_8 = F_11 ( V_17 , V_21 ) ;
if ( V_8 ) {
F_12 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_33 -> V_38 )
V_24 = F_13 ( V_17 ) ;
if ( V_17 -> V_33 -> V_39
#ifdef F_14
&& ! ( V_2 -> V_40 & V_41 )
#endif
)
F_15 ( V_17 ) ;
V_22 = V_17 -> V_42 == V_25 ;
V_23 = V_17 -> V_42 != V_25 ;
if ( V_21 && V_17 -> V_33 -> V_43 ) {
if ( V_23 )
V_26 |= V_44 ;
V_26 |= V_21 -> V_45 ;
if ( V_4 )
V_26 |= V_46 ;
F_16 ( V_17 , V_26 ) ;
}
for ( V_28 = 0 ; V_28 < V_18 ; ++ V_28 ) {
V_7 = & V_19 [ V_28 ] ;
if ( ( V_7 -> V_40 & V_47 ) &&
V_22 &&
! ( V_26 & V_48 ) &&
! F_17 ( V_2 ) )
continue;
F_18 ( V_17 , V_7 , V_21 ? V_21 -> V_32 : 0 ,
V_23 ) ;
V_23 = false ;
}
if ( V_17 -> V_33 -> V_49
#ifdef F_14
&& ! ( V_2 -> V_40 & V_41 )
#endif
)
F_19 ( V_17 ) ;
V_8 = F_20 ( V_17 , V_15 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_21 && V_21 -> V_32 )
F_21 ( V_2 , V_17 -> V_33 -> V_50 ,
V_21 -> V_32 ) ;
F_12 ( V_17 ) ;
return V_8 ;
}
if ( V_17 -> V_33 -> V_51 )
V_17 -> V_33 -> V_51 ( V_17 ) ;
if ( V_21 && V_21 -> V_52 ) {
F_22 ( V_17 , V_21 -> V_52 , V_21 -> V_53 ,
V_54 ) ;
}
if ( V_24 != ~ 0 && V_17 -> V_33 -> V_55 )
F_23 ( V_17 , V_24 ) ;
V_17 -> V_42 = V_25 ;
if ( V_4 && V_17 -> V_33 -> V_56 )
F_24 ( V_17 ) ;
F_25 ( V_17 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_57 ) {
return 0 ;
}
V_8 = F_27 ( V_2 , & V_2 -> V_9 ,
V_58 * 64 * 1024 ,
V_59 ,
V_60 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_28 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_57 = true ;
if ( F_29 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 ) {
F_31 ( V_2 , & V_2 -> V_9 ) ;
F_32 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_57 = false ;
}
}
int F_33 ( struct V_1 * V_2 )
{
unsigned V_28 ;
int V_8 , V_61 = 0 ;
for ( V_28 = 0 ; V_28 < V_62 ; ++ V_28 ) {
struct V_16 * V_17 = V_2 -> V_63 [ V_28 ] ;
if ( ! V_17 || ! V_17 -> V_30 )
continue;
V_8 = F_34 ( V_17 , V_64 ) ;
if ( V_8 ) {
V_17 -> V_30 = false ;
if ( V_17 == & V_2 -> V_65 . V_66 [ 0 ] ) {
F_35 ( L_7 , V_8 ) ;
V_2 -> V_67 = false ;
return V_8 ;
} else {
F_35 ( L_8 , V_28 , V_8 ) ;
V_61 = V_8 ;
}
}
}
return V_61 ;
}
static int F_36 ( struct V_68 * V_69 , void * V_70 )
{
struct V_71 * V_72 = (struct V_71 * ) V_69 -> V_73 ;
struct V_74 * V_11 = V_72 -> V_75 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_76 ;
F_37 ( & V_2 -> V_9 , V_69 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
#if F_38 ( V_77 )
return F_39 ( V_2 , V_78 , 1 ) ;
#else
return 0 ;
#endif
}
