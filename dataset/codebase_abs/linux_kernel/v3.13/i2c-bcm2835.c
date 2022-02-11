static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_4 ;
while ( V_2 -> V_6 ) {
V_4 = F_3 ( V_2 , V_7 ) ;
if ( ! ( V_4 & V_8 ) )
break;
F_1 ( V_2 , V_9 ,
* V_2 -> V_10 ) ;
V_2 -> V_10 ++ ;
V_2 -> V_6 -- ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_4 ;
while ( V_2 -> V_6 ) {
V_4 = F_3 ( V_2 , V_7 ) ;
if ( ! ( V_4 & V_11 ) )
break;
* V_2 -> V_10 = F_3 ( V_2 ,
V_9 ) ;
V_2 -> V_10 ++ ;
V_2 -> V_6 -- ;
}
}
static T_2 F_7 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
T_1 V_4 , V_14 ;
V_4 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_7 , V_4 ) ;
V_14 = V_4 & ( V_15 | V_16 ) ;
if ( V_14 ) {
V_2 -> V_17 = V_14 ;
F_8 ( & V_2 -> V_18 ) ;
return V_19 ;
}
if ( V_4 & V_11 ) {
F_6 ( V_2 ) ;
if ( ! ( V_4 & V_20 ) )
return V_19 ;
}
if ( V_4 & V_20 ) {
if ( V_2 -> V_6 )
V_2 -> V_17 = V_21 ;
else
V_2 -> V_17 = 0 ;
F_8 ( & V_2 -> V_18 ) ;
return V_19 ;
}
if ( V_4 & V_8 ) {
F_5 ( V_2 ) ;
return V_19 ;
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_1 V_25 ;
int V_26 ;
V_2 -> V_10 = V_24 -> V_27 ;
V_2 -> V_6 = V_24 -> V_28 ;
F_10 ( & V_2 -> V_18 ) ;
F_1 ( V_2 , V_29 , V_30 ) ;
if ( V_24 -> V_31 & V_32 ) {
V_25 = V_33 | V_34 ;
} else {
V_25 = V_35 ;
F_5 ( V_2 ) ;
}
V_25 |= V_36 | V_37 | V_38 ;
F_1 ( V_2 , V_39 , V_24 -> V_40 ) ;
F_1 ( V_2 , V_41 , V_24 -> V_28 ) ;
F_1 ( V_2 , V_29 , V_25 ) ;
V_26 = F_11 ( & V_2 -> V_18 ,
V_42 ) ;
F_1 ( V_2 , V_29 , V_30 ) ;
if ( ! V_26 ) {
F_12 ( V_2 -> V_43 , L_1 ) ;
return - V_44 ;
}
if ( F_13 ( ! V_2 -> V_17 ) )
return 0 ;
if ( ( V_2 -> V_17 & V_16 ) &&
( V_24 -> V_31 & V_45 ) )
return 0 ;
F_12 ( V_2 -> V_43 , L_2 , V_2 -> V_17 ) ;
if ( V_2 -> V_17 & V_16 )
return - V_46 ;
else
return - V_47 ;
}
static int F_14 ( struct V_48 * V_49 , struct V_23 V_50 [] ,
int V_51 )
{
struct V_1 * V_2 = F_15 ( V_49 ) ;
int V_52 ;
int V_53 = 0 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
V_53 = F_9 ( V_2 , & V_50 [ V_52 ] ) ;
if ( V_53 )
break;
}
return V_53 ? : V_52 ;
}
static T_1 F_16 ( struct V_48 * V_49 )
{
return V_54 | V_55 ;
}
static int F_17 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 , * V_60 , * V_61 ;
T_1 V_62 , V_63 ;
int V_53 ;
struct V_48 * V_49 ;
V_2 = F_18 ( & V_57 -> V_43 , sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 ) {
F_12 ( & V_57 -> V_43 , L_3 ) ;
return - V_65 ;
}
F_19 ( V_57 , V_2 ) ;
V_2 -> V_43 = & V_57 -> V_43 ;
F_20 ( & V_2 -> V_18 ) ;
V_59 = F_21 ( V_57 , V_66 , 0 ) ;
if ( ! V_59 ) {
F_12 ( & V_57 -> V_43 , L_4 ) ;
return - V_67 ;
}
V_60 = F_22 ( & V_57 -> V_43 , V_59 -> V_68 ,
F_23 ( V_59 ) ,
F_24 ( & V_57 -> V_43 ) ) ;
if ( ! V_60 ) {
F_12 ( & V_57 -> V_43 , L_5 ) ;
return - V_69 ;
}
V_2 -> V_5 = F_25 ( & V_57 -> V_43 , V_59 -> V_68 ,
F_23 ( V_59 ) ) ;
if ( ! V_2 -> V_5 ) {
F_12 ( & V_57 -> V_43 , L_6 ) ;
return - V_65 ;
}
V_2 -> V_70 = F_26 ( & V_57 -> V_43 , NULL ) ;
if ( F_27 ( V_2 -> V_70 ) ) {
F_12 ( & V_57 -> V_43 , L_7 ) ;
return F_28 ( V_2 -> V_70 ) ;
}
V_53 = F_29 ( V_57 -> V_43 . V_71 , L_8 ,
& V_62 ) ;
if ( V_53 < 0 ) {
F_30 ( & V_57 -> V_43 ,
L_9 ) ;
V_62 = 100000 ;
}
V_63 = F_31 ( F_32 ( V_2 -> V_70 ) , V_62 ) ;
if ( V_63 & 1 )
V_63 ++ ;
F_1 ( V_2 , V_72 , V_63 ) ;
V_61 = F_21 ( V_57 , V_73 , 0 ) ;
if ( ! V_61 ) {
F_12 ( & V_57 -> V_43 , L_10 ) ;
return - V_67 ;
}
V_2 -> V_61 = V_61 -> V_68 ;
V_53 = F_33 ( V_2 -> V_61 , F_7 , V_74 ,
F_24 ( & V_57 -> V_43 ) , V_2 ) ;
if ( V_53 ) {
F_12 ( & V_57 -> V_43 , L_11 ) ;
return - V_67 ;
}
V_49 = & V_2 -> V_75 ;
F_34 ( V_49 , V_2 ) ;
V_49 -> V_76 = V_77 ;
V_49 -> V_78 = V_79 ;
F_35 ( V_49 -> V_80 , L_12 , sizeof( V_49 -> V_80 ) ) ;
V_49 -> V_81 = & V_82 ;
V_49 -> V_43 . V_83 = & V_57 -> V_43 ;
V_49 -> V_43 . V_71 = V_57 -> V_43 . V_71 ;
F_1 ( V_2 , V_29 , 0 ) ;
V_53 = F_36 ( V_49 ) ;
if ( V_53 )
F_37 ( V_2 -> V_61 , V_2 ) ;
return V_53 ;
}
static int F_38 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_39 ( V_57 ) ;
F_37 ( V_2 -> V_61 , V_2 ) ;
F_40 ( & V_2 -> V_75 ) ;
return 0 ;
}
