static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 , T_2 V_5 )
{
T_1 V_6 = 0 ;
int V_7 ;
if ( V_4 <= V_5 ) {
F_2 ( L_1 , V_4 , V_5 ) ;
return - V_8 ;
}
V_7 = F_3 ( V_2 , & V_6 , V_4 - V_5 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_3 , V_5 ) ;
if ( V_7 )
return V_7 ;
* V_3 |= V_6 << V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
T_2 * V_9 = V_2 -> V_9 , V_10 = V_2 -> V_11 , V_12 = V_10 + V_4 ;
if ( V_4 > 64 ) {
F_2 ( L_2 , V_4 ) ;
return - V_8 ;
}
if ( V_12 > 64 )
return F_1 ( V_2 , V_3 , V_4 , 32 ) ;
else if ( V_2 -> V_13 < 8 && V_12 > 32 && V_12 <= 56 )
return F_1 ( V_2 , V_3 , V_4 , 16 ) ;
else if ( V_2 -> V_13 < 4 && V_12 > 16 && V_12 <= 24 )
return F_1 ( V_2 , V_3 , V_4 , 8 ) ;
if ( F_4 ( V_12 , 8 ) > V_2 -> V_13 )
return - V_14 ;
if ( V_12 <= 8 )
* V_3 = * V_9 >> ( 8 - V_12 ) ;
else if ( V_12 <= 16 )
* V_3 = F_5 ( F_6 ( ( V_15 * ) V_9 ) ) >> ( 16 - V_12 ) ;
else if ( V_12 <= 32 )
* V_3 = F_7 ( F_6 ( ( V_16 * ) V_9 ) ) >> ( 32 - V_12 ) ;
else
* V_3 = F_8 ( F_6 ( ( V_17 * ) V_9 ) ) >> ( 64 - V_12 ) ;
* V_3 &= F_9 ( V_4 - 1 , 0 ) ;
V_2 -> V_11 += V_4 ;
if ( V_2 -> V_11 > 7 ) {
V_2 -> V_9 += V_2 -> V_11 / 8 ;
V_2 -> V_13 -= V_2 -> V_11 / 8 ;
V_2 -> V_11 %= 8 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_4 )
{
T_1 V_18 ;
int V_7 ;
if ( V_4 > V_2 -> V_19 )
return - V_20 ;
V_7 = F_3 ( V_2 , & V_18 , V_4 * 8 ) ;
if ( V_7 )
return V_7 ;
switch ( V_4 ) {
case 2 :
F_11 ( F_12 ( ( V_21 ) V_18 ) , ( V_15 * ) V_2 -> V_22 ) ;
break;
case 4 :
F_11 ( F_13 ( ( V_23 ) V_18 ) , ( V_16 * ) V_2 -> V_22 ) ;
break;
case 8 :
F_11 ( F_14 ( ( T_1 ) V_18 ) , ( V_17 * ) V_2 -> V_22 ) ;
break;
default:
return - V_8 ;
}
V_2 -> V_22 += V_4 ;
V_2 -> V_19 -= V_4 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_24 , T_2 V_12 , T_1 V_25 )
{
T_1 V_26 , V_27 , V_28 = F_16 ( V_2 -> V_22 - V_2 -> V_29 , 8 ) ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_26 , V_12 ) ;
if ( V_7 )
return V_7 ;
V_27 = V_26 * V_24 ;
if ( V_28 > V_25 ) {
T_1 V_30 = F_16 ( V_28 , V_25 ) ;
T_1 V_31 = V_28 - V_30 ;
if ( V_27 >= V_31 )
V_30 -= V_25 ;
V_27 += V_30 ;
}
if ( V_27 + V_24 > V_28 ) {
F_2 ( L_3 , V_24 ,
( unsigned long ) V_27 , ( unsigned long ) V_28 ) ;
return - V_8 ;
}
if ( V_24 != 2 && V_24 != 4 && V_24 != 8 )
F_17 ( 1 , L_4 , V_24 ) ;
else
F_2 ( L_5 ,
V_24 , ( unsigned long ) V_26 ,
( unsigned long ) ( V_26 * V_24 ) , ( unsigned long ) V_27 ,
( unsigned long ) V_28 ,
( unsigned long ) F_18 ( & V_2 -> V_29 [ V_27 ] , V_24 ) ) ;
memcpy ( V_2 -> V_22 , & V_2 -> V_29 [ V_27 ] , V_24 ) ;
V_2 -> V_22 += V_24 ;
V_2 -> V_19 -= V_24 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_4 )
{
switch ( V_4 ) {
case 2 :
return F_15 ( V_2 , 2 , V_32 , V_33 ) ;
case 4 :
return F_15 ( V_2 , 4 , V_34 , V_35 ) ;
case 8 :
return F_15 ( V_2 , 8 , V_36 , V_37 ) ;
default:
return - V_8 ;
}
}
static int F_20 ( struct V_1 * V_2 , T_2 V_38 )
{
int V_39 , V_7 = 0 ;
if ( V_38 >= V_40 )
return - V_8 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
T_2 V_41 = V_42 [ V_38 ] [ V_39 ] ;
F_2 ( L_6 , V_41 ) ;
switch ( V_41 & V_43 ) {
case V_44 :
V_7 = F_10 ( V_2 , V_41 & V_45 ) ;
break;
case V_46 :
V_7 = F_19 ( V_2 , V_41 & V_45 ) ;
break;
case V_47 :
break;
default:
F_21 ( L_7 , V_41 ) ;
return - V_8 ;
}
if ( V_7 )
return V_7 ;
}
if ( V_48 )
F_22 ( & V_49 [ V_38 ] ) ;
return 0 ;
}
int F_23 ( const T_2 * V_9 , unsigned int V_13 ,
T_2 * V_22 , unsigned int * V_19 )
{
struct V_1 V_2 ;
int V_7 ;
T_1 V_41 , V_50 , V_6 , V_51 , V_28 ;
T_1 V_52 ;
V_2 . V_9 = ( T_2 * ) V_9 ;
V_2 . V_11 = 0 ;
V_2 . V_13 = V_13 ;
V_2 . V_22 = V_22 ;
V_2 . V_29 = V_22 ;
V_2 . V_19 = * V_19 ;
V_28 = V_2 . V_19 ;
* V_19 = 0 ;
do {
V_7 = F_3 ( & V_2 , & V_41 , V_53 ) ;
if ( V_7 )
return V_7 ;
F_2 ( L_8 , ( unsigned long ) V_41 ) ;
switch ( V_41 ) {
case V_54 :
V_7 = F_3 ( & V_2 , & V_50 , V_55 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 . V_22 == V_22 )
return - V_8 ;
V_50 ++ ;
if ( V_50 * 8 > V_2 . V_19 )
return - V_20 ;
while ( V_50 -- > 0 ) {
memcpy ( V_2 . V_22 , V_2 . V_22 - 8 , 8 ) ;
V_2 . V_22 += 8 ;
V_2 . V_19 -= 8 ;
}
if ( V_48 )
F_22 ( & V_56 ) ;
break;
case V_57 :
if ( 8 > V_2 . V_19 )
return - V_20 ;
memset ( V_2 . V_22 , 0 , 8 ) ;
V_2 . V_22 += 8 ;
V_2 . V_19 -= 8 ;
if ( V_48 )
F_22 ( & V_58 ) ;
break;
case V_59 :
V_7 = F_3 ( & V_2 , & V_51 , V_60 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_51 || V_51 > V_61 )
return - V_8 ;
while ( V_51 -- > 0 ) {
V_7 = F_3 ( & V_2 , & V_6 , 8 ) ;
if ( V_7 )
return V_7 ;
* V_2 . V_22 = ( T_2 ) V_6 ;
V_2 . V_22 ++ ;
V_2 . V_19 -- ;
}
if ( V_48 )
F_22 ( & V_62 ) ;
break;
case V_63 :
if ( V_48 )
F_22 ( & V_64 ) ;
break;
default:
V_7 = F_20 ( & V_2 , V_41 ) ;
if ( V_7 )
return V_7 ;
break;
}
} while ( V_41 != V_63 );
V_7 = F_3 ( & V_2 , & V_52 , V_65 ) ;
if ( V_7 )
return V_7 ;
if ( V_52 != ( T_1 ) F_24 ( 0 , V_22 , V_28 - V_2 . V_19 ) ) {
F_2 ( L_9 ) ;
return - V_8 ;
}
if ( F_25 ( ( V_28 - V_2 . V_19 ) > V_66 ) )
return - V_20 ;
* V_19 = V_28 - V_2 . V_19 ;
return 0 ;
}
static int T_3 F_26 ( void )
{
if ( V_48 )
F_27 () ;
return 0 ;
}
static void T_4 F_28 ( void )
{
if ( V_48 )
F_29 () ;
}
