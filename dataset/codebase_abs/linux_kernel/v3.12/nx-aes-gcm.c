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
case V_17 :
F_4 ( V_9 , V_18 ) ;
F_4 ( V_10 , V_18 ) ;
V_6 -> V_14 = & V_6 -> V_15 [ V_19 ] ;
break;
case V_20 :
F_4 ( V_9 , V_21 ) ;
F_4 ( V_10 , V_21 ) ;
V_6 -> V_14 = & V_6 -> V_15 [ V_22 ] ;
break;
default:
return - V_23 ;
}
V_9 -> V_24 . V_25 . V_26 = V_27 ;
memcpy ( V_9 -> V_24 . V_28 . V_29 , V_3 , V_4 ) ;
V_10 -> V_24 . V_25 . V_26 = V_30 ;
memcpy ( V_10 -> V_24 . V_31 . V_29 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
int V_35 ;
if ( V_4 < 4 )
return - V_23 ;
V_4 -= 4 ;
V_35 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_35 )
goto V_36;
memcpy ( V_32 , V_3 + V_4 , 4 ) ;
V_36:
return V_35 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
if ( V_37 > F_7 ( V_2 ) -> V_38 )
return - V_23 ;
F_8 ( V_2 ) -> V_37 = V_37 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
switch ( V_37 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_23 ;
}
F_8 ( V_2 ) -> V_37 = V_37 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_39 * V_40 ,
T_1 * V_36 )
{
int V_35 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_41 V_42 ;
struct V_43 * V_43 = V_6 -> V_44 ;
unsigned int V_45 = V_40 -> V_46 ;
unsigned int V_47 = 0 , V_48 ;
T_2 V_49 ;
if ( V_45 <= V_50 ) {
F_11 ( & V_42 , V_40 -> V_51 ) ;
F_12 ( V_36 , & V_42 , V_45 , V_52 ) ;
F_13 ( & V_42 , V_52 , 0 ) ;
return 0 ;
}
F_14 ( V_10 ) &= ~ V_53 ;
V_49 = F_15 ( T_2 , V_54 . V_55 . V_49 / sizeof( struct V_43 ) ,
V_6 -> V_14 -> V_56 ) ;
do {
V_48 = F_15 ( V_57 , V_45 - V_47 ,
V_6 -> V_14 -> V_58 ) ;
V_48 = F_15 ( V_57 , V_48 ,
V_59 * ( V_49 - 1 ) ) ;
if ( ( V_48 + V_47 ) < V_45 )
F_14 ( V_10 ) |= V_60 ;
else
F_14 ( V_10 ) &= ~ V_60 ;
V_43 = F_16 ( V_6 -> V_44 , V_6 -> V_14 -> V_56 ,
V_40 -> V_51 , V_47 , V_48 ) ;
V_6 -> V_61 . V_62 = ( V_6 -> V_44 - V_43 )
* sizeof( struct V_43 ) ;
V_35 = F_17 ( V_6 , & V_6 -> V_61 ,
V_40 -> V_7 . V_63 & V_64 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_10 -> V_24 . V_31 . V_65 ,
V_10 -> V_24 . V_31 . V_66 ,
V_50 ) ;
F_14 ( V_10 ) |= V_53 ;
F_18 ( & ( V_6 -> V_67 -> V_68 ) ) ;
F_19 ( V_40 -> V_46 , & ( V_6 -> V_67 -> V_69 ) ) ;
V_47 += V_48 ;
} while ( V_47 < V_45 );
memcpy ( V_36 , V_10 -> V_24 . V_31 . V_66 , V_50 ) ;
return V_35 ;
}
static int F_20 ( struct V_39 * V_40 , struct V_70 * V_71 )
{
int V_35 ;
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_43 * V_43 ;
unsigned int V_45 = V_40 -> V_46 ;
unsigned int V_47 = 0 , V_48 ;
T_2 V_49 ;
V_9 -> V_24 . V_25 . V_26 = V_72 ;
F_14 ( V_9 ) &= ~ V_53 ;
V_49 = F_15 ( T_2 , V_54 . V_55 . V_49 / sizeof( struct V_43 ) ,
V_6 -> V_14 -> V_56 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_73 , V_71 -> V_74 , V_50 ) ;
do {
V_48 = F_15 ( V_57 , V_45 - V_47 ,
V_6 -> V_14 -> V_58 ) ;
V_48 = F_15 ( V_57 , V_48 ,
V_59 * ( V_49 - 1 ) ) ;
if ( ( V_48 + V_47 ) < V_45 )
F_14 ( V_9 ) |= V_60 ;
else
F_14 ( V_9 ) &= ~ V_60 ;
V_43 = F_16 ( V_6 -> V_44 , V_6 -> V_14 -> V_56 ,
V_40 -> V_51 , V_47 , V_48 ) ;
V_6 -> V_75 . V_62 = ( V_6 -> V_44 - V_43 )
* sizeof( struct V_43 ) ;
V_9 -> V_24 . V_28 . V_76 = 0 ;
V_9 -> V_24 . V_28 . V_77 = 8 * V_45 ;
V_35 = F_17 ( V_6 , & V_6 -> V_75 ,
V_40 -> V_7 . V_63 & V_64 ) ;
if ( V_35 )
goto V_36;
memcpy ( V_9 -> V_24 . V_28 . V_78 ,
V_9 -> V_24 . V_28 . V_79 , V_50 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_80 ,
V_9 -> V_24 . V_28 . V_81 , V_50 ) ;
F_14 ( V_9 ) |= V_53 ;
F_18 ( & ( V_6 -> V_67 -> V_68 ) ) ;
F_19 ( V_40 -> V_46 , & ( V_6 -> V_67 -> V_69 ) ) ;
V_47 += V_48 ;
} while ( V_47 < V_45 );
V_36:
V_9 -> V_24 . V_25 . V_26 = V_27 ;
return V_35 ;
}
static int F_21 ( struct V_39 * V_40 , struct V_70 * V_71 ,
int V_82 )
{
int V_35 ;
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
char V_36 [ V_50 ] ;
struct V_43 * V_44 , * V_83 ;
V_9 -> V_24 . V_25 . V_26 = V_84 ;
memcpy ( V_9 -> V_24 . V_85 . V_29 , V_9 -> V_24 . V_28 . V_29 ,
sizeof( V_9 -> V_24 . V_85 . V_29 ) ) ;
if ( V_82 )
F_14 ( V_9 ) |= V_86 ;
else
F_14 ( V_9 ) &= ~ V_86 ;
V_44 = F_22 ( V_6 -> V_44 , ( T_1 * ) V_71 -> V_74 ,
V_50 , V_6 -> V_14 -> V_56 ) ;
V_83 = F_22 ( V_6 -> V_83 , ( T_1 * ) V_36 , sizeof( V_36 ) ,
V_6 -> V_14 -> V_56 ) ;
V_6 -> V_75 . V_62 = ( V_6 -> V_44 - V_44 ) * sizeof( struct V_43 ) ;
V_6 -> V_75 . V_87 = ( V_6 -> V_83 - V_83 ) * sizeof( struct V_43 ) ;
V_35 = F_17 ( V_6 , & V_6 -> V_75 ,
V_71 -> V_63 & V_64 ) ;
if ( V_35 )
goto V_36;
F_18 ( & ( V_6 -> V_67 -> V_68 ) ) ;
memcpy ( V_9 -> V_24 . V_28 . V_79 , V_36 ,
F_23 ( F_24 ( V_40 ) ) ) ;
V_36:
V_9 -> V_24 . V_25 . V_26 = V_27 ;
memset ( V_9 -> V_24 . V_85 . V_29 , 0 , sizeof( V_9 -> V_24 . V_85 . V_29 ) ) ;
return V_35 ;
}
static int F_25 ( struct V_39 * V_40 , int V_82 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_70 V_71 ;
unsigned int V_45 = V_40 -> V_88 ;
unsigned int V_47 = 0 , V_48 ;
unsigned long V_89 ;
T_2 V_49 ;
int V_35 = - V_23 ;
F_26 ( & V_6 -> V_90 , V_89 ) ;
V_71 . V_74 = V_6 -> V_33 . V_34 . V_91 ;
* ( T_2 * ) ( V_71 . V_74 + V_92 ) = 1 ;
if ( V_45 == 0 ) {
if ( V_40 -> V_46 == 0 )
V_35 = F_21 ( V_40 , & V_71 , V_82 ) ;
else
V_35 = F_20 ( V_40 , & V_71 ) ;
if ( V_35 )
goto V_36;
else
goto V_93;
}
V_9 -> V_24 . V_28 . V_77 = V_40 -> V_46 * 8 ;
if ( V_40 -> V_46 ) {
V_35 = F_10 ( V_6 , V_40 , V_9 -> V_24 . V_28 . V_78 ) ;
if ( V_35 )
goto V_36;
}
F_14 ( V_9 ) &= ~ V_53 ;
if ( V_82 ) {
F_14 ( V_9 ) |= V_86 ;
} else {
F_14 ( V_9 ) &= ~ V_86 ;
V_45 -= F_23 ( F_24 ( V_40 ) ) ;
}
V_49 = F_15 ( T_2 , V_54 . V_55 . V_49 / sizeof( struct V_43 ) ,
V_6 -> V_14 -> V_56 ) ;
do {
V_48 = F_15 ( V_57 , V_45 - V_47 ,
V_6 -> V_14 -> V_58 ) ;
V_48 = F_15 ( V_57 , V_48 ,
V_59 * ( V_49 - 1 ) ) ;
if ( ( V_48 + V_47 ) < V_45 )
F_14 ( V_9 ) |= V_60 ;
else
F_14 ( V_9 ) &= ~ V_60 ;
V_9 -> V_24 . V_28 . V_76 = V_45 * 8 ;
V_71 . V_2 = (struct V_94 * ) V_40 -> V_7 . V_2 ;
V_35 = F_27 ( V_6 , & V_71 , V_40 -> V_95 ,
V_40 -> V_96 , V_48 , V_47 ,
V_9 -> V_24 . V_28 . V_73 ) ;
if ( V_35 )
goto V_36;
V_35 = F_17 ( V_6 , & V_6 -> V_75 ,
V_40 -> V_7 . V_63 & V_64 ) ;
if ( V_35 )
goto V_36;
memcpy ( V_71 . V_74 , V_9 -> V_24 . V_28 . V_97 , V_50 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_78 ,
V_9 -> V_24 . V_28 . V_79 , V_50 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_80 ,
V_9 -> V_24 . V_28 . V_81 , V_50 ) ;
F_14 ( V_9 ) |= V_53 ;
F_18 ( & ( V_6 -> V_67 -> V_68 ) ) ;
F_19 ( V_9 -> V_98 . V_99 ,
& ( V_6 -> V_67 -> V_69 ) ) ;
V_47 += V_48 ;
} while ( V_47 < V_45 );
V_93:
if ( V_82 ) {
F_28 ( V_9 -> V_24 . V_28 . V_79 ,
V_40 -> V_95 , V_45 ,
F_23 ( F_24 ( V_40 ) ) ,
V_100 ) ;
} else {
T_1 * V_101 = V_6 -> V_33 . V_34 . V_102 ;
T_1 * V_103 = V_9 -> V_24 . V_28 . V_79 ;
F_28 ( V_101 , V_40 -> V_96 , V_45 ,
F_23 ( F_24 ( V_40 ) ) ,
V_52 ) ;
V_35 = memcmp ( V_101 , V_103 ,
F_23 ( F_24 ( V_40 ) ) ) ?
- V_104 : 0 ;
}
V_36:
F_29 ( & V_6 -> V_90 , V_89 ) ;
return V_35 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_91 = V_6 -> V_33 . V_34 . V_91 ;
memcpy ( V_91 , V_40 -> V_91 , 12 ) ;
return F_25 ( V_40 , 1 ) ;
}
static int F_31 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_91 = V_6 -> V_33 . V_34 . V_91 ;
memcpy ( V_91 , V_40 -> V_91 , 12 ) ;
return F_25 ( V_40 , 0 ) ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_91 = V_6 -> V_33 . V_34 . V_91 ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
memcpy ( V_91 , V_32 , V_105 ) ;
memcpy ( V_91 + V_105 , V_40 -> V_91 , 8 ) ;
return F_25 ( V_40 , 1 ) ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_40 -> V_7 . V_2 ) ;
char * V_91 = V_6 -> V_33 . V_34 . V_91 ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
memcpy ( V_91 , V_32 , V_105 ) ;
memcpy ( V_91 + V_105 , V_40 -> V_91 , 8 ) ;
return F_25 ( V_40 , 0 ) ;
}
