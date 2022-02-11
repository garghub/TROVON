void F_1 (
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 ) {
V_2 -> V_6 = V_2 -> V_7 ;
V_2 -> V_8 = ( V_2 -> V_7 +
( ( V_2 -> V_9 . V_10 >
V_4 -> V_11 -> V_12 -> V_13 ) ?
V_4 -> V_11 -> V_12 -> V_13 : V_2 -> V_9 . V_10 ) ) ;
return;
}
if ( ! V_4 -> V_11 -> V_12 -> V_14 )
return;
if ( ! V_2 -> V_6 && ! V_2 -> V_8 ) {
V_2 -> V_6 = V_2 -> V_7 ;
V_2 -> V_8 = ( V_2 -> V_9 . V_10 >
V_4 -> V_11 -> V_12 -> V_15 ) ?
( V_2 -> V_7 +
V_4 -> V_11 -> V_12 -> V_15 ) : V_2 -> V_9 . V_10 ;
} else {
V_2 -> V_6 = V_2 -> V_8 ;
V_2 -> V_8 = ( ( V_2 -> V_8 +
V_4 -> V_11 -> V_12 -> V_15 ) >=
V_2 -> V_9 . V_10 ) ? V_2 -> V_9 . V_10 :
( V_2 -> V_8 +
V_4 -> V_11 -> V_12 -> V_15 ) ;
}
}
static int F_2 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( V_4 -> V_11 -> V_12 -> V_14 ) {
if ( ( V_2 -> V_21 & V_22 ) &&
V_2 -> V_7 != F_4 ( V_18 -> V_23 ) )
goto V_24;
V_2 -> V_21 &= ~ V_22 ;
} else {
struct V_25 * V_26 ;
V_26 = F_5 ( V_2 , F_4 ( V_18 -> V_23 ) ,
V_19 ) ;
if ( ! V_26 )
return V_27 ;
V_2 -> V_28 = V_26 ;
if ( V_4 -> V_11 -> V_12 -> V_29 ) {
if ( V_26 -> V_30 ==
V_31 &&
( V_26 -> V_23 != F_4 ( V_18 -> V_23 ) ||
V_26 -> V_32 != F_4 ( V_18 -> V_33 ) ) )
goto V_24;
} else {
if ( V_26 -> V_30 ==
V_31 &&
V_26 -> V_32 != F_4 ( V_18 -> V_33 ) )
goto V_24;
}
if ( V_26 -> V_30 == V_34 )
goto V_24;
if ( V_26 -> V_30 != V_34 )
V_26 -> V_30 = 0 ;
}
return V_35 ;
V_24:
F_6 ( L_1
L_2 , V_18 -> V_23 , V_19 , V_18 -> V_33 ) ;
return F_7 ( V_4 , V_19 , 1 ) ;
}
static int F_8 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
T_1 V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( ( F_4 ( V_18 -> V_23 ) < V_2 -> V_6 ) ||
( ( F_4 ( V_18 -> V_23 ) + V_19 ) > V_2 -> V_8 ) ) {
F_6 ( L_3
L_4
L_5 , V_2 -> V_37 ,
F_4 ( V_18 -> V_23 ) , V_19 , V_2 -> V_6 ,
V_2 -> V_8 ) ;
return V_27 ;
}
V_36 = ( V_2 -> V_36 + V_19 ) ;
if ( V_36 > V_4 -> V_11 -> V_12 -> V_13 ) {
F_6 ( L_6
L_7 ,
V_36 , V_4 -> V_11 -> V_12 -> V_13 ) ;
F_9 ( & V_2 -> V_9 ,
V_38 , 0 ) ;
return V_27 ;
}
if ( V_18 -> V_39 & V_40 ) {
if ( ! V_4 -> V_11 -> V_12 -> V_29 )
goto V_41;
if ( ( V_36 != V_2 -> V_9 . V_10 ) &&
( V_36 != V_4 -> V_11 -> V_12 -> V_13 ) ) {
F_6 ( L_8
L_9
L_10 , V_36 ,
V_4 -> V_11 -> V_12 -> V_13 ,
V_2 -> V_9 . V_10 ) ;
F_9 ( & V_2 -> V_9 ,
V_38 , 0 ) ;
return V_27 ;
}
} else {
if ( V_36 == V_4 -> V_11 -> V_12 -> V_13 ) {
F_6 ( L_11
L_12
L_13 , V_2 -> V_37 ,
V_4 -> V_11 -> V_12 -> V_13 ) ;
return V_27 ;
}
if ( V_36 == V_2 -> V_9 . V_10 ) {
F_6 ( L_11
L_14
L_13 , V_2 -> V_37 , V_2 -> V_9 . V_10 ) ;
return V_27 ;
}
}
V_41:
return V_35 ;
}
static int F_10 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
T_1 V_42 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_26 = NULL ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( V_4 -> V_11 -> V_12 -> V_14 ) {
if ( ( F_4 ( V_18 -> V_23 ) < V_2 -> V_6 ) ||
( ( F_4 ( V_18 -> V_23 ) + V_19 ) > V_2 -> V_8 ) ) {
F_6 ( L_3
L_15
L_5 , V_2 -> V_37 ,
F_4 ( V_18 -> V_23 ) , V_19 , V_2 -> V_6 ,
V_2 -> V_8 ) ;
if ( F_7 ( V_4 , V_19 , 1 ) < 0 )
return V_27 ;
return V_43 ;
}
V_42 = ( V_2 -> V_42 + V_19 ) ;
} else {
V_26 = F_5 ( V_2 , F_4 ( V_18 -> V_23 ) ,
V_19 ) ;
if ( ! V_26 )
return V_27 ;
V_2 -> V_28 = V_26 ;
if ( V_26 -> V_30 == V_34 ) {
if ( F_7 ( V_4 , V_19 , 1 ) < 0 )
return V_27 ;
return V_43 ;
}
V_42 = ( V_26 -> V_42 + V_19 ) ;
}
if ( V_42 > V_4 -> V_11 -> V_12 -> V_15 ) {
F_6 ( L_16
L_17
L_13 , V_2 -> V_37 ,
( V_42 - V_19 ) ,
V_19 , V_4 -> V_11 -> V_12 -> V_15 ) ;
return V_27 ;
}
if ( V_18 -> V_39 & V_40 ) {
if ( ! V_4 -> V_11 -> V_12 -> V_29 )
goto V_41;
if ( V_4 -> V_11 -> V_12 -> V_14 ) {
if ( ( V_42 <
V_4 -> V_11 -> V_12 -> V_15 ) &&
( ( V_2 -> V_7 + V_19 ) <
V_2 -> V_9 . V_10 ) ) {
F_6 ( L_18
L_19
L_13 , V_2 -> V_37 ) ;
return V_27 ;
}
} else {
if ( V_42 < V_26 -> V_44 ) {
F_6 ( L_18
L_19
L_13 , V_2 -> V_37 ) ;
return V_27 ;
}
}
} else {
if ( V_4 -> V_11 -> V_12 -> V_14 ) {
if ( V_42 ==
V_4 -> V_11 -> V_12 -> V_15 ) {
F_6 ( L_11
L_20
L_21 , V_2 -> V_37 ,
V_4 -> V_11 -> V_12 -> V_15 ) ;
return V_27 ;
}
if ( ( V_2 -> V_7 + V_19 ) ==
V_2 -> V_9 . V_10 ) {
F_6 ( L_11
L_22
L_23 ,
V_2 -> V_37 ) ;
return V_27 ;
}
} else {
if ( V_42 == V_26 -> V_44 ) {
F_6 ( L_11
L_22
L_23 ,
V_2 -> V_37 ) ;
return V_27 ;
}
}
}
V_41:
return V_35 ;
}
static int F_11 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
int V_24 = 0 , V_45 = 0 ;
T_1 V_32 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( V_4 -> V_11 -> V_12 -> V_14 )
V_32 = V_2 -> V_32 ;
else {
struct V_25 * V_26 = V_2 -> V_28 ;
V_32 = V_26 -> V_32 ;
}
if ( F_4 ( V_18 -> V_33 ) > V_32 ) {
F_6 ( L_24
L_25 , V_2 -> V_37 ,
F_4 ( V_18 -> V_33 ) , V_32 ) ;
V_45 = 1 ;
goto V_46;
} else if ( F_4 ( V_18 -> V_33 ) < V_32 ) {
F_6 ( L_24
L_26 ,
V_2 -> V_37 , F_4 ( V_18 -> V_33 ) , V_32 ) ;
V_24 = 1 ;
goto V_24;
}
return V_35 ;
V_46:
if ( ! V_4 -> V_11 -> V_12 -> V_47 ) {
F_6 ( L_27
L_28 ) ;
return V_27 ;
}
V_24:
if ( F_7 ( V_4 , V_19 , 1 ) < 0 )
return V_27 ;
return ( V_45 || V_24 ) ? V_43 :
V_35 ;
}
static int F_12 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
int V_24 = 0 , V_45 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( V_4 -> V_11 -> V_12 -> V_14 ) {
if ( F_4 ( V_18 -> V_23 ) != V_2 -> V_7 ) {
F_6 ( L_29
L_30 , V_2 -> V_37 ,
F_4 ( V_18 -> V_23 ) , V_2 -> V_7 ) ;
V_45 = 1 ;
goto V_46;
}
} else {
struct V_25 * V_26 = V_2 -> V_28 ;
if ( F_4 ( V_18 -> V_23 ) > V_26 -> V_23 ) {
F_6 ( L_29
L_31 , V_2 -> V_37 ,
F_4 ( V_18 -> V_23 ) , V_26 -> V_23 ) ;
V_45 = 1 ;
goto V_46;
} else if ( F_4 ( V_18 -> V_23 ) < V_26 -> V_23 ) {
F_6 ( L_29
L_32 ,
V_2 -> V_37 , F_4 ( V_18 -> V_23 ) ,
V_26 -> V_23 ) ;
V_24 = 1 ;
goto V_24;
}
}
return V_35 ;
V_46:
if ( ! V_4 -> V_11 -> V_12 -> V_47 ) {
F_6 ( L_27
L_28 ) ;
return V_27 ;
}
V_24:
if ( F_7 ( V_4 , V_19 , 1 ) < 0 )
return V_27 ;
return ( V_45 ) ? F_13 ( V_2 ,
F_4 ( V_18 -> V_23 ) , V_19 ) :
( V_24 ) ? V_43 : V_35 ;
}
static int F_14 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
struct V_48 * V_49 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
V_49 = F_15 ( V_2 , F_4 ( V_18 -> V_23 ) ,
V_19 ) ;
if ( ! V_49 )
return V_27 ;
V_2 -> V_50 = V_49 ;
switch ( V_49 -> V_30 ) {
case V_51 :
case V_52 :
case V_53 :
break;
case V_54 :
F_6 ( L_33
L_34 , V_2 -> V_37 ,
F_4 ( V_18 -> V_23 ) , V_19 ) ;
return F_7 ( V_2 -> V_4 , V_19 , 1 ) ;
default:
return V_27 ;
}
return V_35 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_23 , T_1 V_55 )
{
struct V_56 * V_57 ;
if ( V_2 -> V_5 )
return 0 ;
V_57 = F_17 ( V_2 , V_23 , V_55 ) ;
if ( ! V_57 )
return - 1 ;
F_18 ( & V_2 -> V_58 ) ;
V_57 -> V_59 = 1 ;
V_2 -> V_60 -- ;
F_19 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_20 (
struct V_1 * V_2 ,
T_1 V_32 ,
int V_61 )
{
int V_62 = 0 ;
struct V_48 * V_49 = V_2 -> V_50 ;
V_49 -> V_32 = V_32 ;
switch ( V_49 -> V_30 ) {
case V_51 :
V_49 -> V_30 = V_54 ;
break;
case V_52 :
V_49 -> V_30 = V_54 ;
break;
case V_53 :
V_49 -> V_30 = V_54 ;
break;
default:
return V_27 ;
}
if ( V_61 ) {
V_62 = F_21 ( V_2 , V_49 ) ;
if ( V_62 == V_27 )
return V_62 ;
}
return V_35 ;
}
static int F_22 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
int V_62 , V_63 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_26 = NULL ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( V_2 -> V_5 ) {
if ( ( V_2 -> V_36 + V_19 ) ==
V_4 -> V_11 -> V_12 -> V_13 ) {
if ( F_16 ( V_2 , F_4 ( V_18 -> V_23 ) ,
V_19 ) < 0 )
return V_27 ;
V_63 = 1 ;
}
if ( ! V_4 -> V_11 -> V_12 -> V_29 ) {
V_62 = F_20 ( V_2 ,
F_4 ( V_18 -> V_33 ) ,
( V_18 -> V_39 & V_40 ) ) ;
if ( V_62 == V_27 )
return V_62 ;
}
V_2 -> V_36 += V_19 ;
if ( V_4 -> V_11 -> V_12 -> V_14 )
V_2 -> V_32 ++ ;
else {
V_26 = V_2 -> V_28 ;
V_26 -> V_32 ++ ;
V_26 -> V_23 += V_19 ;
}
if ( V_63 ) {
if ( V_26 )
V_26 -> V_30 = V_34 ;
V_2 -> V_36 = 0 ;
V_2 -> V_5 = 0 ;
}
} else {
if ( V_4 -> V_11 -> V_12 -> V_14 ) {
if ( ( V_2 -> V_42 + V_19 ) ==
V_4 -> V_11 -> V_12 -> V_15 ) {
if ( F_16 ( V_2 ,
F_4 ( V_18 -> V_23 ) ,
V_19 ) < 0 )
return V_27 ;
V_63 = 1 ;
}
if ( ! V_4 -> V_11 -> V_12 -> V_29 ) {
V_62 = F_20 (
V_2 , F_4 ( V_18 -> V_33 ) ,
( V_18 -> V_39 & V_40 ) ) ;
if ( V_62 == V_27 )
return V_62 ;
}
V_2 -> V_42 += V_19 ;
V_2 -> V_32 ++ ;
if ( V_63 )
V_2 -> V_42 = 0 ;
} else {
V_26 = V_2 -> V_28 ;
if ( ( V_26 -> V_42 + V_19 ) ==
V_26 -> V_44 ) {
if ( F_16 ( V_2 ,
F_4 ( V_18 -> V_23 ) ,
V_19 ) < 0 )
return V_27 ;
V_63 = 1 ;
}
if ( ! V_4 -> V_11 -> V_12 -> V_29 ) {
V_62 = F_20 (
V_2 , F_4 ( V_18 -> V_33 ) ,
( V_18 -> V_39 & V_40 ) ) ;
if ( V_62 == V_27 )
return V_62 ;
}
V_26 -> V_32 ++ ;
V_26 -> V_23 += V_19 ;
V_26 -> V_42 += V_19 ;
if ( V_63 ) {
V_26 -> V_42 = 0 ;
V_26 -> V_30 = V_34 ;
}
}
}
if ( V_63 && V_4 -> V_11 -> V_12 -> V_14 )
V_2 -> V_32 = 0 ;
V_2 -> V_7 += V_19 ;
if ( V_2 -> V_7 == V_2 -> V_9 . V_10 )
return V_64 ;
else if ( V_63 )
return V_65 ;
else
return V_35 ;
}
static int F_23 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_48 * V_49 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
T_1 V_19 = F_3 ( V_18 -> V_20 ) ;
if ( V_4 -> V_11 -> V_12 -> V_29 )
goto V_46;
V_49 = V_2 -> V_50 ;
switch ( V_49 -> V_30 ) {
case V_51 :
V_49 -> V_30 = V_52 ;
break;
case V_52 :
break;
case V_53 :
V_49 -> V_30 = V_52 ;
break;
default:
return V_27 ;
}
V_46:
return F_13 ( V_2 , F_4 ( V_18 -> V_23 ) ,
V_19 ) ;
}
int F_24 (
struct V_1 * V_2 ,
unsigned char * V_16 )
{
int V_62 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_62 = F_2 ( V_2 , V_16 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_27 ) )
return V_62 ;
V_62 = F_11 ( V_2 , V_16 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_27 ) )
return V_62 ;
if ( V_2 -> V_5 ) {
V_62 = F_8 ( V_2 , V_16 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_27 ) )
return V_62 ;
} else {
V_62 = F_10 ( V_2 , V_16 ) ;
if ( ( V_62 == V_43 ) ||
( V_62 == V_27 ) )
return V_62 ;
}
return ( V_4 -> V_11 -> V_12 -> V_29 ) ?
F_12 ( V_2 , V_16 ) :
F_14 ( V_2 , V_16 ) ;
}
int F_25 (
struct V_1 * V_2 ,
unsigned char * V_16 ,
T_2 V_66 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_67 = 0 ;
if ( ! V_66 )
return F_22 ( V_2 , V_16 ) ;
else {
if ( ! V_4 -> V_11 -> V_12 -> V_47 ) {
F_6 ( L_35
L_36 ) ;
F_26 ( V_68 ,
1 , 0 , V_16 , V_2 ) ;
return V_27 ;
}
F_26 ( V_68 ,
0 , 0 , V_16 , V_2 ) ;
return F_23 ( V_2 , V_16 ) ;
}
}
static void F_27 ( unsigned long V_69 )
{
struct V_70 * V_11 = (struct V_70 * ) V_69 ;
struct V_71 * V_72 = F_28 ( V_11 ) ;
struct V_73 * V_74 = & V_72 -> V_75 ;
F_18 ( & V_74 -> V_76 ) ;
if ( V_11 -> V_77 & V_78 ) {
F_19 ( & V_74 -> V_76 ) ;
return;
}
if ( F_29 ( & V_11 -> V_79 ) ) {
F_6 ( L_37
L_38 ) ;
F_19 ( & V_74 -> V_76 ) ;
return;
}
V_11 -> V_77 |= V_80 ;
F_6 ( L_39
L_40 , V_11 -> V_81 ) ;
{
struct V_82 * V_83 = V_72 -> V_84 ;
if ( V_83 ) {
F_30 ( & V_83 -> V_85 . V_86 ) ;
strcpy ( V_83 -> V_85 . V_87 ,
( void * ) V_11 -> V_12 -> V_88 ) ;
V_83 -> V_85 . V_89 =
V_90 ;
V_83 -> V_85 . V_91 ++ ;
V_11 -> V_92 ++ ;
F_31 ( & V_83 -> V_85 . V_86 ) ;
}
}
F_19 ( & V_74 -> V_76 ) ;
F_32 ( V_11 -> V_93 ) ;
}
void F_33 ( struct V_70 * V_11 )
{
int V_94 ;
F_30 ( & F_28 ( V_11 ) -> V_95 ) ;
V_94 = ( F_28 ( V_11 ) -> V_96 == V_97 ) ;
F_31 ( & F_28 ( V_11 ) -> V_95 ) ;
if ( ! V_94 )
return;
if ( V_11 -> V_77 & V_98 )
return;
F_34 ( L_41
L_42 , V_11 -> V_12 -> V_99 , V_11 -> V_81 ) ;
F_35 ( & V_11 -> V_100 ) ;
V_11 -> V_100 . V_101 =
( F_36 () + V_11 -> V_12 -> V_99 * V_102 ) ;
V_11 -> V_100 . V_69 = ( unsigned long ) V_11 ;
V_11 -> V_100 . V_103 = F_27 ;
V_11 -> V_77 &= ~ V_78 ;
V_11 -> V_77 |= V_98 ;
F_37 ( & V_11 -> V_100 ) ;
}
int F_38 ( struct V_70 * V_11 )
{
struct V_71 * V_72 = F_28 ( V_11 ) ;
struct V_73 * V_74 = & V_72 -> V_75 ;
if ( V_11 -> V_77 & V_80 )
return - 1 ;
if ( ! ( V_11 -> V_77 & V_98 ) )
return 0 ;
V_11 -> V_77 |= V_78 ;
F_19 ( & V_74 -> V_76 ) ;
F_39 ( & V_11 -> V_100 ) ;
F_18 ( & V_74 -> V_76 ) ;
V_11 -> V_77 &= ~ V_98 ;
F_34 ( L_43 ,
V_11 -> V_81 ) ;
return 0 ;
}
void F_40 ( struct V_3 * V_4 )
{
F_18 ( & V_4 -> V_104 ) ;
if ( F_29 ( & V_4 -> V_105 ) ) {
F_19 ( & V_4 -> V_104 ) ;
goto V_106;
}
if ( F_29 ( & V_4 -> V_107 ) ) {
F_19 ( & V_4 -> V_104 ) ;
goto V_106;
}
F_19 ( & V_4 -> V_104 ) ;
F_41 ( V_4 ) ;
V_106:
F_42 ( & V_4 -> V_108 ) ;
F_43 ( & V_4 -> V_109 ) ;
}
void F_44 ( struct V_3 * V_4 , int V_106 )
{
F_18 ( & V_4 -> V_104 ) ;
if ( F_29 ( & V_4 -> V_105 ) ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
if ( F_29 ( & V_4 -> V_107 ) ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
if ( F_29 ( & V_4 -> V_110 ) ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
if ( F_41 ( V_4 ) < 0 ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
F_45 ( & V_4 -> V_110 , 1 ) ;
if ( ! V_106 ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
F_45 ( & V_4 -> V_111 , 1 ) ;
F_19 ( & V_4 -> V_104 ) ;
F_42 ( & V_4 -> V_112 ) ;
F_43 ( & V_4 -> V_109 ) ;
}
void F_46 ( struct V_70 * V_11 )
{
F_34 ( L_44
L_45 , V_11 -> V_81 ) ;
F_45 ( & V_11 -> V_113 , 1 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_70 * V_11 = V_4 -> V_11 ;
if ( ( V_11 -> V_12 -> V_47 == 2 ) &&
! F_29 ( & V_11 -> V_79 ) &&
! F_29 ( & V_11 -> V_113 ) )
F_48 ( V_4 ) ;
else {
F_34 ( L_46
L_47 , V_4 -> V_114 ,
V_11 -> V_12 -> V_88 ) ;
F_49 ( V_4 ) ;
}
}
void F_50 ( struct V_3 * V_4 )
{
F_18 ( & V_4 -> V_104 ) ;
if ( F_29 ( & V_4 -> V_105 ) ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
F_45 ( & V_4 -> V_105 , 1 ) ;
if ( V_4 -> V_115 == V_116 ) {
F_19 ( & V_4 -> V_104 ) ;
F_49 ( V_4 ) ;
return;
}
if ( V_4 -> V_115 == V_117 ) {
F_19 ( & V_4 -> V_104 ) ;
return;
}
F_34 ( L_48 ) ;
V_4 -> V_115 = V_117 ;
F_19 ( & V_4 -> V_104 ) ;
F_47 ( V_4 ) ;
}
int F_51 ( struct V_3 * V_4 )
{
if ( V_4 -> V_118 > ( V_4 -> V_119 -> V_120 * 4 ) ) {
F_6 ( L_49
L_50 , V_4 -> V_118 ,
V_4 -> V_119 -> V_120 * 4 ) ;
return - 1 ;
}
F_34 ( L_51
L_52 , V_4 -> V_118 ) ;
if ( F_7 ( V_4 , V_4 -> V_118 , 0 ) < 0 )
return - 1 ;
if ( V_4 -> V_121 > ( V_122 + ( V_123 * 2 ) +
V_4 -> V_119 -> V_124 ) ) {
F_6 ( L_53 ,
V_4 -> V_121 ) ;
return - 1 ;
}
F_34 ( L_54
L_55 , V_4 -> V_121 ) ;
if ( F_7 ( V_4 , V_4 -> V_121 , 0 ) < 0 )
return - 1 ;
return 0 ;
}
