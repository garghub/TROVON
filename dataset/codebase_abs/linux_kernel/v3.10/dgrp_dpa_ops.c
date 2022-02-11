static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 0 ;
V_5 = F_2 ( V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 = 0 ;
if ( ! F_3 ( V_8 ) ) {
V_5 = - V_9 ;
goto V_10;
}
if ( V_2 -> V_11 ) {
V_5 = - V_12 ;
goto V_10;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
V_5 = - V_7 ;
goto V_10;
}
V_2 -> V_11 = ( void * ) V_4 ;
if ( V_4 -> V_13 ) {
V_5 = - V_14 ;
} else {
V_4 -> V_13 = F_5 ( V_15 , V_16 ) ;
if ( ! V_4 -> V_13 ) {
V_5 = - V_17 ;
} else {
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = V_21 ;
}
}
V_10:
if ( V_5 )
F_6 ( V_6 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_22 ;
unsigned long V_23 ;
V_4 = (struct V_3 * ) ( V_2 -> V_11 ) ;
if ( ! V_4 )
goto V_10;
F_8 ( & V_4 -> V_24 , V_23 ) ;
V_22 = V_4 -> V_13 ;
V_4 -> V_13 = NULL ;
V_4 -> V_18 = V_4 -> V_19 ;
if ( V_4 -> V_25 & V_26 ) {
V_4 -> V_25 &= ~ V_26 ;
F_9 ( & V_4 -> V_27 ) ;
}
F_10 ( & V_4 -> V_24 , V_23 ) ;
F_11 ( V_22 ) ;
V_10:
F_6 ( V_6 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static T_2 F_12 ( struct V_2 * V_2 , char T_3 * V_22 , T_4 V_28 ,
T_5 * V_29 )
{
struct V_3 * V_4 ;
int V_30 ;
int V_31 ;
int V_32 = 0 ;
int V_33 = 0 ;
T_2 V_5 ;
unsigned long V_23 ;
V_4 = (struct V_3 * ) ( V_2 -> V_11 ) ;
if ( ! V_4 )
return - V_7 ;
F_8 ( & V_4 -> V_24 , V_23 ) ;
for (; ; ) {
V_30 = ( V_4 -> V_19 - V_4 -> V_18 ) & V_34 ;
if ( V_30 != 0 )
break;
V_4 -> V_25 |= V_35 ;
F_10 ( & V_4 -> V_24 , V_23 ) ;
V_5 = F_13 ( V_4 -> V_27 ,
( ( V_4 -> V_25 & V_35 ) == 0 ) ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_4 -> V_24 , V_23 ) ;
}
if ( V_30 > V_28 )
V_30 = V_28 ;
V_33 = V_30 ;
V_31 = V_15 - V_4 -> V_18 ;
if ( V_31 <= V_30 ) {
F_10 ( & V_4 -> V_24 , V_23 ) ;
V_5 = F_14 ( ( void T_3 * ) V_22 ,
V_4 -> V_13 + V_4 -> V_18 , V_31 ) ;
F_8 ( & V_4 -> V_24 , V_23 ) ;
if ( V_5 ) {
V_5 = - V_36 ;
goto V_10;
}
V_4 -> V_18 = 0 ;
V_30 -= V_31 ;
V_32 = V_31 ;
}
F_10 ( & V_4 -> V_24 , V_23 ) ;
V_5 = F_14 ( ( void T_3 * ) V_22 + V_32 ,
V_4 -> V_13 + V_4 -> V_18 , V_30 ) ;
F_8 ( & V_4 -> V_24 , V_23 ) ;
if ( V_5 ) {
V_5 = - V_36 ;
goto V_10;
}
V_4 -> V_18 += V_30 ;
* V_29 += V_33 ;
V_5 = V_33 ;
V_30 = ( V_4 -> V_19 - V_4 -> V_18 ) & V_34 ;
if ( V_4 -> V_25 & V_26 &&
( V_15 - V_30 ) > V_37 ) {
V_4 -> V_25 &= ~ V_26 ;
F_9 ( & V_4 -> V_27 ) ;
}
V_10:
F_10 ( & V_4 -> V_24 , V_23 ) ;
return V_5 ;
}
static unsigned int F_15 ( struct V_2 * V_2 ,
struct V_38 * V_39 )
{
unsigned int V_40 = 0 ;
struct V_3 * V_4 = V_2 -> V_11 ;
if ( V_4 -> V_18 != V_4 -> V_19 )
V_40 |= V_41 | V_42 ;
V_40 |= V_43 | V_44 ;
return V_40 ;
}
static long F_16 ( struct V_2 * V_2 , unsigned int V_45 ,
unsigned long V_46 )
{
struct V_3 * V_4 ;
struct V_47 V_48 ;
struct V_49 V_50 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
struct V_55 V_56 ;
unsigned int V_57 ;
void T_3 * V_58 = ( void T_3 * ) V_46 ;
V_4 = V_2 -> V_11 ;
switch ( V_45 ) {
case V_59 :
if ( F_17 ( & V_48 , V_58 , sizeof( struct V_47 ) ) )
return - V_36 ;
V_57 = V_48 . V_60 ;
if ( V_57 > V_4 -> V_61 )
return - V_12 ;
V_52 = V_4 -> V_62 + V_57 ;
V_48 . V_63 = ( V_52 -> V_64 > 0 ) ? 1 : 0 ;
V_48 . V_65 = V_52 -> V_65 ;
V_48 . V_66 = V_52 -> V_66 ;
V_48 . V_67 = V_52 -> V_67 ;
V_48 . V_68 = V_52 -> V_69 ;
V_48 . V_70 = V_52 -> V_70 ;
V_48 . V_71 = V_52 -> V_71 ;
V_48 . V_72 = V_52 -> V_72 ;
V_48 . V_73 = V_52 -> V_73 ;
V_48 . V_74 = V_52 -> V_75 ;
if ( F_14 ( V_58 , & V_48 , sizeof( struct V_47 ) ) )
return - V_36 ;
break;
case V_76 :
V_50 . V_77 = ( V_4 -> V_77 & V_78 ) ? 1 : 0 ;
V_50 . V_61 = V_4 -> V_61 ;
V_50 . V_79 = V_4 -> V_79 ;
V_50 . V_80 = V_4 -> V_80 ;
memset ( & V_50 . V_81 , 0 , V_82 ) ;
strncpy ( V_50 . V_81 , V_4 -> V_81 , V_82 ) ;
if ( F_14 ( V_58 , & V_50 , sizeof( struct V_49 ) ) )
return - V_36 ;
break;
case V_83 :
if ( F_17 ( & V_54 , V_58 , sizeof( struct V_53 ) ) )
return - V_36 ;
V_4 -> V_84 = V_54 . V_85 ;
V_4 -> V_86 = V_54 . V_57 ;
break;
case V_87 :
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
if ( V_4 -> V_88 > 0 ) {
V_56 . V_89 = V_4 -> V_88 ;
memcpy ( & V_56 . V_90 , & V_4 -> V_91 , V_4 -> V_88 ) ;
} else {
V_56 . V_89 = 0 ;
}
if ( F_14 ( V_58 , & V_56 , sizeof( struct V_55 ) ) )
return - V_36 ;
break;
}
return 0 ;
}
static void F_18 ( struct V_3 * V_4 , T_1 * V_22 , int V_92 )
{
int V_30 ;
int V_31 ;
unsigned long V_23 ;
F_8 ( & V_4 -> V_24 , V_23 ) ;
while ( V_92 > 0 && V_4 -> V_13 != NULL ) {
V_30 = ( V_4 -> V_18 - V_4 -> V_19 - 1 ) & V_34 ;
if ( V_30 < ( V_15 - V_37 ) )
V_4 -> V_25 |= V_26 ;
if ( V_30 == 0 ) {
F_10 ( & V_4 -> V_24 , V_23 ) ;
return;
}
if ( V_30 > V_92 )
V_30 = V_92 ;
V_31 = V_15 - V_4 -> V_19 ;
if ( V_31 <= V_30 ) {
memcpy ( V_4 -> V_13 + V_4 -> V_19 , V_22 , V_31 ) ;
V_30 -= V_31 ;
V_4 -> V_19 = 0 ;
V_22 += V_31 ;
V_92 -= V_31 ;
}
memcpy ( V_4 -> V_13 + V_4 -> V_19 , V_22 , V_30 ) ;
V_4 -> V_19 += V_30 ;
V_22 += V_30 ;
V_92 -= V_30 ;
if ( V_4 -> V_19 >= V_15 )
F_19 ( L_1 ,
V_93 , V_4 -> V_19 ) ;
if ( V_4 -> V_25 & V_35 ) {
V_4 -> V_25 &= ~ V_35 ;
F_9 ( & V_4 -> V_27 ) ;
}
}
F_10 ( & V_4 -> V_24 , V_23 ) ;
}
void F_20 ( struct V_3 * V_4 , int type , T_1 * V_22 , int V_94 )
{
T_1 V_95 [ 5 ] ;
V_95 [ 0 ] = type ;
F_21 ( V_94 , V_95 + 1 ) ;
F_18 ( V_4 , V_95 , sizeof( V_95 ) ) ;
F_18 ( V_4 , V_22 , V_94 ) ;
}
