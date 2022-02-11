static const char *
F_1 ( const unsigned char * V_1 )
{
T_1 V_2 ;
if ( V_1 == NULL )
return L_1 ;
else if ( memcmp ( V_1 , V_3 , 12 ) == 0 )
{
V_2 . type = V_4 ;
V_2 . V_5 = 4 ;
V_2 . V_6 = V_1 + 12 ;
return F_2 ( F_3 () , & V_2 ) ;
}
else
{
V_2 . type = V_7 ;
V_2 . V_5 = 16 ;
V_2 . V_6 = V_1 ;
return F_2 ( F_3 () , & V_2 ) ;
}
}
static const char *
F_4 ( const unsigned char * V_1 , unsigned char V_8 )
{
return F_5 ( F_3 () , L_2 , F_1 ( V_1 ) , V_8 ) ;
}
static int
F_6 ( int V_9 , int V_8 , unsigned int V_10 ,
T_2 * V_11 , int V_12 , const unsigned char * V_13 ,
unsigned int V_5 , unsigned char * V_14 )
{
T_3 V_15 ;
unsigned char V_1 [ 16 ] ;
if ( V_8 >= 0 )
V_15 = ( V_8 + 7 ) / 8 ;
else if ( V_9 == 1 )
V_15 = 4 ;
else
V_15 = 16 ;
if ( V_15 > 16 )
return - 1 ;
memset ( V_1 , 0 , 16 ) ;
switch( V_9 ) {
case 0 : break;
case 1 :
if ( V_10 > 4 || V_15 > 4 || ( V_15 > V_10 && V_5 < V_15 - V_10 ) )
return - 1 ;
memcpy ( V_1 , V_3 , 12 ) ;
if ( V_10 ) {
if ( V_13 == NULL ) return - 1 ;
memcpy ( V_1 , V_13 , 12 + V_10 ) ;
}
if ( V_15 > V_10 )
F_7 ( V_11 , V_1 + 12 + V_10 , V_12 , V_15 - V_10 ) ;
break;
case 2 :
if ( V_10 > 16 || ( V_15 > V_10 && V_5 < V_15 - V_10 ) )
return - 1 ;
if ( V_10 ) {
if ( V_13 == NULL ) return - 1 ;
memcpy ( V_1 , V_13 , V_10 ) ;
}
if ( V_15 > V_10 )
F_7 ( V_11 , V_1 + V_10 , V_12 , V_15 - V_10 ) ;
break;
case 3 :
if ( V_15 > 8 && V_5 < V_15 - 8 ) return - 1 ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x80 ;
if ( V_15 > 8 )
F_7 ( V_11 , V_1 + 8 , V_12 , V_15 - 8 ) ;
break;
default:
return - 1 ;
}
memcpy ( V_14 , V_1 , 16 ) ;
return 1 ;
}
static int
F_8 ( int V_9 , T_2 * V_11 , int V_12 , unsigned int V_5 ,
unsigned char * V_16 )
{
return F_6 ( V_9 , - 1 , 0 , V_11 , V_12 , NULL , V_5 , V_16 ) ;
}
static int
F_9 ( T_2 * V_11 , T_4 * V_17 , T_5 * V_18 , void * V_6 V_19 )
{
T_6 * V_20 ;
unsigned char V_21 [ 16 ] = { 0 } , V_22 [ 16 ] = { 0 } ;
int V_23 ;
T_5 * V_24 = NULL ;
T_7 V_25 ;
T_8 V_26 ;
if ( F_10 ( V_11 ) < 4 )
return 0 ;
if ( F_11 ( V_11 , 0 ) != 42 )
return 0 ;
V_25 = F_11 ( V_11 , 1 ) ;
F_12 ( V_17 -> V_27 , V_28 , L_3 ) ;
F_12 ( V_17 -> V_27 , V_29 , L_3 ) ;
if ( V_25 != 2 ) {
F_13 ( V_17 -> V_27 , V_29 , L_4 , V_25 ) ;
return 2 ;
}
if ( V_18 ) {
V_20 = F_14 ( V_18 , V_30 , V_11 , 0 , - 1 , V_31 ) ;
V_24 = F_15 ( V_20 , V_32 ) ;
F_14 ( V_24 , V_33 , V_11 , 0 , 1 , V_34 ) ;
F_14 ( V_24 , V_35 , V_11 , 1 , 1 , V_34 ) ;
F_14 ( V_24 , V_36 ,
V_11 , 2 , 2 , V_34 ) ;
}
V_26 = F_16 ( V_11 , 2 ) ;
V_23 = 0 ;
while ( V_23 < V_26 ) {
T_7 type , V_5 = 0 , V_37 ;
T_5 * V_38 = NULL ;
int V_39 = 4 + V_23 ;
type = F_11 ( V_11 , V_39 ) ;
if ( type == V_40 )
V_37 = 1 ;
else {
V_5 = F_11 ( V_11 , V_39 + 1 ) ;
V_37 = V_5 + 2 ;
}
F_17 ( V_17 -> V_27 , V_29 , L_5 ,
F_18 ( type , V_41 , L_6 ) ) ;
V_20 = F_19 ( V_24 , V_42 ,
V_11 , V_39 , V_37 , type ,
L_7 ,
F_18 ( type , V_41 , L_6 ) ,
type ) ;
if ( V_18 ) {
V_38 = F_15 ( V_20 , V_43 ) ;
F_14 ( V_38 , V_44 ,
V_11 , V_39 , 1 , V_34 ) ;
}
if ( type == V_40 ) {
V_23 ++ ;
continue;
}
if ( V_18 ) {
F_14 ( V_38 , V_45 ,
V_11 , V_39 + 1 , 1 , V_34 ) ;
if ( type == V_46 ) {
} else if ( type == V_47 ) {
F_14 ( V_38 , V_48 ,
V_11 , V_39 + 4 , 2 , V_34 ) ;
F_14 ( V_38 , V_49 ,
V_11 , V_39 + 6 , 2 , V_34 ) ;
} else if ( type == V_50 ) {
F_14 ( V_38 , V_48 ,
V_11 , V_39 + 2 , 2 , V_34 ) ;
} else if ( type == V_51 ) {
F_14 ( V_38 , V_52 ,
V_11 , V_39 + 4 , 2 , V_34 ) ;
F_14 ( V_38 , V_49 ,
V_11 , V_39 + 6 , 2 , V_34 ) ;
} else if ( type == V_53 ) {
T_5 * V_54 ;
unsigned char V_55 [ 16 ] ;
int V_56 =
F_8 ( F_11 ( V_11 , V_39 + 2 ) ,
V_11 , V_39 + 8 , V_5 - 6 , V_55 ) ;
F_14 ( V_38 , V_57 ,
V_11 , V_39 + 4 , 2 , V_34 ) ;
F_14 ( V_38 , V_49 ,
V_11 , V_39 + 6 , 2 , V_34 ) ;
V_54 = F_20 ( V_38 ,
V_11 , V_39 + 4 , V_5 - 2 ,
V_58 , NULL , L_8 ,
F_1 ( V_56 < 0 ?
NULL : V_55 ) ) ;
F_14 ( V_54 , V_59 ,
V_11 , V_39 + 2 , 1 , V_34 ) ;
F_14 ( V_54 , V_60 ,
V_11 , V_39 + 4 , V_5 - 2 , V_31 ) ;
} else if ( type == V_61 ) {
F_14 ( V_38 , V_62 ,
V_11 , V_39 + 4 , 8 , V_31 ) ;
} else if ( type == V_63 ) {
T_5 * V_54 ;
unsigned char V_64 [ 16 ] ;
int V_56 =
F_8 ( F_11 ( V_11 , V_39 + 2 ) ,
V_11 , V_39 + 4 , V_5 - 2 , V_64 ) ;
V_54 = F_20 ( V_38 ,
V_11 , V_39 + 4 , V_5 - 2 ,
V_58 , NULL ,
L_9 ,
F_1 ( V_56 < 0 ? NULL : V_64 ) ) ;
F_14 ( V_54 , V_59 ,
V_11 , V_39 + 2 , 1 , V_34 ) ;
F_14 ( V_54 , V_60 ,
V_11 , V_39 + 4 , V_5 - 2 , V_31 ) ;
} else if ( type == V_65 ) {
T_5 * V_54 ;
unsigned char V_66 [ 16 ] ;
T_7 V_9 = F_11 ( V_11 , V_39 + 2 ) ;
T_7 V_67 = F_11 ( V_11 , V_39 + 3 ) ;
T_7 V_8 = F_11 ( V_11 , V_39 + 4 ) ;
int V_56 =
F_6 ( V_9 , V_8 ,
F_11 ( V_11 , V_39 + 5 ) ,
V_11 , V_39 + 12 ,
V_9 == 1 ? V_21 : V_22 ,
V_5 - 10 , V_66 ) ;
if ( V_56 >= 0 && ( V_67 & 0x80 ) ) {
if ( V_9 == 1 )
memcpy ( V_21 , V_66 , 16 ) ;
else
memcpy ( V_22 , V_66 , 16 ) ;
}
F_14 ( V_38 , V_68 ,
V_11 , V_39 + 3 , 1 , V_34 ) ;
F_14 ( V_38 , V_49 ,
V_11 , V_39 + 6 , 2 , V_34 ) ;
F_14 ( V_38 , V_52 ,
V_11 , V_39 + 8 , 2 , V_34 ) ;
F_14 ( V_38 , V_69 ,
V_11 , V_39 + 10 , 2 , V_34 ) ;
V_54 = F_20 ( V_38 ,
V_11 , V_39 + 12 , V_5 - 10 ,
V_58 , NULL ,
L_10 ,
F_4 ( V_56 < 0 ? NULL : V_66 ,
V_8 ) ) ;
F_14 ( V_54 , V_59 ,
V_11 , V_39 + 2 , 1 , V_34 ) ;
F_14 ( V_54 , V_70 ,
V_11 , V_39 + 4 , 1 , V_34 ) ;
F_14 ( V_54 , V_71 ,
V_11 , V_39 + 5 , 1 , V_34 ) ;
F_14 ( V_54 , V_60 ,
V_11 , V_39 + 12 , V_5 - 10 , V_31 ) ;
} else if ( type == V_72 ) {
T_5 * V_54 ;
unsigned char V_66 [ 16 ] ;
T_7 V_8 = F_11 ( V_11 , V_39 + 3 ) ;
int V_56 =
F_6 ( F_11 ( V_11 , V_39 + 2 ) , V_8 ,
0 , V_11 , V_39 + 4 , NULL ,
V_5 - 2 , V_66 ) ;
V_54 = F_20 ( V_38 ,
V_11 , V_39 + 4 , V_5 - 2 ,
V_58 , NULL ,
L_10 ,
F_4 ( V_56 < 0 ? NULL : V_66 ,
V_8 ) ) ;
F_14 ( V_54 , V_59 ,
V_11 , V_39 + 2 , 1 , V_34 ) ;
F_14 ( V_54 , V_70 ,
V_11 , V_39 + 3 , 1 , V_34 ) ;
F_14 ( V_54 , V_60 ,
V_11 , V_39 + 4 , V_5 - 2 , V_31 ) ;
} else if ( type == V_73 ) {
T_5 * V_54 ;
unsigned char V_66 [ 16 ] ;
T_7 V_8 = F_11 ( V_11 , V_39 + 3 ) ;
int V_56 =
F_6 ( F_11 ( V_11 , V_39 + 2 ) , V_8 ,
0 , V_11 , V_39 + 16 , NULL ,
V_5 - 14 , V_66 ) ;
F_14 ( V_38 , V_52 ,
V_11 , V_39 + 4 , 2 , V_34 ) ;
F_14 ( V_38 , V_74 ,
V_11 , V_39 + 6 , 1 , V_34 ) ;
F_14 ( V_38 , V_62 ,
V_11 , V_39 + 8 , 8 , V_31 ) ;
V_54 = F_20 ( V_38 ,
V_11 , V_39 + 16 , V_5 - 14 ,
V_58 , NULL ,
L_10 ,
F_4 ( V_56 < 0 ? NULL : V_66 ,
V_8 ) ) ;
F_14 ( V_54 , V_59 ,
V_11 , V_39 + 2 , 1 , V_34 ) ;
F_14 ( V_54 , V_70 ,
V_11 , V_39 + 3 , 1 , V_34 ) ;
F_14 ( V_54 , V_60 ,
V_11 , V_39 + 16 , V_5 - 14 , V_31 ) ;
}
}
V_23 += V_5 + 2 ;
}
return V_23 ;
}
void
F_21 ( void )
{
static T_9 V_75 [] = {
{ & V_33 ,
{ L_11 , L_12 , V_76 , V_77 ,
NULL , 0 , L_13 , V_78 }
} ,
{ & V_35 ,
{ L_14 , L_15 , V_76 , V_77 ,
NULL , 0 , L_16 , V_78 }
} ,
{ & V_36 ,
{ L_17 , L_18 , V_79 , V_77 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_42 ,
{ L_19 , L_20 , V_76 , V_77 ,
NULL , 0 , L_21 , V_78 }
} ,
{ & V_44 ,
{ L_22 , L_23 , V_76 , V_77 ,
F_22 ( V_41 ) , 0 , NULL , V_78 }
} ,
{ & V_45 ,
{ L_24 , L_25 , V_76 , V_77 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_48 ,
{ L_26 , L_27 , V_79 , V_80 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_49 ,
{ L_28 , L_29 , V_79 , V_77 ,
NULL , 0 , L_30 , V_78 }
} ,
{ & V_52 ,
{ L_31 , L_32 , V_79 , V_80 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_59 ,
{ L_33 , L_34 , V_76 , V_77 ,
F_22 ( V_81 ) , 0 , NULL , V_78 }
} ,
{ & V_60 ,
{ L_35 , L_36 , V_82 , V_83 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_57 ,
{ L_37 , L_38 , V_79 , V_80 ,
NULL , 0 , L_39 , V_78 }
} ,
{ & V_62 ,
{ L_40 , L_41 , V_82 , V_83 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_68 ,
{ L_42 , L_43 , V_76 , V_80 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_70 ,
{ L_44 , L_45 , V_76 , V_77 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_71 ,
{ L_46 , L_47 , V_76 , V_77 ,
NULL , 0 , L_48 , V_78 }
} ,
{ & V_69 ,
{ L_49 , L_50 , V_79 , V_77 ,
NULL , 0 , NULL , V_78 }
} ,
{ & V_74 ,
{ L_51 , L_52 , V_76 , V_77 ,
NULL , 0 , NULL , V_78 }
} ,
} ;
static T_10 * V_84 [] = {
& V_32 ,
& V_43 ,
& V_58 ,
} ;
V_30 =
F_23 ( L_53 , L_3 , L_54 ) ;
F_24 ( V_30 , V_75 , F_25 ( V_75 ) ) ;
F_26 ( V_84 , F_25 ( V_84 ) ) ;
}
void
F_27 ( void )
{
T_11 V_85 ;
V_85 = F_28 ( F_9 , V_30 ) ;
F_29 ( L_55 , V_86 , V_85 ) ;
F_29 ( L_55 , V_87 , V_85 ) ;
}
