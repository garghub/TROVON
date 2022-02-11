static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
F_3 ( V_6 , V_11 ) ;
switch ( V_4 ) {
case V_12 :
F_4 ( V_9 , V_13 ) ;
F_4 ( V_10 , V_13 ) ;
V_6 -> V_14 = & V_6 -> V_15 [ V_16 ] ;
break;
default:
return - V_17 ;
}
V_9 -> V_18 . V_19 . V_20 = V_21 ;
memcpy ( V_9 -> V_18 . V_22 . V_23 , V_3 , V_4 ) ;
V_10 -> V_18 . V_19 . V_20 = V_24 ;
memcpy ( V_10 -> V_18 . V_25 . V_23 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_4 < 3 )
return - V_17 ;
V_4 -= 3 ;
memcpy ( V_6 -> V_26 . V_27 . V_28 , V_3 + V_4 , 3 ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
switch ( V_29 ) {
case 4 :
case 6 :
case 8 :
case 10 :
case 12 :
case 14 :
case 16 :
break;
default:
return - V_17 ;
}
F_7 ( V_2 ) -> V_29 = V_29 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
switch ( V_29 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_17 ;
}
F_7 ( V_2 ) -> V_29 = V_29 ;
return 0 ;
}
static int F_9 ( T_1 * V_30 , unsigned int V_31 , int V_32 )
{
T_2 V_33 ;
memset ( V_30 , 0 , V_32 ) ;
V_30 += V_32 ;
if ( V_32 >= 4 )
V_32 = 4 ;
else if ( V_31 > ( unsigned int ) ( 1 << ( 8 * V_32 ) ) )
return - V_34 ;
V_33 = F_10 ( V_31 ) ;
memcpy ( V_30 - V_32 , ( T_1 * ) & V_33 + 4 - V_32 , V_32 ) ;
return 0 ;
}
static inline int F_11 ( const T_1 * V_35 )
{
if ( 1 > V_35 [ 0 ] || V_35 [ 0 ] > 7 )
return - V_17 ;
return 0 ;
}
static int F_12 ( T_1 * V_35 , unsigned int V_36 , unsigned int V_29 ,
unsigned int V_37 , T_1 * V_38 )
{
unsigned int V_39 , V_40 , V_41 = V_29 ;
int V_42 ;
memcpy ( V_38 , V_35 , 16 ) ;
V_40 = V_38 [ 0 ] ;
V_39 = V_40 + 1 ;
* V_38 |= ( 8 * ( ( V_41 - 2 ) / 2 ) ) ;
if ( V_36 )
* V_38 |= 64 ;
V_42 = F_9 ( V_38 + 16 - V_39 , V_37 , V_39 ) ;
return V_42 ;
}
static int F_13 ( T_1 * V_35 ,
struct V_43 * V_44 ,
struct V_5 * V_6 ,
unsigned int V_29 ,
unsigned int V_45 ,
T_1 * V_46 )
{
struct V_47 * V_48 = V_6 -> V_49 ;
struct V_47 * V_50 = V_6 -> V_51 ;
unsigned int V_52 = 0 ;
T_1 V_53 [ 16 ] , * V_54 = NULL , * V_38 = NULL , * V_55 = NULL ;
int V_42 ;
unsigned int V_56 ;
memset ( V_35 + 15 - V_35 [ 0 ] , 0 , V_35 [ 0 ] + 1 ) ;
if ( ! V_44 -> V_36 ) {
V_38 = V_6 -> V_9 -> V_18 . V_22 . V_57 ;
} else if ( V_44 -> V_36 <= 14 ) {
V_38 = V_6 -> V_9 -> V_18 . V_22 . V_57 ;
V_54 = V_6 -> V_26 . V_27 . V_58 ;
V_52 = V_44 -> V_36 ;
} else if ( V_44 -> V_36 <= 65280 ) {
V_38 = V_6 -> V_10 -> V_18 . V_25 . V_38 ;
V_54 = V_6 -> V_10 -> V_18 . V_25 . V_54 ;
V_52 = 14 ;
} else {
V_38 = V_6 -> V_10 -> V_18 . V_25 . V_38 ;
V_54 = V_6 -> V_10 -> V_18 . V_25 . V_54 ;
V_52 = 10 ;
}
V_42 = F_12 ( V_35 , V_44 -> V_36 , V_29 , V_45 , V_38 ) ;
if ( V_42 )
return V_42 ;
if ( V_54 ) {
memset ( V_54 , 0 , 16 ) ;
if ( V_44 -> V_36 <= 65280 ) {
* ( V_59 * ) V_54 = ( V_59 ) V_44 -> V_36 ;
F_14 ( V_54 + 2 , V_44 -> V_60 , 0 ,
V_52 , V_61 ) ;
} else {
* ( V_59 * ) V_54 = ( V_59 ) ( 0xfffe ) ;
* ( V_62 * ) & V_54 [ 2 ] = ( V_62 ) V_44 -> V_36 ;
F_14 ( V_54 + 6 , V_44 -> V_60 , 0 ,
V_52 , V_61 ) ;
}
}
if ( ! V_44 -> V_36 ) {
return V_42 ;
} else if ( V_44 -> V_36 <= 14 ) {
unsigned int V_63 = 16 ;
V_48 = F_15 ( V_48 , V_54 , & V_63 , V_6 -> V_14 -> V_64 ) ;
if ( V_63 != 16 )
return - V_17 ;
V_50 = F_15 ( V_50 , V_53 , & V_63 ,
V_6 -> V_14 -> V_64 ) ;
if ( V_63 != 16 )
return - V_17 ;
V_6 -> V_65 . V_66 = ( V_6 -> V_49 - V_48 ) *
sizeof( struct V_47 ) ;
V_6 -> V_65 . V_67 = ( V_6 -> V_51 - V_50 ) *
sizeof( struct V_47 ) ;
F_16 ( V_6 -> V_9 ) |= V_68 ;
F_16 ( V_6 -> V_9 ) |= V_69 ;
V_55 = V_6 -> V_9 -> V_18 . V_22 . V_70 ;
V_42 = F_17 ( V_6 , & V_6 -> V_65 ,
V_44 -> V_7 . V_71 & V_72 ) ;
if ( V_42 )
return V_42 ;
F_18 ( & ( V_6 -> V_73 -> V_74 ) ) ;
F_19 ( V_44 -> V_36 , & ( V_6 -> V_73 -> V_75 ) ) ;
} else {
unsigned int V_76 = 0 , V_77 ;
V_76 += V_52 ;
V_56 = F_20 ( V_78 , V_6 -> V_14 -> V_64 ,
V_79 . V_80 . V_56 / sizeof( struct V_47 ) ) ;
V_56 = F_20 ( V_78 , V_56 ,
V_6 -> V_14 -> V_81 / V_82 ) ;
do {
V_77 = F_20 ( V_62 , V_44 -> V_36 - V_76 ,
V_6 -> V_14 -> V_81 ) ;
V_48 = F_21 ( V_6 -> V_49 ,
V_6 -> V_14 -> V_64 ,
V_44 -> V_60 , V_76 ,
& V_77 ) ;
if ( ( V_77 + V_76 ) < V_44 -> V_36 ) {
F_16 ( V_6 -> V_10 ) |=
V_69 ;
} else {
F_16 ( V_6 -> V_10 ) &=
~ V_69 ;
}
V_6 -> V_83 . V_66 = ( V_6 -> V_49 - V_48 ) *
sizeof( struct V_47 ) ;
V_55 = V_6 -> V_10 -> V_18 . V_25 . V_84 ;
V_42 = F_17 ( V_6 , & V_6 -> V_83 ,
V_44 -> V_7 . V_71 & V_72 ) ;
if ( V_42 )
return V_42 ;
memcpy ( V_6 -> V_10 -> V_18 . V_25 . V_38 ,
V_6 -> V_10 -> V_18 . V_25 . V_84 ,
V_85 ) ;
F_16 ( V_6 -> V_10 ) |= V_86 ;
F_18 ( & ( V_6 -> V_73 -> V_74 ) ) ;
F_19 ( V_44 -> V_36 ,
& ( V_6 -> V_73 -> V_75 ) ) ;
V_76 += V_77 ;
} while ( V_76 < V_44 -> V_36 );
V_55 = V_6 -> V_10 -> V_18 . V_25 . V_84 ;
}
memcpy ( V_46 , V_55 , V_85 ) ;
return V_42 ;
}
static int F_22 ( struct V_43 * V_44 ,
struct V_87 * V_88 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_45 = V_44 -> V_37 ;
unsigned int V_29 = F_23 ( F_24 ( V_44 ) ) ;
struct V_89 * V_26 = & V_6 -> V_26 . V_27 ;
unsigned long V_90 ;
unsigned int V_76 = 0 , V_77 ;
int V_42 = - 1 ;
F_25 ( & V_6 -> V_91 , V_90 ) ;
V_45 -= V_29 ;
F_14 ( V_26 -> V_92 ,
V_44 -> V_93 , V_45 , V_29 ,
V_61 ) ;
V_42 = F_13 ( V_88 -> V_94 , V_44 , V_6 , V_29 , V_45 ,
V_9 -> V_18 . V_22 . V_57 ) ;
if ( V_42 )
goto V_46;
do {
V_77 = V_45 - V_76 ;
if ( ( V_77 + V_76 ) < V_45 )
F_16 ( V_9 ) |= V_69 ;
else
F_16 ( V_9 ) &= ~ V_69 ;
F_16 ( V_6 -> V_9 ) &= ~ V_68 ;
V_42 = F_26 ( V_6 , V_88 , V_44 -> V_95 , V_44 -> V_93 ,
& V_77 , V_76 ,
V_9 -> V_18 . V_22 . V_96 ) ;
if ( V_42 )
goto V_46;
V_42 = F_17 ( V_6 , & V_6 -> V_65 ,
V_44 -> V_7 . V_71 & V_72 ) ;
if ( V_42 )
goto V_46;
memcpy ( V_88 -> V_94 , V_9 -> V_18 . V_22 . V_97 , V_85 ) ;
memcpy ( V_9 -> V_18 . V_22 . V_57 ,
V_9 -> V_18 . V_22 . V_70 , V_85 ) ;
memcpy ( V_9 -> V_18 . V_22 . V_98 ,
V_9 -> V_18 . V_22 . V_99 , V_85 ) ;
F_16 ( V_9 ) |= V_86 ;
F_18 ( & ( V_6 -> V_73 -> V_74 ) ) ;
F_19 ( V_9 -> V_100 . V_101 ,
& ( V_6 -> V_73 -> V_75 ) ) ;
V_76 += V_77 ;
} while ( V_76 < V_45 );
V_42 = memcmp ( V_9 -> V_18 . V_22 . V_70 , V_26 -> V_92 ,
V_29 ) ? - V_102 : 0 ;
V_46:
F_27 ( & V_6 -> V_91 , V_90 ) ;
return V_42 ;
}
static int F_28 ( struct V_43 * V_44 ,
struct V_87 * V_88 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_45 = V_44 -> V_37 ;
unsigned int V_29 = F_23 ( F_24 ( V_44 ) ) ;
unsigned long V_90 ;
unsigned int V_76 = 0 , V_77 ;
int V_42 = - 1 ;
F_25 ( & V_6 -> V_91 , V_90 ) ;
V_42 = F_13 ( V_88 -> V_94 , V_44 , V_6 , V_29 , V_45 ,
V_9 -> V_18 . V_22 . V_57 ) ;
if ( V_42 )
goto V_46;
do {
V_77 = V_45 - V_76 ;
if ( ( V_77 + V_76 ) < V_45 )
F_16 ( V_9 ) |= V_69 ;
else
F_16 ( V_9 ) &= ~ V_69 ;
F_16 ( V_9 ) |= V_68 ;
V_42 = F_26 ( V_6 , V_88 , V_44 -> V_95 , V_44 -> V_93 ,
& V_77 , V_76 ,
V_9 -> V_18 . V_22 . V_96 ) ;
if ( V_42 )
goto V_46;
V_42 = F_17 ( V_6 , & V_6 -> V_65 ,
V_44 -> V_7 . V_71 & V_72 ) ;
if ( V_42 )
goto V_46;
memcpy ( V_88 -> V_94 , V_9 -> V_18 . V_22 . V_97 , V_85 ) ;
memcpy ( V_9 -> V_18 . V_22 . V_57 ,
V_9 -> V_18 . V_22 . V_70 , V_85 ) ;
memcpy ( V_9 -> V_18 . V_22 . V_98 ,
V_9 -> V_18 . V_22 . V_99 , V_85 ) ;
F_16 ( V_9 ) |= V_86 ;
F_18 ( & ( V_6 -> V_73 -> V_74 ) ) ;
F_19 ( V_9 -> V_100 . V_101 ,
& ( V_6 -> V_73 -> V_75 ) ) ;
V_76 += V_77 ;
} while ( V_76 < V_45 );
F_14 ( V_9 -> V_18 . V_22 . V_70 ,
V_44 -> V_95 , V_45 , V_29 ,
V_103 ) ;
V_46:
F_27 ( & V_6 -> V_91 , V_90 ) ;
return V_42 ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_104 * V_105 = F_30 ( V_44 ) ;
struct V_87 V_88 ;
T_1 * V_35 = V_105 -> V_35 ;
V_35 [ 0 ] = 3 ;
memcpy ( V_35 + 1 , V_6 -> V_26 . V_27 . V_28 , 3 ) ;
memcpy ( V_35 + 4 , V_44 -> V_35 , 8 ) ;
V_88 . V_94 = V_35 ;
V_88 . V_2 = (struct V_106 * ) V_44 -> V_7 . V_2 ;
return F_28 ( V_44 , & V_88 ) ;
}
static int F_31 ( struct V_43 * V_44 )
{
struct V_87 V_88 ;
int V_42 ;
V_88 . V_94 = V_44 -> V_35 ;
V_88 . V_2 = (struct V_106 * ) V_44 -> V_7 . V_2 ;
V_42 = F_11 ( V_88 . V_94 ) ;
if ( V_42 )
return V_42 ;
return F_28 ( V_44 , & V_88 ) ;
}
static int F_32 ( struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_104 * V_105 = F_30 ( V_44 ) ;
struct V_87 V_88 ;
T_1 * V_35 = V_105 -> V_35 ;
V_35 [ 0 ] = 3 ;
memcpy ( V_35 + 1 , V_6 -> V_26 . V_27 . V_28 , 3 ) ;
memcpy ( V_35 + 4 , V_44 -> V_35 , 8 ) ;
V_88 . V_94 = V_35 ;
V_88 . V_2 = (struct V_106 * ) V_44 -> V_7 . V_2 ;
return F_22 ( V_44 , & V_88 ) ;
}
static int F_33 ( struct V_43 * V_44 )
{
struct V_87 V_88 ;
int V_42 ;
V_88 . V_94 = V_44 -> V_35 ;
V_88 . V_2 = (struct V_106 * ) V_44 -> V_7 . V_2 ;
V_42 = F_11 ( V_88 . V_94 ) ;
if ( V_42 )
return V_42 ;
return F_22 ( V_44 , & V_88 ) ;
}
