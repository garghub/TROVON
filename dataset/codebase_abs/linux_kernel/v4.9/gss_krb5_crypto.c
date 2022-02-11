T_1
F_1 (
struct V_1 * V_2 ,
void * V_3 ,
void * V_4 ,
void * V_5 ,
int V_6 )
{
T_1 V_7 = - V_8 ;
struct V_9 V_10 [ 1 ] ;
T_2 V_11 [ V_12 ] = { 0 } ;
F_2 ( V_13 , V_2 ) ;
if ( V_6 % F_3 ( V_2 ) != 0 )
goto V_5;
if ( F_4 ( V_2 ) > V_12 ) {
F_5 ( L_1 ,
F_4 ( V_2 ) ) ;
goto V_5;
}
if ( V_3 )
memcpy ( V_11 , V_3 , F_4 ( V_2 ) ) ;
memcpy ( V_5 , V_4 , V_6 ) ;
F_6 ( V_10 , V_5 , V_6 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_9 ( V_13 , V_10 , V_10 , V_6 , V_11 ) ;
V_7 = F_10 ( V_13 ) ;
F_11 ( V_13 ) ;
V_5:
F_5 ( L_2 , V_7 ) ;
return V_7 ;
}
T_1
F_12 (
struct V_1 * V_2 ,
void * V_3 ,
void * V_4 ,
void * V_5 ,
int V_6 )
{
T_1 V_7 = - V_8 ;
struct V_9 V_10 [ 1 ] ;
T_2 V_11 [ V_12 ] = { 0 } ;
F_2 ( V_13 , V_2 ) ;
if ( V_6 % F_3 ( V_2 ) != 0 )
goto V_5;
if ( F_4 ( V_2 ) > V_12 ) {
F_5 ( L_3 ,
F_4 ( V_2 ) ) ;
goto V_5;
}
if ( V_3 )
memcpy ( V_11 , V_3 , F_4 ( V_2 ) ) ;
memcpy ( V_5 , V_4 , V_6 ) ;
F_6 ( V_10 , V_5 , V_6 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_9 ( V_13 , V_10 , V_10 , V_6 , V_11 ) ;
V_7 = F_13 ( V_13 ) ;
F_11 ( V_13 ) ;
V_5:
F_5 ( L_4 , V_7 ) ;
return V_7 ;
}
static int
F_14 ( struct V_9 * V_10 , void * V_14 )
{
struct V_15 * V_13 = V_14 ;
F_15 ( V_13 , V_10 , NULL , V_10 -> V_6 ) ;
return F_16 ( V_13 ) ;
}
static int
F_17 ( unsigned int V_16 , T_2 V_17 [ 4 ] )
{
unsigned int V_18 ;
switch ( V_16 ) {
case V_19 :
V_18 = 15 ;
break;
case V_20 :
V_18 = 13 ;
break;
default:
return - V_8 ;
}
V_17 [ 0 ] = ( V_18 >> 0 ) & 0xff ;
V_17 [ 1 ] = ( V_18 >> 8 ) & 0xff ;
V_17 [ 2 ] = ( V_18 >> 16 ) & 0xff ;
V_17 [ 3 ] = ( V_18 >> 24 ) & 0xff ;
return 0 ;
}
static T_1
F_18 ( struct V_21 * V_22 , char * V_23 , int V_24 ,
struct V_25 * V_26 , int V_27 , T_2 * V_28 ,
unsigned int V_16 , struct V_29 * V_30 )
{
struct V_9 V_10 [ 1 ] ;
int V_31 = - 1 ;
T_2 * V_32 ;
T_2 V_33 [ 4 ] ;
struct V_34 * V_35 ;
struct V_34 * V_36 ;
struct V_15 * V_13 ;
if ( V_28 == NULL )
return V_37 ;
if ( V_30 -> V_38 < V_22 -> V_39 -> V_40 ) {
F_5 ( L_5 ,
V_41 , V_30 -> V_38 , V_22 -> V_39 -> V_42 ) ;
return V_37 ;
}
if ( F_17 ( V_16 , V_33 ) ) {
F_5 ( L_6 , V_41 , V_16 ) ;
return V_37 ;
}
V_32 = F_19 ( V_43 , V_44 ) ;
if ( ! V_32 )
return V_37 ;
V_35 = F_20 ( L_7 , 0 , V_45 ) ;
if ( F_21 ( V_35 ) )
goto V_46;
V_36 = F_20 ( V_22 -> V_39 -> V_47 , 0 ,
V_45 ) ;
if ( F_21 ( V_36 ) )
goto V_48;
V_13 = F_22 ( V_35 , V_49 ) ;
if ( ! V_13 )
goto V_50;
F_23 ( V_13 , V_51 , NULL , NULL ) ;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_33 , 4 ) ;
F_15 ( V_13 , V_10 , NULL , 4 ) ;
V_31 = F_16 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_23 , V_24 ) ;
F_15 ( V_13 , V_10 , NULL , V_24 ) ;
V_31 = F_16 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_25 ( V_26 , V_27 , V_26 -> V_38 - V_27 ,
F_14 , V_13 ) ;
if ( V_31 )
goto V_5;
F_15 ( V_13 , NULL , V_32 , 0 ) ;
V_31 = F_26 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_27 ( V_13 ) ;
V_13 = F_22 ( V_36 , V_49 ) ;
if ( ! V_13 )
goto V_50;
F_23 ( V_13 , V_51 , NULL , NULL ) ;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_28 ( V_36 , V_28 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_32 , F_29 ( V_35 ) ) ;
F_15 ( V_13 , V_10 , V_32 ,
F_29 ( V_35 ) ) ;
V_31 = F_30 ( V_13 ) ;
if ( V_31 )
goto V_5;
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_39 -> V_40 ) ;
V_30 -> V_38 = V_22 -> V_39 -> V_40 ;
V_5:
F_27 ( V_13 ) ;
V_50:
F_31 ( V_36 ) ;
V_48:
F_31 ( V_35 ) ;
V_46:
F_32 ( V_32 ) ;
return V_31 ? V_37 : 0 ;
}
T_1
F_33 ( struct V_21 * V_22 , char * V_23 , int V_24 ,
struct V_25 * V_26 , int V_27 , T_2 * V_28 ,
unsigned int V_16 , struct V_29 * V_30 )
{
struct V_34 * V_2 ;
struct V_15 * V_13 ;
struct V_9 V_10 [ 1 ] ;
int V_31 = - 1 ;
T_2 * V_32 ;
unsigned int V_53 ;
if ( V_22 -> V_39 -> V_54 == V_55 )
return F_18 ( V_22 , V_23 , V_24 ,
V_26 , V_27 ,
V_28 , V_16 , V_30 ) ;
if ( V_30 -> V_38 < V_22 -> V_39 -> V_40 ) {
F_5 ( L_5 ,
V_41 , V_30 -> V_38 , V_22 -> V_39 -> V_42 ) ;
return V_37 ;
}
V_32 = F_19 ( V_43 , V_44 ) ;
if ( V_32 == NULL )
return V_37 ;
V_2 = F_20 ( V_22 -> V_39 -> V_47 , 0 , V_45 ) ;
if ( F_21 ( V_2 ) )
goto V_46;
V_13 = F_22 ( V_2 , V_49 ) ;
if ( ! V_13 )
goto V_56;
F_23 ( V_13 , V_51 , NULL , NULL ) ;
V_53 = F_29 ( V_2 ) ;
if ( V_28 != NULL ) {
V_31 = F_28 ( V_2 , V_28 ,
V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_5;
}
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_23 , V_24 ) ;
F_15 ( V_13 , V_10 , NULL , V_24 ) ;
V_31 = F_16 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_25 ( V_26 , V_27 , V_26 -> V_38 - V_27 ,
F_14 , V_13 ) ;
if ( V_31 )
goto V_5;
F_15 ( V_13 , NULL , V_32 , 0 ) ;
V_31 = F_26 ( V_13 ) ;
if ( V_31 )
goto V_5;
switch ( V_22 -> V_39 -> V_54 ) {
case V_57 :
V_31 = V_22 -> V_39 -> V_58 ( V_22 -> V_59 , NULL , V_32 ,
V_32 , V_53 ) ;
if ( V_31 )
goto V_5;
memcpy ( V_30 -> V_14 ,
V_32 + V_53 - V_22 -> V_39 -> V_40 ,
V_22 -> V_39 -> V_40 ) ;
break;
case V_60 :
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_39 -> V_40 ) ;
break;
default:
F_34 () ;
break;
}
V_30 -> V_38 = V_22 -> V_39 -> V_40 ;
V_5:
F_27 ( V_13 ) ;
V_56:
F_31 ( V_2 ) ;
V_46:
F_32 ( V_32 ) ;
return V_31 ? V_37 : 0 ;
}
T_1
F_35 ( struct V_21 * V_22 , char * V_23 , int V_24 ,
struct V_25 * V_26 , int V_27 , T_2 * V_28 ,
unsigned int V_16 , struct V_29 * V_30 )
{
struct V_34 * V_2 ;
struct V_15 * V_13 ;
struct V_9 V_10 [ 1 ] ;
int V_31 = - 1 ;
T_2 * V_32 ;
unsigned int V_53 ;
if ( V_22 -> V_39 -> V_61 == 0 ) {
F_5 ( L_8 ,
V_41 , V_22 -> V_39 -> V_42 ) ;
return V_37 ;
}
if ( V_28 == NULL ) {
F_5 ( L_9 ,
V_41 , V_22 -> V_39 -> V_42 ) ;
return V_37 ;
}
V_32 = F_19 ( V_43 , V_44 ) ;
if ( ! V_32 )
return V_37 ;
V_2 = F_20 ( V_22 -> V_39 -> V_47 , 0 , V_45 ) ;
if ( F_21 ( V_2 ) )
goto V_46;
V_53 = F_29 ( V_2 ) ;
V_13 = F_22 ( V_2 , V_49 ) ;
if ( ! V_13 )
goto V_56;
F_23 ( V_13 , V_51 , NULL , NULL ) ;
V_31 = F_28 ( V_2 , V_28 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_5;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_25 ( V_26 , V_27 , V_26 -> V_38 - V_27 ,
F_14 , V_13 ) ;
if ( V_31 )
goto V_5;
if ( V_23 != NULL ) {
F_6 ( V_10 , V_23 , V_24 ) ;
F_15 ( V_13 , V_10 , NULL , V_24 ) ;
V_31 = F_16 ( V_13 ) ;
if ( V_31 )
goto V_5;
}
F_15 ( V_13 , NULL , V_32 , 0 ) ;
V_31 = F_26 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_30 -> V_38 = V_22 -> V_39 -> V_40 ;
switch ( V_22 -> V_39 -> V_54 ) {
case V_62 :
case V_63 :
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_39 -> V_40 ) ;
break;
default:
F_34 () ;
break;
}
V_5:
F_27 ( V_13 ) ;
V_56:
F_31 ( V_2 ) ;
V_46:
F_32 ( V_32 ) ;
return V_31 ? V_37 : 0 ;
}
static int
F_36 ( struct V_9 * V_10 , void * V_14 )
{
struct V_64 * V_65 = V_14 ;
struct V_25 * V_66 = V_65 -> V_66 ;
struct V_1 * V_2 = F_37 ( V_65 -> V_13 ) ;
struct V_67 * V_68 ;
int V_69 = V_65 -> V_70 + V_10 -> V_6 ;
int V_70 , V_7 ;
int V_71 ;
F_38 ( V_65 -> V_72 > 3 ) ;
V_71 = V_65 -> V_73 - V_66 -> V_74 [ 0 ] . V_75 ;
if ( V_71 >= 0 && V_71 < V_66 -> V_76 ) {
int V_77 = ( V_71 + V_66 -> V_78 ) >> V_79 ;
V_68 = V_65 -> V_80 [ V_77 ] ;
} else {
V_68 = F_39 ( V_10 ) ;
}
F_40 ( & V_65 -> V_81 [ V_65 -> V_72 ] , V_68 , V_10 -> V_6 ,
V_10 -> V_82 ) ;
F_40 ( & V_65 -> V_83 [ V_65 -> V_72 ] , F_39 ( V_10 ) , V_10 -> V_6 ,
V_10 -> V_82 ) ;
V_65 -> V_72 ++ ;
V_65 -> V_70 += V_10 -> V_6 ;
V_65 -> V_73 += V_10 -> V_6 ;
V_70 = V_69 & ( F_3 ( V_2 ) - 1 ) ;
V_69 -= V_70 ;
if ( V_69 == 0 )
return 0 ;
F_41 ( & V_65 -> V_81 [ V_65 -> V_72 - 1 ] ) ;
F_41 ( & V_65 -> V_83 [ V_65 -> V_72 - 1 ] ) ;
F_9 ( V_65 -> V_13 , V_65 -> V_81 , V_65 -> V_83 ,
V_69 , V_65 -> V_3 ) ;
V_7 = F_10 ( V_65 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_42 ( V_65 -> V_81 , 4 ) ;
F_42 ( V_65 -> V_83 , 4 ) ;
if ( V_70 ) {
F_40 ( & V_65 -> V_83 [ 0 ] , F_39 ( V_10 ) , V_70 ,
V_10 -> V_82 + V_10 -> V_6 - V_70 ) ;
V_65 -> V_81 [ 0 ] = V_65 -> V_83 [ 0 ] ;
F_43 ( & V_65 -> V_81 [ 0 ] , V_68 ) ;
V_65 -> V_72 = 1 ;
V_65 -> V_70 = V_70 ;
} else {
V_65 -> V_72 = 0 ;
V_65 -> V_70 = 0 ;
}
return 0 ;
}
int
F_44 ( struct V_1 * V_2 , struct V_25 * V_84 ,
int V_82 , struct V_67 * * V_80 )
{
int V_7 ;
struct V_64 V_65 ;
F_2 ( V_13 , V_2 ) ;
F_38 ( ( V_84 -> V_38 - V_82 ) % F_3 ( V_2 ) != 0 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
memset ( V_65 . V_3 , 0 , sizeof( V_65 . V_3 ) ) ;
V_65 . V_13 = V_13 ;
V_65 . V_73 = V_82 ;
V_65 . V_66 = V_84 ;
V_65 . V_80 = V_80 ;
V_65 . V_72 = 0 ;
V_65 . V_70 = 0 ;
F_42 ( V_65 . V_81 , 4 ) ;
F_42 ( V_65 . V_83 , 4 ) ;
V_7 = F_25 ( V_84 , V_82 , V_84 -> V_38 - V_82 , F_36 , & V_65 ) ;
F_11 ( V_13 ) ;
return V_7 ;
}
static int
F_45 ( struct V_9 * V_10 , void * V_14 )
{
struct V_85 * V_65 = V_14 ;
int V_69 = V_65 -> V_70 + V_10 -> V_6 ;
struct V_1 * V_2 = F_37 ( V_65 -> V_13 ) ;
int V_70 , V_7 ;
F_38 ( V_65 -> V_72 > 3 ) ;
F_40 ( & V_65 -> V_86 [ V_65 -> V_72 ] , F_39 ( V_10 ) , V_10 -> V_6 ,
V_10 -> V_82 ) ;
V_65 -> V_72 ++ ;
V_65 -> V_70 += V_10 -> V_6 ;
V_70 = V_69 & ( F_3 ( V_2 ) - 1 ) ;
V_69 -= V_70 ;
if ( V_69 == 0 )
return 0 ;
F_41 ( & V_65 -> V_86 [ V_65 -> V_72 - 1 ] ) ;
F_9 ( V_65 -> V_13 , V_65 -> V_86 , V_65 -> V_86 ,
V_69 , V_65 -> V_3 ) ;
V_7 = F_13 ( V_65 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_42 ( V_65 -> V_86 , 4 ) ;
if ( V_70 ) {
F_40 ( & V_65 -> V_86 [ 0 ] , F_39 ( V_10 ) , V_70 ,
V_10 -> V_82 + V_10 -> V_6 - V_70 ) ;
V_65 -> V_72 = 1 ;
V_65 -> V_70 = V_70 ;
} else {
V_65 -> V_72 = 0 ;
V_65 -> V_70 = 0 ;
}
return 0 ;
}
int
F_46 ( struct V_1 * V_2 , struct V_25 * V_84 ,
int V_82 )
{
int V_7 ;
struct V_85 V_65 ;
F_2 ( V_13 , V_2 ) ;
F_38 ( ( V_84 -> V_38 - V_82 ) % F_3 ( V_2 ) != 0 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
memset ( V_65 . V_3 , 0 , sizeof( V_65 . V_3 ) ) ;
V_65 . V_13 = V_13 ;
V_65 . V_72 = 0 ;
V_65 . V_70 = 0 ;
F_42 ( V_65 . V_86 , 4 ) ;
V_7 = F_25 ( V_84 , V_82 , V_84 -> V_38 - V_82 , F_45 , & V_65 ) ;
F_11 ( V_13 ) ;
return V_7 ;
}
int
F_47 ( struct V_25 * V_84 , unsigned int V_87 , unsigned int V_88 )
{
T_2 * V_89 ;
if ( V_88 == 0 )
return 0 ;
F_48 ( V_90 > V_91 ) ;
F_38 ( V_88 > V_91 ) ;
V_89 = V_84 -> V_74 [ 0 ] . V_92 + V_87 ;
memmove ( V_89 + V_88 , V_89 , V_84 -> V_74 [ 0 ] . V_75 - V_87 ) ;
V_84 -> V_74 [ 0 ] . V_75 += V_88 ;
V_84 -> V_38 += V_88 ;
return 0 ;
}
static T_1
F_49 ( struct V_1 * V_93 , struct V_25 * V_84 ,
T_1 V_82 , T_2 * V_3 , struct V_67 * * V_80 , int V_58 )
{
T_1 V_7 ;
struct V_9 V_10 [ 1 ] ;
F_2 ( V_13 , V_93 ) ;
T_2 * V_14 ;
struct V_67 * * V_94 ;
T_1 V_38 = V_84 -> V_38 - V_82 ;
if ( V_38 > V_12 * 2 ) {
F_50 ( 0 ) ;
return - V_95 ;
}
V_14 = F_19 ( V_12 * 2 , V_44 ) ;
if ( ! V_14 )
return - V_95 ;
V_94 = V_84 -> V_80 ;
if ( V_58 )
V_84 -> V_80 = V_80 ;
V_7 = F_51 ( V_84 , V_82 , V_14 , V_38 ) ;
V_84 -> V_80 = V_94 ;
if ( V_7 )
goto V_5;
F_6 ( V_10 , V_14 , V_38 ) ;
F_7 ( V_13 , V_93 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_9 ( V_13 , V_10 , V_10 , V_38 , V_3 ) ;
if ( V_58 )
V_7 = F_10 ( V_13 ) ;
else
V_7 = F_13 ( V_13 ) ;
F_11 ( V_13 ) ;
if ( V_7 )
goto V_5;
V_7 = F_52 ( V_84 , V_82 , V_14 , V_38 ) ;
V_5:
F_32 ( V_14 ) ;
return V_7 ;
}
T_1
F_53 ( struct V_21 * V_22 , T_1 V_82 ,
struct V_25 * V_84 , struct V_67 * * V_80 )
{
T_1 V_31 ;
struct V_29 V_96 ;
T_2 * V_28 ;
T_2 * V_97 ;
struct V_1 * V_93 , * V_98 ;
int V_99 ;
struct V_67 * * V_94 ;
int V_100 , V_101 ;
struct V_64 V_65 ;
T_1 V_102 ;
unsigned int V_16 ;
if ( V_22 -> V_103 ) {
V_93 = V_22 -> V_104 ;
V_98 = V_22 -> V_105 ;
V_28 = V_22 -> V_106 ;
V_16 = V_107 ;
} else {
V_93 = V_22 -> V_108 ;
V_98 = V_22 -> V_109 ;
V_28 = V_22 -> V_110 ;
V_16 = V_111 ;
}
V_99 = F_3 ( V_93 ) ;
V_82 += V_112 ;
if ( F_47 ( V_84 , V_82 , V_22 -> V_39 -> V_113 ) )
return V_37 ;
F_54 ( V_84 -> V_74 [ 0 ] . V_92 + V_82 , V_22 -> V_39 -> V_113 ) ;
V_82 -= V_112 ;
if ( V_84 -> V_114 [ 0 ] . V_92 != NULL ) {
V_97 = V_84 -> V_114 [ 0 ] . V_92 + V_84 -> V_114 [ 0 ] . V_75 ;
} else {
V_84 -> V_114 [ 0 ] . V_92 = V_84 -> V_74 [ 0 ] . V_92
+ V_84 -> V_74 [ 0 ] . V_75 ;
V_84 -> V_114 [ 0 ] . V_75 = 0 ;
V_97 = V_84 -> V_114 [ 0 ] . V_92 ;
}
memcpy ( V_97 , V_84 -> V_74 [ 0 ] . V_92 + V_82 , V_112 ) ;
V_84 -> V_114 [ 0 ] . V_75 += V_112 ;
V_84 -> V_38 += V_112 ;
V_96 . V_38 = V_43 ;
V_96 . V_14 = V_84 -> V_114 [ 0 ] . V_92 + V_84 -> V_114 [ 0 ] . V_75 ;
V_94 = V_84 -> V_80 ;
V_84 -> V_80 = V_80 ;
V_31 = F_35 ( V_22 , NULL , 0 , V_84 ,
V_82 + V_112 ,
V_28 , V_16 , & V_96 ) ;
V_84 -> V_80 = V_94 ;
if ( V_31 )
return V_37 ;
V_101 = V_84 -> V_38 - V_82 - V_112 ;
V_100 = ( V_101 + V_99 - 1 ) / V_99 ;
V_102 = 0 ;
if ( V_100 > 2 )
V_102 = ( V_100 - 2 ) * V_99 ;
memset ( V_65 . V_3 , 0 , sizeof( V_65 . V_3 ) ) ;
if ( V_102 ) {
F_2 ( V_13 , V_98 ) ;
V_65 . V_73 = V_82 + V_112 ;
V_65 . V_72 = 0 ;
V_65 . V_70 = 0 ;
V_65 . V_80 = V_80 ;
V_65 . V_66 = V_84 ;
V_65 . V_13 = V_13 ;
F_7 ( V_13 , V_98 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_42 ( V_65 . V_81 , 4 ) ;
F_42 ( V_65 . V_83 , 4 ) ;
V_31 = F_25 ( V_84 , V_82 + V_112 ,
V_102 , F_36 , & V_65 ) ;
F_11 ( V_13 ) ;
if ( V_31 )
goto V_115;
}
V_31 = F_49 ( V_93 , V_84 ,
V_82 + V_112 + V_102 ,
V_65 . V_3 , V_80 , 1 ) ;
if ( V_31 ) {
V_31 = V_37 ;
goto V_115;
}
V_84 -> V_114 [ 0 ] . V_75 += V_22 -> V_39 -> V_40 ;
V_84 -> V_38 += V_22 -> V_39 -> V_40 ;
V_115:
if ( V_31 )
V_31 = V_37 ;
return V_31 ;
}
T_1
F_55 ( struct V_21 * V_22 , T_1 V_82 , struct V_25 * V_84 ,
T_1 * V_116 , T_1 * V_117 )
{
struct V_25 V_118 ;
T_1 V_7 = 0 ;
T_2 * V_119 ;
struct V_1 * V_93 , * V_98 ;
struct V_29 V_120 ;
T_2 V_121 [ V_43 ] ;
T_2 V_122 [ V_43 ] ;
int V_100 , V_99 , V_102 ;
struct V_85 V_65 ;
unsigned int V_16 ;
if ( V_22 -> V_103 ) {
V_93 = V_22 -> V_108 ;
V_98 = V_22 -> V_109 ;
V_119 = V_22 -> V_110 ;
V_16 = V_111 ;
} else {
V_93 = V_22 -> V_104 ;
V_98 = V_22 -> V_105 ;
V_119 = V_22 -> V_106 ;
V_16 = V_107 ;
}
V_99 = F_3 ( V_93 ) ;
F_56 ( V_84 , & V_118 , V_82 + V_112 ,
( V_84 -> V_38 - V_82 - V_112 -
V_22 -> V_39 -> V_40 ) ) ;
V_100 = ( V_118 . V_38 + V_99 - 1 ) / V_99 ;
V_102 = 0 ;
if ( V_100 > 2 )
V_102 = ( V_100 - 2 ) * V_99 ;
memset ( V_65 . V_3 , 0 , sizeof( V_65 . V_3 ) ) ;
if ( V_102 ) {
F_2 ( V_13 , V_98 ) ;
V_65 . V_72 = 0 ;
V_65 . V_70 = 0 ;
V_65 . V_13 = V_13 ;
F_7 ( V_13 , V_98 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_42 ( V_65 . V_86 , 4 ) ;
V_7 = F_25 ( & V_118 , 0 , V_102 , F_45 , & V_65 ) ;
F_11 ( V_13 ) ;
if ( V_7 )
goto V_115;
}
V_7 = F_49 ( V_93 , & V_118 , V_102 , V_65 . V_3 , NULL , 0 ) ;
if ( V_7 )
goto V_115;
V_120 . V_38 = sizeof( V_121 ) ;
V_120 . V_14 = V_121 ;
V_7 = F_35 ( V_22 , NULL , 0 , & V_118 , 0 ,
V_119 , V_16 , & V_120 ) ;
if ( V_7 )
goto V_115;
V_7 = F_51 ( V_84 , V_84 -> V_38 - V_22 -> V_39 -> V_40 ,
V_122 , V_22 -> V_39 -> V_40 ) ;
if ( V_7 )
goto V_115;
if ( memcmp ( V_122 , V_121 , V_22 -> V_39 -> V_40 ) != 0 ) {
V_7 = V_123 ;
goto V_115;
}
* V_116 = V_22 -> V_39 -> V_113 ;
* V_117 = V_22 -> V_39 -> V_40 ;
V_115:
if ( V_7 && V_7 != V_123 )
V_7 = V_37 ;
return V_7 ;
}
int
F_57 ( struct V_21 * V_22 , struct V_1 * V_93 ,
unsigned char * V_124 )
{
struct V_125 * V_96 ;
struct V_126 * V_65 ;
T_2 V_127 [ V_128 ] ;
T_1 V_129 = 0 ;
int V_31 ;
F_5 ( L_10 , V_41 ) ;
V_96 = F_58 ( V_22 -> V_39 -> V_47 , 0 , 0 ) ;
if ( F_21 ( V_96 ) ) {
F_5 ( L_11 ,
V_41 , F_59 ( V_96 ) , V_22 -> V_39 -> V_47 ) ;
return F_59 ( V_96 ) ;
}
V_65 = F_19 ( sizeof( * V_65 ) + F_60 ( V_96 ) ,
V_49 ) ;
if ( ! V_65 ) {
F_5 ( L_12 ,
V_41 , V_22 -> V_39 -> V_47 ) ;
F_61 ( V_96 ) ;
return - V_95 ;
}
V_65 -> V_2 = V_96 ;
V_65 -> V_130 = 0 ;
V_31 = F_62 ( V_96 , V_22 -> V_131 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_115;
V_31 = F_63 ( V_65 , ( T_2 * ) & V_129 , 4 , V_127 ) ;
if ( V_31 )
goto V_115;
V_31 = F_62 ( V_96 , V_127 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_115;
V_31 = F_63 ( V_65 , V_124 , 8 , V_127 ) ;
if ( V_31 )
goto V_115;
V_31 = F_64 ( V_93 , V_127 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_115;
V_31 = 0 ;
V_115:
F_65 ( V_65 ) ;
F_61 ( V_96 ) ;
F_5 ( L_13 , V_41 , V_31 ) ;
return V_31 ;
}
int
F_66 ( struct V_21 * V_22 , struct V_1 * V_93 ,
T_3 V_132 )
{
struct V_125 * V_96 ;
struct V_126 * V_65 ;
T_2 V_133 [ V_128 ] ;
T_2 V_129 [ 4 ] = { 0 } ;
T_2 V_134 [ 4 ] ;
int V_31 , V_77 ;
F_5 ( L_14 , V_41 , V_132 ) ;
V_96 = F_58 ( V_22 -> V_39 -> V_47 , 0 , 0 ) ;
if ( F_21 ( V_96 ) ) {
F_5 ( L_11 ,
V_41 , F_59 ( V_96 ) , V_22 -> V_39 -> V_47 ) ;
return F_59 ( V_96 ) ;
}
V_65 = F_19 ( sizeof( * V_65 ) + F_60 ( V_96 ) ,
V_49 ) ;
if ( ! V_65 ) {
F_5 ( L_12 ,
V_41 , V_22 -> V_39 -> V_47 ) ;
F_61 ( V_96 ) ;
return - V_95 ;
}
V_65 -> V_2 = V_96 ;
V_65 -> V_130 = 0 ;
for ( V_77 = 0 ; V_77 < V_22 -> V_39 -> V_52 ; V_77 ++ )
V_133 [ V_77 ] = V_22 -> V_131 [ V_77 ] ^ 0xf0 ;
V_31 = F_62 ( V_96 , V_133 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_115;
V_31 = F_63 ( V_65 , V_129 , 4 , V_133 ) ;
if ( V_31 )
goto V_115;
V_31 = F_62 ( V_96 , V_133 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_115;
V_134 [ 0 ] = ( unsigned char ) ( ( V_132 >> 24 ) & 0xff ) ;
V_134 [ 1 ] = ( unsigned char ) ( ( V_132 >> 16 ) & 0xff ) ;
V_134 [ 2 ] = ( unsigned char ) ( ( V_132 >> 8 ) & 0xff ) ;
V_134 [ 3 ] = ( unsigned char ) ( ( V_132 >> 0 ) & 0xff ) ;
V_31 = F_63 ( V_65 , V_134 , 4 , V_133 ) ;
if ( V_31 )
goto V_115;
V_31 = F_64 ( V_93 , V_133 , V_22 -> V_39 -> V_52 ) ;
if ( V_31 )
goto V_115;
V_31 = 0 ;
V_115:
F_65 ( V_65 ) ;
F_61 ( V_96 ) ;
F_5 ( L_13 , V_41 , V_31 ) ;
return V_31 ;
}
