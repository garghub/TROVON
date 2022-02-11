void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_2 -> V_6 = & V_7 ;
V_2 -> V_8 = & V_9 ;
V_4 -> V_10 = V_2 ;
F_2 ( & V_4 -> V_11 ) ;
}
static int F_3 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_3 * V_14 ;
int V_15 = 0 ;
struct V_1 * V_2 ;
V_15 = F_4 ( V_16 ) ;
if ( ! V_15 )
return - V_17 ;
V_15 = 0 ;
if ( ! F_5 ( V_18 ) ) {
V_15 = - V_19 ;
goto V_20;
}
if ( V_13 -> V_21 ) {
V_15 = - V_22 ;
goto V_20;
}
V_2 = F_6 ( V_12 ) ;
if ( ! V_2 ) {
V_15 = - V_17 ;
goto V_20;
}
V_14 = (struct V_3 * ) V_2 -> V_5 ;
if ( ! V_14 ) {
V_15 = - V_17 ;
goto V_20;
}
V_13 -> V_21 = ( void * ) V_14 ;
if ( V_14 -> V_23 ) {
V_15 = - V_24 ;
} else {
V_14 -> V_23 = F_7 ( V_25 , V_26 ) ;
if ( ! V_14 -> V_23 ) {
V_15 = - V_27 ;
} else {
V_14 -> V_28 = 0 ;
V_14 -> V_29 = 0 ;
V_14 -> V_30 = V_31 ;
}
}
V_20:
if ( V_15 )
F_8 ( V_16 ) ;
return V_15 ;
}
static int F_9 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_3 * V_14 ;
T_1 * V_32 ;
unsigned long V_33 ;
V_14 = (struct V_3 * ) ( V_13 -> V_21 ) ;
if ( ! V_14 )
goto V_20;
F_10 ( & V_14 -> V_11 , V_33 ) ;
V_32 = V_14 -> V_23 ;
V_14 -> V_23 = NULL ;
V_14 -> V_28 = V_14 -> V_29 ;
if ( V_14 -> V_34 & V_35 ) {
V_14 -> V_34 &= ~ V_35 ;
F_11 ( & V_14 -> V_36 ) ;
}
F_12 ( & V_14 -> V_11 , V_33 ) ;
F_13 ( V_32 ) ;
V_20:
F_8 ( V_16 ) ;
V_13 -> V_21 = NULL ;
return 0 ;
}
static T_2 F_14 ( struct V_13 * V_13 , char T_3 * V_32 , T_4 V_37 ,
T_5 * V_38 )
{
struct V_3 * V_14 ;
int V_39 ;
int V_40 ;
int V_41 = 0 ;
int V_42 = 0 ;
T_2 V_15 ;
unsigned long V_33 ;
V_14 = (struct V_3 * ) ( V_13 -> V_21 ) ;
if ( ! V_14 )
return - V_17 ;
F_10 ( & V_14 -> V_11 , V_33 ) ;
for (; ; ) {
V_39 = ( V_14 -> V_29 - V_14 -> V_28 ) & V_43 ;
if ( V_39 != 0 )
break;
V_14 -> V_34 |= V_44 ;
F_12 ( & V_14 -> V_11 , V_33 ) ;
V_15 = F_15 ( V_14 -> V_36 ,
( ( V_14 -> V_34 & V_44 ) == 0 ) ) ;
if ( V_15 )
return V_15 ;
F_10 ( & V_14 -> V_11 , V_33 ) ;
}
if ( V_39 > V_37 )
V_39 = V_37 ;
V_42 = V_39 ;
V_40 = V_25 - V_14 -> V_28 ;
if ( V_40 <= V_39 ) {
F_12 ( & V_14 -> V_11 , V_33 ) ;
V_15 = F_16 ( ( void T_3 * ) V_32 ,
V_14 -> V_23 + V_14 -> V_28 , V_40 ) ;
F_10 ( & V_14 -> V_11 , V_33 ) ;
if ( V_15 ) {
V_15 = - V_45 ;
goto V_20;
}
V_14 -> V_28 = 0 ;
V_39 -= V_40 ;
V_41 = V_40 ;
}
F_12 ( & V_14 -> V_11 , V_33 ) ;
V_15 = F_16 ( ( void T_3 * ) V_32 + V_41 ,
V_14 -> V_23 + V_14 -> V_28 , V_39 ) ;
F_10 ( & V_14 -> V_11 , V_33 ) ;
if ( V_15 ) {
V_15 = - V_45 ;
goto V_20;
}
V_14 -> V_28 += V_39 ;
* V_38 += V_42 ;
V_15 = V_42 ;
V_39 = ( V_14 -> V_29 - V_14 -> V_28 ) & V_43 ;
if ( V_14 -> V_34 & V_35 &&
( V_25 - V_39 ) > V_46 ) {
V_14 -> V_34 &= ~ V_35 ;
F_11 ( & V_14 -> V_36 ) ;
}
V_20:
F_12 ( & V_14 -> V_11 , V_33 ) ;
return V_15 ;
}
static unsigned int F_17 ( struct V_13 * V_13 ,
struct V_47 * V_48 )
{
unsigned int V_49 = 0 ;
struct V_3 * V_14 = V_13 -> V_21 ;
if ( V_14 -> V_28 != V_14 -> V_29 )
V_49 |= V_50 | V_51 ;
V_49 |= V_52 | V_53 ;
return V_49 ;
}
static long F_18 ( struct V_13 * V_13 , unsigned int V_54 ,
unsigned long V_55 )
{
struct V_3 * V_14 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
struct V_64 V_65 ;
unsigned int V_66 ;
void T_3 * V_67 = ( void T_3 * ) V_55 ;
V_14 = V_13 -> V_21 ;
switch ( V_54 ) {
case V_68 :
if ( F_19 ( & V_57 , V_67 , sizeof( struct V_56 ) ) )
return - V_45 ;
V_66 = V_57 . V_69 ;
if ( V_66 < 0 || V_66 > V_14 -> V_70 )
return - V_22 ;
V_61 = V_14 -> V_71 + V_66 ;
V_57 . V_72 = ( V_61 -> V_73 > 0 ) ? 1 : 0 ;
V_57 . V_74 = V_61 -> V_74 ;
V_57 . V_75 = V_61 -> V_75 ;
V_57 . V_76 = V_61 -> V_76 ;
V_57 . V_77 = V_61 -> V_78 ;
V_57 . V_79 = V_61 -> V_79 ;
V_57 . V_80 = V_61 -> V_80 ;
V_57 . V_81 = V_61 -> V_81 ;
V_57 . V_82 = V_61 -> V_82 ;
V_57 . V_83 = V_61 -> V_84 ;
if ( F_16 ( V_67 , & V_57 , sizeof( struct V_56 ) ) )
return - V_45 ;
break;
case V_85 :
V_59 . V_86 = ( V_14 -> V_86 & V_87 ) ? 1 : 0 ;
V_59 . V_70 = V_14 -> V_70 ;
V_59 . V_88 = V_14 -> V_88 ;
V_59 . V_89 = V_14 -> V_89 ;
memset ( & V_59 . V_90 , 0 , V_91 ) ;
strncpy ( V_59 . V_90 , V_14 -> V_90 , V_91 ) ;
if ( F_16 ( V_67 , & V_59 , sizeof( struct V_58 ) ) )
return - V_45 ;
break;
case V_92 :
if ( F_19 ( & V_63 , V_67 , sizeof( struct V_62 ) ) )
return - V_45 ;
V_14 -> V_93 = V_63 . V_94 ;
V_14 -> V_95 = V_63 . V_66 ;
break;
case V_96 :
if ( V_14 -> V_97 > 0 ) {
V_65 . V_98 = V_14 -> V_97 ;
memcpy ( & V_65 . V_99 , & V_14 -> V_100 , V_14 -> V_97 ) ;
} else {
V_65 . V_98 = 0 ;
}
if ( F_16 ( V_67 , & V_65 , sizeof( struct V_64 ) ) )
return - V_45 ;
break;
}
return 0 ;
}
static void F_20 ( struct V_3 * V_14 , T_1 * V_32 , int V_101 )
{
int V_39 ;
int V_40 ;
unsigned long V_33 ;
F_10 ( & V_14 -> V_11 , V_33 ) ;
while ( V_101 > 0 && V_14 -> V_23 != NULL ) {
V_39 = ( V_14 -> V_28 - V_14 -> V_29 - 1 ) & V_43 ;
if ( V_39 < ( V_25 - V_46 ) )
V_14 -> V_34 |= V_35 ;
if ( V_39 == 0 ) {
F_12 ( & V_14 -> V_11 , V_33 ) ;
return;
}
if ( V_39 > V_101 )
V_39 = V_101 ;
V_40 = V_25 - V_14 -> V_29 ;
if ( V_40 <= V_39 ) {
memcpy ( V_14 -> V_23 + V_14 -> V_29 , V_32 , V_40 ) ;
V_39 -= V_40 ;
V_14 -> V_29 = 0 ;
V_32 += V_40 ;
V_101 -= V_40 ;
}
memcpy ( V_14 -> V_23 + V_14 -> V_29 , V_32 , V_39 ) ;
V_14 -> V_29 += V_39 ;
V_32 += V_39 ;
V_101 -= V_39 ;
if ( V_14 -> V_29 >= V_25 )
F_21 ( L_1 ,
V_102 , V_14 -> V_29 ) ;
if ( V_14 -> V_34 & V_44 ) {
V_14 -> V_34 &= ~ V_44 ;
F_11 ( & V_14 -> V_36 ) ;
}
}
F_12 ( & V_14 -> V_11 , V_33 ) ;
}
void F_22 ( struct V_3 * V_14 , int type , T_1 * V_32 , int V_103 )
{
T_1 V_104 [ 5 ] ;
V_104 [ 0 ] = type ;
F_23 ( V_103 , V_104 + 1 ) ;
F_20 ( V_14 , V_104 , sizeof( V_104 ) ) ;
F_20 ( V_14 , V_32 , V_103 ) ;
}
