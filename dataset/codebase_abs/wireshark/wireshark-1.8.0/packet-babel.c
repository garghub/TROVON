static const char *
F_1 ( const unsigned char * V_1 )
{
if( V_1 == NULL )
return L_1 ;
else if( memcmp ( V_1 , V_2 , 12 ) == 0 )
return F_2 ( V_1 + 12 ) ;
else
return F_3 ( ( const struct V_3 * ) V_1 ) ;
}
static const char *
F_4 ( const unsigned char * V_1 , unsigned char V_4 )
{
return F_5 ( L_2 , F_1 ( V_1 ) , V_4 ) ;
}
static int
F_6 ( int V_5 , int V_4 , unsigned int V_6 ,
const unsigned char * V_7 , const unsigned char * V_8 ,
unsigned int V_9 , unsigned char * V_10 )
{
unsigned V_11 ;
unsigned char V_1 [ 16 ] ;
if( V_4 >= 0 )
V_11 = ( V_4 + 7 ) / 8 ;
else if( V_5 == 1 )
V_11 = 4 ;
else
V_11 = 16 ;
if( V_11 > 16 )
return - 1 ;
memset ( V_1 , 0 , 16 ) ;
switch( V_5 ) {
case 0 : break;
case 1 :
if( V_6 > 4 || V_11 > 4 || ( V_11 > V_6 && V_9 < V_11 - V_6 ) )
return - 1 ;
memcpy ( V_1 , V_2 , 12 ) ;
if( V_6 ) {
if ( V_8 == NULL ) return - 1 ;
memcpy ( V_1 , V_8 , 12 + V_6 ) ;
}
if( V_11 > V_6 ) memcpy ( V_1 + 12 + V_6 , V_7 , V_11 - V_6 ) ;
break;
case 2 :
if( V_6 > 16 || ( V_11 > V_6 && V_9 < V_11 - V_6 ) )
return - 1 ;
if( V_6 ) {
if ( V_8 == NULL ) return - 1 ;
memcpy ( V_1 , V_8 , V_6 ) ;
}
if( V_11 > V_6 ) memcpy ( V_1 + V_6 , V_7 , V_11 - V_6 ) ;
break;
case 3 :
if( V_11 > 8 && V_9 < V_11 - 8 ) return - 1 ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x80 ;
if( V_11 > 8 ) memcpy ( V_1 + 8 , V_7 , V_11 - 8 ) ;
break;
default:
return - 1 ;
}
memcpy ( V_10 , V_1 , 16 ) ;
return 1 ;
}
static int
F_7 ( int V_5 , const unsigned char * V_12 , unsigned int V_9 ,
unsigned char * V_13 )
{
return F_6 ( V_5 , - 1 , 0 , V_12 , NULL , V_9 , V_13 ) ;
}
static int
F_8 ( T_1 * V_14 , T_2 * V_15 , T_3 * V_16 )
{
T_4 * V_17 ;
unsigned char V_18 [ 16 ] = { 0 } , V_19 [ 16 ] = { 0 } ;
int V_20 = 0 ;
T_3 * V_21 = NULL ;
T_5 V_22 ;
T_6 V_23 ;
if( F_9 ( V_14 ) < 4 )
return 0 ;
if( F_10 ( V_14 , 0 ) != 42 )
return 0 ;
V_22 = F_10 ( V_14 , 1 ) ;
F_11 ( V_15 -> V_24 , V_25 , L_3 ) ;
F_11 ( V_15 -> V_24 , V_26 , L_3 ) ;
if( V_22 != 2 ) {
F_12 ( V_15 -> V_24 , V_26 , L_4 , V_22 ) ;
return 2 ;
}
if( V_16 ) {
V_17 = F_13 ( V_16 , V_27 , V_14 , 0 , - 1 , V_28 ) ;
V_21 = F_14 ( V_17 , V_29 ) ;
F_13 ( V_21 , V_30 , V_14 , 0 , 1 , V_28 ) ;
F_13 ( V_21 , V_31 , V_14 , 1 , 1 , V_28 ) ;
F_13 ( V_21 , V_32 ,
V_14 , 2 , 2 , V_33 ) ;
}
V_23 = F_15 ( V_14 , 2 ) ;
V_20 = 0 ;
while( V_20 < V_23 ) {
T_5 type , V_9 = 0 , V_34 ;
T_3 * V_35 = NULL ;
int V_36 = 4 + V_20 ;
type = F_10 ( V_14 , V_36 ) ;
if( type == V_37 )
V_34 = 1 ;
else {
V_9 = F_10 ( V_14 , V_36 + 1 ) ;
V_34 = V_9 + 2 ;
}
F_16 ( V_15 -> V_24 , V_26 , L_5 ,
F_17 ( type , V_38 , L_6 ) ) ;
V_17 = F_18 ( V_21 , V_39 ,
V_14 , V_36 , V_34 , type ,
L_7 ,
F_17 ( type , V_38 ,
L_6 ) ,
type ) ;
if( V_16 ) {
V_35 = F_14 ( V_17 , V_40 ) ;
F_13 ( V_35 , V_41 ,
V_14 , V_36 , 1 , V_28 ) ;
}
if( type == V_37 ) {
V_20 ++ ;
continue;
}
if( V_16 ) {
F_13 ( V_35 , V_42 ,
V_14 , V_36 + 1 , 1 , V_33 ) ;
if( type == V_43 ) {
} else if( type == V_44 ) {
F_13 ( V_35 , V_45 ,
V_14 , V_36 + 4 , 2 , V_33 ) ;
F_13 ( V_35 , V_46 ,
V_14 , V_36 + 6 , 2 , V_33 ) ;
} else if( type == V_47 ) {
F_13 ( V_35 , V_45 ,
V_14 , V_36 + 2 , 2 , V_33 ) ;
} else if( type == V_48 ) {
F_13 ( V_35 , V_49 ,
V_14 , V_36 + 4 , 2 , V_33 ) ;
F_13 ( V_35 , V_46 ,
V_14 , V_36 + 6 , 2 , V_33 ) ;
} else if( type == V_50 ) {
T_3 * V_51 ;
unsigned char V_52 [ 16 ] ;
int V_53 =
F_7 ( F_10 ( V_14 , V_36 + 2 ) ,
F_19 ( V_14 , V_36 + 8 , V_9 - 6 ) ,
V_9 - 6 ,
V_52 ) ;
F_13 ( V_35 , V_54 ,
V_14 , V_36 + 4 , 2 , V_33 ) ;
F_13 ( V_35 , V_46 ,
V_14 , V_36 + 6 , 2 , V_33 ) ;
V_17 = F_20 ( V_35 ,
V_14 , V_36 + 4 , V_9 - 2 ,
L_8 ,
F_1 ( V_53 < 0 ?
NULL : V_52 ) ) ;
V_51 = F_14 ( V_17 , V_55 ) ;
F_13 ( V_51 , V_56 ,
V_14 , V_36 + 2 , 1 , V_28 ) ;
F_13 ( V_51 , V_57 ,
V_14 , V_36 + 4 , V_9 - 2 , V_28 ) ;
} else if( type == V_58 ) {
F_13 ( V_35 , V_59 ,
V_14 , V_36 + 4 , 8 , V_28 ) ;
} else if( type == V_60 ) {
T_3 * V_51 ;
unsigned char V_61 [ 16 ] ;
int V_53 =
F_7 ( F_10 ( V_14 , V_36 + 2 ) ,
F_19 ( V_14 , V_36 + 4 , V_9 - 2 ) ,
V_9 - 2 ,
V_61 ) ;
V_17 = F_20 ( V_35 ,
V_14 , V_36 + 4 , V_9 - 2 ,
L_9 ,
F_1 ( V_53 < 0 ? NULL : V_61 ) ) ;
V_51 = F_14 ( V_17 , V_55 ) ;
F_13 ( V_51 , V_56 ,
V_14 , V_36 + 2 , 1 , V_28 ) ;
F_13 ( V_51 , V_57 ,
V_14 , V_36 + 4 , V_9 - 2 , V_28 ) ;
} else if( type == V_62 ) {
T_3 * V_51 ;
unsigned char V_7 [ 16 ] ;
T_5 V_5 = F_10 ( V_14 , V_36 + 2 ) ;
T_5 V_63 = F_10 ( V_14 , V_36 + 3 ) ;
T_5 V_4 = F_10 ( V_14 , V_36 + 4 ) ;
int V_53 =
F_6 ( V_5 , V_4 ,
F_10 ( V_14 , V_36 + 5 ) ,
F_19 ( V_14 , V_36 + 12 , V_9 - 10 ) ,
V_5 == 1 ? V_18 : V_19 ,
V_9 - 10 , V_7 ) ;
if( V_53 >= 0 && ( V_63 & 0x80 ) ) {
if( V_5 == 1 )
memcpy ( V_18 , V_7 , 16 ) ;
else
memcpy ( V_19 , V_7 , 16 ) ;
}
F_13 ( V_35 , V_64 ,
V_14 , V_36 + 3 , 1 , V_28 ) ;
F_13 ( V_35 , V_46 ,
V_14 , V_36 + 6 , 2 , V_33 ) ;
F_13 ( V_35 , V_49 ,
V_14 , V_36 + 8 , 2 , V_33 ) ;
F_13 ( V_35 , V_65 ,
V_14 , V_36 + 10 , 2 , V_33 ) ;
V_17 = F_20 ( V_35 ,
V_14 , V_36 + 12 , V_9 - 10 ,
L_10 ,
F_4 ( V_53 < 0 ? NULL : V_7 ,
V_4 ) ) ;
V_51 = F_14 ( V_17 , V_55 ) ;
F_13 ( V_51 , V_56 ,
V_14 , V_36 + 2 , 1 , V_28 ) ;
F_13 ( V_51 , V_66 ,
V_14 , V_36 + 4 , 1 , V_28 ) ;
F_13 ( V_51 , V_67 ,
V_14 , V_36 + 5 , 1 , V_28 ) ;
F_13 ( V_51 , V_57 ,
V_14 , V_36 + 12 , V_9 - 10 , V_28 ) ;
} else if( type == V_68 ) {
T_3 * V_51 ;
unsigned char V_7 [ 16 ] ;
T_5 V_4 = F_10 ( V_14 , V_36 + 3 ) ;
int V_53 =
F_6 ( F_10 ( V_14 , V_36 + 2 ) , V_4 ,
0 ,
F_19 ( V_14 , V_36 + 4 , V_9 - 2 ) ,
NULL ,
V_9 - 2 , V_7 ) ;
V_17 = F_20 ( V_35 ,
V_14 , V_36 + 4 , V_9 - 2 ,
L_10 ,
F_4 ( V_53 < 0 ? NULL : V_7 ,
V_4 ) ) ;
V_51 = F_14 ( V_17 , V_55 ) ;
F_13 ( V_51 , V_56 ,
V_14 , V_36 + 2 , 1 , V_28 ) ;
F_13 ( V_51 , V_66 ,
V_14 , V_36 + 3 , 1 , V_28 ) ;
F_13 ( V_51 , V_57 ,
V_14 , V_36 + 4 , V_9 - 2 , V_28 ) ;
} else if( type == V_69 ) {
T_3 * V_51 ;
unsigned char V_7 [ 16 ] ;
T_5 V_4 = F_10 ( V_14 , V_36 + 3 ) ;
int V_53 =
F_6 ( F_10 ( V_14 , V_36 + 2 ) , V_4 ,
0 ,
F_19 ( V_14 , V_36 + 16 , V_9 - 14 ) ,
NULL ,
V_9 - 14 , V_7 ) ;
F_13 ( V_35 , V_49 ,
V_14 , V_36 + 4 , 2 , V_33 ) ;
F_13 ( V_35 , V_70 ,
V_14 , V_36 + 6 , 1 , V_28 ) ;
F_13 ( V_35 , V_59 ,
V_14 , V_36 + 8 , 8 , V_28 ) ;
V_17 = F_20 ( V_35 ,
V_14 , V_36 + 16 , V_9 - 14 ,
L_10 ,
F_4 ( V_53 < 0 ? NULL : V_7 ,
V_4 ) ) ;
V_51 = F_14 ( V_17 , V_55 ) ;
F_13 ( V_51 , V_56 ,
V_14 , V_36 + 2 , 1 , V_28 ) ;
F_13 ( V_51 , V_66 ,
V_14 , V_36 + 3 , 1 , V_28 ) ;
F_13 ( V_51 , V_57 ,
V_14 , V_36 + 16 , V_9 - 14 , V_28 ) ;
}
}
V_20 += V_9 + 2 ;
}
return V_20 ;
}
void
F_21 ( void )
{
static T_7 V_71 [] = {
{ & V_30 ,
{ L_11 , L_12 , V_72 , V_73 ,
NULL , 0 , L_13 , V_74 }
} ,
{ & V_31 ,
{ L_14 , L_15 , V_72 , V_73 ,
NULL , 0 , L_16 , V_74 }
} ,
{ & V_32 ,
{ L_17 , L_18 , V_75 , V_73 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_39 ,
{ L_19 , L_20 , V_72 , V_73 ,
NULL , 0 , L_21 , V_74 }
} ,
{ & V_41 ,
{ L_22 , L_23 , V_72 , V_73 ,
F_22 ( V_38 ) , 0 , NULL , V_74 }
} ,
{ & V_42 ,
{ L_24 , L_25 , V_72 , V_73 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_45 ,
{ L_26 , L_27 , V_75 , V_76 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_46 ,
{ L_28 , L_29 , V_75 , V_73 ,
NULL , 0 , L_30 , V_74 }
} ,
{ & V_49 ,
{ L_31 , L_32 , V_75 , V_76 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_56 ,
{ L_33 , L_34 , V_72 , V_73 ,
F_22 ( V_77 ) , 0 , NULL , V_74 }
} ,
{ & V_57 ,
{ L_35 , L_36 , V_78 , V_79 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_54 ,
{ L_37 , L_38 , V_75 , V_76 ,
NULL , 0 , L_39 , V_74 }
} ,
{ & V_59 ,
{ L_40 , L_41 , V_78 , V_79 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_64 ,
{ L_42 , L_43 , V_72 , V_76 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_66 ,
{ L_44 , L_45 , V_72 , V_73 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_67 ,
{ L_46 , L_47 , V_72 , V_73 ,
NULL , 0 , L_48 , V_74 }
} ,
{ & V_65 ,
{ L_49 , L_50 , V_75 , V_73 ,
NULL , 0 , NULL , V_74 }
} ,
{ & V_70 ,
{ L_51 , L_52 , V_72 , V_73 ,
NULL , 0 , NULL , V_74 }
} ,
} ;
static T_8 * V_80 [] = {
& V_29 ,
& V_40 ,
& V_55 ,
} ;
V_27 =
F_23 ( L_53 , L_3 , L_54 ) ;
F_24 ( V_27 , V_71 , F_25 ( V_71 ) ) ;
F_26 ( V_80 , F_25 ( V_80 ) ) ;
}
void
F_27 ( void )
{
T_9 V_81 ;
V_81 = F_28 ( F_8 , V_27 ) ;
F_29 ( L_55 , V_82 , V_81 ) ;
F_29 ( L_55 , V_83 , V_81 ) ;
}
