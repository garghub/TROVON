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
V_4 &= V_15 ;
F_1 ( V_2 , V_7 , V_4 ) ;
V_14 = V_4 & ( V_16 | V_17 ) ;
if ( V_14 ) {
V_2 -> V_18 = V_14 ;
F_8 ( & V_2 -> V_19 ) ;
return V_20 ;
}
if ( V_4 & V_11 ) {
F_6 ( V_2 ) ;
if ( ! ( V_4 & V_21 ) )
return V_20 ;
}
if ( V_4 & V_21 ) {
if ( V_2 -> V_6 )
V_2 -> V_18 = V_22 ;
else
V_2 -> V_18 = 0 ;
F_8 ( & V_2 -> V_19 ) ;
return V_20 ;
}
if ( V_4 & V_8 ) {
F_5 ( V_2 ) ;
return V_20 ;
}
return V_23 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_1 V_26 ;
unsigned long V_27 ;
V_2 -> V_10 = V_25 -> V_28 ;
V_2 -> V_6 = V_25 -> V_29 ;
F_10 ( & V_2 -> V_19 ) ;
F_1 ( V_2 , V_30 , V_31 ) ;
if ( V_25 -> V_32 & V_33 ) {
V_26 = V_34 | V_35 ;
} else {
V_26 = V_36 ;
F_5 ( V_2 ) ;
}
V_26 |= V_37 | V_38 | V_39 ;
F_1 ( V_2 , V_40 , V_25 -> V_41 ) ;
F_1 ( V_2 , V_42 , V_25 -> V_29 ) ;
F_1 ( V_2 , V_30 , V_26 ) ;
V_27 = F_11 ( & V_2 -> V_19 ,
V_43 ) ;
F_1 ( V_2 , V_30 , V_31 ) ;
if ( ! V_27 ) {
F_12 ( V_2 -> V_44 , L_1 ) ;
return - V_45 ;
}
if ( F_13 ( ! V_2 -> V_18 ) )
return 0 ;
if ( ( V_2 -> V_18 & V_17 ) &&
( V_25 -> V_32 & V_46 ) )
return 0 ;
F_12 ( V_2 -> V_44 , L_2 , V_2 -> V_18 ) ;
if ( V_2 -> V_18 & V_17 )
return - V_47 ;
else
return - V_48 ;
}
static int F_14 ( struct V_49 * V_50 , struct V_24 V_51 [] ,
int V_52 )
{
struct V_1 * V_2 = F_15 ( V_50 ) ;
int V_53 ;
int V_54 = 0 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_54 = F_9 ( V_2 , & V_51 [ V_53 ] ) ;
if ( V_54 )
break;
}
return V_54 ? : V_53 ;
}
static T_1 F_16 ( struct V_49 * V_50 )
{
return V_55 | V_56 ;
}
static int F_17 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 , * V_61 ;
T_1 V_62 , V_63 ;
int V_54 ;
struct V_49 * V_50 ;
V_2 = F_18 ( & V_58 -> V_44 , sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
F_19 ( V_58 , V_2 ) ;
V_2 -> V_44 = & V_58 -> V_44 ;
F_20 ( & V_2 -> V_19 ) ;
V_60 = F_21 ( V_58 , V_66 , 0 ) ;
V_2 -> V_5 = F_22 ( & V_58 -> V_44 , V_60 ) ;
if ( F_23 ( V_2 -> V_5 ) )
return F_24 ( V_2 -> V_5 ) ;
V_2 -> V_67 = F_25 ( & V_58 -> V_44 , NULL ) ;
if ( F_23 ( V_2 -> V_67 ) ) {
F_12 ( & V_58 -> V_44 , L_3 ) ;
return F_24 ( V_2 -> V_67 ) ;
}
V_54 = F_26 ( V_58 -> V_44 . V_68 , L_4 ,
& V_62 ) ;
if ( V_54 < 0 ) {
F_27 ( & V_58 -> V_44 ,
L_5 ) ;
V_62 = 100000 ;
}
V_63 = F_28 ( F_29 ( V_2 -> V_67 ) , V_62 ) ;
if ( V_63 & 1 )
V_63 ++ ;
if ( ( V_63 < V_69 ) ||
( V_63 > V_70 ) ) {
F_12 ( & V_58 -> V_44 , L_6 ) ;
return - V_71 ;
}
F_1 ( V_2 , V_72 , V_63 ) ;
V_61 = F_21 ( V_58 , V_73 , 0 ) ;
if ( ! V_61 ) {
F_12 ( & V_58 -> V_44 , L_7 ) ;
return - V_71 ;
}
V_2 -> V_61 = V_61 -> V_74 ;
V_54 = F_30 ( V_2 -> V_61 , F_7 , V_75 ,
F_31 ( & V_58 -> V_44 ) , V_2 ) ;
if ( V_54 ) {
F_12 ( & V_58 -> V_44 , L_8 ) ;
return - V_71 ;
}
V_50 = & V_2 -> V_76 ;
F_32 ( V_50 , V_2 ) ;
V_50 -> V_77 = V_78 ;
V_50 -> V_79 = V_80 ;
F_33 ( V_50 -> V_81 , L_9 , sizeof( V_50 -> V_81 ) ) ;
V_50 -> V_82 = & V_83 ;
V_50 -> V_44 . V_84 = & V_58 -> V_44 ;
V_50 -> V_44 . V_68 = V_58 -> V_44 . V_68 ;
F_1 ( V_2 , V_30 , 0 ) ;
V_54 = F_34 ( V_50 ) ;
if ( V_54 )
F_35 ( V_2 -> V_61 , V_2 ) ;
return V_54 ;
}
static int F_36 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_37 ( V_58 ) ;
F_35 ( V_2 -> V_61 , V_2 ) ;
F_38 ( & V_2 -> V_76 ) ;
return 0 ;
}
