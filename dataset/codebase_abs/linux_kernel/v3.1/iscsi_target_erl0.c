void F_1 (
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 ) {
V_2 -> V_6 = V_2 -> V_7 ;
V_2 -> V_8 = ( V_2 -> V_7 +
( V_2 -> V_9 >
V_4 -> V_10 -> V_11 -> V_12 ) ?
V_4 -> V_10 -> V_11 -> V_12 : V_2 -> V_9 ) ;
return;
}
if ( ! V_4 -> V_10 -> V_11 -> V_13 )
return;
if ( ! V_2 -> V_6 && ! V_2 -> V_8 ) {
V_2 -> V_6 = V_2 -> V_7 ;
V_2 -> V_8 = ( V_2 -> V_9 >
V_4 -> V_10 -> V_11 -> V_14 ) ?
( V_2 -> V_7 +
V_4 -> V_10 -> V_11 -> V_14 ) : V_2 -> V_9 ;
} else {
V_2 -> V_6 = V_2 -> V_8 ;
V_2 -> V_8 = ( ( V_2 -> V_8 +
V_4 -> V_10 -> V_11 -> V_14 ) >=
V_2 -> V_9 ) ? V_2 -> V_9 :
( V_2 -> V_8 +
V_4 -> V_10 -> V_11 -> V_14 ) ;
}
}
static int F_2 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( V_4 -> V_10 -> V_11 -> V_13 ) {
if ( ( V_2 -> V_20 & V_21 ) &&
( V_2 -> V_7 != V_17 -> V_22 ) )
goto V_23;
V_2 -> V_20 &= ~ V_21 ;
} else {
struct V_24 * V_25 ;
V_25 = F_4 ( V_2 , V_17 -> V_22 , V_18 ) ;
if ( ! V_25 )
return V_26 ;
V_2 -> V_27 = V_25 ;
if ( V_4 -> V_10 -> V_11 -> V_28 ) {
if ( ( V_25 -> V_29 ==
V_30 ) &&
( ( V_25 -> V_22 != V_17 -> V_22 ) ||
( V_25 -> V_31 != V_17 -> V_32 ) ) )
goto V_23;
} else {
if ( ( V_25 -> V_29 ==
V_30 ) &&
( V_25 -> V_31 != V_17 -> V_32 ) )
goto V_23;
}
if ( V_25 -> V_29 == V_33 )
goto V_23;
if ( V_25 -> V_29 != V_33 )
V_25 -> V_29 = 0 ;
}
return V_34 ;
V_23:
F_5 ( L_1
L_2 , V_17 -> V_22 , V_18 , V_17 -> V_32 ) ;
return F_6 ( V_4 , V_18 , 1 ) ;
}
static int F_7 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
T_1 V_35 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( ( V_17 -> V_22 < V_2 -> V_6 ) ||
( ( V_17 -> V_22 + V_18 ) > V_2 -> V_8 ) ) {
F_5 ( L_3
L_4
L_5 , V_2 -> V_36 ,
V_17 -> V_22 , V_18 , V_2 -> V_6 ,
V_2 -> V_8 ) ;
return V_26 ;
}
V_35 = ( V_2 -> V_35 + V_18 ) ;
if ( V_35 > V_4 -> V_10 -> V_11 -> V_12 ) {
F_5 ( L_6
L_7 ,
V_35 , V_4 -> V_10 -> V_11 -> V_12 ) ;
F_8 ( & V_2 -> V_37 ,
V_38 , 0 ) ;
return V_26 ;
}
if ( V_17 -> V_39 & V_40 ) {
if ( ! V_4 -> V_10 -> V_11 -> V_28 )
goto V_41;
if ( ( V_35 != V_2 -> V_9 ) &&
( V_35 != V_4 -> V_10 -> V_11 -> V_12 ) ) {
F_5 ( L_8
L_9
L_10 , V_35 ,
V_4 -> V_10 -> V_11 -> V_12 ,
V_2 -> V_9 ) ;
F_8 ( & V_2 -> V_37 ,
V_38 , 0 ) ;
return V_26 ;
}
} else {
if ( V_35 == V_4 -> V_10 -> V_11 -> V_12 ) {
F_5 ( L_11
L_12
L_13 , V_2 -> V_36 ,
V_4 -> V_10 -> V_11 -> V_12 ) ;
return V_26 ;
}
if ( V_35 == V_2 -> V_9 ) {
F_5 ( L_11
L_14
L_13 , V_2 -> V_36 , V_2 -> V_9 ) ;
return V_26 ;
}
}
V_41:
return V_34 ;
}
static int F_9 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
T_1 V_42 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = NULL ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( V_4 -> V_10 -> V_11 -> V_13 ) {
if ( ( V_17 -> V_22 < V_2 -> V_6 ) ||
( ( V_17 -> V_22 + V_18 ) > V_2 -> V_8 ) ) {
F_5 ( L_3
L_15
L_5 , V_2 -> V_36 ,
V_17 -> V_22 , V_18 , V_2 -> V_6 ,
V_2 -> V_8 ) ;
if ( F_6 ( V_4 , V_18 , 1 ) < 0 )
return V_26 ;
return V_43 ;
}
V_42 = ( V_2 -> V_42 + V_18 ) ;
} else {
V_25 = F_4 ( V_2 , V_17 -> V_22 , V_18 ) ;
if ( ! V_25 )
return V_26 ;
V_2 -> V_27 = V_25 ;
if ( V_25 -> V_29 == V_33 ) {
if ( F_6 ( V_4 , V_18 , 1 ) < 0 )
return V_26 ;
return V_43 ;
}
V_42 = ( V_25 -> V_42 + V_18 ) ;
}
if ( V_42 > V_4 -> V_10 -> V_11 -> V_14 ) {
F_5 ( L_16
L_17
L_13 , V_2 -> V_36 ,
( V_42 - V_18 ) ,
V_18 , V_4 -> V_10 -> V_11 -> V_14 ) ;
return V_26 ;
}
if ( V_17 -> V_39 & V_40 ) {
if ( ! V_4 -> V_10 -> V_11 -> V_28 )
goto V_41;
if ( V_4 -> V_10 -> V_11 -> V_13 ) {
if ( ( V_42 <
V_4 -> V_10 -> V_11 -> V_14 ) &&
( ( V_2 -> V_7 + V_18 ) <
V_2 -> V_9 ) ) {
F_5 ( L_18
L_19
L_13 , V_2 -> V_36 ) ;
return V_26 ;
}
} else {
if ( V_42 < V_25 -> V_44 ) {
F_5 ( L_18
L_19
L_13 , V_2 -> V_36 ) ;
return V_26 ;
}
}
} else {
if ( V_4 -> V_10 -> V_11 -> V_13 ) {
if ( V_42 ==
V_4 -> V_10 -> V_11 -> V_14 ) {
F_5 ( L_11
L_20
L_21 , V_2 -> V_36 ,
V_4 -> V_10 -> V_11 -> V_14 ) ;
return V_26 ;
}
if ( ( V_2 -> V_7 + V_18 ) ==
V_2 -> V_9 ) {
F_5 ( L_11
L_22
L_23 ,
V_2 -> V_36 ) ;
return V_26 ;
}
} else {
if ( V_42 == V_25 -> V_44 ) {
F_5 ( L_11
L_22
L_23 ,
V_2 -> V_36 ) ;
return V_26 ;
}
}
}
V_41:
return V_34 ;
}
static int F_10 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
int V_23 = 0 , V_45 = 0 ;
T_1 V_31 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( V_4 -> V_10 -> V_11 -> V_13 )
V_31 = V_2 -> V_31 ;
else {
struct V_24 * V_25 = V_2 -> V_27 ;
V_31 = V_25 -> V_31 ;
}
if ( V_17 -> V_32 > V_31 ) {
F_5 ( L_24
L_25 , V_2 -> V_36 ,
V_17 -> V_32 , V_31 ) ;
V_45 = 1 ;
goto V_46;
} else if ( V_17 -> V_32 < V_31 ) {
F_5 ( L_24
L_26 ,
V_2 -> V_36 , V_17 -> V_32 , V_31 ) ;
V_23 = 1 ;
goto V_23;
}
return V_34 ;
V_46:
if ( ! V_4 -> V_10 -> V_11 -> V_47 ) {
F_5 ( L_27
L_28 ) ;
return V_26 ;
}
V_23:
if ( F_6 ( V_4 , V_18 , 1 ) < 0 )
return V_26 ;
return ( V_45 || V_23 ) ? V_43 :
V_34 ;
}
static int F_11 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
int V_23 = 0 , V_45 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( V_4 -> V_10 -> V_11 -> V_13 ) {
if ( V_17 -> V_22 != V_2 -> V_7 ) {
F_5 ( L_29
L_30 , V_2 -> V_36 ,
V_17 -> V_22 , V_2 -> V_7 ) ;
V_45 = 1 ;
goto V_46;
}
} else {
struct V_24 * V_25 = V_2 -> V_27 ;
if ( V_17 -> V_22 > V_25 -> V_22 ) {
F_5 ( L_29
L_31 , V_2 -> V_36 ,
V_17 -> V_22 , V_25 -> V_22 ) ;
V_45 = 1 ;
goto V_46;
} else if ( V_17 -> V_22 < V_25 -> V_22 ) {
F_5 ( L_29
L_32 ,
V_2 -> V_36 , V_17 -> V_22 , V_25 -> V_22 ) ;
V_23 = 1 ;
goto V_23;
}
}
return V_34 ;
V_46:
if ( ! V_4 -> V_10 -> V_11 -> V_47 ) {
F_5 ( L_27
L_28 ) ;
return V_26 ;
}
V_23:
if ( F_6 ( V_4 , V_18 , 1 ) < 0 )
return V_26 ;
return ( V_45 ) ? F_12 ( V_2 ,
V_17 -> V_22 , V_18 ) :
( V_23 ) ? V_43 : V_34 ;
}
static int F_13 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
struct V_48 * V_49 ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
V_49 = F_14 ( V_2 , V_17 -> V_22 , V_18 ) ;
if ( ! V_49 )
return V_26 ;
V_2 -> V_50 = V_49 ;
switch ( V_49 -> V_29 ) {
case V_51 :
case V_52 :
case V_53 :
break;
case V_54 :
F_5 ( L_33
L_34 , V_2 -> V_36 ,
V_17 -> V_22 , V_18 ) ;
return F_6 ( V_2 -> V_4 , V_18 , 1 ) ;
default:
return V_26 ;
}
return V_34 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_55 )
{
struct V_56 * V_57 ;
if ( V_2 -> V_5 )
return 0 ;
V_57 = F_16 ( V_2 , V_22 , V_55 ) ;
if ( ! V_57 )
return - 1 ;
F_17 ( & V_2 -> V_58 ) ;
V_57 -> V_59 = 1 ;
V_2 -> V_60 -- ;
F_18 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_19 (
struct V_1 * V_2 ,
T_1 V_31 ,
int V_61 )
{
int V_62 = 0 ;
struct V_48 * V_49 = V_2 -> V_50 ;
V_49 -> V_31 = V_31 ;
switch ( V_49 -> V_29 ) {
case V_51 :
V_49 -> V_29 = V_54 ;
break;
case V_52 :
V_49 -> V_29 = V_54 ;
break;
case V_53 :
V_49 -> V_29 = V_54 ;
break;
default:
return V_26 ;
}
if ( V_61 ) {
V_62 = F_20 ( V_2 , V_49 ) ;
if ( V_62 == V_26 )
return V_62 ;
}
return V_34 ;
}
static int F_21 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
int V_62 , V_63 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = NULL ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( V_2 -> V_5 ) {
if ( ( V_2 -> V_35 + V_18 ) ==
V_4 -> V_10 -> V_11 -> V_12 ) {
if ( F_15 ( V_2 , V_17 -> V_22 ,
V_18 ) < 0 )
return V_26 ;
V_63 = 1 ;
}
if ( ! V_4 -> V_10 -> V_11 -> V_28 ) {
V_62 = F_19 ( V_2 ,
V_17 -> V_32 , ( V_17 -> V_39 & V_40 ) ) ;
if ( V_62 == V_26 )
return V_62 ;
}
V_2 -> V_35 += V_18 ;
if ( V_4 -> V_10 -> V_11 -> V_13 )
V_2 -> V_31 ++ ;
else {
V_25 = V_2 -> V_27 ;
V_25 -> V_31 ++ ;
V_25 -> V_22 += V_18 ;
}
if ( V_63 ) {
if ( V_25 )
V_25 -> V_29 = V_33 ;
V_2 -> V_35 = 0 ;
V_2 -> V_5 = 0 ;
}
} else {
if ( V_4 -> V_10 -> V_11 -> V_13 ) {
if ( ( V_2 -> V_42 + V_18 ) ==
V_4 -> V_10 -> V_11 -> V_14 ) {
if ( F_15 ( V_2 , V_17 -> V_22 ,
V_18 ) < 0 )
return V_26 ;
V_63 = 1 ;
}
if ( ! V_4 -> V_10 -> V_11 -> V_28 ) {
V_62 = F_19 (
V_2 , V_17 -> V_32 ,
( V_17 -> V_39 & V_40 ) ) ;
if ( V_62 == V_26 )
return V_62 ;
}
V_2 -> V_42 += V_18 ;
V_2 -> V_31 ++ ;
if ( V_63 )
V_2 -> V_42 = 0 ;
} else {
V_25 = V_2 -> V_27 ;
if ( ( V_25 -> V_42 + V_18 ) ==
V_25 -> V_44 ) {
if ( F_15 ( V_2 , V_17 -> V_22 ,
V_18 ) < 0 )
return V_26 ;
V_63 = 1 ;
}
if ( ! V_4 -> V_10 -> V_11 -> V_28 ) {
V_62 = F_19 (
V_2 , V_17 -> V_32 ,
( V_17 -> V_39 & V_40 ) ) ;
if ( V_62 == V_26 )
return V_62 ;
}
V_25 -> V_31 ++ ;
V_25 -> V_22 += V_18 ;
V_25 -> V_42 += V_18 ;
if ( V_63 ) {
V_25 -> V_42 = 0 ;
V_25 -> V_29 = V_33 ;
}
}
}
if ( V_63 && V_4 -> V_10 -> V_11 -> V_13 )
V_2 -> V_31 = 0 ;
V_2 -> V_7 += V_18 ;
return ( V_2 -> V_7 == V_2 -> V_9 ) ?
V_64 : ( V_63 ) ?
V_65 : V_34 ;
}
static int F_22 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_48 * V_49 ;
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_1 V_18 = F_3 ( V_17 -> V_19 ) ;
if ( V_4 -> V_10 -> V_11 -> V_28 )
goto V_46;
V_49 = V_2 -> V_50 ;
switch ( V_49 -> V_29 ) {
case V_51 :
V_49 -> V_29 = V_52 ;
break;
case V_52 :
break;
case V_53 :
V_49 -> V_29 = V_52 ;
break;
default:
return V_26 ;
}
V_46:
return F_12 ( V_2 , V_17 -> V_22 , V_18 ) ;
}
extern int F_23 (
struct V_1 * V_2 ,
unsigned char * V_15 )
{
int V_62 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_62 = F_2 ( V_2 , V_15 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_26 ) )
return V_62 ;
V_62 = F_10 ( V_2 , V_15 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_26 ) )
return V_62 ;
if ( V_2 -> V_5 ) {
V_62 = F_7 ( V_2 , V_15 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_26 ) )
return V_62 ;
} else {
V_62 = F_9 ( V_2 , V_15 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_26 ) )
return V_62 ;
}
return ( V_4 -> V_10 -> V_11 -> V_28 ) ?
F_11 ( V_2 , V_15 ) :
F_13 ( V_2 , V_15 ) ;
}
int F_24 (
struct V_1 * V_2 ,
unsigned char * V_15 ,
T_2 V_66 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_67 = 0 ;
if ( ! V_66 )
return F_21 ( V_2 , V_15 ) ;
else {
if ( ! V_4 -> V_10 -> V_11 -> V_47 ) {
F_5 ( L_35
L_36 ) ;
F_25 ( V_68 ,
1 , 0 , V_15 , V_2 ) ;
return V_26 ;
}
F_25 ( V_68 ,
0 , 0 , V_15 , V_2 ) ;
return F_22 ( V_2 , V_15 ) ;
}
}
static void F_26 ( unsigned long V_69 )
{
struct V_70 * V_10 = (struct V_70 * ) V_69 ;
struct V_71 * V_72 = F_27 ( V_10 ) ;
struct V_73 * V_74 = & V_72 -> V_75 ;
F_17 ( & V_74 -> V_76 ) ;
if ( V_10 -> V_77 & V_78 ) {
F_18 ( & V_74 -> V_76 ) ;
return;
}
if ( F_28 ( & V_10 -> V_79 ) ) {
F_5 ( L_37
L_38 ) ;
F_18 ( & V_74 -> V_76 ) ;
return;
}
V_10 -> V_77 |= V_80 ;
F_5 ( L_39
L_40 , V_10 -> V_81 ) ;
{
struct V_82 * V_83 = V_72 -> V_84 ;
if ( V_83 ) {
F_29 ( & V_83 -> V_85 . V_86 ) ;
strcpy ( V_83 -> V_85 . V_87 ,
( void * ) V_10 -> V_11 -> V_88 ) ;
V_83 -> V_85 . V_89 =
V_90 ;
V_83 -> V_85 . V_91 ++ ;
V_10 -> V_92 ++ ;
F_30 ( & V_83 -> V_85 . V_86 ) ;
}
}
F_18 ( & V_74 -> V_76 ) ;
F_31 ( V_10 ) ;
}
extern void F_32 ( struct V_70 * V_10 )
{
int V_93 ;
F_29 ( & F_27 ( V_10 ) -> V_94 ) ;
V_93 = ( F_27 ( V_10 ) -> V_95 == V_96 ) ;
F_30 ( & F_27 ( V_10 ) -> V_94 ) ;
if ( ! V_93 )
return;
if ( V_10 -> V_77 & V_97 )
return;
F_33 ( L_41
L_42 , V_10 -> V_11 -> V_98 , V_10 -> V_81 ) ;
F_34 ( & V_10 -> V_99 ) ;
V_10 -> V_99 . V_100 =
( F_35 () + V_10 -> V_11 -> V_98 * V_101 ) ;
V_10 -> V_99 . V_69 = ( unsigned long ) V_10 ;
V_10 -> V_99 . V_102 = F_26 ;
V_10 -> V_77 &= ~ V_78 ;
V_10 -> V_77 |= V_97 ;
F_36 ( & V_10 -> V_99 ) ;
}
extern int F_37 ( struct V_70 * V_10 )
{
struct V_71 * V_72 = F_27 ( V_10 ) ;
struct V_73 * V_74 = & V_72 -> V_75 ;
if ( V_10 -> V_77 & V_80 )
return - 1 ;
if ( ! ( V_10 -> V_77 & V_97 ) )
return 0 ;
V_10 -> V_77 |= V_78 ;
F_18 ( & V_74 -> V_76 ) ;
F_38 ( & V_10 -> V_99 ) ;
F_17 ( & V_74 -> V_76 ) ;
V_10 -> V_77 &= ~ V_97 ;
F_33 ( L_43 ,
V_10 -> V_81 ) ;
return 0 ;
}
void F_39 ( struct V_3 * V_4 )
{
F_17 ( & V_4 -> V_103 ) ;
if ( F_28 ( & V_4 -> V_104 ) ) {
F_18 ( & V_4 -> V_103 ) ;
goto V_105;
}
if ( F_28 ( & V_4 -> V_106 ) ) {
F_18 ( & V_4 -> V_103 ) ;
goto V_105;
}
F_18 ( & V_4 -> V_103 ) ;
F_40 ( V_4 ) ;
V_105:
F_41 ( & V_4 -> V_107 ) ;
F_42 ( & V_4 -> V_108 ) ;
}
void F_43 ( struct V_3 * V_4 , int V_105 )
{
F_17 ( & V_4 -> V_103 ) ;
if ( F_28 ( & V_4 -> V_104 ) ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
if ( F_28 ( & V_4 -> V_106 ) ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
if ( F_28 ( & V_4 -> V_109 ) ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
if ( F_40 ( V_4 ) < 0 ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
F_44 ( & V_4 -> V_109 , 1 ) ;
if ( ! V_105 ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
F_44 ( & V_4 -> V_110 , 1 ) ;
F_18 ( & V_4 -> V_103 ) ;
F_41 ( & V_4 -> V_111 ) ;
F_42 ( & V_4 -> V_108 ) ;
}
void F_45 ( struct V_70 * V_10 )
{
F_33 ( L_44
L_45 , V_10 -> V_81 ) ;
F_44 ( & V_10 -> V_112 , 1 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_70 * V_10 = V_4 -> V_10 ;
if ( ( V_10 -> V_11 -> V_47 == 2 ) &&
! F_28 ( & V_10 -> V_79 ) &&
! F_28 ( & V_10 -> V_112 ) )
F_47 ( V_4 ) ;
else {
F_33 ( L_46
L_47 , V_4 -> V_113 ,
V_10 -> V_11 -> V_88 ) ;
F_48 ( V_4 ) ;
}
}
extern void F_49 ( struct V_3 * V_4 )
{
F_17 ( & V_4 -> V_103 ) ;
if ( F_28 ( & V_4 -> V_104 ) ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
F_44 ( & V_4 -> V_104 , 1 ) ;
if ( V_4 -> V_114 == V_115 ) {
F_18 ( & V_4 -> V_103 ) ;
F_48 ( V_4 ) ;
return;
}
if ( V_4 -> V_114 == V_116 ) {
F_18 ( & V_4 -> V_103 ) ;
return;
}
F_33 ( L_48 ) ;
V_4 -> V_114 = V_116 ;
F_18 ( & V_4 -> V_103 ) ;
F_46 ( V_4 ) ;
}
int F_50 ( struct V_3 * V_4 )
{
if ( V_4 -> V_117 > ( V_4 -> V_118 -> V_119 * 4 ) ) {
F_5 ( L_49
L_50 , V_4 -> V_117 ,
V_4 -> V_118 -> V_119 * 4 ) ;
return - 1 ;
}
F_33 ( L_51
L_52 , V_4 -> V_117 ) ;
if ( F_6 ( V_4 , V_4 -> V_117 , 0 ) < 0 )
return - 1 ;
if ( V_4 -> V_120 > ( V_121 + ( V_122 * 2 ) +
V_4 -> V_118 -> V_123 ) ) {
F_5 ( L_53 ,
V_4 -> V_120 ) ;
return - 1 ;
}
F_33 ( L_54
L_55 , V_4 -> V_120 ) ;
if ( F_6 ( V_4 , V_4 -> V_120 , 0 ) < 0 )
return - 1 ;
return 0 ;
}
