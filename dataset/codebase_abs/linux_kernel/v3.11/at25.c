static T_1
F_1 (
struct V_1 * V_2 ,
char * V_3 ,
unsigned V_4 ,
T_2 V_5
)
{
T_3 V_6 [ V_7 + 1 ] ;
T_3 * V_8 ;
T_1 V_9 ;
struct V_10 V_11 [ 2 ] ;
struct V_12 V_13 ;
T_3 V_14 ;
if ( F_2 ( V_4 >= V_2 -> V_15 . V_16 ) )
return 0 ;
if ( ( V_4 + V_5 ) > V_2 -> V_15 . V_16 )
V_5 = V_2 -> V_15 . V_16 - V_4 ;
if ( F_2 ( ! V_5 ) )
return V_5 ;
V_8 = V_6 ;
V_14 = V_17 ;
if ( V_2 -> V_18 . V_19 & V_20 )
if ( V_4 >= ( 1U << ( V_2 -> V_21 * 8 ) ) )
V_14 |= V_22 ;
* V_8 ++ = V_14 ;
switch ( V_2 -> V_21 ) {
default:
* V_8 ++ = V_4 >> 16 ;
case 2 :
* V_8 ++ = V_4 >> 8 ;
case 1 :
case 0 :
* V_8 ++ = V_4 >> 0 ;
}
F_3 ( & V_13 ) ;
memset ( V_11 , 0 , sizeof V_11 ) ;
V_11 [ 0 ] . V_23 = V_6 ;
V_11 [ 0 ] . V_24 = V_2 -> V_21 + 1 ;
F_4 ( & V_11 [ 0 ] , & V_13 ) ;
V_11 [ 1 ] . V_25 = V_3 ;
V_11 [ 1 ] . V_24 = V_5 ;
F_4 ( & V_11 [ 1 ] , & V_13 ) ;
F_5 ( & V_2 -> V_26 ) ;
V_9 = F_6 ( V_2 -> V_27 , & V_13 ) ;
F_7 ( & V_2 -> V_27 -> V_28 ,
L_1 ,
V_5 , V_4 , ( int ) V_9 ) ;
F_8 ( & V_2 -> V_26 ) ;
return V_9 ? V_9 : V_5 ;
}
static T_1
F_9 ( struct V_29 * V_30 , struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_3 , T_4 V_35 , T_2 V_5 )
{
struct V_36 * V_28 ;
struct V_1 * V_2 ;
V_28 = F_10 ( V_32 , struct V_36 , V_32 ) ;
V_2 = F_11 ( V_28 ) ;
return F_1 ( V_2 , V_3 , V_35 , V_5 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , const char * V_3 , T_4 V_35 ,
T_2 V_5 )
{
T_1 V_9 = 0 ;
unsigned V_37 = 0 ;
unsigned V_38 ;
T_3 * V_39 ;
if ( F_2 ( V_35 >= V_2 -> V_15 . V_16 ) )
return - V_40 ;
if ( ( V_35 + V_5 ) > V_2 -> V_15 . V_16 )
V_5 = V_2 -> V_15 . V_16 - V_35 ;
if ( F_2 ( ! V_5 ) )
return V_5 ;
V_38 = V_2 -> V_18 . V_41 ;
if ( V_38 > V_42 )
V_38 = V_42 ;
V_39 = F_13 ( V_38 + V_2 -> V_21 + 1 , V_43 ) ;
if ( ! V_39 )
return - V_44 ;
F_5 ( & V_2 -> V_26 ) ;
do {
unsigned long V_45 , V_46 ;
unsigned V_47 ;
unsigned V_4 = ( unsigned ) V_35 ;
T_3 * V_8 = V_39 ;
int V_48 ;
T_3 V_14 ;
* V_8 = V_49 ;
V_9 = F_14 ( V_2 -> V_27 , V_8 , 1 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_2 -> V_27 -> V_28 , L_2 ,
( int ) V_9 ) ;
break;
}
V_14 = V_50 ;
if ( V_2 -> V_18 . V_19 & V_20 )
if ( V_4 >= ( 1U << ( V_2 -> V_21 * 8 ) ) )
V_14 |= V_22 ;
* V_8 ++ = V_14 ;
switch ( V_2 -> V_21 ) {
default:
* V_8 ++ = V_4 >> 16 ;
case 2 :
* V_8 ++ = V_4 >> 8 ;
case 1 :
case 0 :
* V_8 ++ = V_4 >> 0 ;
}
V_47 = V_38 - ( V_4 % V_38 ) ;
if ( V_47 > V_5 )
V_47 = V_5 ;
memcpy ( V_8 , V_3 , V_47 ) ;
V_9 = F_14 ( V_2 -> V_27 , V_39 ,
V_47 + V_2 -> V_21 + 1 ) ;
F_7 ( & V_2 -> V_27 -> V_28 ,
L_3 ,
V_47 , V_4 , ( int ) V_9 ) ;
if ( V_9 < 0 )
break;
V_45 = V_51 + F_15 ( V_52 ) ;
V_46 = 0 ;
do {
V_48 = F_16 ( V_2 -> V_27 , V_53 ) ;
if ( V_48 < 0 || ( V_48 & V_54 ) ) {
F_7 ( & V_2 -> V_27 -> V_28 ,
L_4 , V_48 , V_48 ) ;
F_17 ( 1 ) ;
continue;
}
if ( ! ( V_48 & V_54 ) )
break;
} while ( V_46 ++ < 3 || F_18 ( V_51 , V_45 ) );
if ( ( V_48 < 0 ) || ( V_48 & V_54 ) ) {
F_19 ( & V_2 -> V_27 -> V_28 ,
L_5
L_6 ,
V_47 , V_4 ,
F_20 ( V_51 -
( V_45 - V_52 ) ) ) ;
V_9 = - V_55 ;
break;
}
V_35 += V_47 ;
V_3 += V_47 ;
V_5 -= V_47 ;
V_37 += V_47 ;
} while ( V_5 > 0 );
F_8 ( & V_2 -> V_26 ) ;
F_21 ( V_39 ) ;
return V_37 ? V_37 : V_9 ;
}
static T_1
F_22 ( struct V_29 * V_30 , struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_3 , T_4 V_35 , T_2 V_5 )
{
struct V_36 * V_28 ;
struct V_1 * V_2 ;
V_28 = F_10 ( V_32 , struct V_36 , V_32 ) ;
V_2 = F_11 ( V_28 ) ;
return F_12 ( V_2 , V_3 , V_35 , V_5 ) ;
}
static T_1 F_23 ( struct V_56 * V_57 , char * V_3 ,
T_5 V_4 , T_2 V_5 )
{
struct V_1 * V_2 = F_10 ( V_57 , struct V_1 , V_57 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static T_1 F_24 ( struct V_56 * V_57 , const char * V_3 ,
T_5 V_4 , T_2 V_5 )
{
struct V_1 * V_2 = F_10 ( V_57 , struct V_1 , V_57 ) ;
return F_12 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_25 ( struct V_36 * V_28 ,
struct V_58 * V_59 ,
struct V_60 * V_18 )
{
T_6 V_61 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
strncpy ( V_18 -> V_62 , V_59 -> V_62 , sizeof( V_18 -> V_62 ) ) ;
if ( F_26 ( V_59 , L_7 , & V_61 ) == 0 ||
F_26 ( V_59 , L_8 , & V_61 ) == 0 ) {
V_18 -> V_63 = V_61 ;
} else {
F_19 ( V_28 , L_9 ) ;
return - V_64 ;
}
if ( F_26 ( V_59 , L_10 , & V_61 ) == 0 ||
F_26 ( V_59 , L_11 , & V_61 ) == 0 ) {
V_18 -> V_41 = ( V_65 ) V_61 ;
} else {
F_19 ( V_28 , L_12 ) ;
return - V_64 ;
}
if ( F_26 ( V_59 , L_13 , & V_61 ) == 0 ) {
V_18 -> V_19 = ( V_65 ) V_61 ;
} else {
if ( F_26 ( V_59 , L_14 , & V_61 ) ) {
F_19 ( V_28 ,
L_15 ) ;
return - V_64 ;
}
switch ( V_61 ) {
case 8 :
V_18 -> V_19 |= V_66 ;
break;
case 16 :
V_18 -> V_19 |= V_67 ;
break;
case 24 :
V_18 -> V_19 |= V_68 ;
break;
default:
F_19 ( V_28 ,
L_16 ,
V_61 ) ;
return - V_64 ;
}
if ( F_27 ( V_59 , L_17 , NULL ) )
V_18 -> V_19 |= V_69 ;
}
return 0 ;
}
static int F_28 ( struct V_70 * V_27 )
{
struct V_1 * V_2 = NULL ;
struct V_60 V_18 ;
struct V_58 * V_59 = V_27 -> V_28 . V_71 ;
int V_72 ;
int V_48 ;
int V_21 ;
if ( ! V_27 -> V_28 . V_73 ) {
if ( V_59 ) {
V_72 = F_25 ( & V_27 -> V_28 , V_59 , & V_18 ) ;
if ( V_72 )
return V_72 ;
} else {
F_19 ( & V_27 -> V_28 , L_18 ) ;
return - V_64 ;
}
} else
V_18 = * (struct V_60 * ) V_27 -> V_28 . V_73 ;
if ( V_18 . V_19 & V_66 )
V_21 = 1 ;
else if ( V_18 . V_19 & V_67 )
V_21 = 2 ;
else if ( V_18 . V_19 & V_68 )
V_21 = 3 ;
else {
F_7 ( & V_27 -> V_28 , L_19 ) ;
return - V_74 ;
}
V_48 = F_16 ( V_27 , V_53 ) ;
if ( V_48 < 0 || V_48 & V_54 ) {
F_7 ( & V_27 -> V_28 , L_4 , V_48 , V_48 ) ;
return - V_75 ;
}
V_2 = F_29 ( & V_27 -> V_28 , sizeof( struct V_1 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
F_30 ( & V_2 -> V_26 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_27 = F_31 ( V_27 ) ;
F_32 ( V_27 , V_2 ) ;
V_2 -> V_21 = V_21 ;
F_33 ( & V_2 -> V_15 ) ;
V_2 -> V_15 . V_76 . V_62 = L_20 ;
V_2 -> V_15 . V_76 . V_77 = V_78 ;
V_2 -> V_15 . V_79 = F_9 ;
V_2 -> V_57 . V_79 = F_23 ;
V_2 -> V_15 . V_16 = V_2 -> V_18 . V_63 ;
if ( ! ( V_18 . V_19 & V_69 ) ) {
V_2 -> V_15 . V_80 = F_22 ;
V_2 -> V_15 . V_76 . V_77 |= V_81 ;
V_2 -> V_57 . V_80 = F_24 ;
}
V_72 = F_34 ( & V_27 -> V_28 . V_32 , & V_2 -> V_15 ) ;
if ( V_72 )
return V_72 ;
if ( V_18 . V_82 )
V_18 . V_82 ( & V_2 -> V_57 , V_18 . V_83 ) ;
F_35 ( & V_27 -> V_28 , L_21 ,
( V_2 -> V_15 . V_16 < 1024 )
? V_2 -> V_15 . V_16
: ( V_2 -> V_15 . V_16 / 1024 ) ,
( V_2 -> V_15 . V_16 < 1024 ) ? L_22 : L_23 ,
V_2 -> V_18 . V_62 ,
( V_18 . V_19 & V_69 ) ? L_24 : L_25 ,
V_2 -> V_18 . V_41 ) ;
return 0 ;
}
static int F_36 ( struct V_70 * V_27 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( V_27 ) ;
F_38 ( & V_27 -> V_28 . V_32 , & V_2 -> V_15 ) ;
return 0 ;
}
