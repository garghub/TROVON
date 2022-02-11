static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
char * V_7 = V_3 ;
T_2 V_8 [ V_9 + 1 ] ;
T_2 * V_10 ;
T_3 V_11 ;
struct V_12 V_13 [ 2 ] ;
struct V_14 V_15 ;
T_2 V_16 ;
if ( F_2 ( V_2 >= V_6 -> V_17 . V_18 ) )
return - V_19 ;
if ( ( V_2 + V_4 ) > V_6 -> V_17 . V_18 )
V_4 = V_6 -> V_17 . V_18 - V_2 ;
if ( F_2 ( ! V_4 ) )
return - V_19 ;
V_10 = V_8 ;
V_16 = V_20 ;
if ( V_6 -> V_17 . V_21 & V_22 )
if ( V_2 >= ( 1U << ( V_6 -> V_23 * 8 ) ) )
V_16 |= V_24 ;
* V_10 ++ = V_16 ;
switch ( V_6 -> V_23 ) {
default:
* V_10 ++ = V_2 >> 16 ;
case 2 :
* V_10 ++ = V_2 >> 8 ;
case 1 :
case 0 :
* V_10 ++ = V_2 >> 0 ;
}
F_3 ( & V_15 ) ;
memset ( V_13 , 0 , sizeof V_13 ) ;
V_13 [ 0 ] . V_25 = V_8 ;
V_13 [ 0 ] . V_26 = V_6 -> V_23 + 1 ;
F_4 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_27 = V_7 ;
V_13 [ 1 ] . V_26 = V_4 ;
F_4 ( & V_13 [ 1 ] , & V_15 ) ;
F_5 ( & V_6 -> V_28 ) ;
V_11 = F_6 ( V_6 -> V_29 , & V_15 ) ;
F_7 ( & V_6 -> V_29 -> V_30 , L_1 ,
V_4 , V_2 , V_11 ) ;
F_8 ( & V_6 -> V_28 ) ;
return V_11 ;
}
static int F_9 ( void * V_1 , unsigned int V_31 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
const char * V_7 = V_3 ;
int V_11 = 0 ;
unsigned V_32 ;
T_2 * V_33 ;
if ( F_2 ( V_31 >= V_6 -> V_17 . V_18 ) )
return - V_34 ;
if ( ( V_31 + V_4 ) > V_6 -> V_17 . V_18 )
V_4 = V_6 -> V_17 . V_18 - V_31 ;
if ( F_2 ( ! V_4 ) )
return - V_19 ;
V_32 = V_6 -> V_17 . V_35 ;
if ( V_32 > V_36 )
V_32 = V_36 ;
V_33 = F_10 ( V_32 + V_6 -> V_23 + 1 , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
F_5 ( & V_6 -> V_28 ) ;
do {
unsigned long V_39 , V_40 ;
unsigned V_41 ;
unsigned V_2 = ( unsigned ) V_31 ;
T_2 * V_10 = V_33 ;
int V_42 ;
T_2 V_16 ;
* V_10 = V_43 ;
V_11 = F_11 ( V_6 -> V_29 , V_10 , 1 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_6 -> V_29 -> V_30 , L_2 , V_11 ) ;
break;
}
V_16 = V_44 ;
if ( V_6 -> V_17 . V_21 & V_22 )
if ( V_2 >= ( 1U << ( V_6 -> V_23 * 8 ) ) )
V_16 |= V_24 ;
* V_10 ++ = V_16 ;
switch ( V_6 -> V_23 ) {
default:
* V_10 ++ = V_2 >> 16 ;
case 2 :
* V_10 ++ = V_2 >> 8 ;
case 1 :
case 0 :
* V_10 ++ = V_2 >> 0 ;
}
V_41 = V_32 - ( V_2 % V_32 ) ;
if ( V_41 > V_4 )
V_41 = V_4 ;
memcpy ( V_10 , V_7 , V_41 ) ;
V_11 = F_11 ( V_6 -> V_29 , V_33 ,
V_41 + V_6 -> V_23 + 1 ) ;
F_7 ( & V_6 -> V_29 -> V_30 , L_3 ,
V_41 , V_2 , V_11 ) ;
if ( V_11 < 0 )
break;
V_39 = V_45 + F_12 ( V_46 ) ;
V_40 = 0 ;
do {
V_42 = F_13 ( V_6 -> V_29 , V_47 ) ;
if ( V_42 < 0 || ( V_42 & V_48 ) ) {
F_7 ( & V_6 -> V_29 -> V_30 ,
L_4 , V_42 , V_42 ) ;
F_14 ( 1 ) ;
continue;
}
if ( ! ( V_42 & V_48 ) )
break;
} while ( V_40 ++ < 3 || F_15 ( V_45 , V_39 ) );
if ( ( V_42 < 0 ) || ( V_42 & V_48 ) ) {
F_16 ( & V_6 -> V_29 -> V_30 ,
L_5 ,
V_41 , V_2 ,
F_17 ( V_45 -
( V_39 - V_46 ) ) ) ;
V_11 = - V_49 ;
break;
}
V_31 += V_41 ;
V_7 += V_41 ;
V_4 -= V_41 ;
} while ( V_4 > 0 );
F_8 ( & V_6 -> V_28 ) ;
F_18 ( V_33 ) ;
return V_11 ;
}
static int F_19 ( struct V_50 * V_30 , struct V_51 * V_17 )
{
T_4 V_3 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
strncpy ( V_17 -> V_52 , L_6 , sizeof( V_17 -> V_52 ) ) ;
if ( F_20 ( V_30 , L_7 , & V_3 ) == 0 ||
F_20 ( V_30 , L_8 , & V_3 ) == 0 ) {
V_17 -> V_18 = V_3 ;
} else {
F_16 ( V_30 , L_9 ) ;
return - V_53 ;
}
if ( F_20 ( V_30 , L_10 , & V_3 ) == 0 ||
F_20 ( V_30 , L_11 , & V_3 ) == 0 ) {
V_17 -> V_35 = ( V_54 ) V_3 ;
} else {
F_16 ( V_30 , L_12 ) ;
return - V_53 ;
}
if ( F_20 ( V_30 , L_13 , & V_3 ) == 0 ) {
V_17 -> V_21 = ( V_54 ) V_3 ;
} else {
if ( F_20 ( V_30 , L_14 , & V_3 ) ) {
F_16 ( V_30 ,
L_15 ) ;
return - V_53 ;
}
switch ( V_3 ) {
case 8 :
V_17 -> V_21 |= V_55 ;
break;
case 16 :
V_17 -> V_21 |= V_56 ;
break;
case 24 :
V_17 -> V_21 |= V_57 ;
break;
default:
F_16 ( V_30 ,
L_16 ,
V_3 ) ;
return - V_53 ;
}
if ( F_21 ( V_30 , L_17 ) )
V_17 -> V_21 |= V_58 ;
}
return 0 ;
}
static int F_22 ( struct V_59 * V_29 )
{
struct V_5 * V_6 = NULL ;
struct V_51 V_17 ;
int V_60 ;
int V_42 ;
int V_23 ;
if ( ! V_29 -> V_30 . V_61 ) {
V_60 = F_19 ( & V_29 -> V_30 , & V_17 ) ;
if ( V_60 )
return V_60 ;
} else
V_17 = * (struct V_51 * ) V_29 -> V_30 . V_61 ;
if ( V_17 . V_21 & V_55 )
V_23 = 1 ;
else if ( V_17 . V_21 & V_56 )
V_23 = 2 ;
else if ( V_17 . V_21 & V_57 )
V_23 = 3 ;
else {
F_7 ( & V_29 -> V_30 , L_18 ) ;
return - V_19 ;
}
V_42 = F_13 ( V_29 , V_47 ) ;
if ( V_42 < 0 || V_42 & V_48 ) {
F_7 ( & V_29 -> V_30 , L_4 , V_42 , V_42 ) ;
return - V_62 ;
}
V_6 = F_23 ( & V_29 -> V_30 , sizeof( struct V_5 ) , V_37 ) ;
if ( ! V_6 )
return - V_38 ;
F_24 ( & V_6 -> V_28 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_29 = V_29 ;
F_25 ( V_29 , V_6 ) ;
V_6 -> V_23 = V_23 ;
V_6 -> V_63 . V_52 = F_26 ( & V_29 -> V_30 ) ;
V_6 -> V_63 . V_30 = & V_29 -> V_30 ;
V_6 -> V_63 . V_64 = V_17 . V_21 & V_58 ;
V_6 -> V_63 . V_65 = true ;
V_6 -> V_63 . V_66 = V_67 ;
V_6 -> V_63 . V_68 = true ;
V_6 -> V_63 . V_69 = & V_29 -> V_30 ;
V_6 -> V_63 . V_70 = F_1 ;
V_6 -> V_63 . V_71 = F_9 ;
V_6 -> V_63 . V_1 = V_6 ;
V_6 -> V_63 . V_72 = 4 ;
V_6 -> V_63 . V_73 = 1 ;
V_6 -> V_63 . V_74 = V_17 . V_18 ;
V_6 -> V_75 = F_27 ( & V_6 -> V_63 ) ;
if ( F_28 ( V_6 -> V_75 ) )
return F_29 ( V_6 -> V_75 ) ;
F_30 ( & V_29 -> V_30 , L_19 ,
( V_17 . V_18 < 1024 ) ? V_17 . V_18 : ( V_17 . V_18 / 1024 ) ,
( V_17 . V_18 < 1024 ) ? L_20 : L_21 ,
V_6 -> V_17 . V_52 ,
( V_17 . V_21 & V_58 ) ? L_22 : L_23 ,
V_6 -> V_17 . V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_29 )
{
struct V_5 * V_6 ;
V_6 = F_32 ( V_29 ) ;
F_33 ( V_6 -> V_75 ) ;
return 0 ;
}
