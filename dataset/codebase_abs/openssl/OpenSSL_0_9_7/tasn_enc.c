int F_1 ( T_1 * V_1 , unsigned char * * V_2 , const T_2 * V_3 )
{
if( V_2 && ! * V_2 ) {
unsigned char * V_4 , * V_5 ;
int V_6 ;
V_6 = F_2 ( & V_1 , NULL , V_3 , - 1 , 0 ) ;
if( V_6 <= 0 ) return V_6 ;
V_5 = F_3 ( V_6 ) ;
if( ! V_5 ) return - 1 ;
V_4 = V_5 ;
F_2 ( & V_1 , & V_4 , V_3 , - 1 , 0 ) ;
* V_2 = V_5 ;
return V_6 ;
}
return F_2 ( & V_1 , V_2 , V_3 , - 1 , 0 ) ;
}
int F_2 ( T_1 * * V_7 , unsigned char * * V_2 , const T_2 * V_3 , int V_8 , int V_9 )
{
const T_3 * V_10 = NULL ;
unsigned char * V_4 = NULL ;
int V_11 , V_12 , V_13 ;
T_4 * V_14 ;
const T_5 * V_15 ;
const T_6 * V_16 ;
const T_7 * V_17 = V_3 -> V_18 ;
T_8 * V_19 ;
if( ( V_3 -> V_20 != V_21 ) && ! * V_7 ) return 0 ;
if( V_17 && V_17 -> V_19 ) V_19 = V_17 -> V_19 ;
else V_19 = 0 ;
switch( V_3 -> V_20 ) {
case V_21 :
if( V_3 -> V_22 )
return F_4 ( V_7 , V_2 , V_3 -> V_22 ) ;
return F_5 ( V_7 , V_2 , V_3 , V_8 , V_9 ) ;
break;
case V_23 :
V_14 = ( T_4 * ) * V_7 ;
return F_5 ( V_7 , V_2 , V_3 , - 1 , 0 ) ;
case V_24 :
if( V_19 && ! V_19 ( V_25 , V_7 , V_3 ) )
return 0 ;
V_11 = F_6 ( V_7 , V_3 ) ;
if( ( V_11 >= 0 ) && ( V_11 < V_3 -> V_26 ) ) {
T_1 * * V_27 ;
const T_3 * V_28 ;
V_28 = V_3 -> V_22 + V_11 ;
V_27 = F_7 ( V_7 , V_28 ) ;
return F_4 ( V_27 , V_2 , V_28 ) ;
}
if( V_19 && ! V_19 ( V_29 , V_7 , V_3 ) )
return 0 ;
break;
case V_30 :
V_16 = V_3 -> V_18 ;
return V_16 -> V_31 ( V_7 , V_2 , V_3 , V_8 , V_9 ) ;
case V_32 :
V_15 = V_3 -> V_18 ;
if( V_2 ) V_4 = * V_2 ;
V_11 = V_15 -> V_33 ( * V_7 , V_2 ) ;
if( V_2 && ( V_8 != - 1 ) )
* V_4 = V_9 | V_8 | ( * V_4 & V_34 ) ;
return V_11 ;
case V_35 :
V_11 = F_8 ( & V_12 , V_2 , V_7 , V_3 ) ;
if( V_11 < 0 ) return 0 ;
if( V_11 > 0 ) return V_12 ;
V_12 = 0 ;
if( V_8 == - 1 ) {
V_8 = V_36 ;
V_9 = V_37 ;
}
if( V_19 && ! V_19 ( V_25 , V_7 , V_3 ) )
return 0 ;
for( V_11 = 0 , V_10 = V_3 -> V_22 ; V_11 < V_3 -> V_26 ; V_10 ++ , V_11 ++ ) {
const T_3 * V_38 ;
T_1 * * V_39 ;
V_38 = F_9 ( V_7 , V_10 , 1 ) ;
if( ! V_38 ) return 0 ;
V_39 = F_7 ( V_7 , V_38 ) ;
V_12 += F_4 ( V_39 , NULL , V_38 ) ;
}
V_13 = F_10 ( 1 , V_12 , V_8 ) ;
if( ! V_2 ) return V_13 ;
F_11 ( V_2 , 1 , V_12 , V_8 , V_9 ) ;
for( V_11 = 0 , V_10 = V_3 -> V_22 ; V_11 < V_3 -> V_26 ; V_10 ++ , V_11 ++ ) {
const T_3 * V_38 ;
T_1 * * V_39 ;
V_38 = F_9 ( V_7 , V_10 , 1 ) ;
if( ! V_38 ) return 0 ;
V_39 = F_7 ( V_7 , V_38 ) ;
F_4 ( V_39 , V_2 , V_38 ) ;
}
if( V_19 && ! V_19 ( V_29 , V_7 , V_3 ) )
return 0 ;
return V_13 ;
default:
return 0 ;
}
return 0 ;
}
int F_4 ( T_1 * * V_7 , unsigned char * * V_2 , const T_3 * V_10 )
{
int V_11 , V_40 , V_41 , V_9 ;
V_41 = V_10 -> V_41 ;
V_9 = V_41 & V_42 ;
if( V_41 & V_43 ) {
F_12 ( T_1 ) * V_44 = ( F_12 ( T_1 ) * ) * V_7 ;
int V_45 , V_46 , V_47 ;
int V_48 , V_49 ;
T_1 * V_50 ;
if( ! * V_7 ) return 0 ;
if( V_41 & V_51 ) {
V_45 = 1 ;
if( V_41 & V_52 ) V_45 = 2 ;
} else V_45 = 0 ;
if( V_41 & V_53 ) {
V_46 = V_10 -> V_8 ;
V_47 = V_9 ;
} else {
V_47 = V_37 ;
if( V_45 ) V_46 = V_54 ;
else V_46 = V_36 ;
}
V_48 = 0 ;
for( V_11 = 0 ; V_11 < F_13 ( V_44 ) ; V_11 ++ ) {
V_50 = F_14 ( V_44 , V_11 ) ;
V_48 += F_2 ( & V_50 , NULL , F_15 ( V_10 -> V_55 ) , - 1 , 0 ) ;
}
V_49 = F_10 ( 1 , V_48 , V_46 ) ;
if( V_41 & V_56 )
V_40 = F_10 ( 1 , V_49 , V_10 -> V_8 ) ;
else V_40 = V_49 ;
if( ! V_2 ) return V_40 ;
if( V_41 & V_56 )
F_11 ( V_2 , 1 , V_49 , V_10 -> V_8 , V_9 ) ;
F_11 ( V_2 , 1 , V_48 , V_46 , V_47 ) ;
F_16 ( V_44 , V_2 , V_48 , F_15 ( V_10 -> V_55 ) , V_45 ) ;
return V_40 ;
}
if( V_41 & V_56 ) {
V_11 = F_2 ( V_7 , NULL , F_15 ( V_10 -> V_55 ) , - 1 , 0 ) ;
if( ! V_11 ) return 0 ;
V_40 = F_10 ( 1 , V_11 , V_10 -> V_8 ) ;
if( V_2 ) {
F_11 ( V_2 , 1 , V_11 , V_10 -> V_8 , V_9 ) ;
F_2 ( V_7 , V_2 , F_15 ( V_10 -> V_55 ) , - 1 , 0 ) ;
}
return V_40 ;
}
if( V_41 & V_53 ) {
return F_2 ( V_7 , V_2 , F_15 ( V_10 -> V_55 ) , V_10 -> V_8 , V_9 ) ;
}
return F_2 ( V_7 , V_2 , F_15 ( V_10 -> V_55 ) , - 1 , 0 ) ;
}
static int F_17 ( const void * V_57 , const void * V_58 )
{
const T_9 * V_59 = V_57 , * V_60 = V_58 ;
int V_61 , V_11 ;
V_61 = ( V_59 -> V_62 < V_60 -> V_62 ) ? V_59 -> V_62 : V_60 -> V_62 ;
V_11 = memcmp ( V_59 -> V_63 , V_60 -> V_63 , V_61 ) ;
if( V_11 ) return V_11 ;
return V_59 -> V_62 - V_60 -> V_62 ;
}
static int F_5 ( T_1 * * V_7 , unsigned char * * V_2 , const T_2 * V_3 , int V_8 , int V_9 )
{
int V_6 ;
int V_64 ;
int V_65 ;
V_64 = V_3 -> V_64 ;
V_6 = F_18 ( V_7 , NULL , & V_64 , V_3 ) ;
if( ( V_64 == V_36 ) || ( V_64 == V_54 ) ||
( V_64 == V_66 ) )
V_65 = 0 ;
else V_65 = 1 ;
if( V_6 == - 1 ) return 0 ;
if( V_8 == - 1 ) V_8 = V_64 ;
if( V_2 ) {
if( V_65 ) F_11 ( V_2 , 0 , V_6 , V_8 , V_9 ) ;
F_18 ( V_7 , * V_2 , & V_64 , V_3 ) ;
* V_2 += V_6 ;
}
if( V_65 ) return F_10 ( 0 , V_6 , V_8 ) ;
return V_6 ;
}
int F_18 ( T_1 * * V_7 , unsigned char * V_67 , int * V_68 , const T_2 * V_3 )
{
T_10 * V_69 = NULL ;
T_4 * V_14 ;
T_11 * V_70 ;
int V_64 ;
unsigned char * V_71 , V_72 ;
int V_6 ;
const T_12 * V_73 ;
V_73 = V_3 -> V_18 ;
if( V_73 && V_73 -> V_74 ) return V_73 -> V_74 ( V_7 , V_67 , V_68 , V_3 ) ;
if( ( V_3 -> V_20 != V_21 ) || ( V_3 -> V_64 != V_75 ) ) {
if( ! * V_7 ) return - 1 ;
}
if( V_3 -> V_20 == V_23 ) {
V_14 = ( T_4 * ) * V_7 ;
V_64 = V_14 -> type ;
* V_68 = V_64 ;
} else if( V_3 -> V_64 == V_76 ) {
T_13 * V_77 ;
V_77 = ( T_13 * ) * V_7 ;
V_64 = V_77 -> type ;
* V_68 = V_64 ;
V_7 = ( T_1 * * ) & V_77 -> V_78 . V_79 ;
} else V_64 = * V_68 ;
switch( V_64 ) {
case V_80 :
V_70 = ( T_11 * ) * V_7 ;
V_71 = V_70 -> V_63 ;
V_6 = V_70 -> V_62 ;
break;
case V_81 :
V_71 = NULL ;
V_6 = 0 ;
break;
case V_75 :
V_69 = ( T_10 * ) V_7 ;
if( * V_69 == - 1 ) return - 1 ;
if( * V_69 && ( V_3 -> V_82 > 0 ) ) return - 1 ;
if( ! * V_69 && ! V_3 -> V_82 ) return - 1 ;
V_72 = ( unsigned char ) * V_69 ;
V_71 = & V_72 ;
V_6 = 1 ;
break;
case V_83 :
return F_19 ( ( V_84 * ) * V_7 , V_67 ? & V_67 : NULL ) ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
return F_20 ( ( V_89 * ) * V_7 , V_67 ? & V_67 : NULL ) ;
break;
case V_90 :
case V_91 :
case V_92 :
case V_93 :
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
case V_36 :
case V_54 :
default:
V_14 = ( T_4 * ) * V_7 ;
V_71 = V_14 -> V_63 ;
V_6 = V_14 -> V_62 ;
break;
}
if( V_67 && V_6 ) memcpy ( V_67 , V_71 , V_6 ) ;
return V_6 ;
}
