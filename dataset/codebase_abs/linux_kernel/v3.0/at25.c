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
if ( F_2 ( V_4 >= V_2 -> V_14 . V_15 ) )
return 0 ;
if ( ( V_4 + V_5 ) > V_2 -> V_14 . V_15 )
V_5 = V_2 -> V_14 . V_15 - V_4 ;
if ( F_2 ( ! V_5 ) )
return V_5 ;
V_8 = V_6 ;
* V_8 ++ = V_16 ;
switch ( V_2 -> V_17 ) {
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
V_11 [ 0 ] . V_18 = V_6 ;
V_11 [ 0 ] . V_19 = V_2 -> V_17 + 1 ;
F_4 ( & V_11 [ 0 ] , & V_13 ) ;
V_11 [ 1 ] . V_20 = V_3 ;
V_11 [ 1 ] . V_19 = V_5 ;
F_4 ( & V_11 [ 1 ] , & V_13 ) ;
F_5 ( & V_2 -> V_21 ) ;
V_9 = F_6 ( V_2 -> V_22 , & V_13 ) ;
F_7 ( & V_2 -> V_22 -> V_23 ,
L_1 ,
V_5 , V_4 , ( int ) V_9 ) ;
F_8 ( & V_2 -> V_21 ) ;
return V_9 ? V_9 : V_5 ;
}
static T_1
F_9 ( struct V_24 * V_25 , struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_3 , T_4 V_30 , T_2 V_5 )
{
struct V_31 * V_23 ;
struct V_1 * V_2 ;
V_23 = F_10 ( V_27 , struct V_31 , V_27 ) ;
V_2 = F_11 ( V_23 ) ;
return F_1 ( V_2 , V_3 , V_30 , V_5 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , const char * V_3 , T_4 V_30 ,
T_2 V_5 )
{
T_1 V_9 = 0 ;
unsigned V_32 = 0 ;
unsigned V_33 ;
T_3 * V_34 ;
if ( F_2 ( V_30 >= V_2 -> V_14 . V_15 ) )
return - V_35 ;
if ( ( V_30 + V_5 ) > V_2 -> V_14 . V_15 )
V_5 = V_2 -> V_14 . V_15 - V_30 ;
if ( F_2 ( ! V_5 ) )
return V_5 ;
V_33 = V_2 -> V_36 . V_37 ;
if ( V_33 > V_38 )
V_33 = V_38 ;
V_34 = F_13 ( V_33 + V_2 -> V_17 + 1 , V_39 ) ;
if ( ! V_34 )
return - V_40 ;
V_34 [ 0 ] = V_41 ;
F_5 ( & V_2 -> V_21 ) ;
do {
unsigned long V_42 , V_43 ;
unsigned V_44 ;
unsigned V_4 = ( unsigned ) V_30 ;
T_3 * V_8 = V_34 + 1 ;
int V_45 ;
* V_8 = V_46 ;
V_9 = F_14 ( V_2 -> V_22 , V_8 , 1 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_2 -> V_22 -> V_23 , L_2 ,
( int ) V_9 ) ;
break;
}
switch ( V_2 -> V_17 ) {
default:
* V_8 ++ = V_4 >> 16 ;
case 2 :
* V_8 ++ = V_4 >> 8 ;
case 1 :
case 0 :
* V_8 ++ = V_4 >> 0 ;
}
V_44 = V_33 - ( V_4 % V_33 ) ;
if ( V_44 > V_5 )
V_44 = V_5 ;
memcpy ( V_8 , V_3 , V_44 ) ;
V_9 = F_14 ( V_2 -> V_22 , V_34 ,
V_44 + V_2 -> V_17 + 1 ) ;
F_7 ( & V_2 -> V_22 -> V_23 ,
L_3 ,
V_44 , V_4 , ( int ) V_9 ) ;
if ( V_9 < 0 )
break;
V_42 = V_47 + F_15 ( V_48 ) ;
V_43 = 0 ;
do {
V_45 = F_16 ( V_2 -> V_22 , V_49 ) ;
if ( V_45 < 0 || ( V_45 & V_50 ) ) {
F_7 ( & V_2 -> V_22 -> V_23 ,
L_4 , V_45 , V_45 ) ;
F_17 ( 1 ) ;
continue;
}
if ( ! ( V_45 & V_50 ) )
break;
} while ( V_43 ++ < 3 || F_18 ( V_47 , V_42 ) );
if ( ( V_45 < 0 ) || ( V_45 & V_50 ) ) {
F_19 ( & V_2 -> V_22 -> V_23 ,
L_5
L_6 ,
V_44 , V_4 ,
F_20 ( V_47 -
( V_42 - V_48 ) ) ) ;
V_9 = - V_51 ;
break;
}
V_30 += V_44 ;
V_3 += V_44 ;
V_5 -= V_44 ;
V_32 += V_44 ;
} while ( V_5 > 0 );
F_8 ( & V_2 -> V_21 ) ;
F_21 ( V_34 ) ;
return V_32 ? V_32 : V_9 ;
}
static T_1
F_22 ( struct V_24 * V_25 , struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_3 , T_4 V_30 , T_2 V_5 )
{
struct V_31 * V_23 ;
struct V_1 * V_2 ;
V_23 = F_10 ( V_27 , struct V_31 , V_27 ) ;
V_2 = F_11 ( V_23 ) ;
return F_12 ( V_2 , V_3 , V_30 , V_5 ) ;
}
static T_1 F_23 ( struct V_52 * V_53 , char * V_3 ,
T_5 V_4 , T_2 V_5 )
{
struct V_1 * V_2 = F_10 ( V_53 , struct V_1 , V_53 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static T_1 F_24 ( struct V_52 * V_53 , const char * V_3 ,
T_5 V_4 , T_2 V_5 )
{
struct V_1 * V_2 = F_10 ( V_53 , struct V_1 , V_53 ) ;
return F_12 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_25 ( struct V_54 * V_22 )
{
struct V_1 * V_2 = NULL ;
const struct V_55 * V_36 ;
int V_56 ;
int V_45 ;
int V_17 ;
V_36 = V_22 -> V_23 . V_57 ;
if ( ! V_36 ) {
F_7 ( & V_22 -> V_23 , L_7 ) ;
V_56 = - V_58 ;
goto V_59;
}
if ( V_36 -> V_60 & V_61 )
V_17 = 1 ;
else if ( V_36 -> V_60 & V_62 )
V_17 = 2 ;
else if ( V_36 -> V_60 & V_63 )
V_17 = 3 ;
else {
F_7 ( & V_22 -> V_23 , L_8 ) ;
V_56 = - V_64 ;
goto V_59;
}
V_45 = F_16 ( V_22 , V_49 ) ;
if ( V_45 < 0 || V_45 & V_50 ) {
F_7 ( & V_22 -> V_23 , L_4 , V_45 , V_45 ) ;
V_56 = - V_65 ;
goto V_59;
}
if ( ! ( V_2 = F_26 ( sizeof *V_2 , V_39 ) ) ) {
V_56 = - V_40 ;
goto V_59;
}
F_27 ( & V_2 -> V_21 ) ;
V_2 -> V_36 = * V_36 ;
V_2 -> V_22 = F_28 ( V_22 ) ;
F_29 ( & V_22 -> V_23 , V_2 ) ;
V_2 -> V_17 = V_17 ;
F_30 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_66 . V_67 = L_9 ;
V_2 -> V_14 . V_66 . V_68 = V_69 ;
V_2 -> V_14 . V_70 = F_9 ;
V_2 -> V_53 . V_70 = F_23 ;
V_2 -> V_14 . V_15 = V_2 -> V_36 . V_71 ;
if ( ! ( V_36 -> V_60 & V_72 ) ) {
V_2 -> V_14 . V_73 = F_22 ;
V_2 -> V_14 . V_66 . V_68 |= V_74 ;
V_2 -> V_53 . V_73 = F_24 ;
}
V_56 = F_31 ( & V_22 -> V_23 . V_27 , & V_2 -> V_14 ) ;
if ( V_56 )
goto V_59;
if ( V_36 -> V_75 )
V_36 -> V_75 ( & V_2 -> V_53 , V_36 -> V_76 ) ;
F_32 ( & V_22 -> V_23 , L_10 ,
( V_2 -> V_14 . V_15 < 1024 )
? V_2 -> V_14 . V_15
: ( V_2 -> V_14 . V_15 / 1024 ) ,
( V_2 -> V_14 . V_15 < 1024 ) ? L_11 : L_12 ,
V_2 -> V_36 . V_67 ,
( V_36 -> V_60 & V_72 ) ? L_13 : L_14 ,
V_2 -> V_36 . V_37 ) ;
return 0 ;
V_59:
F_7 ( & V_22 -> V_23 , L_15 , V_56 ) ;
F_21 ( V_2 ) ;
return V_56 ;
}
static int T_6 F_33 ( struct V_54 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( & V_22 -> V_23 ) ;
F_34 ( & V_22 -> V_23 . V_27 , & V_2 -> V_14 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int T_7 F_35 ( void )
{
return F_36 ( & V_77 ) ;
}
static void T_8 F_37 ( void )
{
F_38 ( & V_77 ) ;
}
