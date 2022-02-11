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
switch ( V_37 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_38 * V_39 ,
T_1 * V_36 )
{
int V_35 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_40 V_41 ;
struct V_42 * V_42 = V_6 -> V_43 ;
unsigned int V_44 = V_39 -> V_45 ;
unsigned int V_46 = 0 , V_47 ;
unsigned int V_48 ;
if ( V_44 <= V_49 ) {
F_8 ( & V_41 , V_39 -> V_50 ) ;
F_9 ( V_36 , & V_41 , V_44 , V_51 ) ;
F_10 ( & V_41 , V_51 , 0 ) ;
return 0 ;
}
F_11 ( V_10 ) &= ~ V_52 ;
V_48 = F_12 ( V_53 , V_54 . V_55 . V_48 / sizeof( struct V_42 ) ,
V_6 -> V_14 -> V_56 ) ;
V_48 = F_12 ( V_53 , V_48 ,
V_6 -> V_14 -> V_57 / V_58 ) ;
do {
V_47 = F_12 ( V_53 , V_44 - V_46 ,
V_6 -> V_14 -> V_57 ) ;
V_47 = F_12 ( V_53 , V_47 ,
V_58 * ( V_48 - 1 ) ) ;
V_42 = F_13 ( V_6 -> V_43 , V_48 ,
V_39 -> V_50 , V_46 , & V_47 ) ;
if ( ( V_47 + V_46 ) < V_44 )
F_11 ( V_10 ) |= V_59 ;
else
F_11 ( V_10 ) &= ~ V_59 ;
V_6 -> V_60 . V_61 = ( V_6 -> V_43 - V_42 )
* sizeof( struct V_42 ) ;
V_35 = F_14 ( V_6 , & V_6 -> V_60 ,
V_39 -> V_7 . V_62 & V_63 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_10 -> V_24 . V_31 . V_64 ,
V_10 -> V_24 . V_31 . V_65 ,
V_49 ) ;
F_11 ( V_10 ) |= V_52 ;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
F_16 ( V_39 -> V_45 , & ( V_6 -> V_66 -> V_68 ) ) ;
V_46 += V_47 ;
} while ( V_46 < V_44 );
memcpy ( V_36 , V_10 -> V_24 . V_31 . V_65 , V_49 ) ;
return V_35 ;
}
static int F_17 ( struct V_38 * V_39 , struct V_69 * V_70 )
{
int V_35 ;
struct V_5 * V_6 = F_2 ( V_39 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_42 * V_42 ;
unsigned int V_44 = V_39 -> V_45 ;
unsigned int V_46 = 0 , V_47 ;
unsigned int V_48 ;
V_9 -> V_24 . V_25 . V_26 = V_71 ;
F_11 ( V_9 ) &= ~ V_52 ;
V_48 = F_12 ( V_53 , V_54 . V_55 . V_48 / sizeof( struct V_42 ) ,
V_6 -> V_14 -> V_56 ) ;
V_48 = F_12 ( V_53 , V_48 ,
V_6 -> V_14 -> V_57 / V_58 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_72 , V_70 -> V_73 , V_49 ) ;
do {
V_47 = F_12 ( V_53 , V_44 - V_46 ,
V_6 -> V_14 -> V_57 ) ;
V_47 = F_12 ( V_53 , V_47 ,
V_58 * ( V_48 - 1 ) ) ;
V_42 = F_13 ( V_6 -> V_43 , V_48 ,
V_39 -> V_50 , V_46 , & V_47 ) ;
if ( ( V_47 + V_46 ) < V_44 )
F_11 ( V_9 ) |= V_59 ;
else
F_11 ( V_9 ) &= ~ V_59 ;
V_6 -> V_74 . V_61 = ( V_6 -> V_43 - V_42 )
* sizeof( struct V_42 ) ;
V_9 -> V_24 . V_28 . V_75 = 0 ;
V_9 -> V_24 . V_28 . V_76 = 8 * V_44 ;
V_35 = F_14 ( V_6 , & V_6 -> V_74 ,
V_39 -> V_7 . V_62 & V_63 ) ;
if ( V_35 )
goto V_36;
memcpy ( V_9 -> V_24 . V_28 . V_77 ,
V_9 -> V_24 . V_28 . V_78 , V_49 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_79 ,
V_9 -> V_24 . V_28 . V_80 , V_49 ) ;
F_11 ( V_9 ) |= V_52 ;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
F_16 ( V_39 -> V_45 , & ( V_6 -> V_66 -> V_68 ) ) ;
V_46 += V_47 ;
} while ( V_46 < V_44 );
V_36:
V_9 -> V_24 . V_25 . V_26 = V_27 ;
return V_35 ;
}
static int F_18 ( struct V_38 * V_39 , struct V_69 * V_70 ,
int V_81 )
{
int V_35 ;
struct V_5 * V_6 = F_2 ( V_39 -> V_7 . V_2 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
char V_36 [ V_49 ] ;
struct V_42 * V_43 , * V_82 ;
int V_83 ;
V_9 -> V_24 . V_25 . V_26 = V_84 ;
memcpy ( V_9 -> V_24 . V_85 . V_29 , V_9 -> V_24 . V_28 . V_29 ,
sizeof( V_9 -> V_24 . V_85 . V_29 ) ) ;
if ( V_81 )
F_11 ( V_9 ) |= V_86 ;
else
F_11 ( V_9 ) &= ~ V_86 ;
V_83 = V_49 ;
V_43 = F_19 ( V_6 -> V_43 , ( T_1 * ) V_70 -> V_73 ,
& V_83 , V_6 -> V_14 -> V_56 ) ;
if ( V_83 != V_49 )
return - V_23 ;
V_83 = sizeof( V_36 ) ;
V_82 = F_19 ( V_6 -> V_82 , ( T_1 * ) V_36 , & V_83 ,
V_6 -> V_14 -> V_56 ) ;
if ( V_83 != sizeof( V_36 ) )
return - V_23 ;
V_6 -> V_74 . V_61 = ( V_6 -> V_43 - V_43 ) * sizeof( struct V_42 ) ;
V_6 -> V_74 . V_87 = ( V_6 -> V_82 - V_82 ) * sizeof( struct V_42 ) ;
V_35 = F_14 ( V_6 , & V_6 -> V_74 ,
V_70 -> V_62 & V_63 ) ;
if ( V_35 )
goto V_36;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
memcpy ( V_9 -> V_24 . V_28 . V_78 , V_36 ,
F_20 ( F_21 ( V_39 ) ) ) ;
V_36:
V_9 -> V_24 . V_25 . V_26 = V_27 ;
memset ( V_9 -> V_24 . V_85 . V_29 , 0 , sizeof( V_9 -> V_24 . V_85 . V_29 ) ) ;
return V_35 ;
}
static int F_22 ( struct V_38 * V_39 , int V_81 )
{
struct V_5 * V_6 = F_2 ( V_39 -> V_7 . V_2 ) ;
struct V_88 * V_89 = F_23 ( V_39 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_69 V_70 ;
unsigned int V_44 = V_39 -> V_90 ;
unsigned int V_46 = 0 , V_47 ;
unsigned long V_91 ;
int V_35 = - V_23 ;
F_24 ( & V_6 -> V_92 , V_91 ) ;
V_70 . V_73 = V_89 -> V_93 ;
* ( V_94 * ) ( V_70 . V_73 + V_95 ) = 1 ;
if ( V_44 == 0 ) {
if ( V_39 -> V_45 == 0 )
V_35 = F_18 ( V_39 , & V_70 , V_81 ) ;
else
V_35 = F_17 ( V_39 , & V_70 ) ;
if ( V_35 )
goto V_36;
else
goto V_96;
}
V_9 -> V_24 . V_28 . V_76 = V_39 -> V_45 * 8 ;
if ( V_39 -> V_45 ) {
V_35 = F_7 ( V_6 , V_39 , V_9 -> V_24 . V_28 . V_77 ) ;
if ( V_35 )
goto V_36;
}
F_11 ( V_9 ) &= ~ V_52 ;
if ( V_81 ) {
F_11 ( V_9 ) |= V_86 ;
} else {
F_11 ( V_9 ) &= ~ V_86 ;
V_44 -= F_20 ( F_21 ( V_39 ) ) ;
}
do {
V_47 = V_44 - V_46 ;
V_9 -> V_24 . V_28 . V_75 = V_44 * 8 ;
V_70 . V_2 = (struct V_97 * ) V_39 -> V_7 . V_2 ;
V_35 = F_25 ( V_6 , & V_70 , V_39 -> V_98 ,
V_39 -> V_50 , & V_47 ,
V_46 + V_39 -> V_45 ,
V_9 -> V_24 . V_28 . V_72 ) ;
if ( V_35 )
goto V_36;
if ( ( V_47 + V_46 ) < V_44 )
F_11 ( V_9 ) |= V_59 ;
else
F_11 ( V_9 ) &= ~ V_59 ;
V_35 = F_14 ( V_6 , & V_6 -> V_74 ,
V_39 -> V_7 . V_62 & V_63 ) ;
if ( V_35 )
goto V_36;
memcpy ( V_70 . V_73 , V_9 -> V_24 . V_28 . V_99 , V_49 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_77 ,
V_9 -> V_24 . V_28 . V_78 , V_49 ) ;
memcpy ( V_9 -> V_24 . V_28 . V_79 ,
V_9 -> V_24 . V_28 . V_80 , V_49 ) ;
F_11 ( V_9 ) |= V_52 ;
F_15 ( & ( V_6 -> V_66 -> V_67 ) ) ;
F_16 ( V_9 -> V_100 . V_101 ,
& ( V_6 -> V_66 -> V_68 ) ) ;
V_46 += V_47 ;
} while ( V_46 < V_44 );
V_96:
if ( V_81 ) {
F_26 (
V_9 -> V_24 . V_28 . V_78 ,
V_39 -> V_98 , V_39 -> V_45 + V_44 ,
F_20 ( F_21 ( V_39 ) ) ,
V_102 ) ;
} else {
T_1 * V_103 = V_6 -> V_33 . V_34 . V_104 ;
T_1 * V_105 = V_9 -> V_24 . V_28 . V_78 ;
F_26 (
V_103 , V_39 -> V_50 , V_39 -> V_45 + V_44 ,
F_20 ( F_21 ( V_39 ) ) ,
V_51 ) ;
V_35 = memcmp ( V_103 , V_105 ,
F_20 ( F_21 ( V_39 ) ) ) ?
- V_106 : 0 ;
}
V_36:
F_27 ( & V_6 -> V_92 , V_91 ) ;
return V_35 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_88 * V_89 = F_23 ( V_39 ) ;
char * V_93 = V_89 -> V_93 ;
memcpy ( V_93 , V_39 -> V_93 , 12 ) ;
return F_22 ( V_39 , 1 ) ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_88 * V_89 = F_23 ( V_39 ) ;
char * V_93 = V_89 -> V_93 ;
memcpy ( V_93 , V_39 -> V_93 , 12 ) ;
return F_22 ( V_39 , 0 ) ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_39 -> V_7 . V_2 ) ;
struct V_88 * V_89 = F_23 ( V_39 ) ;
char * V_93 = V_89 -> V_93 ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
memcpy ( V_93 , V_32 , V_107 ) ;
memcpy ( V_93 + V_107 , V_39 -> V_93 , 8 ) ;
return F_22 ( V_39 , 1 ) ;
}
static int F_31 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_39 -> V_7 . V_2 ) ;
struct V_88 * V_89 = F_23 ( V_39 ) ;
char * V_93 = V_89 -> V_93 ;
char * V_32 = V_6 -> V_33 . V_34 . V_32 ;
memcpy ( V_93 , V_32 , V_107 ) ;
memcpy ( V_93 + V_107 , V_39 -> V_93 , 8 ) ;
return F_22 ( V_39 , 0 ) ;
}
