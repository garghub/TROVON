static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned * V_4 )
{
unsigned V_5 ;
if ( V_3 -> V_6 . V_7 & V_8 ) {
V_5 = * V_4 >> 16 ;
* V_4 &= 0xffff ;
} else {
V_5 = * V_4 >> 8 ;
* V_4 &= 0xff ;
}
return V_3 -> V_9 [ V_5 ] ;
}
static T_1 F_2 ( struct V_2 * V_3 , char * V_10 ,
unsigned V_4 , T_2 V_11 )
{
struct V_12 V_13 [ 2 ] ;
T_3 V_14 [ 2 ] ;
struct V_1 * V_9 ;
unsigned long V_15 , V_16 ;
int V_17 , V_5 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_18 )
V_11 = V_18 ;
switch ( V_3 -> V_19 ) {
case V_20 :
if ( V_11 > V_21 )
V_11 = V_21 ;
break;
case V_22 :
V_11 = 2 ;
break;
case V_23 :
V_11 = 1 ;
break;
default:
V_5 = 0 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_14 [ V_5 ++ ] = V_4 >> 8 ;
V_14 [ V_5 ++ ] = V_4 ;
V_13 [ 0 ] . V_24 = V_9 -> V_24 ;
V_13 [ 0 ] . V_10 = V_14 ;
V_13 [ 0 ] . V_25 = V_5 ;
V_13 [ 1 ] . V_24 = V_9 -> V_24 ;
V_13 [ 1 ] . V_7 = V_26 ;
V_13 [ 1 ] . V_10 = V_10 ;
V_13 [ 1 ] . V_25 = V_11 ;
}
V_15 = V_27 + F_3 ( V_28 ) ;
do {
V_16 = V_27 ;
switch ( V_3 -> V_19 ) {
case V_20 :
V_17 = F_4 ( V_9 , V_4 ,
V_11 , V_10 ) ;
break;
case V_22 :
V_17 = F_5 ( V_9 , V_4 ) ;
if ( V_17 >= 0 ) {
V_10 [ 0 ] = V_17 & 0xff ;
V_10 [ 1 ] = V_17 >> 8 ;
V_17 = V_11 ;
}
break;
case V_23 :
V_17 = F_6 ( V_9 , V_4 ) ;
if ( V_17 >= 0 ) {
V_10 [ 0 ] = V_17 ;
V_17 = V_11 ;
}
break;
default:
V_17 = F_7 ( V_9 -> V_29 , V_13 , 2 ) ;
if ( V_17 == 2 )
V_17 = V_11 ;
}
F_8 ( & V_9 -> V_30 , L_1 ,
V_11 , V_4 , V_17 , V_27 ) ;
if ( V_17 == V_11 )
return V_11 ;
F_9 ( 1 ) ;
} while ( F_10 ( V_16 , V_15 ) );
return - V_31 ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
char * V_10 , T_4 V_32 , T_2 V_11 )
{
T_1 V_33 = 0 ;
if ( F_12 ( ! V_11 ) )
return V_11 ;
F_13 ( & V_3 -> V_34 ) ;
while ( V_11 ) {
T_1 V_17 ;
V_17 = F_2 ( V_3 , V_10 , V_32 , V_11 ) ;
if ( V_17 <= 0 ) {
if ( V_33 == 0 )
V_33 = V_17 ;
break;
}
V_10 += V_17 ;
V_32 += V_17 ;
V_11 -= V_17 ;
V_33 += V_17 ;
}
F_14 ( & V_3 -> V_34 ) ;
return V_33 ;
}
static T_1 F_15 ( struct V_35 * V_36 , struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_10 , T_4 V_32 , T_2 V_11 )
{
struct V_2 * V_3 ;
V_3 = F_16 ( F_17 ( V_38 , struct V_41 , V_38 ) ) ;
return F_11 ( V_3 , V_10 , V_32 , V_11 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 , const char * V_10 ,
unsigned V_4 , T_2 V_11 )
{
struct V_1 * V_9 ;
struct V_12 V_13 ;
T_1 V_17 ;
unsigned long V_15 , V_42 ;
unsigned V_43 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_3 -> V_44 )
V_11 = V_3 -> V_44 ;
V_43 = F_19 ( V_4 + 1 , V_3 -> V_6 . V_45 ) ;
if ( V_4 + V_11 > V_43 )
V_11 = V_43 - V_4 ;
if ( ! V_3 -> V_19 ) {
int V_5 = 0 ;
V_13 . V_24 = V_9 -> V_24 ;
V_13 . V_7 = 0 ;
V_13 . V_10 = V_3 -> V_46 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_13 . V_10 [ V_5 ++ ] = V_4 >> 8 ;
V_13 . V_10 [ V_5 ++ ] = V_4 ;
memcpy ( & V_13 . V_10 [ V_5 ] , V_10 , V_11 ) ;
V_13 . V_25 = V_5 + V_11 ;
}
V_15 = V_27 + F_3 ( V_28 ) ;
do {
V_42 = V_27 ;
if ( V_3 -> V_19 ) {
V_17 = F_20 ( V_9 ,
V_4 , V_11 , V_10 ) ;
if ( V_17 == 0 )
V_17 = V_11 ;
} else {
V_17 = F_7 ( V_9 -> V_29 , & V_13 , 1 ) ;
if ( V_17 == 1 )
V_17 = V_11 ;
}
F_8 ( & V_9 -> V_30 , L_2 ,
V_11 , V_4 , V_17 , V_27 ) ;
if ( V_17 == V_11 )
return V_11 ;
F_9 ( 1 ) ;
} while ( F_10 ( V_42 , V_15 ) );
return - V_31 ;
}
static T_1 F_21 ( struct V_2 * V_3 , const char * V_10 , T_4 V_32 ,
T_2 V_11 )
{
T_1 V_33 = 0 ;
if ( F_12 ( ! V_11 ) )
return V_11 ;
F_13 ( & V_3 -> V_34 ) ;
while ( V_11 ) {
T_1 V_17 ;
V_17 = F_18 ( V_3 , V_10 , V_32 , V_11 ) ;
if ( V_17 <= 0 ) {
if ( V_33 == 0 )
V_33 = V_17 ;
break;
}
V_10 += V_17 ;
V_32 += V_17 ;
V_11 -= V_17 ;
V_33 += V_17 ;
}
F_14 ( & V_3 -> V_34 ) ;
return V_33 ;
}
static T_1 F_22 ( struct V_35 * V_36 , struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_10 , T_4 V_32 , T_2 V_11 )
{
struct V_2 * V_3 ;
V_3 = F_16 ( F_17 ( V_38 , struct V_41 , V_38 ) ) ;
return F_21 ( V_3 , V_10 , V_32 , V_11 ) ;
}
static T_1 F_23 ( struct V_47 * V_48 , char * V_10 ,
T_5 V_4 , T_2 V_11 )
{
struct V_2 * V_3 = F_17 ( V_48 , struct V_2 , V_48 ) ;
return F_11 ( V_3 , V_10 , V_4 , V_11 ) ;
}
static T_1 F_24 ( struct V_47 * V_48 , const char * V_10 ,
T_5 V_4 , T_2 V_11 )
{
struct V_2 * V_3 = F_17 ( V_48 , struct V_2 , V_48 ) ;
return F_21 ( V_3 , V_10 , V_4 , V_11 ) ;
}
static void F_25 ( struct V_1 * V_9 ,
struct V_49 * V_6 )
{
const T_6 * V_50 ;
struct V_51 * V_52 = V_9 -> V_30 . V_53 ;
if ( V_52 ) {
if ( F_26 ( V_52 , L_3 , NULL ) )
V_6 -> V_7 |= V_54 ;
V_50 = F_26 ( V_52 , L_4 , NULL ) ;
if ( V_50 )
V_6 -> V_45 = F_27 ( V_50 ) ;
}
}
static void F_25 ( struct V_1 * V_9 ,
struct V_49 * V_6 )
{ }
static int F_28 ( struct V_1 * V_9 , const struct V_55 * V_56 )
{
struct V_49 V_6 ;
bool V_57 ;
int V_19 = 0 ;
struct V_2 * V_3 ;
int V_58 ;
unsigned V_5 , V_59 ;
T_7 V_60 ;
if ( V_9 -> V_30 . V_61 ) {
V_6 = * (struct V_49 * ) V_9 -> V_30 . V_61 ;
} else {
if ( ! V_56 -> V_62 )
return - V_63 ;
V_60 = V_56 -> V_62 ;
V_6 . V_64 = F_29 ( V_60 & F_30 ( V_65 ) ) ;
V_60 >>= V_65 ;
V_6 . V_7 = V_60 & F_30 ( V_66 ) ;
V_6 . V_45 = 1 ;
F_25 ( V_9 , & V_6 ) ;
V_6 . V_67 = NULL ;
V_6 . V_68 = NULL ;
}
if ( ! F_31 ( V_6 . V_64 ) )
F_32 ( & V_9 -> V_30 ,
L_5 ) ;
if ( ! V_6 . V_45 ) {
F_33 ( & V_9 -> V_30 , L_6 ) ;
return - V_69 ;
}
if ( ! F_31 ( V_6 . V_45 ) )
F_32 ( & V_9 -> V_30 ,
L_7 ) ;
if ( ! F_34 ( V_9 -> V_29 , V_70 ) ) {
if ( V_6 . V_7 & V_8 )
return - V_71 ;
if ( F_34 ( V_9 -> V_29 ,
V_72 ) ) {
V_19 = V_20 ;
} else if ( F_34 ( V_9 -> V_29 ,
V_73 ) ) {
V_19 = V_22 ;
} else if ( F_34 ( V_9 -> V_29 ,
V_74 ) ) {
V_19 = V_23 ;
} else {
return - V_71 ;
}
}
if ( V_6 . V_7 & V_75 )
V_59 = 8 ;
else
V_59 = F_35 ( V_6 . V_64 ,
( V_6 . V_7 & V_8 ) ? 65536 : 256 ) ;
V_3 = F_36 ( & V_9 -> V_30 , sizeof( struct V_2 ) +
V_59 * sizeof( struct V_1 * ) , V_76 ) ;
if ( ! V_3 )
return - V_77 ;
F_37 ( & V_3 -> V_34 ) ;
V_3 -> V_19 = V_19 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_59 = V_59 ;
F_38 ( & V_3 -> V_78 ) ;
V_3 -> V_78 . V_40 . V_79 = L_8 ;
V_3 -> V_78 . V_40 . V_80 = V_6 . V_7 & V_81 ? V_82 : V_83 ;
V_3 -> V_78 . V_84 = F_15 ;
V_3 -> V_78 . V_85 = V_6 . V_64 ;
V_3 -> V_48 . V_84 = F_23 ;
V_57 = ! ( V_6 . V_7 & V_54 ) ;
if ( V_57 ) {
if ( ! V_19 || F_34 ( V_9 -> V_29 ,
V_86 ) ) {
unsigned V_44 = V_6 . V_45 ;
V_3 -> V_48 . V_87 = F_24 ;
V_3 -> V_78 . V_87 = F_22 ;
V_3 -> V_78 . V_40 . V_80 |= V_88 ;
if ( V_44 > V_18 )
V_44 = V_18 ;
if ( V_19 && V_44 > V_21 )
V_44 = V_21 ;
V_3 -> V_44 = V_44 ;
V_3 -> V_46 = F_36 ( & V_9 -> V_30 ,
V_44 + 2 , V_76 ) ;
if ( ! V_3 -> V_46 )
return - V_77 ;
} else {
F_32 ( & V_9 -> V_30 ,
L_9 ) ;
}
}
V_3 -> V_9 [ 0 ] = V_9 ;
for ( V_5 = 1 ; V_5 < V_59 ; V_5 ++ ) {
V_3 -> V_9 [ V_5 ] = F_39 ( V_9 -> V_29 ,
V_9 -> V_24 + V_5 ) ;
if ( ! V_3 -> V_9 [ V_5 ] ) {
F_33 ( & V_9 -> V_30 , L_10 ,
V_9 -> V_24 + V_5 ) ;
V_58 = - V_89 ;
goto V_90;
}
}
V_58 = F_40 ( & V_9 -> V_30 . V_38 , & V_3 -> V_78 ) ;
if ( V_58 )
goto V_90;
F_41 ( V_9 , V_3 ) ;
F_42 ( & V_9 -> V_30 , L_11 ,
V_3 -> V_78 . V_85 , V_9 -> V_79 ,
V_57 ? L_12 : L_3 , V_3 -> V_44 ) ;
if ( V_19 == V_22 ||
V_19 == V_23 ) {
F_43 ( & V_9 -> V_30 , L_13
L_14 , V_19 ==
V_22 ? L_15 : L_16 ) ;
}
if ( V_6 . V_67 )
V_6 . V_67 ( & V_3 -> V_48 , V_6 . V_68 ) ;
return 0 ;
V_90:
for ( V_5 = 1 ; V_5 < V_59 ; V_5 ++ )
if ( V_3 -> V_9 [ V_5 ] )
F_44 ( V_3 -> V_9 [ V_5 ] ) ;
return V_58 ;
}
static int F_45 ( struct V_1 * V_9 )
{
struct V_2 * V_3 ;
int V_5 ;
V_3 = F_46 ( V_9 ) ;
F_47 ( & V_9 -> V_30 . V_38 , & V_3 -> V_78 ) ;
for ( V_5 = 1 ; V_5 < V_3 -> V_59 ; V_5 ++ )
F_44 ( V_3 -> V_9 [ V_5 ] ) ;
return 0 ;
}
static int T_8 F_48 ( void )
{
if ( ! V_18 ) {
F_49 ( L_17 ) ;
return - V_69 ;
}
V_18 = F_50 ( V_18 ) ;
return F_51 ( & V_91 ) ;
}
static void T_9 F_52 ( void )
{
F_53 ( & V_91 ) ;
}
