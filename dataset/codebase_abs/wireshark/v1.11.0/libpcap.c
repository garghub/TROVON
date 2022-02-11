int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
struct V_6 V_7 ;
T_4 V_8 ;
T_4 V_9 ;
T_4 V_10 ;
int V_11 ;
T_5 V_12 ;
T_6 * V_13 ;
V_14 = V_15 ;
V_4 = F_2 ( & V_5 , sizeof V_5 , V_1 -> V_16 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_3 ( V_1 -> V_16 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_17 )
return - 1 ;
return 0 ;
}
switch ( V_5 ) {
case V_18 :
V_8 = FALSE ;
V_9 = FALSE ;
V_1 -> V_19 = V_20 ;
break;
case V_21 :
V_8 = FALSE ;
V_9 = TRUE ;
V_1 -> V_19 = V_20 ;
break;
case V_22 :
V_8 = TRUE ;
V_9 = FALSE ;
V_1 -> V_19 = V_20 ;
break;
case V_23 :
V_8 = TRUE ;
V_9 = TRUE ;
V_1 -> V_19 = V_20 ;
break;
case V_24 :
V_8 = FALSE ;
V_9 = FALSE ;
V_1 -> V_19 = V_25 ;
break;
case V_26 :
V_8 = TRUE ;
V_9 = FALSE ;
V_1 -> V_19 = V_25 ;
break;
default:
return 0 ;
}
V_14 = V_15 ;
V_4 = F_2 ( & V_7 , sizeof V_7 , V_1 -> V_16 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_3 ( V_1 -> V_16 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_17 ;
return - 1 ;
}
if ( V_8 ) {
V_7 . V_27 = F_4 ( V_7 . V_27 ) ;
V_7 . V_28 = F_4 ( V_7 . V_28 ) ;
V_7 . V_29 = F_5 ( V_7 . V_29 ) ;
V_7 . V_30 = F_5 ( V_7 . V_30 ) ;
}
if ( V_7 . V_27 < 2 ) {
* V_2 = V_31 ;
* V_3 = F_6 ( L_1 ,
V_7 . V_27 ) ;
return - 1 ;
}
V_10 = FALSE ;
if ( V_7 . V_27 == 2 && V_7 . V_28 == 2 ) {
switch ( V_7 . V_30 ) {
case 6 :
V_7 . V_30 = 1 ;
V_10 = TRUE ;
break;
case 9 :
V_7 . V_30 = 6 ;
V_10 = TRUE ;
break;
case 15 :
V_7 . V_30 = 10 ;
V_10 = TRUE ;
break;
case 24 :
V_7 . V_30 = 0 ;
V_10 = TRUE ;
break;
}
}
V_11 = F_7 ( V_7 . V_30 ) ;
if ( V_11 == V_32 ) {
* V_2 = V_33 ;
* V_3 = F_6 ( L_2 ,
V_7 . V_30 ) ;
return - 1 ;
}
V_13 = ( T_6 * ) F_8 ( sizeof( T_6 ) ) ;
V_13 -> V_8 = V_8 ;
V_13 -> V_27 = V_7 . V_27 ;
V_13 -> V_28 = V_7 . V_28 ;
V_1 -> V_34 = ( void * ) V_13 ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_39 = V_7 . V_29 ;
switch ( V_7 . V_27 ) {
case 2 :
if ( V_7 . V_28 < 3 )
V_13 -> V_40 = V_41 ;
else if ( V_7 . V_28 == 3 )
V_13 -> V_40 = V_42 ;
else
V_13 -> V_40 = V_43 ;
break;
case 543 :
V_13 -> V_40 = V_41 ;
break;
default:
V_13 -> V_40 = V_43 ;
break;
}
if ( V_10 ) {
V_1 -> V_44 = V_45 ;
V_1 -> V_19 = V_25 ;
return 1 ;
}
if ( V_9 ) {
V_1 -> V_44 = V_46 ;
V_12 = F_9 ( V_1 -> V_16 ) ;
switch ( F_10 ( V_1 , V_2 ) ) {
case V_47 :
return - 1 ;
case V_48 :
if ( F_11 ( V_1 -> V_16 , V_12 , V_49 , V_2 ) == - 1 ) {
return - 1 ;
}
goto V_50;
case V_51 :
break;
}
V_1 -> V_44 = V_52 ;
if ( F_11 ( V_1 -> V_16 , V_12 , V_49 , V_2 ) == - 1 ) {
return - 1 ;
}
} else {
if( V_1 -> V_19 == V_25 ) {
V_1 -> V_44 = V_53 ;
} else {
V_1 -> V_44 = V_54 ;
}
V_12 = F_9 ( V_1 -> V_16 ) ;
switch ( F_10 ( V_1 , V_2 ) ) {
case V_47 :
return - 1 ;
case V_48 :
if ( F_11 ( V_1 -> V_16 , V_12 , V_49 , V_2 ) == - 1 ) {
return - 1 ;
}
goto V_50;
case V_51 :
break;
}
V_1 -> V_44 = V_55 ;
if ( F_11 ( V_1 -> V_16 , V_12 , V_49 , V_2 ) == - 1 ) {
return - 1 ;
}
switch ( F_10 ( V_1 , V_2 ) ) {
case V_47 :
return - 1 ;
case V_48 :
if ( F_11 ( V_1 -> V_16 , V_12 , V_49 , V_2 ) == - 1 ) {
return - 1 ;
}
goto V_50;
case V_51 :
break;
}
V_1 -> V_44 = V_56 ;
if ( F_11 ( V_1 -> V_16 , V_12 , V_49 , V_2 ) == - 1 ) {
return - 1 ;
}
}
V_50:
if ( V_1 -> V_44 == V_56 && V_7 . V_30 == 13 )
V_1 -> V_11 = V_57 ;
if ( V_1 -> V_11 == V_58 ) {
F_12 ( V_1 ) ;
}
return 1 ;
}
static T_7 F_10 ( T_1 * V_1 , int * V_2 )
{
struct V_59 V_60 , V_61 ;
if ( F_13 ( V_1 , V_1 -> V_16 , V_2 , NULL , & V_60 ) == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_17 ) {
return V_48 ;
}
if ( * V_2 == V_62 ) {
return V_48 ;
}
return V_47 ;
}
if ( F_11 ( V_1 -> V_16 , V_60 . V_7 . V_63 , V_64 , V_2 ) == - 1 )
return V_47 ;
if ( F_13 ( V_1 , V_1 -> V_16 , V_2 , NULL , & V_61 ) == - 1 ) {
if ( * V_2 == 0 || * V_2 == V_17 ) {
return V_48 ;
}
if ( * V_2 == V_62 ) {
return V_51 ;
}
return V_47 ;
}
return V_48 ;
}
static T_4 V_36 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_65 )
{
* V_65 = F_9 ( V_1 -> V_16 ) ;
return F_14 ( V_1 , V_1 -> V_16 , & V_1 -> V_66 ,
V_1 -> V_67 , V_2 , V_3 ) ;
}
static T_4
V_38 ( T_1 * V_1 , T_5 V_68 , struct V_69 * V_66 ,
T_8 * V_70 , int T_9 V_71 , int * V_2 , T_2 * * V_3 )
{
if ( F_11 ( V_1 -> V_72 , V_68 , V_49 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_14 ( V_1 , V_1 -> V_72 , V_66 , V_70 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_17 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_14 ( T_1 * V_1 , T_10 V_16 , struct V_69 * V_66 ,
T_8 * V_70 , int * V_2 , T_2 * * V_3 )
{
struct V_59 V_7 ;
T_11 V_73 ;
T_11 V_74 ;
int V_4 ;
int V_75 ;
T_6 * V_13 ;
V_4 = F_13 ( V_1 , V_16 , V_2 , V_3 , & V_7 ) ;
if ( V_4 == - 1 ) {
return FALSE ;
}
V_73 = V_7 . V_7 . V_63 ;
V_74 = V_7 . V_7 . V_76 ;
if ( V_1 -> V_44 == V_45 &&
( V_1 -> V_11 == V_77 ||
V_1 -> V_11 == V_78 ) ) {
V_73 -= 3 ;
V_74 -= 3 ;
if ( ! F_15 ( V_16 , 3 , V_2 ) )
return FALSE ;
}
V_75 = F_16 ( V_16 , V_1 -> V_44 ,
V_1 -> V_11 , V_73 , TRUE , V_66 , V_2 , V_3 ) ;
if ( V_75 < 0 )
return FALSE ;
V_74 -= V_75 ;
V_73 -= V_75 ;
V_66 -> V_79 = V_80 | V_81 ;
if ( V_1 -> V_11 != V_58 ) {
V_66 -> V_82 . V_83 = V_7 . V_7 . V_84 ;
if ( V_1 -> V_19 == V_25 )
V_66 -> V_82 . V_85 = V_7 . V_7 . V_86 ;
else
V_66 -> V_82 . V_85 = V_7 . V_7 . V_86 * 1000 ;
} else {
V_66 -> V_79 |= V_87 ;
V_66 -> V_88 = V_66 -> V_89 . erf . V_66 . V_90 & 0x03 ;
}
V_66 -> V_91 = V_73 ;
V_66 -> V_92 = V_74 ;
if ( ! F_17 ( V_16 , V_70 , V_73 , V_2 , V_3 ) )
return FALSE ;
V_13 = ( T_6 * ) V_1 -> V_34 ;
F_18 ( V_1 -> V_44 , V_1 -> V_11 ,
& V_66 -> V_89 , F_19 ( V_70 ) , V_73 ,
V_13 -> V_8 , - 1 ) ;
return TRUE ;
}
static int F_13 ( T_1 * V_1 , T_10 V_16 , int * V_2 , T_2 * * V_3 ,
struct V_59 * V_7 )
{
int V_93 , V_4 ;
V_14 = V_15 ;
switch ( V_1 -> V_44 ) {
case V_54 :
case V_45 :
case V_53 :
V_93 = sizeof ( struct V_94 ) ;
break;
case V_55 :
case V_46 :
V_93 = sizeof ( struct V_95 ) ;
break;
case V_52 :
V_93 = sizeof ( struct V_59 ) ;
break;
case V_56 :
V_93 = sizeof ( struct V_96 ) ;
break;
default:
F_20 () ;
V_93 = 0 ;
}
V_4 = F_2 ( V_7 , V_93 , V_16 ) ;
if ( V_4 != V_93 ) {
* V_2 = F_3 ( V_16 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_17 ;
}
return - 1 ;
}
F_21 ( V_1 , & V_7 -> V_7 ) ;
if ( V_7 -> V_7 . V_63 > V_97 ) {
* V_2 = V_62 ;
if ( V_3 != NULL ) {
* V_3 = F_6 ( L_3 ,
V_7 -> V_7 . V_63 , V_97 ) ;
}
return - 1 ;
}
#if 0
if (hdr->hdr.incl_len > wth->snapshot_length) {
g_warning("pcap: File has packet larger than file's snapshot length.");
}
#endif
return V_4 ;
}
static void
F_21 ( T_1 * V_1 , struct V_94 * V_7 )
{
T_3 V_98 ;
T_6 * V_13 ;
V_13 = ( T_6 * ) V_1 -> V_34 ;
if ( V_13 -> V_8 ) {
V_7 -> V_84 = F_5 ( V_7 -> V_84 ) ;
V_7 -> V_86 = F_5 ( V_7 -> V_86 ) ;
V_7 -> V_63 = F_5 ( V_7 -> V_63 ) ;
V_7 -> V_76 = F_5 ( V_7 -> V_76 ) ;
}
switch ( V_13 -> V_40 ) {
case V_43 :
break;
case V_42 :
if ( V_7 -> V_63 <= V_7 -> V_76 ) {
break;
}
case V_41 :
V_98 = V_7 -> V_76 ;
V_7 -> V_76 = V_7 -> V_63 ;
V_7 -> V_63 = V_98 ;
break;
}
}
int F_22 ( int V_99 )
{
if ( V_99 == V_100 )
return V_101 ;
if ( F_23 ( V_99 ) == - 1 )
return V_33 ;
return 0 ;
}
T_4 F_24 ( T_12 * V_102 , int * V_2 )
{
T_3 V_5 ;
struct V_6 V_103 ;
V_102 -> V_104 = V_105 ;
V_102 -> V_106 = NULL ;
switch ( V_102 -> V_44 ) {
case V_54 :
case V_55 :
case V_56 :
V_5 = V_18 ;
V_102 -> V_19 = V_20 ;
break;
case V_52 :
case V_46 :
V_5 = V_21 ;
V_102 -> V_19 = V_20 ;
break;
case V_53 :
V_5 = V_24 ;
V_102 -> V_19 = V_25 ;
break;
default:
* V_2 = V_107 ;
return FALSE ;
}
if ( ! F_25 ( V_102 , & V_5 , sizeof V_5 , V_2 ) )
return FALSE ;
V_102 -> V_108 += sizeof V_5 ;
V_103 . V_27 = 2 ;
V_103 . V_28 = 4 ;
V_103 . V_109 = 0 ;
V_103 . V_110 = 0 ;
V_103 . V_29 = ( V_102 -> V_29 != 0 ) ? V_102 -> V_29 :
V_97 ;
V_103 . V_30 = F_23 ( V_102 -> V_99 ) ;
if ( ! F_25 ( V_102 , & V_103 , sizeof V_103 , V_2 ) )
return FALSE ;
V_102 -> V_108 += sizeof V_103 ;
return TRUE ;
}
static T_4 V_105 ( T_12 * V_102 ,
const struct V_69 * V_66 ,
const T_13 * V_111 , int * V_2 )
{
const union V_112 * V_89 = & V_66 -> V_89 ;
struct V_59 V_113 ;
T_14 V_114 ;
int V_115 ;
V_115 = F_26 ( V_102 -> V_99 , V_89 ) ;
V_113 . V_7 . V_84 = ( T_3 ) V_66 -> V_82 . V_83 ;
if( V_102 -> V_19 == V_25 ) {
V_113 . V_7 . V_86 = V_66 -> V_82 . V_85 ;
} else {
V_113 . V_7 . V_86 = V_66 -> V_82 . V_85 / 1000 ;
}
V_113 . V_7 . V_63 = V_66 -> V_91 + V_115 ;
V_113 . V_7 . V_76 = V_66 -> V_92 + V_115 ;
if ( V_113 . V_7 . V_63 > V_97 ) {
* V_2 = V_62 ;
return FALSE ;
}
switch ( V_102 -> V_44 ) {
case V_54 :
case V_53 :
V_114 = sizeof ( struct V_94 ) ;
break;
case V_55 :
case V_46 :
V_113 . V_116 = 0 ;
V_113 . V_117 = 0 ;
V_113 . V_118 = 0 ;
V_114 = sizeof ( struct V_95 ) ;
break;
case V_52 :
V_113 . V_116 = 0 ;
V_113 . V_117 = 0 ;
V_113 . V_118 = 0 ;
V_113 . V_119 = 0 ;
V_113 . V_120 = 0 ;
V_114 = sizeof ( struct V_59 ) ;
break;
case V_56 :
memcpy ( & V_113 . V_116 , V_89 -> V_121 . V_122 , 4 ) ;
V_113 . V_117 = 0 ;
V_113 . V_118 = 0 ;
V_113 . V_119 = 0 ;
V_113 . V_120 = 0 ;
V_114 = sizeof ( struct V_96 ) ;
break;
default:
F_20 () ;
* V_2 = V_107 ;
return FALSE ;
}
if ( ! F_25 ( V_102 , & V_113 , V_114 , V_2 ) )
return FALSE ;
V_102 -> V_108 += V_114 ;
if ( ! F_27 ( V_102 , V_102 -> V_99 , V_89 , V_2 ) )
return FALSE ;
if ( ! F_25 ( V_102 , V_111 , V_66 -> V_91 , V_2 ) )
return FALSE ;
V_102 -> V_108 += V_66 -> V_91 ;
return TRUE ;
}
