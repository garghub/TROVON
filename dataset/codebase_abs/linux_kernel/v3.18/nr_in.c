static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_3 * V_6 , * V_7 = V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_10 + V_11 ) ;
F_4 ( V_2 ) ;
if ( V_5 ) {
V_9 -> V_12 += V_4 -> V_13 ;
F_5 ( & V_9 -> V_14 , V_4 ) ;
return 0 ;
}
if ( ! V_5 && V_9 -> V_12 > 0 ) {
V_9 -> V_12 += V_4 -> V_13 ;
F_5 ( & V_9 -> V_14 , V_4 ) ;
if ( ( V_7 = F_6 ( V_9 -> V_12 , V_15 ) ) == NULL )
return 1 ;
F_7 ( V_7 ) ;
while ( ( V_6 = F_8 ( & V_9 -> V_14 ) ) != NULL ) {
F_9 ( V_6 ,
F_10 ( V_7 , V_6 -> V_13 ) ,
V_6 -> V_13 ) ;
F_11 ( V_6 ) ;
}
V_9 -> V_12 = 0 ;
}
return F_12 ( V_2 , V_7 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_16 )
{
switch ( V_16 ) {
case V_17 : {
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
F_4 ( V_2 ) ;
V_9 -> V_18 = V_4 -> V_19 [ 17 ] ;
V_9 -> V_20 = V_4 -> V_19 [ 18 ] ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = 0 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
V_9 -> V_25 = V_26 ;
V_9 -> V_27 = 0 ;
V_9 -> V_28 = V_4 -> V_19 [ 20 ] ;
V_2 -> V_29 = V_30 ;
if ( ! F_15 ( V_2 , V_31 ) )
V_2 -> V_32 ( V_2 ) ;
break;
}
case V_17 | V_33 :
F_16 ( V_2 , V_34 ) ;
break;
case V_35 :
if ( V_36 )
F_16 ( V_2 , V_37 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_16 )
{
switch ( V_16 ) {
case V_17 | V_33 :
F_16 ( V_2 , V_37 ) ;
break;
case V_38 :
F_18 ( V_2 , V_39 ) ;
case V_39 :
F_16 ( V_2 , 0 ) ;
break;
case V_35 :
if ( V_36 )
F_16 ( V_2 , V_37 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_16 )
{
struct V_8 * V_40 = F_2 ( V_2 ) ;
struct V_41 V_42 ;
struct V_3 * V_7 ;
unsigned short V_43 ;
unsigned short V_9 , V_44 ;
int V_45 = 0 ;
V_9 = V_4 -> V_19 [ 18 ] ;
V_44 = V_4 -> V_19 [ 17 ] ;
switch ( V_16 ) {
case V_46 :
F_18 ( V_2 , V_17 ) ;
break;
case V_38 :
F_18 ( V_2 , V_39 ) ;
F_16 ( V_2 , 0 ) ;
break;
case V_17 | V_33 :
case V_39 :
F_16 ( V_2 , V_37 ) ;
break;
case V_47 :
case V_47 | V_33 :
case V_47 | V_48 :
case V_47 | V_48 | V_33 :
if ( V_16 & V_33 ) {
V_40 -> V_49 |= V_50 ;
F_20 ( V_2 ) ;
} else {
V_40 -> V_49 &= ~ V_50 ;
F_21 ( V_2 ) ;
}
if ( ! F_22 ( V_2 , V_9 ) ) {
break;
}
if ( V_16 & V_48 ) {
F_23 ( V_2 , V_9 ) ;
F_24 ( V_2 ) ;
} else {
if ( V_40 -> V_49 & V_50 ) {
F_23 ( V_2 , V_9 ) ;
} else {
F_25 ( V_2 , V_9 ) ;
}
}
break;
case V_51 :
case V_51 | V_48 :
case V_51 | V_33 :
case V_51 | V_52 :
case V_51 | V_48 | V_33 :
case V_51 | V_33 | V_52 :
case V_51 | V_48 | V_52 :
case V_51 | V_48 | V_33 | V_52 :
if ( V_16 & V_33 ) {
V_40 -> V_49 |= V_50 ;
F_20 ( V_2 ) ;
} else {
V_40 -> V_49 &= ~ V_50 ;
F_21 ( V_2 ) ;
}
if ( F_22 ( V_2 , V_9 ) ) {
if ( V_16 & V_48 ) {
F_23 ( V_2 , V_9 ) ;
F_24 ( V_2 ) ;
} else {
if ( V_40 -> V_49 & V_50 ) {
F_23 ( V_2 , V_9 ) ;
} else {
F_25 ( V_2 , V_9 ) ;
}
}
}
V_45 = 1 ;
F_26 ( & V_40 -> V_53 , V_4 ) ;
if ( V_40 -> V_49 & V_54 )
break;
F_27 ( & V_42 ) ;
do {
V_43 = V_40 -> V_23 ;
while ( ( V_7 = F_8 ( & V_40 -> V_53 ) ) != NULL ) {
V_44 = V_7 -> V_19 [ 17 ] ;
if ( V_44 == V_40 -> V_23 ) {
if ( F_1 ( V_2 , V_7 , V_16 & V_52 ) == 0 ) {
V_40 -> V_23 = ( V_40 -> V_23 + 1 ) % V_55 ;
} else {
V_40 -> V_49 |= V_54 ;
F_5 ( & V_42 , V_7 ) ;
}
} else if ( F_28 ( V_2 , V_44 ) ) {
F_5 ( & V_42 , V_7 ) ;
} else {
F_11 ( V_7 ) ;
}
}
while ( ( V_7 = F_8 ( & V_42 ) ) != NULL ) {
F_5 ( & V_40 -> V_53 , V_7 ) ;
}
} while ( V_43 != V_40 -> V_23 );
if ( ( ( V_40 -> V_24 + V_40 -> V_28 ) % V_55 ) == V_40 -> V_23 ) {
F_29 ( V_2 ) ;
} else {
if ( ! ( V_40 -> V_49 & V_56 ) ) {
V_40 -> V_49 |= V_56 ;
F_30 ( V_2 ) ;
}
}
break;
case V_35 :
if ( V_36 )
F_16 ( V_2 , V_37 ) ;
break;
default:
break;
}
return V_45 ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_45 = 0 , V_16 ;
if ( V_9 -> V_25 == V_57 )
return 0 ;
V_16 = V_4 -> V_19 [ 19 ] ;
switch ( V_9 -> V_25 ) {
case V_58 :
V_45 = F_13 ( V_2 , V_4 , V_16 ) ;
break;
case V_59 :
V_45 = F_17 ( V_2 , V_4 , V_16 ) ;
break;
case V_26 :
V_45 = F_19 ( V_2 , V_4 , V_16 ) ;
break;
}
F_32 ( V_2 ) ;
return V_45 ;
}
