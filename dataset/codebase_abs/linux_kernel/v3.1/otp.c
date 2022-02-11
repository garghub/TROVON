static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
return ( int ) ( V_3 -> V_4 ) ;
}
static int F_2 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
return ( int ) V_3 -> V_5 * 2 ;
}
static T_1 F_3 ( void * V_1 , T_2 * V_6 , T_3 V_7 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_1 ;
return F_4 ( & V_6 -> V_8 [ V_7 ] ) ;
}
static T_1 F_5 ( void * V_1 , T_2 * V_6 , T_3 V_9 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_3 V_10 , V_11 , V_12 ;
T_4 V_13 , V_14 ;
V_11 = V_9 / V_3 -> V_15 ;
V_12 = V_9 % V_3 -> V_15 ;
V_13 = V_16 |
( ( V_17 << V_18 ) & V_19 ) |
( ( V_11 << V_20 ) & V_21 ) |
( ( V_12 << V_22 ) & V_23 ) ;
F_6 ( & V_6 -> V_24 , V_13 ) ;
for ( V_10 = 0 ;
( ( V_14 = F_4 ( & V_6 -> V_24 ) ) & V_16 )
&& ( V_10 < V_25 ) ; V_10 ++ )
;
if ( V_10 >= V_25 ) {
return 0xffff ;
}
if ( V_14 & V_26 ) {
return 0xffff ;
}
V_14 = ( V_14 & V_27 ) >> V_28 ;
return ( int ) V_14 ;
}
static int F_7 ( struct V_29 * V_30 , int V_31 )
{
int V_32 = 0 ;
switch ( V_30 -> V_33 ) {
case V_34 :
case V_35 :
V_32 = V_31 * 2 - V_36 - V_37 ;
break;
case V_38 :
V_32 = V_31 * 2 - V_36 - V_37 ;
break;
default:
break;
}
return V_32 ;
}
static void F_8 ( struct V_2 * V_3 , T_2 * V_6 )
{
T_3 V_10 ;
T_4 V_13 , V_14 ;
if ( V_3 -> V_30 -> V_39 == 21 || V_3 -> V_30 -> V_39 == 24
|| V_3 -> V_30 -> V_39 == 27 ) {
V_3 -> V_40 = V_41 ;
} else if ( V_3 -> V_30 -> V_39 == 36 ) {
if ( V_3 -> V_5 >= 128 )
V_3 -> V_40 = V_42 ;
else
V_3 -> V_40 = V_43 ;
} else if ( V_3 -> V_30 -> V_39 == 23 || V_3 -> V_30 -> V_39 >= 25 ) {
V_3 -> V_40 = V_42 ;
}
V_13 =
V_16 | ( ( V_44 << V_18 ) & V_19 ) ;
F_6 ( & V_6 -> V_24 , V_13 ) ;
for ( V_10 = 0 ;
( ( V_14 = F_4 ( & V_6 -> V_24 ) ) & V_16 )
&& ( V_10 < V_25 ) ; V_10 ++ )
;
if ( V_10 >= V_25 ) {
return;
}
V_3 -> V_4 = F_4 ( & V_6 -> V_45 ) ;
if ( ( V_3 -> V_30 -> V_33 == V_34 )
|| ( V_3 -> V_30 -> V_33 == V_35 ) ) {
T_4 V_46 ;
V_46 =
( F_3 ( V_3 , V_6 , V_3 -> V_40 + V_47 ) &
V_48 )
>> V_49 ;
V_3 -> V_4 |= ( V_46 << V_50 ) ;
}
V_3 -> V_51 = V_3 -> V_40 + V_52 ;
V_3 -> V_53 = V_3 -> V_5 ;
if ( V_3 -> V_4 & V_54 ) {
V_3 -> V_53 =
F_3 ( V_3 , V_6 , V_3 -> V_40 + V_55 ) / 16 ;
V_3 -> V_56 = V_3 -> V_53 ;
} else
V_3 -> V_56 = V_3 -> V_51 ;
V_3 -> V_57 = F_7 ( V_3 -> V_30 , V_3 -> V_5 ) / 2 ;
if ( V_3 -> V_4 & V_58 ) {
V_3 -> V_57 =
F_3 ( V_3 , V_6 , V_3 -> V_40 + V_59 ) / 16 ;
V_3 -> V_60 = V_3 -> V_57 ;
} else
V_3 -> V_60 = V_3 -> V_56 ;
V_3 -> V_61 = V_3 -> V_5 ;
}
static void * F_9 ( struct V_29 * V_30 )
{
T_3 V_62 ;
T_2 * V_6 ;
struct V_2 * V_3 ;
if ( ! F_10 ( V_30 -> V_39 ) )
return NULL ;
if ( F_11 ( V_30 ) )
return NULL ;
V_3 = & V_2 ;
switch ( ( V_30 -> V_63 & V_64 ) >> V_65 ) {
case 0 :
return NULL ;
case 1 :
V_3 -> V_66 = 32 ;
V_3 -> V_15 = 64 ;
V_3 -> V_5 = 128 ;
break;
case 2 :
V_3 -> V_66 = 64 ;
V_3 -> V_15 = 64 ;
V_3 -> V_5 = 256 ;
break;
case 5 :
V_3 -> V_66 = 96 ;
V_3 -> V_15 = 64 ;
V_3 -> V_5 = 384 ;
break;
case 7 :
V_3 -> V_66 = 16 ;
V_3 -> V_15 = 64 ;
V_3 -> V_5 = 64 ;
break;
default:
return NULL ;
}
V_62 = F_12 ( V_30 ) ;
V_6 = F_13 ( V_30 , V_67 ) ;
F_8 ( V_3 , V_6 ) ;
F_13 ( V_30 , V_62 ) ;
return ( void * ) V_3 ;
}
static int F_14 ( void * V_1 , int V_68 , T_1 * V_69 , T_3 * V_70 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_3 V_62 ;
T_2 * V_6 ;
T_3 V_71 , V_72 , V_73 ;
switch ( V_68 ) {
case V_74 :
V_73 = ( T_3 ) V_3 -> V_53 - V_3 -> V_51 ;
if ( ! ( V_3 -> V_4 & V_54 ) ) {
* V_70 = V_73 ;
return - V_75 ;
}
if ( * V_70 < V_73 ) {
* V_70 = V_73 ;
return - V_76 ;
}
V_71 = V_3 -> V_51 ;
break;
case V_77 :
V_73 = ( ( T_3 ) V_3 -> V_57 - V_3 -> V_56 ) ;
if ( ! ( V_3 -> V_4 & V_58 ) ) {
* V_70 = V_73 ;
return - V_75 ;
}
if ( * V_70 < V_73 ) {
* V_70 = V_73 ;
return - V_76 ;
}
V_71 = V_3 -> V_56 ;
break;
case V_78 :
V_73 = V_79 ;
if ( ! ( V_3 -> V_4 & V_80 ) ) {
* V_70 = V_73 ;
return - V_75 ;
}
if ( * V_70 < V_73 ) {
* V_70 = V_73 ;
return - V_76 ;
}
V_71 = V_3 -> V_40 + V_81 ;
break;
case V_82 :
V_73 = ( T_3 ) V_3 -> V_61 - V_3 -> V_60 ;
if ( ! ( V_3 -> V_4 & V_83 ) ) {
* V_70 = V_73 ;
return - V_75 ;
}
if ( * V_70 < V_73 ) {
* V_70 = V_73 ;
return - V_76 ;
}
V_71 = V_3 -> V_60 ;
break;
case V_84 :
V_73 = ( ( T_3 ) V_3 -> V_61 - V_3 -> V_51 ) ;
if ( ! ( V_3 -> V_4 & ( V_54 | V_58 ) ) ) {
* V_70 = V_73 ;
return - V_75 ;
}
if ( * V_70 < V_73 ) {
* V_70 = V_73 ;
return - V_76 ;
}
V_71 = V_3 -> V_51 ;
break;
default:
return - V_85 ;
}
V_62 = F_12 ( V_3 -> V_30 ) ;
V_6 = F_13 ( V_3 -> V_30 , V_67 ) ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
V_69 [ V_72 ] = F_3 ( V_1 , V_6 , V_71 + V_72 ) ;
F_13 ( V_3 -> V_30 , V_62 ) ;
* V_70 = V_73 ;
return 0 ;
}
static int F_15 ( void * V_1 , char * V_69 , T_3 * V_86 )
{
return - V_87 ;
}
int F_16 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
return V_3 -> V_88 -> V_4 ( V_1 ) ;
}
int F_17 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
return V_3 -> V_88 -> V_89 ( V_1 ) ;
}
T_1 F_18 ( void * V_1 , T_3 V_90 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_3 V_62 = F_12 ( V_3 -> V_30 ) ;
T_2 * V_6 = F_13 ( V_3 -> V_30 , V_67 ) ;
T_1 V_91 = ( T_1 ) V_3 -> V_88 -> V_92 ( V_1 , V_6 , V_90 ) ;
F_13 ( V_3 -> V_30 , V_62 ) ;
return V_91 ;
}
void * F_19 ( struct V_29 * V_30 )
{
struct V_2 * V_3 ;
void * V_32 = NULL ;
V_3 = & V_2 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_3 -> V_39 = V_30 -> V_39 ;
if ( F_10 ( V_3 -> V_39 ) )
V_3 -> V_88 = & V_93 ;
if ( V_3 -> V_88 == NULL ) {
return NULL ;
}
V_3 -> V_30 = V_30 ;
V_32 = ( V_3 -> V_88 -> V_94 ) ( V_30 ) ;
return V_32 ;
}
int
F_20 ( struct V_29 * V_30 , int V_68 , T_1 * V_69 ,
T_3 * V_70 ) {
void * V_1 ;
int V_95 = 0 ;
if ( F_11 ( V_30 ) ) {
V_95 = - V_96 ;
goto V_97;
}
V_1 = F_19 ( V_30 ) ;
if ( V_1 == NULL ) {
V_95 = - V_98 ;
goto V_97;
}
V_95 = ( ( (struct V_2 * ) V_1 ) -> V_88 -> V_99 )
( V_1 , V_68 , V_69 , V_70 ) ;
V_97:
return V_95 ;
}
int F_21 ( void * V_1 , char * V_69 , T_3 * V_86 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
return V_3 -> V_88 -> V_100 ( V_1 , V_69 , V_86 ) ;
}
