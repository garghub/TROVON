int F_1 ( T_1 * V_1 , unsigned char * * V_2 ,
const T_2 * V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_3 ( T_1 * V_1 , unsigned char * * V_2 , const T_2 * V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , 0 ) ;
}
static int F_2 ( T_1 * V_1 , unsigned char * * V_2 ,
const T_2 * V_3 , int V_5 )
{
if ( V_2 && ! * V_2 ) {
unsigned char * V_6 , * V_7 ;
int V_8 ;
V_8 = F_4 ( & V_1 , NULL , V_3 , - 1 , V_5 ) ;
if ( V_8 <= 0 )
return V_8 ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 == NULL )
return - 1 ;
V_6 = V_7 ;
F_4 ( & V_1 , & V_6 , V_3 , - 1 , V_5 ) ;
* V_2 = V_7 ;
return V_8 ;
}
return F_4 ( & V_1 , V_2 , V_3 , - 1 , V_5 ) ;
}
int F_4 ( T_1 * * V_9 , unsigned char * * V_2 ,
const T_2 * V_3 , int V_10 , int V_11 )
{
const T_3 * V_12 = NULL ;
int V_13 , V_14 , V_15 , V_16 = 1 ;
const T_4 * V_17 ;
const T_5 * V_18 = V_3 -> V_19 ;
T_6 * V_20 = 0 ;
if ( ( V_3 -> V_21 != V_22 ) && ! * V_9 )
return 0 ;
if ( V_18 && V_18 -> V_20 )
V_20 = V_18 -> V_20 ;
switch ( V_3 -> V_21 ) {
case V_22 :
if ( V_3 -> V_23 )
return F_6 ( V_9 , V_2 , V_3 -> V_23 ,
V_10 , V_11 ) ;
return F_7 ( V_9 , V_2 , V_3 , V_10 , V_11 ) ;
case V_24 :
return F_7 ( V_9 , V_2 , V_3 , - 1 , V_11 ) ;
case V_25 :
if ( V_20 && ! V_20 ( V_26 , V_9 , V_3 , NULL ) )
return 0 ;
V_13 = F_8 ( V_9 , V_3 ) ;
if ( ( V_13 >= 0 ) && ( V_13 < V_3 -> V_27 ) ) {
T_1 * * V_28 ;
const T_3 * V_29 ;
V_29 = V_3 -> V_23 + V_13 ;
V_28 = F_9 ( V_9 , V_29 ) ;
return F_6 ( V_28 , V_2 , V_29 , - 1 , V_11 ) ;
}
if ( V_20 && ! V_20 ( V_30 , V_9 , V_3 , NULL ) )
return 0 ;
break;
case V_31 :
V_17 = V_3 -> V_19 ;
return V_17 -> V_32 ( V_9 , V_2 , V_3 , V_10 , V_11 ) ;
case V_33 :
if ( V_11 & V_4 )
V_16 = 2 ;
case V_34 :
V_13 = F_10 ( & V_14 , V_2 , V_9 , V_3 ) ;
if ( V_13 < 0 )
return 0 ;
if ( V_13 > 0 )
return V_14 ;
V_14 = 0 ;
if ( V_10 == - 1 ) {
V_10 = V_35 ;
V_11 = ( V_11 & ~ V_36 )
| V_37 ;
}
if ( V_20 && ! V_20 ( V_26 , V_9 , V_3 , NULL ) )
return 0 ;
for ( V_13 = 0 , V_12 = V_3 -> V_23 ; V_13 < V_3 -> V_27 ; V_12 ++ , V_13 ++ ) {
const T_3 * V_38 ;
T_1 * * V_39 ;
int V_40 ;
V_38 = F_11 ( V_9 , V_12 , 1 ) ;
if ( ! V_38 )
return 0 ;
V_39 = F_9 ( V_9 , V_38 ) ;
V_40 = F_6 ( V_39 , NULL , V_38 , - 1 , V_11 ) ;
if ( V_40 == - 1 || ( V_40 > V_41 - V_14 ) )
return - 1 ;
V_14 += V_40 ;
}
V_15 = F_12 ( V_16 , V_14 , V_10 ) ;
if ( ! V_2 || V_15 == - 1 )
return V_15 ;
F_13 ( V_2 , V_16 , V_14 , V_10 , V_11 ) ;
for ( V_13 = 0 , V_12 = V_3 -> V_23 ; V_13 < V_3 -> V_27 ; V_12 ++ , V_13 ++ ) {
const T_3 * V_38 ;
T_1 * * V_39 ;
V_38 = F_11 ( V_9 , V_12 , 1 ) ;
if ( ! V_38 )
return 0 ;
V_39 = F_9 ( V_9 , V_38 ) ;
F_6 ( V_39 , V_2 , V_38 , - 1 , V_11 ) ;
}
if ( V_16 == 2 )
F_14 ( V_2 ) ;
if ( V_20 && ! V_20 ( V_30 , V_9 , V_3 , NULL ) )
return 0 ;
return V_15 ;
default:
return 0 ;
}
return 0 ;
}
static int F_6 ( T_1 * * V_9 , unsigned char * * V_2 ,
const T_3 * V_12 , int V_10 , int V_42 )
{
int V_13 , V_43 , V_5 , V_44 , V_45 , V_16 ;
T_1 * V_46 ;
V_5 = V_12 -> V_5 ;
if ( V_5 & V_47 ) {
V_46 = ( T_1 * ) V_9 ;
V_9 = & V_46 ;
}
if ( V_5 & V_48 ) {
if ( V_10 != - 1 )
return - 1 ;
V_44 = V_12 -> V_10 ;
V_45 = V_5 & V_36 ;
} else if ( V_10 != - 1 ) {
V_44 = V_10 ;
V_45 = V_42 & V_36 ;
} else {
V_44 = - 1 ;
V_45 = 0 ;
}
V_42 &= ~ V_36 ;
if ( ( V_5 & V_4 ) && ( V_42 & V_4 ) )
V_16 = 2 ;
else
V_16 = 1 ;
if ( V_5 & V_49 ) {
F_15 ( T_1 ) * V_50 = ( F_15 ( T_1 ) * ) * V_9 ;
int V_51 , V_52 , V_53 ;
int V_54 , V_55 ;
T_1 * V_56 ;
if ( ! * V_9 )
return 0 ;
if ( V_5 & V_57 ) {
V_51 = 1 ;
if ( V_5 & V_58 )
V_51 = 2 ;
} else
V_51 = 0 ;
if ( ( V_44 != - 1 ) && ! ( V_5 & V_59 ) ) {
V_52 = V_44 ;
V_53 = V_45 ;
} else {
V_53 = V_37 ;
if ( V_51 )
V_52 = V_60 ;
else
V_52 = V_35 ;
}
V_54 = 0 ;
for ( V_13 = 0 ; V_13 < F_16 ( V_50 ) ; V_13 ++ ) {
int V_40 ;
V_56 = F_17 ( V_50 , V_13 ) ;
V_40 = F_4 ( & V_56 , NULL , F_18 ( V_12 -> V_61 ) ,
- 1 , V_42 ) ;
if ( V_40 == - 1 || ( V_54 > V_41 - V_40 ) )
return - 1 ;
V_54 += V_40 ;
}
V_55 = F_12 ( V_16 , V_54 , V_52 ) ;
if ( V_55 == - 1 )
return - 1 ;
if ( V_5 & V_59 )
V_43 = F_12 ( V_16 , V_55 , V_44 ) ;
else
V_43 = V_55 ;
if ( ! V_2 || V_43 == - 1 )
return V_43 ;
if ( V_5 & V_59 )
F_13 ( V_2 , V_16 , V_55 , V_44 , V_45 ) ;
F_13 ( V_2 , V_16 , V_54 , V_52 , V_53 ) ;
F_19 ( V_50 , V_2 , V_54 , F_18 ( V_12 -> V_61 ) ,
V_51 , V_42 ) ;
if ( V_16 == 2 ) {
F_14 ( V_2 ) ;
if ( V_5 & V_59 )
F_14 ( V_2 ) ;
}
return V_43 ;
}
if ( V_5 & V_59 ) {
V_13 = F_4 ( V_9 , NULL , F_18 ( V_12 -> V_61 ) , - 1 , V_42 ) ;
if ( ! V_13 )
return 0 ;
V_43 = F_12 ( V_16 , V_13 , V_44 ) ;
if ( V_2 && V_43 != - 1 ) {
F_13 ( V_2 , V_16 , V_13 , V_44 , V_45 ) ;
F_4 ( V_9 , V_2 , F_18 ( V_12 -> V_61 ) , - 1 , V_42 ) ;
if ( V_16 == 2 )
F_14 ( V_2 ) ;
}
return V_43 ;
}
return F_4 ( V_9 , V_2 , F_18 ( V_12 -> V_61 ) ,
V_44 , V_45 | V_42 ) ;
}
static int F_20 ( const void * V_62 , const void * V_63 )
{
const T_7 * V_64 = V_62 , * V_65 = V_63 ;
int V_66 , V_13 ;
V_66 = ( V_64 -> V_67 < V_65 -> V_67 ) ? V_64 -> V_67 : V_65 -> V_67 ;
V_13 = memcmp ( V_64 -> V_68 , V_65 -> V_68 , V_66 ) ;
if ( V_13 )
return V_13 ;
return V_64 -> V_67 - V_65 -> V_67 ;
}
static int F_7 ( T_1 * * V_9 , unsigned char * * V_2 ,
const T_2 * V_3 , int V_10 , int V_11 )
{
int V_8 ;
int V_69 ;
int V_70 ;
int V_16 = 0 ;
V_69 = V_3 -> V_69 ;
V_8 = F_21 ( V_9 , NULL , & V_69 , V_3 ) ;
if ( ( V_69 == V_35 ) || ( V_69 == V_60 ) ||
( V_69 == V_71 ) )
V_70 = 0 ;
else
V_70 = 1 ;
if ( V_8 == - 1 )
return 0 ;
if ( V_8 == - 2 ) {
V_16 = 2 ;
V_8 = 0 ;
}
if ( V_10 == - 1 )
V_10 = V_69 ;
if ( V_2 ) {
if ( V_70 )
F_13 ( V_2 , V_16 , V_8 , V_10 , V_11 ) ;
F_21 ( V_9 , * V_2 , & V_69 , V_3 ) ;
if ( V_16 )
F_14 ( V_2 ) ;
else
* V_2 += V_8 ;
}
if ( V_70 )
return F_12 ( V_16 , V_8 , V_10 ) ;
return V_8 ;
}
static int F_21 ( T_1 * * V_9 , unsigned char * V_72 , int * V_73 ,
const T_2 * V_3 )
{
T_8 * V_74 = NULL ;
T_9 * V_75 ;
T_10 * V_76 ;
int V_69 ;
const unsigned char * V_77 ;
unsigned char V_78 ;
int V_8 ;
const T_11 * V_79 ;
V_79 = V_3 -> V_19 ;
if ( V_79 && V_79 -> V_80 )
return V_79 -> V_80 ( V_9 , V_72 , V_73 , V_3 ) ;
if ( ( V_3 -> V_21 != V_22 )
|| ( V_3 -> V_69 != V_81 ) ) {
if ( ! * V_9 )
return - 1 ;
}
if ( V_3 -> V_21 == V_24 ) {
V_75 = ( T_9 * ) * V_9 ;
V_69 = V_75 -> type ;
* V_73 = V_69 ;
} else if ( V_3 -> V_69 == V_82 ) {
T_12 * V_83 ;
V_83 = ( T_12 * ) * V_9 ;
V_69 = V_83 -> type ;
* V_73 = V_69 ;
V_9 = & V_83 -> V_84 . V_85 ;
} else
V_69 = * V_73 ;
switch ( V_69 ) {
case V_86 :
V_76 = ( T_10 * ) * V_9 ;
V_77 = V_76 -> V_68 ;
V_8 = V_76 -> V_67 ;
break;
case V_87 :
V_77 = NULL ;
V_8 = 0 ;
break;
case V_81 :
V_74 = ( T_8 * ) V_9 ;
if ( * V_74 == - 1 )
return - 1 ;
if ( V_3 -> V_69 != V_82 ) {
if ( * V_74 && ( V_3 -> V_88 > 0 ) )
return - 1 ;
if ( ! * V_74 && ! V_3 -> V_88 )
return - 1 ;
}
V_78 = ( unsigned char ) * V_74 ;
V_77 = & V_78 ;
V_8 = 1 ;
break;
case V_89 :
return F_22 ( ( V_90 * ) * V_9 ,
V_72 ? & V_72 : NULL ) ;
case V_91 :
case V_92 :
return F_23 ( ( V_93 * ) * V_9 , V_72 ? & V_72 : NULL ) ;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_35 :
case V_60 :
default:
V_75 = ( T_9 * ) * V_9 ;
if ( ( V_3 -> V_88 == V_4 )
&& ( V_75 -> V_5 & V_108 ) ) {
if ( V_72 ) {
V_75 -> V_68 = V_72 ;
V_75 -> V_67 = 0 ;
}
return - 2 ;
}
V_77 = V_75 -> V_68 ;
V_8 = V_75 -> V_67 ;
break;
}
if ( V_72 && V_8 )
memcpy ( V_72 , V_77 , V_8 ) ;
return V_8 ;
}
