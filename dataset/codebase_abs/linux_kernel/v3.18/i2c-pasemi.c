static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_2 ( & V_2 -> V_5 -> V_5 , L_1 ,
V_2 -> V_6 + V_3 , V_4 ) ;
F_3 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_7 ;
V_7 = F_5 ( V_2 -> V_6 + V_3 ) ;
F_2 ( & V_2 -> V_5 -> V_5 , L_2 ,
V_2 -> V_6 + V_3 , V_7 ) ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
V_8 = F_4 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_9 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_10 = 10 ;
unsigned int V_8 ;
V_8 = F_4 ( V_2 , V_9 ) ;
while ( ! ( V_8 & V_11 ) && V_10 -- ) {
F_8 ( 1 ) ;
V_8 = F_4 ( V_2 , V_9 ) ;
}
if ( V_8 & V_12 )
return - V_13 ;
if ( V_10 < 0 ) {
F_9 ( & V_2 -> V_5 -> V_5 , L_3 , V_8 ) ;
F_1 ( V_2 , V_9 , V_8 ) ;
return - V_14 ;
}
F_1 ( V_2 , V_9 , V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 ,
struct V_17 * V_18 , int V_19 )
{
struct V_1 * V_2 = V_16 -> V_20 ;
int V_21 , V_22 , V_23 ;
T_1 V_24 ;
V_21 = V_18 -> V_25 & V_26 ? 1 : 0 ;
F_11 ( V_2 , V_27 | ( V_18 -> V_28 << 1 ) | V_21 ) ;
if ( V_21 ) {
F_11 ( V_2 , V_18 -> V_29 | V_30 |
( V_19 ? V_31 : 0 ) ) ;
V_23 = F_7 ( V_2 ) ;
if ( V_23 )
goto V_32;
for ( V_22 = 0 ; V_22 < V_18 -> V_29 ; V_22 ++ ) {
V_24 = F_12 ( V_2 ) ;
if ( V_24 & V_33 ) {
V_23 = - V_34 ;
goto V_32;
}
V_18 -> V_35 [ V_22 ] = V_24 & V_36 ;
}
} else {
for ( V_22 = 0 ; V_22 < V_18 -> V_29 - 1 ; V_22 ++ )
F_11 ( V_2 , V_18 -> V_35 [ V_22 ] ) ;
F_11 ( V_2 , V_18 -> V_35 [ V_18 -> V_29 - 1 ] |
( V_19 ? V_31 : 0 ) ) ;
}
return 0 ;
V_32:
F_1 ( V_2 , V_37 , ( V_38 | V_39 |
( V_40 & V_41 ) ) ) ;
return V_23 ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_17 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_16 -> V_20 ;
int V_7 , V_22 ;
F_6 ( V_2 ) ;
V_7 = 0 ;
for ( V_22 = 0 ; V_22 < V_43 && ! V_7 ; V_22 ++ )
V_7 = F_10 ( V_16 , & V_42 [ V_22 ] , ( V_22 == ( V_43 - 1 ) ) ) ;
return V_7 ? V_7 : V_43 ;
}
static int F_14 ( struct V_15 * V_16 ,
T_2 V_28 , unsigned short V_25 , char V_44 , T_3 V_45 ,
int V_46 , union V_47 * V_48 )
{
struct V_1 * V_2 = V_16 -> V_20 ;
unsigned int V_24 ;
int V_49 , V_23 ;
int V_29 = 0 , V_22 ;
V_28 <<= 1 ;
V_49 = V_44 == V_50 ;
F_6 ( V_2 ) ;
switch ( V_46 ) {
case V_51 :
F_11 ( V_2 , V_28 | V_49 | V_27 |
V_31 ) ;
break;
case V_52 :
F_11 ( V_2 , V_28 | V_49 | V_27 ) ;
if ( V_44 )
F_11 ( V_2 , 1 | V_31 | V_30 ) ;
else
F_11 ( V_2 , V_31 | V_45 ) ;
break;
case V_53 :
F_11 ( V_2 , V_28 | V_27 ) ;
F_11 ( V_2 , V_45 ) ;
if ( V_44 ) {
F_11 ( V_2 , V_28 | V_50 | V_27 ) ;
F_11 ( V_2 , 1 | V_30 | V_31 ) ;
} else {
F_11 ( V_2 , V_31 | V_48 -> V_54 ) ;
}
break;
case V_55 :
F_11 ( V_2 , V_28 | V_27 ) ;
F_11 ( V_2 , V_45 ) ;
if ( V_44 ) {
F_11 ( V_2 , V_28 | V_50 | V_27 ) ;
F_11 ( V_2 , 2 | V_30 | V_31 ) ;
} else {
F_11 ( V_2 , V_48 -> V_56 & V_57 ) ;
F_11 ( V_2 , V_31 | ( V_48 -> V_56 >> 8 ) ) ;
}
break;
case V_58 :
F_11 ( V_2 , V_28 | V_27 ) ;
F_11 ( V_2 , V_45 ) ;
if ( V_44 ) {
F_11 ( V_2 , V_28 | V_50 | V_27 ) ;
F_11 ( V_2 , 1 | V_30 ) ;
V_24 = F_12 ( V_2 ) ;
V_29 = F_15 ( T_3 , ( V_24 & V_36 ) ,
V_59 ) ;
F_11 ( V_2 , V_29 | V_30 |
V_31 ) ;
} else {
V_29 = F_15 ( T_3 , V_48 -> V_60 [ 0 ] , V_59 ) ;
F_11 ( V_2 , V_29 ) ;
for ( V_22 = 1 ; V_22 < V_29 ; V_22 ++ )
F_11 ( V_2 , V_48 -> V_60 [ V_22 ] ) ;
F_11 ( V_2 , V_48 -> V_60 [ V_29 ] | V_31 ) ;
}
break;
case V_61 :
V_44 = V_50 ;
F_11 ( V_2 , V_28 | V_27 ) ;
F_11 ( V_2 , V_45 ) ;
F_11 ( V_2 , V_48 -> V_56 & V_57 ) ;
F_11 ( V_2 , ( V_48 -> V_56 >> 8 ) & V_57 ) ;
F_11 ( V_2 , V_28 | V_50 | V_27 ) ;
F_11 ( V_2 , 2 | V_31 | V_30 ) ;
break;
case V_62 :
V_29 = F_15 ( T_3 , V_48 -> V_60 [ 0 ] , V_59 - 1 ) ;
V_44 = V_50 ;
F_11 ( V_2 , V_28 | V_27 ) ;
F_11 ( V_2 , V_45 ) ;
F_11 ( V_2 , V_29 ) ;
for ( V_22 = 1 ; V_22 <= V_29 ; V_22 ++ )
F_11 ( V_2 , V_48 -> V_60 [ V_22 ] ) ;
F_11 ( V_2 , V_28 | V_50 ) ;
F_11 ( V_2 , V_30 | 1 ) ;
V_24 = F_12 ( V_2 ) ;
V_29 = F_15 ( T_3 , ( V_24 & V_36 ) ,
V_59 - V_29 ) ;
F_11 ( V_2 , V_29 | V_30 | V_31 ) ;
break;
default:
F_9 ( & V_16 -> V_5 , L_4 , V_46 ) ;
return - V_63 ;
}
V_23 = F_7 ( V_2 ) ;
if ( V_23 )
goto V_32;
if ( V_44 == V_64 )
return 0 ;
switch ( V_46 ) {
case V_52 :
case V_53 :
V_24 = F_12 ( V_2 ) ;
if ( V_24 & V_33 ) {
V_23 = - V_34 ;
goto V_32;
}
V_48 -> V_54 = V_24 & V_36 ;
break;
case V_55 :
case V_61 :
V_24 = F_12 ( V_2 ) ;
if ( V_24 & V_33 ) {
V_23 = - V_34 ;
goto V_32;
}
V_48 -> V_56 = V_24 & V_36 ;
V_24 = F_12 ( V_2 ) ;
if ( V_24 & V_33 ) {
V_23 = - V_34 ;
goto V_32;
}
V_48 -> V_56 |= ( V_24 & V_36 ) << 8 ;
break;
case V_58 :
case V_62 :
V_48 -> V_60 [ 0 ] = V_29 ;
for ( V_22 = 1 ; V_22 <= V_29 ; V_22 ++ ) {
V_24 = F_12 ( V_2 ) ;
if ( V_24 & V_33 ) {
V_23 = - V_34 ;
goto V_32;
}
V_48 -> V_60 [ V_22 ] = V_24 & V_36 ;
}
break;
}
return 0 ;
V_32:
F_1 ( V_2 , V_37 , ( V_38 | V_39 |
( V_40 & V_41 ) ) ) ;
return V_23 ;
}
static T_1 F_16 ( struct V_15 * V_16 )
{
return V_65 | V_66 |
V_67 | V_68 |
V_69 | V_70 |
V_71 | V_72 ;
}
static int F_17 ( struct V_73 * V_5 ,
const struct V_74 * V_75 )
{
struct V_1 * V_2 ;
int error ;
if ( ! ( F_18 ( V_5 , 0 ) & V_76 ) )
return - V_77 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = F_20 ( V_5 , 0 ) ;
V_2 -> V_46 = F_21 ( V_5 , 0 ) ;
if ( ! F_22 ( V_2 -> V_6 , V_2 -> V_46 ,
V_80 . V_81 ) ) {
error = - V_82 ;
goto V_83;
}
V_2 -> V_16 . V_84 = V_85 ;
snprintf ( V_2 -> V_16 . V_81 , sizeof( V_2 -> V_16 . V_81 ) ,
L_5 , V_2 -> V_6 ) ;
V_2 -> V_16 . V_86 = V_87 | V_88 ;
V_2 -> V_16 . V_89 = & V_90 ;
V_2 -> V_16 . V_20 = V_2 ;
V_2 -> V_16 . V_91 = F_23 ( V_5 -> V_92 ) ;
V_2 -> V_16 . V_5 . V_93 = & V_5 -> V_5 ;
F_1 ( V_2 , V_37 , ( V_38 | V_39 |
( V_40 & V_41 ) ) ) ;
error = F_24 ( & V_2 -> V_16 ) ;
if ( error )
goto V_94;
F_25 ( V_5 , V_2 ) ;
return 0 ;
V_94:
F_26 ( V_2 -> V_6 , V_2 -> V_46 ) ;
V_83:
F_27 ( V_2 ) ;
return error ;
}
static void F_28 ( struct V_73 * V_5 )
{
struct V_1 * V_2 = F_29 ( V_5 ) ;
F_30 ( & V_2 -> V_16 ) ;
F_26 ( V_2 -> V_6 , V_2 -> V_46 ) ;
F_27 ( V_2 ) ;
}
