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
if ( V_2 -> V_15 . V_18 & V_19 )
if ( V_4 >= ( 1U << ( V_2 -> V_20 * 8 ) ) )
V_14 |= V_21 ;
* V_8 ++ = V_14 ;
switch ( V_2 -> V_20 ) {
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
V_11 [ 0 ] . V_22 = V_6 ;
V_11 [ 0 ] . V_23 = V_2 -> V_20 + 1 ;
F_4 ( & V_11 [ 0 ] , & V_13 ) ;
V_11 [ 1 ] . V_24 = V_3 ;
V_11 [ 1 ] . V_23 = V_5 ;
F_4 ( & V_11 [ 1 ] , & V_13 ) ;
F_5 ( & V_2 -> V_25 ) ;
V_9 = F_6 ( V_2 -> V_26 , & V_13 ) ;
F_7 ( & V_2 -> V_26 -> V_27 ,
L_1 ,
V_5 , V_4 , ( int ) V_9 ) ;
F_8 ( & V_2 -> V_25 ) ;
return V_9 ? V_9 : V_5 ;
}
static int F_9 ( void * V_28 , const void * V_29 , T_2 V_30 ,
void * V_31 , T_2 V_32 )
{
struct V_1 * V_2 = V_28 ;
T_4 V_4 = * ( V_33 * ) V_29 ;
int V_34 ;
V_34 = F_1 ( V_2 , V_31 , V_4 , V_32 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
static T_1
F_10 ( struct V_1 * V_2 , const char * V_3 , T_5 V_35 ,
T_2 V_5 )
{
T_1 V_9 = 0 ;
unsigned V_36 = 0 ;
unsigned V_37 ;
T_3 * V_38 ;
if ( F_2 ( V_35 >= V_2 -> V_15 . V_16 ) )
return - V_39 ;
if ( ( V_35 + V_5 ) > V_2 -> V_15 . V_16 )
V_5 = V_2 -> V_15 . V_16 - V_35 ;
if ( F_2 ( ! V_5 ) )
return V_5 ;
V_37 = V_2 -> V_15 . V_40 ;
if ( V_37 > V_41 )
V_37 = V_41 ;
V_38 = F_11 ( V_37 + V_2 -> V_20 + 1 , V_42 ) ;
if ( ! V_38 )
return - V_43 ;
F_5 ( & V_2 -> V_25 ) ;
do {
unsigned long V_44 , V_45 ;
unsigned V_46 ;
unsigned V_4 = ( unsigned ) V_35 ;
T_3 * V_8 = V_38 ;
int V_47 ;
T_3 V_14 ;
* V_8 = V_48 ;
V_9 = F_12 ( V_2 -> V_26 , V_8 , 1 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_2 -> V_26 -> V_27 , L_2 ,
( int ) V_9 ) ;
break;
}
V_14 = V_49 ;
if ( V_2 -> V_15 . V_18 & V_19 )
if ( V_4 >= ( 1U << ( V_2 -> V_20 * 8 ) ) )
V_14 |= V_21 ;
* V_8 ++ = V_14 ;
switch ( V_2 -> V_20 ) {
default:
* V_8 ++ = V_4 >> 16 ;
case 2 :
* V_8 ++ = V_4 >> 8 ;
case 1 :
case 0 :
* V_8 ++ = V_4 >> 0 ;
}
V_46 = V_37 - ( V_4 % V_37 ) ;
if ( V_46 > V_5 )
V_46 = V_5 ;
memcpy ( V_8 , V_3 , V_46 ) ;
V_9 = F_12 ( V_2 -> V_26 , V_38 ,
V_46 + V_2 -> V_20 + 1 ) ;
F_7 ( & V_2 -> V_26 -> V_27 ,
L_3 ,
V_46 , V_4 , ( int ) V_9 ) ;
if ( V_9 < 0 )
break;
V_44 = V_50 + F_13 ( V_51 ) ;
V_45 = 0 ;
do {
V_47 = F_14 ( V_2 -> V_26 , V_52 ) ;
if ( V_47 < 0 || ( V_47 & V_53 ) ) {
F_7 ( & V_2 -> V_26 -> V_27 ,
L_4 , V_47 , V_47 ) ;
F_15 ( 1 ) ;
continue;
}
if ( ! ( V_47 & V_53 ) )
break;
} while ( V_45 ++ < 3 || F_16 ( V_50 , V_44 ) );
if ( ( V_47 < 0 ) || ( V_47 & V_53 ) ) {
F_17 ( & V_2 -> V_26 -> V_27 ,
L_5
L_6 ,
V_46 , V_4 ,
F_18 ( V_50 -
( V_44 - V_51 ) ) ) ;
V_9 = - V_54 ;
break;
}
V_35 += V_46 ;
V_3 += V_46 ;
V_5 -= V_46 ;
V_36 += V_46 ;
} while ( V_5 > 0 );
F_8 ( & V_2 -> V_25 ) ;
F_19 ( V_38 ) ;
return V_36 ? V_36 : V_9 ;
}
static int F_20 ( void * V_28 , const void * V_55 , T_2 V_5 )
{
struct V_1 * V_2 = V_28 ;
const char * V_3 ;
V_33 V_4 ;
T_2 V_23 ;
int V_34 ;
memcpy ( & V_4 , V_55 , sizeof( V_4 ) ) ;
V_3 = ( const char * ) V_55 + sizeof( V_4 ) ;
V_23 = V_5 - sizeof( V_4 ) ;
V_34 = F_10 ( V_2 , V_3 , V_4 , V_23 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
static int F_21 ( struct V_56 * V_27 , struct V_57 * V_15 )
{
V_33 V_31 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
strncpy ( V_15 -> V_58 , L_7 , sizeof( V_15 -> V_58 ) ) ;
if ( F_22 ( V_27 , L_8 , & V_31 ) == 0 ||
F_22 ( V_27 , L_9 , & V_31 ) == 0 ) {
V_15 -> V_16 = V_31 ;
} else {
F_17 ( V_27 , L_10 ) ;
return - V_59 ;
}
if ( F_22 ( V_27 , L_11 , & V_31 ) == 0 ||
F_22 ( V_27 , L_12 , & V_31 ) == 0 ) {
V_15 -> V_40 = ( V_60 ) V_31 ;
} else {
F_17 ( V_27 , L_13 ) ;
return - V_59 ;
}
if ( F_22 ( V_27 , L_14 , & V_31 ) == 0 ) {
V_15 -> V_18 = ( V_60 ) V_31 ;
} else {
if ( F_22 ( V_27 , L_15 , & V_31 ) ) {
F_17 ( V_27 ,
L_16 ) ;
return - V_59 ;
}
switch ( V_31 ) {
case 8 :
V_15 -> V_18 |= V_61 ;
break;
case 16 :
V_15 -> V_18 |= V_62 ;
break;
case 24 :
V_15 -> V_18 |= V_63 ;
break;
default:
F_17 ( V_27 ,
L_17 ,
V_31 ) ;
return - V_59 ;
}
if ( F_23 ( V_27 , L_18 ) )
V_15 -> V_18 |= V_64 ;
}
return 0 ;
}
static int F_24 ( struct V_65 * V_26 )
{
struct V_1 * V_2 = NULL ;
struct V_57 V_15 ;
struct V_66 * V_66 ;
int V_34 ;
int V_47 ;
int V_20 ;
if ( ! V_26 -> V_27 . V_67 ) {
V_34 = F_21 ( & V_26 -> V_27 , & V_15 ) ;
if ( V_34 )
return V_34 ;
} else
V_15 = * (struct V_57 * ) V_26 -> V_27 . V_67 ;
if ( V_15 . V_18 & V_61 )
V_20 = 1 ;
else if ( V_15 . V_18 & V_62 )
V_20 = 2 ;
else if ( V_15 . V_18 & V_63 )
V_20 = 3 ;
else {
F_7 ( & V_26 -> V_27 , L_19 ) ;
return - V_68 ;
}
V_47 = F_14 ( V_26 , V_52 ) ;
if ( V_47 < 0 || V_47 & V_53 ) {
F_7 ( & V_26 -> V_27 , L_4 , V_47 , V_47 ) ;
return - V_69 ;
}
V_2 = F_25 ( & V_26 -> V_27 , sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
F_26 ( & V_2 -> V_25 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_26 = F_27 ( V_26 ) ;
F_28 ( V_26 , V_2 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_70 . V_71 = 32 ;
V_2 -> V_70 . V_72 = 8 ;
V_2 -> V_70 . V_73 = 1 ;
V_2 -> V_70 . V_74 = V_15 . V_16 - 1 ;
V_66 = F_29 ( & V_26 -> V_27 , & V_75 , V_2 ,
& V_2 -> V_70 ) ;
if ( F_30 ( V_66 ) ) {
F_17 ( & V_26 -> V_27 , L_20 ) ;
return F_31 ( V_66 ) ;
}
V_2 -> V_76 . V_58 = F_32 ( & V_26 -> V_27 ) ;
V_2 -> V_76 . V_27 = & V_26 -> V_27 ;
V_2 -> V_76 . V_77 = V_15 . V_18 & V_64 ;
V_2 -> V_76 . V_78 = true ;
V_2 -> V_76 . V_79 = V_80 ;
V_2 -> V_76 . V_81 = true ;
V_2 -> V_76 . V_82 = & V_26 -> V_27 ;
V_2 -> V_83 = F_33 ( & V_2 -> V_76 ) ;
if ( F_30 ( V_2 -> V_83 ) )
return F_31 ( V_2 -> V_83 ) ;
F_34 ( & V_26 -> V_27 , L_21 ,
( V_15 . V_16 < 1024 )
? V_15 . V_16
: ( V_15 . V_16 / 1024 ) ,
( V_15 . V_16 < 1024 ) ? L_22 : L_23 ,
V_2 -> V_15 . V_58 ,
( V_15 . V_18 & V_64 ) ? L_24 : L_25 ,
V_2 -> V_15 . V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_65 * V_26 )
{
struct V_1 * V_2 ;
V_2 = F_36 ( V_26 ) ;
F_37 ( V_2 -> V_83 ) ;
return 0 ;
}
