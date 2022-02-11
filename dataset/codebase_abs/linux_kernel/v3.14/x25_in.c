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
if ( ! F_15 ( V_4 , V_17 ) )
goto V_35;
F_11 ( V_4 , V_17 ) ;
V_11 = F_16 ( V_4 , & V_23 ,
& V_24 ) ;
if ( V_11 > 0 )
F_11 ( V_4 , V_11 ) ;
else if ( V_11 < 0 )
goto V_35;
V_11 = F_17 ( V_4 , & V_9 -> V_36 ,
& V_9 -> V_37 ,
& V_9 -> V_38 ) ;
if ( V_11 > 0 )
F_11 ( V_4 , V_11 ) ;
else if ( V_11 < 0 )
goto V_35;
if ( V_4 -> V_11 > 0 ) {
if ( V_4 -> V_11 > V_39 )
goto V_35;
F_18 ( V_4 , 0 , V_9 -> V_40 . V_41 ,
V_4 -> V_11 ) ;
V_9 -> V_40 . V_42 = V_4 -> V_11 ;
}
if ( ! F_12 ( V_2 , V_19 ) )
V_2 -> V_43 ( V_2 ) ;
break;
}
case V_44 :
if ( ! F_15 ( V_4 , V_17 + 2 ) )
goto V_35;
F_19 ( V_2 , V_45 ) ;
F_20 ( V_2 , V_46 , V_4 -> V_47 [ 3 ] , V_4 -> V_47 [ 4 ] ) ;
break;
default:
break;
}
return 0 ;
V_35:
F_19 ( V_2 , V_44 ) ;
V_9 -> V_31 = V_48 ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 )
{
switch ( V_21 ) {
case V_44 :
if ( ! F_15 ( V_4 , V_17 + 2 ) )
goto V_35;
F_19 ( V_2 , V_45 ) ;
F_20 ( V_2 , 0 , V_4 -> V_47 [ 3 ] , V_4 -> V_47 [ 4 ] ) ;
break;
case V_45 :
F_20 ( V_2 , 0 , 0 , 0 ) ;
break;
default:
break;
}
return 0 ;
V_35:
F_19 ( V_2 , V_44 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 , int V_49 , int V_50 , int V_51 , int V_52 , int V_53 )
{
int V_54 = 0 ;
int V_55 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_55 = ( V_9 -> V_14 -> V_15 ) ? V_56 : V_57 ;
switch ( V_21 ) {
case V_58 :
F_19 ( V_2 , V_59 ) ;
F_14 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
F_24 ( V_2 ) ;
break;
case V_44 :
if ( ! F_15 ( V_4 , V_17 + 2 ) )
goto V_35;
F_19 ( V_2 , V_45 ) ;
F_20 ( V_2 , 0 , V_4 -> V_47 [ 3 ] , V_4 -> V_47 [ 4 ] ) ;
break;
case V_60 :
case V_61 :
if ( ! F_25 ( V_2 , V_50 ) ) {
F_26 ( V_2 ) ;
F_19 ( V_2 , V_58 ) ;
F_27 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_62 ;
} else {
F_28 ( V_2 , V_50 ) ;
if ( V_21 == V_61 ) {
V_9 -> V_26 |= V_63 ;
} else {
V_9 -> V_26 &= ~ V_63 ;
}
}
break;
case V_64 :
V_9 -> V_26 &= ~ V_63 ;
if ( ( V_49 != V_9 -> V_29 ) || ! F_25 ( V_2 , V_50 ) ) {
F_26 ( V_2 ) ;
F_19 ( V_2 , V_58 ) ;
F_27 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_62 ;
break;
}
F_28 ( V_2 , V_50 ) ;
if ( V_49 == V_9 -> V_29 ) {
if ( F_1 ( V_2 , V_4 , V_53 ) == 0 ) {
V_9 -> V_29 = ( V_9 -> V_29 + 1 ) % V_55 ;
V_54 = 1 ;
} else {
F_26 ( V_2 ) ;
F_19 ( V_2 , V_58 ) ;
F_27 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_27 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_28 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_62 ;
break;
}
if ( F_29 ( & V_2 -> V_65 ) >
( V_2 -> V_66 >> 1 ) )
V_9 -> V_26 |= V_67 ;
}
if ( ( ( V_9 -> V_30 + V_9 -> V_36 . V_68 ) % V_55 ) == V_9 -> V_29 ) {
V_9 -> V_26 &= ~ V_69 ;
F_14 ( V_2 ) ;
F_30 ( V_2 ) ;
} else {
V_9 -> V_26 |= V_69 ;
F_31 ( V_2 ) ;
}
break;
case V_70 :
F_32 ( V_71 , & V_9 -> V_72 ) ;
break;
case V_73 :
if ( F_12 ( V_2 , V_74 ) )
V_54 = ! F_33 ( V_2 , V_4 ) ;
else {
F_4 ( V_4 , V_2 ) ;
F_3 ( & V_9 -> V_75 , V_4 ) ;
V_54 = 1 ;
}
F_34 ( V_2 ) ;
F_19 ( V_2 , V_70 ) ;
break;
default:
F_35 ( L_1 , V_21 ) ;
break;
}
return V_54 ;
V_35:
F_19 ( V_2 , V_44 ) ;
V_9 -> V_31 = V_48 ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_21 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_21 ) {
case V_58 :
F_19 ( V_2 , V_59 ) ;
case V_59 : {
F_14 ( V_2 ) ;
V_9 -> V_26 = 0x00 ;
V_9 -> V_28 = 0 ;
V_9 -> V_29 = 0 ;
V_9 -> V_27 = 0 ;
V_9 -> V_30 = 0 ;
V_9 -> V_31 = V_32 ;
F_24 ( V_2 ) ;
break;
}
case V_44 :
if ( ! F_15 ( V_4 , V_17 + 2 ) )
goto V_35;
F_19 ( V_2 , V_45 ) ;
F_20 ( V_2 , 0 , V_4 -> V_47 [ 3 ] , V_4 -> V_47 [ 4 ] ) ;
break;
default:
break;
}
return 0 ;
V_35:
F_19 ( V_2 , V_44 ) ;
V_9 -> V_31 = V_48 ;
F_21 ( V_2 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_54 = 0 , V_21 , V_49 , V_50 , V_51 , V_52 , V_53 ;
if ( V_9 -> V_31 == V_76 )
return 0 ;
V_21 = F_38 ( V_2 , V_4 , & V_49 , & V_50 , & V_51 , & V_52 , & V_53 ) ;
switch ( V_9 -> V_31 ) {
case V_77 :
V_54 = F_13 ( V_2 , V_4 , V_21 ) ;
break;
case V_48 :
V_54 = F_22 ( V_2 , V_4 , V_21 ) ;
break;
case V_32 :
V_54 = F_23 ( V_2 , V_4 , V_21 , V_49 , V_50 , V_51 , V_52 , V_53 ) ;
break;
case V_62 :
V_54 = F_36 ( V_2 , V_4 , V_21 ) ;
break;
}
F_39 ( V_2 ) ;
return V_54 ;
}
int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_54 = F_37 ( V_2 , V_4 ) ;
if ( ! V_54 )
F_6 ( V_4 ) ;
return 0 ;
}
