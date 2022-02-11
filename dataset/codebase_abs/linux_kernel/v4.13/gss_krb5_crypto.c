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
V_13 = F_22 ( V_35 , V_44 ) ;
if ( ! V_13 )
goto V_49;
F_23 ( V_13 , V_50 , NULL , NULL ) ;
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
V_13 = F_22 ( V_36 , V_44 ) ;
if ( ! V_13 )
goto V_49;
F_23 ( V_13 , V_50 , NULL , NULL ) ;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_28 ( V_36 , V_28 , V_22 -> V_39 -> V_51 ) ;
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
V_49:
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
unsigned int V_52 ;
if ( V_22 -> V_39 -> V_53 == V_54 )
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
V_13 = F_22 ( V_2 , V_44 ) ;
if ( ! V_13 )
goto V_55;
F_23 ( V_13 , V_50 , NULL , NULL ) ;
V_52 = F_29 ( V_2 ) ;
if ( V_28 != NULL ) {
V_31 = F_28 ( V_2 , V_28 ,
V_22 -> V_39 -> V_51 ) ;
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
switch ( V_22 -> V_39 -> V_53 ) {
case V_56 :
V_31 = V_22 -> V_39 -> V_57 ( V_22 -> V_58 , NULL , V_32 ,
V_32 , V_52 ) ;
if ( V_31 )
goto V_5;
memcpy ( V_30 -> V_14 ,
V_32 + V_52 - V_22 -> V_39 -> V_40 ,
V_22 -> V_39 -> V_40 ) ;
break;
case V_59 :
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_39 -> V_40 ) ;
break;
default:
F_34 () ;
break;
}
V_30 -> V_38 = V_22 -> V_39 -> V_40 ;
V_5:
F_27 ( V_13 ) ;
V_55:
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
unsigned int V_52 ;
if ( V_22 -> V_39 -> V_60 == 0 ) {
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
V_52 = F_29 ( V_2 ) ;
V_13 = F_22 ( V_2 , V_44 ) ;
if ( ! V_13 )
goto V_55;
F_23 ( V_13 , V_50 , NULL , NULL ) ;
V_31 = F_28 ( V_2 , V_28 , V_22 -> V_39 -> V_51 ) ;
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
switch ( V_22 -> V_39 -> V_53 ) {
case V_61 :
case V_62 :
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_39 -> V_40 ) ;
break;
default:
F_34 () ;
break;
}
V_5:
F_27 ( V_13 ) ;
V_55:
F_31 ( V_2 ) ;
V_46:
F_32 ( V_32 ) ;
return V_31 ? V_37 : 0 ;
}
static int
F_36 ( struct V_9 * V_10 , void * V_14 )
{
struct V_63 * V_64 = V_14 ;
struct V_25 * V_65 = V_64 -> V_65 ;
struct V_1 * V_2 = F_37 ( V_64 -> V_13 ) ;
struct V_66 * V_67 ;
int V_68 = V_64 -> V_69 + V_10 -> V_6 ;
int V_69 , V_7 ;
int V_70 ;
F_38 ( V_64 -> V_71 > 3 ) ;
V_70 = V_64 -> V_72 - V_65 -> V_73 [ 0 ] . V_74 ;
if ( V_70 >= 0 && V_70 < V_65 -> V_75 ) {
int V_76 = ( V_70 + V_65 -> V_77 ) >> V_78 ;
V_67 = V_64 -> V_79 [ V_76 ] ;
} else {
V_67 = F_39 ( V_10 ) ;
}
F_40 ( & V_64 -> V_80 [ V_64 -> V_71 ] , V_67 , V_10 -> V_6 ,
V_10 -> V_81 ) ;
F_40 ( & V_64 -> V_82 [ V_64 -> V_71 ] , F_39 ( V_10 ) , V_10 -> V_6 ,
V_10 -> V_81 ) ;
V_64 -> V_71 ++ ;
V_64 -> V_69 += V_10 -> V_6 ;
V_64 -> V_72 += V_10 -> V_6 ;
V_69 = V_68 & ( F_3 ( V_2 ) - 1 ) ;
V_68 -= V_69 ;
if ( V_68 == 0 )
return 0 ;
F_41 ( & V_64 -> V_80 [ V_64 -> V_71 - 1 ] ) ;
F_41 ( & V_64 -> V_82 [ V_64 -> V_71 - 1 ] ) ;
F_9 ( V_64 -> V_13 , V_64 -> V_80 , V_64 -> V_82 ,
V_68 , V_64 -> V_3 ) ;
V_7 = F_10 ( V_64 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_42 ( V_64 -> V_80 , 4 ) ;
F_42 ( V_64 -> V_82 , 4 ) ;
if ( V_69 ) {
F_40 ( & V_64 -> V_82 [ 0 ] , F_39 ( V_10 ) , V_69 ,
V_10 -> V_81 + V_10 -> V_6 - V_69 ) ;
V_64 -> V_80 [ 0 ] = V_64 -> V_82 [ 0 ] ;
F_43 ( & V_64 -> V_80 [ 0 ] , V_67 ) ;
V_64 -> V_71 = 1 ;
V_64 -> V_69 = V_69 ;
} else {
V_64 -> V_71 = 0 ;
V_64 -> V_69 = 0 ;
}
return 0 ;
}
int
F_44 ( struct V_1 * V_2 , struct V_25 * V_83 ,
int V_81 , struct V_66 * * V_79 )
{
int V_7 ;
struct V_63 V_64 ;
F_2 ( V_13 , V_2 ) ;
F_38 ( ( V_83 -> V_38 - V_81 ) % F_3 ( V_2 ) != 0 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
memset ( V_64 . V_3 , 0 , sizeof( V_64 . V_3 ) ) ;
V_64 . V_13 = V_13 ;
V_64 . V_72 = V_81 ;
V_64 . V_65 = V_83 ;
V_64 . V_79 = V_79 ;
V_64 . V_71 = 0 ;
V_64 . V_69 = 0 ;
F_42 ( V_64 . V_80 , 4 ) ;
F_42 ( V_64 . V_82 , 4 ) ;
V_7 = F_25 ( V_83 , V_81 , V_83 -> V_38 - V_81 , F_36 , & V_64 ) ;
F_11 ( V_13 ) ;
return V_7 ;
}
static int
F_45 ( struct V_9 * V_10 , void * V_14 )
{
struct V_84 * V_64 = V_14 ;
int V_68 = V_64 -> V_69 + V_10 -> V_6 ;
struct V_1 * V_2 = F_37 ( V_64 -> V_13 ) ;
int V_69 , V_7 ;
F_38 ( V_64 -> V_71 > 3 ) ;
F_40 ( & V_64 -> V_85 [ V_64 -> V_71 ] , F_39 ( V_10 ) , V_10 -> V_6 ,
V_10 -> V_81 ) ;
V_64 -> V_71 ++ ;
V_64 -> V_69 += V_10 -> V_6 ;
V_69 = V_68 & ( F_3 ( V_2 ) - 1 ) ;
V_68 -= V_69 ;
if ( V_68 == 0 )
return 0 ;
F_41 ( & V_64 -> V_85 [ V_64 -> V_71 - 1 ] ) ;
F_9 ( V_64 -> V_13 , V_64 -> V_85 , V_64 -> V_85 ,
V_68 , V_64 -> V_3 ) ;
V_7 = F_13 ( V_64 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_42 ( V_64 -> V_85 , 4 ) ;
if ( V_69 ) {
F_40 ( & V_64 -> V_85 [ 0 ] , F_39 ( V_10 ) , V_69 ,
V_10 -> V_81 + V_10 -> V_6 - V_69 ) ;
V_64 -> V_71 = 1 ;
V_64 -> V_69 = V_69 ;
} else {
V_64 -> V_71 = 0 ;
V_64 -> V_69 = 0 ;
}
return 0 ;
}
int
F_46 ( struct V_1 * V_2 , struct V_25 * V_83 ,
int V_81 )
{
int V_7 ;
struct V_84 V_64 ;
F_2 ( V_13 , V_2 ) ;
F_38 ( ( V_83 -> V_38 - V_81 ) % F_3 ( V_2 ) != 0 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
memset ( V_64 . V_3 , 0 , sizeof( V_64 . V_3 ) ) ;
V_64 . V_13 = V_13 ;
V_64 . V_71 = 0 ;
V_64 . V_69 = 0 ;
F_42 ( V_64 . V_85 , 4 ) ;
V_7 = F_25 ( V_83 , V_81 , V_83 -> V_38 - V_81 , F_45 , & V_64 ) ;
F_11 ( V_13 ) ;
return V_7 ;
}
int
F_47 ( struct V_25 * V_83 , unsigned int V_86 , unsigned int V_87 )
{
T_2 * V_88 ;
if ( V_87 == 0 )
return 0 ;
F_48 ( V_89 > V_90 ) ;
F_38 ( V_87 > V_90 ) ;
V_88 = V_83 -> V_73 [ 0 ] . V_91 + V_86 ;
memmove ( V_88 + V_87 , V_88 , V_83 -> V_73 [ 0 ] . V_74 - V_86 ) ;
V_83 -> V_73 [ 0 ] . V_74 += V_87 ;
V_83 -> V_38 += V_87 ;
return 0 ;
}
static T_1
F_49 ( struct V_1 * V_92 , struct V_25 * V_83 ,
T_1 V_81 , T_2 * V_3 , struct V_66 * * V_79 , int V_57 )
{
T_1 V_7 ;
struct V_9 V_10 [ 1 ] ;
F_2 ( V_13 , V_92 ) ;
T_2 * V_14 ;
struct V_66 * * V_93 ;
T_1 V_38 = V_83 -> V_38 - V_81 ;
if ( V_38 > V_12 * 2 ) {
F_50 ( 0 ) ;
return - V_94 ;
}
V_14 = F_19 ( V_12 * 2 , V_44 ) ;
if ( ! V_14 )
return - V_94 ;
V_93 = V_83 -> V_79 ;
if ( V_57 )
V_83 -> V_79 = V_79 ;
V_7 = F_51 ( V_83 , V_81 , V_14 , V_38 ) ;
V_83 -> V_79 = V_93 ;
if ( V_7 )
goto V_5;
F_6 ( V_10 , V_14 , V_38 ) ;
F_7 ( V_13 , V_92 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_9 ( V_13 , V_10 , V_10 , V_38 , V_3 ) ;
if ( V_57 )
V_7 = F_10 ( V_13 ) ;
else
V_7 = F_13 ( V_13 ) ;
F_11 ( V_13 ) ;
if ( V_7 )
goto V_5;
V_7 = F_52 ( V_83 , V_81 , V_14 , V_38 ) ;
V_5:
F_32 ( V_14 ) ;
return V_7 ;
}
T_1
F_53 ( struct V_21 * V_22 , T_1 V_81 ,
struct V_25 * V_83 , struct V_66 * * V_79 )
{
T_1 V_31 ;
struct V_29 V_95 ;
T_2 * V_28 ;
T_2 * V_96 ;
struct V_1 * V_92 , * V_97 ;
int V_98 ;
struct V_66 * * V_93 ;
int V_99 , V_100 ;
struct V_63 V_64 ;
T_1 V_101 ;
unsigned int V_16 ;
if ( V_22 -> V_102 ) {
V_92 = V_22 -> V_103 ;
V_97 = V_22 -> V_104 ;
V_28 = V_22 -> V_105 ;
V_16 = V_106 ;
} else {
V_92 = V_22 -> V_107 ;
V_97 = V_22 -> V_108 ;
V_28 = V_22 -> V_109 ;
V_16 = V_110 ;
}
V_98 = F_3 ( V_92 ) ;
V_81 += V_111 ;
if ( F_47 ( V_83 , V_81 , V_22 -> V_39 -> V_112 ) )
return V_37 ;
F_54 ( V_83 -> V_73 [ 0 ] . V_91 + V_81 , V_22 -> V_39 -> V_112 ) ;
V_81 -= V_111 ;
if ( V_83 -> V_113 [ 0 ] . V_91 != NULL ) {
V_96 = V_83 -> V_113 [ 0 ] . V_91 + V_83 -> V_113 [ 0 ] . V_74 ;
} else {
V_83 -> V_113 [ 0 ] . V_91 = V_83 -> V_73 [ 0 ] . V_91
+ V_83 -> V_73 [ 0 ] . V_74 ;
V_83 -> V_113 [ 0 ] . V_74 = 0 ;
V_96 = V_83 -> V_113 [ 0 ] . V_91 ;
}
memcpy ( V_96 , V_83 -> V_73 [ 0 ] . V_91 + V_81 , V_111 ) ;
V_83 -> V_113 [ 0 ] . V_74 += V_111 ;
V_83 -> V_38 += V_111 ;
V_95 . V_38 = V_43 ;
V_95 . V_14 = V_83 -> V_113 [ 0 ] . V_91 + V_83 -> V_113 [ 0 ] . V_74 ;
V_93 = V_83 -> V_79 ;
V_83 -> V_79 = V_79 ;
V_31 = F_35 ( V_22 , NULL , 0 , V_83 ,
V_81 + V_111 ,
V_28 , V_16 , & V_95 ) ;
V_83 -> V_79 = V_93 ;
if ( V_31 )
return V_37 ;
V_100 = V_83 -> V_38 - V_81 - V_111 ;
V_99 = ( V_100 + V_98 - 1 ) / V_98 ;
V_101 = 0 ;
if ( V_99 > 2 )
V_101 = ( V_99 - 2 ) * V_98 ;
memset ( V_64 . V_3 , 0 , sizeof( V_64 . V_3 ) ) ;
if ( V_101 ) {
F_2 ( V_13 , V_97 ) ;
V_64 . V_72 = V_81 + V_111 ;
V_64 . V_71 = 0 ;
V_64 . V_69 = 0 ;
V_64 . V_79 = V_79 ;
V_64 . V_65 = V_83 ;
V_64 . V_13 = V_13 ;
F_7 ( V_13 , V_97 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_42 ( V_64 . V_80 , 4 ) ;
F_42 ( V_64 . V_82 , 4 ) ;
V_31 = F_25 ( V_83 , V_81 + V_111 ,
V_101 , F_36 , & V_64 ) ;
F_11 ( V_13 ) ;
if ( V_31 )
goto V_114;
}
V_31 = F_49 ( V_92 , V_83 ,
V_81 + V_111 + V_101 ,
V_64 . V_3 , V_79 , 1 ) ;
if ( V_31 ) {
V_31 = V_37 ;
goto V_114;
}
V_83 -> V_113 [ 0 ] . V_74 += V_22 -> V_39 -> V_40 ;
V_83 -> V_38 += V_22 -> V_39 -> V_40 ;
V_114:
if ( V_31 )
V_31 = V_37 ;
return V_31 ;
}
T_1
F_55 ( struct V_21 * V_22 , T_1 V_81 , struct V_25 * V_83 ,
T_1 * V_115 , T_1 * V_116 )
{
struct V_25 V_117 ;
T_1 V_7 = 0 ;
T_2 * V_118 ;
struct V_1 * V_92 , * V_97 ;
struct V_29 V_119 ;
T_2 V_120 [ V_43 ] ;
T_2 V_121 [ V_43 ] ;
int V_99 , V_98 , V_101 ;
struct V_84 V_64 ;
unsigned int V_16 ;
if ( V_22 -> V_102 ) {
V_92 = V_22 -> V_107 ;
V_97 = V_22 -> V_108 ;
V_118 = V_22 -> V_109 ;
V_16 = V_110 ;
} else {
V_92 = V_22 -> V_103 ;
V_97 = V_22 -> V_104 ;
V_118 = V_22 -> V_105 ;
V_16 = V_106 ;
}
V_98 = F_3 ( V_92 ) ;
F_56 ( V_83 , & V_117 , V_81 + V_111 ,
( V_83 -> V_38 - V_81 - V_111 -
V_22 -> V_39 -> V_40 ) ) ;
V_99 = ( V_117 . V_38 + V_98 - 1 ) / V_98 ;
V_101 = 0 ;
if ( V_99 > 2 )
V_101 = ( V_99 - 2 ) * V_98 ;
memset ( V_64 . V_3 , 0 , sizeof( V_64 . V_3 ) ) ;
if ( V_101 ) {
F_2 ( V_13 , V_97 ) ;
V_64 . V_71 = 0 ;
V_64 . V_69 = 0 ;
V_64 . V_13 = V_13 ;
F_7 ( V_13 , V_97 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_42 ( V_64 . V_85 , 4 ) ;
V_7 = F_25 ( & V_117 , 0 , V_101 , F_45 , & V_64 ) ;
F_11 ( V_13 ) ;
if ( V_7 )
goto V_114;
}
V_7 = F_49 ( V_92 , & V_117 , V_101 , V_64 . V_3 , NULL , 0 ) ;
if ( V_7 )
goto V_114;
V_119 . V_38 = sizeof( V_120 ) ;
V_119 . V_14 = V_120 ;
V_7 = F_35 ( V_22 , NULL , 0 , & V_117 , 0 ,
V_118 , V_16 , & V_119 ) ;
if ( V_7 )
goto V_114;
V_7 = F_51 ( V_83 , V_83 -> V_38 - V_22 -> V_39 -> V_40 ,
V_121 , V_22 -> V_39 -> V_40 ) ;
if ( V_7 )
goto V_114;
if ( F_57 ( V_121 , V_120 , V_22 -> V_39 -> V_40 ) != 0 ) {
V_7 = V_122 ;
goto V_114;
}
* V_115 = V_22 -> V_39 -> V_112 ;
* V_116 = V_22 -> V_39 -> V_40 ;
V_114:
if ( V_7 && V_7 != V_122 )
V_7 = V_37 ;
return V_7 ;
}
int
F_58 ( struct V_21 * V_22 , struct V_1 * V_92 ,
unsigned char * V_123 )
{
struct V_124 * V_95 ;
struct V_125 * V_64 ;
T_2 V_126 [ V_127 ] ;
T_1 V_128 = 0 ;
int V_31 ;
F_5 ( L_10 , V_41 ) ;
V_95 = F_59 ( V_22 -> V_39 -> V_47 , 0 , 0 ) ;
if ( F_21 ( V_95 ) ) {
F_5 ( L_11 ,
V_41 , F_60 ( V_95 ) , V_22 -> V_39 -> V_47 ) ;
return F_60 ( V_95 ) ;
}
V_64 = F_19 ( sizeof( * V_64 ) + F_61 ( V_95 ) ,
V_44 ) ;
if ( ! V_64 ) {
F_5 ( L_12 ,
V_41 , V_22 -> V_39 -> V_47 ) ;
F_62 ( V_95 ) ;
return - V_94 ;
}
V_64 -> V_2 = V_95 ;
V_64 -> V_129 = 0 ;
V_31 = F_63 ( V_95 , V_22 -> V_130 , V_22 -> V_39 -> V_51 ) ;
if ( V_31 )
goto V_114;
V_31 = F_64 ( V_64 , ( T_2 * ) & V_128 , 4 , V_126 ) ;
if ( V_31 )
goto V_114;
V_31 = F_63 ( V_95 , V_126 , V_22 -> V_39 -> V_51 ) ;
if ( V_31 )
goto V_114;
V_31 = F_64 ( V_64 , V_123 , 8 , V_126 ) ;
if ( V_31 )
goto V_114;
V_31 = F_65 ( V_92 , V_126 , V_22 -> V_39 -> V_51 ) ;
if ( V_31 )
goto V_114;
V_31 = 0 ;
V_114:
F_66 ( V_64 ) ;
F_62 ( V_95 ) ;
F_5 ( L_13 , V_41 , V_31 ) ;
return V_31 ;
}
int
F_67 ( struct V_21 * V_22 , struct V_1 * V_92 ,
T_3 V_131 )
{
struct V_124 * V_95 ;
struct V_125 * V_64 ;
T_2 V_132 [ V_127 ] ;
T_2 V_128 [ 4 ] = { 0 } ;
T_2 V_133 [ 4 ] ;
int V_31 , V_76 ;
F_5 ( L_14 , V_41 , V_131 ) ;
V_95 = F_59 ( V_22 -> V_39 -> V_47 , 0 , 0 ) ;
if ( F_21 ( V_95 ) ) {
F_5 ( L_11 ,
V_41 , F_60 ( V_95 ) , V_22 -> V_39 -> V_47 ) ;
return F_60 ( V_95 ) ;
}
V_64 = F_19 ( sizeof( * V_64 ) + F_61 ( V_95 ) ,
V_44 ) ;
if ( ! V_64 ) {
F_5 ( L_12 ,
V_41 , V_22 -> V_39 -> V_47 ) ;
F_62 ( V_95 ) ;
return - V_94 ;
}
V_64 -> V_2 = V_95 ;
V_64 -> V_129 = 0 ;
for ( V_76 = 0 ; V_76 < V_22 -> V_39 -> V_51 ; V_76 ++ )
V_132 [ V_76 ] = V_22 -> V_130 [ V_76 ] ^ 0xf0 ;
V_31 = F_63 ( V_95 , V_132 , V_22 -> V_39 -> V_51 ) ;
if ( V_31 )
goto V_114;
V_31 = F_64 ( V_64 , V_128 , 4 , V_132 ) ;
if ( V_31 )
goto V_114;
V_31 = F_63 ( V_95 , V_132 , V_22 -> V_39 -> V_51 ) ;
if ( V_31 )
goto V_114;
V_133 [ 0 ] = ( unsigned char ) ( ( V_131 >> 24 ) & 0xff ) ;
V_133 [ 1 ] = ( unsigned char ) ( ( V_131 >> 16 ) & 0xff ) ;
V_133 [ 2 ] = ( unsigned char ) ( ( V_131 >> 8 ) & 0xff ) ;
V_133 [ 3 ] = ( unsigned char ) ( ( V_131 >> 0 ) & 0xff ) ;
V_31 = F_64 ( V_64 , V_133 , 4 , V_132 ) ;
if ( V_31 )
goto V_114;
V_31 = F_65 ( V_92 , V_132 , V_22 -> V_39 -> V_51 ) ;
if ( V_31 )
goto V_114;
V_31 = 0 ;
V_114:
F_66 ( V_64 ) ;
F_62 ( V_95 ) ;
F_5 ( L_13 , V_41 , V_31 ) ;
return V_31 ;
}
