static inline bool F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 ,
int V_5 , int V_6 ,
int V_7 , int V_8 )
{
if ( V_8 <= 50 )
return false ;
if ( V_7 > V_6 + V_5 )
return true ;
if ( V_3 >= V_2 -> V_9 &&
V_7 >= V_2 -> V_10 &&
( V_7 > V_6 + V_4 ) )
return true ;
return false ;
}
static inline bool F_2 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
int V_3 , int V_7 ,
int V_6 )
{
bool V_13 , V_14 , V_15 ;
V_13 = V_14 = V_15 = false ;
if ( V_12 -> V_16 == V_17 &&
V_12 -> V_18 == V_19 )
V_14 = true ;
if ( V_12 -> V_16 == V_19 &&
V_12 -> V_18 == V_17 )
V_15 = true ;
switch ( V_12 -> V_20 ) {
case 0 :
if ( V_3 > V_21 )
V_13 = true ;
break;
case 1 :
case 2 :
if ( V_7 < 4 || V_7 < V_2 -> V_10 )
break;
if ( ( V_14 && ( V_7 >= ( V_6 - 5 ) ) ) ||
( V_15 && ( V_7 >= ( V_6 - 2 ) ) ) ||
( V_3 > V_2 -> V_22 ) )
V_13 = true ;
break;
case 3 :
if ( V_7 < 4 || V_7 < V_2 -> V_10 )
break;
if ( ( V_14 && ( V_7 >= ( V_6 - 3 ) ) ) ||
( V_15 && ( V_7 >= ( V_6 + 3 ) ) ) ||
( V_3 > V_2 -> V_22 ) )
V_13 = true ;
break;
}
return V_13 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_11 V_23 ,
int V_6 )
{
V_2 -> V_24 = 0 ;
if ( V_23 . V_16 == V_17 )
V_2 -> V_25 = V_6 ;
else if ( V_23 . V_16 == V_19 )
V_2 -> V_26 = V_6 ;
switch ( ( V_23 . V_16 << 4 ) | V_23 . V_18 ) {
case 0x10 :
V_2 -> V_27 = V_28 ;
V_2 -> V_29 =
V_30 ;
V_2 -> V_31 = V_19 ;
break;
case 0x20 :
V_2 -> V_27 = V_28 ;
V_2 -> V_29 =
V_30 ;
V_2 -> V_31 = V_17 ;
break;
case 0x21 :
V_2 -> V_27 = V_17 ;
V_2 -> V_29 =
V_28 ;
V_2 -> V_31 =
V_30 ;
break;
case 0x12 :
V_2 -> V_27 = V_19 ;
V_2 -> V_29 =
V_28 ;
V_2 -> V_31 =
V_30 ;
break;
case 0x13 :
V_2 -> V_27 = V_30 ;
V_2 -> V_29 =
V_28 ;
V_2 -> V_31 = V_19 ;
break;
case 0x23 :
V_2 -> V_27 = V_30 ;
V_2 -> V_29 =
V_28 ;
V_2 -> V_31 = V_17 ;
break;
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( V_2 -> V_32 && V_2 -> V_33 ) {
if ( V_2 -> V_34 > V_2 -> V_35 ) {
if ( ( V_2 -> V_29 == V_19 ) ||
( V_2 -> V_29 == V_17 ) )
if ( V_12 -> V_16 == V_17 )
V_12 -> V_18 = V_19 ;
else
V_12 -> V_18 = V_17 ;
else
V_12 -> V_18 =
V_2 -> V_29 ;
} else if ( ( V_2 -> V_31 == V_19 ) ||
( V_2 -> V_31 == V_17 ) ) {
if ( V_12 -> V_16 == V_17 )
V_12 -> V_18 = V_19 ;
else
V_12 -> V_18 = V_17 ;
} else {
V_12 -> V_18 = V_2 -> V_31 ;
}
} else if ( V_2 -> V_32 ) {
if ( ( V_2 -> V_29 == V_19 ) ||
( V_2 -> V_29 == V_17 ) )
if ( V_12 -> V_16 == V_17 )
V_12 -> V_18 = V_19 ;
else
V_12 -> V_18 = V_17 ;
else
V_12 -> V_18 = V_2 -> V_29 ;
} else if ( V_2 -> V_33 ) {
if ( ( V_2 -> V_31 == V_19 ) ||
( V_2 -> V_31 == V_17 ) )
if ( V_12 -> V_16 == V_17 )
V_12 -> V_18 = V_19 ;
else
V_12 -> V_18 = V_17 ;
else
V_12 -> V_18 = V_2 -> V_31 ;
} else {
if ( ( V_2 -> V_27 == V_19 ) ||
( V_2 -> V_27 == V_17 ) )
if ( V_12 -> V_16 == V_17 )
V_12 -> V_18 = V_19 ;
else
V_12 -> V_18 = V_17 ;
else
V_12 -> V_18 = V_2 -> V_27 ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_36 ,
int V_6 , int V_7 ,
int V_3 )
{
switch ( V_2 -> V_24 ) {
case 0 :
V_36 -> V_16 = V_2 -> V_27 ;
V_36 -> V_18 = V_2 -> V_29 ;
break;
case 1 :
V_36 -> V_16 = V_2 -> V_27 ;
V_36 -> V_18 = V_2 -> V_31 ;
V_2 -> V_37 = V_6 ;
V_2 -> V_34 = V_7 ;
if ( V_2 -> V_27 == V_19 ) {
if ( F_1 ( V_2 , V_3 ,
V_38 ,
V_39 ,
V_6 , V_7 ,
V_2 -> V_40 ) )
V_2 -> V_32 = true ;
else
V_2 -> V_32 = false ;
} else if ( V_2 -> V_27 == V_17 ) {
if ( F_1 ( V_2 , V_3 ,
V_41 ,
V_39 ,
V_6 , V_7 ,
V_2 -> V_40 ) )
V_2 -> V_32 = true ;
else
V_2 -> V_32 = false ;
} else {
if ( F_1 ( V_2 , V_3 ,
V_38 ,
0 ,
V_6 , V_7 ,
V_2 -> V_40 ) )
V_2 -> V_32 = true ;
else
V_2 -> V_32 = false ;
}
break;
case 2 :
V_2 -> V_42 = false ;
V_2 -> V_43 = false ;
V_2 -> V_44 = false ;
V_2 -> V_37 = V_6 ;
V_2 -> V_35 = V_7 ;
switch( V_2 -> V_31 ) {
case V_19 :
V_2 -> V_26 = V_7 ;
break;
case V_17 :
V_2 -> V_25 = V_7 ;
break;
case V_30 :
if ( V_2 -> V_27 == V_17 )
V_2 -> V_25 = V_6 ;
else if ( V_2 -> V_27 == V_19 )
V_2 -> V_26 = V_6 ;
break;
default:
break;
}
if ( V_2 -> V_25 > V_2 -> V_26 +
V_36 -> V_45 )
V_36 -> V_16 = V_17 ;
else
V_36 -> V_16 = V_19 ;
if ( V_2 -> V_27 == V_19 ) {
if ( F_1 ( V_2 , V_3 ,
V_38 ,
V_39 ,
V_6 , V_7 ,
V_2 -> V_40 ) )
V_2 -> V_33 = true ;
else
V_2 -> V_33 = false ;
} else if ( V_2 -> V_27 == V_17 ) {
if ( F_1 ( V_2 , V_3 ,
V_41 ,
V_39 ,
V_6 , V_7 ,
V_2 -> V_40 ) )
V_2 -> V_33 = true ;
else
V_2 -> V_33 = false ;
} else {
if ( F_1 ( V_2 , V_3 ,
V_38 ,
0 ,
V_6 , V_7 ,
V_2 -> V_40 ) )
V_2 -> V_33 = true ;
else
V_2 -> V_33 = false ;
}
F_4 ( V_2 , V_36 ) ;
break;
default:
break;
}
}
static void F_6 ( struct V_11 * V_23 ,
struct V_1 * V_2 ,
int V_3 )
{
V_23 -> V_46 = 0 ;
V_23 -> V_47 = 0 ;
if ( V_23 -> V_20 == 0 ) {
switch ( ( V_23 -> V_16 << 4 ) |
V_23 -> V_18 ) {
case 0x01 :
V_23 -> V_48 = 0x3b ;
break;
case 0x02 :
V_23 -> V_48 = 0x3d ;
break;
case 0x03 :
V_23 -> V_48 = 0x1 ;
break;
case 0x10 :
V_23 -> V_48 = 0x7 ;
break;
case 0x12 :
V_23 -> V_48 = 0x2 ;
break;
case 0x13 :
V_23 -> V_48 = 0x7 ;
break;
case 0x20 :
V_23 -> V_48 = 0x6 ;
break;
case 0x21 :
V_23 -> V_48 = 0x0 ;
break;
case 0x23 :
V_23 -> V_48 = 0x6 ;
break;
case 0x30 :
V_23 -> V_48 = 0x1 ;
break;
case 0x31 :
V_23 -> V_48 = 0x3b ;
break;
case 0x32 :
V_23 -> V_48 = 0x3d ;
break;
default:
break;
}
} else if ( V_23 -> V_20 == 1 ) {
switch ( ( V_23 -> V_16 << 4 ) |
V_23 -> V_18 ) {
case 0x01 :
V_23 -> V_48 = 0x1 ;
break;
case 0x02 :
V_23 -> V_48 = 0x1 ;
break;
case 0x03 :
V_23 -> V_48 = 0x1 ;
break;
case 0x10 :
if ( ! ( V_2 -> V_44 ) &&
( V_3 > V_21 ) )
V_23 -> V_48 = 0x3f ;
else
V_23 -> V_48 = 0x1 ;
break;
case 0x12 :
V_23 -> V_48 = 0x1 ;
break;
case 0x13 :
if ( ! ( V_2 -> V_44 ) &&
( V_3 > V_21 ) )
V_23 -> V_48 = 0x3f ;
else
V_23 -> V_48 = 0x1 ;
break;
case 0x20 :
if ( ! ( V_2 -> V_44 ) &&
( V_3 > V_21 ) )
V_23 -> V_48 = 0x3f ;
else
V_23 -> V_48 = 0x1 ;
break;
case 0x21 :
V_23 -> V_48 = 0x1 ;
break;
case 0x23 :
if ( ! ( V_2 -> V_44 ) &&
( V_3 > V_21 ) )
V_23 -> V_48 = 0x3f ;
else
V_23 -> V_48 = 0x1 ;
break;
case 0x30 :
V_23 -> V_48 = 0x1 ;
break;
case 0x31 :
V_23 -> V_48 = 0x1 ;
break;
case 0x32 :
V_23 -> V_48 = 0x1 ;
break;
default:
break;
}
} else if ( V_23 -> V_20 == 2 ) {
switch ( ( V_23 -> V_16 << 4 ) |
V_23 -> V_18 ) {
case 0x01 :
V_23 -> V_48 = 0x1 ;
break;
case 0x02 :
V_23 -> V_48 = 0x1 ;
break;
case 0x03 :
V_23 -> V_48 = 0x1 ;
break;
case 0x10 :
if ( ! V_2 -> V_44 && ( V_3 > V_2 -> V_22 ) )
V_23 -> V_48 = 0x1 ;
else
V_23 -> V_48 = 0x2 ;
break;
case 0x12 :
V_23 -> V_48 = 0x1 ;
break;
case 0x13 :
if ( ! V_2 -> V_44 && ( V_3 > V_2 -> V_22 ) )
V_23 -> V_48 = 0x1 ;
else
V_23 -> V_48 = 0x2 ;
break;
case 0x20 :
if ( ! V_2 -> V_44 && ( V_3 > V_2 -> V_22 ) )
V_23 -> V_48 = 0x1 ;
else
V_23 -> V_48 = 0x2 ;
break;
case 0x21 :
V_23 -> V_48 = 0x1 ;
break;
case 0x23 :
if ( ! V_2 -> V_44 && ( V_3 > V_2 -> V_22 ) )
V_23 -> V_48 = 0x1 ;
else
V_23 -> V_48 = 0x2 ;
break;
case 0x30 :
V_23 -> V_48 = 0x1 ;
break;
case 0x31 :
V_23 -> V_48 = 0x1 ;
break;
case 0x32 :
V_23 -> V_48 = 0x1 ;
break;
default:
break;
}
if ( V_2 -> V_48 )
V_23 -> V_48 = V_2 -> V_48 ;
} else if ( V_23 -> V_20 == 3 ) {
switch ( ( V_23 -> V_16 << 4 ) |
V_23 -> V_18 ) {
case 0x01 :
V_23 -> V_48 = 0x1 ;
break;
case 0x02 :
V_23 -> V_48 = 0x39 ;
break;
case 0x03 :
V_23 -> V_48 = 0x1 ;
break;
case 0x10 :
V_23 -> V_48 = 0x2 ;
break;
case 0x12 :
V_23 -> V_48 = 0x3f ;
break;
case 0x13 :
V_23 -> V_48 = 0x2 ;
break;
case 0x20 :
V_23 -> V_48 = 0x3 ;
break;
case 0x21 :
V_23 -> V_48 = 0x3 ;
break;
case 0x23 :
V_23 -> V_48 = 0x3 ;
break;
case 0x30 :
V_23 -> V_48 = 0x1 ;
break;
case 0x31 :
V_23 -> V_48 = 0x6 ;
break;
case 0x32 :
V_23 -> V_48 = 0x1 ;
break;
default:
break;
}
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
int V_49 , int V_7 ,
int V_6 )
{
switch ( V_49 ) {
case V_17 :
V_2 -> V_25 = V_7 ;
V_2 -> V_26 = V_6 ;
V_2 -> V_44 = true ;
V_12 -> V_16 = V_19 ;
V_12 -> V_18 = V_30 ;
break;
case V_19 :
V_2 -> V_26 = V_7 ;
V_2 -> V_25 = V_6 ;
V_2 -> V_44 = true ;
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = V_30 ;
break;
case V_30 :
V_2 -> V_50 = V_7 ;
V_2 -> V_44 = true ;
V_12 -> V_18 = V_28 ;
break;
case V_28 :
V_2 -> V_51 = V_7 ;
V_2 -> V_44 = false ;
if ( V_2 -> V_25 >
( V_2 -> V_26 + V_12 -> V_45 ) ) {
if ( ( V_2 -> V_50 > V_2 -> V_26 ) &&
( V_2 -> V_50 > V_2 -> V_51 ) ) {
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = V_30 ;
} else if ( V_2 -> V_51 >
V_2 -> V_26 ) {
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = V_28 ;
} else {
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = V_19 ;
}
} else {
if ( ( V_2 -> V_50 > V_2 -> V_25 ) &&
( V_2 -> V_50 > V_2 -> V_51 ) ) {
V_12 -> V_16 = V_19 ;
V_12 -> V_18 = V_30 ;
} else if ( V_2 -> V_51 >
V_2 -> V_26 ) {
V_12 -> V_16 = V_19 ;
V_12 -> V_18 = V_28 ;
} else {
V_12 -> V_16 = V_19 ;
V_12 -> V_18 = V_17 ;
}
}
break;
default:
break;
}
}
static bool F_8 ( struct V_11 * V_36 ,
struct V_1 * V_2 ,
int V_3 , int V_7 ,
int V_6 , int V_52 ,
int V_49 )
{
bool V_53 = false ;
if ( F_2 ( V_36 , V_2 , V_3 ,
V_7 , V_6 ) ) {
if ( V_49 == V_17 ) {
V_36 -> V_16 = V_17 ;
V_36 -> V_18 = V_19 ;
} else if ( V_49 == V_19 ) {
V_36 -> V_16 = V_19 ;
V_36 -> V_18 = V_17 ;
}
V_53 = true ;
} else if ( ( V_49 != V_19 ) &&
( V_49 != V_17 ) ) {
if ( V_52 == V_17 )
V_36 -> V_18 = V_19 ;
else if ( V_52 == V_19 )
V_36 -> V_18 = V_17 ;
V_53 = true ;
}
return V_53 ;
}
static bool F_9 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 -> V_44 || ! V_2 -> V_42 )
return false ;
if ( F_10 ( V_54 , V_2 -> V_55 +
F_11 ( V_56 ) ) )
return true ;
if ( V_2 -> V_40 == V_57 ) {
V_3 = ( ( V_2 -> V_58 * 100 ) /
V_2 -> V_40 ) ;
if ( V_3 < V_2 -> V_22 )
return true ;
}
return false ;
}
void F_12 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_11 V_36 ;
struct V_1 * V_2 = & V_60 -> V_63 ;
int V_3 = 0 , V_7 = 0 , V_6 = 0 , V_49 ;
int V_52 ;
int V_64 = V_62 -> V_65 ;
int V_66 = V_62 -> V_67 ;
int V_68 , V_69 ;
bool V_70 = false , V_53 ;
V_68 = ( V_62 -> V_71 >> V_72 ) &
V_73 ;
V_69 = ( V_62 -> V_71 >> V_74 ) &
V_73 ;
if ( V_66 >= V_2 -> V_10 ) {
V_2 -> V_22 = V_21 ;
V_2 -> V_9 = V_75 ;
} else {
V_2 -> V_22 = V_76 ;
V_2 -> V_9 = V_77 ;
}
if ( V_64 > 0 && V_66 > 0 ) {
V_2 -> V_40 ++ ;
V_2 -> V_78 += V_64 ;
V_2 -> V_79 += V_66 ;
if ( V_69 == V_68 )
V_2 -> V_80 ++ ;
else
V_2 -> V_58 ++ ;
}
if ( V_69 == V_68 ) {
F_13 ( V_81 , V_82 ) ;
F_14 ( V_81 , V_68 ) ;
} else {
F_13 ( V_83 , V_82 ) ;
F_14 ( V_83 , V_68 ) ;
}
V_70 = F_9 ( V_2 ) ;
if ( ( ( V_2 -> V_40 < V_84 ) ||
V_62 -> V_85 ) && ! V_70 )
return;
if ( V_2 -> V_40 ) {
V_3 = ( ( V_2 -> V_58 * 100 ) /
V_2 -> V_40 ) ;
V_6 = ( V_2 -> V_78 /
V_2 -> V_40 ) ;
V_7 = ( V_2 -> V_79 /
V_2 -> V_40 ) ;
}
F_15 ( V_60 -> V_86 , & V_36 ) ;
V_49 = V_36 . V_18 ;
V_52 = V_36 . V_16 ;
V_2 -> V_87 ++ ;
if ( V_2 -> V_87 == V_88 ) {
if ( V_3 > V_2 -> V_22 ) {
F_3 ( V_2 , V_36 ,
V_6 ) ;
V_2 -> V_42 = true ;
} else {
V_2 -> V_42 = false ;
}
V_2 -> V_87 = 0 ;
V_2 -> V_44 = true ;
V_2 -> V_43 = true ;
}
if ( ! V_2 -> V_44 ) {
V_53 = F_8 ( & V_36 , V_2 , V_3 ,
V_7 , V_6 ,
V_52 , V_49 ) ;
if ( V_53 )
goto V_89;
}
if ( ! V_2 -> V_44 &&
( V_7 < ( V_6 + V_36 . V_90 ) ) )
goto V_89;
if ( ! V_2 -> V_43 ) {
F_7 ( V_2 , & V_36 , V_49 ,
V_7 , V_6 ) ;
} else {
if ( ! V_2 -> V_42 ) {
V_2 -> V_43 = false ;
if ( V_52 == V_17 ) {
V_36 . V_16 =
V_17 ;
V_36 . V_18 =
V_19 ;
} else if ( V_52 == V_19 ) {
V_36 . V_16 =
V_19 ;
V_36 . V_18 =
V_17 ;
}
goto V_89;
}
F_5 ( V_2 , & V_36 ,
V_6 , V_7 ,
V_3 ) ;
V_2 -> V_24 ++ ;
}
V_89:
F_6 ( & V_36 , V_2 , V_3 ) ;
F_16 ( V_60 -> V_86 , & V_36 ) ;
F_17 ( V_60 , & V_36 , V_6 , V_7 ) ;
V_2 -> V_55 = V_54 ;
V_2 -> V_40 = 0 ;
V_2 -> V_78 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 = 0 ;
V_2 -> V_58 = 0 ;
}
