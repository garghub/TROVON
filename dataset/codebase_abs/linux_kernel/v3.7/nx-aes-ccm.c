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
struct V_53 * V_54 = NULL ;
T_1 V_55 [ 16 ] , * V_56 = NULL , * V_38 = NULL , * V_57 = NULL ;
int V_42 ;
memset ( V_35 + 15 - V_35 [ 0 ] , 0 , V_35 [ 0 ] + 1 ) ;
if ( ! V_44 -> V_36 ) {
V_38 = V_6 -> V_9 -> V_18 . V_22 . V_58 ;
} else if ( V_44 -> V_36 <= 14 ) {
V_38 = V_6 -> V_9 -> V_18 . V_22 . V_58 ;
V_56 = V_6 -> V_26 . V_27 . V_59 ;
V_52 = V_44 -> V_36 ;
V_48 = F_14 ( V_48 , V_56 , 16 , V_6 -> V_14 -> V_60 ) ;
V_50 = F_14 ( V_50 , V_55 , 16 ,
V_6 -> V_14 -> V_60 ) ;
V_6 -> V_54 . V_61 = ( V_6 -> V_49 - V_48 ) *
sizeof( struct V_47 ) ;
V_6 -> V_54 . V_62 = ( V_6 -> V_51 - V_50 ) *
sizeof( struct V_47 ) ;
F_15 ( V_6 -> V_9 ) |= V_63 ;
F_15 ( V_6 -> V_9 ) |= V_64 ;
V_54 = & V_6 -> V_54 ;
V_57 = V_6 -> V_9 -> V_18 . V_22 . V_65 ;
} else if ( V_44 -> V_36 <= 65280 ) {
V_38 = V_6 -> V_10 -> V_18 . V_25 . V_38 ;
V_56 = V_6 -> V_10 -> V_18 . V_25 . V_56 ;
V_52 = 14 ;
V_48 = F_16 ( V_48 , V_6 -> V_14 -> V_60 ,
V_44 -> V_66 , V_52 ,
V_44 -> V_36 - V_52 ) ;
V_6 -> V_67 . V_61 = ( V_6 -> V_49 - V_48 ) *
sizeof( struct V_47 ) ;
V_54 = & V_6 -> V_67 ;
V_57 = V_6 -> V_10 -> V_18 . V_25 . V_68 ;
} else {
F_17 ( L_1 ,
V_44 -> V_36 ) ;
V_42 = - V_17 ;
}
V_42 = F_12 ( V_35 , V_44 -> V_36 , V_29 , V_45 , V_38 ) ;
if ( V_42 )
goto V_69;
if ( V_56 ) {
memset ( V_56 , 0 , 16 ) ;
* ( V_70 * ) V_56 = ( V_70 ) V_44 -> V_36 ;
F_18 ( V_56 + 2 , V_44 -> V_66 , 0 ,
V_52 , V_71 ) ;
V_42 = F_19 ( V_6 , V_54 ,
V_44 -> V_7 . V_72 & V_73 ) ;
if ( V_42 )
goto V_69;
F_20 ( & ( V_6 -> V_74 -> V_75 ) ) ;
F_21 ( V_44 -> V_36 , & ( V_6 -> V_74 -> V_76 ) ) ;
memcpy ( V_46 , V_57 , V_77 ) ;
}
V_69:
return V_42 ;
}
static int F_22 ( struct V_43 * V_44 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_45 = V_44 -> V_37 ;
unsigned int V_29 = F_23 ( F_24 ( V_44 ) ) ;
struct V_80 * V_26 = & V_6 -> V_26 . V_27 ;
int V_42 = - 1 ;
if ( V_45 > V_6 -> V_14 -> V_81 )
return - V_17 ;
V_45 -= V_29 ;
F_18 ( V_26 -> V_82 ,
V_44 -> V_83 , V_45 , V_29 ,
V_71 ) ;
V_42 = F_13 ( V_79 -> V_84 , V_44 , V_6 , V_29 , V_45 ,
V_9 -> V_18 . V_22 . V_58 ) ;
if ( V_42 )
goto V_46;
V_42 = F_25 ( V_6 , V_79 , V_44 -> V_85 , V_44 -> V_83 , V_45 ,
V_9 -> V_18 . V_22 . V_86 ) ;
if ( V_42 )
goto V_46;
F_15 ( V_6 -> V_9 ) &= ~ V_63 ;
F_15 ( V_6 -> V_9 ) &= ~ V_64 ;
V_42 = F_19 ( V_6 , & V_6 -> V_54 ,
V_44 -> V_7 . V_72 & V_73 ) ;
if ( V_42 )
goto V_46;
F_20 ( & ( V_6 -> V_74 -> V_75 ) ) ;
F_21 ( V_9 -> V_87 . V_88 ,
& ( V_6 -> V_74 -> V_76 ) ) ;
V_42 = memcmp ( V_9 -> V_18 . V_22 . V_65 , V_26 -> V_82 ,
V_29 ) ? - V_89 : 0 ;
V_46:
return V_42 ;
}
static int F_26 ( struct V_43 * V_44 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_45 = V_44 -> V_37 ;
unsigned int V_29 = F_23 ( F_24 ( V_44 ) ) ;
int V_42 = - 1 ;
if ( V_45 > V_6 -> V_14 -> V_81 )
return - V_17 ;
V_42 = F_13 ( V_79 -> V_84 , V_44 , V_6 , V_29 , V_45 ,
V_9 -> V_18 . V_22 . V_58 ) ;
if ( V_42 )
goto V_46;
V_42 = F_25 ( V_6 , V_79 , V_44 -> V_85 , V_44 -> V_83 , V_45 ,
V_9 -> V_18 . V_22 . V_86 ) ;
if ( V_42 )
goto V_46;
F_15 ( V_9 ) |= V_63 ;
F_15 ( V_9 ) &= ~ V_64 ;
V_42 = F_19 ( V_6 , & V_6 -> V_54 ,
V_44 -> V_7 . V_72 & V_73 ) ;
if ( V_42 )
goto V_46;
F_20 ( & ( V_6 -> V_74 -> V_75 ) ) ;
F_21 ( V_9 -> V_87 . V_88 ,
& ( V_6 -> V_74 -> V_76 ) ) ;
F_18 ( V_9 -> V_18 . V_22 . V_65 ,
V_44 -> V_85 , V_45 , V_29 ,
V_90 ) ;
V_46:
return V_42 ;
}
static int F_27 ( struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_78 V_79 ;
T_1 * V_35 = V_6 -> V_26 . V_27 . V_35 ;
V_35 [ 0 ] = 3 ;
memcpy ( V_35 + 1 , V_6 -> V_26 . V_27 . V_28 , 3 ) ;
memcpy ( V_35 + 4 , V_44 -> V_35 , 8 ) ;
V_79 . V_84 = V_35 ;
V_79 . V_2 = (struct V_91 * ) V_44 -> V_7 . V_2 ;
return F_26 ( V_44 , & V_79 ) ;
}
static int F_28 ( struct V_43 * V_44 )
{
struct V_78 V_79 ;
int V_42 ;
V_79 . V_84 = V_44 -> V_35 ;
V_79 . V_2 = (struct V_91 * ) V_44 -> V_7 . V_2 ;
V_42 = F_11 ( V_79 . V_84 ) ;
if ( V_42 )
return V_42 ;
return F_26 ( V_44 , & V_79 ) ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 -> V_7 . V_2 ) ;
struct V_78 V_79 ;
T_1 * V_35 = V_6 -> V_26 . V_27 . V_35 ;
V_35 [ 0 ] = 3 ;
memcpy ( V_35 + 1 , V_6 -> V_26 . V_27 . V_28 , 3 ) ;
memcpy ( V_35 + 4 , V_44 -> V_35 , 8 ) ;
V_79 . V_84 = V_35 ;
V_79 . V_2 = (struct V_91 * ) V_44 -> V_7 . V_2 ;
return F_22 ( V_44 , & V_79 ) ;
}
static int F_30 ( struct V_43 * V_44 )
{
struct V_78 V_79 ;
int V_42 ;
V_79 . V_84 = V_44 -> V_35 ;
V_79 . V_2 = (struct V_91 * ) V_44 -> V_7 . V_2 ;
V_42 = F_11 ( V_79 . V_84 ) ;
if ( V_42 )
return V_42 ;
return F_22 ( V_44 , & V_79 ) ;
}
