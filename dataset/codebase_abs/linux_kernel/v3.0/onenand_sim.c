static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 ) ;
V_4 = ! ( V_2 -> V_6 & V_7 ) ;
switch ( V_3 ) {
case V_8 :
case V_9 :
if ( V_4 )
F_3 ( V_10 , V_2 ) ;
else
F_3 ( V_5 | V_10 , V_2 ) ;
break;
case V_11 :
if ( V_4 )
F_3 ( V_12 , V_2 ) ;
else
F_3 ( V_5 | V_12 , V_2 ) ;
break;
case V_13 :
if ( V_4 )
F_3 ( V_14 , V_2 ) ;
else
F_3 ( V_5 | V_14 , V_2 ) ;
break;
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_15 :
F_5 ( V_16 , V_2 -> V_17 ) ;
F_5 ( V_18 , V_2 -> V_17 + 2 ) ;
F_5 ( V_19 , V_2 -> V_17 + 4 ) ;
break;
default:
break;
}
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
int V_20 = V_21 ;
switch ( V_3 ) {
case V_22 :
case V_23 :
V_20 |= V_24 ;
break;
case V_25 :
case V_26 :
V_20 |= V_27 ;
break;
case V_28 :
V_20 |= V_29 ;
break;
case V_30 :
V_20 |= V_31 ;
break;
default:
break;
}
F_5 ( V_20 , V_2 -> V_17 + V_32 ) ;
}
static int F_7 ( void * V_33 , void * V_34 , T_1 V_35 )
{
unsigned int * V_36 = ( unsigned int * ) V_34 ;
unsigned int * V_37 = ( unsigned int * ) V_33 ;
int V_38 ;
V_35 >>= 2 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ )
if ( ( * V_36 ++ ^ * V_37 ++ ) != 0 )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 ,
int V_39 , unsigned int V_40 )
{
struct V_41 * V_42 = & V_43 -> V_42 ;
struct V_44 * V_45 = V_2 -> V_46 ;
int V_47 , V_48 , V_49 = 0 ;
void T_2 * V_34 ;
void T_2 * V_33 ;
unsigned int V_38 ;
static int V_50 ;
int V_51 , V_52 ;
if ( V_39 ) {
V_47 = V_42 -> V_53 ;
V_48 = V_42 -> V_54 ;
} else {
V_47 = 0 ;
V_48 = 0 ;
}
if ( V_50 ) {
V_49 = F_9 ( V_2 -> V_17 + V_55 ) ;
V_49 >>= V_56 ;
}
switch ( V_3 ) {
case V_57 :
V_50 = 1 ;
break;
case V_30 :
V_50 = 0 ;
break;
case V_22 :
V_34 = F_10 ( V_45 ) + V_40 ;
V_33 = F_11 ( V_2 , V_47 ) ;
if ( V_50 ) {
F_5 ( V_58 [ V_49 ] , V_2 -> V_17 + V_59 ) ;
break;
}
memcpy ( V_33 , V_34 , V_42 -> V_53 ) ;
case V_23 :
V_34 = F_12 ( V_45 , V_2 , V_40 ) ;
V_33 = F_13 ( V_2 , V_48 ) ;
memcpy ( V_33 , V_34 , V_42 -> V_54 ) ;
break;
case V_25 :
V_34 = F_11 ( V_2 , V_47 ) ;
V_33 = F_10 ( V_45 ) + V_40 ;
if ( V_50 ) {
V_58 [ V_49 ] = F_9 ( V_2 -> V_17 + V_59 ) ;
break;
}
for ( V_38 = 0 ; V_38 < ( 1 << V_42 -> V_60 ) ; V_38 ++ ) {
int V_61 = V_38 * V_2 -> V_62 ;
if ( ! memcmp ( V_34 + V_61 , V_63 , V_2 -> V_62 ) )
continue;
if ( memcmp ( V_33 + V_61 , V_63 , V_2 -> V_62 ) &&
F_7 ( V_33 + V_61 , V_34 + V_61 , V_2 -> V_62 ) )
F_14 ( V_64 L_1 , V_40 ) ;
memcpy ( V_33 + V_61 , V_34 + V_61 , V_2 -> V_62 ) ;
}
case V_26 :
V_34 = F_13 ( V_2 , V_48 ) ;
if ( ! memcmp ( V_34 , V_63 , V_42 -> V_54 ) )
break;
V_33 = F_12 ( V_45 , V_2 , V_40 ) ;
if ( memcmp ( V_33 , V_63 , V_42 -> V_54 ) &&
F_7 ( V_33 , V_34 , V_42 -> V_54 ) )
F_14 ( V_64 L_2 ,
V_40 ) ;
memcpy ( V_33 , V_34 , V_42 -> V_54 ) ;
break;
case V_28 :
if ( V_50 )
break;
if ( F_15 ( V_2 ) ) {
V_52 = F_16 ( V_42 , V_40 ) ;
V_51 = V_42 -> V_65 [ V_52 ] . V_51 ;
} else
V_51 = V_42 -> V_51 ;
memset ( F_10 ( V_45 ) + V_40 , 0xff , V_51 ) ;
memset ( F_12 ( V_45 , V_2 , V_40 ) , 0xff ,
( V_51 >> 5 ) ) ;
break;
default:
break;
}
}
static void F_17 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_40 = 0 ;
int V_66 = - 1 , V_67 = - 1 , V_68 = - 1 ;
int V_39 = 0 ;
switch ( V_3 ) {
case V_8 :
case V_11 :
case V_13 :
case V_9 :
F_1 ( V_2 , V_3 ) ;
break;
case V_69 :
return;
default:
V_66 = ( int ) F_9 ( V_2 -> V_17 + V_70 ) ;
if ( V_66 & ( 1 << V_56 ) ) {
V_66 &= ~ ( 1 << V_56 ) ;
V_66 += V_2 -> V_71 >> ( V_2 -> V_72 + 1 ) ;
}
if ( V_3 == V_28 )
break;
V_67 = ( int ) F_9 ( V_2 -> V_17 + V_73 ) ;
V_67 = ( V_67 >> V_74 ) ;
V_68 = ( int ) F_9 ( V_2 -> V_17 + V_75 ) ;
V_68 >>= V_76 ;
V_68 &= V_77 ;
V_39 = ( V_68 == V_77 ) ? 1 : 0 ;
break;
}
if ( V_66 != - 1 )
V_40 = F_18 ( V_2 , V_66 ) ;
if ( V_67 != - 1 )
V_40 += V_67 << V_2 -> V_78 ;
F_8 ( V_2 , V_3 , V_39 , V_40 ) ;
F_6 ( V_2 , V_3 ) ;
}
static void F_19 ( unsigned short V_79 , void T_2 * V_80 )
{
struct V_1 * V_2 = V_43 -> V_42 . V_46 ;
if ( V_80 < V_2 -> V_17 + V_59 ) {
F_4 ( V_2 , V_79 ) ;
return;
}
if ( V_80 == V_2 -> V_17 + V_81 )
F_17 ( V_2 , V_79 ) ;
F_5 ( V_79 , V_80 ) ;
}
static int T_3 F_20 ( struct V_44 * V_45 )
{
int V_82 , V_83 ;
int V_84 ;
V_45 -> V_17 = F_21 ( 131072 , V_85 ) ;
if ( ! V_45 -> V_17 ) {
F_14 ( V_64 L_3 ) ;
return - V_86 ;
}
V_82 = V_18 >> V_87 ;
V_82 &= V_88 ;
V_83 = ( ( 16 << 20 ) << V_82 ) ;
F_10 ( V_45 ) = F_22 ( V_83 + ( V_83 >> 5 ) ) ;
if ( ! F_10 ( V_45 ) ) {
F_14 ( V_64 L_4 ) ;
F_23 ( V_45 -> V_17 ) ;
return - V_86 ;
}
memset ( F_10 ( V_45 ) , 0xff , V_83 + ( V_83 >> 5 ) ) ;
F_5 ( V_16 , V_45 -> V_17 + V_89 ) ;
F_5 ( V_18 , V_45 -> V_17 + V_90 ) ;
F_5 ( V_19 , V_45 -> V_17 + V_91 ) ;
F_5 ( V_92 , V_45 -> V_17 + V_93 ) ;
if ( V_82 < 2 && ( ! V_94 ) )
V_84 = 0x0400 ;
else
V_84 = 0x0800 ;
F_5 ( V_84 , V_45 -> V_17 + V_95 ) ;
return 0 ;
}
static void F_24 ( struct V_44 * V_45 )
{
F_25 ( F_10 ( V_45 ) ) ;
F_23 ( V_45 -> V_17 ) ;
}
static int T_3 F_26 ( void )
{
V_63 = F_27 ( V_96 , V_85 ) ;
if ( ! V_63 ) {
F_14 ( V_64 L_5 ) ;
return - V_86 ;
}
memset ( V_63 , 0xff , V_96 ) ;
V_43 = F_21 ( sizeof( struct V_97 ) , V_85 ) ;
if ( ! V_43 ) {
F_14 ( V_64 L_6 ) ;
F_23 ( V_63 ) ;
return - V_86 ;
}
V_43 -> V_98 . V_99 = F_19 ;
if ( F_20 ( & V_43 -> V_45 ) ) {
F_14 ( V_64 L_7 ) ;
F_23 ( V_63 ) ;
F_23 ( V_43 ) ;
return - V_86 ;
}
V_43 -> V_100 = V_101 ;
V_43 -> V_98 . V_17 = V_43 -> V_45 . V_17 ;
V_43 -> V_98 . V_46 = & V_43 -> V_45 ;
V_43 -> V_42 . V_102 = L_8 ;
V_43 -> V_42 . V_46 = & V_43 -> V_98 ;
V_43 -> V_42 . V_103 = V_104 ;
if ( F_28 ( & V_43 -> V_42 , 1 ) ) {
F_24 ( & V_43 -> V_45 ) ;
F_23 ( V_63 ) ;
F_23 ( V_43 ) ;
return - V_105 ;
}
F_29 ( & V_43 -> V_42 , V_43 -> V_100 ,
F_30 ( V_101 ) ) ;
return 0 ;
}
static void T_4 F_31 ( void )
{
struct V_1 * V_2 = V_43 -> V_42 . V_46 ;
struct V_44 * V_45 = V_2 -> V_46 ;
F_32 ( & V_43 -> V_42 ) ;
F_24 ( V_45 ) ;
F_23 ( V_63 ) ;
F_23 ( V_43 ) ;
}
