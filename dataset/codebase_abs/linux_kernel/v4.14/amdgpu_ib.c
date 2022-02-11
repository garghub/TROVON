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
struct V_14 * V_22 = NULL ;
bool V_23 , V_24 ;
unsigned V_25 = ~ 0 ;
struct V_3 * V_4 ;
T_1 V_26 ;
T_2 V_27 = 0 , V_28 ;
unsigned V_29 ;
int V_8 = 0 ;
bool V_30 = false ;
if ( V_18 == 0 )
return - V_31 ;
if ( V_21 ) {
V_4 = V_21 -> V_4 ;
V_26 = V_21 -> V_26 ;
} else {
V_4 = NULL ;
V_26 = 0 ;
}
if ( ! V_17 -> V_32 ) {
F_3 ( V_2 -> V_11 , L_2 , V_17 -> V_33 ) ;
return - V_31 ;
}
if ( V_4 && ! V_21 -> V_34 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return - V_31 ;
}
V_28 = V_17 -> V_35 -> V_36 + V_18 *
V_17 -> V_35 -> V_37 ;
V_8 = F_9 ( V_17 , V_28 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
return V_8 ;
}
if ( V_17 -> V_35 -> V_38 && V_21 &&
( ( V_22 = F_10 ( & V_21 -> V_39 ) ) ||
F_11 ( V_17 , V_21 ) ) ) {
V_30 = true ;
F_12 ( V_22 ) ;
}
if ( V_17 -> V_35 -> V_40 )
V_17 -> V_35 -> V_40 ( V_17 ) ;
if ( V_21 ) {
V_8 = F_13 ( V_17 , V_21 , V_30 ) ;
if ( V_8 ) {
F_14 ( V_17 ) ;
return V_8 ;
}
}
if ( V_17 -> V_35 -> V_41 )
V_25 = F_15 ( V_17 ) ;
if ( V_17 -> V_35 -> V_42
#ifdef F_16
&& ! ( V_2 -> V_43 & V_44 )
#endif
)
F_17 ( V_17 ) ;
V_23 = V_17 -> V_45 == V_26 ;
V_24 = V_17 -> V_45 != V_26 ;
if ( V_21 && V_17 -> V_35 -> V_46 ) {
if ( V_24 )
V_27 |= V_47 ;
V_27 |= V_21 -> V_48 ;
F_18 ( V_17 , V_27 ) ;
}
for ( V_29 = 0 ; V_29 < V_18 ; ++ V_29 ) {
V_7 = & V_19 [ V_29 ] ;
if ( ( V_7 -> V_43 & V_49 ) &&
V_23 &&
! ( V_27 & V_50 ) &&
! F_19 ( V_2 ) )
continue;
F_20 ( V_17 , V_7 , V_21 ? V_21 -> V_34 : 0 ,
V_24 ) ;
V_24 = false ;
}
if ( V_17 -> V_35 -> V_51 )
F_21 ( V_17 , false ) ;
if ( V_17 -> V_35 -> V_52
#ifdef F_16
&& ! ( V_2 -> V_43 & V_44 )
#endif
)
F_22 ( V_17 ) ;
V_8 = F_23 ( V_17 , V_15 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_5 , V_8 ) ;
if ( V_21 && V_21 -> V_34 )
F_24 ( V_2 , V_17 -> V_35 -> V_53 ,
V_21 -> V_34 ) ;
F_14 ( V_17 ) ;
return V_8 ;
}
if ( V_17 -> V_35 -> V_54 )
V_17 -> V_35 -> V_54 ( V_17 ) ;
if ( V_21 && V_21 -> V_55 ) {
F_25 ( V_17 , V_21 -> V_55 , V_21 -> V_56 ,
V_57 ) ;
}
if ( V_25 != ~ 0 && V_17 -> V_35 -> V_58 )
F_26 ( V_17 , V_25 ) ;
V_17 -> V_45 = V_26 ;
if ( V_4 && V_17 -> V_35 -> V_59 )
F_27 ( V_17 ) ;
F_28 ( V_17 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_60 ) {
return 0 ;
}
V_8 = F_30 ( V_2 , & V_2 -> V_9 ,
V_61 * 64 * 1024 ,
V_62 ,
V_63 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_31 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_60 = true ;
if ( F_32 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 ) {
F_34 ( V_2 , & V_2 -> V_9 ) ;
F_35 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_60 = false ;
}
}
int F_36 ( struct V_1 * V_2 )
{
unsigned V_29 ;
int V_8 , V_64 = 0 ;
for ( V_29 = 0 ; V_29 < V_65 ; ++ V_29 ) {
struct V_16 * V_17 = V_2 -> V_66 [ V_29 ] ;
if ( ! V_17 || ! V_17 -> V_32 )
continue;
V_8 = F_37 ( V_17 , V_67 ) ;
if ( V_8 ) {
V_17 -> V_32 = false ;
if ( V_17 == & V_2 -> V_68 . V_69 [ 0 ] ) {
F_38 ( L_7 , V_8 ) ;
V_2 -> V_70 = false ;
return V_8 ;
} else {
F_38 ( L_8 , V_29 , V_8 ) ;
V_64 = V_8 ;
}
}
}
return V_64 ;
}
static int F_39 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_75 = (struct V_74 * ) V_72 -> V_76 ;
struct V_77 * V_11 = V_75 -> V_78 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_79 ;
F_40 ( & V_2 -> V_9 , V_72 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
#if F_41 ( V_80 )
return F_42 ( V_2 , V_81 , 1 ) ;
#else
return 0 ;
#endif
}
