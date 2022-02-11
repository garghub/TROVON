int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 . V_6 . V_7 )
return - V_8 ;
V_4 -> V_9 = true ;
V_4 -> V_10 = true ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 100 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_15 ) &&
V_2 -> V_5 . V_6 . V_16 ) {
V_4 -> V_17 = true ;
V_4 -> V_18 = true ;
V_4 -> V_19 = V_2 -> V_5 . V_6 . V_20 ;
V_4 -> V_21 = V_2 -> V_5 . V_6 . V_22 ;
} else {
V_4 -> V_19 = 0 ;
V_4 -> V_21 = 0 ;
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
T_1 * V_23 )
{
T_1 V_24 ;
T_1 V_25 ;
T_2 V_26 ;
if ( V_2 -> V_5 . V_6 . V_7 )
return - V_8 ;
V_24 = F_4 ( V_2 -> V_27 , V_28 ,
V_29 , V_30 ) ;
V_25 = F_4 ( V_2 -> V_27 , V_28 ,
V_31 , V_32 ) ;
if ( V_24 == 0 )
return - V_33 ;
V_26 = ( T_2 ) V_25 * 100 ;
F_5 ( V_26 , V_24 ) ;
* V_23 = ( T_1 ) V_26 ;
if ( * V_23 > 100 )
* V_23 = 100 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_23 )
{
T_1 V_34 ;
T_1 V_35 ;
if ( V_2 -> V_5 . V_6 . V_7 ||
( V_2 -> V_5 . V_6 .
V_16 == 0 ) )
return - V_8 ;
V_34 = F_4 ( V_2 -> V_27 , V_28 ,
V_36 , V_37 ) ;
if ( V_34 == 0 )
return - V_33 ;
V_35 = F_7 ( V_2 ) ;
* V_23 = 60 * V_35 * 10000 / V_34 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_38 )
{
if ( V_2 -> V_39 ) {
V_2 -> V_40 =
F_4 ( V_2 -> V_27 , V_28 ,
V_41 , V_42 ) ;
V_2 -> V_43 =
F_4 ( V_2 -> V_27 , V_28 ,
V_41 , V_44 ) ;
V_2 -> V_39 = false ;
}
F_9 ( V_2 -> V_27 , V_28 ,
V_41 , V_44 , 0 ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_41 , V_42 , V_38 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_39 ) {
F_9 ( V_2 -> V_27 , V_28 ,
V_41 , V_42 , V_2 -> V_40 ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_41 , V_44 , V_2 -> V_43 ) ;
V_2 -> V_39 = true ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_45 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_46 ) ) {
F_12 ( V_2 -> V_27 , V_47 , V_48 ) ;
V_45 = F_13 ( V_2 -> V_49 , V_50 ) ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_15 ) )
V_2 -> V_51 -> V_52 ( V_2 ,
V_2 -> V_5 .
V_53 . V_54 ) ;
else
V_2 -> V_51 -> V_55 ( V_2 ,
V_2 -> V_5 .
V_53 . V_56 ) ;
} else {
F_12 ( V_2 -> V_27 , V_47 , V_57 ) ;
V_45 = F_13 ( V_2 -> V_49 , V_50 ) ;
}
if ( ! V_45 && V_2 -> V_5 .
V_53 . V_58 )
V_45 = F_14 ( V_2 -> V_49 ,
V_59 ,
V_2 -> V_5 .
V_53 . V_58 ) ;
V_2 -> V_60 = true ;
return V_45 ;
}
int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_60 = false ;
return F_13 ( V_2 -> V_49 , V_61 ) ;
}
int F_16 ( struct V_1 * V_2 ,
T_1 V_23 )
{
T_1 V_24 ;
T_1 V_25 ;
T_2 V_26 ;
if ( V_2 -> V_5 . V_6 . V_7 )
return 0 ;
if ( V_23 > 100 )
V_23 = 100 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_62 ) )
F_15 ( V_2 ) ;
V_24 = F_4 ( V_2 -> V_27 , V_28 ,
V_29 , V_30 ) ;
if ( V_24 == 0 )
return - V_33 ;
V_26 = ( T_2 ) V_23 * V_24 ;
F_5 ( V_26 , 100 ) ;
V_25 = ( T_1 ) V_26 ;
F_9 ( V_2 -> V_27 , V_28 ,
V_63 , V_64 , V_25 ) ;
return F_8 ( V_2 , V_65 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_45 ;
if ( V_2 -> V_5 . V_6 . V_7 )
return 0 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_62 ) ) {
V_45 = F_8 ( V_2 , V_65 ) ;
if ( ! V_45 )
V_45 = F_11 ( V_2 ) ;
} else
V_45 = F_10 ( V_2 ) ;
return V_45 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_23 )
{
T_1 V_34 ;
T_1 V_35 ;
if ( V_2 -> V_5 . V_6 . V_7 ||
( V_2 -> V_5 . V_6 .
V_16 == 0 ) ||
( V_23 < V_2 -> V_5 . V_6 . V_20 ) ||
( V_23 > V_2 -> V_5 . V_6 . V_22 ) )
return 0 ;
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_62 ) )
F_15 ( V_2 ) ;
V_35 = F_7 ( V_2 ) ;
V_34 = 60 * V_35 * 10000 / ( 8 * V_23 ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_36 , V_37 , V_34 ) ;
return F_8 ( V_2 , V_66 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_67 ;
V_67 = F_4 ( V_2 -> V_27 , V_28 ,
V_68 , V_69 ) ;
if ( V_67 & 0x200 )
V_67 = V_70 ;
else
V_67 = V_67 & 0x1ff ;
V_67 *= V_71 ;
return V_67 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_72 , T_1 V_73 )
{
T_1 V_74 = V_75 *
V_71 ;
T_1 V_76 = V_77 *
V_71 ;
if ( V_74 < V_72 )
V_74 = V_72 ;
if ( V_76 > V_73 )
V_76 = V_73 ;
if ( V_74 > V_76 )
return - V_33 ;
F_9 ( V_2 -> V_27 , V_28 ,
V_78 , V_79 ,
( V_76 / V_71 ) ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_78 , V_80 ,
( V_74 / V_71 ) ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_81 , V_82 ,
( V_76 / V_71 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_6 . V_16 )
F_9 ( V_2 -> V_27 , V_28 ,
V_83 , V_84 ,
V_2 -> V_5 . V_6 .
V_16 - 1 ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_41 , V_85 , 0x28 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
T_1 V_86 ;
V_86 = F_4 ( V_2 -> V_27 , V_28 ,
V_78 , V_87 ) ;
V_86 &= ~ ( V_88 | V_89 ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_78 , V_87 , V_86 ) ;
return F_13 ( V_2 -> V_49 , V_90 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
T_1 V_86 ;
V_86 = F_4 ( V_2 -> V_27 , V_28 ,
V_78 , V_87 ) ;
V_86 |= ( V_88 | V_89 ) ;
F_9 ( V_2 -> V_27 , V_28 ,
V_78 , V_87 , V_86 ) ;
return F_13 ( V_2 -> V_49 , V_91 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_45 = F_23 ( V_2 ) ;
if ( ! V_2 -> V_5 . V_6 . V_7 )
F_10 ( V_2 ) ;
return V_45 ;
}
static int F_25 ( struct V_1 * V_2 ,
void * V_92 , void * V_93 , void * V_94 , int V_45 )
{
if ( F_2 ( V_2 -> V_13 . V_14 ,
V_62 ) ) {
F_11 ( V_2 ) ;
F_8 ( V_2 , V_65 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
void * V_92 , void * V_93 , void * V_94 , int V_45 )
{
struct V_95 * V_96 = (struct V_95 * ) V_92 ;
if ( V_96 == NULL )
return - V_33 ;
return F_20 ( V_2 , V_96 -> V_97 , V_96 -> V_98 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
void * V_92 , void * V_93 , void * V_94 , int V_45 )
{
return F_21 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
void * V_92 , void * V_93 , void * V_94 , int V_45 )
{
return F_22 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
void * V_92 , void * V_93 , void * V_94 , int V_45 )
{
return F_23 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_6 . V_7 )
F_10 ( V_2 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_32 ( V_2 ,
& V_99 ,
& ( V_2 -> V_100 ) ) ;
if ( ! V_45 ) {
V_45 = F_32 ( V_2 ,
& V_101 ,
& ( V_2 -> V_102 ) ) ;
if ( V_45 )
F_33 ( V_2 , & ( V_2 -> V_100 ) ) ;
}
if ( ! V_45 )
V_2 -> V_39 = true ;
return V_45 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_33 ( V_2 , & ( V_2 -> V_100 ) ) ;
F_33 ( V_2 , & ( V_2 -> V_102 ) ) ;
return;
}
