static const char *
F_1 ( const unsigned char * V_1 )
{
if ( V_1 == NULL )
return L_1 ;
else if ( memcmp ( V_1 , V_2 , 12 ) == 0 )
return F_2 ( V_1 + 12 ) ;
else
return F_3 ( ( const struct V_3 * ) V_1 ) ;
}
static const char *
F_4 ( const unsigned char * V_1 , unsigned char V_4 )
{
return F_5 ( F_6 () , L_2 , F_1 ( V_1 ) , V_4 ) ;
}
static int
F_7 ( int V_5 , int V_4 , unsigned int V_6 ,
const unsigned char * V_7 , const unsigned char * V_8 ,
unsigned int V_9 , unsigned char * V_10 )
{
T_1 V_11 ;
unsigned char V_1 [ 16 ] ;
if ( V_4 >= 0 )
V_11 = ( V_4 + 7 ) / 8 ;
else if ( V_5 == 1 )
V_11 = 4 ;
else
V_11 = 16 ;
if ( V_11 > 16 )
return - 1 ;
memset ( V_1 , 0 , 16 ) ;
switch( V_5 ) {
case 0 : break;
case 1 :
if ( V_6 > 4 || V_11 > 4 || ( V_11 > V_6 && V_9 < V_11 - V_6 ) )
return - 1 ;
memcpy ( V_1 , V_2 , 12 ) ;
if ( V_6 ) {
if ( V_8 == NULL ) return - 1 ;
memcpy ( V_1 , V_8 , 12 + V_6 ) ;
}
if ( V_11 > V_6 ) memcpy ( V_1 + 12 + V_6 , V_7 , V_11 - V_6 ) ;
break;
case 2 :
if ( V_6 > 16 || ( V_11 > V_6 && V_9 < V_11 - V_6 ) )
return - 1 ;
if ( V_6 ) {
if ( V_8 == NULL ) return - 1 ;
memcpy ( V_1 , V_8 , V_6 ) ;
}
if ( V_11 > V_6 ) memcpy ( V_1 + V_6 , V_7 , V_11 - V_6 ) ;
break;
case 3 :
if ( V_11 > 8 && V_9 < V_11 - 8 ) return - 1 ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x80 ;
if ( V_11 > 8 ) memcpy ( V_1 + 8 , V_7 , V_11 - 8 ) ;
break;
default:
return - 1 ;
}
memcpy ( V_10 , V_1 , 16 ) ;
return 1 ;
}
static int
F_8 ( int V_5 , const unsigned char * V_12 , unsigned int V_9 ,
unsigned char * V_13 )
{
return F_7 ( V_5 , - 1 , 0 , V_12 , NULL , V_9 , V_13 ) ;
}
static int
F_9 ( T_2 * V_14 , T_3 * V_15 , T_4 * V_16 , void * T_5 V_17 )
{
T_6 * V_18 ;
unsigned char V_19 [ 16 ] = { 0 } , V_20 [ 16 ] = { 0 } ;
int V_21 ;
T_4 * V_22 = NULL ;
T_7 V_23 ;
T_8 V_24 ;
if ( F_10 ( V_14 ) < 4 )
return 0 ;
if ( F_11 ( V_14 , 0 ) != 42 )
return 0 ;
V_23 = F_11 ( V_14 , 1 ) ;
F_12 ( V_15 -> V_25 , V_26 , L_3 ) ;
F_12 ( V_15 -> V_25 , V_27 , L_3 ) ;
if ( V_23 != 2 ) {
F_13 ( V_15 -> V_25 , V_27 , L_4 , V_23 ) ;
return 2 ;
}
if ( V_16 ) {
V_18 = F_14 ( V_16 , V_28 , V_14 , 0 , - 1 , V_29 ) ;
V_22 = F_15 ( V_18 , V_30 ) ;
F_14 ( V_22 , V_31 , V_14 , 0 , 1 , V_29 ) ;
F_14 ( V_22 , V_32 , V_14 , 1 , 1 , V_29 ) ;
F_14 ( V_22 , V_33 ,
V_14 , 2 , 2 , V_34 ) ;
}
V_24 = F_16 ( V_14 , 2 ) ;
V_21 = 0 ;
while ( V_21 < V_24 ) {
T_7 type , V_9 = 0 , V_35 ;
T_4 * V_36 = NULL ;
int V_37 = 4 + V_21 ;
type = F_11 ( V_14 , V_37 ) ;
if ( type == V_38 )
V_35 = 1 ;
else {
V_9 = F_11 ( V_14 , V_37 + 1 ) ;
V_35 = V_9 + 2 ;
}
F_17 ( V_15 -> V_25 , V_27 , L_5 ,
F_18 ( type , V_39 , L_6 ) ) ;
V_18 = F_19 ( V_22 , V_40 ,
V_14 , V_37 , V_35 , type ,
L_7 ,
F_18 ( type , V_39 , L_6 ) ,
type ) ;
if ( V_16 ) {
V_36 = F_15 ( V_18 , V_41 ) ;
F_14 ( V_36 , V_42 ,
V_14 , V_37 , 1 , V_29 ) ;
}
if ( type == V_38 ) {
V_21 ++ ;
continue;
}
if ( V_16 ) {
F_14 ( V_36 , V_43 ,
V_14 , V_37 + 1 , 1 , V_34 ) ;
if ( type == V_44 ) {
} else if ( type == V_45 ) {
F_14 ( V_36 , V_46 ,
V_14 , V_37 + 4 , 2 , V_34 ) ;
F_14 ( V_36 , V_47 ,
V_14 , V_37 + 6 , 2 , V_34 ) ;
} else if ( type == V_48 ) {
F_14 ( V_36 , V_46 ,
V_14 , V_37 + 2 , 2 , V_34 ) ;
} else if ( type == V_49 ) {
F_14 ( V_36 , V_50 ,
V_14 , V_37 + 4 , 2 , V_34 ) ;
F_14 ( V_36 , V_47 ,
V_14 , V_37 + 6 , 2 , V_34 ) ;
} else if ( type == V_51 ) {
T_4 * V_52 ;
unsigned char V_53 [ 16 ] ;
int V_54 =
F_8 ( F_11 ( V_14 , V_37 + 2 ) ,
F_20 ( V_14 , V_37 + 8 , V_9 - 6 ) ,
V_9 - 6 ,
V_53 ) ;
F_14 ( V_36 , V_55 ,
V_14 , V_37 + 4 , 2 , V_34 ) ;
F_14 ( V_36 , V_47 ,
V_14 , V_37 + 6 , 2 , V_34 ) ;
V_52 = F_21 ( V_36 ,
V_14 , V_37 + 4 , V_9 - 2 ,
V_56 , NULL , L_8 ,
F_1 ( V_54 < 0 ?
NULL : V_53 ) ) ;
F_14 ( V_52 , V_57 ,
V_14 , V_37 + 2 , 1 , V_29 ) ;
F_14 ( V_52 , V_58 ,
V_14 , V_37 + 4 , V_9 - 2 , V_29 ) ;
} else if ( type == V_59 ) {
F_14 ( V_36 , V_60 ,
V_14 , V_37 + 4 , 8 , V_29 ) ;
} else if ( type == V_61 ) {
T_4 * V_52 ;
unsigned char V_62 [ 16 ] ;
int V_54 =
F_8 ( F_11 ( V_14 , V_37 + 2 ) ,
F_20 ( V_14 , V_37 + 4 , V_9 - 2 ) ,
V_9 - 2 ,
V_62 ) ;
V_52 = F_21 ( V_36 ,
V_14 , V_37 + 4 , V_9 - 2 ,
V_56 , NULL ,
L_9 ,
F_1 ( V_54 < 0 ? NULL : V_62 ) ) ;
F_14 ( V_52 , V_57 ,
V_14 , V_37 + 2 , 1 , V_29 ) ;
F_14 ( V_52 , V_58 ,
V_14 , V_37 + 4 , V_9 - 2 , V_29 ) ;
} else if ( type == V_63 ) {
T_4 * V_52 ;
unsigned char V_7 [ 16 ] ;
T_7 V_5 = F_11 ( V_14 , V_37 + 2 ) ;
T_7 V_64 = F_11 ( V_14 , V_37 + 3 ) ;
T_7 V_4 = F_11 ( V_14 , V_37 + 4 ) ;
int V_54 =
F_7 ( V_5 , V_4 ,
F_11 ( V_14 , V_37 + 5 ) ,
F_20 ( V_14 , V_37 + 12 , V_9 - 10 ) ,
V_5 == 1 ? V_19 : V_20 ,
V_9 - 10 , V_7 ) ;
if ( V_54 >= 0 && ( V_64 & 0x80 ) ) {
if ( V_5 == 1 )
memcpy ( V_19 , V_7 , 16 ) ;
else
memcpy ( V_20 , V_7 , 16 ) ;
}
F_14 ( V_36 , V_65 ,
V_14 , V_37 + 3 , 1 , V_29 ) ;
F_14 ( V_36 , V_47 ,
V_14 , V_37 + 6 , 2 , V_34 ) ;
F_14 ( V_36 , V_50 ,
V_14 , V_37 + 8 , 2 , V_34 ) ;
F_14 ( V_36 , V_66 ,
V_14 , V_37 + 10 , 2 , V_34 ) ;
V_52 = F_21 ( V_36 ,
V_14 , V_37 + 12 , V_9 - 10 ,
V_56 , NULL ,
L_10 ,
F_4 ( V_54 < 0 ? NULL : V_7 ,
V_4 ) ) ;
F_14 ( V_52 , V_57 ,
V_14 , V_37 + 2 , 1 , V_29 ) ;
F_14 ( V_52 , V_67 ,
V_14 , V_37 + 4 , 1 , V_29 ) ;
F_14 ( V_52 , V_68 ,
V_14 , V_37 + 5 , 1 , V_29 ) ;
F_14 ( V_52 , V_58 ,
V_14 , V_37 + 12 , V_9 - 10 , V_29 ) ;
} else if ( type == V_69 ) {
T_4 * V_52 ;
unsigned char V_7 [ 16 ] ;
T_7 V_4 = F_11 ( V_14 , V_37 + 3 ) ;
int V_54 =
F_7 ( F_11 ( V_14 , V_37 + 2 ) , V_4 ,
0 ,
F_20 ( V_14 , V_37 + 4 , V_9 - 2 ) ,
NULL ,
V_9 - 2 , V_7 ) ;
V_52 = F_21 ( V_36 ,
V_14 , V_37 + 4 , V_9 - 2 ,
V_56 , NULL ,
L_10 ,
F_4 ( V_54 < 0 ? NULL : V_7 ,
V_4 ) ) ;
F_14 ( V_52 , V_57 ,
V_14 , V_37 + 2 , 1 , V_29 ) ;
F_14 ( V_52 , V_67 ,
V_14 , V_37 + 3 , 1 , V_29 ) ;
F_14 ( V_52 , V_58 ,
V_14 , V_37 + 4 , V_9 - 2 , V_29 ) ;
} else if ( type == V_70 ) {
T_4 * V_52 ;
unsigned char V_7 [ 16 ] ;
T_7 V_4 = F_11 ( V_14 , V_37 + 3 ) ;
int V_54 =
F_7 ( F_11 ( V_14 , V_37 + 2 ) , V_4 ,
0 ,
F_20 ( V_14 , V_37 + 16 , V_9 - 14 ) ,
NULL ,
V_9 - 14 , V_7 ) ;
F_14 ( V_36 , V_50 ,
V_14 , V_37 + 4 , 2 , V_34 ) ;
F_14 ( V_36 , V_71 ,
V_14 , V_37 + 6 , 1 , V_29 ) ;
F_14 ( V_36 , V_60 ,
V_14 , V_37 + 8 , 8 , V_29 ) ;
V_52 = F_21 ( V_36 ,
V_14 , V_37 + 16 , V_9 - 14 ,
V_56 , NULL ,
L_10 ,
F_4 ( V_54 < 0 ? NULL : V_7 ,
V_4 ) ) ;
F_14 ( V_52 , V_57 ,
V_14 , V_37 + 2 , 1 , V_29 ) ;
F_14 ( V_52 , V_67 ,
V_14 , V_37 + 3 , 1 , V_29 ) ;
F_14 ( V_52 , V_58 ,
V_14 , V_37 + 16 , V_9 - 14 , V_29 ) ;
}
}
V_21 += V_9 + 2 ;
}
return V_21 ;
}
void
F_22 ( void )
{
static T_9 V_72 [] = {
{ & V_31 ,
{ L_11 , L_12 , V_73 , V_74 ,
NULL , 0 , L_13 , V_75 }
} ,
{ & V_32 ,
{ L_14 , L_15 , V_73 , V_74 ,
NULL , 0 , L_16 , V_75 }
} ,
{ & V_33 ,
{ L_17 , L_18 , V_76 , V_74 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_40 ,
{ L_19 , L_20 , V_73 , V_74 ,
NULL , 0 , L_21 , V_75 }
} ,
{ & V_42 ,
{ L_22 , L_23 , V_73 , V_74 ,
F_23 ( V_39 ) , 0 , NULL , V_75 }
} ,
{ & V_43 ,
{ L_24 , L_25 , V_73 , V_74 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_46 ,
{ L_26 , L_27 , V_76 , V_77 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_47 ,
{ L_28 , L_29 , V_76 , V_74 ,
NULL , 0 , L_30 , V_75 }
} ,
{ & V_50 ,
{ L_31 , L_32 , V_76 , V_77 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_57 ,
{ L_33 , L_34 , V_73 , V_74 ,
F_23 ( V_78 ) , 0 , NULL , V_75 }
} ,
{ & V_58 ,
{ L_35 , L_36 , V_79 , V_80 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_55 ,
{ L_37 , L_38 , V_76 , V_77 ,
NULL , 0 , L_39 , V_75 }
} ,
{ & V_60 ,
{ L_40 , L_41 , V_79 , V_80 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_65 ,
{ L_42 , L_43 , V_73 , V_77 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_67 ,
{ L_44 , L_45 , V_73 , V_74 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_68 ,
{ L_46 , L_47 , V_73 , V_74 ,
NULL , 0 , L_48 , V_75 }
} ,
{ & V_66 ,
{ L_49 , L_50 , V_76 , V_74 ,
NULL , 0 , NULL , V_75 }
} ,
{ & V_71 ,
{ L_51 , L_52 , V_73 , V_74 ,
NULL , 0 , NULL , V_75 }
} ,
} ;
static T_10 * V_81 [] = {
& V_30 ,
& V_41 ,
& V_56 ,
} ;
V_28 =
F_24 ( L_53 , L_3 , L_54 ) ;
F_25 ( V_28 , V_72 , F_26 ( V_72 ) ) ;
F_27 ( V_81 , F_26 ( V_81 ) ) ;
}
void
F_28 ( void )
{
T_11 V_82 ;
V_82 = F_29 ( F_9 , V_28 ) ;
F_30 ( L_55 , V_83 , V_82 ) ;
F_30 ( L_55 , V_84 , V_82 ) ;
}
