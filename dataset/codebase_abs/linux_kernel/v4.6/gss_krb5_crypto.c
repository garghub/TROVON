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
int V_31 ;
T_2 V_32 [ V_33 ] ;
T_2 V_34 [ 4 ] ;
struct V_35 * V_36 ;
struct V_35 * V_37 ;
struct V_15 * V_13 ;
if ( V_28 == NULL )
return V_38 ;
if ( V_30 -> V_39 < V_22 -> V_40 -> V_41 ) {
F_5 ( L_5 ,
V_42 , V_30 -> V_39 , V_22 -> V_40 -> V_43 ) ;
return V_38 ;
}
if ( F_17 ( V_16 , V_34 ) ) {
F_5 ( L_6 , V_42 , V_16 ) ;
return V_38 ;
}
V_36 = F_19 ( L_7 , 0 , V_44 ) ;
if ( F_20 ( V_36 ) )
return V_38 ;
V_37 = F_19 ( V_22 -> V_40 -> V_45 , 0 ,
V_44 ) ;
if ( F_20 ( V_37 ) ) {
F_21 ( V_36 ) ;
return V_38 ;
}
V_13 = F_22 ( V_36 , V_46 ) ;
if ( ! V_13 ) {
F_21 ( V_37 ) ;
F_21 ( V_36 ) ;
return V_38 ;
}
F_23 ( V_13 , V_47 , NULL , NULL ) ;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_34 , 4 ) ;
F_15 ( V_13 , V_10 , NULL , 4 ) ;
V_31 = F_16 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_23 , V_24 ) ;
F_15 ( V_13 , V_10 , NULL , V_24 ) ;
V_31 = F_16 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_25 ( V_26 , V_27 , V_26 -> V_39 - V_27 ,
F_14 , V_13 ) ;
if ( V_31 )
goto V_5;
F_15 ( V_13 , NULL , V_32 , 0 ) ;
V_31 = F_26 ( V_13 ) ;
if ( V_31 )
goto V_5;
F_27 ( V_13 ) ;
V_13 = F_22 ( V_37 , V_46 ) ;
if ( ! V_13 ) {
F_21 ( V_37 ) ;
F_21 ( V_36 ) ;
return V_38 ;
}
F_23 ( V_13 , V_47 , NULL , NULL ) ;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_28 ( V_37 , V_28 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_5;
F_6 ( V_10 , V_32 , F_29 ( V_36 ) ) ;
F_15 ( V_13 , V_10 , V_32 ,
F_29 ( V_36 ) ) ;
V_31 = F_30 ( V_13 ) ;
if ( V_31 )
goto V_5;
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_40 -> V_41 ) ;
V_30 -> V_39 = V_22 -> V_40 -> V_41 ;
V_5:
F_27 ( V_13 ) ;
F_21 ( V_36 ) ;
F_21 ( V_37 ) ;
return V_31 ? V_38 : 0 ;
}
T_1
F_31 ( struct V_21 * V_22 , char * V_23 , int V_24 ,
struct V_25 * V_26 , int V_27 , T_2 * V_28 ,
unsigned int V_16 , struct V_29 * V_30 )
{
struct V_35 * V_2 ;
struct V_15 * V_13 ;
struct V_9 V_10 [ 1 ] ;
int V_31 ;
T_2 V_32 [ V_33 ] ;
unsigned int V_49 ;
if ( V_22 -> V_40 -> V_50 == V_51 )
return F_18 ( V_22 , V_23 , V_24 ,
V_26 , V_27 ,
V_28 , V_16 , V_30 ) ;
if ( V_30 -> V_39 < V_22 -> V_40 -> V_41 ) {
F_5 ( L_5 ,
V_42 , V_30 -> V_39 , V_22 -> V_40 -> V_43 ) ;
return V_38 ;
}
V_2 = F_19 ( V_22 -> V_40 -> V_45 , 0 , V_44 ) ;
if ( F_20 ( V_2 ) )
return V_38 ;
V_13 = F_22 ( V_2 , V_46 ) ;
if ( ! V_13 ) {
F_21 ( V_2 ) ;
return V_38 ;
}
F_23 ( V_13 , V_47 , NULL , NULL ) ;
V_49 = F_29 ( V_2 ) ;
if ( V_28 != NULL ) {
V_31 = F_28 ( V_2 , V_28 ,
V_22 -> V_40 -> V_48 ) ;
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
V_31 = F_25 ( V_26 , V_27 , V_26 -> V_39 - V_27 ,
F_14 , V_13 ) ;
if ( V_31 )
goto V_5;
F_15 ( V_13 , NULL , V_32 , 0 ) ;
V_31 = F_26 ( V_13 ) ;
if ( V_31 )
goto V_5;
switch ( V_22 -> V_40 -> V_50 ) {
case V_52 :
V_31 = V_22 -> V_40 -> V_53 ( V_22 -> V_54 , NULL , V_32 ,
V_32 , V_49 ) ;
if ( V_31 )
goto V_5;
memcpy ( V_30 -> V_14 ,
V_32 + V_49 - V_22 -> V_40 -> V_41 ,
V_22 -> V_40 -> V_41 ) ;
break;
case V_55 :
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_40 -> V_41 ) ;
break;
default:
F_32 () ;
break;
}
V_30 -> V_39 = V_22 -> V_40 -> V_41 ;
V_5:
F_27 ( V_13 ) ;
F_21 ( V_2 ) ;
return V_31 ? V_38 : 0 ;
}
T_1
F_33 ( struct V_21 * V_22 , char * V_23 , int V_24 ,
struct V_25 * V_26 , int V_27 , T_2 * V_28 ,
unsigned int V_16 , struct V_29 * V_30 )
{
struct V_35 * V_2 ;
struct V_15 * V_13 ;
struct V_9 V_10 [ 1 ] ;
int V_31 ;
T_2 V_32 [ V_33 ] ;
unsigned int V_49 ;
if ( V_22 -> V_40 -> V_56 == 0 ) {
F_5 ( L_8 ,
V_42 , V_22 -> V_40 -> V_43 ) ;
return V_38 ;
}
if ( V_28 == NULL ) {
F_5 ( L_9 ,
V_42 , V_22 -> V_40 -> V_43 ) ;
return V_38 ;
}
V_2 = F_19 ( V_22 -> V_40 -> V_45 , 0 , V_44 ) ;
if ( F_20 ( V_2 ) )
return V_38 ;
V_49 = F_29 ( V_2 ) ;
V_13 = F_22 ( V_2 , V_46 ) ;
if ( ! V_13 ) {
F_21 ( V_2 ) ;
return V_38 ;
}
F_23 ( V_13 , V_47 , NULL , NULL ) ;
V_31 = F_28 ( V_2 , V_28 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_5;
V_31 = F_24 ( V_13 ) ;
if ( V_31 )
goto V_5;
V_31 = F_25 ( V_26 , V_27 , V_26 -> V_39 - V_27 ,
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
V_30 -> V_39 = V_22 -> V_40 -> V_41 ;
switch ( V_22 -> V_40 -> V_50 ) {
case V_57 :
case V_58 :
memcpy ( V_30 -> V_14 , V_32 , V_22 -> V_40 -> V_41 ) ;
break;
default:
F_32 () ;
break;
}
V_5:
F_27 ( V_13 ) ;
F_21 ( V_2 ) ;
return V_31 ? V_38 : 0 ;
}
static int
F_34 ( struct V_9 * V_10 , void * V_14 )
{
struct V_59 * V_60 = V_14 ;
struct V_25 * V_61 = V_60 -> V_61 ;
struct V_1 * V_2 = F_35 ( V_60 -> V_13 ) ;
struct V_62 * V_63 ;
int V_64 = V_60 -> V_65 + V_10 -> V_6 ;
int V_65 , V_7 ;
int V_66 ;
F_36 ( V_60 -> V_67 > 3 ) ;
V_66 = V_60 -> V_68 - V_61 -> V_69 [ 0 ] . V_70 ;
if ( V_66 >= 0 && V_66 < V_61 -> V_71 ) {
int V_72 = ( V_66 + V_61 -> V_73 ) >> V_74 ;
V_63 = V_60 -> V_75 [ V_72 ] ;
} else {
V_63 = F_37 ( V_10 ) ;
}
F_38 ( & V_60 -> V_76 [ V_60 -> V_67 ] , V_63 , V_10 -> V_6 ,
V_10 -> V_77 ) ;
F_38 ( & V_60 -> V_78 [ V_60 -> V_67 ] , F_37 ( V_10 ) , V_10 -> V_6 ,
V_10 -> V_77 ) ;
V_60 -> V_67 ++ ;
V_60 -> V_65 += V_10 -> V_6 ;
V_60 -> V_68 += V_10 -> V_6 ;
V_65 = V_64 & ( F_3 ( V_2 ) - 1 ) ;
V_64 -= V_65 ;
if ( V_64 == 0 )
return 0 ;
F_39 ( & V_60 -> V_76 [ V_60 -> V_67 - 1 ] ) ;
F_39 ( & V_60 -> V_78 [ V_60 -> V_67 - 1 ] ) ;
F_9 ( V_60 -> V_13 , V_60 -> V_76 , V_60 -> V_78 ,
V_64 , V_60 -> V_3 ) ;
V_7 = F_10 ( V_60 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_40 ( V_60 -> V_76 , 4 ) ;
F_40 ( V_60 -> V_78 , 4 ) ;
if ( V_65 ) {
F_38 ( & V_60 -> V_78 [ 0 ] , F_37 ( V_10 ) , V_65 ,
V_10 -> V_77 + V_10 -> V_6 - V_65 ) ;
V_60 -> V_76 [ 0 ] = V_60 -> V_78 [ 0 ] ;
F_41 ( & V_60 -> V_76 [ 0 ] , V_63 ) ;
V_60 -> V_67 = 1 ;
V_60 -> V_65 = V_65 ;
} else {
V_60 -> V_67 = 0 ;
V_60 -> V_65 = 0 ;
}
return 0 ;
}
int
F_42 ( struct V_1 * V_2 , struct V_25 * V_79 ,
int V_77 , struct V_62 * * V_75 )
{
int V_7 ;
struct V_59 V_60 ;
F_2 ( V_13 , V_2 ) ;
F_36 ( ( V_79 -> V_39 - V_77 ) % F_3 ( V_2 ) != 0 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
memset ( V_60 . V_3 , 0 , sizeof( V_60 . V_3 ) ) ;
V_60 . V_13 = V_13 ;
V_60 . V_68 = V_77 ;
V_60 . V_61 = V_79 ;
V_60 . V_75 = V_75 ;
V_60 . V_67 = 0 ;
V_60 . V_65 = 0 ;
F_40 ( V_60 . V_76 , 4 ) ;
F_40 ( V_60 . V_78 , 4 ) ;
V_7 = F_25 ( V_79 , V_77 , V_79 -> V_39 - V_77 , F_34 , & V_60 ) ;
F_11 ( V_13 ) ;
return V_7 ;
}
static int
F_43 ( struct V_9 * V_10 , void * V_14 )
{
struct V_80 * V_60 = V_14 ;
int V_64 = V_60 -> V_65 + V_10 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_60 -> V_13 ) ;
int V_65 , V_7 ;
F_36 ( V_60 -> V_67 > 3 ) ;
F_38 ( & V_60 -> V_81 [ V_60 -> V_67 ] , F_37 ( V_10 ) , V_10 -> V_6 ,
V_10 -> V_77 ) ;
V_60 -> V_67 ++ ;
V_60 -> V_65 += V_10 -> V_6 ;
V_65 = V_64 & ( F_3 ( V_2 ) - 1 ) ;
V_64 -= V_65 ;
if ( V_64 == 0 )
return 0 ;
F_39 ( & V_60 -> V_81 [ V_60 -> V_67 - 1 ] ) ;
F_9 ( V_60 -> V_13 , V_60 -> V_81 , V_60 -> V_81 ,
V_64 , V_60 -> V_3 ) ;
V_7 = F_13 ( V_60 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_40 ( V_60 -> V_81 , 4 ) ;
if ( V_65 ) {
F_38 ( & V_60 -> V_81 [ 0 ] , F_37 ( V_10 ) , V_65 ,
V_10 -> V_77 + V_10 -> V_6 - V_65 ) ;
V_60 -> V_67 = 1 ;
V_60 -> V_65 = V_65 ;
} else {
V_60 -> V_67 = 0 ;
V_60 -> V_65 = 0 ;
}
return 0 ;
}
int
F_44 ( struct V_1 * V_2 , struct V_25 * V_79 ,
int V_77 )
{
int V_7 ;
struct V_80 V_60 ;
F_2 ( V_13 , V_2 ) ;
F_36 ( ( V_79 -> V_39 - V_77 ) % F_3 ( V_2 ) != 0 ) ;
F_7 ( V_13 , V_2 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
memset ( V_60 . V_3 , 0 , sizeof( V_60 . V_3 ) ) ;
V_60 . V_13 = V_13 ;
V_60 . V_67 = 0 ;
V_60 . V_65 = 0 ;
F_40 ( V_60 . V_81 , 4 ) ;
V_7 = F_25 ( V_79 , V_77 , V_79 -> V_39 - V_77 , F_43 , & V_60 ) ;
F_11 ( V_13 ) ;
return V_7 ;
}
int
F_45 ( struct V_25 * V_79 , unsigned int V_82 , unsigned int V_83 )
{
T_2 * V_84 ;
if ( V_83 == 0 )
return 0 ;
F_46 ( V_85 > V_86 ) ;
F_36 ( V_83 > V_86 ) ;
V_84 = V_79 -> V_69 [ 0 ] . V_87 + V_82 ;
memmove ( V_84 + V_83 , V_84 , V_79 -> V_69 [ 0 ] . V_70 - V_82 ) ;
V_79 -> V_69 [ 0 ] . V_70 += V_83 ;
V_79 -> V_39 += V_83 ;
return 0 ;
}
static T_1
F_47 ( struct V_1 * V_88 , struct V_25 * V_79 ,
T_1 V_77 , T_2 * V_3 , struct V_62 * * V_75 , int V_53 )
{
T_1 V_7 ;
struct V_9 V_10 [ 1 ] ;
F_2 ( V_13 , V_88 ) ;
T_2 V_14 [ V_12 * 2 ] ;
struct V_62 * * V_89 ;
T_1 V_39 = V_79 -> V_39 - V_77 ;
if ( V_39 > F_48 ( V_14 ) ) {
F_49 ( 0 ) ;
return - V_90 ;
}
V_89 = V_79 -> V_75 ;
if ( V_53 )
V_79 -> V_75 = V_75 ;
V_7 = F_50 ( V_79 , V_77 , V_14 , V_39 ) ;
V_79 -> V_75 = V_89 ;
if ( V_7 )
goto V_5;
F_6 ( V_10 , V_14 , V_39 ) ;
F_7 ( V_13 , V_88 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_9 ( V_13 , V_10 , V_10 , V_39 , V_3 ) ;
if ( V_53 )
V_7 = F_10 ( V_13 ) ;
else
V_7 = F_13 ( V_13 ) ;
F_11 ( V_13 ) ;
if ( V_7 )
goto V_5;
V_7 = F_51 ( V_79 , V_77 , V_14 , V_39 ) ;
V_5:
return V_7 ;
}
T_1
F_52 ( struct V_21 * V_22 , T_1 V_77 ,
struct V_25 * V_79 , struct V_62 * * V_75 )
{
T_1 V_31 ;
struct V_29 V_91 ;
T_2 * V_28 ;
T_2 * V_92 ;
struct V_1 * V_88 , * V_93 ;
int V_94 ;
struct V_62 * * V_89 ;
int V_95 , V_96 ;
struct V_59 V_60 ;
T_1 V_97 ;
unsigned int V_16 ;
if ( V_22 -> V_98 ) {
V_88 = V_22 -> V_99 ;
V_93 = V_22 -> V_100 ;
V_28 = V_22 -> V_101 ;
V_16 = V_102 ;
} else {
V_88 = V_22 -> V_103 ;
V_93 = V_22 -> V_104 ;
V_28 = V_22 -> V_105 ;
V_16 = V_106 ;
}
V_94 = F_3 ( V_88 ) ;
V_77 += V_107 ;
if ( F_45 ( V_79 , V_77 , V_22 -> V_40 -> V_108 ) )
return V_38 ;
F_53 ( V_79 -> V_69 [ 0 ] . V_87 + V_77 , V_22 -> V_40 -> V_108 ) ;
V_77 -= V_107 ;
if ( V_79 -> V_109 [ 0 ] . V_87 != NULL ) {
V_92 = V_79 -> V_109 [ 0 ] . V_87 + V_79 -> V_109 [ 0 ] . V_70 ;
} else {
V_79 -> V_109 [ 0 ] . V_87 = V_79 -> V_69 [ 0 ] . V_87
+ V_79 -> V_69 [ 0 ] . V_70 ;
V_79 -> V_109 [ 0 ] . V_70 = 0 ;
V_92 = V_79 -> V_109 [ 0 ] . V_87 ;
}
memcpy ( V_92 , V_79 -> V_69 [ 0 ] . V_87 + V_77 , V_107 ) ;
V_79 -> V_109 [ 0 ] . V_70 += V_107 ;
V_79 -> V_39 += V_107 ;
V_91 . V_39 = V_33 ;
V_91 . V_14 = V_79 -> V_109 [ 0 ] . V_87 + V_79 -> V_109 [ 0 ] . V_70 ;
V_89 = V_79 -> V_75 ;
V_79 -> V_75 = V_75 ;
V_31 = F_33 ( V_22 , NULL , 0 , V_79 ,
V_77 + V_107 ,
V_28 , V_16 , & V_91 ) ;
V_79 -> V_75 = V_89 ;
if ( V_31 )
return V_38 ;
V_96 = V_79 -> V_39 - V_77 - V_107 ;
V_95 = ( V_96 + V_94 - 1 ) / V_94 ;
V_97 = 0 ;
if ( V_95 > 2 )
V_97 = ( V_95 - 2 ) * V_94 ;
memset ( V_60 . V_3 , 0 , sizeof( V_60 . V_3 ) ) ;
if ( V_97 ) {
F_2 ( V_13 , V_93 ) ;
V_60 . V_68 = V_77 + V_107 ;
V_60 . V_67 = 0 ;
V_60 . V_65 = 0 ;
V_60 . V_75 = V_75 ;
V_60 . V_61 = V_79 ;
V_60 . V_13 = V_13 ;
F_7 ( V_13 , V_93 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_40 ( V_60 . V_76 , 4 ) ;
F_40 ( V_60 . V_78 , 4 ) ;
V_31 = F_25 ( V_79 , V_77 + V_107 ,
V_97 , F_34 , & V_60 ) ;
F_11 ( V_13 ) ;
if ( V_31 )
goto V_110;
}
V_31 = F_47 ( V_88 , V_79 ,
V_77 + V_107 + V_97 ,
V_60 . V_3 , V_75 , 1 ) ;
if ( V_31 ) {
V_31 = V_38 ;
goto V_110;
}
V_79 -> V_109 [ 0 ] . V_70 += V_22 -> V_40 -> V_41 ;
V_79 -> V_39 += V_22 -> V_40 -> V_41 ;
V_110:
if ( V_31 )
V_31 = V_38 ;
return V_31 ;
}
T_1
F_54 ( struct V_21 * V_22 , T_1 V_77 , struct V_25 * V_79 ,
T_1 * V_111 , T_1 * V_112 )
{
struct V_25 V_113 ;
T_1 V_7 = 0 ;
T_2 * V_114 ;
struct V_1 * V_88 , * V_93 ;
struct V_29 V_115 ;
T_2 V_116 [ V_33 ] ;
T_2 V_117 [ V_33 ] ;
int V_95 , V_94 , V_97 ;
struct V_80 V_60 ;
unsigned int V_16 ;
if ( V_22 -> V_98 ) {
V_88 = V_22 -> V_103 ;
V_93 = V_22 -> V_104 ;
V_114 = V_22 -> V_105 ;
V_16 = V_106 ;
} else {
V_88 = V_22 -> V_99 ;
V_93 = V_22 -> V_100 ;
V_114 = V_22 -> V_101 ;
V_16 = V_102 ;
}
V_94 = F_3 ( V_88 ) ;
F_55 ( V_79 , & V_113 , V_77 + V_107 ,
( V_79 -> V_39 - V_77 - V_107 -
V_22 -> V_40 -> V_41 ) ) ;
V_95 = ( V_113 . V_39 + V_94 - 1 ) / V_94 ;
V_97 = 0 ;
if ( V_95 > 2 )
V_97 = ( V_95 - 2 ) * V_94 ;
memset ( V_60 . V_3 , 0 , sizeof( V_60 . V_3 ) ) ;
if ( V_97 ) {
F_2 ( V_13 , V_93 ) ;
V_60 . V_67 = 0 ;
V_60 . V_65 = 0 ;
V_60 . V_13 = V_13 ;
F_7 ( V_13 , V_93 ) ;
F_8 ( V_13 , 0 , NULL , NULL ) ;
F_40 ( V_60 . V_81 , 4 ) ;
V_7 = F_25 ( & V_113 , 0 , V_97 , F_43 , & V_60 ) ;
F_11 ( V_13 ) ;
if ( V_7 )
goto V_110;
}
V_7 = F_47 ( V_88 , & V_113 , V_97 , V_60 . V_3 , NULL , 0 ) ;
if ( V_7 )
goto V_110;
V_115 . V_39 = sizeof( V_116 ) ;
V_115 . V_14 = V_116 ;
V_7 = F_33 ( V_22 , NULL , 0 , & V_113 , 0 ,
V_114 , V_16 , & V_115 ) ;
if ( V_7 )
goto V_110;
V_7 = F_50 ( V_79 , V_79 -> V_39 - V_22 -> V_40 -> V_41 ,
V_117 , V_22 -> V_40 -> V_41 ) ;
if ( V_7 )
goto V_110;
if ( memcmp ( V_117 , V_116 , V_22 -> V_40 -> V_41 ) != 0 ) {
V_7 = V_118 ;
goto V_110;
}
* V_111 = V_22 -> V_40 -> V_108 ;
* V_112 = V_22 -> V_40 -> V_41 ;
V_110:
if ( V_7 && V_7 != V_118 )
V_7 = V_38 ;
return V_7 ;
}
int
F_56 ( struct V_21 * V_22 , struct V_1 * V_88 ,
unsigned char * V_119 )
{
struct V_120 * V_91 ;
struct V_121 * V_60 ;
T_2 V_122 [ V_123 ] ;
T_1 V_124 = 0 ;
int V_31 ;
F_5 ( L_10 , V_42 ) ;
V_91 = F_57 ( V_22 -> V_40 -> V_45 , 0 , 0 ) ;
if ( F_20 ( V_91 ) ) {
F_5 ( L_11 ,
V_42 , F_58 ( V_91 ) , V_22 -> V_40 -> V_45 ) ;
return F_58 ( V_91 ) ;
}
V_60 = F_59 ( sizeof( * V_60 ) + F_60 ( V_91 ) ,
V_46 ) ;
if ( ! V_60 ) {
F_5 ( L_12 ,
V_42 , V_22 -> V_40 -> V_45 ) ;
F_61 ( V_91 ) ;
return - V_90 ;
}
V_60 -> V_2 = V_91 ;
V_60 -> V_125 = 0 ;
V_31 = F_62 ( V_91 , V_22 -> V_126 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_110;
V_31 = F_63 ( V_60 , ( T_2 * ) & V_124 , 4 , V_122 ) ;
if ( V_31 )
goto V_110;
V_31 = F_62 ( V_91 , V_122 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_110;
V_31 = F_63 ( V_60 , V_119 , 8 , V_122 ) ;
if ( V_31 )
goto V_110;
V_31 = F_64 ( V_88 , V_122 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_110;
V_31 = 0 ;
V_110:
F_65 ( V_60 ) ;
F_61 ( V_91 ) ;
F_5 ( L_13 , V_42 , V_31 ) ;
return V_31 ;
}
int
F_66 ( struct V_21 * V_22 , struct V_1 * V_88 ,
T_3 V_127 )
{
struct V_120 * V_91 ;
struct V_121 * V_60 ;
T_2 V_128 [ V_123 ] ;
T_2 V_124 [ 4 ] = { 0 } ;
T_2 V_129 [ 4 ] ;
int V_31 , V_72 ;
F_5 ( L_14 , V_42 , V_127 ) ;
V_91 = F_57 ( V_22 -> V_40 -> V_45 , 0 , 0 ) ;
if ( F_20 ( V_91 ) ) {
F_5 ( L_11 ,
V_42 , F_58 ( V_91 ) , V_22 -> V_40 -> V_45 ) ;
return F_58 ( V_91 ) ;
}
V_60 = F_59 ( sizeof( * V_60 ) + F_60 ( V_91 ) ,
V_46 ) ;
if ( ! V_60 ) {
F_5 ( L_12 ,
V_42 , V_22 -> V_40 -> V_45 ) ;
F_61 ( V_91 ) ;
return - V_90 ;
}
V_60 -> V_2 = V_91 ;
V_60 -> V_125 = 0 ;
for ( V_72 = 0 ; V_72 < V_22 -> V_40 -> V_48 ; V_72 ++ )
V_128 [ V_72 ] = V_22 -> V_126 [ V_72 ] ^ 0xf0 ;
V_31 = F_62 ( V_91 , V_128 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_110;
V_31 = F_63 ( V_60 , V_124 , 4 , V_128 ) ;
if ( V_31 )
goto V_110;
V_31 = F_62 ( V_91 , V_128 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_110;
V_129 [ 0 ] = ( unsigned char ) ( ( V_127 >> 24 ) & 0xff ) ;
V_129 [ 1 ] = ( unsigned char ) ( ( V_127 >> 16 ) & 0xff ) ;
V_129 [ 2 ] = ( unsigned char ) ( ( V_127 >> 8 ) & 0xff ) ;
V_129 [ 3 ] = ( unsigned char ) ( ( V_127 >> 0 ) & 0xff ) ;
V_31 = F_63 ( V_60 , V_129 , 4 , V_128 ) ;
if ( V_31 )
goto V_110;
V_31 = F_64 ( V_88 , V_128 , V_22 -> V_40 -> V_48 ) ;
if ( V_31 )
goto V_110;
V_31 = 0 ;
V_110:
F_65 ( V_60 ) ;
F_61 ( V_91 ) ;
F_5 ( L_13 , V_42 , V_31 ) ;
return V_31 ;
}
