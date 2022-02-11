static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_3 * V_6 , * V_7 = V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_5 ) {
V_9 -> V_10 += V_4 -> V_11 ;
F_3 ( & V_9 -> V_12 , V_4 ) ;
F_4 ( V_4 , V_2 ) ;
return 0 ;
}
if ( ! V_5 && V_9 -> V_10 > 0 ) {
int V_11 = V_9 -> V_10 + V_4 -> V_11 ;
if ( ( V_7 = F_5 ( V_11 , V_13 ) ) == NULL ) {
F_6 ( V_4 ) ;
return 1 ;
}
F_3 ( & V_9 -> V_12 , V_4 ) ;
F_7 ( V_7 ) ;
V_6 = F_8 ( & V_9 -> V_12 ) ;
F_9 ( V_6 , F_10 ( V_7 , V_6 -> V_11 ) ,
V_6 -> V_11 ) ;
F_6 ( V_6 ) ;
while ( ( V_6 =
F_8 ( & V_9 -> V_12 ) ) != NULL ) {
F_11 ( V_6 , ( V_9 -> V_14 -> V_15 ) ?
V_16 : V_17 ) ;
F_9 ( V_6 ,
F_10 ( V_7 , V_6 -> V_11 ) ,
V_6 -> V_11 ) ;
F_6 ( V_6 ) ;
}
V_9 -> V_10 = 0 ;
}
F_4 ( V_7 , V_2 ) ;
F_3 ( & V_2 -> V_18 , V_7 ) ;
if ( ! F_12 ( V_2 , V_19 ) )
V_2 -> V_20 ( V_2 , V_7 -> V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 )
{
struct V_22 V_23 , V_24 ;
int V_11 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_21 ) {
case V_25 : {
F_14 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_32 ;
V_2 -> V_33 = V_34 ;
F_11 ( V_4 , V_17 ) ;
V_11 = F_15 ( V_4 , & V_23 ,
& V_24 ) ;
if ( V_11 > 0 )
F_11 ( V_4 , V_11 ) ;
else if ( V_11 < 0 )
goto V_35;
V_11 = F_16 ( V_4 , & V_9 -> V_36 ,
& V_9 -> V_37 ,
& V_9 -> V_38 ) ;
if ( V_11 > 0 )
F_11 ( V_4 , V_11 ) ;
else if ( V_11 < 0 )
goto V_35;
if ( V_4 -> V_11 > 0 ) {
F_9 ( V_4 ,
V_9 -> V_39 . V_40 ,
V_4 -> V_11 ) ;
V_9 -> V_39 . V_41 = V_4 -> V_11 ;
}
if ( ! F_12 ( V_2 , V_19 ) )
V_2 -> V_42 ( V_2 ) ;
break;
}
case V_43 :
F_17 ( V_2 , V_44 ) ;
F_18 ( V_2 , V_45 , V_4 -> V_46 [ 3 ] , V_4 -> V_46 [ 4 ] ) ;
break;
default:
break;
}
return 0 ;
V_35:
F_17 ( V_2 , V_43 ) ;
V_9 -> V_31 = V_47 ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 )
{
switch ( V_21 ) {
case V_43 :
F_17 ( V_2 , V_44 ) ;
F_18 ( V_2 , 0 , V_4 -> V_46 [ 3 ] , V_4 -> V_46 [ 4 ] ) ;
break;
case V_44 :
F_18 ( V_2 , 0 , 0 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 , int V_48 , int V_49 , int V_50 , int V_51 , int V_52 )
{
int V_53 = 0 ;
int V_54 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_54 = ( V_9 -> V_14 -> V_15 ) ? V_55 : V_56 ;
switch ( V_21 ) {
case V_57 :
F_17 ( V_2 , V_58 ) ;
F_14 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
F_22 ( V_2 ) ;
break;
case V_43 :
F_17 ( V_2 , V_44 ) ;
F_18 ( V_2 , 0 , V_4 -> V_46 [ 3 ] , V_4 -> V_46 [ 4 ] ) ;
break;
case V_59 :
case V_60 :
if ( ! F_23 ( V_2 , V_49 ) ) {
F_24 ( V_2 ) ;
F_17 ( V_2 , V_57 ) ;
F_25 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_61 ;
} else {
F_26 ( V_2 , V_49 ) ;
if ( V_21 == V_60 ) {
V_9 -> V_26 |= V_62 ;
} else {
V_9 -> V_26 &= ~ V_62 ;
}
}
break;
case V_63 :
V_9 -> V_26 &= ~ V_62 ;
if ( ( V_48 != V_9 -> V_29 ) || ! F_23 ( V_2 , V_49 ) ) {
F_24 ( V_2 ) ;
F_17 ( V_2 , V_57 ) ;
F_25 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_61 ;
break;
}
F_26 ( V_2 , V_49 ) ;
if ( V_48 == V_9 -> V_29 ) {
if ( F_1 ( V_2 , V_4 , V_52 ) == 0 ) {
V_9 -> V_29 = ( V_9 -> V_29 + 1 ) % V_54 ;
V_53 = 1 ;
} else {
F_24 ( V_2 ) ;
F_17 ( V_2 , V_57 ) ;
F_25 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_61 ;
break;
}
if ( F_27 ( & V_2 -> V_64 ) >
( V_2 -> V_65 >> 1 ) )
V_9 -> V_26 |= V_66 ;
}
if ( ( ( V_9 -> V_30 + V_9 -> V_36 . V_67 ) % V_54 ) == V_9 -> V_29 ) {
V_9 -> V_26 &= ~ V_68 ;
F_14 ( V_2 ) ;
F_28 ( V_2 ) ;
} else {
V_9 -> V_26 |= V_68 ;
F_29 ( V_2 ) ;
}
break;
case V_69 :
F_30 ( V_70 , & V_9 -> V_71 ) ;
break;
case V_72 :
if ( F_12 ( V_2 , V_73 ) )
V_53 = ! F_31 ( V_2 , V_4 ) ;
else {
F_4 ( V_4 , V_2 ) ;
F_3 ( & V_9 -> V_74 , V_4 ) ;
V_53 = 1 ;
}
F_32 ( V_2 ) ;
F_17 ( V_2 , V_69 ) ;
break;
default:
F_33 ( V_75 L_1 , V_21 ) ;
break;
}
return V_53 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 )
{
switch ( V_21 ) {
case V_57 :
F_17 ( V_2 , V_58 ) ;
case V_58 : {
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_28 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_27 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_32 ;
F_22 ( V_2 ) ;
break;
}
case V_43 :
F_17 ( V_2 , V_44 ) ;
F_18 ( V_2 , 0 , V_4 -> V_46 [ 3 ] , V_4 -> V_46 [ 4 ] ) ;
break;
default:
break;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_53 = 0 , V_21 , V_48 , V_49 , V_50 , V_51 , V_52 ;
if ( V_9 -> V_31 == V_76 )
return 0 ;
V_21 = F_36 ( V_2 , V_4 , & V_48 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
switch ( V_9 -> V_31 ) {
case V_77 :
V_53 = F_13 ( V_2 , V_4 , V_21 ) ;
break;
case V_47 :
V_53 = F_20 ( V_2 , V_4 , V_21 ) ;
break;
case V_32 :
V_53 = F_21 ( V_2 , V_4 , V_21 , V_48 , V_49 , V_50 , V_51 , V_52 ) ;
break;
case V_61 :
V_53 = F_34 ( V_2 , V_4 , V_21 ) ;
break;
}
F_37 ( V_2 ) ;
return V_53 ;
}
int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_53 = F_35 ( V_2 , V_4 ) ;
if ( ! V_53 )
F_6 ( V_4 ) ;
return 0 ;
}
